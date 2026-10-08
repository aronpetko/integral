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

  // Updates incrementally from whichever of this evaluator's last position or
  // `source` is closer, refreshing when neither is cheaper
  void Update(const BoardState& state,
              const PolicyEvaluator* source = nullptr);

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
  static constexpr int kChunkSize = 16;
  static constexpr int kChunksPerMove = kHiddenSize / kChunkSize;
  static_assert(kHiddenSize % kChunkSize == 0);

  static constexpr I32 kQ = arch::policy::kQuantisation;
  static constexpr I32 kBiasScale = kQ * kQ;
  static constexpr float kLogitScale = 1.0f / static_cast<float>(kQ * kQ * kQ);

  PolicyAccumulator accumulator_;
  int flip_ = 0;
  bool mirror_ = false;
  std::array<simd::Vector<I16, kChunkSize>, kChunksPerMove> hidden_;
};

}  // namespace nnue::policy

#endif  // INTEGRAL_POLICY_H
