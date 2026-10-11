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

  // Products rescaled to [0, Q] fit in a U8 and keep u8 x i8 pair sums in I16
  static_assert(kQ == 128);
  const auto activated = simd::Clip(accumulator.Values(), static_cast<I16>(kQ));
  const auto product =
      (simd::LowerHalf(activated) * simd::UpperHalf(activated) + kQ / 2) / kQ;
  simd::Store<U8, kHiddenSize>(
      hidden_.data(),
      __builtin_convertvector(product, simd::Vector<U8, kHiddenSize>));
}

void PolicyEvaluator::RawLogits(std::span<const U16> rows, I32* logits) const {
  constexpr int kBatch = simd::kNativeLanes<I32>;
  const int count = static_cast<int>(rows.size());

  for (int base = 0; base < count; base += kBatch) {
    const int batch_size = std::min(kBatch, count - base);

    std::array<simd::Vepi32, kBatch> sums;
    for (int i = 0; i < kBatch; ++i) {
      // Pad a partial batch by repeating its last row
      const int row = rows[base + std::min(i, batch_size - 1)];
      sums[i] = Dot(policy_network->l1_weights[row].data());
    }

    alignas(simd::kAlignment) std::array<I32, kBatch> dots;
    simd::Store<I32>(dots.data(), simd::ReduceAddBatch(sums));

    for (int i = 0; i < batch_size; ++i) {
      logits[base + i] =
          dots[i] * kQ + policy_network->l1_biases[rows[base + i]] * kBiasScale;
    }
  }
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
