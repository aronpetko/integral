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
  Pair(117, 97), Pair(414, 191), Pair(441, 205), Pair(571, 452), Pair(1028, 909), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(120, 16), Pair(45, 79), Pair(46, 84), Pair(40, 80), Pair(54, 81), Pair(29, 88), Pair(-14, 120), Pair(99, 1),
      Pair(-13, -5), Pair(-18, 5), Pair(-18, 4), Pair(19, -11), Pair(22, -9), Pair(35, -10), Pair(-10, 14), Pair(-1, -23),
      Pair(-17, -12), Pair(-9, -11), Pair(-7, -18), Pair(8, -32), Pair(16, -23), Pair(2, -23), Pair(-7, -10), Pair(-20, -19),
      Pair(-23, -12), Pair(-30, -7), Pair(-11, -23), Pair(-2, -25), Pair(1, -26), Pair(-1, -23), Pair(-20, -9), Pair(-24, -20),
      Pair(-23, -19), Pair(-31, -13), Pair(-29, -11), Pair(-22, -19), Pair(-21, -10), Pair(-15, -19), Pair(-6, -15), Pair(-20, -18),
      Pair(-25, -8), Pair(-16, -7), Pair(-27, -5), Pair(-25, -17), Pair(-22, -12), Pair(5, -13), Pair(7, -16), Pair(-21, -22),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-172, -11), Pair(-109, -10), Pair(-28, -18), Pair(21, -15), Pair(48, -22), Pair(-148, 22), Pair(-101, 11), Pair(-109, -13),
      Pair(-45, 5), Pair(4, -4), Pair(27, -9), Pair(61, -2), Pair(35, -8), Pair(25, -12), Pair(17, -16), Pair(-23, 0),
      Pair(-8, -22), Pair(19, -4), Pair(8, 29), Pair(51, 6), Pair(58, 13), Pair(63, 17), Pair(10, 8), Pair(5, -16),
      Pair(5, -6), Pair(12, 12), Pair(35, 23), Pair(43, 25), Pair(32, 14), Pair(59, 6), Pair(23, -1), Pair(36, -9),
      Pair(0, 2), Pair(27, -5), Pair(21, 32), Pair(33, 31), Pair(32, 29), Pair(45, 22), Pair(35, -4), Pair(7, 19),
      Pair(-17, -20), Pair(6, -1), Pair(5, 17), Pair(17, 31), Pair(20, 21), Pair(16, 17), Pair(23, 2), Pair(-7, -1),
      Pair(-24, -28), Pair(-18, 1), Pair(-9, -13), Pair(10, 5), Pair(11, 7), Pair(7, -3), Pair(-4, 6), Pair(-11, -12),
      Pair(-75, -48), Pair(-19, -20), Pair(-24, -18), Pair(-2, 3), Pair(-2, -3), Pair(-11, -7), Pair(-17, -13), Pair(-32, -38)
  },
  {
      Pair(-40, 13), Pair(-54, 17), Pair(3, 7), Pair(-43, 1), Pair(-13, 3), Pair(-41, -16), Pair(-48, 25), Pair(-28, 6),
      Pair(-42, 0), Pair(3, 7), Pair(-32, 12), Pair(10, 11), Pair(-1, -3), Pair(-10, 4), Pair(-18, 14), Pair(-42, 13),
      Pair(0, 1), Pair(20, -4), Pair(-2, 26), Pair(30, 2), Pair(21, 4), Pair(33, 14), Pair(20, -21), Pair(7, -10),
      Pair(-6, -9), Pair(-4, 14), Pair(23, 5), Pair(14, 22), Pair(11, 20), Pair(28, -17), Pair(1, -4), Pair(-8, 1),
      Pair(12, -10), Pair(-5, 6), Pair(1, 11), Pair(4, 9), Pair(11, 6), Pair(2, 11), Pair(1, 6), Pair(16, -8),
      Pair(-3, -4), Pair(16, -5), Pair(9, 7), Pair(6, 7), Pair(3, 19), Pair(5, 12), Pair(22, -8), Pair(4, 3),
      Pair(-8, -10), Pair(10, -8), Pair(25, -21), Pair(-3, -2), Pair(9, -7), Pair(20, -9), Pair(21, -12), Pair(28, -21),
      Pair(-17, -13), Pair(21, -32), Pair(-9, -7), Pair(3, -6), Pair(11, -16), Pair(-16, 1), Pair(0, -24), Pair(10, -35)
  },
  {
      Pair(2, 9), Pair(44, 1), Pair(33, 10), Pair(49, -5), Pair(63, -1), Pair(85, -13), Pair(20, 4), Pair(10, 12),
      Pair(7, 14), Pair(17, 16), Pair(22, 10), Pair(53, 1), Pair(36, 8), Pair(43, 4), Pair(-12, 16), Pair(-19, 18),
      Pair(6, 5), Pair(33, 2), Pair(11, 6), Pair(27, 3), Pair(34, 1), Pair(31, 9), Pair(12, -1), Pair(3, 0),
      Pair(-2, 1), Pair(9, 2), Pair(27, -7), Pair(8, 0), Pair(25, 0), Pair(11, -2), Pair(8, -2), Pair(-5, 2),
      Pair(-23, 3), Pair(-24, 12), Pair(5, 4), Pair(-8, 9), Pair(-21, 14), Pair(-15, 8), Pair(-31, 17), Pair(-35, 6),
      Pair(-36, 0), Pair(-34, 3), Pair(-27, 1), Pair(-34, 3), Pair(-30, 11), Pair(-29, -2), Pair(-27, -1), Pair(-36, 0),
      Pair(-38, -10), Pair(-23, -11), Pair(-8, -19), Pair(-11, -11), Pair(-11, -20), Pair(0, -23), Pair(-28, -17), Pair(-72, -11),
      Pair(-19, -9), Pair(-7, -15), Pair(-11, -7), Pair(1, -15), Pair(-1, -14), Pair(1, -17), Pair(-37, 1), Pair(-21, -13)
  },
  {
      Pair(-20, 4), Pair(19, 15), Pair(39, 5), Pair(28, 8), Pair(34, 19), Pair(47, -31), Pair(41, -4), Pair(26, -6),
      Pair(-22, -4), Pair(-35, 36), Pair(-16, 62), Pair(-18, 77), Pair(-20, 75), Pair(9, 69), Pair(-15, 56), Pair(53, -23),
      Pair(-12, -5), Pair(2, 25), Pair(-29, 83), Pair(1, 78), Pair(2, 94), Pair(22, 57), Pair(-7, 62), Pair(12, -2),
      Pair(-8, -3), Pair(-11, 28), Pair(-23, 64), Pair(-13, 93), Pair(-17, 100), Pair(-1, 62), Pair(2, 29), Pair(9, -1),
      Pair(-4, -30), Pair(-11, -2), Pair(-16, 38), Pair(-27, 81), Pair(-15, 54), Pair(-8, 30), Pair(5, 1), Pair(-6, -26),
      Pair(-1, -38), Pair(-1, -23), Pair(-5, -1), Pair(-9, 6), Pair(-4, -4), Pair(-4, 7), Pair(5, -14), Pair(1, -49),
      Pair(-12, -69), Pair(-4, -54), Pair(10, -61), Pair(5, -37), Pair(8, -54), Pair(21, -86), Pair(5, -70), Pair(14, -121),
      Pair(-4, -82), Pair(-4, -70), Pair(-7, -55), Pair(-2, -60), Pair(0, -67), Pair(-23, -76), Pair(4, -93), Pair(9, -96)
  },
  {
      Pair(12, -99), Pair(161, 72), Pair(138, 36), Pair(-31, 57), Pair(55, 35), Pair(33, -2), Pair(101, -15), Pair(153, -189),
      Pair(-52, -18), Pair(125, -7), Pair(104, 2), Pair(29, 0), Pair(91, -10), Pair(113, -28), Pair(112, -16), Pair(-52, -54),
      Pair(3, -17), Pair(200, -44), Pair(140, -21), Pair(-79, 10), Pair(-107, 6), Pair(-38, -13), Pair(150, -57), Pair(81, -51),
      Pair(4, -38), Pair(80, -32), Pair(-6, 2), Pair(-121, 16), Pair(-179, 18), Pair(-14, -14), Pair(59, -33), Pair(0, -46),
      Pair(-20, -63), Pair(52, -35), Pair(23, -9), Pair(-80, 21), Pair(-67, 7), Pair(2, -12), Pair(22, -28), Pair(-17, -59),
      Pair(3, -49), Pair(24, -29), Pair(10, -10), Pair(-39, 15), Pair(-42, 12), Pair(-29, 0), Pair(10, -17), Pair(-11, -38),
      Pair(35, -41), Pair(-1, -4), Pair(-10, 0), Pair(-47, 13), Pair(-34, 10), Pair(-17, 5), Pair(0, -2), Pair(16, -31),
      Pair(-61, 57), Pair(29, -21), Pair(18, -6), Pair(-62, 8), Pair(-4, -15), Pair(-36, -1), Pair(23, -12), Pair(18, -20)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-13, -48), Pair(3, -50), Pair(13, -25), Pair(20, -15), Pair(25, -12), Pair(29, -5), Pair(33, -10), Pair(39, -22),
  Pair(47, -59)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-17, -52), Pair(-3, -57), Pair(5, -37), Pair(9, -25), Pair(14, -15), Pair(17, -10), Pair(21, -12), Pair(24, -13),
  Pair(26, -14), Pair(42, -25), Pair(53, -37), Pair(60, -47), Pair(118, -73), Pair(-21, -48)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-18, -104), Pair(-5, -88), Pair(-1, -77), Pair(8, -72), Pair(10, -66), Pair(14, -61), Pair(18, -57), Pair(22, -57),
  Pair(27, -49), Pair(30, -51), Pair(38, -52), Pair(41, -51), Pair(50, -52), Pair(65, -61), Pair(125, -98)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-14, -86), Pair(-7, -99), Pair(-5, -104), Pair(-3, -104), Pair(-2, -90), Pair(-2, -62), Pair(0, -53), Pair(4, -54),
  Pair(5, -47), Pair(7, -39), Pair(11, -33), Pair(12, -33), Pair(11, -26), Pair(12, -24), Pair(12, -27), Pair(17, -34),
  Pair(28, -60), Pair(33, -70), Pair(52, -96), Pair(73, -131), Pair(89, -151), Pair(67, -164), Pair(60, -158), Pair(-69, -159),
  Pair(-58, -148), Pair(-133, -158), Pair(-92, -125), Pair(-124, -156)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-34, -34), Pair(-39, -18), Pair(-20, 2), Pair(6, 27), Pair(40, 46), Pair(76, -14), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 7), Pair(12, 4), Pair(18, 16), Pair(38, 50), Pair(104, 98), Pair(108, 125), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(20, 6), Pair(16, 3), Pair(15, 13), Pair(54, 23), Pair(111, 3), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-52, -18), Pair(-11, -12), Pair(-18, -15), Pair(-26, -2), Pair(-18, -3), Pair(-14, -11), Pair(-2, -15), Pair(-10, -23)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(9, -6), Pair(-4, -8), Pair(-10, -5), Pair(-13, -5), Pair(-19, -12), Pair(-2, -8), Pair(5, -11), Pair(-7, -3)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(39, -15), Pair(27, -14), Pair(32, -5), Pair(32, -9), Pair(43, -11), Pair(41, -10), Pair(58, -19), Pair(64, -18)
  },
  {
      Pair(28, 3), Pair(16, -5), Pair(28, -9), Pair(31, -19), Pair(30, -18), Pair(22, -18), Pair(42, -15), Pair(27, -14)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(11, -7), Pair(14, -15), Pair(12, -9),
  Pair(18, -8), Pair(14, -11), Pair(18, -9),
  Pair(16, 8), Pair(0, 0), Pair(15, 7),
  Pair(19, 6), Pair(-30, 20), Pair(18, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-9, 6), Pair(-14, 18), Pair(-10, 12),
  Pair(-12, 6), Pair(-22, 16), Pair(-10, 10),
  Pair(2, -5), Pair(-11, 7), Pair(1, -5),
  Pair(11, -6), Pair(-12, 3), Pair(9, -6),
  Pair(29, -20), Pair(31, -6), Pair(28, -24),
  Pair(0, 0), Pair(-79, 6), Pair(0, 0),
  Pair(37, -51), Pair(0, 0), Pair(40, -55)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(25, 28), Pair(-13, 35), Pair(-2, 13), Pair(1, 2), Pair(1, 9), Pair(11, 9), Pair(-7, -1)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-4, -36), Pair(-1, -10), Pair(0, 19), Pair(9, 32), Pair(14, 41), Pair(11, 46), Pair(-5, 63)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(25, 123);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-96, 39), Pair(-70, 8), Pair(-27, -23), Pair(5, -33), Pair(-16, -26), Pair(-24, -19), Pair(-49, -7), Pair(-70, 25)
  },
  {
      Pair(-19, 47), Pair(-26, 13), Pair(-18, 0), Pair(4, -9), Pair(-12, -3), Pair(-13, 2), Pair(-18, 11), Pair(-41, 45)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -2), Pair(23, -3), Pair(70, -16), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 2), Pair(24, 6), Pair(32, 7), Pair(-13, 4), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(22, -18), Pair(29, -16), Pair(66, -26), Pair(101, -34), Pair(103, -38), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, -9), Pair(20, -6), Pair(39, -13), Pair(83, -49), Pair(102, -19), Pair(118, -30), Pair(140, -85)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(33, -8), Pair(11, 10), Pair(82, -28), Pair(29, -26), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-7, 34), Pair(7, 22)
  },
  {
      Pair(-70, -5), Pair(-63, -22)
  },
  {
      Pair(-54, -34), Pair(-56, -48)
  },
  {
      Pair(-62, -27), Pair(-50, -18)
  },
  {
      Pair(-49, -10), Pair(-56, 23)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(15, 35), Pair(25, 12), Pair(21, 16), Pair(27, -40), Pair(32, 9)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -28), Pair(7, -15)
  },
  {
      Pair(-20, -25), Pair(-17, -37)
  },
  {
      Pair(-45, 0), Pair(-35, -27)
  },
  {
      Pair(-71, 5), Pair(-54, -4)
  },
  {
      Pair(-48, 6), Pair(-38, -13)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-18, -26), Pair(0, -10)
  },
  {
      Pair(-45, -3), Pair(-20, -28)
  },
  {
      Pair(-33, -27), Pair(-15, -37)
  },
  {
      Pair(-46, -22), Pair(-51, -40)
  },
  {
      Pair(-50, -51), Pair(-46, -57)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-15, -17), Pair(11, -15)
  },
  {
      Pair(-57, 3), Pair(-5, -12)
  },
  {
      Pair(-44, 2), Pair(-13, -4)
  },
  {
      Pair(-18, -34), Pair(-12, -5)
  },
  {
      Pair(-32, -101), Pair(-56, -35)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-66, 51), Pair(21, 48), Pair(36, 33), Pair(13, 38), Pair(23, 27), Pair(5, 39), Pair(20, 46), Pair(53, 46),
  Pair(42, -3), Pair(19, 11), Pair(19, 28), Pair(-6, 22), Pair(-1, 45), Pair(-24, 52), Pair(7, 32), Pair(14, 15),
  Pair(13, -9), Pair(-11, 18), Pair(12, 11), Pair(10, 15), Pair(6, 26), Pair(-5, 9), Pair(-17, 10), Pair(16, -13)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(36, 20), Pair(16, 20), Pair(28, 1), Pair(33, -5), Pair(36, 4), Pair(47, 9), Pair(14, 42), Pair(-1, -2),
  Pair(-65, 10), Pair(7, 15), Pair(5, 7), Pair(22, 8), Pair(21, -6), Pair(33, 44), Pair(13, 20), Pair(4, 6),
  Pair(-18, 20), Pair(0, 31), Pair(0, 23), Pair(7, 24), Pair(14, 26), Pair(4, 15), Pair(17, 2), Pair(0, -16)
};

constexpr ScorePair kBishopPairBonus = Pair(27, 55);

constexpr ScorePair kTempoBonus = Pair(20, 1);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H