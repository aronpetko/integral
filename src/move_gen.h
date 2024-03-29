#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "bitboard.h"
#include "board.h"
#include "types.h"

class MoveList {
 public:
  explicit MoveList(const std::array<Move, 256> &moves, int count) : moves_(moves), count_(count) {}

  MoveList() : count_(0) {}

  inline Move &operator[](int i) {
    assert(i >= 0 && i < count_);
    return moves_[i];
  }

  inline void push(const Move &move) {
    assert(count_ < moves_.size());
    moves_[count_++] = move;
  }

  inline void pop_back() {
    assert(count_ > 0);
    --count_;
  }

  [[nodiscard]] inline int size() const {
    return count_;
  }

  [[nodiscard]] inline int empty() const {
    return count_ == 0;
  }

 private:
  std::array<Move, 256> moves_;
  int count_;
};

namespace move_gen {

// initializes piece attack lookups and magics
void initialize_attacks();

BitBoard pawn_attacks(U8 pos, const BoardState &state, Color which = Color::kNoColor);

BitBoard pawn_moves(U8 pos, const BoardState &state);

BitBoard knight_moves(U8 pos);

BitBoard bishop_moves(U8 pos, const BitBoard &occupied);

BitBoard rook_moves(U8 pos, const BitBoard &occupied);

BitBoard king_moves(U8 pos, const BoardState &state);

BitBoard king_attacks(U8 pos);

BitBoard castling_moves(Color which, const BoardState &state);

BitBoard get_attacked_squares(const BoardState &state, Color attacker, bool include_king_attacks = true);

bool king_in_check(Color color, const BoardState &state);

MoveList moves(Board &board);

MoveList legal_moves(Board &board);

MoveList capture_moves(Board &board);

MoveList filter_moves(MoveList &moves, MoveType type, Board &board);

}

#endif // INTEGRAL_MOVE_GEN_H_