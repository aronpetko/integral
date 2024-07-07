#include "transpo.h"

#include "../evaluation/evaluation.h"

// When saving a TT entry, we usually want to prefer newer entries only if
// they've been searched deeper
constexpr int kDepthLenience = 4;

void TranspositionTable::Save(const U64 &key,
                              U16 ply,
                              const TranspositionTableEntry &new_entry) {
  auto &cluster = (*this)[key];
  for (auto &entry : cluster.entries) {
    const bool key_matches = entry.CompareKey(key);
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
}

TranspositionTableEntry &TranspositionTable::Probe(
    const U64 &key) {
  auto &cluster = (*this)[key];
  for (auto &entry : cluster.entries) {
    if (entry.CompareKey(key)) {
      return entry;
    }
  }
  // Just return the first entry if we can't find a valid one
  return cluster.entries[0];
}