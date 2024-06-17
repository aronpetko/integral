#ifndef INTEGRAL_TYPES_H_
#define INTEGRAL_TYPES_H_

#include <cmath>
#include <cstdint>
#include <cstring>
#include <memory>

#include "list.h"

using U8 = std::uint8_t;
using U16 = std::uint16_t;
using I16 = std::int16_t;
using U32 = std::uint32_t;
using I32 = std::int32_t;
using U64 = std::uint64_t;
using U128 = unsigned __int128;

enum PieceType : U8 {
  kPawn,
  kKnight,
  kBishop,
  kRook,
  kQueen,
  kKing,
  kNone,
  kNumPieceTypes = kNone
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
  kNoColor,
  kNumColors
};

inline constexpr Color FlipColor(const Color& color) {
  return Color(!color);
}

enum CastleRightMasks : U8 {
  kWhiteKingside = 0b0001,
  kWhiteQueenside = 0b0010,
  kBlackKingside = 0b0100,
  kBlackQueenside = 0b1000,
};

enum class Direction : int {
  kNorth,
  kSouth,
  kEast,
  kWest,
  kNorthEast,
  kNorthWest,
  kSouthEast,
  kSouthWest
};

enum Rank : int {
  kRank1,
  kRank2,
  kRank3,
  kRank4,
  kRank5,
  kRank6,
  kRank7,
  kRank8,
  kNumRanks
};

enum File : int {
  kFileA,
  kFileB,
  kFileC,
  kFileD,
  kFileE,
  kFileF,
  kFileG,
  kFileH,
  kNumFiles
};

// clang-format off
using Square = U8;
enum Squares : Square {
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
// clang-format on

template <typename T>
using SideTable = std::array<T, 2>;

template <typename T>
using SquareTable = std::array<T, kSquareCount>;

using Score = I32;
class ScorePair {
 public:
  constexpr ScorePair() : score_(0) {}

  constexpr explicit ScorePair(Score middle_game, Score end_game)
      : score_(Pack(middle_game, end_game)) {}

  constexpr explicit ScorePair(Score score_pair) : score_(score_pair) {}

  [[nodiscard]] constexpr I32 Pack(Score middle_game, Score end_game) const {
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

constexpr ScorePair Pair(Score middle_game, Score end_game) {
  return ScorePair(middle_game, end_game);
}

const Score kDrawScore = 0;
const Score kMateScore = std::numeric_limits<I16>::max() - 1;
const Score kInfiniteScore = std::numeric_limits<I16>::max();
const Score kScoreNone = -kInfiniteScore;

#endif  // INTEGRAL_TYPES_H_