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
  Pair(81, 183), Pair(288, 279), Pair(350, 346), Pair(413, 690), Pair(855, 1233), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(48, 130), Pair(36, 132), Pair(21, 134), Pair(64, 90), Pair(54, 94), Pair(50, 105), Pair(-18, 148), Pair(-18, 144),
      Pair(1, -42), Pair(-17, -20), Pair(16, -65), Pair(23, -95), Pair(41, -98), Pair(63, -85), Pair(18, -37), Pair(3, -46),
      Pair(-24, -53), Pair(-23, -46), Pair(-17, -71), Pair(-10, -88), Pair(10, -89), Pair(5, -84), Pair(-15, -53), Pair(-11, -71),
      Pair(-30, -68), Pair(-32, -48), Pair(-20, -76), Pair(-8, -83), Pair(-5, -84), Pair(-4, -83), Pair(-20, -59), Pair(-16, -81),
      Pair(-40, -72), Pair(-42, -55), Pair(-32, -77), Pair(-26, -77), Pair(-19, -77), Pair(-22, -80), Pair(-23, -66), Pair(-22, -86),
      Pair(-32, -67), Pair(-34, -49), Pair(-26, -69), Pair(-28, -75), Pair(-19, -65), Pair(-5, -75), Pair(-9, -63), Pair(-22, -84),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-121, -27), Pair(-89, 13), Pair(-52, 31), Pair(-8, 13), Pair(9, 18), Pair(-34, -4), Pair(-82, 13), Pair(-85, -47),
      Pair(-11, 23), Pair(6, 36), Pair(14, 36), Pair(27, 34), Pair(23, 23), Pair(58, 17), Pair(19, 27), Pair(12, 5),
      Pair(11, 26), Pair(24, 37), Pair(26, 53), Pair(38, 47), Pair(49, 42), Pair(79, 18), Pair(19, 30), Pair(34, 9),
      Pair(23, 36), Pair(22, 42), Pair(41, 52), Pair(53, 51), Pair(44, 50), Pair(52, 48), Pair(31, 38), Pair(48, 23),
      Pair(11, 39), Pair(26, 40), Pair(36, 58), Pair(40, 56), Pair(41, 60), Pair(51, 41), Pair(40, 37), Pair(26, 33),
      Pair(-10, 28), Pair(12, 35), Pair(18, 45), Pair(30, 57), Pair(42, 54), Pair(27, 37), Pair(30, 29), Pair(13, 31),
      Pair(-14, 27), Pair(-2, 36), Pair(9, 39), Pair(22, 39), Pair(25, 37), Pair(19, 36), Pair(18, 24), Pair(15, 37),
      Pair(-46, 31), Pair(-10, 24), Pair(-10, 34), Pair(4, 40), Pair(12, 37), Pair(15, 25), Pair(-5, 29), Pair(-8, 24)
  },
  {
      Pair(-49, 33), Pair(-66, 34), Pair(-67, 27), Pair(-97, 33), Pair(-96, 33), Pair(-92, 23), Pair(-54, 25), Pair(-78, 22),
      Pair(-35, 16), Pair(-27, 28), Pair(-26, 25), Pair(-38, 29), Pair(-39, 24), Pair(-25, 22), Pair(-49, 32), Pair(-47, 18),
      Pair(-21, 31), Pair(-12, 28), Pair(-18, 34), Pair(-15, 26), Pair(-21, 30), Pair(16, 34), Pair(4, 30), Pair(-7, 31),
      Pair(-33, 29), Pair(-22, 33), Pair(-16, 34), Pair(-1, 40), Pair(-5, 35), Pair(-9, 37), Pair(-25, 31), Pair(-30, 28),
      Pair(-26, 24), Pair(-35, 35), Pair(-20, 34), Pair(-3, 34), Pair(-2, 29), Pair(-20, 34), Pair(-27, 32), Pair(-12, 14),
      Pair(-32, 25), Pair(-11, 32), Pair(-12, 34), Pair(-13, 39), Pair(-12, 43), Pair(-9, 34), Pair(-8, 26), Pair(-13, 16),
      Pair(-17, 26), Pair(-13, 15), Pair(-4, 18), Pair(-21, 30), Pair(-9, 28), Pair(-4, 22), Pair(7, 19), Pair(-4, 8),
      Pair(-27, 14), Pair(-7, 33), Pair(-28, 25), Pair(-29, 28), Pair(-20, 24), Pair(-28, 32), Pair(-16, 18), Pair(0, -6)
  },
  {
      Pair(-12, 2), Pair(-10, 11), Pair(-5, 13), Pair(-9, 12), Pair(3, 0), Pair(21, 2), Pair(8, 5), Pair(-14, 2),
      Pair(-8, -3), Pair(-4, 9), Pair(9, 7), Pair(26, -4), Pair(11, -7), Pair(30, -4), Pair(26, -7), Pair(3, -9),
      Pair(-13, -3), Pair(14, -1), Pair(12, -2), Pair(9, -5), Pair(36, -18), Pair(47, -21), Pair(61, -20), Pair(10, -22),
      Pair(-14, -2), Pair(0, 0), Pair(2, 2), Pair(6, -3), Pair(10, -18), Pair(13, -17), Pair(12, -14), Pair(-7, -19),
      Pair(-19, -9), Pair(-19, 1), Pair(-8, -4), Pair(-3, -5), Pair(0, -13), Pair(-19, -5), Pair(3, -17), Pair(-15, -23),
      Pair(-22, -14), Pair(-16, -9), Pair(-9, -12), Pair(-9, -9), Pair(0, -19), Pair(-1, -20), Pair(22, -37), Pair(0, -40),
      Pair(-20, -21), Pair(-13, -12), Pair(0, -14), Pair(-1, -15), Pair(6, -25), Pair(3, -24), Pair(12, -33), Pair(-18, -36),
      Pair(-9, -17), Pair(-3, -16), Pair(2, -12), Pair(7, -17), Pair(14, -26), Pair(6, -21), Pair(1, -24), Pair(-8, -34)
  },
  {
      Pair(-41, -1), Pair(-41, -1), Pair(-29, 18), Pair(-5, 8), Pair(-18, 16), Pair(-14, 16), Pair(32, -42), Pair(-15, -5),
      Pair(-5, -18), Pair(-16, 2), Pair(-21, 37), Pair(-36, 51), Pair(-55, 76), Pair(-14, 36), Pair(-7, 15), Pair(29, 0),
      Pair(-2, -13), Pair(-4, -1), Pair(-8, 29), Pair(-4, 30), Pair(-8, 43), Pair(19, 22), Pair(19, -1), Pair(16, -5),
      Pair(-10, -5), Pair(-5, 13), Pair(-5, 24), Pair(-8, 39), Pair(-8, 38), Pair(2, 19), Pair(10, 15), Pair(7, -1),
      Pair(-5, -10), Pair(-10, 25), Pair(-6, 26), Pair(-2, 41), Pair(3, 31), Pair(-3, 20), Pair(10, 6), Pair(8, -4),
      Pair(-4, -21), Pair(-1, 3), Pair(-1, 19), Pair(-3, 20), Pair(0, 22), Pair(5, 12), Pair(18, -8), Pair(11, -22),
      Pair(1, -27), Pair(4, -22), Pair(8, -17), Pair(12, -10), Pair(11, -8), Pair(18, -34), Pair(23, -56), Pair(30, -78),
      Pair(-9, -19), Pair(-1, -24), Pair(1, -15), Pair(2, -7), Pair(9, -30), Pair(-2, -38), Pair(3, -46), Pair(3, -45)
  },
  {
      Pair(78, -106), Pair(94, -64), Pair(67, -41), Pair(-44, -4), Pair(-25, -19), Pair(-77, -5), Pair(-12, -23), Pair(126, -132),
      Pair(-86, -9), Pair(-3, 14), Pair(-23, 19), Pair(70, 2), Pair(-4, 15), Pair(-31, 35), Pair(-28, 26), Pair(-92, 2),
      Pair(-76, -7), Pair(67, 3), Pair(11, 18), Pair(-28, 32), Pair(9, 29), Pair(65, 17), Pair(-22, 24), Pair(-47, -9),
      Pair(-42, -24), Pair(9, -8), Pair(-28, 14), Pair(-75, 30), Pair(-80, 25), Pair(-52, 17), Pair(-40, -2), Pair(-137, -6),
      Pair(-42, -40), Pair(6, -20), Pair(-40, 6), Pair(-82, 26), Pair(-79, 19), Pair(-43, 0), Pair(-43, -15), Pair(-118, -23),
      Pair(-23, -44), Pair(26, -27), Pair(-23, -4), Pair(-39, 11), Pair(-35, 7), Pair(-34, -5), Pair(-8, -26), Pair(-42, -39),
      Pair(32, -55), Pair(7, -23), Pair(3, -13), Pair(-18, -3), Pair(-23, -3), Pair(-13, -13), Pair(5, -31), Pair(19, -57),
      Pair(17, -81), Pair(35, -53), Pair(23, -36), Pair(-38, -14), Pair(4, -38), Pair(-26, -24), Pair(18, -50), Pair(25, -90)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-30, 29), Pair(-17, 30), Pair(-7, 50), Pair(-2, 57), Pair(4, 62), Pair(9, 69), Pair(15, 66), Pair(20, 63),
  Pair(23, 54)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-36, -20), Pair(-26, -22), Pair(-18, -7), Pair(-13, 4), Pair(-7, 11), Pair(-5, 19), Pair(-3, 22), Pair(-3, 26),
  Pair(-1, 29), Pair(3, 27), Pair(11, 23), Pair(16, 24), Pair(12, 36), Pair(20, 18)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-23, -48), Pair(-16, -21), Pair(-13, -17), Pair(-11, -11), Pair(-13, -6), Pair(-10, -3), Pair(-10, 3), Pair(-9, 5),
  Pair(-8, 8), Pair(-7, 11), Pair(-4, 12), Pair(-6, 16), Pair(-5, 18), Pair(-3, 16), Pair(-6, 14)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(3, -207), Pair(5, -189), Pair(-5, -67), Pair(-3, -26), Pair(-3, -3), Pair(0, 8), Pair(1, 24), Pair(2, 35),
  Pair(4, 41), Pair(6, 43), Pair(7, 47), Pair(9, 50), Pair(11, 48), Pair(10, 51), Pair(13, 49), Pair(15, 48),
  Pair(14, 51), Pair(17, 45), Pair(27, 36), Pair(39, 21), Pair(42, 15), Pair(89, -20), Pair(78, -20), Pair(99, -49),
  Pair(177, -80), Pair(197, -124), Pair(138, -88), Pair(90, -85)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(3, 13), Pair(1, 28), Pair(4, 60), Pair(30, 95), Pair(27, 163), Pair(37, 50), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(15, 7), Pair(21, 18), Pair(47, 60), Pair(123, 190), Pair(-220, 475), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(14, 6), Pair(14, 13), Pair(22, 41), Pair(149, 32), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-10, -46), Pair(10, -36), Pair(1, -25), Pair(-1, -14), Pair(-10, -6), Pair(-9, -19), Pair(9, -33), Pair(-6, -49)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-6, 13), Pair(-2, -12), Pair(-11, -4), Pair(-8, -12), Pair(-11, -14), Pair(-4, -6), Pair(1, -13), Pair(-5, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 6), Pair(26, 2), Pair(21, 8), Pair(23, 7), Pair(24, 13), Pair(37, 3), Pair(46, 2), Pair(75, 0)
  },
  {
      Pair(6, 29), Pair(9, 6), Pair(9, 5), Pair(16, -4), Pair(11, 0), Pair(17, -5), Pair(24, -2), Pair(16, 17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -6), Pair(17, -6), Pair(9, -3),
  Pair(21, -11), Pair(17, -11), Pair(19, -11),
  Pair(30, -4), Pair(0, 0), Pair(27, -3),
  Pair(-10, 5), Pair(-15, 1), Pair(-9, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-14, 3), Pair(-8, 3),
  Pair(-6, 1), Pair(-15, 5), Pair(-9, 3),
  Pair(-1, -7), Pair(-11, 0), Pair(-1, -5),
  Pair(12, -8), Pair(-4, -5), Pair(10, -6),
  Pair(29, -8), Pair(24, 0), Pair(23, -8),
  Pair(0, 0), Pair(6, -31), Pair(0, 0),
  Pair(58, -49), Pair(0, 0), Pair(50, -46)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-24, 22), Pair(-26, 7), Pair(-17, -14), Pair(-14, -24), Pair(-10, -25), Pair(1, -27), Pair(-10, -30)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-78, -43), Pair(-3, -41), Pair(-5, -18), Pair(3, -10), Pair(6, -5), Pair(6, 0), Pair(-8, -3)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-173, 200);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-54, -13), Pair(-70, -6), Pair(-40, -8), Pair(-29, -8), Pair(-23, -1), Pair(-40, 1), Pair(-53, 4), Pair(-37, 7)
  },
  {
      Pair(-18, 48), Pair(-39, 20), Pair(-22, 13), Pair(-3, -4), Pair(-6, -6), Pair(-11, 5), Pair(-32, 23), Pair(-23, 35)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -1), Pair(28, -10), Pair(66, -34), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -1), Pair(31, -3), Pair(60, -11), Pair(65, -40), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -19), Pair(34, -22), Pair(56, -17), Pair(87, -21), Pair(100, -31), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 10), Pair(16, 19), Pair(39, 22), Pair(81, 6), Pair(110, 5), Pair(167, -14), Pair(239, -69)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(32, 14), Pair(31, 20), Pair(54, 0), Pair(30, 12), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-13, 16), Pair(-61, -22), Pair(-63, -52), Pair(-82, -6), Pair(-76, 32), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -15), Pair(14, -2), Pair(-28, -37), Pair(-66, -14), Pair(-51, 28), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -17), Pair(-18, -26), Pair(7, -27), Pair(-48, -23), Pair(-64, -52), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(1, -22), Pair(-14, -26), Pair(-19, -30), Pair(12, -32), Pair(-79, -7), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(11, 23), Pair(13, 11), Pair(27, 21), Pair(37, 19), Pair(38, 27), Pair(22, 45), Pair(39, 15), Pair(-5, 37),
  Pair(-2, 13), Pair(13, 15), Pair(10, 20), Pair(0, 33), Pair(6, 21), Pair(3, 22), Pair(12, 15), Pair(-7, 25),
  Pair(7, 7), Pair(1, 2), Pair(-3, 14), Pair(2, 14), Pair(1, 19), Pair(-11, 18), Pair(-3, 7), Pair(-3, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-15, 12), Pair(14, -1), Pair(19, 1), Pair(33, 0), Pair(54, -14), Pair(33, -3), Pair(20, -11), Pair(-16, -30),
  Pair(-26, -10), Pair(19, 5), Pair(8, 2), Pair(13, 11), Pair(8, 3), Pair(14, -2), Pair(13, 11), Pair(16, -22),
  Pair(-25, 29), Pair(5, 4), Pair(-1, 18), Pair(13, 11), Pair(17, 22), Pair(-1, 7), Pair(10, 0), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 59);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H