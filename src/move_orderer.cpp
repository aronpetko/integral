#include "move_orderer.h"
#include "eval.h"

const int kMVVLVAScore = std::numeric_limits<int>::max() - 256;
const int kTTMoveScore = std::numeric_limits<int>::max();
const int kKillerMoveValue = 10;

// credits: rustic chess engine
const std::array<std::array<int, PieceType::kNumPieceTypes>, PieceType::kNumPieceTypes> kMVVLVATable = {{
  {{0, 0, 0, 0, 0, 0}},       // victim none, attacker K, Q, R, B, N, P
  {{10, 11, 12, 13, 14, 15}}, // victim P, attacker K, Q, R, B, N, P
  {{20, 21, 22, 23, 24, 25}}, // victim N, attacker K, Q, R, B, N, P
  {{30, 31, 32, 33, 34, 35}}, // victim B, attacker K, Q, R, B, N, P
  {{40, 41, 42, 43, 44, 45}}, // victim R, attacker K, Q, R, B, N, P
  {{50, 51, 52, 53, 54, 55}}, // victim Q, attacker K, Q, R, B, N, P
  {{0, 0, 0, 0, 0, 0}},       // victim K, attacker K, Q, R, B, N, P
}};

std::array<std::array<Move, MoveOrderer::kNumKillerMoves>, Search::kMaxSearchDepth> MoveOrderer::killer_moves{};

std::array<std::array<std::array<int, Square::kSquareCount>, Square::kSquareCount>, 2> MoveOrderer::move_history{};

MoveOrderer::MoveOrderer(Board &board, MoveList moves, MoveType move_type) noexcept
    : board_(board), moves_(moves), move_type_(move_type) {
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
  if (move == MoveOrderer::killer_moves[ply][0])
    return;

  // shift killer moves right one
  for (std::size_t i = 1; i < kNumKillerMoves; i++)
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

  for (auto &row : MoveOrderer::killer_moves) {
    std::fill(row.begin(), row.end(), Move::null_move());
  }
}

void MoveOrderer::score_moves() noexcept {
  auto &state = board_.get_state();

  // we always want to get the stored best move for this position first if available
  auto tt_entry = board_.get_transpo_table().probe(state.zobrist_key);
  auto tt_move = Move::null_move();

  if (tt_entry.key == state.zobrist_key && tt_entry.best_move != Move::null_move()) {
    const auto to = tt_entry.best_move.get_to();
    const bool is_capture_move = state.piece_types[to] != PieceType::kNone ||
        (state.en_passant.has_value() && state.en_passant == to);

    if (move_type_ != MoveType::kCaptures || is_capture_move) {
      tt_move = tt_entry.best_move;
    }
  }

  for (int i = 0; i < moves_.size(); i++)
    move_scores_[i] = calculate_move_score(moves_[i], tt_move);
}

int MoveOrderer::calculate_move_score(const Move &move, const Move &tt_move) {
  auto &state = board_.get_state();

  const auto from = move.get_from();
  const auto to = move.get_to();

  const auto move_piece_type = state.piece_types[from];
  const bool is_capture_move = state.piece_types[to] != PieceType::kNone ||
      (state.en_passant.has_value() && state.en_passant == to);

  if (move == tt_move) {
    return kTTMoveScore;
  } else if (is_capture_move) {
    return kMVVLVAScore + kMVVLVATable[state.get_piece_type(to)][move_piece_type];
  } else {
    for (int i = 0; i < kNumKillerMoves; i++) {
      for (const auto &killer_move : MoveOrderer::killer_moves[i]) {
        if (killer_move == move) {
          return kMVVLVAScore - (i + 1) * kKillerMoveValue;
        }
      }
    }

    return MoveOrderer::move_history[state.turn][from][to];
  }
}