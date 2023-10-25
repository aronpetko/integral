export module board;

import bitboard;
import types;

export enum CastleBits {
  kWhiteKingside = 0b0001,
  kWhiteQueenside = 0b0010,
  kBlackKingside = 0b0100,
  kBlackQueenside = 0b1000,
};

export struct BoardState {
  BitBoards   boards;
  U32         full_moves;
  U32         half_moves;
  U8          castle_state;
  Color       turn_to_move;

  BoardState() {
    half_moves = 0;
    full_moves = 1;
    turn_to_move = Color::kWhite;
    castle_state = CastleBits::kWhiteKingside | CastleBits::kWhiteQueenside | CastleBits::kBlackKingside | CastleBits::kBlackQueenside;
  }
};

export class Board {
 public:
  explicit Board(BoardState state) {
    state_ = state;
  }

  BoardState get_state() {
    return state_;
  }

 private:
  BoardState state_;
};