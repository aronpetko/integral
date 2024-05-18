#ifndef INTEGRAL_HISTORY_H
#define INTEGRAL_HISTORY_H

#include <array>

#include "../chess/move_gen.h"

class SearchStack;

constexpr int kFromToCombinations = Square::kSquareCount * Square::kSquareCount;

using KillerMoves = std::array<std::array<Move, 2>, kMaxPlyFromRoot>;
using ButterflyHistory = std::array<std::array<int, kFromToCombinations>, 2>;
using ContinuationEntry = std::array<std::array<std::array<int, 64>, 6>, 2>;
using ContinuationHistory =
    std::array<std::array<std::array<ContinuationEntry, 64>, 6>, 2>;

class MoveHistory {
 public:
  explicit MoveHistory(const BoardState &state);

  int GetHistoryScore(Move move, Color turn) noexcept;

  int GetContHistoryScore(Move move,
                          int plies_ago,
                          SearchStack *stack) noexcept;

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
                         SearchStack *stack);

  void Clear();

  void ClearKillers();

  void ClearKillers(U16 ply);

 private:
  const BoardState &state_;
  KillerMoves killer_moves_;
  ButterflyHistory butterfly_history_;
  std::unique_ptr<ContinuationHistory> cont_history_;
};

#endif  // INTEGRAL_HISTORY_H