#ifndef INTEGRAL_MOVE_PICKER_H_
#define INTEGRAL_MOVE_PICKER_H_

#include "../chess/move_gen.h"
#include "history.h"
#include "search.h"

struct ScoredMoveList {
  List<Move, kMaxMoves> moves;
  List<int, kMaxMoves> scores;
};

enum class MovePickerType { kSearch, kQuiescence };

class MovePicker {
 public:
  MovePicker(MovePickerType type, Board &board, Move tt_move, MoveHistory &move_history, Search::Stack *search_stack);

  Move next();

 private:
  Move &selection_sort(ScoredMoveList &move_list, const int &index);

  template <MoveType move_type>
  void generate_and_score_moves();

  int score_move(Move &move);

 private:
  enum class Stage {
    kTTMove,
    kGenerateMoves,
    kPlayMoves,
    kGenerateCaptures,
    kGoodCaptures,
    kFirstKiller,
    kSecondKiller,
    kCounterMove,
    kGenerateQuiets,
    kQuiets,
    kBadCaptures,
  };

  Board &board_;
  Move tt_move_;
  MovePickerType type_;
  MoveHistory &move_history_;
  Search::Stack *search_stack_;
  Stage stage_;
  ScoredMoveList scored_moves_;
  int moves_idx_;
};

#endif  // INTEGRAL_MOVE_PICKER_H_