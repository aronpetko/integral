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
  Pair(74, 136), Pair(307, 333), Pair(323, 354), Pair(427, 614), Pair(873, 1082), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(40, 69), Pair(26, 72), Pair(13, 73), Pair(55, 29), Pair(45, 32), Pair(41, 44), Pair(-23, 86), Pair(-24, 82),
      Pair(7, 5), Pair(-11, 26), Pair(23, -18), Pair(30, -49), Pair(49, -52), Pair(68, -38), Pair(25, 9), Pair(10, 0),
      Pair(-17, -7), Pair(-17, 0), Pair(-11, -25), Pair(-3, -42), Pair(16, -43), Pair(10, -38), Pair(-9, -7), Pair(-5, -24),
      Pair(-22, -21), Pair(-26, -2), Pair(-13, -30), Pair(-1, -37), Pair(2, -38), Pair(2, -37), Pair(-13, -12), Pair(-10, -35),
      Pair(-32, -26), Pair(-36, -9), Pair(-26, -30), Pair(-19, -31), Pair(-14, -30), Pair(-16, -34), Pair(-17, -20), Pair(-15, -40),
      Pair(-24, -21), Pair(-28, -4), Pair(-19, -22), Pair(-21, -28), Pair(-13, -18), Pair(-3, -27), Pair(-4, -16), Pair(-12, -37),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-135, -50), Pair(-104, -10), Pair(-72, 7), Pair(-25, -11), Pair(-8, -6), Pair(-49, -29), Pair(-100, -10), Pair(-97, -72),
      Pair(-29, 0), Pair(-11, 12), Pair(-2, 11), Pair(10, 9), Pair(6, -1), Pair(38, -6), Pair(1, 2), Pair(-6, -19),
      Pair(-7, 3), Pair(8, 12), Pair(9, 28), Pair(21, 22), Pair(30, 17), Pair(59, -6), Pair(2, 5), Pair(16, -14),
      Pair(6, 13), Pair(6, 17), Pair(25, 27), Pair(37, 26), Pair(28, 25), Pair(36, 23), Pair(15, 12), Pair(31, -1),
      Pair(-6, 15), Pair(10, 15), Pair(20, 32), Pair(24, 31), Pair(25, 34), Pair(35, 16), Pair(23, 12), Pair(9, 8),
      Pair(-26, 4), Pair(-5, 11), Pair(2, 19), Pair(14, 31), Pair(25, 28), Pair(11, 12), Pair(12, 4), Pair(-4, 7),
      Pair(-31, 3), Pair(-18, 11), Pair(-8, 15), Pair(4, 15), Pair(7, 12), Pair(-4, 13), Pair(-5, 2), Pair(-3, 13),
      Pair(-61, 7), Pair(-23, 3), Pair(-21, 9), Pair(-8, 15), Pair(0, 12), Pair(1, 1), Pair(-19, 9), Pair(-24, -1)
  },
  {
      Pair(-28, 15), Pair(-49, 17), Pair(-51, 10), Pair(-80, 16), Pair(-80, 16), Pair(-72, 6), Pair(-36, 8), Pair(-57, 4),
      Pair(-19, -1), Pair(-11, 11), Pair(-9, 7), Pair(-22, 12), Pair(-24, 7), Pair(-12, 5), Pair(-35, 15), Pair(-38, 3),
      Pair(-6, 14), Pair(4, 11), Pair(-4, 17), Pair(-2, 9), Pair(-7, 13), Pair(28, 17), Pair(15, 14), Pair(8, 14),
      Pair(-17, 13), Pair(-6, 16), Pair(-2, 17), Pair(12, 22), Pair(9, 16), Pair(3, 19), Pair(-10, 13), Pair(-15, 11),
      Pair(-9, 7), Pair(-21, 18), Pair(-5, 16), Pair(12, 16), Pair(10, 11), Pair(-6, 16), Pair(-13, 15), Pair(4, -3),
      Pair(-15, 7), Pair(5, 15), Pair(3, 17), Pair(1, 22), Pair(0, 26), Pair(5, 16), Pair(8, 9), Pair(3, -1),
      Pair(0, 8), Pair(3, -3), Pair(10, 1), Pair(-7, 14), Pair(4, 11), Pair(6, 7), Pair(17, 4), Pair(12, -8),
      Pair(-8, -3), Pair(10, 17), Pair(-9, 13), Pair(-10, 11), Pair(1, 7), Pair(-10, 17), Pair(2, 1), Pair(18, -22)
  },
  {
      Pair(-24, 45), Pair(-26, 54), Pair(-22, 56), Pair(-28, 55), Pair(-16, 44), Pair(3, 46), Pair(-8, 48), Pair(-29, 46),
      Pair(-22, 40), Pair(-19, 51), Pair(-8, 50), Pair(9, 39), Pair(-7, 37), Pair(10, 40), Pair(10, 36), Pair(-12, 34),
      Pair(-24, 40), Pair(3, 41), Pair(-2, 40), Pair(-4, 38), Pair(18, 26), Pair(30, 24), Pair(43, 23), Pair(-3, 22),
      Pair(-25, 41), Pair(-12, 43), Pair(-9, 44), Pair(-9, 40), Pair(-5, 26), Pair(-3, 27), Pair(-3, 30), Pair(-20, 26),
      Pair(-29, 34), Pair(-29, 43), Pair(-20, 38), Pair(-17, 38), Pair(-15, 31), Pair(-33, 39), Pair(-10, 26), Pair(-29, 22),
      Pair(-32, 30), Pair(-26, 34), Pair(-21, 31), Pair(-22, 34), Pair(-14, 25), Pair(-16, 24), Pair(7, 8), Pair(-15, 5),
      Pair(-31, 23), Pair(-25, 31), Pair(-12, 29), Pair(-14, 29), Pair(-7, 19), Pair(-17, 23), Pair(-5, 13), Pair(-31, 9),
      Pair(-20, 25), Pair(-16, 25), Pair(-12, 29), Pair(-8, 24), Pair(-2, 15), Pair(-8, 21), Pair(-13, 18), Pair(-21, 11)
  },
  {
      Pair(-41, 66), Pair(-41, 67), Pair(-30, 86), Pair(-6, 76), Pair(-20, 84), Pair(-15, 83), Pair(33, 26), Pair(-13, 61),
      Pair(-8, 53), Pair(-20, 73), Pair(-25, 107), Pair(-39, 120), Pair(-56, 143), Pair(-13, 102), Pair(-7, 81), Pair(26, 70),
      Pair(-5, 58), Pair(-8, 70), Pair(-12, 99), Pair(-10, 101), Pair(-10, 111), Pair(17, 91), Pair(18, 68), Pair(14, 66),
      Pair(-14, 68), Pair(-10, 85), Pair(-10, 94), Pair(-13, 108), Pair(-12, 107), Pair(-2, 89), Pair(7, 86), Pair(4, 70),
      Pair(-10, 63), Pair(-16, 97), Pair(-11, 96), Pair(-9, 112), Pair(-4, 102), Pair(-10, 92), Pair(6, 78), Pair(3, 70),
      Pair(-8, 51), Pair(-6, 76), Pair(-9, 91), Pair(-11, 94), Pair(-10, 96), Pair(-2, 83), Pair(12, 63), Pair(6, 51),
      Pair(-5, 46), Pair(-3, 51), Pair(0, 56), Pair(1, 68), Pair(2, 66), Pair(3, 41), Pair(11, 20), Pair(19, 4),
      Pair(-17, 53), Pair(-12, 47), Pair(-10, 55), Pair(-6, 55), Pair(-3, 43), Pair(-12, 36), Pair(-8, 27), Pair(-2, 28)
  },
  {
      Pair(74, -89), Pair(94, -47), Pair(70, -26), Pair(-40, 12), Pair(-14, -4), Pair(-83, 13), Pair(-23, -5), Pair(86, -107),
      Pair(-89, 7), Pair(-2, 32), Pair(-25, 39), Pair(66, 22), Pair(-8, 35), Pair(-33, 54), Pair(-29, 44), Pair(-98, 18),
      Pair(-72, 8), Pair(67, 22), Pair(6, 42), Pair(-39, 58), Pair(-3, 56), Pair(58, 40), Pair(-21, 42), Pair(-48, 6),
      Pair(-39, -9), Pair(10, 11), Pair(-33, 37), Pair(-89, 59), Pair(-92, 54), Pair(-55, 41), Pair(-38, 16), Pair(-136, 10),
      Pair(-40, -25), Pair(11, -3), Pair(-39, 27), Pair(-83, 49), Pair(-79, 43), Pair(-40, 21), Pair(-37, 1), Pair(-118, -6),
      Pair(-26, -27), Pair(33, -12), Pair(-14, 12), Pair(-29, 27), Pair(-27, 22), Pair(-24, 10), Pair(1, -12), Pair(-47, -21),
      Pair(23, -37), Pair(8, -8), Pair(7, 0), Pair(-13, 10), Pair(-16, 10), Pair(-9, 1), Pair(5, -16), Pair(10, -38),
      Pair(-4, -58), Pair(28, -36), Pair(19, -20), Pair(-43, -1), Pair(-1, -21), Pair(-28, -9), Pair(10, -33), Pair(1, -62)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-32, -5), Pair(-18, -1), Pair(-9, 18), Pair(-3, 26), Pair(3, 31), Pair(8, 37), Pair(14, 35), Pair(19, 31),
  Pair(22, 22)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-27, -14), Pair(-17, -16), Pair(-8, 0), Pair(-3, 10), Pair(3, 17), Pair(6, 26), Pair(8, 29), Pair(9, 32),
  Pair(11, 35), Pair(15, 33), Pair(23, 29), Pair(30, 29), Pair(26, 42), Pair(36, 23)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-31, -28), Pair(-21, -1), Pair(-17, 4), Pair(-17, 19), Pair(-17, 23), Pair(-14, 25), Pair(-13, 30), Pair(-11, 34),
  Pair(-8, 37), Pair(-6, 40), Pair(-3, 41), Pair(-1, 45), Pair(3, 47), Pair(6, 45), Pair(3, 44)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-74, -118), Pair(-18, -248), Pair(-25, -35), Pair(-18, 11), Pair(-18, 53), Pair(-17, 73), Pair(-14, 86), Pair(-13, 99),
  Pair(-12, 108), Pair(-9, 109), Pair(-8, 113), Pair(-7, 121), Pair(-4, 117), Pair(-4, 122), Pair(-2, 120), Pair(2, 117),
  Pair(1, 120), Pair(4, 117), Pair(13, 106), Pair(26, 91), Pair(33, 83), Pair(75, 52), Pair(71, 46), Pair(90, 19),
  Pair(134, 3), Pair(224, -71), Pair(135, -20), Pair(63, -8)
};

constexpr QueenMobilityTable<ScorePair> kKingVirtualMobility = {
  Pair(0, 0), Pair(0, 0), Pair(33, -30), Pair(17, -4), Pair(12, 1), Pair(6, -3), Pair(5, -4), Pair(2, 1),
  Pair(-2, 4), Pair(-10, 7), Pair(-9, 6), Pair(-16, 10), Pair(-19, 11), Pair(-28, 13), Pair(-32, 16), Pair(-34, 14),
  Pair(-31, 12), Pair(-33, 9), Pair(-24, 6), Pair(-15, 2), Pair(-17, 1), Pair(-14, -2), Pair(-1, -5), Pair(-10, -10),
  Pair(17, -18), Pair(17, -20), Pair(0, 0), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-13, -78), Pair(-13, -64), Pair(-11, -32), Pair(14, 4), Pair(10, 71), Pair(32, 65), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(15, 7), Pair(22, 17), Pair(47, 59), Pair(124, 188), Pair(40, 361), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(14, 6), Pair(13, 13), Pair(22, 40), Pair(150, 30), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-10, -45), Pair(10, -36), Pair(1, -25), Pair(-2, -13), Pair(-10, -5), Pair(-7, -19), Pair(9, -32), Pair(-5, -48)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-7, 12), Pair(-2, -12), Pair(-11, -5), Pair(-8, -12), Pair(-11, -14), Pair(-4, -6), Pair(1, -13), Pair(-5, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(24, 5), Pair(21, 1), Pair(18, 7), Pair(19, 6), Pair(21, 11), Pair(33, 1), Pair(40, 2), Pair(69, -2)
  },
  {
      Pair(3, 28), Pair(5, 6), Pair(6, 5), Pair(14, -4), Pair(9, -1), Pair(13, -6), Pair(19, -2), Pair(12, 15)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -5), Pair(15, -6), Pair(8, -2),
  Pair(17, -11), Pair(10, -9), Pair(15, -11),
  Pair(26, -4), Pair(0, 0), Pair(23, -4),
  Pair(-10, 4), Pair(-12, 0), Pair(-9, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, 0), Pair(-12, 1), Pair(-8, 2),
  Pair(-6, 0), Pair(-14, 4), Pair(-9, 2),
  Pair(0, -7), Pair(-11, 0), Pair(-1, -5),
  Pair(12, -8), Pair(-3, -5), Pair(10, -6),
  Pair(29, -8), Pair(24, 1), Pair(23, -8),
  Pair(0, 0), Pair(10, -30), Pair(0, 0),
  Pair(54, -45), Pair(0, 0), Pair(45, -42)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-6, 65), Pair(-10, 51), Pair(-1, 31), Pair(2, 20), Pair(6, 18), Pair(17, 16), Pair(7, 13)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-75, 4), Pair(-2, 7), Pair(-5, 30), Pair(2, 38), Pair(5, 43), Pair(5, 48), Pair(-10, 46)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-256, 199);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-46, -15), Pair(-68, -5), Pair(-39, -7), Pair(-27, -6), Pair(-22, 0), Pair(-38, 2), Pair(-50, 4), Pair(-25, 1)
  },
  {
      Pair(-12, 45), Pair(-36, 19), Pair(-21, 12), Pair(-2, -5), Pair(-5, -8), Pair(-10, 4), Pair(-29, 22), Pair(-13, 30)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 0), Pair(28, -10), Pair(68, -35), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 0), Pair(30, -3), Pair(61, -11), Pair(58, -39), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -19), Pair(34, -21), Pair(54, -16), Pair(80, -19), Pair(93, -30), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 12), Pair(12, 23), Pair(32, 28), Pair(76, 10), Pair(109, 7), Pair(165, -12), Pair(217, -54)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(32, 14), Pair(24, 22), Pair(52, 1), Pair(24, 15), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-14, 16), Pair(-62, -23), Pair(-63, -52), Pair(-84, -5), Pair(-75, 30), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -15), Pair(13, -1), Pair(-29, -37), Pair(-67, -14), Pair(-51, 27), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -17), Pair(-18, -27), Pair(8, -27), Pair(-49, -22), Pair(-63, -47), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(0, -22), Pair(-14, -27), Pair(-20, -30), Pair(23, -36), Pair(-76, -5), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(11, 24), Pair(13, 11), Pair(26, 21), Pair(36, 19), Pair(38, 26), Pair(24, 44), Pair(39, 16), Pair(-5, 37),
  Pair(-2, 13), Pair(12, 15), Pair(10, 20), Pair(0, 33), Pair(6, 20), Pair(3, 22), Pair(12, 15), Pair(-6, 24),
  Pair(6, 7), Pair(0, 1), Pair(-4, 14), Pair(2, 14), Pair(1, 19), Pair(-11, 18), Pair(-3, 6), Pair(-3, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-13, 11), Pair(16, -1), Pair(20, 1), Pair(35, 0), Pair(58, -15), Pair(37, -4), Pair(23, -11), Pair(-14, -31),
  Pair(-25, -10), Pair(20, 5), Pair(8, 1), Pair(16, 10), Pair(9, 3), Pair(17, -2), Pair(14, 11), Pair(17, -22),
  Pair(-25, 29), Pair(6, 4), Pair(0, 17), Pair(14, 11), Pair(19, 20), Pair(0, 7), Pair(11, -1), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 59);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H