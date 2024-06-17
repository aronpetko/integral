#include "move_picker.h"

// clang-format off
constexpr std::array<std::array<int, kNumPieceTypes>, kNumPieceTypes> kMVVLVATable = {{
  {{10, 11, 12, 13, 14, 15}}, // victim P,    attacker K, Q, R, B, N, P
  {{20, 21, 22, 23, 24, 25}}, // victim N,    attacker K, Q, R, B, N, P
  {{30, 31, 32, 33, 34, 35}}, // victim B,    attacker K, Q, R, B, N, P
  {{40, 41, 42, 43, 44, 45}}, // victim R,    attacker K, Q, R, B, N, P
  {{50, 51, 52, 53, 54, 55}}, // victim Q,    attacker K, Q, R, B, N, P
  {{0, 0, 0, 0, 0, 0}},       // victim K,    attacker K, Q, R, B, N, P
}};
// clang-format on

MovePicker::MovePicker(MovePickerType type,
                       Board &board,
                       Move tt_move,
                       history::SearchHistory &history,
                       SearchStackEntry *stack)
    : board_(board),
      tt_move_(tt_move),
      type_(type),
      history_(history),
      stack_(stack),
      stage_(Stage::kTTMove),
      moves_idx_(0) {}

Move MovePicker::Next() {
  const auto &state = board_.GetState();

  if (stage_ == Stage::kTTMove) {
    stage_ = Stage::kGenerateTacticals;

    if (tt_move_ && board_.IsMovePseudoLegal(tt_move_)) {
      if (type_ != MovePickerType::kQuiescence || tt_move_.IsTactical(state)) {
        return tt_move_;
      }
    }
  }

  if (stage_ == Stage::kGenerateTacticals) {
    stage_ = Stage::kGoodTacticals;
    GenerateAndScoreMoves<MoveType::kTactical>(tacticals_);
  }

  if (stage_ == Stage::kGoodTacticals) {
    while (moves_idx_ < tacticals_.Size()) {
      const auto move = SelectionSort(tacticals_, moves_idx_);
      const int score = tacticals_[moves_idx_].score;

      moves_idx_++;

      // If the tactical move loses more than 1 pawn of material it's considered
      // a bad capture. Good captures are searched first, bad captures are
      // searched last
      const bool loses_material = !eval::StaticExchange(
          move, -eval::kSEEPieceScores[PieceType::kPawn], state);
      if (!loses_material && !move.IsUnderPromotion()) {
        return move;
      }

      if (type_ == MovePickerType::kQuiescence && score < 0) {
        return Move::NullMove();
      }

      bad_tacticals_.Push({move, score});
    }

    // Stop searching since all good tacticals have been searched
    if (type_ == MovePickerType::kQuiescence) {
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
    GenerateAndScoreMoves<MoveType::kQuiet>(quiets_);
  }

  if (stage_ == Stage::kQuiets) {
    if (moves_idx_ < quiets_.Size()) {
      return SelectionSort(quiets_, moves_idx_++);
    }

    stage_ = Stage::kBadTacticals;
    moves_idx_ = 0;
  }

  if (stage_ == Stage::kBadTacticals) {
    if (moves_idx_ < bad_tacticals_.Size()) {
      // The bad tacticals are already sorted when we split them off in the good
      // tacticals stage
      return bad_tacticals_[moves_idx_++].move;
    }
  }

  return Move::NullMove();
}

void MovePicker::SkipQuiets() {
  if (stage_ == Stage::kQuiets) {
    stage_ = Stage::kBadTacticals;
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

template <MoveType move_type>
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
  switch (move.GetPromotionType()) {
    case PromotionType::kNone:
      break;
    case PromotionType::kQueen:
      return 1e9 - 1;
    case PromotionType::kKnight:
      return 1e9 - 2;
    default:
      return -1e9;
  }

  auto &state = board_.GetState();

  // Winning/neutral captures are searched next
  // Losing captures are searched last
  if (move.IsCapture(state)) {
    const auto attacker = state.GetPieceType(from);
    const auto victim = state.GetPieceType(to);
    return kMVVLVATable[to == state.en_passant && attacker == PieceType::kPawn
                            ? PieceType::kPawn
                            : victim][attacker];
  }

  // Order moves that caused a beta cutoff by their own history score
  // The higher the depth this move caused a cutoff the more likely it move will
  // be ordered first
  int history = history_.quiet_history->GetScore(move);
  history += history_.continuation_history->GetScore(move, stack_ - 1);
  history += history_.continuation_history->GetScore(move, stack_ - 2);

  return history;
}