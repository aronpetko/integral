#include "threat_accumulator.h"

#include "pawn_pair/pawn_pair_features.h"
#include "threats/threat_features.h"

namespace nnue {

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

template <bool kAddChange>
void ThreatAccumulatorChange::UpdateThreatsForPiece(const BoardState& state,
                                                    PieceType piece_type,
                                                    Color piece_color,
                                                    Square square,
                                                    BitBoard exclude) {
  // Kings are neither valid attackers nor valid victims, so they only ever
  // affect the threat features by blocking rays.
  if (piece_type == PieceType::kKing) {
    return;
  }

  const auto occupied = state.Occupied();
  const auto candidates = occupied & ~state.Kings() & ~exclude;

  // Push all outgoing threats
  const auto threatened_pieces =
      move_gen::GetPieceAttacks(square, piece_type, piece_color, occupied) &
      candidates;
  for (const Square attacked_sq : threatened_pieces) {
    const auto victim_type = state.GetPieceType(attacked_sq);
    const auto victim_color = state.GetPieceColor(attacked_sq);
    PushChangeInfo<kAddChange>({.attacker_square = square,
                                .attacker_type = piece_type,
                                .attacker_color = piece_color,
                                .victim_square = attacked_sq,
                                .victim_type = victim_type,
                                .victim_color = victim_color});
  }

  // Push all incoming threats
  BitBoard incoming_threats = 0;
  incoming_threats |=
      state.Pawns(Color::kBlack) & move_gen::PawnAttacks(square, Color::kWhite);
  incoming_threats |=
      state.Pawns(Color::kWhite) & move_gen::PawnAttacks(square, Color::kBlack);
  incoming_threats |= state.Knights() & move_gen::KnightMoves(square);

  const auto rooks = state.Queens() | state.Rooks();
  const auto bishops = state.Queens() | state.Bishops();
  const auto rook_attacks = move_gen::RookMoves(square, occupied);
  const auto bishop_attacks = move_gen::BishopMoves(square, occupied);
  incoming_threats |= (rooks & rook_attacks) | (bishops & bishop_attacks);

  for (const Square attacker_sq : incoming_threats & ~exclude) {
    const auto attacker_type = state.GetPieceType(attacker_sq);
    const auto attacker_color = state.GetPieceColor(attacker_sq);
    PushChangeInfo<kAddChange>({.attacker_square = attacker_sq,
                                .attacker_type = attacker_type,
                                .attacker_color = attacker_color,
                                .victim_square = square,
                                .victim_type = piece_type,
                                .victim_color = piece_color});
  }
}

template <bool kAddChange>
void ThreatAccumulatorChange::UpdateDiscoveredThreats(const BoardState& state,
                                                      Square square,
                                                      BitBoard exclude) {
  const auto occupied = state.Occupied();
  const auto candidates = occupied & ~state.Kings() & ~exclude;

  const auto rook_attacks = move_gen::RookMoves(square, occupied);
  const auto bishop_attacks = move_gen::BishopMoves(square, occupied);
  const auto queens = state.Queens();

  const auto push_discoveries = [&](BitBoard sliders, BitBoard attacks) {
    for (const Square attacker_sq : sliders & ~exclude) {
      // Ignore if the ray already passed an updated square on its way here
      if (move_gen::RayBetween(attacker_sq, square) & exclude) {
        continue;
      }

      const auto line = move_gen::RayIntersecting(attacker_sq, square);
      const auto behind =
          attacks & candidates & line & ~BitBoard::FromSquare(attacker_sq);
      if (!behind) {
        continue;
      }

      const Square victim_sq = behind.GetLsb();
      const auto attacker_type = state.GetPieceType(attacker_sq);
      const auto attacker_color = state.GetPieceColor(attacker_sq);
      PushChangeInfo<kAddChange>(
          {.attacker_square = attacker_sq,
           .attacker_type = attacker_type,
           .attacker_color = attacker_color,
           .victim_square = victim_sq,
           .victim_type = state.GetPieceType(victim_sq),
           .victim_color = state.GetPieceColor(victim_sq)});
    }
  };

  push_discoveries((queens | state.Rooks()) & rook_attacks, rook_attacks);
  push_discoveries((queens | state.Bishops()) & bishop_attacks, bishop_attacks);
}

template <bool kAddChange>
void ThreatAccumulatorChange::UpdateThreatsForSquares(
    const BoardState& state, BitBoard updated_squares) {
  BitBoard seen;
  for (const Square square : updated_squares) {
    const auto piece_type = state.GetPieceType(square);
    if (piece_type == PieceType::kNone) {
      UpdateDiscoveredThreats<kAddChange>(state, square, updated_squares);
    } else {
      UpdateThreatsForPiece<kAddChange>(
          state, piece_type, state.GetPieceColor(square), square, seen);
    }
    seen |= BitBoard::FromSquare(square);
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

template void ThreatAccumulatorChange::UpdateThreatsForPiece<false>(
    const BoardState& state,
    PieceType piece_type,
    Color piece_color,
    Square square,
    BitBoard exclude);
template void ThreatAccumulatorChange::UpdateThreatsForPiece<true>(
    const BoardState& state,
    PieceType piece_type,
    Color piece_color,
    Square square,
    BitBoard exclude);
template void ThreatAccumulatorChange::UpdateDiscoveredThreats<false>(
    const BoardState& state, Square square, BitBoard exclude);
template void ThreatAccumulatorChange::UpdateDiscoveredThreats<true>(
    const BoardState& state, Square square, BitBoard exclude);
template void ThreatAccumulatorChange::UpdateThreatsForSquares<false>(
    const BoardState& state, BitBoard updated_squares);
template void ThreatAccumulatorChange::UpdateThreatsForSquares<true>(
    const BoardState& state, BitBoard updated_squares);

std::pair<ThreatFeaturePolicy::Weight const*, bool>
ThreatFeaturePolicy::FeatureRow(Color perspective,
                                Square king_square,
                                PieceType attacker,
                                Color attacker_color,
                                PieceType victim,
                                Color victim_color,
                                Square from,
                                Square to) {
  attacker_color = RelativeColor(attacker_color, perspective);
  victim_color = RelativeColor(victim_color, perspective);

  // Horizontal mirroring
  const U8 square_flip =
      (0b111000 * perspective) | (0b111 * (king_square.File() >= kFileE));
  from = from ^ square_flip;
  to = to ^ square_flip;

  const auto [feature_idx, valid] = threats::GetThreatFeatureIndex(
      attacker, attacker_color, victim, victim_color, from, to);
  const auto row = arch::kPawnPairFeatureCount + feature_idx;
  return {network->threat_weights[row].as_array().data(), valid};
}

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

  for (int i = 0; i < change.threat_adds.Size(); ++i) {
    const auto& add = change.threat_adds[i];
    const auto [row, valid] =
        ThreatFeaturePolicy::FeatureRow(perspective,
                                        king_square,
                                        add.attacker_type,
                                        add.attacker_color,
                                        add.victim_type,
                                        add.victim_color,
                                        add.attacker_square,
                                        add.victim_square);
    __builtin_prefetch(row);
    add_rows[num_add] = row;
    num_add += valid;
  }
  for (int i = 0; i < change.threat_subs.Size(); ++i) {
    const auto& sub = change.threat_subs[i];
    const auto [row, valid] =
        ThreatFeaturePolicy::FeatureRow(perspective,
                                        king_square,
                                        sub.attacker_type,
                                        sub.attacker_color,
                                        sub.victim_type,
                                        sub.victim_color,
                                        sub.attacker_square,
                                        sub.victim_square);
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
