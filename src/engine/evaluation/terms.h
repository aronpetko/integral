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
  Pair(86, 176), Pair(298, 321), Pair(334, 347), Pair(409, 704), Pair(862, 1269), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(41, 139), Pair(41, 138), Pair(25, 143), Pair(59, 101), Pair(55, 104), Pair(46, 116), Pair(-3, 154), Pair(-19, 155),
      Pair(-4, -20), Pair(-18, -1), Pair(22, -45), Pair(24, -74), Pair(37, -76), Pair(68, -64), Pair(22, -16), Pair(-2, -26),
      Pair(-24, -36), Pair(-26, -29), Pair(-10, -55), Pair(-5, -72), Pair(17, -75), Pair(9, -68), Pair(-7, -39), Pair(-15, -54),
      Pair(-32, -52), Pair(-37, -36), Pair(-19, -62), Pair(-2, -69), Pair(-1, -72), Pair(0, -69), Pair(-15, -48), Pair(-17, -68),
      Pair(-31, -56), Pair(-32, -41), Pair(-16, -62), Pair(-12, -62), Pair(0, -63), Pair(-6, -66), Pair(-2, -54), Pair(-12, -72),
      Pair(-31, -51), Pair(-33, -34), Pair(-22, -54), Pair(-24, -57), Pair(-13, -49), Pair(2, -61), Pair(3, -50), Pair(-24, -69),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-130, -36), Pair(-106, 12), Pair(-56, 27), Pair(-25, 13), Pair(-6, 17), Pair(-59, -5), Pair(-94, 11), Pair(-95, -54),
      Pair(-7, 17), Pair(14, 27), Pair(39, 22), Pair(42, 22), Pair(18, 15), Pair(79, 4), Pair(11, 23), Pair(21, -3),
      Pair(10, 21), Pair(41, 25), Pair(43, 44), Pair(35, 43), Pair(68, 30), Pair(70, 15), Pair(35, 18), Pair(19, 9),
      Pair(15, 33), Pair(11, 39), Pair(29, 48), Pair(53, 44), Pair(21, 50), Pair(44, 49), Pair(1, 46), Pair(36, 21),
      Pair(3, 35), Pair(13, 35), Pair(22, 52), Pair(27, 48), Pair(31, 53), Pair(37, 38), Pair(32, 33), Pair(17, 29),
      Pair(-16, 23), Pair(4, 31), Pair(11, 36), Pair(21, 51), Pair(37, 47), Pair(19, 31), Pair(24, 25), Pair(6, 27),
      Pair(-20, 23), Pair(-8, 30), Pair(4, 32), Pair(19, 30), Pair(20, 29), Pair(20, 27), Pair(12, 20), Pair(9, 32),
      Pair(-52, 26), Pair(-14, 17), Pair(-15, 27), Pair(-1, 32), Pair(7, 32), Pair(12, 20), Pair(-10, 23), Pair(-17, 19)
  },
  {
      Pair(-47, 31), Pair(-72, 33), Pair(-70, 28), Pair(-113, 36), Pair(-109, 36), Pair(-104, 24), Pair(-61, 26), Pair(-79, 21),
      Pair(-29, 12), Pair(-4, 22), Pair(-18, 24), Pair(-31, 28), Pair(-20, 19), Pair(-27, 23), Pair(-33, 29), Pair(-45, 17),
      Pair(-20, 30), Pair(-4, 26), Pair(-5, 32), Pair(-1, 20), Pair(-23, 29), Pair(10, 35), Pair(-4, 33), Pair(-11, 30),
      Pair(-27, 27), Pair(-16, 31), Pair(-7, 31), Pair(0, 42), Pair(-2, 36), Pair(-9, 38), Pair(-20, 25), Pair(-33, 29),
      Pair(-21, 22), Pair(-31, 31), Pair(-19, 35), Pair(0, 34), Pair(-1, 30), Pair(-19, 31), Pair(-23, 31), Pair(-7, 11),
      Pair(-23, 22), Pair(-6, 34), Pair(-7, 35), Pair(-9, 38), Pair(-6, 42), Pair(-3, 35), Pair(-2, 27), Pair(-2, 16),
      Pair(-10, 28), Pair(-7, 14), Pair(1, 17), Pair(-15, 27), Pair(-4, 27), Pair(6, 20), Pair(15, 20), Pair(1, 9),
      Pair(-22, 16), Pair(1, 31), Pair(-21, 21), Pair(-24, 26), Pair(-15, 23), Pair(-20, 32), Pair(-7, 16), Pair(6, -5)
  },
  {
      Pair(-2, 2), Pair(-9, 13), Pair(-7, 15), Pair(-13, 12), Pair(-5, 4), Pair(16, 10), Pair(10, 10), Pair(-4, 6),
      Pair(-4, 5), Pair(-6, 21), Pair(12, 18), Pair(24, 9), Pair(8, 9), Pair(34, 7), Pair(23, 3), Pair(12, -3),
      Pair(-14, 2), Pair(12, 6), Pair(11, 3), Pair(7, 1), Pair(34, -10), Pair(42, -8), Pair(63, -13), Pair(13, -17),
      Pair(-17, 2), Pair(-3, 4), Pair(1, 5), Pair(4, 2), Pair(7, -11), Pair(7, -4), Pair(7, -5), Pair(-9, -12),
      Pair(-23, -10), Pair(-24, 0), Pair(-13, -5), Pair(-8, -6), Pair(-6, -10), Pair(-23, 2), Pair(-1, -13), Pair(-17, -20),
      Pair(-25, -18), Pair(-19, -14), Pair(-13, -17), Pair(-14, -13), Pair(-2, -21), Pair(-6, -17), Pair(19, -36), Pair(-2, -40),
      Pair(-24, -26), Pair(-17, -17), Pair(-3, -19), Pair(-3, -19), Pair(3, -26), Pair(6, -24), Pair(13, -35), Pair(-19, -38),
      Pair(-10, -21), Pair(-5, -21), Pair(1, -16), Pair(5, -22), Pair(12, -28), Pair(7, -20), Pair(1, -26), Pair(-6, -37)
  },
  {
      Pair(-49, -4), Pair(-56, 8), Pair(-41, 27), Pair(-17, 10), Pair(-27, 15), Pair(-18, 17), Pair(28, -36), Pair(-29, -3),
      Pair(-6, -16), Pair(-24, 15), Pair(-28, 46), Pair(-38, 62), Pair(-58, 83), Pair(-11, 31), Pair(-11, 24), Pair(40, -1),
      Pair(-5, -4), Pair(-9, 10), Pair(-9, 41), Pair(-8, 43), Pair(-12, 54), Pair(16, 30), Pair(20, 6), Pair(11, -3),
      Pair(-13, 5), Pair(-9, 22), Pair(-8, 28), Pair(-14, 48), Pair(-11, 47), Pair(-1, 28), Pair(5, 25), Pair(3, 7),
      Pair(-8, -3), Pair(-14, 24), Pair(-9, 21), Pair(-4, 35), Pair(0, 34), Pair(-7, 22), Pair(8, 10), Pair(6, -2),
      Pair(-5, -21), Pair(-1, -2), Pair(-1, 8), Pair(-4, 13), Pair(2, 18), Pair(5, 11), Pair(18, -9), Pair(12, -23),
      Pair(1, -33), Pair(3, -28), Pair(8, -23), Pair(14, -18), Pair(12, -12), Pair(22, -40), Pair(26, -59), Pair(29, -80),
      Pair(-6, -32), Pair(-1, -29), Pair(3, -22), Pair(6, -12), Pair(10, -27), Pair(0, -36), Pair(5, -51), Pair(7, -57)
  },
  {
      Pair(70, -88), Pair(78, -41), Pair(49, -22), Pair(-76, 18), Pair(-48, -1), Pair(-50, 6), Pair(25, -12), Pair(148, -117),
      Pair(-62, 3), Pair(11, 25), Pair(-33, 34), Pair(50, 20), Pair(-11, 30), Pair(-14, 46), Pair(16, 33), Pair(-56, 11),
      Pair(-66, 4), Pair(80, 12), Pair(-14, 35), Pair(-45, 47), Pair(-19, 45), Pair(60, 28), Pair(8, 31), Pair(-35, 2),
      Pair(-36, -15), Pair(12, 3), Pair(-50, 29), Pair(-108, 46), Pair(-109, 41), Pair(-67, 30), Pair(-47, 11), Pair(-117, 1),
      Pair(-40, -29), Pair(-2, -7), Pair(-63, 22), Pair(-106, 42), Pair(-106, 36), Pair(-59, 15), Pair(-50, -2), Pair(-119, -9),
      Pair(-18, -30), Pair(25, -13), Pair(-35, 11), Pair(-52, 27), Pair(-48, 22), Pair(-42, 9), Pair(-8, -13), Pair(-41, -22),
      Pair(38, -40), Pair(9, -10), Pair(1, 1), Pair(-21, 12), Pair(-27, 12), Pair(-14, 0), Pair(9, -17), Pair(23, -40),
      Pair(26, -65), Pair(42, -39), Pair(29, -24), Pair(-33, -2), Pair(13, -26), Pair(-22, -11), Pair(25, -35), Pair(36, -75)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-34, -11), Pair(-21, -2), Pair(-12, 18), Pair(-6, 27), Pair(-1, 34), Pair(5, 42), Pair(12, 41), Pair(17, 39),
  Pair(21, 31)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-29, -25), Pair(-19, -21), Pair(-9, -4), Pair(-3, 9), Pair(4, 18), Pair(8, 29), Pair(10, 32), Pair(12, 35),
  Pair(13, 39), Pair(16, 37), Pair(25, 33), Pair(30, 33), Pair(27, 47), Pair(30, 26)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-21, -54), Pair(-13, -24), Pair(-10, -20), Pair(-7, -15), Pair(-10, -7), Pair(-5, -3), Pair(-4, 3), Pair(-3, 5),
  Pair(0, 8), Pair(2, 12), Pair(5, 13), Pair(3, 18), Pair(5, 20), Pair(6, 15), Pair(-1, 14)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-1, -251), Pair(1, -236), Pair(-10, -96), Pair(-8, -50), Pair(-7, -25), Pair(-5, -14), Pair(-2, 4), Pair(-1, 16),
  Pair(1, 22), Pair(3, 25), Pair(4, 31), Pair(6, 36), Pair(8, 36), Pair(7, 42), Pair(9, 43), Pair(10, 45),
  Pair(9, 53), Pair(10, 51), Pair(18, 46), Pair(31, 36), Pair(33, 35), Pair(80, 5), Pair(64, 13), Pair(81, -9),
  Pair(182, -49), Pair(200, -84), Pair(118, -28), Pair(77, -27)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-6, -7), Pair(-11, 8), Pair(-8, 43), Pair(15, 79), Pair(12, 146), Pair(22, 39), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-2, 0), Pair(18, 10), Pair(43, 48), Pair(122, 175), Pair(-134, 439), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-4, -47), Pair(10, -39), Pair(-5, -27), Pair(-4, -16), Pair(-13, -7), Pair(-15, -22), Pair(1, -33), Pair(-6, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-17, 8), Pair(-7, -16), Pair(-17, -11), Pair(-15, -20), Pair(-19, -20), Pair(-9, -11), Pair(-6, -16), Pair(-9, 3)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 12), Pair(28, 7), Pair(24, 14), Pair(27, 12), Pair(29, 15), Pair(39, 2), Pair(49, 3), Pair(76, 2)
  },
  {
      Pair(3, 52), Pair(8, 24), Pair(7, 22), Pair(17, 11), Pair(12, 10), Pair(15, 4), Pair(24, 9), Pair(11, 34)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(19, -1), Pair(12, -2),
  Pair(25, -10), Pair(21, -7), Pair(24, -12),
  Pair(33, -2), Pair(0, 0), Pair(30, -1),
  Pair(-11, 4), Pair(-14, 4), Pair(-11, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-14, 4), Pair(-8, 4),
  Pair(-6, 2), Pair(-15, 6), Pair(-8, 4),
  Pair(-1, -6), Pair(-12, 0), Pair(-1, -5),
  Pair(14, -9), Pair(-6, -4), Pair(12, -6),
  Pair(32, -8), Pair(23, -1), Pair(25, -9),
  Pair(0, 0), Pair(0, -32), Pair(0, 0),
  Pair(48, -50), Pair(0, 0), Pair(42, -48)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-18, 17), Pair(-24, 2), Pair(-16, -19), Pair(-14, -29), Pair(-8, -32), Pair(5, -35), Pair(-4, -36)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-66, -22), Pair(10, -22), Pair(8, 2), Pair(13, 12), Pair(11, 19), Pair(9, 25), Pair(-6, 23)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-88, -6), Pair(-96, 1), Pair(-56, -5), Pair(-49, -3), Pair(-38, 2), Pair(-64, 7), Pair(-64, 8), Pair(-51, 10)
  },
  {
      Pair(-23, 55), Pair(-41, 24), Pair(-21, 16), Pair(-3, -2), Pair(-6, -4), Pair(-14, 9), Pair(-32, 26), Pair(-30, 40)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 3), Pair(34, -7), Pair(80, -22), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 4), Pair(34, -5), Pair(55, -15), Pair(61, -45), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -15), Pair(35, -18), Pair(57, -17), Pair(87, -23), Pair(103, -37), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 9), Pair(15, 23), Pair(39, 31), Pair(86, 19), Pair(126, 22), Pair(214, -24), Pair(233, -37)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(3, 23), Pair(-4, 15), Pair(12, 24), Pair(29, 26), Pair(16, 36), Pair(19, 49), Pair(24, 21), Pair(-8, 39),
  Pair(0, 19), Pair(15, 17), Pair(12, 23), Pair(4, 37), Pair(8, 26), Pair(9, 21), Pair(19, 14), Pair(1, 27),
  Pair(9, 14), Pair(2, 7), Pair(1, 19), Pair(6, 22), Pair(4, 26), Pair(-7, 21), Pair(0, 10), Pair(-1, 11)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-13, 13), Pair(12, -2), Pair(13, 0), Pair(24, 3), Pair(60, -15), Pair(39, -7), Pair(29, -17), Pair(-18, -26),
  Pair(-20, -6), Pair(22, 4), Pair(8, 1), Pair(22, 7), Pair(13, 2), Pair(24, -4), Pair(14, 13), Pair(22, -26),
  Pair(-25, 28), Pair(11, 4), Pair(5, 18), Pair(18, 13), Pair(23, 21), Pair(3, 9), Pair(16, -2), Pair(-50, 12)
};

constexpr FileTable<ScorePair> kRookBehindPassedPawnBonus = {
  Pair(10, 34), Pair(25, 29), Pair(13, 16), Pair(17, 1), Pair(14, -8), Pair(5, -6), Pair(-12, 21), Pair(-6, 6)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 64);

constexpr ScorePair kTempoBonus = Pair(20, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H