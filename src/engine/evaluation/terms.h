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
  Pair(81, 185), Pair(287, 281), Pair(354, 349), Pair(409, 692), Pair(853, 1232), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(49, 127), Pair(35, 130), Pair(21, 131), Pair(63, 87), Pair(54, 91), Pair(48, 103), Pair(-18, 144), Pair(-18, 141),
      Pair(1, -43), Pair(-19, -22), Pair(15, -67), Pair(22, -97), Pair(39, -100), Pair(61, -87), Pair(17, -40), Pair(2, -48),
      Pair(-24, -55), Pair(-25, -48), Pair(-18, -73), Pair(-11, -90), Pair(9, -91), Pair(4, -85), Pair(-15, -56), Pair(-13, -72),
      Pair(-29, -69), Pair(-34, -50), Pair(-21, -78), Pair(-9, -85), Pair(-6, -86), Pair(-5, -85), Pair(-21, -61), Pair(-17, -83),
      Pair(-40, -73), Pair(-44, -57), Pair(-33, -78), Pair(-27, -78), Pair(-20, -79), Pair(-23, -82), Pair(-23, -69), Pair(-23, -88),
      Pair(-32, -68), Pair(-36, -52), Pair(-26, -71), Pair(-29, -76), Pair(-20, -67), Pair(-7, -77), Pair(-10, -66), Pair(-22, -86),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-120, -18), Pair(-87, 19), Pair(-51, 33), Pair(-4, 17), Pair(11, 23), Pair(-32, 1), Pair(-79, 20), Pair(-84, -37),
      Pair(-10, 29), Pair(7, 40), Pair(16, 37), Pair(29, 35), Pair(26, 25), Pair(60, 19), Pair(20, 31), Pair(14, 11),
      Pair(12, 29), Pair(25, 36), Pair(28, 49), Pair(40, 45), Pair(50, 40), Pair(80, 16), Pair(20, 31), Pair(35, 14),
      Pair(24, 40), Pair(24, 43), Pair(44, 50), Pair(56, 51), Pair(46, 51), Pair(54, 48), Pair(33, 41), Pair(49, 27),
      Pair(13, 42), Pair(27, 41), Pair(38, 55), Pair(42, 56), Pair(44, 59), Pair(53, 41), Pair(41, 40), Pair(27, 36),
      Pair(-8, 29), Pair(14, 33), Pair(20, 41), Pair(32, 52), Pair(44, 50), Pair(29, 33), Pair(32, 27), Pair(15, 32),
      Pair(-13, 28), Pair(0, 36), Pair(11, 37), Pair(24, 37), Pair(27, 35), Pair(20, 34), Pair(19, 25), Pair(17, 37),
      Pair(-44, 35), Pair(-8, 26), Pair(-8, 34), Pair(6, 41), Pair(13, 39), Pair(17, 26), Pair(-3, 31), Pair(-8, 26)
  },
  {
      Pair(-53, 30), Pair(-68, 31), Pair(-70, 25), Pair(-100, 32), Pair(-100, 31), Pair(-97, 22), Pair(-55, 22), Pair(-82, 19),
      Pair(-38, 12), Pair(-30, 26), Pair(-28, 23), Pair(-40, 28), Pair(-41, 23), Pair(-28, 21), Pair(-53, 30), Pair(-49, 14),
      Pair(-23, 29), Pair(-14, 26), Pair(-20, 33), Pair(-18, 25), Pair(-23, 29), Pair(14, 33), Pair(1, 28), Pair(-9, 29),
      Pair(-35, 28), Pair(-24, 32), Pair(-19, 33), Pair(-4, 39), Pair(-7, 33), Pair(-12, 36), Pair(-27, 29), Pair(-33, 26),
      Pair(-29, 22), Pair(-37, 34), Pair(-22, 33), Pair(-5, 33), Pair(-5, 28), Pair(-22, 33), Pair(-29, 31), Pair(-15, 12),
      Pair(-34, 24), Pair(-14, 31), Pair(-14, 34), Pair(-15, 38), Pair(-15, 41), Pair(-11, 33), Pair(-10, 25), Pair(-15, 15),
      Pair(-19, 23), Pair(-15, 13), Pair(-6, 17), Pair(-23, 30), Pair(-12, 27), Pair(-6, 21), Pair(5, 17), Pair(-6, 7),
      Pair(-29, 11), Pair(-10, 30), Pair(-31, 23), Pair(-31, 27), Pair(-22, 23), Pair(-30, 30), Pair(-18, 16), Pair(-2, -8)
  },
  {
      Pair(-12, 1), Pair(-10, 11), Pair(-5, 13), Pair(-10, 12), Pair(3, 0), Pair(20, 2), Pair(8, 5), Pair(-14, 2),
      Pair(-8, -4), Pair(-4, 8), Pair(9, 6), Pair(26, -5), Pair(11, -7), Pair(30, -5), Pair(26, -8), Pair(3, -10),
      Pair(-13, -4), Pair(15, -2), Pair(12, -3), Pair(8, -5), Pair(35, -19), Pair(47, -21), Pair(61, -21), Pair(10, -22),
      Pair(-14, -2), Pair(1, 0), Pair(3, 1), Pair(7, -3), Pair(10, -18), Pair(13, -17), Pair(13, -14), Pair(-7, -19),
      Pair(-19, -10), Pair(-18, 0), Pair(-7, -5), Pair(-3, -5), Pair(0, -13), Pair(-19, -6), Pair(4, -18), Pair(-15, -24),
      Pair(-22, -15), Pair(-15, -10), Pair(-9, -13), Pair(-9, -10), Pair(0, -19), Pair(-1, -21), Pair(22, -37), Pair(0, -41),
      Pair(-20, -22), Pair(-12, -13), Pair(0, -15), Pair(-1, -15), Pair(6, -25), Pair(3, -24), Pair(12, -33), Pair(-18, -37),
      Pair(-8, -18), Pair(-2, -16), Pair(3, -12), Pair(7, -17), Pair(14, -27), Pair(6, -22), Pair(1, -24), Pair(-8, -35)
  },
  {
      Pair(-42, -1), Pair(-40, -1), Pair(-29, 19), Pair(-5, 8), Pair(-17, 16), Pair(-14, 16), Pair(33, -42), Pair(-15, -5),
      Pair(-5, -18), Pair(-15, 2), Pair(-21, 37), Pair(-35, 51), Pair(-54, 76), Pair(-13, 36), Pair(-7, 15), Pair(30, -1),
      Pair(-1, -14), Pair(-3, -1), Pair(-7, 29), Pair(-4, 30), Pair(-7, 44), Pair(20, 22), Pair(19, -2), Pair(17, -5),
      Pair(-10, -5), Pair(-4, 14), Pair(-4, 25), Pair(-7, 39), Pair(-7, 38), Pair(2, 20), Pair(11, 15), Pair(7, -1),
      Pair(-4, -11), Pair(-10, 26), Pair(-5, 26), Pair(-1, 41), Pair(4, 30), Pair(-2, 20), Pair(11, 5), Pair(8, -4),
      Pair(-3, -21), Pair(0, 3), Pair(0, 19), Pair(-2, 21), Pair(1, 22), Pair(6, 12), Pair(19, -8), Pair(11, -23),
      Pair(2, -27), Pair(5, -22), Pair(9, -17), Pair(13, -10), Pair(12, -9), Pair(19, -35), Pair(24, -56), Pair(30, -78),
      Pair(-8, -19), Pair(0, -24), Pair(2, -15), Pair(3, -7), Pair(10, -31), Pair(-1, -38), Pair(3, -47), Pair(4, -45)
  },
  {
      Pair(80, -109), Pair(93, -66), Pair(70, -45), Pair(-39, -8), Pair(-17, -23), Pair(-80, -7), Pair(-17, -24), Pair(119, -133),
      Pair(-87, -11), Pair(-2, 12), Pair(-22, 17), Pair(72, -1), Pair(-2, 12), Pair(-31, 32), Pair(-27, 24), Pair(-94, 0),
      Pair(-74, -9), Pair(68, 1), Pair(12, 16), Pair(-27, 30), Pair(11, 26), Pair(67, 14), Pair(-20, 21), Pair(-46, -12),
      Pair(-38, -27), Pair(10, -10), Pair(-27, 11), Pair(-74, 28), Pair(-76, 22), Pair(-51, 15), Pair(-38, -5), Pair(-135, -9),
      Pair(-39, -43), Pair(9, -22), Pair(-39, 3), Pair(-81, 23), Pair(-76, 17), Pair(-41, -2), Pair(-41, -17), Pair(-116, -25),
      Pair(-21, -46), Pair(28, -29), Pair(-21, -6), Pair(-37, 9), Pair(-35, 4), Pair(-32, -8), Pair(-6, -29), Pair(-40, -41),
      Pair(34, -57), Pair(8, -26), Pair(5, -16), Pair(-16, -5), Pair(-21, -5), Pair(-12, -15), Pair(7, -33), Pair(21, -59),
      Pair(19, -83), Pair(37, -56), Pair(25, -39), Pair(-37, -16), Pair(6, -41), Pair(-24, -27), Pair(20, -52), Pair(27, -92)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-33, 33), Pair(-19, 27), Pair(-9, 48), Pair(-3, 57), Pair(2, 65), Pair(7, 73), Pair(14, 73), Pair(18, 72),
  Pair(21, 67)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-37, -18), Pair(-27, -19), Pair(-19, -3), Pair(-14, 6), Pair(-9, 13), Pair(-6, 21), Pair(-5, 23), Pair(-4, 26),
  Pair(-3, 28), Pair(1, 26), Pair(9, 22), Pair(14, 21), Pair(11, 34), Pair(18, 15)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-20, -47), Pair(-12, -23), Pair(-9, -18), Pair(-7, -12), Pair(-10, -6), Pair(-6, -3), Pair(-6, 3), Pair(-5, 4),
  Pair(-4, 7), Pair(-3, 10), Pair(0, 11), Pair(-2, 15), Pair(-1, 16), Pair(1, 15), Pair(-1, 13)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(3, -200), Pair(5, -187), Pair(-4, -66), Pair(-2, -24), Pair(-2, -1), Pair(1, 10), Pair(2, 26), Pair(3, 37),
  Pair(5, 43), Pair(7, 45), Pair(8, 48), Pair(10, 51), Pair(12, 50), Pair(11, 52), Pair(13, 51), Pair(16, 49),
  Pair(16, 52), Pair(18, 46), Pair(28, 36), Pair(41, 21), Pair(44, 15), Pair(91, -20), Pair(80, -20), Pair(102, -50),
  Pair(183, -83), Pair(205, -128), Pair(144, -91), Pair(95, -89)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(3, 16), Pair(2, 30), Pair(4, 62), Pair(30, 97), Pair(27, 165), Pair(37, 53), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(15, 8), Pair(22, 18), Pair(47, 60), Pair(124, 189), Pair(-226, 477), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(15, 6), Pair(14, 13), Pair(22, 41), Pair(149, 32), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -46), Pair(10, -36), Pair(2, -24), Pair(-2, -14), Pair(-10, -5), Pair(-8, -19), Pair(8, -32), Pair(-5, -48)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-7, 12), Pair(-1, -11), Pair(-12, -4), Pair(-8, -12), Pair(-11, -14), Pair(-5, -6), Pair(1, -12), Pair(-5, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(31, 6), Pair(25, 2), Pair(22, 8), Pair(23, 7), Pair(24, 12), Pair(37, 3), Pair(46, 2), Pair(75, 0)
  },
  {
      Pair(6, 29), Pair(9, 6), Pair(9, 5), Pair(16, -4), Pair(11, 0), Pair(16, -5), Pair(24, -3), Pair(15, 17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -6), Pair(16, -6), Pair(9, -3),
  Pair(21, -11), Pair(16, -11), Pair(19, -11),
  Pair(30, -4), Pair(0, 0), Pair(27, -3),
  Pair(-10, 5), Pair(-15, 1), Pair(-9, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-13, 3), Pair(-9, 3),
  Pair(-6, 1), Pair(-15, 4), Pair(-9, 3),
  Pair(-1, -7), Pair(-11, 0), Pair(-2, -5),
  Pair(13, -8), Pair(-4, -5), Pair(10, -6),
  Pair(30, -8), Pair(24, 0), Pair(23, -8),
  Pair(0, 0), Pair(7, -31), Pair(0, 0),
  Pair(58, -49), Pair(0, 0), Pair(50, -46)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-23, 22), Pair(-25, 7), Pair(-16, -14), Pair(-13, -24), Pair(-9, -26), Pair(2, -28), Pair(-9, -31)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-79, -44), Pair(-3, -43), Pair(-6, -19), Pair(2, -12), Pair(5, -7), Pair(5, -1), Pair(-8, -5)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-220, 200);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-54, -13), Pair(-70, -6), Pair(-40, -8), Pair(-28, -9), Pair(-24, -1), Pair(-40, 1), Pair(-54, 4), Pair(-37, 7)
  },
  {
      Pair(-17, 47), Pair(-39, 20), Pair(-22, 12), Pair(-3, -4), Pair(-7, -7), Pair(-12, 5), Pair(-33, 23), Pair(-23, 35)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -2), Pair(28, -12), Pair(65, -36), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 0), Pair(31, -3), Pair(60, -11), Pair(66, -40), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -20), Pair(34, -23), Pair(56, -17), Pair(86, -21), Pair(100, -31), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 10), Pair(16, 19), Pair(39, 22), Pair(81, 6), Pair(110, 4), Pair(167, -15), Pair(228, -62)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(18, -5), Pair(32, 14), Pair(30, 19), Pair(54, 0), Pair(30, 12), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-13, 14), Pair(-62, -25), Pair(-63, -52), Pair(-83, -6), Pair(-76, 31), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -13), Pair(14, -3), Pair(-28, -37), Pair(-66, -14), Pair(-51, 28), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -17), Pair(-18, -26), Pair(7, -26), Pair(-49, -22), Pair(-64, -52), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(1, -23), Pair(-14, -25), Pair(-18, -31), Pair(12, -32), Pair(-79, -7), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(10, 22), Pair(12, 6), Pair(26, 16), Pair(37, 15), Pair(37, 23), Pair(22, 40), Pair(36, 12), Pair(-6, 34),
  Pair(-2, 6), Pair(13, 10), Pair(10, 14), Pair(-1, 28), Pair(6, 15), Pair(3, 16), Pair(12, 9), Pair(-7, 20),
  Pair(7, 5), Pair(1, -3), Pair(-3, 11), Pair(2, 11), Pair(1, 17), Pair(-11, 15), Pair(-3, 3), Pair(-3, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-15, 9), Pair(15, 1), Pair(20, 1), Pair(34, 1), Pair(55, -13), Pair(34, -2), Pair(21, -11), Pair(-16, -30),
  Pair(-25, -8), Pair(20, 5), Pair(8, 3), Pair(14, 12), Pair(8, 4), Pair(16, -1), Pair(13, 11), Pair(16, -23),
  Pair(-25, 30), Pair(5, 4), Pair(-1, 18), Pair(14, 11), Pair(17, 21), Pair(-1, 6), Pair(10, 0), Pair(-52, 9)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 60);

constexpr std::array<ScorePair, 9> kClosedPositionKnightBonus = {
  Pair(-2, -25), Pair(-3, -8), Pair(-2, 6), Pair(1, 15), Pair(5, 28), Pair(0, 0), Pair(0, 0), Pair(0, 0),
  Pair(0, 0)
};

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H