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
  Pair(112, 109), Pair(371, 231), Pair(415, 262), Pair(544, 525), Pair(981, 970), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(102, 1), Pair(25, 60), Pair(37, 67), Pair(27, 66), Pair(51, 63), Pair(18, 72), Pair(-23, 105), Pair(78, -4),
      Pair(2, -8), Pair(-8, -2), Pair(-1, -1), Pair(32, -18), Pair(37, -15), Pair(50, -16), Pair(-1, 8), Pair(13, -26),
      Pair(-6, -11), Pair(-1, -12), Pair(4, -20), Pair(19, -36), Pair(28, -25), Pair(15, -25), Pair(0, -12), Pair(-9, -19),
      Pair(-13, -13), Pair(-23, -9), Pair(0, -26), Pair(10, -29), Pair(13, -28), Pair(11, -26), Pair(-15, -11), Pair(-13, -20),
      Pair(-13, -19), Pair(-24, -17), Pair(-20, -12), Pair(-14, -20), Pair(-14, -10), Pair(-6, -21), Pair(1, -17), Pair(-9, -19),
      Pair(-15, -7), Pair(-9, -10), Pair(-18, -6), Pair(-18, -17), Pair(-15, -12), Pair(15, -14), Pair(15, -19), Pair(-10, -23),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-139, -41), Pair(-80, -32), Pair(-12, -38), Pair(36, -32), Pair(63, -39), Pair(-101, -4), Pair(-75, -9), Pair(-65, -57),
      Pair(-20, -13), Pair(32, -27), Pair(51, -29), Pair(79, -18), Pair(65, -28), Pair(54, -32), Pair(41, -36), Pair(8, -24),
      Pair(12, -43), Pair(49, -26), Pair(39, 8), Pair(84, -16), Pair(91, -10), Pair(102, -4), Pair(34, -12), Pair(32, -37),
      Pair(37, -28), Pair(40, -9), Pair(65, 2), Pair(69, 9), Pair(61, -5), Pair(90, -14), Pair(50, -17), Pair(65, -31),
      Pair(28, -17), Pair(54, -25), Pair(51, 14), Pair(60, 14), Pair(62, 10), Pair(74, 4), Pair(60, -21), Pair(35, 2),
      Pair(8, -43), Pair(34, -23), Pair(33, -2), Pair(44, 13), Pair(48, 1), Pair(44, -4), Pair(51, -18), Pair(20, -21),
      Pair(1, -49), Pair(7, -18), Pair(17, -31), Pair(37, -15), Pair(38, -11), Pair(34, -24), Pair(20, -9), Pair(15, -30),
      Pair(-68, -63), Pair(6, -37), Pair(-2, -38), Pair(21, -15), Pair(28, -27), Pair(12, -24), Pair(8, -30), Pair(-15, -51)
  },
  {
      Pair(-14, -6), Pair(-49, 3), Pair(-10, -3), Pair(-37, -15), Pair(-23, -9), Pair(-39, -32), Pair(-22, 4), Pair(-10, -15),
      Pair(-30, -18), Pair(19, -5), Pair(-17, -4), Pair(12, -1), Pair(15, -22), Pair(0, -11), Pair(-5, -3), Pair(-30, 2),
      Pair(11, -15), Pair(37, -20), Pair(7, 14), Pair(44, -14), Pair(36, -9), Pair(41, 0), Pair(31, -37), Pair(18, -27),
      Pair(9, -27), Pair(10, -1), Pair(39, -12), Pair(28, 7), Pair(27, 3), Pair(42, -34), Pair(16, -21), Pair(5, -14),
      Pair(24, -25), Pair(8, -12), Pair(15, -6), Pair(19, -8), Pair(29, -12), Pair(17, -5), Pair(13, -11), Pair(30, -28),
      Pair(12, -24), Pair(30, -22), Pair(23, -10), Pair(20, -9), Pair(17, 6), Pair(20, -5), Pair(37, -24), Pair(16, -13),
      Pair(7, -25), Pair(25, -27), Pair(38, -39), Pair(12, -20), Pair(23, -25), Pair(33, -27), Pair(37, -30), Pair(43, -38),
      Pair(-3, -32), Pair(32, -49), Pair(3, -22), Pair(17, -25), Pair(24, -31), Pair(-4, -14), Pair(10, -42), Pair(22, -48)
  },
  {
      Pair(35, -24), Pair(57, -24), Pair(47, -17), Pair(58, -29), Pair(65, -23), Pair(85, -37), Pair(49, -29), Pair(31, -18),
      Pair(34, -16), Pair(38, -10), Pair(48, -18), Pair(81, -29), Pair(67, -25), Pair(70, -28), Pair(13, -16), Pair(11, -14),
      Pair(28, -24), Pair(63, -28), Pair(36, -23), Pair(52, -29), Pair(66, -33), Pair(61, -22), Pair(32, -30), Pair(31, -31),
      Pair(22, -30), Pair(38, -29), Pair(50, -33), Pair(41, -33), Pair(52, -30), Pair(31, -27), Pair(37, -35), Pair(22, -28),
      Pair(2, -28), Pair(1, -15), Pair(21, -18), Pair(17, -19), Pair(3, -14), Pair(6, -15), Pair(-9, -11), Pair(-12, -21),
      Pair(-11, -32), Pair(-12, -25), Pair(-9, -25), Pair(-11, -26), Pair(-7, -18), Pair(-7, -27), Pair(-6, -27), Pair(-14, -29),
      Pair(-15, -41), Pair(0, -40), Pair(16, -48), Pair(13, -42), Pair(13, -51), Pair(25, -52), Pair(-8, -45), Pair(-54, -38),
      Pair(7, -43), Pair(18, -47), Pair(12, -36), Pair(27, -48), Pair(23, -46), Pair(26, -45), Pair(-16, -27), Pair(4, -45)
  },
  {
      Pair(-14, 25), Pair(15, 41), Pair(34, 29), Pair(37, 25), Pair(45, 39), Pair(46, 6), Pair(46, 20), Pair(30, 21),
      Pair(-19, 23), Pair(-32, 57), Pair(-10, 85), Pair(-5, 98), Pair(-13, 100), Pair(-1, 100), Pair(-16, 86), Pair(51, -5),
      Pair(-11, 18), Pair(3, 52), Pair(-26, 107), Pair(3, 103), Pair(2, 116), Pair(19, 85), Pair(-8, 92), Pair(8, 17),
      Pair(-6, 28), Pair(-10, 55), Pair(-18, 91), Pair(-12, 108), Pair(-15, 123), Pair(2, 82), Pair(4, 61), Pair(9, 24),
      Pair(-5, -6), Pair(-11, 28), Pair(-16, 59), Pair(-25, 107), Pair(-13, 77), Pair(-7, 62), Pair(6, 34), Pair(-5, 8),
      Pair(-2, -15), Pair(-1, 6), Pair(-4, 21), Pair(-9, 35), Pair(-4, 24), Pair(-5, 36), Pair(4, 9), Pair(1, -23),
      Pair(-14, -35), Pair(-2, -30), Pair(11, -28), Pair(6, -10), Pair(9, -23), Pair(20, -54), Pair(8, -52), Pair(15, -85),
      Pair(-15, -36), Pair(-9, -38), Pair(-10, -30), Pair(-2, -30), Pair(1, -45), Pair(-29, -44), Pair(5, -64), Pair(4, -57)
  },
  {
      Pair(25, -129), Pair(157, 48), Pair(122, 43), Pair(-21, 61), Pair(45, 54), Pair(-6, 20), Pair(59, -5), Pair(76, -185),
      Pair(-88, -20), Pair(86, 9), Pair(63, 19), Pair(36, 5), Pair(37, 7), Pair(56, -7), Pair(64, 5), Pair(-113, -40),
      Pair(-7, -12), Pair(163, -29), Pair(89, -3), Pair(-79, 15), Pair(-74, 8), Pair(-5, -12), Pair(37, -29), Pair(25, -39),
      Pair(3, -34), Pair(90, -25), Pair(-14, 13), Pair(-121, 23), Pair(-146, 20), Pair(-46, -3), Pair(35, -23), Pair(-44, -35),
      Pair(-52, -60), Pair(58, -30), Pair(16, -1), Pair(-105, 33), Pair(-89, 18), Pair(-8, -4), Pair(25, -22), Pair(-62, -47),
      Pair(1, -49), Pair(17, -21), Pair(2, 0), Pair(-46, 24), Pair(-48, 22), Pair(-36, 10), Pair(9, -9), Pair(-17, -31),
      Pair(40, -42), Pair(1, 5), Pair(-12, 10), Pair(-51, 24), Pair(-38, 20), Pair(-19, 13), Pair(0, 7), Pair(19, -25),
      Pair(-48, 35), Pair(32, -15), Pair(21, 4), Pair(-67, 16), Pair(-4, -8), Pair(-38, 7), Pair(27, -5), Pair(21, -16)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(6, -28), Pair(24, -33), Pair(34, -6), Pair(42, 6), Pair(47, 10), Pair(52, 19), Pair(56, 14), Pair(61, 2),
  Pair(69, -35)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-6, -54), Pair(9, -59), Pair(16, -35), Pair(22, -22), Pair(26, -10), Pair(29, -5), Pair(33, -7), Pair(35, -7),
  Pair(40, -8), Pair(52, -17), Pair(66, -32), Pair(71, -41), Pair(109, -63), Pair(-21, -41)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-18, -100), Pair(-4, -73), Pair(0, -54), Pair(10, -46), Pair(11, -37), Pair(14, -29), Pair(18, -24), Pair(22, -22),
  Pair(25, -13), Pair(30, -13), Pair(37, -13), Pair(39, -10), Pair(47, -8), Pair(54, -13), Pair(62, -34)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-24, -88), Pair(-16, -158), Pair(-15, -45), Pair(-12, -43), Pair(-12, -1), Pair(-10, 26), Pair(-9, 37), Pair(-6, 47),
  Pair(-4, 52), Pair(-2, 62), Pair(1, 72), Pair(2, 74), Pair(1, 78), Pair(2, 82), Pair(1, 82), Pair(6, 72),
  Pair(16, 51), Pair(15, 44), Pair(35, 19), Pair(48, 0), Pair(50, -11), Pair(38, -38), Pair(49, -41), Pair(7, -72),
  Pair(56, -84), Pair(144, -171), Pair(94, -105), Pair(3, -101)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-19, -50), Pair(-24, -33), Pair(-6, -8), Pair(21, 20), Pair(56, 47), Pair(118, 2), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(8, 10), Pair(14, 5), Pair(19, 19), Pair(42, 57), Pair(163, 140), Pair(-1, 463), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(22, 8), Pair(17, 5), Pair(17, 15), Pair(55, 28), Pair(213, -20), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-53, -20), Pair(-8, -14), Pair(-18, -17), Pair(-28, 0), Pair(-17, -3), Pair(-16, -10), Pair(5, -17), Pair(-9, -24)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(6, -7), Pair(-3, -8), Pair(-12, -6), Pair(-14, -5), Pair(-19, -14), Pair(-2, -10), Pair(4, -9), Pair(-11, -5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(47, -26), Pair(35, -26), Pair(42, -16), Pair(38, -16), Pair(50, -18), Pair(46, -21), Pair(69, -29), Pair(72, -27)
  },
  {
      Pair(31, -1), Pair(19, -11), Pair(33, -16), Pair(33, -23), Pair(33, -24), Pair(26, -27), Pair(46, -21), Pair(31, -19)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -7), Pair(16, -17), Pair(14, -11),
  Pair(20, -9), Pair(15, -12), Pair(19, -10),
  Pair(17, 9), Pair(0, 0), Pair(16, 8),
  Pair(36, 4), Pair(-32, 23), Pair(35, 4)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-9, 5), Pair(-15, 18), Pair(-9, 11),
  Pair(-12, 7), Pair(-23, 18), Pair(-10, 9),
  Pair(2, -5), Pair(-11, 7), Pair(2, -5),
  Pair(14, -7), Pair(-13, 2), Pair(10, -7),
  Pair(34, -23), Pair(33, -7), Pair(32, -29),
  Pair(0, 0), Pair(-65, 3), Pair(0, 0),
  Pair(87, -69), Pair(0, 0), Pair(88, -73)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(18, 39), Pair(-22, 47), Pair(-7, 20), Pair(-2, 8), Pair(-3, 15), Pair(9, 15), Pair(-14, 7)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-49, -27), Pair(-10, -7), Pair(-11, 27), Pair(-1, 41), Pair(2, 51), Pair(3, 54), Pair(-12, 69)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-367, 180);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-86, 42), Pair(-81, 8), Pair(-27, -27), Pair(7, -36), Pair(-17, -29), Pair(-21, -22), Pair(-45, -11), Pair(-76, 26)
  },
  {
      Pair(-32, 63), Pair(-26, 13), Pair(-17, -3), Pair(6, -9), Pair(-13, -4), Pair(-10, 0), Pair(-18, 13), Pair(-41, 47)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -2), Pair(26, -5), Pair(89, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 0), Pair(29, 4), Pair(40, 4), Pair(5, -7), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(27, -22), Pair(33, -21), Pair(79, -34), Pair(135, -50), Pair(162, -61), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -12), Pair(22, -11), Pair(47, -23), Pair(104, -71), Pair(176, -81), Pair(239, -104), Pair(246, -138)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(35, -9), Pair(14, 10), Pair(100, -37), Pair(31, -28), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-9, 36), Pair(6, 24)
  },
  {
      Pair(-77, -7), Pair(-68, -25)
  },
  {
      Pair(-57, -40), Pair(-59, -53)
  },
  {
      Pair(-78, -26), Pair(-65, -23)
  },
  {
      Pair(-53, 1), Pair(-60, 23)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(16, 39), Pair(27, 16), Pair(26, 16), Pair(27, -39), Pair(37, 11)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-4, -32), Pair(7, -17)
  },
  {
      Pair(-8, -30), Pair(-8, -35)
  },
  {
      Pair(-51, 2), Pair(-39, -26)
  },
  {
      Pair(-77, 2), Pair(-63, -2)
  },
  {
      Pair(-54, 20), Pair(-44, -7)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-20, -28), Pair(-1, -12)
  },
  {
      Pair(-51, -3), Pair(-22, -31)
  },
  {
      Pair(-19, -71), Pair(-2, -79)
  },
  {
      Pair(-47, -26), Pair(-59, -38)
  },
  {
      Pair(-56, -55), Pair(-46, -77)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-17, -21), Pair(11, -17)
  },
  {
      Pair(-57, -4), Pair(-5, -16)
  },
  {
      Pair(-44, -4), Pair(-13, -8)
  },
  {
      Pair(-12, -71), Pair(-1, -45)
  },
  {
      Pair(-43, -89), Pair(-65, -31)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-36, 50), Pair(25, 49), Pair(42, 33), Pair(8, 45), Pair(27, 32), Pair(-2, 43), Pair(26, 51), Pair(34, 55),
  Pair(38, -3), Pair(20, 9), Pair(21, 32), Pair(-2, 25), Pair(-3, 50), Pair(-28, 59), Pair(10, 30), Pair(18, 21),
  Pair(10, -9), Pair(-10, 21), Pair(10, 12), Pair(14, 13), Pair(1, 29), Pair(-5, 10), Pair(-17, 13), Pair(16, -17)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(34, 33), Pair(18, 20), Pair(38, -4), Pair(40, -4), Pair(43, 0), Pair(62, 8), Pair(25, 41), Pair(-9, 9),
  Pair(-67, 12), Pair(5, 20), Pair(1, 9), Pair(18, 15), Pair(24, -5), Pair(36, 46), Pair(13, 24), Pair(2, 14),
  Pair(-14, 12), Pair(2, 35), Pair(1, 27), Pair(9, 25), Pair(17, 28), Pair(6, 16), Pair(15, 9), Pair(-1, -21)
};

constexpr ScorePair kBishopPairBonus = Pair(37, 57);

constexpr ScorePair kTempoBonus = Pair(21, 2);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H