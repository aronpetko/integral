#ifndef INTEGRAL_PAWN_HISTORY_H
#define INTEGRAL_PAWN_HISTORY_H

#include "../../../tuner/spsa.h"
#include "../../../utils/multi_array.h"
#include "../stack.h"

namespace history {

constexpr int kPawnHistorySize = 16834;

inline Tunable pawn_history_gravity(
    "pawn_history_gravity", 16834, 8192, 32768, 1024);
inline Tunable pawn_history_scale("pawn_history_scale", 135, 65, 260, 5);
inline Tunable pawn_history_max_bonus(
    "pawn_history_max_bonus", 1188, 580, 2318, 50);

// Same idea as quiet history, only indexed by the position's pawn key
class PawnHistory {
 public:
  explicit PawnHistory(const BoardState &state) : state_(state), table_({}) {}

  void UpdateScore(SearchStackEntry *stack, int depth, MoveList &quiets) {
    const Move move = stack->move;

    const int bonus =
        HistoryBonus(depth, pawn_history_scale, pawn_history_max_bonus);

    // Apply a linear dampening to the bonus as the depth increases
    int &score = table_[GetTableIndex()][state_.turn]
                       [state_.GetPieceType(move.GetFrom())][move.GetTo()];
    score += ScaleBonus(score, bonus, pawn_history_gravity);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    for (int i = 0; i < quiets.Size(); i++) {
      const Move bad_quiet = quiets[i];
      // Apply a linear dampening to the penalty as the depth increases
      int &bad_quiet_score =
          table_[GetTableIndex()][state_.turn]
                [state_.GetPieceType(bad_quiet.GetFrom())][bad_quiet.GetTo()];
      bad_quiet_score +=
          ScaleBonus(bad_quiet_score, -bonus, pawn_history_gravity);
    }
  }

  [[nodiscard]] int GetScore(Move move, PieceType piece) const {
    return table_[GetTableIndex()][state_.turn][piece][move.GetTo()];
  }

 private:
  [[nodiscard]] int GetTableIndex() const {
    return state_.pawn_key & (static_cast<int>(kPawnHistorySize) - 1);
  }

  [[nodiscard]] int ThreatIndex(Move move, BitBoard threats) const {
    return 2 * threats.IsSet(move.GetFrom()) + threats.IsSet(move.GetTo());
  }

 private:
  const BoardState &state_;
  MultiArray<int, kPawnHistorySize, kNumColors, kNumPieceTypes, 64> table_;
};

}  // namespace history

#endif  // INTEGRAL_PAWN_HISTORY_H