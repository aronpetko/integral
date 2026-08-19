#include "accumulator.h"

namespace nnue {

void BucketCacheEntry::Reset() {
  accumulator.perspectives[Color::kWhite].Reset();
  accumulator.perspectives[Color::kBlack].Reset();
  accumulator.threat_perspectives[Color::kWhite].Reset();
  accumulator.threat_perspectives[Color::kBlack].Reset();
  piece_bbs = {};
  side_bbs = {};
}

void Accumulator::SetFromState(const BoardState& state) {
  head_idx_ = 0;
  for (const Color color : {Color::kBlack, Color::kWhite}) {
    auto& accumulator = stack_[head_idx_];
    RefreshPerspective(accumulator, state, color, true);
    accumulator.updated[color] = true;
    accumulator.kings[color] = state.King(color).GetLsb();
    // Threats are refreshed lazily, at eval entry.
    accumulator.threat_valid[color] = false;
    accumulator.state = state;
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
  // piece layout from the last update that landed in this bucket.
  std::array<I16 const*, 32> adds;
  int num_adds = 0;
  std::array<I16 const*, 32> subs;
  int num_subs = 0;

  auto& perspective_accumulator = cached.accumulator.perspectives[perspective];

  for (const Color color : {Color::kBlack, Color::kWhite}) {
    for (int piece = PieceType::kPawn; piece <= PieceType::kKing; piece++) {
      const BitBoard old_pieces = cached.piece_bbs[perspective][piece] &
                                  cached.side_bbs[perspective][color];
      const BitBoard new_pieces =
          state.piece_bbs[piece] & state.side_bbs[color];

      const BitBoard to_remove = ~new_pieces & old_pieces;
      for (Square square : to_remove) {
        subs[num_subs++] = perspective_accumulator.GetFeaturePointer(
            square,
            king_square,
            static_cast<PieceType>(piece),
            color,
            perspective);
      }

      const BitBoard to_add = new_pieces & ~old_pieces;
      for (Square square : to_add) {
        adds[num_adds++] = perspective_accumulator.GetFeaturePointer(
            square,
            king_square,
            static_cast<PieceType>(piece),
            color,
            perspective);
      }
    }
  }

  perspective_accumulator.ApplyDeltas(
      perspective_accumulator, adds.data(), num_adds, subs.data(), num_subs);

  cached.side_bbs[perspective] = state.side_bbs;
  cached.piece_bbs[perspective] = state.piece_bbs;

  accumulator.perspectives[perspective] =
      cached.accumulator.perspectives[perspective];
}

void Accumulator::PushChanges(const BoardState& state,
                              PsqtAccumulatorChange& change) {
  IncrementHead();

  auto& entry = stack_[head_idx_];
  entry.change = change;
  entry.updated[Color::kBlack] = false;
  entry.updated[Color::kWhite] = false;
  // Threats are not propagated forward; the new node refreshes at eval entry.
  entry.threat_valid[Color::kBlack] = false;
  entry.threat_valid[Color::kWhite] = false;
  entry.state = state;

  if (change.sub_0.piece == PieceType::kKing) {
    entry.kings[change.sub_0.color] = change.add_0.square;
  } else {
    entry.kings[change.sub_0.color] =
        stack_[head_idx_ - 1].kings[change.sub_0.color];
  }

  entry.kings[FlipColor(change.sub_0.color)] =
      stack_[head_idx_ - 1].kings[FlipColor(change.sub_0.color)];
}

void Accumulator::ApplyChanges() {
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

void Accumulator::EnsureThreatsFresh() {
  auto& entry = stack_[head_idx_];
  for (const Color perspective : {Color::kWhite, Color::kBlack}) {
    if (entry.threat_valid[perspective]) {
      continue;
    }
    entry.threat_perspectives[perspective].Refresh(
        entry.state, perspective, entry.kings[perspective]);
    entry.threat_valid[perspective] = true;
  }
}

bool Accumulator::NeedRefresh(Color perspective,
                              Square old_king,
                              Square new_king) const {
  if ((old_king.File() >= kFileE) != (new_king.File() >= kFileE)) {
    return true;
  }
  return GetKingBucket(old_king, perspective) !=
         GetKingBucket(new_king, perspective);
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