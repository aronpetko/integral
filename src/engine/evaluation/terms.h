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
  Pair(86, 178), Pair(297, 310), Pair(340, 348), Pair(413, 707), Pair(864, 1268), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(51, 140), Pair(35, 143), Pair(25, 145), Pair(65, 100), Pair(54, 103), Pair(50, 114), Pair(-15, 156), Pair(-13, 153),
      Pair(-4, -22), Pair(-17, -3), Pair(17, -47), Pair(23, -77), Pair(37, -80), Pair(63, -66), Pair(21, -20), Pair(-1, -28),
      Pair(-24, -39), Pair(-24, -32), Pair(-12, -58), Pair(-6, -76), Pair(14, -78), Pair(8, -71), Pair(-13, -41), Pair(-13, -57),
      Pair(-30, -56), Pair(-33, -39), Pair(-18, -65), Pair(-3, -73), Pair(-1, -75), Pair(-1, -73), Pair(-18, -51), Pair(-16, -70),
      Pair(-30, -59), Pair(-27, -44), Pair(-17, -65), Pair(-11, -66), Pair(-2, -65), Pair(-7, -69), Pair(-5, -56), Pair(-12, -74),
      Pair(-30, -54), Pair(-29, -39), Pair(-22, -57), Pair(-24, -61), Pair(-13, -52), Pair(-3, -61), Pair(-2, -52), Pair(-22, -70),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-129, -33), Pair(-101, 14), Pair(-57, 30), Pair(-27, 16), Pair(-6, 20), Pair(-62, -1), Pair(-92, 14), Pair(-93, -51),
      Pair(-3, 20), Pair(17, 30), Pair(42, 25), Pair(45, 24), Pair(21, 17), Pair(79, 7), Pair(12, 26), Pair(22, -1),
      Pair(15, 23), Pair(44, 27), Pair(46, 46), Pair(37, 46), Pair(70, 32), Pair(73, 18), Pair(42, 20), Pair(28, 10),
      Pair(17, 36), Pair(17, 41), Pair(33, 51), Pair(59, 45), Pair(26, 52), Pair(51, 50), Pair(7, 48), Pair(41, 24),
      Pair(6, 38), Pair(18, 38), Pair(28, 53), Pair(31, 50), Pair(36, 55), Pair(43, 39), Pair(38, 36), Pair(20, 32),
      Pair(-15, 26), Pair(6, 34), Pair(12, 39), Pair(23, 52), Pair(36, 50), Pair(21, 33), Pair(24, 27), Pair(8, 30),
      Pair(-20, 26), Pair(-7, 33), Pair(4, 34), Pair(18, 33), Pair(19, 32), Pair(11, 32), Pair(7, 24), Pair(7, 37),
      Pair(-49, 29), Pair(-12, 21), Pair(-13, 30), Pair(1, 35), Pair(9, 34), Pair(13, 23), Pair(-7, 28), Pair(-13, 22)
  },
  {
      Pair(-52, 31), Pair(-76, 34), Pair(-74, 28), Pair(-118, 36), Pair(-113, 36), Pair(-111, 25), Pair(-66, 26), Pair(-80, 20),
      Pair(-29, 12), Pair(-4, 21), Pair(-19, 23), Pair(-32, 27), Pair(-20, 17), Pair(-25, 21), Pair(-29, 28), Pair(-50, 18),
      Pair(-18, 29), Pair(-3, 25), Pair(-1, 30), Pair(-1, 18), Pair(-16, 26), Pair(26, 31), Pair(5, 30), Pair(-3, 29),
      Pair(-27, 26), Pair(-13, 30), Pair(-6, 29), Pair(5, 40), Pair(1, 34), Pair(-3, 36), Pair(-19, 26), Pair(-31, 28),
      Pair(-21, 21), Pair(-29, 31), Pair(-17, 34), Pair(1, 34), Pair(0, 29), Pair(-19, 31), Pair(-22, 31), Pair(-8, 12),
      Pair(-25, 21), Pair(-7, 33), Pair(-9, 34), Pair(-10, 37), Pair(-11, 41), Pair(-6, 33), Pair(-6, 25), Pair(-4, 15),
      Pair(-12, 28), Pair(-10, 14), Pair(-2, 16), Pair(-21, 27), Pair(-9, 26), Pair(-6, 22), Pair(5, 23), Pair(-5, 12),
      Pair(-23, 16), Pair(-2, 31), Pair(-24, 21), Pair(-26, 26), Pair(-17, 23), Pair(-23, 32), Pair(-11, 17), Pair(5, -6)
  },
  {
      Pair(-4, 2), Pair(-10, 13), Pair(-9, 14), Pair(-14, 11), Pair(-7, 1), Pair(12, 8), Pair(7, 9), Pair(-9, 5),
      Pair(-5, 5), Pair(-6, 21), Pair(12, 18), Pair(23, 9), Pair(7, 6), Pair(34, 5), Pair(21, 2), Pair(10, -4),
      Pair(-16, 3), Pair(13, 6), Pair(11, 3), Pair(6, 0), Pair(32, -13), Pair(45, -12), Pair(66, -16), Pair(14, -19),
      Pair(-17, 2), Pair(-2, 4), Pair(1, 5), Pair(3, 1), Pair(8, -15), Pair(9, -8), Pair(9, -7), Pair(-7, -14),
      Pair(-23, -9), Pair(-23, 1), Pair(-11, -7), Pair(-7, -7), Pair(-6, -14), Pair(-22, -3), Pair(-1, -15), Pair(-18, -21),
      Pair(-25, -17), Pair(-19, -13), Pair(-13, -17), Pair(-14, -14), Pair(-4, -25), Pair(-6, -22), Pair(17, -38), Pair(-4, -41),
      Pair(-25, -25), Pair(-18, -16), Pair(-4, -19), Pair(-6, -19), Pair(1, -30), Pair(-5, -25), Pair(4, -34), Pair(-22, -39),
      Pair(-11, -20), Pair(-5, -19), Pair(0, -16), Pair(5, -22), Pair(12, -30), Pair(7, -23), Pair(-1, -26), Pair(-9, -36)
  },
  {
      Pair(-50, -3), Pair(-55, 8), Pair(-41, 27), Pair(-18, 12), Pair(-28, 18), Pair(-19, 19), Pair(26, -35), Pair(-27, -5),
      Pair(-4, -17), Pair(-22, 14), Pair(-25, 46), Pair(-36, 63), Pair(-56, 84), Pair(-7, 33), Pair(-4, 21), Pair(41, -1),
      Pair(-2, -5), Pair(-8, 10), Pair(-7, 40), Pair(-7, 43), Pair(-7, 52), Pair(20, 31), Pair(26, 5), Pair(14, -1),
      Pair(-12, 4), Pair(-6, 20), Pair(-7, 28), Pair(-11, 48), Pair(-8, 47), Pair(2, 29), Pair(8, 25), Pair(6, 6),
      Pair(-6, -5), Pair(-13, 24), Pair(-6, 20), Pair(-4, 36), Pair(1, 34), Pair(-6, 22), Pair(10, 10), Pair(7, -1),
      Pair(-4, -21), Pair(0, -1), Pair(-1, 10), Pair(-5, 14), Pair(-2, 19), Pair(5, 9), Pair(17, -10), Pair(12, -22),
      Pair(1, -32), Pair(3, -29), Pair(7, -22), Pair(10, -16), Pair(10, -11), Pair(14, -38), Pair(20, -59), Pair(27, -79),
      Pair(-6, -31), Pair(0, -29), Pair(3, -22), Pair(5, -12), Pair(11, -28), Pair(1, -36), Pair(6, -50), Pair(7, -54)
  },
  {
      Pair(72, -90), Pair(83, -43), Pair(55, -25), Pair(-72, 16), Pair(-41, -2), Pair(-47, 4), Pair(29, -14), Pair(145, -118),
      Pair(-53, -3), Pair(22, 25), Pair(-25, 36), Pair(55, 22), Pair(-3, 32), Pair(-6, 48), Pair(27, 32), Pair(-47, 6),
      Pair(-53, -2), Pair(90, 12), Pair(-6, 40), Pair(-48, 56), Pair(-19, 54), Pair(67, 34), Pair(21, 30), Pair(-22, -4),
      Pair(-21, -21), Pair(26, 3), Pair(-41, 34), Pair(-113, 58), Pair(-109, 52), Pair(-55, 36), Pair(-30, 10), Pair(-104, -3),
      Pair(-28, -35), Pair(16, -10), Pair(-42, 23), Pair(-90, 45), Pair(-85, 39), Pair(-36, 16), Pair(-29, -5), Pair(-108, -15),
      Pair(-14, -35), Pair(40, -17), Pair(-13, 7), Pair(-29, 22), Pair(-24, 18), Pair(-20, 4), Pair(9, -18), Pair(-38, -27),
      Pair(30, -42), Pair(12, -15), Pair(9, -4), Pair(-15, 7), Pair(-18, 6), Pair(-8, -4), Pair(10, -21), Pair(14, -41),
      Pair(9, -68), Pair(31, -42), Pair(17, -26), Pair(-41, -8), Pair(3, -31), Pair(-30, -16), Pair(14, -39), Pair(16, -75)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-36, -7), Pair(-22, 4), Pair(-11, 25), Pair(-6, 34), Pair(0, 41), Pair(6, 49), Pair(13, 48), Pair(19, 45),
  Pair(25, 36)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-32, -27), Pair(-22, -22), Pair(-12, -5), Pair(-5, 9), Pair(2, 18), Pair(5, 28), Pair(8, 31), Pair(9, 34),
  Pair(9, 38), Pair(13, 35), Pair(21, 31), Pair(25, 32), Pair(21, 45), Pair(29, 23)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-23, -57), Pair(-15, -27), Pair(-11, -22), Pair(-9, -17), Pair(-11, -9), Pair(-6, -5), Pair(-6, 1), Pair(-4, 4),
  Pair(-1, 7), Pair(1, 11), Pair(3, 13), Pair(1, 18), Pair(3, 20), Pair(4, 15), Pair(-3, 14)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-5, -249), Pair(0, -244), Pair(-11, -101), Pair(-9, -54), Pair(-8, -28), Pair(-5, -16), Pair(-2, 3), Pair(-2, 16),
  Pair(1, 23), Pair(3, 25), Pair(4, 32), Pair(6, 37), Pair(8, 38), Pair(7, 44), Pair(9, 44), Pair(11, 47),
  Pair(10, 54), Pair(11, 52), Pair(20, 47), Pair(32, 38), Pair(34, 37), Pair(80, 7), Pair(65, 14), Pair(80, -6),
  Pair(181, -47), Pair(203, -83), Pair(127, -30), Pair(83, -26)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-4, 1), Pair(-6, 15), Pair(-4, 51), Pair(20, 87), Pair(17, 155), Pair(20, 45), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -5), Pair(-3, 1), Pair(17, 10), Pair(43, 47), Pair(119, 174), Pair(-154, 437), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-11, -46), Pair(5, -36), Pair(-5, -26), Pair(-8, -13), Pair(-19, -5), Pair(-15, -21), Pair(3, -32), Pair(-5, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-13, 7), Pair(-7, -16), Pair(-17, -11), Pair(-15, -20), Pair(-19, -21), Pair(-9, -11), Pair(-5, -16), Pair(-11, 3)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 9), Pair(28, 3), Pair(24, 11), Pair(28, 9), Pair(29, 15), Pair(39, 2), Pair(51, 1), Pair(77, 2)
  },
  {
      Pair(3, 47), Pair(8, 19), Pair(7, 18), Pair(17, 8), Pair(12, 10), Pair(14, 5), Pair(24, 7), Pair(13, 33)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(17, -2), Pair(12, -2),
  Pair(17, -10), Pair(14, -5), Pair(15, -10),
  Pair(27, -2), Pair(0, 0), Pair(24, -2),
  Pair(-11, 2), Pair(-5, 1), Pair(-10, 4)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-13, 3), Pair(-8, 4),
  Pair(-6, 1), Pair(-14, 5), Pair(-8, 3),
  Pair(0, -7), Pair(-11, -1), Pair(-1, -5),
  Pair(12, -8), Pair(-3, -4), Pair(10, -6),
  Pair(32, -8), Pair(21, 1), Pair(25, -8),
  Pair(0, 0), Pair(5, -31), Pair(0, 0),
  Pair(44, -46), Pair(0, 0), Pair(38, -43)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-17, 12), Pair(-24, 0), Pair(-16, -21), Pair(-13, -32), Pair(-8, -34), Pair(7, -37), Pair(-3, -39)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-66, -28), Pair(3, -27), Pair(2, -2), Pair(8, 7), Pair(7, 15), Pair(7, 21), Pair(-11, 19)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-71, -7), Pair(-84, 1), Pair(-47, -4), Pair(-38, -2), Pair(-30, 3), Pair(-52, 7), Pair(-54, 7), Pair(-32, 6)
  },
  {
      Pair(-14, 52), Pair(-32, 22), Pair(-15, 15), Pair(4, -3), Pair(0, -6), Pair(-6, 7), Pair(-21, 24), Pair(-15, 36)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(35, -18), Pair(30, 1), Pair(20, -3), Pair(18, -3), Pair(17, -6), Pair(12, -1), Pair(2, 4), Pair(-7, 7)
  },
  {
      Pair(-16, 11), Pair(-25, 13), Pair(-31, 15), Pair(-35, 15), Pair(-48, 17), Pair(-54, 17), Pair(-64, 19), Pair(-60, 15)
  },
  {
      Pair(-66, 13), Pair(-60, 9), Pair(-56, 6), Pair(-52, 2), Pair(-53, 3), Pair(-46, -5), Pair(-35, -8), Pair(-11, -19)
  },
  {
      Pair(4, -21), Pair(37, -22), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(15, 4), Pair(34, -6), Pair(75, -22)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(13, 4), Pair(31, -5), Pair(53, -14)
  }
}};

constexpr QueenMobilityTable<ScorePair> kKingVirtualMobilityTable = {
  Pair(50, -42), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(17, -15), Pair(35, -18), Pair(55, -17),
  Pair(83, -23), Pair(96, -38), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(4, 8), Pair(16, 21), Pair(39, 28),
  Pair(82, 17), Pair(119, 20), Pair(198, -20), Pair(251, -58), Pair(251, -60), Pair(251, -65), Pair(251, -70), Pair(251, -80),
  Pair(251, -90), Pair(251, -100), Pair(251, -110), Pair(251, -120)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(0, 0), Pair(-54, -21), Pair(-62, -43), Pair(-81, -5), Pair(-71, 37), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(0, 25), Pair(-6, 16), Pair(12, 24), Pair(30, 26), Pair(16, 36), Pair(19, 48), Pair(19, 22), Pair(-10, 40),
  Pair(-1, 19), Pair(11, 18), Pair(10, 23), Pair(0, 38), Pair(5, 27), Pair(4, 23), Pair(15, 15), Pair(-2, 28),
  Pair(7, 14), Pair(-3, 7), Pair(-4, 20), Pair(4, 21), Pair(0, 26), Pair(-11, 21), Pair(-4, 8), Pair(-2, 9)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-19, 14), Pair(10, -2), Pair(10, 0), Pair(24, 2), Pair(55, -14), Pair(26, -6), Pair(20, -16), Pair(-23, -26),
  Pair(-22, -6), Pair(18, 4), Pair(4, 1), Pair(17, 8), Pair(8, 2), Pair(17, -5), Pair(11, 11), Pair(19, -25),
  Pair(-28, 28), Pair(7, 4), Pair(2, 17), Pair(16, 13), Pair(21, 21), Pair(0, 8), Pair(14, -3), Pair(-52, 11)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 64);

constexpr ScorePair kTempoBonus = Pair(23, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H