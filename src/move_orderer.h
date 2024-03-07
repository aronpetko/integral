#ifndef INTEGRAL_MOVE_ORDERER_H_
#define INTEGRAL_MOVE_ORDERER_H_

#include "move_gen.h"

class MoveOrderer {
 public:
  explicit MoveOrderer(Board &board, MoveList moves) : board_(board), moves_(std::move(moves)) {}

  const Move &get_next_move();

 private:
  int calculate_move_score(const Move &move);

 private:
  MoveList moves_;

  Board &board_;
};

#endif // INTEGRAL_MOVE_ORDERER_H_