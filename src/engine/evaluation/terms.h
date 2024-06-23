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
  Pair(87, 181), Pair(296, 312), Pair(344, 352), Pair(411, 705), Pair(866, 1268), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(53, 139), Pair(35, 144), Pair(25, 145), Pair(68, 100), Pair(52, 104), Pair(51, 114), Pair(-20, 158), Pair(-16, 153),
      Pair(-3, -25), Pair(-17, -4), Pair(17, -47), Pair(21, -78), Pair(33, -80), Pair(62, -67), Pair(16, -19), Pair(-4, -31),
      Pair(-25, -41), Pair(-25, -33), Pair(-13, -59), Pair(-9, -76), Pair(11, -78), Pair(7, -72), Pair(-13, -42), Pair(-15, -59),
      Pair(-31, -58), Pair(-34, -41), Pair(-19, -67), Pair(-3, -74), Pair(-3, -76), Pair(-1, -75), Pair(-20, -52), Pair(-16, -73),
      Pair(-32, -62), Pair(-28, -47), Pair(-17, -68), Pair(-12, -69), Pair(-2, -69), Pair(-7, -71), Pair(-6, -59), Pair(-13, -77),
      Pair(-32, -56), Pair(-30, -40), Pair(-23, -59), Pair(-24, -65), Pair(-14, -55), Pair(1, -65), Pair(-2, -54), Pair(-25, -75),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-127, -32), Pair(-96, 11), Pair(-51, 27), Pair(-18, 11), Pair(-4, 16), Pair(-47, -7), Pair(-87, 9), Pair(-91, -52),
      Pair(-14, 19), Pair(0, 33), Pair(11, 31), Pair(18, 30), Pair(10, 20), Pair(48, 12), Pair(8, 24), Pair(11, -1),
      Pair(6, 22), Pair(18, 32), Pair(25, 49), Pair(22, 45), Pair(34, 38), Pair(66, 17), Pair(14, 26), Pair(28, 6),
      Pair(17, 33), Pair(19, 38), Pair(32, 49), Pair(56, 48), Pair(29, 48), Pair(48, 47), Pair(14, 37), Pair(42, 20),
      Pair(6, 36), Pair(20, 36), Pair(29, 53), Pair(35, 52), Pair(37, 57), Pair(45, 38), Pair(39, 33), Pair(21, 30),
      Pair(-15, 24), Pair(6, 32), Pair(13, 39), Pair(24, 54), Pair(38, 50), Pair(21, 33), Pair(26, 26), Pair(9, 28),
      Pair(-19, 25), Pair(-7, 33), Pair(4, 35), Pair(19, 35), Pair(21, 33), Pair(19, 32), Pair(15, 22), Pair(11, 34),
      Pair(-50, 27), Pair(-15, 20), Pair(-15, 31), Pair(-1, 36), Pair(7, 35), Pair(12, 24), Pair(-11, 26), Pair(-14, 19)
  },
  {
      Pair(-46, 33), Pair(-67, 33), Pair(-67, 26), Pair(-102, 33), Pair(-102, 33), Pair(-97, 23), Pair(-55, 25), Pair(-78, 22),
      Pair(-32, 15), Pair(-28, 27), Pair(-26, 24), Pair(-36, 27), Pair(-39, 23), Pair(-28, 22), Pair(-54, 32), Pair(-44, 18),
      Pair(-19, 31), Pair(-10, 26), Pair(-18, 33), Pair(-15, 24), Pair(-23, 29), Pair(14, 32), Pair(3, 30), Pair(-6, 31),
      Pair(-32, 30), Pair(-20, 33), Pair(-14, 32), Pair(-2, 38), Pair(-5, 32), Pair(-6, 36), Pair(-24, 30), Pair(-30, 28),
      Pair(-25, 24), Pair(-33, 34), Pair(-19, 34), Pair(0, 32), Pair(1, 27), Pair(-19, 33), Pair(-22, 32), Pair(-10, 14),
      Pair(-29, 25), Pair(-10, 33), Pair(-10, 34), Pair(-11, 40), Pair(-9, 43), Pair(-6, 34), Pair(-6, 27), Pair(-8, 17),
      Pair(-14, 28), Pair(-11, 14), Pair(-2, 19), Pair(-17, 31), Pair(-7, 30), Pair(3, 22), Pair(11, 21), Pair(-3, 9),
      Pair(-25, 15), Pair(-4, 34), Pair(-26, 25), Pair(-27, 30), Pair(-20, 27), Pair(-25, 35), Pair(-12, 18), Pair(3, -6)
  },
  {
      Pair(-13, 4), Pair(-14, 14), Pair(-11, 17), Pair(-16, 16), Pair(-9, 5), Pair(15, 7), Pair(5, 8), Pair(-12, 4),
      Pair(-11, -3), Pair(-11, 11), Pair(1, 8), Pair(16, -1), Pair(1, -4), Pair(20, -1), Pair(19, -5), Pair(6, -9),
      Pair(-16, -2), Pair(10, 1), Pair(7, 0), Pair(5, -3), Pair(31, -16), Pair(46, -19), Pair(62, -20), Pair(15, -23),
      Pair(-18, 0), Pair(-4, 2), Pair(-2, 4), Pair(0, 1), Pair(7, -15), Pair(10, -14), Pair(11, -13), Pair(-6, -17),
      Pair(-23, -8), Pair(-22, 2), Pair(-12, -3), Pair(-6, -2), Pair(-3, -10), Pair(-20, -2), Pair(1, -15), Pair(-16, -21),
      Pair(-24, -14), Pair(-18, -8), Pair(-11, -11), Pair(-11, -7), Pair(-1, -18), Pair(-3, -18), Pair(20, -35), Pair(-1, -39),
      Pair(-23, -20), Pair(-15, -11), Pair(-1, -12), Pair(-1, -12), Pair(5, -23), Pair(7, -22), Pair(14, -32), Pair(-18, -35),
      Pair(-10, -15), Pair(-4, -14), Pair(2, -9), Pair(6, -15), Pair(13, -24), Pair(7, -19), Pair(1, -22), Pair(-7, -33)
  },
  {
      Pair(-39, -9), Pair(-44, 3), Pair(-28, 20), Pair(-7, 5), Pair(-17, 10), Pair(-11, 14), Pair(38, -41), Pair(-14, -10),
      Pair(-2, -17), Pair(-19, 14), Pair(-22, 45), Pair(-32, 60), Pair(-51, 81), Pair(-6, 31), Pair(-5, 25), Pair(42, 0),
      Pair(-2, -6), Pair(-4, 9), Pair(-5, 40), Pair(-4, 43), Pair(-10, 55), Pair(21, 31), Pair(25, 6), Pair(13, -2),
      Pair(-11, 4), Pair(-6, 22), Pair(-5, 28), Pair(-9, 48), Pair(-6, 47), Pair(2, 29), Pair(9, 25), Pair(6, 5),
      Pair(-7, -4), Pair(-12, 24), Pair(-6, 21), Pair(-1, 37), Pair(4, 33), Pair(-5, 24), Pair(10, 9), Pair(7, 0),
      Pair(-5, -20), Pair(-2, 0), Pair(0, 10), Pair(-5, 16), Pair(1, 21), Pair(4, 14), Pair(17, -7), Pair(11, -21),
      Pair(0, -32), Pair(2, -27), Pair(7, -21), Pair(12, -15), Pair(11, -9), Pair(21, -37), Pair(25, -56), Pair(29, -80),
      Pair(-9, -30), Pair(-2, -29), Pair(-1, -19), Pair(2, -10), Pair(8, -26), Pair(-3, -35), Pair(4, -50), Pair(5, -54)
  },
  {
      Pair(67, -91), Pair(78, -46), Pair(50, -26), Pair(-74, 13), Pair(-48, -3), Pair(-56, 4), Pair(21, -14), Pair(143, -119),
      Pair(-63, -1), Pair(13, 23), Pair(-29, 31), Pair(54, 16), Pair(-9, 27), Pair(-12, 43), Pair(17, 31), Pair(-54, 8),
      Pair(-67, 1), Pair(82, 9), Pair(-9, 31), Pair(-41, 43), Pair(-17, 43), Pair(65, 25), Pair(9, 28), Pair(-33, -1),
      Pair(-33, -18), Pair(11, 0), Pair(-47, 26), Pair(-103, 43), Pair(-106, 38), Pair(-63, 27), Pair(-42, 8), Pair(-115, -1),
      Pair(-40, -32), Pair(-1, -10), Pair(-61, 19), Pair(-102, 38), Pair(-102, 33), Pair(-57, 12), Pair(-49, -4), Pair(-117, -12),
      Pair(-17, -34), Pair(27, -16), Pair(-33, 8), Pair(-50, 23), Pair(-46, 19), Pair(-41, 6), Pair(-8, -15), Pair(-39, -26),
      Pair(40, -43), Pair(10, -13), Pair(2, -2), Pair(-20, 9), Pair(-26, 9), Pair(-14, -2), Pair(9, -20), Pair(25, -43),
      Pair(28, -70), Pair(43, -42), Pair(29, -26), Pair(-32, -5), Pair(13, -30), Pair(-20, -14), Pair(26, -39), Pair(39, -79)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-35, 9), Pair(-21, 9), Pair(-10, 29), Pair(-5, 37), Pair(2, 43), Pair(8, 50), Pair(15, 49), Pair(20, 46),
  Pair(24, 37)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-34, -20), Pair(-24, -22), Pair(-15, -6), Pair(-9, 5), Pair(-2, 14), Pair(1, 23), Pair(2, 28), Pair(3, 32),
  Pair(4, 35), Pair(8, 35), Pair(16, 32), Pair(22, 33), Pair(17, 49), Pair(27, 28)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-21, -54), Pair(-14, -26), Pair(-11, -22), Pair(-9, -16), Pair(-12, -9), Pair(-8, -5), Pair(-7, 1), Pair(-6, 3),
  Pair(-5, 6), Pair(-3, 10), Pair(1, 12), Pair(-1, 16), Pair(3, 18), Pair(4, 15), Pair(-2, 16)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(0, -238), Pair(1, -216), Pair(-9, -91), Pair(-8, -48), Pair(-7, -25), Pair(-4, -13), Pair(-2, 5), Pair(0, 17),
  Pair(2, 24), Pair(4, 27), Pair(6, 33), Pair(8, 38), Pair(10, 38), Pair(10, 43), Pair(12, 44), Pair(14, 46),
  Pair(13, 53), Pair(14, 51), Pair(23, 46), Pair(35, 35), Pair(37, 34), Pair(84, 3), Pair(69, 11), Pair(86, -12),
  Pair(184, -51), Pair(204, -88), Pair(133, -39), Pair(87, -34)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(0, 2), Pair(-5, 17), Pair(-3, 53), Pair(21, 88), Pair(19, 156), Pair(21, 48), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-2, 1), Pair(17, 11), Pair(43, 49), Pair(115, 173), Pair(-168, 442), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-10, -47), Pair(6, -37), Pair(-5, -27), Pair(-8, -13), Pair(-16, -5), Pair(-16, -22), Pair(4, -33), Pair(-6, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-12, 9), Pair(-7, -15), Pair(-17, -10), Pair(-15, -18), Pair(-18, -19), Pair(-10, -10), Pair(-5, -16), Pair(-11, 5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(30, 9), Pair(25, 4), Pair(21, 10), Pair(24, 8), Pair(26, 14), Pair(38, 3), Pair(46, 3), Pair(75, 2)
  },
  {
      Pair(3, 29), Pair(8, 5), Pair(8, 4), Pair(18, -7), Pair(13, -2), Pair(16, -6), Pair(26, -3), Pair(13, 17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -6), Pair(19, -2), Pair(12, -2),
  Pair(25, -10), Pair(21, -7), Pair(23, -11),
  Pair(34, -2), Pair(0, 0), Pair(30, -2),
  Pair(-10, 5), Pair(-16, 4), Pair(-8, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, 2), Pair(-14, 4), Pair(-9, 4),
  Pair(-6, 2), Pair(-15, 6), Pair(-9, 4),
  Pair(-1, -6), Pair(-13, 0), Pair(-2, -5),
  Pair(13, -8), Pair(-6, -4), Pair(11, -6),
  Pair(31, -8), Pair(22, -1), Pair(24, -8),
  Pair(0, 0), Pair(0, -31), Pair(0, 0),
  Pair(52, -50), Pair(0, 0), Pair(47, -48)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-19, 16), Pair(-25, 2), Pair(-17, -19), Pair(-15, -30), Pair(-10, -32), Pair(6, -34), Pair(-4, -37)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-68, -31), Pair(4, -30), Pair(3, -5), Pair(8, 4), Pair(6, 11), Pair(4, 17), Pair(-13, 15)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-87, -7), Pair(-94, 0), Pair(-55, -6), Pair(-49, -3), Pair(-37, 1), Pair(-63, 6), Pair(-63, 7), Pair(-50, 9)
  },
  {
      Pair(-25, 54), Pair(-41, 24), Pair(-21, 15), Pair(-3, -2), Pair(-6, -5), Pair(-13, 8), Pair(-31, 25), Pair(-30, 39)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, 1), Pair(35, -8), Pair(84, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -2), Pair(30, -6), Pair(57, -16), Pair(64, -46), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -23), Pair(32, -24), Pair(57, -20), Pair(90, -26), Pair(103, -40), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 9), Pair(15, 22), Pair(39, 29), Pair(86, 17), Pair(126, 19), Pair(211, -25), Pair(273, -67)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-15, 18), Pair(-59, -21), Pair(-63, -53), Pair(-83, -5), Pair(-76, 38), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(8, -15), Pair(12, 0), Pair(-32, -37), Pair(-58, -26), Pair(-48, 2), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(-3, -20), Pair(-18, -28), Pair(7, -27), Pair(-47, -28), Pair(-63, -58), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(-2, -25), Pair(-15, -27), Pair(-19, -31), Pair(1, -30), Pair(-62, -44), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(5, 24), Pair(8, 12), Pair(28, 18), Pair(35, 20), Pair(34, 28), Pair(19, 47), Pair(32, 17), Pair(-11, 36),
  Pair(0, 13), Pair(11, 15), Pair(10, 20), Pair(0, 32), Pair(4, 21), Pair(2, 20), Pair(12, 15), Pair(-5, 25),
  Pair(6, 9), Pair(-3, 3), Pair(-6, 15), Pair(0, 16), Pair(-2, 21), Pair(-14, 18), Pair(-5, 6), Pair(-4, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-17, 10), Pair(11, 1), Pair(18, 2), Pair(33, 1), Pair(56, -13), Pair(31, -3), Pair(18, -11), Pair(-23, -31),
  Pair(-21, -7), Pair(18, 5), Pair(6, 3), Pair(14, 11), Pair(7, 4), Pair(14, -1), Pair(11, 11), Pair(13, -22),
  Pair(-28, 28), Pair(4, 5), Pair(-1, 17), Pair(12, 12), Pair(15, 22), Pair(-2, 7), Pair(9, -1), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 61);

constexpr ScorePair kTempoBonus = Pair(27, 28);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H