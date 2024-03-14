#ifndef INTEGRAL_TYPES_H_
#define INTEGRAL_TYPES_H_

#include <cstdint>

using U8 = std::uint8_t;
using U32 = std::uint32_t;
using U64 = std::uint64_t;

const U8 kBoardFiles = 8;
const U8 kBoardRanks = 8;
const U8 kBoardLength = 8;

enum PieceType : U8 {
  kNone,
  kPawn,
  kKnight,
  kBishop,
  kRook,
  kQueen,
  kKing,
  kNumPieceTypes = kKing - kPawn + 1
};

enum class PromotionType : U8 {
  kNone,
  kKnight,
  kBishop,
  kRook,
  kQueen,
  kAny
};

enum class MoveType {
  kAll,
  kCaptures,
  kQuiet
};

enum Color {
  kBlack,
  kWhite,
  kNoColor
};

static Color flip_color(const Color &color) {
  return Color(!color);
}

enum CastleRights : U8 {
  kWhiteKingside = 0b0001,
  kWhiteQueenside = 0b0010,
  kBlackKingside = 0b0100,
  kBlackQueenside = 0b1000,
  kWhiteBothSides = kWhiteKingside | kWhiteQueenside,
  kBlackBothSides = kBlackKingside | kBlackQueenside,
};

enum Direction : int {
  kNorth,
  kSouth,
  kEast,
  kWest,
  kNorthEast,
  kNorthWest,
  kSouthEast,
  kSouthWest
};

#endif // INTEGRAL_TYPES_H_