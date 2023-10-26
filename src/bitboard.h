#ifndef INTEGRAL__BITBOARD_H_
#define INTEGRAL__BITBOARD_H_

#include <iostream>
#include <array>

#include "types.h"

enum PieceBitBoard {
  kWhitePawns,
  kWhiteKnights,
  kWhiteBishops,
  kWhiteRooks,
  kWhiteQueens,
  kWhiteKing,
  kWhitePieces,

  kBlackPawns,
  kBlackKnights,
  kBlackBishops,
  kBlackRooks,
  kBlackQueens,
  kBlackKing,
  kBlackPieces,

  kAllPieces
};

class BitBoard {
 public:
  BitBoard() {
    bitboard_ = 0ULL;
  }

  explicit BitBoard(U64 bitboard) : bitboard_(bitboard) {}

  U64 as_int() const {
    return bitboard_;
  }

  void set_bit(U8 square) {
    bitboard_ |= (1ULL << square);
  }

  void clear_bit(U8 square) {
    bitboard_ &= ~(1ULL << square);
  }

  bool is_set(U8 square) const {
    return bitboard_ & (1ULL << square);
  }

  void move(U8 from, U8 to) {
    clear_bit(from);
    set_bit(to);
  }

  BitBoard &operator=(U64 bitboard) {
    bitboard_ = bitboard;
    return *this;
  }

  BitBoard &operator=(BitBoard other) {
    bitboard_ = other.as_int();
    return *this;
  }

  BitBoard operator&(const BitBoard &other) const {
    return BitBoard(bitboard_ & other.as_int());
  }

  BitBoard operator|(const BitBoard &other) const {
    return BitBoard(bitboard_ | other.as_int());
  }

  BitBoard &operator|=(const BitBoard &other) {
    bitboard_ |= other.as_int();
    return *this;
  }

  BitBoard &operator&=(const BitBoard &other) {
    bitboard_ &= other.as_int();
    return *this;
  }

 private:
  U64 bitboard_{};
};

using BitBoards = std::array<BitBoard, kAllPieces + 1>;

// the bit boards will get populated when fen is parsed
static char get_piece_char(BitBoards &pieces, U8 pos) {
  if (pieces[kWhitePieces].is_set(pos)) {
    if (pieces[kWhitePawns].is_set(pos)) return 'P';
    if (pieces[kWhiteKnights].is_set(pos)) return 'N';
    if (pieces[kWhiteBishops].is_set(pos)) return 'B';
    if (pieces[kWhiteRooks].is_set(pos)) return 'R';
    if (pieces[kWhiteQueens].is_set(pos)) return 'Q';
    if (pieces[kWhiteKing].is_set(pos)) return 'K';
  } else if (pieces[kBlackPieces].is_set(pos)) {
    if (pieces[kBlackPawns].is_set(pos)) return 'p';
    if (pieces[kBlackKnights].is_set(pos)) return 'n';
    if (pieces[kBlackBishops].is_set(pos)) return 'b';
    if (pieces[kBlackRooks].is_set(pos)) return 'r';
    if (pieces[kBlackQueens].is_set(pos)) return 'q';
    if (pieces[kBlackKing].is_set(pos)) return 'k';
  }

  return ' ';
}

static void print_bb(BitBoard board) {
  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file < 8; file++) {
      U8 square = (rank * 8 + file);
      std::cout << (board.is_set(square) ? '1' : '0');
      if (file < 7) std::cout << " ";  // space separator for clarity
    }
    std::cout << std::endl;
  }
}

#endif // INTEGRAL__BITBOARD_H_