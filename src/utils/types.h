#ifndef INTEGRAL_TYPES_H_
#define INTEGRAL_TYPES_H_

#include <cmath>
#include <cstdint>
#include <cstring>

#include "list.h"

using U8 = std::uint8_t;
using U16 = std::uint16_t;
using I16 = std::int16_t;
using U32 = std::uint32_t;
using I32 = std::int32_t;
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

using Score = I32;

class ScorePair {
 public:
  constexpr ScorePair() : score_(0) {}

  constexpr ScorePair(Score middle_game, Score end_game)
      : score_(Pack(middle_game, end_game)) {}

  constexpr explicit ScorePair(Score score_pair) : score_(score_pair) {}

  [[nodiscard]] constexpr static I32 Pack(Score middle_game,
                                                   Score end_game) {
    return static_cast<I32>(static_cast<U32>(end_game) << 16) + middle_game;
  }

  // Extract the lower 16 bits using memcpy for safe type reinterpretation
  [[nodiscard]] inline Score MiddleGame() const {
    const auto mg = static_cast<U16>(score_);
    I16 v{};
    std::memcpy(&v, &mg, sizeof(mg));
    return static_cast<Score>(v);
  }

  // Extract the upper 16 bits using memcpy and adjust the sign
  [[nodiscard]] inline Score EndGame() const {
    const auto eg = static_cast<I16>(static_cast<U32>(score_ + 0x8000) >> 16);
    I16 v{};
    std::memcpy(&v, &eg, sizeof(eg));
    return static_cast<Score>(v);
  }

  constexpr ScorePair operator+(const ScorePair& other) const {
    return ScorePair{score_ + other.score_};
  }

  constexpr ScorePair operator-(const ScorePair& other) const {
    return ScorePair{score_ - other.score_};
  }

  constexpr ScorePair operator*(const ScorePair& other) const {
    return ScorePair{score_ * other.score_};
  }

  constexpr ScorePair operator*(int scalar) const {
    return ScorePair{score_ * scalar};
  }

  constexpr ScorePair& operator+=(const ScorePair& other) {
    score_ += other.score_;
    return *this;
  }

  constexpr ScorePair& operator-=(const ScorePair& other) {
    score_ -= other.score_;
    return *this;
  }

  constexpr ScorePair& operator*=(const ScorePair& other) {
    score_ *= other.score_;
    return *this;
  }

  constexpr ScorePair& operator*=(int scalar) {
    score_ *= scalar;
    return *this;
  }

 private:
  I32 score_;
};

#define PAIR(middle_game, end_game) ScorePair(middle_game, end_game)

// Compile-time checks
static_assert(ScorePair::Pack(1, 2) == 0x20001, "Pack function failed!");

const Score kDrawScore = 0;
const Score kMateScore = std::numeric_limits<I16>::max() - 1;
const Score kInfiniteScore = std::numeric_limits<I16>::max();
const Score kScoreNone = -kInfiniteScore;

#endif  // INTEGRAL_TYPES_H_