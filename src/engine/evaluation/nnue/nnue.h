#ifndef INTEGRAL_NNUE_H
#define INTEGRAL_NNUE_H

#include "../../../chess/board.h"
#include "../../../third-party/incbin/incbin.h"
#include "../../../utils/multi_array.h"
#include "../../../utils/types.h"
#include "arch.h"

namespace nnue {

struct alignas(64) Network {
  alignas(64) MultiArray<I16,
                         arch::kInputBucketCount,
                         2,
                         PieceType::kNumPieceTypes,
                         Squares::kSquareCount,
                         arch::kHiddenLayerSize> feature_weights;
  alignas(64) MultiArray<I16, arch::kHiddenLayerSize> feature_biases;
  alignas(64) MultiArray<I16,
                         arch::kOutputBucketCount,
                         2,
                         arch::kHiddenLayerSize> output_weights;
  alignas(64) MultiArray<I16, arch::kOutputBucketCount> output_biases;
};

inline std::unique_ptr<Network> network;

class Accumulator;

void LoadFromIncBin();

Score Evaluate(Board &board);

}  // namespace nnue

#endif  // INTEGRAL_NNUE_H