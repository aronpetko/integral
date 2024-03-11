#include "move_orderer.h"
#include "eval.h"

const int kTranspoTableMoveScore = 30000;
const int kCaptureMoveScore = 10000;
const int kKillerMoveScore = 5000;

std::array<std::array<Move, MoveOrderer::kNumKillerMoves>, Search::kMaxSearchDepth> MoveOrderer::killer_moves{};

std::array<std::array<std::array<int, Square::kSquareCount>, Square::kSquareCount>, 2> MoveOrderer::move_history{};

MoveOrderer::MoveOrderer(Board &board, MoveList moves, MoveType move_type) noexcept
    : board_(board), moves_(std::move(moves)), move_type_(move_type) {
  score_moves();
}

const Move &MoveOrderer::get_move(int start) noexcept {
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

void MoveOrderer::update_killer_move(const Move &move, int ply) {
  // shift killer moves right one
  for (std::size_t i = 1; i < MoveOrderer::killer_moves[ply].size(); i++)
    MoveOrderer::killer_moves[ply][i] = MoveOrderer::killer_moves[ply][i - 1];

  // insert at the beginning
  MoveOrderer::killer_moves[ply][0] = move;
}

void MoveOrderer::update_move_history(const Move &move, Color turn, int depth) {
  const int from = move.get_from();
  const int to = move.get_to();

  MoveOrderer::move_history[turn][from][to] += depth * depth;
}

void MoveOrderer::reset_move_history() {
  for (auto &plane : MoveOrderer::move_history) {
    for (auto &row : plane) {
      std::fill(row.begin(), row.end(), 0);
    }
  }
}

void MoveOrderer::score_moves() noexcept {
  std::vector<std::pair<int, Move>> valued_moves;

  auto &state = board_.get_state();

  // we always want to get the stored best move for this position first if available
  auto tt_entry = board_.get_transpo_table().probe(state.zobrist_key);
  bool tt_move_exists = false;

  if (tt_entry.key == state.zobrist_key) {
    const bool is_capture_move =
        state.pieces[state.turn == Color::kWhite ? kBlackPieces : kWhitePieces].is_set(tt_entry.best_move.get_to());

    if (move_type_ != MoveType::kCaptures || is_capture_move) {
      moves_.push({tt_entry.best_move});
      tt_move_exists = true;
    }
  }

  move_scores_.resize(moves_.size());
  for (int i = 0; i < moves_.size(); i++) {
    move_scores_[i] = i == moves_.size() - 1 && tt_move_exists ? kTranspoTableMoveScore : calculate_move_score(moves_[i]);
  }
}

int MoveOrderer::calculate_move_score(const Move &move) {
  auto &state = board_.get_state();

  for (int i = 0; i < kNumKillerMoves; i++) {
    for (const auto &killer_move : MoveOrderer::killer_moves[i]) {
      if (killer_move == move) {
        return kKillerMoveScore;
      }
    }
  }

  const auto from = move.get_from();
  const U8 to = move.get_to();

  int score = 0;

  // will be +0 if move isn't a promotion move
  score += eval::kPieceValues[static_cast<int>(move.get_promotion_type())];

  const auto move_piece_type = move.get_piece_type();
  const bool is_capture_move = state.pieces[state.turn == Color::kWhite ? kBlackPieces : kWhitePieces].is_set(to);

  // MVV-LVA
  if (is_capture_move) {
    const int aggressor_piece_value = eval::kPieceValues[move_piece_type];
    const int victim_piece_value = eval::kPieceValues[state.get_piece_type(to)];

    score += kCaptureMoveScore + victim_piece_value * 10 - aggressor_piece_value;
  } else {
    score += MoveOrderer::move_history[state.turn][from][to];
  }

  return score;
}