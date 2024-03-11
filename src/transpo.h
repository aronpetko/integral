#ifndef INTEGRAL_TRANSPO_H_
#define INTEGRAL_TRANSPO_H_

#include "types.h"
#include "move.h"

#include <cstddef>
#include <cassert>

class TranspositionTable {
 public:
  struct Entry {
    enum Flag : U8 {
      kExact,
      kLowerBound,
      kUpperBound
    };

    explicit Entry() : key(0), depth(0), flag(kExact), evaluation(0), best_move({}) {}

    U64 key;
    U8 depth;
    Flag flag;
    int evaluation;
    Move best_move;
  };

  explicit TranspositionTable(std::size_t mb_size);

  TranspositionTable() : table_size_(0) {}

  void resize(std::size_t mb_size);

  void clear();

  void save(const Entry &entry, int ply);

  [[nodiscard]] const Entry &probe(U64 key) const;

 private:
  std::vector<Entry> table_;

  std::size_t table_size_;
};

#endif // INTEGRAL_TRANSPO_H_