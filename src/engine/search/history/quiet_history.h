#ifndef INTEGRAL_QUIET_HISTORY_H
#define INTEGRAL_QUIET_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class QuietHistory {
 public:
  QuietHistory() : table_({}) {}

  void Clear() {
    table_.fill(I16{0});
  }

  void Update(Color turn, Move move, BitBoard threats, I16 bonus) {
    I16 &score =
        table_[turn][move.GetFrom()][move.GetTo()]
              [threats.IsSet(move.GetFrom())][threats.IsSet(move.GetTo())];
    score += ScaleBonus(score, bonus);
  }

  [[nodiscard]] int GetScore(const BoardState &state,
                             Move move,
                             BitBoard threats) const {
    return table_[state.turn][move.GetFrom()][move.GetTo()]
                 [threats.IsSet(move.GetFrom())][threats.IsSet(move.GetTo())];
  }

 private:
  [[nodiscard]] int ThreatIndex(Move move, BitBoard threats) const {
    return 2 * threats.IsSet(move.GetFrom()) + threats.IsSet(move.GetTo());
  }

 private:
  MultiArray<I16, kNumColors, kSquareCount, kSquareCount, 2, 2> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_QUIET_HISTORY_H