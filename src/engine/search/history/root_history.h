#ifndef INTEGRAL_ROOT_HISTORY_H
#define INTEGRAL_ROOT_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class RootHistory {
 public:
  RootHistory() : table_({}) {}

  void UpdateScore(Color turn, Move move, int depth) {
    // Apply a linear dampening to the bonus as the depth increases
    int &score = table_[turn][move.GetFrom()][move.GetTo()];
    score += ScaleBonus(score, HistoryBonus(depth));
  }

  void Penalize(const BoardState &state, int depth, MoveList &moves) {
    const int penalty = -HistoryBonus(depth);
    // Lower the score of the capture moves that failed to raise alpha
    for (int i = 0; i < moves.Size(); i++) {
      const Move bad_move = moves[i];
      // Apply a linear dampening to the penalty as the depth increases
      int &bad_move_score =
          table_[state.turn][bad_move.GetFrom()][bad_move.GetTo()];
      bad_move_score += ScaleBonus(bad_move_score, penalty);
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