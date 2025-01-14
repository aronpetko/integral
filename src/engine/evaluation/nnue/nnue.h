#ifndef INTEGRAL_NNUE_H
#define INTEGRAL_NNUE_H

#include "../../../chess/board.h"
#include "../../../utils/multi_array.h"
#include "../../../utils/simd.h"
#include "../../../utils/types.h"
#include "arch.h"

namespace nnue {

// clang-format off
struct RawNetwork {
  MultiArray<I16, arch::kInputBucketCount, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::kL1Size> feature_weights;
  MultiArray<I16, arch::kL1Size> feature_biases;
  MultiArray<I8, arch::kOutputBucketCount, arch::kL2Size, arch::kL1Size> l1_weights;
  MultiArray<float, arch::kOutputBucketCount, arch::kL2Size> l1_biases;
  MultiArray<float, arch::kOutputBucketCount, arch::kL3Size, arch::kL2Size> l2_weights;
  MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l2_biases;
  MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l3_weights;
  MultiArray<float, arch::kOutputBucketCount> l3_biases;
};

struct alignas(simd::kAlignment) Network {
  alignas(simd::kAlignment) MultiArray<I16, arch::kInputBucketCount, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::kL1Size> feature_weights;
  alignas(simd::kAlignment) MultiArray<I16, arch::kL1Size> feature_biases;
  union {
    alignas(simd::kAlignment) MultiArray<I8, arch::kOutputBucketCount, arch::kL1Size, arch::kL2Size> l1_weights;
    alignas(simd::kAlignment) MultiArray<I8, arch::kOutputBucketCount, arch::kL1Size * arch::kL2Size> l1_weights_alt;
  };
  alignas(simd::kAlignment) MultiArray<float, arch::kOutputBucketCount, arch::kL2Size> l1_biases;
  alignas(simd::kAlignment) MultiArray<float, arch::kOutputBucketCount, arch::kL2Size, arch::kL3Size> l2_weights;
  alignas(simd::kAlignment) MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l2_biases;
  alignas(simd::kAlignment) MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l3_weights;
  alignas(simd::kAlignment) MultiArray<float, arch::kOutputBucketCount> l3_biases;
};
// clang-format on

inline std::shared_ptr<RawNetwork> raw_network = nullptr;
inline std::shared_ptr<Network> network = nullptr;

class Accumulator;

void LoadFromIncBin();

Score Evaluate(Board &board);

}  // namespace nnue

#endif  // INTEGRAL_NNUE_H