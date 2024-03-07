#include "move_orderer.h"
#include "eval.h"

const int kTranspoTableMoveScore = 10000;
const int kCaptureScore = 1000;

MoveOrderer::MoveOrderer(Board &board, MoveList moves, MoveType move_type)
    : board_(board), moves_(std::move(moves)), move_type_(move_type) {
  score_moves();
}

const Move &MoveOrderer::get_move(int start) {
  // perform a selection sort for the next best move
  int best_score = move_scores_[start];
  int best_score_idx = start;

  for (int i = start + 1; i < moves_.size(); i++) {
    if (move_scores_[i] > best_score) {
      best_score = move_scores_[i];
      best_score_idx = i;
    }
  }

  std::swap(move_scores_[best_score_idx], move_scores_[start]);
  std::swap(moves_[best_score_idx], moves_[start]);

  return moves_[start];
}

[[nodiscard]] std::size_t MoveOrderer::size() const {
  return moves_.size();
}

void MoveOrderer::score_moves() {
  auto &state = board_.get_state();

  // we always want to get the stored best move for this position first if available
  auto tt_entry = board_.get_transpo_table().probe(state.zobrist_key);
  bool tt_move_exists = false;

  if (tt_entry->key == state.zobrist_key) {
    const auto is_capture = [&state](const Move &move) {
      return state.pieces[state.turn == Color::kWhite ? kBlackPieces : kWhitePieces].is_set(move.get_to());
    };

    if (move_type_ != MoveType::kCaptures || is_capture(tt_entry->best_move)) {
      moves_.insert(moves_.begin(), tt_entry->best_move);
      tt_move_exists = true;
    }
  }

  move_scores_.resize(moves_.size());
  for (int i = 0; i < moves_.size(); i++) {
    move_scores_[i] = i == 0 && tt_move_exists ? kTranspoTableMoveScore : calculate_move_score(moves_[i]);
  }
}

int MoveOrderer::calculate_move_score(const Move &move) {
  auto &state = board_.get_state();

  int score = 0;

  // will be +0 if move isn't a promotion move
  const auto promotion_type = move.get_promotion_type();
  score += eval::kPieceValues[static_cast<int>(promotion_type)];

  const auto move_piece_type = move.get_piece_type();
  const bool is_capture_move = state.pieces[state.turn == Color::kWhite ? kBlackPieces : kWhitePieces].is_set(move.get_to());

  if (is_capture_move) {
    const int aggressor_piece_value = eval::kPieceValues[static_cast<int>(move_piece_type)];
    const int victim_piece_value = eval::kPieceValues[static_cast<int>(get_piece_type(move.get_to(), state.pieces))];

    score += kCaptureScore + victim_piece_value * 10 - aggressor_piece_value;
  }

  return score;
}
