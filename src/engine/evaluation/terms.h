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
  Pair(127, 109), Pair(440, 97), Pair(505, 149), Pair(690, 399), Pair(1405, 702), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(119, 4), Pair(42, 59), Pair(65, 45), Pair(80, 41), Pair(85, 38), Pair(38, 49), Pair(-13, 58), Pair(162, -51),
      Pair(15, -22), Pair(13, -18), Pair(3, -13), Pair(9, -17), Pair(22, -18), Pair(46, -30), Pair(7, -4), Pair(9, -32),
      Pair(-11, -20), Pair(-1, -24), Pair(-11, -19), Pair(0, -33), Pair(11, -35), Pair(1, -34), Pair(1, -15), Pair(-21, -33),
      Pair(-25, -26), Pair(-20, -18), Pair(-14, -30), Pair(-4, -36), Pair(0, -42), Pair(-6, -32), Pair(-5, -19), Pair(-28, -33),
      Pair(-32, -28), Pair(-24, -23), Pair(-35, -23), Pair(-28, -26), Pair(-22, -29), Pair(-33, -25), Pair(-2, -18), Pair(-27, -36),
      Pair(-25, -19), Pair(-8, -14), Pair(-24, -15), Pair(-25, -20), Pair(-23, -24), Pair(2, -25), Pair(15, -16), Pair(-22, -32),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-157, 8), Pair(-77, 6), Pair(-43, 18), Pair(51, -8), Pair(84, -19), Pair(-53, 10), Pair(0, 13), Pair(-164, 10),
      Pair(-14, 23), Pair(16, 9), Pair(54, 3), Pair(94, -5), Pair(77, 2), Pair(86, -14), Pair(46, 2), Pair(21, 3),
      Pair(7, 4), Pair(55, -6), Pair(70, 25), Pair(98, 1), Pair(98, 16), Pair(99, 18), Pair(48, 10), Pair(32, -9),
      Pair(55, -4), Pair(48, 12), Pair(87, 16), Pair(92, 19), Pair(90, 8), Pair(95, -1), Pair(69, 11), Pair(57, 4),
      Pair(44, 2), Pair(59, -3), Pair(73, 24), Pair(70, 26), Pair(79, 22), Pair(81, 24), Pair(84, -4), Pair(45, 14),
      Pair(14, -16), Pair(40, 4), Pair(43, 23), Pair(73, 25), Pair(65, 15), Pair(56, 18), Pair(55, -5), Pair(23, 6),
      Pair(20, -7), Pair(34, -11), Pair(30, -4), Pair(44, 4), Pair(48, 2), Pair(40, -5), Pair(55, -14), Pair(32, -9),
      Pair(-45, -38), Pair(3, -5), Pair(32, -8), Pair(42, -17), Pair(55, -16), Pair(23, -14), Pair(6, 3), Pair(5, -45)
  },
  {
      Pair(-48, 28), Pair(-13, 16), Pair(-54, -1), Pair(-47, -3), Pair(41, -10), Pair(-26, -10), Pair(-28, 12), Pair(-96, 16),
      Pair(-12, 13), Pair(6, 10), Pair(9, 6), Pair(3, 3), Pair(12, 1), Pair(23, 0), Pair(-21, 19), Pair(5, -7),
      Pair(23, -2), Pair(37, -7), Pair(25, 16), Pair(42, 3), Pair(62, -8), Pair(57, 9), Pair(66, -31), Pair(45, -15),
      Pair(9, -7), Pair(26, 5), Pair(39, 2), Pair(44, 19), Pair(42, 17), Pair(70, -23), Pair(27, -5), Pair(35, -6),
      Pair(20, -10), Pair(13, 2), Pair(34, 5), Pair(32, 8), Pair(38, 1), Pair(29, 4), Pair(49, -10), Pair(33, -11),
      Pair(12, -1), Pair(42, -4), Pair(35, 7), Pair(36, 2), Pair(32, 8), Pair(49, 3), Pair(38, 3), Pair(26, -9),
      Pair(27, -13), Pair(39, -17), Pair(34, -18), Pair(27, -7), Pair(38, -7), Pair(39, -15), Pair(49, -18), Pair(28, -11),
      Pair(27, -17), Pair(25, -25), Pair(19, -5), Pair(22, -5), Pair(33, -9), Pair(8, 4), Pair(54, -27), Pair(39, -24)
  },
  {
      Pair(60, -36), Pair(58, -30), Pair(99, -45), Pair(103, -55), Pair(90, -48), Pair(146, -71), Pair(88, -43), Pair(67, -41),
      Pair(37, -31), Pair(52, -32), Pair(69, -39), Pair(94, -51), Pair(70, -39), Pair(100, -53), Pair(49, -34), Pair(53, -44),
      Pair(37, -38), Pair(77, -46), Pair(71, -47), Pair(81, -56), Pair(100, -57), Pair(96, -57), Pair(93, -51), Pair(37, -42),
      Pair(41, -43), Pair(53, -47), Pair(67, -51), Pair(79, -62), Pair(64, -50), Pair(76, -58), Pair(57, -46), Pair(19, -40),
      Pair(6, -38), Pair(20, -33), Pair(21, -37), Pair(19, -39), Pair(27, -49), Pair(26, -45), Pair(25, -38), Pair(2, -42),
      Pair(-14, -38), Pair(13, -39), Pair(13, -42), Pair(16, -52), Pair(12, -54), Pair(10, -53), Pair(15, -49), Pair(-5, -46),
      Pair(-8, -57), Pair(5, -56), Pair(27, -65), Pair(30, -70), Pair(28, -70), Pair(33, -70), Pair(26, -63), Pair(-30, -54),
      Pair(16, -57), Pair(23, -60), Pair(27, -57), Pair(36, -68), Pair(38, -72), Pair(42, -71), Pair(3, -46), Pair(12, -57)
  },
  {
      Pair(28, -68), Pair(73, -86), Pair(67, -66), Pair(98, -88), Pair(118, -99), Pair(111, -104), Pair(94, -81), Pair(63, -67),
      Pair(53, -98), Pair(14, -11), Pair(39, -35), Pair(54, -33), Pair(23, -14), Pair(62, -37), Pair(38, -30), Pair(89, -91),
      Pair(50, -80), Pair(74, -93), Pair(50, -36), Pair(60, -30), Pair(66, -31), Pair(71, -27), Pair(81, -80), Pair(81, -95),
      Pair(61, -105), Pair(57, -74), Pair(56, -34), Pair(52, -7), Pair(61, -7), Pair(66, -46), Pair(69, -63), Pair(82, -104),
      Pair(60, -123), Pair(44, -65), Pair(52, -64), Pair(50, -26), Pair(62, -42), Pair(52, -67), Pair(82, -116), Pair(67, -130),
      Pair(51, -104), Pair(61, -113), Pair(60, -88), Pair(63, -85), Pair(60, -84), Pair(68, -99), Pair(76, -120), Pair(68, -130),
      Pair(62, -150), Pair(72, -155), Pair(79, -160), Pair(74, -130), Pair(79, -154), Pair(83, -168), Pair(87, -179), Pair(81, -173),
      Pair(97, -210), Pair(54, -164), Pair(69, -180), Pair(64, -167), Pair(63, -152), Pair(49, -191), Pair(93, -275), Pair(63, -174)
  },
  {
      Pair(-77, -61), Pair(83, 87), Pair(-76, 90), Pair(30, 48), Pair(128, 16), Pair(121, 39), Pair(-30, 59), Pair(30, -77),
      Pair(-13, -17), Pair(124, 17), Pair(78, 14), Pair(30, 7), Pair(140, 2), Pair(189, -17), Pair(162, 4), Pair(7, -48),
      Pair(69, -39), Pair(242, -35), Pair(144, -12), Pair(-15, 10), Pair(-103, 18), Pair(-38, 0), Pair(206, -55), Pair(94, -55),
      Pair(68, -46), Pair(197, -52), Pair(-38, 25), Pair(-84, 21), Pair(-120, 20), Pair(-42, 9), Pair(89, -34), Pair(2, -46),
      Pair(80, -70), Pair(118, -34), Pair(21, -1), Pair(-71, 24), Pair(-53, 15), Pair(-35, 3), Pair(36, -29), Pair(-53, -50),
      Pair(33, -43), Pair(38, -20), Pair(-2, 3), Pair(-39, 19), Pair(-46, 20), Pair(-36, 4), Pair(-12, -12), Pair(-33, -37),
      Pair(12, -26), Pair(-8, 2), Pair(-35, 13), Pair(-43, 20), Pair(-47, 21), Pair(-47, 16), Pair(-23, 4), Pair(6, -31),
      Pair(-71, 39), Pair(14, -12), Pair(1, 1), Pair(-66, 15), Pair(-31, 2), Pair(-52, 10), Pair(2, -2), Pair(-8, -20)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(1, -24), Pair(28, 11), Pair(40, 27), Pair(50, 35), Pair(55, 38), Pair(60, 45), Pair(67, 39), Pair(72, 29),
  Pair(84, -8)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-12, -59), Pair(7, -43), Pair(18, -31), Pair(25, -16), Pair(31, -7), Pair(37, -2), Pair(41, -1), Pair(47, -3),
  Pair(54, -2), Pair(62, -12), Pair(76, -19), Pair(73, -28), Pair(143, -63), Pair(37, -43)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-26, -91), Pair(-4, -77), Pair(2, -66), Pair(9, -47), Pair(13, -42), Pair(16, -38), Pair(21, -35), Pair(26, -33),
  Pair(30, -28), Pair(40, -30), Pair(46, -32), Pair(54, -33), Pair(61, -34), Pair(87, -46), Pair(195, -93)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(43, -342), Pair(50, -216), Pair(55, -123), Pair(63, -139), Pair(63, -101), Pair(65, -64), Pair(70, -64), Pair(72, -51),
  Pair(76, -44), Pair(78, -39), Pair(78, -26), Pair(81, -27), Pair(82, -25), Pair(85, -27), Pair(93, -37), Pair(95, -37),
  Pair(106, -56), Pair(116, -78), Pair(144, -112), Pair(152, -128), Pair(182, -167), Pair(266, -246), Pair(275, -257), Pair(249, -292),
  Pair(275, -309), Pair(250, -343), Pair(248, -301), Pair(18, -284)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-21, -55), Pair(-17, -39), Pair(-1, -19), Pair(31, 3), Pair(72, 26), Pair(118, -16), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(9, -3), Pair(20, 2), Pair(25, 14), Pair(55, 47), Pair(163, 95), Pair(25, 462), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(25, 0), Pair(20, -1), Pair(20, 9), Pair(47, 23), Pair(190, -21), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-57, -25), Pair(-17, -5), Pair(-19, -15), Pair(-21, -11), Pair(-18, -3), Pair(-17, -18), Pair(-17, -26), Pair(-43, -24)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(15, -6), Pair(-5, -10), Pair(-11, -7), Pair(-18, -8), Pair(-13, -11), Pair(-3, -5), Pair(-7, -14), Pair(8, 1)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(32, -3), Pair(32, -10), Pair(23, 3), Pair(34, 2), Pair(36, 3), Pair(42, 1), Pair(47, -14), Pair(50, -8)
  },
  {
      Pair(33, 3), Pair(29, -11), Pair(31, -13), Pair(26, -3), Pair(30, -10), Pair(18, -11), Pair(33, -17), Pair(36, -8)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(18, -8), Pair(19, -15), Pair(15, -8),
  Pair(22, -10), Pair(17, -6), Pair(22, -9),
  Pair(27, 2), Pair(0, 0), Pair(17, 8),
  Pair(2, 9), Pair(-39, 25), Pair(7, 12)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-13, 6), Pair(-16, 13), Pair(-11, 8),
  Pair(-10, 4), Pair(-22, 16), Pair(-10, 9),
  Pair(-1, -7), Pair(-15, 8), Pair(3, -5),
  Pair(10, -7), Pair(-18, 4), Pair(15, -8),
  Pair(37, -26), Pair(26, -7), Pair(36, -25),
  Pair(0, 0), Pair(-118, 6), Pair(0, 0),
  Pair(46, -56), Pair(0, 0), Pair(53, -58)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(9, 30), Pair(-18, 33), Pair(-8, 13), Pair(-14, 3), Pair(-17, 8), Pair(1, 2), Pair(-13, -11)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-1, -16), Pair(0, 5), Pair(-5, 34), Pair(-3, 50), Pair(4, 59), Pair(2, 64), Pair(-28, 81)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-265, 188);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-174, 74), Pair(-104, 15), Pair(-8, -21), Pair(-19, -20), Pair(-7, -24), Pair(-9, -18), Pair(-56, 5), Pair(-88, 47)
  },
  {
      Pair(-88, 68), Pair(-49, 23), Pair(-28, 11), Pair(-14, -1), Pair(-6, -7), Pair(-12, 9), Pair(-26, 23), Pair(-35, 48)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -2), Pair(24, -3), Pair(55, -17), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 4), Pair(19, 9), Pair(35, 7), Pair(-14, 6), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(23, -15), Pair(35, -16), Pair(54, -16), Pair(82, -21), Pair(45, -18), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(5, 16), Pair(18, 25), Pair(39, 19), Pair(94, -13), Pair(152, -34), Pair(252, -74), Pair(253, -94)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(41, -7), Pair(19, 12), Pair(71, -19), Pair(33, -12), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-9, 39), Pair(-2, 37)
  },
  {
      Pair(-91, 4), Pair(-77, -7)
  },
  {
      Pair(-66, -32), Pair(-63, -44)
  },
  {
      Pair(-89, -17), Pair(-71, -26)
  },
  {
      Pair(-62, 8), Pair(-68, 24)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(17, 38), Pair(32, 13), Pair(26, 14), Pair(28, -7), Pair(34, 11)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-2, -32), Pair(9, -15)
  },
  {
      Pair(28, -53), Pair(33, -64)
  },
  {
      Pair(-56, 2), Pair(-45, -19)
  },
  {
      Pair(-86, 9), Pair(-71, 5)
  },
  {
      Pair(-47, -3), Pair(-46, -25)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-17, -26), Pair(1, -11)
  },
  {
      Pair(-59, 4), Pair(-25, -27)
  },
  {
      Pair(6, -67), Pair(12, -80)
  },
  {
      Pair(-68, -5), Pair(-64, -21)
  },
  {
      Pair(-63, -27), Pair(-61, -6)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-8, -27), Pair(15, -18)
  },
  {
      Pair(-54, -2), Pair(-10, -11)
  },
  {
      Pair(-53, -7), Pair(-19, -5)
  },
  {
      Pair(-11, 51), Pair(-17, 80)
  },
  {
      Pair(-63, -51), Pair(-64, -36)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(66, 17), Pair(6, 28), Pair(33, 9), Pair(-3, 42), Pair(43, 28), Pair(15, 22), Pair(53, 19), Pair(64, 31),
  Pair(28, 22), Pair(19, 18), Pair(-4, 31), Pair(-3, 32), Pair(-1, 56), Pair(-11, 52), Pair(3, 21), Pair(26, -4),
  Pair(-2, 11), Pair(-21, 25), Pair(-4, 21), Pair(11, 15), Pair(-1, 30), Pair(-7, 5), Pair(-26, 33), Pair(17, 0)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-10, -57), Pair(44, 9), Pair(18, -8), Pair(62, -19), Pair(110, -10), Pair(68, -13), Pair(34, 34), Pair(13, 44),
  Pair(-30, -31), Pair(25, 17), Pair(3, 19), Pair(24, -2), Pair(20, 8), Pair(-19, 35), Pair(12, 33), Pair(7, 55),
  Pair(3, 13), Pair(13, 13), Pair(10, 9), Pair(31, 5), Pair(28, 12), Pair(-1, 20), Pair(-1, 20), Pair(-69, 75)
};

constexpr ScorePair kBishopPairBonus = Pair(19, 66);

constexpr ScorePair kTempoBonus = Pair(20, 1);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H