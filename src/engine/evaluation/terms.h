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
  Pair(123, 75), Pair(445, 118), Pair(478, 129), Pair(634, 400), Pair(1147, 824), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(94, 18), Pair(26, 66), Pair(20, 81), Pair(27, 75), Pair(47, 73), Pair(15, 81), Pair(-13, 107), Pair(133, -9),
      Pair(-14, 12), Pair(-13, 14), Pair(-15, 22), Pair(13, 5), Pair(15, 10), Pair(28, 7), Pair(-7, 28), Pair(-9, -3),
      Pair(-22, 7), Pair(-1, 2), Pair(-11, 0), Pair(5, -15), Pair(12, -5), Pair(1, -6), Pair(-2, 4), Pair(-24, 1),
      Pair(-28, 5), Pair(-21, 4), Pair(-13, -5), Pair(-1, -11), Pair(1, -10), Pair(0, -9), Pair(-15, 5), Pair(-28, 0),
      Pair(-28, 0), Pair(-22, -4), Pair(-30, 5), Pair(-23, -3), Pair(-23, 6), Pair(-15, -5), Pair(1, -2), Pair(-24, 0),
      Pair(-30, 11), Pair(-6, 2), Pair(-27, 12), Pair(-24, 0), Pair(-22, 5), Pair(6, 2), Pair(17, -3), Pair(-25, -2),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-215, 38), Pair(-101, 21), Pair(-39, 11), Pair(12, 16), Pair(64, 2), Pair(-116, 38), Pair(-59, 26), Pair(-134, 5),
      Pair(-36, 32), Pair(14, 14), Pair(27, 14), Pair(68, 16), Pair(59, 6), Pair(36, 9), Pair(22, 5), Pair(-9, 15),
      Pair(-5, 1), Pair(33, 12), Pair(22, 46), Pair(71, 20), Pair(83, 21), Pair(89, 31), Pair(13, 22), Pair(10, 8),
      Pair(23, 11), Pair(22, 27), Pair(47, 37), Pair(48, 44), Pair(44, 30), Pair(69, 22), Pair(32, 22), Pair(45, 5),
      Pair(11, 21), Pair(36, 9), Pair(34, 47), Pair(41, 48), Pair(44, 43), Pair(54, 37), Pair(42, 12), Pair(19, 33),
      Pair(-8, -4), Pair(17, 15), Pair(15, 35), Pair(26, 45), Pair(30, 34), Pair(25, 31), Pair(33, 19), Pair(4, 14),
      Pair(-13, -10), Pair(-7, 17), Pair(3, 8), Pair(19, 19), Pair(21, 24), Pair(18, 11), Pair(4, 26), Pair(0, 7),
      Pair(-53, -40), Pair(-10, 2), Pair(-16, 0), Pair(7, 18), Pair(19, 4), Pair(-1, 12), Pair(-9, 8), Pair(-20, -19)
  },
  {
      Pair(-60, 34), Pair(-66, 40), Pair(-2, 27), Pair(-50, 25), Pair(-5, 21), Pair(-69, 14), Pair(-5, 28), Pair(-59, 29),
      Pair(-34, 21), Pair(20, 26), Pair(-19, 31), Pair(15, 26), Pair(9, 13), Pair(-1, 20), Pair(-7, 28), Pair(-28, 32),
      Pair(4, 20), Pair(37, 14), Pair(4, 41), Pair(37, 21), Pair(41, 22), Pair(32, 30), Pair(31, -3), Pair(11, 10),
      Pair(4, 12), Pair(7, 30), Pair(32, 22), Pair(20, 39), Pair(19, 36), Pair(35, 5), Pair(12, 14), Pair(2, 18),
      Pair(19, 12), Pair(3, 23), Pair(12, 26), Pair(12, 28), Pair(25, 23), Pair(15, 27), Pair(8, 20), Pair(23, 7),
      Pair(9, 9), Pair(26, 11), Pair(18, 25), Pair(16, 22), Pair(13, 37), Pair(17, 25), Pair(30, 12), Pair(12, 18),
      Pair(2, 12), Pair(21, 6), Pair(31, -2), Pair(9, 13), Pair(19, 7), Pair(26, 7), Pair(33, 2), Pair(37, -1),
      Pair(2, 3), Pair(26, -11), Pair(1, 13), Pair(15, 7), Pair(21, 7), Pair(-5, 19), Pair(2, -3), Pair(24, -12)
  },
  {
      Pair(20, 2), Pair(49, -3), Pair(25, 5), Pair(82, -19), Pair(89, -14), Pair(95, -20), Pair(45, -10), Pair(13, 9),
      Pair(29, 4), Pair(32, 8), Pair(49, -4), Pair(82, -14), Pair(80, -14), Pair(69, -10), Pair(12, 0), Pair(8, 8),
      Pair(22, -2), Pair(64, -13), Pair(35, -8), Pair(50, -15), Pair(71, -21), Pair(64, -7), Pair(32, -12), Pair(27, -9),
      Pair(16, -9), Pair(39, -14), Pair(51, -19), Pair(47, -21), Pair(59, -21), Pair(28, -9), Pair(40, -21), Pair(21, -10),
      Pair(-4, -5), Pair(2, 1), Pair(21, -5), Pair(20, -8), Pair(9, -4), Pair(6, 0), Pair(-7, 0), Pair(-14, -1),
      Pair(-16, -9), Pair(-13, -7), Pair(-11, -8), Pair(-8, -14), Pair(-4, -7), Pair(-5, -11), Pair(-5, -12), Pair(-13, -11),
      Pair(-19, -18), Pair(-2, -22), Pair(19, -35), Pair(13, -29), Pair(13, -37), Pair(24, -36), Pair(-6, -31), Pair(-48, -21),
      Pair(2, -19), Pair(13, -25), Pair(11, -19), Pair(25, -32), Pair(24, -33), Pair(25, -31), Pair(-15, -13), Pair(1, -25)
  },
  {
      Pair(-6, -33), Pair(41, -45), Pair(57, -52), Pair(48, -38), Pair(93, -58), Pair(75, -66), Pair(48, -40), Pair(51, -57),
      Pair(3, -40), Pair(-8, -13), Pair(12, 16), Pair(24, 17), Pair(2, 31), Pair(11, 26), Pair(8, 12), Pair(62, -83),
      Pair(12, -57), Pair(27, -23), Pair(0, 35), Pair(24, 26), Pair(27, 30), Pair(28, 14), Pair(27, -8), Pair(28, -63),
      Pair(23, -52), Pair(17, -25), Pair(6, 22), Pair(11, 34), Pair(9, 45), Pair(26, -4), Pair(34, -30), Pair(40, -64),
      Pair(26, -93), Pair(15, -47), Pair(12, -21), Pair(6, 23), Pair(13, 3), Pair(22, -20), Pair(36, -54), Pair(29, -83),
      Pair(26, -95), Pair(29, -74), Pair(23, -53), Pair(22, -48), Pair(26, -55), Pair(27, -50), Pair(34, -83), Pair(34, -119),
      Pair(25, -136), Pair(35, -127), Pair(41, -119), Pair(38, -93), Pair(41, -110), Pair(52, -148), Pair(42, -142), Pair(53, -194),
      Pair(39, -166), Pair(26, -137), Pair(24, -134), Pair(30, -132), Pair(36, -145), Pair(18, -156), Pair(53, -179), Pair(45, -153)
  },
  {
      Pair(-70, -37), Pair(90, 93), Pair(132, 25), Pair(-7, 44), Pair(104, 30), Pair(111, 1), Pair(171, -25), Pair(216, -176),
      Pair(-34, -20), Pair(192, -19), Pair(170, -7), Pair(26, 4), Pair(57, 2), Pair(184, -39), Pair(193, -30), Pair(23, -61),
      Pair(48, -27), Pair(231, -46), Pair(182, -24), Pair(-89, 15), Pair(-169, 19), Pair(-36, -8), Pair(227, -64), Pair(100, -58),
      Pair(25, -38), Pair(132, -35), Pair(-1, 5), Pair(-87, 16), Pair(-163, 23), Pair(-10, -10), Pair(67, -31), Pair(59, -57),
      Pair(-30, -62), Pair(75, -38), Pair(29, -9), Pair(-83, 23), Pair(-67, 11), Pair(-3, -9), Pair(37, -30), Pair(-29, -56),
      Pair(22, -53), Pair(24, -29), Pair(9, -8), Pair(-35, 13), Pair(-40, 15), Pair(-23, 1), Pair(10, -15), Pair(-13, -40),
      Pair(30, -40), Pair(-1, -4), Pair(-19, 3), Pair(-55, 17), Pair(-44, 15), Pair(-28, 8), Pair(-9, 0), Pair(10, -32),
      Pair(-80, 50), Pair(20, -17), Pair(10, -2), Pair(-72, 8), Pair(-12, -13), Pair(-41, 0), Pair(14, -10), Pair(13, -22)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-2, -26), Pair(14, -30), Pair(24, -7), Pair(31, 3), Pair(36, 7), Pair(42, 15), Pair(46, 9), Pair(50, -3),
  Pair(66, -38)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-6, -38), Pair(8, -42), Pair(16, -20), Pair(21, -7), Pair(25, 4), Pair(28, 7), Pair(32, 6), Pair(33, 7),
  Pair(40, 4), Pair(47, -3), Pair(61, -15), Pair(68, -27), Pair(132, -51), Pair(-2, -31)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-6, -149), Pair(7, -118), Pair(10, -99), Pair(20, -88), Pair(20, -78), Pair(24, -71), Pair(29, -68), Pair(34, -68),
  Pair(39, -62), Pair(46, -63), Pair(53, -65), Pair(57, -66), Pair(68, -67), Pair(77, -74), Pair(196, -124)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(17, -149), Pair(21, -162), Pair(22, -179), Pair(27, -175), Pair(26, -126), Pair(28, -105), Pair(31, -97), Pair(33, -80),
  Pair(36, -78), Pair(38, -71), Pair(41, -60), Pair(43, -61), Pair(43, -62), Pair(45, -61), Pair(44, -59), Pair(50, -75),
  Pair(57, -89), Pair(54, -100), Pair(84, -139), Pair(117, -175), Pair(159, -223), Pair(163, -256), Pair(150, -247), Pair(33, -253),
  Pair(28, -242), Pair(-129, -245), Pair(-119, -200), Pair(-196, -248)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-41, -32), Pair(-45, -18), Pair(-22, 1), Pair(6, 23), Pair(48, 38), Pair(98, -2), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 9), Pair(13, 4), Pair(18, 16), Pair(44, 48), Pair(161, 118), Pair(172, 204), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(20, 8), Pair(17, 3), Pair(17, 13), Pair(55, 22), Pair(182, -13), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-66, -10), Pair(-27, -4), Pair(-17, -15), Pair(-32, 6), Pair(-16, -2), Pair(-17, -7), Pair(-11, -11), Pair(-23, -17)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(18, -10), Pair(-5, -6), Pair(-12, -5), Pair(-15, -3), Pair(-19, -11), Pair(-3, -6), Pair(0, -8), Pair(1, -6)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, -9), Pair(21, -7), Pair(26, 2), Pair(23, 2), Pair(36, -1), Pair(34, -4), Pair(56, -10), Pair(56, -12)
  },
  {
      Pair(25, 5), Pair(17, -3), Pair(24, -3), Pair(28, -10), Pair(27, -12), Pair(20, -16), Pair(41, -12), Pair(25, -11)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -8), Pair(16, -17), Pair(15, -11),
  Pair(20, -8), Pair(16, -12), Pair(20, -11),
  Pair(17, 6), Pair(0, 0), Pair(16, 5),
  Pair(12, 8), Pair(-43, 20), Pair(12, 8)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-12, 7), Pair(-17, 18), Pair(-12, 11),
  Pair(-15, 7), Pair(-25, 17), Pair(-11, 9),
  Pair(-2, -2), Pair(-13, 8), Pair(0, -3),
  Pair(12, -6), Pair(-14, 4), Pair(9, -4),
  Pair(33, -21), Pair(29, -6), Pair(30, -25),
  Pair(0, 0), Pair(-98, 8), Pair(0, 0),
  Pair(47, -50), Pair(0, 0), Pair(51, -53)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(24, 26), Pair(-11, 32), Pair(-1, 11), Pair(0, 3), Pair(-3, 10), Pair(5, 10), Pair(-12, 1)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(8, -33), Pair(0, -6), Pair(0, 23), Pair(10, 34), Pair(14, 43), Pair(14, 46), Pair(-4, 62)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(35, 176);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-136, 52), Pair(-98, 14), Pair(-30, -21), Pair(16, -33), Pair(-13, -26), Pair(-19, -17), Pair(-49, -5), Pair(-87, 33)
  },
  {
      Pair(-29, 46), Pair(-30, 14), Pair(-19, 1), Pair(1, -4), Pair(-14, -4), Pair(-13, 2), Pair(-19, 15), Pair(-41, 45)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -2), Pair(22, -2), Pair(74, -17), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 3), Pair(24, 7), Pair(34, 7), Pair(-19, 9), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(21, -15), Pair(25, -12), Pair(54, -17), Pair(80, -21), Pair(85, -23), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 3), Pair(17, 9), Pair(41, -3), Pair(99, -52), Pair(172, -66), Pair(211, -74), Pair(221, -95)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(30, -4), Pair(12, 10), Pair(70, -19), Pair(27, -16), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-9, 21), Pair(5, 10)
  },
  {
      Pair(-75, -3), Pair(-65, -21)
  },
  {
      Pair(-54, -36), Pair(-55, -51)
  },
  {
      Pair(-79, -21), Pair(-71, -26)
  },
  {
      Pair(-48, 7), Pair(-49, -9)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(17, 35), Pair(25, 18), Pair(31, 10), Pair(20, -17), Pair(38, 9)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -31), Pair(6, -14)
  },
  {
      Pair(1, -22), Pair(-1, -21)
  },
  {
      Pair(-51, 6), Pair(-38, -18)
  },
  {
      Pair(-73, 4), Pair(-67, 3)
  },
  {
      Pair(-52, 32), Pair(-42, -14)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-19, -26), Pair(-1, -10)
  },
  {
      Pair(-53, 3), Pair(-21, -28)
  },
  {
      Pair(-30, -21), Pair(-15, -30)
  },
  {
      Pair(-45, -17), Pair(-62, -23)
  },
  {
      Pair(-57, -32), Pair(-44, -85)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-14, -20), Pair(12, -15)
  },
  {
      Pair(-51, -2), Pair(-6, -11)
  },
  {
      Pair(-41, -2), Pair(-15, -4)
  },
  {
      Pair(-24, -41), Pair(-10, -21)
  },
  {
      Pair(-32, -102), Pair(-68, -19)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-23, 44), Pair(23, 41), Pair(43, 25), Pair(2, 40), Pair(19, 32), Pair(-4, 33), Pair(32, 43), Pair(22, 43),
  Pair(28, -3), Pair(19, 8), Pair(20, 29), Pair(2, 23), Pair(-5, 45), Pair(-27, 53), Pair(11, 23), Pair(22, 19),
  Pair(5, -6), Pair(-10, 23), Pair(6, 13), Pair(15, 11), Pair(-3, 28), Pair(-5, 10), Pair(-18, 20), Pair(11, -13)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(45, 34), Pair(13, 14), Pair(34, -4), Pair(40, -5), Pair(34, 0), Pair(63, 6), Pair(18, 38), Pair(-40, 35),
  Pair(-67, 16), Pair(4, 21), Pair(-3, 8), Pair(17, 14), Pair(26, -8), Pair(29, 37), Pair(12, 23), Pair(-10, 22),
  Pair(-15, 10), Pair(5, 28), Pair(-1, 25), Pair(14, 15), Pair(21, 21), Pair(6, 12), Pair(13, 11), Pair(3, -27)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 59);

constexpr ScorePair kTempoBonus = Pair(20, 1);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H