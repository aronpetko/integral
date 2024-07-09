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
  Pair(76, 178), Pair(294, 299), Pair(344, 348), Pair(414, 702), Pair(863, 1261), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(53, 136), Pair(37, 139), Pair(24, 140), Pair(67, 95), Pair(57, 99), Pair(52, 111), Pair(-15, 154), Pair(-13, 150),
      Pair(6, -35), Pair(-13, -14), Pair(18, -58), Pair(26, -89), Pair(41, -92), Pair(66, -79), Pair(21, -30), Pair(6, -40),
      Pair(-19, -47), Pair(-21, -39), Pair(-12, -65), Pair(-8, -81), Pair(14, -83), Pair(8, -78), Pair(-9, -47), Pair(-8, -64),
      Pair(-24, -61), Pair(-28, -42), Pair(-16, -69), Pair(-3, -77), Pair(0, -78), Pair(2, -77), Pair(-14, -52), Pair(-12, -75),
      Pair(-34, -65), Pair(-39, -48), Pair(-26, -70), Pair(-22, -69), Pair(-13, -70), Pair(-17, -73), Pair(-16, -59), Pair(-17, -80),
      Pair(-26, -60), Pair(-30, -42), Pair(-20, -62), Pair(-21, -69), Pair(-14, -58), Pair(3, -67), Pair(-2, -56), Pair(-19, -77),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-128, -32), Pair(-94, 10), Pair(-50, 27), Pair(-17, 11), Pair(-2, 16), Pair(-46, -6), Pair(-86, 10), Pair(-91, -52),
      Pair(-17, 19), Pair(0, 33), Pair(8, 33), Pair(18, 31), Pair(10, 21), Pair(46, 13), Pair(9, 23), Pair(9, -1),
      Pair(7, 22), Pair(18, 33), Pair(30, 49), Pair(27, 45), Pair(35, 39), Pair(69, 17), Pair(13, 27), Pair(30, 5),
      Pair(18, 32), Pair(22, 36), Pair(36, 48), Pair(59, 47), Pair(33, 47), Pair(53, 46), Pair(20, 35), Pair(44, 18),
      Pair(7, 35), Pair(22, 36), Pair(32, 53), Pair(36, 53), Pair(39, 56), Pair(46, 38), Pair(42, 32), Pair(21, 29),
      Pair(-14, 23), Pair(8, 31), Pair(15, 40), Pair(26, 53), Pair(39, 50), Pair(23, 34), Pair(27, 25), Pair(9, 26),
      Pair(-18, 23), Pair(-6, 31), Pair(5, 35), Pair(20, 34), Pair(22, 33), Pair(19, 31), Pair(16, 22), Pair(11, 33),
      Pair(-50, 25), Pair(-14, 19), Pair(-13, 29), Pair(1, 35), Pair(9, 34), Pair(13, 23), Pair(-10, 25), Pair(-13, 18)
  },
  {
      Pair(-46, 33), Pair(-67, 33), Pair(-69, 27), Pair(-103, 34), Pair(-103, 33), Pair(-97, 23), Pair(-53, 24), Pair(-80, 22),
      Pair(-34, 16), Pair(-26, 28), Pair(-27, 25), Pair(-37, 29), Pair(-40, 25), Pair(-27, 23), Pair(-54, 33), Pair(-46, 18),
      Pair(-21, 32), Pair(-11, 27), Pair(-18, 34), Pair(-16, 26), Pair(-23, 31), Pair(15, 33), Pair(1, 31), Pair(-6, 32),
      Pair(-33, 30), Pair(-21, 34), Pair(-15, 34), Pair(0, 39), Pair(-4, 34), Pair(-7, 37), Pair(-24, 30), Pair(-30, 29),
      Pair(-25, 25), Pair(-35, 36), Pair(-18, 35), Pair(0, 34), Pair(0, 29), Pair(-19, 34), Pair(-23, 33), Pair(-11, 14),
      Pair(-31, 25), Pair(-9, 34), Pair(-10, 35), Pair(-11, 40), Pair(-9, 44), Pair(-6, 35), Pair(-6, 28), Pair(-9, 17),
      Pair(-15, 27), Pair(-11, 15), Pair(-2, 19), Pair(-18, 32), Pair(-7, 30), Pair(2, 23), Pair(10, 21), Pair(-3, 9),
      Pair(-26, 14), Pair(-5, 34), Pair(-26, 26), Pair(-26, 30), Pair(-18, 26), Pair(-25, 35), Pair(-13, 19), Pair(3, -6)
  },
  {
      Pair(-15, 3), Pair(-16, 13), Pair(-12, 16), Pair(-17, 14), Pair(-9, 4), Pair(13, 6), Pair(2, 7), Pair(-14, 3),
      Pair(-12, -3), Pair(-9, 9), Pair(3, 8), Pair(20, -3), Pair(5, -6), Pair(22, -4), Pair(22, -8), Pair(6, -11),
      Pair(-15, -3), Pair(12, -1), Pair(9, -1), Pair(8, -4), Pair(34, -18), Pair(47, -20), Pair(64, -22), Pair(16, -24),
      Pair(-17, -1), Pair(-3, 1), Pair(0, 3), Pair(2, -1), Pair(9, -17), Pair(12, -16), Pair(13, -14), Pair(-5, -19),
      Pair(-22, -9), Pair(-22, 1), Pair(-11, -4), Pair(-5, -4), Pair(-1, -12), Pair(-19, -5), Pair(4, -18), Pair(-15, -23),
      Pair(-24, -15), Pair(-18, -9), Pair(-11, -12), Pair(-10, -9), Pair(1, -19), Pair(-2, -20), Pair(22, -37), Pair(0, -41),
      Pair(-22, -22), Pair(-14, -13), Pair(-1, -14), Pair(0, -15), Pair(6, -25), Pair(7, -25), Pair(15, -34), Pair(-18, -37),
      Pair(-10, -18), Pair(-4, -16), Pair(2, -11), Pair(7, -17), Pair(14, -26), Pair(7, -20), Pair(2, -25), Pair(-7, -36)
  },
  {
      Pair(-41, -10), Pair(-45, 2), Pair(-28, 19), Pair(-8, 4), Pair(-18, 9), Pair(-13, 13), Pair(38, -43), Pair(-16, -12),
      Pair(-5, -18), Pair(-17, 10), Pair(-23, 43), Pair(-32, 59), Pair(-52, 79), Pair(-7, 29), Pair(-4, 21), Pair(39, -2),
      Pair(-3, -7), Pair(-4, 7), Pair(-3, 38), Pair(-4, 42), Pair(-9, 54), Pair(22, 29), Pair(23, 6), Pair(13, -3),
      Pair(-13, 4), Pair(-6, 20), Pair(-5, 27), Pair(-10, 48), Pair(-7, 47), Pair(1, 28), Pair(9, 23), Pair(5, 4),
      Pair(-8, -6), Pair(-13, 24), Pair(-7, 21), Pair(-2, 36), Pair(3, 33), Pair(-5, 23), Pair(9, 9), Pair(6, -2),
      Pair(-7, -22), Pair(-3, 0), Pair(-2, 10), Pair(-5, 15), Pair(-1, 21), Pair(2, 14), Pair(16, -7), Pair(10, -22),
      Pair(-1, -33), Pair(0, -28), Pair(6, -22), Pair(11, -16), Pair(9, -10), Pair(19, -38), Pair(22, -56), Pair(26, -80),
      Pair(-10, -33), Pair(-3, -32), Pair(-2, -20), Pair(0, -10), Pair(6, -27), Pair(-4, -38), Pair(0, -50), Pair(4, -58)
  },
  {
      Pair(68, -98), Pair(89, -55), Pair(54, -34), Pair(-65, 4), Pair(-49, -10), Pair(-65, 1), Pair(12, -17), Pair(137, -126),
      Pair(-78, -3), Pair(-1, 21), Pair(-38, 28), Pair(56, 9), Pair(-18, 24), Pair(-32, 42), Pair(-13, 33), Pair(-67, 7),
      Pair(-87, 0), Pair(62, 10), Pair(-15, 27), Pair(-50, 40), Pair(-24, 39), Pair(48, 24), Pair(-18, 29), Pair(-52, -2),
      Pair(-52, -17), Pair(0, -1), Pair(-54, 22), Pair(-105, 38), Pair(-110, 33), Pair(-74, 25), Pair(-52, 5), Pair(-137, -1),
      Pair(-48, -35), Pair(-7, -14), Pair(-62, 14), Pair(-103, 32), Pair(-103, 27), Pair(-58, 7), Pair(-51, -9), Pair(-124, -16),
      Pair(-19, -38), Pair(27, -22), Pair(-31, 2), Pair(-47, 17), Pair(-46, 13), Pair(-40, 0), Pair(-8, -21), Pair(-39, -32),
      Pair(42, -50), Pair(13, -19), Pair(5, -9), Pair(-17, 2), Pair(-22, 2), Pair(-10, -9), Pair(12, -26), Pair(27, -50),
      Pair(29, -77), Pair(46, -49), Pair(32, -33), Pair(-29, -13), Pair(15, -37), Pair(-18, -22), Pair(29, -46), Pair(40, -86)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-34, 19), Pair(-20, 19), Pair(-10, 39), Pair(-4, 47), Pair(2, 53), Pair(8, 60), Pair(14, 58), Pair(19, 56),
  Pair(22, 47)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-33, -18), Pair(-23, -20), Pair(-14, -4), Pair(-9, 6), Pair(-2, 14), Pair(0, 24), Pair(2, 27), Pair(3, 32),
  Pair(5, 35), Pair(9, 34), Pair(17, 30), Pair(23, 32), Pair(19, 45), Pair(29, 26)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-24, -54), Pair(-16, -27), Pair(-13, -22), Pair(-11, -16), Pair(-14, -9), Pair(-9, -5), Pair(-9, 1), Pair(-8, 3),
  Pair(-7, 6), Pair(-5, 9), Pair(-1, 11), Pair(-2, 16), Pair(1, 17), Pair(2, 15), Pair(-3, 15)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(0, -228), Pair(2, -211), Pair(-8, -87), Pair(-6, -45), Pair(-5, -22), Pair(-2, -10), Pair(0, 7), Pair(1, 18),
  Pair(4, 25), Pair(6, 28), Pair(7, 33), Pair(10, 38), Pair(11, 38), Pair(11, 43), Pair(13, 44), Pair(16, 45),
  Pair(15, 52), Pair(16, 50), Pair(25, 45), Pair(37, 34), Pair(40, 33), Pair(85, 3), Pair(71, 9), Pair(88, -13),
  Pair(186, -52), Pair(207, -90), Pair(150, -49), Pair(103, -42)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(2, 11), Pair(0, 26), Pair(0, 58), Pair(27, 94), Pair(23, 161), Pair(32, 50), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 0), Pair(16, 7), Pair(22, 18), Pair(47, 60), Pair(116, 193), Pair(-199, 464), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(22, 10), Pair(15, 5), Pair(15, 13), Pair(22, 41), Pair(79, 56), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -47), Pair(11, -37), Pair(2, -26), Pair(-1, -13), Pair(-9, -5), Pair(-9, -19), Pair(7, -33), Pair(-3, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-7, 12), Pair(-2, -11), Pair(-12, -4), Pair(-8, -12), Pair(-11, -14), Pair(-4, -6), Pair(1, -13), Pair(-6, 9)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 8), Pair(25, 3), Pair(21, 9), Pair(23, 8), Pair(24, 13), Pair(37, 4), Pair(46, 3), Pair(74, 2)
  },
  {
      Pair(5, 28), Pair(9, 5), Pair(8, 4), Pair(16, -5), Pair(12, -2), Pair(17, -6), Pair(25, -2), Pair(14, 17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -6), Pair(17, -4), Pair(9, -3),
  Pair(25, -10), Pair(19, -9), Pair(24, -11),
  Pair(33, -2), Pair(0, 0), Pair(30, -2),
  Pair(-7, 5), Pair(-19, 3), Pair(-6, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-14, 3), Pair(-9, 3),
  Pair(-6, 1), Pair(-15, 5), Pair(-9, 3),
  Pair(-1, -7), Pair(-13, -1), Pair(-1, -5),
  Pair(13, -9), Pair(-5, -5), Pair(12, -7),
  Pair(31, -9), Pair(22, -1), Pair(24, -9),
  Pair(0, 0), Pair(0, -31), Pair(0, 0),
  Pair(51, -50), Pair(0, 0), Pair(46, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-21, 18), Pair(-26, 3), Pair(-18, -18), Pair(-15, -28), Pair(-10, -30), Pair(4, -32), Pair(-7, -36)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-73, -37), Pair(-1, -35), Pair(-1, -11), Pair(8, -4), Pair(9, 1), Pair(6, 7), Pair(-10, 3)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-80, 201);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-84, -10), Pair(-93, -3), Pair(-56, -7), Pair(-49, -5), Pair(-37, -1), Pair(-63, 4), Pair(-64, 5), Pair(-51, 8)
  },
  {
      Pair(-25, 51), Pair(-42, 21), Pair(-23, 14), Pair(-5, -3), Pair(-7, -6), Pair(-14, 7), Pair(-33, 24), Pair(-30, 37)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(17, 1), Pair(35, -9), Pair(86, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -2), Pair(30, -6), Pair(59, -17), Pair(64, -45), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -22), Pair(33, -24), Pair(57, -20), Pair(92, -27), Pair(107, -40), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 8), Pair(15, 22), Pair(39, 29), Pair(87, 16), Pair(127, 18), Pair(212, -25), Pair(284, -73)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-13, 15), Pair(-62, -22), Pair(-63, -53), Pair(-83, -7), Pair(-77, 35), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -15), Pair(11, 0), Pair(-32, -37), Pair(-68, -15), Pair(-54, 26), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -18), Pair(-19, -27), Pair(6, -27), Pair(-49, -23), Pair(-65, -52), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(0, -24), Pair(-15, -27), Pair(-19, -30), Pair(0, -31), Pair(-76, -10), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(8, 24), Pair(13, 11), Pair(27, 19), Pair(37, 19), Pair(37, 26), Pair(20, 48), Pair(35, 16), Pair(-9, 36),
  Pair(-2, 13), Pair(11, 16), Pair(11, 20), Pair(1, 32), Pair(7, 20), Pair(3, 21), Pair(13, 16), Pair(-7, 25),
  Pair(7, 8), Pair(0, 2), Pair(-3, 14), Pair(2, 14), Pair(1, 20), Pair(-12, 17), Pair(-5, 7), Pair(-3, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-15, 11), Pair(15, -1), Pair(19, 2), Pair(34, 0), Pair(56, -14), Pair(33, -2), Pair(20, -11), Pair(-18, -31),
  Pair(-23, -11), Pair(19, 5), Pair(7, 2), Pair(14, 12), Pair(8, 3), Pair(15, -2), Pair(14, 11), Pair(12, -23),
  Pair(-25, 28), Pair(6, 5), Pair(-1, 18), Pair(14, 12), Pair(18, 22), Pair(-1, 6), Pair(10, -1), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 61);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H