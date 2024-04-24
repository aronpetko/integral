#include "move_picker.h"

// clang-format off
const std::array<std::array<int, PieceType::kNumTypes>, PieceType::kNumTypes> kMVVLVATable = {{
  {{10, 11, 12, 13, 14, 15}}, // victim P,    attacker K, Q, R, B, N, P
  {{20, 21, 22, 23, 24, 25}}, // victim N,    attacker K, Q, R, B, N, P
  {{30, 31, 32, 33, 34, 35}}, // victim B,    attacker K, Q, R, B, N, P
  {{40, 41, 42, 43, 44, 45}}, // victim R,    attacker K, Q, R, B, N, P
  {{50, 51, 52, 53, 54, 55}}, // victim Q,    attacker K, Q, R, B, N, P
  {{0, 0, 0, 0, 0, 0}},       // victim K,    attacker K, Q, R, B, N, P
}};
// clang-format on

MovePicker::MovePicker(MovePickerType type, Board &board, Move tt_move, MoveHistory &move_history,
                       Search::Stack *search_stack)
    : type_(type),
      board_(board),
      tt_move_(tt_move),
      stage_(Stage::kTTMove),
      move_history_(move_history),
      search_stack_(search_stack),
      moves_idx_(0) {}

Move MovePicker::next() {
  if (stage_ == Stage::kTTMove) {
    stage_ = Stage::kGenerateMoves;

    auto &state = board_.get_state();
    if (tt_move_ && board_.is_move_pseudo_legal(tt_move_)) {
      if (type_ != MovePickerType::kQuiescence || tt_move_.is_tactical(state)) {
        return tt_move_;
      }
    }
  }

  if (stage_ == Stage::kGenerateMoves) {
    stage_ = Stage::kPlayMoves;
    if (type_ == MovePickerType::kQuiescence) {
      generate_and_score_moves<MoveType::kTactical>();
    } else {
      generate_and_score_moves<MoveType::kAll>();
    }
  }

  if (stage_ == Stage::kPlayMoves) {
    if (moves_idx_ < scored_moves_.moves.size()) {
      const auto &move = selection_sort(scored_moves_, moves_idx_);
      if (type_ == MovePickerType::kQuiescence && scored_moves_.scores[moves_idx_] < 0) {
        return Move::null_move();
      }

      moves_idx_++;
      return move;
    }
  }

  return Move::null_move();
}

Move &MovePicker::selection_sort(ScoredMoveList &move_list, const int &index) {
  int best_move_idx = index, best_move_score = move_list.scores[index];
  for (int next = index + 1; next < move_list.moves.size(); next++) {
    if (move_list.scores[next] > best_move_score) {
      best_move_idx = next;
      best_move_score = move_list.scores[next];
    }
  }

  std::swap(move_list.moves[index], move_list.moves[best_move_idx]);
  std::swap(move_list.scores[index], move_list.scores[best_move_idx]);
  return move_list.moves[index];
}

template <MoveType move_type>
void MovePicker::generate_and_score_moves() {
  scored_moves_.moves = move_gen::moves(move_type, board_);
  for (int i = 0; i < scored_moves_.moves.size(); i++) {
    if (scored_moves_.moves[i] == tt_move_) {
      scored_moves_.moves.erase(i);
    }
    scored_moves_.scores.push(score_move(scored_moves_.moves[i]));
  }
}

int MovePicker::score_move(Move &move) {
  const auto from = move.get_from();
  const auto to = move.get_to();

  // queen and knight promotions get priority
  switch (move.get_promotion_type()) {
    case PromotionType::kNone:
      break;
    case PromotionType::kQueen:
      return 1e9 - 1;
    case PromotionType::kKnight:
      return 1e9 - 2;
    default:
      return -1e9;
  }

  auto &state = board_.get_state();

  // winning/neutral captures are searched next
  // losing captures are searched last
  const int kBaseGoodCaptureScore = 1e8;
  const int kBaseBadCaptureScore = -1e8;
  if (move.is_capture(state)) {
    const auto attacker = state.get_piece_type(from);
    const auto victim = state.get_piece_type(to);
    const int mvv_lva_score =
        kMVVLVATable[to == state.en_passant && attacker == PieceType::kPawn ? PieceType::kPawn : victim][attacker];
    // good captures are searched first, bad captures are searched last
    if (eval::static_exchange(move, -eval::kSEEPieceScores[PieceType::kPawn], state)) {
      return kBaseGoodCaptureScore + mvv_lva_score;
    } else {
      return kBaseBadCaptureScore + mvv_lva_score;
    }
  }

  // killer moves are searched next (moves that caused a beta cutoff at this ply)
  /* const int kKillerMoveScore = kBaseGoodCaptureScore - 10;
  const auto &killers = move_history_.get_killers(search_stack_->ply);
  if (killers[0] == move) {
    return kKillerMoveScore;
  } else if (killers[1] == move) {
    return kKillerMoveScore - 1;
  } */

  // check if this move was a natural counter to the previous move (caused a beta cutoff)
  // complimentary to killer move heuristic
  /*const int kCounterMoveScore = kKillerMoveScore - 10;
  if (move == move_history_.get_counter(state.move_played)) {
    // counter moves should be searched right after killer moves
    return kCounterMoveScore;
  } */

  // order moves that caused a beta cutoff by their own history score
  // the higher the depth this move caused a cutoff the more likely it move will be ordered first
  return move_history_.get_history_score(move, state.turn);
}