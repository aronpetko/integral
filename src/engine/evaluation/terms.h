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
  Pair(124, 113), Pair(430, 66), Pair(482, 95), Pair(641, 431), Pair(1264, 782), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(132, -40), Pair(68, 22), Pair(35, 30), Pair(11, 24), Pair(34, 20), Pair(-18, 37), Pair(-30, 45), Pair(150, -67),
      Pair(1, -16), Pair(-13, 7), Pair(-2, -9), Pair(17, -18), Pair(13, -22), Pair(30, -13), Pair(17, -12), Pair(22, -28),
      Pair(-11, -21), Pair(-1, -9), Pair(-4, -32), Pair(2, -31), Pair(21, -35), Pair(11, -30), Pair(6, -21), Pair(-13, -18),
      Pair(-25, -32), Pair(-15, -12), Pair(-6, -36), Pair(6, -29), Pair(9, -42), Pair(5, -29), Pair(4, -25), Pair(-12, -26),
      Pair(-31, -29), Pair(-21, -11), Pair(-28, -26), Pair(-22, -28), Pair(-10, -31), Pair(-22, -22), Pair(9, -29), Pair(-14, -24),
      Pair(-27, -22), Pair(-2, -6), Pair(-16, -20), Pair(-21, -18), Pair(-15, -22), Pair(9, -19), Pair(26, -27), Pair(-15, -25),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-158, 70), Pair(12, 27), Pair(-19, 43), Pair(52, 29), Pair(78, -3), Pair(110, -4), Pair(1, 18), Pair(-53, 2),
      Pair(37, 11), Pair(15, 32), Pair(92, 20), Pair(118, 22), Pair(108, 37), Pair(126, -3), Pair(65, 18), Pair(27, 25),
      Pair(70, 16), Pair(78, 25), Pair(90, 57), Pair(108, 27), Pair(137, 30), Pair(123, 35), Pair(61, 45), Pair(95, -5),
      Pair(56, 31), Pair(72, 39), Pair(79, 49), Pair(99, 50), Pair(105, 32), Pair(122, 26), Pair(82, 38), Pair(80, 33),
      Pair(52, 34), Pair(101, 16), Pair(92, 45), Pair(92, 47), Pair(94, 52), Pair(105, 45), Pair(106, 25), Pair(66, 39),
      Pair(28, 18), Pair(60, 32), Pair(60, 51), Pair(80, 49), Pair(84, 43), Pair(74, 41), Pair(71, 26), Pair(45, 31),
      Pair(-3, 16), Pair(59, 13), Pair(59, 13), Pair(66, 30), Pair(66, 28), Pair(62, 9), Pair(43, 18), Pair(38, 18),
      Pair(23, -23), Pair(19, 34), Pair(29, 17), Pair(46, 29), Pair(59, 19), Pair(59, 12), Pair(20, 35), Pair(-2, -1)
  },
  {
      Pair(-29, 63), Pair(-41, 57), Pair(6, 34), Pair(-71, 41), Pair(22, 32), Pair(-87, 49), Pair(24, 38), Pair(17, 46),
      Pair(-8, 46), Pair(37, 43), Pair(49, 34), Pair(62, 38), Pair(9, 37), Pair(64, 34), Pair(-6, 55), Pair(-2, 25),
      Pair(30, 39), Pair(53, 28), Pair(48, 46), Pair(64, 36), Pair(84, 23), Pair(66, 43), Pair(71, 3), Pair(54, 32),
      Pair(40, 30), Pair(46, 38), Pair(53, 43), Pair(67, 56), Pair(53, 51), Pair(76, 12), Pair(43, 37), Pair(51, 31),
      Pair(53, 29), Pair(50, 38), Pair(52, 39), Pair(52, 48), Pair(64, 36), Pair(47, 48), Pair(52, 33), Pair(51, 27),
      Pair(43, 28), Pair(61, 34), Pair(53, 43), Pair(59, 38), Pair(53, 41), Pair(65, 40), Pair(72, 28), Pair(53, 34),
      Pair(59, 23), Pair(59, 17), Pair(68, 10), Pair(48, 27), Pair(62, 27), Pair(76, 10), Pair(75, 19), Pair(33, 47),
      Pair(34, 14), Pair(79, -1), Pair(37, 31), Pair(44, 23), Pair(49, 27), Pair(32, 35), Pair(28, 5), Pair(54, 19)
  },
  {
      Pair(110, -33), Pair(117, -33), Pair(128, -33), Pair(137, -44), Pair(170, -53), Pair(172, -57), Pair(117, -35), Pair(78, -32),
      Pair(93, -31), Pair(101, -29), Pair(126, -34), Pair(146, -42), Pair(138, -46), Pair(142, -50), Pair(102, -31), Pair(85, -35),
      Pair(94, -37), Pair(114, -39), Pair(113, -38), Pair(133, -49), Pair(160, -65), Pair(138, -44), Pair(105, -35), Pair(75, -39),
      Pair(81, -43), Pair(110, -44), Pair(130, -48), Pair(142, -66), Pair(138, -61), Pair(123, -50), Pair(100, -36), Pair(82, -44),
      Pair(58, -41), Pair(92, -39), Pair(73, -29), Pair(82, -37), Pair(88, -50), Pair(64, -29), Pair(63, -30), Pair(36, -35),
      Pair(41, -41), Pair(64, -44), Pair(49, -34), Pair(58, -44), Pair(67, -55), Pair(61, -46), Pair(69, -49), Pair(48, -53),
      Pair(53, -57), Pair(68, -54), Pair(75, -56), Pair(70, -60), Pair(86, -73), Pair(78, -68), Pair(60, -69), Pair(5, -56),
      Pair(60, -51), Pair(72, -58), Pair(72, -51), Pair(87, -66), Pair(94, -75), Pair(85, -66), Pair(51, -48), Pair(56, -60)
  },
  {
      Pair(120, -92), Pair(134, -72), Pair(174, -99), Pair(177, -93), Pair(142, -51), Pair(200, -100), Pair(155, -76), Pair(132, -86),
      Pair(124, -81), Pair(108, -30), Pair(151, -46), Pair(109, -4), Pair(117, -6), Pair(154, -44), Pair(147, -64), Pair(171, -108),
      Pair(150, -130), Pair(147, -77), Pair(131, -27), Pair(140, -20), Pair(154, -23), Pair(149, -22), Pair(194, -110), Pair(163, -125),
      Pair(137, -113), Pair(153, -86), Pair(137, -37), Pair(122, -6), Pair(141, -27), Pair(161, -62), Pair(147, -83), Pair(177, -142),
      Pair(143, -135), Pair(129, -90), Pair(146, -83), Pair(138, -50), Pair(142, -59), Pair(149, -76), Pair(162, -116), Pair(143, -110),
      Pair(135, -149), Pair(155, -145), Pair(142, -95), Pair(149, -115), Pair(147, -98), Pair(155, -102), Pair(157, -120), Pair(146, -147),
      Pair(152, -187), Pair(155, -184), Pair(160, -165), Pair(162, -170), Pair(161, -159), Pair(172, -212), Pair(184, -238), Pair(157, -215),
      Pair(160, -191), Pair(152, -209), Pair(149, -197), Pair(149, -163), Pair(156, -210), Pair(148, -251), Pair(179, -264), Pair(178, -207)
  },
  {
      Pair(-152, -1), Pair(-113, 131), Pair(-34, 93), Pair(-48, 59), Pair(91, 42), Pair(220, 16), Pair(181, 19), Pair(-16, -83),
      Pair(-25, -8), Pair(169, 12), Pair(120, 13), Pair(1, 21), Pair(169, 3), Pair(153, -15), Pair(268, -42), Pair(108, -75),
      Pair(51, -22), Pair(180, -20), Pair(130, -10), Pair(-25, 17), Pair(-130, 27), Pair(-108, 6), Pair(262, -72), Pair(145, -73),
      Pair(89, -57), Pair(79, -22), Pair(-41, 26), Pair(-86, 22), Pair(-122, 24), Pair(-29, 4), Pair(71, -32), Pair(-1, -54),
      Pair(51, -74), Pair(42, -24), Pair(-3, 9), Pair(-86, 31), Pair(-77, 19), Pair(-12, 1), Pair(34, -30), Pair(-84, -42),
      Pair(-33, -40), Pair(16, -15), Pair(-22, 9), Pair(-41, 20), Pair(-52, 25), Pair(-30, 7), Pair(-9, -10), Pair(-44, -36),
      Pair(-12, -19), Pair(-32, 10), Pair(-33, 12), Pair(-70, 29), Pair(-73, 31), Pair(-64, 26), Pair(-32, 7), Pair(-14, -26),
      Pair(-68, 49), Pair(11, -9), Pair(-14, 11), Pair(-97, 25), Pair(-47, 9), Pair(-81, 18), Pair(-10, 0), Pair(-18, -11)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(22, -28), Pair(54, 20), Pair(68, 41), Pair(76, 55), Pair(82, 62), Pair(87, 69), Pair(94, 61), Pair(98, 51),
  Pair(112, 10)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(16, -20), Pair(40, -11), Pair(49, 9), Pair(56, 26), Pair(64, 34), Pair(69, 42), Pair(72, 40), Pair(76, 40),
  Pair(83, 41), Pair(95, 32), Pair(112, 25), Pair(112, 9), Pair(189, -16), Pair(92, -4)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(17, -86), Pair(35, -74), Pair(41, -66), Pair(48, -53), Pair(48, -37), Pair(53, -32), Pair(56, -28), Pair(63, -27),
  Pair(67, -20), Pair(76, -22), Pair(83, -23), Pair(88, -23), Pair(95, -21), Pair(120, -36), Pair(233, -83)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(128, -12), Pair(117, -203), Pair(124, -104), Pair(129, -82), Pair(134, -79), Pair(139, -64), Pair(139, -23), Pair(144, -12),
  Pair(146, -2), Pair(150, 6), Pair(152, 7), Pair(157, 8), Pair(162, 1), Pair(160, 10), Pair(166, -1), Pair(174, -12),
  Pair(181, -24), Pair(193, -43), Pair(211, -75), Pair(234, -112), Pair(266, -147), Pair(332, -236), Pair(332, -220), Pair(339, -286),
  Pair(343, -282), Pair(358, -352), Pair(246, -272), Pair(98, -287)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-23, -42), Pair(-19, -29), Pair(-7, -1), Pair(24, 24), Pair(79, 47), Pair(147, 26), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(9, 7), Pair(21, 2), Pair(25, 19), Pair(59, 52), Pair(259, 94), Pair(150, 581), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(27, 3), Pair(21, 2), Pair(26, 11), Pair(59, 26), Pair(279, -15), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-56, -27), Pair(-7, -17), Pair(-3, -23), Pair(-11, -13), Pair(-16, -7), Pair(-18, -3), Pair(-18, -22), Pair(-44, -28)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(15, -1), Pair(-6, -18), Pair(-17, 4), Pair(-11, -15), Pair(-14, -9), Pair(3, -13), Pair(-11, -5), Pair(5, -10)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(34, -7), Pair(30, -9), Pair(34, -7), Pair(28, -1), Pair(28, 9), Pair(34, 1), Pair(58, -16), Pair(63, -10)
  },
  {
      Pair(27, 2), Pair(22, -11), Pair(36, -18), Pair(29, -14), Pair(26, -11), Pair(25, -12), Pair(47, -24), Pair(41, -3)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -8), Pair(18, -17), Pair(17, -9),
  Pair(23, -12), Pair(19, -11), Pair(21, -9),
  Pair(23, 3), Pair(0, 0), Pair(26, 4),
  Pair(-16, 14), Pair(-52, 27), Pair(-15, 15)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-9, 2), Pair(-21, 17), Pair(-8, 10),
  Pair(-12, 5), Pair(-28, 17), Pair(-9, 6),
  Pair(-3, -4), Pair(-16, 7), Pair(1, -5),
  Pair(10, -7), Pair(-16, 2), Pair(11, -7),
  Pair(35, -24), Pair(42, -10), Pair(34, -26),
  Pair(0, 0), Pair(-94, 0), Pair(0, 0),
  Pair(77, -60), Pair(0, 0), Pair(75, -67)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(15, 14), Pair(-13, 18), Pair(-8, -3), Pair(-2, -15), Pair(-9, -11), Pair(9, -13), Pair(9, -25)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-14, -18), Pair(-8, 10), Pair(-5, 39), Pair(3, 54), Pair(-2, 67), Pair(-3, 77), Pair(-7, 84)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-212, 247);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-172, 77), Pair(-68, 8), Pair(-13, -25), Pair(1, -32), Pair(-16, -27), Pair(-20, -22), Pair(-77, 9), Pair(-85, 40)
  },
  {
      Pair(-45, 52), Pair(-37, 18), Pair(-22, 5), Pair(-8, -6), Pair(-10, -6), Pair(-6, 6), Pair(-27, 17), Pair(-30, 53)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(18, -4), Pair(28, -6), Pair(57, -17), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(14, 1), Pair(27, 5), Pair(47, 4), Pair(-32, 7), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(24, -16), Pair(37, -19), Pair(61, -21), Pair(92, -26), Pair(83, -29), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 18), Pair(13, 31), Pair(38, 21), Pair(109, -29), Pair(154, -38), Pair(309, -106), Pair(303, -113)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(40, -7), Pair(19, 11), Pair(76, -20), Pair(34, -12), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-5, 53), Pair(0, 59)
  },
  {
      Pair(-95, 5), Pair(-79, -8)
  },
  {
      Pair(-63, -46), Pair(-73, -44)
  },
  {
      Pair(-113, -17), Pair(-84, -11)
  },
  {
      Pair(-66, -4), Pair(-60, 1)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(19, 38), Pair(26, 28), Pair(41, 10), Pair(29, -26), Pair(50, 7)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-7, -35), Pair(10, -19)
  },
  {
      Pair(16, -23), Pair(10, -20)
  },
  {
      Pair(-58, 1), Pair(-42, -22)
  },
  {
      Pair(-90, 16), Pair(-76, 5)
  },
  {
      Pair(-58, 12), Pair(-48, -7)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-17, -28), Pair(-1, -11)
  },
  {
      Pair(-69, 9), Pair(-28, -24)
  },
  {
      Pair(5, -42), Pair(20, -52)
  },
  {
      Pair(-77, -4), Pair(-66, -27)
  },
  {
      Pair(-68, -21), Pair(-64, -41)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-9, -28), Pair(15, -19)
  },
  {
      Pair(-59, -7), Pair(-7, -18)
  },
  {
      Pair(-53, -9), Pair(-19, -3)
  },
  {
      Pair(20, -63), Pair(21, -39)
  },
  {
      Pair(-48, -92), Pair(-63, -63)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-31, 34), Pair(-18, 39), Pair(28, 26), Pair(10, 45), Pair(31, 38), Pair(26, 60), Pair(45, 23), Pair(-56, 81),
  Pair(34, 58), Pair(24, 12), Pair(13, 30), Pair(7, 43), Pair(-5, 55), Pair(-15, 46), Pair(9, 22), Pair(23, 6),
  Pair(19, 12), Pair(-35, 21), Pair(0, 32), Pair(11, 24), Pair(3, 26), Pair(-3, 15), Pair(1, 9), Pair(21, -2)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-70, 20), Pair(-2, 30), Pair(17, -2), Pair(71, -14), Pair(69, -30), Pair(16, 6), Pair(30, 41), Pair(-3, 52),
  Pair(-95, 52), Pair(25, 14), Pair(31, 4), Pair(43, -8), Pair(30, 2), Pair(17, 40), Pair(17, 20), Pair(-16, -5),
  Pair(-39, 32), Pair(-10, 26), Pair(17, 21), Pair(25, 11), Pair(23, 16), Pair(-5, 9), Pair(5, -1), Pair(-69, -37)
};

constexpr ScorePair kBishopPairBonus = Pair(23, 62);

constexpr ScorePair kTempoBonus = Pair(21, 1);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H