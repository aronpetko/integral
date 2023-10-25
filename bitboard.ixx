export module bitboard;

import types;

#include <stdexcept>

export enum class PieceType {
  kNone,
  kPawn,
  kKnight,
  kBishop,
  kRook,
  kQueen,
  kKing,
};

export enum class Color {
  kWhite,
  kBlack
};

export class BitBoard {
 public:
  BitBoard() : bitboard_(0ULL) {}

  explicit BitBoard(U64 bitboard) : bitboard_(bitboard) {}

  U64 get_bitboard() {
    return bitboard_;
  }

  void set_bit(U32 square) {
    bitboard_ |= (1ULL << square);
  }

  void clear_bit(U32 square) {
    bitboard_ &= ~(1ULL << square);
  }

  bool is_set(U32 square) const {
    return bitboard_ & (1ULL << square);
  }

  BitBoard &operator=(U64 bitboard) {
    bitboard_ = bitboard;
    return *this;
  }

  BitBoard &operator=(BitBoard other) {
    bitboard_ = other.get_bitboard();
    return *this;
  }

  BitBoard operator|(BitBoard &other) {
    return BitBoard(bitboard_ | other.get_bitboard());
  }

  BitBoard &operator|=(BitBoard &other) {
    bitboard_ |= other.get_bitboard();
    return *this;
  }

  BitBoard &operator&=(BitBoard &other) {
    bitboard_ &= other.get_bitboard();
    return *this;
  }

 private:
  U64 bitboard_;
};

// the bit boards will get populated when fen is parsed
export class BitBoards {
 public:
  char get_piece_char(U32 pos) const {
    if (white_pieces.is_set(pos)) {
      if (white_pawns.is_set(pos)) return 'P';
      if (white_knights.is_set(pos)) return 'N';
      if (white_bishops.is_set(pos)) return 'B';
      if (white_rooks.is_set(pos)) return 'R';
      if (white_queens.is_set(pos)) return 'Q';
      if (white_king.is_set(pos)) return 'K';
    } else if (black_pieces.is_set(pos)) {
      if (black_pawns.is_set(pos)) return 'p';
      if (black_knights.is_set(pos)) return 'n';
      if (black_bishops.is_set(pos)) return 'b';
      if (black_rooks.is_set(pos)) return 'r';
      if (black_queens.is_set(pos)) return 'q';
      if (black_king.is_set(pos)) return 'k';
    } else
      return ' ';
  }

  BitBoard white_pawns;
  BitBoard white_knights;
  BitBoard white_bishops;
  BitBoard white_rooks;
  BitBoard white_queens;
  BitBoard white_king;
  BitBoard white_pieces;

  BitBoard black_pawns;
  BitBoard black_knights;
  BitBoard black_bishops;
  BitBoard black_rooks;
  BitBoard black_queens;
  BitBoard black_king;
  BitBoard black_pieces;

  BitBoard all_pieces;
};