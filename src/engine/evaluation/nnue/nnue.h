#ifndef INTEGRAL_NNUE_H
#define INTEGRAL_NNUE_H

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

// Points the calling thread at a copy of the network on the given NUMA node,
// or at the embedded network if the node is negative
void UseNetworkForNode(int node);

Score Evaluate(Board& board);

}  // namespace nnue

#endif  // INTEGRAL_NNUE_H