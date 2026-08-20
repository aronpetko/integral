#include "threat_accumulator.h"

#include "threats/threat_features.h"

namespace nnue {

namespace {

// Resolves the feature row a single threat change maps to from `perspective`,
// or nullptr if the (attacker, victim) pair carries no feature at all.
inline ThreatFeaturePolicy::Weight const* ResolveRow(
    const ThreatAccumulatorChange::ThreatChangeInfo& info,
    Color perspective,
    Square king_square) {
  const auto row = ThreatFeaturePolicy::FeatureRow(perspective,
                                                   king_square,
                                                   info.attacker_type,
                                                   info.attacker_color,
                                                   info.victim_type,
                                                   info.victim_color,
                                                   info.attacker_square,
                                                   info.victim_square);
  if (!row) {
    return nullptr;
  }
  // The threat weights are far too large to stay resident, so start the fetch
  // now rather than when the tile loop first reaches this row.
  __builtin_prefetch(row->data());
  return row->data();
}

}  // namespace

template <bool kAddChange>
void ThreatAccumulatorChange::PushChangeInfo(ThreatChangeInfo info) {
  if constexpr (kAddChange) {
    adds.Push(info);
  } else {
    subs.Push(info);
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
  std::array<Weight const*, ThreatAccumulatorChange::kMaxThreatRows> sub_rows;
  int num_add = 0, num_sub = 0;

  for (int i = 0; i < change.adds.Size(); ++i) {
    if (const auto row = ResolveRow(change.adds[i], perspective, king_square)) {
      add_rows[num_add++] = row;
    }
  }
  for (int i = 0; i < change.subs.Size(); ++i) {
    if (const auto row = ResolveRow(change.subs[i], perspective, king_square)) {
      sub_rows[num_sub++] = row;
    }
  }

  ApplyDeltas(previous, add_rows.data(), num_add, sub_rows.data(), num_sub);
}

void ThreatPerspectiveAccumulator::ApplyChangeBothPerspectives(
    std::array<ThreatPerspectiveAccumulator, 2>& accumulators,
    const std::array<ThreatPerspectiveAccumulator, 2>& previous,
    const ThreatAccumulatorChange& change,
    const std::array<Square, 2>& king_squares) {
  constexpr int kMaxRows = ThreatAccumulatorChange::kMaxThreatRows;

  std::array<std::array<Weight const*, kMaxRows>, 2> add_rows, sub_rows;
  std::array<int, 2> num_add{}, num_sub{};

  // A change entry is perspective independent, so resolve both of its rows
  // while the entry is hot instead of walking the list once per perspective.
  const auto collect = [&](const auto& list, auto& rows, auto& counts) {
    for (int i = 0; i < list.Size(); ++i) {
      const auto info = list[i];
      for (const Color perspective : {Color::kWhite, Color::kBlack}) {
        if (const auto row =
                ResolveRow(info, perspective, king_squares[perspective])) {
          rows[perspective][counts[perspective]++] = row;
        }
      }
    }
  };
  collect(change.adds, add_rows, num_add);
  collect(change.subs, sub_rows, num_sub);

  // Sweep the accumulator once with both perspectives' tiles live, so every
  // chunk of L1 is loaded and stored a single time for the whole update
  // instead of once per perspective.
  for (int base = 0; base < kWidth; base += kPairedTileWidth) {
    ValueVector tiles[2][kPairedTileVectors];
    for (int perspective = 0; perspective < 2; ++perspective) {
      for (int vec = 0; vec < kPairedTileVectors; ++vec) {
        tiles[perspective][vec] = simd::Load<Value, kLanes>(
            &previous[perspective].values_[base + vec * kLanes]);
      }
    }

    for (int perspective = 0; perspective < 2; ++perspective) {
      for (int i = 0; i < num_add[perspective]; ++i) {
        Weight const* row = add_rows[perspective][i] + base;
        for (int vec = 0; vec < kPairedTileVectors; ++vec) {
          tiles[perspective][vec] += simd::Convert<Value>(
              simd::Load<Weight, kLanes>(row + vec * kLanes));
        }
      }
      for (int i = 0; i < num_sub[perspective]; ++i) {
        Weight const* row = sub_rows[perspective][i] + base;
        for (int vec = 0; vec < kPairedTileVectors; ++vec) {
          tiles[perspective][vec] -= simd::Convert<Value>(
              simd::Load<Weight, kLanes>(row + vec * kLanes));
        }
      }
    }

    for (int perspective = 0; perspective < 2; ++perspective) {
      for (int vec = 0; vec < kPairedTileVectors; ++vec) {
        simd::Store<Value, kLanes>(
            &accumulators[perspective].values_[base + vec * kLanes],
            tiles[perspective][vec]);
      }
    }
  }
}

}  // namespace nnue