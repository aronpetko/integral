#ifndef INTEGRAL_QUIET_HISTORY_H
#define INTEGRAL_QUIET_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class QuietHistory {
 public:
  QuietHistory() : factorizer_table_({}), threat_table_({}) {}

  void UpdateMoveScore(Color turn, Move move, BitBoard threats, I16 bonus) {
    const auto from = move.GetFrom(), to = move.GetTo();
    // Apply a linear dampening to the bonus as the depth increases
    I16 &factorizer_score = factorizer_table_[turn][from][to];
    factorizer_score += ScaleBonus(factorizer_score, bonus);
    I16 &threat_score = threat_table_[threats.IsSet(from)][threats.IsSet(to)];
    threat_score += ScaleBonus(threat_score, bonus);
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
    const auto from = move.GetFrom(), to = move.GetTo();
    return factorizer_table_[state.turn][from][to] +
           threat_table_[state.threats.IsSet(from)][state.threats.IsSet(to)];
  }

 private:
  MultiArray<I16, kNumColors, kSquareCount, kSquareCount> factorizer_table_;
  MultiArray<I16, 2, 2> threat_table_;
};

}  // namespace search::history

#endif  // INTEGRAL_QUIET_HISTORY_H