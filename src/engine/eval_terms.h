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
  Pair(94, 170), Pair(321, 284), Pair(370, 317), Pair(479, 689), Pair(1021, 1152), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(35, 44), Pair(50, 33), Pair(20, 35), Pair(54, -25), Pair(31, -24), Pair(23, -11), Pair(-19, 41), Pair(-53, 44),
      Pair(10, 23), Pair(2, 40), Pair(41, -17), Pair(41, -58), Pair(51, -61), Pair(90, -43), Pair(50, 18), Pair(15, 4),
      Pair(-16, -2), Pair(-10, -1), Pair(-3, -27), Pair(2, -49), Pair(30, -50), Pair(26, -46), Pair(18, -11), Pair(5, -34),
      Pair(-24, -26), Pair(-23, -12), Pair(-12, -36), Pair(7, -44), Pair(10, -46), Pair(15, -47), Pair(16, -26), Pair(2, -51),
      Pair(-24, -31), Pair(-16, -18), Pair(-9, -37), Pair(-3, -36), Pair(10, -34), Pair(9, -43), Pair(24, -31), Pair(6, -56),
      Pair(-22, -25), Pair(-16, -11), Pair(-14, -28), Pair(-17, -32), Pair(-2, -20), Pair(19, -38), Pair(31, -27), Pair(-8, -52),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-167, -26), Pair(-140, 29), Pair(-72, 45), Pair(-31, 31), Pair(6, 34), Pair(-65, 7), Pair(-120, 28), Pair(-117, -50),
      Pair(-20, 35), Pair(4, 48), Pair(35, 42), Pair(55, 39), Pair(25, 32), Pair(99, 17), Pair(-2, 45), Pair(25, 11),
      Pair(1, 40), Pair(34, 47), Pair(46, 73), Pair(59, 73), Pair(103, 55), Pair(102, 44), Pair(59, 38), Pair(27, 28),
      Pair(5, 57), Pair(9, 68), Pair(33, 84), Pair(60, 86), Pair(38, 85), Pair(64, 81), Pair(21, 68), Pair(46, 45),
      Pair(-9, 61), Pair(0, 59), Pair(14, 85), Pair(22, 84), Pair(31, 90), Pair(27, 75), Pair(37, 58), Pair(8, 56),
      Pair(-35, 41), Pair(-11, 51), Pair(-3, 58), Pair(9, 77), Pair(29, 73), Pair(10, 53), Pair(16, 45), Pair(-8, 47),
      Pair(-41, 42), Pair(-26, 49), Pair(-11, 52), Pair(8, 50), Pair(10, 49), Pair(8, 46), Pair(1, 38), Pair(-3, 53),
      Pair(-78, 45), Pair(-32, 34), Pair(-34, 45), Pair(-14, 51), Pair(-6, 52), Pair(-2, 39), Pair(-29, 42), Pair(-39, 39)
  },
  {
      Pair(-32, 68), Pair(-59, 71), Pair(-53, 63), Pair(-102, 73), Pair(-86, 70), Pair(-79, 58), Pair(-35, 58), Pair(-54, 51),
      Pair(-5, 46), Pair(15, 59), Pair(3, 61), Pair(-13, 65), Pair(19, 50), Pair(9, 56), Pair(4, 62), Pair(-15, 49),
      Pair(0, 68), Pair(22, 63), Pair(20, 71), Pair(40, 57), Pair(27, 63), Pair(64, 70), Pair(39, 62), Pair(29, 64),
      Pair(-9, 63), Pair(8, 73), Pair(25, 70), Pair(48, 87), Pair(39, 77), Pair(28, 77), Pair(11, 67), Pair(-4, 64),
      Pair(-3, 59), Pair(-4, 72), Pair(8, 81), Pair(38, 81), Pair(36, 80), Pair(4, 76), Pair(3, 68), Pair(18, 46),
      Pair(0, 58), Pair(21, 73), Pair(17, 75), Pair(16, 79), Pair(19, 82), Pair(20, 74), Pair(21, 64), Pair(24, 50),
      Pair(16, 65), Pair(16, 50), Pair(27, 52), Pair(6, 64), Pair(19, 63), Pair(28, 57), Pair(41, 55), Pair(25, 44),
      Pair(1, 52), Pair(29, 68), Pair(1, 56), Pair(-5, 62), Pair(5, 60), Pair(-1, 70), Pair(17, 50), Pair(30, 26)
  },
  {
      Pair(-9, 55), Pair(-19, 70), Pair(-17, 70), Pair(-20, 63), Pair(-4, 50), Pair(8, 62), Pair(-6, 65), Pair(-22, 61),
      Pair(-20, 59), Pair(-19, 77), Pair(3, 72), Pair(18, 59), Pair(1, 56), Pair(27, 60), Pair(8, 59), Pair(0, 51),
      Pair(-37, 57), Pair(-3, 62), Pair(-4, 56), Pair(-6, 51), Pair(29, 34), Pair(38, 40), Pair(64, 37), Pair(5, 31),
      Pair(-40, 57), Pair(-25, 60), Pair(-20, 62), Pair(-15, 55), Pair(-12, 37), Pair(-7, 46), Pair(-11, 48), Pair(-26, 38),
      Pair(-49, 46), Pair(-50, 58), Pair(-35, 50), Pair(-32, 48), Pair(-29, 41), Pair(-43, 54), Pair(-20, 41), Pair(-37, 29),
      Pair(-52, 37), Pair(-46, 43), Pair(-37, 38), Pair(-38, 41), Pair(-24, 27), Pair(-25, 32), Pair(7, 10), Pair(-20, 6),
      Pair(-51, 28), Pair(-44, 39), Pair(-25, 36), Pair(-24, 35), Pair(-17, 22), Pair(-13, 27), Pair(-9, 16), Pair(-48, 13),
      Pair(-33, 34), Pair(-27, 35), Pair(-19, 38), Pair(-14, 31), Pair(-7, 20), Pair(-12, 31), Pair(-21, 25), Pair(-28, 12)
  },
  {
      Pair(-31, 140), Pair(-38, 161), Pair(-17, 187), Pair(27, 165), Pair(28, 165), Pair(41, 163), Pair(87, 95), Pair(8, 148),
      Pair(15, 121), Pair(-14, 161), Pair(-11, 197), Pair(-26, 225), Pair(-17, 244), Pair(30, 195), Pair(24, 176), Pair(74, 161),
      Pair(15, 130), Pair(10, 146), Pair(6, 186), Pair(19, 194), Pair(23, 213), Pair(83, 187), Pair(85, 155), Pair(83, 151),
      Pair(2, 139), Pair(4, 157), Pair(8, 168), Pair(7, 193), Pair(7, 212), Pair(23, 198), Pair(30, 193), Pair(35, 177),
      Pair(5, 132), Pair(1, 159), Pair(6, 157), Pair(12, 181), Pair(16, 178), Pair(14, 178), Pair(24, 167), Pair(33, 160),
      Pair(10, 109), Pair(15, 131), Pair(15, 143), Pair(12, 145), Pair(18, 153), Pair(23, 153), Pair(38, 135), Pair(33, 126),
      Pair(15, 99), Pair(19, 100), Pair(26, 102), Pair(33, 106), Pair(31, 114), Pair(41, 91), Pair(46, 66), Pair(51, 46),
      Pair(8, 98), Pair(16, 97), Pair(21, 102), Pair(24, 113), Pair(29, 96), Pair(16, 99), Pair(28, 76), Pair(28, 65)
  },
  {
      Pair(95, -135), Pair(110, -77), Pair(111, -57), Pair(-50, -3), Pair(-7, -18), Pair(42, -16), Pair(114, -34), Pair(227, -159),
      Pair(-57, -18), Pair(4, 15), Pair(-30, 27), Pair(78, 11), Pair(19, 31), Pair(22, 49), Pair(58, 32), Pair(21, -4),
      Pair(-97, -8), Pair(53, 11), Pair(-16, 36), Pair(-43, 51), Pair(2, 54), Pair(79, 36), Pair(18, 38), Pair(-15, 0),
      Pair(-49, -24), Pair(-40, 9), Pair(-68, 36), Pair(-122, 55), Pair(-114, 52), Pair(-87, 43), Pair(-81, 23), Pair(-126, 4),
      Pair(-46, -37), Pair(-41, -4), Pair(-90, 29), Pair(-133, 49), Pair(-131, 46), Pair(-87, 26), Pair(-82, 7), Pair(-130, -7),
      Pair(-7, -43), Pair(13, -18), Pair(-51, 12), Pair(-74, 29), Pair(-70, 27), Pair(-73, 15), Pair(-29, -10), Pair(-35, -28),
      Pair(76, -63), Pair(3, -22), Pair(3, -9), Pair(-16, 0), Pair(-29, 6), Pair(-19, -5), Pair(7, -25), Pair(52, -57),
      Pair(68, -104), Pair(70, -69), Pair(65, -52), Pair(-11, -32), Pair(52, -58), Pair(-8, -30), Pair(51, -61), Pair(80, -109)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(5, 74), Pair(22, 83), Pair(35, 108), Pair(41, 119), Pair(48, 128), Pair(55, 137), Pair(64, 135), Pair(71, 131),
  Pair(77, 117)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-34, 38), Pair(-20, 43), Pair(-7, 61), Pair(1, 78), Pair(11, 89), Pair(17, 101), Pair(23, 105), Pair(27, 109),
  Pair(27, 111), Pair(33, 107), Pair(44, 101), Pair(52, 98), Pair(53, 108), Pair(64, 81)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(3, 34), Pair(12, 67), Pair(16, 71), Pair(21, 77), Pair(17, 86), Pair(23, 91), Pair(25, 99), Pair(29, 101),
  Pair(33, 105), Pair(36, 109), Pair(41, 110), Pair(41, 115), Pair(47, 117), Pair(51, 112), Pair(42, 114)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-11, -21), Pair(-4, -57), Pair(-17, 108), Pair(-14, 164), Pair(-12, 193), Pair(-9, 207), Pair(-6, 230), Pair(-5, 247),
  Pair(-1, 255), Pair(2, 259), Pair(3, 268), Pair(7, 275), Pair(9, 277), Pair(9, 286), Pair(12, 289), Pair(15, 295),
  Pair(15, 304), Pair(16, 306), Pair(26, 304), Pair(41, 295), Pair(45, 300), Pair(104, 265), Pair(87, 279), Pair(115, 254),
  Pair(219, 222), Pair(198, 208), Pair(148, 257), Pair(233, 182)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-8, 2), Pair(-15, 12), Pair(-11, 43), Pair(12, 75), Pair(10, 149), Pair(60, 193), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(-1, -9), Pair(-1, 0), Pair(21, 11), Pair(51, 58), Pair(134, 222), Pair(-154, 535), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-17, -48), Pair(1, -38), Pair(-7, -30), Pair(-4, -20), Pair(-15, -11), Pair(-18, -25), Pair(-13, -36), Pair(-18, -58)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-9, 2), Pair(-8, -19), Pair(-21, -14), Pair(-18, -23), Pair(-23, -23), Pair(-13, -11), Pair(-8, -19), Pair(-11, 7)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(32, 11), Pair(31, 3), Pair(26, 12), Pair(32, 12), Pair(36, 18), Pair(60, -3), Pair(76, -6), Pair(111, -6)
  },
  {
      Pair(4, 54), Pair(10, 20), Pair(8, 21), Pair(18, 11), Pair(14, 13), Pair(22, 1), Pair(43, -1), Pair(28, 29)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(21, -1), Pair(41, 0), Pair(17, 5),
  Pair(33, -5), Pair(53, -8), Pair(31, -7),
  Pair(46, 1), Pair(0, 0), Pair(40, 2),
  Pair(-23, 4), Pair(17, 4), Pair(-22, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-17, 9), Pair(-27, 8), Pair(-19, 12),
  Pair(-15, 10), Pair(-29, 9), Pair(-19, 14),
  Pair(-7, 0), Pair(-23, 2), Pair(-8, 2),
  Pair(8, -1), Pair(-15, -5), Pair(5, 2),
  Pair(25, -6), Pair(15, -6), Pair(16, -6),
  Pair(0, 0), Pair(-89, -49), Pair(0, 0),
  Pair(-16, -57), Pair(0, 0), Pair(-22, -54)
};

constexpr ScorePair kBishopPairBonus = Pair(25, 78);
constexpr ScorePair kTempoBonus = Pair(24, 30);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H