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
  Pair(127, -31), Pair(442, -24), Pair(500, 40), Pair(675, 402), Pair(1294, 776), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(134, 25), Pair(59, 76), Pair(25, 82), Pair(41, 73), Pair(-10, 106), Pair(32, 87), Pair(-44, 103), Pair(125, -3),
      Pair(17, 119), Pair(6, 140), Pair(22, 126), Pair(28, 125), Pair(34, 125), Pair(60, 114), Pair(18, 135), Pair(26, 106),
      Pair(2, 118), Pair(19, 115), Pair(10, 106), Pair(20, 97), Pair(41, 101), Pair(26, 96), Pair(36, 108), Pair(6, 103),
      Pair(-9, 107), Pair(-5, 116), Pair(10, 98), Pair(23, 94), Pair(20, 91), Pair(24, 97), Pair(17, 107), Pair(0, 101),
      Pair(-12, 107), Pair(-2, 111), Pair(-11, 101), Pair(-5, 103), Pair(6, 94), Pair(2, 108), Pair(41, 96), Pair(5, 98),
      Pair(-12, 120), Pair(10, 120), Pair(-11, 119), Pair(-1, 111), Pair(0, 107), Pair(31, 113), Pair(53, 106), Pair(8, 101),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-212, 139), Pair(-74, 92), Pair(-25, 67), Pair(89, 68), Pair(90, 55), Pair(1, 64), Pair(-44, 56), Pair(12, 90),
      Pair(26, 55), Pair(49, 72), Pair(104, 47), Pair(137, 58), Pair(158, 44), Pair(125, 33), Pair(37, 72), Pair(60, 48),
      Pair(54, 69), Pair(114, 56), Pair(92, 92), Pair(127, 63), Pair(144, 68), Pair(139, 78), Pair(87, 68), Pair(81, 58),
      Pair(91, 66), Pair(91, 74), Pair(108, 80), Pair(111, 90), Pair(108, 70), Pair(137, 66), Pair(103, 63), Pair(107, 54),
      Pair(84, 70), Pair(92, 53), Pair(102, 89), Pair(111, 89), Pair(117, 77), Pair(126, 69), Pair(127, 49), Pair(89, 87),
      Pair(48, 55), Pair(84, 62), Pair(81, 82), Pair(100, 94), Pair(105, 81), Pair(93, 76), Pair(101, 55), Pair(71, 54),
      Pair(39, 43), Pair(74, 80), Pair(71, 54), Pair(83, 65), Pair(84, 66), Pair(90, 46), Pair(63, 59), Pair(67, 48),
      Pair(-16, 35), Pair(49, 48), Pair(61, 37), Pair(59, 50), Pair(79, 62), Pair(64, 46), Pair(52, 49), Pair(51, -3)
  },
  {
      Pair(-42, 61), Pair(45, 56), Pair(41, 35), Pair(27, 43), Pair(39, 48), Pair(-84, 61), Pair(80, 45), Pair(22, 46),
      Pair(29, 54), Pair(47, 55), Pair(42, 58), Pair(82, 41), Pair(38, 52), Pair(82, 45), Pair(47, 53), Pair(23, 45),
      Pair(62, 49), Pair(83, 35), Pair(60, 64), Pair(86, 53), Pair(129, 27), Pair(83, 53), Pair(93, 24), Pair(58, 46),
      Pair(50, 47), Pair(55, 56), Pair(67, 60), Pair(92, 68), Pair(67, 71), Pair(97, 29), Pair(50, 51), Pair(76, 30),
      Pair(62, 31), Pair(63, 56), Pair(56, 66), Pair(55, 55), Pair(78, 46), Pair(52, 61), Pair(69, 42), Pair(64, 29),
      Pair(47, 47), Pair(64, 49), Pair(58, 62), Pair(68, 56), Pair(60, 68), Pair(80, 51), Pair(75, 48), Pair(57, 42),
      Pair(59, 42), Pair(63, 33), Pair(86, 16), Pair(55, 47), Pair(72, 42), Pair(74, 35), Pair(85, 29), Pair(78, 8),
      Pair(50, 33), Pair(80, 22), Pair(43, 47), Pair(58, 31), Pair(71, 34), Pair(42, 49), Pair(65, 22), Pair(61, 22)
  },
  {
      Pair(139, -59), Pair(146, -52), Pair(128, -40), Pair(149, -57), Pair(155, -65), Pair(245, -97), Pair(104, -49), Pair(118, -44),
      Pair(96, -47), Pair(125, -49), Pair(127, -49), Pair(161, -65), Pair(147, -64), Pair(176, -72), Pair(93, -50), Pair(96, -50),
      Pair(103, -60), Pair(158, -77), Pair(155, -68), Pair(138, -73), Pair(173, -81), Pair(199, -86), Pair(134, -65), Pair(103, -63),
      Pair(94, -61), Pair(126, -63), Pair(146, -71), Pair(137, -69), Pair(171, -87), Pair(134, -67), Pair(115, -61), Pair(89, -58),
      Pair(64, -51), Pair(84, -51), Pair(79, -42), Pair(88, -56), Pair(83, -66), Pair(82, -51), Pair(68, -45), Pair(57, -46),
      Pair(55, -66), Pair(78, -60), Pair(65, -52), Pair(73, -58), Pair(94, -71), Pair(73, -70), Pair(71, -57), Pair(42, -51),
      Pair(61, -78), Pair(67, -70), Pair(92, -77), Pair(93, -85), Pair(91, -86), Pair(98, -88), Pair(74, -81), Pair(12, -56),
      Pair(77, -77), Pair(83, -78), Pair(83, -67), Pair(99, -89), Pair(106, -97), Pair(101, -90), Pair(51, -58), Pair(69, -73)
  },
  {
      Pair(139, -110), Pair(161, -111), Pair(113, -81), Pair(178, -128), Pair(186, -128), Pair(215, -148), Pair(178, -114), Pair(150, -109),
      Pair(110, -88), Pair(106, -63), Pair(128, -75), Pair(131, -76), Pair(175, -99), Pair(141, -81), Pair(112, -50), Pair(162, -105),
      Pair(128, -116), Pair(137, -87), Pair(138, -52), Pair(145, -42), Pair(157, -50), Pair(167, -71), Pair(188, -123), Pair(142, -114),
      Pair(126, -99), Pair(140, -89), Pair(149, -70), Pair(132, -40), Pair(129, -30), Pair(131, -71), Pair(144, -109), Pair(155, -129),
      Pair(140, -143), Pair(138, -108), Pair(130, -85), Pair(128, -54), Pair(146, -80), Pair(143, -90), Pair(154, -113), Pair(141, -150),
      Pair(131, -129), Pair(150, -124), Pair(141, -104), Pair(137, -107), Pair(145, -118), Pair(158, -138), Pair(153, -149), Pair(148, -168),
      Pair(148, -178), Pair(154, -185), Pair(156, -176), Pair(152, -164), Pair(157, -160), Pair(165, -206), Pair(181, -227), Pair(154, -205),
      Pair(154, -187), Pair(138, -192), Pair(136, -194), Pair(143, -182), Pair(141, -173), Pair(159, -245), Pair(130, -252), Pair(136, -191)
  },
  {
      Pair(-128, -27), Pair(-197, 200), Pair(69, 74), Pair(-88, 81), Pair(-38, 58), Pair(127, 22), Pair(-146, 91), Pair(-16, -46),
      Pair(-242, 48), Pair(158, 26), Pair(172, -4), Pair(61, 14), Pair(117, 6), Pair(163, -28), Pair(217, -13), Pair(-99, -44),
      Pair(146, -59), Pair(252, -22), Pair(163, -12), Pair(-80, 25), Pair(-34, 16), Pair(73, -11), Pair(289, -76), Pair(97, -50),
      Pair(82, -59), Pair(151, -35), Pair(43, 14), Pair(-98, 25), Pair(-120, 24), Pair(15, -1), Pair(117, -41), Pair(-13, -46),
      Pair(23, -82), Pair(81, -31), Pair(9, 3), Pair(-70, 21), Pair(-65, 16), Pair(2, -1), Pair(63, -35), Pair(-8, -44),
      Pair(-20, -46), Pair(30, -19), Pair(4, -3), Pair(-45, 22), Pair(-45, 21), Pair(-23, 9), Pair(12, -16), Pair(-13, -35),
      Pair(19, -35), Pair(-12, 1), Pair(-33, 10), Pair(-64, 26), Pair(-62, 27), Pair(-55, 27), Pair(-13, 2), Pair(-5, -23),
      Pair(-63, 28), Pair(5, -9), Pair(-7, 2), Pair(-104, 15), Pair(-35, -4), Pair(-64, 14), Pair(-2, -4), Pair(-10, -8)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(50, 36), Pair(68, 38), Pair(77, 55), Pair(85, 70), Pair(93, 77), Pair(97, 89), Pair(104, 78), Pair(110, 68),
  Pair(122, 27)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(34, 4), Pair(51, 3), Pair(58, 19), Pair(65, 29), Pair(70, 42), Pair(75, 46), Pair(77, 47), Pair(80, 47),
  Pair(87, 42), Pair(98, 36), Pair(116, 26), Pair(117, 11), Pair(181, 4), Pair(77, -4)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(25, -117), Pair(39, -97), Pair(45, -78), Pair(54, -72), Pair(56, -58), Pair(60, -51), Pair(65, -50), Pair(71, -48),
  Pair(73, -37), Pair(85, -42), Pair(93, -43), Pair(102, -45), Pair(106, -38), Pair(129, -56), Pair(224, -101)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(101, -100), Pair(104, -213), Pair(107, -161), Pair(111, -120), Pair(113, -88), Pair(113, -82), Pair(115, -65), Pair(116, -40),
  Pair(120, -44), Pair(121, -34), Pair(125, -34), Pair(128, -32), Pair(131, -37), Pair(134, -36), Pair(134, -38), Pair(143, -49),
  Pair(149, -63), Pair(160, -90), Pair(183, -115), Pair(195, -144), Pair(226, -177), Pair(290, -243), Pair(294, -242), Pair(303, -288),
  Pair(287, -284), Pair(393, -362), Pair(58, -233), Pair(110, -253)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-34, -59), Pair(-32, -45), Pair(-15, -24), Pair(11, 1), Pair(81, 12), Pair(161, 63), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(5, 4), Pair(11, 3), Pair(22, 22), Pair(62, 50), Pair(231, 116), Pair(28, 349), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 8), Pair(16, 6), Pair(22, 12), Pair(60, 24), Pair(137, 12), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-71, -22), Pair(-22, -15), Pair(-22, -6), Pair(-24, 3), Pair(-28, 2), Pair(-29, -11), Pair(-14, -11), Pair(-64, 1)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(8, -5), Pair(-5, -14), Pair(-10, -5), Pair(-18, -9), Pair(-25, -12), Pair(-4, -4), Pair(-19, 0), Pair(9, -11)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(43, -8), Pair(27, -5), Pair(24, -1), Pair(34, 0), Pair(32, 6), Pair(26, 6), Pair(60, -14), Pair(74, -14)
  },
  {
      Pair(34, 11), Pair(23, -11), Pair(29, -16), Pair(28, -12), Pair(29, -9), Pair(19, -10), Pair(50, -22), Pair(53, -17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -10), Pair(12, -16), Pair(14, -8),
  Pair(19, -10), Pair(12, -11), Pair(20, -11),
  Pair(12, 5), Pair(0, 0), Pair(13, 3),
  Pair(-17, 13), Pair(-53, 23), Pair(-36, 19)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-13, 9), Pair(-20, 20), Pair(-14, 15),
  Pair(-10, 5), Pair(-28, 24), Pair(-13, 10),
  Pair(1, -5), Pair(-11, 7), Pair(-1, -4),
  Pair(13, -7), Pair(-16, 2), Pair(13, -3),
  Pair(21, -22), Pair(41, -12), Pair(29, -22),
  Pair(0, 0), Pair(-97, 6), Pair(0, 0),
  Pair(30, -47), Pair(0, 0), Pair(32, -49)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(17, 38), Pair(-1, 37), Pair(0, 19), Pair(11, 8), Pair(-4, 15), Pair(18, 15), Pair(28, -3)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(20, -22), Pair(-4, 10), Pair(-2, 38), Pair(-6, 59), Pair(0, 68), Pair(2, 69), Pair(-3, 81)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-288, 244);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-172, 81), Pair(-109, 8), Pair(-26, -24), Pair(5, -31), Pair(1, -29), Pair(-10, -27), Pair(-50, 3), Pair(-85, 32)
  },
  {
      Pair(-100, 61), Pair(-23, 12), Pair(-38, 12), Pair(-1, -5), Pair(-15, -8), Pair(-11, 7), Pair(-26, 26), Pair(-28, 42)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -2), Pair(28, 2), Pair(72, -9), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 3), Pair(30, 6), Pair(56, 1), Pair(-18, 11), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -11), Pair(28, -11), Pair(55, -19), Pair(90, -24), Pair(87, -23), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 20), Pair(14, 33), Pair(43, 22), Pair(94, -1), Pair(166, -34), Pair(328, -112), Pair(434, -191)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(32, -5), Pair(13, 10), Pair(70, -17), Pair(25, -3), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-16, 28), Pair(2, 22)
  },
  {
      Pair(-82, -6), Pair(-73, -6)
  },
  {
      Pair(-56, -31), Pair(-65, -50)
  },
  {
      Pair(-79, -27), Pair(-59, -37)
  },
  {
      Pair(-54, 13), Pair(-58, -1)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(20, 35), Pair(22, 23), Pair(30, 19), Pair(33, -27), Pair(50, 8)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-4, -31), Pair(8, -14)
  },
  {
      Pair(-9, -49), Pair(-1, -64)
  },
  {
      Pair(-50, -3), Pair(-46, -15)
  },
  {
      Pair(-74, 7), Pair(-71, -2)
  },
  {
      Pair(-46, 5), Pair(-42, -7)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-23, -26), Pair(-3, -8)
  },
  {
      Pair(-49, 1), Pair(-24, -30)
  },
  {
      Pair(-24, -52), Pair(-13, -54)
  },
  {
      Pair(-56, -5), Pair(-58, -31)
  },
  {
      Pair(-57, -44), Pair(-53, -54)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-8, -27), Pair(14, -19)
  },
  {
      Pair(-47, -9), Pair(-7, -17)
  },
  {
      Pair(-58, 1), Pair(-11, -9)
  },
  {
      Pair(18, -71), Pair(16, -52)
  },
  {
      Pair(-65, -49), Pair(-57, -47)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(46, 32), Pair(10, 29), Pair(34, 25), Pair(31, 33), Pair(49, 27), Pair(-11, 27), Pair(48, 45), Pair(84, -17),
  Pair(44, 11), Pair(11, 2), Pair(-13, 53), Pair(2, 39), Pair(12, 67), Pair(-29, 53), Pair(15, 11), Pair(4, 37),
  Pair(4, -3), Pair(5, 40), Pair(-3, 22), Pair(15, 24), Pair(4, 18), Pair(-3, 19), Pair(-19, 40), Pair(14, -23)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-164, 15), Pair(9, 1), Pair(89, -25), Pair(37, -20), Pair(84, 2), Pair(-29, 15), Pair(49, 37), Pair(-112, 62),
  Pair(36, -9), Pair(15, 12), Pair(18, 6), Pair(7, -6), Pair(10, 6), Pair(-22, 33), Pair(23, 26), Pair(-6, 42),
  Pair(-50, 33), Pair(-26, 9), Pair(11, 16), Pair(30, 29), Pair(13, 28), Pair(2, 15), Pair(-14, 30), Pair(-31, 17)
};

constexpr ScorePair kBishopPairBonus = Pair(31, 50);

constexpr ScorePair kTempoBonus = Pair(23, 0);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H