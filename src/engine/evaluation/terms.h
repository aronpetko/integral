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
using PieceSquareTable = KingBuckets<KingBuckets<PieceTable<SquareTable<T>>>>;

// [is_our_piece][pawn_position][piece_position]
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
  Pair(76, 128), Pair(333, 354), Pair(366, 432), Pair(472, 814), Pair(1058, 1351), Pair(0, 0)
};

constexpr PawnRelativePSQT<ScorePair> kPieceSquareTable = {};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-3, 98), Pair(13, 65), Pair(18, 93), Pair(21, 106), Pair(24, 114), Pair(27, 123), Pair(31, 123), Pair(38, 116),
  Pair(42, 104)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-24, 43), Pair(-15, -4), Pair(-8, 20), Pair(-4, 38), Pair(1, 55), Pair(4, 68), Pair(5, 78), Pair(6, 83),
  Pair(10, 89), Pair(14, 90), Pair(23, 87), Pair(33, 83), Pair(64, 91), Pair(84, 68)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-40, -32), Pair(-31, -17), Pair(-28, 2), Pair(-27, 24), Pair(-25, 33), Pair(-19, 37), Pair(-14, 43), Pair(-7, 45),
  Pair(-3, 48), Pair(3, 53), Pair(7, 57), Pair(12, 59), Pair(18, 58), Pair(43, 46), Pair(85, 23)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-25, 202), Pair(-31, 162), Pair(-7, 114), Pair(-2, 102), Pair(0, 114), Pair(0, 136), Pair(2, 150), Pair(3, 171),
  Pair(5, 184), Pair(9, 186), Pair(10, 196), Pair(12, 199), Pair(13, 200), Pair(16, 202), Pair(14, 205), Pair(13, 205),
  Pair(14, 202), Pair(15, 198), Pair(19, 188), Pair(30, 176), Pair(39, 162), Pair(48, 143), Pair(46, 137), Pair(26, 143),
  Pair(26, 133), Pair(113, 75), Pair(159, 85), Pair(165, 65)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-34, -102), Pair(-33, -90), Pair(-18, -57), Pair(19, -22), Pair(38, 47), Pair(172, 134), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 0), Pair(17, 6), Pair(15, 20), Pair(46, 83), Pair(121, 156), Pair(12, 293), Pair(0, 0)};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(22, 10), Pair(13, 6), Pair(18, 13), Pair(46, 52), Pair(209, 36), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-26, -56), Pair(-9, -32), Pair(-7, -23), Pair(-9, -20), Pair(-18, -11), Pair(-15, -13), Pair(-3, -23), Pair(-35, -43)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(3, 2), Pair(-5, -11), Pair(-10, -11), Pair(-9, -18), Pair(-11, -19), Pair(-7, -12), Pair(-7, -9), Pair(11, -4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(21, 10), Pair(23, 8), Pair(23, 13), Pair(25, 10), Pair(28, 12), Pair(43, 8), Pair(51, 1), Pair(58, -1)
  },
  {
      Pair(10, 28), Pair(14, 13), Pair(16, 8), Pair(17, 8), Pair(14, 5), Pair(22, 0), Pair(27, -1), Pair(21, 12)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(14, -2), Pair(30, -8), Pair(20, -2),
  Pair(33, -12), Pair(34, -15), Pair(33, -13),
  Pair(51, -9), Pair(0, 0), Pair(45, -7),
  Pair(15, 4), Pair(7, 0), Pair(11, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-9, 8), Pair(-17, 14), Pair(-10, 8),
  Pair(-13, 5), Pair(-24, 10), Pair(-14, 5),
  Pair(-7, -1), Pair(-15, 5), Pair(-3, -2),
  Pair(8, -2), Pair(-6, 2), Pair(12, -3),
  Pair(42, -18), Pair(45, -8), Pair(41, -19),
  Pair(-22, 1), Pair(-38, -13), Pair(-14, -17),
  Pair(58, -54), Pair(0, 0), Pair(49, -52)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-1, 88), Pair(1, 75), Pair(2, 62), Pair(7, 51), Pair(8, 45), Pair(16, 39), Pair(5, 29)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-13, -30), Pair(-21, 17), Pair(-8, 39), Pair(1, 52), Pair(10, 59), Pair(12, 65), Pair(5, 69)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-644, 109);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-41, -28), Pair(-73, -8), Pair(-6, -23), Pair(-1, -25), Pair(-12, -18), Pair(-5, -18), Pair(-46, -4), Pair(-14, -10)
  },
  {
      Pair(-48, 58), Pair(-43, 22), Pair(-6, 2), Pair(-2, -8), Pair(-1, -5), Pair(5, -3), Pair(-30, 16), Pair(-25, 32)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 4), Pair(28, 1), Pair(71, -10), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 4), Pair(25, 6), Pair(68, -2), Pair(75, -19), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(25, -16), Pair(41, -15), Pair(66, -13), Pair(100, -15), Pair(159, -32), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(6, 21), Pair(17, 48), Pair(37, 63), Pair(97, 54), Pair(143, 62), Pair(243, 27), Pair(352, -32)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(29, 4), Pair(8, 10), Pair(29, -2), Pair(16, 21), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-2, 14), Pair(0, 28)
  },
  {
      Pair(-74, -53), Pair(-50, -68)
  },
  {
      Pair(-63, -71), Pair(-47, -93)
  },
  {
      Pair(-62, -17), Pair(-54, -34)
  },
  {
      Pair(-49, -15), Pair(-42, -25)
  },
  {
      Pair(21, 3), Pair(16, 10)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(16, 43), Pair(14, 39), Pair(24, 30), Pair(14, 22), Pair(23, 5)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-1, -22), Pair(6, -7)
  },
  {
      Pair(-18, 0), Pair(-2, -6)
  },
  {
      Pair(-29, -34), Pair(-20, -47)
  },
  {
      Pair(-56, -14), Pair(-39, -31)
  },
  {
      Pair(-36, -39), Pair(-29, -35)
  },
  {
      Pair(-47, -21), Pair(-15, -49)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-12, -17), Pair(0, -4)
  },
  {
      Pair(-44, -31), Pair(-23, -48)
  },
  {
      Pair(-13, -25), Pair(-10, -40)
  },
  {
      Pair(-51, -17), Pair(-36, -34)
  },
  {
      Pair(-44, -20), Pair(-33, -35)
  },
  {
      Pair(-4, -24), Pair(-5, -19)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(3, -24), Pair(11, -6)
  },
  {
      Pair(-30, -28), Pair(0, -14)
  },
  {
      Pair(-25, -22), Pair(-5, -8)
  },
  {
      Pair(6, -18), Pair(7, -15)
  },
  {
      Pair(-43, -18), Pair(-31, -21)
  },
  {
      Pair(2, -29), Pair(-9, -34)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-2, 38), Pair(18, 48), Pair(39, 24), Pair(39, 27), Pair(36, 36), Pair(41, 32), Pair(4, 61), Pair(21, 27),
  Pair(15, 25), Pair(11, 26), Pair(15, 33), Pair(12, 39), Pair(4, 37), Pair(-3, 39), Pair(1, 26), Pair(2, 22),
  Pair(5, 11), Pair(6, 23), Pair(-1, 30), Pair(10, 23), Pair(2, 30), Pair(-7, 24), Pair(-12, 19), Pair(-1, 5)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-2, 2), Pair(29, 11), Pair(27, -6), Pair(46, -3), Pair(46, -6), Pair(83, -10), Pair(34, 13), Pair(10, -1),
  Pair(13, -14), Pair(18, 16), Pair(24, 2), Pair(38, 8), Pair(17, 8), Pair(38, 3), Pair(10, 20), Pair(1, 12),
  Pair(-21, 6), Pair(16, 16), Pair(7, 18), Pair(17, 13), Pair(16, 18), Pair(-2, 13), Pair(-3, 18), Pair(-14, -10)
};

constexpr ScorePair kBishopPairBonus = Pair(18, 72);

constexpr ScorePair kTempoBonus = Pair(18, 19);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H