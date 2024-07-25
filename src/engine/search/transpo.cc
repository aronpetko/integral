#include "transpo.h"

#include "../evaluation/evaluation.h"

// When saving a TT entry, we usually want to prefer newer entries only if
// they've been searched deeper. This lenience allows a maximum of four
constexpr int kDepthLenience = 4;

void TranspositionTable::Save(const U64 &key,
                              U16 ply,
                              const TranspositionTableEntry &entry) {
  auto &tt_entry = (*this)[key];
  const bool tt_hit = tt_entry.CompareKey(key);

  if (!tt_hit || entry.depth + kDepthLenience >= tt_entry.depth ||
      entry.flag == TranspositionTableEntry::kExact || tt_entry.age < age_) {
    const auto old_move = tt_entry.move;
    tt_entry = entry;
    tt_entry.age = age_;

    // Keep the old move if there is no best move being saved and if the key
    // matches
    if (!entry.move && tt_hit) {
      tt_entry.move = old_move;
    }

    // The ply is negated here since we're saving this entry
    tt_entry.score = TranspositionTableEntry::CorrectScore(entry.score, -ply);
  }
}

void TranspositionTable::Age() {
  age_ = (age_ + 1) % 64;
}

void TranspositionTable::Clear() {
  HashTable::Clear();
  age_ = 0;
}