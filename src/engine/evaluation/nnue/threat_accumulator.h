#ifndef INTEGRAL_THREAT_ACCUMULATOR_H
#define INTEGRAL_THREAT_ACCUMULATOR_H

#include "perspective_accumulator.h"

namespace nnue {

struct ThreatAccumulatorChange {
  static constexpr int kMaxThreatRows = 256;

  struct ThreatChangeInfo {
    Square attacker_square;
    PieceType attacker_type;
    Color attacker_color;
    Square victim_square;
    PieceType victim_type;
    Color victim_color;
  };

  template <bool kAddChange>
  void PushChangeInfo(ThreatChangeInfo info);

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

  List<ThreatChangeInfo, kMaxThreatRows> adds;
  List<ThreatChangeInfo, kMaxThreatRows> subs;

  void Clear() {
    adds.Clear(), subs.Clear();
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
  static std::optional<std::span<Weight, kWidth>> FeatureRow(
      Color perspective,
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
    // Only an occupied, non-king square can carry a threat, so mask the attack
    // set down before walking it rather than testing every empty square it
    // covers -- a queen typically attacks far more empty squares than pieces.
    const auto candidates = occupied & ~state.Kings();
    for (const Color attacker_color : {Color::kWhite, Color::kBlack}) {
      const auto side_occupancy = state.Occupied(attacker_color);
      for (int piece = PieceType::kPawn; piece <= PieceType::kQueen; ++piece) {
        const auto attacker_type = static_cast<PieceType>(piece);
        for (Square from : state.piece_bbs[piece] & side_occupancy) {
          const auto attacks = move_gen::GetPieceAttacks(
              from, attacker_type, attacker_color, occupied);
          for (const Square to : attacks & candidates) {
            const auto victim = state.GetPieceType(to);
            const auto victim_color = state.GetPieceColor(to);
            if (const auto threat_feature_row = FeatureRow(perspective,
                                                           king_square,
                                                           attacker_type,
                                                           attacker_color,
                                                           victim,
                                                           victim_color,
                                                           from,
                                                           to)) {
              emit(threat_feature_row.value().data());
            }
          }
        }
      }
    }
  }
};

class ThreatPerspectiveAccumulator
    : public PerspectiveAccumulator<ThreatFeaturePolicy> {
 public:
  static void ApplyChangeBothPerspectives(
      std::array<ThreatPerspectiveAccumulator, 2>& accumulators,
      const std::array<ThreatPerspectiveAccumulator, 2>& previous,
      const ThreatAccumulatorChange& change,
      const std::array<Square, 2>& king_squares);

  void ApplyChange(const ThreatPerspectiveAccumulator& previous,
                   const ThreatAccumulatorChange& change,
                   Color perspective,
                   Square king_square);
};

}  // namespace nnue

#endif  // INTEGRAL_THREAT_ACCUMULATOR_H