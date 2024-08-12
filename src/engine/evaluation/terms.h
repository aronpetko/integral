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
  Pair(100, -15), Pair(407, 121), Pair(457, 248), Pair(619, 465), Pair(1286, 801), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(86, 58), Pair(72, 76), Pair(33, 80), Pair(30, 71), Pair(16, 86), Pair(35, 93), Pair(-22, 107), Pair(25, 74),
      Pair(16, 108), Pair(-1, 129), Pair(26, 102), Pair(34, 87), Pair(36, 92), Pair(63, 85), Pair(18, 117), Pair(16, 107),
      Pair(1, 108), Pair(11, 108), Pair(11, 89), Pair(18, 82), Pair(37, 83), Pair(28, 78), Pair(30, 94), Pair(5, 95),
      Pair(-6, 96), Pair(-7, 104), Pair(7, 87), Pair(17, 85), Pair(18, 78), Pair(23, 81), Pair(16, 91), Pair(4, 89),
      Pair(-13, 96), Pair(-9, 102), Pair(-10, 92), Pair(-3, 93), Pair(7, 83), Pair(2, 93), Pair(28, 84), Pair(3, 86),
      Pair(-9, 105), Pair(2, 107), Pair(-6, 103), Pair(-1, 100), Pair(0, 96), Pair(27, 95), Pair(42, 91), Pair(5, 87),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-199, 89), Pair(-76, 55), Pair(-39, 38), Pair(71, 30), Pair(72, 22), Pair(-14, 30), Pair(-96, 45), Pair(-12, 35),
      Pair(-9, 34), Pair(7, 55), Pair(55, 28), Pair(78, 39), Pair(117, 23), Pair(79, 22), Pair(-4, 64), Pair(21, 32),
      Pair(15, 47), Pair(55, 46), Pair(50, 60), Pair(71, 50), Pair(87, 42), Pair(97, 36), Pair(45, 45), Pair(32, 51),
      Pair(44, 45), Pair(45, 57), Pair(61, 57), Pair(68, 64), Pair(62, 58), Pair(78, 62), Pair(56, 47), Pair(56, 37),
      Pair(37, 53), Pair(43, 47), Pair(56, 66), Pair(64, 67), Pair(67, 60), Pair(74, 45), Pair(69, 49), Pair(43, 63),
      Pair(5, 41), Pair(36, 48), Pair(35, 56), Pair(51, 73), Pair(55, 66), Pair(45, 50), Pair(49, 45), Pair(32, 34),
      Pair(-9, 44), Pair(28, 64), Pair(24, 48), Pair(38, 51), Pair(38, 48), Pair(40, 34), Pair(22, 49), Pair(21, 41),
      Pair(-58, 44), Pair(3, 42), Pair(18, 32), Pair(18, 37), Pair(34, 50), Pair(22, 34), Pair(4, 40), Pair(1, 9)
  },
  {
      Pair(-72, 17), Pair(9, 7), Pair(-17, -3), Pair(-14, 1), Pair(-3, 5), Pair(-119, 11), Pair(33, -1), Pair(-25, -7),
      Pair(-15, 6), Pair(-4, 7), Pair(-6, 13), Pair(23, 9), Pair(-17, 13), Pair(23, 10), Pair(-4, 10), Pair(-15, -5),
      Pair(8, 8), Pair(19, 4), Pair(10, 15), Pair(28, 4), Pair(64, -5), Pair(32, 15), Pair(24, 10), Pair(5, 9),
      Pair(0, 4), Pair(4, 14), Pair(12, 13), Pair(38, 10), Pair(14, 15), Pair(29, 11), Pair(0, 12), Pair(22, -8),
      Pair(11, -14), Pair(14, 3), Pair(11, 14), Pair(8, 2), Pair(27, 1), Pair(5, 11), Pair(18, 3), Pair(12, -13),
      Pair(1, -1), Pair(12, 9), Pair(11, 9), Pair(18, 12), Pair(12, 19), Pair(28, 4), Pair(24, 2), Pair(12, -4),
      Pair(10, 2), Pair(11, -10), Pair(32, -19), Pair(8, 2), Pair(21, -2), Pair(24, -8), Pair(33, -16), Pair(25, -28),
      Pair(6, -16), Pair(27, -8), Pair(-1, 1), Pair(11, -8), Pair(20, -5), Pair(-3, 5), Pair(20, -24), Pair(16, -26)
  },
  {
      Pair(62, -4), Pair(57, 10), Pair(23, 28), Pair(57, 10), Pair(53, 3), Pair(141, -24), Pair(27, 11), Pair(51, 6),
      Pair(28, 3), Pair(50, 6), Pair(51, 4), Pair(84, -12), Pair(68, -11), Pair(94, -20), Pair(27, 2), Pair(35, -1),
      Pair(28, 0), Pair(76, -15), Pair(78, -12), Pair(58, -13), Pair(89, -22), Pair(114, -28), Pair(59, -8), Pair(32, -5),
      Pair(20, -2), Pair(49, -3), Pair(65, -8), Pair(56, -7), Pair(86, -23), Pair(58, -9), Pair(41, -4), Pair(23, -4),
      Pair(-3, 7), Pair(15, 7), Pair(9, 15), Pair(18, 2), Pair(16, -9), Pair(10, 9), Pair(7, 6), Pair(-3, 3),
      Pair(-7, -10), Pair(14, -2), Pair(0, 6), Pair(10, -4), Pair(29, -16), Pair(9, -10), Pair(9, -4), Pair(-14, -7),
      Pair(-10, -13), Pair(0, -9), Pair(19, -12), Pair(21, -18), Pair(21, -22), Pair(25, -24), Pair(11, -23), Pair(-38, -6),
      Pair(8, -19), Pair(14, -18), Pair(14, -9), Pair(26, -25), Pair(31, -31), Pair(26, -24), Pair(-8, -8), Pair(3, -18)
  },
  {
      Pair(64, 0), Pair(74, 10), Pair(18, 53), Pair(59, 26), Pair(75, 18), Pair(109, -9), Pair(91, 8), Pair(62, 19),
      Pair(28, 37), Pair(23, 53), Pair(40, 47), Pair(31, 63), Pair(69, 38), Pair(55, 34), Pair(34, 65), Pair(71, 28),
      Pair(44, 10), Pair(45, 43), Pair(54, 54), Pair(57, 65), Pair(67, 58), Pair(73, 50), Pair(93, 10), Pair(54, 19),
      Pair(39, 29), Pair(55, 32), Pair(65, 41), Pair(50, 55), Pair(50, 60), Pair(49, 39), Pair(55, 25), Pair(67, -1),
      Pair(51, -9), Pair(54, 16), Pair(50, 25), Pair(50, 49), Pair(63, 27), Pair(59, 24), Pair(72, 4), Pair(50, -4),
      Pair(47, 1), Pair(62, -1), Pair(56, 13), Pair(53, 15), Pair(60, 1), Pair(72, -19), Pair(66, -25), Pair(63, -38),
      Pair(60, -47), Pair(65, -52), Pair(65, -35), Pair(64, -31), Pair(67, -26), Pair(76, -71), Pair(88, -86), Pair(68, -68),
      Pair(67, -60), Pair(54, -61), Pair(51, -59), Pair(56, -45), Pair(54, -39), Pair(68, -98), Pair(50, -114), Pair(47, -49)
  },
  {
      Pair(197, -172), Pair(-122, 56), Pair(106, -4), Pair(-9, -9), Pair(-167, 35), Pair(27, 7), Pair(-92, 36), Pair(113, -167),
      Pair(-68, -5), Pair(56, 35), Pair(52, 24), Pair(42, 18), Pair(14, 11), Pair(-67, 51), Pair(30, 35), Pair(-125, -36),
      Pair(21, -11), Pair(97, 24), Pair(-15, 38), Pair(-126, 48), Pair(-102, 55), Pair(25, 34), Pair(11, 21), Pair(59, -18),
      Pair(-26, -11), Pair(22, 10), Pair(-12, 28), Pair(-132, 47), Pair(-172, 54), Pair(-23, 25), Pair(25, -9), Pair(-55, -24),
      Pair(-53, -33), Pair(26, -6), Pair(-15, 15), Pair(-69, 30), Pair(-62, 33), Pair(-18, 12), Pair(22, -18), Pair(-78, -5),
      Pair(-50, -17), Pair(7, -2), Pair(-12, 11), Pair(-31, 19), Pair(-46, 27), Pair(-25, 17), Pair(3, -7), Pair(-24, -15),
      Pair(33, -37), Pair(4, -6), Pair(-15, 6), Pair(-27, 12), Pair(-33, 17), Pair(-25, 14), Pair(5, -7), Pair(18, -33),
      Pair(13, -61), Pair(32, -29), Pair(21, -15), Pair(-57, -2), Pair(-8, -16), Pair(-27, -1), Pair(28, -28), Pair(28, -58)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(8, 54), Pair(29, 37), Pair(38, 51), Pair(45, 65), Pair(52, 73), Pair(57, 84), Pair(62, 78), Pair(64, 79),
  Pair(68, 68)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-10, -17), Pair(11, -26), Pair(20, -12), Pair(26, -4), Pair(32, 7), Pair(36, 10), Pair(38, 13), Pair(40, 17),
  Pair(45, 15), Pair(52, 17), Pair(66, 7), Pair(67, 11), Pair(73, 19), Pair(75, 9)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-20, -57), Pair(-2, -45), Pair(4, -32), Pair(10, -25), Pair(11, -12), Pair(14, -5), Pair(18, -3), Pair(22, 0),
  Pair(25, 7), Pair(34, 5), Pair(40, 5), Pair(46, 6), Pair(44, 19), Pair(68, -1), Pair(114, -25)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(47, 20), Pair(47, -92), Pair(51, -90), Pair(55, -48), Pair(58, -21), Pair(60, -22), Pair(61, -7), Pair(62, 15),
  Pair(65, 13), Pair(67, 20), Pair(70, 21), Pair(73, 23), Pair(77, 20), Pair(78, 23), Pair(77, 24), Pair(84, 20),
  Pair(84, 15), Pair(92, -6), Pair(105, -18), Pair(109, -34), Pair(125, -54), Pair(149, -80), Pair(188, -109), Pair(167, -101),
  Pair(250, -174), Pair(386, -230), Pair(106, -112), Pair(125, -128)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-21, -82), Pair(-21, -71), Pair(-7, -49), Pair(12, -19), Pair(47, 31), Pair(85, 88), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 3), Pair(12, 5), Pair(20, 26), Pair(51, 58), Pair(241, 84), Pair(97, 285), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 9), Pair(15, 8), Pair(17, 16), Pair(46, 34), Pair(120, 28), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-46, -31), Pair(-11, -18), Pair(-15, -9), Pair(-13, -1), Pair(-25, 9), Pair(-26, -3), Pair(-8, -9), Pair(-42, -10)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(2, 0), Pair(-3, -15), Pair(-8, -7), Pair(-13, -13), Pair(-17, -16), Pair(-1, -9), Pair(-14, -3), Pair(6, -8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(35, -4), Pair(20, 0), Pair(17, 4), Pair(28, -1), Pair(27, 4), Pair(22, 3), Pair(47, -9), Pair(61, -11)
  },
  {
      Pair(24, 21), Pair(17, -5), Pair(23, -10), Pair(21, -6), Pair(22, -5), Pair(17, -10), Pair(38, -14), Pair(39, -1)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(14, -8), Pair(13, -12), Pair(14, -6),
  Pair(18, -9), Pair(12, -11), Pair(18, -10),
  Pair(25, -6), Pair(0, 0), Pair(24, -7),
  Pair(14, -1), Pair(-19, 8), Pair(-7, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-13, 12), Pair(-8, 5),
  Pair(-7, 0), Pair(-19, 15), Pair(-10, 4),
  Pair(2, -8), Pair(-7, 3), Pair(0, -6),
  Pair(13, -10), Pair(-11, -3), Pair(13, -7),
  Pair(21, -20), Pair(36, -12), Pair(27, -20),
  Pair(0, 0), Pair(-90, 15), Pair(0, 0),
  Pair(12, -44), Pair(0, 0), Pair(25, -43)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(10, 55), Pair(-8, 55), Pair(-8, 40), Pair(5, 23), Pair(1, 24), Pair(19, 25), Pair(18, 24)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-3, -6), Pair(-5, 20), Pair(2, 44), Pair(-1, 65), Pair(1, 71), Pair(2, 70), Pair(2, 75)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-410, 113);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-44, -4), Pair(-60, -18), Pair(-34, -20), Pair(-16, -17), Pair(-3, -19), Pair(-24, -16), Pair(-40, -4), Pair(-33, -8)
  },
  {
      Pair(-59, 42), Pair(-24, 18), Pair(-34, 17), Pair(-8, 4), Pair(-8, -7), Pair(-11, 12), Pair(-24, 29), Pair(-10, 23)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 3), Pair(23, 2), Pair(75, -15), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 0), Pair(26, 3), Pair(53, -4), Pair(-6, -1), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -14), Pair(22, -10), Pair(47, -15), Pair(59, -8), Pair(96, -20), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(1, 20), Pair(8, 40), Pair(31, 35), Pair(64, 27), Pair(113, 11), Pair(222, -43), Pair(355, -134)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(32, -2), Pair(15, 15), Pair(50, -4), Pair(20, 9), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-5, 17), Pair(2, 19)
  },
  {
      Pair(-65, -24), Pair(-62, -21)
  },
  {
      Pair(-49, -38), Pair(-54, -51)
  },
  {
      Pair(-65, -28), Pair(-50, -34)
  },
  {
      Pair(-49, 21), Pair(-48, -6)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(17, 30), Pair(18, 23), Pair(25, 15), Pair(24, -11), Pair(37, 5)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-5, -20), Pair(7, -10)
  },
  {
      Pair(6, -71), Pair(7, -79)
  },
  {
      Pair(-42, -8), Pair(-37, -18)
  },
  {
      Pair(-62, 2), Pair(-55, -8)
  },
  {
      Pair(-37, 2), Pair(-34, -2)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-19, -19), Pair(-2, -6)
  },
  {
      Pair(-39, -13), Pair(-23, -28)
  },
  {
      Pair(-14, -62), Pair(-7, -63)
  },
  {
      Pair(-59, -2), Pair(-52, -29)
  },
  {
      Pair(-48, -45), Pair(-44, -46)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-7, -25), Pair(12, -17)
  },
  {
      Pair(-41, -10), Pair(-7, -16)
  },
  {
      Pair(-44, -5), Pair(-10, -9)
  },
  {
      Pair(12, -59), Pair(16, -46)
  },
  {
      Pair(-66, -3), Pair(-45, -46)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(50, 16), Pair(12, 24), Pair(25, 21), Pair(32, 17), Pair(47, 20), Pair(-14, 38), Pair(36, 43), Pair(66, -13),
  Pair(35, 11), Pair(8, 0), Pair(-10, 35), Pair(-1, 28), Pair(9, 42), Pair(-18, 29), Pair(13, 5), Pair(-6, 42),
  Pair(2, -6), Pair(7, 30), Pair(-4, 13), Pair(13, 17), Pair(5, 11), Pair(-2, 17), Pair(-10, 25), Pair(10, -20)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-129, 5), Pair(12, -1), Pair(74, -18), Pair(33, -11), Pair(76, -10), Pair(-37, 25), Pair(49, 20), Pair(-66, 1),
  Pair(29, -10), Pair(13, 9), Pair(17, 5), Pair(3, 6), Pair(9, 11), Pair(0, -1), Pair(18, 16), Pair(-11, 51),
  Pair(-46, 26), Pair(-18, 10), Pair(7, 13), Pair(25, 28), Pair(7, 25), Pair(2, 13), Pair(-13, 24), Pair(-15, -8)
};

constexpr ScorePair kBishopPairBonus = Pair(32, 37);

constexpr ScorePair kTempoBonus = Pair(17, 4);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H