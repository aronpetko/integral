#ifndef INTEGRAL_THREAT_ACCUMULATOR_H
#define INTEGRAL_THREAT_ACCUMULATOR_H

#include "perspective_accumulator.h"
#include "pawn_pair/pawn_pair_features.h"

namespace nnue {

struct ThreatAccumulatorChange {
  static constexpr int kMaxThreatRows = 256;
  static constexpr int kMaxPawnPairRows = 16 * 15 / 2;

  struct ThreatChangeInfo {
    Square attacker_square;
    PieceType attacker_type;
    Color attacker_color;
    Square victim_square;
    PieceType victim_type;
    Color victim_color;
  };

  struct PawnPairChangeInfo {
    Square pawn_square;
    Color pawn_color;
    Square paired_pawn_square;
    Color paired_pawn_color;
  };

  template <bool kAddChange>
  void PushChangeInfo(ThreatChangeInfo info);

  template <bool kAddChange>
  void PushChangeInfo(PawnPairChangeInfo info);

  template <bool kAddChange>
  void UpdateThreatsForPiece(const BoardState& state,
                             PieceType piece_type,
                             Color piece_color,
                             Square square,
                             BitBoard exclude = 0);
  template <bool kAddChange>
  void UpdateDiscoveredThreats(const BoardState& state,
                               Square square,
                               BitBoard exclude = 0);
  template <bool kAddChange>
  void UpdateThreatsForSquares(const BoardState& state,
                               BitBoard updated_squares);

  template <bool kAddChange>
  void UpdatePawnPairsForSquares(const BoardState& state,
                                 BitBoard updated_squares);

  List<ThreatChangeInfo, kMaxThreatRows> threat_adds;
  List<ThreatChangeInfo, kMaxThreatRows> threat_subs;
  List<PawnPairChangeInfo, kMaxPawnPairRows> pawn_pair_adds;
  List<PawnPairChangeInfo, kMaxPawnPairRows> pawn_pair_subs;

  void Clear() {
    threat_adds.Clear(), threat_subs.Clear();
    pawn_pair_adds.Clear(), pawn_pair_subs.Clear();
  }
};

struct ThreatFeaturePolicy {
  static constexpr int kWidth = arch::kL1Size;
  using Value = I16;
  using Weight = I8;

  // Biases are handled by the PSQT accumulator
  static Value Bias(int) {
    return 0;
  }
  static std::pair<Weight const*, bool> FeatureRow(Color perspective,
                                                   Square king_square,
                                                   PieceType attacker,
                                                   Color attacker_color,
                                                   PieceType victim,
                                                   Color victim_color,
                                                   Square from,
                                                   Square to);

  template <typename Emit>
  static void ForEachActiveFeature(const BoardState& state,
                                   Color perspective,
                                   Square king_square,
                                   Emit&& emit) {
    const auto occupied = state.Occupied();
    const auto targets = state.KinglessOccupied();
    for (int piece = PieceType::kPawn; piece <= PieceType::kQueen; ++piece) {
      for (Square from : state.piece_bbs[piece]) {
        const auto attacker_type = static_cast<PieceType>(piece);
        const auto attacker_color = state.GetPieceColor(from);
        const auto attacks = move_gen::GetPieceAttacks(
            from, attacker_type, attacker_color, occupied);
        for (const Square to : attacks& targets) {
          const auto victim = state.GetPieceType(to);
          const auto victim_color = state.GetPieceColor(to);
          const auto [threat_feature_row, valid] = FeatureRow(perspective,
                                                              king_square,
                                                              attacker_type,
                                                              attacker_color,
                                                              victim,
                                                              victim_color,
                                                              from,
                                                              to);
          __builtin_prefetch(threat_feature_row);
          emit(threat_feature_row, valid);
        }
      }
    }
    auto remaining = state.Pawns();
    for (const Square first : state.Pawns()) {
      remaining &= ~BitBoard::FromSquare(first);
      const auto first_color = state.GetPieceColor(first);
      for (const Square second : remaining & pawn_pair::kAdjacentFileMasks[first]) {
        const auto* row = PawnPairRow(perspective, king_square, first,
                                      first_color, second, state.GetPieceColor(second));
        __builtin_prefetch(row);
        emit(row, true);
      }
    }
  }

  static Weight const* PawnPairRow(Color perspective, Square king_square,
                                   Square first, Color first_color,
                                   Square second, Color second_color);
};

class ThreatPerspectiveAccumulator
    : public PerspectiveAccumulator<ThreatFeaturePolicy> {
 public:
  void ApplyChange(const ThreatPerspectiveAccumulator& previous,
                   const ThreatAccumulatorChange& change,
                   Color perspective,
                   Square king_square);
};

}  // namespace nnue

#endif  // INTEGRAL_THREAT_ACCUMULATOR_H
