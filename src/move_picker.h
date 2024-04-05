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
  MovePicker(MovePickerType type, Board &board, const Move &tt_move, Search::Stack *search_stack);

  Move next();

 private:
  ScoredMove &selection_sort(List<ScoredMove> &moves, const int &index);

  template<MoveType move_type>
  List<ScoredMove> generate_and_score_moves();

  int score_move(Move &move);

 private:
  enum class Stage {
    kTTMove,
    kGenerateCaptures,
    kGoodCaptures,
    kFirstKiller,
    kSecondKiller,
    kCounterMove,
    kGenerateQuiets,
    kQuiets,
    kBadCaptures,
    kFinished
  };

  Board &board_;
  const Move &tt_move_;
  MovePickerType type_;
  Search::Stack *search_stack_;
  Stage stage_;
  List<ScoredMove> captures_;
  List<ScoredMove> good_captures_;
  List<ScoredMove> bad_captures_;
  List<ScoredMove> quiets_;
  int good_captures_idx_;
  int bad_captures_idx_;
  int quiets_idx_;
};

#endif //INTEGRAL_MOVE_PICKER_H_