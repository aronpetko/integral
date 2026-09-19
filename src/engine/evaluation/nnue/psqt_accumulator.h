#ifndef INTEGRAL_PSQT_ACCUMULATOR_H
#define INTEGRAL_PSQT_ACCUMULATOR_H

#include "perspective_accumulator.h"

namespace nnue {

struct PsqtAccumulatorChange {
  FeatureData sub_0, add_0, sub_1, add_1;
  enum Type {
    kNormal,
    kCapture,
    kCastle
  } type;

  // The squares this move changed the occupant of, which is all the threat
  // features need to be brought up to date. sub_1 covers both the captured
  // piece (including the en passant pawn) and the castling rook's origin.
  [[nodiscard]] BitBoard UpdatedSquares() const {
    auto squares =
        BitBoard::FromSquare(sub_0.square) | BitBoard::FromSquare(add_0.square);
    if (type != kNormal) {
      squares |= BitBoard::FromSquare(sub_1.square);
      if (type == kCastle) {
        squares |= BitBoard::FromSquare(add_1.square);
      }
    }
    return squares;
  }
};

struct PsqtFeaturePolicy {
  static constexpr int kWidth = arch::kL1Size;
  using Value = I16;
  using Weight = I16;

  static Value Bias(int i) {
    return network->feature_biases[i];
  }

  static std::span<Weight, kWidth> FeatureRow(Square square,
                                              Square king_square,
                                              PieceType piece,
                                              Color piece_color,
                                              Color perspective);

  template <typename Emit>
  static void ForEachActiveFeature(const BoardState& state,
                                   Color perspective,
                                   Square king_square,
                                   Emit&& emit) {
    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
      for (Square square : state.piece_bbs[piece]) {
        const Color piece_color = state.GetPieceColor(square);
        emit(FeatureRow(square,
                        king_square,
                        static_cast<PieceType>(piece),
                        piece_color,
                        perspective)
                 .data());
      }
    }
  }
};

class PsqtPerspectiveAccumulator
    : public PerspectiveAccumulator<PsqtFeaturePolicy> {
 public:
  Weight const* GetFeaturePointer(Square square,
                                  Square king_square,
                                  PieceType piece,
                                  Color piece_color,
                                  Color perspective);

  template <FusedOperation... ops,
            typename... Ts,
            std::enable_if_t<is_all_same_v<FeatureData, Ts...>, bool> = true,
            std::enable_if_t<sizeof...(ops) == sizeof...(Ts), bool> = true>
  void ApplyChange(Color perspective,
                   Square king_square,
                   const Ts&... accumulator_changes) {
    ApplyChange<ops...>(
        *this, perspective, king_square, accumulator_changes...);
  }

  template <FusedOperation... ops,
            typename... Ts,
            std::enable_if_t<is_all_same_v<FeatureData, Ts...>, bool> = true,
            std::enable_if_t<sizeof...(ops) == sizeof...(Ts), bool> = true>
  void ApplyChange(const PsqtPerspectiveAccumulator& previous,
                   Color perspective,
                   Square king_square,
                   const Ts&... accumulator_changes) {
    auto FeatureTable = [&](const FeatureData& feature) {
      return GetFeaturePointer(feature.square,
                               king_square,
                               feature.piece,
                               feature.color,
                               perspective);
    };
    const std::tuple changes = {FeatureTable(accumulator_changes)...};
    for (int i = 0; i < kWidth; ++i) {
      values_[i] = std::apply(
          [&](const auto&... changes) {
            return Fused<ops...>(previous[i], changes[i]...);
          },
          changes);
    }
  }

  void ApplyChange(const PsqtPerspectiveAccumulator& previous,
                   const PsqtAccumulatorChange& change,
                   Color perspective,
                   Square king_square);
};

}  // namespace nnue

#endif
