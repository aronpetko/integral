#ifndef INTEGRAL_MOVE_ORDERER_H_
#define INTEGRAL_MOVE_ORDERER_H_

#include "move_gen.h"
#include "search.h"

class MoveOrderer {
 public:
  explicit MoveOrderer(Board &board, MoveList moves, MoveType move_type) noexcept;

  const Move &get_move(int start) noexcept;

  [[nodiscard]] std::size_t size() const;

  static void update_killer_move(const Move &move, int ply);

 private:
  void score_moves() noexcept;

  int calculate_move_score(const Move &move);

 private:
  Board &board_;

  MoveList moves_;

  MoveType move_type_;

  std::vector<int> move_scores_;

  static const int kNumKillerMoves = 2;

  static std::array<std::array<Move, kNumKillerMoves>, search::kMaxDepth> killer_moves;
};

#endif // INTEGRAL_MOVE_ORDERER_H_