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
  Pair(156, 118), Pair(543, -91), Pair(603, -31), Pair(841, 293), Pair(1713, 542), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(251, -73), Pair(52, -5), Pair(45, 9), Pair(53, -1), Pair(111, -7), Pair(18, 4), Pair(-94, 8), Pair(115, -77),
      Pair(-9, 0), Pair(-25, 10), Pair(7, -14), Pair(22, -6), Pair(41, -8), Pair(70, -16), Pair(17, 3), Pair(24, -23),
      Pair(-13, -17), Pair(13, -17), Pair(-9, -34), Pair(20, -46), Pair(26, -42), Pair(20, -46), Pair(1, -22), Pair(-24, -31),
      Pair(-35, -18), Pair(-17, -9), Pair(-5, -38), Pair(14, -42), Pair(15, -45), Pair(14, -37), Pair(-12, -16), Pair(-27, -27),
      Pair(-37, -15), Pair(-17, -11), Pair(-33, -23), Pair(-19, -32), Pair(-12, -24), Pair(-14, -26), Pair(3, -19), Pair(-26, -30),
      Pair(-34, -2), Pair(-2, 5), Pair(-27, -9), Pair(-15, -15), Pair(-19, -17), Pair(19, -6), Pair(22, -10), Pair(-27, -17),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-257, 148), Pair(41, 81), Pair(36, 51), Pair(111, 38), Pair(51, 53), Pair(-82, 66), Pair(-16, 70), Pair(-185, 78),
      Pair(43, 44), Pair(30, 80), Pair(101, 58), Pair(183, 39), Pair(163, 22), Pair(147, 28), Pair(47, 55), Pair(82, 6),
      Pair(41, 62), Pair(82, 63), Pair(139, 71), Pair(143, 78), Pair(167, 62), Pair(173, 54), Pair(97, 16), Pair(84, 38),
      Pair(106, 46), Pair(93, 36), Pair(127, 85), Pair(157, 70), Pair(131, 81), Pair(139, 76), Pair(112, 25), Pair(104, 43),
      Pair(79, 57), Pair(112, 42), Pair(120, 89), Pair(122, 81), Pair(128, 80), Pair(137, 67), Pair(136, 45), Pair(101, 46),
      Pair(54, 40), Pair(92, 52), Pair(86, 81), Pair(117, 80), Pair(121, 76), Pair(102, 79), Pair(107, 55), Pair(68, 40),
      Pair(39, 27), Pair(86, 42), Pair(76, 42), Pair(93, 49), Pair(101, 52), Pair(81, 40), Pair(89, 35), Pair(71, 47),
      Pair(51, -16), Pair(47, 40), Pair(77, 24), Pair(93, 36), Pair(104, 29), Pair(70, 45), Pair(50, 55), Pair(3, -3)
  },
  {
      Pair(28, 30), Pair(46, 41), Pair(-45, 72), Pair(-40, 68), Pair(-28, 64), Pair(-65, 59), Pair(-36, 72), Pair(-11, 54),
      Pair(38, 28), Pair(47, 58), Pair(59, 61), Pair(61, 64), Pair(32, 69), Pair(42, 63), Pair(53, 36), Pair(48, 5),
      Pair(65, 51), Pair(119, 30), Pair(72, 78), Pair(113, 57), Pair(99, 69), Pair(101, 65), Pair(111, 7), Pair(74, 51),
      Pair(51, 60), Pair(74, 70), Pair(71, 68), Pair(108, 84), Pair(93, 82), Pair(119, 41), Pair(67, 61), Pair(71, 48),
      Pair(75, 35), Pair(56, 69), Pair(80, 81), Pair(83, 65), Pair(78, 66), Pair(72, 69), Pair(89, 41), Pair(77, 39),
      Pair(56, 43), Pair(94, 54), Pair(76, 73), Pair(82, 69), Pair(70, 71), Pair(91, 64), Pair(96, 44), Pair(69, 42),
      Pair(97, 34), Pair(78, 41), Pair(91, 33), Pair(66, 57), Pair(83, 53), Pair(91, 35), Pair(106, 42), Pair(99, 2),
      Pair(60, 37), Pair(99, -10), Pair(56, 48), Pair(65, 42), Pair(93, 25), Pair(49, 58), Pair(105, 1), Pair(69, 13)
  },
  {
      Pair(135, -51), Pair(203, -60), Pair(209, -66), Pair(235, -81), Pair(224, -73), Pair(249, -93), Pair(178, -68), Pair(147, -56),
      Pair(125, -58), Pair(155, -63), Pair(187, -70), Pair(216, -86), Pair(222, -90), Pair(175, -81), Pair(102, -57), Pair(132, -59),
      Pair(115, -57), Pair(191, -70), Pair(159, -61), Pair(193, -81), Pair(184, -74), Pair(169, -73), Pair(143, -60), Pair(105, -54),
      Pair(128, -64), Pair(150, -66), Pair(167, -74), Pair(164, -74), Pair(173, -74), Pair(169, -83), Pair(127, -63), Pair(123, -61),
      Pair(82, -58), Pair(106, -59), Pair(107, -51), Pair(133, -73), Pair(108, -63), Pair(121, -70), Pair(105, -60), Pair(61, -49),
      Pair(68, -56), Pair(81, -47), Pair(82, -48), Pair(93, -62), Pair(97, -53), Pair(85, -67), Pair(84, -61), Pair(70, -62),
      Pair(57, -64), Pair(85, -69), Pair(98, -77), Pair(107, -77), Pair(107, -78), Pair(107, -85), Pair(72, -70), Pair(7, -55),
      Pair(88, -52), Pair(97, -57), Pair(99, -51), Pair(119, -66), Pair(115, -67), Pair(117, -73), Pair(51, -28), Pair(78, -48)
  },
  {
      Pair(140, -129), Pair(202, -175), Pair(234, -172), Pair(255, -155), Pair(265, -190), Pair(297, -215), Pair(306, -291), Pair(224, -178),
      Pair(127, -133), Pair(104, -87), Pair(152, -58), Pair(182, -89), Pair(150, -59), Pair(195, -90), Pair(205, -199), Pair(215, -166),
      Pair(134, -146), Pair(170, -108), Pair(115, -18), Pair(127, -12), Pair(149, -22), Pair(203, -71), Pair(191, -163), Pair(165, -146),
      Pair(154, -154), Pair(137, -88), Pair(130, -30), Pair(123, 10), Pair(136, -4), Pair(151, -63), Pair(188, -149), Pair(173, -151),
      Pair(144, -165), Pair(129, -96), Pair(138, -45), Pair(117, 8), Pair(132, -21), Pair(154, -87), Pair(179, -154), Pair(162, -150),
      Pair(149, -186), Pair(154, -139), Pair(133, -68), Pair(150, -105), Pair(145, -94), Pair(162, -116), Pair(165, -136), Pair(157, -170),
      Pair(170, -230), Pair(167, -180), Pair(171, -196), Pair(166, -169), Pair(174, -181), Pair(179, -198), Pair(178, -191), Pair(149, -259),
      Pair(184, -257), Pair(148, -239), Pair(164, -243), Pair(157, -213), Pair(163, -245), Pair(132, -262), Pair(134, -290), Pair(163, -294)
  },
  {
      Pair(-63, 10), Pair(-136, -5), Pair(-109, 25), Pair(-94, 65), Pair(-15, 52), Pair(14, 39), Pair(-176, -39), Pair(138, 100),
      Pair(60, 37), Pair(170, 78), Pair(147, 51), Pair(77, 93), Pair(8, 92), Pair(147, 67), Pair(46, 59), Pair(124, 78),
      Pair(30, 62), Pair(247, 87), Pair(85, 93), Pair(-32, 131), Pair(-13, 119), Pair(33, 98), Pair(222, 59), Pair(-65, 70),
      Pair(23, 62), Pair(255, 80), Pair(-83, 120), Pair(-93, 140), Pair(-84, 129), Pair(-9, 105), Pair(51, 74), Pair(-12, 55),
      Pair(30, 35), Pair(60, 98), Pair(33, 87), Pair(18, 112), Pair(16, 105), Pair(31, 82), Pair(96, 57), Pair(-16, 43),
      Pair(56, 25), Pair(84, 87), Pair(41, 70), Pair(40, 95), Pair(31, 94), Pair(48, 80), Pair(60, 67), Pair(29, 41),
      Pair(78, 19), Pair(23, 96), Pair(32, 75), Pair(7, 90), Pair(12, 86), Pair(16, 89), Pair(48, 79), Pair(75, 35),
      Pair(-38, -11), Pair(67, 71), Pair(61, 62), Pair(-9, 69), Pair(40, 45), Pair(0, 68), Pair(79, 57), Pair(73, 15)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(42, 9), Pair(73, 57), Pair(89, 81), Pair(101, 89), Pair(112, 94), Pair(119, 100), Pair(128, 83), Pair(137, 65),
  Pair(150, 24)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(35, 2), Pair(59, 21), Pair(73, 32), Pair(82, 44), Pair(91, 55), Pair(97, 60), Pair(103, 58), Pair(110, 48),
  Pair(121, 46), Pair(130, 28), Pair(148, 25), Pair(165, -5), Pair(253, -42), Pair(143, -27)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(32, -117), Pair(52, -79), Pair(59, -66), Pair(68, -48), Pair(72, -40), Pair(79, -35), Pair(84, -31), Pair(94, -33),
  Pair(98, -24), Pair(104, -24), Pair(111, -25), Pair(117, -27), Pair(147, -43), Pair(163, -43), Pair(296, -115)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(148, -306), Pair(156, -273), Pair(161, -194), Pair(163, -106), Pair(166, -75), Pair(167, -57), Pair(173, -41), Pair(177, -29),
  Pair(180, -20), Pair(184, -6), Pair(184, 0), Pair(186, 4), Pair(191, -5), Pair(194, -12), Pair(203, -28), Pair(221, -66),
  Pair(224, -76), Pair(251, -115), Pair(298, -175), Pair(317, -208), Pair(322, -212), Pair(428, -374), Pair(479, -401), Pair(397, -429),
  Pair(468, -458), Pair(308, -465), Pair(239, -470), Pair(18, -444)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-53, -37), Pair(-39, -32), Pair(-4, -24), Pair(47, -5), Pair(118, -9), Pair(172, 13), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(13, -7), Pair(22, 3), Pair(32, 18), Pair(75, 66), Pair(243, 161), Pair(31, 401), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(32, -1), Pair(24, -2), Pair(29, 14), Pair(84, 28), Pair(300, 6), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-73, -17), Pair(-15, -20), Pair(-13, -8), Pair(-40, 6), Pair(-17, 6), Pair(-35, 0), Pair(-14, -14), Pair(-39, -32)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(17, -2), Pair(-15, -17), Pair(-14, -1), Pair(-28, -9), Pair(-24, -14), Pair(-6, -14), Pair(-7, -16), Pair(0, 0)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(48, -11), Pair(50, -36), Pair(48, -28), Pair(35, -11), Pair(51, -27), Pair(60, -20), Pair(92, -35), Pair(67, -14)
  },
  {
      Pair(43, 5), Pair(40, -20), Pair(40, -19), Pair(40, -24), Pair(44, -29), Pair(25, -9), Pair(70, -35), Pair(46, -7)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(21, -13), Pair(24, -23), Pair(20, -15),
  Pair(28, -15), Pair(24, -10), Pair(28, -17),
  Pair(23, 1), Pair(0, 0), Pair(24, 0),
  Pair(-22, 11), Pair(-55, 16), Pair(-38, 13)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-12, 0), Pair(-20, 9), Pair(-12, 6),
  Pair(-12, 5), Pair(-29, 17), Pair(-15, 12),
  Pair(-4, -1), Pair(-15, 6), Pair(-1, 1),
  Pair(14, -7), Pair(-16, -4), Pair(11, -4),
  Pair(50, -30), Pair(46, -17), Pair(38, -33),
  Pair(0, 0), Pair(-76, -24), Pair(0, 0),
  Pair(13, -54), Pair(0, 0), Pair(-6, -54)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-3, 29), Pair(-24, 28), Pair(-10, 9), Pair(-12, 6), Pair(-27, 18), Pair(2, 23), Pair(1, 2)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-38, 6), Pair(-45, 34), Pair(-20, 58), Pair(-2, 63), Pair(23, 51), Pair(34, 43), Pair(2, 49)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-40, 353);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-173, 20), Pair(-116, -41), Pair(-29, -14), Pair(-12, -30), Pair(-17, -15), Pair(-57, 12), Pair(-99, 26), Pair(-108, 45)
  },
  {
      Pair(-173, 116), Pair(-37, -7), Pair(-26, 8), Pair(-41, 3), Pair(-6, -4), Pair(-19, 19), Pair(-32, 30), Pair(-72, 69)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(17, -2), Pair(28, -2), Pair(45, -2), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 2), Pair(29, 3), Pair(53, 2), Pair(6, 18), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(27, -19), Pair(59, -38), Pair(81, -33), Pair(162, -68), Pair(120, -66), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 7), Pair(28, -2), Pair(51, 6), Pair(124, 14), Pair(201, 1), Pair(252, 44), Pair(272, 62)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(35, -3), Pair(12, 12), Pair(135, -57), Pair(38, -25), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-11, 59), Pair(1, 55)
  },
  {
      Pair(-116, 11), Pair(-91, -15)
  },
  {
      Pair(-84, -41), Pair(-81, -70)
  },
  {
      Pair(-157, 17), Pair(-108, -12)
  },
  {
      Pair(-74, -23), Pair(-80, 23)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(20, 46), Pair(29, 37), Pair(46, 1), Pair(28, 3), Pair(19, 18)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-7, -50), Pair(11, -24)
  },
  {
      Pair(24, -56), Pair(24, -84)
  },
  {
      Pair(-71, -2), Pair(-55, -32)
  },
  {
      Pair(-127, 33), Pair(-84, 1)
  },
  {
      Pair(-60, -40), Pair(-54, 14)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-21, -39), Pair(-2, -7)
  },
  {
      Pair(-75, 7), Pair(-30, -33)
  },
  {
      Pair(15, -46), Pair(19, -69)
  },
  {
      Pair(-102, 18), Pair(-84, -23)
  },
  {
      Pair(-80, -25), Pair(-69, -91)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(14, -68), Pair(27, -42)
  },
  {
      Pair(-58, -10), Pair(-1, -30)
  },
  {
      Pair(-61, -16), Pair(-14, -16)
  },
  {
      Pair(-19, 45), Pair(-15, 52)
  },
  {
      Pair(-95, -17), Pair(-88, -12)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(66, 8), Pair(16, 21), Pair(14, 53), Pair(8, 41), Pair(0, 66), Pair(45, 51), Pair(32, 71), Pair(96, 47),
  Pair(23, 27), Pair(25, 36), Pair(14, 22), Pair(-17, 56), Pair(7, 47), Pair(-14, 50), Pair(8, 50), Pair(20, 17),
  Pair(17, 0), Pair(2, 24), Pair(8, 24), Pair(17, 19), Pair(-7, 43), Pair(-1, 17), Pair(-20, 23), Pair(21, 2)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-11, 66), Pair(33, 15), Pair(4, 9), Pair(64, -18), Pair(67, -13), Pair(101, 6), Pair(46, 40), Pair(-102, 86),
  Pair(67, -60), Pair(20, 5), Pair(26, 17), Pair(31, 5), Pair(18, 15), Pair(0, 30), Pair(13, 29), Pair(10, 53),
  Pair(-44, 85), Pair(22, -3), Pair(4, -2), Pair(6, 25), Pair(46, 4), Pair(-5, 20), Pair(-9, 20), Pair(-12, 55)
};

constexpr ScorePair kBishopPairBonus = Pair(40, 48);

constexpr ScorePair kTempoBonus = Pair(27, 0);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H