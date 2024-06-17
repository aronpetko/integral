#ifndef INTEGRAL_EVALUATION_TERMS_H
#define INTEGRAL_EVALUATION_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceValueTable = std::array<T, kNumPieceTypes>;

template <typename T>
using PieceSquareTable = std::array<std::array<T, kSquareCount>,
                                    kNumPieceTypes>;

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

constexpr PieceValueTable<ScorePair> kPieceValues = {
  Pair(86, 153), Pair(295, 331), Pair(346, 346), Pair(416, 699), Pair(873, 1276), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(42, 153), Pair(54, 140), Pair(29, 144), Pair(58, 93), Pair(39, 95), Pair(32, 105), Pair(-1, 149), Pair(-32, 152),
      Pair(-1, 8), Pair(-8, 20), Pair(25, -26), Pair(25, -61), Pair(33, -62), Pair(66, -48), Pair(33, 3), Pair(3, -9),
      Pair(-23, -13), Pair(-17, -14), Pair(-11, -34), Pair(-7, -54), Pair(16, -54), Pair(13, -51), Pair(7, -21), Pair(-5, -40),
      Pair(-28, -32), Pair(-27, -23), Pair(-18, -42), Pair(-2, -49), Pair(0, -49), Pair(4, -51), Pair(5, -33), Pair(-7, -54),
      Pair(-28, -37), Pair(-22, -29), Pair(-16, -43), Pair(-11, -43), Pair(0, -39), Pair(-1, -48), Pair(12, -38), Pair(-4, -59),
      Pair(-28, -32), Pair(-22, -23), Pair(-21, -35), Pair(-23, -39), Pair(-10, -28), Pair(7, -44), Pair(18, -34), Pair(-15, -55),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-137, -50), Pair(-115, -3), Pair(-58, 10), Pair(-23, -2), Pair(7, 0), Pair(-51, -22), Pair(-100, -4), Pair(-94, -69),
      Pair(-15, 1), Pair(6, 12), Pair(31, 7), Pair(48, 5), Pair(23, -1), Pair(84, -14), Pair(0, 10), Pair(22, -19),
      Pair(3, 5), Pair(31, 12), Pair(40, 33), Pair(51, 33), Pair(87, 17), Pair(87, 9), Pair(51, 4), Pair(25, -5),
      Pair(6, 20), Pair(9, 28), Pair(30, 42), Pair(52, 44), Pair(34, 43), Pair(55, 40), Pair(19, 29), Pair(40, 9),
      Pair(-6, 24), Pair(2, 22), Pair(13, 43), Pair(21, 42), Pair(28, 47), Pair(24, 34), Pair(33, 20), Pair(8, 19),
      Pair(-27, 6), Pair(-8, 15), Pair(0, 21), Pair(10, 36), Pair(26, 33), Pair(10, 17), Pair(16, 9), Pair(-4, 11),
      Pair(-32, 7), Pair(-19, 13), Pair(-8, 15), Pair(9, 14), Pair(10, 13), Pair(9, 11), Pair(3, 4), Pair(-1, 17),
      Pair(-63, 10), Pair(-25, 0), Pair(-25, 10), Pair(-10, 15), Pair(-3, 16), Pair(0, 5), Pair(-21, 8), Pair(-31, 5)
  },
  {
      Pair(-39, 22), Pair(-62, 25), Pair(-57, 18), Pair(-98, 27), Pair(-84, 24), Pair(-79, 15), Pair(-42, 14), Pair(-58, 9),
      Pair(-18, 4), Pair(-1, 15), Pair(-11, 16), Pair(-24, 19), Pair(3, 8), Pair(-5, 12), Pair(-10, 17), Pair(-25, 7),
      Pair(-13, 23), Pair(5, 18), Pair(3, 26), Pair(19, 13), Pair(9, 17), Pair(40, 24), Pair(19, 18), Pair(11, 19),
      Pair(-21, 18), Pair(-6, 27), Pair(8, 24), Pair(26, 39), Pair(19, 30), Pair(11, 30), Pair(-4, 22), Pair(-16, 19),
      Pair(-16, 15), Pair(-17, 26), Pair(-6, 34), Pair(19, 34), Pair(16, 33), Pair(-10, 30), Pair(-10, 23), Pair(1, 4),
      Pair(-14, 14), Pair(4, 27), Pair(1, 28), Pair(0, 31), Pair(3, 34), Pair(4, 27), Pair(5, 19), Pair(7, 7),
      Pair(0, 20), Pair(1, 7), Pair(9, 8), Pair(-8, 20), Pair(3, 18), Pair(11, 13), Pair(21, 11), Pair(8, 2),
      Pair(-12, 8), Pair(11, 23), Pair(-13, 13), Pair(-17, 18), Pair(-10, 16), Pair(-14, 24), Pair(1, 7), Pair(12, -13)
  },
  {
      Pair(13, 5), Pair(5, 17), Pair(8, 17), Pair(5, 12), Pair(17, 1), Pair(28, 11), Pair(16, 14), Pair(3, 9),
      Pair(3, 8), Pair(6, 24), Pair(23, 19), Pair(37, 9), Pair(22, 6), Pair(43, 9), Pair(27, 9), Pair(20, 1),
      Pair(-10, 7), Pair(19, 11), Pair(18, 6), Pair(17, 3), Pair(45, -12), Pair(52, -7), Pair(74, -9), Pair(25, -14),
      Pair(-13, 7), Pair(1, 10), Pair(4, 11), Pair(9, 5), Pair(11, -9), Pair(14, -2), Pair(12, 0), Pair(-1, -8),
      Pair(-20, -2), Pair(-20, 8), Pair(-8, 1), Pair(-5, 0), Pair(-4, -6), Pair(-15, 5), Pair(4, -7), Pair(-10, -16),
      Pair(-23, -9), Pair(-17, -4), Pair(-10, -9), Pair(-11, -7), Pair(1, -17), Pair(0, -13), Pair(26, -32), Pair(4, -35),
      Pair(-22, -17), Pair(-15, -8), Pair(0, -11), Pair(0, -12), Pair(6, -23), Pair(10, -18), Pair(13, -27), Pair(-19, -30),
      Pair(-7, -13), Pair(-1, -11), Pair(5, -8), Pair(9, -15), Pair(15, -23), Pair(11, -15), Pair(3, -19), Pair(-3, -31)
  },
  {
      Pair(-48, -3), Pair(-54, 14), Pair(-36, 36), Pair(1, 18), Pair(2, 18), Pair(12, 16), Pair(50, -40), Pair(-15, 5),
      Pair(-10, -20), Pair(-33, 14), Pair(-30, 44), Pair(-43, 68), Pair(-36, 83), Pair(3, 43), Pair(-2, 27), Pair(40, 15),
      Pair(-9, -11), Pair(-13, 3), Pair(-16, 35), Pair(-6, 42), Pair(-2, 57), Pair(47, 36), Pair(49, 9), Pair(47, 6),
      Pair(-20, -3), Pair(-18, 11), Pair(-15, 21), Pair(-16, 41), Pair(-16, 57), Pair(-2, 45), Pair(4, 41), Pair(7, 28),
      Pair(-17, -10), Pair(-21, 13), Pair(-16, 11), Pair(-11, 31), Pair(-8, 29), Pair(-10, 28), Pair(-1, 20), Pair(6, 14),
      Pair(-13, -29), Pair(-9, -10), Pair(-8, 1), Pair(-12, 2), Pair(-6, 8), Pair(-2, 8), Pair(10, -7), Pair(6, -14),
      Pair(-9, -37), Pair(-6, -36), Pair(0, -34), Pair(6, -30), Pair(4, -25), Pair(12, -45), Pair(16, -64), Pair(20, -81),
      Pair(-15, -37), Pair(-8, -38), Pair(-4, -35), Pair(-1, -26), Pair(2, -39), Pair(-8, -37), Pair(1, -56), Pair(1, -65)
  },
  {
      Pair(66, -100), Pair(70, -50), Pair(74, -34), Pair(-67, 12), Pair(-23, -2), Pair(19, -1), Pair(85, -17), Pair(194, -123),
      Pair(-69, -1), Pair(-16, 26), Pair(-45, 36), Pair(45, 23), Pair(-3, 39), Pair(-2, 55), Pair(31, 39), Pair(3, 10),
      Pair(-101, 8), Pair(24, 23), Pair(-34, 44), Pair(-55, 56), Pair(-18, 59), Pair(45, 44), Pair(-6, 45), Pair(-34, 14),
      Pair(-61, -6), Pair(-53, 21), Pair(-76, 44), Pair(-122, 59), Pair(-115, 57), Pair(-92, 50), Pair(-88, 32), Pair(-126, 17),
      Pair(-58, -17), Pair(-54, 11), Pair(-96, 38), Pair(-131, 54), Pair(-130, 53), Pair(-93, 35), Pair(-89, 20), Pair(-129, 7),
      Pair(-26, -22), Pair(-9, -1), Pair(-63, 24), Pair(-81, 38), Pair(-78, 36), Pair(-81, 26), Pair(-45, 5), Pair(-50, -10),
      Pair(43, -39), Pair(-19, -4), Pair(-18, 6), Pair(-34, 14), Pair(-44, 18), Pair(-37, 11), Pair(-15, -7), Pair(22, -33),
      Pair(35, -73), Pair(37, -44), Pair(34, -29), Pair(-30, -12), Pair(23, -35), Pair(-27, -12), Pair(22, -36), Pair(46, -76)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-26, -5), Pair(-11, 1), Pair(-2, 22), Pair(4, 31), Pair(10, 39), Pair(15, 46), Pair(23, 45), Pair(29, 41),
  Pair(34, 30)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-54, -17), Pair(-43, -14), Pair(-32, 3), Pair(-24, 16), Pair(-16, 25), Pair(-12, 36), Pair(-7, 40), Pair(-5, 41),
  Pair(-3, 44), Pair(2, 41), Pair(11, 36), Pair(18, 33), Pair(18, 40), Pair(28, 18)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-35, -59), Pair(-29, -31), Pair(-25, -28), Pair(-22, -23), Pair(-24, -15), Pair(-19, -11), Pair(-17, -4), Pair(-14, -3),
  Pair(-11, 1), Pair(-8, 4), Pair(-4, 5), Pair(-4, 8), Pair(1, 10), Pair(4, 6), Pair(-4, 8)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-7, -261), Pair(-5, -251), Pair(-15, -111), Pair(-13, -65), Pair(-12, -41), Pair(-9, -28), Pair(-7, -10), Pair(-5, 4),
  Pair(-2, 11), Pair(1, 14), Pair(2, 21), Pair(4, 27), Pair(7, 29), Pair(6, 37), Pair(9, 39), Pair(11, 44),
  Pair(11, 52), Pair(12, 53), Pair(21, 51), Pair(33, 45), Pair(35, 48), Pair(85, 19), Pair(72, 31), Pair(94, 10),
  Pair(209, -33), Pair(219, -60), Pair(150, -3), Pair(104, 1)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-6, 2), Pair(-12, 11), Pair(-9, 37), Pair(11, 62), Pair(8, 124), Pair(29, 34), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-1, 0), Pair(18, 9), Pair(43, 47), Pair(112, 184), Pair(-69, 430), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-14, -40), Pair(2, -30), Pair(-6, -25), Pair(-4, -16), Pair(-12, -9), Pair(-15, -20), Pair(-13, -29), Pair(-15, -47)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-7, 0), Pair(-7, -15), Pair(-17, -12), Pair(-15, -19), Pair(-20, -20), Pair(-10, -9), Pair(-7, -16), Pair(-8, 5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(27, 9), Pair(26, 2), Pair(22, 11), Pair(27, 10), Pair(29, 16), Pair(50, -2), Pair(64, -5), Pair(92, -5)
  },
  {
      Pair(3, 44), Pair(8, 16), Pair(6, 17), Pair(15, 9), Pair(11, 12), Pair(19, 1), Pair(37, 0), Pair(23, 24)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(18, 0), Pair(34, 1), Pair(14, 4),
  Pair(28, -5), Pair(44, -6), Pair(26, -6),
  Pair(39, 1), Pair(0, 0), Pair(35, 1),
  Pair(-19, 4), Pair(14, 4), Pair(-18, 5)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-14, 9), Pair(-23, 6), Pair(-15, 10),
  Pair(-12, 8), Pair(-24, 8), Pair(-15, 10),
  Pair(-6, 0), Pair(-19, 1), Pair(-6, 1),
  Pair(6, -1), Pair(-12, -4), Pair(5, 1),
  Pair(21, -6), Pair(14, -6), Pair(14, -6),
  Pair(0, 0), Pair(-74, -40), Pair(0, 0),
  Pair(-13, -48), Pair(0, 0), Pair(-17, -45)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 65);
constexpr ScorePair kTempoBonus = Pair(21, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H