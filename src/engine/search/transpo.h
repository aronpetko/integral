#ifndef INTEGRAL_TRANSPO_H_
#define INTEGRAL_TRANSPO_H_

#include <algorithm>
#include <cassert>
#include <cstddef>

#include "../../chess/move.h"
#include "../../utils/hash_table.h"

namespace search {

struct TranspositionTableEntry {
  enum Flag : U8 {
    kNone,
    kExact,
    kLowerBound,
    kUpperBound
  };

  TranspositionTableEntry()
      : key(0),
        depth(0),
        score(kScoreNone),
        static_eval(0),
        move(Move::NullMove()),
        age(0),
        was_in_pv(false),
        flag(kNone) {}

  explicit TranspositionTableEntry(U64 key,
                                   U8 depth,
                                   Flag flag,
                                   Score score,
                                   Score static_eval,
                                   Move move,
                                   bool was_in_pv)
      : key(static_cast<U16>(key)),
        depth(depth),
        score(score),
        static_eval(static_eval),
        move(move),
        age(0),
        was_in_pv(was_in_pv),
        flag(flag) {}

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
  [[nodiscard]] static Score CorrectScore(Score score, I32 ply) {
    if (score >= kTBWinInMaxPlyScore) {
      score -= ply;
    } else if (score <= -kTBWinInMaxPlyScore) {
      score += ply;
    }
    return score;
  }

  U16 key;
  I16 score, static_eval;
  Move move;
  U8 depth;
  union {
    struct {
      U8 age : 5;
      U8 was_in_pv : 1;
      U8 flag : 2;
    };
    U8 extra_bits;
  };
};

static_assert(sizeof(TranspositionTableEntry) == 10);

constexpr int kTTClusterSize = 3;

struct TranspositionTableCluster {
  std::array<TranspositionTableEntry, kTTClusterSize> entries;
  U16 padding;
};

constexpr int kMaxTTAge = 32;

class TranspositionTable : public AlignedHashTable<TranspositionTableCluster> {
 public:
  explicit TranspositionTable(std::size_t mb_size)
      : AlignedHashTable(mb_size), age_(0) {}

  TranspositionTable() : age_(0) {}

  [[nodiscard]] TranspositionTableEntry *Probe(const U64 &key);

  void Save(TranspositionTableEntry *old_entry,
            TranspositionTableEntry new_entry,
            const U64 &key,
            I32 ply,
            bool in_pv);

  void Age();

  [[nodiscard]] int HashFull() const;

  void Clear(int num_threads);

 private:
  [[nodiscard]] U32 GetAgeDelta(const TranspositionTableEntry *entry) const;

 private:
  int age_;
};

}  // namespace search

#endif  // INTEGRAL_TRANSPO_H_