#ifndef INTEGRAL_TYPES_H_
#define INTEGRAL_TYPES_H_

#include <cmath>
#include <cstdint>
#include <cstring>
#include <memory>
#include <vector>

#include "../../third-party/fmt/include/fmt/format.h"
#include "list.h"

using I8 = std::int8_t;
using U8 = std::uint8_t;
using U16 = std::uint16_t;
using I16 = std::int16_t;
using U32 = std::uint32_t;
using I32 = std::int32_t;
using U64 = std::uint64_t;
using I64 = std::int64_t;
using U128 = unsigned __int128;

constexpr int kMaxPlyFromRoot = 256;
constexpr int kMaxGamePly = 512;

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
  kKnight,
  kBishop,
  kRook,
  kQueen,
};

enum MoveGenType : U8 {
  kQuiet = 0b01,
  kNoisy = 0b10,
  kAll = kQuiet | kNoisy,
};

enum Color : U8 {
  kWhite,
  kBlack,
  kNoColor,
  kNumColors = 2
};

constexpr Color FlipColor(Color color) {
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

class Square {
 public:
  constexpr Square(U8 square) : square_(square) {}
  constexpr Square() = default;

  static constexpr Square FromRankFile(int rank, int file) {
    return rank * kNumRanks + file;
  }

  constexpr operator U8() const {
    return square_;
  }

  constexpr Square operator++() {
    return ++square_;
  }

  constexpr Square operator++(int) {
    return square_++;
  }

  [[nodiscard]] constexpr int DistanceTo(Square other) const {
    const int file_diff = std::abs(File() - other.File());
    const int rank_diff = std::abs(Rank() - other.Rank());
    return std::max(file_diff, rank_diff);
  }

  [[nodiscard]] constexpr int Rank() const {
    return square_ >> 3;
  }

  [[nodiscard]] constexpr int File() const {
    return square_ & 7;
  }

  [[nodiscard]] constexpr Square RelativeTo(Color side) const {
    return square_ ^ (56 * !side);
  }

  template <Color side>
  [[nodiscard]] constexpr Square RelativeTo() const {
    return square_ ^ (56 * !side);
  }

  template <Color side>
  [[nodiscard]] constexpr Square RelativeRank() {
    const int rank = Rank();
    if constexpr (side == Color::kBlack)
      return 7 - rank;
    else
      return rank;
  }

  template <Color side>
  [[nodiscard]] constexpr Square RelativeFile() {
    const int file = File();
    if constexpr (side == Color::kBlack)
      return 7 - file;
    else
      return file;
  }

  constexpr Square operator+(const int other) const {
    return square_ + other;
  }

  constexpr Square operator+=(const int other) {
    return square_ += other;
  }

  constexpr Square operator-(const int other) const {
    return square_ - other;
  }

  constexpr Square operator-=(const int other) {
    return square_ -= other;
  }

  constexpr Square operator*(const Square other) const {
    return square_ * other.square_;
  }

  constexpr Square operator*(int scalar) const {
    return square_ * scalar;
  }

  [[nodiscard]] std::string ToString() const {
    return fmt::format("{}{}",
                       static_cast<char>('a' + (square_ % 8)),
                       static_cast<char>('1' + (square_ / 8)));
  }

 private:
  U8 square_;
};

// clang-format off
enum Squares : U8 {
  kA1, kB1, kC1, kD1, kE1, kF1, kG1, kH1,
  kA2, kB2, kC2, kD2, kE2, kF2, kG2, kH2,
  kA3, kB3, kC3, kD3, kE3, kF3, kG3, kH3,
  kA4, kB4, kC4, kD4, kE4, kF4, kG4, kH4,
  kA5, kB5, kC5, kD5, kE5, kF5, kG5, kH5,
  kA6, kB6, kC6, kD6, kE6, kF6, kG6, kH6,
  kA7, kB7, kC7, kD7, kE7, kF7, kG7, kH7,
  kA8, kB8, kC8, kD8, kE8, kF8, kG8, kH8,
  kSquareCount = 64, kNoSquare = 64
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

  constexpr ScorePair operator/(const ScorePair& other) const {
    return ScorePair{score_ / other.score_};
  }

  constexpr ScorePair operator/(int scalar) const {
    return ScorePair{score_ / scalar};
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

[[nodiscard]] constexpr ScorePair Pair(Score middle_game, Score end_game) {
  return ScorePair(middle_game, end_game);
}

const Score kDrawScore = 0;
const Score kMateScore = std::numeric_limits<I16>::max() - 1;
const Score kMateInMaxPlyScore = kMateScore - kMaxPlyFromRoot;
const Score kInfiniteScore = std::numeric_limits<I16>::max();
const Score kTBWinScore = kMateScore - kMaxPlyFromRoot - 1;
const Score kTBWinInMaxPlyScore = kTBWinScore - kMaxPlyFromRoot;
const Score kScoreNone = -kInfiniteScore;

template <typename T, typename... Ts>
struct is_all_same {
  static constexpr bool value = (std::is_same_v<T, Ts> && ...);
};

template <typename... Ts>
constexpr auto is_all_same_v = is_all_same<Ts...>::value;

#endif  // INTEGRAL_TYPES_H_
