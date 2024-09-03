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
  Pair(97, 132), Pair(324, 278), Pair(366, 343), Pair(494, 596), Pair(1088, 1008), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
    Pair(71, 46), Pair(18, 71), Pair(52, 39), Pair(98, 15), Pair(82, 26), Pair(25, 51), Pair(-24, 63), Pair(15, 58),
    Pair(-10, 0), Pair(-2, 1), Pair(-6, -13), Pair(22, -40), Pair(18, -38), Pair(24, -23), Pair(-8, 3), Pair(-1, -7),
    Pair(-17, -11), Pair(-12, -9), Pair(-17, -26), Pair(-2, -40), Pair(7, -40), Pair(9, -37), Pair(-9, -16), Pair(-16, -22),
    Pair(-27, -23), Pair(-22, -12), Pair(-14, -35), Pair(-6, -39), Pair(-4, -40), Pair(1, -38), Pair(-11, -24), Pair(-22, -33),
    Pair(-30, -28), Pair(-24, -21), Pair(-26, -30), Pair(-26, -29), Pair(-20, -31), Pair(-16, -32), Pair(3, -38), Pair(-19, -40),
    Pair(-29, -22), Pair(-12, -19), Pair(-24, -19), Pair(-25, -21), Pair(-24, -20), Pair(6, -28), Pair(11, -31), Pair(-16, -39),
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(-186, 8), Pair(-58, 27), Pair(-31, 21), Pair(-16, 27), Pair(35, 11), Pair(-149, 47), Pair(-41, 26), Pair(-100, -15),
    Pair(-29, 16), Pair(-9, 28), Pair(24, 17), Pair(56, 24), Pair(53, 18), Pair(59, 4), Pair(7, 14), Pair(2, 14),
    Pair(-11, 16), Pair(23, 20), Pair(18, 42), Pair(41, 32), Pair(66, 27), Pair(79, 20), Pair(20, 25), Pair(29, 5),
    Pair(17, 19), Pair(17, 34), Pair(28, 45), Pair(40, 49), Pair(27, 53), Pair(47, 38), Pair(22, 45), Pair(35, 21),
    Pair(5, 25), Pair(13, 33), Pair(24, 45), Pair(31, 45), Pair(34, 45), Pair(41, 38), Pair(40, 25), Pair(21, 20),
    Pair(-9, -4), Pair(12, 20), Pair(15, 27), Pair(25, 40), Pair(26, 39), Pair(24, 27), Pair(28, 16), Pair(1, 11),
    Pair(-13, 9), Pair(-3, 23), Pair(3, 7), Pair(15, 22), Pair(19, 18), Pair(19, 2), Pair(5, 23), Pair(-1, 14),
    Pair(-44, -5), Pair(-8, 1), Pair(-3, 9), Pair(-1, 26), Pair(8, 17), Pair(2, 3), Pair(-7, -2), Pair(-15, -11)
  },
  {
    Pair(-35, 26), Pair(-64, 29), Pair(-72, 36), Pair(-66, 35), Pair(-46, 32), Pair(-170, 50), Pair(-23, 23), Pair(-51, 23),
    Pair(-32, 12), Pair(-19, 24), Pair(-9, 20), Pair(-21, 34), Pair(-19, 23), Pair(6, 18), Pair(-23, 24), Pair(-32, 14),
    Pair(-12, 12), Pair(0, 20), Pair(-3, 26), Pair(20, 14), Pair(27, 16), Pair(35, 19), Pair(30, 15), Pair(16, 0),
    Pair(-11, 6), Pair(0, 19), Pair(3, 17), Pair(19, 21), Pair(12, 20), Pair(22, 16), Pair(4, 14), Pair(6, 1),
    Pair(4, 2), Pair(-3, 8), Pair(3, 20), Pair(0, 21), Pair(13, 14), Pair(3, 12), Pair(3, 12), Pair(2, 4),
    Pair(-8, 10), Pair(15, 13), Pair(6, 20), Pair(6, 21), Pair(2, 23), Pair(13, 14), Pair(15, 14), Pair(-7, 17),
    Pair(15, 7), Pair(12, -6), Pair(12, 1), Pair(-3, 9), Pair(8, 4), Pair(7, 3), Pair(21, -2), Pair(11, -11),
    Pair(11, -2), Pair(10, -2), Pair(-11, 7), Pair(-8, 4), Pair(-3, 2), Pair(-14, 10), Pair(2, -3), Pair(-1, -1)
  },
  {
    Pair(23, 39), Pair(26, 43), Pair(7, 53), Pair(33, 42), Pair(18, 45), Pair(18, 49), Pair(1, 57), Pair(19, 44),
    Pair(-7, 48), Pair(-7, 53), Pair(21, 45), Pair(36, 40), Pair(25, 42), Pair(28, 40), Pair(-19, 61), Pair(1, 46),
    Pair(-16, 53), Pair(19, 40), Pair(14, 44), Pair(34, 33), Pair(48, 24), Pair(54, 29), Pair(22, 42), Pair(6, 38),
    Pair(-13, 47), Pair(4, 47), Pair(13, 46), Pair(20, 39), Pair(20, 37), Pair(16, 38), Pair(-2, 49), Pair(2, 37),
    Pair(-29, 37), Pair(-23, 45), Pair(-17, 46), Pair(-17, 47), Pair(-15, 41), Pair(-19, 46), Pair(-19, 45), Pair(-20, 29),
    Pair(-35, 28), Pair(-21, 28), Pair(-25, 36), Pair(-26, 35), Pair(-15, 26), Pair(-21, 32), Pair(-19, 28), Pair(-25, 16),
    Pair(-46, 22), Pair(-28, 23), Pair(-22, 25), Pair(-15, 24), Pair(-12, 18), Pair(-14, 16), Pair(-32, 21), Pair(-49, 17),
    Pair(-20, 14), Pair(-17, 12), Pair(-16, 22), Pair(-7, 14), Pair(-4, 9), Pair(-9, 14), Pair(-34, 25), Pair(-5, -6)
  },
  {
    Pair(-14, 89), Pair(1, 88), Pair(2, 90), Pair(34, 69), Pair(33, 78), Pair(57, 66), Pair(50, 66), Pair(35, 84),
    Pair(-29, 98), Pair(-37, 108), Pair(-19, 122), Pair(-4, 114), Pair(-21, 132), Pair(23, 89), Pair(-10, 131), Pair(12, 92),
    Pair(-18, 81), Pair(-5, 102), Pair(-16, 113), Pair(4, 110), Pair(9, 119), Pair(20, 121), Pair(23, 106), Pair(1, 96),
    Pair(-8, 61), Pair(-9, 99), Pair(-10, 113), Pair(-4, 117), Pair(3, 117), Pair(16, 98), Pair(4, 109), Pair(22, 55),
    Pair(-7, 59), Pair(-20, 101), Pair(-10, 100), Pair(-14, 125), Pair(1, 87), Pair(-5, 97), Pair(12, 71), Pair(5, 69),
    Pair(-15, 61), Pair(-3, 63), Pair(-4, 83), Pair(-7, 80), Pair(-6, 85), Pair(2, 68), Pair(13, 51), Pair(13, 26),
    Pair(-8, 29), Pair(-8, 47), Pair(3, 32), Pair(2, 48), Pair(5, 42), Pair(11, 14), Pair(24, -24), Pair(4, 19),
    Pair(-8, 30), Pair(-8, 26), Pair(-5, 18), Pair(-2, 20), Pair(1, 17), Pair(-11, -5), Pair(-13, 5), Pair(37, -35)
  },
  {
    Pair(-9, -50), Pair(78, 4), Pair(133, -5), Pair(67, 27), Pair(103, -17), Pair(78, 20), Pair(5, 28), Pair(-10, -39),
    Pair(51, -24), Pair(105, 34), Pair(92, 35), Pair(72, 50), Pair(74, 28), Pair(86, 35), Pair(115, 29), Pair(31, -5),
    Pair(-28, 19), Pair(52, 36), Pair(68, 42), Pair(47, 43), Pair(69, 41), Pair(25, 47), Pair(76, 34), Pair(17, 3),
    Pair(6, -5), Pair(36, 20), Pair(-12, 39), Pair(-13, 47), Pair(-15, 43), Pair(27, 30), Pair(23, 15), Pair(-32, -8),
    Pair(-41, -15), Pair(17, 2), Pair(-12, 24), Pair(-48, 42), Pair(-36, 35), Pair(-27, 19), Pair(2, 1), Pair(-49, -28),
    Pair(15, -39), Pair(22, -12), Pair(-24, 13), Pair(-49, 32), Pair(-48, 26), Pair(-37, 15), Pair(0, -10), Pair(-18, -35),
    Pair(41, -49), Pair(18, -20), Pair(-16, 3), Pair(-47, 20), Pair(-51, 18), Pair(-38, 9), Pair(-2, -14), Pair(20, -47),
    Pair(32, -80), Pair(51, -50), Pair(31, -32), Pair(-52, -2), Pair(-6, -33), Pair(-42, -9), Pair(30, -42), Pair(34, -84)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-16, -35), Pair(-1, 13), Pair(6, 43), Pair(11, 55), Pair(15, 64), Pair(19, 71), Pair(23, 70), Pair(29, 63),
  Pair(32, 56)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-25, -48), Pair(-16, -22), Pair(-9, -7), Pair(-4, 7), Pair(-1, 18), Pair(1, 26), Pair(4, 30), Pair(4, 33),
  Pair(6, 35), Pair(9, 36), Pair(13, 34), Pair(28, 30), Pair(31, 32), Pair(70, 26)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-41, -65), Pair(-32, -25), Pair(-30, -6), Pair(-24, 8), Pair(-22, 15), Pair(-18, 19), Pair(-15, 24), Pair(-10, 25),
  Pair(-5, 29), Pair(-2, 33), Pair(3, 35), Pair(6, 38), Pair(11, 37), Pair(19, 34), Pair(11, 39)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-15, 15), Pair(-15, -50), Pair(-13, -15), Pair(-12, 17), Pair(-12, 31), Pair(-12, 54), Pair(-10, 67), Pair(-9, 80),
  Pair(-7, 90), Pair(-5, 95), Pair(-3, 103), Pair(-2, 107), Pair(-1, 112), Pair(1, 113), Pair(1, 114), Pair(3, 114),
  Pair(4, 110), Pair(7, 106), Pair(7, 102), Pair(4, 100), Pair(23, 78), Pair(43, 55), Pair(56, 38), Pair(49, 44),
  Pair(97, 2), Pair(122, -10), Pair(79, 3), Pair(92, -36)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-7, -63), Pair(-7, -55), Pair(2, -21), Pair(28, 8), Pair(49, 56), Pair(49, 49), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(4, 8), Pair(10, 7), Pair(15, 18), Pair(36, 58), Pair(196, 90), Pair(339, 374), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(16, 14), Pair(10, 10), Pair(15, 16), Pair(36, 44), Pair(198, 43), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-40, -42), Pair(-12, -23), Pair(-13, -15), Pair(-25, -1), Pair(-22, 0), Pair(-17, -7), Pair(-4, -22), Pair(-20, -38)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(4, 4), Pair(-6, -9), Pair(-3, -10), Pair(-12, -14), Pair(-11, -17), Pair(-4, -12), Pair(-5, -6), Pair(-7, 5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
    Pair(22, -3), Pair(16, 1), Pair(18, 1), Pair(22, -2), Pair(25, 1), Pair(35, -2), Pair(57, -14), Pair(38, -2)
  },
  {
    Pair(14, 26), Pair(13, 9), Pair(18, 0), Pair(18, -4), Pair(20, -3), Pair(17, -4), Pair(47, -18), Pair(20, 11)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(9, -1), Pair(11, -3), Pair(11, -2),
  Pair(14, -1), Pair(16, -5), Pair(16, -3),
  Pair(24, -1), Pair(0, 0), Pair(22, 0),
  Pair(-11, 11), Pair(-17, 6), Pair(-1, 9)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 0), Pair(-15, 7), Pair(-7, -1),
  Pair(-9, 2), Pair(-20, 9), Pair(-9, 1),
  Pair(1, -5), Pair(-7, -2), Pair(1, -7),
  Pair(11, -7), Pair(-10, -2), Pair(10, -7),
  Pair(26, -13), Pair(23, -3), Pair(23, -13),
  Pair(0, 0), Pair(-33, -18), Pair(0, 0),
  Pair(42, -46), Pair(0, 0), Pair(44, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-6, 52), Pair(-11, 43), Pair(-11, 24), Pair(-11, 18), Pair(-10, 18), Pair(5, 13), Pair(-10, 14)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-50, -14), Pair(-13, 11), Pair(-10, 32), Pair(-4, 40), Pair(1, 46), Pair(-3, 51), Pair(-10, 48)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-471, 98);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
    Pair(-63, 4), Pair(-58, 2), Pair(-20, -11), Pair(-20, -12), Pair(-18, -7), Pair(-24, -5), Pair(-45, 2), Pair(-40, 4)
  },
  {
    Pair(-47, 62), Pair(-33, 27), Pair(-23, 13), Pair(-14, -1), Pair(-10, 0), Pair(-15, 9), Pair(-19, 20), Pair(-37, 48)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(9, 2), Pair(20, -3), Pair(73, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(6, 3), Pair(19, 2), Pair(40, -4), Pair(9, -9), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(16, -15), Pair(25, -14), Pair(39, -9), Pair(66, -12), Pair(63, -15), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(2, 21), Pair(9, 31), Pair(21, 41), Pair(70, 18), Pair(114, 5), Pair(221, -54), Pair(301, -104)
  },
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(20, 5), Pair(6, 23), Pair(42, -4), Pair(12, 22), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
    Pair(-11, 44), Pair(-3, 45)
  },
  {
    Pair(-59, -24), Pair(-51, -39)
  },
  {
    Pair(-47, -48), Pair(-47, -65)
  },
  {
    Pair(-66, -31), Pair(-53, -32)
  },
  {
    Pair(-42, -4), Pair(-46, 13)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 30), Pair(18, 25), Pair(23, 15), Pair(19, -3), Pair(39, -1)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
    Pair(-4, -26), Pair(6, -10)
  },
  {
    Pair(7, 7), Pair(6, 6)
  },
  {
    Pair(-41, -11), Pair(-32, -29)
  },
  {
    Pair(-67, 4), Pair(-54, -10)
  },
  {
    Pair(-39, 1), Pair(-36, -6)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
    Pair(-14, -20), Pair(0, -4)
  },
  {
    Pair(-40, -14), Pair(-15, -34)
  },
  {
    Pair(3, -54), Pair(11, -63)
  },
  {
    Pair(-43, -17), Pair(-44, -40)
  },
  {
    Pair(-43, -51), Pair(-32, -65)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
    Pair(-8, -24), Pair(10, -13)
  },
  {
    Pair(-33, -25), Pair(-7, -18)
  },
  {
    Pair(-33, -23), Pair(-11, -12)
  },
  {
    Pair(6, -19), Pair(12, -2)
  },
  {
    Pair(-62, -7), Pair(-44, -42)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(29, 2), Pair(5, 20), Pair(35, 13), Pair(33, 11), Pair(24, 22), Pair(-1, 30), Pair(30, 20), Pair(20, 12),
  Pair(9, 13), Pair(12, 7), Pair(16, 15), Pair(2, 26), Pair(13, 19), Pair(1, 27), Pair(13, 11), Pair(6, 10),
  Pair(8, 3), Pair(3, 11), Pair(4, 10), Pair(6, 16), Pair(-2, 22), Pair(0, 14), Pair(-6, 15), Pair(2, 10)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(7, 4), Pair(21, 6), Pair(24, -3), Pair(28, -3), Pair(27, 7), Pair(51, -6), Pair(18, 11), Pair(6, -43),
  Pair(7, -2), Pair(13, 14), Pair(16, 3), Pair(14, 13), Pair(15, 13), Pair(10, 8), Pair(13, 11), Pair(0, 17),
  Pair(-20, 20), Pair(6, 19), Pair(2, 18), Pair(19, 15), Pair(9, 19), Pair(-5, 24), Pair(4, 10), Pair(-2, -5)
};

constexpr ScorePair kBishopPairBonus = Pair(18, 60);

constexpr ScorePair kTempoBonus = Pair(16, 8);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H