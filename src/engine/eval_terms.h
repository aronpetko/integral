#ifndef INTEGRAL_EVAL_TERMS_H
#define INTEGRAL_EVAL_TERMS_H

#include "../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceValueTable = std::array<T, PieceType::kNumTypes>;

template <typename T>
using PieceSquareTable = std::array<std::array<T, kSquareCount>,
                                    PieceType::kNumTypes>;

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
  Pair(101, 153), Pair(317, 307), Pair(368, 334), Pair(455, 692), Pair(999, 1180), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(40, 63), Pair(56, 48), Pair(35, 47), Pair(78, -24), Pair(49, -22), Pair(26, -10), Pair(-64, 56), Pair(-69, 58),
      Pair(11, 43), Pair(16, 53), Pair(54, -5), Pair(56, -52), Pair(68, -56), Pair(115, -38), Pair(69, 29), Pair(47, 10),
      Pair(-18, 17), Pair(-5, 14), Pair(1, -12), Pair(11, -37), Pair(36, -37), Pair(34, -34), Pair(22, 2), Pair(22, -22),
      Pair(-31, -6), Pair(-19, 2), Pair(-12, -20), Pair(8, -28), Pair(10, -28), Pair(15, -31), Pair(5, -8), Pair(5, -36),
      Pair(-27, -12), Pair(-20, 0), Pair(-11, -18), Pair(-5, -20), Pair(11, -17), Pair(15, -25), Pair(25, -12), Pair(13, -40),
      Pair(-30, -5), Pair(-20, 8), Pair(-21, -6), Pair(-19, -13), Pair(-5, 2), Pair(27, -18), Pair(36, -6), Pair(0, -35),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-185, -62), Pair(-154, 22), Pair(-80, 42), Pair(-45, 28), Pair(0, 30), Pair(-78, 4), Pair(-128, 21), Pair(-129, -85),
      Pair(-31, 23), Pair(-4, 43), Pair(32, 37), Pair(58, 36), Pair(27, 28), Pair(99, 15), Pair(-17, 41), Pair(11, 1),
      Pair(-8, 33), Pair(38, 43), Pair(62, 66), Pair(72, 67), Pair(120, 48), Pair(122, 38), Pair(66, 35), Pair(25, 20),
      Pair(-8, 50), Pair(10, 65), Pair(41, 81), Pair(68, 82), Pair(41, 83), Pair(72, 79), Pair(23, 64), Pair(38, 36),
      Pair(-25, 48), Pair(-4, 56), Pair(18, 81), Pair(21, 82), Pair(33, 86), Pair(25, 70), Pair(23, 55), Pair(-10, 38),
      Pair(-47, 27), Pair(-19, 48), Pair(-2, 54), Pair(14, 74), Pair(30, 70), Pair(9, 48), Pair(10, 37), Pair(-24, 29),
      Pair(-57, 23), Pair(-42, 39), Pair(-23, 46), Pair(-5, 44), Pair(-4, 44), Pair(0, 39), Pair(-18, 25), Pair(-21, 31),
      Pair(-101, 17), Pair(-42, 6), Pair(-48, 34), Pair(-30, 36), Pair(-24, 36), Pair(-14, 21), Pair(-37, 13), Pair(-64, 13)
  },
  {
      Pair(-23, 60), Pair(-53, 70), Pair(-46, 59), Pair(-98, 73), Pair(-80, 68), Pair(-67, 57), Pair(-24, 55), Pair(-48, 54),
      Pair(-3, 46), Pair(21, 54), Pair(9, 56), Pair(-14, 58), Pair(25, 44), Pair(8, 50), Pair(10, 59), Pair(-5, 43),
      Pair(7, 67), Pair(32, 58), Pair(30, 60), Pair(50, 49), Pair(32, 54), Pair(75, 62), Pair(50, 56), Pair(40, 62),
      Pair(-1, 61), Pair(13, 67), Pair(32, 62), Pair(47, 76), Pair(42, 68), Pair(34, 66), Pair(12, 63), Pair(2, 62),
      Pair(0, 56), Pair(4, 66), Pair(6, 72), Pair(37, 72), Pair(33, 68), Pair(8, 66), Pair(6, 61), Pair(15, 42),
      Pair(5, 55), Pair(18, 64), Pair(19, 67), Pair(15, 67), Pair(18, 72), Pair(22, 63), Pair(23, 55), Pair(27, 43),
      Pair(14, 57), Pair(22, 47), Pair(29, 41), Pair(5, 60), Pair(18, 55), Pair(31, 48), Pair(42, 51), Pair(22, 36),
      Pair(4, 47), Pair(27, 61), Pair(5, 51), Pair(-1, 59), Pair(6, 58), Pair(1, 64), Pair(25, 41), Pair(23, 27)
  },
  {
      Pair(5, 58), Pair(-2, 74), Pair(5, 72), Pair(2, 67), Pair(13, 54), Pair(22, 68), Pair(0, 71), Pair(-30, 71),
      Pair(-12, 62), Pair(-10, 83), Pair(13, 77), Pair(34, 62), Pair(7, 60), Pair(34, 63), Pair(4, 67), Pair(-11, 60),
      Pair(-32, 60), Pair(2, 66), Pair(1, 59), Pair(-3, 55), Pair(29, 38), Pair(39, 43), Pair(72, 41), Pair(6, 38),
      Pair(-36, 61), Pair(-22, 66), Pair(-21, 66), Pair(-12, 60), Pair(-14, 40), Pair(-4, 48), Pair(-10, 53), Pair(-25, 43),
      Pair(-46, 50), Pair(-46, 63), Pair(-32, 54), Pair(-29, 53), Pair(-27, 44), Pair(-39, 57), Pair(-20, 45), Pair(-42, 35),
      Pair(-47, 42), Pair(-43, 49), Pair(-33, 42), Pair(-30, 45), Pair(-20, 31), Pair(-22, 37), Pair(7, 14), Pair(-18, 9),
      Pair(-45, 34), Pair(-38, 46), Pair(-21, 41), Pair(-23, 41), Pair(-16, 27), Pair(-11, 32), Pair(-13, 25), Pair(-49, 21),
      Pair(-26, 39), Pair(-22, 43), Pair(-15, 45), Pair(-9, 38), Pair(-4, 27), Pair(-7, 39), Pair(-13, 31), Pair(-30, 18)
  },
  {
      Pair(-18, 142), Pair(-25, 159), Pair(-3, 181), Pair(43, 157), Pair(46, 158), Pair(55, 160), Pair(97, 93), Pair(15, 153),
      Pair(14, 127), Pair(-11, 162), Pair(-6, 195), Pair(-19, 219), Pair(-14, 241), Pair(28, 194), Pair(17, 180), Pair(62, 172),
      Pair(17, 129), Pair(12, 141), Pair(7, 180), Pair(18, 188), Pair(24, 205), Pair(84, 182), Pair(89, 147), Pair(89, 143),
      Pair(1, 141), Pair(3, 152), Pair(6, 163), Pair(3, 189), Pair(5, 203), Pair(18, 193), Pair(27, 187), Pair(33, 175),
      Pair(4, 130), Pair(1, 156), Pair(2, 153), Pair(8, 179), Pair(11, 172), Pair(11, 170), Pair(20, 160), Pair(26, 160),
      Pair(8, 114), Pair(12, 129), Pair(13, 144), Pair(10, 142), Pair(15, 149), Pair(18, 151), Pair(33, 135), Pair(27, 126),
      Pair(11, 109), Pair(16, 107), Pair(25, 104), Pair(29, 114), Pair(25, 120), Pair(40, 91), Pair(46, 63), Pair(52, 44),
      Pair(7, 108), Pair(10, 104), Pair(18, 105), Pair(22, 121), Pair(24, 105), Pair(10, 104), Pair(35, 75), Pair(22, 75)
  },
  {
      Pair(61, -129), Pair(78, -70), Pair(79, -47), Pair(-80, 7), Pair(-46, -6), Pair(21, -8), Pair(87, -22), Pair(188, -151),
      Pair(-91, -9), Pair(-39, 31), Pair(-77, 42), Pair(45, 24), Pair(-23, 48), Pair(-11, 63), Pair(14, 50), Pair(-14, 8),
      Pair(-128, 8), Pair(15, 34), Pair(-62, 57), Pair(-90, 71), Pair(-42, 74), Pair(49, 64), Pair(6, 63), Pair(-44, 20),
      Pair(-85, -5), Pair(-87, 37), Pair(-112, 62), Pair(-168, 77), Pair(-154, 79), Pair(-115, 73), Pair(-112, 60), Pair(-155, 26),
      Pair(-88, -17), Pair(-82, 20), Pair(-127, 51), Pair(-164, 70), Pair(-161, 68), Pair(-117, 52), Pair(-125, 36), Pair(-165, 17),
      Pair(-31, -29), Pair(-5, -2), Pair(-79, 27), Pair(-98, 42), Pair(-90, 42), Pair(-89, 30), Pair(-36, 4), Pair(-54, -12),
      Pair(78, -56), Pair(26, -20), Pair(9, -6), Pair(-35, 8), Pair(-38, 12), Pair(-14, -1), Pair(38, -24), Pair(50, -49),
      Pair(71, -104), Pair(99, -77), Pair(65, -53), Pair(-49, -28), Pair(19, -54), Pair(-14, -33), Pair(70, -70), Pair(75, -106)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(19, 99), Pair(37, 99), Pair(42, 108), Pair(46, 105), Pair(49, 110), Pair(47, 117), Pair(46, 118), Pair(45, 119),
  Pair(47, 115)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-15, 17), Pair(-5, 37), Pair(4, 47), Pair(6, 61), Pair(15, 77), Pair(23, 92), Pair(30, 97), Pair(34, 105),
  Pair(35, 113), Pair(38, 111), Pair(41, 109), Pair(45, 110), Pair(39, 116), Pair(74, 95)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(7, 43), Pair(16, 68), Pair(20, 70), Pair(24, 74), Pair(23, 82), Pair(28, 86), Pair(30, 89), Pair(34, 92),
  Pair(34, 100), Pair(36, 105), Pair(40, 106), Pair(42, 110), Pair(42, 114), Pair(46, 117), Pair(42, 113)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(0, 32), Pair(-8, 62), Pair(-20, 145), Pair(-17, 165), Pair(-15, 169), Pair(-13, 177), Pair(-8, 186), Pair(-10, 211),
  Pair(-8, 220), Pair(-6, 225), Pair(-5, 237), Pair(-5, 245), Pair(-5, 256), Pair(-3, 264), Pair(-1, 270), Pair(-2, 278),
  Pair(2, 282), Pair(-1, 295), Pair(2, 301), Pair(6, 300), Pair(17, 299), Pair(21, 299), Pair(23, 301), Pair(31, 300),
  Pair(55, 277), Pair(120, 256), Pair(117, 255), Pair(234, 206)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-9, 3), Pair(-16, 12), Pair(-9, 41), Pair(13, 69), Pair(3, 144), Pair(51, 192), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -12), Pair(1, 0), Pair(21, 15), Pair(47, 63), Pair(134, 235), Pair(-54, 528), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-23, -48), Pair(-1, -35), Pair(-8, -28), Pair(-7, -13), Pair(-17, -8), Pair(-23, -23), Pair(-14, -37), Pair(-28, -55)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-6, 1), Pair(-9, -19), Pair(-20, -15), Pair(-19, -23), Pair(-22, -25), Pair(-17, -11), Pair(-10, -19), Pair(-14, 7)
};

constexpr FileTable<ScorePair> kRookOnOpenFileBonus = {
  Pair(37, 10), Pair(32, 0), Pair(28, 11), Pair(30, 11), Pair(38, 17), Pair(54, -2), Pair(83, -10), Pair(142, -16)
};

constexpr FileTable<ScorePair> kRookOnSemiOpenFileBonus = {
  Pair(6, 52), Pair(9, 16), Pair(7, 18), Pair(18, 5), Pair(15, 8), Pair(23, -2), Pair(46, -6), Pair(44, 23)
};

constexpr ScorePair kTempoBonus = Pair(24, 29);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H