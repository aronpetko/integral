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
  Pair(73, 135), Pair(305, 338), Pair(322, 357), Pair(428, 615), Pair(878, 1084), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(42, 70), Pair(27, 73), Pair(14, 74), Pair(56, 30), Pair(46, 34), Pair(41, 45), Pair(-26, 88), Pair(-25, 84),
      Pair(8, 8), Pair(-11, 29), Pair(23, -15), Pair(30, -46), Pair(47, -49), Pair(68, -35), Pair(24, 12), Pair(10, 3),
      Pair(-17, -5), Pair(-18, 3), Pair(-10, -23), Pair(-3, -39), Pair(16, -40), Pair(10, -35), Pair(-9, -5), Pair(-5, -22),
      Pair(-22, -19), Pair(-26, 1), Pair(-13, -27), Pair(-1, -35), Pair(2, -35), Pair(3, -34), Pair(-13, -10), Pair(-9, -33),
      Pair(-31, -23), Pair(-36, -7), Pair(-24, -28), Pair(-18, -28), Pair(-11, -28), Pair(-15, -31), Pair(-16, -17), Pair(-15, -37),
      Pair(-23, -18), Pair(-27, -1), Pair(-18, -20), Pair(-19, -26), Pair(-11, -16), Pair(1, -26), Pair(-2, -15), Pair(-14, -35),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-136, -51), Pair(-104, -11), Pair(-72, 7), Pair(-25, -12), Pair(-7, -7), Pair(-48, -30), Pair(-100, -11), Pair(-99, -72),
      Pair(-29, -1), Pair(-12, 11), Pair(-3, 11), Pair(10, 9), Pair(6, -1), Pair(40, -8), Pair(1, 2), Pair(-5, -20),
      Pair(-7, 2), Pair(7, 12), Pair(9, 28), Pair(21, 21), Pair(32, 17), Pair(62, -8), Pair(2, 5), Pair(16, -16),
      Pair(6, 12), Pair(5, 16), Pair(25, 27), Pair(37, 26), Pair(27, 24), Pair(35, 23), Pair(14, 12), Pair(31, -2),
      Pair(-6, 15), Pair(9, 15), Pair(20, 32), Pair(24, 31), Pair(25, 35), Pair(35, 16), Pair(23, 12), Pair(8, 8),
      Pair(-27, 3), Pair(-5, 10), Pair(2, 19), Pair(14, 32), Pair(26, 28), Pair(11, 11), Pair(13, 4), Pair(-4, 6),
      Pair(-31, 3), Pair(-19, 11), Pair(-8, 14), Pair(5, 14), Pair(8, 11), Pair(2, 11), Pair(1, 0), Pair(-2, 12),
      Pair(-61, 6), Pair(-24, 3), Pair(-22, 9), Pair(-9, 15), Pair(-1, 12), Pair(1, 0), Pair(-20, 8), Pair(-25, -1)
  },
  {
      Pair(-29, 15), Pair(-48, 16), Pair(-51, 9), Pair(-81, 16), Pair(-79, 15), Pair(-72, 5), Pair(-37, 8), Pair(-59, 3),
      Pair(-19, -2), Pair(-12, 10), Pair(-10, 6), Pair(-23, 12), Pair(-24, 7), Pair(-13, 5), Pair(-36, 14), Pair(-34, 1),
      Pair(-6, 13), Pair(3, 10), Pair(-5, 17), Pair(-2, 8), Pair(-9, 13), Pair(27, 16), Pair(15, 13), Pair(8, 13),
      Pair(-18, 12), Pair(-7, 15), Pair(-2, 17), Pair(11, 22), Pair(8, 16), Pair(2, 19), Pair(-10, 12), Pair(-16, 10),
      Pair(-10, 6), Pair(-21, 17), Pair(-6, 16), Pair(12, 16), Pair(11, 11), Pair(-6, 15), Pair(-14, 14), Pair(4, -4),
      Pair(-16, 7), Pair(5, 14), Pair(3, 17), Pair(0, 22), Pair(2, 25), Pair(6, 16), Pair(8, 8), Pair(3, -2),
      Pair(-1, 8), Pair(3, -4), Pair(10, 0), Pair(-6, 13), Pair(5, 10), Pair(12, 4), Pair(23, 1), Pair(12, -9),
      Pair(-9, -4), Pair(10, 15), Pair(-10, 12), Pair(-11, 11), Pair(0, 6), Pair(-11, 16), Pair(3, 0), Pair(18, -24)
  },
  {
      Pair(-23, 45), Pair(-25, 54), Pair(-22, 57), Pair(-27, 55), Pair(-15, 44), Pair(3, 46), Pair(-8, 48), Pair(-27, 45),
      Pair(-21, 40), Pair(-20, 52), Pair(-8, 50), Pair(9, 39), Pair(-7, 37), Pair(10, 40), Pair(10, 36), Pair(-11, 34),
      Pair(-24, 40), Pair(2, 41), Pair(-2, 41), Pair(-5, 38), Pair(20, 26), Pair(30, 24), Pair(43, 24), Pair(-3, 22),
      Pair(-25, 42), Pair(-12, 43), Pair(-9, 45), Pair(-9, 41), Pair(-5, 26), Pair(-3, 28), Pair(-3, 30), Pair(-20, 26),
      Pair(-30, 35), Pair(-30, 44), Pair(-20, 39), Pair(-17, 39), Pair(-15, 32), Pair(-34, 40), Pair(-10, 27), Pair(-29, 22),
      Pair(-33, 30), Pair(-27, 34), Pair(-21, 32), Pair(-22, 34), Pair(-13, 25), Pair(-16, 25), Pair(8, 8), Pair(-15, 5),
      Pair(-32, 23), Pair(-25, 31), Pair(-12, 30), Pair(-13, 29), Pair(-7, 19), Pair(-11, 22), Pair(0, 11), Pair(-31, 9),
      Pair(-21, 26), Pair(-16, 25), Pair(-12, 29), Pair(-8, 24), Pair(-2, 15), Pair(-9, 22), Pair(-13, 18), Pair(-21, 11)
  },
  {
      Pair(-42, 66), Pair(-42, 67), Pair(-31, 86), Pair(-6, 75), Pair(-20, 83), Pair(-15, 82), Pair(32, 26), Pair(-13, 61),
      Pair(-8, 53), Pair(-21, 73), Pair(-26, 106), Pair(-41, 121), Pair(-58, 143), Pair(-16, 103), Pair(-11, 84), Pair(27, 70),
      Pair(-6, 59), Pair(-9, 70), Pair(-14, 100), Pair(-12, 101), Pair(-13, 113), Pair(15, 91), Pair(16, 68), Pair(14, 65),
      Pair(-15, 68), Pair(-11, 85), Pair(-11, 94), Pair(-14, 109), Pair(-13, 107), Pair(-3, 89), Pair(6, 86), Pair(4, 69),
      Pair(-10, 63), Pair(-16, 97), Pair(-12, 96), Pair(-9, 111), Pair(-4, 101), Pair(-10, 92), Pair(6, 77), Pair(3, 70),
      Pair(-9, 51), Pair(-6, 76), Pair(-9, 91), Pair(-11, 93), Pair(-8, 96), Pair(-2, 83), Pair(13, 64), Pair(6, 50),
      Pair(-5, 45), Pair(-3, 50), Pair(1, 56), Pair(3, 66), Pair(3, 65), Pair(8, 39), Pair(16, 18), Pair(20, 3),
      Pair(-16, 53), Pair(-12, 47), Pair(-10, 55), Pair(-6, 54), Pair(-3, 42), Pair(-12, 36), Pair(-8, 27), Pair(-2, 26)
  },
  {
      Pair(70, -85), Pair(89, -44), Pair(65, -22), Pair(-43, 15), Pair(-18, -1), Pair(-87, 16), Pair(-28, -1), Pair(80, -104),
      Pair(-97, 12), Pair(-8, 34), Pair(-27, 39), Pair(66, 22), Pair(-9, 35), Pair(-36, 54), Pair(-35, 46), Pair(-104, 22),
      Pair(-80, 13), Pair(61, 23), Pair(6, 38), Pair(-32, 52), Pair(3, 49), Pair(59, 37), Pair(-28, 44), Pair(-54, 10),
      Pair(-47, -4), Pair(3, 12), Pair(-33, 33), Pair(-79, 50), Pair(-83, 45), Pair(-57, 37), Pair(-45, 18), Pair(-143, 13),
      Pair(-47, -20), Pair(1, 0), Pair(-45, 26), Pair(-86, 45), Pair(-83, 39), Pair(-47, 20), Pair(-48, 5), Pair(-123, -3),
      Pair(-30, -23), Pair(21, -7), Pair(-28, 16), Pair(-44, 31), Pair(-41, 27), Pair(-39, 14), Pair(-13, -6), Pair(-49, -18),
      Pair(26, -35), Pair(1, -3), Pair(-2, 6), Pair(-24, 17), Pair(-28, 18), Pair(-18, 7), Pair(-1, -11), Pair(12, -37),
      Pair(12, -61), Pair(33, -34), Pair(23, -17), Pair(-40, 6), Pair(2, -18), Pair(-26, -5), Pair(16, -30), Pair(21, -70)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-29, -6), Pair(-16, -5), Pair(-6, 14), Pair(0, 22), Pair(6, 28), Pair(11, 34), Pair(17, 32), Pair(22, 28),
  Pair(24, 20)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-25, -13), Pair(-15, -15), Pair(-7, 0), Pair(-1, 10), Pair(5, 17), Pair(8, 25), Pair(10, 29), Pair(10, 32),
  Pair(12, 35), Pair(17, 33), Pair(25, 30), Pair(31, 30), Pair(28, 43), Pair(36, 24)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-29, -28), Pair(-19, -1), Pair(-15, 4), Pair(-16, 19), Pair(-17, 23), Pair(-13, 26), Pair(-12, 30), Pair(-10, 33),
  Pair(-8, 37), Pair(-5, 39), Pair(-2, 41), Pair(-1, 45), Pair(3, 47), Pair(6, 45), Pair(4, 43)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-71, -115), Pair(-15, -241), Pair(-22, -35), Pair(-16, 14), Pair(-16, 54), Pair(-15, 74), Pair(-13, 87), Pair(-12, 100),
  Pair(-10, 108), Pair(-8, 109), Pair(-6, 113), Pair(-6, 121), Pair(-3, 117), Pair(-3, 121), Pair(-1, 120), Pair(3, 117),
  Pair(2, 120), Pair(5, 117), Pair(14, 106), Pair(27, 92), Pair(33, 84), Pair(75, 52), Pair(71, 47), Pair(90, 19),
  Pair(133, 4), Pair(212, -63), Pair(125, -14), Pair(57, -5)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-14, -80), Pair(-15, -65), Pair(-13, -33), Pair(14, 2), Pair(10, 70), Pair(30, 67), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(15, 7), Pair(22, 17), Pair(47, 60), Pair(130, 186), Pair(73, 317), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(14, 5), Pair(14, 13), Pair(22, 40), Pair(148, 32), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -46), Pair(11, -37), Pair(1, -26), Pair(-2, -14), Pair(-10, -6), Pair(-8, -20), Pair(9, -32), Pair(-5, -49)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-7, 12), Pair(-2, -11), Pair(-11, -4), Pair(-8, -11), Pair(-11, -14), Pair(-4, -6), Pair(0, -12), Pair(-6, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(24, 5), Pair(21, 1), Pair(17, 7), Pair(19, 6), Pair(21, 11), Pair(32, 2), Pair(40, 2), Pair(68, -1)
  },
  {
      Pair(3, 29), Pair(5, 6), Pair(5, 5), Pair(14, -4), Pair(9, 0), Pair(12, -6), Pair(20, -2), Pair(12, 16)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -6), Pair(16, -6), Pair(9, -3),
  Pair(21, -11), Pair(16, -11), Pair(19, -11),
  Pair(29, -4), Pair(0, 0), Pair(26, -3),
  Pair(-11, 5), Pair(-16, 1), Pair(-10, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, 1), Pair(-13, 3), Pair(-8, 3),
  Pair(-6, 0), Pair(-15, 5), Pair(-9, 3),
  Pair(0, -7), Pair(-12, 0), Pair(-1, -5),
  Pair(13, -9), Pair(-4, -5), Pair(11, -6),
  Pair(30, -8), Pair(25, 0), Pair(24, -8),
  Pair(0, 0), Pair(7, -31), Pair(0, 0),
  Pair(58, -49), Pair(0, 0), Pair(49, -46)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-7, 65), Pair(-9, 50), Pair(-1, 29), Pair(2, 19), Pair(6, 17), Pair(18, 15), Pair(7, 12)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-77, 7), Pair(-2, 9), Pair(-5, 33), Pair(3, 40), Pair(6, 45), Pair(6, 51), Pair(-8, 48)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-219, 199);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-54, -13), Pair(-70, -5), Pair(-40, -8), Pair(-28, -8), Pair(-23, -2), Pair(-39, 1), Pair(-53, 4), Pair(-36, 6)
  },
  {
      Pair(-17, 47), Pair(-39, 20), Pair(-23, 13), Pair(-3, -5), Pair(-7, -7), Pair(-11, 5), Pair(-33, 23), Pair(-23, 35)
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
      Pair(0, 0), Pair(13, 0), Pair(30, -3), Pair(61, -11), Pair(63, -39), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -18), Pair(34, -21), Pair(54, -16), Pair(80, -19), Pair(91, -29), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 12), Pair(12, 24), Pair(32, 29), Pair(76, 11), Pair(109, 8), Pair(166, -11), Pair(209, -47)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(32, 14), Pair(28, 21), Pair(53, 1), Pair(28, 13), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-13, 16), Pair(-62, -22), Pair(-63, -52), Pair(-84, -5), Pair(-76, 31), Pair(0, 0)
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
  Pair(6, 7), Pair(0, 1), Pair(-3, 14), Pair(1, 14), Pair(1, 19), Pair(-12, 18), Pair(-4, 7), Pair(-3, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-12, 11), Pair(15, -1), Pair(20, 1), Pair(35, -1), Pair(58, -15), Pair(37, -4), Pair(22, -11), Pair(-16, -30),
  Pair(-24, -10), Pair(20, 5), Pair(8, 2), Pair(16, 10), Pair(9, 3), Pair(17, -2), Pair(13, 11), Pair(16, -21),
  Pair(-24, 28), Pair(6, 4), Pair(0, 17), Pair(13, 12), Pair(19, 21), Pair(0, 7), Pair(11, -1), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 59);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H