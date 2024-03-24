#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "bitboard.h"
#include "board.h"
#include "types.h"

class MoveList {
 public:
  explicit MoveList(const std::array<Move, 256> &moves, int count) : moves_(moves), count_(count) {}

  MoveList() : moves_({}), count_(0) {}

  Move &operator[](int i) {
    assert(i >= 0 && i < count_);
    return moves_[i];
  }

  void push(const Move &move) {
    assert(count_ < moves_.size());
    moves_[count_++] = move;
  }

  void pop_back() {
    assert(count_ > 0);
    --count_;
  }

  [[nodiscard]] int size() const {
    return count_;
  }

  [[nodiscard]] int empty() const {
    return count_ == 0;
  }

 private:
  std::array<Move, 256> moves_;

  int count_;
};

// initializes piece attack lookups and magics
void initialize_attacks();

BitBoard generate_pawn_attacks(U8 pos, const BoardState &state);

BitBoard generate_pawn_moves(U8 pos, const BoardState &state);

BitBoard generate_knight_moves(U8 pos, const BoardState &state);

BitBoard generate_bishop_moves(U8 pos, const BoardState &state);

BitBoard generate_rook_moves(U8 pos, const BoardState &state);

BitBoard generate_king_moves(U8 pos, const BoardState &state, bool include_castling = true);

BitBoard generate_king_attacks(U8 pos, const BoardState &state);

BitBoard generate_castling_moves(const BoardState &state, Color which);

BitBoard get_attacked_squares(const BoardState &state, Color attacker, bool include_king_attacks = true);

bool king_in_check(Color color, const BoardState &state);

MoveList generate_moves(Board &board);

MoveList generate_legal_moves(Board &board);

MoveList generate_capture_moves(Board &board);

MoveList filter_moves(MoveList &moves, MoveType type, Board &board);

#endif // INTEGRAL_MOVE_GEN_H_