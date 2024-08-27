#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "../../../chess/board.h"
#include "arch.h"

namespace nnue {

class Accumulator {
 public:
  void MakeMove(const BoardState &state, Move move) {}

  void UndoMove() {}

 private:
  MultiArray<I32, 2, arch::kHiddenLayerSize> accumulator_;
};

}  // namespace nnue

#endif  // INTEGRAL_ACCUMULATOR_H