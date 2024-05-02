#include "history.h"

#include "search.h"

const int kHistoryGravity = 16384;
const int kHistoryScale = 130;
const int kHistoryMaxBonus = 1159;

int HistoryBonus(int depth) {
  return std::min(kHistoryScale * depth, kHistoryMaxBonus);
}

// Linear interpolation of the bonus and maximum score
short ScaleBonus(int score, int bonus) {
  return bonus - score * std::abs(bonus) / kHistoryGravity;
}

// Flatten the move to an index
inline int MoveIndex(Move move) {
  return move.GetFrom() * Square::kSquareCount + move.GetTo();
}

MoveHistory::MoveHistory(const BoardState &state)
    : state_(state),
      killer_moves_({}),
      cont_history_({}),
      butterfly_history_({}) {}

short MoveHistory::GetHistoryScore(Move move, Color turn) noexcept {
  return butterfly_history_[turn][MoveIndex(move)];
}

std::array<Move, 2> &MoveHistory::GetKillers(int ply) {
  assert(ply >= 0 && ply < kMaxPlyFromRoot);
  return killer_moves_[ply];
}
void MoveHistory::UpdateKillerMove(Move move, int ply) {
  if (move == killer_moves_[ply][0]) return;

  killer_moves_[ply][1] = killer_moves_[ply][0];
  killer_moves_[ply][0] = move;
}

void MoveHistory::UpdateHistory(Move move,
                                List<Move, kMaxMoves> &bad_quiets,
                                Color turn,
                                int depth) {
  const int bonus = HistoryBonus(depth);

  // Apply a linear dampening to the bonus as the depth increases
  short &score = butterfly_history_[turn][MoveIndex(move)];
  score += ScaleBonus(score, bonus);

  // Lower the score of the quiet moves that failed to raise alpha
  const int penalty = -bonus;
  for (int i = 0; i < bad_quiets.Size(); i++) {
    const auto &bad_quiet = bad_quiets[i];

    // Apply a linear dampening to the penalty as the depth increases
    short &bad_quiet_score = butterfly_history_[turn][MoveIndex(bad_quiet)];
    bad_quiet_score += ScaleBonus(bad_quiet_score, penalty);
  }
}

void MoveHistory::Decay() {
  for (auto &killers : killer_moves_) {
    killers.fill(Move::NullMove());
  }
}

void MoveHistory::Clear() {
  for (auto &sides : butterfly_history_) {
    for (auto &move_scores : sides) {
      move_scores = 0;
    }
  }
  for (auto &killers : killer_moves_) {
    killers.fill(Move::NullMove());
  }
}

void MoveHistory::ClearKillers(int ply) {
  killer_moves_[ply].fill(Move::NullMove());
}