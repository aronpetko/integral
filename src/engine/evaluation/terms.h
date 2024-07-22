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
  Pair(74, 137), Pair(304, 336), Pair(326, 361), Pair(427, 615), Pair(871, 1085), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(42, 69), Pair(27, 71), Pair(13, 73), Pair(56, 29), Pair(47, 34), Pair(42, 44), Pair(-27, 88), Pair(-23, 83),
      Pair(6, 6), Pair(-12, 27), Pair(21, -16), Pair(28, -46), Pair(43, -48), Pair(65, -34), Pair(20, 12), Pair(5, 3),
      Pair(-18, -6), Pair(-18, 1), Pair(-12, -23), Pair(-6, -39), Pair(14, -41), Pair(7, -34), Pair(-11, -5), Pair(-7, -23),
      Pair(-23, -21), Pair(-27, -1), Pair(-14, -29), Pair(-2, -37), Pair(1, -37), Pair(1, -35), Pair(-15, -11), Pair(-11, -34),
      Pair(-33, -25), Pair(-37, -9), Pair(-25, -29), Pair(-19, -30), Pair(-13, -30), Pair(-17, -32), Pair(-18, -19), Pair(-16, -39),
      Pair(-25, -20), Pair(-28, -3), Pair(-19, -23), Pair(-21, -28), Pair(-12, -19), Pair(0, -28), Pair(-3, -16), Pair(-16, -37),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-134, -50), Pair(-103, -11), Pair(-72, 7), Pair(-25, -11), Pair(-6, -7), Pair(-47, -29), Pair(-99, -11), Pair(-98, -72),
      Pair(-28, 0), Pair(-11, 12), Pair(-2, 11), Pair(10, 9), Pair(6, -1), Pair(40, -7), Pair(2, 2), Pair(-5, -19),
      Pair(-6, 2), Pair(8, 12), Pair(9, 28), Pair(22, 22), Pair(32, 17), Pair(62, -7), Pair(2, 5), Pair(17, -15),
      Pair(6, 12), Pair(6, 17), Pair(25, 27), Pair(37, 26), Pair(28, 25), Pair(36, 23), Pair(15, 13), Pair(31, -1),
      Pair(-5, 15), Pair(10, 16), Pair(20, 33), Pair(25, 31), Pair(26, 35), Pair(35, 16), Pair(24, 12), Pair(9, 8),
      Pair(-26, 3), Pair(-5, 11), Pair(2, 19), Pair(15, 32), Pair(26, 28), Pair(12, 12), Pair(13, 5), Pair(-3, 7),
      Pair(-30, 3), Pair(-18, 11), Pair(-7, 14), Pair(6, 14), Pair(9, 12), Pair(3, 11), Pair(1, 0), Pair(-1, 12),
      Pair(-61, 6), Pair(-23, 4), Pair(-22, 9), Pair(-8, 15), Pair(0, 12), Pair(1, 0), Pair(-20, 9), Pair(-24, -1)
  },
  {
      Pair(-30, 14), Pair(-50, 14), Pair(-53, 8), Pair(-82, 14), Pair(-81, 14), Pair(-73, 3), Pair(-39, 6), Pair(-61, 2),
      Pair(-21, -3), Pair(-14, 9), Pair(-12, 5), Pair(-25, 10), Pair(-26, 5), Pair(-14, 4), Pair(-38, 13), Pair(-36, 0),
      Pair(-8, 12), Pair(1, 9), Pair(-7, 15), Pair(-4, 7), Pair(-11, 11), Pair(25, 15), Pair(13, 12), Pair(6, 12),
      Pair(-20, 11), Pair(-9, 14), Pair(-4, 15), Pair(8, 21), Pair(6, 15), Pair(0, 18), Pair(-12, 11), Pair(-17, 9),
      Pair(-12, 5), Pair(-23, 16), Pair(-8, 15), Pair(10, 15), Pair(9, 10), Pair(-8, 14), Pair(-15, 13), Pair(2, -5),
      Pair(-18, 5), Pair(3, 13), Pair(1, 15), Pair(-2, 20), Pair(0, 24), Pair(4, 15), Pair(6, 7), Pair(1, -3),
      Pair(-3, 6), Pair(1, -5), Pair(8, -1), Pair(-8, 12), Pair(3, 9), Pair(10, 3), Pair(21, 0), Pair(10, -11),
      Pair(-11, -5), Pair(8, 14), Pair(-13, 11), Pair(-13, 9), Pair(-2, 4), Pair(-13, 15), Pair(1, -2), Pair(16, -25)
  },
  {
      Pair(-23, 45), Pair(-25, 54), Pair(-22, 56), Pair(-27, 55), Pair(-15, 44), Pair(4, 46), Pair(-8, 48), Pair(-27, 45),
      Pair(-21, 39), Pair(-19, 51), Pair(-8, 50), Pair(9, 39), Pair(-7, 37), Pair(11, 40), Pair(10, 36), Pair(-11, 34),
      Pair(-24, 40), Pair(2, 41), Pair(-2, 41), Pair(-5, 38), Pair(20, 26), Pair(31, 24), Pair(43, 24), Pair(-3, 22),
      Pair(-25, 41), Pair(-12, 43), Pair(-9, 44), Pair(-9, 41), Pair(-5, 26), Pair(-3, 28), Pair(-3, 30), Pair(-20, 25),
      Pair(-30, 34), Pair(-29, 44), Pair(-20, 39), Pair(-17, 39), Pair(-15, 32), Pair(-34, 40), Pair(-10, 27), Pair(-29, 21),
      Pair(-32, 30), Pair(-27, 34), Pair(-21, 31), Pair(-22, 34), Pair(-13, 25), Pair(-15, 25), Pair(8, 8), Pair(-15, 5),
      Pair(-31, 23), Pair(-25, 31), Pair(-12, 29), Pair(-13, 29), Pair(-7, 19), Pair(-11, 22), Pair(0, 11), Pair(-31, 9),
      Pair(-21, 26), Pair(-16, 25), Pair(-12, 29), Pair(-8, 24), Pair(-2, 15), Pair(-9, 21), Pair(-13, 18), Pair(-21, 11)
  },
  {
      Pair(-41, 66), Pair(-42, 67), Pair(-31, 86), Pair(-6, 75), Pair(-19, 83), Pair(-14, 82), Pair(32, 26), Pair(-13, 61),
      Pair(-8, 52), Pair(-21, 73), Pair(-25, 106), Pair(-41, 120), Pair(-57, 143), Pair(-15, 103), Pair(-10, 84), Pair(26, 70),
      Pair(-6, 58), Pair(-8, 70), Pair(-14, 99), Pair(-12, 101), Pair(-13, 113), Pair(15, 91), Pair(16, 68), Pair(14, 65),
      Pair(-15, 67), Pair(-11, 85), Pair(-11, 94), Pair(-14, 109), Pair(-13, 107), Pair(-3, 89), Pair(6, 86), Pair(4, 70),
      Pair(-10, 62), Pair(-16, 97), Pair(-12, 96), Pair(-9, 111), Pair(-3, 101), Pair(-10, 92), Pair(6, 77), Pair(3, 70),
      Pair(-8, 51), Pair(-6, 76), Pair(-9, 91), Pair(-11, 93), Pair(-8, 96), Pair(-2, 82), Pair(13, 64), Pair(6, 50),
      Pair(-5, 45), Pair(-3, 50), Pair(1, 56), Pair(3, 66), Pair(3, 65), Pair(8, 39), Pair(16, 18), Pair(20, 2),
      Pair(-17, 52), Pair(-12, 47), Pair(-10, 54), Pair(-6, 54), Pair(-3, 42), Pair(-12, 35), Pair(-7, 26), Pair(-2, 27)
  },
  {
      Pair(75, -90), Pair(89, -47), Pair(65, -25), Pair(-42, 11), Pair(-18, -5), Pair(-89, 13), Pair(-28, -5), Pair(90, -110),
      Pair(-92, 7), Pair(-6, 31), Pair(-26, 37), Pair(66, 19), Pair(-7, 32), Pair(-35, 52), Pair(-34, 43), Pair(-100, 16),
      Pair(-80, 8), Pair(61, 21), Pair(8, 37), Pair(-31, 51), Pair(6, 48), Pair(61, 36), Pair(-27, 41), Pair(-53, 5),
      Pair(-47, -9), Pair(3, 10), Pair(-30, 32), Pair(-77, 51), Pair(-81, 46), Pair(-53, 36), Pair(-44, 15), Pair(-142, 8),
      Pair(-45, -25), Pair(1, -2), Pair(-43, 25), Pair(-84, 47), Pair(-81, 41), Pair(-45, 20), Pair(-48, 3), Pair(-121, -8),
      Pair(-29, -27), Pair(21, -9), Pair(-28, 16), Pair(-44, 31), Pair(-40, 26), Pair(-38, 15), Pair(-13, -8), Pair(-48, -24),
      Pair(27, -40), Pair(1, -5), Pair(-2, 5), Pair(-24, 16), Pair(-28, 16), Pair(-18, 5), Pair(0, -13), Pair(13, -42),
      Pair(14, -66), Pair(34, -39), Pair(23, -21), Pair(-40, 3), Pair(2, -21), Pair(-25, -9), Pair(17, -35), Pair(22, -75)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-30, -5), Pair(-17, -4), Pair(-7, 16), Pair(-2, 23), Pair(4, 29), Pair(9, 35), Pair(15, 33), Pair(20, 29),
  Pair(22, 21)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-28, -16), Pair(-18, -19), Pair(-10, -3), Pair(-4, 7), Pair(2, 14), Pair(5, 23), Pair(6, 26), Pair(7, 29),
  Pair(9, 32), Pair(14, 30), Pair(21, 26), Pair(28, 27), Pair(25, 40), Pair(33, 21)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-30, -29), Pair(-20, -2), Pair(-16, 3), Pair(-17, 18), Pair(-17, 23), Pair(-13, 25), Pair(-12, 30), Pair(-11, 33),
  Pair(-8, 36), Pair(-6, 39), Pair(-3, 40), Pair(-2, 44), Pair(2, 46), Pair(6, 44), Pair(3, 42)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-70, -121), Pair(-15, -249), Pair(-24, -33), Pair(-17, 15), Pair(-17, 55), Pair(-16, 75), Pair(-13, 88), Pair(-13, 101),
  Pair(-11, 109), Pair(-9, 110), Pair(-7, 114), Pair(-7, 122), Pair(-4, 118), Pair(-4, 122), Pair(-2, 121), Pair(2, 118),
  Pair(1, 121), Pair(4, 117), Pair(13, 106), Pair(26, 92), Pair(32, 84), Pair(74, 52), Pair(69, 47), Pair(89, 20),
  Pair(132, 5), Pair(228, -73), Pair(142, -24), Pair(69, -10)
};

constexpr QueenMobilityTable<ScorePair> kKingVirtualMobility = {
  Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(2, 19), Pair(49, 101), Pair(4, 88), Pair(-29, 52), Pair(7, 43),
  Pair(0, 14), Pair(27, 7), Pair(-7, 24), Pair(-15, 7), Pair(-7, 4), Pair(-7, 1), Pair(-3, -5), Pair(-1, -5),
  Pair(0, -8), Pair(1, -11), Pair(1, -8), Pair(1, -10), Pair(-2, -10), Pair(-4, -12), Pair(-8, -8), Pair(-2, -14),
  Pair(-10, -10), Pair(-1, -18), Pair(51, -33), Pair(-5, -24)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-10, -72), Pair(-11, -58), Pair(-8, -26), Pair(18, 9), Pair(14, 76), Pair(33, 73), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(15, 7), Pair(21, 17), Pair(47, 60), Pair(126, 193), Pair(15, 380), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(14, 5), Pair(14, 13), Pair(22, 41), Pair(153, 34), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -45), Pair(10, -36), Pair(1, -25), Pair(-2, -13), Pair(-9, -6), Pair(-8, -19), Pair(9, -32), Pair(-5, -49)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-7, 12), Pair(-2, -11), Pair(-11, -4), Pair(-8, -11), Pair(-11, -14), Pair(-5, -6), Pair(0, -13), Pair(-5, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(24, 5), Pair(21, 1), Pair(17, 7), Pair(19, 6), Pair(21, 11), Pair(32, 1), Pair(40, 1), Pair(68, -1)
  },
  {
      Pair(2, 28), Pair(5, 6), Pair(5, 5), Pair(14, -4), Pair(9, -1), Pair(13, -6), Pair(20, -2), Pair(12, 16)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -6), Pair(17, -6), Pair(9, -3),
  Pair(21, -11), Pair(16, -11), Pair(19, -11),
  Pair(29, -4), Pair(0, 0), Pair(26, -3),
  Pair(-11, 5), Pair(-16, 1), Pair(-10, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, 1), Pair(-13, 2), Pair(-8, 3),
  Pair(-5, 1), Pair(-14, 4), Pair(-8, 3),
  Pair(0, -6), Pair(-11, -1), Pair(-1, -4),
  Pair(11, -5), Pair(-3, -6), Pair(9, -2),
  Pair(29, -6), Pair(25, 2), Pair(23, -6),
  Pair(0, 0), Pair(9, -27), Pair(0, 0),
  Pair(58, -48), Pair(0, 0), Pair(49, -45)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-7, 64), Pair(-9, 49), Pair(-1, 28), Pair(2, 18), Pair(6, 16), Pair(17, 14), Pair(7, 10)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-81, 2), Pair(-6, 5), Pair(-8, 27), Pair(0, 34), Pair(2, 40), Pair(2, 45), Pair(-11, 41)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-282, 198);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-54, -12), Pair(-70, -6), Pair(-40, -9), Pair(-28, -8), Pair(-23, -2), Pair(-39, 0), Pair(-53, 4), Pair(-35, 7)
  },
  {
      Pair(-17, 46), Pair(-39, 20), Pair(-23, 13), Pair(-2, -5), Pair(-6, -6), Pair(-12, 6), Pair(-32, 23), Pair(-22, 34)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -1), Pair(28, -10), Pair(67, -34), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 0), Pair(30, -3), Pair(60, -11), Pair(63, -40), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -18), Pair(34, -21), Pair(54, -16), Pair(79, -18), Pair(91, -28), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 12), Pair(12, 23), Pair(32, 29), Pair(76, 10), Pair(109, 8), Pair(166, -12), Pair(218, -54)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(32, 14), Pair(27, 21), Pair(53, 1), Pair(28, 13), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-13, 15), Pair(-62, -22), Pair(-63, -53), Pair(-84, -6), Pair(-76, 31), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -15), Pair(14, -1), Pair(-29, -37), Pair(-67, -14), Pair(-51, 27), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -17), Pair(-18, -26), Pair(9, -27), Pair(-49, -22), Pair(-64, -47), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(0, -22), Pair(-14, -26), Pair(-20, -30), Pair(23, -36), Pair(-77, -5), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(11, 23), Pair(13, 11), Pair(26, 21), Pair(35, 19), Pair(37, 27), Pair(21, 47), Pair(38, 16), Pair(-9, 38),
  Pair(-3, 13), Pair(12, 15), Pair(10, 20), Pair(-1, 33), Pair(6, 20), Pair(2, 22), Pair(12, 15), Pair(-7, 24),
  Pair(6, 7), Pair(0, 1), Pair(-3, 14), Pair(1, 14), Pair(1, 19), Pair(-12, 18), Pair(-3, 6), Pair(-3, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-12, 11), Pair(15, -1), Pair(21, 0), Pair(35, -1), Pair(59, -17), Pair(37, -4), Pair(23, -11), Pair(-16, -30),
  Pair(-24, -10), Pair(20, 5), Pair(8, 1), Pair(17, 10), Pair(9, 3), Pair(17, -2), Pair(13, 11), Pair(16, -22),
  Pair(-24, 28), Pair(6, 4), Pair(0, 17), Pair(13, 11), Pair(19, 20), Pair(0, 6), Pair(11, -1), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 59);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H