#ifndef INTEGRAL_POLICY_CORRECTION_HISTORY_H
#define INTEGRAL_POLICY_CORRECTION_HISTORY_H

#include <span>

#include "../../../../shared/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

TUNABLE_STEP(kPolicyCorrDepthScale, 48, 8, 128, false, 8);
TUNABLE_STEP(kPolicyCorrMaxBonus, 256, 64, 1024, false, 32);
TUNABLE_STEP(kPolicyCorrGravity, 4096, 1024, 16384, false, 512);

constexpr int kPolicyOne = 1 << 14;
constexpr I16 kNoPolicy = -1;

class PolicyCorrectionHistory {
 public:
  PolicyCorrectionHistory() {
    Clear();
  }

  void Clear() {
    table_.fill(I16{0});
  }

  void UpdateScore(const BoardState &state,
                   I16 depth,
                   Move best_move,
                   I16 best_policy,
                   MoveList &quiets,
                   std::span<const I16> quiet_policies) {
    const int step = std::min<int>(kPolicyCorrDepthScale * depth,
                                   kPolicyCorrMaxBonus);

    if (best_policy != kNoPolicy) {
      UpdateMoveScore(
          state, best_move, step * (kPolicyOne - best_policy) / kPolicyOne);
    }

    for (int i = 0; i < quiets.Size(); i++) {
      if (quiet_policies[i] != kNoPolicy) {
        UpdateMoveScore(
            state, quiets[i], -step * quiet_policies[i] / kPolicyOne);
      }
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state, Move move) const {
    return table_[GetIndex(state)][state.turn]
                 [state.GetPieceType(move.GetFrom())][move.GetTo()];
  }

 private:
  void UpdateMoveScore(const BoardState &state, Move move, int bonus) {
    I16 &score = table_[GetIndex(state)][state.turn]
                       [state.GetPieceType(move.GetFrom())][move.GetTo()];
    score += ScaleBonus(score, static_cast<I16>(bonus), kPolicyCorrGravity);
  }

  [[nodiscard]] int GetIndex(const BoardState &state) const {
    return state.pawn_key & 2047;
  }

 private:
  MultiArray<I16, 2048, kNumColors, kNumPieceTypes, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_POLICY_CORRECTION_HISTORY_H
