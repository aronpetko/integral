#ifndef INTEGRAL_MOVE_ORDERER_H_
#define INTEGRAL_MOVE_ORDERER_H_

#include "move_gen.h"

class MoveOrderer {
 public:
  explicit MoveOrderer(Board &board, MoveList moves, MoveType move_type);

  const Move &get_move(int start);

  [[nodiscard]] std::size_t size() const;

 private:
  void score_moves();

  int calculate_move_score(const Move &move);

 private:
  MoveList moves_;

  std::vector<int> move_scores_;

  Board &board_;

  MoveType move_type_;
};

#endif // INTEGRAL_MOVE_ORDERER_H_