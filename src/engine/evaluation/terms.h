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
  Pair(88, 136), Pair(393, 238), Pair(408, 256), Pair(531, 529), Pair(1250, 975), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(135, 126), Pair(98, 142), Pair(96, 138), Pair(127, 113), Pair(132, 112), Pair(97, 138), Pair(32, 163), Pair(104, 125),
      Pair(10, -1), Pair(5, 2), Pair(14, -23), Pair(29, -43), Pair(31, -39), Pair(50, -34), Pair(1, 1), Pair(6, -7),
      Pair(-9, -11), Pair(-1, -13), Pair(-2, -33), Pair(8, -43), Pair(21, -46), Pair(21, -47), Pair(5, -21), Pair(-6, -20),
      Pair(-17, -22), Pair(-17, -14), Pair(-4, -35), Pair(8, -42), Pair(11, -45), Pair(15, -43), Pair(0, -25), Pair(-8, -31),
      Pair(-24, -26), Pair(-19, -20), Pair(-18, -31), Pair(-12, -34), Pair(-6, -35), Pair(-7, -35), Pair(4, -33), Pair(-10, -36),
      Pair(-18, -17), Pair(-8, -15), Pair(-13, -21), Pair(-15, -24), Pair(-7, -22), Pair(14, -30), Pair(16, -28), Pair(-8, -33),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-176, 6), Pair(6, 4), Pair(-39, 18), Pair(35, 13), Pair(14, 28), Pair(-147, 31), Pair(-42, 31), Pair(-63, -16),
      Pair(-15, 25), Pair(0, 42), Pair(19, 33), Pair(51, 37), Pair(58, 29), Pair(55, 22), Pair(-6, 35), Pair(-9, 26),
      Pair(2, 22), Pair(17, 36), Pair(23, 49), Pair(43, 46), Pair(58, 33), Pair(67, 36), Pair(20, 41), Pair(21, 13),
      Pair(15, 37), Pair(18, 53), Pair(35, 49), Pair(40, 61), Pair(34, 66), Pair(46, 54), Pair(24, 49), Pair(30, 41),
      Pair(5, 44), Pair(17, 44), Pair(27, 57), Pair(33, 60), Pair(32, 62), Pair(43, 51), Pair(32, 42), Pair(16, 44),
      Pair(-15, 28), Pair(6, 38), Pair(11, 40), Pair(24, 58), Pair(28, 52), Pair(21, 40), Pair(24, 32), Pair(1, 29),
      Pair(-20, 22), Pair(-6, 42), Pair(0, 34), Pair(10, 40), Pair(15, 38), Pair(11, 29), Pair(5, 35), Pair(-4, 27),
      Pair(-63, 32), Pair(-19, 24), Pair(-18, 25), Pair(-5, 35), Pair(12, 31), Pair(-3, 23), Pair(-16, 30), Pair(-43, 23)
  },
  {
      Pair(-39, 58), Pair(-32, 51), Pair(-71, 55), Pair(-66, 53), Pair(-34, 47), Pair(-153, 66), Pair(-51, 50), Pair(-31, 34),
      Pair(-18, 36), Pair(-15, 60), Pair(-6, 54), Pair(-1, 49), Pair(-16, 50), Pair(-8, 46), Pair(-28, 57), Pair(-7, 32),
      Pair(7, 45), Pair(8, 54), Pair(1, 61), Pair(22, 41), Pair(25, 48), Pair(34, 55), Pair(14, 60), Pair(20, 44),
      Pair(-3, 41), Pair(8, 50), Pair(6, 53), Pair(20, 58), Pair(12, 61), Pair(27, 53), Pair(6, 50), Pair(9, 41),
      Pair(12, 32), Pair(-4, 45), Pair(13, 50), Pair(11, 52), Pair(19, 47), Pair(11, 46), Pair(8, 47), Pair(10, 31),
      Pair(4, 40), Pair(21, 49), Pair(13, 54), Pair(15, 53), Pair(11, 57), Pair(24, 47), Pair(21, 41), Pair(14, 36),
      Pair(20, 32), Pair(16, 30), Pair(21, 26), Pair(7, 45), Pair(18, 41), Pair(23, 31), Pair(30, 31), Pair(21, 12),
      Pair(8, 17), Pair(14, 46), Pair(1, 42), Pair(-1, 42), Pair(12, 36), Pair(-3, 44), Pair(6, 18), Pair(14, 17)
  },
  {
      Pair(61, 31), Pair(53, 47), Pair(30, 61), Pair(40, 54), Pair(45, 52), Pair(48, 52), Pair(66, 44), Pair(34, 43),
      Pair(20, 45), Pair(23, 50), Pair(41, 44), Pair(64, 38), Pair(51, 36), Pair(49, 41), Pair(11, 50), Pair(1, 46),
      Pair(18, 44), Pair(45, 35), Pair(38, 42), Pair(60, 23), Pair(67, 22), Pair(65, 30), Pair(52, 30), Pair(3, 41),
      Pair(10, 41), Pair(27, 41), Pair(36, 39), Pair(43, 25), Pair(43, 25), Pair(40, 32), Pair(29, 35), Pair(13, 33),
      Pair(-10, 41), Pair(6, 42), Pair(7, 45), Pair(10, 40), Pair(12, 35), Pair(6, 41), Pair(2, 38), Pair(-7, 36),
      Pair(-7, 24), Pair(5, 26), Pair(-7, 37), Pair(4, 30), Pair(5, 22), Pair(0, 32), Pair(14, 15), Pair(1, 15),
      Pair(-18, 16), Pair(1, 20), Pair(4, 22), Pair(7, 24), Pair(14, 13), Pair(9, 21), Pair(6, 4), Pair(-24, 13),
      Pair(0, 19), Pair(6, 19), Pair(7, 25), Pair(19, 13), Pair(21, 6), Pair(17, 17), Pair(-1, 20), Pair(5, 9)
  },
  {
      Pair(-14, 45), Pair(22, 19), Pair(22, 32), Pair(30, 31), Pair(49, 22), Pair(73, 0), Pair(36, 22), Pair(23, 26),
      Pair(-12, 36), Pair(-31, 82), Pair(-3, 70), Pair(-13, 92), Pair(-23, 77), Pair(17, 51), Pair(15, 51), Pair(31, 20),
      Pair(1, -1), Pair(10, 27), Pair(7, 62), Pair(9, 58), Pair(9, 95), Pair(23, 71), Pair(33, 40), Pair(28, 13),
      Pair(11, 4), Pair(5, 36), Pair(7, 49), Pair(1, 84), Pair(14, 58), Pair(27, 44), Pair(14, 44), Pair(31, -1),
      Pair(5, 3), Pair(-6, 35), Pair(2, 42), Pair(-3, 70), Pair(10, 49), Pair(7, 38), Pair(18, 25), Pair(9, 6),
      Pair(5, -13), Pair(11, 0), Pair(8, 12), Pair(9, 13), Pair(8, 28), Pair(16, 12), Pair(22, -4), Pair(14, -7),
      Pair(13, -44), Pair(15, -43), Pair(19, -42), Pair(16, -15), Pair(17, -11), Pair(27, -61), Pair(30, -69), Pair(11, -39),
      Pair(12, -50), Pair(6, -61), Pair(8, -47), Pair(9, -43), Pair(13, -50), Pair(1, -68), Pair(3, -77), Pair(27, -61)
  },
  {
      Pair(-26, -174), Pair(139, 4), Pair(166, 28), Pair(107, 23), Pair(83, 4), Pair(132, -3), Pair(143, -30), Pair(-14, -175),
      Pair(89, 6), Pair(128, 67), Pair(80, 71), Pair(92, 48), Pair(72, 49), Pair(66, 109), Pair(93, 69), Pair(51, -36),
      Pair(-60, 59), Pair(60, 78), Pair(0, 97), Pair(-62, 103), Pair(-65, 116), Pair(72, 84), Pair(76, 71), Pair(81, 19),
      Pair(-28, 38), Pair(119, 42), Pair(-27, 81), Pair(-93, 104), Pair(-94, 96), Pair(-8, 75), Pair(31, 47), Pair(-37, 21),
      Pair(-22, 20), Pair(22, 42), Pair(-5, 68), Pair(-46, 88), Pair(-48, 83), Pair(-19, 64), Pair(23, 42), Pair(-36, 21),
      Pair(1, 24), Pair(39, 39), Pair(-15, 64), Pair(-34, 79), Pair(-32, 78), Pair(-6, 62), Pair(9, 47), Pair(-24, 33),
      Pair(57, 1), Pair(27, 40), Pair(12, 54), Pair(-12, 66), Pair(-16, 66), Pair(2, 56), Pair(23, 39), Pair(44, 5),
      Pair(33, -14), Pair(60, 14), Pair(48, 28), Pair(-14, 45), Pair(26, 18), Pair(1, 36), Pair(54, 15), Pair(59, -24)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-28, -37), Pair(-9, -6), Pair(1, 21), Pair(7, 32), Pair(11, 39), Pair(15, 47), Pair(19, 48), Pair(22, 47),
  Pair(24, 43)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-22, -32), Pair(-7, -10), Pair(1, 0), Pair(6, 13), Pair(11, 22), Pair(14, 30), Pair(17, 33), Pair(18, 37),
  Pair(18, 41), Pair(23, 40), Pair(30, 37), Pair(33, 39), Pair(41, 37), Pair(49, 34)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-31, -51), Pair(-16, -23), Pair(-11, -15), Pair(-6, -1), Pair(-5, 8), Pair(-1, 10), Pair(2, 15), Pair(8, 17),
  Pair(12, 21), Pair(18, 23), Pair(25, 21), Pair(27, 24), Pair(32, 28), Pair(36, 24), Pair(79, 2)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-24, -127), Pair(-13, -152), Pair(-10, -80), Pair(-7, -65), Pair(-6, -32), Pair(-4, -24), Pair(-2, -7), Pair(0, 4),
  Pair(2, 18), Pair(4, 24), Pair(5, 31), Pair(7, 33), Pair(9, 37), Pair(11, 39), Pair(9, 47), Pair(14, 40),
  Pair(17, 33), Pair(21, 28), Pair(19, 23), Pair(42, 0), Pair(53, -17), Pair(85, -55), Pair(89, -65), Pair(120, -91),
  Pair(110, -104), Pair(75, -95), Pair(8, -60), Pair(11, -77)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-19, -72), Pair(-20, -57), Pair(-13, -26), Pair(8, 10), Pair(18, 67), Pair(-30, -30), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 2), Pair(15, 4), Pair(16, 21), Pair(39, 66), Pair(134, 123), Pair(163, 175), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(19, 10), Pair(14, 8), Pair(15, 18), Pair(40, 43), Pair(149, 27), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-27, -39), Pair(-1, -27), Pair(-12, -17), Pair(-15, -7), Pair(-10, -4), Pair(-14, -10), Pair(0, -20), Pair(-16, -40)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(3, 2), Pair(-6, -10), Pair(-9, -8), Pair(-11, -13), Pair(-14, -12), Pair(-7, -10), Pair(-4, -11), Pair(-2, 0)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(25, 2), Pair(19, 4), Pair(19, 6), Pair(18, 6), Pair(30, 4), Pair(31, -2), Pair(45, -5), Pair(55, -5)
  },
  {
      Pair(19, 27), Pair(14, 9), Pair(19, -1), Pair(20, -2), Pair(20, -2), Pair(21, -8), Pair(30, -3), Pair(23, 17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -2), Pair(12, -6), Pair(11, -3),
  Pair(19, -6), Pair(14, -5), Pair(19, -5),
  Pair(26, -1), Pair(0, 0), Pair(24, -1),
  Pair(-8, 12), Pair(-38, 18), Pair(-3, 11)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, 3), Pair(-17, 10), Pair(-8, 4),
  Pair(-9, 2), Pair(-19, 11), Pair(-9, 2),
  Pair(0, -7), Pair(-13, 4), Pair(-1, -6),
  Pair(9, -4), Pair(-13, 1), Pair(11, -6),
  Pair(23, -13), Pair(27, -8), Pair(22, -14),
  Pair(0, 0), Pair(-54, -4), Pair(0, 0),
  Pair(37, -57), Pair(0, 0), Pair(52, -58)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(9, 51), Pair(-9, 49), Pair(-8, 31), Pair(-4, 19), Pair(6, 15), Pair(14, 16), Pair(9, 11)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-15, -28), Pair(5, -3), Pair(6, 29), Pair(14, 37), Pair(10, 46), Pair(7, 51), Pair(3, 47)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(27, 120);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-62, 10), Pair(-75, 4), Pair(-30, -12), Pair(-20, -17), Pair(-16, -14), Pair(-29, -8), Pair(-51, 1), Pair(-54, 8)
  },
  {
      Pair(-29, 56), Pair(-52, 33), Pair(-23, 13), Pair(-14, 2), Pair(-10, 2), Pair(-19, 14), Pair(-28, 27), Pair(-35, 52)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 0), Pair(19, -5), Pair(58, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, 2), Pair(22, 2), Pair(38, 1), Pair(24, -14), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(17, -20), Pair(29, -21), Pair(43, -12), Pair(70, -14), Pair(57, -14), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 25), Pair(9, 37), Pair(22, 50), Pair(61, 25), Pair(96, 28), Pair(127, 31), Pair(144, -20)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(27, 3), Pair(13, 21), Pair(46, -2), Pair(18, 18), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-6, 31), Pair(1, 30)
  },
  {
      Pair(-64, -23), Pair(-56, -33)
  },
  {
      Pair(-51, -48), Pair(-49, -66)
  },
  {
      Pair(-69, -33), Pair(-59, -37)
  },
  {
      Pair(-48, -4), Pair(-47, -3)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 28), Pair(21, 25), Pair(22, 13), Pair(21, 0), Pair(43, -4)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-6, -24), Pair(7, -11)
  },
  {
      Pair(5, 9), Pair(5, 0)
  },
  {
      Pair(-42, -12), Pair(-30, -30)
  },
  {
      Pair(-62, -6), Pair(-55, -10)
  },
  {
      Pair(-45, 4), Pair(-31, -28)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-16, -21), Pair(0, -7)
  },
  {
      Pair(-47, -15), Pair(-20, -29)
  },
  {
      Pair(-1, 0), Pair(6, -7)
  },
  {
      Pair(-54, -17), Pair(-52, -33)
  },
  {
      Pair(-49, -35), Pair(-42, -59)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-9, -29), Pair(11, -16)
  },
  {
      Pair(-44, -18), Pair(-6, -19)
  },
  {
      Pair(-33, -26), Pair(-14, -12)
  },
  {
      Pair(14, -35), Pair(10, -9)
  },
  {
      Pair(-58, -34), Pair(-44, -68)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(9, 8), Pair(8, 17), Pair(36, 19), Pair(23, 22), Pair(23, 39), Pair(-1, 41), Pair(21, 27), Pair(-22, 58),
  Pair(-5, 15), Pair(10, 0), Pair(6, 24), Pair(2, 23), Pair(4, 25), Pair(-1, 23), Pair(11, 12), Pair(5, 9),
  Pair(4, 6), Pair(-1, 12), Pair(0, 13), Pair(7, 11), Pair(2, 17), Pair(-4, 12), Pair(-8, 15), Pair(8, -4)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-67, 40), Pair(17, 14), Pair(30, 1), Pair(35, 11), Pair(52, 2), Pair(45, 7), Pair(46, -12), Pair(-11, 17),
  Pair(-15, 38), Pair(9, 17), Pair(23, 6), Pair(19, 10), Pair(13, 14), Pair(4, 1), Pair(14, 13), Pair(-6, 3),
  Pair(12, 4), Pair(8, 13), Pair(1, 23), Pair(20, 14), Pair(14, 25), Pair(-1, 19), Pair(10, 14), Pair(-28, 23)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 53);

constexpr ScorePair kTempoBonus = Pair(17, 9);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H