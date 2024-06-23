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
  Pair(86, 177), Pair(296, 315), Pair(338, 348), Pair(412, 707), Pair(863, 1269), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(53, 140), Pair(35, 143), Pair(25, 145), Pair(64, 100), Pair(52, 104), Pair(48, 114), Pair(-17, 158), Pair(-17, 155),
      Pair(-3, -20), Pair(-17, -1), Pair(17, -45), Pair(21, -75), Pair(34, -77), Pair(62, -64), Pair(17, -16), Pair(-4, -26),
      Pair(-24, -37), Pair(-25, -29), Pair(-12, -55), Pair(-8, -73), Pair(14, -75), Pair(7, -69), Pair(-13, -38), Pair(-15, -54),
      Pair(-30, -54), Pair(-34, -37), Pair(-18, -63), Pair(-2, -71), Pair(-1, -73), Pair(0, -71), Pair(-19, -48), Pair(-16, -69),
      Pair(-30, -57), Pair(-28, -42), Pair(-16, -63), Pair(-11, -63), Pair(1, -64), Pair(-6, -67), Pair(-5, -54), Pair(-12, -72),
      Pair(-30, -52), Pair(-29, -36), Pair(-21, -55), Pair(-23, -59), Pair(-11, -50), Pair(2, -61), Pair(1, -51), Pair(-24, -70),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-130, -35), Pair(-104, 13), Pair(-58, 29), Pair(-29, 15), Pair(-8, 19), Pair(-62, -3), Pair(-94, 12), Pair(-96, -53),
      Pair(-5, 19), Pair(15, 29), Pair(40, 23), Pair(42, 23), Pair(19, 16), Pair(79, 5), Pair(11, 25), Pair(22, -2),
      Pair(13, 21), Pair(43, 26), Pair(45, 44), Pair(35, 44), Pair(70, 30), Pair(73, 16), Pair(41, 19), Pair(26, 9),
      Pair(16, 34), Pair(15, 40), Pair(32, 49), Pair(57, 45), Pair(24, 51), Pair(49, 50), Pair(4, 47), Pair(39, 22),
      Pair(4, 36), Pair(17, 37), Pair(26, 52), Pair(31, 49), Pair(35, 54), Pair(41, 39), Pair(37, 35), Pair(19, 31),
      Pair(-16, 24), Pair(4, 32), Pair(11, 38), Pair(22, 52), Pair(38, 49), Pair(20, 32), Pair(25, 27), Pair(7, 28),
      Pair(-21, 24), Pair(-8, 31), Pair(3, 33), Pair(18, 32), Pair(20, 31), Pair(20, 29), Pair(13, 22), Pair(10, 33),
      Pair(-51, 27), Pair(-15, 19), Pair(-15, 29), Pair(-1, 33), Pair(7, 33), Pair(12, 22), Pair(-10, 25), Pair(-16, 20)
  },
  {
      Pair(-51, 32), Pair(-75, 34), Pair(-73, 28), Pair(-118, 37), Pair(-112, 37), Pair(-111, 25), Pair(-65, 26), Pair(-82, 21),
      Pair(-29, 13), Pair(-3, 21), Pair(-19, 24), Pair(-34, 28), Pair(-20, 19), Pair(-27, 23), Pair(-31, 29), Pair(-45, 17),
      Pair(-17, 30), Pair(-2, 26), Pair(-1, 32), Pair(-1, 20), Pair(-18, 29), Pair(25, 33), Pair(5, 32), Pair(-2, 29),
      Pair(-27, 27), Pair(-14, 32), Pair(-4, 31), Pair(3, 43), Pair(2, 37), Pair(-3, 38), Pair(-18, 28), Pair(-31, 29),
      Pair(-21, 22), Pair(-28, 32), Pair(-18, 36), Pair(3, 35), Pair(1, 32), Pair(-18, 33), Pair(-21, 32), Pair(-6, 11),
      Pair(-24, 22), Pair(-7, 34), Pair(-8, 35), Pair(-10, 39), Pair(-6, 43), Pair(-4, 35), Pair(-3, 27), Pair(-3, 16),
      Pair(-12, 28), Pair(-8, 14), Pair(-1, 17), Pair(-17, 27), Pair(-6, 27), Pair(5, 20), Pair(13, 20), Pair(-1, 10),
      Pair(-22, 16), Pair(-1, 31), Pair(-23, 21), Pair(-25, 26), Pair(-17, 23), Pair(-22, 32), Pair(-8, 16), Pair(6, -6)
  },
  {
      Pair(-2, 3), Pair(-8, 14), Pair(-8, 16), Pair(-12, 12), Pair(-5, 2), Pair(15, 9), Pair(9, 9), Pair(-4, 5),
      Pair(-5, 6), Pair(-5, 23), Pair(12, 19), Pair(24, 10), Pair(7, 7), Pair(34, 6), Pair(23, 3), Pair(12, -4),
      Pair(-14, 3), Pair(13, 8), Pair(11, 5), Pair(8, 2), Pair(35, -12), Pair(47, -10), Pair(67, -14), Pair(17, -18),
      Pair(-16, 3), Pair(-2, 6), Pair(2, 7), Pair(5, 3), Pair(9, -13), Pair(10, -6), Pair(11, -6), Pair(-6, -13),
      Pair(-23, -8), Pair(-23, 3), Pair(-10, -4), Pair(-6, -5), Pair(-4, -11), Pair(-21, 1), Pair(1, -13), Pair(-16, -20),
      Pair(-25, -16), Pair(-18, -10), Pair(-12, -15), Pair(-13, -12), Pair(-1, -22), Pair(-4, -19), Pair(21, -36), Pair(-1, -40),
      Pair(-24, -23), Pair(-17, -14), Pair(-3, -17), Pair(-3, -17), Pair(3, -28), Pair(7, -25), Pair(14, -35), Pair(-18, -39),
      Pair(-11, -18), Pair(-5, -18), Pair(1, -14), Pair(6, -21), Pair(12, -29), Pair(7, -21), Pair(1, -26), Pair(-7, -37)
  },
  {
      Pair(-50, -3), Pair(-55, 9), Pair(-41, 28), Pair(-18, 12), Pair(-27, 17), Pair(-17, 18), Pair(26, -35), Pair(-29, -3),
      Pair(-4, -17), Pair(-23, 14), Pair(-26, 46), Pair(-37, 63), Pair(-57, 84), Pair(-10, 32), Pair(-8, 24), Pair(41, -1),
      Pair(-3, -5), Pair(-7, 10), Pair(-8, 41), Pair(-8, 44), Pair(-11, 55), Pair(18, 31), Pair(24, 5), Pair(12, -2),
      Pair(-12, 4), Pair(-8, 22), Pair(-7, 28), Pair(-12, 49), Pair(-9, 48), Pair(1, 29), Pair(8, 25), Pair(6, 5),
      Pair(-7, -3), Pair(-13, 24), Pair(-7, 21), Pair(-3, 36), Pair(2, 34), Pair(-6, 23), Pair(10, 10), Pair(7, -1),
      Pair(-5, -20), Pair(0, -1), Pair(0, 9), Pair(-4, 14), Pair(2, 19), Pair(6, 12), Pair(19, -8), Pair(12, -22),
      Pair(1, -32), Pair(3, -28), Pair(8, -22), Pair(14, -17), Pair(12, -11), Pair(23, -39), Pair(27, -58), Pair(30, -80),
      Pair(-6, -31), Pair(-1, -29), Pair(3, -22), Pair(6, -11), Pair(11, -28), Pair(0, -36), Pair(7, -52), Pair(8, -57)
  },
  {
      Pair(70, -88), Pair(79, -41), Pair(49, -22), Pair(-76, 18), Pair(-47, 0), Pair(-50, 6), Pair(25, -11), Pair(148, -117),
      Pair(-62, 3), Pair(12, 26), Pair(-33, 35), Pair(50, 20), Pair(-10, 30), Pair(-13, 46), Pair(17, 33), Pair(-56, 11),
      Pair(-66, 4), Pair(80, 13), Pair(-13, 35), Pair(-45, 47), Pair(-17, 46), Pair(62, 29), Pair(8, 31), Pair(-33, 2),
      Pair(-36, -15), Pair(11, 4), Pair(-50, 29), Pair(-107, 46), Pair(-109, 42), Pair(-66, 31), Pair(-47, 12), Pair(-117, 2),
      Pair(-41, -28), Pair(-3, -7), Pair(-64, 22), Pair(-106, 42), Pair(-106, 37), Pair(-59, 16), Pair(-51, -1), Pair(-119, -9),
      Pair(-19, -30), Pair(24, -13), Pair(-36, 12), Pair(-53, 27), Pair(-49, 23), Pair(-43, 9), Pair(-9, -13), Pair(-41, -22),
      Pair(37, -39), Pair(8, -10), Pair(1, 1), Pair(-22, 12), Pair(-28, 13), Pair(-15, 1), Pair(7, -17), Pair(22, -39),
      Pair(25, -64), Pair(41, -38), Pair(28, -23), Pair(-32, -2), Pair(12, -25), Pair(-21, -11), Pair(25, -35), Pair(36, -75)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-33, -6), Pair(-19, 2), Pair(-9, 23), Pair(-4, 32), Pair(2, 38), Pair(8, 47), Pair(16, 46), Pair(22, 44),
  Pair(26, 36)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-30, -24), Pair(-21, -20), Pair(-11, -4), Pair(-4, 10), Pair(3, 18), Pair(7, 28), Pair(10, 32), Pair(11, 35),
  Pair(11, 38), Pair(15, 36), Pair(23, 32), Pair(26, 32), Pair(22, 46), Pair(28, 24)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-22, -55), Pair(-15, -26), Pair(-11, -22), Pair(-8, -17), Pair(-11, -9), Pair(-6, -4), Pair(-5, 2), Pair(-3, 4),
  Pair(-1, 7), Pair(1, 11), Pair(4, 12), Pair(2, 18), Pair(4, 19), Pair(5, 15), Pair(-2, 13)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-1, -250), Pair(1, -239), Pair(-10, -98), Pair(-8, -51), Pair(-7, -27), Pair(-4, -15), Pair(-2, 3), Pair(-1, 16),
  Pair(2, 23), Pair(4, 25), Pair(5, 31), Pair(7, 36), Pair(9, 37), Pair(8, 42), Pair(10, 43), Pair(12, 46),
  Pair(11, 53), Pair(12, 51), Pair(20, 47), Pair(33, 36), Pair(34, 36), Pair(82, 5), Pair(66, 12), Pair(82, -9),
  Pair(183, -49), Pair(202, -85), Pair(119, -29), Pair(77, -26)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-4, -4), Pair(-9, 11), Pair(-6, 47), Pair(18, 83), Pair(15, 151), Pair(16, 43), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-2, -1), Pair(17, 10), Pair(43, 48), Pair(117, 175), Pair(-138, 433), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-10, -47), Pair(6, -38), Pair(-5, -27), Pair(-8, -14), Pair(-17, -6), Pair(-15, -22), Pair(3, -33), Pair(-6, -51)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-14, 8), Pair(-7, -16), Pair(-17, -11), Pair(-15, -20), Pair(-19, -21), Pair(-10, -11), Pair(-6, -16), Pair(-12, 4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(29, 10), Pair(27, 3), Pair(23, 11), Pair(27, 10), Pair(28, 15), Pair(39, 2), Pair(50, 2), Pair(75, 3)
  },
  {
      Pair(3, 47), Pair(8, 18), Pair(7, 18), Pair(17, 8), Pair(11, 11), Pair(14, 5), Pair(25, 7), Pair(11, 33)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(19, -1), Pair(12, -2),
  Pair(25, -11), Pair(22, -7), Pair(24, -11),
  Pair(34, -2), Pair(0, 0), Pair(31, -1),
  Pair(-11, 4), Pair(-15, 4), Pair(-11, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-14, 4), Pair(-8, 4),
  Pair(-6, 2), Pair(-15, 6), Pair(-8, 4),
  Pair(-1, -6), Pair(-12, 0), Pair(-1, -5),
  Pair(14, -8), Pair(-5, -4), Pair(11, -6),
  Pair(32, -9), Pair(23, -1), Pair(25, -8),
  Pair(0, 0), Pair(0, -32), Pair(0, 0),
  Pair(50, -50), Pair(0, 0), Pair(44, -48)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-18, 16), Pair(-23, 1), Pair(-16, -20), Pair(-13, -30), Pair(-8, -33), Pair(8, -36), Pair(-2, -37)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-67, -25), Pair(5, -25), Pair(5, 0), Pair(10, 10), Pair(9, 17), Pair(8, 23), Pair(-10, 21)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-88, -6), Pair(-95, 1), Pair(-55, -5), Pair(-49, -3), Pair(-37, 1), Pair(-64, 6), Pair(-63, 8), Pair(-51, 10)
  },
  {
      Pair(-24, 54), Pair(-41, 24), Pair(-20, 16), Pair(-2, -2), Pair(-5, -4), Pair(-13, 9), Pair(-31, 26), Pair(-30, 41)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 4), Pair(35, -6), Pair(78, -22), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 4), Pair(31, -5), Pair(53, -14), Pair(58, -44), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -15), Pair(35, -18), Pair(56, -17), Pair(87, -23), Pair(100, -37), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 9), Pair(15, 24), Pair(39, 31), Pair(85, 19), Pair(125, 22), Pair(213, -24), Pair(235, -39)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(0, 0), Pair(-53, -24), Pair(-60, -47), Pair(-70, -16), Pair(-60, 6), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(1, 24), Pair(-5, 15), Pair(12, 24), Pair(30, 26), Pair(13, 36), Pair(17, 49), Pair(17, 22), Pair(-13, 40),
  Pair(-1, 19), Pair(11, 18), Pair(9, 23), Pair(0, 38), Pair(5, 26), Pair(4, 22), Pair(14, 14), Pair(-2, 28),
  Pair(7, 14), Pair(-3, 7), Pair(-4, 19), Pair(3, 21), Pair(0, 26), Pair(-11, 21), Pair(-4, 9), Pair(-2, 10)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-18, 12), Pair(9, -2), Pair(10, 0), Pair(24, 2), Pair(55, -15), Pair(26, -6), Pair(19, -16), Pair(-25, -26),
  Pair(-23, -6), Pair(18, 4), Pair(4, 0), Pair(17, 7), Pair(8, 1), Pair(17, -5), Pair(11, 11), Pair(18, -25),
  Pair(-27, 27), Pair(7, 4), Pair(2, 17), Pair(15, 12), Pair(21, 20), Pair(0, 7), Pair(14, -3), Pair(-52, 11)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 64);

constexpr ScorePair kTempoBonus = Pair(24, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H