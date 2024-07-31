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
  Pair(77, 140), Pair(332, 291), Pair(380, 412), Pair(465, 732), Pair(914, 1275), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-15, 57), Pair(-41, 71), Pair(-19, 13), Pair(1, -19), Pair(31, -47), Pair(29, -35), Pair(-58, -12), Pair(-73, 48),
      Pair(1, 45), Pair(-6, 39), Pair(30, -9), Pair(41, -53), Pair(57, -55), Pair(97, -59), Pair(44, 3), Pair(34, 13),
      Pair(-19, 11), Pair(-8, 1), Pair(-4, -21), Pair(-4, -39), Pair(23, -49), Pair(25, -51), Pair(-9, -12), Pair(8, -25),
      Pair(-23, -13), Pair(-19, -6), Pair(-9, -28), Pair(2, -35), Pair(7, -40), Pair(18, -51), Pair(-13, -22), Pair(9, -42),
      Pair(-34, -16), Pair(-30, -14), Pair(-20, -25), Pair(-14, -25), Pair(-5, -24), Pair(-7, -37), Pair(-14, -30), Pair(5, -52),
      Pair(-22, -9), Pair(-19, -3), Pair(-14, -12), Pair(-8, -26), Pair(0, -1), Pair(11, -22), Pair(-1, -15), Pair(-4, -46),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-135, -2), Pair(-134, 63), Pair(-69, 38), Pair(-45, 22), Pair(-38, 26), Pair(-24, -36), Pair(-112, 11), Pair(-80, -67),
      Pair(-22, 36), Pair(-15, 59), Pair(-3, 43), Pair(-1, 46), Pair(8, 18), Pair(51, 15), Pair(31, 4), Pair(-5, -11),
      Pair(-8, 47), Pair(8, 47), Pair(6, 65), Pair(20, 44), Pair(35, 31), Pair(80, 0), Pair(9, 33), Pair(29, -6),
      Pair(11, 52), Pair(18, 54), Pair(36, 53), Pair(39, 67), Pair(37, 59), Pair(48, 54), Pair(29, 56), Pair(38, 24),
      Pair(-9, 46), Pair(18, 45), Pair(28, 61), Pair(33, 56), Pair(32, 64), Pair(46, 36), Pair(32, 44), Pair(8, 43),
      Pair(-24, 32), Pair(-2, 41), Pair(7, 48), Pair(19, 60), Pair(34, 55), Pair(20, 42), Pair(19, 38), Pair(0, 38),
      Pair(-34, 29), Pair(-20, 38), Pair(-8, 34), Pair(10, 39), Pair(9, 42), Pair(6, 24), Pair(5, 30), Pair(0, 46),
      Pair(-55, 7), Pair(-21, 28), Pair(-19, 30), Pair(0, 30), Pair(4, 37), Pair(9, 23), Pair(-16, 25), Pair(-24, 11)
    },
    {
      Pair(-29, 41), Pair(-72, 29), Pair(-63, 17), Pair(-115, 36), Pair(-93, 17), Pair(-54, -13), Pair(-88, 60), Pair(-34, -5),
      Pair(-30, 20), Pair(-20, 29), Pair(-11, 10), Pair(-29, 24), Pair(-25, 3), Pair(-24, 14), Pair(-60, 32), Pair(-49, 1),
      Pair(-10, 29), Pair(-5, 32), Pair(-14, 25), Pair(-14, 13), Pair(-24, 23), Pair(20, 29), Pair(10, 24), Pair(-4, 37),
      Pair(-27, 27), Pair(-12, 34), Pair(-6, 26), Pair(-3, 44), Pair(2, 21), Pair(4, 25), Pair(-11, 27), Pair(-20, 22),
      Pair(-20, 24), Pair(-25, 25), Pair(-14, 31), Pair(-1, 16), Pair(-2, 14), Pair(-6, 11), Pair(-19, 22), Pair(-1, -3),
      Pair(-18, 6), Pair(2, 28), Pair(-1, 23), Pair(-6, 28), Pair(-2, 38), Pair(4, 25), Pair(12, 8), Pair(8, 10),
      Pair(-1, 5), Pair(-1, -5), Pair(7, -1), Pair(-9, 16), Pair(3, 16), Pair(13, 23), Pair(27, 12), Pair(16, -6),
      Pair(-2, -10), Pair(19, -2), Pair(-4, 12), Pair(-7, 8), Pair(8, 3), Pair(12, 15), Pair(19, 1), Pair(33, -44)
    },
    {
      Pair(23, 29), Pair(21, 42), Pair(12, 52), Pair(3, 45), Pair(39, 23), Pair(26, 35), Pair(38, 44), Pair(-4, 32),
      Pair(8, 34), Pair(16, 44), Pair(24, 48), Pair(34, 35), Pair(16, 29), Pair(37, 28), Pair(72, 16), Pair(45, 15),
      Pair(2, 34), Pair(44, 31), Pair(30, 35), Pair(31, 22), Pair(57, 7), Pair(80, -4), Pair(128, -25), Pair(56, -8),
      Pair(18, 26), Pair(27, 35), Pair(38, 31), Pair(32, 22), Pair(44, 8), Pair(46, 12), Pair(58, 4), Pair(33, -3),
      Pair(0, 20), Pair(2, 39), Pair(12, 26), Pair(15, 27), Pair(16, 19), Pair(1, 26), Pair(40, 2), Pair(17, -3),
      Pair(-10, 22), Pair(-1, 24), Pair(5, 26), Pair(4, 28), Pair(15, 14), Pair(14, 11), Pair(53, -20), Pair(32, -32),
      Pair(-10, 11), Pair(-5, 26), Pair(13, 17), Pair(12, 24), Pair(19, 8), Pair(17, 4), Pair(41, -12), Pair(10, -29),
      Pair(1, 24), Pair(9, 16), Pair(13, 20), Pair(18, 15), Pair(24, 6), Pair(21, 14), Pair(20, 4), Pair(-17, 12)
    },
    {
      Pair(24, 47), Pair(24, 49), Pair(40, 49), Pair(78, 18), Pair(58, 35), Pair(57, 56), Pair(115, -16), Pair(54, 51),
      Pair(38, 48), Pair(37, 49), Pair(37, 78), Pair(33, 71), Pair(3, 120), Pair(37, 98), Pair(36, 80), Pair(90, 48),
      Pair(45, 50), Pair(45, 58), Pair(45, 77), Pair(42, 88), Pair(41, 90), Pair(65, 102), Pair(71, 80), Pair(60, 64),
      Pair(38, 61), Pair(51, 58), Pair(50, 62), Pair(43, 79), Pair(46, 96), Pair(68, 52), Pair(62, 80), Pair(69, 48),
      Pair(36, 54), Pair(34, 76), Pair(40, 72), Pair(39, 89), Pair(52, 69), Pair(40, 73), Pair(61, 52), Pair(58, 53),
      Pair(40, 40), Pair(42, 58), Pair(39, 77), Pair(36, 75), Pair(38, 79), Pair(50, 60), Pair(68, 40), Pair(65, 5),
      Pair(42, 28), Pair(44, 38), Pair(45, 45), Pair(47, 60), Pair(52, 46), Pair(61, 13), Pair(66, 3), Pair(74, -45),
      Pair(34, 48), Pair(37, 43), Pair(42, 38), Pair(44, 42), Pair(50, 22), Pair(44, 7), Pair(47, -27), Pair(26, 32)
    },
    {
      Pair(1003, -147), Pair(968, -92), Pair(931, -70), Pair(865, -39), Pair(858, -44), Pair(839, -36), Pair(916, -55), Pair(1040, -155),
      Pair(883, -72), Pair(956, -38), Pair(883, -21), Pair(960, -32), Pair(898, -21), Pair(900, -9), Pair(954, -24), Pair(940, -57),
      Pair(878, -43), Pair(1013, -28), Pair(910, -2), Pair(871, 10), Pair(896, 13), Pair(960, -3), Pair(905, -1), Pair(892, -42),
      Pair(921, -65), Pair(952, -38), Pair(896, -13), Pair(837, 3), Pair(834, 2), Pair(858, -5), Pair(884, -26), Pair(799, -39),
      Pair(447, -76), Pair(462, -45), Pair(383, -13), Pair(348, 3), Pair(349, -2), Pair(380, -18), Pair(384, -33), Pair(336, -51),
      Pair(240, -49), Pair(274, -25), Pair(204, 3), Pair(199, 14), Pair(198, 12), Pair(199, 0), Pair(233, -21), Pair(207, -41),
      Pair(46, -33), Pair(6, 10), Pair(-7, 22), Pair(-26, 33), Pair(-31, 35), Pair(-13, 23), Pair(4, 5), Pair(21, -27),
      Pair(-95, -20), Pair(-68, 13), Pair(7, 29), Pair(-46, 46), Pair(-8, 33), Pair(-32, 38), Pair(-93, 22), Pair(-89, -22)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(14, 101), Pair(-9, 120), Pair(-18, 90), Pair(53, 65), Pair(-1, 50), Pair(-25, 40), Pair(-37, 65), Pair(-63, 82),
      Pair(22, 25), Pair(-7, 45), Pair(31, -10), Pair(41, -46), Pair(38, -46), Pair(60, -39), Pair(8, 31), Pair(0, 12),
      Pair(11, 1), Pair(-1, -8), Pair(4, -24), Pair(9, -46), Pair(25, -51), Pair(13, -47), Pair(2, -15), Pair(-4, -10),
      Pair(12, -21), Pair(-11, -7), Pair(10, -37), Pair(21, -44), Pair(15, -43), Pair(12, -47), Pair(4, -25), Pair(-9, -25),
      Pair(9, -28), Pair(-9, -15), Pair(-4, -30), Pair(-9, -29), Pair(-6, -31), Pair(-11, -36), Pair(2, -30), Pair(-16, -29),
      Pair(10, -16), Pair(-2, -4), Pair(-1, -12), Pair(-25, -11), Pair(-25, 0), Pair(-5, -20), Pair(4, -16), Pair(-9, -18),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-149, -92), Pair(-231, 83), Pair(-120, 6), Pair(-94, 26), Pair(2, -20), Pair(-53, -53), Pair(-111, 28), Pair(-114, -89),
      Pair(-93, 31), Pair(-32, 24), Pair(-9, 11), Pair(-41, 26), Pair(-22, 19), Pair(8, 8), Pair(-56, 12), Pair(-7, -15),
      Pair(-58, 42), Pair(0, 40), Pair(-33, 60), Pair(7, 30), Pair(2, 33), Pair(10, 18), Pair(-27, 36), Pair(-25, 14),
      Pair(-2, 45), Pair(0, 50), Pair(16, 47), Pair(27, 44), Pair(25, 41), Pair(32, 45), Pair(13, 34), Pair(15, 20),
      Pair(-14, 47), Pair(7, 51), Pair(17, 47), Pair(23, 47), Pair(23, 52), Pair(35, 33), Pair(18, 50), Pair(-1, 26),
      Pair(-35, 35), Pair(-6, 42), Pair(10, 35), Pair(14, 52), Pair(26, 50), Pair(8, 32), Pair(11, 24), Pair(-15, 31),
      Pair(-38, 44), Pair(-13, 39), Pair(-3, 43), Pair(-7, 43), Pair(1, 32), Pair(0, 27), Pair(-9, 26), Pair(-32, 17),
      Pair(-79, 13), Pair(-34, 33), Pair(-23, 30), Pair(-18, 44), Pair(-8, 43), Pair(-21, 24), Pair(-34, 33), Pair(-30, -11)
    },
    {
      Pair(-85, 16), Pair(-88, 30), Pair(-116, 16), Pair(-146, 34), Pair(-221, 68), Pair(-171, 9), Pair(-59, 15), Pair(-98, 5),
      Pair(-79, 1), Pair(-47, 9), Pair(-48, 5), Pair(-70, 16), Pair(-79, 14), Pair(-43, 7), Pair(-58, 3), Pair(-42, -4),
      Pair(-36, 25), Pair(-48, 38), Pair(-49, 32), Pair(-15, 5), Pair(-38, 12), Pair(-22, 10), Pair(-12, 19), Pair(-10, 11),
      Pair(-34, 28), Pair(-13, 18), Pair(-23, 22), Pair(-16, 21), Pair(-17, 14), Pair(-10, 32), Pair(-25, 23), Pair(-32, 28),
      Pair(-20, -3), Pair(-59, 38), Pair(-7, -5), Pair(-7, 6), Pair(-3, 1), Pair(-19, 8), Pair(-30, 20), Pair(-24, -2),
      Pair(-32, 14), Pair(4, 8), Pair(-4, 21), Pair(-7, 24), Pair(-6, 28), Pair(1, 16), Pair(-5, 11), Pair(-18, -3),
      Pair(-4, -6), Pair(2, 5), Pair(13, -4), Pair(-15, 26), Pair(-3, 15), Pair(2, -2), Pair(3, 2), Pair(-10, -9),
      Pair(-21, 0), Pair(-5, 12), Pair(-26, 16), Pair(-9, 8), Pair(-5, -2), Pair(-29, 19), Pair(-42, 29), Pair(-18, -10)
    },
    {
      Pair(7, 24), Pair(-79, 51), Pair(-32, 29), Pair(-17, 29), Pair(-77, 42), Pair(-73, 49), Pair(-55, 42), Pair(-52, 47),
      Pair(-35, 18), Pair(-36, 33), Pair(-29, 25), Pair(-12, 26), Pair(27, -1), Pair(-10, 10), Pair(-26, 18), Pair(-38, 21),
      Pair(-23, 6), Pair(-1, 17), Pair(-40, 22), Pair(1, 3), Pair(29, -17), Pair(-11, -2), Pair(26, 0), Pair(-18, -4),
      Pair(-28, 11), Pair(12, -1), Pair(-16, 29), Pair(-19, 23), Pair(-14, 10), Pair(9, -1), Pair(2, -3), Pair(-25, 4),
      Pair(-16, 9), Pair(-42, 21), Pair(-30, 11), Pair(-18, 19), Pair(-18, 12), Pair(-33, 7), Pair(-17, 1), Pair(-42, -5),
      Pair(-25, 1), Pair(-14, 15), Pair(-30, 11), Pair(-28, 15), Pair(-20, 3), Pair(-20, -1), Pair(-3, -19), Pair(-30, -13),
      Pair(-28, -15), Pair(-32, 11), Pair(-15, 11), Pair(-23, -7), Pair(-6, -16), Pair(-22, 3), Pair(-16, -23), Pair(-41, -27),
      Pair(-10, -18), Pair(-23, -6), Pair(-24, 11), Pair(-10, -5), Pair(-1, -14), Pair(-27, -13), Pair(-18, -19), Pair(-20, -33)
    },
    {
      Pair(-97, 55), Pair(-112, 74), Pair(-56, 61), Pair(-34, 45), Pair(-50, 60), Pair(-73, 64), Pair(-81, 69), Pair(-59, -2),
      Pair(-40, -17), Pair(-65, 52), Pair(-64, 68), Pair(-111, 121), Pair(-125, 133), Pair(-66, 91), Pair(-40, 41), Pair(-9, 50),
      Pair(-33, 28), Pair(-40, 9), Pair(-52, 67), Pair(-30, 42), Pair(-50, 93), Pair(-26, 55), Pair(-4, 22), Pair(3, 55),
      Pair(-29, 15), Pair(-26, 30), Pair(-19, 47), Pair(-36, 73), Pair(-34, 57), Pair(-9, 33), Pair(2, 27), Pair(-10, 46),
      Pair(-19, 1), Pair(-41, 70), Pair(-24, 32), Pair(-25, 101), Pair(-29, 84), Pair(-22, 38), Pair(-14, 33), Pair(-15, 18),
      Pair(-27, 5), Pair(-14, 27), Pair(-19, 56), Pair(-30, 61), Pair(-19, 51), Pair(-18, 55), Pair(-8, 29), Pair(-12, 44),
      Pair(-20, -31), Pair(-5, -48), Pair(-4, -30), Pair(-9, 5), Pair(-12, 11), Pair(-15, 7), Pair(15, -58), Pair(10, -42),
      Pair(-22, -50), Pair(-16, -59), Pair(-13, -28), Pair(-14, -40), Pair(-23, -22), Pair(-21, -53), Pair(-11, -51), Pair(5, -45)
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
      Pair(100, 79), Pair(44, 96), Pair(56, 83), Pair(107, 23), Pair(71, 24), Pair(82, 41), Pair(8, 80), Pair(-13, 98),
      Pair(8, 19), Pair(10, 20), Pair(23, -7), Pair(42, -46), Pair(64, -57), Pair(86, -39), Pair(45, 14), Pair(6, 21),
      Pair(-15, 4), Pair(-10, 1), Pair(-8, -18), Pair(6, -37), Pair(34, -41), Pair(26, -38), Pair(12, -9), Pair(-17, -10),
      Pair(-20, -11), Pair(-17, -2), Pair(-9, -22), Pair(4, -29), Pair(13, -33), Pair(14, -34), Pair(1, -15), Pair(-25, -22),
      Pair(-38, -12), Pair(-30, -4), Pair(-23, -18), Pair(-16, -19), Pair(-12, -19), Pair(-10, -24), Pair(-1, -21), Pair(-38, -23),
      Pair(-26, -10), Pair(-17, -2), Pair(-12, -15), Pair(-26, -9), Pair(0, -15), Pair(25, -23), Pair(22, -19), Pair(-35, -20),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-178, -12), Pair(-147, 23), Pair(-134, 41), Pair(3, -1), Pair(60, -6), Pair(-141, 24), Pair(-250, 57), Pair(-157, -44),
      Pair(-70, 41), Pair(-41, 38), Pair(-14, 33), Pair(54, 20), Pair(14, 20), Pair(45, 5), Pair(-8, 33), Pair(-6, 5),
      Pair(-37, 36), Pair(-3, 35), Pair(0, 56), Pair(27, 34), Pair(22, 38), Pair(76, -1), Pair(27, 8), Pair(43, 3),
      Pair(-29, 44), Pair(10, 42), Pair(34, 50), Pair(55, 38), Pair(45, 46), Pair(72, 36), Pair(34, 39), Pair(57, 22),
      Pair(-16, 50), Pair(11, 43), Pair(23, 59), Pair(41, 50), Pair(43, 51), Pair(55, 38), Pair(58, 30), Pair(18, 38),
      Pair(-37, 35), Pair(-10, 39), Pair(13, 41), Pair(21, 58), Pair(44, 49), Pair(20, 31), Pair(27, 22), Pair(5, 27),
      Pair(-46, 30), Pair(-45, 44), Pair(-17, 46), Pair(6, 35), Pair(12, 28), Pair(9, 38), Pair(3, 17), Pair(-1, 30),
      Pair(-104, 61), Pair(-34, 36), Pair(-14, 31), Pair(-8, 47), Pair(2, 38), Pair(11, 27), Pair(-9, 31), Pair(-42, 36)
    },
    {
      Pair(-68, 32), Pair(-65, 17), Pair(-121, 32), Pair(-129, 33), Pair(-86, 21), Pair(-117, 34), Pair(-59, 22), Pair(-120, 38),
      Pair(-48, 15), Pair(-31, 19), Pair(-24, 9), Pair(-69, 29), Pair(-50, 20), Pair(-37, 15), Pair(-59, 30), Pair(-37, 17),
      Pair(-33, 24), Pair(-20, 20), Pair(-17, 18), Pair(-26, 13), Pair(3, 7), Pair(20, 16), Pair(5, 23), Pair(5, 22),
      Pair(-27, 19), Pair(-10, 16), Pair(-4, 20), Pair(22, 17), Pair(15, 16), Pair(18, 14), Pair(-12, 14), Pair(-5, 10),
      Pair(-31, 14), Pair(-40, 27), Pair(-5, 12), Pair(4, 18), Pair(9, 8), Pair(-13, 23), Pair(-10, 15), Pair(-13, 12),
      Pair(-37, 22), Pair(5, 14), Pair(0, 15), Pair(5, 18), Pair(3, 26), Pair(5, 14), Pair(12, 13), Pair(-3, -7),
      Pair(-24, 12), Pair(-15, -5), Pair(2, 1), Pair(-13, 8), Pair(0, 7), Pair(4, 3), Pair(20, -9), Pair(-15, -6),
      Pair(-39, 10), Pair(-1, 21), Pair(-1, 8), Pair(-11, 18), Pair(-8, 19), Pair(-21, 27), Pair(7, 0), Pair(-39, -5)
    },
    {
      Pair(-24, 35), Pair(1, 45), Pair(-16, 48), Pair(2, 42), Pair(-10, 34), Pair(32, 33), Pair(-14, 51), Pair(-21, 42),
      Pair(-12, 28), Pair(1, 39), Pair(22, 34), Pair(48, 24), Pair(40, 20), Pair(60, 22), Pair(23, 28), Pair(1, 25),
      Pair(-5, 25), Pair(17, 28), Pair(20, 26), Pair(22, 18), Pair(48, 2), Pair(60, 5), Pair(69, 9), Pair(7, 10),
      Pair(-29, 40), Pair(30, 27), Pair(11, 33), Pair(22, 23), Pair(31, 5), Pair(40, 9), Pair(34, 16), Pair(-7, 16),
      Pair(-49, 34), Pair(-12, 31), Pair(-15, 30), Pair(1, 24), Pair(-6, 18), Pair(-18, 29), Pair(-1, 16), Pair(-23, 15),
      Pair(-32, 17), Pair(-27, 23), Pair(-20, 15), Pair(-15, 18), Pair(-6, 15), Pair(-8, 10), Pair(12, -5), Pair(-41, 8),
      Pair(-34, 8), Pair(-19, 14), Pair(-13, 14), Pair(-9, 14), Pair(4, -5), Pair(0, 1), Pair(-7, 5), Pair(-30, -11),
      Pair(-39, 15), Pair(-29, 12), Pair(-26, 16), Pair(-23, 12), Pair(-13, -3), Pair(-15, -4), Pair(-18, 2), Pair(-39, 9)
    },
    {
      Pair(-56, 60), Pair(-17, 19), Pair(10, 39), Pair(48, 15), Pair(53, 18), Pair(26, 39), Pair(126, -54), Pair(48, 27),
      Pair(-34, 43), Pair(-21, 41), Pair(-19, 76), Pair(0, 52), Pair(-5, 84), Pair(22, 37), Pair(23, 28), Pair(38, 54),
      Pair(-13, 23), Pair(-1, 37), Pair(18, 48), Pair(17, 57), Pair(30, 58), Pair(78, 13), Pair(56, 21), Pair(51, 10),
      Pair(-14, 26), Pair(-3, 53), Pair(11, 53), Pair(15, 61), Pair(27, 47), Pair(25, 57), Pair(39, 43), Pair(33, 21),
      Pair(-7, 23), Pair(-17, 68), Pair(-3, 63), Pair(10, 64), Pair(15, 53), Pair(15, 41), Pair(22, 38), Pair(8, 46),
      Pair(-12, 6), Pair(-6, 36), Pair(-3, 40), Pair(3, 48), Pair(8, 49), Pair(15, 41), Pair(26, 23), Pair(3, 46),
      Pair(-2, 7), Pair(-12, 11), Pair(-2, 14), Pair(6, 14), Pair(4, 22), Pair(8, -1), Pair(12, -30), Pair(23, -39),
      Pair(-43, 19), Pair(-33, 14), Pair(-26, 20), Pair(-5, 5), Pair(-12, 8), Pair(-20, 13), Pair(-4, 18), Pair(-8, -7)
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
      Pair(78, 69), Pair(178, 38), Pair(97, 58), Pair(123, 27), Pair(182, 3), Pair(58, 34), Pair(-31, 102), Pair(-19, 98),
      Pair(10, 7), Pair(52, 17), Pair(95, -32), Pair(92, -52), Pair(122, -61), Pair(128, -44), Pair(56, 3), Pair(64, -12),
      Pair(-21, 3), Pair(0, 8), Pair(-2, -17), Pair(16, -30), Pair(37, -29), Pair(37, -30), Pair(16, -5), Pair(-17, -10),
      Pair(-44, -7), Pair(-26, 12), Pair(-15, -14), Pair(-4, -19), Pair(4, -17), Pair(8, -20), Pair(-9, -2), Pair(-32, -13),
      Pair(-65, -9), Pair(-37, 5), Pair(-22, -15), Pair(5, -17), Pair(-5, -13), Pair(-3, -19), Pair(-15, -7), Pair(-52, -15),
      Pair(-51, 0), Pair(-17, 9), Pair(0, -12), Pair(-38, -3), Pair(6, -7), Pair(17, -16), Pair(-3, -5), Pair(-46, -7),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-248, -38), Pair(-298, 22), Pair(-158, 42), Pair(-88, 13), Pair(-85, 20), Pair(-129, 4), Pair(-59, -10), Pair(-230, -18),
      Pair(-117, 9), Pair(-38, 21), Pair(-62, 30), Pair(14, 4), Pair(10, 0), Pair(-12, 8), Pair(-68, 35), Pair(-87, 15),
      Pair(-15, -8), Pair(12, 9), Pair(15, 17), Pair(27, 23), Pair(17, 11), Pair(50, -13), Pair(48, -2), Pair(33, -18),
      Pair(-15, 28), Pair(-1, 25), Pair(29, 29), Pair(59, 20), Pair(89, 15), Pair(58, 28), Pair(86, -1), Pair(33, 13),
      Pair(-31, 18), Pair(0, 25), Pair(-1, 39), Pair(33, 34), Pair(43, 36), Pair(52, 14), Pair(12, 18), Pair(33, 0),
      Pair(-46, -1), Pair(-44, 22), Pair(1, 19), Pair(4, 34), Pair(40, 32), Pair(33, 8), Pair(6, 10), Pair(-58, 26),
      Pair(-103, 19), Pair(-22, 20), Pair(-52, 24), Pair(-8, 27), Pair(-26, 29), Pair(43, 11), Pair(-26, 18), Pair(5, 17),
      Pair(-80, 24), Pair(-53, 1), Pair(-112, 44), Pair(-144, 38), Pair(-38, 22), Pair(-28, 13), Pair(-63, 17), Pair(-54, 38)
    },
    {
      Pair(-92, 4), Pair(-89, 18), Pair(-66, -1), Pair(-112, -7), Pair(-107, 9), Pair(-208, 10), Pair(-129, -2), Pair(-112, -10),
      Pair(-75, -17), Pair(-6, -14), Pair(-86, 4), Pair(3, -17), Pair(-112, 2), Pair(-45, -15), Pair(-88, 14), Pair(-80, -5),
      Pair(-30, 2), Pair(-47, -10), Pair(-28, -5), Pair(1, -19), Pair(-10, -4), Pair(31, -8), Pair(-3, -1), Pair(22, -17),
      Pair(-21, -6), Pair(-19, -8), Pair(12, -16), Pair(31, -15), Pair(41, -17), Pair(17, 4), Pair(20, -11), Pair(8, -16),
      Pair(-80, 2), Pair(-32, 2), Pair(-9, -8), Pair(11, -4), Pair(9, -12), Pair(3, -2), Pair(-29, 3), Pair(-56, -6),
      Pair(-74, 1), Pair(-43, 3), Pair(-14, -6), Pair(7, -15), Pair(26, -16), Pair(-2, -10), Pair(-24, -11), Pair(-60, -3),
      Pair(-49, 22), Pair(-47, -2), Pair(-54, 5), Pair(-33, 0), Pair(-25, -3), Pair(-48, 1), Pair(-17, -24), Pair(-17, -25),
      Pair(-61, -10), Pair(-75, 47), Pair(-32, -4), Pair(-43, -4), Pair(7, -12), Pair(-35, 0), Pair(-135, 24), Pair(-61, -13)
    },
    {
      Pair(-70, 21), Pair(-74, 24), Pair(-7, 12), Pair(-80, 23), Pair(-38, 7), Pair(-30, 26), Pair(-34, 10), Pair(-106, 24),
      Pair(-23, -3), Pair(-7, 10), Pair(-33, 16), Pair(63, -28), Pair(-16, -5), Pair(-17, 12), Pair(-19, 6), Pair(-44, -4),
      Pair(-61, 11), Pair(-5, 1), Pair(15, -15), Pair(-23, -5), Pair(-1, -12), Pair(24, -10), Pair(-6, -2), Pair(-61, -3),
      Pair(-124, 26), Pair(-17, 2), Pair(-53, 18), Pair(-3, 4), Pair(-15, -7), Pair(-41, 2), Pair(-24, -1), Pair(-59, -3),
      Pair(-114, 14), Pair(-107, 28), Pair(-90, 14), Pair(-56, 8), Pair(-26, -4), Pair(-63, 2), Pair(-67, 6), Pair(-85, -4),
      Pair(-77, -9), Pair(-61, -8), Pair(-51, -13), Pair(-56, -11), Pair(-55, -13), Pair(-62, -2), Pair(-27, -34), Pair(-115, -14),
      Pair(-125, -2), Pair(-69, -14), Pair(-65, -7), Pair(-79, -8), Pair(-83, -1), Pair(-33, -28), Pair(-44, -30), Pair(-100, -12),
      Pair(-76, -14), Pair(-75, -5), Pair(-76, -1), Pair(-66, -5), Pair(-66, -14), Pair(-52, -21), Pair(-60, -18), Pair(-73, -20)
    },
    {
      Pair(-177, -8), Pair(-133, -32), Pair(-139, -11), Pair(-115, -11), Pair(-231, 55), Pair(-129, 35), Pair(-69, -106), Pair(-171, 3),
      Pair(-176, -7), Pair(-183, -1), Pair(-188, 32), Pair(-116, 21), Pair(-91, 2), Pair(-15, -56), Pair(-108, -32), Pair(-26, -90),
      Pair(-98, -25), Pair(-157, -7), Pair(-68, -39), Pair(-149, 31), Pair(-67, -11), Pair(-24, -52), Pair(-12, -92), Pair(-35, -64),
      Pair(-159, -3), Pair(-106, -27), Pair(-91, -33), Pair(-115, 14), Pair(-49, -31), Pair(-41, -34), Pair(-11, -79), Pair(-56, -61),
      Pair(-130, -65), Pair(-176, 13), Pair(-113, 17), Pair(-90, 7), Pair(-100, 28), Pair(-76, -23), Pair(-81, -19), Pair(-123, 11),
      Pair(-211, -7), Pair(-102, -57), Pair(-95, -33), Pair(-103, -23), Pair(-106, -7), Pair(-51, -81), Pair(-38, -118), Pair(-123, -41),
      Pair(-127, -60), Pair(-156, -10), Pair(-91, -80), Pair(-97, -59), Pair(-91, -31), Pair(-104, -62), Pair(-98, -100), Pair(-136, -85),
      Pair(-193, -22), Pair(-196, -12), Pair(-123, -59), Pair(-104, -88), Pair(-90, -109), Pair(-92, -59), Pair(-132, -8), Pair(-88, -85)
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
      Pair(66, 59), Pair(281, 3), Pair(222, 31), Pair(98, 18), Pair(56, 60), Pair(-57, 84), Pair(-7, 113), Pair(203, 40),
      Pair(3, 2), Pair(8, 51), Pair(95, -26), Pair(112, -39), Pair(142, -38), Pair(139, -24), Pair(129, 2), Pair(48, 9),
      Pair(-58, 8), Pair(45, 20), Pair(33, -18), Pair(10, -16), Pair(38, -12), Pair(61, -16), Pair(10, 13), Pair(17, -8),
      Pair(-44, -4), Pair(-48, 37), Pair(-11, -6), Pair(-27, 3), Pair(2, -3), Pair(-10, -2), Pair(-44, 21), Pair(-56, -6),
      Pair(-64, -9), Pair(-23, 22), Pair(6, -18), Pair(-2, -9), Pair(-2, -9), Pair(6, -11), Pair(-4, 5), Pair(-67, -7),
      Pair(-77, 2), Pair(-44, 29), Pair(24, -21), Pair(-21, -22), Pair(9, -5), Pair(23, -15), Pair(4, 2), Pair(-79, 1),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-234, -132), Pair(-297, -47), Pair(-49, -21), Pair(-53, -36), Pair(46, -25), Pair(70, -53), Pair(-235, -19), Pair(-618, 4),
      Pair(-145, -3), Pair(-53, -2), Pair(-32, -15), Pair(117, -46), Pair(29, -49), Pair(-22, 1), Pair(63, -16), Pair(38, -54),
      Pair(-74, -13), Pair(-1, -19), Pair(110, -31), Pair(93, -36), Pair(28, -6), Pair(91, -38), Pair(80, -32), Pair(62, -33),
      Pair(-62, 4), Pair(9, -8), Pair(27, -8), Pair(128, -28), Pair(101, -16), Pair(62, -1), Pair(186, -51), Pair(130, -52),
      Pair(-84, 1), Pair(-60, 7), Pair(-24, 16), Pair(29, 7), Pair(14, 5), Pair(68, -2), Pair(0, -3), Pair(114, -21),
      Pair(-113, 1), Pair(-127, 24), Pair(22, -4), Pair(-24, 12), Pair(-27, 20), Pair(33, -8), Pair(-73, 21), Pair(-81, 10),
      Pair(-101, 13), Pair(-133, 12), Pair(-65, -5), Pair(-20, -3), Pair(-32, 5), Pair(-109, 27), Pair(12, -36), Pair(-41, -19),
      Pair(-84, -7), Pair(-123, -15), Pair(-187, 8), Pair(43, -14), Pair(-47, 5), Pair(-99, -4), Pair(-71, 7), Pair(-200, 47)
    },
    {
      Pair(-12, -44), Pair(-135, -11), Pair(18, -55), Pair(-16, -34), Pair(-37, -45), Pair(-5, -50), Pair(-83, -31), Pair(-11, -45),
      Pair(-30, -47), Pair(13, -51), Pair(25, -42), Pair(-110, -32), Pair(-113, -24), Pair(3, -47), Pair(-117, -19), Pair(-107, -7),
      Pair(-76, -13), Pair(-23, -40), Pair(109, -55), Pair(49, -47), Pair(120, -65), Pair(67, -27), Pair(72, -42), Pair(3, -30),
      Pair(-133, -8), Pair(-1, -40), Pair(37, -41), Pair(97, -56), Pair(-5, -22), Pair(48, -38), Pair(33, -44), Pair(15, -38),
      Pair(-45, -41), Pair(-12, -37), Pair(-20, -37), Pair(38, -46), Pair(-21, -40), Pair(-17, -26), Pair(18, -36), Pair(2, -36),
      Pair(-137, 0), Pair(-3, -25), Pair(-20, -23), Pair(10, -33), Pair(23, -21), Pair(1, -27), Pair(-3, -18), Pair(-131, -6),
      Pair(-91, 9), Pair(-83, -18), Pair(-21, -28), Pair(-28, -28), Pair(-109, -8), Pair(-84, -30), Pair(-28, -41), Pair(-115, -9),
      Pair(-150, -7), Pair(-146, -15), Pair(-49, -20), Pair(-33, -18), Pair(-121, -20), Pair(-68, -19), Pair(-86, -39), Pair(124, -21)
    },
    {
      Pair(-59, -26), Pair(-67, -9), Pair(-22, -19), Pair(-38, -30), Pair(-60, -14), Pair(53, -50), Pair(-55, -17), Pair(56, -52),
      Pair(-33, -33), Pair(20, -41), Pair(-3, -38), Pair(57, -63), Pair(61, -67), Pair(-14, -27), Pair(60, -51), Pair(15, -47),
      Pair(-14, -46), Pair(-31, -26), Pair(-24, -33), Pair(24, -48), Pair(68, -71), Pair(-17, -40), Pair(-21, -29), Pair(-36, -38),
      Pair(-49, -29), Pair(-89, -7), Pair(-13, -42), Pair(8, -45), Pair(-33, -44), Pair(30, -59), Pair(-6, -36), Pair(-73, -31),
      Pair(-87, -35), Pair(-142, -17), Pair(-117, -23), Pair(-107, -28), Pair(-20, -57), Pair(-21, -48), Pair(-73, -37), Pair(-42, -67),
      Pair(-41, -51), Pair(-72, -25), Pair(-188, -10), Pair(-125, -21), Pair(-114, -31), Pair(-91, -42), Pair(-65, -52), Pair(-129, -37),
      Pair(-156, -19), Pair(-152, -7), Pair(-72, -41), Pair(-68, -38), Pair(-24, -62), Pair(-23, -57), Pair(-45, -66), Pair(-108, -41),
      Pair(-139, -19), Pair(-135, -13), Pair(-130, -18), Pair(-108, -31), Pair(-71, -47), Pair(-69, -48), Pair(-121, -18), Pair(-127, -37)
    },
    {
      Pair(-293, -11), Pair(-346, -27), Pair(-230, -39), Pair(-306, 16), Pair(-36, -147), Pair(-427, 85), Pair(50, -226), Pair(-579, 160),
      Pair(-321, -24), Pair(-187, -65), Pair(-378, 50), Pair(-402, 133), Pair(-309, 83), Pair(-361, 35), Pair(-373, 21), Pair(-243, -56),
      Pair(-354, -14), Pair(-336, 14), Pair(-138, -81), Pair(-347, 74), Pair(-87, -93), Pair(-124, -33), Pair(-494, 82), Pair(-189, -69),
      Pair(-386, 36), Pair(-353, 40), Pair(-466, 103), Pair(-155, -43), Pair(-239, -10), Pair(-161, -71), Pair(-290, -4), Pair(-91, -97),
      Pair(-476, 65), Pair(-336, -3), Pair(-607, 175), Pair(-207, -30), Pair(-191, -43), Pair(-279, 38), Pair(-150, -102), Pair(-177, -150),
      Pair(-638, 120), Pair(-377, 49), Pair(-221, -35), Pair(-312, 64), Pair(-174, -55), Pair(-110, -153), Pair(-313, -63), Pair(-331, 41),
      Pair(-496, 122), Pair(-437, 59), Pair(-371, 36), Pair(-356, 32), Pair(-256, -17), Pair(-241, -105), Pair(-314, -26), Pair(-548, 112),
      Pair(-411, 20), Pair(-248, -177), Pair(-283, -77), Pair(-172, -233), Pair(-243, -30), Pair(-371, -13), Pair(-381, 46), Pair(-364, -121)
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
      Pair(-47, 109), Pair(218, 39), Pair(394, 71), Pair(325, 31), Pair(11, 115), Pair(237, 87), Pair(-87, 152), Pair(123, 104),
      Pair(58, 8), Pair(94, 55), Pair(142, 7), Pair(141, -10), Pair(210, -26), Pair(170, 0), Pair(153, 10), Pair(25, 29),
      Pair(-74, 23), Pair(-10, 46), Pair(76, 2), Pair(-14, 6), Pair(49, -4), Pair(48, -1), Pair(26, 19), Pair(-56, 11),
      Pair(-85, 15), Pair(-30, 42), Pair(28, 1), Pair(-46, 6), Pair(1, -5), Pair(-51, 10), Pair(-13, 19), Pair(-74, 2),
      Pair(-84, 1), Pair(-34, 27), Pair(21, -15), Pair(2, -5), Pair(25, -12), Pair(-1, -5), Pair(36, 2), Pair(-55, -4),
      Pair(-95, 4), Pair(-45, 31), Pair(42, -9), Pair(-187, 47), Pair(-94, 5), Pair(-42, 1), Pair(-7, 6), Pair(-98, 10),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(9, -150), Pair(181, -158), Pair(223, -125), Pair(150, -138), Pair(108, -93), Pair(195, -172), Pair(-104, -108), Pair(433, -203),
      Pair(-458, -66), Pair(107, -89), Pair(174, -107), Pair(270, -143), Pair(236, -145), Pair(1, -84), Pair(48, -83), Pair(-59, -85),
      Pair(-187, -50), Pair(27, -80), Pair(53, -90), Pair(76, -68), Pair(402, -144), Pair(143, -95), Pair(198, -120), Pair(81, -111),
      Pair(1, -91), Pair(16, -72), Pair(134, -80), Pair(116, -71), Pair(79, -71), Pair(18, -49), Pair(135, -105), Pair(-2, -70),
      Pair(-58, -73), Pair(-111, -52), Pair(13, -54), Pair(22, -53), Pair(186, -68), Pair(39, -68), Pair(142, -107), Pair(18, -94),
      Pair(-124, -96), Pair(-169, -43), Pair(-77, -47), Pair(13, -64), Pair(-87, -35), Pair(-94, -30), Pair(-142, -46), Pair(-57, -70),
      Pair(-371, -50), Pair(-295, -33), Pair(-206, -47), Pair(-245, -30), Pair(-88, -40), Pair(-16, -66), Pair(-20, -56), Pair(-211, -26),
      Pair(-164, -47), Pair(-79, -87), Pair(-401, -4), Pair(-217, -9), Pair(-102, -70), Pair(-322, -27), Pair(-73, -69), Pair(-165, -41)
    },
    {
      Pair(-323, -66), Pair(237, -134), Pair(157, -136), Pair(37, -127), Pair(22, -127), Pair(-50, -101), Pair(424, -181), Pair(-60, -109),
      Pair(-80, -101), Pair(17, -104), Pair(-42, -88), Pair(-33, -116), Pair(176, -147), Pair(119, -124), Pair(161, -130), Pair(-21, -115),
      Pair(-63, -84), Pair(73, -128), Pair(-6, -95), Pair(144, -122), Pair(52, -114), Pair(141, -111), Pair(190, -132), Pair(101, -119),
      Pair(12, -116), Pair(41, -106), Pair(103, -111), Pair(155, -131), Pair(84, -111), Pair(69, -105), Pair(35, -106), Pair(97, -133),
      Pair(-81, -83), Pair(-32, -90), Pair(61, -104), Pair(30, -98), Pair(58, -112), Pair(-55, -74), Pair(34, -119), Pair(8, -70),
      Pair(-85, -68), Pair(84, -99), Pair(-52, -84), Pair(22, -89), Pair(3, -92), Pair(11, -89), Pair(-71, -57), Pair(-60, -88),
      Pair(-85, -62), Pair(-161, -58), Pair(-101, -84), Pair(-12, -98), Pair(9, -99), Pair(-179, -76), Pair(-225, -41), Pair(-170, -87),
      Pair(-155, -62), Pair(-60, -81), Pair(-151, -48), Pair(-178, -70), Pair(-207, -52), Pair(-127, -75), Pair(-155, -74), Pair(-259, -34)
    },
    {
      Pair(-42, -133), Pair(-21, -140), Pair(-106, -118), Pair(-43, -119), Pair(-150, -119), Pair(-38, -142), Pair(-42, -120), Pair(124, -175),
      Pair(-13, -149), Pair(11, -139), Pair(1, -146), Pair(28, -167), Pair(21, -169), Pair(-77, -134), Pair(159, -195), Pair(-43, -137),
      Pair(-144, -120), Pair(-43, -139), Pair(40, -177), Pair(-50, -150), Pair(-27, -146), Pair(16, -171), Pair(110, -183), Pair(-58, -153),
      Pair(-142, -113), Pair(-61, -139), Pair(-135, -127), Pair(-77, -146), Pair(-133, -139), Pair(16, -188), Pair(-171, -122), Pair(-49, -161),
      Pair(-215, -112), Pair(-214, -102), Pair(-129, -122), Pair(-65, -145), Pair(-88, -145), Pair(-23, -153), Pair(-70, -140), Pair(-151, -118),
      Pair(-145, -139), Pair(-194, -117), Pair(-142, -132), Pair(-160, -114), Pair(-100, -145), Pair(-167, -129), Pair(-37, -152), Pair(-253, -114),
      Pair(-127, -132), Pair(-207, -108), Pair(-129, -127), Pair(-171, -120), Pair(-222, -119), Pair(-149, -126), Pair(-231, -114), Pair(-209, -121),
      Pair(-324, -74), Pair(-323, -54), Pair(-228, -107), Pair(-188, -115), Pair(-221, -111), Pair(-190, -115), Pair(-196, -117), Pair(-292, -78)
    },
    {
      Pair(-446, -241), Pair(-559, -168), Pair(-289, -272), Pair(-272, -244), Pair(-329, -245), Pair(-309, -299), Pair(-329, -291), Pair(-368, -300),
      Pair(-618, -82), Pair(-332, -239), Pair(-292, -222), Pair(-271, -190), Pair(-372, -192), Pair(-80, -332), Pair(-129, -315), Pair(-482, -131),
      Pair(-438, -194), Pair(-251, -308), Pair(-214, -260), Pair(-256, -270), Pair(-156, -301), Pair(28, -429), Pair(-495, -160), Pair(-80, -376),
      Pair(-611, -112), Pair(-383, -236), Pair(-360, -190), Pair(-32, -378), Pair(-335, -208), Pair(-385, -212), Pair(-585, -101), Pair(-511, -151),
      Pair(-731, -28), Pair(-437, -167), Pair(-554, -111), Pair(-471, -81), Pair(-439, -122), Pair(-124, -364), Pair(-709, 0), Pair(-400, -181),
      Pair(-746, -21), Pair(-699, -4), Pair(-449, -151), Pair(-332, -242), Pair(-884, 125), Pair(-565, -132), Pair(-530, -141), Pair(-404, -178),
      Pair(-460, -221), Pair(-556, -133), Pair(-430, -176), Pair(-374, -276), Pair(-550, -125), Pair(-570, -149), Pair(-402, -133), Pair(-482, -229),
      Pair(-389, -321), Pair(-632, -73), Pair(-345, -300), Pair(-565, -201), Pair(-461, -151), Pair(-467, -169), Pair(-631, -68), Pair(-81, -364)
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
      Pair(-70, 157), Pair(209, 141), Pair(329, 180), Pair(115, 191), Pair(12, 199), Pair(100, 211), Pair(-160, 223), Pair(88, 138),
      Pair(-75, 66), Pair(168, 85), Pair(339, 38), Pair(83, 48), Pair(95, 33), Pair(186, 73), Pair(-24, 92), Pair(-54, 32),
      Pair(-100, 48), Pair(-68, 70), Pair(115, 25), Pair(-119, 43), Pair(16, 12), Pair(12, 28), Pair(-188, 68), Pair(-47, 20),
      Pair(-122, 37), Pair(-27, 33), Pair(118, 7), Pair(42, -11), Pair(1, 8), Pair(10, -4), Pair(-48, 33), Pair(-39, -5),
      Pair(-127, 27), Pair(116, -5), Pair(158, -35), Pair(132, -50), Pair(-43, 14), Pair(85, -20), Pair(-59, 15), Pair(30, -15),
      Pair(-162, 32), Pair(57, 16), Pair(84, -11), Pair(-383, 75), Pair(-52, -4), Pair(-42, 3), Pair(-28, 13), Pair(-39, 13),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-42, -179), Pair(-277, -102), Pair(384, -168), Pair(150, -169), Pair(2, -107), Pair(371, -212), Pair(128, -295), Pair(-49, -217),
      Pair(380, -203), Pair(75, -153), Pair(-167, -26), Pair(57, -121), Pair(424, -210), Pair(-209, -83), Pair(171, -221), Pair(28, -132),
      Pair(212, -158), Pair(-201, -62), Pair(197, -101), Pair(416, -131), Pair(757, -203), Pair(181, -104), Pair(320, -154), Pair(224, -137),
      Pair(53, -102), Pair(-182, -26), Pair(336, -151), Pair(422, -155), Pair(317, -135), Pair(147, -93), Pair(552, -159), Pair(367, -181),
      Pair(100, -102), Pair(-154, -42), Pair(-170, -29), Pair(-262, 1), Pair(491, -105), Pair(98, -92), Pair(-76, -72), Pair(-172, -49),
      Pair(-169, -81), Pair(-124, -102), Pair(21, -85), Pair(-48, -69), Pair(327, -122), Pair(52, -83), Pair(41, -138), Pair(-103, -43),
      Pair(7, -181), Pair(-147, -72), Pair(-128, -43), Pair(-421, 8), Pair(-461, -9), Pair(91, -114), Pair(-112, -91), Pair(294, -179),
      Pair(-318, -20), Pair(-466, 50), Pair(-115, -29), Pair(-192, -24), Pair(175, -43), Pair(-521, 14), Pair(-517, 25), Pair(-26, -84)
    },
    {
      Pair(-34, -127), Pair(157, -159), Pair(88, -104), Pair(557, -158), Pair(-289, -90), Pair(-136, -130), Pair(-34, -146), Pair(-65, -91),
      Pair(-87, -144), Pair(-7, -136), Pair(-192, -117), Pair(208, -179), Pair(-3, -100), Pair(93, -133), Pair(213, -161), Pair(-50, -143),
      Pair(47, -131), Pair(-39, -97), Pair(148, -154), Pair(40, -152), Pair(54, -151), Pair(57, -109), Pair(63, -127), Pair(-109, -116),
      Pair(-86, -98), Pair(-40, -88), Pair(201, -120), Pair(12, -129), Pair(166, -141), Pair(-51, -108), Pair(-148, -73), Pair(420, -209),
      Pair(-62, -106), Pair(343, -177), Pair(49, -112), Pair(188, -141), Pair(11, -113), Pair(174, -123), Pair(-9, -90), Pair(550, -124),
      Pair(105, -114), Pair(127, -161), Pair(267, -152), Pair(-64, -95), Pair(-43, -98), Pair(-125, -96), Pair(-23, -108), Pair(-5, -84),
      Pair(-199, -32), Pair(383, -140), Pair(288, -159), Pair(82, -114), Pair(-29, -104), Pair(119, -97), Pair(-378, -94), Pair(-98, -41),
      Pair(-206, -88), Pair(288, -84), Pair(-151, -78), Pair(-237, -38), Pair(-110, -82), Pair(-246, -76), Pair(-155, -45), Pair(-230, -89)
    },
    {
      Pair(153, -222), Pair(-22, -155), Pair(278, -257), Pair(-92, -174), Pair(205, -230), Pair(16, -185), Pair(3, -206), Pair(387, -279),
      Pair(319, -274), Pair(227, -233), Pair(123, -224), Pair(88, -207), Pair(192, -246), Pair(57, -211), Pair(80, -223), Pair(316, -275),
      Pair(14, -197), Pair(117, -201), Pair(5, -194), Pair(19, -200), Pair(-25, -192), Pair(194, -238), Pair(9, -189), Pair(24, -187),
      Pair(137, -230), Pair(-4, -191), Pair(12, -210), Pair(-342, -111), Pair(-158, -143), Pair(285, -260), Pair(254, -256), Pair(141, -202),
      Pair(-103, -173), Pair(129, -197), Pair(214, -226), Pair(-191, -157), Pair(487, -302), Pair(26, -205), Pair(264, -241), Pair(16, -185),
      Pair(-13, -192), Pair(-230, -128), Pair(73, -251), Pair(37, -208), Pair(-388, -114), Pair(76, -210), Pair(202, -202), Pair(-101, -180),
      Pair(-303, -129), Pair(-158, -114), Pair(-229, -168), Pair(46, -190), Pair(-131, -165), Pair(-81, -178), Pair(-68, -163), Pair(-246, -134),
      Pair(-344, -108), Pair(-260, -92), Pair(16, -170), Pair(-340, -112), Pair(-123, -149), Pair(-127, -158), Pair(-59, -191), Pair(-322, -88)
    },
    {
      Pair(-220, -419), Pair(-762, -79), Pair(-404, -239), Pair(-275, -265), Pair(-151, -355), Pair(-667, -132), Pair(-319, -262), Pair(45, -514),
      Pair(-151, -324), Pair(-512, -176), Pair(-51, -338), Pair(-147, -329), Pair(-145, -338), Pair(-524, -150), Pair(-252, -325), Pair(-391, -305),
      Pair(-212, -299), Pair(-100, -370), Pair(-284, -227), Pair(-111, -332), Pair(-176, -288), Pair(-294, -260), Pair(-171, -312), Pair(-132, -408),
      Pair(-191, -271), Pair(-353, -174), Pair(-51, -303), Pair(-119, -333), Pair(-113, -306), Pair(-317, -170), Pair(-229, -251), Pair(-208, -275),
      Pair(-106, -352), Pair(-159, -278), Pair(-190, -322), Pair(-338, -189), Pair(-225, -233), Pair(-199, -223), Pair(-353, -190), Pair(-228, -322),
      Pair(-215, -306), Pair(-313, -173), Pair(-491, -88), Pair(-257, -230), Pair(-693, -39), Pair(-547, -118), Pair(41, -422), Pair(-110, -383),
      Pair(93, -421), Pair(-155, -383), Pair(-373, -172), Pair(-449, -203), Pair(-468, -126), Pair(-160, -314), Pair(-147, -309), Pair(-299, -181),
      Pair(-181, -344), Pair(-346, -395), Pair(-123, -385), Pair(-534, -92), Pair(-394, -246), Pair(-524, -146), Pair(-270, -430), Pair(-627, -194)
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
  Pair(-14, 81), Pair(1, 74), Pair(10, 98), Pair(16, 108), Pair(21, 117), Pair(26, 126), Pair(32, 124), Pair(35, 123),
  Pair(37, 116)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-36, -7), Pair(-26, -17), Pair(-16, 2), Pair(-10, 15), Pair(-3, 25), Pair(-1, 36), Pair(2, 41), Pair(3, 46),
  Pair(5, 51), Pair(10, 51), Pair(19, 49), Pair(21, 54), Pair(19, 69), Pair(15, 55)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-38, -15), Pair(-25, 15), Pair(-21, 22), Pair(-20, 36), Pair(-16, 38), Pair(-10, 41), Pair(-7, 47), Pair(-3, 50),
  Pair(1, 53), Pair(4, 58), Pair(9, 60), Pair(12, 64), Pair(17, 66), Pair(20, 66), Pair(20, 62)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-55, -68), Pair(10, -182), Pair(0, 53), Pair(9, 101), Pair(10, 145), Pair(12, 164), Pair(15, 180), Pair(17, 194),
  Pair(19, 202), Pair(23, 205), Pair(25, 212), Pair(26, 221), Pair(30, 217), Pair(30, 223), Pair(33, 224), Pair(36, 221),
  Pair(36, 227), Pair(39, 223), Pair(46, 215), Pair(61, 200), Pair(69, 193), Pair(112, 164), Pair(109, 154), Pair(125, 131),
  Pair(176, 111), Pair(266, 35), Pair(272, 33), Pair(191, 51)
};

constexpr KingBuckets<RankTable<ScorePair>> kPassedPawnBonus = {{
  {
      Pair(0, 0), Pair(-8, -90), Pair(-3, -73), Pair(2, -38), Pair(29, 2), Pair(25, 67), Pair(87, 124), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-17, -88), Pair(-19, -69), Pair(-5, -36), Pair(11, 7), Pair(-1, 77), Pair(53, 73), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-23, -77), Pair(-27, -61), Pair(-21, -26), Pair(16, 12), Pair(14, 87), Pair(52, 71), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-67, -67), Pair(-50, -52), Pair(-58, -16), Pair(-22, 18), Pair(-20, 96), Pair(60, 72), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-87, -58), Pair(-44, -61), Pair(-61, -18), Pair(-16, 16), Pair(-5, 84), Pair(97, 71), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-93, -53), Pair(-34, -64), Pair(-27, -28), Pair(-23, 20), Pair(-14, 93), Pair(105, 62), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-159, -41), Pair(-119, -57), Pair(-111, 1), Pair(-36, 46), Pair(-38, 109), Pair(-1, 84), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPawnPhalanxBonus = {{
  {
      Pair(0, 0), Pair(5, -2), Pair(15, 4), Pair(23, 15), Pair(57, 61), Pair(121, 283), Pair(-104, 525), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -2), Pair(14, 15), Pair(12, 25), Pair(36, 52), Pair(52, 309), Pair(9, 633), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(5, 5), Pair(15, 9), Pair(20, 20), Pair(45, 68), Pair(90, 247), Pair(-90, 424), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-6, 4), Pair(16, 9), Pair(11, 24), Pair(41, 79), Pair(-127, 285), Pair(-289, 453), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(6, 0), Pair(-18, 6), Pair(37, 12), Pair(39, 70), Pair(-146, 279), Pair(-459, 375), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-17, 4), Pair(-47, -1), Pair(61, -7), Pair(94, 46), Pair(16, 106), Pair(-223, 588), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-109, 15), Pair(-58, 11), Pair(-90, 45), Pair(38, 54), Pair(-579, 182), Pair(-178, -60), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kDefendedPawnBonus = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(22, 19), Pair(12, 17), Pair(12, 22), Pair(18, 79), Pair(91, 102), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(20, 16), Pair(13, 16), Pair(15, 22), Pair(24, 53), Pair(197, 72), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(26, 8), Pair(20, 7), Pair(13, 19), Pair(24, 56), Pair(159, 73), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(32, 4), Pair(25, 0), Pair(17, 15), Pair(-3, 58), Pair(207, 38), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(1, 7), Pair(24, -4), Pair(13, 6), Pair(77, 29), Pair(145, 4), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-20, 8), Pair(1, -3), Pair(26, 5), Pair(95, 2), Pair(190, -62), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-22, 12), Pair(-47, 10), Pair(64, 5), Pair(41, -9), Pair(161, -56), Pair(0, 0)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kDoubledPawnPenalty = {{
  {
      Pair(-6, -52), Pair(8, -33), Pair(-3, -22), Pair(0, -16), Pair(-14, 1), Pair(-17, -5), Pair(24, -31), Pair(-12, -44)
  },
  {
      Pair(-39, -28), Pair(12, -26), Pair(3, -23), Pair(-7, 0), Pair(-6, 7), Pair(-4, -11), Pair(-6, -19), Pair(-12, -41)
  },
  {
      Pair(-6, -43), Pair(1, -25), Pair(1, -25), Pair(3, -8), Pair(-3, -4), Pair(-8, -16), Pair(-5, -24), Pair(1, -50)
  },
  {
      Pair(-37, -40), Pair(-30, -25), Pair(10, -32), Pair(8, -19), Pair(22, -17), Pair(-2, -23), Pair(1, -26), Pair(-58, -38)
  },
  {
      Pair(-36, -40), Pair(-2, -58), Pair(-12, -35), Pair(70, -38), Pair(63, -40), Pair(-37, -37), Pair(-29, -30), Pair(41, -66)
  },
  {
      Pair(23, -69), Pair(-37, -55), Pair(-95, -41), Pair(52, -57), Pair(38, -43), Pair(-60, -40), Pair(-54, -28), Pair(19, -85)
  },
  {
      Pair(1, -56), Pair(-101, 22), Pair(-216, -7), Pair(-118, -100), Pair(92, -32), Pair(-90, -18), Pair(-125, -9), Pair(58, -104)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kIsolatedPawnPenalty = {{
  {
      Pair(-2, 4), Pair(-2, -13), Pair(-12, -10), Pair(-10, -12), Pair(-17, -15), Pair(-10, -3), Pair(1, -19), Pair(-8, 2)
  },
  {
      Pair(-5, 4), Pair(0, -13), Pair(-10, -10), Pair(-10, -10), Pair(-9, -18), Pair(3, -13), Pair(2, -13), Pair(-3, -2)
  },
  {
      Pair(2, 3), Pair(2, -15), Pair(-7, -11), Pair(-1, -20), Pair(-4, -21), Pair(0, -13), Pair(1, -16), Pair(11, -2)
  },
  {
      Pair(9, 6), Pair(-16, -13), Pair(-4, -8), Pair(11, -23), Pair(5, -24), Pair(2, -11), Pair(6, -14), Pair(15, -3)
  },
  {
      Pair(3, 17), Pair(-14, -16), Pair(-8, 2), Pair(16, -20), Pair(-11, -17), Pair(-1, -7), Pair(3, -11), Pair(-14, 10)
  },
  {
      Pair(4, 14), Pair(-17, -15), Pair(-28, 11), Pair(12, -10), Pair(-28, -7), Pair(30, -12), Pair(-35, -2), Pair(-3, 6)
  },
  {
      Pair(82, -3), Pair(-44, -8), Pair(-25, -2), Pair(145, -12), Pair(19, -10), Pair(33, -15), Pair(45, -9), Pair(14, 10)
  }
}};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(22, 7), Pair(19, 3), Pair(18, 10), Pair(21, 8), Pair(22, 13), Pair(36, 3), Pair(45, 2), Pair(76, -4)
  },
  {
      Pair(11, 37), Pair(10, 8), Pair(12, 8), Pair(21, 0), Pair(17, -1), Pair(22, -6), Pair(26, -6), Pair(21, 14)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -4), Pair(19, -6), Pair(9, -1),
  Pair(31, -13), Pair(29, -16), Pair(29, -14),
  Pair(40, -7), Pair(0, 0), Pair(35, -5),
  Pair(8, -2), Pair(25, -14), Pair(7, 0)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-5, 0), Pair(-13, 3), Pair(-8, 3),
  Pair(-5, -1), Pair(-17, 6), Pair(-9, 3),
  Pair(1, -6), Pair(-14, 4), Pair(-1, -4),
  Pair(14, -6), Pair(-5, -2), Pair(12, -4),
  Pair(26, -8), Pair(25, 3), Pair(17, -8),
  Pair(0, 0), Pair(4, -28), Pair(0, 0),
  Pair(50, -48), Pair(0, 0), Pair(42, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(2, 70), Pair(-1, 54), Pair(0, 38), Pair(3, 29), Pair(7, 29), Pair(14, 28), Pair(10, 21)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-77, -13), Pair(-15, -5), Pair(-12, 23), Pair(-5, 36), Pair(-3, 45), Pair(0, 52), Pair(-9, 42)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-2193, 245);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-79, -11), Pair(-83, -6), Pair(-25, -14), Pair(-29, -9), Pair(-26, -5), Pair(-41, -3), Pair(-60, -1), Pair(-42, 3)
  },
  {
      Pair(-14, 48), Pair(-42, 21), Pair(-2, 10), Pair(4, -3), Pair(-9, -4), Pair(-2, 2), Pair(-32, 20), Pair(-19, 30)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 3), Pair(26, -6), Pair(61, -29), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 1), Pair(31, -2), Pair(65, -12), Pair(75, -48), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(22, -21), Pair(37, -21), Pair(53, -13), Pair(83, -16), Pair(92, -25), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(2, 14), Pair(11, 26), Pair(31, 31), Pair(77, 15), Pair(114, 11), Pair(177, -12), Pair(232, -60)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(51, 9), Pair(19, 25), Pair(60, 1), Pair(27, 15), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-20, 15), Pair(-13, 20)
  },
  {
      Pair(-73, -26), Pair(-73, -35)
  },
  {
      Pair(-63, -54), Pair(-71, -81)
  },
  {
      Pair(-103, -1), Pair(-92, -38)
  },
  {
      Pair(-82, 38), Pair(-91, 20)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(19, 36), Pair(22, 24), Pair(32, 11), Pair(25, -2), Pair(60, -6)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-3, -22), Pair(9, -13)
  },
  {
      Pair(-26, -49), Pair(-5, -66)
  },
  {
      Pair(-47, -38), Pair(-31, -39)
  },
  {
      Pair(-89, -3), Pair(-67, -31)
  },
  {
      Pair(-60, 33), Pair(-61, 22)
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
      Pair(-53, -25), Pair(-23, -28)
  },
  {
      Pair(18, -156), Pair(31, -148)
  },
  {
      Pair(-89, -7), Pair(-52, -40)
  },
  {
      Pair(-92, -18), Pair(-67, -93)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(0, -28), Pair(14, -12)
  },
  {
      Pair(-46, -28), Pair(-2, -15)
  },
  {
      Pair(-33, -34), Pair(-14, -6)
  },
  {
      Pair(2, -74), Pair(19, -48)
  },
  {
      Pair(-93, 12), Pair(-66, -51)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(16, 31), Pair(18, 17), Pair(42, 26), Pair(49, 27), Pair(54, 33), Pair(39, 49), Pair(50, 17), Pair(4, 35),
  Pair(3, 19), Pair(15, 20), Pair(21, 24), Pair(11, 38), Pair(15, 25), Pair(14, 20), Pair(15, 17), Pair(-9, 31),
  Pair(10, 11), Pair(6, 3), Pair(2, 17), Pair(9, 19), Pair(8, 22), Pair(-8, 21), Pair(4, 8), Pair(0, 9)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-17, 21), Pair(23, 2), Pair(34, 2), Pair(48, 3), Pair(76, -15), Pair(50, -2), Pair(27, -8), Pair(-22, -23),
  Pair(-21, -13), Pair(22, 10), Pair(12, 5), Pair(27, 12), Pair(15, 8), Pair(18, -4), Pair(13, 14), Pair(15, -18),
  Pair(-24, 34), Pair(12, 5), Pair(3, 23), Pair(21, 15), Pair(27, 24), Pair(2, 8), Pair(16, 0), Pair(-51, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(23, 64);

constexpr ScorePair kTempoBonus = Pair(33, 31);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H