#include "accumulator.h"

namespace nnue {

void BucketCacheEntry::Reset() {
  accumulator.psqt_perspectives[Color::kWhite].Reset();
  accumulator.psqt_perspectives[Color::kBlack].Reset();
  accumulator.threat_perspectives[Color::kWhite].Reset();
  accumulator.threat_perspectives[Color::kBlack].Reset();
  piece_bbs = {};
  side_bbs = {};
}

void Accumulator::SetFromState(const BoardState& state) {
  head_idx_ = 0;
  stack_[head_idx_].previous_state = nullptr;
  for (const Color color : {Color::kBlack, Color::kWhite}) {
    auto& accumulator = stack_[head_idx_];
    RefreshPerspective(accumulator, state, color, true);
    accumulator.updated[color] = true;
    accumulator.kings[color] = state.King(color).GetLsb();
    accumulator.threat_perspectives[color].Refresh(
        state, color, accumulator.kings[color]);
    accumulator.threat_updated_squares = 0;
  }
}

void Accumulator::RefreshPerspective(AccumulatorEntry& __restrict__ accumulator,
                                     const BoardState& __restrict__ state,
                                     Color perspective,
                                     bool reset) {
  const auto king_square = Square(state.King(perspective).GetLsb());
  const auto king_bucket = GetKingBucket(king_square, perspective);
  const auto mirrored = king_square.File() >= kFileE;

  auto& cached = input_bucket_cache_[mirrored][king_bucket];
  if (reset) {
    cached.Reset();
  }

  // Finny tables: rather than refreshing from zero pieces, diff against the
  // piece layout from the last update that landed in this bucket
  std::array<I16 const*, 32> adds;
  int num_adds = 0;
  std::array<I16 const*, 32> subs;
  int num_subs = 0;

  auto& psqt_perspective_accumulator =
      cached.accumulator.psqt_perspectives[perspective];

  for (const Color color : {Color::kBlack, Color::kWhite}) {
    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; piece++) {
      const BitBoard old_pieces = cached.piece_bbs[perspective][piece] &
                                  cached.side_bbs[perspective][color];
      const BitBoard new_pieces =
          state.piece_bbs[piece] & state.side_bbs[color];

      const BitBoard to_remove = ~new_pieces & old_pieces;
      for (Square square : to_remove) {
        subs[num_subs++] = psqt_perspective_accumulator.GetFeaturePointer(
            square,
            king_square,
            static_cast<PieceType>(piece),
            color,
            perspective);
      }

      const BitBoard to_add = new_pieces & ~old_pieces;
      for (Square square : to_add) {
        adds[num_adds++] = psqt_perspective_accumulator.GetFeaturePointer(
            square,
            king_square,
            static_cast<PieceType>(piece),
            color,
            perspective);
      }
    }
  }

  psqt_perspective_accumulator.ApplyDeltas(psqt_perspective_accumulator,
                                           adds.data(),
                                           num_adds,
                                           subs.data(),
                                           num_subs);

  cached.side_bbs[perspective] = state.side_bbs;
  cached.piece_bbs[perspective] = state.piece_bbs;

  accumulator.psqt_perspectives[perspective] =
      cached.accumulator.psqt_perspectives[perspective];
}

void Accumulator::PushChanges(const BoardState& previous_state,
                              PsqtAccumulatorChange& psqt_change) {
  IncrementHead();

  auto& entry = stack_[head_idx_];
  entry.psqt_change = psqt_change;
  entry.updated[Color::kBlack] = false;
  entry.updated[Color::kWhite] = false;
  entry.threat_updated_squares = psqt_change.UpdatedSquares();
  entry.previous_state = &previous_state;

  // Update king positions if necessary
  if (psqt_change.sub_0.piece == PieceType::kKing) {
    entry.kings[psqt_change.sub_0.color] = psqt_change.add_0.square;
  } else {
    entry.kings[psqt_change.sub_0.color] =
        stack_[head_idx_ - 1].kings[psqt_change.sub_0.color];
  }
  // The opponent's king doesn't move, so we can copy it from the previous entry
  entry.kings[FlipColor(psqt_change.sub_0.color)] =
      stack_[head_idx_ - 1].kings[FlipColor(psqt_change.sub_0.color)];
}

void Accumulator::ApplyChanges(const BoardState& current_state) {
  // Find the most recent up-to-date accumulator for each perspective
  std::array<int, 2> last_updated{};
  for (const Color perspective : {Color::kWhite, Color::kBlack}) {
    int iter = head_idx_;
    while (!stack_[iter].updated[perspective]) {
      --iter;
    }
    last_updated[perspective] = iter;
  }

  // Walk the nodes only once, so that the threat rows of a node shared by both
  // perspectives are only built once
  ThreatAccumulatorChange threat_change;
  const auto earliest =
      std::min(last_updated[Color::kWhite], last_updated[Color::kBlack]);

  for (int iter = earliest; iter != head_idx_; ++iter) {
    const int dirty_idx = iter + 1;
    auto& dirty_accumulator = stack_[dirty_idx];
    const auto& clean_accumulator = stack_[iter];
    bool threat_changes_accumulated = false;

    // Entries only store the state their move was made from, so the placement
    // after a move is read off the entry above it, or the live board state at
    // the head of the stack
    const BoardState& clean_state = *dirty_accumulator.previous_state;
    const BoardState& dirty_state = dirty_idx == head_idx_
                                      ? current_state
                                      : *stack_[dirty_idx + 1].previous_state;

    for (const Color perspective : {Color::kWhite, Color::kBlack}) {
      // This perspective was already up to date at this point in the stack
      if (iter < last_updated[perspective]) {
        continue;
      }

      const auto clean_king = clean_accumulator.kings[perspective];
      const auto dirty_king = dirty_accumulator.kings[perspective];

      // If the accumulator needs a refresh, we skip applying updates and just
      // refresh it
      if (NeedRefresh(perspective, clean_king, dirty_king)) {
        RefreshPerspective(dirty_accumulator, dirty_state, perspective);
      } else {
        dirty_accumulator.psqt_perspectives[perspective].ApplyChange(
            clean_accumulator.psqt_perspectives[perspective],
            dirty_accumulator.psqt_change,
            perspective,
            dirty_accumulator.kings[perspective]);
      }

      // If king crosses the E-file, refresh the threat features
      if (NeedThreatRefresh(clean_king, dirty_king)) {
        dirty_accumulator.threat_perspectives[perspective].Refresh(
            dirty_state, perspective, dirty_king);
      } else {
        // Accumulate the changes in threats only once per "move", not per
        // perspective
        if (!threat_changes_accumulated) {
          threat_changes_accumulated = true;
          threat_change.Clear();
          threat_change.UpdateThreatsForSquares<false>(
              clean_state, dirty_accumulator.threat_updated_squares);
          threat_change.UpdateThreatsForSquares<true>(
              dirty_state, dirty_accumulator.threat_updated_squares);
        }
        dirty_accumulator.threat_perspectives[perspective].ApplyChange(
            clean_accumulator.threat_perspectives[perspective],
            threat_change,
            perspective,
            dirty_king);
      }

      // Mark the accumulator as having been updated
      dirty_accumulator.updated[perspective] = true;
    }
  }
}

bool Accumulator::NeedRefresh(Color perspective,
                              Square old_king,
                              Square new_king) const {
  if (NeedThreatRefresh(old_king, new_king)) {
    return true;
  }
  return GetKingBucket(old_king, perspective) !=
         GetKingBucket(new_king, perspective);
}

bool Accumulator::NeedThreatRefresh(Square old_king, Square new_king) {
  return (old_king.File() >= kFileE) != (new_king.File() >= kFileE);
}

void Accumulator::IncrementHead() {
  if (++head_idx_ == stack_.size()) {
    stack_.emplace_back();
  }
}

int Accumulator::GetOutputBucket(const BoardState& state) const {
  return std::min((state.Occupied().PopCount() - 2) / kBucketDivisor,
                  static_cast<int>(arch::kOutputBucketCount - 1));
}

int Accumulator::GetKingBucket(Square king_square, Color king_color) const {
  return kKingBucketMap[king_square ^ (0b111000 * king_color)];
}

}  // namespace nnue