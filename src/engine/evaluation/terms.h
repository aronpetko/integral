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
  Pair(80, 185), Pair(285, 267), Pair(352, 349), Pair(410, 691), Pair(853, 1233), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(48, 128), Pair(35, 131), Pair(21, 132), Pair(63, 88), Pair(53, 92), Pair(49, 103), Pair(-18, 145), Pair(-19, 142),
      Pair(2, -43), Pair(-17, -21), Pair(16, -66), Pair(22, -97), Pair(39, -100), Pair(62, -87), Pair(19, -39), Pair(2, -48),
      Pair(-23, -55), Pair(-23, -47), Pair(-17, -73), Pair(-10, -90), Pair(10, -90), Pair(5, -85), Pair(-14, -55), Pair(-12, -72),
      Pair(-29, -69), Pair(-32, -50), Pair(-20, -78), Pair(-8, -85), Pair(-4, -86), Pair(-4, -84), Pair(-19, -61), Pair(-17, -83),
      Pair(-40, -74), Pair(-43, -57), Pair(-32, -78), Pair(-26, -78), Pair(-19, -78), Pair(-22, -81), Pair(-22, -68), Pair(-22, -87),
      Pair(-32, -68), Pair(-34, -51), Pair(-25, -70), Pair(-28, -76), Pair(-19, -67), Pair(-6, -76), Pair(-8, -65), Pair(-22, -85),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-120, -23), Pair(-85, 15), Pair(-50, 31), Pair(-4, 14), Pair(12, 20), Pair(-32, -2), Pair(-79, 16), Pair(-83, -43),
      Pair(-9, 26), Pair(7, 37), Pair(16, 35), Pair(29, 33), Pair(25, 23), Pair(60, 16), Pair(20, 28), Pair(14, 8),
      Pair(13, 27), Pair(26, 36), Pair(28, 50), Pair(40, 45), Pair(51, 40), Pair(81, 16), Pair(21, 29), Pair(36, 11),
      Pair(25, 38), Pair(24, 42), Pair(44, 50), Pair(56, 51), Pair(46, 50), Pair(54, 48), Pair(33, 39), Pair(50, 25),
      Pair(13, 41), Pair(27, 40), Pair(38, 56), Pair(42, 55), Pair(43, 60), Pair(53, 41), Pair(42, 37), Pair(28, 34),
      Pair(-8, 29), Pair(14, 34), Pair(20, 43), Pair(32, 54), Pair(43, 51), Pair(29, 36), Pair(32, 28), Pair(15, 32),
      Pair(-13, 27), Pair(0, 35), Pair(10, 37), Pair(24, 37), Pair(27, 35), Pair(20, 33), Pair(19, 23), Pair(17, 36),
      Pair(-45, 32), Pair(-8, 25), Pair(-8, 32), Pair(6, 40), Pair(13, 37), Pair(17, 24), Pair(-3, 30), Pair(-7, 22)
  },
  {
      Pair(-52, 31), Pair(-67, 31), Pair(-70, 25), Pair(-99, 32), Pair(-99, 31), Pair(-96, 22), Pair(-56, 23), Pair(-81, 19),
      Pair(-37, 13), Pair(-29, 26), Pair(-27, 23), Pair(-39, 28), Pair(-40, 23), Pair(-27, 21), Pair(-51, 30), Pair(-48, 15),
      Pair(-22, 28), Pair(-13, 26), Pair(-19, 32), Pair(-17, 24), Pair(-23, 28), Pair(15, 32), Pair(2, 28), Pair(-8, 28),
      Pair(-34, 28), Pair(-23, 31), Pair(-17, 32), Pair(-3, 38), Pair(-6, 32), Pair(-11, 35), Pair(-26, 28), Pair(-32, 26),
      Pair(-28, 22), Pair(-36, 33), Pair(-21, 32), Pair(-4, 32), Pair(-4, 27), Pair(-21, 31), Pair(-28, 30), Pair(-14, 12),
      Pair(-33, 22), Pair(-13, 30), Pair(-13, 33), Pair(-14, 37), Pair(-14, 41), Pair(-10, 32), Pair(-9, 24), Pair(-14, 14),
      Pair(-19, 23), Pair(-14, 12), Pair(-5, 16), Pair(-22, 29), Pair(-11, 27), Pair(-5, 21), Pair(6, 17), Pair(-5, 6),
      Pair(-28, 11), Pair(-9, 30), Pair(-30, 23), Pair(-30, 26), Pair(-20, 23), Pair(-29, 30), Pair(-17, 16), Pair(-1, -8)
  },
  {
      Pair(-11, 2), Pair(-10, 11), Pair(-4, 13), Pair(-9, 12), Pair(3, 0), Pair(20, 2), Pair(8, 5), Pair(-14, 2),
      Pair(-7, -4), Pair(-4, 8), Pair(10, 6), Pair(27, -4), Pair(11, -7), Pair(31, -5), Pair(26, -7), Pair(3, -10),
      Pair(-12, -3), Pair(15, -2), Pair(13, -3), Pair(9, -5), Pair(36, -18), Pair(47, -21), Pair(61, -21), Pair(10, -22),
      Pair(-14, -2), Pair(1, 0), Pair(3, 2), Pair(7, -3), Pair(10, -18), Pair(14, -17), Pair(13, -14), Pair(-7, -19),
      Pair(-18, -10), Pair(-18, 0), Pair(-7, -5), Pair(-3, -5), Pair(0, -13), Pair(-19, -5), Pair(4, -17), Pair(-15, -24),
      Pair(-21, -14), Pair(-16, -10), Pair(-9, -12), Pair(-8, -9), Pair(1, -19), Pair(-1, -20), Pair(22, -37), Pair(0, -40),
      Pair(-20, -22), Pair(-12, -12), Pair(1, -14), Pair(0, -14), Pair(6, -25), Pair(3, -24), Pair(13, -33), Pair(-18, -36),
      Pair(-8, -18), Pair(-2, -16), Pair(3, -12), Pair(8, -17), Pair(14, -26), Pair(6, -22), Pair(1, -24), Pair(-7, -34)
  },
  {
      Pair(-41, -1), Pair(-39, -1), Pair(-29, 19), Pair(-4, 8), Pair(-17, 17), Pair(-13, 16), Pair(34, -42), Pair(-14, -5),
      Pair(-4, -18), Pair(-15, 2), Pair(-20, 37), Pair(-34, 51), Pair(-54, 76), Pair(-12, 36), Pair(-7, 16), Pair(31, 0),
      Pair(0, -14), Pair(-2, -1), Pair(-6, 29), Pair(-3, 30), Pair(-6, 44), Pair(21, 22), Pair(20, -1), Pair(18, -5),
      Pair(-9, -5), Pair(-4, 14), Pair(-4, 25), Pair(-6, 39), Pair(-6, 38), Pair(3, 20), Pair(11, 15), Pair(8, -1),
      Pair(-3, -10), Pair(-9, 26), Pair(-4, 26), Pair(0, 40), Pair(5, 30), Pair(-2, 20), Pair(11, 6), Pair(9, -4),
      Pair(-2, -20), Pair(1, 4), Pair(1, 19), Pair(-1, 20), Pair(1, 23), Pair(6, 12), Pair(20, -8), Pair(12, -22),
      Pair(3, -27), Pair(5, -22), Pair(9, -17), Pair(13, -10), Pair(12, -8), Pair(19, -34), Pair(25, -56), Pair(31, -77),
      Pair(-7, -19), Pair(0, -24), Pair(2, -14), Pair(4, -7), Pair(11, -30), Pair(0, -38), Pair(3, -46), Pair(5, -45)
  },
  {
      Pair(80, -109), Pair(93, -67), Pair(69, -45), Pair(-39, -8), Pair(-18, -23), Pair(-79, -7), Pair(-17, -24), Pair(119, -134),
      Pair(-87, -11), Pair(-3, 11), Pair(-22, 16), Pair(71, -1), Pair(-3, 12), Pair(-31, 32), Pair(-28, 24), Pair(-94, 0),
      Pair(-76, -10), Pair(68, 0), Pair(11, 15), Pair(-28, 30), Pair(9, 26), Pair(65, 14), Pair(-21, 21), Pair(-47, -12),
      Pair(-41, -27), Pair(10, -11), Pair(-28, 11), Pair(-74, 27), Pair(-78, 22), Pair(-52, 15), Pair(-39, -5), Pair(-136, -9),
      Pair(-41, -43), Pair(8, -23), Pair(-39, 3), Pair(-82, 23), Pair(-78, 16), Pair(-42, -2), Pair(-42, -18), Pair(-117, -25),
      Pair(-21, -47), Pair(27, -30), Pair(-23, -7), Pair(-39, 9), Pair(-35, 4), Pair(-33, -8), Pair(-7, -29), Pair(-41, -41),
      Pair(33, -58), Pair(7, -26), Pair(4, -16), Pair(-17, -5), Pair(-22, -6), Pair(-13, -15), Pair(6, -34), Pair(20, -60),
      Pair(18, -84), Pair(36, -56), Pair(23, -39), Pair(-38, -17), Pair(5, -41), Pair(-25, -27), Pair(19, -52), Pair(26, -93)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-32, 34), Pair(-19, 31), Pair(-9, 51), Pair(-3, 60), Pair(3, 67), Pair(8, 74), Pair(14, 73), Pair(19, 71),
  Pair(22, 64)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-36, -19), Pair(-27, -20), Pair(-19, -5), Pair(-14, 5), Pair(-8, 12), Pair(-6, 20), Pair(-4, 23), Pair(-4, 26),
  Pair(-2, 28), Pair(2, 26), Pair(9, 23), Pair(14, 22), Pair(11, 35), Pair(19, 17)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-22, -48), Pair(-14, -23), Pair(-11, -18), Pair(-9, -12), Pair(-12, -6), Pair(-8, -4), Pair(-8, 2), Pair(-7, 4),
  Pair(-6, 7), Pair(-5, 10), Pair(-2, 11), Pair(-4, 15), Pair(-3, 16), Pair(-1, 15), Pair(-4, 13)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(1, -200), Pair(4, -187), Pair(-6, -66), Pair(-4, -25), Pair(-4, -3), Pair(-1, 9), Pair(0, 24), Pair(1, 36),
  Pair(3, 41), Pair(5, 43), Pair(6, 47), Pair(8, 50), Pair(10, 49), Pair(10, 51), Pair(12, 50), Pair(14, 48),
  Pair(14, 51), Pair(16, 46), Pair(26, 35), Pair(39, 21), Pair(42, 15), Pair(88, -20), Pair(77, -20), Pair(100, -50),
  Pair(181, -83), Pair(204, -128), Pair(144, -91), Pair(95, -90)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(3, 16), Pair(2, 30), Pair(4, 62), Pair(30, 97), Pair(27, 165), Pair(38, 52), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 1), Pair(15, 7), Pair(21, 18), Pair(47, 59), Pair(123, 189), Pair(-226, 476), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(15, 6), Pair(14, 13), Pair(21, 40), Pair(149, 32), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -46), Pair(10, -37), Pair(1, -25), Pair(-1, -13), Pair(-10, -6), Pair(-8, -20), Pair(8, -32), Pair(-5, -49)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-6, 12), Pair(-2, -12), Pair(-11, -5), Pair(-8, -11), Pair(-11, -14), Pair(-5, -6), Pair(1, -13), Pair(-4, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 6), Pair(25, 2), Pair(21, 8), Pair(23, 7), Pair(24, 12), Pair(37, 3), Pair(46, 2), Pair(75, 0)
  },
  {
      Pair(6, 29), Pair(8, 6), Pair(8, 5), Pair(16, -4), Pair(11, -1), Pair(16, -5), Pair(24, -3), Pair(15, 17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -6), Pair(17, -6), Pair(9, -3),
  Pair(21, -11), Pair(16, -11), Pair(20, -11),
  Pair(30, -4), Pair(0, 0), Pair(27, -3),
  Pair(-10, 5), Pair(-15, 1), Pair(-9, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-13, 3), Pair(-9, 3),
  Pair(-6, 0), Pair(-15, 4), Pair(-10, 3),
  Pair(-1, -7), Pair(-12, 0), Pair(-2, -5),
  Pair(12, -8), Pair(-4, -5), Pair(10, -6),
  Pair(29, -8), Pair(24, 0), Pair(23, -8),
  Pair(0, 0), Pair(6, -31), Pair(0, 0),
  Pair(58, -49), Pair(0, 0), Pair(49, -46)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-23, 20), Pair(-25, 5), Pair(-16, -16), Pair(-13, -26), Pair(-9, -28), Pair(2, -30), Pair(-9, -33)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-79, -43), Pair(-3, -41), Pair(-6, -17), Pair(2, -10), Pair(5, -5), Pair(5, 1), Pair(-9, -3)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-220, 200);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-53, -14), Pair(-70, -6), Pair(-39, -8), Pair(-28, -9), Pair(-23, -2), Pair(-40, 1), Pair(-53, 4), Pair(-37, 6)
  },
  {
      Pair(-17, 47), Pair(-39, 20), Pair(-22, 13), Pair(-3, -5), Pair(-7, -6), Pair(-12, 5), Pair(-33, 23), Pair(-23, 35)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -2), Pair(27, -12), Pair(66, -35), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -1), Pair(31, -3), Pair(60, -11), Pair(66, -40), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -19), Pair(34, -22), Pair(56, -17), Pair(86, -21), Pair(100, -31), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 10), Pair(16, 19), Pair(39, 22), Pair(81, 6), Pair(110, 4), Pair(167, -14), Pair(227, -62)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(18, -5), Pair(32, 14), Pair(30, 20), Pair(54, 0), Pair(30, 12), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-13, 14), Pair(-62, -23), Pair(-63, -52), Pair(-83, -6), Pair(-76, 31), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -14), Pair(14, -3), Pair(-28, -37), Pair(-66, -15), Pair(-51, 29), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -17), Pair(-18, -26), Pair(7, -26), Pair(-49, -22), Pair(-64, -52), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(1, -22), Pair(-14, -25), Pair(-18, -30), Pair(12, -32), Pair(-79, -8), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(10, 22), Pair(11, 6), Pair(26, 16), Pair(37, 16), Pair(37, 23), Pair(21, 41), Pair(36, 12), Pair(-6, 34),
  Pair(-3, 8), Pair(13, 11), Pair(10, 15), Pair(-1, 29), Pair(6, 17), Pair(2, 18), Pair(12, 11), Pair(-7, 21),
  Pair(7, 6), Pair(0, -1), Pair(-3, 12), Pair(2, 13), Pair(1, 18), Pair(-11, 16), Pair(-4, 5), Pair(-3, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-15, 10), Pair(15, 2), Pair(20, 2), Pair(35, 1), Pair(56, -13), Pair(34, -2), Pair(21, -11), Pair(-16, -31),
  Pair(-26, -8), Pair(20, 6), Pair(8, 3), Pair(14, 12), Pair(8, 4), Pair(16, 0), Pair(13, 12), Pair(16, -22),
  Pair(-25, 29), Pair(6, 4), Pair(-1, 18), Pair(14, 11), Pair(17, 22), Pair(-1, 7), Pair(10, 0), Pair(-52, 9)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 58);

constexpr std::array<ScorePair, kNumFiles> kClosedPositionKnightBonus = {
  Pair(5, 15), Pair(7, 27), Pair(8, 41), Pair(10, 49), Pair(27, 53), Pair(44, 54), Pair(27, 33), Pair(11, 3)
};

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H