#ifndef INTEGRAL_NNUE_H
#define INTEGRAL_NNUE_H

#include <optional>

#include "../../../chess/board.h"
#include "../../../utils/types.h"

namespace nnue {

void LoadFromIncBin();

// Each NUMA node reads its own copy of the network. Accumulators pick up the
// calling thread's network the next time they're set from a board state
void UseNetworkForNode(std::optional<std::size_t> node);

Score Evaluate(Board& board);

}  // namespace nnue

#endif  // INTEGRAL_NNUE_H
