#ifndef INTEGRAL_TERMS_H
#define INTEGRAL_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceTable = std::array<T, kNumPieceTypes>;

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
  Pair(85, 121), Pair(331, 201), Pair(354, 230), Pair(468, 551), Pair(1098, 1009), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(70, 68), Pair(8, 97), Pair(51, 60), Pair(63, 29), Pair(69, 24), Pair(55, 49), Pair(8, 88), Pair(-11, 64),
      Pair(-11, 19), Pair(-29, 35), Pair(10, -8), Pair(18, -39), Pair(34, -41), Pair(56, -20), Pair(8, 24), Pair(-9, 11),
      Pair(-27, 7), Pair(-27, 16), Pair(-21, -11), Pair(-20, -20), Pair(2, -25), Pair(-6, -17), Pair(-19, 13), Pair(-22, -9),
      Pair(-29, -7), Pair(-38, 14), Pair(-21, -16), Pair(-9, -21), Pair(-7, -22), Pair(-7, -20), Pair(-21, 8), Pair(-20, -20),
      Pair(-39, -10), Pair(-44, 7), Pair(-31, -18), Pair(-27, -17), Pair(-20, -16), Pair(-26, -18), Pair(-21, -1), Pair(-24, -23),
      Pair(-31, -5), Pair(-34, 10), Pair(-25, -10), Pair(-25, -17), Pair(-18, -6), Pair(-8, -13), Pair(-7, 2), Pair(-24, -20),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-165, 47), Pair(-104, 72), Pair(-69, 77), Pair(-59, 70), Pair(-6, 59), Pair(-46, 37), Pair(-71, 62), Pair(-116, 17),
      Pair(-46, 67), Pair(-33, 90), Pair(-16, 86), Pair(-3, 83), Pair(-28, 76), Pair(32, 61), Pair(-15, 75), Pair(-32, 55),
      Pair(-14, 72), Pair(-2, 91), Pair(-20, 104), Pair(8, 85), Pair(22, 77), Pair(46, 65), Pair(-7, 78), Pair(9, 57),
      Pair(-5, 89), Pair(12, 92), Pair(22, 90), Pair(30, 90), Pair(27, 92), Pair(35, 95), Pair(17, 94), Pair(33, 67),
      Pair(-10, 86), Pair(18, 85), Pair(18, 94), Pair(22, 98), Pair(25, 99), Pair(33, 82), Pair(23, 88), Pair(2, 83),
      Pair(-31, 80), Pair(-5, 87), Pair(6, 86), Pair(15, 100), Pair(26, 92), Pair(13, 83), Pair(16, 77), Pair(-6, 78),
      Pair(-34, 92), Pair(-23, 78), Pair(-10, 84), Pair(5, 84), Pair(4, 82), Pair(1, 78), Pair(2, 83), Pair(-6, 96),
      Pair(-62, 86), Pair(-30, 82), Pair(-22, 86), Pair(-9, 86), Pair(-7, 86), Pair(-4, 76), Pair(-26, 84), Pair(-35, 73)
  },
  {
      Pair(-37, 71), Pair(-74, 94), Pair(-35, 78), Pair(-106, 82), Pair(-76, 74), Pair(-54, 69), Pair(-34, 56), Pair(-83, 84),
      Pair(-26, 64), Pair(-27, 75), Pair(-26, 71), Pair(-24, 78), Pair(-48, 74), Pair(-26, 68), Pair(-52, 70), Pair(-39, 66),
      Pair(-4, 77), Pair(-11, 80), Pair(-19, 83), Pair(-10, 67), Pair(-25, 72), Pair(14, 72), Pair(6, 75), Pair(9, 70),
      Pair(-25, 85), Pair(-6, 83), Pair(-2, 77), Pair(-1, 80), Pair(3, 71), Pair(-1, 79), Pair(-9, 81), Pair(-19, 79),
      Pair(-16, 84), Pair(-28, 78), Pair(-6, 72), Pair(2, 69), Pair(4, 65), Pair(-5, 71), Pair(-11, 70), Pair(-2, 61),
      Pair(-18, 63), Pair(5, 82), Pair(2, 78), Pair(-1, 80), Pair(2, 86), Pair(8, 74), Pair(13, 66), Pair(-3, 68),
      Pair(-3, 71), Pair(0, 59), Pair(7, 63), Pair(-6, 73), Pair(5, 72), Pair(16, 57), Pair(24, 63), Pair(16, 48),
      Pair(-2, 57), Pair(6, 64), Pair(-9, 72), Pair(-9, 72), Pair(2, 77), Pair(-15, 81), Pair(-5, 74), Pair(9, 53)
  },
  {
      Pair(-21, 92), Pair(-27, 98), Pair(-5, 95), Pair(-25, 104), Pair(-26, 88), Pair(-17, 103), Pair(-15, 86), Pair(-45, 99),
      Pair(-21, 88), Pair(-17, 98), Pair(-3, 96), Pair(10, 85), Pair(-3, 78), Pair(7, 83), Pair(16, 77), Pair(-11, 79),
      Pair(-22, 87), Pair(15, 80), Pair(0, 85), Pair(-5, 79), Pair(28, 55), Pair(38, 65), Pair(50, 59), Pair(-7, 66),
      Pair(-18, 85), Pair(0, 86), Pair(9, 82), Pair(0, 81), Pair(10, 62), Pair(8, 73), Pair(19, 68), Pair(-21, 74),
      Pair(-24, 79), Pair(-20, 78), Pair(-19, 80), Pair(-14, 84), Pair(-13, 72), Pair(-27, 84), Pair(6, 56), Pair(-24, 66),
      Pair(-34, 76), Pair(-21, 74), Pair(-20, 78), Pair(-19, 79), Pair(-7, 64), Pair(-14, 69), Pair(9, 48), Pair(-16, 52),
      Pair(-31, 71), Pair(-23, 70), Pair(-12, 70), Pair(-14, 73), Pair(-3, 60), Pair(-10, 62), Pair(0, 55), Pair(-34, 62),
      Pair(-25, 73), Pair(-16, 66), Pair(-13, 70), Pair(-8, 65), Pair(-2, 56), Pair(-8, 65), Pair(-9, 58), Pair(-24, 62)
  },
  {
      Pair(21, -13), Pair(9, 0), Pair(27, 15), Pair(34, 10), Pair(21, 39), Pair(59, 17), Pair(73, -16), Pair(36, -22),
      Pair(30, 6), Pair(22, 36), Pair(10, 69), Pair(26, 44), Pair(-4, 81), Pair(36, 54), Pair(22, 53), Pair(64, 23),
      Pair(40, 11), Pair(40, 20), Pair(30, 61), Pair(40, 44), Pair(32, 64), Pair(62, 55), Pair(62, 29), Pair(77, -2),
      Pair(37, 13), Pair(46, 34), Pair(36, 52), Pair(37, 53), Pair(34, 55), Pair(52, 24), Pair(56, 36), Pair(61, 6),
      Pair(35, 25), Pair(27, 54), Pair(41, 35), Pair(36, 63), Pair(49, 35), Pair(41, 32), Pair(56, 20), Pair(57, 11),
      Pair(32, 16), Pair(42, 17), Pair(39, 40), Pair(36, 39), Pair(43, 34), Pair(45, 32), Pair(64, 7), Pair(61, -30),
      Pair(38, 1), Pair(43, 7), Pair(44, 6), Pair(48, 20), Pair(49, 14), Pair(54, -11), Pair(60, -21), Pair(73, -59),
      Pair(40, -22), Pair(36, -11), Pair(34, 13), Pair(38, 3), Pair(41, 0), Pair(42, -28), Pair(51, -9), Pair(49, -16)
  },
  {
      Pair(-75, -120), Pair(20, -41), Pair(83, -33), Pair(-55, 3), Pair(36, -2), Pair(59, -1), Pair(95, -58), Pair(185, -137),
      Pair(-55, -1), Pair(64, 31), Pair(65, 48), Pair(33, 37), Pair(-24, 46), Pair(39, 48), Pair(27, 47), Pair(-26, -1),
      Pair(-78, 4), Pair(82, 30), Pair(24, 39), Pair(-18, 57), Pair(-39, 46), Pair(34, 30), Pair(31, 33), Pair(-56, 7),
      Pair(-71, -11), Pair(24, 7), Pair(-31, 31), Pair(-76, 47), Pair(-45, 37), Pair(-54, 29), Pair(-39, 15), Pair(-102, -4),
      Pair(-62, -17), Pair(-17, 5), Pair(2, 16), Pair(-53, 37), Pair(-59, 30), Pair(-38, 14), Pair(-35, 1), Pair(-124, -12),
      Pair(-31, -29), Pair(14, -7), Pair(-14, 11), Pair(-31, 25), Pair(-31, 22), Pair(-14, 6), Pair(-3, -9), Pair(-37, -23),
      Pair(24, -36), Pair(-1, -5), Pair(-2, 4), Pair(-22, 13), Pair(-28, 13), Pair(-14, 2), Pair(0, -16), Pair(16, -43),
      Pair(16, -70), Pair(39, -46), Pair(30, -27), Pair(-35, 1), Pair(10, -30), Pair(-22, -11), Pair(21, -40), Pair(27, -78)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-29, 46), Pair(-14, 42), Pair(-3, 57), Pair(1, 69), Pair(5, 76), Pair(9, 83), Pair(14, 84), Pair(18, 81),
  Pair(18, 75)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-31, 30), Pair(-19, 24), Pair(-9, 40), Pair(-3, 50), Pair(2, 59), Pair(5, 69), Pair(7, 74), Pair(8, 78),
  Pair(9, 81), Pair(13, 81), Pair(26, 77), Pair(31, 79), Pair(60, 78), Pair(63, 77)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-19, -53), Pair(-9, -27), Pair(-4, -20), Pair(-5, -6), Pair(-6, -1), Pair(-2, 2), Pair(0, 5), Pair(3, 6),
  Pair(5, 12), Pair(8, 15), Pair(14, 16), Pair(13, 19), Pair(18, 22), Pair(21, 17), Pair(24, 15)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-68, -258), Pair(-1, -326), Pair(15, -213), Pair(19, -101), Pair(21, -62), Pair(24, -51), Pair(25, -22), Pair(25, -11),
  Pair(29, -8), Pair(32, -7), Pair(32, 2), Pair(33, 9), Pair(35, 7), Pair(35, 16), Pair(39, 10), Pair(39, 13),
  Pair(42, 11), Pair(43, 11), Pair(49, 4), Pair(58, -12), Pair(70, -32), Pair(151, -105), Pair(133, -99), Pair(164, -139),
  Pair(180, -130), Pair(75, -87), Pair(64, -65), Pair(0, -81)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-20, -63), Pair(-23, -46), Pair(-14, -15), Pair(10, 17), Pair(10, 73), Pair(10, 53), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 0), Pair(15, 7), Pair(19, 12), Pair(50, 46), Pair(100, 183), Pair(200, 350), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(14, 7), Pair(15, 12), Pair(31, 34), Pair(195, 20), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -55), Pair(8, -38), Pair(3, -28), Pair(-1, -16), Pair(-3, -13), Pair(-3, -23), Pair(9, -40), Pair(-9, -51)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-9, 16), Pair(-4, -9), Pair(-10, -4), Pair(-10, -12), Pair(-13, -11), Pair(-4, -4), Pair(-2, -10), Pair(-4, 13)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(28, 3), Pair(17, 8), Pair(14, 12), Pair(17, 10), Pair(15, 20), Pair(32, 6), Pair(33, 13), Pair(80, -9)
  },
  {
      Pair(11, 29), Pair(6, 11), Pair(9, 10), Pair(18, -3), Pair(14, 3), Pair(12, 2), Pair(23, 1), Pair(22, 11)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(11, -4), Pair(18, -6), Pair(10, -2),
  Pair(22, -11), Pair(17, -10), Pair(23, -12),
  Pair(31, -6), Pair(0, 0), Pair(27, -3),
  Pair(-20, 7), Pair(-12, -1), Pair(-12, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, 1), Pair(-14, 3), Pair(-9, 4),
  Pair(-7, 1), Pair(-16, 6), Pair(-9, 3),
  Pair(-2, -5), Pair(-13, 1), Pair(-1, -3),
  Pair(13, -5), Pair(-4, -2), Pair(11, -3),
  Pair(22, -6), Pair(17, 2), Pair(17, -6),
  Pair(0, 0), Pair(3, -28), Pair(0, 0),
  Pair(46, -42), Pair(0, 0), Pair(31, -43)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-10, 47), Pair(-17, 33), Pair(-7, 14), Pair(0, 5), Pair(1, 2), Pair(16, 1), Pair(6, 3)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-66, 8), Pair(-7, 7), Pair(3, 27), Pair(11, 35), Pair(19, 38), Pair(18, 44), Pair(-13, 46)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-76, 208);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-66, -7), Pair(-58, -7), Pair(-43, -3), Pair(-27, -7), Pair(-24, -2), Pair(-32, 2), Pair(-51, 2), Pair(-35, -5)
  },
  {
      Pair(-8, 44), Pair(-33, 18), Pair(-19, 10), Pair(2, -6), Pair(-2, -4), Pair(-3, 3), Pair(-29, 24), Pair(-20, 36)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, -1), Pair(24, -13), Pair(51, -29), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(14, 1), Pair(27, 0), Pair(57, -10), Pair(54, -29), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(22, -22), Pair(36, -24), Pair(53, -20), Pair(73, -20), Pair(56, -23), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 19), Pair(9, 30), Pair(25, 47), Pair(73, 19), Pair(95, 33), Pair(141, 12), Pair(213, -56)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(38, 3), Pair(16, 18), Pair(53, 0), Pair(19, 20), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-18, 18), Pair(-8, 22)
  },
  {
      Pair(-58, -17), Pair(-67, -7)
  },
  {
      Pair(-54, -40), Pair(-69, -52)
  },
  {
      Pair(-79, 19), Pair(-77, -4)
  },
  {
      Pair(-74, 48), Pair(-69, 21)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(16, 28), Pair(22, 20), Pair(26, 10), Pair(20, -5), Pair(44, -3)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -20), Pair(9, -12)
  },
  {
      Pair(-24, -29), Pair(-13, -37)
  },
  {
      Pair(-48, -29), Pair(-29, -30)
  },
  {
      Pair(-82, 1), Pair(-64, -19)
  },
  {
      Pair(-58, 18), Pair(-58, 2)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-12, -18), Pair(1, -10)
  },
  {
      Pair(-47, -21), Pair(-24, -21)
  },
  {
      Pair(9, -139), Pair(23, -138)
  },
  {
      Pair(-75, -2), Pair(-45, -21)
  },
  {
      Pair(-77, -51), Pair(-53, -88)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-4, -25), Pair(12, -12)
  },
  {
      Pair(-36, -29), Pair(-4, -13)
  },
  {
      Pair(-29, -24), Pair(-15, -7)
  },
  {
      Pair(-2, -75), Pair(23, -48)
  },
  {
      Pair(-93, 7), Pair(-73, -15)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(22, -4), Pair(23, -2), Pair(60, 4), Pair(42, 32), Pair(38, 33), Pair(65, 41), Pair(67, 18), Pair(22, 12),
  Pair(20, 10), Pair(15, 11), Pair(25, 17), Pair(17, 31), Pair(16, 21), Pair(22, 20), Pair(23, 5), Pair(-29, 32),
  Pair(5, 0), Pair(5, 5), Pair(4, 16), Pair(14, 15), Pair(10, 16), Pair(-3, 19), Pair(11, -8), Pair(4, 10)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-40, -16), Pair(34, -4), Pair(39, -9), Pair(50, 2), Pair(77, -23), Pair(55, -3), Pair(38, -16), Pair(-38, -34),
  Pair(-2, -7), Pair(20, 2), Pair(11, 4), Pair(23, 4), Pair(21, 4), Pair(22, -9), Pair(16, -3), Pair(38, -43),
  Pair(-6, 17), Pair(5, 5), Pair(0, 24), Pair(14, 20), Pair(12, 20), Pair(2, 6), Pair(13, 3), Pair(-48, 18)
};

constexpr ScorePair kBishopPairBonus = Pair(18, 53);

constexpr ScorePair kTempoBonus = Pair(33, 24);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H