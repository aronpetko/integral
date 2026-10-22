#include "threat_accumulator.h"

#include "pawn_pair/pawn_pair_features.h"
#include "threats/threat_features.h"

namespace nnue {

namespace {

[[nodiscard]] BitBoard ValidVictims(const BoardState& state,
                                    PieceType attacker) {
  switch (attacker) {
    case PieceType::kPawn:
      return state.Knights() | state.Rooks();
    case PieceType::kBishop:
    case PieceType::kRook:
      return state.Pawns() | state.Knights() | state.Bishops() | state.Rooks();
    case PieceType::kKnight:
    case PieceType::kQueen:
      return state.KinglessOccupied();
    default:
      return 0;
  }
}

[[nodiscard]] constexpr bool HasThreatFeatures(PieceType attacker,
                                               PieceType victim) {
  return threats::kPieceTypeTargetMap[attacker][victim] != -1;
}

}  // namespace

template <bool kAddChange>
void ThreatAccumulatorChange::PushChangeInfo(ThreatChangeInfo info) {
  if constexpr (kAddChange) {
    threat_adds.Push(info);
  } else {
    threat_subs.Push(info);
  }
}

template <bool kAddChange>
void ThreatAccumulatorChange::PushChangeInfo(PawnPairChangeInfo info) {
  if constexpr (kAddChange) {
    pawn_pair_adds.Push(info);
  } else {
    pawn_pair_subs.Push(info);
  }
}

template <bool kPutPiece, bool kChangesOccupancy>
void ThreatAccumulatorChange::UpdateThreatsForPiece(const BoardState& state,
                                                    PieceType piece_type,
                                                    Color piece_color,
                                                    Square square) {
  const auto occupied = state.Occupied();
  const auto rook_attacks = move_gen::RookMoves(square, occupied);
  const auto bishop_attacks = move_gen::BishopMoves(square, occupied);
  const auto queens = state.Queens();
  const auto rook_sliders = (queens | state.Rooks()) & rook_attacks;
  const auto bishop_sliders = (queens | state.Bishops()) & bishop_attacks;

  const auto victims = state.KinglessOccupied();
  const auto push_blocked = [&](BitBoard sliders, BitBoard attacks) {
    for (const Square slider_sq : sliders) {
      const auto behind = attacks & victims &
                          move_gen::RayIntersecting(slider_sq, square) &
                          ~BitBoard::FromSquare(slider_sq);
      if (!behind) {
        continue;
      }

      const Square victim_sq = behind.GetLsb();
      const auto slider_type = state.GetPieceType(slider_sq);
      const auto victim_type = state.GetPieceType(victim_sq);
      if (!HasThreatFeatures(slider_type, victim_type)) {
        continue;
      }

      PushChangeInfo<!kPutPiece>(
          {.attacker_square = slider_sq,
           .victim_square = victim_sq,
           .pair = threats::PackThreatPair(slider_type,
                                           state.GetPieceColor(slider_sq),
                                           victim_type,
                                           state.GetPieceColor(victim_sq))});
    }
  };
  if constexpr (kChangesOccupancy) {
    push_blocked(rook_sliders, rook_attacks);
    push_blocked(bishop_sliders, bishop_attacks);
  }

  // Kings are neither valid attackers nor valid victims, so they only ever
  // affect the threat features by blocking rays
  if (piece_type == PieceType::kKing) {
    return;
  }

  BitBoard attacks;
  switch (piece_type) {
    case PieceType::kBishop:
      attacks = bishop_attacks;
      break;
    case PieceType::kRook:
      attacks = rook_attacks;
      break;
    case PieceType::kQueen:
      attacks = rook_attacks | bishop_attacks;
      break;
    default:
      attacks =
          move_gen::GetPieceAttacks(square, piece_type, piece_color, occupied);
      break;
  }

  // Push all outgoing threats
  for (const Square attacked_sq : attacks& ValidVictims(state, piece_type)) {
    PushChangeInfo<kPutPiece>(
        {.attacker_square = square,
         .victim_square = attacked_sq,
         .pair = threats::PackThreatPair(piece_type,
                                         piece_color,
                                         state.GetPieceType(attacked_sq),
                                         state.GetPieceColor(attacked_sq))});
  }

  // Push all incoming threats
  BitBoard incoming_threats = state.Knights() & move_gen::KnightMoves(square);
  if (HasThreatFeatures(PieceType::kPawn, piece_type)) {
    incoming_threats |= state.Pawns(Color::kBlack) &
                        move_gen::PawnAttacks(square, Color::kWhite);
    incoming_threats |= state.Pawns(Color::kWhite) &
                        move_gen::PawnAttacks(square, Color::kBlack);
  }
  if (HasThreatFeatures(PieceType::kRook, piece_type)) {
    incoming_threats |= rook_sliders;
  } else {
    incoming_threats |= rook_sliders & queens;
  }
  if (HasThreatFeatures(PieceType::kBishop, piece_type)) {
    incoming_threats |= bishop_sliders;
  } else {
    incoming_threats |= bishop_sliders & queens;
  }

  for (const Square attacker_sq : incoming_threats) {
    PushChangeInfo<kPutPiece>(
        {.attacker_square = attacker_sq,
         .victim_square = square,
         .pair = threats::PackThreatPair(state.GetPieceType(attacker_sq),
                                         state.GetPieceColor(attacker_sq),
                                         piece_type,
                                         piece_color)});
  }
}

void ThreatAccumulatorChange::UpdateThreatsForMove(
    const BoardState& state, const PsqtAccumulatorChange& change) {
  BoardState board = state;
  const auto& moved = change.sub_0;
  const auto& landed = change.add_0;

  // Lift the moving piece off its square
  UpdateThreatsForPiece<false, true>(
      board, moved.piece, moved.color, moved.square);
  board.RemovePiece<false>(moved.square, moved.color);

  // A capture on the destination only swaps its occupant, so the rays it
  // blocks stay blocked
  if (change.type == PsqtAccumulatorChange::kCapture &&
      change.sub_1.square == landed.square) {
    const auto& captured = change.sub_1;
    UpdateThreatsForPiece<false, false>(
        board, captured.piece, captured.color, captured.square);
    board.RemovePiece<false>(captured.square, captured.color);
    board.PlacePiece<false>(landed.square, landed.piece, landed.color);
    UpdateThreatsForPiece<true, false>(
        board, landed.piece, landed.color, landed.square);
    return;
  }

  // The en passant pawn or castling rook leaves before anything lands
  if (change.type != PsqtAccumulatorChange::kNormal) {
    const auto& removed = change.sub_1;
    UpdateThreatsForPiece<false, true>(
        board, removed.piece, removed.color, removed.square);
    board.RemovePiece<false>(removed.square, removed.color);
  }

  // Put the moving piece down
  board.PlacePiece<false>(landed.square, landed.piece, landed.color);
  UpdateThreatsForPiece<true, true>(
      board, landed.piece, landed.color, landed.square);

  // The castling rook lands last
  if (change.type == PsqtAccumulatorChange::kCastle) {
    const auto& rook = change.add_1;
    board.PlacePiece<false>(rook.square, rook.piece, rook.color);
    UpdateThreatsForPiece<true, true>(
        board, rook.piece, rook.color, rook.square);
  }
}

template <bool kAddChange>
void ThreatAccumulatorChange::UpdatePawnPairsForSquares(
    const BoardState& state, BitBoard updated_squares) {
  BitBoard candidates = state.Pawns();
  const auto changed_pawns = updated_squares & candidates;
  if (!changed_pawns) {
    return;
  }

  std::array<U8, 2> square_flips;
  for (const Color perspective : {kWhite, kBlack}) {
    const Square king_square = state.King(perspective).GetLsb();
    square_flips[perspective] =
        (0b111000 * perspective) | (0b111 * (king_square.File() >= kFileE));
  }

  // Remove processed pawns from candidates for captures and en passant
  for (const Square pawn_square : changed_pawns) {
    candidates &= ~BitBoard::FromSquare(pawn_square);

    const auto pawn_color = state.GetPieceColor(pawn_square);
    std::array<pawn_pair::PawnId, 2> first_ids;
    for (const Color perspective : {kWhite, kBlack}) {
      first_ids[perspective] = pawn_pair::GetPawnId(
          pawn_square ^ square_flips[perspective], pawn_color, perspective);
    }

    for (const Square other :
         (candidates & pawn_pair::kAdjacentFileMasks[pawn_square])) {
      const auto other_color = state.GetPieceColor(other);

      PawnPairChangeInfo change;
      for (const Color perspective : {kWhite, kBlack}) {
        const auto second_id = pawn_pair::GetPawnId(
            other ^ square_flips[perspective], other_color, perspective);
        change.indices[perspective] =
            pawn_pair::GetPawnIndex(first_ids[perspective], second_id);
      }

      PushChangeInfo<kAddChange>(change);
    }
  }
}

template void ThreatAccumulatorChange::UpdatePawnPairsForSquares<false>(
    const BoardState& state, BitBoard updated_squares);
template void ThreatAccumulatorChange::UpdatePawnPairsForSquares<true>(
    const BoardState& state, BitBoard updated_squares);

ThreatFeaturePolicy::Weight const* ThreatFeaturePolicy::PawnPairRow(
    Color perspective,
    Square king_square,
    Square first,
    Color first_color,
    Square second,
    Color second_color) {
  const auto index = pawn_pair::GetPawnPairIndex(
      first, first_color, second, second_color, perspective, king_square);
  return network->threat_weights[index].as_array().data();
}

void ThreatPerspectiveAccumulator::ApplyChange(
    const ThreatPerspectiveAccumulator& previous,
    const ThreatAccumulatorChange& change,
    Color perspective,
    Square king_square) {
  constexpr int kMaxRows = ThreatAccumulatorChange::kMaxThreatRows +
                           ThreatAccumulatorChange::kMaxPawnPairRows;
  std::array<Weight const*, kMaxRows> add_rows;
  U16 num_add = 0;
  std::array<Weight const*, kMaxRows> sub_rows;
  U16 num_sub = 0;

  const U8 square_flip =
      ThreatFeaturePolicy::SquareFlip(perspective, king_square);
  const U8 pair_flip = ThreatFeaturePolicy::PairFlip(perspective);

  for (int i = 0; i < change.threat_adds.Size(); ++i) {
    const auto& add = change.threat_adds[i];
    const auto [row, valid] =
        ThreatFeaturePolicy::FeatureRow(add.pair ^ pair_flip,
                                        add.attacker_square ^ square_flip,
                                        add.victim_square ^ square_flip);
    __builtin_prefetch(row);
    add_rows[num_add] = row;
    num_add += valid;
  }
  for (int i = 0; i < change.threat_subs.Size(); ++i) {
    const auto& sub = change.threat_subs[i];
    const auto [row, valid] =
        ThreatFeaturePolicy::FeatureRow(sub.pair ^ pair_flip,
                                        sub.attacker_square ^ square_flip,
                                        sub.victim_square ^ square_flip);
    __builtin_prefetch(row);
    sub_rows[num_sub] = row;
    num_sub += valid;
  }

  for (int i = 0; i < change.pawn_pair_adds.Size(); ++i) {
    const auto add = change.pawn_pair_adds[i];
    const auto* row =
        network->threat_weights[add.indices[perspective]].as_array().data();
    __builtin_prefetch(row);
    add_rows[num_add++] = row;
  }
  for (int i = 0; i < change.pawn_pair_subs.Size(); ++i) {
    const auto sub = change.pawn_pair_subs[i];
    const auto* row =
        network->threat_weights[sub.indices[perspective]].as_array().data();
    __builtin_prefetch(row);
    sub_rows[num_sub++] = row;
  }

  ApplyDeltas(previous, add_rows.data(), num_add, sub_rows.data(), num_sub);
}

}  // namespace nnue
