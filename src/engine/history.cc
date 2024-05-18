#include "history.h"

#include "search.h"

constexpr int kHistoryGravity = 16384;
constexpr int kHistoryScale = 130;
constexpr int kHistoryMaxBonus = 1159;

int HistoryBonus(int depth) {
  return std::min(kHistoryScale * depth, kHistoryMaxBonus);
}

// Linear interpolation of the bonus and maximum score
int ScaleBonus(Score score, int bonus) {
  return bonus - score * std::abs(bonus) / kHistoryGravity;
}

// Flatten the move to an index
inline int MoveIndex(Move move) {
  return move.GetFrom() * Square::kSquareCount + move.GetTo();
}

MoveHistory::MoveHistory(const BoardState &state)
    : state_(state),
      killer_moves_({}),
      cont_history_(std::make_unique<ContinuationHistory>()),
      butterfly_history_({}) {}

int MoveHistory::GetHistoryScore(Move move, Color turn) noexcept {
  return butterfly_history_[turn][MoveIndex(move)];
}

int MoveHistory::GetContHistoryScore(Move move,
                                     int plies_ago,
                                     SearchStack *stack) noexcept {
  // Ensure the continuation history table exists for this move
  if ((stack - plies_ago)->move) {
    const auto piece = state_.GetPieceType(move.GetFrom());
    const auto to = move.GetTo();
    return (*(stack - plies_ago)->cont_entry)[state_.turn][piece][to];
  }

  return 0;
}

ContinuationEntry *MoveHistory::GetContEntry(Move move, Color turn) noexcept {
  if (!move) {
    return nullptr;
  }
  const auto from = move.GetFrom(), to = move.GetTo();
  return &(*cont_history_)[turn][state_.GetPieceType(from)][to];
}

std::array<Move, 2> &MoveHistory::GetKillers(U16 ply) {
  assert(ply >= 0 && ply < kMaxPlyFromRoot);
  return killer_moves_[ply];
}
void MoveHistory::UpdateKillerMove(Move move, U16 ply) {
  if (move != killer_moves_[ply][0]) {
    killer_moves_[ply][1] = killer_moves_[ply][0];
    killer_moves_[ply][0] = move;
  }
}

void MoveHistory::UpdateHistory(Move move,
                                List<Move, kMaxMoves> &bad_quiets,
                                Color turn,
                                int depth) {
  const int bonus = HistoryBonus(depth);

  // Apply a linear dampening to the bonus as the depth increases
  int &score = butterfly_history_[turn][MoveIndex(move)];
  score += ScaleBonus(score, bonus);

  // Lower the score of the quiet moves that failed to raise alpha
  const int penalty = -bonus;
  for (int i = 0; i < bad_quiets.Size(); i++) {
    // Apply a linear dampening to the penalty as the depth increases
    int &bad_quiet_score = butterfly_history_[turn][MoveIndex(bad_quiets[i])];
    bad_quiet_score += ScaleBonus(bad_quiet_score, penalty);
  }
}

void MoveHistory::UpdateContHistory(Move move,
                                    List<Move, kMaxMoves> &bad_quiets,
                                    Color turn,
                                    int depth,
                                    SearchStack *stack) {
  const auto update_cont_entry = [this, &turn, &stack](
                                     Move move, int plies_ago, int bonus) {
    const int piece = state_.GetPieceType(move.GetFrom());
    const int to = move.GetTo();

    // Ensure the continuation history table exists for this move
    if ((stack - plies_ago)->move) {
      int &score = (*(stack - plies_ago)->cont_entry)[turn][piece][to];
      score += ScaleBonus(score, bonus);
    }
  };

  const int bonus = HistoryBonus(depth);
  update_cont_entry(move, 1, bonus);
  update_cont_entry(move, 2, bonus);

  // Lower the score of the quiet moves that failed to raise alpha
  const int penalty = -bonus;
  for (int i = 0; i < bad_quiets.Size(); i++) {
    // Apply a linear dampening to the penalty as the depth increases
    update_cont_entry(bad_quiets[i], 1, penalty);
    update_cont_entry(bad_quiets[i], 2, penalty);
  }
}

void MoveHistory::ClearKillers() {
  for (auto &killers : killer_moves_) {
    killers.fill(Move::NullMove());
  }
}

void MoveHistory::Clear() {
  butterfly_history_ = ButterflyHistory();
  killer_moves_ = KillerMoves();
  cont_history_ = std::make_unique<ContinuationHistory>();
}

void MoveHistory::ClearKillers(U16 ply) {
  killer_moves_[ply].fill(Move::NullMove());
}