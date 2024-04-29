#ifndef INTEGRAL_MOVE_PICKER_H_
#define INTEGRAL_MOVE_PICKER_H_

#include "../chess/move_gen.h"
#include "history.h"
#include "search.h"

#include <algorithm>

struct ScoredMove {
  Move move;
  int score;
};

enum class MovePickerType {
  kSearch,
  kQuiescence
};

class MovePicker {
 public:
  MovePicker(MovePickerType type, Board &board, Move tt_move, MoveHistory &move_history, Search::Stack *search_stack);

  Move next();

  int stage();

 private:
  Move &selection_sort(List<ScoredMove, kMaxMoves> &move_list, const int &index);

  template <MoveType move_type>
  void generate_and_score_moves(List<ScoredMove, kMaxMoves> &list);

  int score_move(Move &move);

 private:
  enum class Stage {
    kTTMove,
    kGenerateTacticals,
    kGoodTacticals,
    kFirstKiller,
    kSecondKiller,
    kGenerateQuiets,
    kQuiets,
    kBadTacticals,
  };

  Board &board_;
  Move tt_move_;
  MovePickerType type_;
  MoveHistory &move_history_;
  Search::Stack *search_stack_;
  Stage stage_;
  List<ScoredMove, kMaxMoves> tacticals_, bad_tacticals_;
  List<ScoredMove, kMaxMoves> quiets_;
  int moves_idx_;
};

#endif  // INTEGRAL_MOVE_PICKER_H_