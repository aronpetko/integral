#ifndef INTEGRAL_TERMS_H
#define INTEGRAL_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
constexpr int kNumKingBuckets = 7;

template <typename T>
using KingBuckets = std::array<T, kNumKingBuckets>;

constexpr SquareTable<int> kKingBucketLayout = {
  6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6,
  5, 5, 5, 5, 5, 5, 5, 5,
  5, 5, 5, 5, 5, 5, 5, 5,
  4, 4, 4, 4, 4, 4, 4, 4,
  3, 3, 3, 3, 3, 3, 3, 3,
  2, 2, 2, 2, 2, 2, 2, 2,
  0, 0, 1, 1, 1, 1, 0, 0
};

template <typename T>
using PieceTable = std::array<T, kNumPieceTypes>;

template <typename T>
using PieceSquareTable = KingBuckets<KingBuckets<PieceTable<std::array<T, kSquareCount>>>>;

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
  Pair(76, 128), Pair(333, 354), Pair(366, 432), Pair(472, 814), Pair(1058, 1351), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-80, 171), Pair(-95, 157), Pair(-51, 99), Pair(-22, 40), Pair(-25, 36), Pair(57, -53), Pair(-128, -34), Pair(-182, -10),
        Pair(-13, 125), Pair(-12, 125), Pair(12, 85), Pair(32, 25), Pair(54, 31), Pair(93, 25), Pair(19, 72), Pair(-5, 96),
        Pair(-4, 60), Pair(5, 54), Pair(1, 33), Pair(17, -1), Pair(32, 3), Pair(43, -20), Pair(10, 41), Pair(-5, 41),
        Pair(-8, 46), Pair(0, 46), Pair(6, 9), Pair(8, 8), Pair(14, 1), Pair(33, -11), Pair(24, 8), Pair(7, 18),
        Pair(-15, 34), Pair(-13, 36), Pair(-11, 21), Pair(-6, 15), Pair(1, 26), Pair(8, 15), Pair(7, 15), Pair(5, 0),
        Pair(-11, 39), Pair(-4, 39), Pair(-14, 38), Pair(-6, 33), Pair(-7, 40), Pair(15, 37), Pair(18, 15), Pair(-2, -27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-195, -17), Pair(-165, 109), Pair(-127, 118), Pair(-42, 103), Pair(-17, 99), Pair(-114, 47), Pair(-125, 136), Pair(-86, -58),
        Pair(-39, 89), Pair(-38, 118), Pair(-4, 119), Pair(7, 146), Pair(-4, 132), Pair(80, 89), Pair(-9, 89), Pair(-1, 73),
        Pair(-63, 95), Pair(-26, 124), Pair(-1, 151), Pair(9, 147), Pair(30, 129), Pair(29, 153), Pair(-12, 137), Pair(-1, 116),
        Pair(-18, 101), Pair(5, 124), Pair(23, 154), Pair(22, 187), Pair(23, 169), Pair(41, 150), Pair(6, 163), Pair(14, 133),
        Pair(-22, 94), Pair(-2, 112), Pair(15, 146), Pair(16, 159), Pair(19, 163), Pair(25, 151), Pair(32, 144), Pair(-5, 113),
        Pair(-36, 59), Pair(-13, 105), Pair(-4, 119), Pair(11, 139), Pair(11, 141), Pair(4, 118), Pair(-1, 111), Pair(-18, 70),
        Pair(-54, 98), Pair(-37, 98), Pair(-24, 84), Pair(-9, 115), Pair(-15, 120), Pair(-14, 94), Pair(-23, 105), Pair(-21, 97),
        Pair(-85, 39), Pair(-30, 52), Pair(-43, 84), Pair(-23, 106), Pair(-16, 109), Pair(-11, 98), Pair(-34, 78), Pair(-75, 12)
      },
      { // Piece 2
        Pair(-54, 128), Pair(-100, 138), Pair(-131, 151), Pair(-120, 163), Pair(-100, 125), Pair(-141, 113), Pair(-51, 146), Pair(4, 135),
        Pair(-64, 136), Pair(-33, 137), Pair(-21, 117), Pair(-69, 150), Pair(-42, 112), Pair(-6, 92), Pair(-62, 179), Pair(-19, 93),
        Pair(-18, 126), Pair(-13, 133), Pair(-4, 152), Pair(-7, 109), Pair(3, 125), Pair(-1, 163), Pair(11, 132), Pair(0, 126),
        Pair(-24, 111), Pair(-1, 128), Pair(-8, 118), Pair(5, 134), Pair(-4, 126), Pair(-6, 132), Pair(-10, 127), Pair(-16, 130),
        Pair(-17, 114), Pair(-9, 107), Pair(-3, 127), Pair(-6, 124), Pair(0, 126), Pair(-6, 111), Pair(-3, 104), Pair(-9, 83),
        Pair(-11, 87), Pair(4, 114), Pair(-1, 113), Pair(-1, 127), Pair(-2, 129), Pair(2, 120), Pair(7, 99), Pair(-1, 113),
        Pair(2, 96), Pair(3, 79), Pair(8, 93), Pair(-7, 102), Pair(-3, 115), Pair(8, 87), Pair(20, 104), Pair(9, 64),
        Pair(9, 68), Pair(13, 88), Pair(-11, 96), Pair(-15, 100), Pair(-4, 93), Pair(-1, 119), Pair(6, 94), Pair(15, 75)
      },
      { // Piece 3
        Pair(22, 196), Pair(33, 196), Pair(-7, 196), Pair(-17, 219), Pair(-2, 218), Pair(-110, 217), Pair(-34, 185), Pair(66, 146),
        Pair(10, 197), Pair(0, 214), Pair(24, 200), Pair(27, 205), Pair(20, 213), Pair(77, 178), Pair(39, 216), Pair(43, 230),
        Pair(12, 173), Pair(59, 166), Pair(35, 193), Pair(58, 177), Pair(75, 166), Pair(84, 172), Pair(144, 113), Pair(70, 146),
        Pair(20, 162), Pair(39, 172), Pair(49, 166), Pair(68, 165), Pair(59, 172), Pair(60, 163), Pair(63, 161), Pair(39, 168),
        Pair(-2, 158), Pair(5, 174), Pair(5, 174), Pair(18, 162), Pair(12, 159), Pair(7, 162), Pair(45, 133), Pair(8, 142),
        Pair(-4, 133), Pair(0, 163), Pair(0, 152), Pair(7, 155), Pair(11, 149), Pair(8, 146), Pair(40, 124), Pair(11, 104),
        Pair(-27, 136), Pair(-1, 137), Pair(3, 148), Pair(10, 138), Pair(13, 136), Pair(15, 129), Pair(35, 113), Pair(-3, 64),
        Pair(6, 143), Pair(8, 145), Pair(14, 148), Pair(21, 139), Pair(19, 138), Pair(22, 148), Pair(24, 136), Pair(-15, 108)
      },
      { // Piece 4
        Pair(-46, 362), Pair(7, 324), Pair(-29, 359), Pair(-15, 381), Pair(-22, 397), Pair(15, 413), Pair(36, 212), Pair(183, 61),
        Pair(-3, 287), Pair(-35, 327), Pair(9, 307), Pair(-20, 346), Pair(-30, 365), Pair(32, 399), Pair(-70, 428), Pair(50, 310),
        Pair(1, 284), Pair(8, 304), Pair(8, 306), Pair(17, 322), Pair(19, 363), Pair(54, 322), Pair(47, 373), Pair(13, 340),
        Pair(21, 254), Pair(19, 305), Pair(21, 286), Pair(18, 315), Pair(22, 334), Pair(36, 331), Pair(41, 335), Pair(45, 310),
        Pair(22, 263), Pair(27, 292), Pair(25, 285), Pair(18, 327), Pair(25, 312), Pair(24, 296), Pair(42, 276), Pair(42, 273),
        Pair(22, 260), Pair(32, 271), Pair(30, 281), Pair(24, 280), Pair(20, 293), Pair(32, 272), Pair(52, 238), Pair(44, 230),
        Pair(25, 238), Pair(31, 234), Pair(38, 219), Pair(33, 258), Pair(35, 248), Pair(49, 187), Pair(57, 171), Pair(47, 174),
        Pair(37, 208), Pair(23, 222), Pair(30, 222), Pair(38, 231), Pair(43, 208), Pair(23, 218), Pair(20, 188), Pair(-4, 224)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, -25), Pair(19, 35), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-1, 29), Pair(2, -35)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-66, 76), Pair(-66, 65), Pair(-2, -49), Pair(-11, -57), Pair(-3, -87), Pair(16, -85), Pair(-78, 97), Pair(-84, 141),
        Pair(-6, 52), Pair(28, 40), Pair(26, 22), Pair(63, -38), Pair(77, -48), Pair(51, 31), Pair(38, 27), Pair(36, 60),
        Pair(-7, 30), Pair(-4, 26), Pair(5, 5), Pair(17, -12), Pair(24, -12), Pair(28, -21), Pair(14, 15), Pair(9, 20),
        Pair(-20, 13), Pair(-10, 18), Pair(1, -17), Pair(13, -7), Pair(15, -19), Pair(24, -29), Pair(6, -6), Pair(8, -3),
        Pair(-29, 12), Pair(-25, 12), Pair(-16, -6), Pair(-1, 5), Pair(4, -2), Pair(-5, -14), Pair(-5, 3), Pair(-2, -18),
        Pair(-25, 15), Pair(-16, 12), Pair(-18, 11), Pair(-6, -13), Pair(-4, 10), Pair(5, 3), Pair(6, 4), Pair(-10, -19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-161, -51), Pair(-90, -10), Pair(-153, 75), Pair(-97, 23), Pair(96, 6), Pair(-119, 38), Pair(-86, 29), Pair(-137, -35),
        Pair(-24, 45), Pair(-47, 43), Pair(22, 30), Pair(92, 59), Pair(0, 34), Pair(28, 6), Pair(-24, 33), Pair(14, 34),
        Pair(-17, 19), Pair(0, 31), Pair(-3, 83), Pair(53, 46), Pair(24, 19), Pair(39, 84), Pair(-16, 73), Pair(-9, 19),
        Pair(-6, 30), Pair(2, 81), Pair(39, 53), Pair(15, 95), Pair(17, 100), Pair(43, 84), Pair(28, 72), Pair(23, 74),
        Pair(-26, 46), Pair(-12, 94), Pair(17, 72), Pair(20, 83), Pair(15, 90), Pair(32, 61), Pair(30, 63), Pair(-10, 63),
        Pair(-36, 11), Pair(-2, 22), Pair(-10, 64), Pair(7, 76), Pair(15, 60), Pair(2, 43), Pair(2, 40), Pair(-22, 16),
        Pair(-43, 15), Pair(-27, -22), Pair(-24, 6), Pair(-9, 53), Pair(-14, 54), Pair(-18, 39), Pair(-19, 29), Pair(-39, 36),
        Pair(-165, 69), Pair(-43, 9), Pair(-44, 14), Pair(0, 43), Pair(-18, 38), Pair(-14, 3), Pair(-38, -27), Pair(-90, -94)
      },
      { // Piece 2
        Pair(20, 46), Pair(-35, 49), Pair(-115, 60), Pair(-201, 121), Pair(-120, 31), Pair(-151, 78), Pair(-45, 62), Pair(-95, 52),
        Pair(-48, 44), Pair(-36, 47), Pair(-33, 57), Pair(-118, 56), Pair(-34, 44), Pair(8, 56), Pair(-88, 90), Pair(-68, 53),
        Pair(-19, 52), Pair(26, 31), Pair(-2, 67), Pair(20, 29), Pair(34, 14), Pair(-29, 85), Pair(38, 48), Pair(-4, 56),
        Pair(-24, 36), Pair(0, 45), Pair(-8, 48), Pair(21, 45), Pair(3, 61), Pair(10, 62), Pair(-3, 41), Pair(-2, 57),
        Pair(-12, 64), Pair(-3, 39), Pair(-2, 49), Pair(6, 55), Pair(8, 53), Pair(-1, 36), Pair(8, 30), Pair(-14, 62),
        Pair(-16, 35), Pair(11, 34), Pair(3, 38), Pair(6, 46), Pair(2, 26), Pair(9, 35), Pair(14, 37), Pair(5, 50),
        Pair(6, -3), Pair(3, 17), Pair(14, 26), Pair(-10, 45), Pair(3, 34), Pair(9, 22), Pair(33, 31), Pair(22, 17),
        Pair(-5, 32), Pair(-1, 17), Pair(-14, 40), Pair(-5, 35), Pair(-10, 9), Pair(-7, 41), Pair(4, 26), Pair(8, 0)
      },
      { // Piece 3
        Pair(48, 71), Pair(105, 39), Pair(14, 82), Pair(22, 126), Pair(63, 64), Pair(-60, 109), Pair(80, 97), Pair(1, 57),
        Pair(32, 77), Pair(11, 86), Pair(35, 74), Pair(7, 101), Pair(50, 84), Pair(-23, 133), Pair(-12, 124), Pair(3, 100),
        Pair(17, 82), Pair(61, 52), Pair(55, 62), Pair(86, 39), Pair(34, 63), Pair(46, 98), Pair(96, 35), Pair(-27, 71),
        Pair(2, 60), Pair(41, 57), Pair(47, 35), Pair(30, 63), Pair(52, 49), Pair(33, 75), Pair(74, 42), Pair(-10, 61),
        Pair(-22, 64), Pair(-18, 60), Pair(21, 45), Pair(12, 33), Pair(-2, 54), Pair(-15, 60), Pair(15, 74), Pair(9, 24),
        Pair(-16, 45), Pair(3, 28), Pair(-28, 30), Pair(15, 17), Pair(1, 45), Pair(-8, 49), Pair(-12, 56), Pair(-29, 41),
        Pair(-32, 22), Pair(-10, 35), Pair(21, 9), Pair(1, 15), Pair(-16, 39), Pair(-16, 39), Pair(-24, 33), Pair(-17, -13),
        Pair(-11, 31), Pair(-1, 37), Pair(7, 38), Pair(5, 23), Pair(11, 34), Pair(3, 45), Pair(-6, 42), Pair(-40, 28)
      },
      { // Piece 4
        Pair(60, 62), Pair(34, 129), Pair(21, 122), Pair(100, 139), Pair(-4, 93), Pair(19, 256), Pair(5, 189), Pair(41, 133),
        Pair(17, 84), Pair(-47, 150), Pair(-10, 103), Pair(7, 128), Pair(-69, 262), Pair(-15, 190), Pair(-24, 200), Pair(68, 61),
        Pair(-20, 118), Pair(19, 98), Pair(18, 160), Pair(27, 176), Pair(28, 151), Pair(25, 182), Pair(19, 134), Pair(-3, 165),
        Pair(1, 119), Pair(22, 111), Pair(23, 88), Pair(9, 155), Pair(3, 215), Pair(38, 138), Pair(22, 134), Pair(33, 87),
        Pair(17, 63), Pair(16, 121), Pair(23, 102), Pair(11, 125), Pair(15, 131), Pair(30, 74), Pair(34, 88), Pair(-3, 118),
        Pair(-7, 76), Pair(26, 55), Pair(16, 83), Pair(22, 64), Pair(17, 53), Pair(30, 44), Pair(26, 36), Pair(11, 41),
        Pair(21, 9), Pair(32, 17), Pair(33, -1), Pair(20, 44), Pair(33, 28), Pair(31, 1), Pair(34, -38), Pair(36, -50),
        Pair(-13, 101), Pair(22, 16), Pair(15, 14), Pair(25, 15), Pair(27, -20), Pair(2, 19), Pair(-2, 9), Pair(2, 86)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, -26), Pair(49, 8), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(16, 6), Pair(15, -49)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-48, 72), Pair(-51, 66), Pair(-46, 14), Pair(2, -22), Pair(13, -30), Pair(-27, -36), Pair(-103, 34), Pair(-102, 55),
        Pair(-9, 84), Pair(-11, 81), Pair(16, 42), Pair(49, -4), Pair(63, -13), Pair(123, -23), Pair(16, 51), Pair(-33, 50),
        Pair(-4, 44), Pair(0, 38), Pair(-10, 17), Pair(14, -15), Pair(36, -17), Pair(37, -12), Pair(13, 20), Pair(-9, 19),
        Pair(-8, 21), Pair(-5, 24), Pair(0, -1), Pair(5, -7), Pair(12, -7), Pair(31, -16), Pair(21, -5), Pair(12, 7),
        Pair(-17, 17), Pair(-16, 21), Pair(-17, 10), Pair(-9, 5), Pair(5, 6), Pair(5, 3), Pair(5, -3), Pair(13, -11),
        Pair(-10, 21), Pair(-12, 27), Pair(-16, 16), Pair(-13, 19), Pair(-8, 28), Pair(12, 17), Pair(27, 3), Pair(8, -25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-179, -15), Pair(-145, 81), Pair(-123, 104), Pair(-20, 53), Pair(126, -1), Pair(47, 57), Pair(-10, 45), Pair(-166, -20),
        Pair(-35, 30), Pair(-23, 63), Pair(12, 47), Pair(64, 54), Pair(70, 55), Pair(85, -1), Pair(-49, 68), Pair(-45, 37),
        Pair(-41, 54), Pair(-7, 56), Pair(24, 76), Pair(67, 60), Pair(62, 56), Pair(80, 68), Pair(66, 22), Pair(14, 36),
        Pair(-6, 48), Pair(22, 65), Pair(51, 79), Pair(68, 87), Pair(74, 85), Pair(97, 66), Pair(55, 61), Pair(55, 25),
        Pair(-13, 46), Pair(15, 78), Pair(40, 75), Pair(48, 89), Pair(68, 82), Pair(63, 80), Pair(63, 52), Pair(24, 64),
        Pair(-36, 44), Pair(-2, 55), Pair(16, 65), Pair(26, 87), Pair(46, 69), Pair(27, 60), Pair(25, 49), Pair(6, 8),
        Pair(-48, 68), Pair(-40, 35), Pair(-18, 46), Pair(6, 65), Pair(2, 68), Pair(3, 40), Pair(-2, 40), Pair(-10, 43),
        Pair(-93, 18), Pair(-32, 11), Pair(-45, 34), Pair(-10, 43), Pair(-10, 52), Pair(-7, 48), Pair(-23, 39), Pair(-94, 47)
      },
      { // Piece 2
        Pair(-57, 83), Pair(-82, 67), Pair(-118, 99), Pair(-148, 80), Pair(-72, 69), Pair(-85, 57), Pair(-16, 86), Pair(-78, 66),
        Pair(-48, 59), Pair(-3, 56), Pair(4, 49), Pair(-20, 61), Pair(-33, 62), Pair(-12, 61), Pair(11, 63), Pair(31, -11),
        Pair(-15, 57), Pair(9, 77), Pair(19, 63), Pair(18, 49), Pair(31, 46), Pair(-1, 82), Pair(-2, 68), Pair(8, 35),
        Pair(-2, 41), Pair(6, 59), Pair(12, 48), Pair(34, 54), Pair(56, 46), Pair(23, 79), Pair(39, 44), Pair(2, 61),
        Pair(-12, 44), Pair(6, 42), Pair(16, 53), Pair(25, 60), Pair(36, 48), Pair(18, 42), Pair(29, 33), Pair(10, 47),
        Pair(0, 47), Pair(14, 50), Pair(18, 52), Pair(22, 54), Pair(13, 60), Pair(19, 49), Pair(22, 27), Pair(26, 34),
        Pair(2, 23), Pair(21, 25), Pair(16, 33), Pair(5, 47), Pair(13, 48), Pair(23, 40), Pair(29, 46), Pair(28, 17),
        Pair(24, 19), Pair(35, 12), Pair(8, 27), Pair(-2, 30), Pair(-7, 53), Pair(11, 47), Pair(16, 30), Pair(9, 15)
      },
      { // Piece 3
        Pair(42, 99), Pair(23, 114), Pair(18, 122), Pair(15, 119), Pair(47, 102), Pair(85, 109), Pair(98, 100), Pair(65, 112),
        Pair(18, 96), Pair(15, 104), Pair(35, 110), Pair(52, 103), Pair(66, 88), Pair(23, 82), Pair(12, 119), Pair(43, 75),
        Pair(26, 81), Pair(65, 74), Pair(63, 85), Pair(77, 65), Pair(80, 62), Pair(122, 63), Pair(102, 53), Pair(57, 72),
        Pair(21, 74), Pair(23, 107), Pair(53, 80), Pair(77, 72), Pair(88, 65), Pair(102, 58), Pair(90, 64), Pair(59, 57),
        Pair(-11, 72), Pair(7, 98), Pair(2, 83), Pair(21, 79), Pair(26, 75), Pair(22, 75), Pair(25, 71), Pair(30, 53),
        Pair(-12, 52), Pair(-6, 70), Pair(-4, 69), Pair(26, 50), Pair(14, 66), Pair(10, 66), Pair(31, 56), Pair(9, 26),
        Pair(-29, 57), Pair(-15, 66), Pair(0, 54), Pair(14, 49), Pair(10, 52), Pair(22, 32), Pair(12, 48), Pair(-40, 38),
        Pair(-1, 57), Pair(4, 63), Pair(12, 61), Pair(20, 51), Pair(21, 50), Pair(24, 60), Pair(18, 63), Pair(-16, 39)
      },
      { // Piece 4
        Pair(9, 154), Pair(20, 137), Pair(12, 174), Pair(29, 139), Pair(47, 148), Pair(59, 175), Pair(92, 121), Pair(99, 107),
        Pair(7, 146), Pair(-20, 184), Pair(19, 166), Pair(8, 201), Pair(-23, 240), Pair(38, 170), Pair(29, 200), Pair(85, 125),
        Pair(15, 139), Pair(10, 141), Pair(26, 139), Pair(33, 163), Pair(49, 176), Pair(71, 214), Pair(-4, 272), Pair(50, 168),
        Pair(28, 125), Pair(46, 150), Pair(35, 143), Pair(9, 216), Pair(37, 196), Pair(78, 191), Pair(79, 174), Pair(37, 191),
        Pair(17, 148), Pair(45, 125), Pair(37, 156), Pair(28, 176), Pair(39, 174), Pair(43, 161), Pair(68, 134), Pair(42, 145),
        Pair(38, 78), Pair(38, 124), Pair(44, 132), Pair(40, 131), Pair(44, 122), Pair(41, 138), Pair(45, 107), Pair(66, 58),
        Pair(33, 86), Pair(43, 93), Pair(48, 82), Pair(40, 116), Pair(43, 112), Pair(47, 78), Pair(58, 35), Pair(26, 63),
        Pair(34, 101), Pair(33, 96), Pair(28, 92), Pair(44, 84), Pair(39, 81), Pair(35, 61), Pair(2, 50), Pair(-7, 157)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, -37), Pair(36, 6), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(6, 5), Pair(0, -49)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-40, 29), Pair(-1, 5), Pair(-124, 43), Pair(-9, -26), Pair(-34, -48), Pair(-59, -16), Pair(-136, 98), Pair(-42, 53),
        Pair(-34, 68), Pair(-25, 62), Pair(21, 10), Pair(3, -7), Pair(53, -19), Pair(53, -5), Pair(60, 56), Pair(19, 56),
        Pair(-32, 43), Pair(-29, 29), Pair(-7, 8), Pair(-16, -1), Pair(16, -17), Pair(30, -14), Pair(20, 12), Pair(-36, 25),
        Pair(-28, 17), Pair(-30, 28), Pair(-15, -1), Pair(-30, 11), Pair(-6, 1), Pair(38, -15), Pair(12, 5), Pair(19, -1),
        Pair(-37, 17), Pair(-38, 21), Pair(-30, 9), Pair(-31, 16), Pair(-2, 10), Pair(7, 0), Pair(11, -7), Pair(9, -12),
        Pair(-31, 26), Pair(-21, 17), Pair(-18, 17), Pair(-21, 8), Pair(-27, 28), Pair(6, 10), Pair(18, 2), Pair(7, -20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-115, 11), Pair(-105, 25), Pair(17, 12), Pair(-9, 37), Pair(66, 19), Pair(-45, 39), Pair(-115, 8), Pair(-150, -166),
        Pair(11, 21), Pair(-38, 33), Pair(39, -9), Pair(74, 56), Pair(112, 20), Pair(64, -18), Pair(-12, 10), Pair(-17, -27),
        Pair(-19, 3), Pair(-6, 32), Pair(13, 64), Pair(91, 26), Pair(88, 34), Pair(73, 44), Pair(36, -9), Pair(-3, -5),
        Pair(-31, 44), Pair(25, 42), Pair(35, 68), Pair(51, 65), Pair(145, 28), Pair(163, 7), Pair(129, 8), Pair(16, 18),
        Pair(33, 21), Pair(-9, 46), Pair(47, 61), Pair(63, 52), Pair(73, 46), Pair(108, 29), Pair(78, 42), Pair(7, 38),
        Pair(-110, 59), Pair(-5, 47), Pair(13, 48), Pair(28, 62), Pair(72, 25), Pair(26, 42), Pair(51, 9), Pair(-5, 11),
        Pair(-30, -17), Pair(46, -17), Pair(-21, 30), Pair(-22, 53), Pair(-1, 62), Pair(-14, 31), Pair(-41, 55), Pair(14, 5),
        Pair(-209, -2), Pair(-74, -1), Pair(-98, 79), Pair(-72, 39), Pair(-33, 21), Pair(-26, 14), Pair(-61, 42), Pair(-161, -12)
      },
      { // Piece 2
        Pair(-46, -2), Pair(24, 53), Pair(-59, 37), Pair(-62, 56), Pair(-86, 64), Pair(-45, 6), Pair(-35, 86), Pair(-101, 31),
        Pair(-15, 37), Pair(7, 46), Pair(-13, 48), Pair(43, 32), Pair(-71, 48), Pair(-2, 21), Pair(-47, 28), Pair(38, 4),
        Pair(-15, 34), Pair(-15, 43), Pair(14, 19), Pair(3, 20), Pair(102, 0), Pair(84, 24), Pair(-21, 48), Pair(34, 30),
        Pair(-46, 41), Pair(-15, 27), Pair(-4, 46), Pair(5, 48), Pair(83, 23), Pair(39, 27), Pair(113, -14), Pair(17, 14),
        Pair(28, 21), Pair(-12, 34), Pair(-12, 46), Pair(0, 42), Pair(29, 40), Pair(66, 20), Pair(8, 25), Pair(49, 16),
        Pair(-6, 12), Pair(-6, 29), Pair(2, 33), Pair(13, 31), Pair(14, 41), Pair(-2, 37), Pair(-9, 30), Pair(10, 22),
        Pair(-54, 51), Pair(-3, 23), Pair(7, 15), Pair(-14, 34), Pair(-13, 40), Pair(-18, 36), Pair(-6, 24), Pair(12, -14),
        Pair(-8, 21), Pair(-86, 42), Pair(-53, 30), Pair(-61, 44), Pair(-36, 50), Pair(-8, 24), Pair(-8, -5), Pair(-36, -14)
      },
      { // Piece 3
        Pair(-22, 86), Pair(-35, 90), Pair(-67, 101), Pair(-30, 88), Pair(-25, 89), Pair(-64, 117), Pair(41, 88), Pair(17, 80),
        Pair(-21, 56), Pair(5, 55), Pair(11, 56), Pair(50, 56), Pair(16, 60), Pair(23, 49), Pair(49, 46), Pair(-7, 43),
        Pair(-48, 74), Pair(23, 54), Pair(11, 57), Pair(72, 28), Pair(-1, 48), Pair(21, 23), Pair(-12, 61), Pair(-42, 72),
        Pair(-42, 76), Pair(21, 58), Pair(-16, 73), Pair(13, 56), Pair(42, 49), Pair(61, 47), Pair(53, 33), Pair(-22, 71),
        Pair(-90, 68), Pair(-28, 65), Pair(22, 31), Pair(-39, 60), Pair(-49, 81), Pair(40, 39), Pair(72, 35), Pair(-34, 49),
        Pair(-97, 58), Pair(-66, 71), Pair(-36, 38), Pair(-65, 64), Pair(-32, 42), Pair(-49, 40), Pair(-50, 68), Pair(-50, 26),
        Pair(-101, 48), Pair(-89, 42), Pair(-55, 43), Pair(-68, 54), Pair(-48, 33), Pair(-32, 22), Pair(-44, 47), Pair(-118, 70),
        Pair(-66, 38), Pair(-42, 42), Pair(-43, 39), Pair(-40, 39), Pair(-36, 37), Pair(-19, 34), Pair(-27, 36), Pair(-82, 31)
      },
      { // Piece 4
        Pair(42, 69), Pair(95, 50), Pair(96, 27), Pair(164, 21), Pair(140, 59), Pair(121, 68), Pair(140, 49), Pair(91, 67),
        Pair(69, 38), Pair(48, 51), Pair(41, 81), Pair(96, 50), Pair(71, 81), Pair(97, 63), Pair(43, 75), Pair(89, 96),
        Pair(16, 52), Pair(46, 51), Pair(37, 74), Pair(-11, 94), Pair(76, 83), Pair(224, 93), Pair(83, 10), Pair(193, 15),
        Pair(38, 50), Pair(65, 70), Pair(35, 94), Pair(74, 102), Pair(112, 96), Pair(183, 41), Pair(132, 76), Pair(57, 72),
        Pair(12, 78), Pair(72, 60), Pair(51, 90), Pair(54, 106), Pair(58, 107), Pair(106, 69), Pair(208, -26), Pair(140, 18),
        Pair(26, 32), Pair(30, 62), Pair(68, 62), Pair(49, 68), Pair(44, 69), Pair(65, 32), Pair(75, 62), Pair(75, 35),
        Pair(48, 32), Pair(30, 40), Pair(44, 66), Pair(51, 67), Pair(44, 55), Pair(45, 14), Pair(59, 15), Pair(43, -9),
        Pair(8, 54), Pair(64, -37), Pair(48, -20), Pair(42, 35), Pair(43, 16), Pair(32, 25), Pair(92, -59), Pair(47, -100)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(46, -33), Pair(76, 1), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(21, 13), Pair(11, -38)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-28, -12), Pair(-42, 11), Pair(-116, -7), Pair(-88, -16), Pair(-52, 16), Pair(-103, 48), Pair(-186, 76), Pair(34, -9),
        Pair(5, 38), Pair(7, 16), Pair(8, -26), Pair(30, -18), Pair(38, 9), Pair(-8, -16), Pair(27, 36), Pair(37, 30),
        Pair(-55, 19), Pair(9, 5), Pair(-34, -1), Pair(-30, -7), Pair(11, -15), Pair(-11, -4), Pair(3, 6), Pair(7, -1),
        Pair(7, -8), Pair(-26, 5), Pair(-41, -2), Pair(-64, 15), Pair(31, -21), Pair(54, -38), Pair(29, -9), Pair(16, -12),
        Pair(-45, 10), Pair(-51, 12), Pair(-31, 3), Pair(-40, 22), Pair(-32, 20), Pair(19, -13), Pair(-3, -6), Pair(-18, -3),
        Pair(-8, 11), Pair(-53, 23), Pair(-40, 15), Pair(-27, 26), Pair(11, 24), Pair(33, -15), Pair(49, -14), Pair(17, -26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-177, -61), Pair(-37, -31), Pair(-88, -19), Pair(29, -54), Pair(42, 9), Pair(99, -42), Pair(16, -63), Pair(-40, -145),
        Pair(51, -51), Pair(-38, -46), Pair(11, -65), Pair(126, -17), Pair(104, -16), Pair(149, -90), Pair(13, -12), Pair(7, -44),
        Pair(-100, -11), Pair(84, -51), Pair(-4, -6), Pair(102, -4), Pair(174, -50), Pair(113, -71), Pair(-32, -29), Pair(9, 44),
        Pair(-6, -58), Pair(44, -28), Pair(-55, 25), Pair(131, -26), Pair(99, -10), Pair(117, -60), Pair(10, -14), Pair(112, -69),
        Pair(-49, -57), Pair(14, -21), Pair(26, -13), Pair(157, -43), Pair(97, -34), Pair(199, -41), Pair(137, -36), Pair(155, -70),
        Pair(-186, 16), Pair(-76, 51), Pair(6, -13), Pair(47, 13), Pair(99, 3), Pair(47, -12), Pair(-16, -24), Pair(-28, -56),
        Pair(-87, 0), Pair(54, -53), Pair(75, -20), Pair(16, -8), Pair(41, 9), Pair(27, -32), Pair(-4, -8), Pair(-66, 37),
        Pair(-63, -43), Pair(-96, -8), Pair(-85, -61), Pair(-24, -36), Pair(-74, -33), Pair(-8, -37), Pair(-7, -48), Pair(-23, -122)
      },
      { // Piece 2
        Pair(-102, 5), Pair(-61, -18), Pair(-65, -9), Pair(-98, 37), Pair(-61, 3), Pair(-15, -9), Pair(-39, -16), Pair(-19, -2),
        Pair(-81, 18), Pair(-23, 18), Pair(-67, 33), Pair(-114, -34), Pair(-11, -10), Pair(-73, 8), Pair(-10, -16), Pair(-121, -18),
        Pair(-28, 3), Pair(-52, 5), Pair(-13, 19), Pair(9, -1), Pair(7, -14), Pair(20, 26), Pair(52, -12), Pair(-12, -66),
        Pair(-36, -35), Pair(-26, -6), Pair(-16, 8), Pair(-30, -15), Pair(35, -13), Pair(32, -38), Pair(86, -46), Pair(56, -7),
        Pair(-100, 33), Pair(-11, -19), Pair(1, -20), Pair(34, -45), Pair(41, -8), Pair(131, -47), Pair(-25, 12), Pair(12, -44),
        Pair(-31, -23), Pair(-54, -14), Pair(23, -28), Pair(20, -25), Pair(20, -11), Pair(-25, 5), Pair(-33, 20), Pair(-14, -9),
        Pair(-114, 12), Pair(-95, 13), Pair(12, -52), Pair(-95, 21), Pair(-49, -7), Pair(-2, 13), Pair(-25, -8), Pair(-96, -18),
        Pair(8, -42), Pair(23, -60), Pair(1, -32), Pair(-28, -8), Pair(-35, 3), Pair(-6, -33), Pair(9, -50), Pair(-171, -42)
      },
      { // Piece 3
        Pair(16, -15), Pair(-53, 13), Pair(-70, 22), Pair(-63, 14), Pair(-35, 25), Pair(-51, 50), Pair(-55, 47), Pair(-77, 7),
        Pair(-45, -21), Pair(-45, 1), Pair(-72, -2), Pair(-40, -3), Pair(-12, 0), Pair(38, -24), Pair(80, -33), Pair(-36, -24),
        Pair(-44, -1), Pair(27, -29), Pair(22, -16), Pair(48, -3), Pair(64, -39), Pair(65, -51), Pair(41, -36), Pair(-23, -16),
        Pair(-68, -12), Pair(-74, -7), Pair(-35, -18), Pair(64, -54), Pair(63, -27), Pair(65, -41), Pair(47, -92), Pair(-60, -28),
        Pair(-105, -4), Pair(-42, -1), Pair(-79, 12), Pair(16, -13), Pair(-48, -7), Pair(-24, -7), Pair(31, -58), Pair(26, -25),
        Pair(-77, -19), Pair(-94, -15), Pair(-29, -33), Pair(-21, -43), Pair(-42, -19), Pair(57, -56), Pair(61, -56), Pair(31, -27),
        Pair(-163, -29), Pair(-109, -43), Pair(-105, -7), Pair(-64, -47), Pair(-115, -10), Pair(-2, -42), Pair(-54, -29), Pair(-55, -64),
        Pair(-116, -11), Pair(-112, -12), Pair(-70, -18), Pair(-104, -9), Pair(-75, -24), Pair(-51, -17), Pair(-60, -17), Pair(-54, -52)
      },
      { // Piece 4
        Pair(6, -103), Pair(19, -50), Pair(147, -63), Pair(80, -53), Pair(-16, -36), Pair(125, -96), Pair(84, -103), Pair(232, -136),
        Pair(130, -173), Pair(109, -124), Pair(79, -85), Pair(142, -182), Pair(70, -49), Pair(188, -179), Pair(173, -183), Pair(312, -205),
        Pair(-40, -54), Pair(-21, -36), Pair(-29, -119), Pair(78, -70), Pair(110, -78), Pair(265, -170), Pair(187, -216), Pair(319, -270),
        Pair(39, -8), Pair(25, -96), Pair(-89, -22), Pair(5, 32), Pair(139, -33), Pair(12, 16), Pair(111, -113), Pair(-43, 3),
        Pair(-50, -61), Pair(-31, -25), Pair(40, -14), Pair(10, -13), Pair(82, -136), Pair(146, -87), Pair(121, -21), Pair(0, -2),
        Pair(-19, -98), Pair(-56, -11), Pair(-17, -51), Pair(75, -1), Pair(59, -153), Pair(100, -122), Pair(52, -108), Pair(-27, -84),
        Pair(114, -178), Pair(-39, -39), Pair(-7, -49), Pair(-53, 2), Pair(1, -85), Pair(49, -79), Pair(3, -51), Pair(-72, -52),
        Pair(-90, -58), Pair(-62, -95), Pair(22, -129), Pair(-5, -53), Pair(-18, -58), Pair(-9, -145), Pair(11, -112), Pair(-9, -4)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-54, -1), Pair(74, 11), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(51, 20), Pair(40, -36)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(18, -52), Pair(-9, -53), Pair(-89, -33), Pair(-19, -35), Pair(14, -53), Pair(59, -22), Pair(50, -62), Pair(-102, -2),
        Pair(30, -7), Pair(-16, 21), Pair(-41, 5), Pair(20, -42), Pair(-58, -53), Pair(48, -28), Pair(-5, 15), Pair(-46, 20),
        Pair(-83, -7), Pair(-13, -19), Pair(-46, -24), Pair(-61, -27), Pair(-41, -37), Pair(13, -53), Pair(-37, -12), Pair(-72, -9),
        Pair(-129, 0), Pair(-52, -15), Pair(-74, -10), Pair(-20, -34), Pair(-75, -13), Pair(-3, -42), Pair(-55, -20), Pair(3, -28),
        Pair(-80, -8), Pair(-77, -14), Pair(1, -30), Pair(-15, -4), Pair(11, -8), Pair(10, -7), Pair(0, -19), Pair(6, -27),
        Pair(-35, 4), Pair(-31, 4), Pair(-11, 2), Pair(78, -41), Pair(69, -17), Pair(35, -7), Pair(50, -15), Pair(-14, -20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-113, -141), Pair(-23, -108), Pair(-130, -110), Pair(-5, -74), Pair(-4, -91), Pair(-76, -68), Pair(-48, -110), Pair(-9, -130),
        Pair(85, -84), Pair(0, -77), Pair(39, -123), Pair(34, -38), Pair(79, -66), Pair(63, -74), Pair(0, -76), Pair(-129, -89),
        Pair(63, -114), Pair(17, -52), Pair(69, -76), Pair(37, -60), Pair(149, -73), Pair(85, -57), Pair(-41, -84), Pair(23, -79),
        Pair(4, -91), Pair(-37, -65), Pair(38, -46), Pair(138, -106), Pair(151, -95), Pair(82, -56), Pair(18, -56), Pair(-45, -137),
        Pair(-90, -109), Pair(-101, -64), Pair(44, -41), Pair(106, -37), Pair(128, -57), Pair(145, -61), Pair(35, -81), Pair(113, -109),
        Pair(-39, -139), Pair(-43, -55), Pair(-8, -48), Pair(121, -48), Pair(151, -96), Pair(51, -71), Pair(43, -63), Pair(127, -158),
        Pair(3, -17), Pair(-81, -77), Pair(31, -97), Pair(-83, -41), Pair(-61, -87), Pair(13, -67), Pair(15, -19), Pair(50, -17),
        Pair(28, -143), Pair(-162, -59), Pair(16, -115), Pair(-13, -120), Pair(-102, -52), Pair(7, -39), Pair(19, -89), Pair(-7, -184)
      },
      { // Piece 2
        Pair(36, 21), Pair(-148, 18), Pair(-104, 4), Pair(-153, -14), Pair(-223, 32), Pair(-61, -10), Pair(-216, 20), Pair(-57, -39),
        Pair(-195, 56), Pair(-124, 23), Pair(-164, -2), Pair(-173, -3), Pair(19, 2), Pair(-45, 18), Pair(-164, -47), Pair(-90, -18),
        Pair(-84, -64), Pair(-121, -17), Pair(-83, -1), Pair(-153, 17), Pair(-127, -7), Pair(-40, -15), Pair(-75, -21), Pair(-57, -79),
        Pair(-117, -65), Pair(-126, -30), Pair(-106, 8), Pair(-116, -13), Pair(5, -34), Pair(-95, -10), Pair(-72, 10), Pair(-113, -82),
        Pair(-156, -118), Pair(-86, -46), Pair(-23, -40), Pair(-10, -27), Pair(4, -49), Pair(-20, -61), Pair(-98, -31), Pair(52, -49),
        Pair(-84, -24), Pair(76, -121), Pair(-108, -13), Pair(-98, -22), Pair(76, -64), Pair(85, -65), Pair(34, -75), Pair(89, -104),
        Pair(-106, -25), Pair(-106, -42), Pair(-72, -38), Pair(-151, -33), Pair(25, -65), Pair(17, -28), Pair(71, -97), Pair(-203, 38),
        Pair(-54, -60), Pair(-17, -36), Pair(-17, -47), Pair(-23, -29), Pair(-27, -26), Pair(59, -73), Pair(-27, -86), Pair(-52, -62)
      },
      { // Piece 3
        Pair(17, -63), Pair(-49, -30), Pair(-48, -23), Pair(-40, -67), Pair(-111, -52), Pair(-49, -28), Pair(-137, 8), Pair(-60, -22),
        Pair(-88, -50), Pair(-76, -66), Pair(-103, -61), Pair(-27, -61), Pair(16, -59), Pair(0, -90), Pair(34, -78), Pair(-104, -45),
        Pair(-144, -47), Pair(134, -131), Pair(-69, -75), Pair(-67, -86), Pair(23, -91), Pair(21, -62), Pair(76, -91), Pair(-40, -53),
        Pair(39, -98), Pair(54, -68), Pair(-63, -72), Pair(-27, -94), Pair(59, -104), Pair(78, -114), Pair(17, -75), Pair(29, -97),
        Pair(48, -127), Pair(22, -99), Pair(43, -91), Pair(-56, -63), Pair(18, -122), Pair(-12, -85), Pair(9, -74), Pair(-103, -59),
        Pair(-69, -59), Pair(17, -69), Pair(-125, -41), Pair(38, -99), Pair(-1, -96), Pair(50, -95), Pair(39, -78), Pair(-47, -81),
        Pair(-86, -59), Pair(27, -121), Pair(-137, -62), Pair(-50, -88), Pair(10, -99), Pair(-34, -107), Pair(154, -124), Pair(-17, -96),
        Pair(-151, -69), Pair(-66, -64), Pair(-38, -62), Pair(15, -99), Pair(50, -119), Pair(6, -98), Pair(-5, -110), Pair(83, -146)
      },
      { // Piece 4
        Pair(166, -266), Pair(-60, -163), Pair(-17, -175), Pair(85, -144), Pair(96, -171), Pair(-37, -95), Pair(-130, -90), Pair(-141, -45),
        Pair(26, -212), Pair(62, -227), Pair(-12, -196), Pair(-27, -72), Pair(-6, -200), Pair(37, -139), Pair(26, -209), Pair(-21, -148),
        Pair(-81, -146), Pair(101, -206), Pair(-61, -123), Pair(15, -131), Pair(18, -135), Pair(129, -192), Pair(130, -267), Pair(112, -220),
        Pair(9, -191), Pair(-128, -127), Pair(-23, -134), Pair(-58, -112), Pair(113, -149), Pair(104, -249), Pair(-57, -112), Pair(174, -285),
        Pair(47, -179), Pair(-9, -135), Pair(18, -56), Pair(-188, -14), Pair(-59, -92), Pair(69, -129), Pair(91, -200), Pair(78, -162),
        Pair(-46, -44), Pair(-104, -112), Pair(28, -75), Pair(11, -208), Pair(-2, -90), Pair(126, -79), Pair(87, -176), Pair(77, -149),
        Pair(24, -196), Pair(-57, -66), Pair(-83, -120), Pair(126, -211), Pair(6, -194), Pair(-48, -192), Pair(27, -235), Pair(-12, -98),
        Pair(-51, -147), Pair(-37, -168), Pair(4, -192), Pair(23, -230), Pair(7, -280), Pair(111, -224), Pair(-20, -123), Pair(-24, -183)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-109, 27), Pair(60, 39), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(49, 31), Pair(24, -21)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 72), Pair(34, -22), Pair(43, 132), Pair(73, 72), Pair(44, 91), Pair(-10, -39), Pair(-40, -24), Pair(-12, -10),
        Pair(-43, 39), Pair(-88, 9), Pair(60, 15), Pair(-36, 103), Pair(-74, 29), Pair(17, -59), Pair(-96, 51), Pair(41, 30),
        Pair(14, 0), Pair(-33, -19), Pair(-37, 43), Pair(-75, 8), Pair(-174, -5), Pair(-62, -101), Pair(-2, -6), Pair(17, -34),
        Pair(-86, -63), Pair(-96, -35), Pair(-6, -35), Pair(-11, -10), Pair(-90, -40), Pair(-22, -61), Pair(-62, -32), Pair(-76, -20),
        Pair(-96, 30), Pair(-89, -45), Pair(-71, 0), Pair(24, 44), Pair(-80, 18), Pair(-54, -5), Pair(-94, 3), Pair(129, -57),
        Pair(102, -7), Pair(-14, 35), Pair(-3, 10), Pair(11, -194), Pair(23, 44), Pair(32, 13), Pair(-70, 5), Pair(3, -94),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(6, -69), Pair(-35, -123), Pair(-48, -30), Pair(34, 10), Pair(6, -95), Pair(-2, -60), Pair(-5, -33), Pair(-9, -98),
        Pair(24, 108), Pair(-24, 62), Pair(16, -43), Pair(-77, 77), Pair(-7, -41), Pair(-4, -45), Pair(-104, -158), Pair(-59, -171),
        Pair(-19, -18), Pair(-6, -48), Pair(-44, -97), Pair(-109, -56), Pair(-96, -9), Pair(-30, -4), Pair(-41, 130), Pair(-89, -98),
        Pair(12, -67), Pair(28, 6), Pair(74, 13), Pair(8, -51), Pair(3, -92), Pair(9, -72), Pair(-4, -2), Pair(35, -89),
        Pair(36, -24), Pair(30, -47), Pair(-23, -20), Pair(78, -38), Pair(15, -47), Pair(-62, -60), Pair(33, 20), Pair(1, 13),
        Pair(36, -31), Pair(42, -8), Pair(0, -70), Pair(38, 9), Pair(63, -56), Pair(47, -5), Pair(-29, -151), Pair(34, 15),
        Pair(28, 91), Pair(4, 41), Pair(-26, -111), Pair(60, -136), Pair(35, -21), Pair(56, -54), Pair(-19, -76), Pair(-26, -46),
        Pair(15, 18), Pair(13, -46), Pair(0, 47), Pair(19, 87), Pair(-29, -40), Pair(-37, 34), Pair(22, -4), Pair(14, 19)
      },
      { // Piece 2
        Pair(-71, 37), Pair(-58, -2), Pair(-14, 9), Pair(-26, 46), Pair(-3, 42), Pair(31, -31), Pair(-14, 13), Pair(-19, -30),
        Pair(-32, -2), Pair(-64, 5), Pair(45, 41), Pair(-37, -39), Pair(68, 47), Pair(30, 58), Pair(-1, -15), Pair(-22, -20),
        Pair(-13, -25), Pair(-20, 22), Pair(-28, 20), Pair(-42, -39), Pair(25, 69), Pair(-6, 38), Pair(-7, 67), Pair(11, 60),
        Pair(24, 8), Pair(-61, 4), Pair(58, 3), Pair(77, 62), Pair(-27, 71), Pair(-32, 83), Pair(145, -9), Pair(-27, -25),
        Pair(-64, 32), Pair(28, 3), Pair(48, 16), Pair(-9, 68), Pair(56, 17), Pair(39, 45), Pair(-53, 5), Pair(-60, -106),
        Pair(22, 45), Pair(101, -59), Pair(51, 76), Pair(-35, -60), Pair(7, -58), Pair(83, 7), Pair(9, 5), Pair(15, 91),
        Pair(3, -58), Pair(-4, 59), Pair(86, 8), Pair(-59, -66), Pair(-63, -75), Pair(-87, 20), Pair(22, 67), Pair(23, -13),
        Pair(3, -78), Pair(53, 45), Pair(-23, -73), Pair(-89, -56), Pair(-19, -97), Pair(49, -7), Pair(-57, -99), Pair(-9, -84)
      },
      { // Piece 3
        Pair(-30, -34), Pair(20, 23), Pair(15, 23), Pair(-30, 78), Pair(17, 0), Pair(22, 60), Pair(-67, 27), Pair(-28, 36),
        Pair(-69, -4), Pair(-35, -54), Pair(26, 28), Pair(-124, 38), Pair(17, 24), Pair(-23, -12), Pair(-84, 10), Pair(-80, 62),
        Pair(65, -17), Pair(-8, -58), Pair(90, -34), Pair(-17, 6), Pair(-34, 4), Pair(-70, -14), Pair(-13, 14), Pair(-57, 0),
        Pair(71, -41), Pair(-45, -6), Pair(119, -51), Pair(102, 4), Pair(30, 4), Pair(19, -25), Pair(-101, -15), Pair(44, -47),
        Pair(-57, -22), Pair(46, 14), Pair(40, 43), Pair(24, 11), Pair(-51, 29), Pair(-74, 18), Pair(19, 31), Pair(5, -6),
        Pair(21, -39), Pair(69, -62), Pair(77, 14), Pair(27, -2), Pair(115, -55), Pair(130, 43), Pair(-38, -6), Pair(-37, -117),
        Pair(-21, -81), Pair(53, -31), Pair(164, -36), Pair(30, -1), Pair(7, -50), Pair(-8, -20), Pair(-28, -46), Pair(5, -58),
        Pair(118, -141), Pair(10, -37), Pair(28, -17), Pair(11, -19), Pair(-15, -19), Pair(149, -54), Pair(39, -154), Pair(10, 1)
      },
      { // Piece 4
        Pair(-129, -99), Pair(24, -70), Pair(-3, -9), Pair(-105, -137), Pair(-108, -97), Pair(-35, -90), Pair(28, 13), Pair(-68, -62),
        Pair(26, -89), Pair(35, -123), Pair(-43, -42), Pair(-2, -64), Pair(-38, -92), Pair(-59, -44), Pair(-9, 33), Pair(-57, -61),
        Pair(-22, -92), Pair(-15, -74), Pair(0, -9), Pair(-16, -46), Pair(-11, -118), Pair(-52, -64), Pair(-91, -61), Pair(-43, -163),
        Pair(39, -59), Pair(-2, -135), Pair(79, -55), Pair(55, -47), Pair(18, -27), Pair(55, -47), Pair(-26, -59), Pair(-42, -95),
        Pair(-32, -142), Pair(37, -35), Pair(-33, -109), Pair(-24, -18), Pair(66, -67), Pair(9, 3), Pair(48, 14), Pair(-41, -27),
        Pair(-38, -105), Pair(30, -143), Pair(60, -3), Pair(39, -56), Pair(13, 20), Pair(-26, -78), Pair(50, -20), Pair(7, -53),
        Pair(2, -67), Pair(-49, -101), Pair(0, -4), Pair(2, -28), Pair(-2, -87), Pair(-90, -71), Pair(-8, -68), Pair(-21, 5),
        Pair(-16, -82), Pair(42, 12), Pair(19, -30), Pair(23, -77), Pair(65, -61), Pair(-61, -94), Pair(-35, -130), Pair(-47, -104)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-104, 55), Pair(20, 49), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-73, 54), Pair(-56, 32)
      }
    }}
  }},
  {{ // Bucket 1
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-72, 115), Pair(-118, 124), Pair(-130, 90), Pair(-58, 74), Pair(61, 1), Pair(-81, 100), Pair(-110, -76), Pair(-179, -23),
        Pair(1, 74), Pair(12, 85), Pair(17, 42), Pair(3, -3), Pair(48, -12), Pair(77, -6), Pair(-15, 41), Pair(-25, 49),
        Pair(-12, 51), Pair(3, 31), Pair(6, 2), Pair(17, -15), Pair(35, -32), Pair(27, -23), Pair(10, 10), Pair(-22, 19),
        Pair(0, 19), Pair(-2, 37), Pair(7, 0), Pair(17, -15), Pair(20, -20), Pair(23, -16), Pair(23, -4), Pair(-4, 2),
        Pair(-4, 11), Pair(-7, 29), Pair(-5, 0), Pair(-11, 0), Pair(-12, 12), Pair(-2, -15), Pair(20, -10), Pair(-3, -10),
        Pair(1, 17), Pair(12, 28), Pair(-10, 31), Pair(-11, 20), Pair(-26, 23), Pair(4, 11), Pair(26, -13), Pair(4, -14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-197, -52), Pair(-283, 88), Pair(-151, 88), Pair(-102, 59), Pair(-62, 36), Pair(-169, 51), Pair(-75, 68), Pair(-194, -72),
        Pair(-22, 29), Pair(-14, -2), Pair(-9, 35), Pair(6, 50), Pair(-5, 39), Pair(13, 21), Pair(-97, 102), Pair(51, 34),
        Pair(-85, 53), Pair(-21, 73), Pair(0, 73), Pair(8, 59), Pair(10, 66), Pair(21, 47), Pair(-18, 78), Pair(58, 37),
        Pair(-8, 56), Pair(8, 63), Pair(15, 82), Pair(19, 86), Pair(29, 72), Pair(45, 86), Pair(5, 92), Pair(-8, 68),
        Pair(-19, 43), Pair(-25, 74), Pair(14, 79), Pair(9, 85), Pair(20, 73), Pair(32, 69), Pair(37, 22), Pair(-4, 28),
        Pair(-41, 23), Pair(-17, 59), Pair(1, 44), Pair(9, 74), Pair(3, 79), Pair(1, 46), Pair(-6, 27), Pair(-31, 23),
        Pair(-61, 20), Pair(-28, 22), Pair(-15, 25), Pair(-11, 45), Pair(-6, 39), Pair(-8, 38), Pair(-13, -1), Pair(-14, -40),
        Pair(-115, 65), Pair(-34, 8), Pair(-44, -1), Pair(-36, 70), Pair(-37, 27), Pair(-12, -14), Pair(-40, 24), Pair(-86, -4)
      },
      { // Piece 2
        Pair(-60, 45), Pair(-100, 77), Pair(-187, 120), Pair(-210, 99), Pair(-187, 50), Pair(-63, -7), Pair(-110, 86), Pair(-93, 80),
        Pair(-78, 91), Pair(-26, 44), Pair(-4, 38), Pair(-31, 30), Pair(-48, 50), Pair(10, 84), Pair(-41, 102), Pair(-4, 65),
        Pair(-10, 38), Pair(-12, 80), Pair(19, 53), Pair(-1, 34), Pair(5, 30), Pair(-30, 83), Pair(28, 41), Pair(5, 60),
        Pair(-27, 63), Pair(2, 39), Pair(-29, 79), Pair(3, 36), Pair(2, 50), Pair(9, 44), Pair(-2, 30), Pair(-9, 38),
        Pair(0, -1), Pair(-40, 43), Pair(-3, 52), Pair(3, 37), Pair(4, 50), Pair(-7, 40), Pair(8, 13), Pair(-10, -18),
        Pair(-14, 28), Pair(19, 44), Pair(0, 37), Pair(2, 49), Pair(4, 58), Pair(3, 40), Pair(5, 13), Pair(-24, 9),
        Pair(16, 14), Pair(17, 14), Pair(21, 16), Pair(-3, 43), Pair(0, 36), Pair(-5, 57), Pair(5, 31), Pair(-2, -13),
        Pair(16, -30), Pair(2, 35), Pair(-19, 40), Pair(-16, 32), Pair(-5, 48), Pair(-17, 29), Pair(-9, 21), Pair(-24, -2)
      },
      { // Piece 3
        Pair(35, 91), Pair(-7, 96), Pair(-59, 109), Pair(-27, 66), Pair(-29, 84), Pair(-40, 56), Pair(124, 130), Pair(-74, 168),
        Pair(-4, 85), Pair(-25, 105), Pair(-17, 87), Pair(1, 102), Pair(-32, 106), Pair(-53, 132), Pair(4, 89), Pair(9, 102),
        Pair(-10, 58), Pair(53, 54), Pair(-5, 83), Pair(45, 71), Pair(68, 42), Pair(3, 40), Pair(62, 47), Pair(26, 36),
        Pair(10, 45), Pair(-3, 62), Pair(4, 64), Pair(26, 62), Pair(26, 46), Pair(24, 54), Pair(11, 38), Pair(17, 40),
        Pair(-25, 46), Pair(-15, 61), Pair(-32, 58), Pair(-19, 79), Pair(-22, 56), Pair(-20, 35), Pair(12, -3), Pair(-6, -5),
        Pair(-36, 45), Pair(-21, 32), Pair(-22, 37), Pair(-40, 47), Pair(-18, 51), Pair(-5, 18), Pair(-9, 8), Pair(-6, 2),
        Pair(-55, 44), Pair(-44, 32), Pair(-29, 38), Pair(-33, 39), Pair(-25, 22), Pair(-19, 6), Pair(-17, 2), Pair(-41, 12),
        Pair(-19, 24), Pair(-28, 25), Pair(-26, 44), Pair(-11, 31), Pair(-11, 22), Pair(-8, -5), Pair(-10, -10), Pair(2, -12)
      },
      { // Piece 4
        Pair(-128, 176), Pair(-96, 228), Pair(-101, 254), Pair(12, 185), Pair(-28, 176), Pair(20, 99), Pair(-12, 50), Pair(90, 70),
        Pair(-36, 39), Pair(-63, 69), Pair(-38, 116), Pair(-93, 175), Pair(-99, 173), Pair(-52, 136), Pair(-130, 202), Pair(2, 77),
        Pair(-49, 70), Pair(-16, 70), Pair(-43, 70), Pair(-26, 125), Pair(-13, 120), Pair(-51, 202), Pair(19, 104), Pair(-19, 118),
        Pair(-17, 24), Pair(-27, 97), Pair(-46, 104), Pair(-31, 105), Pair(-32, 128), Pair(-12, 114), Pair(2, 109), Pair(-8, 109),
        Pair(-27, 20), Pair(-35, 86), Pair(-30, 102), Pair(-36, 156), Pair(-26, 103), Pair(-34, 105), Pair(-20, 110), Pair(9, -8),
        Pair(-37, 7), Pair(-18, 42), Pair(-31, 94), Pair(-33, 95), Pair(-33, 90), Pair(-24, 93), Pair(-19, 62), Pair(-6, 30),
        Pair(-59, 16), Pair(-3, -42), Pair(-8, 1), Pair(-12, 31), Pair(-20, 47), Pair(-35, 17), Pair(11, -23), Pair(-25, 85),
        Pair(-15, -30), Pair(-27, -25), Pair(-19, -16), Pair(-16, 13), Pair(-35, 43), Pair(10, -90), Pair(9, -51), Pair(7, -37)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(1, 19), Pair(-65, 26), Pair(-3, -16), Pair(-45, 23), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-111, 118), Pair(-117, 127), Pair(-23, 1), Pair(-114, 8), Pair(-52, -23), Pair(-65, -78), Pair(-91, 7), Pair(-94, 42),
        Pair(6, 77), Pair(0, 63), Pair(25, 12), Pair(21, -7), Pair(1, -21), Pair(17, 12), Pair(26, 51), Pair(3, 55),
        Pair(1, 36), Pair(0, 34), Pair(7, -2), Pair(15, -12), Pair(33, -29), Pair(24, -21), Pair(9, 15), Pair(-10, 27),
        Pair(-10, 27), Pair(-6, 34), Pair(5, -10), Pair(15, -11), Pair(29, -23), Pair(16, -13), Pair(1, 19), Pair(-17, 13),
        Pair(-14, 2), Pair(-20, 25), Pair(-12, -3), Pair(-15, 7), Pair(-8, 1), Pair(-15, 9), Pair(4, 9), Pair(-20, -7),
        Pair(-10, 19), Pair(1, 27), Pair(-10, 27), Pair(-17, 16), Pair(-28, 17), Pair(-7, 16), Pair(9, 9), Pair(-11, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-180, -98), Pair(-104, 53), Pair(-177, 67), Pair(-109, 76), Pair(-95, -16), Pair(-110, -89), Pair(-141, 133), Pair(-131, -116),
        Pair(-70, 42), Pair(-60, 78), Pair(-31, 101), Pair(77, 57), Pair(-14, 36), Pair(-38, 85), Pair(-68, 86), Pair(-15, -34),
        Pair(-116, 81), Pair(-15, 65), Pair(-40, 117), Pair(4, 78), Pair(-1, 118), Pair(-3, 96), Pair(-45, 87), Pair(-55, 23),
        Pair(-24, 56), Pair(-26, 91), Pair(12, 87), Pair(-26, 106), Pair(-13, 103), Pair(26, 87), Pair(-6, 71), Pair(-19, 35),
        Pair(-36, 56), Pair(13, 40), Pair(-6, 92), Pair(-5, 91), Pair(-6, 88), Pair(3, 62), Pair(0, 93), Pair(-29, 54),
        Pair(-62, 51), Pair(-28, 72), Pair(-25, 67), Pair(-15, 100), Pair(-5, 76), Pair(-24, 68), Pair(-25, 76), Pair(-39, -9),
        Pair(-79, 103), Pair(-55, 75), Pair(-41, 57), Pair(-33, 58), Pair(-30, 54), Pair(-32, 55), Pair(-49, 94), Pair(-45, -24),
        Pair(-107, -33), Pair(-58, 45), Pair(-47, 40), Pair(-29, 25), Pair(-15, 26), Pair(-31, 18), Pair(-57, 40), Pair(-79, -19)
      },
      { // Piece 2
        Pair(-140, 124), Pair(-159, 101), Pair(-188, 55), Pair(-137, 62), Pair(-127, 31), Pair(-170, 80), Pair(72, 84), Pair(-102, 113),
        Pair(-38, 12), Pair(-47, 60), Pair(-76, 51), Pair(-120, 104), Pair(-157, 89), Pair(-38, 43), Pair(-59, 53), Pair(-83, 61),
        Pair(-35, 49), Pair(-30, 79), Pair(-42, 120), Pair(-20, 64), Pair(-6, 66), Pair(-25, 75), Pair(-20, 84), Pair(-30, 76),
        Pair(-40, 37), Pair(-38, 83), Pair(-45, 68), Pair(-26, 76), Pair(-25, 66), Pair(-55, 92), Pair(-24, 29), Pair(-43, 87),
        Pair(-38, 35), Pair(-38, 36), Pair(-22, 36), Pair(-22, 64), Pair(-14, 66), Pair(-22, 30), Pair(-15, 20), Pair(-40, 45),
        Pair(-44, 24), Pair(-1, 38), Pair(-24, 68), Pair(-22, 57), Pair(-21, 60), Pair(-15, 43), Pair(-19, 65), Pair(-19, 9),
        Pair(-2, 35), Pair(-13, 54), Pair(-6, 24), Pair(-28, 64), Pair(-27, 54), Pair(-20, 29), Pair(-10, 55), Pair(-18, 11),
        Pair(-8, 13), Pair(7, 50), Pair(-42, 71), Pair(-32, 54), Pair(-2, 28), Pair(-38, 60), Pair(-43, 25), Pair(-37, 43)
      },
      { // Piece 3
        Pair(6, 99), Pair(12, 104), Pair(-28, 123), Pair(70, 48), Pair(40, 22), Pair(-8, 155), Pair(14, 75), Pair(0, 108),
        Pair(-33, 100), Pair(-66, 106), Pair(-73, 131), Pair(36, 100), Pair(81, 48), Pair(-79, 140), Pair(-86, 118), Pair(-31, 110),
        Pair(-7, 64), Pair(49, 62), Pair(-26, 106), Pair(-53, 89), Pair(-23, 71), Pair(-68, 111), Pair(-48, 104), Pair(-51, 107),
        Pair(-16, 73), Pair(9, 51), Pair(-5, 89), Pair(-2, 89), Pair(-2, 81), Pair(31, 37), Pair(-8, 62), Pair(-5, 69),
        Pair(-34, 52), Pair(-40, 52), Pair(-46, 102), Pair(-57, 74), Pair(-25, 64), Pair(-7, 89), Pair(-24, 27), Pair(-29, 30),
        Pair(-49, 75), Pair(-35, 64), Pair(-82, 61), Pair(-50, 32), Pair(-43, 82), Pair(-69, 81), Pair(-24, 33), Pair(-49, 50),
        Pair(-74, 76), Pair(-20, 11), Pair(-54, 56), Pair(-48, 43), Pair(-42, 51), Pair(-38, 39), Pair(-72, 107), Pair(-62, 39),
        Pair(-39, 40), Pair(-39, 41), Pair(-39, 46), Pair(-26, 19), Pair(-9, 23), Pair(-39, 41), Pair(-52, 55), Pair(-37, 28)
      },
      { // Piece 4
        Pair(10, 105), Pair(16, 140), Pair(15, 93), Pair(4, 200), Pair(-24, 56), Pair(-28, 96), Pair(-38, 148), Pair(-37, 203),
        Pair(-23, 138), Pair(-53, 81), Pair(-31, 97), Pair(12, 178), Pair(-68, 37), Pair(21, 51), Pair(-5, 55), Pair(12, 64),
        Pair(-18, 167), Pair(25, 114), Pair(-18, 157), Pair(1, 96), Pair(-19, 205), Pair(-29, 204), Pair(5, 88), Pair(-7, 127),
        Pair(16, 17), Pair(1, 107), Pair(13, 62), Pair(-9, 165), Pair(24, 105), Pair(4, 214), Pair(13, 77), Pair(-4, 168),
        Pair(17, 33), Pair(4, 131), Pair(25, 78), Pair(-3, 156), Pair(-18, 181), Pair(19, 46), Pair(14, 97), Pair(0, 49),
        Pair(12, 49), Pair(28, 24), Pair(20, 74), Pair(8, 69), Pair(21, 26), Pair(16, 62), Pair(18, 100), Pair(16, 17),
        Pair(7, -47), Pair(24, -23), Pair(30, 9), Pair(9, 71), Pair(22, 41), Pair(35, -65), Pair(22, 10), Pair(21, -29),
        Pair(40, -34), Pair(14, -42), Pair(20, -104), Pair(19, 3), Pair(-5, 115), Pair(-1, -35), Pair(17, -54), Pair(54, -28)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(19, 6), Pair(-39, 7), Pair(9, -20), Pair(-35, 17), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-67, 37), Pair(-31, 41), Pair(-76, 28), Pair(-71, -17), Pair(-28, -21), Pair(-128, -29), Pair(-106, -34), Pair(-69, 30),
        Pair(-24, 79), Pair(21, 43), Pair(38, 20), Pair(-2, 16), Pair(94, -58), Pair(42, -10), Pair(-48, 59), Pair(-32, 41),
        Pair(-13, 45), Pair(-6, 31), Pair(12, -1), Pair(23, -23), Pair(12, -14), Pair(25, -16), Pair(-6, 18), Pair(-9, 16),
        Pair(-15, 21), Pair(-7, 32), Pair(11, -13), Pair(19, -16), Pair(16, -16), Pair(23, -15), Pair(14, 1), Pair(-10, 7),
        Pair(-20, 18), Pair(-14, 18), Pair(-5, -2), Pair(-24, 7), Pair(-2, -4), Pair(-18, 3), Pair(5, 3), Pair(-19, 1),
        Pair(-12, 21), Pair(7, 18), Pair(5, 4), Pair(-17, 26), Pair(-11, 23), Pair(2, 7), Pair(19, 2), Pair(-19, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-83, -146), Pair(-143, 62), Pair(-162, 96), Pair(15, 46), Pair(58, 9), Pair(-11, 17), Pair(68, -18), Pair(-122, -164),
        Pair(5, -9), Pair(-24, 15), Pair(27, 26), Pair(61, 51), Pair(59, -1), Pair(44, 22), Pair(-44, 7), Pair(65, 0),
        Pair(6, 7), Pair(45, 27), Pair(21, 78), Pair(45, 42), Pair(97, 63), Pair(10, 87), Pair(18, 25), Pair(106, -13),
        Pair(-6, 41), Pair(28, 41), Pair(44, 63), Pair(42, 55), Pair(65, 59), Pair(33, 92), Pair(13, 72), Pair(43, 41),
        Pair(-37, 68), Pair(34, 48), Pair(30, 65), Pair(43, 76), Pair(39, 60), Pair(52, 50), Pair(55, 55), Pair(24, 40),
        Pair(-49, 31), Pair(-24, 47), Pair(8, 49), Pair(-5, 84), Pair(27, 72), Pair(14, 50), Pair(4, 62), Pair(-24, 1),
        Pair(-18, 5), Pair(-37, 55), Pair(-21, 48), Pair(-8, 59), Pair(-8, 59), Pair(-7, 45), Pair(-31, 73), Pair(-66, 22),
        Pair(-124, -35), Pair(-30, 5), Pair(-66, 18), Pair(-24, 54), Pair(-11, 30), Pair(-24, 55), Pair(-40, 48), Pair(-26, -14)
      },
      { // Piece 2
        Pair(-82, 90), Pair(-57, 18), Pair(-127, 39), Pair(-177, 71), Pair(-116, 79), Pair(-236, 69), Pair(16, 40), Pair(-92, 63),
        Pair(-116, 67), Pair(10, 24), Pair(-24, 40), Pair(-32, 26), Pair(28, 2), Pair(-6, 25), Pair(-29, 38), Pair(-43, 64),
        Pair(-29, 31), Pair(30, 39), Pair(-1, 39), Pair(35, 33), Pair(30, 26), Pair(-81, 56), Pair(29, 34), Pair(-54, 59),
        Pair(-21, 40), Pair(18, 21), Pair(37, 26), Pair(19, 41), Pair(44, 37), Pair(70, 22), Pair(9, 32), Pair(-25, 65),
        Pair(-29, 59), Pair(22, -3), Pair(0, 33), Pair(-17, 39), Pair(32, 20), Pair(10, 38), Pair(38, 12), Pair(-24, 21),
        Pair(21, 8), Pair(46, 3), Pair(-1, 36), Pair(24, 30), Pair(7, 44), Pair(8, 47), Pair(-12, 36), Pair(1, 16),
        Pair(2, 31), Pair(19, 7), Pair(34, 7), Pair(5, 33), Pair(4, 39), Pair(6, 21), Pair(5, 17), Pair(4, -6),
        Pair(11, 22), Pair(9, -11), Pair(-22, 33), Pair(-10, 32), Pair(10, 33), Pair(-24, 29), Pair(5, 24), Pair(-1, 24)
      },
      { // Piece 3
        Pair(-21, 85), Pair(-93, 119), Pair(-44, 94), Pair(-32, 94), Pair(-87, 119), Pair(-64, 122), Pair(-19, 83), Pair(-22, 104),
        Pair(13, 59), Pair(-2, 78), Pair(-45, 94), Pair(5, 88), Pair(-34, 101), Pair(-3, 56), Pair(-85, 113), Pair(-17, 74),
        Pair(-23, 50), Pair(20, 40), Pair(-35, 82), Pair(32, 41), Pair(63, 45), Pair(45, 35), Pair(77, 35), Pair(1, 61),
        Pair(-28, 68), Pair(35, 33), Pair(5, 62), Pair(-36, 74), Pair(47, 38), Pair(16, 55), Pair(6, 66), Pair(2, 59),
        Pair(-50, 43), Pair(-37, 64), Pair(-33, 74), Pair(-58, 72), Pair(-2, 34), Pair(-25, 66), Pair(-54, 57), Pair(-42, 44),
        Pair(-14, 6), Pair(-38, 59), Pair(-88, 72), Pair(-44, 40), Pair(-35, 56), Pair(-17, 30), Pair(-7, 27), Pair(-25, 4),
        Pair(-107, 65), Pair(-50, 15), Pair(-72, 54), Pair(-38, 21), Pair(-29, 18), Pair(-33, 34), Pair(-62, 25), Pair(-61, 14),
        Pair(-36, 28), Pair(-34, 27), Pair(-40, 41), Pair(-27, 31), Pair(-14, 31), Pair(-38, 21), Pair(-23, -1), Pair(-24, 10)
      },
      { // Piece 4
        Pair(-57, 89), Pair(-38, 73), Pair(-14, 109), Pair(-35, 139), Pair(7, 115), Pair(-12, 146), Pair(95, 71), Pair(-39, 104),
        Pair(36, 32), Pair(-83, 193), Pair(-15, 102), Pair(-88, 232), Pair(-71, 187), Pair(-10, 107), Pair(-14, 151), Pair(-22, 141),
        Pair(54, 42), Pair(-29, 51), Pair(21, 31), Pair(81, 11), Pair(11, 124), Pair(-13, 164), Pair(-1, 138), Pair(49, 37),
        Pair(12, 55), Pair(21, 67), Pair(-2, 106), Pair(14, 117), Pair(-1, 134), Pair(40, 132), Pair(28, 92), Pair(37, 78),
        Pair(11, 62), Pair(28, 53), Pair(61, 45), Pair(20, 126), Pair(9, 143), Pair(10, 99), Pair(47, 49), Pair(15, 56),
        Pair(-19, 43), Pair(21, 48), Pair(3, 107), Pair(17, 105), Pair(41, 49), Pair(6, 122), Pair(43, 68), Pair(-6, 86),
        Pair(-46, 69), Pair(-5, 57), Pair(37, 3), Pair(44, 27), Pair(25, 60), Pair(14, 14), Pair(54, 2), Pair(19, 4),
        Pair(0, -13), Pair(61, -11), Pair(6, -38), Pair(25, -9), Pair(-38, 60), Pair(13, -46), Pair(-17, 36), Pair(38, -6)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(25, -6), Pair(-39, 7), Pair(0, -17), Pair(-28, 3), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-44, 29), Pair(36, -13), Pair(-38, 30), Pair(-9, -17), Pair(51, -92), Pair(-35, -40), Pair(-97, 64), Pair(-97, 19),
        Pair(-10, 62), Pair(3, 34), Pair(47, 24), Pair(49, -10), Pair(30, -40), Pair(2, -16), Pair(-38, 35), Pair(-48, 26),
        Pair(-9, 26), Pair(23, 13), Pair(-6, 0), Pair(-15, -16), Pair(35, -24), Pair(5, -1), Pair(-5, 25), Pair(-21, 11),
        Pair(-18, 12), Pair(-14, 23), Pair(-12, -2), Pair(5, -7), Pair(-14, -1), Pair(17, -16), Pair(27, -3), Pair(-35, 1),
        Pair(4, 3), Pair(-36, 22), Pair(-12, 0), Pair(-24, 1), Pair(-40, 5), Pair(-20, 1), Pair(0, -1), Pair(-28, 0),
        Pair(4, 16), Pair(-11, 24), Pair(-3, 4), Pair(10, -2), Pair(-57, 28), Pair(1, 4), Pair(1, 4), Pair(-33, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-58, -134), Pair(-132, -20), Pair(-173, 7), Pair(-58, -32), Pair(-68, -4), Pair(-70, -22), Pair(14, -12), Pair(7, -199),
        Pair(-26, -35), Pair(-91, -16), Pair(59, -18), Pair(24, 30), Pair(73, 25), Pair(146, -79), Pair(23, -5), Pair(-70, -47),
        Pair(80, -32), Pair(-51, 8), Pair(19, 36), Pair(65, 27), Pair(165, -13), Pair(119, -19), Pair(-31, 18), Pair(100, -6),
        Pair(68, -10), Pair(30, 26), Pair(56, 25), Pair(90, 20), Pair(68, 33), Pair(114, -4), Pair(118, -5), Pair(41, -8),
        Pair(-7, -18), Pair(32, 28), Pair(66, 28), Pair(56, 33), Pair(61, 24), Pair(68, 25), Pair(94, 24), Pair(18, -9),
        Pair(-40, 0), Pair(30, 4), Pair(15, 30), Pair(27, 41), Pair(61, 31), Pair(-8, 35), Pair(11, 15), Pair(-53, 6),
        Pair(-43, 15), Pair(-56, 12), Pair(-20, 8), Pair(12, 23), Pair(-15, 26), Pair(-17, 16), Pair(27, -6), Pair(-45, 9),
        Pair(-144, -119), Pair(-37, -1), Pair(46, 9), Pair(-30, 39), Pair(-6, 22), Pair(-13, 8), Pair(-108, 98), Pair(-244, -46)
      },
      { // Piece 2
        Pair(-104, 29), Pair(-19, -9), Pair(-190, 46), Pair(-88, 36), Pair(-137, 51), Pair(-68, 29), Pair(41, -8), Pair(-89, 85),
        Pair(46, 12), Pair(-64, 33), Pair(-59, -3), Pair(83, -20), Pair(-21, 5), Pair(-26, -5), Pair(-85, 41), Pair(-11, -4),
        Pair(5, -14), Pair(-16, 26), Pair(18, 20), Pair(-24, 5), Pair(-33, 17), Pair(-40, 13), Pair(-49, 27), Pair(110, -40),
        Pair(-63, 22), Pair(88, -11), Pair(-35, 10), Pair(22, -6), Pair(31, 21), Pair(-27, 28), Pair(-11, -4), Pair(-24, 13),
        Pair(20, -25), Pair(8, 5), Pair(7, 15), Pair(46, -1), Pair(7, 18), Pair(0, 41), Pair(98, -7), Pair(28, -27),
        Pair(9, -17), Pair(3, 7), Pair(40, 7), Pair(-11, 48), Pair(11, 12), Pair(-5, 8), Pair(41, 7), Pair(7, 4),
        Pair(1, 19), Pair(-15, -15), Pair(46, -8), Pair(46, 14), Pair(-6, 22), Pair(79, -32), Pair(-7, 15), Pair(54, -46),
        Pair(-15, -10), Pair(39, -5), Pair(-62, 6), Pair(-57, 18), Pair(13, -5), Pair(-9, -15), Pair(-60, 43), Pair(55, 49)
      },
      { // Piece 3
        Pair(-18, 37), Pair(-27, 47), Pair(-71, 68), Pair(-35, 54), Pair(-21, 59), Pair(-59, 70), Pair(-8, 45), Pair(-51, 58),
        Pair(-38, 22), Pair(-77, 33), Pair(-12, 28), Pair(25, 14), Pair(24, 20), Pair(93, -9), Pair(-27, 35), Pair(14, 14),
        Pair(-22, 27), Pair(33, 10), Pair(12, 18), Pair(10, 16), Pair(105, -20), Pair(1, -22), Pair(-61, 48), Pair(-11, 23),
        Pair(-38, 31), Pair(-89, 38), Pair(15, 12), Pair(50, 9), Pair(1, 23), Pair(110, 15), Pair(38, 20), Pair(-64, 39),
        Pair(-83, 9), Pair(-75, 48), Pair(-69, 39), Pair(-56, 16), Pair(-31, 12), Pair(43, -10), Pair(-54, 35), Pair(-24, 28),
        Pair(-79, 13), Pair(-45, 20), Pair(-112, 41), Pair(-28, 6), Pair(-17, 11), Pair(-34, -3), Pair(-31, 25), Pair(-157, 10),
        Pair(-67, -20), Pair(-29, -10), Pair(-96, -9), Pair(-24, -16), Pair(-27, -20), Pair(-7, -14), Pair(-69, -21), Pair(-16, -41),
        Pair(-106, 15), Pair(-104, 15), Pair(-55, 1), Pair(-36, -10), Pair(-69, 13), Pair(-34, -24), Pair(-37, 2), Pair(-77, 14)
      },
      { // Piece 4
        Pair(-47, 29), Pair(111, 25), Pair(29, 57), Pair(-39, 18), Pair(27, 83), Pair(116, 73), Pair(-33, 61), Pair(34, 116),
        Pair(73, -73), Pair(14, 33), Pair(23, 28), Pair(73, 17), Pair(-10, 88), Pair(-23, 53), Pair(28, -41), Pair(85, -15),
        Pair(61, 10), Pair(-120, 21), Pair(107, 47), Pair(37, 101), Pair(34, 49), Pair(98, 62), Pair(68, -56), Pair(110, -154),
        Pair(77, -19), Pair(28, 29), Pair(13, 24), Pair(61, 34), Pair(108, -1), Pair(68, 51), Pair(29, 108), Pair(30, 34),
        Pair(24, 19), Pair(-10, 56), Pair(30, 24), Pair(-41, 88), Pair(48, -22), Pair(121, -37), Pair(54, 8), Pair(67, 29),
        Pair(-74, 31), Pair(14, -17), Pair(10, -9), Pair(10, -36), Pair(70, -11), Pair(-33, 20), Pair(35, -48), Pair(111, 3),
        Pair(-120, -18), Pair(1, -89), Pair(27, -47), Pair(8, -66), Pair(45, -33), Pair(-28, -54), Pair(-48, 78), Pair(-31, -19),
        Pair(-44, -89), Pair(-60, -186), Pair(-13, -49), Pair(30, -38), Pair(-14, -2), Pair(-2, -80), Pair(-77, -154), Pair(-99, -29)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(6, 13), Pair(-13, 15), Pair(0, 0), Pair(-26, 18), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(83, -51), Pair(-148, 70), Pair(54, -40), Pair(96, -51), Pair(12, 25), Pair(79, -23), Pair(-119, 62), Pair(28, -43),
        Pair(-4, 29), Pair(-99, 53), Pair(-40, 11), Pair(-28, -19), Pair(-86, -3), Pair(-62, 32), Pair(-59, 8), Pair(37, 11),
        Pair(-69, 27), Pair(-2, 12), Pair(-58, 15), Pair(-37, -16), Pair(-57, -21), Pair(10, 23), Pair(9, 8), Pair(-27, 5),
        Pair(-44, 1), Pair(-3, 16), Pair(-36, -15), Pair(-24, -14), Pair(-40, 2), Pair(9, -25), Pair(38, -12), Pair(-62, 10),
        Pair(-56, -2), Pair(-61, 12), Pair(-12, -2), Pair(-21, 7), Pair(-51, 24), Pair(42, -11), Pair(20, 2), Pair(-71, 4),
        Pair(-10, 4), Pair(-76, 33), Pair(-38, 11), Pair(20, 11), Pair(18, -11), Pair(39, -12), Pair(13, -5), Pair(-54, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-129, -149), Pair(-30, -59), Pair(-117, -19), Pair(-10, -9), Pair(-118, -1), Pair(-105, -9), Pair(-44, -24), Pair(-37, -133),
        Pair(-107, -69), Pair(13, -38), Pair(-73, -19), Pair(-56, -53), Pair(-41, 12), Pair(110, -38), Pair(-15, -7), Pair(12, -58),
        Pair(-27, -58), Pair(-25, -25), Pair(82, -14), Pair(50, -12), Pair(33, 19), Pair(75, -32), Pair(17, -12), Pair(-73, -50),
        Pair(30, -10), Pair(-3, -5), Pair(48, -8), Pair(111, -12), Pair(96, -7), Pair(53, -9), Pair(70, -59), Pair(61, -15),
        Pair(-115, -9), Pair(0, 7), Pair(77, -2), Pair(165, -7), Pair(58, 2), Pair(78, -60), Pair(114, -65), Pair(54, -38),
        Pair(-7, -49), Pair(-7, 2), Pair(-9, 9), Pair(99, 4), Pair(109, 17), Pair(8, -9), Pair(-118, 22), Pair(-50, 4),
        Pair(-50, 16), Pair(-38, 21), Pair(-91, 3), Pair(-15, 13), Pair(49, 8), Pair(-3, 12), Pair(-60, -41), Pair(20, -27),
        Pair(-74, -89), Pair(-165, -9), Pair(187, -36), Pair(8, -47), Pair(44, -31), Pair(6, 3), Pair(-134, 32), Pair(-7, -31)
      },
      { // Piece 2
        Pair(12, -66), Pair(10, 14), Pair(-127, -7), Pair(-97, 23), Pair(-199, 59), Pair(13, 3), Pair(-46, -10), Pair(-66, -3),
        Pair(-34, -6), Pair(-7, -23), Pair(-45, 27), Pair(-31, 7), Pair(2, 23), Pair(-37, -22), Pair(-27, -22), Pair(-146, 16),
        Pair(37, -34), Pair(-47, 35), Pair(4, 1), Pair(-180, 6), Pair(-186, 7), Pair(-40, -8), Pair(56, -26), Pair(133, -60),
        Pair(-146, -8), Pair(2, -14), Pair(-60, 19), Pair(62, -17), Pair(44, -29), Pair(55, -18), Pair(9, -40), Pair(48, 0),
        Pair(59, -42), Pair(24, -14), Pair(15, -6), Pair(154, -72), Pair(88, -15), Pair(-9, -6), Pair(-88, 9), Pair(-9, 11),
        Pair(-24, -14), Pair(-37, -4), Pair(-54, 12), Pair(75, -8), Pair(91, -23), Pair(-16, -17), Pair(-7, -6), Pair(10, -30),
        Pair(-54, -17), Pair(-63, 22), Pair(-23, 6), Pair(26, -14), Pair(-36, 2), Pair(-32, 15), Pair(-16, -20), Pair(-30, -31),
        Pair(-105, 4), Pair(-65, 44), Pair(-123, -10), Pair(-33, -24), Pair(28, -6), Pair(-58, -10), Pair(29, -48), Pair(-48, -38)
      },
      { // Piece 3
        Pair(49, -36), Pair(-30, 7), Pair(-139, 52), Pair(-33, 15), Pair(-61, 16), Pair(-57, 41), Pair(-125, 49), Pair(-60, 18),
        Pair(-65, -32), Pair(-66, -10), Pair(-82, -17), Pair(-36, -20), Pair(-69, 7), Pair(-17, -47), Pair(11, -32), Pair(-25, -22),
        Pair(-44, -23), Pair(-11, -18), Pair(-16, -21), Pair(-57, -2), Pair(44, -65), Pair(121, -81), Pair(19, -44), Pair(-19, -21),
        Pair(-44, -46), Pair(-17, -32), Pair(2, -54), Pair(16, -28), Pair(-5, -37), Pair(-2, -29), Pair(-2, -20), Pair(-67, -64),
        Pair(20, -58), Pair(-52, 0), Pair(-26, -24), Pair(-53, -1), Pair(-51, -34), Pair(37, -47), Pair(-70, -23), Pair(-113, -31),
        Pair(-12, -66), Pair(-56, -58), Pair(-118, -13), Pair(-41, -29), Pair(-46, -31), Pair(-28, -45), Pair(-31, -34), Pair(-135, -3),
        Pair(-78, -64), Pair(-97, -76), Pair(10, -74), Pair(-12, -76), Pair(-29, -62), Pair(-132, -15), Pair(-26, 6), Pair(-139, -33),
        Pair(-21, -86), Pair(-105, -37), Pair(-23, -58), Pair(-30, -50), Pair(0, -66), Pair(50, -118), Pair(-62, -15), Pair(-64, -66)
      },
      { // Piece 4
        Pair(45, -31), Pair(174, -44), Pair(13, -9), Pair(62, -37), Pair(-37, -33), Pair(71, -90), Pair(-78, -19), Pair(3, -78),
        Pair(-16, -69), Pair(-91, 59), Pair(83, -54), Pair(-46, 9), Pair(78, -48), Pair(95, 24), Pair(121, -39), Pair(230, -137),
        Pair(36, -60), Pair(15, -132), Pair(-34, 38), Pair(84, -86), Pair(100, -36), Pair(65, -4), Pair(170, -106), Pair(217, -78),
        Pair(35, -65), Pair(50, -38), Pair(-21, 18), Pair(140, -48), Pair(-5, -12), Pair(78, -128), Pair(22, 41), Pair(-60, 64),
        Pair(-49, -105), Pair(102, -40), Pair(19, -50), Pair(20, 24), Pair(-101, -3), Pair(143, -24), Pair(-83, -12), Pair(-28, 59),
        Pair(-33, -64), Pair(-13, -34), Pair(83, -93), Pair(-48, 47), Pair(-26, -30), Pair(-32, 1), Pair(48, -42), Pair(-106, 13),
        Pair(-6, -133), Pair(-67, -37), Pair(-105, -82), Pair(-40, 25), Pair(9, -10), Pair(-41, -227), Pair(87, -29), Pair(-4, -86),
        Pair(53, 14), Pair(-32, -161), Pair(-168, -169), Pair(80, -164), Pair(71, -124), Pair(-139, -67), Pair(-37, -67), Pair(-7, -8)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(66, 11), Pair(21, 12), Pair(9, 12), Pair(-9, 31), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-49, -54), Pair(43, -24), Pair(4, -64), Pair(77, -78), Pair(-46, -82), Pair(-154, -63), Pair(-1, -35), Pair(-119, -8),
        Pair(-15, 10), Pair(-3, -2), Pair(-80, 18), Pair(-26, -13), Pair(-131, 8), Pair(-124, 18), Pair(69, -6), Pair(-124, 26),
        Pair(-43, 0), Pair(-14, 0), Pair(-82, -18), Pair(-121, -25), Pair(-138, -22), Pair(-34, -38), Pair(-49, -6), Pair(-80, -9),
        Pair(-121, 2), Pair(-16, -14), Pair(-33, -32), Pair(-51, -20), Pair(-80, -8), Pair(-22, -48), Pair(-30, -16), Pair(-10, -25),
        Pair(-103, -6), Pair(-84, 3), Pair(-80, -7), Pair(-61, 13), Pair(-22, 2), Pair(1, -19), Pair(-55, -3), Pair(-24, -12),
        Pair(-81, 12), Pair(-86, 24), Pair(-8, -4), Pair(-150, 34), Pair(-14, 24), Pair(12, -4), Pair(34, -11), Pair(-136, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(21, -103), Pair(-19, -13), Pair(-107, -70), Pair(14, -21), Pair(-31, -95), Pair(-97, -41), Pair(-31, -96), Pair(-60, -159),
        Pair(-98, -100), Pair(-63, -62), Pair(-162, -49), Pair(-72, -12), Pair(-109, -34), Pair(16, -75), Pair(-39, -119), Pair(-110, -66),
        Pair(-103, -96), Pair(-54, -83), Pair(-17, -27), Pair(32, -61), Pair(56, -33), Pair(54, -48), Pair(-35, -100), Pair(-125, -36),
        Pair(-35, -117), Pair(31, -53), Pair(79, -46), Pair(9, -44), Pair(124, -70), Pair(113, -87), Pair(72, -68), Pair(-87, -67),
        Pair(-65, -77), Pair(-150, -38), Pair(114, -73), Pair(30, -56), Pair(88, -71), Pair(127, -65), Pair(-46, -63), Pair(52, -67),
        Pair(-127, -59), Pair(80, -59), Pair(53, -35), Pair(100, -38), Pair(62, -22), Pair(108, -80), Pair(73, -116), Pair(93, -80),
        Pair(-11, -28), Pair(-39, -25), Pair(-40, -38), Pair(-82, -22), Pair(40, -60), Pair(50, -26), Pair(-55, -52), Pair(-85, -82),
        Pair(-45, -115), Pair(-167, -105), Pair(278, -75), Pair(39, -78), Pair(121, -89), Pair(-28, -45), Pair(70, -97), Pair(-23, -55)
      },
      { // Piece 2
        Pair(-123, 32), Pair(-106, -33), Pair(-223, 15), Pair(-165, 14), Pair(-117, 11), Pair(-83, -19), Pair(-203, 17), Pair(-85, 6),
        Pair(-66, 14), Pair(-174, 31), Pair(-138, -19), Pair(-203, 19), Pair(-244, 23), Pair(-202, -14), Pair(-255, 61), Pair(19, -7),
        Pair(-56, -5), Pair(-65, -13), Pair(-156, 8), Pair(-135, -3), Pair(-210, 9), Pair(-262, -5), Pair(-91, 18), Pair(49, -82),
        Pair(5, -63), Pair(-107, 7), Pair(-127, -13), Pair(-165, -10), Pair(-101, -12), Pair(-162, 9), Pair(-232, 10), Pair(-72, -30),
        Pair(-110, -45), Pair(-92, -18), Pair(23, -60), Pair(-45, -18), Pair(-53, -28), Pair(-73, -31), Pair(-152, -23), Pair(-48, -24),
        Pair(-96, 3), Pair(-41, -68), Pair(-10, -54), Pair(58, -70), Pair(-50, -19), Pair(-44, -36), Pair(41, -65), Pair(-42, -74),
        Pair(-99, -16), Pair(-107, -16), Pair(-79, -21), Pair(-36, -10), Pair(-116, -4), Pair(41, -31), Pair(-196, -32), Pair(-167, -98),
        Pair(-81, 63), Pair(-280, 58), Pair(-154, -15), Pair(-12, -45), Pair(81, -74), Pair(3, -77), Pair(-22, 7), Pair(-90, 82)
      },
      { // Piece 3
        Pair(-37, -55), Pair(0, -58), Pair(-11, -61), Pair(-61, -27), Pair(-90, -6), Pair(-53, -7), Pair(-94, -22), Pair(-62, -29),
        Pair(-78, -57), Pair(-101, -40), Pair(-133, -44), Pair(-3, -69), Pair(-114, -31), Pair(-58, -73), Pair(6, -86), Pair(-14, -105),
        Pair(-52, -60), Pair(20, -89), Pair(-102, -53), Pair(83, -102), Pair(-86, -63), Pair(-34, -76), Pair(-21, -81), Pair(-167, -39),
        Pair(-48, -80), Pair(-19, -77), Pair(-40, -76), Pair(98, -102), Pair(-121, -32), Pair(101, -109), Pair(-128, -60), Pair(-43, -67),
        Pair(-82, -91), Pair(85, -113), Pair(154, -130), Pair(5, -65), Pair(3, -116), Pair(89, -123), Pair(11, -96), Pair(-62, -80),
        Pair(-65, -84), Pair(-29, -48), Pair(8, -93), Pair(-94, -45), Pair(100, -113), Pair(32, -94), Pair(89, -121), Pair(-84, -50),
        Pair(-148, -87), Pair(-65, -87), Pair(24, -123), Pair(152, -125), Pair(116, -154), Pair(123, -128), Pair(57, -98), Pair(55, -118),
        Pair(-32, -143), Pair(-49, -109), Pair(-1, -132), Pair(-65, -87), Pair(25, -129), Pair(61, -88), Pair(111, -142), Pair(-49, -138)
      },
      { // Piece 4
        Pair(-110, -190), Pair(30, -123), Pair(-26, -92), Pair(-14, -82), Pair(-54, -93), Pair(-82, -92), Pair(-61, -12), Pair(-44, -99),
        Pair(5, -141), Pair(50, -108), Pair(-55, -83), Pair(45, -48), Pair(-28, -93), Pair(-39, -22), Pair(19, -108), Pair(41, -76),
        Pair(32, -89), Pair(-45, -212), Pair(-51, -97), Pair(-42, -138), Pair(-55, -95), Pair(64, -121), Pair(-9, -149), Pair(-77, -122),
        Pair(-54, -101), Pair(40, -47), Pair(-25, -125), Pair(39, -93), Pair(19, -58), Pair(-18, -164), Pair(32, -132), Pair(70, -82),
        Pair(-66, -144), Pair(-36, -73), Pair(-9, -93), Pair(9, -56), Pair(42, -28), Pair(-18, -83), Pair(5, -21), Pair(35, -134),
        Pair(66, -77), Pair(-85, -92), Pair(-28, -60), Pair(-23, -73), Pair(56, -91), Pair(-31, -120), Pair(-36, -48), Pair(111, -18),
        Pair(-33, -136), Pair(-28, -89), Pair(-19, -157), Pair(-135, -76), Pair(4, -108), Pair(-86, -180), Pair(-18, -108), Pair(-38, -110),
        Pair(-150, -194), Pair(-31, -126), Pair(42, -113), Pair(-1, -185), Pair(-11, -159), Pair(-71, -146), Pair(-81, -141), Pair(-96, -190)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(18, 27), Pair(0, 22), Pair(12, 13), Pair(-14, 35), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, -19), Pair(3, 25), Pair(36, -8), Pair(17, -88), Pair(-22, 70), Pair(-17, -33), Pair(-55, 78), Pair(5, 22),
        Pair(68, -5), Pair(4, 12), Pair(-7, 52), Pair(46, -6), Pair(-67, -52), Pair(12, -15), Pair(-34, 92), Pair(38, 55),
        Pair(-76, 53), Pair(-100, 88), Pair(160, -28), Pair(-71, 20), Pair(-60, -33), Pair(-49, 12), Pair(-50, 13), Pair(-103, 2),
        Pair(-25, -16), Pair(-60, -26), Pair(41, -5), Pair(-56, -22), Pair(-67, -47), Pair(76, -79), Pair(-59, -15), Pair(-213, 33),
        Pair(21, -55), Pair(-114, 22), Pair(4, -48), Pair(-43, -35), Pair(-35, 36), Pair(-33, -35), Pair(-154, 9), Pair(-176, 7),
        Pair(9, -18), Pair(22, -19), Pair(102, 37), Pair(-23, -29), Pair(-33, -18), Pair(48, 8), Pair(-73, 10), Pair(58, -66),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-3, -84), Pair(0, -21), Pair(3, -9), Pair(9, 28), Pair(-21, -119), Pair(-19, -219), Pair(-15, 25), Pair(2, 81),
        Pair(4, 2), Pair(-29, -119), Pair(-51, -116), Pair(-4, -17), Pair(-41, -177), Pair(8, -57), Pair(24, 60), Pair(-70, -76),
        Pair(26, -61), Pair(17, -107), Pair(43, 23), Pair(40, -107), Pair(-65, -3), Pair(52, 47), Pair(5, 23), Pair(-6, -102),
        Pair(1, -32), Pair(16, 43), Pair(4, -63), Pair(-119, 25), Pair(52, 6), Pair(-24, -39), Pair(-48, -111), Pair(-16, 46),
        Pair(15, 26), Pair(5, -23), Pair(43, -25), Pair(22, -4), Pair(66, 8), Pair(2, 56), Pair(29, 33), Pair(-21, -23),
        Pair(-19, -46), Pair(35, 70), Pair(-5, -37), Pair(89, 91), Pair(33, 48), Pair(32, 3), Pair(3, -111), Pair(9, -29),
        Pair(-29, -31), Pair(-20, 49), Pair(26, -1), Pair(-49, -24), Pair(74, 29), Pair(-18, -47), Pair(-36, -84), Pair(-22, -100),
        Pair(1, -25), Pair(-47, -12), Pair(28, 24), Pair(27, 14), Pair(-27, -106), Pair(59, 36), Pair(31, -114), Pair(-4, -8)
      },
      { // Piece 2
        Pair(-7, 67), Pair(-11, -64), Pair(-21, -66), Pair(-5, 17), Pair(-9, 61), Pair(-21, 50), Pair(-8, 78), Pair(-5, 51),
        Pair(-29, 114), Pair(57, 111), Pair(-29, -57), Pair(-17, 4), Pair(13, -9), Pair(-27, -4), Pair(-83, 89), Pair(-12, 97),
        Pair(-19, 46), Pair(33, 57), Pair(31, 55), Pair(26, 92), Pair(-29, -32), Pair(-35, 46), Pair(-12, 35), Pair(-29, 66),
        Pair(4, 76), Pair(-62, 69), Pair(-18, 97), Pair(65, 76), Pair(47, 87), Pair(-39, 74), Pair(-73, 31), Pair(-27, -40),
        Pair(-38, -40), Pair(-73, 47), Pair(29, -17), Pair(-27, -5), Pair(-66, 89), Pair(-2, 33), Pair(-10, 41), Pair(32, 128),
        Pair(-3, 24), Pair(-34, -50), Pair(-48, 26), Pair(84, 57), Pair(28, 50), Pair(72, 71), Pair(-2, 3), Pair(-3, 33),
        Pair(-8, -43), Pair(-33, 183), Pair(-77, 158), Pair(-46, 67), Pair(-60, 118), Pair(4, 84), Pair(-32, 89), Pair(-31, -85),
        Pair(0, -60), Pair(-13, -106), Pair(-50, -131), Pair(6, -115), Pair(19, 39), Pair(48, -12), Pair(13, 89), Pair(-7, -37)
      },
      { // Piece 3
        Pair(-7, -1), Pair(-23, 4), Pair(-12, -1), Pair(17, 44), Pair(-21, -41), Pair(-99, -14), Pair(-20, 2), Pair(20, 25),
        Pair(-41, -82), Pair(-8, 4), Pair(9, -41), Pair(-68, 11), Pair(29, -18), Pair(-35, -98), Pair(-24, 69), Pair(71, -24),
        Pair(-121, -69), Pair(-13, -18), Pair(-88, 15), Pair(52, -43), Pair(-12, 31), Pair(57, 9), Pair(2, -37), Pair(-43, -16),
        Pair(38, 20), Pair(29, -4), Pair(24, 32), Pair(-55, -25), Pair(-36, -48), Pair(17, -31), Pair(15, 46), Pair(-29, 0),
        Pair(4, -31), Pair(29, 34), Pair(-52, -82), Pair(33, -2), Pair(54, -16), Pair(-14, 3), Pair(-63, 40), Pair(-67, -82),
        Pair(78, -132), Pair(66, -17), Pair(41, -40), Pair(-61, -42), Pair(24, 10), Pair(83, -21), Pair(23, -4), Pair(-65, 52),
        Pair(-10, -98), Pair(-6, -96), Pair(14, -14), Pair(47, -67), Pair(59, -126), Pair(-25, -75), Pair(1, 62), Pair(15, 16),
        Pair(80, -45), Pair(-45, -107), Pair(7, -28), Pair(9, -143), Pair(14, -58), Pair(-100, -121), Pair(-2, -50), Pair(33, -79)
      },
      { // Piece 4
        Pair(-29, -54), Pair(-37, -86), Pair(-23, -44), Pair(-26, -50), Pair(-43, -37), Pair(-57, -70), Pair(-21, -19), Pair(-61, -110),
        Pair(-33, -52), Pair(2, -50), Pair(-17, 0), Pair(23, 30), Pair(91, 92), Pair(-64, -25), Pair(-87, -111), Pair(27, 52),
        Pair(-20, -53), Pair(37, 64), Pair(-50, -24), Pair(-1, -31), Pair(-106, -83), Pair(-128, -99), Pair(40, 39), Pair(18, 9),
        Pair(3, 2), Pair(-46, -61), Pair(-45, -67), Pair(70, 63), Pair(-7, -77), Pair(-50, -85), Pair(-38, -67), Pair(-18, -53),
        Pair(-13, -30), Pair(48, 27), Pair(-1, -48), Pair(72, 78), Pair(57, 86), Pair(-2, -43), Pair(-3, -23), Pair(-46, -112),
        Pair(-40, -137), Pair(-58, -107), Pair(36, 6), Pair(-7, -49), Pair(-5, -27), Pair(48, 84), Pair(38, 65), Pair(-39, -29),
        Pair(-48, -115), Pair(-20, -92), Pair(-43, -91), Pair(0, 1), Pair(-29, -21), Pair(-36, -35), Pair(12, 30), Pair(-31, -89),
        Pair(-20, -40), Pair(4, -4), Pair(18, 34), Pair(-75, -139), Pair(-29, -84), Pair(-59, -85), Pair(-21, -46), Pair(13, 26)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(-12, 76), Pair(-35, 54), Pair(-85, 66), Pair(-121, 77), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 2
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-64, 125), Pair(-41, 104), Pair(-24, 77), Pair(8, 2), Pair(-12, 20), Pair(-10, 20), Pair(-54, -81), Pair(-143, -51),
        Pair(-18, 102), Pair(9, 91), Pair(31, 58), Pair(51, 6), Pair(67, 7), Pair(79, 15), Pair(39, 43), Pair(-18, 70),
        Pair(-5, 55), Pair(5, 50), Pair(3, 21), Pair(23, -6), Pair(49, -15), Pair(46, -12), Pair(22, 17), Pair(-3, 28),
        Pair(-6, 31), Pair(4, 32), Pair(12, 5), Pair(11, -5), Pair(21, -10), Pair(34, -5), Pair(15, 8), Pair(-4, 5),
        Pair(-13, 20), Pair(-10, 28), Pair(-8, 12), Pair(0, 4), Pair(4, 9), Pair(18, 1), Pair(14, 2), Pair(-20, -6),
        Pair(-6, 25), Pair(-5, 32), Pair(-12, 24), Pair(-11, 23), Pair(-14, 40), Pair(29, 16), Pair(38, 6), Pair(-21, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-219, 20), Pair(-217, 30), Pair(-103, 64), Pair(-77, 51), Pair(5, 47), Pair(11, 86), Pair(-80, -52), Pair(-167, -98),
        Pair(-28, 38), Pair(-34, 49), Pair(13, 46), Pair(50, 65), Pair(71, 56), Pair(43, 50), Pair(-32, 47), Pair(56, 3),
        Pair(-56, 43), Pair(-2, 64), Pair(37, 78), Pair(46, 70), Pair(45, 70), Pair(114, 43), Pair(43, 63), Pair(54, 50),
        Pair(-14, 65), Pair(18, 60), Pair(41, 81), Pair(65, 93), Pair(61, 94), Pair(86, 72), Pair(42, 79), Pair(45, 56),
        Pair(-16, 54), Pair(20, 61), Pair(40, 88), Pair(37, 94), Pair(43, 90), Pair(51, 86), Pair(59, 80), Pair(27, 62),
        Pair(-34, 19), Pair(2, 45), Pair(9, 63), Pair(23, 88), Pair(35, 82), Pair(23, 55), Pair(15, 54), Pair(1, 26),
        Pair(-30, 24), Pair(-59, 89), Pair(-13, 43), Pair(-4, 55), Pair(3, 49), Pair(3, 51), Pair(-10, 47), Pair(3, 25),
        Pair(-77, 4), Pair(-30, 4), Pair(-15, 6), Pair(-26, 71), Pair(-19, 48), Pair(-3, 39), Pair(-9, 10), Pair(-9, -79)
      },
      { // Piece 2
        Pair(-70, 68), Pair(-63, 81), Pair(-148, 93), Pair(-152, 103), Pair(-73, 55), Pair(-143, 53), Pair(-4, 55), Pair(56, 29),
        Pair(-63, 66), Pair(-6, 65), Pair(-17, 65), Pair(-13, 64), Pair(-46, 54), Pair(42, 28), Pair(-87, 168), Pair(-11, 98),
        Pair(16, 33), Pair(12, 70), Pair(20, 65), Pair(-4, 61), Pair(38, 41), Pair(29, 80), Pair(28, 78), Pair(21, 40),
        Pair(-26, 66), Pair(29, 52), Pair(5, 64), Pair(38, 71), Pair(27, 56), Pair(34, 49), Pair(8, 62), Pair(16, 49),
        Pair(-13, 55), Pair(8, 41), Pair(28, 55), Pair(23, 43), Pair(32, 53), Pair(20, 45), Pair(19, 42), Pair(0, 65),
        Pair(-2, 38), Pair(26, 51), Pair(7, 60), Pair(22, 54), Pair(18, 63), Pair(27, 50), Pair(29, 35), Pair(31, 30),
        Pair(24, 42), Pair(12, 22), Pair(29, 40), Pair(9, 40), Pair(10, 47), Pair(24, 28), Pair(44, 23), Pair(27, 13),
        Pair(6, 29), Pair(26, 22), Pair(14, 26), Pair(-8, 55), Pair(0, 37), Pair(5, 37), Pair(24, 12), Pair(38, -4)
      },
      { // Piece 3
        Pair(44, 98), Pair(41, 116), Pair(3, 120), Pair(53, 100), Pair(46, 99), Pair(12, 115), Pair(33, 149), Pair(29, 94),
        Pair(30, 102), Pair(21, 108), Pair(44, 112), Pair(73, 102), Pair(68, 105), Pair(158, 62), Pair(111, 115), Pair(68, 130),
        Pair(4, 98), Pair(71, 79), Pair(63, 98), Pair(92, 71), Pair(97, 63), Pair(159, 45), Pair(152, 38), Pair(62, 68),
        Pair(14, 84), Pair(34, 86), Pair(54, 85), Pair(87, 76), Pair(78, 69), Pair(74, 63), Pair(75, 54), Pair(37, 77),
        Pair(-2, 76), Pair(11, 88), Pair(16, 90), Pair(14, 88), Pair(16, 80), Pair(28, 73), Pair(67, 49), Pair(-1, 57),
        Pair(-11, 71), Pair(-5, 71), Pair(1, 68), Pair(11, 65), Pair(5, 74), Pair(18, 59), Pair(47, 42), Pair(5, 32),
        Pair(-27, 64), Pair(-5, 59), Pair(6, 53), Pair(3, 61), Pair(15, 48), Pair(19, 44), Pair(22, 33), Pair(-11, 40),
        Pair(-1, 56), Pair(0, 59), Pair(9, 58), Pair(16, 53), Pair(18, 47), Pair(23, 46), Pair(19, 46), Pair(2, 43)
      },
      { // Piece 4
        Pair(-27, 216), Pair(-5, 201), Pair(-66, 251), Pair(32, 181), Pair(38, 189), Pair(82, 263), Pair(33, 178), Pair(146, 31),
        Pair(-40, 161), Pair(-66, 184), Pair(6, 155), Pair(2, 173), Pair(-23, 213), Pair(38, 249), Pair(-63, 266), Pair(-4, 203),
        Pair(-36, 151), Pair(-4, 147), Pair(-7, 153), Pair(13, 145), Pair(-17, 265), Pair(42, 191), Pair(57, 186), Pair(9, 156),
        Pair(-12, 112), Pair(3, 158), Pair(-14, 177), Pair(-11, 207), Pair(4, 199), Pair(39, 186), Pair(12, 222), Pair(38, 144),
        Pair(-4, 118), Pair(3, 154), Pair(-4, 166), Pair(-2, 188), Pair(-9, 196), Pair(12, 165), Pair(29, 137), Pair(21, 129),
        Pair(-20, 129), Pair(-3, 136), Pair(3, 151), Pair(-10, 165), Pair(6, 145), Pair(10, 148), Pair(25, 123), Pair(36, 76),
        Pair(-17, 124), Pair(-5, 105), Pair(10, 88), Pair(3, 118), Pair(10, 109), Pair(24, 61), Pair(35, 54), Pair(62, 4),
        Pair(2, 72), Pair(-27, 114), Pair(-8, 96), Pair(5, 104), Pair(11, 89), Pair(10, 61), Pair(-5, 72), Pair(8, 32)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(27, -26), Pair(-20, 17), Pair(-43, 36), Pair(-80, 48), Pair(-68, 46), Pair(-63, 37), Pair(-14, 7), Pair(17, -36),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(1, 31), Pair(-71, 60), Pair(76, -40), Pair(58, -73), Pair(-34, -77), Pair(64, -80), Pair(-162, 189), Pair(12, 22),
        Pair(-57, 95), Pair(9, 73), Pair(31, 17), Pair(32, -9), Pair(85, -29), Pair(64, 9), Pair(-5, 57), Pair(-3, 64),
        Pair(-10, 36), Pair(-9, 34), Pair(11, 0), Pair(16, -9), Pair(54, -10), Pair(40, -20), Pair(30, 15), Pair(6, 23),
        Pair(-22, 24), Pair(-14, 31), Pair(-9, -1), Pair(17, -11), Pair(18, -12), Pair(24, -8), Pair(20, 5), Pair(-7, 2),
        Pair(-29, 20), Pair(-30, 24), Pair(-13, 0), Pair(-4, -1), Pair(-6, 8), Pair(-3, -3), Pair(3, 0), Pair(-28, -4),
        Pair(-30, 26), Pair(-13, 20), Pair(-16, 12), Pair(-19, 20), Pair(-12, 11), Pair(13, 1), Pair(21, -2), Pair(-25, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-169, -86), Pair(7, -20), Pair(-85, 48), Pair(-80, 22), Pair(107, 2), Pair(-201, 111), Pair(-223, 34), Pair(-191, -43),
        Pair(33, 21), Pair(-49, 29), Pair(44, 17), Pair(31, 33), Pair(48, 25), Pair(134, -28), Pair(60, 15), Pair(-45, 50),
        Pair(-54, 32), Pair(-13, 53), Pair(25, 70), Pair(110, 36), Pair(57, 64), Pair(60, 54), Pair(20, 4), Pair(21, -19),
        Pair(-44, 55), Pair(31, 60), Pair(54, 63), Pair(28, 84), Pair(48, 86), Pair(108, 50), Pair(66, 37), Pair(62, 18),
        Pair(-16, 51), Pair(34, 58), Pair(19, 75), Pair(25, 80), Pair(42, 64), Pair(43, 63), Pair(75, 36), Pair(15, 45),
        Pair(-45, 22), Pair(-14, 59), Pair(5, 51), Pair(29, 59), Pair(1, 73), Pair(8, 50), Pair(7, 52), Pair(-23, 54),
        Pair(-109, 91), Pair(-61, 55), Pair(9, 38), Pair(-7, 65), Pair(-11, 41), Pair(1, 10), Pair(-1, -9), Pair(-23, 26),
        Pair(-86, 21), Pair(-55, 56), Pair(-101, 61), Pair(8, 31), Pair(-10, 21), Pair(21, 27), Pair(-29, 38), Pair(-198, 21)
      },
      { // Piece 2
        Pair(33, 41), Pair(-113, 97), Pair(-158, 40), Pair(-250, 89), Pair(-131, 34), Pair(-214, 93), Pair(-98, 49), Pair(-147, 86),
        Pair(-36, 52), Pair(-49, 56), Pair(23, 18), Pair(-63, 52), Pair(-90, 36), Pair(-76, 60), Pair(-54, 65), Pair(-40, -1),
        Pair(-21, 37), Pair(-19, 61), Pair(38, 31), Pair(33, 30), Pair(26, 49), Pair(29, 49), Pair(55, 25), Pair(8, 87),
        Pair(-36, 41), Pair(13, 20), Pair(34, 32), Pair(43, 32), Pair(23, 45), Pair(24, 32), Pair(29, 22), Pair(21, 12),
        Pair(-20, 29), Pair(3, 25), Pair(12, 25), Pair(20, 37), Pair(51, 12), Pair(19, 33), Pair(40, 23), Pair(20, 23),
        Pair(-34, 22), Pair(28, 13), Pair(18, 37), Pair(7, 37), Pair(-1, 54), Pair(26, 30), Pair(34, 10), Pair(16, 21),
        Pair(-42, 29), Pair(16, 6), Pair(46, 4), Pair(0, 41), Pair(6, 21), Pair(32, 2), Pair(34, 11), Pair(57, -39),
        Pair(15, -9), Pair(38, 40), Pair(-15, 51), Pair(4, 24), Pair(-74, 71), Pair(-18, 30), Pair(41, 16), Pair(27, -18)
      },
      { // Piece 3
        Pair(47, 50), Pair(8, 93), Pair(32, 77), Pair(-11, 104), Pair(9, 88), Pair(-32, 183), Pair(48, 54), Pair(-33, 95),
        Pair(23, 81), Pair(-2, 97), Pair(20, 80), Pair(95, 67), Pair(67, 85), Pair(61, 87), Pair(-3, 106), Pair(9, 86),
        Pair(25, 63), Pair(43, 57), Pair(2, 67), Pair(57, 51), Pair(14, 76), Pair(45, 64), Pair(70, 51), Pair(47, 51),
        Pair(-31, 83), Pair(-13, 54), Pair(-9, 74), Pair(-5, 64), Pair(30, 43), Pair(25, 69), Pair(-33, 51), Pair(-34, 71),
        Pair(-19, 47), Pair(-75, 99), Pair(-20, 66), Pair(-19, 58), Pair(-35, 69), Pair(-20, 55), Pair(-25, 58), Pair(-31, 54),
        Pair(-65, 29), Pair(-93, 76), Pair(-43, 38), Pair(-40, 60), Pair(8, 27), Pair(-37, 37), Pair(-12, 53), Pair(-59, 76),
        Pair(-38, 4), Pair(-40, 38), Pair(-38, 36), Pair(-27, 36), Pair(-12, 21), Pair(-20, 13), Pair(-47, 32), Pair(-62, 7),
        Pair(-49, 37), Pair(-34, 36), Pair(-35, 31), Pair(-26, 21), Pair(-17, 24), Pair(-21, 35), Pair(-41, 39), Pair(-30, 23)
      },
      { // Piece 4
        Pair(24, 39), Pair(32, 162), Pair(-29, 156), Pair(70, 102), Pair(-13, 88), Pair(88, 64), Pair(88, 125), Pair(13, 215),
        Pair(31, 33), Pair(-12, 101), Pair(-56, 150), Pair(38, 82), Pair(-43, 170), Pair(-39, 101), Pair(-12, 145), Pair(62, 79),
        Pair(-39, 82), Pair(65, 29), Pair(10, 119), Pair(-16, 186), Pair(65, 104), Pair(30, 165), Pair(56, 121), Pair(34, 105),
        Pair(0, 34), Pair(34, 46), Pair(39, 84), Pair(-24, 184), Pair(61, 143), Pair(44, 144), Pair(43, 107), Pair(72, 47),
        Pair(34, 49), Pair(17, 85), Pair(8, 113), Pair(10, 115), Pair(25, 124), Pair(52, 39), Pair(47, 87), Pair(27, 72),
        Pair(0, 56), Pair(30, 63), Pair(20, 106), Pair(7, 92), Pair(24, 92), Pair(23, 65), Pair(41, 63), Pair(-12, 75),
        Pair(37, 17), Pair(8, 42), Pair(33, 22), Pair(2, 66), Pair(10, 71), Pair(46, -37), Pair(7, -47), Pair(-14, 20),
        Pair(-30, 133), Pair(1, 27), Pair(3, 49), Pair(15, 27), Pair(40, -25), Pair(-11, -11), Pair(43, 5), Pair(8, -5)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(37, -34), Pair(36, -15), Pair(3, 6), Pair(-42, 27), Pair(-20, 16), Pair(-30, 16), Pair(14, -10), Pair(54, -52),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, 19), Pair(40, 11), Pair(1, -9), Pair(6, -29), Pair(15, -33), Pair(-7, -45), Pair(-53, 24), Pair(91, -36),
        Pair(-11, 72), Pair(4, 67), Pair(26, 29), Pair(45, -4), Pair(33, -2), Pair(117, -23), Pair(40, 5), Pair(-43, 50),
        Pair(-9, 41), Pair(2, 31), Pair(-7, 15), Pair(22, -12), Pair(36, -6), Pair(38, -8), Pair(13, 19), Pair(1, 20),
        Pair(-10, 25), Pair(-1, 29), Pair(7, -2), Pair(11, -9), Pair(24, -11), Pair(23, -1), Pair(18, 9), Pair(-13, 8),
        Pair(-19, 17), Pair(-13, 19), Pair(-11, 6), Pair(-3, 3), Pair(1, 6), Pair(5, 4), Pair(-1, 2), Pair(-20, -5),
        Pair(-17, 24), Pair(-10, 25), Pair(-10, 13), Pair(-20, 28), Pair(-6, 24), Pair(33, 4), Pair(36, 4), Pair(-20, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-250, 7), Pair(-179, 44), Pair(-22, 54), Pair(11, 28), Pair(141, -23), Pair(215, -5), Pair(34, -8), Pair(-169, -39),
        Pair(-11, 25), Pair(7, 23), Pair(29, 33), Pair(109, 45), Pair(80, 51), Pair(106, 15), Pair(18, 4), Pair(43, 16),
        Pair(-39, 41), Pair(5, 46), Pair(55, 66), Pair(84, 52), Pair(82, 50), Pair(128, 44), Pair(94, 28), Pair(8, 46),
        Pair(15, 42), Pair(25, 59), Pair(59, 71), Pair(91, 68), Pair(105, 62), Pair(133, 49), Pair(84, 45), Pair(79, 37),
        Pair(2, 45), Pair(29, 62), Pair(51, 69), Pair(80, 69), Pair(78, 68), Pair(90, 59), Pair(96, 45), Pair(57, 30),
        Pair(3, 36), Pair(12, 49), Pair(21, 61), Pair(46, 77), Pair(55, 72), Pair(38, 53), Pair(58, 34), Pair(13, 39),
        Pair(-27, 29), Pair(4, 30), Pair(-13, 41), Pair(11, 61), Pair(17, 50), Pair(13, 44), Pair(10, 55), Pair(3, 39),
        Pair(-160, 23), Pair(-72, 49), Pair(15, 14), Pair(-32, 74), Pair(-20, 67), Pair(-17, 49), Pair(11, 13), Pair(-193, 50)
      },
      { // Piece 2
        Pair(-31, 32), Pair(-6, 29), Pair(-100, 64), Pair(-69, 58), Pair(-70, 49), Pair(-87, 60), Pair(-17, 40), Pair(-115, 59),
        Pair(-67, 62), Pair(10, 46), Pair(-22, 46), Pair(46, 21), Pair(-37, 58), Pair(10, 43), Pair(-42, 55), Pair(-45, 48),
        Pair(4, 38), Pair(32, 34), Pair(27, 48), Pair(21, 34), Pair(87, 21), Pair(56, 32), Pair(-9, 40), Pair(21, 40),
        Pair(9, 38), Pair(38, 33), Pair(42, 38), Pair(60, 37), Pair(89, 22), Pair(59, 38), Pair(57, 31), Pair(34, 23),
        Pair(28, 9), Pair(20, 29), Pair(37, 35), Pair(36, 35), Pair(51, 33), Pair(36, 36), Pair(43, 22), Pair(31, 31),
        Pair(13, 30), Pair(35, 29), Pair(24, 38), Pair(40, 37), Pair(25, 50), Pair(35, 40), Pair(16, 52), Pair(46, 14),
        Pair(-21, 32), Pair(28, 13), Pair(18, 24), Pair(15, 31), Pair(31, 29), Pair(21, 27), Pair(41, 17), Pair(-16, 4),
        Pair(34, 6), Pair(6, 29), Pair(6, 28), Pair(2, 34), Pair(7, 34), Pair(2, 27), Pair(9, 47), Pair(23, 0)
      },
      { // Piece 3
        Pair(50, 83), Pair(63, 89), Pair(42, 90), Pair(38, 92), Pair(71, 70), Pair(133, 51), Pair(142, 71), Pair(123, 71),
        Pair(27, 83), Pair(8, 95), Pair(51, 81), Pair(93, 68), Pair(79, 65), Pair(75, 41), Pair(-19, 101), Pair(14, 86),
        Pair(25, 70), Pair(64, 61), Pair(64, 67), Pair(97, 50), Pair(131, 28), Pair(147, 44), Pair(128, 57), Pair(24, 70),
        Pair(16, 68), Pair(36, 68), Pair(51, 67), Pair(90, 55), Pair(91, 57), Pair(122, 35), Pair(81, 55), Pair(36, 64),
        Pair(2, 55), Pair(-11, 71), Pair(-2, 77), Pair(8, 69), Pair(16, 62), Pair(24, 62), Pair(41, 52), Pair(-9, 52),
        Pair(-36, 59), Pair(-12, 55), Pair(-3, 47), Pair(-2, 51), Pair(9, 46), Pair(-3, 54), Pair(21, 39), Pair(-12, 36),
        Pair(-45, 49), Pair(-3, 33), Pair(-13, 51), Pair(9, 33), Pair(17, 27), Pair(25, 19), Pair(-3, 35), Pair(-24, 35),
        Pair(-7, 43), Pair(-9, 50), Pair(1, 47), Pair(2, 44), Pair(14, 33), Pair(10, 41), Pair(12, 33), Pair(-22, 40)
      },
      { // Piece 4
        Pair(81, 57), Pair(60, 99), Pair(122, 57), Pair(114, 54), Pair(100, 95), Pair(140, 82), Pair(160, 37), Pair(166, 26),
        Pair(53, 78), Pair(-22, 162), Pair(4, 151), Pair(4, 163), Pair(67, 156), Pair(123, 93), Pair(57, 185), Pair(139, 107),
        Pair(35, 80), Pair(60, 75), Pair(64, 95), Pair(74, 95), Pair(89, 112), Pair(106, 159), Pair(84, 169), Pair(113, 65),
        Pair(20, 79), Pair(29, 144), Pair(46, 114), Pair(69, 137), Pair(54, 163), Pair(72, 162), Pair(111, 126), Pair(94, 97),
        Pair(29, 71), Pair(23, 135), Pair(44, 126), Pair(34, 147), Pair(51, 141), Pair(67, 118), Pair(118, 81), Pair(72, 95),
        Pair(20, 93), Pair(47, 81), Pair(53, 93), Pair(50, 105), Pair(37, 115), Pair(61, 98), Pair(59, 66), Pair(47, 83),
        Pair(24, 73), Pair(35, 74), Pair(50, 58), Pair(36, 87), Pair(54, 76), Pair(57, 40), Pair(45, 42), Pair(54, 12),
        Pair(48, 23), Pair(14, 53), Pair(32, 55), Pair(40, 70), Pair(37, 75), Pair(65, 25), Pair(56, 61), Pair(22, 6)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(66, -42), Pair(-5, 6), Pair(-13, 18), Pair(-44, 36), Pair(-39, 27), Pair(-42, 25), Pair(0, 0), Pair(20, -34),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 9), Pair(-42, 27), Pair(11, -35), Pair(10, -48), Pair(-44, -39), Pair(61, -68), Pair(20, 3), Pair(-29, -1),
        Pair(-15, 46), Pair(-23, 42), Pair(-50, 32), Pair(22, -19), Pair(28, -13), Pair(58, -20), Pair(69, 18), Pair(-26, 48),
        Pair(-36, 35), Pair(-21, 26), Pair(-23, 4), Pair(0, -6), Pair(39, -12), Pair(60, -24), Pair(26, 9), Pair(8, 13),
        Pair(-38, 21), Pair(-29, 28), Pair(-3, 1), Pair(-13, 7), Pair(-11, 6), Pair(18, 2), Pair(20, 8), Pair(-11, 2),
        Pair(-39, 11), Pair(-29, 14), Pair(-20, 5), Pair(-4, -3), Pair(5, 0), Pair(23, -4), Pair(-4, -4), Pair(-33, -3),
        Pair(-38, 25), Pair(-14, 19), Pair(3, 8), Pair(-28, 25), Pair(-7, 12), Pair(33, -2), Pair(21, -1), Pair(-38, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-190, -99), Pair(-14, -32), Pair(-51, 3), Pair(48, -7), Pair(26, -1), Pair(-18, 47), Pair(-162, 16), Pair(-68, -39),
        Pair(-21, -21), Pair(17, -26), Pair(62, -26), Pair(43, 18), Pair(138, -26), Pair(136, -21), Pair(-2, -9), Pair(-23, -1),
        Pair(-30, -27), Pair(16, -7), Pair(-28, 41), Pair(87, 16), Pair(131, 1), Pair(139, 5), Pair(63, -17), Pair(23, -24),
        Pair(23, 0), Pair(19, 19), Pair(85, 23), Pair(120, 14), Pair(135, 8), Pair(85, 22), Pair(133, -10), Pair(-2, 23),
        Pair(36, 12), Pair(28, 22), Pair(29, 36), Pair(47, 43), Pair(89, 26), Pair(66, 29), Pair(94, 17), Pair(41, 9),
        Pair(-30, -12), Pair(15, 16), Pair(24, 33), Pair(47, 39), Pair(61, 31), Pair(53, 15), Pair(40, 12), Pair(10, 7),
        Pair(-39, 12), Pair(18, 0), Pair(32, 6), Pair(6, 14), Pair(15, 11), Pair(-31, 23), Pair(-54, 27), Pair(23, 1),
        Pair(-93, -13), Pair(-50, -22), Pair(-25, 12), Pair(-18, 13), Pair(-21, 14), Pair(26, -4), Pair(7, -11), Pair(-172, -4)
      },
      { // Piece 2
        Pair(-92, 38), Pair(40, -14), Pair(-77, 17), Pair(-91, 16), Pair(-67, 20), Pair(-70, 12), Pair(-27, -5), Pair(-65, -11),
        Pair(-99, 33), Pair(23, 7), Pair(-11, 5), Pair(58, -23), Pair(61, -7), Pair(-12, 17), Pair(-25, 10), Pair(-23, 10),
        Pair(-63, 30), Pair(44, -8), Pair(64, 8), Pair(43, -2), Pair(76, -16), Pair(54, -2), Pair(50, -3), Pair(12, 2),
        Pair(-25, 16), Pair(-8, 9), Pair(35, -6), Pair(60, -11), Pair(44, 8), Pair(37, -5), Pair(44, -13), Pair(43, -8),
        Pair(5, -7), Pair(25, -12), Pair(35, -4), Pair(83, -12), Pair(60, -3), Pair(27, 11), Pair(41, -6), Pair(-25, 5),
        Pair(-29, -7), Pair(16, 2), Pair(20, 3), Pair(17, 12), Pair(43, 9), Pair(29, 5), Pair(46, -7), Pair(4, 1),
        Pair(-10, 1), Pair(8, -17), Pair(-5, 5), Pair(-1, 8), Pair(13, -1), Pair(0, 2), Pair(7, -9), Pair(-98, -14),
        Pair(7, -18), Pair(28, -12), Pair(-1, -4), Pair(-11, 6), Pair(-51, 12), Pair(-18, 6), Pair(-32, 9), Pair(-48, -15)
      },
      { // Piece 3
        Pair(-26, 38), Pair(-23, 44), Pair(-20, 42), Pair(-9, 34), Pair(2, 35), Pair(39, 33), Pair(57, 29), Pair(40, 34),
        Pair(-22, 17), Pair(12, 10), Pair(-4, 18), Pair(40, 8), Pair(10, 24), Pair(86, -8), Pair(-11, 13), Pair(31, 0),
        Pair(-47, 23), Pair(10, 13), Pair(8, 20), Pair(0, 3), Pair(54, -10), Pair(26, -5), Pair(-30, 8), Pair(-41, 11),
        Pair(-35, 21), Pair(31, 17), Pair(23, 12), Pair(28, 10), Pair(64, -4), Pair(41, 0), Pair(60, -12), Pair(12, 7),
        Pair(-52, 11), Pair(-26, 24), Pair(-17, 18), Pair(-35, 32), Pair(19, -3), Pair(30, 10), Pair(-6, 15), Pair(-44, 20),
        Pair(-93, 4), Pair(-40, 0), Pair(-55, 12), Pair(-57, 4), Pair(-61, 10), Pair(-35, 1), Pair(10, -9), Pair(-101, 19),
        Pair(-104, 2), Pair(-61, -6), Pair(-7, -30), Pair(-64, -7), Pair(-40, -22), Pair(-18, -20), Pair(-44, -3), Pair(-125, -15),
        Pair(-61, -12), Pair(-78, 6), Pair(-66, 8), Pair(-59, 6), Pair(-58, -6), Pair(-50, -5), Pair(-73, 2), Pair(-46, -12)
      },
      { // Piece 4
        Pair(92, -28), Pair(135, -68), Pair(170, -63), Pair(180, -58), Pair(126, 7), Pair(105, -3), Pair(234, -63), Pair(196, -63),
        Pair(1, -15), Pair(-3, 0), Pair(60, -30), Pair(101, -26), Pair(55, 27), Pair(184, -65), Pair(128, -41), Pair(114, -35),
        Pair(37, -48), Pair(49, -35), Pair(-10, 43), Pair(42, 23), Pair(72, 17), Pair(176, -13), Pair(125, -44), Pair(145, -4),
        Pair(15, -16), Pair(58, 1), Pair(69, -53), Pair(89, 7), Pair(80, 21), Pair(155, -62), Pair(108, -23), Pair(174, -106),
        Pair(57, -21), Pair(23, 11), Pair(52, -19), Pair(12, 25), Pair(73, 41), Pair(96, 3), Pair(150, -35), Pair(69, -27),
        Pair(39, -76), Pair(-33, -46), Pair(40, -20), Pair(-1, 10), Pair(40, -13), Pair(54, -21), Pair(33, -25), Pair(31, -135),
        Pair(0, -12), Pair(-44, -1), Pair(-34, -39), Pair(-19, 2), Pair(50, -45), Pair(-16, -15), Pair(10, -46), Pair(19, -63),
        Pair(-18, -48), Pair(4, -17), Pair(-4, -55), Pair(-22, -14), Pair(-12, -59), Pair(-45, -12), Pair(55, -91), Pair(34, -17)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(83, -49), Pair(17, 2), Pair(20, 15), Pair(-23, 34), Pair(1, 21), Pair(-26, 25), Pair(12, 1), Pair(34, -29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(1, -16), Pair(4, -15), Pair(-52, -31), Pair(-5, -52), Pair(-19, -54), Pair(-76, -14), Pair(56, -1), Pair(-73, -5),
        Pair(-55, 42), Pair(-21, 28), Pair(-76, 26), Pair(12, -23), Pair(-26, 6), Pair(25, 0), Pair(51, 26), Pair(9, 15),
        Pair(-39, 18), Pair(-23, 13), Pair(-61, 7), Pair(-12, -9), Pair(5, -8), Pair(-59, 4), Pair(17, 5), Pair(-29, 8),
        Pair(-21, 2), Pair(-45, 21), Pair(7, -10), Pair(-17, -5), Pair(14, -14), Pair(12, -9), Pair(27, -5), Pair(-49, 2),
        Pair(-52, 2), Pair(-52, 13), Pair(-21, 2), Pair(-41, 7), Pair(0, 10), Pair(-11, 3), Pair(-15, 1), Pair(-37, -7),
        Pair(-28, 7), Pair(-56, 19), Pair(-12, 1), Pair(-24, 13), Pair(10, -3), Pair(46, -13), Pair(-19, 0), Pair(-46, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(24, -117), Pair(-86, -59), Pair(-125, -27), Pair(20, -73), Pair(-64, -41), Pair(-64, -12), Pair(88, -27), Pair(-14, -110),
        Pair(-97, -61), Pair(-91, -25), Pair(56, -47), Pair(-41, 0), Pair(86, -23), Pair(78, -46), Pair(-32, -17), Pair(35, -55),
        Pair(-79, -60), Pair(31, -70), Pair(24, -30), Pair(81, -29), Pair(71, -33), Pair(61, -49), Pair(65, -59), Pair(-50, -72),
        Pair(-34, -31), Pair(34, -36), Pair(62, -16), Pair(65, -6), Pair(145, -38), Pair(97, -34), Pair(71, -39), Pair(-47, -35),
        Pair(-76, -29), Pair(67, -44), Pair(19, -15), Pair(104, -31), Pair(70, -27), Pair(162, -43), Pair(135, -58), Pair(48, -32),
        Pair(-31, -48), Pair(-6, -47), Pair(3, -10), Pair(62, -2), Pair(71, -10), Pair(14, -4), Pair(28, -33), Pair(27, -28),
        Pair(-69, -90), Pair(-6, -40), Pair(-27, -39), Pair(-42, -31), Pair(-38, -17), Pair(0, -27), Pair(-67, 0), Pair(14, -16),
        Pair(-72, -113), Pair(-46, -16), Pair(-23, -40), Pair(-65, -28), Pair(-47, -17), Pair(-12, -15), Pair(-97, -50), Pair(-83, 18)
      },
      { // Piece 2
        Pair(-28, -7), Pair(-24, -37), Pair(-68, -24), Pair(-93, 0), Pair(-187, 5), Pair(-88, -12), Pair(-68, -13), Pair(-34, -21),
        Pair(-121, -18), Pair(-65, -28), Pair(-79, -28), Pair(-57, -30), Pair(-37, -14), Pair(-35, -23), Pair(-33, -39), Pair(-24, -52),
        Pair(0, -34), Pair(-106, -5), Pair(23, -23), Pair(-37, -30), Pair(12, -33), Pair(-41, -26), Pair(-72, -21), Pair(5, -46),
        Pair(-105, -10), Pair(-51, -31), Pair(-58, -22), Pair(7, -32), Pair(81, -48), Pair(67, -41), Pair(11, -33), Pair(-52, -37),
        Pair(-71, -19), Pair(-85, -28), Pair(-1, -25), Pair(31, -35), Pair(73, -47), Pair(-25, -41), Pair(21, -50), Pair(-32, -49),
        Pair(-23, -32), Pair(-32, -22), Pair(-54, -16), Pair(-54, -3), Pair(-13, -5), Pair(30, -37), Pair(79, -48), Pair(-37, -37),
        Pair(-34, -5), Pair(0, -63), Pair(54, -61), Pair(6, -43), Pair(-36, -40), Pair(4, -50), Pair(-20, -38), Pair(-24, -69),
        Pair(-42, -23), Pair(-42, -12), Pair(10, -48), Pair(-29, -34), Pair(-40, -39), Pair(-26, -46), Pair(-51, -33), Pair(-161, -39)
      },
      { // Piece 3
        Pair(-12, -45), Pair(-19, -42), Pair(-95, -8), Pair(-8, -42), Pair(-13, -36), Pair(-40, -13), Pair(-22, -24), Pair(-46, -36),
        Pair(-18, -65), Pair(-49, -45), Pair(-77, -37), Pair(-41, -36), Pair(48, -58), Pair(10, -68), Pair(17, -61), Pair(-5, -55),
        Pair(-19, -53), Pair(-14, -55), Pair(33, -69), Pair(63, -78), Pair(89, -90), Pair(118, -91), Pair(105, -94), Pair(7, -60),
        Pair(-18, -67), Pair(-13, -72), Pair(-30, -56), Pair(11, -80), Pair(55, -75), Pair(78, -134), Pair(-19, -60), Pair(-25, -64),
        Pair(-55, -57), Pair(-10, -59), Pair(-65, -29), Pair(34, -69), Pair(-2, -62), Pair(29, -59), Pair(3, -71), Pair(-82, -52),
        Pair(-137, -57), Pair(-107, -50), Pair(-78, -54), Pair(-34, -77), Pair(-54, -71), Pair(0, -73), Pair(-76, -55), Pair(-89, -47),
        Pair(-204, -59), Pair(-77, -81), Pair(-79, -82), Pair(-40, -82), Pair(-67, -67), Pair(-48, -70), Pair(-14, -78), Pair(-122, -78),
        Pair(-57, -87), Pair(-95, -72), Pair(-145, -32), Pair(-91, -61), Pair(-85, -54), Pair(-13, -80), Pair(-108, -56), Pair(-72, -63)
      },
      { // Piece 4
        Pair(20, -173), Pair(-91, -137), Pair(90, -91), Pair(72, -95), Pair(86, -132), Pair(66, -153), Pair(97, -165), Pair(11, -112),
        Pair(27, -197), Pair(-27, -126), Pair(197, -191), Pair(139, -110), Pair(178, -151), Pair(83, -123), Pair(97, -152), Pair(38, -118),
        Pair(69, -262), Pair(-48, -167), Pair(71, -156), Pair(17, -120), Pair(169, -258), Pair(64, -142), Pair(124, -181), Pair(135, -208),
        Pair(-30, -149), Pair(-66, -70), Pair(-9, -177), Pair(121, -194), Pair(11, -90), Pair(43, -78), Pair(40, -89), Pair(126, -130),
        Pair(-101, -128), Pair(-48, -102), Pair(-9, -116), Pair(41, -77), Pair(119, -121), Pair(53, -113), Pair(77, -201), Pair(-7, -41),
        Pair(-171, -79), Pair(-12, -111), Pair(40, -145), Pair(18, -122), Pair(-20, -119), Pair(34, -122), Pair(-38, -163), Pair(41, -156),
        Pair(-116, -158), Pair(-17, -157), Pair(-116, -63), Pair(-3, -183), Pair(42, -185), Pair(-77, -116), Pair(-39, -230), Pair(-45, -100),
        Pair(11, -130), Pair(-75, -133), Pair(7, -189), Pair(-15, -191), Pair(-47, -128), Pair(-100, -100), Pair(-100, -65), Pair(-35, -177)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(41, -18), Pair(46, 4), Pair(54, 14), Pair(10, 30), Pair(4, 28), Pair(15, 24), Pair(7, 13), Pair(48, -21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(32, -73), Pair(50, -63), Pair(136, -93), Pair(66, -78), Pair(108, -59), Pair(14, -77), Pair(154, -44), Pair(91, -65),
        Pair(-49, 14), Pair(50, -6), Pair(-71, -1), Pair(-13, -12), Pair(-5, 2), Pair(-54, 4), Pair(20, 4), Pair(0, 19),
        Pair(-100, 9), Pair(-91, 9), Pair(20, -25), Pair(-14, -23), Pair(-13, -27), Pair(-28, -19), Pair(-47, -10), Pair(-74, 6),
        Pair(-78, -3), Pair(-113, 17), Pair(-46, -16), Pair(-69, -12), Pair(-40, -10), Pair(-18, -15), Pair(-40, -10), Pair(-52, -5),
        Pair(-115, 3), Pair(-88, 6), Pair(-35, -8), Pair(-95, 12), Pair(-8, 0), Pair(39, -12), Pair(-32, -4), Pair(-66, -6),
        Pair(-29, -5), Pair(-79, 15), Pair(15, -13), Pair(-5, -11), Pair(-55, 13), Pair(33, -6), Pair(5, -5), Pair(-79, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-114, -117), Pair(-61, -85), Pair(-177, -69), Pair(-94, -84), Pair(-93, -52), Pair(-225, -14), Pair(-19, -82), Pair(-28, -136),
        Pair(-170, -112), Pair(-80, -53), Pair(-45, -83), Pair(-74, -54), Pair(-40, -60), Pair(-15, -82), Pair(-17, -94), Pair(-75, -118),
        Pair(-146, -69), Pair(-75, -62), Pair(17, -58), Pair(29, -70), Pair(56, -75), Pair(4, -53), Pair(-38, -85), Pair(-8, -101),
        Pair(-130, -71), Pair(-29, -79), Pair(-33, -53), Pair(-43, -53), Pair(82, -66), Pair(118, -92), Pair(51, -73), Pair(116, -120),
        Pair(4, -95), Pair(-60, -69), Pair(-26, -47), Pair(44, -56), Pair(44, -61), Pair(57, -50), Pair(79, -80), Pair(47, -63),
        Pair(-41, -99), Pair(14, -71), Pair(-94, -43), Pair(33, -61), Pair(93, -57), Pair(-6, -53), Pair(144, -125), Pair(-13, -82),
        Pair(-71, -94), Pair(-49, -73), Pair(118, -117), Pair(16, -83), Pair(-10, -85), Pair(85, -94), Pair(-98, -44), Pair(36, -76),
        Pair(44, -111), Pair(-51, -115), Pair(-30, -86), Pair(35, -67), Pair(79, -99), Pair(2, -104), Pair(24, -125), Pair(44, -139)
      },
      { // Piece 2
        Pair(-134, 7), Pair(-172, -7), Pair(-182, -15), Pair(-106, -42), Pair(-184, -35), Pair(-238, -4), Pair(-64, -41), Pair(-118, -19),
        Pair(-63, -53), Pair(-142, -24), Pair(-190, -23), Pair(-140, -23), Pair(-248, -18), Pair(-179, -26), Pair(-189, -19), Pair(-99, -31),
        Pair(-165, -29), Pair(-98, -36), Pair(-186, -16), Pair(-113, -35), Pair(-180, -13), Pair(-165, -7), Pair(-123, -38), Pair(-108, -38),
        Pair(-115, -61), Pair(-91, -48), Pair(-113, -28), Pair(-122, -21), Pair(-119, -14), Pair(-143, 5), Pair(-77, -45), Pair(-100, -50),
        Pair(-77, -63), Pair(-124, -34), Pair(-58, -50), Pair(20, -68), Pair(-35, -48), Pair(0, -61), Pair(-78, -38), Pair(60, -111),
        Pair(-85, -60), Pair(-146, -46), Pair(-144, -29), Pair(-24, -54), Pair(15, -65), Pair(-72, -43), Pair(-141, -16), Pair(-78, -48),
        Pair(6, -53), Pair(-79, -71), Pair(-101, -66), Pair(-79, -63), Pair(-20, -75), Pair(7, -87), Pair(-40, -74), Pair(-47, -89),
        Pair(-129, -18), Pair(-289, -6), Pair(-103, -49), Pair(-25, -57), Pair(-84, -76), Pair(-96, -57), Pair(-152, -37), Pair(-131, -41)
      },
      { // Piece 3
        Pair(-33, -94), Pair(-46, -92), Pair(20, -112), Pair(25, -105), Pair(-55, -80), Pair(-80, -68), Pair(-1, -87), Pair(-111, -58),
        Pair(-32, -130), Pair(-5, -124), Pair(-54, -119), Pair(-28, -118), Pair(-34, -106), Pair(-31, -119), Pair(-47, -113), Pair(-7, -127),
        Pair(-84, -98), Pair(-11, -119), Pair(-31, -101), Pair(-10, -123), Pair(6, -116), Pair(85, -138), Pair(-23, -116), Pair(-27, -118),
        Pair(-43, -125), Pair(-34, -121), Pair(-30, -113), Pair(49, -135), Pair(43, -142), Pair(107, -162), Pair(44, -132), Pair(-43, -115),
        Pair(-13, -147), Pair(-72, -109), Pair(-13, -119), Pair(-26, -143), Pair(73, -150), Pair(103, -165), Pair(32, -164), Pair(-13, -120),
        Pair(-113, -112), Pair(-117, -110), Pair(-62, -122), Pair(-6, -130), Pair(3, -132), Pair(141, -169), Pair(105, -127), Pair(-97, -110),
        Pair(-58, -125), Pair(-28, -144), Pair(0, -150), Pair(14, -161), Pair(69, -169), Pair(146, -171), Pair(82, -155), Pair(-53, -134),
        Pair(-18, -145), Pair(5, -155), Pair(1, -141), Pair(24, -143), Pair(-5, -144), Pair(56, -163), Pair(42, -155), Pair(-81, -124)
      },
      { // Piece 4
        Pair(-41, -278), Pair(-134, -174), Pair(-5, -226), Pair(-1, -246), Pair(-98, -199), Pair(-121, -153), Pair(-193, -172), Pair(-209, -215),
        Pair(-47, -247), Pair(-5, -314), Pair(69, -286), Pair(-1, -113), Pair(6, -149), Pair(-73, -192), Pair(152, -326), Pair(139, -252),
        Pair(34, -298), Pair(-87, -194), Pair(-47, -229), Pair(46, -306), Pair(-51, -198), Pair(192, -377), Pair(15, -214), Pair(19, -244),
        Pair(-80, -273), Pair(73, -285), Pair(-7, -181), Pair(25, -203), Pair(130, -268), Pair(-3, -270), Pair(-98, -232), Pair(82, -261),
        Pair(-15, -265), Pair(-4, -243), Pair(-144, -200), Pair(-115, -172), Pair(96, -219), Pair(-80, -215), Pair(-52, -230), Pair(-91, -219),
        Pair(-101, -190), Pair(-148, -195), Pair(-44, -212), Pair(-34, -166), Pair(-17, -150), Pair(45, -260), Pair(-83, -148), Pair(-15, -226),
        Pair(-89, -316), Pair(-24, -291), Pair(-25, -284), Pair(44, -269), Pair(77, -307), Pair(-133, -180), Pair(-20, -151), Pair(-101, -277),
        Pair(2, -237), Pair(-93, -212), Pair(-21, -262), Pair(-78, -193), Pair(6, -271), Pair(-77, -223), Pair(-14, -175), Pair(-27, -195)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(26, -6), Pair(26, 7), Pair(54, 11), Pair(31, 17), Pair(2, 20), Pair(-1, 22), Pair(12, 11), Pair(10, -14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-100, -3), Pair(92, -1), Pair(-3, -62), Pair(75, 87), Pair(-124, -15), Pair(2, 30), Pair(-30, 37), Pair(0, -35),
        Pair(-86, 56), Pair(-76, 107), Pair(-93, 17), Pair(13, -37), Pair(-18, 27), Pair(-71, 44), Pair(8, 101), Pair(-57, -17),
        Pair(-140, 31), Pair(35, 2), Pair(-69, 33), Pair(-137, -21), Pair(12, -19), Pair(17, -7), Pair(-114, 29), Pair(-158, 51),
        Pair(-132, 15), Pair(42, 12), Pair(1, -31), Pair(-138, 8), Pair(-40, -28), Pair(107, -42), Pair(-62, -8), Pair(-112, -10),
        Pair(-92, 4), Pair(-115, 38), Pair(52, -36), Pair(-58, -2), Pair(15, -11), Pair(-39, -11), Pair(-59, 2), Pair(-133, 16),
        Pair(-67, 16), Pair(-12, 17), Pair(65, -20), Pair(-2, 13), Pair(-54, 19), Pair(31, 17), Pair(96, -1), Pair(-121, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-38, -108), Pair(-69, -202), Pair(-24, -67), Pair(-85, -168), Pair(3, -86), Pair(-34, -49), Pair(-26, 26), Pair(-70, -168),
        Pair(-45, -131), Pair(-32, 37), Pair(-31, -96), Pair(33, 1), Pair(54, -30), Pair(-68, -86), Pair(-37, -55), Pair(23, -74),
        Pair(-47, -71), Pair(-2, -53), Pair(-59, -16), Pair(-42, 5), Pair(23, -64), Pair(-42, 5), Pair(-10, -62), Pair(-57, -111),
        Pair(-30, -81), Pair(61, -74), Pair(-6, 2), Pair(62, 23), Pair(93, -7), Pair(37, 14), Pair(-28, -91), Pair(-51, -108),
        Pair(13, -10), Pair(-62, 5), Pair(65, -43), Pair(52, -1), Pair(230, -45), Pair(95, -33), Pair(22, -95), Pair(-16, 67),
        Pair(-38, 3), Pair(-20, -105), Pair(45, 6), Pair(95, 21), Pair(-87, 4), Pair(54, 7), Pair(78, -41), Pair(9, -38),
        Pair(-28, -124), Pair(-22, -140), Pair(-16, -58), Pair(-63, -70), Pair(-7, -56), Pair(224, -26), Pair(-4, -5), Pair(95, -68),
        Pair(16, 23), Pair(40, -100), Pair(20, -125), Pair(16, -49), Pair(-18, -76), Pair(63, -99), Pair(16, -65), Pair(-9, -1)
      },
      { // Piece 2
        Pair(6, 29), Pair(-17, 33), Pair(-2, 77), Pair(-23, -12), Pair(8, 20), Pair(6, 50), Pair(41, -32), Pair(23, 39),
        Pair(-35, 1), Pair(-50, 66), Pair(-67, -63), Pair(-76, 58), Pair(21, 79), Pair(-26, -16), Pair(44, -28), Pair(49, 21),
        Pair(-40, -4), Pair(-13, -38), Pair(-70, 60), Pair(-73, -9), Pair(-41, 52), Pair(-129, 63), Pair(-84, -2), Pair(-9, 17),
        Pair(-15, -34), Pair(-43, -13), Pair(-159, 62), Pair(-65, 71), Pair(-73, 64), Pair(-134, 30), Pair(-65, 43), Pair(-1, 31),
        Pair(-91, -19), Pair(-39, 13), Pair(-86, 45), Pair(-127, 60), Pair(54, -6), Pair(-42, 70), Pair(-39, 7), Pair(-7, 37),
        Pair(-77, 47), Pair(-44, -57), Pair(1, -20), Pair(-3, 32), Pair(20, 52), Pair(-39, -37), Pair(-9, -18), Pair(-53, 41),
        Pair(-14, -40), Pair(-77, -27), Pair(-50, -17), Pair(66, 24), Pair(86, -113), Pair(-37, -53), Pair(18, -97), Pair(-61, 23),
        Pair(-28, 14), Pair(-63, 45), Pair(-49, -9), Pair(-92, 27), Pair(-127, 32), Pair(-27, -65), Pair(-46, 49), Pair(-50, -13)
      },
      { // Piece 3
        Pair(-36, -71), Pair(31, -81), Pair(-12, -64), Pair(-27, -49), Pair(-16, -15), Pair(26, 30), Pair(23, -14), Pair(-21, -26),
        Pair(139, -57), Pair(-58, -56), Pair(11, -103), Pair(-65, -97), Pair(-19, -56), Pair(115, -60), Pair(-11, -22), Pair(26, -26),
        Pair(75, -38), Pair(66, -95), Pair(-8, -106), Pair(53, -98), Pair(-29, -47), Pair(-24, -54), Pair(57, -83), Pair(109, -92),
        Pair(17, -40), Pair(-80, -65), Pair(54, -60), Pair(11, -72), Pair(38, -73), Pair(88, -63), Pair(-19, -70), Pair(72, -76),
        Pair(-74, -60), Pair(-30, -30), Pair(89, -116), Pair(85, -95), Pair(79, -46), Pair(87, -76), Pair(50, -94), Pair(74, -108),
        Pair(-40, -76), Pair(-23, -50), Pair(75, -143), Pair(121, -80), Pair(96, -107), Pair(90, -72), Pair(4, -93), Pair(54, -175),
        Pair(35, -82), Pair(-68, -104), Pair(86, -161), Pair(-16, -111), Pair(125, -174), Pair(-12, -67), Pair(134, -43), Pair(41, -92),
        Pair(47, -88), Pair(87, -114), Pair(0, -123), Pair(53, -223), Pair(31, -83), Pair(155, -121), Pair(62, -104), Pair(127, -81)
      },
      { // Piece 4
        Pair(-222, -108), Pair(-44, -136), Pair(-112, -165), Pair(-45, -131), Pair(-136, -180), Pair(-76, -82), Pair(-184, -158), Pair(-68, -103),
        Pair(-71, -113), Pair(-40, -66), Pair(-44, -20), Pair(-39, -104), Pair(-60, -49), Pair(-19, -105), Pair(67, -117), Pair(-21, -78),
        Pair(-57, -166), Pair(-71, -61), Pair(-28, -16), Pair(-110, -139), Pair(40, -56), Pair(17, -208), Pair(-58, -127), Pair(-24, -94),
        Pair(-45, -132), Pair(-85, -127), Pair(60, -110), Pair(41, -198), Pair(14, -102), Pair(1, -82), Pair(-36, -114), Pair(-67, -131),
        Pair(30, -119), Pair(0, -143), Pair(98, -92), Pair(-13, -54), Pair(-21, -60), Pair(-14, -169), Pair(-29, -105), Pair(-60, -144),
        Pair(-60, -248), Pair(46, -82), Pair(-13, -127), Pair(20, -60), Pair(-66, -255), Pair(24, -72), Pair(-90, -135), Pair(-10, -24),
        Pair(-59, -140), Pair(-16, -50), Pair(20, -4), Pair(57, -69), Pair(4, -91), Pair(-16, -105), Pair(-54, -79), Pair(-45, -115),
        Pair(25, -80), Pair(-34, -172), Pair(48, -91), Pair(-41, -168), Pair(14, -83), Pair(12, -78), Pair(-24, -145), Pair(-77, -154)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-40, 39), Pair(-19, 39), Pair(-33, 50), Pair(64, 30), Pair(-3, 42), Pair(-96, 84), Pair(24, 37), Pair(-57, 38),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 3
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(134, 0), Pair(0, 54), Pair(-97, 147), Pair(30, 42), Pair(24, 13), Pair(5, -17), Pair(-36, -82), Pair(-55, -86),
        Pair(-25, 98), Pair(-26, 100), Pair(4, 72), Pair(19, 33), Pair(52, 26), Pair(115, 14), Pair(20, 40), Pair(-14, 33),
        Pair(-31, 63), Pair(-22, 54), Pair(-7, 31), Pair(19, -2), Pair(38, -4), Pair(23, 4), Pair(22, 15), Pair(-22, 24),
        Pair(-21, 30), Pair(-12, 42), Pair(4, 13), Pair(17, -5), Pair(18, -5), Pair(38, -6), Pair(6, 4), Pair(-38, 9),
        Pair(-20, 20), Pair(-11, 24), Pair(-2, 9), Pair(-7, 17), Pair(-13, 15), Pair(18, 6), Pair(28, -2), Pair(-60, 7),
        Pair(-26, 28), Pair(-22, 37), Pair(-8, 15), Pair(-11, 27), Pair(8, 15), Pair(38, 1), Pair(16, 3), Pair(-40, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-437, 84), Pair(-147, 39), Pair(-168, 82), Pair(46, 27), Pair(-14, 58), Pair(177, -36), Pair(-50, 12), Pair(-18, -76),
        Pair(-48, 45), Pair(-66, 62), Pair(-4, 21), Pair(28, 75), Pair(40, 47), Pair(47, 29), Pair(-46, 58), Pair(32, 1),
        Pair(35, 15), Pair(-16, 56), Pair(-7, 91), Pair(43, 63), Pair(95, 42), Pair(55, 54), Pair(88, 17), Pair(69, -10),
        Pair(-61, 53), Pair(-22, 53), Pair(49, 63), Pair(101, 44), Pair(52, 82), Pair(74, 57), Pair(49, 49), Pair(94, -5),
        Pair(-59, 60), Pair(2, 56), Pair(45, 67), Pair(34, 82), Pair(58, 70), Pair(57, 61), Pair(27, 74), Pair(40, 14),
        Pair(-125, 55), Pair(-14, 18), Pair(-21, 64), Pair(9, 67), Pair(32, 58), Pair(31, 37), Pair(-5, 55), Pair(-14, 1),
        Pair(-107, 26), Pair(-36, 46), Pair(-53, 38), Pair(-36, 57), Pair(-22, 49), Pair(11, 6), Pair(-12, 27), Pair(6, -1),
        Pair(-159, -90), Pair(-49, -23), Pair(-92, 37), Pair(-98, 64), Pair(24, -7), Pair(-30, 21), Pair(-133, 56), Pair(97, -38)
      },
      { // Piece 2
        Pair(-215, 99), Pair(-113, 78), Pair(-117, 48), Pair(-97, 51), Pair(-91, 66), Pair(-88, 82), Pair(-34, 1), Pair(77, 26),
        Pair(-92, 71), Pair(-34, 71), Pair(-13, 45), Pair(36, 21), Pair(-20, 31), Pair(13, 27), Pair(-157, 134), Pair(-56, 96),
        Pair(-16, 49), Pair(35, 16), Pair(-20, 65), Pair(-6, 51), Pair(34, 32), Pair(59, 66), Pair(26, 63), Pair(73, 16),
        Pair(-43, 37), Pair(0, 42), Pair(20, 44), Pair(10, 53), Pair(32, 44), Pair(-11, 75), Pair(-27, 68), Pair(3, 42),
        Pair(-63, 34), Pair(-14, 44), Pair(32, 31), Pair(24, 36), Pair(32, 46), Pair(-2, 44), Pair(5, 40), Pair(59, -11),
        Pair(-74, 38), Pair(-39, 55), Pair(-7, 56), Pair(-3, 53), Pair(6, 48), Pair(16, 31), Pair(18, 15), Pair(7, 7),
        Pair(94, -25), Pair(-34, 43), Pair(4, 37), Pair(5, 35), Pair(1, 39), Pair(4, 5), Pair(-6, 26), Pair(-75, 81),
        Pair(-68, 44), Pair(-99, 94), Pair(-24, 33), Pair(-70, 47), Pair(-3, 41), Pair(-23, 18), Pair(-26, -1), Pair(22, -21)
      },
      { // Piece 3
        Pair(25, 69), Pair(11, 97), Pair(2, 99), Pair(-29, 96), Pair(55, 59), Pair(200, -7), Pair(1, 90), Pair(86, 95),
        Pair(7, 85), Pair(-58, 116), Pair(23, 93), Pair(90, 74), Pair(38, 78), Pair(133, 48), Pair(5, 115), Pair(43, 96),
        Pair(-57, 103), Pair(13, 79), Pair(42, 66), Pair(45, 71), Pair(44, 67), Pair(67, 77), Pair(53, 41), Pair(-29, 91),
        Pair(-12, 63), Pair(-16, 85), Pair(-30, 104), Pair(56, 71), Pair(13, 93), Pair(25, 75), Pair(18, 63), Pair(-41, 77),
        Pair(-16, 56), Pair(-10, 75), Pair(13, 49), Pair(-33, 72), Pair(0, 56), Pair(-30, 80), Pair(-21, 81), Pair(-37, 69),
        Pair(-62, 64), Pair(-56, 65), Pair(-71, 79), Pair(-20, 47), Pair(-17, 50), Pair(-16, 36), Pair(21, 40), Pair(-76, 37),
        Pair(-131, 69), Pair(-73, 57), Pair(-55, 72), Pair(-60, 72), Pair(-71, 67), Pair(-6, 20), Pair(-81, 78), Pair(-72, 34),
        Pair(-63, 50), Pair(-68, 64), Pair(-40, 54), Pair(-28, 44), Pair(-20, 39), Pair(-34, 45), Pair(-39, 43), Pair(-46, 32)
      },
      { // Piece 4
        Pair(-107, 108), Pair(-81, 112), Pair(3, 127), Pair(-25, 171), Pair(-8, 162), Pair(146, 120), Pair(112, 127), Pair(8, -11),
        Pair(-51, 62), Pair(-104, 136), Pair(-11, 72), Pair(-36, 102), Pair(-18, 133), Pair(143, 52), Pair(-56, 158), Pair(8, 44),
        Pair(-26, 23), Pair(-56, 99), Pair(-58, 129), Pair(3, 74), Pair(6, 141), Pair(111, 75), Pair(14, 154), Pair(72, 38),
        Pair(-121, 116), Pair(-35, 102), Pair(-67, 152), Pair(1, 134), Pair(49, 73), Pair(0, 131), Pair(36, 135), Pair(59, 47),
        Pair(-78, 69), Pair(-49, 116), Pair(-13, 119), Pair(-54, 171), Pair(-17, 124), Pair(9, 79), Pair(-28, 109), Pair(28, 16),
        Pair(-97, 115), Pair(-31, 54), Pair(-15, 89), Pair(-43, 99), Pair(-50, 124), Pair(-54, 120), Pair(-39, 60), Pair(-20, -22),
        Pair(-12, -54), Pair(-41, 1), Pair(-40, 49), Pair(-28, 74), Pair(-34, 55), Pair(1, -14), Pair(-24, 11), Pair(28, -66),
        Pair(-60, 11), Pair(-22, -45), Pair(-54, 29), Pair(-1, -16), Pair(-10, 14), Pair(-4, 12), Pair(-26, 10), Pair(27, -26)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-33, -29), Pair(43, -26), Pair(-5, 19), Pair(-69, 50), Pair(-34, 34), Pair(-40, 22), Pair(14, -18), Pair(-8, -46),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-40, 78), Pair(-78, 54), Pair(139, -60), Pair(108, -77), Pair(95, -109), Pair(52, -142), Pair(-51, 110), Pair(-11, 81),
        Pair(9, 63), Pair(48, 52), Pair(139, -21), Pair(117, -38), Pair(103, -44), Pair(192, -25), Pair(149, 27), Pair(-25, 75),
        Pair(29, 29), Pair(8, 34), Pair(-20, 27), Pair(31, 1), Pair(25, -3), Pair(42, -7), Pair(47, 9), Pair(12, 4),
        Pair(-48, 35), Pair(-65, 41), Pair(-34, 12), Pair(32, -6), Pair(19, -9), Pair(7, -3), Pair(4, 11), Pair(-38, 9),
        Pair(-63, 31), Pair(-21, 24), Pair(-3, 2), Pair(-28, 8), Pair(3, 7), Pair(32, -14), Pair(15, -3), Pair(-53, 1),
        Pair(-50, 33), Pair(-30, 25), Pair(12, -7), Pair(-14, -23), Pair(-12, 8), Pair(5, -4), Pair(-16, 11), Pair(-26, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-268, -50), Pair(6, 54), Pair(-76, 89), Pair(-100, -34), Pair(5, 44), Pair(-109, 77), Pair(-5, -58), Pair(-213, -66),
        Pair(-73, 4), Pair(-60, 48), Pair(-37, 35), Pair(24, 35), Pair(101, -19), Pair(14, 10), Pair(29, 20), Pair(-158, 30),
        Pair(10, 8), Pair(27, 15), Pair(79, 17), Pair(61, 29), Pair(105, 12), Pair(141, 8), Pair(44, 5), Pair(62, -49),
        Pair(35, 8), Pair(-7, 40), Pair(85, 28), Pair(68, 54), Pair(97, 28), Pair(100, 37), Pair(54, 31), Pair(69, -1),
        Pair(29, -1), Pair(58, 66), Pair(33, 43), Pair(25, 62), Pair(74, 43), Pair(11, 55), Pair(140, 26), Pair(4, 51),
        Pair(-75, 8), Pair(32, -9), Pair(-14, 35), Pair(73, 10), Pair(40, 44), Pair(9, 33), Pair(6, 33), Pair(-23, 4),
        Pair(-208, 56), Pair(-15, 36), Pair(-39, 30), Pair(23, -7), Pair(-3, 33), Pair(46, -16), Pair(-5, -28), Pair(-65, -38),
        Pair(-81, -25), Pair(-79, 13), Pair(-90, -3), Pair(-98, 72), Pair(-53, 11), Pair(-47, 33), Pair(-69, 35), Pair(-121, 91)
      },
      { // Piece 2
        Pair(-42, 53), Pair(-134, 42), Pair(-64, 1), Pair(-44, 33), Pair(-41, -12), Pair(-71, 15), Pair(-8, 47), Pair(-136, 34),
        Pair(20, -10), Pair(30, 10), Pair(-56, -15), Pair(135, -26), Pair(4, 17), Pair(23, 4), Pair(-79, 71), Pair(-106, 20),
        Pair(-56, 59), Pair(3, 32), Pair(76, 5), Pair(82, -13), Pair(109, 2), Pair(-28, 33), Pair(65, -12), Pair(-9, -4),
        Pair(23, -4), Pair(24, 6), Pair(90, 12), Pair(51, 15), Pair(50, 27), Pair(56, 10), Pair(29, 25), Pair(59, -11),
        Pair(-2, 9), Pair(-73, 25), Pair(-13, 11), Pair(14, 26), Pair(75, -2), Pair(-8, 33), Pair(-20, 37), Pair(-70, 35),
        Pair(-21, 1), Pair(-22, 17), Pair(9, 25), Pair(1, 19), Pair(84, -22), Pair(29, 2), Pair(27, -14), Pair(7, -21),
        Pair(-57, 2), Pair(-24, 15), Pair(15, 1), Pair(-2, 16), Pair(-14, 11), Pair(29, -10), Pair(23, -23), Pair(-9, -21),
        Pair(11, 18), Pair(41, -1), Pair(-21, 14), Pair(-28, 9), Pair(20, -7), Pair(-20, 5), Pair(-78, 34), Pair(1, 39)
      },
      { // Piece 3
        Pair(26, 34), Pair(-4, 72), Pair(-38, 67), Pair(139, 31), Pair(35, -8), Pair(29, 61), Pair(13, 74), Pair(30, 31),
        Pair(56, 33), Pair(-37, 68), Pair(55, 36), Pair(80, 32), Pair(163, 3), Pair(33, 47), Pair(58, 46), Pair(-24, 68),
        Pair(-46, 54), Pair(-22, 46), Pair(7, 42), Pair(35, 20), Pair(-5, 33), Pair(57, 50), Pair(72, 5), Pair(-22, 32),
        Pair(-43, 28), Pair(-87, 61), Pair(42, 33), Pair(-6, 39), Pair(9, 9), Pair(59, 25), Pair(-73, 69), Pair(-87, 48),
        Pair(-58, 33), Pair(-101, 48), Pair(-37, 22), Pair(4, 47), Pair(-64, 51), Pair(-14, 10), Pair(-67, 52), Pair(-100, 50),
        Pair(-94, 23), Pair(-65, 44), Pair(-121, 25), Pair(-78, 23), Pair(-43, 10), Pair(-78, 21), Pair(-40, 36), Pair(43, -38),
        Pair(-104, 36), Pair(-83, 50), Pair(-73, 24), Pair(-127, 40), Pair(-116, 39), Pair(-99, 18), Pair(-69, 34), Pair(-192, 67),
        Pair(-84, 21), Pair(-63, 11), Pair(-44, 17), Pair(-80, 36), Pair(-55, 15), Pair(-78, 22), Pair(-103, 29), Pair(-66, 11)
      },
      { // Piece 4
        Pair(-90, 128), Pair(-11, 62), Pair(76, 126), Pair(26, 69), Pair(77, 116), Pair(111, 63), Pair(-33, -7), Pair(56, 54),
        Pair(3, -5), Pair(11, 2), Pair(80, -35), Pair(72, 38), Pair(-58, 64), Pair(29, 20), Pair(-39, 66), Pair(105, -27),
        Pair(27, -75), Pair(42, -62), Pair(-9, -26), Pair(-43, 108), Pair(23, 135), Pair(82, 70), Pair(34, -19), Pair(64, 16),
        Pair(-50, -17), Pair(-45, 59), Pair(-21, 54), Pair(7, 79), Pair(44, 3), Pair(96, 9), Pair(-16, 58), Pair(9, -45),
        Pair(-46, -73), Pair(63, -16), Pair(-111, 102), Pair(36, 29), Pair(-7, 84), Pair(52, -32), Pair(-17, 41), Pair(-73, 23),
        Pair(-52, -74), Pair(-56, 34), Pair(-60, 62), Pair(-22, -7), Pair(-57, 72), Pair(-48, 45), Pair(-25, -38), Pair(14, 2),
        Pair(-91, -31), Pair(-57, -59), Pair(-29, 37), Pair(-41, 23), Pair(-36, -13), Pair(-15, -44), Pair(-25, -52), Pair(14, -64),
        Pair(-75, -28), Pair(-94, 8), Pair(-66, -23), Pair(-63, 1), Pair(-27, -81), Pair(-1, -50), Pair(17, 38), Pair(-73, 47)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(27, -39), Pair(18, -20), Pair(14, 2), Pair(-38, 22), Pair(-4, 14), Pair(-9, 0), Pair(42, -35), Pair(14, -57),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(43, -23), Pair(36, -26), Pair(94, -51), Pair(31, -46), Pair(-8, -20), Pair(42, -45), Pair(14, -43), Pair(84, -49),
        Pair(2, 56), Pair(9, 59), Pair(54, 20), Pair(61, -20), Pair(75, -21), Pair(143, -11), Pair(13, 22), Pair(2, 35),
        Pair(0, 31), Pair(1, 32), Pair(17, 9), Pair(23, -9), Pair(14, 2), Pair(25, 5), Pair(20, 16), Pair(-10, 12),
        Pair(-28, 27), Pair(-20, 30), Pair(10, -2), Pair(8, 2), Pair(25, -5), Pair(18, -4), Pair(-1, 11), Pair(-41, 9),
        Pair(-37, 18), Pair(-20, 20), Pair(0, 1), Pair(0, 9), Pair(13, 2), Pair(26, -7), Pair(14, 0), Pair(-37, 3),
        Pair(-40, 31), Pair(-11, 23), Pair(-7, 8), Pair(7, 14), Pair(18, 5), Pair(24, -1), Pair(-5, 10), Pair(-32, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-55, -80), Pair(-62, -33), Pair(-48, 18), Pair(45, -11), Pair(10, 9), Pair(58, 10), Pair(98, -92), Pair(-141, -82),
        Pair(-42, -5), Pair(-56, 20), Pair(2, 17), Pair(33, 27), Pair(51, 16), Pair(31, 0), Pair(-1, 34), Pair(-12, -14),
        Pair(-43, 15), Pair(24, 7), Pair(28, 37), Pair(79, 26), Pair(144, -6), Pair(109, 15), Pair(95, -13), Pair(45, -9),
        Pair(-21, 7), Pair(28, 21), Pair(89, 31), Pair(92, 27), Pair(120, 29), Pair(79, 26), Pair(115, 3), Pair(103, 2),
        Pair(12, 8), Pair(61, 24), Pair(63, 40), Pair(79, 47), Pair(56, 46), Pair(76, 32), Pair(101, 4), Pair(14, 22),
        Pair(-77, 31), Pair(11, 18), Pair(5, 27), Pair(66, 34), Pair(36, 40), Pair(42, 15), Pair(40, 10), Pair(-5, 9),
        Pair(-56, 23), Pair(-21, 35), Pair(-34, 34), Pair(-14, 33), Pair(2, 32), Pair(13, 1), Pair(-28, 19), Pair(22, 2),
        Pair(-76, -16), Pair(-198, 48), Pair(-10, -1), Pair(1, 11), Pair(-57, 21), Pair(-36, 11), Pair(-73, -18), Pair(-173, 29)
      },
      { // Piece 2
        Pair(-40, 17), Pair(-14, 22), Pair(-39, 23), Pair(-2, 12), Pair(-47, -2), Pair(-73, 17), Pair(-13, 16), Pair(-50, -3),
        Pair(-18, 3), Pair(-16, 21), Pair(73, -16), Pair(45, -10), Pair(-5, -3), Pair(-4, 6), Pair(38, 5), Pair(-50, 5),
        Pair(27, -2), Pair(42, 0), Pair(3, 10), Pair(75, -13), Pair(63, 1), Pair(113, -11), Pair(101, -21), Pair(28, 6),
        Pair(46, -2), Pair(30, -5), Pair(32, 2), Pair(80, -11), Pair(73, -2), Pair(36, 5), Pair(76, 1), Pair(47, -11),
        Pair(-13, 6), Pair(26, -8), Pair(27, -1), Pair(47, -3), Pair(77, -10), Pair(21, 8), Pair(64, -14), Pair(74, -15),
        Pair(-5, 2), Pair(17, -6), Pair(15, 4), Pair(45, -4), Pair(32, 13), Pair(47, -6), Pair(35, -9), Pair(-42, 12),
        Pair(13, -30), Pair(19, -11), Pair(44, -11), Pair(30, -15), Pair(20, -3), Pair(20, -12), Pair(24, -21), Pair(36, -38),
        Pair(-48, -1), Pair(23, -9), Pair(-45, 8), Pair(-5, -8), Pair(-3, -5), Pair(34, -14), Pair(-67, 19), Pair(-38, 8)
      },
      { // Piece 3
        Pair(-49, 62), Pair(-23, 59), Pair(-28, 55), Pair(-50, 63), Pair(22, 28), Pair(85, 27), Pair(94, 17), Pair(55, 38),
        Pair(28, 25), Pair(-13, 43), Pair(-4, 39), Pair(21, 33), Pair(19, 32), Pair(65, 2), Pair(55, 0), Pair(-27, 27),
        Pair(9, 22), Pair(46, 16), Pair(63, 5), Pair(13, 24), Pair(84, -9), Pair(148, -13), Pair(74, -6), Pair(-34, 34),
        Pair(-46, 28), Pair(-12, 32), Pair(-3, 33), Pair(80, 11), Pair(74, 2), Pair(42, 5), Pair(9, 16), Pair(23, 16),
        Pair(-76, 18), Pair(-79, 44), Pair(-45, 28), Pair(-47, 35), Pair(-41, 24), Pair(13, 6), Pair(-29, 13), Pair(-75, 21),
        Pair(-70, 6), Pair(-42, 15), Pair(-53, 15), Pair(-71, 18), Pair(-95, 26), Pair(-38, 10), Pair(-46, 11), Pair(-69, 6),
        Pair(-129, 24), Pair(-72, 7), Pair(-66, 8), Pair(-47, 0), Pair(-58, 3), Pair(-38, -19), Pair(-67, -5), Pair(-118, 2),
        Pair(-57, -5), Pair(-73, 19), Pair(-63, 15), Pair(-62, 9), Pair(-56, 4), Pair(-66, 13), Pair(-54, -1), Pair(-51, -9)
      },
      { // Piece 4
        Pair(-49, -6), Pair(38, -54), Pair(-3, -5), Pair(41, -18), Pair(11, 20), Pair(151, -56), Pair(153, -57), Pair(79, -105),
        Pair(-35, -14), Pair(-26, 34), Pair(-66, 59), Pair(-106, 94), Pair(29, 36), Pair(28, 14), Pair(9, 48), Pair(130, -15),
        Pair(30, -69), Pair(-68, 16), Pair(25, -26), Pair(-36, 28), Pair(34, 25), Pair(122, -18), Pair(-41, 122), Pair(53, -18),
        Pair(-65, -12), Pair(10, -18), Pair(9, -2), Pair(-16, 60), Pair(76, 8), Pair(-6, 99), Pair(108, -41), Pair(-12, 26),
        Pair(-16, -88), Pair(-70, 40), Pair(-99, 54), Pair(-23, 49), Pair(-16, 64), Pair(47, 19), Pair(-50, 30), Pair(7, -50),
        Pair(-34, -58), Pair(-78, -21), Pair(-37, 32), Pair(1, -17), Pair(-69, 30), Pair(-34, 32), Pair(-48, -38), Pair(1, -66),
        Pair(2, -144), Pair(-99, -27), Pair(-6, -16), Pair(-37, -9), Pair(-69, 17), Pair(-54, -31), Pair(-70, -14), Pair(-31, -38),
        Pair(-28, -36), Pair(-9, -60), Pair(-37, -83), Pair(-29, -48), Pair(-29, -50), Pair(-141, 25), Pair(-96, -31), Pair(-68, -15)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(34, -52), Pair(58, -28), Pair(19, -3), Pair(-23, 27), Pair(-13, 19), Pair(-20, 4), Pair(13, -21), Pair(-20, -44),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(11, -24), Pair(85, -30), Pair(-16, -28), Pair(111, -80), Pair(44, -64), Pair(30, -60), Pair(124, -23), Pair(-16, -7),
        Pair(31, 28), Pair(50, 22), Pair(46, -6), Pair(58, -23), Pair(65, -15), Pair(49, -7), Pair(-11, 24), Pair(38, 22),
        Pair(-1, 27), Pair(-37, 36), Pair(-7, 3), Pair(-14, -4), Pair(29, -8), Pair(67, -12), Pair(41, 7), Pair(-10, 12),
        Pair(-28, 19), Pair(-41, 29), Pair(-31, 7), Pair(-9, 9), Pair(-22, 14), Pair(-5, 8), Pair(16, 11), Pair(-21, 2),
        Pair(-60, 18), Pair(-45, 16), Pair(-14, 1), Pair(-22, 8), Pair(-11, 5), Pair(23, -11), Pair(10, -3), Pair(-51, 6),
        Pair(-68, 28), Pair(-41, 20), Pair(-21, 5), Pair(20, -12), Pair(-18, 7), Pair(15, 0), Pair(11, 6), Pair(-31, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-59, -72), Pair(-58, -46), Pair(-129, 17), Pair(-43, -20), Pair(17, -43), Pair(-84, 38), Pair(-9, -67), Pair(-65, -103),
        Pair(9, -48), Pair(-95, 0), Pair(67, -37), Pair(90, -43), Pair(119, -41), Pair(14, -40), Pair(-12, -47), Pair(-66, -45),
        Pair(46, -64), Pair(46, -24), Pair(17, -1), Pair(78, -1), Pair(112, -12), Pair(86, -24), Pair(47, -43), Pair(49, -54),
        Pair(37, -29), Pair(45, -25), Pair(63, -14), Pair(42, 3), Pair(165, -21), Pair(115, -22), Pair(58, -16), Pair(53, -26),
        Pair(7, -23), Pair(8, -12), Pair(63, 2), Pair(90, 5), Pair(98, -2), Pair(42, 7), Pair(57, -6), Pair(50, -7),
        Pair(4, -47), Pair(-24, -14), Pair(19, -11), Pair(32, 5), Pair(27, 5), Pair(-6, -9), Pair(44, -16), Pair(13, -25),
        Pair(-131, 11), Pair(-58, 4), Pair(22, -22), Pair(26, -20), Pair(-2, -12), Pair(10, -12), Pair(-19, -8), Pair(4, -3),
        Pair(33, -55), Pair(-186, -26), Pair(-92, -11), Pair(-106, -4), Pair(43, -25), Pair(-76, -2), Pair(-40, -26), Pair(-107, -45)
      },
      { // Piece 2
        Pair(-41, -42), Pair(-57, 3), Pair(-56, -28), Pair(-49, -21), Pair(-77, -22), Pair(-17, -42), Pair(10, -27), Pair(-55, -35),
        Pair(-39, -42), Pair(5, -30), Pair(12, -35), Pair(14, -41), Pair(37, -56), Pair(-32, -37), Pair(11, -22), Pair(-45, -46),
        Pair(33, -29), Pair(-30, -23), Pair(79, -40), Pair(51, -41), Pair(119, -50), Pair(92, -26), Pair(76, -30), Pair(-41, -15),
        Pair(-75, -26), Pair(15, -34), Pair(16, -27), Pair(72, -38), Pair(97, -36), Pair(67, -41), Pair(20, -37), Pair(0, -36),
        Pair(-14, -35), Pair(23, -40), Pair(80, -36), Pair(107, -38), Pair(62, -37), Pair(55, -26), Pair(84, -45), Pair(34, -37),
        Pair(-57, 2), Pair(-13, -27), Pair(-18, -22), Pair(13, -27), Pair(38, -28), Pair(80, -52), Pair(40, -37), Pair(-58, -14),
        Pair(-94, 2), Pair(-29, -33), Pair(23, -33), Pair(1, -29), Pair(10, -32), Pair(-80, -16), Pair(7, -40), Pair(58, -72),
        Pair(-46, -23), Pair(-53, 0), Pair(-35, -25), Pair(-57, -24), Pair(-67, -29), Pair(-36, -35), Pair(-7, -36), Pair(-35, -29)
      },
      { // Piece 3
        Pair(-12, -14), Pair(10, -15), Pair(-8, -7), Pair(39, -24), Pair(-6, -12), Pair(88, -35), Pair(35, -15), Pair(-1, -11),
        Pair(6, -40), Pair(27, -38), Pair(63, -51), Pair(37, -37), Pair(34, -34), Pair(104, -63), Pair(64, -46), Pair(-30, -31),
        Pair(22, -40), Pair(-18, -30), Pair(71, -44), Pair(60, -64), Pair(14, -47), Pair(90, -69), Pair(12, -64), Pair(-62, -14),
        Pair(5, -35), Pair(35, -42), Pair(72, -45), Pair(43, -41), Pair(185, -88), Pair(88, -61), Pair(62, -56), Pair(61, -49),
        Pair(-49, -33), Pair(-73, -16), Pair(-5, -28), Pair(37, -41), Pair(1, -33), Pair(-15, -22), Pair(28, -28), Pair(-58, -33),
        Pair(-122, -41), Pair(-37, -48), Pair(-70, -32), Pair(-34, -49), Pair(-15, -57), Pair(-12, -48), Pair(26, -64), Pair(-181, -17),
        Pair(-127, -38), Pair(-83, -57), Pair(-37, -57), Pair(-26, -66), Pair(-26, -59), Pair(-37, -61), Pair(6, -79), Pair(-121, -48),
        Pair(-76, -50), Pair(-62, -45), Pair(-62, -42), Pair(-55, -38), Pair(-55, -44), Pair(-41, -48), Pair(-33, -53), Pair(-92, -36)
      },
      { // Piece 4
        Pair(35, -92), Pair(99, -142), Pair(-7, -105), Pair(141, -135), Pair(37, -37), Pair(30, -61), Pair(3, -47), Pair(41, -110),
        Pair(51, -149), Pair(-125, -46), Pair(-158, 28), Pair(-47, -47), Pair(16, -30), Pair(-33, -33), Pair(171, -206), Pair(-90, -66),
        Pair(-92, -49), Pair(-131, -48), Pair(34, -107), Pair(-60, -52), Pair(84, -127), Pair(80, -82), Pair(6, -17), Pair(-18, -103),
        Pair(-28, -168), Pair(-132, -77), Pair(-75, -26), Pair(18, -78), Pair(-73, -50), Pair(142, -135), Pair(-4, -147), Pair(86, -111),
        Pair(-27, -110), Pair(-72, -45), Pair(-74, -25), Pair(-32, -19), Pair(-5, -35), Pair(25, -72), Pair(-37, -70), Pair(-119, -67),
        Pair(-94, -122), Pair(25, -137), Pair(-138, -23), Pair(-7, -121), Pair(-47, -59), Pair(-55, -68), Pair(9, -147), Pair(-42, 5),
        Pair(-97, -23), Pair(-32, -116), Pair(-18, -114), Pair(-7, -61), Pair(-8, -115), Pair(-32, -5), Pair(-17, -144), Pair(-88, -154),
        Pair(-26, -135), Pair(-202, 4), Pair(-108, -34), Pair(-16, -192), Pair(-137, -125), Pair(-39, -66), Pair(-66, -145), Pair(-12, -72)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(16, -46), Pair(72, -18), Pair(25, 10), Pair(-7, 30), Pair(-1, 21), Pair(-2, 11), Pair(12, -12), Pair(-45, -26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, -28), Pair(88, -41), Pair(-85, -18), Pair(66, -53), Pair(18, -35), Pair(9, -29), Pair(-94, 15), Pair(-151, -16),
        Pair(21, 29), Pair(14, 29), Pair(-16, -2), Pair(11, -5), Pair(82, -23), Pair(-9, 9), Pair(38, 18), Pair(-13, 34),
        Pair(-54, 25), Pair(-45, 24), Pair(-27, -1), Pair(-36, 0), Pair(-39, 13), Pair(-25, 3), Pair(-4, 13), Pair(-24, 16),
        Pair(-74, 24), Pair(-38, 22), Pair(-29, 4), Pair(-11, 7), Pair(-2, 8), Pair(23, -1), Pair(0, 17), Pair(-60, 14),
        Pair(-75, 13), Pair(-68, 21), Pair(-39, 11), Pair(-30, 16), Pair(-33, 23), Pair(-2, 6), Pair(-16, 11), Pair(-72, 14),
        Pair(-100, 31), Pair(-37, 20), Pair(-3, 0), Pair(32, -10), Pair(23, 2), Pair(9, 2), Pair(-39, 17), Pair(-50, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, -131), Pair(-61, -51), Pair(-125, -8), Pair(-35, -31), Pair(-87, -2), Pair(-39, -25), Pair(-39, -36), Pair(13, -100),
        Pair(-142, -72), Pair(-78, -36), Pair(-30, -24), Pair(8, -28), Pair(84, -33), Pair(121, -56), Pair(-28, -54), Pair(-36, -53),
        Pair(-34, -76), Pair(-45, -29), Pair(-19, -21), Pair(5, -22), Pair(81, -38), Pair(-39, -17), Pair(37, -54), Pair(25, -59),
        Pair(-54, -40), Pair(-62, -28), Pair(30, -22), Pair(41, -12), Pair(61, -22), Pair(81, -23), Pair(42, -46), Pair(-41, -50),
        Pair(16, -65), Pair(42, -39), Pair(60, -26), Pair(36, -22), Pair(91, -24), Pair(135, -39), Pair(131, -46), Pair(-24, -43),
        Pair(29, -65), Pair(-77, -14), Pair(-47, -9), Pair(26, -6), Pair(55, -13), Pair(-3, -25), Pair(-51, -11), Pair(-65, -35),
        Pair(-23, -41), Pair(-145, -8), Pair(3, -34), Pair(15, -23), Pair(-35, -25), Pair(-24, -13), Pair(-54, -29), Pair(-48, -11),
        Pair(-37, -34), Pair(-116, -15), Pair(-90, -35), Pair(-59, -15), Pair(-120, -7), Pair(-107, -22), Pair(-146, -54), Pair(9, -19)
      },
      { // Piece 2
        Pair(-72, -24), Pair(-26, -24), Pair(-131, -9), Pair(-71, -28), Pair(-93, -22), Pair(-133, -24), Pair(-31, -34), Pair(30, -27),
        Pair(-60, -46), Pair(-106, -16), Pair(-152, -4), Pair(-115, -29), Pair(-132, -17), Pair(-105, -24), Pair(-97, -41), Pair(-58, -33),
        Pair(-33, -30), Pair(35, -47), Pair(-105, -18), Pair(-61, -27), Pair(-73, -19), Pair(-10, -24), Pair(-56, -31), Pair(-181, -15),
        Pair(-103, -22), Pair(-50, -33), Pair(1, -54), Pair(57, -47), Pair(77, -58), Pair(41, -32), Pair(38, -54), Pair(-85, -25),
        Pair(-108, -41), Pair(-75, -41), Pair(-20, -35), Pair(16, -33), Pair(33, -51), Pair(41, -31), Pair(18, -48), Pair(-69, -46),
        Pair(-25, -42), Pair(-66, -28), Pair(-10, -35), Pair(-36, -38), Pair(7, -32), Pair(18, -48), Pair(-18, -41), Pair(-6, -43),
        Pair(-101, -5), Pair(-47, -57), Pair(-52, -42), Pair(-14, -36), Pair(-24, -46), Pair(53, -46), Pair(7, -62), Pair(-47, -60),
        Pair(-140, -39), Pair(-61, 5), Pair(-29, -38), Pair(-37, -41), Pair(-38, -42), Pair(-132, -33), Pair(-143, -23), Pair(-91, -30)
      },
      { // Piece 3
        Pair(43, -69), Pair(6, -53), Pair(-44, -46), Pair(-20, -47), Pair(11, -53), Pair(25, -47), Pair(86, -66), Pair(42, -51),
        Pair(-57, -68), Pair(-53, -58), Pair(-56, -53), Pair(13, -67), Pair(8, -62), Pair(78, -96), Pair(10, -70), Pair(12, -77),
        Pair(-20, -67), Pair(-1, -70), Pair(66, -88), Pair(52, -92), Pair(104, -94), Pair(151, -102), Pair(26, -87), Pair(25, -75),
        Pair(-54, -72), Pair(-29, -73), Pair(1, -70), Pair(46, -102), Pair(104, -139), Pair(88, -97), Pair(-7, -93), Pair(-81, -59),
        Pair(-49, -69), Pair(-37, -55), Pair(-103, -35), Pair(-36, -60), Pair(-5, -70), Pair(6, -64), Pair(55, -64), Pair(-13, -61),
        Pair(-77, -79), Pair(-93, -69), Pair(-101, -63), Pair(-13, -90), Pair(-69, -73), Pair(-4, -70), Pair(69, -83), Pair(-66, -105),
        Pair(-53, -101), Pair(-96, -93), Pair(-95, -91), Pair(-73, -95), Pair(-13, -107), Pair(-71, -80), Pair(-118, -59), Pair(-51, -97),
        Pair(-141, -67), Pair(-98, -64), Pair(-62, -72), Pair(-54, -90), Pair(-64, -66), Pair(-81, -74), Pair(-44, -81), Pair(-52, -85)
      },
      { // Piece 4
        Pair(80, -185), Pair(-1, -115), Pair(-27, -59), Pair(-61, -55), Pair(19, -117), Pair(-76, -8), Pair(103, -139), Pair(-82, -91),
        Pair(-145, -117), Pair(-39, -97), Pair(67, -68), Pair(35, -56), Pair(30, -114), Pair(-42, -116), Pair(-58, -60), Pair(22, -209),
        Pair(-46, -39), Pair(2, -171), Pair(31, -48), Pair(-3, -105), Pair(141, -203), Pair(-20, -90), Pair(90, -188), Pair(-43, -135),
        Pair(-82, -148), Pair(-6, -79), Pair(-21, -59), Pair(60, -92), Pair(-7, -76), Pair(18, -59), Pair(-28, -99), Pair(-52, -47),
        Pair(-92, -176), Pair(-71, -78), Pair(31, -90), Pair(-67, -50), Pair(-43, 14), Pair(18, -108), Pair(-9, -74), Pair(-26, -85),
        Pair(-60, -160), Pair(-107, -165), Pair(-52, -41), Pair(-71, 0), Pair(28, -140), Pair(140, -174), Pair(-5, -133), Pair(75, -8),
        Pair(-71, -129), Pair(-23, -118), Pair(-40, -161), Pair(-10, -54), Pair(-66, -19), Pair(3, -57), Pair(-44, -127), Pair(-8, -78),
        Pair(-114, -174), Pair(-50, -184), Pair(-3, -125), Pair(-71, -107), Pair(-105, -164), Pair(-64, -91), Pair(17, -36), Pair(-17, -50)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, -48), Pair(98, -27), Pair(2, 9), Pair(-31, 29), Pair(-5, 18), Pair(5, 6), Pair(19, -11), Pair(-39, -30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, -35), Pair(103, -47), Pair(-93, 14), Pair(-120, -20), Pair(-47, -15), Pair(18, -32), Pair(-58, -11), Pair(77, -39),
        Pair(-105, 53), Pair(-15, 26), Pair(-96, 28), Pair(-42, -24), Pair(-19, 26), Pair(-5, -2), Pair(-48, 39), Pair(-53, 32),
        Pair(-125, 33), Pair(-97, 20), Pair(-39, -1), Pair(17, -8), Pair(-64, 6), Pair(5, -10), Pair(-30, 5), Pair(-33, 6),
        Pair(-51, 2), Pair(-35, 15), Pair(-56, 1), Pair(19, -3), Pair(-40, 7), Pair(5, -6), Pair(-79, 15), Pair(-110, 9),
        Pair(-58, 11), Pair(-136, 29), Pair(-37, 7), Pair(-36, 14), Pair(-62, 19), Pair(3, 3), Pair(2, 4), Pair(-86, 6),
        Pair(-109, 21), Pair(-58, 26), Pair(-50, 10), Pair(-23, 5), Pair(-49, 4), Pair(-9, 8), Pair(-50, 20), Pair(-59, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-81, -201), Pair(-83, -75), Pair(-69, -73), Pair(-141, -49), Pair(-86, -34), Pair(-69, -33), Pair(14, -78), Pair(-47, -117),
        Pair(20, -92), Pair(17, -99), Pair(-1, -79), Pair(-132, -37), Pair(-99, -57), Pair(61, -104), Pair(-51, -82), Pair(-72, -100),
        Pair(-65, -115), Pair(-156, -48), Pair(-38, -46), Pair(42, -71), Pair(63, -68), Pair(-81, -45), Pair(35, -105), Pair(-167, -80),
        Pair(115, -95), Pair(20, -89), Pair(31, -67), Pair(26, -56), Pair(44, -56), Pair(-13, -83), Pair(34, -72), Pair(33, -117),
        Pair(-23, -55), Pair(-85, -65), Pair(83, -70), Pair(145, -81), Pair(87, -70), Pair(155, -70), Pair(50, -55), Pair(7, -87),
        Pair(-112, -75), Pair(-41, -95), Pair(17, -86), Pair(67, -54), Pair(-27, -48), Pair(54, -61), Pair(-15, -65), Pair(38, -56),
        Pair(-48, -52), Pair(-122, -90), Pair(-63, -52), Pair(30, -81), Pair(20, -64), Pair(5, -74), Pair(26, -20), Pair(16, -105),
        Pair(-18, -111), Pair(87, -70), Pair(28, -78), Pair(-17, -98), Pair(20, -106), Pair(57, -90), Pair(69, -87), Pair(-59, -20)
      },
      { // Piece 2
        Pair(-60, 8), Pair(48, -31), Pair(-161, -18), Pair(-137, -57), Pair(-107, -43), Pair(-211, -28), Pair(-63, -75), Pair(-29, -78),
        Pair(-92, -22), Pair(-141, -47), Pair(-115, -20), Pair(-84, -34), Pair(-199, -38), Pair(-112, -52), Pair(-120, -29), Pair(-11, -51),
        Pair(-159, -58), Pair(-59, -43), Pair(-67, -44), Pair(-116, -12), Pair(-135, -31), Pair(-68, -31), Pair(-50, -68), Pair(-58, -45),
        Pair(-133, -52), Pair(-75, -43), Pair(-98, -32), Pair(-116, -21), Pair(-85, -21), Pair(-85, -34), Pair(-112, -15), Pair(-148, -57),
        Pair(-49, -43), Pair(-64, -83), Pair(-76, -43), Pair(46, -71), Pair(14, -54), Pair(-2, -27), Pair(-66, -36), Pair(-45, -61),
        Pair(-13, -60), Pair(-36, -63), Pair(1, -65), Pair(-41, -70), Pair(36, -64), Pair(41, -87), Pair(13, -76), Pair(-92, -67),
        Pair(-61, -51), Pair(-113, -54), Pair(-10, -48), Pair(-13, -53), Pair(-76, -55), Pair(-14, -92), Pair(-89, -66), Pair(27, -60),
        Pair(-35, -28), Pair(-156, -27), Pair(-60, -42), Pair(-99, -41), Pair(-33, -77), Pair(-23, -57), Pair(-109, -49), Pair(-90, -58)
      },
      { // Piece 3
        Pair(-43, -101), Pair(62, -115), Pair(55, -116), Pair(71, -113), Pair(1, -86), Pair(62, -104), Pair(62, -104), Pair(13, -80),
        Pair(-32, -117), Pair(49, -126), Pair(36, -124), Pair(-28, -108), Pair(-10, -99), Pair(36, -125), Pair(-54, -104), Pair(-48, -114),
        Pair(-26, -118), Pair(25, -114), Pair(16, -116), Pair(1, -100), Pair(78, -121), Pair(18, -106), Pair(26, -114), Pair(-37, -112),
        Pair(-17, -113), Pair(84, -125), Pair(-35, -108), Pair(62, -124), Pair(98, -151), Pair(76, -137), Pair(55, -124), Pair(5, -137),
        Pair(37, -139), Pair(-43, -118), Pair(-10, -127), Pair(17, -122), Pair(13, -136), Pair(69, -131), Pair(-77, -92), Pair(-18, -129),
        Pair(-18, -141), Pair(59, -153), Pair(23, -141), Pair(-14, -122), Pair(14, -154), Pair(30, -136), Pair(15, -127), Pair(-10, -152),
        Pair(-27, -129), Pair(-36, -124), Pair(-11, -110), Pair(-24, -152), Pair(16, -127), Pair(109, -158), Pair(42, -170), Pair(122, -160),
        Pair(-21, -131), Pair(52, -136), Pair(27, -126), Pair(35, -114), Pair(58, -135), Pair(65, -156), Pair(94, -143), Pair(98, -162)
      },
      { // Piece 4
        Pair(-186, -186), Pair(-73, -181), Pair(-206, -167), Pair(-32, -177), Pair(-101, -49), Pair(-203, -140), Pair(-172, -218), Pair(-156, -219),
        Pair(-110, -192), Pair(-69, -185), Pair(-98, -178), Pair(49, -113), Pair(-26, -72), Pair(37, -97), Pair(-100, -150), Pair(-18, -119),
        Pair(-60, -172), Pair(-98, -122), Pair(-70, -157), Pair(5, -147), Pair(-24, -87), Pair(-72, -115), Pair(-103, -227), Pair(-31, -130),
        Pair(-82, -189), Pair(-58, -96), Pair(-54, -172), Pair(-69, -109), Pair(34, -133), Pair(-126, -90), Pair(-103, -78), Pair(-88, -154),
        Pair(-111, -262), Pair(-60, -147), Pair(-37, -160), Pair(-68, -82), Pair(3, -150), Pair(-60, -127), Pair(-33, -129), Pair(-89, -100),
        Pair(-59, -143), Pair(32, -93), Pair(-52, -179), Pair(-51, -111), Pair(-19, -155), Pair(-94, -119), Pair(-26, -140), Pair(-79, -137),
        Pair(-33, -150), Pair(-4, -157), Pair(-70, -147), Pair(-7, -83), Pair(-10, -83), Pair(-67, -202), Pair(-89, -163), Pair(-48, -95),
        Pair(-44, -95), Pair(-83, -200), Pair(27, -130), Pair(-61, -94), Pair(-69, -141), Pair(-77, -148), Pair(-51, -100), Pair(-127, -200)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, -36), Pair(68, -23), Pair(-6, 5), Pair(-15, 27), Pair(-42, 31), Pair(-18, 17), Pair(36, -13), Pair(-30, -31),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-204, -29), Pair(-68, 4), Pair(-33, 136), Pair(-22, 43), Pair(4, -21), Pair(10, -18), Pair(-109, 53), Pair(-55, -13),
        Pair(-62, 69), Pair(-62, 56), Pair(-45, 22), Pair(-100, 3), Pair(143, -15), Pair(68, 64), Pair(-128, 84), Pair(-2, 55),
        Pair(-165, 63), Pair(-73, 11), Pair(-91, -4), Pair(-72, -22), Pair(-104, -6), Pair(-60, 30), Pair(-133, 42), Pair(-82, 21),
        Pair(-66, 3), Pair(-65, 23), Pair(-55, 4), Pair(73, -33), Pair(-44, -26), Pair(-20, -10), Pair(-34, 6), Pair(-150, -2),
        Pair(-124, 3), Pair(-106, 27), Pair(32, 6), Pair(-77, 50), Pair(26, 3), Pair(64, -15), Pair(-51, 25), Pair(-105, -18),
        Pair(-81, -1), Pair(-39, 40), Pair(-9, -21), Pair(7, 18), Pair(45, 10), Pair(26, 16), Pair(-92, 34), Pair(-107, 30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-17, -179), Pair(-42, -107), Pair(-52, -64), Pair(-55, -80), Pair(-49, -75), Pair(-50, -50), Pair(15, -2), Pair(0, 52),
        Pair(-41, -180), Pair(5, -31), Pair(-26, -73), Pair(24, -131), Pair(-23, -98), Pair(-66, -12), Pair(36, -6), Pair(3, -88),
        Pair(94, -68), Pair(-137, -59), Pair(-68, -52), Pair(-78, -56), Pair(-10, -57), Pair(-69, -6), Pair(8, -43), Pair(27, 2),
        Pair(10, -59), Pair(48, -116), Pair(62, -48), Pair(18, -25), Pair(-6, -40), Pair(14, -85), Pair(-1, -61), Pair(-4, -21),
        Pair(-53, -213), Pair(49, -81), Pair(-64, -78), Pair(77, -26), Pair(18, -60), Pair(81, -98), Pair(14, -61), Pair(-8, -62),
        Pair(-46, -132), Pair(30, -13), Pair(-51, -51), Pair(87, -46), Pair(112, -18), Pair(17, -13), Pair(-45, -6), Pair(44, -34),
        Pair(-41, -79), Pair(17, -58), Pair(30, -14), Pair(118, -114), Pair(-52, -65), Pair(-105, -50), Pair(-29, -92), Pair(-79, -162),
        Pair(8, 8), Pair(55, -43), Pair(-38, -52), Pair(-74, -93), Pair(-14, -54), Pair(26, -94), Pair(0, -35), Pair(-4, -18)
      },
      { // Piece 2
        Pair(19, 52), Pair(-32, 39), Pair(-11, 19), Pair(-23, -23), Pair(15, 5), Pair(-33, -59), Pair(-33, 3), Pair(-21, 75),
        Pair(-2, 20), Pair(31, 42), Pair(-71, -8), Pair(-28, 6), Pair(-74, -83), Pair(78, -47), Pair(-63, 18), Pair(-21, 7),
        Pair(12, 21), Pair(-44, -9), Pair(-88, 42), Pair(-107, -24), Pair(-124, 15), Pair(-40, -5), Pair(55, 17), Pair(-149, -30),
        Pair(27, 41), Pair(9, -34), Pair(-44, 76), Pair(-91, 3), Pair(-34, 14), Pair(-7, 30), Pair(14, -34), Pair(-48, -109),
        Pair(-21, 20), Pair(-60, -16), Pair(5, -10), Pair(53, -26), Pair(-4, 28), Pair(20, -50), Pair(-48, 48), Pair(-80, 50),
        Pair(11, 43), Pair(2, 12), Pair(-90, -32), Pair(-26, -29), Pair(2, -21), Pair(-25, -8), Pair(-34, -12), Pair(-21, 42),
        Pair(-59, -60), Pair(-22, 47), Pair(-40, 136), Pair(-27, 23), Pair(-61, -7), Pair(-117, 47), Pair(2, 72), Pair(-36, -13),
        Pair(-34, 39), Pair(-21, 11), Pair(-24, -7), Pair(-67, 51), Pair(-72, -16), Pair(-70, 40), Pair(-6, 61), Pair(-13, -42)
      },
      { // Piece 3
        Pair(-12, -80), Pair(-46, -118), Pair(-92, -35), Pair(20, -97), Pair(56, -87), Pair(4, -30), Pair(21, -43), Pair(59, -94),
        Pair(50, -105), Pair(43, -102), Pair(36, -99), Pair(-4, -13), Pair(-1, -143), Pair(-96, -56), Pair(-64, -31), Pair(-47, -39),
        Pair(-30, -65), Pair(22, -106), Pair(-9, -62), Pair(61, -105), Pair(118, -133), Pair(62, -94), Pair(5, -80), Pair(73, -145),
        Pair(13, -81), Pair(49, -80), Pair(71, -131), Pair(-48, -89), Pair(20, -93), Pair(155, -99), Pair(26, -52), Pair(7, -56),
        Pair(-83, -107), Pair(17, -79), Pair(-104, -77), Pair(-48, -130), Pair(37, -88), Pair(50, -90), Pair(-1, -142), Pair(-29, -96),
        Pair(-63, -134), Pair(-46, -50), Pair(122, -118), Pair(18, -140), Pair(85, -92), Pair(46, -137), Pair(-19, -83), Pair(-32, -121),
        Pair(26, -21), Pair(54, -126), Pair(-54, -65), Pair(49, -156), Pair(-8, -118), Pair(38, -124), Pair(-50, -123), Pair(38, -115),
        Pair(-58, -114), Pair(119, -173), Pair(-5, -108), Pair(-26, -111), Pair(49, -145), Pair(65, -95), Pair(52, -123), Pair(93, -165)
      },
      { // Piece 4
        Pair(-44, -114), Pair(59, -77), Pair(-91, -149), Pair(-73, -173), Pair(-173, -50), Pair(-56, -129), Pair(-163, -205), Pair(-132, -151),
        Pair(-100, -157), Pair(-41, -80), Pair(-12, 0), Pair(-26, -58), Pair(17, 12), Pair(-62, -94), Pair(-75, -139), Pair(-28, -112),
        Pair(-41, -103), Pair(-39, -198), Pair(-24, -81), Pair(-73, -154), Pair(-22, -54), Pair(-30, -173), Pair(-52, -86), Pair(33, -53),
        Pair(-92, -148), Pair(-61, -143), Pair(-34, -103), Pair(-46, -68), Pair(-20, -78), Pair(-24, -36), Pair(-26, -55), Pair(-43, -80),
        Pair(-65, -109), Pair(8, -19), Pair(-39, -48), Pair(47, 73), Pair(45, -4), Pair(-47, -61), Pair(3, -34), Pair(-56, -117),
        Pair(-61, -129), Pair(-60, -168), Pair(59, 8), Pair(2, -71), Pair(33, 16), Pair(-22, -56), Pair(-73, -106), Pair(-4, 11),
        Pair(-83, -187), Pair(-109, -185), Pair(-70, -130), Pair(20, 24), Pair(-51, -36), Pair(1, -42), Pair(-17, -77), Pair(0, -60),
        Pair(-30, -81), Pair(-68, -181), Pair(-8, -67), Pair(-28, -21), Pair(-13, -43), Pair(-25, -106), Pair(-14, -111), Pair(-18, -85)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-26, 43), Pair(40, 8), Pair(-113, 61), Pair(-40, 69), Pair(-1, 61), Pair(-4, 61), Pair(13, 29), Pair(-131, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 4
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(141, -52), Pair(181, -15), Pair(68, 64), Pair(51, 16), Pair(-26, 73), Pair(23, -21), Pair(35, -133), Pair(-14, -85),
        Pair(91, 48), Pair(63, 61), Pair(-1, 74), Pair(59, 20), Pair(-36, 50), Pair(167, 5), Pair(179, -9), Pair(43, -11),
        Pair(-73, 71), Pair(22, 40), Pair(-5, 31), Pair(24, -11), Pair(11, 6), Pair(73, -7), Pair(58, -1), Pair(49, 2),
        Pair(-51, 33), Pair(-54, 52), Pair(-7, 20), Pair(12, -1), Pair(4, -7), Pair(45, -10), Pair(-17, 22), Pair(-36, 1),
        Pair(-38, 13), Pair(19, 13), Pair(-24, -7), Pair(27, -9), Pair(31, -8), Pair(20, -14), Pair(18, 6), Pair(-30, -3),
        Pair(-81, 44), Pair(-20, 27), Pair(-23, 11), Pair(18, 7), Pair(-24, 23), Pair(-2, 4), Pair(18, -5), Pair(-24, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-150, -13), Pair(-59, -81), Pair(-127, 71), Pair(39, 24), Pair(4, 14), Pair(16, -79), Pair(-52, -155), Pair(-32, -48),
        Pair(-131, 11), Pair(-109, 82), Pair(79, -15), Pair(28, 7), Pair(79, -6), Pair(29, 40), Pair(-21, 31), Pair(73, -44),
        Pair(-58, -28), Pair(-37, -14), Pair(65, 4), Pair(95, 26), Pair(183, -28), Pair(74, -22), Pair(38, 26), Pair(36, 20),
        Pair(-28, 5), Pair(-41, 20), Pair(50, 25), Pair(103, 16), Pair(81, 25), Pair(104, 21), Pair(71, 35), Pair(123, -35),
        Pair(-115, -8), Pair(25, 21), Pair(-6, 44), Pair(38, 45), Pair(80, 15), Pair(58, 31), Pair(65, 0), Pair(111, -62),
        Pair(-51, -36), Pair(-56, 57), Pair(-13, 20), Pair(34, 20), Pair(16, 26), Pair(86, -8), Pair(60, -25), Pair(-35, -6),
        Pair(-115, -76), Pair(-127, -2), Pair(38, -41), Pair(-79, 55), Pair(-50, 19), Pair(25, -17), Pair(29, -36), Pair(10, -76),
        Pair(-11, 5), Pair(-154, -65), Pair(-152, 15), Pair(-31, -19), Pair(-30, 3), Pair(-157, -34), Pair(-93, 32), Pair(-41, -53)
      },
      { // Piece 2
        Pair(-223, -10), Pair(-7, -89), Pair(-51, -27), Pair(-23, 53), Pair(-49, -13), Pair(62, -10), Pair(-6, 22), Pair(53, 53),
        Pair(9, -31), Pair(-80, 12), Pair(60, 29), Pair(-86, -27), Pair(-12, 15), Pair(79, -41), Pair(-103, 80), Pair(-171, 39),
        Pair(-105, -12), Pair(-60, 53), Pair(118, -26), Pair(38, -2), Pair(34, 40), Pair(57, 25), Pair(68, -1), Pair(34, -7),
        Pair(-74, 24), Pair(42, -19), Pair(47, -7), Pair(76, -21), Pair(64, 4), Pair(15, -17), Pair(121, 1), Pair(-51, 46),
        Pair(25, 29), Pair(17, -15), Pair(69, -21), Pair(30, 3), Pair(27, 2), Pair(-32, 21), Pair(-25, 8), Pair(15, -2),
        Pair(-94, 54), Pair(-13, 21), Pair(8, -3), Pair(-24, 9), Pair(41, 5), Pair(79, -50), Pair(-42, -15), Pair(-39, -22),
        Pair(67, 9), Pair(-126, 28), Pair(-2, -11), Pair(-21, 16), Pair(-29, -26), Pair(-100, 13), Pair(-11, -36), Pair(144, -104),
        Pair(-97, 48), Pair(-102, 47), Pair(-107, 32), Pair(-29, -39), Pair(-81, 33), Pair(-39, -23), Pair(13, -100), Pair(5, 76)
      },
      { // Piece 3
        Pair(11, 40), Pair(-52, 84), Pair(-19, 35), Pair(23, 46), Pair(107, 2), Pair(-17, 46), Pair(-3, 73), Pair(-21, 97),
        Pair(-55, 60), Pair(33, 37), Pair(73, 9), Pair(29, 27), Pair(89, 1), Pair(59, 31), Pair(145, -30), Pair(86, -11),
        Pair(-74, 54), Pair(17, 27), Pair(5, 30), Pair(75, 12), Pair(135, -27), Pair(62, -17), Pair(40, 36), Pair(16, 13),
        Pair(-63, 57), Pair(-124, 63), Pair(-28, 49), Pair(-15, 33), Pair(63, 10), Pair(48, 5), Pair(1, 8), Pair(-66, 40),
        Pair(-74, 6), Pair(-40, 20), Pair(25, -3), Pair(-42, 24), Pair(46, -26), Pair(55, -21), Pair(-56, 28), Pair(-101, 46),
        Pair(-151, 17), Pair(-23, 26), Pair(-117, 38), Pair(-19, 13), Pair(-115, 38), Pair(-40, -6), Pair(-47, 14), Pair(-50, -14),
        Pair(-195, 9), Pair(-247, 60), Pair(-21, -25), Pair(-109, 25), Pair(-50, -13), Pair(-20, -13), Pair(-18, -7), Pair(-212, 86),
        Pair(-123, 32), Pair(-127, 39), Pair(-30, -8), Pair(-87, 15), Pair(-64, 3), Pair(-33, -11), Pair(-63, 12), Pair(-129, 12)
      },
      { // Piece 4
        Pair(-17, 1), Pair(-134, 6), Pair(35, -18), Pair(100, -52), Pair(-27, -25), Pair(21, -7), Pair(-15, 16), Pair(-6, 3),
        Pair(-147, -4), Pair(-117, 11), Pair(-97, -40), Pair(-213, 120), Pair(-124, 111), Pair(-81, 27), Pair(44, 36), Pair(-75, 125),
        Pair(-161, -90), Pair(-252, 56), Pair(122, -50), Pair(-180, 12), Pair(-53, 17), Pair(76, 5), Pair(-47, 12), Pair(48, -54),
        Pair(-208, -24), Pair(-164, 30), Pair(-172, 16), Pair(-93, 37), Pair(-118, 27), Pair(-21, 8), Pair(12, 2), Pair(-14, -115),
        Pair(-156, -54), Pair(-142, 4), Pair(-180, -11), Pair(-116, 38), Pair(-47, -13), Pair(-130, 24), Pair(-101, -6), Pair(55, -202),
        Pair(-196, -25), Pair(-100, -70), Pair(-128, -8), Pair(-166, 70), Pair(-94, -27), Pair(-35, -50), Pair(-52, -118), Pair(-35, -62),
        Pair(-304, -18), Pair(-112, -22), Pair(-140, 18), Pair(-98, 1), Pair(-139, -47), Pair(-73, -111), Pair(-139, -12), Pair(-146, -24),
        Pair(-281, -66), Pair(-32, -116), Pair(-160, -39), Pair(-95, -78), Pair(-113, -123), Pair(-174, -37), Pair(-121, -4), Pair(-89, -56)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, -41), Pair(71, -28), Pair(51, -13), Pair(-100, 30), Pair(-65, 16), Pair(-56, 2), Pair(19, -26), Pair(-85, -43),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-59, 50), Pair(75, 45), Pair(307, -130), Pair(161, -117), Pair(138, -104), Pair(200, -138), Pair(69, 111), Pair(-91, 39),
        Pair(-21, 70), Pair(89, 28), Pair(150, -23), Pair(50, -15), Pair(63, -19), Pair(196, -14), Pair(133, -13), Pair(89, 45),
        Pair(-135, 68), Pair(-24, 34), Pair(-16, 20), Pair(-14, 3), Pair(10, 10), Pair(54, -6), Pair(44, 8), Pair(16, 4),
        Pair(-47, 31), Pair(-47, 38), Pair(-30, 13), Pair(-16, 15), Pair(1, 13), Pair(75, -17), Pair(-18, 12), Pair(-98, 23),
        Pair(-121, 44), Pair(-38, 26), Pair(-35, 11), Pair(-103, 14), Pair(-14, -1), Pair(-57, 10), Pair(15, 6), Pair(-30, 12),
        Pair(-150, 47), Pair(-11, 21), Pair(-37, 11), Pair(-43, 0), Pair(17, 17), Pair(-38, 10), Pair(4, -2), Pair(-77, 27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-173, -71), Pair(-10, -36), Pair(77, 60), Pair(-18, 2), Pair(17, -68), Pair(-32, -1), Pair(41, -38), Pair(-298, -143),
        Pair(-44, 11), Pair(-69, 28), Pair(42, -18), Pair(-50, 5), Pair(-14, -26), Pair(-17, -4), Pair(98, 60), Pair(18, 1),
        Pair(51, -67), Pair(-71, 7), Pair(26, 13), Pair(103, 0), Pair(144, 23), Pair(178, -3), Pair(126, -31), Pair(130, -2),
        Pair(21, -7), Pair(38, -6), Pair(30, 10), Pair(139, 6), Pair(50, 33), Pair(100, 15), Pair(99, 9), Pair(78, -15),
        Pair(-85, -9), Pair(-51, 39), Pair(13, 37), Pair(31, 48), Pair(41, 27), Pair(22, -6), Pair(50, -2), Pair(39, -47),
        Pair(-98, -4), Pair(-200, 43), Pair(37, -7), Pair(-17, 29), Pair(-53, 34), Pair(-17, 22), Pair(-45, 11), Pair(-65, -22),
        Pair(-68, -72), Pair(26, 49), Pair(-76, -17), Pair(-88, 16), Pair(-32, 39), Pair(-28, -5), Pair(7, 0), Pair(-73, -49),
        Pair(-54, 8), Pair(-133, 52), Pair(-106, 57), Pair(36, -71), Pair(-167, -25), Pair(7, -62), Pair(-64, -16), Pair(-43, -24)
      },
      { // Piece 2
        Pair(100, -58), Pair(-106, -11), Pair(-26, -43), Pair(-30, -15), Pair(52, 8), Pair(-9, -64), Pair(-90, 46), Pair(135, -31),
        Pair(-48, 28), Pair(75, 10), Pair(-37, -51), Pair(-76, -21), Pair(-7, -51), Pair(144, 20), Pair(24, -29), Pair(111, -27),
        Pair(-19, -12), Pair(28, -2), Pair(84, -11), Pair(61, -29), Pair(145, -49), Pair(95, -13), Pair(130, -17), Pair(-14, -2),
        Pair(-43, -15), Pair(10, -23), Pair(89, -62), Pair(112, -13), Pair(139, -30), Pair(141, -30), Pair(21, 3), Pair(-19, -16),
        Pair(-14, -44), Pair(154, -39), Pair(74, -24), Pair(75, -16), Pair(157, -13), Pair(58, -56), Pair(167, -69), Pair(-78, -19),
        Pair(-57, 4), Pair(-45, 28), Pair(102, -44), Pair(50, -14), Pair(43, -5), Pair(-8, 11), Pair(92, -39), Pair(-115, -32),
        Pair(-156, 27), Pair(-18, -23), Pair(27, 34), Pair(-39, -21), Pair(-90, -3), Pair(-24, -22), Pair(25, -14), Pair(71, 10),
        Pair(32, 11), Pair(-42, 22), Pair(7, -66), Pair(-52, -1), Pair(20, 7), Pair(-124, 16), Pair(-100, -80), Pair(-36, 13)
      },
      { // Piece 3
        Pair(14, 28), Pair(27, 30), Pair(-28, -13), Pair(111, 1), Pair(27, 78), Pair(13, -15), Pair(68, 39), Pair(7, -14),
        Pair(108, -1), Pair(86, 6), Pair(135, -18), Pair(174, -27), Pair(226, -20), Pair(37, 24), Pair(50, 1), Pair(71, 0),
        Pair(150, -16), Pair(93, -3), Pair(72, -9), Pair(75, -18), Pair(11, -1), Pair(116, -58), Pair(21, -1), Pair(55, 13),
        Pair(-5, 30), Pair(-56, 20), Pair(-66, 9), Pair(57, -15), Pair(15, -18), Pair(-34, -14), Pair(-9, -8), Pair(-103, 17),
        Pair(-14, -9), Pair(-134, 13), Pair(-6, -9), Pair(-36, 8), Pair(-66, 3), Pair(-175, 20), Pair(-34, 18), Pair(-72, -8),
        Pair(-70, -14), Pair(-6, -36), Pair(-162, 21), Pair(-112, -23), Pair(-67, -26), Pair(-21, -37), Pair(-183, -11), Pair(-97, 11),
        Pair(-77, -22), Pair(-58, -13), Pair(-17, -15), Pair(-160, 37), Pair(-102, -26), Pair(-54, -39), Pair(-84, -24), Pair(-98, -6),
        Pair(-45, -54), Pair(-60, -2), Pair(-128, 2), Pair(-108, -17), Pair(24, -61), Pair(-61, 2), Pair(-57, -37), Pair(-56, -29)
      },
      { // Piece 4
        Pair(-178, 95), Pair(-48, 40), Pair(-35, 3), Pair(58, 69), Pair(9, 16), Pair(77, 138), Pair(-30, -16), Pair(30, 22),
        Pair(-12, -23), Pair(-40, -64), Pair(-109, 153), Pair(-4, 13), Pair(-44, -8), Pair(-35, -50), Pair(-14, -39), Pair(115, -168),
        Pair(12, -63), Pair(-76, -26), Pair(88, -69), Pair(-109, 83), Pair(251, -71), Pair(71, -39), Pair(-38, 62), Pair(42, -49),
        Pair(8, -69), Pair(-43, 95), Pair(-103, -5), Pair(-9, 37), Pair(-15, 45), Pair(-98, -48), Pair(35, -80), Pair(75, -86),
        Pair(-290, 0), Pair(-50, 13), Pair(-118, 14), Pair(7, -13), Pair(-70, 35), Pair(-53, 18), Pair(75, -101), Pair(-59, -116),
        Pair(-135, -45), Pair(-105, -13), Pair(-127, -39), Pair(-11, -72), Pair(-60, 4), Pair(-9, -27), Pair(-130, 19), Pair(-83, -84),
        Pair(-53, -75), Pair(-108, -62), Pair(-111, -118), Pair(-86, -89), Pair(-1, -35), Pair(-175, 6), Pair(-174, 3), Pair(-90, -145),
        Pair(-130, -126), Pair(-135, -79), Pair(-130, -88), Pair(-164, -134), Pair(-118, -28), Pair(-41, -54), Pair(-73, -126), Pair(16, -68)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, -66), Pair(136, -52), Pair(-20, 0), Pair(-76, 28), Pair(-14, 10), Pair(-1, -11), Pair(9, -32), Pair(-72, -58),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(145, -72), Pair(170, -55), Pair(55, -10), Pair(56, -42), Pair(23, -36), Pair(19, -59), Pair(136, -78), Pair(243, -75),
        Pair(99, 16), Pair(103, 33), Pair(91, 7), Pair(118, -26), Pair(135, -31), Pair(152, -18), Pair(70, 5), Pair(-46, 40),
        Pair(-16, 37), Pair(17, 27), Pair(-2, 11), Pair(-11, 5), Pair(14, 8), Pair(9, 4), Pair(23, 9), Pair(-4, 4),
        Pair(-61, 34), Pair(-20, 32), Pair(-25, 11), Pair(-21, 10), Pair(-3, 7), Pair(21, -2), Pair(1, 11), Pair(-62, 11),
        Pair(-60, 21), Pair(-19, 14), Pair(-6, 4), Pair(33, -8), Pair(28, -7), Pair(-28, 5), Pair(-28, 14), Pair(-66, 9),
        Pair(-77, 34), Pair(-52, 24), Pair(-12, 2), Pair(-12, -1), Pair(-18, 20), Pair(-12, 2), Pair(-8, 13), Pair(-72, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-70, -158), Pair(-9, -53), Pair(-57, -41), Pair(-36, -32), Pair(132, -80), Pair(44, -27), Pair(-15, -23), Pair(-150, -175),
        Pair(14, -41), Pair(13, -24), Pair(-74, -19), Pair(54, -37), Pair(109, -54), Pair(14, -30), Pair(-103, -7), Pair(38, -81),
        Pair(-79, -10), Pair(13, -42), Pair(52, -11), Pair(40, -11), Pair(107, -32), Pair(117, -18), Pair(74, -25), Pair(-22, -53),
        Pair(-42, -27), Pair(59, -25), Pair(80, -14), Pair(126, -22), Pair(93, -4), Pair(111, -16), Pair(63, -23), Pair(117, -45),
        Pair(-20, -29), Pair(-60, 6), Pair(53, -8), Pair(32, 8), Pair(103, -15), Pair(77, -6), Pair(-28, 12), Pair(9, -20),
        Pair(-157, -8), Pair(-16, -27), Pair(15, -16), Pair(31, -9), Pair(29, -2), Pair(45, -27), Pair(-6, -29), Pair(-55, -21),
        Pair(-68, -20), Pair(-95, -32), Pair(-60, -24), Pair(-43, -24), Pair(38, -21), Pair(-42, 6), Pair(-20, -19), Pair(-103, -9),
        Pair(-87, -30), Pair(-269, 9), Pair(-113, -3), Pair(-102, -8), Pair(-101, -32), Pair(-114, 8), Pair(-185, -51), Pair(-107, 1)
      },
      { // Piece 2
        Pair(-18, -55), Pair(-42, -43), Pair(3, -45), Pair(-46, -18), Pair(59, -62), Pair(-29, -49), Pair(84, -50), Pair(-33, -62),
        Pair(-46, -34), Pair(107, -53), Pair(23, -52), Pair(2, -75), Pair(18, -40), Pair(80, -74), Pair(40, -53), Pair(56, -39),
        Pair(9, -17), Pair(82, -52), Pair(132, -60), Pair(50, -44), Pair(185, -80), Pair(118, -40), Pair(26, -41), Pair(63, -51),
        Pair(-16, -37), Pair(49, -50), Pair(83, -50), Pair(118, -51), Pair(166, -60), Pair(141, -49), Pair(164, -64), Pair(21, -39),
        Pair(-112, -22), Pair(-6, -51), Pair(57, -61), Pair(68, -46), Pair(97, -62), Pair(60, -49), Pair(28, -66), Pair(60, -79),
        Pair(-10, -35), Pair(55, -48), Pair(72, -43), Pair(56, -43), Pair(54, -46), Pair(3, -41), Pair(3, -27), Pair(-21, -30),
        Pair(-6, -22), Pair(29, -52), Pair(120, -69), Pair(16, -44), Pair(5, -51), Pair(-11, -59), Pair(4, -59), Pair(-50, -59),
        Pair(-57, -37), Pair(-63, -29), Pair(-107, -27), Pair(-23, -53), Pair(-34, -45), Pair(-49, -39), Pair(-33, -67), Pair(54, -29)
      },
      { // Piece 3
        Pair(6, -15), Pair(18, -7), Pair(-42, -4), Pair(-20, -10), Pair(10, -25), Pair(118, -67), Pair(76, -41), Pair(137, -48),
        Pair(6, -34), Pair(55, -41), Pair(28, -38), Pair(59, -34), Pair(46, -55), Pair(-96, -19), Pair(15, -41), Pair(-51, -41),
        Pair(46, -55), Pair(117, -69), Pair(82, -63), Pair(116, -75), Pair(88, -66), Pair(79, -54), Pair(113, -65), Pair(70, -46),
        Pair(5, -42), Pair(19, -37), Pair(4, -38), Pair(31, -50), Pair(43, -48), Pair(55, -54), Pair(101, -66), Pair(-16, -36),
        Pair(-33, -57), Pair(-28, -33), Pair(30, -70), Pair(-67, -38), Pair(-25, -47), Pair(-41, -42), Pair(-34, -34), Pair(-50, -33),
        Pair(-115, -48), Pair(-82, -39), Pair(-140, -20), Pair(-58, -55), Pair(-70, -50), Pair(-43, -71), Pair(-78, -54), Pair(-134, -33),
        Pair(-257, -8), Pair(-133, -46), Pair(-48, -66), Pair(-87, -58), Pair(-49, -71), Pair(-38, -69), Pair(-84, -60), Pair(-160, -16),
        Pair(-99, -51), Pair(-66, -53), Pair(-81, -50), Pair(-77, -43), Pair(-47, -58), Pair(-48, -49), Pair(-149, -20), Pair(-100, -48)
      },
      { // Piece 4
        Pair(-49, -104), Pair(14, -148), Pair(-119, -66), Pair(-81, -68), Pair(-47, -103), Pair(-62, -50), Pair(20, -60), Pair(-187, 14),
        Pair(-80, -89), Pair(-63, -93), Pair(-133, -65), Pair(-145, -95), Pair(-51, -101), Pair(-114, -55), Pair(-120, 86), Pair(-17, -101),
        Pair(-85, -173), Pair(-102, -107), Pair(-115, -65), Pair(-94, -43), Pair(-39, -95), Pair(-30, -55), Pair(-82, -34), Pair(-5, -109),
        Pair(-187, -86), Pair(-107, -107), Pair(-117, -53), Pair(-51, -53), Pair(53, -79), Pair(-49, -52), Pair(19, -100), Pair(57, -231),
        Pair(-109, -118), Pair(-137, -95), Pair(-222, 40), Pair(-123, -61), Pair(-34, -68), Pair(-51, -52), Pair(3, -139), Pair(-82, -180),
        Pair(-163, -89), Pair(-247, -8), Pair(-111, -52), Pair(-173, 26), Pair(-192, -13), Pair(-128, -86), Pair(-243, -30), Pair(-85, -202),
        Pair(-131, -105), Pair(-182, -96), Pair(-95, -141), Pair(-156, -53), Pair(-94, -91), Pair(-89, -26), Pair(-160, -102), Pair(-162, -64),
        Pair(-96, -217), Pair(-70, -230), Pair(-130, -204), Pair(-108, -169), Pair(-201, -4), Pair(-204, -85), Pair(-258, -207), Pair(-153, -107)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(4, -59), Pair(46, -28), Pair(45, -7), Pair(-69, 26), Pair(-37, 12), Pair(-14, -7), Pair(39, -35), Pair(-89, -52),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(135, -41), Pair(52, -18), Pair(33, -45), Pair(121, -89), Pair(113, -30), Pair(33, -52), Pair(93, -39), Pair(21, -23),
        Pair(-7, 39), Pair(111, 12), Pair(81, -9), Pair(48, -1), Pair(78, -13), Pair(92, -14), Pair(134, -6), Pair(71, 14),
        Pair(-18, 32), Pair(-45, 35), Pair(-2, 8), Pair(-6, 9), Pair(3, 7), Pair(41, 2), Pair(20, 17), Pair(-67, 22),
        Pair(-88, 32), Pair(-25, 33), Pair(-33, 21), Pair(-41, 29), Pair(-48, 29), Pair(0, 9), Pair(-14, 27), Pair(-71, 20),
        Pair(-59, 20), Pair(-48, 23), Pair(-32, 5), Pair(-4, 1), Pair(10, 2), Pair(3, 2), Pair(-37, 17), Pair(-62, 15),
        Pair(-87, 32), Pair(-79, 34), Pair(-31, 14), Pair(10, 1), Pair(-12, 5), Pair(-51, 18), Pair(-55, 26), Pair(-128, 34),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-183, -112), Pair(-7, -98), Pair(-173, 3), Pair(-83, -29), Pair(-30, -42), Pair(19, -36), Pair(-14, -8), Pair(-88, -169),
        Pair(-67, -56), Pair(-14, -37), Pair(-4, -33), Pair(7, -28), Pair(132, -40), Pair(-87, -41), Pair(-84, -44), Pair(14, -53),
        Pair(52, -73), Pair(-41, -34), Pair(46, -13), Pair(69, -30), Pair(7, -13), Pair(164, -47), Pair(55, -57), Pair(-66, -34),
        Pair(52, -53), Pair(58, -45), Pair(81, -38), Pair(83, -25), Pair(159, -30), Pair(103, -33), Pair(107, -53), Pair(98, -54),
        Pair(31, -42), Pair(12, -28), Pair(34, -19), Pair(44, -4), Pair(45, -10), Pair(26, -10), Pair(52, -40), Pair(-36, -8),
        Pair(-12, -35), Pair(-28, -29), Pair(55, -28), Pair(78, -27), Pair(47, -7), Pair(34, -24), Pair(-50, -9), Pair(-31, -4),
        Pair(-83, 7), Pair(-65, -9), Pair(-98, -34), Pair(35, -47), Pair(-122, 2), Pair(-7, -32), Pair(-74, -18), Pair(60, -104),
        Pair(-87, -49), Pair(-163, -12), Pair(-132, -41), Pair(-7, -18), Pair(-66, -31), Pair(-66, -17), Pair(-194, -43), Pair(-16, -62)
      },
      { // Piece 2
        Pair(44, -82), Pair(61, -43), Pair(11, -54), Pair(3, -64), Pair(-75, -53), Pair(8, -53), Pair(12, -45), Pair(-78, -64),
        Pair(-1, -49), Pair(60, -51), Pair(94, -71), Pair(64, -69), Pair(12, -46), Pair(-24, -58), Pair(13, -63), Pair(-90, -46),
        Pair(27, -58), Pair(89, -61), Pair(116, -59), Pair(150, -59), Pair(68, -77), Pair(114, -64), Pair(68, -69), Pair(66, -59),
        Pair(-73, -39), Pair(-8, -57), Pair(23, -50), Pair(130, -63), Pair(158, -63), Pair(131, -68), Pair(29, -55), Pair(-6, -49),
        Pair(30, -40), Pair(43, -58), Pair(75, -63), Pair(82, -62), Pair(58, -60), Pair(72, -66), Pair(20, -60), Pair(7, -52),
        Pair(-68, -34), Pair(11, -57), Pair(-70, -23), Pair(7, -46), Pair(49, -52), Pair(83, -63), Pair(48, -57), Pair(-48, -36),
        Pair(-27, -7), Pair(-58, -40), Pair(-38, -61), Pair(-6, -59), Pair(34, -58), Pair(-53, -53), Pair(-11, -66), Pair(-108, -40),
        Pair(-162, -44), Pair(-8, -66), Pair(-13, -71), Pair(-67, -38), Pair(-41, -52), Pair(-107, -40), Pair(-38, -67), Pair(-8, -37)
      },
      { // Piece 3
        Pair(0, -57), Pair(38, -55), Pair(7, -48), Pair(13, -55), Pair(-18, -38), Pair(168, -84), Pair(113, -72), Pair(83, -69),
        Pair(55, -77), Pair(14, -67), Pair(39, -73), Pair(60, -77), Pair(65, -70), Pair(130, -94), Pair(69, -76), Pair(65, -83),
        Pair(-18, -74), Pair(121, -99), Pair(15, -71), Pair(90, -101), Pair(65, -107), Pair(60, -78), Pair(80, -106), Pair(-86, -43),
        Pair(-69, -37), Pair(15, -57), Pair(42, -70), Pair(40, -68), Pair(99, -81), Pair(122, -99), Pair(142, -105), Pair(0, -68),
        Pair(-54, -79), Pair(-6, -72), Pair(-22, -55), Pair(-12, -59), Pair(-2, -71), Pair(14, -71), Pair(38, -85), Pair(-64, -53),
        Pair(-154, -63), Pair(-80, -62), Pair(-64, -82), Pair(-66, -76), Pair(-46, -62), Pair(-67, -65), Pair(-155, -31), Pair(-91, -78),
        Pair(-162, -55), Pair(-40, -87), Pair(-62, -81), Pair(-57, -87), Pair(-13, -97), Pair(-95, -71), Pair(-78, -78), Pair(-280, -16),
        Pair(-69, -74), Pair(-58, -83), Pair(-59, -76), Pair(-18, -92), Pair(-63, -70), Pair(-2, -94), Pair(-131, -73), Pair(-159, -44)
      },
      { // Piece 4
        Pair(-7, -69), Pair(-134, -92), Pair(-53, -40), Pair(-46, -103), Pair(-63, -48), Pair(-80, -50), Pair(-23, -135), Pair(-33, -89),
        Pair(-88, -156), Pair(-25, -118), Pair(-165, 22), Pair(-64, -32), Pair(97, -48), Pair(-46, -104), Pair(-58, -55), Pair(-91, -115),
        Pair(-28, -31), Pair(8, -65), Pair(-103, -54), Pair(-21, -63), Pair(-23, -111), Pair(7, -66), Pair(-28, -64), Pair(-5, -44),
        Pair(-79, -79), Pair(-139, -43), Pair(-13, 8), Pair(12, -27), Pair(35, -37), Pair(-66, -26), Pair(-57, -24), Pair(-48, -125),
        Pair(-83, -94), Pair(-11, -99), Pair(-2, -135), Pair(-92, -23), Pair(-49, -105), Pair(-63, -53), Pair(11, -76), Pair(-68, -124),
        Pair(-78, -195), Pair(-118, -159), Pair(-85, -38), Pair(-34, -60), Pair(-124, -83), Pair(-75, -66), Pair(-166, -79), Pair(-108, -150),
        Pair(-134, -208), Pair(-141, -92), Pair(-43, -81), Pair(-120, -88), Pair(-109, -52), Pair(-97, -120), Pair(17, -53), Pair(-119, -147),
        Pair(-21, -159), Pair(-84, -169), Pair(-107, -12), Pair(-124, -94), Pair(-72, -159), Pair(-83, -103), Pair(-64, -100), Pair(-102, -132)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-38, -48), Pair(98, -37), Pair(62, -4), Pair(-49, 26), Pair(-41, 14), Pair(-10, -4), Pair(36, -32), Pair(-79, -49),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-39, -37), Pair(161, -41), Pair(26, -68), Pair(50, -50), Pair(71, 22), Pair(-44, 12), Pair(-71, -8), Pair(-7, -3),
        Pair(-6, 31), Pair(78, 36), Pair(79, 23), Pair(49, -2), Pair(78, 1), Pair(60, 30), Pair(-1, 16), Pair(-13, 37),
        Pair(-72, 28), Pair(-46, 35), Pair(2, 20), Pair(-97, 31), Pair(-37, 23), Pair(112, -10), Pair(-20, 25), Pair(-57, 13),
        Pair(-36, 23), Pair(-78, 45), Pair(-56, 16), Pair(-42, 25), Pair(43, 7), Pair(25, 5), Pair(-58, 37), Pair(-71, 17),
        Pair(-68, 13), Pair(-109, 33), Pair(-78, 25), Pair(18, 6), Pair(-78, 31), Pair(-24, 6), Pair(-48, 25), Pair(-73, 19),
        Pair(-87, 27), Pair(-101, 31), Pair(-84, 29), Pair(-22, -44), Pair(-63, 17), Pair(-27, 15), Pair(-34, 27), Pair(-99, 36),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-94, -173), Pair(-22, -100), Pair(49, -148), Pair(30, -88), Pair(-6, -48), Pair(-63, -93), Pair(-74, -68), Pair(-69, -108),
        Pair(-87, -76), Pair(-47, -56), Pair(-15, -67), Pair(78, -81), Pair(7, -58), Pair(44, -74), Pair(41, -77), Pair(-89, -115),
        Pair(-6, -98), Pair(99, -92), Pair(67, -64), Pair(17, -39), Pair(57, -58), Pair(-29, -65), Pair(125, -124), Pair(49, -105),
        Pair(-14, -99), Pair(134, -104), Pair(13, -68), Pair(37, -67), Pair(144, -60), Pair(86, -47), Pair(88, -76), Pair(28, -38),
        Pair(-16, -12), Pair(16, -100), Pair(-27, -31), Pair(100, -53), Pair(40, -93), Pair(14, -69), Pair(73, -75), Pair(118, -63),
        Pair(-124, -114), Pair(17, -65), Pair(55, -53), Pair(-45, -35), Pair(30, -34), Pair(91, -66), Pair(-44, -62), Pair(44, -20),
        Pair(-83, -114), Pair(-24, -41), Pair(-110, -63), Pair(20, -72), Pair(-7, -62), Pair(-1, -99), Pair(-12, -41), Pair(-16, -27),
        Pair(-39, -76), Pair(-58, -33), Pair(-57, -97), Pair(-9, -66), Pair(10, -87), Pair(-29, -43), Pair(-9, -68), Pair(1, -97)
      },
      { // Piece 2
        Pair(-90, -75), Pair(-44, -32), Pair(41, -102), Pair(13, -65), Pair(-78, -47), Pair(18, -26), Pair(18, -81), Pair(-109, -75),
        Pair(-27, -53), Pair(39, -59), Pair(-89, -77), Pair(-34, -72), Pair(-68, -74), Pair(4, -77), Pair(1, -60), Pair(36, -121),
        Pair(70, -84), Pair(15, -87), Pair(11, -70), Pair(80, -81), Pair(28, -71), Pair(-12, -67), Pair(69, -78), Pair(42, -68),
        Pair(-128, -65), Pair(0, -56), Pair(71, -92), Pair(67, -71), Pair(168, -103), Pair(111, -83), Pair(118, -90), Pair(-4, -84),
        Pair(-94, -52), Pair(-8, -83), Pair(49, -90), Pair(39, -79), Pair(110, -84), Pair(82, -76), Pair(91, -117), Pair(-98, -54),
        Pair(-68, -35), Pair(52, -60), Pair(-17, -60), Pair(43, -92), Pair(-7, -50), Pair(-87, -66), Pair(25, -38), Pair(-73, -20),
        Pair(-130, -1), Pair(-139, -50), Pair(-71, -40), Pair(-5, -81), Pair(48, -84), Pair(11, -75), Pair(-88, -68), Pair(-118, -113),
        Pair(0, -44), Pair(-89, -54), Pair(-64, -64), Pair(-92, -35), Pair(-84, -74), Pair(-84, -42), Pair(20, -57), Pair(0, 28)
      },
      { // Piece 3
        Pair(27, -96), Pair(35, -102), Pair(56, -105), Pair(130, -116), Pair(86, -103), Pair(103, -104), Pair(32, -101), Pair(27, -100),
        Pair(-104, -77), Pair(1, -103), Pair(-26, -95), Pair(101, -120), Pair(0, -104), Pair(30, -129), Pair(44, -117), Pair(15, -141),
        Pair(16, -110), Pair(51, -129), Pair(74, -120), Pair(18, -117), Pair(48, -112), Pair(-23, -112), Pair(28, -131), Pair(-15, -97),
        Pair(-94, -110), Pair(32, -126), Pair(7, -94), Pair(51, -111), Pair(3, -137), Pair(81, -143), Pair(54, -129), Pair(-55, -73),
        Pair(-2, -132), Pair(-29, -101), Pair(-92, -69), Pair(10, -97), Pair(66, -163), Pair(-46, -91), Pair(52, -127), Pair(-79, -86),
        Pair(-60, -141), Pair(127, -140), Pair(-25, -119), Pair(-121, -99), Pair(-22, -104), Pair(-54, -124), Pair(28, -108), Pair(-57, -164),
        Pair(-97, -138), Pair(-165, -111), Pair(-65, -110), Pair(-37, -144), Pair(-64, -104), Pair(-64, -131), Pair(-113, -113), Pair(-61, -111),
        Pair(-155, -94), Pair(-85, -110), Pair(-57, -110), Pair(-102, -108), Pair(-32, -116), Pair(-16, -125), Pair(33, -152), Pair(-111, -103)
      },
      { // Piece 4
        Pair(36, -87), Pair(56, -125), Pair(-95, -110), Pair(-91, -75), Pair(12, -71), Pair(-100, -84), Pair(-45, -109), Pair(-57, -46),
        Pair(9, -30), Pair(-15, -110), Pair(27, -22), Pair(-12, -5), Pair(-17, 27), Pair(-58, -93), Pair(-33, -93), Pair(-61, -120),
        Pair(-74, -131), Pair(64, -60), Pair(-13, 12), Pair(22, 14), Pair(-38, -34), Pair(22, -74), Pair(-71, -65), Pair(-23, -59),
        Pair(-66, -120), Pair(-39, -64), Pair(-48, -112), Pair(-17, -39), Pair(49, 80), Pair(-10, -32), Pair(-12, -34), Pair(-40, -103),
        Pair(-92, -132), Pair(-48, -62), Pair(13, 66), Pair(-18, -47), Pair(-6, -2), Pair(-1, 17), Pair(-7, -16), Pair(-39, -77),
        Pair(-102, -198), Pair(17, 13), Pair(-3, -29), Pair(-16, -96), Pair(-16, 0), Pair(-22, -17), Pair(-12, -37), Pair(-77, -93),
        Pair(-46, -6), Pair(-90, -146), Pair(-27, -53), Pair(-32, -39), Pair(-64, -126), Pair(-144, -210), Pair(-59, -72), Pair(-27, -48),
        Pair(-16, -19), Pair(-42, -132), Pair(-65, -93), Pair(19, -22), Pair(-46, -96), Pair(12, -75), Pair(-34, -87), Pair(-72, -131)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(66, -51), Pair(50, -17), Pair(61, 11), Pair(-84, 46), Pair(-51, 35), Pair(1, 15), Pair(56, -12), Pair(-51, -33),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-103, -14), Pair(29, -21), Pair(-96, 13), Pair(-10, 5), Pair(19, -23), Pair(-124, 11), Pair(-50, -9), Pair(-122, 3),
        Pair(-144, 64), Pair(-37, 60), Pair(-9, 35), Pair(-27, 27), Pair(-29, 17), Pair(10, 33), Pair(-2, 40), Pair(-167, 73),
        Pair(-178, 53), Pair(-43, 24), Pair(-31, 21), Pair(6, 16), Pair(-58, 22), Pair(8, 20), Pair(-87, 39), Pair(-124, 38),
        Pair(-121, 32), Pair(-46, 36), Pair(-40, 25), Pair(-66, 32), Pair(-71, 33), Pair(40, 9), Pair(-64, 26), Pair(-141, 33),
        Pair(-128, 26), Pair(-113, 23), Pair(18, 7), Pair(-37, 4), Pair(-23, 10), Pair(-24, 21), Pair(-99, 34), Pair(-119, 25),
        Pair(-176, 45), Pair(-61, 31), Pair(-19, 22), Pair(16, -1), Pair(-17, 18), Pair(-97, 34), Pair(-115, 37), Pair(-78, 29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-44, -207), Pair(-64, -109), Pair(-63, -142), Pair(-39, -95), Pair(-34, -89), Pair(-52, -89), Pair(-12, -112), Pair(-48, -180),
        Pair(-84, -85), Pair(-69, -91), Pair(-7, -119), Pair(-43, -72), Pair(-32, -94), Pair(-1, -114), Pair(-55, -84), Pair(-24, -94),
        Pair(1, -128), Pair(47, -132), Pair(-34, -94), Pair(25, -78), Pair(21, -76), Pair(-20, -72), Pair(-2, -105), Pair(32, -155),
        Pair(-26, -114), Pair(89, -125), Pair(152, -115), Pair(89, -95), Pair(52, -101), Pair(47, -114), Pair(93, -98), Pair(43, -154),
        Pair(-15, -89), Pair(17, -61), Pair(47, -64), Pair(100, -95), Pair(111, -102), Pair(66, -90), Pair(2, -86), Pair(66, -145),
        Pair(-2, -86), Pair(25, -96), Pair(70, -96), Pair(28, -85), Pair(82, -88), Pair(93, -74), Pair(54, -100), Pair(50, -130),
        Pair(3, -85), Pair(50, -67), Pair(-83, -56), Pair(149, -117), Pair(-18, -65), Pair(-53, -70), Pair(-21, -77), Pair(48, -140),
        Pair(16, -47), Pair(-64, -133), Pair(-4, -63), Pair(45, -106), Pair(0, -105), Pair(45, -95), Pair(-55, -141), Pair(24, -103)
      },
      { // Piece 2
        Pair(-48, -65), Pair(-115, -57), Pair(25, -67), Pair(-53, -88), Pair(-101, -61), Pair(-116, -90), Pair(-1, -93), Pair(-7, -93),
        Pair(-87, -74), Pair(27, -86), Pair(-56, -85), Pair(-83, -70), Pair(-111, -51), Pair(-52, -74), Pair(5, -72), Pair(-50, -66),
        Pair(-42, -89), Pair(-64, -66), Pair(0, -72), Pair(-97, -57), Pair(-117, -38), Pair(22, -75), Pair(-76, -68), Pair(-7, -72),
        Pair(-65, -77), Pair(-32, -71), Pair(-118, -56), Pair(12, -72), Pair(-19, -65), Pair(-7, -75), Pair(-66, -47), Pair(-66, -73),
        Pair(-73, -63), Pair(-66, -74), Pair(-17, -84), Pair(-17, -74), Pair(-29, -74), Pair(6, -91), Pair(-13, -81), Pair(-19, -77),
        Pair(44, -83), Pair(-85, -46), Pair(-37, -72), Pair(-82, -66), Pair(-6, -77), Pair(-36, -64), Pair(-143, -60), Pair(-62, -93),
        Pair(-53, -87), Pair(-90, -75), Pair(-28, -91), Pair(-52, -75), Pair(-125, -58), Pair(-35, -44), Pair(-130, -80), Pair(4, -119),
        Pair(-96, -95), Pair(-76, -41), Pair(-24, -44), Pair(-8, -40), Pair(-90, -69), Pair(-59, -49), Pair(-35, -34), Pair(24, -58)
      },
      { // Piece 3
        Pair(91, -173), Pair(9, -154), Pair(102, -167), Pair(34, -118), Pair(-2, -116), Pair(-79, -135), Pair(-5, -128), Pair(-81, -121),
        Pair(-46, -162), Pair(66, -197), Pair(83, -162), Pair(54, -160), Pair(-8, -137), Pair(24, -152), Pair(40, -173), Pair(115, -181),
        Pair(6, -160), Pair(1, -130), Pair(21, -147), Pair(59, -175), Pair(-1, -146), Pair(61, -153), Pair(65, -164), Pair(35, -163),
        Pair(68, -177), Pair(20, -157), Pair(52, -152), Pair(-3, -133), Pair(5, -167), Pair(115, -175), Pair(64, -166), Pair(85, -173),
        Pair(-26, -184), Pair(-104, -122), Pair(-10, -172), Pair(12, -179), Pair(59, -154), Pair(51, -200), Pair(-2, -158), Pair(-32, -167),
        Pair(-23, -178), Pair(-76, -143), Pair(-33, -159), Pair(40, -160), Pair(-33, -149), Pair(-151, -117), Pair(25, -139), Pair(83, -193),
        Pair(-124, -122), Pair(37, -169), Pair(11, -157), Pair(-45, -140), Pair(20, -180), Pair(-19, -143), Pair(-31, -120), Pair(-93, -149),
        Pair(-51, -171), Pair(57, -164), Pair(-91, -151), Pair(-44, -128), Pair(9, -169), Pair(-74, -127), Pair(-81, -131), Pair(-26, -166)
      },
      { // Piece 4
        Pair(-93, -214), Pair(-79, -140), Pair(8, -189), Pair(-14, -94), Pair(1, -182), Pair(-100, -124), Pair(-19, -149), Pair(-63, -182),
        Pair(-74, -172), Pair(-64, -97), Pair(10, -91), Pair(-63, -53), Pair(37, -65), Pair(-92, -73), Pair(-65, -180), Pair(-119, -205),
        Pair(-132, -186), Pair(-38, -76), Pair(-62, -102), Pair(23, -68), Pair(-51, -110), Pair(20, -53), Pair(-65, -32), Pair(-25, -84),
        Pair(-75, -135), Pair(-4, -134), Pair(-78, -35), Pair(-29, -128), Pair(-22, -98), Pair(-30, -44), Pair(-87, -129), Pair(-52, -57),
        Pair(12, -18), Pair(-47, -126), Pair(-94, -64), Pair(-72, -79), Pair(-75, -107), Pair(-53, -95), Pair(-53, -116), Pair(-6, -5),
        Pair(-48, -100), Pair(-53, -154), Pair(-95, -168), Pair(-20, -45), Pair(0, -17), Pair(-16, -67), Pair(-22, -47), Pair(-22, -74),
        Pair(19, -73), Pair(3, -18), Pair(-57, -128), Pair(-68, -162), Pair(-67, -134), Pair(-29, -57), Pair(-61, -139), Pair(-9, -57),
        Pair(-105, -221), Pair(-22, -53), Pair(-104, -239), Pair(-17, -119), Pair(-68, -109), Pair(-21, -155), Pair(-59, -107), Pair(-45, -109)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(29, -52), Pair(101, -20), Pair(2, 18), Pair(-52, 43), Pair(-40, 32), Pair(30, 8), Pair(8, -5), Pair(-85, -30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-167, 45), Pair(-94, 49), Pair(-23, 46), Pair(-28, 6), Pair(-100, 45), Pair(-101, -10), Pair(-29, 125), Pair(-172, 61),
        Pair(-147, 87), Pair(-18, 74), Pair(-49, 42), Pair(-36, 82), Pair(-30, 63), Pair(13, 106), Pair(-25, 111), Pair(-100, 74),
        Pair(-110, 58), Pair(-12, 64), Pair(-166, 58), Pair(-128, 51), Pair(-88, 62), Pair(63, 28), Pair(-63, 67), Pair(-150, 57),
        Pair(-43, 29), Pair(-88, 34), Pair(-34, 42), Pair(-76, 37), Pair(8, 30), Pair(5, 29), Pair(-155, 39), Pair(-210, 39),
        Pair(-103, 18), Pair(2, 9), Pair(-48, 5), Pair(-122, 31), Pair(-121, 14), Pair(4, 8), Pair(-70, 49), Pair(-108, 24),
        Pair(-74, 7), Pair(-100, 73), Pair(75, 10), Pair(-21, 6), Pair(-30, 21), Pair(-30, 46), Pair(-42, 25), Pair(-113, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-27, -259), Pair(-42, -136), Pair(-3, -31), Pair(16, -74), Pair(-8, -46), Pair(-18, -89), Pair(-21, -56), Pair(-2, -12),
        Pair(-8, -200), Pair(2, -149), Pair(-37, -61), Pair(-15, -108), Pair(-11, -66), Pair(-5, -141), Pair(-60, -68), Pair(-11, -124),
        Pair(-49, -117), Pair(-66, -105), Pair(41, -129), Pair(-67, -44), Pair(2, -41), Pair(75, -88), Pair(39, -71), Pair(-38, -134),
        Pair(24, -44), Pair(-16, -161), Pair(39, -53), Pair(94, -81), Pair(-3, -16), Pair(100, -81), Pair(5, -71), Pair(-62, -120),
        Pair(-48, -78), Pair(-3, -85), Pair(14, 28), Pair(185, -102), Pair(0, -59), Pair(62, -71), Pair(5, -19), Pair(36, -47),
        Pair(-16, -127), Pair(0, -17), Pair(-71, 29), Pair(42, -95), Pair(58, -32), Pair(6, -85), Pair(38, -64), Pair(21, -108),
        Pair(2, -28), Pair(11, -24), Pair(-35, -96), Pair(12, -75), Pair(25, -69), Pair(-30, -91), Pair(5, -47), Pair(-20, -38),
        Pair(-2, -93), Pair(-13, -90), Pair(-28, -98), Pair(6, -94), Pair(28, -39), Pair(-4, -221), Pair(-29, -59), Pair(-19, -39)
      },
      { // Piece 2
        Pair(-1, -17), Pair(3, -11), Pair(-69, -22), Pair(-56, -20), Pair(3, -26), Pair(-35, -16), Pair(48, 22), Pair(-10, -13),
        Pair(16, 35), Pair(-21, -9), Pair(19, 16), Pair(-31, -97), Pair(-59, -33), Pair(30, 28), Pair(-86, 22), Pair(-40, -17),
        Pair(-23, -1), Pair(-62, -8), Pair(-103, 20), Pair(-37, 30), Pair(-63, -11), Pair(99, -43), Pair(9, -56), Pair(27, -118),
        Pair(9, 12), Pair(19, -64), Pair(0, 0), Pair(-58, 70), Pair(-28, -5), Pair(1, 0), Pair(-38, 11), Pair(-34, -22),
        Pair(-1, 44), Pair(-56, -44), Pair(20, -6), Pair(98, -33), Pair(-39, -47), Pair(-26, -29), Pair(39, -61), Pair(-15, 8),
        Pair(-109, -47), Pair(5, 12), Pair(41, -40), Pair(46, -35), Pair(-93, -47), Pair(-54, -27), Pair(15, -37), Pair(10, 17),
        Pair(-24, -38), Pair(8, -54), Pair(-33, 39), Pair(-31, -91), Pair(37, -41), Pair(-22, -28), Pair(32, -75), Pair(-6, -45),
        Pair(12, -17), Pair(-15, 54), Pair(-5, -33), Pair(-17, 46), Pair(10, -99), Pair(-4, -55), Pair(-8, -32), Pair(-5, -87)
      },
      { // Piece 3
        Pair(9, -69), Pair(25, -71), Pair(50, -100), Pair(-13, -73), Pair(-9, -93), Pair(38, -59), Pair(21, -75), Pair(-29, -95),
        Pair(48, -40), Pair(-96, -64), Pair(38, -78), Pair(-30, -125), Pair(98, -126), Pair(56, -93), Pair(4, -101), Pair(-1, -111),
        Pair(-34, -78), Pair(21, -87), Pair(-11, -76), Pair(-75, -83), Pair(-71, -81), Pair(-107, -85), Pair(-1, -129), Pair(30, -105),
        Pair(-49, -93), Pair(47, -127), Pair(41, -99), Pair(78, -135), Pair(18, -63), Pair(65, -119), Pair(1, -75), Pair(-44, -94),
        Pair(41, -70), Pair(-6, -91), Pair(-66, -59), Pair(9, -127), Pair(-11, -169), Pair(-98, -68), Pair(-8, -125), Pair(80, -115),
        Pair(-90, -148), Pair(-82, -34), Pair(-5, -124), Pair(52, -126), Pair(28, -129), Pair(33, -193), Pair(2, -165), Pair(5, -135),
        Pair(65, -116), Pair(35, -89), Pair(15, -147), Pair(62, -155), Pair(15, -157), Pair(-28, -102), Pair(13, -124), Pair(-10, -102),
        Pair(-74, -138), Pair(56, -148), Pair(-78, -108), Pair(-28, -153), Pair(1, -186), Pair(37, -87), Pair(136, -139), Pair(-4, -112)
      },
      { // Piece 4
        Pair(-110, -57), Pair(-96, -105), Pair(-27, 30), Pair(-65, -32), Pair(-32, -31), Pair(-131, -192), Pair(-31, -170), Pair(-84, -143),
        Pair(-28, -54), Pair(34, -13), Pair(-54, -131), Pair(-79, -111), Pair(-12, 52), Pair(-81, -131), Pair(7, -9), Pair(-89, -134),
        Pair(23, -57), Pair(-62, -167), Pair(69, 77), Pair(-50, -59), Pair(-38, -58), Pair(-25, -22), Pair(-95, -140), Pair(-61, -87),
        Pair(-19, -57), Pair(-72, -78), Pair(1, -29), Pair(-25, -63), Pair(26, 27), Pair(-32, -53), Pair(-42, -17), Pair(-29, 29),
        Pair(-7, -56), Pair(-45, -149), Pair(-43, -115), Pair(-11, -81), Pair(3, -46), Pair(36, -6), Pair(-51, -82), Pair(-32, -75),
        Pair(-52, -129), Pair(-41, -54), Pair(15, 24), Pair(1, -56), Pair(53, -1), Pair(-45, -31), Pair(-27, -73), Pair(-4, -66),
        Pair(-2, -18), Pair(-10, -34), Pair(-24, -70), Pair(-13, -59), Pair(26, 41), Pair(-75, -145), Pair(-28, -51), Pair(-7, -26),
        Pair(-48, -118), Pair(-63, -119), Pair(-41, -102), Pair(-53, -103), Pair(-39, -56), Pair(1, -63), Pair(17, 7), Pair(-55, -84)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-65, -16), Pair(22, 24), Pair(59, 43), Pair(14, 69), Pair(-22, 57), Pair(-5, 46), Pair(54, 19), Pair(-67, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 5
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(231, -75), Pair(253, -100), Pair(100, 57), Pair(50, 30), Pair(-157, 120), Pair(122, 20), Pair(53, -116), Pair(-13, -122),
        Pair(124, 6), Pair(120, 17), Pair(64, 73), Pair(-104, 110), Pair(26, 68), Pair(94, 10), Pair(216, -43), Pair(78, -50),
        Pair(-59, 48), Pair(-70, 68), Pair(4, 49), Pair(-75, 52), Pair(-8, 25), Pair(-6, 13), Pair(29, 14), Pair(-9, -10),
        Pair(-135, 46), Pair(-40, 37), Pair(-47, 29), Pair(-42, 10), Pair(-13, 9), Pair(-8, 6), Pair(-20, 24), Pair(-64, 5),
        Pair(-75, 15), Pair(-103, 37), Pair(2, -2), Pair(16, -7), Pair(-57, 11), Pair(-55, 7), Pair(-81, 22), Pair(-64, -5),
        Pair(-125, 31), Pair(-54, 36), Pair(-9, 19), Pair(-139, 46), Pair(-122, 83), Pair(-86, 21), Pair(7, 5), Pair(-100, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-125, -176), Pair(28, -36), Pair(76, -27), Pair(29, -103), Pair(-42, -34), Pair(-6, -54), Pair(-17, -87), Pair(-5, 10),
        Pair(72, -51), Pair(164, -42), Pair(53, -13), Pair(36, -15), Pair(282, -35), Pair(2, 45), Pair(-67, -59), Pair(-32, 27),
        Pair(40, -32), Pair(3, 0), Pair(97, -50), Pair(125, -46), Pair(204, -54), Pair(243, -67), Pair(148, -67), Pair(48, 1),
        Pair(-35, -89), Pair(62, -54), Pair(115, -47), Pair(150, -26), Pair(132, -30), Pair(230, -36), Pair(94, -33), Pair(146, -56),
        Pair(-149, 1), Pair(-57, -63), Pair(62, -15), Pair(75, -3), Pair(165, -42), Pair(67, -33), Pair(129, -47), Pair(53, -93),
        Pair(24, -81), Pair(-86, -27), Pair(105, -50), Pair(-90, 13), Pair(-40, 13), Pair(67, -57), Pair(49, -62), Pair(-101, -25),
        Pair(-74, -86), Pair(-142, -91), Pair(-23, -90), Pair(-92, -31), Pair(-113, -28), Pair(22, -35), Pair(54, -49), Pair(-53, -95),
        Pair(-58, -120), Pair(-80, -91), Pair(-148, -67), Pair(-109, 21), Pair(-44, -89), Pair(-36, -89), Pair(-220, -6), Pair(-72, -28)
      },
      { // Piece 2
        Pair(-51, -67), Pair(30, -70), Pair(-48, -70), Pair(-38, -108), Pair(-104, -47), Pair(-13, -90), Pair(145, -37), Pair(-12, -85),
        Pair(-99, -4), Pair(24, -87), Pair(58, -76), Pair(75, -112), Pair(122, -136), Pair(39, -104), Pair(-1, -70), Pair(66, -43),
        Pair(54, -121), Pair(4, -77), Pair(184, -116), Pair(124, -72), Pair(174, -90), Pair(267, -81), Pair(282, -102), Pair(87, -55),
        Pair(-90, -68), Pair(8, -33), Pair(111, -74), Pair(154, -85), Pair(109, -51), Pair(169, -104), Pair(76, -60), Pair(-4, -71),
        Pair(-25, -25), Pair(16, -100), Pair(121, -90), Pair(161, -90), Pair(244, -109), Pair(28, -52), Pair(155, -102), Pair(-7, -63),
        Pair(-16, -63), Pair(122, -65), Pair(78, -72), Pair(80, -52), Pair(135, -82), Pair(109, -113), Pair(173, -76), Pair(3, -129),
        Pair(82, -93), Pair(-85, -70), Pair(86, -105), Pair(23, -83), Pair(-25, -90), Pair(-118, -62), Pair(-26, -126), Pair(-59, -91),
        Pair(-79, -35), Pair(11, -43), Pair(-110, -39), Pair(-33, -70), Pair(-101, -46), Pair(-113, -87), Pair(-52, -68), Pair(8, -60)
      },
      { // Piece 3
        Pair(25, -17), Pair(-93, 16), Pair(-56, 24), Pair(25, -4), Pair(-92, 13), Pair(60, 6), Pair(8, 12), Pair(7, 20),
        Pair(95, -48), Pair(14, -32), Pair(113, -41), Pair(199, -84), Pair(130, -70), Pair(71, -52), Pair(69, -34), Pair(156, -46),
        Pair(-12, -31), Pair(76, -65), Pair(47, -59), Pair(82, -65), Pair(88, -53), Pair(90, -78), Pair(144, -93), Pair(-94, -36),
        Pair(-20, -38), Pair(-16, -13), Pair(-13, -12), Pair(103, -44), Pair(-64, -52), Pair(127, -89), Pair(-21, -67), Pair(62, -60),
        Pair(-174, -1), Pair(-14, -36), Pair(-56, -22), Pair(-15, -67), Pair(-37, -56), Pair(3, -58), Pair(-32, -4), Pair(-79, -10),
        Pair(-188, -38), Pair(-91, -32), Pair(-106, -64), Pair(5, -54), Pair(-47, -55), Pair(-71, -28), Pair(-36, -50), Pair(-170, 16),
        Pair(-177, -1), Pair(-212, 2), Pair(-89, -14), Pair(-66, -67), Pair(-51, -57), Pair(-100, -67), Pair(-115, -17), Pair(-105, -4),
        Pair(-186, -12), Pair(-172, -42), Pair(-127, -33), Pair(-36, -75), Pair(-40, -66), Pair(-65, -61), Pair(-184, -32), Pair(-199, -25)
      },
      { // Piece 4
        Pair(-184, -115), Pair(-116, -34), Pair(-98, -84), Pair(-11, -58), Pair(-15, -45), Pair(-101, -13), Pair(47, 84), Pair(-42, -65),
        Pair(-200, 35), Pair(-116, -94), Pair(-174, 29), Pair(-112, -52), Pair(-100, 8), Pair(99, -63), Pair(-85, -60), Pair(-51, -35),
        Pair(-133, -124), Pair(-46, 19), Pair(-4, -64), Pair(-25, -147), Pair(-32, -100), Pair(93, -177), Pair(-145, -12), Pair(78, -184),
        Pair(-175, -49), Pair(-154, 25), Pair(-25, -51), Pair(-12, -41), Pair(-103, -48), Pair(-75, -25), Pair(-137, -88), Pair(-182, -128),
        Pair(-260, -30), Pair(-159, -99), Pair(-260, -37), Pair(-99, 29), Pair(-130, -30), Pair(-29, -132), Pair(-123, -25), Pair(-157, -75),
        Pair(-154, -114), Pair(-158, -38), Pair(-116, -32), Pair(-23, -175), Pair(-223, -69), Pair(-237, -39), Pair(-196, -71), Pair(-84, -163),
        Pair(-134, -59), Pair(-189, -122), Pair(-177, -116), Pair(-105, -110), Pair(-105, -177), Pair(-164, -94), Pair(-175, -91), Pair(-192, -219),
        Pair(-157, -179), Pair(-210, -216), Pair(-100, -181), Pair(-245, -37), Pair(-89, -97), Pair(-151, -196), Pair(-250, -152), Pair(-106, -116)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-63, -12), Pair(149, -5), Pair(20, 20), Pair(3, 12), Pair(-58, -7), Pair(-17, 7), Pair(45, -13), Pair(-73, -44),
        Pair(-26, -36), Pair(52, -23), Pair(6, -8), Pair(-30, 2), Pair(-18, -6), Pair(-43, 6), Pair(73, -40), Pair(-64, -54),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(123, -37), Pair(211, 12), Pair(367, -116), Pair(206, -114), Pair(226, -117), Pair(345, -150), Pair(-22, 84), Pair(167, -35),
        Pair(-18, 69), Pair(88, 45), Pair(157, 3), Pair(14, 10), Pair(97, -9), Pair(197, -18), Pair(171, 12), Pair(-8, 54),
        Pair(-135, 53), Pair(-56, 52), Pair(-51, 35), Pair(-34, 40), Pair(45, 10), Pair(3, 14), Pair(1, 33), Pair(-31, 21),
        Pair(-146, 44), Pair(-137, 66), Pair(3, 2), Pair(-37, 5), Pair(-28, 7), Pair(34, -2), Pair(-48, 44), Pair(-91, 25),
        Pair(-121, 22), Pair(-87, 35), Pair(-25, 1), Pair(-120, 1), Pair(8, -7), Pair(-27, -2), Pair(-38, 19), Pair(-62, 4),
        Pair(-186, 56), Pair(-140, 35), Pair(-41, 8), Pair(-57, 25), Pair(-35, 3), Pair(-80, 14), Pair(-110, 28), Pair(-129, 30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-58, -151), Pair(-9, -7), Pair(2, -69), Pair(36, -48), Pair(34, -51), Pair(2, -92), Pair(-31, -97), Pair(-38, -7),
        Pair(-152, -22), Pair(44, -44), Pair(24, -101), Pair(14, 14), Pair(37, -20), Pair(55, -55), Pair(-74, 11), Pair(-96, -85),
        Pair(32, -27), Pair(102, -78), Pair(122, -28), Pair(97, -44), Pair(86, -56), Pair(305, -58), Pair(4, -68), Pair(30, -46),
        Pair(-84, -46), Pair(-30, -56), Pair(126, -27), Pair(89, -30), Pair(85, -11), Pair(106, -33), Pair(65, -62), Pair(-21, -42),
        Pair(3, -12), Pair(-62, -20), Pair(79, -53), Pair(160, -52), Pair(41, -27), Pair(38, -7), Pair(114, -69), Pair(-13, -29),
        Pair(-95, -75), Pair(-136, -22), Pair(-41, -35), Pair(-38, -30), Pair(-68, 5), Pair(-25, -40), Pair(23, -67), Pair(32, -104),
        Pair(-48, -88), Pair(-61, -19), Pair(-107, -75), Pair(-116, -54), Pair(-2, -81), Pair(-30, -44), Pair(24, -103), Pair(-65, -106),
        Pair(-14, -56), Pair(-89, -70), Pair(-87, -36), Pair(-167, -53), Pair(13, -107), Pair(-162, -83), Pair(-159, 17), Pair(-33, -73)
      },
      { // Piece 2
        Pair(-53, -78), Pair(-26, -95), Pair(31, -128), Pair(-28, -65), Pair(-6, -153), Pair(69, -105), Pair(26, -81), Pair(1, -55),
        Pair(-60, -56), Pair(109, -124), Pair(104, -39), Pair(73, -85), Pair(80, -49), Pair(111, -71), Pair(79, -102), Pair(-29, -75),
        Pair(48, -76), Pair(50, -62), Pair(131, -98), Pair(179, -108), Pair(313, -125), Pair(291, -93), Pair(182, -89), Pair(102, -113),
        Pair(32, -122), Pair(217, -112), Pair(218, -100), Pair(172, -104), Pair(278, -116), Pair(224, -110), Pair(117, -94), Pair(56, -24),
        Pair(29, -59), Pair(46, -114), Pair(124, -99), Pair(123, -97), Pair(64, -71), Pair(151, -122), Pair(184, -115), Pair(-2, -46),
        Pair(21, -26), Pair(45, -79), Pair(60, -52), Pair(68, -83), Pair(145, -84), Pair(44, -102), Pair(185, -138), Pair(44, -44),
        Pair(-47, -36), Pair(-67, -51), Pair(-39, -86), Pair(80, -118), Pair(57, -79), Pair(-56, -75), Pair(110, -126), Pair(-24, -67),
        Pair(61, -83), Pair(123, -84), Pair(-65, -23), Pair(-91, -65), Pair(-113, -94), Pair(-96, -80), Pair(-23, -90), Pair(57, -132)
      },
      { // Piece 3
        Pair(-47, -33), Pair(11, -17), Pair(-45, -64), Pair(-36, 9), Pair(-19, -42), Pair(-73, -67), Pair(-36, -11), Pair(52, -29),
        Pair(244, -109), Pair(278, -116), Pair(290, -109), Pair(243, -119), Pair(190, -100), Pair(218, -95), Pair(219, -93), Pair(115, -73),
        Pair(62, -48), Pair(112, -89), Pair(69, -72), Pair(96, -75), Pair(235, -126), Pair(187, -105), Pair(115, -102), Pair(24, -72),
        Pair(38, -72), Pair(24, -72), Pair(-19, -85), Pair(26, -89), Pair(-13, -59), Pair(145, -83), Pair(-122, -43), Pair(36, -81),
        Pair(-214, -40), Pair(-86, -31), Pair(13, -71), Pair(-5, -60), Pair(9, -41), Pair(-79, -21), Pair(58, -57), Pair(-5, -30),
        Pair(-68, -71), Pair(-153, -54), Pair(-15, -121), Pair(-35, -89), Pair(-84, -50), Pair(-9, -108), Pair(-14, -55), Pair(-35, -80),
        Pair(-98, -50), Pair(-176, -65), Pair(-184, -66), Pair(-13, -78), Pair(-59, -50), Pair(-42, -102), Pair(-26, -59), Pair(-94, -96),
        Pair(-179, -64), Pair(-147, -22), Pair(-153, -64), Pair(-153, -61), Pair(-156, -39), Pair(-147, -64), Pair(-163, -48), Pair(-190, -54)
      },
      { // Piece 4
        Pair(-182, -170), Pair(-119, 4), Pair(14, -26), Pair(-4, 14), Pair(-35, -60), Pair(-8, -31), Pair(-5, 10), Pair(-5, 21),
        Pair(-188, -108), Pair(-98, -55), Pair(-56, -84), Pair(-22, 24), Pair(-10, -25), Pair(-62, -105), Pair(-23, -77), Pair(31, -65),
        Pair(-57, -113), Pair(-39, -101), Pair(-5, -67), Pair(2, -46), Pair(-5, -45), Pair(5, -99), Pair(-139, -92), Pair(-89, -125),
        Pair(-111, -89), Pair(-91, -90), Pair(14, -96), Pair(64, -148), Pair(-48, -149), Pair(-39, -29), Pair(-41, -84), Pair(-76, -167),
        Pair(-4, -37), Pair(5, -10), Pair(-48, 1), Pair(19, -2), Pair(-85, -26), Pair(-54, -153), Pair(-148, -125), Pair(-85, -92),
        Pair(-123, -29), Pair(-91, -105), Pair(-122, -92), Pair(-212, 26), Pair(-162, -104), Pair(-70, -101), Pair(-68, -116), Pair(-86, -68),
        Pair(-98, -193), Pair(-58, -90), Pair(-132, -171), Pair(-140, -118), Pair(14, -111), Pair(-112, -109), Pair(-88, -24), Pair(-91, -108),
        Pair(-37, -68), Pair(-176, -198), Pair(-74, 10), Pair(-343, -206), Pair(-102, -76), Pair(-52, -39), Pair(-61, -67), Pair(7, 23)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, -54), Pair(195, -50), Pair(41, -2), Pair(-12, 3), Pair(-4, 2), Pair(8, 13), Pair(97, -33), Pair(-106, -23),
        Pair(-66, -48), Pair(130, -44), Pair(35, -14), Pair(-54, -3), Pair(-41, 2), Pair(16, -11), Pair(27, -38), Pair(-114, -42),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(269, -118), Pair(377, -106), Pair(248, -65), Pair(150, -67), Pair(40, -32), Pair(128, -63), Pair(234, -58), Pair(386, -119),
        Pair(138, 7), Pair(143, 19), Pair(330, -25), Pair(210, -42), Pair(202, -37), Pair(181, -19), Pair(175, -29), Pair(103, -5),
        Pair(-70, 40), Pair(-32, 44), Pair(51, 14), Pair(-56, 18), Pair(11, 10), Pair(49, -2), Pair(34, 8), Pair(-15, 7),
        Pair(-74, 27), Pair(-97, 47), Pair(1, 6), Pair(-4, -2), Pair(17, -4), Pair(-36, 3), Pair(-21, 18), Pair(-85, 20),
        Pair(-173, 34), Pair(-103, 22), Pair(-8, -3), Pair(-44, 5), Pair(12, -7), Pair(-46, -2), Pair(-64, 11), Pair(-111, 19),
        Pair(-81, 31), Pair(-40, 21), Pair(-67, 18), Pair(-25, 13), Pair(-4, 33), Pair(-65, 8), Pair(-22, 14), Pair(-132, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-11, -140), Pair(14, -82), Pair(30, -97), Pair(-63, -100), Pair(69, -122), Pair(-97, -54), Pair(-118, -92), Pair(-26, -133),
        Pair(-90, -92), Pair(41, -74), Pair(81, -83), Pair(89, -72), Pair(124, -94), Pair(133, -102), Pair(9, -88), Pair(-46, -114),
        Pair(-100, -107), Pair(-7, -81), Pair(87, -66), Pair(102, -53), Pair(264, -100), Pair(103, -61), Pair(143, -113), Pair(106, -101),
        Pair(-4, -71), Pair(60, -83), Pair(70, -62), Pair(114, -66), Pair(106, -55), Pair(119, -61), Pair(51, -58), Pair(-1, -79),
        Pair(-143, -21), Pair(65, -57), Pair(79, -74), Pair(67, -45), Pair(125, -60), Pair(55, -55), Pair(71, -53), Pair(7, -96),
        Pair(-121, -56), Pair(-29, -84), Pair(-46, -65), Pair(67, -56), Pair(1, -61), Pair(26, -63), Pair(-11, -71), Pair(-41, -105),
        Pair(-139, -15), Pair(-95, -37), Pair(-134, -45), Pair(-74, -40), Pair(-105, -51), Pair(-35, -82), Pair(-96, -73), Pair(-11, -55),
        Pair(-56, -139), Pair(-179, -105), Pair(-245, -23), Pair(-163, -73), Pair(-146, -69), Pair(-210, -52), Pair(-71, -62), Pair(-28, -56)
      },
      { // Piece 2
        Pair(-33, -112), Pair(87, -112), Pair(149, -123), Pair(64, -98), Pair(125, -119), Pair(1, -104), Pair(74, -153), Pair(54, -129),
        Pair(-23, -115), Pair(253, -146), Pair(142, -122), Pair(194, -140), Pair(171, -105), Pair(169, -130), Pair(227, -152), Pair(61, -144),
        Pair(3, -95), Pair(82, -117), Pair(187, -118), Pair(185, -132), Pair(263, -134), Pair(282, -143), Pair(268, -141), Pair(-14, -93),
        Pair(78, -119), Pair(198, -135), Pair(137, -115), Pair(235, -134), Pair(241, -124), Pair(217, -126), Pair(223, -128), Pair(59, -114),
        Pair(-126, -75), Pair(21, -98), Pair(231, -139), Pair(167, -129), Pair(216, -136), Pair(223, -136), Pair(87, -114), Pair(-53, -81),
        Pair(0, -98), Pair(142, -115), Pair(105, -112), Pair(207, -133), Pair(125, -121), Pair(129, -122), Pair(82, -121), Pair(-77, -89),
        Pair(-25, -84), Pair(22, -102), Pair(81, -135), Pair(69, -118), Pair(161, -148), Pair(98, -119), Pair(-81, -128), Pair(28, -120),
        Pair(-57, -105), Pair(91, -120), Pair(-68, -93), Pair(-42, -93), Pair(4, -84), Pair(-29, -125), Pair(49, -107), Pair(-49, -144)
      },
      { // Piece 3
        Pair(93, -114), Pair(137, -121), Pair(62, -90), Pair(92, -116), Pair(-8, -67), Pair(175, -117), Pair(204, -133), Pair(122, -115),
        Pair(-102, -71), Pair(-26, -77), Pair(-1, -114), Pair(100, -117), Pair(30, -121), Pair(56, -148), Pair(-32, -106), Pair(99, -107),
        Pair(53, -119), Pair(87, -126), Pair(135, -143), Pair(101, -131), Pair(174, -165), Pair(185, -147), Pair(133, -142), Pair(70, -126),
        Pair(-11, -111), Pair(61, -123), Pair(12, -113), Pair(100, -139), Pair(64, -126), Pair(57, -126), Pair(54, -136), Pair(-20, -106),
        Pair(-65, -108), Pair(-26, -108), Pair(33, -130), Pair(-8, -89), Pair(-19, -111), Pair(-53, -106), Pair(-54, -108), Pair(-184, -95),
        Pair(-135, -115), Pair(-109, -95), Pair(-107, -101), Pair(-59, -118), Pair(-115, -106), Pair(-42, -132), Pair(-61, -113), Pair(-157, -111),
        Pair(-178, -86), Pair(-123, -99), Pair(-61, -111), Pair(-112, -111), Pair(-155, -121), Pair(-18, -148), Pair(-158, -101), Pair(-206, -87),
        Pair(-127, -118), Pair(-99, -106), Pair(-79, -116), Pair(-66, -119), Pair(-116, -116), Pair(-60, -129), Pair(-162, -110), Pair(-153, -90)
      },
      { // Piece 4
        Pair(-91, -300), Pair(-149, -182), Pair(-76, -176), Pair(-76, -159), Pair(-138, -193), Pair(-177, -160), Pair(-213, -134), Pair(-150, -167),
        Pair(-188, -212), Pair(-50, -149), Pair(-88, -175), Pair(-141, -155), Pair(-24, -176), Pair(-125, -152), Pair(-81, -77), Pair(-115, -171),
        Pair(-110, -185), Pair(-105, -268), Pair(-131, -60), Pair(-154, -59), Pair(-88, -110), Pair(-80, -94), Pair(-54, -202), Pair(-102, -192),
        Pair(-97, -240), Pair(-164, -207), Pair(-129, -82), Pair(-157, -116), Pair(-168, -92), Pair(-112, -81), Pair(-235, -131), Pair(-166, -198),
        Pair(-201, -169), Pair(-209, -117), Pair(-200, -94), Pair(-183, -102), Pair(-117, -162), Pair(-173, -190), Pair(-218, -159), Pair(-66, -260),
        Pair(-157, -184), Pair(-197, -113), Pair(-187, -177), Pair(-79, -228), Pair(-312, -103), Pair(-127, -225), Pair(-232, -203), Pair(-258, -152),
        Pair(-228, -227), Pair(-106, -153), Pair(-153, -190), Pair(-134, -276), Pair(-203, -185), Pair(-277, -205), Pair(-105, -209), Pair(-202, -287),
        Pair(-172, -332), Pair(-170, -186), Pair(-156, -292), Pair(-157, -208), Pair(-147, -246), Pair(-148, -103), Pair(-142, -272), Pair(-155, -199)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(56, -47), Pair(117, -14), Pair(42, 6), Pair(-48, 17), Pair(-57, 12), Pair(38, -1), Pair(30, -3), Pair(-12, -43),
        Pair(-16, -28), Pair(114, -41), Pair(-12, 4), Pair(-108, 19), Pair(-70, 4), Pair(-20, -8), Pair(6, -39), Pair(-87, -47),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(115, -14), Pair(221, 4), Pair(166, -11), Pair(132, 8), Pair(113, -3), Pair(133, 5), Pair(70, 25), Pair(153, -18),
        Pair(116, 16), Pair(210, 30), Pair(236, 5), Pair(96, 27), Pair(108, 10), Pair(146, 1), Pair(209, 10), Pair(109, 22),
        Pair(3, 38), Pair(28, 43), Pair(73, 22), Pair(43, 4), Pair(13, 8), Pair(114, -10), Pair(75, 26), Pair(7, 12),
        Pair(-91, 35), Pair(-107, 50), Pair(-47, 20), Pair(25, 15), Pair(-48, 19), Pair(1, 13), Pair(-66, 34), Pair(-100, 22),
        Pair(-132, 30), Pair(-50, 15), Pair(-32, 11), Pair(11, 25), Pair(3, 0), Pair(0, 1), Pair(-8, 7), Pair(-98, 21),
        Pair(-121, 30), Pair(-60, 28), Pair(-24, 7), Pair(-60, 2), Pair(-51, 21), Pair(-32, 13), Pair(-37, 27), Pair(-135, 40),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-5, -143), Pair(43, -127), Pair(6, -66), Pair(45, -64), Pair(31, -142), Pair(40, -67), Pair(-37, -74), Pair(21, -102),
        Pair(-40, -98), Pair(-90, -90), Pair(-34, -104), Pair(129, -88), Pair(79, -76), Pair(76, -124), Pair(35, -51), Pair(63, -100),
        Pair(37, -114), Pair(90, -107), Pair(51, -62), Pair(54, -67), Pair(161, -101), Pair(95, -61), Pair(15, -89), Pair(108, -114),
        Pair(130, -100), Pair(15, -88), Pair(95, -91), Pair(91, -68), Pair(113, -64), Pair(105, -105), Pair(-10, -86), Pair(11, -112),
        Pair(-22, -87), Pair(-17, -75), Pair(57, -68), Pair(162, -73), Pair(21, -58), Pair(73, -75), Pair(7, -64), Pair(6, -82),
        Pair(61, -123), Pair(-3, -55), Pair(52, -63), Pair(59, -58), Pair(-25, -61), Pair(4, -60), Pair(-34, -69), Pair(-61, -99),
        Pair(1, -88), Pair(-127, -15), Pair(9, -105), Pair(-114, -59), Pair(10, -60), Pair(-41, -72), Pair(-21, -63), Pair(-79, -119),
        Pair(-14, -104), Pair(-112, -50), Pair(-207, -38), Pair(-119, -51), Pair(-143, -54), Pair(-86, -74), Pair(-48, -91), Pair(-66, -112)
      },
      { // Piece 2
        Pair(-58, -66), Pair(12, -91), Pair(55, -123), Pair(57, -123), Pair(31, -146), Pair(39, -122), Pair(23, -90), Pair(41, -55),
        Pair(29, -87), Pair(110, -112), Pair(101, -114), Pair(160, -155), Pair(140, -135), Pair(220, -138), Pair(40, -104), Pair(-32, -88),
        Pair(10, -102), Pair(149, -120), Pair(193, -125), Pair(200, -143), Pair(271, -151), Pair(183, -138), Pair(158, -135), Pair(54, -90),
        Pair(54, -111), Pair(95, -104), Pair(184, -108), Pair(125, -101), Pair(232, -131), Pair(227, -146), Pair(209, -138), Pair(91, -105),
        Pair(-13, -128), Pair(99, -109), Pair(124, -121), Pair(202, -135), Pair(165, -139), Pair(126, -117), Pair(90, -131), Pair(-71, -74),
        Pair(-86, -83), Pair(-1, -101), Pair(117, -131), Pair(91, -133), Pair(141, -134), Pair(43, -119), Pair(4, -101), Pair(-70, -98),
        Pair(41, -128), Pair(72, -134), Pair(54, -119), Pair(51, -125), Pair(75, -118), Pair(-24, -102), Pair(-149, -79), Pair(-19, -63),
        Pair(-108, -80), Pair(-20, -99), Pair(-107, -86), Pair(26, -87), Pair(-23, -110), Pair(81, -141), Pair(13, -133), Pair(-26, -131)
      },
      { // Piece 3
        Pair(51, -146), Pair(26, -109), Pair(68, -135), Pair(115, -122), Pair(-66, -88), Pair(12, -124), Pair(3, -113), Pair(96, -151),
        Pair(119, -160), Pair(67, -135), Pair(151, -166), Pair(31, -135), Pair(105, -163), Pair(165, -158), Pair(100, -152), Pair(35, -137),
        Pair(31, -145), Pair(-45, -82), Pair(26, -141), Pair(-2, -130), Pair(0, -125), Pair(27, -116), Pair(-62, -157), Pair(60, -150),
        Pair(4, -121), Pair(63, -153), Pair(57, -136), Pair(83, -129), Pair(89, -141), Pair(106, -140), Pair(95, -156), Pair(30, -134),
        Pair(-11, -129), Pair(-23, -115), Pair(-32, -120), Pair(-30, -104), Pair(18, -142), Pair(18, -135), Pair(-15, -117), Pair(41, -134),
        Pair(-133, -144), Pair(-68, -125), Pair(-43, -117), Pair(-70, -104), Pair(-72, -128), Pair(-48, -133), Pair(-82, -104), Pair(-82, -152),
        Pair(-201, -87), Pair(-77, -128), Pair(-21, -152), Pair(-77, -146), Pair(11, -145), Pair(-49, -128), Pair(-135, -134), Pair(-100, -106),
        Pair(-118, -134), Pair(-30, -122), Pair(-98, -108), Pair(-95, -115), Pair(-90, -125), Pair(-71, -120), Pair(-98, -105), Pair(-163, -114)
      },
      { // Piece 4
        Pair(-34, -245), Pair(-55, -138), Pair(-38, -82), Pair(-1, -165), Pair(-100, -175), Pair(-84, -166), Pair(-4, -145), Pair(-105, -219),
        Pair(-76, -189), Pair(-76, -70), Pair(14, -141), Pair(-15, -121), Pair(20, -154), Pair(-105, -132), Pair(-79, -116), Pair(-153, -186),
        Pair(-71, -152), Pair(-76, -121), Pair(-114, -47), Pair(-18, -118), Pair(-22, -94), Pair(7, -78), Pair(-86, -167), Pair(-91, -106),
        Pair(-98, -208), Pair(-65, -168), Pair(-19, -120), Pair(4, -111), Pair(15, -168), Pair(-91, -175), Pair(-118, -178), Pair(-124, -206),
        Pair(-37, -38), Pair(-97, -98), Pair(-78, -63), Pair(31, 0), Pair(-67, -45), Pair(-80, -206), Pair(-99, -188), Pair(-123, -113),
        Pair(-122, -190), Pair(-65, -130), Pair(-97, -202), Pair(-22, -106), Pair(-50, -152), Pair(-48, -166), Pair(-48, -120), Pair(-113, -168),
        Pair(-119, -241), Pair(-57, -122), Pair(-41, -229), Pair(-93, -117), Pair(-106, -225), Pair(-87, -96), Pair(-66, -148), Pair(-40, -177),
        Pair(-93, -191), Pair(-46, -83), Pair(8, -27), Pair(-107, -246), Pair(-24, -190), Pair(-117, -144), Pair(-44, -87), Pair(-36, -118)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, -14), Pair(93, 6), Pair(18, 23), Pair(-25, 18), Pair(-37, 17), Pair(43, 15), Pair(-31, 25), Pair(-92, -19),
        Pair(45, -30), Pair(91, -25), Pair(27, 20), Pair(-56, 27), Pair(-1, 8), Pair(-6, 9), Pair(22, -11), Pair(-78, -25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-160, 15), Pair(21, -1), Pair(65, 24), Pair(38, 6), Pair(109, -17), Pair(35, -1), Pair(-65, 49), Pair(-164, 45),
        Pair(-67, 75), Pair(67, 70), Pair(23, 58), Pair(92, 43), Pair(-27, 59), Pair(81, 46), Pair(71, 41), Pair(-13, 58),
        Pair(-106, 46), Pair(12, 51), Pair(11, 21), Pair(-60, 47), Pair(-66, 40), Pair(15, 23), Pair(-14, 33), Pair(-36, 28),
        Pair(-101, 38), Pair(-99, 50), Pair(-47, 26), Pair(-39, 28), Pair(70, -6), Pair(30, 9), Pair(-64, 45), Pair(-145, 38),
        Pair(-132, 29), Pair(-54, 28), Pair(-98, 23), Pair(-44, 32), Pair(-69, 29), Pair(-100, 30), Pair(-33, 34), Pair(-125, 25),
        Pair(-215, 50), Pair(-104, 43), Pair(2, 20), Pair(-99, 55), Pair(-106, 40), Pair(-29, 26), Pair(-132, 50), Pair(-154, 49),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(27, -138), Pair(81, -109), Pair(-59, -56), Pair(33, -158), Pair(94, -120), Pair(-31, -74), Pair(-59, -141), Pair(-13, -240),
        Pair(-65, -122), Pair(31, -89), Pair(26, -118), Pair(124, -116), Pair(-25, -83), Pair(47, -121), Pair(-28, -110), Pair(-69, -130),
        Pair(-50, -152), Pair(22, -127), Pair(62, -106), Pair(64, -97), Pair(39, -91), Pair(59, -72), Pair(-7, -139), Pair(-27, -159),
        Pair(7, -111), Pair(64, -103), Pair(81, -91), Pair(88, -99), Pair(101, -81), Pair(121, -77), Pair(31, -61), Pair(-111, -93),
        Pair(7, -78), Pair(-20, -72), Pair(94, -85), Pair(52, -87), Pair(84, -96), Pair(86, -118), Pair(-28, -70), Pair(27, -123),
        Pair(-74, -102), Pair(-52, -110), Pair(6, -111), Pair(20, -89), Pair(49, -87), Pair(87, -128), Pair(-87, -97), Pair(-27, -115),
        Pair(-28, -91), Pair(-87, -43), Pair(16, -99), Pair(-35, -97), Pair(69, -99), Pair(-63, -96), Pair(32, -100), Pair(-19, -47),
        Pair(-50, -84), Pair(-63, -56), Pair(-49, -109), Pair(-52, -81), Pair(5, -102), Pair(-50, -126), Pair(21, -44), Pair(-18, -143)
      },
      { // Piece 2
        Pair(-63, -110), Pair(99, -137), Pair(-27, -98), Pair(-49, -101), Pair(-93, -121), Pair(-134, -110), Pair(-8, -141), Pair(-20, -143),
        Pair(73, -58), Pair(-62, -61), Pair(63, -133), Pair(-46, -99), Pair(95, -103), Pair(-4, -122), Pair(18, -87), Pair(-71, -88),
        Pair(108, -144), Pair(161, -146), Pair(104, -116), Pair(83, -96), Pair(56, -113), Pair(14, -92), Pair(-13, -129), Pair(53, -75),
        Pair(-53, -85), Pair(46, -105), Pair(169, -101), Pair(116, -117), Pair(138, -110), Pair(163, -147), Pair(72, -107), Pair(6, -112),
        Pair(-20, -63), Pair(123, -120), Pair(111, -115), Pair(109, -121), Pair(94, -135), Pair(140, -106), Pair(15, -147), Pair(61, -123),
        Pair(-53, -48), Pair(25, -91), Pair(96, -109), Pair(2, -93), Pair(64, -116), Pair(59, -110), Pair(18, -106), Pair(-46, -62),
        Pair(-31, -141), Pair(-72, -98), Pair(-35, -92), Pair(111, -125), Pair(54, -112), Pair(13, -98), Pair(-42, -110), Pair(-7, -74),
        Pair(2, -106), Pair(-100, -84), Pair(-111, -56), Pair(-99, -72), Pair(-32, -111), Pair(-17, -107), Pair(12, -180), Pair(31, -101)
      },
      { // Piece 3
        Pair(91, -182), Pair(22, -159), Pair(124, -153), Pair(22, -152), Pair(31, -140), Pair(33, -153), Pair(102, -157), Pair(37, -151),
        Pair(32, -157), Pair(73, -168), Pair(-54, -141), Pair(22, -155), Pair(78, -178), Pair(28, -173), Pair(121, -188), Pair(24, -158),
        Pair(-60, -136), Pair(37, -174), Pair(88, -178), Pair(43, -177), Pair(67, -180), Pair(75, -157), Pair(25, -158), Pair(-13, -149),
        Pair(20, -179), Pair(44, -151), Pair(7, -204), Pair(-43, -127), Pair(-31, -173), Pair(-6, -221), Pair(-13, -177), Pair(-66, -146),
        Pair(-28, -166), Pair(-120, -134), Pair(-25, -139), Pair(-79, -131), Pair(44, -178), Pair(61, -186), Pair(56, -150), Pair(-59, -143),
        Pair(-64, -146), Pair(69, -172), Pair(-79, -162), Pair(-33, -149), Pair(-43, -142), Pair(116, -206), Pair(133, -184), Pair(-88, -162),
        Pair(-58, -178), Pair(-99, -155), Pair(-23, -174), Pair(-113, -150), Pair(-48, -158), Pair(-41, -136), Pair(-58, -148), Pair(-80, -158),
        Pair(-72, -174), Pair(-77, -144), Pair(-63, -144), Pair(-35, -153), Pair(-91, -152), Pair(-82, -122), Pair(-90, -148), Pair(-100, -141)
      },
      { // Piece 4
        Pair(-122, -162), Pair(-126, -209), Pair(-18, -52), Pair(-34, -49), Pair(21, -206), Pair(50, -181), Pair(-125, -165), Pair(-84, -146),
        Pair(-74, -119), Pair(-43, -50), Pair(-52, -139), Pair(17, -51), Pair(-73, -64), Pair(-115, -176), Pair(-13, -88), Pair(-153, -121),
        Pair(-63, -85), Pair(-4, -71), Pair(-19, -166), Pair(-22, -61), Pair(-80, -147), Pair(-54, -88), Pair(-92, -113), Pair(-71, -110),
        Pair(-33, -74), Pair(-3, -32), Pair(-29, -54), Pair(-23, -67), Pair(-55, -86), Pair(-15, -48), Pair(-21, -38), Pair(59, 30),
        Pair(-67, -116), Pair(-61, -113), Pair(-32, -36), Pair(-37, -93), Pair(-95, -116), Pair(-58, -113), Pair(3, -35), Pair(-53, -122),
        Pair(-103, -108), Pair(-72, -99), Pair(-82, -96), Pair(-46, -133), Pair(-51, -118), Pair(-6, -8), Pair(-59, -109), Pair(-9, -69),
        Pair(-15, -83), Pair(-71, -72), Pair(-47, -117), Pair(-113, -176), Pair(0, -108), Pair(-16, -43), Pair(-29, -58), Pair(-20, -157),
        Pair(-66, -157), Pair(-57, -118), Pair(-81, -180), Pair(-49, -118), Pair(-20, -23), Pair(-67, -158), Pair(-93, -179), Pair(-63, -118)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(38, -27), Pair(133, -8), Pair(27, 15), Pair(-29, 20), Pair(-55, 20), Pair(28, 17), Pair(40, 4), Pair(6, -34),
        Pair(-9, -22), Pair(74, -16), Pair(28, 11), Pair(-161, 49), Pair(-64, 26), Pair(-29, 28), Pair(17, -4), Pair(-31, -31),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-224, 21), Pair(-63, 16), Pair(128, -8), Pair(90, -11), Pair(182, -23), Pair(113, 3), Pair(-27, 26), Pair(-187, 22),
        Pair(-146, 73), Pair(-89, 85), Pair(29, 50), Pair(47, 51), Pair(46, 47), Pair(-44, 68), Pair(-40, 59), Pair(-93, 68),
        Pair(-187, 57), Pair(-100, 52), Pair(-49, 38), Pair(-122, 51), Pair(-62, 56), Pair(-26, 28), Pair(-83, 47), Pair(-166, 51),
        Pair(-131, 32), Pair(-63, 33), Pair(-54, 21), Pair(-138, 35), Pair(-59, 32), Pair(-24, 19), Pair(46, 21), Pair(-102, 35),
        Pair(-158, 28), Pair(-124, 35), Pair(-62, 12), Pair(-90, 28), Pair(-73, 26), Pair(1, 13), Pair(-101, 28), Pair(-147, 35),
        Pair(-126, 32), Pair(-164, 50), Pair(-119, 34), Pair(-102, 24), Pair(-100, 48), Pair(-104, 46), Pair(-75, 38), Pair(-219, 52),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-28, -231), Pair(-54, -174), Pair(14, -166), Pair(-85, -155), Pair(-57, -125), Pair(12, -95), Pair(-91, -110), Pair(62, -201),
        Pair(-25, -153), Pair(13, -148), Pair(-36, -157), Pair(39, -135), Pair(-36, -130), Pair(-14, -159), Pair(1, -159), Pair(5, -123),
        Pair(-113, -147), Pair(35, -163), Pair(21, -140), Pair(29, -108), Pair(84, -139), Pair(34, -127), Pair(-14, -147), Pair(-72, -156),
        Pair(-17, -189), Pair(-2, -132), Pair(72, -131), Pair(23, -111), Pair(45, -138), Pair(73, -137), Pair(52, -159), Pair(-6, -151),
        Pair(43, -162), Pair(-5, -115), Pair(29, -113), Pair(90, -117), Pair(139, -141), Pair(72, -141), Pair(142, -162), Pair(-16, -148),
        Pair(-13, -154), Pair(-64, -96), Pair(63, -136), Pair(90, -143), Pair(31, -144), Pair(67, -155), Pair(-55, -155), Pair(-14, -142),
        Pair(-77, -124), Pair(-1, -77), Pair(-56, -103), Pair(-61, -115), Pair(-26, -136), Pair(-13, -147), Pair(-20, -108), Pair(-74, -109),
        Pair(-59, -128), Pair(-9, -137), Pair(-57, -127), Pair(-15, -149), Pair(60, -129), Pair(18, -150), Pair(50, -144), Pair(1, -84)
      },
      { // Piece 2
        Pair(25, -123), Pair(112, -118), Pair(-24, -146), Pair(-78, -148), Pair(68, -137), Pair(-85, -101), Pair(124, -154), Pair(-40, -113),
        Pair(-20, -123), Pair(-195, -90), Pair(-51, -111), Pair(31, -134), Pair(-87, -113), Pair(91, -125), Pair(-16, -118), Pair(2, -126),
        Pair(-76, -112), Pair(37, -124), Pair(39, -123), Pair(26, -129), Pair(42, -138), Pair(-23, -97), Pair(105, -136), Pair(-32, -135),
        Pair(-11, -122), Pair(-74, -105), Pair(53, -134), Pair(4, -110), Pair(45, -130), Pair(69, -126), Pair(-82, -102), Pair(21, -122),
        Pair(28, -113), Pair(-11, -109), Pair(-13, -132), Pair(21, -127), Pair(20, -127), Pair(-75, -107), Pair(24, -135), Pair(-89, -113),
        Pair(-130, -125), Pair(32, -121), Pair(-41, -122), Pair(-96, -120), Pair(-35, -124), Pair(28, -127), Pair(-1, -157), Pair(11, -102),
        Pair(-53, -129), Pair(-116, -125), Pair(121, -126), Pair(-151, -110), Pair(-31, -138), Pair(-41, -134), Pair(-97, -121), Pair(11, -131),
        Pair(-101, -148), Pair(22, -62), Pair(-46, -108), Pair(-66, -96), Pair(-153, -86), Pair(21, -105), Pair(-92, -82), Pair(-12, -133)
      },
      { // Piece 3
        Pair(87, -243), Pair(95, -225), Pair(167, -230), Pair(31, -200), Pair(67, -216), Pair(9, -202), Pair(110, -213), Pair(116, -210),
        Pair(19, -215), Pair(43, -218), Pair(198, -260), Pair(5, -224), Pair(138, -227), Pair(55, -227), Pair(85, -233), Pair(-43, -200),
        Pair(10, -219), Pair(107, -225), Pair(37, -214), Pair(170, -255), Pair(90, -235), Pair(119, -234), Pair(109, -246), Pair(51, -213),
        Pair(57, -226), Pair(193, -257), Pair(57, -232), Pair(141, -227), Pair(63, -224), Pair(145, -247), Pair(-14, -195), Pair(73, -232),
        Pair(-7, -231), Pair(40, -230), Pair(86, -251), Pair(42, -240), Pair(39, -240), Pair(93, -240), Pair(103, -233), Pair(24, -255),
        Pair(52, -250), Pair(30, -266), Pair(-26, -208), Pair(-4, -226), Pair(-32, -229), Pair(-80, -197), Pair(-92, -198), Pair(-46, -223),
        Pair(-53, -193), Pair(-101, -211), Pair(-16, -234), Pair(-106, -224), Pair(-143, -189), Pair(-42, -219), Pair(-12, -209), Pair(-37, -232),
        Pair(-94, -213), Pair(-129, -194), Pair(-13, -217), Pair(-23, -200), Pair(-49, -201), Pair(-22, -202), Pair(-53, -197), Pair(-68, -200)
      },
      { // Piece 4
        Pair(-93, -317), Pair(-87, -195), Pair(-142, -226), Pair(-166, -233), Pair(-97, -211), Pair(-204, -163), Pair(-65, -335), Pair(-94, -270),
        Pair(-124, -242), Pair(-101, -239), Pair(-68, -227), Pair(-24, -223), Pair(-81, -198), Pair(2, -147), Pair(-55, -253), Pair(-129, -265),
        Pair(-88, -219), Pair(-109, -219), Pair(-97, -175), Pair(-52, -252), Pair(-77, -270), Pair(-84, -287), Pair(-91, -270), Pair(-111, -247),
        Pair(-153, -213), Pair(-141, -321), Pair(-136, -246), Pair(-64, -180), Pair(-116, -255), Pair(-4, -212), Pair(-149, -212), Pair(-167, -281),
        Pair(-82, -236), Pair(-132, -255), Pair(-54, -164), Pair(-63, -106), Pair(-138, -234), Pair(-42, -192), Pair(-87, -149), Pair(-102, -193),
        Pair(-95, -163), Pair(-123, -218), Pair(-120, -220), Pair(-98, -203), Pair(-108, -196), Pair(-103, -206), Pair(15, -30), Pair(-70, -174),
        Pair(-98, -269), Pair(-159, -266), Pair(-195, -296), Pair(-135, -261), Pair(-36, -213), Pair(-145, -278), Pair(-101, -223), Pair(-145, -271),
        Pair(-109, -240), Pair(-76, -202), Pair(-128, -274), Pair(-62, -268), Pair(-88, -244), Pair(-125, -251), Pair(-146, -282), Pair(-79, -222)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-38, -20), Pair(97, -2), Pair(15, 20), Pair(-71, 26), Pair(52, -2), Pair(48, 12), Pair(61, 4), Pair(49, -39),
        Pair(-56, -17), Pair(58, -9), Pair(11, 16), Pair(-37, 28), Pair(-80, 27), Pair(-11, 22), Pair(18, -7), Pair(-89, -22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-220, 100), Pair(-200, 77), Pair(0, 114), Pair(149, 80), Pair(72, 97), Pair(13, 81), Pair(-51, 86), Pair(-238, 76),
        Pair(-243, 119), Pair(-32, 115), Pair(58, 112), Pair(-7, 103), Pair(38, 94), Pair(15, 103), Pair(-132, 115), Pair(-143, 125),
        Pair(-105, 83), Pair(-66, 65), Pair(37, 69), Pair(-76, 55), Pair(-59, 47), Pair(79, 59), Pair(9, 75), Pair(-82, 67),
        Pair(-120, 59), Pair(-105, 45), Pair(-15, 37), Pair(-81, 31), Pair(56, 40), Pair(-31, 42), Pair(-46, 52), Pair(-192, 79),
        Pair(-99, 38), Pair(-104, 35), Pair(-13, -3), Pair(-26, 29), Pair(-50, 60), Pair(-43, 28), Pair(-125, 48), Pair(-124, 35),
        Pair(-136, 57), Pair(-116, 69), Pair(-79, 47), Pair(-16, 107), Pair(33, 33), Pair(-116, 39), Pair(-140, 42), Pair(-25, 58),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-44, -137), Pair(-14, -100), Pair(12, -98), Pair(-1, -44), Pair(-51, -145), Pair(-39, -130), Pair(1, -163), Pair(37, -94),
        Pair(-13, -216), Pair(-59, -106), Pair(-72, -81), Pair(5, -102), Pair(-1, -92), Pair(-107, -136), Pair(-35, -91), Pair(-13, -182),
        Pair(-28, -173), Pair(-43, -102), Pair(-70, -80), Pair(-58, -53), Pair(-95, -91), Pair(-1, -111), Pair(43, -97), Pair(-49, -168),
        Pair(-38, -207), Pair(-27, -149), Pair(-83, -108), Pair(21, -112), Pair(82, -80), Pair(83, -77), Pair(98, -202), Pair(-18, -84),
        Pair(-6, -121), Pair(18, -103), Pair(101, -111), Pair(19, -70), Pair(35, -73), Pair(76, 0), Pair(-45, -125), Pair(39, -151),
        Pair(-14, -62), Pair(56, -54), Pair(28, -67), Pair(48, -83), Pair(90, -57), Pair(-36, -32), Pair(-14, 23), Pair(20, -83),
        Pair(-13, -69), Pair(8, -85), Pair(-60, -90), Pair(-35, -95), Pair(-4, -76), Pair(-17, -68), Pair(1, -88), Pair(-9, -8),
        Pair(-27, -69), Pair(-37, -161), Pair(-16, -120), Pair(-67, -84), Pair(34, -89), Pair(36, -69), Pair(-13, -147), Pair(-20, -92)
      },
      { // Piece 2
        Pair(-9, -31), Pair(0, 1), Pair(-84, -70), Pair(-16, -13), Pair(20, -75), Pair(-12, -114), Pair(-13, 35), Pair(-3, -61),
        Pair(23, -8), Pair(-67, -17), Pair(-13, -17), Pair(-12, -101), Pair(-9, -83), Pair(-30, -59), Pair(-28, -46), Pair(-37, -119),
        Pair(7, -68), Pair(10, -64), Pair(-34, -37), Pair(16, -47), Pair(45, 3), Pair(-137, -37), Pair(-32, -48), Pair(4, -19),
        Pair(-56, -19), Pair(-12, -48), Pair(34, -36), Pair(-76, -53), Pair(-6, -57), Pair(-42, -40), Pair(-69, -65), Pair(49, -47),
        Pair(-50, 8), Pair(-51, -52), Pair(43, -60), Pair(34, -20), Pair(61, -96), Pair(-18, -38), Pair(-20, -70), Pair(21, 19),
        Pair(-23, 33), Pair(2, -14), Pair(11, -23), Pair(-94, -26), Pair(-68, 10), Pair(-44, -19), Pair(-43, 2), Pair(6, -59),
        Pair(-24, -19), Pair(-69, -55), Pair(13, -41), Pair(-32, -33), Pair(-63, -87), Pair(-25, -134), Pair(8, -21), Pair(-40, -106),
        Pair(7, -34), Pair(68, -210), Pair(-21, -47), Pair(12, -73), Pair(-56, -65), Pair(-42, -100), Pair(5, 18), Pair(44, -71)
      },
      { // Piece 3
        Pair(43, -154), Pair(30, -120), Pair(13, -162), Pair(71, -113), Pair(25, -121), Pair(-55, -156), Pair(-64, -137), Pair(42, -153),
        Pair(-17, -144), Pair(29, -177), Pair(86, -129), Pair(26, -166), Pair(-14, -170), Pair(13, -156), Pair(12, -143), Pair(-29, -197),
        Pair(3, -132), Pair(-13, -139), Pair(22, -160), Pair(115, -159), Pair(5, -136), Pair(-2, -120), Pair(2, -164), Pair(-5, -197),
        Pair(22, -163), Pair(50, -121), Pair(-32, -178), Pair(-29, -165), Pair(-103, -166), Pair(53, -177), Pair(-13, -167), Pair(-20, -136),
        Pair(73, -169), Pair(47, -162), Pair(-96, -151), Pair(38, -212), Pair(-46, -169), Pair(-14, -125), Pair(-28, -132), Pair(27, -155),
        Pair(-34, -132), Pair(-42, -148), Pair(6, -176), Pair(-64, -141), Pair(27, -187), Pair(56, -209), Pair(40, -117), Pair(34, -127),
        Pair(-40, -189), Pair(41, -142), Pair(20, -167), Pair(-54, -213), Pair(10, -224), Pair(4, -133), Pair(-21, -199), Pair(11, -145),
        Pair(1, -138), Pair(-55, -117), Pair(174, -154), Pair(20, -153), Pair(-6, -158), Pair(-7, -215), Pair(-27, -184), Pair(-18, -164)
      },
      { // Piece 4
        Pair(-108, -167), Pair(-10, -150), Pair(0, -182), Pair(-74, -63), Pair(-31, -58), Pair(-104, -100), Pair(-90, -157), Pair(-74, -136),
        Pair(-33, -138), Pair(-91, -137), Pair(-49, -13), Pair(-75, -56), Pair(-52, -154), Pair(-34, -78), Pair(-41, -69), Pair(-13, -30),
        Pair(-21, -103), Pair(-130, -120), Pair(-35, -79), Pair(-22, -83), Pair(-25, -61), Pair(-9, -68), Pair(-33, -44), Pair(-53, -60),
        Pair(-50, -127), Pair(-48, -122), Pair(6, -45), Pair(4, -46), Pair(-35, -81), Pair(-34, -128), Pair(-61, -100), Pair(-23, -164),
        Pair(-20, -60), Pair(11, -95), Pair(11, -146), Pair(-23, -22), Pair(42, -63), Pair(12, -75), Pair(-37, -92), Pair(-25, -85),
        Pair(-34, -103), Pair(-40, -105), Pair(-104, -160), Pair(-10, -84), Pair(25, 4), Pair(-85, -127), Pair(-35, -132), Pair(-23, -96),
        Pair(-25, -82), Pair(-42, -63), Pair(-32, -98), Pair(-16, -87), Pair(19, -8), Pair(-11, -111), Pair(25, 16), Pair(-11, -47),
        Pair(-90, -91), Pair(-21, -49), Pair(-34, -85), Pair(-46, -105), Pair(-22, -95), Pair(-71, -182), Pair(-15, -48), Pair(-75, -196)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-30, -36), Pair(45, 9), Pair(36, 37), Pair(14, 47), Pair(-43, 25), Pair(-5, 33), Pair(88, 15), Pair(21, -20),
        Pair(-77, -5), Pair(97, -6), Pair(28, 33), Pair(-71, 54), Pair(-7, 39), Pair(18, 40), Pair(58, 4), Pair(-29, -30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 6
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-2, 48), Pair(204, -27), Pair(98, 242), Pair(83, 194), Pair(-52, 118), Pair(36, 143), Pair(44, -99), Pair(25, -144),
        Pair(24, 132), Pair(179, 102), Pair(3, 123), Pair(19, 119), Pair(2, 109), Pair(150, 14), Pair(102, -29), Pair(95, -78),
        Pair(-7, 78), Pair(-63, 63), Pair(186, 64), Pair(-5, 115), Pair(-14, 89), Pair(-22, 51), Pair(-120, 45), Pair(13, -49),
        Pair(-68, 42), Pair(-132, 106), Pair(41, 76), Pair(56, 16), Pair(-26, 0), Pair(-58, 21), Pair(-152, 21), Pair(-156, 7),
        Pair(-129, 84), Pair(20, 16), Pair(56, -18), Pair(48, -11), Pair(-66, 14), Pair(21, -3), Pair(-176, 18), Pair(-2, -22),
        Pair(-24, 18), Pair(-48, 47), Pair(-16, 20), Pair(-69, -5), Pair(-32, -9), Pair(-96, -13), Pair(-209, 53), Pair(-166, -22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(14, 61), Pair(16, 6), Pair(64, 30), Pair(-9, -67), Pair(27, 60), Pair(38, -110), Pair(18, 53), Pair(-1, -16),
        Pair(10, 22), Pair(-12, 21), Pair(18, -96), Pair(73, 53), Pair(65, -55), Pair(18, -108), Pair(-34, -72), Pair(5, -6),
        Pair(-47, -84), Pair(-3, -24), Pair(-17, -38), Pair(43, 35), Pair(256, 3), Pair(60, 35), Pair(62, 32), Pair(54, 44),
        Pair(55, -18), Pair(-18, -33), Pair(62, 34), Pair(-18, 50), Pair(29, 94), Pair(26, 39), Pair(146, 59), Pair(12, 5),
        Pair(53, 55), Pair(5, -15), Pair(23, 58), Pair(-73, 10), Pair(116, 178), Pair(25, 18), Pair(-24, 7), Pair(-67, -24),
        Pair(-62, -33), Pair(8, -49), Pair(-93, 24), Pair(-7, -51), Pair(2, -37), Pair(-62, -40), Pair(-1, -64), Pair(10, -57),
        Pair(-19, -88), Pair(8, 14), Pair(-67, 79), Pair(-198, 18), Pair(-72, -63), Pair(19, 40), Pair(18, -2), Pair(-39, -68),
        Pair(0, 21), Pair(-9, 31), Pair(24, 61), Pair(-8, -12), Pair(-1, -39), Pair(-75, -117), Pair(-101, -85), Pair(-17, -70)
      },
      { // Piece 2
        Pair(-17, -1), Pair(6, -28), Pair(-28, -24), Pair(18, -80), Pair(6, 48), Pair(-106, -124), Pair(-11, -58), Pair(5, 93),
        Pair(8, -52), Pair(-28, -50), Pair(-37, -62), Pair(8, -52), Pair(21, -16), Pair(-28, -106), Pair(20, 35), Pair(28, 21),
        Pair(-31, -72), Pair(28, -34), Pair(92, -45), Pair(-19, -56), Pair(102, 4), Pair(37, 56), Pair(14, -1), Pair(32, 59),
        Pair(12, -13), Pair(114, -81), Pair(23, -90), Pair(126, -57), Pair(-16, -72), Pair(-71, 7), Pair(-78, -91), Pair(63, -58),
        Pair(37, 88), Pair(37, -33), Pair(-28, 60), Pair(176, -117), Pair(53, -70), Pair(42, -94), Pair(-23, -15), Pair(-22, 21),
        Pair(29, 70), Pair(8, -103), Pair(55, 89), Pair(-54, -17), Pair(33, -123), Pair(-99, -15), Pair(-4, 59), Pair(14, -39),
        Pair(14, -50), Pair(100, -15), Pair(114, -121), Pair(-62, 20), Pair(-19, -73), Pair(-6, 16), Pair(-63, -72), Pair(-16, -62),
        Pair(-52, -43), Pair(-11, 28), Pair(-187, 16), Pair(-21, 13), Pair(-12, 8), Pair(-96, -101), Pair(33, -55), Pair(-3, -88)
      },
      { // Piece 3
        Pair(-4, -14), Pair(76, 108), Pair(85, 137), Pair(58, 61), Pair(64, 163), Pair(-78, -91), Pair(-19, -33), Pair(8, 0),
        Pair(100, -47), Pair(169, -4), Pair(48, -45), Pair(-19, 29), Pair(210, -42), Pair(94, 13), Pair(54, 77), Pair(-13, -13),
        Pair(-14, -10), Pair(15, -13), Pair(78, -20), Pair(45, 28), Pair(-52, 35), Pair(25, 23), Pair(-30, 32), Pair(-25, 24),
        Pair(-53, -16), Pair(-125, -19), Pair(-128, 15), Pair(-122, -50), Pair(-3, -33), Pair(43, 76), Pair(12, 52), Pair(14, 35),
        Pair(31, 19), Pair(-6, -6), Pair(-29, 13), Pair(8, -4), Pair(98, -112), Pair(0, 8), Pair(47, 86), Pair(2, 1),
        Pair(-59, -103), Pair(-18, 38), Pair(-41, -21), Pair(-88, -5), Pair(-33, -100), Pair(45, -25), Pair(52, 37), Pair(-21, 94),
        Pair(-92, 43), Pair(-31, 93), Pair(-32, -74), Pair(-85, 70), Pair(-42, -39), Pair(35, 26), Pair(-51, 84), Pair(27, 16),
        Pair(-240, 81), Pair(-234, 101), Pair(-53, 34), Pair(-158, 53), Pair(45, -61), Pair(-99, 53), Pair(-69, -38), Pair(-267, 89)
      },
      { // Piece 4
        Pair(-73, -59), Pair(-14, -48), Pair(22, -40), Pair(32, 10), Pair(17, -43), Pair(-105, -78), Pair(-29, -16), Pair(3, 6),
        Pair(-19, -126), Pair(-90, -55), Pair(-55, -32), Pair(-50, -11), Pair(16, 36), Pair(-84, 9), Pair(7, -48), Pair(-39, -20),
        Pair(10, -18), Pair(78, 103), Pair(17, 11), Pair(29, 37), Pair(13, 88), Pair(1, 13), Pair(59, -41), Pair(60, -97),
        Pair(-54, -84), Pair(-100, -56), Pair(-22, 63), Pair(13, 9), Pair(32, -33), Pair(-16, -19), Pair(-44, -20), Pair(-31, 7),
        Pair(-56, -132), Pair(94, 74), Pair(-79, -22), Pair(16, 33), Pair(85, -37), Pair(36, 90), Pair(13, 88), Pair(-54, -115),
        Pair(-51, -109), Pair(-2, 20), Pair(-18, 70), Pair(-61, -45), Pair(-29, -58), Pair(-96, -37), Pair(55, 93), Pair(-23, -12),
        Pair(57, -44), Pair(-79, -133), Pair(2, -5), Pair(-109, -68), Pair(-45, -44), Pair(-66, -84), Pair(-17, -23), Pair(-13, -18),
        Pair(-58, -51), Pair(-107, -143), Pair(-12, -9), Pair(-127, -89), Pair(-25, -59), Pair(-140, -103), Pair(-26, -23), Pair(-143, -133)
      },
      { // Piece 5
        Pair(-17, -122), Pair(84, -52), Pair(108, -12), Pair(138, -52), Pair(-64, -15), Pair(131, -60), Pair(-64, 64), Pair(-38, -141),
        Pair(-53, 17), Pair(78, 17), Pair(89, -36), Pair(42, -14), Pair(-17, -21), Pair(-115, 39), Pair(23, 41), Pair(-33, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(27, -9), Pair(42, 128), Pair(135, -66), Pair(68, 12), Pair(42, -91), Pair(72, -72), Pair(37, 199), Pair(44, 58),
        Pair(-6, 98), Pair(72, 89), Pair(78, 20), Pair(81, -63), Pair(71, 13), Pair(117, 73), Pair(202, 34), Pair(19, 26),
        Pair(2, 10), Pair(-156, 45), Pair(-1, 1), Pair(2, 49), Pair(-15, 72), Pair(13, 0), Pair(-100, 93), Pair(-62, 43),
        Pair(-132, 52), Pair(-53, 52), Pair(26, -15), Pair(87, 6), Pair(14, -24), Pair(-87, 37), Pair(-75, 53), Pair(-149, 75),
        Pair(-108, 7), Pair(14, 16), Pair(-56, 14), Pair(-21, 28), Pair(-179, -4), Pair(-111, 66), Pair(-176, 7), Pair(-69, 45),
        Pair(-139, 1), Pair(-116, 117), Pair(-98, -2), Pair(-7, -6), Pair(-60, -42), Pair(-128, 74), Pair(-120, 25), Pair(-168, 73),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(43, -38), Pair(11, 23), Pair(-38, -45), Pair(-26, -69), Pair(-13, -124), Pair(14, 1), Pair(-5, -22), Pair(-46, -114),
        Pair(19, 54), Pair(-27, -24), Pair(42, 31), Pair(-5, -17), Pair(39, 8), Pair(5, -22), Pair(-51, -159), Pair(-4, 8),
        Pair(-32, -53), Pair(-8, 13), Pair(85, -30), Pair(117, 7), Pair(41, 5), Pair(84, 124), Pair(42, 12), Pair(-59, -150),
        Pair(-5, -62), Pair(34, 29), Pair(100, 48), Pair(-3, 22), Pair(70, 67), Pair(-4, 59), Pair(97, 50), Pair(-44, -26),
        Pair(-21, -20), Pair(1, -6), Pair(51, 51), Pair(-17, 12), Pair(78, 51), Pair(18, 17), Pair(1, -36), Pair(4, 36),
        Pair(0, -51), Pair(-61, -132), Pair(26, 0), Pair(25, 58), Pair(28, 35), Pair(12, 66), Pair(1, -54), Pair(-20, -72),
        Pair(-14, -67), Pair(3, 15), Pair(-11, 6), Pair(-19, -33), Pair(-84, -32), Pair(-1, -31), Pair(-15, -43), Pair(-13, -69),
        Pair(-14, -10), Pair(-67, 87), Pair(9, -11), Pair(2, 80), Pair(-21, -93), Pair(-51, -141), Pair(-80, -110), Pair(-10, -38)
      },
      { // Piece 2
        Pair(-5, -70), Pair(7, -26), Pair(22, -46), Pair(11, -134), Pair(-22, -79), Pair(-24, -133), Pair(-14, -213), Pair(-29, -172),
        Pair(-34, -208), Pair(45, 13), Pair(2, 23), Pair(15, -119), Pair(41, 39), Pair(8, -21), Pair(74, -33), Pair(-37, -108),
        Pair(-12, 47), Pair(38, -13), Pair(-17, -70), Pair(29, -89), Pair(69, -139), Pair(105, -59), Pair(-44, -12), Pair(-27, -70),
        Pair(-32, 1), Pair(77, -27), Pair(100, -26), Pair(-33, -80), Pair(-1, -79), Pair(-11, -97), Pair(113, 0), Pair(28, 38),
        Pair(-35, -47), Pair(-52, -58), Pair(26, -48), Pair(9, -51), Pair(-26, -102), Pair(18, 23), Pair(42, -37), Pair(14, 1),
        Pair(4, -8), Pair(5, -31), Pair(-16, -46), Pair(5, -34), Pair(-77, 27), Pair(-23, -102), Pair(-39, -31), Pair(11, 63),
        Pair(32, -5), Pair(68, 42), Pair(23, -60), Pair(-5, -29), Pair(44, -80), Pair(-38, -20), Pair(-66, -47), Pair(27, 3),
        Pair(-8, -134), Pair(-15, -14), Pair(-114, -110), Pair(-13, 61), Pair(-44, -15), Pair(-7, -57), Pair(-5, -94), Pair(-9, -95)
      },
      { // Piece 3
        Pair(92, 81), Pair(38, 60), Pair(-11, 73), Pair(52, 97), Pair(-8, -23), Pair(-54, -13), Pair(13, 11), Pair(12, -38),
        Pair(256, -7), Pair(170, -34), Pair(165, -60), Pair(107, -39), Pair(40, 15), Pair(83, -21), Pair(30, -24), Pair(25, 38),
        Pair(13, 6), Pair(75, 21), Pair(-33, 41), Pair(47, 80), Pair(116, 60), Pair(162, 30), Pair(8, 2), Pair(23, 17),
        Pair(54, 89), Pair(41, -31), Pair(-35, -13), Pair(16, -5), Pair(16, 74), Pair(45, -6), Pair(-2, -19), Pair(-36, -39),
        Pair(-46, -73), Pair(25, 19), Pair(-2, -78), Pair(-120, 11), Pair(61, 48), Pair(37, -35), Pair(1, 48), Pair(10, 27),
        Pair(27, -62), Pair(-39, 73), Pair(0, -58), Pair(10, 16), Pair(10, 6), Pair(-30, -72), Pair(50, 89), Pair(-6, -25),
        Pair(-34, -53), Pair(-22, 65), Pair(-10, -91), Pair(34, 9), Pair(-70, -17), Pair(25, 50), Pair(11, 78), Pair(12, 81),
        Pair(-143, -18), Pair(-1, 11), Pair(-110, 21), Pair(-43, -56), Pair(-1, -59), Pair(-11, 27), Pair(-30, 29), Pair(-35, 105)
      },
      { // Piece 4
        Pair(-48, -97), Pair(-54, -111), Pair(15, 34), Pair(-19, 2), Pair(1, 3), Pair(-21, -50), Pair(-27, -49), Pair(29, 52),
        Pair(-10, -73), Pair(5, -19), Pair(34, -19), Pair(-49, -113), Pair(10, 58), Pair(16, 26), Pair(9, -77), Pair(-115, -142),
        Pair(0, -17), Pair(-23, -64), Pair(92, 108), Pair(-3, -20), Pair(18, 36), Pair(29, 44), Pair(33, 37), Pair(15, 21),
        Pair(35, 11), Pair(50, 57), Pair(-2, -51), Pair(61, -22), Pair(-3, -67), Pair(-25, -67), Pair(-3, -8), Pair(1, 4),
        Pair(-15, -13), Pair(-37, -37), Pair(-20, -59), Pair(-30, -70), Pair(25, 55), Pair(-34, -77), Pair(-74, -99), Pair(-38, -59),
        Pair(-36, -20), Pair(-62, -94), Pair(25, 49), Pair(-13, -19), Pair(-50, -44), Pair(14, 35), Pair(2, -37), Pair(-10, -17),
        Pair(-59, -35), Pair(-15, -7), Pair(37, 72), Pair(-56, -61), Pair(-10, -17), Pair(-11, -24), Pair(43, 46), Pair(-17, -26),
        Pair(-25, -65), Pair(-57, -87), Pair(-8, -5), Pair(-142, -83), Pair(-11, -18), Pair(-8, -10), Pair(-10, -48), Pair(0, 0)
      },
      { // Piece 5
        Pair(20, -217), Pair(-22, -53), Pair(-105, 56), Pair(109, -20), Pair(-13, -2), Pair(-84, 88), Pair(-9, -3), Pair(8, -181),
        Pair(-39, -84), Pair(48, -7), Pair(54, 26), Pair(44, 20), Pair(67, 46), Pair(128, -6), Pair(44, 29), Pair(29, -63),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(218, -68), Pair(294, -26), Pair(210, 38), Pair(97, 21), Pair(-41, 91), Pair(95, 79), Pair(20, 43), Pair(348, -53),
        Pair(191, 0), Pair(185, 60), Pair(218, 55), Pair(243, 25), Pair(174, 8), Pair(88, 27), Pair(203, 54), Pair(196, -26),
        Pair(-40, 32), Pair(45, 72), Pair(121, 17), Pair(-27, 5), Pair(35, 14), Pair(85, 26), Pair(-75, 53), Pair(19, 23),
        Pair(-166, 75), Pair(-53, 76), Pair(8, 16), Pair(-55, 43), Pair(-53, 20), Pair(-59, 35), Pair(-83, 32), Pair(-140, 29),
        Pair(-118, 24), Pair(-21, 29), Pair(-29, 19), Pair(-64, 2), Pair(-33, -2), Pair(12, 11), Pair(-85, 5), Pair(-168, 34),
        Pair(-235, 98), Pair(-168, 66), Pair(-43, -11), Pair(-58, 53), Pair(-107, 72), Pair(-79, 31), Pair(-154, 61), Pair(-102, 36),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-52, -118), Pair(7, 20), Pair(-9, -17), Pair(-11, -56), Pair(-4, 9), Pair(59, 40), Pair(-12, -95), Pair(-3, -27),
        Pair(1, -86), Pair(15, -74), Pair(7, 12), Pair(61, -93), Pair(43, -1), Pair(-91, 24), Pair(-15, -37), Pair(6, -84),
        Pair(-28, -20), Pair(-30, -83), Pair(26, -6), Pair(83, -8), Pair(167, -47), Pair(60, 37), Pair(80, -57), Pair(41, -58),
        Pair(3, -57), Pair(-62, -19), Pair(20, -56), Pair(88, -28), Pair(10, 13), Pair(-37, -2), Pair(106, -76), Pair(56, -88),
        Pair(-34, -8), Pair(12, 31), Pair(-46, 0), Pair(-39, 32), Pair(137, -36), Pair(-22, -26), Pair(-9, -17), Pair(-16, -20),
        Pair(-21, -191), Pair(-42, -29), Pair(-89, -8), Pair(-98, -25), Pair(65, -77), Pair(-17, -61), Pair(-62, -135), Pair(11, 33),
        Pair(0, -74), Pair(-90, -47), Pair(-8, -67), Pair(-141, -84), Pair(15, 24), Pair(-14, -40), Pair(-21, -5), Pair(-7, -1),
        Pair(-74, -123), Pair(-52, 68), Pair(-77, 4), Pair(-61, -40), Pair(26, 56), Pair(-50, -62), Pair(-118, -72), Pair(-23, -80)
      },
      { // Piece 2
        Pair(-18, -109), Pair(-7, -120), Pair(-43, -87), Pair(92, 9), Pair(-17, -46), Pair(54, -76), Pair(29, -146), Pair(-40, -18),
        Pair(-41, -109), Pair(66, -90), Pair(23, -81), Pair(69, -97), Pair(90, -79), Pair(99, -116), Pair(44, -66), Pair(-20, -100),
        Pair(-39, -9), Pair(12, -60), Pair(141, -60), Pair(49, -71), Pair(47, -16), Pair(180, -68), Pair(75, -136), Pair(-101, -41),
        Pair(1, -80), Pair(12, -24), Pair(70, -100), Pair(129, -92), Pair(138, -147), Pair(69, -124), Pair(-34, -59), Pair(101, -30),
        Pair(44, -95), Pair(166, -56), Pair(44, -55), Pair(236, -87), Pair(134, -122), Pair(176, -88), Pair(-35, -44), Pair(94, -39),
        Pair(-60, -57), Pair(122, -119), Pair(-14, -15), Pair(107, -99), Pair(40, -83), Pair(73, -41), Pair(-30, -52), Pair(-48, -60),
        Pair(-48, 39), Pair(-101, -4), Pair(78, -46), Pair(34, -42), Pair(4, -68), Pair(113, -135), Pair(-36, -51), Pair(-14, -127),
        Pair(26, -114), Pair(-5, -15), Pair(-65, -57), Pair(-122, -14), Pair(-17, -48), Pair(-4, -29), Pair(-19, -62), Pair(30, -100)
      },
      { // Piece 3
        Pair(88, -85), Pair(34, -56), Pair(97, -79), Pair(-80, -5), Pair(114, -87), Pair(52, -54), Pair(16, -53), Pair(186, -56),
        Pair(-26, -96), Pair(9, -34), Pair(-37, -56), Pair(81, -120), Pair(27, -74), Pair(10, -87), Pair(32, -17), Pair(9, 47),
        Pair(-26, -38), Pair(10, -88), Pair(-58, -18), Pair(-5, -43), Pair(88, -100), Pair(-2, -67), Pair(20, -35), Pair(24, -77),
        Pair(-93, -69), Pair(-72, -44), Pair(8, -66), Pair(-164, 13), Pair(76, -53), Pair(50, -70), Pair(109, -93), Pair(39, -62),
        Pair(-11, -30), Pair(73, -41), Pair(-25, -59), Pair(-21, -104), Pair(-22, -91), Pair(-34, -56), Pair(69, -36), Pair(-59, -42),
        Pair(-78, -57), Pair(-60, -29), Pair(-5, -78), Pair(-79, -30), Pair(-146, -70), Pair(-19, -143), Pair(119, -51), Pair(-35, -101),
        Pair(-48, -70), Pair(17, -57), Pair(10, -86), Pair(-179, -33), Pair(22, -31), Pair(-83, -30), Pair(-64, -71), Pair(-98, -68),
        Pair(-320, -4), Pair(-100, -13), Pair(-50, -83), Pair(-204, -29), Pair(-199, -36), Pair(-73, -60), Pair(-60, -40), Pair(-184, -34)
      },
      { // Piece 4
        Pair(26, -191), Pair(-200, -1), Pair(-50, -110), Pair(-28, -73), Pair(-13, -97), Pair(-141, -63), Pair(-36, -59), Pair(-117, -126),
        Pair(11, 22), Pair(-30, 0), Pair(6, -15), Pair(31, 0), Pair(-15, -93), Pair(-75, -36), Pair(-45, -38), Pair(47, 16),
        Pair(-80, -57), Pair(-5, -75), Pair(-32, -35), Pair(-40, -28), Pair(6, -61), Pair(-15, -14), Pair(-54, -105), Pair(-109, -164),
        Pair(-43, -85), Pair(35, -15), Pair(-1, 4), Pair(-47, -69), Pair(-41, -38), Pair(-21, -29), Pair(-37, -35), Pair(2, -71),
        Pair(-63, -117), Pair(-22, -65), Pair(-42, -84), Pair(-13, 4), Pair(-97, -57), Pair(6, -35), Pair(-66, -41), Pair(-49, -113),
        Pair(-19, -127), Pair(-27, -74), Pair(-36, -59), Pair(-55, -73), Pair(-122, -52), Pair(-97, -124), Pair(-47, -73), Pair(-77, -149),
        Pair(-39, -5), Pair(-64, -32), Pair(-45, 17), Pair(-26, 2), Pair(-103, -101), Pair(43, 23), Pair(-30, -62), Pair(-20, -33),
        Pair(-94, -110), Pair(-113, -134), Pair(-54, -95), Pair(-133, -58), Pair(-96, -83), Pair(-30, -30), Pair(-52, -153), Pair(-80, -138)
      },
      { // Piece 5
        Pair(149, -213), Pair(4, -51), Pair(30, -15), Pair(-33, -17), Pair(-67, -40), Pair(4, 5), Pair(-149, 14), Pair(112, -166),
        Pair(16, -46), Pair(74, 17), Pair(108, -3), Pair(-45, 49), Pair(-55, 17), Pair(29, 5), Pair(2, 11), Pair(-40, -51),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-57, 100), Pair(-9, 120), Pair(151, 123), Pair(152, 76), Pair(-70, 57), Pair(53, 139), Pair(-28, 129), Pair(-108, 57),
        Pair(94, 66), Pair(102, 66), Pair(298, 1), Pair(69, 62), Pair(109, 18), Pair(157, 1), Pair(85, 45), Pair(27, 62),
        Pair(-72, 62), Pair(-45, 76), Pair(27, 43), Pair(48, 17), Pair(63, -1), Pair(69, 15), Pair(-60, 76), Pair(-33, 37),
        Pair(-100, 26), Pair(-125, 80), Pair(12, 55), Pair(-8, 64), Pair(74, 42), Pair(-67, 39), Pair(-23, 38), Pair(-108, 14),
        Pair(-80, 31), Pair(-105, 40), Pair(-85, -7), Pair(18, -21), Pair(-61, 26), Pair(124, -7), Pair(-124, 38), Pair(-63, 23),
        Pair(-142, 51), Pair(-166, 49), Pair(-11, 85), Pair(35, 69), Pair(9, -13), Pair(-63, 21), Pair(-143, 55), Pair(-207, 66),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-71, -182), Pair(-58, -59), Pair(-22, -92), Pair(30, -13), Pair(-34, -27), Pair(49, -69), Pair(30, -46), Pair(-32, -205),
        Pair(-17, 4), Pair(-60, -36), Pair(-61, -105), Pair(-30, -7), Pair(39, -30), Pair(25, -36), Pair(-18, -65), Pair(-11, -80),
        Pair(-92, -153), Pair(17, -83), Pair(28, -36), Pair(57, -80), Pair(122, -55), Pair(75, -30), Pair(-18, -62), Pair(-7, -60),
        Pair(47, 5), Pair(12, -87), Pair(58, -7), Pair(-49, -47), Pair(83, -60), Pair(14, -20), Pair(29, 31), Pair(-7, -113),
        Pair(-7, -109), Pair(-105, -19), Pair(-6, -55), Pair(0, -35), Pair(179, -48), Pair(28, 7), Pair(-8, -105), Pair(-14, -90),
        Pair(-49, -58), Pair(0, -36), Pair(-32, -21), Pair(16, 8), Pair(5, -8), Pair(-8, 13), Pair(-44, -99), Pair(-35, -88),
        Pair(32, -56), Pair(-23, -24), Pair(-65, -83), Pair(-27, -22), Pair(-29, -69), Pair(-71, -119), Pair(-43, -106), Pair(60, 36),
        Pair(-29, -108), Pair(1, -61), Pair(1, -48), Pair(-12, -67), Pair(6, -123), Pair(-40, -35), Pair(-37, -100), Pair(-1, -23)
      },
      { // Piece 2
        Pair(16, -123), Pair(39, -79), Pair(54, -145), Pair(136, -50), Pair(-104, -80), Pair(-44, -105), Pair(7, -135), Pair(9, -101),
        Pair(-79, -146), Pair(60, -119), Pair(20, -155), Pair(65, -79), Pair(-46, -147), Pair(15, -83), Pair(26, -134), Pair(-20, -144),
        Pair(-9, -56), Pair(-18, -91), Pair(61, -58), Pair(-20, -132), Pair(69, -84), Pair(80, -103), Pair(4, -116), Pair(-93, -84),
        Pair(-56, -75), Pair(96, -61), Pair(200, -117), Pair(75, -80), Pair(110, -103), Pair(-54, -94), Pair(77, -114), Pair(40, -92),
        Pair(-33, -113), Pair(23, -84), Pair(66, -111), Pair(128, -57), Pair(101, -78), Pair(89, -127), Pair(-46, -141), Pair(83, -34),
        Pair(27, -50), Pair(38, -70), Pair(-19, -88), Pair(83, -148), Pair(65, -119), Pair(-23, -102), Pair(-1, -96), Pair(13, -79),
        Pair(0, -112), Pair(13, -121), Pair(37, -68), Pair(25, -80), Pair(95, -73), Pair(-21, -117), Pair(-27, -81), Pair(29, -67),
        Pair(-31, -52), Pair(8, -43), Pair(-115, -53), Pair(-44, -40), Pair(-61, -75), Pair(-56, -71), Pair(-44, -148), Pair(-38, -84)
      },
      { // Piece 3
        Pair(77, -170), Pair(-75, -77), Pair(137, -86), Pair(10, -120), Pair(13, -76), Pair(47, -100), Pair(-113, -48), Pair(58, -129),
        Pair(74, -54), Pair(6, -74), Pair(30, -132), Pair(70, -47), Pair(148, -139), Pair(88, -148), Pair(40, -143), Pair(139, -95),
        Pair(-19, -19), Pair(-148, -115), Pair(-39, -118), Pair(14, -96), Pair(24, -96), Pair(17, -20), Pair(-14, -102), Pair(-23, -135),
        Pair(-2, -86), Pair(81, -102), Pair(52, -51), Pair(-45, -85), Pair(0, -107), Pair(103, -131), Pair(157, -86), Pair(9, -72),
        Pair(-94, -85), Pair(-69, -111), Pair(-11, -159), Pair(7, -121), Pair(96, -118), Pair(39, -110), Pair(-10, -93), Pair(-24, -86),
        Pair(-45, -76), Pair(-19, -65), Pair(7, -197), Pair(-18, -68), Pair(-25, -108), Pair(-99, -91), Pair(1, -78), Pair(-4, -117),
        Pair(-55, -60), Pair(-81, -125), Pair(7, -56), Pair(-54, -160), Pair(-96, -110), Pair(-65, -128), Pair(-97, -159), Pair(-94, -171),
        Pair(-160, -103), Pair(-98, -91), Pair(-34, -115), Pair(-61, -109), Pair(29, -67), Pair(-127, -23), Pair(-40, -93), Pair(-205, -67)
      },
      { // Piece 4
        Pair(-11, -178), Pair(-73, -51), Pair(-83, -176), Pair(20, -45), Pair(-45, -58), Pair(30, -86), Pair(17, -178), Pair(-20, -189),
        Pair(41, -46), Pair(-81, -3), Pair(38, -44), Pair(-16, -39), Pair(-37, -105), Pair(-44, -156), Pair(-39, -56), Pair(0, -23),
        Pair(-6, 0), Pair(-19, -48), Pair(-3, -56), Pair(-5, 1), Pair(26, 27), Pair(72, 80), Pair(84, 126), Pair(-3, -4),
        Pair(-22, -60), Pair(-71, -36), Pair(-12, -38), Pair(-23, 19), Pair(-44, -68), Pair(1, 2), Pair(-15, -11), Pair(-26, -63),
        Pair(-1, -4), Pair(-35, -101), Pair(-29, -24), Pair(8, -24), Pair(-122, -20), Pair(27, 12), Pair(-41, -74), Pair(-27, -77),
        Pair(36, 41), Pair(22, 41), Pair(-44, -57), Pair(12, 55), Pair(-27, -68), Pair(-20, -48), Pair(-56, -41), Pair(40, 39),
        Pair(-32, -58), Pair(-53, -83), Pair(-60, -58), Pair(-23, -58), Pair(-49, -77), Pair(-101, -176), Pair(-24, -38), Pair(-16, -15),
        Pair(-21, -10), Pair(-56, -130), Pair(-5, -16), Pair(53, 50), Pair(-108, -197), Pair(-62, -85), Pair(-64, -124), Pair(-69, -142)
      },
      { // Piece 5
        Pair(74, -104), Pair(190, -77), Pair(-41, -36), Pair(52, -3), Pair(26, -25), Pair(-124, -13), Pair(-13, -27), Pair(-39, -129),
        Pair(12, -54), Pair(84, 8), Pair(-29, 35), Pair(78, 14), Pair(48, 1), Pair(-19, 12), Pair(57, 22), Pair(-80, -26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-121, 82), Pair(37, 102), Pair(15, 73), Pair(-51, 122), Pair(22, 90), Pair(-73, 150), Pair(-15, 104), Pair(-34, 70),
        Pair(-20, 92), Pair(40, 118), Pair(144, 86), Pair(-102, 102), Pair(-75, 93), Pair(-1, 59), Pair(-20, 107), Pair(-25, 84),
        Pair(-70, 53), Pair(-8, 79), Pair(8, 44), Pair(-57, 41), Pair(-41, 84), Pair(61, 40), Pair(-59, 71), Pair(-70, 53),
        Pair(-134, 53), Pair(-83, 52), Pair(19, 56), Pair(21, 7), Pair(-26, 40), Pair(-71, 43), Pair(18, 26), Pair(-158, 60),
        Pair(-145, 37), Pair(-135, 72), Pair(40, 30), Pair(-36, 30), Pair(-101, 31), Pair(-16, 38), Pair(-21, 31), Pair(-197, 44),
        Pair(-184, 65), Pair(-112, 65), Pair(-29, 31), Pair(3, 40), Pair(-141, 40), Pair(-116, 57), Pair(-36, 49), Pair(-145, 56),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-61, -86), Pair(21, -107), Pair(10, -98), Pair(-11, -72), Pair(-62, -89), Pair(-10, -63), Pair(-37, -120), Pair(-39, -111),
        Pair(-9, -145), Pair(12, -90), Pair(-49, -98), Pair(-77, -94), Pair(32, -83), Pair(0, -51), Pair(-11, -64), Pair(-23, -79),
        Pair(-11, -51), Pair(-16, -45), Pair(-38, -25), Pair(-47, -50), Pair(201, -141), Pair(24, -53), Pair(19, -107), Pair(-21, -111),
        Pair(-11, -150), Pair(-62, -119), Pair(-24, -58), Pair(8, -55), Pair(96, -23), Pair(27, -46), Pair(-26, -35), Pair(-59, -79),
        Pair(-48, -100), Pair(-38, -76), Pair(-28, 4), Pair(17, -91), Pair(48, -81), Pair(-47, -104), Pair(-97, -110), Pair(-44, -56),
        Pair(-18, -34), Pair(12, -60), Pair(-77, -30), Pair(19, -88), Pair(24, -10), Pair(38, -18), Pair(-46, -88), Pair(-75, -18),
        Pair(2, -3), Pair(-20, -52), Pair(-25, -50), Pair(-36, -86), Pair(1, -54), Pair(9, -70), Pair(-63, -79), Pair(10, -5),
        Pair(-15, -30), Pair(-53, -79), Pair(-47, -18), Pair(37, -61), Pair(0, -30), Pair(-23, -61), Pair(7, -20), Pair(-8, -31)
      },
      { // Piece 2
        Pair(-48, -9), Pair(-7, -2), Pair(-24, -75), Pair(43, -73), Pair(-66, -102), Pair(-16, -77), Pair(-98, -165), Pair(27, 34),
        Pair(17, -66), Pair(4, -33), Pair(1, -143), Pair(-65, -91), Pair(0, -20), Pair(7, -95), Pair(34, 11), Pair(-1, -62),
        Pair(-6, -87), Pair(94, -113), Pair(88, -56), Pair(23, -60), Pair(34, -72), Pair(19, -53), Pair(54, -69), Pair(14, -92),
        Pair(-38, -55), Pair(-74, -47), Pair(-73, -25), Pair(69, -122), Pair(0, -68), Pair(-62, -125), Pair(32, -94), Pair(-11, -130),
        Pair(3, -151), Pair(46, -91), Pair(-43, -25), Pair(134, -57), Pair(35, -70), Pair(-7, -96), Pair(5, -72), Pair(67, -86),
        Pair(-10, -61), Pair(-44, -61), Pair(13, -59), Pair(-41, -34), Pair(-7, 1), Pair(13, -64), Pair(35, -56), Pair(-28, -116),
        Pair(-56, -28), Pair(-6, -86), Pair(-74, -84), Pair(-31, -103), Pair(-57, -76), Pair(-28, -98), Pair(-148, -85), Pair(22, -82),
        Pair(14, 41), Pair(2, -95), Pair(16, -73), Pair(-23, -88), Pair(-11, -121), Pair(-42, -69), Pair(-26, -31), Pair(-37, -21)
      },
      { // Piece 3
        Pair(-18, -133), Pair(86, -108), Pair(-86, -119), Pair(14, -124), Pair(24, -67), Pair(-49, -95), Pair(26, -92), Pair(137, -114),
        Pair(87, -145), Pair(-36, -121), Pair(-25, -144), Pair(7, -99), Pair(49, -122), Pair(-61, -137), Pair(2, -155), Pair(-40, -130),
        Pair(58, -134), Pair(118, -129), Pair(83, -141), Pair(167, -124), Pair(-10, -98), Pair(77, -144), Pair(26, -96), Pair(14, -99),
        Pair(-22, -188), Pair(0, -82), Pair(-9, -91), Pair(-17, -161), Pair(-81, -66), Pair(-31, -168), Pair(-20, -117), Pair(-77, -112),
        Pair(-33, -121), Pair(16, -120), Pair(72, -122), Pair(22, -144), Pair(24, -122), Pair(-4, -72), Pair(44, -88), Pair(45, -116),
        Pair(-34, -107), Pair(-16, -123), Pair(34, -127), Pair(-25, -132), Pair(-40, -127), Pair(-37, -133), Pair(-33, -99), Pair(-30, -81),
        Pair(-114, -129), Pair(44, -169), Pair(58, -109), Pair(160, -148), Pair(29, -183), Pair(71, -183), Pair(46, -144), Pair(-112, -105),
        Pair(-50, -97), Pair(-4, -149), Pair(71, -99), Pair(80, -112), Pair(-68, -98), Pair(-83, -98), Pair(-21, -154), Pair(-59, -152)
      },
      { // Piece 4
        Pair(-169, -207), Pair(-88, -132), Pair(-83, -123), Pair(-15, -97), Pair(132, -120), Pair(21, -41), Pair(-47, -63), Pair(42, -157),
        Pair(-7, -65), Pair(-7, -121), Pair(-16, -18), Pair(-4, -83), Pair(-74, -73), Pair(-13, -9), Pair(-67, -140), Pair(-96, -109),
        Pair(-14, -92), Pair(-48, -106), Pair(-123, -132), Pair(32, -21), Pair(5, -57), Pair(-30, -45), Pair(-57, -109), Pair(-65, -65),
        Pair(-8, -14), Pair(50, 81), Pair(18, 15), Pair(-5, -23), Pair(0, -3), Pair(0, -11), Pair(29, 56), Pair(3, 10),
        Pair(-14, -49), Pair(-53, -130), Pair(58, 31), Pair(51, 11), Pair(17, 6), Pair(5, 57), Pair(25, 22), Pair(-10, -47),
        Pair(36, -9), Pair(68, 97), Pair(-36, -81), Pair(-10, -52), Pair(-50, -68), Pair(-10, -7), Pair(-47, -63), Pair(-59, -56),
        Pair(48, 26), Pair(-49, -134), Pair(-48, -109), Pair(-14, -48), Pair(2, 36), Pair(-18, -46), Pair(-20, -43), Pair(-81, -127),
        Pair(-73, -132), Pair(-30, -66), Pair(-13, -24), Pair(-32, -89), Pair(-8, -64), Pair(-22, -83), Pair(-48, -75), Pair(-51, -82)
      },
      { // Piece 5
        Pair(-42, -87), Pair(33, -72), Pair(-50, -15), Pair(-81, 7), Pair(56, -47), Pair(-20, 3), Pair(-2, -13), Pair(-43, -92),
        Pair(-67, -11), Pair(75, 1), Pair(-1, 28), Pair(74, 22), Pair(88, 3), Pair(26, 19), Pair(-15, 22), Pair(-33, -54),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-175, 96), Pair(53, 105), Pair(65, 83), Pair(59, 61), Pair(107, 109), Pair(26, 137), Pair(-91, 131), Pair(-118, 83),
        Pair(-183, 142), Pair(47, 101), Pair(85, 120), Pair(-97, 87), Pair(74, 100), Pair(-39, 93), Pair(-120, 115), Pair(-223, 124),
        Pair(-119, 98), Pair(-97, 63), Pair(-19, 71), Pair(-28, 76), Pair(19, 71), Pair(-76, 62), Pair(-87, 101), Pair(-83, 75),
        Pair(-108, 69), Pair(-85, 56), Pair(56, 39), Pair(103, 29), Pair(-32, 38), Pair(-55, 54), Pair(-6, 50), Pair(-103, 66),
        Pair(-127, 65), Pair(-55, 47), Pair(-24, 17), Pair(-67, 20), Pair(-32, 17), Pair(-18, 25), Pair(-83, 56), Pair(-117, 49),
        Pair(-184, 60), Pair(-126, 74), Pair(-127, 70), Pair(-21, 9), Pair(-107, 14), Pair(-141, 82), Pair(-74, 64), Pair(-94, 51),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-23, -150), Pair(-63, -158), Pair(-7, -158), Pair(-7, -71), Pair(-29, -15), Pair(-15, -104), Pair(11, -136), Pair(15, 75),
        Pair(-12, -95), Pair(3, -56), Pair(-32, -102), Pair(18, -56), Pair(-9, -129), Pair(-110, -76), Pair(-26, -127), Pair(-15, -131),
        Pair(-11, -197), Pair(-69, -160), Pair(58, -98), Pair(19, -89), Pair(21, -89), Pair(22, -34), Pair(56, -114), Pair(-23, -142),
        Pair(-43, -156), Pair(-50, -119), Pair(32, -112), Pair(13, -90), Pair(-11, -70), Pair(-68, -26), Pair(26, -156), Pair(-21, -134),
        Pair(-7, -97), Pair(-31, -61), Pair(46, -39), Pair(-5, -83), Pair(40, -79), Pair(-54, -112), Pair(-44, -111), Pair(-10, -133),
        Pair(-22, -145), Pair(-33, -76), Pair(-52, -119), Pair(21, -157), Pair(-43, -97), Pair(-103, -64), Pair(12, -63), Pair(-25, -97),
        Pair(-53, -139), Pair(5, 11), Pair(-13, -78), Pair(-19, -36), Pair(-75, -121), Pair(8, -65), Pair(1, -98), Pair(-40, -111),
        Pair(-21, -110), Pair(13, -66), Pair(-17, -138), Pair(-17, -120), Pair(-9, -68), Pair(-50, -62), Pair(-21, -41), Pair(5, -43)
      },
      { // Piece 2
        Pair(-7, -75), Pair(28, -53), Pair(-74, -115), Pair(27, -53), Pair(-65, -98), Pair(-38, -133), Pair(-67, -121), Pair(23, -69),
        Pair(-80, -96), Pair(13, -82), Pair(-42, -110), Pair(2, -81), Pair(-7, -87), Pair(23, -98), Pair(-24, -80), Pair(48, -101),
        Pair(-82, -55), Pair(-67, -50), Pair(28, -50), Pair(61, -97), Pair(17, -95), Pair(-98, -16), Pair(-44, -100), Pair(8, -80),
        Pair(-27, -68), Pair(-81, -47), Pair(-13, -67), Pair(-30, -56), Pair(53, -72), Pair(145, -94), Pair(10, -86), Pair(-11, -51),
        Pair(-7, 10), Pair(1, -46), Pair(3, -104), Pair(1, -98), Pair(88, -81), Pair(-39, -48), Pair(-18, -25), Pair(-42, -48),
        Pair(-8, -54), Pair(-11, -150), Pair(-12, -18), Pair(-32, -132), Pair(-31, -113), Pair(17, -120), Pair(5, -61), Pair(-34, -134),
        Pair(-18, 46), Pair(-6, -89), Pair(-59, -115), Pair(25, -129), Pair(-83, -177), Pair(-15, -65), Pair(-16, -135), Pair(-25, 30),
        Pair(-27, -42), Pair(40, 39), Pair(13, -40), Pair(-18, -125), Pair(-93, -73), Pair(-39, -91), Pair(-52, -58), Pair(-28, -102)
      },
      { // Piece 3
        Pair(211, -225), Pair(53, -175), Pair(58, -179), Pair(-26, -128), Pair(41, -128), Pair(32, -129), Pair(118, -197), Pair(106, -140),
        Pair(-5, -178), Pair(-21, -145), Pair(-10, -174), Pair(45, -151), Pair(77, -138), Pair(71, -176), Pair(-9, -177), Pair(4, -176),
        Pair(-32, -170), Pair(82, -159), Pair(28, -194), Pair(-33, -177), Pair(42, -182), Pair(62, -177), Pair(44, -148), Pair(42, -188),
        Pair(119, -196), Pair(-34, -190), Pair(48, -167), Pair(-44, -112), Pair(83, -180), Pair(105, -197), Pair(77, -163), Pair(-54, -183),
        Pair(-42, -150), Pair(-34, -180), Pair(23, -146), Pair(-9, -90), Pair(109, -225), Pair(4, -205), Pair(-38, -214), Pair(-16, -216),
        Pair(-26, -141), Pair(-32, -168), Pair(-61, -215), Pair(52, -139), Pair(36, -145), Pair(-152, -130), Pair(-21, -139), Pair(-51, -148),
        Pair(-5, -174), Pair(-26, -176), Pair(-19, -84), Pair(19, -180), Pair(-18, -164), Pair(-54, -211), Pair(-71, -170), Pair(29, -144),
        Pair(-24, -134), Pair(-44, -157), Pair(24, -181), Pair(-1, -209), Pair(41, -138), Pair(-56, -185), Pair(12, -176), Pair(18, -192)
      },
      { // Piece 4
        Pair(-69, -222), Pair(-89, -133), Pair(-96, -51), Pair(-27, -95), Pair(-66, -141), Pair(-158, -137), Pair(-82, -153), Pair(-65, -208),
        Pair(-25, -96), Pair(-93, -132), Pair(-54, -90), Pair(-14, -72), Pair(-34, -57), Pair(28, -63), Pair(-43, -78), Pair(-82, -107),
        Pair(-71, -66), Pair(-31, -106), Pair(-81, -115), Pair(-33, -78), Pair(-60, -44), Pair(-83, -150), Pair(-48, -103), Pair(-57, -91),
        Pair(-52, -131), Pair(9, -61), Pair(-2, -75), Pair(-51, -99), Pair(-17, -47), Pair(-17, -48), Pair(44, -70), Pair(-1, -72),
        Pair(-68, -131), Pair(-16, -3), Pair(-37, -69), Pair(-15, -12), Pair(-12, -44), Pair(11, -7), Pair(-55, -84), Pair(-71, -127),
        Pair(-106, -176), Pair(11, 38), Pair(-22, -35), Pair(10, -40), Pair(-3, -15), Pair(30, -12), Pair(-24, -55), Pair(-30, -44),
        Pair(-68, -143), Pair(-57, -145), Pair(-83, -203), Pair(-3, -73), Pair(-15, -64), Pair(-28, -54), Pair(-32, -103), Pair(4, -12),
        Pair(-69, -148), Pair(-27, -116), Pair(-127, -254), Pair(-31, -56), Pair(-25, -83), Pair(-32, -62), Pair(-58, -168), Pair(-64, -70)
      },
      { // Piece 5
        Pair(81, -124), Pair(-46, -8), Pair(-33, -41), Pair(-73, 8), Pair(-48, -4), Pair(-74, -9), Pair(-23, -30), Pair(76, -107),
        Pair(-74, -31), Pair(61, -1), Pair(-57, 26), Pair(13, 17), Pair(-66, 20), Pair(46, 16), Pair(76, 10), Pair(-60, -23),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-175, 104), Pair(-50, 117), Pair(-6, 187), Pair(46, 209), Pair(-12, 193), Pair(55, 237), Pair(-81, 225), Pair(-43, 231),
        Pair(-167, 229), Pair(-14, 119), Pair(24, 149), Pair(91, 136), Pair(-15, 154), Pair(-52, 204), Pair(-13, 144), Pair(-169, 216),
        Pair(-186, 140), Pair(23, 92), Pair(-58, 168), Pair(-4, 110), Pair(-40, 216), Pair(47, 122), Pair(-78, 155), Pair(-38, 139),
        Pair(-93, 59), Pair(-99, 140), Pair(34, 84), Pair(3, 29), Pair(-12, 122), Pair(-5, 89), Pair(-60, 134), Pair(-86, 70),
        Pair(-86, 34), Pair(-95, 94), Pair(-53, -16), Pair(33, 106), Pair(-34, 56), Pair(-11, 43), Pair(-38, 66), Pair(-26, 50),
        Pair(-91, 78), Pair(-182, 61), Pair(40, 91), Pair(-14, 72), Pair(-17, 26), Pair(-41, 104), Pair(-15, 85), Pair(-48, 58),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-7, -21), Pair(-30, -56), Pair(6, 48), Pair(-9, -96), Pair(-8, -110), Pair(-4, 3), Pair(-9, -124), Pair(4, -76),
        Pair(-5, -55), Pair(-1, -113), Pair(-40, -102), Pair(-71, -76), Pair(-13, 28), Pair(-15, -73), Pair(-19, -58), Pair(-50, -116),
        Pair(40, -33), Pair(-12, -43), Pair(-71, -63), Pair(-28, -81), Pair(4, 21), Pair(0, -92), Pair(55, -124), Pair(-33, -110),
        Pair(-34, -73), Pair(-18, -68), Pair(17, -34), Pair(31, 24), Pair(9, -55), Pair(5, -21), Pair(-13, -26), Pair(-11, -153),
        Pair(-17, -43), Pair(27, -93), Pair(-28, -21), Pair(-58, -82), Pair(16, -75), Pair(-11, -2), Pair(-19, -142), Pair(13, 29),
        Pair(-18, -39), Pair(-16, 22), Pair(9, -14), Pair(-28, -87), Pair(17, 18), Pair(-14, 10), Pair(-2, -76), Pair(-9, 8),
        Pair(-12, -131), Pair(25, 90), Pair(-1, -142), Pair(8, -71), Pair(-16, -84), Pair(-6, -4), Pair(-1, -17), Pair(-3, -35),
        Pair(-3, -57), Pair(37, -15), Pair(6, 0), Pair(8, 94), Pair(-8, -72), Pair(-2, -19), Pair(5, 23), Pair(-5, -74)
      },
      { // Piece 2
        Pair(14, -30), Pair(44, -6), Pair(11, -6), Pair(-7, -60), Pair(-3, 49), Pair(22, -81), Pair(-4, -74), Pair(7, 25),
        Pair(-6, 14), Pair(-76, -73), Pair(-61, 29), Pair(-16, -87), Pair(-110, -86), Pair(0, -5), Pair(21, 58), Pair(2, -56),
        Pair(4, -48), Pair(-36, -15), Pair(-16, 72), Pair(15, -59), Pair(16, 21), Pair(-48, 83), Pair(34, -34), Pair(-6, -59),
        Pair(-5, -14), Pair(4, 62), Pair(13, 11), Pair(-27, 47), Pair(69, -6), Pair(1, 10), Pair(-27, 46), Pair(-3, -124),
        Pair(1, 74), Pair(-19, 61), Pair(9, 104), Pair(1, -47), Pair(-84, -48), Pair(32, 34), Pair(5, 28), Pair(4, 80),
        Pair(-2, -102), Pair(-5, 25), Pair(-28, -35), Pair(4, 23), Pair(-33, 5), Pair(-5, -86), Pair(-7, -5), Pair(3, 14),
        Pair(-54, -63), Pair(22, 10), Pair(37, 83), Pair(-1, -54), Pair(49, 104), Pair(-14, -15), Pair(3, 32), Pair(1, 4),
        Pair(-15, 22), Pair(-3, -66), Pair(-11, -111), Pair(10, -108), Pair(-12, -30), Pair(-18, -60), Pair(-11, -59), Pair(-14, 20)
      },
      { // Piece 3
        Pair(7, -119), Pair(27, -78), Pair(38, -34), Pair(-7, -72), Pair(-54, -80), Pair(0, -126), Pair(-30, -97), Pair(1, -78),
        Pair(-5, -140), Pair(-15, -106), Pair(13, -80), Pair(1, -61), Pair(-8, -99), Pair(-64, -120), Pair(-15, 24), Pair(19, -95),
        Pair(-7, -74), Pair(3, -62), Pair(-9, -160), Pair(22, -95), Pair(-28, -109), Pair(30, -40), Pair(38, -116), Pair(-53, 0),
        Pair(3, -78), Pair(-7, -122), Pair(-12, -95), Pair(15, -132), Pair(5, -114), Pair(103, -74), Pair(-73, -130), Pair(-38, -69),
        Pair(37, -127), Pair(70, -40), Pair(3, -89), Pair(-16, -143), Pair(-1, -74), Pair(-34, -104), Pair(23, -15), Pair(-3, -83),
        Pair(23, -102), Pair(-7, -134), Pair(14, -91), Pair(65, -132), Pair(-34, -115), Pair(-2, -51), Pair(-22, -128), Pair(-58, -158),
        Pair(-42, -85), Pair(-41, 9), Pair(-82, -108), Pair(-5, -29), Pair(36, -74), Pair(-36, -76), Pair(-2, -123), Pair(40, -86),
        Pair(-32, -75), Pair(39, -102), Pair(10, -30), Pair(15, -48), Pair(66, -89), Pair(-33, -46), Pair(-34, -120), Pair(-44, -119)
      },
      { // Piece 4
        Pair(-34, -159), Pair(-58, -64), Pair(-29, -2), Pair(-9, -10), Pair(-38, 29), Pair(-70, -55), Pair(-56, -89), Pair(114, -75),
        Pair(-20, -64), Pair(8, -12), Pair(-26, -101), Pair(-13, -31), Pair(15, -48), Pair(-16, -19), Pair(19, 32), Pair(-117, -222),
        Pair(11, 17), Pair(-16, 8), Pair(-17, -22), Pair(-33, -42), Pair(6, -2), Pair(56, 81), Pair(-36, -28), Pair(-79, -119),
        Pair(-15, -32), Pair(27, 78), Pair(18, -42), Pair(-34, -1), Pair(18, 82), Pair(19, 53), Pair(-51, -63), Pair(-29, -28),
        Pair(10, 11), Pair(35, 42), Pair(12, -10), Pair(-44, -10), Pair(-22, -12), Pair(-43, -82), Pair(18, -1), Pair(46, 92),
        Pair(-35, -112), Pair(42, 57), Pair(15, 43), Pair(43, 18), Pair(-13, 31), Pair(9, -1), Pair(6, -34), Pair(-14, -34),
        Pair(10, -86), Pair(-11, -48), Pair(48, 59), Pair(25, 67), Pair(-27, -31), Pair(-29, -16), Pair(-36, -53), Pair(57, 83),
        Pair(-25, -105), Pair(8, 32), Pair(60, 108), Pair(-50, -108), Pair(-10, 12), Pair(-51, -117), Pair(-34, -81), Pair(-27, -68)
      },
      { // Piece 5
        Pair(-110, -76), Pair(62, 7), Pair(173, -50), Pair(-90, 59), Pair(-48, 41), Pair(49, -19), Pair(14, -6), Pair(23, -75),
        Pair(33, -30), Pair(-17, 64), Pair(-8, 55), Pair(2, 4), Pair(-36, 38), Pair(3, 5), Pair(11, 22), Pair(-79, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }}
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-3, 98), Pair(13, 65), Pair(18, 93), Pair(21, 106), Pair(24, 114), Pair(27, 123), Pair(31, 123), Pair(38, 116),
  Pair(42, 104)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-24, 43), Pair(-15, -4), Pair(-8, 20), Pair(-4, 38), Pair(1, 55), Pair(4, 68), Pair(5, 78), Pair(6, 83),
  Pair(10, 89), Pair(14, 90), Pair(23, 87), Pair(33, 83), Pair(64, 91), Pair(84, 68)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-40, -32), Pair(-31, -17), Pair(-28, 2), Pair(-27, 24), Pair(-25, 33), Pair(-19, 37), Pair(-14, 43), Pair(-7, 45),
  Pair(-3, 48), Pair(3, 53), Pair(7, 57), Pair(12, 59), Pair(18, 58), Pair(43, 46), Pair(85, 23)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-25, 202), Pair(-31, 162), Pair(-7, 114), Pair(-2, 102), Pair(0, 114), Pair(0, 136), Pair(2, 150), Pair(3, 171),
  Pair(5, 184), Pair(9, 186), Pair(10, 196), Pair(12, 199), Pair(13, 200), Pair(16, 202), Pair(14, 205), Pair(13, 205),
  Pair(14, 202), Pair(15, 198), Pair(19, 188), Pair(30, 176), Pair(39, 162), Pair(48, 143), Pair(46, 137), Pair(26, 143),
  Pair(26, 133), Pair(113, 75), Pair(159, 85), Pair(165, 65)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-34, -102), Pair(-33, -90), Pair(-18, -57), Pair(19, -22), Pair(38, 47), Pair(172, 134), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 0), Pair(17, 6), Pair(15, 20), Pair(46, 83), Pair(121, 156), Pair(12, 293), Pair(0, 0)};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(22, 10), Pair(13, 6), Pair(18, 13), Pair(46, 52), Pair(209, 36), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-26, -56), Pair(-9, -32), Pair(-7, -23), Pair(-9, -20), Pair(-18, -11), Pair(-15, -13), Pair(-3, -23), Pair(-35, -43)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(3, 2), Pair(-5, -11), Pair(-10, -11), Pair(-9, -18), Pair(-11, -19), Pair(-7, -12), Pair(-7, -9), Pair(11, -4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(21, 10), Pair(23, 8), Pair(23, 13), Pair(25, 10), Pair(28, 12), Pair(43, 8), Pair(51, 1), Pair(58, -1)
  },
  {
      Pair(10, 28), Pair(14, 13), Pair(16, 8), Pair(17, 8), Pair(14, 5), Pair(22, 0), Pair(27, -1), Pair(21, 12)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(14, -2), Pair(30, -8), Pair(20, -2),
  Pair(33, -12), Pair(34, -15), Pair(33, -13),
  Pair(51, -9), Pair(0, 0), Pair(45, -7),
  Pair(15, 4), Pair(7, 0), Pair(11, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-9, 8), Pair(-17, 14), Pair(-10, 8),
  Pair(-13, 5), Pair(-24, 10), Pair(-14, 5),
  Pair(-7, -1), Pair(-15, 5), Pair(-3, -2),
  Pair(8, -2), Pair(-6, 2), Pair(12, -3),
  Pair(42, -18), Pair(45, -8), Pair(41, -19),
  Pair(-22, 1), Pair(-38, -13), Pair(-14, -17),
  Pair(58, -54), Pair(0, 0), Pair(49, -52)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-1, 88), Pair(1, 75), Pair(2, 62), Pair(7, 51), Pair(8, 45), Pair(16, 39), Pair(5, 29)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-13, -30), Pair(-21, 17), Pair(-8, 39), Pair(1, 52), Pair(10, 59), Pair(12, 65), Pair(5, 69)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-644, 109);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-41, -28), Pair(-73, -8), Pair(-6, -23), Pair(-1, -25), Pair(-12, -18), Pair(-5, -18), Pair(-46, -4), Pair(-14, -10)
  },
  {
      Pair(-48, 58), Pair(-43, 22), Pair(-6, 2), Pair(-2, -8), Pair(-1, -5), Pair(5, -3), Pair(-30, 16), Pair(-25, 32)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 4), Pair(28, 1), Pair(71, -10), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 4), Pair(25, 6), Pair(68, -2), Pair(75, -19), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(25, -16), Pair(41, -15), Pair(66, -13), Pair(100, -15), Pair(159, -32), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(6, 21), Pair(17, 48), Pair(37, 63), Pair(97, 54), Pair(143, 62), Pair(243, 27), Pair(352, -32)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(29, 4), Pair(8, 10), Pair(29, -2), Pair(16, 21), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-2, 14), Pair(0, 28)
  },
  {
      Pair(-74, -53), Pair(-50, -68)
  },
  {
      Pair(-63, -71), Pair(-47, -93)
  },
  {
      Pair(-62, -17), Pair(-54, -34)
  },
  {
      Pair(-49, -15), Pair(-42, -25)
  },
  {
      Pair(21, 3), Pair(16, 10)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(16, 43), Pair(14, 39), Pair(24, 30), Pair(14, 22), Pair(23, 5)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-1, -22), Pair(6, -7)
  },
  {
      Pair(-18, 0), Pair(-2, -6)
  },
  {
      Pair(-29, -34), Pair(-20, -47)
  },
  {
      Pair(-56, -14), Pair(-39, -31)
  },
  {
      Pair(-36, -39), Pair(-29, -35)
  },
  {
      Pair(-47, -21), Pair(-15, -49)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-12, -17), Pair(0, -4)
  },
  {
      Pair(-44, -31), Pair(-23, -48)
  },
  {
      Pair(-13, -25), Pair(-10, -40)
  },
  {
      Pair(-51, -17), Pair(-36, -34)
  },
  {
      Pair(-44, -20), Pair(-33, -35)
  },
  {
      Pair(-4, -24), Pair(-5, -19)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(3, -24), Pair(11, -6)
  },
  {
      Pair(-30, -28), Pair(0, -14)
  },
  {
      Pair(-25, -22), Pair(-5, -8)
  },
  {
      Pair(6, -18), Pair(7, -15)
  },
  {
      Pair(-43, -18), Pair(-31, -21)
  },
  {
      Pair(2, -29), Pair(-9, -34)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-2, 38), Pair(18, 48), Pair(39, 24), Pair(39, 27), Pair(36, 36), Pair(41, 32), Pair(4, 61), Pair(21, 27),
  Pair(15, 25), Pair(11, 26), Pair(15, 33), Pair(12, 39), Pair(4, 37), Pair(-3, 39), Pair(1, 26), Pair(2, 22),
  Pair(5, 11), Pair(6, 23), Pair(-1, 30), Pair(10, 23), Pair(2, 30), Pair(-7, 24), Pair(-12, 19), Pair(-1, 5)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-2, 2), Pair(29, 11), Pair(27, -6), Pair(46, -3), Pair(46, -6), Pair(83, -10), Pair(34, 13), Pair(10, -1),
  Pair(13, -14), Pair(18, 16), Pair(24, 2), Pair(38, 8), Pair(17, 8), Pair(38, 3), Pair(10, 20), Pair(1, 12),
  Pair(-21, 6), Pair(16, 16), Pair(7, 18), Pair(17, 13), Pair(16, 18), Pair(-2, 13), Pair(-3, 18), Pair(-14, -10)
};

constexpr ScorePair kBishopPairBonus = Pair(18, 72);

constexpr ScorePair kTempoBonus = Pair(18, 19);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H