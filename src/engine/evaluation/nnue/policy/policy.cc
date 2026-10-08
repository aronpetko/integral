#include "policy.h"

#include <algorithm>
#include <cmath>

namespace nnue::policy {

void PolicyEvaluator::Refresh(const BoardState& state) {
  key_ = state.zobrist_key;
  mirror_ = Square(state.King(state.turn).GetLsb()).File() >= File::kFileE;
  flip_ =
      (state.turn == Color::kBlack ? 0b111000 : 0) ^ (mirror_ ? 0b000111 : 0);

  PolicyAccumulator accumulator;
  accumulator.Refresh(state);

  // Pairwise CReLU
  const auto activated = simd::Clip(accumulator.Values(), static_cast<I16>(kQ));
  const auto hidden = simd::LowerHalf(activated) * simd::UpperHalf(activated);
  hidden_pair_ = simd::Concat(hidden, hidden);
}

void PolicyEvaluator::RawLogits(const BoardState& state,
                                std::span<const Move> moves,
                                std::span<I32> logits) const {
  constexpr int kBlockSize = 8;
  static_assert(kHiddenSize == 8, "the reduction assumes 8 hidden neurons");

  // Compute every output index up front so the rows can be prefetched while
  // the rest are being computed
  std::array<U16, kMaxMoves> indices;
  for (std::size_t i = 0; i < moves.size(); ++i) {
    const Move move = moves[i];
    indices[i] = features::GetMoveOutputIndex(
        move, state.GetPieceType(move.GetFrom()), flip_, mirror_);
    __builtin_prefetch(policy_network->l1_weights[indices[i]].data());
  }

  for (std::size_t start = 0; start < moves.size(); start += kBlockSize) {
    const int count = static_cast<int>(
        std::min<std::size_t>(kBlockSize, moves.size() - start));

    // Pad a partial block with its first move
    std::array<const I8*, kBlockSize> rows;
    for (int i = 0; i < kBlockSize; ++i) {
      rows[i] = policy_network->l1_weights[indices[start + (i < count ? i : 0)]]
                    .data();
    }

    // Each madd yields 4 partial sums for each of two moves
    std::array<simd::Vector<I32, kBlockSize>, kBlockSize / 2> sums;
    for (int i = 0; i < kBlockSize / 2; ++i) {
      const auto pair_weights = simd::Convert<I16>(
          simd::Concat(simd::Load<I8, kHiddenSize>(rows[2 * i]),
                       simd::Load<I8, kHiddenSize>(rows[2 * i + 1])));
      sums[i] = simd::MultiplyAddEpi16(pair_weights, hidden_pair_);
    }

    alignas(simd::kAlignment) std::array<I32, kBlockSize> out;
    simd::Store<I32, kBlockSize>(
        out.data(),
        simd::PairwiseAdd(simd::PairwiseAdd(sums[0], sums[1]),
                          simd::PairwiseAdd(sums[2], sums[3])));
    for (int i = 0; i < count; ++i) {
      logits[start + i] =
          out[i] + policy_network->l1_biases[indices[start + i]] * kBiasScale;
    }
  }
}

void PolicyEvaluator::Logits(const BoardState& state,
                             const MoveList& moves,
                             std::span<float> logits) const {
  std::array<Move, kMaxMoves> move_array;
  std::array<I32, kMaxMoves> raw;
  for (int i = 0; i < moves.Size(); ++i) move_array[i] = moves[i];
  RawLogits(state,
            std::span(move_array.data(), moves.Size()),
            std::span(raw.data(), moves.Size()));
  for (int i = 0; i < moves.Size(); ++i) {
    logits[i] = static_cast<float>(raw[i]) * kLogitScale;
  }
}

void PolicyEvaluator::Probabilities(const BoardState& state,
                                    const MoveList& moves,
                                    std::span<float> probabilities) const {
  if (moves.Size() == 0) return;

  Logits(state, moves, probabilities);

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
