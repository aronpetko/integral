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
  Pair(96, 133), Pair(347, 296), Pair(379, 327), Pair(514, 545), Pair(1156, 878), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
    Pair(83, 34), Pair(29, 54), Pair(55, 34), Pair(95, 16), Pair(64, 9), Pair(19, 39), Pair(-22, 59), Pair(27, 45),
    Pair(-10, -7), Pair(2, -11), Pair(-7, -24), Pair(18, -49), Pair(10, -48), Pair(15, -28), Pair(1, -7), Pair(-2, -15),
    Pair(-20, -20), Pair(-12, -21), Pair(-19, -32), Pair(-3, -45), Pair(5, -48), Pair(3, -41), Pair(-5, -27), Pair(-21, -28),
    Pair(-30, -30), Pair(-21, -22), Pair(-13, -44), Pair(-5, -48), Pair(-5, -48), Pair(-2, -43), Pair(-9, -31), Pair(-27, -37),
    Pair(-35, -34), Pair(-22, -30), Pair(-27, -37), Pair(-23, -37), Pair(-18, -43), Pair(-19, -36), Pair(6, -43), Pair(-23, -41),
    Pair(-34, -25), Pair(-12, -27), Pair(-22, -26), Pair(-24, -30), Pair(-21, -33), Pair(3, -33), Pair(14, -37), Pair(-20, -39),
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(-145, -138), Pair(-37, 13), Pair(-88, 16), Pair(-31, 5), Pair(43, -14), Pair(-216, 57), Pair(-71, 6), Pair(-81, -69),
    Pair(-25, -1), Pair(-23, 19), Pair(17, 4), Pair(47, 17), Pair(43, 10), Pair(58, -7), Pair(-7, 6), Pair(-9, 0),
    Pair(-8, 1), Pair(17, 13), Pair(25, 26), Pair(49, 16), Pair(66, 9), Pair(81, 0), Pair(10, 14), Pair(26, -11),
    Pair(11, 8), Pair(19, 20), Pair(30, 27), Pair(42, 32), Pair(29, 36), Pair(49, 25), Pair(24, 26), Pair(34, 4),
    Pair(5, 11), Pair(13, 16), Pair(27, 29), Pair(33, 32), Pair(36, 33), Pair(43, 21), Pair(35, 13), Pair(20, 12),
    Pair(-8, -14), Pair(15, 8), Pair(17, 14), Pair(25, 27), Pair(30, 25), Pair(26, 12), Pair(28, 1), Pair(3, -3),
    Pair(-10, -15), Pair(-4, 3), Pair(6, 0), Pair(16, 9), Pair(19, 7), Pair(22, -9), Pair(10, 1), Pair(3, -6),
    Pair(-35, -25), Pair(-8, -11), Pair(-2, -12), Pair(-4, 8), Pair(12, 1), Pair(4, -8), Pair(-6, -12), Pair(-16, -20)
  },
  {
    Pair(-64, 13), Pair(-79, 25), Pair(-95, 32), Pair(-113, 39), Pair(-60, 29), Pair(-170, 44), Pair(-15, 25), Pair(-53, 22),
    Pair(-29, 8), Pair(-19, 19), Pair(-10, 15), Pair(-28, 28), Pair(-26, 28), Pair(-3, 25), Pair(-18, 19), Pair(-20, 2),
    Pair(-7, 5), Pair(7, 15), Pair(3, 21), Pair(21, 11), Pair(33, 14), Pair(36, 22), Pair(28, 9), Pair(19, 2),
    Pair(-6, 1), Pair(10, 11), Pair(8, 15), Pair(24, 19), Pair(16, 18), Pair(29, 8), Pair(10, 10), Pair(12, -1),
    Pair(7, -2), Pair(-3, 4), Pair(12, 11), Pair(8, 14), Pair(15, 11), Pair(10, 10), Pair(4, 4), Pair(11, 2),
    Pair(-3, 4), Pair(20, 8), Pair(15, 12), Pair(10, 16), Pair(9, 17), Pair(17, 8), Pair(18, 6), Pair(0, 7),
    Pair(17, -1), Pair(19, -12), Pair(15, -1), Pair(3, 3), Pair(13, 0), Pair(15, -5), Pair(27, -8), Pair(17, -19),
    Pair(20, -7), Pair(11, -7), Pair(-3, -1), Pair(-2, -3), Pair(2, -7), Pair(-6, 2), Pair(4, -16), Pair(0, -8)
  },
  {
    Pair(30, 31), Pair(13, 42), Pair(21, 44), Pair(26, 36), Pair(22, 33), Pair(22, 41), Pair(8, 49), Pair(13, 35),
    Pair(-4, 41), Pair(-5, 47), Pair(13, 44), Pair(41, 34), Pair(28, 33), Pair(24, 31), Pair(-30, 53), Pair(1, 35),
    Pair(-1, 40), Pair(22, 32), Pair(15, 38), Pair(38, 24), Pair(42, 17), Pair(43, 29), Pair(11, 31), Pair(0, 34),
    Pair(-10, 36), Pair(-1, 39), Pair(11, 38), Pair(16, 33), Pair(25, 27), Pair(18, 36), Pair(-3, 39), Pair(-5, 29),
    Pair(-29, 32), Pair(-21, 39), Pair(-14, 42), Pair(-8, 35), Pair(-8, 30), Pair(-9, 36), Pair(-19, 36), Pair(-21, 20),
    Pair(-32, 19), Pair(-19, 19), Pair(-31, 32), Pair(-15, 25), Pair(-14, 18), Pair(-17, 25), Pair(-19, 22), Pair(-21, 7),
    Pair(-45, 17), Pair(-30, 15), Pair(-19, 22), Pair(-16, 21), Pair(-11, 9), Pair(-9, 8), Pair(-29, 13), Pair(-48, 12),
    Pair(-20, 10), Pair(-18, 9), Pair(-17, 20), Pair(-6, 11), Pair(-4, 3), Pair(-9, 10), Pair(-34, 18), Pair(-6, -8)
  },
  {
    Pair(-2, 64), Pair(10, 68), Pair(42, 46), Pair(45, 56), Pair(42, 58), Pair(43, 68), Pair(-5, 101), Pair(6, 84),
    Pair(-39, 97), Pair(-32, 97), Pair(-27, 123), Pair(-18, 122), Pair(-42, 137), Pair(4, 101), Pair(-25, 133), Pair(-7, 100),
    Pair(-19, 74), Pair(-8, 94), Pair(-19, 114), Pair(-4, 110), Pair(13, 110), Pair(17, 109), Pair(22, 85), Pair(-1, 84),
    Pair(-6, 57), Pair(-7, 88), Pair(-13, 103), Pair(-7, 119), Pair(0, 122), Pair(8, 101), Pair(4, 100), Pair(16, 57),
    Pair(-6, 49), Pair(-13, 85), Pair(-8, 89), Pair(-16, 125), Pair(-2, 94), Pair(-7, 96), Pair(11, 74), Pair(1, 65),
    Pair(-11, 50), Pair(-1, 55), Pair(-5, 77), Pair(-6, 71), Pair(-5, 77), Pair(2, 68), Pair(11, 54), Pair(12, 29),
    Pair(-14, 29), Pair(-4, 34), Pair(4, 25), Pair(-2, 52), Pair(4, 45), Pair(9, 11), Pair(15, -6), Pair(8, 16),
    Pair(-3, 16), Pair(-13, 25), Pair(-6, 7), Pair(-4, 20), Pair(1, 12), Pair(-17, -5), Pair(-15, -16), Pair(-2, 26)
  },
  {
    Pair(89, -55), Pair(101, 5), Pair(268, -41), Pair(181, -14), Pair(218, -37), Pair(159, -9), Pair(124, -10), Pair(88, -103),
    Pair(103, -29), Pair(184, 10), Pair(129, 29), Pair(112, 16), Pair(78, 20), Pair(51, 36), Pair(136, 15), Pair(43, -7),
    Pair(38, -1), Pair(108, 21), Pair(104, 31), Pair(36, 38), Pair(76, 25), Pair(101, 19), Pair(93, 20), Pair(34, -7),
    Pair(25, -9), Pair(61, 10), Pair(12, 33), Pair(-25, 45), Pair(-7, 38), Pair(16, 24), Pair(59, 3), Pair(-30, -9),
    Pair(-20, -18), Pair(17, 5), Pair(-11, 22), Pair(-38, 39), Pair(-43, 37), Pair(-4, 14), Pair(1, -2), Pair(-49, -25),
    Pair(1, -22), Pair(0, 0), Pair(-25, 17), Pair(-43, 31), Pair(-47, 28), Pair(-29, 14), Pair(1, -10), Pair(-25, -26),
    Pair(39, -32), Pair(7, -8), Pair(-26, 13), Pair(-46, 23), Pair(-46, 21), Pair(-36, 12), Pair(-3, -8), Pair(17, -37),
    Pair(34, -68), Pair(40, -33), Pair(22, -20), Pair(-57, 6), Pair(-8, -24), Pair(-39, -5), Pair(28, -34), Pair(30, -77)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-16, -69), Pair(-2, -17), Pair(5, 9), Pair(10, 19), Pair(14, 27), Pair(17, 32), Pair(20, 31), Pair(26, 24),
  Pair(27, 17)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-19, -55), Pair(-9, -33), Pair(-2, -16), Pair(2, -3), Pair(6, 4), Pair(8, 11), Pair(10, 14), Pair(11, 17),
  Pair(14, 19), Pair(15, 20), Pair(19, 16), Pair(32, 13), Pair(35, 13), Pair(81, 5)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-35, -69), Pair(-28, -25), Pair(-24, -12), Pair(-19, 7), Pair(-17, 12), Pair(-14, 16), Pair(-10, 20), Pair(-5, 21),
  Pair(0, 26), Pair(5, 28), Pair(9, 30), Pair(13, 31), Pair(20, 28), Pair(28, 23), Pair(33, 23)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-20, 14), Pair(-15, -16), Pair(-13, -12), Pair(-9, -11), Pair(-10, 27), Pair(-10, 46), Pair(-8, 61), Pair(-6, 68),
  Pair(-4, 76), Pair(-3, 87), Pair(-1, 93), Pair(0, 96), Pair(1, 101), Pair(4, 98), Pair(2, 103), Pair(5, 97),
  Pair(8, 94), Pair(12, 87), Pair(15, 77), Pair(25, 62), Pair(29, 55), Pair(57, 21), Pair(76, -3), Pair(100, -24),
  Pair(93, -33), Pair(127, -75), Pair(272, -159), Pair(142, -53)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-5, -64), Pair(-5, -54), Pair(3, -25), Pair(25, 2), Pair(48, 46), Pair(34, 38), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(4, 6), Pair(10, 5), Pair(15, 16), Pair(34, 55), Pair(177, 100), Pair(135, 481), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(16, 10), Pair(11, 7), Pair(14, 14), Pair(39, 40), Pair(181, 54), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-30, -39), Pair(-5, -25), Pair(-9, -15), Pair(-24, 6), Pair(-14, -6), Pair(-13, -8), Pair(-7, -20), Pair(-22, -37)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(4, 1), Pair(-8, -8), Pair(-6, -10), Pair(-12, -14), Pair(-11, -11), Pair(-4, -12), Pair(-7, -3), Pair(-1, 2)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
    Pair(18, -3), Pair(15, 2), Pair(20, -2), Pair(19, -1), Pair(27, 1), Pair(32, -2), Pair(48, -11), Pair(34, -1)
  },
  {
    Pair(12, 27), Pair(13, 7), Pair(21, -2), Pair(19, -4), Pair(20, -1), Pair(14, -4), Pair(43, -12), Pair(18, 14)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(10, -2), Pair(11, -4), Pair(11, -1),
  Pair(15, -3), Pair(14, -5), Pair(17, -4),
  Pair(24, -1), Pair(0, 0), Pair(24, -1),
  Pair(-9, 9), Pair(-16, 5), Pair(-6, 9)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-16, 6), Pair(-7, 2),
  Pair(-10, 3), Pair(-20, 8), Pair(-9, 2),
  Pair(0, -6), Pair(-8, -2), Pair(1, -7),
  Pair(11, -7), Pair(-12, -1), Pair(11, -8),
  Pair(25, -16), Pair(18, -2), Pair(19, -13),
  Pair(0, 0), Pair(-33, -18), Pair(0, 0),
  Pair(60, -47), Pair(0, 0), Pair(24, -38)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-4, 52), Pair(-13, 42), Pair(-14, 27), Pair(-12, 19), Pair(-9, 17), Pair(4, 16), Pair(-2, 12)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-36, -12), Pair(-13, 15), Pair(-10, 35), Pair(-3, 43), Pair(-1, 48), Pair(-1, 49), Pair(-18, 54)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-470, 76);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
    Pair(-65, -2), Pair(-55, -2), Pair(-23, -12), Pair(-17, -12), Pair(-17, -9), Pair(-32, -3), Pair(-45, 1), Pair(-58, 9)
  },
  {
    Pair(-52, 57), Pair(-32, 23), Pair(-16, 9), Pair(-13, -2), Pair(-10, -3), Pair(-21, 12), Pair(-19, 19), Pair(-33, 44)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(11, 2), Pair(21, -3), Pair(65, -21), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(8, 2), Pair(23, 1), Pair(42, -6), Pair(-9, -13), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(19, -15), Pair(28, -15), Pair(45, -11), Pair(70, -12), Pair(70, -14), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(2, 18), Pair(10, 31), Pair(26, 32), Pair(71, 9), Pair(127, -13), Pair(220, -56), Pair(212, -57)
  },
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(22, 3), Pair(6, 20), Pair(46, -9), Pair(14, 17), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
    Pair(-8, 37), Pair(0, 36)
  },
  {
    Pair(-63, -28), Pair(-54, -35)
  },
  {
    Pair(-49, -48), Pair(-50, -57)
  },
  {
    Pair(-60, -36), Pair(-53, -23)
  },
  {
    Pair(-45, 19), Pair(-50, 20)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(12, 29), Pair(17, 24), Pair(20, 14), Pair(17, -4), Pair(39, 2)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
    Pair(-4, -25), Pair(6, -10)
  },
  {
    Pair(21, -15), Pair(24, -21)
  },
  {
    Pair(-42, -14), Pair(-31, -27)
  },
  {
    Pair(-66, 7), Pair(-50, -9)
  },
  {
    Pair(-35, -10), Pair(-30, -24)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
    Pair(-12, -20), Pair(-1, -4)
  },
  {
    Pair(-42, -14), Pair(-14, -36)
  },
  {
    Pair(6, -62), Pair(11, -70)
  },
  {
    Pair(-44, -18), Pair(-44, -36)
  },
  {
    Pair(-44, -39), Pair(-36, -50)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
    Pair(-7, -22), Pair(12, -13)
  },
  {
    Pair(-37, -22), Pair(-5, -19)
  },
  {
    Pair(-36, -18), Pair(-14, -10)
  },
  {
    Pair(6, -26), Pair(11, -9)
  },
  {
    Pair(-63, 0), Pair(-44, -45)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(5, 29), Pair(7, 15), Pair(32, 10), Pair(27, 15), Pair(4, 32), Pair(0, 36), Pair(30, 29), Pair(20, 18),
  Pair(27, 9), Pair(10, 5), Pair(11, 19), Pair(3, 22), Pair(14, 24), Pair(0, 19), Pair(13, 6), Pair(11, 7),
  Pair(6, -1), Pair(2, 14), Pair(0, 14), Pair(8, 15), Pair(1, 20), Pair(-1, 13), Pair(-6, 16), Pair(6, -3)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-8, 10), Pair(16, 16), Pair(25, 1), Pair(27, -3), Pair(31, -8), Pair(43, 3), Pair(27, 14), Pair(-44, 36),
  Pair(-10, 0), Pair(13, 11), Pair(8, 5), Pair(10, 11), Pair(10, 10), Pair(8, 10), Pair(12, 13), Pair(-1, -2),
  Pair(-21, 34), Pair(5, 21), Pair(-2, 24), Pair(15, 15), Pair(11, 22), Pair(-5, 14), Pair(10, 5), Pair(-6, -14)
};

constexpr ScorePair kBishopPairBonus = Pair(19, 49);

constexpr ScorePair kTempoBonus = Pair(15, 6);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H