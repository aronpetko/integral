#ifndef INTEGRAL_NNUE_H
#define INTEGRAL_NNUE_H

#include "../../../chess/board.h"
#include "../../../third-party/incbin/incbin.h"
#include "../../../utils/multi_array.h"
#include "../../../utils/types.h"
#include "arch.h"

namespace nnue {

class Accumulator;

struct Network {
  MultiArray<I16, arch::kInputLayerSize, arch::kHiddenLayerSize>
      feature_weights;
  MultiArray<I16, arch::kHiddenLayerSize> feature_biases;
  MultiArray<I16, 2, arch::kHiddenLayerSize> output_weights;
  I16 output_bias;
};

void LoadFromFile(std::string_view path);

void LoadFromIncBin();

Score Evaluate(std::shared_ptr<Accumulator> &accumulator);

inline Network network;

}  // namespace nnue

#endif  // INTEGRAL_NNUE_H