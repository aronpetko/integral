#include "policy.h"

#include <cmath>

namespace nnue::policy {

PolicyEvaluator::PolicyEvaluator(const BoardState& state) : state_(state) {
  mirror_ = Square(state.King(state.turn).GetLsb()).File() >= File::kFileE;
  flip_ =
      (state.turn == Color::kBlack ? 0b111000 : 0) ^ (mirror_ ? 0b000111 : 0);

  PolicyAccumulator accumulator;
  accumulator.Refresh(state);

  // Pairwise CReLU
  const auto activated = simd::Clip(accumulator.Values(), static_cast<I16>(kQ));
  hidden_ = simd::Convert<I32>(simd::LowerHalf(activated)) *
            simd::Convert<I32>(simd::UpperHalf(activated));
}

void PolicyEvaluator::Logits(const MoveList& moves,
                             std::span<float> logits) const {
  for (int i = 0; i < moves.Size(); ++i) {
    logits[i] = Logit(moves[i]);
  }
}

void PolicyEvaluator::Probabilities(const MoveList& moves,
                                    std::span<float> probabilities) const {
  if (moves.Size() == 0) return;

  Logits(moves, probabilities);

  float max_logit = probabilities[0];
  for (int i = 1; i < moves.Size(); ++i) {
    max_logit = std::max(max_logit, probabilities[i]);
  }

  float total = 0.0f;
  for (int i = 0; i < moves.Size(); ++i) {
    probabilities[i] = std::exp(probabilities[i] - max_logit);
    total += probabilities[i];
  }

  const float inverse_total = 1.0f / total;
  for (int i = 0; i < moves.Size(); ++i) {
    probabilities[i] *= inverse_total;
  }
}

}  // namespace nnue::policy
