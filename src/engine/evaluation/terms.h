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
  Pair(70, 134), Pair(269, 1), Pair(383, 375), Pair(426, 725), Pair(815, 1103), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(15, 29), Pair(-4, 59), Pair(-9, 65), Pair(43, -1), Pair(45, -13), Pair(60, -35), Pair(-3, -106), Pair(-71, -57),
      Pair(10, 59), Pair(-9, 85), Pair(20, 42), Pair(25, 4), Pair(42, 8), Pair(93, -27), Pair(37, 16), Pair(19, 17),
      Pair(-7, 10), Pair(-7, 22), Pair(-1, -11), Pair(-1, -30), Pair(24, -40), Pair(26, -41), Pair(-3, -2), Pair(4, -27),
      Pair(-8, -11), Pair(-16, 18), Pair(-2, -22), Pair(8, -34), Pair(12, -37), Pair(20, -40), Pair(-4, -9), Pair(1, -37),
      Pair(-18, -17), Pair(-24, 9), Pair(-14, -18), Pair(-9, -21), Pair(-3, -19), Pair(-3, -27), Pair(-7, -13), Pair(-2, -42),
      Pair(-9, -13), Pair(-14, 14), Pair(-6, -9), Pair(-11, -18), Pair(-1, -6), Pair(17, -18), Pair(7, -5), Pair(-2, -44),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-171, 48), Pair(-163, 58), Pair(-84, 63), Pair(-51, 33), Pair(-41, 40), Pair(-24, -44), Pair(-104, -5), Pair(-83, -94),
      Pair(-43, 53), Pair(-19, 59), Pair(-6, 46), Pair(-10, 61), Pair(-12, 52), Pair(71, 16), Pair(17, 53), Pair(24, -3),
      Pair(-9, 44), Pair(2, 62), Pair(-2, 74), Pair(10, 55), Pair(26, 44), Pair(73, 35), Pair(-1, 53), Pair(40, 34),
      Pair(1, 59), Pair(19, 54), Pair(34, 59), Pair(39, 65), Pair(33, 61), Pair(46, 57), Pair(23, 59), Pair(34, 48),
      Pair(-7, 48), Pair(15, 45), Pair(27, 61), Pair(30, 60), Pair(31, 65), Pair(42, 41), Pair(31, 50), Pair(8, 44),
      Pair(-22, 33), Pair(0, 43), Pair(12, 46), Pair(19, 62), Pair(31, 59), Pair(21, 42), Pair(19, 41), Pair(2, 37),
      Pair(-30, 33), Pair(-18, 41), Pair(-5, 42), Pair(9, 38), Pair(11, 40), Pair(7, 30), Pair(3, 35), Pair(1, 44),
      Pair(-60, 52), Pair(-18, 22), Pair(-18, 40), Pair(-11, 52), Pair(3, 48), Pair(5, 33), Pair(-24, 38), Pair(-16, 14)
    },
    {
      Pair(-36, 48), Pair(-47, 28), Pair(-65, 26), Pair(-89, 49), Pair(-85, 13), Pair(-48, -13), Pair(-58, 51), Pair(-68, 61),
      Pair(-21, 33), Pair(-12, 35), Pair(-4, 14), Pair(-31, 29), Pair(-20, 7), Pair(-7, 13), Pair(-49, 55), Pair(-20, 23),
      Pair(1, 33), Pair(-2, 34), Pair(-2, 30), Pair(-11, 21), Pair(-22, 34), Pair(36, 38), Pair(32, 33), Pair(14, 42),
      Pair(-13, 34), Pair(5, 33), Pair(4, 28), Pair(10, 49), Pair(8, 24), Pair(14, 25), Pair(1, 26), Pair(-5, 30),
      Pair(-1, 14), Pair(-17, 33), Pair(4, 33), Pair(10, 16), Pair(10, 16), Pair(4, 17), Pair(-4, 28), Pair(9, -1),
      Pair(-7, 7), Pair(16, 36), Pair(12, 27), Pair(10, 28), Pair(10, 40), Pair(16, 29), Pair(20, 17), Pair(16, 8),
      Pair(12, 15), Pair(13, -6), Pair(20, 3), Pair(4, 19), Pair(18, 19), Pair(22, 17), Pair(34, 14), Pair(28, -17),
      Pair(6, -3), Pair(27, 7), Pair(5, 15), Pair(1, 23), Pair(15, 20), Pair(3, 32), Pair(19, 17), Pair(39, -32)
    },
    {
      Pair(1, 121), Pair(52, 106), Pair(-10, 153), Pair(35, 85), Pair(70, 59), Pair(42, 118), Pair(-32, 107), Pair(-14, 47),
      Pair(0, 52), Pair(4, 62), Pair(16, 67), Pair(33, 46), Pair(19, 44), Pair(61, 41), Pair(67, 44), Pair(29, 38),
      Pair(2, 41), Pair(32, 47), Pair(22, 53), Pair(24, 44), Pair(57, 18), Pair(76, 8), Pair(104, 14), Pair(47, 3),
      Pair(14, 36), Pair(31, 43), Pair(36, 42), Pair(29, 40), Pair(39, 27), Pair(44, 21), Pair(56, 18), Pair(35, 1),
      Pair(2, 34), Pair(10, 45), Pair(11, 37), Pair(17, 40), Pair(16, 29), Pair(1, 34), Pair(38, 13), Pair(12, -3),
      Pair(-2, 29), Pair(4, 26), Pair(5, 35), Pair(6, 35), Pair(16, 24), Pair(17, 13), Pair(50, -11), Pair(23, -24),
      Pair(-6, 19), Pair(-2, 36), Pair(16, 27), Pair(13, 33), Pair(23, 17), Pair(18, 18), Pair(42, -10), Pair(-1, -5),
      Pair(8, 22), Pair(10, 21), Pair(14, 27), Pair(20, 21), Pair(25, 12), Pair(23, 14), Pair(21, 3), Pair(7, -3)
    },
    {
      Pair(-162, 270), Pair(-29, 130), Pair(-37, 149), Pair(-13, 147), Pair(21, 70), Pair(22, 74), Pair(-3, 138), Pair(-128, 247),
      Pair(-55, 111), Pair(-42, 113), Pair(-48, 156), Pair(-54, 161), Pair(-72, 190), Pair(-25, 169), Pair(-70, 159), Pair(-58, 191),
      Pair(-27, 101), Pair(-27, 112), Pair(-29, 134), Pair(-31, 144), Pair(-29, 144), Pair(5, 145), Pair(1, 130), Pair(5, 101),
      Pair(-33, 112), Pair(-22, 121), Pair(-22, 124), Pair(-25, 147), Pair(-23, 138), Pair(-1, 104), Pair(-3, 126), Pair(1, 95),
      Pair(-29, 97), Pair(-33, 129), Pair(-25, 118), Pair(-24, 141), Pair(-19, 128), Pair(-23, 123), Pair(-3, 104), Pair(-10, 103),
      Pair(-27, 88), Pair(-21, 103), Pair(-23, 115), Pair(-28, 120), Pair(-27, 131), Pair(-15, 110), Pair(2, 92), Pair(-4, 70),
      Pair(-23, 84), Pair(-19, 72), Pair(-16, 78), Pair(-13, 92), Pair(-14, 91), Pair(-7, 60), Pair(9, 24), Pair(18, -2),
      Pair(-33, 84), Pair(-28, 76), Pair(-21, 76), Pair(-19, 78), Pair(-18, 74), Pair(-24, 58), Pair(-20, 49), Pair(-5, 33)
    },
    {
      Pair(-594, -104), Pair(-529, -69), Pair(-568, -49), Pair(-587, -72), Pair(-712, -31), Pair(-642, -46), Pair(-675, -9), Pair(-558, -263),
      Pair(-639, -37), Pair(-500, -22), Pair(-557, -17), Pair(-575, -23), Pair(-653, -12), Pair(-807, 13), Pair(-623, -2), Pair(-702, -42),
      Pair(-812, 10), Pair(-548, 24), Pair(-744, 66), Pair(-688, 38), Pair(-779, 49), Pair(-617, 27), Pair(-733, 45), Pair(-723, -15),
      Pair(-691, -21), Pair(-639, 4), Pair(-682, 16), Pair(-676, 17), Pair(-766, 29), Pair(-727, 25), Pair(-732, 17), Pair(-710, -45),
      Pair(-335, -12), Pair(-292, 10), Pair(-390, 41), Pair(-464, 69), Pair(-448, 52), Pair(-405, 27), Pair(-362, 8), Pair(-413, -12),
      Pair(-268, -1), Pair(-185, 7), Pair(-251, 41), Pair(-293, 59), Pair(-290, 55), Pair(-265, 29), Pair(-206, -5), Pair(-234, -18),
      Pair(-40, -18), Pair(-70, 16), Pair(-78, 27), Pair(-103, 38), Pair(-111, 38), Pair(-83, 21), Pair(-59, -5), Pair(-45, -36),
      Pair(93, -35), Pair(112, 1), Pair(-52, 16), Pair(-116, 32), Pair(-73, 1), Pair(-90, 24), Pair(98, -7), Pair(104, -52)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(119, 59), Pair(-6, 52), Pair(8, -38), Pair(50, -81), Pair(27, -87), Pair(-19, -38), Pair(-79, 141), Pair(42, 86),
      Pair(5, 53), Pair(2, 46), Pair(45, -13), Pair(45, -34), Pair(59, -58), Pair(53, -17), Pair(35, 26), Pair(26, 24),
      Pair(-22, 14), Pair(-9, 11), Pair(0, -16), Pair(6, -29), Pair(23, -34), Pair(8, -25), Pair(7, -4), Pair(17, -14),
      Pair(-34, -1), Pair(-23, 9), Pair(-10, -26), Pair(9, -25), Pair(12, -29), Pair(7, -30), Pair(-9, -5), Pair(8, -32),
      Pair(-48, -9), Pair(-34, 5), Pair(-26, -23), Pair(-19, -13), Pair(-11, -22), Pair(-17, -25), Pair(-9, -15), Pair(-6, -36),
      Pair(-36, -5), Pair(-22, 8), Pair(-17, -11), Pair(-16, -10), Pair(-7, -5), Pair(0, -19), Pair(7, -16), Pair(-3, -33),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-104, -69), Pair(-28, 30), Pair(-71, 56), Pair(-37, -2), Pair(152, -31), Pair(-25, -6), Pair(-154, 22), Pair(-104, -40),
      Pair(-3, 29), Pair(-19, 62), Pair(-5, 63), Pair(45, -23), Pair(38, -8), Pair(14, 38), Pair(-13, 60), Pair(-22, 18),
      Pair(-7, 43), Pair(16, 48), Pair(1, 61), Pair(43, 43), Pair(3, 46), Pair(13, 39), Pair(-8, 37), Pair(20, 0),
      Pair(25, 55), Pair(1, 63), Pair(19, 63), Pair(21, 71), Pair(29, 62), Pair(31, 76), Pair(27, 59), Pair(27, 37),
      Pair(-9, 57), Pair(10, 55), Pair(19, 65), Pair(33, 57), Pair(20, 70), Pair(39, 44), Pair(17, 50), Pair(1, 55),
      Pair(-27, 37), Pair(-2, 44), Pair(4, 47), Pair(16, 50), Pair(27, 56), Pair(10, 43), Pair(12, 44), Pair(-12, 39),
      Pair(-35, 37), Pair(-9, 47), Pair(-10, 33), Pair(2, 45), Pair(1, 40), Pair(0, 57), Pair(-3, 3), Pair(-14, 52),
      Pair(-77, 70), Pair(-36, 63), Pair(-24, 45), Pair(-8, 53), Pair(-10, 36), Pair(-2, 27), Pair(-31, 56), Pair(-44, 47)
    },
    {
      Pair(8, 15), Pair(-70, 27), Pair(-73, 0), Pair(-161, 39), Pair(-72, 19), Pair(-93, 13), Pair(-26, 0), Pair(-42, -2),
      Pair(1, -13), Pair(4, 11), Pair(-2, 0), Pair(-17, 17), Pair(-15, 21), Pair(-15, 7), Pair(-43, 30), Pair(-47, 6),
      Pair(1, 32), Pair(27, -4), Pair(5, 9), Pair(42, 8), Pair(36, -1), Pair(3, 42), Pair(13, 22), Pair(-3, 29),
      Pair(-8, 18), Pair(5, 20), Pair(13, 21), Pair(13, 16), Pair(19, 13), Pair(21, 18), Pair(-1, 20), Pair(-12, 26),
      Pair(-5, 11), Pair(-21, 17), Pair(-2, 11), Pair(20, 14), Pair(16, 6), Pair(4, 16), Pair(-6, 17), Pair(-3, 23),
      Pair(-9, 20), Pair(17, 11), Pair(13, 15), Pair(5, 26), Pair(13, 21), Pair(15, 12), Pair(23, 18), Pair(12, -4),
      Pair(13, 1), Pair(13, 6), Pair(27, -7), Pair(4, 16), Pair(9, 12), Pair(19, 19), Pair(34, 2), Pair(14, 29),
      Pair(18, -13), Pair(23, -8), Pair(-5, 27), Pair(10, 12), Pair(16, 4), Pair(-16, 35), Pair(10, -33), Pair(18, -15)
    },
    {
      Pair(69, 49), Pair(85, 64), Pair(81, 50), Pair(105, 41), Pair(42, 8), Pair(-57, 65), Pair(39, 62), Pair(-20, 94),
      Pair(43, 40), Pair(41, 47), Pair(30, 43), Pair(67, 23), Pair(32, 29), Pair(-25, 66), Pair(-3, 58), Pair(-11, 61),
      Pair(19, 48), Pair(47, 32), Pair(29, 39), Pair(29, 17), Pair(21, 13), Pair(23, 22), Pair(49, 26), Pair(-12, 35),
      Pair(13, 35), Pair(15, 37), Pair(13, 32), Pair(0, 31), Pair(12, 15), Pair(23, 20), Pair(-3, 36), Pair(-20, 47),
      Pair(-15, 27), Pair(-34, 40), Pair(-6, 26), Pair(-15, 40), Pair(4, 21), Pair(-20, 43), Pair(-16, 34), Pair(-31, 35),
      Pair(-36, 27), Pair(-12, 23), Pair(2, 19), Pair(-6, 19), Pair(-3, 16), Pair(-13, 31), Pair(4, 11), Pair(-27, 32),
      Pair(-18, 3), Pair(-10, 16), Pair(-6, 20), Pair(-20, 20), Pair(-1, 9), Pair(-10, 23), Pair(-3, 12), Pair(-35, 18),
      Pair(-21, 19), Pair(-6, 14), Pair(-2, 19), Pair(0, 7), Pair(13, -1), Pair(-4, 17), Pair(-18, 19), Pair(-22, 10)
    },
    {
      Pair(63, 34), Pair(50, 41), Pair(64, 20), Pair(109, -16), Pair(-209, 298), Pair(-2, 123), Pair(7, 110), Pair(2, 100),
      Pair(80, 11), Pair(30, 37), Pair(35, 73), Pair(19, 97), Pair(-103, 209), Pair(-5, 80), Pair(20, 53), Pair(57, 59),
      Pair(51, 25), Pair(50, 25), Pair(47, 51), Pair(34, 93), Pair(15, 107), Pair(21, 90), Pair(50, 40), Pair(30, 59),
      Pair(39, 46), Pair(28, 72), Pair(41, 79), Pair(-5, 120), Pair(21, 93), Pair(22, 103), Pair(29, 85), Pair(44, 57),
      Pair(23, 45), Pair(0, 116), Pair(15, 89), Pair(15, 81), Pair(22, 99), Pair(19, 74), Pair(21, 72), Pair(25, 75),
      Pair(25, 39), Pair(25, 52), Pair(16, 79), Pair(10, 78), Pair(24, 74), Pair(23, 62), Pair(32, 56), Pair(24, 41),
      Pair(15, -16), Pair(29, 0), Pair(26, 29), Pair(24, 39), Pair(31, 31), Pair(31, 30), Pair(30, 13), Pair(27, 20),
      Pair(9, 42), Pair(1, 62), Pair(13, 42), Pair(14, 19), Pair(30, -10), Pair(3, 46), Pair(34, 13), Pair(7, 60)
    },
    {
      Pair(-108, -116), Pair(-156, -45), Pair(-189, -59), Pair(13, -70), Pair(-83, -41), Pair(-176, 65), Pair(-134, -34), Pair(-91, -111),
      Pair(-136, -64), Pair(-156, -16), Pair(-160, -3), Pair(-43, -6), Pair(-123, 57), Pair(-94, 53), Pair(-164, 19), Pair(-174, -32),
      Pair(-188, -35), Pair(-147, 3), Pair(-251, 31), Pair(-207, 34), Pair(-167, 33), Pair(-143, 39), Pair(-161, 8), Pair(-149, -20),
      Pair(-166, -55), Pair(-107, -34), Pair(-196, 0), Pair(-199, 4), Pair(-218, 0), Pair(-184, -3), Pair(-126, -39), Pair(-256, -30),
      Pair(-101, -27), Pair(-77, -3), Pair(-116, 10), Pair(-198, 42), Pair(-175, 25), Pair(-154, 5), Pair(-122, -12), Pair(-173, -26),
      Pair(-54, -29), Pair(-62, -10), Pair(-91, 7), Pair(-117, 23), Pair(-128, 31), Pair(-111, 8), Pair(-67, -16), Pair(-89, -26),
      Pair(35, -49), Pair(16, -1), Pair(8, 0), Pair(-28, 23), Pair(-26, 19), Pair(-26, 8), Pair(-6, -13), Pair(14, -41),
      Pair(22, -35), Pair(49, -4), Pair(22, -2), Pair(-22, 8), Pair(1, -2), Pair(-26, 9), Pair(25, 4), Pair(33, -30)
    }
  }},
  {{ // Bucket 2
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(29, 38), Pair(36, 28), Pair(13, 26), Pair(26, -12), Pair(6, -7), Pair(24, -13), Pair(-51, 58), Pair(53, 34),
      Pair(-3, 11), Pair(-11, 35), Pair(20, -16), Pair(27, -43), Pair(33, -52), Pair(75, -47), Pair(26, -1), Pair(-5, 5),
      Pair(-6, 2), Pair(-15, 15), Pair(-6, -13), Pair(0, -28), Pair(27, -29), Pair(16, -25), Pair(2, -2), Pair(5, -13),
      Pair(-22, -9), Pair(-27, 13), Pair(-7, -19), Pair(-1, -25), Pair(2, -24), Pair(4, -28), Pair(-5, -10), Pair(1, -25),
      Pair(-27, -16), Pair(-32, 4), Pair(-16, -20), Pair(-15, -17), Pair(3, -24), Pair(-10, -26), Pair(-4, -18), Pair(-3, -31),
      Pair(-15, -12), Pair(-20, 10), Pair(-3, -16), Pair(-17, -13), Pair(5, -8), Pair(10, -20), Pair(21, -17), Pair(-3, -27),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-137, -58), Pair(-56, 11), Pair(-77, 10), Pair(4, -8), Pair(-1, -1), Pair(-27, -35), Pair(-31, -18), Pair(-114, -78),
      Pair(-29, 3), Pair(-21, 30), Pair(-8, 28), Pair(34, 13), Pair(22, 7), Pair(11, 20), Pair(-28, 22), Pair(-45, 8),
      Pair(-29, 40), Pair(3, 35), Pair(24, 31), Pair(47, 19), Pair(51, 20), Pair(86, -12), Pair(52, 6), Pair(2, 0),
      Pair(2, 32), Pair(17, 38), Pair(36, 42), Pair(54, 32), Pair(60, 34), Pair(60, 31), Pair(37, 34), Pair(47, 2),
      Pair(-15, 40), Pair(21, 40), Pair(33, 48), Pair(47, 43), Pair(52, 46), Pair(63, 30), Pair(51, 25), Pair(20, 30),
      Pair(-42, 42), Pair(-14, 38), Pair(8, 44), Pair(25, 48), Pair(45, 44), Pair(24, 28), Pair(18, 21), Pair(1, 29),
      Pair(-49, 35), Pair(-39, 41), Pair(-15, 40), Pair(6, 41), Pair(14, 37), Pair(-5, 41), Pair(1, 26), Pair(-6, 33),
      Pair(-87, 17), Pair(-35, 30), Pair(-34, 34), Pair(1, 30), Pair(-13, 41), Pair(-12, 30), Pair(-10, 24), Pair(-49, 51)
    },
    {
      Pair(-42, 5), Pair(-47, 11), Pair(-23, 7), Pair(-86, -2), Pair(-52, -15), Pair(-104, -6), Pair(-54, -6), Pair(-80, 1),
      Pair(-50, -7), Pair(-12, 0), Pair(1, -7), Pair(1, -15), Pair(-12, -7), Pair(-20, 6), Pair(-32, 8), Pair(-8, -22),
      Pair(-14, 7), Pair(12, -5), Pair(-22, 10), Pair(11, -14), Pair(-8, -1), Pair(-17, 4), Pair(-8, -3), Pair(5, -10),
      Pair(-13, 3), Pair(-3, 7), Pair(20, 1), Pair(17, 8), Pair(43, 4), Pair(50, -1), Pair(20, 1), Pair(5, -5),
      Pair(-22, 4), Pair(-4, 6), Pair(0, 0), Pair(21, 3), Pair(25, -6), Pair(10, 0), Pair(-10, 3), Pair(2, -6),
      Pair(-11, 4), Pair(6, 5), Pair(11, 8), Pair(9, 9), Pair(11, 15), Pair(17, 2), Pair(16, -1), Pair(6, -10),
      Pair(-20, 8), Pair(3, -5), Pair(16, -8), Pair(0, 6), Pair(5, 6), Pair(18, -1), Pair(24, -8), Pair(12, -16),
      Pair(-31, 5), Pair(17, -13), Pair(-4, 6), Pair(-5, 3), Pair(-6, 8), Pair(-7, 13), Pair(0, 7), Pair(7, -12)
    },
    {
      Pair(-52, 29), Pair(-50, 35), Pair(-36, 32), Pair(-38, 27), Pair(-15, 11), Pair(26, 10), Pair(-24, 28), Pair(-42, 31),
      Pair(-6, 17), Pair(3, 27), Pair(18, 17), Pair(47, 13), Pair(30, 2), Pair(25, 4), Pair(-14, 16), Pair(-22, 18),
      Pair(-9, 12), Pair(26, 12), Pair(15, 11), Pair(16, 1), Pair(52, -12), Pair(71, -11), Pair(59, -1), Pair(-5, 2),
      Pair(-22, 21), Pair(8, 15), Pair(10, 20), Pair(14, 7), Pair(32, -9), Pair(46, -11), Pair(31, -8), Pair(-31, 6),
      Pair(-32, 6), Pair(-27, 16), Pair(-8, 7), Pair(-2, 7), Pair(6, 0), Pair(3, -5), Pair(-5, -1), Pair(-18, -6),
      Pair(-23, -2), Pair(-22, 8), Pair(-14, 1), Pair(-10, 5), Pair(4, -8), Pair(2, -10), Pair(14, -22), Pair(2, -32),
      Pair(-29, -1), Pair(-20, 2), Pair(-18, 5), Pair(-2, -3), Pair(-9, -7), Pair(0, -14), Pair(-11, -11), Pair(-38, -17),
      Pair(-21, 2), Pair(-17, 0), Pair(-10, 0), Pair(-3, -4), Pair(2, -11), Pair(0, -8), Pair(-8, -10), Pair(-28, -10)
    },
    {
      Pair(-62, 29), Pair(-97, 50), Pair(-58, 53), Pair(-36, 39), Pair(-20, 32), Pair(-25, 46), Pair(27, -10), Pair(-20, 21),
      Pair(-22, 30), Pair(-27, 49), Pair(-12, 49), Pair(-45, 69), Pair(-22, 45), Pair(-18, 31), Pair(-30, 113), Pair(15, 47),
      Pair(-3, 14), Pair(-9, 30), Pair(-10, 61), Pair(3, 41), Pair(0, 66), Pair(37, 29), Pair(20, 22), Pair(11, 50),
      Pair(-18, 16), Pair(6, 22), Pair(11, 27), Pair(4, 33), Pair(13, 54), Pair(18, 42), Pair(32, 23), Pair(14, 36),
      Pair(-13, 21), Pair(-3, 31), Pair(-4, 54), Pair(10, 55), Pair(12, 50), Pair(-8, 46), Pair(9, 30), Pair(12, 18),
      Pair(-8, 6), Pair(-9, 35), Pair(1, 38), Pair(5, 40), Pair(2, 39), Pair(7, 34), Pair(14, 21), Pair(12, 3),
      Pair(-3, 4), Pair(-2, 22), Pair(2, 21), Pair(3, 27), Pair(7, 23), Pair(15, -4), Pair(19, -14), Pair(-3, -14),
      Pair(-5, -13), Pair(-3, -8), Pair(-20, 17), Pair(0, 8), Pair(-15, 13), Pair(-17, 1), Pair(-10, -10), Pair(-25, 19)
    },
    {
      Pair(-35, -150), Pair(-178, -68), Pair(-169, -27), Pair(-146, -48), Pair(-246, 5), Pair(-219, -1), Pair(-271, 12), Pair(-59, -104),
      Pair(-174, -69), Pair(-135, -14), Pair(-172, 7), Pair(-221, 13), Pair(-192, 4), Pair(-193, 18), Pair(-228, 11), Pair(-188, -55),
      Pair(-154, -36), Pair(-115, 1), Pair(-138, 13), Pair(-254, 32), Pair(-219, 24), Pair(-201, 27), Pair(-259, 27), Pair(-201, -23),
      Pair(-148, -47), Pair(-132, -21), Pair(-180, 1), Pair(-261, 17), Pair(-270, 13), Pair(-225, -4), Pair(-238, -17), Pair(-243, -42),
      Pair(-101, -32), Pair(-90, -6), Pair(-115, 13), Pair(-166, 28), Pair(-166, 28), Pair(-138, 7), Pair(-114, -12), Pair(-210, -14),
      Pair(-22, -38), Pair(-22, -11), Pair(-92, 17), Pair(-84, 25), Pair(-111, 29), Pair(-97, 11), Pair(-65, -9), Pair(-87, -28),
      Pair(42, -40), Pair(-1, 4), Pair(-20, 18), Pair(-18, 26), Pair(-33, 31), Pair(-25, 21), Pair(3, 0), Pair(15, -29),
      Pair(33, -33), Pair(66, -2), Pair(38, -5), Pair(-17, 13), Pair(2, 9), Pair(-3, 9), Pair(40, 7), Pair(31, -27)
    }
  }},
  {{ // Bucket 3
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(40, 26), Pair(142, -23), Pair(26, 31), Pair(1, 15), Pair(1, 8), Pair(-8, 9), Pair(78, 52), Pair(3, 57),
      Pair(17, -10), Pair(1, 0), Pair(50, -44), Pair(72, -67), Pair(27, -53), Pair(46, -45), Pair(48, -21), Pair(58, -18),
      Pair(-24, 3), Pair(-14, -4), Pair(-2, -27), Pair(-9, -32), Pair(28, -35), Pair(30, -39), Pair(-1, -7), Pair(12, -17),
      Pair(-37, -6), Pair(-30, 2), Pair(-15, -15), Pair(-14, -11), Pair(-11, -13), Pair(-4, -20), Pair(-6, -3), Pair(2, -24),
      Pair(-38, -13), Pair(-40, -6), Pair(-6, -25), Pair(-21, -18), Pair(4, -24), Pair(4, -29), Pair(-13, -18), Pair(-9, -28),
      Pair(-37, -3), Pair(-23, -1), Pair(2, -17), Pair(-31, -11), Pair(5, -16), Pair(20, -25), Pair(8, -15), Pair(-19, -17),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-120, -66), Pair(-206, -10), Pair(-159, 16), Pair(52, -25), Pair(55, -17), Pair(16, -17), Pair(-250, 17), Pair(-59, -80),
      Pair(-87, 25), Pair(11, 3), Pair(29, -12), Pair(78, -13), Pair(99, -35), Pair(46, -26), Pair(-43, 5), Pair(-24, -11),
      Pair(-43, -1), Pair(14, -4), Pair(22, 17), Pair(58, 4), Pair(84, 7), Pair(74, -22), Pair(-18, 9), Pair(5, -18),
      Pair(14, 21), Pair(27, 8), Pair(54, 15), Pair(82, 6), Pair(98, 0), Pair(76, 10), Pair(139, -26), Pair(40, 5),
      Pair(-1, 26), Pair(8, 20), Pair(42, 21), Pair(66, 13), Pair(80, 14), Pair(71, 5), Pair(84, -2), Pair(23, 4),
      Pair(-31, 13), Pair(-1, 21), Pair(10, 26), Pair(44, 30), Pair(65, 22), Pair(31, 18), Pair(37, 6), Pair(22, 16),
      Pair(-98, 50), Pair(-60, 35), Pair(0, 21), Pair(16, 18), Pair(-1, 23), Pair(14, 23), Pair(4, 11), Pair(-46, 44),
      Pair(-140, 38), Pair(-60, 18), Pair(-80, 37), Pair(-44, 25), Pair(26, 17), Pair(14, 13), Pair(-48, 36), Pair(-105, 30)
    },
    {
      Pair(-58, -4), Pair(20, -23), Pair(-32, -13), Pair(-6, -31), Pair(-51, -11), Pair(-39, -8), Pair(-7, -20), Pair(-152, -8),
      Pair(-39, -16), Pair(-50, -4), Pair(-28, -14), Pair(73, -40), Pair(-30, -28), Pair(-39, -18), Pair(-46, -11), Pair(-36, -4),
      Pair(-14, -4), Pair(35, -14), Pair(7, -15), Pair(22, -27), Pair(29, -33), Pair(38, -19), Pair(-17, -9), Pair(30, -20),
      Pair(41, -25), Pair(5, -16), Pair(24, -16), Pair(74, -36), Pair(61, -32), Pair(60, -25), Pair(29, -22), Pair(-8, -17),
      Pair(-17, -8), Pair(29, -14), Pair(15, -16), Pair(83, -24), Pair(32, -19), Pair(31, -9), Pair(13, -9), Pair(27, -24),
      Pair(2, -11), Pair(2, -10), Pair(24, -12), Pair(15, -7), Pair(40, -9), Pair(-7, -3), Pair(0, -6), Pair(2, -4),
      Pair(-47, 16), Pair(-21, -9), Pair(9, -10), Pair(-2, -7), Pair(-12, -2), Pair(16, -16), Pair(26, -23), Pair(-40, -7),
      Pair(-3, -7), Pair(-13, -4), Pair(-13, -7), Pair(-47, 0), Pair(-18, -7), Pair(-17, -6), Pair(-41, -2), Pair(-43, -9)
    },
    {
      Pair(-81, 5), Pair(-65, 7), Pair(-23, -5), Pair(-3, -13), Pair(-43, -2), Pair(-90, 10), Pair(-24, -5), Pair(-41, -5),
      Pair(-52, -20), Pair(-27, -12), Pair(5, -23), Pair(39, -41), Pair(27, -41), Pair(38, -33), Pair(-13, -24), Pair(-39, -23),
      Pair(-18, -19), Pair(-7, -10), Pair(0, -19), Pair(21, -38), Pair(4, -34), Pair(1, -31), Pair(-62, 9), Pair(-112, 7),
      Pair(-42, -8), Pair(-8, -16), Pair(14, -18), Pair(23, -22), Pair(22, -36), Pair(46, -39), Pair(24, -26), Pair(-51, -17),
      Pair(-84, -5), Pair(-76, 5), Pair(-41, -9), Pair(-35, -16), Pair(-3, -33), Pair(15, -32), Pair(-8, -25), Pair(-59, -23),
      Pair(-71, -22), Pair(-51, -20), Pair(-44, -29), Pair(-22, -29), Pair(-13, -37), Pair(-11, -34), Pair(-4, -44), Pair(-73, -28),
      Pair(-73, -22), Pair(-55, -18), Pair(-35, -28), Pair(-58, -23), Pair(-32, -39), Pair(-20, -43), Pair(-35, -41), Pair(-94, -27),
      Pair(-65, -18), Pair(-76, -10), Pair(-46, -21), Pair(-36, -28), Pair(-36, -33), Pair(-33, -27), Pair(-63, -19), Pair(-75, -18)
    },
    {
      Pair(14, -27), Pair(54, -53), Pair(134, -79), Pair(236, -143), Pair(105, -60), Pair(80, -49), Pair(119, -100), Pair(18, -14),
      Pair(50, -74), Pair(1, -47), Pair(-23, -6), Pair(-17, -3), Pair(64, -6), Pair(17, 0), Pair(59, -71), Pair(75, -53),
      Pair(-20, -20), Pair(7, -22), Pair(3, 19), Pair(45, -17), Pair(17, 22), Pair(97, -27), Pair(83, -46), Pair(114, -98),
      Pair(41, -54), Pair(30, -55), Pair(13, -6), Pair(106, -58), Pair(94, -60), Pair(117, -59), Pair(79, -41), Pair(84, -72),
      Pair(13, -41), Pair(25, -37), Pair(36, -50), Pair(54, -40), Pair(68, -67), Pair(53, -39), Pair(88, -80), Pair(87, -78),
      Pair(16, -77), Pair(21, -42), Pair(28, -36), Pair(18, -27), Pair(41, -28), Pair(60, -74), Pair(56, -84), Pair(70, -51),
      Pair(4, -79), Pair(17, -78), Pair(9, -43), Pair(41, -43), Pair(39, -66), Pair(52, -72), Pair(36, -81), Pair(-35, -13),
      Pair(-25, -40), Pair(-17, -52), Pair(5, -12), Pair(-1, -16), Pair(-43, -31), Pair(5, -27), Pair(-37, -97), Pair(8, -110)
    },
    {
      Pair(-33, -109), Pair(65, -107), Pair(-137, -41), Pair(-134, -18), Pair(-108, -49), Pair(-254, -3), Pair(-113, -44), Pair(-87, -119),
      Pair(-96, -53), Pair(-80, -17), Pair(-210, 11), Pair(-114, -18), Pair(-146, 8), Pair(-214, 20), Pair(-46, -1), Pair(-195, -27),
      Pair(-123, -28), Pair(-102, -2), Pair(-176, 21), Pair(-168, 15), Pair(-236, 32), Pair(-157, 24), Pair(-159, 24), Pair(-206, -19),
      Pair(-102, -42), Pair(-97, -25), Pair(-141, 2), Pair(-169, 6), Pair(-211, 7), Pair(-218, 20), Pair(-151, -19), Pair(-203, -25),
      Pair(-58, -38), Pair(5, -21), Pair(-58, 11), Pair(-59, 19), Pair(-97, 19), Pair(-56, 3), Pair(-57, -16), Pair(-73, -42),
      Pair(-31, -18), Pair(78, -13), Pair(-12, 14), Pair(-11, 20), Pair(2, 16), Pair(-6, 10), Pair(8, -8), Pair(-25, -23),
      Pair(130, -48), Pair(110, -14), Pair(84, 4), Pair(81, 9), Pair(76, 10), Pair(70, 6), Pair(91, -12), Pair(99, -34),
      Pair(12, -20), Pair(86, -14), Pair(136, -13), Pair(86, -1), Pair(88, 4), Pair(88, 0), Pair(46, -1), Pair(15, -20)
    }
  }},
  {{ // Bucket 4
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-11, 39), Pair(246, -26), Pair(-75, 82), Pair(94, 27), Pair(-54, 66), Pair(-31, 71), Pair(-147, 131), Pair(-6, 62),
      Pair(-34, -11), Pair(13, -15), Pair(-40, -16), Pair(44, -31), Pair(44, -28), Pair(25, -22), Pair(-41, 19), Pair(107, -23),
      Pair(-47, -4), Pair(1, -11), Pair(-1, -26), Pair(-1, -27), Pair(43, -37), Pair(40, -40), Pair(26, -8), Pair(41, -24),
      Pair(-41, -14), Pair(15, -15), Pair(-8, -30), Pair(23, -28), Pair(30, -31), Pair(14, -35), Pair(34, -16), Pair(24, -28),
      Pair(-60, -16), Pair(-20, -15), Pair(-21, -22), Pair(1, -16), Pair(16, -21), Pair(17, -27), Pair(17, -18), Pair(8, -29),
      Pair(-58, -5), Pair(19, -17), Pair(10, -24), Pair(22, -26), Pair(44, -28), Pair(46, -33), Pair(24, -22), Pair(-1, -21),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-104, -99), Pair(-84, -33), Pair(-236, 25), Pair(28, -47), Pair(-30, -13), Pair(-61, -21), Pair(-119, 38), Pair(-40, -83),
      Pair(-93, -28), Pair(-65, 2), Pair(-14, -5), Pair(163, -53), Pair(74, -16), Pair(41, -14), Pair(-25, 2), Pair(50, -31),
      Pair(-87, -1), Pair(-110, 8), Pair(45, -10), Pair(112, -24), Pair(100, -26), Pair(103, -51), Pair(-49, -9), Pair(-132, 21),
      Pair(-84, 11), Pair(11, 16), Pair(25, 4), Pair(140, -21), Pair(108, -13), Pair(95, -6), Pair(11, -18), Pair(-61, 14),
      Pair(-8, -10), Pair(78, -16), Pair(15, 5), Pair(139, -19), Pair(88, -12), Pair(157, -24), Pair(62, 2), Pair(68, -29),
      Pair(15, -16), Pair(47, -12), Pair(65, -10), Pair(84, 2), Pair(60, 3), Pair(39, -9), Pair(-87, 19), Pair(-123, 19),
      Pair(-168, 14), Pair(-11, -2), Pair(47, 6), Pair(-1, 5), Pair(44, -5), Pair(48, -9), Pair(-5, -8), Pair(-36, 14),
      Pair(-170, 19), Pair(-117, 23), Pair(60, -5), Pair(-25, 2), Pair(-94, 28), Pair(-49, 12), Pair(-64, 33), Pair(-35, 4)
    },
    {
      Pair(-124, 4), Pair(-50, -15), Pair(-25, -31), Pair(-19, -18), Pair(-74, -1), Pair(-30, -38), Pair(-16, -30), Pair(-2, -12),
      Pair(-47, -23), Pair(-14, -19), Pair(-133, -4), Pair(-23, -16), Pair(-26, -29), Pair(-53, -21), Pair(-52, -19), Pair(-131, -6),
      Pair(-6, -9), Pair(-23, -12), Pair(-28, -9), Pair(-84, -18), Pair(14, -28), Pair(7, -21), Pair(-50, -6), Pair(37, -35),
      Pair(-93, 5), Pair(-25, -4), Pair(49, -25), Pair(78, -42), Pair(12, -19), Pair(55, -22), Pair(62, -28), Pair(60, -27),
      Pair(57, -25), Pair(21, -27), Pair(4, -29), Pair(64, -34), Pair(-15, -26), Pair(-3, -27), Pair(-26, -11), Pair(6, -21),
      Pair(-7, -13), Pair(-43, -5), Pair(19, -24), Pair(17, -19), Pair(80, -24), Pair(52, -13), Pair(83, -26), Pair(-45, -5),
      Pair(-232, 23), Pair(-1, -23), Pair(8, -19), Pair(9, -23), Pair(3, -24), Pair(-30, -20), Pair(-4, -20), Pair(-46, -12),
      Pair(-244, 35), Pair(-185, 45), Pair(-46, -6), Pair(-95, -2), Pair(-41, -15), Pair(-50, -15), Pair(-18, -16), Pair(-166, 7)
    },
    {
      Pair(-99, -28), Pair(-162, 4), Pair(-138, -2), Pair(-120, -7), Pair(-130, -2), Pair(-4, -29), Pair(-47, -21), Pair(-99, -22),
      Pair(-116, -34), Pair(12, -52), Pair(-97, -26), Pair(-61, -33), Pair(-24, -40), Pair(-31, -39), Pair(18, -60), Pair(-39, -64),
      Pair(-63, -42), Pair(-69, -39), Pair(-5, -66), Pair(32, -65), Pair(73, -78), Pair(81, -76), Pair(-52, -47), Pair(-57, -56),
      Pair(-74, -40), Pair(92, -76), Pair(-88, -27), Pair(20, -76), Pair(22, -73), Pair(111, -100), Pair(156, -108), Pair(-48, -44),
      Pair(-109, -22), Pair(-94, -20), Pair(-109, -13), Pair(-20, -44), Pair(-61, -32), Pair(14, -52), Pair(-23, -41), Pair(-116, -21),
      Pair(-149, -23), Pair(-23, -60), Pair(-67, -45), Pair(-81, -43), Pair(-73, -37), Pair(-29, -43), Pair(-21, -62), Pair(-106, -46),
      Pair(-144, -50), Pair(-117, -54), Pair(-68, -47), Pair(-60, -63), Pair(-72, -52), Pair(-72, -48), Pair(-57, -47), Pair(-115, -52),
      Pair(-77, -51), Pair(-60, -47), Pair(-29, -55), Pair(-48, -46), Pair(-42, -53), Pair(-27, -64), Pair(-108, -29), Pair(-113, -38)
    },
    {
      Pair(103, -179), Pair(133, -192), Pair(173, -175), Pair(128, -140), Pair(6, -60), Pair(176, -162), Pair(169, -219), Pair(172, -185),
      Pair(68, -167), Pair(191, -170), Pair(222, -171), Pair(370, -254), Pair(396, -304), Pair(218, -184), Pair(155, -172), Pair(310, -279),
      Pair(133, -168), Pair(165, -190), Pair(110, -156), Pair(255, -190), Pair(287, -237), Pair(375, -294), Pair(318, -279), Pair(510, -423),
      Pair(173, -139), Pair(121, -76), Pair(45, -87), Pair(377, -270), Pair(279, -265), Pair(285, -218), Pair(232, -245), Pair(130, -85),
      Pair(-52, -60), Pair(139, -138), Pair(322, -209), Pair(99, -106), Pair(135, -128), Pair(245, -187), Pair(220, -165), Pair(64, -81),
      Pair(155, -207), Pair(86, -131), Pair(262, -207), Pair(126, -135), Pair(123, -147), Pair(200, -168), Pair(107, -166), Pair(70, -109),
      Pair(258, -263), Pair(108, -197), Pair(113, -176), Pair(-1, -85), Pair(93, -155), Pair(166, -200), Pair(113, -212), Pair(27, -189),
      Pair(133, -145), Pair(123, -192), Pair(134, -204), Pair(119, -154), Pair(106, -157), Pair(-40, -92), Pair(88, -69), Pair(101, -74)
    },
    {
      Pair(-39, -107), Pair(-53, -69), Pair(-130, -35), Pair(-161, -10), Pair(7, -61), Pair(-121, -38), Pair(-97, -43), Pair(-25, -123),
      Pair(-176, -31), Pair(-20, -41), Pair(-191, 0), Pair(-4, -28), Pair(-67, 0), Pair(-154, 15), Pair(-96, -18), Pair(-76, -38),
      Pair(-55, -35), Pair(12, -19), Pair(-124, 14), Pair(-147, 19), Pair(-168, 35), Pair(-82, 10), Pair(-74, 2), Pair(-83, -43),
      Pair(-38, -54), Pair(-98, -14), Pair(-128, 5), Pair(-194, 13), Pair(-194, 19), Pair(-171, 22), Pair(-54, -22), Pair(-158, -31),
      Pair(97, -55), Pair(53, -23), Pair(-36, 21), Pair(-21, 23), Pair(-59, 35), Pair(14, 6), Pair(4, -8), Pair(-33, -25),
      Pair(104, -52), Pair(157, -30), Pair(72, 1), Pair(29, 17), Pair(42, 12), Pair(64, 0), Pair(74, -18), Pair(56, -36),
      Pair(187, -52), Pair(202, -26), Pair(134, -1), Pair(139, -1), Pair(142, 5), Pair(130, 3), Pair(146, -13), Pair(149, -37),
      Pair(-24, -20), Pair(49, -10), Pair(211, -21), Pair(179, -4), Pair(158, 2), Pair(138, -5), Pair(-5, 5), Pair(-23, -32)
    }
  }},
  {{ // Bucket 5
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-73, 47), Pair(197, 5), Pair(254, 5), Pair(-86, 57), Pair(82, 52), Pair(-5, 73), Pair(-121, 90), Pair(38, 39),
      Pair(82, -6), Pair(70, 9), Pair(87, -1), Pair(12, 11), Pair(105, 9), Pair(87, 6), Pair(132, 8), Pair(103, 2),
      Pair(15, -20), Pair(28, -19), Pair(34, -31), Pair(-58, -20), Pair(-6, -21), Pair(68, -34), Pair(22, -27), Pair(36, -29),
      Pair(35, -32), Pair(29, -19), Pair(54, -40), Pair(33, -32), Pair(51, -38), Pair(99, -47), Pair(76, -39), Pair(64, -37),
      Pair(13, -30), Pair(2, -25), Pair(22, -34), Pair(15, -26), Pair(42, -32), Pair(71, -31), Pair(34, -29), Pair(50, -36),
      Pair(-1, -13), Pair(14, -14), Pair(67, -32), Pair(-60, -21), Pair(111, -47), Pair(101, -32), Pair(96, -34), Pair(-6, -20),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-117, -111), Pair(-309, -32), Pair(-318, -32), Pair(-57, -55), Pair(-52, -62), Pair(-271, -46), Pair(-3, -124), Pair(91, -134),
      Pair(-26, -56), Pair(6, -69), Pair(-62, -49), Pair(-39, -53), Pair(15, -71), Pair(-35, -71), Pair(-20, -47), Pair(-106, -49),
      Pair(-199, -41), Pair(-51, -60), Pair(54, -64), Pair(124, -64), Pair(163, -79), Pair(75, -76), Pair(-40, -78), Pair(-128, -30),
      Pair(57, -87), Pair(26, -52), Pair(146, -78), Pair(137, -75), Pair(232, -98), Pair(47, -51), Pair(-41, -67), Pair(178, -98),
      Pair(-76, -38), Pair(-33, -35), Pair(9, -35), Pair(105, -47), Pair(100, -52), Pair(95, -55), Pair(90, -59), Pair(186, -84),
      Pair(-159, -62), Pair(50, -49), Pair(159, -74), Pair(211, -67), Pair(177, -54), Pair(118, -61), Pair(154, -72), Pair(15, -57),
      Pair(-32, -97), Pair(-106, -36), Pair(2, -60), Pair(36, -42), Pair(99, -66), Pair(133, -74), Pair(-73, -17), Pair(31, -66),
      Pair(242, -91), Pair(-85, -40), Pair(147, -68), Pair(280, -95), Pair(120, -82), Pair(12, -50), Pair(12, -60), Pair(-128, -28)
    },
    {
      Pair(103, -64), Pair(-45, -31), Pair(61, -70), Pair(-130, -45), Pair(-27, -39), Pair(-275, -18), Pair(-28, -44), Pair(-24, -74),
      Pair(-167, -38), Pair(-27, -49), Pair(-43, -27), Pair(-31, -32), Pair(-36, -40), Pair(-9, -48), Pair(-58, -45), Pair(-67, -14),
      Pair(-178, -29), Pair(16, -46), Pair(-35, -30), Pair(-118, -28), Pair(-79, -23), Pair(-103, -28), Pair(-97, -17), Pair(-43, -43),
      Pair(-22, -58), Pair(-64, -31), Pair(-112, -21), Pair(-47, -32), Pair(-10, -47), Pair(-137, 6), Pair(-184, -10), Pair(-143, -18),
      Pair(-64, -29), Pair(-49, -45), Pair(-6, -44), Pair(-44, -39), Pair(12, -46), Pair(-13, -30), Pair(-50, -35), Pair(19, -43),
      Pair(-62, -35), Pair(-26, -41), Pair(-114, -32), Pair(-56, -41), Pair(57, -76), Pair(-3, -49), Pair(1, -64), Pair(-11, -60),
      Pair(-173, 10), Pair(-11, -76), Pair(-20, -50), Pair(-16, -60), Pair(16, -62), Pair(-10, -63), Pair(-33, -39), Pair(-91, -52),
      Pair(-366, -21), Pair(-457, 70), Pair(-105, -35), Pair(-58, -28), Pair(-45, -51), Pair(-60, -31), Pair(-280, 4), Pair(-406, -6)
    },
    {
      Pair(3, -131), Pair(-129, -90), Pair(-135, -74), Pair(-136, -68), Pair(-125, -83), Pair(59, -116), Pair(-15, -97), Pair(-11, -117),
      Pair(-100, -109), Pair(-6, -120), Pair(12, -111), Pair(-129, -84), Pair(-13, -123), Pair(-90, -90), Pair(21, -120), Pair(-96, -100),
      Pair(-111, -102), Pair(66, -138), Pair(-34, -123), Pair(-93, -107), Pair(-80, -105), Pair(-13, -123), Pair(-76, -104), Pair(-31, -126),
      Pair(-70, -100), Pair(95, -140), Pair(-100, -97), Pair(-61, -105), Pair(-74, -113), Pair(81, -145), Pair(-40, -105), Pair(-57, -111),
      Pair(18, -132), Pair(5, -129), Pair(155, -176), Pair(61, -163), Pair(59, -146), Pair(-13, -106), Pair(-72, -126), Pair(-137, -99),
      Pair(-78, -115), Pair(125, -145), Pair(-106, -101), Pair(-52, -110), Pair(-60, -122), Pair(-62, -116), Pair(10, -122), Pair(-27, -126),
      Pair(-85, -118), Pair(-101, -106), Pair(-65, -118), Pair(-33, -123), Pair(50, -159), Pair(64, -155), Pair(-22, -138), Pair(38, -158),
      Pair(-24, -134), Pair(-14, -133), Pair(-21, -134), Pair(17, -144), Pair(87, -162), Pair(29, -146), Pair(25, -144), Pair(-105, -111)
    },
    {
      Pair(46, -321), Pair(-194, -165), Pair(-42, -225), Pair(141, -287), Pair(91, -278), Pair(-278, -104), Pair(-210, -155), Pair(-256, -137),
      Pair(192, -364), Pair(41, -282), Pair(13, -256), Pair(7, -199), Pair(70, -252), Pair(44, -223), Pair(107, -315), Pair(189, -332),
      Pair(47, -254), Pair(184, -344), Pair(-96, -163), Pair(205, -329), Pair(-54, -165), Pair(207, -363), Pair(137, -317), Pair(64, -253),
      Pair(85, -285), Pair(152, -303), Pair(135, -286), Pair(192, -306), Pair(392, -424), Pair(115, -301), Pair(-124, -193), Pair(282, -376),
      Pair(231, -414), Pair(5, -211), Pair(62, -258), Pair(-433, 89), Pair(155, -306), Pair(-65, -143), Pair(143, -296), Pair(-22, -198),
      Pair(-44, -206), Pair(-23, -165), Pair(164, -289), Pair(147, -305), Pair(78, -190), Pair(266, -376), Pair(-31, -188), Pair(185, -299),
      Pair(79, -331), Pair(215, -334), Pair(-18, -214), Pair(172, -328), Pair(124, -278), Pair(-42, -270), Pair(219, -346), Pair(65, -309),
      Pair(-50, -243), Pair(123, -360), Pair(276, -454), Pair(285, -403), Pair(135, -309), Pair(139, -341), Pair(-88, -187), Pair(-10, -308)
    },
    {
      Pair(93, -98), Pair(3, -39), Pair(9, -53), Pair(-17, -20), Pair(31, -48), Pair(21, -41), Pair(112, -69), Pair(125, -120),
      Pair(-80, -38), Pair(-89, -7), Pair(-71, -8), Pair(77, -35), Pair(-1, -23), Pair(8, -2), Pair(5, 1), Pair(-32, -7),
      Pair(-82, -1), Pair(83, -7), Pair(20, 4), Pair(-45, 15), Pair(54, 14), Pair(43, 2), Pair(14, 6), Pair(27, -29),
      Pair(72, -47), Pair(20, -10), Pair(-36, 10), Pair(-85, 33), Pair(-62, 22), Pair(27, 18), Pair(17, -1), Pair(-55, -16),
      Pair(206, -56), Pair(273, -26), Pair(111, 18), Pair(119, 26), Pair(132, 25), Pair(181, 8), Pair(122, 1), Pair(96, -16),
      Pair(280, -64), Pair(231, -24), Pair(162, 8), Pair(198, 17), Pair(255, 10), Pair(194, 13), Pair(186, -7), Pair(125, -20),
      Pair(237, -26), Pair(280, -10), Pair(242, 12), Pair(229, 8), Pair(232, 17), Pair(225, 15), Pair(250, 2), Pair(227, -22),
      Pair(-258, 9), Pair(-118, 14), Pair(310, -7), Pair(304, -3), Pair(227, 8), Pair(222, 5), Pair(-137, 3), Pair(-211, -15)
    }
  }},
  {{ // Bucket 6
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-115, 62), Pair(-90, 45), Pair(164, 29), Pair(430, -7), Pair(2, 66), Pair(96, 37), Pair(-49, 30), Pair(-182, 63),
      Pair(12, 24), Pair(59, 13), Pair(168, 9), Pair(172, -41), Pair(134, 1), Pair(138, -17), Pair(-17, 42), Pair(186, -13),
      Pair(46, -5), Pair(124, -21), Pair(72, -8), Pair(-60, 9), Pair(-34, -18), Pair(159, -35), Pair(64, -16), Pair(82, -21),
      Pair(6, -19), Pair(78, -29), Pair(29, -23), Pair(-33, -19), Pair(-29, -33), Pair(142, -52), Pair(59, -28), Pair(53, -31),
      Pair(48, -42), Pair(43, -65), Pair(118, -65), Pair(-74, -41), Pair(-36, -30), Pair(91, -65), Pair(74, -48), Pair(94, -54),
      Pair(25, -30), Pair(84, -33), Pair(182, -54), Pair(95, -16), Pair(-174, -5), Pair(145, -43), Pair(129, -44), Pair(56, -37),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(103, -242), Pair(-264, -138), Pair(-71, -103), Pair(-212, -101), Pair(-43, -130), Pair(-246, -61), Pair(-54, -93), Pair(-2, -111),
      Pair(-55, -72), Pair(-67, -34), Pair(6, -110), Pair(24, -86), Pair(196, -172), Pair(-165, -66), Pair(-226, -78), Pair(-89, -131),
      Pair(105, -109), Pair(-104, -107), Pair(48, -108), Pair(-189, -66), Pair(-106, -95), Pair(-146, -28), Pair(169, -64), Pair(26, -97),
      Pair(20, -114), Pair(90, -67), Pair(136, -109), Pair(168, -113), Pair(226, -120), Pair(259, -139), Pair(60, -128), Pair(-222, -23),
      Pair(160, -164), Pair(115, -119), Pair(190, -52), Pair(245, -106), Pair(121, -123), Pair(-10, -74), Pair(40, -106), Pair(35, -45),
      Pair(-210, -70), Pair(151, -115), Pair(38, -73), Pair(432, -153), Pair(30, -49), Pair(58, -70), Pair(43, -89), Pair(283, -49),
      Pair(-104, -100), Pair(93, -106), Pair(38, -58), Pair(-88, -74), Pair(162, -118), Pair(-14, -105), Pair(-217, -70), Pair(-93, -95),
      Pair(67, -119), Pair(73, -94), Pair(80, -115), Pair(-39, -95), Pair(38, -124), Pair(-3, -115), Pair(52, -110), Pair(25, -30)
    },
    {
      Pair(-20, -57), Pair(51, -28), Pair(-208, -61), Pair(-80, -58), Pair(174, -51), Pair(-36, -102), Pair(145, -73), Pair(-167, -36),
      Pair(79, -74), Pair(-93, -66), Pair(-52, -65), Pair(-16, -93), Pair(116, -95), Pair(79, -115), Pair(27, -73), Pair(90, -96),
      Pair(-80, -61), Pair(14, -99), Pair(-32, -82), Pair(-46, -66), Pair(65, -91), Pair(-29, -68), Pair(-52, -59), Pair(-19, -55),
      Pair(40, -70), Pair(12, -99), Pair(-69, -66), Pair(-66, -33), Pair(-71, -74), Pair(-253, -22), Pair(41, -83), Pair(-137, -42),
      Pair(-187, -74), Pair(-109, -50), Pair(127, -106), Pair(28, -85), Pair(104, -83), Pair(-24, -41), Pair(-235, -36), Pair(-112, -18),
      Pair(-169, -13), Pair(183, -94), Pair(-132, -73), Pair(70, -58), Pair(-124, -54), Pair(-172, -42), Pair(-62, -46), Pair(-79, -47),
      Pair(-235, -12), Pair(-206, -41), Pair(-44, -78), Pair(-23, -88), Pair(-136, -56), Pair(-116, -83), Pair(47, -172), Pair(-34, -85),
      Pair(-84, -82), Pair(-153, -21), Pair(-223, -97), Pair(-94, -95), Pair(-230, -45), Pair(-5, -101), Pair(-240, -52), Pair(-72, -156)
    },
    {
      Pair(39, -169), Pair(138, -179), Pair(-106, -136), Pair(177, -169), Pair(171, -208), Pair(96, -167), Pair(-144, -76), Pair(98, -175),
      Pair(141, -186), Pair(46, -171), Pair(131, -183), Pair(-167, -132), Pair(-29, -154), Pair(-145, -131), Pair(-185, -75), Pair(-143, -134),
      Pair(-84, -138), Pair(-17, -145), Pair(68, -181), Pair(18, -161), Pair(-56, -125), Pair(-98, -138), Pair(-19, -140), Pair(157, -208),
      Pair(250, -208), Pair(133, -163), Pair(52, -164), Pair(105, -187), Pair(87, -189), Pair(127, -191), Pair(-46, -121), Pair(183, -194),
      Pair(47, -178), Pair(173, -196), Pair(21, -156), Pair(159, -199), Pair(78, -191), Pair(43, -152), Pair(84, -186), Pair(76, -179),
      Pair(-87, -130), Pair(-1, -131), Pair(117, -204), Pair(212, -230), Pair(207, -203), Pair(217, -220), Pair(-97, -134), Pair(-73, -128),
      Pair(89, -151), Pair(64, -152), Pair(232, -206), Pair(317, -267), Pair(240, -234), Pair(105, -164), Pair(152, -186), Pair(278, -239),
      Pair(1, -150), Pair(56, -194), Pair(82, -194), Pair(24, -192), Pair(41, -208), Pair(338, -272), Pair(92, -192), Pair(141, -194)
    },
    {
      Pair(-324, -169), Pair(96, -376), Pair(-117, -272), Pair(-66, -302), Pair(-381, -84), Pair(-181, -245), Pair(-321, -230), Pair(-18, -382),
      Pair(21, -345), Pair(-13, -289), Pair(-70, -218), Pair(-133, -263), Pair(-32, -255), Pair(-240, -169), Pair(-131, -232), Pair(-106, -281),
      Pair(78, -331), Pair(-177, -239), Pair(-120, -204), Pair(38, -325), Pair(-39, -276), Pair(-59, -320), Pair(-235, -216), Pair(18, -308),
      Pair(-63, -244), Pair(-133, -246), Pair(256, -391), Pair(133, -365), Pair(119, -332), Pair(9, -284), Pair(28, -278), Pair(-112, -217),
      Pair(107, -370), Pair(214, -401), Pair(44, -310), Pair(-171, -166), Pair(160, -317), Pair(-133, -194), Pair(-69, -247), Pair(-108, -216),
      Pair(40, -415), Pair(342, -503), Pair(208, -351), Pair(245, -410), Pair(53, -295), Pair(-39, -280), Pair(-50, -302), Pair(13, -249),
      Pair(58, -374), Pair(-126, -272), Pair(28, -286), Pair(144, -344), Pair(36, -243), Pair(-184, -216), Pair(-16, -274), Pair(-42, -240),
      Pair(-39, -311), Pair(-155, -304), Pair(130, -312), Pair(67, -349), Pair(-61, -292), Pair(-73, -341), Pair(217, -403), Pair(-111, -325)
    },
    {
      Pair(-39, -49), Pair(20, -36), Pair(121, -19), Pair(-53, 26), Pair(-11, 57), Pair(28, 3), Pair(43, -28), Pair(32, -120),
      Pair(22, -14), Pair(-51, 41), Pair(65, -13), Pair(-13, 43), Pair(-62, 19), Pair(27, 28), Pair(-12, 12), Pair(-118, 55),
      Pair(-74, 29), Pair(56, 12), Pair(53, 26), Pair(20, 42), Pair(-9, 59), Pair(-96, 43), Pair(-29, 41), Pair(108, 8),
      Pair(-45, -2), Pair(47, 36), Pair(-10, 23), Pair(-68, 52), Pair(-6, 32), Pair(-30, 31), Pair(-71, 34), Pair(23, 10),
      Pair(113, -11), Pair(225, 16), Pair(218, 37), Pair(224, 38), Pair(63, 54), Pair(73, 62), Pair(139, 32), Pair(24, 45),
      Pair(256, -5), Pair(215, 14), Pair(136, 39), Pair(185, 51), Pair(217, 56), Pair(169, 46), Pair(166, 28), Pair(128, 8),
      Pair(245, 2), Pair(242, 38), Pair(265, 35), Pair(348, 8), Pair(268, 39), Pair(162, 49), Pair(192, 47), Pair(249, 4),
      Pair(-51, -7), Pair(-102, 10), Pair(368, 47), Pair(332, 46), Pair(269, 44), Pair(211, 51), Pair(-99, 11), Pair(-98, -31)
    }
  }}
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(25, 347), Pair(38, 339), Pair(47, 360), Pair(53, 370), Pair(57, 377), Pair(61, 385), Pair(67, 386), Pair(70, 385),
  Pair(71, 377)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-76, 7), Pair(-67, -7), Pair(-56, 12), Pair(-51, 24), Pair(-44, 34), Pair(-42, 44), Pair(-40, 49), Pair(-38, 52),
  Pair(-37, 57), Pair(-32, 56), Pair(-23, 54), Pair(-18, 57), Pair(-24, 74), Pair(-21, 55)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-32, -52), Pair(-22, -24), Pair(-18, -15), Pair(-17, -2), Pair(-17, 3), Pair(-12, 6), Pair(-9, 10), Pair(-6, 13),
  Pair(-1, 16), Pair(1, 20), Pair(4, 23), Pair(6, 28), Pair(10, 30), Pair(14, 29), Pair(13, 27)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(24, -22), Pair(70, -111), Pair(63, 105), Pair(71, 152), Pair(71, 192), Pair(73, 211), Pair(76, 225), Pair(78, 239),
  Pair(80, 247), Pair(83, 249), Pair(85, 255), Pair(86, 263), Pair(90, 260), Pair(89, 265), Pair(92, 265), Pair(95, 263),
  Pair(95, 267), Pair(97, 267), Pair(104, 258), Pair(117, 246), Pair(124, 238), Pair(163, 213), Pair(157, 209), Pair(172, 187),
  Pair(213, 173), Pair(300, 106), Pair(283, 113), Pair(231, 115)
};

constexpr KingBuckets<RankTable<ScorePair>> kPassedPawnBonus = {{
  {
      Pair(0, 0), Pair(20, -116), Pair(25, -107), Pair(26, -71), Pair(48, -27), Pair(50, 8), Pair(61, 130), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(32, -122), Pair(32, -115), Pair(29, -81), Pair(44, -35), Pair(46, 30), Pair(108, 106), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(14, -110), Pair(11, -94), Pair(14, -61), Pair(41, -24), Pair(56, 43), Pair(91, 85), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-10, -100), Pair(-12, -78), Pair(-7, -42), Pair(34, -6), Pair(33, 77), Pair(119, 86), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-36, -81), Pair(-57, -54), Pair(-64, -20), Pair(-42, 22), Pair(-81, 133), Pair(87, 107), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-59, -74), Pair(-93, -59), Pair(-141, -4), Pair(-176, 70), Pair(-258, 149), Pair(122, 89), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-83, -75), Pair(-92, -48), Pair(-107, -11), Pair(-157, 52), Pair(-167, 113), Pair(66, 92), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPawnPhalanxBonus = {{
  {
      Pair(0, 0), Pair(8, -3), Pair(14, 0), Pair(18, 13), Pair(48, 53), Pair(142, 148), Pair(198, 602), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 1), Pair(19, 5), Pair(24, 10), Pair(57, 52), Pair(377, 153), Pair(133, 431), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 2), Pair(12, 10), Pair(30, 15), Pair(41, 71), Pair(-58, 380), Pair(-222, 560), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 5), Pair(-5, 16), Pair(25, 22), Pair(-6, 77), Pair(-92, 250), Pair(-114, 495), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-20, 19), Pair(4, 16), Pair(-24, 22), Pair(-68, 93), Pair(55, 228), Pair(-42, 458), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 6), Pair(-21, 5), Pair(-69, 38), Pair(-128, 103), Pair(-249, 265), Pair(-422, 395), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-22, -13), Pair(-36, 15), Pair(3, 14), Pair(-259, 103), Pair(-151, 129), Pair(-199, 251), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kDefendedPawnBonus = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(21, 14), Pair(13, 13), Pair(13, 16), Pair(19, 62), Pair(184, 18), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(23, 9), Pair(14, 7), Pair(11, 14), Pair(28, 55), Pair(322, 34), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(20, 12), Pair(12, 9), Pair(11, 18), Pair(20, 54), Pair(99, 45), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(13, 13), Pair(5, 8), Pair(3, 19), Pair(20, 45), Pair(138, 52), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(13, 13), Pair(-16, 12), Pair(-8, 22), Pair(27, 43), Pair(-48, 159), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-10, 10), Pair(-27, 10), Pair(-43, 22), Pair(82, 7), Pair(-303, 165), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-41, 21), Pair(29, -2), Pair(-43, 5), Pair(68, 45), Pair(-261, 182), Pair(0, 0)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kDoubledPawnPenalty = {{
  {
      Pair(-12, -58), Pair(12, -54), Pair(-2, -29), Pair(-3, -13), Pair(-12, -8), Pair(-12, -15), Pair(15, -41), Pair(-2, -57)
  },
  {
      Pair(-3, -45), Pair(12, -40), Pair(7, -27), Pair(3, -26), Pair(-1, -4), Pair(-5, -21), Pair(-1, -26), Pair(-12, -36)
  },
  {
      Pair(-11, -45), Pair(15, -39), Pair(9, -29), Pair(12, -17), Pair(-2, -7), Pair(2, -22), Pair(10, -28), Pair(-13, -51)
  },
  {
      Pair(-13, -38), Pair(18, -31), Pair(8, -32), Pair(34, -16), Pair(39, -11), Pair(-6, -18), Pair(20, -25), Pair(-40, -27)
  },
  {
      Pair(-41, -40), Pair(-24, -21), Pair(36, -26), Pair(-37, -7), Pair(69, -24), Pair(26, -20), Pair(-9, -24), Pair(-40, -39)
  },
  {
      Pair(-64, -34), Pair(-51, -11), Pair(-3, -35), Pair(25, -38), Pair(-170, 17), Pair(5, -33), Pair(7, -13), Pair(-43, -32)
  },
  {
      Pair(-371, 57), Pair(-203, 29), Pair(-129, -4), Pair(-146, -6), Pair(30, -40), Pair(-296, -4), Pair(-111, 13), Pair(-65, -38)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kIsolatedPawnPenalty = {{
  {
      Pair(-7, 21), Pair(0, -15), Pair(-11, -6), Pair(-10, -10), Pair(-16, -9), Pair(-9, -3), Pair(2, -14), Pair(-8, 14)
  },
  {
      Pair(2, 10), Pair(0, -9), Pair(-13, -6), Pair(-10, -18), Pair(-11, -19), Pair(4, -12), Pair(-1, -16), Pair(-7, 7)
  },
  {
      Pair(-4, 13), Pair(-3, -13), Pair(-14, -4), Pair(-2, -14), Pair(-7, -19), Pair(-2, -9), Pair(-3, -11), Pair(-3, 2)
  },
  {
      Pair(-4, 3), Pair(-4, -9), Pair(-19, -3), Pair(12, -22), Pair(-6, -22), Pair(5, -10), Pair(-10, -11), Pair(-18, 4)
  },
  {
      Pair(20, -4), Pair(-32, -7), Pair(-9, -6), Pair(13, -22), Pair(0, -21), Pair(4, -9), Pair(3, -11), Pair(-24, 6)
  },
  {
      Pair(5, -4), Pair(17, -14), Pair(-13, -2), Pair(56, -20), Pair(22, -16), Pair(7, -10), Pair(17, -12), Pair(0, -4)
  },
  {
      Pair(81, -30), Pair(103, -29), Pair(-15, 4), Pair(40, -16), Pair(99, -19), Pair(97, -10), Pair(69, -28), Pair(39, -18)
  }
}};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(21, 5), Pair(19, 2), Pair(18, 8), Pair(20, 7), Pair(21, 11), Pair(30, 4), Pair(45, -1), Pair(75, -7)
  },
  {
      Pair(9, 34), Pair(9, 9), Pair(12, 8), Pair(19, 0), Pair(15, -1), Pair(17, -4), Pair(25, -4), Pair(26, 14)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(14, -4), Pair(19, -5), Pair(10, -1),
  Pair(23, -11), Pair(20, -12), Pair(22, -11),
  Pair(32, -3), Pair(0, 0), Pair(29, -2),
  Pair(-7, 6), Pair(2, -5), Pair(-9, 8)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 2), Pair(-15, 5), Pair(-9, 4),
  Pair(-7, 1), Pair(-17, 7), Pair(-9, 3),
  Pair(-2, -5), Pair(-16, 4), Pair(-2, -3),
  Pair(12, -7), Pair(-4, -3), Pair(10, -4),
  Pair(21, -12), Pair(21, 0), Pair(15, -12),
  Pair(0, 0), Pair(-7, -15), Pair(0, 0),
  Pair(42, -40), Pair(0, 0), Pair(31, -37)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-18, 114), Pair(-21, 99), Pair(-15, 80), Pair(-13, 69), Pair(-12, 67), Pair(-4, 66), Pair(-10, 63)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-36, -47), Pair(-14, -27), Pair(-14, 2), Pair(-12, 17), Pair(-13, 27), Pair(-13, 33), Pair(-19, 24)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-2514, 193);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-70, -10), Pair(-81, -4), Pair(-30, -11), Pair(-31, -6), Pair(-18, -5), Pair(-31, -3), Pair(-52, -1), Pair(-35, 3)
  },
  {
      Pair(-5, 43), Pair(-38, 19), Pair(-13, 10), Pair(2, 0), Pair(-1, -5), Pair(-2, 2), Pair(-27, 19), Pair(-16, 29)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 2), Pair(25, -7), Pair(52, -21), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(14, 1), Pair(28, -1), Pair(63, -7), Pair(71, -38), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(20, -21), Pair(36, -20), Pair(53, -14), Pair(79, -14), Pair(94, -24), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 12), Pair(10, 25), Pair(30, 30), Pair(73, 17), Pair(110, 11), Pair(171, -12), Pair(222, -53)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(48, 10), Pair(20, 23), Pair(59, 1), Pair(26, 14), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-19, 13), Pair(-12, 18)
  },
  {
      Pair(-68, -24), Pair(-68, -31)
  },
  {
      Pair(-60, -49), Pair(-68, -76)
  },
  {
      Pair(-97, 3), Pair(-86, -34)
  },
  {
      Pair(-79, 35), Pair(-86, 15)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(17, 33), Pair(21, 21), Pair(29, 10), Pair(23, -4), Pair(57, -2)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-2, -20), Pair(9, -12)
  },
  {
      Pair(-23, -45), Pair(-3, -60)
  },
  {
      Pair(-43, -35), Pair(-30, -34)
  },
  {
      Pair(-85, -3), Pair(-64, -28)
  },
  {
      Pair(-60, 35), Pair(-61, 21)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-11, -21), Pair(0, -10)
  },
  {
      Pair(-51, -24), Pair(-22, -27)
  },
  {
      Pair(21, -140), Pair(32, -133)
  },
  {
      Pair(-84, -8), Pair(-49, -40)
  },
  {
      Pair(-88, -17), Pair(-63, -92)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-2, -25), Pair(11, -11)
  },
  {
      Pair(-41, -28), Pair(-3, -15)
  },
  {
      Pair(-30, -29), Pair(-14, -4)
  },
  {
      Pair(-2, -58), Pair(13, -34)
  },
  {
      Pair(-88, 9), Pair(-64, -45)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(24, 19), Pair(19, 11), Pair(42, 22), Pair(49, 23), Pair(50, 29), Pair(27, 47), Pair(38, 14), Pair(3, 44),
  Pair(4, 14), Pair(14, 17), Pair(18, 22), Pair(10, 36), Pair(14, 25), Pair(12, 21), Pair(13, 18), Pair(-6, 29),
  Pair(10, 12), Pair(5, 4), Pair(1, 18), Pair(9, 19), Pair(7, 22), Pair(-7, 22), Pair(2, 8), Pair(1, 10)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-10, 13), Pair(24, -2), Pair(32, 2), Pair(46, 5), Pair(73, -12), Pair(54, 0), Pair(26, -8), Pair(-16, -19),
  Pair(-21, -16), Pair(20, 7), Pair(11, 3), Pair(25, 13), Pair(15, 6), Pair(18, -4), Pair(13, 9), Pair(17, -20),
  Pair(-21, 29), Pair(11, 4), Pair(3, 21), Pair(19, 16), Pair(25, 23), Pair(3, 9), Pair(15, 0), Pair(-48, 5)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 61);

constexpr ScorePair kTempoBonus = Pair(32, 29);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H