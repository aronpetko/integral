#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "../../../chess/board.h"
#include "arch.h"
#include "nnue.h"

namespace nnue {

constexpr U8 kBucketDivisor =
    (32 + arch::kOutputBucketCount - 1) / arch::kOutputBucketCount;

// clang-format off
constexpr std::array<int, 64> kKingBucketMap {
  0, 0, 1, 1, 1, 1, 0, 0,
  2, 2, 2, 2, 2, 2, 2, 2,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
};
// clang-format on

struct FeatureData {
  Square square = Squares::kNoSquare;
  PieceType piece{};
  Color color{};
};

struct AccumulatorChange {
  FeatureData sub_0, add_0, sub_1, add_1;

  enum Type {
    kNormal,
    kCapture,
    kCastle,
    kPromotion,
    kEnPassant
  } type;
};

static std::array<I16, arch::kHiddenLayerSize>& GetFeatureTable(
    Square square,
    Square king_square,
    PieceType piece,
    Color piece_color,
    Color perspective) {
  if (king_square.File() >= kFileE) {
    square = square ^ 0b111;
  }

  const int relative_king_square = king_square ^ (56 * perspective);
  const int king_bucket_idx = kKingBucketMap[relative_king_square];
  const int square_idx = static_cast<int>(square ^ (56 * perspective));
  const int color_idx = static_cast<int>(perspective != piece_color);
  const int piece_idx = static_cast<int>(piece);

  return network
      ->feature_weights[king_bucket_idx][color_idx][piece_idx][square_idx];
}

class PerspectiveAccumulator {
 public:
  PerspectiveAccumulator() : values_({}) {}

  void Refresh(const BoardState& state, Color perspective) {
    // Initialize the accumulator values with the network biases
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] = network->feature_biases[i];
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

  void ApplyChange(const PerspectiveAccumulator& previous,
                   const AccumulatorChange& change,
                   Color perspective,
                   Square king_square) {
    switch (change.type) {
      case AccumulatorChange::kNormal:
        AddSubFeatures(previous,
                       perspective,
                       king_square,
                       change.add_0.square,
                       change.add_0.piece,
                       change.add_0.color,
                       change.sub_0.square,
                       change.sub_0.piece,
                       change.sub_0.color);
        break;
      case AccumulatorChange::kCapture:
        AddSubSubFeatures(previous,
                          perspective,
                          king_square,
                          change.add_0.square,
                          change.add_0.piece,
                          change.add_0.color,
                          change.sub_0.square,
                          change.sub_0.piece,
                          change.sub_0.color,
                          change.sub_1.square,
                          change.sub_1.piece,
                          change.sub_1.color);
        break;
      case AccumulatorChange::kCastle:
        AddAddSubSubFeatures(previous,
                             perspective,
                             king_square,
                             change.add_0.square,
                             change.add_0.piece,
                             change.add_0.color,
                             change.add_1.square,
                             change.add_1.piece,
                             change.add_1.color,
                             change.sub_0.square,
                             change.sub_0.piece,
                             change.sub_0.color,
                             change.sub_1.square,
                             change.sub_1.piece,
                             change.sub_1.color);
        break;
      case AccumulatorChange::kPromotion:
        if (change.sub_1.piece != PieceType::kNone) {
          // Promotion with capture
          AddSubSubFeatures(previous,
                            perspective,
                            king_square,
                            change.add_0.square,
                            change.add_0.piece,
                            change.add_0.color,
                            change.sub_0.square,
                            change.sub_0.piece,
                            change.sub_0.color,
                            change.sub_1.square,
                            change.sub_1.piece,
                            change.sub_1.color);
        } else {
          // Promotion without capture
          AddSubFeatures(previous,
                         perspective,
                         king_square,
                         change.add_0.square,
                         change.add_0.piece,
                         change.add_0.color,
                         change.sub_0.square,
                         change.sub_0.piece,
                         change.sub_0.color);
        }
        break;
      case AccumulatorChange::kEnPassant:
        AddSubSubFeatures(previous,
                          perspective,
                          king_square,
                          change.add_0.square,
                          change.add_0.piece,
                          change.add_0.color,
                          change.sub_0.square,
                          change.sub_0.piece,
                          change.sub_0.color,
                          change.sub_1.square,
                          change.sub_1.piece,
                          change.sub_1.color);
        break;
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

struct AccumulatorEntry {
  AccumulatorChange change;
  std::array<bool, 2> updated{};
  std::array<Square, 2> kings{};
  std::array<PerspectiveAccumulator, 2> perspectives;
};

class Accumulator {
 public:
  Accumulator() : head_idx_(0) {
    stack_.resize(2048);
  }

  void SetFromState(const BoardState& state) {
    head_idx_ = 0;
    for (const Color color : {Color::kBlack, Color::kWhite}) {
      Refresh(state, color);
    }
  }

  void Refresh(const BoardState& state, Color perspective) {
    stack_[head_idx_].perspectives[perspective].Refresh(state, perspective);
    stack_[head_idx_].kings[perspective] = state.King(perspective).GetLsb();
    stack_[head_idx_].updated[perspective] = true;
  }

  void PushChange(const BoardState& state, Move move) {
    IncrementHead();

    auto& entry = stack_[head_idx_];
    auto& change = entry.change;

    const auto from = move.GetFrom();
    const auto to = move.GetTo();
    const auto type = move.GetType();
    const auto moving_piece = state.GetPieceType(from);
    const auto captured_piece = state.GetPieceType(to);
    const auto moving_color = state.GetPieceColor(from);
    const auto opponent_color =
        move.IsCapture(state) ? FlipColor(moving_color) : Color::kNoColor;

    switch (type) {
      case MoveType::kPromotion: {
        auto promotion_piece = static_cast<PieceType>(
            static_cast<int>(move.GetPromotionType()) + 1);
        change.type = AccumulatorChange::kPromotion;
        change.add_0 = {to, promotion_piece, moving_color};
        change.sub_0 = {from, moving_piece, moving_color};
        if (captured_piece != PieceType::kNone) {
          change.sub_1 = {to, captured_piece, opponent_color};
        }
        break;
      }
      case MoveType::kCastle: {
        change.type = AccumulatorChange::kCastle;
        const Square rook_from = to > from ? Square(to + 1) : Square(to - 2);
        const Square rook_to = to > from ? Square(to - 1) : Square(to + 1);
        change.add_0 = {to, PieceType::kKing, moving_color};
        change.add_1 = {rook_to, PieceType::kRook, moving_color};
        change.sub_0 = {from, PieceType::kKing, moving_color};
        change.sub_1 = {rook_from, PieceType::kRook, moving_color};
        break;
      }
      case MoveType::kEnPassant: {
        change.type = AccumulatorChange::kEnPassant;
        const Square captured_pawn =
            Square(to - (moving_color == Color::kWhite ? 8 : -8));
        change.add_0 = {to, PieceType::kPawn, moving_color};
        change.sub_0 = {from, moving_piece, moving_color};
        change.sub_1 = {captured_pawn, PieceType::kPawn, opponent_color};
        break;
      }
      case MoveType::kNormal: {
        if (captured_piece != PieceType::kNone) {
          change.type = AccumulatorChange::kCapture;
          change.add_0 = {to, moving_piece, moving_color};
          change.sub_0 = {from, moving_piece, moving_color};
          change.sub_1 = {to, captured_piece, opponent_color};
        } else {
          change.type = AccumulatorChange::kNormal;
          change.add_0 = {to, moving_piece, moving_color};
          change.sub_0 = {from, moving_piece, moving_color};
        }
        break;
      }
      default:
        break;
    }
  }

  void UpdateKings(const BoardState &state) {
    auto& entry = stack_[head_idx_];
    // Update king positions and reset update flags
    for (Color perspective : {Color::kBlack, Color::kWhite}) {
      entry.kings[perspective] = state.King(perspective).GetLsb();
      entry.updated[perspective] = false;
    }
  }

  void ApplyChanges(const BoardState& state) {
    for (Color perspective : {Color::kWhite, Color::kBlack}) {
      if (stack_[head_idx_].updated[perspective]) {
        continue;
      }

      const Square king = stack_[head_idx_].kings[perspective];
      int iter = head_idx_;

      while (true) {
        --iter;

        // If the accumulator needs a refresh, we skip applying updates and just
        // refresh it
        if (NeedRefresh(perspective, stack_[iter].kings[perspective], king)) {
          Refresh(state, perspective);
          break;
        }

        // We've found the earliest updated accumulator
        if (stack_[iter].updated[perspective]) {
          int last_updated = iter;
          // Apply all updates from the earliest updated accumulator to now
          while (last_updated != head_idx_) {
            stack_[last_updated + 1].perspectives[perspective].ApplyChange(
                stack_[last_updated].perspectives[perspective],
                stack_[last_updated + 1].change,
                perspective,
                king);
            // Mark the accumulator as having been updated
            stack_[++last_updated].updated[perspective] = true;
          }
          break;
        }
      }
    }
  }

  [[nodiscard]] bool NeedRefresh(Color perspective,
                                 Square old_king,
                                 Square new_king) const {
    // Check if the king has moved to a different half of the board
    if ((old_king.File() >= kFileE) != (new_king.File() >= kFileE)) {
      return true;
    }

    // Check if the king has changed buckets
    return kKingBucketMap[old_king ^ (56 * perspective)] !=
           kKingBucketMap[new_king ^ (56 * perspective)];
  }

  void IncrementHead() {
    // Move forward the head accumulator
    if (++head_idx_ == stack_.size()) {
      stack_.emplace_back();
    }
  }

  void MakeMove(const BoardState& state, Color perspective, Move move) {
    // Don't make any changes in a null move
    if (!move) {
      return;
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
          stack_[head_idx_].perspectives[perspective].AddSubSubFeatures(
              prev_head.perspectives[perspective],
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
          stack_[head_idx_].perspectives[perspective].AddSubFeatures(
              prev_head.perspectives[perspective],
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
        stack_[head_idx_].perspectives[perspective].AddAddSubSubFeatures(
            prev_head.perspectives[perspective],
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
        stack_[head_idx_].perspectives[perspective].AddSubSubFeatures(
            prev_head.perspectives[perspective],
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
          stack_[head_idx_].perspectives[perspective].AddSubSubFeatures(
              prev_head.perspectives[perspective],
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
          stack_[head_idx_].perspectives[perspective].AddSubFeatures(
              prev_head.perspectives[perspective],
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

    for (const Color perspective : {Color::kWhite, Color::kBlack}) {
      MakeMove(state, perspective, move);
    }
  }

  void UndoMove() {
    --head_idx_;
  }

  [[nodiscard]] int GetOutputBucket(const BoardState& state) const {
    return std::min((state.Occupied().PopCount() - 2) / kBucketDivisor,
                    static_cast<int>(arch::kOutputBucketCount - 1));
  }

  PerspectiveAccumulator& operator[](int perspective) {
    return stack_[head_idx_].perspectives[perspective];
  }

  const PerspectiveAccumulator& operator[](int perspective) const {
    return stack_[head_idx_].perspectives[perspective];
  }

 private:
  int head_idx_;
  std::vector<AccumulatorEntry> stack_;
};

}  // namespace nnue

#endif
