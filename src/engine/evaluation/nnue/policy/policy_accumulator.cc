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
  const BitBoard their_threats = state.threats;

  const auto& weights = policy_network->feature_weights;
  values_ = simd::Convert<I16>(
      simd::Load<I8, kWidth>(policy_network->feature_biases.data()));

  for (const Color side : {us, them}) {
    const BitBoard side_pieces = state.Occupied(side);
    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
      for (const Square square : state.piece_bbs[piece] & side_pieces) {
        const auto& row =
            weights[our_threats.IsSet(square)][their_threats.IsSet(square)]
                   [side != us][piece][square ^ flip];
        values_ += simd::Convert<I16>(simd::Load<I8, kWidth>(row.data()));
      }
    }
  }
}

}  // namespace nnue::policy
