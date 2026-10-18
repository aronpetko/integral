#ifndef INTEGRAL_NNUE_GEOMETRY_H
#define INTEGRAL_NNUE_GEOMETRY_H

#include <array>

#include "../../../../../utils/types.h"

namespace nnue::geometry {

// Single-bit-per-piece-type flags, used to build compact masks of
// "which piece types can be responsible for this kind of attack".
namespace bit {

constexpr U8 kWhitePawn = 0x01;
constexpr U8 kBlackPawn = 0x02;
constexpr U8 kKnight = 0x04;
constexpr U8 kBishop = 0x08;
constexpr U8 kRook = 0x10;
constexpr U8 kQueen = 0x20;
constexpr U8 kKing = 0x40;

}  // namespace bit

// The "ray-vector" format. One square's full super-piece attack
// pattern packed into 8 bytes, one byte per compass direction, in the
// order N, NE, E, SE, S, SW, W, NW. Within each byte, bit 0 is the
// "knight attacks from here" flag, and bits 1-7 mark ray steps at
// distance 1..7 in that direction.
using BitRays = U64;

constexpr int PieceIndex(PieceType piece_type, Color color) noexcept {
  return static_cast<int>(piece_type) * 2 + static_cast<int>(color);
}

// Get the bit flag used to identify a piece in mailbox representation consumed
// by the permutation gather.
constexpr U8 PieceTobit(PieceType piece_type, Color color) noexcept {
  switch (piece_type) {
    case PieceType::kPawn:
      return color == Color::kWhite ? bit::kWhitePawn : bit::kBlackPawn;
    case PieceType::kKnight:
      return bit::kKnight;
    case PieceType::kBishop:
      return bit::kBishop;
    case PieceType::kRook:
      return bit::kRook;
    case PieceType::kQueen:
      return bit::kQueen;
    case PieceType::kKing:
      return bit::kKing;
    default:
      return 0;
  }
}

// Given a "focus" square, which byte-slot in the ray-vector layout does square
// 'i' occupy relative to focus.
constexpr std::array<std::array<U8, 64>, 64> ComputePermutation() noexcept {
  constexpr std::array<int, 64> kOffsets = {
      0x1F, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,  // N
      0x21, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,  // NE
      0x12, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,  // E
      0xF2, 0xF1, 0xE2, 0xD3, 0xC4, 0xB5, 0xA6, 0x97,  // SE
      0xE1, 0xF0, 0xE0, 0xD0, 0xC0, 0xB0, 0xA0, 0x90,  // S
      0xDF, 0xEF, 0xDE, 0xCD, 0xBC, 0xAB, 0x9A, 0x89,  // SW
      0xEE, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9,  // W
      0x0E, 0x0F, 0x1E, 0x2D, 0x3C, 0x4B, 0x5A, 0x69,  // NW
  };

  std::array<std::array<U8, 64>, 64> permutations{};

  for (int focus = 0; focus < 64; ++focus) {
    for (int i = 0; i < 64; ++i) {
      const int wide_focus = focus + (focus & 0x38);
      const int wide_result = kOffsets[i] + wide_focus;
      const int result = ((wide_result & 0x70) >> 1) | (wide_result & 0x07);
      const bool valid = (wide_result & 0x88) == 0;
      permutations[focus][i] =
          valid ? static_cast<U8>(result) : static_cast<U8>(0x80);
    }
  }

  return permutations;
}

inline constexpr auto kPermutation = ComputePermutation();

// Which ray-vector slots (direction + distance) a piece of this type/color can
// actually attack through, in the same 8-byte layout as BitRays. Used to mask a
// "nearest occupant per ray" vector down to only the slots this piece is
// capable of using. Kings are zeroed out.
constexpr std::array<BitRays, 12> ComputeOutgoingThreats() noexcept {
  std::array<BitRays, 12> lut{};
  lut[PieceIndex(PieceType::kPawn, Color::kWhite)] = 0x0200000000020000ULL;
  lut[PieceIndex(PieceType::kPawn, Color::kBlack)] = 0x0000020002000000ULL;
  lut[PieceIndex(PieceType::kKnight, Color::kWhite)] = 0x0101010101010101ULL;
  lut[PieceIndex(PieceType::kKnight, Color::kBlack)] = 0x0101010101010101ULL;
  lut[PieceIndex(PieceType::kBishop, Color::kWhite)] = 0xFE00FE00FE00FE00ULL;
  lut[PieceIndex(PieceType::kBishop, Color::kBlack)] = 0xFE00FE00FE00FE00ULL;
  lut[PieceIndex(PieceType::kRook, Color::kWhite)] = 0x00FE00FE00FE00FEULL;
  lut[PieceIndex(PieceType::kRook, Color::kBlack)] = 0x00FE00FE00FE00FEULL;
  lut[PieceIndex(PieceType::kQueen, Color::kWhite)] = 0xFEFEFEFEFEFEFEFEULL;
  lut[PieceIndex(PieceType::kQueen, Color::kBlack)] = 0xFEFEFEFEFEFEFEFEULL;
  lut[PieceIndex(PieceType::kKing, Color::kWhite)] = 0ULL;  // Excluded
  lut[PieceIndex(PieceType::kKing, Color::kBlack)] = 0ULL;  // Excluded
  return lut;
}

inline constexpr auto kOutgoingThreats = ComputeOutgoingThreats();

namespace detail {

constexpr U8 kHors = bit::kKnight;
constexpr U8 kOrth = bit::kQueen | bit::kRook;
constexpr U8 kDiag = bit::kQueen | bit::kBishop;
constexpr U8 kOrnr = kOrth;
constexpr U8 kWpnr = kDiag | bit::kWhitePawn;
constexpr U8 kBpnr = kDiag | bit::kBlackPawn;
constexpr U8 kInvalidSlider = 0x80;

}  // namespace detail

// Given a ray-vector slot index (direction + distance, in N/NE/E/SE/S/SW/W/NW
// row order), which piece types could possibly be attacking through it? Knight
// slots -> knight only; orthogonal ray slots -> rook/queen; diagonal ray slots
// -> bishop/queen, except the first diagonal step, which could also be a pawn
// of the appropriate color (pawns only threaten one square diagonally).
inline constexpr std::array<U8, 64> kIncomingThreatsMask = {
    detail::kHors, detail::kOrnr, detail::kOrth, detail::kOrth,
    detail::kOrth, detail::kOrth, detail::kOrth, detail::kOrth,  // N
    detail::kHors, detail::kBpnr, detail::kDiag, detail::kDiag,
    detail::kDiag, detail::kDiag, detail::kDiag, detail::kDiag,  // NE
    detail::kHors, detail::kOrnr, detail::kOrth, detail::kOrth,
    detail::kOrth, detail::kOrth, detail::kOrth, detail::kOrth,  // E
    detail::kHors, detail::kWpnr, detail::kDiag, detail::kDiag,
    detail::kDiag, detail::kDiag, detail::kDiag, detail::kDiag,  // SE
    detail::kHors, detail::kOrnr, detail::kOrth, detail::kOrth,
    detail::kOrth, detail::kOrth, detail::kOrth, detail::kOrth,  // S
    detail::kHors, detail::kWpnr, detail::kDiag, detail::kDiag,
    detail::kDiag, detail::kDiag, detail::kDiag, detail::kDiag,  // SW
    detail::kHors, detail::kOrnr, detail::kOrth, detail::kOrth,
    detail::kOrth, detail::kOrth, detail::kOrth, detail::kOrth,  // W
    detail::kHors, detail::kBpnr, detail::kDiag, detail::kDiag,
    detail::kDiag, detail::kDiag, detail::kDiag, detail::kDiag,  // NW
};

// Same idea except restricted to sliders only.
inline constexpr std::array<U8, 64> kIncomingSlidersMask = {
    detail::kInvalidSlider, detail::kOrth, detail::kOrth, detail::kOrth,
    detail::kOrth,          detail::kOrth, detail::kOrth, detail::kOrth,  // N
    detail::kInvalidSlider, detail::kDiag, detail::kDiag, detail::kDiag,
    detail::kDiag,          detail::kDiag, detail::kDiag, detail::kDiag,  // NE
    detail::kInvalidSlider, detail::kOrth, detail::kOrth, detail::kOrth,
    detail::kOrth,          detail::kOrth, detail::kOrth, detail::kOrth,  // E
    detail::kInvalidSlider, detail::kDiag, detail::kDiag, detail::kDiag,
    detail::kDiag,          detail::kDiag, detail::kDiag, detail::kDiag,  // SE
    detail::kInvalidSlider, detail::kOrth, detail::kOrth, detail::kOrth,
    detail::kOrth,          detail::kOrth, detail::kOrth, detail::kOrth,  // S
    detail::kInvalidSlider, detail::kDiag, detail::kDiag, detail::kDiag,
    detail::kDiag,          detail::kDiag, detail::kDiag, detail::kDiag,  // SW
    detail::kInvalidSlider, detail::kOrth, detail::kOrth, detail::kOrth,
    detail::kOrth,          detail::kOrth, detail::kOrth, detail::kOrth,  // W
    detail::kInvalidSlider, detail::kDiag, detail::kDiag, detail::kDiag,
    detail::kDiag,          detail::kDiag, detail::kDiag, detail::kDiag,  // NW
};

// Given a BitRays with sparse bits marking "first occupant" per
// ray, fills every bit at-or-beyond that point in the same ray. A single
// add + mask + subtract does all 8 direction-lanes in parallel. Magic!
constexpr BitRays RayFill(BitRays br) noexcept {
  constexpr U64 kAddMask = 0x7E7E7E7E7E7E7E7EULL;
  constexpr U64 kHighbitMask = 0x8080808080808080ULL;
  br = (br + kAddMask) & kHighbitMask;
  return br - (br >> 7);
}

// Given a piece and a "closest occupant per ray" vector for its square, return
// only the slots that piece is actually capable of attacking through.
constexpr BitRays OutgoingThreats(PieceType piece_type,
                                  Color color,
                                  BitRays closest) noexcept {
  return kOutgoingThreats[PieceIndex(piece_type, color)] & closest;
}

}  // namespace nnue::geometry

#endif  // INTEGRAL_NNUE_GEOMETRY_H