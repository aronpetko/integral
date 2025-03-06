#ifndef INTEGRAL_MOVE_PICKER_H_
#define INTEGRAL_MOVE_PICKER_H_

#include <algorithm>

#include "../../chess/move_gen.h"
#include "../evaluation/evaluation.h"
#include "history/history.h"

namespace search {

TUNABLE(kPawnScore, 97, 50, 150, false);
TUNABLE(kKnightScore, 305, 200, 400, false);
TUNABLE(kBishopScore, 290, 200, 400, false);
TUNABLE(kRookScore, 537, 400, 600, false);
TUNABLE(kQueenScore, 906, 700, 1100, false);
TUNABLE(kKingScore, 0, 0, 0, true);  // Always 0
TUNABLE(kNoneScore, 0, 0, 0, true);  // Always 0

// clang-format off
inline std::array kPieceScores = {
  &kPawnScore,
  &kKnightScore,
  &kBishopScore,
  &kRookScore,
  &kQueenScore,
  &kKingScore,
  &kNoneScore
};

// clang-format on
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
    kFirstKiller,
    kSecondKiller,
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