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
      kExact,
      kLowerBound,
      kUpperBound
    };

    Entry() : key(0), depth(0), flag(kExact), score(0), move(Move::null_move()) {}

    explicit Entry(U64 key, U8 depth, Flag flag, int score, Move move) : key(static_cast<U16>(key)), depth(depth), flag(flag), score(score), move(move) {}

    [[nodiscard]] bool compare_key(const U64 &test_key) const {
      return static_cast<U16>(test_key) == key;
    }

    U16 key;
    U8 depth;
    Flag flag;
    int score;
    Move move;
  };

  explicit TranspositionTable(std::size_t mb_size);

  TranspositionTable() : table_size_(0ULL), used_entries_(0ULL) {}

  void resize(std::size_t mb_size);

  void clear();

  void save(const U64 &key, const Entry &entry, int ply);

  void prefetch(const U64 &key) const;

  [[nodiscard]] const Entry &probe(const U64 &key) const;

  [[nodiscard]] int correct_score(int evaluation, int ply) const;

  [[nodiscard]] U64 index(const U64 &key) const;

  [[nodiscard]] int hash_full() const;

 private:
  std::vector<Entry> table_;
  std::size_t table_size_;
  std::size_t used_entries_;
};

inline TranspositionTable transposition_table;

#endif // INTEGRAL_TRANSPO_H_