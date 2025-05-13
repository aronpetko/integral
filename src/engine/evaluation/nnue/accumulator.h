#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include "../../../../shared/nnue/definitions.h"
#include "../../../../shared/simd.h"
#include "../../../chess/board.h"
#include "../../../utils/fused.h"
#include "nnue.h"

namespace nnue {

constexpr U8 kBucketDivisor =
    (32 + arch::kOutputBucketCount - 1) / arch::kOutputBucketCount;

// clang-format off
constexpr std::array<int, 64> kKingBucketMap {
  0,  1,  2,  3,  3,  2,  1,  0,
  4,  5,  6,  7,  7,  6,  5,  4,
  8,  8,  9,  9,  9,  9,  8,  8,
  10, 10, 10, 10, 10, 10, 10, 10,
  10, 10, 10, 10, 10, 10, 10, 10,
  11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11,
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

static std::array<I16, arch::kL1Size>& GetFeatureTable(Square square,
                                                       Square king_square,
                                                       PieceType piece,
                                                       Color piece_color,
                                                       Color perspective) {
  if (king_square.File() >= kFileE) {
    square = square ^ 0b111;
  }

  const int relative_king_square = king_square ^ (56 * perspective);
  const int king_bucket_idx = kKingBucketMap[relative_king_square];
  const int square_idx = square ^ 56 * perspective;
  const int color_idx = perspective != piece_color;
  const int piece_idx = piece;

  return network
      ->feature_weights[king_bucket_idx][color_idx][piece_idx][square_idx]
      .as_array();
}

class PerspectiveAccumulator {
 public:
  PerspectiveAccumulator() : values_({}) {}

  void Reset() {
    // Initialize the accumulator values with the network biases
    for (int i = 0; i < arch::kL1Size; ++i) {
      values_[i] = network->feature_biases[i];
    }
  }

  void Refresh(const BoardState& state, Color perspective) {
    Reset();
    const Square king_square = state.King(perspective).GetLsb();
    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
      for (Square square : state.piece_bbs[piece]) {
        ApplyChange<kAdd>(perspective,
                          king_square,
                          FeatureData{square,
                                      static_cast<PieceType>(piece),
                                      state.GetPieceColor(square)});
      }
    }
  }

  I16 const* GetFeaturePointer(Color perspective,
                               Square king_square,
                               Square square,
                               PieceType piece,
                               Color piece_color) {
    return GetFeatureTable(square, king_square, piece, piece_color, perspective)
        .data();
  }

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
  void ApplyChange(const PerspectiveAccumulator& previous,
                   Color perspective,
                   Square king_square,
                   const Ts&... accumulator_changes) {
    auto FeatureTable = [&](const FeatureData& feature) {
      return std::as_const(GetFeaturePointer(feature.square,
                                             king_square,
                                             feature.piece,
                                             feature.color,
                                             perspective));
    };

    const std::tuple changes = {FeatureTable(accumulator_changes)...};

    for (int i = 0; i < arch::kL1Size; ++i) {
      values_[i] = std::apply(
          [&](const auto&... changes) {
            return Fused<ops...>(previous[i], changes[i]...);
          },
          changes);
    }
  }

  void ApplyChange(const PerspectiveAccumulator& previous,
                   const AccumulatorChange& change,
                   Color perspective,
                   Square king_square) {
    switch (change.type) {
      case AccumulatorChange::kNormal:
        ApplyChange<kAdd, kSub>(
            previous, perspective, king_square, change.add_0, change.sub_0);
        break;
      case AccumulatorChange::kCapture:
        ApplyChange<kAdd, kSub, kSub>(previous,
                                      perspective,
                                      king_square,
                                      change.add_0,
                                      change.sub_0,
                                      change.sub_1);
        break;
      case AccumulatorChange::kCastle:
        ApplyChange<kAdd, kAdd, kSub, kSub>(previous,
                                            perspective,
                                            king_square,
                                            change.add_0,
                                            change.add_1,
                                            change.sub_0,
                                            change.sub_1);
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
  alignas(simd::kAlignment) std::array<I16, arch::kL1Size> values_;
};

struct AccumulatorEntry {
  alignas(simd::kAlignment) std::array<PerspectiveAccumulator, 2> perspectives;
  AccumulatorChange change;
  std::array<Square, 2> kings;
  std::array<bool, 2> updated;
  BoardState state;
};

struct BucketCacheEntry {
  AccumulatorEntry accumulator;
  MultiArray<BitBoard, 2, kNumPieceTypes> piece_bbs{};
  MultiArray<BitBoard, 2, kNumColors> side_bbs{};

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
    stack_.resize(512);
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

  void RefreshPerspective(AccumulatorEntry& __restrict__ accumulator,
                          const BoardState& __restrict__ state,
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
    std::array<I16 const*, 32> adds;
    int num_adds = 0;
    std::array<I16 const*, 32> subs;
    int num_subs = 0;
    auto& perspective_accumulator =
        cached.accumulator.perspectives[perspective];
    for (const Color color : {Color::kBlack, Color::kWhite}) {
      for (int piece = PieceType::kPawn; piece <= PieceType::kKing; piece++) {
        const BitBoard old_pieces = cached.piece_bbs[perspective][piece] &
                                    cached.side_bbs[perspective][color];
        const BitBoard new_pieces =
            state.piece_bbs[piece] & state.side_bbs[color];

        // Calculate difference of features to remove
        const BitBoard to_remove = ~new_pieces & old_pieces;
        for (Square square : to_remove) {
          subs[num_subs++] = perspective_accumulator.GetFeaturePointer(
              perspective,
              king_square,
              square,
              static_cast<PieceType>(piece),
              color);
        }

        // Calculate difference of features to add
        const BitBoard to_add = new_pieces & ~old_pieces;
        for (Square square : to_add) {
          adds[num_adds++] = perspective_accumulator.GetFeaturePointer(
              perspective,
              king_square,
              square,
              static_cast<PieceType>(piece),
              color);
        }
      }
    }

    // Perform all add operations
    for (; num_adds >= 4; num_adds -= 4) {
      for (int i = 0; i < arch::kL1Size; ++i) {
        perspective_accumulator[i] +=
            adds[num_adds - 4][i] + adds[num_adds - 3][i] +
            adds[num_adds - 2][i] + adds[num_adds - 1][i];
      }
    }
    for (; num_adds >= 1; num_adds -= 1) {
      for (int i = 0; i < arch::kL1Size; ++i) {
        perspective_accumulator[i] += adds[num_adds - 1][i];
      }
    }

    // Perform all sub operations
    for (; num_subs >= 4; num_subs -= 4) {
      for (int i = 0; i < arch::kL1Size; ++i) {
        perspective_accumulator[i] -=
            subs[num_subs - 4][i] + subs[num_subs - 3][i] +
            subs[num_subs - 2][i] + subs[num_subs - 1][i];
      }
    }
    for (; num_subs >= 1; num_subs -= 1) {
      for (int i = 0; i < arch::kL1Size; ++i) {
        perspective_accumulator[i] -= subs[num_subs - 1][i];
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

  void ApplyChanges() {
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
