#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "../../../chess/board.h"
#include "../../../utils/simd.h"
#include "arch.h"
#include "nnue.h"

namespace nnue {

constexpr U8 kBucketDivisor =
    (32 + arch::kOutputBucketCount - 1) / arch::kOutputBucketCount;

// clang-format off
constexpr std::array<int, 64> kKingBucketMap {
  0, 1, 2, 3, 3, 2, 1, 0,
  4, 4, 5, 5, 5, 5, 4, 4,
  6, 6, 7, 7, 7, 7, 6, 6,
  6, 6, 7, 7, 7, 7, 6, 6,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
};
// clang-format on

struct FeatureData {
  Square square = Squares::kNoSquare;
  PieceType piece = PieceType::kNone;
  Color color = Color::kNoColor;
};

struct AccumulatorChange {
  FeatureData sub_0, add_0, sub_1, add_1;

  enum Type {
    kNormal,
    kCapture,
    kCastle
  } type;
};

static std::array<I16, arch::kHiddenLayerSize>& GetFeatureTable(
    Square square,
    Square king_square,
    PieceType piece,
    Color piece_color,
    Color perspective) {
  square = square ^ ((king_square.File() >= kFileE) * 0b111);

  const int relative_king_square = king_square ^ (56 * perspective);
  const int king_bucket_idx = kKingBucketMap[relative_king_square];
  const int square_idx = square ^ 56 * perspective;
  const int color_idx = perspective != piece_color;
  const int piece_idx = piece;

  return network
      ->feature_weights[king_bucket_idx][color_idx][piece_idx][square_idx];
}

class PerspectiveAccumulator {
 public:
  PerspectiveAccumulator() : values_({}) {}

  void Reset() {
    // Initialize the accumulator values with the network biases
#if BUILD_HAS_SIMD
    constexpr int simd_width = sizeof(simd::Vepi16) / sizeof(I16);
    for (int i = 0; i < arch::kHiddenLayerSize; i += simd_width) {
      simd::StoreEpi16(&values_[i],
                       simd::LoadEpi16(&network->feature_biases[i]));
    }
#else
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] = network->feature_biases[i];
    }
#endif
  }

  void Refresh(const BoardState& state, Color perspective) {
    Reset();
    const Square king_square = state.King(perspective).GetLsb();

#if BUILD_HAS_SIMD
    // Process pieces in SIMD-friendly chunks
    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
      Square squares[32];  // Max pieces of one type
      Color colors[32];
      int count = 0;

      for (Square square : state.piece_bbs[piece]) {
        squares[count] = square;
        colors[count] = state.GetPieceColor(square);
        count++;
      }

      // Process pieces in groups of 4 for SIMD
      for (int i = 0; i < count; i += 4) {
        if (i + 4 <= count) {
          AddFeatures4(perspective,
                       king_square,
                       squares[i],
                       squares[i + 1],
                       squares[i + 2],
                       squares[i + 3],
                       static_cast<PieceType>(piece),
                       colors[i],
                       colors[i + 1],
                       colors[i + 2],
                       colors[i + 3]);
        } else {
          for (int j = i; j < count; ++j) {
            AddFeature(perspective,
                       king_square,
                       squares[j],
                       static_cast<PieceType>(piece),
                       colors[j]);
          }
        }
      }
    }
#else
    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
      for (Square square : state.piece_bbs[piece]) {
        AddFeature(perspective,
                   king_square,
                   square,
                   static_cast<PieceType>(piece),
                   state.GetPieceColor(square));
      }
    }
#endif
  }

#if BUILD_HAS_SIMD
  void AddFeatures4(Color perspective,
                    Square king_square,
                    Square square1,
                    Square square2,
                    Square square3,
                    Square square4,
                    PieceType piece,
                    Color color1,
                    Color color2,
                    Color color3,
                    Color color4) {
    const auto& table1 =
        GetFeatureTable(square1, king_square, piece, color1, perspective);
    const auto& table2 =
        GetFeatureTable(square2, king_square, piece, color2, perspective);
    const auto& table3 =
        GetFeatureTable(square3, king_square, piece, color3, perspective);
    const auto& table4 =
        GetFeatureTable(square4, king_square, piece, color4, perspective);

    constexpr int simd_width = sizeof(simd::Vepi16) / sizeof(I16);
    for (int i = 0; i < arch::kHiddenLayerSize; i += simd_width) {
      auto current = simd::LoadEpi16(&values_[i]);
      auto vec1 = simd::LoadEpi16(&table1[i]);
      auto vec2 = simd::LoadEpi16(&table2[i]);
      auto vec3 = simd::LoadEpi16(&table3[i]);
      auto vec4 = simd::LoadEpi16(&table4[i]);

      current = simd::AddEpi16(current, vec1);
      current = simd::AddEpi16(current, vec2);
      current = simd::AddEpi16(current, vec3);
      current = simd::AddEpi16(current, vec4);

      simd::StoreEpi16(&values_[i], current);
    }
  }
#endif

  void AddFeature(Color perspective,
                  Square king_square,
                  Square square,
                  PieceType piece,
                  Color piece_color) {
    const auto& table =
        GetFeatureTable(square, king_square, piece, piece_color, perspective);

#if BUILD_HAS_SIMD
    constexpr int simd_width = sizeof(simd::Vepi16) / sizeof(I16);
    for (int i = 0; i < arch::kHiddenLayerSize; i += simd_width) {
      auto current = simd::LoadEpi16(&values_[i]);
      auto value = simd::LoadEpi16(&table[i]);
      current = simd::AddEpi16(current, value);
      simd::StoreEpi16(&values_[i], current);
    }
#else
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] += table[i];
    }
#endif
  }

  void SubFeature(Color perspective,
                  Square king_square,
                  Square square,
                  PieceType piece,
                  Color piece_color) {
    const auto& table =
        GetFeatureTable(square, king_square, piece, piece_color, perspective);

#if BUILD_HAS_SIMD
    constexpr int simd_width = sizeof(simd::Vepi16) / sizeof(I16);
    for (int i = 0; i < arch::kHiddenLayerSize; i += simd_width) {
      auto current = simd::LoadEpi16(&values_[i]);
      auto value = simd::LoadEpi16(&table[i]);
      value = simd::MultiplyEpi16(value, simd::SetEpi16(-1));
      current = simd::AddEpi16(current, value);
      simd::StoreEpi16(&values_[i], current);
    }
#else
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] -= table[i];
    }
#endif
  }

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

#if BUILD_HAS_SIMD
    constexpr int simd_width = sizeof(simd::Vepi16) / sizeof(I16);
    for (int i = 0; i < arch::kHiddenLayerSize; i += simd_width) {
      auto prev = simd::LoadEpi16(&previous[i]);
      auto add = simd::LoadEpi16(&add_table[i]);
      auto sub = simd::LoadEpi16(&sub_table[i]);
      sub = simd::MultiplyEpi16(sub, simd::SetEpi16(-1));
      auto result = simd::AddEpi16(prev, add);
      result = simd::AddEpi16(result, sub);
      simd::StoreEpi16(&values_[i], result);
    }
#else
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] = previous[i] + add_table[i] - sub_table[i];
    }
#endif
  }

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

#if BUILD_HAS_SIMD
    constexpr int simd_width = sizeof(simd::Vepi16) / sizeof(I16);
    for (int i = 0; i < arch::kHiddenLayerSize; i += simd_width) {
      auto prev = simd::LoadEpi16(&previous[i]);
      auto add = simd::LoadEpi16(&add_table[i]);
      auto sub1 = simd::LoadEpi16(&sub_table1[i]);
      auto sub2 = simd::LoadEpi16(&sub_table2[i]);

      sub1 = simd::MultiplyEpi16(sub1, simd::SetEpi16(-1));
      sub2 = simd::MultiplyEpi16(sub2, simd::SetEpi16(-1));

      auto result = simd::AddEpi16(prev, add);
      result = simd::AddEpi16(result, sub1);
      result = simd::AddEpi16(result, sub2);

      simd::StoreEpi16(&values_[i], result);
    }
#else
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] = previous[i] + add_table[i] - sub_table1[i] - sub_table2[i];
    }
#endif
  }

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

#if BUILD_HAS_SIMD
    constexpr int simd_width = sizeof(simd::Vepi16) / sizeof(I16);
    for (int i = 0; i < arch::kHiddenLayerSize; i += simd_width) {
      auto prev = simd::LoadEpi16(&previous[i]);
      auto add1 = simd::LoadEpi16(&add_table1[i]);
      auto add2 = simd::LoadEpi16(&add_table2[i]);
      auto sub1 = simd::LoadEpi16(&sub_table1[i]);
      auto sub2 = simd::LoadEpi16(&sub_table2[i]);

      sub1 = simd::MultiplyEpi16(sub1, simd::SetEpi16(-1));
      sub2 = simd::MultiplyEpi16(sub2, simd::SetEpi16(-1));

      auto result = simd::AddEpi16(prev, add1);
      result = simd::AddEpi16(result, add2);
      result = simd::AddEpi16(result, sub1);
      result = simd::AddEpi16(result, sub2);

      simd::StoreEpi16(&values_[i], result);
    }
#else
    for (int i = 0; i < arch::kHiddenLayerSize; ++i) {
      values_[i] = previous[i] + add_table1[i] + add_table2[i] - sub_table1[i] -
                   sub_table2[i];
    }
#endif
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
  alignas(64) std::array<PerspectiveAccumulator, 2> perspectives;
  AccumulatorChange change;
  std::array<Square, 2> kings;
  std::array<bool, 2> updated;
  BoardState state;
};

struct BucketCacheEntry {
  MultiArray<BitBoard, 2, kNumPieceTypes> piece_bbs{};
  MultiArray<BitBoard, 2, kNumColors> side_bbs{};
  AccumulatorEntry accumulator;

  BucketCacheEntry() {
    Reset();
  }

  void Reset() {
    accumulator.perspectives[Color::kWhite].Reset();
    accumulator.perspectives[Color::kBlack].Reset();
    piece_bbs = {};
    side_bbs = {};
  }
};

class Accumulator {
 public:
  Accumulator() : head_idx_(0) {
    stack_.resize(2048);
  }

  void SetFromState(const BoardState& state) {
    head_idx_ = 0;
    for (const Color color : {Color::kBlack, Color::kWhite}) {
      auto& accumulator = stack_[head_idx_];
      RefreshPerspective(accumulator, state, color, true);
      accumulator.updated[color] = true;
      accumulator.kings[color] = state.King(color).GetLsb();
    }
  }

  void RefreshPerspective(AccumulatorEntry& accumulator,
                          const BoardState& state,
                          Color perspective,
                          bool reset = false) {
    const auto king_square = Square(state.King(perspective).GetLsb());
    const auto king_bucket = GetKingBucket(king_square, perspective);
    const auto mirrored = king_square.File() >= kFileE;

    auto& cached = input_bucket_cache_[mirrored][king_bucket];
    // Reset the cached accumulator data to the network biases
    if (reset) {
      cached.Reset();
    }

    // Instead of refreshing this perspective's accumulator from zero pieces, we
    // reset from the pieces of the last accumulator update in this bucket. This
    // is an optimization trick known as "Finny Tables".
    for (const Color color : {Color::kBlack, Color::kWhite}) {
      for (int piece = PieceType::kPawn; piece <= PieceType::kKing; piece++) {
        const BitBoard old_pieces = cached.piece_bbs[perspective][piece] &
                                    cached.side_bbs[perspective][color];
        const BitBoard new_pieces =
            state.piece_bbs[piece] & state.side_bbs[color];

        // Calculate difference of features to remove
        const BitBoard to_remove = ~new_pieces & old_pieces;
        for (Square square : to_remove) {
          cached.accumulator.perspectives[perspective].SubFeature(
              perspective,
              king_square,
              square,
              static_cast<PieceType>(piece),
              color);
        }

        // Calculate difference of features to add
        const BitBoard to_add = new_pieces & ~old_pieces;
        for (Square square : to_add) {
          cached.accumulator.perspectives[perspective].AddFeature(
              perspective,
              king_square,
              square,
              static_cast<PieceType>(piece),
              color);
        }
      }
    }

    cached.side_bbs[perspective] = state.side_bbs;
    cached.piece_bbs[perspective] = state.piece_bbs;

    accumulator.perspectives[perspective] =
        cached.accumulator.perspectives[perspective];
  }

  void PushChanges(const BoardState& state, AccumulatorChange& change) {
    IncrementHead();

    auto& entry = stack_[head_idx_];
    entry.change = change;
    entry.updated[Color::kBlack] = false;
    entry.updated[Color::kWhite] = false;
    entry.state = state;

    // Update king positions if necessary
    if (change.sub_0.piece == PieceType::kKing) {
      entry.kings[change.sub_0.color] = change.add_0.square;
    } else {
      entry.kings[change.sub_0.color] =
          stack_[head_idx_ - 1].kings[change.sub_0.color];
    }
    // The opponent's king doesn't move, so we can copy it from the previous
    // entry
    entry.kings[FlipColor(change.sub_0.color)] =
        stack_[head_idx_ - 1].kings[FlipColor(change.sub_0.color)];
  }

  void ApplyChanges(Board& board) {
    for (Color perspective : {Color::kWhite, Color::kBlack}) {
      if (stack_[head_idx_].updated[perspective]) {
        continue;
      }

      int iter = head_idx_;
      while (true) {
        --iter;

        // We've found the earliest updated accumulator
        if (stack_[iter].updated[perspective]) {
          int last_updated = iter;

          // Apply all updates from the earliest updated accumulator to now
          while (last_updated != head_idx_) {
            auto& dirty_accumulator = stack_[last_updated + 1];
            const auto& clean_accumulator = stack_[last_updated];

            // If the accumulator needs a refresh, we skip applying updates and
            // just refresh it
            if (NeedRefresh(perspective,
                            clean_accumulator.kings[perspective],
                            dirty_accumulator.kings[perspective])) {
              RefreshPerspective(
                  dirty_accumulator, dirty_accumulator.state, perspective);
            } else {
              dirty_accumulator.perspectives[perspective].ApplyChange(
                  clean_accumulator.perspectives[perspective],
                  dirty_accumulator.change,
                  perspective,
                  dirty_accumulator.kings[perspective]);
            }
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

    // Check if the king moved into a different bucket
    return GetKingBucket(old_king, perspective) !=
           GetKingBucket(new_king, perspective);
  }

  void IncrementHead() {
    // Move forward the head accumulator
    if (++head_idx_ == stack_.size()) {
      stack_.emplace_back();
    }
  }

  void UndoMove() {
    --head_idx_;
  }

  [[nodiscard]] int GetOutputBucket(const BoardState& state) const {
    return std::min((state.Occupied().PopCount() - 2) / kBucketDivisor,
                    static_cast<int>(arch::kOutputBucketCount - 1));
  }

  [[nodiscard]] PerspectiveAccumulator& operator[](int perspective) {
    return stack_[head_idx_].perspectives[perspective];
  }

  [[nodiscard]] const PerspectiveAccumulator& operator[](
      int perspective) const {
    return stack_[head_idx_].perspectives[perspective];
  }

 private:
  [[nodiscard]] inline int GetKingBucket(Square king_square,
                                         Color king_color) const {
    return kKingBucketMap[king_square ^ (56 * king_color)];
  }

 private:
  int head_idx_;
  std::vector<AccumulatorEntry> stack_;
  MultiArray<BucketCacheEntry, 2, arch::kInputBucketCount> input_bucket_cache_;
};

}  // namespace nnue

#endif
