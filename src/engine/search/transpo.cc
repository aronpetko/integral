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
        break;
      }
      // Always prefer the lowest quality entry
      const int lowest_quality =
          replace_entry->depth - GetAgeDelta(replace_entry) * 4;
      const int current_quality = entry->depth - GetAgeDelta(entry) * 4;
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
  new_entry.age = age_;
  // Prefer to replace entries that are very old even if they're far greater
  // than the current depth
  const int new_quality =
      new_entry.depth + std::pow(GetAgeDelta(&new_entry), 2) / 4;
  const int old_quality = old_entry->depth;

  const bool tt_hit = old_entry->CompareKey(key);
  if (!tt_hit ||
      (new_entry.flag == TranspositionTableEntry::kExact &&
       old_entry->flag != TranspositionTableEntry::kExact) ||
      new_quality * 3 >= old_quality * 2) {
    const auto old_move = old_entry->move;
    *old_entry = new_entry;

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
  return (kMaxTTAge + age_ - entry->age) % kMaxTTAge;
}

void TranspositionTable::Age() {
  age_ = (age_ + 1) % kMaxTTAge;
}

void TranspositionTable::Clear() {
  HashTable::Clear();
  age_ = 0;
}