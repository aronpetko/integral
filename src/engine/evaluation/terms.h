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
  Pair(96, 126), Pair(337, 258), Pair(376, 325), Pair(505, 554), Pair(1085, 933), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
    Pair(67, 36), Pair(15, 57), Pair(39, 37), Pair(80, 19), Pair(49, 11), Pair(3, 42), Pair(-37, 63), Pair(12, 48),
    Pair(-10, -1), Pair(3, -4), Pair(-7, -18), Pair(18, -42), Pair(10, -42), Pair(15, -21), Pair(1, 0), Pair(-1, -9),
    Pair(-19, -14), Pair(-12, -14), Pair(-19, -26), Pair(-3, -38), Pair(5, -41), Pair(3, -34), Pair(-4, -20), Pair(-20, -21),
    Pair(-30, -24), Pair(-20, -15), Pair(-13, -38), Pair(-5, -41), Pair(-5, -42), Pair(-2, -36), Pair(-8, -24), Pair(-26, -31),
    Pair(-35, -28), Pair(-21, -23), Pair(-26, -30), Pair(-23, -30), Pair(-17, -36), Pair(-19, -29), Pair(6, -36), Pair(-22, -35),
    Pair(-34, -19), Pair(-11, -20), Pair(-23, -19), Pair(-24, -23), Pair(-21, -27), Pair(3, -26), Pair(13, -29), Pair(-20, -33),
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(-142, -131), Pair(-37, 22), Pair(-87, 25), Pair(-31, 15), Pair(43, -5), Pair(-208, 63), Pair(-70, 15), Pair(-79, -61),
    Pair(-24, 8), Pair(-23, 27), Pair(17, 13), Pair(47, 25), Pair(43, 19), Pair(59, 2), Pair(-7, 15), Pair(-9, 8),
    Pair(-8, 10), Pair(18, 22), Pair(26, 35), Pair(49, 24), Pair(67, 18), Pair(82, 9), Pair(11, 23), Pair(26, -2),
    Pair(12, 17), Pair(19, 29), Pair(31, 36), Pair(43, 41), Pair(29, 45), Pair(49, 34), Pair(24, 35), Pair(34, 13),
    Pair(5, 19), Pair(13, 25), Pair(28, 38), Pair(34, 42), Pair(36, 42), Pair(43, 31), Pair(35, 21), Pair(20, 20),
    Pair(-7, -5), Pair(15, 17), Pair(17, 22), Pair(25, 36), Pair(30, 34), Pair(27, 21), Pair(29, 10), Pair(3, 6),
    Pair(-10, -6), Pair(-3, 12), Pair(6, 9), Pair(16, 19), Pair(19, 16), Pair(22, 0), Pair(10, 10), Pair(3, 2),
    Pair(-35, -17), Pair(-8, -3), Pair(-2, -3), Pair(-4, 17), Pair(12, 10), Pair(4, 1), Pair(-6, -3), Pair(-15, -12)
  },
  {
    Pair(-68, 12), Pair(-83, 24), Pair(-99, 31), Pair(-117, 38), Pair(-63, 28), Pair(-174, 43), Pair(-19, 24), Pair(-57, 20),
    Pair(-34, 7), Pair(-23, 18), Pair(-14, 13), Pair(-32, 27), Pair(-30, 27), Pair(-8, 23), Pair(-22, 18), Pair(-24, 1),
    Pair(-11, 4), Pair(2, 13), Pair(-1, 20), Pair(16, 9), Pair(29, 13), Pair(32, 20), Pair(23, 8), Pair(15, 0),
    Pair(-11, 0), Pair(6, 9), Pair(4, 14), Pair(20, 17), Pair(12, 17), Pair(25, 7), Pair(6, 9), Pair(7, -2),
    Pair(3, -3), Pair(-7, 3), Pair(8, 9), Pair(4, 13), Pair(11, 10), Pair(6, 9), Pair(-1, 3), Pair(6, 0),
    Pair(-7, 2), Pair(16, 7), Pair(10, 11), Pair(6, 14), Pair(4, 16), Pair(13, 7), Pair(13, 5), Pair(-4, 5),
    Pair(14, -2), Pair(14, -13), Pair(11, -3), Pair(-2, 2), Pair(9, -1), Pair(11, -6), Pair(22, -9), Pair(12, -21),
    Pair(16, -9), Pair(6, -8), Pair(-7, -3), Pair(-6, -4), Pair(-3, -8), Pair(-10, 1), Pair(-1, -17), Pair(-5, -9)
  },
  {
    Pair(32, 26), Pair(15, 37), Pair(23, 40), Pair(28, 32), Pair(24, 29), Pair(24, 37), Pair(9, 45), Pair(15, 30),
    Pair(-2, 37), Pair(-3, 42), Pair(15, 40), Pair(43, 29), Pair(31, 29), Pair(27, 27), Pair(-28, 49), Pair(4, 30),
    Pair(1, 35), Pair(24, 28), Pair(17, 33), Pair(40, 20), Pair(44, 13), Pair(44, 25), Pair(14, 27), Pair(2, 30),
    Pair(-8, 31), Pair(1, 34), Pair(13, 33), Pair(18, 28), Pair(27, 23), Pair(20, 32), Pair(-1, 35), Pair(-3, 24),
    Pair(-27, 28), Pair(-19, 34), Pair(-12, 37), Pair(-5, 31), Pair(-6, 26), Pair(-7, 31), Pair(-17, 32), Pair(-19, 15),
    Pair(-30, 14), Pair(-18, 14), Pair(-28, 27), Pair(-13, 20), Pair(-11, 14), Pair(-15, 20), Pair(-16, 17), Pair(-19, 3),
    Pair(-43, 13), Pair(-28, 10), Pair(-16, 17), Pair(-14, 17), Pair(-9, 6), Pair(-6, 3), Pair(-26, 8), Pair(-46, 7),
    Pair(-18, 5), Pair(-15, 5), Pair(-14, 15), Pair(-3, 6), Pair(-1, -1), Pair(-6, 6), Pair(-32, 14), Pair(-4, -13)
  },
  {
    Pair(13, 57), Pair(24, 62), Pair(57, 39), Pair(60, 48), Pair(56, 51), Pair(59, 60), Pair(10, 94), Pair(20, 78),
    Pair(-25, 91), Pair(-19, 91), Pair(-14, 118), Pair(-5, 116), Pair(-28, 132), Pair(17, 95), Pair(-11, 127), Pair(7, 94),
    Pair(-6, 68), Pair(6, 88), Pair(-6, 109), Pair(10, 105), Pair(26, 106), Pair(30, 104), Pair(36, 81), Pair(13, 78),
    Pair(8, 52), Pair(7, 82), Pair(0, 97), Pair(6, 114), Pair(14, 117), Pair(22, 95), Pair(18, 95), Pair(29, 51),
    Pair(8, 43), Pair(0, 80), Pair(6, 84), Pair(-2, 120), Pair(12, 90), Pair(7, 91), Pair(24, 69), Pair(15, 59),
    Pair(2, 44), Pair(13, 49), Pair(9, 71), Pair(7, 65), Pair(8, 71), Pair(15, 62), Pair(24, 49), Pair(25, 24),
    Pair(-1, 23), Pair(10, 28), Pair(18, 20), Pair(11, 47), Pair(18, 39), Pair(23, 5), Pair(28, -11), Pair(22, 10),
    Pair(10, 11), Pair(0, 20), Pair(7, 2), Pair(10, 14), Pair(15, 6), Pair(-3, -10), Pair(-1, -21), Pair(12, 20)
  },
  {
    Pair(82, -60), Pair(101, 0), Pair(204, -33), Pair(105, -3), Pair(132, -24), Pair(63, 9), Pair(83, -6), Pair(86, -108),
    Pair(64, -26), Pair(154, 10), Pair(105, 28), Pair(109, 10), Pair(73, 15), Pair(46, 30), Pair(114, 13), Pair(25, -10),
    Pair(32, -6), Pair(102, 16), Pair(99, 26), Pair(33, 33), Pair(73, 20), Pair(98, 14), Pair(88, 15), Pair(31, -13),
    Pair(21, -15), Pair(57, 5), Pair(9, 27), Pair(-28, 39), Pair(-10, 33), Pair(13, 18), Pair(56, -2), Pair(-33, -15),
    Pair(-23, -23), Pair(14, 0), Pair(-14, 17), Pair(-40, 34), Pair(-46, 32), Pair(-6, 9), Pair(-2, -8), Pair(-52, -31),
    Pair(-2, -27), Pair(-2, -5), Pair(-28, 11), Pair(-46, 25), Pair(-50, 24), Pair(-31, 8), Pair(-2, -15), Pair(-27, -32),
    Pair(37, -37), Pair(5, -14), Pair(-29, 7), Pair(-48, 17), Pair(-48, 15), Pair(-38, 7), Pair(-5, -14), Pair(15, -43),
    Pair(32, -73), Pair(38, -39), Pair(20, -26), Pair(-59, 0), Pair(-10, -30), Pair(-41, -11), Pair(26, -40), Pair(28, -82)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-8, -40), Pair(6, 12), Pair(13, 38), Pair(18, 48), Pair(22, 55), Pair(25, 61), Pair(27, 60), Pair(33, 53),
  Pair(35, 45)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-13, -51), Pair(-4, -29), Pair(3, -12), Pair(8, 1), Pair(12, 9), Pair(13, 16), Pair(16, 19), Pair(16, 21),
  Pair(19, 24), Pair(20, 25), Pair(25, 21), Pair(37, 18), Pair(40, 18), Pair(86, 10)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-32, -73), Pair(-24, -28), Pair(-21, -15), Pair(-16, 3), Pair(-14, 8), Pair(-10, 13), Pair(-7, 16), Pair(-2, 18),
  Pair(3, 23), Pair(8, 25), Pair(12, 27), Pair(16, 28), Pair(24, 25), Pair(32, 20), Pair(36, 19)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-16, -20), Pair(-11, -63), Pair(-9, -22), Pair(-6, -21), Pair(-6, 15), Pair(-6, 35), Pair(-5, 49), Pair(-2, 57),
  Pair(-1, 64), Pair(1, 75), Pair(2, 80), Pair(3, 83), Pair(5, 88), Pair(8, 85), Pair(5, 89), Pair(9, 83),
  Pair(12, 79), Pair(17, 72), Pair(20, 61), Pair(31, 46), Pair(35, 38), Pair(63, 4), Pair(83, -21), Pair(108, -44),
  Pair(97, -50), Pair(154, -105), Pair(201, -129), Pair(108, -47)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-7, -57), Pair(-8, -47), Pair(0, -18), Pair(23, 9), Pair(46, 53), Pair(48, 48), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(4, 6), Pair(9, 5), Pair(14, 16), Pair(34, 55), Pair(175, 101), Pair(74, 502), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(16, 10), Pair(11, 7), Pair(14, 14), Pair(39, 40), Pair(179, 55), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-31, -39), Pair(-6, -25), Pair(-10, -15), Pair(-24, 6), Pair(-13, -5), Pair(-13, -8), Pair(-7, -21), Pair(-22, -38)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(5, 1), Pair(-8, -8), Pair(-5, -10), Pair(-11, -14), Pair(-11, -11), Pair(-5, -12), Pair(-7, -4), Pair(-1, 2)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
    Pair(18, -3), Pair(15, 2), Pair(20, -1), Pair(19, -1), Pair(27, 1), Pair(32, -2), Pair(48, -11), Pair(34, -1)
  },
  {
    Pair(12, 27), Pair(13, 8), Pair(20, -2), Pair(19, -3), Pair(19, -1), Pair(14, -5), Pair(42, -12), Pair(19, 14)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(11, -2), Pair(11, -4), Pair(11, -1),
  Pair(15, -3), Pair(14, -5), Pair(16, -4),
  Pair(24, -1), Pair(0, 0), Pair(24, -1),
  Pair(-9, 9), Pair(-15, 5), Pair(-6, 8)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-16, 7), Pair(-8, 2),
  Pair(-10, 4), Pair(-20, 9), Pair(-9, 2),
  Pair(1, -6), Pair(-8, -2), Pair(1, -8),
  Pair(12, -7), Pair(-12, 0), Pair(11, -8),
  Pair(26, -16), Pair(18, -2), Pair(19, -14),
  Pair(0, 0), Pair(-33, -18), Pair(0, 0),
  Pair(59, -47), Pair(0, 0), Pair(23, -38)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-1, 49), Pair(-8, 40), Pair(-9, 24), Pair(-8, 16), Pair(-5, 14), Pair(8, 14), Pair(2, 10)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-39, -16), Pair(-16, 11), Pair(-12, 31), Pair(-5, 39), Pair(-4, 44), Pair(-4, 44), Pair(-21, 50)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-425, 75);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
    Pair(-64, -3), Pair(-54, -2), Pair(-22, -11), Pair(-16, -12), Pair(-17, -9), Pair(-33, -2), Pair(-45, 2), Pair(-57, 9)
  },
  {
    Pair(-51, 57), Pair(-32, 24), Pair(-16, 9), Pair(-13, 0), Pair(-11, -3), Pair(-21, 13), Pair(-19, 19), Pair(-32, 44)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(11, 3), Pair(21, -2), Pair(65, -20), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(8, 3), Pair(23, 1), Pair(42, -5), Pair(-9, -13), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(19, -15), Pair(27, -15), Pair(44, -11), Pair(70, -11), Pair(70, -14), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(3, 18), Pair(10, 31), Pair(27, 31), Pair(72, 8), Pair(128, -15), Pair(221, -57), Pair(215, -60)
  },
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(21, 3), Pair(6, 20), Pair(45, -9), Pair(14, 18), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
    Pair(-7, 36), Pair(0, 35)
  },
  {
    Pair(-63, -28), Pair(-54, -35)
  },
  {
    Pair(-49, -47), Pair(-50, -56)
  },
  {
    Pair(-60, -36), Pair(-52, -23)
  },
  {
    Pair(-45, 19), Pair(-49, 20)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(12, 29), Pair(17, 24), Pair(20, 15), Pair(17, -5), Pair(40, 1)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
    Pair(-5, -24), Pair(6, -10)
  },
  {
    Pair(22, -20), Pair(25, -26)
  },
  {
    Pair(-42, -13), Pair(-31, -27)
  },
  {
    Pair(-66, 6), Pair(-50, -9)
  },
  {
    Pair(-35, -10), Pair(-30, -23)
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
    Pair(-42, -15), Pair(-14, -35)
  },
  {
    Pair(6, -58), Pair(11, -65)
  },
  {
    Pair(-44, -18), Pair(-43, -36)
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
    Pair(-7, -22), Pair(12, -12)
  },
  {
    Pair(-37, -21), Pair(-6, -19)
  },
  {
    Pair(-37, -17), Pair(-14, -9)
  },
  {
    Pair(6, -27), Pair(11, -10)
  },
  {
    Pair(-63, -1), Pair(-44, -45)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(5, 29), Pair(7, 15), Pair(32, 10), Pair(26, 16), Pair(4, 32), Pair(-1, 36), Pair(30, 29), Pair(20, 18),
  Pair(27, 9), Pair(11, 6), Pair(11, 20), Pair(3, 22), Pair(14, 24), Pair(1, 19), Pair(13, 7), Pair(12, 7),
  Pair(6, 0), Pair(2, 14), Pair(0, 14), Pair(8, 16), Pair(1, 21), Pair(-1, 13), Pair(-6, 16), Pair(6, -3)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-8, 10), Pair(16, 16), Pair(24, 1), Pair(27, -3), Pair(31, -7), Pair(43, 3), Pair(27, 14), Pair(-44, 36),
  Pair(-10, 0), Pair(13, 12), Pair(8, 6), Pair(10, 11), Pair(10, 10), Pair(8, 11), Pair(12, 14), Pair(-1, -2),
  Pair(-21, 34), Pair(5, 21), Pair(-3, 25), Pair(15, 16), Pair(11, 22), Pair(-5, 15), Pair(11, 5), Pair(-6, -14)
};

constexpr ScorePair kBishopPairBonus = Pair(19, 49);

constexpr ScorePair kTempoBonus = Pair(15, 6);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H