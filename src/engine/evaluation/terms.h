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
  Pair(85, 176), Pair(298, 323), Pair(334, 348), Pair(409, 704), Pair(863, 1270), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(45, 142), Pair(46, 140), Pair(27, 145), Pair(59, 102), Pair(55, 103), Pair(43, 116), Pair(-4, 156), Pair(-25, 157),
      Pair(-2, -19), Pair(-14, 0), Pair(23, -45), Pair(25, -74), Pair(39, -77), Pair(68, -64), Pair(20, -15), Pair(-3, -25),
      Pair(-23, -36), Pair(-23, -28), Pair(-9, -54), Pair(-4, -71), Pair(19, -75), Pair(9, -68), Pair(-10, -38), Pair(-14, -53),
      Pair(-31, -52), Pair(-34, -35), Pair(-17, -61), Pair(-1, -69), Pair(0, -71), Pair(1, -69), Pair(-18, -48), Pair(-16, -67),
      Pair(-30, -56), Pair(-29, -40), Pair(-15, -62), Pair(-10, -62), Pair(1, -62), Pair(-5, -66), Pair(-4, -53), Pair(-11, -71),
      Pair(-30, -51), Pair(-30, -34), Pair(-20, -54), Pair(-22, -57), Pair(-11, -48), Pair(3, -61), Pair(1, -49), Pair(-24, -69),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-131, -38), Pair(-107, 11), Pair(-58, 25), Pair(-26, 11), Pair(-7, 16), Pair(-61, -6), Pair(-94, 9), Pair(-97, -55),
      Pair(-8, 16), Pair(12, 26), Pair(37, 21), Pair(41, 20), Pair(17, 14), Pair(77, 3), Pair(10, 22), Pair(19, -5),
      Pair(9, 19), Pair(39, 23), Pair(42, 42), Pair(34, 42), Pair(66, 28), Pair(69, 14), Pair(33, 17), Pair(18, 8),
      Pair(13, 31), Pair(9, 38), Pair(27, 47), Pair(51, 43), Pair(19, 48), Pair(43, 47), Pair(-1, 44), Pair(35, 20),
      Pair(1, 33), Pair(11, 34), Pair(21, 50), Pair(25, 46), Pair(30, 52), Pair(36, 36), Pair(31, 32), Pair(15, 28),
      Pair(-18, 21), Pair(3, 30), Pair(9, 35), Pair(19, 49), Pair(35, 46), Pair(17, 30), Pair(23, 24), Pair(5, 26),
      Pair(-22, 21), Pair(-10, 28), Pair(2, 30), Pair(17, 29), Pair(18, 28), Pair(18, 26), Pair(10, 19), Pair(7, 31),
      Pair(-53, 24), Pair(-16, 15), Pair(-17, 26), Pair(-3, 30), Pair(6, 30), Pair(10, 19), Pair(-11, 22), Pair(-19, 17)
  },
  {
      Pair(-47, 30), Pair(-72, 32), Pair(-70, 27), Pair(-113, 35), Pair(-109, 35), Pair(-104, 23), Pair(-61, 24), Pair(-79, 20),
      Pair(-29, 12), Pair(-4, 21), Pair(-18, 22), Pair(-31, 27), Pair(-20, 18), Pair(-27, 22), Pair(-33, 28), Pair(-44, 16),
      Pair(-19, 30), Pair(-3, 25), Pair(-5, 31), Pair(-1, 19), Pair(-23, 28), Pair(10, 34), Pair(-4, 32), Pair(-10, 29),
      Pair(-26, 26), Pair(-16, 30), Pair(-7, 30), Pair(0, 41), Pair(-1, 34), Pair(-9, 37), Pair(-20, 24), Pair(-33, 29),
      Pair(-21, 21), Pair(-30, 30), Pair(-18, 34), Pair(0, 33), Pair(-1, 29), Pair(-19, 30), Pair(-23, 30), Pair(-7, 10),
      Pair(-22, 21), Pair(-6, 33), Pair(-7, 34), Pair(-9, 37), Pair(-6, 41), Pair(-3, 34), Pair(-2, 25), Pair(-1, 15),
      Pair(-10, 27), Pair(-7, 13), Pair(2, 16), Pair(-15, 26), Pair(-4, 26), Pair(7, 19), Pair(15, 19), Pair(1, 8),
      Pair(-21, 15), Pair(1, 30), Pair(-21, 20), Pair(-24, 25), Pair(-15, 22), Pair(-20, 30), Pair(-7, 15), Pair(6, -6)
  },
  {
      Pair(-2, 4), Pair(-9, 15), Pair(-8, 16), Pair(-13, 10), Pair(-5, 2), Pair(16, 10), Pair(9, 10), Pair(-5, 6),
      Pair(-5, 7), Pair(-6, 24), Pair(11, 19), Pair(23, 8), Pair(7, 7), Pair(34, 7), Pair(23, 4), Pair(12, -2),
      Pair(-14, 4), Pair(12, 9), Pair(10, 5), Pair(7, 0), Pair(33, -13), Pair(42, -8), Pair(63, -12), Pair(13, -16),
      Pair(-18, 4), Pair(-3, 7), Pair(0, 7), Pair(3, 0), Pair(7, -14), Pair(7, -5), Pair(7, -4), Pair(-10, -12),
      Pair(-24, -8), Pair(-25, 4), Pair(-13, -4), Pair(-8, -8), Pair(-6, -13), Pair(-24, 1), Pair(-2, -12), Pair(-17, -20),
      Pair(-26, -15), Pair(-19, -11), Pair(-13, -15), Pair(-15, -14), Pair(-2, -24), Pair(-6, -18), Pair(19, -35), Pair(-3, -40),
      Pair(-25, -23), Pair(-17, -14), Pair(-4, -18), Pair(-3, -20), Pair(2, -29), Pair(6, -25), Pair(12, -34), Pair(-19, -38),
      Pair(-10, -19), Pair(-5, -17), Pair(0, -15), Pair(5, -24), Pair(12, -30), Pair(7, -20), Pair(0, -25), Pair(-7, -36)
  },
  {
      Pair(-50, -5), Pair(-56, 8), Pair(-42, 26), Pair(-17, 9), Pair(-28, 15), Pair(-18, 16), Pair(27, -36), Pair(-30, -4),
      Pair(-7, -17), Pair(-25, 14), Pair(-29, 45), Pair(-38, 62), Pair(-60, 83), Pair(-12, 31), Pair(-12, 25), Pair(38, 0),
      Pair(-5, -5), Pair(-10, 10), Pair(-10, 41), Pair(-9, 43), Pair(-13, 54), Pair(15, 30), Pair(19, 6), Pair(10, -2),
      Pair(-14, 5), Pair(-10, 22), Pair(-9, 28), Pair(-14, 48), Pair(-12, 47), Pair(-2, 28), Pair(4, 25), Pair(2, 7),
      Pair(-9, -3), Pair(-15, 23), Pair(-10, 20), Pair(-4, 35), Pair(-1, 33), Pair(-7, 22), Pair(7, 11), Pair(5, -2),
      Pair(-6, -21), Pair(-1, -3), Pair(-1, 8), Pair(-5, 13), Pair(1, 18), Pair(4, 11), Pair(17, -10), Pair(11, -23),
      Pair(0, -33), Pair(2, -28), Pair(7, -23), Pair(13, -18), Pair(11, -12), Pair(22, -40), Pair(25, -59), Pair(28, -81),
      Pair(-7, -32), Pair(-2, -30), Pair(2, -22), Pair(5, -12), Pair(9, -28), Pair(-1, -37), Pair(5, -52), Pair(7, -58)
  },
  {
      Pair(71, -88), Pair(80, -41), Pair(50, -21), Pair(-76, 19), Pair(-47, 1), Pair(-47, 6), Pair(28, -11), Pair(151, -116),
      Pair(-62, 4), Pair(12, 27), Pair(-33, 36), Pair(50, 21), Pair(-11, 31), Pair(-14, 47), Pair(15, 34), Pair(-56, 12),
      Pair(-67, 5), Pair(80, 13), Pair(-14, 36), Pair(-46, 48), Pair(-19, 47), Pair(60, 30), Pair(8, 32), Pair(-35, 3),
      Pair(-37, -14), Pair(11, 5), Pair(-50, 31), Pair(-109, 48), Pair(-109, 42), Pair(-67, 32), Pair(-47, 13), Pair(-117, 3),
      Pair(-42, -27), Pair(-2, -6), Pair(-63, 23), Pair(-107, 43), Pair(-106, 38), Pair(-59, 17), Pair(-49, 0), Pair(-119, -8),
      Pair(-18, -29), Pair(25, -12), Pair(-35, 13), Pair(-52, 28), Pair(-47, 24), Pair(-42, 10), Pair(-8, -12), Pair(-41, -21),
      Pair(38, -39), Pair(10, -9), Pair(2, 2), Pair(-21, 13), Pair(-26, 13), Pair(-14, 2), Pair(9, -16), Pair(23, -39),
      Pair(27, -64), Pair(43, -37), Pair(29, -23), Pair(-33, -1), Pair(13, -25), Pair(-21, -10), Pair(26, -34), Pair(36, -73)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-33, -11), Pair(-20, -2), Pair(-10, 18), Pair(-5, 27), Pair(1, 34), Pair(6, 42), Pair(13, 41), Pair(18, 39),
  Pair(22, 30)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-28, -24), Pair(-19, -21), Pair(-9, -4), Pair(-2, 10), Pair(4, 19), Pair(8, 29), Pair(11, 33), Pair(12, 36),
  Pair(13, 39), Pair(17, 37), Pair(25, 33), Pair(30, 34), Pair(26, 47), Pair(30, 26)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-21, -54), Pair(-13, -25), Pair(-10, -21), Pair(-7, -16), Pair(-9, -8), Pair(-5, -4), Pair(-4, 2), Pair(-2, 4),
  Pair(0, 7), Pair(2, 11), Pair(5, 12), Pair(3, 17), Pair(5, 19), Pair(6, 14), Pair(0, 13)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-2, -251), Pair(0, -237), Pair(-11, -97), Pair(-9, -50), Pair(-8, -26), Pair(-5, -15), Pair(-3, 3), Pair(-2, 16),
  Pair(0, 22), Pair(2, 24), Pair(4, 30), Pair(5, 35), Pair(7, 36), Pair(6, 41), Pair(8, 43), Pair(9, 45),
  Pair(8, 52), Pair(9, 51), Pair(18, 46), Pair(30, 36), Pair(32, 35), Pair(80, 4), Pair(64, 12), Pair(81, -10),
  Pair(183, -52), Pair(200, -86), Pair(113, -28), Pair(73, -26)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-7, -7), Pair(-11, 8), Pair(-8, 43), Pair(15, 79), Pair(10, 147), Pair(20, 38), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-2, 0), Pair(18, 10), Pair(43, 48), Pair(122, 175), Pair(-125, 437), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-6, -47), Pair(9, -38), Pair(-5, -27), Pair(-4, -16), Pair(-13, -8), Pair(-15, -22), Pair(4, -33), Pair(-3, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-15, 8), Pair(-7, -16), Pair(-17, -11), Pair(-15, -20), Pair(-19, -21), Pair(-10, -11), Pair(-6, -16), Pair(-12, 4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 11), Pair(28, 4), Pair(24, 13), Pair(27, 14), Pair(29, 18), Pair(40, 3), Pair(51, 2), Pair(76, 3)
  },
  {
      Pair(4, 49), Pair(8, 20), Pair(7, 22), Pair(17, 13), Pair(11, 15), Pair(15, 6), Pair(25, 9), Pair(12, 35)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(19, -1), Pair(12, -1),
  Pair(25, -11), Pair(20, -7), Pair(24, -11),
  Pair(33, -2), Pair(0, 0), Pair(30, -1),
  Pair(-11, 5), Pair(-15, 4), Pair(-11, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-13, 4), Pair(-8, 4),
  Pair(-5, 2), Pair(-15, 6), Pair(-7, 4),
  Pair(-1, -6), Pair(-11, 0), Pair(-1, -5),
  Pair(14, -9), Pair(-5, -4), Pair(12, -6),
  Pair(32, -8), Pair(23, -1), Pair(26, -9),
  Pair(0, 0), Pair(1, -32), Pair(0, 0),
  Pair(49, -50), Pair(0, 0), Pair(43, -48)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-16, 18), Pair(-23, 4), Pair(-16, -17), Pair(-13, -28), Pair(-7, -31), Pair(7, -33), Pair(-3, -35)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-69, -23), Pair(7, -23), Pair(6, 1), Pair(11, 11), Pair(10, 18), Pair(8, 24), Pair(-8, 22)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-89, -6), Pair(-97, 1), Pair(-57, -5), Pair(-49, -3), Pair(-38, 1), Pair(-64, 6), Pair(-64, 7), Pair(-52, 9)
  },
  {
      Pair(-24, 54), Pair(-41, 24), Pair(-21, 16), Pair(-3, -1), Pair(-6, -4), Pair(-14, 9), Pair(-32, 26), Pair(-30, 40)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 4), Pair(34, -7), Pair(80, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 3), Pair(34, -6), Pair(55, -15), Pair(61, -45), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -15), Pair(35, -18), Pair(57, -17), Pair(88, -23), Pair(104, -37), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 9), Pair(16, 24), Pair(39, 31), Pair(86, 19), Pair(126, 22), Pair(213, -23), Pair(215, -23)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(4, 24), Pair(-4, 15), Pair(12, 24), Pair(29, 26), Pair(16, 36), Pair(19, 49), Pair(23, 21), Pair(-8, 40),
  Pair(0, 19), Pair(15, 18), Pair(13, 23), Pair(4, 37), Pair(8, 26), Pair(9, 21), Pair(19, 15), Pair(1, 27),
  Pair(8, 14), Pair(2, 7), Pair(1, 19), Pair(6, 22), Pair(4, 26), Pair(-6, 21), Pair(0, 10), Pair(-1, 11)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-13, 12), Pair(12, -2), Pair(13, -1), Pair(24, 2), Pair(61, -14), Pair(39, -7), Pair(28, -16), Pair(-18, -27),
  Pair(-20, -6), Pair(22, 4), Pair(8, 1), Pair(22, 7), Pair(13, 2), Pair(24, -4), Pair(14, 13), Pair(22, -26),
  Pair(-25, 28), Pair(11, 4), Pair(5, 18), Pair(18, 13), Pair(23, 21), Pair(3, 9), Pair(17, -1), Pair(-50, 12)
};

constexpr ScorePair kRookBehindPassedPawnBonus = Pair(12, 10);
constexpr ScorePair kBishopPairBonus = Pair(21, 64);

constexpr ScorePair kTempoBonus = Pair(20, 26);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H