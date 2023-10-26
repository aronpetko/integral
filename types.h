#ifndef INTEGRAL_TYPES_H_
#define INTEGRAL_TYPES_H_

using U8 = unsigned char;
using U32 = unsigned int;
using U64 = unsigned long long;

enum PieceType {
  kNone,
  kPawn,
  kKnight,
  kBishop,
  kRook,
  kQueen,
  kKing,
};

enum class Color {
  kWhite,
  kBlack
};

enum CastleBits {
  kWhiteKingside = 0b0001,
  kWhiteQueenside = 0b0010,
  kBlackKingside = 0b0100,
  kBlackQueenside = 0b1000,
};

#endif // INTEGRAL_TYPES_H_