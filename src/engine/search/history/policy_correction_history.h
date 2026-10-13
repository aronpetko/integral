#ifndef INTEGRAL_POLICY_CORRECTION_HISTORY_H
#define INTEGRAL_POLICY_CORRECTION_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../../../chess/board.h"
#include "bonus.h"

namespace search::history {

class PolicyCorrectionHistory {
 public:
  PolicyCorrectionHistory() : table_({}) {}

  void Clear() {
    table_.fill(I16{0});
  }

  int GetScore(const BoardState &state, Move move, BitBoard threats) const {
    return table_[state.turn][move.GetFrom()][move.GetTo()]
                 [threats.IsSet(move.GetFrom())][threats.IsSet(move.GetTo())];
  }

  void UpdateScore(const BoardState &state,
                   Move move,
                   BitBoard threats,
                   int policy_score,
                   int bonus) {
    I16 &score =
        table_[state.turn][move.GetFrom()][move.GetTo()]
              [threats.IsSet(move.GetFrom())][threats.IsSet(move.GetTo())];
    const int limit = std::min<int>(kHistBonusGravity, 32767);
    const int prediction = std::clamp(policy_score + score, -limit, limit);
    score = std::clamp(
        score + bonus - prediction * std::abs(bonus) / kHistBonusGravity,
        -limit,
        limit);
  }

 private:
  MultiArray<I16, kNumColors, kSquareCount, kSquareCount, 2, 2> table_;
};

}

#endif
