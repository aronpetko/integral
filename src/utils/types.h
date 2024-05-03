#ifndef INTEGRAL_TYPES_H_
#define INTEGRAL_TYPES_H_

#include <cmath>
#include <cstdint>

#include "list.h"

using U8 = std::uint8_t;
using U16 = std::uint16_t;
using U32 = std::uint32_t;
using U64 = std::uint64_t;
using U128 = unsigned __int128;

const U8 kNumFiles = 8;
const U8 kNumRanks = 8;
const U8 kBoardLength = 8;

enum PieceType : U8 {
  kPawn,
  kKnight,
  kBishop,
  kRook,
  kQueen,
  kKing,
  kNone,
  kNumTypes = kNone
};

enum class PromotionType : U8 {
  kNone,
  kKnight,
  kBishop,
  kRook,
  kQueen,
  kAny,
};

enum MoveType : U8 {
  kCaptures = 0b1,
  kQuiet = 0b10,
  kTactical = 0b100 | kCaptures,
  kAll = kCaptures | kQuiet | kTactical,
};

enum Color : U8 {
  kBlack,
  kWhite,
  kNoColor
};

inline Color FlipColor(const Color &color) {
  return Color(!color);
}

enum CastleRightMasks : U8 {
  kWhiteKingside = 0b0001,
  kWhiteQueenside = 0b0010,
  kBlackKingside = 0b0100,
  kBlackQueenside = 0b1000,
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

using Score = std::int32_t;

const Score kDrawScore = 0;
const Score kMateScore = 1e8;
const Score kInfiniteScore = 1e8 + 1;
const Score kScoreNone = -kInfiniteScore;

#endif  // INTEGRAL_TYPES_H_