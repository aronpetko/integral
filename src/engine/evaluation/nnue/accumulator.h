#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "../../../chess/board.h"
#include "arch.h"
#include "nnue.h"

namespace nnue {

constexpr U8 kBucketDivisor =
    (32 + arch::kOutputBucketCount - 1) / arch::kOutputBucketCount;

static std::array<I16, arch::kHiddenLayerSize>& GetFeatureTable(
    Square square,
    Square king_square,
    PieceType piece,
    Color piece_color,
    Color perspective) {
  if (king_square.File() >= kFileE) {
    square = square ^ 0b111;
  }

  const int color_idx = static_cast<int>(perspective != piece_color);
  const int piece_idx = static_cast<int>(piece);
  const int square_idx = static_cast<int>(square ^ (56 * perspective));
  return network.feature_weights[color_idx][piece_idx][square_idx];
}

class PerspectiveAccumulator {
 public:
  PerspectiveAccumulator() : values_({}) {}

  void Refresh(const BoardState& state, Color perspective) {
    // Initialize the accumulator values with the network biases
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] = network.feature_biases[i];
    }

    const Square king_square = state.King(perspective).GetLsb();

    // Add each piece's features
    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
      for (Square square : state.piece_bbs[piece]) {
        AddFeature(*this,
                   perspective,
                   king_square,
                   square,
                   static_cast<PieceType>(piece),
                   state.GetPieceColor(square));
      }
    }
  }

  // Update features by adding a single feature
  void AddFeature(const PerspectiveAccumulator& previous,
                  Color perspective,
                  Square king_square,
                  Square square,
                  PieceType piece,
                  Color piece_color) {
    const auto& table =
        GetFeatureTable(square, king_square, piece, piece_color, perspective);
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] = previous[i] + table[i];
    }
  }

  // Update features by adding one feature and subtracting another
  void AddSubFeatures(const PerspectiveAccumulator& previous,
                      Color perspective,
                      Square king_square,
                      Square add_square,
                      PieceType add_piece,
                      Color add_piece_color,
                      Square sub_square,
                      PieceType sub_piece,
                      Color sub_piece_color) {
    const auto& add_table = GetFeatureTable(
        add_square, king_square, add_piece, add_piece_color, perspective);
    const auto& sub_table = GetFeatureTable(
        sub_square, king_square, sub_piece, sub_piece_color, perspective);
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] = previous[i] + add_table[i] - sub_table[i];
    }
  }

  // Update features by adding two features and subtracting two features
  void AddAddSubSubFeatures(const PerspectiveAccumulator& previous,
                            Color perspective,
                            Square king_square,
                            Square add_square1,
                            PieceType add_piece1,
                            Color add_piece_color1,
                            Square add_square2,
                            PieceType add_piece2,
                            Color add_piece_color2,
                            Square sub_square1,
                            PieceType sub_piece1,
                            Color sub_piece_color1,
                            Square sub_square2,
                            PieceType sub_piece2,
                            Color sub_piece_color2) {
    const auto& add_table1 = GetFeatureTable(
        add_square1, king_square, add_piece1, add_piece_color1, perspective);
    const auto& add_table2 = GetFeatureTable(
        add_square2, king_square, add_piece2, add_piece_color2, perspective);
    const auto& sub_table1 = GetFeatureTable(
        sub_square1, king_square, sub_piece1, sub_piece_color1, perspective);
    const auto& sub_table2 = GetFeatureTable(
        sub_square2, king_square, sub_piece2, sub_piece_color2, perspective);
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] = previous[i] + add_table1[i] + add_table2[i] - sub_table1[i] -
                   sub_table2[i];
    }
  }

  // Update features by adding one feature and subtracting two features
  void AddSubSubFeatures(const PerspectiveAccumulator& previous,
                         Color perspective,
                         Square king_square,
                         Square add_square,
                         PieceType add_piece,
                         Color add_piece_color,
                         Square sub_square1,
                         PieceType sub_piece1,
                         Color sub_piece_color1,
                         Square sub_square2,
                         PieceType sub_piece2,
                         Color sub_piece_color2) {
    const auto& add_table = GetFeatureTable(
        add_square, king_square, add_piece, add_piece_color, perspective);
    const auto& sub_table1 = GetFeatureTable(
        sub_square1, king_square, sub_piece1, sub_piece_color1, perspective);
    const auto& sub_table2 = GetFeatureTable(
        sub_square2, king_square, sub_piece2, sub_piece_color2, perspective);
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] = previous[i] + add_table[i] - sub_table1[i] - sub_table2[i];
    }
  }

  I16& operator[](int idx) {
    return values_[idx];
  }

  const I16& operator[](int idx) const {
    return values_[idx];
  }

 private:
  alignas(64) std::array<I16, arch::kHiddenLayerSize> values_;
};

class Accumulator {
 public:
  Accumulator() : head_idx_(0) {
    stack_.resize(2048);
  }

  void SetFromState(const BoardState& state) {
    // Refresh both sides' accumulator
    head_idx_ = 0;
    for (const Color color : {Color::kBlack, Color::kWhite}) {
      stack_[head_idx_][color].Refresh(state, color);
    }
  }

  void Refresh(const BoardState& state, Color perspective) {
    stack_[head_idx_][perspective].Refresh(state, perspective);
  }

  void FullRefresh(const BoardState& state) {
    ++head_idx_;
    stack_[head_idx_][Color::kWhite].Refresh(state, Color::kWhite);
    stack_[head_idx_][Color::kBlack].Refresh(state, Color::kBlack);
  }

  [[nodiscard]] bool ShouldRefresh(const BoardState& state, Move move) const {
    const auto from = move.GetFrom();
    const auto to = move.GetTo();
    const auto moving_piece = state.GetPieceType(from);

    if (moving_piece == PieceType::kKing) {
      // Refresh the perspective's accumulator if the king crosses to the other
      // half of the board
      return (from.File() >= kFileE) != (to.File() >= kFileE);
    }

    return false;
  }

  void MakeMove(const BoardState& state, Color perspective, Move move) {
    // Don't make any changes in a null move
    if (!move) {
      return;
    }

    // Move forward the head accumulator
    if (++head_idx_ == stack_.size()) {
      stack_.emplace_back();
    }

    const auto& prev_head = stack_[head_idx_ - 1];
    const auto from = move.GetFrom();
    const auto to = move.GetTo();
    const auto type = move.GetType();
    const auto moving_piece = state.GetPieceType(from);
    const auto captured_piece = state.GetPieceType(to);
    const auto moving_color = state.GetPieceColor(from);
    const auto opponent_color =
        move.IsCapture(state) ? FlipColor(moving_color) : Color::kNoColor;

    const Square king_square = state.King(perspective).GetLsb();
    switch (type) {
      case MoveType::kPromotion: {
        auto promotion_piece = static_cast<PieceType>(
            static_cast<int>(move.GetPromotionType()) + 1);
        if (captured_piece != PieceType::kNone) {
          // Promotion with capture
          stack_[head_idx_][perspective].AddSubSubFeatures(
              prev_head[perspective],
              perspective,
              king_square,
              to,
              promotion_piece,
              moving_color,
              from,
              moving_piece,
              moving_color,
              to,
              captured_piece,
              opponent_color);
        } else {
          // Promotion without capture
          stack_[head_idx_][perspective].AddSubFeatures(prev_head[perspective],
                                                        perspective,
                                                        king_square,
                                                        to,
                                                        promotion_piece,
                                                        moving_color,
                                                        from,
                                                        moving_piece,
                                                        moving_color);
        }
        break;
      }
      case MoveType::kCastle: {
        const Square rook_from = to > from ? Square(to + 1) : Square(to - 2);
        const Square rook_to = to > from ? Square(to - 1) : Square(to + 1);
        stack_[head_idx_][perspective].AddAddSubSubFeatures(
            prev_head[perspective],
            perspective,
            king_square,
            to,
            PieceType::kKing,
            moving_color,
            rook_to,
            PieceType::kRook,
            moving_color,
            from,
            PieceType::kKing,
            moving_color,
            rook_from,
            PieceType::kRook,
            moving_color);
        break;
      }
      case MoveType::kEnPassant: {
        const Square captured_pawn =
            Square(to - (moving_color == Color::kWhite ? 8 : -8));
        stack_[head_idx_][perspective].AddSubSubFeatures(prev_head[perspective],
                                                         perspective,
                                                         king_square,
                                                         to,
                                                         PieceType::kPawn,
                                                         moving_color,
                                                         from,
                                                         moving_piece,
                                                         moving_color,
                                                         captured_pawn,
                                                         PieceType::kPawn,
                                                         opponent_color);
        break;
      }
      case MoveType::kNormal: {
        if (captured_piece != PieceType::kNone) {
          stack_[head_idx_][perspective].AddSubSubFeatures(
              prev_head[perspective],
              perspective,
              king_square,
              to,
              moving_piece,
              moving_color,
              from,
              moving_piece,
              moving_color,
              to,
              captured_piece,
              opponent_color);
        } else {
          stack_[head_idx_][perspective].AddSubFeatures(prev_head[perspective],
                                                        perspective,
                                                        king_square,
                                                        to,
                                                        moving_piece,
                                                        moving_color,
                                                        from,
                                                        moving_piece,
                                                        moving_color);
        }
        break;
      }
      default:
        break;
    }
  }

  void MakeMove(const BoardState& state, Move move) {
    // Don't make any changes in a null move
    if (!move) {
      return;
    }

    // Move forward the head accumulator
    if (++head_idx_ == stack_.size()) {
      stack_.emplace_back();
    }

    const auto& prev_head = stack_[head_idx_ - 1];
    const auto from = move.GetFrom();
    const auto to = move.GetTo();
    const auto type = move.GetType();
    const auto moving_piece = state.GetPieceType(from);
    const auto captured_piece = state.GetPieceType(to);
    const auto moving_color = state.GetPieceColor(from);
    const auto opponent_color =
        move.IsCapture(state) ? FlipColor(moving_color) : Color::kNoColor;

    for (const Color perspective : {Color::kWhite, Color::kBlack}) {
      const Square king_square = state.King(perspective).GetLsb();
      switch (type) {
        case MoveType::kPromotion: {
          auto promotion_piece = static_cast<PieceType>(
              static_cast<int>(move.GetPromotionType()) + 1);
          if (captured_piece != PieceType::kNone) {
            // Promotion with capture
            stack_[head_idx_][perspective].AddSubSubFeatures(
                prev_head[perspective],
                perspective,
                king_square,
                to,
                promotion_piece,
                moving_color,
                from,
                moving_piece,
                moving_color,
                to,
                captured_piece,
                opponent_color);
          } else {
            // Promotion without capture
            stack_[head_idx_][perspective].AddSubFeatures(
                prev_head[perspective],
                perspective,
                king_square,
                to,
                promotion_piece,
                moving_color,
                from,
                moving_piece,
                moving_color);
          }
          break;
        }
        case MoveType::kCastle: {
          const Square rook_from = to > from ? Square(to + 1) : Square(to - 2);
          const Square rook_to = to > from ? Square(to - 1) : Square(to + 1);
          stack_[head_idx_][perspective].AddAddSubSubFeatures(
              prev_head[perspective],
              perspective,
              king_square,
              to,
              PieceType::kKing,
              moving_color,
              rook_to,
              PieceType::kRook,
              moving_color,
              from,
              PieceType::kKing,
              moving_color,
              rook_from,
              PieceType::kRook,
              moving_color);
          break;
        }
        case MoveType::kEnPassant: {
          const Square captured_pawn =
              Square(to - (moving_color == Color::kWhite ? 8 : -8));
          stack_[head_idx_][perspective].AddSubSubFeatures(
              prev_head[perspective],
              perspective,
              king_square,
              to,
              PieceType::kPawn,
              moving_color,
              from,
              moving_piece,
              moving_color,
              captured_pawn,
              PieceType::kPawn,
              opponent_color);
          break;
        }
        case MoveType::kNormal: {
          if (captured_piece != PieceType::kNone) {
            stack_[head_idx_][perspective].AddSubSubFeatures(
                prev_head[perspective],
                perspective,
                king_square,
                to,
                moving_piece,
                moving_color,
                from,
                moving_piece,
                moving_color,
                to,
                captured_piece,
                opponent_color);
          } else {
            stack_[head_idx_][perspective].AddSubFeatures(
                prev_head[perspective],
                perspective,
                king_square,
                to,
                moving_piece,
                moving_color,
                from,
                moving_piece,
                moving_color);
          }
          break;
        }
        default:
          break;
      }
    }
  }

  void UndoMove() {
    --head_idx_;
  }

  [[nodiscard]] int GetOutputBucket(const BoardState& state) {
    return std::min((state.Occupied().PopCount() - 2) / kBucketDivisor,
                    static_cast<int>(arch::kOutputBucketCount - 1));
  }

  PerspectiveAccumulator& operator[](int perspective) {
    return stack_[head_idx_][perspective];
  }

  const PerspectiveAccumulator& operator[](int perspective) const {
    return stack_[head_idx_][perspective];
  }

 private:
  int head_idx_;
  std::vector<std::array<PerspectiveAccumulator, 2>> stack_;
};

}  // namespace nnue

#endif
