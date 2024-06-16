#ifndef INTEGRAL_TRANSPO_H_
#define INTEGRAL_TRANSPO_H_

#include <algorithm>
#include <cassert>
#include <cstddef>

#include "../../chess/move.h"
#include "../../utils/types.h"

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

  U16 key;
  U8 depth;
  Flag flag;
  Score score;
  Move move;
};

class TranspositionTable {
 public:
  explicit TranspositionTable(std::size_t mb_size);

  TranspositionTable() : table_size_(0ULL), used_entries_(0ULL) {}

  void Resize(std::size_t mb_size);

  void Clear();

  void Save(const U64 &key, U16 ply, const TranspositionTableEntry &entry);

  [[nodiscard]] const TranspositionTableEntry &Probe(const U64 &key) const;

  // Uses an intrinsic to cache this entry for faster probing
  void Prefetch(const U64 &key) const;

  // Adjusts mate scores to correctly indicate the ply until mate
  [[nodiscard]] Score CorrectScore(Score score, U16 ply) const;

  // Returns how much of the table has been filled with entries
  [[nodiscard]] int HashFull() const;

 private:
  [[nodiscard]] U64 Index(const U64 &key) const;

 private:
  std::vector<TranspositionTableEntry> table_;
  std::size_t table_size_;
  std::size_t used_entries_;
};

inline TranspositionTable transposition_table;

#endif  // INTEGRAL_TRANSPO_H_