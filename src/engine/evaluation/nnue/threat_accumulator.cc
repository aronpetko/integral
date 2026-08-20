#include "threat_accumulator.h"

#include "threats/threat_features.h"

namespace nnue {

template <bool kAddChange>
void ThreatAccumulatorChange::PushChangeInfo(ThreatChangeInfo info) {
  if constexpr (kAddChange) {
    adds.Push(info);
  } else {
    subs.Push(info);
  }
}

void ThreatAccumulatorChange::Update(const BoardState& previous,
                                     const BoardState& current,
                                     BitBoard changed_squares) {
  UpdateChangedSquares<false>(previous, changed_squares);
  UpdateChangedSquares<true>(current, changed_squares);
  UpdateSliderDeltas(previous, current, changed_squares);
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
void ThreatAccumulatorChange::UpdateChangedSquares(const BoardState& state,
                                                   BitBoard changed_squares) {
  BitBoard seen = 0;
  for (const Square square : changed_squares) {
    const PieceType piece_type = state.GetPieceType(square);
    // Empty square in this state has no threat feature of its own
    if (piece_type != PieceType::kNone) {
      UpdateThreatsForPiece<kAddChange>(
          state, piece_type, state.GetPieceColor(square), square, seen);
    }
    // Prevent relationships between two changed squares from being emitted
    // twice.
    seen |= BitBoard::FromSquare(square);
  }
}

void ThreatAccumulatorChange::UpdateSliderDeltas(const BoardState& previous,
                                                 const BoardState& current,
                                                 BitBoard changed_squares) {
  const BitBoard previous_occ = previous.Occupied();
  const BitBoard current_occ = current.Occupied();

  const BitBoard previous_bishop_sliders =
      previous.Bishops() | previous.Queens();
  const BitBoard previous_rook_sliders = previous.Rooks() | previous.Queens();

  const BitBoard current_bishop_sliders = current.Bishops() | current.Queens();
  const BitBoard current_rook_sliders = current.Rooks() | current.Queens();

  // Find unchanged sliders whose rays pass through a changed square
  BitBoard affected_sliders = 0;
  for (const Square square : changed_squares) {
    affected_sliders |=
        move_gen::BishopMoves(square, previous_occ) & previous_bishop_sliders;

    affected_sliders |=
        move_gen::RookMoves(square, previous_occ) & previous_rook_sliders;

    affected_sliders |=
        move_gen::BishopMoves(square, current_occ) & current_bishop_sliders;

    affected_sliders |=
        move_gen::RookMoves(square, current_occ) & current_rook_sliders;
  }
  affected_sliders &= ~changed_squares;

  const BitBoard previous_candidates =
      previous_occ & ~previous.Kings() & ~changed_squares;

  const BitBoard current_candidates =
      current_occ & ~current.Kings() & ~changed_squares;

  for (const Square attacker_square : affected_sliders) {
    const PieceType attacker_type = current.GetPieceType(attacker_square);
    const Color attacker_color = current.GetPieceColor(attacker_square);
    assert(attacker_type == PieceType::kBishop ||
           attacker_type == PieceType::kRook ||
           attacker_type == PieceType::kQueen);

    const BitBoard previous_attacks =
        move_gen::GetPieceAttacks(
            attacker_square, attacker_type, attacker_color, previous_occ) &
        previous_candidates;

    const BitBoard current_attacks =
        move_gen::GetPieceAttacks(
            attacker_square, attacker_type, attacker_color, current_occ) &
        current_candidates;

    const BitBoard dropped = previous_attacks & ~current_attacks;

    const BitBoard gained = current_attacks & ~previous_attacks;

    // Threats that existed before but no longer exist
    for (const Square victim_square : dropped) {
      PushChangeInfo<false>({
          .attacker_square = attacker_square,
          .attacker_type = attacker_type,
          .attacker_color = attacker_color,
          .victim_square = victim_square,
          .victim_type = previous.GetPieceType(victim_square),
          .victim_color = previous.GetPieceColor(victim_square),
      });
    }

    // Newly created threats
    for (const Square victim_square : gained) {
      PushChangeInfo<true>({
          .attacker_square = attacker_square,
          .attacker_type = attacker_type,
          .attacker_color = attacker_color,
          .victim_square = victim_square,
          .victim_type = current.GetPieceType(victim_square),
          .victim_color = current.GetPieceColor(victim_square),
      });
    }
  }
}

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
template void ThreatAccumulatorChange::UpdateChangedSquares<false>(
    const BoardState& state, BitBoard changed_squares);
template void ThreatAccumulatorChange::UpdateChangedSquares<true>(
    const BoardState& state, BitBoard changed_squares);

std::optional<
    std::span<ThreatFeaturePolicy::Weight, ThreatFeaturePolicy::kWidth>>
ThreatFeaturePolicy::FeatureRow(Color perspective,
                                Square king_square,
                                PieceType attacker,
                                Color attacker_color,
                                PieceType victim,
                                Color victim_color,
                                Square from,
                                Square to) {
  if (perspective == Color::kBlack) {
    attacker_color = FlipColor(attacker_color);
    victim_color = FlipColor(victim_color);
    from = from ^ 0b111000;
    to = to ^ 0b111000;
  }

  // Horizontal mirroring
  if (king_square.File() >= kFileE) {
    from = from ^ 0b111;
    to = to ^ 0b111;
  }

  const auto feature_idx = threats::get_threat_feature_index(
      attacker, attacker_color, victim, victim_color, from, to);
  if (!feature_idx) {
    return std::nullopt;
  }
  return network->threat_weights[feature_idx.value()].as_array();
}

void ThreatPerspectiveAccumulator::ApplyChange(
    const ThreatPerspectiveAccumulator& previous,
    const ThreatAccumulatorChange& change,
    Color perspective,
    Square king_square) {
  std::array<Weight const*, ThreatAccumulatorChange::kMaxThreatRows> add_rows;
  U16 num_add = 0;
  std::array<Weight const*, ThreatAccumulatorChange::kMaxThreatRows> sub_rows;
  U16 num_sub = 0;

  for (int i = 0; i < change.adds.Size(); ++i) {
    const auto& add = change.adds[i];
    const auto row = ThreatFeaturePolicy::FeatureRow(perspective,
                                                     king_square,
                                                     add.attacker_type,
                                                     add.attacker_color,
                                                     add.victim_type,
                                                     add.victim_color,
                                                     add.attacker_square,
                                                     add.victim_square);
    if (row) {
      add_rows[num_add++] = row.value().data();
    }
  }
  for (int i = 0; i < change.subs.Size(); ++i) {
    const auto& sub = change.subs[i];
    const auto row = ThreatFeaturePolicy::FeatureRow(perspective,
                                                     king_square,
                                                     sub.attacker_type,
                                                     sub.attacker_color,
                                                     sub.victim_type,
                                                     sub.victim_color,
                                                     sub.attacker_square,
                                                     sub.victim_square);
    if (row) {
      sub_rows[num_sub++] = row.value().data();
    }
  }

  ApplyDeltas(previous, add_rows.data(), num_add, sub_rows.data(), num_sub);
}

}  // namespace nnue