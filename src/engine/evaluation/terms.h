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
  Pair(69, 127), Pair(335, 341), Pair(360, 395), Pair(446, 750), Pair(941, 1287), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-86, 92), Pair(-102, 108), Pair(-60, 27), Pair(-40, 9), Pair(-9, -43), Pair(-3, -62), Pair(-65, -139), Pair(-177, -2),
        Pair(18, 89), Pair(10, 85), Pair(41, 37), Pair(62, -34), Pair(74, -14), Pair(121, -32), Pair(87, 9), Pair(42, 47),
        Pair(2, 35), Pair(14, 26), Pair(12, 0), Pair(14, -23), Pair(39, -31), Pair(43, -34), Pair(21, 2), Pair(21, -13),
        Pair(-1, 10), Pair(3, 23), Pair(9, -10), Pair(18, -17), Pair(25, -24), Pair(37, -29), Pair(25, -13), Pair(21, -25),
        Pair(-13, 10), Pair(-8, 18), Pair(-6, -1), Pair(2, -3), Pair(8, 4), Pair(10, -13), Pair(20, -10), Pair(18, -35),
        Pair(0, 10), Pair(5, 19), Pair(3, 4), Pair(8, -13), Pair(15, 15), Pair(30, -2), Pair(34, -6), Pair(11, -41),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-186, 100), Pair(-165, 100), Pair(-85, 108), Pair(-74, 67), Pair(-86, 86), Pair(-17, -52), Pair(-149, 83), Pair(-112, -85),
        Pair(-40, 88), Pair(-23, 104), Pair(-8, 89), Pair(-16, 103), Pair(-13, 88), Pair(79, 46), Pair(48, 40), Pair(-1, 59),
        Pair(-5, 72), Pair(4, 97), Pair(-1, 117), Pair(10, 92), Pair(32, 68), Pair(80, 65), Pair(1, 87), Pair(40, 66),
        Pair(8, 95), Pair(19, 99), Pair(37, 98), Pair(39, 117), Pair(34, 103), Pair(50, 96), Pair(22, 101), Pair(37, 79),
        Pair(-8, 84), Pair(19, 78), Pair(27, 101), Pair(32, 96), Pair(32, 109), Pair(43, 80), Pair(31, 87), Pair(7, 78),
        Pair(-22, 65), Pair(-1, 78), Pair(10, 83), Pair(20, 98), Pair(32, 98), Pair(21, 81), Pair(18, 82), Pair(-1, 82),
        Pair(-33, 69), Pair(-17, 73), Pair(-7, 77), Pair(11, 73), Pair(9, 79), Pair(7, 56), Pair(6, 71), Pair(2, 86),
        Pair(-56, 54), Pair(-16, 59), Pair(-19, 68), Pair(-6, 81), Pair(6, 78), Pair(9, 67), Pair(-16, 59), Pair(-24, 63)
      },
      { // Piece 2
        Pair(-35, 101), Pair(-60, 78), Pair(-77, 85), Pair(-86, 96), Pair(-87, 63), Pair(-32, 3), Pair(-57, 112), Pair(-22, 58),
        Pair(-22, 88), Pair(-10, 98), Pair(5, 62), Pair(-23, 96), Pair(-10, 49), Pair(-11, 73), Pair(-49, 116), Pair(-42, 111),
        Pair(3, 96), Pair(2, 96), Pair(4, 83), Pair(-6, 64), Pair(-13, 81), Pair(48, 90), Pair(28, 101), Pair(11, 111),
        Pair(-10, 79), Pair(4, 91), Pair(5, 81), Pair(12, 115), Pair(15, 72), Pair(17, 77), Pair(4, 83), Pair(-8, 94),
        Pair(-1, 72), Pair(-11, 81), Pair(5, 93), Pair(15, 64), Pair(12, 72), Pair(9, 66), Pair(-2, 81), Pair(16, 45),
        Pair(-2, 53), Pair(20, 92), Pair(15, 80), Pair(11, 86), Pair(12, 100), Pair(20, 85), Pair(26, 64), Pair(24, 69),
        Pair(15, 70), Pair(16, 44), Pair(24, 50), Pair(7, 69), Pair(20, 74), Pair(28, 78), Pair(43, 71), Pair(36, 31),
        Pair(19, 35), Pair(37, 53), Pair(12, 63), Pair(6, 72), Pair(27, 57), Pair(31, 79), Pair(34, 64), Pair(53, 4)
      },
      { // Piece 3
        Pair(26, 214), Pair(82, 194), Pair(-3, 251), Pair(47, 184), Pair(104, 137), Pair(-24, 221), Pair(-70, 180), Pair(81, 54),
        Pair(26, 134), Pair(36, 144), Pair(46, 155), Pair(58, 139), Pair(44, 127), Pair(79, 116), Pair(118, 132), Pair(89, 113),
        Pair(26, 125), Pair(67, 124), Pair(54, 135), Pair(56, 123), Pair(87, 101), Pair(113, 81), Pair(172, 68), Pair(101, 77),
        Pair(51, 108), Pair(57, 128), Pair(71, 119), Pair(63, 117), Pair(69, 110), Pair(76, 96), Pair(93, 90), Pair(72, 75),
        Pair(31, 112), Pair(39, 124), Pair(42, 116), Pair(44, 122), Pair(44, 112), Pair(29, 114), Pair(77, 80), Pair(58, 55),
        Pair(23, 106), Pair(31, 109), Pair(36, 115), Pair(33, 122), Pair(45, 104), Pair(49, 90), Pair(93, 54), Pair(69, 34),
        Pair(21, 98), Pair(22, 125), Pair(47, 106), Pair(43, 117), Pair(51, 100), Pair(50, 90), Pair(91, 43), Pair(48, 46),
        Pair(34, 113), Pair(40, 109), Pair(43, 113), Pair(50, 108), Pair(54, 98), Pair(53, 103), Pair(59, 88), Pair(15, 102)
      },
      { // Piece 4
        Pair(-65, 300), Pair(58, 186), Pair(16, 248), Pair(40, 245), Pair(69, 168), Pair(35, 281), Pair(82, 182), Pair(127, 36),
        Pair(-8, 212), Pair(5, 218), Pair(4, 253), Pair(-4, 259), Pair(-29, 302), Pair(4, 305), Pair(-36, 307), Pair(-1, 271),
        Pair(18, 205), Pair(19, 216), Pair(19, 237), Pair(12, 251), Pair(18, 245), Pair(42, 267), Pair(47, 249), Pair(42, 215),
        Pair(13, 212), Pair(31, 205), Pair(23, 221), Pair(22, 242), Pair(26, 237), Pair(50, 193), Pair(40, 228), Pair(50, 190),
        Pair(16, 203), Pair(14, 223), Pair(24, 209), Pair(23, 231), Pair(31, 220), Pair(24, 215), Pair(46, 194), Pair(39, 200),
        Pair(21, 188), Pair(26, 200), Pair(23, 213), Pair(19, 215), Pair(19, 221), Pair(32, 203), Pair(56, 174), Pair(51, 135),
        Pair(27, 164), Pair(28, 174), Pair(29, 181), Pair(32, 195), Pair(35, 186), Pair(44, 150), Pair(54, 127), Pair(78, 45),
        Pair(20, 186), Pair(21, 179), Pair(28, 176), Pair(29, 179), Pair(32, 171), Pair(28, 147), Pair(31, 110), Pair(35, 115)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, -19), Pair(18, 24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-4, 23), Pair(5, -27)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(57, 10), Pair(-86, 78), Pair(-43, -76), Pair(-11, -111), Pair(-3, -138), Pair(-5, -83), Pair(-99, 83), Pair(15, 126),
        Pair(8, 58), Pair(20, 44), Pair(70, -32), Pair(61, -53), Pair(88, -86), Pair(53, 7), Pair(57, 24), Pair(57, 45),
        Pair(-13, 26), Pair(-1, 21), Pair(8, -11), Pair(8, -31), Pair(25, -37), Pair(14, -29), Pair(22, -5), Pair(23, 10),
        Pair(-24, 6), Pair(-13, 5), Pair(-5, -20), Pair(15, -18), Pair(14, -26), Pair(17, -31), Pair(-8, 2), Pair(19, -23),
        Pair(-41, 9), Pair(-28, 9), Pair(-17, -16), Pair(-4, -12), Pair(1, -19), Pair(-11, -21), Pair(-2, -12), Pair(10, -29),
        Pair(-26, 9), Pair(-17, 14), Pair(-15, 2), Pair(4, -7), Pair(11, -1), Pair(3, -10), Pair(12, -5), Pair(0, -20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-94, -79), Pair(-56, 28), Pair(-128, 68), Pair(-30, -7), Pair(72, -8), Pair(-61, 41), Pair(-128, 2), Pair(-115, -6),
        Pair(0, 29), Pair(-45, 82), Pair(-33, 75), Pair(-42, 27), Pair(20, -37), Pair(6, 49), Pair(-1, 61), Pair(-27, 17),
        Pair(-29, 27), Pair(-12, 52), Pair(-24, 62), Pair(43, 24), Pair(3, 19), Pair(10, 27), Pair(-32, 65), Pair(25, -1),
        Pair(7, 74), Pair(-14, 51), Pair(-1, 57), Pair(8, 75), Pair(16, 65), Pair(17, 75), Pair(26, 54), Pair(13, 33),
        Pair(-27, 45), Pair(-15, 53), Pair(8, 71), Pair(18, 60), Pair(9, 68), Pair(30, 19), Pair(-3, 66), Pair(-12, 43),
        Pair(-42, 35), Pair(-18, 37), Pair(-13, 39), Pair(2, 45), Pair(14, 42), Pair(0, 40), Pair(0, 35), Pair(-24, 23),
        Pair(-54, 32), Pair(-44, 49), Pair(-29, 18), Pair(-6, 28), Pair(-7, 26), Pair(-5, 11), Pair(-10, -18), Pair(-19, 55),
        Pair(-97, 41), Pair(-49, 47), Pair(-36, 35), Pair(-15, 34), Pair(-16, 26), Pair(-10, 3), Pair(-43, 57), Pair(-39, -118)
      },
      { // Piece 2
        Pair(9, 11), Pair(-64, -10), Pair(-68, -10), Pair(-195, 64), Pair(-131, 38), Pair(-79, -16), Pair(-31, 18), Pair(-13, -2),
        Pair(-18, -9), Pair(-40, 43), Pair(-4, 9), Pair(-20, 30), Pair(-19, 88), Pair(-14, 17), Pair(-61, 29), Pair(-53, -5),
        Pair(-25, 47), Pair(24, 11), Pair(-24, 36), Pair(38, 32), Pair(27, 11), Pair(-2, 65), Pair(23, 16), Pair(-2, 58),
        Pair(-37, 58), Pair(-4, 37), Pair(1, 40), Pair(0, 19), Pair(15, 17), Pair(14, 22), Pair(-3, 24), Pair(-13, 14),
        Pair(-21, 53), Pair(-31, 33), Pair(-17, 25), Pair(3, 36), Pair(3, 22), Pair(-4, 26), Pair(-17, 23), Pair(-11, 34),
        Pair(-15, 34), Pair(2, 22), Pair(6, 18), Pair(-3, 27), Pair(5, 26), Pair(4, 24), Pair(21, 29), Pair(8, 16),
        Pair(9, -5), Pair(6, 8), Pair(19, 2), Pair(-6, 16), Pair(0, 16), Pair(13, 43), Pair(37, 10), Pair(7, 60),
        Pair(-2, 5), Pair(1, 38), Pair(-5, 25), Pair(8, -3), Pair(14, 30), Pair(1, 27), Pair(-11, 62), Pair(28, -45)
      },
      { // Piece 3
        Pair(75, 48), Pair(111, 95), Pair(36, 127), Pair(3, 54), Pair(56, 21), Pair(2, 103), Pair(57, 60), Pair(24, 70),
        Pair(36, 43), Pair(41, 53), Pair(37, 49), Pair(65, 20), Pair(-5, 41), Pair(-15, 74), Pair(28, 64), Pair(9, 64),
        Pair(1, 64), Pair(47, 52), Pair(37, 40), Pair(60, -2), Pair(25, 27), Pair(37, 21), Pair(69, 12), Pair(24, 7),
        Pair(39, 16), Pair(21, 34), Pair(14, 48), Pair(17, 21), Pair(24, 12), Pair(41, 1), Pair(23, 23), Pair(8, 44),
        Pair(11, -10), Pair(-19, 37), Pair(4, 31), Pair(-3, 30), Pair(11, 21), Pair(-15, 48), Pair(3, 29), Pair(1, 37),
        Pair(-31, 40), Pair(-4, 14), Pair(23, 8), Pair(4, 18), Pair(0, 23), Pair(-11, 35), Pair(12, 20), Pair(-11, 33),
        Pair(-6, -6), Pair(0, 4), Pair(-10, 35), Pair(-17, 25), Pair(-9, 26), Pair(-10, 20), Pair(18, 5), Pair(-5, -15),
        Pair(-13, 25), Pair(2, 20), Pair(9, 23), Pair(11, 8), Pair(22, 6), Pair(5, 22), Pair(-10, 26), Pair(-26, 11)
      },
      { // Piece 4
        Pair(65, 37), Pair(53, 69), Pair(35, 77), Pair(24, -11), Pair(-66, 66), Pair(-45, 115), Pair(17, 106), Pair(52, 34),
        Pair(59, 35), Pair(28, 35), Pair(21, 95), Pair(-23, 130), Pair(-87, 218), Pair(-5, 121), Pair(6, 92), Pair(73, 30),
        Pair(22, 30), Pair(45, -7), Pair(28, 61), Pair(28, 114), Pair(21, 77), Pair(25, 94), Pair(44, 57), Pair(32, 69),
        Pair(32, 39), Pair(18, 76), Pair(42, 71), Pair(-5, 101), Pair(-2, 178), Pair(28, 90), Pair(25, 114), Pair(65, 20),
        Pair(23, 37), Pair(-3, 90), Pair(6, 109), Pair(6, 69), Pair(29, 71), Pair(8, 83), Pair(29, 50), Pair(25, 100),
        Pair(28, 14), Pair(21, 49), Pair(12, 81), Pair(14, 59), Pair(18, 68), Pair(26, 38), Pair(30, 52), Pair(11, 65),
        Pair(8, -15), Pair(31, -5), Pair(23, 20), Pair(22, 32), Pair(37, 5), Pair(34, -6), Pair(18, 28), Pair(23, 4),
        Pair(10, 29), Pair(2, 71), Pair(12, 32), Pair(18, 7), Pair(37, -46), Pair(10, 23), Pair(4, -25), Pair(-35, 22)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(2, -41), Pair(35, -7), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(12, 2), Pair(21, -42)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-68, 36), Pair(-34, -3), Pair(-57, -40), Pair(-68, -53), Pair(-3, -115), Pair(-31, -70), Pair(-47, -33), Pair(7, -6),
        Pair(-2, 60), Pair(-10, 61), Pair(30, -10), Pair(39, -29), Pair(33, -44), Pair(100, -46), Pair(13, 50), Pair(6, 21),
        Pair(-5, 28), Pair(-10, 24), Pair(-7, -2), Pair(1, -18), Pair(31, -27), Pair(22, -14), Pair(11, 12), Pair(-5, 6),
        Pair(-18, 5), Pair(-17, 18), Pair(-4, -9), Pair(-1, -11), Pair(5, -14), Pair(10, -19), Pair(8, -3), Pair(8, -14),
        Pair(-27, 3), Pair(-31, 18), Pair(-17, -5), Pair(-13, -1), Pair(4, -6), Pair(-10, -11), Pair(5, -10), Pair(10, -27),
        Pair(-14, 3), Pair(-20, 21), Pair(-8, 1), Pair(-14, -3), Pair(4, 24), Pair(7, -4), Pair(24, -9), Pair(2, -26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-137, -62), Pair(-127, 89), Pair(-108, 44), Pair(-12, 7), Pair(-15, -23), Pair(-1, -84), Pair(-68, -15), Pair(-117, -57),
        Pair(-24, 10), Pair(-20, 60), Pair(-6, 37), Pair(44, 6), Pair(24, 8), Pair(-6, 41), Pair(-2, 9), Pair(-59, 4),
        Pair(-48, 98), Pair(5, 41), Pair(17, 51), Pair(51, 25), Pair(48, 25), Pair(106, -22), Pair(45, 18), Pair(8, -22),
        Pair(8, 36), Pair(16, 48), Pair(31, 54), Pair(52, 52), Pair(55, 51), Pair(56, 49), Pair(32, 58), Pair(33, 12),
        Pair(-21, 47), Pair(4, 60), Pair(31, 60), Pair(39, 53), Pair(44, 55), Pair(62, 37), Pair(52, 32), Pair(17, 47),
        Pair(-47, 58), Pair(-13, 44), Pair(2, 59), Pair(19, 69), Pair(47, 50), Pair(21, 35), Pair(20, 24), Pair(3, 33),
        Pair(-51, 25), Pair(-42, 55), Pair(-15, 34), Pair(6, 49), Pair(10, 49), Pair(-1, 30), Pair(7, 24), Pair(-4, 31),
        Pair(-78, 2), Pair(-39, 35), Pair(-31, 39), Pair(10, 15), Pair(-14, 51), Pair(-5, 33), Pair(-7, 21), Pair(-42, 52)
      },
      { // Piece 2
        Pair(-20, 48), Pair(-75, 65), Pair(-20, 21), Pair(-187, 51), Pair(-91, 6), Pair(-55, 8), Pair(-122, 66), Pair(-72, -6),
        Pair(-33, 26), Pair(-15, 20), Pair(-3, 25), Pair(-19, 14), Pair(-24, 22), Pair(-28, 30), Pair(-36, 49), Pair(-9, -17),
        Pair(10, 12), Pair(15, 27), Pair(-36, 56), Pair(7, 15), Pair(-32, 36), Pair(-37, 45), Pair(-24, 31), Pair(8, 10),
        Pair(-36, 46), Pair(-11, 45), Pair(17, 26), Pair(-1, 50), Pair(37, 33), Pair(48, 28), Pair(28, 23), Pair(-1, 27),
        Pair(-31, 40), Pair(-9, 30), Pair(2, 32), Pair(20, 22), Pair(21, 23), Pair(10, 21), Pair(-9, 19), Pair(8, 3),
        Pair(0, 14), Pair(1, 40), Pair(7, 42), Pair(6, 34), Pair(11, 43), Pair(16, 31), Pair(21, 10), Pair(8, 25),
        Pair(-13, 29), Pair(6, 15), Pair(15, 18), Pair(0, 33), Pair(7, 27), Pair(25, 33), Pair(32, 19), Pair(12, 26),
        Pair(-34, 47), Pair(26, -2), Pair(5, 25), Pair(2, 19), Pair(-8, 29), Pair(11, 42), Pair(34, 16), Pair(29, 6)
      },
      { // Piece 3
        Pair(-24, 60), Pair(-33, 79), Pair(-3, 67), Pair(-21, 69), Pair(16, 54), Pair(46, 47), Pair(-13, 94), Pair(-17, 59),
        Pair(19, 53), Pair(21, 71), Pair(36, 65), Pair(37, 64), Pair(15, 61), Pair(31, 58), Pair(16, 64), Pair(38, 54),
        Pair(15, 47), Pair(54, 48), Pair(33, 56), Pair(27, 42), Pair(65, 33), Pair(113, 1), Pair(138, 0), Pair(53, 6),
        Pair(-3, 56), Pair(13, 63), Pair(32, 56), Pair(32, 42), Pair(58, 23), Pair(55, 38), Pair(74, 2), Pair(18, 27),
        Pair(-6, 35), Pair(-20, 70), Pair(24, 40), Pair(16, 49), Pair(21, 39), Pair(23, 30), Pair(49, 17), Pair(5, 33),
        Pair(-1, 26), Pair(-3, 48), Pair(-2, 51), Pair(5, 51), Pair(24, 26), Pair(21, 23), Pair(50, -6), Pair(57, -45),
        Pair(-17, 43), Pair(-3, 45), Pair(-3, 46), Pair(11, 52), Pair(12, 33), Pair(21, 19), Pair(18, 27), Pair(-1, -7),
        Pair(-8, 47), Pair(1, 37), Pair(8, 40), Pair(13, 39), Pair(20, 28), Pair(19, 34), Pair(17, 26), Pair(-26, 31)
      },
      { // Piece 4
        Pair(-25, 77), Pair(-56, 105), Pair(-1, 74), Pair(19, 63), Pair(17, 76), Pair(10, 112), Pair(82, 13), Pair(24, 80),
        Pair(18, 66), Pair(12, 82), Pair(44, 81), Pair(33, 63), Pair(-33, 131), Pair(11, 75), Pair(19, 129), Pair(73, 70),
        Pair(34, 67), Pair(20, 92), Pair(15, 119), Pair(37, 94), Pair(23, 121), Pair(42, 148), Pair(14, 190), Pair(29, 127),
        Pair(12, 74), Pair(49, 56), Pair(56, 45), Pair(45, 58), Pair(46, 113), Pair(46, 88), Pair(56, 98), Pair(40, 101),
        Pair(19, 70), Pair(32, 70), Pair(31, 91), Pair(33, 106), Pair(47, 88), Pair(14, 108), Pair(44, 72), Pair(50, 48),
        Pair(23, 50), Pair(25, 72), Pair(30, 95), Pair(39, 73), Pair(34, 89), Pair(40, 80), Pair(42, 73), Pair(64, 9),
        Pair(38, 51), Pair(29, 69), Pair(36, 67), Pair(30, 90), Pair(41, 72), Pair(51, 41), Pair(68, 13), Pair(24, 39),
        Pair(16, 76), Pair(38, 45), Pair(15, 65), Pair(36, 54), Pair(25, 50), Pair(22, 49), Pair(48, -20), Pair(-17, 133)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, -38), Pair(40, -6), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(3, 11), Pair(-3, -27)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, -14), Pair(14, -19), Pair(-63, -30), Pair(-31, -92), Pair(22, -94), Pair(-45, -74), Pair(-79, 41), Pair(-12, -13),
        Pair(5, 34), Pair(0, 32), Pair(12, 1), Pair(96, -70), Pair(13, -32), Pair(125, -74), Pair(58, 19), Pair(24, 39),
        Pair(-39, 33), Pair(-35, 27), Pair(-28, -2), Pair(-19, -15), Pair(6, -21), Pair(12, -16), Pair(-21, 16), Pair(-14, 18),
        Pair(-47, 7), Pair(-38, 19), Pair(-29, 4), Pair(-29, 6), Pair(-24, 2), Pair(-3, -9), Pair(-7, 4), Pair(-20, 6),
        Pair(-55, 5), Pair(-63, 23), Pair(-34, 0), Pair(-53, 17), Pair(-12, 0), Pair(-14, -12), Pair(-10, -7), Pair(-8, -21),
        Pair(-56, 12), Pair(-30, 20), Pair(-14, 6), Pair(-31, 3), Pair(-17, 19), Pair(8, -6), Pair(21, -8), Pair(-21, -12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-139, -21), Pair(-124, -27), Pair(-41, -48), Pair(29, -13), Pair(87, -34), Pair(2, 24), Pair(-109, -38), Pair(-108, -150),
        Pair(-8, 28), Pair(46, 5), Pair(41, -3), Pair(120, 1), Pair(112, -27), Pair(48, -24), Pair(-33, 8), Pair(50, -51),
        Pair(-11, 24), Pair(-40, 39), Pair(42, 10), Pair(50, 10), Pair(108, 8), Pair(23, -5), Pair(-6, -4), Pair(-3, -57),
        Pair(-43, 55), Pair(35, 8), Pair(63, 13), Pair(52, 29), Pair(78, -2), Pair(65, 23), Pair(178, -53), Pair(-2, 19),
        Pair(-9, 61), Pair(4, 0), Pair(34, 21), Pair(59, 11), Pair(65, 4), Pair(55, 1), Pair(59, -11), Pair(29, -24),
        Pair(-101, 61), Pair(-18, 18), Pair(-3, 41), Pair(-21, 54), Pair(63, 15), Pair(28, 16), Pair(58, 12), Pair(27, 27),
        Pair(-79, 9), Pair(-31, 11), Pair(-49, 43), Pair(-8, 32), Pair(1, 29), Pair(-49, 43), Pair(7, 22), Pair(-57, 54),
        Pair(-182, 8), Pair(-61, -2), Pair(-149, 63), Pair(-71, 9), Pair(32, 8), Pair(16, 18), Pair(-30, 4), Pair(-103, 25)
      },
      { // Piece 2
        Pair(-24, 32), Pair(8, 3), Pair(-62, 37), Pair(-45, -9), Pair(-50, 45), Pair(-27, 36), Pair(-68, 30), Pair(-178, 5),
        Pair(-39, 13), Pair(-63, 27), Pair(-59, 33), Pair(62, -35), Pair(-9, -29), Pair(-19, -29), Pair(-103, 28), Pair(-71, 34),
        Pair(-12, 11), Pair(-26, 38), Pair(-4, -4), Pair(-23, 18), Pair(-25, 10), Pair(77, 8), Pair(-41, 29), Pair(-40, 29),
        Pair(87, -40), Pair(-10, 10), Pair(-11, 38), Pair(62, 6), Pair(68, -8), Pair(8, 26), Pair(46, 10), Pair(-58, 9),
        Pair(-21, 5), Pair(61, -14), Pair(-3, 9), Pair(66, 10), Pair(16, 1), Pair(38, -5), Pair(-18, 17), Pair(73, -6),
        Pair(26, 7), Pair(-21, 25), Pair(11, 4), Pair(-18, 34), Pair(28, 17), Pair(-22, 24), Pair(1, 14), Pair(57, -32),
        Pair(-59, -21), Pair(-13, 12), Pair(30, -5), Pair(-12, 24), Pair(-33, 27), Pair(30, 4), Pair(39, 7), Pair(-23, 2),
        Pair(8, 10), Pair(-9, 13), Pair(1, 4), Pair(-50, -6), Pair(-5, -2), Pair(-13, 16), Pair(-1, 18), Pair(62, -79)
      },
      { // Piece 3
        Pair(-65, 35), Pair(-75, 59), Pair(-49, 56), Pair(10, 19), Pair(-8, 30), Pair(-109, 60), Pair(106, -16), Pair(-17, 46),
        Pair(-54, 21), Pair(-16, 28), Pair(11, 15), Pair(53, -10), Pair(40, -15), Pair(44, 4), Pair(-11, 25), Pair(26, 1),
        Pair(-33, 41), Pair(-7, 48), Pair(-2, 40), Pair(36, -15), Pair(-43, 8), Pair(72, -8), Pair(25, -3), Pair(7, 33),
        Pair(-40, 46), Pair(-37, 49), Pair(-18, 50), Pair(-25, 34), Pair(4, 8), Pair(71, 4), Pair(80, -2), Pair(-33, 13),
        Pair(-81, 51), Pair(-88, 65), Pair(-85, 50), Pair(-34, 23), Pair(-12, 12), Pair(-46, 51), Pair(2, 15), Pair(9, -17),
        Pair(-105, 55), Pair(-109, 65), Pair(-53, 20), Pair(-47, 31), Pair(10, 1), Pair(-9, 22), Pair(31, -9), Pair(-16, 16),
        Pair(-64, 17), Pair(-79, 43), Pair(-55, 23), Pair(-83, 42), Pair(-18, 11), Pair(-22, -4), Pair(-45, 42), Pair(-31, 18),
        Pair(-66, 33), Pair(-79, 39), Pair(-30, 15), Pair(-27, 16), Pair(-33, 19), Pair(-33, 24), Pair(-58, 18), Pair(-64, 7)
      },
      { // Piece 4
        Pair(18, 48), Pair(64, 37), Pair(84, 46), Pair(208, -27), Pair(135, 4), Pair(116, 21), Pair(149, -50), Pair(47, 13),
        Pair(60, 14), Pair(76, -36), Pair(-1, 61), Pair(28, 21), Pair(99, 41), Pair(49, 79), Pair(57, -6), Pair(76, 65),
        Pair(29, -8), Pair(34, 9), Pair(20, 65), Pair(26, 57), Pair(26, 112), Pair(168, -3), Pair(128, -25), Pair(133, -15),
        Pair(38, 34), Pair(49, 14), Pair(48, 54), Pair(95, 22), Pair(65, 72), Pair(192, -26), Pair(121, 29), Pair(79, 73),
        Pair(35, -1), Pair(65, 27), Pair(66, -31), Pair(72, -4), Pair(71, 21), Pair(61, 54), Pair(119, -10), Pair(126, -9),
        Pair(81, -33), Pair(49, 4), Pair(30, 52), Pair(7, 52), Pair(33, 82), Pair(79, 0), Pair(75, 35), Pair(108, -33),
        Pair(12, 10), Pair(48, -24), Pair(21, 55), Pair(54, 52), Pair(75, -12), Pair(85, -33), Pair(58, 23), Pair(26, -19),
        Pair(11, 58), Pair(2, 70), Pair(60, 18), Pair(9, 90), Pair(-30, 65), Pair(51, -1), Pair(14, -50), Pair(-6, -131)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, -23), Pair(80, -14), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(21, 8), Pair(2, -20)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-82, 33), Pair(-71, -4), Pair(-121, 40), Pair(-65, -19), Pair(-25, 18), Pair(-107, 47), Pair(-183, 54), Pair(57, 85),
        Pair(6, 46), Pair(43, 10), Pair(-86, 34), Pair(88, -9), Pair(37, 33), Pair(9, 14), Pair(24, 60), Pair(38, 37),
        Pair(-80, 23), Pair(-73, 34), Pair(-27, -3), Pair(-27, -25), Pair(17, -34), Pair(8, -9), Pair(50, -7), Pair(-10, 1),
        Pair(-55, 0), Pair(-20, -3), Pair(-54, -7), Pair(-39, 3), Pair(46, -30), Pair(-32, -24), Pair(33, -18), Pair(80, -37),
        Pair(-94, 7), Pair(-57, 6), Pair(-53, -1), Pair(-33, 8), Pair(-8, 2), Pair(-16, -9), Pair(11, -14), Pair(-2, -18),
        Pair(-81, 20), Pair(-26, 12), Pair(-32, 1), Pair(12, -16), Pair(-43, 57), Pair(27, -21), Pair(18, -8), Pair(-26, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-167, -79), Pair(-37, -23), Pair(-88, -45), Pair(18, -62), Pair(24, 4), Pair(99, -41), Pair(18, -10), Pair(-52, -108),
        Pair(31, -130), Pair(-39, -82), Pair(-74, -26), Pair(86, -42), Pair(104, -71), Pair(106, -63), Pair(-54, -61), Pair(-79, -83),
        Pair(-110, -15), Pair(11, -66), Pair(7, -22), Pair(70, -32), Pair(157, -124), Pair(155, -111), Pair(-58, -65), Pair(-11, 33),
        Pair(-18, -59), Pair(13, 0), Pair(56, -5), Pair(120, -21), Pair(96, -44), Pair(133, -67), Pair(-1, -34), Pair(124, -70),
        Pair(-18, -29), Pair(91, -20), Pair(-46, -28), Pair(147, -36), Pair(79, -34), Pair(218, -99), Pair(120, -42), Pair(138, -56),
        Pair(-151, 33), Pair(-25, 16), Pair(88, -61), Pair(44, 23), Pair(92, -3), Pair(36, -38), Pair(6, -66), Pair(-53, -108),
        Pair(-95, -28), Pair(9, -54), Pair(34, -42), Pair(-32, 14), Pair(82, -58), Pair(78, -47), Pair(15, -23), Pair(-99, 7),
        Pair(-33, -31), Pair(-147, 27), Pair(-31, -45), Pair(-39, -52), Pair(-58, -18), Pair(-16, 21), Pair(-13, -33), Pair(1, -68)
      },
      { // Piece 2
        Pair(-79, -25), Pair(-43, 13), Pair(-52, -56), Pair(-50, 3), Pair(-23, -25), Pair(3, -21), Pair(-15, 13), Pair(11, -3),
        Pair(-109, -4), Pair(14, -8), Pair(-98, 8), Pair(-74, 26), Pair(-18, -59), Pair(-80, -18), Pair(-79, 26), Pair(-137, 4),
        Pair(-21, 22), Pair(-91, 30), Pair(7, 15), Pair(-29, 17), Pair(-40, -3), Pair(-15, -27), Pair(29, -16), Pair(-10, -68),
        Pair(43, -25), Pair(-60, 42), Pair(-61, 10), Pair(50, -5), Pair(-17, -35), Pair(46, 14), Pair(97, -44), Pair(57, 15),
        Pair(-85, 73), Pair(-38, -35), Pair(-67, 6), Pair(-31, -8), Pair(-6, -12), Pair(136, -77), Pair(-16, 55), Pair(-1, -13),
        Pair(37, -3), Pair(-36, -10), Pair(56, -5), Pair(17, -27), Pair(60, 20), Pair(77, -9), Pair(-23, 47), Pair(37, -24),
        Pair(-91, 66), Pair(25, -35), Pair(35, -19), Pair(-46, -24), Pair(-19, -5), Pair(62, -47), Pair(63, -41), Pair(-43, -8),
        Pair(-61, -63), Pair(11, -28), Pair(-75, 23), Pair(-43, -38), Pair(-108, 8), Pair(7, -66), Pair(13, -52), Pair(-111, -15)
      },
      { // Piece 3
        Pair(-77, -24), Pair(-146, 23), Pair(-54, -16), Pair(-100, -10), Pair(-100, 13), Pair(10, -6), Pair(-35, 32), Pair(-78, -24),
        Pair(-72, -26), Pair(-14, -26), Pair(-49, -7), Pair(-44, -9), Pair(5, -28), Pair(28, -45), Pair(31, -46), Pair(12, -49),
        Pair(46, -47), Pair(11, -36), Pair(-72, -24), Pair(54, -29), Pair(134, -77), Pair(72, -46), Pair(49, -52), Pair(-70, -19),
        Pair(-55, -27), Pair(-57, -20), Pair(-27, -50), Pair(-36, -68), Pair(83, -90), Pair(64, -67), Pair(59, -40), Pair(-46, 7),
        Pair(-137, 4), Pair(-60, 9), Pair(-44, -6), Pair(-61, -19), Pair(-88, 28), Pair(-5, -34), Pair(82, -47), Pair(31, -6),
        Pair(-153, 43), Pair(-36, -44), Pair(-40, 17), Pair(-93, -12), Pair(-42, 9), Pair(46, -33), Pair(20, -48), Pair(-24, -63),
        Pair(-137, -30), Pair(-131, -57), Pair(-101, 13), Pair(-15, -55), Pair(-117, -26), Pair(20, -61), Pair(-40, 8), Pair(-27, -102),
        Pair(-101, -14), Pair(-37, -30), Pair(-47, -26), Pair(-59, -16), Pair(-85, -5), Pair(-23, -31), Pair(-53, 10), Pair(-23, -36)
      },
      { // Piece 4
        Pair(21, -47), Pair(21, -61), Pair(137, -56), Pair(80, -58), Pair(-58, -33), Pair(135, -148), Pair(107, -147), Pair(160, -114),
        Pair(99, -203), Pair(142, -122), Pair(69, -28), Pair(174, -143), Pair(96, -64), Pair(222, -143), Pair(124, -137), Pair(256, -202),
        Pair(11, -18), Pair(3, -48), Pair(-12, -93), Pair(67, -26), Pair(66, -25), Pair(217, -125), Pair(189, -145), Pair(281, -268),
        Pair(40, 47), Pair(52, -89), Pair(-67, 27), Pair(34, 15), Pair(98, -102), Pair(45, 84), Pair(48, -169), Pair(-27, 13),
        Pair(-50, -81), Pair(-40, -42), Pair(93, -60), Pair(-13, 8), Pair(76, -103), Pair(106, -100), Pair(86, -14), Pair(-41, 0),
        Pair(54, -86), Pair(-89, 22), Pair(64, -32), Pair(78, -19), Pair(24, -129), Pair(149, -127), Pair(26, -70), Pair(2, -49),
        Pair(71, -177), Pair(-77, -62), Pair(-26, 15), Pair(-50, -55), Pair(-2, -69), Pair(35, -57), Pair(6, -51), Pair(-81, -54),
        Pair(-46, 6), Pair(-59, -26), Pair(54, -119), Pair(-59, -17), Pair(-12, -59), Pair(-48, -91), Pair(15, -71), Pair(1, 21)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, -15), Pair(70, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(35, 19), Pair(18, -29)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(77, -68), Pair(24, 1), Pair(-85, 13), Pair(3, 36), Pair(-1, 15), Pair(74, -6), Pair(66, 28), Pair(-107, 10),
        Pair(-47, 42), Pair(-22, 33), Pair(-5, 48), Pair(9, -7), Pair(-62, 23), Pair(50, -16), Pair(-3, 58), Pair(-84, 67),
        Pair(-26, 0), Pair(-79, 4), Pair(-114, -2), Pair(-104, -21), Pair(-27, -10), Pair(-25, -26), Pair(-101, 11), Pair(-148, 26),
        Pair(-92, 3), Pair(-59, 0), Pair(-68, -5), Pair(-33, -17), Pair(-26, -30), Pair(9, -33), Pair(-64, -9), Pair(-7, -30),
        Pair(-148, 1), Pair(-54, -14), Pair(-66, -24), Pair(0, -12), Pair(-1, -17), Pair(-5, -17), Pair(-95, -1), Pair(34, -45),
        Pair(-138, 38), Pair(26, -9), Pair(-44, -8), Pair(106, -10), Pair(90, -20), Pair(52, -15), Pair(77, -7), Pair(-41, -12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-115, -182), Pair(-21, -40), Pair(-120, -152), Pair(-3, -60), Pair(9, -97), Pair(-50, -86), Pair(-58, -150), Pair(-26, -130),
        Pair(52, -107), Pair(18, -48), Pair(1, -122), Pair(65, -37), Pair(43, -128), Pair(10, -117), Pair(-1, -69), Pair(-66, -17),
        Pair(58, -58), Pair(-24, -76), Pair(75, -46), Pair(-3, -55), Pair(131, -46), Pair(66, -107), Pair(-42, -120), Pair(20, -63),
        Pair(-7, -82), Pair(-40, -47), Pair(34, -72), Pair(186, -94), Pair(147, -105), Pair(60, -40), Pair(-7, -50), Pair(-39, -76),
        Pair(-77, -64), Pair(-93, -64), Pair(-1, -19), Pair(60, -18), Pair(89, -54), Pair(146, -41), Pair(70, -29), Pair(98, -83),
        Pair(-26, -58), Pair(-8, 47), Pair(74, -48), Pair(126, -33), Pair(132, -56), Pair(97, -44), Pair(48, -41), Pair(98, -140),
        Pair(14, -16), Pair(-91, -34), Pair(3, -97), Pair(-84, -65), Pair(-9, -20), Pair(-11, -13), Pair(-7, 1), Pair(35, -58),
        Pair(6, -158), Pair(-165, -58), Pair(40, -77), Pair(30, -61), Pair(-73, -6), Pair(47, -24), Pair(-31, -176), Pair(-8, -132)
      },
      { // Piece 2
        Pair(21, 25), Pair(-106, -24), Pair(-52, -39), Pair(-126, -70), Pair(-140, 35), Pair(-43, -67), Pair(-151, 69), Pair(-33, -9),
        Pair(-165, -14), Pair(-106, 1), Pair(-137, 2), Pair(-137, 23), Pair(86, -36), Pair(-18, 28), Pair(-92, 2), Pair(-54, 7),
        Pair(-67, -6), Pair(-69, 26), Pair(-91, -8), Pair(-168, 5), Pair(-142, -1), Pair(-65, -12), Pair(-73, -13), Pair(-51, -23),
        Pair(-80, -57), Pair(-73, 9), Pair(-149, 21), Pair(-112, 31), Pair(60, -19), Pair(-84, -1), Pair(-110, -17), Pair(-102, -50),
        Pair(-117, -13), Pair(-64, -42), Pair(-62, 3), Pair(-52, -33), Pair(39, -14), Pair(-10, -32), Pair(-80, -15), Pair(19, -68),
        Pair(-44, -75), Pair(86, -66), Pair(-29, -76), Pair(-49, -34), Pair(81, -105), Pair(104, -34), Pair(51, -52), Pair(128, -84),
        Pair(-20, 7), Pair(-36, -53), Pair(-42, 5), Pair(-182, -53), Pair(22, -46), Pair(13, -59), Pair(127, -60), Pair(-124, 41),
        Pair(-89, -139), Pair(4, -8), Pair(-13, -25), Pair(42, 29), Pair(-73, -20), Pair(20, -16), Pair(7, 24), Pair(-44, -9)
      },
      { // Piece 3
        Pair(5, -93), Pair(-25, -87), Pair(-106, -35), Pair(-2, -49), Pair(-132, -60), Pair(9, -55), Pair(-88, 7), Pair(-47, -36),
        Pair(-63, -52), Pair(-82, -40), Pair(-62, -21), Pair(-80, -33), Pair(0, -62), Pair(33, -70), Pair(62, -85), Pair(-126, -32),
        Pair(-132, -52), Pair(155, -101), Pair(-52, -36), Pair(-73, -68), Pair(-15, -73), Pair(56, -67), Pair(15, -98), Pair(-58, -45),
        Pair(9, -71), Pair(27, -73), Pair(-76, -23), Pair(-44, -75), Pair(28, -104), Pair(55, -80), Pair(19, -28), Pair(85, -105),
        Pair(80, -101), Pair(27, -83), Pair(93, -100), Pair(-34, -60), Pair(28, -85), Pair(-13, -31), Pair(-35, -60), Pair(-64, -31),
        Pair(-67, -32), Pair(75, -28), Pair(-104, -6), Pair(40, -78), Pair(0, -65), Pair(21, -55), Pair(44, -77), Pair(-11, -8),
        Pair(-40, -51), Pair(64, -116), Pair(-73, -49), Pair(-10, -48), Pair(27, -107), Pair(33, -78), Pair(91, -105), Pair(-8, -111),
        Pair(-121, -39), Pair(29, -72), Pair(-33, -69), Pair(39, -96), Pair(91, -89), Pair(14, -67), Pair(43, -80), Pair(65, -152)
      },
      { // Piece 4
        Pair(160, -180), Pair(-59, -144), Pair(-19, -121), Pair(90, -122), Pair(67, -125), Pair(-77, -105), Pair(-111, -90), Pair(-92, 5),
        Pair(53, -160), Pair(35, -191), Pair(-10, -171), Pair(-32, -90), Pair(20, -133), Pair(4, -108), Pair(29, -160), Pair(16, -97),
        Pair(-78, -125), Pair(94, -105), Pair(-16, -49), Pair(2, -113), Pair(-30, -147), Pair(80, -139), Pair(71, -229), Pair(127, -131),
        Pair(28, -108), Pair(-43, -40), Pair(34, -33), Pair(-36, -41), Pair(90, -90), Pair(91, -180), Pair(-73, -111), Pair(156, -132),
        Pair(39, -149), Pair(-7, -83), Pair(12, -34), Pair(-126, 4), Pair(-84, -129), Pair(30, -124), Pair(79, -143), Pair(41, -144),
        Pair(-13, 1), Pair(-76, -97), Pair(8, -78), Pair(-13, -182), Pair(17, -52), Pair(94, -82), Pair(68, -150), Pair(50, -129),
        Pair(44, -166), Pair(-35, -22), Pair(-39, -60), Pair(96, -162), Pair(25, -124), Pair(-59, -174), Pair(24, -184), Pair(-21, -85),
        Pair(-61, -124), Pair(-39, -134), Pair(9, -144), Pair(26, -197), Pair(47, -132), Pair(53, -189), Pair(-18, -65), Pair(-31, -160)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-81, 7), Pair(60, 19), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(18, 14), Pair(-39, -13)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-27, 52), Pair(28, 18), Pair(42, 110), Pair(56, 72), Pair(51, 97), Pair(9, 28), Pair(-41, -43), Pair(-5, -12),
        Pair(-42, 64), Pair(-79, 18), Pair(64, 9), Pair(-51, 4), Pair(-67, 23), Pair(25, -25), Pair(-78, 38), Pair(40, 34),
        Pair(-5, 7), Pair(-25, 0), Pair(-16, 83), Pair(-60, 22), Pair(-135, -8), Pair(-54, -34), Pair(-11, 1), Pair(43, -21),
        Pair(-39, -27), Pair(-82, -14), Pair(37, 4), Pair(-20, -26), Pair(-96, -59), Pair(-11, -10), Pair(-74, 9), Pair(-71, -26),
        Pair(-67, 5), Pair(-65, -21), Pair(-20, 37), Pair(8, 44), Pair(-78, 23), Pair(-41, -13), Pair(-105, 12), Pair(87, -54),
        Pair(72, -55), Pair(-21, -18), Pair(-28, 16), Pair(13, -112), Pair(29, 36), Pair(38, -16), Pair(-13, -3), Pair(46, -66),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-1, -65), Pair(-32, -100), Pair(-39, -32), Pair(23, -1), Pair(3, -77), Pair(2, -32), Pair(-6, -10), Pair(-7, -75),
        Pair(36, 122), Pair(-5, 80), Pair(13, -18), Pair(-52, 92), Pair(7, 13), Pair(-6, -20), Pair(-95, -159), Pair(-60, -170),
        Pair(-15, 16), Pair(-6, -41), Pair(-43, -88), Pair(-91, -66), Pair(-83, -7), Pair(-27, -4), Pair(-24, 141), Pair(-64, -61),
        Pair(15, -3), Pair(32, 30), Pair(52, -32), Pair(-14, -93), Pair(-17, -130), Pair(5, -92), Pair(9, 26), Pair(32, -56),
        Pair(25, -20), Pair(20, -12), Pair(-23, -19), Pair(67, 1), Pair(1, -105), Pair(-57, -50), Pair(38, 41), Pair(4, 33),
        Pair(21, -44), Pair(27, 9), Pair(0, -43), Pair(31, 18), Pair(47, -61), Pair(45, 14), Pair(-34, -139), Pair(39, 20),
        Pair(12, 55), Pair(9, 75), Pair(-15, -64), Pair(37, -139), Pair(17, -44), Pair(38, -66), Pair(-26, -65), Pair(-31, -56),
        Pair(10, 10), Pair(17, -4), Pair(-5, 25), Pair(19, 88), Pair(-28, -41), Pair(-28, 5), Pair(18, -4), Pair(10, 13)
      },
      { // Piece 2
        Pair(-56, -22), Pair(-54, -53), Pair(-12, -13), Pair(-25, 14), Pair(0, 44), Pair(13, -68), Pair(-7, 40), Pair(-18, -43),
        Pair(-27, -38), Pair(-37, 6), Pair(33, 10), Pair(-34, -75), Pair(61, 80), Pair(41, 69), Pair(17, 28), Pair(-18, -26),
        Pair(-18, -40), Pair(-13, 33), Pair(0, 15), Pair(-29, -44), Pair(34, 115), Pair(7, 21), Pair(9, 78), Pair(23, 100),
        Pair(20, -17), Pair(-50, -21), Pair(45, 7), Pair(77, 69), Pair(-18, 4), Pair(-20, 49), Pair(107, -6), Pair(-30, -1),
        Pair(-53, -26), Pair(19, -24), Pair(45, 58), Pair(15, 121), Pair(32, -10), Pair(50, 121), Pair(-37, 23), Pair(-43, -114),
        Pair(19, 35), Pair(71, -53), Pair(27, 27), Pair(-28, -70), Pair(-7, -90), Pair(78, 41), Pair(7, 26), Pair(33, 121),
        Pair(-3, -59), Pair(7, 35), Pair(69, -10), Pair(-36, -39), Pair(-68, -112), Pair(-63, 17), Pair(-5, -38), Pair(36, 16),
        Pair(-2, -75), Pair(38, 17), Pair(-56, -125), Pair(-70, -51), Pair(-17, -73), Pair(38, -43), Pair(-54, -102), Pair(-10, -74)
      },
      { // Piece 3
        Pair(-36, -44), Pair(4, 4), Pair(-9, -9), Pair(-29, 46), Pair(-2, -26), Pair(-8, -24), Pair(-48, 5), Pair(-16, 42),
        Pair(-49, 21), Pair(-16, -38), Pair(34, 15), Pair(-129, -57), Pair(10, -11), Pair(-36, -27), Pair(-77, 11), Pair(-90, -17),
        Pair(47, 4), Pair(7, 5), Pair(88, -4), Pair(-26, 2), Pair(-39, 0), Pair(-61, -47), Pair(-21, 3), Pair(-40, 18),
        Pair(71, -8), Pair(-10, 47), Pair(88, -70), Pair(71, -21), Pair(16, -40), Pair(18, -2), Pair(-68, 14), Pair(19, -65),
        Pair(-27, 58), Pair(24, 4), Pair(19, 5), Pair(38, 45), Pair(-46, -23), Pair(-64, 1), Pair(3, -1), Pair(1, -10),
        Pair(18, -33), Pair(73, 11), Pair(53, 25), Pair(8, -43), Pair(94, -11), Pair(96, 30), Pair(-27, 22), Pair(-26, -79),
        Pair(-29, -85), Pair(54, -2), Pair(114, -25), Pair(15, -5), Pair(1, -54), Pair(-9, -33), Pair(-43, -39), Pair(-5, -63),
        Pair(128, -52), Pair(20, -62), Pair(34, -19), Pair(-6, -43), Pair(-13, 4), Pair(136, -6), Pair(23, -139), Pair(1, -20)
      },
      { // Piece 4
        Pair(-107, -76), Pair(21, -49), Pair(5, 6), Pair(-87, -117), Pair(-89, -90), Pair(-43, -88), Pair(43, 36), Pair(-37, -35),
        Pair(19, -79), Pair(25, -106), Pair(-37, -36), Pair(-4, -55), Pair(-29, -72), Pair(-55, -56), Pair(24, 79), Pair(-56, -64),
        Pair(-25, -77), Pair(-12, -56), Pair(14, -1), Pair(13, 0), Pair(6, -69), Pair(-26, -22), Pair(-104, -86), Pair(-31, -118),
        Pair(45, -37), Pair(8, -98), Pair(73, -24), Pair(34, -56), Pair(2, -54), Pair(57, -1), Pair(1, -19), Pair(-16, -53),
        Pair(-17, -95), Pair(45, -4), Pair(-11, -67), Pair(-34, -39), Pair(22, -101), Pair(14, 12), Pair(58, 46), Pair(-50, -47),
        Pair(-27, -78), Pair(20, -120), Pair(76, 43), Pair(38, -24), Pair(39, 67), Pair(-29, -65), Pair(55, 18), Pair(16, -22),
        Pair(12, -36), Pair(-65, -129), Pair(16, 28), Pair(-14, -50), Pair(-5, -71), Pair(-86, -83), Pair(-25, -95), Pair(-14, 9),
        Pair(-20, -89), Pair(25, 16), Pair(40, 10), Pair(19, -58), Pair(56, -49), Pair(-59, -96), Pair(-13, -75), Pair(-38, -84)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-76, 40), Pair(-21, 52), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-47, 57), Pair(-34, 5)
      }
    }}
  }},
  {{ // Bucket 1
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-152, 93), Pair(-96, 120), Pair(-134, 88), Pair(-60, 48), Pair(-21, -23), Pair(-72, -39), Pair(-73, -189), Pair(-187, -72),
        Pair(11, 53), Pair(-4, 97), Pair(34, 12), Pair(32, -21), Pair(51, -52), Pair(95, -40), Pair(13, 31), Pair(-11, 22),
        Pair(-1, 39), Pair(10, 12), Pair(9, -1), Pair(13, -33), Pair(34, -37), Pair(32, -39), Pair(12, -4), Pair(-4, -2),
        Pair(7, 7), Pair(-4, 18), Pair(10, -13), Pair(23, -28), Pair(20, -28), Pair(24, -33), Pair(15, -11), Pair(-6, -14),
        Pair(2, 0), Pair(-1, 15), Pair(-2, -10), Pair(-11, -11), Pair(-5, -9), Pair(-3, -19), Pair(10, -17), Pair(-14, -17),
        Pair(7, 7), Pair(14, 12), Pair(6, 5), Pair(-23, 5), Pair(-18, 3), Pair(8, -11), Pair(23, -10), Pair(2, -14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-183, -3), Pair(-298, 125), Pair(-166, 90), Pair(-113, 16), Pair(59, -62), Pair(-84, -61), Pair(-43, 66), Pair(-120, -97),
        Pair(-93, 26), Pair(-30, 33), Pair(-17, 32), Pair(-57, 33), Pair(-41, 45), Pair(78, -29), Pair(-84, 47), Pair(18, -7),
        Pair(-64, 88), Pair(-8, 72), Pair(-43, 71), Pair(-20, 56), Pair(-6, 30), Pair(24, 27), Pair(-48, 46), Pair(19, 7),
        Pair(-10, 61), Pair(-2, 49), Pair(9, 49), Pair(21, 55), Pair(16, 49), Pair(25, 49), Pair(4, 34), Pair(-5, 53),
        Pair(-24, 36), Pair(-13, 77), Pair(7, 51), Pair(10, 58), Pair(17, 43), Pair(30, 29), Pair(18, 52), Pair(-12, 38),
        Pair(-49, 39), Pair(-15, 39), Pair(-1, 37), Pair(-2, 55), Pair(17, 46), Pair(-1, 29), Pair(7, 19), Pair(-18, 30),
        Pair(-48, 35), Pair(-23, 26), Pair(-8, 38), Pair(-16, 35), Pair(-4, 31), Pair(1, 12), Pair(-23, 31), Pair(-35, 5),
        Pair(-99, 85), Pair(-43, 18), Pair(-18, 31), Pair(-33, 55), Pair(-8, 38), Pair(-32, 35), Pair(-48, 31), Pair(-22, -1)
      },
      { // Piece 2
        Pair(-84, 69), Pair(-100, 104), Pair(-45, 20), Pair(-131, 68), Pair(-165, 24), Pair(-130, 15), Pair(-156, 34), Pair(-131, 27),
        Pair(-52, 32), Pair(-51, 37), Pair(-29, 16), Pair(-85, 30), Pair(-76, 51), Pair(-28, 35), Pair(-65, 60), Pair(-26, -19),
        Pair(-25, 26), Pair(-41, 55), Pair(-27, 43), Pair(-12, 16), Pair(-57, 47), Pair(9, 29), Pair(29, 24), Pair(3, 30),
        Pair(-25, 68), Pair(-10, 44), Pair(-13, 37), Pair(-13, 42), Pair(-15, 28), Pair(-9, 41), Pair(-18, 35), Pair(-24, 24),
        Pair(-8, -2), Pair(-57, 64), Pair(-8, 21), Pair(1, 10), Pair(-3, 15), Pair(-16, 22), Pair(-30, 42), Pair(-15, -2),
        Pair(-32, 14), Pair(4, 41), Pair(0, 36), Pair(-6, 39), Pair(0, 44), Pair(3, 37), Pair(-2, 21), Pair(-20, 6),
        Pair(12, -9), Pair(7, 10), Pair(18, 14), Pair(-13, 43), Pair(4, 27), Pair(4, 20), Pair(4, 23), Pair(-10, 33),
        Pair(-27, 31), Pair(-3, 34), Pair(-21, 28), Pair(-4, 25), Pair(-11, 33), Pair(-29, 43), Pair(-25, 68), Pair(-14, 36)
      },
      { // Piece 3
        Pair(22, 154), Pair(-49, 149), Pair(13, 105), Pair(29, 43), Pair(-91, 144), Pair(41, 127), Pair(102, 136), Pair(-92, 106),
        Pair(-25, 40), Pair(-51, 83), Pair(-35, 77), Pair(-8, 53), Pair(29, 30), Pair(82, 30), Pair(33, 25), Pair(-44, 69),
        Pair(-29, 24), Pair(10, 57), Pair(-43, 61), Pair(5, 46), Pair(36, 27), Pair(-25, 48), Pair(49, 37), Pair(15, -23),
        Pair(-21, 38), Pair(16, 27), Pair(-15, 70), Pair(-16, 62), Pair(-6, 62), Pair(40, 18), Pair(25, 18), Pair(16, -12),
        Pair(-8, 32), Pair(-28, 74), Pair(-31, 44), Pair(-3, 61), Pair(-29, 52), Pair(-12, 4), Pair(28, -14), Pair(-19, 1),
        Pair(-21, 39), Pair(-5, 30), Pair(-24, 46), Pair(-22, 38), Pair(-11, 43), Pair(12, -6), Pair(20, -20), Pair(-12, -9),
        Pair(-20, 5), Pair(-37, 41), Pair(-4, 29), Pair(-12, 27), Pair(10, 5), Pair(-16, 31), Pair(5, -17), Pair(-20, -27),
        Pair(-4, 12), Pair(-22, 23), Pair(-24, 46), Pair(-3, 23), Pair(9, 8), Pair(-16, -1), Pair(-2, -6), Pair(-3, -24)
      },
      { // Piece 4
        Pair(-196, 192), Pair(-123, 196), Pair(-109, 174), Pair(-59, 109), Pair(-46, 115), Pair(32, 81), Pair(-34, 22), Pair(29, 23),
        Pair(-65, -7), Pair(-68, 68), Pair(-68, 83), Pair(-109, 138), Pair(-123, 200), Pair(-35, 148), Pair(-97, 121), Pair(-29, 45),
        Pair(-26, -10), Pair(-42, 14), Pair(-47, 64), Pair(-26, 64), Pair(-49, 77), Pair(-11, 117), Pair(-25, 95), Pair(0, 86),
        Pair(-33, 26), Pair(-40, 77), Pair(-16, 51), Pair(-35, 118), Pair(-44, 102), Pair(0, 41), Pair(3, 61), Pair(-4, 34),
        Pair(-31, 26), Pair(-37, 76), Pair(-35, 50), Pair(-31, 150), Pair(-36, 98), Pair(-19, 38), Pair(-5, 23), Pair(-11, 10),
        Pair(-31, 28), Pair(-24, 54), Pair(-24, 74), Pair(-36, 83), Pair(-28, 94), Pair(-21, 78), Pair(-12, 49), Pair(-11, 60),
        Pair(-14, -14), Pair(6, -84), Pair(-6, -27), Pair(-7, 14), Pair(-17, 29), Pair(-22, 44), Pair(23, -64), Pair(18, -39),
        Pair(-31, -33), Pair(-16, -44), Pair(-13, -20), Pair(-18, -19), Pair(-20, -25), Pair(-25, -7), Pair(-18, 13), Pair(13, -52)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(3, 8), Pair(-51, 26), Pair(-6, -1), Pair(-30, 14), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(35, 127), Pair(-81, 102), Pair(-60, -43), Pair(-32, -45), Pair(-31, -113), Pair(-96, -88), Pair(-93, 19), Pair(-37, 80),
        Pair(22, 63), Pair(-10, 54), Pair(44, -16), Pair(47, -59), Pair(45, -65), Pair(61, -23), Pair(35, 31), Pair(27, 30),
        Pair(9, 19), Pair(13, 0), Pair(16, -12), Pair(13, -27), Pair(37, -46), Pair(15, -23), Pair(16, -9), Pair(11, 9),
        Pair(0, -5), Pair(2, 15), Pair(17, -31), Pair(30, -25), Pair(24, -21), Pair(21, -29), Pair(9, -4), Pair(5, -10),
        Pair(-7, -15), Pair(-7, 13), Pair(2, -18), Pair(-2, -10), Pair(5, -24), Pair(-2, -18), Pair(6, -11), Pair(-9, -16),
        Pair(3, -8), Pair(10, 13), Pair(11, -2), Pair(-19, 9), Pair(-10, 22), Pair(9, -11), Pair(21, -10), Pair(5, -14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-140, -97), Pair(-42, 81), Pair(-75, 32), Pair(-56, -2), Pair(-60, -11), Pair(-20, -70), Pair(-183, 86), Pair(-108, -79),
        Pair(-93, 89), Pair(-52, 62), Pair(-43, 71), Pair(40, -60), Pair(13, -7), Pair(-31, 56), Pair(-61, 67), Pair(-45, 18),
        Pair(-59, 46), Pair(-5, 45), Pair(-49, 84), Pair(6, 49), Pair(-20, 74), Pair(-58, 90), Pair(-33, 66), Pair(-58, 2),
        Pair(4, 36), Pair(-18, 101), Pair(5, 69), Pair(-3, 91), Pair(12, 55), Pair(8, 82), Pair(-1, 70), Pair(13, 30),
        Pair(-19, 77), Pair(7, 47), Pair(-2, 75), Pair(16, 62), Pair(2, 85), Pair(23, 39), Pair(-5, 79), Pair(-11, 61),
        Pair(-40, 52), Pair(-9, 56), Pair(0, 53), Pair(10, 54), Pair(21, 58), Pair(-1, 43), Pair(-5, 59), Pair(-31, 51),
        Pair(-43, 73), Pair(-1, 74), Pair(-3, 36), Pair(-15, 62), Pair(-9, 36), Pair(-26, 93), Pair(-20, 25), Pair(-46, 11),
        Pair(-75, 23), Pair(-42, 71), Pair(-47, 75), Pair(-23, 66), Pair(-26, 66), Pair(-13, 19), Pair(-44, 58), Pair(-39, -18)
      },
      { // Piece 2
        Pair(-48, 66), Pair(-91, 134), Pair(-154, 43), Pair(-183, 76), Pair(-89, -11), Pair(-177, 65), Pair(-21, 72), Pair(-62, 19),
        Pair(-45, 12), Pair(-9, 20), Pair(-33, 6), Pair(-83, 73), Pair(-85, 17), Pair(-31, 41), Pair(-41, 35), Pair(-65, 29),
        Pair(-23, 79), Pair(-24, 52), Pair(-41, 38), Pair(13, 25), Pair(5, 61), Pair(-32, 60), Pair(-29, 76), Pair(-19, 14),
        Pair(-22, 41), Pair(-3, 41), Pair(-4, 26), Pair(-9, 72), Pair(0, 21), Pair(3, 53), Pair(-13, 43), Pair(-25, 65),
        Pair(-7, -18), Pair(-50, 52), Pair(1, 5), Pair(4, 31), Pair(11, 31), Pair(-6, 22), Pair(-13, 38), Pair(-21, 48),
        Pair(-17, 26), Pair(15, 24), Pair(0, 58), Pair(2, 49), Pair(5, 43), Pair(11, 37), Pair(6, 34), Pair(-1, 20),
        Pair(-7, 30), Pair(12, 40), Pair(20, -7), Pair(-2, 47), Pair(6, 31), Pair(12, 32), Pair(22, 32), Pair(-1, 46),
        Pair(-2, 88), Pair(25, 2), Pair(-17, 45), Pair(13, 31), Pair(18, -5), Pair(-24, 51), Pair(-19, -39), Pair(-13, 11)
      },
      { // Piece 3
        Pair(67, 141), Pair(14, 79), Pair(42, 96), Pair(114, 60), Pair(53, 23), Pair(-51, 106), Pair(44, 78), Pair(-20, 55),
        Pair(-1, 57), Pair(-1, 83), Pair(-20, 77), Pair(50, 40), Pair(24, 70), Pair(-63, 99), Pair(-44, 94), Pair(-51, 102),
        Pair(-10, 54), Pair(59, 35), Pair(-20, 69), Pair(17, 16), Pair(32, -10), Pair(4, 46), Pair(40, 22), Pair(-52, 88),
        Pair(-5, 26), Pair(17, 36), Pair(19, 42), Pair(-15, 60), Pair(-13, 39), Pair(-32, 55), Pair(-18, 52), Pair(-25, 39),
        Pair(-27, 59), Pair(-52, 39), Pair(-7, 33), Pair(-18, 55), Pair(-2, 47), Pair(3, 0), Pair(-28, 19), Pair(-35, 44),
        Pair(-51, 55), Pair(1, 34), Pair(-26, 51), Pair(-13, 39), Pair(13, 4), Pair(-26, 48), Pair(3, -3), Pair(-26, 39),
        Pair(-21, -21), Pair(-6, 36), Pair(-3, 49), Pair(-17, 10), Pair(25, 7), Pair(15, 23), Pair(-15, 10), Pair(-41, 44),
        Pair(-11, 15), Pair(-6, 22), Pair(-3, 18), Pair(5, 12), Pair(21, -2), Pair(-12, 15), Pair(-19, 17), Pair(-14, 1)
      },
      { // Piece 4
        Pair(13, 159), Pair(-40, 141), Pair(79, 70), Pair(39, 134), Pair(-77, 7), Pair(26, 64), Pair(-33, 104), Pair(-35, 70),
        Pair(38, 48), Pair(-22, 113), Pair(-3, 117), Pair(26, 117), Pair(-110, -10), Pair(-30, 90), Pair(-2, 109), Pair(31, 52),
        Pair(26, 66), Pair(18, 89), Pair(-8, 106), Pair(-3, 147), Pair(-17, 211), Pair(-23, 118), Pair(48, 36), Pair(19, 73),
        Pair(22, 64), Pair(25, 22), Pair(20, 102), Pair(-28, 154), Pair(11, 58), Pair(-3, 118), Pair(20, 63), Pair(11, 133),
        Pair(24, 20), Pair(-11, 121), Pair(14, 75), Pair(4, 118), Pair(10, 100), Pair(6, 92), Pair(11, 69), Pair(15, 59),
        Pair(25, 4), Pair(30, 45), Pair(13, 98), Pair(4, 90), Pair(27, 41), Pair(14, 104), Pair(28, 70), Pair(28, 55),
        Pair(19, -77), Pair(32, -33), Pair(36, -1), Pair(20, 29), Pair(29, 24), Pair(24, 23), Pair(41, -20), Pair(39, -13),
        Pair(14, -9), Pair(6, 30), Pair(17, 49), Pair(17, -11), Pair(9, 77), Pair(9, -68), Pair(77, -144), Pair(46, -29)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(19, -3), Pair(-21, 9), Pair(10, -3), Pair(-32, 10), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-55, 10), Pair(-84, 9), Pair(-56, -1), Pair(-4, -33), Pair(-129, -25), Pair(-60, -89), Pair(-147, 7), Pair(-82, 3),
        Pair(-14, 29), Pair(27, 39), Pair(21, -11), Pair(29, -36), Pair(71, -44), Pair(49, -33), Pair(6, 58), Pair(1, 7),
        Pair(-21, 23), Pair(6, 5), Pair(11, -13), Pair(-1, -24), Pair(28, -34), Pair(16, -31), Pair(0, 6), Pair(-13, 5),
        Pair(-5, -4), Pair(-19, 22), Pair(5, -15), Pair(16, -21), Pair(11, -19), Pair(9, -24), Pair(10, -8), Pair(-5, -15),
        Pair(-16, -6), Pair(-11, 6), Pair(-10, -11), Pair(-20, -3), Pair(-7, -9), Pair(-11, -18), Pair(0, -5), Pair(-25, -16),
        Pair(-6, 0), Pair(4, 9), Pair(8, -4), Pair(-17, -4), Pair(-7, 3), Pair(0, -8), Pair(7, -1), Pair(-13, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-103, -135), Pair(-149, 41), Pair(-147, -43), Pair(40, 15), Pair(61, -2), Pair(29, -51), Pair(54, -60), Pair(-95, -152),
        Pair(-54, -15), Pair(-36, 13), Pair(-1, 2), Pair(-50, 47), Pair(-22, -1), Pair(-9, 13), Pair(-46, -30), Pair(0, -31),
        Pair(-60, 22), Pair(-27, 55), Pair(6, 33), Pair(28, -3), Pair(35, 33), Pair(40, 13), Pair(30, 3), Pair(-40, 6),
        Pair(-31, 55), Pair(2, 41), Pair(8, 48), Pair(30, 30), Pair(38, 34), Pair(31, 48), Pair(16, 33), Pair(28, -4),
        Pair(-18, 51), Pair(55, 31), Pair(30, 29), Pair(49, 34), Pair(48, 40), Pair(30, 31), Pair(13, 60), Pair(4, -5),
        Pair(-62, 55), Pair(-31, 50), Pair(3, 32), Pair(42, 34), Pair(19, 57), Pair(15, 19), Pair(9, 22), Pair(-24, 32),
        Pair(-57, 49), Pair(-78, 68), Pair(-34, 56), Pair(-10, 49), Pair(9, 29), Pair(-22, 36), Pair(0, 40), Pair(-21, 8),
        Pair(-69, -22), Pair(-45, 43), Pair(-66, 38), Pair(11, 20), Pair(-28, 59), Pair(-33, 27), Pair(-23, 24), Pair(-10, 4)
      },
      { // Piece 2
        Pair(-66, 4), Pair(-102, 34), Pair(-112, 54), Pair(-175, 35), Pair(-99, 6), Pair(-251, 58), Pair(-16, 64), Pair(-75, 32),
        Pair(-110, 24), Pair(-10, 1), Pair(-36, 31), Pair(9, -3), Pair(8, 15), Pair(-62, 56), Pair(-48, -13), Pair(5, -21),
        Pair(-8, 14), Pair(-42, 48), Pair(-42, 41), Pair(2, 2), Pair(-8, 0), Pair(-50, 19), Pair(-16, 21), Pair(-10, 9),
        Pair(10, 11), Pair(-2, 15), Pair(8, 29), Pair(-17, 30), Pair(25, 19), Pair(45, 30), Pair(4, 21), Pair(-17, 24),
        Pair(-20, 35), Pair(6, 14), Pair(-11, 4), Pair(-8, 31), Pair(12, 1), Pair(-3, 10), Pair(-15, 16), Pair(1, -18),
        Pair(1, 5), Pair(27, 4), Pair(12, 19), Pair(15, 20), Pair(13, 37), Pair(19, 15), Pair(18, 12), Pair(2, -6),
        Pair(-25, 14), Pair(31, -11), Pair(40, 4), Pair(9, 27), Pair(3, 33), Pair(12, -1), Pair(-1, 0), Pair(8, -22),
        Pair(-1, -18), Pair(22, -13), Pair(-18, 31), Pair(5, 10), Pair(35, 3), Pair(-20, 25), Pair(-105, 80), Pair(8, -32)
      },
      { // Piece 3
        Pair(-38, 43), Pair(-77, 68), Pair(-84, 45), Pair(-35, 49), Pair(-72, 33), Pair(-34, 61), Pair(-98, 71), Pair(-72, 72),
        Pair(-76, 57), Pair(-33, 61), Pair(-59, 54), Pair(-23, 68), Pair(52, 19), Pair(-34, 32), Pair(-60, 20), Pair(-57, 56),
        Pair(-13, 14), Pair(-49, 52), Pair(-21, 39), Pair(17, 9), Pair(36, 2), Pair(0, 28), Pair(-15, 39), Pair(-20, 24),
        Pair(-85, 56), Pair(19, 9), Pair(-70, 68), Pair(-22, 37), Pair(-28, 22), Pair(10, 6), Pair(-26, 13), Pair(-86, 57),
        Pair(-51, 24), Pair(-54, 32), Pair(-47, 33), Pair(-63, 46), Pair(16, 14), Pair(-39, 26), Pair(-67, 48), Pair(-52, -5),
        Pair(-17, 10), Pair(-31, 23), Pair(-58, 33), Pair(-16, 15), Pair(-43, 20), Pair(-73, 40), Pair(-16, 11), Pair(-22, -20),
        Pair(-63, 32), Pair(-24, 13), Pair(-34, 30), Pair(-17, -5), Pair(-39, 8), Pair(-36, 7), Pair(-36, 3), Pair(-47, -32),
        Pair(-26, 2), Pair(-44, 8), Pair(-41, 27), Pair(-12, 7), Pair(-4, 8), Pair(-22, 8), Pair(-29, 6), Pair(-29, -1)
      },
      { // Piece 4
        Pair(-30, 8), Pair(-61, 48), Pair(-73, 90), Pair(-17, 61), Pair(-24, 88), Pair(-56, 93), Pair(7, -3), Pair(-17, -14),
        Pair(14, 0), Pair(-15, 87), Pair(-39, 113), Pair(-138, 145), Pair(-56, 80), Pair(-27, 22), Pair(-18, 85), Pair(-9, 112),
        Pair(26, 52), Pair(-32, 57), Pair(-18, 105), Pair(-18, 55), Pair(-27, 134), Pair(-22, 96), Pair(21, 37), Pair(20, 76),
        Pair(3, 17), Pair(9, 53), Pair(9, 69), Pair(2, 44), Pair(-39, 107), Pair(17, 84), Pair(35, 50), Pair(8, 88),
        Pair(16, 30), Pair(11, 48), Pair(23, 47), Pair(23, 96), Pair(3, 125), Pair(5, 57), Pair(12, 85), Pair(18, 43),
        Pair(8, 62), Pair(6, 62), Pair(19, 51), Pair(14, 88), Pair(9, 79), Pair(10, 59), Pair(35, 46), Pair(-13, 91),
        Pair(-29, 30), Pair(29, 41), Pair(23, 29), Pair(25, 29), Pair(20, 48), Pair(24, 18), Pair(44, -33), Pair(9, 4),
        Pair(13, -43), Pair(13, -53), Pair(29, -65), Pair(26, -23), Pair(-19, 62), Pair(24, -41), Pair(-12, 25), Pair(22, 7)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(12, -5), Pair(-28, 9), Pair(-7, 7), Pair(-10, 3), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-64, 2), Pair(36, -10), Pair(-34, -23), Pair(-15, -46), Pair(15, -113), Pair(-55, 0), Pair(-68, 88), Pair(-126, -7),
        Pair(-11, 34), Pair(18, 26), Pair(26, -1), Pair(61, -28), Pair(-54, -29), Pair(-22, -21), Pair(-22, 25), Pair(27, 20),
        Pair(-52, 24), Pair(63, -12), Pair(-25, -13), Pair(-1, -24), Pair(34, -40), Pair(-5, -33), Pair(-31, 9), Pair(-25, 6),
        Pair(-46, 4), Pair(15, 2), Pair(-2, -17), Pair(-14, -6), Pair(-8, -18), Pair(1, -26), Pair(30, -1), Pair(2, -20),
        Pair(-34, -6), Pair(-26, 0), Pair(-11, -16), Pair(-27, -9), Pair(-37, -5), Pair(-29, -12), Pair(-5, -4), Pair(-16, -17),
        Pair(-29, 4), Pair(-3, 9), Pair(-2, -3), Pair(-27, 0), Pair(-14, 7), Pair(-19, -5), Pair(-6, 3), Pair(-18, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(9, -162), Pair(-108, -64), Pair(-116, -7), Pair(-58, 0), Pair(-71, 37), Pair(-60, -49), Pair(10, -18), Pair(31, -148),
        Pair(-65, 25), Pair(-29, -14), Pair(79, -77), Pair(-34, 11), Pair(17, 6), Pair(148, -121), Pair(-8, 34), Pair(-110, -1),
        Pair(43, -27), Pair(52, -15), Pair(11, 27), Pair(53, -13), Pair(66, -5), Pair(95, -28), Pair(-92, 34), Pair(68, -7),
        Pair(27, 29), Pair(30, -6), Pair(48, 18), Pair(69, -3), Pair(72, -8), Pair(70, -1), Pair(113, -53), Pair(40, -20),
        Pair(-10, 17), Pair(41, 34), Pair(55, -5), Pair(14, 23), Pair(76, 8), Pair(56, -1), Pair(108, -7), Pair(-21, 14),
        Pair(25, -32), Pair(50, 7), Pair(5, 20), Pair(79, 19), Pair(25, 38), Pair(14, 25), Pair(37, -11), Pair(7, -2),
        Pair(-82, 33), Pair(-44, 33), Pair(38, 31), Pair(-5, 28), Pair(-7, 14), Pair(45, -4), Pair(41, -56), Pair(-75, 1),
        Pair(-116, -70), Pair(-80, 51), Pair(56, -38), Pair(-12, 41), Pair(12, 53), Pair(6, 17), Pair(-73, 67), Pair(-171, -59)
      },
      { // Piece 2
        Pair(-82, 25), Pair(-6, -12), Pair(-186, 22), Pair(-64, 15), Pair(-135, 64), Pair(-74, -40), Pair(27, -32), Pair(-117, -25),
        Pair(78, -39), Pair(-2, -30), Pair(-79, 4), Pair(98, -38), Pair(-11, -55), Pair(-28, -28), Pair(-60, 37), Pair(12, 17),
        Pair(37, 5), Pair(-62, 57), Pair(-23, 16), Pair(8, -7), Pair(-11, -23), Pair(-60, 19), Pair(1, 20), Pair(109, 10),
        Pair(-86, 14), Pair(-12, 10), Pair(-23, -3), Pair(14, -10), Pair(-85, 26), Pair(8, 27), Pair(-46, 23), Pair(5, 30),
        Pair(37, -42), Pair(6, 0), Pair(13, -1), Pair(43, -12), Pair(62, -30), Pair(27, 9), Pair(57, -21), Pair(49, -64),
        Pair(20, 8), Pair(28, -31), Pair(67, -6), Pair(0, 15), Pair(35, 8), Pair(-25, 4), Pair(-25, 31), Pair(20, 2),
        Pair(26, 22), Pair(5, -13), Pair(56, -36), Pair(40, 5), Pair(-3, 10), Pair(42, -13), Pair(-57, 8), Pair(12, -92),
        Pair(52, -39), Pair(1, -42), Pair(-43, 26), Pair(-49, 25), Pair(-48, 9), Pair(-1, -14), Pair(-20, 56), Pair(71, -40)
      },
      { // Piece 3
        Pair(-94, 51), Pair(-50, 9), Pair(-47, 50), Pair(-55, 17), Pair(-28, 58), Pair(-97, 25), Pair(-71, 64), Pair(-8, 46),
        Pair(-29, 6), Pair(-45, 8), Pair(7, 6), Pair(4, 6), Pair(18, -28), Pair(-15, -6), Pair(-17, 6), Pair(-2, -15),
        Pair(55, -2), Pair(10, 14), Pair(-7, -1), Pair(-35, 11), Pair(161, -46), Pair(19, -75), Pair(-81, 94), Pair(-105, 15),
        Pair(-106, 26), Pair(-48, 11), Pair(9, 1), Pair(60, -11), Pair(-41, 26), Pair(43, -2), Pair(10, 8), Pair(-40, 4),
        Pair(-106, 26), Pair(-41, 23), Pair(-97, 44), Pair(-81, 20), Pair(-51, 5), Pair(17, -6), Pair(-70, 35), Pair(-86, 6),
        Pair(-71, 7), Pair(-39, 26), Pair(-105, 13), Pair(-11, 5), Pair(-51, 11), Pair(14, -10), Pair(-59, 16), Pair(-126, 18),
        Pair(-51, -38), Pair(-114, 21), Pair(-24, 2), Pair(-45, -10), Pair(-40, -17), Pair(-48, -7), Pair(-23, -70), Pair(-46, -22),
        Pair(-47, -24), Pair(-33, -11), Pair(-87, 26), Pair(-41, -4), Pair(-43, -14), Pair(-42, -10), Pair(-68, 3), Pair(-66, -12)
      },
      { // Piece 4
        Pair(-102, 57), Pair(16, -20), Pair(73, 73), Pair(-25, 25), Pair(-19, 23), Pair(28, 10), Pair(-100, 62), Pair(-29, 76),
        Pair(132, -89), Pair(-16, -34), Pair(9, 23), Pair(43, 4), Pair(-11, 70), Pair(-38, 107), Pair(28, 16), Pair(75, -2),
        Pair(36, 1), Pair(-29, 3), Pair(116, -14), Pair(3, 64), Pair(-9, 74), Pair(45, 67), Pair(46, -19), Pair(161, -125),
        Pair(90, -29), Pair(-59, 44), Pair(-43, 89), Pair(90, -25), Pair(159, -43), Pair(7, 67), Pair(-11, 105), Pair(15, -3),
        Pair(-26, 3), Pair(28, 8), Pair(53, -10), Pair(-14, 11), Pair(81, -14), Pair(107, -10), Pair(2, 31), Pair(31, 8),
        Pair(-99, 54), Pair(7, 28), Pair(55, 2), Pair(20, -30), Pair(28, 19), Pair(40, -12), Pair(28, -33), Pair(84, 23),
        Pair(-23, 37), Pair(38, -87), Pair(-12, -4), Pair(24, -2), Pair(43, -12), Pair(47, -46), Pair(-32, 28), Pair(-4, 39),
        Pair(-43, -72), Pair(7, -154), Pair(-13, -6), Pair(-5, -24), Pair(-47, -76), Pair(49, -37), Pair(-101, -140), Pair(-122, -74)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(26, 2), Pair(-21, 16), Pair(3, 14), Pair(-14, 16), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(62, -10), Pair(-106, 64), Pair(56, -32), Pair(119, -20), Pair(3, -16), Pair(33, 0), Pair(-97, 85), Pair(6, -31),
        Pair(-66, 33), Pair(-143, 97), Pair(-53, 44), Pair(3, -3), Pair(-85, 26), Pair(-54, 7), Pair(-22, 63), Pair(46, 10),
        Pair(-55, 2), Pair(11, 10), Pair(-33, -21), Pair(32, -8), Pair(-88, -9), Pair(23, -28), Pair(-38, 21), Pair(39, -15),
        Pair(23, -22), Pair(-75, 6), Pair(36, -41), Pair(10, -27), Pair(-27, -2), Pair(-47, -41), Pair(52, -15), Pair(-20, -8),
        Pair(-7, -19), Pair(-80, 11), Pair(21, -16), Pair(-34, -3), Pair(-19, -7), Pair(-63, -6), Pair(31, -17), Pair(-26, -10),
        Pair(-44, 5), Pair(-45, 23), Pair(-10, -2), Pair(-45, -15), Pair(-26, 6), Pair(26, -15), Pair(-19, 3), Pair(-19, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-129, -162), Pair(-17, -40), Pair(-102, -45), Pair(-43, -61), Pair(-111, -46), Pair(-84, -22), Pair(-39, -17), Pair(-35, -132),
        Pair(-60, -30), Pair(25, -17), Pair(-42, -31), Pair(-71, -29), Pair(-43, 36), Pair(89, -45), Pair(0, 40), Pair(36, -12),
        Pair(-8, 6), Pair(31, -29), Pair(119, 10), Pair(1, -44), Pair(-10, -9), Pair(35, -66), Pair(-15, 13), Pair(-56, 55),
        Pair(81, 1), Pair(12, 14), Pair(72, -22), Pair(92, -46), Pair(15, 2), Pair(40, -5), Pair(94, -20), Pair(33, -62),
        Pair(-126, 0), Pair(-24, -47), Pair(56, -7), Pair(84, -27), Pair(42, -36), Pair(73, -17), Pair(102, -41), Pair(10, -59),
        Pair(25, -26), Pair(-18, 20), Pair(-15, 9), Pair(97, -8), Pair(122, -59), Pair(-6, 19), Pair(-99, 45), Pair(-55, -43),
        Pair(-48, 26), Pair(-83, -26), Pair(-77, 25), Pair(-14, 14), Pair(39, 4), Pair(40, -18), Pair(-24, 10), Pair(38, 40),
        Pair(-62, -88), Pair(-135, -3), Pair(164, -23), Pair(39, -77), Pair(23, 26), Pair(-42, -70), Pair(-146, 37), Pair(11, -27)
      },
      { // Piece 2
        Pair(8, -43), Pair(-13, -63), Pair(-90, -52), Pair(-73, 13), Pair(-133, 80), Pair(3, -65), Pair(-44, -30), Pair(-36, 72),
        Pair(-44, -23), Pair(-14, -11), Pair(-85, 1), Pair(3, 36), Pair(18, -13), Pair(-22, -55), Pair(-53, -54), Pair(-115, -2),
        Pair(13, 13), Pair(-49, 9), Pair(-48, 14), Pair(-183, -58), Pair(-164, 7), Pair(-12, 13), Pair(-2, -21), Pair(105, 11),
        Pair(-134, -11), Pair(-6, 8), Pair(-51, 30), Pair(64, -54), Pair(39, -44), Pair(71, -6), Pair(-67, 22), Pair(39, -9),
        Pair(75, -6), Pair(50, -34), Pair(-50, 1), Pair(173, -34), Pair(86, 0), Pair(-98, -17), Pair(-74, 36), Pair(-5, -34),
        Pair(-28, 8), Pair(-35, -2), Pair(-36, 9), Pair(37, -20), Pair(81, -15), Pair(19, 2), Pair(-20, -7), Pair(-16, -49),
        Pair(-68, -6), Pair(25, -16), Pair(5, -22), Pair(63, -42), Pair(-3, -16), Pair(-66, -22), Pair(-28, -54), Pair(24, 21),
        Pair(-56, -58), Pair(-42, 29), Pair(-117, 24), Pair(-15, 3), Pair(34, -11), Pair(-79, -40), Pair(94, 19), Pair(-43, -42)
      },
      { // Piece 3
        Pair(40, -22), Pair(-35, 16), Pair(-118, 42), Pair(-13, 5), Pair(-58, 11), Pair(-67, -1), Pair(-153, 25), Pair(-36, 25),
        Pair(-128, 5), Pair(-4, -42), Pair(-141, -19), Pair(-99, 7), Pair(-88, 28), Pair(-19, -32), Pair(51, -46), Pair(-58, -33),
        Pair(-51, -11), Pair(-63, -17), Pair(5, -25), Pair(-62, -12), Pair(17, -40), Pair(165, -62), Pair(23, -19), Pair(4, -38),
        Pair(-18, -59), Pair(-14, -35), Pair(1, -3), Pair(29, -39), Pair(-40, -56), Pair(-5, -6), Pair(-24, -23), Pair(2, -19),
        Pair(7, -10), Pair(-92, -11), Pair(-77, -37), Pair(-29, -11), Pair(-58, 0), Pair(5, -12), Pair(-109, 20), Pair(-93, 29),
        Pair(-30, -57), Pair(-96, -2), Pair(-42, -20), Pair(-10, -7), Pair(-48, -7), Pair(-13, -11), Pair(-9, -53), Pair(-97, 9),
        Pair(-95, -36), Pair(-71, -25), Pair(-6, -55), Pair(-5, -88), Pair(-70, -39), Pair(-32, -4), Pair(-22, -28), Pair(-142, -75),
        Pair(-14, -49), Pair(-139, -11), Pair(10, -56), Pair(-17, -37), Pair(70, -79), Pair(28, -99), Pair(-48, -44), Pair(-111, -27)
      },
      { // Piece 4
        Pair(57, 10), Pair(126, -55), Pair(-16, -23), Pair(49, -55), Pair(-9, 18), Pair(68, -67), Pair(-40, 20), Pair(-17, -94),
        Pair(-55, -82), Pair(-125, 32), Pair(30, -78), Pair(-22, 76), Pair(58, -61), Pair(-25, -3), Pair(51, -91), Pair(248, -53),
        Pair(40, -3), Pair(1, -106), Pair(-44, 41), Pair(74, -46), Pair(55, -82), Pair(11, -75), Pair(108, -128), Pair(191, -25),
        Pair(44, 3), Pair(51, -12), Pair(-6, 33), Pair(96, -87), Pair(1, 20), Pair(51, -121), Pair(48, 61), Pair(-54, 62),
        Pair(-4, -25), Pair(157, 10), Pair(35, 17), Pair(-5, 37), Pair(-61, 21), Pair(125, 3), Pair(-74, -1), Pair(-27, 71),
        Pair(-52, -78), Pair(9, -44), Pair(127, -14), Pair(-86, -15), Pair(-9, -16), Pair(-32, 23), Pair(29, -52), Pair(-115, 48),
        Pair(41, -74), Pair(-16, -13), Pair(-59, -37), Pair(-52, 8), Pair(-8, -85), Pair(7, -202), Pair(61, -37), Pair(-26, -100),
        Pair(60, 40), Pair(-24, -135), Pair(-154, -154), Pair(105, -163), Pair(73, -77), Pair(-104, -45), Pair(-47, -64), Pair(39, 44)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(22, 6), Pair(8, 17), Pair(-22, 27), Pair(-35, 18), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-74, -10), Pair(53, -36), Pair(12, -9), Pair(54, -12), Pair(-53, 4), Pair(-130, -15), Pair(-18, -1), Pair(-93, 2),
        Pair(-18, 42), Pair(-25, 50), Pair(-67, 24), Pair(-91, 50), Pair(-81, 115), Pair(-148, 72), Pair(25, 44), Pair(-147, 52),
        Pair(-6, -19), Pair(-64, 16), Pair(-97, -1), Pair(-162, 27), Pair(-153, 23), Pair(2, -45), Pair(-68, 7), Pair(-94, -10),
        Pair(-82, -18), Pair(-93, -2), Pair(24, -54), Pair(78, -42), Pair(-70, -12), Pair(46, -58), Pair(4, -28), Pair(8, -41),
        Pair(-59, -22), Pair(-139, 7), Pair(-87, -9), Pair(-42, -12), Pair(0, -24), Pair(11, -29), Pair(-49, -9), Pair(-16, -21),
        Pair(-90, 3), Pair(-64, 17), Pair(16, -7), Pair(-143, 29), Pair(9, 15), Pair(15, -10), Pair(28, -13), Pair(-102, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(19, -97), Pair(-19, 3), Pair(-69, -70), Pair(14, 19), Pair(-39, -130), Pair(-74, -64), Pair(-26, -80), Pair(-48, -132),
        Pair(-63, 0), Pair(-48, -19), Pair(-145, -49), Pair(-66, -77), Pair(-92, -32), Pair(12, -49), Pair(-62, -108), Pair(-92, -68),
        Pair(-86, -44), Pair(-68, -103), Pair(-21, -76), Pair(40, -30), Pair(42, -76), Pair(53, -90), Pair(-24, -36), Pair(-98, -21),
        Pair(-47, -70), Pair(10, -47), Pair(95, -84), Pair(19, -64), Pair(117, -55), Pair(78, -73), Pair(58, -53), Pair(-73, 0),
        Pair(-59, 13), Pair(-116, 8), Pair(124, -43), Pair(-24, -46), Pair(66, -34), Pair(103, -37), Pair(-40, -17), Pair(38, 20),
        Pair(-109, -85), Pair(61, -58), Pair(88, -48), Pair(72, -43), Pair(53, -21), Pair(97, -51), Pair(53, -99), Pair(72, -64),
        Pair(-2, 5), Pair(-42, -43), Pair(0, -29), Pair(-54, -25), Pair(52, -46), Pair(39, -45), Pair(-37, -47), Pair(-66, -51),
        Pair(-32, -63), Pair(-147, -57), Pair(253, -77), Pair(22, -29), Pair(87, -108), Pair(-53, -5), Pair(74, -89), Pair(-27, -69)
      },
      { // Piece 2
        Pair(-98, -59), Pair(-90, -33), Pair(-135, -35), Pair(-129, -55), Pair(-87, 13), Pair(-76, -82), Pair(-149, -35), Pair(-76, -133),
        Pair(-82, -92), Pair(-93, 13), Pair(-71, -28), Pair(-118, 7), Pair(-201, -59), Pair(-136, -41), Pair(-207, -45), Pair(18, -9),
        Pair(-64, -59), Pair(-81, -2), Pair(-103, 7), Pair(-108, -26), Pair(-208, -8), Pair(-211, -47), Pair(-70, -27), Pair(46, -72),
        Pair(38, -52), Pair(-138, -8), Pair(-122, -22), Pair(-120, -3), Pair(-63, -36), Pair(-118, -20), Pair(-194, 23), Pair(-27, 4),
        Pair(-63, -23), Pair(-57, -5), Pair(94, -56), Pair(-52, -30), Pair(-28, -26), Pair(-52, -31), Pair(-124, -21), Pair(-4, 73),
        Pair(-45, 20), Pair(-8, -20), Pair(1, -47), Pair(9, -20), Pair(-30, -36), Pair(-29, -20), Pair(31, -39), Pair(-34, -74),
        Pair(-88, -58), Pair(-97, -35), Pair(-58, -48), Pair(22, -36), Pair(-59, -14), Pair(37, -71), Pair(-156, 6), Pair(-123, -88),
        Pair(-66, -55), Pair(-230, 75), Pair(-174, -23), Pair(-17, -23), Pair(108, -80), Pair(49, -60), Pair(-37, -43), Pair(-65, -52)
      },
      { // Piece 3
        Pair(-28, -60), Pair(-64, -41), Pair(-55, -69), Pair(-41, -19), Pair(-93, -21), Pair(-2, -14), Pair(-70, -41), Pair(-40, -63),
        Pair(-56, -46), Pair(-63, -32), Pair(-144, -49), Pair(-37, -59), Pair(-113, -39), Pair(-113, -40), Pair(70, -80), Pair(-4, -71),
        Pair(-47, -54), Pair(15, -69), Pair(-94, -74), Pair(88, -102), Pair(-112, -41), Pair(-53, -75), Pair(-41, -66), Pair(-153, -44),
        Pair(-31, -63), Pair(-17, -64), Pair(-38, -49), Pair(86, -94), Pair(-148, -44), Pair(107, -84), Pair(-147, -51), Pair(-31, -55),
        Pair(-70, -52), Pair(30, -91), Pair(127, -95), Pair(-12, -84), Pair(14, -55), Pair(74, -50), Pair(11, -82), Pair(-82, -95),
        Pair(-54, -67), Pair(-43, -18), Pair(-16, -33), Pair(-79, 1), Pair(33, -92), Pair(-25, -83), Pair(56, -94), Pair(-73, -43),
        Pair(-130, -76), Pair(-85, -71), Pair(41, -92), Pair(124, -109), Pair(53, -130), Pair(140, -92), Pair(42, -86), Pair(50, -88),
        Pair(-59, -100), Pair(-111, -97), Pair(1, -128), Pair(-56, -94), Pair(64, -100), Pair(24, -102), Pair(65, -133), Pair(-56, -122)
      },
      { // Piece 4
        Pair(-75, -147), Pair(-55, -193), Pair(-25, -68), Pair(8, -23), Pair(-27, -54), Pair(-88, -95), Pair(-45, -11), Pair(-65, -107),
        Pair(-30, -168), Pair(49, -54), Pair(-60, -69), Pair(42, -19), Pair(-5, -59), Pair(-37, -29), Pair(-11, -128), Pair(17, -62),
        Pair(61, 12), Pair(-25, -150), Pair(-65, -95), Pair(-50, -97), Pair(-18, -30), Pair(10, -130), Pair(12, -113), Pair(-7, -27),
        Pair(-45, -73), Pair(19, -56), Pair(-10, -80), Pair(31, -49), Pair(17, -33), Pair(-9, -111), Pair(-23, -173), Pair(57, -67),
        Pair(-66, -128), Pair(2, -5), Pair(-8, -72), Pair(10, -23), Pair(19, -36), Pair(-28, -85), Pair(14, 5), Pair(48, -70),
        Pair(37, -63), Pair(-72, -67), Pair(-10, -18), Pair(-10, -49), Pair(51, -49), Pair(-18, -105), Pair(-23, -29), Pair(102, 3),
        Pair(-24, -80), Pair(30, 12), Pair(29, -41), Pair(-96, -37), Pair(-14, -111), Pair(-42, -120), Pair(4, -58), Pair(-11, -53),
        Pair(-121, -160), Pair(-26, -99), Pair(42, -71), Pair(-5, -150), Pair(-11, -124), Pair(-61, -119), Pair(-61, -101), Pair(-83, -156)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(-2, 8), Pair(-37, 17), Pair(-85, 24), Pair(-59, 13), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, -9), Pair(7, 51), Pair(19, -35), Pair(19, -63), Pair(-15, 55), Pair(-14, -16), Pair(-37, 78), Pair(7, 35),
        Pair(56, -10), Pair(5, 31), Pair(11, 84), Pair(60, 36), Pair(-49, -77), Pair(0, -21), Pair(-34, 152), Pair(30, -5),
        Pair(-75, 3), Pair(-86, 69), Pair(117, 10), Pair(-47, 47), Pair(-31, -1), Pair(-54, 11), Pair(-34, 28), Pair(-73, -40),
        Pair(-28, -42), Pair(-48, -1), Pair(-1, -29), Pair(-66, 10), Pair(-54, -52), Pair(95, -56), Pair(-27, 11), Pair(-183, -9),
        Pair(16, -62), Pair(-81, -12), Pair(-19, -57), Pair(-60, 10), Pair(-27, -8), Pair(-70, -28), Pair(-157, 5), Pair(-149, -3),
        Pair(14, -33), Pair(4, 3), Pair(78, -23), Pair(-50, -76), Pair(-40, -15), Pair(37, -41), Pair(-58, 9), Pair(68, -16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-6, -79), Pair(1, -11), Pair(-1, -11), Pair(4, 9), Pair(-16, -82), Pair(-17, -183), Pair(-10, 32), Pair(3, 74),
        Pair(6, 25), Pair(-22, -87), Pair(-41, -84), Pair(-2, -25), Pair(-34, -160), Pair(7, -28), Pair(26, 66), Pair(-72, -98),
        Pair(19, -69), Pair(17, -62), Pair(35, 38), Pair(29, -101), Pair(-66, -16), Pair(33, 70), Pair(24, 69), Pair(-4, -51),
        Pair(2, -14), Pair(14, 13), Pair(-4, -18), Pair(-78, 27), Pair(16, -46), Pair(-12, -36), Pair(-33, -89), Pair(-11, 46),
        Pair(10, 35), Pair(-5, -61), Pair(43, 0), Pair(22, 26), Pair(25, -90), Pair(-8, 29), Pair(18, 17), Pair(-19, -11),
        Pair(-11, -3), Pair(31, 71), Pair(-22, -83), Pair(64, 52), Pair(42, 114), Pair(32, 40), Pair(-1, -93), Pair(8, -26),
        Pair(-28, -36), Pair(-13, 60), Pair(15, -18), Pair(-48, -8), Pair(73, 54), Pair(-41, -118), Pair(-30, -63), Pair(-17, -76),
        Pair(-4, -48), Pair(-47, -25), Pair(24, 52), Pair(20, 22), Pair(-28, -81), Pair(48, 40), Pair(26, -109), Pair(-1, 3)
      },
      { // Piece 2
        Pair(4, 84), Pair(-2, -26), Pair(-26, -104), Pair(-8, -32), Pair(2, 79), Pair(-14, 59), Pair(-3, 71), Pair(0, 45),
        Pair(-22, 99), Pair(49, 78), Pair(-19, -31), Pair(-5, 21), Pair(7, -16), Pair(-38, -82), Pair(-65, 70), Pair(-9, 41),
        Pair(2, 99), Pair(28, 56), Pair(21, 21), Pair(39, 154), Pair(-30, -96), Pair(-23, 32), Pair(-12, 0), Pair(-21, 59),
        Pair(7, 64), Pair(-29, 63), Pair(-1, 61), Pair(71, 97), Pair(44, 72), Pair(-33, 18), Pair(-48, 22), Pair(-17, -4),
        Pair(-26, -29), Pair(-49, 63), Pair(45, -36), Pair(-2, 49), Pair(-54, 7), Pair(-4, 39), Pair(-7, 41), Pair(29, 97),
        Pair(-8, -3), Pair(-21, -16), Pair(-47, -20), Pair(71, 53), Pair(25, -17), Pair(34, -32), Pair(6, -16), Pair(-3, 7),
        Pair(0, -4), Pair(-30, 65), Pair(-51, 91), Pair(-31, -60), Pair(-55, 37), Pair(-5, 34), Pair(-10, 73), Pair(-28, -78),
        Pair(-5, -88), Pair(-9, -85), Pair(-34, -99), Pair(-8, -108), Pair(18, 52), Pair(35, -9), Pair(20, 105), Pair(-5, -20)
      },
      { // Piece 3
        Pair(3, 47), Pair(-17, -7), Pair(17, 52), Pair(19, 68), Pair(-25, -69), Pair(-66, 1), Pair(3, 90), Pair(4, -2),
        Pair(-22, -25), Pair(8, 39), Pair(-14, -72), Pair(-53, 32), Pair(35, 25), Pair(-48, -115), Pair(-24, 74), Pair(46, -39),
        Pair(-105, -48), Pair(-4, 27), Pair(-57, 40), Pair(61, 25), Pair(-20, 1), Pair(53, -7), Pair(8, 10), Pair(-43, -48),
        Pair(21, -26), Pair(35, 35), Pair(12, 24), Pair(-41, 3), Pair(-14, 12), Pair(7, -46), Pair(5, 23), Pair(-18, -6),
        Pair(12, 43), Pair(25, 31), Pair(-55, -111), Pair(26, 3), Pair(37, -28), Pair(-14, -13), Pair(-52, -3), Pair(-49, -42),
        Pair(50, -147), Pair(54, 9), Pair(6, -59), Pair(-57, -63), Pair(20, -9), Pair(46, -69), Pair(14, 8), Pair(-50, 95),
        Pair(-23, -122), Pair(-12, -89), Pair(5, -27), Pair(60, 9), Pair(57, -61), Pair(-13, -48), Pair(18, 102), Pair(2, 0),
        Pair(54, -45), Pair(-32, -64), Pair(-19, -65), Pair(20, -112), Pair(33, 18), Pair(-88, -106), Pair(-1, -8), Pair(21, -71)
      },
      { // Piece 4
        Pair(-16, -32), Pair(-33, -76), Pair(-21, -40), Pair(-27, -49), Pair(-35, -32), Pair(-55, -62), Pair(-22, -22), Pair(-52, -91),
        Pair(-26, -42), Pair(5, -35), Pair(-18, -10), Pair(30, 46), Pair(78, 85), Pair(-60, -36), Pair(-71, -98), Pair(24, 47),
        Pair(-27, -64), Pair(47, 81), Pair(-41, -18), Pair(-5, -31), Pair(-77, -52), Pair(-96, -68), Pair(34, 39), Pair(22, 24),
        Pair(24, 39), Pair(-53, -75), Pair(-47, -75), Pair(65, 65), Pair(-6, -77), Pair(-32, -60), Pair(-26, -38), Pair(-10, -46),
        Pair(-10, -20), Pair(47, 33), Pair(-1, -49), Pair(61, 63), Pair(42, 64), Pair(-18, -66), Pair(1, -10), Pair(-51, -117),
        Pair(-36, -118), Pair(-53, -100), Pair(38, 17), Pair(-4, -39), Pair(0, -16), Pair(39, 69), Pair(29, 44), Pair(-29, -15),
        Pair(-40, -96), Pair(-13, -67), Pair(-38, -75), Pair(-15, -22), Pair(-3, 18), Pair(-36, -41), Pair(9, 23), Pair(-18, -55),
        Pair(-12, -25), Pair(1, -7), Pair(11, 28), Pair(-59, -109), Pair(-27, -72), Pair(-47, -66), Pair(-17, -37), Pair(9, 17)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(25, 30), Pair(-6, 45), Pair(-79, 43), Pair(-159, 54), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 2
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-42, 34), Pair(-70, 60), Pair(-99, 105), Pair(31, -45), Pair(14, -53), Pair(67, -78), Pair(-35, -142), Pair(-154, -56),
        Pair(8, 83), Pair(17, 57), Pair(31, 24), Pair(31, -1), Pair(75, -30), Pair(102, -19), Pair(59, 30), Pair(12, 41),
        Pair(-13, 39), Pair(-1, 26), Pair(-3, 6), Pair(5, -11), Pair(41, -30), Pair(33, -25), Pair(16, 4), Pair(-4, -3),
        Pair(-10, 15), Pair(-6, 22), Pair(0, -5), Pair(13, -19), Pair(21, -22), Pair(27, -24), Pair(9, -6), Pair(-13, -11),
        Pair(-24, 6), Pair(-16, 11), Pair(-15, -3), Pair(-9, -6), Pair(-3, -5), Pair(1, -12), Pair(12, -16), Pair(-22, -16),
        Pair(-13, 9), Pair(-6, 16), Pair(-4, 4), Pair(-22, 13), Pair(5, 11), Pair(38, -8), Pair(32, -4), Pair(-16, -17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-229, 36), Pair(-210, 52), Pair(-175, 63), Pair(-33, 43), Pair(-7, 30), Pair(-125, 31), Pair(-146, -103), Pair(-168, -102),
        Pair(-95, 85), Pair(-51, 60), Pair(-15, 36), Pair(46, 37), Pair(-17, 51), Pair(37, 40), Pair(27, 91), Pair(63, -37),
        Pair(-35, 51), Pair(-15, 57), Pair(-12, 88), Pair(23, 46), Pair(25, 53), Pair(91, 25), Pair(4, 62), Pair(15, 78),
        Pair(-47, 77), Pair(14, 46), Pair(24, 67), Pair(50, 53), Pair(40, 60), Pair(67, 44), Pair(18, 70), Pair(46, 56),
        Pair(-26, 68), Pair(7, 35), Pair(19, 68), Pair(33, 65), Pair(37, 64), Pair(49, 41), Pair(58, 37), Pair(11, 42),
        Pair(-39, 49), Pair(-14, 51), Pair(10, 51), Pair(22, 72), Pair(40, 56), Pair(17, 38), Pair(23, 27), Pair(9, 25),
        Pair(-39, 29), Pair(-50, 66), Pair(-26, 55), Pair(2, 41), Pair(8, 31), Pair(9, 34), Pair(2, 20), Pair(10, 8),
        Pair(-68, 65), Pair(-39, 31), Pair(-15, 44), Pair(-11, 50), Pair(-1, 54), Pair(13, 20), Pair(-12, 25), Pair(-1, -20)
      },
      { // Piece 2
        Pair(-44, 37), Pair(-34, 11), Pair(-141, 64), Pair(-190, 115), Pair(-87, 8), Pair(-76, 37), Pair(-12, 83), Pair(-34, 44),
        Pair(-16, 46), Pair(-6, 34), Pair(-17, 39), Pair(-76, 58), Pair(-17, 8), Pair(-6, 22), Pair(-90, 97), Pair(-7, 40),
        Pair(0, 52), Pair(-17, 46), Pair(-4, 42), Pair(-20, 45), Pair(-16, 42), Pair(48, 40), Pair(48, 44), Pair(16, 53),
        Pair(-16, 47), Pair(8, 35), Pair(9, 41), Pair(20, 69), Pair(26, 36), Pair(33, 24), Pair(-3, 38), Pair(24, 17),
        Pair(-2, 17), Pair(-27, 43), Pair(15, 43), Pair(16, 37), Pair(23, 35), Pair(-1, 41), Pair(7, 35), Pair(-7, 35),
        Pair(-19, 38), Pair(22, 50), Pair(10, 46), Pair(20, 38), Pair(15, 56), Pair(18, 44), Pair(22, 42), Pair(20, 12),
        Pair(-2, 42), Pair(-1, 14), Pair(21, 21), Pair(1, 33), Pair(14, 33), Pair(31, 15), Pair(36, 14), Pair(6, -6),
        Pair(-17, 11), Pair(27, 26), Pair(14, 25), Pair(16, 31), Pair(14, 52), Pair(-4, 48), Pair(14, 32), Pair(0, -10)
      },
      { // Piece 3
        Pair(-31, 157), Pair(89, 133), Pair(7, 197), Pair(52, 110), Pair(65, 92), Pair(53, 164), Pair(56, 89), Pair(9, 52),
        Pair(-4, 78), Pair(9, 91), Pair(29, 94), Pair(55, 68), Pair(43, 72), Pair(121, 46), Pair(44, 88), Pair(39, 66),
        Pair(22, 60), Pair(37, 75), Pair(31, 89), Pair(29, 78), Pair(85, 27), Pair(127, 15), Pair(102, 41), Pair(47, 27),
        Pair(-5, 75), Pair(50, 67), Pair(31, 71), Pair(39, 70), Pair(65, 37), Pair(59, 45), Pair(74, 38), Pair(48, 22),
        Pair(-21, 69), Pair(23, 67), Pair(12, 72), Pair(31, 61), Pair(22, 54), Pair(7, 58), Pair(35, 47), Pair(17, 27),
        Pair(3, 49), Pair(3, 40), Pair(-7, 61), Pair(2, 62), Pair(20, 49), Pair(7, 46), Pair(52, 5), Pair(4, 8),
        Pair(-19, 49), Pair(6, 50), Pair(7, 57), Pair(10, 63), Pair(28, 36), Pair(25, 38), Pair(31, 27), Pair(3, 24),
        Pair(-13, 47), Pair(-5, 44), Pair(0, 46), Pair(2, 46), Pair(12, 31), Pair(12, 24), Pair(12, 23), Pair(-8, 33)
      },
      { // Piece 4
        Pair(-177, 282), Pair(-40, 170), Pair(-45, 190), Pair(-4, 173), Pair(24, 105), Pair(-18, 83), Pair(2, 118), Pair(113, 19),
        Pair(-75, 142), Pair(-21, 104), Pair(-50, 197), Pair(6, 117), Pair(-55, 208), Pair(36, 135), Pair(-124, 200), Pair(-42, 197),
        Pair(-23, 113), Pair(-15, 112), Pair(2, 132), Pair(-11, 164), Pair(9, 159), Pair(69, 111), Pair(32, 135), Pair(40, 86),
        Pair(-33, 122), Pair(-18, 143), Pair(-10, 148), Pair(1, 156), Pair(13, 135), Pair(5, 140), Pair(11, 158), Pair(18, 114),
        Pair(-9, 80), Pair(-24, 141), Pair(-6, 133), Pair(6, 138), Pair(5, 134), Pair(1, 135), Pair(16, 119), Pair(1, 128),
        Pair(-30, 96), Pair(-9, 98), Pair(-6, 105), Pair(-4, 119), Pair(4, 129), Pair(12, 110), Pair(15, 112), Pair(14, 100),
        Pair(-16, 126), Pair(-20, 84), Pair(-5, 77), Pair(0, 87), Pair(0, 90), Pair(5, 54), Pair(23, 4), Pair(31, 19),
        Pair(-57, 95), Pair(-32, 90), Pair(-23, 68), Pair(-5, 68), Pair(-13, 79), Pair(-12, 67), Pair(-8, 55), Pair(-4, 48)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(26, -25), Pair(-17, 17), Pair(-24, 25), Pair(-48, 37), Pair(-57, 38), Pair(-23, 19), Pair(-8, 0), Pair(10, -36),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(102, 66), Pair(-65, 6), Pair(12, -79), Pair(-19, -110), Pair(-16, -97), Pair(-26, -115), Pair(-140, 129), Pair(54, 81),
        Pair(14, 59), Pair(25, 41), Pair(20, -10), Pair(67, -52), Pair(126, -90), Pair(65, -18), Pair(5, 72), Pair(46, 50),
        Pair(-24, 20), Pair(0, 15), Pair(1, -12), Pair(25, -40), Pair(33, -22), Pair(24, -20), Pair(19, 1), Pair(10, 4),
        Pair(-30, 11), Pair(-22, 22), Pair(-15, -11), Pair(22, -28), Pair(26, -22), Pair(10, -19), Pair(8, -5), Pair(3, -22),
        Pair(-41, 2), Pair(-27, 9), Pair(-10, -17), Pair(-10, -16), Pair(-8, -9), Pair(-5, -17), Pair(5, -17), Pair(-27, -16),
        Pair(-34, 9), Pair(-14, 16), Pair(-13, 0), Pair(-16, -6), Pair(-8, 15), Pair(20, -11), Pair(12, -7), Pair(-22, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-122, -53), Pair(-30, -21), Pair(-107, 63), Pair(-102, 0), Pair(139, -11), Pair(-177, 71), Pair(-224, 29), Pair(-139, -56),
        Pair(-30, 11), Pair(-42, 45), Pair(-10, 50), Pair(31, 7), Pair(4, 12), Pair(39, 13), Pair(-12, 26), Pair(-54, 3),
        Pair(-37, 39), Pair(37, 20), Pair(-27, 67), Pair(22, 46), Pair(-23, 59), Pair(24, 24), Pair(-11, 24), Pair(34, -19),
        Pair(8, 18), Pair(-16, 43), Pair(24, 56), Pair(21, 55), Pair(34, 57), Pair(55, 47), Pair(32, 47), Pair(35, 32),
        Pair(-2, 29), Pair(-7, 46), Pair(17, 58), Pair(39, 42), Pair(25, 54), Pair(37, 53), Pair(39, 23), Pair(16, 53),
        Pair(-40, 25), Pair(-3, 29), Pair(8, 25), Pair(-13, 52), Pair(11, 52), Pair(7, 33), Pair(29, 21), Pair(-16, 24),
        Pair(-63, 25), Pair(-29, 23), Pair(-10, 14), Pair(-2, 37), Pair(-5, 29), Pair(-9, 66), Pair(17, -23), Pair(-42, 70),
        Pair(-101, 76), Pair(-41, 56), Pair(-23, 31), Pair(-34, 66), Pair(-11, 9), Pair(0, 30), Pair(-22, 36), Pair(-128, 84)
      },
      { // Piece 2
        Pair(1, 53), Pair(-143, 85), Pair(-76, 37), Pair(-200, 66), Pair(-93, 38), Pair(-156, 61), Pair(-105, 30), Pair(-82, 19),
        Pair(2, -1), Pair(-25, 16), Pair(-14, 26), Pair(-82, 17), Pair(-58, 57), Pair(-57, 29), Pair(-47, 59), Pair(-43, 17),
        Pair(-35, 25), Pair(-9, 26), Pair(2, 11), Pair(30, -4), Pair(99, -30), Pair(8, 39), Pair(30, 18), Pair(-8, 48),
        Pair(-42, 32), Pair(3, 9), Pair(3, 12), Pair(9, 24), Pair(18, 15), Pair(43, 26), Pair(3, 14), Pair(-18, 39),
        Pair(-37, 19), Pair(-42, 26), Pair(-6, 19), Pair(19, 26), Pair(-4, 20), Pair(-8, 33), Pair(10, 24), Pair(18, 24),
        Pair(-19, 25), Pair(18, 13), Pair(21, 9), Pair(15, 38), Pair(11, 35), Pair(25, 10), Pair(34, 13), Pair(6, -5),
        Pair(-22, 11), Pair(7, 8), Pair(13, 3), Pair(5, 12), Pair(9, 18), Pair(-27, 37), Pair(28, 1), Pair(10, 3),
        Pair(20, -23), Pair(52, -6), Pair(1, 31), Pair(-39, 49), Pair(-39, 30), Pair(-26, 60), Pair(91, -79), Pair(-37, 26)
      },
      { // Piece 3
        Pair(21, 57), Pair(-70, 122), Pair(44, 68), Pair(70, 92), Pair(-20, 47), Pair(-64, 100), Pair(22, 88), Pair(-31, 134),
        Pair(37, 49), Pair(40, 54), Pair(22, 43), Pair(66, 28), Pair(129, 1), Pair(-12, 72), Pair(23, 44), Pair(28, 43),
        Pair(2, 46), Pair(20, 30), Pair(-12, 63), Pair(-16, 35), Pair(48, 6), Pair(-1, 27), Pair(65, 36), Pair(27, 23),
        Pair(-33, 66), Pair(37, 15), Pair(22, 22), Pair(-11, 36), Pair(12, 16), Pair(29, 32), Pair(3, 39), Pair(-38, 78),
        Pair(-25, 36), Pair(-59, 58), Pair(-30, 22), Pair(-30, 60), Pair(-31, 39), Pair(-66, 82), Pair(-32, 51), Pair(-72, 56),
        Pair(-33, 25), Pair(-45, 31), Pair(-9, 32), Pair(-14, 19), Pair(-22, 25), Pair(-1, 23), Pair(-18, 29), Pair(-68, 58),
        Pair(-30, 8), Pair(-19, 9), Pair(-28, 25), Pair(-25, 19), Pair(11, -7), Pair(-9, 20), Pair(-39, 28), Pair(-19, -8),
        Pair(-47, 27), Pair(-30, 13), Pair(-26, 22), Pair(-29, 12), Pair(-6, -5), Pair(-16, 9), Pair(-36, 22), Pair(-40, 18)
      },
      { // Piece 4
        Pair(27, 18), Pair(31, 31), Pair(-23, 45), Pair(80, 80), Pair(62, 132), Pair(130, 31), Pair(87, 77), Pair(8, 108),
        Pair(49, 24), Pair(49, 5), Pair(-2, 91), Pair(62, 45), Pair(-68, 146), Pair(-3, 56), Pair(57, -2), Pair(61, 71),
        Pair(14, 12), Pair(-13, 75), Pair(60, 35), Pair(3, 79), Pair(34, 86), Pair(42, 75), Pair(73, 37), Pair(22, 37),
        Pair(61, -5), Pair(24, 83), Pair(75, 65), Pair(10, 112), Pair(24, 91), Pair(41, 125), Pair(49, 76), Pair(54, 33),
        Pair(20, 35), Pair(-9, 154), Pair(40, 32), Pair(30, 68), Pair(23, 91), Pair(45, 58), Pair(8, 95), Pair(1, 72),
        Pair(8, 70), Pair(12, 58), Pair(15, 67), Pair(16, 71), Pair(18, 87), Pair(9, 65), Pair(28, 51), Pair(3, 23),
        Pair(6, -12), Pair(-14, 12), Pair(7, 76), Pair(19, 40), Pair(1, 74), Pair(16, 75), Pair(15, 15), Pair(38, 36),
        Pair(-24, 105), Pair(-44, 51), Pair(-25, 40), Pair(-6, 25), Pair(11, -21), Pair(-28, 77), Pair(19, 65), Pair(13, 7)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(44, -55), Pair(32, -4), Pair(17, -5), Pair(-15, 18), Pair(-12, 14), Pair(-4, 3), Pair(9, -13), Pair(34, -47),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(52, -25), Pair(12, 0), Pair(32, -46), Pair(53, -97), Pair(-16, -87), Pair(69, -101), Pair(-56, -13), Pair(68, -37),
        Pair(-19, 45), Pair(-10, 54), Pair(29, 15), Pair(57, -36), Pair(34, -50), Pair(89, -46), Pair(48, 6), Pair(-19, 34),
        Pair(-18, 33), Pair(-18, 30), Pair(-18, 9), Pair(-1, -15), Pair(23, -15), Pair(19, -10), Pair(-9, 24), Pair(-11, 15),
        Pair(-36, 16), Pair(-23, 27), Pair(-14, 2), Pair(-3, -8), Pair(10, -11), Pair(7, -9), Pair(-10, 12), Pair(-22, 0),
        Pair(-48, 15), Pair(-36, 23), Pair(-32, 7), Pair(-13, 0), Pair(0, -6), Pair(-8, -8), Pair(-12, 5), Pair(-29, -6),
        Pair(-37, 13), Pair(-19, 22), Pair(-13, 3), Pair(-12, 0), Pair(10, -6), Pair(27, -5), Pair(18, 4), Pair(-38, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-130, -27), Pair(-101, 79), Pair(-97, 20), Pair(-14, 9), Pair(114, -29), Pair(103, -39), Pair(36, -11), Pair(-159, -52),
        Pair(-20, 21), Pair(-57, 45), Pair(-20, 46), Pair(44, 21), Pair(14, 28), Pair(46, -1), Pair(-75, 41), Pair(-11, 28),
        Pair(-40, 54), Pair(-1, 43), Pair(19, 44), Pair(30, 31), Pair(0, 49), Pair(52, 6), Pair(66, -8), Pair(62, -6),
        Pair(-37, 56), Pair(17, 42), Pair(55, 46), Pair(70, 31), Pair(56, 42), Pair(85, 34), Pair(47, 46), Pair(79, -1),
        Pair(-17, 56), Pair(43, 46), Pair(34, 61), Pair(70, 42), Pair(84, 42), Pair(85, 32), Pair(65, 26), Pair(29, 40),
        Pair(-62, 54), Pair(-25, 49), Pair(4, 53), Pair(13, 66), Pair(53, 52), Pair(31, 28), Pair(28, 16), Pair(-3, 36),
        Pair(-53, 29), Pair(-55, 47), Pair(-10, 54), Pair(2, 44), Pair(21, 35), Pair(-1, 55), Pair(-5, 29), Pair(-21, 40),
        Pair(-186, 80), Pair(-40, 40), Pair(-15, 22), Pair(-4, 55), Pair(2, 42), Pair(0, 37), Pair(0, 38), Pair(-101, 87)
      },
      { // Piece 2
        Pair(-71, 41), Pair(-33, 42), Pair(-97, 54), Pair(2, -12), Pair(-39, 7), Pair(-104, 35), Pair(-46, 20), Pair(-85, 55),
        Pair(-84, 29), Pair(8, 25), Pair(12, 6), Pair(22, 14), Pair(-50, 41), Pair(-4, 20), Pair(-23, 48), Pair(-24, 37),
        Pair(-53, 45), Pair(18, 21), Pair(27, 7), Pair(-11, 19), Pair(34, 12), Pair(15, 22), Pair(-16, 29), Pair(31, 8),
        Pair(5, 23), Pair(11, 26), Pair(29, 28), Pair(43, 32), Pair(62, 20), Pair(59, 13), Pair(29, 18), Pair(10, 12),
        Pair(-4, 24), Pair(-6, 37), Pair(-1, 17), Pair(27, 28), Pair(48, 8), Pair(21, 22), Pair(-2, 22), Pair(17, 17),
        Pair(-43, 46), Pair(-2, 32), Pair(16, 31), Pair(14, 29), Pair(17, 35), Pair(17, 19), Pair(29, 20), Pair(-1, -1),
        Pair(-36, 21), Pair(-2, 9), Pair(8, 9), Pair(-3, 24), Pair(16, 16), Pair(15, 21), Pair(30, 4), Pair(-18, 11),
        Pair(-35, 34), Pair(10, 13), Pair(5, 25), Pair(3, 30), Pair(-4, 39), Pair(-8, 36), Pair(29, 10), Pair(-45, 3)
      },
      { // Piece 3
        Pair(-32, 56), Pair(-12, 64), Pair(-25, 64), Pair(-5, 61), Pair(-2, 41), Pair(62, 25), Pair(-14, 73), Pair(-9, 61),
        Pair(-10, 54), Pair(-5, 72), Pair(30, 51), Pair(85, 42), Pair(38, 41), Pair(77, 25), Pair(-25, 74), Pair(-71, 89),
        Pair(-16, 55), Pair(14, 53), Pair(7, 51), Pair(31, 32), Pair(48, 21), Pair(66, 29), Pair(52, 42), Pair(-17, 40),
        Pair(-18, 59), Pair(29, 49), Pair(18, 57), Pair(21, 39), Pair(18, 33), Pair(71, 11), Pair(46, 29), Pair(-44, 37),
        Pair(-61, 57), Pair(-29, 48), Pair(-35, 49), Pair(-6, 41), Pair(-16, 41), Pair(-3, 36), Pair(-27, 35), Pair(-9, 36),
        Pair(-64, 53), Pair(-40, 49), Pair(-18, 34), Pair(-10, 35), Pair(3, 38), Pair(18, 14), Pair(2, 15), Pair(-50, 27),
        Pair(-27, 24), Pair(-32, 37), Pair(-17, 37), Pair(2, 26), Pair(-14, 26), Pair(-1, 16), Pair(-26, 26), Pair(-58, 19),
        Pair(-46, 37), Pair(-39, 36), Pair(-33, 36), Pair(-17, 22), Pair(-19, 20), Pair(-17, 14), Pair(-17, 21), Pair(-55, 35)
      },
      { // Piece 4
        Pair(-12, 81), Pair(-12, 51), Pair(30, 66), Pair(43, 56), Pair(80, 35), Pair(78, 39), Pair(125, 9), Pair(113, 5),
        Pair(38, 58), Pair(-4, 109), Pair(-12, 115), Pair(-27, 103), Pair(97, 45), Pair(21, 68), Pair(16, 174), Pair(85, 73),
        Pair(4, 63), Pair(74, 42), Pair(62, 79), Pair(77, 60), Pair(46, 108), Pair(83, 71), Pair(69, 51), Pair(124, 48),
        Pair(-2, 64), Pair(31, 82), Pair(47, 76), Pair(22, 91), Pair(67, 69), Pair(82, 72), Pair(98, 48), Pair(41, 74),
        Pair(-6, 83), Pair(2, 117), Pair(1, 130), Pair(27, 109), Pair(66, 69), Pair(35, 78), Pair(42, 70), Pair(32, 83),
        Pair(15, 52), Pair(14, 86), Pair(17, 87), Pair(24, 99), Pair(19, 95), Pair(36, 90), Pair(58, 57), Pair(-8, 112),
        Pair(10, 54), Pair(28, 44), Pair(16, 70), Pair(30, 58), Pair(27, 67), Pair(44, 34), Pair(9, 60), Pair(34, -16),
        Pair(20, 2), Pair(-25, 71), Pair(-17, 104), Pair(8, 70), Pair(-3, 71), Pair(-5, 29), Pair(38, 36), Pair(-18, 54)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(54, -44), Pair(-1, 6), Pair(-25, 20), Pair(-23, 31), Pair(-39, 35), Pair(-24, 24), Pair(0, 3), Pair(14, -29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(43, -20), Pair(23, -45), Pair(-16, -21), Pair(22, -32), Pair(-44, -70), Pair(60, -57), Pair(69, 44), Pair(47, -20),
        Pair(5, 20), Pair(16, 34), Pair(24, -13), Pair(104, -60), Pair(81, -44), Pair(35, -28), Pair(66, 6), Pair(55, 13),
        Pair(-48, 23), Pair(-35, 21), Pair(-35, -3), Pair(-7, -17), Pair(12, -13), Pair(21, -22), Pair(21, 9), Pair(-20, 10),
        Pair(-65, 11), Pair(-44, 23), Pair(-23, 2), Pair(1, 1), Pair(-11, 1), Pair(-8, -5), Pair(1, 12), Pair(-30, 1),
        Pair(-75, 9), Pair(-63, 23), Pair(-39, 2), Pair(-24, -1), Pair(-28, 2), Pair(-12, -3), Pair(-27, 2), Pair(-56, 0),
        Pair(-74, 15), Pair(-42, 25), Pair(-14, 1), Pair(-39, 5), Pair(-5, -10), Pair(36, -11), Pair(2, 4), Pair(-52, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-147, -63), Pair(-33, -75), Pair(-72, -14), Pair(113, -63), Pair(11, -14), Pair(-62, -7), Pair(-181, -16), Pair(-68, -71),
        Pair(-47, -2), Pair(70, -11), Pair(27, -23), Pair(86, -27), Pair(78, -54), Pair(113, -43), Pair(-57, 3), Pair(-41, -19),
        Pair(-100, -2), Pair(-4, 6), Pair(10, 25), Pair(49, 9), Pair(81, -4), Pair(187, -62), Pair(30, -8), Pair(30, -21),
        Pair(-19, 22), Pair(-2, 29), Pair(46, 23), Pair(123, -6), Pair(105, 12), Pair(120, -10), Pair(121, -14), Pair(57, 12),
        Pair(-19, 34), Pair(42, 11), Pair(32, 35), Pair(95, 12), Pair(107, 8), Pair(93, 14), Pair(103, 6), Pair(6, 28),
        Pair(-8, -4), Pair(-13, 23), Pair(-8, 29), Pair(43, 29), Pair(121, 5), Pair(34, 14), Pair(15, 6), Pair(2, 16),
        Pair(-94, 62), Pair(-11, 10), Pair(13, 18), Pair(46, 3), Pair(-1, 15), Pair(18, 19), Pair(29, -5), Pair(51, 22),
        Pair(-61, 62), Pair(-107, 49), Pair(-27, 28), Pair(-10, 22), Pair(67, 1), Pair(8, 18), Pair(16, 6), Pair(-72, 49)
      },
      { // Piece 2
        Pair(-121, 41), Pair(74, -24), Pair(-97, 16), Pair(-68, -15), Pair(-6, 16), Pair(-33, 29), Pair(19, 1), Pair(-43, -6),
        Pair(-132, 42), Pair(-66, 25), Pair(-18, -10), Pair(48, 2), Pair(63, -7), Pair(-32, 15), Pair(-16, 5), Pair(-45, 18),
        Pair(-71, 26), Pair(112, -24), Pair(23, 4), Pair(11, -7), Pair(26, -16), Pair(36, 3), Pair(-39, 17), Pair(62, -2),
        Pair(80, -3), Pair(45, -6), Pair(21, -5), Pair(48, -24), Pair(43, -16), Pair(79, -26), Pair(20, -6), Pair(-9, 3),
        Pair(16, 0), Pair(26, 5), Pair(-18, 12), Pair(88, -8), Pair(16, -3), Pair(0, 24), Pair(-8, 24), Pair(-19, -16),
        Pair(-33, 12), Pair(41, -10), Pair(7, 1), Pair(17, 6), Pair(31, 9), Pair(-13, 16), Pair(1, 11), Pair(-31, 13),
        Pair(-14, 5), Pair(-49, -1), Pair(-4, 13), Pair(-46, 15), Pair(-4, 6), Pair(-5, 8), Pair(39, -23), Pair(-15, 3),
        Pair(42, 6), Pair(8, -2), Pair(-22, 6), Pair(-19, 14), Pair(-18, 15), Pair(-36, 16), Pair(-44, 18), Pair(-101, 10)
      },
      { // Piece 3
        Pair(-71, 29), Pair(-64, 42), Pair(-83, 47), Pair(5, 23), Pair(-56, 38), Pair(-16, 33), Pair(-1, 26), Pair(-41, 25),
        Pair(-39, 10), Pair(4, 13), Pair(4, 11), Pair(20, 6), Pair(0, 6), Pair(89, -6), Pair(-34, 21), Pair(-54, 15),
        Pair(-36, 21), Pair(-47, 36), Pair(-2, 17), Pair(40, -1), Pair(-13, 15), Pair(-60, 3), Pair(-49, 15), Pair(-44, 28),
        Pair(-17, 19), Pair(-7, 22), Pair(26, 12), Pair(63, -3), Pair(39, -16), Pair(6, 3), Pair(4, 9), Pair(-41, 14),
        Pair(-99, 31), Pair(-68, 36), Pair(8, 4), Pair(-51, 19), Pair(24, -14), Pair(84, -25), Pair(13, -4), Pair(-60, 8),
        Pair(-90, 19), Pair(-47, 10), Pair(-27, -2), Pair(-37, 7), Pair(-65, 8), Pair(-35, -5), Pair(-22, -19), Pair(-135, 33),
        Pair(-47, -9), Pair(-45, 9), Pair(-33, -4), Pair(-72, 17), Pair(-27, -24), Pair(33, -40), Pair(-32, 3), Pair(-99, -18),
        Pair(-81, 9), Pair(-90, 17), Pair(-78, 21), Pair(-74, 12), Pair(-64, -1), Pair(-43, -9), Pair(-48, -5), Pair(-78, 11)
      },
      { // Piece 4
        Pair(26, 10), Pair(117, -30), Pair(143, -14), Pair(164, -61), Pair(79, 32), Pair(90, 25), Pair(226, -129), Pair(205, -62),
        Pair(94, -64), Pair(-15, 7), Pair(88, -45), Pair(10, 25), Pair(90, -7), Pair(94, -44), Pair(137, -72), Pair(148, -46),
        Pair(-14, 27), Pair(71, 5), Pair(-21, 76), Pair(47, 30), Pair(24, 14), Pair(99, -14), Pair(142, -9), Pair(83, -42),
        Pair(88, -57), Pair(28, -15), Pair(27, 5), Pair(60, 41), Pair(42, -3), Pair(108, -40), Pair(137, -17), Pair(199, -158),
        Pair(75, -19), Pair(-9, -14), Pair(-13, 25), Pair(67, 8), Pair(3, 6), Pair(69, -53), Pair(113, -71), Pair(64, -38),
        Pair(60, -94), Pair(-29, 14), Pair(34, -11), Pair(2, 17), Pair(89, -59), Pair(13, -12), Pair(38, -80), Pair(94, -17),
        Pair(-22, -65), Pair(-4, -10), Pair(3, -27), Pair(30, -14), Pair(-37, -3), Pair(62, -37), Pair(51, -96), Pair(-13, -62),
        Pair(-96, -10), Pair(-13, -23), Pair(16, -17), Pair(-24, 28), Pair(9, -31), Pair(-36, 38), Pair(27, -133), Pair(22, -12)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(68, -48), Pair(41, -10), Pair(7, 11), Pair(0, 17), Pair(-7, 19), Pair(-3, 13), Pair(14, -3), Pair(41, -33),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(3, -5), Pair(25, 4), Pair(-40, 8), Pair(12, -38), Pair(-40, -18), Pair(-82, 30), Pair(93, 25), Pair(-13, 37),
        Pair(-28, 23), Pair(-31, 33), Pair(-104, 47), Pair(-89, 26), Pair(-53, 24), Pair(47, 21), Pair(-28, 66), Pair(7, 66),
        Pair(-50, 11), Pair(-83, 18), Pair(-19, 1), Pair(-2, -14), Pair(48, -24), Pair(-35, -16), Pair(-10, 13), Pair(-4, 8),
        Pair(-88, 6), Pair(-39, 11), Pair(-58, -5), Pair(-6, -7), Pair(-27, -13), Pair(0, -21), Pair(0, 4), Pair(-80, 6),
        Pair(-104, 4), Pair(-70, 17), Pair(-67, 8), Pair(-31, 7), Pair(-28, 10), Pair(-7, 0), Pair(-17, 6), Pair(-48, -1),
        Pair(-117, 17), Pair(-64, 24), Pair(-12, 1), Pair(12, 4), Pair(85, -27), Pair(37, -14), Pair(-17, 6), Pair(-104, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(33, -94), Pair(-74, -74), Pair(-94, 4), Pair(19, -41), Pair(20, -43), Pair(-68, -71), Pair(54, 2), Pair(-6, -88),
        Pair(-61, -15), Pair(-78, -12), Pair(83, -39), Pair(-35, 0), Pair(30, -9), Pair(26, -27), Pair(24, -24), Pair(-22, -12),
        Pair(-49, -11), Pair(-51, -22), Pair(-21, -9), Pair(33, -28), Pair(43, -34), Pair(102, -78), Pair(44, -70), Pair(-48, -23),
        Pair(-59, -16), Pair(26, 9), Pair(-43, 9), Pair(62, -30), Pair(96, -27), Pair(107, -21), Pair(41, -65), Pair(-67, 6),
        Pair(24, -20), Pair(26, -18), Pair(92, -21), Pair(97, -37), Pair(91, -44), Pair(182, -44), Pair(148, -27), Pair(47, -54),
        Pair(-17, -9), Pair(8, -23), Pair(45, -25), Pair(89, -19), Pair(49, -12), Pair(-45, -9), Pair(-1, -3), Pair(-9, -21),
        Pair(-61, -46), Pair(-37, 6), Pair(0, 3), Pair(24, -33), Pair(-10, -22), Pair(-7, -30), Pair(-122, -12), Pair(53, -14),
        Pair(-27, -53), Pair(-152, -17), Pair(-37, -7), Pair(-17, -13), Pair(-57, 0), Pair(6, -6), Pair(-34, 32), Pair(-92, -32)
      },
      { // Piece 2
        Pair(-16, -1), Pair(-53, -33), Pair(-8, -49), Pair(-96, 13), Pair(-100, 1), Pair(-59, -32), Pair(-62, -11), Pair(-24, 13),
        Pair(-162, -1), Pair(-57, 2), Pair(-112, -16), Pair(-82, 10), Pair(-73, -6), Pair(34, -26), Pair(-25, -41), Pair(-13, -41),
        Pair(10, -7), Pair(-100, 12), Pair(-9, -13), Pair(-75, -26), Pair(44, -43), Pair(0, -19), Pair(-45, -22), Pair(52, -29),
        Pair(-102, 1), Pair(-37, 5), Pair(34, -8), Pair(63, -48), Pair(82, -17), Pair(-45, -13), Pair(119, -42), Pair(-35, -1),
        Pair(8, -9), Pair(-23, -24), Pair(91, -44), Pair(56, -40), Pair(12, -45), Pair(-11, -38), Pair(35, -57), Pair(-17, -11),
        Pair(-7, -9), Pair(-45, -8), Pair(7, -33), Pair(-20, -3), Pair(65, -24), Pair(59, -11), Pair(110, -44), Pair(-63, -8),
        Pair(-70, -35), Pair(-63, -25), Pair(22, -17), Pair(-39, -21), Pair(-14, -23), Pair(-60, -32), Pair(-55, -1), Pair(-61, -33),
        Pair(-110, 12), Pair(-118, 28), Pair(28, -38), Pair(-26, -17), Pair(-13, -35), Pair(10, -29), Pair(-69, -30), Pair(-114, 4)
      },
      { // Piece 3
        Pair(-98, -20), Pair(-127, 1), Pair(-105, 1), Pair(-30, -30), Pair(-82, -16), Pair(-26, -5), Pair(-52, -7), Pair(-28, -35),
        Pair(-76, -38), Pair(36, -51), Pair(-56, -29), Pair(-45, -21), Pair(-12, -28), Pair(21, -46), Pair(28, -62), Pair(44, -71),
        Pair(-29, -45), Pair(-48, -35), Pair(18, -68), Pair(39, -60), Pair(68, -63), Pair(96, -73), Pair(108, -82), Pair(-4, -58),
        Pair(-55, -23), Pair(23, -28), Pair(-47, -29), Pair(62, -80), Pair(17, -49), Pair(32, -89), Pair(18, -59), Pair(-33, -48),
        Pair(-68, -24), Pair(-64, -15), Pair(-92, 0), Pair(-3, -37), Pair(-43, -36), Pair(51, -49), Pair(1, -35), Pair(-89, -29),
        Pair(-112, -32), Pair(-14, -38), Pair(-106, -36), Pair(-74, -37), Pair(-107, -25), Pair(20, -61), Pair(5, -46), Pair(-138, -29),
        Pair(-103, -45), Pair(-4, -72), Pair(-86, -43), Pair(-119, -34), Pair(-15, -65), Pair(-116, -35), Pair(-20, -41), Pair(-93, -58),
        Pair(-120, -28), Pair(-16, -64), Pair(-68, -32), Pair(-52, -31), Pair(-12, -55), Pair(-43, -58), Pair(-131, -14), Pair(-176, -17)
      },
      { // Piece 4
        Pair(40, -124), Pair(-61, -66), Pair(40, -85), Pair(19, -107), Pair(52, -59), Pair(62, -94), Pair(46, -175), Pair(54, -33),
        Pair(64, -135), Pair(16, -29), Pair(170, -124), Pair(88, -96), Pair(132, -137), Pair(15, -65), Pair(76, -115), Pair(-21, -36),
        Pair(73, -196), Pair(6, -104), Pair(88, -137), Pair(68, -99), Pair(119, -197), Pair(5, -101), Pair(93, -148), Pair(89, -207),
        Pair(-19, -65), Pair(-19, 13), Pair(33, -117), Pair(116, -114), Pair(2, -75), Pair(15, -102), Pair(43, -95), Pair(117, -49),
        Pair(-75, -48), Pair(-21, -28), Pair(65, -53), Pair(20, -92), Pair(91, -105), Pair(0, -102), Pair(96, -136), Pair(-41, -39),
        Pair(-148, -58), Pair(-69, -44), Pair(95, -135), Pair(41, -141), Pair(27, -76), Pair(28, -54), Pair(-38, -136), Pair(38, -122),
        Pair(-97, -107), Pair(2, -107), Pair(-67, -75), Pair(18, -132), Pair(32, -101), Pair(-23, -78), Pair(-1, -168), Pair(-31, -76),
        Pair(3, -87), Pair(-34, -44), Pair(14, -127), Pair(-9, -81), Pair(-11, -51), Pair(-11, -34), Pair(-6, 10), Pair(20, -91)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(73, -40), Pair(80, -12), Pair(12, 12), Pair(15, 14), Pair(20, 20), Pair(5, 19), Pair(32, 1), Pair(45, -28),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(76, -51), Pair(59, -17), Pair(154, -19), Pair(56, -30), Pair(93, -33), Pair(20, 9), Pair(107, -29), Pair(124, -28),
        Pair(-101, 53), Pair(-40, 36), Pair(-146, 77), Pair(-110, 70), Pair(-23, 81), Pair(-80, 62), Pair(-73, 70), Pair(-20, 59),
        Pair(-111, 12), Pair(-120, 35), Pair(-126, 13), Pair(-135, 11), Pair(-120, 11), Pair(-46, -7), Pair(-66, 14), Pair(-54, 4),
        Pair(-92, 3), Pair(-93, 15), Pair(-33, -7), Pair(-35, -12), Pair(-57, -8), Pair(-11, -28), Pair(-33, -10), Pair(-68, -7),
        Pair(-124, 6), Pair(-102, 11), Pair(-74, 2), Pair(-98, 10), Pair(-65, 13), Pair(-19, -7), Pair(-81, 5), Pair(-99, -3),
        Pair(-141, 29), Pair(-90, 28), Pair(10, -6), Pair(-55, -1), Pair(52, -24), Pair(39, -7), Pair(13, 0), Pair(-130, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-75, -130), Pair(-40, -32), Pair(-116, -30), Pair(-55, -78), Pair(-83, -98), Pair(-190, -64), Pair(-5, -106), Pair(-21, -131),
        Pair(-136, -18), Pair(-13, -80), Pair(-74, -28), Pair(-83, -27), Pair(-6, -69), Pair(-24, -78), Pair(-57, -28), Pair(-86, -82),
        Pair(-131, -39), Pair(-86, -36), Pair(55, -65), Pair(40, -55), Pair(-8, -42), Pair(-6, -69), Pair(-73, -83), Pair(7, -50),
        Pair(-85, -54), Pair(-34, -41), Pair(26, -50), Pair(16, -52), Pair(131, -76), Pair(143, -72), Pair(-8, -67), Pair(116, -98),
        Pair(24, -53), Pair(-60, -21), Pair(-17, -34), Pair(26, -43), Pair(8, -38), Pair(54, -59), Pair(44, -35), Pair(45, -35),
        Pair(-41, -94), Pair(-6, -49), Pair(3, -46), Pair(49, -36), Pair(95, -42), Pair(58, -59), Pair(169, -71), Pair(-11, -38),
        Pair(-60, -57), Pair(3, -50), Pair(113, -72), Pair(66, -47), Pair(9, -61), Pair(77, -82), Pair(-98, -6), Pair(50, -74),
        Pair(34, -60), Pair(-51, -77), Pair(-59, -49), Pair(10, -43), Pair(84, -44), Pair(73, -70), Pair(26, -63), Pair(38, -82)
      },
      { // Piece 2
        Pair(-71, 6), Pair(-156, -19), Pair(-80, -26), Pair(-82, -30), Pair(-120, -16), Pair(-203, -16), Pair(-36, -28), Pair(-90, -43),
        Pair(-33, -57), Pair(-83, -22), Pair(-137, 0), Pair(-105, -28), Pair(-175, -23), Pair(-145, -21), Pair(-184, -17), Pair(-87, -5),
        Pair(-150, -34), Pair(-49, -30), Pair(-147, 16), Pair(-161, -11), Pair(-94, -14), Pair(-128, -31), Pair(-93, 14), Pair(-130, 1),
        Pair(-28, -66), Pair(-57, -35), Pair(-65, -3), Pair(-50, -22), Pair(-63, -25), Pair(-135, 24), Pair(-133, -7), Pair(-56, -14),
        Pair(-40, -29), Pair(-111, -14), Pair(-30, -27), Pair(17, -56), Pair(-16, -21), Pair(53, -40), Pair(11, -37), Pair(103, -59),
        Pair(-84, -12), Pair(-70, -30), Pair(-116, -32), Pair(-1, -46), Pair(37, -63), Pair(-70, -40), Pair(-105, -53), Pair(-93, -41),
        Pair(-33, -8), Pair(-63, -53), Pair(-41, -34), Pair(22, -61), Pair(64, -74), Pair(-12, -47), Pair(-50, -33), Pair(8, -72),
        Pair(-99, -34), Pair(-306, 46), Pair(-111, -22), Pair(-14, -19), Pair(-22, -46), Pair(-91, -26), Pair(-107, -14), Pair(-87, -72)
      },
      { // Piece 3
        Pair(-49, -80), Pair(-124, -33), Pair(-12, -57), Pair(-69, -48), Pair(-27, -67), Pair(-4, -61), Pair(-35, -54), Pair(-55, -45),
        Pair(-47, -84), Pair(-22, -73), Pair(-39, -48), Pair(-13, -68), Pair(-12, -86), Pair(-71, -50), Pair(-37, -52), Pair(12, -74),
        Pair(19, -99), Pair(21, -78), Pair(-17, -65), Pair(-45, -76), Pair(64, -98), Pair(15, -82), Pair(9, -85), Pair(20, -95),
        Pair(-4, -74), Pair(59, -86), Pair(-75, -62), Pair(13, -77), Pair(9, -88), Pair(77, -89), Pair(57, -79), Pair(-52, -67),
        Pair(23, -91), Pair(-18, -82), Pair(42, -107), Pair(6, -98), Pair(42, -94), Pair(76, -90), Pair(24, -128), Pair(-41, -76),
        Pair(-87, -69), Pair(-36, -56), Pair(-17, -98), Pair(-55, -82), Pair(26, -91), Pair(111, -116), Pair(44, -74), Pair(-77, -59),
        Pair(-24, -103), Pair(-51, -62), Pair(34, -119), Pair(-53, -74), Pair(101, -138), Pair(164, -139), Pair(61, -108), Pair(-32, -85),
        Pair(69, -121), Pair(85, -122), Pair(42, -98), Pair(67, -103), Pair(53, -143), Pair(22, -112), Pair(47, -112), Pair(-40, -93)
      },
      { // Piece 4
        Pair(-35, -270), Pair(-138, -172), Pair(-5, -179), Pair(51, -155), Pair(-53, -124), Pair(-123, -145), Pair(-176, -144), Pair(-159, -141),
        Pair(-14, -172), Pair(-29, -255), Pair(33, -243), Pair(-40, -126), Pair(-7, -123), Pair(-51, -143), Pair(109, -247), Pair(84, -190),
        Pair(17, -239), Pair(-98, -161), Pair(-35, -188), Pair(59, -206), Pair(-3, -114), Pair(111, -323), Pair(-12, -197), Pair(-5, -202),
        Pair(-20, -154), Pair(39, -235), Pair(-15, -185), Pair(-4, -189), Pair(107, -187), Pair(-15, -206), Pair(-73, -195), Pair(37, -228),
        Pair(-27, -232), Pair(-18, -213), Pair(-108, -156), Pair(-43, -78), Pair(79, -152), Pair(-49, -114), Pair(-47, -157), Pair(-49, -120),
        Pair(-102, -192), Pair(-75, -75), Pair(8, -156), Pair(-29, -133), Pair(3, -115), Pair(16, -196), Pair(-80, -124), Pair(-5, -134),
        Pair(-89, -240), Pair(-50, -266), Pair(-18, -187), Pair(33, -212), Pair(47, -242), Pair(-123, -149), Pair(-25, -138), Pair(-86, -226),
        Pair(-1, -185), Pair(-123, -239), Pair(-40, -248), Pair(-60, -157), Pair(2, -193), Pair(-69, -175), Pair(-16, -124), Pair(-28, -160)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(21, -36), Pair(37, -11), Pair(13, 8), Pair(-20, 7), Pair(-7, 14), Pair(-21, 16), Pair(39, -5), Pair(38, -37),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-71, 8), Pair(69, -4), Pair(9, 49), Pair(45, -77), Pair(-97, 8), Pair(-14, 52), Pair(-13, 13), Pair(8, -14),
        Pair(-58, 36), Pair(-55, 128), Pair(-73, 89), Pair(28, 19), Pair(4, 83), Pair(-87, 59), Pair(24, 136), Pair(-25, 73),
        Pair(-109, 33), Pair(56, 45), Pair(-51, 59), Pair(-131, 35), Pair(-22, -4), Pair(-2, -13), Pair(-116, 73), Pair(-137, 37),
        Pair(-167, 36), Pair(48, -10), Pair(20, -40), Pair(-143, 21), Pair(-46, -18), Pair(159, -44), Pair(-86, -4), Pair(-84, 6),
        Pair(-57, -13), Pair(-149, 22), Pair(-19, -33), Pair(-92, -12), Pair(-1, -7), Pair(-52, -17), Pair(-38, -5), Pair(-79, -2),
        Pair(-109, 30), Pair(37, 32), Pair(73, 0), Pair(9, 56), Pair(-42, -12), Pair(28, 18), Pair(82, -7), Pair(-124, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-35, -102), Pair(-62, -155), Pair(-24, -93), Pair(-71, -180), Pair(0, -58), Pair(-21, 10), Pair(-18, 26), Pair(-59, -145),
        Pair(-34, -114), Pair(-38, -29), Pair(-21, -60), Pair(40, 71), Pair(35, -91), Pair(-60, -130), Pair(-35, -63), Pair(7, -103),
        Pair(-34, -19), Pair(-15, -124), Pair(-54, -37), Pair(-44, -7), Pair(13, -56), Pair(-61, -97), Pair(-8, -34), Pair(-42, -86),
        Pair(-36, -142), Pair(44, -96), Pair(-23, -59), Pair(29, -27), Pair(110, -44), Pair(13, -55), Pair(-12, -46), Pair(-10, -28),
        Pair(14, 10), Pair(-56, -16), Pair(57, 9), Pair(13, -41), Pair(200, -52), Pair(53, -25), Pair(18, -59), Pair(-23, 69),
        Pair(-25, 31), Pair(-27, -137), Pair(-1, -19), Pair(78, -7), Pair(-91, 1), Pair(33, -13), Pair(57, -12), Pair(19, 10),
        Pair(-25, -111), Pair(-36, -177), Pair(-21, 36), Pair(-57, -18), Pair(1, -19), Pair(152, -37), Pair(-44, -92), Pair(86, -24),
        Pair(11, 8), Pair(21, -54), Pair(23, -67), Pair(-3, -32), Pair(-17, -53), Pair(63, -73), Pair(10, -38), Pair(-9, 10)
      },
      { // Piece 2
        Pair(6, 18), Pair(-5, 30), Pair(-1, 86), Pair(-5, -6), Pair(10, 5), Pair(18, 21), Pair(38, -13), Pair(14, 16),
        Pair(-26, -1), Pair(-59, -36), Pair(-42, 14), Pair(-51, 19), Pair(43, 29), Pair(-10, -81), Pair(46, -7), Pair(58, 60),
        Pair(-32, -30), Pair(-4, -46), Pair(-43, 0), Pair(-38, -17), Pair(-9, 7), Pair(-93, 18), Pair(-53, 13), Pair(8, 68),
        Pair(1, -33), Pair(-35, -27), Pair(-135, -26), Pair(-79, 17), Pair(-45, 7), Pair(-85, 70), Pair(-60, -19), Pair(-3, 7),
        Pair(-66, -21), Pair(0, 53), Pair(-63, -33), Pair(-119, 27), Pair(63, 27), Pair(-19, 7), Pair(-7, -8), Pair(8, 53),
        Pair(-48, 34), Pair(-18, 15), Pair(20, -15), Pair(13, 68), Pair(4, -19), Pair(-46, -49), Pair(10, 38), Pair(-38, 6),
        Pair(9, 44), Pair(-65, -45), Pair(-60, -38), Pair(70, 35), Pair(87, -62), Pair(-33, -19), Pair(-18, -122), Pair(-43, 48),
        Pair(-2, 72), Pair(-31, 99), Pair(-52, -36), Pair(-62, -5), Pair(-106, 40), Pair(11, -29), Pair(-37, -6), Pair(-31, 0)
      },
      { // Piece 3
        Pair(-56, -58), Pair(32, -28), Pair(-13, -12), Pair(-22, 10), Pair(-43, -22), Pair(2, -66), Pair(15, -5), Pair(-7, -6),
        Pair(78, -60), Pair(-48, -52), Pair(12, -14), Pair(-26, -18), Pair(-17, -47), Pair(108, -43), Pair(12, 13), Pair(-9, -69),
        Pair(52, -26), Pair(46, -72), Pair(-12, -62), Pair(58, -55), Pair(-17, -23), Pair(-25, -11), Pair(55, -27), Pair(107, -83),
        Pair(23, -25), Pair(-47, 23), Pair(42, -10), Pair(12, -43), Pair(36, -29), Pair(65, -79), Pair(11, -14), Pair(74, -44),
        Pair(-82, -85), Pair(-27, -53), Pair(93, -9), Pair(99, -24), Pair(66, -62), Pair(71, -40), Pair(19, -73), Pair(58, -61),
        Pair(-29, -77), Pair(-9, 2), Pair(48, -129), Pair(85, -100), Pair(85, -52), Pair(61, -92), Pair(19, -40), Pair(69, -92),
        Pair(34, -46), Pair(-55, -60), Pair(84, -102), Pair(-21, -61), Pair(110, -86), Pair(12, 19), Pair(104, 6), Pair(18, -89),
        Pair(39, -4), Pair(47, -83), Pair(-2, -94), Pair(38, -114), Pair(-6, -85), Pair(92, -130), Pair(35, -69), Pair(120, -15)
      },
      { // Piece 4
        Pair(-171, -94), Pair(-37, -85), Pair(-61, -88), Pair(-16, -77), Pair(-106, -145), Pair(-65, -69), Pair(-115, -85), Pair(-50, -97),
        Pair(-43, -71), Pair(-15, -24), Pair(-22, 11), Pair(-47, -103), Pair(-29, -14), Pair(-32, -116), Pair(30, -148), Pair(-29, -71),
        Pair(-10, -67), Pair(-70, -61), Pair(-41, -52), Pair(-64, -77), Pair(11, -82), Pair(-27, -211), Pair(-25, -69), Pair(20, -18),
        Pair(-39, -94), Pair(-49, -69), Pair(60, -48), Pair(60, -113), Pair(12, -61), Pair(-12, -70), Pair(-22, -75), Pair(-38, -83),
        Pair(36, -66), Pair(0, -116), Pair(75, -46), Pair(-20, -48), Pair(4, -11), Pair(20, -93), Pair(-15, -71), Pair(-33, -86),
        Pair(-52, -185), Pair(30, -69), Pair(-1, -65), Pair(-16, -92), Pair(-54, -179), Pair(-29, -113), Pair(-52, -80), Pair(17, 24),
        Pair(-86, -170), Pair(-11, -32), Pair(23, 5), Pair(39, -57), Pair(4, -70), Pair(5, -38), Pair(-50, -74), Pair(-52, -107),
        Pair(19, -63), Pair(-57, -176), Pair(40, -71), Pair(-40, -147), Pair(9, -64), Pair(-7, -82), Pair(13, -63), Pair(-70, -136)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-27, -4), Pair(-19, 36), Pair(-17, 45), Pair(74, 21), Pair(-8, 38), Pair(-107, 57), Pair(-44, 39), Pair(3, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 3
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(41, 18), Pair(7, 51), Pair(-110, 131), Pair(55, 21), Pair(54, -30), Pair(-8, -42), Pair(-93, -106), Pair(-206, -47),
        Pair(28, 45), Pair(-24, 93), Pair(-4, 67), Pair(18, 21), Pair(69, 8), Pair(106, -30), Pair(70, -20), Pair(38, -5),
        Pair(-20, 36), Pair(-23, 41), Pair(-25, 28), Pair(-12, 7), Pair(42, -20), Pair(42, -25), Pair(9, 8), Pair(-10, -3),
        Pair(-43, 19), Pair(-30, 36), Pair(-19, 9), Pair(-4, -6), Pair(17, -15), Pair(19, -13), Pair(-21, 11), Pair(-46, 4),
        Pair(-34, 4), Pair(-36, 16), Pair(-11, -2), Pair(-9, 0), Pair(3, -4), Pair(10, -14), Pair(3, -7), Pair(-47, -11),
        Pair(-33, 14), Pair(-27, 26), Pair(-9, 6), Pair(-46, 29), Pair(-15, 25), Pair(20, -3), Pair(9, 1), Pair(-46, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-378, 45), Pair(-137, -35), Pair(-92, 73), Pair(65, -7), Pair(-82, 63), Pair(114, -93), Pair(-42, 11), Pair(-32, -82),
        Pair(-125, 50), Pair(9, 29), Pair(-79, 44), Pair(-7, 57), Pair(-31, 61), Pair(33, 25), Pair(-56, 104), Pair(-5, -41),
        Pair(-18, 6), Pair(7, 41), Pair(-13, 43), Pair(31, 30), Pair(15, 25), Pair(96, 13), Pair(68, 17), Pair(109, -44),
        Pair(-81, 75), Pair(-26, 37), Pair(44, 22), Pair(64, 19), Pair(70, 42), Pair(95, 27), Pair(82, 20), Pair(73, 5),
        Pair(-32, 27), Pair(-1, 27), Pair(-12, 51), Pair(24, 55), Pair(62, 35), Pair(50, 7), Pair(-20, 19), Pair(42, 17),
        Pair(-56, -1), Pair(-52, 37), Pair(3, 11), Pair(-8, 41), Pair(18, 47), Pair(33, 11), Pair(20, 27), Pair(-47, 9),
        Pair(-151, 51), Pair(-41, 22), Pair(-59, 16), Pair(-9, 30), Pair(-23, 33), Pair(78, -22), Pair(-43, 19), Pair(9, 15),
        Pair(-96, 44), Pair(-69, -12), Pair(-127, 52), Pair(-143, 66), Pair(-10, 28), Pair(-66, 45), Pair(-86, 35), Pair(104, -82)
      },
      { // Piece 2
        Pair(-150, 76), Pair(-88, 60), Pair(-86, -2), Pair(-86, 35), Pair(-101, -23), Pair(-72, -24), Pair(16, 47), Pair(79, 53),
        Pair(-11, 8), Pair(26, 12), Pair(-54, 31), Pair(38, -29), Pair(-63, 34), Pair(59, -35), Pair(-108, 109), Pair(-67, 54),
        Pair(8, 10), Pair(34, -4), Pair(30, 32), Pair(-6, 31), Pair(-13, 49), Pair(77, 54), Pair(-8, 54), Pair(44, 30),
        Pair(-3, 31), Pair(-12, 27), Pair(-4, 25), Pair(20, 13), Pair(65, 2), Pair(37, 30), Pair(24, 17), Pair(-16, 41),
        Pair(-54, 15), Pair(-40, 46), Pair(13, 49), Pair(5, 31), Pair(15, 16), Pair(18, 23), Pair(-33, 28), Pair(-43, 38),
        Pair(-55, 9), Pair(-28, 50), Pair(7, 13), Pair(20, 10), Pair(17, 30), Pair(16, 7), Pair(-14, 23), Pair(-52, 11),
        Pair(59, 22), Pair(-15, 9), Pair(-52, 45), Pair(-43, 47), Pair(-3, 22), Pair(-6, 20), Pair(4, 3), Pair(-61, 32),
        Pair(-35, 42), Pair(-17, 37), Pair(-19, 26), Pair(-8, 24), Pair(26, 20), Pair(-18, 28), Pair(-30, 37), Pair(-72, -4)
      },
      { // Piece 3
        Pair(28, 84), Pair(-47, 132), Pair(-4, 143), Pair(-24, 133), Pair(95, 100), Pair(171, 55), Pair(16, 114), Pair(35, 79),
        Pair(-8, 60), Pair(-22, 79), Pair(-49, 92), Pair(78, 22), Pair(-15, 56), Pair(107, 35), Pair(-10, 80), Pair(51, 31),
        Pair(-54, 73), Pair(-49, 84), Pair(45, 44), Pair(7, 45), Pair(13, 41), Pair(38, 27), Pair(96, 47), Pair(0, 36),
        Pair(-112, 68), Pair(6, 49), Pair(-8, 55), Pair(-4, 51), Pair(-20, 58), Pair(-33, 56), Pair(38, 40), Pair(-18, 19),
        Pair(-101, 77), Pair(-75, 79), Pair(-53, 54), Pair(-46, 67), Pair(-9, 43), Pair(-37, 58), Pair(-55, 56), Pair(-50, 29),
        Pair(-40, 53), Pair(-58, 59), Pair(-48, 55), Pair(-15, 42), Pair(-22, 31), Pair(-10, 24), Pair(-7, 24), Pair(-94, 25),
        Pair(-106, 35), Pair(-38, 41), Pair(-66, 68), Pair(-65, 61), Pair(-40, 41), Pair(-19, 23), Pair(-12, 11), Pair(-99, 27),
        Pair(-62, 35), Pair(-80, 52), Pair(-70, 57), Pair(-47, 46), Pair(-43, 36), Pair(-30, 20), Pair(-20, 6), Pair(-55, 23)
      },
      { // Piece 4
        Pair(-75, 124), Pair(-125, 39), Pair(4, 20), Pair(-19, 83), Pair(-59, 93), Pair(101, 36), Pair(92, 105), Pair(-5, -21),
        Pair(-143, 127), Pair(-121, 80), Pair(-61, 86), Pair(-44, 139), Pair(-54, 109), Pair(105, 2), Pair(-106, 98), Pair(83, 55),
        Pair(-71, 108), Pair(-82, 94), Pair(-34, 80), Pair(-93, 132), Pair(-26, 60), Pair(41, 75), Pair(68, 35), Pair(24, 37),
        Pair(-102, 122), Pair(-48, 75), Pair(-52, 105), Pair(-87, 120), Pair(-36, 127), Pair(18, 47), Pair(31, 62), Pair(-26, 76),
        Pair(-61, 8), Pair(-96, 98), Pair(-50, 124), Pair(-17, 86), Pair(-42, 114), Pair(-1, 67), Pair(18, 25), Pair(5, 33),
        Pair(-155, 108), Pair(-44, 35), Pair(-12, 55), Pair(-32, 55), Pair(-41, 95), Pair(-31, 58), Pair(43, -81), Pair(-38, 2),
        Pair(3, -41), Pair(-129, 95), Pair(-43, 9), Pair(-45, 41), Pair(-34, 71), Pair(-24, -27), Pair(-19, -64), Pair(1, -74),
        Pair(-143, 89), Pair(-110, 31), Pair(-70, 20), Pair(-24, -56), Pair(-23, -10), Pair(-37, 11), Pair(-52, 44), Pair(4, -66)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, -27), Pair(53, -15), Pair(-16, 21), Pair(-48, 39), Pair(-50, 34), Pair(-34, 12), Pair(18, -17), Pair(-9, -36),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, 128), Pair(-42, 55), Pair(41, -52), Pair(78, -125), Pair(79, -160), Pair(6, -105), Pair(-41, 58), Pair(17, 90),
        Pair(-45, 86), Pair(34, 33), Pair(130, -40), Pair(139, -68), Pair(156, -98), Pair(161, -30), Pair(121, 13), Pair(-2, 30),
        Pair(25, 16), Pair(-39, 31), Pair(-10, -9), Pair(25, -22), Pair(37, -23), Pair(26, -14), Pair(-3, 12), Pair(-41, 6),
        Pair(-59, 19), Pair(-58, 27), Pair(-4, -17), Pair(-17, -7), Pair(19, -24), Pair(5, -12), Pair(-15, 13), Pair(-33, -5),
        Pair(-82, 13), Pair(-35, 15), Pair(-12, -13), Pair(-10, 4), Pair(6, -12), Pair(-4, -7), Pair(-11, -3), Pair(-30, -19),
        Pair(-71, 26), Pair(-35, 22), Pair(19, -16), Pair(-54, -18), Pair(-3, -17), Pair(12, -5), Pair(-26, 5), Pair(-29, -11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-244, -37), Pair(1, 26), Pair(-77, 59), Pair(-124, -17), Pair(-12, 13), Pair(-102, -38), Pair(-15, -84), Pair(-140, -29),
        Pair(-39, -2), Pair(-72, 21), Pair(-23, 64), Pair(46, -43), Pair(75, -41), Pair(-8, -1), Pair(24, 1), Pair(-109, -2),
        Pair(-24, 13), Pair(70, 10), Pair(65, 14), Pair(3, 27), Pair(-1, -12), Pair(124, -38), Pair(31, -39), Pair(44, -45),
        Pair(14, 46), Pair(26, 28), Pair(14, 42), Pair(66, 34), Pair(89, 11), Pair(32, 75), Pair(100, 12), Pair(14, 17),
        Pair(-29, 46), Pair(-14, 72), Pair(16, 29), Pair(15, 44), Pair(-6, 64), Pair(-15, 51), Pair(49, 5), Pair(1, 27),
        Pair(-47, -3), Pair(-2, 6), Pair(14, 15), Pair(30, 33), Pair(40, 63), Pair(10, 18), Pair(12, 16), Pair(25, -39),
        Pair(-193, 40), Pair(-23, 30), Pair(-12, 7), Pair(2, 17), Pair(-33, 52), Pair(23, 0), Pair(27, -50), Pair(-39, 39),
        Pair(-27, 11), Pair(-30, 42), Pair(-75, 34), Pair(-95, 20), Pair(-51, 7), Pair(14, 43), Pair(-39, 4), Pair(-111, 111)
      },
      { // Piece 2
        Pair(-34, 0), Pair(-139, -11), Pair(-64, -39), Pair(-77, -36), Pair(-2, 21), Pair(-55, 13), Pair(-25, -25), Pair(-143, -27),
        Pair(-18, 3), Pair(99, -16), Pair(-109, -14), Pair(141, 30), Pair(-35, -18), Pair(-6, -22), Pair(-33, 60), Pair(-55, 34),
        Pair(-58, 39), Pair(-46, -22), Pair(6, 2), Pair(4, 11), Pair(80, -13), Pair(3, 28), Pair(105, -35), Pair(50, -12),
        Pair(16, -6), Pair(-6, 20), Pair(39, 8), Pair(26, 0), Pair(73, -23), Pair(95, -17), Pair(-6, 1), Pair(24, -12),
        Pair(28, -6), Pair(-33, 16), Pair(-35, 17), Pair(57, 3), Pair(33, -10), Pair(31, -10), Pair(15, 5), Pair(-70, 10),
        Pair(8, 11), Pair(-28, 13), Pair(-35, 34), Pair(-11, 17), Pair(39, -8), Pair(-19, 14), Pair(-21, 15), Pair(64, -54),
        Pair(-68, 37), Pair(-14, 7), Pair(-39, 14), Pair(-33, 18), Pair(-20, 24), Pair(-34, 18), Pair(-21, 1), Pair(38, -12),
        Pair(10, -52), Pair(54, -23), Pair(-31, 43), Pair(14, 21), Pair(-22, -2), Pair(-31, 33), Pair(-111, -45), Pair(7, 64)
      },
      { // Piece 3
        Pair(27, 36), Pair(79, 131), Pair(-17, 55), Pair(126, 43), Pair(29, -9), Pair(22, 36), Pair(63, 98), Pair(83, 46),
        Pair(42, 28), Pair(41, 44), Pair(65, 31), Pair(93, -6), Pair(88, -22), Pair(-13, 32), Pair(19, 43), Pair(-20, 44),
        Pair(10, 43), Pair(-25, 42), Pair(9, 30), Pair(-16, 34), Pair(18, 14), Pair(75, 2), Pair(35, 17), Pair(-42, 25),
        Pair(-81, 68), Pair(-120, 83), Pair(-2, 42), Pair(-28, 45), Pair(25, 13), Pair(-20, 30), Pair(-53, 32), Pair(-35, 41),
        Pair(-99, 49), Pair(-105, 64), Pair(-30, 34), Pair(-87, 58), Pair(-32, 19), Pair(-34, 25), Pair(-45, 42), Pair(-46, 14),
        Pair(-45, -6), Pair(-76, 37), Pair(-39, 13), Pair(-103, 39), Pair(-3, 18), Pair(-73, 53), Pair(-61, -9), Pair(-39, 1),
        Pair(-49, -4), Pair(-131, 60), Pair(-25, -2), Pair(-131, 45), Pair(-37, 7), Pair(-4, -12), Pair(-6, -20), Pair(-85, 17),
        Pair(-56, -1), Pair(-22, -12), Pair(-40, 18), Pair(-66, 25), Pair(-43, -4), Pair(-33, 4), Pair(-52, 12), Pair(-46, 1)
      },
      { // Piece 4
        Pair(-57, 87), Pair(-14, -8), Pair(53, 89), Pair(24, 67), Pair(62, 81), Pair(72, 39), Pair(-41, -47), Pair(38, 11),
        Pair(-24, 6), Pair(16, -30), Pair(80, -17), Pair(96, 52), Pair(-6, 114), Pair(56, -16), Pair(-22, -12), Pair(66, -53),
        Pair(32, -18), Pair(95, -36), Pair(32, 3), Pair(-30, 82), Pair(16, 69), Pair(43, 0), Pair(-37, -2), Pair(62, -27),
        Pair(33, 32), Pair(-28, 33), Pair(-5, -6), Pair(-16, 68), Pair(27, -10), Pair(46, 11), Pair(-10, -3), Pair(-5, -32),
        Pair(-18, -77), Pair(45, -55), Pair(-87, 121), Pair(-46, 63), Pair(-10, 80), Pair(35, -59), Pair(-54, 26), Pair(-138, 49),
        Pair(-43, -91), Pair(-42, -2), Pair(-54, 52), Pair(-96, 44), Pair(-22, 78), Pair(-2, -34), Pair(63, -20), Pair(-1, -26),
        Pair(-119, -32), Pair(-61, -61), Pair(-34, 0), Pair(-18, -2), Pair(-31, 24), Pair(-44, 6), Pair(5, -83), Pair(-110, -130),
        Pair(-166, -77), Pair(-97, 51), Pair(-54, -37), Pair(-46, 11), Pair(-16, -83), Pair(20, -113), Pair(-12, -8), Pair(-48, 42)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(31, -45), Pair(33, -24), Pair(-1, -6), Pair(-17, 9), Pair(-20, 13), Pair(-14, -5), Pair(34, -31), Pair(9, -43),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(37, -27), Pair(49, -55), Pair(65, -60), Pair(8, -73), Pair(114, -100), Pair(95, -103), Pair(13, -5), Pair(109, -41),
        Pair(-25, 33), Pair(48, 29), Pair(121, -28), Pair(98, -51), Pair(92, -65), Pair(107, -41), Pair(29, 12), Pair(64, -7),
        Pair(-42, 28), Pair(-18, 32), Pair(-5, 7), Pair(9, -15), Pair(5, -3), Pair(3, -1), Pair(-2, 20), Pair(-23, 9),
        Pair(-62, 21), Pair(-62, 38), Pair(-29, 6), Pair(-7, -4), Pair(-3, -2), Pair(-15, -3), Pair(-16, 17), Pair(-30, 0),
        Pair(-70, 10), Pair(-36, 15), Pair(-18, -3), Pair(23, -10), Pair(15, -8), Pair(1, -5), Pair(-6, 3), Pair(-42, -3),
        Pair(-80, 25), Pair(-55, 33), Pair(-16, 7), Pair(-39, 18), Pair(28, 7), Pair(12, -4), Pair(-10, 12), Pair(-48, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-48, -56), Pair(-40, -42), Pair(-17, 0), Pair(53, -51), Pair(-45, 2), Pair(-10, -22), Pair(65, -72), Pair(-122, -103),
        Pair(-16, -23), Pair(-31, 29), Pair(-18, 28), Pair(0, 13), Pair(39, -16), Pair(-4, 16), Pair(-56, 43), Pair(-39, 2),
        Pair(-23, -2), Pair(7, 22), Pair(58, 8), Pair(86, 9), Pair(110, -10), Pair(69, -24), Pair(83, 8), Pair(68, -33),
        Pair(15, 18), Pair(48, 22), Pair(63, 29), Pair(62, 17), Pair(107, 11), Pair(28, 22), Pair(91, -7), Pair(83, 2),
        Pair(-61, 25), Pair(69, -2), Pair(-1, 50), Pair(67, 36), Pair(62, 31), Pair(129, -4), Pair(62, 13), Pair(22, 6),
        Pair(-15, 7), Pair(-33, 24), Pair(-1, 25), Pair(0, 35), Pair(58, 25), Pair(27, 12), Pair(22, 10), Pair(-41, 26),
        Pair(-32, 16), Pair(-30, 16), Pair(6, 12), Pair(2, 33), Pair(-11, 31), Pair(42, 19), Pair(27, 11), Pair(78, 8),
        Pair(-19, -20), Pair(-107, 19), Pair(-31, 49), Pair(-82, 33), Pair(-62, 32), Pair(-41, 1), Pair(-73, 18), Pair(-127, 37)
      },
      { // Piece 2
        Pair(-34, 18), Pair(3, 18), Pair(-19, 44), Pair(-14, -5), Pair(-11, 20), Pair(-118, -12), Pair(-74, -17), Pair(-37, -8),
        Pair(-56, -21), Pair(-54, 4), Pair(20, -17), Pair(-51, -7), Pair(-34, -11), Pair(16, -9), Pair(-23, -6), Pair(-34, -36),
        Pair(-9, 17), Pair(19, -16), Pair(-44, 9), Pair(64, -29), Pair(-49, 22), Pair(94, -29), Pair(4, -14), Pair(-30, -5),
        Pair(31, -9), Pair(6, -8), Pair(82, -25), Pair(122, -30), Pair(101, -9), Pair(30, 23), Pair(86, -14), Pair(103, -35),
        Pair(-54, 7), Pair(17, 3), Pair(-8, 1), Pair(54, 0), Pair(70, -16), Pair(26, 5), Pair(-23, 23), Pair(-2, -8),
        Pair(-43, 14), Pair(12, -8), Pair(54, -13), Pair(53, -12), Pair(67, -15), Pair(44, -5), Pair(16, -6), Pair(-10, -18),
        Pair(-75, 19), Pair(-37, 13), Pair(16, -4), Pair(47, -8), Pair(-27, 20), Pair(-23, 10), Pair(7, -15), Pair(31, -34),
        Pair(-66, 8), Pair(-55, 40), Pair(-38, 9), Pair(-32, 3), Pair(78, -14), Pair(-4, -3), Pair(-70, 37), Pair(-37, 10)
      },
      { // Piece 3
        Pair(-48, 37), Pair(-67, 46), Pair(-7, 36), Pair(-83, 32), Pair(-18, 17), Pair(42, 22), Pair(-27, 17), Pair(-81, 49),
        Pair(50, 12), Pair(26, 31), Pair(-67, 53), Pair(120, -8), Pair(61, -13), Pair(-38, 19), Pair(-4, -2), Pair(-92, 17),
        Pair(-17, 25), Pair(58, 10), Pair(-6, 19), Pair(28, 2), Pair(61, -6), Pair(51, 9), Pair(-16, 27), Pair(-9, 11),
        Pair(-90, 43), Pair(-3, 21), Pair(-66, 45), Pair(60, 12), Pair(-39, 25), Pair(31, 1), Pair(-9, 14), Pair(-60, 18),
        Pair(-95, 22), Pair(-61, 35), Pair(-100, 36), Pair(-15, 15), Pair(-19, 12), Pair(-81, 21), Pair(-48, 19), Pair(-31, -8),
        Pair(-78, 17), Pair(-65, 22), Pair(-9, -6), Pair(-63, 19), Pair(-62, 11), Pair(-78, 28), Pair(-18, -17), Pair(-114, 16),
        Pair(-107, 24), Pair(-87, 20), Pair(-54, 7), Pair(-67, 13), Pair(-102, 33), Pair(11, -14), Pair(-70, 12), Pair(-71, 12),
        Pair(-70, 14), Pair(-68, 20), Pair(-83, 21), Pair(-74, 24), Pair(-77, 16), Pair(-47, -6), Pair(-45, -7), Pair(-75, 4)
      },
      { // Piece 4
        Pair(-76, -5), Pair(-72, -17), Pair(-47, 33), Pair(-18, 1), Pair(-83, 42), Pair(131, -28), Pair(26, -86), Pair(10, -38),
        Pair(-58, 11), Pair(-75, 35), Pair(-147, 49), Pair(-125, 119), Pair(13, -29), Pair(-24, 18), Pair(-25, 77), Pair(34, -55),
        Pair(-20, -14), Pair(-131, 30), Pair(107, -72), Pair(-26, 30), Pair(-17, 40), Pair(76, -60), Pair(-116, -6), Pair(-14, -22),
        Pair(-26, -30), Pair(-63, 21), Pair(16, -12), Pair(-20, 49), Pair(44, 10), Pair(-69, 76), Pair(133, -104), Pair(-20, -25),
        Pair(-32, -9), Pair(-111, 54), Pair(-24, 23), Pair(55, 4), Pair(-51, 84), Pair(-22, 18), Pair(-64, 41), Pair(18, 4),
        Pair(-40, -29), Pair(-12, -20), Pair(-30, 6), Pair(40, -19), Pair(-85, 40), Pair(8, -24), Pair(-7, 7), Pair(-38, -59),
        Pair(8, -118), Pair(2, 24), Pair(-2, -22), Pair(-19, -29), Pair(-57, 49), Pair(-65, 13), Pair(-23, 2), Pair(-87, -25),
        Pair(20, -99), Pair(-48, -16), Pair(-48, -37), Pair(-43, -35), Pair(-43, -9), Pair(-80, 57), Pair(-44, 33), Pair(-59, -6)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(58, -49), Pair(60, -18), Pair(-20, 11), Pair(-1, 17), Pair(-31, 21), Pair(-26, 8), Pair(0, -12), Pair(-28, -32),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(25, -40), Pair(157, -78), Pair(80, -61), Pair(124, -94), Pair(11, -92), Pair(21, -114), Pair(124, -33), Pair(37, 8),
        Pair(1, 21), Pair(47, 17), Pair(134, -43), Pair(68, -46), Pair(73, -43), Pair(92, -39), Pair(3, 8), Pair(93, 1),
        Pair(-63, 30), Pair(-32, 23), Pair(-15, -1), Pair(-14, -13), Pair(-10, -5), Pair(9, -11), Pair(-32, 24), Pair(-62, 21),
        Pair(-108, 28), Pair(-71, 40), Pair(-78, 20), Pair(-50, 15), Pair(-34, 18), Pair(-57, 19), Pair(-60, 36), Pair(-63, 12),
        Pair(-126, 22), Pair(-97, 29), Pair(-69, 10), Pair(-28, 0), Pair(-17, 8), Pair(-38, 2), Pair(-87, 22), Pair(-117, 15),
        Pair(-120, 34), Pair(-72, 36), Pair(-62, 17), Pair(24, -8), Pair(42, -3), Pair(-31, 10), Pair(-59, 29), Pair(-122, 29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-52, -138), Pair(-57, -16), Pair(-140, 35), Pair(-47, 17), Pair(40, -33), Pair(-90, -3), Pair(-3, -29), Pair(-38, -49),
        Pair(-36, 12), Pair(-96, 17), Pair(6, -13), Pair(49, -13), Pair(56, -46), Pair(-32, -18), Pair(-42, 3), Pair(-112, -20),
        Pair(0, -30), Pair(-5, -22), Pair(7, 4), Pair(5, 26), Pair(30, 5), Pair(-3, -22), Pair(49, -16), Pair(30, -31),
        Pair(96, 6), Pair(23, -3), Pair(40, 14), Pair(43, 14), Pair(172, -18), Pair(72, 10), Pair(82, -8), Pair(59, -2),
        Pair(9, 15), Pair(62, 9), Pair(44, 16), Pair(75, 0), Pair(87, 15), Pair(40, 3), Pair(72, -4), Pair(85, -19),
        Pair(-17, -4), Pair(-48, 17), Pair(10, 15), Pair(93, 8), Pair(38, 16), Pair(5, 11), Pair(2, -10), Pair(-21, 38),
        Pair(-66, 36), Pair(-47, 34), Pair(-18, 6), Pair(-8, 22), Pair(-17, 21), Pair(50, 10), Pair(-8, 30), Pair(-34, 40),
        Pair(39, 9), Pair(-203, 26), Pair(-87, 18), Pair(-103, 5), Pair(-16, 14), Pair(2, -2), Pair(-28, 12), Pair(-80, 20)
      },
      { // Piece 2
        Pair(-26, -27), Pair(-99, 13), Pair(-36, -9), Pair(-52, -10), Pair(-85, -8), Pair(-42, 7), Pair(10, -26), Pair(-58, -47),
        Pair(-87, -21), Pair(20, -4), Pair(13, -5), Pair(13, -28), Pair(-92, -12), Pair(-102, -16), Pair(-26, 14), Pair(-70, -3),
        Pair(74, -16), Pair(6, -4), Pair(27, -21), Pair(20, -31), Pair(80, -48), Pair(0, -25), Pair(53, -19), Pair(-30, -26),
        Pair(-30, -13), Pair(58, -31), Pair(60, -15), Pair(148, -42), Pair(49, -23), Pair(56, -22), Pair(61, -30), Pair(-6, -20),
        Pair(-49, 6), Pair(6, 0), Pair(97, -30), Pair(107, -21), Pair(75, -19), Pair(44, -9), Pair(40, -19), Pair(1, -17),
        Pair(-58, 13), Pair(-27, 3), Pair(19, 4), Pair(-17, -1), Pair(55, -15), Pair(9, -9), Pair(-12, -18), Pair(-79, 39),
        Pair(-101, 45), Pair(-100, 22), Pair(-70, 20), Pair(-26, -3), Pair(6, -8), Pair(-33, 2), Pair(46, -29), Pair(65, -46),
        Pair(-112, -1), Pair(-17, 29), Pair(-7, -4), Pair(-35, -1), Pair(1, -4), Pair(-20, -1), Pair(12, -20), Pair(-63, 1)
      },
      { // Piece 3
        Pair(-30, 21), Pair(-36, 12), Pair(34, -7), Pair(33, -12), Pair(-49, 0), Pair(-17, 13), Pair(-28, -1), Pair(-18, -8),
        Pair(-4, -14), Pair(15, 4), Pair(52, -14), Pair(73, -39), Pair(38, -17), Pair(10, -2), Pair(70, -31), Pair(-7, -17),
        Pair(-5, -3), Pair(41, -11), Pair(45, -12), Pair(-3, -23), Pair(32, -32), Pair(45, -9), Pair(-10, 16), Pair(-164, 29),
        Pair(-29, 7), Pair(55, -19), Pair(41, -7), Pair(20, 0), Pair(103, -40), Pair(3, -14), Pair(41, -19), Pair(-21, -10),
        Pair(-64, 6), Pair(-83, 30), Pair(9, -7), Pair(34, -16), Pair(40, -19), Pair(-18, -18), Pair(-6, -7), Pair(-11, -16),
        Pair(-117, -4), Pair(7, -31), Pair(-22, -22), Pair(8, -32), Pair(1, -25), Pair(-37, -9), Pair(46, -49), Pair(-130, -19),
        Pair(-127, 7), Pair(-16, -30), Pair(-30, -17), Pair(-33, -32), Pair(-78, -3), Pair(-38, -33), Pair(-23, -39), Pair(-114, -4),
        Pair(-74, -9), Pair(-77, -3), Pair(-66, -8), Pair(-55, -13), Pair(-36, -25), Pair(-35, -18), Pair(-46, -11), Pair(-75, -11)
      },
      { // Piece 4
        Pair(1, -44), Pair(53, -74), Pair(-7, -84), Pair(157, -101), Pair(-2, -66), Pair(-55, -76), Pair(-48, -40), Pair(49, -41),
        Pair(58, -145), Pair(-137, -9), Pair(-175, 49), Pair(-41, -82), Pair(36, -2), Pair(-45, -2), Pair(172, -175), Pair(-129, -44),
        Pair(-66, -64), Pair(-64, 32), Pair(52, -40), Pair(-58, -28), Pair(83, -72), Pair(57, -38), Pair(6, -34), Pair(-10, -63),
        Pair(31, -35), Pair(-68, -6), Pair(-56, -29), Pair(18, -74), Pair(-69, -46), Pair(133, -120), Pair(46, -106), Pair(85, -81),
        Pair(-38, -137), Pair(-82, -20), Pair(-47, 0), Pair(-22, -21), Pair(-24, -35), Pair(45, -33), Pair(-37, -82), Pair(-122, -18),
        Pair(-132, -148), Pair(54, -86), Pair(-122, -28), Pair(45, -86), Pair(-2, -14), Pair(-27, -88), Pair(-16, -144), Pair(-65, -14),
        Pair(-84, -20), Pair(-78, -127), Pair(10, -83), Pair(-37, -75), Pair(15, -58), Pair(-36, 23), Pair(-60, -100), Pair(-70, -104),
        Pair(-61, -132), Pair(-181, -58), Pair(-92, 39), Pair(21, -170), Pair(-106, -128), Pair(8, 11), Pair(-42, -118), Pair(-17, -51)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-34, -19), Pair(76, -13), Pair(-25, 17), Pair(1, 19), Pair(21, 15), Pair(0, 11), Pair(14, -6), Pair(-16, -25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, -11), Pair(83, -73), Pair(-23, 15), Pair(-45, -24), Pair(23, 26), Pair(35, -10), Pair(-80, 115), Pair(-208, 23),
        Pair(-92, 48), Pair(-67, 54), Pair(-32, 30), Pair(-25, 35), Pair(31, 27), Pair(-37, 10), Pair(7, 78), Pair(-56, 44),
        Pair(-124, 38), Pair(-111, 48), Pair(-93, 18), Pair(-92, 14), Pair(-5, -3), Pair(-56, 2), Pair(-10, 32), Pair(-129, 32),
        Pair(-139, 31), Pair(-116, 40), Pair(-79, 14), Pair(-95, 23), Pair(-29, 14), Pair(-59, 10), Pair(-71, 34), Pair(-105, 26),
        Pair(-145, 27), Pair(-113, 39), Pair(-96, 27), Pair(-61, 25), Pair(-33, 23), Pair(-40, 16), Pair(-101, 36), Pair(-130, 29),
        Pair(-176, 48), Pair(-127, 43), Pair(-39, 25), Pair(29, -2), Pair(67, -3), Pair(-14, 12), Pair(-89, 39), Pair(-143, 42),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-38, -166), Pair(-57, -6), Pair(-110, -6), Pair(-28, -27), Pair(-88, -5), Pair(-26, 1), Pair(-29, 40), Pair(7, -78),
        Pair(-115, -26), Pair(11, 5), Pair(-10, 4), Pair(40, -19), Pair(104, -6), Pair(107, -27), Pair(-36, 0), Pair(16, -22),
        Pair(-35, -12), Pair(-79, 11), Pair(-47, -1), Pair(36, 9), Pair(19, -19), Pair(-22, -40), Pair(30, 36), Pair(3, -19),
        Pair(-79, 15), Pair(8, 16), Pair(34, 10), Pair(82, -5), Pair(111, 11), Pair(80, 1), Pair(34, -13), Pair(-23, 5),
        Pair(32, -26), Pair(39, 1), Pair(109, -7), Pair(57, 3), Pair(82, -4), Pair(70, -8), Pair(149, -21), Pair(-27, -13),
        Pair(15, -34), Pair(-54, 0), Pair(15, 5), Pair(80, 2), Pair(52, 8), Pair(55, -3), Pair(-44, 3), Pair(-68, -4),
        Pair(-25, -2), Pair(-86, 12), Pair(49, 13), Pair(7, 15), Pair(-21, 6), Pair(19, 4), Pair(-61, -3), Pair(-32, -10),
        Pair(-31, 6), Pair(-111, 37), Pair(-94, 28), Pair(-57, 20), Pair(-81, 23), Pair(-77, 4), Pair(-114, 23), Pair(12, 11)
      },
      { // Piece 2
        Pair(-34, 7), Pair(-45, 5), Pair(-89, 0), Pair(-30, -44), Pair(16, 3), Pair(-122, -3), Pair(-42, -22), Pair(47, -32),
        Pair(-72, -17), Pair(-67, -5), Pair(-147, 10), Pair(-79, 1), Pair(-142, -8), Pair(-98, -3), Pair(-74, -1), Pair(-54, -26),
        Pair(8, 1), Pair(10, -21), Pair(-72, 4), Pair(-39, -32), Pair(-43, -8), Pair(14, -13), Pair(-35, 12), Pair(-162, 11),
        Pair(-60, 26), Pair(31, -9), Pair(15, -26), Pair(62, -19), Pair(46, -24), Pair(6, -7), Pair(52, -17), Pair(-64, 7),
        Pair(-91, 2), Pair(26, -19), Pair(-64, -18), Pair(49, -16), Pair(-17, -23), Pair(-54, -9), Pair(-6, 1), Pair(-54, 0),
        Pair(-27, -27), Pair(-47, 12), Pair(-20, -12), Pair(-40, -7), Pair(29, -11), Pair(10, -6), Pair(-7, -20), Pair(-28, 5),
        Pair(-96, 29), Pair(-76, -4), Pair(-77, 2), Pair(10, 1), Pair(-79, -4), Pair(-4, -2), Pair(-19, -14), Pair(-28, -7),
        Pair(-118, 9), Pair(-114, 56), Pair(1, -16), Pair(-92, 11), Pair(14, -6), Pair(-85, 19), Pair(-157, 23), Pair(-42, -48)
      },
      { // Piece 3
        Pair(-55, -13), Pair(-36, 7), Pair(13, -1), Pair(-8, 1), Pair(13, 5), Pair(9, 12), Pair(152, -26), Pair(15, -21),
        Pair(-58, -13), Pair(15, -14), Pair(-67, -3), Pair(15, -23), Pair(-33, -22), Pair(70, -14), Pair(-30, -10), Pair(-10, -42),
        Pair(-82, 8), Pair(15, -16), Pair(94, -53), Pair(26, -26), Pair(53, -34), Pair(125, -46), Pair(9, -30), Pair(-45, -26),
        Pair(-61, -4), Pair(11, -23), Pair(20, 11), Pair(83, -54), Pair(122, -61), Pair(111, -59), Pair(53, -54), Pair(-29, -25),
        Pair(-21, 2), Pair(-88, 14), Pair(-82, 11), Pair(-31, -4), Pair(0, -17), Pair(40, -35), Pair(44, -26), Pair(-71, -10),
        Pair(-103, -2), Pair(-24, -38), Pair(-156, 7), Pair(-54, -27), Pair(20, -42), Pair(-61, -1), Pair(44, -67), Pair(-36, -40),
        Pair(-54, -49), Pair(-94, -48), Pair(-65, -16), Pair(-77, -23), Pair(23, -36), Pair(-15, -34), Pair(-110, -18), Pair(-34, -27),
        Pair(-152, -12), Pair(-19, -29), Pair(21, -38), Pair(-50, -23), Pair(-51, -19), Pair(-74, -27), Pair(-129, 8), Pair(-94, -20)
      },
      { // Piece 4
        Pair(53, -127), Pair(36, -34), Pair(-77, -91), Pair(-18, 10), Pair(-8, -80), Pair(-48, 58), Pair(87, -128), Pair(-85, -70),
        Pair(-104, -71), Pair(-15, -81), Pair(19, -68), Pair(19, -58), Pair(19, -88), Pair(-21, -66), Pair(-59, -46), Pair(18, -163),
        Pair(-29, -24), Pair(43, -83), Pair(-7, -62), Pair(8, -48), Pair(155, -81), Pair(-44, -117), Pair(110, -88), Pair(-18, -82),
        Pair(-47, -78), Pair(30, 2), Pair(-36, -77), Pair(83, -7), Pair(-19, -102), Pair(11, -48), Pair(-23, -61), Pair(-23, -9),
        Pair(-53, -89), Pair(-69, -83), Pair(66, -21), Pair(-62, -32), Pair(-27, 34), Pair(31, -57), Pair(-10, -56), Pair(-2, -16),
        Pair(-10, -78), Pair(-37, -80), Pair(-37, -32), Pair(-68, -15), Pair(53, -59), Pair(112, -107), Pair(33, -50), Pair(80, 36),
        Pair(-26, -65), Pair(-55, -91), Pair(-31, -160), Pair(-6, -51), Pair(-68, -76), Pair(17, -52), Pair(-88, -159), Pair(-8, -64),
        Pair(-92, -139), Pair(-35, -149), Pair(-16, -111), Pair(-32, -37), Pair(-115, -177), Pair(-39, -68), Pair(33, 2), Pair(-8, -39)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(68, -54), Pair(110, -26), Pair(-6, 10), Pair(-34, 24), Pair(-23, 18), Pair(2, 7), Pair(0, -8), Pair(19, -35),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-41, -5), Pair(151, -30), Pair(-84, 14), Pair(-135, 49), Pair(-94, 2), Pair(-12, -12), Pair(-76, 21), Pair(71, -4),
        Pair(-80, 62), Pair(-78, 107), Pair(-116, 74), Pair(-56, 86), Pair(-101, 92), Pair(-56, 78), Pair(-97, 110), Pair(-113, 67),
        Pair(-110, 33), Pair(21, 34), Pair(-9, 5), Pair(-87, 23), Pair(-139, 22), Pair(56, -15), Pair(-19, 12), Pair(-42, 10),
        Pair(-26, -4), Pair(-59, 30), Pair(-77, 11), Pair(6, 3), Pair(-52, 5), Pair(34, -19), Pair(-100, 19), Pair(-107, 13),
        Pair(-153, 3), Pair(-126, 34), Pair(-31, 7), Pair(23, 7), Pair(-84, 16), Pair(25, -4), Pair(-44, 17), Pair(-138, 13),
        Pair(-148, 32), Pair(-163, 59), Pair(71, 6), Pair(-14, -44), Pair(-16, 0), Pair(2, 5), Pair(-42, 18), Pair(-128, 28),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-65, -154), Pair(-75, -116), Pair(-44, -80), Pair(-115, -62), Pair(-70, -38), Pair(-56, -124), Pair(7, -105), Pair(-46, -144),
        Pair(2, -128), Pair(19, -91), Pair(35, -54), Pair(-135, -77), Pair(-73, -47), Pair(38, -92), Pair(-35, -41), Pair(-39, -5),
        Pair(-56, -70), Pair(-149, -40), Pair(-39, -60), Pair(72, -51), Pair(98, -54), Pair(-104, -39), Pair(-5, -108), Pair(-163, -52),
        Pair(123, -70), Pair(22, -50), Pair(50, -59), Pair(-8, -51), Pair(70, -91), Pair(-49, -31), Pair(-3, -60), Pair(40, -91),
        Pair(-60, -34), Pair(-87, -28), Pair(44, -45), Pair(199, -44), Pair(41, -48), Pair(139, -61), Pair(49, -65), Pair(20, -76),
        Pair(-98, -88), Pair(-35, -15), Pair(63, -50), Pair(47, -8), Pair(-65, -2), Pair(60, -54), Pair(-40, -28), Pair(38, -37),
        Pair(-54, -175), Pair(-91, -41), Pair(-64, -36), Pair(-17, -16), Pair(-6, -49), Pair(22, -38), Pair(19, 6), Pair(3, -61),
        Pair(-8, -76), Pair(75, -48), Pair(35, -35), Pair(-13, -95), Pair(30, -77), Pair(68, -68), Pair(53, -41), Pair(-40, 24)
      },
      { // Piece 2
        Pair(-37, -35), Pair(59, -19), Pair(-124, -45), Pair(-91, -51), Pair(-54, -14), Pair(-165, -54), Pair(-23, -34), Pair(-1, -43),
        Pair(-73, -33), Pair(-92, -49), Pair(-76, -7), Pair(-76, -1), Pair(-184, -9), Pair(-94, -26), Pair(-76, -35), Pair(-14, -15),
        Pair(-102, -31), Pair(-64, -27), Pair(-66, -40), Pair(-130, -19), Pair(-45, 10), Pair(-18, -36), Pair(-90, -9), Pair(-47, -15),
        Pair(-91, -39), Pair(-68, -9), Pair(-83, -19), Pair(-58, -15), Pair(-56, -46), Pair(-55, 36), Pair(-104, -6), Pair(-114, -15),
        Pair(-22, 8), Pair(-58, -23), Pair(-52, -17), Pair(78, -39), Pair(-13, -32), Pair(38, -22), Pair(-57, -5), Pair(-17, -56),
        Pair(-19, -31), Pair(-73, -12), Pair(-58, -25), Pair(-22, -62), Pair(16, -45), Pair(57, -42), Pair(15, -29), Pair(-66, -15),
        Pair(-66, 26), Pair(-76, -57), Pair(-10, -24), Pair(-6, -28), Pair(-41, -44), Pair(-37, -34), Pair(-130, -43), Pair(24, -51),
        Pair(-73, -73), Pair(-127, 34), Pair(-65, -23), Pair(-78, -32), Pair(4, -57), Pair(0, -19), Pair(-84, -16), Pair(-95, -99)
      },
      { // Piece 3
        Pair(-54, -72), Pair(-10, -99), Pair(41, -77), Pair(49, -54), Pair(-22, -69), Pair(77, -82), Pair(96, -106), Pair(28, -98),
        Pair(-69, -81), Pair(79, -107), Pair(82, -61), Pair(-58, -60), Pair(-60, -55), Pair(-37, -64), Pair(-23, -63), Pair(-19, -96),
        Pair(-69, -69), Pair(-3, -97), Pair(24, -109), Pair(-44, -69), Pair(39, -87), Pair(-34, -68), Pair(-78, -59), Pair(-17, -107),
        Pair(-33, -82), Pair(22, -80), Pair(-77, -63), Pair(5, -80), Pair(58, -112), Pair(-20, -85), Pair(22, -82), Pair(-17, -89),
        Pair(-3, -121), Pair(-15, -91), Pair(-37, -113), Pair(0, -121), Pair(2, -75), Pair(55, -79), Pair(-85, -90), Pair(-12, -100),
        Pair(-39, -116), Pair(51, -107), Pair(-15, -91), Pair(20, -109), Pair(19, -116), Pair(18, -98), Pair(34, -73), Pair(-33, -136),
        Pair(-26, -93), Pair(-35, -75), Pair(-15, -84), Pair(-27, -79), Pair(1, -75), Pair(69, -141), Pair(49, -115), Pair(87, -149),
        Pair(-23, -95), Pair(-5, -99), Pair(-9, -87), Pair(-41, -94), Pair(38, -86), Pair(46, -89), Pair(106, -97), Pair(29, -77)
      },
      { // Piece 4
        Pair(-165, -169), Pair(-45, -134), Pair(-178, -109), Pair(-41, -141), Pair(-74, -21), Pair(-165, -63), Pair(-158, -205), Pair(-111, -136),
        Pair(-75, -126), Pair(-40, -114), Pair(-106, -143), Pair(38, -103), Pair(-31, -68), Pair(12, -108), Pair(-83, -121), Pair(-40, -112),
        Pair(-31, -84), Pair(-44, -59), Pair(-39, -84), Pair(27, -62), Pair(-43, -85), Pair(-68, -98), Pair(-63, -119), Pair(-10, -67),
        Pair(-50, -118), Pair(-47, -65), Pair(-55, -149), Pair(-53, -87), Pair(-10, -154), Pair(-103, -69), Pair(-73, -43), Pair(-54, -98),
        Pair(-100, -225), Pair(-35, -94), Pair(-11, -74), Pair(-22, 13), Pair(14, -94), Pair(1, -7), Pair(22, -19), Pair(-66, -62),
        Pair(-36, -88), Pair(32, -46), Pair(4, -81), Pair(-60, -111), Pair(-15, -118), Pair(-73, -102), Pair(-7, -93), Pair(-57, -96),
        Pair(-11, -94), Pair(6, -102), Pair(-51, -105), Pair(38, 26), Pair(26, -19), Pair(-35, -138), Pair(-66, -108), Pair(-22, -44),
        Pair(-18, -46), Pair(-43, -111), Pair(-20, -154), Pair(-23, -25), Pair(-41, -83), Pair(-71, -120), Pair(-48, -81), Pair(-107, -167)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(65, -70), Pair(13, -22), Pair(-51, 12), Pair(-15, 20), Pair(52, 13), Pair(11, 13), Pair(-3, -5), Pair(-58, -30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-156, -6), Pair(-59, 36), Pair(-43, 1), Pair(-25, 13), Pair(4, -9), Pair(24, 0), Pair(-105, -24), Pair(-33, 8),
        Pair(-55, 92), Pair(-61, 98), Pair(-33, 78), Pair(-103, 36), Pair(112, 79), Pair(57, 72), Pair(-79, 122), Pair(25, 80),
        Pair(-131, 70), Pair(-71, 45), Pair(-73, 34), Pair(-86, 33), Pair(-99, 26), Pair(-28, 26), Pair(-158, 44), Pair(-82, 40),
        Pair(-15, 1), Pair(-20, 29), Pair(-47, 35), Pair(25, -22), Pair(-78, 5), Pair(-39, -8), Pair(-73, 27), Pair(-112, 15),
        Pair(-60, 3), Pair(-47, -5), Pair(-17, 2), Pair(-52, 9), Pair(16, -2), Pair(52, -33), Pair(-59, -3), Pair(-93, 2),
        Pair(-148, 29), Pair(-79, 61), Pair(45, -7), Pair(5, -7), Pair(34, 7), Pair(19, 14), Pair(-78, 38), Pair(-129, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-18, -162), Pair(-32, -86), Pair(-36, -43), Pair(-39, -70), Pair(-44, -90), Pair(-37, -65), Pair(17, 16), Pair(2, 60),
        Pair(-34, -129), Pair(8, 8), Pair(-22, -38), Pair(9, -127), Pair(-27, -110), Pair(-58, -26), Pair(0, -95), Pair(0, -58),
        Pair(84, -21), Pair(-110, -48), Pair(-56, -56), Pair(-85, -110), Pair(-7, -99), Pair(-75, 6), Pair(-1, -53), Pair(16, -17),
        Pair(-3, -48), Pair(46, -26), Pair(38, -53), Pair(49, -34), Pair(-1, -33), Pair(1, -51), Pair(-15, -149), Pair(-8, 11),
        Pair(-41, -159), Pair(40, -12), Pair(-41, 64), Pair(28, -52), Pair(15, -47), Pair(62, -9), Pair(12, -28), Pair(-6, -55),
        Pair(-30, -74), Pair(12, -45), Pair(-50, -16), Pair(58, -41), Pair(89, -1), Pair(22, -11), Pair(-37, -32), Pair(44, 37),
        Pair(-30, -72), Pair(13, -20), Pair(16, -20), Pair(81, -79), Pair(-41, -29), Pair(-53, -33), Pair(-29, -67), Pair(-67, -161),
        Pair(11, 38), Pair(41, 12), Pair(-39, -99), Pair(-53, -76), Pair(-12, -56), Pair(15, -75), Pair(2, -20), Pair(6, 24)
      },
      { // Piece 2
        Pair(19, 61), Pair(-22, 46), Pair(-18, -46), Pair(-20, 15), Pair(33, 54), Pair(-33, -140), Pair(-27, -49), Pair(-9, 88),
        Pair(6, -4), Pair(27, 4), Pair(-59, 6), Pair(-28, 6), Pair(-49, -41), Pair(71, -35), Pair(-36, -19), Pair(-14, 39),
        Pair(4, -28), Pair(-43, -20), Pair(-63, -16), Pair(-70, -19), Pair(-108, -54), Pair(-11, -5), Pair(27, -36), Pair(-129, -43),
        Pair(33, -20), Pair(18, -45), Pair(-37, -17), Pair(-77, 70), Pair(-44, -56), Pair(-16, -57), Pair(-3, -12), Pair(-21, -22),
        Pair(-9, 29), Pair(-44, -19), Pair(15, -42), Pair(55, -35), Pair(7, 38), Pair(49, 9), Pair(-61, 13), Pair(-61, -33),
        Pair(6, 49), Pair(-3, 9), Pair(-101, -56), Pair(-20, 6), Pair(-14, -65), Pair(-7, -15), Pair(-25, 3), Pair(-7, 68),
        Pair(-47, -28), Pair(-3, 47), Pair(-31, -29), Pair(-8, -15), Pair(-39, 2), Pair(-82, -1), Pair(1, -57), Pair(-9, 30),
        Pair(-31, 7), Pair(-9, 60), Pair(-7, -1), Pair(-37, -56), Pair(-48, -37), Pair(-54, -24), Pair(3, 99), Pair(-11, -66)
      },
      { // Piece 3
        Pair(-1, -51), Pair(-50, -46), Pair(-102, -64), Pair(33, 11), Pair(32, -54), Pair(6, 28), Pair(-9, -17), Pair(53, -85),
        Pair(39, -66), Pair(27, -66), Pair(17, -69), Pair(-34, -55), Pair(6, -77), Pair(-100, -38), Pair(-43, -16), Pair(-67, -89),
        Pair(-37, -61), Pair(23, -57), Pair(-54, -55), Pair(38, -70), Pair(82, -75), Pair(26, -89), Pair(-20, -57), Pair(95, -55),
        Pair(-3, -63), Pair(41, -35), Pair(64, -58), Pair(-34, -54), Pair(12, -77), Pair(124, -65), Pair(39, -2), Pair(7, -52),
        Pair(-58, -81), Pair(0, -63), Pair(-86, -87), Pair(-37, -89), Pair(17, -102), Pair(44, -40), Pair(-1, -100), Pair(-4, -76),
        Pair(-35, -42), Pair(-35, -39), Pair(95, -84), Pair(9, -57), Pair(69, -38), Pair(25, -111), Pair(-22, -104), Pair(-9, -29),
        Pair(12, -14), Pair(29, -89), Pair(-49, -41), Pair(27, -116), Pair(4, -70), Pair(44, -37), Pair(-42, -85), Pair(33, -99),
        Pair(-37, -84), Pair(81, -133), Pair(0, -69), Pair(-13, -70), Pair(24, -124), Pair(54, -75), Pair(52, -28), Pair(84, -94)
      },
      { // Piece 4
        Pair(-60, -119), Pair(48, -37), Pair(-59, -104), Pair(-58, -142), Pair(-132, -28), Pair(4, -42), Pair(-184, -248), Pair(-105, -135),
        Pair(-95, -152), Pair(-35, -75), Pair(-2, 16), Pair(-23, -53), Pair(47, 65), Pair(-30, -47), Pair(-53, -100), Pair(-17, -75),
        Pair(-19, -47), Pair(-53, -196), Pair(-38, -90), Pair(-65, -128), Pair(-22, -51), Pair(-18, -118), Pair(-80, -132), Pair(37, -12),
        Pair(-80, -125), Pair(-46, -100), Pair(-47, -104), Pair(-43, -65), Pair(-19, -64), Pair(-15, -16), Pair(-10, -30), Pair(-26, -41),
        Pair(-63, -95), Pair(22, 20), Pair(-44, -56), Pair(94, 145), Pair(55, 31), Pair(-24, -14), Pair(50, 61), Pair(-42, -80),
        Pair(-58, -122), Pair(-55, -133), Pair(54, 29), Pair(-2, -54), Pair(12, 3), Pair(-12, -44), Pair(-61, -88), Pair(11, 30),
        Pair(-85, -167), Pair(-84, -135), Pair(-57, -105), Pair(23, 28), Pair(-34, -14), Pair(9, -7), Pair(-19, -54), Pair(-1, -47),
        Pair(-12, -39), Pair(-61, -152), Pair(0, -44), Pair(4, 31), Pair(-19, -43), Pair(-29, -95), Pair(-19, -103), Pair(-11, -65)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-25, 5), Pair(42, -3), Pair(-103, 46), Pair(-76, 67), Pair(-27, 67), Pair(-28, 49), Pair(-24, 19), Pair(-61, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 4
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(144, -31), Pair(143, 13), Pair(100, 43), Pair(58, -17), Pair(-72, 109), Pair(24, -22), Pair(0, -94), Pair(-6, -74),
        Pair(84, 4), Pair(-52, 79), Pair(44, 58), Pair(41, 9), Pair(11, 22), Pair(104, -27), Pair(163, -48), Pair(79, -12),
        Pair(-86, 58), Pair(3, 37), Pair(12, 20), Pair(-18, 1), Pair(-4, 9), Pair(8, -22), Pair(27, 1), Pair(63, -28),
        Pair(-62, 35), Pair(-90, 57), Pair(-2, 6), Pair(-34, 5), Pair(-2, -4), Pair(-5, -12), Pair(7, 0), Pair(-50, -6),
        Pair(-75, 7), Pair(-46, 16), Pair(20, -16), Pair(-38, 13), Pair(-17, -11), Pair(38, -29), Pair(7, -7), Pair(-81, 7),
        Pair(-94, 32), Pair(-27, 14), Pair(25, -5), Pair(-37, -14), Pair(-58, 37), Pair(36, -18), Pair(-1, 3), Pair(-32, -12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-128, -47), Pair(-62, -135), Pair(-125, -41), Pair(4, -24), Pair(-2, 3), Pair(23, -102), Pair(-25, -99), Pair(-18, -25),
        Pair(-114, 3), Pair(-116, 77), Pair(55, -10), Pair(8, 24), Pair(54, -5), Pair(-3, 35), Pair(-15, -5), Pair(47, -46),
        Pair(-50, -36), Pair(-7, 22), Pair(107, -61), Pair(55, -15), Pair(127, -24), Pair(68, -6), Pair(17, -2), Pair(-14, 47),
        Pair(-59, -12), Pair(3, 0), Pair(10, 19), Pair(105, -16), Pair(101, 17), Pair(49, -5), Pair(104, 2), Pair(102, -42),
        Pair(-52, 7), Pair(-37, -26), Pair(0, 20), Pair(34, 3), Pair(5, 18), Pair(28, 7), Pair(-2, 27), Pair(44, -5),
        Pair(-18, -76), Pair(-95, 35), Pair(-7, 3), Pair(-7, -23), Pair(12, -35), Pair(53, -7), Pair(3, 2), Pair(-58, -26),
        Pair(-68, 9), Pair(-135, -46), Pair(29, -39), Pair(-46, 29), Pair(16, -31), Pair(-60, 27), Pair(20, 14), Pair(-2, -32),
        Pair(-9, -3), Pair(-49, -31), Pair(-121, -21), Pair(-43, 36), Pair(4, 34), Pair(-142, 10), Pair(-121, 18), Pair(-16, -6)
      },
      { // Piece 2
        Pair(-151, -36), Pair(16, -12), Pair(-34, 1), Pair(-12, 14), Pair(-36, -7), Pair(39, -86), Pair(-18, -47), Pair(29, -5),
        Pair(31, -6), Pair(-117, -25), Pair(44, -25), Pair(-72, -3), Pair(-33, -55), Pair(11, -103), Pair(-123, -13), Pair(-139, 31),
        Pair(-94, 35), Pair(-66, 27), Pair(126, -46), Pair(50, -29), Pair(-19, 30), Pair(9, 38), Pair(105, -1), Pair(5, 1),
        Pair(-73, -11), Pair(50, -15), Pair(35, -32), Pair(10, -18), Pair(-19, 6), Pair(36, -27), Pair(6, 8), Pair(-94, 31),
        Pair(48, 25), Pair(-17, -7), Pair(-31, -1), Pair(23, 16), Pair(-13, -21), Pair(-5, 22), Pair(-50, 9), Pair(4, -36),
        Pair(-96, 27), Pair(62, 5), Pair(29, 19), Pair(33, -10), Pair(79, -10), Pair(50, -8), Pair(-21, 18), Pair(-60, -32),
        Pair(58, -31), Pair(-83, 9), Pair(11, 6), Pair(-37, -7), Pair(-40, -8), Pair(-162, -2), Pair(-41, -16), Pair(122, -86),
        Pair(-84, 25), Pair(-89, 4), Pair(2, -10), Pair(40, 3), Pair(-179, 13), Pair(-76, -4), Pair(38, -74), Pair(9, 111)
      },
      { // Piece 3
        Pair(-46, 112), Pair(-32, 71), Pair(87, 128), Pair(70, 145), Pair(74, 8), Pair(6, 48), Pair(12, 71), Pair(-9, 105),
        Pair(-2, 29), Pair(58, 26), Pair(9, 27), Pair(21, 12), Pair(28, 8), Pair(42, 32), Pair(107, -19), Pair(49, -3),
        Pair(-38, 1), Pair(-5, 19), Pair(-31, 14), Pair(54, 30), Pair(140, -48), Pair(6, 13), Pair(46, 10), Pair(9, -10),
        Pair(-54, 45), Pair(-47, 47), Pair(-16, 27), Pair(6, -9), Pair(-49, 32), Pair(53, -18), Pair(-15, 8), Pair(-66, 37),
        Pair(-156, 54), Pair(-62, 0), Pair(-7, -12), Pair(-126, 64), Pair(51, -27), Pair(57, 6), Pair(-70, 22), Pair(-41, -41),
        Pair(-97, 26), Pair(-93, 2), Pair(-124, 56), Pair(-84, 27), Pair(-74, 38), Pair(-91, 15), Pair(-26, 9), Pair(-64, -45),
        Pair(-119, 27), Pair(-162, 61), Pair(-6, -17), Pair(-127, 54), Pair(57, -12), Pair(39, -18), Pair(-18, -10), Pair(-143, 48),
        Pair(-153, 47), Pair(-142, 58), Pair(-98, 44), Pair(-64, 29), Pair(-59, 26), Pair(-87, 21), Pair(-78, 27), Pair(-110, 12)
      },
      { // Piece 4
        Pair(-66, -76), Pair(-162, -66), Pair(9, -23), Pair(48, -111), Pair(-5, 35), Pair(47, 41), Pair(-3, 21), Pair(-2, 2),
        Pair(-158, -6), Pair(-47, 24), Pair(-66, -23), Pair(-181, 161), Pair(-116, 123), Pair(-74, 33), Pair(30, 9), Pair(-37, 108),
        Pair(-126, -51), Pair(-156, 69), Pair(52, -104), Pair(-98, 64), Pair(-27, -1), Pair(40, 54), Pair(-73, -54), Pair(31, -89),
        Pair(-135, 36), Pair(-112, 107), Pair(-149, 65), Pair(-30, 42), Pair(-113, -4), Pair(-44, -10), Pair(-98, -8), Pair(-27, -40),
        Pair(-214, -96), Pair(-112, 62), Pair(-195, 16), Pair(-72, 106), Pair(-63, 64), Pair(-107, 26), Pair(-61, 28), Pair(48, -175),
        Pair(-234, -76), Pair(-116, -66), Pair(-48, 7), Pair(-170, 131), Pair(-46, 48), Pair(-1, -84), Pair(-73, -142), Pair(-41, 36),
        Pair(-213, -9), Pair(-116, 1), Pair(-192, 29), Pair(-154, 71), Pair(-103, 23), Pair(-63, -100), Pair(-101, -35), Pair(-164, -36),
        Pair(-208, -48), Pair(-46, -153), Pair(-116, 27), Pair(-46, -132), Pair(12, -67), Pair(-156, -49), Pair(-55, 55), Pair(-169, -158)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(63, -51), Pair(88, -25), Pair(-8, 2), Pair(-90, 35), Pair(-54, 14), Pair(-55, 6), Pair(6, -21), Pair(-63, -35),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 103), Pair(60, 2), Pair(248, -120), Pair(110, -187), Pair(69, -129), Pair(145, -111), Pair(89, 140), Pair(-82, 32),
        Pair(-71, 52), Pair(102, 47), Pair(112, -26), Pair(47, -43), Pair(96, -53), Pair(203, -26), Pair(195, -31), Pair(14, 32),
        Pair(-162, 53), Pair(4, 36), Pair(36, -9), Pair(-13, -17), Pair(47, -34), Pair(64, -14), Pair(-20, 12), Pair(4, -7),
        Pair(-43, 15), Pair(-93, 45), Pair(39, -19), Pair(43, -24), Pair(7, -4), Pair(6, -20), Pair(-105, 31), Pair(-88, -1),
        Pair(-103, 6), Pair(-53, 20), Pair(-26, -10), Pair(-54, 6), Pair(2, -17), Pair(-63, 5), Pair(-63, 20), Pair(-84, 4),
        Pair(-105, 26), Pair(-83, 36), Pair(-24, 8), Pair(-66, 11), Pair(6, -6), Pair(-64, 8), Pair(-51, 12), Pair(-103, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-157, -73), Pair(-21, -76), Pair(76, -7), Pair(-9, 11), Pair(26, -47), Pair(-28, 9), Pair(16, -57), Pair(-270, -153),
        Pair(-51, -73), Pair(-31, 30), Pair(12, -74), Pair(-44, -4), Pair(-10, -53), Pair(-13, 23), Pair(99, 93), Pair(2, 0),
        Pair(54, -21), Pair(-102, 25), Pair(74, -19), Pair(78, -9), Pair(103, -5), Pair(113, -37), Pair(92, -53), Pair(115, -53),
        Pair(-11, 48), Pair(22, 10), Pair(1, 11), Pair(99, -13), Pair(50, 18), Pair(128, -19), Pair(67, -31), Pair(40, -3),
        Pair(-76, 37), Pair(-65, -8), Pair(-6, -10), Pair(91, 8), Pair(30, 19), Pair(-2, 43), Pair(18, -17), Pair(27, -32),
        Pair(-83, -37), Pair(-150, 44), Pair(31, 16), Pair(-49, 0), Pair(-62, 34), Pair(-5, 4), Pair(-87, -19), Pair(-86, -45),
        Pair(-26, 8), Pair(7, -1), Pair(-87, 52), Pair(-68, 17), Pair(-46, 19), Pair(-24, 23), Pair(3, 15), Pair(-79, -93),
        Pair(-34, 55), Pair(-184, 21), Pair(-104, -45), Pair(44, 14), Pair(-133, 46), Pair(46, -2), Pair(2, -31), Pair(-20, 1)
      },
      { // Piece 2
        Pair(95, 21), Pair(-88, -20), Pair(-38, -124), Pair(-46, -35), Pair(41, 32), Pair(6, -32), Pair(-88, -3), Pair(130, 42),
        Pair(-67, -58), Pair(81, -97), Pair(-24, -16), Pair(-53, -74), Pair(-33, -79), Pair(93, -57), Pair(5, 2), Pair(71, -56),
        Pair(-4, 37), Pair(23, -59), Pair(87, -53), Pair(50, -15), Pair(130, -29), Pair(109, -14), Pair(115, 1), Pair(0, -28),
        Pair(-39, -47), Pair(-14, 10), Pair(93, -24), Pair(71, -23), Pair(96, -10), Pair(181, -43), Pair(30, -13), Pair(53, 13),
        Pair(20, -49), Pair(136, -36), Pair(51, -7), Pair(35, -60), Pair(143, -56), Pair(34, -31), Pair(201, -46), Pair(-102, -54),
        Pair(-52, 22), Pair(-61, 5), Pair(78, -58), Pair(0, 10), Pair(21, 4), Pair(23, -10), Pair(53, -25), Pair(-110, -20),
        Pair(-147, 36), Pair(0, 10), Pair(-22, 2), Pair(-45, -2), Pair(-115, 15), Pair(-14, 27), Pair(-18, -38), Pair(31, -77),
        Pair(3, -65), Pair(-46, -63), Pair(-23, -5), Pair(-32, -6), Pair(4, -82), Pair(-59, 19), Pair(-104, -69), Pair(-31, 5)
      },
      { // Piece 3
        Pair(26, 74), Pair(10, 18), Pair(27, 108), Pair(120, 106), Pair(34, 95), Pair(19, -24), Pair(56, 24), Pair(77, 96),
        Pair(17, 20), Pair(114, -3), Pair(104, 2), Pair(139, -1), Pair(160, -36), Pair(0, 30), Pair(35, 13), Pair(33, 16),
        Pair(150, -15), Pair(49, 1), Pair(60, 3), Pair(88, -48), Pair(10, -49), Pair(99, -45), Pair(11, 4), Pair(93, -15),
        Pair(-7, 16), Pair(-47, 64), Pair(-55, -3), Pair(59, -16), Pair(-7, -25), Pair(10, 4), Pair(-56, 33), Pair(-79, 25),
        Pair(64, 10), Pair(-84, 28), Pair(-48, 33), Pair(-21, 27), Pair(-64, 1), Pair(-138, 46), Pair(-41, -15), Pair(-58, -42),
        Pair(-15, -11), Pair(14, -9), Pair(-148, 39), Pair(-57, 4), Pair(-129, 21), Pair(47, -30), Pair(-113, -11), Pair(-43, 39),
        Pair(-59, 3), Pair(-46, 41), Pair(5, 0), Pair(-139, 71), Pair(-50, -9), Pair(-19, -10), Pair(-12, 31), Pair(-42, 12),
        Pair(-53, -15), Pair(-110, 29), Pair(-55, 11), Pair(-129, 29), Pair(-21, -19), Pair(-11, -19), Pair(-101, 46), Pair(-69, -1)
      },
      { // Piece 4
        Pair(-143, 60), Pair(-69, -20), Pair(-49, -21), Pair(51, 62), Pair(2, 9), Pair(79, 131), Pair(-15, 7), Pair(85, 71),
        Pair(-8, -4), Pair(-17, 8), Pair(-115, 92), Pair(-2, 8), Pair(-34, 1), Pair(-15, -29), Pair(-29, -43), Pair(118, -93),
        Pair(53, -3), Pair(-62, 2), Pair(46, -90), Pair(-74, 51), Pair(164, -92), Pair(85, -19), Pair(-94, -12), Pair(29, -18),
        Pair(38, -13), Pair(-31, 55), Pair(-98, -11), Pair(26, 59), Pair(-29, 9), Pair(-94, -59), Pair(52, -52), Pair(94, -45),
        Pair(-223, 60), Pair(2, 73), Pair(-116, 30), Pair(14, -7), Pair(-16, 33), Pair(39, 87), Pair(82, -63), Pair(-47, -86),
        Pair(-125, -36), Pair(-94, -15), Pair(-114, -51), Pair(15, -14), Pair(-43, 22), Pair(37, -27), Pair(-123, -31), Pair(-63, -75),
        Pair(-32, -58), Pair(-103, -72), Pair(-86, -122), Pair(-67, -51), Pair(-49, -26), Pair(-166, -7), Pair(-120, -5), Pair(-76, -115),
        Pair(-122, -112), Pair(-131, -75), Pair(-117, -93), Pair(-82, -118), Pair(-114, -15), Pair(-9, -24), Pair(-58, -97), Pair(30, -12)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, -50), Pair(48, -22), Pair(55, -15), Pair(-37, 17), Pair(1, 2), Pair(14, -22), Pair(27, -30), Pair(-42, -47),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(71, -29), Pair(102, -82), Pair(117, -54), Pair(70, -85), Pair(31, -70), Pair(15, -89), Pair(108, -72), Pair(274, -81),
        Pair(60, 9), Pair(128, 12), Pair(53, -24), Pair(182, -73), Pair(136, -74), Pair(93, -40), Pair(16, 4), Pair(-14, 19),
        Pair(-88, 38), Pair(21, 30), Pair(6, 0), Pair(36, -17), Pair(46, -4), Pair(3, 2), Pair(2, 19), Pair(-11, 10),
        Pair(-121, 34), Pair(-92, 43), Pair(-42, 9), Pair(-24, 2), Pair(-6, -1), Pair(-34, 7), Pair(-32, 21), Pair(-103, 13),
        Pair(-90, 17), Pair(-86, 28), Pair(-40, 6), Pair(-4, -8), Pair(-8, -1), Pair(-41, 1), Pair(-27, 12), Pair(-117, 12),
        Pair(-123, 34), Pair(-107, 38), Pair(20, -8), Pair(-114, 40), Pair(5, 10), Pair(-9, 2), Pair(4, 7), Pair(-142, 24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-51, -199), Pair(7, -67), Pair(-31, 0), Pair(-49, -39), Pair(117, -63), Pair(15, -63), Pair(-29, -22), Pair(-124, -153),
        Pair(-13, -42), Pair(-27, -11), Pair(-65, -23), Pair(65, -52), Pair(34, -73), Pair(18, -3), Pair(-40, -7), Pair(28, -82),
        Pair(-97, -15), Pair(22, -20), Pair(44, -25), Pair(86, -33), Pair(35, -22), Pair(66, -60), Pair(68, -39), Pair(-4, -24),
        Pair(-58, 0), Pair(-13, 2), Pair(32, -6), Pair(123, -38), Pair(88, -16), Pair(101, -15), Pair(47, -17), Pair(125, -73),
        Pair(-64, 1), Pair(30, 5), Pair(39, 3), Pair(41, 3), Pair(20, 0), Pair(129, -10), Pair(70, -20), Pair(71, 15),
        Pair(-159, 35), Pair(-79, 16), Pair(9, 3), Pair(58, -5), Pair(50, 1), Pair(5, -6), Pair(-34, 34), Pair(-65, 22),
        Pair(-72, 20), Pair(-76, 17), Pair(-52, -8), Pair(-54, 17), Pair(-27, 7), Pair(-81, 34), Pair(5, -40), Pair(-69, 46),
        Pair(-69, -21), Pair(-191, -1), Pair(-121, 4), Pair(-86, 9), Pair(-70, 6), Pair(-153, 37), Pair(-139, 62), Pair(-82, 33)
      },
      { // Piece 2
        Pair(-20, -23), Pair(-57, -38), Pair(-24, -45), Pair(-41, -22), Pair(74, -83), Pair(-78, -38), Pair(54, -40), Pair(-32, -77),
        Pair(-31, -43), Pair(61, -38), Pair(-26, -22), Pair(-2, -55), Pair(23, -52), Pair(151, -60), Pair(-60, -18), Pair(51, -58),
        Pair(-34, -15), Pair(30, -53), Pair(71, -33), Pair(114, -58), Pair(135, -91), Pair(50, -31), Pair(-28, -43), Pair(15, -26),
        Pair(1, -25), Pair(-13, -28), Pair(148, -54), Pair(196, -67), Pair(26, -14), Pair(60, -25), Pair(68, -47), Pair(-32, -30),
        Pair(-124, -38), Pair(54, -53), Pair(-12, -38), Pair(46, -40), Pair(-15, -33), Pair(44, -44), Pair(25, -60), Pair(155, -68),
        Pair(-103, 12), Pair(6, -27), Pair(0, -19), Pair(31, -16), Pair(42, -19), Pair(9, -34), Pair(37, -16), Pair(-70, -20),
        Pair(16, -18), Pair(-4, -17), Pair(1, -25), Pair(-14, -29), Pair(-28, -26), Pair(-61, -18), Pair(53, -41), Pair(-52, -18),
        Pair(-77, -35), Pair(-81, -52), Pair(-64, -8), Pair(-59, -4), Pair(-27, -28), Pair(-49, 6), Pair(-42, -57), Pair(104, 8)
      },
      { // Piece 3
        Pair(-45, -19), Pair(-44, 1), Pair(-72, 5), Pair(-55, -31), Pair(-5, -13), Pair(59, -31), Pair(38, -30), Pair(110, -49),
        Pair(27, -28), Pair(-40, -10), Pair(-14, -22), Pair(71, -51), Pair(83, -45), Pair(-107, -5), Pair(81, -52), Pair(-48, -58),
        Pair(4, -31), Pair(39, -26), Pair(41, -26), Pair(97, -49), Pair(76, -55), Pair(110, -62), Pair(48, -41), Pair(34, -43),
        Pair(19, -16), Pair(2, -15), Pair(27, -21), Pair(58, -46), Pair(13, -40), Pair(64, -56), Pair(97, -65), Pair(-5, -43),
        Pair(-45, -30), Pair(-56, -12), Pair(-62, -22), Pair(-76, -28), Pair(-13, -44), Pair(-66, -39), Pair(-18, -40), Pair(-42, -45),
        Pair(-37, -30), Pair(-20, -14), Pair(-112, -10), Pair(-103, -3), Pair(-68, -24), Pair(-13, -50), Pair(-67, -20), Pair(-95, -13),
        Pair(-163, -4), Pair(-135, 5), Pair(-62, -18), Pair(-8, -29), Pair(-2, -53), Pair(-52, -28), Pair(-55, -47), Pair(-54, -36),
        Pair(-94, -19), Pair(-84, -14), Pair(-160, 7), Pair(-92, -15), Pair(-17, -46), Pair(-12, -56), Pair(-135, 3), Pair(-182, -4)
      },
      { // Piece 4
        Pair(-41, -67), Pair(1, -97), Pair(-113, -9), Pair(-105, -37), Pair(-14, -85), Pair(-93, -64), Pair(18, -27), Pair(-224, 11),
        Pair(-27, -60), Pair(-38, -73), Pair(-45, -17), Pair(-66, -11), Pair(-60, -81), Pair(-109, -73), Pair(-123, 21), Pair(-71, -123),
        Pair(-80, -118), Pair(-39, -49), Pair(-63, -20), Pair(-74, -10), Pair(26, -54), Pair(-82, -83), Pair(-99, -119), Pair(-16, -97),
        Pair(-156, -20), Pair(-89, -96), Pair(-104, -22), Pair(9, -41), Pair(56, -53), Pair(-67, -35), Pair(-25, -129), Pair(77, -128),
        Pair(-79, -112), Pair(-120, -115), Pair(-211, 56), Pair(-116, -6), Pair(-41, -63), Pair(-70, -13), Pair(-37, -132), Pair(-78, -141),
        Pair(-142, -112), Pair(-211, 68), Pair(-92, -21), Pair(-108, 38), Pair(-135, -5), Pair(-71, -69), Pair(-188, -15), Pair(-37, -121),
        Pair(-154, -60), Pair(-122, -56), Pair(-45, -61), Pair(-194, -7), Pair(-46, -36), Pair(-67, -70), Pair(-112, -53), Pair(-103, -58),
        Pair(-57, -125), Pair(-83, -213), Pair(-106, -125), Pair(-23, -155), Pair(-190, -11), Pair(-107, -10), Pair(-220, -172), Pair(-154, -88)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, -45), Pair(28, -17), Pair(-1, 2), Pair(-46, 17), Pair(-42, 17), Pair(-8, -2), Pair(1, -18), Pair(-103, -24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(123, -59), Pair(66, -71), Pair(43, -61), Pair(105, -87), Pair(94, -88), Pair(19, -80), Pair(99, -32), Pair(79, -47),
        Pair(-43, 21), Pair(21, 33), Pair(112, -25), Pair(139, -39), Pair(206, -39), Pair(146, -26), Pair(142, -3), Pair(46, 25),
        Pair(-127, 45), Pair(-81, 42), Pair(-12, 9), Pair(-1, 0), Pair(-28, 7), Pair(61, -6), Pair(-39, 38), Pair(-62, 35),
        Pair(-124, 44), Pair(-84, 51), Pair(-98, 35), Pair(-117, 44), Pair(-50, 31), Pair(-62, 29), Pair(-87, 53), Pair(-139, 37),
        Pair(-156, 34), Pair(-96, 38), Pair(-59, 12), Pair(-59, 14), Pair(-35, 10), Pair(-66, 15), Pair(-86, 29), Pair(-159, 34),
        Pair(-195, 55), Pair(-164, 57), Pair(-108, 25), Pair(-16, 6), Pair(-16, 29), Pair(-31, 12), Pair(-95, 43), Pair(-208, 55),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-135, -126), Pair(7, -73), Pair(-135, -35), Pair(-97, -28), Pair(-17, -25), Pair(29, -36), Pair(-28, -66), Pair(-58, -63),
        Pair(-22, 21), Pair(-1, -22), Pair(54, -3), Pair(9, 3), Pair(106, -37), Pair(-117, -20), Pair(-95, -22), Pair(0, -18),
        Pair(97, -17), Pair(-42, -32), Pair(-14, 18), Pair(63, -48), Pair(-72, 26), Pair(57, -38), Pair(40, 1), Pair(-20, -26),
        Pair(125, -15), Pair(40, -18), Pair(62, -11), Pair(27, -21), Pair(55, -19), Pair(88, -9), Pair(197, -53), Pair(42, -31),
        Pair(-56, 3), Pair(-36, 10), Pair(7, 11), Pair(-8, 10), Pair(48, -4), Pair(-22, -13), Pair(31, -8), Pair(37, -2),
        Pair(-17, -11), Pair(-62, 23), Pair(-7, -2), Pair(33, 24), Pair(12, 27), Pair(-4, 16), Pair(-19, 18), Pair(-61, 17),
        Pair(-52, 26), Pair(-53, 23), Pair(-85, 27), Pair(26, -17), Pair(-67, 31), Pair(-27, 18), Pair(-56, -47), Pair(64, -8),
        Pair(-73, -47), Pair(-120, 15), Pair(-71, 13), Pair(-9, 11), Pair(-59, 21), Pair(-64, 4), Pair(-140, 38), Pair(-22, -25)
      },
      { // Piece 2
        Pair(-1, -47), Pair(58, -24), Pair(14, -32), Pair(-14, -43), Pair(-85, -25), Pair(33, -39), Pair(-23, -28), Pair(-80, -15),
        Pair(59, -51), Pair(34, -33), Pair(58, -29), Pair(41, -31), Pair(9, -31), Pair(-42, -9), Pair(-18, -40), Pair(-124, -7),
        Pair(-24, -6), Pair(56, -32), Pair(131, -35), Pair(149, -47), Pair(135, -66), Pair(100, -30), Pair(66, -25), Pair(15, -29),
        Pair(-20, -8), Pair(-11, -28), Pair(-17, -17), Pair(98, -43), Pair(132, -61), Pair(150, -54), Pair(31, -39), Pair(-24, -42),
        Pair(-19, 8), Pair(36, -22), Pair(10, -29), Pair(78, -36), Pair(66, -45), Pair(-25, -16), Pair(18, -11), Pair(24, 4),
        Pair(-113, -1), Pair(-28, -7), Pair(-44, 0), Pair(46, -25), Pair(-4, 4), Pair(24, -9), Pair(66, -12), Pair(-53, 22),
        Pair(-21, 39), Pair(-75, -10), Pair(-1, -18), Pair(57, -13), Pair(-24, 13), Pair(-1, -31), Pair(-48, -31), Pair(-129, 39),
        Pair(-136, 20), Pair(-35, -16), Pair(-104, -5), Pair(4, -2), Pair(3, -11), Pair(-79, -14), Pair(-36, -4), Pair(-52, -4)
      },
      { // Piece 3
        Pair(-9, -11), Pair(57, -6), Pair(67, 2), Pair(-2, -5), Pair(-31, -4), Pair(143, -57), Pair(114, -33), Pair(36, -22),
        Pair(100, -40), Pair(7, -12), Pair(52, -30), Pair(53, -46), Pair(32, -43), Pair(89, -41), Pair(30, -31), Pair(39, -34),
        Pair(-19, -29), Pair(62, -27), Pair(4, -17), Pair(105, -53), Pair(76, -30), Pair(73, -28), Pair(105, -35), Pair(-91, 7),
        Pair(-23, -18), Pair(-15, 3), Pair(37, -29), Pair(38, -19), Pair(76, -42), Pair(103, -59), Pair(47, -12), Pair(-21, -22),
        Pair(-46, -20), Pair(-11, -22), Pair(25, -27), Pair(-27, -20), Pair(-50, -29), Pair(-20, -30), Pair(57, -54), Pair(-84, -20),
        Pair(-87, -20), Pair(-109, 2), Pair(-120, -14), Pair(-44, -20), Pair(-2, -32), Pair(-87, -30), Pair(-137, -14), Pair(-118, -26),
        Pair(-145, 9), Pair(-39, -4), Pair(-69, -18), Pair(-71, -18), Pair(-37, -23), Pair(-50, -14), Pair(-23, -54), Pair(-208, -2),
        Pair(-125, 14), Pair(-88, -6), Pair(-65, -15), Pair(-18, -40), Pair(-119, -8), Pair(-58, -15), Pair(-142, 10), Pair(-101, 11)
      },
      { // Piece 4
        Pair(36, -29), Pair(-119, -90), Pair(-59, -63), Pair(-29, -44), Pair(-37, -23), Pair(-53, -17), Pair(5, -96), Pair(-23, -31),
        Pair(-54, -102), Pair(-5, -102), Pair(-172, -28), Pair(-11, 26), Pair(116, 29), Pair(-27, -39), Pair(-79, -88), Pair(-70, -81),
        Pair(-6, 22), Pair(8, -69), Pair(-39, -13), Pair(-22, -36), Pair(-9, -45), Pair(83, 85), Pair(21, 21), Pair(32, 29),
        Pair(-58, -50), Pair(-96, -38), Pair(-34, -50), Pair(10, -44), Pair(12, -46), Pair(8, 54), Pair(-28, 17), Pair(-5, -59),
        Pair(-58, -41), Pair(-9, -66), Pair(-13, -89), Pair(-57, -6), Pair(-87, -113), Pair(-68, -26), Pair(10, -56), Pair(-52, -91),
        Pair(-36, -141), Pair(-58, -82), Pair(-67, 2), Pair(-16, -30), Pair(-71, -53), Pair(-48, -74), Pair(-85, -36), Pair(-68, -97),
        Pair(-83, -127), Pair(-77, -29), Pair(-11, -42), Pair(-93, -89), Pair(-100, 7), Pair(-98, -99), Pair(10, -68), Pair(-60, -62),
        Pair(-27, -115), Pair(-70, -142), Pair(-100, -4), Pair(-126, -93), Pair(-4, -63), Pair(-125, -114), Pair(-54, -68), Pair(-64, -90)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(22, -47), Pair(69, -25), Pair(-8, 13), Pair(-16, 24), Pair(-49, 20), Pair(-4, 5), Pair(-17, -12), Pair(-14, -45),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-57, 3), Pair(96, -115), Pair(39, 64), Pair(73, 26), Pair(12, 25), Pair(-48, 53), Pair(-15, 85), Pair(-7, 6),
        Pair(10, 68), Pair(17, 87), Pair(109, 13), Pair(2, 39), Pair(76, 47), Pair(27, 5), Pair(-34, 59), Pair(-6, 68),
        Pair(-135, 42), Pair(30, 21), Pair(-13, 16), Pair(-22, 29), Pair(-9, 24), Pair(107, -12), Pair(-86, 58), Pair(-31, 22),
        Pair(-75, 20), Pair(-126, 50), Pair(-27, 25), Pair(-74, 29), Pair(-29, 19), Pair(-28, 12), Pair(-26, 37), Pair(-54, 28),
        Pair(-151, 30), Pair(-48, 35), Pair(-14, 8), Pair(-41, 42), Pair(-75, 31), Pair(13, 3), Pair(-52, 32), Pair(-154, 36),
        Pair(-157, 41), Pair(-174, 55), Pair(-123, 25), Pair(12, -10), Pair(-81, 10), Pair(-92, 25), Pair(-33, 25), Pair(-138, 53),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-92, -259), Pair(-27, -116), Pair(54, -63), Pair(3, -119), Pair(-5, -53), Pair(-45, -92), Pair(-59, -53), Pair(-50, -101),
        Pair(-91, -98), Pair(-29, -28), Pair(-21, -56), Pair(59, -100), Pair(-17, -58), Pair(31, -8), Pair(21, -43), Pair(-80, -113),
        Pair(0, -55), Pair(103, -67), Pair(67, -94), Pair(3, -41), Pair(33, -59), Pair(-95, -22), Pair(101, -109), Pair(34, -53),
        Pair(-11, -67), Pair(88, -84), Pair(12, -53), Pair(17, -37), Pair(138, -72), Pair(80, -44), Pair(75, -44), Pair(33, -9),
        Pair(-34, -83), Pair(3, -67), Pair(-18, -29), Pair(93, -55), Pair(31, -61), Pair(14, -42), Pair(68, -2), Pair(95, -16),
        Pair(-105, -46), Pair(18, -104), Pair(70, -23), Pair(-22, -27), Pair(12, -39), Pair(50, -64), Pair(-42, -75), Pair(32, 27),
        Pair(-67, -23), Pair(-3, -27), Pair(-87, -69), Pair(-12, -58), Pair(9, -22), Pair(26, -22), Pair(4, -63), Pair(-34, -114),
        Pair(-33, -87), Pair(-59, -57), Pair(-64, -91), Pair(-17, -134), Pair(18, -86), Pair(-28, -85), Pair(-1, 33), Pair(9, -27)
      },
      { // Piece 2
        Pair(-68, -52), Pair(-47, -19), Pair(49, -77), Pair(23, -16), Pair(-78, -39), Pair(13, -79), Pair(9, -58), Pair(-82, -26),
        Pair(-16, -15), Pair(13, -50), Pair(-80, -39), Pair(-31, -70), Pair(-83, -56), Pair(-35, -74), Pair(8, -51), Pair(38, -22),
        Pair(42, -59), Pair(-1, -55), Pair(-9, -68), Pair(56, -26), Pair(42, -46), Pair(-18, -38), Pair(61, -86), Pair(31, -40),
        Pair(-93, -4), Pair(-11, -33), Pair(33, -64), Pair(97, -72), Pair(148, -41), Pair(136, -45), Pair(99, -73), Pair(29, -43),
        Pair(-80, -89), Pair(-7, -2), Pair(70, -64), Pair(0, -47), Pair(51, -54), Pair(39, -68), Pair(107, -11), Pair(-78, -80),
        Pair(-68, -15), Pair(93, -39), Pair(-2, -36), Pair(-20, -67), Pair(-56, -24), Pair(-67, -25), Pair(35, -2), Pair(-53, -28),
        Pair(-108, -41), Pair(-119, -20), Pair(-68, -27), Pair(5, -30), Pair(4, -59), Pair(-1, -49), Pair(-80, -20), Pair(-68, -11),
        Pair(1, 2), Pair(-89, -43), Pair(-42, 1), Pair(-42, -31), Pair(-82, -14), Pair(-85, 8), Pair(2, -39), Pair(0, 46)
      },
      { // Piece 3
        Pair(37, -71), Pair(43, -86), Pair(25, -82), Pair(129, -72), Pair(58, -52), Pair(59, -71), Pair(-7, -96), Pair(64, -79),
        Pair(-94, -62), Pair(-25, -55), Pair(-27, -49), Pair(74, -109), Pair(-1, -55), Pair(68, -77), Pair(13, -64), Pair(28, -120),
        Pair(-23, -81), Pair(-10, -67), Pair(68, -102), Pair(33, -78), Pair(40, -116), Pair(-52, -89), Pair(-47, -63), Pair(-70, -94),
        Pair(-84, -102), Pair(37, -92), Pair(-8, -149), Pair(58, -52), Pair(-28, -134), Pair(51, -110), Pair(57, -56), Pair(-51, -30),
        Pair(53, -100), Pair(-54, -77), Pair(-85, -69), Pair(0, -104), Pair(45, -100), Pair(-50, -44), Pair(28, -94), Pair(-61, -105),
        Pair(-18, -69), Pair(78, -102), Pair(-38, -105), Pair(-134, -62), Pair(-1, -93), Pair(-30, -55), Pair(-25, -101), Pair(-48, -101),
        Pair(-26, -117), Pair(-151, -91), Pair(-52, -69), Pair(-28, -97), Pair(-51, -80), Pair(-49, -99), Pair(-101, -98), Pair(-12, -92),
        Pair(-152, -53), Pair(-44, -66), Pair(-47, -83), Pair(-58, -49), Pair(10, -107), Pair(-76, -71), Pair(5, -64), Pair(-15, -111)
      },
      { // Piece 4
        Pair(51, -21), Pair(9, -133), Pair(-55, -76), Pair(-45, -17), Pair(31, -24), Pair(-33, -5), Pair(-75, -145), Pair(-64, -42),
        Pair(10, -7), Pair(22, -32), Pair(24, -3), Pair(-14, -13), Pair(-38, -7), Pair(-57, -74), Pair(-39, -93), Pair(-68, -112),
        Pair(-73, -110), Pair(65, -3), Pair(2, 46), Pair(29, 40), Pair(-43, -48), Pair(46, -12), Pair(-52, -69), Pair(-27, -52),
        Pair(-45, -81), Pair(-29, -48), Pair(-31, -84), Pair(-14, -27), Pair(50, 88), Pair(-21, -47), Pair(7, -4), Pair(-29, -72),
        Pair(-72, -115), Pair(-18, -8), Pair(38, 101), Pair(-47, -69), Pair(0, -1), Pair(36, 57), Pair(-2, -4), Pair(-19, -40),
        Pair(-79, -154), Pair(10, 1), Pair(18, -1), Pair(-13, -62), Pair(5, 16), Pair(16, 49), Pair(-2, -21), Pair(-31, -30),
        Pair(-4, 22), Pair(-70, -116), Pair(-39, -45), Pair(17, 21), Pair(-43, -95), Pair(-114, -171), Pair(-31, -28), Pair(-9, -21),
        Pair(7, 6), Pair(-18, -79), Pair(-38, -54), Pair(-8, -29), Pair(-24, -55), Pair(-15, -76), Pair(-22, -57), Pair(-57, -99)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(100, -56), Pair(63, -23), Pair(-15, 20), Pair(-36, 24), Pair(-61, 34), Pair(13, 10), Pair(15, -8), Pair(-33, -25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-48, -5), Pair(-15, -31), Pair(-53, -18), Pair(-26, -36), Pair(-8, 5), Pair(-128, 65), Pair(-32, 42), Pair(-122, -12),
        Pair(-157, 77), Pair(-33, 113), Pair(-50, 79), Pair(-28, 75), Pair(-63, 112), Pair(-53, 69), Pair(62, 97), Pair(-184, 102),
        Pair(-157, 58), Pair(-38, 43), Pair(-39, 26), Pair(-58, 48), Pair(-31, 39), Pair(13, 29), Pair(-110, 38), Pair(-202, 53),
        Pair(-110, 34), Pair(-60, 56), Pair(-51, 19), Pair(-106, 53), Pair(-64, 36), Pair(-32, 25), Pair(-95, 37), Pair(-147, 40),
        Pair(-40, 14), Pair(-33, 30), Pair(-23, 6), Pair(-4, 16), Pair(-117, 17), Pair(-14, 11), Pair(-69, 25), Pair(-50, 17),
        Pair(-119, 47), Pair(-90, 55), Pair(1, 20), Pair(-4, -39), Pair(-32, 10), Pair(-1, 13), Pair(-105, 40), Pair(-166, 43),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-43, -216), Pair(-50, -66), Pair(-40, -129), Pair(-33, -62), Pair(-10, -61), Pair(-36, -61), Pair(-2, -70), Pair(-39, -155),
        Pair(-65, -80), Pair(-52, -49), Pair(-25, -72), Pair(-32, -90), Pair(-65, -115), Pair(-6, -111), Pair(-55, -54), Pair(-34, -97),
        Pair(-19, -114), Pair(76, -105), Pair(-42, -71), Pair(17, -76), Pair(11, -82), Pair(-38, -85), Pair(17, -111), Pair(41, -101),
        Pair(-5, -124), Pair(81, -86), Pair(141, -116), Pair(48, -89), Pair(23, -83), Pair(48, -50), Pair(69, -146), Pair(23, -121),
        Pair(-39, -87), Pair(11, -44), Pair(3, -50), Pair(87, -46), Pair(134, -100), Pair(19, -19), Pair(2, -83), Pair(49, -133),
        Pair(-14, -47), Pair(30, -70), Pair(77, -96), Pair(-13, -72), Pair(62, -67), Pair(55, -108), Pair(13, -80), Pair(40, -83),
        Pair(-21, -155), Pair(29, -120), Pair(-79, -106), Pair(118, -92), Pair(-12, -83), Pair(-47, -111), Pair(-25, -83), Pair(28, -177),
        Pair(19, -30), Pair(-53, -100), Pair(-15, -51), Pair(45, -82), Pair(-17, -142), Pair(35, -94), Pair(-33, -141), Pair(26, -50)
      },
      { // Piece 2
        Pair(-30, -60), Pair(-87, -23), Pair(38, -57), Pair(-33, 5), Pair(-72, -42), Pair(-102, -56), Pair(11, -44), Pair(-2, -79),
        Pair(-61, -66), Pair(56, -77), Pair(-71, -41), Pair(-57, 13), Pair(-87, -6), Pair(-57, -67), Pair(14, -60), Pair(-38, 30),
        Pair(-16, -49), Pair(-35, -43), Pair(13, -35), Pair(-71, -56), Pair(-85, -42), Pair(14, -22), Pair(-80, -53), Pair(-23, -36),
        Pair(-21, -28), Pair(-49, -40), Pair(-115, -31), Pair(41, -61), Pair(26, -21), Pair(9, -36), Pair(-76, -69), Pair(-43, -21),
        Pair(-38, -43), Pair(-52, -39), Pair(21, -27), Pair(11, -58), Pair(-73, -35), Pair(44, -22), Pair(17, 8), Pair(12, 27),
        Pair(27, -69), Pair(-96, -20), Pair(-44, -16), Pair(-67, -31), Pair(11, -41), Pair(-69, -10), Pair(-116, -33), Pair(-37, -50),
        Pair(-43, -48), Pair(-30, -99), Pair(-65, -78), Pair(-68, -32), Pair(-97, -48), Pair(-32, -67), Pair(-109, -51), Pair(6, -63),
        Pair(-68, -94), Pair(-56, 33), Pair(22, -23), Pair(-47, -11), Pair(-64, -45), Pair(-25, -44), Pair(-40, -80), Pair(19, -29)
      },
      { // Piece 3
        Pair(72, -129), Pair(-17, -108), Pair(46, -121), Pair(-27, -114), Pair(-62, -87), Pair(-100, -116), Pair(-57, -75), Pair(-106, -118),
        Pair(-31, -125), Pair(73, -147), Pair(54, -118), Pair(-2, -110), Pair(-14, -132), Pair(10, -100), Pair(11, -101), Pair(99, -121),
        Pair(17, -113), Pair(-34, -91), Pair(-18, -101), Pair(38, -134), Pair(-33, -101), Pair(25, -116), Pair(39, -99), Pair(10, -117),
        Pair(55, -130), Pair(-31, -113), Pair(28, -137), Pair(0, -117), Pair(-5, -116), Pair(71, -131), Pair(52, -143), Pair(60, -126),
        Pair(-1, -118), Pair(-98, -101), Pair(-25, -137), Pair(-14, -176), Pair(31, -117), Pair(25, -109), Pair(-7, -72), Pair(-30, -128),
        Pair(-11, -136), Pair(-35, -103), Pair(-61, -82), Pair(55, -102), Pair(-45, -141), Pair(-150, -93), Pair(-1, -129), Pair(33, -146),
        Pair(-75, -90), Pair(23, -146), Pair(-2, -112), Pair(-20, -120), Pair(-13, -139), Pair(-49, -138), Pair(-27, -127), Pair(-53, -111),
        Pair(3, -119), Pair(117, -111), Pair(-79, -65), Pair(-3, -98), Pair(73, -116), Pair(-53, -125), Pair(-114, -72), Pair(-36, -118)
      },
      { // Piece 4
        Pair(-79, -173), Pair(-94, -120), Pair(0, -160), Pair(15, -23), Pair(10, -125), Pair(-73, -104), Pair(-60, -159), Pair(-59, -162),
        Pair(-47, -113), Pair(-39, -63), Pair(34, -47), Pair(-51, -50), Pair(13, -70), Pair(-68, -44), Pair(-64, -143), Pair(-88, -148),
        Pair(-111, -146), Pair(-6, -6), Pair(-40, -66), Pair(21, -44), Pair(-11, -49), Pair(68, 50), Pair(-40, -22), Pair(-31, -63),
        Pair(-78, -132), Pair(9, -83), Pair(-76, -48), Pair(-22, -76), Pair(-9, -41), Pair(-10, -4), Pair(-73, -92), Pair(-35, -31),
        Pair(21, 8), Pair(-27, -78), Pair(-90, -84), Pair(-80, -99), Pair(-36, -46), Pair(-35, -66), Pair(-30, -72), Pair(3, 11),
        Pair(-37, -76), Pair(-31, -100), Pair(-86, -156), Pair(17, 13), Pair(15, 22), Pair(-9, -44), Pair(-12, -28), Pair(-6, -32),
        Pair(33, -20), Pair(26, 27), Pair(-41, -93), Pair(-42, -110), Pair(-15, -46), Pair(1, 0), Pair(-48, -104), Pair(2, -19),
        Pair(-85, -172), Pair(-7, -19), Pair(-83, -176), Pair(-32, -104), Pair(-48, -66), Pair(-23, -125), Pair(-26, -40), Pair(-14, -39)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(31, -62), Pair(124, -27), Pair(-47, 19), Pair(-61, 35), Pair(-16, 24), Pair(35, 13), Pair(-51, 5), Pair(-78, -18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-106, 35), Pair(-65, 47), Pair(-13, 2), Pair(-28, 63), Pair(-89, 71), Pair(-70, 61), Pair(-22, 57), Pair(-125, 89),
        Pair(-147, 113), Pair(-1, 149), Pair(-31, 114), Pair(-18, 113), Pair(0, 136), Pair(-15, 84), Pair(-21, 109), Pair(-77, 93),
        Pair(-106, 71), Pair(21, 112), Pair(-181, 70), Pair(-108, 36), Pair(-126, 53), Pair(55, 61), Pair(-53, 61), Pair(-160, 68),
        Pair(-45, 50), Pair(-77, 52), Pair(-32, 73), Pair(-41, 66), Pair(2, 33), Pair(14, 25), Pair(-167, 51), Pair(-164, 48),
        Pair(-69, 45), Pair(40, 0), Pair(-23, 49), Pair(-86, 49), Pair(-122, 44), Pair(80, -10), Pair(-44, 26), Pair(-54, 18),
        Pair(-85, 22), Pair(-74, 52), Pair(80, 41), Pair(-13, 25), Pair(-42, -9), Pair(-22, 29), Pair(-12, 29), Pair(-66, 32),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-26, -229), Pair(-30, -107), Pair(4, 40), Pair(18, -24), Pair(-12, -48), Pair(-17, -77), Pair(-21, -51), Pair(-3, -15),
        Pair(-9, -165), Pair(3, -104), Pair(-29, -40), Pair(-15, -70), Pair(-13, -67), Pair(4, -70), Pair(-40, -62), Pair(-12, -152),
        Pair(-57, -179), Pair(-46, -59), Pair(18, -115), Pair(-63, -51), Pair(-9, -81), Pair(61, -85), Pair(31, -46), Pair(-27, -101),
        Pair(11, -28), Pair(2, -36), Pair(26, -71), Pair(43, -111), Pair(-3, -71), Pair(69, -47), Pair(-15, -102), Pair(-54, -71),
        Pair(-51, -135), Pair(-15, -75), Pair(7, 39), Pair(131, -72), Pair(12, -12), Pair(5, -80), Pair(-13, -57), Pair(25, -34),
        Pair(-5, -67), Pair(-2, -8), Pair(-61, 10), Pair(39, -84), Pair(41, 6), Pair(-12, -94), Pair(24, -42), Pair(16, -76),
        Pair(-4, -56), Pair(0, -48), Pair(-27, -75), Pair(-10, -85), Pair(-6, -120), Pair(-40, -146), Pair(9, -6), Pair(-20, -53),
        Pair(-8, -97), Pair(-15, -80), Pair(-34, -134), Pair(0, -74), Pair(25, -34), Pair(-17, -210), Pair(-25, -46), Pair(-6, -36)
      },
      { // Piece 2
        Pair(-6, -71), Pair(16, 18), Pair(-49, -16), Pair(-56, -73), Pair(10, -18), Pair(-30, -27), Pair(43, -4), Pair(-9, -22),
        Pair(21, 76), Pair(-15, -21), Pair(37, 38), Pair(-6, -56), Pair(-57, -65), Pair(37, 4), Pair(-72, 3), Pair(-38, -46),
        Pair(-15, 30), Pair(-39, -2), Pair(-88, -76), Pair(-52, -39), Pair(-32, -7), Pair(91, -57), Pair(23, -27), Pair(34, -7),
        Pair(-5, -55), Pair(16, -77), Pair(7, 18), Pair(-48, -6), Pair(-55, -60), Pair(-27, -43), Pair(-37, -19), Pair(-20, 16),
        Pair(-6, -53), Pair(-53, -24), Pair(24, -31), Pair(51, -83), Pair(-12, -4), Pair(-14, -20), Pair(13, -26), Pair(-10, -5),
        Pair(-64, 9), Pair(9, 48), Pair(41, -14), Pair(47, -32), Pair(-63, 25), Pair(-39, 34), Pair(31, -28), Pair(11, 68),
        Pair(-11, 56), Pair(16, 11), Pair(-27, 39), Pair(-11, 5), Pair(34, -18), Pair(-25, -44), Pair(28, -14), Pair(-3, -36),
        Pair(1, -25), Pair(-9, 53), Pair(-9, -46), Pair(-19, 1), Pair(18, -52), Pair(-9, -61), Pair(-2, 23), Pair(-13, -91)
      },
      { // Piece 3
        Pair(-4, -77), Pair(26, -41), Pair(43, -81), Pair(-34, -64), Pair(-33, -108), Pair(30, -19), Pair(-3, -55), Pair(-33, -92),
        Pair(37, -80), Pair(-96, -89), Pair(15, -121), Pair(-24, -105), Pair(64, -123), Pair(26, -84), Pair(1, -36), Pair(-3, -102),
        Pair(-25, -68), Pair(17, -67), Pair(-40, -80), Pair(-83, -45), Pair(-68, -65), Pair(-99, -62), Pair(-15, -104), Pair(18, -90),
        Pair(-49, -36), Pair(49, -72), Pair(17, -63), Pair(54, -81), Pair(4, -90), Pair(37, -75), Pair(-6, -60), Pair(-39, -88),
        Pair(16, -93), Pair(-21, -101), Pair(-40, 11), Pair(-19, -119), Pair(-1, -94), Pair(-90, -72), Pair(9, -68), Pair(48, -159),
        Pair(-66, -32), Pair(-65, -8), Pair(-8, -91), Pair(17, -128), Pair(8, -96), Pair(36, -70), Pair(-27, -98), Pair(7, -128),
        Pair(72, -42), Pair(49, -1), Pair(14, -80), Pair(46, -100), Pair(22, -106), Pair(-29, -64), Pair(-3, -141), Pair(-5, -50),
        Pair(-43, -34), Pair(30, -78), Pair(-41, -23), Pair(-44, -132), Pair(11, -117), Pair(31, -26), Pair(103, -38), Pair(-10, -75)
      },
      { // Piece 4
        Pair(-98, -56), Pair(-80, -92), Pair(-8, 56), Pair(-45, -12), Pair(-30, -28), Pair(-80, -101), Pair(-54, -166), Pair(-69, -125),
        Pair(-29, -46), Pair(4, -34), Pair(-42, -107), Pair(-62, -88), Pair(-7, 52), Pair(-71, -102), Pair(6, -4), Pair(-63, -94),
        Pair(14, -49), Pair(-61, -145), Pair(66, 88), Pair(-52, -52), Pair(-14, -31), Pair(-20, 0), Pair(-63, -92), Pair(-52, -74),
        Pair(-4, -18), Pair(-69, -88), Pair(2, -17), Pair(-19, -45), Pair(35, 53), Pair(-30, -50), Pair(-21, 4), Pair(-20, 42),
        Pair(6, -17), Pair(-56, -145), Pair(-34, -84), Pair(-7, -57), Pair(21, -9), Pair(26, 11), Pair(-43, -57), Pair(-22, -53),
        Pair(-45, -107), Pair(-18, -25), Pair(21, 42), Pair(4, -42), Pair(52, 32), Pair(-32, -18), Pair(-28, -68), Pair(0, -44),
        Pair(4, 5), Pair(-26, -54), Pair(-22, -60), Pair(-2, -26), Pair(30, 53), Pair(-66, -124), Pair(-17, -32), Pair(4, -1),
        Pair(-39, -89), Pair(-55, -101), Pair(-31, -78), Pair(-29, -60), Pair(-16, -14), Pair(-6, -57), Pair(32, 39), Pair(-54, -83)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-73, -18), Pair(68, 7), Pair(53, 41), Pair(46, 52), Pair(-74, 60), Pair(-69, 72), Pair(-12, 36), Pair(-124, 40),
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
        Pair(217, -45), Pair(166, -62), Pair(198, 209), Pair(53, 79), Pair(-164, 150), Pair(105, 114), Pair(0, -124), Pair(12, -98),
        Pair(167, -39), Pair(69, 48), Pair(-13, 98), Pair(-91, 95), Pair(50, 68), Pair(55, 21), Pair(161, -49), Pair(96, -35),
        Pair(-106, 52), Pair(-31, 76), Pair(3, 50), Pair(-40, 43), Pair(-6, 12), Pair(45, -6), Pair(-8, -10), Pair(-21, -8),
        Pair(-137, 55), Pair(-60, 54), Pair(-57, 33), Pair(-44, 5), Pair(-107, 18), Pair(-30, 6), Pair(-56, 12), Pair(7, -27),
        Pair(-110, 26), Pair(-95, 26), Pair(-58, 14), Pair(-18, -18), Pair(-29, 9), Pair(-49, 16), Pair(-116, 33), Pair(-19, -13),
        Pair(-112, 17), Pair(-74, 26), Pair(-40, 24), Pair(-157, 3), Pair(-151, 33), Pair(-73, -2), Pair(-46, 4), Pair(-28, -13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-96, -175), Pair(20, -20), Pair(69, -27), Pair(6, -96), Pair(-49, -46), Pair(-11, -52), Pair(-22, -81), Pair(-2, 9),
        Pair(36, -87), Pair(152, -25), Pair(38, -63), Pair(-9, -32), Pair(227, -86), Pair(-23, 38), Pair(-26, -31), Pair(-39, 10),
        Pair(11, -77), Pair(16, 20), Pair(97, -79), Pair(127, -13), Pair(240, -61), Pair(190, -28), Pair(135, -4), Pair(26, -51),
        Pair(-32, -71), Pair(21, -58), Pair(93, -10), Pair(56, -32), Pair(110, -37), Pair(145, -27), Pair(66, 6), Pair(142, -46),
        Pair(-124, 5), Pair(-47, -20), Pair(65, -34), Pair(55, -44), Pair(179, -2), Pair(38, -37), Pair(84, 8), Pair(55, -38),
        Pair(-32, -149), Pair(-71, -53), Pair(10, 11), Pair(-68, 22), Pair(-18, -27), Pair(107, -42), Pair(44, -47), Pair(-90, -84),
        Pair(-88, -149), Pair(-99, -67), Pair(-54, -96), Pair(-137, -41), Pair(-77, -13), Pair(-14, -107), Pair(33, -77), Pair(-45, -79),
        Pair(-26, -42), Pair(-45, -86), Pair(-144, -118), Pair(-82, 46), Pair(-43, -53), Pair(-69, -105), Pair(-183, -12), Pair(-59, -35)
      },
      { // Piece 2
        Pair(-38, -4), Pair(34, -39), Pair(-13, -53), Pair(-47, -68), Pair(-67, 31), Pair(-10, -41), Pair(110, -62), Pair(-8, -51),
        Pair(-120, 9), Pair(19, -56), Pair(29, -25), Pair(24, -55), Pair(99, -92), Pair(47, 26), Pair(-51, -73), Pair(41, -57),
        Pair(47, -98), Pair(-18, -61), Pair(137, -92), Pair(111, -5), Pair(79, -85), Pair(212, -33), Pair(229, -75), Pair(74, -13),
        Pair(-62, -19), Pair(0, -14), Pair(45, -44), Pair(200, -68), Pair(74, -47), Pair(116, -19), Pair(72, -71), Pair(-11, 5),
        Pair(-41, -14), Pair(23, -52), Pair(117, -49), Pair(89, -62), Pair(148, -94), Pair(-49, -19), Pair(162, -111), Pair(21, 10),
        Pair(-39, 12), Pair(92, 8), Pair(79, -85), Pair(-36, 8), Pair(84, -64), Pair(57, -110), Pair(146, -67), Pair(21, -45),
        Pair(34, -72), Pair(-131, -34), Pair(27, -73), Pair(-34, -69), Pair(-12, -23), Pair(-179, -20), Pair(-43, -33), Pair(-69, -95),
        Pair(-62, -27), Pair(-34, -32), Pair(-159, 25), Pair(-77, -56), Pair(-65, 12), Pair(-108, -39), Pair(-49, -90), Pair(-7, -32)
      },
      { // Piece 3
        Pair(49, 48), Pair(-70, -7), Pair(-40, 45), Pair(5, -46), Pair(-45, 27), Pair(52, 17), Pair(20, 49), Pair(19, 49),
        Pair(13, -27), Pair(18, -13), Pair(93, -17), Pair(176, -71), Pair(68, -56), Pair(16, -17), Pair(62, -30), Pair(122, -69),
        Pair(-42, -21), Pair(27, -38), Pair(73, -16), Pair(75, -24), Pair(86, -45), Pair(109, -85), Pair(75, -51), Pair(-96, -27),
        Pair(-7, 3), Pair(-60, -24), Pair(8, -7), Pair(97, -25), Pair(-62, -14), Pair(145, -97), Pair(-27, -40), Pair(31, -51),
        Pair(-140, 8), Pair(-63, 13), Pair(-69, -18), Pair(1, -50), Pair(-19, -21), Pair(-22, 9), Pair(-23, -13), Pair(-38, -20),
        Pair(-156, 7), Pair(-43, -9), Pair(-84, 31), Pair(26, -61), Pair(-25, -5), Pair(-96, -3), Pair(0, 26), Pair(-168, -23),
        Pair(-126, 40), Pair(-188, 13), Pair(-85, 6), Pair(-50, -1), Pair(-71, 7), Pair(-101, 2), Pair(-111, 20), Pair(-98, 21),
        Pair(-262, 56), Pair(-237, 49), Pair(-137, 25), Pair(-65, 4), Pair(-130, -2), Pair(-102, -3), Pair(-198, 13), Pair(-188, 8)
      },
      { // Piece 4
        Pair(-171, -140), Pair(-130, -76), Pair(-95, -62), Pair(43, 38), Pair(-20, -24), Pair(-72, 1), Pair(34, 64), Pair(-26, -46),
        Pair(-157, 37), Pair(-80, -80), Pair(-127, 61), Pair(-38, 28), Pair(-139, -54), Pair(86, -57), Pair(-55, -41), Pair(-21, -11),
        Pair(-71, -68), Pair(-72, -59), Pair(-13, -53), Pair(5, -100), Pair(31, 0), Pair(95, -102), Pair(-137, 8), Pair(68, -170),
        Pair(-138, -60), Pair(-87, 58), Pair(-30, -47), Pair(-4, -72), Pair(-68, -20), Pair(-84, -26), Pair(-123, -80), Pair(-153, -98),
        Pair(-166, 37), Pair(-46, -1), Pair(-177, -64), Pair(-79, 56), Pair(-130, 4), Pair(10, -58), Pair(-126, -31), Pair(-94, -37),
        Pair(-134, -105), Pair(-104, 8), Pair(-44, 32), Pair(-8, -123), Pair(-139, 9), Pair(-178, -1), Pair(-139, -27), Pair(-23, -71),
        Pair(-105, -51), Pair(-118, -76), Pair(-106, -43), Pair(-119, -82), Pair(-123, -129), Pair(-151, -66), Pair(-127, -77), Pair(-170, -225),
        Pair(-120, -130), Pair(-186, -172), Pair(-84, -149), Pair(-177, -20), Pair(-61, -60), Pair(-69, -97), Pair(-216, -145), Pair(-33, -38)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-102, -19), Pair(103, 14), Pair(2, 26), Pair(47, 6), Pair(-53, 20), Pair(64, 2), Pair(20, 12), Pair(-56, -28),
        Pair(11, -53), Pair(108, -32), Pair(51, -23), Pair(36, -15), Pair(-65, 5), Pair(-16, -1), Pair(-21, -14), Pair(-50, -55),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(53, 14), Pair(110, -71), Pair(227, -119), Pair(175, -166), Pair(183, -128), Pair(290, -78), Pair(3, 160), Pair(107, 38),
        Pair(3, 71), Pair(64, 37), Pair(150, -13), Pair(137, -36), Pair(144, -63), Pair(220, -52), Pair(137, -1), Pair(-30, 55),
        Pair(-129, 49), Pair(-86, 49), Pair(-36, 10), Pair(45, -12), Pair(30, -14), Pair(71, -14), Pair(-61, 38), Pair(-11, 19),
        Pair(-160, 27), Pair(-186, 56), Pair(7, -20), Pair(-31, -16), Pair(-121, 4), Pair(-57, -7), Pair(-64, 31), Pair(-133, 3),
        Pair(-169, 5), Pair(-129, 31), Pair(-95, 9), Pair(-139, 24), Pair(-15, -6), Pair(0, -18), Pair(23, -4), Pair(-73, -5),
        Pair(-153, 24), Pair(-134, 24), Pair(-9, -20), Pair(-38, -1), Pair(-38, -20), Pair(-44, 3), Pair(-108, 18), Pair(-148, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-44, -151), Pair(-15, -37), Pair(11, -53), Pair(12, -128), Pair(9, -104), Pair(2, -84), Pair(0, -45), Pair(-20, -5),
        Pair(-131, -80), Pair(61, 31), Pair(41, -14), Pair(-29, -81), Pair(2, -53), Pair(22, -64), Pair(-38, 22), Pair(-67, -13),
        Pair(22, -4), Pair(86, -37), Pair(108, -42), Pair(26, -35), Pair(61, -38), Pair(276, -93), Pair(-27, -21), Pair(23, -76),
        Pair(-41, 79), Pair(5, -28), Pair(74, -14), Pair(61, -10), Pair(41, -2), Pair(74, 21), Pair(81, -5), Pair(-71, -88),
        Pair(1, -1), Pair(-57, 23), Pair(121, -36), Pair(108, -20), Pair(109, -7), Pair(12, 7), Pair(88, -67), Pair(-7, -33),
        Pair(-75, -91), Pair(-115, -3), Pair(-36, -43), Pair(-10, -17), Pair(-118, 20), Pair(-40, -28), Pair(-20, -35), Pair(55, -48),
        Pair(-40, -69), Pair(-50, -26), Pair(-85, -58), Pair(-94, -35), Pair(-1, -30), Pair(0, -8), Pair(19, -71), Pair(-56, -115),
        Pair(-14, -43), Pair(-78, -30), Pair(-55, -20), Pair(-106, 6), Pair(26, -31), Pair(-124, -106), Pair(-143, 20), Pair(-17, -14)
      },
      { // Piece 2
        Pair(-58, -79), Pair(-18, -75), Pair(27, -42), Pair(-37, -103), Pair(9, -62), Pair(50, -79), Pair(16, -63), Pair(-18, -55),
        Pair(-46, -84), Pair(59, -26), Pair(72, -60), Pair(27, -37), Pair(21, -120), Pair(59, -92), Pair(45, -106), Pair(-48, -67),
        Pair(-4, -53), Pair(-10, -95), Pair(78, -57), Pair(89, -62), Pair(235, -133), Pair(257, -67), Pair(122, -64), Pair(97, -63),
        Pair(-13, -85), Pair(149, -94), Pair(140, -55), Pair(185, -97), Pair(230, -93), Pair(118, -77), Pair(50, -58), Pair(-2, -60),
        Pair(22, -53), Pair(0, -76), Pair(17, -56), Pair(61, -82), Pair(12, -76), Pair(69, -63), Pair(121, -101), Pair(19, -53),
        Pair(18, -44), Pair(54, -36), Pair(26, -64), Pair(32, -58), Pair(88, -60), Pair(62, -37), Pair(145, -53), Pair(41, -15),
        Pair(-67, -35), Pair(-81, -28), Pair(-51, -65), Pair(96, -60), Pair(2, -49), Pair(-80, -32), Pair(76, -76), Pair(-22, -19),
        Pair(46, -86), Pair(66, -124), Pair(-77, -17), Pair(-81, -12), Pair(-118, -20), Pair(-72, -25), Pair(-32, -93), Pair(15, -78)
      },
      { // Piece 3
        Pair(-46, -2), Pair(36, 89), Pair(-30, -25), Pair(-42, -28), Pair(-20, -48), Pair(-44, -45), Pair(-33, -39), Pair(57, -15),
        Pair(209, -73), Pair(191, -70), Pair(199, -80), Pair(208, -71), Pair(150, -94), Pair(192, -68), Pair(180, -71), Pair(73, -30),
        Pair(48, -19), Pair(67, -31), Pair(54, -76), Pair(49, -44), Pair(147, -96), Pair(174, -96), Pair(85, -47), Pair(17, -71),
        Pair(12, -46), Pair(-6, -18), Pair(22, -57), Pair(37, -71), Pair(-4, -62), Pair(128, -85), Pair(-155, -2), Pair(60, -80),
        Pair(-163, -5), Pair(-75, -44), Pair(21, -16), Pair(-1, -21), Pair(19, -51), Pair(-75, -26), Pair(98, -29), Pair(0, -14),
        Pair(-41, -56), Pair(-125, 11), Pair(26, -63), Pair(-15, -21), Pair(-70, -53), Pair(29, -56), Pair(20, -7), Pair(-28, -47),
        Pair(-48, -25), Pair(-123, -40), Pair(-152, -47), Pair(7, -22), Pair(-31, -52), Pair(39, 7), Pair(-29, -24), Pair(-47, -50),
        Pair(-156, -36), Pair(-211, 11), Pair(-150, -28), Pair(-75, -31), Pair(-150, -18), Pair(-92, -29), Pair(-141, -31), Pair(-143, -2)
      },
      { // Piece 4
        Pair(-152, -117), Pair(-115, -38), Pair(32, 13), Pair(2, 19), Pair(-34, -55), Pair(14, 10), Pair(21, 40), Pair(23, 51),
        Pair(-128, -46), Pair(-124, -121), Pair(-20, -23), Pair(-18, 25), Pair(-9, -20), Pair(-19, -48), Pair(-13, -77), Pair(40, 15),
        Pair(-36, -82), Pair(-58, -119), Pair(3, -36), Pair(1, -16), Pair(11, -22), Pair(19, -69), Pair(-108, -101), Pair(-63, -103),
        Pair(-102, -83), Pair(-85, -104), Pair(14, -61), Pair(83, -59), Pair(-12, -84), Pair(-38, -25), Pair(-28, -64), Pair(-39, -90),
        Pair(4, -20), Pair(-6, -17), Pair(-50, -16), Pair(12, -20), Pair(-16, 38), Pair(-37, -115), Pair(-81, -34), Pair(-54, -45),
        Pair(-100, -24), Pair(-69, -81), Pair(-107, -80), Pair(-139, 68), Pair(-53, -4), Pair(-64, -88), Pair(-56, -96), Pair(-64, -51),
        Pair(-81, -160), Pair(-38, -62), Pair(-71, -114), Pair(-105, -88), Pair(9, -71), Pair(-75, -63), Pair(-46, 30), Pair(-55, -55),
        Pair(-41, -74), Pair(-139, -159), Pair(-47, 25), Pair(-285, -177), Pair(-64, -36), Pair(-32, -7), Pair(-32, -22), Pair(24, 57)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(12, -45), Pair(101, -26), Pair(9, 6), Pair(4, 20), Pair(42, 22), Pair(79, 17), Pair(54, -7), Pair(-35, -13),
        Pair(-15, -61), Pair(115, -59), Pair(30, -24), Pair(-19, -5), Pair(3, -17), Pair(6, -13), Pair(94, -53), Pair(-77, -37),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(156, -49), Pair(345, -120), Pair(224, -40), Pair(263, -103), Pair(27, -47), Pair(120, -54), Pair(82, -11), Pair(335, -54),
        Pair(102, -2), Pair(206, 21), Pair(312, -47), Pair(220, -70), Pair(231, -56), Pair(243, -48), Pair(159, -25), Pair(24, 15),
        Pair(-54, 32), Pair(-57, 44), Pair(43, 16), Pair(-6, -3), Pair(56, -5), Pair(25, -2), Pair(30, 17), Pair(-49, 12),
        Pair(-123, 38), Pair(-85, 44), Pair(-30, 20), Pair(-39, -1), Pair(-19, 2), Pair(-75, 6), Pair(-80, 26), Pair(-148, 17),
        Pair(-153, 26), Pair(-107, 29), Pair(-93, 4), Pair(-51, 8), Pair(-55, -1), Pair(-22, -12), Pair(-37, 7), Pair(-155, 13),
        Pair(-142, 37), Pair(-140, 47), Pair(-71, 22), Pair(-62, 89), Pair(-69, 12), Pair(-96, 9), Pair(-77, 23), Pair(-185, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-12, -103), Pair(-4, -150), Pair(53, -98), Pair(-55, -65), Pair(63, -81), Pair(-84, -128), Pair(-91, -116), Pair(-23, -144),
        Pair(-98, -70), Pair(17, -94), Pair(49, -32), Pair(112, -51), Pair(103, -68), Pair(87, -57), Pair(21, -39), Pair(-42, -82),
        Pair(-84, -37), Pair(6, -36), Pair(85, -78), Pair(41, -50), Pair(246, -117), Pair(92, -87), Pair(144, -84), Pair(103, -84),
        Pair(-4, -72), Pair(69, -51), Pair(112, -59), Pair(102, -50), Pair(130, -47), Pair(93, -65), Pair(75, -61), Pair(-35, -41),
        Pair(-142, -5), Pair(9, -43), Pair(23, -25), Pair(8, -15), Pair(153, -23), Pair(26, -32), Pair(72, -62), Pair(46, -54),
        Pair(-123, -45), Pair(-64, -44), Pair(-72, -37), Pair(-16, -41), Pair(-44, -28), Pair(-91, 4), Pair(-86, -55), Pair(3, -44),
        Pair(-119, 28), Pair(-72, -39), Pair(-107, -24), Pair(-97, -31), Pair(-98, 8), Pair(-20, -14), Pair(-72, -37), Pair(18, -18),
        Pair(-36, -91), Pair(-152, -37), Pair(-181, -33), Pair(-140, -3), Pair(-126, -70), Pair(-168, 29), Pair(-56, -32), Pair(-14, -30)
      },
      { // Piece 2
        Pair(-30, -75), Pair(55, -99), Pair(114, -100), Pair(31, -88), Pair(82, -108), Pair(-23, -87), Pair(27, -105), Pair(16, -61),
        Pair(-55, -71), Pair(121, -93), Pair(82, -91), Pair(141, -116), Pair(117, -98), Pair(108, -73), Pair(200, -86), Pair(33, -100),
        Pair(-86, -44), Pair(16, -92), Pair(60, -63), Pair(188, -114), Pair(119, -105), Pair(169, -109), Pair(211, -106), Pair(-29, -81),
        Pair(88, -116), Pair(163, -89), Pair(157, -77), Pair(213, -115), Pair(155, -93), Pair(170, -107), Pair(140, -82), Pair(60, -108),
        Pair(-177, -51), Pair(-30, -51), Pair(156, -74), Pair(135, -77), Pair(150, -91), Pair(202, -89), Pair(75, -82), Pair(-31, 3),
        Pair(-27, -30), Pair(129, -76), Pair(7, -48), Pair(137, -82), Pair(120, -64), Pair(132, -73), Pair(-12, -17), Pair(-69, -55),
        Pair(-24, -26), Pair(35, -65), Pair(9, -53), Pair(17, -61), Pair(90, -79), Pair(33, -73), Pair(-141, -33), Pair(14, -101),
        Pair(-95, -23), Pair(64, -96), Pair(-91, -16), Pair(-64, -58), Pair(-61, -25), Pair(-117, -40), Pair(33, -34), Pair(-63, -43)
      },
      { // Piece 3
        Pair(42, -58), Pair(134, -97), Pair(34, -57), Pair(20, -44), Pair(-97, -62), Pair(129, -99), Pair(165, -108), Pair(107, -91),
        Pair(-73, -54), Pair(10, -64), Pair(19, -90), Pair(92, -92), Pair(34, -122), Pair(25, -116), Pair(-4, -91), Pair(93, -112),
        Pair(-7, -73), Pair(43, -70), Pair(192, -119), Pair(75, -105), Pair(156, -110), Pair(100, -109), Pair(153, -107), Pair(35, -92),
        Pair(-33, -57), Pair(59, -78), Pair(-62, -43), Pair(23, -87), Pair(64, -109), Pair(-12, -88), Pair(27, -73), Pair(-11, -79),
        Pair(-59, -75), Pair(-105, -49), Pair(15, -73), Pair(4, -57), Pair(13, -77), Pair(10, -71), Pair(-72, -52), Pair(-146, -38),
        Pair(-42, -84), Pair(-98, -56), Pair(-135, -48), Pair(-43, -39), Pair(-33, -83), Pair(-41, -79), Pair(-16, -75), Pair(-142, -56),
        Pair(-108, -56), Pair(-95, -55), Pair(-59, -54), Pair(-22, -83), Pair(-143, -59), Pair(-24, -100), Pair(-177, -43), Pair(-155, -61),
        Pair(-216, -24), Pair(-123, -17), Pair(-175, -41), Pair(-131, -53), Pair(-119, -62), Pair(-48, -85), Pair(-105, -53), Pair(-203, -17)
      },
      { // Piece 4
        Pair(-64, -244), Pair(-168, -186), Pair(-82, -177), Pair(-91, -123), Pair(-118, -135), Pair(-183, -177), Pair(-202, -169), Pair(-143, -179),
        Pair(-127, -122), Pair(-55, -151), Pair(-71, -121), Pair(-63, -63), Pair(-40, -120), Pair(-71, -99), Pair(-47, -37), Pair(-80, -114),
        Pair(-99, -162), Pair(-49, -153), Pair(-133, -54), Pair(-161, -123), Pair(-88, -116), Pair(-100, -127), Pair(-40, -154), Pair(-61, -103),
        Pair(-41, -141), Pair(-123, -169), Pair(-108, -90), Pair(-103, -117), Pair(-128, -61), Pair(-133, -120), Pair(-193, -105), Pair(-96, -100),
        Pair(-182, -182), Pair(-202, -171), Pair(-149, -97), Pair(-136, -106), Pair(-37, -80), Pair(-145, -152), Pair(-149, -68), Pair(-34, -157),
        Pair(-104, -125), Pair(-131, -74), Pair(-118, -124), Pair(-42, -147), Pair(-221, -40), Pair(-67, -180), Pair(-149, -149), Pair(-198, -98),
        Pair(-149, -132), Pair(-75, -110), Pair(-93, -113), Pair(-46, -182), Pair(-181, -143), Pair(-192, -123), Pair(-32, -82), Pair(-182, -247),
        Pair(-138, -281), Pair(-114, -98), Pair(-132, -252), Pair(-127, -209), Pair(-107, -166), Pair(-99, -63), Pair(-82, -170), Pair(-115, -153)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(23, -35), Pair(113, -6), Pair(47, 13), Pair(-68, 36), Pair(4, 20), Pair(6, 27), Pair(-43, 25), Pair(-16, -19),
        Pair(40, -50), Pair(67, -23), Pair(25, 1), Pair(-57, 18), Pair(-56, 14), Pair(-14, -3), Pair(-27, -14), Pair(-38, -40),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(66, 12), Pair(146, -106), Pair(164, 51), Pair(120, 0), Pair(76, 24), Pair(120, 18), Pair(59, 26), Pair(150, 64),
        Pair(49, 57), Pair(123, 57), Pair(139, 29), Pair(117, 19), Pair(115, 10), Pair(85, 35), Pair(108, 38), Pair(110, 41),
        Pair(-88, 59), Pair(-68, 64), Pair(96, 11), Pair(23, -2), Pair(34, -2), Pair(147, -34), Pair(69, 19), Pair(-67, 28),
        Pair(-109, 41), Pair(-84, 49), Pair(-68, 38), Pair(-45, 40), Pair(-59, 25), Pair(-76, 22), Pair(-64, 39), Pair(-78, 15),
        Pair(-159, 30), Pair(-62, 34), Pair(-3, 3), Pair(-57, 23), Pair(24, -8), Pair(-37, 2), Pair(-49, 19), Pair(-133, 22),
        Pair(-138, 40), Pair(-121, 47), Pair(-81, 29), Pair(-75, 43), Pair(-58, 2), Pair(-115, 27), Pair(-110, 45), Pair(-178, 46),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, -122), Pair(34, -111), Pair(3, -45), Pair(14, -106), Pair(50, -27), Pair(37, -94), Pair(-37, -55), Pair(9, -92),
        Pair(-55, -145), Pair(-61, -36), Pair(-52, -56), Pair(85, -84), Pair(26, -96), Pair(43, -106), Pair(24, -104), Pair(51, -29),
        Pair(11, -77), Pair(54, -94), Pair(47, -88), Pair(46, -35), Pair(182, -36), Pair(82, -51), Pair(-22, -73), Pair(69, -98),
        Pair(112, -83), Pair(-12, -69), Pair(112, -59), Pair(24, -37), Pair(37, -52), Pair(75, -32), Pair(-38, -73), Pair(-2, -79),
        Pair(-38, -63), Pair(-23, -64), Pair(60, -34), Pair(168, -71), Pair(10, -32), Pair(53, -86), Pair(9, -82), Pair(10, -106),
        Pair(55, -75), Pair(-20, -42), Pair(43, -32), Pair(52, -23), Pair(-30, -33), Pair(-26, -18), Pair(-15, -42), Pair(-57, -83),
        Pair(-1, -69), Pair(-102, -16), Pair(-8, -66), Pair(-78, -20), Pair(50, -59), Pair(-41, -48), Pair(6, 11), Pair(-48, -60),
        Pair(-15, -109), Pair(-97, -108), Pair(-155, 19), Pair(-93, 30), Pair(-124, -65), Pair(-78, -120), Pair(-34, -53), Pair(-56, -104)
      },
      { // Piece 2
        Pair(-61, -54), Pair(21, -84), Pair(48, -88), Pair(59, -84), Pair(-31, -119), Pair(31, -73), Pair(5, -82), Pair(28, -73),
        Pair(3, -67), Pair(45, -88), Pair(36, -92), Pair(130, -145), Pair(85, -122), Pair(196, -126), Pair(12, -109), Pair(-57, -75),
        Pair(-22, -56), Pair(154, -88), Pair(160, -89), Pair(155, -98), Pair(233, -97), Pair(109, -83), Pair(59, -109), Pair(24, -50),
        Pair(26, -79), Pair(45, -62), Pair(147, -100), Pair(116, -93), Pair(229, -111), Pair(177, -77), Pair(123, -112), Pair(76, -84),
        Pair(14, -61), Pair(74, -58), Pair(85, -79), Pair(177, -92), Pair(146, -62), Pair(118, -85), Pair(90, -111), Pair(-77, -50),
        Pair(-110, -93), Pair(-12, -47), Pair(54, -80), Pair(59, -53), Pair(83, -72), Pair(88, -68), Pair(-33, -33), Pair(-71, -54),
        Pair(33, -54), Pair(67, -30), Pair(41, -93), Pair(33, -49), Pair(78, -71), Pair(-24, -51), Pair(-108, -14), Pair(-34, -43),
        Pair(-68, -50), Pair(-5, -58), Pair(-117, 8), Pair(32, -73), Pair(-23, -86), Pair(110, -46), Pair(18, -67), Pair(8, -5)
      },
      { // Piece 3
        Pair(48, -110), Pair(27, -82), Pair(49, -140), Pair(100, -80), Pair(-67, -71), Pair(3, -99), Pair(-15, -67), Pair(92, -115),
        Pair(103, -145), Pair(71, -102), Pair(141, -144), Pair(-14, -132), Pair(174, -146), Pair(97, -139), Pair(131, -156), Pair(19, -120),
        Pair(38, -102), Pair(-54, -57), Pair(17, -102), Pair(-3, -111), Pair(-34, -109), Pair(30, -76), Pair(-25, -40), Pair(64, -136),
        Pair(4, -83), Pair(50, -116), Pair(65, -110), Pair(56, -113), Pair(46, -121), Pair(83, -134), Pair(23, -137), Pair(35, -120),
        Pair(-45, -91), Pair(-20, -77), Pair(-41, -84), Pair(12, -79), Pair(-6, -126), Pair(13, -118), Pair(4, -64), Pair(60, -100),
        Pair(-117, -114), Pair(-40, -109), Pair(-8, -124), Pair(-62, -86), Pair(-86, -105), Pair(-47, -102), Pair(-82, -69), Pair(-52, -116),
        Pair(-164, -64), Pair(-16, -80), Pair(22, -111), Pair(-107, -73), Pair(63, -137), Pair(18, -116), Pair(-59, -106), Pair(-78, -77),
        Pair(-128, -56), Pair(16, -67), Pair(-31, -78), Pair(-80, -72), Pair(-55, -85), Pair(-44, -79), Pair(-83, -77), Pair(-153, -70)
      },
      { // Piece 4
        Pair(-18, -184), Pair(-66, -130), Pair(-38, -85), Pair(-2, -140), Pair(-66, -115), Pair(-55, -112), Pair(-18, -111), Pair(-94, -215),
        Pair(-50, -121), Pair(-63, -43), Pair(4, -147), Pair(-11, -112), Pair(39, -87), Pair(-56, -79), Pair(-38, -54), Pair(-114, -139),
        Pair(-58, -126), Pair(-63, -106), Pair(-46, 46), Pair(-24, -115), Pair(-32, -100), Pair(7, -84), Pair(-70, -137), Pair(-69, -83),
        Pair(-94, -191), Pair(-84, -177), Pair(-6, -75), Pair(0, -94), Pair(35, -103), Pair(-91, -167), Pair(-90, -135), Pair(-82, -126),
        Pair(-24, -17), Pair(-50, -47), Pair(-55, -27), Pair(35, 14), Pair(-63, -62), Pair(-60, -144), Pair(-68, -135), Pair(-72, -53),
        Pair(-95, -150), Pair(-20, -48), Pair(-60, -137), Pair(15, -39), Pair(-4, -52), Pair(-9, -71), Pair(-42, -117), Pair(-71, -106),
        Pair(-105, -223), Pair(-20, -55), Pair(-23, -160), Pair(-52, -60), Pair(-61, -157), Pair(-80, -99), Pair(-40, -90), Pair(16, -55),
        Pair(-40, -102), Pair(-38, -64), Pair(7, -10), Pair(-99, -203), Pair(-15, -134), Pair(-90, -114), Pair(-26, -47), Pair(-10, -58)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(39, -28), Pair(82, -4), Pair(-10, 24), Pair(-11, 24), Pair(-58, 39), Pair(41, 27), Pair(9, 28), Pair(-42, -17),
        Pair(69, -42), Pair(79, -21), Pair(35, 4), Pair(-21, 15), Pair(-79, 18), Pair(-76, 28), Pair(34, -15), Pair(-93, -12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-168, 58), Pair(-49, 12), Pair(55, 112), Pair(48, 49), Pair(70, 48), Pair(-19, 64), Pair(-91, 103), Pair(-171, 84),
        Pair(-133, 85), Pair(72, 80), Pair(12, 103), Pair(41, 135), Pair(-28, 93), Pair(56, 105), Pair(23, 118), Pair(-17, 94),
        Pair(-158, 81), Pair(-35, 89), Pair(-7, 56), Pair(-66, 83), Pair(20, 34), Pair(-13, 42), Pair(-116, 73), Pair(-112, 70),
        Pair(-103, 51), Pair(-54, 60), Pair(37, 14), Pair(-20, 19), Pair(34, 1), Pair(23, 22), Pair(-65, 44), Pair(-154, 44),
        Pair(-161, 37), Pair(-120, 42), Pair(-119, 31), Pair(38, 40), Pair(-70, 33), Pair(-39, 27), Pair(-67, 34), Pair(-132, 25),
        Pair(-196, 52), Pair(-132, 68), Pair(-19, 29), Pair(-46, 84), Pair(-85, 55), Pair(-65, 35), Pair(-163, 45), Pair(-47, 33),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(17, -117), Pair(65, -128), Pair(-31, -45), Pair(35, -147), Pair(72, -109), Pair(-33, -114), Pair(-63, -155), Pair(-12, -209),
        Pair(-58, -179), Pair(36, -61), Pair(14, -127), Pair(113, -177), Pair(-39, -122), Pair(34, -124), Pair(-54, -100), Pair(-61, -100),
        Pair(-53, -138), Pair(21, -81), Pair(14, -69), Pair(59, -88), Pair(36, -42), Pair(25, -76), Pair(-33, -137), Pair(-38, -128),
        Pair(18, -25), Pair(57, -69), Pair(69, -107), Pair(87, -69), Pair(57, -99), Pair(103, -71), Pair(-13, -127), Pair(-94, -56),
        Pair(-3, -117), Pair(-21, -69), Pair(35, -121), Pair(43, -88), Pair(70, -92), Pair(90, -59), Pair(-33, -37), Pair(-2, -139),
        Pair(-52, -113), Pair(-10, -45), Pair(-29, -99), Pair(14, -68), Pair(56, -55), Pair(52, -108), Pair(-80, -39), Pair(-3, -20),
        Pair(-32, -110), Pair(-77, -108), Pair(13, -46), Pair(-29, -58), Pair(23, -53), Pair(-34, -73), Pair(30, -36), Pair(-13, 7),
        Pair(-46, -87), Pair(-53, -40), Pair(-45, -88), Pair(-47, -43), Pair(26, -31), Pair(-25, -28), Pair(16, -95), Pair(-13, -82)
      },
      { // Piece 2
        Pair(-46, -84), Pair(98, -76), Pair(-45, -66), Pair(-35, -99), Pair(-66, -95), Pair(-96, -84), Pair(-27, -163), Pair(-12, -126),
        Pair(57, -74), Pair(-23, -103), Pair(59, -56), Pair(-54, -75), Pair(88, -97), Pair(-7, -108), Pair(27, -77), Pair(-47, -53),
        Pair(91, -84), Pair(113, -85), Pair(32, -76), Pair(16, -78), Pair(70, -81), Pair(45, -74), Pair(-33, -59), Pair(39, -127),
        Pair(-7, -26), Pair(30, -70), Pair(171, -68), Pair(95, -87), Pair(62, -82), Pair(118, -86), Pair(52, -56), Pair(11, -121),
        Pair(5, -33), Pair(93, -62), Pair(43, -88), Pair(80, -95), Pair(59, -92), Pair(83, -59), Pair(-22, -93), Pair(45, -71),
        Pair(-30, -17), Pair(22, -53), Pair(68, -38), Pair(-7, -56), Pair(29, -54), Pair(87, -54), Pair(16, -16), Pair(-14, -48),
        Pair(-25, -108), Pair(-23, -19), Pair(-39, -68), Pair(88, -77), Pair(27, -72), Pair(-6, -71), Pair(-45, -36), Pair(-9, -86),
        Pair(-1, -30), Pair(-76, 20), Pair(-109, -21), Pair(-83, -62), Pair(-24, -59), Pair(-34, -64), Pair(18, -89), Pair(9, -82)
      },
      { // Piece 3
        Pair(102, -137), Pair(16, -112), Pair(61, -139), Pair(-13, -106), Pair(41, -119), Pair(20, -149), Pair(99, -110), Pair(33, -119),
        Pair(71, -134), Pair(69, -85), Pair(-65, -102), Pair(-8, -132), Pair(82, -135), Pair(27, -149), Pair(104, -142), Pair(48, -155),
        Pair(-32, -124), Pair(11, -149), Pair(72, -171), Pair(11, -162), Pair(32, -131), Pair(36, -145), Pair(5, -159), Pair(-15, -139),
        Pair(42, -104), Pair(21, -138), Pair(-17, -158), Pair(-64, -134), Pair(-44, -150), Pair(3, -150), Pair(-9, -148), Pair(-61, -104),
        Pair(-5, -133), Pair(-95, -101), Pair(-46, -84), Pair(-59, -120), Pair(13, -122), Pair(56, -146), Pair(41, -166), Pair(-32, -122),
        Pair(-45, -127), Pair(64, -173), Pair(-68, -116), Pair(-19, -134), Pair(-64, -92), Pair(103, -135), Pair(128, -161), Pair(-62, -154),
        Pair(-50, -153), Pair(-31, -107), Pair(-5, -120), Pair(-102, -99), Pair(-14, -127), Pair(-26, -121), Pair(-89, -96), Pair(-39, -117),
        Pair(-71, -115), Pair(-65, -86), Pair(-60, -118), Pair(-40, -109), Pair(-56, -100), Pair(-91, -104), Pair(-92, -109), Pair(-45, -82)
      },
      { // Piece 4
        Pair(-95, -156), Pair(-92, -182), Pair(-11, -50), Pair(-65, -71), Pair(41, -134), Pair(34, -143), Pair(-115, -132), Pair(-98, -168),
        Pair(-53, -72), Pair(-9, -15), Pair(-16, -59), Pair(48, 23), Pair(-60, -44), Pair(-84, -131), Pair(-4, -31), Pair(-120, -93),
        Pair(-38, -42), Pair(22, -15), Pair(-6, -116), Pair(-51, -108), Pair(-18, -49), Pair(-56, -86), Pair(-70, -80), Pair(-62, -88),
        Pair(-20, -39), Pair(25, 26), Pair(-13, -23), Pair(-29, -59), Pair(-67, -114), Pair(8, -4), Pair(7, 11), Pair(60, 53),
        Pair(-29, -48), Pair(-52, -91), Pair(-11, -23), Pair(-6, -21), Pair(-78, -104), Pair(-35, -65), Pair(13, -9), Pair(-34, -96),
        Pair(-73, -57), Pair(-46, -57), Pair(-31, -31), Pair(-39, -99), Pair(-11, -40), Pair(6, 13), Pair(-15, -14), Pair(25, -3),
        Pair(-1, -41), Pair(-58, -57), Pair(-16, -54), Pair(-106, -144), Pair(21, -43), Pair(-8, -24), Pair(-6, -17), Pair(13, -74),
        Pair(-47, -101), Pair(-18, -33), Pair(-51, -111), Pair(-5, -47), Pair(17, 46), Pair(-47, -108), Pair(-50, -94), Pair(-41, -73)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(36, -34), Pair(151, -18), Pair(35, 14), Pair(-38, 29), Pair(-32, 41), Pair(14, 19), Pair(44, 4), Pair(4, -35),
        Pair(64, -48), Pair(58, -7), Pair(3, 9), Pair(-102, 25), Pair(-109, 32), Pair(-60, 30), Pair(74, -17), Pair(-64, -25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-255, 45), Pair(22, 35), Pair(167, 17), Pair(41, -1), Pair(135, 37), Pair(109, 34), Pair(9, 67), Pair(-203, 42),
        Pair(-172, 113), Pair(-115, 141), Pair(-10, 128), Pair(8, 108), Pair(-15, 129), Pair(-81, 121), Pair(1, 106), Pair(-120, 122),
        Pair(-211, 76), Pair(-75, 77), Pair(-52, 68), Pair(-141, 99), Pair(-123, 97), Pair(-43, 66), Pair(-129, 84), Pair(-211, 73),
        Pair(-135, 47), Pair(-47, 53), Pair(-24, 42), Pair(-85, 59), Pair(14, 27), Pair(-59, 36), Pair(14, 32), Pair(-97, 45),
        Pair(-112, 35), Pair(-73, 42), Pair(-50, 25), Pair(-30, 49), Pair(-24, 26), Pair(31, 16), Pair(-13, 22), Pair(-132, 31),
        Pair(-195, 57), Pair(-131, 60), Pair(-41, 55), Pair(-88, 76), Pair(-53, 27), Pair(-105, 40), Pair(-45, 46), Pair(-217, 73),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-2, -109), Pair(-38, -142), Pair(8, -133), Pair(-77, -152), Pair(-37, -73), Pair(27, -176), Pair(-84, -135), Pair(48, -160),
        Pair(-37, -141), Pair(6, -131), Pair(-30, -169), Pair(28, -156), Pair(-2, -146), Pair(-17, -139), Pair(19, -172), Pair(-19, -179),
        Pair(-86, -96), Pair(22, -133), Pair(0, -111), Pair(13, -117), Pair(122, -159), Pair(-18, -119), Pair(-3, -151), Pair(-71, -127),
        Pair(-3, -162), Pair(-1, -116), Pair(54, -106), Pair(18, -105), Pair(-11, -128), Pair(53, -118), Pair(49, -192), Pair(-2, -94),
        Pair(53, -106), Pair(-4, -127), Pair(-34, -90), Pair(-7, -123), Pair(114, -97), Pair(31, -131), Pair(105, -158), Pair(-36, -126),
        Pair(-13, -147), Pair(-72, -133), Pair(21, -127), Pair(69, -166), Pair(-6, -71), Pair(44, -94), Pair(-47, -94), Pair(-12, -137),
        Pair(-76, -196), Pair(-29, -109), Pair(-44, -119), Pair(-35, -101), Pair(-7, -106), Pair(-10, -102), Pair(-15, -80), Pair(-61, -56),
        Pair(-42, -100), Pair(-13, -73), Pair(-20, -67), Pair(8, -82), Pair(52, -142), Pair(8, -93), Pair(28, -87), Pair(5, -20)
      },
      { // Piece 2
        Pair(13, -117), Pair(109, -86), Pair(13, -87), Pair(-47, -89), Pair(57, -109), Pair(-68, -48), Pair(101, -114), Pair(-33, -91),
        Pair(-5, -94), Pair(-189, -67), Pair(-74, -44), Pair(26, -94), Pair(-68, -69), Pair(94, -86), Pair(-13, -57), Pair(3, -76),
        Pair(-77, -51), Pair(8, -93), Pair(36, -85), Pair(11, -67), Pair(54, -61), Pair(-7, -57), Pair(94, -103), Pair(-23, -89),
        Pair(5, -91), Pair(-73, -53), Pair(42, -76), Pair(11, -62), Pair(-28, -83), Pair(13, -68), Pair(-109, -48), Pair(45, -88),
        Pair(59, -61), Pair(12, -87), Pair(15, -75), Pair(-1, -45), Pair(-13, -88), Pair(-80, -41), Pair(3, -71), Pair(-56, -55),
        Pair(-95, -62), Pair(61, -71), Pair(-53, -55), Pair(-59, -56), Pair(-81, -90), Pair(-12, -74), Pair(6, -70), Pair(20, -83),
        Pair(-51, -11), Pair(-74, -80), Pair(109, -81), Pair(-96, -78), Pair(20, -86), Pair(-20, -100), Pair(-77, -25), Pair(4, -102),
        Pair(-70, -66), Pair(49, -6), Pair(-52, -78), Pair(-51, -50), Pair(-118, -37), Pair(31, -51), Pair(-72, -58), Pair(-7, -64)
      },
      { // Piece 3
        Pair(59, -207), Pair(72, -183), Pair(117, -155), Pair(7, -152), Pair(-6, -149), Pair(-25, -145), Pair(81, -148), Pair(62, -176),
        Pair(-38, -181), Pair(13, -158), Pair(189, -224), Pair(13, -173), Pair(71, -188), Pair(14, -176), Pair(98, -189), Pair(-79, -150),
        Pair(10, -169), Pair(97, -197), Pair(-28, -204), Pair(133, -188), Pair(45, -172), Pair(151, -230), Pair(95, -195), Pair(51, -190),
        Pair(17, -157), Pair(182, -195), Pair(49, -192), Pair(73, -189), Pair(21, -174), Pair(102, -243), Pair(-51, -170), Pair(45, -206),
        Pair(15, -164), Pair(37, -171), Pair(87, -209), Pair(35, -209), Pair(35, -215), Pair(53, -202), Pair(35, -200), Pair(6, -173),
        Pair(62, -185), Pair(45, -169), Pair(-39, -176), Pair(-6, -161), Pair(-38, -178), Pair(-86, -195), Pair(-124, -237), Pair(-46, -164),
        Pair(22, -163), Pair(-64, -153), Pair(-45, -157), Pair(-124, -141), Pair(-117, -159), Pair(-40, -160), Pair(19, -187), Pair(24, -189),
        Pair(-78, -141), Pair(-113, -134), Pair(-52, -177), Pair(-58, -161), Pair(-5, -167), Pair(-17, -178), Pair(-26, -171), Pair(-78, -137)
      },
      { // Piece 4
        Pair(-38, -202), Pair(-91, -175), Pair(-85, -142), Pair(-131, -151), Pair(-72, -178), Pair(-173, -144), Pair(-35, -238), Pair(-85, -236),
        Pair(-80, -168), Pair(-59, -168), Pair(-53, -165), Pair(26, -103), Pair(-60, -137), Pair(6, -99), Pair(-28, -166), Pair(-107, -196),
        Pair(-59, -158), Pair(-90, -167), Pair(-37, -63), Pair(-16, -149), Pair(-28, -123), Pair(-82, -241), Pair(-59, -174), Pair(-78, -167),
        Pair(-130, -183), Pair(-71, -168), Pair(-107, -185), Pair(-56, -136), Pair(-74, -153), Pair(-9, -177), Pair(-110, -156), Pair(-93, -143),
        Pair(-74, -187), Pair(-62, -132), Pair(-19, -89), Pair(-5, 3), Pair(-92, -152), Pair(-24, -123), Pair(-42, -69), Pair(-83, -164),
        Pair(-43, -68), Pair(-71, -114), Pair(-73, -143), Pair(-73, -148), Pair(-75, -129), Pair(-89, -174), Pair(32, 17), Pair(-33, -95),
        Pair(-87, -206), Pair(-96, -151), Pair(-131, -190), Pair(-98, -182), Pair(-15, -125), Pair(-124, -234), Pair(-53, -113), Pair(-97, -190),
        Pair(-80, -182), Pair(-3, -48), Pair(-72, -143), Pair(-83, -242), Pair(-74, -170), Pair(-61, -121), Pair(-116, -207), Pair(-71, -168)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-60, -5), Pair(123, -13), Pair(23, 8), Pair(-45, 18), Pair(67, 16), Pair(56, 4), Pair(4, 7), Pair(20, -32),
        Pair(43, -46), Pair(37, -10), Pair(-45, 13), Pair(-97, 38), Pair(-63, 27), Pair(15, 24), Pair(25, 1), Pair(-95, -15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-197, 21), Pair(-148, 71), Pair(24, 156), Pair(129, 105), Pair(62, 161), Pair(27, 52), Pair(-48, 18), Pair(-196, 42),
        Pair(-163, 121), Pair(-45, 196), Pair(63, 183), Pair(0, 125), Pair(51, 120), Pair(-6, 113), Pair(-84, 125), Pair(-138, 132),
        Pair(-186, 85), Pair(-103, 124), Pair(5, 101), Pair(-70, 152), Pair(-74, 83), Pair(74, 99), Pair(35, 105), Pair(-104, 86),
        Pair(-86, 64), Pair(-121, 73), Pair(-4, 82), Pair(-115, 74), Pair(76, 38), Pair(-64, 39), Pair(-8, 42), Pair(-166, 77),
        Pair(-44, 56), Pair(-80, 33), Pair(6, 24), Pair(-18, 35), Pair(-60, 48), Pair(-18, 35), Pair(-127, 43), Pair(-29, 29),
        Pair(-133, 65), Pair(-67, 76), Pair(-62, 61), Pair(12, 117), Pair(33, 82), Pair(-128, 69), Pair(-93, 53), Pair(-39, 59),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-35, -116), Pair(-11, -77), Pair(9, -71), Pair(-6, -52), Pair(-29, -91), Pair(-34, -112), Pair(-2, -145), Pair(25, -102),
        Pair(-18, -200), Pair(-48, -65), Pair(-71, -158), Pair(-24, -148), Pair(4, -63), Pair(-95, -144), Pair(-21, -61), Pair(-8, -95),
        Pair(-12, -80), Pair(-39, -114), Pair(-66, -76), Pair(-62, -57), Pair(-88, -102), Pair(15, 9), Pair(32, -27), Pair(-45, -211),
        Pair(-30, -130), Pair(-20, -50), Pair(-42, -86), Pair(79, -8), Pair(81, -86), Pair(44, -104), Pair(85, -141), Pair(4, -44),
        Pair(-16, -151), Pair(8, -87), Pair(91, -59), Pair(-4, -20), Pair(15, -135), Pair(34, -105), Pair(-42, -90), Pair(24, -109),
        Pair(-10, -58), Pair(40, -78), Pair(-2, -101), Pair(40, -98), Pair(60, -86), Pair(-19, 11), Pair(-10, 72), Pair(0, -124),
        Pair(-8, -30), Pair(2, -54), Pair(-43, -51), Pair(-24, -66), Pair(-8, -97), Pair(-19, -104), Pair(-3, -49), Pair(-13, -49),
        Pair(-17, -57), Pair(-26, -99), Pair(-5, -63), Pair(-59, -111), Pair(22, -114), Pair(20, -59), Pair(-11, -98), Pair(-14, -54)
      },
      { // Piece 2
        Pair(-7, -48), Pair(10, 70), Pair(-71, -131), Pair(-2, 36), Pair(12, -72), Pair(-9, -87), Pair(-14, -14), Pair(-14, -70),
        Pair(13, -14), Pair(-47, 30), Pair(-4, -25), Pair(-3, -83), Pair(-5, -61), Pair(-9, -68), Pair(-32, -55), Pair(-41, -183),
        Pair(8, -64), Pair(8, -84), Pair(-40, -40), Pair(25, -38), Pair(40, -11), Pair(-116, -42), Pair(-29, 10), Pair(8, -17),
        Pair(-40, 11), Pair(-21, -58), Pair(45, -27), Pair(-66, -73), Pair(10, -31), Pair(-39, -15), Pair(-63, -87), Pair(42, -3),
        Pair(-34, 15), Pair(-45, -61), Pair(23, -65), Pair(17, -10), Pair(42, -69), Pair(-34, -8), Pair(-4, -60), Pair(20, 46),
        Pair(-19, 51), Pair(5, -41), Pair(-1, -47), Pair(-74, -6), Pair(-62, 2), Pair(-31, 14), Pair(-18, -8), Pair(7, -41),
        Pair(-21, 13), Pair(-59, -53), Pair(19, 6), Pair(-19, -77), Pair(-35, -8), Pair(-23, -118), Pair(-10, -108), Pair(-34, -104),
        Pair(4, -77), Pair(63, -86), Pair(-25, -41), Pair(22, -57), Pair(-39, -26), Pair(-33, -60), Pair(-20, -71), Pair(28, -39)
      },
      { // Piece 3
        Pair(16, -142), Pair(-6, -123), Pair(2, -117), Pair(32, -150), Pair(25, -118), Pair(-63, -105), Pair(-61, -76), Pair(10, -123),
        Pair(-39, -135), Pair(36, -102), Pair(83, -72), Pair(10, -182), Pair(-20, -50), Pair(-33, -170), Pair(9, -111), Pair(-9, -89),
        Pair(-4, -126), Pair(-19, -85), Pair(-7, -122), Pair(90, -132), Pair(-10, -95), Pair(-37, -150), Pair(15, -109), Pair(-5, -158),
        Pair(6, -153), Pair(29, -117), Pair(-34, -104), Pair(-34, -143), Pair(-107, -155), Pair(-14, -203), Pair(-18, -105), Pair(-23, -124),
        Pair(48, -144), Pair(40, -73), Pair(-109, -154), Pair(25, -194), Pair(-42, -128), Pair(-24, -134), Pair(-39, -131), Pair(33, -111),
        Pair(-26, -98), Pair(-29, -96), Pair(-15, -132), Pair(-60, -136), Pair(38, -113), Pair(48, -138), Pair(9, -143), Pair(30, -79),
        Pair(-11, -93), Pair(28, -84), Pair(29, -63), Pair(-48, -170), Pair(33, -88), Pair(6, -101), Pair(-25, -144), Pair(0, -115),
        Pair(-13, -88), Pair(-66, -109), Pair(108, -121), Pair(15, -120), Pair(-19, -128), Pair(-1, -137), Pair(13, -79), Pair(22, -44)
      },
      { // Piece 4
        Pair(-78, -137), Pair(-41, -159), Pair(-39, -176), Pair(-52, -51), Pair(-13, -21), Pair(-80, -84), Pair(-85, -138), Pair(-110, -154),
        Pair(-41, -132), Pair(-100, -146), Pair(-30, 15), Pair(-66, -53), Pair(-43, -121), Pair(-16, -44), Pair(-44, -72), Pair(-15, -25),
        Pair(-31, -106), Pair(-117, -127), Pair(-29, -62), Pair(-24, -91), Pair(-45, -70), Pair(-15, -57), Pair(-25, -25), Pair(-55, -63),
        Pair(-32, -71), Pair(-36, -85), Pair(14, -7), Pair(-19, -68), Pair(-41, -87), Pair(-28, -88), Pair(-16, -21), Pair(0, -95),
        Pair(-14, -36), Pair(22, -51), Pair(42, -53), Pair(-18, -6), Pair(48, -27), Pair(15, -47), Pair(-42, -88), Pair(1, -29),
        Pair(-31, -81), Pair(-42, -93), Pair(-72, -102), Pair(3, -43), Pair(14, -6), Pair(-89, -147), Pair(-52, -138), Pair(-1, -44),
        Pair(13, -4), Pair(-20, -22), Pair(-35, -93), Pair(4, -13), Pair(18, 4), Pair(-12, -86), Pair(30, 35), Pair(1, -16),
        Pair(-67, -64), Pair(-4, -5), Pair(-19, -44), Pair(-26, -49), Pair(-22, -85), Pair(-47, -121), Pair(17, 19), Pair(-58, -130)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-66, -6), Pair(59, 10), Pair(8, 29), Pair(13, 45), Pair(-19, 61), Pair(-38, 32), Pair(43, 23), Pair(40, 4),
        Pair(-116, -14), Pair(75, 29), Pair(24, 21), Pair(-125, 64), Pair(-31, 27), Pair(-18, 22), Pair(13, 18), Pair(-30, -4),
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
        Pair(-42, 41), Pair(135, -16), Pair(89, 251), Pair(78, 154), Pair(-36, 170), Pair(42, 138), Pair(22, -50), Pair(11, -150),
        Pair(17, 44), Pair(167, 116), Pair(-6, 140), Pair(28, 173), Pair(22, 114), Pair(111, 38), Pair(68, -15), Pair(68, -15),
        Pair(-21, 47), Pair(-13, 73), Pair(159, 38), Pair(2, 92), Pair(-8, 72), Pair(-36, 68), Pair(-87, 35), Pair(32, 2),
        Pair(-80, 33), Pair(-122, 95), Pair(25, 65), Pair(63, 19), Pair(-4, 1), Pair(-95, 15), Pair(-121, 20), Pair(-128, -4),
        Pair(-118, 19), Pair(-8, 71), Pair(66, 11), Pair(43, -53), Pair(-48, 4), Pair(26, -6), Pair(-176, 52), Pair(24, -9),
        Pair(-19, 2), Pair(-44, 31), Pair(5, 50), Pair(-59, -29), Pair(-22, -17), Pair(-46, -21), Pair(-166, 73), Pair(-153, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(10, 45), Pair(12, -2), Pair(52, 26), Pair(-23, -81), Pair(22, 55), Pair(27, -96), Pair(15, 44), Pair(0, -5),
        Pair(6, 12), Pair(-8, 14), Pair(13, -81), Pair(62, 45), Pair(38, -70), Pair(5, -113), Pair(-24, -60), Pair(4, 5),
        Pair(-41, -103), Pair(0, -20), Pair(-4, 5), Pair(25, 19), Pair(236, 131), Pair(52, 60), Pair(46, 50), Pair(42, 31),
        Pair(49, -1), Pair(-12, -48), Pair(66, 35), Pair(-23, 9), Pair(10, 39), Pair(18, 30), Pair(138, 86), Pair(8, 14),
        Pair(47, 64), Pair(16, -4), Pair(32, 79), Pair(-77, -61), Pair(84, 189), Pair(10, 10), Pair(2, 77), Pair(-41, -5),
        Pair(-48, -4), Pair(4, -60), Pair(-72, 14), Pair(-5, -32), Pair(-2, 10), Pair(-49, -22), Pair(3, -48), Pair(8, -39),
        Pair(-17, -79), Pair(5, 8), Pair(-58, 56), Pair(-155, 11), Pair(-57, -86), Pair(19, 38), Pair(16, -2), Pair(-24, -45),
        Pair(-2, 1), Pair(-6, 35), Pair(24, 62), Pair(-1, 6), Pair(4, -15), Pair(-61, -95), Pair(-96, -88), Pair(-15, -66)
      },
      { // Piece 2
        Pair(-11, 3), Pair(8, 13), Pair(-27, -44), Pair(8, -78), Pair(1, 25), Pair(-86, -107), Pair(-7, -35), Pair(5, 79),
        Pair(3, -35), Pair(-22, -19), Pair(-36, -83), Pair(11, -21), Pair(32, 43), Pair(-35, -124), Pair(19, 56), Pair(22, 11),
        Pair(-35, -101), Pair(11, -30), Pair(86, 13), Pair(-35, -57), Pair(78, 7), Pair(31, 62), Pair(-14, -19), Pair(28, 89),
        Pair(17, 0), Pair(89, -65), Pair(21, -66), Pair(89, -23), Pair(4, -20), Pair(-49, 24), Pair(-69, -81), Pair(60, -25),
        Pair(34, 85), Pair(34, 26), Pair(-36, 36), Pair(128, -66), Pair(24, -101), Pair(39, -34), Pair(-15, 1), Pair(-19, 25),
        Pair(22, 64), Pair(9, -71), Pair(76, 144), Pair(-42, -14), Pair(44, -26), Pair(-91, -80), Pair(3, 78), Pair(12, -19),
        Pair(11, -23), Pair(91, 20), Pair(81, -95), Pair(-52, 31), Pair(-27, -74), Pair(-9, 8), Pair(-63, -85), Pair(-9, -36),
        Pair(-48, -95), Pair(-10, 36), Pair(-124, 66), Pair(-24, -22), Pair(7, 55), Pair(-107, -133), Pair(30, -8), Pair(-6, -71)
      },
      { // Piece 3
        Pair(-7, -26), Pair(74, 114), Pair(70, 119), Pair(42, 47), Pair(59, 148), Pair(-72, -110), Pair(-6, -7), Pair(7, 1),
        Pair(88, -28), Pair(141, -28), Pair(51, -28), Pair(-4, 34), Pair(140, -53), Pair(75, 21), Pair(23, 35), Pair(-29, -67),
        Pair(-19, -33), Pair(17, -15), Pair(71, 37), Pair(18, -17), Pair(-43, 16), Pair(11, 17), Pair(-23, 24), Pair(-7, 55),
        Pair(-25, 20), Pair(-110, -48), Pair(-83, 65), Pair(-77, 10), Pair(14, 18), Pair(30, 37), Pair(23, 70), Pair(24, 32),
        Pair(44, 42), Pair(19, 48), Pair(-2, 22), Pair(5, -28), Pair(102, -47), Pair(7, -29), Pair(44, 96), Pair(18, 20),
        Pair(-52, -89), Pair(18, 116), Pair(-43, -45), Pair(-67, -4), Pair(-23, -53), Pair(56, 28), Pair(46, 46), Pair(-31, 45),
        Pair(-69, 26), Pair(-24, 60), Pair(-10, -37), Pair(-59, 59), Pair(-51, -43), Pair(33, 35), Pair(-29, 59), Pair(30, 19),
        Pair(-218, 72), Pair(-184, 114), Pair(-21, 77), Pair(-121, 85), Pair(65, -3), Pair(-83, 20), Pair(-31, 11), Pair(-218, 110)
      },
      { // Piece 4
        Pair(-68, -56), Pair(-16, -42), Pair(19, -13), Pair(26, 10), Pair(-1, -55), Pair(-108, -109), Pair(-14, 1), Pair(3, 5),
        Pair(-33, -125), Pair(-108, -97), Pair(-12, 3), Pair(-60, -49), Pair(-3, 16), Pair(-91, -44), Pair(-1, -46), Pair(-28, -10),
        Pair(-2, -32), Pair(66, 92), Pair(18, -2), Pair(-12, -20), Pair(5, 60), Pair(-8, -6), Pair(39, -48), Pair(30, -93),
        Pair(-32, -54), Pair(-87, -67), Pair(-13, 56), Pair(18, 18), Pair(23, -8), Pair(-14, -21), Pair(-43, -36), Pair(-7, 39),
        Pair(-40, -94), Pair(76, 56), Pair(-72, -45), Pair(27, 56), Pair(77, -25), Pair(36, 94), Pair(20, 90), Pair(-55, -114),
        Pair(-44, -93), Pair(-2, 20), Pair(-12, 57), Pair(-60, -55), Pair(-17, -33), Pair(-106, -65), Pair(51, 86), Pair(-16, -6),
        Pair(47, -35), Pair(-54, -88), Pair(-2, -8), Pair(-79, -43), Pair(-26, -11), Pair(-60, -76), Pair(-12, -17), Pair(-8, -4),
        Pair(-49, -39), Pair(-90, -126), Pair(-9, -4), Pair(-112, -78), Pair(-18, -43), Pair(-126, -95), Pair(-20, -20), Pair(-122, -119)
      },
      { // Piece 5
        Pair(-26, -100), Pair(69, -33), Pair(93, -46), Pair(122, -92), Pair(-44, -36), Pair(125, -47), Pair(-33, 56), Pair(-43, -135),
        Pair(-68, 3), Pair(64, 2), Pair(45, 15), Pair(43, 1), Pair(19, 0), Pair(-141, 63), Pair(22, 28), Pair(-23, 12),
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
        Pair(26, 18), Pair(37, 156), Pair(104, -24), Pair(62, 105), Pair(23, -78), Pair(52, -55), Pair(43, 179), Pair(46, 96),
        Pair(17, 120), Pair(60, 114), Pair(19, 73), Pair(78, -22), Pair(47, 28), Pair(85, 75), Pair(188, 120), Pair(20, 39),
        Pair(9, 1), Pair(-139, 70), Pair(6, 14), Pair(1, 29), Pair(-35, 42), Pair(3, -12), Pair(-102, 37), Pair(-66, 40),
        Pair(-88, 62), Pair(-33, 5), Pair(39, -11), Pair(94, -3), Pair(18, -33), Pair(-64, 7), Pair(-81, 47), Pair(-153, 0),
        Pair(-93, -29), Pair(18, -14), Pair(-38, -24), Pair(-23, -14), Pair(-148, 11), Pair(-83, 15), Pair(-182, 26), Pair(-34, -40),
        Pair(-94, -4), Pair(-116, 61), Pair(-106, -6), Pair(-9, -35), Pair(-48, -54), Pair(-96, 52), Pair(-135, 20), Pair(-184, 27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(37, -33), Pair(8, 25), Pair(-29, -37), Pair(-23, -61), Pair(-11, -103), Pair(16, 10), Pair(-12, -35), Pair(-36, -88),
        Pair(15, 39), Pair(-12, -8), Pair(44, 75), Pair(6, 27), Pair(35, 23), Pair(-10, -45), Pair(-43, -139), Pair(-3, 7),
        Pair(-22, -37), Pair(-10, 2), Pair(61, -44), Pair(107, 70), Pair(34, 9), Pair(69, 77), Pair(27, -52), Pair(-58, -178),
        Pair(2, -44), Pair(34, 66), Pair(67, 2), Pair(-10, -11), Pair(42, 90), Pair(29, 105), Pair(55, 1), Pair(-22, 22),
        Pair(-20, -45), Pair(9, 32), Pair(24, -17), Pair(-17, 6), Pair(84, 100), Pair(4, 9), Pair(4, -16), Pair(6, 47),
        Pair(-2, -40), Pair(-54, -133), Pair(28, 0), Pair(31, 63), Pair(31, 26), Pair(-3, 3), Pair(-11, -82), Pair(-7, -39),
        Pair(-13, -57), Pair(1, 6), Pair(-3, 22), Pair(-11, -24), Pair(-85, -71), Pair(-3, -35), Pair(-15, -40), Pair(-12, -70),
        Pair(-12, -10), Pair(-52, 79), Pair(8, -9), Pair(-1, 54), Pair(-19, -80), Pair(-41, -132), Pair(-75, -110), Pair(-4, -18)
      },
      { // Piece 2
        Pair(-7, -60), Pair(8, -11), Pair(21, 5), Pair(10, -93), Pair(-23, -99), Pair(-24, -120), Pair(-19, -211), Pair(-19, -112),
        Pair(-36, -204), Pair(33, 53), Pair(-4, 20), Pair(5, -109), Pair(29, 31), Pair(14, 34), Pair(70, 51), Pair(-33, -116),
        Pair(-3, 55), Pair(15, -73), Pair(-17, -91), Pair(10, -87), Pair(44, -79), Pair(69, -10), Pair(-43, 19), Pair(-26, -58),
        Pair(-22, 20), Pair(64, -3), Pair(79, -2), Pair(-42, -23), Pair(-3, -14), Pair(-23, -75), Pair(64, -20), Pair(24, 83),
        Pair(-28, -29), Pair(-35, -3), Pair(15, -13), Pair(2, -45), Pair(-23, -42), Pair(3, 67), Pair(37, -2), Pair(10, 25),
        Pair(1, -19), Pair(24, 22), Pair(-10, -8), Pair(-5, -11), Pair(-85, -9), Pair(-27, -98), Pair(-34, -9), Pair(5, -5),
        Pair(32, 10), Pair(64, 80), Pair(16, -54), Pair(-6, -3), Pair(35, -39), Pair(-34, -32), Pair(-48, -61), Pair(23, 23),
        Pair(-10, -109), Pair(-13, -5), Pair(-104, -141), Pair(-4, 75), Pair(-27, 32), Pair(-18, -46), Pair(-3, -52), Pair(-7, -74)
      },
      { // Piece 3
        Pair(79, 72), Pair(29, 44), Pair(-13, 50), Pair(37, 63), Pair(-9, -31), Pair(-47, -18), Pair(4, -11), Pair(4, -45),
        Pair(214, -25), Pair(147, -26), Pair(138, -58), Pair(88, -1), Pair(58, 46), Pair(73, 14), Pair(24, -4), Pair(25, 35),
        Pair(9, 29), Pair(40, 5), Pair(-32, 6), Pair(29, 67), Pair(80, 8), Pair(115, -5), Pair(0, -30), Pair(14, -33),
        Pair(32, 17), Pair(26, -31), Pair(-31, -12), Pair(9, -23), Pair(6, 40), Pair(25, -23), Pair(-10, -26), Pair(-33, -42),
        Pair(-53, -93), Pair(38, 74), Pair(0, -57), Pair(-86, 3), Pair(67, 95), Pair(27, -11), Pair(22, 71), Pair(14, 41),
        Pair(35, -5), Pair(-28, 58), Pair(12, -23), Pair(41, 90), Pair(18, 16), Pair(-3, 3), Pair(56, 94), Pair(-3, -38),
        Pair(-18, -63), Pair(-35, 20), Pair(-12, -105), Pair(26, 11), Pair(-61, -51), Pair(11, 25), Pair(28, 107), Pair(12, 74),
        Pair(-107, 13), Pair(2, 32), Pair(-72, 46), Pair(-59, -79), Pair(39, 41), Pair(-5, 27), Pair(-24, 53), Pair(-55, 78)
      },
      { // Piece 4
        Pair(-37, -74), Pair(-45, -95), Pair(11, 25), Pair(-20, -5), Pair(1, 3), Pair(-17, -41), Pair(-25, -45), Pair(22, 40),
        Pair(-4, -60), Pair(23, 19), Pair(21, -26), Pair(-29, -70), Pair(7, 50), Pair(-5, -14), Pair(7, -59), Pair(-93, -115),
        Pair(4, -6), Pair(-27, -65), Pair(83, 105), Pair(1, -5), Pair(20, 40), Pair(24, 33), Pair(11, 9), Pair(6, 6),
        Pair(23, 3), Pair(37, 40), Pair(9, -26), Pair(52, -14), Pair(-6, -57), Pair(-20, -56), Pair(5, 9), Pair(-13, -18),
        Pair(-19, -26), Pair(-34, -42), Pair(0, -21), Pair(-22, -54), Pair(29, 62), Pair(-26, -60), Pair(-63, -79), Pair(-34, -54),
        Pair(-25, -18), Pair(-53, -81), Pair(25, 48), Pair(-10, -14), Pair(-45, -41), Pair(12, 28), Pair(8, -19), Pair(2, 1),
        Pair(-46, -25), Pair(-10, -1), Pair(34, 70), Pair(-42, -44), Pair(-9, -17), Pair(-8, -17), Pair(39, 46), Pair(-12, -17),
        Pair(-20, -52), Pair(-41, -60), Pair(-1, 4), Pair(-131, -69), Pair(-8, -12), Pair(-7, -9), Pair(-9, -41), Pair(-1, -2)
      },
      { // Piece 5
        Pair(30, -123), Pair(-18, -46), Pair(-105, -10), Pair(90, -47), Pair(-18, -14), Pair(-72, 80), Pair(-19, 11), Pair(8, -115),
        Pair(-33, -50), Pair(37, -7), Pair(49, -9), Pair(72, 11), Pair(54, 59), Pair(134, 48), Pair(4, 8), Pair(38, -33),
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
        Pair(149, 70), Pair(222, 27), Pair(168, 140), Pair(28, 107), Pair(-37, 118), Pair(89, 94), Pair(-10, 136), Pair(291, 42),
        Pair(133, 17), Pair(74, 149), Pair(201, 101), Pair(257, 17), Pair(140, -7), Pair(89, 51), Pair(170, 67), Pair(178, -36),
        Pair(-2, 61), Pair(27, 109), Pair(73, 36), Pair(36, 53), Pair(80, 32), Pair(36, 21), Pair(-89, 53), Pair(19, 3),
        Pair(-112, 46), Pair(-81, 46), Pair(21, 25), Pair(-14, 31), Pair(-75, 28), Pair(-32, 6), Pair(-93, 40), Pair(-105, 27),
        Pair(-93, 38), Pair(30, 19), Pair(-33, 21), Pair(2, -4), Pair(-60, 14), Pair(71, -18), Pair(-104, 20), Pair(-147, 27),
        Pair(-224, 58), Pair(-110, 44), Pair(-92, 13), Pair(-51, 10), Pair(-82, 50), Pair(-90, 11), Pair(-150, 48), Pair(-106, 45),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, -124), Pair(9, 18), Pair(3, -6), Pair(-16, -90), Pair(-2, 9), Pair(35, -6), Pair(-11, -92), Pair(-3, -35),
        Pair(-1, -48), Pair(3, -70), Pair(3, 13), Pair(42, -93), Pair(18, -38), Pair(-104, -40), Pair(-13, -44), Pair(-8, -106),
        Pair(-24, -26), Pair(-36, -41), Pair(26, 36), Pair(105, 59), Pair(158, 75), Pair(6, 27), Pair(75, -29), Pair(40, 5),
        Pair(8, 10), Pair(-56, -52), Pair(6, 21), Pair(56, -44), Pair(-2, -38), Pair(-46, -7), Pair(110, 19), Pair(22, -176),
        Pair(-38, -52), Pair(1, 37), Pair(-54, -18), Pair(-53, 14), Pair(163, 70), Pair(-1, 9), Pair(-16, -66), Pair(-7, -12),
        Pair(-24, -137), Pair(-58, -41), Pair(-49, 72), Pair(-73, -3), Pair(61, -39), Pair(-8, -11), Pair(-49, -124), Pair(-2, 32),
        Pair(7, -23), Pair(-74, -44), Pair(8, 1), Pair(-88, 5), Pair(-6, -52), Pair(-28, -32), Pair(-13, 5), Pair(-4, -8),
        Pair(-60, -98), Pair(-24, 101), Pair(-49, 23), Pair(-49, -39), Pair(29, 86), Pair(-42, -31), Pair(-92, -88), Pair(-15, -59)
      },
      { // Piece 2
        Pair(-25, -170), Pair(-3, -125), Pair(-27, -14), Pair(71, 4), Pair(-12, -40), Pair(39, -57), Pair(23, -91), Pair(-26, -23),
        Pair(-45, -155), Pair(35, -66), Pair(-10, -108), Pair(55, -118), Pair(71, -62), Pair(75, -53), Pair(12, -95), Pair(-20, -78),
        Pair(-36, -36), Pair(-18, -40), Pair(94, -73), Pair(0, -130), Pair(1, -48), Pair(117, -45), Pair(50, -44), Pair(-85, -30),
        Pair(-24, -128), Pair(-5, 28), Pair(40, -21), Pair(30, -84), Pair(114, -8), Pair(42, -96), Pair(-36, 3), Pair(62, -63),
        Pair(35, -64), Pair(118, -112), Pair(21, -60), Pair(177, -61), Pair(75, -75), Pair(138, -77), Pair(-50, -73), Pair(95, 67),
        Pair(-59, -37), Pair(96, -98), Pair(6, -12), Pair(64, -30), Pair(-34, -69), Pair(62, -61), Pair(-34, -62), Pair(-22, 67),
        Pair(-34, 37), Pair(-66, 9), Pair(78, -30), Pair(5, 6), Pair(-1, -11), Pair(98, -18), Pair(-44, -43), Pair(-9, -91),
        Pair(6, -120), Pair(-16, 10), Pair(-52, -8), Pair(-73, 44), Pair(-15, 12), Pair(-16, -44), Pair(-7, -10), Pair(16, -51)
      },
      { // Piece 3
        Pair(50, -57), Pair(-8, -10), Pair(82, -53), Pair(-81, -11), Pair(102, -69), Pair(16, -33), Pair(17, -6), Pair(161, -74),
        Pair(-18, -61), Pair(20, -50), Pair(-26, -62), Pair(61, -78), Pair(1, -90), Pair(0, -96), Pair(17, -60), Pair(-11, -6),
        Pair(-30, -36), Pair(33, -38), Pair(-79, -50), Pair(-34, -43), Pair(56, -78), Pair(-9, -17), Pair(31, -25), Pair(2, -49),
        Pair(-84, -82), Pair(-40, 6), Pair(12, -51), Pair(-181, -54), Pair(64, -29), Pair(40, -52), Pair(99, -88), Pair(47, -11),
        Pair(-28, -37), Pair(54, -74), Pair(25, 42), Pair(13, -26), Pair(7, -5), Pair(-29, -33), Pair(55, -25), Pair(-33, -13),
        Pair(-57, -48), Pair(-60, -26), Pair(-15, -73), Pair(-48, -22), Pair(-138, -56), Pair(13, -43), Pair(114, -11), Pair(-16, -79),
        Pair(-18, -58), Pair(19, -19), Pair(-13, -118), Pair(-126, 7), Pair(39, -19), Pair(-59, 7), Pair(-28, -16), Pair(-74, -66),
        Pair(-267, -28), Pair(-69, 44), Pair(-24, 3), Pair(-184, -6), Pair(-169, -17), Pair(-26, -27), Pair(-61, -36), Pair(-147, 16)
      },
      { // Piece 4
        Pair(17, -149), Pair(-159, 8), Pair(-48, -96), Pair(-49, -100), Pair(-45, -108), Pair(-166, -128), Pair(-28, -47), Pair(-84, -85),
        Pair(21, 50), Pair(-45, -36), Pair(15, 2), Pair(28, 8), Pair(-19, -82), Pair(-31, 3), Pair(-30, -18), Pair(46, 28),
        Pair(-59, -37), Pair(-9, -71), Pair(-21, -22), Pair(-31, -19), Pair(-6, -75), Pair(-28, -37), Pair(-48, -100), Pair(-99, -154),
        Pair(-8, -29), Pair(58, 34), Pair(33, 48), Pair(-14, -18), Pair(7, 37), Pair(-4, 6), Pair(-17, -24), Pair(5, -45),
        Pair(-45, -82), Pair(-20, -53), Pair(-24, -33), Pair(2, 22), Pair(-58, -20), Pair(-16, -55), Pair(-36, 4), Pair(-42, -86),
        Pair(1, -81), Pair(8, -17), Pair(-21, -43), Pair(-42, -57), Pair(-85, -34), Pair(-84, -98), Pair(-30, -48), Pair(-59, -115),
        Pair(2, 43), Pair(-48, -17), Pair(-23, 34), Pair(-8, 22), Pair(-77, -86), Pair(48, 33), Pair(-20, -36), Pair(-8, -15),
        Pair(-69, -75), Pair(-84, -101), Pair(-38, -67), Pair(-94, -39), Pair(-68, -48), Pair(-11, -5), Pair(-32, -106), Pair(-63, -105)
      },
      { // Piece 5
        Pair(155, -170), Pair(-9, -69), Pair(33, -33), Pair(-32, -32), Pair(-59, 14), Pair(-16, 6), Pair(-142, 35), Pair(92, -90),
        Pair(13, -64), Pair(83, -11), Pair(26, 17), Pair(-33, 32), Pair(20, 14), Pair(10, 31), Pair(-13, 25), Pair(-11, -38),
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
        Pair(-48, 56), Pair(11, 149), Pair(146, 163), Pair(156, 163), Pair(-19, 136), Pair(66, 140), Pair(-41, 113), Pair(-75, 144),
        Pair(74, 76), Pair(36, 131), Pair(207, 91), Pair(36, 140), Pair(69, 91), Pair(162, 140), Pair(27, 109), Pair(9, 56),
        Pair(-75, 85), Pair(-136, 82), Pair(4, 57), Pair(19, 37), Pair(100, -13), Pair(74, 40), Pair(-135, 86), Pair(-48, 55),
        Pair(-44, 45), Pair(-141, 56), Pair(8, 52), Pair(-40, 28), Pair(54, 19), Pair(-13, 9), Pair(-33, 42), Pair(-161, 20),
        Pair(-113, 48), Pair(-66, 29), Pair(-58, 1), Pair(45, 23), Pair(-112, 37), Pair(151, -29), Pair(-168, 32), Pair(-111, 24),
        Pair(-92, 61), Pair(-112, 54), Pair(27, 45), Pair(41, 88), Pair(14, -21), Pair(-89, 37), Pair(-95, 46), Pair(-139, 36),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-51, -133), Pair(-51, -57), Pair(-20, -103), Pair(13, -59), Pair(-26, -46), Pair(28, -85), Pair(17, -36), Pair(-30, -184),
        Pair(-21, -58), Pair(-52, -59), Pair(-67, -119), Pair(-32, -44), Pair(19, -48), Pair(17, -41), Pair(-21, -88), Pair(-13, -73),
        Pair(-71, -129), Pair(29, -9), Pair(39, -15), Pair(61, -53), Pair(142, 46), Pair(45, -66), Pair(3, -15), Pair(-5, -53),
        Pair(28, -28), Pair(-17, -85), Pair(50, -5), Pair(-30, -26), Pair(57, -65), Pair(8, -36), Pair(23, 12), Pair(2, -29),
        Pair(6, -36), Pair(-79, 17), Pair(10, 8), Pair(32, -33), Pair(168, 64), Pair(31, -26), Pair(6, -34), Pair(-15, -78),
        Pair(-28, -23), Pair(-4, 1), Pair(-60, -34), Pair(9, 0), Pair(0, -32), Pair(-11, -70), Pair(-6, -2), Pair(-22, -73),
        Pair(16, -82), Pair(-20, -45), Pair(-51, -77), Pair(-17, 18), Pair(-13, 0), Pair(-56, -42), Pair(-30, -98), Pair(52, 66),
        Pair(-23, -86), Pair(-1, -29), Pair(2, -3), Pair(-11, -68), Pair(3, -98), Pair(-24, 10), Pair(-28, -81), Pair(1, -2)
      },
      { // Piece 2
        Pair(11, -58), Pair(4, -140), Pair(67, 2), Pair(93, -38), Pair(-86, -68), Pair(-24, -62), Pair(17, -85), Pair(5, -80),
        Pair(-52, -95), Pair(38, -72), Pair(3, -92), Pair(34, -95), Pair(-48, -127), Pair(-8, -83), Pair(16, -129), Pair(-28, -110),
        Pair(-8, -33), Pair(-27, -57), Pair(35, -81), Pair(-18, -94), Pair(52, -69), Pair(60, -64), Pair(-20, -107), Pair(-85, -91),
        Pair(-43, -22), Pair(64, -20), Pair(171, -17), Pair(47, -67), Pair(97, -84), Pair(-38, -39), Pair(57, -29), Pair(38, -62),
        Pair(-21, -82), Pair(8, -79), Pair(33, -97), Pair(60, -71), Pair(81, -61), Pair(64, -54), Pair(-33, -49), Pair(109, 85),
        Pair(10, -58), Pair(17, -99), Pair(-19, -63), Pair(39, -83), Pair(44, -19), Pair(-19, 8), Pair(-5, -77), Pair(1, -60),
        Pair(4, -12), Pair(21, -3), Pair(22, -2), Pair(17, -44), Pair(63, -60), Pair(-4, -44), Pair(-25, -66), Pair(17, -70),
        Pair(-3, 43), Pair(10, 24), Pair(-101, -61), Pair(-18, 24), Pair(-51, -80), Pair(-37, -14), Pair(-48, -139), Pair(-18, -23)
      },
      { // Piece 3
        Pair(85, -87), Pair(-59, -38), Pair(109, -104), Pair(-13, -105), Pair(21, -62), Pair(43, -90), Pair(-84, -60), Pair(41, -91),
        Pair(42, -96), Pair(28, -68), Pair(29, -69), Pair(48, -97), Pair(123, -128), Pair(41, -132), Pair(34, -138), Pair(111, -69),
        Pair(-44, -120), Pair(-95, -60), Pair(-44, -125), Pair(30, -39), Pair(4, -97), Pair(5, -22), Pair(-16, -83), Pair(-28, -130),
        Pair(-19, -84), Pair(65, -104), Pair(28, -92), Pair(-39, -79), Pair(-19, -73), Pair(79, -93), Pair(130, -98), Pair(9, -44),
        Pair(-66, -57), Pair(-34, -35), Pair(7, -89), Pair(9, -114), Pair(64, -103), Pair(38, -103), Pair(-32, -107), Pair(-19, -84),
        Pair(-28, -72), Pair(-12, -62), Pair(23, -116), Pair(-33, -95), Pair(1, -62), Pair(-75, -55), Pair(15, -52), Pair(18, -55),
        Pair(-38, -95), Pair(-59, -54), Pair(2, -66), Pair(-13, -94), Pair(-64, -56), Pair(-67, -83), Pair(-57, -87), Pair(-60, -82),
        Pair(-154, -88), Pair(-89, -49), Pair(-19, -88), Pair(-76, -111), Pair(44, -46), Pair(-115, -31), Pair(-13, -89), Pair(-200, -113)
      },
      { // Piece 4
        Pair(-8, -128), Pair(-94, -105), Pair(-88, -155), Pair(21, -16), Pair(-48, -69), Pair(30, -69), Pair(36, -105), Pair(-2, -146),
        Pair(53, 9), Pair(-51, 22), Pair(32, -36), Pair(-42, -74), Pair(-5, -36), Pair(-22, -93), Pair(-12, -30), Pair(4, -4),
        Pair(-12, -16), Pair(-3, -16), Pair(0, -38), Pair(49, 84), Pair(37, 49), Pair(36, 28), Pair(84, 132), Pair(0, 0),
        Pair(-2, -17), Pair(-52, -21), Pair(-8, -31), Pair(-34, -7), Pair(-29, -50), Pair(10, 14), Pair(1, 13), Pair(-9, -24),
        Pair(-6, -14), Pair(-36, -84), Pair(-25, -30), Pair(21, 15), Pair(-84, 12), Pair(36, 26), Pair(-32, -70), Pair(-23, -61),
        Pair(35, 54), Pair(25, 53), Pair(-46, -64), Pair(18, 59), Pair(7, 2), Pair(-5, -6), Pair(-43, -30), Pair(50, 66),
        Pair(-16, -31), Pair(-36, -61), Pair(-40, -31), Pair(-16, -42), Pair(-29, -37), Pair(-67, -117), Pair(-20, -37), Pair(5, 24),
        Pair(8, 36), Pair(-46, -105), Pair(0, -10), Pair(59, 70), Pair(-92, -170), Pair(-50, -70), Pair(-44, -83), Pair(-61, -124)
      },
      { // Piece 5
        Pair(59, -89), Pair(184, -103), Pair(-28, -20), Pair(39, 1), Pair(27, -39), Pair(-128, 15), Pair(-10, -10), Pair(-37, -101),
        Pair(38, -40), Pair(100, 0), Pair(-52, 25), Pair(74, -6), Pair(13, 27), Pair(-29, 39), Pair(125, 13), Pair(-63, -3),
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
        Pair(-103, 99), Pair(56, 111), Pair(36, 181), Pair(6, 218), Pair(38, 106), Pair(-42, 187), Pair(20, 126), Pair(-20, 160),
        Pair(-4, 122), Pair(7, 187), Pair(130, 144), Pair(-15, 244), Pair(-60, 145), Pair(11, 197), Pair(-7, 117), Pair(-24, 130),
        Pair(-31, 83), Pair(-42, 123), Pair(34, 107), Pair(4, 109), Pair(12, 57), Pair(8, 63), Pair(-114, 123), Pair(-102, 91),
        Pair(-132, 76), Pair(-66, 80), Pair(6, 83), Pair(15, 36), Pair(-58, 72), Pair(-89, 29), Pair(35, 37), Pair(-200, 77),
        Pair(-165, 80), Pair(-105, 69), Pair(17, 16), Pair(8, 15), Pair(-42, 69), Pair(21, 19), Pair(-59, 32), Pair(-194, 67),
        Pair(-95, 67), Pair(-86, 96), Pair(-4, 39), Pair(-3, -4), Pair(-104, 79), Pair(-99, 25), Pair(-5, 34), Pair(-102, 82),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-44, -37), Pair(9, -142), Pair(3, -112), Pair(-18, -98), Pair(-50, -88), Pair(-14, -111), Pair(-37, -160), Pair(-32, -96),
        Pair(-14, -195), Pair(5, -97), Pair(-31, -44), Pair(-69, -96), Pair(7, -141), Pair(-11, -84), Pair(5, -28), Pair(-13, -49),
        Pair(4, 11), Pair(-28, -102), Pair(-22, -32), Pair(-49, -92), Pair(170, -17), Pair(8, -38), Pair(8, -122), Pair(-15, -85),
        Pair(-8, -142), Pair(-32, -2), Pair(-48, -135), Pair(26, -14), Pair(89, -29), Pair(19, -46), Pair(-17, -28), Pair(-44, -104),
        Pair(-24, -25), Pair(-34, -105), Pair(-29, -38), Pair(9, -36), Pair(58, 31), Pair(-26, 4), Pair(-79, -93), Pair(-16, 4),
        Pair(-7, -2), Pair(-3, -96), Pair(-53, -84), Pair(28, -33), Pair(8, -21), Pair(31, 8), Pair(-31, -45), Pair(-59, 14),
        Pair(13, -6), Pair(-14, -77), Pair(-10, -20), Pair(-15, -91), Pair(-4, -43), Pair(3, -88), Pair(-43, -44), Pair(6, -39),
        Pair(-12, -16), Pair(-44, -105), Pair(-30, 4), Pair(34, 34), Pair(-7, -58), Pair(-10, 11), Pair(12, 26), Pair(-1, 22)
      },
      { // Piece 2
        Pair(-31, 25), Pair(-15, -35), Pair(-5, -52), Pair(43, 1), Pair(-36, -64), Pair(-23, -104), Pair(-73, -93), Pair(23, 58),
        Pair(13, -55), Pair(7, -61), Pair(32, -83), Pair(-43, -98), Pair(3, -19), Pair(-7, -48), Pair(39, 8), Pair(2, -12),
        Pair(1, -69), Pair(83, -24), Pair(39, 9), Pair(12, -53), Pair(6, -48), Pair(5, -36), Pair(53, -25), Pair(19, -63),
        Pair(-22, -35), Pair(-65, -65), Pair(-45, 11), Pair(56, -73), Pair(-14, -23), Pair(-51, -59), Pair(24, -33), Pair(-14, -124),
        Pair(12, -95), Pair(35, -58), Pair(-29, -32), Pair(77, -21), Pair(7, -61), Pair(-16, -93), Pair(-10, -96), Pair(58, -37),
        Pair(17, 19), Pair(-17, -37), Pair(17, -70), Pair(-25, -63), Pair(-9, 5), Pair(-11, -37), Pair(36, -32), Pair(-24, -53),
        Pair(-45, -63), Pair(-6, -45), Pair(-57, -124), Pair(-17, -51), Pair(-40, -39), Pair(-19, -21), Pair(-109, -35), Pair(22, -13),
        Pair(7, 32), Pair(10, 1), Pair(30, 32), Pair(-8, -4), Pair(-6, -75), Pair(-23, -46), Pair(-21, 3), Pair(-17, 47)
      },
      { // Piece 3
        Pair(-11, -66), Pair(84, -60), Pair(-96, -128), Pair(-9, -127), Pair(18, -50), Pair(-26, -57), Pair(3, -110), Pair(82, -114),
        Pair(56, -123), Pair(-9, -78), Pair(-9, -101), Pair(6, -51), Pair(40, -98), Pair(-31, -115), Pair(20, -98), Pair(-52, -164),
        Pair(45, -98), Pair(120, -62), Pair(79, -42), Pair(133, -105), Pair(-26, -97), Pair(84, -73), Pair(25, -65), Pair(-1, -112),
        Pair(-37, -169), Pair(6, -56), Pair(-6, -73), Pair(-8, -110), Pair(-57, -3), Pair(-26, -110), Pair(-28, -150), Pair(-44, -35),
        Pair(-60, -113), Pair(28, -72), Pair(58, -106), Pair(32, -97), Pair(18, -75), Pair(-16, -86), Pair(36, -77), Pair(37, -57),
        Pair(-42, -91), Pair(-8, -63), Pair(37, -139), Pair(-23, -118), Pair(-12, -67), Pair(-35, -101), Pair(-23, -69), Pair(-8, -58),
        Pair(-82, -99), Pair(56, -76), Pair(46, -73), Pair(132, -139), Pair(42, -152), Pair(74, -108), Pair(65, -54), Pair(-93, -82),
        Pair(-9, -82), Pair(29, -7), Pair(57, -60), Pair(65, -75), Pair(-49, -116), Pair(-86, -125), Pair(-18, -143), Pair(-26, -49)
      },
      { // Piece 4
        Pair(-132, -159), Pair(-91, -152), Pair(-49, -84), Pair(-4, -69), Pair(131, -60), Pair(9, -29), Pair(-43, -63), Pair(30, -124),
        Pair(-9, -58), Pair(-7, -100), Pair(16, 33), Pair(-11, -74), Pair(-60, -74), Pair(9, 30), Pair(-72, -147), Pair(-74, -82),
        Pair(-10, -72), Pair(-40, -83), Pair(-91, -93), Pair(37, -25), Pair(-1, -60), Pair(-13, -25), Pair(-49, -91), Pair(-57, -65),
        Pair(2, 4), Pair(42, 73), Pair(19, 20), Pair(9, 6), Pair(2, -2), Pair(8, 8), Pair(19, 38), Pair(4, 9),
        Pair(-5, -26), Pair(-28, -77), Pair(47, 33), Pair(54, 36), Pair(51, 64), Pair(4, 44), Pair(33, 38), Pair(1, -25),
        Pair(43, 23), Pair(53, 75), Pair(-14, -40), Pair(-9, -41), Pair(-26, -31), Pair(-1, 10), Pair(-48, -69), Pair(-38, -33),
        Pair(49, 52), Pair(-35, -96), Pair(-40, -88), Pair(11, 10), Pair(23, 72), Pair(8, -12), Pair(-22, -45), Pair(-52, -86),
        Pair(-53, -96), Pair(-25, -56), Pair(-9, -16), Pair(-16, -44), Pair(6, -20), Pair(-23, -72), Pair(-27, -41), Pair(-41, -61)
      },
      { // Piece 5
        Pair(-32, -77), Pair(56, -58), Pair(-58, -18), Pair(-93, 11), Pair(64, -29), Pair(-50, -18), Pair(40, -22), Pair(-21, -79),
        Pair(-62, -29), Pair(128, -32), Pair(15, -2), Pair(82, -6), Pair(58, 21), Pair(2, 28), Pair(46, -8), Pair(7, -23),
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
        Pair(-103, 109), Pair(81, 118), Pair(40, 107), Pair(51, 98), Pair(103, 162), Pair(76, 176), Pair(-43, 127), Pair(-74, 92),
        Pair(-122, 169), Pair(51, 185), Pair(124, 148), Pair(-61, 188), Pair(80, 165), Pair(43, 170), Pair(-66, 202), Pair(-148, 174),
        Pair(-165, 153), Pair(-61, 93), Pair(-38, 113), Pair(19, 122), Pair(-11, 107), Pair(-80, 122), Pair(-120, 102), Pair(-73, 81),
        Pair(-69, 91), Pair(-105, 96), Pair(8, 73), Pair(79, 17), Pair(16, 80), Pair(-96, 59), Pair(-4, 72), Pair(-116, 60),
        Pair(-83, 71), Pair(-46, 53), Pair(-51, 31), Pair(-18, 34), Pair(24, 51), Pair(17, 38), Pair(-93, 66), Pair(-34, 32),
        Pair(-150, 66), Pair(-56, 89), Pair(-65, 60), Pair(6, 89), Pair(-57, 74), Pair(-122, 76), Pair(-59, 87), Pair(-63, 75),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-22, -135), Pair(-64, -139), Pair(10, -81), Pair(-2, -42), Pair(-32, -51), Pair(-15, -80), Pair(4, -126), Pair(17, 86),
        Pair(0, -81), Pair(-23, -154), Pair(-19, -16), Pair(3, -59), Pair(-33, -114), Pair(-101, -94), Pair(-16, -114), Pair(-9, -110),
        Pair(-4, -147), Pair(-72, -155), Pair(29, -123), Pair(28, -39), Pair(-2, -158), Pair(8, -81), Pair(49, -92), Pair(-8, -44),
        Pair(-33, -95), Pair(-35, -33), Pair(22, -28), Pair(29, -70), Pair(-18, -104), Pair(-57, -35), Pair(19, -117), Pair(-16, -145),
        Pair(-7, -106), Pair(-22, -95), Pair(44, -51), Pair(-3, -41), Pair(28, -70), Pair(-54, -109), Pair(-26, -114), Pair(-17, -152),
        Pair(-17, -68), Pair(-23, -84), Pair(-43, -144), Pair(24, -102), Pair(-45, -147), Pair(-73, -1), Pair(-2, -94), Pair(-20, -75),
        Pair(-40, -95), Pair(0, -34), Pair(-14, -82), Pair(-10, 7), Pair(-46, -23), Pair(-5, -105), Pair(-1, -93), Pair(-26, -73),
        Pair(-15, -80), Pair(12, -21), Pair(-18, -179), Pair(0, -32), Pair(-1, -73), Pair(-38, -49), Pair(-11, 10), Pair(-1, -58)
      },
      { // Piece 2
        Pair(-2, -32), Pair(38, -9), Pair(-75, -121), Pair(25, -4), Pair(-35, -85), Pair(-10, -37), Pair(-46, -54), Pair(23, -62),
        Pair(-66, -94), Pair(4, -78), Pair(-27, -68), Pair(12, -22), Pair(3, 0), Pair(14, -58), Pair(2, -89), Pair(42, -35),
        Pair(-86, -99), Pair(-45, -28), Pair(17, -64), Pair(44, -53), Pair(19, -101), Pair(-106, 2), Pair(-33, -64), Pair(20, -50),
        Pair(-3, 37), Pair(-50, -27), Pair(-34, -21), Pair(-63, -93), Pair(24, -80), Pair(138, 13), Pair(1, -36), Pair(-8, -53),
        Pair(6, 38), Pair(-12, -73), Pair(-6, -51), Pair(-16, -27), Pair(65, -2), Pair(-34, 7), Pair(-10, 34), Pair(-28, -67),
        Pair(-1, -56), Pair(6, -83), Pair(6, -46), Pair(-3, -39), Pair(-23, -113), Pair(-5, -163), Pair(5, -58), Pair(-11, -88),
        Pair(-12, 70), Pair(-9, -52), Pair(-58, -95), Pair(38, -79), Pair(-46, -45), Pair(-9, -21), Pair(-11, -128), Pair(-23, 71),
        Pair(-33, -72), Pair(32, 8), Pair(4, -74), Pair(8, -26), Pair(-76, -47), Pair(-16, -16), Pair(-13, 57), Pair(-28, -79)
      },
      { // Piece 3
        Pair(165, -233), Pair(54, -160), Pair(30, -168), Pair(-44, -139), Pair(22, -147), Pair(13, -123), Pair(103, -175), Pair(51, -169),
        Pair(-10, -161), Pair(-29, -155), Pair(16, -112), Pair(24, -150), Pair(43, -125), Pair(32, -121), Pair(-25, -184), Pair(-3, -174),
        Pair(-21, -143), Pair(58, -124), Pair(29, -135), Pair(-46, -171), Pair(28, -135), Pair(22, -180), Pair(36, -135), Pair(29, -99),
        Pair(92, -153), Pair(-28, -142), Pair(18, -197), Pair(-50, -101), Pair(60, -158), Pair(53, -179), Pair(56, -143), Pair(-54, -134),
        Pair(-45, -122), Pair(-8, -121), Pair(1, -156), Pair(-26, -131), Pair(90, -157), Pair(-4, -165), Pair(-9, -175), Pair(-23, -194),
        Pair(-49, -136), Pair(-39, -174), Pair(-28, -182), Pair(41, -128), Pair(7, -177), Pair(-144, -153), Pair(-8, -71), Pair(-44, -176),
        Pair(0, -162), Pair(-30, -115), Pair(-36, -107), Pair(18, -112), Pair(-18, -130), Pair(-33, -139), Pair(-67, -126), Pair(34, -113),
        Pair(-39, -91), Pair(-28, -129), Pair(25, -129), Pair(14, -181), Pair(40, -123), Pair(-50, -149), Pair(9, -131), Pair(18, -99)
      },
      { // Piece 4
        Pair(-65, -171), Pair(-84, -86), Pair(-81, -59), Pair(6, -35), Pair(-13, -69), Pair(-133, -113), Pair(-43, -63), Pair(-34, -157),
        Pair(4, -37), Pair(-63, -85), Pair(-29, -50), Pair(24, -3), Pair(-27, -44), Pair(2, -81), Pair(-42, -75), Pair(-62, -83),
        Pair(-66, -68), Pair(-19, -81), Pair(-5, -14), Pair(-18, -51), Pair(-19, 11), Pair(-31, -65), Pair(10, -6), Pair(-36, -56),
        Pair(-41, -99), Pair(42, 13), Pair(2, -45), Pair(-37, -73), Pair(3, -6), Pair(24, 21), Pair(59, -3), Pair(-1, -60),
        Pair(-43, -80), Pair(-9, 5), Pair(-6, -11), Pair(-3, 7), Pair(4, -14), Pair(40, 48), Pair(-48, -76), Pair(-26, -51),
        Pair(-62, -108), Pair(8, 26), Pair(-12, -23), Pair(15, -27), Pair(27, 46), Pair(36, 22), Pair(7, 2), Pair(-21, -31),
        Pair(-22, -73), Pair(-34, -89), Pair(-51, -116), Pair(-32, -90), Pair(-3, -26), Pair(9, 16), Pair(-19, -55), Pair(10, 6),
        Pair(-23, -63), Pair(-2, -59), Pair(-107, -205), Pair(16, 29), Pair(-15, -53), Pair(-12, -22), Pair(-43, -113), Pair(-28, -25)
      },
      { // Piece 5
        Pair(104, -99), Pair(4, -41), Pair(1, -52), Pair(-64, 3), Pair(-10, -29), Pair(-11, -21), Pair(71, -48), Pair(93, -93),
        Pair(-91, -44), Pair(-12, -14), Pair(-54, -7), Pair(76, -18), Pair(10, -7), Pair(14, 14), Pair(56, 16), Pair(-32, 1),
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
        Pair(-127, 35), Pair(-20, 134), Pair(30, 229), Pair(30, 154), Pair(8, 195), Pair(62, 194), Pair(-79, 134), Pair(-36, 129),
        Pair(-119, 193), Pair(-28, 163), Pair(36, 165), Pair(59, 111), Pair(2, 195), Pair(-33, 200), Pair(-10, 109), Pair(-161, 158),
        Pair(-149, 87), Pair(5, 54), Pair(-39, 147), Pair(8, 185), Pair(-61, 119), Pair(48, 141), Pair(-67, 141), Pair(-60, 122),
        Pair(-84, 23), Pair(-82, 79), Pair(35, 113), Pair(12, 60), Pair(10, 110), Pair(-8, 55), Pair(-67, 76), Pair(-33, 73),
        Pair(-76, -26), Pair(-69, 26), Pair(12, 32), Pair(3, 93), Pair(-2, 2), Pair(12, 10), Pair(3, 83), Pair(9, 21),
        Pair(-53, 10), Pair(-126, 101), Pair(12, 28), Pair(-1, 86), Pair(-23, -36), Pair(-5, 132), Pair(22, 34), Pair(-26, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-5, -11), Pair(-28, -77), Pair(7, 40), Pair(-8, -70), Pair(-7, -106), Pair(-2, 1), Pair(-9, -109), Pair(2, -63),
        Pair(-1, -41), Pair(6, -96), Pair(-28, -59), Pair(-55, -58), Pair(-9, 5), Pair(-12, -56), Pair(-12, -54), Pair(-39, -87),
        Pair(34, -7), Pair(-17, -63), Pair(-44, -59), Pair(-25, -52), Pair(-30, -116), Pair(-3, -68), Pair(35, -85), Pair(-16, -77),
        Pair(-16, -18), Pair(-9, -19), Pair(11, -46), Pair(18, -3), Pair(14, -44), Pair(2, -23), Pair(1, 3), Pair(-9, -136),
        Pair(-17, -20), Pair(10, -92), Pair(-30, -44), Pair(-43, -83), Pair(20, -76), Pair(-5, 2), Pair(-15, -104), Pair(10, 30),
        Pair(-14, -32), Pair(-12, -9), Pair(16, 21), Pair(-26, -100), Pair(20, 37), Pair(2, 26), Pair(5, -40), Pair(-7, -7),
        Pair(-9, -106), Pair(22, 81), Pair(-4, -114), Pair(-2, -52), Pair(-9, -63), Pair(-3, 23), Pair(-3, -24), Pair(-1, -12),
        Pair(-2, -37), Pair(32, 3), Pair(4, -7), Pair(6, 63), Pair(-10, -78), Pair(-3, -32), Pair(5, 21), Pair(-7, -60)
      },
      { // Piece 2
        Pair(10, -27), Pair(34, -8), Pair(11, 16), Pair(-4, -35), Pair(-2, 46), Pair(6, -88), Pair(-2, -65), Pair(4, 32),
        Pair(-6, -4), Pair(-57, -54), Pair(-48, -26), Pair(-9, -46), Pair(-80, -64), Pair(-2, -15), Pair(19, 88), Pair(2, -31),
        Pair(-2, 14), Pair(-15, -5), Pair(-3, 70), Pair(13, -60), Pair(-6, -47), Pair(-39, 17), Pair(9, -68), Pair(-11, -67),
        Pair(-5, -25), Pair(-2, 40), Pair(8, -3), Pair(-20, 61), Pair(41, -35), Pair(-5, -61), Pair(-31, 47), Pair(-8, -138),
        Pair(1, 39), Pair(-8, 104), Pair(-10, 65), Pair(5, -47), Pair(-65, -41), Pair(18, 29), Pair(2, 15), Pair(1, 60),
        Pair(-1, -64), Pair(-7, 29), Pair(-19, -43), Pair(-1, -1), Pair(-37, -26), Pair(-4, -66), Pair(-2, 20), Pair(9, 8),
        Pair(-37, -20), Pair(20, 45), Pair(30, 69), Pair(-4, -85), Pair(47, 108), Pair(-9, -25), Pair(11, 36), Pair(2, 0),
        Pair(-12, 29), Pair(-1, -24), Pair(-13, -95), Pair(2, -118), Pair(-9, -21), Pair(-10, -47), Pair(-7, -51), Pair(-16, 23)
      },
      { // Piece 3
        Pair(4, -52), Pair(22, -45), Pair(3, -122), Pair(-16, -45), Pair(-51, -53), Pair(-1, -121), Pair(-23, -23), Pair(-10, -98),
        Pair(-9, -125), Pair(-5, -46), Pair(15, -54), Pair(-2, -11), Pair(2, -66), Pair(-45, -96), Pair(-28, 5), Pair(29, -26),
        Pair(-1, -73), Pair(-3, -98), Pair(-16, -148), Pair(28, 7), Pair(-25, -102), Pair(19, -17), Pair(16, -99), Pair(-42, 5),
        Pair(11, -8), Pair(-8, -118), Pair(-19, -89), Pair(10, -116), Pair(-16, -126), Pair(88, -59), Pair(-59, -113), Pair(-24, -56),
        Pair(35, -114), Pair(47, -72), Pair(-3, -91), Pair(-14, -116), Pair(11, -35), Pair(-31, -82), Pair(28, 20), Pair(-7, -66),
        Pair(27, -66), Pair(-14, -135), Pair(-7, -100), Pair(57, -85), Pair(-36, -133), Pair(2, -39), Pair(-27, -116), Pair(-50, -104),
        Pair(1, 50), Pair(-16, 44), Pair(-79, -103), Pair(0, -5), Pair(20, -77), Pair(-43, -93), Pair(3, -64), Pair(21, -98),
        Pair(-18, -38), Pair(27, -73), Pair(7, -7), Pair(23, 9), Pair(58, -50), Pair(-29, -56), Pair(-29, -76), Pair(-27, -98)
      },
      { // Piece 4
        Pair(15, -56), Pair(-76, -77), Pair(-10, 18), Pair(7, 8), Pair(-26, 33), Pair(-81, -66), Pair(-54, -90), Pair(83, -70),
        Pair(-19, -54), Pair(9, -11), Pair(-45, -111), Pair(-21, -43), Pair(7, -47), Pair(-12, -15), Pair(14, 26), Pair(-123, -221),
        Pair(24, 40), Pair(-24, -19), Pair(-14, -18), Pair(-39, -53), Pair(21, 23), Pair(41, 59), Pair(-24, -15), Pair(-67, -98),
        Pair(-7, -17), Pair(30, 79), Pair(22, -14), Pair(-31, -46), Pair(42, 107), Pair(14, 50), Pair(-30, -34), Pair(-7, -8),
        Pair(35, 62), Pair(12, 14), Pair(-13, -36), Pair(-42, -16), Pair(-14, -2), Pair(-34, -60), Pair(9, -13), Pair(38, 74),
        Pair(-25, -76), Pair(52, 80), Pair(19, 45), Pair(29, 4), Pair(-7, 24), Pair(0, 0), Pair(6, -21), Pair(-7, -22),
        Pair(23, -44), Pair(-5, -29), Pair(49, 71), Pair(18, 51), Pair(-24, -24), Pair(-6, 19), Pair(-11, -16), Pair(47, 70),
        Pair(-28, -91), Pair(9, 29), Pair(52, 93), Pair(-27, -68), Pair(-4, 16), Pair(-45, -105), Pair(-29, -67), Pair(-15, -41)
      },
      { // Piece 5
        Pair(-87, -74), Pair(53, -32), Pair(189, -19), Pair(-95, 29), Pair(-16, 62), Pair(3, 10), Pair(12, -51), Pair(24, -112),
        Pair(43, 11), Pair(-9, 33), Pair(38, 10), Pair(-13, 50), Pair(-59, 3), Pair(-17, 32), Pair(-5, 12), Pair(-79, 54),
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
  Pair(-14, 47), Pair(0, 37), Pair(10, 61), Pair(16, 72), Pair(20, 81), Pair(25, 91), Pair(31, 91), Pair(34, 90),
  Pair(36, 83)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-29, 14), Pair(-18, 0), Pair(-8, 19), Pair(-2, 33), Pair(4, 44), Pair(6, 55), Pair(9, 60), Pair(12, 65),
  Pair(13, 70), Pair(17, 70), Pair(26, 68), Pair(30, 72), Pair(24, 90), Pair(18, 75)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-40, -27), Pair(-28, 3), Pair(-24, 12), Pair(-22, 24), Pair(-20, 27), Pair(-13, 31), Pair(-10, 37), Pair(-6, 40),
  Pair(-1, 44), Pair(2, 47), Pair(7, 50), Pair(9, 55), Pair(15, 57), Pair(20, 57), Pair(23, 53)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-110, 77), Pair(-17, -105), Pair(-17, 35), Pair(-8, 82), Pair(-7, 125), Pair(-4, 144), Pair(-1, 160), Pair(1, 174),
  Pair(4, 184), Pair(7, 185), Pair(9, 193), Pair(11, 201), Pair(15, 197), Pair(15, 204), Pair(18, 204), Pair(22, 201),
  Pair(21, 206), Pair(24, 204), Pair(33, 194), Pair(46, 181), Pair(55, 172), Pair(98, 142), Pair(94, 137), Pair(113, 109),
  Pair(117, 118), Pair(211, 47), Pair(208, 41), Pair(153, 41)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-18, -108), Pair(-18, -93), Pair(-13, -58), Pair(14, -18), Pair(9, 55), Pair(126, 151), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 1), Pair(16, 7), Pair(21, 18), Pair(51, 68), Pair(127, 221), Pair(-45, 468), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(24, 12), Pair(16, 8), Pair(14, 17), Pair(27, 54), Pair(169, 47), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-18, -49), Pair(3, -35), Pair(0, -28), Pair(-2, -12), Pair(-10, -4), Pair(-9, -19), Pair(1, -28), Pair(-11, -54)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(2, 7), Pair(-3, -12), Pair(-12, -7), Pair(-8, -17), Pair(-13, -19), Pair(-5, -8), Pair(-4, -11), Pair(1, 2)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(22, 6), Pair(20, 1), Pair(19, 9), Pair(20, 8), Pair(23, 12), Pair(34, 4), Pair(49, -1), Pair(75, -6)
  },
  {
      Pair(11, 36), Pair(11, 8), Pair(13, 9), Pair(21, -1), Pair(17, -2), Pair(21, -4), Pair(28, -6), Pair(22, 15)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(14, -4), Pair(22, -5), Pair(9, 1),
  Pair(32, -14), Pair(31, -16), Pair(30, -14),
  Pair(38, -7), Pair(0, 0), Pair(34, -6),
  Pair(6, -1), Pair(27, -16), Pair(10, 0)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-9, 4), Pair(-17, 8), Pair(-11, 7),
  Pair(-8, 3), Pair(-20, 10), Pair(-11, 6),
  Pair(-2, -3), Pair(-17, 7), Pair(-3, -2),
  Pair(13, -5), Pair(-3, -1), Pair(11, -3),
  Pair(27, -12), Pair(28, -1), Pair(20, -12),
  Pair(4, -1), Pair(17, -26), Pair(-1, -5),
  Pair(53, -49), Pair(0, 0), Pair(42, -46)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(1, 83), Pair(0, 67), Pair(3, 52), Pair(6, 43), Pair(6, 42), Pair(11, 41), Pair(8, 35)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-56, 3), Pair(-10, 10), Pair(-4, 36), Pair(2, 48), Pair(3, 57), Pair(3, 63), Pair(-5, 57)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-728, 221);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-77, -12), Pair(-88, -5), Pair(-23, -13), Pair(-31, -8), Pair(-24, -5), Pair(-34, -5), Pair(-56, -3), Pair(-37, 0)
  },
  {
      Pair(-9, 49), Pair(-40, 22), Pair(-3, 10), Pair(5, -1), Pair(-5, -4), Pair(-1, 2), Pair(-24, 17), Pair(-18, 31)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 2), Pair(27, -8), Pair(54, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 1), Pair(29, 0), Pair(66, -8), Pair(77, -45), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(21, -21), Pair(36, -19), Pair(53, -14), Pair(81, -15), Pair(92, -25), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 12), Pair(11, 25), Pair(31, 29), Pair(78, 14), Pair(114, 10), Pair(182, -16), Pair(248, -77)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(51, 11), Pair(20, 26), Pair(60, 1), Pair(27, 15), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-20, 13), Pair(-12, 19)
  },
  {
      Pair(-74, -29), Pair(-73, -37)
  },
  {
      Pair(-64, -55), Pair(-73, -84)
  },
  {
      Pair(-106, 2), Pair(-94, -38)
  },
  {
      Pair(-83, 33), Pair(-92, 14)
  },
  {
      Pair(17, 10), Pair(-12, -7)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(18, 37), Pair(23, 23), Pair(32, 12), Pair(24, -3), Pair(62, -6)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -22), Pair(10, -12)
  },
  {
      Pair(-26, -41), Pair(-5, -58)
  },
  {
      Pair(-47, -37), Pair(-32, -37)
  },
  {
      Pair(-92, -2), Pair(-69, -30)
  },
  {
      Pair(-64, 43), Pair(-65, 25)
  },
  {
      Pair(-37, -21), Pair(6, -52)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-11, -23), Pair(1, -9)
  },
  {
      Pair(-54, -27), Pair(-24, -30)
  },
  {
      Pair(15, -139), Pair(28, -131)
  },
  {
      Pair(-91, -7), Pair(-53, -43)
  },
  {
      Pair(-93, -22), Pair(-68, -100)
  },
  {
      Pair(-3, -17), Pair(1, -30)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-1, -27), Pair(14, -11)
  },
  {
      Pair(-44, -29), Pair(-2, -16)
  },
  {
      Pair(-33, -31), Pair(-14, -5)
  },
  {
      Pair(-3, -56), Pair(13, -30)
  },
  {
      Pair(-92, 2), Pair(-66, -55)
  },
  {
      Pair(-16, -20), Pair(-16, -29)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(22, 27), Pair(18, 13), Pair(44, 23), Pair(53, 26), Pair(55, 31), Pair(32, 52), Pair(45, 13), Pair(0, 43),
  Pair(5, 17), Pair(15, 18), Pair(21, 22), Pair(11, 38), Pair(16, 26), Pair(12, 23), Pair(15, 18), Pair(-11, 33),
  Pair(10, 11), Pair(6, 2), Pair(3, 17), Pair(10, 19), Pair(8, 22), Pair(-8, 22), Pair(2, 8), Pair(0, 10)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-16, 17), Pair(24, 1), Pair(34, 2), Pair(50, 4), Pair(76, -12), Pair(58, -1), Pair(22, -2), Pair(-17, -21),
  Pair(-21, -14), Pair(22, 9), Pair(12, 5), Pair(28, 11), Pair(14, 9), Pair(17, -4), Pair(13, 12), Pair(11, -12),
  Pair(-24, 32), Pair(12, 5), Pair(3, 24), Pair(21, 16), Pair(28, 23), Pair(3, 10), Pair(15, 1), Pair(-52, 11)
};

constexpr ScorePair kBishopPairBonus = Pair(23, 63);

constexpr ScorePair kTempoBonus = Pair(35, 32);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H