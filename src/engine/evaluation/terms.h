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
  Pair(98, 100), Pair(353, 123), Pair(361, 208), Pair(525, 509), Pair(1098, 931), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(68, -16), Pair(43, 3), Pair(29, -2), Pair(38, -19), Pair(26, -11), Pair(33, 3), Pair(-27, 23), Pair(19, -6),
      Pair(-9, 18), Pair(-20, 35), Pair(3, 2), Pair(11, -14), Pair(14, -10), Pair(37, -11), Pair(-3, 24), Pair(-5, 13),
      Pair(-24, 11), Pair(-16, 14), Pair(-14, -7), Pair(-9, -17), Pair(6, -16), Pair(4, -17), Pair(-6, 3), Pair(-16, -2),
      Pair(-31, 0), Pair(-31, 11), Pair(-19, -9), Pair(-10, -15), Pair(-7, -19), Pair(-3, -14), Pair(-15, 0), Pair(-20, -10),
      Pair(-37, -2), Pair(-34, 8), Pair(-32, -7), Pair(-28, -5), Pair(-21, -10), Pair(-22, -6), Pair(-8, -6), Pair(-22, -13),
      Pair(-33, 5), Pair(-24, 13), Pair(-28, 3), Pair(-28, 1), Pair(-23, 1), Pair(-1, -3), Pair(3, 0), Pair(-20, -11),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-176, 35), Pair(-64, 25), Pair(-69, 23), Pair(27, 14), Pair(29, 6), Pair(-93, 23), Pair(-57, 19), Pair(-74, 11),
      Pair(-23, 10), Pair(-13, 31), Pair(21, 14), Pair(37, 23), Pair(54, 13), Pair(42, 7), Pair(-24, 36), Pair(-5, 12),
      Pair(-7, 22), Pair(15, 26), Pair(13, 38), Pair(29, 29), Pair(46, 23), Pair(57, 16), Pair(12, 23), Pair(8, 19),
      Pair(10, 22), Pair(9, 34), Pair(24, 35), Pair(29, 40), Pair(23, 38), Pair(38, 36), Pair(17, 29), Pair(21, 19),
      Pair(0, 30), Pair(8, 27), Pair(18, 42), Pair(22, 41), Pair(24, 39), Pair(32, 26), Pair(27, 27), Pair(8, 36),
      Pair(-23, 16), Pair(0, 25), Pair(1, 31), Pair(13, 44), Pair(18, 39), Pair(9, 27), Pair(13, 21), Pair(-5, 17),
      Pair(-31, 18), Pair(-10, 35), Pair(-9, 23), Pair(1, 27), Pair(3, 25), Pair(2, 15), Pair(-7, 24), Pair(-11, 18),
      Pair(-60, 14), Pair(-25, 15), Pair(-15, 15), Pair(-11, 18), Pair(-2, 24), Pair(-9, 12), Pair(-24, 16), Pair(-30, 3)
  },
  {
      Pair(-47, 23), Pair(-26, 24), Pair(-34, 16), Pair(-28, 17), Pair(-14, 17), Pair(-99, 23), Pair(6, 12), Pair(-34, 8),
      Pair(-24, 16), Pair(-16, 21), Pair(-15, 24), Pair(-1, 20), Pair(-25, 22), Pair(1, 17), Pair(-25, 25), Pair(-15, 8),
      Pair(-5, 20), Pair(1, 20), Pair(0, 23), Pair(13, 16), Pair(32, 12), Pair(21, 25), Pair(14, 20), Pair(-2, 19),
      Pair(-13, 16), Pair(-5, 23), Pair(0, 22), Pair(19, 23), Pair(3, 26), Pair(13, 22), Pair(-7, 22), Pair(4, 9),
      Pair(-3, 3), Pair(-5, 17), Pair(-1, 24), Pair(-2, 18), Pair(9, 15), Pair(-5, 21), Pair(0, 17), Pair(-1, 4),
      Pair(-11, 12), Pair(3, 21), Pair(1, 21), Pair(3, 24), Pair(0, 27), Pair(11, 17), Pair(9, 14), Pair(0, 11),
      Pair(0, 13), Pair(0, 3), Pair(11, 3), Pair(-5, 15), Pair(5, 13), Pair(9, 7), Pair(17, 1), Pair(8, -7),
      Pair(-8, 2), Pair(8, 9), Pair(-12, 14), Pair(-6, 10), Pair(2, 10), Pair(-13, 16), Pair(0, -2), Pair(3, -6)
  },
  {
      Pair(11, 17), Pair(13, 26), Pair(-2, 37), Pair(8, 28), Pair(7, 23), Pair(59, 10), Pair(-1, 26), Pair(3, 22),
      Pair(-17, 25), Pair(-4, 27), Pair(4, 24), Pair(26, 13), Pair(16, 12), Pair(29, 9), Pair(-14, 21), Pair(-7, 17),
      Pair(-15, 21), Pair(15, 12), Pair(16, 12), Pair(7, 11), Pair(28, 3), Pair(38, 4), Pair(17, 9), Pair(-9, 14),
      Pair(-23, 18), Pair(-4, 19), Pair(7, 16), Pair(5, 12), Pair(20, 3), Pair(6, 13), Pair(0, 13), Pair(-19, 13),
      Pair(-40, 21), Pair(-30, 25), Pair(-30, 28), Pair(-25, 19), Pair(-27, 12), Pair(-31, 25), Pair(-29, 19), Pair(-37, 15),
      Pair(-42, 7), Pair(-29, 14), Pair(-36, 18), Pair(-31, 13), Pair(-19, 3), Pair(-32, 9), Pair(-21, 3), Pair(-38, 1),
      Pair(-45, 1), Pair(-36, 6), Pair(-25, 6), Pair(-23, 2), Pair(-22, -3), Pair(-22, -2), Pair(-23, -10), Pair(-57, -2),
      Pair(-30, -2), Pair(-26, 0), Pair(-24, 5), Pair(-17, -4), Pair(-13, -10), Pair(-18, -2), Pair(-33, 1), Pair(-31, -7)
  },
  {
      Pair(1, -1), Pair(1, 13), Pair(-33, 43), Pair(-2, 20), Pair(5, 20), Pair(36, -5), Pair(29, 2), Pair(9, 10),
      Pair(-28, 26), Pair(-38, 45), Pair(-25, 47), Pair(-26, 57), Pair(-15, 51), Pair(-6, 34), Pair(-15, 51), Pair(7, 27),
      Pair(-24, 15), Pair(-16, 33), Pair(-14, 52), Pair(-15, 58), Pair(-2, 53), Pair(2, 51), Pair(17, 22), Pair(-8, 22),
      Pair(-21, 16), Pair(-13, 29), Pair(-11, 37), Pair(-17, 52), Pair(-14, 54), Pair(-10, 36), Pair(-9, 28), Pair(2, 0),
      Pair(-17, -1), Pair(-19, 21), Pair(-19, 28), Pair(-20, 46), Pair(-11, 32), Pair(-13, 24), Pair(-4, 15), Pair(-14, 4),
      Pair(-20, -5), Pair(-12, 3), Pair(-16, 17), Pair(-17, 15), Pair(-13, 10), Pair(-5, -3), Pair(-3, -16), Pair(-6, -21),
      Pair(-13, -29), Pair(-10, -35), Pair(-8, -27), Pair(-8, -20), Pair(-7, -18), Pair(0, -46), Pair(7, -61), Pair(-2, -55),
      Pair(-13, -38), Pair(-16, -52), Pair(-17, -45), Pair(-16, -33), Pair(-15, -36), Pair(-13, -67), Pair(-19, -83), Pair(-14, -48)
  },
  {
      Pair(229, -156), Pair(-63, 61), Pair(117, 7), Pair(29, 7), Pair(-114, 49), Pair(4, 30), Pair(-52, 42), Pair(144, -165),
      Pair(14, 0), Pair(40, 53), Pair(20, 48), Pair(33, 38), Pair(16, 36), Pair(-24, 61), Pair(1, 61), Pair(-80, -12),
      Pair(24, 8), Pair(50, 45), Pair(-6, 55), Pair(-81, 62), Pair(-62, 66), Pair(27, 52), Pair(19, 41), Pair(52, 6),
      Pair(-8, 1), Pair(28, 22), Pair(-28, 46), Pair(-89, 56), Pair(-118, 61), Pair(-34, 43), Pair(14, 16), Pair(-41, -1),
      Pair(-32, -17), Pair(17, 10), Pair(-32, 32), Pair(-67, 44), Pair(-62, 44), Pair(-30, 27), Pair(-1, 5), Pair(-70, 6),
      Pair(-36, -6), Pair(11, 9), Pair(-23, 24), Pair(-35, 32), Pair(-47, 36), Pair(-30, 26), Pair(-5, 7), Pair(-28, -4),
      Pair(32, -24), Pair(8, 4), Pair(-9, 17), Pair(-23, 22), Pair(-30, 25), Pair(-21, 19), Pair(2, 3), Pair(17, -21),
      Pair(18, -47), Pair(32, -17), Pair(24, -7), Pair(-34, 5), Pair(1, -10), Pair(-19, 4), Pair(24, -15), Pair(28, -45)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-13, 84), Pair(3, 115), Pair(11, 131), Pair(16, 143), Pair(20, 150), Pair(24, 158), Pair(28, 156), Pair(31, 156),
  Pair(33, 149)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-4, 38), Pair(9, 51), Pair(16, 63), Pair(20, 73), Pair(25, 82), Pair(28, 86), Pair(29, 89), Pair(31, 93),
  Pair(32, 93), Pair(38, 93), Pair(47, 89), Pair(50, 91), Pair(56, 97), Pair(62, 87)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-38, -34), Pair(-25, -16), Pair(-21, -5), Pair(-17, 4), Pair(-16, 13), Pair(-13, 19), Pair(-11, 21), Pair(-7, 24),
  Pair(-5, 29), Pair(1, 30), Pair(5, 29), Pair(9, 32), Pair(9, 38), Pair(22, 29), Pair(47, 16)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(12, -170), Pair(16, -139), Pair(18, -77), Pair(21, -40), Pair(22, -14), Pair(24, -8), Pair(26, 6), Pair(26, 22),
  Pair(28, 26), Pair(30, 30), Pair(32, 34), Pair(33, 39), Pair(36, 38), Pair(36, 41), Pair(36, 44), Pair(38, 44),
  Pair(39, 41), Pair(44, 28), Pair(50, 21), Pair(56, 10), Pair(64, -3), Pair(84, -23), Pair(107, -40), Pair(104, -43),
  Pair(196, -112), Pair(349, -180), Pair(182, -120), Pair(312, -178)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-10, -91), Pair(-12, -77), Pair(-4, -49), Pair(14, -16), Pair(31, 37), Pair(40, 97), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(12, 4), Pair(17, 21), Pair(38, 57), Pair(183, 98), Pair(170, 281), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(18, 9), Pair(13, 7), Pair(15, 15), Pair(36, 37), Pair(122, 33), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-25, -41), Pair(-4, -28), Pair(-10, -17), Pair(-10, -7), Pair(-16, 1), Pair(-18, -12), Pair(-2, -20), Pair(-24, -30)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(0, 5), Pair(-3, -13), Pair(-8, -6), Pair(-10, -13), Pair(-14, -15), Pair(-4, -8), Pair(-7, -7), Pair(0, -1)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(28, -1), Pair(18, 1), Pair(17, 4), Pair(21, 3), Pair(23, 6), Pair(24, 1), Pair(39, -3), Pair(54, -6)
  },
  {
      Pair(16, 27), Pair(13, 4), Pair(17, -1), Pair(17, -1), Pair(17, 0), Pair(16, -6), Pair(26, -4), Pair(26, 10)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -6), Pair(13, -8), Pair(11, -4),
  Pair(19, -8), Pair(14, -8), Pair(18, -8),
  Pair(25, -5), Pair(0, 0), Pair(24, -5),
  Pair(5, 4), Pair(-15, 6), Pair(-7, 8)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, 1), Pair(-13, 9), Pair(-7, 4),
  Pair(-6, 0), Pair(-16, 10), Pair(-8, 2),
  Pair(1, -7), Pair(-7, 1), Pair(-1, -5),
  Pair(11, -8), Pair(-8, -3), Pair(9, -6),
  Pair(18, -14), Pair(23, -7), Pair(18, -13),
  Pair(0, 0), Pair(-53, -2), Pair(0, 0),
  Pair(19, -41), Pair(0, 0), Pair(27, -41)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-4, 38), Pair(-17, 32), Pair(-14, 16), Pair(-6, 2), Pair(-6, 1), Pair(8, 0), Pair(6, -2)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-20, 18), Pair(2, 39), Pair(6, 62), Pair(7, 78), Pair(8, 84), Pair(7, 86), Pair(2, 89)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-473, 95);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-55, 2), Pair(-53, -10), Pair(-30, -14), Pair(-21, -10), Pair(-13, -10), Pair(-24, -8), Pair(-41, 0), Pair(-33, -1)
  },
  {
      Pair(-31, 38), Pair(-30, 21), Pair(-26, 14), Pair(-10, 5), Pair(-7, -4), Pair(-8, 10), Pair(-23, 24), Pair(-16, 27)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, 2), Pair(17, 0), Pair(59, -15), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 1), Pair(21, 2), Pair(41, -3), Pair(-10, -2), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(14, -12), Pair(20, -11), Pair(38, -11), Pair(51, -9), Pair(60, -14), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(1, 17), Pair(7, 34), Pair(20, 36), Pair(48, 29), Pair(83, 20), Pair(177, -23), Pair(251, -75)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(26, 0), Pair(11, 15), Pair(38, -1), Pair(16, 12), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-4, 14), Pair(0, 16)
  },
  {
      Pair(-54, -23), Pair(-49, -27)
  },
  {
      Pair(-42, -38), Pair(-43, -46)
  },
  {
      Pair(-58, -25), Pair(-47, -30)
  },
  {
      Pair(-42, 11), Pair(-39, -7)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 26), Pair(16, 20), Pair(20, 12), Pair(19, -5), Pair(34, -1)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -22), Pair(6, -10)
  },
  {
      Pair(10, -24), Pair(11, -32)
  },
  {
      Pair(-34, -10), Pair(-29, -20)
  },
  {
      Pair(-50, -3), Pair(-44, -12)
  },
  {
      Pair(-30, -9), Pair(-27, -13)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-13, -19), Pair(0, -7)
  },
  {
      Pair(-37, -15), Pair(-18, -29)
  },
  {
      Pair(4, -29), Pair(10, -35)
  },
  {
      Pair(-48, -8), Pair(-41, -34)
  },
  {
      Pair(-40, -34), Pair(-34, -45)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-7, -24), Pair(8, -14)
  },
  {
      Pair(-35, -15), Pair(-5, -17)
  },
  {
      Pair(-33, -15), Pair(-10, -10)
  },
  {
      Pair(11, -24), Pair(12, -10)
  },
  {
      Pair(-54, -5), Pair(-36, -44)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(34, 15), Pair(9, 17), Pair(20, 14), Pair(23, 19), Pair(23, 23), Pair(-2, 33), Pair(21, 34), Pair(31, 1),
  Pair(16, 18), Pair(10, 3), Pair(1, 23), Pair(1, 24), Pair(8, 27), Pair(-9, 21), Pair(9, 7), Pair(1, 21),
  Pair(3, 2), Pair(2, 17), Pair(-1, 9), Pair(8, 13), Pair(2, 11), Pair(-2, 12), Pair(-7, 17), Pair(5, -7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-59, 1), Pair(13, 1), Pair(45, -6), Pair(27, -2), Pair(52, -8), Pair(0, 11), Pair(29, 10), Pair(-40, 12),
  Pair(-4, -6), Pair(12, 8), Pair(11, 6), Pair(7, 10), Pair(9, 7), Pair(5, 1), Pair(11, 15), Pair(0, 21),
  Pair(-24, 20), Pair(-7, 11), Pair(3, 15), Pair(17, 21), Pair(9, 22), Pair(2, 10), Pair(-2, 16), Pair(-28, 0)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 47);

constexpr ScorePair kTempoBonus = Pair(15, 5);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H