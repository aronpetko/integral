#ifndef INTEGRAL_TERMS_H
#define INTEGRAL_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
constexpr int kNumKingBuckets = 7;

template <typename T>
using KingBuckets = std::array<T, kNumKingBuckets>;

constexpr SquareTable<int> kKingBucketLayout = {
  6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6,
  5, 5, 5, 5, 5, 5, 5, 5,
  5, 5, 5, 5, 5, 5, 5, 5,
  4, 4, 4, 4, 4, 4, 4, 4,
  3, 3, 3, 3, 3, 3, 3, 3,
  2, 2, 2, 2, 2, 2, 2, 2,
  0, 0, 1, 1, 1, 1, 0, 0
};

template <typename T>
using PieceTable = std::array<T, kNumPieceTypes>;

template <typename T>
using PieceSquareTable = PieceTable<SquareTable<T>>;

// [is_our_piece][pawn_position][piece][piece_position]
template <typename T>
using PawnRelativePSQT = SideTable<SquareTable<PieceTable<SquareTable<T>>>>;

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
  Pair(104, 73), Pair(368, 243), Pair(410, 279), Pair(554, 507), Pair(1091, 898), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(75, 34), Pair(-5, 84), Pair(-1, 55), Pair(64, 36), Pair(48, 27), Pair(5, 62), Pair(-45, 81), Pair(38, 38),
      Pair(-6, 34), Pair(5, 39), Pair(-10, 25), Pair(16, 13), Pair(11, 17), Pair(26, 19), Pair(-7, 39), Pair(10, 21),
      Pair(-16, 27), Pair(4, 21), Pair(-13, 11), Pair(3, 7), Pair(10, 8), Pair(10, 3), Pair(-2, 22), Pair(-8, 10),
      Pair(-26, 18), Pair(-10, 20), Pair(-12, 6), Pair(-2, 5), Pair(0, 2), Pair(1, 7), Pair(-8, 18), Pair(-15, 7),
      Pair(-30, 16), Pair(-10, 12), Pair(-22, 10), Pair(-18, 11), Pair(-14, 10), Pair(-12, 11), Pair(7, 8), Pair(-10, 3),
      Pair(-32, 27), Pair(1, 16), Pair(-20, 20), Pair(-20, 22), Pair(-17, 18), Pair(8, 17), Pair(15, 13), Pair(-11, 8),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-119, -157), Pair(-49, 17), Pair(-73, 23), Pair(22, 7), Pair(19, 7), Pair(-111, 29), Pair(-82, 14), Pair(-90, -122),
      Pair(-39, 13), Pair(2, 5), Pair(11, 17), Pair(93, 1), Pair(59, 9), Pair(59, -2), Pair(-10, 19), Pair(-21, 7),
      Pair(-11, 11), Pair(17, 15), Pair(41, 24), Pair(55, 22), Pair(75, 10), Pair(66, 12), Pair(19, 22), Pair(9, 7),
      Pair(8, 1), Pair(21, 24), Pair(44, 26), Pair(51, 31), Pair(42, 35), Pair(50, 27), Pair(29, 30), Pair(36, 17),
      Pair(8, 8), Pair(13, 24), Pair(36, 30), Pair(38, 34), Pair(39, 35), Pair(50, 26), Pair(42, 18), Pair(22, 18),
      Pair(-6, -12), Pair(17, 7), Pair(18, 20), Pair(35, 31), Pair(34, 29), Pair(28, 20), Pair(33, 11), Pair(2, -6),
      Pair(-16, -4), Pair(0, 17), Pair(12, -3), Pair(16, 13), Pair(22, 10), Pair(24, -7), Pair(14, 5), Pair(-3, -4),
      Pair(-42, -23), Pair(-11, -8), Pair(0, -17), Pair(2, -3), Pair(18, 1), Pair(5, -4), Pair(-9, -6), Pair(-23, -43)
  },
  {
      Pair(-23, -14), Pair(-47, 23), Pair(-71, 34), Pair(-136, 40), Pair(-129, 51), Pair(-176, 51), Pair(-66, 36), Pair(-46, -1),
      Pair(-29, 5), Pair(-17, 22), Pair(-17, 24), Pair(-36, 48), Pair(-25, 30), Pair(-15, 35), Pair(-28, 21), Pair(-17, 8),
      Pair(-8, 4), Pair(12, 15), Pair(2, 32), Pair(29, 18), Pair(30, 22), Pair(47, 19), Pair(13, 24), Pair(19, -9),
      Pair(-5, -5), Pair(5, 18), Pair(17, 8), Pair(31, 17), Pair(19, 15), Pair(33, 11), Pair(11, 9), Pair(5, -3),
      Pair(12, 1), Pair(-3, 2), Pair(16, 9), Pair(12, 7), Pair(20, 11), Pair(11, 17), Pair(14, 9), Pair(21, -14),
      Pair(4, 0), Pair(26, 6), Pair(19, 4), Pair(16, 14), Pair(9, 17), Pair(22, 8), Pair(27, 6), Pair(7, 5),
      Pair(42, -4), Pair(22, -13), Pair(25, -3), Pair(6, -2), Pair(20, -6), Pair(21, -9), Pair(32, -11), Pair(19, -16),
      Pair(16, -21), Pair(36, -22), Pair(-4, 0), Pair(0, -3), Pair(13, -17), Pair(-8, 2), Pair(14, -10), Pair(9, -11)
  },
  {
      Pair(17, 18), Pair(20, 32), Pair(19, 33), Pair(27, 21), Pair(27, 17), Pair(11, 31), Pair(0, 36), Pair(30, 21),
      Pair(-5, 29), Pair(3, 36), Pair(31, 29), Pair(58, 16), Pair(63, 6), Pair(47, 14), Pair(-13, 40), Pair(15, 20),
      Pair(19, 18), Pair(30, 20), Pair(33, 20), Pair(54, 4), Pair(63, -1), Pair(69, 3), Pair(29, 24), Pair(12, 18),
      Pair(0, 17), Pair(12, 25), Pair(30, 24), Pair(44, 7), Pair(43, 6), Pair(39, 16), Pair(15, 25), Pair(-3, 14),
      Pair(-16, 12), Pair(-3, 16), Pair(-1, 24), Pair(3, 18), Pair(7, 11), Pair(1, 17), Pair(-6, 23), Pair(-16, 11),
      Pair(-16, 2), Pair(-14, 9), Pair(-8, 8), Pair(1, 5), Pair(1, 4), Pair(-10, 10), Pair(-9, 7), Pair(-17, -3),
      Pair(-25, -8), Pair(-5, -2), Pair(-1, 3), Pair(8, -5), Pair(4, -12), Pair(-2, -6), Pair(-10, -4), Pair(-40, -9),
      Pair(-6, -9), Pair(-2, -7), Pair(-1, -2), Pair(16, -13), Pair(19, -25), Pair(10, -17), Pair(-20, 2), Pair(-7, -23)
  },
  {
      Pair(10, 18), Pair(12, 37), Pair(43, 27), Pair(43, 27), Pair(69, 10), Pair(106, 8), Pair(30, 42), Pair(21, 61),
      Pair(-16, 55), Pair(-9, 64), Pair(5, 84), Pair(16, 80), Pair(-16, 102), Pair(27, 74), Pair(13, 101), Pair(30, 56),
      Pair(0, 34), Pair(19, 48), Pair(13, 76), Pair(24, 96), Pair(29, 79), Pair(34, 88), Pair(23, 83), Pair(24, 34),
      Pair(16, 31), Pair(11, 58), Pair(14, 71), Pair(7, 97), Pair(16, 94), Pair(30, 72), Pair(18, 75), Pair(23, 44),
      Pair(12, 21), Pair(2, 65), Pair(17, 52), Pair(-3, 103), Pair(16, 63), Pair(16, 54), Pair(29, 25), Pair(18, 18),
      Pair(8, 22), Pair(17, 16), Pair(11, 41), Pair(16, 34), Pair(9, 53), Pair(21, 35), Pair(33, 10), Pair(22, -16),
      Pair(26, -17), Pair(16, 5), Pair(23, -12), Pair(22, 2), Pair(24, 3), Pair(29, -24), Pair(34, -42), Pair(37, -43),
      Pair(21, -14), Pair(10, -25), Pair(10, -20), Pair(12, -8), Pair(20, -32), Pair(5, -45), Pair(12, -55), Pair(17, -36)
  },
  {
      Pair(131, -106), Pair(131, -11), Pair(183, -34), Pair(78, -22), Pair(81, -33), Pair(16, -4), Pair(28, 26), Pair(96, -122),
      Pair(22, -13), Pair(93, 14), Pair(108, 11), Pair(113, 2), Pair(89, -8), Pair(79, 12), Pair(67, 23), Pair(11, -8),
      Pair(31, -22), Pair(105, 10), Pair(126, -6), Pair(80, 14), Pair(117, 0), Pair(116, -3), Pair(123, -6), Pair(50, -18),
      Pair(35, -31), Pair(113, -26), Pair(12, 17), Pair(16, 29), Pair(54, 14), Pair(82, -5), Pair(81, -9), Pair(3, -34),
      Pair(6, -39), Pair(36, -11), Pair(13, 4), Pair(-84, 44), Pair(-44, 25), Pair(-25, 10), Pair(14, -11), Pair(-40, -34),
      Pair(-23, -26), Pair(-13, -9), Pair(-41, 10), Pair(-57, 34), Pair(-57, 23), Pair(-45, 13), Pair(-21, -4), Pair(-42, -28),
      Pair(18, -27), Pair(-4, -5), Pair(-37, 11), Pair(-66, 29), Pair(-64, 21), Pair(-50, 13), Pair(-20, -2), Pair(-2, -31),
      Pair(10, -57), Pair(27, -30), Pair(6, -14), Pair(-69, 5), Pair(-20, -22), Pair(-53, -3), Pair(7, -21), Pair(10, -61)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(0, -1), Pair(13, -1), Pair(22, 16), Pair(27, 25), Pair(31, 32), Pair(34, 37), Pair(38, 34), Pair(43, 29),
  Pair(43, 22)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-13, -23), Pair(0, -26), Pair(7, -11), Pair(11, 2), Pair(15, 9), Pair(17, 14), Pair(21, 16), Pair(22, 18),
  Pair(24, 20), Pair(25, 20), Pair(36, 8), Pair(49, 10), Pair(64, 8), Pair(119, 4)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-27, -89), Pair(-15, -48), Pair(-12, -36), Pair(-5, -18), Pair(-3, -12), Pair(0, -3), Pair(4, 2), Pair(9, 1),
  Pair(11, 8), Pair(18, 8), Pair(25, 9), Pair(30, 9), Pair(43, 2), Pair(53, -5), Pair(67, -10)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-13, -45), Pair(-6, -84), Pair(-2, -35), Pair(3, -40), Pair(4, -4), Pair(4, 13), Pair(8, 24), Pair(9, 34),
  Pair(11, 45), Pair(13, 46), Pair(14, 54), Pair(17, 58), Pair(18, 60), Pair(21, 55), Pair(18, 61), Pair(19, 59),
  Pair(28, 44), Pair(32, 29), Pair(37, 17), Pair(48, -1), Pair(63, -23), Pair(101, -66), Pair(97, -68), Pair(122, -112),
  Pair(108, -117), Pair(171, -176), Pair(78, -141), Pair(54, -71)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-15, -50), Pair(-18, -41), Pair(-3, -16), Pair(23, 5), Pair(49, 40), Pair(70, 57), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(5, 10), Pair(11, 8), Pair(18, 18), Pair(25, 59), Pair(188, 82), Pair(22, 510), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(18, 12), Pair(13, 6), Pair(18, 11), Pair(42, 28), Pair(244, 10), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-44, -33), Pair(-15, -18), Pair(-14, -7), Pair(-22, 0), Pair(-14, -8), Pair(-20, -5), Pair(-4, -18), Pair(-37, -26)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(15, -9), Pair(-8, -7), Pair(-5, -5), Pair(-14, -12), Pair(-13, -9), Pair(-6, -10), Pair(-8, -5), Pair(-1, 0)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(29, -7), Pair(22, -7), Pair(25, -5), Pair(15, -1), Pair(24, 4), Pair(33, 1), Pair(48, -16), Pair(43, -4)
  },
  {
      Pair(16, 21), Pair(17, 4), Pair(23, -4), Pair(18, -2), Pair(23, -3), Pair(16, -1), Pair(39, -13), Pair(25, 9)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(10, -3), Pair(11, -9), Pair(10, -5),
  Pair(17, -9), Pair(15, -9), Pair(17, -7),
  Pair(20, -1), Pair(0, 0), Pair(20, 0),
  Pair(10, 2), Pair(-16, 5), Pair(-3, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 0), Pair(-16, 5), Pair(-6, 2),
  Pair(-8, -1), Pair(-19, 8), Pair(-7, 1),
  Pair(2, -9), Pair(-8, -4), Pair(2, -9),
  Pair(11, -11), Pair(-10, -7), Pair(9, -7),
  Pair(24, -20), Pair(20, -6), Pair(25, -21),
  Pair(0, 0), Pair(-49, -15), Pair(0, 0),
  Pair(35, -36), Pair(0, 0), Pair(20, -35)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(10, 40), Pair(-5, 36), Pair(-9, 20), Pair(-10, 14), Pair(-12, 16), Pair(6, 14), Pair(-5, 10)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-6, -26), Pair(-5, 13), Pair(-9, 38), Pair(-3, 47), Pair(2, 55), Pair(-3, 57), Pair(-19, 66)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-372, 90);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-62, 5), Pair(-53, 3), Pair(-24, -9), Pair(0, -25), Pair(-13, -11), Pair(-14, -8), Pair(-39, -2), Pair(-48, 2)
  },
  {
      Pair(-69, 66), Pair(-46, 27), Pair(-18, 11), Pair(-11, -12), Pair(-12, -1), Pair(-15, 10), Pair(-23, 19), Pair(-15, 34)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 3), Pair(18, -1), Pair(60, -16), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, 1), Pair(18, 5), Pair(34, -1), Pair(5, 2), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(14, -17), Pair(23, -13), Pair(35, -4), Pair(54, -3), Pair(36, 2), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(1, 23), Pair(9, 30), Pair(25, 37), Pair(68, 6), Pair(103, 9), Pair(231, -60), Pair(264, -92)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(24, 4), Pair(8, 17), Pair(51, -11), Pair(15, 16), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-11, 24), Pair(-2, 25)
  },
  {
      Pair(-63, -27), Pair(-58, -24)
  },
  {
      Pair(-49, -44), Pair(-47, -56)
  },
  {
      Pair(-82, -23), Pair(-41, -37)
  },
  {
      Pair(-46, -3), Pair(-40, -3)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(14, 32), Pair(18, 27), Pair(25, 18), Pair(19, -4), Pair(29, 9)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-7, -22), Pair(6, -8)
  },
  {
      Pair(-16, -25), Pair(-16, -27)
  },
  {
      Pair(-44, -1), Pair(-34, -19)
  },
  {
      Pair(-65, 9), Pair(-59, 4)
  },
  {
      Pair(-39, -16), Pair(-38, 8)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-17, -25), Pair(-1, -4)
  },
  {
      Pair(-49, -5), Pair(-17, -33)
  },
  {
      Pair(2, -41), Pair(8, -52)
  },
  {
      Pair(-47, -10), Pair(-50, -32)
  },
  {
      Pair(-38, -57), Pair(-35, -69)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-11, -19), Pair(10, -12)
  },
  {
      Pair(-32, -17), Pair(-5, -20)
  },
  {
      Pair(-36, -6), Pair(-13, -8)
  },
  {
      Pair(-12, -72), Pair(5, -61)
  },
  {
      Pair(-68, -6), Pair(-48, -38)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(17, 19), Pair(0, 36), Pair(21, 15), Pair(3, 29), Pair(6, 31), Pair(10, 41), Pair(33, 17), Pair(76, -5),
  Pair(17, 20), Pair(9, 11), Pair(10, 17), Pair(-1, 33), Pair(7, 32), Pair(5, 38), Pair(14, 12), Pair(-4, 13),
  Pair(9, 2), Pair(0, 11), Pair(1, 15), Pair(10, 19), Pair(3, 30), Pair(-2, 25), Pair(-6, 20), Pair(10, -2)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-45, 22), Pair(-3, 26), Pair(26, -7), Pair(23, -8), Pair(52, -16), Pair(30, 2), Pair(39, 11), Pair(-58, 9),
  Pair(5, 17), Pair(13, 21), Pair(-6, 16), Pair(12, 5), Pair(11, 25), Pair(3, 13), Pair(17, 17), Pair(-4, 20),
  Pair(8, -18), Pair(11, 19), Pair(2, 23), Pair(11, 28), Pair(12, 24), Pair(-2, 13), Pair(14, -1), Pair(-23, -10)
};

constexpr ScorePair kBishopPairBonus = Pair(19, 40);

constexpr ScorePair kTempoBonus = Pair(18, 4);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H