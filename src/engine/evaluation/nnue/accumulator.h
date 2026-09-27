#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "perspective_accumulator.h"
#include "psqt_accumulator.h"
#include "threat_accumulator.h"

namespace nnue {

struct AccumulatorEntry {
  alignas(simd::kAlignment)
      std::array<PsqtPerspectiveAccumulator, 2> psqt_perspectives;
  alignas(simd::kAlignment)
      std::array<ThreatPerspectiveAccumulator, 2> threat_perspectives;
  PsqtAccumulatorChange psqt_change;
  std::array<Square, 2> kings;
  std::array<bool, 2> updated;
  // The squares the move into this node changed the occupant of
  BitBoard threat_updated_squares;
  // The board state this entry's move was made from
  const BoardState* previous_state;
};

struct BucketCacheEntry {
  AccumulatorEntry accumulator;
  MultiArray<BitBoard, 2, kNumPieceTypes> piece_bbs{};
  MultiArray<BitBoard, 2, kNumColors> side_bbs{};

  BucketCacheEntry() {
    Reset();
  }

  void Reset();
};

struct PerspectiveView {
  PsqtPerspectiveAccumulator& psqt;
  ThreatPerspectiveAccumulator& threat;
};

class Accumulator {
 public:
  Accumulator() : head_idx_(0) {
    stack_.resize(512);
  }

  void SetFromState(const BoardState& state);
  void RefreshPerspective(AccumulatorEntry& __restrict__ accumulator,
                          const BoardState& __restrict__ state,
                          Color perspective,
                          bool reset = false);

  void PushChanges(const BoardState& previous_state,
                   PsqtAccumulatorChange& psqt_change);
  void ApplyChanges(const BoardState& current_state);

  [[nodiscard]] bool NeedRefresh(Color perspective,
                                 Square old_king,
                                 Square new_king) const;
  // Threat rows are only keyed on whether the king is mirrored, so a king
  // bucket change on its own doesn't invalidate them.
  [[nodiscard]] static bool NeedThreatRefresh(Square old_king, Square new_king);

  void IncrementHead();
  void UndoMove() {
    --head_idx_;
  }

  [[nodiscard]] int GetOutputBucket(const BoardState& state) const;

  [[nodiscard]] PerspectiveView operator[](int perspective) {
    auto& entry = stack_[head_idx_];
    return {entry.psqt_perspectives[perspective],
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