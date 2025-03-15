#ifndef INTEGRAL_QUIET_HISTORY_H
#define INTEGRAL_QUIET_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class QuietHistory {
 public:
  QuietHistory() : table_({}) {}

  void UpdateMoveScore(
      Color turn, Move move, BitBoard threats, I16 bonus, int ply) {
    // Apply a linear dampening to the bonus as the depth increases
    I16 &score = table_[ply / 8][turn][move.GetFrom()][move.GetTo()]
                       [ThreatIndex(move, threats)];
    score += ScaleBonus(score, bonus);
  }

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   I16 depth,
                   BitBoard threats,
                   MoveList &quiets) {
    const I16 bonus = HistoryBonus(depth);

    // Apply a linear dampening to the bonus as the depth increases
    UpdateMoveScore(state.turn, stack->move, threats, bonus, stack->ply);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    const I16 penalty = HistoryPenalty(depth);
    for (int i = 0; i < quiets.Size(); i++) {
      UpdateMoveScore(state.turn, quiets[i], threats, penalty, stack->ply);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state,
                             Move move,
                             BitBoard threats,
                             int ply) const {
    return table_[ply / 8][state.turn][move.GetFrom()][move.GetTo()]
                 [ThreatIndex(move, threats)];
  }

 private:
  [[nodiscard]] int ThreatIndex(Move move, BitBoard threats) const {
    return 2 * threats.IsSet(move.GetFrom()) + threats.IsSet(move.GetTo());
  }

 private:
  MultiArray<I16, 32, kNumColors, kSquareCount, kSquareCount, 4> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_QUIET_HISTORY_H