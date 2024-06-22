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
  Pair(85, 175), Pair(296, 319), Pair(334, 346), Pair(408, 704), Pair(862, 1269), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(46, 141), Pair(46, 140), Pair(27, 144), Pair(61, 101), Pair(56, 103), Pair(45, 116), Pair(-4, 156), Pair(-24, 155),
      Pair(-2, -19), Pair(-14, 1), Pair(23, -44), Pair(25, -73), Pair(38, -76), Pair(68, -63), Pair(21, -14), Pair(-3, -25),
      Pair(-23, -35), Pair(-23, -28), Pair(-9, -54), Pair(-4, -71), Pair(19, -74), Pair(9, -67), Pair(-9, -37), Pair(-14, -53),
      Pair(-30, -52), Pair(-33, -34), Pair(-17, -61), Pair(0, -68), Pair(1, -71), Pair(1, -69), Pair(-17, -46), Pair(-17, -67),
      Pair(-30, -56), Pair(-28, -39), Pair(-15, -61), Pair(-10, -61), Pair(1, -62), Pair(-5, -65), Pair(-3, -52), Pair(-11, -71),
      Pair(-30, -50), Pair(-29, -33), Pair(-20, -53), Pair(-22, -57), Pair(-11, -48), Pair(3, -60), Pair(2, -49), Pair(-24, -69),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-131, -38), Pair(-107, 11), Pair(-57, 26), Pair(-26, 12), Pair(-7, 16), Pair(-60, -6), Pair(-94, 9), Pair(-97, -55),
      Pair(-8, 16), Pair(12, 26), Pair(37, 21), Pair(41, 20), Pair(17, 14), Pair(78, 3), Pair(10, 22), Pair(20, -5),
      Pair(9, 19), Pair(40, 23), Pair(42, 42), Pair(34, 42), Pair(67, 28), Pair(69, 14), Pair(34, 17), Pair(18, 8),
      Pair(14, 31), Pair(10, 38), Pair(28, 47), Pair(52, 43), Pair(20, 48), Pair(43, 48), Pair(0, 44), Pair(35, 20),
      Pair(1, 33), Pair(11, 34), Pair(21, 50), Pair(26, 47), Pair(30, 52), Pair(36, 36), Pair(31, 32), Pair(16, 28),
      Pair(-18, 21), Pair(3, 30), Pair(10, 35), Pair(20, 50), Pair(36, 46), Pair(18, 30), Pair(23, 24), Pair(5, 26),
      Pair(-22, 21), Pair(-9, 28), Pair(2, 30), Pair(18, 29), Pair(19, 28), Pair(19, 26), Pair(11, 19), Pair(8, 31),
      Pair(-53, 24), Pair(-15, 15), Pair(-16, 26), Pair(-2, 30), Pair(6, 30), Pair(10, 19), Pair(-11, 22), Pair(-18, 17)
  },
  {
      Pair(-47, 31), Pair(-72, 33), Pair(-70, 27), Pair(-113, 36), Pair(-109, 36), Pair(-105, 24), Pair(-61, 25), Pair(-79, 20),
      Pair(-29, 12), Pair(-5, 21), Pair(-19, 23), Pair(-31, 27), Pair(-20, 18), Pair(-27, 23), Pair(-33, 29), Pair(-45, 17),
      Pair(-20, 30), Pair(-4, 25), Pair(-5, 32), Pair(-2, 19), Pair(-24, 29), Pair(9, 35), Pair(-4, 32), Pair(-11, 30),
      Pair(-27, 26), Pair(-17, 31), Pair(-7, 31), Pair(0, 42), Pair(-2, 35), Pair(-10, 37), Pair(-20, 25), Pair(-33, 29),
      Pair(-22, 22), Pair(-31, 31), Pair(-19, 35), Pair(0, 34), Pair(-2, 30), Pair(-19, 31), Pair(-23, 31), Pair(-7, 11),
      Pair(-23, 21), Pair(-6, 34), Pair(-8, 34), Pair(-10, 38), Pair(-6, 42), Pair(-4, 35), Pair(-2, 26), Pair(-2, 16),
      Pair(-10, 28), Pair(-7, 14), Pair(1, 17), Pair(-16, 27), Pair(-5, 27), Pair(6, 20), Pair(14, 20), Pair(1, 9),
      Pair(-22, 16), Pair(0, 31), Pair(-21, 21), Pair(-24, 26), Pair(-16, 23), Pair(-21, 31), Pair(-7, 16), Pair(5, -5)
  },
  {
      Pair(-2, 4), Pair(-9, 15), Pair(-8, 16), Pair(-13, 10), Pair(-5, 2), Pair(15, 10), Pair(9, 10), Pair(-5, 6),
      Pair(-5, 7), Pair(-6, 24), Pair(11, 19), Pair(24, 8), Pair(7, 7), Pair(33, 8), Pair(23, 4), Pair(12, -3),
      Pair(-15, 4), Pair(12, 9), Pair(10, 4), Pair(7, 0), Pair(33, -12), Pair(43, -8), Pair(62, -12), Pair(13, -16),
      Pair(-18, 4), Pair(-3, 7), Pair(0, 7), Pair(4, 0), Pair(7, -13), Pair(7, -4), Pair(6, -4), Pair(-10, -12),
      Pair(-24, -8), Pair(-25, 4), Pair(-13, -4), Pair(-7, -8), Pair(-6, -12), Pair(-23, 1), Pair(-2, -12), Pair(-18, -20),
      Pair(-26, -15), Pair(-19, -10), Pair(-13, -15), Pair(-14, -14), Pair(-2, -23), Pair(-6, -18), Pair(18, -35), Pair(-2, -40),
      Pair(-25, -23), Pair(-17, -14), Pair(-4, -18), Pair(-3, -21), Pair(3, -29), Pair(6, -25), Pair(12, -35), Pair(-19, -39),
      Pair(-10, -19), Pair(-5, -17), Pair(1, -15), Pair(6, -23), Pair(12, -30), Pair(7, -20), Pair(0, -26), Pair(-6, -36)
  },
  {
      Pair(-50, -5), Pair(-56, 7), Pair(-42, 26), Pair(-17, 9), Pair(-28, 14), Pair(-19, 16), Pair(27, -37), Pair(-30, -4),
      Pair(-7, -18), Pair(-25, 14), Pair(-29, 45), Pair(-39, 61), Pair(-60, 83), Pair(-12, 31), Pair(-12, 24), Pair(38, -1),
      Pair(-5, -5), Pair(-9, 9), Pair(-10, 40), Pair(-9, 42), Pair(-13, 53), Pair(15, 30), Pair(19, 6), Pair(9, -3),
      Pair(-14, 4), Pair(-10, 21), Pair(-9, 28), Pair(-15, 48), Pair(-12, 46), Pair(-2, 27), Pair(4, 25), Pair(1, 7),
      Pair(-9, -4), Pair(-15, 23), Pair(-10, 20), Pair(-5, 34), Pair(-1, 33), Pair(-8, 21), Pair(7, 10), Pair(5, -2),
      Pair(-6, -22), Pair(-1, -3), Pair(-2, 8), Pair(-5, 13), Pair(1, 17), Pair(4, 10), Pair(17, -10), Pair(11, -23),
      Pair(0, -34), Pair(2, -29), Pair(7, -24), Pair(13, -18), Pair(11, -12), Pair(21, -41), Pair(25, -59), Pair(28, -81),
      Pair(-7, -33), Pair(-2, -31), Pair(2, -22), Pair(5, -13), Pair(9, -28), Pair(-1, -37), Pair(5, -52), Pair(6, -58)
  },
  {
      Pair(71, -87), Pair(80, -40), Pair(50, -21), Pair(-76, 19), Pair(-47, 1), Pair(-47, 7), Pair(28, -11), Pair(151, -116),
      Pair(-62, 4), Pair(11, 27), Pair(-34, 36), Pair(49, 21), Pair(-11, 31), Pair(-14, 48), Pair(15, 35), Pair(-56, 12),
      Pair(-67, 5), Pair(79, 14), Pair(-14, 36), Pair(-46, 49), Pair(-20, 47), Pair(60, 30), Pair(7, 32), Pair(-35, 3),
      Pair(-37, -14), Pair(11, 5), Pair(-51, 31), Pair(-109, 48), Pair(-110, 43), Pair(-67, 32), Pair(-47, 13), Pair(-117, 3),
      Pair(-42, -27), Pair(-3, -6), Pair(-64, 24), Pair(-107, 43), Pair(-106, 38), Pair(-59, 17), Pair(-50, 0), Pair(-120, -7),
      Pair(-19, -29), Pair(25, -12), Pair(-35, 13), Pair(-53, 29), Pair(-48, 24), Pair(-43, 11), Pair(-8, -11), Pair(-42, -21),
      Pair(37, -39), Pair(9, -9), Pair(1, 3), Pair(-22, 13), Pair(-27, 13), Pair(-14, 2), Pair(9, -16), Pair(22, -38),
      Pair(26, -63), Pair(42, -37), Pair(28, -22), Pair(-34, 0), Pair(12, -25), Pair(-22, -9), Pair(26, -34), Pair(36, -73)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-32, -8), Pair(-18, 1), Pair(-9, 21), Pair(-4, 30), Pair(2, 37), Pair(8, 45), Pair(14, 44), Pair(20, 42),
  Pair(24, 33)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-28, -23), Pair(-18, -19), Pair(-8, -2), Pair(-2, 11), Pair(5, 20), Pair(8, 30), Pair(11, 34), Pair(13, 36),
  Pair(14, 40), Pair(17, 38), Pair(26, 33), Pair(31, 34), Pair(28, 48), Pair(31, 27)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-19, -54), Pair(-12, -25), Pair(-9, -21), Pair(-6, -16), Pair(-8, -8), Pair(-4, -4), Pair(-3, 2), Pair(-1, 4),
  Pair(2, 7), Pair(3, 11), Pair(6, 12), Pair(5, 17), Pair(6, 19), Pair(7, 14), Pair(1, 13)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(0, -251), Pair(1, -236), Pair(-10, -96), Pair(-8, -49), Pair(-7, -25), Pair(-4, -14), Pair(-2, 4), Pair(-1, 16),
  Pair(2, 23), Pair(4, 25), Pair(5, 31), Pair(7, 36), Pair(8, 36), Pair(7, 42), Pair(9, 43), Pair(11, 45),
  Pair(10, 53), Pair(11, 51), Pair(19, 46), Pair(31, 36), Pair(33, 35), Pair(80, 5), Pair(65, 13), Pair(82, -9),
  Pair(184, -51), Pair(200, -85), Pair(114, -27), Pair(73, -25)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-8, -7), Pair(-11, 8), Pair(-8, 44), Pair(15, 79), Pair(12, 147), Pair(21, 39), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-2, 0), Pair(18, 10), Pair(43, 48), Pair(122, 175), Pair(-125, 437), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-6, -47), Pair(8, -39), Pair(-5, -27), Pair(-5, -15), Pair(-13, -8), Pair(-15, -21), Pair(3, -34), Pair(-3, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-15, 8), Pair(-7, -16), Pair(-17, -11), Pair(-15, -20), Pair(-19, -21), Pair(-10, -11), Pair(-6, -16), Pair(-11, 4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(29, 11), Pair(28, 5), Pair(24, 13), Pair(27, 14), Pair(29, 18), Pair(39, 3), Pair(51, 3), Pair(76, 4)
  },
  {
      Pair(3, 49), Pair(8, 21), Pair(7, 22), Pair(16, 13), Pair(11, 14), Pair(15, 6), Pair(25, 9), Pair(12, 35)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(18, -1), Pair(12, -2),
  Pair(24, -10), Pair(20, -7), Pair(24, -12),
  Pair(33, -1), Pair(0, 0), Pair(30, -1),
  Pair(-12, 4), Pair(-15, 3), Pair(-11, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-13, 4), Pair(-8, 4),
  Pair(-5, 2), Pair(-15, 6), Pair(-8, 4),
  Pair(-1, -6), Pair(-12, 0), Pair(-1, -5),
  Pair(14, -9), Pair(-5, -4), Pair(12, -6),
  Pair(33, -9), Pair(23, -1), Pair(26, -9),
  Pair(0, 0), Pair(1, -32), Pair(0, 0),
  Pair(49, -50), Pair(0, 0), Pair(43, -48)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-16, 16), Pair(-23, 1), Pair(-17, -19), Pair(-13, -31), Pair(-8, -33), Pair(7, -35), Pair(-3, -38)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-68, -21), Pair(8, -21), Pair(7, 3), Pair(13, 12), Pair(11, 20), Pair(9, 26), Pair(-7, 24)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-89, -6), Pair(-97, 0), Pair(-56, -5), Pair(-49, -4), Pair(-38, 1), Pair(-64, 6), Pair(-65, 7), Pair(-51, 9)
  },
  {
      Pair(-23, 54), Pair(-41, 24), Pair(-21, 15), Pair(-3, -2), Pair(-6, -5), Pair(-14, 8), Pair(-32, 26), Pair(-30, 39)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 3), Pair(34, -7), Pair(80, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 4), Pair(34, -5), Pair(55, -15), Pair(61, -45), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -15), Pair(35, -18), Pair(57, -17), Pair(88, -23), Pair(103, -37), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 9), Pair(16, 24), Pair(40, 31), Pair(86, 19), Pair(126, 22), Pair(213, -23), Pair(215, -23)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(4, 24), Pair(-4, 15), Pair(12, 24), Pair(29, 26), Pair(16, 35), Pair(19, 49), Pair(23, 21), Pair(-8, 39),
  Pair(0, 19), Pair(15, 17), Pair(12, 23), Pair(5, 37), Pair(9, 26), Pair(9, 22), Pair(19, 15), Pair(1, 27),
  Pair(8, 15), Pair(2, 7), Pair(1, 19), Pair(6, 21), Pair(4, 26), Pair(-6, 21), Pair(0, 10), Pair(-1, 11)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-13, 12), Pair(12, -2), Pair(13, 0), Pair(24, 2), Pair(60, -15), Pair(39, -7), Pair(28, -16), Pair(-18, -27),
  Pair(-20, -6), Pair(22, 4), Pair(7, 1), Pair(22, 7), Pair(13, 2), Pair(23, -4), Pair(14, 13), Pair(22, -25),
  Pair(-25, 28), Pair(11, 4), Pair(4, 18), Pair(18, 13), Pair(24, 21), Pair(3, 9), Pair(17, -1), Pair(-50, 12)
};

constexpr ScorePair kRookBehindPassedPawnBonus = Pair(9, 13);
constexpr ScorePair kBishopPairBonus = Pair(22, 64);

constexpr ScorePair kTempoBonus = Pair(20, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H