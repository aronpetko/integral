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
  Pair(104, 122), Pair(380, 211), Pair(422, 267), Pair(565, 493), Pair(1211, 839), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(64, 40), Pair(38, 58), Pair(68, 31), Pair(65, 36), Pair(83, 20), Pair(27, 51), Pair(-8, 58), Pair(43, 24),
      Pair(1, -13), Pair(0, -20), Pair(0, -23), Pair(11, -40), Pair(23, -41), Pair(41, -43), Pair(0, -7), Pair(1, -28),
      Pair(-17, -16), Pair(-10, -26), Pair(-11, -28), Pair(-1, -45), Pair(8, -45), Pair(2, -43), Pair(-4, -24), Pair(-20, -36),
      Pair(-27, -25), Pair(-24, -25), Pair(-14, -37), Pair(-5, -43), Pair(-2, -49), Pair(-4, -42), Pair(-8, -30), Pair(-24, -40),
      Pair(-32, -28), Pair(-28, -30), Pair(-30, -32), Pair(-26, -31), Pair(-20, -37), Pair(-28, -34), Pair(-6, -28), Pair(-24, -43),
      Pair(-26, -23), Pair(-14, -22), Pair(-21, -25), Pair(-22, -29), Pair(-21, -31), Pair(1, -35), Pair(8, -27), Pair(-20, -40),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-155, 9), Pair(-68, 5), Pair(-29, 6), Pair(55, -18), Pair(82, -23), Pair(-76, 14), Pair(-18, 8), Pair(-150, -9),
      Pair(-29, 19), Pair(-6, 15), Pair(24, 10), Pair(65, -3), Pair(60, 2), Pair(62, -4), Pair(17, 16), Pair(2, 7),
      Pair(-11, 13), Pair(28, 3), Pair(45, 16), Pair(65, 9), Pair(65, 12), Pair(76, 4), Pair(21, 18), Pair(14, -5),
      Pair(28, 5), Pair(19, 23), Pair(55, 16), Pair(58, 23), Pair(53, 27), Pair(56, 22), Pair(38, 21), Pair(29, 14),
      Pair(17, 14), Pair(29, 9), Pair(41, 29), Pair(38, 31), Pair(45, 31), Pair(48, 27), Pair(46, 17), Pair(19, 24),
      Pair(-7, -4), Pair(14, 15), Pair(18, 24), Pair(40, 30), Pair(34, 27), Pair(28, 19), Pair(26, 9), Pair(1, 17),
      Pair(-1, 6), Pair(6, 8), Pair(6, 11), Pair(18, 13), Pair(21, 13), Pair(14, 7), Pair(25, 5), Pair(8, 3),
      Pair(-65, -4), Pair(-14, 1), Pair(5, 11), Pair(14, 0), Pair(26, 0), Pair(0, -1), Pair(-11, 8), Pair(-22, -6)
  },
  {
      Pair(-52, 37), Pair(-16, 14), Pair(-86, 15), Pair(-67, 4), Pair(18, -6), Pair(-53, -5), Pair(-51, 14), Pair(-87, 12),
      Pair(-27, 12), Pair(-15, 15), Pair(-8, 5), Pair(-21, 15), Pair(-7, 4), Pair(5, -4), Pair(-40, 21), Pair(-10, -11),
      Pair(-2, 8), Pair(11, 1), Pair(1, 17), Pair(20, 2), Pair(40, -3), Pair(32, 15), Pair(25, 1), Pair(19, -6),
      Pair(-10, -2), Pair(5, 5), Pair(15, 1), Pair(25, 7), Pair(23, 7), Pair(29, 7), Pair(5, 2), Pair(11, -3),
      Pair(-1, -7), Pair(-5, -1), Pair(13, 0), Pair(9, 6), Pair(14, 1), Pair(10, -1), Pair(21, -1), Pair(10, -6),
      Pair(-5, -5), Pair(18, 2), Pair(13, 5), Pair(12, 6), Pair(9, 10), Pair(24, 4), Pair(14, 9), Pair(6, -7),
      Pair(9, -19), Pair(17, -18), Pair(9, -6), Pair(6, -5), Pair(14, -2), Pair(16, -9), Pair(26, -16), Pair(7, -10),
      Pair(8, -18), Pair(2, -9), Pair(1, -5), Pair(0, 3), Pair(10, -3), Pair(-8, 4), Pair(25, -13), Pair(15, -18)
  },
  {
      Pair(40, -4), Pair(22, 11), Pair(33, 11), Pair(36, 6), Pair(20, 13), Pair(73, -8), Pair(48, 8), Pair(44, -5),
      Pair(14, 2), Pair(25, 2), Pair(36, -1), Pair(60, -14), Pair(40, -4), Pair(65, -12), Pair(20, 5), Pair(29, -6),
      Pair(10, 2), Pair(42, -4), Pair(39, -5), Pair(48, -16), Pair(67, -17), Pair(64, -15), Pair(59, -10), Pair(13, -2),
      Pair(10, 0), Pair(20, -2), Pair(30, -4), Pair(42, -16), Pair(29, -3), Pair(40, -10), Pair(25, -2), Pair(-4, -1),
      Pair(-18, 7), Pair(-10, 12), Pair(-7, 7), Pair(-10, 6), Pair(-1, -1), Pair(-3, 3), Pair(-3, 5), Pair(-20, -1),
      Pair(-33, 2), Pair(-13, 6), Pair(-14, 4), Pair(-11, -5), Pair(-12, -9), Pair(-17, -4), Pair(-8, -6), Pair(-23, -10),
      Pair(-28, -13), Pair(-19, -10), Pair(-2, -12), Pair(0, -20), Pair(-1, -18), Pair(3, -17), Pair(-1, -17), Pair(-43, -14),
      Pair(-8, -15), Pair(-3, -17), Pair(0, -14), Pair(6, -21), Pair(8, -23), Pair(10, -21), Pair(-17, -8), Pair(-10, -19)
  },
  {
      Pair(-2, 16), Pair(32, -3), Pair(26, 22), Pair(52, -2), Pair(74, -16), Pair(59, -10), Pair(48, 11), Pair(23, 17),
      Pair(11, 0), Pair(-18, 61), Pair(1, 47), Pair(9, 58), Pair(-20, 77), Pair(17, 52), Pair(-1, 53), Pair(39, 4),
      Pair(7, 20), Pair(29, 1), Pair(12, 42), Pair(21, 46), Pair(23, 54), Pair(33, 46), Pair(34, 19), Pair(30, 17),
      Pair(16, -3), Pair(11, 29), Pair(13, 51), Pair(14, 60), Pair(21, 60), Pair(23, 38), Pair(21, 42), Pair(32, 3),
      Pair(15, -18), Pair(0, 37), Pair(8, 32), Pair(8, 55), Pair(17, 41), Pair(9, 24), Pair(32, -7), Pair(19, -18),
      Pair(7, 2), Pair(16, -11), Pair(15, 8), Pair(18, 13), Pair(14, 15), Pair(21, -1), Pair(27, -15), Pair(20, -19),
      Pair(15, -36), Pair(24, -43), Pair(30, -47), Pair(25, -22), Pair(29, -41), Pair(33, -53), Pair(36, -57), Pair(33, -55),
      Pair(43, -89), Pair(9, -47), Pair(21, -62), Pair(18, -53), Pair(15, -35), Pair(0, -58), Pair(42, -136), Pair(12, -43)
  },
  {
      Pair(29, -131), Pair(166, -31), Pair(-77, 36), Pair(-16, -2), Pair(35, -18), Pair(40, 1), Pair(24, 5), Pair(45, -149),
      Pair(17, -24), Pair(66, 18), Pair(6, 23), Pair(-3, 15), Pair(-8, 18), Pair(52, 26), Pair(35, 23), Pair(-55, -40),
      Pair(-28, 1), Pair(103, 11), Pair(3, 32), Pair(-46, 33), Pair(-142, 63), Pair(-32, 44), Pair(50, 22), Pair(12, -20),
      Pair(-20, -13), Pair(76, -12), Pair(-76, 39), Pair(-124, 43), Pair(-149, 46), Pair(-42, 20), Pair(20, -10), Pair(-66, -22),
      Pair(-1, -35), Pair(67, -18), Pair(-6, 14), Pair(-76, 35), Pair(-62, 28), Pair(-55, 12), Pair(7, -20), Pair(-117, -17),
      Pair(3, -22), Pair(20, -11), Pair(-19, 14), Pair(-41, 23), Pair(-51, 25), Pair(-41, 9), Pair(-17, -7), Pair(-42, -25),
      Pair(14, -22), Pair(2, -3), Pair(-22, 10), Pair(-24, 11), Pair(-32, 15), Pair(-27, 6), Pair(-6, -8), Pair(19, -39),
      Pair(3, -60), Pair(33, -33), Pair(20, -16), Pair(-38, 4), Pair(-6, -15), Pair(-25, -7), Pair(23, -27), Pair(23, -69)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-17, -35), Pair(5, -1), Pair(15, 17), Pair(22, 26), Pair(26, 31), Pair(30, 40), Pair(35, 38), Pair(37, 37),
  Pair(44, 27)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-24, -55), Pair(-9, -41), Pair(0, -28), Pair(6, -15), Pair(10, -7), Pair(15, -1), Pair(18, 2), Pair(22, 4),
  Pair(26, 6), Pair(30, 5), Pair(38, 3), Pair(41, 7), Pair(51, -4), Pair(69, -3)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-38, -60), Pair(-19, -46), Pair(-14, -36), Pair(-8, -19), Pair(-5, -16), Pair(-3, -11), Pair(2, -8), Pair(6, -5),
  Pair(10, -2), Pair(17, -1), Pair(21, -1), Pair(28, -1), Pair(32, 1), Pair(56, -12), Pair(90, -25)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(4, -265), Pair(7, -141), Pair(11, -60), Pair(18, -74), Pair(18, -42), Pair(19, -14), Pair(24, -13), Pair(26, -1),
  Pair(29, 6), Pair(30, 12), Pair(30, 24), Pair(32, 23), Pair(34, 27), Pair(35, 27), Pair(40, 23), Pair(41, 25),
  Pair(47, 15), Pair(54, -3), Pair(73, -23), Pair(74, -31), Pair(90, -52), Pair(148, -104), Pair(159, -120), Pair(206, -157),
  Pair(218, -174), Pair(261, -213), Pair(255, -173), Pair(100, -135)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-9, -71), Pair(-7, -57), Pair(3, -35), Pair(25, -6), Pair(39, 48), Pair(53, 24), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, -1), Pair(16, 4), Pair(19, 21), Pair(42, 58), Pair(153, 97), Pair(40, 464), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(20, 4), Pair(16, 4), Pair(15, 13), Pair(37, 34), Pair(129, 1), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-36, -33), Pair(-6, -12), Pair(-15, -13), Pair(-18, -5), Pair(-17, 5), Pair(-15, -14), Pair(-10, -20), Pair(-29, -30)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(6, -4), Pair(-5, -7), Pair(-9, -10), Pair(-13, -12), Pair(-8, -17), Pair(-2, -11), Pair(-5, -15), Pair(3, 2)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(24, 2), Pair(23, 0), Pair(17, 7), Pair(27, 2), Pair(30, 1), Pair(35, -1), Pair(39, -10), Pair(43, -4)
  },
  {
      Pair(22, 19), Pair(22, -1), Pair(24, -7), Pair(20, 1), Pair(23, -7), Pair(16, -9), Pair(27, -9), Pair(26, 7)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(14, -9), Pair(12, -4),
  Pair(19, -8), Pair(13, -4), Pair(18, -8),
  Pair(28, -3), Pair(0, 0), Pair(20, 0),
  Pair(18, -1), Pair(-17, 14), Pair(17, 5)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-10, 1), Pair(-12, 6), Pair(-7, 3),
  Pair(-7, -1), Pair(-17, 9), Pair(-7, 5),
  Pair(0, -9), Pair(-12, 3), Pair(3, -9),
  Pair(8, -8), Pair(-14, -1), Pair(13, -10),
  Pair(29, -21), Pair(22, -9), Pair(29, -20),
  Pair(0, 0), Pair(-101, 11), Pair(0, 0),
  Pair(34, -52), Pair(0, 0), Pair(34, -50)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(3, 45), Pair(-19, 48), Pair(-10, 28), Pair(-11, 14), Pair(-6, 13), Pair(10, 10), Pair(-9, 11)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-19, -8), Pair(-5, 12), Pair(-4, 37), Pair(-4, 52), Pair(1, 59), Pair(-1, 61), Pair(-20, 68)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-373, 96);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-78, 8), Pair(-65, -2), Pair(-12, -21), Pair(-31, -9), Pair(-13, -13), Pair(-23, -4), Pair(-45, 3), Pair(-49, 14)
  },
  {
      Pair(-55, 55), Pair(-46, 30), Pair(-25, 13), Pair(-20, 7), Pair(-7, -3), Pair(-15, 16), Pair(-27, 30), Pair(-22, 30)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 3), Pair(19, -1), Pair(65, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, 2), Pair(16, 8), Pair(34, 3), Pair(-5, -4), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(19, -15), Pair(28, -14), Pair(43, -10), Pair(48, -2), Pair(41, -8), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 23), Pair(11, 35), Pair(25, 38), Pair(62, 24), Pair(105, 8), Pair(176, -27), Pair(175, -62)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(35, -3), Pair(14, 17), Pair(49, -4), Pair(20, 10), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-7, 26), Pair(-1, 27)
  },
  {
      Pair(-72, -13), Pair(-60, -23)
  },
  {
      Pair(-52, -40), Pair(-50, -48)
  },
  {
      Pair(-74, -20), Pair(-57, -34)
  },
  {
      Pair(-50, 4), Pair(-54, 12)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 32), Pair(24, 19), Pair(22, 13), Pair(23, -4), Pair(29, 4)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -24), Pair(7, -11)
  },
  {
      Pair(23, -42), Pair(27, -53)
  },
  {
      Pair(-43, -6), Pair(-35, -23)
  },
  {
      Pair(-69, 3), Pair(-55, -7)
  },
  {
      Pair(-36, -11), Pair(-35, -29)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-15, -19), Pair(1, -8)
  },
  {
      Pair(-45, -13), Pair(-20, -30)
  },
  {
      Pair(7, -81), Pair(11, -92)
  },
  {
      Pair(-56, -10), Pair(-50, -29)
  },
  {
      Pair(-48, -40), Pair(-49, -12)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-5, -26), Pair(13, -17)
  },
  {
      Pair(-38, -11), Pair(-8, -13)
  },
  {
      Pair(-38, -15), Pair(-14, -8)
  },
  {
      Pair(-11, 46), Pair(-12, 67)
  },
  {
      Pair(-63, -12), Pair(-49, -41)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(55, 5), Pair(6, 24), Pair(24, 10), Pair(-5, 35), Pair(32, 31), Pair(10, 27), Pair(40, 24), Pair(36, 52),
  Pair(19, 25), Pair(15, 12), Pair(-5, 32), Pair(-5, 31), Pair(2, 34), Pair(-4, 27), Pair(3, 15), Pair(18, 2),
  Pair(-2, 10), Pair(-16, 21), Pair(-2, 15), Pair(9, 12), Pair(0, 21), Pair(-6, 3), Pair(-19, 20), Pair(13, 4)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-32, 8), Pair(37, 10), Pair(17, 1), Pair(52, -12), Pair(92, -18), Pair(64, -24), Pair(35, 10), Pair(16, 20),
  Pair(-22, -43), Pair(19, 17), Pair(2, 20), Pair(16, 9), Pair(13, 14), Pair(-3, 4), Pair(10, 24), Pair(12, 19),
  Pair(-2, 26), Pair(10, 18), Pair(6, 15), Pair(26, 10), Pair(24, 12), Pair(-2, 20), Pair(3, 13), Pair(-48, 47)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 54);

constexpr ScorePair kTempoBonus = Pair(16, 4);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H