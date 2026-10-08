#include "policy_accumulator.h"

namespace nnue::policy {

namespace {

[[nodiscard]] BitBoard PinnedPieces(const BoardState& state, Color side) {
  const Square king = state.King(side).GetLsb();
  const BitBoard enemies = state.Occupied(FlipColor(side));
  const BitBoard queens = state.piece_bbs[PieceType::kQueen];

  BitBoard snipers =
      enemies & ((move_gen::BishopMoves(king, enemies) &
                  (state.piece_bbs[PieceType::kBishop] | queens)) |
                 (move_gen::RookMoves(king, enemies) &
                  (state.piece_bbs[PieceType::kRook] | queens)));

  BitBoard pinned;
  while (snipers) {
    const BitBoard between =
        move_gen::RayBetween(king, snipers.PopLsb()) & state.Occupied();
    if (between.PopCount() == 1) {
      pinned |= between;
    }
  }
  return pinned;
}

[[nodiscard]] BitBoard UnpinnedAttacks(const BoardState& state,
                                       Color side,
                                       BitBoard pinned) {
  const BitBoard occupied = state.Occupied();
  const BitBoard pieces = state.Occupied(side) & ~pinned;
  const BitBoard queens = state.piece_bbs[PieceType::kQueen];

  BitBoard attacks =
      move_gen::KingAttacks(state.King(side).GetLsb()) |
      move_gen::PawnAttacks(state.piece_bbs[PieceType::kPawn] & pieces, side);
  for (const Square square : state.piece_bbs[PieceType::kKnight] & pieces) {
    attacks |= move_gen::KnightMoves(square);
  }
  for (const Square square :
       (state.piece_bbs[PieceType::kBishop] | queens) & pieces) {
    attacks |= move_gen::BishopMoves(square, occupied);
  }
  for (const Square square :
       (state.piece_bbs[PieceType::kRook] | queens) & pieces) {
    attacks |= move_gen::RookMoves(square, occupied);
  }
  return attacks;
}

[[nodiscard]] BitBoard TheirUnpinnedAttacks(const BoardState& state,
                                            BitBoard pinned) {
  const Color them = FlipColor(state.turn);
  const BitBoard occupied = state.Occupied();
  const BitBoard their_pieces = state.Occupied(them);

  BitBoard attacks = state.threatened_by[PieceType::kKing];
  for (int piece = PieceType::kPawn; piece < PieceType::kKing; ++piece) {
    const BitBoard pieces = state.piece_bbs[piece] & their_pieces;
    if (!(pieces & pinned)) {
      attacks |= state.threatened_by[piece];
    } else if (piece == PieceType::kPawn) {
      attacks |= move_gen::PawnAttacks(pieces & ~pinned, them);
    } else {
      for (const Square square : pieces & ~pinned) {
        attacks |= move_gen::GetPieceAttacks(
            square, static_cast<PieceType>(piece), them, occupied);
      }
    }
  }
  return attacks;
}

}  // namespace

std::array<BitBoard, 2> PolicyAccumulator::CalculateThreats(
    const BoardState& state) {
  const Color us = state.turn, them = FlipColor(us);

  // The board's threats only differ when a side has pinned pieces
  std::array<BitBoard, 2> threats;
  const BitBoard our_pinned = state.pinned[us];
  threats[us] =
      our_pinned ? UnpinnedAttacks(state, us, our_pinned) : state.threats[them];

  const BitBoard their_pinned = PinnedPieces(state, them);
  threats[them] = their_pinned ? TheirUnpinnedAttacks(state, their_pinned)
                               : state.threats[us];
  return threats;
}

void PolicyAccumulator::Refresh(const BoardState& state) {
  const Color us = state.turn, them = FlipColor(us);
  const auto threats = CalculateThreats(state);

  const int flip =
      (us == Color::kBlack ? 0b111000 : 0) ^
      (Square(state.King(us).GetLsb()).File() >= File::kFileE ? 0b000111 : 0);

  const auto& weights = policy_network->feature_weights;
  values_ = simd::Convert<I16>(
      simd::Load<I8, kWidth>(policy_network->feature_biases.data()));

  for (const Color side : {us, them}) {
    const bool is_them = side != us;
    const BitBoard side_pieces = state.Occupied(side);
    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
      for (const Square square : state.piece_bbs[piece] & side_pieces) {
        const auto& row =
            weights[threats[us].IsSet(square)][threats[them].IsSet(square)]
                   [is_them][piece][square ^ flip];
        values_ += simd::Convert<I16>(simd::Load<I8, kWidth>(row.data()));
      }
    }
  }
}

}  // namespace nnue::policy
