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
  Pair(81, 185), Pair(289, 278), Pair(353, 347), Pair(411, 690), Pair(851, 1224), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(48, 126), Pair(33, 129), Pair(20, 130), Pair(63, 86), Pair(52, 90), Pair(46, 102), Pair(-20, 145), Pair(-20, 141),
      Pair(0, -43), Pair(-19, -21), Pair(15, -66), Pair(22, -97), Pair(40, -100), Pair(60, -86), Pair(16, -38), Pair(2, -48),
      Pair(-25, -55), Pair(-26, -47), Pair(-18, -73), Pair(-11, -89), Pair(8, -90), Pair(2, -85), Pair(-17, -55), Pair(-13, -72),
      Pair(-30, -70), Pair(-34, -49), Pair(-21, -78), Pair(-9, -85), Pair(-6, -86), Pair(-5, -84), Pair(-21, -60), Pair(-17, -83),
      Pair(-40, -74), Pair(-44, -56), Pair(-33, -78), Pair(-26, -78), Pair(-20, -79), Pair(-23, -82), Pair(-24, -68), Pair(-23, -87),
      Pair(-31, -69), Pair(-35, -50), Pair(-26, -71), Pair(-28, -76), Pair(-19, -67), Pair(-6, -76), Pair(-10, -65), Pair(-22, -85),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-118, -27), Pair(-87, 13), Pair(-55, 31), Pair(-8, 12), Pair(10, 17), Pair(-30, -6), Pair(-83, 13), Pair(-81, -48),
      Pair(-12, 23), Pair(6, 35), Pair(14, 35), Pair(27, 33), Pair(23, 23), Pair(57, 17), Pair(19, 26), Pair(12, 4),
      Pair(11, 26), Pair(25, 36), Pair(26, 52), Pair(39, 45), Pair(49, 41), Pair(79, 17), Pair(19, 29), Pair(34, 8),
      Pair(23, 36), Pair(23, 41), Pair(42, 51), Pair(54, 50), Pair(45, 48), Pair(53, 47), Pair(32, 36), Pair(48, 22),
      Pair(11, 38), Pair(27, 39), Pair(37, 56), Pair(42, 55), Pair(42, 59), Pair(52, 40), Pair(41, 36), Pair(26, 32),
      Pair(-10, 27), Pair(12, 34), Pair(19, 43), Pair(32, 56), Pair(43, 52), Pair(28, 35), Pair(30, 28), Pair(14, 30),
      Pair(-14, 27), Pair(-1, 35), Pair(10, 38), Pair(22, 38), Pair(26, 35), Pair(19, 35), Pair(18, 24), Pair(15, 36),
      Pair(-44, 30), Pair(-7, 27), Pair(-5, 33), Pair(8, 38), Pair(16, 36), Pair(18, 24), Pair(-3, 32), Pair(-8, 23)
  },
  {
      Pair(-45, 31), Pair(-65, 32), Pair(-68, 26), Pair(-98, 32), Pair(-97, 32), Pair(-89, 21), Pair(-55, 24), Pair(-76, 20),
      Pair(-37, 15), Pair(-29, 27), Pair(-27, 23), Pair(-40, 28), Pair(-41, 23), Pair(-30, 22), Pair(-53, 31), Pair(-51, 17),
      Pair(-23, 30), Pair(-14, 26), Pair(-22, 33), Pair(-19, 25), Pair(-26, 29), Pair(10, 33), Pair(-2, 29), Pair(-9, 30),
      Pair(-35, 29), Pair(-24, 32), Pair(-19, 33), Pair(-7, 39), Pair(-9, 33), Pair(-15, 36), Pair(-27, 29), Pair(-33, 27),
      Pair(-27, 23), Pair(-38, 34), Pair(-23, 33), Pair(-5, 32), Pair(-6, 28), Pair(-23, 32), Pair(-31, 31), Pair(-13, 13),
      Pair(-33, 23), Pair(-12, 31), Pair(-14, 33), Pair(-17, 38), Pair(-15, 42), Pair(-11, 33), Pair(-9, 25), Pair(-14, 15),
      Pair(-18, 24), Pair(-14, 13), Pair(-7, 17), Pair(-23, 30), Pair(-12, 27), Pair(-5, 21), Pair(6, 18), Pair(-5, 7),
      Pair(-26, 13), Pair(-7, 32), Pair(-28, 29), Pair(-28, 27), Pair(-17, 23), Pair(-28, 33), Pair(-14, 16), Pair(1, -7)
  },
  {
      Pair(-9, 2), Pair(-10, 11), Pair(-7, 13), Pair(-12, 12), Pair(-1, 1), Pair(18, 4), Pair(7, 5), Pair(-12, 2),
      Pair(-7, -4), Pair(-5, 8), Pair(6, 7), Pair(23, -4), Pair(7, -6), Pair(25, -3), Pair(25, -7), Pair(4, -9),
      Pair(-9, -4), Pair(17, -2), Pair(13, -2), Pair(10, -5), Pair(34, -17), Pair(46, -19), Pair(58, -19), Pair(12, -21),
      Pair(-10, -2), Pair(3, 0), Pair(5, 2), Pair(6, -2), Pair(10, -17), Pair(12, -15), Pair(12, -13), Pair(-5, -18),
      Pair(-15, -9), Pair(-15, 1), Pair(-6, -4), Pair(-2, -5), Pair(-1, -11), Pair(-19, -3), Pair(5, -16), Pair(-14, -22),
      Pair(-18, -13), Pair(-12, -9), Pair(-7, -12), Pair(-7, -9), Pair(1, -18), Pair(-1, -18), Pair(23, -36), Pair(0, -38),
      Pair(-17, -20), Pair(-10, -12), Pair(2, -13), Pair(2, -14), Pair(8, -24), Pair(4, -22), Pair(15, -32), Pair(-16, -34),
      Pair(-6, -18), Pair(-2, -18), Pair(2, -14), Pair(7, -20), Pair(12, -28), Pair(6, -21), Pair(2, -25), Pair(-6, -32)
  },
  {
      Pair(-34, -5), Pair(-34, -4), Pair(-23, 15), Pair(2, 5), Pair(-11, 12), Pair(-7, 12), Pair(40, -45), Pair(-5, -10),
      Pair(0, -18), Pair(-13, 3), Pair(-18, 36), Pair(-33, 50), Pair(-50, 73), Pair(-8, 33), Pair(-3, 13), Pair(35, -1),
      Pair(2, -12), Pair(-1, -1), Pair(-6, 29), Pair(-4, 31), Pair(-6, 42), Pair(23, 21), Pair(24, -3), Pair(22, -5),
      Pair(-7, -3), Pair(-3, 14), Pair(-3, 24), Pair(-6, 38), Pair(-6, 37), Pair(5, 18), Pair(14, 15), Pair(12, -1),
      Pair(-2, -8), Pair(-9, 26), Pair(-4, 26), Pair(-1, 40), Pair(4, 30), Pair(-2, 21), Pair(14, 7), Pair(10, -1),
      Pair(-1, -20), Pair(2, 5), Pair(-1, 20), Pair(-3, 23), Pair(-1, 25), Pair(6, 12), Pair(21, -7), Pair(15, -21),
      Pair(3, -25), Pair(5, -21), Pair(9, -15), Pair(11, -5), Pair(11, -6), Pair(16, -32), Pair(24, -53), Pair(28, -69),
      Pair(-9, -18), Pair(-4, -24), Pair(-2, -16), Pair(2, -16), Pair(5, -28), Pair(-5, -35), Pair(0, -44), Pair(6, -44)
  },
  {
      Pair(80, -110), Pair(95, -68), Pair(69, -46), Pair(-39, -9), Pair(-16, -24), Pair(-82, -8), Pair(-21, -25), Pair(118, -135),
      Pair(-92, -12), Pair(-3, 10), Pair(-22, 15), Pair(71, -2), Pair(-4, 11), Pair(-31, 31), Pair(-30, 23), Pair(-99, -1),
      Pair(-76, -11), Pair(66, -1), Pair(11, 14), Pair(-28, 28), Pair(8, 25), Pair(64, 13), Pair(-24, 20), Pair(-49, -13),
      Pair(-43, -28), Pair(8, -12), Pair(-28, 10), Pair(-75, 26), Pair(-79, 21), Pair(-52, 14), Pair(-40, -6), Pair(-138, -10),
      Pair(-42, -44), Pair(6, -24), Pair(-40, 2), Pair(-82, 22), Pair(-78, 15), Pair(-43, -3), Pair(-43, -19), Pair(-119, -27),
      Pair(-25, -47), Pair(26, -31), Pair(-23, -8), Pair(-39, 7), Pair(-36, 3), Pair(-34, -9), Pair(-8, -30), Pair(-44, -42),
      Pair(31, -59), Pair(6, -27), Pair(3, -17), Pair(-19, -6), Pair(-24, -6), Pair(-13, -17), Pair(4, -35), Pair(17, -60),
      Pair(17, -85), Pair(38, -58), Pair(28, -41), Pair(-35, -18), Pair(7, -42), Pair(-21, -28), Pair(21, -54), Pair(26, -94)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-31, 31), Pair(-17, 32), Pair(-7, 52), Pair(-2, 60), Pair(4, 65), Pair(9, 71), Pair(16, 69), Pair(20, 66),
  Pair(23, 57)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-39, -18), Pair(-29, -21), Pair(-21, -6), Pair(-15, 4), Pair(-9, 12), Pair(-6, 20), Pair(-4, 23), Pair(-4, 27),
  Pair(-2, 29), Pair(3, 27), Pair(11, 24), Pair(17, 24), Pair(14, 37), Pair(22, 18)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-27, -57), Pair(-17, -31), Pair(-13, -25), Pair(-14, -10), Pair(-14, -6), Pair(-10, -3), Pair(-9, 1), Pair(-7, 5),
  Pair(-5, 8), Pair(-3, 11), Pair(1, 12), Pair(2, 16), Pair(5, 18), Pair(9, 16), Pair(6, 14)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-46, -215), Pair(-5, -264), Pair(-8, -97), Pair(-2, -49), Pair(-2, -8), Pair(-1, 11), Pair(2, 25), Pair(3, 37),
  Pair(4, 45), Pair(7, 46), Pair(8, 51), Pair(9, 58), Pair(12, 54), Pair(12, 58), Pair(14, 57), Pair(18, 54),
  Pair(16, 57), Pair(20, 53), Pair(28, 42), Pair(41, 28), Pair(48, 20), Pair(90, -12), Pair(85, -17), Pair(105, -44),
  Pair(157, -66), Pair(227, -128), Pair(158, -89), Pair(102, -85)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(3, 16), Pair(3, 30), Pair(4, 62), Pair(31, 98), Pair(27, 166), Pair(35, 55), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(15, 7), Pair(22, 17), Pair(47, 60), Pair(124, 190), Pair(-225, 480), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(14, 6), Pair(14, 13), Pair(22, 41), Pair(150, 32), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -46), Pair(11, -37), Pair(1, -26), Pair(-2, -14), Pair(-9, -6), Pair(-8, -19), Pair(9, -33), Pair(-5, -49)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-8, 13), Pair(-2, -12), Pair(-11, -4), Pair(-9, -11), Pair(-11, -14), Pair(-4, -6), Pair(1, -12), Pair(-6, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(25, 5), Pair(21, 1), Pair(18, 7), Pair(19, 6), Pair(21, 11), Pair(33, 2), Pair(41, 2), Pair(68, -1)
  },
  {
      Pair(3, 28), Pair(5, 6), Pair(6, 5), Pair(14, -4), Pair(9, -1), Pair(12, -6), Pair(19, -2), Pair(12, 16)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -6), Pair(17, -5), Pair(9, -3),
  Pair(21, -11), Pair(17, -11), Pair(19, -11),
  Pair(29, -4), Pair(0, 0), Pair(26, -3),
  Pair(-11, 5), Pair(-15, 1), Pair(-10, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-13, 3), Pair(-8, 3),
  Pair(-6, 1), Pair(-15, 5), Pair(-9, 3),
  Pair(0, -7), Pair(-12, 0), Pair(-1, -5),
  Pair(13, -9), Pair(-4, -5), Pair(11, -6),
  Pair(30, -8), Pair(25, 0), Pair(24, -8),
  Pair(0, 0), Pair(7, -31), Pair(0, 0),
  Pair(58, -49), Pair(0, 0), Pair(50, -46)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-23, 23), Pair(-25, 8), Pair(-16, -13), Pair(-14, -23), Pair(-9, -25), Pair(2, -27), Pair(-9, -30)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-79, -46), Pair(-4, -43), Pair(-6, -20), Pair(2, -13), Pair(5, -8), Pair(5, -3), Pair(-9, -6)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-237, 200);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-54, -13), Pair(-70, -6), Pair(-40, -8), Pair(-28, -8), Pair(-23, -2), Pair(-39, 1), Pair(-53, 4), Pair(-35, 6)
  },
  {
      Pair(-17, 47), Pair(-39, 21), Pair(-22, 13), Pair(-3, -5), Pair(-6, -7), Pair(-11, 5), Pair(-32, 24), Pair(-22, 35)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -1), Pair(28, -10), Pair(67, -35), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 0), Pair(30, -3), Pair(61, -11), Pair(63, -39), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -19), Pair(34, -21), Pair(54, -16), Pair(80, -19), Pair(91, -29), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 12), Pair(12, 24), Pair(32, 30), Pair(76, 11), Pair(109, 8), Pair(167, -12), Pair(224, -57)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(18, -5), Pair(32, 14), Pair(28, 21), Pair(53, 1), Pair(28, 13), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-14, 16), Pair(-62, -22), Pair(-63, -52), Pair(-84, -6), Pair(-76, 31), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -15), Pair(14, -1), Pair(-29, -37), Pair(-67, -14), Pair(-51, 27), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -17), Pair(-18, -26), Pair(8, -27), Pair(-49, -22), Pair(-64, -47), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(0, -22), Pair(-14, -27), Pair(-20, -30), Pair(23, -36), Pair(-77, -5), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(11, 23), Pair(13, 11), Pair(26, 21), Pair(36, 19), Pair(37, 26), Pair(22, 45), Pair(38, 16), Pair(-7, 37),
  Pair(-3, 13), Pair(12, 15), Pair(10, 20), Pair(-1, 33), Pair(6, 20), Pair(2, 22), Pair(12, 15), Pair(-7, 24),
  Pair(6, 7), Pair(0, 1), Pair(-3, 14), Pair(1, 14), Pair(1, 19), Pair(-12, 18), Pair(-4, 6), Pair(-3, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-12, 11), Pair(15, -1), Pair(21, 1), Pair(35, 0), Pair(58, -15), Pair(37, -4), Pair(22, -11), Pair(-15, -30),
  Pair(-24, -10), Pair(20, 5), Pair(8, 2), Pair(17, 10), Pair(9, 3), Pair(17, -2), Pair(13, 11), Pair(16, -22),
  Pair(-24, 29), Pair(6, 4), Pair(0, 17), Pair(13, 12), Pair(18, 21), Pair(0, 7), Pair(11, -1), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 59);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H