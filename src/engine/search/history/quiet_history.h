#ifndef INTEGRAL_QUIET_HISTORY_H
#define INTEGRAL_QUIET_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class QuietHistory {
 public:
  QuietHistory() : table_({}) {}

  void UpdateMoveScore(Color turn, Move move, BitBoard threats, I16 bonus) {
    // Apply a linear dampening to the bonus as the depth increases
    I16 &score =
        table_[turn][move.GetFrom()][move.GetTo()]
              [threats.IsSet(move.GetFrom())][threats.IsSet(move.GetTo())];
    score += ScaleBonus(score, bonus);
  }

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   I16 depth,
                   MoveList &quiets,
                   I32 moves_seen) {
    const I16 bonus = HistoryBonus(depth);

    // Apply a linear dampening to the bonus as the depth increases
    UpdateMoveScore(state.turn, stack->move, stack->threats, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    const I16 penalty = HistoryPenalty(depth) - 16 * (moves_seen - 1);
    for (int i = 0; i < quiets.Size(); i++) {
      UpdateMoveScore(state.turn, quiets[i], stack->threats, penalty);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state,
                             Move move,
                             BitBoard threats) const {
    return table_[state.turn][move.GetFrom()][move.GetTo()]
                 [threats.IsSet(move.GetFrom())][threats.IsSet(move.GetTo())];
  }

 private:
  [[nodiscard]] int ThreatIndex(Move move, BitBoard threats) const {
    return 2 * threats.IsSet(move.GetFrom()) + threats.IsSet(move.GetTo());
  }

 private:
  MultiArray<I16, kNumColors, kSquareCount, kSquareCount, 2, 2> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_QUIET_HISTORY_H