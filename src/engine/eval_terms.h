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
  Pair(102, 161), Pair(327, 297), Pair(362, 319), Pair(451, 694), Pair(996, 1175), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(34, 71), Pair(61, 41), Pair(34, 44), Pair(74, -31), Pair(46, -31), Pair(30, -8), Pair(-50, 45), Pair(-78, 69),
      Pair(10, 47), Pair(24, 44), Pair(59, -10), Pair(60, -58), Pair(72, -64), Pair(121, -34), Pair(82, 16), Pair(45, 18),
      Pair(-15, 22), Pair(5, 8), Pair(6, -15), Pair(15, -42), Pair(40, -44), Pair(39, -31), Pair(38, -7), Pair(19, -13),
      Pair(-29, -1), Pair(-9, -1), Pair(-8, -22), Pair(12, -34), Pair(14, -34), Pair(20, -28), Pair(21, -17), Pair(2, -29),
      Pair(-25, -6), Pair(-8, -4), Pair(-6, -20), Pair(0, -22), Pair(16, -22), Pair(20, -22), Pair(42, -20), Pair(11, -33),
      Pair(-29, 1), Pair(-8, 4), Pair(-16, -8), Pair(-14, -15), Pair(0, -5), Pair(32, -15), Pair(53, -14), Pair(-2, -28),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-188, -59), Pair(-156, 22), Pair(-85, 42), Pair(-49, 29), Pair(-5, 30), Pair(-82, 4), Pair(-128, 21), Pair(-133, -82),
      Pair(-35, 24), Pair(-8, 43), Pair(27, 39), Pair(52, 37), Pair(22, 28), Pair(95, 16), Pair(-22, 40), Pair(8, 2),
      Pair(-12, 33), Pair(33, 45), Pair(57, 69), Pair(66, 69), Pair(114, 50), Pair(115, 41), Pair(58, 36), Pair(18, 21),
      Pair(-14, 51), Pair(4, 66), Pair(34, 83), Pair(62, 83), Pair(34, 85), Pair(67, 80), Pair(18, 64), Pair(31, 37),
      Pair(-31, 48), Pair(-11, 57), Pair(12, 84), Pair(14, 83), Pair(27, 87), Pair(19, 72), Pair(17, 57), Pair(-17, 37),
      Pair(-54, 27), Pair(-24, 46), Pair(-7, 56), Pair(8, 75), Pair(23, 71), Pair(3, 48), Pair(5, 37), Pair(-29, 29),
      Pair(-63, 24), Pair(-48, 39), Pair(-29, 46), Pair(-10, 44), Pair(-10, 45), Pair(-6, 41), Pair(-24, 25), Pair(-27, 31),
      Pair(-107, 20), Pair(-47, 7), Pair(-55, 34), Pair(-36, 37), Pair(-29, 36), Pair(-19, 23), Pair(-42, 13), Pair(-68, 14)
  },
  {
      Pair(-19, 64), Pair(-49, 76), Pair(-43, 64), Pair(-95, 79), Pair(-77, 72), Pair(-62, 62), Pair(-22, 59), Pair(-45, 59),
      Pair(1, 50), Pair(25, 58), Pair(12, 60), Pair(-11, 62), Pair(27, 50), Pair(10, 54), Pair(14, 62), Pair(-2, 48),
      Pair(10, 72), Pair(34, 63), Pair(33, 63), Pair(51, 52), Pair(35, 58), Pair(76, 64), Pair(51, 60), Pair(43, 68),
      Pair(3, 66), Pair(14, 71), Pair(34, 65), Pair(49, 78), Pair(44, 71), Pair(37, 69), Pair(14, 67), Pair(4, 66),
      Pair(2, 60), Pair(7, 70), Pair(9, 76), Pair(40, 74), Pair(35, 71), Pair(11, 69), Pair(8, 66), Pair(17, 46),
      Pair(8, 61), Pair(21, 69), Pair(23, 71), Pair(17, 70), Pair(21, 75), Pair(23, 67), Pair(25, 60), Pair(29, 47),
      Pair(17, 62), Pair(25, 51), Pair(32, 45), Pair(8, 64), Pair(22, 58), Pair(34, 53), Pair(44, 55), Pair(24, 40),
      Pair(6, 52), Pair(30, 65), Pair(8, 56), Pair(1, 64), Pair(9, 63), Pair(3, 69), Pair(29, 46), Pair(26, 32)
  },
  {
      Pair(10, 57), Pair(1, 71), Pair(7, 71), Pair(3, 64), Pair(17, 54), Pair(25, 67), Pair(8, 67), Pair(-26, 71),
      Pair(-7, 61), Pair(-7, 81), Pair(16, 76), Pair(37, 59), Pair(12, 60), Pair(37, 64), Pair(8, 65), Pair(-8, 61),
      Pair(-29, 61), Pair(4, 65), Pair(2, 59), Pair(-2, 53), Pair(31, 38), Pair(41, 45), Pair(75, 40), Pair(8, 40),
      Pair(-33, 62), Pair(-20, 63), Pair(-19, 65), Pair(-12, 57), Pair(-11, 40), Pair(-1, 48), Pair(-6, 52), Pair(-23, 45),
      Pair(-44, 50), Pair(-43, 61), Pair(-31, 53), Pair(-28, 50), Pair(-24, 43), Pair(-36, 57), Pair(-18, 45), Pair(-40, 36),
      Pair(-44, 41), Pair(-42, 47), Pair(-31, 42), Pair(-28, 42), Pair(-17, 31), Pair(-19, 38), Pair(10, 14), Pair(-15, 10),
      Pair(-43, 34), Pair(-36, 44), Pair(-19, 41), Pair(-20, 39), Pair(-13, 28), Pair(-8, 34), Pair(-11, 24), Pair(-45, 22),
      Pair(-23, 38), Pair(-20, 41), Pair(-13, 45), Pair(-7, 35), Pair(-1, 27), Pair(-5, 38), Pair(-10, 30), Pair(-27, 18)
  },
  {
      Pair(-18, 144), Pair(-27, 160), Pair(-3, 180), Pair(39, 158), Pair(44, 160), Pair(50, 161), Pair(95, 93), Pair(14, 154),
      Pair(15, 127), Pair(-11, 160), Pair(-6, 194), Pair(-18, 217), Pair(-15, 241), Pair(26, 194), Pair(15, 180), Pair(60, 173),
      Pair(17, 129), Pair(12, 139), Pair(6, 179), Pair(15, 187), Pair(22, 204), Pair(82, 182), Pair(87, 148), Pair(87, 145),
      Pair(-1, 141), Pair(2, 151), Pair(5, 163), Pair(2, 187), Pair(3, 202), Pair(17, 193), Pair(25, 186), Pair(31, 175),
      Pair(3, 131), Pair(-1, 157), Pair(2, 152), Pair(7, 177), Pair(10, 169), Pair(10, 169), Pair(20, 160), Pair(26, 159),
      Pair(6, 117), Pair(10, 129), Pair(12, 143), Pair(8, 140), Pair(14, 149), Pair(17, 151), Pair(32, 135), Pair(26, 127),
      Pair(11, 112), Pair(16, 109), Pair(23, 105), Pair(27, 112), Pair(24, 121), Pair(40, 92), Pair(45, 64), Pair(51, 47),
      Pair(6, 110), Pair(8, 106), Pair(17, 105), Pair(20, 122), Pair(23, 105), Pair(9, 106), Pair(35, 75), Pair(22, 77)
  },
  {
      Pair(59, -125), Pair(78, -67), Pair(80, -45), Pair(-79, 9), Pair(-46, -4), Pair(19, -4), Pair(88, -18), Pair(185, -147),
      Pair(-90, -7), Pair(-39, 35), Pair(-71, 45), Pair(45, 27), Pair(-21, 51), Pair(-10, 65), Pair(15, 55), Pair(-10, 13),
      Pair(-126, 12), Pair(17, 37), Pair(-58, 59), Pair(-92, 74), Pair(-42, 76), Pair(50, 67), Pair(5, 67), Pair(-40, 26),
      Pair(-81, 0), Pair(-87, 42), Pair(-108, 65), Pair(-167, 80), Pair(-152, 81), Pair(-112, 76), Pair(-111, 64), Pair(-154, 31),
      Pair(-83, -13), Pair(-80, 24), Pair(-125, 55), Pair(-164, 74), Pair(-159, 72), Pair(-113, 56), Pair(-120, 41), Pair(-161, 22),
      Pair(-27, -24), Pair(-1, 2), Pair(-73, 32), Pair(-92, 46), Pair(-85, 46), Pair(-82, 34), Pair(-30, 9), Pair(-48, -8),
      Pair(82, -51), Pair(29, -14), Pair(14, 0), Pair(-29, 12), Pair(-32, 16), Pair(-8, 3), Pair(44, -21), Pair(55, -45),
      Pair(74, -99), Pair(104, -72), Pair(70, -48), Pair(-44, -23), Pair(25, -49), Pair(-8, -29), Pair(75, -65), Pair(80, -102)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(13, 103), Pair(31, 105), Pair(38, 115), Pair(41, 111), Pair(43, 117), Pair(43, 124), Pair(41, 125), Pair(40, 125),
  Pair(43, 121)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-12, 22), Pair(-1, 43), Pair(7, 54), Pair(10, 66), Pair(19, 84), Pair(27, 101), Pair(34, 106), Pair(38, 114),
  Pair(40, 123), Pair(42, 121), Pair(45, 119), Pair(50, 119), Pair(43, 129), Pair(79, 107)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(6, 37), Pair(15, 62), Pair(20, 63), Pair(23, 68), Pair(22, 76), Pair(28, 80), Pair(30, 83), Pair(33, 84),
  Pair(33, 95), Pair(36, 99), Pair(40, 100), Pair(41, 105), Pair(41, 108), Pair(45, 111), Pair(39, 108)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-1, 32), Pair(-9, 64), Pair(-22, 146), Pair(-19, 164), Pair(-18, 169), Pair(-14, 177), Pair(-10, 185), Pair(-12, 210),
  Pair(-10, 219), Pair(-7, 224), Pair(-6, 237), Pair(-6, 244), Pair(-5, 255), Pair(-4, 263), Pair(-3, 270), Pair(-2, 276),
  Pair(1, 282), Pair(-2, 294), Pair(1, 303), Pair(4, 302), Pair(17, 299), Pair(20, 301), Pair(21, 303), Pair(29, 302),
  Pair(54, 281), Pair(117, 261), Pair(119, 258), Pair(238, 205)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-19, -8), Pair(-25, 1), Pair(-17, 29), Pair(9, 59), Pair(0, 136), Pair(53, 180), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(1, -10), Pair(2, 4), Pair(22, 21), Pair(49, 72), Pair(135, 249), Pair(-39, 535), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-29, -61), Pair(-16, -46), Pair(-19, -47), Pair(-17, -29), Pair(-24, -25), Pair(-33, -41), Pair(-34, -38), Pair(-40, -60)
};

constexpr FileTable<ScorePair> kRookOnOpenFileBonus = {
  Pair(37, 10), Pair(33, 2), Pair(29, 12), Pair(32, 14), Pair(38, 17), Pair(55, -3), Pair(84, -9), Pair(144, -18)
};

constexpr FileTable<ScorePair> kRookOnSemiOpenFileBonus = {
  Pair(6, 55), Pair(11, 20), Pair(8, 22), Pair(20, 9), Pair(15, 9), Pair(24, -1), Pair(48, -3), Pair(45, 24)
};

constexpr ScorePair kTempoBonus = Pair(25, 28);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H