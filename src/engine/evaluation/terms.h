#ifndef INTEGRAL_TERMS_H
#define INTEGRAL_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceTable = std::array<T, kNumPieceTypes>;

template <typename T>
using PiecePlusOneTable = std::array<T, kNumPieceTypes + 1>;

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
  Pair(106, 38), Pair(397, 175), Pair(444, 271), Pair(599, 495), Pair(1178, 877), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(88, 46), Pair(70, 65), Pair(31, 69), Pair(29, 60), Pair(15, 75), Pair(33, 83), Pair(-24, 97), Pair(27, 61),
      Pair(11, 59), Pair(-7, 81), Pair(20, 52), Pair(29, 38), Pair(31, 43), Pair(58, 35), Pair(11, 70), Pair(11, 57),
      Pair(-5, 60), Pair(5, 59), Pair(5, 39), Pair(12, 33), Pair(30, 35), Pair(22, 28), Pair(23, 46), Pair(0, 45),
      Pair(-13, 47), Pair(-13, 56), Pair(2, 38), Pair(11, 36), Pair(12, 30), Pair(16, 33), Pair(9, 44), Pair(-2, 39),
      Pair(-19, 47), Pair(-16, 55), Pair(-16, 43), Pair(-9, 44), Pair(0, 35), Pair(-5, 45), Pair(20, 37), Pair(-2, 36),
      Pair(-15, 56), Pair(-5, 59), Pair(-12, 54), Pair(-7, 51), Pair(-6, 48), Pair(20, 47), Pair(33, 44), Pair(-1, 37),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-194, 64), Pair(-81, 35), Pair(-44, 18), Pair(68, 10), Pair(67, 3), Pair(-18, 10), Pair(-99, 25), Pair(-10, 11),
      Pair(-12, 14), Pair(5, 35), Pair(52, 8), Pair(76, 19), Pair(114, 4), Pair(77, 2), Pair(-7, 45), Pair(19, 13),
      Pair(13, 28), Pair(53, 26), Pair(47, 42), Pair(68, 31), Pair(85, 23), Pair(95, 17), Pair(43, 26), Pair(29, 32),
      Pair(41, 25), Pair(42, 38), Pair(58, 38), Pair(64, 45), Pair(60, 39), Pair(75, 43), Pair(54, 28), Pair(53, 18),
      Pair(34, 34), Pair(40, 28), Pair(54, 47), Pair(61, 48), Pair(63, 41), Pair(71, 26), Pair(66, 30), Pair(40, 44),
      Pair(2, 22), Pair(32, 30), Pair(32, 37), Pair(48, 54), Pair(52, 47), Pair(42, 31), Pair(45, 26), Pair(29, 14),
      Pair(-12, 25), Pair(25, 45), Pair(20, 28), Pair(34, 32), Pair(35, 29), Pair(37, 15), Pair(18, 29), Pair(17, 21),
      Pair(-60, 24), Pair(0, 22), Pair(15, 12), Pair(15, 17), Pair(30, 31), Pair(19, 15), Pair(1, 20), Pair(-1, -12)
  },
  {
      Pair(-69, 11), Pair(10, 3), Pair(-15, -8), Pair(-13, -4), Pair(-2, 0), Pair(-117, 6), Pair(33, -5), Pair(-20, -13),
      Pair(-14, 1), Pair(-3, 3), Pair(-4, 8), Pair(24, 4), Pair(-15, 9), Pair(24, 6), Pair(-4, 6), Pair(-13, -11),
      Pair(9, 3), Pair(20, 0), Pair(11, 11), Pair(30, 0), Pair(65, -9), Pair(34, 11), Pair(25, 6), Pair(6, 5),
      Pair(2, -1), Pair(5, 9), Pair(14, 8), Pair(39, 7), Pair(17, 11), Pair(31, 7), Pair(1, 7), Pair(24, -12),
      Pair(13, -19), Pair(15, -1), Pair(13, 10), Pair(9, -3), Pair(28, -4), Pair(6, 7), Pair(20, -2), Pair(14, -18),
      Pair(2, -5), Pair(13, 5), Pair(12, 4), Pair(20, 8), Pair(14, 15), Pair(28, 0), Pair(26, -3), Pair(13, -9),
      Pair(11, -3), Pair(13, -16), Pair(33, -24), Pair(9, -2), Pair(23, -6), Pair(26, -13), Pair(34, -20), Pair(26, -33),
      Pair(8, -21), Pair(28, -13), Pair(1, -4), Pair(12, -13), Pair(21, -10), Pair(-2, 0), Pair(21, -29), Pair(17, -30)
  },
  {
      Pair(59, -9), Pair(54, 4), Pair(20, 24), Pair(53, 6), Pair(50, -2), Pair(140, -29), Pair(25, 6), Pair(47, 2),
      Pair(26, -2), Pair(48, 1), Pair(48, 0), Pair(83, -17), Pair(66, -16), Pair(92, -26), Pair(25, -3), Pair(32, -6),
      Pair(27, -5), Pair(74, -21), Pair(75, -18), Pair(55, -18), Pair(87, -28), Pair(113, -33), Pair(57, -14), Pair(31, -10),
      Pair(19, -7), Pair(47, -8), Pair(63, -14), Pair(54, -12), Pair(85, -29), Pair(56, -15), Pair(39, -9), Pair(21, -10),
      Pair(-5, 1), Pair(13, 1), Pair(7, 10), Pair(16, -2), Pair(13, -14), Pair(7, 4), Pair(5, 1), Pair(-4, -2),
      Pair(-9, -16), Pair(12, -8), Pair(-3, 1), Pair(7, -9), Pair(27, -21), Pair(7, -15), Pair(7, -10), Pair(-16, -12),
      Pair(-11, -19), Pair(-2, -14), Pair(16, -17), Pair(18, -23), Pair(19, -28), Pair(23, -29), Pair(9, -29), Pair(-40, -11),
      Pair(7, -25), Pair(12, -23), Pair(13, -15), Pair(24, -30), Pair(30, -37), Pair(24, -30), Pair(-10, -13), Pair(1, -24)
  },
  {
      Pair(48, 13), Pair(56, 26), Pair(5, 65), Pair(46, 37), Pair(60, 33), Pair(95, 4), Pair(76, 22), Pair(45, 34),
      Pair(11, 51), Pair(5, 70), Pair(23, 62), Pair(15, 78), Pair(51, 56), Pair(38, 51), Pair(17, 82), Pair(54, 42),
      Pair(27, 25), Pair(28, 59), Pair(36, 72), Pair(39, 85), Pair(49, 77), Pair(56, 67), Pair(75, 28), Pair(37, 35),
      Pair(22, 45), Pair(37, 49), Pair(47, 59), Pair(32, 75), Pair(32, 79), Pair(31, 57), Pair(36, 42), Pair(49, 15),
      Pair(33, 8), Pair(36, 33), Pair(32, 43), Pair(32, 69), Pair(44, 45), Pair(42, 41), Pair(54, 20), Pair(32, 10),
      Pair(30, 17), Pair(44, 16), Pair(39, 30), Pair(35, 33), Pair(42, 18), Pair(54, -2), Pair(49, -10), Pair(46, -24),
      Pair(43, -32), Pair(47, -35), Pair(48, -19), Pair(46, -15), Pair(49, -10), Pair(59, -55), Pair(70, -70), Pair(50, -54),
      Pair(49, -44), Pair(36, -44), Pair(33, -41), Pair(38, -28), Pair(37, -24), Pair(51, -84), Pair(32, -98), Pair(30, -36)
  },
  {
      Pair(159, -169), Pair(-84, 44), Pair(110, -7), Pair(-6, -12), Pair(-154, 31), Pair(27, 6), Pair(-89, 33), Pair(104, -170),
      Pair(-67, -6), Pair(55, 35), Pair(52, 23), Pair(43, 17), Pair(17, 9), Pair(-71, 51), Pair(27, 34), Pair(-129, -38),
      Pair(21, -12), Pair(96, 23), Pair(-19, 37), Pair(-135, 49), Pair(-110, 56), Pair(23, 34), Pair(11, 20), Pair(56, -18),
      Pair(-30, -11), Pair(21, 10), Pair(-16, 27), Pair(-139, 47), Pair(-180, 55), Pair(-24, 24), Pair(26, -10), Pair(-54, -26),
      Pair(-55, -34), Pair(24, -7), Pair(-18, 14), Pair(-71, 30), Pair(-64, 33), Pair(-20, 11), Pair(22, -20), Pair(-80, -6),
      Pair(-52, -17), Pair(7, -3), Pair(-12, 10), Pair(-33, 18), Pair(-46, 27), Pair(-26, 16), Pair(3, -8), Pair(-25, -16),
      Pair(35, -38), Pair(5, -8), Pair(-14, 5), Pair(-26, 11), Pair(-32, 16), Pair(-24, 13), Pair(6, -8), Pair(19, -34),
      Pair(14, -63), Pair(33, -30), Pair(22, -17), Pair(-56, -3), Pair(-7, -17), Pair(-27, -2), Pair(29, -29), Pair(29, -60)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(8, 31), Pair(29, 13), Pair(38, 28), Pair(46, 42), Pair(52, 51), Pair(57, 61), Pair(62, 56), Pair(64, 56),
  Pair(68, 46)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-10, -24), Pair(11, -34), Pair(19, -19), Pair(26, -10), Pair(31, 1), Pair(35, 4), Pair(37, 7), Pair(40, 11),
  Pair(44, 9), Pair(50, 11), Pair(66, 1), Pair(67, 5), Pair(73, 13), Pair(76, 3)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-17, -61), Pair(0, -50), Pair(7, -37), Pair(13, -31), Pair(14, -17), Pair(17, -10), Pair(21, -8), Pair(25, -4),
  Pair(28, 2), Pair(37, 1), Pair(43, 1), Pair(49, 2), Pair(47, 15), Pair(71, -5), Pair(117, -30)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(30, 18), Pair(30, -76), Pair(33, -65), Pair(38, -23), Pair(41, 5), Pair(43, 3), Pair(44, 18), Pair(45, 39),
  Pair(48, 37), Pair(50, 43), Pair(53, 44), Pair(56, 46), Pair(60, 41), Pair(62, 43), Pair(61, 43), Pair(68, 37),
  Pair(69, 31), Pair(79, 7), Pair(93, -7), Pair(98, -25), Pair(115, -46), Pair(140, -74), Pair(177, -102), Pair(159, -97),
  Pair(183, -136), Pair(348, -210), Pair(97, -107), Pair(95, -114)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-17, -73), Pair(-17, -62), Pair(-4, -39), Pair(16, -8), Pair(48, 44), Pair(81, 64), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(8, 3), Pair(13, 4), Pair(21, 25), Pair(50, 58), Pair(234, 88), Pair(66, 304), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 8), Pair(16, 8), Pair(17, 15), Pair(45, 34), Pair(114, 31), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-44, -34), Pair(-9, -20), Pair(-15, -10), Pair(-12, -2), Pair(-24, 7), Pair(-25, -4), Pair(-6, -11), Pair(-42, -12)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(1, 1), Pair(-2, -16), Pair(-7, -7), Pair(-13, -13), Pair(-18, -17), Pair(-1, -9), Pair(-14, -3), Pair(5, -7)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(35, -4), Pair(20, 1), Pair(17, 4), Pair(28, -1), Pair(27, 3), Pair(23, 3), Pair(48, -9), Pair(62, -11)
  },
  {
      Pair(24, 22), Pair(18, -5), Pair(23, -10), Pair(21, -6), Pair(23, -5), Pair(17, -10), Pair(38, -14), Pair(40, -2)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(14, -9), Pair(12, -12), Pair(14, -5),
  Pair(18, -9), Pair(11, -10), Pair(19, -11),
  Pair(25, -6), Pair(0, 0), Pair(25, -7),
  Pair(16, -1), Pair(-18, 8), Pair(-6, 5)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, 0), Pair(-13, 12), Pair(-8, 5),
  Pair(-7, 0), Pair(-19, 15), Pair(-10, 4),
  Pair(2, -8), Pair(-8, 3), Pair(-1, -6),
  Pair(13, -10), Pair(-11, -4), Pair(13, -7),
  Pair(21, -21), Pair(36, -13), Pair(27, -21),
  Pair(0, 0), Pair(-90, 15), Pair(0, 0),
  Pair(14, -46), Pair(0, 0), Pair(26, -45)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(7, 55), Pair(-10, 55), Pair(-10, 39), Pair(3, 22), Pair(-1, 22), Pair(17, 23), Pair(16, 22)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-4, -17), Pair(-5, 9), Pair(1, 34), Pair(-3, 55), Pair(-1, 61), Pair(1, 61), Pair(1, 65)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-406, 111);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-42, -5), Pair(-60, -18), Pair(-34, -20), Pair(-16, -17), Pair(-3, -19), Pair(-24, -16), Pair(-40, -4), Pair(-31, -9)
  },
  {
      Pair(-59, 42), Pair(-24, 19), Pair(-35, 18), Pair(-7, 4), Pair(-10, -7), Pair(-12, 12), Pair(-25, 30), Pair(-9, 22)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 3), Pair(22, 2), Pair(76, -16), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 0), Pair(27, 3), Pair(54, -4), Pair(-7, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -14), Pair(23, -10), Pair(48, -16), Pair(61, -9), Pair(100, -21), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(1, 19), Pair(9, 38), Pair(32, 32), Pair(65, 24), Pair(114, 8), Pair(228, -49), Pair(353, -136)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(33, -2), Pair(15, 15), Pair(51, -5), Pair(21, 8), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-6, 18), Pair(2, 19)
  },
  {
      Pair(-65, -25), Pair(-61, -21)
  },
  {
      Pair(-49, -39), Pair(-54, -52)
  },
  {
      Pair(-65, -29), Pair(-50, -34)
  },
  {
      Pair(-49, 21), Pair(-47, -6)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(16, 30), Pair(18, 24), Pair(24, 15), Pair(24, -12), Pair(38, 5)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-5, -20), Pair(7, -10)
  },
  {
      Pair(6, -72), Pair(8, -80)
  },
  {
      Pair(-42, -8), Pair(-37, -19)
  },
  {
      Pair(-61, 1), Pair(-54, -8)
  },
  {
      Pair(-37, 3), Pair(-35, 1)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-19, -19), Pair(-2, -7)
  },
  {
      Pair(-39, -14), Pair(-23, -29)
  },
  {
      Pair(-15, -63), Pair(-7, -64)
  },
  {
      Pair(-59, -3), Pair(-52, -30)
  },
  {
      Pair(-47, -47), Pair(-44, -45)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-7, -26), Pair(12, -17)
  },
  {
      Pair(-41, -10), Pair(-6, -16)
  },
  {
      Pair(-44, -5), Pair(-10, -9)
  },
  {
      Pair(12, -59), Pair(16, -48)
  },
  {
      Pair(-64, -7), Pair(-45, -46)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(51, 16), Pair(11, 24), Pair(25, 21), Pair(32, 18), Pair(47, 20), Pair(-16, 39), Pair(35, 43), Pair(66, -14),
  Pair(35, 12), Pair(8, 0), Pair(-10, 35), Pair(-1, 29), Pair(9, 43), Pair(-19, 30), Pair(12, 6), Pair(-6, 43),
  Pair(3, -6), Pair(6, 31), Pair(-4, 13), Pair(13, 17), Pair(5, 12), Pair(-2, 18), Pair(-10, 26), Pair(11, -20)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-128, 4), Pair(12, -2), Pair(75, -18), Pair(32, -11), Pair(75, -9), Pair(-36, 25), Pair(48, 21), Pair(-68, 2),
  Pair(30, -10), Pair(14, 10), Pair(16, 5), Pair(3, 6), Pair(9, 11), Pair(0, -1), Pair(18, 17), Pair(-11, 53),
  Pair(-47, 26), Pair(-18, 10), Pair(7, 13), Pair(25, 29), Pair(7, 26), Pair(1, 13), Pair(-13, 25), Pair(-16, -7)
};

constexpr ScorePair kBishopPairBonus = Pair(32, 37);

constexpr ScorePair kTempoBonus = Pair(17, 4);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H