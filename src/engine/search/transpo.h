#ifndef INTEGRAL_TRANSPO_H_
#define INTEGRAL_TRANSPO_H_

#include <algorithm>
#include <cassert>
#include <cstddef>

#include "../../chess/move.h"
#include "../../utils/hash_table.h"

struct TranspositionTableEntry {
  enum Flag : U8 {
    kNone,
    kExact,
    kLowerBound,
    kUpperBound
  };

  TranspositionTableEntry()
      : key(0), depth(0), flag(kNone), score(0), move(Move::NullMove()) {}

  explicit TranspositionTableEntry(
      U64 key, U8 depth, Flag flag, Score score, Move move)
      : key(static_cast<U16>(key)),
        depth(depth),
        flag(flag),
        score(score),
        move(move) {}

  // Keys are packed to maximize the number of entries the table can hold
  // Therefore, we must down-cast when checking for key equality
  [[nodiscard]] bool CompareKey(const U64 &test_key) const {
    return static_cast<U16>(test_key) == key;
  }

  // Check if the entry's score falls within the search window
  [[nodiscard]] bool CanUseScore(Score alpha, Score beta) const {
    return score != kScoreNone &&
           ((flag == kUpperBound && score <= alpha) ||
            (flag == kLowerBound && score >= beta) || flag == kExact);
  }

  // Adjusts mate scores to correctly indicate the ply until mate
  [[nodiscard]] static Score CorrectScore(Score score, U16 ply) {
    constexpr int kRoughlyMate = kMateScore - kMaxPlyFromRoot;
    if (score >= kRoughlyMate) {
      score -= ply;
    } else if (score <= -kRoughlyMate) {
      score += ply;
    }
    return score;
  }

  U16 key;
  Move move;
  Score score;
  U8 depth;
  Flag flag;
};

struct TranspositionTableCluster {
  [[nodiscard]] TranspositionTableEntry &MatchEntry(const U64 &test_key) {
    for (auto &entry : entries) {
      if (entry.CompareKey(test_key)) {
        return entry;
      }
    }
    // Just return the first one
    return entries[0];
  }

  std::array<TranspositionTableEntry, 3> entries;
};

class TranspositionTable : public HashTable<TranspositionTableCluster> {
 public:
  explicit TranspositionTable(std::size_t mb_size) : HashTable(mb_size) {}

  TranspositionTable() = default;

  void Save(const U64 &key, U16 ply, const TranspositionTableEntry &entry);

  [[nodiscard]] TranspositionTableEntry &Probe(const U64 &key);
};

inline TranspositionTable transposition_table;

#endif  // INTEGRAL_TRANSPO_H_