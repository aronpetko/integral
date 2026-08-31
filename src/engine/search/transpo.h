#ifndef INTEGRAL_TRANSPO_H_
#define INTEGRAL_TRANSPO_H_

#include <algorithm>
#include <array>
#include <bit>
#include <cassert>
#include <cstddef>
#include <tuple>

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
      : depth(0),
        score(kScoreNone),
        static_eval(0),
        move(Move::NullMove()),
        age(0),
        was_in_pv(false),
        flag(kNone) {}

  explicit TranspositionTableEntry(U8 depth,
                                   Flag flag,
                                   Score score,
                                   Score static_eval,
                                   Move move,
                                   bool was_in_pv)
      : depth(depth),
        score(score),
        static_eval(static_eval),
        move(move),
        age(0),
        was_in_pv(was_in_pv),
        flag(flag) {}

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

static_assert(sizeof(TranspositionTableEntry) == 8);

constexpr std::size_t kTTClusterSize = 3;
constexpr std::size_t kFragmentWidth = 16;
constexpr U64 kFragmentMask = (U64{1} << kFragmentWidth) - 1;
static_assert(kTTClusterSize * kFragmentWidth < 64);

struct TranspositionTableCluster {
  std::array<TranspositionTableEntry, kTTClusterSize> entries;
  U64 fragments;

  [[nodiscard]] U64 GetFragment(std::size_t idx) const {
    const std::size_t shift = idx * kFragmentWidth;
    return (fragments >> shift) & kFragmentMask;
  }

  void SetFragment(std::size_t idx, U64 fragment) {
    const std::size_t shift = idx * kFragmentWidth;
    fragments &= ~(kFragmentMask << shift);
    fragments |= fragment << shift;
  }

  [[nodiscard]] std::size_t LookupFragment(U64 fragment) const {
    constexpr U64 bits = U64{1} | (U64{1} << kFragmentWidth) |
                         (U64{1} << (kFragmentWidth * 2)) |
                         (U64{1} << (kFragmentWidth * 3));
    const U64 needle = bits * fragment;
    const U64 zeros = fragments ^ needle;
    const U64 matches =
        (zeros - bits) & ~zeros & (bits << (kFragmentWidth - 1));
    return static_cast<std::size_t>(std::countr_zero(matches) / kFragmentWidth);
  }

  constexpr static std::tuple<std::size_t, U64> SplitHash(std::size_t count,
                                                          U64 hash) {
    const U128 mul = static_cast<U128>(hash) * count;
    const std::size_t index = static_cast<std::size_t>(mul >> 64);
    // Fragments are packed to maximize the number of entries the table can
    // hold, so we only keep the bottom bits of the hash
    const U64 fragment = hash & kFragmentMask;
    return {index, fragment};
  }
};

static_assert(sizeof(TranspositionTableCluster) == 32);

constexpr int kMaxTTAge = 32;

class TranspositionTable : public AlignedHashTable<TranspositionTableCluster> {
 public:
  explicit TranspositionTable(std::size_t mb_size)
      : AlignedHashTable(mb_size), age_(0) {}

  TranspositionTable() : age_(0) {}

  [[nodiscard]] TranspositionTableEntry *Probe(const U64 &key, bool &hit);

  void Save(TranspositionTableEntry *old_entry,
            TranspositionTableEntry new_entry,
            const U64 &key,
            I32 ply,
            bool in_pv);

  void Prefetch(const U64 &key);

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