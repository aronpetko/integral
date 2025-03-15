//
// Created by Aron Petkovski on 3/15/25.
//

#ifndef INTEGRAL_PLY_HISTORY_H
#define INTEGRAL_PLY_HISTORY_H
#include "../../../utils/types.h"

namespace search::history {

class PlyHistory {
  static constexpr int kPlyWindow = 8;

 public:
  PlyHistory() : table_({}) {}

  void UpdateMoveScore(Color turn, Move move, int ply, I16 bonus) {
    // Apply a linear dampening to the bonus as the depth increases
    I16 &score = table_[ply / kPlyWindow][turn][move.GetFrom()][move.GetTo()];
    score += ScaleBonus(score, bonus);
  }

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   I16 depth,
                   MoveList &quiets) {
    const I16 bonus = HistoryBonus(depth) + PlyHistoryBonus(stack->ply);

    // Apply a linear dampening to the bonus as the depth increases
    UpdateMoveScore(state.turn, stack->move, stack->ply, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    const I16 penalty = HistoryPenalty(depth);
    for (int i = 0; i < quiets.Size(); i++) {
      UpdateMoveScore(state.turn, quiets[i], stack->ply, penalty);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state,
                             Move move,
                             int ply) const {
    return table_[ply / kPlyWindow][state.turn][move.GetFrom()][move.GetTo()];
  }

 private:
  int PlyHistoryBonus(int ply) {
    ply %= kPlyWindow;

    const int kMinPly = 0;
    const int kMaxPly = kPlyWindow - 1;
    const int kMinBonus = 128;
    const int kMaxBonus = 256;

    // Midpoint where bonus is at its lowest
    const int mid_ply = (kMinPly + kMaxPly) / 2;

    if (ply <= mid_ply) {
      // Linearly decrease from kMaxBonus to kMinBonus
      return kMaxBonus -
             (kMaxBonus - kMinBonus) * (ply - kMinPly) / (mid_ply - kMinPly);
    } else {
      // Linearly increase from kMinBonus back to kMaxBonus
      return kMinBonus +
             (kMaxBonus - kMinBonus) * (ply - mid_ply) / (kMaxPly - mid_ply);
    }
  }

 private:
  MultiArray<I16,
             kMaxGamePly / kPlyWindow,
             kNumColors,
             kSquareCount,
             kSquareCount>
      table_;
};

}  // namespace search::history

#endif  // INTEGRAL_PLY_HISTORY_H
