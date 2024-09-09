#ifndef INTEGRAL_NNUE_H
#define INTEGRAL_NNUE_H

#include "../../../chess/board.h"
#include "../../../third-party/incbin/incbin.h"
#include "../../../utils/multi_array.h"
#include "../../../utils/types.h"
#include "arch.h"

namespace nnue {

struct alignas(64) RawNetwork {
  MultiArray<I16, arch::kInputLayerSize, arch::kHiddenLayerSize>
      feature_weights;
  MultiArray<I16, arch::kHiddenLayerSize> feature_biases;
  MultiArray<I16, 2, arch::kHiddenLayerSize, arch::kOutputBucketCount>
      output_weights;
  MultiArray<I16, arch::kOutputBucketCount> output_biases;
};

struct TransposedNetwork {
  alignas(64) MultiArray<I16, arch::kInputLayerSize, arch::kHiddenLayerSize>
      feature_weights;
  alignas(64) MultiArray<I16, arch::kHiddenLayerSize> feature_biases;
  alignas(64) MultiArray<I16, arch::kOutputBucketCount, 2, arch::kHiddenLayerSize>
      output_weights;
  alignas(64) MultiArray<I16, arch::kOutputBucketCount> output_biases;
};

inline TransposedNetwork network;

class Accumulator;

void LoadFromIncBin();

Score Evaluate(std::shared_ptr<Accumulator> &accumulator);

}  // namespace nnue

#endif  // INTEGRAL_NNUE_H