#ifndef INTEGRAL_BOARD_H_
#define INTEGRAL_BOARD_H_

#include <memory>
#include <utility>

#include "bitboard.h"
#include "move.h"

struct BoardState {
  BoardState *prev_state;
  BitBoards pieces;
  Color turn_to_move;
  U32 full_moves;
  U32 half_moves;
  U8 castle_state;

  BoardState() {
    half_moves = 0;
    full_moves = 1;
    prev_state = nullptr;
    turn_to_move = Color::kWhite;
    castle_state = CastleBits::kWhiteKingside | CastleBits::kWhiteQueenside | CastleBits::kBlackKingside | CastleBits::kBlackQueenside;
  }
};

class Board {
 public:
  explicit Board(BoardState *state) {
    state_ = state;
  }

  BoardState *get_state() {
    return state_;
  }


  bool is_valid_move(Move move);

  void make_move(Move move, bool check_valid = true);

  void undo_move();

 private:
  BoardState *state_;
};

#endif // INTEGRAL_BOARD_H_
