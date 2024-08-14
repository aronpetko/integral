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
  Pair(155, 104), Pair(443, -42), Pair(504, -19), Pair(674, 412), Pair(1413, 752), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(178, -46), Pair(102, 28), Pair(72, 22), Pair(43, 31), Pair(42, 47), Pair(-41, 63), Pair(-62, 65), Pair(117, -54),
      Pair(-4, -3), Pair(-10, 21), Pair(3, 0), Pair(11, 0), Pair(0, 1), Pair(27, -6), Pair(-3, 13), Pair(8, -14),
      Pair(-23, 0), Pair(-5, 3), Pair(-13, -12), Pair(3, -19), Pair(11, -16), Pair(-5, -12), Pair(6, -10), Pair(-34, -7),
      Pair(-27, -13), Pair(-17, 3), Pair(-15, -16), Pair(-2, -20), Pair(-1, -24), Pair(0, -12), Pair(-6, -8), Pair(-37, -11),
      Pair(-30, -17), Pair(-17, 1), Pair(-33, -3), Pair(-30, -9), Pair(-17, -10), Pair(-19, -5), Pair(15, -16), Pair(-29, -14),
      Pair(-34, -3), Pair(-4, 6), Pair(-28, 3), Pair(-31, 0), Pair(-26, -7), Pair(4, 0), Pair(28, -15), Pair(-35, -10),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-228, 159), Pair(-19, 128), Pair(-2, 101), Pair(103, 75), Pair(156, 71), Pair(6, 107), Pair(130, 88), Pair(-24, 88),
      Pair(18, 114), Pair(56, 92), Pair(123, 92), Pair(162, 94), Pair(103, 120), Pair(173, 64), Pair(23, 113), Pair(77, 90),
      Pair(68, 89), Pair(113, 86), Pair(105, 138), Pair(159, 103), Pair(169, 104), Pair(179, 104), Pair(96, 111), Pair(125, 63),
      Pair(98, 97), Pair(98, 110), Pair(129, 118), Pair(132, 124), Pair(132, 111), Pair(152, 94), Pair(117, 88), Pair(97, 99),
      Pair(81, 93), Pair(120, 96), Pair(122, 125), Pair(132, 122), Pair(127, 124), Pair(135, 120), Pair(145, 79), Pair(96, 101),
      Pair(62, 70), Pair(89, 98), Pair(90, 123), Pair(112, 122), Pair(122, 118), Pair(104, 116), Pair(107, 94), Pair(75, 91),
      Pair(69, 74), Pair(64, 94), Pair(81, 92), Pair(94, 106), Pair(97, 96), Pair(101, 82), Pair(92, 89), Pair(81, 94),
      Pair(-4, 57), Pair(54, 85), Pair(66, 76), Pair(75, 97), Pair(86, 93), Pair(89, 80), Pair(55, 91), Pair(33, 61)
  },
  {
      Pair(10, 106), Pair(-1, 115), Pair(10, 102), Pair(15, 100), Pair(29, 96), Pair(-70, 112), Pair(56, 107), Pair(8, 111),
      Pair(39, 96), Pair(42, 106), Pair(70, 91), Pair(86, 103), Pair(61, 103), Pair(67, 95), Pair(20, 121), Pair(29, 76),
      Pair(42, 93), Pair(90, 83), Pair(82, 110), Pair(110, 103), Pair(105, 105), Pair(101, 92), Pair(93, 64), Pair(77, 91),
      Pair(70, 89), Pair(66, 105), Pair(95, 100), Pair(98, 107), Pair(100, 111), Pair(112, 80), Pair(72, 95), Pair(66, 87),
      Pair(82, 82), Pair(59, 100), Pair(78, 101), Pair(81, 106), Pair(95, 92), Pair(74, 106), Pair(96, 86), Pair(70, 81),
      Pair(65, 84), Pair(91, 86), Pair(75, 103), Pair(75, 103), Pair(76, 112), Pair(87, 94), Pair(95, 85), Pair(68, 87),
      Pair(91, 70), Pair(85, 68), Pair(90, 68), Pair(71, 92), Pair(84, 85), Pair(93, 80), Pair(98, 77), Pair(60, 67),
      Pair(67, 69), Pair(92, 48), Pair(57, 88), Pair(71, 84), Pair(75, 89), Pair(50, 98), Pair(56, 56), Pair(46, 62)
  },
  {
      Pair(152, -23), Pair(194, -33), Pair(206, -20), Pair(207, -41), Pair(219, -43), Pair(241, -57), Pair(181, -31), Pair(176, -30),
      Pair(135, -17), Pair(159, -25), Pair(182, -26), Pair(207, -40), Pair(203, -44), Pair(164, -30), Pair(129, -11), Pair(119, -20),
      Pair(114, -16), Pair(169, -35), Pair(160, -29), Pair(184, -50), Pair(186, -57), Pair(202, -46), Pair(139, -22), Pair(96, -19),
      Pair(124, -27), Pair(152, -30), Pair(151, -25), Pair(177, -43), Pair(158, -44), Pair(177, -44), Pair(124, -25), Pair(99, -19),
      Pair(92, -25), Pair(114, -26), Pair(120, -25), Pair(124, -32), Pair(123, -35), Pair(112, -26), Pair(81, -16), Pair(64, -24),
      Pair(92, -35), Pair(120, -44), Pair(105, -30), Pair(98, -37), Pair(97, -39), Pair(94, -37), Pair(90, -24), Pair(72, -38),
      Pair(81, -56), Pair(107, -52), Pair(122, -66), Pair(120, -64), Pair(113, -69), Pair(116, -65), Pair(91, -49), Pair(26, -32),
      Pair(101, -48), Pair(115, -56), Pair(111, -44), Pair(127, -58), Pair(127, -74), Pair(118, -59), Pair(70, -32), Pair(84, -51)
  },
  {
      Pair(160, -80), Pair(220, -104), Pair(208, -82), Pair(220, -106), Pair(282, -125), Pair(272, -145), Pair(223, -98), Pair(221, -116),
      Pair(160, -102), Pair(130, -19), Pair(175, -26), Pair(199, -40), Pair(205, -37), Pair(205, -60), Pair(189, -68), Pair(224, -127),
      Pair(169, -95), Pair(182, -80), Pair(182, -32), Pair(187, -21), Pair(210, -40), Pair(232, -57), Pair(213, -68), Pair(212, -112),
      Pair(184, -129), Pair(177, -85), Pair(188, -47), Pair(183, -14), Pair(194, -34), Pair(201, -53), Pair(202, -100), Pair(210, -112),
      Pair(185, -113), Pair(177, -107), Pair(185, -82), Pair(177, -43), Pair(182, -63), Pair(191, -93), Pair(206, -117), Pair(180, -122),
      Pair(180, -139), Pair(198, -161), Pair(185, -107), Pair(188, -123), Pair(184, -100), Pair(203, -124), Pair(202, -128), Pair(180, -148),
      Pair(171, -170), Pair(206, -209), Pair(206, -202), Pair(203, -186), Pair(205, -165), Pair(219, -226), Pair(205, -241), Pair(209, -217),
      Pair(196, -190), Pair(197, -229), Pair(194, -233), Pair(193, -209), Pair(190, -229), Pair(189, -283), Pair(225, -316), Pair(199, -240)
  },
  {
      Pair(-269, 44), Pair(-18, 93), Pair(186, 60), Pair(54, 68), Pair(32, 27), Pair(212, 26), Pair(227, 5), Pair(-20, -140),
      Pair(-21, -47), Pair(180, 30), Pair(47, 40), Pair(84, 48), Pair(116, 20), Pair(-78, -9), Pair(206, -5), Pair(-29, -64),
      Pair(111, -53), Pair(232, -32), Pair(105, 12), Pair(-130, 36), Pair(-128, 31), Pair(-57, 7), Pair(153, -49), Pair(-16, -43),
      Pair(116, -83), Pair(106, -27), Pair(-37, 23), Pair(-162, 45), Pair(-79, 15), Pair(-34, 4), Pair(102, -33), Pair(-28, -59),
      Pair(-4, -68), Pair(76, -33), Pair(-6, 1), Pair(-74, 28), Pair(-48, 12), Pair(13, -6), Pair(5, -23), Pair(-27, -68),
      Pair(-14, -51), Pair(3, -14), Pair(-28, 6), Pair(-43, 21), Pair(-44, 18), Pair(-46, 15), Pair(-3, -10), Pair(-49, -37),
      Pair(-6, -27), Pair(-36, 8), Pair(-58, 25), Pair(-81, 31), Pair(-78, 26), Pair(-62, 28), Pair(-35, 13), Pair(-20, -24),
      Pair(-101, 79), Pair(3, 0), Pair(-11, 3), Pair(-98, 23), Pair(-34, -8), Pair(-84, 17), Pair(-10, 1), Pair(-27, -8)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(75, 43), Pair(91, 55), Pair(102, 78), Pair(110, 92), Pair(116, 99), Pair(120, 106), Pair(128, 99), Pair(132, 87),
  Pair(148, 52)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(63, 35), Pair(79, 43), Pair(88, 56), Pair(94, 72), Pair(100, 82), Pair(105, 89), Pair(107, 92), Pair(112, 89),
  Pair(118, 91), Pair(134, 79), Pair(150, 75), Pair(167, 53), Pair(211, 47), Pair(111, 31)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(49, -116), Pair(66, -66), Pair(70, -48), Pair(77, -28), Pair(82, -18), Pair(86, -12), Pair(89, -9), Pair(99, -8),
  Pair(102, 1), Pair(114, -4), Pair(126, -8), Pair(133, -10), Pair(132, -2), Pair(166, -25), Pair(288, -77)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(167, 52), Pair(175, -139), Pair(179, -104), Pair(184, -102), Pair(184, -72), Pair(186, -50), Pair(189, -37), Pair(192, -8),
  Pair(195, -6), Pair(198, 11), Pair(199, 14), Pair(200, 17), Pair(203, 12), Pair(204, 19), Pair(210, 4), Pair(211, 0),
  Pair(216, -11), Pair(238, -40), Pair(254, -77), Pair(295, -122), Pair(332, -160), Pair(417, -259), Pair(392, -234), Pair(449, -342),
  Pair(440, -350), Pair(442, -405), Pair(382, -352), Pair(75, -352)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-16, -53), Pair(-20, -38), Pair(4, -12), Pair(55, 11), Pair(99, 37), Pair(141, 47), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 4), Pair(16, -1), Pair(23, 20), Pair(62, 56), Pair(150, 118), Pair(327, 453), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(23, 4), Pair(18, 3), Pair(26, 10), Pair(73, 26), Pair(200, 8), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-89, -22), Pair(-15, -28), Pair(-26, -14), Pair(-39, 8), Pair(-27, -3), Pair(-14, -18), Pair(-28, -7), Pair(-33, -27)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(22, -3), Pair(-10, -13), Pair(-14, -6), Pair(-16, -13), Pair(-19, -11), Pair(-10, -8), Pair(-18, -2), Pair(9, -6)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(33, -10), Pair(20, -11), Pair(37, -6), Pair(28, 0), Pair(39, 4), Pair(47, -3), Pair(68, -22), Pair(80, -19)
  },
  {
      Pair(35, 6), Pair(16, -1), Pair(31, -9), Pair(26, -8), Pair(32, -4), Pair(34, -14), Pair(65, -33), Pair(44, -6)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(18, -11), Pair(16, -22), Pair(16, -10),
  Pair(26, -12), Pair(21, -11), Pair(24, -9),
  Pair(26, 3), Pair(0, 0), Pair(23, 7),
  Pair(-12, 17), Pair(-63, 27), Pair(-1, 14)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-14, 9), Pair(-21, 20), Pair(-14, 16),
  Pair(-17, 12), Pair(-28, 23), Pair(-15, 13),
  Pair(-2, -3), Pair(-14, 11), Pair(-1, -1),
  Pair(14, -8), Pair(-18, 1), Pair(11, -5),
  Pair(29, -28), Pair(38, -13), Pair(37, -31),
  Pair(0, 0), Pair(-92, -1), Pair(0, 0),
  Pair(78, -69), Pair(0, 0), Pair(122, -83)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(12, 10), Pair(-21, 16), Pair(-18, -6), Pair(-22, -16), Pair(-19, -13), Pair(-3, -19), Pair(-11, -26)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-30, -5), Pair(-15, 27), Pair(-21, 57), Pair(-6, 75), Pair(-4, 83), Pair(-3, 90), Pair(-32, 95)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-85, 287);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-229, 90), Pair(-56, 0), Pair(-12, -28), Pair(0, -40), Pair(-19, -27), Pair(-14, -30), Pair(-56, -5), Pair(-101, 40)
  },
  {
      Pair(-113, 73), Pair(-44, 23), Pair(-23, 1), Pair(-9, -10), Pair(-11, -3), Pair(-16, 8), Pair(-27, 14), Pair(-53, 57)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -3), Pair(28, -3), Pair(74, -15), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 2), Pair(25, 6), Pair(38, 6), Pair(2, 5), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(17, -18), Pair(30, -17), Pair(52, -20), Pair(82, -24), Pair(86, -29), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 7), Pair(24, 20), Pair(42, 23), Pair(117, -18), Pair(189, -39), Pair(373, -124), Pair(298, -87)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(28, -5), Pair(9, 14), Pair(75, -21), Pair(29, -7), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-23, 61), Pair(-8, 67)
  },
  {
      Pair(-99, -12), Pair(-80, -32)
  },
  {
      Pair(-66, -33), Pair(-66, -52)
  },
  {
      Pair(-105, -37), Pair(-80, -49)
  },
  {
      Pair(-42, -26), Pair(-58, 39)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(17, 38), Pair(29, 15), Pair(34, 19), Pair(26, -21), Pair(46, 10)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-6, -43), Pair(7, -17)
  },
  {
      Pair(-9, -19), Pair(2, -31)
  },
  {
      Pair(-59, -6), Pair(-45, -32)
  },
  {
      Pair(-96, -6), Pair(-78, -20)
  },
  {
      Pair(-48, -56), Pair(-45, -41)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-25, -34), Pair(-2, -11)
  },
  {
      Pair(-71, 5), Pair(-23, -36)
  },
  {
      Pair(-26, -9), Pair(-13, -35)
  },
  {
      Pair(-72, -28), Pair(-78, -51)
  },
  {
      Pair(-64, -43), Pair(-61, -40)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-10, -37), Pair(13, -18)
  },
  {
      Pair(-80, 4), Pair(-11, -17)
  },
  {
      Pair(-64, 3), Pair(-21, -5)
  },
  {
      Pair(11, -43), Pair(17, -28)
  },
  {
      Pair(-68, -71), Pair(-74, -65)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(81, 35), Pair(-34, 33), Pair(38, 19), Pair(-10, 40), Pair(3, 42), Pair(-27, 55), Pair(2, 36), Pair(-22, 84),
  Pair(-16, 37), Pair(15, 9), Pair(2, 33), Pair(-2, 38), Pair(-9, 56), Pair(-16, 53), Pair(4, 32), Pair(43, -28),
  Pair(19, 16), Pair(-15, 17), Pair(-1, 23), Pair(2, 30), Pair(3, 27), Pair(0, 13), Pair(-22, 35), Pair(10, -19)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-43, 42), Pair(69, 19), Pair(34, 6), Pair(36, 10), Pair(14, -35), Pair(17, 20), Pair(54, 24), Pair(70, -45),
  Pair(69, 22), Pair(19, 24), Pair(18, 20), Pair(10, 29), Pair(4, 12), Pair(0, 28), Pair(15, 29), Pair(23, -28),
  Pair(-17, 32), Pair(9, 24), Pair(10, 14), Pair(17, 11), Pair(11, 45), Pair(1, 10), Pair(-22, 27), Pair(-26, 22)
};

constexpr ScorePair kBishopPairBonus = Pair(30, 67);

constexpr ScorePair kTempoBonus = Pair(26, 6);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H