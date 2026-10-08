#include "policy.h"

#include <algorithm>
#include <cmath>

namespace nnue::policy {

PolicyEvaluator::PolicyEvaluator(const BoardState& state) {
  mirror_ = Square(state.King(state.turn).GetLsb()).File() >= File::kFileE;
  flip_ =
      (state.turn == Color::kBlack ? 0b111000 : 0) ^ (mirror_ ? 0b000111 : 0);

  PolicyAccumulator accumulator;
  accumulator.Refresh(state);

  const auto activated = simd::Clip(accumulator.Values(), static_cast<I16>(kQ));
  hidden_ = simd::Convert<I32>(simd::LowerHalf(activated)) *
            simd::Convert<I32>(simd::UpperHalf(activated));
}

void PolicyEvaluator::Probabilities(const BoardState& state,
                                    const MoveList& moves,
                                    std::span<float> probabilities) const {
  if (moves.Size() == 0) return;

  for (int i = 0; i < moves.Size(); ++i) {
    probabilities[i] = Logit(state, moves[i]);
  }

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
