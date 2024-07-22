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
  Pair(75, 133), Pair(304, 330), Pair(322, 361), Pair(423, 615), Pair(872, 1080), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(39, 71), Pair(24, 74), Pair(11, 75), Pair(53, 31), Pair(42, 35), Pair(38, 46), Pair(-27, 89), Pair(-26, 84),
      Pair(6, 8), Pair(-13, 30), Pair(21, -15), Pair(28, -45), Pair(47, -49), Pair(66, -34), Pair(23, 13), Pair(9, 3),
      Pair(-19, -4), Pair(-19, 4), Pair(-12, -21), Pair(-4, -38), Pair(14, -39), Pair(9, -34), Pair(-11, -3), Pair(-6, -21),
      Pair(-24, -18), Pair(-28, 2), Pair(-15, -26), Pair(-3, -34), Pair(0, -34), Pair(1, -33), Pair(-15, -8), Pair(-11, -32),
      Pair(-34, -22), Pair(-38, -5), Pair(-27, -27), Pair(-20, -27), Pair(-15, -27), Pair(-17, -30), Pair(-19, -16), Pair(-16, -36),
      Pair(-26, -17), Pair(-29, 1), Pair(-20, -19), Pair(-22, -25), Pair(-13, -15), Pair(-3, -24), Pair(-6, -13), Pair(-14, -34),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-133, -50), Pair(-102, -11), Pair(-70, 7), Pair(-23, -11), Pair(-6, -6), Pair(-47, -29), Pair(-97, -10), Pair(-93, -72),
      Pair(-26, 0), Pair(-9, 12), Pair(0, 11), Pair(12, 9), Pair(9, -2), Pair(41, -7), Pair(4, 2), Pair(-3, -19),
      Pair(-4, 3), Pair(10, 12), Pair(11, 28), Pair(23, 22), Pair(33, 17), Pair(62, -6), Pair(5, 4), Pair(18, -15),
      Pair(8, 12), Pair(9, 17), Pair(28, 26), Pair(39, 26), Pair(30, 24), Pair(38, 23), Pair(17, 12), Pair(33, -1),
      Pair(-3, 15), Pair(12, 15), Pair(22, 32), Pair(27, 31), Pair(28, 34), Pair(38, 15), Pair(26, 12), Pair(11, 8),
      Pair(-24, 3), Pair(-2, 11), Pair(5, 19), Pair(17, 31), Pair(28, 28), Pair(14, 11), Pair(15, 4), Pair(-1, 7),
      Pair(-28, 3), Pair(-16, 11), Pair(-5, 14), Pair(7, 14), Pair(10, 12), Pair(0, 12), Pair(-1, 1), Pair(0, 13),
      Pair(-58, 7), Pair(-21, 4), Pair(-21, 9), Pair(-8, 16), Pair(1, 12), Pair(-2, 0), Pair(-19, 10), Pair(-22, -1)
  },
  {
      Pair(-29, 11), Pair(-50, 12), Pair(-52, 6), Pair(-83, 12), Pair(-82, 12), Pair(-74, 2), Pair(-38, 4), Pair(-58, 0),
      Pair(-20, -5), Pair(-12, 7), Pair(-11, 3), Pair(-24, 8), Pair(-25, 3), Pair(-14, 2), Pair(-36, 11), Pair(-39, -1),
      Pair(-7, 10), Pair(3, 7), Pair(-6, 13), Pair(-3, 5), Pair(-9, 9), Pair(27, 13), Pair(13, 9), Pair(7, 10),
      Pair(-19, 9), Pair(-8, 12), Pair(-3, 13), Pair(11, 18), Pair(7, 12), Pair(1, 16), Pair(-12, 8), Pair(-17, 7),
      Pair(-11, 3), Pair(-22, 14), Pair(-6, 12), Pair(10, 12), Pair(9, 8), Pair(-7, 12), Pair(-15, 11), Pair(3, -7),
      Pair(-17, 3), Pair(4, 11), Pair(2, 13), Pair(-1, 18), Pair(0, 22), Pair(4, 12), Pair(7, 4), Pair(2, -5),
      Pair(-2, 5), Pair(2, -7), Pair(9, -3), Pair(-8, 10), Pair(3, 7), Pair(7, 2), Pair(18, -1), Pair(10, -12),
      Pair(-10, -7), Pair(9, 13), Pair(-12, 9), Pair(-14, 8), Pair(-3, 3), Pair(-16, 14), Pair(-4, -1), Pair(16, -27)
  },
  {
      Pair(-18, 45), Pair(-19, 54), Pair(-14, 56), Pair(-19, 54), Pair(-7, 43), Pair(11, 45), Pair(-1, 48), Pair(-23, 46),
      Pair(-17, 40), Pair(-15, 52), Pair(-4, 50), Pair(14, 39), Pair(-2, 37), Pair(15, 40), Pair(13, 37), Pair(-9, 35),
      Pair(-20, 41), Pair(7, 42), Pair(2, 41), Pair(1, 38), Pair(23, 26), Pair(35, 23), Pair(48, 24), Pair(0, 23),
      Pair(-20, 42), Pair(-8, 44), Pair(-5, 45), Pair(-3, 41), Pair(1, 27), Pair(2, 27), Pair(2, 30), Pair(-17, 27),
      Pair(-25, 35), Pair(-25, 44), Pair(-16, 39), Pair(-11, 39), Pair(-10, 32), Pair(-28, 39), Pair(-6, 27), Pair(-25, 23),
      Pair(-28, 31), Pair(-22, 34), Pair(-16, 31), Pair(-16, 34), Pair(-9, 25), Pair(-10, 24), Pair(12, 8), Pair(-11, 6),
      Pair(-27, 24), Pair(-20, 32), Pair(-8, 30), Pair(-9, 30), Pair(-3, 20), Pair(-10, 22), Pair(1, 13), Pair(-29, 11),
      Pair(-16, 27), Pair(-12, 26), Pair(-9, 30), Pair(-6, 26), Pair(-2, 16), Pair(-12, 22), Pair(-13, 21), Pair(-19, 13)
  },
  {
      Pair(-41, 66), Pair(-40, 66), Pair(-28, 84), Pair(-3, 73), Pair(-15, 80), Pair(-12, 80), Pair(34, 25), Pair(-12, 60),
      Pair(-8, 52), Pair(-21, 73), Pair(-26, 106), Pair(-40, 119), Pair(-57, 142), Pair(-15, 102), Pair(-8, 81), Pair(26, 70),
      Pair(-6, 58), Pair(-9, 70), Pair(-13, 99), Pair(-12, 101), Pair(-11, 111), Pair(16, 90), Pair(16, 67), Pair(14, 64),
      Pair(-15, 68), Pair(-11, 84), Pair(-11, 94), Pair(-14, 108), Pair(-13, 107), Pair(-4, 88), Pair(6, 85), Pair(4, 69),
      Pair(-11, 63), Pair(-17, 96), Pair(-12, 96), Pair(-10, 111), Pair(-5, 101), Pair(-11, 91), Pair(5, 77), Pair(2, 69),
      Pair(-9, 51), Pair(-7, 75), Pair(-10, 91), Pair(-12, 93), Pair(-11, 96), Pair(-3, 82), Pair(12, 63), Pair(6, 50),
      Pair(-6, 45), Pair(-4, 50), Pair(-1, 55), Pair(1, 67), Pair(1, 66), Pair(3, 40), Pair(11, 19), Pair(18, 2),
      Pair(-18, 53), Pair(-14, 48), Pair(-12, 55), Pair(-9, 53), Pair(-6, 39), Pair(-20, 35), Pair(-16, 31), Pair(-5, 27)
  },
  {
      Pair(75, -93), Pair(98, -54), Pair(74, -32), Pair(-34, 4), Pair(-9, -11), Pair(-77, 5), Pair(-18, -11), Pair(97, -113),
      Pair(-94, 5), Pair(-3, 27), Pair(-23, 32), Pair(69, 14), Pair(-5, 27), Pair(-28, 45), Pair(-29, 38), Pair(-101, 16),
      Pair(-76, 6), Pair(66, 16), Pair(3, 34), Pair(-38, 48), Pair(-4, 46), Pair(56, 32), Pair(-23, 36), Pair(-52, 4),
      Pair(-43, -11), Pair(7, 5), Pair(-36, 30), Pair(-96, 50), Pair(-98, 45), Pair(-58, 33), Pair(-40, 11), Pair(-141, 8),
      Pair(-45, -27), Pair(7, -8), Pair(-43, 21), Pair(-92, 43), Pair(-89, 37), Pair(-43, 14), Pair(-42, -3), Pair(-124, -8),
      Pair(-30, -29), Pair(27, -15), Pair(-20, 9), Pair(-35, 23), Pair(-33, 19), Pair(-29, 7), Pair(-6, -14), Pair(-52, -22),
      Pair(21, -40), Pair(7, -11), Pair(6, -2), Pair(-15, 8), Pair(-20, 8), Pair(-10, -2), Pair(5, -19), Pair(9, -41),
      Pair(4, -64), Pair(33, -40), Pair(23, -23), Pair(-36, -3), Pair(5, -25), Pair(-23, -13), Pair(14, -36), Pair(6, -69)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-33, 0), Pair(-19, 2), Pair(-9, 22), Pair(-3, 30), Pair(2, 35), Pair(7, 42), Pair(14, 39), Pair(18, 36),
  Pair(21, 27)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-24, -16), Pair(-15, -18), Pair(-6, -3), Pair(-1, 7), Pair(6, 15), Pair(8, 23), Pair(10, 26), Pair(11, 30),
  Pair(13, 32), Pair(17, 30), Pair(26, 27), Pair(32, 27), Pair(29, 40), Pair(38, 21)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-30, -30), Pair(-21, -3), Pair(-17, 3), Pair(-17, 17), Pair(-18, 21), Pair(-14, 24), Pair(-13, 29), Pair(-11, 32),
  Pair(-9, 36), Pair(-7, 38), Pair(-3, 40), Pair(-2, 44), Pair(2, 45), Pair(5, 44), Pair(2, 42)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-70, -124), Pair(-15, -250), Pair(-23, -33), Pair(-16, 14), Pair(-16, 55), Pair(-15, 75), Pair(-12, 88), Pair(-11, 102),
  Pair(-9, 110), Pair(-7, 111), Pair(-5, 115), Pair(-5, 123), Pair(-1, 119), Pair(-2, 123), Pair(1, 122), Pair(5, 119),
  Pair(4, 122), Pair(7, 119), Pair(16, 107), Pair(29, 93), Pair(35, 85), Pair(78, 53), Pair(73, 48), Pair(92, 21),
  Pair(138, 4), Pair(241, -78), Pair(160, -32), Pair(82, -16)
};

constexpr QueenMobilityTable<ScorePair> kKingVirtualMobility = {
  Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(27, -24), Pair(29, -22), Pair(9, 1), Pair(6, -1), Pair(2, -6),
  Pair(-1, -4), Pair(-5, -6), Pair(-3, -4), Pair(-9, 1), Pair(-9, -2), Pair(-12, 0), Pair(-18, 4), Pair(-23, 8),
  Pair(-28, 9), Pair(-28, 7), Pair(-33, 8), Pair(-34, 7), Pair(-25, 3), Pair(-17, 2), Pair(-15, -1), Pair(0, -5),
  Pair(-4, -5), Pair(22, -12), Pair(8, -10), Pair(63, -21)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-10, -65), Pair(-11, -51), Pair(-9, -19), Pair(17, 16), Pair(12, 84), Pair(35, 80), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 0), Pair(15, 7), Pair(21, 17), Pair(47, 59), Pair(124, 189), Pair(-46, 409), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(14, 5), Pair(14, 13), Pair(22, 40), Pair(149, 31), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -45), Pair(10, -37), Pair(1, -25), Pair(-2, -13), Pair(-10, -5), Pair(-8, -19), Pair(9, -33), Pair(-5, -49)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-7, 12), Pair(-2, -12), Pair(-11, -4), Pair(-8, -12), Pair(-11, -14), Pair(-4, -6), Pair(1, -13), Pair(-5, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(25, 5), Pair(21, 1), Pair(18, 7), Pair(19, 6), Pair(21, 11), Pair(33, 3), Pair(40, 2), Pair(69, -2)
  },
  {
      Pair(3, 28), Pair(5, 6), Pair(6, 5), Pair(14, -4), Pair(9, -1), Pair(12, -5), Pair(19, -2), Pair(13, 15)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -6), Pair(16, -5), Pair(8, -2),
  Pair(19, -11), Pair(12, -10), Pair(16, -11),
  Pair(27, -4), Pair(0, 0), Pair(24, -3),
  Pair(-9, 4), Pair(-13, 0), Pair(-9, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, 1), Pair(-13, 2), Pair(-8, 3),
  Pair(-6, 0), Pair(-15, 4), Pair(-9, 3),
  Pair(0, -7), Pair(-11, 0), Pair(-1, -5),
  Pair(12, -8), Pair(-3, -5), Pair(10, -6),
  Pair(30, -8), Pair(24, 0), Pair(23, -8),
  Pair(0, 0), Pair(10, -31), Pair(0, 0),
  Pair(54, -47), Pair(0, 0), Pair(46, -44)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-4, 64), Pair(-7, 50), Pair(2, 29), Pair(5, 19), Pair(9, 17), Pair(21, 15), Pair(10, 12)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-81, -7), Pair(-7, -5), Pair(-10, 18), Pair(-3, 26), Pair(0, 32), Pair(0, 37), Pair(-14, 34)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-345, 200);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-47, -15), Pair(-69, -4), Pair(-41, -6), Pair(-29, -5), Pair(-23, 0), Pair(-40, 3), Pair(-51, 4), Pair(-26, 2)
  },
  {
      Pair(-14, 46), Pair(-37, 19), Pair(-21, 12), Pair(-2, -5), Pair(-5, -7), Pair(-10, 5), Pair(-30, 23), Pair(-14, 32)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -1), Pair(27, -10), Pair(68, -35), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 0), Pair(30, -3), Pair(60, -11), Pair(59, -38), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -19), Pair(34, -21), Pair(54, -16), Pair(80, -18), Pair(93, -29), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 12), Pair(11, 24), Pair(32, 29), Pair(75, 11), Pair(108, 9), Pair(164, -10), Pair(218, -51)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(32, 14), Pair(25, 21), Pair(51, 2), Pair(25, 15), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-14, 16), Pair(-62, -23), Pair(-63, -52), Pair(-84, -5), Pair(-76, 31), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -15), Pair(13, -1), Pair(-29, -37), Pair(-67, -14), Pair(-51, 27), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -17), Pair(-18, -26), Pair(8, -27), Pair(-49, -22), Pair(-63, -47), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(0, -22), Pair(-14, -27), Pair(-20, -30), Pair(23, -36), Pair(-77, -5), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(11, 23), Pair(13, 11), Pair(27, 20), Pair(36, 19), Pair(38, 26), Pair(23, 44), Pair(39, 16), Pair(-6, 37),
  Pair(-2, 13), Pair(12, 15), Pair(10, 20), Pair(0, 33), Pair(6, 20), Pair(3, 22), Pair(12, 15), Pair(-7, 24),
  Pair(6, 7), Pair(0, 1), Pair(-3, 14), Pair(2, 14), Pair(0, 19), Pair(-12, 18), Pair(-4, 6), Pair(-3, 6)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-12, 11), Pair(16, -1), Pair(20, 1), Pair(35, 0), Pair(58, -15), Pair(37, -4), Pair(23, -11), Pair(-14, -30),
  Pair(-25, -10), Pair(20, 5), Pair(8, 2), Pair(16, 10), Pair(9, 3), Pair(17, -2), Pair(13, 11), Pair(17, -22),
  Pair(-24, 28), Pair(6, 4), Pair(1, 17), Pair(14, 12), Pair(19, 21), Pair(0, 7), Pair(11, -1), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 59);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H