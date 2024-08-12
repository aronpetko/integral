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
  Pair(75, 141), Pair(301, 321), Pair(331, 356), Pair(439, 612), Pair(874, 1080), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(44, 67), Pair(25, 70), Pair(14, 71), Pair(53, 28), Pair(47, 30), Pair(41, 43), Pair(-32, 86), Pair(-27, 83),
      Pair(5, 0), Pair(-16, 21), Pair(19, -23), Pair(27, -53), Pair(43, -57), Pair(65, -43), Pair(18, 4), Pair(6, -4),
      Pair(-19, -11), Pair(-22, -4), Pair(-13, -30), Pair(-10, -44), Pair(11, -46), Pair(6, -42), Pair(-15, -12), Pair(-10, -28),
      Pair(-24, -26), Pair(-32, -5), Pair(-15, -34), Pair(-5, -41), Pair(-2, -42), Pair(-1, -41), Pair(-20, -16), Pair(-13, -39),
      Pair(-34, -29), Pair(-39, -13), Pair(-26, -35), Pair(-21, -34), Pair(-14, -35), Pair(-19, -38), Pair(-19, -25), Pair(-18, -43),
      Pair(-25, -25), Pair(-29, -8), Pair(-18, -28), Pair(-21, -32), Pair(-12, -25), Pair(1, -33), Pair(-4, -23), Pair(-17, -41),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-131, -47), Pair(-101, -6), Pair(-69, 10), Pair(-26, -8), Pair(-8, -3), Pair(-39, -28), Pair(-106, -4), Pair(-99, -66),
      Pair(-28, 4), Pair(-12, 16), Pair(-1, 11), Pair(9, 9), Pair(7, -2), Pair(39, -6), Pair(1, 7), Pair(-6, -14),
      Pair(-6, 6), Pair(10, 14), Pair(7, 27), Pair(19, 19), Pair(27, 15), Pair(59, -9), Pair(7, 5), Pair(20, -13),
      Pair(7, 18), Pair(16, 22), Pair(32, 25), Pair(39, 25), Pair(34, 27), Pair(44, 26), Pair(24, 22), Pair(33, 5),
      Pair(-7, 20), Pair(15, 19), Pair(25, 31), Pair(31, 28), Pair(30, 34), Pair(42, 16), Pair(32, 15), Pair(8, 15),
      Pair(-22, 7), Pair(-1, 15), Pair(10, 20), Pair(19, 31), Pair(31, 29), Pair(18, 14), Pair(18, 10), Pair(0, 12),
      Pair(-31, 8), Pair(-18, 16), Pair(-7, 16), Pair(7, 16), Pair(9, 15), Pair(4, 13), Pair(3, 5), Pair(-3, 18),
      Pair(-61, 13), Pair(-23, 8), Pair(-20, 12), Pair(-8, 17), Pair(0, 15), Pair(2, 4), Pair(-20, 14), Pair(-26, 5)
  },
  {
      Pair(-29, 16), Pair(-52, 17), Pair(-53, 10), Pair(-87, 16), Pair(-84, 15), Pair(-73, 5), Pair(-38, 8), Pair(-62, 5),
      Pair(-21, 0), Pair(-15, 10), Pair(-14, 6), Pair(-28, 10), Pair(-29, 5), Pair(-19, 4), Pair(-46, 17), Pair(-33, 1),
      Pair(-8, 14), Pair(-2, 10), Pair(-12, 15), Pair(-8, 6), Pair(-14, 10), Pair(17, 15), Pair(11, 13), Pair(5, 14),
      Pair(-18, 13), Pair(-4, 15), Pair(-2, 13), Pair(5, 18), Pair(2, 14), Pair(8, 16), Pair(-9, 15), Pair(-12, 11),
      Pair(-14, 7), Pair(-24, 17), Pair(-6, 12), Pair(1, 12), Pair(2, 6), Pair(-6, 11), Pair(-14, 15), Pair(-3, 1),
      Pair(-18, 8), Pair(6, 13), Pair(2, 13), Pair(-1, 17), Pair(2, 22), Pair(6, 13), Pair(10, 7), Pair(3, 0),
      Pair(-3, 9), Pair(0, -5), Pair(8, -1), Pair(-7, 10), Pair(4, 9), Pair(11, 3), Pair(22, 0), Pair(11, -9),
      Pair(-9, -4), Pair(8, 15), Pair(-9, 11), Pair(-10, 10), Pair(2, 5), Pair(-11, 16), Pair(4, 1), Pair(17, -22)
  },
  {
      Pair(-19, 45), Pair(-22, 53), Pair(-23, 56), Pair(-28, 54), Pair(-18, 43), Pair(-2, 47), Pair(-10, 49), Pair(-27, 46),
      Pair(-18, 41), Pair(-12, 51), Pair(-3, 49), Pair(13, 37), Pair(-3, 36), Pair(12, 39), Pair(16, 35), Pair(-8, 35),
      Pair(-23, 40), Pair(9, 39), Pair(1, 38), Pair(-1, 33), Pair(22, 22), Pair(34, 22), Pair(50, 22), Pair(-3, 23),
      Pair(-21, 42), Pair(1, 41), Pair(3, 41), Pair(-2, 38), Pair(8, 24), Pair(13, 25), Pair(13, 28), Pair(-14, 27),
      Pair(-32, 36), Pair(-27, 44), Pair(-20, 38), Pair(-14, 37), Pair(-14, 30), Pair(-29, 39), Pair(-6, 27), Pair(-29, 24),
      Pair(-36, 30), Pair(-28, 34), Pair(-23, 29), Pair(-24, 33), Pair(-15, 24), Pair(-18, 25), Pair(7, 8), Pair(-18, 6),
      Pair(-37, 24), Pair(-29, 30), Pair(-17, 28), Pair(-18, 27), Pair(-11, 17), Pair(-15, 20), Pair(-2, 9), Pair(-36, 10),
      Pair(-26, 27), Pair(-22, 25), Pair(-18, 28), Pair(-12, 22), Pair(-7, 14), Pair(-12, 21), Pair(-17, 18), Pair(-26, 13)
  },
  {
      Pair(-39, 68), Pair(-35, 66), Pair(-28, 88), Pair(1, 75), Pair(-14, 84), Pair(-5, 81), Pair(36, 28), Pair(-13, 65),
      Pair(-9, 57), Pair(-20, 76), Pair(-22, 107), Pair(-34, 119), Pair(-50, 142), Pair(-11, 104), Pair(-8, 85), Pair(30, 72),
      Pair(-5, 61), Pair(-5, 70), Pair(-10, 100), Pair(-9, 103), Pair(-11, 114), Pair(19, 92), Pair(22, 68), Pair(16, 68),
      Pair(-11, 67), Pair(-2, 79), Pair(-2, 88), Pair(-10, 105), Pair(-5, 104), Pair(10, 82), Pair(14, 83), Pair(14, 67),
      Pair(-11, 65), Pair(-17, 96), Pair(-12, 95), Pair(-10, 110), Pair(-4, 99), Pair(-9, 91), Pair(7, 76), Pair(3, 72),
      Pair(-9, 52), Pair(-7, 75), Pair(-9, 89), Pair(-13, 92), Pair(-9, 93), Pair(-1, 80), Pair(13, 62), Pair(6, 52),
      Pair(-8, 48), Pair(-5, 51), Pair(-3, 55), Pair(-1, 66), Pair(0, 65), Pair(6, 38), Pair(15, 17), Pair(16, 4),
      Pair(-18, 55), Pair(-15, 50), Pair(-11, 56), Pair(-9, 58), Pair(-4, 45), Pair(-13, 37), Pair(-10, 32), Pair(-1, 27)
  },
  {
      Pair(74, -91), Pair(82, -49), Pair(60, -27), Pair(-46, 9), Pair(-19, -7), Pair(-91, 11), Pair(-24, -7), Pair(101, -114),
      Pair(-91, 6), Pair(-4, 27), Pair(-26, 33), Pair(68, 15), Pair(-5, 28), Pair(-36, 49), Pair(-34, 40), Pair(-97, 16),
      Pair(-72, 6), Pair(68, 16), Pair(6, 32), Pair(-31, 45), Pair(5, 42), Pair(59, 31), Pair(-22, 37), Pair(-48, 4),
      Pair(-36, -12), Pair(12, 5), Pair(-28, 26), Pair(-76, 43), Pair(-76, 37), Pair(-48, 30), Pair(-32, 9), Pair(-131, 6),
      Pair(-43, -27), Pair(7, -7), Pair(-39, 18), Pair(-81, 38), Pair(-78, 32), Pair(-41, 13), Pair(-39, -3), Pair(-119, -10),
      Pair(-26, -30), Pair(23, -14), Pair(-23, 9), Pair(-40, 24), Pair(-36, 19), Pair(-32, 7), Pair(-10, -13), Pair(-48, -25),
      Pair(27, -42), Pair(2, -10), Pair(-3, 0), Pair(-24, 11), Pair(-29, 12), Pair(-18, 1), Pair(0, -17), Pair(12, -42),
      Pair(12, -67), Pair(35, -40), Pair(26, -24), Pair(-37, -1), Pair(5, -24), Pair(-23, -11), Pair(18, -36), Pair(20, -75)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-25, 8), Pair(-11, 4), Pair(-2, 24), Pair(3, 33), Pair(7, 39), Pair(11, 47), Pair(16, 46), Pair(19, 44),
  Pair(21, 37)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-31, -16), Pair(-21, -24), Pair(-12, -8), Pair(-7, 4), Pair(-1, 13), Pair(2, 22), Pair(4, 26), Pair(6, 30),
  Pair(7, 34), Pair(12, 32), Pair(21, 30), Pair(28, 32), Pair(29, 44), Pair(35, 27)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-36, -31), Pair(-26, -4), Pair(-21, 1), Pair(-22, 16), Pair(-22, 20), Pair(-18, 23), Pair(-16, 28), Pair(-13, 31),
  Pair(-9, 35), Pair(-7, 38), Pair(-3, 40), Pair(-2, 45), Pair(2, 47), Pair(4, 46), Pair(1, 45)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-69, -126), Pair(-15, -237), Pair(-22, -28), Pair(-16, 17), Pair(-16, 57), Pair(-14, 76), Pair(-11, 89), Pair(-10, 102),
  Pair(-8, 110), Pair(-5, 111), Pair(-3, 116), Pair(-3, 123), Pair(1, 120), Pair(1, 124), Pair(3, 124), Pair(7, 121),
  Pair(6, 125), Pair(9, 122), Pair(17, 112), Pair(30, 98), Pair(37, 90), Pair(77, 61), Pair(75, 55), Pair(91, 32),
  Pair(135, 15), Pair(239, -65), Pair(160, -18), Pair(85, 1)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-10, -74), Pair(-10, -60), Pair(-8, -28), Pair(18, 7), Pair(11, 75), Pair(28, 66), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(5, 1), Pair(12, 7), Pair(18, 17), Pair(44, 59), Pair(98, 192), Pair(-46, 414), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(20, 11), Pair(13, 7), Pair(13, 15), Pair(23, 43), Pair(150, 37), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-7, -45), Pair(13, -37), Pair(2, -25), Pair(1, -15), Pair(-8, -6), Pair(-7, -19), Pair(11, -32), Pair(-3, -49)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-8, 12), Pair(-1, -12), Pair(-11, -4), Pair(-7, -13), Pair(-11, -15), Pair(-4, -6), Pair(1, -12), Pair(-7, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(22, 5), Pair(19, 3), Pair(17, 9), Pair(18, 8), Pair(19, 13), Pair(31, 3), Pair(39, 3), Pair(66, -1)
  },
  {
      Pair(9, 33), Pair(9, 9), Pair(11, 9), Pair(18, 0), Pair(14, 1), Pair(14, -2), Pair(21, 0), Pair(16, 19)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -6), Pair(17, -6), Pair(9, -3),
  Pair(21, -11), Pair(18, -11), Pair(20, -11),
  Pair(31, -4), Pair(0, 0), Pair(28, -3),
  Pair(-8, 5), Pair(-5, 0), Pair(-7, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, 1), Pair(-13, 3), Pair(-7, 3),
  Pair(-5, 0), Pair(-14, 5), Pair(-8, 3),
  Pair(1, -7), Pair(-11, 0), Pair(0, -5),
  Pair(14, -9), Pair(-2, -5), Pair(12, -6),
  Pair(23, -9), Pair(24, 0), Pair(16, -9),
  Pair(0, 0), Pair(15, -31), Pair(0, 0),
  Pair(56, -49), Pair(0, 0), Pair(51, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-9, 63), Pair(-13, 48), Pair(-3, 27), Pair(0, 17), Pair(3, 15), Pair(15, 13), Pair(5, 10)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-76, 4), Pair(-11, 7), Pair(-7, 30), Pair(1, 37), Pair(3, 42), Pair(5, 47), Pair(-9, 44)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-344, 199);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-55, -13), Pair(-67, -7), Pair(-37, -9), Pair(-24, -9), Pair(-20, -2), Pair(-36, 0), Pair(-49, 3), Pair(-34, 5)
  },
  {
      Pair(-3, 45), Pair(-31, 19), Pair(-17, 12), Pair(3, -5), Pair(-2, -7), Pair(-3, 3), Pair(-27, 23), Pair(-15, 34)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 0), Pair(27, -10), Pair(63, -30), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 1), Pair(29, -2), Pair(61, -11), Pair(68, -40), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(21, -21), Pair(36, -22), Pair(54, -16), Pair(81, -19), Pair(90, -29), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 12), Pair(12, 23), Pair(31, 28), Pair(75, 11), Pair(110, 6), Pair(169, -15), Pair(229, -62)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(47, 7), Pair(19, 21), Pair(59, -2), Pair(28, 13), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-17, 13), Pair(-11, 17)
  },
  {
      Pair(-66, -20), Pair(-66, -25)
  },
  {
      Pair(-55, -44), Pair(-64, -66)
  },
  {
      Pair(-91, 3), Pair(-79, -30)
  },
  {
      Pair(-74, 37), Pair(-82, 20)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(16, 30), Pair(21, 18), Pair(27, 10), Pair(23, -6), Pair(55, -6)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-1, -20), Pair(10, -12)
  },
  {
      Pair(-24, -43), Pair(-4, -59)
  },
  {
      Pair(-41, -31), Pair(-27, -33)
  },
  {
      Pair(-79, -4), Pair(-58, -27)
  },
  {
      Pair(-54, 30), Pair(-55, 17)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-10, -20), Pair(1, -9)
  },
  {
      Pair(-47, -23), Pair(-21, -24)
  },
  {
      Pair(16, -136), Pair(27, -130)
  },
  {
      Pair(-79, -7), Pair(-45, -36)
  },
  {
      Pair(-81, -16), Pair(-59, -85)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-2, -25), Pair(10, -11)
  },
  {
      Pair(-42, -24), Pair(-3, -13)
  },
  {
      Pair(-30, -29), Pair(-14, -3)
  },
  {
      Pair(-3, -62), Pair(13, -38)
  },
  {
      Pair(-83, 9), Pair(-62, -38)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(18, 23), Pair(16, 13), Pair(36, 21), Pair(43, 22), Pair(47, 28), Pair(31, 43), Pair(43, 17), Pair(-3, 39),
  Pair(1, 14), Pair(13, 16), Pair(17, 20), Pair(9, 34), Pair(13, 23), Pair(11, 19), Pair(14, 14), Pair(-4, 24),
  Pair(9, 10), Pair(6, 3), Pair(2, 16), Pair(8, 18), Pair(7, 21), Pair(-7, 19), Pair(2, 9), Pair(1, 9)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-10, 15), Pair(20, 0), Pair(30, 2), Pair(42, 3), Pair(67, -14), Pair(45, 0), Pair(26, -10), Pair(-16, -26),
  Pair(-20, -8), Pair(18, 7), Pair(11, 3), Pair(24, 13), Pair(16, 5), Pair(15, 1), Pair(14, 9), Pair(18, -21),
  Pair(-23, 31), Pair(10, 6), Pair(3, 20), Pair(18, 14), Pair(23, 24), Pair(2, 10), Pair(14, 0), Pair(-47, 10)
};

constexpr ScorePair kBishopPairBonus = Pair(18, 58);

constexpr ScorePair kTempoBonus = Pair(30, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H