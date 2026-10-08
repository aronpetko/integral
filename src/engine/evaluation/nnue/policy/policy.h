#ifndef INTEGRAL_POLICY_H
#define INTEGRAL_POLICY_H

#include <span>

#include "policy_accumulator.h"
#include "policy_features.h"

namespace nnue::policy {

class PolicyEvaluator {
 public:
  explicit PolicyEvaluator(const BoardState& state);

  [[nodiscard]] I32 RawLogit(Move move) const {
    const auto idx = features::GetMoveOutputIndex(
        move, state_.GetPieceType(move.GetFrom()), flip_, mirror_);
    const auto weights =
        simd::Convert<I32>(simd::Load<I8, arch::policy::kL1Size / 2>(
            policy_network->l1_weights[idx].data()));
    return simd::ReduceAdd(hidden_ * weights) +
           policy_network->l1_biases[idx] * kBiasScale;
  }

  [[nodiscard]] float Logit(Move move) const {
    return static_cast<float>(RawLogit(move)) * kLogitScale;
  }

  void Logits(const MoveList& moves, std::span<float> logits) const;

  void Probabilities(const MoveList& moves,
                     std::span<float> probabilities) const;

 private:
  static constexpr I32 kQ = arch::policy::kQuantisation;
  static constexpr I32 kBiasScale = kQ * kQ;
  static constexpr float kLogitScale = 1.0f / static_cast<float>(kQ * kQ * kQ);

  const BoardState& state_;
  int flip_;
  bool mirror_;
  simd::Vector<I32, arch::policy::kL1Size / 2> hidden_;
};

}  // namespace nnue::policy

#endif  // INTEGRAL_POLICY_H
