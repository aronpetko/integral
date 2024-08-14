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
  Pair(83, 115), Pair(377, 159), Pair(393, 193), Pair(520, 482), Pair(1221, 963), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(178, 82), Pair(138, 105), Pair(139, 97), Pair(160, 71), Pair(157, 79), Pair(123, 99), Pair(81, 115), Pair(143, 82),
      Pair(10, 18), Pair(3, 24), Pair(18, -4), Pair(33, -24), Pair(33, -19), Pair(52, -15), Pair(9, 18), Pair(12, 13),
      Pair(-6, 6), Pair(0, 7), Pair(3, -15), Pair(11, -26), Pair(24, -27), Pair(24, -26), Pair(8, -4), Pair(-1, -3),
      Pair(-15, -5), Pair(-15, 5), Pair(0, -18), Pair(11, -22), Pair(14, -27), Pair(17, -23), Pair(4, -9), Pair(-4, -13),
      Pair(-21, -8), Pair(-19, 0), Pair(-15, -13), Pair(-9, -16), Pair(-3, -17), Pair(-6, -17), Pair(7, -17), Pair(-5, -18),
      Pair(-15, -1), Pair(-6, 4), Pair(-9, -4), Pair(-12, -6), Pair(-4, -6), Pair(17, -13), Pair(20, -13), Pair(-3, -16),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-151, 43), Pair(-25, 53), Pair(-55, 61), Pair(32, 55), Pair(45, 52), Pair(-115, 76), Pair(-26, 61), Pair(-50, -1),
      Pair(-1, 53), Pair(-6, 81), Pair(29, 71), Pair(65, 68), Pair(62, 71), Pair(59, 56), Pair(3, 73), Pair(-1, 62),
      Pair(18, 61), Pair(26, 74), Pair(33, 88), Pair(53, 80), Pair(70, 69), Pair(77, 70), Pair(27, 80), Pair(35, 47),
      Pair(23, 76), Pair(27, 87), Pair(41, 85), Pair(50, 96), Pair(44, 99), Pair(59, 88), Pair(35, 86), Pair(40, 72),
      Pair(13, 79), Pair(34, 79), Pair(37, 95), Pair(41, 95), Pair(41, 99), Pair(54, 86), Pair(43, 81), Pair(25, 82),
      Pair(-6, 63), Pair(16, 74), Pair(20, 80), Pair(33, 93), Pair(36, 88), Pair(30, 77), Pair(33, 69), Pair(10, 68),
      Pair(-14, 61), Pair(4, 78), Pair(11, 69), Pair(20, 77), Pair(24, 75), Pair(20, 64), Pair(10, 72), Pair(6, 66),
      Pair(-55, 69), Pair(-10, 60), Pair(-10, 66), Pair(3, 74), Pair(20, 68), Pair(8, 61), Pair(-7, 70), Pair(-29, 57)
  },
  {
      Pair(-31, 93), Pair(-46, 92), Pair(-55, 89), Pair(-81, 93), Pair(-30, 84), Pair(-115, 90), Pair(-42, 88), Pair(-30, 79),
      Pair(-14, 77), Pair(-9, 95), Pair(1, 87), Pair(3, 86), Pair(-17, 83), Pair(3, 82), Pair(-31, 97), Pair(-7, 68),
      Pair(6, 85), Pair(12, 88), Pair(7, 95), Pair(27, 76), Pair(35, 78), Pair(36, 93), Pair(20, 92), Pair(23, 80),
      Pair(5, 74), Pair(13, 83), Pair(12, 87), Pair(28, 91), Pair(20, 91), Pair(33, 85), Pair(10, 86), Pair(11, 78),
      Pair(18, 67), Pair(3, 81), Pair(17, 84), Pair(15, 91), Pair(25, 81), Pair(16, 81), Pair(13, 80), Pair(15, 66),
      Pair(8, 74), Pair(26, 80), Pair(18, 88), Pair(19, 89), Pair(16, 92), Pair(28, 82), Pair(27, 75), Pair(18, 74),
      Pair(24, 69), Pair(20, 66), Pair(24, 65), Pair(11, 80), Pair(22, 76), Pair(29, 65), Pair(34, 65), Pair(20, 55),
      Pair(9, 54), Pair(23, 75), Pair(5, 78), Pair(7, 76), Pair(16, 72), Pair(1, 81), Pair(10, 54), Pair(17, 57)
  },
  {
      Pair(55, 57), Pair(50, 69), Pair(30, 82), Pair(41, 75), Pair(50, 72), Pair(58, 73), Pair(56, 69), Pair(36, 64),
      Pair(22, 68), Pair(28, 70), Pair(40, 68), Pair(65, 60), Pair(53, 56), Pair(60, 57), Pair(19, 70), Pair(9, 67),
      Pair(20, 67), Pair(51, 57), Pair(37, 61), Pair(62, 45), Pair(71, 43), Pair(69, 53), Pair(51, 55), Pair(11, 61),
      Pair(11, 64), Pair(30, 64), Pair(38, 63), Pair(44, 49), Pair(45, 49), Pair(44, 55), Pair(28, 62), Pair(15, 57),
      Pair(-7, 64), Pair(10, 65), Pair(11, 66), Pair(10, 64), Pair(16, 55), Pair(4, 66), Pair(2, 63), Pair(-6, 57),
      Pair(-7, 49), Pair(6, 51), Pair(-7, 63), Pair(3, 53), Pair(8, 46), Pair(1, 54), Pair(15, 38), Pair(2, 36),
      Pair(-14, 41), Pair(2, 45), Pair(7, 46), Pair(6, 47), Pair(16, 36), Pair(11, 41), Pair(7, 30), Pair(-25, 35),
      Pair(1, 44), Pair(7, 42), Pair(8, 48), Pair(19, 37), Pair(23, 29), Pair(18, 40), Pair(0, 43), Pair(5, 32)
  },
  {
      Pair(-20, 30), Pair(16, 23), Pair(13, 36), Pair(22, 31), Pair(38, 24), Pair(66, 7), Pair(20, 34), Pair(-1, 48),
      Pair(-13, 33), Pair(-32, 71), Pair(-9, 69), Pair(-23, 92), Pair(-29, 89), Pair(10, 53), Pair(3, 59), Pair(22, 26),
      Pair(-4, 3), Pair(3, 31), Pair(-4, 61), Pair(3, 60), Pair(5, 85), Pair(19, 69), Pair(35, 27), Pair(19, 5),
      Pair(5, -2), Pair(-1, 42), Pair(-3, 61), Pair(-4, 72), Pair(3, 64), Pair(20, 44), Pair(5, 42), Pair(26, -6),
      Pair(0, -2), Pair(-13, 33), Pair(-2, 37), Pair(-8, 66), Pair(4, 46), Pair(1, 41), Pair(10, 27), Pair(2, 17),
      Pair(1, -18), Pair(5, -6), Pair(0, 18), Pair(3, 11), Pair(2, 27), Pair(11, 12), Pair(15, 2), Pair(7, -11),
      Pair(5, -45), Pair(9, -48), Pair(12, -37), Pair(11, -18), Pair(12, -15), Pair(20, -53), Pair(26, -83), Pair(8, -44),
      Pair(8, -58), Pair(1, -55), Pair(1, -45), Pair(4, -39), Pair(7, -54), Pair(-1, -79), Pair(4, -81), Pair(14, -34)
  },
  {
      Pair(90, -180), Pair(193, -9), Pair(235, 0), Pair(98, 17), Pair(83, 4), Pair(147, -3), Pair(202, -20), Pair(210, -216),
      Pair(69, 7), Pair(140, 62), Pair(112, 63), Pair(108, 47), Pair(88, 48), Pair(-14, 116), Pair(102, 70), Pair(34, -23),
      Pair(-31, 56), Pair(68, 73), Pair(32, 89), Pair(-57, 100), Pair(-53, 112), Pair(57, 88), Pair(84, 70), Pair(62, 20),
      Pair(-1, 35), Pair(85, 45), Pair(-24, 81), Pair(-70, 97), Pair(-75, 94), Pair(15, 70), Pair(49, 44), Pair(-27, 19),
      Pair(-27, 25), Pair(23, 42), Pair(-2, 68), Pair(-47, 87), Pair(-36, 79), Pair(-16, 63), Pair(34, 35), Pair(-57, 22),
      Pair(-19, 33), Pair(39, 38), Pair(-12, 64), Pair(-25, 76), Pair(-29, 77), Pair(-5, 61), Pair(12, 44), Pair(-24, 31),
      Pair(53, 6), Pair(26, 40), Pair(15, 53), Pair(-12, 66), Pair(-13, 65), Pair(3, 55), Pair(25, 37), Pair(45, 4),
      Pair(40, -17), Pair(62, 12), Pair(50, 27), Pair(-15, 47), Pair(27, 21), Pair(1, 38), Pair(55, 14), Pair(58, -25)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-30, 3), Pair(-10, 37), Pair(0, 61), Pair(6, 72), Pair(10, 79), Pair(14, 88), Pair(18, 87), Pair(21, 86),
  Pair(22, 81)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-19, -5), Pair(-4, 17), Pair(4, 28), Pair(10, 39), Pair(14, 49), Pair(18, 56), Pair(20, 59), Pair(22, 62),
  Pair(22, 68), Pair(26, 67), Pair(34, 64), Pair(36, 66), Pair(43, 63), Pair(58, 59)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-31, -25), Pair(-16, 0), Pair(-10, 7), Pair(-5, 21), Pair(-4, 30), Pair(0, 34), Pair(3, 38), Pair(8, 39),
  Pair(12, 44), Pair(18, 46), Pair(24, 45), Pair(27, 48), Pair(30, 52), Pair(40, 46), Pair(74, 29)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-10, -211), Pair(-5, -163), Pair(-3, -66), Pair(1, -59), Pair(1, -28), Pair(4, -14), Pair(6, 6), Pair(7, 17),
  Pair(9, 29), Pair(11, 35), Pair(13, 42), Pair(15, 47), Pair(18, 47), Pair(17, 54), Pair(18, 56), Pair(22, 51),
  Pair(25, 46), Pair(29, 41), Pair(33, 32), Pair(50, 8), Pair(63, -7), Pair(82, -35), Pair(94, -49), Pair(143, -96),
  Pair(213, -144), Pair(290, -210), Pair(193, -142), Pair(196, -163)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(1, -82), Pair(3, -69), Pair(7, -36), Pair(28, 1), Pair(38, 56), Pair(-48, 19), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 3), Pair(15, 4), Pair(16, 22), Pair(39, 64), Pair(168, 122), Pair(410, 449), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(19, 10), Pair(14, 8), Pair(16, 19), Pair(40, 44), Pair(209, 13), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-25, -41), Pair(2, -27), Pair(-10, -16), Pair(-12, -8), Pair(-10, -3), Pair(-14, -9), Pair(0, -20), Pair(-18, -39)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(3, 2), Pair(-6, -11), Pair(-10, -7), Pair(-10, -13), Pair(-13, -13), Pair(-4, -12), Pair(-5, -11), Pair(-2, -1)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(26, -1), Pair(19, 1), Pair(20, 4), Pair(19, 4), Pair(27, 5), Pair(32, -3), Pair(46, -8), Pair(54, -5)
  },
  {
      Pair(18, 25), Pair(13, 7), Pair(20, -1), Pair(20, -3), Pair(19, -2), Pair(20, -8), Pair(30, -3), Pair(25, 16)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -2), Pair(12, -6), Pair(11, -3),
  Pair(19, -7), Pair(14, -5), Pair(18, -5),
  Pair(25, -1), Pair(0, 0), Pair(25, -1),
  Pair(-9, 12), Pair(-32, 16), Pair(-2, 10)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-16, 10), Pair(-7, 5),
  Pair(-8, 3), Pair(-19, 11), Pair(-8, 3),
  Pair(0, -6), Pair(-12, 4), Pair(0, -6),
  Pair(9, -5), Pair(-13, 2), Pair(11, -7),
  Pair(24, -14), Pair(28, -8), Pair(23, -14),
  Pair(0, 0), Pair(-43, -8), Pair(0, 0),
  Pair(54, -58), Pair(0, 0), Pair(63, -60)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-10, 36), Pair(-26, 31), Pair(-24, 12), Pair(-18, 0), Pair(-10, -2), Pair(1, -2), Pair(-5, -8)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-33, 4), Pair(2, 26), Pair(2, 57), Pair(9, 67), Pair(5, 76), Pair(3, 81), Pair(-2, 76)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-34, 149);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-57, 7), Pair(-66, 3), Pair(-29, -12), Pair(-17, -17), Pair(-17, -14), Pair(-30, -8), Pair(-53, 3), Pair(-53, 11)
  },
  {
      Pair(-25, 49), Pair(-50, 33), Pair(-25, 15), Pair(-13, 3), Pair(-11, 1), Pair(-17, 14), Pair(-27, 26), Pair(-30, 50)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 0), Pair(20, -4), Pair(65, -25), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, 1), Pair(23, 1), Pair(40, -2), Pair(4, -11), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(18, -20), Pair(29, -20), Pair(45, -13), Pair(69, -14), Pair(62, -18), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 25), Pair(9, 38), Pair(22, 47), Pair(66, 20), Pair(100, 19), Pair(199, -30), Pair(239, -76)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(28, 3), Pair(13, 21), Pair(47, -2), Pair(18, 19), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-3, 28), Pair(4, 28)
  },
  {
      Pair(-63, -24), Pair(-56, -30)
  },
  {
      Pair(-46, -56), Pair(-49, -61)
  },
  {
      Pair(-77, -27), Pair(-54, -36)
  },
  {
      Pair(-44, -15), Pair(-45, -8)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 29), Pair(21, 25), Pair(24, 12), Pair(21, -6), Pair(43, -3)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-5, -25), Pair(7, -12)
  },
  {
      Pair(6, 58), Pair(3, 52)
  },
  {
      Pair(-41, -14), Pair(-30, -28)
  },
  {
      Pair(-65, -2), Pair(-55, -11)
  },
  {
      Pair(-39, -8), Pair(-33, -28)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-15, -21), Pair(0, -7)
  },
  {
      Pair(-49, -12), Pair(-20, -29)
  },
  {
      Pair(-4, 2), Pair(4, -4)
  },
  {
      Pair(-52, -18), Pair(-51, -34)
  },
  {
      Pair(-48, -37), Pair(-42, -61)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-8, -29), Pair(11, -16)
  },
  {
      Pair(-43, -19), Pair(-6, -17)
  },
  {
      Pair(-34, -25), Pair(-13, -11)
  },
  {
      Pair(8, -44), Pair(11, -22)
  },
  {
      Pair(-59, -23), Pair(-46, -67)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(1, 10), Pair(7, 15), Pair(34, 19), Pair(22, 27), Pair(27, 35), Pair(0, 48), Pair(22, 32), Pair(-13, 57),
  Pair(6, 21), Pair(12, 7), Pair(9, 22), Pair(0, 26), Pair(4, 26), Pair(-3, 25), Pair(10, 11), Pair(5, 19),
  Pair(9, 6), Pair(-12, 12), Pair(1, 14), Pair(8, 11), Pair(4, 15), Pair(-5, 12), Pair(-8, 13), Pair(8, -2)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-58, 37), Pair(12, 17), Pair(26, 3), Pair(37, 5), Pair(48, 0), Pair(44, 2), Pair(42, -2), Pair(-5, 17),
  Pair(-27, 34), Pair(11, 18), Pair(21, 6), Pair(21, 9), Pair(12, 16), Pair(6, 7), Pair(14, 13), Pair(-8, -7),
  Pair(-3, 9), Pair(4, 18), Pair(2, 22), Pair(21, 12), Pair(13, 24), Pair(-3, 19), Pair(11, 5), Pair(-30, 11)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 53);

constexpr ScorePair kTempoBonus = Pair(17, 9);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H