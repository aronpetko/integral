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
  Pair(114, 108), Pair(368, 234), Pair(413, 274), Pair(540, 529), Pair(964, 980), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(130, -2), Pair(61, 44), Pair(51, 45), Pair(71, 37), Pair(37, 65), Pair(70, 47), Pair(-25, 68), Pair(67, -3),
      Pair(17, -10), Pair(-5, 9), Pair(25, -7), Pair(31, -11), Pair(32, -6), Pair(66, -24), Pair(-2, 6), Pair(25, -21),
      Pair(-1, -5), Pair(2, -7), Pair(8, -21), Pair(15, -28), Pair(33, -24), Pair(21, -31), Pair(8, -12), Pair(0, -17),
      Pair(-12, -17), Pair(-22, -7), Pair(4, -26), Pair(13, -29), Pair(10, -32), Pair(15, -26), Pair(-13, -12), Pair(-6, -20),
      Pair(-16, -15), Pair(-24, -10), Pair(-19, -20), Pair(-17, -19), Pair(-7, -26), Pair(-11, -12), Pair(7, -21), Pair(-3, -23),
      Pair(-16, -4), Pair(-12, -4), Pair(-18, -5), Pair(-14, -10), Pair(-13, -16), Pair(17, -11), Pair(17, -14), Pair(0, -24),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-135, -14), Pair(-88, -11), Pair(-67, -27), Pair(31, -18), Pair(50, -39), Pair(-41, -28), Pair(-84, -38), Pair(-31, -8),
      Pair(-11, -41), Pair(6, -17), Pair(57, -43), Pair(73, -23), Pair(76, -34), Pair(78, -55), Pair(-4, -17), Pair(23, -44),
      Pair(12, -21), Pair(57, -29), Pair(47, 2), Pair(71, -22), Pair(82, -15), Pair(92, -13), Pair(38, -11), Pair(40, -30),
      Pair(45, -23), Pair(42, -11), Pair(60, -7), Pair(60, 6), Pair(59, -15), Pair(86, -17), Pair(55, -18), Pair(59, -31),
      Pair(37, -16), Pair(44, -31), Pair(54, 4), Pair(61, 6), Pair(66, -6), Pair(76, -16), Pair(74, -26), Pair(40, 6),
      Pair(3, -31), Pair(36, -22), Pair(35, -5), Pair(51, 11), Pair(56, -4), Pair(45, -9), Pair(52, -28), Pair(24, -30),
      Pair(-7, -41), Pair(24, 3), Pair(23, -28), Pair(34, -17), Pair(35, -18), Pair(41, -37), Pair(15, -23), Pair(19, -33),
      Pair(-79, -39), Pair(4, -37), Pair(10, -44), Pair(10, -32), Pair(26, -20), Pair(11, -33), Pair(7, -34), Pair(-7, -67)
  },
  {
      Pair(-24, -21), Pair(2, -15), Pair(-7, -34), Pair(-24, -24), Pair(-26, -16), Pair(-106, -11), Pair(15, -23), Pair(5, -23),
      Pair(-15, -14), Pair(0, -9), Pair(-6, -6), Pair(20, -20), Pair(-10, -11), Pair(20, -12), Pair(-6, -10), Pair(-19, -22),
      Pair(13, -16), Pair(35, -33), Pair(15, -2), Pair(37, -11), Pair(52, -31), Pair(27, -8), Pair(33, -34), Pair(8, -16),
      Pair(6, -22), Pair(9, -12), Pair(20, -5), Pair(42, 5), Pair(23, 5), Pair(51, -41), Pair(5, -12), Pair(25, -34),
      Pair(16, -39), Pair(17, -12), Pair(8, 2), Pair(10, -15), Pair(31, -23), Pair(5, -3), Pair(23, -25), Pair(18, -38),
      Pair(0, -19), Pair(16, -15), Pair(12, -3), Pair(19, -8), Pair(12, 3), Pair(30, -12), Pair(27, -16), Pair(8, -20),
      Pair(10, -25), Pair(15, -30), Pair(37, -51), Pair(7, -18), Pair(22, -22), Pair(26, -31), Pair(35, -33), Pair(29, -57),
      Pair(-3, -32), Pair(31, -47), Pair(-5, -18), Pair(7, -33), Pair(20, -30), Pair(-6, -15), Pair(16, -46), Pair(6, -35)
  },
  {
      Pair(51, -29), Pair(52, -15), Pair(45, -7), Pair(49, -20), Pair(58, -26), Pair(82, -40), Pair(37, -23), Pair(35, -16),
      Pair(16, -16), Pair(39, -12), Pair(41, -12), Pair(75, -29), Pair(57, -26), Pair(79, -33), Pair(17, -21), Pair(20, -23),
      Pair(21, -28), Pair(63, -34), Pair(60, -29), Pair(50, -35), Pair(75, -37), Pair(99, -44), Pair(49, -33), Pair(28, -35),
      Pair(16, -29), Pair(40, -25), Pair(54, -30), Pair(47, -29), Pair(69, -37), Pair(45, -24), Pair(37, -28), Pair(14, -29),
      Pair(-10, -21), Pair(2, -13), Pair(-8, -1), Pair(8, -19), Pair(2, -26), Pair(-3, -9), Pair(-9, -12), Pair(-14, -18),
      Pair(-15, -39), Pair(-1, -24), Pair(-15, -16), Pair(-6, -22), Pair(12, -30), Pair(-11, -28), Pair(-8, -19), Pair(-32, -21),
      Pair(-12, -47), Pair(-12, -33), Pair(8, -37), Pair(12, -45), Pair(9, -44), Pair(13, -44), Pair(-6, -40), Pair(-63, -24),
      Pair(5, -49), Pair(7, -44), Pair(4, -32), Pair(21, -52), Pair(23, -52), Pair(20, -49), Pair(-24, -23), Pair(-4, -44)
  },
  {
      Pair(4, 39), Pair(6, 52), Pair(-4, 49), Pair(48, 12), Pair(37, 29), Pair(50, 19), Pair(49, 28), Pair(17, 36),
      Pair(-29, 49), Pair(-30, 73), Pair(-8, 62), Pair(-5, 68), Pair(15, 70), Pair(-1, 65), Pair(-29, 94), Pair(22, 40),
      Pair(-13, 26), Pair(-7, 61), Pair(-4, 92), Pair(3, 107), Pair(15, 100), Pair(22, 89), Pair(32, 45), Pair(-4, 48),
      Pair(-18, 52), Pair(-5, 63), Pair(7, 77), Pair(-9, 106), Pair(-10, 117), Pair(-14, 87), Pair(-4, 56), Pair(4, 39),
      Pair(-9, 15), Pair(-8, 42), Pair(-14, 62), Pair(-17, 94), Pair(1, 69), Pair(-5, 69), Pair(5, 46), Pair(-9, 19),
      Pair(-16, 21), Pair(0, 33), Pair(-4, 40), Pair(-11, 43), Pair(-4, 35), Pair(7, 19), Pair(3, 14), Pair(-1, -8),
      Pair(-3, -16), Pair(2, -22), Pair(5, -16), Pair(1, -4), Pair(6, -4), Pair(13, -38), Pair(27, -57), Pair(1, -41),
      Pair(-11, -17), Pair(-17, -20), Pair(-18, -14), Pair(-8, -14), Pair(-10, -15), Pair(-6, -48), Pair(-38, -42), Pair(-23, -28)
  },
  {
      Pair(35, -147), Pair(109, 46), Pair(125, 49), Pair(-3, 56), Pair(22, 46), Pair(-25, 62), Pair(10, 60), Pair(118, -130),
      Pair(-104, 2), Pair(55, 59), Pair(52, 16), Pair(98, 0), Pair(58, 22), Pair(12, 9), Pair(31, 46), Pair(-145, -42),
      Pair(4, -25), Pair(146, 2), Pair(51, 6), Pair(-78, 16), Pair(-50, 15), Pair(26, -3), Pair(36, -32), Pair(6, -33),
      Pair(9, -38), Pair(86, -23), Pair(13, 17), Pair(-124, 23), Pair(-127, 20), Pair(-31, 2), Pair(31, -30), Pair(-90, -32),
      Pair(-37, -63), Pair(62, -29), Pair(-17, 6), Pair(-88, 19), Pair(-92, 18), Pair(-7, -1), Pair(35, -33), Pair(-45, -34),
      Pair(-54, -30), Pair(20, -15), Pair(-11, 2), Pair(-41, 19), Pair(-47, 22), Pair(-28, 12), Pair(19, -17), Pair(-8, -32),
      Pair(36, -35), Pair(8, 0), Pair(-11, 7), Pair(-40, 22), Pair(-38, 24), Pair(-29, 24), Pair(10, 1), Pair(19, -27),
      Pair(-37, 24), Pair(29, -14), Pair(17, 0), Pair(-70, 8), Pair(-9, -7), Pair(-37, 11), Pair(27, -9), Pair(14, -11)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(10, -31), Pair(29, -32), Pair(38, -14), Pair(45, 0), Pair(51, 9), Pair(54, 22), Pair(60, 12), Pair(64, 5),
  Pair(68, -33)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-10, -51), Pair(5, -52), Pair(12, -35), Pair(19, -25), Pair(23, -11), Pair(27, -7), Pair(29, -6), Pair(31, -4),
  Pair(39, -11), Pair(47, -14), Pair(70, -30), Pair(67, -40), Pair(114, -52), Pair(-9, -44)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-24, -81), Pair(-10, -67), Pair(-5, -53), Pair(4, -49), Pair(5, -38), Pair(8, -30), Pair(13, -28), Pair(17, -24),
  Pair(16, -10), Pair(25, -12), Pair(31, -10), Pair(36, -8), Pair(30, 8), Pair(52, -10), Pair(34, -25)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-27, -73), Pair(-22, -166), Pair(-19, -31), Pair(-16, -1), Pair(-14, 25), Pair(-14, 28), Pair(-13, 43), Pair(-12, 67),
  Pair(-9, 64), Pair(-8, 73), Pair(-5, 73), Pair(-3, 78), Pair(0, 74), Pair(1, 79), Pair(0, 77), Pair(7, 71),
  Pair(11, 60), Pair(20, 36), Pair(35, 21), Pair(28, 10), Pair(29, 2), Pair(32, -24), Pair(44, -28), Pair(27, -55),
  Pair(65, -70), Pair(172, -152), Pair(89, -100), Pair(27, -80)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-18, -51), Pair(-17, -34), Pair(-8, -7), Pair(11, 23), Pair(60, 51), Pair(113, 6), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 3), Pair(13, 1), Pair(21, 23), Pair(54, 55), Pair(162, 134), Pair(-26, 401), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(23, 5), Pair(16, 5), Pair(20, 13), Pair(50, 29), Pair(163, 2), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-42, -35), Pair(4, -25), Pair(-17, -10), Pair(-18, -2), Pair(-20, -3), Pair(-26, -12), Pair(20, -24), Pair(-31, -13)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-6, -2), Pair(-2, -14), Pair(-9, -7), Pair(-16, -11), Pair(-21, -14), Pair(-1, -6), Pair(-13, 0), Pair(-11, -9)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(59, -29), Pair(42, -31), Pair(40, -25), Pair(44, -20), Pair(44, -18), Pair(39, -19), Pair(65, -32), Pair(81, -29)
  },
  {
      Pair(32, 4), Pair(25, -23), Pair(35, -29), Pair(28, -22), Pair(30, -22), Pair(23, -25), Pair(41, -25), Pair(46, -18)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -9), Pair(10, -15), Pair(12, -8),
  Pair(18, -10), Pair(10, -8), Pair(19, -10),
  Pair(13, 6), Pair(0, 0), Pair(15, 4),
  Pair(25, 2), Pair(-29, 22), Pair(0, 10)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 5), Pair(-13, 17), Pair(-7, 10),
  Pair(-5, 2), Pair(-21, 21), Pair(-7, 6),
  Pair(6, -9), Pair(-5, 4), Pair(3, -6),
  Pair(16, -11), Pair(-11, -2), Pair(14, -6),
  Pair(19, -25), Pair(42, -16), Pair(28, -26),
  Pair(0, 0), Pair(-49, -3), Pair(0, 0),
  Pair(73, -68), Pair(0, 0), Pair(73, -69)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(7, 40), Pair(-13, 41), Pair(-4, 17), Pair(8, 3), Pair(-2, 9), Pair(20, 9), Pair(26, -7)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-35, -31), Pair(5, -12), Pair(4, 20), Pair(-2, 44), Pair(0, 54), Pair(5, 53), Pair(6, 61)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-368, 175);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-64, 43), Pair(-95, 3), Pair(-25, -25), Pair(-14, -26), Pair(0, -30), Pair(-9, -30), Pair(-42, 2), Pair(-56, 22)
  },
  {
      Pair(-66, 54), Pair(-14, 8), Pair(-31, 10), Pair(2, -6), Pair(-13, -10), Pair(-3, 4), Pair(-24, 27), Pair(-32, 47)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -4), Pair(28, -1), Pair(82, -18), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(14, -2), Pair(33, -1), Pair(60, -7), Pair(12, -10), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(23, -21), Pair(36, -22), Pair(80, -41), Pair(136, -54), Pair(165, -67), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(5, -4), Pair(18, 2), Pair(47, -13), Pair(94, -38), Pair(150, -59), Pair(240, -96), Pair(239, -132)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(34, -10), Pair(14, 7), Pair(98, -37), Pair(26, -14), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-15, 27), Pair(2, 21)
  },
  {
      Pair(-75, -14), Pair(-67, -11)
  },
  {
      Pair(-53, -35), Pair(-60, -51)
  },
  {
      Pair(-71, -32), Pair(-51, -40)
  },
  {
      Pair(-50, 9), Pair(-54, 10)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(18, 36), Pair(21, 21), Pair(25, 22), Pair(32, -32), Pair(47, 9)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-5, -28), Pair(7, -15)
  },
  {
      Pair(-6, -52), Pair(1, -68)
  },
  {
      Pair(-46, -7), Pair(-42, -18)
  },
  {
      Pair(-65, -2), Pair(-61, -9)
  },
  {
      Pair(-42, -3), Pair(-40, 4)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-22, -25), Pair(-3, -9)
  },
  {
      Pair(-43, -4), Pair(-21, -33)
  },
  {
      Pair(-10, -87), Pair(0, -90)
  },
  {
      Pair(-50, -16), Pair(-49, -39)
  },
  {
      Pair(-49, -67), Pair(-46, -63)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-14, -24), Pair(10, -20)
  },
  {
      Pair(-42, -17), Pair(-4, -22)
  },
  {
      Pair(-54, -4), Pair(-9, -13)
  },
  {
      Pair(15, -67), Pair(14, -50)
  },
  {
      Pair(-57, -66), Pair(-50, -58)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(51, 30), Pair(20, 30), Pair(32, 31), Pair(35, 33), Pair(58, 23), Pair(-14, 34), Pair(47, 40), Pair(55, -4),
  Pair(39, 17), Pair(12, 0), Pair(-11, 52), Pair(2, 39), Pair(11, 67), Pair(-26, 51), Pair(13, 8), Pair(4, 39),
  Pair(7, -6), Pair(5, 40), Pair(-2, 22), Pair(16, 21), Pair(6, 16), Pair(-1, 18), Pair(-16, 34), Pair(17, -28)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-82, -23), Pair(8, 5), Pair(76, -21), Pair(35, -21), Pair(105, -2), Pair(-7, 7), Pair(60, 35), Pair(-78, 34),
  Pair(22, -2), Pair(14, 15), Pair(16, 6), Pair(8, -8), Pair(7, 9), Pair(-18, 36), Pair(20, 28), Pair(-1, 37),
  Pair(-44, 36), Pair(-24, 12), Pair(10, 14), Pair(24, 36), Pair(8, 34), Pair(3, 15), Pair(-16, 37), Pair(-35, 25)
};

constexpr ScorePair kBishopPairBonus = Pair(47, 38);

constexpr ScorePair kTempoBonus = Pair(21, 2);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H