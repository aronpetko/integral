#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "bitboard.h"
#include "board.h"
#include "types.h"

template<class T>
class List {
 public:
  explicit List(const std::array<T, 256> &container, int count) : container_(container), count_(count) {}

  List() : count_(0) {}

  inline T &operator[](int i) {
    assert(i >= 0 && i < count_);
    return container_[i];
  }

  inline void push(const T &object) {
    assert(count_ < container_.size());
    container_[count_++] = object;
  }

  inline void pop_back() {
    assert(count_ > 0);
    --count_;
  }

  inline void erase(int i) {
    std::swap(container_[i], container_[--count_]);
  }

  [[nodiscard]] inline int size() const {
    return count_;
  }

  [[nodiscard]] inline int empty() const {
    return count_ == 0;
  }

  [[nodiscard]] inline std::array<T, 256> &data() {
    return container_;
  }

 private:
  std::array<T, 256> container_;
  int count_;
};

namespace move_gen {

// initializes piece attack lookups and magics
void initialize_attacks();

BitBoard pawn_attacks(U8 pos, const BoardState &state, Color which = Color::kNoColor, bool en_passant = true);

BitBoard pawn_moves(U8 pos, const BoardState &state);

BitBoard knight_moves(U8 pos);

BitBoard bishop_moves(U8 pos, const BitBoard &occupied);

BitBoard rook_moves(U8 pos, const BitBoard &occupied);

BitBoard king_moves(U8 pos, const BoardState &state);

BitBoard king_attacks(U8 pos);

BitBoard castling_moves(Color which, const BoardState &state);

BitBoard get_attacked_squares(const BoardState &state, Color attacker, bool include_king_attacks = true);

bool king_in_check(Color color, const BoardState &state);

List<Move> moves(MoveType move_type, Board &board);

List<Move> filter_moves(List<Move> &moves, MoveType type, Board &board);

}

#endif // INTEGRAL_MOVE_GEN_H_