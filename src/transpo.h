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
      kAlpha,
      kBeta
    };

    explicit Entry() : hash(0ULL), depth(0), flag(Flag::kExact), evaluation(0) {}

    U64 hash;
    U8 depth;
    Flag flag;
    int evaluation;
    Move best_move;
  };

  explicit TranspositionTable(int mb_size) {
    resize(mb_size);
  }

  void resize(int mb_size) {
    assert(mb_size >= 0);

    const int kBytesInMegabyte = 1048576;
    table_.clear();
    table_.resize(mb_size * kBytesInMegabyte / sizeof(Entry));
  }

  Entry *operator[](U64 key) {
    return &table_[key % table_.size()];
  }

 private:
  std::vector<Entry> table_;
};

#endif // INTEGRAL_TRANSPO_H_