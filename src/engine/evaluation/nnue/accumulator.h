#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "../../../chess/board.h"
#include "arch.h"
#include "nnue.h"

namespace nnue {

static I16 GetFeatureIndex(
    Square square, int piece, int piece_color, Color perspective, bool flip) {
  if (flip) {
    square = square ^ 0b111;
  }

  constexpr int kColorStride =
      Squares::kSquareCount * PieceType::kNumPieceTypes;
  constexpr int kPieceStride = Squares::kSquareCount;
  if (perspective == Color::kWhite) {
    return piece_color * kColorStride + piece * kPieceStride + square;
  } else {
    return !piece_color * kColorStride + piece * kPieceStride + (square ^ 56);
  }
}

class PerspectiveAccumulator {
 public:
  void Refresh(const BoardState& state, Color perspective) {
    num_pieces_ = 0;
    for (int i = 0; i < arch::kHiddenLayerSize; i++) {
      active_[i] = network.feature_biases[i];
    }

    const Square king_square = state.King(perspective).GetLsb();
    const bool flip = king_square.File() >= kFileE;

    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; piece++) {
      for (Square square : state.piece_bbs[piece]) {
        const auto piece_color = state.GetPieceColor(square);
        AddFeatures(square, piece, piece_color, perspective, flip);
      }
    }

    needs_refresh_ = false;
  }

  [[nodiscard]] bool NeedsRefresh() const {
    return needs_refresh_;
  }
  void SetNeedsRefresh(bool value) {
    needs_refresh_ = value;
  }

  std::array<I16, arch::kHiddenLayerSize>& GetActive() {
    return active_;
  }
  const std::array<I16, arch::kHiddenLayerSize>& GetActive() const {
    return active_;
  }

  int& GetNumPieces() {
    return num_pieces_;
  }

 private:
  void AddFeatures(
      Square square, int piece, int piece_color, Color perspective, bool flip) {
    const int index =
        GetFeatureIndex(square, piece, piece_color, perspective, flip);
    for (int i = 0; i < arch::kHiddenLayerSize; i++) {
      active_[i] += network.feature_weights[index][i];
    }
    num_pieces_++;
  }

  alignas(64) std::array<I16, arch::kHiddenLayerSize> active_;
  int num_pieces_ = 0;
  bool needs_refresh_ = true;
};

class Accumulator {
  static constexpr U8 kBucketDivisor =
      (32 + arch::kOutputBucketCount - 1) / arch::kOutputBucketCount;

 public:
  Accumulator() {
    accumulators_.clear();
    accumulators_.shrink_to_fit();
    accumulators_.reserve(kMaxGamePly);
  }

  void SetFromState(const BoardState& state) {
    accumulator_.accumulators[Color::kWhite].Refresh(state, Color::kWhite);
    accumulator_.accumulators[Color::kBlack].Refresh(state, Color::kBlack);
  }

  void Refresh(const BoardState& state, Color perspective) {
    accumulators_.push_back(accumulator_);
    accumulator_.accumulators[perspective].Refresh(state, perspective);
  }

  void MakeMove(const BoardState& state, Move move) {
    accumulators_.push_back(accumulator_);

    if (!move) return;

    const auto from = move.GetFrom();
    const auto to = move.GetTo();
    const auto type = move.GetType();
    const auto moving_piece = state.GetPieceType(from);
    const auto captured_piece = state.GetPieceType(to);
    const Square king_square = state.King(state.turn).GetLsb();
    const bool flip = king_square.File() >= kFileE;

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
                            FlipColor(state.turn),
                            flip);
        } else {
          AddSubFeatures(to,
                         promotion_piece,
                         state.turn,
                         from,
                         moving_piece,
                         state.turn,
                         flip);
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
                             state.turn,
                             flip);
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
                          FlipColor(state.turn),
                          flip);
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
                            FlipColor(state.turn),
                            flip);
        } else {
          AddSubFeatures(to,
                         moving_piece,
                         state.turn,
                         from,
                         moving_piece,
                         state.turn,
                         flip);
        }
        break;
      default:
        break;
    }
  }

  void UndoMove() {
    accumulator_ = accumulators_.back();
    accumulators_.pop_back();
  }

  [[nodiscard]] int GetOutputBucket() {
    return std::min(
        (accumulator_.accumulators[Color::kWhite].GetNumPieces() - 2) /
            kBucketDivisor,
        static_cast<int>(arch::kOutputBucketCount - 1));
  }

  std::array<I16, arch::kHiddenLayerSize>& operator[](int perspective) {
    return accumulator_.accumulators[perspective].GetActive();
  }

  const std::array<I16, arch::kHiddenLayerSize>& operator[](
      int perspective) const {
    return accumulator_.accumulators[perspective].GetActive();
  }

 private:
  void AddSubFeatures(Square add_square,
                      int add_piece,
                      int add_color,
                      Square sub_square,
                      int sub_piece,
                      int sub_color,
                      bool flip) {
    for (Color perspective : {Color::kWhite, Color::kBlack}) {
      const int add_index =
          GetFeatureIndex(add_square, add_piece, add_color, perspective, flip);
      const int sub_index =
          GetFeatureIndex(sub_square, sub_piece, sub_color, perspective, flip);
      auto& active = accumulator_.accumulators[perspective].GetActive();
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        active[i] += network.feature_weights[add_index][i] -
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
                         int sub2_color,
                         bool flip) {
    for (Color perspective : {Color::kWhite, Color::kBlack}) {
      const int add_index =
          GetFeatureIndex(add_square, add_piece, add_color, perspective, flip);
      const int sub1_index = GetFeatureIndex(
          sub1_square, sub1_piece, sub1_color, perspective, flip);
      const int sub2_index = GetFeatureIndex(
          sub2_square, sub2_piece, sub2_color, perspective, flip);
      auto& active = accumulator_.accumulators[perspective].GetActive();
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        active[i] += network.feature_weights[add_index][i] -
                     network.feature_weights[sub1_index][i] -
                     network.feature_weights[sub2_index][i];
      }
    }
    accumulator_.accumulators[Color::kWhite].GetNumPieces()--;
    accumulator_.accumulators[Color::kBlack].GetNumPieces()--;
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
                            int sub2_color,
                            bool flip) {
    for (Color perspective : {Color::kWhite, Color::kBlack}) {
      const int add1_index = GetFeatureIndex(
          add1_square, add1_piece, add1_color, perspective, flip);
      const int add2_index = GetFeatureIndex(
          add2_square, add2_piece, add2_color, perspective, flip);
      const int sub1_index = GetFeatureIndex(
          sub1_square, sub1_piece, sub1_color, perspective, flip);
      const int sub2_index = GetFeatureIndex(
          sub2_square, sub2_piece, sub2_color, perspective, flip);
      auto& active = accumulator_.accumulators[perspective].GetActive();
      for (int i = 0; i < arch::kHiddenLayerSize; i++) {
        active[i] += network.feature_weights[add1_index][i] +
                     network.feature_weights[add2_index][i] -
                     network.feature_weights[sub1_index][i] -
                     network.feature_weights[sub2_index][i];
      }
    }
  }

  struct AccumulatorEntry {
    std::array<PerspectiveAccumulator, 2> accumulators;
  };

  AccumulatorEntry accumulator_;
  std::vector<AccumulatorEntry> accumulators_;
};

}  // namespace nnue

#endif  // INTEGRAL_ACCUMULATOR_H