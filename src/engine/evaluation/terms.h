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
  Pair(99, 129), Pair(357, 263), Pair(397, 294), Pair(516, 547), Pair(946, 1000), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(100, 8), Pair(74, 47), Pair(52, 55), Pair(70, 27), Pair(71, 35), Pair(25, 47), Pair(4, 59), Pair(40, 16),
      Pair(7, -17), Pair(-14, 1), Pair(7, -12), Pair(28, -27), Pair(20, -26), Pair(41, -23), Pair(12, -16), Pair(26, -30),
      Pair(-4, -23), Pair(-8, -9), Pair(3, -35), Pair(7, -36), Pair(22, -37), Pair(17, -37), Pair(-4, -20), Pair(-9, -21),
      Pair(-18, -35), Pair(-21, -13), Pair(-2, -39), Pair(8, -32), Pair(9, -41), Pair(6, -33), Pair(-6, -25), Pair(-7, -28),
      Pair(-23, -32), Pair(-29, -12), Pair(-26, -27), Pair(-22, -30), Pair(-13, -29), Pair(-22, -22), Pair(-5, -27), Pair(-9, -28),
      Pair(-20, -26), Pair(-13, -8), Pair(-14, -23), Pair(-21, -20), Pair(-17, -22), Pair(7, -21), Pair(10, -26), Pair(-10, -30),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-113, -21), Pair(-53, -21), Pair(-37, -16), Pair(4, -16), Pair(25, -47), Pair(6, -38), Pair(-62, -23), Pair(-47, -79),
      Pair(2, -40), Pair(-23, -16), Pair(46, -26), Pair(60, -17), Pair(40, 9), Pair(79, -49), Pair(25, -29), Pair(-5, -22),
      Pair(29, -33), Pair(36, -22), Pair(43, 8), Pair(62, -21), Pair(73, -12), Pair(79, -19), Pair(18, 6), Pair(51, -49),
      Pair(20, -18), Pair(30, -6), Pair(40, -1), Pair(55, 2), Pair(60, -13), Pair(76, -18), Pair(39, -1), Pair(39, -12),
      Pair(14, -12), Pair(55, -25), Pair(50, -3), Pair(51, 0), Pair(50, 9), Pair(61, -2), Pair(59, -12), Pair(26, -3),
      Pair(-7, -30), Pair(21, -16), Pair(22, 1), Pair(39, 3), Pair(41, -2), Pair(33, -6), Pair(30, -16), Pair(7, -15),
      Pair(-38, -29), Pair(20, -30), Pair(20, -31), Pair(25, -14), Pair(25, -17), Pair(20, -32), Pair(3, -25), Pair(-1, -22),
      Pair(-40, -47), Pair(-14, -16), Pair(-14, -23), Pair(3, -13), Pair(16, -23), Pair(16, -28), Pair(-14, -13), Pair(-51, -26)
  },
  {
      Pair(-25, 16), Pair(-75, 12), Pair(-39, -9), Pair(-108, -6), Pair(-39, -8), Pair(-107, -1), Pair(0, -14), Pair(-9, -1),
      Pair(-43, -1), Pair(-10, 4), Pair(8, -9), Pair(0, 2), Pair(-27, -9), Pair(10, -4), Pair(-50, 16), Pair(-38, -22),
      Pair(-10, -6), Pair(9, -12), Pair(3, 6), Pair(24, -9), Pair(32, -19), Pair(21, 3), Pair(21, -33), Pair(12, -11),
      Pair(0, -17), Pair(4, -7), Pair(11, -1), Pair(23, 12), Pair(17, 1), Pair(32, -33), Pair(2, -6), Pair(9, -12),
      Pair(11, -17), Pair(7, -8), Pair(10, -6), Pair(12, 0), Pair(20, -10), Pair(6, 3), Pair(12, -12), Pair(11, -19),
      Pair(2, -17), Pair(17, -10), Pair(11, 0), Pair(16, -5), Pair(10, -1), Pair(20, -2), Pair(28, -15), Pair(10, -8),
      Pair(17, -24), Pair(17, -26), Pair(24, -34), Pair(6, -17), Pair(17, -16), Pair(32, -33), Pair(28, -21), Pair(-9, 6),
      Pair(-13, -27), Pair(31, -41), Pair(-5, -14), Pair(-2, -19), Pair(3, -17), Pair(-11, -9), Pair(-18, -35), Pair(1, -13)
  },
  {
      Pair(32, -1), Pair(34, 3), Pair(36, 6), Pair(33, 2), Pair(43, 2), Pair(61, -12), Pair(40, -5), Pair(16, -6),
      Pair(12, 5), Pair(22, 8), Pair(40, 5), Pair(61, -1), Pair(44, -2), Pair(53, -12), Pair(31, -3), Pair(13, -4),
      Pair(15, -1), Pair(35, -3), Pair(31, -2), Pair(40, -2), Pair(61, -17), Pair(51, -2), Pair(27, -3), Pair(2, -6),
      Pair(8, -10), Pair(29, -6), Pair(42, -7), Pair(47, -17), Pair(45, -11), Pair(36, -5), Pair(21, 1), Pair(9, -9),
      Pair(-11, -9), Pair(10, 3), Pair(-8, 12), Pair(0, 8), Pair(5, -4), Pair(-18, 17), Pair(-11, 6), Pair(-30, -3),
      Pair(-27, -9), Pair(-11, -8), Pair(-28, 5), Pair(-23, 0), Pair(-12, -9), Pair(-17, -4), Pair(-6, -10), Pair(-23, -19),
      Pair(-18, -24), Pair(-9, -15), Pair(-4, -15), Pair(-12, -13), Pair(4, -26), Pair(-2, -22), Pair(-17, -27), Pair(-64, -21),
      Pair(-9, -19), Pair(-2, -22), Pair(-5, -12), Pair(8, -21), Pair(13, -26), Pair(8, -21), Pair(-21, -11), Pair(-14, -26)
  },
  {
      Pair(-6, 41), Pair(-5, 70), Pair(18, 57), Pair(43, 44), Pair(11, 89), Pair(38, 60), Pair(31, 53), Pair(9, 37),
      Pair(-19, 67), Pair(-33, 107), Pair(5, 99), Pair(-23, 128), Pair(-22, 141), Pair(6, 105), Pair(5, 75), Pair(28, 37),
      Pair(0, 25), Pair(-2, 77), Pair(-12, 110), Pair(-1, 119), Pair(12, 113), Pair(12, 120), Pair(32, 66), Pair(11, 41),
      Pair(-11, 38), Pair(2, 72), Pair(-9, 111), Pair(-20, 133), Pair(-3, 116), Pair(9, 99), Pair(-7, 89), Pair(18, 36),
      Pair(-10, 30), Pair(-18, 62), Pair(-5, 69), Pair(-10, 93), Pair(-6, 86), Pair(-4, 85), Pair(7, 51), Pair(-12, 63),
      Pair(-19, 15), Pair(-1, 22), Pair(-8, 54), Pair(-6, 44), Pair(-7, 57), Pair(-2, 62), Pair(1, 47), Pair(-12, 27),
      Pair(-7, -7), Pair(-4, -3), Pair(3, 3), Pair(4, 7), Pair(3, 10), Pair(10, -24), Pair(18, -41), Pair(-2, -34),
      Pair(-13, 0), Pair(-10, -13), Pair(-13, 0), Pair(-7, 13), Pair(-6, -15), Pair(-30, -21), Pair(1, -36), Pair(11, -28)
  },
  {
      Pair(41, -134), Pair(125, 12), Pair(107, 33), Pair(-13, 46), Pair(30, 49), Pair(-29, 66), Pair(33, 52), Pair(69, -160),
      Pair(-79, -12), Pair(48, 41), Pair(28, 29), Pair(45, 3), Pair(42, 24), Pair(8, 34), Pair(33, 15), Pair(-115, -36),
      Pair(-41, 5), Pair(123, -9), Pair(31, 7), Pair(-61, 15), Pair(-48, 11), Pair(3, -15), Pair(1, -18), Pair(-18, -42),
      Pair(10, -32), Pair(46, -14), Pair(-45, 26), Pair(-110, 21), Pair(-116, 16), Pair(-54, 3), Pair(1, -20), Pair(-103, -33),
      Pair(4, -53), Pair(21, -17), Pair(-16, 13), Pair(-90, 30), Pair(-85, 17), Pair(-4, -2), Pair(17, -26), Pair(-95, -34),
      Pair(-43, -26), Pair(14, -8), Pair(-23, 13), Pair(-26, 18), Pair(-38, 23), Pair(-19, 7), Pair(5, -8), Pair(-30, -31),
      Pair(13, -14), Pair(1, 8), Pair(0, 9), Pair(-33, 24), Pair(-37, 26), Pair(-25, 20), Pair(4, 4), Pair(20, -28),
      Pair(-5, 4), Pair(47, -16), Pair(24, 5), Pair(-52, 18), Pair(-8, 2), Pair(-40, 12), Pair(30, -8), Pair(19, -23)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-23, -43), Pair(12, -26), Pair(25, -7), Pair(32, 8), Pair(38, 15), Pair(41, 24), Pair(47, 18), Pair(50, 11),
  Pair(52, -21)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-26, -57), Pair(-4, -53), Pair(4, -32), Pair(10, -16), Pair(16, -6), Pair(20, 2), Pair(23, 1), Pair(26, 2),
  Pair(31, 4), Pair(40, -2), Pair(57, -11), Pair(53, -23), Pair(87, -30), Pair(17, -26)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-33, -51), Pair(-16, -45), Pair(-11, -36), Pair(-3, -28), Pair(-3, -15), Pair(1, -10), Pair(2, -4), Pair(8, -1),
  Pair(10, 7), Pair(16, 8), Pair(21, 9), Pair(22, 14), Pair(26, 19), Pair(43, 8), Pair(47, -9)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-21, -100), Pair(-26, -191), Pair(-22, 4), Pair(-17, 24), Pair(-13, 24), Pair(-9, 37), Pair(-9, 70), Pair(-4, 80),
  Pair(-3, 89), Pair(-1, 97), Pair(1, 99), Pair(4, 104), Pair(9, 98), Pair(6, 111), Pair(11, 102), Pair(17, 95),
  Pair(20, 87), Pair(30, 73), Pair(46, 44), Pair(48, 31), Pair(53, 20), Pair(39, -5), Pair(63, -9), Pair(39, -38),
  Pair(86, -51), Pair(179, -137), Pair(123, -77), Pair(39, -66)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-16, -59), Pair(-13, -44), Pair(-9, -11), Pair(13, 19), Pair(51, 54), Pair(89, 15), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(11, 7), Pair(21, 1), Pair(23, 22), Pair(50, 59), Pair(149, 135), Pair(-5, 462), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(27, 3), Pair(20, 3), Pair(23, 13), Pair(50, 30), Pair(207, -5), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-31, -41), Pair(14, -25), Pair(1, -26), Pair(-8, -13), Pair(-10, -10), Pair(-16, -3), Pair(5, -31), Pair(-21, -35)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(1, 3), Pair(-3, -19), Pair(-14, 1), Pair(-9, -16), Pair(-9, -13), Pair(5, -15), Pair(-6, -6), Pair(-7, -8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(47, -23), Pair(41, -26), Pair(46, -24), Pair(40, -21), Pair(38, -11), Pair(41, -17), Pair(60, -26), Pair(65, -20)
  },
  {
      Pair(25, 1), Pair(23, -19), Pair(39, -26), Pair(32, -26), Pair(27, -22), Pair(27, -23), Pair(38, -24), Pair(36, -3)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(14, -7), Pair(15, -15), Pair(15, -9),
  Pair(22, -12), Pair(15, -7), Pair(18, -8),
  Pair(24, 3), Pair(0, 0), Pair(26, 5),
  Pair(19, 5), Pair(-24, 25), Pair(22, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-4, -1), Pair(-15, 12), Pair(-2, 5),
  Pair(-7, 3), Pair(-21, 14), Pair(-4, 3),
  Pair(1, -6), Pair(-11, 4), Pair(4, -7),
  Pair(12, -9), Pair(-12, -1), Pair(12, -10),
  Pair(32, -25), Pair(41, -13), Pair(31, -28),
  Pair(0, 0), Pair(-36, -9), Pair(0, 0),
  Pair(91, -71), Pair(0, 0), Pair(74, -80)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(12, 42), Pair(-17, 48), Pair(-6, 23), Pair(3, 6), Pair(1, 9), Pair(19, 8), Pair(13, 2)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-68, -24), Pair(0, -10), Pair(0, 22), Pair(6, 40), Pair(0, 53), Pair(1, 61), Pair(3, 62)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-353, 180);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-55, 33), Pair(-57, 3), Pair(-21, -23), Pair(-16, -27), Pair(-19, -25), Pair(-29, -20), Pair(-62, 3), Pair(-53, 26)
  },
  {
      Pair(-19, 42), Pair(-32, 19), Pair(-18, 4), Pair(-5, -7), Pair(-9, -5), Pair(0, 2), Pair(-25, 16), Pair(-25, 48)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(19, -7), Pair(30, -10), Pair(76, -32), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -4), Pair(29, 0), Pair(51, -5), Pair(20, -25), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(29, -24), Pair(42, -27), Pair(78, -37), Pair(121, -47), Pair(139, -62), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 0), Pair(15, 8), Pair(38, -4), Pair(97, -47), Pair(127, -46), Pair(210, -76), Pair(208, -107)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(41, -11), Pair(18, 9), Pair(91, -34), Pair(34, -23), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-2, 33), Pair(2, 40)
  },
  {
      Pair(-84, -5), Pair(-70, -14)
  },
  {
      Pair(-55, -52), Pair(-66, -45)
  },
  {
      Pair(-102, -23), Pair(-72, -17)
  },
  {
      Pair(-61, 3), Pair(-56, 11)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(17, 38), Pair(23, 26), Pair(34, 15), Pair(29, -35), Pair(47, 9)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-7, -32), Pair(10, -19)
  },
  {
      Pair(2, -45), Pair(-1, -47)
  },
  {
      Pair(-51, -5), Pair(-37, -26)
  },
  {
      Pair(-76, 7), Pair(-65, -3)
  },
  {
      Pair(-51, 0), Pair(-44, 0)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-16, -27), Pair(-1, -11)
  },
  {
      Pair(-59, 1), Pair(-25, -27)
  },
  {
      Pair(12, -120), Pair(27, -132)
  },
  {
      Pair(-62, -16), Pair(-56, -36)
  },
  {
      Pair(-58, -42), Pair(-56, -50)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-13, -25), Pair(11, -20)
  },
  {
      Pair(-49, -17), Pair(-5, -23)
  },
  {
      Pair(-43, -18), Pair(-15, -8)
  },
  {
      Pair(11, -60), Pair(16, -39)
  },
  {
      Pair(-56, -59), Pair(-55, -67)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-17, 36), Pair(-16, 37), Pair(36, 23), Pair(9, 49), Pair(44, 38), Pair(23, 71), Pair(42, 24), Pair(-34, 78),
  Pair(34, 56), Pair(24, 10), Pair(11, 31), Pair(5, 47), Pair(-4, 57), Pair(-13, 46), Pair(10, 18), Pair(20, 7),
  Pair(20, 9), Pair(-28, 14), Pair(0, 33), Pair(10, 24), Pair(3, 23), Pair(-2, 15), Pair(3, 7), Pair(21, -3)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-46, 6), Pair(6, 26), Pair(15, -1), Pair(67, -12), Pair(82, -32), Pair(24, 2), Pair(39, 36), Pair(15, 20),
  Pair(-63, 35), Pair(22, 18), Pair(29, 4), Pair(40, -5), Pair(22, 12), Pair(24, 39), Pair(15, 21), Pair(-1, -13),
  Pair(-35, 31), Pair(-11, 31), Pair(15, 23), Pair(21, 17), Pair(20, 20), Pair(-4, 10), Pair(1, 4), Pair(-65, -31)
};

constexpr ScorePair kBishopPairBonus = Pair(36, 52);

constexpr ScorePair kTempoBonus = Pair(19, 2);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H