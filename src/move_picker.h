#ifndef INTEGRAL_MOVE_PICKER_H_
#define INTEGRAL_MOVE_PICKER_H_

#include "move_gen.h"
#include "search.h"

struct ScoredMove {
  Move move;
  int score;

  explicit ScoredMove(Move &move, const int &score) : move(move), score(score) {}

  ScoredMove() : score(kScoreNone) {}
};

enum class MovePickerType {
  kSearch,
  kQuiescence
};

class MovePicker {
 public:
  MovePicker(MovePickerType type, Board &board, Move tt_move, Search::Stack *search_stack);

  Move next();

 private:
  ScoredMove &selection_sort(List<ScoredMove> &moves, const int &index);

  template<MoveType move_type>
  List<ScoredMove> generate_and_score_moves();

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
  Search::Stack *search_stack_;
  Stage stage_;
  List<ScoredMove> scored_moves_;
  int moves_idx_;
};

#endif // INTEGRAL_MOVE_PICKER_H_