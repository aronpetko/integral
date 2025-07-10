#ifndef INTEGRAL_MOVE_PICKER_H_
#define INTEGRAL_MOVE_PICKER_H_

#include <algorithm>

#include "../../chess/move_gen.h"
#include "../evaluation/evaluation.h"
#include "history/history.h"

namespace search {

struct ScoredMove {
  Move move;
  int score;
};

enum class MovePickerType {
  kSearch,
  kQuiescence,
  kNoisy = kQuiescence
};

class MovePicker {
 public:
  enum class Stage {
    kTTMove,
    kGenerateNoisys,
    kGoodNoisys,
    kGenerateQuiets,
    kQuiets,
    kBadNoisys,
  };

  MovePicker(MovePickerType type,
             Board &board,
             Move tt_move,
             history::History &history,
             StackEntry *stack,
             int see_threshold = 0);

  Move Next();

  void SkipQuiets();

  [[nodiscard]] Stage GetStage() const {
    return stage_;
  }

 private:
  Move &SelectionSort(List<ScoredMove, kMaxMoves> &move_list, int index);

  template <MoveGenType move_type>
  void GenerateAndScoreMoves(List<ScoredMove, kMaxMoves> &list);

  int ScoreMove(Move &move);

 private:
  Board &board_;
  Move tt_move_;
  MovePickerType type_;
  history::History &history_;
  StackEntry *stack_;
  Stage stage_;
  List<ScoredMove, kMaxMoves> noisys_, bad_noisys_;
  List<ScoredMove, kMaxMoves> quiets_;
  int moves_idx_;
  int see_threshold_;
};

}  // namespace search

#endif  // INTEGRAL_MOVE_PICKER_H_