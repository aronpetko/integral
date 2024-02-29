#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include "board.h"
#include "eval.h"

#include <algorithm>
#include <ranges>

namespace search {

inline int nodes_searched = 0;

MoveList order_moves(Board &board, const MoveList &moves);

Move find_best_move(Board &board);

}

#endif // INTEGRAL_SEARCH_H_