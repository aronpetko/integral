#include "move_picker.h"

namespace search {

TUNABLE(kSeeNoisyHistoryDiv, 109, 32, 250, false);

TUNABLE(kPawnScore, 97, 50, 150, false);
TUNABLE(kKnightScore, 305, 200, 400, false);
TUNABLE(kBishopScore, 290, 200, 400, false);
TUNABLE(kRookScore, 537, 400, 600, false);
TUNABLE(kQueenScore, 906, 700, 1100, false);
TUNABLE(kKingScore, 0, 0, 0, true);  // Always 0
TUNABLE(kNoneScore, 0, 0, 0, true);  // Always 0

// clang-format off
inline std::array<Tunable<int>, kNumPieceTypes + 1> kPieceScores = {
  kPawnScore,
  kKnightScore,
  kBishopScore,
  kRookScore,
  kQueenScore,
  kKingScore,
  kNoneScore
};
// clang-format on

TUNABLE(kQueenRookThreatScorePos, 20004, 10000, 30000, false);
TUNABLE(kQueenRookThreatScoreNeg, 18629, 10000, 30000, false);
TUNABLE(kRookMinorThreatScorePos, 12809, 5000, 20000, false);
TUNABLE(kRookMinorThreatScoreNeg, 13027, 5000, 20000, false);
TUNABLE(kMinorPawnThreatScorePos, 7728, 3000, 12000, false);
TUNABLE(kMinorPawnThreatScoreNeg, 8293, 3000, 12000, false);

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
      moves_idx_(0),
      see_threshold_(see_threshold) {}

Move MovePicker::Next() {
  const auto &state = board_.GetState();

  if (stage_ == Stage::kTTMove) {
    stage_ = Stage::kGenerateNoisys;

    if (tt_move_ && board_.IsMovePseudoLegal(tt_move_)) {
      if (type_ != MovePickerType::kQuiescence || state.InCheck() ||
          tt_move_.IsNoisy(state)) {
        return tt_move_;
      }
    }
  }

  if (stage_ == Stage::kGenerateNoisys) {
    stage_ = Stage::kGoodNoisys;
    GenerateAndScoreMoves<MoveGenType::kNoisy>(noisys_);
  }

  if (stage_ == Stage::kGoodNoisys) {
    while (moves_idx_ < noisys_.Size()) {
      const auto move = SelectionSort(noisys_, moves_idx_);
      const auto score = noisys_[moves_idx_].score;
      const auto history_score =
          history_.GetCaptureMoveScore(state, move, stack_->threats);

      moves_idx_++;

      const bool loses_material = !eval::StaticExchange(
          move, see_threshold_ - history_score / kSeeNoisyHistoryDiv, state);
      if (!loses_material && !move.IsUnderPromotion()) {
        return move;
      }

      bad_noisys_.Push({move, score});
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
          board_.IsMovePseudoLegal(second_killer)) {
        return second_killer;
      }
    }
  }

  if (stage_ == Stage::kGenerateQuiets) {
    stage_ = Stage::kQuiets;
    moves_idx_ = 0;
    GenerateAndScoreMoves<MoveGenType::kQuiet>(quiets_);
  }

  if (stage_ == Stage::kQuiets) {
    if (moves_idx_ < quiets_.Size()) {
      return SelectionSort(quiets_, moves_idx_++);
    }

    stage_ = Stage::kBadNoisys;
    moves_idx_ = 0;
  }

  if (stage_ == Stage::kBadNoisys) {
    if (moves_idx_ < bad_noisys_.Size()) {
      // The bad noisys are already sorted when we split them off in the good
      // noisys stage
      return bad_noisys_[moves_idx_++].move;
    }
  }

  return Move::NullMove();
}

void MovePicker::SkipQuiets() {
  if (stage_ == Stage::kQuiets) {
    stage_ = Stage::kBadNoisys;
    moves_idx_ = 0;
  }
}

Move &MovePicker::SelectionSort(List<ScoredMove, kMaxMoves> &move_list,
                                const int &index) {
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

  return move_list[index].move;
}

template <MoveGenType move_type>
void MovePicker::GenerateAndScoreMoves(List<ScoredMove, kMaxMoves> &list) {
  const auto &killers = stack_->killer_moves;
  auto moves = move_gen::GenerateMoves(move_type, board_);
  for (int i = 0; i < moves.Size(); i++) {
    auto move = moves[i];
    if (move != tt_move_ && killers[0] != move && killers[1] != move) {
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
    const int victim_value = kPieceScores[victim] * 100;
    return victim_value +
           history_.GetCaptureMoveScore(state, move, stack_->threats);
  }

  const auto us = state.turn;

  const BitBoard queens = state.Queens(us);
  const BitBoard rooks = queens | state.Rooks(us);
  const BitBoard minors = rooks | state.Knights(us) | state.Bishops(us);

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
  return threat_score +
         history_.GetQuietMoveScore(state, move, state.threats, stack_);
}

}  // namespace search