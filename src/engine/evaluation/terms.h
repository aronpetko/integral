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
  Pair(87, 181), Pair(294, 305), Pair(344, 350), Pair(411, 702), Pair(866, 1259), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(52, 136), Pair(33, 141), Pair(25, 142), Pair(66, 98), Pair(54, 101), Pair(50, 111), Pair(-20, 155), Pair(-17, 151),
      Pair(-2, -26), Pair(-17, -5), Pair(15, -47), Pair(20, -77), Pair(32, -79), Pair(62, -67), Pair(17, -20), Pair(-3, -32),
      Pair(-24, -42), Pair(-25, -34), Pair(-13, -59), Pair(-9, -76), Pair(11, -78), Pair(7, -73), Pair(-13, -42), Pair(-16, -60),
      Pair(-30, -59), Pair(-34, -41), Pair(-19, -67), Pair(-3, -75), Pair(-3, -76), Pair(0, -75), Pair(-19, -52), Pair(-16, -74),
      Pair(-31, -63), Pair(-28, -48), Pair(-17, -68), Pair(-12, -69), Pair(-2, -69), Pair(-7, -72), Pair(-5, -59), Pair(-13, -77),
      Pair(-31, -57), Pair(-30, -41), Pair(-23, -60), Pair(-24, -65), Pair(-14, -55), Pair(1, -66), Pair(-2, -54), Pair(-25, -75),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-126, -33), Pair(-94, 10), Pair(-49, 26), Pair(-17, 10), Pair(-2, 15), Pair(-46, -8), Pair(-84, 8), Pair(-90, -53),
      Pair(-15, 19), Pair(0, 33), Pair(8, 32), Pair(16, 30), Pair(11, 20), Pair(46, 13), Pair(9, 23), Pair(11, -1),
      Pair(6, 22), Pair(17, 33), Pair(25, 49), Pair(22, 45), Pair(31, 39), Pair(66, 17), Pair(13, 26), Pair(29, 5),
      Pair(18, 32), Pair(20, 37), Pair(33, 48), Pair(57, 46), Pair(30, 47), Pair(49, 46), Pair(16, 35), Pair(43, 18),
      Pair(8, 35), Pair(21, 35), Pair(30, 52), Pair(36, 51), Pair(39, 56), Pair(46, 37), Pair(40, 32), Pair(22, 28),
      Pair(-14, 23), Pair(7, 31), Pair(14, 38), Pair(25, 53), Pair(39, 49), Pair(22, 32), Pair(27, 25), Pair(10, 26),
      Pair(-18, 23), Pair(-6, 31), Pair(5, 34), Pair(21, 34), Pair(22, 33), Pair(20, 31), Pair(16, 21), Pair(12, 33),
      Pair(-48, 25), Pair(-13, 19), Pair(-13, 30), Pair(0, 35), Pair(8, 34), Pair(13, 23), Pair(-9, 25), Pair(-13, 18)
  },
  {
      Pair(-46, 32), Pair(-67, 32), Pair(-67, 26), Pair(-102, 33), Pair(-103, 32), Pair(-97, 22), Pair(-55, 24), Pair(-77, 21),
      Pair(-33, 15), Pair(-29, 27), Pair(-27, 24), Pair(-37, 27), Pair(-40, 23), Pair(-28, 21), Pair(-54, 31), Pair(-44, 17),
      Pair(-20, 31), Pair(-10, 26), Pair(-19, 32), Pair(-16, 24), Pair(-23, 29), Pair(14, 32), Pair(3, 29), Pair(-6, 31),
      Pair(-32, 29), Pair(-20, 33), Pair(-15, 32), Pair(-2, 38), Pair(-5, 32), Pair(-6, 35), Pair(-24, 29), Pair(-30, 28),
      Pair(-25, 24), Pair(-33, 34), Pair(-19, 33), Pair(0, 31), Pair(1, 26), Pair(-19, 33), Pair(-23, 32), Pair(-10, 13),
      Pair(-29, 24), Pair(-10, 32), Pair(-10, 33), Pair(-10, 39), Pair(-9, 42), Pair(-6, 34), Pair(-6, 26), Pair(-8, 16),
      Pair(-14, 27), Pair(-11, 14), Pair(-1, 18), Pair(-17, 30), Pair(-7, 29), Pair(3, 22), Pair(10, 20), Pair(-3, 9),
      Pair(-25, 14), Pair(-4, 33), Pair(-26, 25), Pair(-27, 30), Pair(-20, 26), Pair(-25, 34), Pair(-12, 17), Pair(3, -7)
  },
  {
      Pair(-13, 4), Pair(-15, 14), Pair(-11, 16), Pair(-16, 14), Pair(-9, 4), Pair(15, 6), Pair(4, 7), Pair(-12, 4),
      Pair(-11, -3), Pair(-12, 10), Pair(1, 7), Pair(16, -3), Pair(2, -6), Pair(20, -2), Pair(19, -6), Pair(6, -10),
      Pair(-16, -2), Pair(10, 0), Pair(7, -2), Pair(5, -4), Pair(31, -17), Pair(46, -20), Pair(62, -22), Pair(15, -24),
      Pair(-18, 0), Pair(-5, 1), Pair(-2, 3), Pair(0, 0), Pair(8, -17), Pair(11, -15), Pair(11, -14), Pair(-6, -17),
      Pair(-23, -8), Pair(-22, 1), Pair(-12, -4), Pair(-6, -3), Pair(-3, -11), Pair(-20, -4), Pair(1, -16), Pair(-16, -22),
      Pair(-24, -14), Pair(-18, -9), Pair(-11, -12), Pair(-11, -8), Pair(0, -19), Pair(-3, -19), Pair(21, -36), Pair(-1, -39),
      Pair(-23, -20), Pair(-14, -11), Pair(-1, -13), Pair(-1, -14), Pair(5, -24), Pair(8, -23), Pair(14, -33), Pair(-18, -36),
      Pair(-10, -16), Pair(-4, -14), Pair(2, -11), Pair(6, -16), Pair(13, -25), Pair(7, -19), Pair(1, -24), Pair(-7, -34)
  },
  {
      Pair(-40, -10), Pair(-44, 1), Pair(-28, 19), Pair(-8, 4), Pair(-17, 9), Pair(-11, 12), Pair(37, -43), Pair(-13, -13),
      Pair(-4, -18), Pair(-19, 12), Pair(-22, 43), Pair(-32, 59), Pair(-51, 79), Pair(-6, 30), Pair(-5, 23), Pair(41, -1),
      Pair(-2, -7), Pair(-5, 8), Pair(-5, 39), Pair(-4, 41), Pair(-11, 53), Pair(21, 29), Pair(25, 4), Pair(12, -2),
      Pair(-12, 4), Pair(-7, 20), Pair(-6, 27), Pair(-10, 47), Pair(-7, 46), Pair(2, 28), Pair(8, 24), Pair(6, 5),
      Pair(-8, -5), Pair(-12, 23), Pair(-7, 20), Pair(-2, 35), Pair(3, 32), Pair(-6, 23), Pair(9, 9), Pair(6, -1),
      Pair(-6, -21), Pair(-3, -1), Pair(-1, 9), Pair(-5, 15), Pair(0, 20), Pair(3, 13), Pair(16, -8), Pair(11, -21),
      Pair(-1, -33), Pair(1, -28), Pair(6, -21), Pair(11, -16), Pair(10, -10), Pair(20, -38), Pair(24, -57), Pair(28, -80),
      Pair(-10, -31), Pair(-3, -30), Pair(-1, -20), Pair(1, -11), Pair(7, -27), Pair(-3, -35), Pair(3, -50), Pair(4, -56)
  },
  {
      Pair(68, -96), Pair(87, -53), Pair(53, -31), Pair(-67, 7), Pair(-49, -7), Pair(-63, 2), Pair(14, -16), Pair(139, -122),
      Pair(-73, -1), Pair(2, 22), Pair(-34, 29), Pair(55, 12), Pair(-14, 25), Pair(-27, 44), Pair(-6, 33), Pair(-68, 8),
      Pair(-80, 1), Pair(68, 10), Pair(-12, 28), Pair(-47, 41), Pair(-23, 40), Pair(52, 25), Pair(-11, 30), Pair(-48, -1),
      Pair(-47, -17), Pair(2, 0), Pair(-52, 24), Pair(-106, 40), Pair(-108, 35), Pair(-71, 26), Pair(-51, 6), Pair(-131, 0),
      Pair(-45, -33), Pair(-5, -12), Pair(-62, 15), Pair(-102, 34), Pair(-102, 29), Pair(-59, 9), Pair(-52, -7), Pair(-122, -14),
      Pair(-19, -36), Pair(26, -20), Pair(-32, 4), Pair(-50, 19), Pair(-47, 15), Pair(-41, 2), Pair(-8, -20), Pair(-39, -30),
      Pair(39, -47), Pair(10, -17), Pair(2, -7), Pair(-20, 4), Pair(-26, 4), Pair(-14, -7), Pair(9, -25), Pair(25, -48),
      Pair(29, -75), Pair(44, -47), Pair(30, -31), Pair(-31, -10), Pair(13, -35), Pair(-20, -20), Pair(27, -44), Pair(39, -84)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-34, 14), Pair(-21, 14), Pair(-10, 34), Pair(-4, 42), Pair(3, 47), Pair(8, 55), Pair(16, 53), Pair(21, 50),
  Pair(24, 42)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-35, -20), Pair(-25, -23), Pair(-15, -6), Pair(-9, 5), Pair(-3, 13), Pair(0, 23), Pair(2, 27), Pair(3, 31),
  Pair(4, 35), Pair(8, 34), Pair(16, 31), Pair(22, 32), Pair(17, 47), Pair(28, 27)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-21, -55), Pair(-15, -27), Pair(-11, -22), Pair(-9, -17), Pair(-12, -10), Pair(-8, -6), Pair(-8, 0), Pair(-7, 2),
  Pair(-5, 6), Pair(-3, 10), Pair(0, 11), Pair(-1, 16), Pair(2, 17), Pair(4, 15), Pair(-2, 15)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(1, -233), Pair(2, -215), Pair(-9, -91), Pair(-7, -49), Pair(-6, -26), Pair(-3, -14), Pair(-1, 4), Pair(0, 16),
  Pair(3, 24), Pair(5, 26), Pair(7, 32), Pair(9, 37), Pair(11, 37), Pair(11, 42), Pair(13, 43), Pair(15, 45),
  Pair(14, 52), Pair(15, 50), Pair(24, 44), Pair(35, 34), Pair(38, 33), Pair(85, 2), Pair(70, 9), Pair(87, -13),
  Pair(186, -53), Pair(207, -90), Pair(145, -46), Pair(97, -41)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-1, 8), Pair(-6, 22), Pair(-3, 56), Pair(23, 90), Pair(24, 155), Pair(26, 50), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -6), Pair(-2, 1), Pair(17, 11), Pair(42, 49), Pair(110, 178), Pair(-190, 453), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-11, -47), Pair(6, -37), Pair(-6, -26), Pair(-8, -13), Pair(-16, -5), Pair(-16, -21), Pair(4, -33), Pair(-6, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-12, 8), Pair(-6, -15), Pair(-17, -9), Pair(-15, -18), Pair(-18, -20), Pair(-10, -10), Pair(-5, -16), Pair(-10, 4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 8), Pair(26, 3), Pair(22, 10), Pair(24, 8), Pair(26, 14), Pair(37, 4), Pair(47, 4), Pair(75, 2)
  },
  {
      Pair(4, 27), Pair(8, 4), Pair(8, 4), Pair(18, -6), Pair(13, -2), Pair(16, -6), Pair(26, -3), Pair(13, 16)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(20, -2), Pair(12, -2),
  Pair(24, -9), Pair(21, -7), Pair(23, -11),
  Pair(34, -2), Pair(0, 0), Pair(31, -2),
  Pair(-10, 5), Pair(-18, 4), Pair(-9, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-14, 3), Pair(-9, 3),
  Pair(-6, 1), Pair(-16, 6), Pair(-9, 4),
  Pair(-1, -6), Pair(-13, 0), Pair(-2, -5),
  Pair(13, -8), Pair(-6, -4), Pair(11, -6),
  Pair(31, -8), Pair(21, -1), Pair(25, -8),
  Pair(0, 0), Pair(0, -31), Pair(0, 0),
  Pair(51, -49), Pair(0, 0), Pair(46, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-19, 17), Pair(-24, 2), Pair(-16, -19), Pair(-14, -29), Pair(-9, -31), Pair(6, -33), Pair(-4, -36)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-73, -33), Pair(0, -33), Pair(1, -9), Pair(7, -1), Pair(7, 5), Pair(5, 11), Pair(-10, 6)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-47, 137);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-85, -9), Pair(-91, -1), Pair(-54, -6), Pair(-48, -4), Pair(-36, 1), Pair(-62, 5), Pair(-62, 6), Pair(-50, 9)
  },
  {
      Pair(-23, 52), Pair(-41, 23), Pair(-21, 15), Pair(-3, -2), Pair(-6, -4), Pair(-13, 8), Pair(-31, 25), Pair(-30, 39)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, 1), Pair(35, -9), Pair(84, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -2), Pair(30, -6), Pair(57, -17), Pair(64, -46), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -23), Pair(32, -24), Pair(57, -20), Pair(90, -26), Pair(103, -40), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 8), Pair(15, 22), Pair(39, 29), Pair(86, 17), Pair(126, 19), Pair(211, -25), Pair(279, -72)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-15, 18), Pair(-59, -21), Pair(-64, -53), Pair(-82, -5), Pair(-76, 38), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(8, -15), Pair(12, 0), Pair(-32, -37), Pair(-68, -15), Pair(-54, 25), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(-3, -19), Pair(-18, -28), Pair(7, -27), Pair(-49, -24), Pair(-66, -53), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(-2, -25), Pair(-15, -27), Pair(-19, -30), Pair(1, -30), Pair(-77, -12), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(6, 23), Pair(10, 11), Pair(29, 17), Pair(36, 19), Pair(37, 26), Pair(20, 46), Pair(34, 16), Pair(-10, 34),
  Pair(0, 12), Pair(10, 15), Pair(10, 19), Pair(0, 32), Pair(4, 21), Pair(3, 20), Pair(12, 15), Pair(-5, 25),
  Pair(6, 9), Pair(-3, 3), Pair(-5, 15), Pair(0, 16), Pair(-2, 21), Pair(-13, 18), Pair(-5, 6), Pair(-4, 8)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-17, 10), Pair(11, 2), Pair(19, 1), Pair(33, 0), Pair(56, -13), Pair(31, -3), Pair(18, -11), Pair(-23, -30),
  Pair(-21, -7), Pair(18, 5), Pair(6, 3), Pair(14, 11), Pair(7, 4), Pair(14, -1), Pair(11, 11), Pair(13, -22),
  Pair(-28, 28), Pair(4, 5), Pair(-1, 17), Pair(12, 12), Pair(15, 22), Pair(-2, 7), Pair(10, -2), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 61);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H