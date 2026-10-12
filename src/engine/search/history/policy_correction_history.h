#ifndef INTEGRAL_POLICY_CORRECTION_HISTORY_H
#define INTEGRAL_POLICY_CORRECTION_HISTORY_H

#include <algorithm>

#include "../../../../shared/multi_array.h"
#include "../../../chess/board.h"

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
                   int bonus) {
    I16 &score =
        table_[state.turn][move.GetFrom()][move.GetTo()]
              [threats.IsSet(move.GetFrom())][threats.IsSet(move.GetTo())];
    score = std::clamp(score + bonus, -2048, 2048);
  }

 private:
  MultiArray<I16, kNumColors, kSquareCount, kSquareCount, 2, 2> table_;
};

}

#endif
