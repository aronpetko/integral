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
  Pair(81, 185), Pair(288, 280), Pair(352, 347), Pair(411, 692), Pair(855, 1233), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(49, 129), Pair(35, 131), Pair(21, 133), Pair(64, 89), Pair(55, 92), Pair(50, 103), Pair(-17, 147), Pair(-18, 143),
      Pair(1, -42), Pair(-17, -22), Pair(16, -66), Pair(23, -96), Pair(41, -99), Pair(63, -86), Pair(18, -38), Pair(2, -47),
      Pair(-23, -54), Pair(-23, -47), Pair(-17, -73), Pair(-9, -89), Pair(10, -90), Pair(5, -85), Pair(-14, -55), Pair(-12, -72),
      Pair(-29, -69), Pair(-32, -50), Pair(-20, -78), Pair(-8, -85), Pair(-5, -85), Pair(-4, -84), Pair(-20, -60), Pair(-16, -83),
      Pair(-39, -73), Pair(-43, -57), Pair(-32, -78), Pair(-25, -78), Pair(-19, -78), Pair(-22, -81), Pair(-22, -67), Pair(-22, -87),
      Pair(-31, -68), Pair(-34, -51), Pair(-25, -70), Pair(-28, -76), Pair(-19, -66), Pair(-6, -76), Pair(-9, -64), Pair(-22, -85),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-120, -27), Pair(-87, 13), Pair(-51, 30), Pair(-7, 13), Pair(10, 17), Pair(-33, -4), Pair(-81, 13), Pair(-84, -47),
      Pair(-10, 23), Pair(7, 36), Pair(15, 36), Pair(28, 34), Pair(24, 23), Pair(59, 17), Pair(20, 26), Pair(14, 4),
      Pair(12, 26), Pair(26, 37), Pair(27, 53), Pair(39, 46), Pair(50, 42), Pair(80, 17), Pair(20, 29), Pair(35, 9),
      Pair(24, 36), Pair(24, 42), Pair(43, 51), Pair(55, 51), Pair(45, 50), Pair(54, 48), Pair(32, 37), Pair(50, 23),
      Pair(13, 39), Pair(27, 40), Pair(37, 58), Pair(41, 56), Pair(42, 60), Pair(52, 41), Pair(41, 36), Pair(27, 33),
      Pair(-9, 28), Pair(13, 35), Pair(20, 44), Pair(32, 57), Pair(43, 53), Pair(28, 37), Pair(31, 29), Pair(14, 31),
      Pair(-13, 27), Pair(-1, 35), Pair(10, 39), Pair(23, 39), Pair(26, 37), Pair(20, 36), Pair(19, 24), Pair(16, 36),
      Pair(-45, 31), Pair(-9, 24), Pair(-9, 34), Pair(6, 39), Pair(13, 38), Pair(17, 25), Pair(-4, 30), Pair(-7, 23)
  },
  {
      Pair(-49, 33), Pair(-66, 33), Pair(-67, 26), Pair(-97, 33), Pair(-97, 32), Pair(-93, 23), Pair(-54, 25), Pair(-78, 21),
      Pair(-36, 15), Pair(-27, 27), Pair(-26, 24), Pair(-38, 28), Pair(-39, 24), Pair(-25, 22), Pair(-50, 31), Pair(-47, 17),
      Pair(-21, 30), Pair(-12, 27), Pair(-18, 33), Pair(-16, 25), Pair(-21, 29), Pair(16, 33), Pair(3, 29), Pair(-7, 30),
      Pair(-33, 29), Pair(-22, 33), Pair(-17, 34), Pair(-2, 39), Pair(-5, 34), Pair(-10, 36), Pair(-25, 30), Pair(-31, 27),
      Pair(-27, 23), Pair(-35, 34), Pair(-20, 33), Pair(-3, 33), Pair(-3, 28), Pair(-20, 33), Pair(-28, 31), Pair(-13, 13),
      Pair(-32, 24), Pair(-11, 32), Pair(-12, 34), Pair(-13, 38), Pair(-13, 42), Pair(-9, 33), Pair(-8, 25), Pair(-14, 15),
      Pair(-18, 25), Pair(-13, 14), Pair(-4, 17), Pair(-21, 30), Pair(-10, 27), Pair(-4, 21), Pair(6, 18), Pair(-5, 8),
      Pair(-27, 13), Pair(-8, 32), Pair(-29, 25), Pair(-29, 27), Pair(-20, 23), Pair(-28, 31), Pair(-16, 17), Pair(0, -7)
  },
  {
      Pair(-12, 2), Pair(-10, 11), Pair(-5, 13), Pair(-10, 11), Pair(2, 0), Pair(20, 3), Pair(8, 5), Pair(-14, 2),
      Pair(-8, -3), Pair(-4, 9), Pair(9, 6), Pair(26, -4), Pair(11, -7), Pair(30, -5), Pair(25, -8), Pair(3, -10),
      Pair(-13, -3), Pair(15, -1), Pair(12, -3), Pair(8, -6), Pair(36, -18), Pair(47, -21), Pair(61, -21), Pair(10, -22),
      Pair(-14, -2), Pair(0, 0), Pair(2, 1), Pair(6, -3), Pair(10, -18), Pair(13, -17), Pair(12, -15), Pair(-7, -19),
      Pair(-19, -9), Pair(-19, 0), Pair(-8, -5), Pair(-3, -5), Pair(-1, -13), Pair(-19, -5), Pair(3, -18), Pair(-15, -23),
      Pair(-22, -14), Pair(-16, -9), Pair(-10, -13), Pair(-9, -10), Pair(0, -19), Pair(-1, -20), Pair(21, -37), Pair(0, -40),
      Pair(-20, -21), Pair(-13, -12), Pair(0, -15), Pair(-1, -15), Pair(6, -25), Pair(3, -24), Pair(12, -33), Pair(-18, -36),
      Pair(-9, -18), Pair(-3, -16), Pair(3, -12), Pair(7, -18), Pair(14, -27), Pair(6, -22), Pair(1, -24), Pair(-8, -34)
  },
  {
      Pair(-41, -1), Pair(-40, -1), Pair(-28, 18), Pair(-4, 8), Pair(-17, 16), Pair(-14, 16), Pair(33, -42), Pair(-14, -5),
      Pair(-4, -17), Pair(-15, 2), Pair(-20, 37), Pair(-35, 51), Pair(-54, 76), Pair(-13, 36), Pair(-6, 15), Pair(31, 0),
      Pair(-1, -13), Pair(-2, -1), Pair(-7, 29), Pair(-3, 30), Pair(-7, 43), Pair(20, 22), Pair(20, -2), Pair(17, -5),
      Pair(-10, -5), Pair(-4, 14), Pair(-4, 24), Pair(-6, 39), Pair(-6, 38), Pair(3, 19), Pair(11, 15), Pair(8, -1),
      Pair(-4, -10), Pair(-9, 26), Pair(-5, 26), Pair(-1, 41), Pair(4, 31), Pair(-2, 21), Pair(11, 6), Pair(9, -4),
      Pair(-3, -20), Pair(1, 3), Pair(0, 20), Pair(-2, 21), Pair(1, 22), Pair(6, 12), Pair(19, -8), Pair(12, -22),
      Pair(2, -27), Pair(5, -22), Pair(9, -17), Pair(13, -10), Pair(12, -8), Pair(19, -34), Pair(24, -56), Pair(31, -77),
      Pair(-8, -19), Pair(0, -24), Pair(2, -15), Pair(3, -7), Pair(11, -30), Pair(-1, -38), Pair(4, -46), Pair(4, -45)
  },
  {
      Pair(79, -107), Pair(94, -65), Pair(68, -42), Pair(-42, -5), Pair(-22, -20), Pair(-78, -5), Pair(-14, -23), Pair(124, -132),
      Pair(-86, -9), Pair(-3, 14), Pair(-22, 19), Pair(71, 1), Pair(-3, 14), Pair(-31, 34), Pair(-27, 25), Pair(-93, 1),
      Pair(-76, -7), Pair(67, 3), Pair(12, 18), Pair(-27, 31), Pair(9, 28), Pair(65, 16), Pair(-21, 23), Pair(-46, -10),
      Pair(-41, -25), Pair(10, -8), Pair(-27, 13), Pair(-74, 29), Pair(-79, 24), Pair(-51, 17), Pair(-39, -3), Pair(-136, -7),
      Pair(-41, -41), Pair(7, -21), Pair(-40, 6), Pair(-81, 25), Pair(-78, 19), Pair(-42, 0), Pair(-42, -16), Pair(-117, -23),
      Pair(-22, -44), Pair(27, -27), Pair(-23, -4), Pair(-38, 11), Pair(-35, 6), Pair(-33, -6), Pair(-7, -27), Pair(-41, -39),
      Pair(33, -56), Pair(7, -24), Pair(4, -14), Pair(-17, -3), Pair(-22, -3), Pair(-13, -13), Pair(5, -32), Pair(20, -58),
      Pair(18, -81), Pair(35, -53), Pair(23, -37), Pair(-38, -15), Pair(4, -39), Pair(-25, -24), Pair(19, -50), Pair(27, -90)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-31, 29), Pair(-18, 30), Pair(-8, 50), Pair(-2, 58), Pair(3, 63), Pair(8, 69), Pair(15, 66), Pair(19, 63),
  Pair(22, 54)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-37, -20), Pair(-27, -21), Pair(-19, -6), Pair(-14, 4), Pair(-8, 11), Pair(-6, 20), Pair(-4, 23), Pair(-3, 27),
  Pair(-2, 29), Pair(2, 27), Pair(9, 24), Pair(15, 24), Pair(11, 36), Pair(19, 18)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-22, -48), Pair(-14, -22), Pair(-12, -17), Pair(-9, -12), Pair(-12, -6), Pair(-8, -3), Pair(-8, 2), Pair(-7, 5),
  Pair(-6, 7), Pair(-5, 10), Pair(-2, 11), Pair(-4, 16), Pair(-3, 17), Pair(-1, 15), Pair(-4, 14)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(2, -205), Pair(5, -188), Pair(-5, -67), Pair(-3, -25), Pair(-3, -2), Pair(-1, 9), Pair(1, 25), Pair(2, 36),
  Pair(4, 42), Pair(6, 43), Pair(7, 47), Pair(9, 50), Pair(11, 48), Pair(10, 51), Pair(13, 50), Pair(15, 48),
  Pair(15, 51), Pair(17, 46), Pair(27, 35), Pair(39, 21), Pair(42, 15), Pair(89, -20), Pair(78, -20), Pair(99, -49),
  Pair(178, -81), Pair(199, -125), Pair(140, -89), Pair(91, -87)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(2, 14), Pair(1, 28), Pair(3, 61), Pair(29, 96), Pair(26, 163), Pair(37, 50), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 0), Pair(15, 7), Pair(22, 18), Pair(47, 60), Pair(123, 190), Pair(-222, 476), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(14, 6), Pair(14, 13), Pair(22, 41), Pair(149, 32), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-10, -46), Pair(10, -36), Pair(1, -25), Pair(-2, -14), Pair(-10, -5), Pair(-9, -19), Pair(8, -32), Pair(-5, -49)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-7, 12), Pair(-2, -11), Pair(-11, -5), Pair(-8, -12), Pair(-11, -15), Pair(-5, -6), Pair(1, -13), Pair(-5, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 6), Pair(25, 2), Pair(21, 8), Pair(24, 7), Pair(24, 12), Pair(37, 3), Pair(46, 2), Pair(75, 0)
  },
  {
      Pair(6, 29), Pair(9, 6), Pair(8, 5), Pair(16, -4), Pair(11, 0), Pair(16, -5), Pair(24, -2), Pair(15, 17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -6), Pair(16, -6), Pair(9, -3),
  Pair(21, -11), Pair(16, -11), Pair(20, -11),
  Pair(30, -4), Pair(0, 0), Pair(27, -3),
  Pair(-10, 5), Pair(-15, 1), Pair(-10, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-13, 3), Pair(-9, 3),
  Pair(-6, 1), Pair(-15, 5), Pair(-10, 3),
  Pair(-1, -7), Pair(-12, 0), Pair(-1, -5),
  Pair(12, -8), Pair(-4, -5), Pair(10, -6),
  Pair(29, -8), Pair(24, 0), Pair(23, -8),
  Pair(0, 0), Pair(6, -31), Pair(0, 0),
  Pair(58, -49), Pair(0, 0), Pair(50, -46)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-24, 20), Pair(-26, 5), Pair(-17, -16), Pair(-14, -26), Pair(-10, -27), Pair(1, -29), Pair(-10, -32)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-77, -42), Pair(-1, -40), Pair(-4, -16), Pair(4, -9), Pair(7, -4), Pair(7, 1), Pair(-7, -1)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-186, 200);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-54, -14), Pair(-70, -6), Pair(-40, -9), Pair(-28, -8), Pair(-23, -1), Pair(-40, 1), Pair(-53, 3), Pair(-37, 6)
  },
  {
      Pair(-18, 47), Pair(-39, 20), Pair(-23, 12), Pair(-3, -4), Pair(-7, -7), Pair(-11, 5), Pair(-33, 23), Pair(-23, 35)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -1), Pair(28, -11), Pair(66, -34), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -1), Pair(31, -3), Pair(60, -11), Pair(65, -40), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -20), Pair(34, -22), Pair(56, -17), Pair(86, -21), Pair(100, -31), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 10), Pair(16, 19), Pair(39, 22), Pair(81, 6), Pair(111, 5), Pair(167, -14), Pair(234, -66)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(18, -5), Pair(32, 14), Pair(31, 20), Pair(54, 0), Pair(30, 12), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-13, 15), Pair(-62, -22), Pair(-63, -52), Pair(-82, -6), Pair(-76, 32), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -15), Pair(14, -2), Pair(-29, -37), Pair(-67, -14), Pair(-51, 28), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -17), Pair(-18, -26), Pair(7, -27), Pair(-49, -23), Pair(-64, -52), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(1, -22), Pair(-14, -26), Pair(-19, -30), Pair(12, -32), Pair(-79, -7), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(11, 23), Pair(14, 11), Pair(27, 21), Pair(37, 19), Pair(38, 27), Pair(22, 45), Pair(39, 15), Pair(-5, 37),
  Pair(-2, 13), Pair(12, 15), Pair(10, 20), Pair(0, 33), Pair(6, 21), Pair(3, 22), Pair(12, 15), Pair(-7, 25),
  Pair(7, 7), Pair(1, 1), Pair(-3, 14), Pair(2, 14), Pair(1, 20), Pair(-11, 18), Pair(-3, 7), Pair(-3, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-15, 12), Pair(14, -1), Pair(19, 1), Pair(33, 0), Pair(54, -14), Pair(33, -3), Pair(20, -11), Pair(-16, -30),
  Pair(-26, -10), Pair(19, 5), Pair(8, 2), Pair(14, 11), Pair(8, 3), Pair(15, -2), Pair(13, 10), Pair(16, -22),
  Pair(-25, 29), Pair(5, 4), Pair(-1, 18), Pair(14, 11), Pair(17, 21), Pair(-1, 7), Pair(10, -1), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 59);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H