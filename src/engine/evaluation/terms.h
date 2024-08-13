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
  Pair(90, 138), Pair(333, 275), Pair(367, 312), Pair(491, 555), Pair(1025, 956), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(55, 51), Pair(25, 74), Pair(39, 51), Pair(51, 40), Pair(56, 36), Pair(24, 57), Pair(-22, 74), Pair(18, 48),
      Pair(1, -14), Pair(-5, -10), Pair(2, -27), Pair(12, -47), Pair(24, -49), Pair(41, -45), Pair(1, -5), Pair(1, -24),
      Pair(-18, -20), Pair(-14, -21), Pair(-12, -35), Pair(-4, -50), Pair(7, -50), Pair(5, -48), Pair(-7, -24), Pair(-14, -37),
      Pair(-26, -32), Pair(-27, -21), Pair(-15, -42), Pair(-6, -48), Pair(-3, -52), Pair(-2, -47), Pair(-13, -28), Pair(-20, -44),
      Pair(-32, -35), Pair(-32, -26), Pair(-28, -38), Pair(-25, -37), Pair(-20, -40), Pair(-22, -41), Pair(-11, -31), Pair(-21, -48),
      Pair(-26, -29), Pair(-19, -21), Pair(-21, -31), Pair(-24, -34), Pair(-19, -32), Pair(2, -39), Pair(2, -29), Pair(-18, -46),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-137, -11), Pair(-89, 12), Pair(-42, 8), Pair(40, -15), Pair(67, -19), Pair(-114, 21), Pair(-30, 1), Pair(-120, -26),
      Pair(-26, 10), Pair(-10, 15), Pair(18, 8), Pair(47, 3), Pair(43, 3), Pair(48, -5), Pair(2, 13), Pair(0, 2),
      Pair(-8, 8), Pair(19, 4), Pair(24, 17), Pair(44, 13), Pair(46, 13), Pair(60, 5), Pair(13, 14), Pair(15, -5),
      Pair(17, 5), Pair(13, 21), Pair(36, 17), Pair(41, 22), Pair(36, 26), Pair(42, 22), Pair(25, 19), Pair(27, 8),
      Pair(7, 11), Pair(18, 9), Pair(27, 26), Pair(27, 27), Pair(29, 28), Pair(36, 21), Pair(33, 14), Pair(12, 16),
      Pair(-14, -4), Pair(5, 11), Pair(9, 17), Pair(25, 25), Pair(25, 23), Pair(17, 14), Pair(18, 7), Pair(-3, 7),
      Pair(-16, 2), Pair(-7, 10), Pair(-2, 6), Pair(8, 10), Pair(11, 10), Pair(6, 4), Pair(9, 5), Pair(-2, 0),
      Pair(-52, -14), Pair(-19, -5), Pair(-8, 5), Pair(1, 2), Pair(11, 2), Pair(-3, -3), Pair(-17, 3), Pair(-27, -8)
  },
  {
      Pair(-38, 26), Pair(-28, 16), Pair(-78, 17), Pair(-59, 10), Pair(-14, 5), Pair(-69, 5), Pair(-37, 13), Pair(-60, 9),
      Pair(-25, 8), Pair(-19, 16), Pair(-14, 10), Pair(-15, 12), Pair(-16, 8), Pair(-3, 3), Pair(-40, 21), Pair(-12, -5),
      Pair(-8, 9), Pair(4, 7), Pair(-4, 17), Pair(11, 7), Pair(23, 5), Pair(24, 15), Pair(15, 6), Pair(10, 2),
      Pair(-14, 3), Pair(-1, 10), Pair(5, 9), Pair(15, 12), Pair(11, 12), Pair(17, 11), Pair(-1, 7), Pair(3, 1),
      Pair(-6, -1), Pair(-11, 6), Pair(4, 8), Pair(3, 11), Pair(7, 6), Pair(2, 5), Pair(7, 4), Pair(2, -2),
      Pair(-10, 0), Pair(11, 7), Pair(6, 10), Pair(5, 11), Pair(3, 16), Pair(13, 8), Pair(9, 10), Pair(2, -2),
      Pair(5, -8), Pair(7, -9), Pair(6, -2), Pair(-2, 3), Pair(6, 4), Pair(10, -3), Pair(19, -8), Pair(7, -12),
      Pair(-3, -10), Pair(3, 0), Pair(-7, 1), Pair(-6, 6), Pair(1, 1), Pair(-12, 8), Pair(10, -5), Pair(6, -13)
  },
  {
      Pair(18, 18), Pair(9, 30), Pair(15, 31), Pair(15, 27), Pair(8, 30), Pair(40, 19), Pair(23, 27), Pair(20, 16),
      Pair(-3, 24), Pair(4, 26), Pair(16, 22), Pair(34, 13), Pair(23, 15), Pair(37, 13), Pair(5, 23), Pair(8, 15),
      Pair(-7, 22), Pair(18, 20), Pair(14, 18), Pair(23, 9), Pair(38, 5), Pair(41, 8), Pair(32, 12), Pair(-3, 15),
      Pair(-9, 21), Pair(3, 21), Pair(10, 19), Pair(16, 9), Pair(12, 13), Pair(16, 12), Pair(8, 16), Pair(-13, 15),
      Pair(-29, 21), Pair(-23, 29), Pair(-18, 24), Pair(-20, 22), Pair(-16, 16), Pair(-19, 23), Pair(-13, 18), Pair(-27, 12),
      Pair(-38, 15), Pair(-25, 20), Pair(-26, 20), Pair(-23, 13), Pair(-20, 7), Pair(-24, 12), Pair(-11, 4), Pair(-24, -3),
      Pair(-35, 2), Pair(-27, 7), Pair(-16, 7), Pair(-15, 1), Pair(-12, -2), Pair(-12, 0), Pair(-9, -7), Pair(-43, -5),
      Pair(-20, 0), Pair(-15, 0), Pair(-13, 4), Pair(-7, -2), Pair(-5, -6), Pair(-6, -1), Pair(-20, 1), Pair(-19, -8)
  },
  {
      Pair(-8, 49), Pair(20, 41), Pair(7, 65), Pair(30, 50), Pair(49, 32), Pair(50, 28), Pair(40, 47), Pair(11, 59),
      Pair(-8, 50), Pair(-26, 90), Pair(-13, 91), Pair(-6, 96), Pair(-27, 111), Pair(8, 86), Pair(-8, 89), Pair(24, 49),
      Pair(-8, 55), Pair(6, 53), Pair(-1, 80), Pair(1, 90), Pair(7, 94), Pair(15, 89), Pair(19, 66), Pair(9, 63),
      Pair(-1, 44), Pair(-4, 69), Pair(-3, 87), Pair(-4, 96), Pair(2, 97), Pair(8, 76), Pair(6, 81), Pair(16, 43),
      Pair(-3, 34), Pair(-13, 70), Pair(-7, 72), Pair(-9, 92), Pair(0, 76), Pair(-5, 67), Pair(9, 45), Pair(3, 36),
      Pair(-8, 40), Pair(0, 36), Pair(-3, 52), Pair(-2, 56), Pair(-3, 57), Pair(4, 42), Pair(9, 32), Pair(5, 25),
      Pair(-2, 11), Pair(3, 10), Pair(8, 6), Pair(5, 24), Pair(8, 12), Pair(13, -4), Pair(16, -16), Pair(14, -15),
      Pair(10, -18), Pair(-6, -2), Pair(0, -8), Pair(-2, -2), Pair(-1, 4), Pair(-11, -17), Pair(11, -59), Pair(-2, -3)
  },
  {
      Pair(78, -137), Pair(155, -29), Pair(3, 25), Pair(11, 2), Pair(53, -11), Pair(-11, 22), Pair(23, 5), Pair(85, -161),
      Pair(2, -14), Pair(46, 31), Pair(20, 32), Pair(2, 26), Pair(1, 26), Pair(40, 37), Pair(-1, 37), Pair(-50, -25),
      Pair(-32, 9), Pair(56, 27), Pair(0, 41), Pair(-46, 43), Pair(-88, 61), Pair(-16, 47), Pair(15, 34), Pair(-8, -5),
      Pair(-24, -5), Pair(42, 4), Pair(-69, 41), Pair(-111, 47), Pair(-127, 48), Pair(-46, 28), Pair(-2, 4), Pair(-65, -9),
      Pair(-16, -30), Pair(38, -8), Pair(-23, 18), Pair(-77, 35), Pair(-70, 30), Pair(-53, 15), Pair(-12, -9), Pair(-101, -13),
      Pair(-8, -23), Pair(12, -7), Pair(-26, 13), Pair(-41, 21), Pair(-51, 23), Pair(-40, 9), Pair(-16, -7), Pair(-39, -23),
      Pair(20, -30), Pair(3, -6), Pair(-13, 4), Pair(-22, 7), Pair(-31, 10), Pair(-22, 2), Pair(-2, -12), Pair(19, -40),
      Pair(11, -65), Pair(33, -34), Pair(24, -21), Pair(-27, -5), Pair(0, -24), Pair(-19, -13), Pair(22, -29), Pair(26, -68)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-22, -33), Pair(-6, -1), Pair(3, 16), Pair(8, 26), Pair(13, 31), Pair(16, 39), Pair(20, 38), Pair(23, 37),
  Pair(28, 29)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-26, -43), Pair(-14, -30), Pair(-7, -16), Pair(-2, -6), Pair(2, 2), Pair(5, 8), Pair(8, 11), Pair(10, 14),
  Pair(13, 16), Pair(16, 15), Pair(22, 13), Pair(29, 15), Pair(36, 10), Pair(51, 9)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-42, -47), Pair(-28, -30), Pair(-24, -20), Pair(-20, -6), Pair(-18, 0), Pair(-15, 4), Pair(-12, 7), Pair(-9, 10),
  Pair(-5, 13), Pair(-1, 15), Pair(2, 16), Pair(7, 17), Pair(10, 19), Pair(25, 12), Pair(45, 4)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-14, -183), Pair(-8, -119), Pair(-6, -35), Pair(-2, -28), Pair(-1, 0), Pair(1, 20), Pair(3, 27), Pair(5, 37),
  Pair(7, 45), Pair(9, 51), Pair(9, 61), Pair(11, 62), Pair(12, 65), Pair(13, 66), Pair(16, 65), Pair(17, 66),
  Pair(20, 60), Pair(25, 49), Pair(39, 35), Pair(41, 27), Pair(53, 10), Pair(90, -22), Pair(101, -37), Pair(142, -65),
  Pair(151, -81), Pair(248, -141), Pair(200, -95), Pair(95, -64)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-5, -75), Pair(-6, -60), Pair(0, -31), Pair(19, 3), Pair(28, 62), Pair(46, 38), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(14, 4), Pair(17, 19), Pair(34, 60), Pair(135, 115), Pair(18, 451), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(19, 8), Pair(15, 6), Pair(15, 15), Pair(34, 39), Pair(151, 16), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-23, -41), Pair(-1, -24), Pair(-9, -18), Pair(-13, -8), Pair(-13, -2), Pair(-13, -15), Pair(-4, -27), Pair(-18, -39)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(1, 4), Pair(-3, -11), Pair(-8, -8), Pair(-11, -12), Pair(-10, -15), Pair(-4, -9), Pair(-3, -14), Pair(-2, 5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(24, 1), Pair(21, 0), Pair(18, 5), Pair(24, 3), Pair(26, 3), Pair(33, -2), Pair(37, -6), Pair(48, -3)
  },
  {
      Pair(17, 26), Pair(16, 4), Pair(20, -1), Pair(18, 2), Pair(19, -2), Pair(16, -7), Pair(24, -3), Pair(22, 14)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -4), Pair(14, -7), Pair(10, -3),
  Pair(19, -7), Pair(16, -5), Pair(19, -7),
  Pair(27, -2), Pair(0, 0), Pair(22, 0),
  Pair(6, 5), Pair(-12, 9), Pair(5, 10)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, 1), Pair(-13, 7), Pair(-7, 3),
  Pair(-7, -1), Pair(-15, 7), Pair(-7, 2),
  Pair(0, -8), Pair(-9, 1), Pair(1, -7),
  Pair(8, -7), Pair(-9, -2), Pair(10, -8),
  Pair(22, -14), Pair(20, -6), Pair(20, -14),
  Pair(0, 0), Pair(-57, -4), Pair(0, 0),
  Pair(32, -47), Pair(0, 0), Pair(36, -46)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(0, 49), Pair(-15, 45), Pair(-8, 26), Pair(-6, 13), Pair(-2, 10), Pair(12, 8), Pair(-1, 8)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-38, -9), Pair(-7, 10), Pair(-5, 34), Pair(-3, 47), Pair(0, 54), Pair(-2, 57), Pair(-17, 62)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-391, 95);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-68, 5), Pair(-57, -4), Pair(-19, -15), Pair(-26, -7), Pair(-16, -8), Pair(-25, -2), Pair(-41, 3), Pair(-46, 10)
  },
  {
      Pair(-37, 46), Pair(-38, 23), Pair(-18, 10), Pair(-14, 5), Pair(-6, -2), Pair(-12, 11), Pair(-24, 25), Pair(-21, 30)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 2), Pair(16, -2), Pair(56, -20), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 2), Pair(16, 4), Pair(31, 1), Pair(7, -7), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -15), Pair(24, -14), Pair(37, -8), Pair(46, -5), Pair(39, -9), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 19), Pair(9, 31), Pair(20, 38), Pair(53, 26), Pair(90, 18), Pair(148, -10), Pair(178, -47)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(30, 0), Pair(12, 17), Pair(41, -1), Pair(17, 13), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-6, 28), Pair(-2, 28)
  },
  {
      Pair(-63, -19), Pair(-54, -26)
  },
  {
      Pair(-48, -43), Pair(-46, -51)
  },
  {
      Pair(-69, -21), Pair(-51, -31)
  },
  {
      Pair(-44, -4), Pair(-47, 8)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(12, 28), Pair(20, 19), Pair(20, 11), Pair(19, 0), Pair(30, -1)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -23), Pair(7, -11)
  },
  {
      Pair(18, -24), Pair(20, -31)
  },
  {
      Pair(-38, -11), Pair(-31, -25)
  },
  {
      Pair(-63, 0), Pair(-50, -11)
  },
  {
      Pair(-35, -9), Pair(-32, -23)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-13, -19), Pair(1, -8)
  },
  {
      Pair(-42, -15), Pair(-18, -29)
  },
  {
      Pair(7, -100), Pair(13, -108)
  },
  {
      Pair(-50, -15), Pair(-45, -34)
  },
  {
      Pair(-44, -37), Pair(-41, -24)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-7, -26), Pair(9, -14)
  },
  {
      Pair(-34, -16), Pair(-7, -13)
  },
  {
      Pair(-33, -18), Pair(-13, -9)
  },
  {
      Pair(2, 14), Pair(0, 34)
  },
  {
      Pair(-57, -11), Pair(-44, -43)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(35, 13), Pair(6, 20), Pair(26, 12), Pair(6, 27), Pair(25, 29), Pair(16, 24), Pair(27, 18), Pair(13, 44),
  Pair(11, 22), Pair(12, 10), Pair(4, 25), Pair(-1, 26), Pair(3, 27), Pair(0, 19), Pair(6, 13), Pair(5, 11),
  Pair(2, 10), Pair(-8, 16), Pair(0, 13), Pair(7, 12), Pair(2, 17), Pair(-2, 7), Pair(-9, 12), Pair(7, 4)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-16, 14), Pair(23, 10), Pair(23, 3), Pair(38, -5), Pair(58, -10), Pair(45, -8), Pair(25, 9), Pair(-6, 19),
  Pair(-11, -27), Pair(13, 16), Pair(6, 12), Pair(15, 12), Pair(11, 13), Pair(4, 4), Pair(10, 16), Pair(12, 2),
  Pair(-9, 28), Pair(5, 20), Pair(4, 14), Pair(19, 13), Pair(18, 16), Pair(0, 16), Pair(2, 11), Pair(-36, 28)
};

constexpr ScorePair kBishopPairBonus = Pair(18, 56);

constexpr ScorePair kTempoBonus = Pair(17, 6);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H