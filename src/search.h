#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include "board.h"
#include "eval.h"
#include "time_mgmt.h"

class Search {
 public:
  explicit Search(TimeManagement::Config &time_config, Board &board);

  Move find_best_move();

 private:
  int quiesce(int ply, int alpha, int beta);

  int negamax(int depth, int ply, int alpha, int beta);

 private:
  Board &board_;

  TimeManagement time_mgmt_;

  Move best_move_this_iteration_;

  int best_eval_this_iteration_;

  double branching_factor_;

  int total_bfs_;

  bool following_pv_;

 public:
  static constexpr int kMaxSearchDepth = 100;
};

#endif // INTEGRAL_SEARCH_H_