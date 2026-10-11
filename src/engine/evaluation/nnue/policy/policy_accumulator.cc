#include "policy_accumulator.h"

namespace nnue::policy {

void PolicyAccumulator::Refresh(const BoardState& state) {
  const Color us = state.turn, them = FlipColor(us);
  const int flip =
      (us == Color::kBlack ? 0b111000 : 0) ^
      (Square(state.King(us).GetLsb()).File() >= File::kFileE ? 0b000111 : 0);

  const BitBoard occupied = state.Occupied();
  const BitBoard queens = state.Queens(us);

  BitBoard our_threats = move_gen::KingAttacks(state.King(us).GetLsb()) |
                         move_gen::PawnAttacks(state.Pawns(us), us);
  for (const Square square : state.Knights(us)) {
    our_threats |= move_gen::KnightMoves(square);
  }
  for (const Square square : state.Bishops(us) | queens) {
    our_threats |= move_gen::BishopMoves(square, occupied);
  }
  for (const Square square : state.Rooks(us) | queens) {
    our_threats |= move_gen::RookMoves(square, occupied);
  }

  const auto ours = static_cast<U64>(our_threats);
  const auto theirs = static_cast<U64>(state.threats);
  const auto their_pieces = static_cast<U64>(state.Occupied(them));

  // Single branchless loop over all pieces, accumulated in registers
  const auto* weights =
      reinterpret_cast<const I8*>(&policy_network->feature_weights);
  auto values = simd::Convert<I16>(
      simd::Load<I8, kWidth>(policy_network->feature_biases.data()));
#if defined(__clang__)
#pragma clang loop unroll(disable)
#elif defined(__GNUC__)
#pragma GCC unroll 1
#endif
  for (const Square square : occupied) {
    const U64 bit = 1ULL << square;
    const int threat = 2 * !!(ours & bit) + !!(theirs & bit);
    const int side = !!(their_pieces & bit);
    const int feature = ((threat * 2 + side) * PieceType::kNumPieceTypes +
                         state.piece_on_square[square]) *
                            Squares::kSquareCount +
                        (square ^ flip);
    values += simd::Convert<I16>(
        simd::Load<I8, kWidth>(weights + feature * kWidth));
  }
  values_ = values;
}

}  // namespace nnue::policy
