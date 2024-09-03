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
  Pair(96, 128), Pair(353, 255), Pair(380, 300), Pair(521, 527), Pair(1182, 849), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), 
    Pair(79, 33), Pair(-2, 68), Pair(58, 32), Pair(105, 9), Pair(63, 22), Pair(40, 44), Pair(-23, 66), Pair(20, 40), 
    Pair(-16, -3), Pair(2, -7), Pair(-2, -21), Pair(25, -50), Pair(15, -44), Pair(22, -22), Pair(3, -8), Pair(0, -14), 
    Pair(-20, -17), Pair(-9, -17), Pair(-16, -29), Pair(-5, -41), Pair(4, -44), Pair(5, -36), Pair(-7, -22), Pair(-19, -23), 
    Pair(-30, -27), Pair(-23, -15), Pair(-11, -40), Pair(-5, -43), Pair(-3, -45), Pair(0, -39), Pair(-12, -25), Pair(-25, -34), 
    Pair(-34, -32), Pair(-23, -25), Pair(-25, -33), Pair(-22, -37), Pair(-18, -38), Pair(-17, -33), Pair(4, -39), Pair(-21, -39), 
    Pair(-32, -24), Pair(-11, -23), Pair(-22, -22), Pair(-22, -27), Pair(-20, -30), Pair(5, -30), Pair(12, -33), Pair(-18, -37), 
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(-173, -74), Pair(-65, 21), Pair(-153, 52), Pair(12, -6), Pair(1, 4), Pair(-221, 57), Pair(-51, 24), Pair(-69, -69), 
    Pair(-24, 5), Pair(-27, 18), Pair(10, 17), Pair(42, 20), Pair(49, 8), Pair(46, 4), Pair(23, 3), Pair(-26, 9), 
    Pair(-15, 11), Pair(21, 16), Pair(17, 34), Pair(40, 22), Pair(61, 15), Pair(83, 3), Pair(12, 20), Pair(29, -3), 
    Pair(10, 13), Pair(16, 24), Pair(20, 37), Pair(38, 35), Pair(25, 41), Pair(50, 27), Pair(23, 30), Pair(28, 7), 
    Pair(0, 10), Pair(6, 20), Pair(23, 35), Pair(28, 39), Pair(30, 41), Pair(39, 27), Pair(31, 12), Pair(14, 16), 
    Pair(-14, -7), Pair(8, 10), Pair(12, 20), Pair(24, 34), Pair(27, 30), Pair(22, 16), Pair(26, 3), Pair(-1, 1), 
    Pair(-19, -10), Pair(-4, 6), Pair(3, 0), Pair(10, 12), Pair(15, 12), Pair(17, 0), Pair(4, 7), Pair(-4, 1), 
    Pair(-42, -39), Pair(-15, -3), Pair(-7, -1), Pair(-4, 8), Pair(8, 7), Pair(-6, 3), Pair(-10, -8), Pair(-6, -31)
  },
  {
    Pair(-62, 26), Pair(-54, 28), Pair(-74, 37), Pair(-118, 45), Pair(-39, 32), Pair(-161, 45), Pair(-55, 39), Pair(-38, 10), 
    Pair(-26, 12), Pair(-8, 22), Pair(-16, 26), Pair(-27, 33), Pair(-18, 35), Pair(0, 24), Pair(-34, 35), Pair(-35, 16), 
    Pair(0, 6), Pair(8, 25), Pair(4, 29), Pair(26, 17), Pair(29, 22), Pair(25, 30), Pair(33, 13), Pair(16, 9), 
    Pair(-5, 7), Pair(11, 20), Pair(8, 25), Pair(25, 24), Pair(18, 31), Pair(30, 22), Pair(12, 20), Pair(10, 6), 
    Pair(7, 10), Pair(-3, 13), Pair(12, 18), Pair(11, 21), Pair(18, 19), Pair(12, 19), Pair(2, 14), Pair(13, 8), 
    Pair(-1, 11), Pair(26, 14), Pair(15, 16), Pair(12, 23), Pair(12, 23), Pair(20, 10), Pair(21, 12), Pair(-2, 19), 
    Pair(17, 10), Pair(20, -5), Pair(18, 5), Pair(3, 11), Pair(15, 6), Pair(18, 2), Pair(26, 1), Pair(21, -15), 
    Pair(23, -6), Pair(12, 2), Pair(-2, 5), Pair(-6, 8), Pair(1, 1), Pair(-7, 14), Pair(20, -8), Pair(1, 5)
  },
  {
    Pair(29, 38), Pair(23, 43), Pair(22, 45), Pair(21, 41), Pair(26, 36), Pair(22, 43), Pair(-1, 52), Pair(43, 31), 
    Pair(-4, 44), Pair(-7, 48), Pair(18, 44), Pair(38, 38), Pair(35, 28), Pair(31, 30), Pair(-33, 55), Pair(0, 40), 
    Pair(-9, 43), Pair(19, 36), Pair(13, 40), Pair(28, 33), Pair(58, 13), Pair(49, 27), Pair(15, 35), Pair(6, 32), 
    Pair(-10, 39), Pair(-4, 43), Pair(10, 40), Pair(20, 39), Pair(31, 24), Pair(16, 37), Pair(-4, 41), Pair(-3, 34), 
    Pair(-29, 35), Pair(-23, 42), Pair(-20, 45), Pair(-9, 41), Pair(-10, 35), Pair(-10, 34), Pair(-19, 41), Pair(-24, 29), 
    Pair(-30, 21), Pair(-21, 24), Pair(-20, 33), Pair(-14, 31), Pair(-10, 21), Pair(-22, 28), Pair(-18, 23), Pair(-26, 17), 
    Pair(-41, 25), Pair(-25, 12), Pair(-22, 24), Pair(-13, 21), Pair(-7, 10), Pair(-12, 12), Pair(-32, 16), Pair(-52, 17), 
    Pair(-20, 15), Pair(-17, 10), Pair(-17, 21), Pair(-6, 14), Pair(-2, 4), Pair(-11, 15), Pair(-34, 24), Pair(-5, -7)
  },
  {
    Pair(-26, 78), Pair(33, 47), Pair(46, 39), Pair(16, 79), Pair(3, 93), Pair(75, 36), Pair(15, 87), Pair(2, 84), 
    Pair(-32, 85), Pair(-40, 104), Pair(-27, 116), Pair(-10, 103), Pair(-35, 130), Pair(21, 80), Pair(-26, 127), Pair(-13, 97), 
    Pair(-20, 71), Pair(-25, 104), Pair(-9, 106), Pair(-3, 106), Pair(17, 100), Pair(19, 108), Pair(23, 93), Pair(-1, 83), 
    Pair(-14, 49), Pair(-6, 84), Pair(-17, 100), Pair(-6, 111), Pair(4, 112), Pair(10, 93), Pair(7, 91), Pair(20, 33), 
    Pair(-9, 56), Pair(-13, 70), Pair(-9, 95), Pair(-21, 126), Pair(-3, 93), Pair(-5, 87), Pair(7, 72), Pair(1, 57), 
    Pair(-15, 45), Pair(-2, 53), Pair(-5, 71), Pair(-7, 71), Pair(-6, 73), Pair(1, 63), Pair(10, 49), Pair(11, 26), 
    Pair(-11, 30), Pair(-9, 33), Pair(1, 23), Pair(-5, 48), Pair(4, 34), Pair(6, 5), Pair(16, -11), Pair(11, -6), 
    Pair(-12, 22), Pair(-21, 23), Pair(-9, -1), Pair(-6, 17), Pair(1, 1), Pair(-17, -3), Pair(-22, 1), Pair(14, -15)
  },
  {
    Pair(-10, -67), Pair(71, -6), Pair(168, -11), Pair(205, -39), Pair(105, -11), Pair(-2, 19), Pair(193, -46), Pair(176, -115), 
    Pair(6, -11), Pair(108, 20), Pair(53, 39), Pair(91, 10), Pair(96, 5), Pair(76, 9), Pair(74, 21), Pair(38, -36), 
    Pair(14, 3), Pair(54, 25), Pair(27, 36), Pair(16, 34), Pair(55, 23), Pair(43, 22), Pair(93, 13), Pair(-32, 1), 
    Pair(44, -17), Pair(22, 11), Pair(7, 30), Pair(-19, 35), Pair(-37, 32), Pair(23, 14), Pair(51, 0), Pair(-29, -17), 
    Pair(-61, -16), Pair(-6, -4), Pair(-27, 15), Pair(-70, 36), Pair(-55, 31), Pair(-17, 7), Pair(-16, -5), Pair(-58, -31), 
    Pair(-35, -24), Pair(-2, -17), Pair(-46, 8), Pair(-66, 26), Pair(-50, 20), Pair(-36, 5), Pair(-6, -17), Pair(-36, -32), 
    Pair(31, -44), Pair(-3, -15), Pair(-34, 3), Pair(-52, 14), Pair(-53, 11), Pair(-43, 3), Pair(-7, -19), Pair(11, -46), 
    Pair(22, -79), Pair(35, -51), Pair(20, -34), Pair(-57, -7), Pair(-15, -32), Pair(-45, -16), Pair(24, -43), Pair(31, -91)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-12, -49), Pair(1, 8), Pair(8, 36), Pair(12, 47), Pair(16, 54), Pair(20, 58), Pair(23, 56), Pair(29, 48), 
  Pair(28, 41)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-18, -44), Pair(-9, -20), Pair(-1, -7), Pair(4, 4), Pair(7, 16), Pair(9, 22), Pair(12, 25), Pair(14, 26), 
  Pair(16, 28), Pair(16, 28), Pair(22, 20), Pair(33, 20), Pair(32, 24), Pair(99, 5)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-38, -72), Pair(-30, -23), Pair(-26, -9), Pair(-19, 4), Pair(-16, 9), Pair(-14, 17), Pair(-11, 19), Pair(-5, 20), 
  Pair(0, 23), Pair(6, 25), Pair(8, 28), Pair(12, 30), Pair(22, 26), Pair(29, 22), Pair(34, 21)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-26, -63), Pair(-20, -67), Pair(-17, -14), Pair(-14, 22), Pair(-13, 12), Pair(-14, 47), Pair(-11, 56), Pair(-10, 64), 
  Pair(-8, 75), Pair(-7, 83), Pair(-5, 92), Pair(-4, 91), Pair(-3, 99), Pair(-2, 99), Pair(0, 101), Pair(0, 95), 
  Pair(4, 89), Pair(9, 83), Pair(14, 75), Pair(20, 65), Pair(29, 50), Pair(73, 4), Pair(74, -2), Pair(116, -54), 
  Pair(132, -73), Pair(180, -116), Pair(192, -113), Pair(172, -57)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-3, -55), Pair(-5, -45), Pair(5, -18), Pair(25, 11), Pair(47, 55), Pair(41, 48), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(4, 6), Pair(9, 7), Pair(15, 15), Pair(36, 51), Pair(139, 101), Pair(201, 463), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(16, 10), Pair(12, 6), Pair(16, 12), Pair(34, 43), Pair(168, 56), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-33, -41), Pair(-7, -26), Pair(-14, -17), Pair(-24, 3), Pair(-14, -1), Pair(-17, -9), Pair(-2, -24), Pair(-23, -37)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(4, 2), Pair(-7, -9), Pair(-4, -11), Pair(-13, -13), Pair(-11, -14), Pair(-4, -11), Pair(-10, -2), Pair(-3, 2)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
    Pair(18, -4), Pair(18, 2), Pair(20, -1), Pair(22, -4), Pair(25, 5), Pair(36, -2), Pair(52, -11), Pair(35, -3)
  },
  {
    Pair(11, 25), Pair(12, 9), Pair(21, -1), Pair(18, -3), Pair(18, 1), Pair(17, -4), Pair(45, -15), Pair(19, 13)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(11, 0), Pair(10, -1), Pair(10, 1), 
  Pair(16, -2), Pair(15, -4), Pair(16, -4), 
  Pair(27, -1), Pair(0, 0), Pair(26, -1), 
  Pair(-2, 7), Pair(-8, 4), Pair(-4, 9)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-9, 2), Pair(-14, 5), Pair(-8, 3), 
  Pair(-10, 2), Pair(-18, 6), Pair(-9, 2), 
  Pair(0, -7), Pair(-7, -3), Pair(1, -7), 
  Pair(13, -9), Pair(-9, -2), Pair(12, -8), 
  Pair(30, -17), Pair(21, -3), Pair(22, -14), 
  Pair(0, 0), Pair(-27, -18), Pair(0, 0), 
  Pair(45, -44), Pair(0, 0), Pair(27, -38)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-10, 43), Pair(-19, 32), Pair(-17, 17), Pair(-14, 9), Pair(-17, 9), Pair(-2, 5), Pair(-3, -1)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-40, -6), Pair(-9, 16), Pair(-4, 35), Pair(1, 43), Pair(6, 48), Pair(4, 49), Pair(-14, 55)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-425, 84);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
    Pair(-52, -7), Pair(-69, 5), Pair(-24, -8), Pair(-19, -12), Pair(-18, -7), Pair(-32, -1), Pair(-47, 3), Pair(-58, 11)
  },
  {
    Pair(-34, 49), Pair(-29, 26), Pair(-14, 10), Pair(-15, 0), Pair(-8, -5), Pair(-17, 14), Pair(-18, 20), Pair(-35, 46)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(10, 2), Pair(18, -2), Pair(76, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(7, 3), Pair(23, 0), Pair(42, -6), Pair(41, -30), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(16, -14), Pair(28, -16), Pair(45, -11), Pair(58, -8), Pair(66, -12), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(1, 19), Pair(10, 29), Pair(25, 32), Pair(81, 2), Pair(127, -19), Pair(222, -57), Pair(246, -75)
  },
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(23, 3), Pair(6, 20), Pair(43, -8), Pair(15, 15), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
    Pair(-8, 33), Pair(-1, 34)
  },
  {
    Pair(-65, -30), Pair(-51, -42)
  },
  {
    Pair(-52, -38), Pair(-53, -54)
  },
  {
    Pair(-83, -22), Pair(-56, -28)
  },
  {
    Pair(-27, -26), Pair(-53, 19)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(12, 26), Pair(17, 21), Pair(19, 15), Pair(20, -11), Pair(39, 3)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
    Pair(-6, -22), Pair(6, -10)
  },
  {
    Pair(-1, -50), Pair(15, -68)
  },
  {
    Pair(-44, -12), Pair(-31, -28)
  },
  {
    Pair(-74, 8), Pair(-51, -9)
  },
  {
    Pair(-48, 3), Pair(-37, -1)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
    Pair(-13, -20), Pair(0, -5)
  },
  {
    Pair(-42, -12), Pair(-14, -34)
  },
  {
    Pair(16, -63), Pair(20, -77)
  },
  {
    Pair(-43, -22), Pair(-48, -35)
  },
  {
    Pair(-53, -29), Pair(-24, -82)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
    Pair(-7, -23), Pair(11, -12)
  },
  {
    Pair(-48, -17), Pair(-8, -18)
  },
  {
    Pair(-37, -18), Pair(-13, -10)
  },
  {
    Pair(0, -13), Pair(7, 7)
  },
  {
    Pair(-65, -7), Pair(-47, -33)
  },
  {
    Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(12, -9), Pair(-8, 21), Pair(29, 14), Pair(39, 11), Pair(12, 26), Pair(-5, 39), Pair(31, 15), Pair(-31, 36), 
  Pair(16, 24), Pair(9, 9), Pair(19, 16), Pair(2, 28), Pair(14, 25), Pair(-9, 29), Pair(11, 4), Pair(2, 7), 
  Pair(12, 9), Pair(9, 17), Pair(2, 13), Pair(9, 17), Pair(1, 17), Pair(2, 10), Pair(-8, 21), Pair(6, -2)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-31, 9), Pair(30, 6), Pair(36, 6), Pair(31, -8), Pair(32, -8), Pair(49, 3), Pair(9, 32), Pair(34, 9), 
  Pair(5, -4), Pair(10, 12), Pair(18, -3), Pair(15, 10), Pair(12, 5), Pair(12, 1), Pair(11, 11), Pair(-14, 19), 
  Pair(1, 10), Pair(2, 17), Pair(2, 21), Pair(14, 20), Pair(12, 18), Pair(-4, 13), Pair(12, 3), Pair(-1, -19)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 48);

constexpr ScorePair kTempoBonus = Pair(16, 6);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H