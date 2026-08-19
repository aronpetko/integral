#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "perspective_accumulator.h"
#include "psqt_accumulator.h"
#include "threat_accumulator.h"

namespace nnue {

struct AccumulatorEntry {
  alignas(simd::kAlignment)
      std::array<PsqtPerspectiveAccumulator, 2> perspectives;
  alignas(simd::kAlignment)
      std::array<ThreatPerspectiveAccumulator, 2> threat_perspectives;
  PsqtAccumulatorChange change;
  std::array<Square, 2> kings;
  std::array<bool, 2> updated;
  // Threats have no delta chain to walk, so they get their own flag and are
  // refreshed on first read rather than propagated forward.
  std::array<bool, 2> threat_valid;
  BoardState state;
};

// Finny table entry: the cached accumulator for one (mirrored, king bucket)
// pair, plus the piece layout it was built from, so a refresh can diff against
// it instead of rebuilding from an empty board.
struct BucketCacheEntry {
  AccumulatorEntry accumulator;
  MultiArray<BitBoard, 2, kNumPieceTypes> piece_bbs{};
  MultiArray<BitBoard, 2, kNumColors> side_bbs{};

  BucketCacheEntry() { Reset(); }

  void Reset();
};

struct PerspectiveView {
  PsqtPerspectiveAccumulator& psqt;
  ThreatPerspectiveAccumulator& threat;
};

class Accumulator {
 public:
  Accumulator() : head_idx_(0) { stack_.resize(512); }

  void SetFromState(const BoardState& state);
  void RefreshPerspective(AccumulatorEntry& __restrict__ accumulator,
                          const BoardState& __restrict__ state,
                          Color perspective,
                          bool reset = false);

  void PushChanges(const BoardState& state, PsqtAccumulatorChange& change);
  void ApplyChanges();

  void EnsureThreatsFresh();

  [[nodiscard]] bool NeedRefresh(Color perspective,
                                 Square old_king,
                                 Square new_king) const;

  void IncrementHead();
  void UndoMove() { --head_idx_; }

  [[nodiscard]] int GetOutputBucket(const BoardState& state) const;

  [[nodiscard]] PerspectiveView operator[](int perspective) {
    auto& entry = stack_[head_idx_];
    return {entry.perspectives[perspective],
            entry.threat_perspectives[perspective]};
  }

 private:
  [[nodiscard]] int GetKingBucket(Square king_square, Color king_color) const;

  int head_idx_;
  std::vector<AccumulatorEntry> stack_;
  // Finny tables: [mirrored][king bucket].
  MultiArray<BucketCacheEntry, 2, arch::kInputBucketCount> input_bucket_cache_;
};

}  // namespace nnue

#endif  // INTEGRAL_ACCUMULATOR_H