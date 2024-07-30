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
  Pair(71, 132), Pair(323, 327), Pair(351, 375), Pair(456, 678), Pair(910, 1177), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    { // Piece 0
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-16, 45), Pair(-47, 66), Pair(-27, 6), Pair(-8, -21), Pair(23, -49), Pair(18, -31), Pair(-46, -18), Pair(-75, 41),
      Pair(6, 35), Pair(-6, 38), Pair(34, -15), Pair(47, -58), Pair(61, -58), Pair(91, -49), Pair(56, 1), Pair(33, 9),
      Pair(-15, 9), Pair(-9, 6), Pair(-2, -20), Pair(-1, -36), Pair(23, -45), Pair(22, -41), Pair(4, -11), Pair(7, -23),
      Pair(-20, -13), Pair(-21, 2), Pair(-7, -25), Pair(3, -30), Pair(8, -36), Pair(15, -40), Pair(-3, -18), Pair(6, -35),
      Pair(-31, -13), Pair(-31, -1), Pair(-19, -20), Pair(-12, -19), Pair(-4, -17), Pair(-10, -25), Pair(-5, -21), Pair(2, -42),
      Pair(-20, -10), Pair(-20, 3), Pair(-12, -13), Pair(-6, -25), Pair(1, -2), Pair(8, -18), Pair(7, -14), Pair(-6, -42),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    { // Piece 1
      Pair(-128, -21), Pair(-120, 37), Pair(-68, 18), Pair(-40, 0), Pair(-37, 6), Pair(-24, -53), Pair(-92, -19), Pair(-79, -79),
      Pair(-23, 15), Pair(-16, 36), Pair(-5, 21), Pair(-4, 25), Pair(5, -2), Pair(46, -7), Pair(28, -17), Pair(-5, -31),
      Pair(-8, 25), Pair(5, 25), Pair(3, 42), Pair(17, 22), Pair(30, 9), Pair(72, -20), Pair(5, 11), Pair(26, -27),
      Pair(8, 29), Pair(15, 32), Pair(32, 31), Pair(35, 42), Pair(32, 35), Pair(43, 32), Pair(24, 32), Pair(33, 3),
      Pair(-12, 25), Pair(14, 24), Pair(23, 39), Pair(29, 34), Pair(28, 40), Pair(41, 15), Pair(28, 23), Pair(5, 21),
      Pair(-26, 13), Pair(-5, 20), Pair(4, 26), Pair(16, 39), Pair(29, 33), Pair(16, 20), Pair(15, 16), Pair(-3, 17),
      Pair(-36, 10), Pair(-22, 19), Pair(-10, 15), Pair(6, 18), Pair(6, 22), Pair(2, 6), Pair(2, 11), Pair(-4, 26),
      Pair(-56, -10), Pair(-22, 7), Pair(-21, 10), Pair(-4, 11), Pair(1, 17), Pair(5, 4), Pair(-18, 5), Pair(-26, -7)
    },
    { // Piece 2
      Pair(-25, 38), Pair(-64, 25), Pair(-53, 14), Pair(-105, 32), Pair(-82, 13), Pair(-47, -14), Pair(-76, 50), Pair(-29, -7),
      Pair(-23, 14), Pair(-14, 22), Pair(-6, 5), Pair(-24, 19), Pair(-20, 0), Pair(-17, 7), Pair(-51, 25), Pair(-42, -3),
      Pair(-4, 23), Pair(-1, 26), Pair(-9, 20), Pair(-10, 9), Pair(-19, 17), Pair(23, 23), Pair(14, 18), Pair(0, 30),
      Pair(-21, 22), Pair(-7, 28), Pair(-2, 21), Pair(1, 36), Pair(4, 15), Pair(8, 19), Pair(-6, 21), Pair(-15, 17),
      Pair(-15, 19), Pair(-21, 20), Pair(-10, 24), Pair(3, 11), Pair(1, 9), Pair(-2, 7), Pair(-14, 17), Pair(2, -6),
      Pair(-15, 4), Pair(5, 23), Pair(2, 19), Pair(-2, 23), Pair(2, 31), Pair(7, 19), Pair(14, 4), Pair(10, 9),
      Pair(2, 3), Pair(2, -7), Pair(10, -4), Pair(-6, 12), Pair(6, 12), Pair(15, 19), Pair(29, 8), Pair(18, -7),
      Pair(1, -12), Pair(21, -5), Pair(-1, 6), Pair(-4, 5), Pair(11, 0), Pair(15, 12), Pair(20, -2), Pair(35, -44)
    },
    { // Piece 3
      Pair(18, 17), Pair(17, 30), Pair(6, 41), Pair(-2, 34), Pair(32, 14), Pair(24, 23), Pair(41, 27), Pair(-5, 19),
      Pair(5, 21), Pair(13, 30), Pair(20, 35), Pair(29, 23), Pair(12, 17), Pair(33, 14), Pair(67, 2), Pair(41, 0),
      Pair(1, 20), Pair(39, 17), Pair(26, 22), Pair(27, 9), Pair(52, -4), Pair(73, -16), Pair(119, -37), Pair(53, -22),
      Pair(14, 13), Pair(23, 21), Pair(33, 18), Pair(28, 10), Pair(38, -3), Pair(40, 0), Pair(53, -9), Pair(29, -17),
      Pair(-3, 7), Pair(-1, 26), Pair(8, 14), Pair(11, 15), Pair(12, 7), Pair(-3, 13), Pair(34, -9), Pair(13, -14),
      Pair(-13, 10), Pair(-4, 12), Pair(1, 16), Pair(0, 16), Pair(12, 3), Pair(10, 0), Pair(46, -29), Pair(26, -39),
      Pair(-12, 1), Pair(-8, 15), Pair(9, 7), Pair(8, 13), Pair(15, -2), Pair(13, -5), Pair(36, -22), Pair(6, -36),
      Pair(-2, 12), Pair(6, 4), Pair(9, 9), Pair(15, 3), Pair(20, -5), Pair(16, 3), Pair(16, -6), Pair(-20, 3)
    },
    { // Piece 4
      Pair(11, 28), Pair(14, 28), Pair(27, 28), Pair(66, -1), Pair(44, 16), Pair(51, 27), Pair(104, -41), Pair(40, 30),
      Pair(27, 26), Pair(23, 30), Pair(24, 57), Pair(19, 50), Pair(-9, 97), Pair(25, 74), Pair(28, 51), Pair(76, 27),
      Pair(31, 31), Pair(32, 37), Pair(31, 56), Pair(27, 66), Pair(28, 67), Pair(50, 77), Pair(57, 54), Pair(45, 42),
      Pair(25, 41), Pair(37, 39), Pair(37, 42), Pair(29, 58), Pair(32, 73), Pair(52, 31), Pair(47, 57), Pair(53, 28),
      Pair(22, 37), Pair(20, 56), Pair(25, 52), Pair(25, 67), Pair(37, 49), Pair(25, 52), Pair(45, 32), Pair(42, 33),
      Pair(26, 21), Pair(27, 40), Pair(24, 56), Pair(22, 54), Pair(24, 58), Pair(34, 40), Pair(52, 21), Pair(48, -11),
      Pair(27, 11), Pair(29, 20), Pair(31, 27), Pair(32, 40), Pair(37, 28), Pair(45, -3), Pair(50, -12), Pair(57, -57),
      Pair(21, 30), Pair(22, 25), Pair(27, 20), Pair(29, 25), Pair(35, 5), Pair(29, -9), Pair(32, -41), Pair(12, 15)
    },
    { // Piece 5
      Pair(120, -126), Pair(177, -93), Pair(155, -70), Pair(91, -42), Pair(91, -48), Pair(56, -35), Pair(114, -52), Pair(90, -130),
      Pair(89, -67), Pair(170, -38), Pair(127, -27), Pair(180, -32), Pair(143, -25), Pair(115, -6), Pair(151, -19), Pair(96, -44),
      Pair(123, -24), Pair(217, -4), Pair(161, 13), Pair(137, 24), Pair(156, 27), Pair(197, 16), Pair(159, 16), Pair(143, -22),
      Pair(163, -45), Pair(199, -20), Pair(159, 0), Pair(108, 16), Pair(113, 13), Pair(139, 7), Pair(153, -11), Pair(57, -21),
      Pair(136, -54), Pair(166, -29), Pair(106, -1), Pair(69, 16), Pair(76, 10), Pair(107, -6), Pair(106, -20), Pair(43, -33),
      Pair(64, -38), Pair(101, -17), Pair(37, 9), Pair(29, 21), Pair(30, 18), Pair(34, 6), Pair(65, -15), Pair(35, -31),
      Pair(39, -29), Pair(2, 10), Pair(-9, 23), Pair(-28, 34), Pair(-33, 35), Pair(-14, 22), Pair(2, 4), Pair(17, -24),
      Pair(-50, -20), Pair(-26, 9), Pair(6, 23), Pair(-46, 41), Pair(-9, 27), Pair(-31, 31), Pair(-50, 18), Pair(-47, -21)
    }
  }},
  {{ // Bucket 1
    { // Piece 0
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-31, 46), Pair(-44, 71), Pair(-52, 33), Pair(14, 13), Pair(-34, 0), Pair(-52, -13), Pair(-77, 19), Pair(-97, 28),
      Pair(13, 19), Pair(-8, 44), Pair(27, -15), Pair(30, -45), Pair(34, -48), Pair(59, -38), Pair(1, 34), Pair(-2, 6),
      Pair(7, 0), Pair(1, -3), Pair(8, -23), Pair(9, -41), Pair(27, -46), Pair(16, -43), Pair(-1, -6), Pair(-4, -11),
      Pair(9, -19), Pair(-10, 2), Pair(10, -33), Pair(19, -36), Pair(16, -36), Pair(13, -40), Pair(-1, -12), Pair(-8, -23),
      Pair(4, -23), Pair(-12, -1), Pair(-3, -25), Pair(-10, -22), Pair(-7, -24), Pair(-10, -27), Pair(-6, -13), Pair(-18, -24),
      Pair(12, -17), Pair(3, 2), Pair(7, -13), Pair(-22, -10), Pair(-17, -1), Pair(1, -18), Pair(6, -9), Pair(-4, -19),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    { // Piece 1
      Pair(-140, -102), Pair(-149, 39), Pair(-104, -14), Pair(-82, 6), Pair(1, -32), Pair(-51, -64), Pair(-83, 0), Pair(-110, -100),
      Pair(-87, 12), Pair(-30, 6), Pair(-7, -5), Pair(-35, 8), Pair(-20, 2), Pair(8, -10), Pair(-51, -6), Pair(-8, -32),
      Pair(-54, 22), Pair(3, 21), Pair(-32, 41), Pair(7, 13), Pair(2, 14), Pair(10, 0), Pair(-25, 16), Pair(-22, -5),
      Pair(0, 24), Pair(1, 30), Pair(16, 28), Pair(27, 25), Pair(25, 23), Pair(31, 26), Pair(13, 15), Pair(16, 0),
      Pair(-13, 29), Pair(7, 31), Pair(16, 29), Pair(21, 30), Pair(23, 33), Pair(34, 14), Pair(18, 32), Pair(0, 8),
      Pair(-34, 19), Pair(-6, 25), Pair(10, 19), Pair(14, 33), Pair(24, 32), Pair(8, 15), Pair(10, 8), Pair(-14, 14),
      Pair(-36, 29), Pair(-14, 22), Pair(-3, 25), Pair(-7, 26), Pair(1, 16), Pair(0, 12), Pair(-8, 10), Pair(-29, 1),
      Pair(-75, 0), Pair(-32, 16), Pair(-21, 14), Pair(-17, 27), Pair(-6, 23), Pair(-19, 8), Pair(-32, 16), Pair(-25, -29)
    },
    { // Piece 2
      Pair(-76, 18), Pair(-76, 29), Pair(-99, 15), Pair(-123, 29), Pair(-168, 53), Pair(-149, 5), Pair(-48, 14), Pair(-87, 8),
      Pair(-64, -2), Pair(-37, 7), Pair(-39, 6), Pair(-60, 16), Pair(-67, 14), Pair(-33, 6), Pair(-46, 1), Pair(-32, -6),
      Pair(-27, 21), Pair(-39, 37), Pair(-41, 31), Pair(-8, 5), Pair(-30, 10), Pair(-14, 10), Pair(-5, 17), Pair(-2, 9),
      Pair(-25, 25), Pair(-5, 16), Pair(-15, 20), Pair(-8, 19), Pair(-10, 13), Pair(-3, 29), Pair(-16, 20), Pair(-23, 25),
      Pair(-12, -4), Pair(-49, 35), Pair(0, -5), Pair(0, 5), Pair(4, 1), Pair(-11, 7), Pair(-21, 18), Pair(-15, -2),
      Pair(-25, 14), Pair(10, 7), Pair(3, 21), Pair(0, 22), Pair(1, 27), Pair(7, 16), Pair(2, 10), Pair(-11, -2),
      Pair(2, -4), Pair(9, 5), Pair(19, -4), Pair(-7, 26), Pair(4, 15), Pair(9, 0), Pair(9, 3), Pair(-4, -8),
      Pair(-14, 1), Pair(1, 13), Pair(-18, 16), Pair(-2, 8), Pair(2, -1), Pair(-21, 18), Pair(-34, 28), Pair(-10, -10)
    },
    { // Piece 3
      Pair(8, 19), Pair(-70, 43), Pair(-30, 24), Pair(-17, 25), Pair(-70, 37), Pair(-62, 41), Pair(-48, 35), Pair(-47, 42),
      Pair(-31, 12), Pair(-32, 26), Pair(-26, 19), Pair(-10, 21), Pair(28, -5), Pair(-4, 3), Pair(-21, 10), Pair(-35, 14),
      Pair(-21, 0), Pair(2, 10), Pair(-35, 15), Pair(4, -2), Pair(31, -22), Pair(-4, -9), Pair(26, -7), Pair(-14, -11),
      Pair(-25, 4), Pair(15, -9), Pair(-11, 21), Pair(-14, 16), Pair(-10, 4), Pair(14, -8), Pair(4, -10), Pair(-19, -4),
      Pair(-14, 4), Pair(-36, 14), Pair(-26, 6), Pair(-15, 13), Pair(-14, 8), Pair(-26, 0), Pair(-13, -5), Pair(-36, -11),
      Pair(-22, -3), Pair(-12, 9), Pair(-26, 6), Pair(-23, 10), Pair(-16, -1), Pair(-15, -6), Pair(-2, -21), Pair(-25, -16),
      Pair(-24, -17), Pair(-28, 6), Pair(-12, 7), Pair(-19, -11), Pair(-3, -19), Pair(-17, -1), Pair(-13, -25), Pair(-35, -28),
      Pair(-8, -20), Pair(-20, -10), Pair(-21, 6), Pair(-7, -9), Pair(2, -16), Pair(-22, -17), Pair(-16, -21), Pair(-16, -34)
    },
    { // Piece 4
      Pair(-88, 43), Pair(-94, 53), Pair(-50, 50), Pair(-29, 34), Pair(-41, 51), Pair(-47, 36), Pair(-66, 46), Pair(-55, -11),
      Pair(-34, -25), Pair(-58, 42), Pair(-59, 59), Pair(-101, 106), Pair(-113, 114), Pair(-59, 76), Pair(-31, 27), Pair(-6, 36),
      Pair(-27, 17), Pair(-34, 1), Pair(-46, 57), Pair(-25, 32), Pair(-43, 78), Pair(-21, 42), Pair(0, 10), Pair(7, 39),
      Pair(-24, 4), Pair(-21, 20), Pair(-14, 33), Pair(-30, 61), Pair(-28, 46), Pair(-4, 22), Pair(6, 14), Pair(-5, 33),
      Pair(-14, -7), Pair(-35, 56), Pair(-19, 22), Pair(-21, 89), Pair(-24, 73), Pair(-17, 26), Pair(-9, 22), Pair(-10, 8),
      Pair(-22, -4), Pair(-10, 19), Pair(-15, 46), Pair(-24, 51), Pair(-14, 42), Pair(-14, 46), Pair(-3, 19), Pair(-7, 34),
      Pair(-14, -37), Pair(0, -54), Pair(1, -36), Pair(-5, -2), Pair(-7, 4), Pair(-10, 1), Pair(18, -62), Pair(14, -47),
      Pair(-18, -54), Pair(-11, -66), Pair(-9, -33), Pair(-9, -45), Pair(-18, -26), Pair(-16, -58), Pair(-6, -57), Pair(10, -50)
    },
    { // Piece 5
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
    { // Piece 0
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(65, 18), Pair(5, 41), Pair(24, 20), Pair(71, -35), Pair(38, -32), Pair(48, -17), Pair(-32, 24), Pair(-39, 38),
      Pair(11, 20), Pair(4, 28), Pair(23, -4), Pair(42, -40), Pair(64, -50), Pair(81, -33), Pair(34, 22), Pair(12, 21),
      Pair(-12, 3), Pair(-15, 8), Pair(-8, -15), Pair(7, -34), Pair(34, -37), Pair(25, -34), Pair(2, -1), Pair(-9, -9),
      Pair(-16, -11), Pair(-20, 5), Pair(-6, -21), Pair(7, -28), Pair(15, -31), Pair(15, -31), Pair(-7, -8), Pair(-18, -21),
      Pair(-32, -13), Pair(-31, 0), Pair(-18, -18), Pair(-11, -19), Pair(-7, -18), Pair(-7, -22), Pair(-8, -14), Pair(-30, -23),
      Pair(-22, -9), Pair(-21, 5), Pair(-10, -13), Pair(-23, -8), Pair(3, -14), Pair(25, -20), Pair(12, -10), Pair(-27, -19),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    { // Piece 1
      Pair(-152, -34), Pair(-108, -2), Pair(-114, 20), Pair(4, -17), Pair(60, -22), Pair(-112, 2), Pair(-146, 18), Pair(-127, -67),
      Pair(-65, 23), Pair(-39, 20), Pair(-11, 16), Pair(52, 4), Pair(16, 3), Pair(44, -11), Pair(-5, 14), Pair(-5, -10),
      Pair(-37, 19), Pair(-1, 17), Pair(2, 37), Pair(27, 17), Pair(22, 20), Pair(73, -17), Pair(26, -8), Pair(42, -14),
      Pair(-27, 26), Pair(10, 24), Pair(33, 32), Pair(53, 19), Pair(44, 28), Pair(70, 18), Pair(34, 21), Pair(56, 5),
      Pair(-14, 32), Pair(11, 25), Pair(23, 40), Pair(39, 32), Pair(43, 33), Pair(53, 20), Pair(56, 12), Pair(18, 20),
      Pair(-34, 17), Pair(-8, 22), Pair(14, 24), Pair(22, 39), Pair(43, 30), Pair(20, 15), Pair(27, 5), Pair(5, 10),
      Pair(-42, 14), Pair(-40, 26), Pair(-15, 28), Pair(7, 18), Pair(13, 11), Pair(9, 20), Pair(4, 0), Pair(1, 12),
      Pair(-95, 43), Pair(-31, 20), Pair(-12, 14), Pair(-6, 29), Pair(3, 20), Pair(12, 10), Pair(-7, 15), Pair(-36, 15)
    },
    { // Piece 2
      Pair(-57, 32), Pair(-53, 17), Pair(-103, 29), Pair(-111, 31), Pair(-73, 21), Pair(-101, 31), Pair(-50, 20), Pair(-105, 36),
      Pair(-38, 14), Pair(-22, 18), Pair(-16, 10), Pair(-56, 26), Pair(-40, 20), Pair(-29, 14), Pair(-48, 28), Pair(-27, 17),
      Pair(-24, 23), Pair(-12, 18), Pair(-9, 17), Pair(-16, 12), Pair(11, 6), Pair(27, 14), Pair(11, 22), Pair(12, 21),
      Pair(-20, 19), Pair(-2, 16), Pair(3, 19), Pair(29, 16), Pair(21, 15), Pair(25, 12), Pair(-4, 14), Pair(3, 10),
      Pair(-22, 14), Pair(-31, 26), Pair(4, 11), Pair(10, 17), Pair(16, 8), Pair(-5, 21), Pair(-1, 14), Pair(-4, 11),
      Pair(-27, 21), Pair(13, 13), Pair(7, 15), Pair(13, 17), Pair(10, 25), Pair(13, 13), Pair(19, 12), Pair(6, -7),
      Pair(-15, 12), Pair(-7, -4), Pair(9, 2), Pair(-5, 9), Pair(7, 7), Pair(11, 4), Pair(26, -8), Pair(-6, -5),
      Pair(-30, 11), Pair(7, 22), Pair(6, 9), Pair(-4, 18), Pair(0, 19), Pair(-13, 26), Pair(14, 1), Pair(-29, -4)
    },
    { // Piece 3
      Pair(-16, 29), Pair(6, 37), Pair(-11, 43), Pair(7, 36), Pair(-7, 30), Pair(34, 28), Pair(-9, 44), Pair(-12, 36),
      Pair(-7, 23), Pair(6, 33), Pair(25, 28), Pair(50, 19), Pair(43, 15), Pair(64, 15), Pair(27, 21), Pair(6, 19),
      Pair(-1, 20), Pair(20, 22), Pair(24, 21), Pair(26, 13), Pair(51, -2), Pair(62, -1), Pair(68, 4), Pair(13, 5),
      Pair(-23, 34), Pair(32, 21), Pair(15, 26), Pair(26, 17), Pair(35, 0), Pair(44, 3), Pair(37, 9), Pair(0, 9),
      Pair(-42, 29), Pair(-8, 25), Pair(-10, 24), Pair(6, 19), Pair(0, 13), Pair(-11, 22), Pair(4, 10), Pair(-15, 9),
      Pair(-26, 13), Pair(-22, 18), Pair(-14, 11), Pair(-9, 13), Pair(0, 10), Pair(-1, 4), Pair(16, -9), Pair(-33, 3),
      Pair(-28, 5), Pair(-13, 9), Pair(-8, 9), Pair(-2, 9), Pair(9, -9), Pair(6, -4), Pair(-2, 1), Pair(-23, -15),
      Pair(-32, 12), Pair(-23, 8), Pair(-20, 12), Pair(-16, 7), Pair(-7, -6), Pair(-8, -8), Pair(-12, -2), Pair(-31, 6)
    },
    { // Piece 4
      Pair(-44, 49), Pair(-9, 12), Pair(16, 32), Pair(55, 8), Pair(57, 10), Pair(36, 26), Pair(116, -52), Pair(55, 15),
      Pair(-29, 37), Pair(-15, 35), Pair(-13, 68), Pair(6, 44), Pair(2, 73), Pair(27, 29), Pair(29, 18), Pair(43, 43),
      Pair(-8, 18), Pair(4, 31), Pair(22, 43), Pair(21, 49), Pair(34, 50), Pair(78, 8), Pair(58, 13), Pair(52, 5),
      Pair(-9, 20), Pair(1, 47), Pair(16, 46), Pair(19, 54), Pair(30, 40), Pair(29, 48), Pair(43, 35), Pair(37, 13),
      Pair(0, 17), Pair(-10, 60), Pair(2, 57), Pair(15, 57), Pair(20, 46), Pair(21, 34), Pair(27, 30), Pair(14, 38),
      Pair(-5, 2), Pair(0, 30), Pair(3, 35), Pair(8, 42), Pair(13, 43), Pair(20, 35), Pair(30, 18), Pair(10, 38),
      Pair(4, 2), Pair(-7, 8), Pair(4, 11), Pair(11, 10), Pair(10, 17), Pair(14, -4), Pair(18, -32), Pair(28, -43),
      Pair(-35, 14), Pair(-26, 11), Pair(-19, 16), Pair(0, 5), Pair(-5, 5), Pair(-11, 6), Pair(2, 13), Pair(0, -12)
    },
    { // Piece 5
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
    { // Piece 0
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(56, 13), Pair(106, -6), Pair(66, 5), Pair(90, -27), Pair(136, -46), Pair(31, -23), Pair(-44, 48), Pair(-38, 39),
      Pair(2, 16), Pair(10, 30), Pair(72, -21), Pair(66, -40), Pair(98, -50), Pair(100, -33), Pair(27, 17), Pair(46, -4),
      Pair(-13, 5), Pair(-20, 14), Pair(-1, -14), Pair(13, -28), Pair(39, -28), Pair(33, -28), Pair(8, 3), Pair(-16, -9),
      Pair(-32, -5), Pair(-38, 16), Pair(-8, -14), Pair(-3, -19), Pair(8, -17), Pair(10, -20), Pair(-14, 3), Pair(-24, -14),
      Pair(-46, -10), Pair(-42, 5), Pair(-11, -16), Pair(10, -19), Pair(8, -16), Pair(6, -21), Pair(-12, -5), Pair(-39, -18),
      Pair(-42, 2), Pair(-35, 13), Pair(0, -11), Pair(-41, -3), Pair(10, -9), Pair(18, -16), Pair(-14, 2), Pair(-40, -8),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    { // Piece 1
      Pair(-163, -67), Pair(-105, -16), Pair(-90, 24), Pair(-48, 0), Pair(-50, 10), Pair(-67, -13), Pair(-26, -19), Pair(-125, -47),
      Pair(-87, 1), Pair(-22, 14), Pair(-45, 24), Pair(29, -1), Pair(27, -6), Pair(1, 2), Pair(-55, 27), Pair(-73, 10),
      Pair(0, -12), Pair(27, 4), Pair(19, 13), Pair(41, 17), Pair(35, 5), Pair(57, -15), Pair(62, -9), Pair(46, -23),
      Pair(3, 21), Pair(13, 20), Pair(43, 22), Pair(72, 13), Pair(103, 9), Pair(74, 21), Pair(99, -6), Pair(43, 9),
      Pair(-15, 13), Pair(20, 17), Pair(16, 31), Pair(49, 27), Pair(58, 28), Pair(65, 8), Pair(27, 12), Pair(50, -6),
      Pair(-27, -6), Pair(-25, 16), Pair(17, 14), Pair(20, 27), Pair(56, 24), Pair(49, 3), Pair(23, 4), Pair(-36, 18),
      Pair(-77, 12), Pair(-11, 15), Pair(-34, 18), Pair(8, 21), Pair(-7, 22), Pair(58, 5), Pair(-5, 10), Pair(22, 10),
      Pair(-52, 15), Pair(-37, -3), Pair(-87, 35), Pair(-112, 28), Pair(-18, 13), Pair(-11, 6), Pair(-46, 12), Pair(-28, 26)
    },
    { // Piece 2
      Pair(-61, 14), Pair(-46, 24), Pair(-36, 9), Pair(-76, 3), Pair(-68, 17), Pair(-133, 13), Pair(-73, 5), Pair(-66, -4),
      Pair(-52, -5), Pair(16, -2), Pair(-58, 14), Pair(21, -4), Pair(-81, 11), Pair(-27, -2), Pair(-60, 24), Pair(-54, 6),
      Pair(-8, 13), Pair(-16, 0), Pair(-1, 5), Pair(27, -8), Pair(10, 8), Pair(55, 2), Pair(14, 11), Pair(44, -5),
      Pair(3, 5), Pair(1, 4), Pair(33, -4), Pair(55, -5), Pair(63, -6), Pair(42, 13), Pair(38, 2), Pair(29, -3),
      Pair(-54, 13), Pair(-11, 13), Pair(16, 4), Pair(35, 7), Pair(32, 0), Pair(26, 9), Pair(-6, 15), Pair(-28, 5),
      Pair(-43, 11), Pair(-14, 13), Pair(12, 5), Pair(30, -3), Pair(47, -4), Pair(23, 2), Pair(3, 0), Pair(-29, 6),
      Pair(-22, 30), Pair(-20, 9), Pair(-28, 15), Pair(-9, 11), Pair(0, 7), Pair(-20, 11), Pair(6, -11), Pair(6, -13),
      Pair(-34, 0), Pair(-48, 56), Pair(-11, 9), Pair(-19, 7), Pair(29, 0), Pair(-12, 11), Pair(-90, 31), Pair(-31, -2)
    },
    { // Piece 3
      Pair(-39, 38), Pair(-39, 40), Pair(26, 29), Pair(-49, 40), Pair(-2, 24), Pair(4, 41), Pair(-9, 29), Pair(-65, 41),
      Pair(5, 17), Pair(22, 28), Pair(-3, 35), Pair(88, -8), Pair(14, 13), Pair(12, 30), Pair(9, 24), Pair(-18, 15),
      Pair(-30, 30), Pair(17, 21), Pair(43, 5), Pair(5, 14), Pair(31, 5), Pair(50, 9), Pair(17, 18), Pair(-32, 16),
      Pair(-92, 44), Pair(9, 21), Pair(-24, 36), Pair(22, 23), Pair(16, 10), Pair(-10, 19), Pair(4, 18), Pair(-31, 17),
      Pair(-83, 34), Pair(-75, 46), Pair(-58, 33), Pair(-22, 25), Pair(3, 15), Pair(-29, 20), Pair(-34, 24), Pair(-50, 14),
      Pair(-45, 10), Pair(-30, 11), Pair(-19, 6), Pair(-23, 8), Pair(-19, 5), Pair(-28, 16), Pair(5, -14), Pair(-81, 6),
      Pair(-89, 16), Pair(-35, 4), Pair(-32, 11), Pair(-46, 10), Pair(-49, 16), Pair(0, -10), Pair(-11, -11), Pair(-63, 5),
      Pair(-46, 8), Pair(-43, 14), Pair(-45, 18), Pair(-34, 14), Pair(-34, 6), Pair(-20, -2), Pair(-29, 2), Pair(-42, 2)
    },
    { // Piece 4
      Pair(-99, 17), Pair(-51, -10), Pair(-56, 14), Pair(-37, 19), Pair(-114, 56), Pair(-17, 36), Pair(-25, -62), Pair(-84, 17),
      Pair(-117, 27), Pair(-109, 28), Pair(-116, 61), Pair(-49, 53), Pair(-20, 33), Pair(35, -15), Pair(-38, -3), Pair(12, -41),
      Pair(-49, 13), Pair(-92, 26), Pair(-18, 6), Pair(-88, 68), Pair(-13, 27), Pair(30, -12), Pair(42, -56), Pair(21, -26),
      Pair(-100, 32), Pair(-46, 8), Pair(-35, 7), Pair(-56, 53), Pair(8, 9), Pair(18, 3), Pair(50, -43), Pair(2, -26),
      Pair(-60, -38), Pair(-101, 39), Pair(-55, 57), Pair(-33, 48), Pair(-44, 68), Pair(-15, 15), Pair(-18, 18), Pair(-58, 44),
      Pair(-103, -11), Pair(-39, -21), Pair(-33, 8), Pair(-41, 17), Pair(-43, 33), Pair(12, -40), Pair(23, -78), Pair(-51, -10),
      Pair(-51, -42), Pair(-86, 19), Pair(-30, -37), Pair(-31, -22), Pair(-27, 7), Pair(-37, -24), Pair(-34, -60), Pair(-63, -54),
      Pair(-95, -14), Pair(-107, 0), Pair(-62, -19), Pair(-43, -43), Pair(-25, -69), Pair(-26, -26), Pair(-58, 18), Pair(-18, -50)
    },
    { // Piece 5
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
    { // Piece 0
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(48, 17), Pair(149, -32), Pair(121, 2), Pair(97, -38), Pair(41, 1), Pair(-26, 16), Pair(26, 50), Pair(119, 7),
      Pair(3, 11), Pair(-1, 40), Pair(86, -23), Pair(132, -50), Pair(134, -43), Pair(129, -29), Pair(114, 0), Pair(49, 9),
      Pair(-58, 17), Pair(30, 12), Pair(25, -14), Pair(12, -22), Pair(38, -16), Pair(48, -18), Pair(8, 10), Pair(12, -7),
      Pair(-39, 4), Pair(-47, 25), Pair(-7, -5), Pair(-19, -4), Pair(1, -6), Pair(-6, -8), Pair(-31, 15), Pair(-53, -5),
      Pair(-64, -1), Pair(-40, 10), Pair(-3, -15), Pair(-1, -15), Pair(-12, -13), Pair(-9, -14), Pair(-15, 0), Pair(-73, -6),
      Pair(-76, 13), Pair(-63, 22), Pair(15, -14), Pair(-39, -15), Pair(-10, -1), Pair(9, -13), Pair(-2, 3), Pair(-79, 4),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    { // Piece 1
      Pair(-133, -135), Pair(-57, -70), Pair(-18, -19), Pair(-7, -31), Pair(22, -11), Pair(44, -38), Pair(-47, -40), Pair(-154, -82),
      Pair(-88, -4), Pair(-22, 3), Pair(-6, -10), Pair(86, -29), Pair(27, -36), Pair(-12, 7), Pair(45, -3), Pair(20, -39),
      Pair(-20, -13), Pair(9, -10), Pair(112, -21), Pair(104, -26), Pair(45, 0), Pair(81, -25), Pair(73, -20), Pair(55, -20),
      Pair(-36, 8), Pair(24, 0), Pair(30, 2), Pair(134, -20), Pair(118, -9), Pair(82, 6), Pair(161, -32), Pair(107, -34),
      Pair(-48, 4), Pair(-42, 14), Pair(4, 20), Pair(47, 13), Pair(44, 8), Pair(79, 4), Pair(15, 3), Pair(101, -7),
      Pair(-78, 3), Pair(-96, 28), Pair(40, 3), Pair(9, 14), Pair(-9, 25), Pair(58, -3), Pair(-31, 21), Pair(-41, 12),
      Pair(-31, 13), Pair(-51, 6), Pair(-33, 0), Pair(-4, 4), Pair(-11, 10), Pair(-51, 24), Pair(7, -27), Pair(-10, -18),
      Pair(-34, -10), Pair(-96, -9), Pair(-95, -3), Pair(37, -7), Pair(-21, 8), Pair(-61, -3), Pair(-47, 14), Pair(-43, 21)
    },
    { // Piece 2
      Pair(20, -20), Pair(-59, 3), Pair(11, -27), Pair(11, -13), Pair(-9, -21), Pair(9, -23), Pair(-25, -11), Pair(9, -19),
      Pair(-8, -22), Pair(25, -23), Pair(46, -17), Pair(-59, -12), Pair(-70, -2), Pair(37, -23), Pair(-73, 0), Pair(-82, 15),
      Pair(-51, 10), Pair(15, -17), Pair(116, -27), Pair(77, -23), Pair(111, -34), Pair(82, -3), Pair(72, -12), Pair(18, -5),
      Pair(-81, 9), Pair(29, -14), Pair(59, -16), Pair(111, -28), Pair(27, 0), Pair(72, -13), Pair(54, -19), Pair(21, -11),
      Pair(1, -21), Pair(26, -14), Pair(10, -11), Pair(71, -23), Pair(18, -17), Pair(14, -3), Pair(21, -7), Pair(25, -14),
      Pair(-95, 20), Pair(19, 0), Pair(16, -2), Pair(38, -9), Pair(51, 1), Pair(31, -5), Pair(30, 3), Pair(-79, 11),
      Pair(-51, 27), Pair(-55, 5), Pair(12, -6), Pair(-1, -5), Pair(-73, 13), Pair(-56, -6), Pair(-8, -16), Pair(-48, 4),
      Pair(-77, 4), Pair(-77, 2), Pair(-14, 4), Pair(15, 0), Pair(-88, 1), Pair(-36, 3), Pair(-33, -20), Pair(77, 15)
    },
    { // Piece 3
      Pair(-24, 15), Pair(-23, 29), Pair(22, 19), Pair(-1, 9), Pair(-11, 23), Pair(63, -4), Pair(-15, 22), Pair(79, -8),
      Pair(1, 9), Pair(60, -1), Pair(29, 5), Pair(91, -21), Pair(83, -20), Pair(25, 12), Pair(88, -8), Pair(54, -7),
      Pair(17, -4), Pair(8, 14), Pair(17, 7), Pair(60, -8), Pair(87, -24), Pair(26, -1), Pair(12, 12), Pair(-4, 5),
      Pair(-11, 11), Pair(-48, 33), Pair(13, 2), Pair(36, -2), Pair(12, -4), Pair(61, -17), Pair(13, 8), Pair(-27, 8),
      Pair(-46, 5), Pair(-83, 18), Pair(-69, 16), Pair(-67, 13), Pair(16, -14), Pair(-1, -3), Pair(-24, 1), Pair(6, -28),
      Pair(-6, -8), Pair(-29, 15), Pair(-124, 25), Pair(-92, 22), Pair(-70, 9), Pair(-49, -2), Pair(-8, -15), Pair(-71, -1),
      Pair(-96, 16), Pair(-87, 25), Pair(-31, 1), Pair(-35, 5), Pair(17, -21), Pair(9, -16), Pair(0, -26), Pair(-55, -3),
      Pair(-106, 27), Pair(-91, 27), Pair(-84, 22), Pair(-64, 10), Pair(-30, -5), Pair(-46, 0), Pair(-87, 26), Pair(-87, 9)
    },
    { // Piece 4
      Pair(-89, -5), Pair(-96, -39), Pair(-57, -4), Pair(-95, 25), Pair(3, -34), Pair(-73, 0), Pair(-6, -67), Pair(-135, 18),
      Pair(-105, -24), Pair(-57, -9), Pair(-120, 27), Pair(-96, 81), Pair(-52, 63), Pair(-130, 28), Pair(-75, -20), Pair(-73, -29),
      Pair(-91, -38), Pair(-85, -4), Pair(-19, -15), Pair(-86, 55), Pair(13, -14), Pair(11, 20), Pair(-112, -24), Pair(-38, -33),
      Pair(-111, 5), Pair(-99, 19), Pair(-140, 35), Pair(-33, 21), Pair(-70, 25), Pair(-26, -17), Pair(-87, 6), Pair(16, -27),
      Pair(-127, -36), Pair(-96, -19), Pair(-170, 37), Pair(-62, 20), Pair(-48, 9), Pair(-75, 46), Pair(-17, -45), Pair(-77, -74),
      Pair(-147, -55), Pair(-137, 20), Pair(-65, 6), Pair(-118, 71), Pair(-34, -2), Pair(-18, -61), Pair(-112, -53), Pair(-60, -2),
      Pair(-119, 12), Pair(-116, -23), Pair(-153, 7), Pair(-121, 7), Pair(-93, 12), Pair(-72, -73), Pair(-74, -40), Pair(-115, -30),
      Pair(-103, -58), Pair(-97, -121), Pair(-95, -62), Pair(-48, -128), Pair(-63, -9), Pair(-97, -50), Pair(-79, -15), Pair(-122, -111)
    },
    { // Piece 5
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
    { // Piece 0
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(15, 54), Pair(135, -5), Pair(153, 69), Pair(172, 2), Pair(56, 45), Pair(131, 45), Pair(0, 83), Pair(100, 55),
      Pair(76, 20), Pair(80, 55), Pair(105, 27), Pair(162, -10), Pair(164, -13), Pair(168, -6), Pair(123, 19), Pair(56, 29),
      Pair(-55, 30), Pair(-7, 39), Pair(66, 10), Pair(19, 3), Pair(47, -3), Pair(85, -11), Pair(19, 21), Pair(-30, 8),
      Pair(-54, 16), Pair(-19, 29), Pair(27, 4), Pair(-17, -3), Pair(-4, -5), Pair(-14, -2), Pair(-8, 16), Pair(-41, -4),
      Pair(-73, 5), Pair(-55, 17), Pair(-5, -10), Pair(5, -11), Pair(-2, -8), Pair(12, -13), Pair(0, 3), Pair(-45, -8),
      Pair(-85, 13), Pair(-77, 29), Pair(-13, 7), Pair(-106, 35), Pair(-94, 11), Pair(-45, 1), Pair(-39, 15), Pair(-85, 12),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    { // Piece 1
      Pair(-25, -90), Pair(26, -87), Pair(45, -45), Pair(43, -66), Pair(52, -30), Pair(27, -92), Pair(-22, -68), Pair(45, -70),
      Pair(-76, -70), Pair(66, -31), Pair(92, -38), Pair(139, -67), Pair(108, -66), Pair(33, -38), Pair(55, -30), Pair(-6, -44),
      Pair(-44, -22), Pair(32, -30), Pair(72, -40), Pair(110, -20), Pair(201, -45), Pair(122, -36), Pair(120, -50), Pair(62, -55),
      Pair(47, -45), Pair(49, -25), Pair(135, -25), Pair(120, -18), Pair(125, -24), Pair(63, -3), Pair(100, -41), Pair(28, -23),
      Pair(-11, -32), Pair(-37, -14), Pair(61, -9), Pair(64, -8), Pair(151, -8), Pair(101, -27), Pair(98, -49), Pair(42, -48),
      Pair(-52, -62), Pair(-71, -13), Pair(-32, -5), Pair(60, -25), Pair(-11, 0), Pair(-51, 12), Pair(-58, -11), Pair(-7, -32),
      Pair(-68, -54), Pair(-80, -23), Pair(-90, -18), Pair(-138, -2), Pair(-48, 0), Pair(-7, -22), Pair(9, -17), Pair(-38, -9),
      Pair(-29, -29), Pair(-78, -35), Pair(-129, -6), Pair(-74, 10), Pair(-30, -39), Pair(-101, -21), Pair(-108, -18), Pair(-36, -30)
    },
    { // Piece 2
      Pair(-58, -30), Pair(116, -51), Pair(104, -60), Pair(38, -59), Pair(52, -61), Pair(-19, -38), Pair(118, -71), Pair(-16, -52),
      Pair(-42, -37), Pair(38, -37), Pair(18, -27), Pair(38, -56), Pair(129, -67), Pair(97, -49), Pair(120, -55), Pair(2, -50),
      Pair(-43, -18), Pair(101, -62), Pair(47, -33), Pair(149, -51), Pair(97, -49), Pair(141, -41), Pair(141, -52), Pair(118, -52),
      Pair(46, -55), Pair(86, -41), Pair(144, -46), Pair(171, -61), Pair(134, -48), Pair(119, -40), Pair(68, -41), Pair(81, -58),
      Pair(1, -27), Pair(15, -27), Pair(76, -35), Pair(108, -39), Pair(106, -49), Pair(12, -16), Pair(85, -56), Pair(30, -3),
      Pair(-54, -10), Pair(117, -34), Pair(2, -25), Pair(87, -31), Pair(44, -30), Pair(56, -29), Pair(8, -2), Pair(17, -36),
      Pair(-22, -7), Pair(-126, 2), Pair(-38, -27), Pair(9, -35), Pair(49, -38), Pair(-66, -29), Pair(-123, 7), Pair(-41, -48),
      Pair(-50, -16), Pair(-18, -19), Pair(-136, 16), Pair(-78, -18), Pair(-106, -3), Pair(-95, -14), Pair(-21, -31), Pair(-67, 1)
    },
    { // Piece 3
      Pair(63, -19), Pair(74, -24), Pair(5, -8), Pair(52, -4), Pair(1, -17), Pair(58, -26), Pair(49, -2), Pair(129, -36),
      Pair(92, -32), Pair(108, -21), Pair(103, -29), Pair(127, -50), Pair(114, -50), Pair(56, -27), Pair(160, -52), Pair(76, -24),
      Pair(-5, -14), Pair(66, -26), Pair(133, -59), Pair(78, -40), Pair(60, -27), Pair(92, -49), Pair(121, -45), Pair(27, -33),
      Pair(-14, -5), Pair(50, -27), Pair(-17, -17), Pair(32, -33), Pair(-26, -28), Pair(82, -63), Pair(-55, -11), Pair(58, -47),
      Pair(-49, -12), Pair(-67, 1), Pair(-2, -13), Pair(33, -28), Pair(21, -33), Pair(44, -30), Pair(40, -27), Pair(-22, -12),
      Pair(-33, -26), Pair(-67, -10), Pair(-40, -19), Pair(-35, -7), Pair(7, -34), Pair(-46, -20), Pair(75, -39), Pair(-76, -18),
      Pair(-6, -23), Pair(-78, -4), Pair(-12, -20), Pair(-49, -15), Pair(-56, -24), Pair(-7, -27), Pair(-57, -20), Pair(-45, -26),
      Pair(-186, 26), Pair(-162, 37), Pair(-91, -6), Pair(-82, -6), Pair(-94, -8), Pair(-68, -11), Pair(-94, -7), Pair(-165, 26)
    },
    { // Piece 4
      Pair(-116, -80), Pair(-114, -67), Pair(-8, -70), Pair(-6, -35), Pair(-16, -61), Pair(-43, -85), Pair(-59, -78), Pair(-74, -105),
      Pair(-122, -9), Pair(-54, -39), Pair(-13, -12), Pair(17, 10), Pair(-36, -13), Pair(49, -35), Pair(13, -30), Pair(-73, -12),
      Pair(-58, -46), Pair(-16, -83), Pair(-3, -13), Pair(1, -56), Pair(30, -37), Pair(77, -97), Pair(-77, -38), Pair(26, -75),
      Pair(-93, -45), Pair(-42, -61), Pair(-58, -2), Pair(64, -65), Pair(-24, -17), Pair(-52, -39), Pair(-94, -24), Pair(-97, -30),
      Pair(-113, -23), Pair(-48, -21), Pair(-77, -25), Pair(-58, 42), Pair(-67, 27), Pair(2, -73), Pair(-113, 1), Pair(-51, -35),
      Pair(-102, -24), Pair(-115, 16), Pair(-72, -3), Pair(-53, -37), Pair(-134, 42), Pair(-104, -43), Pair(-87, -44), Pair(-38, -23),
      Pair(-79, -77), Pair(-95, -43), Pair(-95, -30), Pair(-85, -77), Pair(-89, -36), Pair(-87, -65), Pair(-34, 19), Pair(-72, -80),
      Pair(-100, -122), Pair(-118, -24), Pair(-74, -81), Pair(-170, -105), Pair(-61, -25), Pair(-68, -48), Pair(-78, -32), Pair(-28, -50)
    },
    { // Piece 5
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
    { // Piece 0
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(16, 100), Pair(82, 113), Pair(136, 156), Pair(124, 153), Pair(87, 134), Pair(102, 147), Pair(46, 137), Pair(63, 104),
      Pair(-37, 83), Pair(86, 114), Pair(136, 93), Pair(117, 82), Pair(53, 63), Pair(115, 91), Pair(19, 107), Pair(-47, 52),
      Pair(21, 47), Pair(-38, 83), Pair(85, 41), Pair(16, 55), Pair(95, 13), Pair(46, 30), Pair(-145, 77), Pair(-3, 28),
      Pair(-35, 32), Pair(-82, 47), Pair(76, 17), Pair(81, -6), Pair(5, 18), Pair(5, -2), Pair(-26, 40), Pair(-29, 1),
      Pair(-66, 20), Pair(21, 8), Pair(92, -27), Pair(83, -43), Pair(-43, 18), Pair(112, -25), Pair(-110, 21), Pair(6, -11),
      Pair(-101, 32), Pair(-56, 40), Pair(-39, 21), Pair(-59, 48), Pair(-45, 6), Pair(-53, 7), Pair(-48, 25), Pair(-72, 22),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    { // Piece 1
      Pair(-34, -106), Pair(-55, -93), Pair(35, -28), Pair(2, -73), Pair(1, -52), Pair(22, -92), Pair(-7, -113), Pair(-28, -103),
      Pair(29, -66), Pair(12, -70), Pair(-19, -6), Pair(16, -44), Pair(75, -57), Pair(-66, -63), Pair(9, -99), Pair(-6, -55),
      Pair(16, -67), Pair(-31, -34), Pair(55, -14), Pair(108, 8), Pair(173, 79), Pair(63, -12), Pair(65, -29), Pair(26, -29),
      Pair(11, -19), Pair(1, 6), Pair(97, -23), Pair(94, -30), Pair(100, -23), Pair(65, -8), Pair(139, 66), Pair(29, -59),
      Pair(11, -15), Pair(-24, -4), Pair(-7, 0), Pair(-53, 25), Pair(151, 95), Pair(18, -3), Pair(-10, -23), Pair(-4, -11),
      Pair(-28, -51), Pair(-19, -58), Pair(1, -27), Pair(-7, -19), Pair(49, -17), Pair(-4, -6), Pair(48, -59), Pair(-10, -1),
      Pair(-17, -96), Pair(-47, -43), Pair(-28, 7), Pair(-89, -7), Pair(-77, -19), Pair(-6, -49), Pair(-37, -61), Pair(18, -71),
      Pair(-31, -11), Pair(-92, 27), Pair(-1, -8), Pair(-22, 2), Pair(22, 14), Pair(-53, -11), Pair(-100, -20), Pair(-9, -47)
    },
    { // Piece 2
      Pair(-2, -55), Pair(25, -64), Pair(25, -20), Pair(102, -3), Pair(-68, -54), Pair(-35, -68), Pair(-24, -81), Pair(18, -31),
      Pair(-47, -73), Pair(2, -54), Pair(-53, -59), Pair(46, -68), Pair(6, -20), Pair(37, -54), Pair(61, -53), Pair(0, -62),
      Pair(-21, -43), Pair(9, -24), Pair(84, -57), Pair(17, -65), Pair(34, -66), Pair(0, -21), Pair(10, -39), Pair(-34, -47),
      Pair(-12, -41), Pair(32, -19), Pair(85, -22), Pair(9, -52), Pair(104, -51), Pair(1, -35), Pair(-28, -9), Pair(66, -71),
      Pair(10, -36), Pair(102, -59), Pair(15, -28), Pair(122, -51), Pair(80, -40), Pair(66, -34), Pair(-20, -10), Pair(94, 71),
      Pair(17, -23), Pair(31, -75), Pair(107, -44), Pair(2, -31), Pair(-49, -23), Pair(-20, -37), Pair(18, -33), Pair(-13, 4),
      Pair(-10, 25), Pair(72, -26), Pair(71, -48), Pair(29, -33), Pair(-2, -36), Pair(32, -13), Pair(-63, -59), Pair(8, 18),
      Pair(-29, -48), Pair(38, 19), Pair(-62, -17), Pair(-17, 0), Pair(-43, -25), Pair(-99, -32), Pair(-10, 4), Pair(-40, -65)
    },
    { // Piece 3
      Pair(110, -51), Pair(62, -18), Pair(97, -57), Pair(4, -39), Pair(77, -37), Pair(37, -31), Pair(49, -53), Pair(129, -59),
      Pair(164, -64), Pair(144, -43), Pair(125, -53), Pair(107, -39), Pair(106, -65), Pair(95, -62), Pair(87, -68), Pair(119, -54),
      Pair(57, -44), Pair(102, -35), Pair(57, -46), Pair(56, -48), Pair(26, -39), Pair(56, -39), Pair(47, -32), Pair(31, -23),
      Pair(63, -52), Pair(46, -38), Pair(34, -49), Pair(-90, -17), Pair(5, -16), Pair(109, -58), Pair(106, -54), Pair(58, -22),
      Pair(26, -43), Pair(57, -16), Pair(74, -26), Pair(25, -47), Pair(125, -38), Pair(23, -37), Pair(108, -20), Pair(42, -25),
      Pair(-4, -36), Pair(-15, -21), Pair(5, -71), Pair(56, -52), Pair(-71, -34), Pair(63, -37), Pair(97, 13), Pair(18, -40),
      Pair(-56, -35), Pair(-16, 5), Pair(-2, -62), Pair(71, -42), Pair(-1, -38), Pair(28, -46), Pair(23, -18), Pair(-18, -32),
      Pair(-166, -5), Pair(-79, 17), Pair(74, -39), Pair(-106, -23), Pair(60, -46), Pair(-24, -29), Pair(63, -66), Pair(-134, 13)
    },
    { // Piece 4
      Pair(-41, -115), Pair(-102, -56), Pair(-48, -39), Pair(17, -30), Pair(62, -67), Pair(-84, -64), Pair(39, -59), Pair(14, -97),
      Pair(28, -30), Pair(-49, -37), Pair(33, 0), Pair(1, -25), Pair(0, -28), Pair(-7, -31), Pair(-46, -65), Pair(-81, -91),
      Pair(7, -23), Pair(24, -34), Pair(20, 4), Pair(20, -9), Pair(13, -1), Pair(-8, -21), Pair(2, -24), Pair(-29, -75),
      Pair(9, 4), Pair(23, 25), Pair(52, 36), Pair(42, -33), Pair(34, 14), Pair(13, 34), Pair(28, 6), Pair(-12, -8),
      Pair(9, -32), Pair(23, 6), Pair(2, -18), Pair(3, 18), Pair(33, 18), Pair(26, 44), Pair(-22, 12), Pair(-18, -41),
      Pair(5, -29), Pair(21, 48), Pair(-15, 32), Pair(4, 20), Pair(-60, -4), Pair(-65, -2), Pair(24, -30), Pair(-22, -38),
      Pair(42, 11), Pair(-44, -73), Pair(-17, 11), Pair(-47, -26), Pair(-32, 30), Pair(3, -24), Pair(-1, -5), Pair(5, 32),
      Pair(-35, -50), Pair(-96, -122), Pair(-35, -68), Pair(-101, 18), Pair(-47, -42), Pair(-85, -54), Pair(-49, -94), Pair(-83, -74)
    },
    { // Piece 5
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
  Pair(-18, 24), Pair(-4, 19), Pair(5, 42), Pair(11, 52), Pair(15, 59), Pair(20, 67), Pair(26, 66), Pair(29, 65),
  Pair(31, 57)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-26, -8), Pair(-16, -18), Pair(-7, 0), Pair(-1, 13), Pair(5, 23), Pair(7, 33), Pair(10, 38), Pair(12, 42),
  Pair(13, 47), Pair(17, 47), Pair(26, 45), Pair(30, 49), Pair(28, 64), Pair(26, 50)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-41, -23), Pair(-29, 5), Pair(-26, 12), Pair(-24, 23), Pair(-21, 26), Pair(-15, 29), Pair(-12, 35), Pair(-8, 37),
  Pair(-4, 40), Pair(-1, 44), Pair(2, 46), Pair(6, 49), Pair(11, 51), Pair(13, 51), Pair(11, 48)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-63, -119), Pair(-6, -203), Pair(-16, 23), Pair(-7, 68), Pair(-6, 110), Pair(-4, 128), Pair(-1, 143), Pair(1, 156),
  Pair(3, 165), Pair(6, 167), Pair(8, 174), Pair(9, 182), Pair(12, 179), Pair(12, 184), Pair(15, 184), Pair(19, 181),
  Pair(19, 186), Pair(21, 183), Pair(30, 173), Pair(44, 159), Pair(52, 150), Pair(95, 120), Pair(92, 112), Pair(112, 84),
  Pair(162, 64), Pair(267, -21), Pair(214, 9), Pair(119, 32)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-14, -83), Pair(-13, -68), Pair(-9, -34), Pair(17, 3), Pair(12, 73), Pair(84, 119), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 0), Pair(14, 6), Pair(19, 17), Pair(47, 62), Pair(114, 201), Pair(-135, 489), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(22, 10), Pair(15, 7), Pair(14, 16), Pair(26, 46), Pair(172, 24), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-10, -46), Pair(10, -36), Pair(0, -27), Pair(0, -14), Pair(-8, -6), Pair(-8, -19), Pair(8, -30), Pair(-8, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-6, 10), Pair(-2, -12), Pair(-11, -6), Pair(-8, -14), Pair(-12, -16), Pair(-5, -7), Pair(-1, -12), Pair(-3, 5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(21, 7), Pair(18, 3), Pair(17, 10), Pair(19, 8), Pair(20, 13), Pair(33, 5), Pair(43, 2), Pair(71, -3)
  },
  {
      Pair(9, 34), Pair(9, 8), Pair(11, 8), Pair(19, 0), Pair(15, 0), Pair(18, -3), Pair(25, -4), Pair(17, 15)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(14, -4), Pair(21, -6), Pair(9, 0),
  Pair(30, -13), Pair(29, -16), Pair(28, -13),
  Pair(38, -7), Pair(0, 0), Pair(33, -6),
  Pair(5, -1), Pair(22, -12), Pair(5, 1)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-4, -2), Pair(-11, 0), Pair(-6, 0),
  Pair(-3, -3), Pair(-14, 3), Pair(-7, 0),
  Pair(2, -7), Pair(-12, 1), Pair(0, -5),
  Pair(14, -8), Pair(-3, -5), Pair(12, -5),
  Pair(24, -8), Pair(24, 1), Pair(17, -8),
  Pair(0, 0), Pair(5, -28), Pair(0, 0),
  Pair(46, -46), Pair(0, 0), Pair(41, -44)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-9, 66), Pair(-12, 50), Pair(-3, 32), Pair(1, 22), Pair(3, 21), Pair(15, 18), Pair(5, 14)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-70, -1), Pair(-11, 6), Pair(-6, 31), Pair(3, 41), Pair(6, 48), Pair(7, 54), Pair(-2, 47)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-492, 220);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-66, -13), Pair(-73, -7), Pair(-23, -13), Pair(-25, -10), Pair(-24, -5), Pair(-38, -2), Pair(-54, -2), Pair(-36, 2)
  },
  {
      Pair(-9, 45), Pair(-35, 18), Pair(0, 7), Pair(7, -6), Pair(-5, -7), Pair(1, 0), Pair(-27, 18), Pair(-16, 29)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 2), Pair(25, -7), Pair(61, -28), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 0), Pair(30, -2), Pair(62, -12), Pair(71, -44), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(21, -20), Pair(35, -20), Pair(51, -14), Pair(80, -17), Pair(91, -26), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 14), Pair(10, 25), Pair(29, 31), Pair(74, 14), Pair(110, 10), Pair(173, -13), Pair(232, -63)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(49, 8), Pair(19, 22), Pair(58, 0), Pair(26, 14), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-18, 13), Pair(-11, 18)
  },
  {
      Pair(-69, -23), Pair(-69, -31)
  },
  {
      Pair(-58, -50), Pair(-68, -75)
  },
  {
      Pair(-98, 2), Pair(-88, -33)
  },
  {
      Pair(-78, 37), Pair(-87, 19)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(17, 33), Pair(22, 21), Pair(29, 10), Pair(24, -5), Pair(55, -6)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-2, -21), Pair(9, -12)
  },
  {
      Pair(-25, -45), Pair(-5, -61)
  },
  {
      Pair(-44, -35), Pair(-30, -36)
  },
  {
      Pair(-85, -3), Pair(-63, -29)
  },
  {
      Pair(-58, 32), Pair(-59, 19)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-10, -21), Pair(1, -9)
  },
  {
      Pair(-50, -24), Pair(-22, -26)
  },
  {
      Pair(16, -146), Pair(29, -139)
  },
  {
      Pair(-84, -5), Pair(-49, -37)
  },
  {
      Pair(-87, -18), Pair(-64, -90)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-1, -27), Pair(13, -12)
  },
  {
      Pair(-44, -26), Pair(-2, -15)
  },
  {
      Pair(-32, -31), Pair(-13, -5)
  },
  {
      Pair(0, -69), Pair(17, -43)
  },
  {
      Pair(-88, 9), Pair(-63, -47)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(18, 25), Pair(16, 15), Pair(40, 23), Pair(47, 25), Pair(52, 30), Pair(37, 46), Pair(49, 16), Pair(4, 34),
  Pair(3, 17), Pair(14, 18), Pair(19, 22), Pair(9, 36), Pair(14, 24), Pair(13, 19), Pair(14, 17), Pair(-10, 29),
  Pair(11, 10), Pair(6, 2), Pair(2, 15), Pair(9, 18), Pair(8, 21), Pair(-7, 20), Pair(3, 7), Pair(1, 8)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-17, 21), Pair(22, 1), Pair(32, 3), Pair(46, 3), Pair(71, -14), Pair(47, -1), Pair(27, -10), Pair(-20, -23),
  Pair(-20, -11), Pair(20, 9), Pair(11, 5), Pair(25, 11), Pair(15, 7), Pair(16, -2), Pair(13, 13), Pair(15, -16),
  Pair(-24, 32), Pair(11, 5), Pair(3, 22), Pair(20, 15), Pair(25, 23), Pair(3, 9), Pair(14, 1), Pair(-48, 7)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 60);

constexpr ScorePair kTempoBonus = Pair(32, 29);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H