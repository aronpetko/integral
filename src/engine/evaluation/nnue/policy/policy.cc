#include "policy.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace nnue::policy {

void PolicyEvaluator::Update(const BoardState& state,
                             const PolicyEvaluator* source) {
  if (accumulator_.IsAt(state)) return;

  // A refresh adds one row per piece
  int best_cost = state.Occupied().PopCount();
  const PolicyAccumulator* best = nullptr;
  const PolicyAccumulator* candidates[] = {
      &accumulator_, source ? &source->accumulator_ : nullptr};
  for (const auto* candidate : candidates) {
    if (!candidate) continue;
    const int cost = candidate->UpdateCost(state);
    if (cost >= 0 && cost < best_cost) {
      best_cost = cost;
      best = candidate;
    }
  }

  if (!best) {
    accumulator_.Refresh(state);
  } else {
    if (best != &accumulator_) accumulator_ = *best;
    accumulator_.Update(state);
  }

  mirror_ = Square(state.King(state.turn).GetLsb()).File() >= File::kFileE;
  flip_ =
      (state.turn == Color::kBlack ? 0b111000 : 0) ^ (mirror_ ? 0b000111 : 0);

  // Pairwise CReLU
  const auto activated =
      simd::Clip(accumulator_.Values(), static_cast<I16>(kQ));
  const auto hidden = simd::LowerHalf(activated) * simd::UpperHalf(activated);
  std::memcpy(hidden_.data(), &hidden, sizeof(hidden_));
}

void PolicyEvaluator::RawLogits(const BoardState& state,
                                std::span<const Move> moves,
                                std::span<I32> logits) const {
  constexpr int kBlockSize = 8;
  constexpr int kChunks = kBlockSize * kChunksPerMove;

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

    // Each madd yields partial sums for one chunk of a move; padding a partial
    // block with its first move keeps the reduction branchless
    std::array<simd::Vector<I32, kBlockSize>, kChunks> sums;
    for (int i = 0; i < kBlockSize; ++i) {
      const I8* row =
          policy_network->l1_weights[indices[start + (i < count ? i : 0)]]
              .data();
      for (int c = 0; c < kChunksPerMove; ++c) {
        const auto weights = simd::Convert<I16>(
            simd::Load<I8, kChunkSize>(row + c * kChunkSize));
        sums[i * kChunksPerMove + c] =
            simd::MultiplyAddEpi16(weights, hidden_[c]);
      }
    }

    // Pairwise adds collapse the partial sums into one logit per move
    for (int width = kChunks; width > 1; width /= 2) {
      for (int i = 0; i < width / 2; ++i) {
        sums[i] = simd::PairwiseAdd(sums[2 * i], sums[2 * i + 1]);
      }
    }

    alignas(simd::kAlignment) std::array<I32, kBlockSize> out;
    simd::Store<I32, kBlockSize>(out.data(), sums[0]);
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
