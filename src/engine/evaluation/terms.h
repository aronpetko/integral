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
  Pair(104, 101), Pair(392, 133), Pair(405, 199), Pair(584, 481), Pair(1224, 853), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(85, -17), Pair(54, 7), Pair(38, 8), Pair(54, -13), Pair(33, 1), Pair(46, 4), Pair(-19, 27), Pair(48, -21),
      Pair(-4, 20), Pair(-12, 36), Pair(8, 10), Pair(13, -2), Pair(19, 0), Pair(45, -4), Pair(4, 27), Pair(0, 15),
      Pair(-19, 12), Pair(-9, 11), Pair(-11, -5), Pair(-5, -16), Pair(13, -14), Pair(9, -15), Pair(2, 3), Pair(-12, -1),
      Pair(-27, 0), Pair(-25, 11), Pair(-15, -9), Pair(-4, -16), Pair(-2, -19), Pair(2, -13), Pair(-9, 0), Pair(-17, -8),
      Pair(-34, 0), Pair(-29, 7), Pair(-29, -6), Pair(-24, -7), Pair(-17, -11), Pair(-18, -4), Pair(-1, -6), Pair(-19, -11),
      Pair(-30, 7), Pair(-17, 13), Pair(-23, 4), Pair(-24, 1), Pair(-18, 1), Pair(5, 0), Pair(12, 0), Pair(-17, -8),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-199, 19), Pair(-74, 6), Pair(-70, 1), Pair(21, -4), Pair(25, -15), Pair(-100, 2), Pair(-56, -9), Pair(-79, -9),
      Pair(-25, -14), Pair(-14, 8), Pair(25, -11), Pair(44, 0), Pair(57, -9), Pair(45, -19), Pair(-25, 9), Pair(-4, -15),
      Pair(-6, -2), Pair(20, 1), Pair(17, 19), Pair(35, 6), Pair(52, 4), Pair(67, -1), Pair(15, -1), Pair(14, -9),
      Pair(12, 0), Pair(12, 10), Pair(29, 14), Pair(34, 19), Pair(29, 12), Pair(46, 10), Pair(22, 4), Pair(26, -5),
      Pair(2, 5), Pair(11, 2), Pair(22, 21), Pair(27, 20), Pair(30, 16), Pair(38, 5), Pair(34, 1), Pair(11, 14),
      Pair(-23, -9), Pair(3, 0), Pair(3, 11), Pair(17, 22), Pair(23, 14), Pair(12, 6), Pair(17, -4), Pair(-3, -8),
      Pair(-32, -13), Pair(-8, 10), Pair(-8, -4), Pair(4, 3), Pair(5, 2), Pair(5, -10), Pair(-6, -4), Pair(-10, -9),
      Pair(-62, -17), Pair(-27, -9), Pair(-13, -16), Pair(-9, -10), Pair(1, -4), Pair(-8, -16), Pair(-25, -8), Pair(-28, -30)
  },
  {
      Pair(-52, 9), Pair(-25, 9), Pair(-28, -2), Pair(-31, 2), Pair(-11, 2), Pair(-97, 8), Pair(11, -3), Pair(-41, 0),
      Pair(-22, 2), Pair(-12, 8), Pair(-12, 9), Pair(4, 2), Pair(-21, 5), Pair(8, 0), Pair(-21, 9), Pair(-13, -7),
      Pair(-1, 5), Pair(9, 2), Pair(4, 10), Pair(18, 3), Pair(42, -7), Pair(28, 7), Pair(25, -3), Pair(4, 1),
      Pair(-9, 0), Pair(0, 8), Pair(5, 10), Pair(25, 13), Pair(8, 15), Pair(23, 1), Pair(-3, 6), Pair(10, -8),
      Pair(1, -11), Pair(-2, 6), Pair(4, 11), Pair(2, 6), Pair(14, 1), Pair(-1, 8), Pair(5, 1), Pair(3, -12),
      Pair(-7, -2), Pair(9, 5), Pair(5, 9), Pair(8, 9), Pair(5, 13), Pair(17, 3), Pair(15, -1), Pair(5, -4),
      Pair(4, -3), Pair(5, -12), Pair(18, -16), Pair(-1, 0), Pair(10, -3), Pair(15, -9), Pair(23, -13), Pair(14, -26),
      Pair(-5, -12), Pair(15, -10), Pair(-8, -1), Pair(-2, -7), Pair(8, -7), Pair(-10, 1), Pair(4, -16), Pair(8, -23)
  },
  {
      Pair(26, 6), Pair(31, 15), Pair(21, 24), Pair(29, 14), Pair(31, 8), Pair(85, -8), Pair(16, 12), Pair(16, 12),
      Pair(-7, 16), Pair(8, 18), Pair(18, 15), Pair(40, 4), Pair(30, 3), Pair(46, -1), Pair(-1, 11), Pair(2, 8),
      Pair(-4, 9), Pair(29, 1), Pair(29, 3), Pair(21, -1), Pair(42, -8), Pair(54, -7), Pair(29, -2), Pair(1, 3),
      Pair(-13, 7), Pair(7, 8), Pair(20, 4), Pair(18, 0), Pair(35, -11), Pair(17, 1), Pair(12, 1), Pair(-10, 2),
      Pair(-32, 9), Pair(-21, 14), Pair(-21, 17), Pair(-16, 8), Pair(-18, 0), Pair(-21, 12), Pair(-22, 8), Pair(-30, 5),
      Pair(-35, -5), Pair(-21, 2), Pair(-28, 7), Pair(-23, 2), Pair(-10, -9), Pair(-24, -3), Pair(-13, -8), Pair(-33, -8),
      Pair(-38, -12), Pair(-30, -5), Pair(-15, -7), Pair(-13, -13), Pair(-13, -17), Pair(-12, -16), Pair(-15, -22), Pair(-53, -11),
      Pair(-22, -14), Pair(-17, -12), Pair(-15, -6), Pair(-7, -18), Pair(-3, -24), Pair(-8, -16), Pair(-27, -9), Pair(-24, -17)
  },
  {
      Pair(4, -1), Pair(11, 8), Pair(-23, 36), Pair(18, 6), Pair(26, 5), Pair(55, -21), Pair(45, -8), Pair(21, 0),
      Pair(-21, 20), Pair(-31, 43), Pair(-16, 44), Pair(-15, 50), Pair(-1, 43), Pair(5, 31), Pair(-8, 48), Pair(20, 16),
      Pair(-16, 8), Pair(-7, 28), Pair(-8, 55), Pair(-7, 61), Pair(8, 55), Pair(13, 48), Pair(30, 14), Pair(3, 12),
      Pair(-12, 10), Pair(-4, 25), Pair(-2, 36), Pair(-11, 58), Pair(-8, 61), Pair(-1, 35), Pair(1, 21), Pair(12, -9),
      Pair(-9, -9), Pair(-11, 15), Pair(-11, 25), Pair(-12, 45), Pair(-3, 32), Pair(-4, 20), Pair(7, 7), Pair(-5, -8),
      Pair(-12, -14), Pair(-3, -2), Pair(-8, 13), Pair(-9, 8), Pair(-4, 4), Pair(5, -11), Pair(7, -25), Pair(4, -33),
      Pair(-6, -37), Pair(-1, -46), Pair(2, -39), Pair(1, -32), Pair(3, -27), Pair(11, -60), Pair(19, -76), Pair(7, -68),
      Pair(-3, -51), Pair(-7, -65), Pair(-9, -57), Pair(-8, -46), Pair(-7, -48), Pair(-1, -88), Pair(-10, -104), Pair(-6, -61)
  },
  {
      Pair(150, -127), Pair(-39, 82), Pair(122, 28), Pair(27, 33), Pair(-64, 57), Pair(58, 34), Pair(-5, 53), Pair(162, -117),
      Pair(-12, 3), Pair(83, 49), Pair(64, 39), Pair(50, 36), Pair(49, 37), Pair(44, 42), Pair(48, 55), Pair(-49, -17),
      Pair(56, -6), Pair(97, 35), Pair(54, 40), Pair(-51, 52), Pair(-33, 54), Pair(50, 37), Pair(90, 18), Pair(65, -3),
      Pair(14, -10), Pair(66, 11), Pair(-3, 40), Pair(-77, 50), Pair(-97, 52), Pair(-11, 32), Pair(46, 5), Pair(-31, -7),
      Pair(-12, -32), Pair(35, 3), Pair(-25, 29), Pair(-64, 41), Pair(-63, 40), Pair(-21, 23), Pair(18, -2), Pair(-52, -5),
      Pair(-31, -15), Pair(18, 4), Pair(-16, 19), Pair(-36, 33), Pair(-45, 35), Pair(-26, 22), Pair(-2, 4), Pair(-26, -10),
      Pair(30, -25), Pair(5, 6), Pair(-12, 17), Pair(-29, 26), Pair(-37, 29), Pair(-27, 24), Pair(-2, 7), Pair(13, -18),
      Pair(2, -25), Pair(27, -11), Pair(18, 0), Pair(-46, 10), Pair(-8, -3), Pair(-29, 9), Pair(18, -8), Pair(21, -35)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-8, 61), Pair(10, 94), Pair(20, 109), Pair(26, 120), Pair(31, 127), Pair(35, 135), Pair(40, 131), Pair(44, 128),
  Pair(47, 112)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-2, 23), Pair(14, 36), Pair(21, 49), Pair(27, 58), Pair(32, 68), Pair(35, 72), Pair(37, 74), Pair(40, 77),
  Pair(43, 76), Pair(49, 74), Pair(60, 69), Pair(61, 66), Pair(82, 69), Pair(57, 59)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-32, -46), Pair(-18, -29), Pair(-13, -17), Pair(-9, -7), Pair(-8, 4), Pair(-5, 9), Pair(-2, 12), Pair(2, 14),
  Pair(4, 21), Pair(11, 20), Pair(16, 19), Pair(21, 21), Pair(22, 26), Pair(38, 14), Pair(86, -8)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(15, -124), Pair(21, -141), Pair(23, -90), Pair(27, -46), Pair(29, -18), Pair(30, -11), Pair(32, 4), Pair(33, 21),
  Pair(35, 24), Pair(38, 29), Pair(39, 33), Pair(41, 38), Pair(44, 36), Pair(45, 40), Pair(44, 41), Pair(48, 40),
  Pair(51, 34), Pair(57, 21), Pair(66, 9), Pair(73, -5), Pair(86, -22), Pair(128, -60), Pair(137, -65), Pair(194, -114),
  Pair(242, -149), Pair(422, -243), Pair(173, -145), Pair(270, -183)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-17, -89), Pair(-18, -72), Pair(-9, -44), Pair(13, -12), Pair(45, 26), Pair(68, 76), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(13, 2), Pair(20, 19), Pair(44, 57), Pair(184, 113), Pair(163, 339), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 7), Pair(16, 5), Pair(18, 14), Pair(42, 34), Pair(144, 23), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-32, -40), Pair(-9, -25), Pair(-12, -17), Pair(-11, -8), Pair(-18, -1), Pair(-19, -15), Pair(-5, -19), Pair(-30, -26)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(3, 2), Pair(-3, -13), Pair(-9, -7), Pair(-11, -13), Pair(-15, -15), Pair(-4, -7), Pair(-8, -6), Pair(3, -5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(32, -2), Pair(22, -2), Pair(20, 3), Pair(24, 3), Pair(26, 7), Pair(27, 1), Pair(44, -4), Pair(59, -6)
  },
  {
      Pair(20, 25), Pair(16, 0), Pair(20, -4), Pair(19, -4), Pair(20, -2), Pair(18, -7), Pair(31, -7), Pair(31, 5)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(14, -8), Pair(15, -14), Pair(13, -6),
  Pair(21, -9), Pair(16, -12), Pair(20, -9),
  Pair(25, -2), Pair(0, 0), Pair(24, -2),
  Pair(-2, 8), Pair(-26, 9), Pair(-15, 13)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, 2), Pair(-15, 11), Pair(-9, 6),
  Pair(-8, 1), Pair(-18, 12), Pair(-11, 5),
  Pair(0, -7), Pair(-9, 3), Pair(-1, -5),
  Pair(12, -9), Pair(-10, -2), Pair(10, -6),
  Pair(20, -17), Pair(27, -7), Pair(20, -15),
  Pair(0, 0), Pair(-70, 2), Pair(0, 0),
  Pair(24, -42), Pair(0, 0), Pair(28, -43)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(0, 38), Pair(-14, 33), Pair(-10, 14), Pair(-3, 2), Pair(-7, 3), Pair(8, 2), Pair(9, -4)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-7, 6), Pair(1, 33), Pair(5, 59), Pair(7, 76), Pair(8, 84), Pair(8, 85), Pair(3, 91)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-421, 146);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-76, 17), Pair(-64, -8), Pair(-29, -18), Pair(-17, -19), Pair(-11, -19), Pair(-22, -14), Pair(-45, -1), Pair(-46, 5)
  },
  {
      Pair(-38, 42), Pair(-29, 15), Pair(-26, 10), Pair(-8, -2), Pair(-7, -8), Pair(-6, 5), Pair(-23, 21), Pair(-18, 29)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 1), Pair(20, 0), Pair(64, -14), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 1), Pair(23, 3), Pair(44, -2), Pair(-15, 2), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -13), Pair(24, -12), Pair(43, -12), Pair(64, -14), Pair(61, -16), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 19), Pair(8, 35), Pair(24, 37), Pair(59, 27), Pair(100, 15), Pair(210, -37), Pair(287, -93)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(30, -2), Pair(13, 14), Pair(53, -9), Pair(21, 4), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-4, 20), Pair(0, 22)
  },
  {
      Pair(-65, -16), Pair(-57, -22)
  },
  {
      Pair(-51, -36), Pair(-51, -47)
  },
  {
      Pair(-67, -26), Pair(-53, -32)
  },
  {
      Pair(-49, 12), Pair(-45, -3)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(14, 29), Pair(18, 21), Pair(22, 15), Pair(21, -6), Pair(38, 3)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-4, -26), Pair(7, -12)
  },
  {
      Pair(10, -23), Pair(11, -32)
  },
  {
      Pair(-40, -7), Pair(-33, -19)
  },
  {
      Pair(-60, 2), Pair(-52, -9)
  },
  {
      Pair(-35, -9), Pair(-31, -14)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-14, -22), Pair(0, -8)
  },
  {
      Pair(-44, -11), Pair(-21, -29)
  },
  {
      Pair(4, -34), Pair(11, -40)
  },
  {
      Pair(-57, -4), Pair(-47, -34)
  },
  {
      Pair(-47, -32), Pair(-39, -47)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-7, -25), Pair(10, -15)
  },
  {
      Pair(-39, -16), Pair(-5, -17)
  },
  {
      Pair(-39, -14), Pair(-11, -10)
  },
  {
      Pair(16, -32), Pair(13, -13)
  },
  {
      Pair(-59, -14), Pair(-44, -46)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(33, 21), Pair(8, 19), Pair(23, 18), Pair(26, 23), Pair(25, 25), Pair(-5, 30), Pair(24, 36), Pair(37, -3),
  Pair(21, 17), Pair(11, 4), Pair(-1, 30), Pair(0, 28), Pair(7, 37), Pair(-12, 27), Pair(10, 9), Pair(2, 21),
  Pair(3, 4), Pair(4, 19), Pair(-2, 12), Pair(9, 15), Pair(2, 14), Pair(-2, 13), Pair(-8, 18), Pair(6, -7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-64, -1), Pair(15, -1), Pair(52, -9), Pair(31, -6), Pair(57, -4), Pair(3, 9), Pair(32, 13), Pair(-51, 27),
  Pair(1, -8), Pair(13, 8), Pair(12, 6), Pair(9, 4), Pair(10, 6), Pair(-2, 9), Pair(12, 19), Pair(0, 16),
  Pair(-26, 22), Pair(-8, 9), Pair(4, 17), Pair(20, 21), Pair(11, 24), Pair(2, 11), Pair(-4, 19), Pair(-33, 6)
};

constexpr ScorePair kBishopPairBonus = Pair(23, 52);

constexpr ScorePair kTempoBonus = Pair(17, 4);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H