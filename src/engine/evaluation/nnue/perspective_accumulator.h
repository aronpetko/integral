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

// How many accumulator vectors a tile keeps live at once. A tile stays in
// registers while every feature row is applied to it, so it has to leave room
// for the widened row loads it is accumulating; half the register file is a
// safe budget.
#if BUILD_HAS_AVX512
constexpr int kMaxTileVectors = 12;
#else
constexpr int kMaxTileVectors = 8;
#endif

// The largest tile that still divides the accumulator width evenly, so the
// tile loop never needs a scalar tail.
constexpr int ComputeTileVectors(int width, int lanes, int max_vectors) {
  for (int vectors = max_vectors; vectors > 1; --vectors) {
    if (width % (vectors * lanes) == 0) {
      return vectors;
    }
  }
  return 1;
}

template <typename FeaturePolicy>
class PerspectiveAccumulator {
 public:
  static constexpr int kWidth = FeaturePolicy::kWidth;
  // The accumulator's storage type and the feature weights' type are
  // independent: threat rows are I8 while the running sum stays I16.
  using Value = typename FeaturePolicy::Value;
  using Weight = typename FeaturePolicy::Weight;

  static constexpr int kLanes = simd::kNativeLanes<Value>;
  static constexpr int kTileVectors =
      ComputeTileVectors(kWidth, kLanes, kMaxTileVectors);
  static constexpr int kTileWidth = kTileVectors * kLanes;
  static_assert(kWidth % kTileWidth == 0);

  // A sweep that carries both perspectives at once holds two tiles live, so
  // each one gets half of the register budget.
  static constexpr int kPairedTileVectors =
      ComputeTileVectors(kWidth, kLanes, kMaxTileVectors / 2);
  static constexpr int kPairedTileWidth = kPairedTileVectors * kLanes;
  static_assert(kWidth % kPairedTileWidth == 0);

  static constexpr int kRefreshBatchSize = 64;

  using ValueVector = simd::Vector<Value, kLanes>;

  PerspectiveAccumulator() : values_({}) {}

  void Reset() {
    for (int i = 0; i < kWidth; ++i) {
      values_[i] = FeaturePolicy::Bias(i);
    }
  }

  void Refresh(const BoardState& state, Color perspective, Square king_square) {
    Reset();

    std::array<Weight const*, kRefreshBatchSize> rows;
    int num_rows = 0;
    FeaturePolicy::ForEachActiveFeature(
        state, perspective, king_square, [&](Weight const* row) {
          rows[num_rows++] = row;
          if (num_rows == kRefreshBatchSize) {
            ApplyDeltas(*this, rows.data(), num_rows, nullptr, 0);
            num_rows = 0;
          }
        });
    if (num_rows > 0) {
      ApplyDeltas(*this, rows.data(), num_rows, nullptr, 0);
    }
  }

  void ApplyDeltas(const PerspectiveAccumulator& previous,
                   Weight const* const* adds,
                   int num_adds,
                   Weight const* const* subs,
                   int num_subs) {
    for (int base = 0; base < kWidth; base += kTileWidth) {
      ValueVector tile[kTileVectors];
      for (int vec = 0; vec < kTileVectors; ++vec) {
        tile[vec] =
            simd::Load<Value, kLanes>(&previous.values_[base + vec * kLanes]);
      }

      for (int i = 0; i < num_adds; ++i) {
        Weight const* row = adds[i] + base;
        for (int vec = 0; vec < kTileVectors; ++vec) {
          tile[vec] += simd::Convert<Value>(
              simd::Load<Weight, kLanes>(row + vec * kLanes));
        }
      }
      for (int i = 0; i < num_subs; ++i) {
        Weight const* row = subs[i] + base;
        for (int vec = 0; vec < kTileVectors; ++vec) {
          tile[vec] -= simd::Convert<Value>(
              simd::Load<Weight, kLanes>(row + vec * kLanes));
        }
      }

      for (int vec = 0; vec < kTileVectors; ++vec) {
        simd::Store<Value, kLanes>(&values_[base + vec * kLanes], tile[vec]);
      }
    }
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