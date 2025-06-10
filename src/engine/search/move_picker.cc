#include "move_picker.h"

namespace search {

TUNABLE(kSeeNoisyHistoryDiv, 105, 32, 250, false);

TUNABLE(kPawnScore, 101, 50, 150, false);
TUNABLE(kKnightScore, 304, 200, 400, false);
TUNABLE(kBishopScore, 289, 200, 400, false);
TUNABLE(kRookScore, 528, 400, 600, false);
TUNABLE(kQueenScore, 917, 700, 1100, false);
TUNABLE(kKingScore, 0, 0, 0, true);  // Always 0
TUNABLE(kNoneScore, 0, 0, 0, true);  // Always 0

// clang-format off
inline std::array kPieceScores = {
  &kPawnScore,
  &kKnightScore,
  &kBishopScore,
  &kRookScore,
  &kQueenScore,
  &kKingScore,
  &kNoneScore
};
// clang-format on

TUNABLE(kQueenRookThreatScorePos, 20418, 10000, 30000, false);
TUNABLE(kQueenRookThreatScoreNeg, 18561, 10000, 30000, false);
TUNABLE(kRookMinorThreatScorePos, 12930, 5000, 20000, false);
TUNABLE(kRookMinorThreatScoreNeg, 12720, 5000, 20000, false);
TUNABLE(kMinorPawnThreatScorePos, 8063, 3000, 12000, false);
TUNABLE(kMinorPawnThreatScoreNeg, 8355, 3000, 12000, false);

MovePicker::MovePicker(MovePickerType type,
                       Board &board,
                       Move tt_move,
                       history::History &history,
                       StackEntry *stack,
                       int see_threshold)
    : board_(board),
      tt_move_(tt_move),
      type_(type),
      history_(history),
      stack_(stack),
      stage_(Stage::kTTMove),
      noisy_moves_idx_(0),
      quiet_moves_idx_(0),
      skip_quiets_(false),
      see_threshold_(see_threshold) {}

Move MovePicker::Next() {
  const auto &state = board_.GetState();

  if (stage_ == Stage::kTTMove) {
    stage_ = Stage::kGenerateNoisies;

    if (tt_move_ && board_.IsMovePseudoLegal(tt_move_)) {
      if (type_ != MovePickerType::kQuiescence || state.InCheck() ||
          tt_move_.IsNoisy(state)) {
        return tt_move_;
      }
    }
  }

  if (stage_ == Stage::kGenerateNoisies) {
    stage_ = Stage::kGoodNoisies;
    GenerateAndScoreMoves<MoveGenType::kNoisy>(noisies_);
  }

  if (stage_ == Stage::kGoodNoisies) {
    while (noisy_moves_idx_ < noisies_.Size()) {
      const auto move = SelectionSort(noisies_, noisy_moves_idx_).move;
      const auto score = noisies_[noisy_moves_idx_].score;
      const auto history_score = history_.GetCaptureMoveScore(state, move);

      noisy_moves_idx_++;

      const bool loses_material = !eval::StaticExchange(
          move, see_threshold_ - history_score / kSeeNoisyHistoryDiv, state);
      if (!loses_material && !move.IsUnderPromotion()) {
        return move;
      }

      bad_noisies_.Push({move, score});
    }

    if (type_ == MovePickerType::kQuiescence && !state.InCheck()) {
      return Move::NullMove();
    }

    stage_ = Stage::kFirstKiller;
  }

  if (stage_ == Stage::kFirstKiller) {
    stage_ = Stage::kSecondKiller;

    if (stack_) {
      const auto first_killer = stack_->killer_moves[0];
      if (first_killer && first_killer != tt_move_ &&
          !first_killer.IsNoisy(state) &&
          board_.IsMovePseudoLegal(first_killer)) {
        return first_killer;
      }
    }
  }

  if (stage_ == Stage::kSecondKiller) {
    stage_ = Stage::kGenerateQuiets;

    if (stack_) {
      const auto second_killer = stack_->killer_moves[1];
      if (second_killer && second_killer != tt_move_ &&
          !second_killer.IsNoisy(state) &&
          board_.IsMovePseudoLegal(second_killer)) {
        return second_killer;
      }
    }
  }

  if (stage_ == Stage::kGenerateQuiets) {
    if (skip_quiets_) {
      stage_ = Stage::kBadNoisies;
    } else {
      stage_ = Stage::kGoodQuiets;
      quiet_moves_idx_ = 0;
      GenerateAndScoreMoves<MoveGenType::kQuiet>(quiets_);
    }
  }

  if (stage_ == Stage::kGoodQuiets) {
    if (quiet_moves_idx_ < quiets_.Size() && !skip_quiets_) {
      const auto scored_move = SelectionSort(quiets_, quiet_moves_idx_++);
      if (scored_move.score < -14000) {
        quiet_moves_idx_--;
      } else {
        return scored_move.move;
      }
    }

    stage_ = Stage::kBadNoisies;
    noisy_moves_idx_ = 0;
  }

  if (stage_ == Stage::kBadNoisies) {
    if (noisy_moves_idx_ < bad_noisies_.Size()) {
      // The bad noisies are already sorted when we split them off in the good
      // noisies stage
      return bad_noisies_[noisy_moves_idx_++].move;
    }

    stage_ = Stage::kBadQuiets;
  }

  if (stage_ == Stage::kBadQuiets) {
    if (quiet_moves_idx_ < quiets_.Size() && !skip_quiets_) {
      const auto scored_move = SelectionSort(quiets_, quiet_moves_idx_++);
      if (scored_move.score < -20000) {
        return scored_move.move;
      }
    }
  }

  return Move::NullMove();
}

void MovePicker::SkipQuiets() {
  skip_quiets_ = true;
}

ScoredMove &MovePicker::SelectionSort(List<ScoredMove, kMaxMoves> &move_list,
                                      int index) {
  int best_move_idx = index;
  int best_score = move_list[index].score;
  for (int next = index + 1; next < move_list.Size(); ++next) {
    if (move_list[next].score > best_score) {
      best_move_idx = next;
      best_score = move_list[next].score;
    }
  }

  if (best_move_idx != index) {
    std::swap(move_list[index], move_list[best_move_idx]);
  }

  return move_list[index];
}

template <MoveGenType move_type>
void MovePicker::GenerateAndScoreMoves(List<ScoredMove, kMaxMoves> &list) {
  const auto &state = board_.GetState();

  const auto &killers = stack_->killer_moves;
  const bool killer_0_noisy = killers[0].IsNoisy(state),
             killer_1_noisy = killers[1].IsNoisy(state);

  auto moves = move_gen::GenerateMoves<move_type>(board_);
  for (int i = 0; i < moves.Size(); i++) {
    auto move = moves[i];
    if (move != tt_move_ && (killers[0] != move || killer_0_noisy) &&
        (killers[1] != move || killer_1_noisy)) {
      list.Push({move, ScoreMove(move)});
    }
  }
}

int MovePicker::ScoreMove(Move &move) {
  const auto from = move.GetFrom();
  const auto to = move.GetTo();

  // Queen and knight promotions get priority
  if (move.GetType() == MoveType::kPromotion) {
    switch (move.GetPromotionType()) {
      case PromotionType::kQueen:
        return 1e9 - 1;
      case PromotionType::kKnight:
        return 1e9 - 2;
      default:
        return -1e9;
    }
  }

  auto &state = board_.GetState();

  // Winning/neutral captures are searched next
  // Losing captures are searched last
  if (move.IsCapture(state)) {
    const auto victim =
        move.IsEnPassant(state) ? PieceType::kPawn : state.GetPieceType(to);
    const int victim_value = *kPieceScores[victim] * 100;
    return victim_value + history_.GetCaptureMoveScore(state, move);
  }

  const BitBoard pawn_threats = state.threatened_by[kPawn];
  const BitBoard minor_threats = pawn_threats | state.threatened_by[kKnight] |
                                 state.threatened_by[kBishop];
  const BitBoard rook_threats = minor_threats | state.threatened_by[kRook];

  int threat_score = 0;
  switch (state.GetPieceType(from)) {
    case kQueen:
      if (rook_threats.IsSet(from)) threat_score += kQueenRookThreatScorePos;
      if (rook_threats.IsSet(to)) threat_score -= kQueenRookThreatScoreNeg;
      break;
    case kRook:
      if (minor_threats.IsSet(from)) threat_score += kRookMinorThreatScorePos;
      if (minor_threats.IsSet(to)) threat_score -= kRookMinorThreatScoreNeg;
      break;
    case kBishop:
    case kKnight:
      if (pawn_threats.IsSet(from)) threat_score += kMinorPawnThreatScorePos;
      if (pawn_threats.IsSet(to)) threat_score -= kMinorPawnThreatScoreNeg;
      break;
    default:
      break;
  }

  // Order moves that caused a beta cutoff by their own history score
  // The higher the depth this move caused a cutoff the more likely it move will
  // be ordered first
  return threat_score + history_.GetQuietMoveScore(state, move, stack_);
}

}  // namespace search