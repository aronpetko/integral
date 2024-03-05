#ifndef INTEGRAL_TRANSPO_H_
#define INTEGRAL_TRANSPO_H_

#include "types.h"
#include "move.h"

#include <cassert>

class TranspositionTable {
 public:
  struct Entry {
    enum Flag : U8 {
      kExact,
      kLowerBound,
      kUpperBound
    };

    explicit Entry() : key(0ULL), depth(0), flag(Flag::kExact), evaluation(0) {}

    U64 key;
    U8 depth;
    Flag flag;
    int evaluation;
    Move best_move;
  };

  explicit TranspositionTable(int mb_size);

  void resize(std::size_t mb_size);

  void clear();

  void save(const Entry &entry);

  const Entry *probe(U64 key) const;

 private:
  Entry* table_;

  std::size_t table_size_;
};

#endif // INTEGRAL_TRANSPO_H_