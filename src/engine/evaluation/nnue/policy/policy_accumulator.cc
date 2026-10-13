#include "policy_accumulator.h"

namespace nnue::policy {

void PolicyAccumulator::Refresh(const BoardState& state) {
  const Color us = state.turn;
  const int flip =
      (us == Color::kBlack ? 0b111000 : 0) ^
      (Square(state.King(us).GetLsb()).File() >= File::kFileE ? 0b000111 : 0);

  auto values = simd::Convert<I16>(
      simd::Load<I8, kWidth>(policy_network->feature_biases.data()));
  for (const Square square : state.Occupied()) {
    const auto& row =
        policy_network->feature_weights[state.GetPieceColor(square) != us]
                                       [state.piece_on_square[square]]
                                       [square ^ flip];
    values += simd::Convert<I16>(simd::Load<I8, kWidth>(row.data()));
  }
  values_ = values;
}

}  // namespace nnue::policy
