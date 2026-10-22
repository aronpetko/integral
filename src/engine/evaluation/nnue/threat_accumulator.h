#ifndef INTEGRAL_THREAT_ACCUMULATOR_H
#define INTEGRAL_THREAT_ACCUMULATOR_H

#include "pawn_pair/pawn_pair_features.h"
#include "perspective_accumulator.h"
#include "psqt_accumulator.h"
#include "threats/threat_features.h"

namespace nnue {

struct ThreatAccumulatorChange {
  static constexpr int kMaxThreatRows = 256;
  static constexpr int kMaxPawnPairRows = 16 * 15 / 2;

  struct ThreatChangeInfo {
    Square attacker_square;
    Square victim_square;
    U8 pair;
  };

  struct PawnPairChangeInfo {
    std::array<U16, 2> indices;
  };

  template <bool kAddChange>
  void PushChangeInfo(ThreatChangeInfo info);

  template <bool kAddChange>
  void PushChangeInfo(PawnPairChangeInfo info);

  template <bool kPutPiece, bool kChangesOccupancy>
  void UpdateThreatsForPiece(const BoardState& state,
                             PieceType piece_type,
                             Color piece_color,
                             Square square);
  void UpdateThreatsForMove(const BoardState& state,
                            const PsqtAccumulatorChange& change);

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
  static U8 SquareFlip(Color perspective, Square king_square) {
    return (0b111000 * perspective) | (0b111 * (king_square.File() >= kFileE));
  }

  static U8 PairFlip(Color perspective) {
    return threats::kThreatPairColorFlip * perspective;
  }

  static std::pair<Weight const*, bool> FeatureRow(U8 pair,
                                                   Square from,
                                                   Square to) {
    const auto feature = threats::GetThreatFeatureIndex(pair, from, to);
    const bool valid = feature < arch::kThreatFeatureCount;
    const auto row = valid ? arch::kPawnPairFeatureCount + feature : 0;
    return {network->threat_weights[row].as_array().data(), valid};
  }

  template <typename Emit>
  static void ForEachActiveFeature(const BoardState& state,
                                   Color perspective,
                                   Square king_square,
                                   Emit&& emit) {
    const auto occupied = state.Occupied();
    const auto targets = state.KinglessOccupied();
    const U8 square_flip = SquareFlip(perspective, king_square);
    const U8 pair_flip = PairFlip(perspective);
    for (int piece = PieceType::kPawn; piece <= PieceType::kQueen; ++piece) {
      for (Square from : state.piece_bbs[piece]) {
        const auto attacker_type = static_cast<PieceType>(piece);
        const auto attacker_color = state.GetPieceColor(from);
        const auto attacks = move_gen::GetPieceAttacks(
            from, attacker_type, attacker_color, occupied);
        for (const Square to : attacks& targets) {
          const auto pair = threats::PackThreatPair(attacker_type,
                                                    attacker_color,
                                                    state.GetPieceType(to),
                                                    state.GetPieceColor(to));
          const auto [threat_feature_row, valid] = FeatureRow(
              pair ^ pair_flip, from ^ square_flip, to ^ square_flip);
          __builtin_prefetch(threat_feature_row);
          emit(threat_feature_row, valid);
        }
      }
    }
    auto remaining = state.Pawns();
    for (const Square first : state.Pawns()) {
      remaining &= ~BitBoard::FromSquare(first);
      const auto first_id = pawn_pair::GetPawnId(
          first ^ square_flip, state.GetPieceColor(first), perspective);
      for (const Square second :
           remaining& pawn_pair::kAdjacentFileMasks[first]) {
        const auto second_id = pawn_pair::GetPawnId(
            second ^ square_flip, state.GetPieceColor(second), perspective);
        const auto index = pawn_pair::GetPawnIndex(first_id, second_id);
        const auto* row = network->threat_weights[index].as_array().data();
        __builtin_prefetch(row);
        emit(row, true);
      }
    }
  }

  static Weight const* PawnPairRow(Color perspective,
                                   Square king_square,
                                   Square first,
                                   Color first_color,
                                   Square second,
                                   Color second_color);
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
