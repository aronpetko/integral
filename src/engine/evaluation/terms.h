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
  Pair(104, 136), Pair(341, 134), Pair(386, 171), Pair(496, 546), Pair(1177, 955), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(75, 11), Pair(51, 43), Pair(49, 33), Pair(41, 0), Pair(29, 15), Pair(-6, 33), Pair(-21, 47), Pair(21, 27),
      Pair(-6, 0), Pair(-22, 21), Pair(7, -21), Pair(29, -47), Pair(18, -39), Pair(35, -31), Pair(2, 8), Pair(6, -4),
      Pair(-15, -17), Pair(-14, 0), Pair(-4, -37), Pair(1, -45), Pair(19, -47), Pair(15, -45), Pair(0, -23), Pair(-11, -21),
      Pair(-25, -30), Pair(-25, -8), Pair(-5, -42), Pair(3, -37), Pair(8, -46), Pair(7, -43), Pair(0, -31), Pair(-11, -31),
      Pair(-30, -32), Pair(-32, -7), Pair(-24, -32), Pair(-21, -33), Pair(-9, -36), Pair(-18, -31), Pair(1, -34), Pair(-13, -34),
      Pair(-25, -27), Pair(-14, -6), Pair(-15, -26), Pair(-20, -26), Pair(-13, -23), Pair(9, -29), Pair(18, -32), Pair(-12, -35),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-110, 86), Pair(15, 82), Pair(-1, 94), Pair(72, 80), Pair(69, 71), Pair(106, 71), Pair(17, 72), Pair(-35, 3),
      Pair(32, 80), Pair(19, 96), Pair(71, 86), Pair(103, 90), Pair(99, 101), Pair(107, 76), Pair(57, 101), Pair(23, 98),
      Pair(58, 85), Pair(64, 101), Pair(74, 112), Pair(88, 99), Pair(121, 86), Pair(112, 86), Pair(57, 105), Pair(81, 73),
      Pair(48, 103), Pair(60, 107), Pair(69, 107), Pair(85, 113), Pair(84, 113), Pair(95, 111), Pair(68, 112), Pair(72, 98),
      Pair(46, 105), Pair(77, 95), Pair(75, 114), Pair(75, 115), Pair(76, 123), Pair(88, 107), Pair(82, 107), Pair(56, 112),
      Pair(25, 89), Pair(51, 99), Pair(52, 107), Pair(67, 113), Pair(70, 112), Pair(62, 101), Pair(59, 102), Pair(40, 97),
      Pair(-2, 97), Pair(46, 92), Pair(48, 88), Pair(55, 99), Pair(55, 98), Pair(51, 83), Pair(36, 98), Pair(33, 96),
      Pair(10, 73), Pair(20, 93), Pair(24, 95), Pair(34, 107), Pair(47, 96), Pair(46, 87), Pair(19, 101), Pair(-13, 106)
  },
  {
      Pair(-22, 111), Pair(-48, 116), Pair(-7, 91), Pair(-80, 108), Pair(17, 89), Pair(-86, 95), Pair(17, 85), Pair(17, 80),
      Pair(-10, 97), Pair(19, 103), Pair(31, 87), Pair(44, 92), Pair(6, 86), Pair(44, 87), Pair(-20, 113), Pair(-2, 78),
      Pair(16, 103), Pair(30, 97), Pair(30, 100), Pair(51, 84), Pair(68, 80), Pair(59, 104), Pair(43, 91), Pair(36, 97),
      Pair(29, 84), Pair(32, 93), Pair(35, 96), Pair(55, 97), Pair(43, 95), Pair(50, 95), Pair(27, 101), Pair(32, 92),
      Pair(37, 84), Pair(33, 89), Pair(37, 93), Pair(36, 103), Pair(46, 91), Pair(35, 97), Pair(35, 95), Pair(36, 80),
      Pair(29, 78), Pair(43, 94), Pair(38, 101), Pair(41, 99), Pair(37, 102), Pair(48, 94), Pair(53, 85), Pair(41, 86),
      Pair(48, 77), Pair(44, 72), Pair(47, 79), Pair(34, 89), Pair(44, 88), Pair(55, 72), Pair(59, 75), Pair(26, 88),
      Pair(24, 69), Pair(59, 70), Pair(25, 87), Pair(27, 86), Pair(33, 92), Pair(22, 93), Pair(16, 72), Pair(40, 73)
  },
  {
      Pair(93, 44), Pair(93, 47), Pair(69, 68), Pair(90, 51), Pair(101, 46), Pair(99, 53), Pair(89, 54), Pair(73, 45),
      Pair(76, 47), Pair(83, 48), Pair(95, 48), Pair(120, 39), Pair(111, 28), Pair(110, 33), Pair(85, 47), Pair(70, 42),
      Pair(72, 45), Pair(94, 41), Pair(88, 43), Pair(113, 28), Pair(123, 17), Pair(111, 39), Pair(87, 47), Pair(65, 41),
      Pair(65, 37), Pair(87, 37), Pair(99, 40), Pair(109, 25), Pair(107, 22), Pair(93, 35), Pair(83, 39), Pair(67, 32),
      Pair(49, 36), Pair(72, 40), Pair(59, 50), Pair(64, 48), Pair(67, 34), Pair(45, 59), Pair(52, 44), Pair(33, 36),
      Pair(34, 34), Pair(52, 31), Pair(37, 49), Pair(45, 40), Pair(56, 27), Pair(49, 33), Pair(61, 21), Pair(44, 15),
      Pair(44, 16), Pair(58, 20), Pair(62, 24), Pair(56, 25), Pair(67, 15), Pair(62, 18), Pair(55, 8), Pair(10, 14),
      Pair(50, 23), Pair(60, 18), Pair(60, 25), Pair(70, 18), Pair(75, 8), Pair(67, 20), Pair(47, 21), Pair(50, 9)
  },
  {
      Pair(121, 18), Pair(136, 26), Pair(149, 28), Pair(160, 20), Pair(125, 58), Pair(176, 16), Pair(127, 65), Pair(127, 42),
      Pair(117, 41), Pair(103, 77), Pair(138, 59), Pair(100, 98), Pair(107, 96), Pair(147, 51), Pair(141, 50), Pair(150, 37),
      Pair(134, 1), Pair(138, 34), Pair(129, 52), Pair(140, 63), Pair(153, 56), Pair(156, 62), Pair(181, 4), Pair(150, 6),
      Pair(132, 4), Pair(141, 27), Pair(126, 74), Pair(129, 57), Pair(139, 52), Pair(154, 41), Pair(133, 50), Pair(162, -11),
      Pair(132, -6), Pair(121, 26), Pair(135, 34), Pair(129, 52), Pair(135, 37), Pair(137, 38), Pair(144, 25), Pair(130, 33),
      Pair(127, -17), Pair(141, -22), Pair(132, 20), Pair(137, 1), Pair(136, 24), Pair(142, 16), Pair(143, 11), Pair(136, -8),
      Pair(134, -35), Pair(144, -51), Pair(145, -34), Pair(146, -32), Pair(144, -19), Pair(153, -66), Pair(163, -88), Pair(143, -53),
      Pair(143, -54), Pair(140, -76), Pair(135, -53), Pair(136, -34), Pair(141, -68), Pair(134, -88), Pair(152, -81), Pair(143, -19)
  },
  {
      Pair(-41, -156), Pair(-67, -2), Pair(11, 13), Pair(-71, 19), Pair(-27, 1), Pair(159, -24), Pair(79, -14), Pair(160, -226),
      Pair(-96, 6), Pair(9, 32), Pair(44, 29), Pair(-24, 33), Pair(-30, 37), Pair(-80, 63), Pair(45, 25), Pair(-59, -1),
      Pair(-93, 36), Pair(21, 35), Pair(-36, 51), Pair(-119, 62), Pair(-129, 79), Pair(-53, 58), Pair(88, 27), Pair(20, -11),
      Pair(-52, 15), Pair(-46, 23), Pair(-73, 47), Pair(-112, 62), Pair(-118, 60), Pair(-58, 41), Pair(-31, 17), Pair(-67, -10),
      Pair(-88, -5), Pair(-30, 9), Pair(-74, 37), Pair(-98, 48), Pair(-89, 39), Pair(-34, 16), Pair(-27, -4), Pair(-143, -18),
      Pair(-104, 8), Pair(-16, -2), Pair(-56, 27), Pair(-55, 29), Pair(-72, 37), Pair(-43, 15), Pair(-29, -3), Pair(-74, -16),
      Pair(-6, -30), Pair(-19, -8), Pair(-30, 7), Pair(-59, 22), Pair(-59, 21), Pair(-45, 9), Pair(-16, -16), Pair(2, -49),
      Pair(2, -74), Pair(27, -43), Pair(8, -19), Pair(-66, 3), Pair(-21, -21), Pair(-51, -9), Pair(11, -36), Pair(13, -78)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(20, 9), Pair(43, 51), Pair(55, 72), Pair(61, 87), Pair(67, 97), Pair(70, 106), Pair(75, 103), Pair(76, 103),
  Pair(83, 97)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(15, 20), Pair(33, 34), Pair(41, 52), Pair(46, 66), Pair(52, 76), Pair(55, 84), Pair(58, 86), Pair(59, 91),
  Pair(62, 95), Pair(69, 94), Pair(77, 93), Pair(79, 94), Pair(87, 96), Pair(122, 84)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(15, -24), Pair(30, -9), Pair(36, -2), Pair(41, 9), Pair(42, 22), Pair(46, 26), Pair(48, 32), Pair(54, 34),
  Pair(58, 37), Pair(65, 39), Pair(70, 38), Pair(72, 42), Pair(78, 42), Pair(95, 33), Pair(118, 26)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(117, 20), Pair(111, -159), Pair(116, -71), Pair(120, -37), Pair(124, -30), Pair(127, -17), Pair(128, 17), Pair(132, 31),
  Pair(134, 37), Pair(137, 47), Pair(138, 52), Pair(141, 56), Pair(146, 50), Pair(141, 67), Pair(146, 58), Pair(150, 58),
  Pair(148, 62), Pair(151, 60), Pair(158, 44), Pair(169, 24), Pair(180, 14), Pair(223, -35), Pair(221, -28), Pair(358, -131),
  Pair(410, -158), Pair(492, -208), Pair(395, -162), Pair(289, -96)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(2, -73), Pair(5, -64), Pair(12, -31), Pair(31, 12), Pair(41, 76), Pair(57, 92), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 8), Pair(18, 6), Pair(19, 29), Pair(48, 63), Pair(201, 112), Pair(289, 680), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(23, 11), Pair(17, 9), Pair(20, 20), Pair(47, 41), Pair(224, 7), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-28, -48), Pair(8, -37), Pair(-6, -16), Pair(-8, -7), Pair(-17, -4), Pair(-17, -3), Pair(-9, -22), Pair(-28, -37)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(1, 10), Pair(-5, -17), Pair(-14, -3), Pair(-7, -19), Pair(-10, -16), Pair(3, -14), Pair(-6, -10), Pair(-2, -2)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(28, 0), Pair(19, 4), Pair(24, 4), Pair(22, 0), Pair(23, 11), Pair(34, -3), Pair(49, -8), Pair(58, -6)
  },
  {
      Pair(18, 22), Pair(14, 6), Pair(26, -5), Pair(22, -9), Pair(20, -3), Pair(22, -8), Pair(36, -11), Pair(30, 16)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(11, -2), Pair(13, -7), Pair(12, -2),
  Pair(21, -9), Pair(16, -8), Pair(19, -7),
  Pair(26, -2), Pair(0, 0), Pair(28, -2),
  Pair(-12, 9), Pair(-16, 11), Pair(2, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, -2), Pair(-16, 9), Pair(-5, 2),
  Pair(-7, 0), Pair(-20, 9), Pair(-5, -1),
  Pair(-1, -7), Pair(-12, 2), Pair(1, -8),
  Pair(9, -8), Pair(-13, 0), Pair(9, -7),
  Pair(28, -17), Pair(32, -9), Pair(23, -16),
  Pair(0, 0), Pair(-50, -7), Pair(0, 0),
  Pair(54, -52), Pair(0, 0), Pair(61, -59)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-3, 34), Pair(-20, 28), Pair(-19, 10), Pair(-8, -7), Pair(-3, -8), Pair(12, -9), Pair(0, -8)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-54, 1), Pair(-12, 24), Pair(-9, 55), Pair(-4, 69), Pair(-9, 77), Pair(-10, 83), Pair(-15, 83)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-239, 105);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-52, -10), Pair(-36, -7), Pair(-20, -20), Pair(-11, -20), Pair(-21, -15), Pair(-33, -7), Pair(-60, 6), Pair(-57, 15)
  },
  {
      Pair(3, 28), Pair(-41, 31), Pair(-29, 17), Pair(-20, 8), Pair(-11, -2), Pair(-15, 13), Pair(-28, 24), Pair(-20, 43)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 1), Pair(21, -4), Pair(67, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -1), Pair(24, 2), Pair(46, -2), Pair(-19, -3), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(22, -22), Pair(30, -20), Pair(48, -13), Pair(63, -12), Pair(99, -31), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 30), Pair(4, 48), Pair(19, 53), Pair(66, 28), Pair(90, 39), Pair(212, -17), Pair(154, -4)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(31, 1), Pair(14, 20), Pair(47, -1), Pair(17, 22), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-3, 33), Pair(1, 39)
  },
  {
      Pair(-71, -21), Pair(-60, -31)
  },
  {
      Pair(-47, -57), Pair(-56, -53)
  },
  {
      Pair(-87, -23), Pair(-68, -17)
  },
  {
      Pair(-52, -9), Pair(-48, -7)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(15, 35), Pair(20, 28), Pair(35, 7), Pair(24, -18), Pair(50, -6)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-6, -28), Pair(8, -15)
  },
  {
      Pair(13, -16), Pair(10, -21)
  },
  {
      Pair(-44, -12), Pair(-34, -30)
  },
  {
      Pair(-73, 6), Pair(-59, -7)
  },
  {
      Pair(-41, -11), Pair(-35, -23)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-16, -22), Pair(-1, -8)
  },
  {
      Pair(-55, -10), Pair(-23, -29)
  },
  {
      Pair(4, 1), Pair(15, -4)
  },
  {
      Pair(-60, -13), Pair(-54, -35)
  },
  {
      Pair(-52, -39), Pair(-50, -50)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-7, -30), Pair(13, -18)
  },
  {
      Pair(-41, -19), Pair(-6, -17)
  },
  {
      Pair(-36, -22), Pair(-15, -8)
  },
  {
      Pair(8, -43), Pair(14, -25)
  },
  {
      Pair(-59, -16), Pair(-48, -67)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-25, 24), Pair(-7, 25), Pair(26, 20), Pair(17, 34), Pair(35, 27), Pair(20, 60), Pair(32, 31), Pair(-49, 97),
  Pair(24, 47), Pair(19, 13), Pair(11, 25), Pair(2, 38), Pair(0, 33), Pair(-5, 29), Pair(9, 16), Pair(14, 15),
  Pair(14, 12), Pair(-24, 8), Pair(1, 23), Pair(10, 18), Pair(3, 20), Pair(-4, 14), Pair(5, -3), Pair(15, 0)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-45, 10), Pair(-1, 22), Pair(16, 6), Pair(55, -7), Pair(48, -17), Pair(0, 1), Pair(30, 25), Pair(0, 24),
  Pair(-72, 36), Pair(17, 17), Pair(28, 2), Pair(31, 7), Pair(16, 12), Pair(24, 4), Pair(16, 12), Pair(-16, 1),
  Pair(-19, 38), Pair(-10, 33), Pair(11, 17), Pair(20, 12), Pair(18, 21), Pair(-5, 14), Pair(10, -3), Pair(-58, -7)
};

constexpr ScorePair kBishopPairBonus = Pair(23, 59);

constexpr ScorePair kTempoBonus = Pair(17, 7);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H