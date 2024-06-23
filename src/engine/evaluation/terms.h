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
  Pair(87, 177), Pair(294, 310), Pair(339, 348), Pair(412, 705), Pair(864, 1268), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(50, 141), Pair(34, 142), Pair(24, 145), Pair(64, 100), Pair(53, 104), Pair(49, 114), Pair(-16, 157), Pair(-14, 153),
      Pair(-5, -21), Pair(-17, -3), Pair(16, -46), Pair(22, -76), Pair(36, -79), Pair(61, -66), Pair(20, -19), Pair(-2, -28),
      Pair(-25, -37), Pair(-25, -31), Pair(-13, -56), Pair(-7, -75), Pair(13, -76), Pair(7, -70), Pair(-14, -39), Pair(-14, -56),
      Pair(-31, -54), Pair(-34, -38), Pair(-19, -64), Pair(-4, -71), Pair(-2, -74), Pair(-2, -72), Pair(-19, -49), Pair(-17, -69),
      Pair(-32, -58), Pair(-27, -44), Pair(-18, -64), Pair(-12, -65), Pair(-3, -64), Pair(-8, -68), Pair(-6, -55), Pair(-13, -73),
      Pair(-31, -52), Pair(-29, -38), Pair(-23, -56), Pair(-25, -60), Pair(-14, -51), Pair(-4, -60), Pair(-2, -51), Pair(-22, -70),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-129, -33), Pair(-101, 13), Pair(-57, 29), Pair(-27, 15), Pair(-6, 20), Pair(-62, -2), Pair(-92, 13), Pair(-93, -52),
      Pair(-4, 19), Pair(17, 29), Pair(42, 24), Pair(44, 23), Pair(21, 16), Pair(79, 6), Pair(12, 25), Pair(22, -1),
      Pair(14, 23), Pair(44, 26), Pair(46, 45), Pair(37, 44), Pair(70, 31), Pair(73, 17), Pair(42, 19), Pair(27, 9),
      Pair(17, 35), Pair(17, 40), Pair(33, 50), Pair(58, 44), Pair(25, 51), Pair(50, 49), Pair(6, 47), Pair(40, 23),
      Pair(5, 37), Pair(18, 37), Pair(27, 52), Pair(30, 49), Pair(36, 54), Pair(42, 38), Pair(37, 35), Pair(20, 31),
      Pair(-15, 25), Pair(5, 33), Pair(12, 38), Pair(23, 51), Pair(36, 49), Pair(21, 32), Pair(24, 27), Pair(7, 29),
      Pair(-20, 25), Pair(-7, 32), Pair(4, 33), Pair(17, 32), Pair(18, 31), Pair(11, 32), Pair(7, 24), Pair(7, 37),
      Pair(-49, 28), Pair(-12, 20), Pair(-13, 30), Pair(1, 34), Pair(9, 34), Pair(13, 23), Pair(-8, 27), Pair(-14, 21)
  },
  {
      Pair(-51, 31), Pair(-75, 33), Pair(-73, 27), Pair(-117, 36), Pair(-112, 36), Pair(-110, 25), Pair(-65, 25), Pair(-79, 20),
      Pair(-29, 12), Pair(-3, 20), Pair(-18, 22), Pair(-32, 27), Pair(-19, 17), Pair(-25, 21), Pair(-29, 27), Pair(-49, 17),
      Pair(-17, 29), Pair(-2, 25), Pair(0, 30), Pair(-1, 18), Pair(-15, 26), Pair(27, 31), Pair(5, 30), Pair(-2, 29),
      Pair(-26, 26), Pair(-13, 30), Pair(-5, 30), Pair(6, 40), Pair(2, 34), Pair(-2, 36), Pair(-18, 26), Pair(-31, 28),
      Pair(-20, 21), Pair(-28, 30), Pair(-17, 34), Pair(2, 33), Pair(0, 29), Pair(-18, 30), Pair(-22, 31), Pair(-7, 12),
      Pair(-24, 21), Pair(-6, 33), Pair(-9, 34), Pair(-10, 37), Pair(-11, 41), Pair(-5, 33), Pair(-5, 26), Pair(-4, 15),
      Pair(-11, 28), Pair(-9, 14), Pair(-1, 16), Pair(-20, 26), Pair(-8, 26), Pair(-5, 22), Pair(6, 22), Pair(-4, 12),
      Pair(-22, 16), Pair(-1, 31), Pair(-23, 21), Pair(-25, 26), Pair(-17, 23), Pair(-22, 32), Pair(-10, 17), Pair(5, -6)
  },
  {
      Pair(-3, 2), Pair(-9, 13), Pair(-9, 15), Pair(-14, 11), Pair(-6, 2), Pair(12, 9), Pair(8, 9), Pair(-9, 5),
      Pair(-5, 5), Pair(-6, 22), Pair(12, 18), Pair(24, 9), Pair(7, 7), Pair(34, 5), Pair(21, 2), Pair(11, -4),
      Pair(-15, 3), Pair(13, 6), Pair(11, 3), Pair(7, 1), Pair(32, -13), Pair(46, -11), Pair(67, -16), Pair(14, -19),
      Pair(-17, 2), Pair(-2, 5), Pair(1, 5), Pair(4, 1), Pair(8, -14), Pair(10, -8), Pair(10, -7), Pair(-7, -14),
      Pair(-23, -9), Pair(-23, 1), Pair(-11, -6), Pair(-7, -7), Pair(-5, -13), Pair(-21, -3), Pair(0, -15), Pair(-18, -21),
      Pair(-25, -17), Pair(-18, -12), Pair(-13, -17), Pair(-13, -14), Pair(-4, -24), Pair(-5, -21), Pair(17, -37), Pair(-4, -41),
      Pair(-24, -24), Pair(-17, -15), Pair(-4, -18), Pair(-5, -19), Pair(1, -29), Pair(-4, -24), Pair(5, -34), Pair(-22, -39),
      Pair(-11, -19), Pair(-5, -19), Pair(1, -15), Pair(5, -21), Pair(12, -30), Pair(7, -23), Pair(-1, -26), Pair(-9, -36)
  },
  {
      Pair(-49, -3), Pair(-54, 8), Pair(-41, 27), Pair(-18, 12), Pair(-28, 18), Pair(-19, 19), Pair(26, -34), Pair(-27, -5),
      Pair(-4, -17), Pair(-21, 14), Pair(-25, 46), Pair(-36, 63), Pair(-55, 84), Pair(-7, 33), Pair(-3, 21), Pair(41, -1),
      Pair(-2, -5), Pair(-7, 10), Pair(-7, 40), Pair(-6, 43), Pair(-6, 52), Pair(20, 31), Pair(26, 5), Pair(13, -1),
      Pair(-11, 4), Pair(-6, 20), Pair(-7, 28), Pair(-11, 48), Pair(-8, 47), Pair(2, 29), Pair(8, 25), Pair(6, 6),
      Pair(-6, -4), Pair(-12, 24), Pair(-6, 20), Pair(-3, 36), Pair(1, 34), Pair(-6, 22), Pair(10, 10), Pair(7, -1),
      Pair(-4, -21), Pair(0, -1), Pair(-1, 10), Pair(-4, 13), Pair(-2, 19), Pair(5, 9), Pair(17, -10), Pair(12, -22),
      Pair(2, -32), Pair(3, -29), Pair(7, -22), Pair(11, -16), Pair(10, -11), Pair(14, -39), Pair(20, -59), Pair(28, -79),
      Pair(-6, -31), Pair(0, -29), Pair(3, -22), Pair(6, -12), Pair(11, -28), Pair(1, -36), Pair(6, -50), Pair(7, -54)
  },
  {
      Pair(72, -90), Pair(85, -43), Pair(58, -25), Pair(-71, 17), Pair(-39, -2), Pair(-45, 5), Pair(31, -14), Pair(144, -118),
      Pair(-51, -2), Pair(25, 25), Pair(-23, 36), Pair(58, 22), Pair(-1, 32), Pair(-3, 48), Pair(29, 32), Pair(-46, 6),
      Pair(-51, -1), Pair(93, 12), Pair(-3, 40), Pair(-46, 56), Pair(-16, 54), Pair(70, 34), Pair(24, 30), Pair(-20, -4),
      Pair(-20, -21), Pair(29, 3), Pair(-38, 34), Pair(-110, 58), Pair(-106, 52), Pair(-52, 36), Pair(-28, 10), Pair(-104, -3),
      Pair(-28, -34), Pair(18, -10), Pair(-40, 23), Pair(-88, 45), Pair(-82, 39), Pair(-34, 16), Pair(-28, -5), Pair(-107, -14),
      Pair(-14, -34), Pair(41, -17), Pair(-12, 7), Pair(-28, 22), Pair(-23, 18), Pair(-19, 5), Pair(10, -18), Pair(-38, -26),
      Pair(31, -41), Pair(13, -14), Pair(9, -4), Pair(-15, 7), Pair(-17, 7), Pair(-8, -4), Pair(11, -21), Pair(15, -40),
      Pair(9, -67), Pair(31, -42), Pair(17, -26), Pair(-41, -8), Pair(3, -30), Pair(-30, -15), Pair(14, -39), Pair(16, -74)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-33, -5), Pair(-19, 5), Pair(-8, 26), Pair(-3, 35), Pair(3, 42), Pair(9, 50), Pair(16, 49), Pair(22, 46),
  Pair(28, 38)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-31, -27), Pair(-22, -21), Pair(-11, -4), Pair(-5, 9), Pair(2, 18), Pair(6, 28), Pair(9, 32), Pair(9, 34),
  Pair(10, 38), Pair(13, 36), Pair(22, 31), Pair(25, 32), Pair(22, 45), Pair(30, 23)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-22, -56), Pair(-14, -26), Pair(-11, -22), Pair(-8, -16), Pair(-10, -9), Pair(-6, -4), Pair(-5, 3), Pair(-3, 5),
  Pair(-1, 8), Pair(1, 12), Pair(4, 13), Pair(2, 18), Pair(4, 20), Pair(5, 16), Pair(-2, 15)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-5, -249), Pair(0, -245), Pair(-11, -101), Pair(-9, -54), Pair(-8, -28), Pair(-5, -16), Pair(-3, 2), Pair(-2, 16),
  Pair(1, 22), Pair(3, 25), Pair(4, 31), Pair(6, 37), Pair(8, 38), Pair(7, 43), Pair(9, 44), Pair(11, 47),
  Pair(10, 54), Pair(11, 52), Pair(20, 47), Pair(32, 37), Pair(34, 37), Pair(80, 7), Pair(65, 14), Pair(80, -6),
  Pair(180, -47), Pair(203, -83), Pair(128, -31), Pair(84, -26)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-5, 1), Pair(-8, 16), Pair(-5, 51), Pair(19, 87), Pair(16, 155), Pair(19, 46), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -5), Pair(-3, 1), Pair(17, 10), Pair(43, 47), Pair(119, 174), Pair(-157, 438), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-11, -46), Pair(5, -36), Pair(-5, -26), Pair(-8, -14), Pair(-19, -5), Pair(-15, -21), Pair(3, -33), Pair(-6, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-12, 7), Pair(-7, -16), Pair(-17, -11), Pair(-14, -20), Pair(-19, -21), Pair(-9, -12), Pair(-6, -16), Pair(-11, 3)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(29, 9), Pair(27, 3), Pair(24, 11), Pair(27, 9), Pair(29, 14), Pair(39, 1), Pair(50, 1), Pair(77, 1)
  },
  {
      Pair(3, 47), Pair(8, 18), Pair(7, 18), Pair(17, 7), Pair(11, 10), Pair(14, 4), Pair(24, 7), Pair(13, 32)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -6), Pair(17, -2), Pair(12, -1),
  Pair(17, -10), Pair(14, -5), Pair(16, -10),
  Pair(27, -3), Pair(0, 0), Pair(24, -2),
  Pair(-11, 2), Pair(-4, 1), Pair(-10, 4)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-13, 2), Pair(-8, 4),
  Pair(-6, 1), Pair(-15, 5), Pair(-8, 3),
  Pair(0, -7), Pair(-11, -1), Pair(-1, -5),
  Pair(12, -8), Pair(-3, -5), Pair(10, -5),
  Pair(32, -8), Pair(21, 0), Pair(25, -8),
  Pair(0, 0), Pair(5, -31), Pair(0, 0),
  Pair(44, -46), Pair(0, 0), Pair(38, -43)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-18, 13), Pair(-25, 0), Pair(-16, -20), Pair(-13, -31), Pair(-9, -34), Pair(6, -36), Pair(-4, -39)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-64, -28), Pair(5, -28), Pair(4, -3), Pair(10, 7), Pair(9, 14), Pair(9, 20), Pair(-9, 19)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-71, -7), Pair(-83, 1), Pair(-46, -4), Pair(-37, -2), Pair(-30, 3), Pair(-51, 7), Pair(-53, 8), Pair(-31, 6)
  },
  {
      Pair(-14, 51), Pair(-32, 22), Pair(-15, 15), Pair(4, -3), Pair(0, -6), Pair(-6, 6), Pair(-22, 24), Pair(-15, 35)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(35, -20), Pair(30, 0), Pair(20, -4), Pair(18, -5), Pair(17, -8), Pair(13, -2), Pair(2, 3), Pair(-7, 5)
  },
  {
      Pair(-16, 10), Pair(-25, 12), Pair(-31, 14), Pair(-35, 14), Pair(-48, 16), Pair(-55, 16), Pair(-65, 18), Pair(-62, 15)
  },
  {
      Pair(-69, 12), Pair(-62, 9), Pair(-58, 5), Pair(-56, 1), Pair(-57, 3), Pair(-51, -5), Pair(-39, -8), Pair(-17, -19)
  },
  {
      Pair(1, -21), Pair(42, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(14, 4), Pair(34, -6), Pair(76, -22)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(13, 4), Pair(31, -5), Pair(53, -14)
  }
}};

constexpr QueenMobilityTable<ScorePair> kKingVirtualMobilityTable = {
  Pair(50, -42), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(16, -15), Pair(35, -18), Pair(55, -17),
  Pair(83, -22), Pair(95, -37), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(5, 8), Pair(16, 21), Pair(39, 28),
  Pair(82, 17), Pair(119, 20), Pair(198, -20), Pair(253, -60), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
  Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(0, 0), Pair(-54, -21), Pair(-62, -43), Pair(-81, -5), Pair(-71, 37), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(0, 25), Pair(-5, 16), Pair(12, 24), Pair(30, 26), Pair(16, 36), Pair(19, 48), Pair(19, 22), Pair(-10, 40),
  Pair(-1, 19), Pair(11, 18), Pair(10, 23), Pair(0, 38), Pair(5, 27), Pair(4, 23), Pair(15, 15), Pair(-2, 28),
  Pair(7, 14), Pair(-3, 7), Pair(-4, 20), Pair(4, 21), Pair(-1, 26), Pair(-11, 21), Pair(-4, 9), Pair(-2, 9)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-19, 14), Pair(10, -2), Pair(10, 0), Pair(24, 2), Pair(55, -14), Pair(26, -6), Pair(20, -16), Pair(-23, -26),
  Pair(-22, -6), Pair(18, 5), Pair(4, 1), Pair(17, 7), Pair(8, 2), Pair(17, -5), Pair(11, 11), Pair(19, -25),
  Pair(-28, 29), Pair(7, 4), Pair(2, 17), Pair(16, 13), Pair(21, 21), Pair(0, 7), Pair(14, -3), Pair(-52, 11)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 64);

constexpr ScorePair kTempoBonus = Pair(24, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H