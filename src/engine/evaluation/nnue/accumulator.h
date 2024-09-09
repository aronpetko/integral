#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "../../../chess/board.h"
#include "arch.h"
#include "nnue.h"

namespace nnue {

class Accumulator {
  static constexpr U8 kBucketDivisor =
      (32 + arch::kOutputBucketCount - 1) / arch::kOutputBucketCount;

 public:
  void SetFromState(const BoardState& state) {
    accumulators_.clear();
    accumulators_.shrink_to_fit();
    accumulators_.reserve(kMaxGamePly);
    accumulator_.num_pieces = 0;

    for (int perspective = Color::kWhite; perspective <= Color::kBlack;
         perspective++) {
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        accumulator_.active[perspective][i] = network.feature_biases[i];
      }
    }

    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; piece++) {
      for (Square square : state.piece_bbs[piece]) {
        const auto piece_color = state.GetPieceColor(square);
        AddFeatures(square, piece, piece_color);
      }
    }
  }

  void MakeMove(const BoardState& state, Move move) {
    accumulators_.push_back(accumulator_);

    turn_ = FlipColor(state.turn);
    if (!move) return;

    const auto from = move.GetFrom();
    const auto to = move.GetTo();
    const auto type = move.GetType();
    const auto moving_piece = state.GetPieceType(from);
    const auto captured_piece = state.GetPieceType(to);

    switch (type) {
      case MoveType::kPromotion: {
        auto promotion_piece = static_cast<PieceType>(
            static_cast<int>(move.GetPromotionType()) + 1);
        if (captured_piece != PieceType::kNone) {
          AddSubSubFeatures(to,
                            promotion_piece,
                            state.turn,
                            from,
                            moving_piece,
                            state.turn,
                            to,
                            captured_piece,
                            FlipColor(state.turn));
        } else {
          AddSubFeatures(
              to, promotion_piece, state.turn, from, moving_piece, state.turn);
        }
        break;
      }
      case MoveType::kCastle: {
        const Square rook_from = to > from ? Square(to + 1) : Square(to - 2);
        const Square rook_to = to > from ? Square(to - 1) : Square(to + 1);
        AddSubSubSubFeatures(to,
                             PieceType::kKing,
                             state.turn,
                             rook_to,
                             PieceType::kRook,
                             state.turn,
                             from,
                             PieceType::kKing,
                             state.turn,
                             rook_from,
                             PieceType::kRook,
                             state.turn);
        break;
      }
      case MoveType::kEnPassant: {
        const Square captured_pawn =
            Square(to - (state.turn == Color::kWhite ? 8 : -8));
        AddSubSubFeatures(to,
                          PieceType::kPawn,
                          state.turn,
                          from,
                          moving_piece,
                          state.turn,
                          captured_pawn,
                          PieceType::kPawn,
                          FlipColor(state.turn));
        break;
      }
      case MoveType::kNormal:
        if (captured_piece != PieceType::kNone) {
          AddSubSubFeatures(to,
                            moving_piece,
                            state.turn,
                            from,
                            moving_piece,
                            state.turn,
                            to,
                            captured_piece,
                            FlipColor(state.turn));
        } else {
          AddSubFeatures(
              to, moving_piece, state.turn, from, moving_piece, state.turn);
        }
        break;
      default:
        throw std::runtime_error("unknown move type in MakeMove");
    }
  }

  void UndoMove() {
    if (accumulators_.empty()) {
      throw std::runtime_error(
          "attempt to undo move with empty accumulator stack");
    }
    accumulator_ = accumulators_.back();
    accumulators_.pop_back();
  }

  [[nodiscard]] Color GetTurn() const {
    return turn_;
  }

  [[nodiscard]] int GetOutputBucket() const {
    return std::min((accumulator_.num_pieces - 2) / kBucketDivisor,
                    static_cast<int>(arch::kOutputBucketCount - 1));
  }

  MultiArray<I16, arch::kHiddenLayerSize>& operator[](int perspective) {
    return accumulator_.active[perspective];
  }

  const MultiArray<I16, arch::kHiddenLayerSize>& operator[](
      int perspective) const {
    return accumulator_.active[perspective];
  }

 private:
  void AddFeatures(Square square, int piece, int piece_color) {
    for (int perspective = Color::kWhite; perspective <= Color::kBlack;
         perspective++) {
      const int index =
          GetFeatureIndex(square, piece, piece_color, perspective);
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        accumulator_.active[perspective][i] +=
            network.feature_weights[index][i];
      }
    }
    accumulator_.num_pieces++;
  }

  void AddSubFeatures(Square add_square,
                      int add_piece,
                      int add_color,
                      Square sub_square,
                      int sub_piece,
                      int sub_color) {
    for (int perspective = Color::kWhite; perspective <= Color::kBlack;
         perspective++) {
      const int add_index =
          GetFeatureIndex(add_square, add_piece, add_color, perspective);
      const int sub_index =
          GetFeatureIndex(sub_square, sub_piece, sub_color, perspective);
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        accumulator_.active[perspective][i] +=
            network.feature_weights[add_index][i] -
            network.feature_weights[sub_index][i];
      }
    }
  }

  void AddSubSubFeatures(Square add_square,
                         int add_piece,
                         int add_color,
                         Square sub1_square,
                         int sub1_piece,
                         int sub1_color,
                         Square sub2_square,
                         int sub2_piece,
                         int sub2_color) {
    for (int perspective = Color::kWhite; perspective <= Color::kBlack;
         perspective++) {
      const int add_index =
          GetFeatureIndex(add_square, add_piece, add_color, perspective);
      const int sub1_index =
          GetFeatureIndex(sub1_square, sub1_piece, sub1_color, perspective);
      const int sub2_index =
          GetFeatureIndex(sub2_square, sub2_piece, sub2_color, perspective);
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        accumulator_.active[perspective][i] +=
            network.feature_weights[add_index][i] -
            network.feature_weights[sub1_index][i] -
            network.feature_weights[sub2_index][i];
      }
    }
    accumulator_.num_pieces--;
  }

  void AddSubSubSubFeatures(Square add1_square,
                            int add1_piece,
                            int add1_color,
                            Square add2_square,
                            int add2_piece,
                            int add2_color,
                            Square sub1_square,
                            int sub1_piece,
                            int sub1_color,
                            Square sub2_square,
                            int sub2_piece,
                            int sub2_color) {
    for (int perspective = Color::kWhite; perspective <= Color::kBlack;
         perspective++) {
      const int add1_index =
          GetFeatureIndex(add1_square, add1_piece, add1_color, perspective);
      const int add2_index =
          GetFeatureIndex(add2_square, add2_piece, add2_color, perspective);
      const int sub1_index =
          GetFeatureIndex(sub1_square, sub1_piece, sub1_color, perspective);
      const int sub2_index =
          GetFeatureIndex(sub2_square, sub2_piece, sub2_color, perspective);
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        accumulator_.active[perspective][i] +=
            network.feature_weights[add1_index][i] +
            network.feature_weights[add2_index][i] -
            network.feature_weights[sub1_index][i] -
            network.feature_weights[sub2_index][i];
      }
    }
  }

  I16 GetFeatureIndex(Square square,
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
  using AccumulatorContainer = MultiArray<I16, 2, arch::kHiddenLayerSize>;

  struct AccumulatorEntry {
    int num_pieces;
    alignas(64) AccumulatorContainer active;
  };

 private:
  Color turn_;
  AccumulatorEntry accumulator_;
  std::vector<AccumulatorEntry> accumulators_;
};

}  // namespace nnue

#endif  // INTEGRAL_ACCUMULATOR_H