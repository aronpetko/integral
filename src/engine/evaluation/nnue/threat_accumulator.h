#ifndef INTEGRAL_THREAT_ACCUMULATOR_H
#define INTEGRAL_THREAT_ACCUMULATOR_H

#include "perspective_accumulator.h"
#include "threats/threat_features.h"

namespace nnue {

struct ThreatAccumulatorChange {
  static constexpr int kMaxThreatRows = 256;

  struct ThreatChangeInfo {
    Square attacker_square;
    Square victim_square;
    Piece attacker_piece;
    Piece victim_piece;
  };

  template <bool kAddChange>
  void PushChangeInfo(ThreatChangeInfo info);

  template <bool kAddChange>
  void UpdateThreatsForPiece(const BoardState& state,
                             Piece piece,
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

  static U32 FeatureIndex(Color perspective,
                          Square king_square,
                          Piece attacker,
                          Piece victim,
                          Square from,
                          Square to) {
    const U8 flip =
        (0b111000 * perspective) | (0b111 * (king_square.File() >= kFileE));
    return threats::get_threat_feature_index(
        PerspectivePiece(attacker, perspective),
        PerspectivePiece(victim, perspective),
        Square(from ^ flip),
        Square(to ^ flip));
  }

  static bool IsValidFeature(U32 feature_index) {
    return feature_index < arch::kThreatFeatureCount;
  }

  // Clamped, so that a row destined to be discarded still addresses inside the
  // weights. The caller drops it by not counting it rather than by branching.
  static Weight const* FeatureRow(U32 feature_index) {
    return network
        ->threat_weights[IsValidFeature(feature_index) ? feature_index : 0]
        .as_array()
        .data();
  }

  template <typename Emit>
  static void ForEachActiveFeature(const BoardState& state,
                                   Color perspective,
                                   Square king_square,
                                   Emit&& emit) {
    const auto occupied = state.Occupied();
    const auto victims = occupied & ~state.Kings();
    for (int piece = PieceType::kPawn; piece <= PieceType::kQueen; ++piece) {
      for (Square from : state.piece_bbs[piece]) {
        const auto attacker = state.GetPiece(from);
        const auto attacks = move_gen::GetPieceAttacks(
            from, static_cast<PieceType>(piece), ColorOf(attacker), occupied);
        for (const Square to : attacks& victims) {
          const auto feature_index = FeatureIndex(
              perspective, king_square, attacker, state.GetPiece(to), from, to);
          if (IsValidFeature(feature_index)) {
            emit(FeatureRow(feature_index));
          }
        }
      }
    }
  }
};

class ThreatPerspectiveAccumulator
    : public PerspectiveAccumulator<ThreatFeaturePolicy> {
 public:
  void ApplyChange(const ThreatPerspectiveAccumulator& previous,
                   const ThreatAccumulatorChange& change,
                   Color perspective,
                   Square king_square);

  // Folds the change into both perspectives on one pass over them. The same
  // rows land on different weights for each perspective, so doing them together
  // keeps two independent streams of the (very large) threat weights in flight.
  static void ApplyChangeBothPerspectives(
      std::array<ThreatPerspectiveAccumulator, 2>& accumulators,
      const std::array<ThreatPerspectiveAccumulator, 2>& previous,
      const ThreatAccumulatorChange& change,
      const std::array<Square, 2>& king_squares);
};

}  // namespace nnue

#endif  // INTEGRAL_THREAT_ACCUMULATOR_H