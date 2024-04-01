#include "move_orderer.h"

const std::array<std::array<int, PieceType::kNumPieceTypes>, PieceType::kNumPieceTypes + 1> kMVVLVATable = {{
                                                                                                                {{10, 11, 12, 13, 14, 15}}, // victim P,    attacker K, Q, R, B, N, P
                                                                                                                {{20, 21, 22, 23, 24, 25}}, // victim N,    attacker K, Q, R, B, N, P
                                                                                                                {{30, 31, 32, 33, 34, 35}}, // victim B,    attacker K, Q, R, B, N, P
                                                                                                                {{40, 41, 42, 43, 44, 45}}, // victim R,    attacker K, Q, R, B, N, P
                                                                                                                {{50, 51, 52, 53, 54, 55}}, // victim Q,    attacker K, Q, R, B, N, P
                                                                                                                {{0, 0, 0, 0, 0, 0}},       // victim K,    attacker K, Q, R, B, N, P
                                                                                                                {{0, 0, 0, 0, 0, 0}},       // victim None, attacker K, Q, R, B, N, P
                                                                                                            }};

std::array<std::array<Move, MoveOrderer::kNumKillerMoves>, kMaxPlyFromRoot> MoveOrderer::killer_moves{};
std::array<std::array<Move, Square::kSquareCount>, Square::kSquareCount> MoveOrderer::counter_moves{};
std::array<std::array<std::array<int, Square::kSquareCount>, Square::kSquareCount>, 2> MoveOrderer::move_history{};

MoveOrderer::MoveOrderer(Board &board, MoveList moves, MoveType move_type, const int &ply) noexcept
    : board_(board), moves_(moves), move_type_(move_type), move_scores_({}), ply_(ply) {
  score_moves();
}

const Move &MoveOrderer::get_move(int start) noexcept {
  // perform a selection sort for the next best move
  for (int i = start + 1; i < moves_.size(); i++) {
    if (move_scores_[i] > move_scores_[start]) {
      std::swap(move_scores_[start], move_scores_[i]);
      std::swap(moves_[start], moves_[i]);
    }
  }

  return moves_[start];
}

const int &MoveOrderer::get_move_score(int start) noexcept {
  return move_scores_[start];
}

const int &MoveOrderer::get_history_score(const Move &move, Color turn) noexcept {
  return MoveOrderer::move_history[turn][move.get_from()][move.get_to()];
}

[[nodiscard]] std::size_t MoveOrderer::size() const {
  return moves_.size();
}

void MoveOrderer::update_killer_move(const Move &move, int ply) {
  if (move == MoveOrderer::killer_moves[ply][0])
    return;

  MoveOrderer::killer_moves[ply][1] = MoveOrderer::killer_moves[ply][0];
  MoveOrderer::killer_moves[ply][0] = move;
}

void MoveOrderer::update_counter_move(const Move &prev_move, const Move &counter) {
  if (prev_move != Move::null_move()) {
    counter_moves[prev_move.get_from()][prev_move.get_to()] = counter;
  }
}

const int kHistoryCap = 8192;

void MoveOrderer::update_move_history(const Move &move, MoveList& quiet_non_cutoffs, Color turn, int depth) {
  auto &move_history_score = MoveOrderer::move_history[turn][move.get_from()][move.get_to()];

  // apply a linear dampening to the bonus as the depth increases
  const int bonus = depth * depth;
  const int scaled_bonus = bonus - move_history_score * std::abs(bonus) / kHistoryCap;
  move_history_score += scaled_bonus;

  // lower the score of the quiet moves that did not cause a beta cutoff
  // a good side effect of this is that moves that caused a beta cutoff earlier and were awarded a bonus but no longer cause a beta cutoff are eventually "discarded"
  penalize_move_history(quiet_non_cutoffs, turn, depth);
}

void MoveOrderer::penalize_move_history(MoveList& moves, Color turn, int depth) {
  const int bonus = depth * depth;
  for (int i = 0; i < moves.size(); i++) {
    const auto &move = moves[i];
    auto &move_history_score = MoveOrderer::move_history[turn][move.get_from()][move.get_to()];

    // apply a linear dampening to the bonus (penalty here) as the depth increases
    const int scaled_bonus = bonus - move_history_score * std::abs(bonus) / kHistoryCap;
    move_history_score -= scaled_bonus;
  }
}

void MoveOrderer::clear_move_history() {
  for (auto &sides : MoveOrderer::move_history) {
    for (auto &moves : sides) {
      moves.fill(0);
    }
  }
  for (auto &killers : MoveOrderer::killer_moves) {
    killers.fill(Move::null_move());
  }
  for (auto &counters : MoveOrderer::counter_moves) {
    counters.fill(Move::null_move());
  }
}

void MoveOrderer::clear_killers(int ply) {
  MoveOrderer::killer_moves[ply].fill(Move::null_move());
}

void MoveOrderer::score_moves() noexcept {
  auto &state = board_.get_state();

  // we always want to get the stored best move for this position first if available
  auto tt_entry = board_.get_transpo_table().probe(state.zobrist_key);
  auto tt_move = Move::null_move();

  if (tt_entry.key == state.zobrist_key && !tt_entry.move.is_null()) {
    if (move_type_ != MoveType::kTactical || tt_entry.move.is_tactical(state)) {
      tt_move = tt_entry.move;
    }
  }

  for (int i = 0; i < moves_.size(); i++) {
    move_scores_[i] = calculate_move_score(moves_[i], tt_move);
  }
}

int MoveOrderer::calculate_move_score(const Move &move, const Move &tt_move) const {
  auto &state = board_.get_state();

  const auto from = move.get_from();
  const auto to = move.get_to();

  // tt move get priority since it's the current stored best move
  if (move == tt_move) {
    return std::numeric_limits<int>::max();
  }

  // queen and knight promotions get next priority
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

  // winning/neutral captures are searched next
  // losing captures are searched last
  const int kBaseGoodCaptureScore = 1e8;
  const int kBaseBadCaptureScore = -1e8;
  if (move.is_capture(state)) {
    const auto attacker = state.get_piece_type(from);
    const auto victim = state.get_piece_type(to);

    const int mvv_lva_score =
        kMVVLVATable[attacker][to == state.en_passant && attacker == PieceType::kPawn ? PieceType::kPawn : victim];
    return eval::static_exchange(move, -eval::kSEEPieceScores[PieceType::kPawn], state) ?
      kBaseGoodCaptureScore + mvv_lva_score : mvv_lva_score + MoveOrderer::move_history[state.turn][from][to];
  }

  // no point is scoring moves that the quiescent search will not look at
  if (move_type_ == MoveType::kTactical) {
    return std::numeric_limits<int>::min();
  }

  // killer moves are searched next (moves that caused a beta cutoff at this ply)
  const int kKillerMoveScore = kBaseGoodCaptureScore - 10;
  for (int i = 0; i < kNumKillerMoves; i++) {
    if (MoveOrderer::killer_moves[ply_][i] == move) {
      return kKillerMoveScore;
    }
  }

  // check if this move was a natural counter to the previous move (caused a beta cutoff)
  // complimentary to killer move heuristic
  const int kCounterMoveScore = kKillerMoveScore - 10;
  const auto &last_move = state.move_played;
  if (move == MoveOrderer::counter_moves[last_move.get_from()][last_move.get_to()]) {
    // counter moves should be searched right after killer moves
    return kCounterMoveScore;
  }

  // order moves that caused a beta cutoff by their own history score
  // the higher the depth this move caused a cutoff the more likely it move will be ordered first
  return MoveOrderer::move_history[state.turn][from][to];
}