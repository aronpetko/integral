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
  Pair(85, 174), Pair(296, 323), Pair(333, 347), Pair(409, 706), Pair(863, 1271), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(49, 142), Pair(45, 141), Pair(27, 145), Pair(62, 102), Pair(56, 104), Pair(44, 116), Pair(-9, 157), Pair(-24, 157),
      Pair(-2, -18), Pair(-14, 2), Pair(23, -43), Pair(25, -72), Pair(38, -76), Pair(69, -63), Pair(20, -14), Pair(-3, -24),
      Pair(-23, -34), Pair(-23, -27), Pair(-9, -53), Pair(-4, -70), Pair(19, -74), Pair(10, -66), Pair(-8, -37), Pair(-14, -52),
      Pair(-30, -51), Pair(-33, -34), Pair(-17, -60), Pair(-1, -68), Pair(1, -70), Pair(1, -68), Pair(-16, -46), Pair(-17, -66),
      Pair(-29, -55), Pair(-28, -39), Pair(-15, -61), Pair(-11, -61), Pair(1, -61), Pair(-5, -64), Pair(-3, -52), Pair(-12, -70),
      Pair(-29, -49), Pair(-29, -33), Pair(-20, -52), Pair(-23, -56), Pair(-11, -47), Pair(4, -59), Pair(2, -48), Pair(-24, -68),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-131, -37), Pair(-106, 11), Pair(-57, 26), Pair(-25, 12), Pair(-6, 17), Pair(-60, -5), Pair(-94, 10), Pair(-96, -55),
      Pair(-7, 16), Pair(13, 27), Pair(38, 22), Pair(42, 21), Pair(17, 14), Pair(78, 3), Pair(11, 23), Pair(20, -4),
      Pair(9, 20), Pair(41, 24), Pair(43, 43), Pair(35, 42), Pair(67, 28), Pair(70, 14), Pair(34, 17), Pair(19, 8),
      Pair(14, 32), Pair(10, 39), Pair(28, 48), Pair(52, 43), Pair(20, 49), Pair(44, 48), Pair(0, 45), Pair(35, 21),
      Pair(2, 33), Pair(12, 34), Pair(22, 50), Pair(26, 47), Pair(31, 52), Pair(37, 37), Pair(31, 33), Pair(16, 28),
      Pair(-17, 21), Pair(3, 30), Pair(10, 35), Pair(20, 50), Pair(36, 47), Pair(18, 30), Pair(24, 24), Pair(5, 26),
      Pair(-22, 22), Pair(-9, 29), Pair(3, 30), Pair(18, 29), Pair(19, 28), Pair(19, 26), Pair(11, 20), Pair(8, 31),
      Pair(-53, 24), Pair(-15, 16), Pair(-16, 26), Pair(-2, 31), Pair(6, 31), Pair(11, 19), Pair(-11, 22), Pair(-18, 18)
  },
  {
      Pair(-47, 31), Pair(-72, 33), Pair(-69, 28), Pair(-113, 36), Pair(-109, 36), Pair(-104, 24), Pair(-61, 26), Pair(-79, 21),
      Pair(-29, 13), Pair(-4, 22), Pair(-18, 24), Pair(-31, 28), Pair(-20, 18), Pair(-27, 23), Pair(-33, 29), Pair(-44, 17),
      Pair(-19, 30), Pair(-4, 26), Pair(-5, 32), Pair(-1, 20), Pair(-23, 29), Pair(10, 35), Pair(-4, 33), Pair(-10, 31),
      Pair(-27, 27), Pair(-16, 31), Pair(-7, 31), Pair(0, 43), Pair(-2, 35), Pair(-9, 38), Pair(-20, 25), Pair(-33, 29),
      Pair(-21, 22), Pair(-30, 31), Pair(-19, 35), Pair(0, 34), Pair(-1, 30), Pair(-19, 31), Pair(-23, 31), Pair(-7, 11),
      Pair(-22, 21), Pair(-6, 34), Pair(-7, 35), Pair(-9, 38), Pair(-6, 42), Pair(-3, 35), Pair(-2, 27), Pair(-1, 15),
      Pair(-10, 28), Pair(-7, 14), Pair(1, 17), Pair(-15, 27), Pair(-4, 27), Pair(7, 20), Pair(15, 20), Pair(2, 9),
      Pair(-21, 16), Pair(1, 31), Pair(-21, 21), Pair(-24, 26), Pair(-15, 23), Pair(-20, 32), Pair(-7, 16), Pair(6, -5)
  },
  {
      Pair(-1, 3), Pair(-7, 15), Pair(-6, 16), Pair(-11, 13), Pair(-4, 3), Pair(16, 9), Pair(10, 9), Pair(-4, 6),
      Pair(-4, 7), Pair(-5, 24), Pair(12, 20), Pair(25, 10), Pair(8, 8), Pair(34, 7), Pair(23, 3), Pair(13, -4),
      Pair(-14, 4), Pair(13, 9), Pair(11, 5), Pair(8, 2), Pair(34, -11), Pair(43, -8), Pair(63, -13), Pair(14, -17),
      Pair(-17, 4), Pair(-3, 7), Pair(2, 7), Pair(5, 3), Pair(8, -12), Pair(8, -5), Pair(7, -5), Pair(-8, -12),
      Pair(-23, -7), Pair(-24, 4), Pair(-12, -3), Pair(-6, -4), Pair(-5, -11), Pair(-23, 1), Pair(-1, -12), Pair(-16, -20),
      Pair(-25, -15), Pair(-19, -10), Pair(-12, -14), Pair(-13, -11), Pair(-1, -22), Pair(-6, -18), Pair(19, -35), Pair(-2, -40),
      Pair(-24, -22), Pair(-16, -13), Pair(-2, -16), Pair(-2, -17), Pair(4, -27), Pair(6, -24), Pair(13, -35), Pair(-18, -38),
      Pair(-9, -18), Pair(-4, -17), Pair(2, -13), Pair(7, -20), Pair(13, -28), Pair(8, -21), Pair(1, -26), Pair(-6, -36)
  },
  {
      Pair(-49, -4), Pair(-55, 8), Pair(-41, 27), Pair(-16, 9), Pair(-27, 15), Pair(-18, 17), Pair(27, -37), Pair(-29, -3),
      Pair(-6, -18), Pair(-24, 14), Pair(-28, 45), Pair(-38, 62), Pair(-59, 83), Pair(-11, 32), Pair(-11, 25), Pair(39, -1),
      Pair(-4, -6), Pair(-9, 10), Pair(-9, 40), Pair(-8, 43), Pair(-12, 54), Pair(16, 30), Pair(20, 6), Pair(11, -3),
      Pair(-14, 4), Pair(-10, 22), Pair(-8, 28), Pair(-14, 48), Pair(-11, 47), Pair(-2, 28), Pair(5, 25), Pair(2, 8),
      Pair(-8, -3), Pair(-14, 24), Pair(-9, 21), Pair(-4, 35), Pair(0, 34), Pair(-7, 22), Pair(7, 11), Pair(6, -2),
      Pair(-6, -21), Pair(-1, -2), Pair(-1, 8), Pair(-5, 13), Pair(1, 18), Pair(4, 11), Pair(17, -10), Pair(11, -23),
      Pair(1, -33), Pair(3, -28), Pair(8, -23), Pair(13, -18), Pair(12, -12), Pair(22, -40), Pair(26, -59), Pair(29, -80),
      Pair(-6, -32), Pair(-1, -30), Pair(2, -22), Pair(5, -12), Pair(10, -27), Pair(0, -37), Pair(6, -52), Pair(7, -57)
  },
  {
      Pair(73, -87), Pair(83, -40), Pair(52, -21), Pair(-74, 19), Pair(-45, 2), Pair(-42, 7), Pair(31, -11), Pair(154, -116),
      Pair(-62, 5), Pair(12, 28), Pair(-33, 37), Pair(50, 22), Pair(-10, 32), Pair(-13, 49), Pair(15, 36), Pair(-55, 13),
      Pair(-69, 7), Pair(79, 15), Pair(-14, 37), Pair(-45, 49), Pair(-18, 48), Pair(59, 32), Pair(7, 34), Pair(-37, 5),
      Pair(-38, -12), Pair(11, 6), Pair(-50, 32), Pair(-108, 49), Pair(-109, 44), Pair(-67, 34), Pair(-48, 14), Pair(-119, 4),
      Pair(-42, -26), Pair(-3, -5), Pair(-64, 25), Pair(-107, 44), Pair(-105, 39), Pair(-59, 18), Pair(-50, 1), Pair(-120, -6),
      Pair(-19, -28), Pair(25, -11), Pair(-35, 14), Pair(-52, 29), Pair(-48, 25), Pair(-42, 12), Pair(-8, -11), Pair(-41, -20),
      Pair(38, -38), Pair(9, -8), Pair(1, 3), Pair(-21, 14), Pair(-27, 14), Pair(-14, 3), Pair(9, -15), Pair(23, -37),
      Pair(26, -63), Pair(42, -36), Pair(29, -21), Pair(-33, 1), Pair(13, -24), Pair(-22, -8), Pair(26, -33), Pair(36, -72)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-31, -11), Pair(-18, -3), Pair(-9, 18), Pair(-4, 27), Pair(2, 34), Pair(8, 42), Pair(15, 41), Pair(20, 39),
  Pair(24, 31)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-28, -23), Pair(-19, -20), Pair(-9, -3), Pair(-2, 10), Pair(5, 20), Pair(8, 30), Pair(11, 33), Pair(12, 37),
  Pair(13, 40), Pair(17, 38), Pair(25, 34), Pair(30, 35), Pair(27, 48), Pair(31, 27)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-20, -54), Pair(-13, -25), Pair(-10, -21), Pair(-7, -16), Pair(-9, -8), Pair(-5, -3), Pair(-4, 3), Pair(-2, 5),
  Pair(1, 8), Pair(2, 12), Pair(5, 13), Pair(3, 18), Pair(5, 20), Pair(6, 16), Pair(-1, 15)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-1, -251), Pair(0, -237), Pair(-10, -97), Pair(-9, -50), Pair(-8, -26), Pair(-5, -15), Pair(-3, 3), Pair(-2, 16),
  Pair(1, 22), Pair(3, 24), Pair(4, 30), Pair(6, 35), Pair(8, 36), Pair(7, 41), Pair(9, 42), Pair(10, 45),
  Pair(9, 52), Pair(10, 50), Pair(18, 46), Pair(31, 35), Pair(33, 34), Pair(80, 4), Pair(65, 11), Pair(83, -11),
  Pair(186, -53), Pair(199, -86), Pair(109, -26), Pair(70, -25)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-7, -8), Pair(-11, 7), Pair(-8, 42), Pair(15, 78), Pair(13, 146), Pair(21, 39), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -6), Pair(-2, -1), Pair(18, 10), Pair(44, 48), Pair(123, 175), Pair(-115, 434), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-8, -47), Pair(8, -38), Pair(-5, -27), Pair(-5, -16), Pair(-13, -8), Pair(-16, -22), Pair(3, -33), Pair(-5, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-14, 8), Pair(-7, -16), Pair(-17, -11), Pair(-14, -20), Pair(-19, -21), Pair(-10, -11), Pair(-6, -16), Pair(-11, 3)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(29, 10), Pair(28, 3), Pair(24, 11), Pair(27, 10), Pair(29, 15), Pair(40, 2), Pair(50, 2), Pair(76, 2)
  },
  {
      Pair(3, 46), Pair(8, 18), Pair(7, 19), Pair(16, 8), Pair(11, 11), Pair(15, 4), Pair(25, 8), Pair(11, 33)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(19, -1), Pair(12, -2),
  Pair(25, -10), Pair(21, -7), Pair(23, -11),
  Pair(33, -1), Pair(0, 0), Pair(30, -1),
  Pair(-12, 5), Pair(-15, 4), Pair(-12, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-13, 4), Pair(-8, 4),
  Pair(-5, 2), Pair(-15, 6), Pair(-8, 4),
  Pair(-1, -6), Pair(-12, 0), Pair(-1, -5),
  Pair(14, -9), Pair(-6, -4), Pair(12, -6),
  Pair(32, -9), Pair(23, -1), Pair(26, -9),
  Pair(0, 0), Pair(-5, -31), Pair(0, 0),
  Pair(45, -50), Pair(0, 0), Pair(39, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-17, 17), Pair(-23, 3), Pair(-15, -18), Pair(-12, -29), Pair(-7, -32), Pair(10, -35), Pair(-1, -36)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-59, -22), Pair(9, -21), Pair(8, 3), Pair(13, 13), Pair(11, 20), Pair(10, 26), Pair(-8, 24)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-88, -6), Pair(-97, 1), Pair(-56, -5), Pair(-49, -3), Pair(-39, 1), Pair(-65, 6), Pair(-64, 8), Pair(-52, 10)
  },
  {
      Pair(-23, 54), Pair(-41, 24), Pair(-21, 16), Pair(-3, -2), Pair(-6, -5), Pair(-14, 9), Pair(-32, 26), Pair(-30, 40)
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
      Pair(0, 0), Pair(13, 3), Pair(34, -6), Pair(55, -15), Pair(61, -45), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -15), Pair(35, -18), Pair(56, -18), Pair(88, -23), Pair(103, -38), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 9), Pair(15, 24), Pair(39, 32), Pair(85, 20), Pair(125, 23), Pair(202, -14), Pair(184, -2)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(4, 24), Pair(-4, 15), Pair(12, 24), Pair(29, 26), Pair(16, 36), Pair(19, 49), Pair(23, 21), Pair(-8, 40),
  Pair(0, 19), Pair(15, 18), Pair(13, 23), Pair(4, 37), Pair(8, 26), Pair(9, 21), Pair(19, 15), Pair(0, 28),
  Pair(8, 15), Pair(1, 7), Pair(0, 19), Pair(6, 21), Pair(4, 26), Pair(-7, 21), Pair(0, 9), Pair(-1, 11)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-13, 12), Pair(12, -2), Pair(13, 0), Pair(25, 2), Pair(61, -15), Pair(39, -7), Pair(28, -17), Pair(-18, -27),
  Pair(-20, -6), Pair(22, 5), Pair(7, 1), Pair(22, 7), Pair(13, 3), Pair(24, -5), Pair(14, 13), Pair(22, -25),
  Pair(-25, 28), Pair(11, 4), Pair(5, 18), Pair(18, 13), Pair(23, 21), Pair(3, 9), Pair(17, -2), Pair(-50, 12)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 64);

constexpr ScorePair kTempoBonus = Pair(20, 26);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H