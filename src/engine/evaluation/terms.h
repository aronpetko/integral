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
  Pair(99, 123), Pair(353, 273), Pair(382, 310), Pair(520, 525), Pair(1189, 838), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
    Pair(63, 35), Pair(2, 63), Pair(40, 31), Pair(80, 13), Pair(65, 15), Pair(25, 46), Pair(-35, 64), Pair(-5, 50),
    Pair(-12, -1), Pair(0, -1), Pair(-7, -16), Pair(17, -39), Pair(12, -38), Pair(19, -20), Pair(-5, 3), Pair(-4, -9),
    Pair(-20, -12), Pair(-10, -11), Pair(-16, -27), Pair(-5, -38), Pair(3, -39), Pair(2, -33), Pair(-3, -19), Pair(-24, -20),
    Pair(-30, -23), Pair(-24, -13), Pair(-15, -36), Pair(-8, -36), Pair(-6, -41), Pair(-4, -36), Pair(-9, -22), Pair(-29, -30),
    Pair(-32, -29), Pair(-24, -23), Pair(-29, -30), Pair(-25, -32), Pair(-20, -35), Pair(-22, -30), Pair(8, -34), Pair(-29, -34),
    Pair(-32, -20), Pair(-14, -19), Pair(-26, -19), Pair(-25, -21), Pair(-24, -23), Pair(1, -26), Pair(13, -29), Pair(-23, -34),
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(-180, -60), Pair(-82, 20), Pair(-101, 25), Pair(-30, 12), Pair(34, -4), Pair(-165, 44), Pair(-12, -3), Pair(-101, -52),
    Pair(-24, -5), Pair(-24, 17), Pair(19, 4), Pair(59, 7), Pair(51, 1), Pair(51, -4), Pair(-2, 5), Pair(-21, 3),
    Pair(-19, 4), Pair(15, 9), Pair(33, 22), Pair(50, 18), Pair(68, 9), Pair(77, 2), Pair(16, 13), Pair(28, -15),
    Pair(15, 8), Pair(20, 16), Pair(32, 27), Pair(41, 29), Pair(33, 33), Pair(48, 23), Pair(27, 25), Pair(36, 0),
    Pair(5, 6), Pair(13, 12), Pair(29, 28), Pair(36, 28), Pair(38, 31), Pair(42, 20), Pair(38, 9), Pair(21, 11),
    Pair(-8, -16), Pair(12, 5), Pair(17, 14), Pair(26, 26), Pair(31, 21), Pair(26, 10), Pair(30, -1), Pair(2, -5),
    Pair(-20, -10), Pair(-3, 6), Pair(6, -7), Pair(15, 7), Pair(21, 0), Pair(20, -8), Pair(9, 3), Pair(0, -4),
    Pair(-49, -25), Pair(-10, -13), Pair(-5, -11), Pair(3, 5), Pair(15, -3), Pair(-1, -8), Pair(-6, -8), Pair(-19, -19)
  },
  {
    Pair(-46, 8), Pair(-63, 22), Pair(-94, 32), Pair(-92, 30), Pair(-69, 32), Pair(-138, 41), Pair(-42, 26), Pair(-64, 18),
    Pair(-29, 2), Pair(-23, 20), Pair(-10, 16), Pair(-27, 29), Pair(-23, 28), Pair(3, 20), Pair(-20, 18), Pair(-27, 1),
    Pair(-8, 5), Pair(12, 12), Pair(4, 23), Pair(27, 9), Pair(31, 12), Pair(35, 19), Pair(24, 14), Pair(14, 1),
    Pair(-10, 2), Pair(11, 11), Pair(14, 16), Pair(25, 15), Pair(19, 16), Pair(23, 13), Pair(11, 10), Pair(6, -1),
    Pair(5, 1), Pair(-2, 7), Pair(12, 8), Pair(12, 11), Pair(18, 7), Pair(11, 11), Pair(4, 2), Pair(11, -2),
    Pair(-2, 3), Pair(24, 4), Pair(14, 8), Pair(12, 14), Pair(11, 15), Pair(20, 4), Pair(22, 2), Pair(-1, 6),
    Pair(21, 5), Pair(17, -9), Pair(17, -6), Pair(4, 2), Pair(15, -3), Pair(15, -7), Pair(26, -9), Pair(25, -21),
    Pair(16, -6), Pair(19, -10), Pair(-2, -2), Pair(-8, -4), Pair(7, -5), Pair(-7, 1), Pair(16, -12), Pair(0, -3)
  },
  {
    Pair(26, 34), Pair(27, 37), Pair(22, 43), Pair(39, 31), Pair(30, 32), Pair(26, 38), Pair(4, 47), Pair(30, 29),
    Pair(-3, 45), Pair(0, 46), Pair(18, 42), Pair(37, 37), Pair(41, 30), Pair(44, 28), Pair(-23, 53), Pair(6, 33),
    Pair(-2, 43), Pair(23, 31), Pair(19, 37), Pair(36, 27), Pair(53, 17), Pair(53, 25), Pair(24, 35), Pair(10, 29),
    Pair(-10, 40), Pair(2, 41), Pair(12, 37), Pair(21, 33), Pair(35, 24), Pair(25, 33), Pair(2, 38), Pair(7, 23),
    Pair(-26, 35), Pair(-22, 40), Pair(-14, 41), Pair(-8, 37), Pair(-4, 27), Pair(-12, 37), Pair(-18, 37), Pair(-22, 23),
    Pair(-30, 21), Pair(-17, 22), Pair(-21, 29), Pair(-17, 26), Pair(-8, 17), Pair(-19, 28), Pair(-12, 15), Pair(-23, 15),
    Pair(-42, 22), Pair(-22, 13), Pair(-17, 20), Pair(-12, 14), Pair(-4, 7), Pair(-9, 9), Pair(-23, 8), Pair(-48, 9),
    Pair(-18, 14), Pair(-13, 10), Pair(-15, 20), Pair(-4, 10), Pair(1, 3), Pair(-7, 11), Pair(-33, 23), Pair(-3, -11)
  },
  {
    Pair(-22, 79), Pair(6, 63), Pair(27, 52), Pair(1, 72), Pair(-1, 81), Pair(21, 67), Pair(6, 80), Pair(-1, 86),
    Pair(-38, 94), Pair(-39, 103), Pair(-26, 112), Pair(-13, 107), Pair(-24, 119), Pair(16, 78), Pair(-6, 88), Pair(-10, 88),
    Pair(-29, 75), Pair(-19, 99), Pair(-15, 105), Pair(1, 103), Pair(7, 104), Pair(28, 96), Pair(24, 86), Pair(1, 76),
    Pair(-8, 45), Pair(-9, 83), Pair(-15, 102), Pair(-5, 104), Pair(6, 102), Pair(15, 84), Pair(7, 94), Pair(19, 38),
    Pair(-10, 53), Pair(-18, 81), Pair(-7, 88), Pair(-18, 122), Pair(1, 80), Pair(-4, 82), Pair(8, 58), Pair(1, 57),
    Pair(-20, 53), Pair(-8, 59), Pair(-4, 66), Pair(-7, 66), Pair(-4, 70), Pair(3, 53), Pair(13, 35), Pair(9, 20),
    Pair(-12, 34), Pair(-7, 29), Pair(1, 21), Pair(-1, 36), Pair(4, 30), Pair(10, 4), Pair(13, -15), Pair(15, -3),
    Pair(-8, 22), Pair(-17, 24), Pair(-9, 2), Pair(-6, 11), Pair(1, 1), Pair(-8, -24), Pair(-20, 0), Pair(6, 9)
  },
  {
    Pair(-10, -78), Pair(53, 12), Pair(29, 21), Pair(111, -6), Pair(37, 11), Pair(41, 9), Pair(106, -11), Pair(157, -150),
    Pair(30, -12), Pair(33, 51), Pair(90, 23), Pair(45, 36), Pair(53, 21), Pair(88, 23), Pair(89, 19), Pair(-14, -7),
    Pair(17, 5), Pair(60, 27), Pair(40, 39), Pair(7, 43), Pair(34, 29), Pair(70, 22), Pair(37, 30), Pair(71, -20),
    Pair(-10, -6), Pair(49, 9), Pair(22, 28), Pair(-25, 41), Pair(-16, 35), Pair(36, 16), Pair(42, 3), Pair(-17, -18),
    Pair(-32, -19), Pair(7, 2), Pair(-6, 18), Pair(-51, 38), Pair(-65, 37), Pair(-12, 12), Pair(0, -4), Pair(-25, -32),
    Pair(-16, -32), Pair(7, -9), Pair(-33, 13), Pair(-48, 27), Pair(-46, 25), Pair(-37, 12), Pair(-1, -13), Pair(-27, -30),
    Pair(33, -44), Pair(5, -11), Pair(-25, 5), Pair(-49, 17), Pair(-47, 17), Pair(-37, 7), Pair(-4, -16), Pair(19, -44),
    Pair(26, -71), Pair(43, -45), Pair(23, -29), Pair(-54, -3), Pair(-10, -28), Pair(-40, -12), Pair(29, -41), Pair(34, -81)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-18, -62), Pair(-3, -8), Pair(4, 18), Pair(9, 30), Pair(12, 37), Pair(16, 42), Pair(20, 41), Pair(25, 34),
  Pair(28, 27)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-19, -51), Pair(-9, -24), Pair(-2, -11), Pair(3, 1), Pair(7, 9), Pair(9, 17), Pair(11, 19), Pair(13, 21),
  Pair(14, 22), Pair(16, 20), Pair(24, 17), Pair(35, 11), Pair(33, 17), Pair(75, 1)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-38, -73), Pair(-29, -31), Pair(-26, -13), Pair(-19, 2), Pair(-17, 6), Pair(-14, 13), Pair(-10, 16), Pair(-5, 17),
  Pair(-1, 22), Pair(4, 24), Pair(9, 25), Pair(14, 27), Pair(19, 25), Pair(30, 20), Pair(40, 16)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-18, -26), Pair(-16, -7), Pair(-11, -27), Pair(-7, -2), Pair(-7, 19), Pair(-7, 44), Pair(-6, 52), Pair(-3, 62),
  Pair(-2, 71), Pair(1, 78), Pair(1, 85), Pair(3, 87), Pair(6, 86), Pair(6, 89), Pair(6, 95), Pair(4, 93),
  Pair(8, 87), Pair(12, 80), Pair(10, 78), Pair(23, 61), Pair(36, 39), Pair(51, 17), Pair(81, -19), Pair(97, -43),
  Pair(99, -45), Pair(186, -120), Pair(241, -176), Pair(136, -90)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-9, -57), Pair(-13, -49), Pair(-3, -20), Pair(18, 7), Pair(41, 49), Pair(47, 47), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(4, 6), Pair(10, 6), Pair(15, 12), Pair(34, 53), Pair(151, 104), Pair(232, 385), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(16, 10), Pair(12, 6), Pair(14, 14), Pair(38, 40), Pair(164, 54), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-41, -35), Pair(-7, -27), Pair(-14, -15), Pair(-24, -2), Pair(-15, -1), Pair(-18, -7), Pair(-5, -25), Pair(-21, -37)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(5, 0), Pair(-6, -9), Pair(-3, -10), Pair(-13, -14), Pair(-12, -12), Pair(-3, -12), Pair(-13, -4), Pair(0, 1)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
    Pair(19, -7), Pair(18, 0), Pair(22, 0), Pair(24, -3), Pair(26, 2), Pair(31, -1), Pair(50, -10), Pair(31, 1)
  },
  {
    Pair(15, 23), Pair(14, 8), Pair(21, -3), Pair(18, -1), Pair(20, -2), Pair(17, -5), Pair(46, -14), Pair(16, 18)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -1), Pair(10, -3), Pair(13, 0),
  Pair(15, -2), Pair(14, -5), Pair(16, -3),
  Pair(27, -2), Pair(0, 0), Pair(25, -2),
  Pair(-2, 6), Pair(-7, 0), Pair(-5, 8)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, 1), Pair(-15, 6), Pair(-7, 1),
  Pair(-9, 2), Pair(-20, 7), Pair(-9, 0),
  Pair(2, -9), Pair(-8, -2), Pair(2, -9),
  Pair(13, -8), Pair(-11, -1), Pair(13, -9),
  Pair(27, -15), Pair(21, -3), Pair(24, -14),
  Pair(0, 0), Pair(-26, -16), Pair(0, 0),
  Pair(36, -43), Pair(0, 0), Pair(29, -42)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(0, 51), Pair(-10, 43), Pair(-8, 27), Pair(-7, 19), Pair(-6, 19), Pair(10, 16), Pair(-3, 13)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-49, -9), Pair(-9, 9), Pair(-7, 29), Pair(2, 34), Pair(2, 41), Pair(1, 43), Pair(-14, 48)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-417, 94);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
    Pair(-63, -1), Pair(-52, -3), Pair(-26, -9), Pair(-13, -13), Pair(-17, -10), Pair(-29, -4), Pair(-49, 3), Pair(-44, 6)
  },
  {
    Pair(-42, 53), Pair(-32, 25), Pair(-15, 9), Pair(-18, 0), Pair(-11, -4), Pair(-17, 10), Pair(-17, 19), Pair(-33, 44)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(10, 2), Pair(21, -3), Pair(70, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(7, 2), Pair(23, 1), Pair(46, -7), Pair(20, -16), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(18, -16), Pair(27, -16), Pair(45, -12), Pair(61, -11), Pair(48, -10), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(3, 21), Pair(10, 33), Pair(26, 35), Pair(75, 13), Pair(132, -15), Pair(218, -57), Pair(245, -79)
  },
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(22, 4), Pair(7, 19), Pair(45, -7), Pair(15, 15), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
    Pair(-10, 50), Pair(-3, 51)
  },
  {
    Pair(-63, -28), Pair(-54, -31)
  },
  {
    Pair(-48, -52), Pair(-51, -54)
  },
  {
    Pair(-77, -30), Pair(-51, -29)
  },
  {
    Pair(-42, 3), Pair(-48, 0)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 29), Pair(18, 22), Pair(21, 16), Pair(18, 1), Pair(32, 3)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
    Pair(-4, -24), Pair(6, -11)
  },
  {
    Pair(19, -82), Pair(24, -95)
  },
  {
    Pair(-39, -12), Pair(-32, -26)
  },
  {
    Pair(-66, 8), Pair(-53, -10)
  },
  {
    Pair(-39, -3), Pair(-36, -24)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
    Pair(-14, -20), Pair(-1, -3)
  },
  {
    Pair(-43, -12), Pair(-15, -32)
  },
  {
    Pair(13, -94), Pair(21, -105)
  },
  {
    Pair(-48, -18), Pair(-45, -38)
  },
  {
    Pair(-42, -48), Pair(-31, -66)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
    Pair(-6, -23), Pair(11, -12)
  },
  {
    Pair(-39, -20), Pair(-6, -18)
  },
  {
    Pair(-36, -20), Pair(-11, -12)
  },
  {
    Pair(3, -8), Pair(12, 4)
  },
  {
    Pair(-68, 4), Pair(-46, -36)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(8, 16), Pair(15, 8), Pair(17, 20), Pair(19, 16), Pair(12, 22), Pair(8, 22), Pair(14, 39), Pair(16, 30),
  Pair(14, 3), Pair(7, 12), Pair(11, 20), Pair(6, 26), Pair(8, 24), Pair(-1, 21), Pair(12, 5), Pair(13, 9),
  Pair(13, 3), Pair(4, 19), Pair(1, 14), Pair(5, 17), Pair(-2, 21), Pair(1, 12), Pair(-4, 16), Pair(4, -3)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-40, 44), Pair(23, 15), Pair(37, -3), Pair(14, 4), Pair(35, -9), Pair(25, 5), Pair(14, 17), Pair(21, -13),
  Pair(-33, 16), Pair(12, 14), Pair(9, 0), Pair(11, 12), Pair(12, 11), Pair(17, 2), Pair(16, 8), Pair(-4, 3),
  Pair(-11, 9), Pair(6, 10), Pair(-2, 29), Pair(11, 19), Pair(13, 19), Pair(-4, 20), Pair(13, 4), Pair(6, -25)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 48);

constexpr ScorePair kTempoBonus = Pair(16, 6);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H