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
  Pair(92, 157), Pair(321, 305), Pair(369, 326), Pair(457, 688), Pair(1006, 1176), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(45, 59), Pair(58, 46), Pair(42, 43), Pair(86, -26), Pair(57, -25), Pair(31, -12), Pair(-60, 54), Pair(-93, 63),
      Pair(19, 36), Pair(22, 49), Pair(62, -11), Pair(67, -57), Pair(76, -62), Pair(118, -42), Pair(72, 24), Pair(35, 9),
      Pair(-9, 12), Pair(2, 11), Pair(10, -17), Pair(17, -40), Pair(44, -42), Pair(43, -39), Pair(30, -2), Pair(15, -23),
      Pair(-22, -11), Pair(-12, -1), Pair(-4, -25), Pair(16, -33), Pair(18, -33), Pair(23, -37), Pair(16, -14), Pair(-1, -38),
      Pair(-20, -17), Pair(-14, -4), Pair(-4, -24), Pair(0, -24), Pair(12, -21), Pair(8, -28), Pair(17, -15), Pair(0, -40),
      Pair(-22, -10), Pair(-14, 3), Pair(-16, -13), Pair(-24, -14), Pair(-6, -3), Pair(10, -19), Pair(25, -9), Pair(-22, -34),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-191, -61), Pair(-150, 20), Pair(-79, 41), Pair(-43, 28), Pair(-4, 30), Pair(-80, 4), Pair(-130, 21), Pair(-137, -83),
      Pair(-32, 24), Pair(-2, 42), Pair(32, 37), Pair(60, 35), Pair(22, 28), Pair(99, 14), Pair(-16, 40), Pair(15, 1),
      Pair(-5, 32), Pair(40, 43), Pair(64, 66), Pair(74, 68), Pair(121, 48), Pair(120, 39), Pair(66, 35), Pair(20, 21),
      Pair(-6, 49), Pair(11, 64), Pair(43, 81), Pair(68, 82), Pair(43, 83), Pair(75, 77), Pair(24, 63), Pair(34, 36),
      Pair(-23, 48), Pair(-4, 56), Pair(20, 80), Pair(21, 82), Pair(34, 85), Pair(26, 70), Pair(27, 53), Pair(-8, 37),
      Pair(-48, 26), Pair(-18, 47), Pair(-1, 54), Pair(15, 73), Pair(32, 69), Pair(10, 48), Pair(12, 36), Pair(-24, 30),
      Pair(-55, 23), Pair(-42, 38), Pair(-21, 46), Pair(-4, 44), Pair(-4, 43), Pair(2, 38), Pair(-12, 23), Pair(-16, 29),
      Pair(-96, 18), Pair(-45, 8), Pair(-49, 33), Pair(-30, 35), Pair(-23, 36), Pair(-13, 21), Pair(-41, 17), Pair(-61, 13)
  },
  {
      Pair(-24, 63), Pair(-50, 72), Pair(-45, 61), Pair(-97, 75), Pair(-78, 69), Pair(-70, 59), Pair(-20, 56), Pair(-47, 57),
      Pair(-1, 48), Pair(23, 56), Pair(12, 58), Pair(-12, 60), Pair(26, 45), Pair(14, 51), Pair(13, 60), Pair(-9, 49),
      Pair(7, 69), Pair(32, 60), Pair(32, 63), Pair(51, 51), Pair(37, 56), Pair(75, 64), Pair(50, 58), Pair(39, 65),
      Pair(-1, 63), Pair(15, 69), Pair(33, 63), Pair(51, 77), Pair(43, 71), Pair(34, 69), Pair(13, 64), Pair(3, 64),
      Pair(2, 57), Pair(5, 67), Pair(8, 75), Pair(40, 74), Pair(34, 71), Pair(10, 69), Pair(6, 63), Pair(16, 44),
      Pair(5, 57), Pair(21, 67), Pair(22, 69), Pair(16, 70), Pair(21, 73), Pair(23, 65), Pair(25, 57), Pair(27, 45),
      Pair(15, 60), Pair(23, 49), Pair(29, 44), Pair(7, 60), Pair(20, 58), Pair(33, 51), Pair(48, 52), Pair(25, 40),
      Pair(6, 49), Pair(26, 64), Pair(5, 53), Pair(-1, 62), Pair(8, 60), Pair(3, 67), Pair(21, 45), Pair(29, 26)
  },
  {
      Pair(5, 58), Pair(-5, 74), Pair(3, 73), Pair(0, 66), Pair(13, 54), Pair(22, 66), Pair(6, 69), Pair(-19, 67),
      Pair(-13, 62), Pair(-12, 83), Pair(12, 77), Pair(32, 62), Pair(7, 60), Pair(37, 63), Pair(11, 66), Pair(4, 56),
      Pair(-32, 60), Pair(-1, 66), Pair(-2, 60), Pair(-5, 54), Pair(28, 38), Pair(36, 44), Pair(71, 41), Pair(7, 39),
      Pair(-37, 61), Pair(-24, 65), Pair(-21, 65), Pair(-13, 57), Pair(-15, 39), Pair(-7, 48), Pair(-11, 52), Pair(-24, 43),
      Pair(-48, 49), Pair(-48, 63), Pair(-33, 54), Pair(-30, 51), Pair(-27, 43), Pair(-41, 55), Pair(-20, 44), Pair(-38, 33),
      Pair(-48, 41), Pair(-46, 48), Pair(-35, 41), Pair(-32, 43), Pair(-21, 31), Pair(-24, 37), Pair(7, 13), Pair(-17, 9),
      Pair(-47, 34), Pair(-40, 46), Pair(-23, 41), Pair(-24, 40), Pair(-17, 27), Pair(-11, 30), Pair(-7, 19), Pair(-45, 17),
      Pair(-28, 38), Pair(-26, 43), Pair(-18, 46), Pair(-13, 37), Pair(-7, 28), Pair(-10, 37), Pair(-17, 30), Pair(-23, 16)
  },
  {
      Pair(-21, 142), Pair(-23, 158), Pair(-3, 181), Pair(41, 158), Pair(46, 159), Pair(51, 163), Pair(106, 89), Pair(18, 149),
      Pair(16, 127), Pair(-9, 161), Pair(-3, 195), Pair(-18, 220), Pair(-13, 241), Pair(36, 192), Pair(33, 172), Pair(77, 165),
      Pair(16, 130), Pair(11, 142), Pair(9, 178), Pair(20, 187), Pair(28, 204), Pair(82, 181), Pair(91, 148), Pair(83, 150),
      Pair(-1, 140), Pair(4, 150), Pair(8, 162), Pair(6, 188), Pair(6, 203), Pair(20, 192), Pair(28, 185), Pair(34, 174),
      Pair(3, 130), Pair(0, 155), Pair(4, 152), Pair(9, 177), Pair(13, 170), Pair(13, 169), Pair(22, 159), Pair(28, 157),
      Pair(7, 112), Pair(11, 131), Pair(14, 143), Pair(10, 139), Pair(16, 147), Pair(20, 150), Pair(35, 133), Pair(28, 128),
      Pair(10, 109), Pair(16, 107), Pair(24, 105), Pair(28, 113), Pair(25, 121), Pair(39, 91), Pair(44, 69), Pair(46, 48),
      Pair(5, 108), Pair(7, 106), Pair(15, 108), Pair(19, 123), Pair(22, 105), Pair(8, 104), Pair(23, 83), Pair(22, 72)
  },
  {
      Pair(72, -131), Pair(90, -74), Pair(91, -51), Pair(-70, 4), Pair(-38, -9), Pair(30, -11), Pair(93, -25), Pair(198, -154),
      Pair(-74, -14), Pair(-20, 26), Pair(-57, 37), Pair(63, 18), Pair(-8, 44), Pair(5, 58), Pair(31, 45), Pair(0, 3),
      Pair(-105, 2), Pair(37, 27), Pair(-38, 50), Pair(-66, 64), Pair(-17, 68), Pair(74, 57), Pair(32, 55), Pair(-18, 13),
      Pair(-59, -12), Pair(-61, 28), Pair(-88, 54), Pair(-148, 71), Pair(-131, 71), Pair(-90, 65), Pair(-82, 49), Pair(-125, 17),
      Pair(-70, -24), Pair(-68, 13), Pair(-112, 45), Pair(-156, 66), Pair(-156, 65), Pair(-104, 45), Pair(-113, 28), Pair(-146, 9),
      Pair(-25, -34), Pair(-9, -6), Pair(-76, 24), Pair(-104, 42), Pair(-93, 40), Pair(-95, 27), Pair(-47, 0), Pair(-53, -17),
      Pair(61, -56), Pair(-9, -16), Pair(-11, -3), Pair(-46, 11), Pair(-53, 13), Pair(-30, 0), Pair(5, -22), Pair(43, -51),
      Pair(61, -102), Pair(69, -69), Pair(62, -53), Pair(-27, -31), Pair(41, -59), Pair(-10, -33), Pair(61, -67), Pair(80, -110)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(18, 98), Pair(34, 101), Pair(41, 109), Pair(45, 107), Pair(47, 112), Pair(46, 118), Pair(45, 119), Pair(44, 120),
  Pair(46, 116)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-13, 21), Pair(-4, 39), Pair(5, 50), Pair(9, 64), Pair(16, 80), Pair(25, 96), Pair(31, 101), Pair(36, 108),
  Pair(37, 117), Pair(40, 115), Pair(43, 113), Pair(48, 112), Pair(43, 120), Pair(76, 98)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(14, 45), Pair(21, 71), Pair(26, 74), Pair(29, 78), Pair(25, 87), Pair(31, 90), Pair(33, 93), Pair(36, 95),
  Pair(36, 105), Pair(39, 108), Pair(42, 109), Pair(44, 113), Pair(43, 117), Pair(47, 120), Pair(44, 115)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-3, 30), Pair(-6, 56), Pair(-19, 141), Pair(-17, 161), Pair(-16, 169), Pair(-13, 179), Pair(-9, 187), Pair(-12, 212),
  Pair(-10, 221), Pair(-7, 225), Pair(-7, 238), Pair(-6, 245), Pair(-7, 256), Pair(-6, 263), Pair(-5, 271), Pair(-4, 277),
  Pair(-1, 282), Pair(-5, 295), Pair(-1, 301), Pair(3, 301), Pair(14, 298), Pair(18, 299), Pair(19, 302), Pair(26, 301),
  Pair(54, 276), Pair(117, 256), Pair(113, 254), Pair(228, 206)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-6, 2), Pair(-14, 12), Pair(-8, 41), Pair(15, 69), Pair(3, 146), Pair(52, 191), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(-1, -9), Pair(0, 1), Pair(20, 15), Pair(49, 64), Pair(135, 235), Pair(-77, 532), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-18, -48), Pair(0, -36), Pair(-7, -28), Pair(-6, -14), Pair(-16, -8), Pair(-21, -22), Pair(-23, -35), Pair(-21, -57)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-9, 2), Pair(-9, -18), Pair(-20, -14), Pair(-19, -22), Pair(-23, -24), Pair(-11, -12), Pair(-10, -19), Pair(-8, 7)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(36, 9), Pair(33, 1), Pair(28, 11), Pair(31, 12), Pair(37, 17), Pair(59, -2), Pair(82, -8), Pair(123, -10)
  },
  {
      Pair(7, 52), Pair(12, 15), Pair(9, 16), Pair(16, 8), Pair(12, 10), Pair(25, -4), Pair(44, -4), Pair(30, 26)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(22, -3), Pair(39, -1), Pair(18, 1),
  Pair(35, -8), Pair(49, -10), Pair(31, -10),
  Pair(47, -2), Pair(0, 0), Pair(40, -2),
  Pair(-31, 19), Pair(14, 4), Pair(-30, 19)
};

constexpr ScorePair kTempoBonus = Pair(24, 28);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H