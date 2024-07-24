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
  Pair(74, 137), Pair(305, 332), Pair(325, 355), Pair(436, 614), Pair(875, 1086), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(43, 68), Pair(26, 70), Pair(13, 71), Pair(52, 28), Pair(46, 31), Pair(39, 44), Pair(-31, 87), Pair(-28, 83),
      Pair(6, 4), Pair(-12, 25), Pair(20, -18), Pair(28, -49), Pair(45, -52), Pair(65, -38), Pair(22, 8), Pair(8, 0),
      Pair(-17, -8), Pair(-19, -1), Pair(-11, -26), Pair(-9, -40), Pair(12, -42), Pair(8, -38), Pair(-11, -8), Pair(-7, -25),
      Pair(-22, -22), Pair(-29, -2), Pair(-14, -31), Pair(-3, -37), Pair(-1, -38), Pair(1, -38), Pair(-16, -13), Pair(-11, -35),
      Pair(-31, -26), Pair(-37, -10), Pair(-25, -31), Pair(-19, -30), Pair(-12, -31), Pair(-17, -34), Pair(-17, -21), Pair(-16, -40),
      Pair(-23, -21), Pair(-27, -4), Pair(-17, -24), Pair(-19, -29), Pair(-10, -21), Pair(2, -30), Pair(-1, -18), Pair(-15, -37),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-133, -46), Pair(-103, -6), Pair(-68, 10), Pair(-23, -8), Pair(-8, -3), Pair(-38, -28), Pair(-107, -4), Pair(-99, -65),
      Pair(-31, 4), Pair(-14, 16), Pair(-2, 11), Pair(7, 9), Pair(7, -1), Pair(38, -7), Pair(-1, 7), Pair(-10, -14),
      Pair(-9, 6), Pair(8, 12), Pair(7, 26), Pair(21, 19), Pair(27, 15), Pair(60, -10), Pair(5, 4), Pair(20, -13),
      Pair(2, 17), Pair(5, 18), Pair(25, 24), Pair(34, 24), Pair(29, 22), Pair(34, 21), Pair(13, 14), Pair(26, 4),
      Pair(-10, 19), Pair(10, 16), Pair(22, 29), Pair(27, 26), Pair(27, 31), Pair(38, 12), Pair(26, 12), Pair(5, 13),
      Pair(-26, 6), Pair(-5, 12), Pair(7, 17), Pair(16, 29), Pair(28, 27), Pair(15, 11), Pair(14, 7), Pair(-4, 10),
      Pair(-33, 7), Pair(-21, 15), Pair(-9, 14), Pair(5, 15), Pair(6, 13), Pair(1, 12), Pair(-1, 4), Pair(-5, 18),
      Pair(-64, 13), Pair(-26, 8), Pair(-24, 11), Pair(-11, 17), Pair(-3, 15), Pair(-1, 4), Pair(-23, 14), Pair(-28, 5)
  },
  {
      Pair(-26, 17), Pair(-49, 18), Pair(-52, 11), Pair(-85, 17), Pair(-82, 17), Pair(-72, 6), Pair(-37, 10), Pair(-59, 6),
      Pair(-19, 1), Pair(-13, 11), Pair(-13, 7), Pair(-26, 11), Pair(-29, 6), Pair(-19, 6), Pair(-46, 18), Pair(-31, 2),
      Pair(-7, 16), Pair(1, 11), Pair(-11, 16), Pair(-7, 7), Pair(-14, 11), Pair(17, 16), Pair(11, 14), Pair(5, 16),
      Pair(-19, 14), Pair(-13, 16), Pair(-6, 15), Pair(4, 19), Pair(-3, 14), Pair(-3, 18), Pair(-20, 14), Pair(-17, 12),
      Pair(-12, 8), Pair(-23, 17), Pair(-5, 12), Pair(2, 13), Pair(2, 7), Pair(-6, 12), Pair(-13, 15), Pair(-4, 2),
      Pair(-15, 9), Pair(7, 14), Pair(4, 14), Pair(0, 18), Pair(4, 23), Pair(7, 14), Pair(11, 8), Pair(6, 0),
      Pair(0, 10), Pair(3, -4), Pair(10, -1), Pair(-4, 11), Pair(7, 9), Pair(14, 4), Pair(25, 1), Pair(14, -8),
      Pair(-7, -3), Pair(11, 16), Pair(-6, 12), Pair(-8, 11), Pair(4, 6), Pair(-8, 17), Pair(6, 1), Pair(20, -21)
  },
  {
      Pair(-17, 45), Pair(-21, 53), Pair(-22, 57), Pair(-26, 54), Pair(-16, 44), Pair(-1, 48), Pair(-8, 48), Pair(-25, 46),
      Pair(-16, 40), Pair(-11, 51), Pair(-1, 49), Pair(15, 38), Pair(-1, 36), Pair(15, 39), Pair(17, 35), Pair(-7, 34),
      Pair(-21, 40), Pair(11, 39), Pair(2, 39), Pair(2, 34), Pair(24, 23), Pair(36, 22), Pair(52, 22), Pair(-1, 23),
      Pair(-22, 42), Pair(-8, 42), Pair(-5, 43), Pair(-4, 38), Pair(0, 24), Pair(1, 26), Pair(0, 29), Pair(-20, 27),
      Pair(-31, 35), Pair(-30, 43), Pair(-21, 38), Pair(-17, 37), Pair(-15, 30), Pair(-33, 38), Pair(-10, 26), Pair(-30, 23),
      Pair(-35, 30), Pair(-29, 33), Pair(-23, 30), Pair(-24, 33), Pair(-14, 24), Pair(-18, 24), Pair(6, 7), Pair(-17, 5),
      Pair(-35, 24), Pair(-28, 30), Pair(-16, 28), Pair(-16, 27), Pair(-10, 17), Pair(-13, 20), Pair(-2, 9), Pair(-35, 9),
      Pair(-24, 28), Pair(-20, 25), Pair(-16, 29), Pair(-11, 23), Pair(-6, 14), Pair(-11, 22), Pair(-16, 18), Pair(-24, 13)
  },
  {
      Pair(-39, 68), Pair(-35, 67), Pair(-29, 89), Pair(0, 77), Pair(-15, 85), Pair(-7, 83), Pair(36, 29), Pair(-13, 66),
      Pair(-8, 58), Pair(-20, 76), Pair(-22, 108), Pair(-34, 119), Pair(-50, 144), Pair(-11, 104), Pair(-8, 85), Pair(29, 73),
      Pair(-4, 61), Pair(-4, 71), Pair(-9, 100), Pair(-7, 103), Pair(-11, 115), Pair(20, 93), Pair(23, 69), Pair(17, 68),
      Pair(-12, 70), Pair(-8, 85), Pair(-8, 93), Pair(-13, 108), Pair(-10, 108), Pair(0, 90), Pair(8, 89), Pair(6, 73),
      Pair(-9, 65), Pair(-16, 97), Pair(-11, 95), Pair(-9, 111), Pair(-3, 100), Pair(-9, 92), Pair(7, 77), Pair(4, 71),
      Pair(-8, 52), Pair(-6, 75), Pair(-8, 89), Pair(-12, 92), Pair(-7, 94), Pair(-1, 81), Pair(14, 61), Pair(8, 51),
      Pair(-7, 47), Pair(-4, 51), Pair(0, 54), Pair(2, 66), Pair(3, 64), Pair(8, 38), Pair(16, 18), Pair(18, 4),
      Pair(-17, 55), Pair(-13, 49), Pair(-10, 55), Pair(-6, 57), Pair(-3, 44), Pair(-11, 36), Pair(-9, 32), Pair(1, 27)
  },
  {
      Pair(71, -88), Pair(83, -46), Pair(60, -23), Pair(-46, 12), Pair(-18, -4), Pair(-91, 14), Pair(-25, -3), Pair(94, -108),
      Pair(-92, 9), Pair(-4, 31), Pair(-25, 36), Pair(69, 19), Pair(-6, 32), Pair(-36, 53), Pair(-35, 44), Pair(-98, 20),
      Pair(-74, 10), Pair(68, 20), Pair(6, 36), Pair(-31, 49), Pair(6, 46), Pair(60, 34), Pair(-23, 41), Pair(-50, 8),
      Pair(-40, -8), Pair(7, 9), Pair(-31, 31), Pair(-78, 47), Pair(-81, 42), Pair(-53, 35), Pair(-41, 15), Pair(-137, 11),
      Pair(-45, -23), Pair(4, -3), Pair(-41, 22), Pair(-83, 42), Pair(-79, 36), Pair(-44, 17), Pair(-45, 1), Pair(-122, -5),
      Pair(-28, -26), Pair(22, -10), Pair(-25, 13), Pair(-41, 28), Pair(-37, 23), Pair(-33, 11), Pair(-11, -9), Pair(-49, -21),
      Pair(25, -38), Pair(1, -6), Pair(-3, 4), Pair(-24, 14), Pair(-29, 15), Pair(-18, 5), Pair(-1, -13), Pair(10, -39),
      Pair(10, -63), Pair(33, -37), Pair(24, -20), Pair(-39, 2), Pair(4, -20), Pair(-25, -7), Pair(16, -33), Pair(18, -72)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-27, -2), Pair(-12, -6), Pair(-3, 14), Pair(2, 23), Pair(6, 31), Pair(10, 39), Pair(16, 39), Pair(19, 37),
  Pair(22, 31)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-28, -14), Pair(-18, -22), Pair(-9, -6), Pair(-4, 6), Pair(2, 15), Pair(5, 24), Pair(8, 28), Pair(10, 32),
  Pair(12, 36), Pair(17, 35), Pair(26, 33), Pair(33, 34), Pair(33, 48), Pair(39, 30)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-34, -31), Pair(-24, -4), Pair(-19, 1), Pair(-20, 15), Pair(-20, 20), Pair(-16, 23), Pair(-14, 28), Pair(-11, 31),
  Pair(-8, 35), Pair(-5, 38), Pair(-2, 40), Pair(-1, 45), Pair(3, 47), Pair(6, 46), Pair(3, 45)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-70, -121), Pair(-16, -241), Pair(-24, -32), Pair(-17, 14), Pair(-17, 56), Pair(-16, 74), Pair(-13, 88), Pair(-12, 101),
  Pair(-10, 109), Pair(-7, 110), Pair(-5, 115), Pair(-4, 123), Pair(-1, 119), Pair(-1, 123), Pair(2, 122), Pair(6, 119),
  Pair(5, 123), Pair(8, 120), Pair(17, 110), Pair(30, 97), Pair(37, 89), Pair(78, 59), Pair(75, 53), Pair(91, 30),
  Pair(135, 14), Pair(232, -62), Pair(145, -13), Pair(74, 4)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-12, -77), Pair(-12, -63), Pair(-10, -31), Pair(16, 4), Pair(12, 72), Pair(29, 67), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(15, 7), Pair(23, 17), Pair(48, 59), Pair(122, 191), Pair(14, 382), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 11), Pair(13, 8), Pair(12, 16), Pair(21, 43), Pair(151, 38), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-7, -45), Pair(11, -36), Pair(2, -25), Pair(1, -15), Pair(-8, -6), Pair(-7, -19), Pair(10, -32), Pair(-2, -49)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-8, 12), Pair(-1, -12), Pair(-11, -4), Pair(-8, -12), Pair(-11, -15), Pair(-4, -6), Pair(0, -12), Pair(-7, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(22, 5), Pair(19, 2), Pair(17, 8), Pair(18, 8), Pair(19, 13), Pair(31, 3), Pair(39, 3), Pair(66, -1)
  },
  {
      Pair(9, 33), Pair(10, 10), Pair(10, 8), Pair(18, 0), Pair(14, 1), Pair(15, -3), Pair(22, 0), Pair(16, 19)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -6), Pair(17, -6), Pair(9, -3),
  Pair(22, -11), Pair(18, -11), Pair(20, -11),
  Pair(31, -4), Pair(0, 0), Pair(28, -3),
  Pair(-9, 6), Pair(-7, 0), Pair(-8, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-5, 0), Pair(-13, 2), Pair(-7, 2),
  Pair(-5, 0), Pair(-14, 4), Pair(-8, 3),
  Pair(1, -7), Pair(-11, 0), Pair(0, -5),
  Pair(15, -8), Pair(-2, -5), Pair(13, -6),
  Pair(30, -9), Pair(25, 0), Pair(24, -9),
  Pair(0, 0), Pair(15, -31), Pair(0, 0),
  Pair(57, -49), Pair(0, 0), Pair(52, -46)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-8, 65), Pair(-11, 49), Pair(-2, 28), Pair(2, 18), Pair(5, 16), Pair(17, 14), Pair(6, 11)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-76, 6), Pair(-8, 8), Pair(-6, 31), Pair(2, 39), Pair(4, 44), Pair(5, 49), Pair(-9, 46)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-281, 201);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-55, -13), Pair(-68, -6), Pair(-36, -9), Pair(-24, -8), Pair(-20, -2), Pair(-36, 0), Pair(-49, 3), Pair(-33, 5)
  },
  {
      Pair(-2, 45), Pair(-31, 19), Pair(-17, 12), Pair(3, -4), Pair(-2, -7), Pair(-3, 4), Pair(-27, 23), Pair(-15, 34)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -1), Pair(28, -9), Pair(63, -30), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 0), Pair(33, -4), Pair(63, -12), Pair(69, -40), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(20, -21), Pair(36, -22), Pair(54, -16), Pair(81, -19), Pair(92, -29), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 12), Pair(12, 23), Pair(32, 28), Pair(77, 10), Pair(111, 6), Pair(168, -14), Pair(229, -62)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(47, 7), Pair(19, 21), Pair(60, -1), Pair(28, 12), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-20, 13), Pair(-13, 17)
  },
  {
      Pair(-64, -19), Pair(-64, -26)
  },
  {
      Pair(-53, -45), Pair(-62, -66)
  },
  {
      Pair(-86, 1), Pair(-72, -36)
  },
  {
      Pair(-68, 28), Pair(-72, -7)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(3, -13), Pair(12, -7)
  },
  {
      Pair(-24, -33), Pair(-3, -49)
  },
  {
      Pair(-41, -32), Pair(-28, -33)
  },
  {
      Pair(-77, -5), Pair(-57, -30)
  },
  {
      Pair(-53, 27), Pair(-53, 9)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-9, -19), Pair(1, -9)
  },
  {
      Pair(-48, -23), Pair(-21, -23)
  },
  {
      Pair(1, -97), Pair(12, -90)
  },
  {
      Pair(-77, -8), Pair(-44, -36)
  },
  {
      Pair(-77, -34), Pair(-61, -73)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-3, -25), Pair(10, -11)
  },
  {
      Pair(-42, -24), Pair(-3, -12)
  },
  {
      Pair(-30, -29), Pair(-13, -3)
  },
  {
      Pair(-13, -35), Pair(5, -10)
  },
  {
      Pair(-74, -10), Pair(-60, -44)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(17, 23), Pair(15, 13), Pair(35, 22), Pair(42, 23), Pair(47, 28), Pair(31, 44), Pair(41, 17), Pair(-5, 41),
  Pair(1, 15), Pair(17, 17), Pair(19, 21), Pair(8, 34), Pair(14, 23), Pair(13, 21), Pair(17, 16), Pair(-2, 26),
  Pair(9, 10), Pair(6, 3), Pair(1, 17), Pair(8, 18), Pair(6, 22), Pair(-8, 20), Pair(1, 7), Pair(0, 9)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-10, 15), Pair(20, 0), Pair(29, 2), Pair(42, 3), Pair(67, -14), Pair(43, 0), Pair(26, -10), Pair(-15, -27),
  Pair(-19, -9), Pair(25, 7), Pair(14, 4), Pair(25, 13), Pair(17, 6), Pair(20, 1), Pair(17, 12), Pair(21, -21),
  Pair(-23, 30), Pair(10, 6), Pair(3, 21), Pair(19, 14), Pair(23, 25), Pair(3, 10), Pair(14, 0), Pair(-46, 10)
};

constexpr ScorePair kBishopPairBonus = Pair(19, 58);

constexpr ScorePair kTempoBonus = Pair(30, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H