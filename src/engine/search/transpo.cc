#include "transpo.h"

#include "../evaluation/evaluation.h"

// When saving a TT entry, we usually want to prefer newer entries only if
// they've been searched deeper
constexpr int kDepthLenience = 4;

void TranspositionTable::Save(TranspositionTableEntry &entry,
                              U16 ply,
                              const TranspositionTableEntry &new_entry) {
  const bool key_matches = entry.CompareKey(new_entry.key);
  if (!entry.key || key_matches ||
      new_entry.depth + kDepthLenience >= entry.depth ||
      new_entry.flag == TranspositionTableEntry::kExact) {
    const auto old_move = entry.move;
    entry = new_entry;

    // Keep the old move if there is no best move being saved and if the key
    // matches
    if (!new_entry.move && key_matches) {
      entry.move = old_move;
    }

    // The ply is negated here since we're saving this entry
    entry.score = TranspositionTableEntry::CorrectScore(entry.score, -ply);
  }
}

TranspositionTableEntry &TranspositionTable::Probe(const U64 &key) {
  auto &cluster = (*this)[key];
  return cluster.MatchEntry(key);
}

void TranspositionTable::Prefetch(const U64 &key) {
  auto &entry = (*this)[key];
  __builtin_prefetch(&entry.entries[0]);
}