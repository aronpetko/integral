#ifndef INTEGRAL_ROOT_HISTORY_H
#define INTEGRAL_ROOT_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class RootHistory {
 public:
  RootHistory() : table_({}) {}

  void UpdateScore(Color turn, Move move, int depth, MoveList &quiets) {
    const int bonus = HistoryBonus(depth);
    // Apply a linear dampening to the bonus as the depth increases
    int &score = table_[turn][move.GetFrom()][move.GetTo()];
    score += ScaleBonus(score, depth);

    // Lower the score of the capture moves that failed to raise alpha
    for (int i = 0; i < quiets.Size(); i++) {
      const Move bad_quiet = quiets[i];
      // Apply a linear dampening to the penalty as the depth increases
      int &bad_quiet_score =
          table_[turn][bad_quiet.GetFrom()][bad_quiet.GetTo()];
      bad_quiet_score += ScaleBonus(bad_quiet_score, -depth);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state, Move move) const {
    return table_[state.turn][move.GetFrom()][move.GetTo()];
  }

 private:
  MultiArray<int, kNumColors, kSquareCount, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_ROOT_HISTORY_H