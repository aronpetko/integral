#ifndef INTEGRAL_ACCUMULATOR_H
#define INTEGRAL_ACCUMULATOR_H

#include <array>
#include <memory>

#include "../../../chess/board.h"
#include "../../../utils/types.h"

namespace nnue {

struct PieceChange {
  Square square = Squares::kNoSquare;
  PieceType piece = PieceType::kNone;
  Color color = Color::kNoColor;
};

// The pieces a move takes off the board and the ones it puts on it. A capture
// removes two pieces, and castling both removes and adds two
struct BoardChange {
  std::array<PieceChange, 2> removed, added;
  U8 num_removed = 0, num_added = 0;

  void Remove(Square square, PieceType piece, Color color) {
    removed[num_removed++] = {square, piece, color};
  }

  void Add(Square square, PieceType piece, Color color) {
    added[num_added++] = {square, piece, color};
  }
};

// The accumulators for every ply of the line being searched. The inference
// itself is done by MantaRay, which is kept out of this header so that only
// nnue.cc has to compile it
class Accumulator {
 public:
  Accumulator();
  ~Accumulator();

  void SetFromState(const BoardState& state);

  // `state` is the position after the move has been made
  void PushChanges(const BoardChange& change, const BoardState& state);
  // `state` is the position the undone move was made from
  void UndoMove(const BoardState& state);

  [[nodiscard]] Score Evaluate(const BoardState& state);

 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

}  // namespace nnue

#endif  // INTEGRAL_ACCUMULATOR_H
