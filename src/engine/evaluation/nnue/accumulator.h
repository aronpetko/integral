#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "../../../chess/board.h"
#include "arch.h"
#include "nnue.h"

namespace nnue {

class Accumulator {
 public:
  void SetFromState(const BoardState &state) {
    for (int perspective = Color::kWhite; perspective <= Color::kBlack;
         perspective++) {
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        // Initialize with feature biases
        accumulator_[perspective][i] = network.feature_biases[i];
      }
    }

    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; piece++) {
      // Loop through all pieces that belong to this color
      for (Square square : state.piece_bbs[piece]) {
        const auto piece_color = state.GetPieceColor(square);
        for (int perspective = Color::kWhite; perspective <= Color::kBlack;
             perspective++) {
          // Update accumulator for the current perspective
          for (int i = 0; i < arch::kHiddenLayerSize; i++) {
            const int index =
                GetFeatureIndex(square, piece, piece_color, perspective);
            accumulator_[perspective][i] += network.feature_weights[index][i];
          }
        }
      }
    }
  }

  void MakeMove(const BoardState &state, Move move) {
    accumulators_.Push(accumulator_);

    auto &our_accumulator = accumulator_[state.turn];
    auto &their_accumulator = accumulator_[FlipColor(state.turn)];

    const auto from = move.GetFrom();
    const auto to = move.GetTo();
    const auto type = move.GetType();

    switch (type) {
      case MoveType::kPromotion: {
        for (int i = 0; i < arch::kHiddenLayerSize; i++) {
          const int from_index = GetFeatureIndex(
              from, state.GetPieceType(from), state.turn, state.turn);
          our_accumulator[i] -= network.feature_weights[from_index][i];
          const int to_index = GetFeatureIndex(
              from,
              PieceType(static_cast<int>(move.GetPromotionType()) + 1),
              state.turn,
              state.turn);
          our_accumulator[i] += network.feature_weights[to_index][i];
        }
        break;
      }
      case MoveType::kCastle: {
        break;
      }
      case MoveType::kEnPassant: {
        break;
      }
      case MoveType::kNormal: {
        break;
      }
    }
  }

  void UndoMove() {
    accumulator_ = accumulators_.PopBack();
  }

 private:
  I32 GetFeatureIndex(Square square,
                      int piece,
                      int piece_color,
                      int perspective) {
    constexpr int kColorStride =
        Squares::kSquareCount * PieceType::kNumPieceTypes;
    constexpr int kPieceStride = Squares::kSquareCount;
    if (perspective == Color::kWhite) {
      return piece_color * kColorStride + piece * kPieceStride + square;
    } else {
      return !piece_color * kColorStride + piece * kPieceStride + (square ^ 56);
    }
  }

 private:
  MultiArray<I32, 2, arch::kHiddenLayerSize> accumulator_;
  List<MultiArray<I32, 2, arch::kHiddenLayerSize>, 1024> accumulators_;
};

}  // namespace nnue

#endif  // INTEGRAL_ACCUMULATOR_H