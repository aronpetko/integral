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
        bits({}) {
    SetFlag(kNone);
  }

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
        bits({}) {
    SetWasPV(was_in_pv);
    SetFlag(flag);
  }

  // Keys are packed to maximize the number of entries the table can hold
  // Therefore, we must down-cast when checking for key equality
  [[nodiscard]] bool CompareKey(const U64 &test_key) const {
    return static_cast<U16>(test_key) == key;
  }

  // Check if the entry's score falls within the search window
  [[nodiscard]] bool CanUseScore(Score alpha, Score beta) const {
    const auto flag = GetFlag();
    return score != kScoreNone &&
           ((flag == kUpperBound && score <= alpha) ||
            (flag == kLowerBound && score >= beta) || flag == kExact);
  }

  // Adjusts mate scores to correctly indicate the ply until mate
  [[nodiscard]] static Score CorrectScore(Score score, U16 ply) {
    if (score >= kMateInMaxPlyScore) {
      score -= ply;
    } else if (score <= -kMateInMaxPlyScore) {
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
      U8 was_pv : 1;
      U8 flag : 2;
    } bits;
  };

  [[nodiscard]] U32 GetAge() const {
    return bits.age;
  }

  void SetAge(U32 age) {
    bits.age = age;
  }

  [[nodiscard]] bool GetWasPV() const {
    return bits.was_pv;
  }

  void SetWasPV(bool was_pv) {
    bits.was_pv = was_pv;
  }

  [[nodiscard]] Flag GetFlag() const {
    return static_cast<Flag>(bits.flag);
  }

  void SetFlag(Flag flag) {
    bits.flag = static_cast<U8>(flag);
  }
};

static_assert(sizeof(TranspositionTableEntry) == 10);

constexpr int kTTClusterSize = 3;

struct TranspositionTableCluster {
  std::array<TranspositionTableEntry, kTTClusterSize> entries;
  U16 padding;
};

constexpr int kMaxTTAge = 64;

class TranspositionTable : public AlignedHashTable<TranspositionTableCluster> {
 public:
  explicit TranspositionTable(std::size_t mb_size)
      : AlignedHashTable(mb_size), age_(0) {}

  TranspositionTable() : age_(0) {}

  [[nodiscard]] TranspositionTableEntry *Probe(const U64 &key);

  void Save(TranspositionTableEntry *old_entry,
            TranspositionTableEntry new_entry,
            const U64 &key,
            U16 ply);

  void Age();

  [[nodiscard]] int HashFull() const;

  virtual void Clear();

 private:
  [[nodiscard]] U32 GetAgeDelta(const TranspositionTableEntry *entry) const;

 private:
  int age_;
};

inline TranspositionTable transposition_table;

}  // namespace search

#endif  // INTEGRAL_TRANSPO_H_