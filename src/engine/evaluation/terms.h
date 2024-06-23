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
  Pair(86, 180), Pair(297, 320), Pair(336, 347), Pair(412, 702), Pair(862, 1267), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(49, 135), Pair(29, 137), Pair(20, 140), Pair(59, 95), Pair(47, 98), Pair(44, 109), Pair(-24, 153), Pair(-20, 148),
      Pair(-3, -23), Pair(-17, -5), Pair(17, -47), Pair(21, -77), Pair(34, -81), Pair(62, -67), Pair(16, -19), Pair(-3, -30),
      Pair(-25, -39), Pair(-26, -33), Pair(-13, -58), Pair(-8, -76), Pair(13, -79), Pair(6, -72), Pair(-14, -41), Pair(-14, -58),
      Pair(-31, -56), Pair(-35, -40), Pair(-19, -65), Pair(-2, -73), Pair(-1, -76), Pair(-1, -74), Pair(-20, -51), Pair(-16, -73),
      Pair(-31, -60), Pair(-28, -46), Pair(-17, -66), Pair(-12, -66), Pair(0, -67), Pair(-7, -70), Pair(-5, -57), Pair(-12, -76),
      Pair(-31, -55), Pair(-30, -39), Pair(-21, -58), Pair(-24, -62), Pair(-12, -54), Pair(2, -65), Pair(0, -54), Pair(-23, -74),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-131, -38), Pair(-104, 10), Pair(-60, 26), Pair(-29, 12), Pair(-9, 16), Pair(-63, -6), Pair(-95, 9), Pair(-97, -55),
      Pair(-5, 16), Pair(14, 25), Pair(39, 20), Pair(41, 21), Pair(18, 13), Pair(78, 3), Pair(10, 22), Pair(21, -5),
      Pair(12, 18), Pair(42, 23), Pair(44, 42), Pair(34, 42), Pair(69, 28), Pair(73, 13), Pair(40, 16), Pair(25, 6),
      Pair(15, 32), Pair(14, 38), Pair(30, 47), Pair(56, 42), Pair(23, 48), Pair(48, 47), Pair(4, 44), Pair(38, 20),
      Pair(4, 33), Pair(15, 34), Pair(25, 49), Pair(29, 46), Pair(34, 52), Pair(41, 36), Pair(36, 33), Pair(18, 29),
      Pair(-17, 22), Pair(3, 30), Pair(10, 35), Pair(20, 49), Pair(36, 46), Pair(19, 30), Pair(23, 24), Pair(5, 25),
      Pair(-22, 22), Pair(-9, 28), Pair(2, 30), Pair(17, 29), Pair(19, 28), Pair(18, 26), Pair(12, 19), Pair(9, 31),
      Pair(-52, 24), Pair(-16, 17), Pair(-16, 25), Pair(-2, 31), Pair(6, 30), Pair(10, 19), Pair(-11, 23), Pair(-17, 17)
  },
  {
      Pair(-50, 33), Pair(-74, 35), Pair(-72, 29), Pair(-117, 38), Pair(-111, 38), Pair(-110, 27), Pair(-65, 27), Pair(-81, 22),
      Pair(-27, 14), Pair(-2, 23), Pair(-18, 25), Pair(-33, 30), Pair(-20, 20), Pair(-26, 24), Pair(-30, 30), Pair(-45, 18),
      Pair(-17, 31), Pair(-1, 27), Pair(0, 32), Pair(-1, 21), Pair(-17, 30), Pair(26, 34), Pair(6, 33), Pair(-2, 30),
      Pair(-26, 28), Pair(-13, 33), Pair(-3, 32), Pair(4, 44), Pair(2, 38), Pair(-2, 39), Pair(-17, 29), Pair(-30, 30),
      Pair(-20, 23), Pair(-28, 33), Pair(-17, 37), Pair(4, 36), Pair(2, 32), Pair(-17, 34), Pair(-20, 33), Pair(-5, 13),
      Pair(-23, 23), Pair(-6, 36), Pair(-7, 36), Pair(-9, 40), Pair(-6, 44), Pair(-3, 36), Pair(-3, 29), Pair(-2, 17),
      Pair(-11, 30), Pair(-8, 16), Pair(0, 18), Pair(-17, 28), Pair(-5, 28), Pair(6, 22), Pair(14, 21), Pair(0, 11),
      Pair(-22, 17), Pair(0, 32), Pair(-23, 22), Pair(-24, 27), Pair(-16, 24), Pair(-22, 33), Pair(-8, 17), Pair(7, -5)
  },
  {
      Pair(-2, 2), Pair(-8, 14), Pair(-8, 16), Pair(-12, 12), Pair(-6, 2), Pair(14, 9), Pair(8, 8), Pair(-5, 4),
      Pair(-5, 5), Pair(-5, 22), Pair(12, 20), Pair(24, 10), Pair(8, 7), Pair(34, 6), Pair(23, 2), Pair(12, -5),
      Pair(-14, 3), Pair(13, 7), Pair(11, 4), Pair(8, 2), Pair(35, -13), Pair(47, -10), Pair(67, -15), Pair(16, -19),
      Pair(-16, 3), Pair(-2, 5), Pair(2, 7), Pair(5, 2), Pair(9, -13), Pair(10, -6), Pair(11, -6), Pair(-6, -14),
      Pair(-22, -9), Pair(-22, 2), Pair(-9, -5), Pair(-6, -5), Pair(-3, -12), Pair(-21, 0), Pair(2, -14), Pair(-17, -21),
      Pair(-25, -16), Pair(-18, -11), Pair(-11, -15), Pair(-13, -12), Pair(-1, -23), Pair(-4, -19), Pair(20, -36), Pair(-2, -41),
      Pair(-24, -24), Pair(-17, -14), Pair(-3, -17), Pair(-3, -18), Pair(3, -28), Pair(6, -25), Pair(13, -36), Pair(-19, -39),
      Pair(-11, -19), Pair(-5, -18), Pair(1, -14), Pair(5, -21), Pair(12, -29), Pair(7, -21), Pair(0, -27), Pair(-7, -36)
  },
  {
      Pair(-49, -2), Pair(-55, 9), Pair(-40, 28), Pair(-17, 12), Pair(-27, 17), Pair(-16, 18), Pair(27, -34), Pair(-28, -3),
      Pair(-3, -17), Pair(-22, 14), Pair(-26, 45), Pair(-37, 63), Pair(-57, 84), Pair(-9, 32), Pair(-7, 24), Pair(42, -1),
      Pair(-2, -5), Pair(-7, 10), Pair(-8, 41), Pair(-7, 44), Pair(-11, 55), Pair(18, 31), Pair(24, 5), Pair(13, -1),
      Pair(-11, 4), Pair(-7, 21), Pair(-6, 28), Pair(-12, 49), Pair(-9, 47), Pair(2, 29), Pair(8, 26), Pair(7, 5),
      Pair(-7, -4), Pair(-12, 24), Pair(-6, 20), Pair(-2, 36), Pair(2, 34), Pair(-5, 23), Pair(11, 10), Pair(8, -1),
      Pair(-4, -20), Pair(0, -1), Pair(1, 9), Pair(-4, 14), Pair(3, 19), Pair(6, 12), Pair(19, -8), Pair(13, -21),
      Pair(1, -32), Pair(3, -28), Pair(8, -22), Pair(14, -17), Pair(12, -11), Pair(23, -40), Pair(27, -58), Pair(30, -81),
      Pair(-6, -31), Pair(0, -30), Pair(3, -22), Pair(6, -11), Pair(11, -29), Pair(1, -36), Pair(7, -52), Pair(9, -57)
  },
  {
      Pair(68, -87), Pair(77, -41), Pair(49, -22), Pair(-76, 18), Pair(-49, 1), Pair(-54, 8), Pair(22, -10), Pair(143, -115),
      Pair(-61, 3), Pair(12, 26), Pair(-31, 35), Pair(51, 20), Pair(-10, 31), Pair(-12, 47), Pair(18, 34), Pair(-55, 12),
      Pair(-65, 4), Pair(81, 13), Pair(-12, 36), Pair(-45, 48), Pair(-17, 47), Pair(62, 29), Pair(9, 32), Pair(-32, 3),
      Pair(-35, -14), Pair(12, 4), Pair(-49, 31), Pair(-107, 47), Pair(-109, 42), Pair(-66, 32), Pair(-46, 13), Pair(-116, 2),
      Pair(-40, -28), Pair(-3, -6), Pair(-63, 23), Pair(-105, 43), Pair(-106, 38), Pair(-58, 17), Pair(-50, 0), Pair(-118, -7),
      Pair(-18, -30), Pair(25, -13), Pair(-34, 12), Pair(-53, 28), Pair(-48, 24), Pair(-42, 10), Pair(-8, -12), Pair(-41, -22),
      Pair(37, -39), Pair(9, -9), Pair(1, 2), Pair(-21, 13), Pair(-27, 13), Pair(-14, 2), Pair(8, -17), Pair(23, -39),
      Pair(26, -64), Pair(42, -38), Pair(29, -23), Pair(-32, -1), Pair(12, -25), Pair(-22, -10), Pair(25, -34), Pair(36, -74)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-33, -7), Pair(-20, 1), Pair(-9, 21), Pair(-4, 30), Pair(2, 37), Pair(8, 45), Pair(16, 44), Pair(21, 43),
  Pair(26, 33)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-30, -25), Pair(-21, -21), Pair(-10, -5), Pair(-4, 8), Pair(4, 18), Pair(7, 28), Pair(10, 31), Pair(11, 34),
  Pair(12, 38), Pair(15, 35), Pair(23, 31), Pair(26, 32), Pair(23, 45), Pair(29, 24)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-22, -51), Pair(-15, -21), Pair(-12, -17), Pair(-9, -12), Pair(-12, -4), Pair(-7, 0), Pair(-6, 6), Pair(-4, 9),
  Pair(-1, 12), Pair(1, 16), Pair(3, 17), Pair(1, 22), Pair(3, 24), Pair(4, 20), Pair(-3, 18)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-1, -248), Pair(2, -238), Pair(-9, -95), Pair(-7, -49), Pair(-6, -26), Pair(-3, -14), Pair(-1, 3), Pair(0, 17),
  Pair(3, 24), Pair(4, 26), Pair(6, 32), Pair(8, 38), Pair(9, 38), Pair(9, 44), Pair(11, 45), Pair(12, 48),
  Pair(11, 55), Pair(12, 54), Pair(21, 48), Pair(33, 38), Pair(35, 38), Pair(82, 7), Pair(67, 15), Pair(82, -6),
  Pair(182, -46), Pair(204, -84), Pair(135, -35), Pair(89, -30)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-9, -13), Pair(-14, 2), Pair(-11, 38), Pair(13, 74), Pair(9, 141), Pair(14, 37), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-2, -1), Pair(17, 10), Pair(43, 48), Pair(116, 175), Pair(-171, 441), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-10, -47), Pair(6, -37), Pair(-6, -27), Pair(-8, -14), Pair(-17, -5), Pair(-15, -21), Pair(4, -33), Pair(-6, -51)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-14, 7), Pair(-7, -16), Pair(-17, -11), Pair(-15, -20), Pair(-19, -21), Pair(-10, -11), Pair(-6, -16), Pair(-12, 4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(29, 10), Pair(27, 3), Pair(23, 11), Pair(27, 10), Pair(29, 15), Pair(39, 1), Pair(50, 2), Pair(75, 2)
  },
  {
      Pair(3, 47), Pair(8, 18), Pair(7, 19), Pair(17, 8), Pair(12, 11), Pair(14, 4), Pair(25, 8), Pair(13, 32)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(20, -2), Pair(12, -1),
  Pair(25, -11), Pair(21, -7), Pair(24, -11),
  Pair(33, -1), Pair(0, 0), Pair(30, -1),
  Pair(-10, 4), Pair(-14, 3), Pair(-11, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, 2), Pair(-14, 4), Pair(-9, 4),
  Pair(-6, 2), Pair(-15, 6), Pair(-8, 4),
  Pair(-1, -6), Pair(-13, 0), Pair(-1, -5),
  Pair(14, -9), Pair(-6, -4), Pair(11, -6),
  Pair(32, -9), Pair(22, -1), Pair(26, -9),
  Pair(0, 0), Pair(0, -32), Pair(0, 0),
  Pair(49, -50), Pair(0, 0), Pair(44, -48)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-15, 19), Pair(-20, 4), Pair(-12, -17), Pair(-10, -28), Pair(-5, -30), Pair(11, -32), Pair(0, -35)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-64, -19), Pair(8, -19), Pair(7, 6), Pair(12, 16), Pair(11, 23), Pair(10, 29), Pair(-8, 28)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-87, -6), Pair(-95, 0), Pair(-55, -5), Pair(-48, -3), Pair(-36, 1), Pair(-63, 6), Pair(-63, 7), Pair(-50, 9)
  },
  {
      Pair(-24, 54), Pair(-41, 24), Pair(-21, 16), Pair(-2, -2), Pair(-6, -5), Pair(-13, 8), Pair(-31, 25), Pair(-29, 40)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(14, 4), Pair(34, -6), Pair(78, -22), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 4), Pair(31, -5), Pair(53, -15), Pair(58, -43), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -14), Pair(35, -18), Pair(57, -18), Pair(88, -23), Pair(100, -37), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 8), Pair(15, 23), Pair(39, 30), Pair(85, 19), Pair(125, 21), Pair(213, -24), Pair(277, -68)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(0, 0), Pair(-54, -21), Pair(-62, -43), Pair(-81, -5), Pair(-71, 38), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(1, 24), Pair(-6, 15), Pair(12, 24), Pair(30, 26), Pair(14, 36), Pair(16, 49), Pair(17, 22), Pair(-13, 40),
  Pair(-2, 19), Pair(11, 18), Pair(9, 23), Pair(-1, 38), Pair(5, 26), Pair(4, 22), Pair(14, 14), Pair(-3, 28),
  Pair(7, 14), Pair(-3, 7), Pair(-4, 20), Pair(3, 21), Pair(-1, 27), Pair(-12, 21), Pair(-4, 9), Pair(-3, 10)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-18, 13), Pair(9, -2), Pair(10, 0), Pair(24, 2), Pair(55, -14), Pair(26, -5), Pair(19, -16), Pair(-25, -25),
  Pair(-23, -6), Pair(18, 4), Pair(4, 1), Pair(17, 7), Pair(8, 1), Pair(17, -5), Pair(11, 11), Pair(18, -25),
  Pair(-27, 28), Pair(7, 4), Pair(2, 18), Pair(15, 12), Pair(21, 20), Pair(0, 7), Pair(14, -3), Pair(-52, 11)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 64);

constexpr ScorePair kTempoBonus = Pair(23, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H