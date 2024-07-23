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

  void UpdateScore(SearchStackEntry *stack,
                   int depth,
                   BitBoard threats,
                   MoveList &quiets) {
    const Color turn = state_.turn;
    const Move move = stack->move;

    const int bonus = HistoryBonus(depth);

    // Apply a linear dampening to the bonus as the depth increases
    int &score =
        table_[GetTableIndex()][turn][move.GetFrom()]
              [state_.GetPieceType(move.GetTo())][ThreatIndex(move, threats)];
    score += ScaleBonus(score, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    for (int i = 0; i < quiets.Size(); i++) {
      const Move bad_quiet = quiets[i];
      // Apply a linear dampening to the penalty as the depth increases
      int &bad_quiet_score = table_[GetTableIndex()][turn][bad_quiet.GetFrom()]
                                   [state_.GetPieceType(bad_quiet.GetTo())]
                                   [ThreatIndex(bad_quiet, threats)];
      bad_quiet_score += ScaleBonus(bad_quiet_score, -bonus);
    }
  }

  [[nodiscard]] int GetScore(Move move, BitBoard threats) const {
    return table_[GetTableIndex()][state_.turn][move.GetFrom()]
                 [state_.GetPieceType(move.GetTo())]
                 [ThreatIndex(move, threats)];
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
  MultiArray<Score, kPawnHistorySize, kNumColors, 64, kNumPieceTypes + 1, 4> table_;
};

}  // namespace history

#endif  // INTEGRAL_PAWN_HISTORY_H