#ifndef INTEGRAL_QUIET_HISTORY_H
#define INTEGRAL_QUIET_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class QuietHistory {
 public:
  QuietHistory() : table_({}) {}

  void UpdateMoveScore(Color turn, Move move, BitBoard threats, int bonus) {
    // Apply a linear dampening to the bonus as the depth increases
    int &score =
        table_[turn][move.GetFrom()][move.GetTo()][ThreatIndex(move, threats)];
    score += ScaleBonus(score, bonus);
  }

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   int depth,
                   BitBoard threats,
                   List<std::pair<Move, int>, 64> &quiets,
                   int tried_count) {
    const int bonus = HistoryBonus(depth) * tried_count;

    // Apply a linear dampening to the bonus as the depth increases
    UpdateMoveScore(state.turn, stack->move, threats, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    for (int i = 0; i < quiets.Size(); i++) {
      const auto [bad_quiet, tried_count] = quiets[i];
      const int penalty = HistoryPenalty(depth) * tried_count;
      UpdateMoveScore(state.turn, bad_quiet, threats, penalty);
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