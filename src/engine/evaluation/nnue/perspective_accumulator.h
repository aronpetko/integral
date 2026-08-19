#ifndef INTEGRAL_PERSPECTIVE_ACCUMULATOR_H
#define INTEGRAL_PERSPECTIVE_ACCUMULATOR_H

#include "../../../../shared/nnue/definitions.h"
#include "../../../../shared/simd.h"
#include "../../../chess/board.h"
#include "../../../chess/move_gen.h"
#include "../../../utils/fused.h"
#include "../../../utils/list.h"
#include "nnue.h"
#include <span>

namespace nnue {

// clang-format off
constexpr std::array<int, 64> kKingBucketMap {
  0,  1,  2,  3,  3,  2,  1,  0,
  4,  5,  6,  7,  7,  6,  5,  4,
  8,  8,  9,  9,  9,  9,  8,  8,
  10, 10, 10, 10, 10, 10, 10, 10,
  10, 10, 10, 10, 10, 10, 10, 10,
  11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11,
};
// clang-format on

constexpr U8 kBucketDivisor =
    (32 + arch::kOutputBucketCount - 1) / arch::kOutputBucketCount;

struct FeatureData {
  Square square = Squares::kNoSquare;
  PieceType piece = PieceType::kNone;
  Color color = Color::kNoColor;
};

template <typename FeaturePolicy>
class PerspectiveAccumulator {
 public:
  static constexpr int kWidth = FeaturePolicy::kWidth;
  // The accumulator's storage type and the feature weights' type are
  // independent: threat rows are I8 while the running sum stays I16.
  using Value = typename FeaturePolicy::Value;
  using Weight = typename FeaturePolicy::Weight;

  // Vector tiling used when rows are folded into the accumulator. A tile is
  // the slice of the accumulator kept in registers while rows stream over it.
  static constexpr std::size_t kChunk = simd::kNativeLanes<Value>;
  static constexpr std::size_t kChunks = kWidth / kChunk;
#if BUILD_HAS_AVX512
  static constexpr std::size_t kTileTarget = 32;
#else
  static constexpr std::size_t kTileTarget = 8;
#endif
  static constexpr std::size_t kTile =
      kChunks < kTileTarget ? kChunks : kTileTarget;

  using ValueVector = simd::Vector<Value, kChunk>;

  static_assert(kWidth % kChunk == 0);
  static_assert(kChunks % kTile == 0);

  PerspectiveAccumulator() : values_({}) {}

  void Reset() {
    for (int i = 0; i < kWidth; ++i) {
      values_[i] = FeaturePolicy::Bias(i);
    }
  }

  void Refresh(const BoardState& state, Color perspective, Square king_square) {
    // A refresh can carry far more rows than a delta, so they're gathered and
    // folded in a batch at a time instead of walking the whole accumulator once
    // per row. The batch size bounds the stack use.
    static constexpr int kBatchSize = 64;
    std::array<Weight const*, kBatchSize> rows;
    int num_rows = 0;

    Reset();
    FeaturePolicy::ForEachActiveFeature(
        state, perspective, king_square, [&](Weight const* row) {
          rows[num_rows++] = row;
          if (num_rows == kBatchSize) {
            ApplyRows(*this, rows.data(), num_rows, nullptr, 0);
            num_rows = 0;
          }
        });

    if (num_rows > 0) {
      ApplyRows(*this, rows.data(), num_rows, nullptr, 0);
    }
  }

  // Folds every row in on a single pass: one tile of the accumulator is held in
  // registers while all the sub and add rows stream over that tile, so the
  // accumulator is loaded and stored exactly once no matter how many rows the
  // change carries.
  void ApplyRows(const PerspectiveAccumulator& previous,
                 Weight const* const* adds,
                 int num_adds,
                 Weight const* const* subs,
                 int num_subs) {
    for (std::size_t base = 0; base < kChunks; base += kTile) {
      std::array<ValueVector, kTile> values;

      for (std::size_t tile = 0; tile < kTile; ++tile) {
        values[tile] =
            simd::Load<Value, kChunk>(&previous.values_[(base + tile) * kChunk]);
      }

      for (int sub = 0; sub < num_subs; ++sub) {
        for (std::size_t tile = 0; tile < kTile; ++tile) {
          values[tile] -= simd::Convert<Value>(
              simd::Load<Weight, kChunk>(&subs[sub][(base + tile) * kChunk]));
        }
      }

      for (int add = 0; add < num_adds; ++add) {
        for (std::size_t tile = 0; tile < kTile; ++tile) {
          values[tile] += simd::Convert<Value>(
              simd::Load<Weight, kChunk>(&adds[add][(base + tile) * kChunk]));
        }
      }

      for (std::size_t tile = 0; tile < kTile; ++tile) {
        simd::Store<Value, kChunk>(&values_[(base + tile) * kChunk],
                                   values[tile]);
      }
    }
  }

  void ApplyDeltas(const PerspectiveAccumulator& previous,
                   Weight const* const* adds,
                   int num_adds,
                   Weight const* const* subs,
                   int num_subs) {
    ApplyRows(previous, adds, num_adds, subs, num_subs);
  }

  Value& operator[](int idx) {
    return values_[idx];
  }
  const Value& operator[](int idx) const {
    return values_[idx];
  }

 protected:
  alignas(simd::kAlignment) std::array<Value, kWidth> values_;
};

}  // namespace nnue

#endif  // INTEGRAL_PERSPECTIVE_ACCUMULATOR_H