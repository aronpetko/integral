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
  Pair(77, 13), Pair(328, 124), Pair(361, 242), Pair(510, 522), Pair(1099, 929), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(59, 72), Pair(42, 89), Pair(29, 88), Pair(44, 69), Pair(43, 69), Pair(39, 82), Pair(-19, 122), Pair(22, 77),
      Pair(7, 116), Pair(2, 126), Pair(12, 104), Pair(31, 80), Pair(37, 79), Pair(51, 89), Pair(14, 126), Pair(12, 107),
      Pair(-5, 106), Pair(0, 110), Pair(3, 90), Pair(13, 76), Pair(25, 76), Pair(21, 80), Pair(6, 104), Pair(0, 93),
      Pair(-12, 96), Pair(-14, 109), Pair(1, 83), Pair(11, 78), Pair(14, 77), Pair(16, 80), Pair(-3, 101), Pair(-5, 85),
      Pair(-15, 90), Pair(-17, 102), Pair(-11, 88), Pair(-8, 89), Pair(-4, 89), Pair(-2, 85), Pair(5, 93), Pair(-5, 83),
      Pair(-13, 99), Pair(-3, 107), Pair(-8, 96), Pair(-9, 92), Pair(-2, 95), Pair(20, 89), Pair(18, 95), Pair(-4, 83),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-145, 56), Pair(-57, 68), Pair(-32, 64), Pair(38, 60), Pair(58, 57), Pair(-130, 93), Pair(-3, 64), Pair(-98, 37),
      Pair(-6, 70), Pair(10, 74), Pair(32, 69), Pair(63, 72), Pair(58, 64), Pair(48, 63), Pair(9, 73), Pair(9, 60),
      Pair(11, 60), Pair(34, 70), Pair(30, 87), Pair(55, 79), Pair(66, 78), Pair(81, 72), Pair(24, 77), Pair(24, 58),
      Pair(27, 69), Pair(26, 85), Pair(42, 89), Pair(46, 94), Pair(38, 92), Pair(58, 84), Pair(33, 82), Pair(47, 66),
      Pair(16, 75), Pair(32, 74), Pair(34, 94), Pair(37, 96), Pair(38, 95), Pair(49, 86), Pair(43, 74), Pair(25, 81),
      Pair(-1, 58), Pair(20, 72), Pair(21, 80), Pair(31, 93), Pair(36, 88), Pair(29, 78), Pair(34, 71), Pair(12, 70),
      Pair(-5, 58), Pair(1, 75), Pair(11, 67), Pair(22, 74), Pair(25, 74), Pair(23, 66), Pair(14, 75), Pair(11, 65),
      Pair(-42, 56), Pair(-1, 56), Pair(0, 60), Pair(10, 76), Pair(17, 68), Pair(11, 64), Pair(0, 62), Pair(-14, 63)
  },
  {
      Pair(-45, 47), Pair(-56, 45), Pair(-41, 42), Pair(-52, 38), Pair(-7, 31), Pair(-85, 33), Pair(-40, 43), Pair(-29, 31),
      Pair(-25, 30), Pair(-3, 37), Pair(-14, 36), Pair(-7, 39), Pair(-9, 30), Pair(-7, 34), Pair(-18, 40), Pair(-22, 34),
      Pair(-3, 33), Pair(10, 35), Pair(2, 44), Pair(17, 29), Pair(21, 35), Pair(24, 41), Pair(16, 32), Pair(7, 26),
      Pair(-7, 27), Pair(2, 38), Pair(12, 36), Pair(19, 39), Pair(14, 39), Pair(17, 34), Pair(2, 31), Pair(-1, 28),
      Pair(3, 25), Pair(-8, 36), Pair(3, 37), Pair(6, 37), Pair(10, 34), Pair(4, 34), Pair(-3, 36), Pair(10, 21),
      Pair(-3, 26), Pair(14, 31), Pair(10, 35), Pair(6, 38), Pair(4, 45), Pair(11, 36), Pair(17, 26), Pair(5, 28),
      Pair(5, 29), Pair(10, 18), Pair(14, 20), Pair(0, 30), Pair(9, 26), Pair(15, 22), Pair(23, 19), Pair(19, 11),
      Pair(-6, 20), Pair(12, 25), Pair(-6, 27), Pair(-2, 30), Pair(6, 24), Pair(-9, 33), Pair(2, 16), Pair(10, 7)
  },
  {
      Pair(15, 30), Pair(24, 33), Pair(18, 39), Pair(33, 30), Pair(31, 35), Pair(51, 28), Pair(28, 28), Pair(17, 30),
      Pair(1, 37), Pair(2, 40), Pair(17, 33), Pair(38, 24), Pair(28, 27), Pair(36, 26), Pair(1, 34), Pair(-4, 33),
      Pair(-7, 35), Pair(17, 30), Pair(6, 30), Pair(19, 21), Pair(32, 17), Pair(33, 24), Pair(23, 20), Pair(-1, 25),
      Pair(-13, 31), Pair(0, 31), Pair(13, 25), Pair(2, 24), Pair(16, 20), Pair(8, 24), Pair(9, 20), Pair(-8, 23),
      Pair(-29, 32), Pair(-26, 36), Pair(-11, 32), Pair(-16, 30), Pair(-17, 30), Pair(-22, 33), Pair(-16, 28), Pair(-29, 25),
      Pair(-36, 24), Pair(-28, 26), Pair(-29, 27), Pair(-27, 23), Pair(-25, 24), Pair(-25, 22), Pair(-9, 9), Pair(-22, 8),
      Pair(-37, 13), Pair(-26, 16), Pair(-15, 14), Pair(-16, 12), Pair(-13, 8), Pair(-12, 6), Pair(-14, -1), Pair(-43, 0),
      Pair(-22, 12), Pair(-14, 10), Pair(-14, 15), Pair(-8, 8), Pair(-6, 5), Pair(-9, 11), Pair(-19, 8), Pair(-19, 2)
  },
  {
      Pair(13, 28), Pair(43, 20), Pair(51, 22), Pair(33, 40), Pair(65, 25), Pair(60, 15), Pair(69, 13), Pair(48, 25),
      Pair(11, 31), Pair(3, 48), Pair(13, 71), Pair(15, 81), Pair(11, 85), Pair(36, 67), Pair(23, 60), Pair(60, 13),
      Pair(18, 18), Pair(27, 42), Pair(20, 68), Pair(25, 77), Pair(32, 81), Pair(42, 63), Pair(40, 52), Pair(38, 16),
      Pair(23, 15), Pair(22, 40), Pair(17, 66), Pair(19, 71), Pair(22, 78), Pair(30, 57), Pair(30, 50), Pair(41, 17),
      Pair(24, 1), Pair(14, 34), Pair(17, 46), Pair(11, 73), Pair(21, 51), Pair(22, 42), Pair(29, 30), Pair(27, 9),
      Pair(21, 0), Pair(25, 9), Pair(21, 27), Pair(20, 26), Pair(22, 26), Pair(27, 17), Pair(34, 1), Pair(30, -17),
      Pair(21, -25), Pair(27, -24), Pair(32, -25), Pair(30, -8), Pair(32, -14), Pair(40, -40), Pair(39, -51), Pair(39, -65),
      Pair(29, -51), Pair(22, -42), Pair(22, -36), Pair(24, -38), Pair(27, -40), Pair(16, -57), Pair(24, -53), Pair(34, -51)
  },
  {
      Pair(119, -137), Pair(28, 15), Pair(86, 13), Pair(11, 18), Pair(-36, 37), Pair(80, -4), Pair(42, -5), Pair(149, -171),
      Pair(-35, -10), Pair(78, 19), Pair(63, 29), Pair(0, 32), Pair(14, 29), Pair(49, 37), Pair(60, 32), Pair(-32, -27),
      Pair(-9, 4), Pair(57, 22), Pair(47, 32), Pair(-67, 48), Pair(-95, 57), Pair(-23, 40), Pair(5, 32), Pair(20, -6),
      Pair(-37, -6), Pair(19, 9), Pair(-38, 32), Pair(-97, 45), Pair(-142, 49), Pair(-31, 23), Pair(-10, 10), Pair(-34, -13),
      Pair(-52, -26), Pair(10, -5), Pair(-31, 17), Pair(-86, 37), Pair(-73, 31), Pair(-37, 13), Pair(-22, -2), Pair(-80, -18),
      Pair(-36, -21), Pair(12, -9), Pair(-20, 9), Pair(-45, 24), Pair(-52, 24), Pair(-37, 12), Pair(-12, -4), Pair(-39, -20),
      Pair(24, -35), Pair(0, -5), Pair(-16, 6), Pair(-37, 14), Pair(-38, 14), Pair(-23, 6), Pair(-7, -5), Pair(13, -33),
      Pair(-4, -41), Pair(30, -29), Pair(20, -15), Pair(-38, -2), Pair(-2, -21), Pair(-25, -9), Pair(19, -23), Pair(25, -57)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-16, 49), Pair(-3, 79), Pair(4, 102), Pair(10, 113), Pair(14, 120), Pair(17, 127), Pair(21, 126), Pair(25, 121),
  Pair(31, 109)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-9, -6), Pair(1, 9), Pair(7, 27), Pair(11, 38), Pair(15, 47), Pair(17, 53), Pair(19, 54), Pair(20, 57),
  Pair(22, 59), Pair(26, 57), Pair(33, 53), Pair(37, 51), Pair(36, 59), Pair(25, 52)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-39, -37), Pair(-29, -7), Pair(-25, 5), Pair(-21, 17), Pair(-19, 23), Pair(-16, 29), Pair(-14, 33), Pair(-10, 34),
  Pair(-7, 39), Pair(-3, 40), Pair(1, 40), Pair(3, 43), Pair(8, 42), Pair(16, 38), Pair(53, 24)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(14, -99), Pair(16, -100), Pair(19, -74), Pair(22, -57), Pair(22, -23), Pair(23, -1), Pair(24, 12), Pair(26, 24),
  Pair(27, 31), Pair(29, 40), Pair(31, 47), Pair(31, 53), Pair(31, 58), Pair(32, 62), Pair(31, 64), Pair(32, 62),
  Pair(35, 57), Pair(35, 54), Pair(44, 41), Pair(56, 24), Pair(78, 1), Pair(114, -36), Pair(119, -41), Pair(197, -110),
  Pair(220, -121), Pair(396, -234), Pair(174, -127), Pair(232, -164)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-13, -97), Pair(-17, -82), Pair(-8, -51), Pair(13, -15), Pair(27, 37), Pair(56, 117), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(4, 7), Pair(11, 7), Pair(14, 20), Pair(31, 60), Pair(134, 148), Pair(199, 407), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(17, 11), Pair(13, 8), Pair(15, 16), Pair(38, 36), Pair(196, 4), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-27, -38), Pair(-3, -29), Pair(-9, -20), Pair(-16, -7), Pair(-14, -3), Pair(-15, -14), Pair(0, -24), Pair(-12, -39)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(2, 5), Pair(-3, -11), Pair(-10, -4), Pair(-11, -10), Pair(-13, -14), Pair(-5, -8), Pair(-2, -11), Pair(-4, 4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(24, -2), Pair(19, -1), Pair(19, 6), Pair(22, 3), Pair(27, 2), Pair(34, -3), Pair(41, -2), Pair(56, -5)
  },
  {
      Pair(16, 26), Pair(12, 9), Pair(17, 5), Pair(20, -1), Pair(18, -4), Pair(18, -7), Pair(25, 0), Pair(20, 13)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(11, -5), Pair(14, -9), Pair(9, -5),
  Pair(20, -8), Pair(17, -10), Pair(19, -9),
  Pair(24, 1), Pair(0, 0), Pair(23, 0),
  Pair(4, 8), Pair(-19, 8), Pair(5, 9)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, 2), Pair(-15, 9), Pair(-8, 4),
  Pair(-9, 1), Pair(-17, 9), Pair(-9, 3),
  Pair(-1, -7), Pair(-10, 1), Pair(-1, -6),
  Pair(9, -8), Pair(-8, -2), Pair(7, -6),
  Pair(21, -13), Pair(19, -5), Pair(19, -15),
  Pair(0, 0), Pair(-46, -7), Pair(0, 0),
  Pair(40, -47), Pair(0, 0), Pair(39, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(3, 52), Pair(-15, 48), Pair(-10, 27), Pair(-5, 14), Pair(-2, 14), Pair(8, 13), Pair(-6, 11)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-38, 9), Pair(-4, 30), Pair(-2, 57), Pair(5, 68), Pair(8, 75), Pair(6, 78), Pair(-4, 84)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-419, 162);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-57, 3), Pair(-62, 0), Pair(-32, -12), Pair(-20, -13), Pair(-19, -12), Pair(-28, -5), Pair(-43, -3), Pair(-55, 11)
  },
  {
      Pair(-9, 39), Pair(-36, 20), Pair(-19, 7), Pair(-7, 1), Pair(-8, -2), Pair(-12, 7), Pair(-24, 19), Pair(-25, 32)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 2), Pair(18, -3), Pair(65, -21), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 2), Pair(19, 5), Pair(30, 2), Pair(-8, -4), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -16), Pair(23, -15), Pair(40, -10), Pair(55, -12), Pair(59, -17), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 19), Pair(8, 32), Pair(19, 41), Pair(54, 25), Pair(99, 15), Pair(176, -22), Pair(248, -70)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(24, 1), Pair(8, 17), Pair(45, -3), Pair(15, 14), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-5, 33), Pair(4, 28)
  },
  {
      Pair(-61, -20), Pair(-54, -32)
  },
  {
      Pair(-46, -47), Pair(-47, -57)
  },
  {
      Pair(-72, -23), Pair(-59, -24)
  },
  {
      Pair(-43, -4), Pair(-44, -3)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 28), Pair(20, 19), Pair(22, 10), Pair(19, -7), Pair(31, 1)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -26), Pair(6, -12)
  },
  {
      Pair(6, -21), Pair(6, -25)
  },
  {
      Pair(-38, -10), Pair(-31, -26)
  },
  {
      Pair(-62, -1), Pair(-49, -12)
  },
  {
      Pair(-38, -7), Pair(-31, -25)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-14, -21), Pair(0, -8)
  },
  {
      Pair(-44, -14), Pair(-17, -31)
  },
  {
      Pair(-6, -37), Pair(3, -42)
  },
  {
      Pair(-42, -20), Pair(-44, -41)
  },
  {
      Pair(-43, -42), Pair(-36, -61)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-8, -25), Pair(9, -14)
  },
  {
      Pair(-43, -13), Pair(-5, -16)
  },
  {
      Pair(-31, -20), Pair(-12, -10)
  },
  {
      Pair(2, -37), Pair(5, -16)
  },
  {
      Pair(-53, -14), Pair(-48, -40)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(0, 28), Pair(10, 26), Pair(24, 23), Pair(13, 25), Pair(16, 20), Pair(4, 29), Pair(20, 27), Pair(18, 37),
  Pair(14, 6), Pair(13, 7), Pair(14, 21), Pair(1, 22), Pair(7, 25), Pair(-6, 27), Pair(10, 15), Pair(6, 17),
  Pair(6, 4), Pair(-5, 14), Pair(4, 10), Pair(10, 10), Pair(4, 18), Pair(-1, 8), Pair(-9, 12), Pair(5, -2)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-2, 31), Pair(21, 3), Pair(27, 0), Pair(33, 2), Pair(39, -8), Pair(42, 5), Pair(15, 12), Pair(-22, -1),
  Pair(-26, 4), Pair(8, 12), Pair(5, 4), Pair(10, 18), Pair(12, 5), Pair(21, 15), Pair(10, 14), Pair(9, -5),
  Pair(-8, 9), Pair(4, 19), Pair(3, 19), Pair(14, 15), Pair(17, 21), Pair(2, 12), Pair(11, 5), Pair(-22, -2)
};

constexpr ScorePair kBishopPairBonus = Pair(18, 61);

constexpr ScorePair kTempoBonus = Pair(19, 6);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H