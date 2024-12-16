#ifndef INTEGRAL_NNUE_H
#define INTEGRAL_NNUE_H

#include "../../../chess/board.h"
#include "../../../utils/multi_array.h"
#include "../../../utils/types.h"
#include "arch.h"

namespace nnue {

// clang-format off
struct alignas(64) RawNetwork {
  MultiArray<I16, arch::kInputBucketCount, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::kL1Size> feature_weights;
  MultiArray<I16, arch::kL1Size> feature_biases;
  MultiArray<I8, arch::kOutputBucketCount, arch::kL1Size, arch::kL2Size> l1_weights;
  MultiArray<float, arch::kOutputBucketCount, arch::kL2Size> l1_biases;
  MultiArray<float, arch::kOutputBucketCount, arch::kL2Size, arch::kL3Size> l2_weights;
  MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l2_biases;
  MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l3_weights;
  MultiArray<float, arch::kOutputBucketCount> l3_biases;
};

struct AlignedNetwork {
  alignas(64) MultiArray<I16, arch::kInputBucketCount, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::kL1Size> feature_weights;
  alignas(64) MultiArray<I16, arch::kL1Size> feature_biases;
  alignas(64) MultiArray<I8, arch::kOutputBucketCount, arch::kL1Size, arch::kL2Size> l1_weights;
  alignas(64) MultiArray<float, arch::kOutputBucketCount, arch::kL2Size> l1_biases;
  alignas(64) MultiArray<float, arch::kOutputBucketCount, arch::kL2Size, arch::kL3Size> l2_weights;
  alignas(64) MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l2_biases;
  alignas(64) MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l3_weights;
  alignas(64) MultiArray<float, arch::kOutputBucketCount> l3_biases;
};
// clang-format on

inline std::unique_ptr<AlignedNetwork> network = nullptr;

class Accumulator;

void LoadFromIncBin();

Score Evaluate(Board &board);

}  // namespace nnue

#endif  // INTEGRAL_NNUE_H