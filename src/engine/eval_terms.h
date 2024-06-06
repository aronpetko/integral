#ifndef INTEGRAL_EVAL_TERMS_H
#define INTEGRAL_EVAL_TERMS_H

#include "../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceValueTable = std::array<T, PieceType::kNumTypes>;

template <typename T>
using PieceSquareTable = std::array<std::array<T, kSquareCount>,
                                    PieceType::kNumTypes>;

template <typename T>
using KnightMobilityTable = std::array<T, 9>;

template <typename T>
using RookMobilityTable = std::array<T, 15>;

template <typename T>
using BishopMobilityTable = std::array<T, 14>;

template <typename T>
using QueenMobilityTable = std::array<T, 28>;

template <typename T>
using RankTable = std::array<T, kNumRanks>;

template <typename T>
using FileTable = std::array<T, kNumFiles>;

constexpr PieceValueTable<ScorePair> kPieceValues = {
  Pair(86, 156), Pair(320, 294), Pair(376, 321), Pair(470, 684), Pair(1008, 1178), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(48, 57), Pair(56, 43), Pair(37, 41), Pair(77, -29), Pair(49, -27), Pair(27, -13), Pair(-62, 50), Pair(-89, 61),
      Pair(21, 37), Pair(13, 48), Pair(53, -10), Pair(59, -57), Pair(68, -61), Pair(111, -41), Pair(66, 23), Pair(35, 10),
      Pair(-9, 13), Pair(-3, 9), Pair(4, -17), Pair(10, -42), Pair(36, -42), Pair(41, -40), Pair(21, -3), Pair(17, -23),
      Pair(-17, -12), Pair(-18, -2), Pair(-5, -26), Pair(13, -35), Pair(14, -34), Pair(21, -37), Pair(12, -15), Pair(4, -38),
      Pair(-18, -17), Pair(-11, -7), Pair(-4, -24), Pair(0, -25), Pair(13, -22), Pair(8, -28), Pair(19, -17), Pair(3, -41),
      Pair(-16, -11), Pair(-11, 1), Pair(-9, -14), Pair(-15, -17), Pair(0, -4), Pair(15, -19), Pair(25, -11), Pair(-13, -36),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-172, -34), Pair(-145, 26), Pair(-75, 41), Pair(-37, 27), Pair(1, 29), Pair(-71, 4), Pair(-125, 28), Pair(-119, -56),
      Pair(-22, 31), Pair(3, 43), Pair(31, 35), Pair(55, 33), Pair(23, 28), Pair(96, 13), Pair(-6, 43), Pair(26, 9),
      Pair(0, 35), Pair(32, 41), Pair(43, 66), Pair(58, 65), Pair(101, 48), Pair(103, 39), Pair(56, 34), Pair(26, 25),
      Pair(3, 52), Pair(7, 60), Pair(32, 77), Pair(59, 79), Pair(36, 77), Pair(63, 75), Pair(20, 61), Pair(43, 42),
      Pair(-11, 54), Pair(-2, 53), Pair(12, 77), Pair(20, 76), Pair(29, 81), Pair(26, 67), Pair(36, 53), Pair(7, 51),
      Pair(-36, 34), Pair(-13, 42), Pair(-4, 48), Pair(8, 69), Pair(27, 64), Pair(9, 43), Pair(16, 35), Pair(-8, 41),
      Pair(-41, 36), Pair(-26, 43), Pair(-13, 43), Pair(7, 41), Pair(9, 39), Pair(6, 37), Pair(0, 32), Pair(-4, 48),
      Pair(-79, 41), Pair(-33, 26), Pair(-35, 38), Pair(-14, 44), Pair(-8, 44), Pair(-3, 31), Pair(-28, 33), Pair(-43, 40)
  },
  {
      Pair(-26, 62), Pair(-56, 71), Pair(-47, 62), Pair(-99, 74), Pair(-82, 69), Pair(-75, 58), Pair(-27, 56), Pair(-50, 55),
      Pair(0, 46), Pair(22, 56), Pair(9, 59), Pair(-8, 62), Pair(24, 49), Pair(14, 53), Pair(11, 61), Pair(-7, 48),
      Pair(5, 69), Pair(27, 60), Pair(28, 67), Pair(46, 54), Pair(34, 60), Pair(70, 68), Pair(44, 60), Pair(34, 65),
      Pair(-4, 63), Pair(19, 70), Pair(31, 67), Pair(55, 81), Pair(46, 75), Pair(34, 72), Pair(17, 67), Pair(0, 66),
      Pair(5, 58), Pair(2, 70), Pair(14, 79), Pair(45, 78), Pair(41, 75), Pair(11, 73), Pair(8, 67), Pair(24, 45),
      Pair(6, 58), Pair(27, 72), Pair(23, 73), Pair(22, 75), Pair(26, 80), Pair(26, 70), Pair(27, 60), Pair(29, 50),
      Pair(22, 63), Pair(23, 49), Pair(33, 50), Pair(12, 63), Pair(25, 61), Pair(35, 54), Pair(47, 52), Pair(30, 44),
      Pair(9, 52), Pair(34, 68), Pair(8, 57), Pair(0, 63), Pair(10, 60), Pair(6, 70), Pair(24, 47), Pair(34, 31)
  },
  {
      Pair(-3, 56), Pair(-12, 73), Pair(-7, 71), Pair(-10, 64), Pair(2, 52), Pair(14, 64), Pair(-2, 68), Pair(-27, 66),
      Pair(-18, 61), Pair(-16, 82), Pair(5, 76), Pair(25, 61), Pair(2, 59), Pair(29, 62), Pair(5, 65), Pair(-2, 55),
      Pair(-34, 60), Pair(-2, 66), Pair(-1, 59), Pair(-2, 54), Pair(29, 38), Pair(38, 44), Pair(72, 41), Pair(6, 38),
      Pair(-38, 60), Pair(-23, 66), Pair(-19, 65), Pair(-11, 58), Pair(-10, 40), Pair(-7, 50), Pair(-7, 52), Pair(-25, 42),
      Pair(-47, 48), Pair(-48, 63), Pair(-33, 53), Pair(-29, 51), Pair(-29, 44), Pair(-42, 56), Pair(-18, 44), Pair(-37, 33),
      Pair(-50, 39), Pair(-43, 46), Pair(-36, 39), Pair(-35, 41), Pair(-23, 30), Pair(-23, 34), Pair(8, 12), Pair(-20, 8),
      Pair(-49, 30), Pair(-41, 43), Pair(-24, 37), Pair(-22, 35), Pair(-16, 23), Pair(-13, 28), Pair(-7, 18), Pair(-47, 15),
      Pair(-31, 33), Pair(-25, 37), Pair(-18, 40), Pair(-11, 32), Pair(-5, 21), Pair(-11, 32), Pair(-17, 26), Pair(-27, 11)
  },
  {
      Pair(-24, 138), Pair(-32, 161), Pair(-11, 185), Pair(31, 165), Pair(37, 163), Pair(44, 164), Pair(95, 93), Pair(15, 146),
      Pair(14, 122), Pair(-14, 164), Pair(-11, 199), Pair(-25, 226), Pair(-19, 247), Pair(32, 197), Pair(27, 177), Pair(77, 162),
      Pair(15, 132), Pair(9, 147), Pair(8, 187), Pair(18, 196), Pair(28, 213), Pair(83, 190), Pair(88, 155), Pair(81, 152),
      Pair(0, 140), Pair(5, 155), Pair(8, 169), Pair(7, 197), Pair(8, 213), Pair(22, 201), Pair(30, 194), Pair(33, 179),
      Pair(6, 128), Pair(0, 160), Pair(6, 161), Pair(12, 184), Pair(14, 181), Pair(13, 180), Pair(24, 166), Pair(32, 159),
      Pair(9, 109), Pair(14, 133), Pair(14, 145), Pair(10, 148), Pair(16, 154), Pair(23, 152), Pair(37, 134), Pair(32, 124),
      Pair(14, 101), Pair(17, 101), Pair(25, 104), Pair(32, 107), Pair(29, 115), Pair(39, 90), Pair(46, 65), Pair(49, 43),
      Pair(7, 98), Pair(14, 98), Pair(20, 101), Pair(23, 113), Pair(26, 96), Pair(15, 96), Pair(27, 75), Pair(26, 61)
  },
  {
      Pair(79, -132), Pair(97, -75), Pair(97, -53), Pair(-63, 2), Pair(-29, -10), Pair(37, -13), Pair(98, -25), Pair(207, -156),
      Pair(-68, -15), Pair(-14, 24), Pair(-52, 35), Pair(69, 16), Pair(0, 42), Pair(13, 57), Pair(39, 44), Pair(10, 2),
      Pair(-99, 1), Pair(36, 27), Pair(-36, 49), Pair(-63, 62), Pair(-14, 66), Pair(81, 55), Pair(35, 53), Pair(-10, 12),
      Pair(-59, -12), Pair(-60, 28), Pair(-88, 53), Pair(-146, 69), Pair(-128, 69), Pair(-89, 64), Pair(-79, 47), Pair(-122, 16),
      Pair(-68, -24), Pair(-68, 12), Pair(-109, 43), Pair(-154, 64), Pair(-153, 63), Pair(-104, 44), Pair(-111, 27), Pair(-143, 8),
      Pair(-24, -35), Pair(-7, -8), Pair(-75, 23), Pair(-103, 40), Pair(-93, 39), Pair(-94, 26), Pair(-47, -1), Pair(-52, -18),
      Pair(63, -57), Pair(-9, -17), Pair(-10, -4), Pair(-41, 8), Pair(-50, 12), Pair(-29, -1), Pair(7, -23), Pair(43, -52),
      Pair(62, -102), Pair(72, -71), Pair(64, -53), Pair(-23, -32), Pair(45, -59), Pair(-5, -34), Pair(62, -68), Pair(80, -110)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-1, 33), Pair(21, 75), Pair(34, 101), Pair(41, 112), Pair(48, 121), Pair(55, 133), Pair(63, 131), Pair(70, 128),
  Pair(77, 115)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-24, 16), Pair(-10, 41), Pair(3, 61), Pair(11, 78), Pair(21, 90), Pair(27, 103), Pair(32, 108), Pair(35, 111),
  Pair(37, 115), Pair(43, 111), Pair(53, 106), Pair(62, 103), Pair(61, 115), Pair(75, 85)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(7, 42), Pair(15, 70), Pair(20, 73), Pair(23, 78), Pair(21, 88), Pair(27, 93), Pair(29, 100), Pair(32, 103),
  Pair(37, 106), Pair(41, 110), Pair(45, 112), Pair(44, 117), Pair(49, 119), Pair(54, 115), Pair(42, 117)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-20, 20), Pair(-17, 43), Pair(-28, 134), Pair(-25, 165), Pair(-23, 187), Pair(-19, 197), Pair(-16, 216), Pair(-15, 231),
  Pair(-12, 239), Pair(-9, 243), Pair(-7, 251), Pair(-3, 259), Pair(-1, 262), Pair(-2, 272), Pair(0, 274), Pair(3, 281),
  Pair(2, 291), Pair(5, 292), Pair(14, 290), Pair(30, 281), Pair(33, 285), Pair(91, 251), Pair(79, 262), Pair(86, 251),
  Pair(126, 259), Pair(137, 225), Pair(121, 252), Pair(218, 178)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-8, 3), Pair(-15, 13), Pair(-8, 42), Pair(14, 70), Pair(2, 147), Pair(46, 194), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -8), Pair(-1, 1), Pair(20, 16), Pair(50, 63), Pair(139, 235), Pair(-99, 533), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-18, -45), Pair(2, -35), Pair(-7, -27), Pair(-5, -15), Pair(-16, -10), Pair(-20, -23), Pair(-19, -35), Pair(-22, -53)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-9, 1), Pair(-8, -18), Pair(-20, -14), Pair(-19, -22), Pair(-22, -24), Pair(-12, -12), Pair(-8, -18), Pair(-8, 5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(34, 10), Pair(32, 0), Pair(28, 12), Pair(30, 13), Pair(38, 17), Pair(59, -3), Pair(82, -9), Pair(122, -10)
  },
  {
      Pair(4, 51), Pair(10, 17), Pair(9, 18), Pair(16, 8), Pair(12, 12), Pair(26, -3), Pair(42, -4), Pair(31, 27)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(20, -3), Pair(38, -1), Pair(17, 1),
  Pair(34, -8), Pair(50, -10), Pair(31, -8),
  Pair(46, -1), Pair(0, 0), Pair(41, -1),
  Pair(-28, 19), Pair(14, 5), Pair(-27, 19)
};

constexpr ScorePair kTempoBonus = Pair(24, 29);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H