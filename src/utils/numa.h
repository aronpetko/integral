#ifndef INTEGRAL_NUMA_H
#define INTEGRAL_NUMA_H

#include <cstddef>
#include <thread>
#include <vector>

#include "types.h"

#if defined(USE_NUMA) && defined(_WIN32)

#include <algorithm>
#include <bit>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

namespace numa {

namespace detail {

// A NUMA node's logical processors, split by the processor group they're in
struct WindowsNumaNode {
  std::size_t id;
  std::vector<GROUP_AFFINITY> group_masks;
};

[[nodiscard]] inline std::vector<WindowsNumaNode> QueryNumaNodes() {
  for (const auto relation : {RelationNumaNodeEx, RelationNumaNode}) {
    DWORD length = 0;
    GetLogicalProcessorInformationEx(relation, nullptr, &length);
    if (GetLastError() != ERROR_INSUFFICIENT_BUFFER) {
      continue;
    }

    std::vector<std::byte> buffer(length);
    if (!GetLogicalProcessorInformationEx(
            relation,
            reinterpret_cast<SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX *>(
                buffer.data()),
            &length)) {
      continue;
    }

    std::vector<WindowsNumaNode> nodes;
    for (DWORD offset = 0; offset < length;) {
      const auto *info =
          reinterpret_cast<const SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX *>(
              buffer.data() + offset);
      offset += info->Size;

      if (info->Relationship != RelationNumaNode &&
          info->Relationship != RelationNumaNodeEx) {
        continue;
      }

      const auto &numa = info->NumaNode;
      const WORD group_count = std::max<WORD>(1, numa.GroupCount);

      WindowsNumaNode node{numa.NodeNumber, {}};
      for (WORD i = 0; i < group_count; ++i) {
        if (numa.GroupMasks[i].Mask != 0) {
          node.group_masks.push_back(numa.GroupMasks[i]);
        }
      }

      // Memory-only nodes have no processors to run on
      if (!node.group_masks.empty()) {
        nodes.push_back(std::move(node));
      }
    }

    std::ranges::sort(nodes, {}, &WindowsNumaNode::id);
    return nodes;
  }

  return {};
}

[[nodiscard]] inline std::size_t LogicalProcessorCount() {
  return GetActiveProcessorCount(ALL_PROCESSOR_GROUPS);
}

}  // namespace detail

[[nodiscard]] inline bool ShouldConfigureNuma(std::size_t num_threads) {
  ULONG highest_node = 0;
  if (!GetNumaHighestNodeNumber(&highest_node)) {
    return false;
  }

  // Processes are confined to a single processor group by default before
  // Windows 11, so pinning matters with multiple groups even on one node
  if (highest_node == 0 && GetActiveProcessorGroupCount() <= 1) {
    return false;
  }

  // Only pin when claiming the majority of available threads
  if (num_threads <= detail::LogicalProcessorCount() / 2) {
    return false;
  }

  return true;
}

struct NumaNode {
  std::size_t id;
  std::vector<std::size_t> core_ids;
};

[[nodiscard]] inline std::vector<NumaNode> GetCoresPerNumaNode() {
  std::vector<NumaNode> nodes;
  for (const auto &[id, group_masks] : detail::QueryNumaNodes()) {
    std::vector<std::size_t> core_ids;
    for (const auto &affinity : group_masks) {
      for (std::size_t bit = 0; bit < sizeof(KAFFINITY) * 8; ++bit) {
        if (affinity.Mask & (KAFFINITY{1} << bit)) {
          core_ids.emplace_back(affinity.Group * sizeof(KAFFINITY) * 8 + bit);
        }
      }
    }
    nodes.push_back({id, std::move(core_ids)});
  }

  if (nodes.empty()) {
    std::vector<std::size_t> core_ids;
    for (std::size_t i = 0; i < detail::LogicalProcessorCount(); ++i) {
      core_ids.emplace_back(i);
    }

    nodes.push_back({0, std::move(core_ids)});
  }

  return nodes;
}

[[nodiscard]] inline std::size_t GetNumaNodeForThreadId(std::size_t thread_id) {
  thread_id %= detail::LogicalProcessorCount();

  std::size_t cores_seen = 0;
  for (const auto &[id, core_ids] : GetCoresPerNumaNode()) {
    if (thread_id < cores_seen + core_ids.size()) {
      return id;
    }
    cores_seen += core_ids.size();
  }

  return 0;
}

inline void PinThreadToNumaNode(std::size_t thread_id) {
  const auto nodes = detail::QueryNumaNodes();

  std::size_t total_cores = 0;
  for (const auto &node : nodes) {
    for (const auto &affinity : node.group_masks) {
      total_cores += std::popcount(affinity.Mask);
    }
  }

  if (total_cores == 0) {
    return;
  }

  thread_id %= total_cores;

  for (const auto &node : nodes) {
    for (auto affinity : node.group_masks) {
      const std::size_t group_cores = std::popcount(affinity.Mask);
      if (thread_id >= group_cores) {
        thread_id -= group_cores;
        continue;
      }

      const auto thread = GetCurrentThread();
      SetThreadGroupAffinity(thread, &affinity, nullptr);

      PROCESSOR_NUMBER ideal{};
      ideal.Group = affinity.Group;
      ideal.Number = static_cast<BYTE>(std::countr_zero(affinity.Mask));
      SetThreadIdealProcessorEx(thread, &ideal, nullptr);
      return;
    }
  }
}

}  // namespace numa

#elif defined(USE_NUMA)

#include <numa.h>
#include <sched.h>

#include <cassert>

namespace numa {

[[nodiscard]] inline bool ShouldConfigureNuma(std::size_t num_threads) {
  if (numa_available() == -1) {
    return false;
  }

  // Only pin when claiming the majority of available threads
  if (num_threads <= std::thread::hardware_concurrency() / 2) {
    return false;
  }

  return true;
}

struct NumaNode {
  std::size_t id;
  std::vector<std::size_t> core_ids;
};

[[nodiscard]] inline std::vector<NumaNode> GetCoresPerNumaNode() {
  std::vector<NumaNode> nodes;
  if (numa_available() != -1) {
    // Node ids can be sparse, so walk up to the highest id rather than the
    // configured node count
    for (int node = 0; node <= numa_max_node(); ++node) {
      const auto cpu_mask = numa_allocate_cpumask();
      if (numa_node_to_cpus(node, cpu_mask) != 0) {
        numa_free_cpumask(cpu_mask);
        continue;
      }

      std::vector<std::size_t> core_ids;
      for (std::size_t core_id = 0; core_id < cpu_mask->size; ++core_id) {
        if (numa_bitmask_isbitset(cpu_mask, core_id)) {
          core_ids.emplace_back(core_id);
        }
      }

      numa_free_cpumask(cpu_mask);

      // Memory-only nodes have no processors to run on
      if (!core_ids.empty()) {
        nodes.push_back({static_cast<std::size_t>(node), std::move(core_ids)});
      }
    }
  }

  if (nodes.empty()) {
    std::vector<std::size_t> core_ids;
    for (std::size_t i = 0; i < std::thread::hardware_concurrency(); ++i) {
      core_ids.emplace_back(i);
    }

    nodes.push_back({0, std::move(core_ids)});
  }

  assert(!nodes.empty());
  return nodes;
}

[[nodiscard]] inline std::size_t GetNumaNodeForThreadId(std::size_t thread_id) {
  thread_id %= std::thread::hardware_concurrency();

  std::size_t cores_seen = 0;
  for (const auto& [id, core_ids] : GetCoresPerNumaNode()) {
    if (thread_id < cores_seen + core_ids.size()) {
      return id;
    }
    cores_seen += core_ids.size();
  }

  return 0;
}

inline void PinThreadToNumaNode(std::size_t thread_id) {
  if (numa_available() == -1) {
    return;
  }

  const auto node = static_cast<int>(GetNumaNodeForThreadId(thread_id));
  numa_run_on_node(node);
  numa_set_preferred(node);
}

}  // namespace numa

#endif

#endif  // INTEGRAL_NUMA_H