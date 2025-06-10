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
    kGenerateNoisies,
    kGoodNoisies,
    kFirstKiller,
    kSecondKiller,
    kGenerateQuiets,
    kGoodQuiets,
    kBadNoisies,
    kBadQuiets
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
  ScoredMove &SelectionSort(List<ScoredMove, kMaxMoves> &move_list, int index);

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
  List<ScoredMove, kMaxMoves> noisies_, bad_noisies_;
  List<ScoredMove, kMaxMoves> quiets_;
  int quiet_moves_idx_, noisy_moves_idx_;
  int see_threshold_;
  bool skip_quiets_;
};

}  // namespace search

#endif  // INTEGRAL_MOVE_PICKER_H_