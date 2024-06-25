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

  U16 key = 0;
  U8 depth = 0;
  Flag flag = kNone;
  Score score = kScoreNone;
  Score static_eval = kScoreNone;
  Move move = Move::NullMove();
};

class TranspositionTable : public HashTable<TranspositionTableEntry> {
 public:
  explicit TranspositionTable(std::size_t mb_size) : HashTable(mb_size) {}

  TranspositionTable() = default;

  void Save(const U64 &key, U16 ply, const TranspositionTableEntry &entry);
};

inline TranspositionTable transposition_table;

#endif  // INTEGRAL_TRANSPO_H_