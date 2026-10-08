#include "policy_accumulator.h"

namespace nnue::policy {

namespace {

[[nodiscard]] bool IsMirrored(const BoardState& state) {
  return Square(state.King(state.turn).GetLsb()).File() >= File::kFileE;
}

[[nodiscard]] int GetFlip(Color turn, bool mirror) {
  return (turn == Color::kBlack ? 0b111000 : 0) ^ (mirror ? 0b000111 : 0);
}

// Adds or subtracts the rows of the pieces on `squares`, as given by the
// bitboards of the position they're in
template <bool kAdd>
void ApplyRows(PolicyAccumulator::Vector& values,
               BitBoard squares,
               const std::array<BitBoard, kNumPieceTypes>& piece_bbs,
               const std::array<BitBoard, 2>& side_bbs,
               const std::array<BitBoard, 2>& threats,
               Color us,
               int flip) {
  constexpr int kWidth = PolicyAccumulator::kWidth;
  const Color them = FlipColor(us);
  const auto& weights = policy_network->feature_weights;

  for (const Color side : {us, them}) {
    const BitBoard side_squares = squares & side_bbs[side];
    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
      for (const Square square : (side_squares & piece_bbs[piece])) {
        // threats[c] holds the squares attacked by c's opponent
        const auto& row =
            weights[threats[them].IsSet(square)][threats[us].IsSet(square)]
                   [side != us][piece][square ^ flip];
        const auto delta =
            simd::Convert<I16>(simd::Load<I8, kWidth>(row.data()));
        if constexpr (kAdd) {
          values += delta;
        } else {
          values -= delta;
        }
      }
    }
  }
}

}  // namespace

void PolicyAccumulator::Refresh(const BoardState& state) {
  piece_bbs_ = state.piece_bbs;
  side_bbs_ = state.side_bbs;
  threats_ = state.threats;
  key_ = state.zobrist_key;
  turn_ = state.turn;
  mirror_ = IsMirrored(state);
  valid_ = true;

  values_ = simd::Convert<I16>(
      simd::Load<I8, kWidth>(policy_network->feature_biases.data()));
  ApplyRows<true>(values_,
                  state.Occupied(),
                  piece_bbs_,
                  side_bbs_,
                  threats_,
                  turn_,
                  GetFlip(turn_, mirror_));
}

BitBoard PolicyAccumulator::ChangedSquares(const BoardState& state) const {
  BitBoard changed =
      (side_bbs_[0] ^ state.side_bbs[0]) | (side_bbs_[1] ^ state.side_bbs[1]) |
      (threats_[0] ^ state.threats[0]) | (threats_[1] ^ state.threats[1]);
  for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
    changed |= piece_bbs_[piece] ^ state.piece_bbs[piece];
  }
  return changed;
}

int PolicyAccumulator::UpdateCost(const BoardState& state) const {
  if (!valid_ || state.turn != turn_ || IsMirrored(state) != mirror_) {
    return -1;
  }

  const BitBoard changed = ChangedSquares(state);
  return (changed & (side_bbs_[0] | side_bbs_[1])).PopCount() +
         (changed & state.Occupied()).PopCount();
}

void PolicyAccumulator::Update(const BoardState& state) {
  const BitBoard changed = ChangedSquares(state);
  const int flip = GetFlip(turn_, mirror_);

  ApplyRows<false>(values_,
                   changed & (side_bbs_[0] | side_bbs_[1]),
                   piece_bbs_,
                   side_bbs_,
                   threats_,
                   turn_,
                   flip);
  ApplyRows<true>(values_,
                  changed & state.Occupied(),
                  state.piece_bbs,
                  state.side_bbs,
                  state.threats,
                  turn_,
                  flip);

  piece_bbs_ = state.piece_bbs;
  side_bbs_ = state.side_bbs;
  threats_ = state.threats;
  key_ = state.zobrist_key;
}

}  // namespace nnue::policy
