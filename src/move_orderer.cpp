#include "move_orderer.h"

const std::array<std::array<int, PieceType::kNumPieceTypes>, PieceType::kNumPieceTypes> kMVVLVATable = {{
  {{10, 11, 12, 13, 14, 15}}, // victim P, attacker K, Q, R, B, N, P
  {{20, 21, 22, 23, 24, 25}}, // victim N, attacker K, Q, R, B, N, P
  {{30, 31, 32, 33, 34, 35}}, // victim B, attacker K, Q, R, B, N, P
  {{40, 41, 42, 43, 44, 45}}, // victim R, attacker K, Q, R, B, N, P
  {{50, 51, 52, 53, 54, 55}}, // victim Q, attacker K, Q, R, B, N, P
  {{0, 0, 0, 0, 0, 0}},       // victim K, attacker K, Q, R, B, N, P
}};

std::array<std::array<Move, MoveOrderer::kNumKillerMoves>, kMaxGameMoves> MoveOrderer::killer_moves{};

std::array<std::array<std::array<int, Square::kSquareCount>, Square::kSquareCount>, 2> MoveOrderer::move_history{};

MoveOrderer::MoveOrderer(Board &board, MoveList moves, MoveType move_type) noexcept
    : board_(board), moves_(moves), move_type_(move_type), move_scores_({}) {
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

const int kHistoryClamp = 8192;

void MoveOrderer::update_move_history(const Move &move, Color turn, int depth) {
  auto &move_history_score = MoveOrderer::move_history[turn][move.get_from()][move.get_to()];

  const int bonus = depth * depth;
  const int scaled_bonus = bonus - move_history_score * std::abs(bonus) / kHistoryClamp;

  move_history_score += scaled_bonus;
}

void MoveOrderer::penalize_move_history(MoveList& moves, Color turn, int depth) {
  const int bonus = depth * depth;
  for (int i = 0; i < moves.size(); i++) {
    const auto &move = moves[i];

    auto &move_history_score = MoveOrderer::move_history[turn][move.get_from()][move.get_to()];
    const int scaled_bonus = bonus - move_history_score * std::abs(bonus) / kHistoryClamp;

    move_history_score -= scaled_bonus;
  }
}

void MoveOrderer::reset_move_history() {
  for (auto &sides : MoveOrderer::move_history) {
    for (auto &moves : sides) {
      moves.fill(0);
    }
  }

  for (auto &killers : MoveOrderer::killer_moves) {
    killers.fill(Move::null_move());
  }
}

void MoveOrderer::score_moves() noexcept {
  auto &state = board_.get_state();

  // we always want to get the stored best move for this position first if available
  auto tt_entry = board_.get_transpo_table().probe(state.zobrist_key);
  auto tt_move = Move::null_move();

  if (tt_entry.key == state.zobrist_key && !tt_entry.move.is_null()) {
    const bool is_capture = tt_entry.move.is_capture(state);
    if (move_type_ != MoveType::kCaptures || is_capture) {
      tt_move = tt_entry.move;
    }
  }

  for (int i = 0; i < moves_.size(); i++)
    move_scores_[i] = calculate_move_score(moves_[i], tt_move);
}

int MoveOrderer::calculate_move_score(const Move &move, const Move &tt_move) {
  const int kMVVLVAScore = std::numeric_limits<int>::max() - 256;
  const int kMaxMoveScore = std::numeric_limits<int>::max();
  const int kKillerMoveScore = 15;

  auto &state = board_.get_state();

  const auto from = move.get_from();
  const auto to = move.get_to();

  const bool is_capture = move.is_capture(state);

  int score = 0;

  // tt move get priority since it's the current stored best move
  if (move == tt_move) {
    return kMaxMoveScore;
  }

  // moves that caused a beta cutoff
  bool is_killer = false;
  for (int i = 0; i < kNumKillerMoves; i++) {
    // if we've already found a killer (avoiding goto)
    if (is_killer) break;

    for (const auto &killer_move : MoveOrderer::killer_moves[i]) {
      if (killer_move == move) {
        // killer moves should get higher priority than bad captures
        score = kMVVLVAScore + (kNumKillerMoves - 1 - i) * kKillerMoveScore;
        is_killer = true;
        break;
      }
    }
  }

  if (is_capture) {
    // killer moves are already close to the base MVV-LVA score
    // therefore, if this move wasn't a killer, we set it to the base MVV-LVA score
    if (!is_killer) {
      score = kMVVLVAScore;
    }

    score += kMVVLVATable[state.get_piece_type(to)][state.get_piece_type(from)];
  } else if (!is_killer) {
    score += MoveOrderer::move_history[state.turn][from][to];
  }

  return score;
}