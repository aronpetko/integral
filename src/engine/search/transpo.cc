#include "transpo.h"

#include "../evaluation/evaluation.h"

namespace search {

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
        entry->SetAge(age_);
        return entry;
      }
      // Always prefer the lowest quality entry
      const int lowest_quality =
          replace_entry->depth - GetAgeDelta(replace_entry);
      const int current_quality = entry->depth -  GetAgeDelta(entry);
      if (lowest_quality > current_quality) {
        replace_entry = entry;
      }
    }
  }

  return replace_entry;
}

void TranspositionTable::Save(TranspositionTableEntry *old_entry,
                              TranspositionTableEntry new_entry,
                              const U64 &key,
                              U16 ply,
                              bool in_pv) {
  if (new_entry.move || !old_entry->CompareKey(key)) {
    old_entry->move = new_entry.move;
  }

  if (!old_entry->CompareKey(key) ||
      new_entry.GetFlag() == TranspositionTableEntry::kExact ||
      new_entry.depth + 4 >= old_entry->depth) {
    new_entry.bits.age = age_;

    old_entry->key = static_cast<U16>(key);
    old_entry->score =
        TranspositionTableEntry::CorrectScore(new_entry.score, -ply);
    old_entry->depth = new_entry.depth;
    old_entry->bits = new_entry.bits;
    old_entry->static_eval = new_entry.static_eval;
  }
}

U32 TranspositionTable::GetAgeDelta(
    const TranspositionTableEntry *entry) const {
  return (kMaxTTAge + age_ - entry->GetAge()) % kMaxTTAge;
}

void TranspositionTable::Age() {
  age_ = (age_ + 1) % kMaxTTAge;
}

int TranspositionTable::HashFull() const {
  int count = 0;
  for (int i = 0; i < 1000; i++) {
    count +=
        std::ranges::count_if(table_[i].entries, [this](const auto &entry) {
          return entry.bits.age == age_ && entry.key != 0 &&
                 entry.score != kScoreNone;
        });
  }
  return count / kTTClusterSize;
}

void TranspositionTable::Clear() {
  AlignedHashTable::Clear();
  age_ = 0;
}

}  // namespace search