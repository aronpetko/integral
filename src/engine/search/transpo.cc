#include "transpo.h"

#include "../evaluation/evaluation.h"

[[nodiscard]] TranspositionTableEntry *TranspositionTable::Probe(
    const U64 &key) {
  auto &cluster = (*this)[key];
  // Default to replacing the first entry (if it's available)
  auto replace_entry = &cluster.entries[0];
  // Find another entry if the first one is already taken
  if (replace_entry->key != 0 && !replace_entry->CompareKey(key)) {
    for (int i = 1; i < kTTClusterSize; i++) {
      const auto entry = &cluster.entries[i];
      // If this entry is available, we can attempt to write to it
      if (entry->key == 0 || entry->CompareKey(key)) {
        replace_entry = entry;
        replace_entry->age = age_;
        break;
      }
      // Always prefer the lowest quality entry
      const int lowest_quality =
          replace_entry->depth - GetAgeDelta(replace_entry);
      const int current_quality = entry->depth - GetAgeDelta(entry);
      if (current_quality <= lowest_quality) {
        replace_entry = entry;
      }
    }
  }

  return replace_entry;
}

void TranspositionTable::Save(TranspositionTableEntry *old_entry,
                              TranspositionTableEntry new_entry,
                              const U64 &key,
                              U16 ply) {
  const bool tt_hit = old_entry->CompareKey(key);
  if (!tt_hit ||
      (new_entry.flag == TranspositionTableEntry::kExact &&
       old_entry->flag != TranspositionTableEntry::kExact) ||
      new_entry.depth + 2 * new_entry.was_in_pv + 2 > old_entry->depth) {
    const auto old_move = old_entry->move;
    *old_entry = new_entry;
    old_entry->age = age_;

    // Keep the old move if there is no best move being saved and if the key
    // matches
    if (!new_entry.move && tt_hit) {
      old_entry->move = old_move;
    }

    // The ply is negated here since we're saving this entry
    old_entry->score =
        TranspositionTableEntry::CorrectScore(new_entry.score, -ply);
  }
}

int TranspositionTable::GetAgeDelta(
    const TranspositionTableEntry *entry) const {
  return (kMaxTTAge + age_ - entry->age) & (kMaxTTAge - 1);
}

void TranspositionTable::Age() {
  age_ = (age_ + 1) % kMaxTTAge;
}

int TranspositionTable::HashFull() const {
  int count = 0;
  for (int i = 0; i < 1000; i++) {
    for (const auto &entry : table_[i].entries) {
      count += entry.age == age_ && entry.score != kScoreNone;
    }
  }
  return count / kTTClusterSize;
}

void TranspositionTable::Clear() {
  AlignedHashTable::Clear();
  age_ = 0;
}