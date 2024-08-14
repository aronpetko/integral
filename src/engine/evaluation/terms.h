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
  Pair(83, 124), Pair(381, 197), Pair(399, 222), Pair(519, 506), Pair(1230, 972), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(161, 102), Pair(123, 118), Pair(121, 111), Pair(147, 92), Pair(150, 94), Pair(117, 117), Pair(60, 137), Pair(129, 100),
      Pair(14, 10), Pair(6, 14), Pair(19, -12), Pair(32, -30), Pair(33, -26), Pair(53, -23), Pair(5, 12), Pair(11, 5),
      Pair(-6, 0), Pair(1, -1), Pair(2, -22), Pair(10, -33), Pair(24, -33), Pair(23, -35), Pair(8, -10), Pair(-3, -10),
      Pair(-13, -12), Pair(-14, -2), Pair(-1, -23), Pair(11, -30), Pair(14, -33), Pair(17, -30), Pair(3, -14), Pair(-4, -20),
      Pair(-20, -15), Pair(-17, -8), Pair(-14, -19), Pair(-9, -23), Pair(-3, -23), Pair(-5, -24), Pair(7, -22), Pair(-6, -25),
      Pair(-15, -7), Pair(-6, -3), Pair(-10, -9), Pair(-12, -12), Pair(-5, -11), Pair(16, -19), Pair(18, -17), Pair(-4, -23),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-164, 19), Pair(-36, 37), Pair(-60, 39), Pair(25, 43), Pair(27, 45), Pair(-144, 59), Pair(-42, 54), Pair(-60, -4),
      Pair(-12, 44), Pair(-1, 67), Pair(23, 56), Pair(59, 54), Pair(64, 48), Pair(53, 41), Pair(-11, 56), Pair(-1, 39),
      Pair(9, 44), Pair(21, 56), Pair(24, 72), Pair(47, 66), Pair(62, 55), Pair(71, 60), Pair(24, 64), Pair(22, 32),
      Pair(21, 61), Pair(23, 73), Pair(39, 70), Pair(44, 83), Pair(38, 87), Pair(52, 73), Pair(28, 69), Pair(35, 56),
      Pair(9, 64), Pair(26, 65), Pair(31, 80), Pair(37, 80), Pair(37, 82), Pair(48, 72), Pair(37, 63), Pair(20, 65),
      Pair(-9, 47), Pair(11, 59), Pair(16, 61), Pair(29, 77), Pair(32, 73), Pair(25, 60), Pair(29, 52), Pair(6, 50),
      Pair(-12, 43), Pair(-1, 62), Pair(6, 54), Pair(15, 61), Pair(20, 57), Pair(17, 49), Pair(7, 58), Pair(1, 49),
      Pair(-59, 56), Pair(-14, 43), Pair(-13, 47), Pair(-2, 57), Pair(18, 52), Pair(2, 43), Pair(-10, 51), Pair(-31, 36)
  },
  {
      Pair(-33, 81), Pair(-27, 72), Pair(-65, 81), Pair(-75, 80), Pair(-29, 72), Pair(-125, 81), Pair(-53, 79), Pair(-36, 64),
      Pair(-11, 62), Pair(-13, 84), Pair(-3, 77), Pair(-6, 75), Pair(-14, 72), Pair(-5, 71), Pair(-29, 82), Pair(-4, 54),
      Pair(8, 70), Pair(13, 75), Pair(7, 82), Pair(25, 64), Pair(28, 70), Pair(35, 81), Pair(17, 86), Pair(22, 66),
      Pair(1, 64), Pair(12, 73), Pair(11, 74), Pair(24, 80), Pair(17, 83), Pair(32, 74), Pair(9, 74), Pair(11, 64),
      Pair(16, 54), Pair(0, 68), Pair(16, 73), Pair(14, 75), Pair(22, 72), Pair(14, 68), Pair(12, 67), Pair(13, 52),
      Pair(6, 62), Pair(24, 70), Pair(17, 76), Pair(17, 79), Pair(14, 81), Pair(26, 70), Pair(24, 63), Pair(17, 60),
      Pair(22, 54), Pair(18, 54), Pair(22, 50), Pair(9, 68), Pair(20, 64), Pair(25, 54), Pair(32, 53), Pair(23, 34),
      Pair(9, 42), Pair(17, 69), Pair(4, 65), Pair(3, 64), Pair(16, 57), Pair(0, 68), Pair(10, 37), Pair(16, 43)
  },
  {
      Pair(60, 46), Pair(51, 62), Pair(32, 74), Pair(46, 67), Pair(42, 67), Pair(49, 66), Pair(64, 59), Pair(39, 56),
      Pair(19, 61), Pair(25, 64), Pair(40, 59), Pair(64, 52), Pair(44, 53), Pair(51, 54), Pair(11, 65), Pair(5, 59),
      Pair(17, 60), Pair(49, 49), Pair(36, 55), Pair(59, 38), Pair(70, 37), Pair(65, 44), Pair(54, 43), Pair(8, 53),
      Pair(10, 56), Pair(29, 57), Pair(34, 55), Pair(41, 41), Pair(40, 41), Pair(40, 47), Pair(26, 52), Pair(14, 49),
      Pair(-10, 57), Pair(6, 57), Pair(10, 56), Pair(9, 54), Pair(13, 48), Pair(3, 56), Pair(2, 52), Pair(-6, 51),
      Pair(-5, 38), Pair(7, 42), Pair(-6, 51), Pair(5, 43), Pair(6, 36), Pair(0, 45), Pair(15, 28), Pair(2, 29),
      Pair(-17, 33), Pair(0, 36), Pair(4, 36), Pair(7, 38), Pair(14, 26), Pair(10, 34), Pair(7, 21), Pair(-23, 26),
      Pair(1, 34), Pair(7, 33), Pair(7, 39), Pair(19, 28), Pair(21, 20), Pair(17, 32), Pair(0, 34), Pair(6, 23)
  },
  {
      Pair(-18, 33), Pair(20, 20), Pair(17, 38), Pair(26, 26), Pair(49, 16), Pair(74, 4), Pair(30, 18), Pair(6, 45),
      Pair(-12, 34), Pair(-30, 69), Pair(-6, 64), Pair(-17, 91), Pair(-31, 84), Pair(14, 57), Pair(11, 59), Pair(26, 25),
      Pair(-3, 8), Pair(5, 31), Pair(2, 62), Pair(3, 64), Pair(5, 96), Pair(18, 71), Pair(30, 38), Pair(22, 7),
      Pair(9, -3), Pair(-1, 45), Pair(2, 56), Pair(-1, 78), Pair(6, 67), Pair(22, 49), Pair(8, 47), Pair(27, -4),
      Pair(2, 2), Pair(-10, 37), Pair(-2, 42), Pair(-7, 71), Pair(7, 49), Pair(3, 38), Pair(12, 27), Pair(6, 8),
      Pair(4, -14), Pair(7, -1), Pair(4, 14), Pair(6, 13), Pair(3, 30), Pair(13, 11), Pair(18, 0), Pair(9, -10),
      Pair(10, -49), Pair(11, -48), Pair(15, -38), Pair(13, -15), Pair(14, -14), Pair(23, -54), Pair(27, -73), Pair(9, -38),
      Pair(12, -56), Pair(3, -54), Pair(4, -44), Pair(6, -41), Pair(9, -50), Pair(1, -71), Pair(2, -79), Pair(22, -46)
  },
  {
      Pair(11, -174), Pair(147, 12), Pair(206, 18), Pair(109, 19), Pair(82, 4), Pair(83, 2), Pair(196, -31), Pair(137, -204),
      Pair(96, 3), Pair(169, 62), Pair(107, 66), Pair(120, 44), Pair(103, 43), Pair(32, 115), Pair(97, 72), Pair(45, -29),
      Pair(-31, 55), Pair(74, 74), Pair(30, 94), Pair(-49, 102), Pair(-56, 116), Pair(82, 84), Pair(102, 68), Pair(61, 24),
      Pair(-28, 38), Pair(116, 43), Pair(-28, 83), Pair(-81, 103), Pair(-91, 98), Pair(4, 74), Pair(54, 45), Pair(-35, 21),
      Pair(-35, 28), Pair(32, 41), Pair(1, 68), Pair(-50, 90), Pair(-35, 81), Pair(-32, 70), Pair(33, 39), Pair(-38, 23),
      Pair(-7, 30), Pair(41, 40), Pair(-14, 66), Pair(-29, 80), Pair(-27, 79), Pair(-7, 64), Pair(14, 47), Pair(-22, 34),
      Pair(60, 3), Pair(29, 41), Pair(16, 55), Pair(-9, 68), Pair(-11, 66), Pair(6, 57), Pair(27, 40), Pair(47, 6),
      Pair(37, -13), Pair(63, 15), Pair(53, 28), Pair(-10, 47), Pair(30, 19), Pair(5, 38), Pair(58, 16), Pair(61, -23)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-30, -8), Pair(-10, 23), Pair(-1, 47), Pair(5, 58), Pair(10, 64), Pair(14, 74), Pair(17, 74), Pair(21, 73),
  Pair(20, 69)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-23, -15), Pair(-9, 8), Pair(0, 17), Pair(5, 28), Pair(10, 38), Pair(13, 46), Pair(16, 48), Pair(17, 52),
  Pair(17, 57), Pair(21, 55), Pair(27, 51), Pair(31, 56), Pair(37, 50), Pair(45, 50)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-30, -36), Pair(-15, -8), Pair(-10, 0), Pair(-5, 14), Pair(-3, 22), Pair(0, 25), Pair(3, 29), Pair(8, 32),
  Pair(12, 36), Pair(18, 39), Pair(25, 37), Pair(27, 40), Pair(30, 44), Pair(37, 41), Pair(78, 19)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-12, -235), Pair(-6, -175), Pair(-5, -64), Pair(-1, -62), Pair(0, -23), Pair(2, -13), Pair(4, 3), Pair(5, 12),
  Pair(7, 29), Pair(9, 35), Pair(11, 41), Pair(13, 44), Pair(15, 46), Pair(15, 50), Pair(15, 57), Pair(19, 51),
  Pair(23, 44), Pair(29, 36), Pair(29, 34), Pair(47, 9), Pair(65, -10), Pair(81, -39), Pair(90, -53), Pair(126, -88),
  Pair(180, -127), Pair(231, -178), Pair(126, -104), Pair(127, -151)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-6, -79), Pair(-7, -64), Pair(0, -33), Pair(21, 3), Pair(29, 60), Pair(-42, -1), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 3), Pair(14, 5), Pair(15, 21), Pair(37, 67), Pair(173, 129), Pair(369, 393), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(19, 11), Pair(13, 8), Pair(15, 19), Pair(39, 43), Pair(220, 3), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-26, -39), Pair(-1, -28), Pair(-12, -16), Pair(-14, -7), Pair(-9, -4), Pair(-13, -10), Pair(1, -19), Pair(-16, -40)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(3, 3), Pair(-6, -11), Pair(-9, -8), Pair(-11, -12), Pair(-14, -13), Pair(-6, -11), Pair(-6, -11), Pair(-2, 0)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(26, 0), Pair(19, 3), Pair(19, 6), Pair(18, 5), Pair(29, 4), Pair(31, -2), Pair(45, -7), Pair(53, -5)
  },
  {
      Pair(19, 27), Pair(13, 8), Pair(18, 1), Pair(19, -1), Pair(19, -1), Pair(19, -7), Pair(28, -1), Pair(23, 17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -1), Pair(11, -5), Pair(10, -3),
  Pair(19, -6), Pair(13, -5), Pair(19, -5),
  Pair(26, -1), Pair(0, 0), Pair(25, -1),
  Pair(-4, 10), Pair(-33, 17), Pair(-1, 9)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 3), Pair(-16, 11), Pair(-7, 5),
  Pair(-8, 3), Pair(-19, 11), Pair(-8, 3),
  Pair(0, -6), Pair(-13, 5), Pair(-1, -5),
  Pair(9, -4), Pair(-13, 2), Pair(12, -6),
  Pair(23, -13), Pair(27, -8), Pair(22, -14),
  Pair(0, 0), Pair(-46, -7), Pair(0, 0),
  Pair(48, -60), Pair(0, 0), Pair(62, -62)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(0, 46), Pair(-18, 42), Pair(-16, 24), Pair(-12, 13), Pair(-1, 9), Pair(8, 9), Pair(1, 5)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-30, -9), Pair(1, 12), Pair(2, 43), Pair(9, 52), Pair(6, 60), Pair(2, 65), Pair(-4, 59)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-7, 162);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-59, 9), Pair(-79, 6), Pair(-32, -11), Pair(-19, -17), Pair(-15, -14), Pair(-30, -9), Pair(-50, 0), Pair(-52, 7)
  },
  {
      Pair(-33, 54), Pair(-54, 34), Pair(-23, 15), Pair(-14, 2), Pair(-11, 3), Pair(-19, 14), Pair(-28, 27), Pair(-34, 52)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 0), Pair(20, -5), Pair(61, -25), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 2), Pair(21, 2), Pair(37, 0), Pair(4, -10), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(17, -20), Pair(28, -20), Pair(42, -13), Pair(68, -13), Pair(51, -13), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 24), Pair(9, 36), Pair(22, 48), Pair(62, 23), Pair(100, 17), Pair(185, -24), Pair(262, -96)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(27, 3), Pair(13, 21), Pair(45, -1), Pair(18, 19), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-5, 34), Pair(2, 31)
  },
  {
      Pair(-63, -24), Pair(-55, -30)
  },
  {
      Pair(-46, -58), Pair(-48, -65)
  },
  {
      Pair(-75, -29), Pair(-52, -43)
  },
  {
      Pair(-46, -4), Pair(-44, -10)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 28), Pair(21, 25), Pair(22, 12), Pair(20, 2), Pair(41, -3)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-5, -24), Pair(7, -11)
  },
  {
      Pair(0, 64), Pair(1, 53)
  },
  {
      Pair(-41, -13), Pair(-30, -29)
  },
  {
      Pair(-64, -6), Pair(-54, -10)
  },
  {
      Pair(-40, -3), Pair(-31, -32)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-15, -20), Pair(0, -6)
  },
  {
      Pair(-48, -14), Pair(-19, -30)
  },
  {
      Pair(-4, 1), Pair(3, -7)
  },
  {
      Pair(-52, -18), Pair(-51, -36)
  },
  {
      Pair(-47, -44), Pair(-40, -63)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-9, -28), Pair(10, -14)
  },
  {
      Pair(-43, -19), Pair(-6, -18)
  },
  {
      Pair(-34, -26), Pair(-13, -12)
  },
  {
      Pair(8, -37), Pair(9, -14)
  },
  {
      Pair(-59, -27), Pair(-46, -65)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(1, 12), Pair(5, 16), Pair(41, 17), Pair(25, 26), Pair(28, 36), Pair(-2, 37), Pair(18, 30), Pair(-6, 50),
  Pair(-5, 18), Pair(11, 2), Pair(7, 23), Pair(2, 21), Pair(4, 24), Pair(-3, 25), Pair(11, 11), Pair(2, 18),
  Pair(5, 5), Pair(-8, 12), Pair(2, 11), Pair(8, 10), Pair(2, 15), Pair(-4, 12), Pair(-10, 17), Pair(8, -3)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-55, 41), Pair(15, 14), Pair(25, 6), Pair(32, 8), Pair(54, 1), Pair(47, 7), Pair(51, -16), Pair(-14, 16),
  Pair(-16, 37), Pair(10, 17), Pair(19, 9), Pair(19, 10), Pair(13, 16), Pair(6, 4), Pair(13, 12), Pair(-8, -7),
  Pair(6, 3), Pair(7, 16), Pair(0, 23), Pair(19, 15), Pair(13, 25), Pair(-2, 21), Pair(8, 12), Pair(-26, 23)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 53);

constexpr ScorePair kTempoBonus = Pair(16, 9);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H