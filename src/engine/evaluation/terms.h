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
  Pair(86, 180), Pair(295, 312), Pair(340, 348), Pair(413, 706), Pair(860, 1270), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(53, 139), Pair(34, 143), Pair(25, 145), Pair(64, 100), Pair(51, 104), Pair(50, 113), Pair(-19, 158), Pair(-16, 153),
      Pair(-3, -24), Pair(-16, -4), Pair(16, -48), Pair(21, -78), Pair(33, -80), Pair(62, -67), Pair(16, -19), Pair(-3, -30),
      Pair(-25, -40), Pair(-25, -32), Pair(-12, -58), Pair(-8, -76), Pair(13, -78), Pair(7, -72), Pair(-14, -41), Pair(-15, -58),
      Pair(-31, -57), Pair(-34, -40), Pair(-19, -66), Pair(-2, -74), Pair(-1, -76), Pair(0, -74), Pair(-19, -52), Pair(-16, -72),
      Pair(-31, -61), Pair(-28, -45), Pair(-17, -66), Pair(-11, -67), Pair(0, -67), Pair(-6, -70), Pair(-5, -57), Pair(-12, -76),
      Pair(-31, -55), Pair(-29, -39), Pair(-21, -58), Pair(-23, -62), Pair(-12, -53), Pair(3, -65), Pair(0, -54), Pair(-24, -73),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-127, -35), Pair(-101, 13), Pair(-60, 30), Pair(-32, 15), Pair(-7, 19), Pair(-62, -3), Pair(-93, 12), Pair(-93, -53),
      Pair(-14, 20), Pair(1, 33), Pair(7, 31), Pair(16, 29), Pair(17, 16), Pair(43, 13), Pair(8, 25), Pair(9, 1),
      Pair(6, 23), Pair(23, 30), Pair(26, 49), Pair(26, 46), Pair(34, 40), Pair(63, 18), Pair(20, 24), Pair(26, 8),
      Pair(18, 34), Pair(16, 40), Pair(32, 49), Pair(57, 45), Pair(25, 50), Pair(49, 49), Pair(7, 46), Pair(43, 22),
      Pair(7, 36), Pair(19, 36), Pair(28, 52), Pair(34, 48), Pair(38, 54), Pair(44, 39), Pair(39, 34), Pair(23, 30),
      Pair(-13, 24), Pair(8, 32), Pair(14, 37), Pair(25, 51), Pair(41, 48), Pair(23, 32), Pair(28, 26), Pair(10, 28),
      Pair(-17, 24), Pair(-5, 31), Pair(7, 32), Pair(22, 31), Pair(23, 30), Pair(23, 28), Pair(16, 21), Pair(13, 33),
      Pair(-48, 27), Pair(-12, 18), Pair(-11, 28), Pair(3, 33), Pair(11, 32), Pair(15, 21), Pair(-7, 25), Pair(-12, 20)
  },
  {
      Pair(-49, 32), Pair(-76, 34), Pair(-75, 28), Pair(-121, 37), Pair(-114, 37), Pair(-110, 25), Pair(-66, 26), Pair(-80, 21),
      Pair(-34, 14), Pair(-28, 27), Pair(-28, 25), Pair(-42, 29), Pair(-45, 23), Pair(-33, 24), Pair(-57, 33), Pair(-47, 17),
      Pair(-22, 31), Pair(-9, 27), Pair(-16, 34), Pair(-13, 23), Pair(-21, 28), Pair(14, 34), Pair(1, 32), Pair(-6, 29),
      Pair(-32, 29), Pair(-15, 31), Pair(-11, 32), Pair(2, 42), Pair(-1, 37), Pair(-4, 37), Pair(-19, 26), Pair(-32, 29),
      Pair(-22, 22), Pair(-32, 32), Pair(-17, 35), Pair(3, 35), Pair(1, 30), Pair(-18, 32), Pair(-22, 32), Pair(-6, 11),
      Pair(-25, 22), Pair(-6, 34), Pair(-7, 35), Pair(-9, 38), Pair(-6, 43), Pair(-3, 35), Pair(-3, 27), Pair(-4, 16),
      Pair(-12, 28), Pair(-8, 14), Pair(0, 17), Pair(-17, 27), Pair(-6, 27), Pair(5, 20), Pair(13, 20), Pair(0, 10),
      Pair(-22, 15), Pair(0, 31), Pair(-23, 21), Pair(-25, 26), Pair(-16, 23), Pair(-22, 32), Pair(-8, 16), Pair(6, -6)
  },
  {
      Pair(-3, 3), Pair(-9, 14), Pair(-8, 16), Pair(-11, 12), Pair(-6, 2), Pair(15, 9), Pair(7, 9), Pair(-5, 5),
      Pair(-5, 6), Pair(-5, 22), Pair(11, 20), Pair(23, 10), Pair(7, 8), Pair(32, 7), Pair(24, 2), Pair(11, -4),
      Pair(-14, 3), Pair(14, 7), Pair(10, 5), Pair(8, 2), Pair(34, -11), Pair(47, -10), Pair(68, -14), Pair(16, -18),
      Pair(-17, 3), Pair(-3, 6), Pair(1, 7), Pair(3, 4), Pair(9, -12), Pair(10, -6), Pair(10, -6), Pair(-6, -13),
      Pair(-23, -8), Pair(-22, 2), Pair(-11, -4), Pair(-7, -4), Pair(-4, -12), Pair(-22, 0), Pair(1, -13), Pair(-17, -20),
      Pair(-25, -16), Pair(-19, -10), Pair(-12, -15), Pair(-13, -12), Pair(-2, -22), Pair(-5, -19), Pair(20, -36), Pair(-3, -40),
      Pair(-25, -23), Pair(-17, -14), Pair(-3, -17), Pair(-3, -18), Pair(3, -28), Pair(6, -25), Pair(13, -35), Pair(-20, -39),
      Pair(-12, -19), Pair(-6, -18), Pair(0, -14), Pair(5, -20), Pair(11, -29), Pair(6, -21), Pair(0, -26), Pair(-9, -37)
  },
  {
      Pair(-41, -7), Pair(-45, 4), Pair(-30, 22), Pair(-8, 7), Pair(-19, 12), Pair(-12, 16), Pair(34, -38), Pair(-15, -10),
      Pair(-1, -17), Pair(-19, 14), Pair(-23, 45), Pair(-33, 61), Pair(-51, 81), Pair(-7, 32), Pair(-5, 25), Pair(43, 0),
      Pair(-1, -5), Pair(-4, 9), Pair(-5, 41), Pair(-5, 44), Pair(-10, 55), Pair(20, 32), Pair(25, 5), Pair(13, -1),
      Pair(-11, 5), Pair(-6, 22), Pair(-5, 29), Pair(-10, 48), Pair(-6, 47), Pair(2, 29), Pair(9, 26), Pair(7, 6),
      Pair(-7, -3), Pair(-12, 24), Pair(-6, 21), Pair(-2, 36), Pair(4, 33), Pair(-5, 24), Pair(10, 10), Pair(7, 0),
      Pair(-5, -19), Pair(-1, 0), Pair(0, 10), Pair(-4, 15), Pair(1, 20), Pair(4, 13), Pair(17, -7), Pair(12, -21),
      Pair(1, -32), Pair(2, -26), Pair(7, -20), Pair(13, -16), Pair(11, -9), Pair(22, -37), Pair(26, -56), Pair(29, -79),
      Pair(-8, -30), Pair(-1, -29), Pair(2, -20), Pair(4, -9), Pair(10, -26), Pair(0, -35), Pair(5, -50), Pair(7, -55)
  },
  {
      Pair(67, -90), Pair(75, -43), Pair(49, -24), Pair(-77, 15), Pair(-48, -2), Pair(-54, 5), Pair(22, -13), Pair(145, -118),
      Pair(-63, 0), Pair(11, 23), Pair(-31, 32), Pair(50, 17), Pair(-10, 27), Pair(-14, 44), Pair(18, 31), Pair(-54, 9),
      Pair(-66, 2), Pair(79, 10), Pair(-14, 32), Pair(-45, 44), Pair(-18, 44), Pair(62, 26), Pair(9, 28), Pair(-32, -1),
      Pair(-35, -18), Pair(11, 1), Pair(-49, 27), Pair(-106, 44), Pair(-109, 39), Pair(-65, 28), Pair(-46, 9), Pair(-115, -1),
      Pair(-41, -31), Pair(-2, -10), Pair(-63, 20), Pair(-105, 39), Pair(-105, 34), Pair(-58, 13), Pair(-50, -4), Pair(-118, -11),
      Pair(-19, -33), Pair(25, -16), Pair(-36, 9), Pair(-52, 24), Pair(-48, 20), Pair(-42, 7), Pair(-9, -15), Pair(-41, -25),
      Pair(37, -42), Pair(8, -13), Pair(0, -1), Pair(-22, 10), Pair(-28, 10), Pair(-15, -1), Pair(8, -20), Pair(23, -42),
      Pair(26, -68), Pair(42, -41), Pair(28, -25), Pair(-32, -5), Pair(12, -28), Pair(-21, -13), Pair(25, -38), Pair(37, -77)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-36, -2), Pair(-22, 5), Pair(-12, 26), Pair(-6, 35), Pair(0, 42), Pair(6, 49), Pair(13, 48), Pair(18, 47),
  Pair(22, 38)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-33, -26), Pair(-24, -22), Pair(-13, -6), Pair(-7, 8), Pair(1, 16), Pair(4, 27), Pair(6, 30), Pair(6, 33),
  Pair(7, 37), Pair(10, 35), Pair(17, 31), Pair(21, 32), Pair(15, 45), Pair(23, 23)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-22, -54), Pair(-15, -26), Pair(-11, -22), Pair(-9, -17), Pair(-11, -9), Pair(-7, -5), Pair(-6, 2), Pair(-4, 4),
  Pair(-1, 7), Pair(0, 11), Pair(4, 12), Pair(2, 18), Pair(4, 19), Pair(5, 15), Pair(-2, 13)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-1, -243), Pair(0, -212), Pair(-11, -88), Pair(-9, -48), Pair(-7, -25), Pair(-4, -14), Pair(-2, 4), Pair(-1, 16),
  Pair(2, 23), Pair(5, 25), Pair(6, 31), Pair(8, 37), Pair(10, 37), Pair(10, 42), Pair(12, 43), Pair(14, 45),
  Pair(13, 52), Pair(14, 51), Pair(23, 45), Pair(35, 35), Pair(37, 35), Pair(84, 4), Pair(69, 12), Pair(85, -10),
  Pair(185, -49), Pair(204, -85), Pair(128, -33), Pair(83, -29)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-2, -2), Pair(-6, 14), Pair(-4, 49), Pair(20, 85), Pair(18, 153), Pair(17, 43), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-2, 0), Pair(17, 10), Pair(43, 47), Pair(114, 176), Pair(-155, 440), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -47), Pair(6, -38), Pair(-5, -27), Pair(-8, -14), Pair(-16, -6), Pair(-15, -21), Pair(4, -33), Pair(-5, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-13, 8), Pair(-7, -16), Pair(-17, -11), Pair(-15, -20), Pair(-18, -21), Pair(-10, -11), Pair(-6, -16), Pair(-12, 4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(29, 10), Pair(26, 3), Pair(23, 11), Pair(25, 10), Pair(28, 15), Pair(38, 2), Pair(48, 2), Pair(74, 2)
  },
  {
      Pair(2, 47), Pair(8, 19), Pair(7, 18), Pair(17, 7), Pair(12, 11), Pair(15, 4), Pair(24, 8), Pair(11, 33)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -5), Pair(20, -1), Pair(12, -2),
  Pair(25, -11), Pair(21, -7), Pair(24, -11),
  Pair(34, -2), Pair(0, 0), Pair(31, -1),
  Pair(-11, 4), Pair(-14, 4), Pair(-10, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-14, 4), Pair(-8, 4),
  Pair(-6, 2), Pair(-15, 6), Pair(-8, 4),
  Pair(-1, -6), Pair(-12, 0), Pair(-1, -5),
  Pair(14, -9), Pair(-5, -4), Pair(11, -6),
  Pair(32, -9), Pair(23, -1), Pair(25, -9),
  Pair(0, 0), Pair(0, -32), Pair(0, 0),
  Pair(49, -50), Pair(0, 0), Pair(44, -48)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-19, 16), Pair(-25, 1), Pair(-17, -20), Pair(-14, -30), Pair(-9, -33), Pair(7, -35), Pair(-4, -37)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-67, -27), Pair(5, -27), Pair(4, -2), Pair(9, 7), Pair(8, 15), Pair(6, 20), Pair(-11, 19)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-88, -6), Pair(-95, 0), Pair(-55, -5), Pair(-49, -3), Pair(-37, 1), Pair(-63, 6), Pair(-64, 8), Pair(-51, 10)
  },
  {
      Pair(-25, 55), Pair(-41, 24), Pair(-20, 16), Pair(-2, -2), Pair(-6, -4), Pair(-13, 8), Pair(-31, 26), Pair(-30, 40)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 4), Pair(35, -7), Pair(84, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 4), Pair(31, -5), Pair(55, -15), Pair(69, -46), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -15), Pair(35, -18), Pair(57, -18), Pair(88, -24), Pair(102, -38), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 9), Pair(16, 22), Pair(39, 30), Pair(86, 17), Pair(126, 20), Pair(212, -25), Pair(262, -59)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(0, 0), Pair(-57, -21), Pair(-63, -43), Pair(-83, -5), Pair(-75, 40), Pair(0, 0)
};

constexpr ScorePair kRookThreatenedByKnightPenalty = Pair(-64, -24);
constexpr ScorePair kRookThreatenedByBishopPenalty = Pair(-47, -25);
constexpr ScorePair kQueenThreatenedByKnightPenalty = Pair(-50, 12);
constexpr ScorePair kQueenThreatenedByBishopPenalty = Pair(-61, -56);
constexpr ScorePair kQueenThreatenedByRookPenalty = Pair(-62, -35);

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(8, 25), Pair(12, 13), Pair(29, 20), Pair(39, 24), Pair(39, 30), Pair(26, 48), Pair(34, 19), Pair(-9, 39),
  Pair(-1, 18), Pair(12, 18), Pair(11, 23), Pair(2, 38), Pair(6, 26), Pair(5, 22), Pair(14, 15), Pair(-4, 28),
  Pair(7, 14), Pair(-2, 7), Pair(-4, 19), Pair(3, 21), Pair(0, 26), Pair(-11, 21), Pair(-4, 9), Pair(-2, 10)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-13, 12), Pair(14, -2), Pair(22, -2), Pair(34, 0), Pair(57, -14), Pair(35, -6), Pair(21, -15), Pair(-22, -25),
  Pair(-17, -7), Pair(18, 5), Pair(7, 1), Pair(18, 8), Pair(10, 2), Pair(17, -4), Pair(12, 13), Pair(18, -25),
  Pair(-26, 28), Pair(7, 5), Pair(2, 17), Pair(15, 13), Pair(21, 21), Pair(0, 8), Pair(13, -3), Pair(-51, 10)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 63);

constexpr ScorePair kTempoBonus = Pair(27, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H