#ifndef INTEGRAL_TERMS_H
#define INTEGRAL_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceTable = std::array<T, kNumPieceTypes>;

template <typename T>
using PieceSquareTable = PieceTable<std::array<T, kSquareCount>>;

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

template <typename T>
using OutpostTable = std::array<T, 24>;

constexpr PieceTable<ScorePair> kPieceValues = {
  Pair(87, 182), Pair(292, 303), Pair(346, 350), Pair(411, 703), Pair(862, 1261), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(50, 135), Pair(33, 138), Pair(22, 140), Pair(65, 94), Pair(54, 98), Pair(51, 110), Pair(-18, 154), Pair(-16, 149),
      Pair(-1, -26), Pair(-16, -5), Pair(14, -48), Pair(20, -81), Pair(32, -83), Pair(62, -68), Pair(18, -21), Pair(-3, -32),
      Pair(-24, -42), Pair(-25, -34), Pair(-13, -60), Pair(-10, -79), Pair(10, -80), Pair(6, -74), Pair(-12, -42), Pair(-16, -61),
      Pair(-30, -60), Pair(-34, -41), Pair(-20, -68), Pair(-4, -77), Pair(-4, -77), Pair(-1, -76), Pair(-19, -52), Pair(-17, -75),
      Pair(-31, -64), Pair(-28, -47), Pair(-18, -69), Pair(-13, -70), Pair(-2, -70), Pair(-8, -72), Pair(-5, -57), Pair(-13, -78),
      Pair(-32, -58), Pair(-30, -40), Pair(-23, -60), Pair(-25, -67), Pair(-15, -56), Pair(0, -65), Pair(-1, -53), Pair(-26, -76),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-125, -33), Pair(-93, 9), Pair(-49, 27), Pair(-16, 10), Pair(-1, 16), Pair(-46, -7), Pair(-83, 9), Pair(-90, -52),
      Pair(-14, 19), Pair(0, 34), Pair(9, 32), Pair(17, 30), Pair(11, 20), Pair(47, 13), Pair(9, 24), Pair(11, -1),
      Pair(7, 22), Pair(17, 33), Pair(26, 49), Pair(23, 45), Pair(31, 39), Pair(66, 17), Pair(14, 26), Pair(29, 5),
      Pair(18, 33), Pair(20, 37), Pair(34, 48), Pair(57, 47), Pair(31, 47), Pair(50, 47), Pair(16, 36), Pair(43, 18),
      Pair(8, 35), Pair(22, 35), Pair(31, 53), Pair(37, 51), Pair(39, 56), Pair(46, 38), Pair(40, 33), Pair(22, 29),
      Pair(-13, 23), Pair(7, 31), Pair(15, 39), Pair(26, 53), Pair(40, 49), Pair(23, 32), Pair(27, 25), Pair(10, 27),
      Pair(-17, 23), Pair(-5, 32), Pair(6, 34), Pair(21, 34), Pair(23, 33), Pair(21, 31), Pair(16, 22), Pair(13, 33),
      Pair(-48, 25), Pair(-13, 19), Pair(-13, 30), Pair(1, 35), Pair(8, 34), Pair(13, 23), Pair(-9, 26), Pair(-12, 18)
  },
  {
      Pair(-47, 32), Pair(-68, 32), Pair(-69, 26), Pair(-103, 33), Pair(-104, 32), Pair(-97, 22), Pair(-56, 23), Pair(-78, 20),
      Pair(-34, 15), Pair(-30, 27), Pair(-28, 24), Pair(-39, 28), Pair(-40, 23), Pair(-28, 21), Pair(-55, 32), Pair(-45, 17),
      Pair(-21, 31), Pair(-11, 25), Pair(-19, 32), Pair(-16, 24), Pair(-23, 29), Pair(13, 32), Pair(2, 28), Pair(-7, 31),
      Pair(-33, 29), Pair(-21, 33), Pair(-16, 32), Pair(-3, 37), Pair(-5, 32), Pair(-7, 35), Pair(-25, 29), Pair(-31, 28),
      Pair(-26, 24), Pair(-34, 34), Pair(-19, 33), Pair(-1, 31), Pair(0, 27), Pair(-20, 32), Pair(-23, 32), Pair(-11, 13),
      Pair(-29, 24), Pair(-11, 32), Pair(-10, 33), Pair(-11, 38), Pair(-9, 42), Pair(-7, 33), Pair(-7, 26), Pair(-8, 16),
      Pair(-15, 26), Pair(-11, 14), Pair(-2, 17), Pair(-18, 30), Pair(-7, 29), Pair(2, 21), Pair(10, 20), Pair(-3, 8),
      Pair(-26, 14), Pair(-5, 32), Pair(-26, 24), Pair(-28, 29), Pair(-20, 25), Pair(-26, 34), Pair(-12, 17), Pair(3, -7)
  },
  {
      Pair(-13, 3), Pair(-14, 13), Pair(-10, 16), Pair(-16, 14), Pair(-9, 4), Pair(14, 5), Pair(4, 7), Pair(-12, 3),
      Pair(-11, -3), Pair(-11, 10), Pair(3, 8), Pair(18, -2), Pair(3, -6), Pair(21, -3), Pair(21, -8), Pair(7, -10),
      Pair(-16, -2), Pair(11, -1), Pair(9, -1), Pair(7, -4), Pair(32, -17), Pair(47, -20), Pair(63, -23), Pair(15, -24),
      Pair(-17, -1), Pair(-4, 1), Pair(-1, 3), Pair(1, 0), Pair(8, -17), Pair(12, -15), Pair(12, -15), Pair(-5, -18),
      Pair(-22, -8), Pair(-21, 1), Pair(-11, -4), Pair(-6, -3), Pair(-2, -12), Pair(-19, -4), Pair(2, -17), Pair(-15, -23),
      Pair(-23, -15), Pair(-18, -10), Pair(-10, -13), Pair(-10, -8), Pair(0, -20), Pair(-2, -20), Pair(21, -37), Pair(0, -40),
      Pair(-22, -21), Pair(-14, -12), Pair(0, -14), Pair(0, -14), Pair(6, -25), Pair(8, -24), Pair(15, -34), Pair(-17, -36),
      Pair(-10, -17), Pair(-4, -15), Pair(3, -11), Pair(7, -16), Pair(13, -26), Pair(8, -20), Pair(2, -24), Pair(-6, -35)
  },
  {
      Pair(-39, -10), Pair(-44, 2), Pair(-28, 19), Pair(-7, 4), Pair(-16, 8), Pair(-12, 14), Pair(38, -43), Pair(-12, -13),
      Pair(-4, -17), Pair(-19, 13), Pair(-22, 44), Pair(-32, 60), Pair(-50, 79), Pair(-6, 31), Pair(-5, 23), Pair(41, -1),
      Pair(-2, -7), Pair(-5, 8), Pair(-5, 39), Pair(-4, 42), Pair(-10, 55), Pair(20, 30), Pair(25, 5), Pair(12, -3),
      Pair(-12, 4), Pair(-7, 21), Pair(-5, 28), Pair(-10, 48), Pair(-6, 46), Pair(2, 28), Pair(9, 24), Pair(6, 5),
      Pair(-7, -5), Pair(-12, 23), Pair(-7, 22), Pair(-2, 37), Pair(4, 33), Pair(-6, 24), Pair(10, 9), Pair(6, -1),
      Pair(-6, -21), Pair(-2, 0), Pair(-1, 10), Pair(-5, 15), Pair(0, 20), Pair(3, 13), Pair(16, -8), Pair(10, -21),
      Pair(-1, -33), Pair(1, -27), Pair(6, -21), Pair(12, -16), Pair(10, -10), Pair(20, -38), Pair(24, -56), Pair(28, -80),
      Pair(-10, -30), Pair(-3, -30), Pair(-1, -20), Pair(1, -11), Pair(7, -27), Pair(-3, -35), Pair(3, -51), Pair(5, -57)
  },
  {
      Pair(69, -96), Pair(90, -54), Pair(55, -33), Pair(-66, 5), Pair(-47, -9), Pair(-65, 3), Pair(12, -16), Pair(137, -123),
      Pair(-77, 0), Pair(-2, 23), Pair(-38, 30), Pair(56, 11), Pair(-15, 24), Pair(-33, 44), Pair(-14, 34), Pair(-67, 9),
      Pair(-84, 2), Pair(61, 11), Pair(-15, 28), Pair(-48, 41), Pair(-23, 40), Pair(46, 26), Pair(-18, 31), Pair(-50, -1),
      Pair(-50, -16), Pair(-1, 0), Pair(-54, 23), Pair(-106, 39), Pair(-109, 34), Pair(-74, 25), Pair(-53, 6), Pair(-136, 0),
      Pair(-47, -34), Pair(-6, -13), Pair(-63, 14), Pair(-101, 32), Pair(-102, 27), Pair(-59, 7), Pair(-52, -8), Pair(-123, -15),
      Pair(-18, -37), Pair(26, -22), Pair(-32, 3), Pair(-48, 17), Pair(-45, 13), Pair(-41, 0), Pair(-8, -21), Pair(-39, -32),
      Pair(40, -47), Pair(11, -18), Pair(3, -8), Pair(-19, 2), Pair(-25, 2), Pair(-13, -8), Pair(10, -26), Pair(26, -49),
      Pair(30, -76), Pair(44, -48), Pair(31, -33), Pair(-30, -12), Pair(14, -37), Pair(-19, -21), Pair(28, -46), Pair(40, -85)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-33, 17), Pair(-19, 17), Pair(-9, 37), Pair(-3, 45), Pair(3, 50), Pair(9, 57), Pair(17, 56), Pair(22, 53),
  Pair(25, 45)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-36, -19), Pair(-26, -22), Pair(-17, -6), Pair(-11, 5), Pair(-4, 14), Pair(-2, 23), Pair(0, 27), Pair(1, 31),
  Pair(2, 35), Pair(6, 34), Pair(14, 30), Pair(20, 31), Pair(16, 46), Pair(25, 27)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-23, -54), Pair(-16, -26), Pair(-13, -22), Pair(-10, -17), Pair(-13, -10), Pair(-9, -6), Pair(-9, 0), Pair(-8, 3),
  Pair(-7, 6), Pair(-5, 9), Pair(-1, 11), Pair(-2, 15), Pair(1, 17), Pair(3, 14), Pair(-3, 15)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(0, -230), Pair(1, -214), Pair(-9, -89), Pair(-7, -46), Pair(-7, -24), Pair(-4, -12), Pair(-1, 6), Pair(0, 18),
  Pair(2, 25), Pair(5, 27), Pair(6, 33), Pair(9, 37), Pair(11, 38), Pair(10, 43), Pair(12, 44), Pair(14, 45),
  Pair(13, 52), Pair(15, 50), Pair(23, 44), Pair(35, 35), Pair(38, 33), Pair(83, 3), Pair(69, 10), Pair(86, -12),
  Pair(184, -52), Pair(206, -90), Pair(150, -49), Pair(103, -42)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(0, 11), Pair(-9, 25), Pair(-2, 56), Pair(20, 87), Pair(21, 152), Pair(29, 50), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPassedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(17, -3), Pair(9, 6), Pair(15, 22), Pair(51, 34), Pair(78, 53), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-2, 2), Pair(17, 13), Pair(42, 55), Pair(111, 191), Pair(-200, 462), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-10, -49), Pair(5, -39), Pair(-6, -28), Pair(-7, -14), Pair(-16, -7), Pair(-16, -22), Pair(2, -35), Pair(-6, -51)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-11, 10), Pair(-6, -14), Pair(-17, -7), Pair(-14, -13), Pair(-18, -17), Pair(-10, -9), Pair(-5, -15), Pair(-9, 6)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 8), Pair(26, 3), Pair(21, 9), Pair(24, 8), Pair(26, 14), Pair(37, 4), Pair(46, 4), Pair(75, 2)
  },
  {
      Pair(4, 27), Pair(9, 4), Pair(8, 5), Pair(18, -6), Pair(13, -2), Pair(16, -5), Pair(26, -2), Pair(13, 17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(20, -2), Pair(12, -2),
  Pair(25, -10), Pair(21, -8), Pair(23, -11),
  Pair(35, -3), Pair(0, 0), Pair(31, -2),
  Pair(-9, 5), Pair(-17, 4), Pair(-9, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-14, 3), Pair(-9, 3),
  Pair(-5, 1), Pair(-15, 5), Pair(-9, 3),
  Pair(-1, -7), Pair(-13, 0), Pair(-2, -5),
  Pair(13, -9), Pair(-6, -5), Pair(11, -7),
  Pair(31, -9), Pair(22, -1), Pair(24, -9),
  Pair(0, 0), Pair(0, -31), Pair(0, 0),
  Pair(51, -49), Pair(0, 0), Pair(44, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-22, 17), Pair(-28, 1), Pair(-18, -20), Pair(-16, -30), Pair(-12, -32), Pair(4, -34), Pair(-5, -37)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-75, -38), Pair(-3, -35), Pair(-2, -11), Pair(4, -3), Pair(5, 2), Pair(4, 8), Pair(-11, 3)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-80, 201);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-83, -10), Pair(-90, -2), Pair(-53, -6), Pair(-48, -4), Pair(-36, 1), Pair(-62, 5), Pair(-61, 6), Pair(-50, 9)
  },
  {
      Pair(-24, 50), Pair(-41, 22), Pair(-21, 14), Pair(-3, -2), Pair(-6, -5), Pair(-13, 7), Pair(-31, 24), Pair(-30, 38)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, 1), Pair(35, -9), Pair(84, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -2), Pair(30, -6), Pair(57, -17), Pair(63, -46), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -22), Pair(32, -24), Pair(57, -20), Pair(90, -27), Pair(104, -41), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 8), Pair(15, 22), Pair(39, 29), Pair(86, 16), Pair(125, 19), Pair(210, -25), Pair(278, -72)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-15, 18), Pair(-59, -21), Pair(-63, -53), Pair(-82, -6), Pair(-76, 37), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(8, -15), Pair(12, 0), Pair(-32, -37), Pair(-68, -15), Pair(-54, 25), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(-3, -19), Pair(-18, -27), Pair(7, -27), Pair(-49, -24), Pair(-65, -53), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(-2, -24), Pair(-15, -27), Pair(-19, -30), Pair(1, -31), Pair(-77, -10), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(8, 23), Pair(10, 11), Pair(29, 18), Pair(37, 20), Pair(38, 27), Pair(20, 47), Pair(33, 16), Pair(-9, 33),
  Pair(0, 13), Pair(11, 15), Pair(10, 20), Pair(1, 32), Pair(4, 21), Pair(2, 20), Pair(12, 16), Pair(-4, 24),
  Pair(6, 9), Pair(-3, 3), Pair(-5, 15), Pair(-1, 16), Pair(-2, 21), Pair(-13, 18), Pair(-4, 6), Pair(-3, 8)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-16, 12), Pair(12, 1), Pair(19, 3), Pair(34, 1), Pair(56, -12), Pair(30, -2), Pair(19, -10), Pair(-22, -29),
  Pair(-20, -9), Pair(18, 6), Pair(6, 2), Pair(15, 11), Pair(7, 4), Pair(14, -1), Pair(11, 11), Pair(13, -22),
  Pair(-28, 27), Pair(4, 5), Pair(-1, 17), Pair(12, 12), Pair(15, 21), Pair(-2, 7), Pair(10, -2), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 61);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H