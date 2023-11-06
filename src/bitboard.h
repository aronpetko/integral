#ifndef INTEGRAL_BITBOARD_H_
#define INTEGRAL_BITBOARD_H_

#include <iostream>
#include <array>

#include "types.h"
#include "move.h"

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

enum Square : U8 {
  kA1, kB1, kC1, kD1, kE1, kF1, kG1, kH1,
  kA2, kB2, kC2, kD2, kE2, kF2, kG2, kH2,
  kA3, kB3, kC3, kD3, kE3, kF3, kG3, kH3,
  kA4, kB4, kC4, kD4, kE4, kF4, kG4, kH4,
  kA5, kB5, kC5, kD5, kE5, kF5, kG5, kH5,
  kA6, kB6, kC6, kD6, kE6, kF6, kG6, kH6,
  kA7, kB7, kC7, kD7, kE7, kF7, kG7, kH7,
  kA8, kB8, kC8, kD8, kE8, kF8, kG8, kH8,
  kSquareCount = 64
};

enum RankMasks : U64 {
  kRank1 = 0x00000000000000FFULL,
  kRank2 = 0x000000000000FF00ULL,
  kRank3 = 0x0000000000FF0000ULL,
  kRank4 = 0x00000000FF000000ULL,
  kRank5 = 0x000000FF00000000ULL,
  kRank6 = 0x0000FF0000000000ULL,
  kRank7 = 0x00FF000000000000ULL,
  kRank8 = 0xFF00000000000000ULL
};

enum FileMasks : U64 {
  kFileH = 0x8080808080808080ULL,
  kFileG = 0x4040404040404040ULL,
  kFileF = 0x2020202020202020ULL,
  kFileE = 0x1010101010101010ULL,
  kFileD = 0x0808080808080808ULL,
  kFileC = 0x0404040404040404ULL,
  kFileB = 0x0202020202020202ULL,
  kFileA = 0x0101010101010101ULL
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

  BitBoard operator&(U64 other) const {
    return BitBoard(bitboard_ & other);
  }

  BitBoard operator&(const BitBoard &other) const {
    return BitBoard(bitboard_ & other.as_int());
  }

  BitBoard operator|(const BitBoard &other) const {
    return BitBoard(bitboard_ | other.as_int());
  }

  BitBoard operator|(U64 &other) const {
    return BitBoard(bitboard_ | other);
  }

  BitBoard operator<<(U8 shift) const {
    return BitBoard(bitboard_ << shift);
  }

  BitBoard operator>>(U8 shift) const {
    return BitBoard(bitboard_ >> shift);
  }

  BitBoard &operator|=(const BitBoard &other) {
    bitboard_ |= other.as_int();
    return *this;
  }

  BitBoard &operator&=(const BitBoard &other) {
    bitboard_ &= other.as_int();
    return *this;
  }

  BitBoard &operator&=(U64 other) {
    bitboard_ &= other;
    return *this;
  }

  BitBoard &operator^=(const BitBoard &other) {
    bitboard_ ^= other.as_int();
    return *this;
  }

 private:
  U64 bitboard_;
};

using BitBoards = std::array<BitBoard, kAllPieces + 1>;

static U8 rank_file_to_pos(U8 rank, U8 file) {
  return rank * 8 + file;
}

// todo: handle promotion
static Move algebraic_to_move(const std::string &move_str) {
  int from_rank = move_str[1] - '1', from_file = move_str[0] - 'a';
  int to_rank = move_str[3] - '1', to_file = move_str[2] - 'a';
  return Move(rank_file_to_pos(from_rank, from_file), rank_file_to_pos(to_rank, to_file));
}

// todo: handle promotion
static std::string move_to_algebraic(Move move) {
  std::string output;
  output.push_back(move.get_from() / 8 + 'a');
  output.push_back(move.get_from() % 8 + '1');
  output.push_back(move.get_to() / 8 + 'a');
  output.push_back(move.get_to() % 8 + '1');
  return output;
}

static std::string pos_to_algebraic(U8 pos) {
  std::string output;
  output.push_back(pos % 8 + 'a');
  output.push_back(pos / 8 + '1');
  return output;
}

template<Direction dir>
static BitBoard shift(BitBoard bb) {
  if (dir == Direction::kNorth)
    return bb << 8;
  if (dir == Direction::kSouth)
    return bb >> 8;
  if (dir == Direction::kEast)
    return (bb & ~FileMasks::kFileH) >> 1;
  if (dir == Direction::kWest)
    return (bb & ~FileMasks::kFileA) << 1;
  if (dir == Direction::kNorthEast)
    return (bb & ~FileMasks::kFileH) << 9;
  if (dir == Direction::kNorthWest)
    return (bb & ~FileMasks::kFileA) << 7;
  if (dir == Direction::kSouthEast)
    return ((bb & ~FileMasks::kFileH) >> 9);
  if (dir == Direction::kSouthWest)
    return ((bb & ~FileMasks::kFileA) >> 7);
}

static U8 get_lsb_pos(U64 val) {
  U8 position = 0;
  while (val) {
    if (val & 1) return position;
    val >>= 1;
    position++;
  }
  return position;  // shouldn't reach here if val is not 0.
}

static U8 get_lsb_pos(BitBoard bb) {
  return get_lsb_pos(bb.as_int());
}

static U8 pop_lsb(BitBoard &bb) {
  U8 lsb_pos = get_lsb_pos(bb);
  bb &= BitBoard(bb.as_int() - 1);
  return lsb_pos;
}

static Color get_piece_color(U8 pos, BitBoards &pieces) {
  return pieces[kWhitePieces].is_set(pos) ? Color::kWhite : pieces[kBlackPieces].is_set(pos) ? Color::kBlack
                                                                                             : Color::kNone;
}

static Color get_piece_color(BitBoard bb, BitBoards &pieces) {
  return (pieces[kWhitePieces] & bb).as_int() ? Color::kWhite : (pieces[kBlackPieces] & bb).as_int() ? Color::kBlack
                                                                                                     : Color::kNone;
}

static void print_bb(BitBoard board) {
  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file < 8; file++) {
      U8 square = rank_file_to_pos(rank, file);
      std::cout << (board.is_set(square) ? '1' : '0');
      if (file < 7)
        std::cout << " ";  // space separator for clarity
    }
    std::cout << std::endl;
  }
}

static std::string get_piece_unicode(BitBoards &pieces, U8 pos) {
  if (pieces[kWhitePieces].is_set(pos)) {
    if (pieces[kWhitePawns].is_set(pos)) return "♙";
    if (pieces[kWhiteKnights].is_set(pos)) return "♘";
    if (pieces[kWhiteBishops].is_set(pos)) return "♗";
    if (pieces[kWhiteRooks].is_set(pos)) return "♖";
    if (pieces[kWhiteQueens].is_set(pos)) return "♕";
    if (pieces[kWhiteKing].is_set(pos)) return "♔";
  } else if (pieces[kBlackPieces].is_set(pos)) {
    if (pieces[kBlackPawns].is_set(pos)) return "♟";
    if (pieces[kBlackKnights].is_set(pos)) return "♞";
    if (pieces[kBlackBishops].is_set(pos)) return "♝";
    if (pieces[kBlackRooks].is_set(pos)) return "♜";
    if (pieces[kBlackQueens].is_set(pos)) return "♛";
    if (pieces[kBlackKing].is_set(pos)) return "♚";
  }
  return " ";
}

static void print_pieces(BitBoards &pieces) {
  for (int rank = 7; rank >= 0; rank--) {
    std::cout << rank + 1 << ' ';
    for (int file = 0; file < 8; file++) {
      U8 square = rank_file_to_pos(rank, file);
      std::cout << get_piece_unicode(pieces, square);
      if (file < 7)
        std::cout << " ";  // space separator for clarity
    }
    std::cout << std::endl;
  }
  std::cout << "  ";
  for (int file = 0; file < 8; file++)
    std::cout << (char) ('a' + file) << ' ';
  std::cout << std::endl;
}

#endif // INTEGRAL_BITBOARD_H_