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
                   BitBoard threats,
                   MoveList &quiets) {
    const I16 bonus = HistoryBonus(depth);

    // Apply a linear dampening to the bonus as the depth increases
    UpdateMoveScore(state.turn, stack->move, threats, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    const I16 penalty = HistoryPenalty(depth);
    for (int i = 0; i < quiets.Size(); i++) {
      UpdateMoveScore(state.turn, quiets[i], threats, penalty);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state,
                             Move move,
                             BitBoard threats) const {
    return table_[state.turn][move.GetFrom()][move.GetTo()]
                 [threats.IsSet(move.GetFrom())][threats.IsSet(move.GetTo())];
  }

  void Age() {
    for (int c = 0; c < kNumColors; ++c) {
      for (int from = 0; from < kSquareCount; ++from) {
        for (int to = 0; to < kSquareCount; ++to) {
          for (int from_threat = 0; from_threat < 2; ++from_threat) {
            for (int to_threat = 0; to_threat < 2; ++to_threat) {
              I16 &score = table_[c][from][to][from_threat][to_threat];
              score = (score * 3) / 4;
            }
          }
        }
      }
    }
  }

 private:
  MultiArray<I16, kNumColors, kSquareCount, kSquareCount, 2, 2> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_QUIET_HISTORY_H