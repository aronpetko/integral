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
  Pair(64, 121), Pair(246, 1), Pair(355, 360), Pair(384, 668), Pair(727, 1030), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(8, 20), Pair(-9, 48), Pair(-13, 54), Pair(37, -8), Pair(39, -19), Pair(51, -39), Pair(-6, -106), Pair(-71, -62),
      Pair(9, 55), Pair(-9, 80), Pair(19, 41), Pair(24, 5), Pair(39, 8), Pair(86, -25), Pair(36, 14), Pair(16, 17),
      Pair(-5, 9), Pair(-8, 22), Pair(-1, -8), Pair(0, -27), Pair(22, -35), Pair(25, -37), Pair(0, -2), Pair(4, -23),
      Pair(-6, -10), Pair(-15, 18), Pair(-1, -19), Pair(8, -31), Pair(11, -33), Pair(20, -37), Pair(0, -10), Pair(2, -33),
      Pair(-15, -15), Pair(-23, 10), Pair(-13, -16), Pair(-8, -18), Pair(-3, -16), Pair(-1, -26), Pair(-1, -15), Pair(0, -40),
      Pair(-7, -11), Pair(-13, 15), Pair(-6, -6), Pair(-9, -16), Pair(-1, -4), Pair(17, -17), Pair(9, -5), Pair(-1, -39),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-154, 41), Pair(-147, 51), Pair(-74, 56), Pair(-46, 29), Pair(-36, 35), Pair(-20, -42), Pair(-96, -2), Pair(-71, -90),
      Pair(-38, 48), Pair(-16, 54), Pair(-5, 42), Pair(-9, 56), Pair(-11, 48), Pair(66, 15), Pair(16, 49), Pair(23, -3),
      Pair(-8, 40), Pair(3, 56), Pair(-1, 68), Pair(10, 51), Pair(25, 41), Pair(68, 31), Pair(1, 49), Pair(37, 31),
      Pair(1, 54), Pair(18, 48), Pair(31, 54), Pair(37, 60), Pair(31, 56), Pair(44, 52), Pair(22, 55), Pair(31, 44),
      Pair(-6, 43), Pair(14, 42), Pair(25, 55), Pair(28, 55), Pair(30, 60), Pair(39, 37), Pair(30, 45), Pair(8, 40),
      Pair(-19, 30), Pair(0, 39), Pair(12, 42), Pair(18, 57), Pair(28, 53), Pair(19, 38), Pair(18, 37), Pair(3, 34),
      Pair(-27, 30), Pair(-15, 37), Pair(-4, 38), Pair(9, 34), Pair(10, 36), Pair(7, 26), Pair(4, 32), Pair(2, 39),
      Pair(-54, 47), Pair(-16, 19), Pair(-17, 36), Pair(-10, 47), Pair(3, 44), Pair(5, 30), Pair(-21, 33), Pair(-14, 12)
    },
    {
      Pair(-29, 44), Pair(-40, 28), Pair(-55, 25), Pair(-78, 46), Pair(-74, 12), Pair(-40, -12), Pair(-52, 50), Pair(-59, 55),
      Pair(-17, 31), Pair(-9, 32), Pair(0, 14), Pair(-25, 27), Pair(-15, 7), Pair(-3, 12), Pair(-42, 50), Pair(-17, 24),
      Pair(4, 31), Pair(1, 31), Pair(1, 29), Pair(-7, 21), Pair(-17, 33), Pair(36, 35), Pair(31, 32), Pair(16, 40),
      Pair(-9, 31), Pair(7, 31), Pair(6, 27), Pair(11, 46), Pair(10, 23), Pair(16, 24), Pair(4, 25), Pair(-1, 28),
      Pair(3, 13), Pair(-13, 31), Pair(7, 31), Pair(12, 16), Pair(13, 16), Pair(7, 17), Pair(-1, 26), Pair(11, 1),
      Pair(-3, 8), Pair(18, 34), Pair(14, 26), Pair(12, 27), Pair(12, 38), Pair(18, 27), Pair(20, 16), Pair(17, 9),
      Pair(13, 14), Pair(15, -4), Pair(21, 4), Pair(6, 18), Pair(19, 18), Pair(23, 16), Pair(34, 14), Pair(28, -14),
      Pair(9, -2), Pair(28, 7), Pair(7, 14), Pair(4, 22), Pair(17, 19), Pair(6, 29), Pair(21, 15), Pair(38, -27)
    },
    {
      Pair(6, 116), Pair(54, 102), Pair(-3, 145), Pair(39, 83), Pair(71, 59), Pair(42, 113), Pair(-29, 107), Pair(-7, 48),
      Pair(6, 53), Pair(10, 62), Pair(20, 67), Pair(36, 48), Pair(23, 45), Pair(62, 43), Pair(66, 47), Pair(31, 43),
      Pair(8, 42), Pair(36, 48), Pair(26, 54), Pair(27, 47), Pair(58, 22), Pair(75, 12), Pair(100, 19), Pair(47, 10),
      Pair(19, 39), Pair(35, 44), Pair(38, 44), Pair(31, 42), Pair(41, 31), Pair(46, 24), Pair(57, 22), Pair(37, 8),
      Pair(8, 36), Pair(15, 46), Pair(16, 39), Pair(21, 43), Pair(21, 32), Pair(6, 35), Pair(40, 18), Pair(16, 4),
      Pair(4, 32), Pair(10, 29), Pair(10, 37), Pair(10, 38), Pair(21, 27), Pair(22, 17), Pair(51, -5), Pair(26, -16),
      Pair(0, 22), Pair(4, 38), Pair(20, 30), Pair(17, 36), Pair(27, 20), Pair(23, 20), Pair(44, -4), Pair(3, 3),
      Pair(13, 24), Pair(16, 24), Pair(18, 29), Pair(23, 26), Pair(29, 16), Pair(27, 18), Pair(23, 10), Pair(10, 4)
    },
    {
      Pair(-140, 263), Pair(-19, 134), Pair(-26, 153), Pair(-5, 153), Pair(27, 80), Pair(32, 83), Pair(9, 135), Pair(-115, 249),
      Pair(-43, 118), Pair(-32, 120), Pair(-37, 160), Pair(-42, 164), Pair(-59, 192), Pair(-17, 175), Pair(-56, 163), Pair(-47, 193),
      Pair(-18, 108), Pair(-18, 119), Pair(-20, 140), Pair(-21, 149), Pair(-21, 151), Pair(12, 150), Pair(7, 138), Pair(11, 111),
      Pair(-24, 119), Pair(-13, 128), Pair(-13, 131), Pair(-16, 151), Pair(-14, 143), Pair(6, 112), Pair(3, 133), Pair(7, 105),
      Pair(-19, 106), Pair(-24, 135), Pair(-17, 126), Pair(-15, 147), Pair(-10, 134), Pair(-14, 130), Pair(3, 112), Pair(-3, 112),
      Pair(-18, 97), Pair(-13, 112), Pair(-14, 123), Pair(-19, 127), Pair(-18, 137), Pair(-7, 118), Pair(8, 101), Pair(3, 80),
      Pair(-15, 95), Pair(-10, 83), Pair(-8, 89), Pair(-6, 101), Pair(-6, 102), Pair(0, 71), Pair(14, 39), Pair(23, 16),
      Pair(-23, 93), Pair(-19, 86), Pair(-13, 87), Pair(-11, 89), Pair(-9, 85), Pair(-15, 70), Pair(-12, 62), Pair(2, 48)
    },
    {
      Pair(-550, -124), Pair(-598, -75), Pair(-639, -52), Pair(-675, -34), Pair(-681, -39), Pair(-730, -24), Pair(-672, -43), Pair(-518, -134),
      Pair(-673, -56), Pair(-621, -29), Pair(-671, -16), Pair(-630, -25), Pair(-679, -16), Pair(-710, 3), Pair(-671, -11), Pair(-728, -33),
      Pair(-836, 1), Pair(-729, 15), Pair(-806, 34), Pair(-833, 40), Pair(-831, 44), Pair(-777, 34), Pair(-811, 33), Pair(-806, -5),
      Pair(-786, -21), Pair(-764, 3), Pair(-819, 24), Pair(-857, 35), Pair(-869, 32), Pair(-841, 29), Pair(-819, 7), Pair(-863, -7),
      Pair(-347, -19), Pair(-322, 7), Pair(-389, 35), Pair(-427, 48), Pair(-435, 46), Pair(-407, 30), Pair(-379, 10), Pair(-429, -3),
      Pair(-186, -18), Pair(-152, 2), Pair(-207, 27), Pair(-227, 39), Pair(-228, 37), Pair(-223, 25), Pair(-183, 3), Pair(-205, -14),
      Pair(7, -29), Pair(-19, 6), Pair(-30, 17), Pair(-47, 25), Pair(-54, 28), Pair(-42, 19), Pair(-23, 1), Pair(-8, -26),
      Pair(96, -36), Pair(118, -7), Pair(-24, 9), Pair(-75, 22), Pair(-46, 10), Pair(-62, 18), Pair(100, -6), Pair(103, -43)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(106, 48), Pair(-8, 40), Pair(5, -40), Pair(38, -76), Pair(25, -87), Pair(-22, -38), Pair(-73, 121), Pair(37, 72),
      Pair(3, 50), Pair(-1, 43), Pair(40, -10), Pair(41, -30), Pair(52, -51), Pair(47, -14), Pair(30, 25), Pair(23, 24),
      Pair(-21, 14), Pair(-10, 12), Pair(0, -14), Pair(6, -25), Pair(20, -29), Pair(6, -22), Pair(5, -2), Pair(15, -11),
      Pair(-32, 0), Pair(-23, 9), Pair(-9, -22), Pair(8, -23), Pair(12, -26), Pair(7, -27), Pair(-9, -3), Pair(7, -28),
      Pair(-45, -7), Pair(-33, 5), Pair(-24, -20), Pair(-17, -12), Pair(-9, -20), Pair(-16, -22), Pair(-10, -13), Pair(-6, -32),
      Pair(-34, -3), Pair(-23, 7), Pair(-16, -9), Pair(-15, -8), Pair(-7, -4), Pair(0, -16), Pair(4, -12), Pair(-4, -29),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-94, -70), Pair(-25, 23), Pair(-66, 47), Pair(-36, -5), Pair(138, -31), Pair(-28, -5), Pair(-146, 18), Pair(-94, -42),
      Pair(-5, 23), Pair(-21, 54), Pair(-8, 55), Pair(38, -24), Pair(30, -11), Pair(9, 32), Pair(-15, 52), Pair(-23, 14),
      Pair(-10, 36), Pair(11, 40), Pair(-1, 53), Pair(37, 36), Pair(0, 39), Pair(8, 33), Pair(-11, 30), Pair(16, -4),
      Pair(19, 47), Pair(-2, 54), Pair(14, 55), Pair(17, 61), Pair(23, 54), Pair(25, 67), Pair(21, 52), Pair(20, 31),
      Pair(-12, 49), Pair(6, 47), Pair(14, 56), Pair(26, 50), Pair(15, 61), Pair(32, 37), Pair(11, 43), Pair(-3, 47),
      Pair(-28, 31), Pair(-5, 37), Pair(0, 40), Pair(11, 42), Pair(21, 48), Pair(6, 37), Pair(7, 37), Pair(-14, 32),
      Pair(-35, 31), Pair(-12, 40), Pair(-13, 27), Pair(-2, 38), Pair(-2, 34), Pair(-4, 49), Pair(-6, 0), Pair(-17, 45),
      Pair(-75, 62), Pair(-36, 55), Pair(-25, 38), Pair(-11, 46), Pair(-13, 30), Pair(-5, 22), Pair(-31, 49), Pair(-44, 40)
    },
    {
      Pair(9, 11), Pair(-63, 22), Pair(-69, -2), Pair(-147, 34), Pair(-73, 19), Pair(-87, 12), Pair(-25, -1), Pair(-37, -4),
      Pair(0, -13), Pair(3, 9), Pair(-3, -1), Pair(-18, 15), Pair(-16, 19), Pair(-14, 4), Pair(-41, 26), Pair(-44, 3),
      Pair(0, 27), Pair(23, -5), Pair(3, 6), Pair(37, 5), Pair(31, -2), Pair(1, 36), Pair(12, 18), Pair(-4, 25),
      Pair(-9, 16), Pair(4, 17), Pair(10, 17), Pair(9, 13), Pair(16, 11), Pair(17, 15), Pair(-3, 17), Pair(-12, 22),
      Pair(-6, 8), Pair(-21, 13), Pair(-3, 8), Pair(16, 11), Pair(14, 4), Pair(2, 14), Pair(-7, 14), Pair(-4, 20),
      Pair(-10, 16), Pair(14, 8), Pair(10, 12), Pair(3, 22), Pair(11, 18), Pair(12, 9), Pair(20, 15), Pair(10, -6),
      Pair(11, -1), Pair(11, 4), Pair(23, -7), Pair(2, 13), Pair(6, 10), Pair(16, 15), Pair(30, 1), Pair(11, 26),
      Pair(13, -13), Pair(20, -9), Pair(-6, 24), Pair(8, 9), Pair(13, 2), Pair(-15, 30), Pair(9, -31), Pair(15, -15)
    },
    {
      Pair(58, 47), Pair(75, 58), Pair(69, 48), Pair(95, 38), Pair(36, 6), Pair(-56, 60), Pair(34, 57), Pair(-22, 87),
      Pair(34, 38), Pair(33, 44), Pair(23, 40), Pair(55, 24), Pair(21, 31), Pair(-27, 61), Pair(-6, 53), Pair(-15, 57),
      Pair(12, 46), Pair(37, 30), Pair(21, 36), Pair(22, 16), Pair(14, 13), Pair(16, 21), Pair(39, 26), Pair(-16, 33),
      Pair(7, 33), Pair(9, 34), Pair(7, 29), Pair(-4, 29), Pair(6, 14), Pair(16, 19), Pair(-8, 35), Pair(-21, 43),
      Pair(-18, 25), Pair(-35, 36), Pair(-9, 24), Pair(-18, 38), Pair(-1, 20), Pair(-23, 39), Pair(-19, 33), Pair(-31, 32),
      Pair(-37, 26), Pair(-15, 22), Pair(-1, 17), Pair(-10, 18), Pair(-7, 15), Pair(-16, 30), Pair(0, 11), Pair(-27, 30),
      Pair(-20, 3), Pair(-13, 14), Pair(-9, 17), Pair(-22, 18), Pair(-5, 8), Pair(-14, 21), Pair(-6, 13), Pair(-35, 17),
      Pair(-23, 19), Pair(-9, 13), Pair(-6, 18), Pair(-5, 8), Pair(8, 0), Pair(-8, 18), Pair(-19, 18), Pair(-22, 9)
    },
    {
      Pair(54, 31), Pair(42, 36), Pair(53, 17), Pair(96, -14), Pair(-188, 262), Pair(-4, 110), Pair(1, 103), Pair(-1, 91),
      Pair(68, 10), Pair(22, 35), Pair(26, 69), Pair(10, 91), Pair(-102, 195), Pair(-10, 73), Pair(13, 49), Pair(47, 54),
      Pair(41, 23), Pair(41, 23), Pair(38, 46), Pair(25, 86), Pair(9, 99), Pair(13, 85), Pair(41, 37), Pair(22, 56),
      Pair(30, 44), Pair(21, 65), Pair(32, 73), Pair(-9, 110), Pair(15, 84), Pair(16, 94), Pair(21, 78), Pair(36, 51),
      Pair(16, 41), Pair(-5, 106), Pair(9, 81), Pair(9, 74), Pair(16, 90), Pair(12, 68), Pair(15, 65), Pair(19, 69),
      Pair(18, 36), Pair(18, 47), Pair(10, 71), Pair(5, 71), Pair(17, 67), Pair(16, 56), Pair(25, 51), Pair(18, 39),
      Pair(9, -16), Pair(21, 0), Pair(20, 25), Pair(17, 36), Pair(24, 29), Pair(24, 27), Pair(23, 13), Pair(20, 19),
      Pair(1, 41), Pair(-4, 56), Pair(7, 38), Pair(8, 16), Pair(22, -10), Pair(-2, 44), Pair(27, 14), Pair(0, 55)
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
      Pair(26, 34), Pair(31, 24), Pair(10, 23), Pair(24, -12), Pair(5, -7), Pair(21, -13), Pair(-48, 52), Pair(49, 29),
      Pair(-3, 12), Pair(-12, 35), Pair(19, -13), Pair(25, -37), Pair(30, -46), Pair(70, -42), Pair(24, -1), Pair(-4, 5),
      Pair(-5, 4), Pair(-15, 16), Pair(-5, -10), Pair(0, -24), Pair(25, -25), Pair(15, -21), Pair(3, -1), Pair(5, -11),
      Pair(-20, -7), Pair(-27, 14), Pair(-7, -15), Pair(0, -22), Pair(2, -20), Pair(4, -23), Pair(-3, -8), Pair(1, -22),
      Pair(-24, -13), Pair(-31, 5), Pair(-15, -17), Pair(-13, -14), Pair(3, -20), Pair(-8, -23), Pair(-3, -15), Pair(-3, -27),
      Pair(-13, -9), Pair(-20, 11), Pair(-2, -13), Pair(-15, -11), Pair(5, -6), Pair(10, -17), Pair(18, -14), Pair(-3, -23),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-124, -56), Pair(-51, 9), Pair(-73, 9), Pair(3, -8), Pair(-3, -1), Pair(-28, -31), Pair(-31, -16), Pair(-104, -74),
      Pair(-27, 3), Pair(-21, 27), Pair(-8, 26), Pair(30, 11), Pair(19, 7), Pair(8, 18), Pair(-27, 20), Pair(-41, 8),
      Pair(-29, 36), Pair(1, 32), Pair(20, 29), Pair(42, 18), Pair(45, 18), Pair(76, -11), Pair(46, 6), Pair(0, 1),
      Pair(-1, 29), Pair(14, 34), Pair(31, 38), Pair(48, 29), Pair(53, 31), Pair(53, 29), Pair(33, 31), Pair(42, 2),
      Pair(-15, 36), Pair(17, 36), Pair(28, 44), Pair(41, 39), Pair(46, 42), Pair(56, 27), Pair(45, 23), Pair(18, 27),
      Pair(-39, 37), Pair(-14, 34), Pair(6, 40), Pair(21, 44), Pair(38, 40), Pair(20, 25), Pair(15, 19), Pair(0, 25),
      Pair(-46, 31), Pair(-38, 37), Pair(-15, 36), Pair(4, 37), Pair(10, 33), Pair(-6, 38), Pair(-2, 24), Pair(-7, 30),
      Pair(-80, 16), Pair(-33, 27), Pair(-33, 31), Pair(-1, 27), Pair(-13, 38), Pair(-13, 28), Pair(-11, 21), Pair(-45, 46)
    },
    {
      Pair(-37, 6), Pair(-42, 10), Pair(-21, 8), Pair(-77, -2), Pair(-47, -12), Pair(-96, -4), Pair(-52, -3), Pair(-72, 2),
      Pair(-44, -5), Pair(-11, 1), Pair(2, -5), Pair(1, -12), Pair(-10, -5), Pair(-17, 6), Pair(-29, 8), Pair(-7, -19),
      Pair(-12, 8), Pair(12, -4), Pair(-20, 11), Pair(11, -12), Pair(-7, 1), Pair(-14, 4), Pair(-6, -2), Pair(6, -8),
      Pair(-12, 4), Pair(-2, 7), Pair(19, 2), Pair(15, 9), Pair(40, 5), Pair(45, 1), Pair(19, 2), Pair(6, -4),
      Pair(-19, 4), Pair(-3, 6), Pair(1, 1), Pair(20, 3), Pair(23, -4), Pair(10, 1), Pair(-9, 4), Pair(3, -4),
      Pair(-9, 5), Pair(6, 6), Pair(11, 8), Pair(9, 8), Pair(11, 14), Pair(16, 4), Pair(15, 0), Pair(6, -8),
      Pair(-18, 8), Pair(4, -4), Pair(15, -7), Pair(1, 6), Pair(5, 7), Pair(17, 0), Pair(22, -6), Pair(11, -14),
      Pair(-28, 5), Pair(16, -12), Pair(-2, 6), Pair(-5, 4), Pair(-5, 9), Pair(-6, 13), Pair(-2, 9), Pair(8, -10)
    },
    {
      Pair(-47, 31), Pair(-45, 37), Pair(-32, 34), Pair(-34, 30), Pair(-13, 15), Pair(23, 14), Pair(-22, 32), Pair(-39, 35),
      Pair(-4, 21), Pair(4, 30), Pair(17, 20), Pair(43, 18), Pair(28, 8), Pair(23, 9), Pair(-14, 20), Pair(-19, 22),
      Pair(-8, 17), Pair(25, 17), Pair(13, 16), Pair(14, 8), Pair(48, -5), Pair(63, -4), Pair(53, 6), Pair(-4, 8),
      Pair(-21, 25), Pair(8, 20), Pair(9, 23), Pair(12, 13), Pair(28, -2), Pair(41, -5), Pair(27, -1), Pair(-27, 10),
      Pair(-29, 11), Pair(-25, 20), Pair(-8, 11), Pair(-2, 12), Pair(5, 5), Pair(2, 2), Pair(-5, 5), Pair(-16, 0),
      Pair(-21, 4), Pair(-20, 13), Pair(-13, 6), Pair(-9, 10), Pair(4, -2), Pair(1, -3), Pair(12, -14), Pair(2, -24),
      Pair(-26, 5), Pair(-18, 7), Pair(-16, 10), Pair(-2, 2), Pair(-9, -1), Pair(0, -7), Pair(-11, -3), Pair(-33, -11),
      Pair(-19, 7), Pair(-16, 6), Pair(-9, 5), Pair(-2, 1), Pair(2, -6), Pair(0, -3), Pair(-8, -4), Pair(-23, -6)
    },
    {
      Pair(-54, 38), Pair(-87, 58), Pair(-51, 61), Pair(-31, 48), Pair(-18, 41), Pair(-22, 55), Pair(29, 1), Pair(-15, 29),
      Pair(-18, 38), Pair(-22, 55), Pair(-10, 57), Pair(-40, 76), Pair(-19, 53), Pair(-16, 40), Pair(-24, 113), Pair(16, 53),
      Pair(-1, 24), Pair(-6, 38), Pair(-8, 68), Pair(4, 50), Pair(0, 73), Pair(35, 39), Pair(21, 29), Pair(13, 56),
      Pair(-15, 27), Pair(7, 32), Pair(12, 36), Pair(5, 42), Pair(14, 61), Pair(17, 51), Pair(30, 34), Pair(13, 45),
      Pair(-9, 30), Pair(-1, 40), Pair(-2, 61), Pair(11, 61), Pair(13, 58), Pair(-6, 53), Pair(9, 41), Pair(11, 28),
      Pair(-6, 17), Pair(-6, 44), Pair(3, 46), Pair(7, 48), Pair(3, 47), Pair(8, 43), Pair(14, 32), Pair(12, 15),
      Pair(-1, 15), Pair(-1, 32), Pair(4, 29), Pair(5, 35), Pair(9, 32), Pair(15, 9), Pair(18, 0), Pair(-2, -3),
      Pair(-4, 1), Pair(-2, 5), Pair(-16, 26), Pair(3, 17), Pair(-12, 23), Pair(-15, 13), Pair(-12, 6), Pair(-19, 28)
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
      Pair(34, 19), Pair(131, -25), Pair(20, 23), Pair(0, 10), Pair(1, 3), Pair(-10, 5), Pair(68, 42), Pair(0, 48),
      Pair(18, -9), Pair(3, 1), Pair(45, -40), Pair(66, -60), Pair(26, -47), Pair(43, -40), Pair(41, -18), Pair(53, -15),
      Pair(-22, 4), Pair(-14, -2), Pair(-2, -23), Pair(-9, -27), Pair(25, -30), Pair(28, -35), Pair(-2, -4), Pair(9, -14),
      Pair(-33, -4), Pair(-28, 4), Pair(-13, -12), Pair(-13, -8), Pair(-11, -11), Pair(-3, -17), Pair(-7, -1), Pair(1, -20),
      Pair(-34, -11), Pair(-38, -4), Pair(-4, -21), Pair(-21, -14), Pair(4, -20), Pair(4, -25), Pair(-14, -14), Pair(-9, -24),
      Pair(-33, -2), Pair(-21, 1), Pair(5, -15), Pair(-26, -9), Pair(4, -13), Pair(22, -22), Pair(5, -11), Pair(-17, -14),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-110, -63), Pair(-207, -8), Pair(-149, 12), Pair(47, -26), Pair(49, -18), Pair(15, -18), Pair(-243, 16), Pair(-56, -76),
      Pair(-78, 20), Pair(6, 0), Pair(22, -13), Pair(72, -16), Pair(89, -36), Pair(38, -27), Pair(-44, 2), Pair(-21, -14),
      Pair(-43, -4), Pair(13, -8), Pair(20, 12), Pair(52, 0), Pair(74, 4), Pair(62, -23), Pair(-16, 5), Pair(2, -19),
      Pair(10, 16), Pair(26, 3), Pair(47, 11), Pair(72, 2), Pair(87, -4), Pair(65, 7), Pair(121, -24), Pair(34, 1),
      Pair(-3, 20), Pair(6, 16), Pair(37, 16), Pair(57, 9), Pair(70, 10), Pair(61, 2), Pair(72, -4), Pair(20, 0),
      Pair(-31, 8), Pair(-4, 16), Pair(7, 21), Pair(37, 24), Pair(55, 18), Pair(27, 14), Pair(31, 3), Pair(17, 12),
      Pair(-91, 42), Pair(-57, 28), Pair(-2, 16), Pair(13, 14), Pair(-2, 19), Pair(11, 19), Pair(-2, 8), Pair(-48, 38),
      Pair(-130, 31), Pair(-57, 15), Pair(-74, 31), Pair(-43, 20), Pair(23, 13), Pair(9, 9), Pair(-47, 32), Pair(-97, 24)
    },
    {
      Pair(-57, -5), Pair(16, -23), Pair(-30, -14), Pair(-9, -30), Pair(-51, -11), Pair(-38, -9), Pair(-7, -20), Pair(-144, -8),
      Pair(-36, -16), Pair(-48, -5), Pair(-26, -15), Pair(66, -38), Pair(-24, -28), Pair(-36, -18), Pair(-42, -11), Pair(-33, -6),
      Pair(-12, -6), Pair(32, -15), Pair(7, -16), Pair(20, -27), Pair(25, -32), Pair(32, -19), Pair(-15, -10), Pair(25, -19),
      Pair(37, -25), Pair(4, -16), Pair(21, -16), Pair(65, -34), Pair(57, -31), Pair(53, -25), Pair(28, -24), Pair(-6, -18),
      Pair(-16, -9), Pair(26, -15), Pair(13, -16), Pair(77, -24), Pair(27, -18), Pair(29, -10), Pair(11, -10), Pair(24, -23),
      Pair(2, -12), Pair(0, -11), Pair(23, -13), Pair(12, -8), Pair(37, -10), Pair(-8, -4), Pair(-1, -7), Pair(0, -5),
      Pair(-42, 12), Pair(-19, -10), Pair(9, -11), Pair(-1, -9), Pair(-12, -3), Pair(14, -16), Pair(21, -22), Pair(-43, -6),
      Pair(-3, -8), Pair(-15, -5), Pair(-12, -8), Pair(-43, -1), Pair(-14, -9), Pair(-18, -7), Pair(-41, -3), Pair(-40, -10)
    },
    {
      Pair(-76, 4), Pair(-62, 6), Pair(-23, -5), Pair(-7, -11), Pair(-43, -2), Pair(-85, 9), Pair(-23, -5), Pair(-43, -4),
      Pair(-48, -18), Pair(-26, -10), Pair(2, -20), Pair(33, -37), Pair(19, -35), Pair(32, -29), Pair(-14, -22), Pair(-36, -22),
      Pair(-20, -16), Pair(-7, -8), Pair(-3, -16), Pair(18, -33), Pair(-2, -30), Pair(1, -29), Pair(-57, 7), Pair(-102, 6),
      Pair(-41, -7), Pair(-9, -14), Pair(10, -16), Pair(18, -19), Pair(17, -32), Pair(41, -36), Pair(21, -24), Pair(-48, -16),
      Pair(-79, -4), Pair(-72, 5), Pair(-40, -9), Pair(-34, -15), Pair(-7, -29), Pair(8, -28), Pair(-11, -22), Pair(-54, -21),
      Pair(-66, -20), Pair(-49, -17), Pair(-44, -26), Pair(-23, -26), Pair(-16, -33), Pair(-14, -30), Pair(-7, -39), Pair(-70, -25),
      Pair(-71, -20), Pair(-52, -16), Pair(-35, -26), Pair(-56, -20), Pair(-33, -35), Pair(-24, -38), Pair(-37, -35), Pair(-86, -25),
      Pair(-65, -15), Pair(-73, -8), Pair(-45, -19), Pair(-33, -27), Pair(-36, -30), Pair(-35, -24), Pair(-60, -16), Pair(-66, -17)
    },
    {
      Pair(10, -27), Pair(45, -49), Pair(123, -75), Pair(216, -132), Pair(94, -55), Pair(71, -45), Pair(107, -94), Pair(15, -16),
      Pair(42, -66), Pair(-2, -42), Pair(-26, -4), Pair(-20, 0), Pair(52, -3), Pair(10, 1), Pair(53, -67), Pair(70, -50),
      Pair(-24, -16), Pair(0, -17), Pair(0, 18), Pair(37, -14), Pair(7, 25), Pair(83, -22), Pair(77, -45), Pair(106, -94),
      Pair(32, -45), Pair(24, -49), Pair(7, -4), Pair(88, -49), Pair(81, -53), Pair(104, -54), Pair(78, -43), Pair(75, -66),
      Pair(9, -36), Pair(17, -31), Pair(26, -42), Pair(44, -34), Pair(57, -60), Pair(44, -34), Pair(72, -68), Pair(75, -68),
      Pair(9, -67), Pair(14, -37), Pair(20, -30), Pair(10, -20), Pair(33, -24), Pair(46, -62), Pair(46, -74), Pair(56, -41),
      Pair(-2, -69), Pair(8, -67), Pair(2, -36), Pair(30, -34), Pair(29, -56), Pair(40, -61), Pair(26, -70), Pair(-34, -14),
      Pair(-31, -31), Pair(-25, -42), Pair(-5, -4), Pair(-7, -13), Pair(-47, -23), Pair(-8, -18), Pair(-39, -87), Pair(6, -102)
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
      Pair(-11, 33), Pair(231, -27), Pair(-78, 73), Pair(96, 18), Pair(-54, 58), Pair(-33, 63), Pair(-144, 118), Pair(-2, 52),
      Pair(-29, -11), Pair(12, -12), Pair(-32, -15), Pair(43, -27), Pair(48, -27), Pair(24, -20), Pair(-40, 19), Pair(106, -22),
      Pair(-45, -3), Pair(-2, -7), Pair(-2, -23), Pair(-3, -22), Pair(39, -32), Pair(38, -35), Pair(19, -4), Pair(37, -21),
      Pair(-40, -11), Pair(11, -12), Pair(-6, -26), Pair(22, -24), Pair(29, -28), Pair(15, -31), Pair(26, -11), Pair(20, -24),
      Pair(-56, -13), Pair(-21, -12), Pair(-17, -19), Pair(0, -13), Pair(16, -18), Pair(17, -23), Pair(10, -13), Pair(5, -25),
      Pair(-57, -3), Pair(13, -13), Pair(13, -22), Pair(20, -21), Pair(39, -25), Pair(41, -29), Pair(11, -16), Pair(-5, -17),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-104, -97), Pair(-83, -38), Pair(-234, 15), Pair(19, -52), Pair(-42, -20), Pair(-64, -27), Pair(-126, 27), Pair(-43, -85),
      Pair(-99, -32), Pair(-71, -7), Pair(-23, -13), Pair(143, -57), Pair(63, -24), Pair(26, -20), Pair(-33, -6), Pair(43, -39),
      Pair(-92, -8), Pair(-115, 0), Pair(34, -18), Pair(95, -32), Pair(79, -33), Pair(81, -55), Pair(-47, -18), Pair(-131, 11),
      Pair(-83, 1), Pair(0, 6), Pair(10, -5), Pair(120, -28), Pair(91, -21), Pair(74, -13), Pair(6, -26), Pair(-65, 4),
      Pair(-11, -19), Pair(66, -24), Pair(7, -4), Pair(119, -26), Pair(69, -20), Pair(136, -31), Pair(45, -5), Pair(51, -34),
      Pair(6, -23), Pair(32, -20), Pair(49, -18), Pair(71, -7), Pair(49, -6), Pair(26, -17), Pair(-94, 10), Pair(-126, 10),
      Pair(-168, 6), Pair(-21, -9), Pair(38, -3), Pair(-8, -4), Pair(32, -13), Pair(34, -17), Pair(-15, -16), Pair(-51, 6),
      Pair(-168, 9), Pair(-117, 13), Pair(55, -15), Pair(-31, -7), Pair(-97, 17), Pair(-60, 4), Pair(-67, 22), Pair(-27, -7)
    },
    {
      Pair(-133, -1), Pair(-54, -22), Pair(-32, -35), Pair(-28, -24), Pair(-85, -7), Pair(-33, -42), Pair(-16, -36), Pair(-4, -19),
      Pair(-57, -27), Pair(-23, -24), Pair(-130, -10), Pair(-33, -21), Pair(-39, -33), Pair(-57, -27), Pair(-58, -24), Pair(-134, -12),
      Pair(-13, -15), Pair(-37, -18), Pair(-37, -16), Pair(-87, -24), Pair(8, -35), Pair(-9, -26), Pair(-53, -13), Pair(22, -38),
      Pair(-93, -2), Pair(-32, -11), Pair(36, -31), Pair(55, -44), Pair(3, -26), Pair(42, -28), Pair(52, -34), Pair(50, -33),
      Pair(46, -30), Pair(13, -32), Pair(-4, -34), Pair(48, -38), Pair(-20, -31), Pair(-8, -33), Pair(-33, -17), Pair(-4, -26),
      Pair(-17, -18), Pair(-48, -12), Pair(10, -30), Pair(9, -25), Pair(64, -30), Pair(36, -19), Pair(71, -32), Pair(-52, -11),
      Pair(-232, 17), Pair(-13, -27), Pair(-3, -25), Pair(-1, -28), Pair(-7, -29), Pair(-37, -26), Pair(-16, -25), Pair(-59, -17),
      Pair(-238, 26), Pair(-187, 34), Pair(-50, -12), Pair(-102, -8), Pair(-46, -20), Pair(-54, -21), Pair(-29, -21), Pair(-170, 0)
    },
    {
      Pair(-116, -34), Pair(-169, -6), Pair(-151, -11), Pair(-130, -16), Pair(-139, -12), Pair(-23, -38), Pair(-60, -31), Pair(-108, -31),
      Pair(-121, -42), Pair(-12, -57), Pair(-111, -33), Pair(-79, -38), Pair(-44, -46), Pair(-49, -46), Pair(-3, -65), Pair(-55, -68),
      Pair(-80, -47), Pair(-82, -46), Pair(-27, -70), Pair(10, -69), Pair(52, -83), Pair(56, -80), Pair(-61, -54), Pair(-66, -62),
      Pair(-86, -47), Pair(75, -82), Pair(-107, -33), Pair(12, -83), Pair(11, -80), Pair(98, -107), Pair(135, -112), Pair(-57, -51),
      Pair(-117, -30), Pair(-106, -29), Pair(-118, -23), Pair(-35, -50), Pair(-75, -40), Pair(-5, -58), Pair(-37, -48), Pair(-129, -29),
      Pair(-155, -31), Pair(-34, -66), Pair(-76, -53), Pair(-90, -49), Pair(-85, -44), Pair(-50, -49), Pair(-40, -67), Pair(-114, -53),
      Pair(-152, -55), Pair(-127, -59), Pair(-76, -54), Pair(-69, -68), Pair(-83, -59), Pair(-82, -56), Pair(-71, -55), Pair(-120, -59),
      Pair(-93, -56), Pair(-80, -51), Pair(-48, -60), Pair(-65, -51), Pair(-62, -58), Pair(-52, -67), Pair(-115, -38), Pair(-110, -48)
    },
    {
      Pair(68, -194), Pair(102, -210), Pair(137, -195), Pair(95, -162), Pair(-27, -80), Pair(135, -180), Pair(138, -234), Pair(138, -204),
      Pair(43, -184), Pair(153, -188), Pair(187, -194), Pair(320, -265), Pair(352, -317), Pair(184, -204), Pair(123, -190), Pair(271, -292),
      Pair(108, -189), Pair(136, -208), Pair(82, -175), Pair(218, -210), Pair(249, -255), Pair(332, -308), Pair(282, -293), Pair(467, -429),
      Pair(130, -158), Pair(78, -92), Pair(16, -108), Pair(307, -271), Pair(241, -277), Pair(235, -227), Pair(202, -259), Pair(92, -108),
      Pair(-74, -86), Pair(109, -159), Pair(273, -221), Pair(68, -129), Pair(95, -146), Pair(207, -206), Pair(184, -187), Pair(36, -104),
      Pair(126, -221), Pair(54, -150), Pair(222, -222), Pair(81, -149), Pair(98, -170), Pair(163, -186), Pair(80, -186), Pair(45, -136),
      Pair(198, -259), Pair(71, -205), Pair(84, -191), Pair(-28, -105), Pair(60, -172), Pair(123, -214), Pair(77, -221), Pair(-1, -200),
      Pair(90, -162), Pair(87, -207), Pair(96, -216), Pair(87, -175), Pair(70, -171), Pair(-60, -114), Pair(49, -90), Pair(53, -88)
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
      Pair(-83, 43), Pair(161, 2), Pair(229, 1), Pair(-102, 54), Pair(71, 43), Pair(-2, 62), Pair(-107, 77), Pair(33, 31),
      Pair(67, -3), Pair(57, 9), Pair(82, -1), Pair(21, 10), Pair(104, 7), Pair(66, 8), Pair(112, 9), Pair(92, 2),
      Pair(4, -16), Pair(9, -14), Pair(35, -28), Pair(-56, -16), Pair(-7, -18), Pair(54, -30), Pair(2, -20), Pair(22, -25),
      Pair(18, -26), Pair(10, -15), Pair(48, -35), Pair(29, -27), Pair(39, -33), Pair(87, -42), Pair(50, -31), Pair(45, -32),
      Pair(1, -25), Pair(-12, -19), Pair(19, -30), Pair(1, -19), Pair(32, -27), Pair(59, -27), Pair(10, -21), Pair(28, -30),
      Pair(-16, -8), Pair(-7, -8), Pair(51, -27), Pair(-59, -17), Pair(90, -43), Pair(76, -26), Pair(48, -24), Pair(-22, -16),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-139, -118), Pair(-285, -51), Pair(-303, -51), Pair(-81, -71), Pair(-74, -77), Pair(-283, -61), Pair(-19, -132), Pair(55, -142),
      Pair(-61, -70), Pair(-27, -84), Pair(-91, -66), Pair(-74, -69), Pair(-14, -87), Pair(-75, -82), Pair(-49, -65), Pair(-128, -66),
      Pair(-201, -59), Pair(-69, -76), Pair(5, -75), Pair(67, -77), Pair(102, -90), Pair(24, -87), Pair(-87, -89), Pair(-134, -51),
      Pair(30, -100), Pair(-12, -70), Pair(89, -90), Pair(102, -92), Pair(173, -110), Pair(6, -67), Pair(-82, -79), Pair(132, -113),
      Pair(-90, -56), Pair(-67, -52), Pair(-34, -51), Pair(59, -62), Pair(44, -65), Pair(56, -71), Pair(55, -75), Pair(144, -99),
      Pair(-183, -73), Pair(14, -65), Pair(101, -86), Pair(163, -83), Pair(129, -70), Pair(74, -77), Pair(115, -86), Pair(-13, -71),
      Pair(-47, -108), Pair(-121, -54), Pair(-39, -74), Pair(-17, -56), Pair(58, -81), Pair(89, -88), Pair(-106, -38), Pair(8, -82),
      Pair(189, -100), Pair(-118, -53), Pair(118, -84), Pair(228, -108), Pair(72, -96), Pair(-38, -64), Pair(-29, -74), Pair(-119, -48)
    },
    {
      Pair(63, -79), Pair(-58, -50), Pair(30, -86), Pair(-144, -62), Pair(-72, -55), Pair(-288, -35), Pair(-61, -59), Pair(-42, -88),
      Pair(-194, -52), Pair(-77, -62), Pair(-76, -44), Pair(-76, -47), Pair(-73, -55), Pair(-50, -62), Pair(-70, -63), Pair(-93, -33),
      Pair(-209, -43), Pair(-15, -63), Pair(-85, -45), Pair(-151, -43), Pair(-129, -37), Pair(-138, -44), Pair(-125, -35), Pair(-79, -57),
      Pair(-49, -72), Pair(-109, -45), Pair(-139, -38), Pair(-82, -48), Pair(-54, -62), Pair(-166, -15), Pair(-208, -28), Pair(-174, -35),
      Pair(-106, -43), Pair(-80, -59), Pair(-36, -61), Pair(-86, -53), Pair(-33, -60), Pair(-50, -46), Pair(-94, -49), Pair(-13, -60),
      Pair(-103, -48), Pair(-53, -59), Pair(-130, -49), Pair(-90, -56), Pair(13, -87), Pair(-53, -61), Pair(-29, -79), Pair(-53, -73),
      Pair(-189, -11), Pair(-49, -86), Pair(-52, -66), Pair(-53, -72), Pair(-30, -74), Pair(-46, -76), Pair(-93, -52), Pair(-108, -66),
      Pair(-383, -33), Pair(-470, 46), Pair(-128, -51), Pair(-103, -44), Pair(-91, -64), Pair(-98, -45), Pair(-285, -16), Pair(-401, -25)
    },
    {
      Pair(-60, -155), Pair(-187, -117), Pair(-195, -102), Pair(-189, -98), Pair(-178, -112), Pair(-19, -141), Pair(-79, -126), Pair(-69, -146),
      Pair(-151, -137), Pair(-66, -146), Pair(-41, -140), Pair(-191, -110), Pair(-70, -150), Pair(-153, -117), Pair(-44, -146), Pair(-158, -126),
      Pair(-164, -129), Pair(-3, -163), Pair(-95, -148), Pair(-144, -134), Pair(-144, -132), Pair(-75, -149), Pair(-135, -131), Pair(-86, -152),
      Pair(-137, -125), Pair(19, -163), Pair(-157, -124), Pair(-108, -134), Pair(-127, -142), Pair(20, -173), Pair(-97, -135), Pair(-115, -139),
      Pair(-47, -156), Pair(-55, -155), Pair(105, -206), Pair(28, -194), Pair(18, -177), Pair(-55, -140), Pair(-123, -152), Pair(-185, -130),
      Pair(-126, -143), Pair(57, -170), Pair(-156, -129), Pair(-102, -139), Pair(-115, -148), Pair(-112, -143), Pair(-50, -148), Pair(-86, -153),
      Pair(-135, -143), Pair(-156, -132), Pair(-109, -146), Pair(-81, -149), Pair(-10, -182), Pair(-7, -176), Pair(-79, -162), Pair(-19, -182),
      Pair(-91, -154), Pair(-79, -155), Pair(-92, -154), Pair(-52, -164), Pair(-2, -179), Pair(-43, -167), Pair(-64, -160), Pair(-151, -138)
    },
    {
      Pair(-56, -383), Pair(-276, -238), Pair(-129, -296), Pair(45, -367), Pair(-4, -355), Pair(-340, -191), Pair(-280, -237), Pair(-315, -215),
      Pair(98, -434), Pair(-48, -358), Pair(-79, -331), Pair(-74, -287), Pair(-23, -331), Pair(-48, -306), Pair(6, -383), Pair(89, -404),
      Pair(-43, -328), Pair(85, -416), Pair(-183, -245), Pair(108, -408), Pair(-145, -248), Pair(105, -434), Pair(48, -397), Pair(-33, -328),
      Pair(-7, -361), Pair(53, -379), Pair(51, -369), Pair(95, -388), Pair(283, -493), Pair(34, -388), Pair(-205, -270), Pair(184, -450),
      Pair(131, -479), Pair(-81, -299), Pair(-24, -338), Pair(-445, -44), Pair(60, -378), Pair(-146, -232), Pair(51, -370), Pair(-115, -281),
      Pair(-119, -292), Pair(-110, -254), Pair(61, -366), Pair(72, -397), Pair(-20, -278), Pair(147, -450), Pair(-121, -274), Pair(76, -375),
      Pair(-15, -393), Pair(87, -395), Pair(-110, -287), Pair(68, -404), Pair(35, -364), Pair(-113, -356), Pair(96, -412), Pair(-34, -376),
      Pair(-134, -324), Pair(19, -420), Pair(166, -511), Pair(161, -463), Pair(29, -382), Pair(51, -412), Pair(-154, -279), Pair(-88, -378)
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
      Pair(-117, 59), Pair(-111, 45), Pair(143, 31), Pair(350, -7), Pair(41, 52), Pair(89, 29), Pair(-38, 23), Pair(-156, 54),
      Pair(1, 24), Pair(35, 15), Pair(152, 8), Pair(149, -36), Pair(105, 4), Pair(136, -18), Pair(-37, 41), Pair(160, -10),
      Pair(29, -3), Pair(82, -15), Pair(60, -7), Pair(-59, 9), Pair(-35, -14), Pair(134, -30), Pair(39, -10), Pair(63, -16),
      Pair(-1, -16), Pair(46, -23), Pair(15, -18), Pair(-36, -16), Pair(-42, -26), Pair(126, -47), Pair(36, -22), Pair(25, -23),
      Pair(23, -36), Pair(12, -56), Pair(97, -56), Pair(-80, -38), Pair(-26, -29), Pair(73, -59), Pair(36, -39), Pair(60, -45),
      Pair(5, -25), Pair(52, -27), Pair(157, -48), Pair(73, -17), Pair(-158, -9), Pair(104, -38), Pair(80, -37), Pair(26, -31),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(61, -220), Pair(-231, -151), Pair(-64, -113), Pair(-168, -112), Pair(-47, -134), Pair(-209, -72), Pair(-49, -105), Pair(-5, -121),
      Pair(-43, -80), Pair(-47, -44), Pair(-13, -116), Pair(22, -90), Pair(146, -164), Pair(-162, -74), Pair(-179, -91), Pair(-91, -131),
      Pair(82, -110), Pair(-108, -110), Pair(28, -113), Pair(-165, -74), Pair(-118, -99), Pair(-141, -41), Pair(131, -76), Pair(4, -102),
      Pair(6, -114), Pair(75, -76), Pair(118, -113), Pair(176, -121), Pair(199, -124), Pair(230, -142), Pair(44, -128), Pair(-193, -43),
      Pair(114, -161), Pair(83, -121), Pair(150, -62), Pair(218, -114), Pair(103, -125), Pair(-9, -83), Pair(31, -109), Pair(19, -61),
      Pair(-168, -88), Pair(118, -117), Pair(3, -80), Pair(376, -152), Pair(29, -64), Pair(41, -75), Pair(31, -91), Pair(226, -53),
      Pair(-80, -109), Pair(73, -107), Pair(19, -70), Pair(-98, -82), Pair(123, -116), Pair(-8, -112), Pair(-188, -93), Pair(-95, -103),
      Pair(42, -123), Pair(57, -96), Pair(56, -122), Pair(-27, -99), Pair(33, -129), Pair(-27, -121), Pair(22, -114), Pair(13, -42)
    },
    {
      Pair(-25, -66), Pair(34, -36), Pair(-175, -79), Pair(-67, -66), Pair(148, -64), Pair(-21, -110), Pair(108, -77), Pair(-134, -55),
      Pair(54, -83), Pair(-96, -71), Pair(-64, -69), Pair(-27, -97), Pair(98, -101), Pair(65, -118), Pair(29, -79), Pair(56, -98),
      Pair(-105, -68), Pair(9, -102), Pair(-54, -86), Pair(-46, -70), Pair(51, -96), Pair(-33, -75), Pair(-43, -68), Pair(-16, -61),
      Pair(32, -79), Pair(7, -105), Pair(-82, -74), Pair(-87, -43), Pair(-82, -78), Pair(-232, -34), Pair(41, -91), Pair(-125, -57),
      Pair(-148, -84), Pair(-104, -55), Pair(113, -110), Pair(16, -88), Pair(86, -90), Pair(-49, -48), Pair(-209, -48), Pair(-99, -29),
      Pair(-128, -28), Pair(137, -99), Pair(-134, -80), Pair(66, -64), Pair(-128, -61), Pair(-171, -52), Pair(-63, -53), Pair(-72, -58),
      Pair(-188, -30), Pair(-186, -52), Pair(-52, -85), Pair(-18, -94), Pair(-138, -67), Pair(-97, -95), Pair(25, -171), Pair(-41, -93),
      Pair(-80, -85), Pair(-119, -34), Pair(-199, -101), Pair(-88, -106), Pair(-201, -59), Pair(1, -108), Pair(-179, -61), Pair(-65, -154)
    },
    {
      Pair(36, -179), Pair(125, -190), Pair(-107, -149), Pair(153, -178), Pair(150, -216), Pair(81, -179), Pair(-150, -96), Pair(76, -183),
      Pair(122, -196), Pair(48, -182), Pair(95, -190), Pair(-183, -138), Pair(-62, -160), Pair(-148, -144), Pair(-182, -95), Pair(-156, -144),
      Pair(-102, -147), Pair(-29, -155), Pair(65, -192), Pair(-13, -167), Pair(-74, -135), Pair(-83, -155), Pair(-31, -155), Pair(131, -216),
      Pair(219, -215), Pair(123, -177), Pair(19, -172), Pair(99, -199), Pair(73, -200), Pair(108, -203), Pair(-46, -138), Pair(144, -200),
      Pair(28, -184), Pair(137, -201), Pair(2, -168), Pair(140, -210), Pair(61, -199), Pair(21, -166), Pair(68, -193), Pair(74, -191),
      Pair(-77, -143), Pair(-37, -139), Pair(92, -209), Pair(183, -236), Pair(186, -213), Pair(186, -224), Pair(-103, -144), Pair(-90, -136),
      Pair(68, -159), Pair(46, -161), Pair(199, -209), Pair(278, -264), Pair(228, -244), Pair(89, -176), Pair(101, -191), Pair(223, -237),
      Pair(-29, -155), Pair(40, -201), Pair(65, -202), Pair(-17, -194), Pair(19, -216), Pair(293, -275), Pair(57, -194), Pair(118, -199)
    },
    {
      Pair(-335, -206), Pair(41, -395), Pair(-136, -310), Pair(-89, -321), Pair(-368, -141), Pair(-211, -271), Pair(-323, -260), Pair(-58, -396),
      Pair(-26, -361), Pair(-63, -319), Pair(-108, -252), Pair(-163, -288), Pair(-63, -287), Pair(-249, -210), Pair(-137, -269), Pair(-140, -300),
      Pair(29, -350), Pair(-202, -268), Pair(-160, -239), Pair(-7, -348), Pair(-77, -305), Pair(-100, -340), Pair(-244, -258), Pair(-48, -319),
      Pair(-101, -281), Pair(-134, -289), Pair(174, -404), Pair(81, -383), Pair(55, -356), Pair(-33, -315), Pair(-16, -304), Pair(-135, -259),
      Pair(38, -375), Pair(135, -408), Pair(-2, -333), Pair(-193, -211), Pair(83, -331), Pair(-159, -232), Pair(-102, -278), Pair(-140, -251),
      Pair(-33, -425), Pair(224, -489), Pair(114, -355), Pair(142, -408), Pair(5, -327), Pair(-78, -311), Pair(-82, -329), Pair(-50, -273),
      Pair(-8, -382), Pair(-150, -303), Pair(-20, -306), Pair(62, -348), Pair(-12, -273), Pair(-194, -258), Pair(-63, -298), Pair(-85, -258),
      Pair(-86, -326), Pair(-164, -330), Pair(53, -325), Pair(-1, -366), Pair(-105, -315), Pair(-119, -360), Pair(117, -394), Pair(-146, -339)
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
  Pair(21, 322), Pair(33, 314), Pair(41, 334), Pair(46, 342), Pair(50, 349), Pair(54, 357), Pair(59, 357), Pair(61, 356),
  Pair(62, 349)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-77, -7), Pair(-68, -18), Pair(-59, -3), Pair(-54, 9), Pair(-49, 17), Pair(-46, 27), Pair(-44, 31), Pair(-41, 35),
  Pair(-41, 39), Pair(-36, 37), Pair(-29, 36), Pair(-25, 38), Pair(-29, 54), Pair(-27, 37)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-31, -49), Pair(-23, -23), Pair(-19, -15), Pair(-18, -3), Pair(-18, 2), Pair(-14, 4), Pair(-11, 7), Pair(-8, 10),
  Pair(-4, 13), Pair(-2, 17), Pair(1, 19), Pair(2, 23), Pair(7, 25), Pair(11, 25), Pair(9, 24)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(18, -27), Pair(61, -113), Pair(55, 83), Pair(62, 126), Pair(62, 163), Pair(64, 180), Pair(67, 193), Pair(68, 205),
  Pair(70, 213), Pair(73, 214), Pair(75, 220), Pair(76, 228), Pair(79, 224), Pair(79, 229), Pair(81, 229), Pair(84, 227),
  Pair(83, 231), Pair(85, 231), Pair(93, 223), Pair(104, 212), Pair(110, 206), Pair(143, 184), Pair(139, 178), Pair(149, 162),
  Pair(184, 152), Pair(273, 84), Pair(269, 83), Pair(210, 96)
};

constexpr KingBuckets<RankTable<ScorePair>> kPassedPawnBonus = {{
  {
      Pair(0, 0), Pair(20, -104), Pair(25, -97), Pair(26, -64), Pair(46, -25), Pair(48, 7), Pair(64, 127), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(31, -110), Pair(31, -104), Pair(29, -74), Pair(42, -32), Pair(44, 26), Pair(102, 103), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, -100), Pair(13, -86), Pair(16, -56), Pair(39, -22), Pair(54, 38), Pair(87, 80), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-5, -91), Pair(-7, -71), Pair(-4, -38), Pair(32, -6), Pair(30, 70), Pair(114, 82), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-30, -75), Pair(-49, -50), Pair(-57, -19), Pair(-36, 18), Pair(-76, 120), Pair(82, 97), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-55, -68), Pair(-84, -54), Pair(-128, -5), Pair(-159, 60), Pair(-242, 130), Pair(100, 79), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-80, -67), Pair(-91, -42), Pair(-96, -12), Pair(-144, 45), Pair(-156, 99), Pair(42, 82), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPawnPhalanxBonus = {{
  {
      Pair(0, 0), Pair(7, -3), Pair(13, 1), Pair(16, 12), Pair(44, 49), Pair(130, 134), Pair(220, 570), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(6, 2), Pair(18, 5), Pair(22, 9), Pair(52, 47), Pair(360, 133), Pair(135, 390), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 1), Pair(11, 10), Pair(27, 13), Pair(37, 65), Pair(-57, 350), Pair(-153, 503), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(1, 4), Pair(-3, 14), Pair(24, 20), Pair(-5, 70), Pair(-89, 227), Pair(-25, 472), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-16, 17), Pair(4, 14), Pair(-22, 21), Pair(-64, 85), Pair(54, 198), Pair(-6, 423), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(6, 4), Pair(-27, 5), Pair(-68, 36), Pair(-129, 94), Pair(-201, 222), Pair(-282, 322), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-37, -10), Pair(-43, 14), Pair(2, 12), Pair(-238, 90), Pair(-104, 110), Pair(-135, 209), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kDefendedPawnBonus = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(20, 13), Pair(12, 12), Pair(13, 15), Pair(17, 57), Pair(171, 13), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(22, 9), Pair(13, 6), Pair(10, 14), Pair(25, 51), Pair(310, 27), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(18, 11), Pair(11, 8), Pair(10, 17), Pair(18, 50), Pair(90, 39), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(13, 12), Pair(6, 7), Pair(4, 17), Pair(17, 41), Pair(129, 46), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(13, 12), Pair(-14, 11), Pair(-8, 21), Pair(22, 40), Pair(-28, 135), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-14, 9), Pair(-29, 9), Pair(-43, 20), Pair(66, 6), Pair(-231, 122), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-44, 21), Pair(22, -2), Pair(-45, 4), Pair(56, 37), Pair(-204, 147), Pair(0, 0)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kDoubledPawnPenalty = {{
  {
      Pair(-11, -52), Pair(12, -50), Pair(-1, -26), Pair(-3, -11), Pair(-11, -7), Pair(-12, -13), Pair(11, -36), Pair(-3, -50)
  },
  {
      Pair(1, -42), Pair(13, -35), Pair(7, -24), Pair(3, -23), Pair(-2, -4), Pair(-4, -19), Pair(1, -24), Pair(-9, -33)
  },
  {
      Pair(-8, -41), Pair(16, -36), Pair(9, -26), Pair(11, -15), Pair(-2, -6), Pair(1, -20), Pair(9, -25), Pair(-12, -47)
  },
  {
      Pair(-11, -34), Pair(18, -28), Pair(7, -29), Pair(32, -14), Pair(35, -10), Pair(-7, -16), Pair(20, -23), Pair(-34, -25)
  },
  {
      Pair(-27, -39), Pair(-18, -21), Pair(36, -23), Pair(-32, -7), Pair(65, -23), Pair(26, -19), Pair(-1, -24), Pair(-35, -38)
  },
  {
      Pair(-27, -38), Pair(-24, -14), Pair(9, -33), Pair(38, -37), Pair(-160, 17), Pair(22, -33), Pair(31, -17), Pair(-22, -33)
  },
  {
      Pair(-302, 47), Pair(-178, 23), Pair(-122, -4), Pair(-114, -10), Pair(54, -40), Pair(-255, -6), Pair(-70, 8), Pair(-46, -42)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kIsolatedPawnPenalty = {{
  {
      Pair(-7, 19), Pair(0, -14), Pair(-11, -5), Pair(-9, -9), Pair(-14, -8), Pair(-8, -3), Pair(2, -13), Pair(-5, 11)
  },
  {
      Pair(1, 9), Pair(0, -8), Pair(-12, -6), Pair(-9, -16), Pair(-10, -17), Pair(4, -11), Pair(-1, -14), Pair(-7, 7)
  },
  {
      Pair(-5, 12), Pair(-2, -12), Pair(-13, -4), Pair(-3, -13), Pair(-6, -17), Pair(-1, -8), Pair(-3, -10), Pair(-3, 2)
  },
  {
      Pair(-4, 3), Pair(-4, -9), Pair(-17, -3), Pair(11, -21), Pair(-4, -21), Pair(5, -9), Pair(-8, -11), Pair(-17, 4)
  },
  {
      Pair(16, -2), Pair(-31, -7), Pair(-10, -5), Pair(10, -20), Pair(-1, -19), Pair(1, -7), Pair(3, -11), Pair(-27, 7)
  },
  {
      Pair(-5, -3), Pair(8, -12), Pair(-24, -1), Pair(45, -19), Pair(14, -13), Pair(-4, -6), Pair(6, -9), Pair(-19, 0)
  },
  {
      Pair(63, -26), Pair(81, -24), Pair(-27, 4), Pair(29, -13), Pair(83, -17), Pair(75, -4), Pair(43, -22), Pair(14, -14)
  }
}};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(19, 5), Pair(18, 2), Pair(18, 7), Pair(19, 6), Pair(19, 11), Pair(28, 4), Pair(41, -1), Pair(69, -6)
  },
  {
      Pair(8, 32), Pair(8, 8), Pair(11, 8), Pair(18, -1), Pair(14, 0), Pair(16, -4), Pair(23, -4), Pair(24, 13)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -3), Pair(17, -4), Pair(9, 0),
  Pair(20, -9), Pair(19, -10), Pair(20, -10),
  Pair(29, -2), Pair(0, 0), Pair(26, -1),
  Pair(-6, 5), Pair(3, -5), Pair(-8, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 3), Pair(-14, 5), Pair(-8, 5),
  Pair(-7, 2), Pair(-17, 7), Pair(-9, 4),
  Pair(-2, -3), Pair(-15, 5), Pair(-3, -2),
  Pair(11, -5), Pair(-4, -2), Pair(10, -4),
  Pair(20, -10), Pair(21, 0), Pair(14, -11),
  Pair(0, 0), Pair(-6, -14), Pair(0, 0),
  Pair(40, -36), Pair(0, 0), Pair(31, -34)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-16, 110), Pair(-17, 95), Pair(-12, 79), Pair(-10, 69), Pair(-8, 68), Pair(-3, 67), Pair(-11, 65)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-37, -48), Pair(-17, -30), Pair(-18, -4), Pair(-16, 10), Pair(-16, 19), Pair(-15, 24), Pair(-20, 15)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-2560, 184);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-63, -8), Pair(-71, -5), Pair(-26, -11), Pair(-23, -7), Pair(-15, -4), Pair(-27, -3), Pair(-49, 1), Pair(-35, 6)
  },
  {
      Pair(-6, 41), Pair(-34, 18), Pair(-12, 9), Pair(3, 0), Pair(-1, -4), Pair(-1, 2), Pair(-24, 17), Pair(-14, 28)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 1), Pair(23, -6), Pair(46, -20), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 1), Pair(25, -1), Pair(58, -7), Pair(65, -35), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(18, -18), Pair(32, -17), Pair(49, -13), Pair(72, -13), Pair(84, -22), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 10), Pair(10, 23), Pair(28, 27), Pair(67, 15), Pair(99, 10), Pair(156, -11), Pair(200, -47)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(44, 9), Pair(19, 21), Pair(53, 0), Pair(24, 13), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-17, 13), Pair(-11, 17)
  },
  {
      Pair(-63, -22), Pair(-63, -29)
  },
  {
      Pair(-55, -44), Pair(-62, -69)
  },
  {
      Pair(-89, 2), Pair(-79, -32)
  },
  {
      Pair(-71, 32), Pair(-78, 14)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(15, 30), Pair(19, 20), Pair(27, 10), Pair(21, -3), Pair(52, -3)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-2, -18), Pair(8, -11)
  },
  {
      Pair(-21, -41), Pair(-3, -55)
  },
  {
      Pair(-40, -32), Pair(-27, -32)
  },
  {
      Pair(-78, -2), Pair(-58, -26)
  },
  {
      Pair(-54, 33), Pair(-55, 20)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-10, -19), Pair(1, -8)
  },
  {
      Pair(-46, -23), Pair(-20, -25)
  },
  {
      Pair(21, -132), Pair(31, -125)
  },
  {
      Pair(-77, -7), Pair(-44, -36)
  },
  {
      Pair(-80, -15), Pair(-57, -85)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-2, -23), Pair(10, -9)
  },
  {
      Pair(-38, -25), Pair(-3, -13)
  },
  {
      Pair(-28, -26), Pair(-12, -4)
  },
  {
      Pair(-1, -55), Pair(13, -32)
  },
  {
      Pair(-79, 7), Pair(-58, -41)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(21, 18), Pair(17, 10), Pair(37, 20), Pair(44, 22), Pair(45, 27), Pair(25, 43), Pair(35, 14), Pair(3, 40),
  Pair(4, 13), Pair(12, 17), Pair(17, 21), Pair(9, 32), Pair(13, 24), Pair(10, 21), Pair(12, 16), Pair(-5, 27),
  Pair(8, 11), Pair(5, 4), Pair(1, 17), Pair(8, 18), Pair(6, 21), Pair(-7, 20), Pair(2, 7), Pair(0, 9)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-10, 12), Pair(21, -2), Pair(29, 2), Pair(41, 4), Pair(67, -11), Pair(49, -1), Pair(24, -7), Pair(-15, -17),
  Pair(-19, -15), Pair(18, 7), Pair(11, 3), Pair(23, 12), Pair(14, 5), Pair(16, -3), Pair(12, 9), Pair(15, -18),
  Pair(-20, 26), Pair(9, 4), Pair(3, 20), Pair(18, 14), Pair(22, 22), Pair(2, 8), Pair(13, 0), Pair(-43, 5)
};

constexpr ScorePair kBishopPairBonus = Pair(17, 55);

constexpr ScorePair kTempoBonus = Pair(29, 26);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H