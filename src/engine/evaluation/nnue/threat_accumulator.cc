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

template <bool kAddChange>
void ThreatAccumulatorChange::UpdateThreatsForPiece(const BoardState& state,
                                                    Piece piece,
                                                    Square square,
                                                    BitBoard exclude) {
  const auto piece_type = TypeOf(piece);

  // Kings are neither valid attackers nor valid victims, so they only ever
  // affect the threat features by blocking rays.
  if (piece_type == PieceType::kKing) {
    return;
  }

  const auto occupied = state.Occupied();
  const auto candidates = occupied & ~state.Kings() & ~exclude;

  // Push all outgoing threats
  const auto threatened_pieces =
      move_gen::GetPieceAttacks(square, piece_type, ColorOf(piece), occupied) &
      candidates;
  for (const Square attacked_sq : threatened_pieces) {
    PushChangeInfo<kAddChange>({.attacker_square = square,
                                .victim_square = attacked_sq,
                                .attacker_piece = piece,
                                .victim_piece = state.GetPiece(attacked_sq)});
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
    PushChangeInfo<kAddChange>({.attacker_square = attacker_sq,
                                .victim_square = square,
                                .attacker_piece = state.GetPiece(attacker_sq),
                                .victim_piece = piece});
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
      PushChangeInfo<kAddChange>({.attacker_square = attacker_sq,
                                  .victim_square = victim_sq,
                                  .attacker_piece = state.GetPiece(attacker_sq),
                                  .victim_piece = state.GetPiece(victim_sq)});
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
    const auto piece = state.GetPiece(square);
    if (piece == Piece::kNoPiece) {
      UpdateDiscoveredThreats<kAddChange>(state, square, updated_squares);
    } else {
      UpdateThreatsForPiece<kAddChange>(state, piece, square, seen);
    }
    seen |= BitBoard::FromSquare(square);
  }
}

template void ThreatAccumulatorChange::UpdateThreatsForPiece<false>(
    const BoardState& state, Piece piece, Square square, BitBoard exclude);
template void ThreatAccumulatorChange::UpdateThreatsForPiece<true>(
    const BoardState& state, Piece piece, Square square, BitBoard exclude);
template void ThreatAccumulatorChange::UpdateDiscoveredThreats<false>(
    const BoardState& state, Square square, BitBoard exclude);
template void ThreatAccumulatorChange::UpdateDiscoveredThreats<true>(
    const BoardState& state, Square square, BitBoard exclude);
template void ThreatAccumulatorChange::UpdateThreatsForSquares<false>(
    const BoardState& state, BitBoard updated_squares);
template void ThreatAccumulatorChange::UpdateThreatsForSquares<true>(
    const BoardState& state, BitBoard updated_squares);

namespace {

U16 CollectRows(const List<ThreatAccumulatorChange::ThreatChangeInfo,
                           ThreatAccumulatorChange::kMaxThreatRows>& infos,
                Color perspective,
                Square king_square,
                ThreatFeaturePolicy::Weight const** rows) {
  U16 count = 0;
  for (int i = 0; i < infos.Size(); ++i) {
    const auto& info = infos[i];
    const auto feature_index =
        ThreatFeaturePolicy::FeatureIndex(perspective,
                                          king_square,
                                          info.attacker_piece,
                                          info.victim_piece,
                                          info.attacker_square,
                                          info.victim_square);
    rows[count] = ThreatFeaturePolicy::FeatureRow(feature_index);
    count += ThreatFeaturePolicy::IsValidFeature(feature_index);
  }
  return count;
}

}  // namespace

void ThreatPerspectiveAccumulator::ApplyChange(
    const ThreatPerspectiveAccumulator& previous,
    const ThreatAccumulatorChange& change,
    Color perspective,
    Square king_square) {
  std::array<Weight const*, ThreatAccumulatorChange::kMaxThreatRows> add_rows;
  std::array<Weight const*, ThreatAccumulatorChange::kMaxThreatRows> sub_rows;

  const auto num_add =
      CollectRows(change.adds, perspective, king_square, add_rows.data());
  const auto num_sub =
      CollectRows(change.subs, perspective, king_square, sub_rows.data());

  ApplyDeltas(previous, add_rows.data(), num_add, sub_rows.data(), num_sub);
}

void ThreatPerspectiveAccumulator::ApplyChangeBothPerspectives(
    std::array<ThreatPerspectiveAccumulator, 2>& accumulators,
    const std::array<ThreatPerspectiveAccumulator, 2>& previous,
    const ThreatAccumulatorChange& change,
    const std::array<Square, 2>& king_squares) {
  constexpr int kMaxRows = ThreatAccumulatorChange::kMaxThreatRows;
  std::array<std::array<Weight const*, kMaxRows>, 2> add_rows;
  std::array<std::array<Weight const*, kMaxRows>, 2> sub_rows;
  std::array<U16, 2> num_adds{}, num_subs{};

  for (const Color perspective : {Color::kWhite, Color::kBlack}) {
    num_adds[perspective] = CollectRows(change.adds,
                                        perspective,
                                        king_squares[perspective],
                                        add_rows[perspective].data());
    num_subs[perspective] = CollectRows(change.subs,
                                        perspective,
                                        king_squares[perspective],
                                        sub_rows[perspective].data());
  }

  constexpr std::size_t kFusedTile = kTile > 1 ? kTile / 2 : 1;
  static_assert(kChunks % kFusedTile == 0);

  for (std::size_t base = 0; base < kChunks; base += kFusedTile) {
    std::array<std::array<ValueVector, kFusedTile>, 2> values;

    for (const Color perspective : {Color::kWhite, Color::kBlack}) {
      for (std::size_t tile = 0; tile < kFusedTile; ++tile) {
        values[perspective][tile] = simd::Load<Value, kChunk>(
            &previous[perspective].values_[(base + tile) * kChunk]);
      }
    }

    for (const Color perspective : {Color::kWhite, Color::kBlack}) {
      for (U16 sub = 0; sub < num_subs[perspective]; ++sub) {
        Weight const* row = sub_rows[perspective][sub];
        for (std::size_t tile = 0; tile < kFusedTile; ++tile) {
          values[perspective][tile] -= simd::Convert<Value>(
              simd::Load<Weight, kChunk>(&row[(base + tile) * kChunk]));
        }
      }
      for (U16 add = 0; add < num_adds[perspective]; ++add) {
        Weight const* row = add_rows[perspective][add];
        for (std::size_t tile = 0; tile < kFusedTile; ++tile) {
          values[perspective][tile] += simd::Convert<Value>(
              simd::Load<Weight, kChunk>(&row[(base + tile) * kChunk]));
        }
      }
    }

    for (const Color perspective : {Color::kWhite, Color::kBlack}) {
      for (std::size_t tile = 0; tile < kFusedTile; ++tile) {
        simd::Store<Value, kChunk>(
            &accumulators[perspective].values_[(base + tile) * kChunk],
            values[perspective][tile]);
      }
    }
  }
}

}  // namespace nnue