#ifndef INTEGRAL_CAPTURE_HISTORY_H
#define INTEGRAL_CAPTURE_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class CaptureHistory {
 public:
  CaptureHistory() : table_({}) {}

  void Clear() {
    table_.fill(I16{0});
  }

  void Update(const BoardState &state, Move move, I16 bonus) {
    const auto from = move.GetFrom(), to = move.GetTo();
    const auto captured =
        move.IsEnPassant(state) ? kPawn : state.GetPieceType(to);
    I16 &score = table_[state.turn][state.GetPieceType(from)][to][captured];
    score += ScaleBonus(score, bonus);
  }

  [[nodiscard]] I16 GetScore(const BoardState &state, Move move) const {
    const auto from = move.GetFrom(), to = move.GetTo();
    const auto captured =
        move.IsEnPassant(state) ? kPawn : state.GetPieceType(to);
    return table_[state.turn][state.GetPieceType(from)][to][captured];
  }

 private:
  MultiArray<I16, kNumColors, kNumPieceTypes, kSquareCount, kNumPieceTypes>
      table_;
};

}  // namespace search::history

#endif  // INTEGRAL_CAPTURE_HISTORY_H