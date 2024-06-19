#ifndef INTEGRAL_EVALUATION_TERMS_H
#define INTEGRAL_EVALUATION_TERMS_H

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
  Pair(117, 156), Pair(326, 241), Pair(398, 312), Pair(495, 625), Pair(1073, 1142), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(132, 97), Pair(89, 109), Pair(101, 96), Pair(82, 76), Pair(73, 80), Pair(66, 75), Pair(-38, 108), Pair(45, 76),
      Pair(-2, -16), Pair(6, -22), Pair(13, -43), Pair(0, -60), Pair(20, -68), Pair(67, -62), Pair(66, -55), Pair(8, -41),
      Pair(-17, -36), Pair(-9, -39), Pair(-12, -54), Pair(3, -71), Pair(15, -67), Pair(21, -68), Pair(16, -50), Pair(-4, -59),
      Pair(-27, -48), Pair(-23, -45), Pair(-19, -61), Pair(-7, -68), Pair(-4, -71), Pair(13, -70), Pair(7, -60), Pair(-19, -66),
      Pair(-28, -53), Pair(-16, -52), Pair(-26, -60), Pair(-23, -59), Pair(-8, -62), Pair(6, -69), Pair(21, -66), Pair(-16, -70),
      Pair(-27, -48), Pair(-19, -46), Pair(-25, -53), Pair(-31, -56), Pair(-20, -47), Pair(19, -64), Pair(31, -63), Pair(-30, -66),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-128, 26), Pair(-93, 52), Pair(-67, 70), Pair(-45, 52), Pair(30, 37), Pair(-127, 62), Pair(0, 23), Pair(-102, -10),
      Pair(-13, 37), Pair(6, 55), Pair(61, 36), Pair(71, 44), Pair(51, 45), Pair(111, 18), Pair(1, 45), Pair(42, 20),
      Pair(3, 37), Pair(44, 38), Pair(68, 50), Pair(69, 55), Pair(109, 42), Pair(121, 37), Pair(61, 38), Pair(31, 34),
      Pair(18, 46), Pair(24, 51), Pair(50, 60), Pair(92, 52), Pair(50, 63), Pair(88, 53), Pair(28, 52), Pair(67, 36),
      Pair(14, 39), Pair(26, 45), Pair(45, 58), Pair(39, 59), Pair(57, 61), Pair(50, 53), Pair(75, 33), Pair(29, 48),
      Pair(-12, 26), Pair(12, 35), Pair(20, 41), Pair(40, 54), Pair(55, 49), Pair(32, 35), Pair(39, 30), Pair(5, 34),
      Pair(-23, 26), Pair(-7, 38), Pair(10, 32), Pair(32, 31), Pair(31, 32), Pair(33, 21), Pair(21, 33), Pair(11, 32),
      Pair(-43, 6), Pair(-8, 11), Pair(-17, 28), Pair(8, 35), Pair(15, 28), Pair(28, 17), Pair(1, 16), Pair(-13, -5)
  },
  {
      Pair(-94, 31), Pair(-118, 37), Pair(-111, 30), Pair(-117, 32), Pair(-104, 33), Pair(-165, 36), Pair(-23, 21), Pair(-29, 17),
      Pair(-40, 18), Pair(-12, 18), Pair(-17, 25), Pair(-34, 27), Pair(-10, 19), Pair(-7, 22), Pair(-29, 18), Pair(-48, 22),
      Pair(-27, 22), Pair(-2, 21), Pair(-16, 29), Pair(1, 23), Pair(16, 29), Pair(2, 34), Pair(21, 24), Pair(7, 20),
      Pair(-26, 15), Pair(-13, 26), Pair(2, 21), Pair(25, 29), Pair(9, 29), Pair(7, 25), Pair(-8, 20), Pair(-19, 25),
      Pair(-17, 15), Pair(-15, 18), Pair(-7, 27), Pair(18, 22), Pair(16, 22), Pair(-18, 25), Pair(-5, 19), Pair(6, 12),
      Pair(-17, 16), Pair(2, 25), Pair(-6, 25), Pair(2, 22), Pair(4, 32), Pair(2, 23), Pair(1, 15), Pair(-3, 15),
      Pair(-2, 22), Pair(-10, 4), Pair(1, 14), Pair(-13, 18), Pair(0, 18), Pair(12, 10), Pair(19, 2), Pair(-4, 2),
      Pair(-32, 11), Pair(-11, 16), Pair(-24, 9), Pair(-33, 22), Pair(-18, 15), Pair(-18, 16), Pair(-8, 0), Pair(-30, 9)
  },
  {
      Pair(42, -4), Pair(24, 15), Pair(30, 10), Pair(36, -1), Pair(43, -1), Pair(25, 15), Pair(55, 3), Pair(52, -1),
      Pair(20, 16), Pair(22, 23), Pair(45, 15), Pair(60, 2), Pair(49, 7), Pair(80, 3), Pair(42, 13), Pair(42, -1),
      Pair(11, 12), Pair(30, 14), Pair(43, 11), Pair(44, 0), Pair(84, -13), Pair(85, -1), Pair(76, -2), Pair(8, 10),
      Pair(-11, 11), Pair(-6, 20), Pair(17, 12), Pair(37, -3), Pair(49, -5), Pair(38, 10), Pair(20, 10), Pair(9, -2),
      Pair(-23, -1), Pair(-14, 6), Pair(-8, 6), Pair(4, -4), Pair(14, -12), Pair(-5, 6), Pair(-9, -4), Pair(-17, -16),
      Pair(-29, -16), Pair(-22, -6), Pair(-12, -10), Pair(-1, -19), Pair(13, -24), Pair(7, -14), Pair(21, -33), Pair(-12, -33),
      Pair(-27, -23), Pair(-14, -20), Pair(3, -18), Pair(11, -30), Pair(22, -34), Pair(22, -32), Pair(11, -35), Pair(-41, -27),
      Pair(-2, -27), Pair(4, -28), Pair(13, -22), Pair(19, -31), Pair(32, -42), Pair(27, -31), Pair(3, -33), Pair(-1, -40)
  },
  {
      Pair(-57, 33), Pair(-37, 35), Pair(-34, 52), Pair(-5, 37), Pair(-7, 50), Pair(51, 20), Pair(86, -13), Pair(99, -24),
      Pair(-37, 18), Pair(-52, 54), Pair(-39, 70), Pair(-24, 76), Pair(-27, 95), Pair(28, 51), Pair(-6, 44), Pair(79, -33),
      Pair(-20, -6), Pair(-23, 36), Pair(-13, 45), Pair(-18, 65), Pair(20, 62), Pair(77, 35), Pair(69, 18), Pair(38, 25),
      Pair(-20, -3), Pair(-19, 27), Pair(-17, 47), Pair(-1, 52), Pair(9, 56), Pair(2, 63), Pair(7, 45), Pair(22, 17),
      Pair(-15, -18), Pair(-19, 10), Pair(-2, 9), Pair(-6, 39), Pair(4, 22), Pair(2, 27), Pair(11, 9), Pair(17, -7),
      Pair(-14, -31), Pair(3, -33), Pair(5, -12), Pair(3, -12), Pair(18, -17), Pair(19, -15), Pair(23, -34), Pair(21, -56),
      Pair(-6, -44), Pair(8, -52), Pair(17, -54), Pair(26, -59), Pair(25, -55), Pair(35, -82), Pair(42, -98), Pair(13, -102),
      Pair(2, -61), Pair(6, -72), Pair(9, -67), Pair(20, -75), Pair(23, -85), Pair(12, -99), Pair(-26, -73), Pair(-19, -72)
  },
  {
      Pair(230, -89), Pair(208, -15), Pair(156, -9), Pair(86, 7), Pair(121, 3), Pair(83, 21), Pair(127, 19), Pair(239, -47),
      Pair(62, 19), Pair(144, 29), Pair(155, 27), Pair(51, 43), Pair(108, 28), Pair(98, 47), Pair(78, 44), Pair(77, 3),
      Pair(33, 25), Pair(144, 29), Pair(84, 43), Pair(58, 54), Pair(112, 35), Pair(104, 36), Pair(63, 43), Pair(-7, 30),
      Pair(13, 12), Pair(82, 27), Pair(25, 52), Pair(32, 54), Pair(9, 52), Pair(30, 40), Pair(-18, 31), Pair(-36, 20),
      Pair(2, -7), Pair(44, 20), Pair(1, 45), Pair(-47, 63), Pair(-50, 56), Pair(-36, 41), Pair(-30, 21), Pair(-36, -1),
      Pair(-15, -3), Pair(27, 18), Pair(-29, 43), Pair(-47, 51), Pair(-47, 47), Pair(-52, 37), Pair(-27, 18), Pair(-24, -4),
      Pair(30, -14), Pair(-3, 17), Pair(-24, 32), Pair(-34, 34), Pair(-36, 31), Pair(-36, 26), Pair(-3, 6), Pair(30, -18),
      Pair(13, -28), Pair(47, -21), Pair(42, -7), Pair(-40, 17), Pair(34, -16), Pair(-44, 7), Pair(37, -24), Pair(56, -64)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-13, 21), Pair(1, 11), Pair(15, 34), Pair(24, 48), Pair(33, 53), Pair(40, 61), Pair(47, 61), Pair(53, 58),
  Pair(52, 51)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-33, -20), Pair(-18, -28), Pair(-7, -14), Pair(4, -1), Pair(13, 9), Pair(21, 18), Pair(25, 21), Pair(28, 23),
  Pair(32, 25), Pair(36, 25), Pair(43, 22), Pair(66, 19), Pair(71, 20), Pair(89, 17)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-17, -62), Pair(-5, -40), Pair(0, -32), Pair(4, -27), Pair(4, -18), Pair(9, -15), Pair(13, -8), Pair(16, -8),
  Pair(18, -2), Pair(22, 0), Pair(25, 1), Pair(27, 3), Pair(30, 1), Pair(41, -6), Pair(28, -2)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-6, -177), Pair(-11, -103), Pair(-12, -77), Pair(-7, -68), Pair(-4, -53), Pair(0, -36), Pair(6, -32), Pair(10, -25),
  Pair(15, -17), Pair(18, -14), Pair(20, -7), Pair(23, -2), Pair(25, 0), Pair(29, 3), Pair(28, 9), Pair(34, 10),
  Pair(38, 10), Pair(44, 4), Pair(58, -4), Pair(66, -7), Pair(84, -22), Pair(103, -31), Pair(102, -33), Pair(157, -73),
  Pair(174, -81), Pair(234, -122), Pair(97, -46), Pair(80, -50)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-13, 6), Pair(-19, 13), Pair(-9, 33), Pair(18, 49), Pair(64, 75), Pair(102, -37), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(-4, -5), Pair(-1, 0), Pair(26, 8), Pair(54, 49), Pair(227, 106), Pair(36, 562), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-35, -48), Pair(-15, -28), Pair(-19, -20), Pair(-15, -16), Pair(-16, -16), Pair(-29, -14), Pair(-29, -25), Pair(-22, -39)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-1, -4), Pair(-11, -13), Pair(-22, -12), Pair(-26, -16), Pair(-25, -15), Pair(-16, -12), Pair(-10, -10), Pair(-2, -1)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(40, -1), Pair(43, -7), Pair(39, 0), Pair(42, 5), Pair(41, 5), Pair(63, -13), Pair(94, -15), Pair(110, -18)
  },
  {
      Pair(21, 33), Pair(18, 13), Pair(18, 8), Pair(26, 8), Pair(17, 8), Pair(33, -8), Pair(42, -2), Pair(34, 18)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(24, -2), Pair(27, -1), Pair(21, -2),
  Pair(37, -7), Pair(41, -5), Pair(38, -8),
  Pair(45, -4), Pair(0, 0), Pair(46, -5),
  Pair(-1, -5), Pair(7, 2), Pair(0, -4)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-15, 10), Pair(-19, 13), Pair(-17, 14),
  Pair(-10, 9), Pair(-21, 18), Pair(-14, 11),
  Pair(-1, -1), Pair(-17, 14), Pair(-4, 2),
  Pair(9, 1), Pair(-15, 13), Pair(6, 1),
  Pair(23, -8), Pair(13, 9), Pair(27, -9),
  Pair(0, 0), Pair(-60, -31), Pair(0, 0),
  Pair(-39, -36), Pair(0, 0), Pair(-35, -39)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-43, -20), Pair(-103, -2), Pair(-58, -11), Pair(-34, -12), Pair(-33, -5), Pair(-39, -1), Pair(-55, 8), Pair(-38, -3)
  },
  {
      Pair(-80, 86), Pair(-83, 46), Pair(-24, 19), Pair(-5, 8), Pair(-1, 6), Pair(-14, 14), Pair(-32, 29), Pair(-40, 50)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(32, -19), Pair(5, 9), Pair(29, 9), Pair(39, 16), Pair(16, 21), Pair(10, 33), Pair(34, 11), Pair(36, 8),
  Pair(13, 22), Pair(18, -3), Pair(19, 20), Pair(7, 30), Pair(14, 17), Pair(-5, 29), Pair(29, 7), Pair(10, 19),
  Pair(7, 15), Pair(0, 8), Pair(-3, 20), Pair(14, 20), Pair(2, 21), Pair(0, 11), Pair(-24, 15), Pair(3, -8)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-35, 0), Pair(22, 0), Pair(32, -8), Pair(43, -9), Pair(39, -11), Pair(74, -17), Pair(37, -10), Pair(-24, -1),
  Pair(-6, 10), Pair(19, 9), Pair(18, 1), Pair(32, -2), Pair(21, 0), Pair(30, 6), Pair(19, 15), Pair(-2, -5),
  Pair(-38, 20), Pair(4, 15), Pair(15, 11), Pair(20, 10), Pair(24, 12), Pair(2, 12), Pair(-4, 17), Pair(-70, 28)
};

constexpr ScorePair kBishopPairBonus = Pair(35, 56);

constexpr ScorePair kTempoBonus = Pair(50, 13);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H