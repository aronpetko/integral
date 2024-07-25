#ifndef INTEGRAL_TRANSPO_H_
#define INTEGRAL_TRANSPO_H_

#include <algorithm>
#include <cassert>
#include <cstddef>

#include "../../chess/move.h"
#include "../../utils/hash_table.h"

struct TranspositionTableEntry {
  enum Flag : U8 {
    kExact,
    kLowerBound,
    kUpperBound
  };

  TranspositionTableEntry()
      : key(0),
        depth(0),
        score(0),
        flag(kExact),
        age(0),
        move(Move::NullMove()),
        was_in_pv(false) {}

  explicit TranspositionTableEntry(U64 key,
                                   U8 depth,
                                   Flag flag,
                                   Score score,
                                   Move move,
                                   bool was_in_pv)
      : key(static_cast<U16>(key)),
        depth(depth),
        flag(flag),
        age(0),
        score(score),
        move(move),
        was_in_pv(was_in_pv) {}

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
  U8 depth;
  struct {
    U8 age : 6;
    Flag flag : 2;
  };
  Score score;
  Move move;
  bool was_in_pv;
};

class TranspositionTable : public HashTable<TranspositionTableEntry> {
 public:
  explicit TranspositionTable(std::size_t mb_size) : HashTable(mb_size), age_(0) {}

  TranspositionTable() : age_(0) {}

  void Save(const U64 &key, U16 ply, const TranspositionTableEntry &entry);

  void Age();

 private:
  int age_;
};

inline TranspositionTable transposition_table;

#endif  // INTEGRAL_TRANSPO_H_