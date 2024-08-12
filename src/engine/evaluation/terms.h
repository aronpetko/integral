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
  Pair(80, 0), Pair(371, 142), Pair(418, 259), Pair(576, 493), Pair(1271, 822), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(65, 76), Pair(49, 91), Pair(31, 89), Pair(44, 68), Pair(27, 77), Pair(38, 88), Pair(-25, 109), Pair(8, 89),
      Pair(11, 119), Pair(2, 133), Pair(23, 102), Pair(30, 85), Pair(35, 87), Pair(57, 89), Pair(27, 120), Pair(13, 114),
      Pair(-4, 111), Pair(4, 113), Pair(4, 93), Pair(9, 83), Pair(26, 82), Pair(24, 83), Pair(21, 100), Pair(3, 99),
      Pair(-12, 100), Pair(-10, 110), Pair(0, 90), Pair(11, 83), Pair(14, 80), Pair(18, 84), Pair(13, 96), Pair(-2, 90),
      Pair(-17, 97), Pair(-13, 106), Pair(-11, 92), Pair(-6, 92), Pair(1, 88), Pair(0, 92), Pair(19, 89), Pair(-3, 86),
      Pair(-13, 103), Pair(-1, 110), Pair(-6, 100), Pair(-7, 99), Pair(0, 99), Pair(21, 95), Pair(32, 93), Pair(-2, 88),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-189, 80), Pair(-57, 60), Pair(-37, 52), Pair(53, 43), Pair(57, 35), Pair(-41, 45), Pair(-72, 61), Pair(-47, 26),
      Pair(4, 39), Pair(16, 58), Pair(48, 43), Pair(64, 51), Pair(84, 40), Pair(69, 35), Pair(4, 61), Pair(19, 42),
      Pair(20, 49), Pair(41, 54), Pair(41, 64), Pair(57, 54), Pair(73, 50), Pair(86, 42), Pair(39, 49), Pair(34, 44),
      Pair(35, 50), Pair(36, 60), Pair(52, 60), Pair(58, 64), Pair(52, 63), Pair(67, 60), Pair(44, 55), Pair(49, 46),
      Pair(26, 56), Pair(34, 55), Pair(45, 68), Pair(50, 66), Pair(52, 64), Pair(59, 52), Pair(54, 52), Pair(35, 61),
      Pair(5, 42), Pair(27, 50), Pair(28, 55), Pair(40, 67), Pair(46, 63), Pair(36, 52), Pair(40, 47), Pair(22, 44),
      Pair(-3, 44), Pair(15, 59), Pair(18, 48), Pair(28, 52), Pair(30, 51), Pair(29, 42), Pair(21, 50), Pair(16, 43),
      Pair(-33, 42), Pair(1, 41), Pair(12, 42), Pair(18, 45), Pair(26, 48), Pair(20, 36), Pair(2, 41), Pair(-5, 32)
  },
  {
      Pair(-51, 20), Pair(-18, 16), Pair(-27, 11), Pair(-22, 11), Pair(-6, 10), Pair(-98, 18), Pair(16, 4), Pair(-48, 10),
      Pair(-15, 8), Pair(-7, 14), Pair(-5, 15), Pair(10, 11), Pair(-16, 12), Pair(10, 7), Pair(-17, 17), Pair(-6, 1),
      Pair(6, 11), Pair(10, 13), Pair(7, 15), Pair(21, 7), Pair(41, 3), Pair(41, 13), Pair(26, 10), Pair(10, 9),
      Pair(-5, 8), Pair(5, 15), Pair(10, 13), Pair(28, 14), Pair(14, 17), Pair(24, 13), Pair(3, 13), Pair(12, 2),
      Pair(6, -3), Pair(2, 10), Pair(9, 14), Pair(9, 10), Pair(19, 7), Pair(6, 12), Pair(8, 9), Pair(8, -3),
      Pair(-1, 4), Pair(15, 12), Pair(11, 12), Pair(13, 15), Pair(10, 17), Pair(21, 8), Pair(20, 5), Pair(12, 2),
      Pair(11, 5), Pair(11, -6), Pair(20, -4), Pair(5, 7), Pair(15, 4), Pair(19, -1), Pair(28, -8), Pair(18, -14),
      Pair(3, -6), Pair(18, 1), Pair(-1, 5), Pair(4, 3), Pair(12, 1), Pair(-2, 7), Pair(11, -9), Pair(16, -15)
  },
  {
      Pair(39, 12), Pair(42, 19), Pair(33, 27), Pair(35, 21), Pair(39, 15), Pair(105, -2), Pair(29, 20), Pair(31, 14),
      Pair(13, 18), Pair(26, 20), Pair(36, 16), Pair(57, 5), Pair(48, 4), Pair(61, 2), Pair(16, 16), Pair(24, 10),
      Pair(15, 15), Pair(46, 6), Pair(47, 5), Pair(39, 3), Pair(61, -6), Pair(76, -6), Pair(52, 3), Pair(22, 7),
      Pair(6, 12), Pair(26, 12), Pair(38, 8), Pair(36, 4), Pair(53, -7), Pair(37, 4), Pair(32, 6), Pair(10, 6),
      Pair(-11, 14), Pair(0, 18), Pair(3, 18), Pair(6, 11), Pair(4, 5), Pair(1, 15), Pair(2, 11), Pair(-8, 7),
      Pair(-13, 2), Pair(1, 6), Pair(-4, 9), Pair(-1, 5), Pair(11, -6), Pair(0, 1), Pair(13, -6), Pair(-5, -10),
      Pair(-16, -6), Pair(-6, -2), Pair(5, -1), Pair(6, -5), Pair(9, -11), Pair(9, -10), Pair(9, -18), Pair(-22, -13),
      Pair(-2, -8), Pair(3, -7), Pair(6, -3), Pair(12, -11), Pair(17, -18), Pair(12, -11), Pair(-1, -8), Pair(-1, -16)
  },
  {
      Pair(61, 5), Pair(67, 14), Pair(28, 48), Pair(58, 25), Pair(70, 21), Pair(102, -5), Pair(94, 2), Pair(76, 9),
      Pair(43, 23), Pair(31, 43), Pair(42, 49), Pair(42, 57), Pair(47, 55), Pair(64, 33), Pair(56, 50), Pair(77, 24),
      Pair(45, 14), Pair(54, 31), Pair(53, 53), Pair(52, 57), Pair(66, 52), Pair(70, 49), Pair(87, 20), Pair(63, 17),
      Pair(49, 11), Pair(56, 27), Pair(56, 36), Pair(50, 51), Pair(54, 52), Pair(62, 33), Pair(63, 24), Pair(73, -5),
      Pair(52, -5), Pair(49, 21), Pair(50, 27), Pair(49, 43), Pair(57, 31), Pair(56, 21), Pair(65, 15), Pair(57, 0),
      Pair(50, -10), Pair(57, -1), Pair(53, 16), Pair(53, 11), Pair(56, 9), Pair(64, -4), Pair(67, -19), Pair(64, -22),
      Pair(55, -30), Pair(59, -37), Pair(62, -30), Pair(61, -22), Pair(63, -21), Pair(70, -47), Pair(76, -63), Pair(68, -58),
      Pair(58, -41), Pair(55, -55), Pair(54, -48), Pair(54, -37), Pair(55, -39), Pair(56, -68), Pair(55, -91), Pair(59, -49)
  },
  {
      Pair(210, -151), Pair(-109, 65), Pair(105, -2), Pair(4, 6), Pair(-151, 48), Pair(17, 15), Pair(-85, 39), Pair(112, -161),
      Pair(-47, 4), Pair(49, 36), Pair(35, 32), Pair(34, 27), Pair(23, 25), Pair(-38, 50), Pair(18, 45), Pair(-103, -13),
      Pair(23, -4), Pair(70, 27), Pair(-2, 42), Pair(-98, 53), Pair(-70, 53), Pair(38, 37), Pair(22, 28), Pair(61, -7),
      Pair(-13, -11), Pair(27, 8), Pair(-19, 31), Pair(-100, 46), Pair(-136, 50), Pair(-27, 28), Pair(25, 3), Pair(-43, -10),
      Pair(-38, -28), Pair(17, -4), Pair(-29, 18), Pair(-69, 32), Pair(-56, 29), Pair(-31, 14), Pair(7, -9), Pair(-74, -8),
      Pair(-33, -21), Pair(14, -6), Pair(-24, 10), Pair(-40, 20), Pair(-48, 21), Pair(-30, 11), Pair(-9, -6), Pair(-33, -18),
      Pair(28, -37), Pair(5, -9), Pair(-11, 3), Pair(-27, 9), Pair(-35, 12), Pair(-24, 5), Pair(-3, -10), Pair(13, -34),
      Pair(16, -57), Pair(31, -30), Pair(23, -20), Pair(-36, -7), Pair(0, -25), Pair(-21, -10), Pair(20, -27), Pair(26, -59)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(6, 20), Pair(21, 45), Pair(29, 61), Pair(34, 73), Pair(38, 80), Pair(42, 88), Pair(46, 87), Pair(50, 86),
  Pair(52, 80)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-3, -32), Pair(10, -20), Pair(17, -7), Pair(22, 2), Pair(26, 11), Pair(29, 15), Pair(31, 18), Pair(32, 22),
  Pair(34, 22), Pair(39, 22), Pair(47, 19), Pair(51, 21), Pair(59, 26), Pair(64, 17)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-20, -55), Pair(-8, -33), Pair(-4, -22), Pair(-1, -11), Pair(1, -2), Pair(3, 3), Pair(6, 6), Pair(10, 8),
  Pair(13, 12), Pair(18, 13), Pair(24, 12), Pair(28, 14), Pair(33, 16), Pair(43, 9), Pair(92, -8)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(43, 10), Pair(51, -118), Pair(54, -97), Pair(56, -59), Pair(58, -33), Pair(60, -25), Pair(62, -11), Pair(63, 4),
  Pair(64, 8), Pair(67, 11), Pair(68, 16), Pair(70, 21), Pair(72, 20), Pair(73, 23), Pair(72, 26), Pair(75, 26),
  Pair(76, 23), Pair(80, 13), Pair(86, 6), Pair(95, -7), Pair(108, -23), Pair(145, -52), Pair(183, -80), Pair(173, -76),
  Pair(271, -146), Pair(404, -203), Pair(125, -90), Pair(146, -102)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-16, -92), Pair(-18, -77), Pair(-8, -49), Pair(13, -18), Pair(33, 32), Pair(69, 102), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(5, 3), Pair(12, 5), Pair(17, 20), Pair(39, 54), Pair(222, 86), Pair(107, 285), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(18, 10), Pair(13, 7), Pair(16, 16), Pair(39, 37), Pair(137, 32), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-28, -37), Pair(-8, -26), Pair(-10, -16), Pair(-11, -6), Pair(-16, 1), Pair(-18, -12), Pair(-13, -15), Pair(-31, -27)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(2, 4), Pair(-4, -11), Pair(-9, -6), Pair(-11, -12), Pair(-14, -14), Pair(-6, -7), Pair(-9, -6), Pair(7, -3)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(24, 1), Pair(15, 3), Pair(14, 7), Pair(18, 5), Pair(20, 9), Pair(24, 2), Pair(38, -2), Pair(53, -4)
  },
  {
      Pair(17, 26), Pair(12, 5), Pair(16, 1), Pair(17, -1), Pair(17, 0), Pair(17, -5), Pair(29, -7), Pair(25, 11)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -5), Pair(14, -8), Pair(11, -4),
  Pair(20, -8), Pair(16, -9), Pair(19, -8),
  Pair(26, -5), Pair(0, 0), Pair(26, -4),
  Pair(-6, 8), Pair(-17, 6), Pair(-14, 11)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, 2), Pair(-15, 10), Pair(-8, 6),
  Pair(-7, 1), Pair(-17, 10), Pair(-9, 4),
  Pair(0, -6), Pair(-9, 2), Pair(-2, -5),
  Pair(10, -8), Pair(-9, -2), Pair(9, -5),
  Pair(19, -12), Pair(21, -5), Pair(17, -10),
  Pair(0, 0), Pair(-69, 0), Pair(0, 0),
  Pair(8, -35), Pair(0, 0), Pair(13, -35)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(7, 56), Pair(-5, 49), Pair(-5, 34), Pair(1, 22), Pair(1, 21), Pair(15, 19), Pair(13, 17)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-9, -3), Pair(-6, 22), Pair(-1, 45), Pair(2, 59), Pair(4, 65), Pair(1, 68), Pair(-5, 71)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-412, 101);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-56, 3), Pair(-54, -8), Pair(-31, -12), Pair(-15, -12), Pair(-15, -9), Pair(-24, -7), Pair(-44, 1), Pair(-36, 1)
  },
  {
      Pair(-33, 40), Pair(-36, 22), Pair(-27, 14), Pair(-12, 4), Pair(-7, -3), Pair(-11, 9), Pair(-23, 21), Pair(-17, 27)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, 3), Pair(16, 0), Pair(56, -15), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, 1), Pair(20, 2), Pair(39, -3), Pair(-8, -1), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -11), Pair(19, -10), Pair(34, -7), Pair(45, -6), Pair(63, -13), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(1, 19), Pair(6, 35), Pair(19, 39), Pair(50, 31), Pair(90, 20), Pair(202, -34), Pair(340, -119)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(25, 1), Pair(11, 16), Pair(34, 2), Pair(15, 14), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-3, 14), Pair(0, 16)
  },
  {
      Pair(-56, -21), Pair(-49, -27)
  },
  {
      Pair(-42, -38), Pair(-43, -46)
  },
  {
      Pair(-60, -23), Pair(-49, -28)
  },
  {
      Pair(-42, 10), Pair(-39, -7)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(12, 25), Pair(17, 20), Pair(22, 11), Pair(18, -1), Pair(35, -2)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -22), Pair(7, -10)
  },
  {
      Pair(13, -66), Pair(12, -74)
  },
  {
      Pair(-36, -9), Pair(-29, -20)
  },
  {
      Pair(-53, -1), Pair(-46, -10)
  },
  {
      Pair(-30, -10), Pair(-26, -17)
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
      Pair(-38, -14), Pair(-19, -27)
  },
  {
      Pair(0, -57), Pair(6, -64)
  },
  {
      Pair(-51, -6), Pair(-43, -33)
  },
  {
      Pair(-41, -30), Pair(-35, -46)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-5, -25), Pair(9, -14)
  },
  {
      Pair(-34, -16), Pair(-5, -16)
  },
  {
      Pair(-31, -16), Pair(-10, -9)
  },
  {
      Pair(21, -49), Pair(20, -35)
  },
  {
      Pair(-55, 0), Pair(-36, -43)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(34, 12), Pair(7, 13), Pair(20, 11), Pair(23, 19), Pair(23, 21), Pair(3, 29), Pair(20, 30), Pair(39, -5),
  Pair(14, 16), Pair(11, 3), Pair(2, 21), Pair(0, 23), Pair(7, 26), Pair(-7, 18), Pair(9, 7), Pair(2, 15),
  Pair(3, 4), Pair(2, 13), Pair(-1, 8), Pair(6, 13), Pair(1, 13), Pair(-2, 11), Pair(-7, 15), Pair(3, -3)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-93, 25), Pair(15, 0), Pair(46, -7), Pair(29, -2), Pair(52, -9), Pair(-8, 13), Pair(27, 5), Pair(-41, 20),
  Pair(2, -16), Pair(12, 7), Pair(11, 6), Pair(8, 10), Pair(10, 6), Pair(5, 1), Pair(10, 14), Pair(0, 21),
  Pair(-23, 19), Pair(-5, 11), Pair(3, 16), Pair(16, 18), Pair(11, 20), Pair(1, 10), Pair(1, 14), Pair(-31, 2)
};

constexpr ScorePair kBishopPairBonus = Pair(19, 52);

constexpr ScorePair kTempoBonus = Pair(15, 5);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H