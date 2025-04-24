#ifndef INTEGRAL_NNUE_H
#define INTEGRAL_NNUE_H

#include "../../../../shared/multi_array.h"
#include "../../../../shared/nnue/definitions.h"
#include "../../../../shared/simd.h"
#include "../../../chess/board.h"
#include "../../../utils/types.h"

namespace nnue {

inline Network* network = nullptr;

class Accumulator;

void LoadFromIncBin();

Score Evaluate(Board& board);

}  // namespace nnue

#endif  // INTEGRAL_NNUE_H