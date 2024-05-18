#ifndef INTEGRAL_TRANSPO_H_
#define INTEGRAL_TRANSPO_H_

#include <algorithm>
#include <cassert>
#include <cstddef>

#include "../chess/move.h"
#include "../utils/types.h"

class TranspositionTable {
 public:
  struct Entry {
    enum Flag : U8 {
      kNone,
      kExact,
      kLowerBound,
      kUpperBound
    };

    Entry() : key(0), depth(0), flag(kNone), score(0), move(Move::NullMove()) {}

    explicit Entry(U64 key, U8 depth, Flag flag, Score score, Move move)
        : key(static_cast<U16>(key)),
          depth(depth),
          flag(flag),
          score(score),
          move(move) {}

    [[nodiscard]] bool CompareKey(const U64 &test_key) const {
      return static_cast<U16>(test_key) == key;
    }

    [[nodiscard]] bool CanUseScore(Score alpha, Score beta) const {
      return score != kScoreNone &&
             (flag == kUpperBound && score <= alpha ||
              flag == kLowerBound && score >= beta || flag == kExact);
    }

    U16 key;
    U8 depth;
    Flag flag;
    Score score;
    Move move;
  };

  explicit TranspositionTable(std::size_t mb_size);

  TranspositionTable() : table_size_(0ULL), used_entries_(0ULL) {}

  void Resize(std::size_t mb_size);

  void Clear();

  void Save(const U64 &key, const Entry &entry, U16 ply);

  void Prefetch(const U64 &key) const;

  [[nodiscard]] const Entry &Probe(const U64 &key) const;

  [[nodiscard]] int CorrectScore(Score score, U16 ply) const;

  [[nodiscard]] U64 Index(const U64 &key) const;

  [[nodiscard]] int HashFull() const;

 private:
  std::vector<Entry> table_;
  std::size_t table_size_;
  std::size_t used_entries_;
};

inline TranspositionTable transposition_table;

#endif  // INTEGRAL_TRANSPO_H_