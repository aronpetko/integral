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
  Pair(90, 169), Pair(319, 286), Pair(367, 315), Pair(475, 685), Pair(1021, 1168), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(35, 47), Pair(51, 37), Pair(20, 39), Pair(56, -22), Pair(32, -19), Pair(25, -8), Pair(-16, 46), Pair(-52, 47),
      Pair(10, 26), Pair(3, 43), Pair(43, -14), Pair(42, -55), Pair(51, -57), Pair(93, -41), Pair(51, 23), Pair(16, 6),
      Pair(-16, 0), Pair(-8, 3), Pair(0, -23), Pair(4, -45), Pair(31, -48), Pair(29, -44), Pair(20, -6), Pair(5, -33),
      Pair(-24, -22), Pair(-20, -10), Pair(-9, -33), Pair(9, -42), Pair(12, -42), Pair(18, -44), Pair(17, -21), Pair(3, -49),
      Pair(-23, -29), Pair(-14, -15), Pair(-7, -35), Pair(-1, -33), Pair(12, -31), Pair(12, -41), Pair(25, -25), Pair(7, -53),
      Pair(-22, -22), Pair(-14, -7), Pair(-11, -24), Pair(-15, -26), Pair(0, -14), Pair(22, -35), Pair(32, -20), Pair(-7, -50),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-166, -32), Pair(-140, 26), Pair(-71, 41), Pair(-31, 27), Pair(5, 31), Pair(-64, 2), Pair(-124, 25), Pair(-115, -55),
      Pair(-17, 32), Pair(5, 45), Pair(36, 38), Pair(57, 37), Pair(26, 29), Pair(98, 14), Pair(0, 42), Pair(27, 6),
      Pair(3, 36), Pair(35, 44), Pair(45, 71), Pair(60, 70), Pair(103, 52), Pair(103, 41), Pair(58, 35), Pair(29, 24),
      Pair(6, 55), Pair(10, 65), Pair(34, 81), Pair(61, 83), Pair(39, 82), Pair(64, 78), Pair(22, 67), Pair(47, 42),
      Pair(-8, 59), Pair(0, 56), Pair(14, 83), Pair(22, 81), Pair(31, 86), Pair(28, 72), Pair(38, 55), Pair(9, 54),
      Pair(-34, 38), Pair(-11, 48), Pair(-2, 56), Pair(9, 74), Pair(30, 69), Pair(10, 50), Pair(17, 42), Pair(-7, 45),
      Pair(-38, 39), Pair(-24, 46), Pair(-11, 48), Pair(9, 47), Pair(11, 45), Pair(7, 42), Pair(2, 34), Pair(-1, 51),
      Pair(-75, 43), Pair(-30, 27), Pair(-33, 43), Pair(-12, 48), Pair(-5, 49), Pair(-1, 35), Pair(-26, 36), Pair(-36, 38)
  },
  {
      Pair(-31, 68), Pair(-56, 71), Pair(-50, 62), Pair(-101, 73), Pair(-83, 69), Pair(-77, 58), Pair(-31, 58), Pair(-52, 52),
      Pair(-3, 46), Pair(17, 59), Pair(4, 60), Pair(-12, 65), Pair(21, 50), Pair(11, 56), Pair(7, 61), Pair(-13, 49),
      Pair(2, 68), Pair(24, 62), Pair(23, 70), Pair(41, 56), Pair(31, 62), Pair(66, 70), Pair(41, 62), Pair(32, 65),
      Pair(-9, 63), Pair(13, 72), Pair(27, 70), Pair(49, 86), Pair(41, 77), Pair(31, 76), Pair(13, 68), Pair(-3, 63),
      Pair(-1, 58), Pair(-2, 72), Pair(9, 81), Pair(39, 81), Pair(37, 80), Pair(5, 76), Pair(5, 67), Pair(19, 46),
      Pair(2, 58), Pair(22, 72), Pair(18, 73), Pair(17, 78), Pair(21, 82), Pair(22, 72), Pair(22, 63), Pair(26, 50),
      Pair(18, 65), Pair(18, 49), Pair(29, 50), Pair(8, 64), Pair(20, 61), Pair(30, 56), Pair(42, 53), Pair(26, 45),
      Pair(2, 53), Pair(31, 68), Pair(2, 57), Pair(-3, 61), Pair(6, 60), Pair(1, 69), Pair(18, 49), Pair(32, 28)
  },
  {
      Pair(-1, 57), Pair(-9, 73), Pair(-6, 72), Pair(-10, 65), Pair(5, 53), Pair(14, 65), Pair(0, 68), Pair(-15, 63),
      Pair(-16, 61), Pair(-14, 81), Pair(7, 75), Pair(24, 61), Pair(4, 60), Pair(32, 63), Pair(11, 63), Pair(6, 52),
      Pair(-33, 60), Pair(0, 65), Pair(-1, 60), Pair(-2, 53), Pair(33, 37), Pair(41, 43), Pair(69, 40), Pair(10, 33),
      Pair(-36, 60), Pair(-20, 63), Pair(-17, 65), Pair(-11, 57), Pair(-9, 40), Pair(-4, 48), Pair(-5, 51), Pair(-21, 39),
      Pair(-45, 48), Pair(-46, 61), Pair(-32, 53), Pair(-27, 50), Pair(-26, 43), Pair(-41, 56), Pair(-15, 43), Pair(-32, 30),
      Pair(-48, 39), Pair(-42, 45), Pair(-34, 40), Pair(-34, 43), Pair(-20, 31), Pair(-22, 35), Pair(11, 12), Pair(-15, 7),
      Pair(-47, 30), Pair(-40, 42), Pair(-23, 38), Pair(-20, 37), Pair(-14, 24), Pair(-12, 28), Pair(-6, 18), Pair(-43, 14),
      Pair(-30, 34), Pair(-24, 37), Pair(-16, 41), Pair(-10, 33), Pair(-4, 24), Pair(-9, 34), Pair(-18, 27), Pair(-24, 12)
  },
  {
      Pair(-26, 140), Pair(-33, 161), Pair(-11, 185), Pair(31, 164), Pair(32, 165), Pair(42, 163), Pair(91, 94), Pair(13, 147),
      Pair(13, 123), Pair(-14, 164), Pair(-11, 199), Pair(-26, 227), Pair(-18, 246), Pair(32, 197), Pair(25, 178), Pair(74, 163),
      Pair(15, 132), Pair(9, 147), Pair(7, 186), Pair(18, 194), Pair(28, 211), Pair(82, 189), Pair(87, 156), Pair(82, 153),
      Pair(1, 140), Pair(6, 155), Pair(8, 170), Pair(8, 196), Pair(9, 211), Pair(23, 200), Pair(31, 194), Pair(34, 178),
      Pair(7, 128), Pair(1, 160), Pair(7, 160), Pair(12, 184), Pair(16, 179), Pair(14, 179), Pair(24, 169), Pair(32, 160),
      Pair(9, 109), Pair(14, 134), Pair(14, 146), Pair(11, 147), Pair(17, 154), Pair(23, 154), Pair(37, 136), Pair(32, 126),
      Pair(15, 101), Pair(18, 102), Pair(25, 105), Pair(33, 106), Pair(29, 115), Pair(38, 90), Pair(44, 67), Pair(47, 46),
      Pair(6, 100), Pair(15, 98), Pair(19, 101), Pair(23, 112), Pair(28, 96), Pair(13, 98), Pair(25, 77), Pair(25, 66)
  },
  {
      Pair(87, -131), Pair(103, -74), Pair(102, -54), Pair(-57, 1), Pair(-19, -13), Pair(40, -14), Pair(103, -30), Pair(216, -154),
      Pair(-59, -16), Pair(-2, 19), Pair(-40, 32), Pair(75, 15), Pair(10, 35), Pair(16, 53), Pair(48, 35), Pair(16, -1),
      Pair(-98, -4), Pair(50, 15), Pair(-18, 39), Pair(-47, 55), Pair(-2, 58), Pair(80, 39), Pair(18, 40), Pair(-15, 2),
      Pair(-49, -21), Pair(-40, 12), Pair(-68, 39), Pair(-124, 58), Pair(-115, 54), Pair(-88, 46), Pair(-84, 24), Pair(-127, 5),
      Pair(-45, -34), Pair(-43, -1), Pair(-90, 32), Pair(-134, 52), Pair(-134, 49), Pair(-88, 28), Pair(-83, 9), Pair(-130, -5),
      Pair(-8, -41), Pair(11, -15), Pair(-53, 15), Pair(-75, 31), Pair(-72, 30), Pair(-75, 18), Pair(-31, -9), Pair(-36, -25),
      Pair(75, -59), Pair(0, -18), Pair(2, -5), Pair(-19, 3), Pair(-31, 8), Pair(-22, -2), Pair(5, -22), Pair(53, -54),
      Pair(67, -101), Pair(69, -66), Pair(65, -49), Pair(-12, -31), Pair(51, -56), Pair(-8, -28), Pair(51, -59), Pair(80, -107)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(1, 43), Pair(23, 85), Pair(35, 107), Pair(43, 119), Pair(50, 128), Pair(56, 138), Pair(65, 135), Pair(73, 130),
  Pair(80, 117)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-31, 15), Pair(-19, 41), Pair(-5, 61), Pair(4, 78), Pair(13, 89), Pair(19, 102), Pair(24, 106), Pair(27, 108),
  Pair(30, 112), Pair(35, 107), Pair(45, 101), Pair(53, 99), Pair(54, 109), Pair(65, 82)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(3, 45), Pair(13, 70), Pair(17, 72), Pair(21, 79), Pair(18, 89), Pair(24, 93), Pair(27, 100), Pair(31, 103),
  Pair(34, 105), Pair(38, 110), Pair(43, 111), Pair(44, 116), Pair(50, 116), Pair(53, 112), Pair(42, 114)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-14, 14), Pair(-12, 52), Pair(-24, 139), Pair(-19, 169), Pair(-19, 190), Pair(-14, 199), Pair(-12, 218), Pair(-10, 235),
  Pair(-6, 245), Pair(-4, 248), Pair(-2, 257), Pair(1, 264), Pair(4, 265), Pair(4, 274), Pair(6, 278), Pair(9, 283),
  Pair(9, 294), Pair(11, 296), Pair(20, 295), Pair(35, 285), Pair(38, 289), Pair(95, 254), Pair(82, 266), Pair(106, 244),
  Pair(171, 235), Pair(162, 212), Pair(128, 248), Pair(220, 173)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-4, 0), Pair(-14, 11), Pair(-9, 42), Pair(14, 73), Pair(12, 148), Pair(63, 191), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(-1, -9), Pair(-1, 0), Pair(22, 11), Pair(50, 57), Pair(135, 221), Pair(-121, 531), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-15, -50), Pair(1, -39), Pair(-6, -32), Pair(-3, -21), Pair(-14, -13), Pair(-18, -26), Pair(-14, -40), Pair(-13, -62)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-9, 3), Pair(-10, -19), Pair(-21, -14), Pair(-18, -23), Pair(-23, -22), Pair(-14, -10), Pair(-9, -21), Pair(-12, 9)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(31, 13), Pair(31, 4), Pair(27, 13), Pair(31, 14), Pair(36, 19), Pair(60, -3), Pair(78, -5), Pair(110, -4)
  },
  {
      Pair(1, 55), Pair(9, 21), Pair(7, 20), Pair(18, 12), Pair(13, 15), Pair(23, 2), Pair(42, 0), Pair(26, 31)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(21, 0), Pair(42, 0), Pair(17, 4),
  Pair(33, -6), Pair(54, -9), Pair(31, -7),
  Pair(47, 1), Pair(0, 0), Pair(43, 1),
  Pair(-23, 4), Pair(18, 5), Pair(-23, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-18, 10), Pair(-28, 7), Pair(-18, 11),
  Pair(-15, 10), Pair(-29, 9), Pair(-18, 11),
  Pair(-7, -1), Pair(-24, 1), Pair(-6, 1),
  Pair(8, -3), Pair(-15, -4), Pair(7, 1),
  Pair(26, -7), Pair(16, -8), Pair(17, -7),
  Pair(0, 0), Pair(-91, -49), Pair(0, 0),
  Pair(-16, -57), Pair(0, 0), Pair(-22, -55)
};

constexpr ScorePair kBishopPairBonus = Pair(25, 84);
constexpr ScorePair kTempoBonus = Pair(23, 29);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H