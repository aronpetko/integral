#include "policy_accumulator.h"

namespace nnue::policy {

void PolicyAccumulator::Refresh(const BoardState& state, Color perspective) {
  const auto king_square = Square(state.King(perspective).GetLsb());

  auto values = simd::Convert<I16>(
      simd::Load<I8, kWidth>(policy_network->feature_biases.data()));
  for (const Square square : state.Occupied()) {
    values += Row(
        {square, state.GetPieceType(square), state.GetPieceColor(square)},
        perspective,
        king_square);
  }
  values_ = values;
}

void PolicyAccumulator::ApplyChange(const PolicyAccumulator& previous,
                                    const PsqtAccumulatorChange& change,
                                    Color perspective,
                                    Square king_square) {
  auto values = previous.values_;
  values += Row(change.add_0, perspective, king_square);
  values -= Row(change.sub_0, perspective, king_square);
  if (change.type != PsqtAccumulatorChange::kNormal) {
    values -= Row(change.sub_1, perspective, king_square);
  }
  if (change.type == PsqtAccumulatorChange::kCastle) {
    values += Row(change.add_1, perspective, king_square);
  }
  values_ = values;
}

PolicyAccumulator::Vector PolicyAccumulator::Row(const FeatureData& feature,
                                                 Color perspective,
                                                 Square king_square) {
  const int flip = (perspective == Color::kBlack ? 0b111000 : 0) ^
                   (king_square.File() >= File::kFileE ? 0b000111 : 0);
  const auto& row =
      policy_network->feature_weights[feature.color != perspective]
                                     [feature.piece][feature.square ^ flip];
  return simd::Convert<I16>(simd::Load<I8, kWidth>(row.data()));
}

}  // namespace nnue::policy
