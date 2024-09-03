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
  Pair(99, 127), Pair(330, 260), Pair(371, 319), Pair(497, 545), Pair(1151, 888), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
    Pair(73, 36), Pair(24, 81), Pair(41, 56), Pair(96, 20), Pair(64, 22), Pair(-2, 65), Pair(-18, 60), Pair(21, 54),
    Pair(-19, 3), Pair(-11, 11), Pair(-23, -6), Pair(13, -34), Pair(0, -23), Pair(22, -27), Pair(-14, 5), Pair(-3, -4),
    Pair(-24, -6), Pair(-15, -7), Pair(-18, -23), Pair(-4, -35), Pair(4, -35), Pair(11, -36), Pair(-10, -15), Pair(-21, -16),
    Pair(-34, -20), Pair(-24, -8), Pair(-16, -33), Pair(-9, -35), Pair(-7, -37), Pair(-3, -33), Pair(-15, -19), Pair(-26, -29),
    Pair(-37, -22), Pair(-26, -18), Pair(-29, -25), Pair(-27, -29), Pair(-22, -29), Pair(-18, -28), Pair(-1, -31), Pair(-24, -34),
    Pair(-36, -16), Pair(-15, -14), Pair(-25, -16), Pair(-26, -22), Pair(-25, -16), Pair(7, -26), Pair(8, -26), Pair(-21, -32),
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(-175, -55), Pair(7, 0), Pair(28, 3), Pair(-72, 44), Pair(68, -5), Pair(-199, 65), Pair(-6, 8), Pair(-36, -37),
    Pair(-24, 1), Pair(-23, 29), Pair(14, 18), Pair(63, 14), Pair(54, 9), Pair(52, 1), Pair(-17, 21), Pair(4, -1),
    Pair(-14, 24), Pair(16, 21), Pair(14, 45), Pair(33, 34), Pair(73, 20), Pair(88, 16), Pair(17, 31), Pair(13, 11),
    Pair(8, 17), Pair(19, 33), Pair(22, 51), Pair(46, 47), Pair(32, 48), Pair(50, 35), Pair(28, 37), Pair(37, 17),
    Pair(8, 11), Pair(18, 28), Pair(27, 42), Pair(33, 44), Pair(33, 49), Pair(42, 32), Pair(41, 20), Pair(20, 16),
    Pair(-9, -7), Pair(12, 15), Pair(16, 24), Pair(26, 41), Pair(26, 38), Pair(26, 24), Pair(29, 11), Pair(1, 10),
    Pair(-23, 7), Pair(5, 21), Pair(2, 11), Pair(16, 21), Pair(19, 22), Pair(16, 2), Pair(6, 20), Pair(0, 10),
    Pair(-33, -24), Pair(-10, 2), Pair(-15, 17), Pair(-8, 28), Pair(8, 13), Pair(4, -6), Pair(-8, -7), Pair(-28, -17)
  },
  {
    Pair(-54, 19), Pair(-68, 20), Pair(-117, 44), Pair(-97, 36), Pair(-51, 31), Pair(-195, 54), Pair(-65, 26), Pair(-56, 23),
    Pair(-56, 29), Pair(-14, 24), Pair(-16, 23), Pair(-11, 32), Pair(-37, 30), Pair(14, 18), Pair(-23, 27), Pair(-25, 5),
    Pair(0, -1), Pair(-7, 21), Pair(3, 26), Pair(23, 19), Pair(32, 15), Pair(23, 30), Pair(22, 15), Pair(22, -5),
    Pair(-8, -2), Pair(2, 11), Pair(1, 17), Pair(21, 21), Pair(15, 24), Pair(16, 17), Pair(4, 14), Pair(16, -2),
    Pair(6, 4), Pair(3, 8), Pair(5, 15), Pair(3, 20), Pair(14, 15), Pair(6, 12), Pair(1, 7), Pair(5, 0),
    Pair(-3, 11), Pair(23, 11), Pair(11, 16), Pair(8, 20), Pair(7, 21), Pair(15, 9), Pair(21, 6), Pair(-5, 11),
    Pair(13, 12), Pair(16, -10), Pair(17, -5), Pair(0, 7), Pair(12, 0), Pair(15, -1), Pair(23, -6), Pair(16, -5),
    Pair(14, -15), Pair(5, 4), Pair(-6, 5), Pair(-2, 2), Pair(1, -9), Pair(-12, 6), Pair(8, 0), Pair(0, 11)
  },
  {
    Pair(11, 47), Pair(42, 40), Pair(16, 49), Pair(50, 33), Pair(32, 43), Pair(36, 42), Pair(15, 61), Pair(20, 48),
    Pair(-7, 53), Pair(-10, 55), Pair(17, 53), Pair(43, 34), Pair(35, 37), Pair(52, 32), Pair(-11, 65), Pair(7, 43),
    Pair(-17, 53), Pair(23, 36), Pair(18, 46), Pair(43, 27), Pair(59, 20), Pair(87, 19), Pair(40, 36), Pair(-1, 42),
    Pair(-9, 48), Pair(1, 46), Pair(9, 49), Pair(31, 24), Pair(16, 35), Pair(16, 44), Pair(-9, 58), Pair(4, 37),
    Pair(-24, 35), Pair(-28, 50), Pair(-7, 47), Pair(-13, 43), Pair(-10, 38), Pair(-15, 48), Pair(-22, 45), Pair(-22, 33),
    Pair(-31, 31), Pair(-11, 23), Pair(-18, 39), Pair(-12, 29), Pair(-10, 20), Pair(-21, 36), Pair(-20, 32), Pair(-26, 26),
    Pair(-42, 24), Pair(-23, 21), Pair(-19, 31), Pair(-5, 20), Pair(-10, 16), Pair(-12, 19), Pair(-32, 24), Pair(-44, 16),
    Pair(-16, 17), Pair(-15, 14), Pair(-13, 27), Pair(-2, 12), Pair(1, 6), Pair(-3, 12), Pair(-36, 35), Pair(-1, -3)
  },
  {
    Pair(-6, 57), Pair(16, 56), Pair(-23, 92), Pair(47, 25), Pair(22, 73), Pair(31, 78), Pair(59, 23), Pair(5, 80),
    Pair(-24, 69), Pair(-46, 98), Pair(-15, 103), Pair(12, 77), Pair(-17, 106), Pair(19, 85), Pair(-25, 115), Pair(-15, 116),
    Pair(-27, 82), Pair(-22, 111), Pair(-9, 83), Pair(4, 91), Pair(-7, 132), Pair(28, 95), Pair(35, 87), Pair(-1, 80),
    Pair(-26, 75), Pair(-15, 89), Pair(-16, 114), Pair(-16, 116), Pair(3, 92), Pair(21, 78), Pair(2, 92), Pair(13, 62),
    Pair(-13, 59), Pair(-18, 77), Pair(-14, 80), Pair(-22, 126), Pair(-3, 72), Pair(-11, 93), Pair(6, 62), Pair(2, 48),
    Pair(-16, 36), Pair(-3, 47), Pair(-12, 81), Pair(-12, 83), Pair(-11, 79), Pair(0, 56), Pair(10, 34), Pair(7, 12),
    Pair(-7, 18), Pair(-12, 44), Pair(0, 28), Pair(-2, 42), Pair(2, 30), Pair(9, 4), Pair(11, -9), Pair(1, -14),
    Pair(-13, 10), Pair(-10, 7), Pair(-8, 1), Pair(-6, 19), Pair(-2, 4), Pair(-22, -3), Pair(-8, -27), Pair(22, -31)
  },
  {
    Pair(127, -106), Pair(-83, 28), Pair(198, 3), Pair(60, -1), Pair(111, -28), Pair(225, -3), Pair(119, 17), Pair(120, -126),
    Pair(105, -47), Pair(157, 40), Pair(131, 27), Pair(101, 33), Pair(212, -13), Pair(44, 24), Pair(101, 35), Pair(182, -43),
    Pair(13, 4), Pair(109, 15), Pair(39, 46), Pair(-5, 50), Pair(92, 29), Pair(79, 30), Pair(100, 21), Pair(29, -3),
    Pair(72, -29), Pair(35, 16), Pair(-27, 38), Pair(-16, 43), Pair(6, 36), Pair(40, 19), Pair(20, 5), Pair(-52, -1),
    Pair(-6, -21), Pair(35, 2), Pair(-3, 20), Pair(-60, 43), Pair(-58, 41), Pair(-11, 13), Pair(24, -11), Pair(-39, -28),
    Pair(39, -47), Pair(28, -15), Pair(-38, 16), Pair(-49, 31), Pair(-49, 27), Pair(-22, 10), Pair(0, -13), Pair(-28, -28),
    Pair(36, -43), Pair(24, -21), Pair(-19, 6), Pair(-36, 14), Pair(-51, 22), Pair(-32, 7), Pair(-1, -10), Pair(23, -44),
    Pair(33, -76), Pair(45, -42), Pair(30, -31), Pair(-50, 1), Pair(-7, -23), Pair(-45, -5), Pair(31, -38), Pair(34, -78)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-11, -62), Pair(3, 10), Pair(10, 33), Pair(15, 45), Pair(19, 55), Pair(23, 61), Pair(27, 60), Pair(34, 51),
  Pair(43, 42)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-26, -51), Pair(-15, -26), Pair(-7, -9), Pair(-3, 5), Pair(1, 16), Pair(4, 24), Pair(5, 25), Pair(7, 29),
  Pair(9, 31), Pair(11, 28), Pair(18, 24), Pair(38, 19), Pair(33, 23), Pair(55, 8)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-34, -57), Pair(-25, -26), Pair(-22, -6), Pair(-17, 10), Pair(-13, 12), Pair(-11, 20), Pair(-7, 24), Pair(-2, 28),
  Pair(3, 29), Pair(10, 31), Pair(10, 35), Pair(14, 35), Pair(22, 34), Pair(25, 31), Pair(29, 27)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-12, 45), Pair(-9, -69), Pair(-8, -29), Pair(-7, 8), Pair(-6, 17), Pair(-5, 47), Pair(-4, 64), Pair(-2, 72),
  Pair(1, 86), Pair(1, 94), Pair(8, 92), Pair(7, 97), Pair(9, 105), Pair(11, 106), Pair(7, 110), Pair(10, 107),
  Pair(13, 98), Pair(26, 83), Pair(27, 78), Pair(19, 82), Pair(20, 80), Pair(88, 16), Pair(53, 20), Pair(152, -50),
  Pair(168, -61), Pair(179, -90), Pair(79, -87), Pair(153, -80)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(0, -50), Pair(0, -46), Pair(8, -15), Pair(32, 15), Pair(62, 61), Pair(53, 48), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(3, 8), Pair(11, 5), Pair(16, 16), Pair(35, 56), Pair(199, 78), Pair(414, 532), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(16, 12), Pair(11, 8), Pair(13, 17), Pair(38, 37), Pair(191, 44), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-32, -48), Pair(-8, -24), Pair(-13, -12), Pair(-24, 0), Pair(-20, -4), Pair(-14, -10), Pair(-3, -20), Pair(-20, -37)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(4, 3), Pair(-7, -8), Pair(0, -11), Pair(-8, -18), Pair(-9, -16), Pair(-8, -8), Pair(-5, -3), Pair(-5, 0)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
    Pair(20, -2), Pair(16, 2), Pair(19, -1), Pair(16, 8), Pair(27, 2), Pair(36, -2), Pair(60, -20), Pair(39, -4)
  },
  {
    Pair(12, 24), Pair(12, 12), Pair(17, -1), Pair(14, 3), Pair(21, 0), Pair(16, 0), Pair(54, -25), Pair(22, 8)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(10, -3), Pair(12, -5), Pair(12, -2),
  Pair(14, -3), Pair(14, -5), Pair(15, -1),
  Pair(25, -4), Pair(0, 0), Pair(24, -2),
  Pair(8, 6), Pair(-21, 3), Pair(-2, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, -1), Pair(-15, 3), Pair(-9, 0),
  Pair(-10, 2), Pair(-21, 8), Pair(-9, 1),
  Pair(2, -8), Pair(-7, -5), Pair(1, -8),
  Pair(12, -9), Pair(-8, -7), Pair(9, -8),
  Pair(30, -17), Pair(29, -5), Pair(25, -12),
  Pair(0, 0), Pair(-33, -17), Pair(0, 0),
  Pair(49, -46), Pair(0, 0), Pair(36, -44)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-3, 53), Pair(-10, 43), Pair(-9, 24), Pair(-9, 19), Pair(-5, 18), Pair(11, 16), Pair(5, 10)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-53, -23), Pair(-21, 3), Pair(-16, 25), Pair(-13, 32), Pair(-11, 39), Pair(-14, 41), Pair(-17, 39)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-389, 98);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
    Pair(-62, 4), Pair(-61, 4), Pair(-21, -12), Pair(-22, -12), Pair(-13, -11), Pair(-32, 0), Pair(-53, 4), Pair(-47, 4)
  },
  {
    Pair(-45, 63), Pair(-22, 20), Pair(-15, 11), Pair(-16, -5), Pair(-10, -1), Pair(-11, 9), Pair(-22, 22), Pair(-33, 42)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(11, 2), Pair(21, -2), Pair(60, -19), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(8, 2), Pair(22, 2), Pair(50, -10), Pair(19, -31), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(16, -14), Pair(27, -17), Pair(40, -10), Pair(73, -15), Pair(71, -21), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(1, 20), Pair(9, 31), Pair(24, 36), Pair(75, -1), Pair(129, -22), Pair(225, -68), Pair(246, -77)
  },
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(22, 3), Pair(5, 21), Pair(46, -7), Pair(16, 18), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
    Pair(-17, 42), Pair(-8, 39)
  },
  {
    Pair(-54, -30), Pair(-55, -28)
  },
  {
    Pair(-48, -49), Pair(-52, -72)
  },
  {
    Pair(-72, -36), Pair(-61, -6)
  },
  {
    Pair(-38, -11), Pair(-41, -4)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(12, 31), Pair(16, 22), Pair(20, 21), Pair(19, -8), Pair(34, 1)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
    Pair(-5, -25), Pair(7, -11)
  },
  {
    Pair(-18, 31), Pair(-25, 34)
  },
  {
    Pair(-42, -14), Pair(-33, -31)
  },
  {
    Pair(-70, 14), Pair(-56, 0)
  },
  {
    Pair(-38, 7), Pair(-36, 31)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
    Pair(-14, -22), Pair(-1, -4)
  },
  {
    Pair(-55, -5), Pair(-15, -38)
  },
  {
    Pair(4, -11), Pair(2, -22)
  },
  {
    Pair(-45, -9), Pair(-50, -50)
  },
  {
    Pair(-41, -86), Pair(-34, -88)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
    Pair(-8, -22), Pair(10, -13)
  },
  {
    Pair(-52, -17), Pair(-10, -16)
  },
  {
    Pair(-36, -21), Pair(-16, -6)
  },
  {
    Pair(-4, -25), Pair(-4, -13)
  },
  {
    Pair(-64, -3), Pair(-49, -18)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(78, -23), Pair(7, 6), Pair(23, -4), Pair(55, -6), Pair(22, 19), Pair(-9, 30), Pair(39, 0), Pair(38, 27),
  Pair(14, 17), Pair(12, 11), Pair(17, 13), Pair(8, 16), Pair(12, 19), Pair(-4, 35), Pair(12, 16), Pair(-2, 5),
  Pair(2, 11), Pair(2, 20), Pair(3, 5), Pair(9, 10), Pair(1, 24), Pair(-1, 16), Pair(-13, 9), Pair(4, 0)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-55, 42), Pair(27, -4), Pair(23, -16), Pair(19, -10), Pair(16, 10), Pair(43, -4), Pair(18, 26), Pair(8, -55),
  Pair(-33, 24), Pair(15, 22), Pair(5, 5), Pair(7, 16), Pair(22, 1), Pair(21, -3), Pair(21, 7), Pair(-18, 17),
  Pair(-2, 24), Pair(8, 14), Pair(9, 20), Pair(18, 12), Pair(17, 18), Pair(-6, 18), Pair(5, 11), Pair(2, -31)
};

constexpr ScorePair kBishopPairBonus = Pair(16, 58);

constexpr ScorePair kTempoBonus = Pair(16, 5);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H