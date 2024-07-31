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
using PieceSquareTable = KingBuckets<PieceTable<std::array<T, kSquareCount>>>;

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
  Pair(76, 150), Pair(274, 34), Pair(406, 410), Pair(452, 805), Pair(819, 1303), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-3, 57), Pair(-27, 70), Pair(-8, 13), Pair(11, -21), Pair(42, -50), Pair(39, -39), Pair(-42, -17), Pair(-65, 44),
      Pair(3, 37), Pair(-2, 30), Pair(32, -16), Pair(42, -61), Pair(58, -64), Pair(99, -68), Pair(53, -7), Pair(35, 5),
      Pair(-17, 3), Pair(-3, -10), Pair(-2, -29), Pair(-3, -48), Pair(25, -57), Pair(28, -60), Pair(1, -22), Pair(10, -35),
      Pair(-21, -22), Pair(-14, -16), Pair(-7, -36), Pair(3, -43), Pair(8, -48), Pair(20, -60), Pair(-4, -32), Pair(10, -51),
      Pair(-33, -26), Pair(-25, -25), Pair(-19, -33), Pair(-13, -33), Pair(-4, -32), Pair(-5, -47), Pair(-5, -42), Pair(6, -62),
      Pair(-22, -18), Pair(-14, -14), Pair(-13, -20), Pair(-8, -34), Pair(1, -9), Pair(12, -31), Pair(8, -27), Pair(-3, -55),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-110, 60), Pair(-112, 133), Pair(-47, 106), Pair(-23, 92), Pair(-16, 95), Pair(-1, 30), Pair(-89, 79), Pair(-51, -7),
      Pair(-1, 107), Pair(6, 131), Pair(19, 115), Pair(22, 116), Pair(30, 89), Pair(73, 86), Pair(53, 77), Pair(19, 59),
      Pair(14, 119), Pair(30, 119), Pair(28, 137), Pair(42, 116), Pair(58, 101), Pair(102, 73), Pair(31, 104), Pair(51, 65),
      Pair(33, 123), Pair(39, 127), Pair(57, 126), Pair(61, 140), Pair(59, 130), Pair(71, 127), Pair(50, 127), Pair(60, 95),
      Pair(12, 118), Pair(39, 116), Pair(49, 134), Pair(55, 129), Pair(54, 136), Pair(67, 109), Pair(54, 116), Pair(30, 114),
      Pair(-3, 103), Pair(20, 112), Pair(28, 120), Pair(41, 132), Pair(55, 127), Pair(41, 114), Pair(40, 109), Pair(21, 109),
      Pair(-13, 98), Pair(1, 109), Pair(14, 105), Pair(31, 111), Pair(30, 113), Pair(28, 95), Pair(27, 100), Pair(21, 116),
      Pair(-34, 76), Pair(-1, 99), Pair(2, 101), Pair(20, 101), Pair(24, 109), Pair(30, 95), Pair(4, 96), Pair(-3, 81)
    },
    {
      Pair(-25, 62), Pair(-68, 51), Pair(-58, 39), Pair(-112, 58), Pair(-90, 41), Pair(-50, 9), Pair(-86, 85), Pair(-27, 15),
      Pair(-26, 43), Pair(-16, 54), Pair(-7, 33), Pair(-25, 47), Pair(-21, 25), Pair(-20, 38), Pair(-55, 56), Pair(-44, 24),
      Pair(-6, 54), Pair(-2, 56), Pair(-10, 50), Pair(-11, 36), Pair(-21, 48), Pair(24, 54), Pair(14, 48), Pair(0, 62),
      Pair(-24, 50), Pair(-8, 59), Pair(-3, 51), Pair(1, 70), Pair(5, 46), Pair(7, 50), Pair(-7, 52), Pair(-16, 46),
      Pair(-16, 49), Pair(-21, 49), Pair(-10, 55), Pair(3, 41), Pair(1, 39), Pair(-3, 35), Pair(-15, 46), Pair(3, 21),
      Pair(-15, 31), Pair(5, 54), Pair(2, 48), Pair(-2, 52), Pair(2, 63), Pair(7, 50), Pair(15, 32), Pair(12, 33),
      Pair(2, 29), Pair(3, 20), Pair(11, 23), Pair(-6, 40), Pair(6, 41), Pair(16, 47), Pair(31, 36), Pair(19, 18),
      Pair(1, 13), Pair(22, 23), Pair(-1, 37), Pair(-5, 32), Pair(11, 27), Pair(16, 40), Pair(21, 25), Pair(37, -21)
    },
    {
      Pair(36, 45), Pair(34, 59), Pair(26, 69), Pair(17, 62), Pair(53, 41), Pair(38, 53), Pair(52, 62), Pair(9, 50),
      Pair(21, 52), Pair(29, 63), Pair(38, 66), Pair(47, 52), Pair(29, 47), Pair(50, 47), Pair(85, 35), Pair(59, 33),
      Pair(14, 52), Pair(56, 50), Pair(42, 54), Pair(43, 40), Pair(70, 26), Pair(92, 15), Pair(141, -5), Pair(69, 11),
      Pair(29, 45), Pair(39, 54), Pair(50, 51), Pair(45, 41), Pair(56, 26), Pair(58, 31), Pair(70, 24), Pair(45, 15),
      Pair(13, 38), Pair(13, 58), Pair(24, 44), Pair(27, 46), Pair(28, 37), Pair(13, 44), Pair(52, 21), Pair(28, 14),
      Pair(2, 38), Pair(11, 42), Pair(18, 45), Pair(16, 46), Pair(28, 32), Pair(26, 28), Pair(65, -2), Pair(44, -15),
      Pair(3, 26), Pair(7, 43), Pair(25, 35), Pair(24, 42), Pair(31, 25), Pair(30, 21), Pair(55, 5), Pair(22, -13),
      Pair(13, 40), Pair(22, 33), Pair(26, 38), Pair(31, 32), Pair(36, 24), Pair(33, 31), Pair(33, 21), Pair(-6, 29)
    },
    {
      Pair(58, 108), Pair(56, 111), Pair(74, 109), Pair(110, 80), Pair(94, 93), Pair(86, 122), Pair(142, 54), Pair(88, 114),
      Pair(71, 109), Pair(70, 110), Pair(71, 140), Pair(67, 131), Pair(36, 181), Pair(70, 160), Pair(69, 144), Pair(123, 114),
      Pair(78, 112), Pair(78, 119), Pair(78, 139), Pair(75, 148), Pair(74, 152), Pair(97, 167), Pair(104, 143), Pair(92, 128),
      Pair(70, 122), Pair(84, 119), Pair(84, 124), Pair(77, 140), Pair(79, 157), Pair(100, 114), Pair(95, 142), Pair(101, 110),
      Pair(70, 115), Pair(67, 137), Pair(73, 132), Pair(73, 149), Pair(86, 130), Pair(73, 134), Pair(95, 113), Pair(91, 114),
      Pair(74, 100), Pair(75, 119), Pair(72, 138), Pair(69, 135), Pair(72, 140), Pair(82, 120), Pair(101, 100), Pair(98, 66),
      Pair(76, 88), Pair(77, 98), Pair(79, 105), Pair(80, 119), Pair(85, 107), Pair(95, 72), Pair(101, 62), Pair(108, 14),
      Pair(67, 109), Pair(70, 103), Pair(75, 99), Pair(77, 103), Pair(84, 82), Pair(77, 67), Pair(80, 35), Pair(59, 94)
    },
    {
      Pair(2030, -168), Pair(1996, -113), Pair(1954, -93), Pair(1902, -66), Pair(1906, -73), Pair(1881, -64), Pair(1946, -78), Pair(2048, -165),
      Pair(1938, -102), Pair(1995, -66), Pair(1938, -51), Pair(1987, -59), Pair(1931, -50), Pair(1929, -38), Pair(1991, -53), Pair(1988, -87),
      Pair(1897, -71), Pair(2021, -55), Pair(1917, -29), Pair(1877, -17), Pair(1899, -15), Pair(1961, -29), Pair(1921, -30), Pair(1914, -72),
      Pair(1948, -93), Pair(1973, -65), Pair(1912, -41), Pair(1854, -25), Pair(1851, -27), Pair(1876, -33), Pair(1912, -56), Pair(1834, -70),
      Pair(1161, -91), Pair(1173, -59), Pair(1099, -28), Pair(1061, -12), Pair(1063, -17), Pair(1093, -32), Pair(1100, -47), Pair(1056, -68),
      Pair(600, -58), Pair(633, -32), Pair(565, -5), Pair(559, 6), Pair(558, 4), Pair(559, -7), Pair(592, -27), Pair(567, -49),
      Pair(115, -36), Pair(73, 8), Pair(62, 21), Pair(43, 31), Pair(36, 34), Pair(56, 22), Pair(71, 5), Pair(88, -28),
      Pair(-219, -20), Pair(-193, 16), Pair(28, 28), Pair(-25, 46), Pair(14, 32), Pair(-11, 38), Pair(-218, 26), Pair(-215, -22)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(25, 91), Pair(1, 110), Pair(-10, 83), Pair(61, 60), Pair(7, 42), Pair(-16, 33), Pair(-29, 56), Pair(-55, 71),
      Pair(24, 16), Pair(-5, 34), Pair(31, -18), Pair(40, -52), Pair(38, -53), Pair(61, -47), Pair(10, 22), Pair(0, 3),
      Pair(12, -7), Pair(0, -18), Pair(5, -31), Pair(9, -54), Pair(25, -58), Pair(14, -56), Pair(3, -25), Pair(-3, -19),
      Pair(13, -29), Pair(-10, -17), Pair(10, -44), Pair(21, -52), Pair(15, -50), Pair(13, -55), Pair(5, -34), Pair(-8, -35),
      Pair(10, -36), Pair(-8, -26), Pair(-3, -39), Pair(-9, -39), Pair(-6, -41), Pair(-11, -45), Pair(3, -40), Pair(-16, -38),
      Pair(11, -24), Pair(-2, -15), Pair(0, -20), Pair(-25, -19), Pair(-24, -9), Pair(-4, -29), Pair(6, -27), Pair(-9, -28),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-123, -46), Pair(-213, 141), Pair(-104, 63), Pair(-78, 86), Pair(12, 39), Pair(-40, 6), Pair(-95, 89), Pair(-89, -38),
      Pair(-82, 92), Pair(-22, 85), Pair(2, 72), Pair(-29, 86), Pair(-10, 79), Pair(18, 69), Pair(-45, 73), Pair(4, 46),
      Pair(-46, 102), Pair(12, 100), Pair(-22, 121), Pair(18, 92), Pair(13, 94), Pair(20, 80), Pair(-15, 96), Pair(-14, 75),
      Pair(10, 106), Pair(11, 111), Pair(26, 107), Pair(37, 104), Pair(37, 101), Pair(44, 105), Pair(24, 93), Pair(26, 81),
      Pair(-3, 108), Pair(18, 112), Pair(28, 107), Pair(34, 108), Pair(35, 112), Pair(46, 94), Pair(29, 110), Pair(10, 86),
      Pair(-24, 94), Pair(5, 102), Pair(21, 96), Pair(26, 112), Pair(36, 111), Pair(19, 91), Pair(22, 84), Pair(-4, 90),
      Pair(-26, 104), Pair(-3, 99), Pair(8, 103), Pair(4, 103), Pair(13, 92), Pair(11, 87), Pair(2, 86), Pair(-21, 76),
      Pair(-67, 71), Pair(-23, 93), Pair(-12, 91), Pair(-8, 105), Pair(2, 103), Pair(-10, 84), Pair(-23, 93), Pair(-20, 50)
    },
    {
      Pair(-86, 25), Pair(-94, 43), Pair(-121, 27), Pair(-151, 45), Pair(-225, 79), Pair(-175, 21), Pair(-62, 26), Pair(-96, 11),
      Pair(-86, 13), Pair(-55, 22), Pair(-56, 18), Pair(-77, 27), Pair(-86, 26), Pair(-51, 20), Pair(-66, 16), Pair(-49, 9),
      Pair(-43, 38), Pair(-55, 51), Pair(-57, 45), Pair(-24, 19), Pair(-46, 25), Pair(-30, 23), Pair(-21, 33), Pair(-19, 25),
      Pair(-41, 41), Pair(-21, 31), Pair(-31, 36), Pair(-24, 34), Pair(-25, 27), Pair(-18, 46), Pair(-32, 36), Pair(-39, 42),
      Pair(-28, 10), Pair(-67, 52), Pair(-15, 7), Pair(-15, 19), Pair(-11, 13), Pair(-27, 20), Pair(-37, 32), Pair(-31, 10),
      Pair(-40, 26), Pair(-4, 21), Pair(-12, 34), Pair(-14, 36), Pair(-13, 41), Pair(-7, 29), Pair(-12, 24), Pair(-26, 9),
      Pair(-12, 5), Pair(-6, 17), Pair(5, 8), Pair(-22, 39), Pair(-10, 27), Pair(-5, 11), Pair(-5, 15), Pair(-18, 3),
      Pair(-29, 13), Pair(-13, 24), Pair(-33, 28), Pair(-17, 21), Pair(-13, 11), Pair(-37, 31), Pair(-48, 42), Pair(-27, 2)
    },
    {
      Pair(-1, 21), Pair(-93, 50), Pair(-41, 26), Pair(-26, 27), Pair(-84, 40), Pair(-85, 49), Pair(-64, 42), Pair(-60, 45),
      Pair(-45, 16), Pair(-47, 32), Pair(-40, 23), Pair(-23, 25), Pair(16, -2), Pair(-20, 9), Pair(-34, 17), Pair(-47, 20),
      Pair(-33, 5), Pair(-12, 16), Pair(-50, 21), Pair(-8, 1), Pair(19, -17), Pair(-22, -2), Pair(15, 0), Pair(-29, -5),
      Pair(-38, 9), Pair(2, -4), Pair(-26, 27), Pair(-28, 21), Pair(-24, 9), Pair(-1, -3), Pair(-8, -3), Pair(-34, 3),
      Pair(-25, 7), Pair(-51, 18), Pair(-40, 9), Pair(-27, 16), Pair(-27, 10), Pair(-42, 5), Pair(-26, -1), Pair(-51, -7),
      Pair(-35, -2), Pair(-24, 12), Pair(-40, 8), Pair(-36, 13), Pair(-29, 1), Pair(-30, -3), Pair(-12, -21), Pair(-38, -17),
      Pair(-36, -19), Pair(-41, 6), Pair(-24, 7), Pair(-31, -11), Pair(-15, -20), Pair(-31, 1), Pair(-24, -27), Pair(-49, -31),
      Pair(-18, -23), Pair(-32, -11), Pair(-33, 6), Pair(-18, -10), Pair(-10, -17), Pair(-36, -16), Pair(-27, -22), Pair(-28, -38)
    },
    {
      Pair(-106, 75), Pair(-123, 96), Pair(-68, 81), Pair(-49, 68), Pair(-61, 80), Pair(-94, 94), Pair(-92, 94), Pair(-68, 19),
      Pair(-53, 2), Pair(-78, 72), Pair(-78, 88), Pair(-126, 143), Pair(-138, 152), Pair(-79, 114), Pair(-55, 65), Pair(-23, 73),
      Pair(-47, 50), Pair(-53, 30), Pair(-65, 85), Pair(-43, 62), Pair(-63, 113), Pair(-41, 78), Pair(-19, 46), Pair(-13, 78),
      Pair(-42, 36), Pair(-40, 51), Pair(-33, 65), Pair(-49, 91), Pair(-47, 76), Pair(-23, 55), Pair(-13, 49), Pair(-24, 69),
      Pair(-32, 22), Pair(-54, 91), Pair(-37, 52), Pair(-39, 121), Pair(-42, 102), Pair(-36, 60), Pair(-27, 54), Pair(-28, 39),
      Pair(-40, 27), Pair(-27, 48), Pair(-32, 76), Pair(-43, 82), Pair(-32, 72), Pair(-32, 76), Pair(-21, 50), Pair(-25, 65),
      Pair(-33, -12), Pair(-18, -29), Pair(-17, -9), Pair(-22, 25), Pair(-25, 32), Pair(-27, 28), Pair(2, -38), Pair(-4, -22),
      Pair(-38, -29), Pair(-30, -38), Pair(-27, -8), Pair(-27, -18), Pair(-36, -1), Pair(-35, -31), Pair(-25, -28), Pair(-12, -20)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 2
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(114, 76), Pair(62, 90), Pair(69, 82), Pair(119, 22), Pair(84, 21), Pair(94, 38), Pair(20, 75), Pair(1, 94),
      Pair(9, 11), Pair(12, 9), Pair(23, -15), Pair(41, -54), Pair(63, -66), Pair(84, -48), Pair(46, 3), Pair(6, 12),
      Pair(-15, -5), Pair(-8, -11), Pair(-8, -27), Pair(6, -46), Pair(34, -50), Pair(26, -47), Pair(13, -20), Pair(-15, -18),
      Pair(-19, -20), Pair(-15, -13), Pair(-8, -31), Pair(4, -38), Pair(12, -42), Pair(14, -43), Pair(2, -26), Pair(-25, -31),
      Pair(-37, -21), Pair(-27, -15), Pair(-22, -27), Pair(-16, -28), Pair(-12, -27), Pair(-10, -32), Pair(0, -32), Pair(-37, -32),
      Pair(-26, -19), Pair(-15, -13), Pair(-12, -23), Pair(-26, -17), Pair(0, -23), Pair(24, -32), Pair(21, -29), Pair(-35, -29),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-162, 41), Pair(-138, 79), Pair(-128, 98), Pair(10, 56), Pair(67, 51), Pair(-137, 83), Pair(-240, 114), Pair(-139, 9),
      Pair(-65, 99), Pair(-36, 96), Pair(-9, 92), Pair(60, 78), Pair(19, 78), Pair(48, 63), Pair(-4, 92), Pair(1, 63),
      Pair(-31, 94), Pair(3, 93), Pair(6, 115), Pair(32, 94), Pair(27, 96), Pair(80, 59), Pair(33, 67), Pair(48, 61),
      Pair(-23, 102), Pair(16, 100), Pair(39, 109), Pair(60, 96), Pair(51, 104), Pair(78, 94), Pair(41, 97), Pair(63, 81),
      Pair(-10, 108), Pair(16, 100), Pair(29, 117), Pair(47, 107), Pair(50, 110), Pair(60, 97), Pair(64, 88), Pair(24, 97),
      Pair(-30, 92), Pair(-3, 97), Pair(20, 98), Pair(27, 116), Pair(50, 107), Pair(27, 89), Pair(33, 79), Pair(11, 84),
      Pair(-39, 87), Pair(-38, 101), Pair(-10, 103), Pair(12, 93), Pair(18, 85), Pair(15, 96), Pair(9, 74), Pair(5, 87),
      Pair(-97, 118), Pair(-27, 94), Pair(-9, 90), Pair(-2, 105), Pair(8, 97), Pair(17, 85), Pair(-2, 89), Pair(-36, 94)
    },
    {
      Pair(-78, 42), Pair(-77, 28), Pair(-132, 42), Pair(-143, 43), Pair(-97, 31), Pair(-130, 44), Pair(-70, 32), Pair(-125, 45),
      Pair(-62, 26), Pair(-45, 30), Pair(-38, 20), Pair(-81, 39), Pair(-63, 31), Pair(-51, 26), Pair(-73, 41), Pair(-48, 28),
      Pair(-47, 35), Pair(-34, 30), Pair(-30, 29), Pair(-39, 24), Pair(-11, 18), Pair(8, 26), Pair(-8, 34), Pair(-9, 33),
      Pair(-40, 29), Pair(-22, 26), Pair(-18, 31), Pair(9, 28), Pair(2, 26), Pair(5, 25), Pair(-24, 23), Pair(-18, 20),
      Pair(-43, 24), Pair(-52, 37), Pair(-17, 22), Pair(-9, 28), Pair(-4, 19), Pair(-25, 32), Pair(-22, 25), Pair(-25, 23),
      Pair(-48, 31), Pair(-7, 24), Pair(-12, 25), Pair(-7, 28), Pair(-9, 36), Pair(-7, 24), Pair(0, 24), Pair(-15, 2),
      Pair(-35, 21), Pair(-27, 4), Pair(-10, 12), Pair(-25, 18), Pair(-12, 17), Pair(-8, 13), Pair(7, 0), Pair(-26, 3),
      Pair(-51, 20), Pair(-13, 31), Pair(-14, 18), Pair(-24, 29), Pair(-20, 29), Pair(-34, 37), Pair(-5, 10), Pair(-50, 4)
    },
    {
      Pair(-43, 28), Pair(-20, 38), Pair(-34, 42), Pair(-15, 34), Pair(-30, 27), Pair(11, 27), Pair(-34, 45), Pair(-40, 35),
      Pair(-32, 20), Pair(-20, 33), Pair(1, 27), Pair(28, 17), Pair(19, 13), Pair(38, 16), Pair(1, 23), Pair(-19, 18),
      Pair(-26, 19), Pair(-5, 22), Pair(-1, 19), Pair(1, 11), Pair(26, -4), Pair(39, -1), Pair(47, 3), Pair(-15, 4),
      Pair(-50, 33), Pair(9, 21), Pair(-9, 26), Pair(1, 17), Pair(11, -2), Pair(20, 2), Pair(14, 10), Pair(-28, 10),
      Pair(-69, 27), Pair(-33, 24), Pair(-35, 22), Pair(-19, 17), Pair(-25, 11), Pair(-37, 22), Pair(-21, 10), Pair(-43, 8),
      Pair(-51, 10), Pair(-46, 15), Pair(-39, 7), Pair(-33, 10), Pair(-25, 8), Pair(-27, 2), Pair(-7, -12), Pair(-60, 0),
      Pair(-53, 0), Pair(-38, 6), Pair(-32, 6), Pair(-27, 6), Pair(-14, -13), Pair(-19, -8), Pair(-26, -3), Pair(-49, -19),
      Pair(-55, 4), Pair(-46, 2), Pair(-43, 5), Pair(-39, 1), Pair(-30, -13), Pair(-32, -15), Pair(-36, -8), Pair(-56, -2)
    },
    {
      Pair(-81, 65), Pair(-45, 26), Pair(-18, 46), Pair(23, 20), Pair(24, 24), Pair(-8, 53), Pair(93, -38), Pair(19, 38),
      Pair(-60, 49), Pair(-48, 46), Pair(-46, 81), Pair(-27, 56), Pair(-33, 90), Pair(-7, 45), Pair(-5, 36), Pair(10, 63),
      Pair(-39, 28), Pair(-27, 41), Pair(-8, 53), Pair(-10, 61), Pair(2, 63), Pair(50, 19), Pair(27, 30), Pair(23, 19),
      Pair(-40, 32), Pair(-29, 57), Pair(-15, 56), Pair(-11, 63), Pair(0, 50), Pair(-1, 61), Pair(12, 49), Pair(7, 27),
      Pair(-31, 26), Pair(-42, 72), Pair(-28, 66), Pair(-15, 66), Pair(-10, 56), Pair(-10, 45), Pair(-4, 42), Pair(-17, 51),
      Pair(-36, 9), Pair(-30, 38), Pair(-27, 42), Pair(-22, 50), Pair(-17, 51), Pair(-10, 44), Pair(1, 26), Pair(-22, 50),
      Pair(-27, 9), Pair(-37, 14), Pair(-26, 16), Pair(-18, 17), Pair(-21, 25), Pair(-17, 2), Pair(-14, -26), Pair(-4, -34),
      Pair(-70, 23), Pair(-56, 16), Pair(-50, 22), Pair(-29, 7), Pair(-36, 10), Pair(-45, 18), Pair(-29, 22), Pair(-35, -3)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 3
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(83, 50), Pair(176, 21), Pair(101, 43), Pair(118, 15), Pair(173, -9), Pair(56, 18), Pair(-33, 87), Pair(-16, 79),
      Pair(6, -4), Pair(42, 9), Pair(87, -40), Pair(84, -59), Pair(113, -68), Pair(118, -51), Pair(39, -3), Pair(59, -23),
      Pair(-21, -8), Pair(-9, 0), Pair(-4, -26), Pair(10, -38), Pair(32, -37), Pair(30, -40), Pair(3, -12), Pair(-20, -20),
      Pair(-44, -16), Pair(-35, 5), Pair(-18, -23), Pair(-10, -27), Pair(-1, -25), Pair(1, -29), Pair(-23, -9), Pair(-34, -24),
      Pair(-66, -19), Pair(-47, -3), Pair(-26, -23), Pair(-2, -27), Pair(-12, -21), Pair(-12, -28), Pair(-31, -13), Pair(-55, -25),
      Pair(-53, -10), Pair(-26, 1), Pair(-4, -21), Pair(-38, -13), Pair(1, -15), Pair(11, -26), Pair(-17, -11), Pair(-48, -18),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-242, -3), Pair(-314, 62), Pair(-176, 82), Pair(-110, 53), Pair(-114, 61), Pair(-144, 43), Pair(-80, 32), Pair(-233, 21),
      Pair(-144, 50), Pair(-64, 62), Pair(-86, 70), Pair(-8, 44), Pair(-10, 39), Pair(-36, 48), Pair(-94, 75), Pair(-106, 55),
      Pair(-41, 35), Pair(-9, 47), Pair(-8, 57), Pair(2, 63), Pair(-7, 51), Pair(26, 29), Pair(21, 38), Pair(10, 22),
      Pair(-38, 69), Pair(-20, 64), Pair(4, 69), Pair(35, 59), Pair(67, 54), Pair(35, 67), Pair(64, 38), Pair(13, 52),
      Pair(-48, 58), Pair(-24, 64), Pair(-21, 77), Pair(13, 72), Pair(20, 75), Pair(30, 53), Pair(-9, 57), Pair(15, 38),
      Pair(-64, 38), Pair(-62, 62), Pair(-15, 58), Pair(-17, 73), Pair(18, 71), Pair(15, 47), Pair(-14, 49), Pair(-74, 64),
      Pair(-119, 59), Pair(-40, 60), Pair(-72, 65), Pair(-26, 66), Pair(-42, 68), Pair(24, 50), Pair(-46, 58), Pair(-13, 56),
      Pair(-96, 63), Pair(-68, 39), Pair(-131, 84), Pair(-161, 78), Pair(-53, 61), Pair(-45, 52), Pair(-76, 55), Pair(-69, 79)
    },
    {
      Pair(-123, -4), Pair(-137, 11), Pair(-107, -8), Pair(-152, -14), Pair(-150, 2), Pair(-250, 3), Pair(-170, -9), Pair(-145, -19),
      Pair(-119, -24), Pair(-51, -22), Pair(-129, -4), Pair(-39, -25), Pair(-153, -6), Pair(-88, -23), Pair(-133, 8), Pair(-121, -12),
      Pair(-71, -6), Pair(-89, -17), Pair(-70, -14), Pair(-45, -26), Pair(-57, -11), Pair(-15, -15), Pair(-48, -9), Pair(-22, -25),
      Pair(-62, -14), Pair(-57, -17), Pair(-31, -23), Pair(-16, -23), Pair(-6, -24), Pair(-27, -4), Pair(-19, -21), Pair(-33, -25),
      Pair(-120, -6), Pair(-74, -6), Pair(-48, -17), Pair(-33, -12), Pair(-34, -20), Pair(-38, -11), Pair(-70, -5), Pair(-91, -16),
      Pair(-109, -8), Pair(-81, -6), Pair(-53, -15), Pair(-32, -24), Pair(-13, -25), Pair(-40, -18), Pair(-64, -19), Pair(-98, -11),
      Pair(-87, 14), Pair(-82, -12), Pair(-90, -4), Pair(-69, -9), Pair(-61, -13), Pair(-86, -7), Pair(-53, -33), Pair(-55, -33),
      Pair(-100, -18), Pair(-108, 38), Pair(-67, -13), Pair(-80, -12), Pair(-32, -20), Pair(-69, -10), Pair(-173, 17), Pair(-97, -22)
    },
    {
      Pair(-140, -25), Pair(-145, -20), Pair(-83, -32), Pair(-148, -22), Pair(-109, -39), Pair(-106, -17), Pair(-109, -34), Pair(-174, -21),
      Pair(-95, -48), Pair(-79, -35), Pair(-106, -29), Pair(-11, -73), Pair(-89, -51), Pair(-94, -31), Pair(-93, -38), Pair(-116, -48),
      Pair(-133, -33), Pair(-76, -44), Pair(-59, -59), Pair(-93, -50), Pair(-74, -56), Pair(-49, -53), Pair(-76, -46), Pair(-132, -47),
      Pair(-193, -19), Pair(-88, -42), Pair(-122, -28), Pair(-73, -42), Pair(-84, -53), Pair(-111, -42), Pair(-95, -45), Pair(-126, -48),
      Pair(-181, -31), Pair(-175, -18), Pair(-159, -31), Pair(-125, -38), Pair(-97, -50), Pair(-132, -42), Pair(-134, -38), Pair(-149, -51),
      Pair(-141, -56), Pair(-127, -54), Pair(-118, -59), Pair(-121, -57), Pair(-120, -60), Pair(-128, -47), Pair(-93, -79), Pair(-177, -61),
      Pair(-185, -49), Pair(-131, -61), Pair(-130, -53), Pair(-141, -55), Pair(-146, -48), Pair(-96, -75), Pair(-107, -76), Pair(-161, -60),
      Pair(-133, -65), Pair(-135, -53), Pair(-137, -50), Pair(-124, -54), Pair(-125, -63), Pair(-110, -70), Pair(-120, -67), Pair(-129, -71)
    },
    {
      Pair(-281, -83), Pair(-243, -107), Pair(-247, -89), Pair(-233, -84), Pair(-339, -23), Pair(-266, -25), Pair(-185, -171), Pair(-273, -72),
      Pair(-281, -87), Pair(-289, -81), Pair(-295, -50), Pair(-222, -62), Pair(-199, -78), Pair(-136, -128), Pair(-221, -105), Pair(-139, -162),
      Pair(-205, -102), Pair(-263, -86), Pair(-175, -120), Pair(-255, -52), Pair(-183, -87), Pair(-135, -131), Pair(-120, -172), Pair(-144, -141),
      Pair(-262, -86), Pair(-212, -107), Pair(-197, -118), Pair(-219, -74), Pair(-158, -114), Pair(-152, -114), Pair(-120, -158), Pair(-160, -140),
      Pair(-229, -147), Pair(-276, -71), Pair(-214, -68), Pair(-193, -80), Pair(-205, -57), Pair(-178, -108), Pair(-186, -102), Pair(-231, -69),
      Pair(-312, -91), Pair(-198, -145), Pair(-196, -120), Pair(-201, -110), Pair(-207, -93), Pair(-152, -166), Pair(-143, -198), Pair(-220, -127),
      Pair(-231, -136), Pair(-254, -94), Pair(-188, -168), Pair(-195, -144), Pair(-189, -115), Pair(-205, -145), Pair(-200, -181), Pair(-236, -165),
      Pair(-303, -94), Pair(-291, -99), Pair(-220, -144), Pair(-197, -179), Pair(-189, -189), Pair(-192, -140), Pair(-234, -89), Pair(-193, -163)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 4
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(71, 48), Pair(243, 1), Pair(239, 22), Pair(115, 11), Pair(55, 55), Pair(-54, 75), Pair(-6, 101), Pair(191, 30),
      Pair(-8, -8), Pair(-13, 42), Pair(82, -33), Pair(99, -46), Pair(126, -44), Pair(111, -30), Pair(100, -5), Pair(35, -2),
      Pair(-65, -2), Pair(17, 14), Pair(19, -25), Pair(-2, -24), Pair(22, -19), Pair(38, -23), Pair(-21, 7), Pair(5, -17),
      Pair(-52, -12), Pair(-75, 31), Pair(-27, -14), Pair(-42, -5), Pair(-18, -11), Pair(-29, -11), Pair(-81, 16), Pair(-68, -15),
      Pair(-72, -18), Pair(-54, 16), Pair(-10, -26), Pair(-15, -17), Pair(-24, -17), Pair(-14, -19), Pair(-43, 0), Pair(-78, -15),
      Pair(-83, -7), Pair(-70, 22), Pair(10, -29), Pair(-24, -34), Pair(-7, -13), Pair(6, -23), Pair(-33, -2), Pair(-88, -9),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-248, -112), Pair(-314, -26), Pair(-110, 0), Pair(-116, -14), Pair(-26, -1), Pair(59, -39), Pair(-319, 7), Pair(-648, 26),
      Pair(-199, 17), Pair(-108, 17), Pair(-96, 5), Pair(44, -24), Pair(-34, -30), Pair(-84, 21), Pair(-2, 3), Pair(-21, -33),
      Pair(-142, 9), Pair(-56, -1), Pair(34, -10), Pair(25, -16), Pair(-50, 16), Pair(24, -18), Pair(13, -12), Pair(-22, -10),
      Pair(-116, 23), Pair(-49, 9), Pair(-35, 10), Pair(62, -10), Pair(40, 3), Pair(1, 17), Pair(123, -32), Pair(56, -30),
      Pair(-127, 19), Pair(-109, 25), Pair(-85, 34), Pair(-26, 24), Pair(-48, 23), Pair(-7, 18), Pair(-54, 16), Pair(60, -4),
      Pair(-161, 20), Pair(-176, 41), Pair(-26, 12), Pair(-92, 32), Pair(-89, 40), Pair(-20, 9), Pair(-130, 40), Pair(-121, 26),
      Pair(-193, 41), Pair(-173, 30), Pair(-119, 15), Pair(-69, 15), Pair(-75, 22), Pair(-158, 44), Pair(-45, -16), Pair(-103, 2),
      Pair(-172, 21), Pair(-152, 1), Pair(-239, 30), Pair(-8, 6), Pair(-101, 25), Pair(-151, 16), Pair(-113, 24), Pair(-284, 78)
    },
    {
      Pair(-177, -58), Pair(-221, -37), Pair(-71, -82), Pair(-106, -59), Pair(-130, -71), Pair(-102, -75), Pair(-155, -59), Pair(-79, -73),
      Pair(-113, -74), Pair(-67, -79), Pair(-61, -69), Pair(-182, -62), Pair(-186, -53), Pair(-77, -76), Pair(-194, -48), Pair(-191, -34),
      Pair(-148, -43), Pair(-100, -70), Pair(25, -83), Pair(-36, -75), Pair(28, -92), Pair(-23, -54), Pair(-21, -69), Pair(-76, -59),
      Pair(-203, -37), Pair(-78, -69), Pair(-45, -70), Pair(8, -84), Pair(-96, -50), Pair(-42, -65), Pair(-46, -74), Pair(-69, -65),
      Pair(-113, -71), Pair(-96, -65), Pair(-96, -68), Pair(-50, -74), Pair(-101, -69), Pair(-98, -55), Pair(-59, -66), Pair(-73, -65),
      Pair(-203, -29), Pair(-70, -57), Pair(-95, -54), Pair(-64, -62), Pair(-54, -51), Pair(-78, -56), Pair(-80, -47), Pair(-201, -35),
      Pair(-158, -20), Pair(-145, -50), Pair(-94, -57), Pair(-97, -59), Pair(-168, -40), Pair(-155, -59), Pair(-96, -71), Pair(-194, -34),
      Pair(-230, -32), Pair(-224, -42), Pair(-109, -51), Pair(-99, -48), Pair(-190, -49), Pair(-126, -52), Pair(-156, -68), Pair(48, -48)
    },
    {
      Pair(-189, -117), Pair(-202, -97), Pair(-163, -107), Pair(-166, -120), Pair(-198, -101), Pair(-91, -136), Pair(-178, -108), Pair(-80, -140),
      Pair(-170, -123), Pair(-124, -129), Pair(-139, -127), Pair(-85, -151), Pair(-81, -153), Pair(-158, -114), Pair(-96, -135), Pair(-130, -134),
      Pair(-148, -135), Pair(-158, -117), Pair(-155, -124), Pair(-116, -136), Pair(-78, -156), Pair(-155, -127), Pair(-153, -119), Pair(-174, -126),
      Pair(-173, -121), Pair(-216, -99), Pair(-141, -133), Pair(-129, -133), Pair(-165, -133), Pair(-105, -147), Pair(-137, -125), Pair(-199, -121),
      Pair(-213, -126), Pair(-265, -109), Pair(-243, -114), Pair(-234, -119), Pair(-145, -147), Pair(-152, -138), Pair(-198, -128), Pair(-169, -156),
      Pair(-159, -143), Pair(-191, -117), Pair(-305, -102), Pair(-238, -114), Pair(-232, -122), Pair(-209, -134), Pair(-190, -143), Pair(-245, -128),
      Pair(-268, -111), Pair(-267, -100), Pair(-180, -135), Pair(-179, -132), Pair(-135, -154), Pair(-141, -148), Pair(-167, -155), Pair(-223, -132),
      Pair(-237, -118), Pair(-240, -108), Pair(-241, -111), Pair(-216, -125), Pair(-177, -142), Pair(-172, -144), Pair(-233, -111), Pair(-222, -136)
    },
    {
      Pair(-527, -165), Pair(-533, -206), Pair(-469, -197), Pair(-517, -157), Pair(-306, -288), Pair(-565, -126), Pair(-237, -355), Pair(-799, -5),
      Pair(-514, -204), Pair(-391, -242), Pair(-568, -137), Pair(-621, -42), Pair(-500, -111), Pair(-538, -159), Pair(-615, -131), Pair(-447, -229),
      Pair(-562, -183), Pair(-589, -137), Pair(-332, -266), Pair(-538, -112), Pair(-308, -263), Pair(-342, -204), Pair(-669, -113), Pair(-378, -252),
      Pair(-575, -147), Pair(-540, -150), Pair(-657, -84), Pair(-347, -236), Pair(-430, -197), Pair(-360, -257), Pair(-485, -186), Pair(-280, -283),
      Pair(-662, -119), Pair(-544, -181), Pair(-759, -34), Pair(-399, -222), Pair(-386, -232), Pair(-454, -159), Pair(-361, -277), Pair(-360, -333),
      Pair(-809, -77), Pair(-524, -162), Pair(-419, -220), Pair(-483, -136), Pair(-369, -241), Pair(-293, -339), Pair(-493, -252), Pair(-539, -139),
      Pair(-684, -56), Pair(-626, -124), Pair(-523, -176), Pair(-522, -168), Pair(-433, -207), Pair(-421, -293), Pair(-527, -194), Pair(-738, -73),
      Pair(-561, -175), Pair(-446, -333), Pair(-448, -266), Pair(-349, -411), Pair(-422, -222), Pair(-534, -203), Pair(-546, -156), Pair(-538, -297)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 5
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-37, 82), Pair(172, 29), Pair(350, 58), Pair(309, 18), Pair(3, 100), Pair(166, 76), Pair(-59, 125), Pair(89, 86),
      Pair(41, -2), Pair(53, 50), Pair(132, -2), Pair(119, -15), Pair(190, -30), Pair(114, -2), Pair(101, 7), Pair(-9, 21),
      Pair(-90, 12), Pair(-63, 42), Pair(44, -6), Pair(-45, 0), Pair(26, -11), Pair(0, -6), Pair(-36, 16), Pair(-92, 4),
      Pair(-106, 7), Pair(-87, 40), Pair(-4, -6), Pair(-77, 0), Pair(-28, -10), Pair(-92, 4), Pair(-73, 17), Pair(-115, -3),
      Pair(-102, -8), Pair(-92, 25), Pair(-9, -22), Pair(-28, -11), Pair(-6, -19), Pair(-39, -12), Pair(-24, 1), Pair(-94, -9),
      Pair(-106, -5), Pair(-97, 29), Pair(15, -17), Pair(-188, 36), Pair(-117, -5), Pair(-75, -6), Pair(-63, 6), Pair(-125, 3),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-74, -137), Pair(44, -140), Pair(81, -113), Pair(-18, -115), Pair(-15, -80), Pair(41, -149), Pair(-263, -89), Pair(324, -190),
      Pair(-528, -58), Pair(-22, -75), Pair(18, -92), Pair(135, -129), Pair(110, -130), Pair(-98, -77), Pair(-100, -68), Pair(-158, -77),
      Pair(-317, -35), Pair(-81, -71), Pair(-47, -81), Pair(-56, -58), Pair(214, -123), Pair(22, -84), Pair(66, -108), Pair(-28, -101),
      Pair(-130, -77), Pair(-70, -69), Pair(17, -72), Pair(1, -62), Pair(-35, -63), Pair(-87, -44), Pair(24, -98), Pair(-119, -60),
      Pair(-145, -67), Pair(-222, -41), Pair(-85, -49), Pair(-100, -44), Pair(50, -58), Pair(-94, -56), Pair(-6, -91), Pair(-74, -84),
      Pair(-221, -82), Pair(-257, -36), Pair(-155, -44), Pair(-109, -52), Pair(-188, -27), Pair(-168, -28), Pair(-246, -37), Pair(-134, -63),
      Pair(-491, -26), Pair(-396, -20), Pair(-303, -34), Pair(-308, -26), Pair(-153, -36), Pair(-139, -53), Pair(-137, -43), Pair(-381, -2),
      Pair(-293, -28), Pair(-139, -80), Pair(-431, -5), Pair(-306, -1), Pair(-180, -60), Pair(-394, -21), Pair(-119, -63), Pair(-246, -18)
    },
    {
      Pair(-456, -98), Pair(59, -164), Pair(24, -171), Pair(-100, -162), Pair(-141, -158), Pair(-201, -136), Pair(229, -209), Pair(-164, -146),
      Pair(-192, -140), Pair(-104, -143), Pair(-163, -127), Pair(-169, -153), Pair(34, -182), Pair(-27, -160), Pair(13, -166), Pair(-149, -152),
      Pair(-167, -126), Pair(-64, -166), Pair(-137, -133), Pair(-11, -157), Pair(-80, -152), Pair(2, -148), Pair(30, -167), Pair(-29, -158),
      Pair(-105, -154), Pair(-94, -144), Pair(-49, -146), Pair(2, -166), Pair(-60, -149), Pair(-65, -145), Pair(-88, -146), Pair(-56, -168),
      Pair(-202, -122), Pair(-154, -131), Pair(-61, -146), Pair(-116, -135), Pair(-71, -151), Pair(-172, -116), Pair(-89, -159), Pair(-163, -103),
      Pair(-173, -111), Pair(-44, -139), Pair(-174, -124), Pair(-95, -131), Pair(-106, -135), Pair(-104, -131), Pair(-195, -97), Pair(-171, -127),
      Pair(-202, -99), Pair(-255, -101), Pair(-226, -122), Pair(-130, -138), Pair(-93, -140), Pair(-308, -112), Pair(-311, -85), Pair(-303, -119),
      Pair(-268, -97), Pair(-187, -118), Pair(-229, -94), Pair(-288, -109), Pair(-317, -92), Pair(-212, -115), Pair(-270, -110), Pair(-378, -70)
    },
    {
      Pair(-272, -244), Pair(-236, -254), Pair(-312, -234), Pair(-256, -235), Pair(-358, -233), Pair(-284, -248), Pair(-284, -227), Pair(-131, -280),
      Pair(-233, -263), Pair(-206, -254), Pair(-209, -263), Pair(-170, -286), Pair(-192, -283), Pair(-299, -246), Pair(-84, -303), Pair(-292, -243),
      Pair(-349, -238), Pair(-260, -254), Pair(-176, -291), Pair(-266, -265), Pair(-251, -258), Pair(-196, -285), Pair(-120, -293), Pair(-253, -272),
      Pair(-351, -229), Pair(-271, -255), Pair(-326, -248), Pair(-277, -263), Pair(-326, -257), Pair(-191, -303), Pair(-363, -240), Pair(-259, -274),
      Pair(-400, -233), Pair(-391, -225), Pair(-330, -240), Pair(-249, -266), Pair(-262, -267), Pair(-236, -266), Pair(-277, -254), Pair(-338, -238),
      Pair(-323, -261), Pair(-375, -237), Pair(-316, -254), Pair(-336, -235), Pair(-277, -265), Pair(-320, -255), Pair(-264, -262), Pair(-395, -243),
      Pair(-320, -250), Pair(-364, -233), Pair(-297, -250), Pair(-321, -245), Pair(-376, -244), Pair(-327, -245), Pair(-410, -232), Pair(-355, -248),
      Pair(-434, -211), Pair(-456, -185), Pair(-376, -231), Pair(-348, -236), Pair(-360, -239), Pair(-344, -240), Pair(-359, -239), Pair(-413, -215)
    },
    {
      Pair(-765, -456), Pair(-810, -430), Pair(-589, -512), Pair(-604, -473), Pair(-662, -471), Pair(-596, -543), Pair(-676, -508), Pair(-656, -533),
      Pair(-901, -334), Pair(-674, -467), Pair(-631, -445), Pair(-559, -449), Pair(-592, -486), Pair(-436, -551), Pair(-466, -546), Pair(-808, -364),
      Pair(-723, -446), Pair(-618, -512), Pair(-515, -510), Pair(-555, -522), Pair(-459, -550), Pair(-396, -606), Pair(-759, -428), Pair(-327, -651),
      Pair(-868, -372), Pair(-731, -453), Pair(-661, -442), Pair(-388, -602), Pair(-674, -442), Pair(-680, -466), Pair(-871, -355), Pair(-767, -419),
      Pair(-899, -350), Pair(-800, -387), Pair(-817, -377), Pair(-726, -363), Pair(-737, -378), Pair(-465, -586), Pair(-997, -253), Pair(-665, -442),
      Pair(-1202, -182), Pair(-946, -282), Pair(-736, -407), Pair(-595, -508), Pair(-1123, -160), Pair(-827, -396), Pair(-754, -423), Pair(-869, -336),
      Pair(-741, -466), Pair(-793, -413), Pair(-705, -433), Pair(-645, -536), Pair(-786, -403), Pair(-769, -446), Pair(-686, -384), Pair(-762, -481),
      Pair(-747, -518), Pair(-974, -291), Pair(-681, -491), Pair(-721, -513), Pair(-794, -370), Pair(-759, -407), Pair(-1032, -253), Pair(-305, -639)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 6
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-151, 153), Pair(293, 119), Pair(254, 170), Pair(95, 186), Pair(40, 180), Pair(85, 196), Pair(-177, 206), Pair(79, 121),
      Pair(-121, 55), Pair(278, 58), Pair(315, 22), Pair(89, 42), Pair(156, 14), Pair(173, 59), Pair(-47, 80), Pair(-21, 14),
      Pair(-200, 46), Pair(-18, 52), Pair(68, 16), Pair(-98, 28), Pair(24, -1), Pair(-11, 17), Pair(-233, 61), Pair(-52, 6),
      Pair(-232, 38), Pair(20, 21), Pair(44, 3), Pair(35, -16), Pair(3, -4), Pair(-21, -12), Pair(-117, 32), Pair(-61, -14),
      Pair(-238, 29), Pair(148, -15), Pair(100, -40), Pair(134, -54), Pair(-54, 0), Pair(63, -29), Pair(-111, 15), Pair(38, -26),
      Pair(-234, 30), Pair(81, 7), Pair(30, -18), Pair(-391, 72), Pair(-79, -18), Pair(-65, -5), Pair(-110, 17), Pair(-67, 6),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-110, -167), Pair(-393, -76), Pair(498, -209), Pair(39, -157), Pair(-147, -88), Pair(495, -235), Pair(262, -304), Pair(-174, -219),
      Pair(618, -267), Pair(-5, -147), Pair(-266, -20), Pair(-93, -104), Pair(358, -207), Pair(-262, -82), Pair(33, -201), Pair(-17, -134),
      Pair(153, -157), Pair(-313, -49), Pair(44, -84), Pair(179, -106), Pair(449, -170), Pair(75, -94), Pair(349, -174), Pair(175, -139),
      Pair(-66, -100), Pair(-315, -15), Pair(147, -126), Pair(235, -136), Pair(158, -118), Pair(59, -91), Pair(320, -133), Pair(445, -206),
      Pair(36, -113), Pair(-312, -25), Pair(-494, 18), Pair(-434, 20), Pair(228, -71), Pair(27, -95), Pair(-231, -55), Pair(-277, -36),
      Pair(-314, -52), Pair(-251, -83), Pair(-41, -81), Pair(-183, -54), Pair(217, -109), Pair(-274, -38), Pair(-171, -101), Pair(-219, -29),
      Pair(-42, -160), Pair(-251, -51), Pair(-222, -38), Pair(-600, 34), Pair(-637, 12), Pair(65, -108), Pair(-132, -82), Pair(587, -244),
      Pair(-760, 38), Pair(-393, 36), Pair(-344, 4), Pair(-295, -9), Pair(230, -50), Pair(-711, 52), Pair(-893, 89), Pair(-86, -69)
    },
    {
      Pair(-20, -174), Pair(43, -194), Pair(-36, -141), Pair(394, -193), Pair(-408, -124), Pair(-302, -160), Pair(-144, -179), Pair(-25, -148),
      Pair(-191, -181), Pair(-158, -167), Pair(-346, -147), Pair(54, -209), Pair(-179, -131), Pair(-25, -169), Pair(44, -192), Pair(-191, -174),
      Pair(-99, -165), Pair(-182, -131), Pair(-27, -186), Pair(-126, -182), Pair(-108, -181), Pair(-120, -137), Pair(-131, -150), Pair(-237, -152),
      Pair(-215, -131), Pair(-203, -121), Pair(17, -151), Pair(-123, -165), Pair(-19, -167), Pair(-217, -137), Pair(-299, -112), Pair(253, -238),
      Pair(-232, -135), Pair(162, -206), Pair(-74, -153), Pair(59, -178), Pair(-95, -149), Pair(0, -153), Pair(-172, -125), Pair(432, -179),
      Pair(-12, -152), Pair(-21, -187), Pair(118, -188), Pair(-215, -128), Pair(-143, -140), Pair(-220, -137), Pair(-141, -149), Pair(-138, -118),
      Pair(-383, -56), Pair(230, -169), Pair(118, -185), Pair(-95, -143), Pair(-257, -124), Pair(-24, -133), Pair(-472, -131), Pair(-209, -81),
      Pair(-337, -109), Pair(275, -135), Pair(-275, -112), Pair(-359, -71), Pair(-392, -97), Pair(-388, -103), Pair(-341, -59), Pair(-405, -100)
    },
    {
      Pair(-105, -323), Pair(-233, -267), Pair(-89, -333), Pair(-333, -278), Pair(-60, -330), Pair(-277, -280), Pair(-193, -324), Pair(105, -381),
      Pair(22, -367), Pair(-25, -341), Pair(-131, -328), Pair(-167, -311), Pair(-83, -343), Pair(-196, -311), Pair(-160, -328), Pair(2, -366),
      Pair(-266, -295), Pair(-141, -301), Pair(-258, -293), Pair(-285, -288), Pair(-300, -290), Pair(-91, -335), Pair(-207, -300), Pair(-218, -295),
      Pair(-109, -333), Pair(-253, -298), Pair(-265, -307), Pair(-536, -230), Pair(-334, -268), Pair(8, -359), Pair(-34, -351), Pair(-122, -303),
      Pair(-348, -279), Pair(-144, -299), Pair(-76, -324), Pair(-383, -274), Pair(217, -401), Pair(-250, -306), Pair(-105, -316), Pair(-291, -279),
      Pair(-280, -292), Pair(-471, -233), Pair(-238, -334), Pair(-150, -326), Pair(-552, -236), Pair(-189, -312), Pair(-124, -290), Pair(-344, -289),
      Pair(-444, -258), Pair(-365, -230), Pair(-451, -271), Pair(-174, -296), Pair(-311, -285), Pair(-324, -281), Pair(-340, -265), Pair(-487, -239),
      Pair(-442, -244), Pair(-420, -212), Pair(-224, -268), Pair(-479, -236), Pair(-332, -255), Pair(-360, -260), Pair(-282, -293), Pair(-411, -228)
    },
    {
      Pair(-576, -626), Pair(-1095, -305), Pair(-729, -479), Pair(-686, -467), Pair(-531, -565), Pair(-914, -404), Pair(-683, -479), Pair(-451, -654),
      Pair(-552, -535), Pair(-916, -377), Pair(-413, -575), Pair(-505, -564), Pair(-513, -565), Pair(-893, -370), Pair(-493, -615), Pair(-595, -586),
      Pair(-596, -513), Pair(-401, -629), Pair(-573, -502), Pair(-428, -591), Pair(-526, -528), Pair(-610, -516), Pair(-532, -544), Pair(-423, -674),
      Pair(-599, -483), Pair(-761, -384), Pair(-469, -510), Pair(-500, -554), Pair(-473, -543), Pair(-805, -345), Pair(-617, -470), Pair(-493, -549),
      Pair(-396, -623), Pair(-507, -524), Pair(-694, -483), Pair(-861, -348), Pair(-560, -487), Pair(-588, -454), Pair(-780, -382), Pair(-561, -572),
      Pair(-563, -552), Pair(-690, -404), Pair(-961, -261), Pair(-791, -375), Pair(-1485, -34), Pair(-939, -341), Pair(-243, -695), Pair(-258, -734),
      Pair(-15, -782), Pair(-379, -673), Pair(-784, -387), Pair(-1268, -204), Pair(-1063, -243), Pair(-492, -568), Pair(-425, -590), Pair(-854, -331),
      Pair(-477, -610), Pair(-752, -568), Pair(-197, -774), Pair(-1244, -134), Pair(-958, -365), Pair(-1009, -288), Pair(-659, -608), Pair(-1365, -218)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }}
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(19, 298), Pair(34, 291), Pair(43, 316), Pair(48, 328), Pair(54, 335), Pair(58, 344), Pair(65, 344), Pair(68, 343),
  Pair(70, 335)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-69, 4), Pair(-59, -7), Pair(-50, 13), Pair(-44, 27), Pair(-38, 37), Pair(-35, 49), Pair(-32, 53), Pair(-30, 59),
  Pair(-29, 64), Pair(-25, 64), Pair(-16, 62), Pair(-12, 67), Pair(-15, 84), Pair(-19, 68)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-44, -44), Pair(-33, -14), Pair(-30, -5), Pair(-28, 8), Pair(-25, 11), Pair(-19, 15), Pair(-16, 21), Pair(-12, 24),
  Pair(-8, 28), Pair(-5, 32), Pair(-1, 34), Pair(2, 39), Pair(7, 42), Pair(8, 41), Pair(6, 39)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-27, -8), Pair(38, -126), Pair(29, 103), Pair(38, 152), Pair(38, 196), Pair(41, 215), Pair(44, 232), Pair(46, 245),
  Pair(48, 255), Pair(52, 256), Pair(53, 265), Pair(55, 272), Pair(59, 270), Pair(59, 276), Pair(61, 276), Pair(64, 274),
  Pair(64, 279), Pair(66, 276), Pair(75, 269), Pair(89, 254), Pair(95, 249), Pair(135, 223), Pair(133, 214), Pair(144, 196),
  Pair(191, 178), Pair(267, 116), Pair(254, 118), Pair(163, 143)
};

constexpr KingBuckets<RankTable<ScorePair>> kPassedPawnBonus = {{
  {
      Pair(0, 0), Pair(20, -86), Pair(24, -70), Pair(28, -34), Pair(54, 6), Pair(51, 72), Pair(104, 124), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, -86), Pair(8, -67), Pair(20, -36), Pair(36, 10), Pair(23, 79), Pair(69, 75), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, -76), Pair(-1, -59), Pair(5, -24), Pair(42, 13), Pair(39, 89), Pair(63, 67), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-40, -69), Pair(-24, -53), Pair(-34, -16), Pair(-1, 18), Pair(2, 94), Pair(73, 77), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-62, -62), Pair(-20, -63), Pair(-41, -21), Pair(-4, 14), Pair(5, 80), Pair(92, 64), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-62, -60), Pair(-8, -69), Pair(-8, -33), Pair(-16, 16), Pair(-32, 87), Pair(80, 60), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-99, -55), Pair(-85, -61), Pair(-73, -9), Pair(-29, 39), Pair(-83, 104), Pair(-43, 73), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPawnPhalanxBonus = {{
  {
      Pair(0, 0), Pair(5, -2), Pair(15, 5), Pair(22, 15), Pair(57, 64), Pair(120, 298), Pair(-102, 545), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -1), Pair(14, 16), Pair(12, 24), Pair(36, 53), Pair(49, 318), Pair(-104, 692), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(5, 5), Pair(14, 9), Pair(20, 20), Pair(45, 69), Pair(87, 255), Pair(-128, 445), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-5, 3), Pair(19, 8), Pair(10, 24), Pair(38, 80), Pair(-133, 282), Pair(-741, 533), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, -1), Pair(-15, 5), Pair(37, 11), Pair(31, 69), Pair(-187, 276), Pair(-978, 493), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-8, 2), Pair(-36, -2), Pair(57, -7), Pair(75, 47), Pair(-69, 111), Pair(-1490, 673), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-80, 12), Pair(-73, 11), Pair(-104, 44), Pair(20, 53), Pair(-793, 226), Pair(-628, 60), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kDefendedPawnBonus = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(22, 20), Pair(12, 17), Pair(12, 22), Pair(17, 82), Pair(91, 107), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(20, 16), Pair(13, 15), Pair(15, 22), Pair(24, 53), Pair(195, 72), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(26, 8), Pair(20, 7), Pair(13, 20), Pair(23, 57), Pair(150, 78), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(32, 4), Pair(26, -1), Pair(17, 15), Pair(-5, 57), Pair(180, 39), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(4, 6), Pair(27, -5), Pair(15, 5), Pair(64, 30), Pair(75, 11), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-8, 5), Pair(14, -5), Pair(31, 5), Pair(83, 2), Pair(53, -39), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-28, 11), Pair(-52, 9), Pair(46, 8), Pair(-5, -3), Pair(78, -52), Pair(0, 0)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kDoubledPawnPenalty = {{
  {
      Pair(-10, -49), Pair(4, -31), Pair(-3, -21), Pair(-1, -16), Pair(-14, 2), Pair(-17, -4), Pair(16, -30), Pair(-17, -43)
  },
  {
      Pair(-39, -26), Pair(11, -24), Pair(4, -24), Pair(-7, -1), Pair(-5, 6), Pair(-4, -12), Pair(-7, -18), Pair(-11, -40)
  },
  {
      Pair(-7, -42), Pair(0, -23), Pair(0, -25), Pair(3, -7), Pair(-3, -4), Pair(-7, -17), Pair(-6, -23), Pair(2, -52)
  },
  {
      Pair(-29, -41), Pair(-23, -28), Pair(12, -33), Pair(12, -18), Pair(25, -17), Pair(2, -24), Pair(11, -29), Pair(-46, -42)
  },
  {
      Pair(-16, -43), Pair(19, -62), Pair(-4, -38), Pair(81, -41), Pair(77, -43), Pair(-19, -40), Pair(-1, -35), Pair(65, -70)
  },
  {
      Pair(78, -76), Pair(6, -62), Pair(-61, -46), Pair(83, -60), Pair(60, -47), Pair(-23, -46), Pair(-10, -35), Pair(58, -92)
  },
  {
      Pair(44, -60), Pair(-75, 10), Pair(-175, -14), Pair(-81, -107), Pair(82, -29), Pair(-41, -27), Pair(-77, -16), Pair(64, -104)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kIsolatedPawnPenalty = {{
  {
      Pair(1, 1), Pair(-2, -14), Pair(-11, -12), Pair(-9, -14), Pair(-16, -16), Pair(-10, -4), Pair(1, -19), Pair(-1, 0)
  },
  {
      Pair(-5, 2), Pair(-1, -13), Pair(-10, -10), Pair(-10, -12), Pair(-9, -18), Pair(3, -14), Pair(1, -12), Pair(-2, -3)
  },
  {
      Pair(4, 1), Pair(2, -15), Pair(-6, -11), Pair(-1, -21), Pair(-4, -22), Pair(0, -13), Pair(1, -15), Pair(11, -3)
  },
  {
      Pair(5, 7), Pair(-16, -13), Pair(-7, -8), Pair(10, -22), Pair(3, -24), Pair(0, -10), Pair(6, -14), Pair(6, 0)
  },
  {
      Pair(-12, 20), Pair(-14, -14), Pair(-13, 3), Pair(8, -18), Pair(-15, -16), Pair(-11, -5), Pair(-1, -10), Pair(-32, 13)
  },
  {
      Pair(-19, 20), Pair(-16, -14), Pair(-38, 14), Pair(9, -9), Pair(-45, -4), Pair(11, -8), Pair(-49, 0), Pair(-22, 12)
  },
  {
      Pair(141, -9), Pair(-152, 5), Pair(-26, 3), Pair(115, -11), Pair(-12, -6), Pair(-11, -8), Pair(41, -8), Pair(-34, 20)
  }
}};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(23, 6), Pair(20, 1), Pair(19, 9), Pair(21, 7), Pair(23, 13), Pair(37, 3), Pair(45, 1), Pair(75, -4)
  },
  {
      Pair(11, 35), Pair(11, 6), Pair(13, 8), Pair(21, -1), Pair(17, -2), Pair(22, -7), Pair(26, -7), Pair(22, 13)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -4), Pair(20, -4), Pair(9, 0),
  Pair(31, -14), Pair(30, -15), Pair(29, -13),
  Pair(39, -7), Pair(0, 0), Pair(35, -6),
  Pair(7, -2), Pair(21, -13), Pair(6, 0)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, 2), Pair(-14, 4), Pair(-8, 4),
  Pair(-6, 1), Pair(-18, 7), Pair(-9, 4),
  Pair(0, -4), Pair(-15, 5), Pair(-1, -2),
  Pair(12, -5), Pair(-6, -1), Pair(11, -3),
  Pair(24, -7), Pair(24, 3), Pair(17, -8),
  Pair(0, 0), Pair(-2, -27), Pair(0, 0),
  Pair(46, -48), Pair(0, 0), Pair(39, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-15, 99), Pair(-18, 84), Pair(-16, 67), Pair(-13, 60), Pair(-9, 58), Pair(-3, 59), Pair(-8, 52)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-77, -43), Pair(-24, -35), Pair(-21, -7), Pair(-15, 6), Pair(-13, 15), Pair(-12, 24), Pair(-20, 13)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-2624, 243);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-80, -7), Pair(-84, -4), Pair(-26, -12), Pair(-31, -8), Pair(-27, -4), Pair(-42, -2), Pair(-59, 0), Pair(-40, 6)
  },
  {
      Pair(-14, 49), Pair(-41, 21), Pair(-3, 12), Pair(3, -2), Pair(-9, -3), Pair(-4, 3), Pair(-30, 18), Pair(-17, 32)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 3), Pair(25, -7), Pair(58, -28), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 1), Pair(31, -1), Pair(65, -12), Pair(74, -46), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(22, -20), Pair(37, -20), Pair(53, -13), Pair(82, -14), Pair(89, -23), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 15), Pair(10, 28), Pair(30, 31), Pair(76, 16), Pair(113, 12), Pair(176, -10), Pair(227, -52)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(51, 9), Pair(20, 24), Pair(60, 2), Pair(27, 17), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-20, 14), Pair(-12, 21)
  },
  {
      Pair(-73, -26), Pair(-72, -36)
  },
  {
      Pair(-61, -53), Pair(-71, -82)
  },
  {
      Pair(-101, -1), Pair(-91, -41)
  },
  {
      Pair(-82, 36), Pair(-91, 19)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(19, 35), Pair(22, 25), Pair(32, 13), Pair(23, 0), Pair(59, -6)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-2, -22), Pair(10, -12)
  },
  {
      Pair(-25, -49), Pair(-5, -66)
  },
  {
      Pair(-45, -37), Pair(-31, -39)
  },
  {
      Pair(-88, -4), Pair(-66, -32)
  },
  {
      Pair(-60, 33), Pair(-62, 22)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-11, -22), Pair(1, -9)
  },
  {
      Pair(-53, -25), Pair(-24, -27)
  },
  {
      Pair(18, -154), Pair(31, -148)
  },
  {
      Pair(-89, -7), Pair(-51, -42)
  },
  {
      Pair(-92, -18), Pair(-67, -94)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(0, -27), Pair(14, -12)
  },
  {
      Pair(-46, -27), Pair(-2, -14)
  },
  {
      Pair(-33, -32), Pair(-14, -6)
  },
  {
      Pair(2, -75), Pair(18, -49)
  },
  {
      Pair(-94, 15), Pair(-66, -51)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(16, 31), Pair(17, 16), Pair(42, 25), Pair(50, 27), Pair(54, 33), Pair(39, 47), Pair(49, 16), Pair(3, 36),
  Pair(3, 20), Pair(14, 19), Pair(20, 23), Pair(11, 38), Pair(15, 26), Pair(13, 21), Pair(15, 18), Pair(-10, 30),
  Pair(10, 11), Pair(6, 3), Pair(2, 17), Pair(9, 20), Pair(7, 23), Pair(-8, 22), Pair(3, 8), Pair(0, 9)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-17, 21), Pair(23, 2), Pair(34, 3), Pair(48, 3), Pair(76, -16), Pair(50, -2), Pair(27, -9), Pair(-21, -22),
  Pair(-22, -14), Pair(21, 10), Pair(13, 6), Pair(27, 11), Pair(15, 8), Pair(18, -3), Pair(13, 15), Pair(15, -17),
  Pair(-24, 34), Pair(11, 5), Pair(3, 23), Pair(21, 16), Pair(27, 25), Pair(3, 9), Pair(15, 2), Pair(-52, 10)
};

constexpr ScorePair kBishopPairBonus = Pair(24, 63);

constexpr ScorePair kTempoBonus = Pair(34, 30);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H