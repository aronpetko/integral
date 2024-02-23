#ifndef INTEGRAL_BOARD_H_
#define INTEGRAL_BOARD_H_

#include <vector>
#include <memory>
#include <utility>

#include "bitboard.h"
#include "move.h"

struct BoardState {
  BitBoards pieces;
  Move move;
  Color turn;
  U32 full_moves;
  U32 half_moves;
  U8 castle_state;
  std::optional<Square> en_passant;

  BoardState() {
    half_moves = 0;
    full_moves = 1;
    turn = Color::kWhite;
    castle_state = CastleRights::kWhiteKingside | CastleRights::kWhiteQueenside | CastleRights::kBlackKingside | CastleRights::kBlackQueenside;
  }

  BoardState(const BoardState &other) = default;
};

class Board {
 public:
  explicit Board(std::unique_ptr<BoardState> state) : state_(std::move(state)) {}

  std::unique_ptr<BoardState> &get_state() {
    return state_;
  }

  bool is_legal_move(const Move &move);

  void make_move(const Move &move, bool check_valid = true);

  void undo_move();

 private:
  void handle_castling(const Move &move);

  void handle_promotions(const Move &move);

 private:
  std::unique_ptr<BoardState> state_;
  std::vector<std::unique_ptr<BoardState>> history_;
};

#endif // INTEGRAL_BOARD_H_