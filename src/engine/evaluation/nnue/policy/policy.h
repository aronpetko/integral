#ifndef INTEGRAL_POLICY_H
#define INTEGRAL_POLICY_H

#include <span>

#include "policy_accumulator.h"
#include "policy_features.h"

namespace nnue::policy {

class PolicyEvaluator {
 public:
  explicit PolicyEvaluator(const BoardState& state);

  // Logit scaled by Q^3
  [[nodiscard]] I32 RawLogit(const BoardState& state, Move move) const {
    const auto row = OutputRow(state, move);
    return simd::ReduceAdd(Dot(policy_network->l1_weights[row].data())) * kQ +
           policy_network->l1_biases[row] * kBiasScale;
  }

  // Output row of a move for RawLogits, prefetching its weights
  [[nodiscard]] U16 PrefetchOutput(const BoardState& state, Move move) const {
    const auto row = OutputRow(state, move);
    __builtin_prefetch(policy_network->l1_weights[row].data());
    return static_cast<U16>(row);
  }

  // Logits scaled by Q^3 for each output row from PrefetchOutput
  void RawLogits(std::span<const U16> rows, I32* logits) const;

  [[nodiscard]] float Logit(const BoardState& state, Move move) const {
    return static_cast<float>(RawLogit(state, move)) * kLogitScale;
  }

  void Probabilities(const BoardState& state,
                     const MoveList& moves,
                     std::span<float> probabilities) const;

 private:
  static constexpr int kHiddenSize = arch::policy::kL1Size / 2;
  static constexpr int kChunks = kHiddenSize / simd::kNativeLanes<U8>;
  static constexpr I32 kQ = arch::policy::kQuantisation;
  static constexpr I32 kBiasScale = kQ * kQ;
  static constexpr float kLogitScale = 1.0f / static_cast<float>(kQ * kQ * kQ);

  static_assert(kHiddenSize % simd::kNativeLanes<U8> == 0);

  [[nodiscard]] std::size_t OutputRow(const BoardState& state,
                                      Move move) const {
    return features::GetMoveOutputIndex(
        move, state.GetPieceType(move.GetFrom()), flip_, mirror_);
  }

  // Unreduced dot product of the hidden layer with an output row
  [[nodiscard]] simd::Vepi32 Dot(const I8* row) const {
    auto sum = simd::Zero<I32>();
    for (int i = 0; i < kChunks; ++i) {
      sum = simd::DpbusdEpi32(
          sum,
          simd::Load<U8>(hidden_.data() + i * simd::kNativeLanes<U8>),
          simd::Load<I8>(row + i * simd::kNativeLanes<I8>));
    }
    return sum;
  }

  // Pairwise products rescaled from Q^2 to Q
  alignas(simd::kAlignment) std::array<U8, kHiddenSize> hidden_;
  int flip_;
  bool mirror_;
};

}  // namespace nnue::policy

#endif  // INTEGRAL_POLICY_H
