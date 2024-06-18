#ifndef INTEGRAL_EVALUATION_TERMS_H
#define INTEGRAL_EVALUATION_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceTable = std::array<T, kNumPieceTypes>;

template <typename T>
using PieceSquareTable = std::array<std::array<T, kSquareCount>,
                                    kNumPieceTypes>;

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

constexpr PieceTable<ScorePair> kPieceValues = {
  Pair(82, 158), Pair(297, 323), Pair(349, 342), Pair(417, 697), Pair(863, 1270), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(46, 148), Pair(51, 139), Pair(33, 140), Pair(62, 88), Pair(45, 89), Pair(35, 102), Pair(-17, 151), Pair(-33, 153),
      Pair(3, 4), Pair(-6, 17), Pair(27, -30), Pair(29, -66), Pair(37, -69), Pair(68, -51), Pair(23, 3), Pair(3, -9),
      Pair(-19, -17), Pair(-16, -17), Pair(-8, -38), Pair(-3, -58), Pair(19, -60), Pair(15, -54), Pair(-3, -21), Pair(-6, -40),
      Pair(-25, -37), Pair(-26, -26), Pair(-16, -46), Pair(1, -55), Pair(2, -56), Pair(7, -56), Pair(-8, -32), Pair(-8, -54),
      Pair(-25, -41), Pair(-20, -31), Pair(-14, -47), Pair(-9, -47), Pair(3, -48), Pair(0, -52), Pair(4, -38), Pair(-5, -58),
      Pair(-23, -36), Pair(-21, -26), Pair(-18, -40), Pair(-20, -46), Pair(-6, -36), Pair(8, -48), Pair(12, -35), Pair(-17, -55),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-138, -46), Pair(-116, 1), Pair(-60, 14), Pair(-25, 1), Pair(4, 6), Pair(-55, -18), Pair(-97, -1), Pair(-97, -64),
      Pair(-17, 5), Pair(4, 16), Pair(30, 10), Pair(47, 8), Pair(21, 3), Pair(83, -11), Pair(-1, 12), Pair(21, -17),
      Pair(1, 8), Pair(28, 13), Pair(39, 34), Pair(49, 33), Pair(85, 18), Pair(87, 8), Pair(49, 4), Pair(23, -2),
      Pair(4, 22), Pair(7, 29), Pair(27, 40), Pair(50, 42), Pair(31, 41), Pair(53, 38), Pair(18, 29), Pair(39, 12),
      Pair(-8, 24), Pair(0, 21), Pair(11, 42), Pair(19, 40), Pair(27, 47), Pair(22, 31), Pair(31, 19), Pair(6, 19),
      Pair(-30, 6), Pair(-10, 13), Pair(-2, 18), Pair(8, 38), Pair(24, 32), Pair(8, 12), Pair(13, 5), Pair(-6, 11),
      Pair(-33, 11), Pair(-21, 18), Pair(-9, 19), Pair(7, 18), Pair(9, 17), Pair(7, 15), Pair(2, 8), Pair(-2, 20),
      Pair(-64, 14), Pair(-26, 5), Pair(-27, 15), Pair(-12, 20), Pair(-5, 20), Pair(-1, 9), Pair(-23, 12), Pair(-32, 9)
  },
  {
      Pair(-41, 25), Pair(-65, 29), Pair(-59, 22), Pair(-101, 31), Pair(-85, 28), Pair(-82, 18), Pair(-42, 17), Pair(-60, 13),
      Pair(-21, 7), Pair(-3, 16), Pair(-12, 18), Pair(-26, 21), Pair(2, 10), Pair(-7, 14), Pair(-11, 17), Pair(-27, 10),
      Pair(-14, 25), Pair(3, 17), Pair(1, 23), Pair(17, 12), Pair(8, 15), Pair(37, 22), Pair(17, 18), Pair(9, 23),
      Pair(-22, 20), Pair(-7, 24), Pair(5, 20), Pair(23, 33), Pair(17, 25), Pair(9, 26), Pair(-5, 20), Pair(-16, 21),
      Pair(-16, 16), Pair(-19, 23), Pair(-8, 32), Pair(16, 30), Pair(15, 29), Pair(-13, 26), Pair(-12, 20), Pair(0, 6),
      Pair(-14, 17), Pair(0, 23), Pair(-2, 25), Pair(-1, 30), Pair(-1, 32), Pair(-1, 25), Pair(0, 13), Pair(5, 10),
      Pair(0, 23), Pair(0, 11), Pair(8, 12), Pair(-9, 22), Pair(2, 22), Pair(9, 17), Pair(20, 16), Pair(7, 5),
      Pair(-14, 13), Pair(10, 26), Pair(-13, 17), Pair(-18, 22), Pair(-10, 20), Pair(-14, 28), Pair(0, 11), Pair(10, -9)
  },
  {
      Pair(13, 7), Pair(6, 19), Pair(8, 18), Pair(5, 14), Pair(16, 4), Pair(29, 12), Pair(22, 12), Pair(3, 10),
      Pair(4, 9), Pair(7, 26), Pair(23, 21), Pair(37, 10), Pair(23, 8), Pair(47, 9), Pair(36, 6), Pair(21, 0),
      Pair(-10, 8), Pair(18, 12), Pair(18, 7), Pair(16, 3), Pair(45, -11), Pair(52, -7), Pair(77, -11), Pair(26, -15),
      Pair(-14, 8), Pair(-2, 11), Pair(1, 11), Pair(6, 6), Pair(9, -9), Pair(12, -3), Pair(16, -3), Pair(0, -10),
      Pair(-20, -2), Pair(-21, 9), Pair(-10, 2), Pair(-7, 1), Pair(-4, -5), Pair(-17, 4), Pair(5, -9), Pair(-10, -17),
      Pair(-24, -8), Pair(-19, -3), Pair(-12, -8), Pair(-11, -4), Pair(-3, -16), Pair(-3, -13), Pair(25, -33), Pair(2, -36),
      Pair(-21, -15), Pair(-14, -6), Pair(1, -9), Pair(2, -10), Pair(8, -20), Pair(11, -17), Pair(19, -28), Pair(-16, -29),
      Pair(-6, -11), Pair(0, -9), Pair(6, -7), Pair(11, -13), Pair(16, -21), Pair(12, -13), Pair(6, -19), Pair(-1, -31)
  },
  {
      Pair(-48, 0), Pair(-54, 17), Pair(-35, 38), Pair(3, 19), Pair(2, 20), Pair(11, 19), Pair(54, -40), Pair(-15, 6),
      Pair(-10, -19), Pair(-32, 15), Pair(-29, 46), Pair(-42, 69), Pair(-35, 85), Pair(6, 43), Pair(5, 23), Pair(41, 13),
      Pair(-9, -10), Pair(-12, 3), Pair(-14, 36), Pair(-4, 42), Pair(-1, 58), Pair(48, 36), Pair(51, 10), Pair(46, 9),
      Pair(-19, -4), Pair(-17, 10), Pair(-12, 19), Pair(-13, 40), Pair(-13, 55), Pair(0, 44), Pair(6, 41), Pair(7, 30),
      Pair(-17, -8), Pair(-18, 12), Pair(-14, 11), Pair(-8, 29), Pair(-6, 28), Pair(-7, 26), Pair(1, 18), Pair(7, 15),
      Pair(-9, -31), Pair(-5, -14), Pair(-6, -2), Pair(-10, 1), Pair(-2, 2), Pair(2, 3), Pair(16, -14), Pair(11, -20),
      Pair(-8, -34), Pair(-5, -32), Pair(0, -29), Pair(6, -26), Pair(4, -21), Pair(13, -41), Pair(17, -60), Pair(21, -78),
      Pair(-14, -34), Pair(-8, -35), Pair(-3, -30), Pair(-1, -22), Pair(3, -37), Pair(-7, -34), Pair(2, -54), Pair(1, -60)
  },
  {
      Pair(75, -93), Pair(107, -48), Pair(86, -29), Pair(-53, 15), Pair(-29, -2), Pair(4, -6), Pair(72, -23), Pair(180, -129),
      Pair(-58, 4), Pair(23, 26), Pair(-34, 42), Pair(53, 28), Pair(-11, 40), Pair(-4, 50), Pair(23, 33), Pair(-25, 7),
      Pair(-87, 12), Pair(61, 23), Pair(-23, 49), Pair(-46, 62), Pair(-24, 61), Pair(51, 40), Pair(-6, 39), Pair(-50, 10),
      Pair(-59, -1), Pair(-17, 20), Pair(-70, 49), Pair(-113, 65), Pair(-120, 60), Pair(-83, 47), Pair(-81, 27), Pair(-130, 12),
      Pair(-56, -15), Pair(-24, 9), Pair(-91, 43), Pair(-123, 61), Pair(-133, 57), Pair(-85, 33), Pair(-81, 15), Pair(-127, 0),
      Pair(-23, -22), Pair(9, -2), Pair(-61, 29), Pair(-81, 44), Pair(-82, 40), Pair(-73, 25), Pair(-33, 0), Pair(-44, -18),
      Pair(40, -38), Pair(-6, -4), Pair(-17, 10), Pair(-39, 21), Pair(-49, 22), Pair(-32, 9), Pair(-7, -12), Pair(25, -40),
      Pair(34, -72), Pair(40, -42), Pair(33, -28), Pair(-34, -4), Pair(16, -31), Pair(-25, -13), Pair(25, -39), Pair(47, -82)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-25, 1), Pair(-12, 5), Pair(-2, 26), Pair(3, 34), Pair(9, 42), Pair(15, 50), Pair(22, 50), Pair(28, 47),
  Pair(33, 37)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-56, -17), Pair(-45, -16), Pair(-35, 1), Pair(-27, 14), Pair(-19, 24), Pair(-14, 35), Pair(-10, 39), Pair(-7, 42),
  Pair(-5, 45), Pair(0, 43), Pair(10, 39), Pair(16, 39), Pair(16, 48), Pair(26, 26)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-38, -57), Pair(-31, -30), Pair(-27, -27), Pair(-24, -22), Pair(-26, -14), Pair(-21, -10), Pair(-19, -4), Pair(-16, -2),
  Pair(-12, 0), Pair(-10, 4), Pair(-6, 5), Pair(-6, 9), Pair(-1, 9), Pair(3, 6), Pair(-5, 6)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-2, -260), Pair(0, -246), Pair(-11, -107), Pair(-9, -61), Pair(-8, -38), Pair(-4, -26), Pair(-2, -8), Pair(-1, 6),
  Pair(2, 13), Pair(5, 16), Pair(6, 24), Pair(9, 30), Pair(11, 32), Pair(10, 40), Pair(12, 43), Pair(15, 48),
  Pair(15, 56), Pair(16, 57), Pair(24, 57), Pair(37, 49), Pair(39, 52), Pair(89, 23), Pair(75, 35), Pair(98, 14),
  Pair(210, -29), Pair(227, -59), Pair(164, -6), Pair(119, -4)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-6, 1), Pair(-13, 9), Pair(-9, 35), Pair(10, 61), Pair(8, 122), Pair(27, 33), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -8), Pair(-1, -1), Pair(17, 9), Pair(42, 47), Pair(112, 181), Pair(-122, 444), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-13, -43), Pair(5, -34), Pair(-4, -28), Pair(-3, -18), Pair(-12, -10), Pair(-13, -25), Pair(1, -40), Pair(-11, -54)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-9, 2), Pair(-7, -15), Pair(-17, -11), Pair(-15, -19), Pair(-19, -20), Pair(-9, -10), Pair(-7, -16), Pair(-6, 4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(26, 11), Pair(24, 3), Pair(21, 12), Pair(26, 11), Pair(28, 16), Pair(49, -1), Pair(57, 0), Pair(90, -1)
  },
  {
      Pair(3, 46), Pair(7, 18), Pair(5, 18), Pair(15, 8), Pair(11, 10), Pair(19, 2), Pair(28, 5), Pair(19, 29)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(18, -1), Pair(18, 8), Pair(15, 3),
  Pair(28, -6), Pair(25, 2), Pair(27, -7),
  Pair(38, 1), Pair(0, 0), Pair(34, 1),
  Pair(-20, 5), Pair(-12, 13), Pair(-20, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-12, 8), Pair(-17, 12), Pair(-13, 10),
  Pair(-11, 8), Pair(-18, 15), Pair(-13, 11),
  Pair(-6, 1), Pair(-15, 11), Pair(-5, 3),
  Pair(7, -1), Pair(-12, 8), Pair(6, 2),
  Pair(20, -5), Pair(14, 8), Pair(15, -5),
  Pair(0, 0), Pair(-70, -24), Pair(0, 0),
  Pair(-11, -48), Pair(0, 0), Pair(-15, -45)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-83, -13), Pair(-114, 4), Pair(-62, -4), Pair(-59, -2), Pair(-41, 2), Pair(-76, 11), Pair(-72, 13), Pair(-47, 8)
  },
  {
      Pair(-31, 68), Pair(-62, 38), Pair(-28, 27), Pair(-11, 10), Pair(-9, 5), Pair(-24, 19), Pair(-42, 36), Pair(-29, 50)
  }
}};

constexpr PieceTable<ScorePair> kDefendedByPawnBonus = {
  Pair(0, 0), Pair(0, 14), Pair(4, 13), Pair(6, 7), Pair(-8, 19), Pair(0, 0)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 66);
constexpr ScorePair kTempoBonus = Pair(20, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H