#include "transpo.h"

#include <cstdint>
#include <thread>

#include "../evaluation/evaluation.h"

namespace search {

[[nodiscard]] TranspositionTableEntry *TranspositionTable::Probe(const U64 &key,
                                                                 bool &hit) {
  const auto [idx, fragment] =
      TranspositionTableCluster::SplitHash(table_size_, key);
  auto &cluster = table_[idx];

  // Take the first entry that either matches this key or has never been
  // written to, whichever comes first in the cluster
  std::size_t entry_idx =
      std::min(cluster.LookupFragment(fragment), cluster.LookupEmpty());

  // Neither exists, so fall back to replacing the lowest quality entry
  if (entry_idx >= kTTClusterSize) {
    entry_idx = 0;
    int lowest_quality = cluster.entries[0].depth -
                         8 * static_cast<int>(GetAgeDelta(&cluster.entries[0]));

    for (std::size_t i = 1; i < kTTClusterSize; i++) {
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
  const U64 fragment = TranspositionTableCluster::Fragment(key);

  // Probe handed out this entry for this same key, so its cluster can be
  // recovered from the pointer rather than hashing the key a second time
  static_assert((sizeof(TranspositionTableCluster) &
                 (sizeof(TranspositionTableCluster) - 1)) == 0);
  auto &cluster = *reinterpret_cast<TranspositionTableCluster *>(
      reinterpret_cast<std::uintptr_t>(old_entry) &
      ~(sizeof(TranspositionTableCluster) - 1));
  const auto entry_idx =
      static_cast<std::size_t>(old_entry - cluster.entries.data());
  assert(entry_idx < kTTClusterSize);
  assert(&cluster == &table_[std::get<0>(TranspositionTableCluster::SplitHash(
                         table_size_, key))]);

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
  static_assert((kMaxTTAge & (kMaxTTAge - 1)) == 0);
  return static_cast<U32>(kMaxTTAge + age_ - entry->age) & (kMaxTTAge - 1);
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