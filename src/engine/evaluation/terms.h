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
  Pair(104, 99), Pair(375, 152), Pair(402, 171), Pair(543, 460), Pair(1205, 865), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(65, 48), Pair(45, 70), Pair(30, 73), Pair(43, 57), Pair(34, 61), Pair(36, 67), Pair(-19, 105), Pair(47, 42),
      Pair(-14, 13), Pair(-18, 21), Pair(-14, 8), Pair(14, -13), Pair(18, -13), Pair(32, -8), Pair(-5, 22), Pair(-8, 2),
      Pair(-22, 4), Pair(-16, 5), Pair(-15, -9), Pair(-2, -22), Pair(8, -19), Pair(1, -17), Pair(-9, 1), Pair(-20, -7),
      Pair(-28, -3), Pair(-32, 5), Pair(-16, -16), Pair(-7, -19), Pair(-3, -20), Pair(-3, -18), Pair(-20, 0), Pair(-25, -13),
      Pair(-30, -9), Pair(-34, -1), Pair(-30, -8), Pair(-25, -11), Pair(-22, -8), Pair(-19, -13), Pair(-9, -8), Pair(-23, -13),
      Pair(-29, 0), Pair(-20, 3), Pair(-27, -1), Pair(-27, -9), Pair(-22, -6), Pair(2, -9), Pair(3, -8), Pair(-24, -14),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-179, 53), Pair(-88, 52), Pair(-38, 46), Pair(23, 43), Pair(45, 38), Pair(-166, 82), Pair(-46, 54), Pair(-123, 40),
      Pair(-30, 56), Pair(-4, 57), Pair(20, 51), Pair(60, 53), Pair(38, 49), Pair(33, 46), Pair(3, 52), Pair(-14, 49),
      Pair(-4, 40), Pair(20, 53), Pair(13, 74), Pair(48, 61), Pair(55, 62), Pair(67, 59), Pair(12, 61), Pair(8, 43),
      Pair(10, 52), Pair(12, 68), Pair(31, 74), Pair(37, 77), Pair(26, 73), Pair(49, 66), Pair(20, 60), Pair(34, 48),
      Pair(2, 58), Pair(21, 56), Pair(21, 80), Pair(27, 80), Pair(27, 79), Pair(39, 71), Pair(31, 56), Pair(10, 67),
      Pair(-15, 40), Pair(6, 55), Pair(7, 65), Pair(18, 79), Pair(22, 72), Pair(16, 64), Pair(22, 54), Pair(-3, 52),
      Pair(-20, 38), Pair(-14, 59), Pair(-4, 48), Pair(10, 58), Pair(12, 58), Pair(10, 51), Pair(1, 57), Pair(-5, 46),
      Pair(-59, 30), Pair(-16, 39), Pair(-16, 43), Pair(-2, 59), Pair(2, 53), Pair(-4, 47), Pair(-14, 44), Pair(-26, 36)
  },
  {
      Pair(-52, 70), Pair(-58, 64), Pair(-24, 61), Pair(-49, 56), Pair(-2, 51), Pair(-66, 47), Pair(-61, 71), Pair(-35, 57),
      Pair(-31, 52), Pair(-1, 57), Pair(-18, 57), Pair(5, 59), Pair(-5, 49), Pair(-7, 54), Pair(-18, 61), Pair(-26, 57),
      Pair(-1, 54), Pair(13, 52), Pair(2, 67), Pair(25, 47), Pair(23, 52), Pair(30, 61), Pair(17, 46), Pair(9, 44),
      Pair(-5, 45), Pair(0, 60), Pair(17, 54), Pair(21, 60), Pair(15, 60), Pair(21, 48), Pair(4, 48), Pair(-2, 49),
      Pair(7, 44), Pair(-5, 55), Pair(4, 56), Pair(8, 56), Pair(12, 54), Pair(5, 54), Pair(0, 56), Pair(13, 43),
      Pair(-1, 46), Pair(16, 49), Pair(12, 54), Pair(8, 58), Pair(6, 65), Pair(12, 56), Pair(21, 43), Pair(7, 49),
      Pair(2, 47), Pair(12, 39), Pair(19, 37), Pair(1, 49), Pair(11, 45), Pair(19, 42), Pair(24, 39), Pair(23, 30),
      Pair(-8, 39), Pair(16, 39), Pair(-5, 46), Pair(3, 48), Pair(12, 39), Pair(-9, 51), Pair(3, 36), Pair(13, 22)
  },
  {
      Pair(9, 47), Pair(36, 43), Pair(28, 50), Pair(42, 38), Pair(48, 43), Pair(72, 35), Pair(26, 43), Pair(20, 46),
      Pair(11, 49), Pair(16, 51), Pair(28, 44), Pair(50, 35), Pair(38, 39), Pair(43, 41), Pair(2, 49), Pair(-3, 49),
      Pair(6, 45), Pair(28, 42), Pair(17, 42), Pair(32, 32), Pair(41, 31), Pair(39, 40), Pair(25, 35), Pair(7, 39),
      Pair(-2, 43), Pair(11, 42), Pair(27, 34), Pair(12, 35), Pair(27, 33), Pair(19, 35), Pair(14, 34), Pair(0, 39),
      Pair(-21, 44), Pair(-18, 49), Pair(3, 42), Pair(-5, 42), Pair(-11, 44), Pair(-11, 45), Pair(-12, 45), Pair(-25, 41),
      Pair(-29, 38), Pair(-22, 40), Pair(-19, 39), Pair(-21, 36), Pair(-19, 40), Pair(-18, 34), Pair(-7, 26), Pair(-20, 28),
      Pair(-30, 28), Pair(-18, 29), Pair(-4, 24), Pair(-6, 25), Pair(-4, 19), Pair(0, 17), Pair(-10, 14), Pair(-45, 18),
      Pair(-15, 28), Pair(-6, 24), Pair(-5, 29), Pair(2, 20), Pair(3, 19), Pair(1, 24), Pair(-18, 27), Pair(-13, 20)
  },
  {
      Pair(21, -16), Pair(62, -27), Pair(66, -19), Pair(44, -4), Pair(68, -13), Pair(71, -39), Pair(81, -36), Pair(59, -24),
      Pair(30, -25), Pair(21, 1), Pair(32, 23), Pair(29, 37), Pair(27, 32), Pair(60, 16), Pair(41, 11), Pair(88, -37),
      Pair(37, -30), Pair(52, -12), Pair(32, 28), Pair(45, 30), Pair(50, 35), Pair(67, 8), Pair(55, 4), Pair(58, -31),
      Pair(45, -36), Pair(42, -6), Pair(35, 18), Pair(40, 31), Pair(37, 40), Pair(50, 11), Pair(52, -6), Pair(63, -41),
      Pair(46, -53), Pair(36, -20), Pair(38, -2), Pair(31, 29), Pair(40, 7), Pair(45, -14), Pair(53, -27), Pair(49, -51),
      Pair(46, -53), Pair(49, -48), Pair(44, -26), Pair(43, -25), Pair(45, -27), Pair(50, -31), Pair(57, -50), Pair(53, -69),
      Pair(43, -83), Pair(49, -80), Pair(58, -82), Pair(55, -62), Pair(57, -72), Pair(67, -103), Pair(61, -104), Pair(63, -128),
      Pair(56, -115), Pair(47, -99), Pair(47, -94), Pair(48, -93), Pair(51, -93), Pair(40, -115), Pair(49, -106), Pair(58, -105)
  },
  {
      Pair(-96, -91), Pair(57, 21), Pair(124, 6), Pair(-7, 23), Pair(87, 6), Pair(143, -31), Pair(181, -42), Pair(209, -186),
      Pair(-24, -24), Pair(127, -4), Pair(116, 5), Pair(5, 17), Pair(53, 7), Pair(139, 1), Pair(145, -3), Pair(16, -52),
      Pair(19, -13), Pair(131, -11), Pair(109, 3), Pair(-59, 29), Pair(-119, 39), Pair(-15, 15), Pair(151, -18), Pair(69, -30),
      Pair(-8, -25), Pair(51, -12), Pair(-16, 13), Pair(-88, 27), Pair(-138, 30), Pair(-11, 3), Pair(26, -12), Pair(0, -31),
      Pair(-36, -41), Pair(27, -20), Pair(-10, 3), Pair(-74, 25), Pair(-59, 16), Pair(-20, -1), Pair(-6, -16), Pair(-56, -35),
      Pair(-29, -32), Pair(17, -20), Pair(-11, -3), Pair(-44, 16), Pair(-48, 14), Pair(-36, 3), Pair(-6, -14), Pair(-33, -29),
      Pair(20, -40), Pair(-3, -11), Pair(-18, -1), Pair(-44, 8), Pair(-40, 7), Pair(-25, 1), Pair(-8, -10), Pair(9, -36),
      Pair(-21, -20), Pair(26, -32), Pair(15, -18), Pair(-50, -3), Pair(-7, -23), Pair(-33, -11), Pair(16, -25), Pair(20, -55)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-8, 7), Pair(5, 1), Pair(13, 24), Pair(18, 34), Pair(23, 39), Pair(27, 45), Pair(30, 43), Pair(36, 35),
  Pair(40, 18)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-10, -2), Pair(2, -7), Pair(8, 10), Pair(12, 21), Pair(17, 30), Pair(18, 35), Pair(22, 36), Pair(23, 37),
  Pair(25, 39), Pair(33, 34), Pair(39, 30), Pair(44, 26), Pair(56, 27), Pair(16, 25)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-15, -103), Pair(-5, -72), Pair(-2, -58), Pair(4, -46), Pair(5, -39), Pair(9, -34), Pair(12, -30), Pair(16, -29),
  Pair(20, -23), Pair(23, -23), Pair(30, -24), Pair(32, -22), Pair(40, -24), Pair(51, -31), Pair(126, -60)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(30, -170), Pair(34, -198), Pair(37, -190), Pair(39, -181), Pair(40, -150), Pair(40, -119), Pair(42, -105), Pair(44, -98),
  Pair(45, -90), Pair(47, -79), Pair(49, -74), Pair(50, -70), Pair(50, -61), Pair(50, -58), Pair(49, -59), Pair(51, -59),
  Pair(58, -73), Pair(58, -75), Pair(67, -90), Pair(83, -115), Pair(113, -143), Pair(186, -213), Pair(171, -204), Pair(124, -219),
  Pair(119, -209), Pair(-29, -183), Pair(-35, -154), Pair(-93, -181)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-24, -58), Pair(-28, -43), Pair(-14, -18), Pair(9, 11), Pair(30, 49), Pair(50, 30), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(4, 7), Pair(11, 6), Pair(16, 18), Pair(34, 53), Pair(148, 132), Pair(250, 311), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(18, 10), Pair(14, 6), Pair(15, 14), Pair(45, 29), Pair(219, -12), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-39, -27), Pair(-8, -21), Pair(-12, -17), Pair(-20, -5), Pair(-16, -3), Pair(-15, -12), Pair(-5, -18), Pair(-15, -31)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(5, 0), Pair(-4, -8), Pair(-10, -4), Pair(-12, -8), Pair(-15, -13), Pair(-4, -8), Pair(0, -10), Pair(-3, 0)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(25, -3), Pair(18, -1), Pair(18, 7), Pair(22, 4), Pair(29, 1), Pair(33, -3), Pair(44, -4), Pair(57, -8)
  },
  {
      Pair(21, 18), Pair(12, 5), Pair(18, 2), Pair(22, -5), Pair(21, -6), Pair(18, -8), Pair(30, -4), Pair(22, 4)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(10, -5), Pair(13, -11), Pair(10, -6),
  Pair(19, -8), Pair(16, -10), Pair(18, -9),
  Pair(20, 3), Pair(0, 0), Pair(20, 2),
  Pair(5, 7), Pair(-25, 11), Pair(5, 8)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-9, 3), Pair(-15, 12), Pair(-9, 6),
  Pair(-10, 3), Pair(-19, 11), Pair(-10, 5),
  Pair(0, -6), Pair(-10, 3), Pair(-1, -5),
  Pair(9, -7), Pair(-9, 0), Pair(7, -6),
  Pair(23, -14), Pair(23, -4), Pair(21, -16),
  Pair(0, 0), Pair(-62, -1), Pair(0, 0),
  Pair(39, -46), Pair(0, 0), Pair(44, -48)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(10, 40), Pair(-13, 40), Pair(-7, 20), Pair(-4, 9), Pair(-2, 12), Pair(8, 12), Pair(-8, 8)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-16, -19), Pair(-2, 4), Pair(2, 29), Pair(10, 40), Pair(14, 47), Pair(12, 51), Pair(1, 59)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(10, 163);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-68, 11), Pair(-60, 3), Pair(-29, -14), Pair(-7, -20), Pair(-16, -15), Pair(-24, -9), Pair(-46, -2), Pair(-58, 14)
  },
  {
      Pair(-4, 37), Pair(-35, 20), Pair(-20, 7), Pair(-4, -2), Pair(-9, -1), Pair(-13, 6), Pair(-22, 17), Pair(-27, 33)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 1), Pair(19, -2), Pair(67, -19), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 2), Pair(20, 5), Pair(30, 4), Pair(-6, -1), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -16), Pair(23, -13), Pair(44, -12), Pair(65, -14), Pair(63, -18), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 17), Pair(10, 30), Pair(23, 36), Pair(63, 14), Pair(118, -2), Pair(207, -46), Pair(261, -86)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(26, -1), Pair(8, 15), Pair(50, -8), Pair(17, 8), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-6, 36), Pair(5, 28)
  },
  {
      Pair(-63, -14), Pair(-57, -27)
  },
  {
      Pair(-49, -40), Pair(-51, -50)
  },
  {
      Pair(-73, -18), Pair(-55, -17)
  },
  {
      Pair(-44, -8), Pair(-50, 18)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(14, 29), Pair(22, 14), Pair(22, 11), Pair(21, -18), Pair(31, 2)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -25), Pair(6, -12)
  },
  {
      Pair(-17, -31), Pair(-14, -38)
  },
  {
      Pair(-40, -7), Pair(-32, -25)
  },
  {
      Pair(-67, 4), Pair(-51, -8)
  },
  {
      Pair(-40, -6), Pair(-31, -32)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-16, -22), Pair(0, -8)
  },
  {
      Pair(-42, -9), Pair(-18, -28)
  },
  {
      Pair(-25, -47), Pair(-12, -52)
  },
  {
      Pair(-43, -16), Pair(-46, -39)
  },
  {
      Pair(-45, -43), Pair(-40, -61)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-9, -22), Pair(10, -15)
  },
  {
      Pair(-46, -6), Pair(-5, -13)
  },
  {
      Pair(-33, -10), Pair(-12, -6)
  },
  {
      Pair(0, -71), Pair(3, -48)
  },
  {
      Pair(-48, -29), Pair(-51, -31)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-26, 32), Pair(12, 33), Pair(30, 24), Pair(10, 28), Pair(18, 20), Pair(5, 31), Pair(17, 32), Pair(40, 31),
  Pair(24, 1), Pair(15, 8), Pair(15, 21), Pair(-2, 21), Pair(6, 29), Pair(-11, 32), Pair(9, 21), Pair(10, 13),
  Pair(9, -1), Pair(-7, 14), Pair(6, 10), Pair(9, 11), Pair(5, 20), Pair(-2, 8), Pair(-9, 8), Pair(9, -5)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(11, 20), Pair(22, 6), Pair(27, -1), Pair(30, 0), Pair(36, -3), Pair(40, 4), Pair(15, 18), Pair(-14, -7),
  Pair(-42, 7), Pair(9, 11), Pair(7, 3), Pair(13, 14), Pair(13, 1), Pair(28, 21), Pair(12, 14), Pair(9, -5),
  Pair(-12, 12), Pair(3, 21), Pair(2, 19), Pair(11, 17), Pair(16, 20), Pair(2, 14), Pair(14, 0), Pair(-16, -6)
};

constexpr ScorePair kBishopPairBonus = Pair(19, 57);

constexpr ScorePair kTempoBonus = Pair(19, 4);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H