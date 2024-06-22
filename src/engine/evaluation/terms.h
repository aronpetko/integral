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
  Pair(82, 173), Pair(293, 324), Pair(336, 351), Pair(405, 702), Pair(868, 1264), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(55, 150), Pair(51, 152), Pair(39, 145), Pair(70, 95), Pair(57, 94), Pair(40, 111), Pair(-20, 159), Pair(-34, 164),
      Pair(0, -8), Pair(-10, 12), Pair(30, -40), Pair(31, -75), Pair(40, -81), Pair(72, -63), Pair(22, -9), Pair(-1, -18),
      Pair(-21, -27), Pair(-20, -19), Pair(-6, -49), Pair(-1, -69), Pair(21, -73), Pair(13, -65), Pair(-6, -32), Pair(-11, -49),
      Pair(-29, -46), Pair(-32, -26), Pair(-15, -56), Pair(2, -65), Pair(3, -68), Pair(4, -66), Pair(-14, -42), Pair(-13, -63),
      Pair(-28, -51), Pair(-26, -32), Pair(-13, -58), Pair(-8, -58), Pair(4, -59), Pair(-2, -63), Pair(-1, -48), Pair(-8, -67),
      Pair(-27, -45), Pair(-27, -25), Pair(-17, -49), Pair(-20, -53), Pair(-8, -45), Pair(6, -57), Pair(4, -45), Pair(-20, -65),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-130, -38), Pair(-105, 10), Pair(-56, 25), Pair(-25, 11), Pair(-6, 16), Pair(-60, -7), Pair(-95, 10), Pair(-96, -55),
      Pair(-6, 16), Pair(14, 27), Pair(38, 21), Pair(43, 20), Pair(18, 14), Pair(78, 3), Pair(10, 23), Pair(21, -4),
      Pair(10, 20), Pair(41, 24), Pair(43, 43), Pair(35, 42), Pair(68, 29), Pair(70, 15), Pair(34, 19), Pair(19, 9),
      Pair(15, 32), Pair(11, 38), Pair(29, 48), Pair(53, 43), Pair(21, 48), Pair(44, 48), Pair(1, 44), Pair(36, 22),
      Pair(3, 33), Pair(12, 35), Pair(22, 50), Pair(27, 46), Pair(31, 52), Pair(37, 37), Pair(32, 32), Pair(17, 27),
      Pair(-16, 21), Pair(4, 29), Pair(11, 35), Pair(21, 50), Pair(37, 47), Pair(19, 30), Pair(25, 24), Pair(7, 25),
      Pair(-21, 21), Pair(-8, 28), Pair(4, 30), Pair(19, 29), Pair(20, 28), Pair(20, 25), Pair(12, 19), Pair(10, 30),
      Pair(-52, 25), Pair(-14, 16), Pair(-15, 26), Pair(-1, 30), Pair(7, 30), Pair(12, 19), Pair(-10, 22), Pair(-17, 18)
  },
  {
      Pair(-46, 28), Pair(-72, 33), Pair(-69, 26), Pair(-115, 36), Pair(-109, 34), Pair(-105, 25), Pair(-60, 24), Pair(-79, 19),
      Pair(-29, 12), Pair(-4, 21), Pair(-18, 23), Pair(-31, 26), Pair(-20, 18), Pair(-27, 22), Pair(-33, 29), Pair(-44, 16),
      Pair(-20, 30), Pair(-4, 26), Pair(-5, 31), Pair(-1, 19), Pair(-23, 28), Pair(10, 35), Pair(-5, 32), Pair(-11, 31),
      Pair(-27, 27), Pair(-16, 30), Pair(-7, 30), Pair(0, 41), Pair(-1, 35), Pair(-9, 37), Pair(-20, 25), Pair(-34, 30),
      Pair(-21, 20), Pair(-30, 30), Pair(-19, 34), Pair(1, 33), Pair(-1, 29), Pair(-19, 31), Pair(-22, 30), Pair(-7, 10),
      Pair(-22, 20), Pair(-6, 33), Pair(-7, 34), Pair(-9, 37), Pair(-5, 41), Pair(-3, 34), Pair(-2, 25), Pair(-1, 13),
      Pair(-10, 27), Pair(-7, 13), Pair(2, 16), Pair(-15, 26), Pair(-4, 26), Pair(7, 19), Pair(15, 19), Pair(2, 8),
      Pair(-21, 15), Pair(1, 30), Pair(-21, 20), Pair(-24, 26), Pair(-15, 22), Pair(-20, 31), Pair(-7, 15), Pair(6, -6)
  },
  {
      Pair(1, 5), Pair(-7, 17), Pair(-6, 18), Pair(-11, 14), Pair(-2, 4), Pair(19, 11), Pair(13, 10), Pair(-2, 6),
      Pair(-3, 8), Pair(-4, 25), Pair(14, 21), Pair(26, 11), Pair(10, 9), Pair(36, 8), Pair(24, 4), Pair(15, -2),
      Pair(-13, 6), Pair(14, 11), Pair(13, 7), Pair(10, 3), Pair(36, -11), Pair(45, -8), Pair(65, -12), Pair(15, -16),
      Pair(-15, 6), Pair(-1, 10), Pair(3, 10), Pair(6, 4), Pair(10, -11), Pair(9, -4), Pair(9, -3), Pair(-7, -11),
      Pair(-21, -5), Pair(-23, 6), Pair(-11, -1), Pair(-5, -3), Pair(-4, -9), Pair(-22, 3), Pair(0, -11), Pair(-15, -19),
      Pair(-24, -13), Pair(-18, -8), Pair(-11, -12), Pair(-12, -9), Pair(0, -20), Pair(-4, -16), Pair(21, -34), Pair(0, -39),
      Pair(-22, -21), Pair(-15, -11), Pair(-1, -14), Pair(-1, -16), Pair(5, -26), Pair(8, -23), Pair(14, -33), Pair(-17, -37),
      Pair(-8, -17), Pair(-3, -15), Pair(3, -12), Pair(8, -19), Pair(14, -27), Pair(9, -19), Pair(2, -24), Pair(-4, -35)
  },
  {
      Pair(-49, -7), Pair(-53, 4), Pair(-39, 23), Pair(-10, 1), Pair(-21, 7), Pair(-15, 12), Pair(32, -42), Pair(-27, -7),
      Pair(-6, -19), Pair(-25, 15), Pair(-28, 45), Pair(-38, 60), Pair(-56, 80), Pair(-9, 27), Pair(-9, 21), Pair(40, -4),
      Pair(-5, -5), Pair(-9, 11), Pair(-10, 42), Pair(-8, 41), Pair(-9, 50), Pair(22, 24), Pair(25, 1), Pair(19, -11),
      Pair(-15, 6), Pair(-11, 24), Pair(-9, 30), Pair(-14, 48), Pair(-11, 46), Pair(0, 26), Pair(6, 23), Pair(4, 5),
      Pair(-9, -2), Pair(-15, 25), Pair(-10, 22), Pair(-5, 36), Pair(-1, 35), Pair(-7, 22), Pair(7, 10), Pair(6, -4),
      Pair(-7, -20), Pair(-2, -2), Pair(-2, 9), Pair(-6, 14), Pair(0, 19), Pair(4, 11), Pair(17, -10), Pair(11, -24),
      Pair(0, -32), Pair(2, -27), Pair(7, -22), Pair(12, -16), Pair(11, -10), Pair(21, -39), Pair(25, -59), Pair(29, -82),
      Pair(-7, -31), Pair(-2, -29), Pair(1, -21), Pair(4, -11), Pair(9, -26), Pair(-1, -36), Pair(6, -53), Pair(7, -61)
  },
  {
      Pair(77, -98), Pair(98, -51), Pair(68, -27), Pair(-63, 18), Pair(-36, 2), Pair(-22, 1), Pair(46, -17), Pair(162, -124),
      Pair(-59, -1), Pair(21, 24), Pair(-24, 38), Pair(62, 26), Pair(-1, 39), Pair(-3, 52), Pair(16, 36), Pair(-46, 11),
      Pair(-76, 4), Pair(74, 15), Pair(-7, 42), Pair(-30, 56), Pair(-1, 55), Pair(65, 36), Pair(2, 37), Pair(-41, 7),
      Pair(-48, -13), Pair(3, 9), Pair(-52, 39), Pair(-96, 57), Pair(-98, 52), Pair(-68, 41), Pair(-62, 19), Pair(-128, 7),
      Pair(-50, -26), Pair(-8, -2), Pair(-66, 33), Pair(-104, 53), Pair(-105, 49), Pair(-61, 26), Pair(-57, 7), Pair(-128, -3),
      Pair(-18, -30), Pair(25, -9), Pair(-37, 21), Pair(-55, 37), Pair(-48, 33), Pair(-44, 19), Pair(-9, -4), Pair(-43, -18),
      Pair(40, -43), Pair(7, -8), Pair(-2, 7), Pair(-25, 18), Pair(-30, 19), Pair(-17, 8), Pair(6, -12), Pair(22, -38),
      Pair(28, -71), Pair(41, -40), Pair(28, -23), Pair(-34, -2), Pair(12, -25), Pair(-23, -10), Pair(24, -35), Pair(36, -77)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-29, -13), Pair(-16, -4), Pair(-6, 16), Pair(-2, 25), Pair(4, 32), Pair(10, 40), Pair(17, 39), Pair(22, 37),
  Pair(26, 29)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-30, -28), Pair(-21, -23), Pair(-11, -7), Pair(-4, 6), Pair(3, 15), Pair(6, 26), Pair(9, 29), Pair(10, 33),
  Pair(11, 36), Pair(15, 34), Pair(23, 30), Pair(29, 30), Pair(25, 44), Pair(30, 23)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-19, -53), Pair(-11, -23), Pair(-8, -19), Pair(-5, -14), Pair(-8, -6), Pair(-3, -2), Pair(-2, 4), Pair(0, 6),
  Pair(2, 10), Pair(4, 13), Pair(7, 15), Pair(5, 19), Pair(7, 21), Pair(8, 17), Pair(1, 16)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-2, -250), Pair(0, -237), Pair(-11, -96), Pair(-9, -49), Pair(-8, -25), Pair(-5, -14), Pair(-3, 4), Pair(-2, 16),
  Pair(1, 23), Pair(3, 25), Pair(4, 30), Pair(6, 35), Pair(8, 36), Pair(7, 41), Pair(9, 42), Pair(11, 43),
  Pair(10, 51), Pair(12, 48), Pair(20, 42), Pair(34, 31), Pair(37, 29), Pair(86, -4), Pair(72, 2), Pair(90, -21),
  Pair(190, -62), Pair(192, -88), Pair(97, -21), Pair(61, -24)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-3, 1), Pair(-5, 11), Pair(0, 39), Pair(20, 70), Pair(13, 137), Pair(19, 35), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -6), Pair(-2, -1), Pair(18, 9), Pair(44, 47), Pair(124, 175), Pair(-87, 430), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-7, -52), Pair(9, -42), Pair(-5, -28), Pair(-5, -16), Pair(-13, -7), Pair(-16, -21), Pair(4, -35), Pair(-5, -52)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-15, 12), Pair(-7, -16), Pair(-17, -10), Pair(-14, -20), Pair(-19, -22), Pair(-9, -12), Pair(-6, -17), Pair(-12, 4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(29, 10), Pair(28, 2), Pair(24, 11), Pair(27, 10), Pair(29, 15), Pair(39, 2), Pair(50, 2), Pair(76, 3)
  },
  {
      Pair(3, 45), Pair(9, 16), Pair(7, 18), Pair(16, 9), Pair(11, 11), Pair(15, 4), Pair(25, 7), Pair(13, 31)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(15, -6), Pair(18, 2), Pair(12, -2),
  Pair(25, -13), Pair(21, -5), Pair(24, -14),
  Pair(35, -6), Pair(0, 0), Pair(31, -6),
  Pair(-18, -4), Pair(-15, 2), Pair(-17, -2)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-8, 3), Pair(-14, 5), Pair(-9, 5),
  Pair(-6, 2), Pair(-15, 7), Pair(-8, 4),
  Pair(-1, -6), Pair(-12, 1), Pair(-2, -5),
  Pair(14, -9), Pair(-6, -3), Pair(12, -7),
  Pair(32, -14), Pair(23, -5), Pair(26, -14),
  Pair(0, 0), Pair(-58, -37), Pair(0, 0),
  Pair(6, -57), Pair(0, 0), Pair(1, -54)
};

constexpr std::array<ScorePair, 8> kKingPassedPawnDistanceTable = {
  Pair(0, 0), Pair(-5, 20), Pair(-11, 3), Pair(-7, -15), Pair(-5, -24), Pair(2, -25), Pair(16, -26), Pair(3, -28)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-92, -4), Pair(-100, 4), Pair(-56, -2), Pair(-50, 0), Pair(-39, 4), Pair(-65, 10), Pair(-66, 10), Pair(-50, 11)
  },
  {
      Pair(-27, 74), Pair(-46, 38), Pair(-23, 25), Pair(-5, 6), Pair(-7, 0), Pair(-15, 13), Pair(-34, 32), Pair(-30, 48)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 4), Pair(34, -6), Pair(78, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, 4), Pair(34, -6), Pair(55, -16), Pair(59, -44), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -15), Pair(34, -17), Pair(56, -17), Pair(85, -22), Pair(93, -35), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 12), Pair(13, 30), Pair(35, 39), Pair(74, 35), Pair(94, 57), Pair(111, 61), Pair(101, 58)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(7, 18), Pair(-4, 14), Pair(12, 24), Pair(29, 26), Pair(16, 36), Pair(19, 48), Pair(24, 20), Pair(-8, 37),
  Pair(0, 18), Pair(15, 17), Pair(13, 23), Pair(5, 37), Pair(9, 26), Pair(9, 22), Pair(19, 15), Pair(1, 26),
  Pair(8, 14), Pair(2, 6), Pair(1, 19), Pair(6, 22), Pair(4, 26), Pair(-6, 21), Pair(0, 9), Pair(-1, 11)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-11, 9), Pair(12, -3), Pair(13, 0), Pair(24, 3), Pair(62, -15), Pair(38, -6), Pair(29, -18), Pair(-18, -26),
  Pair(-20, -8), Pair(22, 5), Pair(7, 1), Pair(22, 7), Pair(13, 3), Pair(24, -4), Pair(14, 13), Pair(22, -26),
  Pair(-25, 27), Pair(11, 5), Pair(4, 18), Pair(18, 14), Pair(24, 22), Pair(3, 9), Pair(17, -2), Pair(-50, 12)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 65);

constexpr ScorePair kTempoBonus = Pair(20, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H