#ifndef INTEGRAL_HISTORY_H
#define INTEGRAL_HISTORY_H

#include "../chess/move_gen.h"
#include "../utils/multi_array.h"

class SearchStackEntry;

constexpr int kFromToCombinations = kSquareCount * kSquareCount;

using KillerMoves = MultiArray<Move, kMaxPlyFromRoot, 2>;
using ButterflyHistory = MultiArray<int, 2, kFromToCombinations>;
using ContinuationEntry = MultiArray<int, 2, 6, 64>;
using ContinuationHistory = MultiArray<ContinuationEntry, 2, 6, 64>;

class MoveHistory {
 public:
  explicit MoveHistory(const BoardState &state);

  int GetHistoryScore(Move move, Color turn) noexcept;

  int GetContHistoryScore(Move move,
                          int plies_ago,
                          SearchStackEntry *stack) noexcept;

  ContinuationEntry *GetContEntry(Move move, Color turn) noexcept;

  std::array<Move, 2> &GetKillers(U16 ply);

  void UpdateKillerMove(Move move, U16 ply);

  void UpdateHistory(Move move,
                     List<Move, kMaxMoves> &bad_quiets,
                     Color turn,
                     int depth);

  void UpdateContHistory(Move move,
                         List<Move, kMaxMoves> &bad_quiets,
                         Color turn,
                         int depth,
                         SearchStackEntry *stack);

  void Clear();

  void ClearKillers();

  void ClearKillers(U16 ply);

 private:
  const BoardState &state_;
  KillerMoves killer_moves_;
  std::unique_ptr<ButterflyHistory> butterfly_history_;
  std::unique_ptr<ContinuationHistory> cont_history_;
};

#endif  // INTEGRAL_HISTORY_H