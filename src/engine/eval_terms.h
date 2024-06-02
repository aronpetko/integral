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
  Pair(104, 149), Pair(322, 316), Pair(360, 346), Pair(456, 690), Pair(998, 1179), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(29, 62), Pair(64, 46), Pair(36, 48), Pair(68, -23), Pair(46, -23), Pair(29, 3), Pair(-45, 52), Pair(-81, 71),
      Pair(0, 51), Pair(18, 55), Pair(53, 1), Pair(50, -47), Pair(63, -52), Pair(106, -19), Pair(74, 29), Pair(26, 31),
      Pair(-27, 28), Pair(0, 19), Pair(1, -5), Pair(7, -30), Pair(33, -31), Pair(24, -16), Pair(28, 6), Pair(1, 0),
      Pair(-38, 6), Pair(-13, 10), Pair(-11, -12), Pair(6, -22), Pair(9, -22), Pair(6, -13), Pair(12, -3), Pair(-15, -16),
      Pair(-33, 0), Pair(-13, 8), Pair(-9, -10), Pair(-5, -11), Pair(12, -10), Pair(7, -7), Pair(34, -6), Pair(-5, -19),
      Pair(-35, 6), Pair(-13, 16), Pair(-19, 1), Pair(-19, -4), Pair(-4, 9), Pair(19, 0), Pair(45, 0), Pair(-18, -16),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-188, -63), Pair(-158, 20), Pair(-85, 40), Pair(-47, 26), Pair(-4, 28), Pair(-78, 0), Pair(-127, 18), Pair(-128, -87),
      Pair(-34, 24), Pair(-6, 41), Pair(28, 36), Pair(53, 33), Pair(23, 25), Pair(99, 11), Pair(-19, 37), Pair(10, -1),
      Pair(-11, 33), Pair(35, 42), Pair(58, 63), Pair(67, 65), Pair(116, 44), Pair(117, 36), Pair(63, 31), Pair(23, 18),
      Pair(-14, 49), Pair(5, 62), Pair(36, 78), Pair(63, 78), Pair(37, 80), Pair(68, 75), Pair(19, 61), Pair(33, 35),
      Pair(-30, 46), Pair(-9, 53), Pair(14, 78), Pair(16, 78), Pair(29, 82), Pair(22, 66), Pair(20, 53), Pair(-15, 35),
      Pair(-52, 24), Pair(-23, 43), Pair(-5, 51), Pair(11, 71), Pair(27, 66), Pair(6, 44), Pair(5, 33), Pair(-28, 26),
      Pair(-60, 20), Pair(-47, 37), Pair(-27, 43), Pair(-8, 42), Pair(-8, 41), Pair(-3, 36), Pair(-24, 22), Pair(-26, 27),
      Pair(-107, 14), Pair(-43, 3), Pair(-50, 30), Pair(-32, 34), Pair(-27, 33), Pair(-18, 20), Pair(-39, 10), Pair(-68, 9)
  },
  {
      Pair(-19, 57), Pair(-51, 69), Pair(-45, 58), Pair(-97, 72), Pair(-77, 65), Pair(-62, 55), Pair(-20, 51), Pair(-45, 51),
      Pair(2, 46), Pair(24, 51), Pair(11, 53), Pair(-13, 55), Pair(25, 42), Pair(11, 45), Pair(15, 55), Pair(2, 41),
      Pair(10, 66), Pair(34, 56), Pair(32, 57), Pair(50, 45), Pair(33, 50), Pair(78, 57), Pair(53, 53), Pair(46, 61),
      Pair(3, 60), Pair(14, 63), Pair(34, 58), Pair(48, 71), Pair(44, 64), Pair(36, 62), Pair(14, 61), Pair(4, 59),
      Pair(2, 54), Pair(6, 63), Pair(9, 68), Pair(39, 66), Pair(35, 65), Pair(11, 63), Pair(6, 58), Pair(17, 40),
      Pair(8, 54), Pair(20, 61), Pair(23, 63), Pair(17, 63), Pair(21, 69), Pair(25, 60), Pair(24, 52), Pair(29, 40),
      Pair(18, 54), Pair(25, 44), Pair(31, 38), Pair(9, 57), Pair(21, 51), Pair(34, 46), Pair(44, 49), Pair(24, 34),
      Pair(8, 44), Pair(31, 59), Pair(11, 50), Pair(4, 57), Pair(12, 56), Pair(4, 62), Pair(30, 39), Pair(26, 25)
  },
  {
      Pair(4, 70), Pair(-5, 78), Pair(0, 81), Pair(-1, 70), Pair(11, 58), Pair(23, 66), Pair(15, 66), Pair(-28, 77),
      Pair(-14, 74), Pair(-12, 88), Pair(10, 85), Pair(35, 64), Pair(8, 64), Pair(35, 64), Pair(16, 63), Pair(-5, 65),
      Pair(-34, 73), Pair(2, 72), Pair(-2, 68), Pair(-5, 57), Pair(27, 41), Pair(46, 43), Pair(92, 36), Pair(21, 42),
      Pair(-35, 75), Pair(-20, 71), Pair(-23, 74), Pair(-12, 60), Pair(-13, 43), Pair(4, 45), Pair(14, 47), Pair(-9, 47),
      Pair(-46, 65), Pair(-44, 68), Pair(-33, 63), Pair(-26, 54), Pair(-24, 47), Pair(-31, 54), Pair(-3, 41), Pair(-31, 41),
      Pair(-48, 57), Pair(-42, 54), Pair(-33, 51), Pair(-25, 45), Pair(-17, 35), Pair(-17, 36), Pair(19, 13), Pair(-13, 18),
      Pair(-46, 49), Pair(-38, 53), Pair(-20, 49), Pair(-17, 42), Pair(-12, 30), Pair(-5, 31), Pair(10, 21), Pair(-38, 30),
      Pair(-26, 46), Pair(-21, 48), Pair(-12, 52), Pair(-2, 38), Pair(2, 29), Pair(-3, 39), Pair(6, 29), Pair(-27, 24)
  },
  {
      Pair(-20, 139), Pair(-29, 157), Pair(-8, 179), Pair(34, 157), Pair(39, 158), Pair(49, 159), Pair(94, 89), Pair(15, 148),
      Pair(15, 127), Pair(-13, 159), Pair(-10, 192), Pair(-22, 215), Pair(-18, 238), Pair(26, 191), Pair(15, 178), Pair(62, 172),
      Pair(15, 131), Pair(8, 140), Pair(3, 178), Pair(11, 186), Pair(18, 203), Pair(80, 179), Pair(87, 147), Pair(88, 143),
      Pair(-3, 142), Pair(-1, 150), Pair(0, 163), Pair(-2, 185), Pair(0, 200), Pair(14, 191), Pair(23, 186), Pair(29, 176),
      Pair(-1, 130), Pair(-4, 156), Pair(-2, 151), Pair(4, 175), Pair(7, 169), Pair(7, 168), Pair(14, 159), Pair(23, 158),
      Pair(3, 115), Pair(7, 129), Pair(8, 142), Pair(5, 139), Pair(11, 147), Pair(15, 149), Pair(29, 133), Pair(24, 125),
      Pair(9, 107), Pair(12, 106), Pair(20, 104), Pair(26, 111), Pair(22, 118), Pair(37, 88), Pair(43, 60), Pair(52, 37),
      Pair(6, 105), Pair(9, 102), Pair(18, 100), Pair(20, 120), Pair(23, 101), Pair(6, 103), Pair(35, 70), Pair(20, 73)
  },
  {
      Pair(51, -119), Pair(71, -62), Pair(75, -41), Pair(-80, 12), Pair(-47, -2), Pair(15, -2), Pair(82, -16), Pair(171, -144),
      Pair(-100, -1), Pair(-47, 38), Pair(-77, 47), Pair(40, 28), Pair(-24, 53), Pair(-13, 66), Pair(12, 56), Pair(-14, 14),
      Pair(-135, 17), Pair(8, 40), Pair(-65, 62), Pair(-95, 76), Pair(-42, 77), Pair(51, 68), Pair(6, 67), Pair(-39, 26),
      Pair(-90, 4), Pair(-95, 45), Pair(-114, 67), Pair(-168, 82), Pair(-153, 83), Pair(-113, 77), Pair(-111, 65), Pair(-154, 31),
      Pair(-92, -10), Pair(-86, 26), Pair(-130, 57), Pair(-168, 76), Pair(-161, 73), Pair(-118, 58), Pair(-124, 42), Pair(-165, 23),
      Pair(-34, -22), Pair(-9, 5), Pair(-80, 33), Pair(-98, 48), Pair(-91, 48), Pair(-87, 36), Pair(-36, 11), Pair(-55, -6),
      Pair(74, -48), Pair(22, -13), Pair(7, 2), Pair(-35, 14), Pair(-39, 18), Pair(-16, 5), Pair(38, -19), Pair(49, -43),
      Pair(68, -97), Pair(99, -71), Pair(67, -46), Pair(-46, -21), Pair(22, -48), Pair(-13, -28), Pair(72, -64), Pair(75, -101)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(16, 90), Pair(33, 89), Pair(40, 99), Pair(44, 96), Pair(47, 102), Pair(45, 109), Pair(43, 110), Pair(43, 111),
  Pair(45, 108)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-12, 2), Pair(-2, 22), Pair(7, 32), Pair(10, 46), Pair(19, 63), Pair(28, 78), Pair(34, 85), Pair(40, 93),
  Pair(40, 102), Pair(42, 100), Pair(46, 99), Pair(50, 100), Pair(44, 108), Pair(80, 85)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(1, 39), Pair(11, 62), Pair(17, 63), Pair(22, 68), Pair(21, 76), Pair(28, 81), Pair(32, 86), Pair(39, 87),
  Pair(40, 99), Pair(43, 104), Pair(46, 106), Pair(47, 110), Pair(47, 115), Pair(51, 119), Pair(46, 114)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-3, 30), Pair(-12, 67), Pair(-24, 148), Pair(-21, 164), Pair(-18, 167), Pair(-15, 176), Pair(-11, 183), Pair(-12, 208),
  Pair(-10, 217), Pair(-7, 221), Pair(-6, 234), Pair(-6, 243), Pair(-5, 253), Pair(-4, 262), Pair(-3, 268), Pair(-2, 275),
  Pair(1, 280), Pair(-2, 292), Pair(2, 300), Pair(4, 300), Pair(17, 297), Pair(20, 298), Pair(22, 301), Pair(29, 299),
  Pair(53, 277), Pair(119, 255), Pair(125, 250), Pair(244, 198)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-18, -8), Pair(-24, 1), Pair(-16, 29), Pair(9, 60), Pair(0, 134), Pair(39, 185), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(1, -9), Pair(2, 4), Pair(22, 20), Pair(48, 73), Pair(132, 252), Pair(0, 515), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-24, -51), Pair(-10, -44), Pair(-18, -43), Pair(-11, -27), Pair(-20, -25), Pair(-21, -42), Pair(-25, -40), Pair(-27, -60)
};

constexpr FileTable<ScorePair> kRookOnOpenFileBonus = {
  Pair(32, -5), Pair(26, -7), Pair(22, 2), Pair(21, 8), Pair(30, 12), Pair(46, -5), Pair(59, -8), Pair(131, -25)
};

constexpr ScorePair kTempoBonus = Pair(24, 28);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H