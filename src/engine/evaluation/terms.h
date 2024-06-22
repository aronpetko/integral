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
  Pair(86, 176), Pair(296, 317), Pair(337, 347), Pair(409, 703), Pair(859, 1267), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(42, 140), Pair(42, 137), Pair(27, 143), Pair(60, 101), Pair(57, 104), Pair(47, 115), Pair(-2, 154), Pair(-18, 154),
      Pair(-4, -20), Pair(-18, -2), Pair(22, -46), Pair(24, -74), Pair(37, -77), Pair(68, -65), Pair(22, -16), Pair(-2, -26),
      Pair(-24, -36), Pair(-25, -30), Pair(-10, -55), Pair(-5, -72), Pair(18, -76), Pair(9, -69), Pair(-7, -39), Pair(-14, -55),
      Pair(-31, -53), Pair(-36, -36), Pair(-18, -62), Pair(-2, -70), Pair(0, -72), Pair(0, -71), Pair(-15, -49), Pair(-17, -68),
      Pair(-30, -57), Pair(-31, -42), Pair(-16, -63), Pair(-11, -63), Pair(0, -63), Pair(-6, -67), Pair(-1, -54), Pair(-12, -72),
      Pair(-30, -51), Pair(-32, -35), Pair(-21, -55), Pair(-23, -58), Pair(-12, -49), Pair(2, -62), Pair(4, -51), Pair(-24, -70),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-130, -37), Pair(-106, 11), Pair(-57, 26), Pair(-25, 12), Pair(-6, 17), Pair(-59, -6), Pair(-94, 10), Pair(-96, -55),
      Pair(-8, 16), Pair(13, 26), Pair(38, 21), Pair(42, 21), Pair(17, 15), Pair(78, 4), Pair(10, 23), Pair(20, -4),
      Pair(9, 20), Pair(40, 24), Pair(42, 43), Pair(34, 42), Pair(67, 29), Pair(69, 15), Pair(34, 18), Pair(19, 8),
      Pair(14, 32), Pair(10, 39), Pair(29, 48), Pair(52, 43), Pair(20, 49), Pair(44, 48), Pair(0, 45), Pair(35, 21),
      Pair(2, 34), Pair(12, 35), Pair(22, 51), Pair(26, 47), Pair(31, 53), Pair(36, 37), Pair(32, 32), Pair(16, 28),
      Pair(-17, 22), Pair(3, 30), Pair(10, 35), Pair(20, 50), Pair(36, 46), Pair(18, 30), Pair(24, 24), Pair(6, 26),
      Pair(-21, 22), Pair(-9, 29), Pair(3, 31), Pair(18, 29), Pair(19, 29), Pair(19, 26), Pair(11, 20), Pair(8, 32),
      Pair(-52, 25), Pair(-15, 16), Pair(-15, 26), Pair(-2, 31), Pair(7, 31), Pair(11, 19), Pair(-10, 22), Pair(-18, 18)
  },
  {
      Pair(-48, 31), Pair(-73, 33), Pair(-71, 27), Pair(-114, 35), Pair(-110, 35), Pair(-105, 24), Pair(-62, 25), Pair(-80, 20),
      Pair(-30, 11), Pair(-5, 21), Pair(-20, 23), Pair(-32, 27), Pair(-21, 18), Pair(-28, 22), Pair(-34, 28), Pair(-46, 16),
      Pair(-21, 29), Pair(-5, 25), Pair(-6, 31), Pair(-3, 19), Pair(-25, 29), Pair(9, 35), Pair(-5, 32), Pair(-12, 30),
      Pair(-28, 26), Pair(-17, 30), Pair(-8, 30), Pair(-1, 42), Pair(-3, 35), Pair(-10, 37), Pair(-21, 24), Pair(-34, 28),
      Pair(-23, 21), Pair(-32, 31), Pair(-20, 34), Pair(-1, 34), Pair(-3, 29), Pair(-20, 30), Pair(-24, 30), Pair(-8, 11),
      Pair(-23, 21), Pair(-7, 33), Pair(-8, 34), Pair(-10, 37), Pair(-7, 41), Pair(-5, 34), Pair(-3, 26), Pair(-3, 15),
      Pair(-11, 27), Pair(-8, 13), Pair(0, 16), Pair(-16, 26), Pair(-6, 26), Pair(5, 20), Pair(14, 20), Pair(0, 8),
      Pair(-23, 15), Pair(-1, 30), Pair(-22, 20), Pair(-25, 25), Pair(-16, 22), Pair(-21, 31), Pair(-8, 15), Pair(5, -6)
  },
  {
      Pair(-4, 2), Pair(-10, 13), Pair(-9, 14), Pair(-14, 11), Pair(-6, 4), Pair(15, 10), Pair(9, 9), Pair(-6, 6),
      Pair(-6, 5), Pair(-7, 21), Pair(11, 17), Pair(22, 9), Pair(6, 9), Pair(32, 7), Pair(21, 3), Pair(11, -3),
      Pair(-15, 2), Pair(11, 6), Pair(9, 2), Pair(5, 1), Pair(32, -11), Pair(41, -8), Pair(61, -13), Pair(12, -17),
      Pair(-19, 2), Pair(-5, 4), Pair(-1, 5), Pair(2, 1), Pair(5, -11), Pair(5, -5), Pair(6, -5), Pair(-10, -13),
      Pair(-24, -10), Pair(-26, 0), Pair(-14, -6), Pair(-10, -6), Pair(-8, -10), Pair(-25, 1), Pair(-3, -13), Pair(-18, -21),
      Pair(-27, -18), Pair(-20, -14), Pair(-15, -18), Pair(-16, -13), Pair(-4, -21), Pair(-7, -17), Pair(18, -36), Pair(-3, -40),
      Pair(-26, -27), Pair(-19, -18), Pair(-5, -20), Pair(-5, -19), Pair(1, -27), Pair(4, -24), Pair(11, -36), Pair(-20, -39),
      Pair(-11, -22), Pair(-6, -21), Pair(-1, -17), Pair(4, -22), Pair(10, -28), Pair(6, -20), Pair(-1, -27), Pair(-7, -37)
  },
  {
      Pair(-50, -4), Pair(-56, 8), Pair(-42, 26), Pair(-17, 9), Pair(-28, 15), Pair(-18, 16), Pair(27, -37), Pair(-30, -4),
      Pair(-7, -17), Pair(-25, 13), Pair(-29, 45), Pair(-38, 61), Pair(-59, 82), Pair(-11, 31), Pair(-11, 24), Pair(39, -2),
      Pair(-6, -5), Pair(-10, 10), Pair(-10, 40), Pair(-9, 42), Pair(-12, 53), Pair(16, 30), Pair(20, 5), Pair(10, -3),
      Pair(-14, 5), Pair(-10, 21), Pair(-9, 27), Pair(-14, 47), Pair(-12, 46), Pair(-2, 27), Pair(4, 24), Pair(2, 7),
      Pair(-9, -4), Pair(-14, 23), Pair(-10, 20), Pair(-4, 34), Pair(0, 33), Pair(-8, 21), Pair(7, 10), Pair(5, -3),
      Pair(-6, -22), Pair(-1, -3), Pair(-1, 7), Pair(-5, 12), Pair(1, 17), Pair(4, 10), Pair(17, -10), Pair(11, -23),
      Pair(0, -34), Pair(2, -29), Pair(7, -23), Pair(13, -19), Pair(11, -12), Pair(22, -40), Pair(25, -60), Pair(28, -81),
      Pair(-7, -33), Pair(-2, -30), Pair(2, -23), Pair(5, -13), Pair(10, -28), Pair(0, -37), Pair(4, -52), Pair(7, -57)
  },
  {
      Pair(69, -88), Pair(78, -41), Pair(48, -22), Pair(-77, 18), Pair(-48, 0), Pair(-51, 6), Pair(25, -11), Pair(148, -116),
      Pair(-62, 3), Pair(11, 26), Pair(-33, 35), Pair(49, 20), Pair(-11, 30), Pair(-14, 46), Pair(16, 33), Pair(-56, 12),
      Pair(-66, 4), Pair(80, 13), Pair(-14, 35), Pair(-45, 47), Pair(-19, 46), Pair(60, 29), Pair(7, 31), Pair(-35, 3),
      Pair(-36, -15), Pair(11, 4), Pair(-50, 30), Pair(-108, 47), Pair(-109, 42), Pair(-67, 31), Pair(-47, 12), Pair(-117, 2),
      Pair(-40, -28), Pair(-2, -7), Pair(-63, 22), Pair(-106, 42), Pair(-105, 37), Pair(-59, 16), Pair(-50, -1), Pair(-119, -9),
      Pair(-18, -30), Pair(25, -13), Pair(-35, 12), Pair(-52, 27), Pair(-48, 23), Pair(-43, 10), Pair(-8, -12), Pair(-41, -22),
      Pair(38, -39), Pair(9, -10), Pair(2, 1), Pair(-21, 12), Pair(-27, 12), Pair(-14, 1), Pair(8, -17), Pair(23, -39),
      Pair(26, -65), Pair(42, -38), Pair(29, -24), Pair(-33, -2), Pair(12, -26), Pair(-22, -11), Pair(26, -35), Pair(36, -74)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-32, -6), Pair(-19, 2), Pair(-9, 22), Pair(-5, 31), Pair(1, 38), Pair(7, 46), Pair(13, 46), Pair(19, 44),
  Pair(23, 35)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-31, -23), Pair(-22, -20), Pair(-12, -3), Pair(-6, 10), Pair(2, 19), Pair(5, 29), Pair(8, 33), Pair(9, 36),
  Pair(10, 39), Pair(13, 38), Pair(22, 33), Pair(28, 34), Pair(24, 48), Pair(28, 27)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-21, -53), Pair(-13, -24), Pair(-10, -20), Pair(-7, -15), Pair(-10, -7), Pair(-5, -3), Pair(-4, 3), Pair(-3, 5),
  Pair(0, 8), Pair(2, 12), Pair(5, 13), Pair(3, 18), Pair(5, 20), Pair(6, 16), Pair(-1, 14)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(1, -251), Pair(2, -235), Pair(-9, -95), Pair(-7, -49), Pair(-6, -25), Pair(-3, -13), Pair(-1, 5), Pair(0, 17),
  Pair(2, 23), Pair(4, 25), Pair(6, 31), Pair(7, 37), Pair(9, 37), Pair(8, 43), Pair(10, 44), Pair(12, 46),
  Pair(10, 53), Pair(11, 52), Pair(20, 47), Pair(32, 37), Pair(34, 36), Pair(81, 6), Pair(65, 14), Pair(82, -8),
  Pair(182, -48), Pair(201, -84), Pair(119, -28), Pair(77, -26)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-7, -5), Pair(-11, 9), Pair(-8, 45), Pair(15, 80), Pair(12, 147), Pair(21, 39), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-2, 0), Pair(17, 10), Pair(43, 48), Pair(121, 175), Pair(-136, 439), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-4, -47), Pair(10, -38), Pair(-5, -27), Pair(-4, -16), Pair(-13, -8), Pair(-15, -22), Pair(1, -33), Pair(-6, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-17, 8), Pair(-7, -16), Pair(-17, -11), Pair(-15, -20), Pair(-19, -21), Pair(-9, -11), Pair(-6, -16), Pair(-9, 3)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 13), Pair(28, 7), Pair(24, 14), Pair(28, 12), Pair(29, 15), Pair(39, 2), Pair(49, 3), Pair(75, 3)
  },
  {
      Pair(3, 52), Pair(8, 23), Pair(7, 23), Pair(17, 11), Pair(12, 11), Pair(15, 4), Pair(25, 9), Pair(11, 34)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(18, -1), Pair(12, -1),
  Pair(24, -10), Pair(21, -7), Pair(24, -11),
  Pair(33, -1), Pair(0, 0), Pair(30, -1),
  Pair(-12, 5), Pair(-14, 4), Pair(-11, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-14, 5), Pair(-8, 4),
  Pair(-5, 2), Pair(-15, 6), Pair(-8, 4),
  Pair(-1, -6), Pair(-12, 0), Pair(-1, -4),
  Pair(14, -9), Pair(-6, -4), Pair(12, -6),
  Pair(32, -9), Pair(23, -1), Pair(26, -9),
  Pair(0, 0), Pair(1, -32), Pair(0, 0),
  Pair(48, -50), Pair(0, 0), Pair(43, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-16, 17), Pair(-22, 2), Pair(-15, -19), Pair(-13, -29), Pair(-7, -32), Pair(7, -35), Pair(-3, -36)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-67, -22), Pair(8, -23), Pair(6, 1), Pair(11, 11), Pair(9, 18), Pair(8, 24), Pair(-8, 22)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-88, -6), Pair(-96, 0), Pair(-56, -5), Pair(-49, -3), Pair(-38, 1), Pair(-64, 6), Pair(-64, 8), Pair(-51, 10)
  },
  {
      Pair(-23, 55), Pair(-41, 24), Pair(-21, 16), Pair(-3, -2), Pair(-6, -4), Pair(-14, 9), Pair(-32, 26), Pair(-30, 40)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 3), Pair(34, -7), Pair(80, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 3), Pair(34, -5), Pair(54, -15), Pair(61, -45), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -15), Pair(35, -18), Pair(57, -18), Pair(87, -23), Pair(103, -37), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 9), Pair(16, 24), Pair(39, 31), Pair(85, 19), Pair(125, 21), Pair(213, -24), Pair(241, -43)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(3, 23), Pair(-4, 15), Pair(12, 24), Pair(29, 26), Pair(16, 35), Pair(19, 49), Pair(24, 21), Pair(-8, 39),
  Pair(0, 19), Pair(15, 17), Pair(12, 23), Pair(4, 37), Pair(8, 26), Pair(9, 22), Pair(19, 15), Pair(1, 27),
  Pair(9, 14), Pair(2, 7), Pair(1, 19), Pair(6, 21), Pair(4, 26), Pair(-6, 21), Pair(-1, 10), Pair(-1, 11)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-13, 12), Pair(12, -2), Pair(13, 0), Pair(25, 3), Pair(60, -15), Pair(39, -7), Pair(29, -17), Pair(-18, -26),
  Pair(-20, -6), Pair(22, 5), Pair(8, 1), Pair(22, 7), Pair(13, 2), Pair(24, -4), Pair(14, 13), Pair(22, -25),
  Pair(-25, 28), Pair(11, 4), Pair(4, 18), Pair(18, 13), Pair(23, 21), Pair(3, 8), Pair(17, -1), Pair(-50, 12)
};

constexpr FileTable<ScorePair> kRookBehindPassedPawnBonus = {
  Pair(10, 33), Pair(25, 29), Pair(13, 16), Pair(17, 1), Pair(14, -8), Pair(5, -6), Pair(-11, 21), Pair(-6, 6)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 64);

constexpr ScorePair kTempoBonus = Pair(20, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H