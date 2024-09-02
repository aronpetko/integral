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
  Pair(100, 127), Pair(361, 249), Pair(374, 272), Pair(514, 491), Pair(1190, 823), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
    Pair(73, 60), Pair(27, 82), Pair(48, 60), Pair(100, 29), Pair(84, 42), Pair(46, 63), Pair(-15, 91), Pair(8, 74),
    Pair(-16, -7), Pair(-6, -7), Pair(-7, -22), Pair(17, -47), Pair(13, -42), Pair(22, -28), Pair(0, -2), Pair(-2, -14),
    Pair(-23, -17), Pair(-12, -18), Pair(-17, -29), Pair(-5, -44), Pair(2, -43), Pair(5, -42), Pair(-6, -22), Pair(-24, -25),
    Pair(-32, -29), Pair(-26, -20), Pair(-16, -39), Pair(-8, -44), Pair(-7, -45), Pair(-2, -43), Pair(-10, -26), Pair(-28, -36),
    Pair(-35, -31), Pair(-24, -30), Pair(-27, -34), Pair(-26, -39), Pair(-20, -39), Pair(-21, -36), Pair(7, -39), Pair(-27, -40),
    Pair(-35, -24), Pair(-14, -26), Pair(-26, -24), Pair(-26, -30), Pair(-24, -28), Pair(3, -36), Pair(11, -33), Pair(-21, -39),
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(-174, -55), Pair(-69, 15), Pair(-148, 51), Pair(-49, 24), Pair(17, 16), Pair(-158, 55), Pair(-25, 5), Pair(-120, -61),
    Pair(-23, -1), Pair(-31, 29), Pair(13, 13), Pair(34, 23), Pair(40, 13), Pair(48, 5), Pair(-16, 19), Pair(-44, 21),
    Pair(-23, 12), Pair(9, 19), Pair(14, 36), Pair(42, 29), Pair(59, 21), Pair(73, 14), Pair(10, 19), Pair(25, -9),
    Pair(11, 19), Pair(16, 26), Pair(25, 37), Pair(36, 40), Pair(27, 41), Pair(48, 31), Pair(23, 38), Pair(31, 9),
    Pair(0, 18), Pair(13, 21), Pair(21, 39), Pair(31, 40), Pair(32, 40), Pair(38, 30), Pair(29, 22), Pair(18, 14),
    Pair(-14, -3), Pair(5, 22), Pair(12, 23), Pair(21, 36), Pair(25, 33), Pair(22, 19), Pair(27, 9), Pair(-2, 6),
    Pair(-22, -2), Pair(-8, 16), Pair(0, 4), Pair(10, 20), Pair(16, 11), Pair(15, 2), Pair(2, 17), Pair(-4, 3),
    Pair(-39, -23), Pair(-15, -9), Pair(-4, 3), Pair(1, 12), Pair(5, 15), Pair(-3, 2), Pair(-10, -2), Pair(-12, -22)
  },
  {
    Pair(-31, 21), Pair(-34, 34), Pair(-70, 49), Pair(-98, 52), Pair(-35, 47), Pair(-153, 64), Pair(-35, 45), Pair(-37, 32),
    Pair(-22, 22), Pair(-4, 34), Pair(2, 32), Pair(-14, 49), Pair(-5, 46), Pair(9, 36), Pair(-4, 36), Pair(-15, 22),
    Pair(3, 28), Pair(19, 29), Pair(14, 40), Pair(35, 31), Pair(42, 29), Pair(50, 35), Pair(25, 32), Pair(22, 22),
    Pair(3, 19), Pair(18, 33), Pair(26, 33), Pair(33, 34), Pair(31, 36), Pair(31, 30), Pair(21, 30), Pair(17, 19),
    Pair(17, 15), Pair(7, 25), Pair(23, 27), Pair(21, 33), Pair(25, 27), Pair(20, 27), Pair(13, 28), Pair(23, 14),
    Pair(6, 24), Pair(34, 19), Pair(24, 28), Pair(21, 31), Pair(19, 34), Pair(29, 22), Pair(30, 21), Pair(10, 25),
    Pair(30, 19), Pair(28, 10), Pair(27, 13), Pair(12, 22), Pair(24, 16), Pair(21, 16), Pair(35, 10), Pair(33, 1),
    Pair(24, 11), Pair(22, 10), Pair(7, 19), Pair(11, 16), Pair(16, 14), Pair(3, 20), Pair(20, 6), Pair(10, 19)
  },
  {
    Pair(34, 45), Pair(30, 53), Pair(35, 53), Pair(36, 46), Pair(33, 47), Pair(35, 50), Pair(5, 61), Pair(35, 44),
    Pair(-2, 59), Pair(3, 59), Pair(21, 56), Pair(42, 50), Pair(42, 45), Pair(44, 42), Pair(-13, 65), Pair(14, 48),
    Pair(-4, 57), Pair(30, 44), Pair(29, 48), Pair(41, 38), Pair(49, 31), Pair(61, 38), Pair(27, 47), Pair(10, 45),
    Pair(-5, 54), Pair(8, 52), Pair(23, 51), Pair(26, 46), Pair(34, 39), Pair(30, 45), Pair(4, 52), Pair(10, 39),
    Pair(-22, 49), Pair(-18, 54), Pair(-11, 53), Pair(-1, 49), Pair(3, 41), Pair(-5, 49), Pair(-14, 51), Pair(-17, 36),
    Pair(-24, 36), Pair(-12, 35), Pair(-13, 43), Pair(-11, 37), Pair(-2, 30), Pair(-12, 39), Pair(-6, 28), Pair(-19, 28),
    Pair(-36, 35), Pair(-22, 30), Pair(-11, 33), Pair(-10, 30), Pair(3, 19), Pair(-1, 20), Pair(-23, 26), Pair(-45, 25),
    Pair(-14, 28), Pair(-8, 24), Pair(-10, 32), Pair(-1, 24), Pair(6, 15), Pair(-1, 23), Pair(-30, 36), Pair(1, 4)
  },
  {
    Pair(-33, 101), Pair(-4, 70), Pair(32, 50), Pair(2, 79), Pair(-1, 87), Pair(41, 50), Pair(8, 70), Pair(1, 92),
    Pair(-41, 97), Pair(-45, 108), Pair(-29, 116), Pair(-10, 102), Pair(-29, 120), Pair(11, 88), Pair(-13, 115), Pair(-14, 107),
    Pair(-31, 72), Pair(-21, 102), Pair(-13, 95), Pair(2, 101), Pair(8, 107), Pair(13, 117), Pair(21, 85), Pair(5, 71),
    Pair(-13, 60), Pair(-7, 88), Pair(-15, 104), Pair(-8, 110), Pair(3, 108), Pair(15, 71), Pair(13, 80), Pair(19, 46),
    Pair(-8, 53), Pair(-14, 71), Pair(-7, 88), Pair(-19, 124), Pair(-1, 86), Pair(-1, 84), Pair(10, 65), Pair(0, 59),
    Pair(-19, 43), Pair(-6, 62), Pair(-6, 69), Pair(-5, 63), Pair(-5, 74), Pair(5, 53), Pair(13, 39), Pair(13, 16),
    Pair(-3, 27), Pair(-3, 22), Pair(3, 16), Pair(3, 34), Pair(6, 30), Pair(13, -3), Pair(14, -12), Pair(12, -20),
    Pair(-9, 22), Pair(-10, 11), Pair(-5, 2), Pair(-5, 13), Pair(4, 1), Pair(-9, -12), Pair(-13, -3), Pair(14, -5)
  },
  {
    Pair(-12, -49), Pair(-22, 43), Pair(16, 29), Pair(87, 5), Pair(-14, 24), Pair(95, -7), Pair(18, 12), Pair(85, -107),
    Pair(46, 0), Pair(44, 48), Pair(39, 39), Pair(55, 39), Pair(8, 41), Pair(83, 32), Pair(45, 34), Pair(17, -10),
    Pair(11, 21), Pair(49, 38), Pair(42, 45), Pair(38, 40), Pair(42, 36), Pair(58, 34), Pair(47, 32), Pair(19, -4),
    Pair(13, -1), Pair(49, 15), Pair(-2, 42), Pair(-14, 45), Pair(-17, 40), Pair(28, 24), Pair(35, 11), Pair(-23, -9),
    Pair(-51, -11), Pair(23, 5), Pair(-16, 26), Pair(-65, 44), Pair(-69, 43), Pair(-27, 18), Pair(-8, 4), Pair(-37, -21),
    Pair(-26, -17), Pair(3, -4), Pair(-37, 21), Pair(-54, 34), Pair(-50, 32), Pair(-39, 17), Pair(-3, -7), Pair(-30, -23),
    Pair(35, -35), Pair(4, -5), Pair(-25, 10), Pair(-50, 22), Pair(-52, 21), Pair(-38, 11), Pair(-5, -11), Pair(21, -40),
    Pair(18, -65), Pair(42, -41), Pair(23, -24), Pair(-54, 1), Pair(-11, -23), Pair(-43, -4), Pair(26, -33), Pair(32, -75)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-19, -53), Pair(-4, 6), Pair(2, 29), Pair(8, 40), Pair(12, 46), Pair(16, 52), Pair(19, 50), Pair(25, 45),
  Pair(30, 35)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-18, -39), Pair(-9, -11), Pair(-2, 1), Pair(3, 14), Pair(7, 23), Pair(9, 31), Pair(12, 34), Pair(13, 34),
  Pair(15, 36), Pair(18, 34), Pair(23, 32), Pair(34, 27), Pair(39, 27), Pair(85, 17)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-32, -53), Pair(-25, -16), Pair(-22, 1), Pair(-15, 16), Pair(-13, 21), Pair(-9, 27), Pair(-5, 29), Pair(0, 30),
  Pair(5, 35), Pair(8, 37), Pair(13, 40), Pair(16, 41), Pair(21, 40), Pair(36, 33), Pair(44, 27)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-18, -15), Pair(-15, -26), Pair(-11, -15), Pair(-8, 0), Pair(-9, 35), Pair(-8, 41), Pair(-6, 64), Pair(-4, 71),
  Pair(-3, 83), Pair(-1, 86), Pair(1, 96), Pair(4, 93), Pair(5, 99), Pair(6, 99), Pair(6, 100), Pair(5, 103),
  Pair(6, 99), Pair(14, 86), Pair(17, 79), Pair(24, 69), Pair(44, 43), Pair(53, 21), Pair(80, -9), Pair(85, -25),
  Pair(79, -32), Pair(196, -134), Pair(180, -117), Pair(172, -80)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-13, -81), Pair(-17, -73), Pair(-5, -45), Pair(17, -19), Pair(36, 25), Pair(31, -11), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(4, 7), Pair(9, 7), Pair(15, 14), Pair(34, 48), Pair(138, 94), Pair(271, 454), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(15, 9), Pair(12, 5), Pair(14, 13), Pair(32, 41), Pair(168, 48), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-38, -37), Pair(-7, -21), Pair(-14, -16), Pair(-26, 2), Pair(-15, -2), Pair(-20, -5), Pair(-2, -28), Pair(-20, -35)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(5, -1), Pair(-5, -8), Pair(-4, -13), Pair(-13, -11), Pair(-14, -13), Pair(-6, -9), Pair(-12, -5), Pair(0, 0)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
    Pair(22, -7), Pair(18, 2), Pair(21, 0), Pair(26, -4), Pair(25, 3), Pair(31, -1), Pair(51, -11), Pair(31, 2)
  },
  {
    Pair(13, 24), Pair(12, 9), Pair(21, -1), Pair(18, -1), Pair(20, -3), Pair(15, -3), Pair(48, -15), Pair(17, 16)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -1), Pair(11, -3), Pair(13, -1),
  Pair(15, -2), Pair(15, -6), Pair(15, -3),
  Pair(27, -3), Pair(0, 0), Pair(24, -2),
  Pair(2, 5), Pair(-11, 0), Pair(2, 4)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-15, 6), Pair(-8, 2),
  Pair(-8, 0), Pair(-19, 7), Pair(-9, 1),
  Pair(1, -9), Pair(-7, -4), Pair(2, -8),
  Pair(10, -10), Pair(-11, -2), Pair(13, -9),
  Pair(31, -17), Pair(21, -4), Pair(26, -15),
  Pair(0, 0), Pair(-35, -14), Pair(0, 0),
  Pair(27, -41), Pair(0, 0), Pair(44, -44)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(4, 63), Pair(-4, 54), Pair(-5, 38), Pair(-3, 31), Pair(1, 31), Pair(14, 29), Pair(1, 26)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-50, 5), Pair(-16, 25), Pair(-9, 44), Pair(0, 49), Pair(1, 55), Pair(1, 56), Pair(-19, 63)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-455, 100);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
    Pair(-51, -6), Pair(-52, -2), Pair(-23, -8), Pair(-20, -12), Pair(-17, -10), Pair(-33, -1), Pair(-46, 2), Pair(-46, 4)
  },
  {
    Pair(-41, 45), Pair(-40, 25), Pair(-16, 9), Pair(-20, 0), Pair(-10, -3), Pair(-14, 9), Pair(-16, 19), Pair(-34, 47)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(10, 2), Pair(23, -4), Pair(66, -22), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(7, 3), Pair(24, 1), Pair(41, -6), Pair(3, -18), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(18, -16), Pair(25, -15), Pair(44, -12), Pair(64, -11), Pair(61, -13), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(3, 18), Pair(11, 31), Pair(28, 32), Pair(76, 9), Pair(134, -19), Pair(226, -68), Pair(267, -92)
  },
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(22, 4), Pair(7, 19), Pair(44, -7), Pair(16, 14), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
    Pair(-13, 45), Pair(-4, 46)
  },
  {
    Pair(-62, -27), Pair(-54, -31)
  },
  {
    Pair(-51, -46), Pair(-52, -54)
  },
  {
    Pair(-60, -34), Pair(-54, -41)
  },
  {
    Pair(-43, 11), Pair(-48, 11)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 28), Pair(19, 19), Pair(23, 13), Pair(18, -4), Pair(30, 4)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
    Pair(-5, -24), Pair(6, -10)
  },
  {
    Pair(8, -27), Pair(15, -42)
  },
  {
    Pair(-43, -7), Pair(-33, -27)
  },
  {
    Pair(-69, 9), Pair(-52, -10)
  },
  {
    Pair(-39, -16), Pair(-37, -9)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
    Pair(-14, -21), Pair(-1, -4)
  },
  {
    Pair(-46, -11), Pair(-15, -34)
  },
  {
    Pair(5, -106), Pair(16, -114)
  },
  {
    Pair(-44, -22), Pair(-44, -38)
  },
  {
    Pair(-40, -53), Pair(-31, -66)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
    Pair(-5, -23), Pair(11, -12)
  },
  {
    Pair(-39, -19), Pair(-6, -19)
  },
  {
    Pair(-33, -20), Pair(-13, -11)
  },
  {
    Pair(-7, 2), Pair(1, 16)
  },
  {
    Pair(-64, -7), Pair(-46, -46)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(7, 27), Pair(16, 14), Pair(31, 10), Pair(32, 14), Pair(16, 22), Pair(-1, 22), Pair(25, 37), Pair(4, 44),
  Pair(10, 5), Pair(7, 10), Pair(12, 21), Pair(3, 26), Pair(10, 25), Pair(-8, 28), Pair(13, 1), Pair(10, 12),
  Pair(12, -1), Pair(0, 9), Pair(4, 16), Pair(5, 20), Pair(0, 19), Pair(-1, 15), Pair(-5, 4), Pair(4, -1)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-57, 40), Pair(23, 21), Pair(43, 2), Pair(21, 7), Pair(38, -9), Pair(26, 7), Pair(40, 6), Pair(31, 15),
  Pair(-11, 10), Pair(14, 12), Pair(5, 4), Pair(17, 8), Pair(10, 11), Pair(12, 9), Pair(14, 11), Pair(2, 4),
  Pair(-10, 13), Pair(11, 11), Pair(-1, 27), Pair(11, 21), Pair(15, 21), Pair(-3, 21), Pair(11, 3), Pair(0, -15)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 47);

constexpr ScorePair kTempoBonus = Pair(16, 6);


constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H