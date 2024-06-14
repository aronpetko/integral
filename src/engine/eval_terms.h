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
  Pair(98, 175), Pair(321, 279), Pair(368, 315), Pair(474, 689), Pair(1019, 1154), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(29, 55), Pair(58, 27), Pair(20, 35), Pair(52, -31), Pair(29, -28), Pair(27, -7), Pair(-8, 35), Pair(-61, 58),
      Pair(6, 30), Pair(7, 32), Pair(41, -18), Pair(40, -63), Pair(50, -66), Pair(92, -37), Pair(56, 9), Pair(8, 14),
      Pair(-20, 6), Pair(-2, -6), Pair(-4, -27), Pair(2, -52), Pair(30, -55), Pair(27, -40), Pair(26, -18), Pair(-3, -23),
      Pair(-28, -17), Pair(-14, -16), Pair(-11, -36), Pair(7, -48), Pair(10, -50), Pair(17, -42), Pair(23, -32), Pair(-4, -41),
      Pair(-27, -23), Pair(-7, -21), Pair(-9, -37), Pair(-3, -37), Pair(12, -37), Pair(10, -38), Pair(32, -36), Pair(0, -47),
      Pair(-26, -17), Pair(-7, -13), Pair(-14, -28), Pair(-16, -33), Pair(-1, -22), Pair(20, -31), Pair(39, -31), Pair(-15, -43),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-164, -24), Pair(-137, 31), Pair(-70, 46), Pair(-28, 32), Pair(8, 35), Pair(-61, 7), Pair(-117, 29), Pair(-113, -48),
      Pair(-16, 36), Pair(9, 48), Pair(38, 42), Pair(58, 39), Pair(28, 32), Pair(102, 17), Pair(1, 45), Pair(28, 11),
      Pair(4, 40), Pair(36, 47), Pair(47, 73), Pair(61, 72), Pair(104, 54), Pair(104, 45), Pair(60, 38), Pair(30, 30),
      Pair(6, 59), Pair(11, 68), Pair(35, 83), Pair(62, 85), Pair(40, 84), Pair(66, 80), Pair(24, 68), Pair(47, 46),
      Pair(-7, 63), Pair(2, 59), Pair(15, 85), Pair(25, 84), Pair(34, 89), Pair(30, 75), Pair(40, 59), Pair(10, 57),
      Pair(-33, 42), Pair(-9, 50), Pair(0, 58), Pair(12, 77), Pair(32, 73), Pair(12, 52), Pair(19, 44), Pair(-5, 47),
      Pair(-38, 43), Pair(-23, 51), Pair(-9, 51), Pair(11, 50), Pair(13, 49), Pair(11, 48), Pair(3, 39), Pair(0, 55),
      Pair(-77, 48), Pair(-30, 35), Pair(-31, 46), Pair(-12, 53), Pair(-4, 53), Pair(1, 41), Pair(-26, 44), Pair(-37, 40)
  },
  {
      Pair(-30, 66), Pair(-59, 71), Pair(-52, 62), Pair(-101, 74), Pair(-85, 69), Pair(-78, 58), Pair(-35, 56), Pair(-53, 51),
      Pair(-5, 45), Pair(16, 57), Pair(3, 60), Pair(-14, 63), Pair(19, 50), Pair(9, 54), Pair(5, 61), Pair(-15, 49),
      Pair(0, 68), Pair(21, 62), Pair(19, 70), Pair(39, 56), Pair(26, 61), Pair(63, 68), Pair(38, 62), Pair(29, 64),
      Pair(-10, 63), Pair(8, 74), Pair(26, 69), Pair(46, 85), Pair(39, 75), Pair(29, 76), Pair(11, 68), Pair(-4, 63),
      Pair(-3, 58), Pair(-4, 73), Pair(7, 81), Pair(38, 80), Pair(35, 78), Pair(4, 75), Pair(4, 68), Pair(17, 46),
      Pair(-1, 59), Pair(20, 72), Pair(17, 73), Pair(16, 77), Pair(19, 82), Pair(20, 72), Pair(20, 64), Pair(24, 49),
      Pair(16, 65), Pair(17, 51), Pair(27, 51), Pair(6, 65), Pair(19, 63), Pair(29, 57), Pair(42, 55), Pair(25, 44),
      Pair(1, 52), Pair(29, 69), Pair(1, 57), Pair(-5, 62), Pair(5, 61), Pair(0, 70), Pair(18, 51), Pair(30, 26)
  },
  {
      Pair(-6, 56), Pair(-16, 69), Pair(-15, 69), Pair(-17, 62), Pair(-1, 49), Pair(14, 63), Pair(4, 63), Pair(-19, 61),
      Pair(-17, 59), Pair(-15, 77), Pair(5, 72), Pair(21, 57), Pair(4, 56), Pair(30, 61), Pair(12, 59), Pair(2, 52),
      Pair(-36, 58), Pair(-2, 62), Pair(-3, 56), Pair(-5, 51), Pair(28, 34), Pair(40, 42), Pair(66, 40), Pair(7, 34),
      Pair(-39, 59), Pair(-22, 60), Pair(-19, 60), Pair(-14, 53), Pair(-11, 37), Pair(-5, 46), Pair(-7, 49), Pair(-25, 40),
      Pair(-48, 46), Pair(-47, 58), Pair(-34, 48), Pair(-30, 47), Pair(-28, 40), Pair(-42, 54), Pair(-19, 42), Pair(-35, 30),
      Pair(-50, 36), Pair(-44, 43), Pair(-35, 37), Pair(-36, 39), Pair(-22, 28), Pair(-23, 34), Pair(9, 11), Pair(-18, 6),
      Pair(-49, 28), Pair(-41, 39), Pair(-23, 34), Pair(-22, 32), Pair(-15, 21), Pair(-11, 28), Pair(-7, 17), Pair(-45, 13),
      Pair(-31, 33), Pair(-25, 33), Pair(-17, 37), Pair(-12, 28), Pair(-4, 20), Pair(-10, 32), Pair(-19, 25), Pair(-26, 12)
  },
  {
      Pair(-30, 141), Pair(-39, 162), Pair(-16, 187), Pair(25, 167), Pair(28, 168), Pair(39, 164), Pair(87, 96), Pair(8, 150),
      Pair(15, 120), Pair(-11, 160), Pair(-9, 196), Pair(-24, 224), Pair(-17, 244), Pair(31, 196), Pair(25, 177), Pair(74, 163),
      Pair(16, 131), Pair(11, 146), Pair(8, 186), Pair(18, 194), Pair(23, 213), Pair(83, 188), Pair(85, 157), Pair(84, 153),
      Pair(2, 139), Pair(4, 157), Pair(9, 168), Pair(6, 192), Pair(7, 212), Pair(24, 199), Pair(32, 193), Pair(35, 178),
      Pair(5, 133), Pair(1, 160), Pair(8, 157), Pair(15, 180), Pair(17, 177), Pair(15, 178), Pair(25, 168), Pair(35, 160),
      Pair(11, 112), Pair(15, 131), Pair(16, 144), Pair(14, 145), Pair(19, 153), Pair(25, 154), Pair(39, 135), Pair(35, 127),
      Pair(17, 101), Pair(20, 101), Pair(27, 104), Pair(35, 107), Pair(32, 115), Pair(42, 93), Pair(47, 67), Pair(51, 49),
      Pair(9, 101), Pair(17, 99), Pair(23, 103), Pair(26, 113), Pair(30, 97), Pair(17, 101), Pair(30, 77), Pair(29, 67)
  },
  {
      Pair(91, -134), Pair(108, -77), Pair(109, -57), Pair(-54, -2), Pair(-11, -18), Pair(40, -15), Pair(112, -32), Pair(223, -157),
      Pair(-59, -18), Pair(2, 17), Pair(-29, 28), Pair(75, 12), Pair(17, 31), Pair(20, 50), Pair(56, 33), Pair(22, -2),
      Pair(-99, -6), Pair(52, 13), Pair(-16, 37), Pair(-48, 53), Pair(-2, 55), Pair(79, 37), Pair(16, 40), Pair(-15, 3),
      Pair(-49, -21), Pair(-43, 12), Pair(-66, 37), Pair(-124, 56), Pair(-114, 53), Pair(-88, 44), Pair(-82, 26), Pair(-128, 7),
      Pair(-44, -34), Pair(-42, -2), Pair(-92, 31), Pair(-137, 52), Pair(-132, 49), Pair(-88, 28), Pair(-83, 10), Pair(-130, -5),
      Pair(-9, -40), Pair(13, -14), Pair(-51, 15), Pair(-72, 32), Pair(-69, 30), Pair(-72, 18), Pair(-28, -7), Pair(-34, -26),
      Pair(75, -60), Pair(2, -18), Pair(5, -6), Pair(-14, 3), Pair(-27, 8), Pair(-18, -2), Pair(7, -22), Pair(52, -55),
      Pair(66, -102), Pair(72, -66), Pair(67, -50), Pair(-9, -30), Pair(55, -56), Pair(-6, -29), Pair(53, -58), Pair(81, -107)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(2, 78), Pair(19, 85), Pair(31, 110), Pair(38, 122), Pair(46, 131), Pair(52, 142), Pair(61, 140), Pair(68, 136),
  Pair(75, 122)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-33, 36), Pair(-19, 40), Pair(-6, 58), Pair(3, 77), Pair(12, 89), Pair(19, 102), Pair(24, 107), Pair(27, 110),
  Pair(29, 114), Pair(34, 109), Pair(45, 104), Pair(53, 101), Pair(54, 111), Pair(62, 84)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(4, 31), Pair(13, 66), Pair(17, 70), Pair(21, 76), Pair(19, 85), Pair(24, 91), Pair(26, 98), Pair(31, 99),
  Pair(34, 104), Pair(38, 108), Pair(42, 109), Pair(41, 114), Pair(45, 116), Pair(49, 112), Pair(37, 111)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-18, -13), Pair(-10, -51), Pair(-22, 103), Pair(-19, 158), Pair(-18, 187), Pair(-14, 202), Pair(-11, 224), Pair(-10, 240),
  Pair(-6, 249), Pair(-3, 254), Pair(-1, 262), Pair(2, 270), Pair(6, 273), Pair(5, 282), Pair(6, 286), Pair(10, 290),
  Pair(10, 301), Pair(10, 303), Pair(21, 302), Pair(35, 294), Pair(38, 298), Pair(98, 261), Pair(80, 276), Pair(108, 250),
  Pair(202, 227), Pair(187, 207), Pair(144, 256), Pair(227, 178)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-15, -7), Pair(-23, 3), Pair(-18, 34), Pair(9, 66), Pair(7, 140), Pair(58, 181), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(0, 5), Pair(23, 17), Pair(52, 65), Pair(137, 236), Pair(-140, 544), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-26, -61), Pair(-13, -48), Pair(-17, -48), Pair(-14, -35), Pair(-23, -28), Pair(-28, -42), Pair(-28, -37), Pair(-26, -64)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-9, 3), Pair(-10, -19), Pair(-21, -14), Pair(-18, -23), Pair(-23, -22), Pair(-14, -10), Pair(-9, -21), Pair(-12, 9)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(33, 12), Pair(31, 4), Pair(28, 15), Pair(33, 15), Pair(35, 20), Pair(60, -4), Pair(77, -6), Pair(113, -6)
  },
  {
      Pair(4, 55), Pair(11, 23), Pair(8, 25), Pair(19, 15), Pair(13, 16), Pair(25, 2), Pair(45, 0), Pair(27, 31)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(22, -1), Pair(42, 1), Pair(17, 4),
  Pair(34, -8), Pair(53, -8), Pair(32, -9),
  Pair(48, 0), Pair(0, 0), Pair(43, 1),
  Pair(-20, 3), Pair(19, 4), Pair(-21, 5)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-17, 9), Pair(-27, 7), Pair(-18, 12),
  Pair(-14, 10), Pair(-28, 8), Pair(-17, 12),
  Pair(-6, 1), Pair(-23, 1), Pair(-6, 3),
  Pair(8, -1), Pair(-13, -6), Pair(6, 2),
  Pair(26, -7), Pair(18, -9), Pair(17, -6),
  Pair(0, 0), Pair(-86, -50), Pair(0, 0),
  Pair(-15, -56), Pair(0, 0), Pair(-18, -53)
};

constexpr ScorePair kBishopPairBonus = Pair(26, 78);
constexpr ScorePair kTempoBonus = Pair(25, 31);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H