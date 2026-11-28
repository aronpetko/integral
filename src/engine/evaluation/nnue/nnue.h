#ifndef INTEGRAL_NNUE_H
#define INTEGRAL_NNUE_H

#include <optional>

#include "../../../../shared/multi_array.h"
#include "../../../../shared/nnue/definitions.h"
#include "../../../../shared/simd.h"
#include "../../../chess/board.h"
#include "../../../utils/types.h"

namespace nnue {

// Per thread so each NUMA node can read its own copy of the network
inline thread_local Network* network = nullptr;

class Accumulator;

void LoadFromIncBin();

void UseNetworkForNode(std::optional<std::size_t> node);

Score Evaluate(Board& board);

}  // namespace nnue

#endif  // INTEGRAL_NNUE_H