#include "transpo.h"

#include <thread>

#include "../evaluation/evaluation.h"

namespace search {

[[nodiscard]] TranspositionTableEntry *TranspositionTable::Probe(const U64 &key,
                                                                 bool &hit) {
  const auto [idx, fragment] =
      TranspositionTableCluster::SplitHash(table_size_, key);
  auto &cluster = table_[idx];

  // Default to replacing the first entry (if it's available)
  std::size_t entry_idx = 0;
  // Find another entry if the first one is already taken
  const U64 first_fragment = cluster.GetFragment(0);
  if (first_fragment != 0 && first_fragment != fragment) {
    int lowest_quality = cluster.entries[0].depth -
                         8 * static_cast<int>(GetAgeDelta(&cluster.entries[0]));

    for (std::size_t i = 1; i < kTTClusterSize; i++) {
      // If this entry is available, we can attempt to write to it
      const U64 entry_fragment = cluster.GetFragment(i);
      if (entry_fragment == 0 || entry_fragment == fragment) {
        entry_idx = i;
        break;
      }
      // Always prefer the lowest quality entry
      const auto entry = &cluster.entries[i];
      const int quality =
          entry->depth - 8 * static_cast<int>(GetAgeDelta(entry));
      if (quality < lowest_quality) {
        lowest_quality = quality;
        entry_idx = i;
      }
    }
  }

  hit = cluster.GetFragment(entry_idx) == fragment;
  return &cluster.entries[entry_idx];
}

void TranspositionTable::Save(TranspositionTableEntry *old_entry,
                              TranspositionTableEntry new_entry,
                              const U64 &key,
                              I32 ply,
                              bool in_pv) {
  const auto [idx, fragment] =
      TranspositionTableCluster::SplitHash(table_size_, key);
  auto &cluster = table_[idx];

  // The entry being written to was handed out by Probe for this same key, so
  // it always lives in this key's cluster
  const auto entry_idx =
      static_cast<std::size_t>(old_entry - cluster.entries.data());
  assert(entry_idx < kTTClusterSize);

  // Either Probe matched this key's fragment, or it picked this entry for
  // replacement
  const bool matched = cluster.GetFragment(entry_idx) == fragment;

  if (new_entry.move || !matched) {
    old_entry->move = new_entry.move;
  }

  if (!matched || new_entry.flag == TranspositionTableEntry::kExact ||
      new_entry.depth + 3 + 2 * in_pv >= old_entry->depth ||
      old_entry->age != age_) {
    new_entry.age = age_;
    // Keep the move that was just resolved above
    new_entry.move = old_entry->move;
    new_entry.score =
        TranspositionTableEntry::CorrectScore(new_entry.score, -ply);

    *old_entry = new_entry;
    cluster.SetFragment(entry_idx, fragment);
  }
}

void TranspositionTable::Prefetch(const U64 &key) {
  const auto [idx, fragment] =
      TranspositionTableCluster::SplitHash(table_size_, key);
  const auto &cluster = table_[idx];
  __builtin_prefetch(&cluster, 0, 2);
}

U32 TranspositionTable::GetAgeDelta(
    const TranspositionTableEntry *entry) const {
  return (kMaxTTAge + age_ - entry->age) % kMaxTTAge;
}

void TranspositionTable::Age() {
  age_ = (age_ + 1) % kMaxTTAge;
}

int TranspositionTable::HashFull() const {
  int count = 0;
  for (int i = 0; i < 1000; i++) {
    count +=
        std::ranges::count_if(table_[i].entries, [this](const auto &entry) {
          return entry.age == age_ &&
                 entry.flag != TranspositionTableEntry::kNone;
        });
  }
  return count / static_cast<int>(kTTClusterSize);
}

void TranspositionTable::Clear(int num_threads) {
  const std::size_t chunks = (table_size_ + num_threads - 1) / num_threads;

  std::vector<std::thread> threads;
  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back([i, chunks, this]() {
      const std::size_t clear_index = chunks * i;
      const std::size_t clear_size =
          std::min(chunks, table_size_ - clear_index) *
          sizeof(TranspositionTableCluster);
      std::memset(table_ + clear_index, 0, clear_size);
    });
  }

  for (auto &thread : threads) {
    thread.join();
  }

  age_ = 0;
}

}  // namespace search