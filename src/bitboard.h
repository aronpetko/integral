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
  kSquareCount = 64,
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
  BitBoard() : bitboard_(0ULL) {}

  explicit BitBoard(U64 bitboard) : bitboard_(bitboard) {}

  [[nodiscard]] U64 as_u64() const {
    return bitboard_;
  }

  void set_bit(U8 square) {
    bitboard_ |= (1ULL << square);
  }

  void clear_bit(U8 square) {
    bitboard_ &= ~(1ULL << square);
  }

  [[nodiscard]] bool is_set(U8 square) const {
    return bitboard_ & (1ULL << square);
  }

  void move(U8 from, U8 to) {
    clear_bit(from);
    set_bit(to);
  }

  [[nodiscard]] U8 get_lsb_pos() const {
    U64 copy = bitboard_;

    U8 position = 0;
    while (copy) {
      if (copy & 1)
        return position;

      copy >>= 1;
      position++;
    }

    // should only reach here if the bitboard isn't empty
    return position;
  }

  U8 pop_lsb() {
    U8 lsb_pos = get_lsb_pos();
    bitboard_ &= bitboard_ - 1;
    return lsb_pos;
  }

  BitBoard &operator=(U64 bitboard) {
    bitboard_ = bitboard;
    return *this;
  }

  BitBoard &operator=(BitBoard other) {
    bitboard_ = other.as_u64();
    return *this;
  }

  BitBoard operator&(U64 other) const {
    return BitBoard(bitboard_ & other);
  }

  BitBoard operator&(const BitBoard &other) const {
    return BitBoard(bitboard_ & other.as_u64());
  }

  BitBoard operator|(const BitBoard &other) const {
    return BitBoard(bitboard_ | other.as_u64());
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
    bitboard_ |= other.as_u64();
    return *this;
  }

  BitBoard &operator&=(const BitBoard &other) {
    bitboard_ &= other.as_u64();
    return *this;
  }

  BitBoard &operator&=(U64 other) {
    bitboard_ &= other;
    return *this;
  }

  BitBoard &operator^=(const BitBoard &other) {
    bitboard_ ^= other.as_u64();
    return *this;
  }

 private:
  U64 bitboard_;
};

using BitBoards = std::array<BitBoard, kAllPieces + 1>;

template<Direction dir>
static BitBoard shift(BitBoard bb) {
  if (dir == Direction::kNorth)
    return bb << 8;
  if (dir == Direction::kSouth)
    return bb >> 8;
  if (dir == Direction::kEast)
    return (bb << 1) & ~FileMasks::kFileA;
  if (dir == Direction::kWest)
    return (bb >> 1) & ~FileMasks::kFileH;
  if (dir == Direction::kNorthEast)
    return (bb << 9) & ~FileMasks::kFileA;
  if (dir == Direction::kNorthWest)
    return (bb << 7) & ~FileMasks::kFileH;
  if (dir == Direction::kSouthEast)
    return (bb >> 7) & ~FileMasks::kFileA;
  if (dir == Direction::kSouthWest)
    return (bb >> 9) & ~FileMasks::kFileH;
}

static Color get_piece_color(U8 pos, BitBoards &pieces) {
  if (pieces[kWhitePieces].is_set(pos)) return Color::kWhite;
  if (pieces[kBlackPieces].is_set(pos)) return Color::kBlack;
  return Color::kNone;
}

static Color get_piece_color(BitBoard bb, BitBoards &pieces) {
  if ((pieces[kWhitePieces] & bb).as_u64()) return Color::kWhite;
  if ((pieces[kBlackPieces] & bb).as_u64()) return Color::kBlack;
  return Color::kNone;
}

static PieceType get_piece_type(U8 pos, BitBoards &pieces) {
  auto color = get_piece_color(pos, pieces);

  int start_bb = color == Color::kWhite ? kWhitePawns : kBlackPawns;
  int end_bb = color == Color::kWhite ? kWhitePieces : kBlackPieces;

  for (int bb_idx = start_bb; bb_idx <= end_bb; bb_idx++) {
    BitBoard &piece_bb = pieces[bb_idx];

    // there should be only one piece on this square, so this is kind of safe
    if (piece_bb.is_set(pos))
      return PieceType(bb_idx - start_bb + 1);
  }

  return PieceType::kNone;
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
  for (int rank = kBoardRanks - 1; rank >= 0; rank--) {
    std::cout << rank + 1 << ' ';
    for (int file = 0; file < kBoardFiles; file++) {
      U8 square = rank_file_to_pos(rank, file);
      std::cout << get_piece_unicode(pieces, square);
      if (file < kBoardFiles - 1)
        std::cout << " ";  // space separator for clarity
    }
    std::cout << std::endl;
  }
  std::cout << "  ";
  for (int file = 0; file < kBoardFiles; file++)
    std::cout << static_cast<char>('a' + file) << ' ';
  std::cout << std::endl;
}

#endif // INTEGRAL_BITBOARD_H_