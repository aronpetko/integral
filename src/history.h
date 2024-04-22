#ifndef INTEGRAL_HISTORY_H
#define INTEGRAL_HISTORY_H

#include "move_gen.h"

#include <array>

class MoveHistory {
 public:
  explicit MoveHistory(const BoardState &state);

  const int &get_history_score(Move move, Color turn) noexcept;

  std::array<Move, 2> &get_killers(int ply);

  Move &get_counter(Move move);

  void update_killer_move(Move move, int ply);

  void update_counter_move(Move prev_move, Move counter);

  void update_move_history(Move move, List<Move, kMaxMoves>& quiet_non_cutoffs, Color turn, int depth);

  void decay_move_history();

  void clear_killers(int ply);

 private:
  void penalize_move_history(List<Move, kMaxMoves>& moves, Color turn, int depth);

 private:
  const BoardState &state_;
  std::array<std::array<Move, 2>, kMaxPlyFromRoot> killer_moves_;
  std::array<std::array<Move, Square::kSquareCount>, Square::kSquareCount> counter_moves_;
  std::array<std::array<std::array<int, Square::kSquareCount>, Square::kSquareCount>, 2> butterfly_history_;
};

#endif  // INTEGRAL_HISTORY_H