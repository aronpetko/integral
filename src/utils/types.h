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

inline Color FlipColor(const Color& color) {
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

#include <cstdint>

using Score = std::int32_t;

class ScorePair {
 public:
  constexpr ScorePair() : score_(0) {}

  constexpr ScorePair(Score middle_game, Score end_game)
      : score_(Pack(middle_game, end_game)) {}

  constexpr explicit ScorePair(std::int32_t score_pair) : score_(score_pair) {}

  constexpr operator std::int32_t() const {
    return score_;
  }

  [[nodiscard]] constexpr static std::int32_t Pack(Score middle_game,
                                                   Score end_game) {
    return static_cast<std::int32_t>(static_cast<std::uint32_t>(end_game) << 16) + middle_game;
  }

  // Extract the upper 16 bits
  [[nodiscard]] constexpr Score MiddleGame() const {
    return static_cast<Score>(score_);
  }

  // Extract the lower 16 bits
  [[nodiscard]] constexpr Score EndGame() const {
    return static_cast<Score>(static_cast<std::int32_t>(score_ + 0x8000) >> 16);
  }

  constexpr ScorePair operator+(const ScorePair& other) const {
    return ScorePair(score_ + other.score_);
  }

  constexpr ScorePair operator-(const ScorePair& other) const {
    return ScorePair(score_ - other.score_);
  }

  constexpr ScorePair operator*(const ScorePair& other) const {
    return ScorePair(score_ * other.score_);
  }

  constexpr ScorePair operator*(Score scalar) const {
    return ScorePair(score_ * scalar);
  }

  constexpr ScorePair& operator+=(const ScorePair& other) {
    *this = *this + other;
    return *this;
  }

  constexpr ScorePair& operator-=(const ScorePair& other) {
    *this = *this - other;
    return *this;
  }

  constexpr ScorePair& operator*=(const ScorePair& other) {
    *this = *this * other;
    return *this;
  }

  constexpr ScorePair& operator*=(Score scalar) {
    *this = *this * scalar;
    return *this;
  }

 private:
  std::int32_t score_;
};

#define PAIR(middle_game, end_game) ScorePair(middle_game, end_game)

const Score kDrawScore = 0;
const Score kMateScore = std::numeric_limits<Score>::max() - 1;
const Score kInfiniteScore = std::numeric_limits<Score>::max();
const Score kScoreNone = -kInfiniteScore;

#endif  // INTEGRAL_TYPES_H_