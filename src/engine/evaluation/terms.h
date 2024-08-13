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
  Pair(129, 106), Pair(439, 20), Pair(502, 69), Pair(704, 353), Pair(1520, 632), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(136, -23), Pair(60, 31), Pair(84, 17), Pair(98, 13), Pair(102, 10), Pair(55, 22), Pair(3, 31), Pair(180, -78),
      Pair(11, -19), Pair(10, -15), Pair(2, -11), Pair(7, -15), Pair(17, -15), Pair(41, -26), Pair(4, 0), Pair(8, -29),
      Pair(-13, -17), Pair(-5, -20), Pair(-12, -16), Pair(-1, -30), Pair(10, -32), Pair(-1, -31), Pair(-1, -11), Pair(-22, -30),
      Pair(-26, -24), Pair(-22, -15), Pair(-14, -29), Pair(-4, -34), Pair(-1, -40), Pair(-5, -30), Pair(-8, -15), Pair(-28, -31),
      Pair(-33, -25), Pair(-24, -20), Pair(-34, -20), Pair(-29, -23), Pair(-22, -27), Pair(-33, -23), Pair(0, -16), Pair(-26, -34),
      Pair(-28, -15), Pair(-9, -11), Pair(-26, -12), Pair(-25, -17), Pair(-25, -21), Pair(1, -22), Pair(15, -13), Pair(-21, -30),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-158, 45), Pair(-72, 39), Pair(-36, 50), Pair(56, 25), Pair(91, 13), Pair(-60, 45), Pair(11, 44), Pair(-164, 45),
      Pair(-6, 54), Pair(22, 40), Pair(61, 34), Pair(101, 25), Pair(84, 33), Pair(93, 17), Pair(51, 34), Pair(28, 35),
      Pair(12, 36), Pair(62, 26), Pair(78, 56), Pair(105, 33), Pair(107, 47), Pair(106, 50), Pair(52, 42), Pair(37, 23),
      Pair(61, 27), Pair(54, 44), Pair(92, 49), Pair(95, 52), Pair(93, 41), Pair(101, 31), Pair(72, 44), Pair(64, 36),
      Pair(52, 34), Pair(65, 29), Pair(77, 57), Pair(75, 57), Pair(83, 55), Pair(85, 57), Pair(90, 27), Pair(51, 45),
      Pair(22, 14), Pair(47, 36), Pair(50, 55), Pair(78, 56), Pair(71, 46), Pair(62, 50), Pair(63, 26), Pair(30, 37),
      Pair(30, 25), Pair(41, 20), Pair(38, 27), Pair(51, 35), Pair(55, 33), Pair(48, 26), Pair(62, 18), Pair(40, 23),
      Pair(-37, -4), Pair(14, 23), Pair(38, 25), Pair(47, 16), Pair(60, 17), Pair(29, 18), Pair(17, 31), Pair(10, -10)
  },
  {
      Pair(-50, 67), Pair(-9, 52), Pair(-50, 36), Pair(-43, 34), Pair(46, 26), Pair(-22, 27), Pair(-31, 50), Pair(-88, 52),
      Pair(-6, 49), Pair(12, 46), Pair(14, 42), Pair(12, 39), Pair(19, 36), Pair(31, 36), Pair(-11, 54), Pair(8, 30),
      Pair(28, 35), Pair(44, 29), Pair(32, 51), Pair(51, 37), Pair(72, 27), Pair(65, 44), Pair(71, 5), Pair(53, 21),
      Pair(17, 29), Pair(32, 41), Pair(46, 37), Pair(54, 53), Pair(51, 51), Pair(75, 13), Pair(36, 30), Pair(41, 30),
      Pair(29, 25), Pair(21, 38), Pair(41, 40), Pair(39, 43), Pair(44, 36), Pair(38, 39), Pair(55, 26), Pair(39, 26),
      Pair(20, 35), Pair(48, 32), Pair(41, 43), Pair(41, 38), Pair(38, 44), Pair(56, 39), Pair(46, 39), Pair(32, 28),
      Pair(33, 23), Pair(47, 18), Pair(41, 18), Pair(33, 28), Pair(44, 29), Pair(46, 21), Pair(57, 18), Pair(35, 26),
      Pair(33, 21), Pair(30, 12), Pair(25, 32), Pair(28, 31), Pair(38, 28), Pair(15, 39), Pair(59, 10), Pair(46, 12)
  },
  {
      Pair(63, -19), Pair(61, -13), Pair(100, -28), Pair(103, -38), Pair(93, -31), Pair(145, -53), Pair(89, -26), Pair(73, -25),
      Pair(39, -15), Pair(55, -16), Pair(71, -22), Pair(95, -35), Pair(72, -23), Pair(101, -35), Pair(47, -16), Pair(54, -27),
      Pair(38, -22), Pair(81, -30), Pair(73, -30), Pair(83, -40), Pair(102, -41), Pair(97, -40), Pair(94, -34), Pair(39, -26),
      Pair(43, -26), Pair(55, -30), Pair(70, -34), Pair(80, -46), Pair(64, -33), Pair(78, -42), Pair(56, -28), Pair(21, -23),
      Pair(6, -21), Pair(22, -17), Pair(21, -21), Pair(19, -23), Pair(28, -32), Pair(28, -27), Pair(25, -21), Pair(1, -24),
      Pair(-11, -22), Pair(14, -21), Pair(13, -25), Pair(17, -36), Pair(11, -36), Pair(11, -36), Pair(15, -31), Pair(-4, -29),
      Pair(-5, -40), Pair(8, -39), Pair(29, -48), Pair(31, -53), Pair(29, -53), Pair(34, -53), Pair(27, -46), Pair(-30, -36),
      Pair(18, -40), Pair(26, -43), Pair(28, -41), Pair(37, -52), Pair(40, -55), Pair(43, -54), Pair(3, -29), Pair(14, -42)
  },
  {
      Pair(47, -84), Pair(93, -106), Pair(85, -84), Pair(116, -108), Pair(136, -119), Pair(130, -122), Pair(109, -95), Pair(78, -80),
      Pair(76, -119), Pair(39, -36), Pair(62, -59), Pair(76, -55), Pair(47, -39), Pair(87, -62), Pair(60, -53), Pair(110, -111),
      Pair(73, -101), Pair(98, -115), Pair(74, -60), Pair(86, -55), Pair(92, -57), Pair(95, -52), Pair(107, -108), Pair(106, -120),
      Pair(85, -129), Pair(81, -98), Pair(80, -59), Pair(79, -37), Pair(86, -34), Pair(90, -72), Pair(90, -84), Pair(104, -125),
      Pair(86, -151), Pair(67, -87), Pair(77, -87), Pair(71, -46), Pair(84, -65), Pair(77, -93), Pair(106, -139), Pair(90, -152),
      Pair(75, -128), Pair(87, -139), Pair(83, -111), Pair(86, -108), Pair(82, -106), Pair(91, -120), Pair(99, -142), Pair(90, -150),
      Pair(86, -173), Pair(97, -181), Pair(104, -188), Pair(97, -152), Pair(103, -179), Pair(107, -191), Pair(112, -204), Pair(106, -196),
      Pair(121, -233), Pair(79, -190), Pair(92, -202), Pair(88, -193), Pair(87, -176), Pair(73, -215), Pair(119, -302), Pair(88, -197)
  },
  {
      Pair(-165, -33), Pair(-13, 113), Pair(-95, 96), Pair(22, 51), Pair(161, 10), Pair(142, 35), Pair(-80, 70), Pair(-28, -63),
      Pair(-19, -15), Pair(127, 18), Pair(81, 15), Pair(35, 9), Pair(188, -5), Pair(211, -20), Pair(190, 0), Pair(0, -45),
      Pair(76, -40), Pair(263, -38), Pair(176, -16), Pair(-2, 10), Pair(-59, 12), Pair(-15, -2), Pair(305, -70), Pair(90, -53),
      Pair(75, -46), Pair(208, -52), Pair(-31, 26), Pair(-74, 22), Pair(-105, 19), Pair(-37, 9), Pair(92, -33), Pair(1, -44),
      Pair(81, -69), Pair(120, -33), Pair(23, 1), Pair(-68, 26), Pair(-49, 16), Pair(-33, 4), Pair(36, -27), Pair(-56, -48),
      Pair(31, -41), Pair(36, -18), Pair(-3, 4), Pair(-43, 22), Pair(-48, 22), Pair(-37, 6), Pair(-12, -11), Pair(-35, -35),
      Pair(8, -24), Pair(-11, 3), Pair(-39, 15), Pair(-48, 23), Pair(-51, 23), Pair(-51, 18), Pair(-26, 5), Pair(2, -29),
      Pair(-75, 41), Pair(11, -10), Pair(-3, 3), Pair(-70, 18), Pair(-32, 1), Pair(-56, 12), Pair(-2, -1), Pair(-11, -19)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(13, 5), Pair(34, 49), Pair(46, 66), Pair(55, 75), Pair(61, 78), Pair(65, 85), Pair(71, 79), Pair(77, 69),
  Pair(89, 33)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-2, -26), Pair(15, -7), Pair(26, 5), Pair(33, 21), Pair(38, 30), Pair(43, 35), Pair(47, 37), Pair(53, 36),
  Pair(59, 36), Pair(67, 26), Pair(81, 21), Pair(78, 11), Pair(145, -21), Pair(40, -4)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-20, -81), Pair(-4, -58), Pair(2, -46), Pair(9, -26), Pair(13, -22), Pair(16, -17), Pair(22, -15), Pair(27, -13),
  Pair(31, -8), Pair(40, -10), Pair(46, -12), Pair(55, -13), Pair(62, -14), Pair(87, -26), Pair(195, -72)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(70, -353), Pair(79, -243), Pair(79, -157), Pair(85, -165), Pair(85, -126), Pair(87, -90), Pair(91, -87), Pair(93, -70),
  Pair(96, -63), Pair(98, -56), Pair(99, -45), Pair(101, -44), Pair(103, -41), Pair(105, -41), Pair(112, -50), Pair(114, -50),
  Pair(123, -66), Pair(132, -88), Pair(158, -119), Pair(166, -135), Pair(200, -176), Pair(321, -278), Pair(325, -287), Pair(361, -351),
  Pair(374, -364), Pair(358, -397), Pair(316, -347), Pair(105, -337)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-17, -58), Pair(-14, -43), Pair(3, -23), Pair(33, 0), Pair(75, 22), Pair(101, 11), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, -2), Pair(18, 3), Pair(23, 15), Pair(54, 48), Pair(168, 92), Pair(17, 460), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(23, 1), Pair(18, 0), Pair(20, 9), Pair(48, 24), Pair(196, -22), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-60, -24), Pair(-16, -6), Pair(-21, -14), Pair(-24, -8), Pair(-19, -2), Pair(-17, -18), Pair(-16, -26), Pair(-44, -25)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(15, -6), Pair(-6, -9), Pair(-12, -6), Pair(-19, -7), Pair(-15, -10), Pair(-4, -4), Pair(-7, -14), Pair(6, 2)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(31, -3), Pair(30, -9), Pair(22, 3), Pair(34, 2), Pair(36, 2), Pair(43, 0), Pair(47, -15), Pair(49, -7)
  },
  {
      Pair(33, 3), Pair(28, -10), Pair(31, -13), Pair(26, -3), Pair(30, -11), Pair(17, -11), Pair(35, -18), Pair(35, -7)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(18, -8), Pair(17, -14), Pair(15, -8),
  Pair(21, -10), Pair(16, -5), Pair(21, -9),
  Pair(25, 3), Pair(0, 0), Pair(16, 8),
  Pair(-5, 10), Pair(-43, 26), Pair(1, 13)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-13, 6), Pair(-16, 13), Pair(-11, 9),
  Pair(-11, 3), Pair(-22, 16), Pair(-10, 9),
  Pair(-1, -7), Pair(-14, 7), Pair(2, -5),
  Pair(10, -7), Pair(-18, 4), Pair(14, -8),
  Pair(35, -26), Pair(25, -7), Pair(36, -25),
  Pair(0, 0), Pair(-115, 6), Pair(0, 0),
  Pair(50, -57), Pair(0, 0), Pair(55, -58)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(6, 25), Pair(-19, 29), Pair(-10, 9), Pair(-16, -1), Pair(-19, 4), Pair(0, -3), Pair(-14, -15)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-3, -8), Pair(-1, 12), Pair(-6, 41), Pair(-5, 57), Pair(3, 66), Pair(1, 70), Pair(-29, 88)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-204, 190);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-181, 75), Pair(-106, 16), Pair(-9, -21), Pair(-18, -21), Pair(-10, -23), Pair(-10, -17), Pair(-59, 6), Pair(-88, 46)
  },
  {
      Pair(-89, 69), Pair(-51, 24), Pair(-29, 12), Pair(-15, -1), Pair(-8, -6), Pair(-13, 10), Pair(-25, 24), Pair(-37, 49)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -2), Pair(23, -2), Pair(57, -17), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, 4), Pair(18, 9), Pair(34, 7), Pair(-14, 6), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(23, -15), Pair(35, -16), Pair(53, -17), Pair(81, -21), Pair(41, -18), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 23), Pair(15, 35), Pair(34, 32), Pair(88, 4), Pair(144, -18), Pair(231, -49), Pair(221, -61)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(37, -5), Pair(16, 13), Pair(70, -19), Pair(27, -3), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-7, 36), Pair(1, 33)
  },
  {
      Pair(-88, 2), Pair(-73, -10)
  },
  {
      Pair(-65, -33), Pair(-60, -47)
  },
  {
      Pair(-88, -17), Pair(-71, -26)
  },
  {
      Pair(-61, 7), Pair(-63, 14)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(16, 37), Pair(30, 15), Pair(27, 14), Pair(28, -5), Pair(35, 11)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-2, -32), Pair(8, -14)
  },
  {
      Pair(26, -55), Pair(36, -68)
  },
  {
      Pair(-54, 2), Pair(-45, -19)
  },
  {
      Pair(-84, 8), Pair(-71, 5)
  },
  {
      Pair(-44, -11), Pair(-44, -33)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-18, -26), Pair(1, -10)
  },
  {
      Pair(-57, 3), Pair(-23, -30)
  },
  {
      Pair(6, -60), Pair(12, -73)
  },
  {
      Pair(-64, -7), Pair(-63, -22)
  },
  {
      Pair(-59, -33), Pair(-57, -16)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-7, -27), Pair(15, -18)
  },
  {
      Pair(-53, -3), Pair(-9, -11)
  },
  {
      Pair(-52, -8), Pair(-18, -6)
  },
  {
      Pair(-10, 55), Pair(-17, 84)
  },
  {
      Pair(-65, -45), Pair(-61, -41)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(65, 18), Pair(5, 28), Pair(31, 10), Pair(-4, 42), Pair(40, 29), Pair(15, 22), Pair(53, 19), Pair(65, 30),
  Pair(30, 21), Pair(17, 19), Pair(-4, 31), Pair(-3, 33), Pair(-2, 58), Pair(-13, 52), Pair(5, 20), Pair(26, -4),
  Pair(-2, 9), Pair(-20, 24), Pair(-2, 20), Pair(9, 17), Pair(-1, 30), Pair(-7, 6), Pair(-29, 35), Pair(15, 2)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-12, -55), Pair(44, 9), Pair(17, -8), Pair(60, -19), Pair(108, -10), Pair(67, -12), Pair(30, 34), Pair(11, 45),
  Pair(-31, -31), Pair(23, 18), Pair(2, 20), Pair(22, -2), Pair(18, 9), Pair(-18, 34), Pair(12, 33), Pair(8, 55),
  Pair(-1, 16), Pair(12, 14), Pair(9, 8), Pair(31, 6), Pair(29, 12), Pair(-4, 22), Pair(-1, 21), Pair(-65, 74)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 67);

constexpr ScorePair kTempoBonus = Pair(20, 1);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H