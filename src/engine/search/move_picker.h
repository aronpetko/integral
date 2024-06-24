#ifndef INTEGRAL_MOVE_PICKER_H_
#define INTEGRAL_MOVE_PICKER_H_

#include <algorithm>

#include "../../chess/move_gen.h"
#include "../evaluation/evaluation.h"
#include "history/history.h"

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
  enum class Stage {
    kTTMove,
    kGenerateTacticals,
    kGoodTacticals,
    kQSTacticals,  // Used in quiescent search
    kFirstKiller,
    kSecondKiller,
    kGenerateQuiets,
    kQuiets,
    kBadTacticals,
  };

  MovePicker(MovePickerType type,
             Board &board,
             Move tt_move,
             history::SearchHistory &history,
             SearchStackEntry *stack);

  Move Next();

  void SkipQuiets();

  [[nodiscard]] Stage GetStage() const {
    return stage_;
  }

 private:
  Move &SelectionSort(List<ScoredMove, kMaxMoves> &move_list, const int &index);

  template <MoveType move_type>
  void GenerateAndScoreMoves(List<ScoredMove, kMaxMoves> &list);

  int ScoreMove(Move &move);

 private:
  Board &board_;
  Move tt_move_;
  MovePickerType type_;
  history::SearchHistory &history_;
  SearchStackEntry *stack_;
  Stage stage_;
  List<ScoredMove, kMaxMoves> tacticals_, bad_tacticals_;
  List<ScoredMove, kMaxMoves> quiets_;
  int moves_idx_;
};

#endif  // INTEGRAL_MOVE_PICKER_H_