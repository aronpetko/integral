#ifndef INTEGRAL_QUIET_HISTORY_H
#define INTEGRAL_QUIET_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class QuietHistory {
 public:
  QuietHistory() : table_({}) {}

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   int bonus_depth,
                   int penalty_depth,
                   BitBoard threats,
                   MoveList &quiets) {
    const Color turn = state.turn;
    const Move move = stack->move;

    const int bonus = HistoryBonus(bonus_depth);

    // Apply a linear dampening to the bonus as the depth increases
    int &score =
        table_[turn][move.GetFrom()][move.GetTo()][ThreatIndex(move, threats)];
    score += ScaleBonus(score, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    const int penalty = -HistoryBonus(penalty_depth);
    for (int i = 0; i < quiets.Size(); i++) {
      const Move bad_quiet = quiets[i];
      // Apply a linear dampening to the penalty as the depth increases
      int &bad_quiet_score =
          table_[turn][bad_quiet.GetFrom()][bad_quiet.GetTo()]
                [ThreatIndex(bad_quiet, threats)];
      bad_quiet_score += ScaleBonus(bad_quiet_score, penalty);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state,
                             Move move,
                             BitBoard threats) const {
    return table_[state.turn][move.GetFrom()][move.GetTo()]
                 [ThreatIndex(move, threats)];
  }

 private:
  [[nodiscard]] int ThreatIndex(Move move, BitBoard threats) const {
    return 2 * threats.IsSet(move.GetFrom()) + threats.IsSet(move.GetTo());
  }

 private:
  MultiArray<int, kNumColors, kSquareCount, kSquareCount, 4> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_QUIET_HISTORY_H