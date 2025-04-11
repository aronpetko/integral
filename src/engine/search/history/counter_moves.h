#ifndef INTEGRAL_COUNTER_MOVES_H
#define INTEGRAL_COUNTER_MOVES_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class CounterMoves {
 public:
  CounterMoves() : table_({}) {}

  [[nodiscard]] Move GetCounterMove(StackEntry* prev_stack, Color turn) const {
    return prev_stack->move ? table_[FlipColor(turn)][prev_stack->moved_piece]
                                    [prev_stack->move.GetTo()]
                            : Move::NullMove();
  }

  void UpdateCounterMove(StackEntry* prev_stack, Color turn) {
    table_[FlipColor(turn)][prev_stack->moved_piece][prev_stack->move.GetTo()] =
        (prev_stack + 1)->move;
  }

 private:
  MultiArray<Move, kNumColors, kNumPieceTypes, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_COUNTER_MOVES_H