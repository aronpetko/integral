#ifndef INTEGRAL_POLICY_H
#define INTEGRAL_POLICY_H

#include <span>

#include "policy_accumulator.h"
#include "policy_features.h"

namespace nnue::policy {

class PolicyEvaluator {
 public:
  PolicyEvaluator() = default;

  explicit PolicyEvaluator(const BoardState& state) {
    Update(state);
  }

  // Only refreshes when the position changed since the last update
  void Update(const BoardState& state) {
    if (state.zobrist_key != key_) Refresh(state);
  }

  // Logits scaled by Q^3
  void RawLogits(const BoardState& state,
                 std::span<const Move> moves,
                 std::span<I32> logits) const;

  void Logits(const BoardState& state,
              const MoveList& moves,
              std::span<float> logits) const;

  void Probabilities(const BoardState& state,
                     const MoveList& moves,
                     std::span<float> probabilities) const;

 private:
  static constexpr int kHiddenSize = arch::policy::kL1Size / 2;
  static constexpr I32 kQ = arch::policy::kQuantisation;
  static constexpr I32 kBiasScale = kQ * kQ;
  static constexpr float kLogitScale = 1.0f / static_cast<float>(kQ * kQ * kQ);

  void Refresh(const BoardState& state);

  U64 key_ = 0;
  int flip_ = 0;
  bool mirror_ = false;
  // Hidden layer repeated twice, so one madd covers two moves
  simd::Vector<I16, kHiddenSize * 2> hidden_pair_;
};

}  // namespace nnue::policy

#endif  // INTEGRAL_POLICY_H
