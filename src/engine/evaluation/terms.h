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
  Pair(75, 121), Pair(354, 332), Pair(376, 383), Pair(490, 708), Pair(1086, 1200), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-38, 80), Pair(-75, 88), Pair(-39, 34), Pair(-15, 8), Pair(6, -30), Pair(20, -72), Pair(-72, -91), Pair(-142, -41),
        Pair(1, 84), Pair(-1, 84), Pair(29, 43), Pair(45, -18), Pair(61, -8), Pair(104, -11), Pair(43, 22), Pair(19, 50),
        Pair(0, 33), Pair(7, 27), Pair(5, 8), Pair(19, -25), Pair(34, -23), Pair(43, -35), Pair(7, 12), Pair(4, 7),
        Pair(-3, 15), Pair(0, 23), Pair(9, -12), Pair(14, -15), Pair(20, -24), Pair(36, -32), Pair(19, -12), Pair(11, -13),
        Pair(-12, 10), Pair(-8, 14), Pair(-6, -1), Pair(0, -5), Pair(7, 5), Pair(11, -11), Pair(11, -7), Pair(12, -28),
        Pair(-5, 14), Pair(1, 17), Pair(-5, 11), Pair(3, -1), Pair(5, 16), Pair(24, 6), Pair(23, -5), Pair(5, -41),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-221, 71), Pair(-155, 85), Pair(-113, 102), Pair(-31, 47), Pair(-39, 53), Pair(-37, -46), Pair(-114, 109), Pair(-104, -82),
        Pair(-38, 44), Pair(-34, 62), Pair(-4, 62), Pair(-1, 80), Pair(0, 74), Pair(66, 31), Pair(18, 26), Pair(5, 21),
        Pair(-31, 44), Pair(-10, 66), Pair(8, 90), Pair(20, 75), Pair(38, 52), Pair(64, 56), Pair(4, 78), Pair(21, 47),
        Pair(2, 54), Pair(16, 65), Pair(30, 83), Pair(36, 105), Pair(32, 96), Pair(48, 85), Pair(16, 94), Pair(26, 62),
        Pair(-11, 50), Pair(8, 57), Pair(25, 83), Pair(28, 83), Pair(30, 92), Pair(39, 70), Pair(38, 70), Pair(5, 56),
        Pair(-22, 25), Pair(0, 46), Pair(9, 58), Pair(20, 73), Pair(27, 79), Pair(18, 58), Pair(15, 51), Pair(0, 13),
        Pair(-42, 48), Pair(-19, 50), Pair(-9, 35), Pair(6, 54), Pair(3, 59), Pair(4, 28), Pair(-8, 49), Pair(-5, 51),
        Pair(-64, 6), Pair(-17, 16), Pair(-25, 41), Pair(-8, 53), Pair(-2, 49), Pair(6, 39), Pair(-12, 18), Pair(-53, 27)
      },
      { // Piece 2
        Pair(-40, 76), Pair(-48, 51), Pair(-79, 64), Pair(-78, 68), Pair(-116, 62), Pair(-79, 38), Pair(-34, 90), Pair(16, 52),
        Pair(-48, 78), Pair(-24, 78), Pair(-6, 47), Pair(-46, 90), Pair(-25, 48), Pair(6, 46), Pair(-39, 89), Pair(-17, 72),
        Pair(-7, 69), Pair(-7, 78), Pair(7, 74), Pair(-3, 49), Pair(0, 63), Pair(22, 90), Pair(26, 76), Pair(6, 79),
        Pair(-18, 64), Pair(6, 70), Pair(-4, 69), Pair(14, 86), Pair(8, 65), Pair(15, 59), Pair(1, 66), Pair(-6, 72),
        Pair(-2, 49), Pair(-1, 50), Pair(6, 69), Pair(8, 57), Pair(15, 58), Pair(5, 53), Pair(5, 44), Pair(7, 33),
        Pair(-1, 35), Pair(17, 67), Pair(10, 58), Pair(10, 68), Pair(9, 73), Pair(15, 59), Pair(19, 40), Pair(13, 53),
        Pair(15, 41), Pair(14, 26), Pair(18, 35), Pair(5, 47), Pair(11, 55), Pair(21, 44), Pair(35, 51), Pair(22, 9),
        Pair(18, 21), Pair(28, 35), Pair(4, 43), Pair(-2, 49), Pair(9, 44), Pair(16, 62), Pair(21, 37), Pair(32, 11)
      },
      { // Piece 3
        Pair(45, 113), Pair(60, 113), Pair(-2, 150), Pair(13, 132), Pair(57, 108), Pair(80, 187), Pair(-58, 171), Pair(87, 20),
        Pair(31, 109), Pair(26, 120), Pair(42, 120), Pair(54, 118), Pair(46, 104), Pair(83, 91), Pair(96, 115), Pair(66, 111),
        Pair(38, 80), Pair(76, 86), Pair(58, 103), Pair(74, 85), Pair(90, 68), Pair(104, 70), Pair(148, 55), Pair(88, 64),
        Pair(44, 79), Pair(63, 86), Pair(68, 91), Pair(76, 85), Pair(75, 82), Pair(72, 82), Pair(86, 57), Pair(73, 52),
        Pair(26, 74), Pair(28, 97), Pair(35, 89), Pair(42, 89), Pair(38, 78), Pair(28, 84), Pair(71, 56), Pair(44, 44),
        Pair(19, 66), Pair(29, 72), Pair(25, 81), Pair(32, 80), Pair(38, 68), Pair(38, 63), Pair(76, 41), Pair(53, 10),
        Pair(9, 62), Pair(24, 75), Pair(35, 69), Pair(37, 74), Pair(41, 60), Pair(43, 58), Pair(70, 24), Pair(30, 16),
        Pair(32, 72), Pair(35, 70), Pair(40, 74), Pair(46, 68), Pair(46, 64), Pair(48, 70), Pair(55, 56), Pair(12, 48)
      },
      { // Piece 4
        Pair(-36, 167), Pair(1, 152), Pair(3, 166), Pair(33, 161), Pair(23, 175), Pair(36, 247), Pair(96, 118), Pair(146, 45),
        Pair(-15, 138), Pair(-35, 166), Pair(1, 155), Pair(-28, 186), Pair(-39, 204), Pair(16, 218), Pair(-17, 227), Pair(76, 94),
        Pair(-8, 136), Pair(-3, 152), Pair(-3, 165), Pair(5, 154), Pair(14, 183), Pair(36, 170), Pair(38, 194), Pair(7, 180),
        Pair(3, 121), Pair(14, 142), Pair(8, 135), Pair(11, 155), Pair(9, 166), Pair(32, 144), Pair(37, 154), Pair(39, 129),
        Pair(8, 123), Pair(14, 137), Pair(15, 131), Pair(10, 166), Pair(18, 149), Pair(16, 143), Pair(38, 113), Pair(32, 114),
        Pair(13, 100), Pair(22, 118), Pair(17, 135), Pair(15, 129), Pair(16, 131), Pair(24, 121), Pair(48, 85), Pair(36, 67),
        Pair(18, 76), Pair(23, 84), Pair(27, 80), Pair(25, 110), Pair(29, 100), Pair(39, 50), Pair(47, 32), Pair(42, 24),
        Pair(24, 74), Pair(15, 78), Pair(21, 78), Pair(29, 83), Pair(28, 78), Pair(19, 56), Pair(27, 7), Pair(22, 23)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, -15), Pair(17, 21), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-3, 22), Pair(1, -30)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(2, 21), Pair(-80, 65), Pair(-26, -56), Pair(18, -78), Pair(19, -111), Pair(24, -93), Pair(-94, 71), Pair(4, 78),
        Pair(4, 52), Pair(18, 40), Pair(46, -11), Pair(55, -44), Pair(77, -70), Pair(70, -8), Pair(24, 39), Pair(31, 38),
        Pair(-5, 20), Pair(0, 14), Pair(11, -15), Pair(14, -27), Pair(25, -29), Pair(25, -24), Pair(15, -10), Pair(18, 3),
        Pair(-20, 1), Pair(-12, 0), Pair(1, -25), Pair(15, -18), Pair(16, -29), Pair(20, -35), Pair(-2, -7), Pair(9, -17),
        Pair(-33, 2), Pair(-26, 7), Pair(-13, -18), Pair(-1, -14), Pair(6, -17), Pair(-6, -21), Pair(-1, -13), Pair(6, -31),
        Pair(-22, 2), Pair(-15, 5), Pair(-12, -4), Pair(3, -18), Pair(5, 8), Pair(10, -10), Pair(12, -6), Pair(-1, -27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-113, -84), Pair(-55, -13), Pair(-150, 79), Pair(42, -59), Pair(32, 8), Pair(2, 16), Pair(-114, -30), Pair(-88, -61),
        Pair(-31, 18), Pair(-47, 63), Pair(-11, 61), Pair(-43, 31), Pair(25, -7), Pair(24, 17), Pair(-26, 56), Pair(-36, 1),
        Pair(-37, 34), Pair(-16, 40), Pair(-21, 61), Pair(45, 25), Pair(27, 15), Pair(45, 26), Pair(-7, 51), Pair(9, -22),
        Pair(-4, 52), Pair(-6, 61), Pair(10, 64), Pair(15, 71), Pair(21, 66), Pair(27, 70), Pair(24, 48), Pair(16, 40),
        Pair(-24, 21), Pair(-8, 61), Pair(9, 61), Pair(19, 52), Pair(14, 60), Pair(32, 30), Pair(12, 54), Pair(-10, 23),
        Pair(-33, 16), Pair(-12, 20), Pair(-6, 26), Pair(14, 30), Pair(19, 26), Pair(6, 23), Pair(6, 18), Pair(-19, 2),
        Pair(-43, 20), Pair(-32, 39), Pair(-23, 12), Pair(-6, 26), Pair(-7, 20), Pair(-8, 1), Pair(-12, -10), Pair(-15, 32),
        Pair(-102, -4), Pair(-38, 13), Pair(-41, 10), Pair(-13, 24), Pair(-17, 11), Pair(-6, -7), Pair(-40, 30), Pair(-68, -79)
      },
      { // Piece 2
        Pair(-9, 30), Pair(-41, 3), Pair(-63, 8), Pair(-140, 35), Pair(-145, 31), Pair(-33, -37), Pair(6, -27), Pair(-30, 40),
        Pair(-26, 5), Pair(-24, 20), Pair(-2, 2), Pair(-51, 46), Pair(-26, 59), Pair(-7, 20), Pair(-60, 33), Pair(-61, 6),
        Pair(-20, 42), Pair(20, 16), Pair(2, 18), Pair(32, 22), Pair(14, 20), Pair(4, 60), Pair(30, 10), Pair(-3, 38),
        Pair(-29, 37), Pair(-8, 40), Pair(-4, 33), Pair(11, 19), Pair(19, 23), Pair(12, 27), Pair(4, 13), Pair(-20, 35),
        Pair(-21, 41), Pair(-5, 17), Pair(-7, 19), Pair(3, 29), Pair(9, 21), Pair(2, 20), Pair(-1, 15), Pair(-13, 38),
        Pair(-7, 15), Pair(6, 12), Pair(6, 14), Pair(2, 25), Pair(8, 20), Pair(10, 11), Pair(17, 29), Pair(14, 16),
        Pair(8, -12), Pair(12, 1), Pair(12, 4), Pair(-2, 11), Pair(2, 14), Pair(15, 26), Pair(40, 5), Pair(18, 12),
        Pair(-11, 19), Pair(-2, 31), Pair(-3, 19), Pair(6, 2), Pair(2, 29), Pair(-3, 24), Pair(5, 44), Pair(15, -26)
      },
      { // Piece 3
        Pair(97, 35), Pair(56, 61), Pair(14, 94), Pair(34, 57), Pair(106, 11), Pair(-12, 48), Pair(23, 72), Pair(20, 33),
        Pair(26, 46), Pair(14, 60), Pair(43, 37), Pair(84, 24), Pair(21, 36), Pair(-9, 69), Pair(24, 64), Pair(9, 69),
        Pair(-4, 67), Pair(71, 41), Pair(51, 33), Pair(59, 14), Pair(24, 32), Pair(40, 28), Pair(62, 26), Pair(37, 23),
        Pair(28, 17), Pair(21, 34), Pair(40, 32), Pair(52, 12), Pair(27, 19), Pair(37, 24), Pair(45, 12), Pair(12, 35),
        Pair(-4, 18), Pair(-21, 40), Pair(-6, 34), Pair(0, 33), Pair(9, 9), Pair(-12, 37), Pair(14, 23), Pair(12, 11),
        Pair(-27, 24), Pair(-2, 6), Pair(0, 7), Pair(12, 6), Pair(3, 9), Pair(-12, 35), Pair(10, 19), Pair(-4, 7),
        Pair(-18, 3), Pair(7, -2), Pair(-1, 24), Pair(-16, 17), Pair(-8, 24), Pair(-10, 13), Pair(11, -14), Pair(-28, -4),
        Pair(-6, 17), Pair(2, 20), Pair(15, 14), Pair(15, 1), Pair(21, 3), Pair(11, 18), Pair(-5, 19), Pair(-29, 1)
      },
      { // Piece 4
        Pair(52, 34), Pair(46, 53), Pair(10, 58), Pair(70, 31), Pair(-29, 59), Pair(7, 75), Pair(5, 78), Pair(51, 70),
        Pair(28, 36), Pair(-27, 60), Pair(-13, 86), Pair(-46, 124), Pair(-60, 193), Pair(-11, 109), Pair(-16, 100), Pair(57, 15),
        Pair(5, 34), Pair(28, 9), Pair(18, 44), Pair(6, 126), Pair(17, 62), Pair(18, 98), Pair(33, 38), Pair(13, 92),
        Pair(9, 33), Pair(15, 49), Pair(21, 79), Pair(-12, 79), Pair(-6, 141), Pair(21, 79), Pair(21, 68), Pair(45, 29),
        Pair(9, 23), Pair(2, 68), Pair(3, 81), Pair(-4, 75), Pair(10, 82), Pair(7, 53), Pair(30, 13), Pair(7, 83),
        Pair(9, 3), Pair(16, 38), Pair(7, 51), Pair(9, 40), Pair(9, 45), Pair(23, 14), Pair(19, 31), Pair(-12, 60),
        Pair(10, -58), Pair(23, -10), Pair(17, 2), Pair(13, 22), Pair(31, -12), Pair(28, -26), Pair(15, -5), Pair(20, 2),
        Pair(-8, 29), Pair(-6, 47), Pair(11, -14), Pair(19, -18), Pair(23, -33), Pair(-2, -10), Pair(-10, -18), Pair(-24, -4)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, -35), Pair(39, -2), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(7, 6), Pair(12, -42)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, 18), Pair(-31, 19), Pair(-25, -35), Pair(-6, -52), Pair(18, -82), Pair(32, -94), Pair(3, -44), Pair(32, -41),
        Pair(-7, 61), Pair(-4, 52), Pair(31, 3), Pair(37, -19), Pair(37, -28), Pair(101, -51), Pair(22, 14), Pair(-18, 37),
        Pair(-6, 25), Pair(-6, 20), Pair(-15, 2), Pair(5, -20), Pair(28, -24), Pair(29, -20), Pair(1, 12), Pair(-7, -2),
        Pair(-12, 4), Pair(-15, 15), Pair(-4, -11), Pair(3, -16), Pair(8, -20), Pair(18, -24), Pair(8, -9), Pair(8, -14),
        Pair(-17, -1), Pair(-25, 14), Pair(-17, -6), Pair(-10, -6), Pair(2, -5), Pair(-5, -9), Pair(1, -14), Pair(11, -29),
        Pair(-11, 5), Pair(-18, 16), Pair(-14, 2), Pair(-15, 11), Pair(-6, 19), Pair(10, -2), Pair(19, -9), Pair(2, -33),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-193, -38), Pair(-142, 64), Pair(-130, 48), Pair(23, -6), Pair(-45, 35), Pair(12, -33), Pair(-45, -34), Pair(-129, -41),
        Pair(-24, -4), Pair(-31, 33), Pair(7, 25), Pair(25, 31), Pair(36, 8), Pair(12, 21), Pair(-25, 4), Pair(-52, -13),
        Pair(-55, 57), Pair(-3, 26), Pair(25, 40), Pair(47, 32), Pair(65, 8), Pair(88, 6), Pair(39, 17), Pair(8, -1),
        Pair(5, 17), Pair(6, 47), Pair(23, 52), Pair(57, 45), Pair(51, 51), Pair(67, 34), Pair(29, 49), Pair(36, 11),
        Pair(-22, 24), Pair(3, 48), Pair(24, 53), Pair(38, 49), Pair(48, 45), Pair(53, 37), Pair(48, 25), Pair(15, 33),
        Pair(-38, 25), Pair(-12, 36), Pair(2, 39), Pair(15, 54), Pair(28, 49), Pair(15, 32), Pair(16, 17), Pair(-2, 9),
        Pair(-49, 28), Pair(-41, 29), Pair(-20, 26), Pair(-1, 36), Pair(0, 43), Pair(-3, 11), Pair(0, 9), Pair(-11, 24),
        Pair(-81, -21), Pair(-38, 1), Pair(-33, 20), Pair(-12, 27), Pair(-22, 34), Pair(-7, 17), Pair(-28, 17), Pair(-74, 10)
      },
      { // Piece 2
        Pair(-20, 28), Pair(-58, 49), Pair(-76, 44), Pair(-126, 55), Pair(-114, 46), Pair(-63, 13), Pair(-117, 62), Pair(-55, 16),
        Pair(-49, 24), Pair(-26, 29), Pair(-10, 22), Pair(13, -4), Pair(-22, 30), Pair(-26, 31), Pair(-32, 28), Pair(9, -25),
        Pair(-16, 21), Pair(-17, 42), Pair(-19, 48), Pair(3, 19), Pair(-12, 32), Pair(8, 27), Pair(-20, 34), Pair(1, 10),
        Pair(-22, 24), Pair(-7, 38), Pair(-5, 28), Pair(15, 37), Pair(30, 24), Pair(37, 25), Pair(25, 19), Pair(-2, 25),
        Pair(-27, 22), Pair(0, 23), Pair(5, 24), Pair(11, 26), Pair(21, 15), Pair(8, 15), Pair(6, 13), Pair(6, -7),
        Pair(-9, 19), Pair(-3, 29), Pair(6, 25), Pair(7, 27), Pair(3, 36), Pair(10, 22), Pair(7, 13), Pair(11, 18),
        Pair(-12, 21), Pair(6, 7), Pair(9, 12), Pair(-7, 24), Pair(2, 23), Pair(19, 11), Pair(23, 17), Pair(18, -12),
        Pair(16, -5), Pair(20, -11), Pair(-3, 14), Pair(2, 0), Pair(-6, 16), Pair(-3, 31), Pair(27, 12), Pair(-4, 21)
      },
      { // Piece 3
        Pair(19, 53), Pair(15, 62), Pair(0, 64), Pair(4, 59), Pair(35, 43), Pair(72, 38), Pair(43, 70), Pair(10, 78),
        Pair(20, 52), Pair(13, 57), Pair(28, 63), Pair(26, 62), Pair(19, 63), Pair(35, 32), Pair(-10, 65), Pair(69, 29),
        Pair(11, 40), Pair(46, 43), Pair(46, 45), Pair(40, 36), Pair(55, 30), Pair(115, 3), Pair(125, 2), Pair(45, 14),
        Pair(11, 38), Pair(28, 45), Pair(38, 42), Pair(51, 32), Pair(63, 21), Pair(58, 30), Pair(75, 9), Pair(22, 33),
        Pair(-13, 27), Pair(-19, 62), Pair(-2, 49), Pair(9, 40), Pair(13, 30), Pair(16, 28), Pair(23, 16), Pair(11, 17),
        Pair(-16, 19), Pair(-9, 36), Pair(-5, 36), Pair(2, 28), Pair(7, 22), Pair(9, 23), Pair(40, -1), Pair(33, -33),
        Pair(-28, 24), Pair(-11, 27), Pair(-6, 27), Pair(2, 32), Pair(-1, 19), Pair(12, 12), Pair(9, 12), Pair(-26, 4),
        Pair(-12, 33), Pair(-7, 28), Pair(1, 27), Pair(8, 25), Pair(10, 17), Pair(12, 26), Pair(12, 19), Pair(-26, 13)
      },
      { // Piece 4
        Pair(-25, 42), Pair(-44, 71), Pair(8, 44), Pair(4, 46), Pair(27, 42), Pair(14, 79), Pair(100, -17), Pair(15, 56),
        Pair(-4, 38), Pair(-22, 81), Pair(12, 52), Pair(2, 82), Pair(-22, 105), Pair(-4, 75), Pair(7, 103), Pair(65, 50),
        Pair(20, 4), Pair(10, 42), Pair(8, 59), Pair(22, 57), Pair(22, 81), Pair(69, 90), Pair(27, 105), Pair(28, 82),
        Pair(7, 37), Pair(33, 47), Pair(21, 40), Pair(18, 69), Pair(25, 99), Pair(34, 75), Pair(52, 71), Pair(31, 63),
        Pair(8, 35), Pair(24, 40), Pair(22, 48), Pair(25, 72), Pair(28, 67), Pair(18, 73), Pair(51, 33), Pair(31, 40),
        Pair(14, 10), Pair(22, 21), Pair(20, 53), Pair(25, 40), Pair(27, 42), Pair(29, 49), Pair(33, 26), Pair(49, -27),
        Pair(15, 18), Pair(20, 26), Pair(30, 7), Pair(24, 38), Pair(31, 26), Pair(39, -5), Pair(52, -56), Pair(26, -23),
        Pair(21, 16), Pair(20, 8), Pair(16, 2), Pair(30, 4), Pair(19, 0), Pair(12, -2), Pair(41, -68), Pair(-13, 22)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(1, -32), Pair(35, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(5, 11), Pair(0, -33)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, -21), Pair(2, -16), Pair(-67, -15), Pair(-22, -66), Pair(41, -78), Pair(-64, -36), Pair(-14, 38), Pair(12, -5),
        Pair(-24, 49), Pair(-21, 39), Pair(19, 1), Pair(48, -45), Pair(11, -14), Pair(93, -52), Pair(23, 25), Pair(-22, 33),
        Pair(-11, 13), Pair(-35, 18), Pair(-26, -4), Pair(-3, -22), Pair(13, -23), Pair(19, -15), Pair(-4, 7), Pair(-51, 24),
        Pair(-33, 7), Pair(-37, 17), Pair(-28, -4), Pair(-27, 4), Pair(-17, -8), Pair(11, -17), Pair(1, -2), Pair(-14, -4),
        Pair(-36, 1), Pair(-48, 13), Pair(-28, -3), Pair(-38, 8), Pair(-7, -5), Pair(-9, -14), Pair(-8, -12), Pair(-11, -19),
        Pair(-34, 10), Pair(-32, 14), Pair(-17, 4), Pair(-28, -4), Pair(-33, 29), Pair(3, -2), Pair(17, -7), Pair(-16, -20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-119, -45), Pair(-73, -47), Pair(-57, 0), Pair(65, -29), Pair(68, -27), Pair(31, 31), Pair(-67, -37), Pair(-91, -162),
        Pair(26, -4), Pair(43, -8), Pair(47, -30), Pair(128, -14), Pair(127, -40), Pair(75, -44), Pair(1, -1), Pair(84, -71),
        Pair(-1, -15), Pair(-34, 18), Pair(34, 33), Pair(84, -12), Pair(101, 2), Pair(36, 10), Pair(35, -22), Pair(9, -40),
        Pair(-25, 15), Pair(25, 4), Pair(35, 32), Pair(101, 6), Pair(86, 20), Pair(84, 0), Pair(157, -47), Pair(20, -6),
        Pair(0, 25), Pair(-20, 10), Pair(17, 32), Pair(37, 33), Pair(57, 24), Pair(80, -1), Pair(52, 8), Pair(72, -32),
        Pair(-107, 30), Pair(-7, 13), Pair(11, 22), Pair(3, 48), Pair(43, 10), Pair(42, 7), Pair(65, -15), Pair(2, -2),
        Pair(-76, 26), Pair(-38, -7), Pair(-46, 16), Pair(-3, 33), Pair(1, 28), Pair(-30, 26), Pair(14, 2), Pair(-14, -4),
        Pair(-147, -32), Pair(-61, -8), Pair(-88, 27), Pair(-48, 4), Pair(20, -9), Pair(-4, 10), Pair(-61, 36), Pair(-140, -64)
      },
      { // Piece 2
        Pair(-32, 26), Pair(58, -8), Pair(-60, 12), Pair(-36, 5), Pair(-64, 46), Pair(34, -8), Pair(-83, 19), Pair(-140, 28),
        Pair(-51, 16), Pair(8, 13), Pair(-29, 10), Pair(53, -26), Pair(43, -41), Pair(3, -19), Pair(-78, 13), Pair(-67, 9),
        Pair(-21, 13), Pair(-40, 33), Pair(-5, 9), Pair(6, 6), Pair(31, -4), Pair(65, 19), Pair(-37, 28), Pair(-32, 21),
        Pair(28, -26), Pair(-10, 3), Pair(-40, 40), Pair(38, 5), Pair(44, 4), Pair(4, 6), Pair(60, -7), Pair(-23, 9),
        Pair(-1, -11), Pair(10, 2), Pair(-2, 10), Pair(36, 10), Pair(5, 4), Pair(35, -6), Pair(-6, 10), Pair(53, -8),
        Pair(-23, 11), Pair(-30, 26), Pair(7, 0), Pair(1, 25), Pair(14, 16), Pair(-15, 15), Pair(16, 4), Pair(27, 1),
        Pair(-56, -8), Pair(-3, 0), Pair(11, 0), Pair(-33, 24), Pair(-23, 17), Pair(1, -4), Pair(17, -3), Pair(13, -27),
        Pair(12, -15), Pair(-45, 16), Pair(-9, -7), Pair(-21, -6), Pair(-22, 11), Pair(-2, 5), Pair(-3, -9), Pair(1, -48)
      },
      { // Piece 3
        Pair(2, 29), Pair(-44, 50), Pair(-32, 46), Pair(28, 15), Pair(-8, 30), Pair(-73, 55), Pair(89, -9), Pair(31, 35),
        Pair(-24, 12), Pair(3, 22), Pair(30, 0), Pair(48, 3), Pair(21, 5), Pair(69, -9), Pair(26, 7), Pair(13, -1),
        Pair(3, 15), Pair(-3, 34), Pair(-3, 32), Pair(2, 11), Pair(-35, 15), Pair(60, -6), Pair(54, 1), Pair(30, 2),
        Pair(-15, 28), Pair(5, 17), Pair(-12, 40), Pair(39, 8), Pair(33, 1), Pair(62, 7), Pair(96, -8), Pair(-10, 1),
        Pair(-81, 29), Pair(-45, 42), Pair(-33, 18), Pair(-33, 21), Pair(-20, 14), Pair(-16, 23), Pair(34, 4), Pair(-38, 21),
        Pair(-101, 37), Pair(-72, 33), Pair(-85, 29), Pair(-59, 28), Pair(-33, 8), Pair(4, -6), Pair(3, -6), Pair(-18, -12),
        Pair(-59, -1), Pair(-92, 25), Pair(-50, 9), Pair(-52, 18), Pair(-35, 5), Pair(-27, -6), Pair(-69, 22), Pair(-74, 15),
        Pair(-61, 21), Pair(-55, 18), Pair(-40, 15), Pair(-35, 10), Pair(-36, 9), Pair(-33, 15), Pair(-10, -15), Pair(-85, 13)
      },
      { // Piece 4
        Pair(-9, 17), Pair(77, -22), Pair(65, 4), Pair(179, -56), Pair(98, 14), Pair(69, 21), Pair(118, -16), Pair(17, 31),
        Pair(41, -44), Pair(73, -64), Pair(6, 25), Pair(17, 2), Pair(90, -13), Pair(62, 38), Pair(62, -40), Pair(94, -4),
        Pair(6, -28), Pair(-29, 35), Pair(16, 43), Pair(34, 31), Pair(26, 57), Pair(134, 20), Pair(113, -48), Pair(124, -26),
        Pair(6, 1), Pair(37, -13), Pair(31, 15), Pair(78, -12), Pair(92, 4), Pair(139, -4), Pair(93, -14), Pair(81, 19),
        Pair(41, -48), Pair(31, 7), Pair(68, -33), Pair(64, -10), Pair(88, -5), Pair(28, 38), Pair(108, -17), Pair(121, -46),
        Pair(25, -38), Pair(11, 34), Pair(12, 33), Pair(-10, 37), Pair(25, 36), Pair(49, -15), Pair(75, -21), Pair(99, -88),
        Pair(-2, 23), Pair(26, -26), Pair(32, -2), Pair(27, 10), Pair(51, -37), Pair(35, -27), Pair(43, -32), Pair(31, -43),
        Pair(7, 31), Pair(-12, 13), Pair(26, -40), Pair(5, 16), Pair(-6, -20), Pair(17, -39), Pair(-42, -34), Pair(-43, -86)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, -18), Pair(74, -15), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(15, 10), Pair(-1, -27)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-83, 28), Pair(-68, -9), Pair(-121, 21), Pair(-39, -22), Pair(-14, -17), Pair(-91, 25), Pair(-103, 79), Pair(7, 7),
        Pair(-63, 49), Pair(-8, 25), Pair(-73, 18), Pair(112, -39), Pair(-24, 12), Pair(-3, 16), Pair(38, 35), Pair(-7, 38),
        Pair(-47, 15), Pair(-36, 5), Pair(-41, -3), Pair(-36, -10), Pair(7, -20), Pair(12, -8), Pair(20, -7), Pair(11, -6),
        Pair(-23, -5), Pair(-34, 2), Pair(-65, -6), Pair(-44, 0), Pair(44, -30), Pair(14, -31), Pair(35, -19), Pair(15, -17),
        Pair(-54, -1), Pair(-28, -6), Pair(-55, 5), Pair(-4, 1), Pair(-11, 4), Pair(6, -17), Pair(1, -16), Pair(-10, -20),
        Pair(-47, 11), Pair(-26, 7), Pair(-15, -2), Pair(14, -17), Pair(-32, 26), Pair(50, -22), Pair(34, -14), Pair(-12, -18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-124, -86), Pair(-39, -8), Pair(-56, -42), Pair(33, -33), Pair(12, -19), Pair(54, -48), Pair(7, -35), Pair(-64, -91),
        Pair(38, -76), Pair(-71, -53), Pair(-42, -24), Pair(55, -28), Pair(55, -6), Pair(71, -49), Pair(-79, -46), Pair(-85, -39),
        Pair(-84, -9), Pair(-8, -26), Pair(-41, 15), Pair(68, 1), Pair(123, -58), Pair(121, -60), Pair(-32, -51), Pair(-9, 8),
        Pair(-19, -20), Pair(-21, 0), Pair(2, 8), Pair(96, -8), Pair(122, -38), Pair(131, -34), Pair(-32, -10), Pair(122, -58),
        Pair(-15, -25), Pair(48, -33), Pair(-11, -7), Pair(106, -30), Pair(96, -30), Pair(182, -51), Pair(114, -17), Pair(137, -29),
        Pair(-134, 26), Pair(-49, 1), Pair(72, -46), Pair(19, 23), Pair(45, -3), Pair(12, -19), Pair(-36, -6), Pair(-36, -54),
        Pair(-70, -11), Pair(-1, -30), Pair(24, -30), Pair(3, -4), Pair(18, -10), Pair(65, -54), Pair(22, -15), Pair(-39, 37),
        Pair(-18, -43), Pair(-107, 11), Pair(-29, -21), Pair(-22, -45), Pair(-12, -32), Pair(34, -10), Pair(-6, 9), Pair(0, -41)
      },
      { // Piece 2
        Pair(-56, -13), Pair(-36, -20), Pair(-47, -36), Pair(12, -11), Pair(-8, 3), Pair(15, -18), Pair(-21, -1), Pair(47, -7),
        Pair(-84, 15), Pair(4, 2), Pair(-72, -16), Pair(-40, 19), Pair(-11, -11), Pair(-89, 2), Pair(-58, 24), Pair(-76, 5),
        Pair(-11, 1), Pair(-92, 20), Pair(67, -27), Pair(-21, 19), Pair(-49, -9), Pair(-21, -2), Pair(20, 5), Pair(-14, -54),
        Pair(77, -27), Pair(-72, 19), Pair(-50, 14), Pair(10, 14), Pair(-39, -10), Pair(65, -15), Pair(103, -37), Pair(56, -36),
        Pair(-98, 38), Pair(47, -39), Pair(-91, 16), Pair(-31, -11), Pair(-30, 1), Pair(89, -53), Pair(14, 12), Pair(23, -19),
        Pair(-19, 1), Pair(-97, 4), Pair(-3, 4), Pair(-41, 1), Pair(3, 25), Pair(19, -3), Pair(-53, 18), Pair(66, -32),
        Pair(-95, 49), Pair(-36, -14), Pair(6, -22), Pair(-18, -18), Pair(-28, 2), Pair(52, -34), Pair(50, -32), Pair(-50, -12),
        Pair(-43, -45), Pair(19, -16), Pair(-70, 1), Pair(-23, -35), Pair(-69, 19), Pair(-26, -20), Pair(-7, -53), Pair(-8, -50)
      },
      { // Piece 3
        Pair(-59, -9), Pair(-98, 34), Pair(-13, -7), Pair(-96, 14), Pair(-98, 40), Pair(41, -15), Pair(-31, 36), Pair(-48, -2),
        Pair(-68, -11), Pair(-10, -8), Pair(-81, 20), Pair(-61, 15), Pair(33, -21), Pair(76, -40), Pair(57, -26), Pair(9, -29),
        Pair(35, -27), Pair(9, -20), Pair(-18, -10), Pair(65, -24), Pair(160, -65), Pair(73, -35), Pair(63, -38), Pair(-40, -11),
        Pair(-5, -13), Pair(-49, -3), Pair(59, -45), Pair(-56, -16), Pair(114, -51), Pair(59, -43), Pair(29, -56), Pair(-53, -30),
        Pair(-88, 1), Pair(-63, 13), Pair(-32, -1), Pair(-35, -7), Pair(-64, 27), Pair(50, -28), Pair(78, -28), Pair(76, -28),
        Pair(-130, 4), Pair(-33, -49), Pair(-73, 7), Pair(-34, -20), Pair(-21, 10), Pair(56, -29), Pair(63, -45), Pair(-5, -37),
        Pair(-125, -9), Pair(-104, -47), Pair(-129, 32), Pair(-74, -27), Pair(-49, -34), Pair(-2, -28), Pair(-30, -34), Pair(2, -92),
        Pair(-117, 8), Pair(-15, -31), Pair(-47, -17), Pair(-27, -22), Pair(-49, -12), Pair(-26, -20), Pair(-20, 10), Pair(2, -59)
      },
      { // Piece 4
        Pair(-3, -37), Pair(6, -90), Pair(85, -46), Pair(50, -1), Pair(-51, -15), Pair(129, -116), Pair(104, -116), Pair(82, -49),
        Pair(52, -138), Pair(99, -99), Pair(18, -33), Pair(134, -96), Pair(84, -57), Pair(178, -108), Pair(144, -109), Pair(224, -107),
        Pair(10, -51), Pair(27, -59), Pair(13, -68), Pair(40, -5), Pair(39, -7), Pair(170, -69), Pair(154, -105), Pair(190, -201),
        Pair(63, 49), Pair(35, -70), Pair(-79, 27), Pair(78, 8), Pair(137, -46), Pair(32, 64), Pair(32, -136), Pair(11, -1),
        Pair(-8, -93), Pair(-52, -15), Pair(93, -20), Pair(-16, 34), Pair(62, -27), Pair(90, -76), Pair(84, -6), Pair(-18, 2),
        Pair(57, -60), Pair(-74, -21), Pair(20, -41), Pair(66, -3), Pair(-11, -84), Pair(146, -101), Pair(1, -35), Pair(-10, -14),
        Pair(76, -137), Pair(-16, -8), Pair(-31, 44), Pair(18, -83), Pair(-39, -83), Pair(7, -41), Pair(22, -31), Pair(-32, -29),
        Pair(-74, -38), Pair(-91, -10), Pair(32, -79), Pair(-26, 21), Pair(-9, -32), Pair(-54, -70), Pair(19, -49), Pair(4, 20)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, -5), Pair(79, 7), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(33, 22), Pair(9, -21)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(60, -67), Pair(-18, 12), Pair(-78, 7), Pair(5, 29), Pair(-30, 3), Pair(73, 9), Pair(36, -3), Pair(-111, 23),
        Pair(-83, 30), Pair(-42, 31), Pair(8, 14), Pair(9, -10), Pair(-47, 7), Pair(60, -6), Pair(-46, 57), Pair(-28, 51),
        Pair(-82, 13), Pair(-78, 3), Pair(-173, 8), Pair(-71, -24), Pair(-28, -20), Pair(-32, -32), Pair(-79, 0), Pair(-134, 18),
        Pair(-96, 4), Pair(-94, 6), Pair(-62, -12), Pair(-33, -20), Pair(-35, -27), Pair(18, -38), Pair(-57, -14), Pair(-25, -20),
        Pair(-120, -4), Pair(-62, -13), Pair(-66, -21), Pair(-29, -8), Pair(-12, -12), Pair(-34, -9), Pair(-79, -5), Pair(15, -34),
        Pair(-116, 30), Pair(0, -2), Pair(-43, 5), Pair(86, -17), Pair(67, 12), Pair(82, -19), Pair(56, -5), Pair(-35, -17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-80, -153), Pair(-34, -16), Pair(-103, -157), Pair(0, -58), Pair(11, -100), Pair(-31, -72), Pair(-52, -117), Pair(-26, -104),
        Pair(24, -112), Pair(12, -33), Pair(-29, -87), Pair(72, -23), Pair(22, -67), Pair(28, -104), Pair(-5, -54), Pair(-90, -70),
        Pair(30, -46), Pair(-16, -32), Pair(65, -27), Pair(14, -31), Pair(65, -42), Pair(32, -49), Pair(-25, -77), Pair(10, -69),
        Pair(-28, -50), Pair(-12, -43), Pair(68, -51), Pair(128, -50), Pair(118, -66), Pair(63, -6), Pair(9, -31), Pair(-24, -62),
        Pair(-66, -59), Pair(-44, -52), Pair(-8, -21), Pair(23, 2), Pair(68, -26), Pair(125, -34), Pair(59, -21), Pair(61, -72),
        Pair(-5, -39), Pair(-13, 2), Pair(79, -36), Pair(104, 1), Pair(80, -42), Pair(62, -24), Pair(22, -34), Pair(69, -66),
        Pair(13, 7), Pair(-72, -59), Pair(-23, -88), Pair(-49, -52), Pair(-11, -25), Pair(-12, -11), Pair(-3, -13), Pair(30, -26),
        Pair(-8, -118), Pair(-129, -44), Pair(41, -62), Pair(13, -50), Pair(-40, -35), Pair(37, -24), Pair(-22, -115), Pair(-20, -112)
      },
      { // Piece 2
        Pair(0, -6), Pair(-52, 32), Pair(-10, -23), Pair(-71, -31), Pair(-77, 13), Pair(-17, -23), Pair(-93, 37), Pair(-37, -23),
        Pair(-113, 2), Pair(-58, 33), Pair(-107, 10), Pair(-95, 26), Pair(85, -28), Pair(15, -13), Pair(-73, -2), Pair(-41, -34),
        Pair(-54, -18), Pair(-52, 9), Pair(-110, 19), Pair(-166, 43), Pair(-126, 6), Pair(-60, -8), Pair(-31, -3), Pair(-56, -3),
        Pair(-39, -7), Pair(11, -5), Pair(-139, 36), Pair(6, 6), Pair(76, -16), Pair(-54, 18), Pair(-112, -8), Pair(-79, -56),
        Pair(-85, -24), Pair(-72, 2), Pair(-28, 13), Pair(-59, -8), Pair(38, -3), Pair(14, -6), Pair(-24, -15), Pair(2, -39),
        Pair(1, -68), Pair(104, -48), Pair(-28, -54), Pair(-54, -8), Pair(63, -66), Pair(63, -16), Pair(48, -59), Pair(104, -47),
        Pair(17, -30), Pair(-15, -46), Pair(-5, -20), Pair(-116, -35), Pair(0, -16), Pair(3, -25), Pair(135, -57), Pair(-45, -2),
        Pair(-64, -128), Pair(28, -7), Pair(-12, -24), Pair(37, 20), Pair(-58, -8), Pair(39, -30), Pair(17, 6), Pair(-21, -26)
      },
      { // Piece 3
        Pair(-7, -37), Pair(9, -38), Pair(-54, -6), Pair(5, -25), Pair(-96, -20), Pair(38, -23), Pair(-27, 18), Pair(-12, -11),
        Pair(-58, -42), Pair(-68, -21), Pair(-54, -17), Pair(-87, 1), Pair(20, -48), Pair(48, -54), Pair(51, -51), Pair(-110, -7),
        Pair(-115, -36), Pair(78, -58), Pair(-56, -16), Pair(-54, -26), Pair(-30, -52), Pair(83, -48), Pair(33, -49), Pair(-43, -24),
        Pair(12, -49), Pair(0, -40), Pair(-105, -16), Pair(-50, -44), Pair(-7, -49), Pair(76, -59), Pair(14, -27), Pair(88, -66),
        Pair(66, -82), Pair(6, -51), Pair(93, -51), Pair(-45, -60), Pair(0, -68), Pair(-11, -15), Pair(-23, -32), Pair(-53, -20),
        Pair(-71, -24), Pair(84, -37), Pair(-90, -1), Pair(21, -54), Pair(36, -51), Pair(15, -24), Pair(68, -63), Pair(-6, -28),
        Pair(-35, -17), Pair(52, -87), Pair(-26, -42), Pair(-17, -44), Pair(-12, -87), Pair(14, -46), Pair(68, -73), Pair(13, -99),
        Pair(-102, -32), Pair(63, -73), Pair(10, -64), Pair(59, -78), Pair(98, -76), Pair(41, -61), Pair(53, -60), Pair(53, -109)
      },
      { // Piece 4
        Pair(101, -113), Pair(-32, -97), Pair(-52, -91), Pair(82, -60), Pair(80, -38), Pair(-56, -77), Pair(-73, -65), Pair(-71, 16),
        Pair(29, -117), Pair(13, -143), Pair(15, -114), Pair(-1, -38), Pair(3, -107), Pair(18, -52), Pair(36, -97), Pair(8, -72),
        Pair(-69, -95), Pair(79, -30), Pair(16, -18), Pair(15, -78), Pair(-21, -74), Pair(24, -100), Pair(56, -141), Pair(107, -72),
        Pair(16, -96), Pair(-26, -52), Pair(24, -41), Pair(-43, -35), Pair(51, -66), Pair(72, -101), Pair(-63, -81), Pair(87, -87),
        Pair(19, -113), Pair(20, -33), Pair(-25, -47), Pair(-60, -7), Pair(-30, -79), Pair(40, -56), Pair(61, -84), Pair(26, -91),
        Pair(17, 22), Pair(-44, -83), Pair(17, -25), Pair(-24, -144), Pair(1, -40), Pair(95, -23), Pair(30, -106), Pair(52, -70),
        Pair(36, -97), Pair(1, 18), Pair(-30, -37), Pair(55, -103), Pair(8, -95), Pair(-32, -108), Pair(26, -107), Pair(-1, -37),
        Pair(-53, -81), Pair(-7, -77), Pair(-21, -89), Pair(42, -90), Pair(5, -92), Pair(30, -101), Pair(5, -27), Pair(-29, -114)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-108, 23), Pair(50, 24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(14, 24), Pair(-44, -10)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 90), Pair(6, 18), Pair(34, 72), Pair(34, 53), Pair(47, 108), Pair(7, 50), Pair(-23, 4), Pair(-12, -48),
        Pair(-34, 82), Pair(-52, 12), Pair(55, 2), Pair(-30, 27), Pair(-41, 45), Pair(35, -25), Pair(-51, 48), Pair(28, 61),
        Pair(-22, 17), Pair(-27, 4), Pair(3, 47), Pair(-49, 9), Pair(-77, -22), Pair(-55, -43), Pair(-6, -7), Pair(40, -29),
        Pair(-28, -41), Pair(-64, 1), Pair(29, -4), Pair(-42, -21), Pair(-92, -49), Pair(13, -27), Pair(-82, 23), Pair(-24, -41),
        Pair(-48, -14), Pair(-91, -20), Pair(4, 28), Pair(15, 61), Pair(-83, -7), Pair(-29, -8), Pair(-113, 12), Pair(70, -47),
        Pair(55, -41), Pair(11, -28), Pair(-41, 23), Pair(10, -57), Pair(28, 34), Pair(64, -11), Pair(24, -13), Pair(59, -66),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-1, -41), Pair(-23, -58), Pair(-21, 5), Pair(25, 21), Pair(-4, -72), Pair(3, -7), Pair(-6, -11), Pair(-5, -49),
        Pair(26, 97), Pair(13, 90), Pair(7, -21), Pair(-28, 76), Pair(14, 32), Pair(-11, -36), Pair(-62, -114), Pair(-46, -139),
        Pair(-5, 34), Pair(0, -24), Pair(-33, -84), Pair(-84, -110), Pair(-50, 0), Pair(-11, 13), Pair(-10, 122), Pair(-44, -42),
        Pair(7, 20), Pair(22, 5), Pair(39, -25), Pair(-15, -73), Pair(-15, -82), Pair(2, -76), Pair(20, 43), Pair(12, -55),
        Pair(23, -1), Pair(21, 61), Pair(-27, -26), Pair(38, -15), Pair(0, -98), Pair(-36, -51), Pair(39, 50), Pair(-4, 13),
        Pair(7, -45), Pair(21, 36), Pair(-4, -33), Pair(24, 21), Pair(34, -26), Pair(32, 30), Pair(-32, -116), Pair(25, 9),
        Pair(8, 38), Pair(14, 76), Pair(-13, -50), Pair(26, -79), Pair(7, -41), Pair(27, -33), Pair(-25, -59), Pair(-24, -48),
        Pair(8, 7), Pair(13, -10), Pair(-5, 18), Pair(15, 72), Pair(-12, -14), Pair(-11, -3), Pair(8, -11), Pair(5, 6)
      },
      { // Piece 2
        Pair(-32, -25), Pair(-42, -60), Pair(-9, -23), Pair(-13, 9), Pair(-8, -14), Pair(-5, -84), Pair(-4, 31), Pair(-10, -19),
        Pair(-17, -61), Pair(-9, 19), Pair(22, -4), Pair(-28, -93), Pair(46, 40), Pair(38, 48), Pair(20, 54), Pair(-11, -33),
        Pair(-12, -47), Pair(-7, 10), Pair(3, 9), Pair(-23, -60), Pair(31, 99), Pair(3, -2), Pair(13, 64), Pair(16, 69),
        Pair(16, -16), Pair(-25, 14), Pair(32, -20), Pair(75, 98), Pair(-2, 32), Pair(-2, 50), Pair(72, 13), Pair(-14, 15),
        Pair(-36, -45), Pair(15, -9), Pair(23, 36), Pair(19, 135), Pair(28, 19), Pair(40, 108), Pair(-24, -6), Pair(-32, -105),
        Pair(15, 42), Pair(35, -55), Pair(14, 12), Pair(-13, -39), Pair(-13, -75), Pair(56, 32), Pair(7, 15), Pair(28, 97),
        Pair(-6, -56), Pair(16, 34), Pair(36, -15), Pair(-13, -16), Pair(-56, -105), Pair(-38, -5), Pair(16, 11), Pair(28, 18),
        Pair(-6, -60), Pair(26, -2), Pair(-54, -113), Pair(-52, -63), Pair(-6, -39), Pair(26, -52), Pair(-32, -59), Pair(-9, -51)
      },
      { // Piece 3
        Pair(-23, -10), Pair(-7, 13), Pair(-8, 10), Pair(-21, 13), Pair(3, -7), Pair(-3, -11), Pair(-17, 19), Pair(-19, 18),
        Pair(-40, 6), Pair(-14, -47), Pair(24, 18), Pair(-79, -32), Pair(-2, -20), Pair(-22, -19), Pair(-68, -4), Pair(-63, -27),
        Pair(22, 17), Pair(18, 22), Pair(60, -5), Pair(-30, -19), Pair(-29, -17), Pair(-40, -33), Pair(-19, 15), Pair(-32, -7),
        Pair(52, 6), Pair(2, 31), Pair(58, -47), Pair(41, -41), Pair(25, -26), Pair(17, 10), Pair(-47, -7), Pair(6, -50),
        Pair(-2, 70), Pair(13, 2), Pair(15, 14), Pair(47, 59), Pair(-15, -2), Pair(-38, -13), Pair(7, 4), Pair(5, 30),
        Pair(17, -31), Pair(58, 22), Pair(32, 10), Pair(1, -37), Pair(57, -9), Pair(60, 28), Pair(-15, 12), Pair(-19, -65),
        Pair(-20, -49), Pair(34, -7), Pair(69, 15), Pair(18, 13), Pair(4, -42), Pair(5, -4), Pair(-47, -23), Pair(-4, -42),
        Pair(103, -37), Pair(15, -66), Pair(20, -42), Pair(10, -18), Pair(-17, 4), Pair(98, 6), Pair(14, -106), Pair(-2, -26)
      },
      { // Piece 4
        Pair(-84, -70), Pair(12, -31), Pair(10, 19), Pair(-57, -80), Pair(-57, -59), Pair(-34, -57), Pair(42, 36), Pair(-17, -24),
        Pair(15, -56), Pair(16, -80), Pair(-26, -28), Pair(-8, -45), Pair(-17, -46), Pair(-49, -60), Pair(13, 42), Pair(-61, -76),
        Pair(-17, -54), Pair(-14, -53), Pair(29, 19), Pair(17, 21), Pair(1, -52), Pair(-26, -29), Pair(-82, -77), Pair(-41, -101),
        Pair(34, -27), Pair(4, -74), Pair(66, 14), Pair(14, -50), Pair(-6, -51), Pair(33, 10), Pair(-5, -19), Pair(-7, -34),
        Pair(-12, -66), Pair(46, 19), Pair(-1, -47), Pair(-27, -33), Pair(5, -75), Pair(1, -8), Pair(50, 57), Pair(-38, -38),
        Pair(-21, -58), Pair(2, -99), Pair(56, 30), Pair(24, -11), Pair(29, 54), Pair(-21, -50), Pair(50, 32), Pair(9, -21),
        Pair(7, -21), Pair(-54, -99), Pair(31, 55), Pair(-15, -39), Pair(-18, -73), Pair(-51, -51), Pair(-10, -59), Pair(-1, 21),
        Pair(-12, -53), Pair(17, 8), Pair(23, 1), Pair(10, -37), Pair(34, -39), Pair(-42, -72), Pair(3, -26), Pair(-32, -69)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-59, 33), Pair(-2, 36), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-43, 45), Pair(-58, -3)
      }
    }}
  }},
  {{ // Bucket 1
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-98, 84), Pair(-98, 89), Pair(-105, 60), Pair(-56, 12), Pair(-27, -18), Pair(-48, -61), Pair(-95, -124), Pair(-181, -71),
        Pair(6, 54), Pair(-8, 71), Pair(19, 30), Pair(14, -12), Pair(40, -25), Pair(76, -25), Pair(6, 33), Pair(-18, 30),
        Pair(1, 28), Pair(10, 17), Pair(4, -1), Pair(15, -34), Pair(34, -36), Pair(29, -32), Pair(6, 4), Pair(-16, 5),
        Pair(3, 7), Pair(-2, 14), Pair(10, -17), Pair(22, -29), Pair(25, -34), Pair(24, -29), Pair(15, -13), Pair(-10, -9),
        Pair(2, -4), Pair(-2, 11), Pair(1, -15), Pair(-10, -11), Pair(-5, -8), Pair(-4, -16), Pair(11, -17), Pair(-10, -15),
        Pair(7, 3), Pair(15, 9), Pair(2, 8), Pair(-18, 10), Pair(-18, 9), Pair(7, -9), Pair(24, -11), Pair(4, -17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-205, 6), Pair(-270, 85), Pair(-143, 88), Pair(-88, 37), Pair(41, -33), Pair(-100, -38), Pair(-26, 46), Pair(-82, -111),
        Pair(-84, -2), Pair(-44, 38), Pair(-20, 15), Pair(-22, 33), Pair(-15, 16), Pair(46, -10), Pair(-63, 40), Pair(9, -3),
        Pair(-84, 87), Pair(-13, 38), Pair(-25, 59), Pair(6, 32), Pair(12, 16), Pair(10, 48), Pair(-29, 39), Pair(3, -8),
        Pair(-16, 45), Pair(6, 38), Pair(16, 47), Pair(27, 49), Pair(17, 47), Pair(27, 53), Pair(1, 46), Pair(-2, 52),
        Pair(-18, 26), Pair(-16, 44), Pair(10, 50), Pair(11, 52), Pair(20, 48), Pair(27, 36), Pair(27, 26), Pair(-10, 15),
        Pair(-41, 9), Pair(-13, 31), Pair(5, 30), Pair(10, 46), Pair(14, 42), Pair(2, 25), Pair(7, 17), Pair(-21, 18),
        Pair(-49, 16), Pair(-28, 14), Pair(-18, 19), Pair(-10, 23), Pair(-2, 21), Pair(-5, 15), Pair(-31, 11), Pair(-31, -2),
        Pair(-95, 67), Pair(-35, 3), Pair(-33, 18), Pair(-34, 45), Pair(-16, 29), Pair(-33, 20), Pair(-42, 3), Pair(-52, -30)
      },
      { // Piece 2
        Pair(-56, 32), Pair(-79, 81), Pair(-39, 26), Pair(-164, 68), Pair(-214, 70), Pair(-78, -25), Pair(-120, 17), Pair(-142, 62),
        Pair(-82, 50), Pair(-39, 31), Pair(-41, 31), Pair(-74, 37), Pair(-72, 51), Pair(-28, 28), Pair(-91, 85), Pair(-24, 37),
        Pair(-25, 17), Pair(-20, 27), Pair(-11, 31), Pair(-7, 10), Pair(-19, 19), Pair(-10, 39), Pair(23, 16), Pair(5, 28),
        Pair(-15, 39), Pair(-9, 33), Pair(-24, 43), Pair(-12, 32), Pair(-3, 21), Pair(-10, 29), Pair(-9, 20), Pair(-26, 29),
        Pair(-3, -19), Pair(-35, 38), Pair(-1, 18), Pair(12, 10), Pair(8, 15), Pair(-4, 5), Pair(-16, 21), Pair(-15, -16),
        Pair(-21, 7), Pair(11, 40), Pair(1, 33), Pair(1, 30), Pair(5, 35), Pair(4, 26), Pair(-1, 14), Pair(-18, 0),
        Pair(19, -12), Pair(15, 0), Pair(21, 4), Pair(-7, 30), Pair(4, 21), Pair(4, 14), Pair(13, 12), Pair(0, -3),
        Pair(-6, 7), Pair(-3, 25), Pair(-18, 20), Pair(-4, 13), Pair(-12, 23), Pair(-21, 21), Pair(-12, 29), Pair(4, 0)
      },
      { // Piece 3
        Pair(1, 113), Pair(-61, 103), Pair(-14, 107), Pair(-21, 74), Pair(-96, 126), Pair(79, 118), Pair(71, 107), Pair(-28, 89),
        Pair(5, 39), Pair(-48, 86), Pair(-22, 68), Pair(0, 64), Pair(8, 54), Pair(43, 47), Pair(12, 50), Pair(-38, 80),
        Pair(-1, 24), Pair(27, 47), Pair(-26, 56), Pair(22, 35), Pair(28, 32), Pair(-13, 32), Pair(42, 33), Pair(8, 15),
        Pair(7, 20), Pair(17, 35), Pair(0, 55), Pair(2, 52), Pair(21, 41), Pair(28, 32), Pair(31, 11), Pair(2, 22),
        Pair(-5, 16), Pair(-17, 51), Pair(-31, 37), Pair(-6, 45), Pair(-7, 31), Pair(-12, 7), Pair(2, -1), Pair(-18, 15),
        Pair(-19, 30), Pair(-11, 12), Pair(-30, 39), Pair(-19, 27), Pair(-13, 29), Pair(-5, -6), Pair(3, -4), Pair(-3, -26),
        Pair(-25, 7), Pair(-27, 27), Pair(-22, 24), Pair(-22, 31), Pair(-2, 13), Pair(-14, 17), Pair(-4, -25), Pair(-25, -21),
        Pair(-7, 13), Pair(-17, 15), Pair(-17, 33), Pair(-3, 21), Pair(2, 9), Pair(-24, 5), Pair(-7, -9), Pair(4, -27)
      },
      { // Piece 4
        Pair(-208, 177), Pair(-129, 193), Pair(-114, 115), Pair(-3, 78), Pair(5, 79), Pair(83, 89), Pair(-18, 18), Pair(84, 56),
        Pair(-60, 4), Pair(-76, 48), Pair(-55, 52), Pair(-117, 104), Pair(-114, 142), Pair(-48, 120), Pair(-53, 62), Pair(42, 14),
        Pair(-33, -8), Pair(-44, 21), Pair(-41, 39), Pair(-15, 28), Pair(-39, 54), Pair(-31, 111), Pair(-7, 81), Pair(-3, 44),
        Pair(-34, -16), Pair(-30, 46), Pair(-24, 16), Pair(-35, 71), Pair(-56, 119), Pair(-16, 65), Pair(-12, 82), Pair(0, 14),
        Pair(-31, 1), Pair(-33, 38), Pair(-35, 39), Pair(-38, 123), Pair(-35, 85), Pair(-20, 33), Pair(-5, 12), Pair(-13, 4),
        Pair(-43, 19), Pair(-13, -5), Pair(-22, 49), Pair(-28, 58), Pair(-30, 65), Pair(-19, 48), Pair(-11, 16), Pair(-13, 15),
        Pair(-36, -18), Pair(-1, -88), Pair(-1, -51), Pair(-3, -7), Pair(-13, 4), Pair(-25, 23), Pair(16, -76), Pair(24, -91),
        Pair(3, -124), Pair(-17, -66), Pair(-5, -68), Pair(-11, -39), Pair(-27, -17), Pair(-34, -21), Pair(-36, 31), Pair(8, -31)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(5, 2), Pair(-59, 22), Pair(-5, -10), Pair(-41, 14), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-73, 102), Pair(-121, 62), Pair(-83, -43), Pair(-72, -37), Pair(-16, -70), Pair(-70, -34), Pair(-59, -43), Pair(-46, 26),
        Pair(19, 46), Pair(-15, 59), Pair(43, -2), Pair(23, -33), Pair(40, -43), Pair(44, -4), Pair(24, 45), Pair(21, 34),
        Pair(13, 23), Pair(11, 4), Pair(16, -8), Pair(22, -27), Pair(40, -37), Pair(28, -27), Pair(21, -3), Pair(7, 9),
        Pair(-7, 12), Pair(7, 13), Pair(15, -27), Pair(36, -29), Pair(39, -29), Pair(27, -28), Pair(11, -2), Pair(-11, -4),
        Pair(-7, -8), Pair(-6, 13), Pair(4, -11), Pair(-1, -6), Pair(7, -11), Pair(-1, -16), Pair(13, -7), Pair(-10, -12),
        Pair(0, 3), Pair(17, 10), Pair(8, 6), Pair(-9, 13), Pair(-3, 4), Pair(15, -10), Pair(25, -10), Pair(8, -14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-184, -52), Pair(-50, 47), Pair(-59, 7), Pair(-3, -46), Pair(-8, 7), Pair(-63, -42), Pair(-144, 54), Pair(-121, -88),
        Pair(-70, 83), Pair(-34, 26), Pair(56, 12), Pair(43, -33), Pair(60, -5), Pair(-3, 28), Pair(-42, 17), Pair(-6, -26),
        Pair(-45, 62), Pair(9, 33), Pair(-20, 74), Pair(13, 55), Pair(37, 65), Pair(-8, 91), Pair(-15, 52), Pair(-23, -18),
        Pair(24, 55), Pair(18, 76), Pair(29, 63), Pair(27, 85), Pair(31, 61), Pair(40, 66), Pair(30, 55), Pair(23, 26),
        Pair(6, 46), Pair(20, 38), Pair(28, 66), Pair(38, 59), Pair(34, 58), Pair(45, 49), Pair(37, 44), Pair(-1, 54),
        Pair(-13, 24), Pair(14, 33), Pair(26, 38), Pair(31, 58), Pair(42, 42), Pair(27, 26), Pair(23, 30), Pair(-6, 25),
        Pair(-16, 45), Pair(22, 45), Pair(16, 38), Pair(15, 41), Pair(19, 22), Pair(14, 42), Pair(2, 14), Pair(-20, -22),
        Pair(-73, 19), Pair(-10, 35), Pair(-23, 42), Pair(8, 28), Pair(-12, 59), Pair(4, -8), Pair(-14, 28), Pair(-39, -19)
      },
      { // Piece 2
        Pair(-11, 31), Pair(-88, 90), Pair(-71, 7), Pair(-182, 138), Pair(-42, -27), Pair(-137, 49), Pair(-26, 95), Pair(-38, 26),
        Pair(-21, -9), Pair(13, 19), Pair(-22, 12), Pair(-55, 41), Pair(5, -17), Pair(22, -2), Pair(-32, 36), Pair(-53, 34),
        Pair(17, 28), Pair(19, 41), Pair(28, 47), Pair(42, 10), Pair(53, 26), Pair(-6, 53), Pair(12, 54), Pair(23, 7),
        Pair(7, 26), Pair(6, 44), Pair(17, 30), Pair(5, 47), Pair(23, 25), Pair(23, 37), Pair(21, 19), Pair(13, 46),
        Pair(-2, 3), Pair(10, 23), Pair(25, 2), Pair(31, 16), Pair(36, 29), Pair(22, 15), Pair(26, 28), Pair(6, 18),
        Pair(16, 13), Pair(39, 8), Pair(28, 39), Pair(29, 27), Pair(34, 32), Pair(37, 27), Pair(31, 8), Pair(26, 7),
        Pair(24, 8), Pair(44, 13), Pair(40, 0), Pair(27, 34), Pair(30, 19), Pair(36, 21), Pair(52, 8), Pair(32, 2),
        Pair(43, 23), Pair(37, 0), Pair(15, 25), Pair(16, 37), Pair(25, 16), Pair(6, 29), Pair(13, -31), Pair(16, 25)
      },
      { // Piece 3
        Pair(120, 73), Pair(74, 74), Pair(-19, 86), Pair(143, 89), Pair(35, 57), Pair(-66, 67), Pair(81, 26), Pair(17, 40),
        Pair(12, 69), Pair(3, 86), Pair(7, 79), Pair(109, 47), Pair(67, 53), Pair(-34, 96), Pair(-18, 93), Pair(-12, 94),
        Pair(27, 47), Pair(101, 25), Pair(-18, 74), Pair(56, 22), Pair(30, 22), Pair(20, 46), Pair(66, 35), Pair(0, 72),
        Pair(38, 27), Pair(64, 13), Pair(57, 36), Pair(32, 37), Pair(46, 28), Pair(-8, 48), Pair(29, 44), Pair(43, 25),
        Pair(6, 59), Pair(3, 25), Pair(10, 41), Pair(12, 43), Pair(24, 48), Pair(0, 25), Pair(-14, 50), Pair(15, 39),
        Pair(13, 20), Pair(40, 12), Pair(6, 47), Pair(14, 32), Pair(37, 4), Pair(11, 42), Pair(27, 0), Pair(17, 20),
        Pair(5, 14), Pair(32, 20), Pair(16, 39), Pair(17, 7), Pair(42, 9), Pair(25, 29), Pair(22, -6), Pair(-22, 46),
        Pair(25, 11), Pair(27, 15), Pair(32, 7), Pair(42, -3), Pair(47, 0), Pair(2, 22), Pair(6, 20), Pair(25, -7)
      },
      { // Piece 4
        Pair(5, 92), Pair(43, 94), Pair(161, 24), Pair(58, 76), Pair(-57, 3), Pair(78, 60), Pair(40, 77), Pair(-56, 146),
        Pair(-4, 105), Pair(-21, 84), Pair(-37, 152), Pair(17, 81), Pair(-84, -27), Pair(-9, 55), Pair(-27, 118), Pair(3, 103),
        Pair(4, 76), Pair(25, 59), Pair(39, 93), Pair(-5, 167), Pair(-19, 203), Pair(-30, 109), Pair(49, 40), Pair(0, 88),
        Pair(9, 72), Pair(15, 70), Pair(2, 115), Pair(-19, 115), Pair(28, 53), Pair(8, 129), Pair(28, 46), Pair(14, 111),
        Pair(16, 34), Pair(3, 77), Pair(22, 65), Pair(6, 123), Pair(20, 86), Pair(12, 82), Pair(20, 81), Pair(-4, 91),
        Pair(9, 38), Pair(34, 28), Pair(20, 90), Pair(13, 84), Pair(26, 38), Pair(23, 77), Pair(21, 97), Pair(4, 98),
        Pair(5, -52), Pair(29, -14), Pair(43, -26), Pair(25, 35), Pair(35, 32), Pair(39, -2), Pair(35, -8), Pair(41, -43),
        Pair(34, -7), Pair(17, 7), Pair(32, -25), Pair(34, -30), Pair(-3, 72), Pair(2, -58), Pair(72, -174), Pair(40, -55)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(24, -7), Pair(-28, 10), Pair(9, -6), Pair(-43, 12), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-42, 12), Pair(-31, -1), Pair(-44, -4), Pair(17, -51), Pair(-89, -43), Pair(-35, -60), Pair(-120, -1), Pair(-88, 7),
        Pair(-27, 47), Pair(21, 32), Pair(15, 4), Pair(28, -30), Pair(83, -44), Pair(41, -18), Pair(3, 44), Pair(-11, 11),
        Pair(-26, 27), Pair(2, 6), Pair(8, -11), Pair(4, -21), Pair(23, -32), Pair(17, -26), Pair(-3, 5), Pair(-12, 0),
        Pair(-10, 3), Pair(-14, 17), Pair(5, -19), Pair(20, -23), Pair(19, -27), Pair(15, -26), Pair(11, -13), Pair(-8, -12),
        Pair(-15, -1), Pair(-12, 4), Pair(-9, -10), Pair(-13, -9), Pair(-2, -13), Pair(-10, -18), Pair(4, -10), Pair(-16, -16),
        Pair(-4, 4), Pair(4, 8), Pair(7, -1), Pair(-13, 5), Pair(-2, 5), Pair(4, -10), Pair(13, -5), Pair(-6, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-141, -117), Pair(-132, 28), Pair(-78, -27), Pair(5, 13), Pair(64, -3), Pair(20, -5), Pair(31, -66), Pair(-107, -106),
        Pair(-68, -14), Pair(-45, 24), Pair(5, 3), Pair(-35, 53), Pair(3, 0), Pair(8, -7), Pair(-15, -31), Pair(22, -31),
        Pair(-37, 15), Pair(-27, 35), Pair(3, 40), Pair(48, 7), Pair(66, 20), Pair(47, 16), Pair(57, -26), Pair(-35, 12),
        Pair(-2, 42), Pair(16, 28), Pair(38, 32), Pair(40, 30), Pair(45, 34), Pair(39, 52), Pair(19, 27), Pair(39, -6),
        Pair(-13, 31), Pair(32, 31), Pair(36, 31), Pair(43, 33), Pair(41, 40), Pair(37, 33), Pair(35, 32), Pair(2, 14),
        Pair(-52, 35), Pair(-27, 37), Pair(8, 20), Pair(20, 38), Pair(15, 45), Pair(16, 19), Pair(22, 14), Pair(-18, 13),
        Pair(-47, 30), Pair(-49, 38), Pair(-11, 27), Pair(-10, 37), Pair(9, 27), Pair(3, 22), Pair(-9, 21), Pair(-31, 15),
        Pair(-86, -21), Pair(-39, 28), Pair(-51, 21), Pair(3, 11), Pair(-19, 37), Pair(-36, 17), Pair(-27, 12), Pair(-14, -3)
      },
      { // Piece 2
        Pair(-92, 32), Pair(-118, 34), Pair(-133, 49), Pair(-164, 33), Pair(-57, 7), Pair(-229, 65), Pair(-63, 77), Pair(-44, 51),
        Pair(-106, 35), Pair(-10, 7), Pair(-68, 37), Pair(15, -10), Pair(9, 15), Pair(-30, 21), Pair(-25, 9), Pair(10, -22),
        Pair(-19, 18), Pair(-7, 24), Pair(-10, 22), Pair(-9, 22), Pair(12, -15), Pair(-19, 10), Pair(7, 2), Pair(-12, 13),
        Pair(-2, 8), Pair(3, 4), Pair(-5, 26), Pair(-4, 18), Pair(27, 19), Pair(45, 11), Pair(3, 17), Pair(-1, 13),
        Pair(-29, 20), Pair(-11, 12), Pair(2, 8), Pair(3, 18), Pair(25, -4), Pair(14, 1), Pair(-13, 13), Pair(-6, -8),
        Pair(-7, 16), Pair(29, -4), Pair(4, 20), Pair(24, 12), Pair(16, 24), Pair(16, 13), Pair(21, -1), Pair(5, -7),
        Pair(-17, 9), Pair(29, -12), Pair(43, -7), Pair(15, 16), Pair(4, 21), Pair(10, 4), Pair(4, 1), Pair(4, -30),
        Pair(2, -11), Pair(23, -16), Pair(-10, 20), Pair(-6, 13), Pair(16, 5), Pair(-22, 18), Pair(-52, 18), Pair(-10, -16)
      },
      { // Piece 3
        Pair(-28, 44), Pair(-49, 58), Pair(-70, 62), Pair(4, 40), Pair(-52, 34), Pair(-14, 58), Pair(-78, 82), Pair(-43, 67),
        Pair(-24, 42), Pair(-36, 58), Pair(-9, 38), Pair(12, 40), Pair(14, 32), Pair(-20, 31), Pair(-33, 20), Pair(-29, 40),
        Pair(-5, 22), Pair(-16, 34), Pair(-6, 39), Pair(8, 22), Pair(73, -6), Pair(32, 19), Pair(18, 22), Pair(3, 31),
        Pair(-32, 35), Pair(22, 3), Pair(-46, 52), Pair(-4, 29), Pair(-29, 29), Pair(14, 10), Pair(2, 18), Pair(-28, 33),
        Pair(-14, 7), Pair(-48, 32), Pair(-24, 28), Pair(-41, 35), Pair(-17, 24), Pair(-44, 33), Pair(-75, 39), Pair(-29, 5),
        Pair(-7, -1), Pair(-42, 19), Pair(-47, 26), Pair(-19, 15), Pair(-35, 15), Pair(-48, 24), Pair(-14, 8), Pair(-19, -18),
        Pair(-54, 18), Pair(-31, 18), Pair(-15, 14), Pair(-9, -12), Pair(-24, 2), Pair(-23, -5), Pair(-38, -1), Pair(-60, -8),
        Pair(-23, 2), Pair(-33, 0), Pair(-34, 19), Pair(-12, 2), Pair(-10, 4), Pair(-12, 1), Pair(-28, -1), Pair(-20, -8)
      },
      { // Piece 4
        Pair(-44, 0), Pair(-52, 34), Pair(-94, 85), Pair(-7, 28), Pair(-47, 83), Pair(-93, 80), Pair(-2, -28), Pair(-48, 14),
        Pair(6, -2), Pair(-27, 64), Pair(-70, 118), Pair(-111, 144), Pair(-54, 89), Pair(-27, 34), Pair(-35, 49), Pair(3, 64),
        Pair(19, -6), Pair(-44, 47), Pair(-28, 67), Pair(7, 21), Pair(-24, 81), Pair(-28, 87), Pair(31, -5), Pair(21, 44),
        Pair(-12, 8), Pair(0, 37), Pair(-3, 66), Pair(-16, 46), Pair(-59, 107), Pair(11, 74), Pair(21, 44), Pair(7, 47),
        Pair(11, 0), Pair(11, 37), Pair(25, 19), Pair(16, 66), Pair(-8, 96), Pair(18, 4), Pair(21, 36), Pair(10, 16),
        Pair(-5, 15), Pair(1, 30), Pair(9, 45), Pair(17, 47), Pair(8, 50), Pair(12, 41), Pair(28, 25), Pair(-32, 95),
        Pair(-52, 9), Pair(3, 44), Pair(29, -12), Pair(35, -12), Pair(14, 20), Pair(20, -26), Pair(32, -49), Pair(6, -49),
        Pair(-25, -13), Pair(19, -59), Pair(33, -76), Pair(29, -60), Pair(-26, 45), Pair(27, -86), Pair(-45, 5), Pair(22, -52)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(17, -4), Pair(-33, 9), Pair(-8, 3), Pair(-24, 9), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-67, 0), Pair(68, -33), Pair(-15, -20), Pair(30, -52), Pair(12, -87), Pair(-53, 19), Pair(3, 60), Pair(-103, -11),
        Pair(-41, 52), Pair(35, 12), Pair(65, -6), Pair(17, -4), Pair(-55, -11), Pair(-27, -6), Pair(10, 9), Pair(22, 12),
        Pair(-35, 22), Pair(9, 4), Pair(-8, -7), Pair(-21, -16), Pair(38, -34), Pair(17, -35), Pair(-12, 5), Pair(-22, 7),
        Pair(-57, 10), Pair(-1, 11), Pair(-14, -11), Pair(-9, -6), Pair(-12, -12), Pair(0, -21), Pair(19, 1), Pair(3, -17),
        Pair(-42, 0), Pair(-28, 9), Pair(-11, -9), Pair(-24, -10), Pair(-27, -5), Pair(-28, -10), Pair(-8, -6), Pair(-15, -14),
        Pair(-23, 10), Pair(-5, 8), Pair(-5, 2), Pair(3, -16), Pair(-38, 16), Pair(-13, -2), Pair(3, 1), Pair(-13, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(9, -128), Pair(-58, -65), Pair(-83, 5), Pair(-52, 6), Pair(-74, 27), Pair(-60, -39), Pair(4, -46), Pair(25, -133),
        Pair(-78, 7), Pair(-39, -9), Pair(55, -43), Pair(-20, 17), Pair(30, 17), Pair(129, -76), Pair(-88, 26), Pair(-79, 6),
        Pair(-5, -22), Pair(32, 2), Pair(26, 27), Pair(52, -3), Pair(80, -7), Pair(106, -20), Pair(-82, 26), Pair(79, -20),
        Pair(47, 12), Pair(29, 12), Pair(42, 13), Pair(92, -8), Pair(61, 11), Pair(114, -12), Pair(105, -25), Pair(72, -10),
        Pair(6, -5), Pair(47, 3), Pair(34, 23), Pair(-18, 47), Pair(70, 17), Pair(60, 10), Pair(66, 33), Pair(-39, 24),
        Pair(40, -23), Pair(38, 9), Pair(19, 15), Pair(67, 20), Pair(18, 36), Pair(6, 30), Pair(24, -6), Pair(-29, -2),
        Pair(-53, 19), Pair(-6, -3), Pair(57, 8), Pair(-1, 18), Pair(2, 22), Pair(18, 7), Pair(82, -20), Pair(-85, 17),
        Pair(-89, -78), Pair(-62, 23), Pair(54, -36), Pair(-29, 42), Pair(-10, 33), Pair(27, 21), Pair(-75, 50), Pair(-104, -54)
      },
      { // Piece 2
        Pair(-69, 30), Pair(3, -17), Pair(-130, 25), Pair(-78, 27), Pair(-59, 21), Pair(-43, -9), Pair(31, -4), Pair(-74, -25),
        Pair(32, -27), Pair(-25, -2), Pair(-58, 23), Pair(74, -23), Pair(27, -25), Pair(-29, -7), Pair(-71, 23), Pair(44, -19),
        Pair(26, -7), Pair(-46, 49), Pair(-13, 18), Pair(38, -2), Pair(6, -19), Pair(-42, 17), Pair(-5, 23), Pair(72, -16),
        Pair(-73, 27), Pair(-8, 1), Pair(-37, 7), Pair(45, -10), Pair(-83, 37), Pair(33, 16), Pair(-34, -1), Pair(9, 19),
        Pair(25, -37), Pair(36, 4), Pair(1, 7), Pair(34, -3), Pair(37, -5), Pair(6, 23), Pair(70, -27), Pair(51, -56),
        Pair(18, -10), Pair(28, -11), Pair(40, 13), Pair(0, 16), Pair(29, 8), Pair(-4, 7), Pair(-21, 25), Pair(25, 4),
        Pair(36, 6), Pair(6, -8), Pair(67, -27), Pair(31, 7), Pair(-12, 16), Pair(22, -8), Pair(3, 0), Pair(14, -31),
        Pair(74, -21), Pair(41, -19), Pair(-42, 20), Pair(-4, 2), Pair(-76, 19), Pair(3, -19), Pair(-25, 48), Pair(123, -54)
      },
      { // Piece 3
        Pair(-53, 44), Pair(37, 11), Pair(-74, 54), Pair(-29, 22), Pair(-2, 39), Pair(-56, 37), Pair(-71, 65), Pair(-11, 47),
        Pair(-23, 8), Pair(-9, 6), Pair(17, 8), Pair(15, 14), Pair(60, -13), Pair(25, -10), Pair(-2, 6), Pair(-3, -8),
        Pair(76, -11), Pair(-19, 26), Pair(-5, 8), Pair(-3, 7), Pair(129, -42), Pair(49, -42), Pair(-87, 52), Pair(-113, 35),
        Pair(-84, 24), Pair(-46, 22), Pair(26, 9), Pair(41, 2), Pair(-26, 22), Pair(67, -4), Pair(29, -6), Pair(-48, 19),
        Pair(-88, 23), Pair(-77, 41), Pair(-62, 39), Pair(-80, 28), Pair(-36, 10), Pair(37, -12), Pair(-29, 24), Pair(-55, 5),
        Pair(-64, 5), Pair(-58, 8), Pair(-81, 13), Pair(-3, -2), Pair(-80, 16), Pair(8, -11), Pair(-54, 14), Pair(-105, 16),
        Pair(-46, -16), Pair(-108, 22), Pair(-39, 16), Pair(-37, -12), Pair(-27, -27), Pair(-35, -4), Pair(-51, -33), Pair(-44, -34),
        Pair(-47, -16), Pair(-47, -3), Pair(-60, 15), Pair(-25, -10), Pair(-40, -10), Pair(-33, -6), Pair(-72, 9), Pair(-61, -11)
      },
      { // Piece 4
        Pair(-106, 53), Pair(2, -10), Pair(55, 42), Pair(-31, -9), Pair(-43, 30), Pair(27, 21), Pair(-116, 79), Pair(-27, 86),
        Pair(133, -95), Pair(-24, -31), Pair(-28, 18), Pair(46, -12), Pair(2, 46), Pair(-18, 66), Pair(33, -14), Pair(62, -4),
        Pair(7, 6), Pair(-64, -21), Pair(73, 1), Pair(10, 28), Pair(-10, 54), Pair(42, 86), Pair(53, 7), Pair(132, -86),
        Pair(78, -36), Pair(-106, 62), Pair(-35, 59), Pair(90, -8), Pair(163, -52), Pair(-10, 61), Pair(15, 78), Pair(-34, 35),
        Pair(-31, 0), Pair(26, -14), Pair(63, -33), Pair(13, -5), Pair(51, 4), Pair(73, -15), Pair(10, 16), Pair(48, -32),
        Pair(-83, 26), Pair(-12, 8), Pair(33, -22), Pair(25, -66), Pair(32, 1), Pair(28, -26), Pair(37, -35), Pair(55, 29),
        Pair(-62, 41), Pair(42, -75), Pair(-3, -2), Pair(38, -50), Pair(47, -43), Pair(24, -56), Pair(-46, 1), Pair(-29, 8),
        Pair(-69, -69), Pair(21, -130), Pair(10, 4), Pair(14, -51), Pair(-28, -81), Pair(23, -50), Pair(-94, -111), Pair(-66, -68)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(30, 1), Pair(-26, 15), Pair(-1, 8), Pair(-12, 13), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, -6), Pair(-74, 44), Pair(30, -46), Pair(77, -33), Pair(-3, 2), Pair(15, 32), Pair(-56, 80), Pair(-29, -19),
        Pair(-89, 38), Pair(-124, 72), Pair(-2, 38), Pair(-9, -2), Pair(-98, -4), Pair(-17, -10), Pair(-14, 39), Pair(80, 0),
        Pair(-70, 7), Pair(15, 4), Pair(-14, -22), Pair(27, -13), Pair(-64, -14), Pair(-8, -14), Pair(25, 5), Pair(23, -7),
        Pair(-35, -4), Pair(-27, 4), Pair(0, -36), Pair(-20, -17), Pair(-31, -9), Pair(-1, -36), Pair(34, -13), Pair(-4, -8),
        Pair(-10, -14), Pair(-82, 18), Pair(11, -11), Pair(-44, 0), Pair(-41, -1), Pair(-57, 1), Pair(26, -11), Pair(-23, -10),
        Pair(-16, -2), Pair(-44, 17), Pair(-3, -4), Pair(-1, -16), Pair(-13, -7), Pair(16, -8), Pair(-10, 2), Pair(4, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-111, -118), Pair(-12, -38), Pair(-72, -44), Pair(-46, -58), Pair(-80, -59), Pair(-51, -11), Pair(-36, -47), Pair(-25, -100),
        Pair(-37, -39), Pair(15, -23), Pair(-21, -53), Pair(-74, -4), Pair(-17, -3), Pair(47, -21), Pair(-8, 9), Pair(9, -50),
        Pair(-20, -36), Pair(37, -28), Pair(115, -9), Pair(-4, 5), Pair(-37, 26), Pair(9, -40), Pair(-28, -10), Pair(-75, 15),
        Pair(100, -24), Pair(-1, 5), Pair(83, -20), Pair(67, -5), Pair(29, 11), Pair(-14, 7), Pair(58, -12), Pair(27, -49),
        Pair(-96, 9), Pair(-4, -7), Pair(58, 5), Pair(71, 10), Pair(34, -21), Pair(73, -24), Pair(74, -34), Pair(17, -34),
        Pair(11, -48), Pair(-16, 20), Pair(-3, 4), Pair(45, 7), Pair(108, -25), Pair(-5, 8), Pair(-58, 6), Pair(-49, -4),
        Pair(-27, 3), Pair(-65, -17), Pair(-83, 13), Pair(10, 5), Pair(6, -1), Pair(3, 3), Pair(-20, -10), Pair(29, 24),
        Pair(-53, -102), Pair(-132, 10), Pair(122, -33), Pair(44, -54), Pair(-29, -1), Pair(-31, -40), Pair(-173, 49), Pair(12, -9)
      },
      { // Piece 2
        Pair(11, -10), Pair(4, -40), Pair(-60, -37), Pair(-64, 30), Pair(-80, 33), Pair(16, -41), Pair(-38, -25), Pair(-21, 42),
        Pair(-35, -26), Pair(-27, -7), Pair(-52, 9), Pair(6, -28), Pair(-7, -7), Pair(-27, -13), Pair(-24, -2), Pair(-70, 11),
        Pair(2, -1), Pair(-8, -7), Pair(-81, 19), Pair(-112, -1), Pair(-100, -1), Pair(-3, -6), Pair(-1, -8), Pair(51, 15),
        Pair(-117, -14), Pair(19, -17), Pair(-33, 11), Pair(44, -14), Pair(17, -22), Pair(10, 3), Pair(-53, 14), Pair(40, -14),
        Pair(67, -3), Pair(53, -35), Pair(-58, -3), Pair(138, -12), Pair(84, -1), Pair(-69, -2), Pair(-44, 7), Pair(-1, -20),
        Pair(-37, -7), Pair(-44, -1), Pair(-40, 6), Pair(54, -14), Pair(91, -11), Pair(0, -4), Pair(-46, 4), Pair(-8, -18),
        Pair(-49, -26), Pair(17, -16), Pair(1, -10), Pair(1, -14), Pair(-18, -7), Pair(-78, -10), Pair(-60, -26), Pair(30, 23),
        Pair(15, -58), Pair(-18, 5), Pair(-85, 7), Pair(-74, 11), Pair(36, -17), Pair(-68, -25), Pair(66, 31), Pair(-17, -19)
      },
      { // Piece 3
        Pair(-13, 9), Pair(-41, 16), Pair(-59, 16), Pair(-18, 15), Pair(-43, 9), Pair(3, 17), Pair(-129, 50), Pair(-8, 5),
        Pair(-109, 8), Pair(3, -25), Pair(-144, 9), Pair(-114, 22), Pair(-84, 16), Pair(5, -27), Pair(49, -27), Pair(-35, -21),
        Pair(-116, 14), Pair(-40, 4), Pair(14, -20), Pair(-98, 14), Pair(-3, -28), Pair(141, -48), Pair(33, -18), Pair(25, -29),
        Pair(-5, -54), Pair(-58, -13), Pair(16, 13), Pair(33, -20), Pair(-44, -64), Pair(-17, -33), Pair(-25, -20), Pair(29, -40),
        Pair(-31, -15), Pair(-95, 2), Pair(-62, 0), Pair(-32, 6), Pair(-79, 5), Pair(-33, -3), Pair(-100, 23), Pair(-42, -5),
        Pair(-36, -39), Pair(-84, -15), Pair(-2, -19), Pair(-38, 2), Pair(-18, -21), Pair(23, -22), Pair(-8, -53), Pair(-75, -11),
        Pair(-121, -16), Pair(-61, -33), Pair(-3, -58), Pair(-1, -72), Pair(-67, -28), Pair(4, -21), Pair(-10, -15), Pair(-114, -60),
        Pair(-26, -44), Pair(-127, -10), Pair(-4, -52), Pair(-17, -32), Pair(2, -45), Pair(49, -86), Pair(-38, -50), Pair(-104, -27)
      },
      { // Piece 4
        Pair(6, -33), Pair(98, -21), Pair(25, 4), Pair(50, -24), Pair(-1, 20), Pair(33, -44), Pair(-51, -9), Pair(4, -38),
        Pair(-39, -7), Pair(-88, 41), Pair(-15, -86), Pair(-13, 62), Pair(43, -19), Pair(-30, 42), Pair(65, -66), Pair(180, -41),
        Pair(30, 0), Pair(-6, -69), Pair(-4, 38), Pair(40, -45), Pair(56, -50), Pair(-3, -65), Pair(84, -76), Pair(150, 25),
        Pair(19, -3), Pair(8, -51), Pair(6, 8), Pair(91, -35), Pair(2, 38), Pair(20, -91), Pair(76, 69), Pair(-36, 80),
        Pair(-22, -12), Pair(115, 26), Pair(28, 28), Pair(2, 73), Pair(4, 53), Pair(90, 5), Pair(-64, -1), Pair(7, 64),
        Pair(-65, -62), Pair(41, -26), Pair(95, 10), Pair(-61, -35), Pair(24, 23), Pair(-11, 28), Pair(46, 13), Pair(-126, 32),
        Pair(28, -48), Pair(0, -3), Pair(-59, -62), Pair(-33, -21), Pair(-12, -59), Pair(86, -101), Pair(90, 2), Pair(-2, -54),
        Pair(40, 36), Pair(-25, -97), Pair(-125, -125), Pair(112, -97), Pair(33, -57), Pair(-81, -46), Pair(-52, -63), Pair(15, 11)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(16, 14), Pair(-6, 19), Pair(-14, 24), Pair(-39, 26), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-51, -17), Pair(32, -11), Pair(-33, -13), Pair(49, -18), Pair(-50, -1), Pair(-86, -2), Pair(-41, 16), Pair(-92, 2),
        Pair(-108, 50), Pair(-38, 45), Pair(-69, 32), Pair(-95, 50), Pair(-81, 69), Pair(-109, 60), Pair(-38, 52), Pair(-129, 33),
        Pair(-45, -11), Pair(-96, 15), Pair(-65, -10), Pair(-181, 13), Pair(-106, 0), Pair(-43, -31), Pair(-75, 3), Pair(-128, 2),
        Pair(-76, -17), Pair(-74, -6), Pair(51, -56), Pair(74, -38), Pair(-61, -8), Pair(48, -51), Pair(-3, -28), Pair(-7, -31),
        Pair(-28, -27), Pair(-55, -2), Pair(-75, -12), Pair(-11, -15), Pair(-7, -18), Pair(37, -27), Pair(10, -16), Pair(-10, -23),
        Pair(-69, 1), Pair(-35, 8), Pair(31, -7), Pair(-96, 14), Pair(-9, 13), Pair(44, -6), Pair(42, -11), Pair(-109, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, -87), Pair(-13, 0), Pair(-43, -61), Pair(19, 16), Pair(-43, -110), Pair(-47, -61), Pair(-12, -51), Pair(-44, -119),
        Pair(-42, -25), Pair(-49, -29), Pair(-80, -25), Pair(-24, -53), Pair(-70, -28), Pair(4, -23), Pair(-44, -68), Pair(-73, -62),
        Pair(-56, -45), Pair(-23, -67), Pair(-23, -16), Pair(55, -24), Pair(53, -64), Pair(43, -60), Pair(-15, -49), Pair(-67, 0),
        Pair(-31, -43), Pair(-29, -57), Pair(67, -64), Pair(12, -54), Pair(77, -34), Pair(53, -58), Pair(64, -43), Pair(-68, -16),
        Pair(-51, -12), Pair(-87, -15), Pair(98, -43), Pair(-38, -14), Pair(41, -16), Pair(78, -8), Pair(-22, -5), Pair(5, -3),
        Pair(-75, -85), Pair(48, -40), Pair(76, -36), Pair(46, -33), Pair(35, -17), Pair(83, -36), Pair(59, -62), Pair(38, -45),
        Pair(2, 2), Pair(-20, -25), Pair(-1, -19), Pair(-17, -19), Pair(45, -27), Pair(31, -22), Pair(-22, -21), Pair(-44, -32),
        Pair(-22, -60), Pair(-104, -62), Pair(202, -47), Pair(0, -15), Pair(55, -57), Pair(-57, -2), Pair(69, -83), Pair(-27, -87)
      },
      { // Piece 2
        Pair(-60, -71), Pair(-63, -42), Pair(-62, -32), Pair(-85, -30), Pair(-37, 17), Pair(-61, -47), Pair(-91, -42), Pair(-44, -128),
        Pair(-41, -54), Pair(-46, 18), Pair(-44, -11), Pair(-49, 1), Pair(-106, -13), Pair(-52, -24), Pair(-117, 15), Pair(18, -5),
        Pair(-45, -66), Pair(-61, 19), Pair(-41, 1), Pair(-76, 3), Pair(-160, 16), Pair(-126, -13), Pair(-37, -20), Pair(32, -50),
        Pair(43, -17), Pair(-86, 3), Pair(-82, -18), Pair(-54, -16), Pair(-29, -17), Pair(-61, -18), Pair(-124, 16), Pair(2, -17),
        Pair(-20, -18), Pair(-9, -16), Pair(85, -55), Pair(-62, -14), Pair(-22, -23), Pair(-16, -11), Pair(-76, -23), Pair(-1, 23),
        Pair(-32, 14), Pair(-12, -22), Pair(3, -18), Pair(11, -19), Pair(35, -45), Pair(-64, -37), Pair(8, -21), Pair(-14, -56),
        Pair(-57, -64), Pair(-63, -14), Pair(-35, -35), Pair(34, -21), Pair(-5, -11), Pair(32, -34), Pair(-97, -11), Pair(-66, -67),
        Pair(-23, -30), Pair(-153, 73), Pair(-97, -9), Pair(-61, -17), Pair(108, -69), Pair(30, -27), Pair(-23, -7), Pair(-50, -48)
      },
      { // Piece 3
        Pair(-12, -33), Pair(-63, -18), Pair(-35, -31), Pair(-39, -22), Pair(-54, -4), Pair(34, -4), Pair(-47, -14), Pair(0, -33),
        Pair(-43, -41), Pair(-55, -30), Pair(-101, -37), Pair(-22, -34), Pair(-87, -7), Pair(-109, -29), Pair(65, -62), Pair(-27, -50),
        Pair(-46, -30), Pair(6, -52), Pair(-83, -40), Pair(47, -53), Pair(-84, -30), Pair(-53, -38), Pair(-41, -44), Pair(-112, -22),
        Pair(-24, -53), Pair(-20, -54), Pair(-33, -51), Pair(71, -54), Pair(-130, -17), Pair(63, -67), Pair(-120, -29), Pair(-27, -52),
        Pair(-65, -52), Pair(-9, -66), Pair(78, -73), Pair(-2, -78), Pair(11, -63), Pair(50, -40), Pair(6, -81), Pair(-57, -74),
        Pair(-33, -61), Pair(-46, -16), Pair(-28, -34), Pair(-56, -21), Pair(-9, -67), Pair(-50, -49), Pair(33, -57), Pair(-35, -35),
        Pair(-108, -66), Pair(-48, -59), Pair(27, -76), Pair(79, -83), Pair(33, -107), Pair(83, -67), Pair(15, -86), Pair(6, -90),
        Pair(-7, -97), Pair(-120, -62), Pair(-17, -83), Pair(-23, -83), Pair(64, -92), Pair(28, -72), Pair(12, -101), Pair(-45, -110)
      },
      { // Piece 4
        Pair(-51, -112), Pair(-57, -164), Pair(-10, -44), Pair(1, -14), Pair(-29, -48), Pair(-59, -46), Pair(-28, -13), Pair(-46, -59),
        Pair(-35, -129), Pair(31, -35), Pair(-43, -41), Pair(26, -9), Pair(0, -30), Pair(-11, -16), Pair(-20, -117), Pair(9, -39),
        Pair(33, 12), Pair(-41, -130), Pair(-27, -42), Pair(-44, -74), Pair(-2, -29), Pair(-24, -107), Pair(37, -46), Pair(8, -14),
        Pair(-21, -40), Pair(18, -22), Pair(-28, -84), Pair(6, -33), Pair(31, 17), Pair(-6, -73), Pair(-40, -149), Pair(45, -14),
        Pair(-51, -88), Pair(9, 6), Pair(-24, -75), Pair(-12, -38), Pair(24, -7), Pair(-28, -63), Pair(25, 33), Pair(42, -24),
        Pair(37, 1), Pair(-45, -45), Pair(-2, -3), Pair(7, -18), Pair(44, -23), Pair(-6, -51), Pair(-2, -1), Pair(88, 12),
        Pair(-22, -58), Pair(46, 63), Pair(43, 24), Pair(-62, -31), Pair(-14, -75), Pair(-7, -59), Pair(-1, -46), Pair(11, -2),
        Pair(-88, -123), Pair(-25, -77), Pair(25, -57), Pair(-18, -111), Pair(-8, -66), Pair(-39, -75), Pair(-56, -93), Pair(-45, -79)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(-22, 23), Pair(-33, 23), Pair(-72, 24), Pair(-74, 31), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-2, 14), Pair(10, 49), Pair(9, -32), Pair(21, -27), Pair(0, 58), Pair(-12, -28), Pair(-29, 14), Pair(5, -26),
        Pair(18, 8), Pair(-11, 17), Pair(21, 91), Pair(54, 60), Pair(-17, -31), Pair(-4, -15), Pair(-12, 142), Pair(25, -9),
        Pair(-69, 8), Pair(-63, 49), Pair(73, 21), Pair(-31, 33), Pair(-32, -19), Pair(-32, -20), Pair(-9, 9), Pair(-26, -23),
        Pair(-18, -31), Pair(-44, -20), Pair(-13, -24), Pair(-69, 0), Pair(-34, -55), Pair(60, -58), Pair(-9, 0), Pair(-122, -11),
        Pair(-11, -56), Pair(-52, 20), Pair(-26, -39), Pair(-63, -1), Pair(-49, -6), Pair(-63, -32), Pair(-114, -3), Pair(-129, -8),
        Pair(43, -35), Pair(19, -10), Pair(76, -9), Pair(-42, -56), Pair(-40, -38), Pair(1, -26), Pair(-14, -2), Pair(56, -16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, -66), Pair(-1, -12), Pair(0, 1), Pair(3, 5), Pair(-12, -75), Pair(-12, -122), Pair(-7, 15), Pair(2, 47),
        Pair(5, 28), Pair(-13, -47), Pair(-24, -46), Pair(-1, -27), Pair(-21, -115), Pair(2, -14), Pair(19, 21), Pair(-65, -79),
        Pair(11, -52), Pair(9, -28), Pair(19, 42), Pair(24, -71), Pair(-42, -1), Pair(9, 68), Pair(22, 68), Pair(-1, -17),
        Pair(2, -6), Pair(15, 37), Pair(-27, -39), Pair(-44, 17), Pair(15, 9), Pair(-10, -42), Pair(-27, -98), Pair(-6, 32),
        Pair(6, 42), Pair(5, -13), Pair(26, 8), Pair(12, 33), Pair(5, -73), Pair(1, 42), Pair(17, 42), Pair(-9, 4),
        Pair(-5, 3), Pair(33, 50), Pair(-12, -52), Pair(53, 87), Pair(34, 91), Pair(33, 56), Pair(2, -44), Pair(6, -32),
        Pair(-20, -28), Pair(-8, 39), Pair(13, -35), Pair(-27, -10), Pair(57, 41), Pair(-35, -101), Pair(-26, -46), Pair(-13, -61),
        Pair(-5, -40), Pair(-30, -11), Pair(20, 60), Pair(3, 0), Pair(-27, -66), Pair(36, 36), Pair(19, -96), Pair(1, 8)
      },
      { // Piece 2
        Pair(13, 86), Pair(2, -8), Pair(-19, -69), Pair(1, -14), Pair(2, 53), Pair(-9, 48), Pair(-4, 50), Pair(2, 29),
        Pair(-14, 49), Pair(38, 60), Pair(-5, -5), Pair(2, 36), Pair(0, -6), Pair(-24, -63), Pair(-40, 48), Pair(-2, 13),
        Pair(13, 91), Pair(19, 57), Pair(17, -16), Pair(40, 136), Pair(-14, -83), Pair(-12, 38), Pair(-16, -44), Pair(-16, 44),
        Pair(6, 34), Pair(-10, 55), Pair(6, 38), Pair(57, 131), Pair(24, 46), Pair(-18, 4), Pair(-9, 29), Pair(-13, -25),
        Pair(-16, -13), Pair(-42, 13), Pair(42, -21), Pair(-7, 21), Pair(-31, 17), Pair(2, 36), Pair(-14, -37), Pair(18, 39),
        Pair(-9, -39), Pair(-15, -6), Pair(-32, -9), Pair(53, 38), Pair(38, 21), Pair(17, -51), Pair(11, -38), Pair(-2, -4),
        Pair(3, 6), Pair(-9, 75), Pair(-18, 64), Pair(17, -56), Pair(-40, 25), Pair(-5, 27), Pair(-2, 83), Pair(-20, -60),
        Pair(-7, -88), Pair(-4, -59), Pair(-23, -99), Pair(-21, -101), Pair(14, 33), Pair(6, -51), Pair(22, 84), Pair(-3, -13)
      },
      { // Piece 3
        Pair(4, 37), Pair(-3, 9), Pair(20, 45), Pair(23, 72), Pair(-18, -66), Pair(-24, 40), Pair(-1, 63), Pair(-1, -30),
        Pair(-19, -24), Pair(16, 32), Pair(-13, -48), Pair(-39, 5), Pair(30, 46), Pair(-37, -82), Pair(-1, 82), Pair(33, -17),
        Pair(-67, -25), Pair(-6, 6), Pair(-30, 31), Pair(38, 17), Pair(-12, 6), Pair(34, 7), Pair(9, 26), Pair(-17, -11),
        Pair(20, -9), Pair(24, 42), Pair(16, 22), Pair(-16, 31), Pair(-11, 12), Pair(12, -9), Pair(-3, 6), Pair(-21, -32),
        Pair(23, 79), Pair(18, 19), Pair(-29, -61), Pair(21, 23), Pair(22, -13), Pair(-10, -20), Pair(-32, -19), Pair(-45, -69),
        Pair(17, -110), Pair(35, 21), Pair(-17, -40), Pair(-38, -75), Pair(14, 10), Pair(25, -45), Pair(13, 27), Pair(-34, 79),
        Pair(-28, -112), Pair(-18, -80), Pair(3, -21), Pair(44, 11), Pair(33, -37), Pair(-4, -28), Pair(21, 98), Pair(1, 2),
        Pair(37, 3), Pair(-16, -26), Pair(-31, -52), Pair(24, -52), Pair(20, 5), Pair(-64, -90), Pair(-4, -12), Pair(12, -60)
      },
      { // Piece 4
        Pair(-12, -22), Pair(-21, -48), Pair(-14, -27), Pair(-18, -34), Pair(-21, -16), Pair(-52, -52), Pair(-12, -13), Pair(-44, -73),
        Pair(-24, -40), Pair(0, -34), Pair(-9, 1), Pair(26, 38), Pair(51, 62), Pair(-45, -35), Pair(-56, -92), Pair(17, 33),
        Pair(-26, -58), Pair(44, 77), Pair(-27, -13), Pair(0, -12), Pair(-49, -39), Pair(-66, -56), Pair(15, 18), Pair(17, 21),
        Pair(13, 18), Pair(-50, -78), Pair(-34, -56), Pair(57, 60), Pair(4, -49), Pair(-29, -59), Pair(-30, -45), Pair(-2, -31),
        Pair(-11, -19), Pair(30, 20), Pair(-3, -52), Pair(37, 39), Pair(51, 84), Pair(-13, -49), Pair(-3, -12), Pair(-26, -63),
        Pair(-23, -86), Pair(-37, -73), Pair(27, 9), Pair(-8, -37), Pair(8, 7), Pair(18, 25), Pair(22, 32), Pair(-17, -3),
        Pair(-27, -64), Pair(-7, -40), Pair(-29, -58), Pair(-28, -42), Pair(4, 21), Pair(-29, -36), Pair(6, 15), Pair(-8, -27),
        Pair(-5, -11), Pair(1, -4), Pair(-1, 8), Pair(-43, -81), Pair(-16, -41), Pair(-27, -41), Pair(-11, -24), Pair(8, 13)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(30, 35), Pair(42, 14), Pair(-86, 30), Pair(-149, 41), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 2
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-19, 47), Pair(-37, 59), Pair(-47, 67), Pair(6, -13), Pair(18, -43), Pair(114, -81), Pair(-28, -97), Pair(-147, -58),
        Pair(-12, 84), Pair(3, 63), Pair(28, 34), Pair(32, 0), Pair(73, -17), Pair(87, -8), Pair(45, 25), Pair(0, 33),
        Pair(-6, 30), Pair(-4, 29), Pair(-2, 5), Pair(15, -20), Pair(42, -29), Pair(38, -26), Pair(3, 11), Pair(-9, 12),
        Pair(-8, 14), Pair(-6, 19), Pair(5, -8), Pair(12, -20), Pair(22, -27), Pair(31, -21), Pair(7, -6), Pair(-10, -9),
        Pair(-20, 5), Pair(-15, 10), Pair(-10, -6), Pair(-4, -9), Pair(3, -6), Pair(12, -14), Pair(6, -11), Pair(-26, -18),
        Pair(-10, 9), Pair(-9, 17), Pair(-12, 10), Pair(-8, 3), Pair(-5, 12), Pair(32, -4), Pair(29, -5), Pair(-18, -20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-298, 69), Pair(-216, 42), Pair(-170, 59), Pair(-54, 36), Pair(1, 17), Pair(-83, 16), Pair(-143, -116), Pair(-123, -110),
        Pair(-69, 35), Pair(-42, 37), Pair(-21, 36), Pair(41, 40), Pair(39, 29), Pair(53, 25), Pair(27, 58), Pair(101, -51),
        Pair(-63, 31), Pair(-10, 34), Pair(-2, 65), Pair(26, 40), Pair(27, 50), Pair(76, 33), Pair(6, 54), Pair(19, 35),
        Pair(-38, 51), Pair(6, 46), Pair(24, 59), Pair(54, 53), Pair(43, 61), Pair(68, 42), Pair(24, 54), Pair(38, 41),
        Pair(-22, 35), Pair(7, 40), Pair(25, 60), Pair(27, 56), Pair(35, 58), Pair(44, 41), Pair(52, 38), Pair(11, 34),
        Pair(-37, 14), Pair(-17, 32), Pair(1, 42), Pair(17, 58), Pair(27, 51), Pair(12, 31), Pair(10, 21), Pair(-10, 19),
        Pair(-46, 22), Pair(-37, 38), Pair(-25, 34), Pair(-5, 31), Pair(-5, 29), Pair(-3, 12), Pair(-5, 15), Pair(4, -1),
        Pair(-77, 23), Pair(-42, 10), Pair(-37, 24), Pair(-16, 34), Pair(-12, 35), Pair(3, 7), Pair(-20, 11), Pair(-36, 1)
      },
      { // Piece 2
        Pair(-34, 35), Pair(-113, 53), Pair(-134, 61), Pair(-169, 88), Pair(-95, 23), Pair(-103, 35), Pair(2, 65), Pair(-61, 47),
        Pair(-45, 48), Pair(-15, 40), Pair(-15, 35), Pair(-43, 43), Pair(-33, 15), Pair(-7, 25), Pair(-70, 88), Pair(-22, 58),
        Pair(-17, 40), Pair(-23, 53), Pair(-2, 41), Pair(-21, 40), Pair(10, 23), Pair(23, 59), Pair(30, 46), Pair(8, 42),
        Pair(-23, 35), Pair(1, 38), Pair(0, 35), Pair(18, 51), Pair(10, 35), Pair(34, 15), Pair(-11, 44), Pair(2, 29),
        Pair(-14, 16), Pair(-16, 30), Pair(13, 38), Pair(7, 36), Pair(26, 22), Pair(3, 31), Pair(3, 21), Pair(3, 27),
        Pair(-16, 16), Pair(11, 37), Pair(-3, 39), Pair(11, 33), Pair(6, 44), Pair(13, 34), Pair(11, 34), Pair(5, 19),
        Pair(-1, 34), Pair(-1, 10), Pair(15, 14), Pair(-4, 23), Pair(0, 28), Pair(13, 8), Pair(28, 11), Pair(-3, -7),
        Pair(-11, 2), Pair(19, 10), Pair(2, 17), Pair(-2, 20), Pair(-11, 35), Pair(-11, 34), Pair(-5, 19), Pair(-11, 1)
      },
      { // Piece 3
        Pair(6, 89), Pair(85, 68), Pair(-14, 115), Pair(8, 74), Pair(33, 75), Pair(63, 111), Pair(67, 109), Pair(45, 62),
        Pair(5, 69), Pair(-4, 82), Pair(24, 80), Pair(47, 67), Pair(34, 67), Pair(99, 46), Pair(42, 82), Pair(55, 56),
        Pair(6, 55), Pair(43, 54), Pair(35, 60), Pair(32, 63), Pair(68, 33), Pair(109, 20), Pair(113, 15), Pair(39, 28),
        Pair(-5, 58), Pair(34, 55), Pair(35, 54), Pair(50, 52), Pair(53, 35), Pair(64, 32), Pair(53, 34), Pair(36, 28),
        Pair(-13, 49), Pair(5, 50), Pair(4, 55), Pair(17, 55), Pair(11, 41), Pair(5, 45), Pair(39, 25), Pair(3, 27),
        Pair(-11, 33), Pair(-7, 38), Pair(-12, 40), Pair(3, 45), Pair(1, 42), Pair(6, 31), Pair(41, 4), Pair(-12, 13),
        Pair(-29, 34), Pair(-12, 42), Pair(-1, 42), Pair(0, 42), Pair(10, 24), Pair(9, 31), Pair(21, 11), Pair(2, -2),
        Pair(-13, 33), Pair(-12, 33), Pair(-6, 34), Pair(4, 29), Pair(8, 20), Pair(12, 15), Pair(9, 8), Pair(-13, 21)
      },
      { // Piece 4
        Pair(-145, 188), Pair(-31, 111), Pair(-49, 129), Pair(-8, 113), Pair(62, 74), Pair(13, 116), Pair(-3, 110), Pair(81, -31),
        Pair(-64, 87), Pair(-63, 94), Pair(-43, 105), Pair(-39, 103), Pair(-72, 161), Pair(45, 106), Pair(-125, 190), Pair(-18, 146),
        Pair(-30, 55), Pair(-22, 62), Pair(-20, 97), Pair(-14, 96), Pair(-7, 139), Pair(61, 60), Pair(15, 123), Pair(-6, 99),
        Pair(-22, 50), Pair(-15, 83), Pair(-33, 103), Pair(-23, 118), Pair(4, 93), Pair(6, 103), Pair(7, 103), Pair(16, 71),
        Pair(-25, 52), Pair(-21, 79), Pair(-16, 91), Pair(-12, 101), Pair(-23, 111), Pair(-2, 84), Pair(12, 70), Pair(-2, 65),
        Pair(-32, 35), Pair(-16, 50), Pair(-17, 74), Pair(-17, 78), Pair(-11, 84), Pair(2, 58), Pair(7, 56), Pair(2, 34),
        Pair(-23, 52), Pair(-27, 35), Pair(-10, 20), Pair(-9, 43), Pair(-5, 39), Pair(3, -4), Pair(20, -30), Pair(26, -41),
        Pair(-23, 16), Pair(-39, 39), Pair(-21, 10), Pair(-7, 18), Pair(-8, 21), Pair(-21, 9), Pair(-4, -36), Pair(-7, -4)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(26, -29), Pair(-10, 7), Pair(-29, 25), Pair(-59, 37), Pair(-61, 38), Pair(-39, 22), Pair(-8, -2), Pair(18, -37),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(89, 29), Pair(-38, 21), Pair(-26, -55), Pair(-4, -75), Pair(-22, -81), Pair(57, -111), Pair(-96, 63), Pair(36, 33),
        Pair(-14, 58), Pair(25, 41), Pair(36, -4), Pair(52, -41), Pair(101, -70), Pair(69, -13), Pair(-7, 46), Pair(16, 55),
        Pair(-18, 23), Pair(-2, 13), Pair(8, -13), Pair(24, -35), Pair(40, -23), Pair(27, -18), Pair(20, 3), Pair(12, 2),
        Pair(-28, 12), Pair(-19, 17), Pair(-2, -13), Pair(27, -29), Pair(26, -23), Pair(19, -20), Pair(10, -7), Pair(-8, -14),
        Pair(-39, 5), Pair(-22, 7), Pair(-3, -14), Pair(-5, -14), Pair(-3, -6), Pair(3, -17), Pair(7, -15), Pair(-27, -17),
        Pair(-30, 7), Pair(-12, 13), Pair(-11, 0), Pair(-17, 4), Pair(-8, 8), Pair(17, -12), Pair(15, -9), Pair(-19, -12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-160, -40), Pair(-84, -8), Pair(-112, 27), Pair(-56, 4), Pair(106, -12), Pair(-113, 23), Pair(-182, 4), Pair(-150, -39),
        Pair(-20, -6), Pair(-25, 16), Pair(8, 26), Pair(29, 5), Pair(15, 9), Pair(41, 23), Pair(-2, 11), Pair(-66, 31),
        Pair(-18, 34), Pair(-38, 44), Pair(13, 47), Pair(65, 30), Pair(28, 37), Pair(31, 34), Pair(28, -4), Pair(32, -20),
        Pair(10, 22), Pair(8, 37), Pair(38, 49), Pair(36, 47), Pair(41, 59), Pair(69, 40), Pair(45, 27), Pair(27, 23),
        Pair(-20, 21), Pair(-34, 49), Pair(24, 52), Pair(42, 40), Pair(34, 43), Pair(38, 51), Pair(49, 18), Pair(20, 34),
        Pair(-32, 6), Pair(-7, 26), Pair(8, 26), Pair(0, 49), Pair(14, 46), Pair(13, 27), Pair(23, 8), Pair(-8, 6),
        Pair(-78, 23), Pair(-32, 24), Pair(-14, 9), Pair(-1, 31), Pair(1, 18), Pair(2, 27), Pair(-13, -2), Pair(-30, 44),
        Pair(-120, 43), Pair(-38, 33), Pair(-27, 13), Pair(-21, 30), Pair(-18, 3), Pair(9, 9), Pair(-21, 32), Pair(-130, 80)
      },
      { // Piece 2
        Pair(-64, 62), Pair(-84, 65), Pair(-37, 30), Pair(-166, 73), Pair(-61, 6), Pair(-103, 9), Pair(-117, 21), Pair(-56, -2),
        Pair(-33, 7), Pair(-12, 13), Pair(2, 16), Pair(20, 14), Pair(-57, 7), Pair(-44, 15), Pair(-42, 35), Pair(-30, -4),
        Pair(-29, 22), Pair(-10, 27), Pair(40, 1), Pair(21, 9), Pair(110, -22), Pair(10, 41), Pair(28, 16), Pair(1, 29),
        Pair(-39, 25), Pair(5, 10), Pair(20, 9), Pair(7, 19), Pair(28, 9), Pair(34, 20), Pair(4, 12), Pair(-15, 11),
        Pair(-25, 11), Pair(-10, 12), Pair(10, 11), Pair(21, 16), Pair(14, 17), Pair(-2, 22), Pair(32, 10), Pair(24, 3),
        Pair(-10, 20), Pair(27, 7), Pair(17, 14), Pair(22, 23), Pair(12, 27), Pair(32, 9), Pair(28, 9), Pair(15, -3),
        Pair(-22, 4), Pair(15, -6), Pair(20, -2), Pair(0, 12), Pair(11, 12), Pair(-2, 6), Pair(32, -3), Pair(24, -16),
        Pair(23, -18), Pair(38, -9), Pair(-3, 29), Pair(-36, 35), Pair(-40, 15), Pair(-24, 46), Pair(64, -55), Pair(-29, 26)
      },
      { // Piece 3
        Pair(63, 22), Pair(-70, 92), Pair(49, 51), Pair(28, 21), Pair(-3, 68), Pair(-19, 115), Pair(20, 68), Pair(-14, 73),
        Pair(15, 47), Pair(20, 52), Pair(16, 50), Pair(80, 37), Pair(110, 20), Pair(11, 56), Pair(13, 56), Pair(9, 45),
        Pair(8, 45), Pair(53, 32), Pair(-8, 51), Pair(-3, 43), Pair(46, 22), Pair(7, 33), Pair(89, 8), Pair(16, 28),
        Pair(-24, 40), Pair(6, 21), Pair(21, 34), Pair(-1, 34), Pair(12, 22), Pair(21, 35), Pair(2, 27), Pair(-26, 58),
        Pair(-27, 24), Pair(-58, 44), Pair(-35, 30), Pair(-46, 54), Pair(-30, 41), Pair(-64, 70), Pair(-31, 43), Pair(-53, 39),
        Pair(-34, 16), Pair(-54, 27), Pair(-2, 19), Pair(-1, 10), Pair(-26, 25), Pair(-4, 22), Pair(1, 1), Pair(-60, 47),
        Pair(-35, -1), Pair(-39, 11), Pair(-23, 15), Pair(-38, 23), Pair(-9, 0), Pair(-12, -1), Pair(-41, 29), Pair(-24, -12),
        Pair(-37, 20), Pair(-25, 9), Pair(-19, 18), Pair(-21, 6), Pair(-7, -8), Pair(-16, 6), Pair(-38, 17), Pair(-29, 7)
      },
      { // Piece 4
        Pair(-7, 33), Pair(32, 26), Pair(61, 30), Pair(77, 74), Pair(52, 79), Pair(128, 22), Pair(74, 44), Pair(-10, 124),
        Pair(25, 4), Pair(-5, 15), Pair(-17, 57), Pair(65, 27), Pair(-60, 78), Pair(10, 16), Pair(22, 10), Pair(58, 23),
        Pair(-3, 5), Pair(-17, 47), Pair(73, -12), Pair(-5, 79), Pair(26, 67), Pair(12, 103), Pair(70, 16), Pair(15, 46),
        Pair(49, -45), Pair(12, 61), Pair(79, 13), Pair(-19, 115), Pair(19, 68), Pair(29, 72), Pair(24, 63), Pair(46, 17),
        Pair(6, 8), Pair(-20, 113), Pair(25, 11), Pair(21, 52), Pair(3, 76), Pair(28, 39), Pair(19, 49), Pair(7, 29),
        Pair(-11, 45), Pair(5, 26), Pair(10, 35), Pair(0, 39), Pair(15, 36), Pair(-5, 56), Pair(27, -12), Pair(-26, 42),
        Pair(17, -33), Pair(9, -53), Pair(0, 32), Pair(4, 14), Pair(-4, 33), Pair(14, 1), Pair(0, -12), Pair(12, -14),
        Pair(-23, 65), Pair(-45, 36), Pair(-15, 1), Pair(-7, -16), Pair(1, -42), Pair(-27, 17), Pair(-10, 23), Pair(8, -30)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(38, -38), Pair(31, -11), Pair(14, -1), Pair(-22, 22), Pair(-17, 15), Pair(-13, 8), Pair(16, -15), Pair(48, -47),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(16, -2), Pair(29, -17), Pair(19, -25), Pair(33, -66), Pair(14, -68), Pair(41, -79), Pair(-38, -8), Pair(25, -32),
        Pair(-30, 59), Pair(10, 44), Pair(17, 16), Pair(48, -28), Pair(38, -28), Pair(81, -33), Pair(41, 4), Pair(-32, 33),
        Pair(-13, 30), Pair(-11, 26), Pair(-13, 5), Pair(6, -16), Pair(24, -14), Pair(24, -12), Pair(-3, 15), Pair(-10, 12),
        Pair(-19, 11), Pair(-18, 24), Pair(-7, -5), Pair(3, -10), Pair(15, -16), Pair(18, -12), Pair(-3, 5), Pair(-20, 0),
        Pair(-29, 7), Pair(-24, 13), Pair(-19, 2), Pair(-6, -3), Pair(4, -7), Pair(5, -10), Pair(-8, -1), Pair(-27, -9),
        Pair(-22, 12), Pair(-17, 18), Pair(-15, 7), Pair(-20, 15), Pair(-6, 10), Pair(26, -6), Pair(21, 0), Pair(-29, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-147, -33), Pair(-55, 50), Pair(-104, 35), Pair(-57, 28), Pair(45, 6), Pair(67, 0), Pair(50, 1), Pair(-134, -68),
        Pair(-5, 0), Pair(-64, 40), Pair(-11, 32), Pair(44, 36), Pair(24, 29), Pair(74, -2), Pair(-25, 17), Pair(-44, 15),
        Pair(-33, 29), Pair(7, 35), Pair(35, 45), Pair(42, 33), Pair(37, 43), Pair(54, 26), Pair(69, 3), Pair(28, 2),
        Pair(-13, 45), Pair(6, 46), Pair(33, 51), Pair(71, 41), Pair(67, 46), Pair(87, 37), Pair(52, 33), Pair(51, 4),
        Pair(-23, 40), Pair(23, 45), Pair(25, 60), Pair(54, 50), Pair(61, 54), Pair(65, 42), Pair(54, 33), Pair(30, 32),
        Pair(-40, 30), Pair(-16, 38), Pair(-2, 52), Pair(16, 58), Pair(43, 46), Pair(24, 31), Pair(28, 20), Pair(4, 28),
        Pair(-48, 27), Pair(-25, 26), Pair(-22, 39), Pair(1, 38), Pair(3, 36), Pair(-9, 31), Pair(-19, 40), Pair(-29, 39),
        Pair(-181, 39), Pair(-44, 20), Pair(-30, 21), Pair(-31, 45), Pair(-26, 37), Pair(-2, 20), Pair(-8, 24), Pair(-158, 85)
      },
      { // Piece 2
        Pair(-54, 21), Pair(-37, 37), Pair(-97, 45), Pair(-20, 26), Pair(-48, 27), Pair(-69, 24), Pair(-13, 36), Pair(-88, 52),
        Pair(-86, 30), Pair(-21, 32), Pair(0, 21), Pair(17, 20), Pair(-15, 23), Pair(-2, 34), Pair(-12, 37), Pair(-52, 39),
        Pair(-56, 49), Pair(-12, 40), Pair(24, 24), Pair(-21, 27), Pair(33, 16), Pair(25, 26), Pair(-25, 30), Pair(23, 15),
        Pair(-18, 30), Pair(5, 28), Pair(11, 32), Pair(39, 28), Pair(42, 25), Pair(53, 9), Pair(28, 26), Pair(5, 18),
        Pair(-2, 17), Pair(-16, 33), Pair(7, 22), Pair(17, 31), Pair(41, 11), Pair(11, 29), Pair(14, 13), Pair(4, 22),
        Pair(-23, 28), Pair(-4, 30), Pair(-6, 34), Pair(16, 30), Pair(5, 37), Pair(22, 18), Pair(8, 27), Pair(2, 8),
        Pair(-40, 24), Pair(-3, 11), Pair(7, 5), Pair(-8, 25), Pair(7, 20), Pair(4, 14), Pair(24, 5), Pair(14, -5),
        Pair(-7, 6), Pair(-7, 22), Pair(-7, 21), Pair(-17, 28), Pair(-23, 34), Pair(-15, 27), Pair(5, 24), Pair(-33, 7)
      },
      { // Piece 3
        Pair(-3, 62), Pair(-8, 73), Pair(-22, 74), Pair(-11, 72), Pair(14, 51), Pair(76, 28), Pair(1, 75), Pair(20, 65),
        Pair(-6, 57), Pair(-6, 68), Pair(0, 65), Pair(60, 47), Pair(30, 50), Pair(40, 43), Pair(-35, 65), Pair(-38, 75),
        Pair(-22, 60), Pair(-2, 57), Pair(17, 50), Pair(28, 41), Pair(52, 21), Pair(65, 36), Pair(64, 33), Pair(-7, 46),
        Pair(-23, 55), Pair(9, 54), Pair(9, 58), Pair(26, 44), Pair(54, 28), Pair(60, 23), Pair(53, 29), Pair(-28, 48),
        Pair(-50, 49), Pair(-52, 59), Pair(-35, 52), Pair(-27, 53), Pair(-16, 46), Pair(-2, 44), Pair(-34, 46), Pair(-35, 43),
        Pair(-61, 40), Pair(-49, 49), Pair(-31, 36), Pair(-18, 34), Pair(-15, 35), Pair(-17, 30), Pair(-9, 22), Pair(-40, 21),
        Pair(-46, 27), Pair(-46, 36), Pair(-32, 35), Pair(-15, 27), Pair(-11, 18), Pair(-8, 15), Pair(-33, 27), Pair(-54, 18),
        Pair(-44, 35), Pair(-39, 37), Pair(-35, 36), Pair(-27, 26), Pair(-23, 19), Pair(-23, 23), Pair(-19, 17), Pair(-53, 33)
      },
      { // Piece 4
        Pair(3, 32), Pair(0, 35), Pair(3, 53), Pair(50, 16), Pair(23, 45), Pair(101, -3), Pair(34, 36), Pair(61, 22),
        Pair(24, 18), Pair(-38, 93), Pair(-23, 76), Pair(-40, 96), Pair(57, 66), Pair(14, 68), Pair(19, 122), Pair(51, 60),
        Pair(-3, 37), Pair(32, 17), Pair(12, 66), Pair(53, 31), Pair(45, 66), Pair(66, 74), Pair(77, 38), Pair(93, 6),
        Pair(0, 20), Pair(4, 73), Pair(40, 31), Pair(17, 73), Pair(24, 94), Pair(70, 65), Pair(62, 60), Pair(35, 51),
        Pair(-35, 55), Pair(7, 60), Pair(12, 66), Pair(11, 86), Pair(37, 60), Pair(40, 49), Pair(49, 36), Pair(18, 55),
        Pair(-3, 13), Pair(8, 43), Pair(5, 58), Pair(15, 63), Pair(23, 43), Pair(34, 44), Pair(38, 14), Pair(9, 53),
        Pair(-6, 28), Pair(0, 31), Pair(10, 16), Pair(18, 20), Pair(14, 41), Pair(24, 4), Pair(17, -9), Pair(33, -36),
        Pair(18, -23), Pair(-36, 33), Pair(-14, 39), Pair(9, 29), Pair(7, 14), Pair(-11, 8), Pair(36, -27), Pair(-61, 39)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(52, -36), Pair(7, 2), Pair(-14, 19), Pair(-27, 35), Pair(-31, 30), Pair(-31, 27), Pair(7, 2), Pair(23, -29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(60, -22), Pair(81, -36), Pair(4, -33), Pair(55, -57), Pair(32, -79), Pair(28, -57), Pair(101, -14), Pair(6, -5),
        Pair(-22, 34), Pair(4, 32), Pair(-22, 8), Pair(44, -36), Pair(45, -28), Pair(44, -18), Pair(53, 7), Pair(-3, 31),
        Pair(-37, 25), Pair(-38, 23), Pair(-30, -2), Pair(-9, -14), Pair(15, -16), Pair(28, -20), Pair(30, 2), Pair(-15, 8),
        Pair(-56, 16), Pair(-43, 22), Pair(-13, -3), Pair(-9, 0), Pair(-11, 2), Pair(2, -5), Pair(-5, 11), Pair(-23, -4),
        Pair(-58, 8), Pair(-54, 17), Pair(-32, 0), Pair(-20, -3), Pair(-17, 0), Pair(-2, -7), Pair(-15, -2), Pair(-37, -6),
        Pair(-51, 17), Pair(-42, 24), Pair(-5, 2), Pair(3, -2), Pair(-17, 1), Pair(34, -10), Pair(6, 1), Pair(-39, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-124, -63), Pair(-28, -35), Pair(-63, -5), Pair(141, -54), Pair(-1, -1), Pair(-82, 9), Pair(-139, -1), Pair(-54, -93),
        Pair(-27, -10), Pair(-19, 5), Pair(5, 0), Pair(79, 0), Pair(26, 3), Pair(106, -34), Pair(-25, 4), Pair(-28, 1),
        Pair(-111, 0), Pair(25, -3), Pair(14, 29), Pair(45, 21), Pair(103, -5), Pair(159, -18), Pair(49, -24), Pair(58, -30),
        Pair(-5, 10), Pair(43, 10), Pair(58, 24), Pair(104, -1), Pair(81, 13), Pair(83, 17), Pair(109, -14), Pair(21, 8),
        Pair(-19, 19), Pair(4, 19), Pair(46, 34), Pair(84, 24), Pair(96, 16), Pair(76, 18), Pair(75, 9), Pair(11, -1),
        Pair(-8, -5), Pair(-11, 17), Pair(3, 30), Pair(37, 31), Pair(43, 28), Pair(21, 20), Pair(9, 16), Pair(-33, 17),
        Pair(-97, 45), Pair(2, 6), Pair(-12, 15), Pair(36, 8), Pair(15, 8), Pair(-38, 24), Pair(57, -9), Pair(15, 13),
        Pair(-49, 24), Pair(-99, 40), Pair(-9, 16), Pair(-35, 25), Pair(30, 8), Pair(0, 9), Pair(-2, -3), Pair(-84, 37)
      },
      { // Piece 2
        Pair(-71, 23), Pair(90, -15), Pair(-136, 28), Pair(-88, 18), Pair(-3, 5), Pair(-2, 11), Pair(17, -3), Pair(-13, 21),
        Pair(-104, 22), Pair(-57, 28), Pair(-31, 6), Pair(24, -4), Pair(27, 3), Pair(20, 2), Pair(0, 3), Pair(-29, 7),
        Pair(-75, 28), Pair(70, -11), Pair(56, 1), Pair(3, 7), Pair(42, -13), Pair(49, 4), Pair(16, 5), Pair(69, -8),
        Pair(17, 6), Pair(5, 5), Pair(-9, 11), Pair(72, -10), Pair(32, -3), Pair(39, -7), Pair(43, -17), Pair(4, 3),
        Pair(11, -13), Pair(29, 1), Pair(8, 11), Pair(59, -2), Pair(45, 0), Pair(5, 17), Pair(21, 9), Pair(-10, -6),
        Pair(-47, 7), Pair(49, -10), Pair(-5, 8), Pair(12, 11), Pair(30, 13), Pair(12, 8), Pair(28, 3), Pair(-12, 14),
        Pair(-49, 18), Pair(3, -12), Pair(25, 0), Pair(-9, 4), Pair(10, -3), Pair(5, 0), Pair(10, -4), Pair(-30, -19),
        Pair(17, -3), Pair(0, 7), Pair(-34, 9), Pair(-32, 21), Pair(-11, 5), Pair(-50, 18), Pair(-87, 28), Pair(-111, 7)
      },
      { // Piece 3
        Pair(-11, 25), Pair(-37, 41), Pair(-49, 44), Pair(15, 20), Pair(-50, 40), Pair(20, 30), Pair(48, 18), Pair(-19, 33),
        Pair(-37, 15), Pair(-8, 21), Pair(7, 13), Pair(27, 10), Pair(34, 5), Pair(83, -9), Pair(-57, 32), Pair(-10, 10),
        Pair(-8, 10), Pair(-45, 25), Pair(7, 14), Pair(36, 4), Pair(70, -12), Pair(-21, 15), Pair(5, -1), Pair(-41, 25),
        Pair(-27, 21), Pair(-33, 29), Pair(1, 16), Pair(44, 3), Pair(51, -7), Pair(19, 11), Pair(29, 7), Pair(-14, 15),
        Pair(-75, 20), Pair(-43, 32), Pair(-19, 13), Pair(-31, 20), Pair(-3, 3), Pair(37, 5), Pair(13, 1), Pair(-16, 0),
        Pair(-56, -1), Pair(-24, 1), Pair(-21, -1), Pair(-48, 10), Pair(-59, 5), Pair(-46, 4), Pair(-28, -6), Pair(-106, 15),
        Pair(-79, 1), Pair(-30, -11), Pair(-33, -8), Pair(-38, -1), Pair(-38, -15), Pair(4, -25), Pair(-33, -5), Pair(-87, -16),
        Pair(-76, 7), Pair(-72, 11), Pair(-72, 19), Pair(-54, 6), Pair(-64, 0), Pair(-42, 0), Pair(-63, 7), Pair(-72, 9)
      },
      { // Piece 4
        Pair(9, -6), Pair(44, -19), Pair(125, -24), Pair(100, -21), Pair(23, 38), Pair(57, 39), Pair(220, -92), Pair(159, -53),
        Pair(82, -67), Pair(-36, 14), Pair(94, -67), Pair(-11, 26), Pair(87, -3), Pair(110, -28), Pair(124, -64), Pair(154, -70),
        Pair(-55, 27), Pair(56, -42), Pair(-65, 81), Pair(-7, 27), Pair(47, 9), Pair(81, 26), Pair(100, -2), Pair(66, -55),
        Pair(66, -67), Pair(9, -4), Pair(-10, 0), Pair(60, 10), Pair(55, 2), Pair(88, -23), Pair(103, -1), Pair(149, -98),
        Pair(143, -117), Pair(17, -23), Pair(-8, 8), Pair(57, -3), Pair(-34, 53), Pair(62, -50), Pair(116, -73), Pair(52, -16),
        Pair(57, -112), Pair(-41, 22), Pair(37, -20), Pair(-3, 15), Pair(85, -73), Pair(35, -28), Pair(61, -64), Pair(59, -42),
        Pair(-25, -22), Pair(-32, 1), Pair(-12, -37), Pair(6, -16), Pair(6, -24), Pair(56, -50), Pair(55, -105), Pair(-57, -58),
        Pair(-117, 25), Pair(9, -38), Pair(-10, 3), Pair(0, -25), Pair(14, -39), Pair(-54, 25), Pair(23, -82), Pair(-19, -5)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(61, -43), Pair(33, -8), Pair(16, 8), Pair(-5, 20), Pair(-6, 17), Pair(-7, 16), Pair(12, -4), Pair(30, -30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-39, -7), Pair(-31, -1), Pair(-63, -2), Pair(-2, -29), Pair(-61, -7), Pair(-88, 23), Pair(58, 37), Pair(-53, 13),
        Pair(-44, 31), Pair(-76, 40), Pair(-42, 26), Pair(-92, 19), Pair(-53, 22), Pair(20, 13), Pair(-36, 41), Pair(-39, 48),
        Pair(-66, 19), Pair(-70, 21), Pair(-45, 1), Pair(-51, 3), Pair(14, -16), Pair(-3, -12), Pair(-10, 11), Pair(-18, 10),
        Pair(-80, 11), Pair(-61, 16), Pair(-20, -11), Pair(-20, -5), Pair(-7, -13), Pair(8, -15), Pair(0, 5), Pair(-58, -1),
        Pair(-75, 2), Pair(-60, 13), Pair(-55, 4), Pair(-33, 9), Pair(-28, 11), Pair(-9, 0), Pair(-12, 3), Pair(-48, -8),
        Pair(-77, 16), Pair(-50, 19), Pair(-23, 1), Pair(2, 1), Pair(59, -20), Pair(34, -11), Pair(-8, 3), Pair(-82, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(35, -110), Pair(-29, -54), Pair(-42, -1), Pair(2, -33), Pair(31, -48), Pair(-25, -22), Pair(41, -4), Pair(-24, -137),
        Pair(-39, -18), Pair(-120, 2), Pair(41, -34), Pair(-8, -9), Pair(36, -11), Pair(45, -31), Pair(12, -28), Pair(-54, -10),
        Pair(-73, -13), Pair(9, -15), Pair(-36, 12), Pair(-6, -3), Pair(47, -11), Pair(79, -35), Pair(13, -61), Pair(-2, -27),
        Pair(-80, -7), Pair(-6, 3), Pair(12, 3), Pair(21, 2), Pair(57, -1), Pair(27, 1), Pair(88, -40), Pair(-64, -9),
        Pair(69, -39), Pair(-29, -7), Pair(76, -16), Pair(57, -4), Pair(118, -24), Pair(151, -28), Pair(110, -11), Pair(79, -53),
        Pair(-38, -21), Pair(-7, -3), Pair(0, -6), Pair(32, 8), Pair(66, 2), Pair(-86, 14), Pair(8, -3), Pair(-8, -19),
        Pair(-21, -36), Pair(-62, 3), Pair(-3, -9), Pair(22, -25), Pair(-19, -4), Pair(-26, -7), Pair(-114, -2), Pair(50, -21),
        Pair(-22, -57), Pair(-125, 4), Pair(16, -2), Pair(10, -11), Pair(-64, 6), Pair(18, -11), Pair(25, 7), Pair(-63, -32)
      },
      { // Piece 2
        Pair(-3, 8), Pair(-30, -26), Pair(21, -27), Pair(-68, 11), Pair(-62, -2), Pair(-47, -17), Pair(-37, -11), Pair(-6, 14),
        Pair(-102, -6), Pair(-58, 2), Pair(-75, -8), Pair(-26, -5), Pair(-51, -1), Pair(11, -15), Pair(-13, -30), Pair(48, -34),
        Pair(21, -14), Pair(-121, 14), Pair(-8, -7), Pair(-54, -10), Pair(0, -12), Pair(55, -18), Pair(-28, -12), Pair(29, -33),
        Pair(-138, 16), Pair(-35, 3), Pair(15, -7), Pair(33, -23), Pair(94, -25), Pair(-47, -3), Pair(135, -40), Pair(-36, 1),
        Pair(-21, -13), Pair(-46, -4), Pair(34, -28), Pair(67, -27), Pair(13, -19), Pair(11, -25), Pair(-28, -26), Pair(33, -23),
        Pair(-57, -6), Pair(-44, -4), Pair(14, -16), Pair(-18, 1), Pair(33, -12), Pair(4, 1), Pair(107, -32), Pair(-33, -11),
        Pair(-49, -18), Pair(-14, -19), Pair(6, -17), Pair(-41, -9), Pair(8, -24), Pair(-105, -3), Pair(-27, -14), Pair(-47, -24),
        Pair(-98, 19), Pair(-81, 26), Pair(5, -18), Pair(-38, -11), Pair(17, -24), Pair(1, -26), Pair(-113, 28), Pair(-83, -12)
      },
      { // Piece 3
        Pair(-53, -6), Pair(-75, 9), Pair(-54, 5), Pair(31, -19), Pair(-90, 5), Pair(-43, 14), Pair(-37, 11), Pair(-51, 5),
        Pair(-54, -24), Pair(-4, -26), Pair(-55, -13), Pair(1, -19), Pair(12, -25), Pair(16, -32), Pair(46, -44), Pair(27, -42),
        Pair(-18, -25), Pair(14, -32), Pair(2, -34), Pair(77, -48), Pair(84, -51), Pair(119, -54), Pair(95, -58), Pair(23, -41),
        Pair(-35, -17), Pair(44, -41), Pair(-76, -12), Pair(72, -60), Pair(-3, -38), Pair(13, -54), Pair(14, -35), Pair(-29, -29),
        Pair(-94, -11), Pair(-61, -9), Pair(-50, 3), Pair(-15, -13), Pair(-49, -16), Pair(67, -42), Pair(20, -22), Pair(-47, -31),
        Pair(-60, -35), Pair(-79, -11), Pair(-52, -39), Pair(-70, -23), Pair(-45, -28), Pair(62, -55), Pair(22, -48), Pair(-125, -15),
        Pair(-73, -46), Pair(-24, -60), Pair(-101, -24), Pair(-98, -31), Pair(-56, -38), Pair(-118, -16), Pair(-33, -41), Pair(-52, -58),
        Pair(-130, -15), Pair(-62, -36), Pair(-96, -18), Pair(-102, -10), Pair(-46, -35), Pair(-12, -50), Pair(-120, -3), Pair(-108, -21)
      },
      { // Piece 4
        Pair(17, -60), Pair(-18, -29), Pair(25, -39), Pair(52, -41), Pair(53, -18), Pair(30, -31), Pair(65, -87), Pair(30, 2),
        Pair(35, -98), Pair(6, -24), Pair(140, -88), Pair(85, -38), Pair(99, -51), Pair(31, -6), Pair(79, -54), Pair(-9, -4),
        Pair(59, -130), Pair(12, -102), Pair(91, -88), Pair(28, -49), Pair(84, -110), Pair(-2, -28), Pair(64, -88), Pair(76, -144),
        Pair(-44, -41), Pair(-22, -9), Pair(27, -71), Pair(73, -56), Pair(-1, -8), Pair(62, -7), Pair(79, -17), Pair(110, 3),
        Pair(-53, -41), Pair(0, -5), Pair(100, -30), Pair(26, -49), Pair(52, -65), Pair(19, -38), Pair(83, -65), Pair(-39, 5),
        Pair(-97, -38), Pair(-33, -8), Pair(108, -115), Pair(35, -76), Pair(42, -45), Pair(8, -39), Pair(-10, -35), Pair(29, -85),
        Pair(-36, -71), Pair(-6, -87), Pair(-53, -29), Pair(-3, -85), Pair(1, -64), Pair(-60, -111), Pair(30, -114), Pair(-8, -48),
        Pair(-19, -40), Pair(-21, -38), Pair(-13, -66), Pair(-40, -22), Pair(-19, -49), Pair(5, -33), Pair(-32, -31), Pair(71, -13)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(47, -28), Pair(67, -5), Pair(31, 10), Pair(6, 21), Pair(5, 23), Pair(-2, 21), Pair(24, 3), Pair(43, -26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, -48), Pair(42, -28), Pair(77, -30), Pair(14, -52), Pair(31, -10), Pair(24, -15), Pair(54, -25), Pair(41, -21),
        Pair(-118, 43), Pair(-78, 39), Pair(-185, 55), Pair(-156, 52), Pair(-153, 68), Pair(-95, 39), Pair(-79, 57), Pair(-50, 50),
        Pair(-118, 20), Pair(-104, 22), Pair(-118, 11), Pair(-118, 6), Pair(-84, 2), Pair(-41, -9), Pair(-45, 5), Pair(-69, 9),
        Pair(-99, 9), Pair(-63, 9), Pair(-30, -13), Pair(-30, -8), Pair(-49, -3), Pair(-3, -22), Pair(-36, -5), Pair(-54, -5),
        Pair(-118, 8), Pair(-80, 7), Pair(-72, 3), Pair(-107, 11), Pair(-59, 11), Pair(-12, -3), Pair(-56, 2), Pair(-90, -6),
        Pair(-99, 21), Pair(-71, 21), Pair(12, -6), Pair(-73, 11), Pair(9, -3), Pair(42, -6), Pair(11, 2), Pair(-114, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-40, -110), Pair(-28, -44), Pair(-68, -33), Pair(2, -70), Pair(-42, -78), Pair(-113, -48), Pair(10, -72), Pair(-10, -90),
        Pair(-99, -38), Pair(-16, -49), Pair(-96, -25), Pair(-91, -15), Pair(16, -53), Pair(4, -63), Pair(-60, -45), Pair(-94, -69),
        Pair(-113, -38), Pair(-103, -37), Pair(43, -42), Pair(-5, -32), Pair(-28, -32), Pair(-11, -35), Pair(-77, -57), Pair(7, -44),
        Pair(-56, -52), Pair(-38, -33), Pair(-20, -28), Pair(-6, -23), Pair(139, -57), Pair(121, -57), Pair(25, -64), Pair(90, -87),
        Pair(49, -67), Pair(-63, -32), Pair(34, -26), Pair(64, -35), Pair(6, -25), Pair(34, -38), Pair(20, -25), Pair(24, -39),
        Pair(-23, -80), Pair(-51, -30), Pair(-33, -26), Pair(27, -20), Pair(46, -25), Pair(59, -50), Pair(131, -58), Pair(18, -45),
        Pair(-45, -59), Pair(-4, -33), Pair(50, -51), Pair(22, -34), Pair(18, -56), Pair(74, -54), Pair(-97, 4), Pair(38, -65),
        Pair(-1, -91), Pair(-44, -68), Pair(-61, -36), Pair(-19, -41), Pair(66, -63), Pair(67, -62), Pair(10, -55), Pair(20, -91)
      },
      { // Piece 2
        Pair(-37, 2), Pair(-104, -7), Pair(-32, -18), Pair(-31, -26), Pair(-27, -17), Pair(-117, -12), Pair(-24, -20), Pair(-53, -9),
        Pair(-18, -42), Pair(-42, -15), Pair(-104, 9), Pair(-51, -11), Pair(-83, -4), Pair(-160, 8), Pair(-123, -20), Pair(-61, -21),
        Pair(-75, -47), Pair(-72, -15), Pair(-135, 17), Pair(-136, 1), Pair(-119, -1), Pair(-94, -7), Pair(-64, -7), Pair(-76, -9),
        Pair(14, -59), Pair(-77, -27), Pair(-61, -17), Pair(-60, -8), Pair(-77, -5), Pair(-90, 12), Pair(-130, -6), Pair(-3, -25),
        Pair(-13, -38), Pair(-130, -20), Pair(-18, -23), Pair(3, -34), Pair(-13, -7), Pair(61, -35), Pair(17, -25), Pair(96, -53),
        Pair(-81, -37), Pair(-47, -24), Pair(-147, -12), Pair(4, -36), Pair(123, -54), Pair(-83, -13), Pair(-43, -36), Pair(-68, -49),
        Pair(-60, -9), Pair(-54, -51), Pair(-57, -30), Pair(19, -51), Pair(80, -55), Pair(9, -47), Pair(-72, -34), Pair(38, -65),
        Pair(-36, -16), Pair(-186, 24), Pair(-103, -20), Pair(-31, -20), Pair(-43, -40), Pair(-96, -27), Pair(-47, -5), Pair(-26, -40)
      },
      { // Piece 3
        Pair(-75, -43), Pair(-120, -24), Pair(14, -53), Pair(-75, -30), Pair(-17, -52), Pair(50, -51), Pair(-19, -32), Pair(-82, -27),
        Pair(-32, -67), Pair(-71, -48), Pair(-38, -43), Pair(4, -62), Pair(-36, -58), Pair(-91, -26), Pair(-24, -50), Pair(-10, -61),
        Pair(12, -72), Pair(32, -67), Pair(-2, -57), Pair(-12, -71), Pair(3, -73), Pair(5, -57), Pair(11, -64), Pair(-10, -69),
        Pair(-29, -60), Pair(8, -69), Pair(-88, -47), Pair(23, -65), Pair(46, -86), Pair(37, -75), Pair(36, -68), Pair(-19, -70),
        Pair(30, -86), Pair(-63, -62), Pair(56, -91), Pair(-16, -65), Pair(14, -75), Pair(45, -93), Pair(16, -102), Pair(-14, -76),
        Pair(-60, -71), Pair(-70, -50), Pair(-2, -75), Pair(-57, -65), Pair(17, -81), Pair(89, -96), Pair(2, -60), Pair(-63, -68),
        Pair(-56, -79), Pair(-64, -69), Pair(10, -101), Pair(-30, -67), Pair(53, -116), Pair(179, -129), Pair(13, -74), Pair(-23, -80),
        Pair(-12, -93), Pair(53, -108), Pair(0, -78), Pair(27, -81), Pair(27, -111), Pair(37, -100), Pair(36, -89), Pair(-17, -83)
      },
      { // Piece 4
        Pair(-12, -189), Pair(-109, -125), Pair(13, -92), Pair(71, -88), Pair(-34, -97), Pair(-76, -103), Pair(-118, -93), Pair(-117, -138),
        Pair(-16, -109), Pair(-28, -157), Pair(51, -135), Pair(-6, -46), Pair(10, -47), Pair(2, -90), Pair(72, -139), Pair(61, -129),
        Pair(5, -138), Pair(-63, -102), Pair(2, -120), Pair(31, -132), Pair(20, -75), Pair(69, -179), Pair(21, -108), Pair(19, -109),
        Pair(-14, -125), Pair(21, -160), Pair(6, -111), Pair(2, -100), Pair(52, -110), Pair(-11, -113), Pair(-50, -143), Pair(36, -141),
        Pair(-32, -180), Pair(-3, -107), Pair(-63, -108), Pair(-14, -42), Pair(61, -82), Pair(-31, -52), Pair(-6, -38), Pair(-11, -50),
        Pair(-64, -117), Pair(-12, -1), Pair(4, -101), Pair(-5, -93), Pair(37, -50), Pair(14, -120), Pair(-23, -39), Pair(0, -77),
        Pair(-67, -164), Pair(-20, -159), Pair(-6, -110), Pair(17, -105), Pair(27, -130), Pair(-81, -84), Pair(2, -60), Pair(-65, -161),
        Pair(-7, -113), Pair(-77, -154), Pair(-18, -165), Pair(-41, -103), Pair(11, -97), Pair(-37, -108), Pair(-15, -79), Pair(-8, -87)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(25, -19), Pair(12, 4), Pair(26, 11), Pair(-20, 20), Pair(-8, 20), Pair(-19, 25), Pair(31, 5), Pair(1, -18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, -8), Pair(44, 12), Pair(-12, 64), Pair(33, -79), Pair(-67, 0), Pair(-5, 49), Pair(1, 50), Pair(17, 12),
        Pair(-52, 35), Pair(-48, 101), Pair(-58, 108), Pair(17, 26), Pair(3, 52), Pair(-60, 47), Pair(-4, 104), Pair(-29, 75),
        Pair(-92, 40), Pair(57, 13), Pair(-26, 35), Pair(-149, 25), Pair(-1, -5), Pair(-32, -7), Pair(-123, 51), Pair(-105, 34),
        Pair(-124, 18), Pair(42, -10), Pair(51, -33), Pair(-133, 21), Pair(-52, -22), Pair(152, -42), Pair(-90, 1), Pair(-58, -1),
        Pair(-60, -17), Pair(-127, 17), Pair(23, -33), Pair(-60, -4), Pair(21, -22), Pair(-18, -21), Pair(-3, -13), Pair(-43, -12),
        Pair(-83, 18), Pair(21, 23), Pair(44, 8), Pair(21, 67), Pair(-40, 25), Pair(69, -1), Pair(75, -6), Pair(-90, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-26, -69), Pair(-48, -121), Pair(-12, -77), Pair(-48, -156), Pair(-3, -62), Pair(-15, 2), Pair(-16, 8), Pair(-38, -94),
        Pair(-17, -76), Pair(-31, -59), Pair(-16, -52), Pair(28, 72), Pair(26, -60), Pair(-49, -127), Pair(-18, -35), Pair(4, -88),
        Pair(-22, -25), Pair(-17, -88), Pair(-29, 4), Pair(-20, 18), Pair(13, -51), Pair(-38, -17), Pair(2, -14), Pair(-31, -73),
        Pair(-25, -112), Pair(30, -77), Pair(-35, -28), Pair(-8, -19), Pair(89, -43), Pair(15, -11), Pair(-4, -39), Pair(-7, -74),
        Pair(10, -14), Pair(-29, -5), Pair(38, -3), Pair(2, -6), Pair(143, 9), Pair(22, -7), Pair(15, -47), Pair(-7, 48),
        Pair(-19, 27), Pair(-12, -95), Pair(-4, 4), Pair(47, 6), Pair(-59, 5), Pair(18, 12), Pair(30, -2), Pair(7, -6),
        Pair(-21, -120), Pair(-36, -159), Pair(-24, 39), Pair(-53, -20), Pair(12, -15), Pair(84, 1), Pair(-46, -95), Pair(58, -9),
        Pair(10, 22), Pair(5, -44), Pair(17, -43), Pair(-4, -20), Pair(-16, -47), Pair(28, -52), Pair(3, -31), Pair(-4, 30)
      },
      { // Piece 2
        Pair(11, 49), Pair(0, 22), Pair(4, 80), Pair(4, -22), Pair(14, 5), Pair(22, 35), Pair(21, -8), Pair(15, 26),
        Pair(-15, -6), Pair(-28, -30), Pair(-27, 28), Pair(-27, 52), Pair(38, 23), Pair(7, -67), Pair(34, -4), Pair(51, 88),
        Pair(-25, -30), Pair(-14, -57), Pair(-19, -3), Pair(-20, 17), Pair(4, 32), Pair(-47, 37), Pair(-15, 46), Pair(9, 35),
        Pair(14, -25), Pair(-25, -13), Pair(-57, 16), Pair(-53, 10), Pair(-24, 10), Pair(-42, 79), Pair(-31, 13), Pair(-3, -26),
        Pair(-37, -1), Pair(13, 45), Pair(-12, -6), Pair(-78, 38), Pair(51, 22), Pair(16, 30), Pair(8, -14), Pair(19, 45),
        Pair(-17, 17), Pair(-4, 33), Pair(27, -30), Pair(12, 37), Pair(-2, -15), Pair(-48, -40), Pair(12, 29), Pair(-16, 0),
        Pair(9, 32), Pair(-34, -34), Pair(-44, -18), Pair(60, 32), Pair(62, -25), Pair(-28, -26), Pair(-32, -110), Pair(-20, 76),
        Pair(5, 43), Pair(-5, 83), Pair(-26, 0), Pair(-22, 7), Pair(-70, 21), Pair(26, -2), Pair(-31, -44), Pair(-13, 5)
      },
      { // Piece 3
        Pair(-58, -20), Pair(17, -15), Pair(-9, 5), Pair(-36, 25), Pair(-34, 2), Pair(6, 5), Pair(15, 7), Pair(0, 5),
        Pair(20, -17), Pair(-47, -44), Pair(9, -14), Pair(-27, -15), Pair(4, -21), Pair(75, -18), Pair(23, -11), Pair(-17, -46),
        Pair(35, -15), Pair(30, -45), Pair(6, -14), Pair(39, -26), Pair(-9, -23), Pair(-16, -18), Pair(49, -15), Pair(94, -38),
        Pair(22, -1), Pair(-43, 4), Pair(24, -10), Pair(4, -25), Pair(5, -22), Pair(64, -18), Pair(11, -15), Pair(26, -29),
        Pair(-63, -44), Pair(-6, -31), Pair(61, -4), Pair(60, -11), Pair(59, -35), Pair(39, -33), Pair(4, -46), Pair(21, -44),
        Pair(12, -48), Pair(-13, 0), Pair(39, -90), Pair(59, -66), Pair(46, -45), Pair(52, -52), Pair(35, -44), Pair(52, -66),
        Pair(19, -39), Pair(-39, -37), Pair(50, -90), Pair(-21, -20), Pair(76, -59), Pair(1, -3), Pair(52, 0), Pair(0, -71),
        Pair(-14, -8), Pair(18, -54), Pair(11, -74), Pair(14, -87), Pair(19, -50), Pair(68, -83), Pair(13, -43), Pair(62, -9)
      },
      { // Piece 4
        Pair(-114, -75), Pair(-79, -118), Pair(-34, -59), Pair(-11, -57), Pair(-70, -105), Pair(-46, -37), Pair(-80, -81), Pair(-13, -46),
        Pair(-37, -59), Pair(-3, -2), Pair(-3, 36), Pair(-43, -80), Pair(-6, 17), Pair(-24, -87), Pair(12, -112), Pair(-34, -63),
        Pair(-5, -37), Pair(-45, -36), Pair(-21, -23), Pair(-24, -15), Pair(6, -60), Pair(-42, -164), Pair(-18, -44), Pair(30, 10),
        Pair(-44, -80), Pair(-28, -41), Pair(31, -19), Pair(48, -67), Pair(-5, -57), Pair(3, -33), Pair(-4, -26), Pair(-30, -65),
        Pair(28, -35), Pair(20, -38), Pair(60, 3), Pair(-4, 4), Pair(18, 21), Pair(24, -51), Pair(5, -31), Pair(-12, -37),
        Pair(-50, -146), Pair(16, -49), Pair(0, -30), Pair(-7, -53), Pair(-52, -128), Pair(-34, -90), Pair(-31, -48), Pair(27, 42),
        Pair(-67, -136), Pair(-10, -28), Pair(21, 12), Pair(22, -25), Pair(-7, -70), Pair(10, -1), Pair(-37, -56), Pair(-38, -77),
        Pair(8, -49), Pair(-57, -151), Pair(34, -27), Pair(-37, -113), Pair(-3, -58), Pair(0, -37), Pair(18, -25), Pair(-57, -107)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-28, 15), Pair(-40, 42), Pair(-40, 41), Pair(69, 31), Pair(-8, 43), Pair(-84, 61), Pair(-28, 38), Pair(-36, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 3
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(54, 0), Pair(35, 12), Pair(-90, 105), Pair(11, 20), Pair(59, -40), Pair(14, -60), Pair(-40, -85), Pair(-156, -68),
        Pair(10, 52), Pair(-27, 83), Pair(14, 65), Pair(21, 14), Pair(39, 7), Pair(117, -23), Pair(29, 13), Pair(21, 1),
        Pair(-27, 41), Pair(-31, 39), Pair(-16, 24), Pair(6, -7), Pair(54, -29), Pair(35, -22), Pair(7, 7), Pair(-18, 6),
        Pair(-29, 17), Pair(-35, 35), Pair(-9, 3), Pair(9, -13), Pair(12, -16), Pair(24, -14), Pair(-12, 5), Pair(-42, -3),
        Pair(-25, 2), Pair(-38, 18), Pair(-12, -2), Pair(0, -8), Pair(-6, 0), Pair(21, -16), Pair(13, -7), Pair(-44, -11),
        Pair(-27, 12), Pair(-32, 24), Pair(-12, 7), Pair(-22, 14), Pair(-5, 19), Pair(18, -6), Pair(2, 2), Pair(-42, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-256, 21), Pair(-91, -43), Pair(-54, 43), Pair(74, -8), Pair(-62, 33), Pair(89, -63), Pair(-21, -3), Pair(-21, -56),
        Pair(-113, 42), Pair(11, 23), Pair(-72, 26), Pair(12, 48), Pair(-2, 45), Pair(33, 22), Pair(-66, 61), Pair(8, 2),
        Pair(-38, 4), Pair(4, 20), Pair(13, 37), Pair(53, 21), Pair(64, 14), Pair(93, 2), Pair(2, 24), Pair(69, -37),
        Pair(-80, 52), Pair(-10, 20), Pair(44, 33), Pair(53, 29), Pair(87, 25), Pair(91, 18), Pair(57, 33), Pair(87, -4),
        Pair(-19, 16), Pair(6, 35), Pair(-15, 58), Pair(26, 50), Pair(57, 34), Pair(49, 28), Pair(50, 8), Pair(21, 14),
        Pair(-53, -23), Pair(-48, 31), Pair(-8, 19), Pair(20, 32), Pair(35, 30), Pair(25, 15), Pair(-3, 26), Pair(-40, 20),
        Pair(-148, 33), Pair(-40, 34), Pair(-45, 16), Pair(-17, 33), Pair(-17, 22), Pair(46, -13), Pair(-31, 7), Pair(3, 5),
        Pair(-107, 17), Pair(-76, -10), Pair(-144, 37), Pair(-89, 43), Pair(-7, 16), Pair(-73, 20), Pair(-98, 18), Pair(70, -73)
      },
      { // Piece 2
        Pair(-118, 69), Pair(-82, 49), Pair(-31, -15), Pair(-55, 21), Pair(-77, 3), Pair(-37, -6), Pair(27, 21), Pair(36, 30),
        Pair(-54, 17), Pair(-20, 36), Pair(-50, 33), Pair(5, -15), Pair(-28, 35), Pair(79, -43), Pair(-138, 93), Pair(-85, 50),
        Pair(4, 16), Pair(-13, 18), Pair(5, 26), Pair(14, 23), Pair(8, 29), Pair(31, 49), Pair(-18, 30), Pair(68, 11),
        Pair(-36, 26), Pair(-6, 17), Pair(-12, 28), Pair(20, 21), Pair(26, 26), Pair(41, 11), Pair(-14, 34), Pair(-16, 44),
        Pair(-54, 9), Pair(-6, 17), Pair(20, 32), Pair(3, 29), Pair(13, 20), Pair(14, 23), Pair(-14, 18), Pair(4, 13),
        Pair(-46, 2), Pair(-19, 30), Pair(-32, 26), Pair(12, 18), Pair(-1, 26), Pair(3, 11), Pair(13, 12), Pair(-26, 5),
        Pair(50, 9), Pair(-24, 8), Pair(-41, 35), Pair(-14, 22), Pair(4, 13), Pair(-2, -4), Pair(5, 2), Pair(-69, 24),
        Pair(-32, 23), Pair(12, 9), Pair(-17, 14), Pair(-15, 11), Pair(-23, 25), Pair(-21, 15), Pair(-55, 9), Pair(-94, 15)
      },
      { // Piece 3
        Pair(37, 45), Pair(-55, 94), Pair(2, 84), Pair(-10, 66), Pair(68, 49), Pair(98, -15), Pair(14, 70), Pair(72, 96),
        Pair(-15, 53), Pair(-12, 67), Pair(-21, 69), Pair(56, 38), Pair(33, 36), Pair(126, 16), Pair(11, 78), Pair(66, 32),
        Pair(-46, 52), Pair(-1, 44), Pair(26, 42), Pair(13, 43), Pair(43, 27), Pair(39, 34), Pair(73, 23), Pair(8, 31),
        Pair(-68, 50), Pair(-5, 49), Pair(-1, 44), Pair(4, 38), Pair(18, 31), Pair(-14, 47), Pair(30, 28), Pair(-1, 14),
        Pair(-89, 46), Pair(-79, 65), Pair(-2, 27), Pair(-43, 53), Pair(-21, 30), Pair(-31, 41), Pair(-62, 55), Pair(-36, 21),
        Pair(-60, 38), Pair(-91, 52), Pair(-39, 31), Pair(-19, 23), Pair(-29, 14), Pair(-6, 8), Pair(10, 2), Pair(-98, 23),
        Pair(-89, 23), Pair(-40, 22), Pair(-73, 52), Pair(-41, 26), Pair(-57, 35), Pair(-16, 3), Pair(-42, 13), Pair(-90, 15),
        Pair(-60, 30), Pair(-59, 27), Pair(-56, 38), Pair(-38, 27), Pair(-45, 26), Pair(-30, 14), Pair(-20, -4), Pair(-50, 11)
      },
      { // Piece 4
        Pair(-52, 52), Pair(-58, 45), Pair(67, 13), Pair(0, 35), Pair(-37, 85), Pair(119, 88), Pair(66, 81), Pair(-24, -25),
        Pair(-157, 100), Pair(-88, 33), Pair(-80, 81), Pair(-79, 100), Pair(-50, 80), Pair(89, 3), Pair(-39, 69), Pair(84, 37),
        Pair(-102, 76), Pair(-99, 60), Pair(-47, 32), Pair(-77, 91), Pair(-26, 82), Pair(43, 30), Pair(78, -6), Pair(46, -33),
        Pair(-146, 75), Pair(-94, 67), Pair(-95, 84), Pair(-100, 102), Pair(-41, 81), Pair(9, 44), Pair(3, 34), Pair(-38, 28),
        Pair(-83, 12), Pair(-94, 76), Pair(-45, 64), Pair(-50, 70), Pair(-33, 62), Pair(-13, 50), Pair(16, -17), Pair(-26, -8),
        Pair(-149, 95), Pair(-74, 42), Pair(-39, 10), Pair(-52, 30), Pair(-66, 66), Pair(-45, 43), Pair(49, -119), Pair(-52, -19),
        Pair(-43, -76), Pair(-62, -10), Pair(-54, -30), Pair(-50, 5), Pair(-42, 12), Pair(-31, -52), Pair(-4, -90), Pair(-31, -68),
        Pair(-135, 31), Pair(-102, -24), Pair(-85, 19), Pair(-44, -40), Pair(-59, -7), Pair(-61, -37), Pair(-86, 53), Pair(-44, -47)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, -37), Pair(45, -23), Pair(-3, 11), Pair(-47, 35), Pair(-51, 30), Pair(-32, 11), Pair(11, -20), Pair(-6, -43),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 90), Pair(-43, 48), Pair(25, -55), Pair(96, -112), Pair(45, -116), Pair(-1, -99), Pair(0, 64), Pair(-58, 80),
        Pair(1, 64), Pair(44, 30), Pair(131, -35), Pair(123, -58), Pair(113, -72), Pair(129, -23), Pair(119, 9), Pair(-14, 43),
        Pair(19, 26), Pair(-40, 36), Pair(-9, -4), Pair(23, -15), Pair(29, -17), Pair(38, -14), Pair(26, 6), Pair(-27, 9),
        Pair(-55, 22), Pair(-60, 29), Pair(-12, -10), Pair(-5, -8), Pair(16, -20), Pair(24, -14), Pair(-4, 8), Pair(-41, -3),
        Pair(-70, 17), Pair(-43, 19), Pair(-9, -7), Pair(-6, 2), Pair(6, -5), Pair(15, -13), Pair(3, -6), Pair(-32, -11),
        Pair(-73, 31), Pair(-34, 21), Pair(4, -9), Pair(-47, -6), Pair(-48, 16), Pair(7, -4), Pair(-24, 4), Pair(-31, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-236, -40), Pair(0, 23), Pair(-57, 29), Pair(-89, 24), Pair(-10, 19), Pair(-37, -20), Pair(-6, -73), Pair(-114, -68),
        Pair(-11, -10), Pair(-74, 31), Pair(19, 2), Pair(27, -31), Pair(78, -26), Pair(3, 12), Pair(53, 15), Pair(-45, -7),
        Pair(-15, -4), Pair(64, 6), Pair(43, 31), Pair(2, 36), Pair(1, 21), Pair(113, -11), Pair(31, -26), Pair(27, -34),
        Pair(28, 21), Pair(49, 19), Pair(52, 34), Pair(83, 33), Pair(96, 20), Pair(81, 48), Pair(74, 8), Pair(30, -9),
        Pair(-73, 45), Pair(-16, 78), Pair(10, 45), Pair(30, 47), Pair(28, 51), Pair(26, 43), Pair(133, -17), Pair(16, 14),
        Pair(-88, 13), Pair(-7, 11), Pair(13, 20), Pair(55, 25), Pair(70, 33), Pair(8, 21), Pair(-11, 15), Pair(43, -47),
        Pair(-158, 29), Pair(-14, 36), Pair(-15, 15), Pair(-11, 15), Pair(-23, 34), Pair(29, -7), Pair(40, -47), Pair(-40, 16),
        Pair(-24, -29), Pair(-39, 23), Pair(-39, 27), Pair(-65, 12), Pair(-65, 7), Pair(18, -7), Pair(-30, -4), Pair(-82, 101)
      },
      { // Piece 2
        Pair(-39, 4), Pair(-74, -4), Pair(-33, -17), Pair(-59, 3), Pair(27, -4), Pair(-39, 3), Pair(-20, -12), Pair(-124, -1),
        Pair(-28, 7), Pair(89, -5), Pair(-102, 29), Pair(99, 7), Pair(-29, -13), Pair(21, -18), Pair(-2, 35), Pair(-63, 27),
        Pair(-22, 29), Pair(-65, 4), Pair(-21, 10), Pair(24, 0), Pair(76, -10), Pair(-33, 45), Pair(80, -19), Pair(45, -10),
        Pair(2, 7), Pair(28, 13), Pair(24, 16), Pair(46, -1), Pair(69, -3), Pair(52, 1), Pair(20, 7), Pair(1, -3),
        Pair(32, -15), Pair(3, -1), Pair(-28, 18), Pair(64, -5), Pair(47, -6), Pair(36, 1), Pair(3, 16), Pair(-37, -3),
        Pair(25, 6), Pair(-4, 1), Pair(-31, 30), Pair(6, 9), Pair(31, 1), Pair(-14, 20), Pair(-2, 18), Pair(49, -36),
        Pair(-60, 27), Pair(-3, 6), Pair(-10, 2), Pair(-21, 24), Pair(-39, 25), Pair(-42, 12), Pair(-13, 12), Pair(61, -22),
        Pair(22, -22), Pair(44, -9), Pair(-30, 34), Pair(16, 4), Pair(-7, -7), Pair(-26, 24), Pair(-97, -19), Pair(-9, 32)
      },
      { // Piece 3
        Pair(62, 16), Pair(70, 34), Pair(29, 49), Pair(76, 24), Pair(42, 26), Pair(27, 12), Pair(50, 54), Pair(64, -1),
        Pair(63, 25), Pair(34, 37), Pair(86, 25), Pair(108, 3), Pair(83, 3), Pair(53, 23), Pair(41, 44), Pair(2, 45),
        Pair(14, 28), Pair(13, 28), Pair(19, 34), Pair(12, 30), Pair(40, 9), Pair(103, -2), Pair(33, 6), Pair(-34, 36),
        Pair(-84, 52), Pair(-103, 68), Pair(-21, 51), Pair(-40, 45), Pair(58, 2), Pair(38, 13), Pair(-73, 47), Pair(-16, 17),
        Pair(-67, 28), Pair(-93, 65), Pair(13, 27), Pair(-82, 48), Pair(-12, 23), Pair(-5, 10), Pair(-16, 23), Pair(-68, 31),
        Pair(-46, 9), Pair(-106, 43), Pair(7, -1), Pair(-95, 30), Pair(-24, 13), Pair(-85, 43), Pair(-57, 11), Pair(4, -16),
        Pair(-55, 3), Pair(-125, 53), Pair(-20, -4), Pair(-109, 43), Pair(-46, -1), Pair(-46, 0), Pair(-10, -17), Pair(-105, 42),
        Pair(-43, -2), Pair(-39, 7), Pair(-26, 11), Pair(-51, 17), Pair(-22, -2), Pair(-32, 4), Pair(-64, 23), Pair(-40, 3)
      },
      { // Piece 4
        Pair(-46, 53), Pair(20, 7), Pair(82, 120), Pair(26, 51), Pair(55, 58), Pair(44, 19), Pair(-4, -44), Pair(59, 39),
        Pair(-36, -16), Pair(-8, -22), Pair(56, -19), Pair(66, 24), Pair(36, 102), Pair(35, -15), Pair(-22, -20), Pair(56, -59),
        Pair(4, -27), Pair(65, -39), Pair(19, -11), Pair(-12, 41), Pair(15, 44), Pair(36, 18), Pair(-33, 8), Pair(79, -70),
        Pair(20, -17), Pair(-14, 36), Pair(0, 8), Pair(-22, 46), Pair(64, -3), Pair(39, 20), Pair(10, -1), Pair(-23, -31),
        Pair(-37, -77), Pair(18, -40), Pair(-96, 100), Pair(-58, 71), Pair(-33, 78), Pair(-10, -30), Pair(-41, 25), Pair(-142, 55),
        Pair(-57, -86), Pair(-38, -1), Pair(-48, 44), Pair(-93, 34), Pair(-23, 35), Pair(-16, -41), Pair(3, -55), Pair(-2, -21),
        Pair(-135, -78), Pair(-43, -88), Pair(-60, 4), Pair(-12, -54), Pair(-61, 29), Pair(-80, 8), Pair(-2, -83), Pair(-99, -101),
        Pair(-177, -92), Pair(-65, 39), Pair(-59, -19), Pair(-36, -46), Pair(-46, -65), Pair(5, -105), Pair(16, -20), Pair(-53, 2)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(16, -38), Pair(25, -24), Pair(-1, 1), Pair(-25, 17), Pair(-17, 12), Pair(-17, -1), Pair(25, -30), Pair(15, -51),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(59, -30), Pair(83, -55), Pair(78, -63), Pair(54, -75), Pair(80, -68), Pair(76, -101), Pair(24, -29), Pair(109, -49),
        Pair(-18, 43), Pair(21, 37), Pair(100, -16), Pair(76, -28), Pair(77, -44), Pair(125, -34), Pair(31, 3), Pair(43, 8),
        Pair(-21, 28), Pair(-20, 30), Pair(3, 3), Pair(2, -10), Pair(9, -6), Pair(18, -7), Pair(-4, 12), Pair(-14, 6),
        Pair(-50, 22), Pair(-44, 31), Pair(-13, 0), Pair(2, -4), Pair(10, -5), Pair(10, -10), Pair(-16, 12), Pair(-38, 0),
        Pair(-51, 9), Pair(-39, 15), Pair(-9, -2), Pair(9, -3), Pair(7, -2), Pair(12, -10), Pair(6, -1), Pair(-43, -5),
        Pair(-60, 25), Pair(-37, 23), Pair(-15, 6), Pair(-33, 6), Pair(13, 7), Pair(19, -8), Pair(-8, 10), Pair(-39, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-65, -76), Pair(-34, -40), Pair(-54, -6), Pair(74, -40), Pair(-70, 6), Pair(-4, 1), Pair(18, -48), Pair(-74, -89),
        Pair(-32, -18), Pair(-53, 29), Pair(-24, 20), Pair(44, 13), Pair(10, 24), Pair(-26, 19), Pair(-58, 42), Pair(-12, 5),
        Pair(-23, -1), Pair(-15, 16), Pair(45, 22), Pair(76, 10), Pair(116, -7), Pair(85, -8), Pair(74, -12), Pair(41, -21),
        Pair(-3, 16), Pair(38, 21), Pair(41, 39), Pair(91, 16), Pair(86, 27), Pair(47, 25), Pair(97, -5), Pair(69, -8),
        Pair(-19, 21), Pair(35, 15), Pair(48, 33), Pair(74, 35), Pair(64, 35), Pair(119, 8), Pair(110, -5), Pair(27, -1),
        Pair(-3, -9), Pair(-24, 23), Pair(12, 24), Pair(51, 28), Pair(36, 28), Pair(16, 20), Pair(25, 14), Pair(-66, 31),
        Pair(-27, 22), Pair(-65, 36), Pair(-12, 21), Pair(5, 28), Pair(4, 23), Pair(16, 20), Pair(8, 25), Pair(69, -12),
        Pair(30, -50), Pair(-155, 30), Pair(-27, 24), Pair(-59, 29), Pair(-90, 32), Pair(-62, 9), Pair(-75, 4), Pair(-93, 40)
      },
      { // Piece 2
        Pair(-42, 14), Pair(2, 9), Pair(18, 16), Pair(-11, 11), Pair(-50, 10), Pair(-69, -8), Pair(-40, 2), Pair(-32, 4),
        Pair(-113, 9), Pair(-48, 18), Pair(-1, -3), Pair(-77, 20), Pair(-54, 5), Pair(15, 1), Pair(7, -7), Pair(-68, 5),
        Pair(-26, 15), Pair(22, -3), Pair(2, 4), Pair(35, -7), Pair(20, 12), Pair(51, -11), Pair(11, -9), Pair(1, 2),
        Pair(4, 3), Pair(47, -10), Pair(66, -10), Pair(68, -8), Pair(77, 0), Pair(66, 4), Pair(72, -5), Pair(73, -21),
        Pair(-88, 20), Pair(47, -6), Pair(0, 6), Pair(52, -1), Pair(49, -4), Pair(39, 3), Pair(23, 0), Pair(28, -9),
        Pair(-9, 2), Pair(14, -2), Pair(29, -1), Pair(24, 1), Pair(13, 10), Pair(19, 2), Pair(16, 1), Pair(-12, -3),
        Pair(-99, 25), Pair(-11, 3), Pair(27, -4), Pair(10, 3), Pair(11, 0), Pair(10, -10), Pair(7, -9), Pair(5, -20),
        Pair(-92, 21), Pair(-75, 33), Pair(-41, 14), Pair(-19, -4), Pair(3, -2), Pair(23, -11), Pair(7, -6), Pair(-63, 11)
      },
      { // Piece 3
        Pair(-45, 50), Pair(-51, 54), Pair(-24, 46), Pair(-74, 55), Pair(-5, 20), Pair(86, 9), Pair(43, 17), Pair(-36, 48),
        Pair(39, 17), Pair(19, 27), Pair(-33, 48), Pair(60, 20), Pair(99, -12), Pair(-69, 37), Pair(-11, 26), Pair(-53, 27),
        Pair(-4, 24), Pair(34, 14), Pair(45, 10), Pair(45, 7), Pair(36, 7), Pair(89, 1), Pair(-20, 28), Pair(-19, 23),
        Pair(-67, 35), Pair(22, 20), Pair(-16, 33), Pair(72, 7), Pair(-8, 19), Pair(45, 1), Pair(1, 18), Pair(-24, 16),
        Pair(-61, 18), Pair(-50, 31), Pair(-41, 20), Pair(-46, 25), Pair(-27, 20), Pair(-33, 15), Pair(-48, 17), Pair(-20, -4),
        Pair(-86, 8), Pair(-64, 24), Pair(-39, 7), Pair(-64, 16), Pair(-41, 6), Pair(-59, 19), Pair(-5, -8), Pair(-94, 4),
        Pair(-94, 14), Pair(-76, 16), Pair(-59, 5), Pair(-61, 8), Pair(-70, 13), Pair(-17, -11), Pair(-72, 4), Pair(-96, 13),
        Pair(-65, 12), Pair(-61, 18), Pair(-62, 15), Pair(-67, 20), Pair(-62, 10), Pair(-43, 4), Pair(-47, 3), Pair(-64, 3)
      },
      { // Piece 4
        Pair(-34, -25), Pair(-97, 7), Pair(-100, 52), Pair(-48, 10), Pair(-107, 50), Pair(78, -11), Pair(4, -24), Pair(-32, -1),
        Pair(-57, 0), Pair(-107, 44), Pair(-106, 35), Pair(-91, 89), Pair(24, 9), Pair(14, 21), Pair(-11, 31), Pair(39, -31),
        Pair(-46, -22), Pair(-107, 18), Pair(64, -68), Pair(-56, 31), Pair(-9, 28), Pair(45, -15), Pair(-89, 10), Pair(-32, -19),
        Pair(-8, -50), Pair(-72, 19), Pair(-13, -3), Pair(-46, 63), Pair(41, 12), Pair(-48, 77), Pair(119, -63), Pair(18, -21),
        Pair(-66, -10), Pair(-94, 36), Pair(9, -3), Pair(6, 13), Pair(-41, 58), Pair(-19, 25), Pair(-36, 10), Pair(-9, 15),
        Pair(-84, -64), Pair(-27, -35), Pair(-57, 25), Pair(9, -26), Pair(-76, 29), Pair(-23, -4), Pair(-43, -30), Pair(-1, -73),
        Pair(-42, -103), Pair(-48, -1), Pair(-20, -20), Pair(-38, -20), Pair(-58, 15), Pair(-44, -20), Pair(-16, -37), Pair(-95, -2),
        Pair(12, -110), Pair(-69, -14), Pair(-39, -27), Pair(-67, -7), Pair(-82, 8), Pair(-107, 35), Pair(-52, 6), Pair(-65, -36)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(60, -53), Pair(44, -22), Pair(16, 0), Pair(-17, 23), Pair(-16, 17), Pair(-24, 7), Pair(4, -15), Pair(-25, -35),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, -27), Pair(175, -63), Pair(68, -45), Pair(118, -85), Pair(33, -78), Pair(21, -83), Pair(110, -24), Pair(25, -13),
        Pair(-30, 35), Pair(14, 27), Pair(70, -15), Pair(42, -31), Pair(8, -19), Pair(105, -28), Pair(16, 14), Pair(20, 10),
        Pair(-42, 26), Pair(-46, 29), Pair(-9, -1), Pair(-27, -5), Pair(5, -8), Pair(10, -6), Pair(-9, 19), Pair(-58, 19),
        Pair(-80, 23), Pair(-55, 33), Pair(-61, 12), Pair(-48, 17), Pair(-38, 17), Pair(-18, 8), Pair(-47, 25), Pair(-67, 9),
        Pair(-95, 18), Pair(-76, 22), Pair(-39, 5), Pair(-43, 7), Pair(-21, 8), Pair(-15, -2), Pair(-42, 10), Pair(-89, 10),
        Pair(-97, 30), Pair(-70, 30), Pair(-32, 11), Pair(8, -11), Pair(-20, 11), Pair(-5, 5), Pair(-41, 20), Pair(-88, 22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-51, -121), Pair(-53, -10), Pair(-102, 12), Pair(-66, 16), Pair(1, -28), Pair(-77, 21), Pair(17, -28), Pair(-35, -103),
        Pair(-25, -7), Pair(-28, -1), Pair(-4, -8), Pair(33, 4), Pair(50, -17), Pair(-37, -6), Pair(-59, 5), Pair(-78, -15),
        Pair(-25, -28), Pair(-21, -10), Pair(-30, 19), Pair(32, 19), Pair(76, -4), Pair(42, -2), Pair(21, -18), Pair(23, -24),
        Pair(64, -9), Pair(14, -4), Pair(58, 11), Pair(62, 12), Pair(109, 1), Pair(79, 16), Pair(83, -4), Pair(109, -21),
        Pair(20, 11), Pair(82, 2), Pair(28, 24), Pair(81, 13), Pair(57, 23), Pair(52, 13), Pair(42, 11), Pair(60, -3),
        Pair(-37, -18), Pair(-29, 20), Pair(18, 10), Pair(46, 21), Pair(8, 28), Pair(26, 7), Pair(43, -12), Pair(-29, 29),
        Pair(-62, 8), Pair(-48, 31), Pair(-72, 16), Pair(15, 15), Pair(41, 3), Pair(-33, 12), Pair(-27, 29), Pair(-61, 38),
        Pair(24, -7), Pair(-209, 16), Pair(-73, 10), Pair(-47, 2), Pair(3, 3), Pair(5, 3), Pair(-29, -5), Pair(-59, 32)
      },
      { // Piece 2
        Pair(-13, -13), Pair(-91, 15), Pair(-31, -8), Pair(-36, -6), Pair(-41, -7), Pair(-89, 14), Pair(2, -14), Pair(-53, -39),
        Pair(-77, -14), Pair(12, -4), Pair(2, -3), Pair(21, -18), Pair(-79, -2), Pair(-100, 12), Pair(-32, 1), Pair(-42, -10),
        Pair(53, -16), Pair(11, -6), Pair(1, -10), Pair(0, -5), Pair(73, -21), Pair(-11, -8), Pair(74, -11), Pair(-6, -18),
        Pair(-81, 12), Pair(68, -23), Pair(21, -4), Pair(103, -23), Pair(34, -6), Pair(35, -14), Pair(34, -12), Pair(-25, -11),
        Pair(-39, 1), Pair(11, -5), Pair(84, -26), Pair(56, -6), Pair(64, -11), Pair(64, -9), Pair(56, -17), Pair(-10, -23),
        Pair(-23, 7), Pair(-37, 4), Pair(21, -7), Pair(-17, 2), Pair(-1, 0), Pair(27, -12), Pair(7, -12), Pair(-104, 32),
        Pair(-89, 32), Pair(-79, 11), Pair(9, -6), Pair(-9, -5), Pair(9, -9), Pair(-50, 5), Pair(-26, -14), Pair(59, -30),
        Pair(-80, 1), Pair(-8, 19), Pair(-55, 5), Pair(-29, -1), Pair(-37, -4), Pair(-48, 4), Pair(-12, -12), Pair(-45, 1)
      },
      { // Piece 3
        Pair(-13, 16), Pair(-40, 25), Pair(8, 11), Pair(0, 11), Pair(-12, 8), Pair(-4, 13), Pair(-19, 10), Pair(25, 4),
        Pair(2, -12), Pair(-15, 7), Pair(33, -9), Pair(72, -23), Pair(29, -9), Pair(43, -12), Pair(93, -32), Pair(24, -15),
        Pair(-19, 2), Pair(10, 0), Pair(16, -1), Pair(-25, -8), Pair(22, -24), Pair(21, 1), Pair(-5, 1), Pair(-167, 37),
        Pair(-24, 6), Pair(59, -16), Pair(54, -10), Pair(60, -15), Pair(95, -29), Pair(37, -19), Pair(46, -18), Pair(14, -12),
        Pair(-69, 4), Pair(-83, 19), Pair(6, -1), Pair(12, -5), Pair(-13, -1), Pair(4, -12), Pair(-2, 2), Pair(-40, -7),
        Pair(-100, -8), Pair(-42, -12), Pair(-64, -11), Pair(-44, -17), Pair(-14, -25), Pair(-28, -11), Pair(60, -49), Pair(-134, 4),
        Pair(-140, 0), Pair(-16, -27), Pair(-5, -31), Pair(-32, -23), Pair(-55, -13), Pair(-37, -28), Pair(-66, -20), Pair(-119, 0),
        Pair(-85, -8), Pair(-68, -3), Pair(-60, -6), Pair(-43, -13), Pair(-42, -21), Pair(-29, -20), Pair(-67, -6), Pair(-87, -5)
      },
      { // Piece 4
        Pair(-5, -7), Pair(30, -37), Pair(-13, -44), Pair(111, -57), Pair(-7, -15), Pair(-28, 9), Pair(9, -6), Pair(13, -29),
        Pair(56, -126), Pair(-88, -26), Pair(-138, 55), Pair(-19, -51), Pair(32, -10), Pair(-58, 51), Pair(133, -144), Pair(-101, -18),
        Pair(-41, -47), Pair(-53, 16), Pair(52, -27), Pair(-42, -11), Pair(78, -43), Pair(63, 19), Pair(6, 6), Pair(-28, -28),
        Pair(-1, -50), Pair(-57, -25), Pair(-29, -18), Pair(25, -43), Pair(-39, -9), Pair(88, -79), Pair(43, -80), Pair(65, -50),
        Pair(-49, -75), Pair(-72, 7), Pair(-51, 1), Pair(33, -22), Pair(-10, 13), Pair(13, -34), Pair(-19, -71), Pair(-81, 44),
        Pair(-92, -77), Pair(22, -65), Pair(-76, -18), Pair(31, -66), Pair(-5, -24), Pair(25, -54), Pair(19, -78), Pair(-81, -32),
        Pair(-74, -4), Pair(-73, -66), Pair(6, -32), Pair(-12, -58), Pair(-29, -52), Pair(-35, 18), Pair(-10, -56), Pair(-78, -102),
        Pair(-63, -113), Pair(-122, -62), Pair(-80, 56), Pair(33, -95), Pair(-82, -83), Pair(20, -18), Pair(-20, -58), Pair(-43, -52)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, -32), Pair(49, -10), Pair(4, 11), Pair(-15, 27), Pair(2, 20), Pair(12, 9), Pair(29, -10), Pair(-30, -24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-29, -14), Pair(80, -47), Pair(-29, -23), Pair(-101, -18), Pair(-36, 0), Pair(40, -5), Pair(-92, 68), Pair(-199, 10),
        Pair(-116, 51), Pair(-63, 47), Pair(-18, 24), Pair(-70, 24), Pair(-47, 25), Pair(5, 7), Pair(4, 48), Pair(-73, 43),
        Pair(-94, 33), Pair(-85, 37), Pair(-62, 10), Pair(-61, 8), Pair(-36, 7), Pair(-28, -1), Pair(3, 20), Pair(-62, 21),
        Pair(-132, 27), Pair(-94, 34), Pair(-75, 12), Pair(-64, 15), Pair(-31, 13), Pair(-9, 3), Pair(-41, 24), Pair(-80, 18),
        Pair(-119, 22), Pair(-103, 30), Pair(-79, 20), Pair(-62, 23), Pair(-61, 26), Pair(-28, 12), Pair(-79, 24), Pair(-98, 16),
        Pair(-157, 42), Pair(-110, 35), Pair(-49, 15), Pair(18, -6), Pair(31, 6), Pair(-16, 10), Pair(-75, 30), Pair(-102, 28),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-36, -154), Pair(-29, -12), Pair(-68, -16), Pair(-20, -32), Pair(-69, 8), Pair(-31, -4), Pair(-30, -4), Pair(1, -54),
        Pair(-92, -34), Pair(43, -20), Pair(-22, 2), Pair(41, -7), Pair(64, 0), Pair(69, -29), Pair(-27, -11), Pair(20, -38),
        Pair(-45, -39), Pair(-96, 5), Pair(-76, 15), Pair(68, -3), Pair(-21, -2), Pair(-59, 0), Pair(-11, -6), Pair(-21, -19),
        Pair(-75, 12), Pair(-17, 16), Pair(69, -1), Pair(69, -1), Pair(84, 1), Pair(90, 0), Pair(49, -15), Pair(35, -3),
        Pair(21, -17), Pair(36, -1), Pair(18, 9), Pair(60, 7), Pair(62, -2), Pair(87, -9), Pair(94, -18), Pair(-23, -10),
        Pair(-14, -31), Pair(-57, 0), Pair(-3, 2), Pair(43, 4), Pair(55, 11), Pair(38, -3), Pair(-30, 3), Pair(-94, -14),
        Pair(-3, -35), Pair(-67, 6), Pair(-25, 1), Pair(-17, 7), Pair(-30, 3), Pair(0, -6), Pair(-18, 2), Pair(-13, -20),
        Pair(-20, 10), Pair(-100, 19), Pair(-82, 16), Pair(-71, -3), Pair(-35, 8), Pair(-70, -3), Pair(-71, 3), Pair(17, -9)
      },
      { // Piece 2
        Pair(-6, -27), Pair(-16, 1), Pair(-71, -5), Pair(16, -15), Pair(43, -5), Pair(-82, 3), Pair(-20, -15), Pair(42, 1),
        Pair(-38, -13), Pair(-60, -9), Pair(-93, 1), Pair(-102, 3), Pair(-128, -2), Pair(-68, 3), Pair(-72, -5), Pair(-35, -13),
        Pair(26, -12), Pair(-1, -13), Pair(-34, 2), Pair(-41, -1), Pair(-10, -7), Pair(54, -4), Pair(-46, 2), Pair(-158, 6),
        Pair(-23, 6), Pair(-21, 1), Pair(-15, -11), Pair(38, -15), Pair(84, -13), Pair(-31, -8), Pair(58, -16), Pair(-47, 0),
        Pair(-92, -3), Pair(50, -31), Pair(-74, -8), Pair(38, -9), Pair(-2, -14), Pair(-43, 2), Pair(-82, -3), Pair(-46, -20),
        Pair(11, -18), Pair(-41, -2), Pair(-46, -9), Pair(-59, -2), Pair(19, -8), Pair(-21, -8), Pair(-57, -7), Pair(40, -11),
        Pair(-65, 14), Pair(-88, -6), Pair(-93, 8), Pair(-25, -4), Pair(-23, -15), Pair(-31, -5), Pair(-69, -11), Pair(-22, -25),
        Pair(-83, 13), Pair(-95, 32), Pair(-13, -12), Pair(-113, 6), Pair(5, -8), Pair(-141, 16), Pair(-104, 9), Pair(8, -49)
      },
      { // Piece 3
        Pair(-36, -5), Pair(-65, 9), Pair(-3, 0), Pair(43, -14), Pair(-23, 0), Pair(-17, 2), Pair(120, -32), Pair(-11, -12),
        Pair(-41, -23), Pair(-16, -24), Pair(-29, -9), Pair(37, -26), Pair(-34, -11), Pair(57, -35), Pair(-5, -23), Pair(14, -36),
        Pair(-65, -3), Pair(3, -18), Pair(86, -44), Pair(36, -28), Pair(46, -37), Pair(88, -43), Pair(1, -32), Pair(-24, -24),
        Pair(-93, -2), Pair(-35, -16), Pair(-31, 1), Pair(67, -52), Pair(89, -52), Pair(102, -50), Pair(69, -45), Pair(-45, -29),
        Pair(-61, -8), Pair(-30, -10), Pair(-60, 3), Pair(13, -18), Pair(-4, -25), Pair(2, -30), Pair(92, -36), Pair(-8, -24),
        Pair(-87, -29), Pair(10, -46), Pair(-143, -3), Pair(-36, -35), Pair(60, -54), Pair(-87, 2), Pair(30, -57), Pair(-35, -39),
        Pair(-51, -48), Pair(-77, -45), Pair(-90, -22), Pair(-75, -32), Pair(-45, -32), Pair(-6, -33), Pair(-46, -33), Pair(-68, -24),
        Pair(-142, -20), Pair(-30, -42), Pair(-54, -20), Pair(-50, -30), Pair(-39, -34), Pair(-50, -24), Pair(-137, 0), Pair(-67, -28)
      },
      { // Piece 4
        Pair(28, -64), Pair(33, -4), Pair(-51, -56), Pair(34, 24), Pair(-4, -11), Pair(-39, 60), Pair(68, -90), Pair(-48, -39),
        Pair(-61, -35), Pair(-20, -64), Pair(22, -32), Pair(26, -18), Pair(33, -19), Pair(0, -21), Pair(-41, -39), Pair(20, -66),
        Pair(-22, -20), Pair(41, -31), Pair(-5, -19), Pair(-6, -23), Pair(108, -41), Pair(-18, -73), Pair(80, -40), Pair(-34, -88),
        Pair(-22, -23), Pair(36, 34), Pair(-30, -68), Pair(69, 20), Pair(8, -57), Pair(41, 5), Pair(-13, -33), Pair(5, 27),
        Pair(-16, -31), Pair(-48, -64), Pair(72, 32), Pair(-8, 6), Pair(-28, 18), Pair(43, 0), Pair(-37, -75), Pair(-11, -4),
        Pair(-18, -84), Pair(5, -13), Pair(-25, 2), Pair(-39, 8), Pair(56, -9), Pair(61, -51), Pair(42, -6), Pair(65, 55),
        Pair(17, 12), Pair(-47, -37), Pair(-18, -108), Pair(9, -42), Pair(-15, -16), Pair(-8, -59), Pair(-47, -109), Pair(4, -36),
        Pair(-62, -104), Pair(-13, -79), Pair(-10, -75), Pair(12, 13), Pair(-103, -161), Pair(-5, -26), Pair(29, 20), Pair(-3, -26)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(59, -47), Pair(78, -17), Pair(2, 9), Pair(-29, 29), Pair(-21, 24), Pair(7, 12), Pair(-8, -3), Pair(0, -27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, -3), Pair(128, -34), Pair(-56, 9), Pair(-92, -11), Pair(-94, 13), Pair(-3, 6), Pair(-83, 51), Pair(13, -15),
        Pair(-177, 77), Pair(-104, 74), Pair(-113, 61), Pair(-89, 45), Pair(-131, 66), Pair(-37, 59), Pair(-77, 74), Pair(-38, 41),
        Pair(-76, 31), Pair(-16, 30), Pair(-3, 6), Pair(-67, 19), Pair(-136, 15), Pair(29, -12), Pair(-24, 14), Pair(-82, 22),
        Pair(-41, 5), Pair(-59, 23), Pair(-63, 7), Pair(-17, 7), Pair(-67, 10), Pair(25, -12), Pair(-63, 17), Pair(-117, 13),
        Pair(-97, 8), Pair(-86, 22), Pair(-3, 4), Pair(42, 1), Pair(-105, 26), Pair(8, -1), Pair(-14, 13), Pair(-119, 10),
        Pair(-121, 30), Pair(-122, 40), Pair(62, -5), Pair(-1, -22), Pair(-5, 15), Pair(-11, 10), Pair(-23, 20), Pair(-128, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-60, -144), Pair(-58, -77), Pair(-21, -49), Pair(-77, -52), Pair(-50, -31), Pair(-34, -125), Pair(5, -43), Pair(-31, -89),
        Pair(14, -96), Pair(9, -64), Pair(23, -61), Pair(-92, -26), Pair(-64, -46), Pair(28, -71), Pair(-7, -51), Pair(-39, -62),
        Pair(-31, -76), Pair(-120, -54), Pair(-36, -40), Pair(25, -47), Pair(95, -50), Pair(-80, -28), Pair(-52, -72), Pair(-122, -54),
        Pair(76, -74), Pair(-19, -40), Pair(24, -32), Pair(14, -41), Pair(52, -55), Pair(-87, -28), Pair(-18, -47), Pair(61, -71),
        Pair(-52, -37), Pair(-65, -36), Pair(7, -33), Pair(126, -38), Pair(27, -32), Pair(67, -43), Pair(53, -34), Pair(20, -75),
        Pair(-73, -66), Pair(-48, -21), Pair(43, -36), Pair(34, -32), Pair(-89, -11), Pair(38, -57), Pair(-38, -26), Pair(18, -58),
        Pair(-37, -115), Pair(-69, -31), Pair(-77, -39), Pair(-74, -36), Pair(-31, -43), Pair(16, -35), Pair(2, 6), Pair(-9, -37),
        Pair(-12, -83), Pair(39, -45), Pair(21, -43), Pair(-6, -73), Pair(27, -45), Pair(43, -65), Pair(21, -54), Pair(-32, -6)
      },
      { // Piece 2
        Pair(-27, -45), Pair(49, -34), Pair(-77, -36), Pair(-60, -15), Pair(-23, -22), Pair(-109, -38), Pair(-14, -42), Pair(-1, -35),
        Pair(-58, -24), Pair(-67, -33), Pair(-80, -18), Pair(-58, -14), Pair(-111, -2), Pair(-51, -19), Pair(-33, -25), Pair(-21, -56),
        Pair(-58, -25), Pair(-38, -21), Pair(-46, -20), Pair(-79, -7), Pair(-8, -2), Pair(-32, -17), Pair(-48, -24), Pair(-34, -20),
        Pair(-36, -22), Pair(-40, -24), Pair(-25, -15), Pair(-55, -6), Pair(-15, -29), Pair(-32, 0), Pair(-97, -11), Pair(-45, -22),
        Pair(-32, -32), Pair(-15, -39), Pair(-44, -21), Pair(86, -34), Pair(-32, -31), Pair(58, -24), Pair(-44, -17), Pair(-7, -52),
        Pair(-15, -27), Pair(-60, -26), Pair(-69, -14), Pair(-27, -44), Pair(-12, -27), Pair(61, -40), Pair(3, -28), Pair(-55, 6),
        Pair(-65, -1), Pair(-43, -41), Pair(-1, -20), Pair(-26, -38), Pair(-47, -35), Pair(-43, -46), Pair(-98, -33), Pair(26, -37),
        Pair(-48, -45), Pair(-76, 15), Pair(-24, -10), Pair(-70, -29), Pair(41, -57), Pair(13, -40), Pair(-47, -16), Pair(-59, -69)
      },
      { // Piece 3
        Pair(-36, -54), Pair(-15, -65), Pair(5, -55), Pair(45, -54), Pair(-26, -55), Pair(65, -60), Pair(74, -80), Pair(26, -58),
        Pair(-77, -63), Pair(62, -89), Pair(50, -61), Pair(-76, -44), Pair(-68, -41), Pair(-43, -53), Pair(-8, -69), Pair(0, -80),
        Pair(-67, -60), Pair(12, -74), Pair(-23, -66), Pair(-38, -60), Pair(-13, -63), Pair(-46, -39), Pair(-85, -53), Pair(-17, -79),
        Pair(-29, -68), Pair(-3, -63), Pair(-42, -60), Pair(-21, -59), Pair(-9, -82), Pair(-55, -59), Pair(-7, -78), Pair(-31, -62),
        Pair(-48, -87), Pair(-23, -87), Pair(-26, -82), Pair(-6, -93), Pair(0, -66), Pair(32, -59), Pair(-73, -77), Pair(-9, -91),
        Pair(-42, -104), Pair(13, -90), Pair(-25, -80), Pair(22, -86), Pair(17, -101), Pair(2, -72), Pair(36, -64), Pair(-33, -98),
        Pair(-16, -79), Pair(-39, -77), Pair(-29, -79), Pair(-60, -67), Pair(-14, -78), Pair(56, -115), Pair(34, -103), Pair(37, -108),
        Pair(0, -84), Pair(-45, -72), Pair(-52, -70), Pair(-71, -57), Pair(-23, -81), Pair(0, -86), Pair(68, -93), Pair(24, -69)
      },
      { // Piece 4
        Pair(-128, -131), Pair(-24, -88), Pair(-106, -70), Pair(-32, -88), Pair(-54, -19), Pair(-117, -44), Pair(-89, -124), Pair(-91, -89),
        Pair(-49, -78), Pair(-31, -63), Pair(-76, -99), Pair(56, -26), Pair(-26, -50), Pair(28, -40), Pair(-37, -67), Pair(-29, -46),
        Pair(-31, -59), Pair(-5, -14), Pair(-24, -53), Pair(37, -13), Pair(-31, -24), Pair(-41, -60), Pair(-34, -51), Pair(-11, -44),
        Pair(-35, -75), Pair(-39, -53), Pair(-41, -104), Pair(-30, -41), Pair(4, -85), Pair(-71, -43), Pair(-52, -46), Pair(-18, -43),
        Pair(-70, -152), Pair(-14, -42), Pair(-2, -21), Pair(-12, 30), Pair(8, -56), Pair(5, 12), Pair(45, 44), Pair(-34, -12),
        Pair(-30, -61), Pair(25, 1), Pair(25, -29), Pair(-28, -41), Pair(-11, -64), Pair(-34, -52), Pair(-2, -59), Pair(-34, -55),
        Pair(12, -28), Pair(24, -29), Pair(-24, -54), Pair(39, 58), Pair(15, -10), Pair(-21, -85), Pair(-22, -33), Pair(-14, -30),
        Pair(-5, -17), Pair(-16, -47), Pair(-40, -128), Pair(-3, 14), Pair(-33, -62), Pair(-51, -75), Pair(-26, -40), Pair(-77, -122)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(21, -45), Pair(2, -11), Pair(-15, 11), Pair(-22, 30), Pair(13, 23), Pair(4, 17), Pair(4, -1), Pair(-68, -19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-91, 4), Pair(-46, 7), Pair(-33, 16), Pair(-11, 4), Pair(2, -20), Pair(25, -4), Pair(-55, 30), Pair(-34, -1),
        Pair(-7, 80), Pair(-49, 81), Pair(-34, 94), Pair(-87, 12), Pair(65, 61), Pair(38, 62), Pair(-32, 101), Pair(69, 61),
        Pair(-104, 53), Pair(-62, 30), Pair(-30, 26), Pair(-80, 36), Pair(-55, 16), Pair(-2, 37), Pair(-125, 27), Pair(-82, 49),
        Pair(13, -9), Pair(-37, 35), Pair(-32, 24), Pair(36, -10), Pair(-83, 9), Pair(-43, -9), Pair(-88, 21), Pair(-77, 0),
        Pair(-67, -1), Pair(-16, 3), Pair(-1, 4), Pair(-16, 18), Pair(22, 2), Pair(51, -21), Pair(-84, 16), Pair(-69, -6),
        Pair(-113, 21), Pair(-67, 42), Pair(40, -2), Pair(5, 5), Pair(25, 14), Pair(-10, 28), Pair(-79, 42), Pair(-125, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-15, -117), Pair(-19, -57), Pair(-23, -29), Pair(-18, -58), Pair(-36, -99), Pair(-25, -66), Pair(14, 20), Pair(-1, 35),
        Pair(-20, -118), Pair(15, 55), Pair(-16, -29), Pair(-11, -160), Pair(-10, -50), Pair(-33, -14), Pair(-1, -91), Pair(0, -25),
        Pair(46, -28), Pair(-63, -41), Pair(-26, -36), Pair(-61, -74), Pair(-10, -62), Pair(-46, -10), Pair(-4, -42), Pair(12, 45),
        Pair(2, -29), Pair(23, -25), Pair(12, -22), Pair(49, -8), Pair(-11, -29), Pair(-8, -23), Pair(-11, -112), Pair(-7, 28),
        Pair(-30, -109), Pair(19, -2), Pair(-22, 34), Pair(4, -26), Pair(23, -22), Pair(40, -16), Pair(6, -9), Pair(7, 12),
        Pair(-26, -68), Pair(2, -16), Pair(-45, 8), Pair(31, -29), Pair(63, 31), Pair(15, -2), Pair(-17, -15), Pair(27, 32),
        Pair(-20, -64), Pair(2, -25), Pair(7, -28), Pair(51, -35), Pair(-29, -25), Pair(-10, 0), Pair(-38, -76), Pair(-45, -123),
        Pair(7, 21), Pair(25, 45), Pair(-35, -106), Pair(-26, -56), Pair(-9, -52), Pair(0, -60), Pair(2, -12), Pair(10, 52)
      },
      { // Piece 2
        Pair(17, 60), Pair(0, 105), Pair(-8, 1), Pair(-15, 7), Pair(29, 85), Pair(-22, -103), Pair(-14, -67), Pair(-4, 48),
        Pair(2, 19), Pair(10, 5), Pair(-38, 50), Pair(-19, 25), Pair(-30, -20), Pair(59, -17), Pair(-14, 0), Pair(-15, 17),
        Pair(0, -48), Pair(-33, 49), Pair(-30, 6), Pair(-44, -17), Pair(-49, 9), Pair(11, 42), Pair(25, -18), Pair(-83, -41),
        Pair(40, 11), Pair(9, -25), Pair(4, 22), Pair(-56, 59), Pair(-35, -36), Pair(-2, -14), Pair(-14, 11), Pair(-25, -77),
        Pair(2, 41), Pair(-11, 11), Pair(22, -17), Pair(47, 3), Pair(-5, 27), Pair(59, 25), Pair(-56, -21), Pair(-20, 6),
        Pair(-1, 19), Pair(6, 38), Pair(-79, -23), Pair(-6, 18), Pair(-5, -17), Pair(17, 38), Pair(-14, -4), Pair(-1, 40),
        Pair(-40, -65), Pair(20, 94), Pair(10, -27), Pair(-2, 23), Pair(-6, 19), Pair(-32, 76), Pair(6, -51), Pair(13, 60),
        Pair(-20, -5), Pair(-6, 23), Pair(1, -67), Pair(-8, -3), Pair(-25, 0), Pair(-32, -43), Pair(5, 80), Pair(-15, -87)
      },
      { // Piece 3
        Pair(4, -26), Pair(-58, -30), Pair(-69, -41), Pair(15, 9), Pair(2, -12), Pair(7, 18), Pair(-24, -26), Pair(47, -51),
        Pair(8, -50), Pair(6, -60), Pair(1, -57), Pair(-32, -43), Pair(12, -35), Pair(-78, -39), Pair(-32, -23), Pair(-43, -47),
        Pair(-31, -53), Pair(5, -46), Pair(-53, -38), Pair(3, -53), Pair(43, -61), Pair(9, -55), Pair(-17, -51), Pair(69, -50),
        Pair(-7, -45), Pair(21, -37), Pair(36, -59), Pair(-32, -24), Pair(5, -66), Pair(73, -59), Pair(25, -13), Pair(18, -14),
        Pair(-31, -48), Pair(-19, -52), Pair(-51, -43), Pair(-12, -67), Pair(15, -56), Pair(34, -25), Pair(-9, -47), Pair(14, -52),
        Pair(-22, -34), Pair(-32, -33), Pair(67, -63), Pair(-11, -53), Pair(51, -29), Pair(26, -75), Pair(-4, -74), Pair(-14, -49),
        Pair(6, -3), Pair(15, -43), Pair(-34, -26), Pair(-4, -114), Pair(-10, -100), Pair(12, -56), Pair(-41, -79), Pair(25, -53),
        Pair(-17, -78), Pair(55, -79), Pair(4, -19), Pair(7, -50), Pair(11, -84), Pair(44, -63), Pair(33, -4), Pair(53, -66)
      },
      { // Piece 4
        Pair(-38, -66), Pair(45, 6), Pair(-63, -97), Pair(-29, -86), Pair(-75, -11), Pair(-1, -37), Pair(-136, -196), Pair(-75, -103),
        Pair(-72, -113), Pair(-24, -52), Pair(1, 16), Pair(-8, -21), Pair(30, 43), Pair(-13, -24), Pair(-43, -82), Pair(-17, -60),
        Pair(9, 12), Pair(-54, -152), Pair(-44, -77), Pair(-53, -100), Pair(-2, -8), Pair(-10, -66), Pair(-74, -116), Pair(11, -23),
        Pair(-55, -84), Pair(-47, -92), Pair(-36, -75), Pair(-24, -38), Pair(-13, -41), Pair(-9, -8), Pair(13, 3), Pair(-26, -42),
        Pair(-47, -63), Pair(28, 52), Pair(-25, -44), Pair(81, 125), Pair(43, 35), Pair(-9, 12), Pair(58, 86), Pair(-16, -26),
        Pair(-40, -85), Pair(-22, -60), Pair(45, 40), Pair(-15, -43), Pair(-4, -7), Pair(-2, -31), Pair(-29, -37), Pair(7, 21),
        Pair(-78, -135), Pair(-43, -60), Pair(-28, -54), Pair(23, 26), Pair(-13, 12), Pair(14, 5), Pair(-17, -35), Pair(-8, -36),
        Pair(-7, -22), Pair(-39, -96), Pair(5, -20), Pair(16, 44), Pair(-8, -20), Pair(-27, -74), Pair(-10, -62), Pair(-3, -38)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 1), Pair(39, 8), Pair(-52, 37), Pair(-43, 57), Pair(-6, 62), Pair(-65, 62), Pair(3, 26), Pair(-63, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 4
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(125, -33), Pair(103, -1), Pair(97, 43), Pair(99, 4), Pair(-87, 70), Pair(36, 13), Pair(-34, -95), Pair(-23, -83),
        Pair(-1, 25), Pair(-69, 83), Pair(26, 63), Pair(50, 11), Pair(6, 22), Pair(116, -12), Pair(106, -21), Pair(-3, -5),
        Pair(-58, 46), Pair(22, 29), Pair(24, 11), Pair(45, -13), Pair(26, -6), Pair(51, -16), Pair(31, 1), Pair(11, -7),
        Pair(-44, 24), Pair(-68, 46), Pair(2, 6), Pair(-8, 4), Pair(-25, 1), Pair(24, -12), Pair(-3, 6), Pair(-28, -10),
        Pair(-40, 4), Pair(-33, 16), Pair(10, -16), Pair(6, -5), Pair(-16, -7), Pair(37, -26), Pair(2, 2), Pair(-68, 1),
        Pair(-90, 31), Pair(-32, 21), Pair(11, -6), Pair(-45, -2), Pair(-53, 24), Pair(10, -11), Pair(0, 3), Pair(-27, -18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-81, -68), Pair(-41, -100), Pair(-82, -27), Pair(-13, -19), Pair(-14, 25), Pair(22, -73), Pair(-16, -57), Pair(-14, -18),
        Pair(-79, -34), Pair(-89, 52), Pair(34, -6), Pair(0, 50), Pair(44, 6), Pair(-36, 33), Pair(-6, -23), Pair(23, -38),
        Pair(-14, -31), Pair(-17, 24), Pair(71, -12), Pair(54, 1), Pair(106, -8), Pair(51, 6), Pair(0, 23), Pair(-38, 29),
        Pair(-34, -10), Pair(27, -3), Pair(5, 25), Pair(134, -5), Pair(83, 31), Pair(96, 11), Pair(131, 1), Pair(90, -38),
        Pair(-20, -4), Pair(-35, 0), Pair(17, 31), Pair(33, 23), Pair(49, 25), Pair(33, 19), Pair(-6, 66), Pair(-4, -7),
        Pair(16, -58), Pair(-65, 22), Pair(-44, 27), Pair(-33, 23), Pair(78, -21), Pair(71, -5), Pair(8, -7), Pair(-72, -9),
        Pair(-66, -18), Pair(-68, -14), Pair(30, -12), Pair(-64, 27), Pair(21, -16), Pair(-64, 43), Pair(13, 38), Pair(-29, -40),
        Pair(-15, -9), Pair(-53, -32), Pair(-63, -26), Pair(-46, 28), Pair(-59, -8), Pair(-137, -19), Pair(-115, -7), Pair(-5, 13)
      },
      { // Piece 2
        Pair(-69, -46), Pair(10, -26), Pair(-21, 3), Pair(20, 22), Pair(-9, 20), Pair(19, -87), Pair(-2, -36), Pair(19, -4),
        Pair(17, -2), Pair(-86, 24), Pair(42, -22), Pair(-57, 5), Pair(1, -42), Pair(21, -82), Pair(-96, 1), Pair(-141, -45),
        Pair(-72, 31), Pair(-90, 39), Pair(125, -31), Pair(77, -21), Pair(12, 28), Pair(-37, 60), Pair(99, 2), Pair(-36, 34),
        Pair(-8, -6), Pair(46, -16), Pair(40, -18), Pair(45, -16), Pair(5, 23), Pair(-8, 4), Pair(-25, 28), Pair(-62, 30),
        Pair(16, 19), Pair(50, -14), Pair(-33, 20), Pair(32, 18), Pair(36, -5), Pair(0, 12), Pair(-61, 20), Pair(31, -27),
        Pair(-94, 37), Pair(67, 1), Pair(-17, 23), Pair(69, -13), Pair(20, 6), Pair(42, -20), Pair(26, 12), Pair(-82, -8),
        Pair(55, -9), Pair(-115, 23), Pair(0, 11), Pair(-11, -1), Pair(-48, -3), Pair(-151, 3), Pair(-6, -20), Pair(61, -84),
        Pair(-40, -10), Pair(-64, 0), Pair(-34, 6), Pair(17, -10), Pair(-141, 18), Pair(-68, -1), Pair(14, -65), Pair(-13, 75)
      },
      { // Piece 3
        Pair(-58, 104), Pair(14, 58), Pair(76, 23), Pair(23, 83), Pair(20, -4), Pair(34, 56), Pair(33, 80), Pair(-38, 20),
        Pair(12, 39), Pair(84, 18), Pair(51, 22), Pair(34, 33), Pair(19, 29), Pair(6, 49), Pair(98, 17), Pair(33, 19),
        Pair(-10, 22), Pair(-11, 30), Pair(18, 18), Pair(53, 28), Pair(139, -19), Pair(17, 28), Pair(25, 4), Pair(24, 9),
        Pair(-57, 47), Pair(-22, 50), Pair(2, 23), Pair(-7, 34), Pair(-75, 61), Pair(37, 14), Pair(-36, 29), Pair(-73, 39),
        Pair(-168, 47), Pair(-43, 8), Pair(-10, 5), Pair(-103, 50), Pair(41, -19), Pair(1, 25), Pair(-49, 34), Pair(13, -26),
        Pair(-106, 39), Pair(-98, 20), Pair(-98, 46), Pair(-93, 30), Pair(-43, 5), Pair(-59, 12), Pair(-8, 34), Pair(-53, -16),
        Pair(-158, 30), Pair(-167, 54), Pair(3, -19), Pair(-141, 59), Pair(64, -25), Pair(4, -15), Pair(1, -14), Pair(-109, 45),
        Pair(-135, 55), Pair(-121, 55), Pair(-55, 30), Pair(-42, 20), Pair(-7, -9), Pair(-41, 11), Pair(-53, 19), Pair(-95, 27)
      },
      { // Piece 4
        Pair(-63, -78), Pair(-119, -53), Pair(-6, -5), Pair(41, -74), Pair(-11, 27), Pair(74, 83), Pair(16, 32), Pair(-2, -3),
        Pair(-128, 5), Pair(-62, 8), Pair(-67, -5), Pair(-117, 114), Pair(-83, 65), Pair(-35, 25), Pair(54, 45), Pair(-6, 75),
        Pair(-99, -43), Pair(-119, 23), Pair(53, -57), Pair(-62, 44), Pair(-11, 24), Pair(26, 31), Pair(17, -17), Pair(12, -38),
        Pair(-101, 28), Pair(-111, 61), Pair(-119, 51), Pair(-27, 46), Pair(-81, 46), Pair(-49, 37), Pair(-96, 39), Pair(-40, -42),
        Pair(-174, -99), Pair(-101, 46), Pair(-158, 11), Pair(-90, 60), Pair(-79, 75), Pair(-23, 1), Pair(-43, 5), Pair(49, -129),
        Pair(-167, -60), Pair(-134, -56), Pair(-49, 0), Pair(-99, 67), Pair(-84, 32), Pair(-9, -71), Pair(-98, -103), Pair(-62, 36),
        Pair(-152, -22), Pair(-118, 23), Pair(-157, 31), Pair(-136, 77), Pair(-108, 8), Pair(-80, -62), Pair(-28, -26), Pair(-102, -6),
        Pair(-149, -69), Pair(-62, -113), Pair(-133, 31), Pair(-80, -137), Pair(6, -68), Pair(-108, -39), Pair(-40, 60), Pair(-132, -132)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(13, -41), Pair(102, -40), Pair(-2, 1), Pair(-107, 31), Pair(-57, 15), Pair(-43, 0), Pair(33, -29), Pair(-66, -39),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, 87), Pair(50, 8), Pair(154, -116), Pair(48, -120), Pair(26, -107), Pair(105, -124), Pair(70, 69), Pair(-34, -10),
        Pair(-27, 45), Pair(83, 21), Pair(101, -26), Pair(4, -16), Pair(88, -40), Pair(171, -13), Pair(177, -25), Pair(3, 28),
        Pair(-128, 44), Pair(-26, 30), Pair(7, 6), Pair(5, -10), Pair(35, -13), Pair(36, -2), Pair(-31, 15), Pair(-9, 1),
        Pair(-63, 22), Pair(-88, 38), Pair(-17, -3), Pair(24, -15), Pair(-5, -1), Pair(11, -14), Pair(-78, 24), Pair(-78, 7),
        Pair(-91, 6), Pair(-64, 22), Pair(-13, -11), Pair(-41, -7), Pair(-8, -13), Pair(-51, 1), Pair(-46, 17), Pair(-59, 2),
        Pair(-119, 26), Pair(-73, 28), Pair(-14, 8), Pair(-79, 32), Pair(-11, 5), Pair(-55, 4), Pair(-47, 17), Pair(-91, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-134, -78), Pair(-22, -83), Pair(70, -16), Pair(-1, 23), Pair(13, -27), Pair(-8, 30), Pair(2, -50), Pair(-198, -121),
        Pair(-43, -44), Pair(-20, 11), Pair(6, -48), Pair(-33, -43), Pair(-13, -61), Pair(-32, 10), Pair(70, 72), Pair(-16, -11),
        Pair(36, -14), Pair(-65, 19), Pair(50, 29), Pair(59, 16), Pair(62, 1), Pair(78, 1), Pair(66, -30), Pair(92, -41),
        Pair(16, 15), Pair(27, 19), Pair(-14, 10), Pair(106, 9), Pair(60, 18), Pair(136, 10), Pair(66, -19), Pair(-16, -16),
        Pair(-62, 21), Pair(-31, -5), Pair(28, 12), Pair(64, 30), Pair(86, 17), Pair(15, 26), Pair(30, 0), Pair(22, -47),
        Pair(-60, -23), Pair(-85, 51), Pair(-28, 16), Pair(1, -2), Pair(-58, 37), Pair(36, -2), Pair(-63, -18), Pair(-67, -57),
        Pair(-11, 5), Pair(12, -19), Pair(-65, 6), Pair(-80, 17), Pair(-23, 16), Pair(-5, -11), Pair(-6, -9), Pair(-50, -88),
        Pair(-24, 52), Pair(-178, 4), Pair(-60, -23), Pair(2, -1), Pair(-80, 7), Pair(45, 32), Pair(17, -38), Pair(-22, -9)
      },
      { // Piece 2
        Pair(61, 9), Pair(-55, -39), Pair(-35, -108), Pair(-38, 15), Pair(29, 35), Pair(-7, -39), Pair(-60, 17), Pair(94, 59),
        Pair(-30, -24), Pair(73, -57), Pair(-16, 2), Pair(-21, -21), Pair(-33, -60), Pair(63, -25), Pair(-35, -5), Pair(74, -29),
        Pair(-7, 29), Pair(-28, 0), Pair(87, -28), Pair(19, -19), Pair(84, -11), Pair(94, -4), Pair(102, -2), Pair(16, -4),
        Pair(3, -25), Pair(28, -5), Pair(63, -11), Pair(82, -12), Pair(49, 9), Pair(156, -28), Pair(36, -11), Pair(61, -7),
        Pair(47, -37), Pair(100, -32), Pair(42, -17), Pair(46, -11), Pair(125, -31), Pair(38, -4), Pair(170, -29), Pair(-53, -14),
        Pair(-47, 18), Pair(-66, 10), Pair(69, -37), Pair(37, -4), Pair(24, -2), Pair(18, -8), Pair(48, -25), Pair(-85, 6),
        Pair(-112, 24), Pair(34, -6), Pair(-33, 23), Pair(-25, 6), Pair(-91, 8), Pair(25, 8), Pair(17, -33), Pair(30, -44),
        Pair(6, -57), Pair(-18, 5), Pair(-29, 5), Pair(-26, 13), Pair(13, -31), Pair(-49, 13), Pair(-59, -39), Pair(-30, -16)
      },
      { // Piece 3
        Pair(16, 31), Pair(1, 49), Pair(29, 47), Pair(75, 86), Pair(35, 78), Pair(9, -48), Pair(49, 20), Pair(82, 67),
        Pair(1, 43), Pair(106, 15), Pair(93, 20), Pair(76, 19), Pair(106, 15), Pair(46, 21), Pair(46, 25), Pair(56, 21),
        Pair(126, 4), Pair(36, 28), Pair(69, 24), Pair(111, -19), Pair(23, -10), Pair(73, -23), Pair(13, 13), Pair(86, -9),
        Pair(17, 15), Pair(-31, 43), Pair(-23, 8), Pair(56, -5), Pair(29, 4), Pair(39, -15), Pair(-71, 29), Pair(-57, 24),
        Pair(53, -1), Pair(-55, 14), Pair(-20, 27), Pair(-24, 18), Pair(-65, 28), Pair(-121, 42), Pair(10, -3), Pair(-46, -10),
        Pair(-12, -19), Pair(25, -2), Pair(-79, 23), Pair(-61, 25), Pair(-100, 24), Pair(60, -31), Pair(-42, -5), Pair(-18, 0),
        Pair(-47, 0), Pair(-8, 5), Pair(-6, 7), Pair(-102, 37), Pair(-68, 12), Pair(-24, 21), Pair(-15, 9), Pair(-49, 29),
        Pair(-54, 3), Pair(-84, 27), Pair(-19, 6), Pair(-82, 26), Pair(-18, -18), Pair(-26, -13), Pair(-129, 58), Pair(-67, -4)
      },
      { // Piece 4
        Pair(-89, 43), Pair(-67, -43), Pair(-26, 0), Pair(47, 61), Pair(0, 6), Pair(64, 101), Pair(3, 28), Pair(73, 72),
        Pair(-8, 4), Pair(-12, 33), Pair(-72, 63), Pair(-14, -9), Pair(-45, -31), Pair(-17, -16), Pair(-39, -34), Pair(87, -69),
        Pair(46, -6), Pair(-43, -6), Pair(25, -58), Pair(-79, -13), Pair(112, -50), Pair(57, -28), Pair(-86, -9), Pair(22, -21),
        Pair(41, 14), Pair(2, 56), Pair(-54, 18), Pair(30, 59), Pair(-5, 28), Pair(-53, -44), Pair(29, -37), Pair(92, -19),
        Pair(-183, 36), Pair(19, 75), Pair(-69, 45), Pair(26, 23), Pair(32, 17), Pair(30, 54), Pair(54, -31), Pair(-59, -68),
        Pair(-80, -39), Pair(-61, -32), Pair(-106, -54), Pair(7, 16), Pair(-7, 26), Pair(15, -28), Pair(-80, -39), Pair(-25, -37),
        Pair(-34, -67), Pair(-84, -69), Pair(-101, -101), Pair(-62, -43), Pair(-85, -41), Pair(-105, -20), Pair(-81, -29), Pair(-51, -63),
        Pair(-82, -72), Pair(-73, -43), Pair(-86, -84), Pair(-75, -113), Pair(-111, -32), Pair(1, -1), Pair(-40, -68), Pair(55, 42)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(41, -56), Pair(59, -24), Pair(46, -12), Pair(-20, 14), Pair(1, -1), Pair(2, -17), Pair(35, -34), Pair(-47, -53),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(89, -49), Pair(120, -76), Pair(99, -36), Pair(82, -70), Pair(18, -52), Pair(5, -94), Pair(53, -58), Pair(223, -59),
        Pair(51, 29), Pair(84, 23), Pair(72, -6), Pair(136, -49), Pair(80, -44), Pair(96, -33), Pair(13, 1), Pair(-14, 16),
        Pair(-39, 32), Pair(0, 28), Pair(-1, 7), Pair(23, -4), Pair(15, 2), Pair(-13, 8), Pair(-3, 16), Pair(-32, 10),
        Pair(-75, 27), Pair(-83, 40), Pair(-20, 6), Pair(-17, 5), Pair(-25, 7), Pair(6, 0), Pair(-23, 18), Pair(-76, 8),
        Pair(-76, 13), Pair(-61, 24), Pair(-27, 3), Pair(-2, -5), Pair(14, -5), Pair(-29, -1), Pair(-28, 10), Pair(-69, 5),
        Pair(-95, 32), Pair(-76, 32), Pair(-8, -3), Pair(-59, 8), Pair(9, -2), Pair(-18, 3), Pair(-20, 12), Pair(-116, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-34, -175), Pair(-4, -76), Pair(0, -14), Pair(-43, -9), Pair(75, -36), Pair(9, -39), Pair(-28, -9), Pair(-95, -120),
        Pair(-25, -46), Pair(-31, -20), Pair(-53, -6), Pair(85, -18), Pair(71, -36), Pair(13, -19), Pair(-17, -25), Pair(14, -48),
        Pair(-88, -29), Pair(31, -18), Pair(57, -10), Pair(47, -6), Pair(-27, 2), Pair(97, -25), Pair(75, -30), Pair(7, -21),
        Pair(-73, -5), Pair(-14, 2), Pair(32, 14), Pair(138, -23), Pair(67, 4), Pair(83, 0), Pair(17, -1), Pair(93, -35),
        Pair(-26, -6), Pair(79, -4), Pair(41, 8), Pair(44, 14), Pair(46, 11), Pair(67, 5), Pair(33, -1), Pair(4, 1),
        Pair(-101, -3), Pair(-97, 20), Pair(4, -2), Pair(54, 3), Pair(34, 19), Pair(13, -1), Pair(-30, 3), Pair(-43, 7),
        Pair(-60, 2), Pair(-92, 9), Pair(-107, 11), Pair(-39, 11), Pair(-38, 9), Pair(-43, 19), Pair(5, -35), Pair(-56, 19),
        Pair(-32, -8), Pair(-175, -8), Pair(-114, 8), Pair(-59, -2), Pair(-49, -21), Pair(-159, 2), Pair(-141, 46), Pair(-54, 27)
      },
      { // Piece 2
        Pair(-33, -2), Pair(-68, -21), Pair(-40, -27), Pair(-27, -31), Pair(89, -49), Pair(-84, -27), Pair(21, -16), Pair(6, -20),
        Pair(-41, -23), Pair(-12, -16), Pair(-34, -8), Pair(-20, -31), Pair(-6, -18), Pair(109, -40), Pair(-68, -10), Pair(51, -25),
        Pair(-44, -2), Pair(4, -35), Pair(29, -18), Pair(132, -32), Pair(118, -56), Pair(38, -13), Pair(-45, -25), Pair(-33, 6),
        Pair(-5, -17), Pair(2, -28), Pair(75, -20), Pair(149, -45), Pair(55, -15), Pair(52, -25), Pair(56, -32), Pair(-6, -13),
        Pair(-83, -11), Pair(13, -26), Pair(13, -24), Pair(46, -22), Pair(26, -21), Pair(41, -22), Pair(26, -39), Pair(163, -65),
        Pair(-93, 15), Pair(-2, -14), Pair(34, -16), Pair(23, -12), Pair(8, -9), Pair(31, -21), Pair(21, -14), Pair(-51, -11),
        Pair(-14, -14), Pair(-14, -6), Pair(18, -31), Pair(39, -31), Pair(6, -28), Pair(-90, -12), Pair(28, -37), Pair(-64, -21),
        Pair(-84, -23), Pair(-41, -38), Pair(-68, 8), Pair(-91, 3), Pair(1, -20), Pair(-47, -5), Pair(-2, -45), Pair(97, -33)
      },
      { // Piece 3
        Pair(-47, 12), Pair(-19, 17), Pair(-61, 22), Pair(14, -5), Pair(3, -2), Pair(79, -28), Pair(13, -5), Pair(70, -12),
        Pair(-10, -9), Pair(1, -5), Pair(21, -9), Pair(82, -29), Pair(60, -35), Pair(-48, -9), Pair(76, -41), Pair(16, -20),
        Pair(14, -16), Pair(72, -20), Pair(51, -22), Pair(119, -45), Pair(77, -38), Pair(137, -42), Pair(29, -19), Pair(72, -36),
        Pair(26, -19), Pair(13, -10), Pair(22, -15), Pair(79, -28), Pair(47, -26), Pair(101, -49), Pair(72, -40), Pair(14, -22),
        Pair(-56, -15), Pair(-95, 9), Pair(-15, -28), Pair(-69, -10), Pair(-24, -15), Pair(-39, -22), Pair(3, -24), Pair(-8, -41),
        Pair(-69, -22), Pair(-27, -21), Pair(-92, -7), Pair(-62, -11), Pair(-30, -25), Pair(-49, -28), Pair(-48, -21), Pair(-99, -8),
        Pair(-172, 2), Pair(-94, -5), Pair(-65, -20), Pair(-31, -24), Pair(-41, -27), Pair(-46, -25), Pair(-78, -18), Pair(-53, -27),
        Pair(-107, -10), Pair(-88, -6), Pair(-121, 3), Pair(-73, -13), Pair(-37, -33), Pair(-29, -29), Pair(-132, 12), Pair(-139, -2)
      },
      { // Piece 4
        Pair(-55, -36), Pair(-1, -86), Pair(-88, -25), Pair(-57, -11), Pair(28, -56), Pair(-40, -28), Pair(-1, -22), Pair(-176, 1),
        Pair(-15, -66), Pair(-35, -59), Pair(-5, -20), Pair(-23, -8), Pair(-30, -24), Pair(-68, -12), Pair(-67, 32), Pair(-56, -81),
        Pair(-76, -81), Pair(-39, -71), Pair(-44, -19), Pair(-58, 10), Pair(71, -38), Pair(-73, -51), Pair(-30, -64), Pair(10, -47),
        Pair(-116, -35), Pair(-67, -52), Pair(-87, 3), Pair(45, -9), Pair(48, -28), Pair(-47, 28), Pair(-28, -78), Pair(16, -66),
        Pair(-35, -86), Pair(-85, -96), Pair(-145, 33), Pair(-102, 19), Pair(10, -34), Pair(-36, 8), Pair(-41, -53), Pair(-79, -73),
        Pair(-79, -51), Pair(-209, 38), Pair(-51, 3), Pair(-82, 24), Pair(-71, -12), Pair(-48, -43), Pair(-121, -16), Pair(-54, -123),
        Pair(-114, -30), Pair(-78, -16), Pair(-30, -44), Pair(-134, 22), Pair(-48, -52), Pair(-41, -56), Pair(-86, -57), Pair(-42, -18),
        Pair(-39, -63), Pair(-84, -128), Pair(-63, -74), Pair(-54, -124), Pair(-116, -28), Pair(-64, 0), Pair(-182, -152), Pair(-143, -89)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(12, -51), Pair(53, -25), Pair(25, -3), Pair(-59, 22), Pair(-42, 15), Pair(0, -4), Pair(24, -24), Pair(-97, -31),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(96, -45), Pair(39, -49), Pair(80, -55), Pair(93, -64), Pair(58, -81), Pair(-2, -44), Pair(93, -20), Pair(68, -44),
        Pair(4, 25), Pair(37, 31), Pair(148, -19), Pair(104, -25), Pair(138, -24), Pair(117, -19), Pair(107, 4), Pair(44, 16),
        Pair(-94, 41), Pair(-92, 42), Pair(-44, 15), Pair(-22, 7), Pair(-36, 10), Pair(41, -2), Pair(-34, 26), Pair(-57, 27),
        Pair(-131, 39), Pair(-93, 47), Pair(-94, 31), Pair(-88, 38), Pair(-82, 33), Pair(-44, 20), Pair(-53, 38), Pair(-119, 27),
        Pair(-133, 31), Pair(-90, 30), Pair(-68, 9), Pair(-33, 10), Pair(-3, 5), Pair(-49, 10), Pair(-51, 22), Pair(-112, 21),
        Pair(-182, 50), Pair(-129, 44), Pair(-77, 18), Pair(36, 7), Pair(-33, 18), Pair(-49, 16), Pair(-77, 35), Pair(-156, 41),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-94, -128), Pair(19, -62), Pair(-89, -13), Pair(-67, 0), Pair(13, -20), Pair(18, -28), Pair(-34, -47), Pair(-45, -72),
        Pair(-22, -19), Pair(-11, -10), Pair(60, 6), Pair(13, 4), Pair(51, -10), Pair(-73, -8), Pair(-58, -5), Pair(-26, -22),
        Pair(69, -49), Pair(-54, -17), Pair(16, 17), Pair(56, -19), Pair(-89, 21), Pair(13, -3), Pair(8, -16), Pair(-31, -22),
        Pair(93, -29), Pair(83, -13), Pair(86, -7), Pair(27, -2), Pair(68, -2), Pair(148, -12), Pair(132, -37), Pair(12, -30),
        Pair(-18, -2), Pair(-12, 6), Pair(-10, 17), Pair(31, 14), Pair(68, 3), Pair(-7, 9), Pair(23, -2), Pair(64, 1),
        Pair(-47, -16), Pair(-110, 23), Pair(-13, 3), Pair(22, 21), Pair(-6, 25), Pair(12, 12), Pair(5, 9), Pair(-72, 20),
        Pair(-50, 7), Pair(-47, 22), Pair(-87, 2), Pair(54, -14), Pair(-42, 23), Pair(-17, 1), Pair(-32, -10), Pair(24, -15),
        Pair(-53, -63), Pair(-87, -1), Pair(-23, -16), Pair(-4, 14), Pair(-60, -4), Pair(-50, -23), Pair(-87, 20), Pair(-22, 22)
      },
      { // Piece 2
        Pair(-21, -23), Pair(48, -19), Pair(3, -20), Pair(-42, -17), Pair(-54, -20), Pair(23, -21), Pair(-32, -17), Pair(-47, -14),
        Pair(54, -29), Pair(14, -35), Pair(32, -28), Pair(15, -34), Pair(-7, -35), Pair(-29, -23), Pair(-32, -27), Pair(-85, -13),
        Pair(-56, -20), Pair(-13, -13), Pair(75, -30), Pair(162, -30), Pair(119, -63), Pair(127, -39), Pair(11, -19), Pair(20, -27),
        Pair(-3, -10), Pair(0, -22), Pair(-16, -10), Pair(79, -33), Pair(96, -38), Pair(168, -44), Pair(23, -23), Pair(-45, -18),
        Pair(-34, -5), Pair(31, -20), Pair(48, -31), Pair(67, -20), Pair(67, -30), Pair(-18, -5), Pair(7, -13), Pair(23, -23),
        Pair(-72, 3), Pair(-37, -7), Pair(-30, -5), Pair(60, -20), Pair(51, -11), Pair(-8, -14), Pair(52, -13), Pair(-17, 5),
        Pair(-26, 16), Pair(-90, -5), Pair(11, -23), Pair(12, -12), Pair(-47, -8), Pair(0, -27), Pair(-11, -25), Pair(-131, -2),
        Pair(-82, 2), Pair(-57, -9), Pair(-77, -17), Pair(-23, -13), Pair(-11, -18), Pair(-115, -13), Pair(-45, -19), Pair(-62, 7)
      },
      { // Piece 3
        Pair(-12, -5), Pair(24, -1), Pair(59, -12), Pair(-57, 14), Pair(-36, 6), Pair(123, -34), Pair(95, -23), Pair(46, -13),
        Pair(108, -42), Pair(-6, -12), Pair(101, -41), Pair(75, -34), Pair(-4, -11), Pair(61, -33), Pair(-3, -19), Pair(52, -36),
        Pair(-12, -15), Pair(26, -23), Pair(-1, -12), Pair(79, -42), Pair(23, -36), Pair(89, -18), Pair(78, -40), Pair(-87, 4),
        Pair(-14, -14), Pair(-21, -3), Pair(32, -22), Pair(21, -13), Pair(40, -28), Pair(79, -41), Pair(-6, -15), Pair(-4, -18),
        Pair(-77, -18), Pair(-6, -22), Pair(17, -22), Pair(6, -21), Pair(-38, -21), Pair(-27, -19), Pair(39, -31), Pair(-116, -8),
        Pair(-85, -32), Pair(-55, -23), Pair(-82, -16), Pair(-62, -17), Pair(5, -38), Pair(-71, -27), Pair(-142, -8), Pair(-76, -29),
        Pair(-143, -9), Pair(-78, -9), Pair(-77, -22), Pair(-116, -13), Pair(-31, -28), Pair(-41, -21), Pair(9, -54), Pair(-104, -14),
        Pair(-128, 4), Pair(-72, -27), Pair(-95, -10), Pair(0, -47), Pair(-18, -42), Pair(-76, -18), Pair(-142, 1), Pair(-124, -1)
      },
      { // Piece 4
        Pair(36, 17), Pair(-79, -47), Pair(-22, 5), Pair(-29, -36), Pair(-27, -3), Pair(-22, 27), Pair(31, -4), Pair(-18, 10),
        Pair(-54, -85), Pair(-12, -74), Pair(-133, -54), Pair(5, 41), Pair(78, 38), Pair(10, 29), Pair(-49, -69), Pair(-63, -72),
        Pair(-18, 14), Pair(13, -41), Pair(8, 28), Pair(-20, -41), Pair(-3, -29), Pair(98, 142), Pair(38, 61), Pair(27, 43),
        Pair(-39, -48), Pair(-78, -43), Pair(-4, -21), Pair(45, 29), Pair(16, -15), Pair(-5, 13), Pair(-16, 30), Pair(5, -17),
        Pair(-45, -28), Pair(-21, -43), Pair(-24, -68), Pair(-40, -1), Pair(-58, -47), Pair(-60, -21), Pair(13, -20), Pair(-48, -84),
        Pair(-24, -86), Pair(-26, -36), Pair(-34, 36), Pair(10, 24), Pair(-37, -24), Pair(-7, -10), Pair(-48, -46), Pair(-53, -83),
        Pair(-40, -71), Pair(-59, -32), Pair(4, -14), Pair(-40, -65), Pair(-94, 14), Pair(-82, -60), Pair(27, -28), Pair(-14, -2),
        Pair(-17, -53), Pair(-53, -103), Pair(-73, -16), Pair(-61, -24), Pair(17, -16), Pair(-97, -95), Pair(-31, -32), Pair(-12, -17)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(34, -55), Pair(97, -33), Pair(22, 4), Pair(-27, 25), Pair(-46, 20), Pair(-3, 4), Pair(14, -20), Pair(-40, -42),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, -3), Pair(63, -32), Pair(17, 49), Pair(71, -4), Pair(-23, -5), Pair(-46, 1), Pair(-1, 37), Pair(0, 16),
        Pair(-64, 64), Pair(-52, 66), Pair(148, 21), Pair(-33, 36), Pair(58, 18), Pair(-14, 17), Pair(-39, 54), Pair(-13, 51),
        Pair(-134, 42), Pair(-30, 30), Pair(14, 15), Pair(-44, 30), Pair(-20, 22), Pair(60, -2), Pair(-13, 39), Pair(-65, 25),
        Pair(-94, 28), Pair(-107, 48), Pair(0, 9), Pair(-49, 26), Pair(-27, 13), Pair(-53, 17), Pair(-31, 34), Pair(-91, 24),
        Pair(-177, 29), Pair(-63, 30), Pair(-42, 11), Pair(-15, 24), Pair(-52, 22), Pair(-15, 8), Pair(-90, 32), Pair(-135, 25),
        Pair(-144, 40), Pair(-150, 48), Pair(-69, 16), Pair(20, -23), Pair(-79, 27), Pair(-63, 22), Pair(-44, 32), Pair(-120, 42),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-64, -195), Pair(-24, -108), Pair(25, -91), Pair(-15, -118), Pair(-2, -32), Pair(-26, -93), Pair(-42, -74), Pair(-21, -65),
        Pair(-66, -81), Pair(-27, -26), Pair(-11, -53), Pair(42, -59), Pair(-22, -35), Pair(30, -31), Pair(5, -61), Pair(-58, -79),
        Pair(12, -35), Pair(81, -62), Pair(73, -69), Pair(23, -25), Pair(18, -28), Pair(-86, -31), Pair(83, -75), Pair(9, -32),
        Pair(-32, -47), Pair(53, -48), Pair(19, -34), Pair(34, -23), Pair(128, -30), Pair(56, -38), Pair(38, -44), Pair(-4, -22),
        Pair(-38, -45), Pair(-22, -43), Pair(21, -33), Pair(73, -23), Pair(28, -32), Pair(16, -47), Pair(30, -17), Pair(62, -4),
        Pair(-65, -67), Pair(19, -46), Pair(47, -12), Pair(-11, -14), Pair(8, -7), Pair(1, -41), Pair(-26, -29), Pair(19, 24),
        Pair(-47, -40), Pair(14, -26), Pair(-63, -31), Pair(25, -27), Pair(0, -22), Pair(13, -26), Pair(15, -50), Pair(-27, -86),
        Pair(-21, -53), Pair(-34, -38), Pair(-45, -59), Pair(-4, -57), Pair(6, -57), Pair(-24, -76), Pair(6, 77), Pair(8, -8)
      },
      { // Piece 2
        Pair(-47, -71), Pair(-31, -21), Pair(35, -54), Pair(20, -23), Pair(-56, -44), Pair(12, -57), Pair(8, -32), Pair(-51, -47),
        Pair(-9, -31), Pair(6, -40), Pair(-39, -33), Pair(-29, -59), Pair(-82, -50), Pair(-36, -46), Pair(5, -27), Pair(19, -40),
        Pair(24, -9), Pair(-8, -28), Pair(-12, -32), Pair(33, -26), Pair(43, -32), Pair(24, -45), Pair(49, -46), Pair(3, -41),
        Pair(-53, -1), Pair(-29, -31), Pair(14, -38), Pair(59, -34), Pair(112, -43), Pair(87, -32), Pair(43, -52), Pair(39, -33),
        Pair(-49, -38), Pair(-19, -23), Pair(22, -40), Pair(-14, -43), Pair(20, -23), Pair(37, -32), Pair(66, -33), Pair(-55, -36),
        Pair(-51, -32), Pair(88, -49), Pair(-2, -36), Pair(-49, -20), Pair(-82, -10), Pair(-57, -20), Pair(32, -5), Pair(-24, -21),
        Pair(-75, -35), Pair(-91, -18), Pair(-62, -13), Pair(-14, -28), Pair(-11, -40), Pair(-11, -32), Pair(-57, -39), Pair(-28, -5),
        Pair(3, -23), Pair(-58, -30), Pair(7, -13), Pair(-24, -27), Pair(-31, -7), Pair(-42, -19), Pair(-2, -42), Pair(-9, 17)
      },
      { // Piece 3
        Pair(46, -53), Pair(43, -53), Pair(-9, -40), Pair(101, -63), Pair(23, -24), Pair(27, -43), Pair(3, -47), Pair(33, -55),
        Pair(-82, -38), Pair(-52, -35), Pair(-52, -42), Pair(19, -57), Pair(-5, -52), Pair(45, -63), Pair(-8, -56), Pair(31, -84),
        Pair(-24, -50), Pair(-21, -51), Pair(52, -62), Pair(13, -50), Pair(40, -70), Pair(-20, -52), Pair(-96, -34), Pair(-62, -64),
        Pair(-42, -71), Pair(22, -83), Pair(10, -77), Pair(35, -46), Pair(-47, -115), Pair(22, -87), Pair(19, -87), Pair(-61, -29),
        Pair(78, -89), Pair(-25, -55), Pair(-60, -54), Pair(8, -62), Pair(18, -69), Pair(-59, -40), Pair(18, -72), Pair(-28, -68),
        Pair(12, -68), Pair(25, -89), Pair(-50, -72), Pair(-78, -71), Pair(-9, -74), Pair(2, -66), Pair(-27, -63), Pair(-52, -72),
        Pair(-11, -87), Pair(-91, -68), Pair(-53, -52), Pair(-32, -73), Pair(-52, -54), Pair(-28, -75), Pair(-70, -81), Pair(48, -72),
        Pair(-122, -37), Pair(-56, -53), Pair(-15, -58), Pair(-31, -37), Pair(5, -69), Pair(-39, -60), Pair(-36, -42), Pair(33, -86)
      },
      { // Piece 4
        Pair(32, -11), Pair(-18, -113), Pair(-28, -52), Pair(24, 55), Pair(36, 8), Pair(-30, -29), Pair(-57, -106), Pair(-56, -25),
        Pair(14, 20), Pair(28, 0), Pair(29, 19), Pair(15, 28), Pair(-9, 25), Pair(-41, -62), Pair(-32, -70), Pair(-68, -93),
        Pair(-62, -85), Pair(34, 4), Pair(-1, 43), Pair(21, 48), Pair(-32, -36), Pair(19, -16), Pair(-22, -46), Pair(-40, -63),
        Pair(-18, -32), Pair(-22, -36), Pair(-10, -50), Pair(7, 15), Pair(42, 81), Pair(-17, -31), Pair(11, 12), Pair(-17, -37),
        Pair(-47, -80), Pair(-15, -9), Pair(25, 79), Pair(-68, -110), Pair(-9, -15), Pair(36, 53), Pair(12, 24), Pair(-4, -11),
        Pair(-51, -98), Pair(7, 3), Pair(5, -6), Pair(-12, -44), Pair(14, 19), Pair(32, 69), Pair(21, 16), Pair(-7, 4),
        Pair(23, 32), Pair(-49, -87), Pair(-18, -22), Pair(22, 38), Pair(-30, -58), Pair(-67, -98), Pair(-21, -9), Pair(30, 47),
        Pair(18, 15), Pair(2, -33), Pair(-25, -40), Pair(-18, -36), Pair(-6, -23), Pair(-16, -43), Pair(-11, -28), Pair(-35, -60)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(92, -51), Pair(47, -16), Pair(16, 12), Pair(-38, 31), Pair(-49, 32), Pair(-7, 16), Pair(40, -10), Pair(-61, -26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(28, -28), Pair(-34, 0), Pair(-30, 1), Pair(-17, -18), Pair(-21, 21), Pair(-93, 41), Pair(-2, 47), Pair(-101, 15),
        Pair(-184, 79), Pair(-19, 88), Pair(-49, 63), Pair(-2, 69), Pair(-79, 99), Pair(-39, 62), Pair(41, 79), Pair(-154, 87),
        Pair(-131, 54), Pair(-35, 43), Pair(-23, 30), Pair(-27, 29), Pair(-21, 34), Pair(36, 17), Pair(-76, 42), Pair(-130, 39),
        Pair(-98, 33), Pair(-73, 42), Pair(-72, 21), Pair(-97, 41), Pair(-52, 34), Pair(-27, 18), Pair(-44, 31), Pair(-110, 30),
        Pair(-84, 22), Pair(-48, 24), Pair(25, 0), Pair(-7, 11), Pair(-45, 12), Pair(-3, 7), Pair(-19, 21), Pair(-79, 18),
        Pair(-103, 40), Pair(-63, 41), Pair(21, 13), Pair(-11, 3), Pair(-56, 20), Pair(-12, 21), Pair(-57, 33), Pair(-120, 37),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-36, -158), Pair(-36, -44), Pair(-25, -99), Pair(-25, -54), Pair(-4, -90), Pair(-37, -61), Pair(-8, -99), Pair(-31, -154),
        Pair(-50, -70), Pair(-38, -57), Pair(-42, -93), Pair(-31, -58), Pair(-38, -101), Pair(13, -106), Pair(-43, -89), Pair(-37, -105),
        Pair(-21, -94), Pair(72, -75), Pair(-35, -56), Pair(32, -51), Pair(-9, -58), Pair(-46, -61), Pair(22, -90), Pair(32, -99),
        Pair(4, -73), Pair(40, -82), Pair(65, -75), Pair(28, -59), Pair(24, -49), Pair(7, -51), Pair(46, -106), Pair(10, -100),
        Pair(-46, -93), Pair(-2, -49), Pair(-16, -39), Pair(72, -43), Pair(62, -50), Pair(-13, -33), Pair(0, -73), Pair(23, -79),
        Pair(-16, -48), Pair(23, -57), Pair(61, -55), Pair(-22, -43), Pair(30, -45), Pair(16, -67), Pair(-1, -49), Pair(12, -83),
        Pair(-16, -84), Pair(6, -60), Pair(-45, -66), Pair(82, -74), Pair(-12, -64), Pair(-26, -85), Pair(-9, -27), Pair(8, -137),
        Pair(4, -43), Pair(-30, -67), Pair(-8, -32), Pair(26, -61), Pair(-13, -77), Pair(31, -52), Pair(-23, -105), Pair(18, -60)
      },
      { // Piece 2
        Pair(-18, -28), Pair(-37, -19), Pair(29, -42), Pair(-22, -8), Pair(-47, -45), Pair(-71, -43), Pair(8, -43), Pair(3, -62),
        Pair(-37, -52), Pair(54, -48), Pair(-48, -43), Pair(-42, -28), Pair(-56, -15), Pair(-51, -48), Pair(17, -37), Pair(-39, -2),
        Pair(-21, -54), Pair(-13, -36), Pair(2, -32), Pair(-40, -36), Pair(-39, -33), Pair(25, -29), Pair(-75, -31), Pair(-25, -19),
        Pair(15, -10), Pair(-43, -8), Pair(-69, -18), Pair(58, -41), Pair(30, -19), Pair(23, -17), Pair(-52, -45), Pair(-32, -37),
        Pair(-26, -41), Pair(-25, -63), Pair(-8, -12), Pair(23, -52), Pair(-66, -34), Pair(18, -22), Pair(-4, -33), Pair(2, -20),
        Pair(27, -39), Pair(-68, -31), Pair(-82, -35), Pair(-36, -29), Pair(11, -40), Pair(-57, -19), Pair(-89, -14), Pair(-32, -21),
        Pair(-27, -27), Pair(20, -50), Pair(-63, -69), Pair(-51, -21), Pair(-54, -32), Pair(1, -61), Pair(-78, -47), Pair(-5, -64),
        Pair(-33, -61), Pair(-32, 18), Pair(30, -16), Pair(-29, -12), Pair(-32, -47), Pair(-7, -46), Pair(-25, -64), Pair(6, -22)
      },
      { // Piece 3
        Pair(64, -95), Pair(17, -85), Pair(-18, -72), Pair(-22, -82), Pair(-81, -61), Pair(-43, -88), Pair(-57, -64), Pair(-71, -68),
        Pair(-20, -89), Pair(40, -107), Pair(30, -92), Pair(-62, -78), Pair(31, -102), Pair(6, -94), Pair(-29, -89), Pair(37, -93),
        Pair(18, -86), Pair(-47, -78), Pair(-21, -70), Pair(23, -88), Pair(-34, -76), Pair(20, -103), Pair(-8, -73), Pair(-11, -80),
        Pair(20, -99), Pair(-35, -79), Pair(12, -104), Pair(6, -77), Pair(-15, -93), Pair(43, -106), Pair(12, -93), Pair(9, -84),
        Pair(-11, -87), Pair(-64, -86), Pair(-38, -91), Pair(-25, -126), Pair(23, -107), Pair(-2, -87), Pair(-14, -75), Pair(-33, -127),
        Pair(-14, -120), Pair(3, -103), Pair(-61, -64), Pair(39, -96), Pair(-38, -125), Pair(-107, -77), Pair(-14, -100), Pair(-14, -126),
        Pair(-22, -87), Pair(4, -111), Pair(-13, -94), Pair(-40, -102), Pair(-31, -90), Pair(-31, -105), Pair(-30, -89), Pair(-31, -93),
        Pair(19, -93), Pair(84, -97), Pair(-78, -65), Pair(16, -84), Pair(58, -98), Pair(-49, -87), Pair(-98, -72), Pair(-23, -80)
      },
      { // Piece 4
        Pair(-52, -134), Pair(-62, -62), Pair(1, -101), Pair(23, 11), Pair(4, -68), Pair(-44, -79), Pair(-75, -134), Pair(-17, -107),
        Pair(-19, -54), Pair(-26, -46), Pair(50, -10), Pair(-39, -41), Pair(10, -37), Pair(-53, -35), Pair(-56, -97), Pair(-48, -87),
        Pair(-66, -84), Pair(2, 19), Pair(-23, -29), Pair(27, -10), Pair(4, -17), Pair(75, 74), Pair(-36, -36), Pair(-26, -50),
        Pair(-52, -86), Pair(12, -42), Pair(-64, -49), Pair(-17, -38), Pair(-1, -2), Pair(-14, -8), Pair(-36, -34), Pair(-6, 3),
        Pair(17, 11), Pair(2, -16), Pair(-81, -95), Pair(-65, -91), Pair(-13, -4), Pair(-26, -52), Pair(0, -13), Pair(11, 21),
        Pair(-7, -18), Pair(-30, -75), Pair(-50, -95), Pair(17, 16), Pair(5, 9), Pair(-7, -27), Pair(-4, -12), Pair(4, -6),
        Pair(20, -8), Pair(22, 26), Pair(-10, -29), Pair(-16, -48), Pair(29, 41), Pair(5, 8), Pair(-22, -54), Pair(-5, -19),
        Pair(-50, -94), Pair(-5, -12), Pair(-54, -107), Pair(-20, -62), Pair(-26, -26), Pair(-8, -62), Pair(-18, -23), Pair(-5, -15)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(15, -55), Pair(84, -15), Pair(20, 13), Pair(-97, 44), Pair(-38, 31), Pair(-23, 23), Pair(-4, 6), Pair(-49, -24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-46, 23), Pair(-39, 49), Pair(13, 36), Pair(-19, 58), Pair(-66, 37), Pair(-57, 70), Pair(-14, 79), Pair(-52, 72),
        Pair(-88, 96), Pair(24, 141), Pair(-12, 113), Pair(-24, 99), Pair(15, 112), Pair(3, 91), Pair(11, 96), Pair(-37, 109),
        Pair(-106, 79), Pair(27, 74), Pair(-111, 55), Pair(-56, 46), Pair(-107, 57), Pair(55, 48), Pair(-51, 68), Pair(-154, 72),
        Pair(-17, 36), Pair(-49, 46), Pair(-16, 47), Pair(-30, 45), Pair(43, 19), Pair(-30, 37), Pair(-136, 45), Pair(-115, 33),
        Pair(-35, 32), Pair(52, 21), Pair(-7, 27), Pair(-77, 43), Pair(-91, 34), Pair(98, 1), Pair(-18, 26), Pair(4, 6),
        Pair(-83, 23), Pair(-46, 61), Pair(60, 23), Pair(-9, 18), Pair(-38, 3), Pair(-4, 29), Pair(-14, 32), Pair(-47, 28),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-17, -148), Pair(-13, -61), Pair(3, 22), Pair(18, 2), Pair(-10, -23), Pair(-11, -53), Pair(-20, -51), Pair(-3, -11),
        Pair(-7, -108), Pair(-3, -89), Pair(-24, -38), Pair(-9, -62), Pair(-19, -102), Pair(1, -111), Pair(-19, -45), Pair(-15, -133),
        Pair(-45, -145), Pair(-30, -45), Pair(8, -61), Pair(-31, -28), Pair(-12, -63), Pair(30, -92), Pair(13, -85), Pair(-21, -44),
        Pair(5, -37), Pair(5, -28), Pair(2, -41), Pair(13, -88), Pair(20, 4), Pair(39, -54), Pair(-9, -47), Pair(-46, -76),
        Pair(-34, -112), Pair(-15, -10), Pair(4, -12), Pair(70, -59), Pair(26, -8), Pair(-21, -58), Pair(-19, -46), Pair(12, -21),
        Pair(-1, -55), Pair(7, -13), Pair(-41, 22), Pair(36, -57), Pair(36, 6), Pair(-14, -58), Pair(10, -14), Pair(3, -85),
        Pair(-6, -50), Pair(2, -19), Pair(-19, -61), Pair(-9, -43), Pair(-12, -104), Pair(-27, -126), Pair(5, 4), Pair(-4, -7),
        Pair(-6, -73), Pair(-22, -74), Pair(-26, -138), Pair(1, -49), Pair(13, -30), Pair(-19, -157), Pair(-15, 0), Pair(-4, -39)
      },
      { // Piece 2
        Pair(-11, -84), Pair(14, 22), Pair(-27, -15), Pair(-44, -66), Pair(5, 3), Pair(-13, 18), Pair(37, -17), Pair(-9, -29),
        Pair(17, 65), Pair(-4, -20), Pair(36, 40), Pair(0, -60), Pair(-39, -47), Pair(30, 37), Pair(-34, 24), Pair(-28, -68),
        Pair(-11, -4), Pair(-7, 13), Pair(-43, -28), Pair(-41, 22), Pair(-5, 11), Pair(64, -36), Pair(19, 15), Pair(22, 3),
        Pair(-1, -32), Pair(21, -59), Pair(0, 14), Pair(-41, 25), Pair(-35, -13), Pair(-23, -9), Pair(-24, -9), Pair(-12, 6),
        Pair(2, -52), Pair(-40, -10), Pair(21, -22), Pair(44, -4), Pair(-6, 26), Pair(7, 1), Pair(5, 23), Pair(-5, 6),
        Pair(-26, -29), Pair(3, 39), Pair(16, -17), Pair(24, -43), Pair(-51, 15), Pair(-29, 9), Pair(24, -33), Pair(-6, 29),
        Pair(0, 65), Pair(7, 11), Pair(-19, 42), Pair(-15, 15), Pair(27, 0), Pair(-22, -48), Pair(16, 16), Pair(0, -29),
        Pair(-7, -50), Pair(2, 62), Pair(-6, -18), Pair(-7, 38), Pair(9, -22), Pair(-3, -34), Pair(1, 23), Pair(-11, -71)
      },
      { // Piece 3
        Pair(2, -37), Pair(20, -11), Pair(25, -46), Pair(-14, -32), Pair(-30, -59), Pair(10, -10), Pair(-21, -39), Pair(-22, -47),
        Pair(37, -45), Pair(-70, -50), Pair(27, -64), Pair(-4, -48), Pair(39, -88), Pair(8, -68), Pair(-20, -76), Pair(1, -71),
        Pair(-16, -40), Pair(2, -35), Pair(-34, -41), Pair(-63, -12), Pair(-56, -42), Pair(-57, -39), Pair(-14, -70), Pair(16, -76),
        Pair(-44, -46), Pair(27, -49), Pair(8, -52), Pair(31, -47), Pair(9, -44), Pair(24, -33), Pair(4, -22), Pair(-18, -52),
        Pair(4, -69), Pair(-34, -92), Pair(-20, 13), Pair(-21, -96), Pair(-2, -96), Pair(-59, -71), Pair(-4, -58), Pair(32, -101),
        Pair(-59, -31), Pair(-54, -27), Pair(-5, -54), Pair(-1, -94), Pair(-10, -104), Pair(9, -72), Pair(-47, -53), Pair(10, -114),
        Pair(43, -20), Pair(44, 15), Pair(2, -72), Pair(19, -81), Pair(8, -56), Pair(-25, -60), Pair(5, -71), Pair(0, -26),
        Pair(-26, -23), Pair(13, -42), Pair(-15, -2), Pair(-41, -102), Pair(2, -91), Pair(13, -25), Pair(60, -14), Pair(-7, -66)
      },
      { // Piece 4
        Pair(-70, -51), Pair(-39, -48), Pair(-11, 31), Pair(-12, 20), Pair(-8, -6), Pair(-40, -45), Pair(-47, -125), Pair(-22, -69),
        Pair(-20, -26), Pair(-12, -49), Pair(-32, -81), Pair(-30, -40), Pair(-10, 34), Pair(-42, -64), Pair(2, -5), Pair(-39, -58),
        Pair(7, -34), Pair(-39, -86), Pair(45, 79), Pair(-60, -62), Pair(8, 1), Pair(-1, 39), Pair(-45, -70), Pair(-33, -48),
        Pair(20, 25), Pair(-45, -59), Pair(6, -12), Pair(-8, -24), Pair(21, 33), Pair(-25, -41), Pair(4, 30), Pair(-22, 28),
        Pair(9, 2), Pair(-41, -97), Pair(-48, -93), Pair(-18, -56), Pair(12, -12), Pair(4, -9), Pair(-26, -33), Pair(-27, -56),
        Pair(-37, -80), Pair(-4, -1), Pair(10, 26), Pair(-6, -41), Pair(43, 45), Pair(-32, -28), Pair(-13, -39), Pair(-13, -54),
        Pair(9, 19), Pair(-13, -26), Pair(-14, -37), Pair(4, -7), Pair(22, 39), Pair(-42, -78), Pair(-13, -25), Pair(14, 14),
        Pair(-20, -47), Pair(-36, -66), Pair(-12, -33), Pair(-8, -22), Pair(-3, 9), Pair(-6, -34), Pair(32, 45), Pair(-49, -77)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-47, -14), Pair(14, 9), Pair(54, 35), Pair(5, 55), Pair(-36, 47), Pair(-69, 56), Pair(-10, 34), Pair(-103, 23),
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
        Pair(166, -60), Pair(107, -63), Pair(160, 154), Pair(32, 74), Pair(-133, 92), Pair(41, 24), Pair(-52, -95), Pair(-11, -107),
        Pair(171, -13), Pair(102, 28), Pair(-5, 79), Pair(-81, 98), Pair(85, 67), Pair(65, 11), Pair(173, -35), Pair(92, -50),
        Pair(-85, 52), Pair(-19, 53), Pair(9, 42), Pair(-39, 32), Pair(4, 23), Pair(70, -4), Pair(-33, 15), Pair(-40, -6),
        Pair(-125, 48), Pair(-88, 52), Pair(-46, 22), Pair(-31, 9), Pair(-75, 12), Pair(13, -3), Pair(-72, 23), Pair(-38, -13),
        Pair(-111, 23), Pair(-101, 32), Pair(-57, 13), Pair(2, -15), Pair(-49, 12), Pair(-52, 17), Pair(-97, 33), Pair(-24, -11),
        Pair(-144, 31), Pair(-71, 31), Pair(-23, 19), Pair(-122, 9), Pair(-146, 42), Pair(-82, 10), Pair(-23, 3), Pair(-32, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-60, -152), Pair(12, -13), Pair(44, -12), Pair(11, -55), Pair(-30, -22), Pair(-32, -62), Pair(-15, -50), Pair(3, 32),
        Pair(13, -58), Pair(99, 15), Pair(31, -57), Pair(-9, -10), Pair(147, -67), Pair(-23, 26), Pair(-14, -31), Pair(-32, -23),
        Pair(-13, -72), Pair(31, 16), Pair(73, -62), Pair(105, -3), Pair(198, -34), Pair(127, -10), Pair(104, 22), Pair(8, -66),
        Pair(-26, -45), Pair(-22, -29), Pair(79, 3), Pair(42, 4), Pair(71, -7), Pair(126, -11), Pair(44, -2), Pair(94, -9),
        Pair(-93, 3), Pair(-36, -18), Pair(70, 7), Pair(49, -12), Pair(131, -5), Pair(14, -1), Pair(62, -4), Pair(49, -44),
        Pair(-17, -102), Pair(-61, -34), Pair(-20, 8), Pair(-65, 21), Pair(21, -31), Pair(64, -3), Pair(48, -41), Pair(-43, -87),
        Pair(-60, -106), Pair(-48, -27), Pair(-80, -76), Pair(-105, -30), Pair(-65, -25), Pair(-12, -86), Pair(23, -36), Pair(-31, -67),
        Pair(-15, -38), Pair(-32, -67), Pair(-122, -139), Pair(-40, 48), Pair(-41, -28), Pair(-53, -88), Pair(-150, -39), Pair(-38, -35)
      },
      { // Piece 2
        Pair(-26, -1), Pair(22, -34), Pair(-7, -51), Pair(-40, -21), Pair(-44, -24), Pair(-2, -27), Pair(68, -34), Pair(-8, -40),
        Pair(-96, -7), Pair(13, -21), Pair(-2, -31), Pair(-13, -75), Pair(48, -57), Pair(17, -14), Pair(-51, -50), Pair(28, -30),
        Pair(23, -54), Pair(-34, -33), Pair(71, -68), Pair(80, -3), Pair(38, -31), Pair(116, -11), Pair(188, -37), Pair(52, -7),
        Pair(-39, -3), Pair(-19, -28), Pair(-21, -16), Pair(133, -44), Pair(61, -26), Pair(74, -13), Pair(29, -29), Pair(-11, 14),
        Pair(-49, -6), Pair(7, -38), Pair(111, -22), Pair(98, -50), Pair(87, -43), Pair(-74, 19), Pair(110, -66), Pair(18, -4),
        Pair(-56, 14), Pair(83, -3), Pair(85, -55), Pair(-63, 3), Pair(109, -64), Pair(13, -54), Pair(112, -23), Pair(6, -62),
        Pair(15, -29), Pair(-135, -20), Pair(4, -69), Pair(-85, -25), Pair(0, -15), Pair(-151, -40), Pair(-88, -50), Pair(-63, -68),
        Pair(-49, -35), Pair(-44, -39), Pair(-194, 26), Pair(-77, -37), Pair(-41, -3), Pair(-112, -28), Pair(-33, -54), Pair(-11, -46)
      },
      { // Piece 3
        Pair(48, 34), Pair(-63, 11), Pair(-25, 23), Pair(20, 10), Pair(-26, 19), Pair(37, 45), Pair(22, 57), Pair(3, 22),
        Pair(2, 8), Pair(-28, 18), Pair(60, 3), Pair(102, -20), Pair(75, -26), Pair(28, -3), Pair(61, 9), Pair(86, -8),
        Pair(-28, 6), Pair(13, -14), Pair(47, -1), Pair(46, -10), Pair(62, -13), Pair(105, -32), Pair(46, -23), Pair(-55, -15),
        Pair(-13, 3), Pair(-49, 0), Pair(20, -2), Pair(90, -13), Pair(-31, -14), Pair(136, -50), Pair(-53, -19), Pair(11, -6),
        Pair(-96, 13), Pair(-71, 38), Pair(-52, -10), Pair(-31, -28), Pair(-11, -27), Pair(-28, -3), Pair(7, -2), Pair(-39, -18),
        Pair(-117, 5), Pair(-13, -9), Pair(-95, 30), Pair(-10, -38), Pair(-10, -19), Pair(-40, -7), Pair(-10, 14), Pair(-138, 1),
        Pair(-109, 38), Pair(-142, 8), Pair(-72, 2), Pair(-59, 2), Pair(-65, 7), Pair(-93, 16), Pair(-83, -4), Pair(-44, 8),
        Pair(-237, 62), Pair(-214, 55), Pair(-134, 33), Pair(-31, 6), Pair(-124, 12), Pair(-89, 1), Pair(-160, 25), Pair(-183, 17)
      },
      { // Piece 4
        Pair(-127, -119), Pair(-86, -49), Pair(-42, 11), Pair(48, 87), Pair(51, 83), Pair(-27, 30), Pair(29, 55), Pair(-16, -30),
        Pair(-103, 13), Pair(-44, -41), Pair(-82, 46), Pair(-29, 44), Pair(-89, -2), Pair(92, -19), Pair(-8, 7), Pair(7, 17),
        Pair(-53, -36), Pair(-19, 6), Pair(-4, 6), Pair(29, -43), Pair(52, 27), Pair(60, -64), Pair(-96, 23), Pair(51, -109),
        Pair(-110, -52), Pair(-58, 48), Pair(-5, 15), Pair(0, -34), Pair(-42, 8), Pair(-48, -9), Pair(-69, -42), Pair(-107, -75),
        Pair(-81, 43), Pair(-23, 13), Pair(-104, -34), Pair(-66, 29), Pair(-83, 44), Pair(8, -33), Pair(-86, -14), Pair(-71, -33),
        Pair(-80, -66), Pair(-61, 24), Pair(-15, 35), Pair(-37, -97), Pair(-66, 58), Pair(-121, 14), Pair(-86, -15), Pair(9, -9),
        Pair(-54, -19), Pair(-55, -40), Pair(-83, -36), Pair(-79, -58), Pair(-92, -56), Pair(-122, -73), Pair(-59, -31), Pair(-93, -137),
        Pair(-94, -90), Pair(-155, -136), Pair(-51, -85), Pair(-157, -46), Pair(-45, -29), Pair(-58, -90), Pair(-163, -125), Pair(-16, -16)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-92, -18), Pair(110, 3), Pair(-14, 17), Pair(57, -2), Pair(-21, 9), Pair(65, -2), Pair(83, -11), Pair(-45, -39),
        Pair(-57, -41), Pair(117, -38), Pair(21, -10), Pair(30, -8), Pair(-75, 6), Pair(-18, -3), Pair(-5, -21), Pair(-52, -57),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(19, 30), Pair(79, 21), Pair(118, -100), Pair(89, -124), Pair(112, -126), Pair(167, -106), Pair(-9, 117), Pair(48, 9),
        Pair(4, 66), Pair(58, 33), Pair(158, -15), Pair(128, -14), Pair(134, -41), Pair(158, -20), Pair(115, 16), Pair(-32, 60),
        Pair(-73, 37), Pair(-120, 53), Pair(-46, 24), Pair(43, -2), Pair(38, -8), Pair(33, -2), Pair(-25, 34), Pair(-53, 25),
        Pair(-103, 19), Pair(-137, 49), Pair(5, -13), Pair(-4, -11), Pair(-92, 6), Pair(5, -7), Pair(-33, 25), Pair(-104, 8),
        Pair(-116, 8), Pair(-112, 29), Pair(-102, 10), Pair(-106, 13), Pair(11, -14), Pair(17, -17), Pair(-18, 5), Pair(-68, -2),
        Pair(-114, 24), Pair(-118, 24), Pair(-23, -4), Pair(-23, 9), Pair(-23, -3), Pair(-27, 3), Pair(-102, 22), Pair(-117, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-37, -121), Pair(-15, -45), Pair(10, -21), Pair(2, -96), Pair(3, -44), Pair(-4, -68), Pair(2, -63), Pair(-11, -19),
        Pair(-84, -89), Pair(36, 20), Pair(18, -3), Pair(-33, -52), Pair(-4, -6), Pair(0, -40), Pair(15, 39), Pair(-64, -53),
        Pair(6, -32), Pair(55, -25), Pair(86, -19), Pair(-7, 0), Pair(37, -20), Pair(178, -37), Pair(-51, -22), Pair(15, -62),
        Pair(-37, 30), Pair(12, -19), Pair(56, -11), Pair(36, -1), Pair(0, 5), Pair(32, 21), Pair(51, -5), Pair(-52, -42),
        Pair(15, -12), Pair(-56, 6), Pair(90, 6), Pair(102, -12), Pair(87, -1), Pair(-5, -19), Pair(51, -40), Pair(4, -12),
        Pair(-50, -69), Pair(-86, -2), Pair(-53, -19), Pair(-3, 3), Pair(-87, 41), Pair(12, -22), Pair(-42, -30), Pair(37, -96),
        Pair(-28, -29), Pair(-31, -23), Pair(-45, -38), Pair(-75, -22), Pair(-3, -19), Pair(14, -26), Pair(6, -86), Pair(-38, -76),
        Pair(-18, -35), Pair(-80, -10), Pair(-29, -10), Pair(-74, -30), Pair(30, -21), Pair(-75, -91), Pair(-131, 8), Pair(-3, 15)
      },
      { // Piece 2
        Pair(-46, -59), Pair(-17, -101), Pair(16, -50), Pair(-19, -48), Pair(7, -71), Pair(33, -56), Pair(6, -41), Pair(-29, -64),
        Pair(-14, -36), Pair(24, -22), Pair(46, -38), Pair(14, -36), Pair(21, -68), Pair(25, -52), Pair(22, -74), Pair(-41, -48),
        Pair(-36, -39), Pair(-31, -50), Pair(30, -64), Pair(38, -59), Pair(169, -78), Pair(165, -36), Pair(55, -23), Pair(76, -55),
        Pair(-34, -60), Pair(101, -65), Pair(94, -46), Pair(119, -68), Pair(145, -71), Pair(44, -46), Pair(24, -41), Pair(-37, -39),
        Pair(16, -58), Pair(-34, -59), Pair(-6, -37), Pair(-19, -42), Pair(15, -50), Pair(51, -41), Pair(51, -47), Pair(31, -4),
        Pair(17, -15), Pair(23, -27), Pair(-12, -35), Pair(35, -49), Pair(25, -42), Pair(4, -45), Pair(66, -43), Pair(27, 3),
        Pair(-54, -52), Pair(-71, -30), Pair(-70, -46), Pair(71, -53), Pair(-5, -37), Pair(-81, -56), Pair(75, -38), Pair(-18, -5),
        Pair(25, -60), Pair(22, -96), Pair(-89, 10), Pair(-57, -11), Pair(-102, -10), Pair(-78, -29), Pair(-26, -75), Pair(-15, -83)
      },
      { // Piece 3
        Pair(-39, -7), Pair(25, 57), Pair(-14, 35), Pair(-11, 18), Pair(-17, -39), Pair(-10, 8), Pair(-5, -3), Pair(52, -5),
        Pair(170, -47), Pair(123, -30), Pair(117, -30), Pair(135, -42), Pair(89, -57), Pair(142, -41), Pair(129, -39), Pair(66, -12),
        Pair(55, -2), Pair(7, -13), Pair(47, -33), Pair(18, -15), Pair(94, -48), Pair(134, -62), Pair(36, -31), Pair(45, -42),
        Pair(1, -26), Pair(1, -13), Pair(23, -25), Pair(4, -39), Pair(17, -21), Pair(78, -55), Pair(-132, 9), Pair(69, -51),
        Pair(-100, -8), Pair(-45, -17), Pair(16, -6), Pair(-12, -3), Pair(12, -32), Pair(-33, -2), Pair(68, -32), Pair(-2, -10),
        Pair(-19, -39), Pair(-80, -7), Pair(17, -44), Pair(-29, -26), Pair(-25, -33), Pair(6, -37), Pair(32, -28), Pair(-27, -47),
        Pair(-23, -29), Pair(-61, -43), Pair(-110, -32), Pair(8, -17), Pair(-6, -50), Pair(6, -25), Pair(-17, 6), Pair(-19, -34),
        Pair(-168, -14), Pair(-171, 23), Pair(-92, -23), Pair(-100, -4), Pair(-91, -11), Pair(-67, -32), Pair(-98, -22), Pair(-116, -2)
      },
      { // Piece 4
        Pair(-126, -86), Pair(-77, -28), Pair(34, 38), Pair(23, 47), Pair(-31, -46), Pair(22, 28), Pair(39, 60), Pair(31, 52),
        Pair(-72, -20), Pair(-86, -87), Pair(6, 23), Pair(21, 68), Pair(3, -3), Pair(25, 8), Pair(0, -68), Pair(15, 19),
        Pair(-35, -69), Pair(-22, -59), Pair(13, 8), Pair(22, 45), Pair(20, 0), Pair(21, -31), Pair(-61, -68), Pair(-31, -54),
        Pair(-75, -48), Pair(-51, -70), Pair(16, -19), Pair(72, -19), Pair(-4, -45), Pair(-14, 13), Pair(-4, -45), Pair(-15, -37),
        Pair(5, 2), Pair(12, 30), Pair(-23, -6), Pair(23, 9), Pair(26, 66), Pair(-37, -98), Pair(-57, -50), Pair(-25, -12),
        Pair(-59, -7), Pair(-55, -72), Pair(-80, -66), Pair(-99, 51), Pair(-17, 24), Pair(-27, -38), Pair(-24, -44), Pair(-31, -22),
        Pair(-57, -109), Pair(-20, -30), Pair(-51, -77), Pair(-70, -62), Pair(-2, -50), Pair(-54, -37), Pair(-20, 41), Pair(2, 12),
        Pair(-31, -60), Pair(-93, -109), Pair(-9, 42), Pair(-233, -164), Pair(-41, -20), Pair(4, 22), Pair(-26, -4), Pair(11, 44)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, -50), Pair(113, -29), Pair(-13, 2), Pair(10, 12), Pair(41, 8), Pair(94, -4), Pair(89, -27), Pair(-48, -32),
        Pair(2, -53), Pair(116, -56), Pair(17, -18), Pair(-34, -4), Pair(-22, -13), Pair(20, -24), Pair(49, -45), Pair(-42, -49),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(132, -72), Pair(216, -80), Pair(183, -37), Pair(223, -74), Pair(2, -28), Pair(87, -58), Pair(-14, -9), Pair(211, -66),
        Pair(67, 13), Pair(202, 14), Pair(268, -25), Pair(197, -39), Pair(186, -41), Pair(163, -27), Pair(149, -18), Pair(0, 12),
        Pair(-65, 35), Pair(-38, 42), Pair(38, 17), Pair(-38, 14), Pair(23, 6), Pair(25, 3), Pair(23, 16), Pair(-56, 13),
        Pair(-108, 37), Pair(-92, 45), Pair(-18, 14), Pair(-22, 3), Pair(-16, 4), Pair(-51, 7), Pair(-71, 25), Pair(-118, 18),
        Pair(-122, 27), Pair(-97, 25), Pair(-68, 7), Pair(-62, 9), Pair(-31, 0), Pair(-35, -3), Pair(-46, 13), Pair(-130, 14),
        Pair(-144, 42), Pair(-118, 40), Pair(-78, 19), Pair(-72, 51), Pair(-36, 20), Pair(-63, 11), Pair(-70, 26), Pair(-179, 30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-15, -71), Pair(-16, -127), Pair(45, -75), Pair(-42, -71), Pair(38, -39), Pair(-40, -61), Pair(-63, -110), Pair(-19, -102),
        Pair(-51, -65), Pair(-8, -62), Pair(19, -38), Pair(100, -41), Pair(63, -33), Pair(39, -41), Pair(23, -43), Pair(-42, -84),
        Pair(-75, -49), Pair(-18, -39), Pair(69, -33), Pair(92, -30), Pair(181, -68), Pair(40, -38), Pair(119, -68), Pair(63, -61),
        Pair(11, -57), Pair(56, -31), Pair(106, -31), Pair(95, -33), Pair(87, -22), Pair(87, -30), Pair(9, -31), Pair(-42, -44),
        Pair(-116, -14), Pair(51, -33), Pair(32, -27), Pair(68, -13), Pair(122, -16), Pair(12, -14), Pair(42, -41), Pair(64, -40),
        Pair(-107, -49), Pair(-69, -17), Pair(-55, -20), Pair(33, -26), Pair(-51, -8), Pair(-67, -12), Pair(-71, -22), Pair(6, -51),
        Pair(-79, 14), Pair(-31, -29), Pair(-88, -25), Pair(-62, -23), Pair(-110, 1), Pair(10, -35), Pair(-38, -37), Pair(9, -29),
        Pair(-24, -77), Pair(-149, -28), Pair(-99, -37), Pair(-103, -26), Pair(-67, -52), Pair(-123, -10), Pair(-64, -47), Pair(-13, -33)
      },
      { // Piece 2
        Pair(-12, -62), Pair(45, -60), Pair(74, -70), Pair(5, -52), Pair(47, -91), Pair(-37, -74), Pair(2, -79), Pair(0, -45),
        Pair(-66, -60), Pair(97, -69), Pair(61, -74), Pair(85, -78), Pair(76, -78), Pair(14, -58), Pair(122, -38), Pair(-14, -66),
        Pair(-117, -40), Pair(-37, -48), Pair(-8, -49), Pair(139, -82), Pair(100, -82), Pair(127, -74), Pair(133, -87), Pair(-19, -58),
        Pair(27, -82), Pair(117, -81), Pair(156, -72), Pair(167, -84), Pair(116, -70), Pair(151, -85), Pair(96, -71), Pair(27, -89),
        Pair(-127, -39), Pair(-63, -43), Pair(144, -66), Pair(93, -65), Pair(152, -79), Pair(206, -80), Pair(46, -69), Pair(-46, -33),
        Pair(1, -36), Pair(84, -64), Pair(13, -49), Pair(134, -73), Pair(122, -65), Pair(123, -76), Pair(-59, -25), Pair(-84, -44),
        Pair(-42, -41), Pair(6, -64), Pair(-5, -62), Pair(-3, -44), Pair(87, -70), Pair(-49, -61), Pair(-96, -37), Pair(-20, -74),
        Pair(-92, -26), Pair(20, -49), Pair(-88, -15), Pair(-66, -49), Pair(-68, -15), Pair(-139, -31), Pair(19, -53), Pair(-46, -54)
      },
      { // Piece 3
        Pair(18, -38), Pair(130, -65), Pair(40, -39), Pair(33, -32), Pair(-101, -23), Pair(72, -57), Pair(104, -65), Pair(26, -40),
        Pair(-58, -33), Pair(-17, -26), Pair(-6, -46), Pair(58, -54), Pair(24, -63), Pair(17, -80), Pair(15, -61), Pair(73, -69),
        Pair(-1, -54), Pair(27, -51), Pair(155, -88), Pair(96, -83), Pair(129, -96), Pair(58, -69), Pair(134, -86), Pair(17, -61),
        Pair(-16, -48), Pair(59, -64), Pair(-107, -18), Pair(30, -72), Pair(59, -82), Pair(6, -62), Pair(19, -54), Pair(10, -56),
        Pair(-19, -61), Pair(-95, -32), Pair(3, -57), Pair(-3, -43), Pair(14, -47), Pair(-1, -56), Pair(-80, -45), Pair(-143, -26),
        Pair(-11, -74), Pair(-71, -43), Pair(-123, -44), Pair(-11, -52), Pair(-45, -66), Pair(-61, -59), Pair(-45, -47), Pair(-102, -50),
        Pair(-107, -45), Pair(-76, -58), Pair(-66, -38), Pair(-13, -72), Pair(-77, -60), Pair(2, -88), Pair(-145, -42), Pair(-112, -50),
        Pair(-209, -11), Pair(-98, -32), Pair(-158, -28), Pair(-121, -37), Pair(-87, -53), Pair(-22, -74), Pair(-86, -45), Pair(-195, -3)
      },
      { // Piece 4
        Pair(-82, -166), Pair(-89, -91), Pair(-33, -131), Pair(-89, -67), Pair(-103, -57), Pair(-122, -85), Pair(-138, -120), Pair(-74, -142),
        Pair(-82, -65), Pair(-31, -107), Pair(-15, -21), Pair(-49, -34), Pair(-26, -23), Pair(-16, -43), Pair(0, 23), Pair(-43, -64),
        Pair(-66, -85), Pair(-46, -87), Pair(-70, -6), Pair(-74, -69), Pair(-50, -46), Pair(-65, -75), Pair(-10, -87), Pair(-56, -80),
        Pair(-18, -86), Pair(-61, -103), Pair(-44, -43), Pair(-47, -49), Pair(-87, -15), Pair(-73, -41), Pair(-120, -56), Pair(-54, -43),
        Pair(-126, -131), Pair(-114, -99), Pair(-91, -40), Pair(-81, -42), Pair(-33, -38), Pair(-100, -106), Pair(-86, -34), Pair(-27, -88),
        Pair(-56, -80), Pair(-73, -22), Pair(-51, -61), Pair(-28, -77), Pair(-164, -38), Pair(-53, -131), Pair(-95, -130), Pair(-125, -63),
        Pair(-80, -57), Pair(-44, -53), Pair(-93, -96), Pair(-24, -99), Pair(-134, -97), Pair(-138, -94), Pair(-2, -15), Pair(-134, -175),
        Pair(-105, -195), Pair(-65, -52), Pair(-82, -141), Pair(-67, -118), Pair(-81, -106), Pair(-61, -25), Pair(-44, -84), Pair(-83, -120)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(19, -34), Pair(120, -13), Pair(30, 8), Pair(-50, 22), Pair(-35, 10), Pair(25, 7), Pair(25, 3), Pair(-17, -24),
        Pair(19, -47), Pair(72, -29), Pair(23, -4), Pair(-67, 14), Pair(-64, 7), Pair(-1, -8), Pair(15, -29), Pair(-64, -38),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(42, 17), Pair(124, -2), Pair(113, 26), Pair(95, 11), Pair(38, -1), Pair(106, 6), Pair(20, 36), Pair(105, 17),
        Pair(87, 30), Pair(69, 53), Pair(89, 31), Pair(93, 31), Pair(123, 13), Pair(23, 35), Pair(73, 45), Pair(97, 29),
        Pair(-75, 48), Pair(-68, 58), Pair(71, 16), Pair(35, 5), Pair(6, 3), Pair(116, -15), Pair(71, 20), Pair(-44, 22),
        Pair(-78, 33), Pair(-81, 46), Pair(-66, 33), Pair(-66, 37), Pair(-67, 22), Pair(-35, 18), Pair(-50, 37), Pair(-98, 23),
        Pair(-120, 26), Pair(-55, 27), Pair(-22, 11), Pair(-57, 25), Pair(-1, -2), Pair(-41, 2), Pair(-57, 20), Pair(-109, 22),
        Pair(-145, 39), Pair(-115, 43), Pair(-68, 23), Pair(-67, 35), Pair(-44, 11), Pair(-95, 29), Pair(-120, 44), Pair(-164, 48),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-15, -130), Pair(21, -123), Pair(1, -44), Pair(5, -93), Pair(14, -94), Pair(18, -73), Pair(-32, -55), Pair(0, -82),
        Pair(-30, -103), Pair(-45, -56), Pair(-41, -61), Pair(60, -56), Pair(-4, -69), Pair(33, -88), Pair(6, -96), Pair(19, -60),
        Pair(1, -79), Pair(39, -91), Pair(61, -44), Pair(35, -42), Pair(152, -62), Pair(56, -40), Pair(-20, -62), Pair(32, -91),
        Pair(54, -57), Pair(-28, -59), Pair(94, -52), Pair(27, -27), Pair(-12, -37), Pair(26, -32), Pair(-31, -72), Pair(-7, -95),
        Pair(-16, -67), Pair(-9, -55), Pair(30, -18), Pair(109, -40), Pair(-51, -4), Pair(36, -44), Pair(21, -53), Pair(23, -81),
        Pair(54, -45), Pair(-25, -46), Pair(24, -16), Pair(83, -32), Pair(-43, -18), Pair(-24, -23), Pair(-3, -57), Pair(-39, -99),
        Pair(-9, -73), Pair(-57, -64), Pair(-2, -62), Pair(-40, -33), Pair(41, -42), Pair(-41, -38), Pair(18, -22), Pair(-25, -42),
        Pair(-23, -118), Pair(-71, -87), Pair(-103, 14), Pair(-71, -18), Pair(-64, -65), Pair(-55, -95), Pair(-33, -73), Pair(-30, -53)
      },
      { // Piece 2
        Pair(-42, -62), Pair(5, -77), Pair(33, -77), Pair(23, -69), Pair(-39, -89), Pair(24, -61), Pair(-8, -77), Pair(26, -48),
        Pair(-8, -57), Pair(13, -65), Pair(12, -73), Pair(87, -96), Pair(56, -100), Pair(110, -95), Pair(32, -86), Pair(-42, -42),
        Pair(-42, -45), Pair(89, -70), Pair(110, -81), Pair(84, -69), Pair(143, -86), Pair(45, -55), Pair(7, -85), Pair(-9, -43),
        Pair(0, -62), Pair(28, -59), Pair(113, -71), Pair(79, -65), Pair(143, -71), Pair(101, -78), Pair(58, -87), Pair(33, -61),
        Pair(18, -48), Pair(61, -49), Pair(32, -65), Pair(146, -77), Pair(87, -57), Pair(97, -56), Pair(62, -72), Pair(-57, -42),
        Pair(-93, -66), Pair(-14, -52), Pair(45, -67), Pair(-37, -55), Pair(21, -63), Pair(59, -71), Pair(-48, -39), Pair(-55, -39),
        Pair(16, -47), Pair(32, -37), Pair(46, -82), Pair(-22, -54), Pair(49, -67), Pair(-26, -51), Pair(-107, -24), Pair(-27, -56),
        Pair(-18, -43), Pair(-19, -56), Pair(-93, -31), Pair(35, -60), Pair(20, -58), Pair(95, -63), Pair(7, -66), Pair(13, -30)
      },
      { // Piece 3
        Pair(-5, -68), Pair(5, -55), Pair(63, -88), Pair(55, -66), Pair(-53, -40), Pair(-13, -63), Pair(-9, -61), Pair(94, -84),
        Pair(54, -91), Pair(22, -67), Pair(99, -101), Pair(-8, -84), Pair(160, -102), Pair(48, -93), Pair(118, -126), Pair(-2, -78),
        Pair(8, -85), Pair(-48, -58), Pair(-18, -79), Pair(-3, -91), Pair(-7, -75), Pair(27, -64), Pair(-29, -53), Pair(37, -104),
        Pair(-10, -65), Pair(17, -76), Pair(41, -82), Pair(57, -91), Pair(12, -83), Pair(70, -83), Pair(-9, -85), Pair(15, -86),
        Pair(-38, -71), Pair(-6, -72), Pair(-22, -73), Pair(33, -62), Pair(-17, -87), Pair(3, -82), Pair(2, -58), Pair(45, -93),
        Pair(-86, -86), Pair(-48, -81), Pair(19, -95), Pair(-70, -59), Pair(-74, -77), Pair(-23, -80), Pair(-65, -74), Pair(-37, -93),
        Pair(-108, -53), Pair(0, -82), Pair(1, -85), Pair(-61, -71), Pair(67, -113), Pair(40, -98), Pair(-21, -89), Pair(-59, -64),
        Pair(-136, -39), Pair(8, -64), Pair(-14, -78), Pair(-55, -61), Pair(-1, -75), Pair(-27, -80), Pair(-39, -59), Pair(-151, -53)
      },
      { // Piece 4
        Pair(1, -106), Pair(-31, -76), Pair(-24, -39), Pair(8, -81), Pair(-25, -33), Pair(-15, -53), Pair(-24, -70), Pair(-48, -133),
        Pair(-45, -110), Pair(-34, 4), Pair(13, -77), Pair(-4, -65), Pair(34, -21), Pair(-39, -52), Pair(-2, 1), Pair(-74, -91),
        Pair(-25, -56), Pair(-14, -27), Pair(0, 95), Pair(14, -33), Pair(-30, -77), Pair(39, -6), Pair(-45, -88), Pair(-54, -73),
        Pair(-50, -102), Pair(-74, -148), Pair(39, 18), Pair(24, -24), Pair(41, -33), Pair(-36, -72), Pair(-61, -100), Pair(-51, -81),
        Pair(-24, -26), Pair(-25, -22), Pair(-35, -9), Pair(52, 53), Pair(-24, -3), Pair(-22, -48), Pair(-40, -78), Pair(-57, -55),
        Pair(-64, -98), Pair(15, 10), Pair(-21, -68), Pair(8, -22), Pair(27, 23), Pair(-5, -41), Pair(-41, -93), Pair(-7, -15),
        Pair(-62, -132), Pair(-17, -40), Pair(10, -65), Pair(-24, -11), Pair(-23, -101), Pair(-36, -47), Pair(-25, -56), Pair(1, -42),
        Pair(-4, -35), Pair(-26, -43), Pair(6, 3), Pair(-85, -151), Pair(-7, -79), Pair(-41, -49), Pair(-20, -33), Pair(-2, -26)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(38, -35), Pair(103, -9), Pair(-10, 19), Pair(-30, 20), Pair(-67, 24), Pair(51, 10), Pair(34, 8), Pair(-37, -29),
        Pair(67, -38), Pair(92, -25), Pair(59, 3), Pair(-59, 19), Pair(-37, 8), Pair(-56, 16), Pair(50, -24), Pair(-62, -26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-150, 39), Pair(-49, 53), Pair(60, 58), Pair(25, 33), Pair(12, 9), Pair(-56, 52), Pair(-59, 78), Pair(-124, 40),
        Pair(-106, 87), Pair(86, 80), Pair(-38, 91), Pair(35, 89), Pair(-52, 80), Pair(47, 72), Pair(-12, 83), Pair(-1, 72),
        Pair(-108, 54), Pair(-15, 62), Pair(-15, 40), Pair(-19, 55), Pair(13, 34), Pair(-34, 48), Pair(-116, 62), Pair(-79, 52),
        Pair(-119, 50), Pair(-72, 53), Pair(19, 16), Pair(-1, 15), Pair(5, 7), Pair(-16, 19), Pair(-49, 41), Pair(-147, 38),
        Pair(-148, 36), Pair(-93, 37), Pair(-88, 32), Pair(68, 27), Pair(-59, 32), Pair(-40, 23), Pair(-66, 34), Pair(-108, 24),
        Pair(-153, 50), Pair(-110, 52), Pair(-62, 28), Pair(-5, 38), Pair(-45, 27), Pair(-63, 39), Pair(-110, 42), Pair(-60, 35),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-2, -107), Pair(31, -121), Pair(-19, -64), Pair(16, -106), Pair(44, -85), Pair(-20, -93), Pair(-64, -123), Pair(-8, -142),
        Pair(-43, -134), Pair(32, -70), Pair(17, -85), Pair(86, -97), Pair(-29, -69), Pair(-3, -107), Pair(-66, -85), Pair(-61, -83),
        Pair(-51, -118), Pair(24, -61), Pair(-31, -36), Pair(49, -74), Pair(25, -52), Pair(-12, -62), Pair(-38, -97), Pair(-47, -120),
        Pair(-18, -78), Pair(30, -50), Pair(17, -44), Pair(42, -42), Pair(82, -46), Pair(72, -50), Pair(-42, -82), Pair(-57, -44),
        Pair(-17, -87), Pair(-7, -38), Pair(2, -54), Pair(15, -52), Pair(62, -45), Pair(44, -45), Pair(-28, -24), Pair(1, -94),
        Pair(-37, -92), Pair(6, -46), Pair(1, -76), Pair(-17, -44), Pair(41, -32), Pair(24, -68), Pair(-56, -40), Pair(-5, -46),
        Pair(-24, -52), Pair(-47, -67), Pair(9, -58), Pair(-19, -34), Pair(0, -29), Pair(-18, -43), Pair(11, -24), Pair(-5, 10),
        Pair(-30, -44), Pair(-43, -53), Pair(-37, -67), Pair(-35, -52), Pair(10, -45), Pair(-24, -63), Pair(17, -84), Pair(-12, -60)
      },
      { // Piece 2
        Pair(-33, -97), Pair(78, -43), Pair(-49, -50), Pair(-13, -73), Pair(-52, -69), Pair(-46, -58), Pair(-11, -124), Pair(7, -88),
        Pair(20, -61), Pair(16, -52), Pair(33, -65), Pair(-24, -90), Pair(64, -62), Pair(8, -81), Pair(22, -75), Pair(-21, -25),
        Pair(59, -80), Pair(41, -48), Pair(22, -57), Pair(3, -57), Pair(51, -68), Pair(27, -56), Pair(-49, -67), Pair(39, -90),
        Pair(0, -55), Pair(8, -58), Pair(137, -62), Pair(87, -73), Pair(32, -49), Pair(44, -68), Pair(8, -49), Pair(16, -95),
        Pair(11, -49), Pair(74, -68), Pair(21, -60), Pair(51, -65), Pair(41, -72), Pair(45, -49), Pair(-17, -75), Pair(18, -60),
        Pair(-13, -35), Pair(-6, -66), Pair(31, -38), Pair(-3, -59), Pair(5, -41), Pair(90, -64), Pair(-5, -55), Pair(-9, -74),
        Pair(-28, -81), Pair(-9, -47), Pair(-3, -53), Pair(37, -59), Pair(-6, -60), Pair(-14, -59), Pair(-58, -43), Pair(-8, -49),
        Pair(-16, -49), Pair(-71, -15), Pair(-72, -38), Pair(-55, -45), Pair(-9, -39), Pair(-33, -54), Pair(10, -23), Pair(-3, -19)
      },
      { // Piece 3
        Pair(52, -110), Pair(4, -65), Pair(26, -93), Pair(-56, -67), Pair(37, -89), Pair(38, -109), Pair(105, -89), Pair(28, -86),
        Pair(63, -115), Pair(32, -86), Pair(-54, -74), Pair(-8, -91), Pair(40, -95), Pair(33, -108), Pair(60, -108), Pair(55, -112),
        Pair(-9, -88), Pair(18, -107), Pair(89, -130), Pair(-2, -107), Pair(6, -110), Pair(14, -90), Pair(-17, -101), Pair(-32, -89),
        Pair(15, -103), Pair(1, -97), Pair(-26, -121), Pair(-51, -79), Pair(-38, -111), Pair(-10, -133), Pair(22, -76), Pair(-49, -95),
        Pair(1, -105), Pair(-66, -87), Pair(-50, -73), Pair(-52, -92), Pair(-25, -96), Pair(53, -94), Pair(8, -104), Pair(-23, -93),
        Pair(-17, -98), Pair(28, -107), Pair(-66, -101), Pair(4, -96), Pair(-43, -76), Pair(70, -93), Pair(67, -115), Pair(-33, -107),
        Pair(-36, -114), Pair(4, -90), Pair(-18, -96), Pair(-95, -86), Pair(-30, -93), Pair(-1, -87), Pair(-74, -68), Pair(-35, -83),
        Pair(-55, -90), Pair(-49, -72), Pair(-21, -100), Pair(-22, -85), Pair(-31, -90), Pair(-30, -81), Pair(-32, -92), Pair(-52, -72)
      },
      { // Piece 4
        Pair(-21, -95), Pair(-69, -137), Pair(-11, -31), Pair(-80, -63), Pair(12, -90), Pair(31, -76), Pair(-58, -48), Pair(-75, -107),
        Pair(-38, -49), Pair(0, -1), Pair(-8, -22), Pair(60, 65), Pair(-25, -2), Pair(-29, -43), Pair(-21, -40), Pair(-88, -85),
        Pair(-23, -20), Pair(37, 34), Pair(-16, -88), Pair(-38, -81), Pair(-4, -31), Pair(-22, -23), Pair(-48, -51), Pair(-61, -82),
        Pair(-17, -27), Pair(23, 27), Pair(2, 2), Pair(-13, -25), Pair(-38, -68), Pair(14, 10), Pair(15, 27), Pair(50, 52),
        Pair(-10, -19), Pair(-27, -43), Pair(-3, -15), Pair(24, 32), Pair(-39, -41), Pair(-22, -31), Pair(-1, -21), Pair(-6, -38),
        Pair(-40, -18), Pair(-26, -30), Pair(-7, 2), Pair(-42, -90), Pair(0, -12), Pair(4, 9), Pair(11, 31), Pair(32, 19),
        Pair(7, -8), Pair(-42, -36), Pair(-1, -22), Pair(-60, -81), Pair(45, 23), Pair(-13, -30), Pair(19, 34), Pair(17, -26),
        Pair(-28, -54), Pair(3, 7), Pair(-47, -91), Pair(17, -4), Pair(13, 38), Pair(-29, -62), Pair(-23, -34), Pair(-19, -33)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, -31), Pair(159, -15), Pair(88, 2), Pair(-80, 24), Pair(-33, 22), Pair(21, 11), Pair(63, -2), Pair(-9, -32),
        Pair(36, -41), Pair(67, -15), Pair(8, 9), Pair(-99, 37), Pair(-60, 26), Pair(1, 21), Pair(23, -8), Pair(-49, -27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-187, 36), Pair(59, 17), Pair(113, 10), Pair(45, -1), Pair(107, 18), Pair(109, 20), Pair(31, 47), Pair(-154, 28),
        Pair(-150, 96), Pair(-88, 108), Pair(-4, 94), Pair(-1, 86), Pair(-58, 92), Pair(-65, 85), Pair(-9, 91), Pair(-116, 99),
        Pair(-188, 64), Pair(-113, 64), Pair(-74, 58), Pair(-135, 72), Pair(-130, 74), Pair(-14, 47), Pair(-81, 71), Pair(-189, 59),
        Pair(-159, 40), Pair(-38, 42), Pair(-53, 32), Pair(-76, 42), Pair(4, 19), Pair(-44, 30), Pair(40, 27), Pair(-120, 40),
        Pair(-135, 30), Pair(-99, 38), Pair(-27, 17), Pair(-29, 35), Pair(-21, 29), Pair(24, 15), Pair(-60, 32), Pair(-129, 26),
        Pair(-183, 51), Pair(-177, 54), Pair(-63, 45), Pair(-53, 35), Pair(-16, 12), Pair(-99, 43), Pair(-76, 46), Pair(-155, 59),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, -94), Pair(-23, -143), Pair(-4, -119), Pair(-48, -116), Pair(-21, -97), Pair(34, -117), Pair(-70, -113), Pair(20, -150),
        Pair(-35, -147), Pair(7, -127), Pair(-16, -147), Pair(31, -124), Pair(27, -117), Pair(-20, -125), Pair(37, -144), Pair(-16, -155),
        Pair(-52, -124), Pair(39, -128), Pair(-35, -97), Pair(27, -103), Pair(113, -115), Pair(-25, -92), Pair(-9, -127), Pair(-63, -120),
        Pair(2, -157), Pair(25, -118), Pair(21, -93), Pair(-31, -96), Pair(-2, -95), Pair(7, -112), Pair(17, -153), Pair(-3, -125),
        Pair(23, -140), Pair(-19, -113), Pair(-45, -83), Pair(-50, -89), Pair(74, -99), Pair(11, -100), Pair(73, -127), Pair(-50, -95),
        Pair(-14, -124), Pair(-52, -86), Pair(-1, -95), Pair(39, -119), Pair(-47, -71), Pair(12, -99), Pair(-33, -113), Pair(-5, -129),
        Pair(-51, -135), Pair(-33, -99), Pair(-20, -118), Pair(-20, -97), Pair(-13, -95), Pair(-4, -99), Pair(1, -84), Pair(-44, -68),
        Pair(-32, -127), Pair(-16, -106), Pair(-2, -96), Pair(2, -83), Pair(41, -118), Pair(-4, -96), Pair(6, -85), Pair(-4, -55)
      },
      { // Piece 2
        Pair(1, -101), Pair(65, -84), Pair(5, -75), Pair(-23, -81), Pair(40, -114), Pair(-51, -51), Pair(70, -118), Pair(-25, -97),
        Pair(-2, -108), Pair(-133, -69), Pair(-91, -66), Pair(50, -83), Pair(-39, -82), Pair(41, -98), Pair(1, -76), Pair(0, -72),
        Pair(-67, -71), Pair(-1, -79), Pair(-4, -79), Pair(-24, -78), Pair(22, -79), Pair(-1, -63), Pair(38, -86), Pair(-10, -101),
        Pair(17, -93), Pair(-61, -65), Pair(51, -83), Pair(38, -73), Pair(-58, -72), Pair(-16, -77), Pair(-101, -61), Pair(26, -79),
        Pair(56, -79), Pair(-1, -85), Pair(-1, -78), Pair(-80, -59), Pair(-26, -75), Pair(-60, -51), Pair(-5, -78), Pair(-32, -80),
        Pair(-76, -84), Pair(67, -95), Pair(-29, -63), Pair(-29, -78), Pair(-73, -80), Pair(-30, -71), Pair(-11, -96), Pair(9, -110),
        Pair(-55, -49), Pair(-46, -79), Pair(61, -103), Pair(-66, -96), Pair(29, -97), Pair(-20, -95), Pair(-84, -90), Pair(-5, -101),
        Pair(-43, -60), Pair(32, -40), Pair(-21, -81), Pair(-24, -65), Pair(-59, -65), Pair(10, -72), Pair(-33, -55), Pair(-4, -66)
      },
      { // Piece 3
        Pair(28, -169), Pair(58, -172), Pair(50, -154), Pair(-69, -128), Pair(-41, -132), Pair(-32, -143), Pair(62, -158), Pair(-3, -155),
        Pair(-34, -161), Pair(-29, -137), Pair(123, -201), Pair(-16, -152), Pair(23, -174), Pair(-40, -148), Pair(82, -186), Pair(-74, -152),
        Pair(-8, -164), Pair(44, -171), Pair(-54, -161), Pair(35, -162), Pair(-4, -163), Pair(117, -192), Pair(47, -172), Pair(34, -173),
        Pair(-14, -150), Pair(128, -184), Pair(7, -172), Pair(5, -174), Pair(-11, -158), Pair(35, -171), Pair(-48, -150), Pair(30, -170),
        Pair(43, -165), Pair(-6, -156), Pair(59, -174), Pair(25, -176), Pair(8, -180), Pair(-2, -178), Pair(-1, -171), Pair(-36, -157),
        Pair(57, -182), Pair(44, -171), Pair(-54, -147), Pair(8, -173), Pair(-26, -165), Pair(-66, -171), Pair(-92, -171), Pair(-48, -158),
        Pair(36, -156), Pair(-58, -150), Pair(-59, -139), Pair(-126, -137), Pair(-96, -133), Pair(-62, -155), Pair(18, -159), Pair(24, -167),
        Pair(-71, -131), Pair(-67, -141), Pair(-80, -135), Pair(-72, -144), Pair(11, -159), Pair(26, -160), Pair(-24, -164), Pair(-63, -136)
      },
      { // Piece 4
        Pair(-14, -115), Pair(-55, -89), Pair(-36, -76), Pair(-87, -96), Pair(-35, -107), Pair(-110, -72), Pair(-23, -124), Pair(-20, -150),
        Pair(-17, -58), Pair(-37, -112), Pair(-33, -86), Pair(28, -37), Pair(-26, -48), Pair(26, -21), Pair(-11, -89), Pair(-80, -134),
        Pair(-36, -106), Pair(-73, -106), Pair(-7, -20), Pair(10, -54), Pair(-22, -48), Pair(-52, -147), Pair(-39, -92), Pair(-53, -99),
        Pair(-77, -101), Pair(-40, -77), Pair(-66, -116), Pair(-24, -61), Pair(-18, -55), Pair(10, -85), Pair(-68, -108), Pair(-52, -62),
        Pair(-52, -114), Pair(0, -37), Pair(-22, -74), Pair(10, 41), Pair(-49, -83), Pair(7, -48), Pair(-23, -29), Pair(-38, -86),
        Pair(-17, -15), Pair(-38, -56), Pair(-32, -78), Pair(-26, -57), Pair(-35, -57), Pair(-53, -107), Pair(24, 18), Pair(-31, -80),
        Pair(-57, -114), Pair(-67, -97), Pair(-103, -153), Pair(-75, -126), Pair(10, -50), Pair(-76, -151), Pair(-22, -44), Pair(-43, -99),
        Pair(-55, -123), Pair(6, -16), Pair(-28, -49), Pair(-49, -128), Pair(-26, -56), Pair(-16, -41), Pair(-75, -120), Pair(-11, -41)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-33, -13), Pair(109, -7), Pair(45, 13), Pair(-30, 16), Pair(37, 9), Pair(40, 6), Pair(18, 6), Pair(26, -31),
        Pair(27, -35), Pair(12, -7), Pair(-11, 13), Pair(-76, 34), Pair(-80, 28), Pair(2, 19), Pair(-5, 0), Pair(-68, -23),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-121, 30), Pair(-104, 60), Pair(43, 148), Pair(82, 93), Pair(37, 135), Pair(46, 77), Pair(-16, 75), Pair(-116, 66),
        Pair(-89, 109), Pair(-22, 158), Pair(56, 152), Pair(22, 129), Pair(63, 131), Pair(6, 119), Pair(-7, 129), Pair(-88, 126),
        Pair(-164, 86), Pair(-101, 92), Pair(-13, 93), Pair(-33, 126), Pair(-85, 74), Pair(41, 90), Pair(17, 102), Pair(-77, 79),
        Pair(-73, 45), Pair(-132, 65), Pair(-10, 57), Pair(-98, 51), Pair(93, 14), Pair(-50, 47), Pair(-8, 51), Pair(-121, 56),
        Pair(-10, 37), Pair(-30, 40), Pair(18, 32), Pair(-26, 51), Pair(-55, 51), Pair(-4, 31), Pair(-72, 36), Pair(-22, 27),
        Pair(-108, 49), Pair(-45, 64), Pair(-50, 41), Pair(26, 97), Pair(18, 66), Pair(-112, 80), Pair(-51, 57), Pair(-38, 61),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-25, -88), Pair(-11, -58), Pair(2, -45), Pair(-5, -58), Pair(-15, -57), Pair(-14, -52), Pair(-3, -112), Pair(3, -106),
        Pair(-12, -114), Pair(-25, -35), Pair(-49, -137), Pair(-17, -71), Pair(0, -75), Pair(-65, -160), Pair(-15, -69), Pair(-11, -36),
        Pair(-8, -50), Pair(-32, -84), Pair(-56, -51), Pair(-40, -39), Pair(-50, -55), Pair(-8, -28), Pair(15, -51), Pair(-41, -192),
        Pair(-30, -119), Pair(-4, -43), Pair(-17, -67), Pair(66, -16), Pair(60, -46), Pair(12, -59), Pair(50, -76), Pair(6, -55),
        Pair(-24, -158), Pair(8, -30), Pair(65, -69), Pair(-3, -14), Pair(27, -83), Pair(38, -37), Pair(-28, -76), Pair(13, -65),
        Pair(-7, -45), Pair(24, -78), Pair(-25, -109), Pair(31, -68), Pair(35, -30), Pair(-3, 24), Pair(-8, 46), Pair(-3, -114),
        Pair(-3, -9), Pair(-3, -72), Pair(-20, 8), Pair(-15, -76), Pair(-5, -45), Pair(-10, -76), Pair(-5, -29), Pair(-11, -52),
        Pair(-15, -77), Pair(-16, -39), Pair(-2, -61), Pair(-42, -97), Pair(15, -78), Pair(1, -77), Pair(-9, -54), Pair(-5, -13)
      },
      { // Piece 2
        Pair(-4, -56), Pair(6, 55), Pair(-44, -109), Pair(3, 2), Pair(-1, -45), Pair(-12, -83), Pair(-7, -17), Pair(-15, -60),
        Pair(-1, -29), Pair(-29, 13), Pair(9, 0), Pair(0, -49), Pair(6, -41), Pair(21, -32), Pair(-26, -2), Pair(-34, -164),
        Pair(11, -63), Pair(12, -69), Pair(-42, -23), Pair(22, -17), Pair(35, -2), Pair(-67, -28), Pair(-29, 21), Pair(7, 2),
        Pair(-17, 49), Pair(-25, -32), Pair(32, -12), Pair(-31, -15), Pair(14, -25), Pair(-39, 8), Pair(-25, -53), Pair(23, 11),
        Pair(-16, -29), Pair(-18, -31), Pair(29, -41), Pair(9, -8), Pair(28, -52), Pair(-24, 15), Pair(-2, -40), Pair(28, 79),
        Pair(-13, 16), Pair(4, -23), Pair(-1, -11), Pair(-57, -28), Pair(-28, 9), Pair(-32, -11), Pair(0, 7), Pair(5, -69),
        Pair(-16, 27), Pair(-45, -63), Pair(11, -18), Pair(-2, -77), Pair(-32, -62), Pair(-21, -107), Pair(-8, -64), Pair(-18, -63),
        Pair(17, 0), Pair(35, -72), Pair(-29, -37), Pair(17, -34), Pair(-24, -35), Pair(-27, -87), Pair(-20, -72), Pair(16, -10)
      },
      { // Piece 3
        Pair(27, -80), Pair(-21, -97), Pair(0, -95), Pair(9, -108), Pair(18, -95), Pair(-77, -108), Pair(-45, -87), Pair(-8, -81),
        Pair(-34, -87), Pair(14, -73), Pair(63, -60), Pair(25, -112), Pair(-47, -56), Pair(-25, -124), Pair(9, -112), Pair(-13, -82),
        Pair(-5, -93), Pair(-23, -69), Pair(-9, -106), Pair(52, -103), Pair(-29, -86), Pair(-30, -87), Pair(4, -93), Pair(-7, -103),
        Pair(11, -95), Pair(9, -88), Pair(-35, -78), Pair(-15, -88), Pair(-77, -72), Pair(-25, -132), Pair(-31, -81), Pair(-5, -87),
        Pair(13, -123), Pair(7, -73), Pair(-75, -132), Pair(23, -130), Pair(-37, -103), Pair(-33, -100), Pair(-24, -104), Pair(35, -79),
        Pair(-21, -73), Pair(-28, -84), Pair(-41, -129), Pair(-50, -106), Pair(7, -110), Pair(25, -124), Pair(7, -112), Pair(8, -74),
        Pair(-1, -70), Pair(-2, -66), Pair(27, -37), Pair(-38, -140), Pair(17, -91), Pair(7, -70), Pair(-21, -112), Pair(-22, -108),
        Pair(-20, -59), Pair(-60, -70), Pair(64, -94), Pair(-5, -105), Pair(-26, -111), Pair(-2, -84), Pair(25, -68), Pair(28, -30)
      },
      { // Piece 4
        Pair(-54, -98), Pair(-9, -73), Pair(-24, -108), Pair(-53, -62), Pair(-23, -25), Pair(-45, -53), Pair(-59, -96), Pair(-73, -86),
        Pair(-41, -108), Pair(-69, -103), Pair(-9, 34), Pair(-31, -16), Pair(-12, -52), Pair(-17, -42), Pair(-28, -49), Pair(-26, -29),
        Pair(-22, -64), Pair(-76, -81), Pair(-8, -17), Pair(-6, -58), Pair(-11, -10), Pair(-25, -53), Pair(-29, -24), Pair(-25, -30),
        Pair(-34, -59), Pair(-27, -55), Pair(20, 20), Pair(-15, -47), Pair(4, -17), Pair(-8, -34), Pair(-7, -4), Pair(0, -60),
        Pair(-8, -17), Pair(23, -19), Pair(26, -27), Pair(4, 21), Pair(42, -13), Pair(15, -18), Pair(-21, -43), Pair(0, -26),
        Pair(4, -19), Pair(-25, -52), Pair(-29, -33), Pair(17, 1), Pair(23, 16), Pair(-45, -69), Pair(-41, -98), Pair(-1, -30),
        Pair(18, 12), Pair(-19, -25), Pair(-43, -93), Pair(14, 18), Pair(7, -5), Pair(-6, -47), Pair(35, 44), Pair(-4, -18),
        Pair(-37, -32), Pair(-3, 12), Pair(-10, -15), Pair(-5, 3), Pair(-23, -76), Pair(-20, -54), Pair(23, 36), Pair(-34, -68)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-31, -3), Pair(74, 7), Pair(29, 26), Pair(32, 23), Pair(-31, 41), Pair(-45, 24), Pair(30, 23), Pair(4, 5),
        Pair(-96, -15), Pair(32, 25), Pair(24, 20), Pair(-49, 43), Pair(-15, 24), Pair(-7, 21), Pair(-15, 13), Pair(-17, -17),
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
        Pair(-47, 43), Pair(80, 13), Pair(84, 220), Pair(87, 158), Pair(-8, 132), Pair(45, 127), Pair(12, -44), Pair(-10, -143),
        Pair(27, 53), Pair(130, 107), Pair(5, 106), Pair(33, 171), Pair(34, 131), Pair(60, 55), Pair(68, 23), Pair(50, -37),
        Pair(-3, 40), Pair(29, 60), Pair(111, 54), Pair(3, 92), Pair(2, 60), Pair(-29, 60), Pair(-67, 24), Pair(3, 8),
        Pair(-83, 33), Pair(-100, 107), Pair(-2, 58), Pair(67, 11), Pair(20, 2), Pair(-88, 11), Pair(-84, 22), Pair(-106, -22),
        Pair(-98, 10), Pair(-9, 47), Pair(39, 3), Pair(36, -29), Pair(-35, 10), Pair(36, -9), Pair(-154, 43), Pair(15, -23),
        Pair(-9, -3), Pair(-27, 20), Pair(-10, 11), Pair(-34, -38), Pair(-13, -27), Pair(-37, -21), Pair(-145, 64), Pair(-133, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(6, 27), Pair(8, 2), Pair(32, 15), Pair(-31, -79), Pair(11, 28), Pair(9, -85), Pair(11, 32), Pair(0, 0),
        Pair(0, -4), Pair(-1, 24), Pair(-9, -88), Pair(46, 37), Pair(21, -76), Pair(-2, -92), Pair(-14, -49), Pair(3, 9),
        Pair(-31, -98), Pair(3, -19), Pair(3, 1), Pair(24, 2), Pair(158, 130), Pair(34, 23), Pair(32, 72), Pair(26, 20),
        Pair(33, -8), Pair(-14, -64), Pair(55, 62), Pair(-4, 25), Pair(10, 44), Pair(18, 39), Pair(96, 89), Pair(12, 24),
        Pair(27, 43), Pair(9, -2), Pair(20, 46), Pair(-60, -84), Pair(74, 196), Pair(-17, -25), Pair(11, 68), Pair(-11, 7),
        Pair(-24, 18), Pair(6, -49), Pair(-50, 8), Pair(-4, -24), Pair(-3, 1), Pair(-21, 29), Pair(18, -38), Pair(1, -34),
        Pair(-10, -44), Pair(2, 3), Pair(-35, 40), Pair(-108, -30), Pair(-40, -68), Pair(11, 26), Pair(13, 5), Pair(-17, -32),
        Pair(-1, -4), Pair(-5, 21), Pair(20, 57), Pair(0, 7), Pair(-1, -18), Pair(-40, -57), Pair(-71, -66), Pair(-10, -47)
      },
      { // Piece 2
        Pair(-4, 8), Pair(7, 24), Pair(-19, -37), Pair(-12, -94), Pair(-6, 0), Pair(-52, -58), Pair(-5, -9), Pair(4, 51),
        Pair(-5, -33), Pair(-11, -8), Pair(-20, -56), Pair(17, 43), Pair(18, 35), Pair(-23, -83), Pair(12, 41), Pair(13, 3),
        Pair(-26, -69), Pair(-9, -28), Pair(44, 31), Pair(-48, -81), Pair(60, 15), Pair(19, 50), Pair(-19, -33), Pair(27, 88),
        Pair(21, 23), Pair(51, -41), Pair(7, -70), Pair(42, -48), Pair(10, -31), Pair(-31, 18), Pair(-48, -59), Pair(35, -30),
        Pair(24, 62), Pair(23, 44), Pair(-28, 9), Pair(83, -45), Pair(14, -81), Pair(19, -23), Pair(-8, -13), Pair(-14, 17),
        Pair(11, 40), Pair(16, -40), Pair(68, 110), Pair(-26, -43), Pair(14, 7), Pair(-58, -54), Pair(0, 57), Pair(1, -17),
        Pair(7, -5), Pair(63, 21), Pair(53, -76), Pair(-32, 23), Pair(-24, -57), Pair(-4, 5), Pair(-47, -78), Pair(-3, -22),
        Pair(-37, -70), Pair(-11, 13), Pair(-91, 38), Pair(-22, -37), Pair(12, 39), Pair(-89, -112), Pair(17, 3), Pair(-5, -57)
      },
      { // Piece 3
        Pair(-3, -13), Pair(54, 75), Pair(52, 98), Pair(20, 19), Pair(35, 89), Pair(-52, -100), Pair(-1, -4), Pair(5, 2),
        Pair(68, -7), Pair(105, -14), Pair(29, -27), Pair(-11, 23), Pair(94, -43), Pair(52, 20), Pair(8, 29), Pair(-12, -46),
        Pair(-4, -13), Pair(25, 28), Pair(47, 41), Pair(9, -22), Pair(-18, 22), Pair(7, 25), Pair(-3, 45), Pair(-7, 44),
        Pair(-22, 0), Pair(-77, -49), Pair(-50, 57), Pair(-62, -6), Pair(16, 40), Pair(19, 13), Pair(27, 77), Pair(27, 47),
        Pair(29, 40), Pair(18, 31), Pair(14, 30), Pair(16, -10), Pair(74, -27), Pair(5, -24), Pair(37, 78), Pair(23, 18),
        Pair(-48, -94), Pair(25, 124), Pair(-35, -52), Pair(-36, -7), Pair(-30, -68), Pair(37, 7), Pair(27, 49), Pair(-24, 21),
        Pair(-45, 2), Pair(-13, 49), Pair(-19, -62), Pair(-37, 42), Pair(-41, -50), Pair(37, 47), Pair(-18, 42), Pair(33, 32),
        Pair(-177, 59), Pair(-133, 80), Pair(-7, 75), Pair(-95, 78), Pair(52, 5), Pair(-40, 36), Pair(-16, 1), Pair(-166, 76)
      },
      { // Piece 4
        Pair(-57, -46), Pair(-8, -20), Pair(21, 8), Pair(41, 50), Pair(-4, -30), Pair(-76, -81), Pair(-4, 10), Pair(2, 4),
        Pair(-37, -100), Pair(-64, -47), Pair(-8, -6), Pair(-43, -41), Pair(1, 26), Pair(-37, -4), Pair(-8, -34), Pair(-16, -3),
        Pair(-6, -29), Pair(55, 89), Pair(17, -2), Pair(9, 9), Pair(8, 36), Pair(10, 13), Pair(24, -42), Pair(16, -67),
        Pair(-13, -30), Pair(-62, -57), Pair(-19, 23), Pair(20, 32), Pair(17, 8), Pair(-15, -16), Pair(-34, -33), Pair(-3, 31),
        Pair(-42, -87), Pair(58, 63), Pair(-46, -43), Pair(3, 21), Pair(48, -15), Pair(28, 77), Pair(9, 61), Pair(-47, -86),
        Pair(-36, -71), Pair(2, 20), Pair(-4, 37), Pair(-42, -43), Pair(-12, -21), Pair(-83, -47), Pair(33, 55), Pair(-9, -3),
        Pair(35, -11), Pair(-31, -49), Pair(-5, 1), Pair(-43, -9), Pair(-17, 3), Pair(-45, -54), Pair(-9, -11), Pair(13, 26),
        Pair(-28, -17), Pair(-59, -79), Pair(-5, 4), Pair(-76, -36), Pair(-13, -29), Pair(-105, -88), Pair(-12, -14), Pair(-85, -88)
      },
      { // Piece 5
        Pair(-43, -84), Pair(26, -17), Pair(76, -47), Pair(88, -73), Pair(-23, -9), Pair(106, -30), Pair(-14, 37), Pair(-32, -79),
        Pair(-68, 0), Pair(51, -2), Pair(61, 11), Pair(28, 2), Pair(13, -6), Pair(-96, 44), Pair(41, 12), Pair(-28, 7),
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
        Pair(19, 10), Pair(22, 127), Pair(54, -40), Pair(43, 58), Pair(0, -92), Pair(26, -25), Pair(47, 183), Pair(19, 57),
        Pair(-1, 97), Pair(48, 83), Pair(-2, 48), Pair(51, 7), Pair(14, 18), Pair(59, 51), Pair(129, 65), Pair(35, 43),
        Pair(3, -1), Pair(-96, 66), Pair(8, 12), Pair(-11, 26), Pair(-23, 25), Pair(8, -15), Pair(-80, 21), Pair(-52, 6),
        Pair(-59, 26), Pair(-14, 14), Pair(-1, -1), Pair(84, -5), Pair(36, -34), Pair(-37, -7), Pair(-28, 49), Pair(-108, -5),
        Pair(-71, -40), Pair(9, -4), Pair(-17, -11), Pair(-15, -32), Pair(-92, -7), Pair(-43, -5), Pair(-153, 19), Pair(-24, -39),
        Pair(-70, -14), Pair(-109, 52), Pair(-92, 9), Pair(-16, -53), Pair(-31, -58), Pair(-48, 21), Pair(-98, 30), Pair(-153, 27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(27, -15), Pair(7, 33), Pair(-14, -16), Pair(-14, -36), Pair(-7, -70), Pair(11, 3), Pair(-12, -28), Pair(-24, -55),
        Pair(6, 5), Pair(1, 3), Pair(25, 39), Pair(6, 30), Pair(27, 29), Pair(-14, -30), Pair(-31, -105), Pair(-5, -6),
        Pair(-12, -35), Pair(-13, -11), Pair(41, -13), Pair(74, 93), Pair(20, -8), Pair(57, 74), Pair(5, -103), Pair(-43, -157),
        Pair(5, -9), Pair(19, 37), Pair(35, -9), Pair(-7, 30), Pair(23, 52), Pair(18, 72), Pair(34, -5), Pair(-15, -14),
        Pair(-14, -37), Pair(4, 36), Pair(21, 29), Pair(-21, 4), Pair(62, 107), Pair(-3, -17), Pair(2, -13), Pair(5, 39),
        Pair(-3, -49), Pair(-34, -70), Pair(20, 32), Pair(31, 40), Pair(19, 19), Pair(-11, -25), Pair(-13, -75), Pair(1, -18),
        Pair(-14, -52), Pair(-2, -5), Pair(-3, 2), Pair(-8, -21), Pair(-64, -66), Pair(1, 1), Pair(-15, -41), Pair(-9, -56),
        Pair(-7, -3), Pair(-42, 49), Pair(4, -15), Pair(-6, 20), Pair(-8, -45), Pair(-24, -80), Pair(-56, -85), Pair(0, -2)
      },
      { // Piece 2
        Pair(-3, -35), Pair(2, -19), Pair(15, 7), Pair(3, -78), Pair(-16, -73), Pair(-14, -71), Pair(-19, -176), Pair(-15, -70),
        Pair(-32, -137), Pair(30, 70), Pair(-8, 17), Pair(-4, -105), Pair(16, 17), Pair(-6, 20), Pair(49, 53), Pair(-13, -33),
        Pair(8, 48), Pair(4, -57), Pair(-20, -82), Pair(-3, -88), Pair(16, -93), Pair(34, -10), Pair(-47, 18), Pair(-20, -39),
        Pair(-11, 25), Pair(32, -37), Pair(58, -20), Pair(-33, 30), Pair(-7, 1), Pair(-28, -94), Pair(32, -22), Pair(16, 81),
        Pair(-17, 21), Pair(-10, 29), Pair(4, -55), Pair(-1, -50), Pair(-36, -98), Pair(0, 78), Pair(26, 18), Pair(0, 15),
        Pair(-7, -59), Pair(26, 5), Pair(-6, -12), Pair(-12, -36), Pair(-58, 15), Pair(-28, -80), Pair(-15, 35), Pair(5, -19),
        Pair(15, -17), Pair(46, 85), Pair(7, -43), Pair(-7, -2), Pair(10, -31), Pair(-24, -7), Pair(-24, -67), Pair(11, 23),
        Pair(-12, -74), Pair(-11, -5), Pair(-81, -126), Pair(-8, 23), Pair(-23, 31), Pair(-23, -18), Pair(1, -32), Pair(-10, -68)
      },
      { // Piece 3
        Pair(63, 72), Pair(21, 33), Pair(-2, 52), Pair(23, 35), Pair(-7, -32), Pair(-38, -17), Pair(-5, -33), Pair(2, -25),
        Pair(152, 4), Pair(96, -20), Pair(98, -46), Pair(50, 7), Pair(56, 32), Pair(48, 13), Pair(14, -2), Pair(24, 2),
        Pair(9, 50), Pair(31, 47), Pair(-15, -6), Pair(32, 78), Pair(48, 10), Pair(77, 33), Pair(-6, -42), Pair(12, -33),
        Pair(23, 11), Pair(21, -5), Pair(-23, -26), Pair(19, 9), Pair(12, 56), Pair(29, 28), Pair(-6, -10), Pair(-34, -79),
        Pair(-43, -83), Pair(34, 83), Pair(3, -32), Pair(-40, 18), Pair(36, 45), Pair(7, -25), Pair(29, 73), Pair(10, 36),
        Pair(32, 17), Pair(-22, 29), Pair(10, -21), Pair(31, 52), Pair(17, 17), Pair(-11, -12), Pair(59, 97), Pair(10, -3),
        Pair(-7, -50), Pair(-19, 27), Pair(-9, -84), Pair(23, 15), Pair(-31, -27), Pair(10, 32), Pair(27, 108), Pair(13, 51),
        Pair(-91, 6), Pair(11, 43), Pair(-44, 43), Pair(-53, -53), Pair(29, 52), Pair(-4, 43), Pair(-19, 52), Pair(-56, 50)
      },
      { // Piece 4
        Pair(-22, -43), Pair(-24, -50), Pair(4, 10), Pair(-14, -6), Pair(1, 3), Pair(-8, -20), Pair(-22, -40), Pair(15, 28),
        Pair(-9, -48), Pair(28, 37), Pair(-2, -37), Pair(-11, -30), Pair(2, 38), Pair(-2, -7), Pair(-8, -52), Pair(-70, -92),
        Pair(2, -4), Pair(-23, -52), Pair(57, 74), Pair(8, 11), Pair(24, 42), Pair(12, 18), Pair(6, 0), Pair(4, 3),
        Pair(28, 26), Pair(27, 28), Pair(11, -12), Pair(39, -8), Pair(-11, -43), Pair(-18, -44), Pair(-1, -3), Pair(-17, -20),
        Pair(-8, -11), Pair(-19, -24), Pair(13, 11), Pair(-13, -36), Pair(21, 44), Pair(-12, -28), Pair(-51, -63), Pair(-23, -38),
        Pair(-7, -20), Pair(-37, -55), Pair(21, 41), Pair(1, 2), Pair(-27, -27), Pair(10, 21), Pair(11, -4), Pair(-4, -8),
        Pair(-28, -15), Pair(-2, 8), Pair(22, 50), Pair(-21, -18), Pair(1, 1), Pair(-4, -8), Pair(26, 33), Pair(-9, -12),
        Pair(-14, -35), Pair(-25, -31), Pair(3, 7), Pair(-110, -46), Pair(-6, -9), Pair(-6, -8), Pair(-5, -24), Pair(-3, -6)
      },
      { // Piece 5
        Pair(10, -115), Pair(-15, -46), Pair(-82, -1), Pair(65, -41), Pair(-12, 2), Pair(-46, 58), Pair(-29, 14), Pair(-13, -89),
        Pair(-47, -56), Pair(49, -2), Pair(51, 0), Pair(75, 2), Pair(51, 69), Pair(105, 38), Pair(6, 17), Pair(25, -38),
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
        Pair(97, 47), Pair(143, 17), Pair(86, 113), Pair(-10, 90), Pair(-14, 85), Pair(62, 57), Pair(-29, 126), Pair(171, 9),
        Pair(90, 25), Pair(11, 120), Pair(144, 101), Pair(180, 16), Pair(109, 24), Pair(48, 43), Pair(109, 57), Pair(152, -15),
        Pair(38, 40), Pair(20, 88), Pair(68, 29), Pair(10, 37), Pair(69, 22), Pair(45, 17), Pair(-46, 56), Pair(57, -5),
        Pair(-92, 34), Pair(-61, 39), Pair(22, 15), Pair(-2, 25), Pair(-102, 40), Pair(-46, 11), Pair(-93, 42), Pair(-43, 3),
        Pair(-84, 35), Pair(24, 16), Pair(-58, 22), Pair(27, -4), Pair(-27, 11), Pair(68, -12), Pair(-89, 21), Pair(-135, 14),
        Pair(-181, 54), Pair(-92, 31), Pair(-85, 22), Pair(-15, 36), Pair(-48, 35), Pair(-97, 19), Pair(-130, 51), Pair(-76, 29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-30, -98), Pair(9, 21), Pair(9, 23), Pair(-13, -59), Pair(5, 38), Pair(24, 32), Pair(-4, -57), Pair(-3, -34),
        Pair(-9, -53), Pair(-8, -73), Pair(-4, -12), Pair(24, -50), Pair(8, -62), Pair(-76, -31), Pair(2, -24), Pair(-17, -90),
        Pair(-33, -93), Pair(-30, -57), Pair(16, 32), Pair(75, 53), Pair(118, 63), Pair(10, 8), Pair(41, -59), Pair(22, 8),
        Pair(0, 4), Pair(-32, -14), Pair(2, 1), Pair(31, -7), Pair(3, -46), Pair(-39, 30), Pair(57, 6), Pair(-2, -184),
        Pair(-27, -26), Pair(-7, 28), Pair(-24, -9), Pair(-40, 2), Pair(148, 63), Pair(9, -10), Pair(-30, -105), Pair(0, -34),
        Pair(-21, -102), Pair(-44, -27), Pair(-25, 35), Pair(-58, -14), Pair(47, -56), Pair(-18, -32), Pair(-40, -122), Pair(-1, 41),
        Pair(10, 19), Pair(-50, -33), Pair(11, -2), Pair(-64, -32), Pair(-9, -64), Pair(-37, -62), Pair(-9, -13), Pair(2, -6),
        Pair(-44, -73), Pair(-3, 87), Pair(-21, -1), Pair(-46, -60), Pair(19, 78), Pair(-36, -43), Pair(-55, -89), Pair(-5, -32)
      },
      { // Piece 2
        Pair(-14, -122), Pair(-5, -137), Pair(-12, 2), Pair(45, 28), Pair(-8, -22), Pair(25, -34), Pair(15, -64), Pair(-8, -16),
        Pair(-36, -149), Pair(20, -74), Pair(-11, -68), Pair(25, -99), Pair(40, -55), Pair(41, -24), Pair(-1, -55), Pair(-22, -66),
        Pair(-30, -42), Pair(-40, -36), Pair(60, -48), Pair(16, -57), Pair(-16, -32), Pair(62, -19), Pair(20, -17), Pair(-64, -38),
        Pair(-13, -95), Pair(-14, -7), Pair(24, -5), Pair(-1, -47), Pair(67, 0), Pair(6, -77), Pair(-27, -10), Pair(39, -53),
        Pair(17, -86), Pair(78, -79), Pair(13, -38), Pair(91, -30), Pair(39, -56), Pair(86, -74), Pair(-39, -64), Pair(59, 39),
        Pair(-53, -10), Pair(39, -62), Pair(8, -10), Pair(26, -12), Pair(-60, -52), Pair(44, -53), Pair(-34, -42), Pair(-17, 59),
        Pair(-12, 51), Pair(-25, 49), Pair(54, -8), Pair(-13, -11), Pair(6, -16), Pair(43, -79), Pair(-46, -56), Pair(-5, -90),
        Pair(-6, -83), Pair(-21, -2), Pair(-28, -46), Pair(-47, 26), Pair(-13, 7), Pair(1, -30), Pair(-1, -5), Pair(7, 1)
      },
      { // Piece 3
        Pair(5, -34), Pair(-27, -8), Pair(38, -9), Pair(-61, 6), Pair(50, -32), Pair(3, -4), Pair(20, 3), Pair(113, -18),
        Pair(-17, -26), Pair(9, -59), Pair(-13, -28), Pair(24, -57), Pair(-4, -70), Pair(-12, -68), Pair(10, -49), Pair(5, 30),
        Pair(-45, -14), Pair(30, -27), Pair(-62, -38), Pair(-20, -10), Pair(15, -56), Pair(5, -3), Pair(42, 6), Pair(-1, -22),
        Pair(-66, -40), Pair(-23, 10), Pair(24, -47), Pair(-127, -16), Pair(51, 2), Pair(20, -24), Pair(81, -48), Pair(31, 7),
        Pair(-25, -30), Pair(47, -34), Pair(24, 19), Pair(6, -5), Pair(1, -5), Pair(-5, -10), Pair(38, -1), Pair(-17, -23),
        Pair(-44, -46), Pair(-31, -7), Pair(-14, -41), Pair(-24, -9), Pair(-95, -14), Pair(3, -33), Pair(88, 11), Pair(-4, -26),
        Pair(-15, -27), Pair(9, -3), Pair(-35, -71), Pair(-85, -14), Pair(29, 0), Pair(-46, 2), Pair(-26, -24), Pair(-47, -60),
        Pair(-175, -19), Pair(-31, 41), Pair(-26, 0), Pair(-149, -12), Pair(-106, -4), Pair(0, -11), Pair(-45, -18), Pair(-85, 33)
      },
      { // Piece 4
        Pair(6, -95), Pair(-91, 2), Pair(-30, -59), Pair(-13, -50), Pair(-27, -60), Pair(-137, -95), Pair(-28, -32), Pair(-61, -67),
        Pair(20, 53), Pair(-17, 0), Pair(21, 31), Pair(37, 46), Pair(-20, -68), Pair(13, 43), Pair(-21, -10), Pair(29, 19),
        Pair(-33, -18), Pair(6, -27), Pair(22, 32), Pair(-18, -2), Pair(15, -11), Pair(8, 15), Pair(-21, -55), Pair(-54, -82),
        Pair(-5, -19), Pair(64, 67), Pair(19, 33), Pair(-4, -5), Pair(20, 57), Pair(6, 19), Pair(8, 7), Pair(9, -13),
        Pair(-38, -61), Pair(-17, -40), Pair(-31, -31), Pair(19, 48), Pair(-25, 10), Pair(-6, -26), Pair(-24, 11), Pair(-23, -40),
        Pair(1, -48), Pair(15, 2), Pair(-15, -43), Pair(-22, -26), Pair(-59, -50), Pair(-50, -47), Pair(-20, -31), Pair(-34, -66),
        Pair(17, 46), Pair(-26, 0), Pair(3, 47), Pair(6, 36), Pair(-46, -53), Pair(33, 13), Pair(-16, -32), Pair(1, -1),
        Pair(-41, -49), Pair(-54, -64), Pair(-23, -42), Pair(-44, -22), Pair(-40, -24), Pair(-2, 5), Pair(-21, -63), Pair(-47, -74)
      },
      { // Piece 5
        Pair(108, -149), Pair(-13, -46), Pair(29, -35), Pair(-46, -15), Pair(-87, 6), Pair(16, -15), Pair(-95, 8), Pair(24, -100),
        Pair(-6, -54), Pair(71, -2), Pair(84, 2), Pair(-36, 23), Pair(33, 6), Pair(81, 9), Pair(29, 16), Pair(-38, -38),
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
        Pair(-10, 59), Pair(37, 143), Pair(96, 117), Pair(112, 133), Pair(17, 94), Pair(70, 113), Pair(-51, 118), Pair(-58, 89),
        Pair(47, 60), Pair(-4, 96), Pair(129, 57), Pair(50, 107), Pair(18, 77), Pair(105, 71), Pair(-9, 94), Pair(4, 43),
        Pair(-24, 50), Pair(-119, 90), Pair(-4, 52), Pair(-8, 25), Pair(83, -2), Pair(44, 37), Pair(-95, 76), Pair(-53, 41),
        Pair(-9, 29), Pair(-133, 60), Pair(-16, 42), Pair(-36, 40), Pair(-4, 44), Pair(3, 12), Pair(-15, 36), Pair(-170, 29),
        Pair(-77, 30), Pair(-36, 26), Pair(-45, 6), Pair(52, 18), Pair(-134, 38), Pair(146, -21), Pair(-118, 23), Pair(-106, 28),
        Pair(-57, 64), Pair(-60, 38), Pair(39, 31), Pair(39, 133), Pair(13, -19), Pair(-71, 35), Pair(-93, 48), Pair(-145, 45),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-31, -88), Pair(-35, -47), Pair(-21, -109), Pair(1, -81), Pair(-23, -75), Pair(3, -86), Pair(-1, -41), Pair(-24, -131),
        Pair(-7, -48), Pair(-31, -45), Pair(-45, -81), Pair(-18, -15), Pair(0, -30), Pair(13, -41), Pair(-20, -84), Pair(-8, -35),
        Pair(-43, -98), Pair(11, 2), Pair(39, -10), Pair(57, -31), Pair(105, 45), Pair(28, -58), Pair(11, 11), Pair(-7, -51),
        Pair(12, -48), Pair(-29, -74), Pair(35, -8), Pair(-15, -4), Pair(26, -33), Pair(10, -33), Pair(19, 0), Pair(-2, -55),
        Pair(-1, -52), Pair(-47, 14), Pair(17, 26), Pair(36, -47), Pair(114, 55), Pair(27, -11), Pair(1, -40), Pair(-4, -34),
        Pair(-17, -18), Pair(-13, 1), Pair(-49, -12), Pair(8, -6), Pair(0, 6), Pair(-2, -44), Pair(-4, -20), Pair(-8, -54),
        Pair(3, -51), Pair(-10, -6), Pair(-41, -82), Pair(-15, 11), Pair(-3, 18), Pair(-36, 11), Pair(-17, -74), Pair(33, 70),
        Pair(-17, -70), Pair(0, -10), Pair(2, 10), Pair(-8, -44), Pair(2, -91), Pair(-14, 1), Pair(-22, -67), Pair(0, -8)
      },
      { // Piece 2
        Pair(-1, -50), Pair(-16, -106), Pair(47, -15), Pair(48, -32), Pair(-65, -85), Pair(-1, -34), Pair(4, -102), Pair(5, -32),
        Pair(-28, -78), Pair(15, -27), Pair(-17, -67), Pair(18, -59), Pair(-26, -75), Pair(-19, -64), Pair(6, -92), Pair(-13, -62),
        Pair(-7, -7), Pair(-18, -34), Pair(15, -60), Pair(-2, -80), Pair(21, -65), Pair(36, -20), Pair(-29, -90), Pair(-60, -79),
        Pair(-28, -3), Pair(28, -35), Pair(106, -18), Pair(31, -32), Pair(69, -49), Pair(-33, -47), Pair(33, -13), Pair(38, -34),
        Pair(-14, -77), Pair(-1, -81), Pair(6, -80), Pair(34, -42), Pair(58, -75), Pair(29, -57), Pair(-17, -30), Pair(77, 78),
        Pair(0, -53), Pair(6, -69), Pair(-13, -34), Pair(6, -73), Pair(3, -24), Pair(-10, -25), Pair(-14, -98), Pair(-5, -24),
        Pair(3, -1), Pair(3, -27), Pair(5, 16), Pair(8, -44), Pair(23, -62), Pair(-1, -56), Pair(-14, -70), Pair(2, -64),
        Pair(-2, 24), Pair(3, 18), Pair(-72, -71), Pair(-1, 23), Pair(-32, -107), Pair(-17, -5), Pair(-37, -84), Pair(-6, -23)
      },
      { // Piece 3
        Pair(66, -60), Pair(-44, -5), Pair(85, -44), Pair(-21, -64), Pair(18, -67), Pair(36, -45), Pair(-42, -45), Pair(20, -51),
        Pair(12, -51), Pair(19, -61), Pair(14, -39), Pair(23, -79), Pair(85, -100), Pair(5, -88), Pair(31, -91), Pair(77, -41),
        Pair(-18, -66), Pair(-58, -52), Pair(-23, -82), Pair(30, -50), Pair(17, -37), Pair(3, -9), Pair(-3, -19), Pair(-16, -77),
        Pair(-39, -56), Pair(33, -73), Pair(20, -42), Pair(-21, -65), Pair(-27, -66), Pair(51, -64), Pair(89, -56), Pair(6, -38),
        Pair(-26, -41), Pair(-4, -10), Pair(14, -68), Pair(25, -53), Pair(42, -60), Pair(26, -61), Pair(-31, -69), Pair(-22, -80),
        Pair(-11, -52), Pair(-13, -36), Pair(0, -108), Pair(-28, -71), Pair(5, -45), Pair(-61, -69), Pair(27, -23), Pair(5, -38),
        Pair(-26, -59), Pair(-49, -29), Pair(-18, -50), Pair(-9, -59), Pair(-51, -57), Pair(-59, -80), Pair(-36, -55), Pair(-30, -48),
        Pair(-120, -55), Pair(-53, -19), Pair(-6, -44), Pair(-51, -63), Pair(22, -33), Pair(-84, -10), Pair(-8, -51), Pair(-153, -77)
      },
      { // Piece 4
        Pair(-20, -76), Pair(-92, -124), Pair(-58, -112), Pair(30, 22), Pair(-33, -57), Pair(27, -35), Pair(7, -88), Pair(20, -66),
        Pair(36, 14), Pair(-15, 53), Pair(28, -9), Pair(-27, -43), Pair(15, 7), Pair(-2, -34), Pair(-2, -21), Pair(13, 18),
        Pair(-14, -22), Pair(9, 7), Pair(-2, -31), Pair(39, 56), Pair(37, 55), Pair(11, -6), Pair(64, 97), Pair(2, 4),
        Pair(8, 5), Pair(-36, -18), Pair(-4, -15), Pair(-27, -10), Pair(2, 1), Pair(23, 35), Pair(9, 20), Pair(-6, -15),
        Pair(0, -3), Pair(-40, -70), Pair(-13, -16), Pair(28, 40), Pair(-36, 36), Pair(29, 17), Pair(-29, -63), Pair(-18, -43),
        Pair(28, 57), Pair(18, 47), Pair(-33, -46), Pair(18, 45), Pair(27, 45), Pair(-14, -17), Pair(-32, -23), Pair(40, 60),
        Pair(-8, -18), Pair(-16, -28), Pair(-26, -18), Pair(-15, -32), Pair(-21, -30), Pair(-35, -62), Pair(-3, -13), Pair(17, 42),
        Pair(15, 42), Pair(-34, -74), Pair(3, -5), Pair(44, 59), Pair(-68, -123), Pair(-31, -44), Pair(-20, -37), Pair(-40, -83)
      },
      { // Piece 5
        Pair(37, -93), Pair(105, -76), Pair(-21, -23), Pair(40, 0), Pair(8, -34), Pair(-121, 6), Pair(-37, -21), Pair(-42, -91),
        Pair(15, -35), Pair(126, -1), Pair(-38, 31), Pair(77, 0), Pair(32, 10), Pair(-20, 25), Pair(111, 11), Pair(-67, -16),
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
        Pair(-69, 85), Pair(70, 126), Pair(27, 135), Pair(31, 173), Pair(27, 102), Pair(-9, 169), Pair(12, 117), Pair(-24, 121),
        Pair(41, 97), Pair(-16, 164), Pair(92, 110), Pair(-22, 179), Pair(-38, 105), Pair(-20, 149), Pair(17, 129), Pair(-34, 86),
        Pair(-31, 61), Pair(-14, 103), Pair(33, 70), Pair(16, 70), Pair(13, 57), Pair(-23, 68), Pair(-92, 80), Pair(-94, 70),
        Pair(-105, 62), Pair(-50, 83), Pair(-1, 72), Pair(15, 34), Pair(-45, 49), Pair(-83, 33), Pair(54, 42), Pair(-151, 53),
        Pair(-135, 52), Pair(-82, 50), Pair(16, 26), Pair(25, 30), Pair(-35, 49), Pair(34, 28), Pair(-43, 34), Pair(-105, 46),
        Pair(-105, 53), Pair(-71, 82), Pair(34, 13), Pair(5, 3), Pair(-74, 46), Pair(-116, 48), Pair(-7, 36), Pair(-46, 59),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-26, -17), Pair(-1, -119), Pair(1, -67), Pair(-18, -112), Pair(-47, -107), Pair(-19, -114), Pair(-27, -151), Pair(-25, -91),
        Pair(-3, -110), Pair(1, -99), Pair(-30, -69), Pair(-46, -83), Pair(-19, -110), Pair(3, -61), Pair(23, 31), Pair(-14, -59),
        Pair(3, -17), Pair(-21, -57), Pair(-6, -41), Pair(-31, -36), Pair(107, -14), Pair(-4, -35), Pair(-1, -138), Pair(-11, -65),
        Pair(-17, -101), Pair(-45, -18), Pair(-40, -65), Pair(10, -11), Pair(60, -18), Pair(14, -19), Pair(-5, -11), Pair(-20, -106),
        Pair(-16, -53), Pair(-29, -105), Pair(-15, -7), Pair(-7, -78), Pair(33, -4), Pair(-20, 21), Pair(-46, -46), Pair(12, 80),
        Pair(-2, -16), Pair(-5, -44), Pair(-26, -35), Pair(27, -29), Pair(0, 0), Pair(16, 17), Pair(-19, -49), Pair(-39, 9),
        Pair(4, -15), Pair(-8, -94), Pair(-7, 8), Pair(5, -59), Pair(-11, -5), Pair(4, -46), Pair(-24, -21), Pair(3, -21),
        Pair(-7, 5), Pair(-27, -82), Pair(-10, 45), Pair(17, 32), Pair(-8, -58), Pair(-7, 0), Pair(6, 17), Pair(-2, 13)
      },
      { // Piece 2
        Pair(-12, 38), Pair(-9, -46), Pair(-3, -42), Pair(20, -6), Pair(-10, -36), Pair(-30, -124), Pair(-48, -87), Pair(18, 72),
        Pair(7, -35), Pair(12, -20), Pair(47, -64), Pair(-31, -61), Pair(-1, -22), Pair(-17, -26), Pair(22, -39), Pair(5, 45),
        Pair(11, -24), Pair(43, -32), Pair(17, -2), Pair(15, -5), Pair(-23, -46), Pair(15, -30), Pair(34, -29), Pair(9, -40),
        Pair(-13, -24), Pair(-51, -42), Pair(-17, 23), Pair(36, -51), Pair(-18, 9), Pair(-25, -16), Pair(11, -31), Pair(-8, -91),
        Pair(15, -46), Pair(19, -27), Pair(-11, -4), Pair(42, -19), Pair(-5, -51), Pair(-6, -57), Pair(-1, -35), Pair(31, -37),
        Pair(18, 28), Pair(-9, -58), Pair(21, -48), Pair(0, -31), Pair(-10, 6), Pair(-16, 4), Pair(31, -5), Pair(-9, 13),
        Pair(-30, -55), Pair(-3, -13), Pair(-30, -104), Pair(-9, -59), Pair(-10, -16), Pair(-11, 7), Pair(-56, -3), Pair(15, 7),
        Pair(4, 22), Pair(6, 35), Pair(21, -11), Pair(-15, -35), Pair(-3, -80), Pair(2, -16), Pair(-16, 24), Pair(-3, 80)
      },
      { // Piece 3
        Pair(-12, -66), Pair(57, -23), Pair(-54, -72), Pair(-28, -78), Pair(-1, -43), Pair(-27, -54), Pair(9, -72), Pair(31, -78),
        Pair(36, -109), Pair(0, -54), Pair(-18, -86), Pair(-2, -53), Pair(45, -56), Pair(-17, -76), Pair(6, -70), Pair(-44, -124),
        Pair(28, -63), Pair(90, -60), Pair(63, -32), Pair(85, -75), Pair(-30, -57), Pair(59, -57), Pair(29, -27), Pair(8, -61),
        Pair(-25, -106), Pair(10, -46), Pair(-12, -61), Pair(7, -38), Pair(-42, 10), Pair(-23, -81), Pair(-16, -92), Pair(-28, -61),
        Pair(-49, -71), Pair(10, -57), Pair(33, -65), Pair(11, -76), Pair(-6, -65), Pair(-6, -36), Pair(30, -62), Pair(12, -53),
        Pair(-39, -70), Pair(-4, -50), Pair(29, -89), Pair(-28, -87), Pair(-12, -60), Pair(-30, -76), Pair(-3, -33), Pair(-7, -30),
        Pair(-43, -50), Pair(36, -67), Pair(35, -23), Pair(83, -100), Pair(34, -83), Pair(53, -79), Pair(59, -21), Pair(-52, -55),
        Pair(12, -59), Pair(6, -2), Pair(25, -53), Pair(34, -44), Pair(-24, -67), Pair(-59, -47), Pair(-15, -104), Pair(-8, -31)
      },
      { // Piece 4
        Pair(-113, -139), Pair(-37, -79), Pair(-45, -72), Pair(18, -19), Pair(104, -18), Pair(-4, -19), Pair(-42, -54), Pair(27, -62),
        Pair(4, -25), Pair(-6, -73), Pair(24, 52), Pair(0, -43), Pair(-19, -31), Pair(0, 24), Pair(-38, -84), Pair(-55, -66),
        Pair(-3, -41), Pair(-33, -61), Pair(-56, -55), Pair(46, 14), Pair(19, -7), Pair(2, -5), Pair(-40, -77), Pair(-32, -39),
        Pair(2, 4), Pair(27, 53), Pair(16, 21), Pair(14, 19), Pair(-2, -7), Pair(25, 44), Pair(15, 32), Pair(1, 2),
        Pair(5, 0), Pair(-6, -31), Pair(35, 36), Pair(41, 42), Pair(62, 96), Pair(-8, 6), Pair(23, 28), Pair(-6, -29),
        Pair(22, 9), Pair(38, 50), Pair(-6, -25), Pair(-18, -52), Pair(-7, -2), Pair(0, 9), Pair(-45, -62), Pair(-25, -14),
        Pair(37, 51), Pair(-29, -73), Pair(-27, -60), Pair(16, 27), Pair(9, 46), Pair(12, 7), Pair(-10, -20), Pair(-9, -18),
        Pair(-31, -55), Pair(-9, -24), Pair(-5, -11), Pair(-16, -40), Pair(5, -2), Pair(-19, -45), Pair(-27, -43), Pair(-21, -29)
      },
      { // Piece 5
        Pair(-62, -66), Pair(45, -42), Pair(-25, -14), Pair(-90, 26), Pair(48, -37), Pair(-35, -21), Pair(71, -25), Pair(-31, -74),
        Pair(-57, -26), Pair(105, -16), Pair(15, 3), Pair(86, -5), Pair(40, 21), Pair(34, 13), Pair(7, 20), Pair(42, -33),
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
        Pair(-58, 81), Pair(55, 100), Pair(39, 94), Pair(33, 85), Pair(71, 135), Pair(58, 140), Pair(-8, 130), Pair(-55, 99),
        Pair(-38, 135), Pair(37, 167), Pair(96, 117), Pair(-61, 153), Pair(44, 136), Pair(33, 145), Pair(-48, 168), Pair(-107, 139),
        Pair(-146, 110), Pair(-4, 74), Pair(-26, 107), Pair(21, 86), Pair(-27, 103), Pair(-66, 98), Pair(-117, 84), Pair(-61, 70),
        Pair(-74, 59), Pair(-56, 74), Pair(-1, 58), Pair(66, 39), Pair(39, 53), Pair(-79, 50), Pair(-9, 62), Pair(-140, 56),
        Pair(-79, 45), Pair(-36, 33), Pair(-52, 38), Pair(5, 59), Pair(26, 26), Pair(27, 33), Pair(-88, 63), Pair(-17, 32),
        Pair(-124, 55), Pair(-74, 68), Pair(14, 59), Pair(21, 132), Pair(-28, 36), Pair(-90, 77), Pair(-29, 71), Pair(-23, 58),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-20, -121), Pair(-48, -125), Pair(4, -65), Pair(1, -7), Pair(-35, -89), Pair(-18, -72), Pair(6, -67), Pair(14, 65),
        Pair(8, -21), Pair(-28, -109), Pair(-25, -73), Pair(4, -92), Pair(-41, -94), Pair(-73, -98), Pair(-15, -57), Pair(4, -44),
        Pair(-3, -129), Pair(-55, -126), Pair(15, -93), Pair(21, -27), Pair(-18, -123), Pair(28, -11), Pair(32, -113), Pair(-5, -28),
        Pair(-19, -38), Pair(-37, -45), Pair(-7, -61), Pair(36, -28), Pair(-31, -92), Pair(-27, -35), Pair(6, -87), Pair(-9, -88),
        Pair(-19, -143), Pair(-12, -75), Pair(35, -46), Pair(-10, -70), Pair(16, -55), Pair(-56, -120), Pair(-15, -100), Pair(-8, -116),
        Pair(-21, -43), Pair(-11, -48), Pair(-29, -97), Pair(4, -72), Pair(-24, -83), Pair(-40, 17), Pair(-5, -49), Pair(-18, -85),
        Pair(-25, -45), Pair(3, -16), Pair(-16, -129), Pair(-17, -43), Pair(-38, -32), Pair(-14, -104), Pair(-4, -83), Pair(-14, -64),
        Pair(-11, -62), Pair(4, -18), Pair(-10, -144), Pair(-2, -80), Pair(0, -84), Pair(-30, -55), Pair(-11, -11), Pair(-7, -82)
      },
      { // Piece 2
        Pair(-2, -45), Pair(26, -6), Pair(-58, -96), Pair(26, 35), Pair(-30, -86), Pair(-13, -17), Pair(-30, -14), Pair(19, -47),
        Pair(-44, -67), Pair(7, -35), Pair(0, -23), Pair(-8, -36), Pair(0, -38), Pair(-6, -79), Pair(1, -72), Pair(18, -61),
        Pair(-57, -55), Pair(-25, -20), Pair(5, -39), Pair(9, -49), Pair(23, -53), Pair(-85, 2), Pair(-20, -64), Pair(19, -35),
        Pair(4, 41), Pair(-12, -9), Pair(-32, -23), Pair(-48, -38), Pair(15, -44), Pair(94, -23), Pair(-18, -27), Pair(-5, -77),
        Pair(5, 16), Pair(-17, -50), Pair(-22, -25), Pair(-19, -19), Pair(28, -18), Pair(-37, 9), Pair(-12, 19), Pair(-19, -61),
        Pair(5, -62), Pair(12, -71), Pair(15, -46), Pair(8, 1), Pair(-21, -87), Pair(5, -72), Pair(6, -33), Pair(6, -57),
        Pair(-17, 41), Pair(-14, -71), Pair(-45, -80), Pair(27, -94), Pair(-34, -65), Pair(-13, -38), Pair(-7, -120), Pair(-26, 57),
        Pair(-28, -86), Pair(19, 20), Pair(1, -63), Pair(14, -32), Pair(-47, -53), Pair(-14, 9), Pair(2, 12), Pair(-22, -38)
      },
      { // Piece 3
        Pair(112, -157), Pair(27, -94), Pair(13, -130), Pair(-25, -105), Pair(12, -87), Pair(-2, -95), Pair(48, -144), Pair(16, -110),
        Pair(-13, -132), Pair(-54, -121), Pair(7, -106), Pair(-5, -120), Pair(26, -85), Pair(-3, -79), Pair(-24, -140), Pair(-16, -140),
        Pair(-22, -90), Pair(31, -93), Pair(0, -127), Pair(-37, -116), Pair(37, -107), Pair(5, -120), Pair(36, -109), Pair(7, -86),
        Pair(68, -112), Pair(-31, -111), Pair(6, -140), Pair(-26, -77), Pair(27, -121), Pair(13, -145), Pair(32, -110), Pair(-45, -88),
        Pair(-43, -96), Pair(-10, -103), Pair(0, -111), Pair(-10, -92), Pair(55, -138), Pair(-13, -136), Pair(5, -128), Pair(-24, -174),
        Pair(-54, -108), Pair(-45, -144), Pair(-16, -138), Pair(18, -124), Pair(-7, -132), Pair(-88, -113), Pair(-6, -48), Pair(-27, -126),
        Pair(-6, -148), Pair(-33, -81), Pair(-28, -91), Pair(0, -119), Pair(-23, -82), Pair(-31, -93), Pair(-76, -104), Pair(27, -75),
        Pair(-36, -58), Pair(-18, -101), Pair(23, -95), Pair(4, -133), Pair(7, -121), Pair(-58, -109), Pair(28, -82), Pair(1, -55)
      },
      { // Piece 4
        Pair(-70, -127), Pair(-84, -62), Pair(-36, -29), Pair(0, -32), Pair(-16, -45), Pair(-95, -68), Pair(-48, -52), Pair(-44, -118),
        Pair(15, -3), Pair(-47, -52), Pair(-14, -26), Pair(26, 16), Pair(-15, -18), Pair(1, -40), Pair(-32, -53), Pair(-37, -58),
        Pair(-51, -58), Pair(8, -27), Pair(25, 22), Pair(-7, -41), Pair(16, 38), Pair(-5, -30), Pair(32, 28), Pair(-33, -46),
        Pair(-27, -57), Pair(52, 48), Pair(29, 22), Pair(-24, -55), Pair(5, 25), Pair(8, 0), Pair(41, 6), Pair(-8, -49),
        Pair(-21, -38), Pair(4, 22), Pair(12, 25), Pair(-5, -1), Pair(3, -8), Pair(33, 43), Pair(-25, -40), Pair(9, 3),
        Pair(-39, -69), Pair(12, 28), Pair(-5, -19), Pair(14, -4), Pair(50, 89), Pair(40, 47), Pair(21, 33), Pair(-12, -23),
        Pair(8, -20), Pair(-25, -63), Pair(-14, -38), Pair(-42, -74), Pair(7, 6), Pair(13, 22), Pair(-8, -24), Pair(17, 27),
        Pair(-3, -23), Pair(36, 25), Pair(-82, -145), Pair(36, 61), Pair(-36, -82), Pair(2, 8), Pair(-19, -56), Pair(1, 5)
      },
      { // Piece 5
        Pair(84, -78), Pair(-17, -13), Pair(7, -29), Pair(-63, 12), Pair(-8, -20), Pair(6, -15), Pair(74, -28), Pair(77, -87),
        Pair(-96, -23), Pair(14, 5), Pair(-41, 13), Pair(62, 5), Pair(-13, 10), Pair(17, 18), Pair(30, 16), Pair(-58, -16),
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
        Pair(-78, 67), Pair(10, 110), Pair(19, 153), Pair(34, 177), Pair(21, 159), Pair(70, 184), Pair(-39, 140), Pair(-20, 127),
        Pair(-68, 163), Pair(-39, 132), Pair(34, 154), Pair(38, 145), Pair(5, 140), Pair(6, 177), Pair(16, 124), Pair(-113, 148),
        Pair(-113, 74), Pair(-20, 53), Pair(-17, 142), Pair(13, 171), Pair(-29, 143), Pair(30, 132), Pair(-44, 127), Pair(-54, 121),
        Pair(-66, 28), Pair(-41, 71), Pair(40, 96), Pair(6, 53), Pair(13, 101), Pair(-16, 51), Pair(-52, 82), Pair(-7, 74),
        Pair(-56, -13), Pair(-34, 9), Pair(40, 33), Pair(-8, 115), Pair(27, 29), Pair(15, 22), Pair(14, 59), Pair(19, 26),
        Pair(-3, 41), Pair(-104, 31), Pair(10, 41), Pair(4, 64), Pair(-18, -57), Pair(29, 141), Pair(25, 60), Pair(-10, 27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-4, -8), Pair(-22, -71), Pair(4, 8), Pair(-2, -31), Pair(-5, -72), Pair(-1, 1), Pair(-6, -71), Pair(2, -40),
        Pair(-1, -26), Pair(6, -86), Pair(-17, -32), Pair(-27, -19), Pair(-8, 6), Pair(-10, -50), Pair(-5, -54), Pair(-25, -53),
        Pair(26, 15), Pair(-14, -54), Pair(-4, -2), Pair(-12, -41), Pair(-30, -96), Pair(-13, -63), Pair(16, -27), Pair(-7, -28),
        Pair(-2, 19), Pair(-1, -19), Pair(0, -74), Pair(-2, -15), Pair(-6, -70), Pair(5, -14), Pair(7, -22), Pair(-13, -134),
        Pair(-15, -2), Pair(1, -79), Pair(-27, -59), Pair(-33, -112), Pair(8, -83), Pair(1, -6), Pair(-3, -25), Pair(8, 9),
        Pair(-8, -29), Pair(-3, -7), Pair(14, 33), Pair(-13, -65), Pair(20, 52), Pair(5, 10), Pair(8, -12), Pair(-5, -12),
        Pair(-7, -82), Pair(13, 42), Pair(-6, -86), Pair(-1, -16), Pair(-2, -37), Pair(-1, 33), Pair(-2, -22), Pair(-1, -1),
        Pair(-3, -35), Pair(21, 6), Pair(1, -22), Pair(3, 40), Pair(-10, -57), Pair(-2, -23), Pair(5, 21), Pair(-2, -23)
      },
      { // Piece 2
        Pair(5, -21), Pair(11, -36), Pair(12, 37), Pair(-3, -18), Pair(-4, 30), Pair(-3, -76), Pair(-4, -60), Pair(-2, 17),
        Pair(-5, -35), Pair(-43, -46), Pair(-25, -47), Pair(-22, -39), Pair(-43, -66), Pair(2, 1), Pair(9, 46), Pair(1, -30),
        Pair(-7, 12), Pair(-1, -1), Pair(-11, 22), Pair(4, -50), Pair(-12, -62), Pair(-31, -5), Pair(-6, -73), Pair(-9, -61),
        Pair(-1, -4), Pair(-2, 23), Pair(8, -33), Pair(3, 76), Pair(31, -7), Pair(-8, -59), Pair(-34, 10), Pair(-10, -103),
        Pair(-2, -12), Pair(-5, 43), Pair(-7, 46), Pair(5, -69), Pair(-33, -24), Pair(6, 11), Pair(0, -2), Pair(3, 36),
        Pair(-4, -55), Pair(-9, 10), Pair(-16, -60), Pair(7, 11), Pair(-23, -38), Pair(-6, -69), Pair(-1, 19), Pair(-3, -36),
        Pair(-21, 5), Pair(9, 37), Pair(15, 32), Pair(-17, -124), Pair(34, 95), Pair(-4, -24), Pair(16, 34), Pair(1, -2),
        Pair(-6, 41), Pair(-2, -15), Pair(-8, -61), Pair(-6, -105), Pair(-8, -32), Pair(-5, -42), Pair(-2, -17), Pair(-12, 12)
      },
      { // Piece 3
        Pair(-11, -33), Pair(6, -43), Pair(3, -80), Pair(-19, -24), Pair(-38, -26), Pair(5, -71), Pair(-25, -42), Pair(-4, -50),
        Pair(-5, -84), Pair(-9, -45), Pair(18, -8), Pair(-5, -10), Pair(-18, -98), Pair(-26, -79), Pair(-32, -35), Pair(16, -18),
        Pair(10, -13), Pair(13, -71), Pair(-7, -89), Pair(17, 18), Pair(-9, -43), Pair(13, 14), Pair(19, -29), Pair(-29, 14),
        Pair(6, 6), Pair(-1, -83), Pair(-13, -58), Pair(-7, -119), Pair(-23, -93), Pair(54, -46), Pair(-47, -108), Pair(-11, -40),
        Pair(20, -83), Pair(47, -23), Pair(-5, -72), Pair(-18, -114), Pair(16, -20), Pair(-17, -36), Pair(17, 8), Pair(-11, -61),
        Pair(9, -53), Pair(-16, -99), Pair(-21, -91), Pair(37, -53), Pair(-23, -102), Pair(4, -17), Pair(-30, -106), Pair(-33, -77),
        Pair(7, 31), Pair(-2, 63), Pair(-59, -81), Pair(2, 13), Pair(22, -20), Pair(-42, -84), Pair(-4, -34), Pair(17, -75),
        Pair(-22, -52), Pair(19, -31), Pair(3, 1), Pair(17, -14), Pair(42, -28), Pair(-18, -26), Pair(-25, -72), Pair(-19, -85)
      },
      { // Piece 4
        Pair(3, -42), Pair(-54, -51), Pair(9, 40), Pair(30, 30), Pair(-4, 33), Pair(-79, -63), Pair(-31, -49), Pair(58, -43),
        Pair(-25, -56), Pair(0, -26), Pair(-47, -92), Pair(-20, -41), Pair(7, -35), Pair(-21, -35), Pair(2, 9), Pair(-106, -188),
        Pair(18, 34), Pair(-33, -43), Pair(-3, 2), Pair(-34, -45), Pair(17, 21), Pair(28, 43), Pair(-1, 21), Pair(-28, -37),
        Pair(-8, -20), Pair(32, 70), Pair(8, -9), Pair(-8, -27), Pair(36, 80), Pair(2, 30), Pair(-8, 1), Pair(3, 8),
        Pair(29, 54), Pair(-2, -1), Pair(-12, -25), Pair(-33, -23), Pair(-12, -4), Pair(-22, -34), Pair(16, 2), Pair(15, 27),
        Pair(-9, -29), Pair(33, 52), Pair(9, 17), Pair(25, 11), Pair(-4, 13), Pair(-9, -7), Pair(-15, -30), Pair(-10, -26),
        Pair(23, -21), Pair(15, 11), Pair(47, 74), Pair(13, 34), Pair(-20, -21), Pair(14, 47), Pair(7, 14), Pair(22, 28),
        Pair(-15, -52), Pair(3, 14), Pair(33, 59), Pair(0, -24), Pair(11, 31), Pair(-26, -72), Pair(-23, -50), Pair(-19, -42)
      },
      { // Piece 5
        Pair(-65, -68), Pair(44, -35), Pair(145, -30), Pair(-73, 6), Pair(25, 13), Pair(-18, 25), Pair(-3, -21), Pair(15, -49),
        Pair(35, -12), Pair(-12, 45), Pair(36, 32), Pair(1, 37), Pair(-64, 2), Pair(32, 15), Pair(-53, 20), Pair(-58, 27),
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
  Pair(-3, 50), Pair(13, 28), Pair(20, 52), Pair(24, 64), Pair(28, 72), Pair(32, 79), Pair(37, 79), Pair(41, 76),
  Pair(44, 65)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-12, 11), Pair(-3, -12), Pair(6, 6), Pair(11, 22), Pair(17, 34), Pair(20, 46), Pair(21, 54), Pair(23, 58),
  Pair(24, 64), Pair(30, 64), Pair(37, 62), Pair(52, 59), Pair(50, 77), Pair(72, 51)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-37, -15), Pair(-26, 5), Pair(-24, 17), Pair(-22, 30), Pair(-19, 35), Pair(-13, 38), Pair(-9, 44), Pair(-3, 45),
  Pair(2, 48), Pair(6, 52), Pair(10, 55), Pair(14, 58), Pair(21, 59), Pair(33, 54), Pair(64, 38)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-34, 112), Pair(-12, 30), Pair(-4, 54), Pair(3, 76), Pair(3, 104), Pair(5, 125), Pair(8, 140), Pair(8, 160),
  Pair(10, 169), Pair(14, 170), Pair(15, 179), Pair(16, 184), Pair(20, 183), Pair(19, 188), Pair(20, 188), Pair(22, 187),
  Pair(21, 189), Pair(24, 185), Pair(29, 179), Pair(43, 164), Pair(48, 154), Pair(74, 134), Pair(76, 119), Pair(95, 100),
  Pair(77, 110), Pair(185, 41), Pair(230, 5), Pair(160, 37)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-17, -82), Pair(-18, -68), Pair(-10, -36), Pair(20, -2), Pair(28, 65), Pair(130, 160), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 0), Pair(16, 6), Pair(17, 19), Pair(47, 69), Pair(131, 159), Pair(-113, 425), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 11), Pair(14, 8), Pair(18, 15), Pair(36, 50), Pair(209, 33), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-24, -46), Pair(-1, -31), Pair(-5, -23), Pair(-6, -16), Pair(-15, -8), Pair(-15, -13), Pair(1, -26), Pair(-20, -45)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(0, 4), Pair(-5, -10), Pair(-11, -8), Pair(-10, -16), Pair(-11, -17), Pair(-6, -9), Pair(-5, -10), Pair(2, 1)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(22, 6), Pair(22, 3), Pair(23, 7), Pair(23, 7), Pair(26, 11), Pair(39, 3), Pair(48, -2), Pair(64, -5)
  },
  {
      Pair(11, 27), Pair(13, 9), Pair(15, 7), Pair(18, 2), Pair(16, 2), Pair(22, -2), Pair(30, -5), Pair(22, 11)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -2), Pair(26, -6), Pair(15, -1),
  Pair(33, -13), Pair(32, -15), Pair(32, -13),
  Pair(44, -8), Pair(0, 0), Pair(37, -6),
  Pair(13, 2), Pair(17, -7), Pair(12, 3)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-10, 5), Pair(-17, 9), Pair(-9, 7),
  Pair(-10, 5), Pair(-21, 9), Pair(-11, 5),
  Pair(-6, -3), Pair(-14, 5), Pair(-2, -3),
  Pair(10, -4), Pair(-4, 0), Pair(12, -4),
  Pair(33, -16), Pair(36, -6), Pair(28, -15),
  Pair(29, -5), Pair(-7, -20), Pair(39, -19),
  Pair(57, -52), Pair(0, 0), Pair(52, -50)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-5, 68), Pair(-6, 55), Pair(-4, 41), Pair(1, 32), Pair(2, 28), Pair(7, 25), Pair(1, 16)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-36, -19), Pair(-13, 7), Pair(-5, 30), Pair(3, 42), Pair(7, 49), Pair(8, 55), Pair(-1, 55)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-733, 156);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-59, -17), Pair(-72, -8), Pair(-23, -15), Pair(-18, -16), Pair(-17, -11), Pair(-18, -10), Pair(-46, -4), Pair(-28, -1)
  },
  {
      Pair(-32, 51), Pair(-42, 21), Pair(-6, 7), Pair(0, -5), Pair(-2, -5), Pair(1, 0), Pair(-28, 17), Pair(-26, 30)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 3), Pair(26, -3), Pair(69, -17), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 3), Pair(26, 2), Pair(60, -5), Pair(87, -33), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(23, -17), Pair(39, -17), Pair(59, -13), Pair(95, -16), Pair(120, -27), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 17), Pair(16, 34), Pair(35, 45), Pair(90, 33), Pair(141, 24), Pair(234, -17), Pair(329, -75)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(38, 6), Pair(13, 16), Pair(41, -2), Pair(21, 15), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-8, 14), Pair(-6, 22)
  },
  {
      Pair(-63, -30), Pair(-53, -43)
  },
  {
      Pair(-50, -56), Pair(-57, -74)
  },
  {
      Pair(-92, 13), Pair(-64, -30)
  },
  {
      Pair(-48, -3), Pair(-57, -12)
  },
  {
      Pair(-43, 15), Pair(-26, 3)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(17, 36), Pair(18, 29), Pair(28, 17), Pair(20, 4), Pair(40, -2)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-1, -20), Pair(7, -8)
  },
  {
      Pair(-18, -30), Pair(-8, -31)
  },
  {
      Pair(-30, -32), Pair(-23, -42)
  },
  {
      Pair(-66, -5), Pair(-46, -26)
  },
  {
      Pair(-38, -2), Pair(-39, -3)
  },
  {
      Pair(-105, 0), Pair(-60, -36)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-12, -16), Pair(1, -6)
  },
  {
      Pair(-42, -26), Pair(-23, -37)
  },
  {
      Pair(2, -73), Pair(5, -80)
  },
  {
      Pair(-64, -4), Pair(-41, -27)
  },
  {
      Pair(-61, -10), Pair(-41, -65)
  },
  {
      Pair(-39, -15), Pair(-39, -36)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(1, -21), Pair(12, -8)
  },
  {
      Pair(-33, -23), Pair(-1, -14)
  },
  {
      Pair(-21, -23), Pair(-7, -8)
  },
  {
      Pair(16, -46), Pair(13, -34)
  },
  {
      Pair(-60, -4), Pair(-38, -46)
  },
  {
      Pair(-69, 2), Pair(-51, -24)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(34, 15), Pair(20, 29), Pair(37, 25), Pair(40, 27), Pair(35, 35), Pair(39, 38), Pair(27, 37), Pair(39, 14),
  Pair(15, 11), Pair(15, 20), Pair(20, 25), Pair(7, 43), Pair(8, 31), Pair(6, 29), Pair(10, 23), Pair(4, 24),
  Pair(7, 14), Pair(9, 12), Pair(4, 21), Pair(12, 21), Pair(4, 23), Pair(-6, 22), Pair(-4, 12), Pair(1, 9)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-10, 32), Pair(26, 6), Pair(34, -2), Pair(45, 3), Pair(60, -8), Pair(63, 0), Pair(18, 17), Pair(-8, -5),
  Pair(-20, -6), Pair(21, 13), Pair(23, -1), Pair(33, 8), Pair(16, 11), Pair(18, 6), Pair(10, 18), Pair(-1, 7),
  Pair(-26, 27), Pair(10, 11), Pair(5, 17), Pair(17, 13), Pair(20, 20), Pair(0, 8), Pair(3, 9), Pair(-39, 0)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 63);

constexpr ScorePair kTempoBonus = Pair(20, 21);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H