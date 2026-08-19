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

  PerspectiveAccumulator() : values_({}) {}

  void Reset() {
    for (int i = 0; i < kWidth; ++i) {
      values_[i] = FeaturePolicy::Bias(i);
    }
  }

  void Refresh(const BoardState& state, Color perspective, Square king_square) {
    Reset();
    FeaturePolicy::ForEachActiveFeature(
        state, perspective, king_square, [&](Weight const* row) {
          for (int i = 0; i < kWidth; ++i) {
            values_[i] += row[i];
          }
        });
  }

  void ApplyDeltas(const PerspectiveAccumulator& previous,
                   Weight const* const* adds,
                   int num_adds,
                   Weight const* const* subs,
                   int num_subs) {
    if (this != &previous) {
      for (int i = 0; i < kWidth; ++i) {
        values_[i] = previous.values_[i];
      }
    }
    for (; num_adds >= 4; num_adds -= 4) {
      for (int i = 0; i < kWidth; ++i) {
        values_[i] += adds[num_adds - 4][i] + adds[num_adds - 3][i] +
                      adds[num_adds - 2][i] + adds[num_adds - 1][i];
      }
    }
    for (; num_adds >= 1; num_adds -= 1) {
      for (int i = 0; i < kWidth; ++i) {
        values_[i] += adds[num_adds - 1][i];
      }
    }
    for (; num_subs >= 4; num_subs -= 4) {
      for (int i = 0; i < kWidth; ++i) {
        values_[i] -= subs[num_subs - 4][i] + subs[num_subs - 3][i] +
                      subs[num_subs - 2][i] + subs[num_subs - 1][i];
      }
    }
    for (; num_subs >= 1; num_subs -= 1) {
      for (int i = 0; i < kWidth; ++i) {
        values_[i] -= subs[num_subs - 1][i];
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