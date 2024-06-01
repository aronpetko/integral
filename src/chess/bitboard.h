#ifndef INTEGRAL_BITBOARD_H_
#define INTEGRAL_BITBOARD_H_

#include <array>
#include <bit>
#include <functional>
#include <iostream>
#include <vector>

#include "../utils/types.h"

static constexpr std::array<U64, kNumRanks> kRankMasks = {
    0x00000000000000FFULL,
    0x000000000000FF00ULL,
    0x0000000000FF0000ULL,
    0x00000000FF000000ULL,
    0x000000FF00000000ULL,
    0x0000FF0000000000ULL,
    0x00FF000000000000ULL,
    0xFF00000000000000ULL,
};

static constexpr std::array<U64, kNumFiles> kFileMasks = {
    0x0101010101010101ULL,
    0x0202020202020202ULL,
    0x0404040404040404ULL,
    0x0808080808080808ULL,
    0x1010101010101010ULL,
    0x2020202020202020ULL,
    0x4040404040404040ULL,
    0x8080808080808080ULL,
};

constexpr U64 kDarkSquares = 0xAA55AA55AA55AA55ULL;
constexpr U64 kLightSquares = 0x55AA55AA55AA55AAULL;

inline int Rank(Square square) {
  return square >> 3;
}

inline int File(Square square) {
  return square & 7;
}

inline Square RankFileToSquare(int rank, int file) {
  return Square(rank * kNumRanks + file);
}

inline Square RelativeSquare(Square square, Color side) {
  return Square(square ^ (56 * side));
}

inline Square RelativeRank(Square square, Color side) {
  const int rank = Rank(square);
  return side == Color::kBlack ? 7 - rank : rank;
}

class BitBoard {
 public:
  constexpr BitBoard() : bitboard_(0ULL) {}

  constexpr BitBoard(U64 bitboard) : bitboard_(bitboard) {}

  static BitBoard FromSquare(U8 square) {
    return {1ULL << square};
  }

  [[nodiscard]] constexpr inline U64 AsU64() const {
    return bitboard_;
  }

  constexpr inline void SetBit(U8 square) {
    bitboard_ |= (1ULL << square);
  }

  constexpr inline void ClearBit(U8 square) {
    bitboard_ &= ~(1ULL << square);
  }

  inline constexpr void MoveBit(U8 from, U8 to) {
    bitboard_ ^= (1ULL << from) | (1ULL << to);
  }

  [[nodiscard]] constexpr inline bool IsSet(U8 square) const {
    return (bitboard_ >> square) & 1;
  }

  [[nodiscard]] constexpr inline U8 GetLsb() const {
    return std::countr_zero(bitboard_);
  }

  [[nodiscard]] constexpr inline U8 GetMsb() const {
    return 63 - std::countl_zero(bitboard_);
  }

  constexpr inline U8 PopLsb() {
    const U8 lsb_pos = GetLsb();
    bitboard_ &= bitboard_ - 1;
    return lsb_pos;
  }

  [[nodiscard]] constexpr inline int PopCount() const {
    return std::popcount(bitboard_);
  }

  [[nodiscard]] constexpr inline bool MoreThanOne() const {
    return (bitboard_ & (bitboard_ - 1)) != 0;
  }

  template <class Function>
  void PopEnumerate(const Function &fn) {
    while (bitboard_ != 0) {
      Square bit_location = PopLsb();
      fn(bit_location);
    }
  }

  constexpr inline BitBoard &operator=(const U64 &bitboard) {
    bitboard_ = bitboard;
    return *this;
  }

  constexpr inline BitBoard &operator=(const BitBoard &other) = default;

  constexpr inline BitBoard operator&(const U64 &other) const {
    return {bitboard_ & other};
  }

  constexpr inline BitBoard operator&(const BitBoard &other) const {
    return {bitboard_ & other.bitboard_};
  }

  constexpr inline BitBoard operator|(const BitBoard &other) const {
    return {bitboard_ | other.bitboard_};
  }

  constexpr inline BitBoard operator|(const U64 &other) const {
    return {bitboard_ | other};
  }

  constexpr inline BitBoard operator|(U64 &other) const {
    return {bitboard_ | other};
  }

  constexpr inline BitBoard operator^(const U64 &other) const {
    return {bitboard_ ^ other};
  }

  constexpr inline BitBoard operator^(const BitBoard &other) const {
    return {bitboard_ ^ other.bitboard_};
  }

  constexpr inline BitBoard operator<<(U8 shift) const {
    return {bitboard_ << shift};
  }

  constexpr inline BitBoard operator>>(U8 shift) const {
    return {bitboard_ >> shift};
  }

  constexpr inline BitBoard &operator|=(const BitBoard &other) {
    bitboard_ |= other.bitboard_;
    return *this;
  }

  constexpr inline BitBoard &operator&=(const BitBoard &other) {
    bitboard_ &= other.bitboard_;
    return *this;
  }

  constexpr inline BitBoard &operator&=(const U64 &other) {
    bitboard_ &= other;
    return *this;
  }

  constexpr inline BitBoard &operator^=(const BitBoard &other) {
    bitboard_ ^= other.bitboard_;
    return *this;
  }

  constexpr inline BitBoard &operator*=(const BitBoard &other) {
    bitboard_ *= other.bitboard_;
    return *this;
  }

  constexpr inline BitBoard &operator>>=(const BitBoard &other) {
    bitboard_ >>= other.bitboard_;
    return *this;
  }

  constexpr inline BitBoard &operator<<=(const BitBoard &other) {
    bitboard_ <<= other.bitboard_;
    return *this;
  }

  constexpr inline BitBoard operator~() const {
    return {~bitboard_};
  }

  constexpr inline BitBoard operator-(const BitBoard &other) const {
    return {bitboard_ - other.bitboard_};
  }

  constexpr inline BitBoard operator-(int num) const {
    return {bitboard_ - num};
  }

  constexpr inline BitBoard operator-() const {
    return {~bitboard_ + 1};
  }

  constexpr inline BitBoard operator+(const BitBoard &other) const {
    return {bitboard_ + other.bitboard_};
  }

  constexpr inline BitBoard operator/(const BitBoard &other) const {
    return {bitboard_ / other.bitboard_};
  }

  constexpr inline BitBoard operator*(const BitBoard &other) const {
    return {bitboard_ * other.bitboard_};
  }

  constexpr inline bool operator==(const BitBoard &other) const {
    return bitboard_ == other.bitboard_;
  }

  constexpr inline bool operator==(U64 value) const {
    return bitboard_ == value;
  }

  constexpr inline explicit operator bool() const {
    return bitboard_ != 0ULL;
  }

  void Print() const {
    for (int rank = 7; rank >= 0; rank--) {
      for (int file = 0; file < 8; file++) {
        const auto square = RankFileToSquare(rank, file);
        std::cout << (IsSet(square) ? '1' : '0');
        if (file < 7) std::cout << " ";  // Space separator for clarity
      }
      std::cout << std::endl;
    }
  }

 private:
  U64 bitboard_;
};

template <Direction dir>
constexpr inline BitBoard Shift(const BitBoard &bitboard) {
  if constexpr (dir == Direction::kNorth)
    return BitBoard(bitboard << 8);
  else if constexpr (dir == Direction::kSouth)
    return BitBoard(bitboard >> 8);
  else if constexpr (dir == Direction::kEast)
    return BitBoard((bitboard << 1) & ~kFileMasks[kFileA]);
  else if constexpr (dir == Direction::kWest)
    return BitBoard((bitboard >> 1) & ~kFileMasks[kFileH]);
  else if constexpr (dir == Direction::kNorthEast)
    return BitBoard((bitboard << 9) & ~kFileMasks[kFileA]);
  else if constexpr (dir == Direction::kNorthWest)
    return BitBoard((bitboard << 7) & ~kFileMasks[kFileH]);
  else if constexpr (dir == Direction::kSouthEast)
    return BitBoard((bitboard >> 7) & ~kFileMasks[kFileA]);
  else if constexpr (dir == Direction::kSouthWest)
    return BitBoard((bitboard >> 9) & ~kFileMasks[kFileH]);
  else
    // Default case to avoid compiler warnings, should not be reached
    return {0};
}

// Returns the bitboard of all squares "higher" than the given square from the
// given color
inline BitBoard ForwardRanks(Color color, Square square) {
  if (color == Color::kWhite)
    return ~kRankMasks[kRank1] << 8 * Rank(square);
  else
    return ~kRankMasks[kRank8] >> 8 * (kRank8 - Rank(square));
}

// Returns the bitboard of all squares "in front" of the given square from the
// given color
inline BitBoard ForwardFileMask(Color color, Square square) {
  return ForwardRanks(color, square) & kFileMasks[File(square)];
}

#endif  // INTEGRAL_BITBOARD_H_