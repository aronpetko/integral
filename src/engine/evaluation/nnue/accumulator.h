#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "../../../chess/board.h"
#include "arch.h"
#include "nnue.h"

namespace nnue {

class Accumulator {
 public:
  void SetFromState(const BoardState& state) {
    for (int perspective = Color::kWhite; perspective <= Color::kBlack;
         perspective++) {
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        // Initialize with feature biases
        accumulator_[perspective][i] = network.feature_biases[i];
      }
    }

    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; piece++) {
      for (Square square : state.piece_bbs[piece]) {
        const auto piece_color = state.GetPieceColor(square);
        UpdateFeatures(square, piece, piece_color, 1);
      }
    }
  }

  void MakeMove(const BoardState& state, Move move) {
    accumulators_.Push(accumulator_);

    turn_ = FlipColor(state.turn);
    // Account for null moves
    if (!move) {
      return;
    }

    const auto from = move.GetFrom();
    const auto to = move.GetTo();
    const auto type = move.GetType();
    const auto moving_piece = state.GetPieceType(from);
    const auto captured_piece = state.GetPieceType(to);

    // Remove the moving piece from its original square
    UpdateFeatures(from, moving_piece, state.turn, -1);

    switch (type) {
      case MoveType::kPromotion: {
        // Add the promoted piece
        UpdateFeatures(to,
                       PieceType(static_cast<int>(move.GetPromotionType()) + 1),
                       state.turn,
                       1);
        break;
      }
      case MoveType::kCastle: {
        // Move the king
        UpdateFeatures(to, PieceType::kKing, state.turn, 1);
        // Move the rook
        const Square rook_from = to > from ? Square(to + 1) : Square(to - 2);
        const Square rook_to = to > from ? Square(to - 1) : Square(to + 1);
        UpdateFeatures(rook_from, PieceType::kRook, state.turn, -1);
        UpdateFeatures(rook_to, PieceType::kRook, state.turn, 1);
        break;
      }
      case MoveType::kEnPassant: {
        // Add the moving pawn
        UpdateFeatures(to, PieceType::kPawn, state.turn, 1);
        // Remove the captured pawn
        const Square captured_pawn =
            Square(to - (state.turn == Color::kWhite ? 8 : -8));
        UpdateFeatures(
            captured_pawn, PieceType::kPawn, FlipColor(state.turn), -1);
        break;
      }
      case MoveType::kNormal: {
        // Add the moving piece to its new square
        UpdateFeatures(to, moving_piece, state.turn, 1);
        // Remove the captured piece, if any
        if (captured_piece != PieceType::kNone) {
          UpdateFeatures(to, captured_piece, FlipColor(state.turn), -1);
        }
        break;
      }
      default:
        throw std::runtime_error("unknown move type in MakeMove");
    }
  }

  void UndoMove() {
    if (accumulators_.Empty()) {
      throw std::runtime_error(
          "attempt to undo move with empty accumulator stack");
    }
    accumulator_ = accumulators_.PopBack();
  }

  [[nodiscard]] Color GetTurn() const {
    return turn_;
  }

  MultiArray<I32, arch::kHiddenLayerSize>& operator[](int perspective) {
    return accumulator_[perspective];
  }

  const MultiArray<I32, arch::kHiddenLayerSize>& operator[](
      int perspective) const {
    return accumulator_[perspective];
  }

 private:
  void UpdateFeatures(Square square, int piece, int piece_color, int delta) {
    for (int perspective = Color::kWhite; perspective <= Color::kBlack;
         perspective++) {
      const int index =
          GetFeatureIndex(square, piece, piece_color, perspective);
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        accumulator_[perspective][i] +=
            delta * network.feature_weights[index][i];
      }
    }
  }

  I32 GetFeatureIndex(Square square,
                      int piece,
                      int piece_color,
                      int perspective) const {
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
  Color turn_;
  MultiArray<I32, 2, arch::kHiddenLayerSize> accumulator_;
  List<MultiArray<I32, 2, arch::kHiddenLayerSize>, kMaxPlyFromRoot>
      accumulators_;
};

}  // namespace nnue

#endif  // INTEGRAL_ACCUMULATOR_H