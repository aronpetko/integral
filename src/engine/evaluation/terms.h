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
using PieceTable = KingBuckets<std::array<T, kNumPieceTypes>>;

template <typename T>
using PieceSquareTable = PieceTable<SquareTable<T>>;

template <typename T>
using KnightMobilityTable = KingBuckets<std::array<T, 9>>;

template <typename T>
using RookMobilityTable = KingBuckets<std::array<T, 15>>;

template <typename T>
using BishopMobilityTable = KingBuckets<std::array<T, 14>>;

template <typename T>
using QueenMobilityTable = KingBuckets<std::array<T, 28>>;

template <typename T>
using RankTable = std::array<T, kNumRanks>;

template <typename T>
using FileTable = std::array<T, kNumFiles>;

template <typename T>
using OutpostTable = KingBuckets<std::array<T, 24>>;

constexpr PieceTable<ScorePair> kPieceValues = {{
  {
      Pair(59, 129), Pair(328, 294), Pair(354, 345), Pair(467, 639), Pair(835, 1065), Pair(0, 0)
  },
  {
      Pair(50, 57), Pair(123, 122), Pair(123, 129), Pair(139, 194), Pair(233, 261), Pair(0, 0)
  },
  {
      Pair(53, 59), Pair(129, 126), Pair(130, 140), Pair(146, 188), Pair(240, 257), Pair(0, 0)
  },
  {
      Pair(68, 60), Pair(137, 133), Pair(140, 133), Pair(155, 190), Pair(253, 252), Pair(0, 0)
  },
  {
      Pair(85, 59), Pair(138, 128), Pair(145, 133), Pair(165, 184), Pair(251, 242), Pair(0, 0)
  },
  {
      Pair(92, 56), Pair(136, 124), Pair(140, 122), Pair(157, 174), Pair(229, 216), Pair(0, 0)
  },
  {
      Pair(142, 51), Pair(135, 141), Pair(151, 138), Pair(165, 166), Pair(223, 210), Pair(0, 0)
  }
}};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-12, 47), Pair(-55, 56), Pair(-5, 8), Pair(28, -23), Pair(54, -45), Pair(49, -53), Pair(-68, -46), Pair(-37, 18),
      Pair(2, 45), Pair(-13, 45), Pair(41, -4), Pair(52, -45), Pair(79, -50), Pair(103, -39), Pair(-21, 1), Pair(25, 34),
      Pair(0, 8), Pair(-11, 5), Pair(10, -19), Pair(22, -44), Pair(42, -47), Pair(35, -43), Pair(-64, -9), Pair(9, -2),
      Pair(-6, -11), Pair(-22, 2), Pair(9, -35), Pair(17, -37), Pair(23, -44), Pair(21, -44), Pair(-64, -22), Pair(9, -17),
      Pair(-16, -14), Pair(-34, -9), Pair(-7, -28), Pair(-1, -30), Pair(10, -27), Pair(-9, -26), Pair(-73, -31), Pair(8, -29),
      Pair(-9, -5), Pair(-26, -1), Pair(-8, -14), Pair(1, -24), Pair(5, -4), Pair(6, -11), Pair(-63, -20), Pair(-3, -24),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-134, 17), Pair(-124, 53), Pair(-90, 51), Pair(-2, 7), Pair(-30, 19), Pair(-25, -21), Pair(-96, 10), Pair(-48, -40),
      Pair(-27, 5), Pair(-22, 25), Pair(3, 23), Pair(-1, 37), Pair(10, 11), Pair(59, -12), Pair(13, 1), Pair(-8, -24),
      Pair(-30, 22), Pair(-7, 27), Pair(20, 31), Pair(33, 17), Pair(52, -2), Pair(77, -10), Pair(19, 13), Pair(24, -20),
      Pair(7, 13), Pair(20, 18), Pair(35, 36), Pair(54, 29), Pair(47, 30), Pair(60, 20), Pair(31, 25), Pair(36, 2),
      Pair(-9, 7), Pair(10, 26), Pair(31, 29), Pair(35, 27), Pair(39, 28), Pair(45, 14), Pair(41, 20), Pair(9, 13),
      Pair(-22, -11), Pair(1, -2), Pair(13, 6), Pair(23, 20), Pair(34, 14), Pair(23, 1), Pair(19, -5), Pair(1, -18),
      Pair(-44, 15), Pair(-23, 12), Pair(-10, -13), Pair(8, 5), Pair(5, 9), Pair(6, -25), Pair(-7, -8), Pair(-3, 5),
      Pair(-80, -25), Pair(-20, -19), Pair(-33, -6), Pair(-12, 1), Pair(-5, -5), Pair(5, -23), Pair(-15, -21), Pair(-58, -24)
    },
    {
      Pair(-13, 24), Pair(-56, 31), Pair(-72, 31), Pair(-72, 34), Pair(-101, 36), Pair(-57, -1), Pair(-83, 44), Pair(-20, 21),
      Pair(-41, 21), Pair(-20, 24), Pair(-7, 6), Pair(-38, 37), Pair(-24, 7), Pair(-1, 4), Pair(-43, 20), Pair(-24, -9),
      Pair(-9, 17), Pair(-5, 23), Pair(8, 14), Pair(1, -2), Pair(-3, 7), Pair(22, 22), Pair(27, 10), Pair(9, 8),
      Pair(-22, 18), Pair(1, 16), Pair(-5, 15), Pair(20, 13), Pair(14, 0), Pair(20, 3), Pair(1, 6), Pair(-4, 11),
      Pair(-11, 6), Pair(-7, 4), Pair(2, 8), Pair(6, 0), Pair(15, -3), Pair(5, -6), Pair(1, -2), Pair(1, -11),
      Pair(-8, -7), Pair(12, 6), Pair(6, 2), Pair(7, 11), Pair(7, 13), Pair(11, 1), Pair(15, -10), Pair(9, 4),
      Pair(7, -7), Pair(9, -21), Pair(15, -19), Pair(-2, -4), Pair(5, 3), Pair(17, -14), Pair(33, -5), Pair(18, -27),
      Pair(6, -20), Pair(21, -15), Pair(-4, -7), Pair(-12, -11), Pair(-3, -9), Pair(7, -2), Pair(15, -26), Pair(18, -36)
    },
    {
      Pair(13, 8), Pair(0, 17), Pair(-43, 28), Pair(-31, 21), Pair(-4, 6), Pair(3, 15), Pair(3, 26), Pair(-28, 32),
      Pair(15, 2), Pair(8, 15), Pair(23, 8), Pair(29, 11), Pair(18, 5), Pair(49, -9), Pair(47, 7), Pair(6, 9),
      Pair(11, -3), Pair(49, 0), Pair(35, 6), Pair(43, -4), Pair(56, -15), Pair(79, -19), Pair(102, -26), Pair(33, -10),
      Pair(16, -2), Pair(32, -2), Pair(40, -2), Pair(50, -10), Pair(49, -17), Pair(47, -9), Pair(48, -13), Pair(21, -12),
      Pair(-3, -15), Pair(-7, 13), Pair(3, -4), Pair(12, -10), Pair(8, -17), Pair(0, -11), Pair(27, -16), Pair(-5, -16),
      Pair(-14, -18), Pair(-6, -15), Pair(-7, -14), Pair(0, -19), Pair(5, -30), Pair(6, -27), Pair(39, -46), Pair(7, -53),
      Pair(-25, -20), Pair(-7, -20), Pair(3, -29), Pair(5, -25), Pair(6, -36), Pair(14, -44), Pair(30, -56), Pair(-32, -47),
      Pair(2, -18), Pair(5, -27), Pair(11, -29), Pair(18, -35), Pair(19, -38), Pair(20, -28), Pair(19, -38), Pair(-25, -32)
    },
    {
      Pair(-43, -43), Pair(-52, -43), Pair(-38, -35), Pair(-7, -42), Pair(-17, -17), Pair(-13, -21), Pair(39, -82), Pair(-4, -27),
      Pair(-31, -44), Pair(-48, -24), Pair(-22, -22), Pair(-43, -8), Pair(-61, 29), Pair(-18, 26), Pair(-26, 2), Pair(14, -44),
      Pair(-22, -64), Pair(-21, -43), Pair(-13, -44), Pair(-19, -15), Pair(-17, 9), Pair(2, 16), Pair(8, 1), Pair(-28, 29),
      Pair(-20, -60), Pair(-11, -39), Pair(-17, -28), Pair(-16, -18), Pair(-22, 11), Pair(-5, -7), Pair(-4, 1), Pair(-4, -10),
      Pair(-25, -47), Pair(-20, -20), Pair(-23, -18), Pair(-25, 8), Pair(-11, -24), Pair(-26, -5), Pair(1, -41), Pair(-14, -21),
      Pair(-26, -56), Pair(-16, -38), Pair(-23, -15), Pair(-24, -25), Pair(-19, -43), Pair(-15, -34), Pair(4, -64), Pair(-13, -67),
      Pair(-26, -69), Pair(-18, -58), Pair(-11, -69), Pair(-13, -43), Pair(-7, -62), Pair(-1, -106), Pair(2, -124), Pair(-11, -119),
      Pair(-31, -54), Pair(-30, -70), Pair(-20, -88), Pair(-10, -77), Pair(-9, -109), Pair(-35, -102), Pair(-38, -138), Pair(-64, -62)
    },
    {
      Pair(198, -5), Pair(266, 31), Pair(257, 50), Pair(180, 75), Pair(179, 64), Pair(135, 76), Pair(201, 59), Pair(163, -3),
      Pair(189, 26), Pair(315, 57), Pair(265, 75), Pair(295, 69), Pair(265, 74), Pair(230, 82), Pair(276, 71), Pair(177, 41),
      Pair(225, 22), Pair(372, 37), Pair(304, 65), Pair(269, 72), Pair(276, 72), Pair(312, 67), Pair(307, 57), Pair(218, 28),
      Pair(276, 4), Pair(345, 24), Pair(300, 57), Pair(235, 75), Pair(241, 72), Pair(257, 68), Pair(297, 37), Pair(196, 24),
      Pair(258, -17), Pair(313, 12), Pair(253, 50), Pair(185, 75), Pair(209, 68), Pair(226, 55), Pair(280, 24), Pair(198, 1),
      Pair(183, -17), Pair(215, 14), Pair(175, 44), Pair(145, 65), Pair(158, 59), Pair(160, 47), Pair(211, 17), Pair(183, -13),
      Pair(161, 5), Pair(130, 44), Pair(112, 65), Pair(77, 81), Pair(82, 80), Pair(91, 73), Pair(138, 44), Pair(155, 4),
      Pair(-246, -116), Pair(-206, -86), Pair(134, 90), Pair(73, 101), Pair(113, 95), Pair(91, 96), Pair(-224, -72), Pair(-230, -127)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-10, 93), Pair(-39, 111), Pair(-25, 68), Pair(50, 37), Pair(22, 45), Pair(-6, 43), Pair(-14, 60), Pair(-55, 53),
      Pair(60, 75), Pair(55, 84), Pair(73, 48), Pair(61, 27), Pair(98, 10), Pair(102, 20), Pair(77, 66), Pair(39, 58),
      Pair(57, 46), Pair(51, 48), Pair(36, 29), Pair(42, 14), Pair(72, 4), Pair(57, 9), Pair(52, 36), Pair(31, 40),
      Pair(49, 29), Pair(44, 45), Pair(35, 18), Pair(47, 14), Pair(63, 6), Pair(41, 12), Pair(48, 25), Pair(20, 27),
      Pair(53, 20), Pair(44, 36), Pair(28, 22), Pair(20, 25), Pair(39, 17), Pair(16, 20), Pair(51, 18), Pair(25, 21),
      Pair(52, 34), Pair(56, 43), Pair(24, 45), Pair(8, 52), Pair(21, 41), Pair(21, 36), Pair(51, 31), Pair(32, 31),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-6, 8), Pair(-106, 95), Pair(-2, 69), Pair(49, 75), Pair(59, 37), Pair(25, 28), Pair(-31, 56), Pair(18, 0),
      Pair(-15, 50), Pair(42, 54), Pair(82, 43), Pair(62, 70), Pair(67, 58), Pair(74, 53), Pair(26, 54), Pair(65, 20),
      Pair(18, 72), Pair(68, 69), Pair(59, 88), Pair(95, 63), Pair(109, 55), Pair(97, 60), Pair(66, 62), Pair(49, 52),
      Pair(73, 72), Pair(87, 69), Pair(98, 73), Pair(114, 73), Pair(96, 79), Pair(105, 81), Pair(86, 71), Pair(93, 53),
      Pair(57, 69), Pair(66, 72), Pair(88, 80), Pair(95, 81), Pair(101, 83), Pair(106, 71), Pair(104, 66), Pair(61, 61),
      Pair(39, 57), Pair(64, 67), Pair(86, 59), Pair(90, 76), Pair(96, 72), Pair(82, 59), Pair(84, 57), Pair(52, 62),
      Pair(34, 71), Pair(60, 61), Pair(65, 59), Pair(74, 60), Pair(78, 58), Pair(76, 50), Pair(59, 51), Pair(42, 55),
      Pair(-15, 28), Pair(43, 61), Pair(35, 53), Pair(46, 64), Pair(51, 59), Pair(45, 55), Pair(37, 63), Pair(23, 22)
    },
    {
      Pair(67, 85), Pair(21, 98), Pair(-20, 96), Pair(21, 103), Pair(-87, 118), Pair(-34, 89), Pair(23, 88), Pair(50, 95),
      Pair(1, 76), Pair(54, 83), Pair(36, 92), Pair(45, 83), Pair(26, 96), Pair(67, 75), Pair(25, 95), Pair(52, 65),
      Pair(58, 83), Pair(56, 98), Pair(77, 94), Pair(75, 86), Pair(80, 76), Pair(78, 88), Pair(89, 78), Pair(85, 78),
      Pair(68, 83), Pair(65, 87), Pair(66, 98), Pair(68, 94), Pair(79, 92), Pair(74, 98), Pair(66, 89), Pair(70, 87),
      Pair(53, 69), Pair(58, 96), Pair(74, 78), Pair(82, 84), Pair(91, 83), Pair(64, 87), Pair(74, 83), Pair(61, 66),
      Pair(56, 83), Pair(89, 77), Pair(77, 93), Pair(78, 91), Pair(79, 97), Pair(84, 84), Pair(79, 75), Pair(66, 77),
      Pair(82, 71), Pair(92, 70), Pair(95, 67), Pair(74, 86), Pair(83, 81), Pair(85, 66), Pair(94, 67), Pair(78, 56),
      Pair(85, 57), Pair(74, 73), Pair(63, 80), Pair(67, 67), Pair(71, 56), Pair(57, 85), Pair(49, 76), Pair(67, 66)
    },
    {
      Pair(111, 170), Pair(50, 181), Pair(82, 168), Pair(96, 163), Pair(30, 170), Pair(26, 189), Pair(37, 181), Pair(47, 188),
      Pair(84, 156), Pair(79, 164), Pair(96, 152), Pair(125, 150), Pair(127, 133), Pair(105, 146), Pair(75, 159), Pair(65, 162),
      Pair(83, 151), Pair(119, 142), Pair(84, 149), Pair(122, 132), Pair(134, 113), Pair(102, 136), Pair(129, 132), Pair(93, 144),
      Pair(86, 142), Pair(114, 126), Pair(105, 146), Pair(104, 143), Pair(106, 127), Pair(112, 133), Pair(111, 125), Pair(103, 136),
      Pair(70, 144), Pair(77, 139), Pair(71, 145), Pair(85, 140), Pair(86, 131), Pair(76, 132), Pair(75, 131), Pair(77, 131),
      Pair(72, 135), Pair(84, 124), Pair(72, 134), Pair(79, 134), Pair(80, 114), Pair(83, 120), Pair(91, 112), Pair(86, 117),
      Pair(67, 134), Pair(79, 132), Pair(78, 132), Pair(78, 121), Pair(89, 101), Pair(90, 114), Pair(86, 104), Pair(57, 120),
      Pair(87, 139), Pair(79, 127), Pair(85, 133), Pair(96, 125), Pair(91, 116), Pair(66, 131), Pair(77, 119), Pair(89, 119)
    },
    {
      Pair(117, 225), Pair(91, 227), Pair(115, 218), Pair(134, 207), Pair(118, 228), Pair(94, 194), Pair(90, 195), Pair(127, 161),
      Pair(140, 187), Pair(121, 233), Pair(124, 243), Pair(73, 269), Pair(57, 282), Pair(121, 249), Pair(130, 191), Pair(166, 211),
      Pair(157, 208), Pair(151, 186), Pair(158, 237), Pair(156, 208), Pair(128, 244), Pair(142, 218), Pair(179, 184), Pair(171, 213),
      Pair(156, 197), Pair(162, 226), Pair(157, 218), Pair(140, 243), Pair(153, 227), Pair(163, 203), Pair(173, 198), Pair(171, 207),
      Pair(158, 213), Pair(150, 237), Pair(160, 223), Pair(152, 287), Pair(161, 267), Pair(158, 211), Pair(177, 205), Pair(159, 188),
      Pair(149, 177), Pair(171, 231), Pair(165, 261), Pair(155, 270), Pair(162, 257), Pair(164, 258), Pair(173, 219), Pair(161, 214),
      Pair(151, 143), Pair(178, 150), Pair(181, 199), Pair(177, 231), Pair(175, 246), Pair(170, 206), Pair(197, 135), Pair(195, 116),
      Pair(170, 135), Pair(167, 130), Pair(175, 166), Pair(175, 202), Pair(161, 182), Pair(157, 112), Pair(161, 97), Pair(180, 105)
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
      Pair(103, 105), Pair(76, 111), Pair(96, 89), Pair(146, 47), Pair(122, 49), Pair(123, 44), Pair(78, 87), Pair(20, 95),
      Pair(18, 92), Pair(54, 83), Pair(67, 52), Pair(89, 20), Pair(125, 11), Pair(142, 22), Pair(119, 50), Pair(29, 77),
      Pair(21, 63), Pair(39, 58), Pair(36, 36), Pair(57, 18), Pair(81, 18), Pair(80, 16), Pair(74, 36), Pair(18, 50),
      Pair(18, 46), Pair(33, 50), Pair(35, 27), Pair(47, 23), Pair(56, 20), Pair(66, 17), Pair(64, 28), Pair(10, 33),
      Pair(5, 42), Pair(20, 44), Pair(19, 32), Pair(25, 31), Pair(31, 35), Pair(39, 25), Pair(56, 23), Pair(-7, 32),
      Pair(14, 48), Pair(27, 50), Pair(17, 39), Pair(15, 40), Pair(26, 41), Pair(58, 27), Pair(80, 25), Pair(-6, 38),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-54, 59), Pair(-70, 82), Pair(-46, 87), Pair(56, 51), Pair(111, 44), Pair(-37, 82), Pair(-104, 94), Pair(-40, 21),
      Pair(15, 63), Pair(31, 67), Pair(60, 72), Pair(112, 74), Pair(94, 67), Pair(120, 51), Pair(60, 63), Pair(51, 52),
      Pair(16, 71), Pair(66, 77), Pair(77, 95), Pair(102, 77), Pair(105, 77), Pair(136, 66), Pair(100, 50), Pair(98, 46),
      Pair(52, 71), Pair(81, 81), Pair(102, 91), Pair(119, 85), Pair(117, 88), Pair(149, 75), Pair(110, 72), Pair(116, 54),
      Pair(50, 75), Pair(71, 81), Pair(87, 99), Pair(108, 86), Pair(108, 91), Pair(117, 76), Pair(130, 68), Pair(84, 69),
      Pair(32, 60), Pair(54, 71), Pair(74, 80), Pair(86, 92), Pair(100, 83), Pair(85, 66), Pair(87, 55), Pair(62, 58),
      Pair(19, 68), Pair(34, 71), Pair(45, 70), Pair(69, 66), Pair(71, 62), Pair(61, 54), Pair(59, 52), Pair(62, 63),
      Pair(-53, 73), Pair(27, 66), Pair(28, 67), Pair(43, 71), Pair(49, 64), Pair(66, 52), Pair(50, 62), Pair(-2, 80)
    },
    {
      Pair(36, 102), Pair(12, 102), Pair(-30, 110), Pair(-13, 113), Pair(6, 98), Pair(-17, 103), Pair(5, 104), Pair(-14, 121),
      Pair(29, 85), Pair(54, 94), Pair(63, 89), Pair(45, 98), Pair(39, 92), Pair(51, 95), Pair(34, 100), Pair(40, 87),
      Pair(42, 99), Pair(64, 95), Pair(72, 93), Pair(56, 90), Pair(93, 78), Pair(105, 91), Pair(90, 92), Pair(91, 85),
      Pair(48, 92), Pair(71, 95), Pair(79, 91), Pair(97, 86), Pair(81, 89), Pair(96, 84), Pair(74, 91), Pair(76, 82),
      Pair(50, 81), Pair(49, 93), Pair(83, 87), Pair(78, 88), Pair(88, 83), Pair(74, 91), Pair(76, 81), Pair(75, 81),
      Pair(53, 81), Pair(84, 80), Pair(70, 87), Pair(86, 89), Pair(79, 93), Pair(90, 79), Pair(89, 78), Pair(81, 73),
      Pair(58, 88), Pair(71, 69), Pair(88, 67), Pair(68, 76), Pair(78, 75), Pair(80, 60), Pair(108, 56), Pair(66, 66),
      Pair(53, 72), Pair(75, 84), Pair(70, 74), Pair(51, 84), Pair(53, 82), Pair(57, 87), Pair(60, 80), Pair(43, 73)
    },
    {
      Pair(103, 194), Pair(116, 195), Pair(94, 198), Pair(104, 184), Pair(100, 181), Pair(126, 191), Pair(94, 203), Pair(90, 202),
      Pair(111, 176), Pair(111, 185), Pair(140, 175), Pair(173, 155), Pair(161, 157), Pair(176, 167), Pair(124, 181), Pair(114, 178),
      Pair(99, 182), Pair(130, 175), Pair(139, 171), Pair(145, 156), Pair(163, 145), Pair(178, 158), Pair(188, 155), Pair(120, 168),
      Pair(83, 186), Pair(122, 175), Pair(128, 173), Pair(147, 155), Pair(151, 146), Pair(152, 156), Pair(147, 160), Pair(114, 168),
      Pair(73, 175), Pair(82, 179), Pair(89, 175), Pair(103, 164), Pair(97, 159), Pair(95, 166), Pair(113, 158), Pair(89, 159),
      Pair(70, 167), Pair(72, 171), Pair(81, 161), Pair(96, 152), Pair(91, 151), Pair(92, 150), Pair(125, 128), Pair(71, 152),
      Pair(67, 154), Pair(81, 151), Pair(93, 150), Pair(100, 141), Pair(106, 127), Pair(104, 133), Pair(112, 127), Pair(87, 129),
      Pair(71, 182), Pair(74, 176), Pair(79, 177), Pair(91, 161), Pair(95, 154), Pair(95, 161), Pair(90, 160), Pair(70, 174)
    },
    {
      Pair(146, 242), Pair(180, 205), Pair(187, 219), Pair(230, 200), Pair(225, 208), Pair(204, 209), Pair(277, 130), Pair(222, 196),
      Pair(161, 253), Pair(157, 249), Pair(162, 257), Pair(176, 237), Pair(161, 271), Pair(209, 232), Pair(190, 207), Pair(205, 234),
      Pair(186, 239), Pair(195, 242), Pair(207, 252), Pair(191, 240), Pair(198, 246), Pair(239, 206), Pair(222, 209), Pair(203, 215),
      Pair(193, 245), Pair(201, 276), Pair(190, 259), Pair(192, 261), Pair(199, 245), Pair(198, 243), Pair(210, 235), Pair(213, 215),
      Pair(185, 252), Pair(181, 278), Pair(187, 282), Pair(193, 285), Pair(194, 266), Pair(200, 236), Pair(214, 230), Pair(191, 235),
      Pair(180, 212), Pair(186, 261), Pair(187, 270), Pair(187, 281), Pair(196, 271), Pair(205, 250), Pair(216, 218), Pair(194, 229),
      Pair(191, 216), Pair(178, 234), Pair(190, 243), Pair(195, 248), Pair(197, 260), Pair(203, 213), Pair(217, 172), Pair(210, 126),
      Pair(165, 228), Pair(161, 233), Pair(172, 242), Pair(185, 256), Pair(187, 244), Pair(174, 226), Pair(187, 198), Pair(181, 179)
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
      Pair(122, 89), Pair(169, 73), Pair(122, 70), Pair(164, 42), Pair(199, 35), Pair(81, 46), Pair(12, 109), Pair(5, 92),
      Pair(39, 78), Pair(59, 84), Pair(118, 37), Pair(112, 20), Pair(136, 14), Pair(168, 24), Pair(96, 58), Pair(66, 55),
      Pair(34, 57), Pair(37, 63), Pair(49, 34), Pair(67, 24), Pair(90, 22), Pair(94, 23), Pair(81, 40), Pair(33, 44),
      Pair(11, 47), Pair(22, 61), Pair(33, 30), Pair(45, 32), Pair(56, 30), Pair(74, 25), Pair(54, 38), Pair(-2, 37),
      Pair(-5, 41), Pair(10, 51), Pair(23, 30), Pair(40, 29), Pair(35, 35), Pair(51, 23), Pair(64, 30), Pair(-11, 35),
      Pair(-6, 55), Pair(21, 58), Pair(29, 37), Pair(11, 40), Pair(36, 47), Pair(55, 36), Pair(54, 43), Pair(-11, 47),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-96, 24), Pair(-88, 60), Pair(-65, 72), Pair(-3, 58), Pair(-29, 65), Pair(-30, 61), Pair(-6, 41), Pair(-96, 17),
      Pair(-48, 55), Pair(10, 65), Pair(-1, 68), Pair(74, 62), Pair(68, 59), Pair(39, 58), Pair(-16, 72), Pair(-38, 60),
      Pair(16, 42), Pair(52, 54), Pair(68, 71), Pair(92, 62), Pair(104, 53), Pair(103, 52), Pair(85, 46), Pair(61, 35),
      Pair(20, 64), Pair(61, 65), Pair(87, 76), Pair(102, 70), Pair(132, 60), Pair(112, 67), Pair(133, 42), Pair(83, 46),
      Pair(31, 65), Pair(59, 74), Pair(45, 86), Pair(89, 80), Pair(98, 75), Pair(103, 66), Pair(91, 53), Pair(74, 48),
      Pair(-9, 42), Pair(2, 71), Pair(49, 65), Pair(74, 72), Pair(75, 68), Pair(82, 49), Pair(52, 52), Pair(12, 63),
      Pair(-46, 64), Pair(9, 72), Pair(1, 68), Pair(45, 64), Pair(43, 60), Pair(73, 47), Pair(23, 62), Pair(50, 55),
      Pair(-37, 49), Pair(-10, 41), Pair(-57, 73), Pair(-50, 66), Pair(-1, 55), Pair(16, 46), Pair(0, 52), Pair(-8, 86)
    },
    {
      Pair(-14, 91), Pair(-26, 104), Pair(-14, 90), Pair(-25, 95), Pair(-24, 95), Pair(-94, 100), Pair(-48, 88), Pair(-28, 86),
      Pair(-17, 78), Pair(46, 85), Pair(-10, 95), Pair(43, 78), Pair(-13, 90), Pair(19, 87), Pair(-10, 97), Pair(-22, 85),
      Pair(52, 85), Pair(39, 86), Pair(56, 83), Pair(74, 74), Pair(69, 85), Pair(91, 83), Pair(55, 83), Pair(108, 66),
      Pair(30, 87), Pair(63, 78), Pair(81, 78), Pair(99, 77), Pair(105, 83), Pair(84, 80), Pair(88, 82), Pair(75, 72),
      Pair(-16, 90), Pair(54, 78), Pair(63, 77), Pair(82, 79), Pair(81, 75), Pair(77, 80), Pair(55, 75), Pair(38, 73),
      Pair(24, 82), Pair(37, 79), Pair(39, 81), Pair(64, 74), Pair(71, 73), Pair(66, 69), Pair(59, 73), Pair(28, 83),
      Pair(24, 97), Pair(37, 77), Pair(40, 83), Pair(47, 79), Pair(62, 72), Pair(34, 75), Pair(65, 59), Pair(43, 68),
      Pair(5, 82), Pair(10, 107), Pair(37, 78), Pair(21, 77), Pair(33, 76), Pair(41, 78), Pair(-55, 94), Pair(7, 71)
    },
    {
      Pair(53, 192), Pair(46, 196), Pair(98, 179), Pair(49, 184), Pair(76, 165), Pair(79, 183), Pair(77, 180), Pair(39, 192),
      Pair(105, 157), Pair(114, 167), Pair(99, 168), Pair(180, 134), Pair(122, 146), Pair(115, 164), Pair(110, 168), Pair(82, 166),
      Pair(43, 177), Pair(104, 167), Pair(124, 155), Pair(108, 150), Pair(111, 143), Pair(136, 155), Pair(98, 163), Pair(56, 167),
      Pair(7, 184), Pair(85, 171), Pair(71, 174), Pair(109, 153), Pair(95, 144), Pair(81, 156), Pair(91, 160), Pair(64, 158),
      Pair(-2, 176), Pair(3, 188), Pair(39, 172), Pair(49, 161), Pair(61, 150), Pair(42, 157), Pair(50, 164), Pair(39, 152),
      Pair(26, 143), Pair(33, 154), Pair(52, 140), Pair(57, 132), Pair(57, 124), Pair(52, 137), Pair(97, 115), Pair(7, 136),
      Pair(-1, 161), Pair(41, 155), Pair(29, 157), Pair(35, 148), Pair(21, 150), Pair(63, 135), Pair(59, 135), Pair(7, 154),
      Pair(32, 167), Pair(34, 171), Pair(34, 170), Pair(49, 160), Pair(44, 152), Pair(55, 156), Pair(54, 154), Pair(39, 155)
    },
    {
      Pair(64, 193), Pair(94, 158), Pair(86, 181), Pair(101, 186), Pair(29, 231), Pair(102, 186), Pair(112, 102), Pair(63, 183),
      Pair(35, 217), Pair(25, 202), Pair(17, 229), Pair(69, 213), Pair(107, 204), Pair(159, 157), Pair(79, 156), Pair(135, 130),
      Pair(98, 200), Pair(65, 218), Pair(126, 184), Pair(35, 232), Pair(102, 192), Pair(160, 157), Pair(178, 111), Pair(144, 135),
      Pair(62, 223), Pair(114, 210), Pair(97, 193), Pair(71, 234), Pair(119, 179), Pair(126, 168), Pair(168, 128), Pair(120, 144),
      Pair(108, 165), Pair(49, 220), Pair(93, 245), Pair(104, 240), Pair(92, 252), Pair(116, 183), Pair(109, 171), Pair(66, 200),
      Pair(33, 153), Pair(122, 164), Pair(115, 198), Pair(114, 209), Pair(116, 221), Pair(162, 148), Pair(157, 75), Pair(68, 125),
      Pair(83, 116), Pair(80, 197), Pair(132, 163), Pair(135, 191), Pair(143, 216), Pair(124, 159), Pair(128, 110), Pair(70, 93),
      Pair(45, 152), Pair(43, 165), Pair(104, 168), Pair(144, 168), Pair(140, 120), Pair(118, 141), Pair(71, 163), Pair(109, 100)
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
      Pair(118, 78), Pair(210, 53), Pair(185, 66), Pair(173, 51), Pair(95, 72), Pair(14, 72), Pair(57, 100), Pair(140, 63),
      Pair(49, 72), Pair(63, 96), Pair(147, 42), Pair(163, 32), Pair(164, 31), Pair(175, 41), Pair(147, 56), Pair(54, 61),
      Pair(4, 61), Pair(74, 64), Pair(66, 36), Pair(74, 34), Pair(97, 32), Pair(110, 33), Pair(94, 48), Pair(68, 37),
      Pair(-1, 51), Pair(9, 73), Pair(22, 38), Pair(40, 43), Pair(40, 39), Pair(74, 32), Pair(47, 52), Pair(0, 37),
      Pair(-11, 44), Pair(13, 62), Pair(20, 32), Pair(57, 29), Pair(56, 30), Pair(47, 31), Pair(49, 46), Pair(-3, 37),
      Pair(-35, 60), Pair(5, 70), Pair(38, 31), Pair(1, 39), Pair(19, 43), Pair(36, 40), Pair(47, 51), Pair(-29, 49),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-106, -62), Pair(-42, -4), Pair(-4, 30), Pair(5, 27), Pair(44, 28), Pair(44, 9), Pair(-40, 7), Pair(-146, -27),
      Pair(-78, 33), Pair(-18, 43), Pair(21, 45), Pair(117, 38), Pair(54, 24), Pair(14, 42), Pair(51, 25), Pair(28, 10),
      Pair(-7, 29), Pair(37, 42), Pair(133, 47), Pair(125, 37), Pair(82, 48), Pair(107, 42), Pair(106, 30), Pair(63, 26),
      Pair(-30, 42), Pair(46, 47), Pair(70, 57), Pair(157, 45), Pair(137, 51), Pair(127, 46), Pair(161, 21), Pair(118, 15),
      Pair(-15, 47), Pair(-22, 65), Pair(32, 67), Pair(93, 59), Pair(85, 55), Pair(89, 55), Pair(43, 52), Pair(99, 30),
      Pair(-49, 41), Pair(-59, 75), Pair(38, 58), Pair(30, 68), Pair(23, 75), Pair(86, 43), Pair(0, 55), Pair(-32, 50),
      Pair(-30, 42), Pair(-34, 55), Pair(-28, 50), Pair(24, 50), Pair(25, 57), Pair(-29, 57), Pair(23, 27), Pair(5, 21),
      Pair(-28, 24), Pair(-26, 36), Pair(-83, 48), Pair(52, 41), Pair(-22, 29), Pair(-57, 29), Pair(-15, 50), Pair(-35, 56)
    },
    {
      Pair(26, 48), Pair(-48, 70), Pair(30, 51), Pair(22, 59), Pair(8, 52), Pair(23, 50), Pair(-11, 62), Pair(32, 57),
      Pair(10, 54), Pair(49, 50), Pair(58, 50), Pair(-35, 56), Pair(-38, 65), Pair(67, 46), Pair(-51, 72), Pair(-59, 75),
      Pair(-18, 72), Pair(31, 63), Pair(140, 45), Pair(124, 47), Pair(140, 41), Pair(123, 57), Pair(110, 54), Pair(44, 65),
      Pair(-37, 82), Pair(65, 55), Pair(88, 56), Pair(148, 44), Pair(84, 66), Pair(114, 49), Pair(105, 46), Pair(47, 62),
      Pair(22, 57), Pair(62, 55), Pair(54, 56), Pair(105, 54), Pair(80, 56), Pair(54, 62), Pair(58, 50), Pair(55, 51),
      Pair(-47, 85), Pair(37, 60), Pair(46, 61), Pair(77, 56), Pair(65, 61), Pair(54, 55), Pair(58, 64), Pair(-52, 81),
      Pair(-22, 89), Pair(-12, 70), Pair(42, 56), Pair(41, 59), Pair(-12, 65), Pair(-33, 59), Pair(36, 48), Pair(-35, 57),
      Pair(-56, 66), Pair(-51, 71), Pair(39, 59), Pair(7, 64), Pair(-50, 69), Pair(8, 58), Pair(-16, 42), Pair(81, 62)
    },
    {
      Pair(51, 157), Pair(47, 163), Pair(72, 146), Pair(69, 136), Pair(45, 143), Pair(120, 130), Pair(50, 153), Pair(142, 136),
      Pair(78, 136), Pair(116, 127), Pair(102, 124), Pair(148, 101), Pair(133, 101), Pair(96, 132), Pair(132, 123), Pair(120, 121),
      Pair(83, 133), Pair(72, 141), Pair(73, 131), Pair(114, 108), Pair(129, 99), Pair(94, 129), Pair(69, 138), Pair(57, 133),
      Pair(49, 140), Pair(5, 158), Pair(70, 125), Pair(93, 117), Pair(61, 114), Pair(118, 109), Pair(56, 133), Pair(35, 138),
      Pair(5, 131), Pair(-28, 146), Pair(-5, 131), Pair(-6, 122), Pair(60, 96), Pair(40, 112), Pair(25, 124), Pair(51, 98),
      Pair(33, 122), Pair(11, 134), Pair(-68, 149), Pair(-24, 129), Pair(-4, 114), Pair(6, 119), Pair(34, 115), Pair(-13, 123),
      Pair(-30, 145), Pair(-32, 151), Pair(17, 124), Pair(-11, 124), Pair(64, 103), Pair(57, 112), Pair(54, 108), Pair(17, 130),
      Pair(-10, 155), Pair(-9, 154), Pair(-10, 149), Pair(12, 133), Pair(47, 112), Pair(43, 125), Pair(-13, 148), Pair(11, 134)
    },
    {
      Pair(52, 157), Pair(37, 121), Pair(51, 139), Pair(28, 177), Pair(125, 125), Pair(30, 134), Pair(92, 63), Pair(-20, 163),
      Pair(3, 132), Pair(27, 123), Pair(-31, 160), Pair(-26, 201), Pair(24, 190), Pair(-32, 170), Pair(-2, 103), Pair(18, 101),
      Pair(5, 106), Pair(5, 135), Pair(81, 128), Pair(-5, 189), Pair(103, 123), Pair(106, 153), Pair(-8, 122), Pair(65, 106),
      Pair(-9, 157), Pair(-6, 161), Pair(-44, 181), Pair(69, 169), Pair(28, 170), Pair(65, 123), Pair(9, 143), Pair(104, 97),
      Pair(-34, 99), Pair(-13, 106), Pair(-82, 175), Pair(25, 160), Pair(45, 149), Pair(8, 159), Pair(54, 61), Pair(10, 46),
      Pair(-77, 62), Pair(-46, 147), Pair(31, 149), Pair(-13, 211), Pair(69, 143), Pair(94, 89), Pair(-17, 79), Pair(-5, 90),
      Pair(-57, 114), Pair(-33, 101), Pair(-29, 147), Pair(-5, 152), Pair(21, 153), Pair(15, 48), Pair(9, 81), Pair(-51, 75),
      Pair(-41, 41), Pair(-23, -10), Pair(-15, 52), Pair(88, 17), Pair(15, 95), Pair(-29, 48), Pair(-29, 72), Pair(-57, -8)
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
      Pair(57, 114), Pair(214, 94), Pair(219, 104), Pair(239, 75), Pair(116, 108), Pair(160, 92), Pair(42, 138), Pair(115, 89),
      Pair(91, 78), Pair(130, 101), Pair(160, 68), Pair(177, 54), Pair(199, 49), Pair(207, 52), Pair(159, 72), Pair(81, 68),
      Pair(4, 70), Pair(50, 84), Pair(86, 51), Pair(59, 49), Pair(106, 43), Pair(140, 38), Pair(94, 64), Pair(38, 48),
      Pair(9, 60), Pair(44, 78), Pair(49, 45), Pair(56, 39), Pair(69, 36), Pair(67, 41), Pair(67, 60), Pair(12, 43),
      Pair(-17, 52), Pair(-3, 69), Pair(28, 40), Pair(61, 36), Pair(61, 38), Pair(61, 34), Pair(68, 52), Pair(28, 35),
      Pair(-38, 63), Pair(-7, 78), Pair(24, 47), Pair(-78, 71), Pair(-65, 58), Pair(9, 54), Pair(25, 66), Pair(-24, 56),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-10, -41), Pair(42, -37), Pair(58, -2), Pair(54, -19), Pair(67, 4), Pair(48, -15), Pair(-24, -32), Pair(51, -48),
      Pair(-61, -18), Pair(82, 2), Pair(108, 0), Pair(168, -2), Pair(141, 2), Pair(59, 4), Pair(63, -1), Pair(-8, -18),
      Pair(-38, 5), Pair(55, 21), Pair(111, 32), Pair(137, 26), Pair(237, 5), Pair(152, 29), Pair(150, 8), Pair(79, -11),
      Pair(37, -10), Pair(67, 24), Pair(154, 28), Pair(147, 36), Pair(136, 34), Pair(102, 41), Pair(108, 4), Pair(39, 12),
      Pair(0, 9), Pair(-12, 43), Pair(74, 41), Pair(87, 42), Pair(148, 33), Pair(103, 28), Pair(110, 14), Pair(57, 5),
      Pair(-34, 3), Pair(-52, 44), Pair(6, 49), Pair(89, 42), Pair(5, 60), Pair(-5, 51), Pair(-50, 34), Pair(8, -9),
      Pair(-56, 13), Pair(-69, 22), Pair(-70, 34), Pair(-109, 52), Pair(-23, 44), Pair(7, 23), Pair(18, 16), Pair(-34, 17),
      Pair(-28, -21), Pair(-45, 7), Pair(-128, 28), Pair(-71, 32), Pair(-15, 9), Pair(-102, 3), Pair(-74, 20), Pair(-23, 21)
    },
    {
      Pair(-46, 34), Pair(136, 25), Pair(124, 18), Pair(57, 28), Pair(73, 11), Pair(9, 38), Pair(132, -2), Pair(8, 28),
      Pair(-16, 33), Pair(69, 43), Pair(48, 32), Pair(69, 19), Pair(159, 8), Pair(123, 19), Pair(137, 27), Pair(20, 38),
      Pair(-23, 43), Pair(127, 27), Pair(89, 30), Pair(172, 19), Pair(146, 26), Pair(183, 33), Pair(186, 21), Pair(140, 17),
      Pair(65, 24), Pair(107, 26), Pair(174, 18), Pair(208, 14), Pair(173, 23), Pair(166, 28), Pair(100, 27), Pair(104, 19),
      Pair(23, 41), Pair(49, 36), Pair(116, 32), Pair(139, 30), Pair(159, 21), Pair(52, 49), Pair(108, 14), Pair(39, 49),
      Pair(-24, 55), Pair(116, 24), Pair(44, 43), Pair(101, 29), Pair(85, 35), Pair(82, 31), Pair(31, 50), Pair(37, 32),
      Pair(10, 50), Pair(-76, 64), Pair(-1, 37), Pair(37, 35), Pair(81, 30), Pair(-47, 39), Pair(-87, 62), Pair(-21, 27),
      Pair(-25, 57), Pair(6, 42), Pair(-71, 69), Pair(-59, 55), Pair(-77, 65), Pair(-44, 51), Pair(3, 42), Pair(-48, 41)
    },
    {
      Pair(117, 105), Pair(137, 102), Pair(68, 108), Pair(92, 97), Pair(52, 106), Pair(114, 101), Pair(108, 117), Pair(176, 94),
      Pair(152, 84), Pair(147, 97), Pair(161, 77), Pair(183, 54), Pair(172, 61), Pair(129, 92), Pair(217, 72), Pair(119, 98),
      Pair(53, 105), Pair(109, 93), Pair(179, 60), Pair(113, 59), Pair(96, 72), Pair(150, 79), Pair(176, 78), Pair(91, 92),
      Pair(44, 111), Pair(96, 93), Pair(35, 96), Pair(69, 64), Pair(27, 83), Pair(143, 68), Pair(0, 115), Pair(113, 84),
      Pair(4, 114), Pair(-21, 123), Pair(40, 98), Pair(64, 80), Pair(62, 81), Pair(78, 93), Pair(75, 96), Pair(22, 108),
      Pair(25, 101), Pair(-10, 115), Pair(-3, 95), Pair(12, 93), Pair(45, 78), Pair(15, 102), Pair(97, 85), Pair(-26, 104),
      Pair(36, 104), Pair(-29, 114), Pair(22, 99), Pair(-3, 89), Pair(-2, 91), Pair(48, 93), Pair(-16, 108), Pair(13, 101),
      Pair(-80, 148), Pair(-77, 150), Pair(-26, 115), Pair(-9, 109), Pair(-28, 111), Pair(10, 113), Pair(-13, 121), Pair(-80, 141)
    },
    {
      Pair(43, 96), Pair(36, 99), Pair(125, 85), Pair(120, 116), Pair(115, 97), Pair(83, 67), Pair(58, 67), Pair(74, 62),
      Pair(-28, 136), Pair(37, 98), Pair(84, 131), Pair(94, 137), Pair(58, 125), Pair(141, 98), Pair(85, 89), Pair(14, 123),
      Pair(25, 89), Pair(88, 70), Pair(90, 126), Pair(96, 82), Pair(112, 88), Pair(179, 52), Pair(20, 104), Pair(115, 59),
      Pair(-1, 93), Pair(38, 71), Pair(36, 137), Pair(152, 68), Pair(60, 116), Pair(34, 89), Pair(-1, 117), Pair(-11, 106),
      Pair(-36, 104), Pair(24, 100), Pair(5, 104), Pair(26, 176), Pair(32, 172), Pair(91, 62), Pair(-35, 123), Pair(36, 97),
      Pair(-38, 88), Pair(-55, 122), Pair(2, 117), Pair(35, 96), Pair(-65, 161), Pair(-27, 84), Pair(-13, 73), Pair(15, 74),
      Pair(-11, 38), Pair(-36, 62), Pair(-31, 73), Pair(-13, 39), Pair(-13, 81), Pair(-29, 38), Pair(20, 113), Pair(-13, 20),
      Pair(-39, -10), Pair(-61, 80), Pair(-11, 24), Pair(-77, 13), Pair(0, 77), Pair(-2, 58), Pair(-28, 63), Pair(24, 44)
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
      Pair(47, 138), Pair(116, 153), Pair(153, 143), Pair(142, 149), Pair(108, 155), Pair(109, 149), Pair(40, 172), Pair(64, 118),
      Pair(-8, 103), Pair(80, 119), Pair(172, 78), Pair(123, 84), Pair(73, 81), Pair(119, 91), Pair(24, 123), Pair(-33, 76),
      Pair(32, 56), Pair(-9, 92), Pair(83, 49), Pair(55, 38), Pair(134, 34), Pair(68, 50), Pair(-78, 89), Pair(21, 39),
      Pair(-6, 58), Pair(-13, 87), Pair(91, 47), Pair(139, 30), Pair(60, 51), Pair(55, 31), Pair(25, 69), Pair(41, 29),
      Pair(-31, 46), Pair(50, 49), Pair(130, 23), Pair(114, 17), Pair(6, 41), Pair(143, 15), Pair(-10, 63), Pair(75, 21),
      Pair(-57, 64), Pair(-11, 71), Pair(-10, 48), Pair(-57, 61), Pair(-46, 14), Pair(12, 53), Pair(-1, 68), Pair(-22, 47),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-24, -73), Pair(-47, -57), Pair(42, -19), Pair(10, -33), Pair(4, -30), Pair(34, -56), Pair(-4, -96), Pair(-25, -87),
      Pair(35, -43), Pair(22, -45), Pair(-17, 5), Pair(37, -2), Pair(96, -20), Pair(-52, -13), Pair(19, -61), Pair(-8, -52),
      Pair(20, -57), Pair(-26, -6), Pair(82, 37), Pair(115, 24), Pair(135, -14), Pair(80, 29), Pair(82, -10), Pair(31, -9),
      Pair(5, -26), Pair(4, 26), Pair(114, 15), Pair(115, 27), Pair(122, 13), Pair(78, 41), Pair(122, 11), Pair(37, -43),
      Pair(10, -15), Pair(-20, 17), Pair(7, 52), Pair(-50, 27), Pair(131, 42), Pair(24, 19), Pair(-9, -16), Pair(-2, 1),
      Pair(-24, -19), Pair(-7, -12), Pair(15, 21), Pair(9, 26), Pair(61, 21), Pair(8, 34), Pair(51, -43), Pair(-11, -4),
      Pair(-10, -74), Pair(-41, -18), Pair(-28, -3), Pair(-83, 8), Pair(-75, -3), Pair(-1, -16), Pair(-37, -52), Pair(24, -48),
      Pair(-31, -9), Pair(-87, 33), Pair(1, -5), Pair(-21, 5), Pair(23, 6), Pair(-55, -8), Pair(-96, -8), Pair(-6, -39)
    },
    {
      Pair(6, -22), Pair(48, -18), Pair(36, 8), Pair(114, 11), Pair(-56, -4), Pair(-24, -20), Pair(-18, -56), Pair(23, -7),
      Pair(-41, -37), Pair(21, -7), Pair(-31, -5), Pair(60, -18), Pair(15, 3), Pair(48, -12), Pair(75, -18), Pair(9, -20),
      Pair(-5, 10), Pair(25, 11), Pair(105, -3), Pair(39, -7), Pair(51, -16), Pair(24, 26), Pair(23, -2), Pair(-21, -11),
      Pair(-4, 2), Pair(47, 14), Pair(105, 9), Pair(34, 11), Pair(129, 8), Pair(13, 7), Pair(-23, 9), Pair(83, -27),
      Pair(21, 3), Pair(120, -16), Pair(35, 7), Pair(147, -4), Pair(102, -3), Pair(81, 7), Pair(-17, 10), Pair(98, 42),
      Pair(26, 2), Pair(54, -15), Pair(118, -6), Pair(17, 14), Pair(-24, 16), Pair(-2, 9), Pair(26, 10), Pair(-8, 14),
      Pair(-9, 34), Pair(84, 8), Pair(82, -14), Pair(41, -7), Pair(7, 3), Pair(40, 4), Pair(-55, -17), Pair(13, 28),
      Pair(-16, 8), Pair(39, 24), Pair(-49, 4), Pair(-12, 24), Pair(-41, -8), Pair(-80, 24), Pair(-6, 15), Pair(-28, -11)
    },
    {
      Pair(147, 41), Pair(104, 68), Pair(133, 27), Pair(33, 35), Pair(110, 38), Pair(71, 51), Pair(79, 16), Pair(170, 33),
      Pair(198, 14), Pair(159, 8), Pair(138, 0), Pair(117, 0), Pair(147, 6), Pair(123, 18), Pair(126, 15), Pair(146, 21),
      Pair(84, 36), Pair(122, 27), Pair(72, 4), Pair(74, 2), Pair(47, 23), Pair(77, 33), Pair(85, 54), Pair(52, 58),
      Pair(99, 31), Pair(62, 18), Pair(49, 10), Pair(-80, 37), Pair(19, 34), Pair(130, 1), Pair(133, 15), Pair(77, 53),
      Pair(49, 33), Pair(75, 42), Pair(90, 24), Pair(50, 23), Pair(140, 8), Pair(38, 20), Pair(105, 19), Pair(53, 32),
      Pair(13, 37), Pair(3, 48), Pair(31, 5), Pair(70, 7), Pair(-47, 47), Pair(75, 19), Pair(89, 36), Pair(35, 32),
      Pair(-27, 49), Pair(3, 67), Pair(19, 21), Pair(88, 17), Pair(27, 37), Pair(53, 27), Pair(28, 36), Pair(9, 52),
      Pair(-90, 96), Pair(-37, 103), Pair(115, 50), Pair(-63, 66), Pair(97, 46), Pair(16, 66), Pair(105, 28), Pair(-72, 107)
    },
    {
      Pair(106, 59), Pair(14, 93), Pair(53, 93), Pair(122, 102), Pair(162, 64), Pair(20, 73), Pair(123, 59), Pair(135, 58),
      Pair(71, 50), Pair(19, 71), Pair(80, 80), Pair(58, 65), Pair(51, 63), Pair(57, 72), Pair(2, 19), Pair(-21, 7),
      Pair(53, 55), Pair(70, 45), Pair(71, 90), Pair(75, 75), Pair(68, 91), Pair(53, 72), Pair(59, 69), Pair(13, 2),
      Pair(51, 78), Pair(61, 95), Pair(83, 99), Pair(95, 62), Pair(83, 101), Pair(50, 108), Pair(76, 88), Pair(34, 76),
      Pair(45, 40), Pair(54, 66), Pair(35, 47), Pair(43, 99), Pair(69, 89), Pair(61, 112), Pair(8, 71), Pair(18, 26),
      Pair(31, 27), Pair(49, 102), Pair(19, 96), Pair(29, 75), Pair(-21, 70), Pair(-27, 74), Pair(55, 31), Pair(8, 25),
      Pair(70, 68), Pair(-7, 3), Pair(14, 71), Pair(-22, 31), Pair(-12, 80), Pair(30, 28), Pair(28, 50), Pair(34, 89),
      Pair(-3, 15), Pair(-50, -28), Pair(-6, -2), Pair(-73, 81), Pair(-20, 19), Pair(-55, 9), Pair(-13, -21), Pair(-51, -3)
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

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {{
  {
      Pair(-16, -33), Pair(4, -11), Pair(12, 13), Pair(16, 28), Pair(20, 36), Pair(24, 43), Pair(28, 45), Pair(31, 43),
      Pair(28, 42)
  },
  {
      Pair(82, 79), Pair(90, 69), Pair(98, 89), Pair(105, 100), Pair(110, 104), Pair(115, 109), Pair(119, 110), Pair(122, 108),
      Pair(124, 97)
  },
  {
      Pair(83, 61), Pair(82, 69), Pair(90, 86), Pair(96, 97), Pair(99, 105), Pair(104, 110), Pair(113, 107), Pair(116, 101),
      Pair(117, 88)
  },
  {
      Pair(82, 81), Pair(73, 62), Pair(85, 91), Pair(92, 104), Pair(99, 107), Pair(97, 115), Pair(101, 114), Pair(105, 107),
      Pair(100, 99)
  },
  {
      Pair(57, 91), Pair(53, 59), Pair(67, 102), Pair(62, 105), Pair(82, 110), Pair(90, 111), Pair(86, 106), Pair(91, 103),
      Pair(84, 94)
  },
  {
      Pair(49, 84), Pair(43, 95), Pair(43, 100), Pair(57, 108), Pair(77, 108), Pair(74, 108), Pair(95, 101), Pair(74, 98),
      Pair(89, 84)
  },
  {
      Pair(17, 38), Pair(5, 29), Pair(26, 81), Pair(40, 90), Pair(44, 88), Pair(45, 93), Pair(53, 84), Pair(42, 75),
      Pair(27, 50)
  }
}};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {{
  {
      Pair(-20, -51), Pair(-14, -51), Pair(-5, -28), Pair(0, -12), Pair(6, 1), Pair(9, 14), Pair(11, 21), Pair(11, 26),
      Pair(12, 33), Pair(15, 37), Pair(20, 39), Pair(21, 47), Pair(19, 59), Pair(27, 35)
  },
  {
      Pair(71, 66), Pair(78, 73), Pair(94, 78), Pair(100, 93), Pair(107, 102), Pair(110, 108), Pair(111, 114), Pair(112, 115),
      Pair(114, 119), Pair(122, 112), Pair(124, 116), Pair(136, 104), Pair(93, 111), Pair(80, 113)
  },
  {
      Pair(59, 72), Pair(76, 48), Pair(81, 64), Pair(89, 76), Pair(95, 88), Pair(99, 97), Pair(101, 104), Pair(104, 108),
      Pair(106, 112), Pair(113, 112), Pair(115, 111), Pair(136, 105), Pair(100, 133), Pair(84, 113)
  },
  {
      Pair(56, 97), Pair(61, 58), Pair(74, 68), Pair(77, 87), Pair(92, 91), Pair(98, 103), Pair(98, 112), Pair(99, 117),
      Pair(107, 120), Pair(107, 120), Pair(111, 123), Pair(99, 121), Pair(77, 132), Pair(74, 121)
  },
  {
      Pair(68, 96), Pair(37, 47), Pair(44, 77), Pair(68, 87), Pair(85, 93), Pair(76, 106), Pair(95, 109), Pair(97, 109),
      Pair(97, 115), Pair(96, 116), Pair(89, 118), Pair(75, 115), Pair(54, 134), Pair(49, 108)
  },
  {
      Pair(62, 112), Pair(53, 64), Pair(34, 74), Pair(63, 90), Pair(66, 90), Pair(71, 103), Pair(80, 107), Pair(100, 104),
      Pair(100, 110), Pair(99, 108), Pair(82, 109), Pair(87, 110), Pair(59, 125), Pair(39, 108)
  },
  {
      Pair(26, 66), Pair(17, 49), Pair(25, 64), Pair(38, 84), Pair(53, 96), Pair(43, 87), Pair(55, 95), Pair(76, 94),
      Pair(63, 93), Pair(67, 92), Pair(47, 88), Pair(54, 84), Pair(25, 88), Pair(27, 74)
  }
}};

constexpr RookMobilityTable<ScorePair> kRookMobility = {{
  {
      Pair(-32, -59), Pair(-22, -25), Pair(-22, -13), Pair(-19, -4), Pair(-17, -4), Pair(-10, -5), Pair(-5, 0), Pair(-1, 4),
      Pair(3, 10), Pair(5, 15), Pair(8, 17), Pair(6, 23), Pair(1, 27), Pair(-1, 22), Pair(-22, 32)
  },
  {
      Pair(99, 132), Pair(105, 152), Pair(109, 171), Pair(111, 182), Pair(116, 185), Pair(123, 187), Pair(129, 186), Pair(138, 182),
      Pair(140, 184), Pair(152, 178), Pair(155, 177), Pair(163, 171), Pair(164, 171), Pair(163, 162), Pair(142, 157)
  },
  {
      Pair(92, 128), Pair(95, 159), Pair(96, 161), Pair(101, 172), Pair(104, 179), Pair(105, 184), Pair(106, 186), Pair(112, 182),
      Pair(118, 183), Pair(125, 183), Pair(132, 181), Pair(142, 176), Pair(154, 170), Pair(166, 164), Pair(180, 150)
  },
  {
      Pair(110, 105), Pair(109, 129), Pair(101, 142), Pair(106, 166), Pair(107, 177), Pair(97, 188), Pair(104, 188), Pair(109, 185),
      Pair(111, 186), Pair(124, 184), Pair(128, 182), Pair(149, 175), Pair(163, 171), Pair(158, 166), Pair(159, 157)
  },
  {
      Pair(77, 76), Pair(92, 110), Pair(89, 139), Pair(105, 161), Pair(90, 174), Pair(106, 177), Pair(93, 183), Pair(103, 177),
      Pair(114, 173), Pair(123, 175), Pair(131, 170), Pair(136, 169), Pair(142, 162), Pair(150, 154), Pair(130, 147)
  },
  {
      Pair(48, 54), Pair(63, 111), Pair(63, 125), Pair(80, 154), Pair(85, 162), Pair(96, 166), Pair(105, 174), Pair(102, 168),
      Pair(110, 166), Pair(112, 165), Pair(115, 167), Pair(126, 159), Pair(129, 154), Pair(136, 144), Pair(120, 141)
  },
  {
      Pair(15, 10), Pair(9, 37), Pair(19, 63), Pair(38, 104), Pair(43, 122), Pair(49, 130), Pair(80, 150), Pair(81, 147),
      Pair(79, 146), Pair(93, 151), Pair(96, 143), Pair(90, 136), Pair(99, 123), Pair(98, 112), Pair(85, 117)
  }
}};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {{
  {
      Pair(-85, -118), Pair(-69, -217), Pair(-58, -64), Pair(-50, -28), Pair(-51, 4), Pair(-50, 27), Pair(-47, 42), Pair(-47, 64),
      Pair(-45, 76), Pair(-42, 77), Pair(-43, 90), Pair(-42, 95), Pair(-39, 94), Pair(-40, 97), Pair(-41, 98), Pair(-39, 94),
      Pair(-41, 94), Pair(-40, 89), Pair(-37, 82), Pair(-35, 70), Pair(-31, 50), Pair(-8, 16), Pair(-14, 2), Pair(0, -25),
      Pair(38, -54), Pair(175, -118), Pair(182, -34), Pair(99, 2)
  },
  {
      Pair(86, 13), Pair(169, 69), Pair(174, 141), Pair(179, 190), Pair(181, 218), Pair(188, 229), Pair(192, 241), Pair(195, 251),
      Pair(198, 251), Pair(203, 251), Pair(207, 252), Pair(210, 250), Pair(210, 249), Pair(212, 246), Pair(211, 241), Pair(215, 236),
      Pair(216, 232), Pair(214, 224), Pair(209, 217), Pair(212, 209), Pair(204, 193), Pair(188, 186), Pair(152, 158), Pair(115, 145),
      Pair(75, 107), Pair(50, 78), Pair(12, 22), Pair(7, 16)
  },
  {
      Pair(50, 41), Pair(112, 93), Pair(159, 113), Pair(168, 146), Pair(174, 184), Pair(180, 216), Pair(182, 236), Pair(185, 251),
      Pair(189, 256), Pair(191, 260), Pair(198, 257), Pair(202, 260), Pair(207, 254), Pair(209, 256), Pair(215, 249), Pair(218, 245),
      Pair(222, 238), Pair(224, 231), Pair(219, 221), Pair(223, 209), Pair(215, 202), Pair(208, 186), Pair(183, 177), Pair(159, 162),
      Pair(124, 150), Pair(78, 120), Pair(35, 54), Pair(23, 46)
  },
  {
      Pair(7, 12), Pair(32, 34), Pair(40, 40), Pair(66, 56), Pair(135, 100), Pair(172, 142), Pair(174, 176), Pair(184, 207),
      Pair(186, 221), Pair(198, 237), Pair(201, 239), Pair(206, 245), Pair(201, 243), Pair(201, 243), Pair(213, 238), Pair(215, 236),
      Pair(213, 232), Pair(218, 227), Pair(208, 215), Pair(206, 211), Pair(193, 198), Pair(183, 189), Pair(151, 174), Pair(134, 162),
      Pair(81, 122), Pair(72, 117), Pair(33, 58), Pair(21, 43)
  },
  {
      Pair(7, 11), Pair(7, 6), Pair(11, 18), Pair(12, 11), Pair(13, 19), Pair(42, 40), Pair(95, 94), Pair(115, 118),
      Pair(139, 141), Pair(148, 169), Pair(164, 195), Pair(173, 213), Pair(180, 213), Pair(189, 220), Pair(186, 219), Pair(186, 217),
      Pair(189, 213), Pair(183, 205), Pair(185, 206), Pair(182, 200), Pair(168, 187), Pair(167, 180), Pair(125, 163), Pair(109, 145),
      Pair(73, 116), Pair(57, 97), Pair(15, 34), Pair(9, 21)
  },
  {
      Pair(1, 2), Pair(6, 11), Pair(7, 12), Pair(-3, -4), Pair(13, 12), Pair(21, 30), Pair(43, 55), Pair(57, 82),
      Pair(76, 110), Pair(99, 147), Pair(145, 188), Pair(151, 196), Pair(160, 199), Pair(168, 201), Pair(178, 207), Pair(183, 204),
      Pair(188, 202), Pair(184, 200), Pair(183, 193), Pair(176, 192), Pair(170, 179), Pair(172, 173), Pair(132, 158), Pair(116, 142),
      Pair(73, 112), Pair(77, 116), Pair(14, 36), Pair(28, 58)
  },
  {
      Pair(0, 0), Pair(2, 6), Pair(8, 13), Pair(7, 10), Pair(4, 6), Pair(7, 14), Pair(10, 16), Pair(21, 36),
      Pair(36, 58), Pair(65, 95), Pair(86, 128), Pair(96, 134), Pair(113, 155), Pair(124, 159), Pair(157, 187), Pair(148, 178),
      Pair(147, 179), Pair(144, 172), Pair(143, 172), Pair(132, 158), Pair(136, 160), Pair(135, 152), Pair(92, 129), Pair(91, 126),
      Pair(60, 101), Pair(46, 86), Pair(17, 42), Pair(19, 43)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPassedPawnBonus = {{
  {
      Pair(0, 0), Pair(-34, -63), Pair(-14, -63), Pair(-1, -38), Pair(34, -12), Pair(44, 46), Pair(129, 97), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-42, -14), Pair(-24, -8), Pair(0, 6), Pair(36, 26), Pair(33, 83), Pair(69, 68), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-67, -14), Pair(-50, -7), Pair(-20, 7), Pair(30, 24), Pair(50, 76), Pair(113, 93), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-82, -22), Pair(-61, -13), Pair(-50, 15), Pair(8, 32), Pair(48, 77), Pair(121, 93), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-89, -25), Pair(-68, -21), Pair(-52, 7), Pair(-6, 36), Pair(47, 75), Pair(132, 96), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-82, -14), Pair(-66, -19), Pair(-57, 0), Pair(-18, 34), Pair(52, 75), Pair(127, 87), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-35, -7), Pair(-33, -7), Pair(-29, 13), Pair(9, 32), Pair(37, 55), Pair(83, 60), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPawnPhalanxBonus = {{
  {
      Pair(0, 0), Pair(10, 1), Pair(17, 5), Pair(20, 19), Pair(54, 67), Pair(102, 168), Pair(-140, 466), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 6), Pair(11, 18), Pair(13, 26), Pair(35, 53), Pair(74, 112), Pair(21, 48), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 12), Pair(13, 12), Pair(11, 24), Pair(47, 65), Pair(78, 131), Pair(34, 98), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-3, 6), Pair(9, 14), Pair(5, 27), Pair(42, 66), Pair(55, 117), Pair(20, 78), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-1, 4), Pair(12, 8), Pair(23, 19), Pair(46, 63), Pair(31, 105), Pair(12, 55), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(20, 1), Pair(-3, 8), Pair(18, 12), Pair(42, 53), Pair(36, 84), Pair(16, 88), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(22, 10), Pair(23, 21), Pair(11, 36), Pair(12, 51), Pair(1, 39), Pair(-2, -4), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kDefendedPawnBonus = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(24, 19), Pair(13, 13), Pair(17, 15), Pair(30, 61), Pair(137, 35), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(16, 20), Pair(11, 16), Pair(15, 22), Pair(18, 43), Pair(76, 47), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(22, 11), Pair(13, 10), Pair(11, 17), Pair(30, 41), Pair(78, 47), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(21, 9), Pair(14, 3), Pair(8, 14), Pair(34, 36), Pair(43, 32), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(11, 8), Pair(25, 1), Pair(22, 6), Pair(50, 24), Pair(30, 24), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(19, 9), Pair(14, 8), Pair(30, 12), Pair(39, 18), Pair(22, -24), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(32, 15), Pair(36, 9), Pair(42, 24), Pair(28, -3), Pair(-2, -27), Pair(0, 0)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kDoubledPawnPenalty = {{
  {
      Pair(11, -60), Pair(25, -37), Pair(-2, -20), Pair(-3, -22), Pair(-16, -8), Pair(-5, -10), Pair(85, -18), Pair(37, -50)
  },
  {
      Pair(-70, -19), Pair(-22, -21), Pair(-6, -17), Pair(-14, -7), Pair(-26, 5), Pair(-19, 0), Pair(-33, -15), Pair(-45, -16)
  },
  {
      Pair(-32, -39), Pair(-20, -18), Pair(-14, -10), Pair(-12, -9), Pair(-22, -2), Pair(-32, 0), Pair(-40, -8), Pair(-62, -22)
  },
  {
      Pair(-74, -32), Pair(-58, -15), Pair(-27, -13), Pair(-25, -9), Pair(-30, -7), Pair(-51, -5), Pair(-49, -12), Pair(-95, -23)
  },
  {
      Pair(-56, -39), Pair(-58, -33), Pair(-57, -23), Pair(-11, -38), Pair(-31, -21), Pair(-44, -21), Pair(-72, -21), Pair(-64, -41)
  },
  {
      Pair(-32, -62), Pair(-39, -44), Pair(-66, -33), Pair(-22, -46), Pair(-24, -37), Pair(-70, -31), Pair(-63, -36), Pair(-52, -59)
  },
  {
      Pair(-9, -40), Pair(-6, -24), Pair(-21, -37), Pair(-10, -45), Pair(-1, -19), Pair(-39, -45), Pair(-17, -41), Pair(-21, -63)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kIsolatedPawnPenalty = {{
  {
      Pair(-23, 16), Pair(-6, -3), Pair(-14, -6), Pair(-11, -9), Pair(-19, -6), Pair(-13, -4), Pair(-8, 8), Pair(-49, 3)
  },
  {
      Pair(20, 3), Pair(1, -15), Pair(-8, -5), Pair(-9, -9), Pair(-9, -10), Pair(10, -14), Pair(4, -12), Pair(16, -5)
  },
  {
      Pair(11, 2), Pair(4, -14), Pair(-1, -10), Pair(-2, -14), Pair(3, -20), Pair(11, -14), Pair(4, -14), Pair(50, -12)
  },
  {
      Pair(20, 3), Pair(12, -18), Pair(5, -9), Pair(18, -22), Pair(17, -21), Pair(19, -15), Pair(19, -16), Pair(51, -10)
  },
  {
      Pair(34, 6), Pair(38, -18), Pair(17, -3), Pair(28, -19), Pair(24, -18), Pair(29, -14), Pair(43, -18), Pair(37, 0)
  },
  {
      Pair(49, 7), Pair(66, -17), Pair(27, 1), Pair(61, -11), Pair(42, -15), Pair(38, -8), Pair(51, -13), Pair(59, 3)
  },
  {
      Pair(73, 5), Pair(70, -13), Pair(51, 0), Pair(86, -3), Pair(83, -17), Pair(59, -4), Pair(101, -14), Pair(86, 7)
  }
}};

constexpr KingBuckets<std::array<FileTable<ScorePair>, 2>> kRookOnFileBonus = {{
  {{ // Bucket 0
    {
      Pair(23, 8), Pair(22, 8), Pair(24, 14), Pair(24, 9), Pair(27, 12), Pair(34, 8), Pair(31, 5), Pair(83, -17)
    },
    {
      Pair(6, 23), Pair(10, 8), Pair(15, 9), Pair(17, 7), Pair(16, 7), Pair(11, 5), Pair(17, -11), Pair(43, -9)
    }
  }},
  {{ // Bucket 1
    {
      Pair(53, 15), Pair(24, 28), Pair(21, 31), Pair(23, 27), Pair(37, 35), Pair(55, 10), Pair(63, 18), Pair(92, -1)
    },
    {
      Pair(57, 15), Pair(26, 18), Pair(11, 31), Pair(19, 14), Pair(39, 18), Pair(33, 5), Pair(38, 8), Pair(45, 4)
    }
  }},
  {{ // Bucket 2
    {
      Pair(35, 16), Pair(29, 17), Pair(25, 25), Pair(18, 33), Pair(26, 32), Pair(47, 11), Pair(49, 11), Pair(84, 0)
    },
    {
      Pair(13, 30), Pair(12, 20), Pair(14, 15), Pair(11, 20), Pair(13, 17), Pair(28, 4), Pair(27, 1), Pair(29, 9)
    }
  }},
  {{ // Bucket 3
    {
      Pair(25, 24), Pair(12, 21), Pair(13, 29), Pair(-1, 39), Pair(19, 40), Pair(28, 26), Pair(33, 19), Pair(74, 15)
    },
    {
      Pair(11, 39), Pair(6, 20), Pair(13, 20), Pair(23, 12), Pair(17, 19), Pair(22, 10), Pair(18, 7), Pair(36, 18)
    }
  }},
  {{ // Bucket 4
    {
      Pair(16, 35), Pair(23, 30), Pair(14, 44), Pair(12, 49), Pair(19, 54), Pair(30, 35), Pair(17, 36), Pair(52, 32)
    },
    {
      Pair(0, 56), Pair(0, 34), Pair(21, 29), Pair(23, 26), Pair(0, 35), Pair(19, 19), Pair(6, 19), Pair(-28, 48)
    }
  }},
  {{ // Bucket 5
    {
      Pair(36, 43), Pair(19, 42), Pair(24, 52), Pair(28, 63), Pair(28, 62), Pair(21, 45), Pair(22, 39), Pair(29, 48)
    },
    {
      Pair(31, 66), Pair(28, 43), Pair(16, 54), Pair(35, 44), Pair(12, 42), Pair(22, 21), Pair(24, 23), Pair(21, 44)
    }
  }},
  {{ // Bucket 6
    {
      Pair(67, 75), Pair(61, 78), Pair(53, 88), Pair(61, 92), Pair(56, 81), Pair(47, 85), Pair(56, 73), Pair(46, 65)
    },
    {
      Pair(44, 88), Pair(16, 59), Pair(18, 52), Pair(18, 45), Pair(34, 48), Pair(32, 53), Pair(12, 62), Pair(32, 58)
    }
  }}
}};

constexpr KingBuckets<std::array<ScorePair, 12>> kPawnShelterTable = {{
  {
      Pair(13, -2), Pair(25, -6), Pair(15, -1),
      Pair(34, -16), Pair(31, -14), Pair(33, -16),
      Pair(45, -10), Pair(0, 0), Pair(37, -7),
      Pair(3, 1), Pair(14, -10), Pair(0, 3)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 21>> kPawnStormTable = {{
  {
      Pair(-2, -1), Pair(-7, -1), Pair(-1, 0),
      Pair(-5, 2), Pair(-15, 6), Pair(-5, 2),
      Pair(-2, -2), Pair(-11, 3), Pair(2, -3),
      Pair(9, 0), Pair(-7, 3), Pair(11, 0),
      Pair(33, -10), Pair(31, 2), Pair(27, -9),
      Pair(48, -8), Pair(-24, -18), Pair(41, -20),
      Pair(5, -36), Pair(0, 0), Pair(7, -36)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 8>> kKingPPDistanceTable = {{
  {
      Pair(0, 0), Pair(-7, 37), Pair(-5, 36), Pair(-5, 31), Pair(5, 27), Pair(6, 27), Pair(-1, 33), Pair(-21, 31)
  },
  {
      Pair(0, 0), Pair(-7, 6), Pair(-10, 8), Pair(-6, 9), Pair(-14, 13), Pair(-8, 13), Pair(69, 68), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 16), Pair(-8, 23), Pair(-3, 20), Pair(-5, 19), Pair(-13, 18), Pair(-9, 13), Pair(5, -3)
  },
  {
      Pair(0, 0), Pair(-7, 34), Pair(-7, 26), Pair(-19, 23), Pair(-21, 18), Pair(-49, 20), Pair(-30, 8), Pair(-48, -1)
  },
  {
      Pair(0, 0), Pair(-5, 42), Pair(-10, 28), Pair(-5, 12), Pair(-42, 12), Pair(-33, 0), Pair(-41, 0), Pair(-33, -11)
  },
  {
      Pair(0, 0), Pair(2, 54), Pair(10, 28), Pair(-26, 8), Pair(-38, -6), Pair(-45, -12), Pair(-27, -15), Pair(-49, -9)
  },
  {
      Pair(0, 0), Pair(53, 87), Pair(36, 67), Pair(15, 13), Pair(-20, -5), Pair(-22, -15), Pair(-36, -19), Pair(-15, -11)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 8>> kEnemyKingPPDistanceTable = {{
  {
      Pair(0, 0), Pair(-89, 16), Pair(-45, 28), Pair(-21, 41), Pair(-2, 44), Pair(13, 46), Pair(43, 37), Pair(21, 30)
  },
  {
      Pair(0, 0), Pair(-72, -16), Pair(-41, 0), Pair(-17, 14), Pair(-4, 22), Pair(11, 24), Pair(37, 18), Pair(28, 15)
  },
  {
      Pair(0, 0), Pair(-93, -4), Pair(-56, 9), Pair(-27, 20), Pair(-4, 24), Pair(22, 23), Pair(52, 18), Pair(33, 26)
  },
  {
      Pair(0, 0), Pair(-77, -3), Pair(-64, 15), Pair(-33, 27), Pair(-4, 33), Pair(13, 36), Pair(56, 28), Pair(53, 32)
  },
  {
      Pair(0, 0), Pair(-53, -18), Pair(-48, 12), Pair(-24, 32), Pair(-10, 41), Pair(12, 45), Pair(54, 41), Pair(46, 44)
  },
  {
      Pair(0, 0), Pair(-48, -26), Pair(-44, 12), Pair(-27, 36), Pair(-4, 46), Pair(31, 49), Pair(43, 49), Pair(53, 51)
  },
  {
      Pair(0, 0), Pair(-14, -34), Pair(-33, 6), Pair(-18, 31), Pair(-6, 45), Pair(27, 46), Pair(54, 41), Pair(40, 44)
  }
}};

constexpr KingBuckets<ScorePair> kKingCantReachPPBonus = {
  Pair(-487, 270), Pair(24, 147), Pair(37, 167), Pair(34, 165), Pair(27, 139), Pair(37, 103), Pair(34, 100)
};


constexpr KingBuckets<std::array<FileTable<ScorePair>, 2>> kKingOnFilePenalty = {{
  {{ // Bucket 0
    {
      Pair(-1, -11), Pair(-61, 3), Pair(-11, -15), Pair(8, -19), Pair(-6, -13), Pair(3, -13), Pair(-78, 10), Pair(-35, 10)
    },
    {
      Pair(-36, 60), Pair(-43, 29), Pair(1, 6), Pair(20, -10), Pair(13, -11), Pair(30, -8), Pair(-57, 24), Pair(-31, 38)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-9, 45), Pair(-35, 18), Pair(0, 7), Pair(7, -6), Pair(-5, -7), Pair(1, 0), Pair(-27, 18), Pair(-16, 29)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 2
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 3
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 4
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 5
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 6
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(8, 12), Pair(20, 10), Pair(28, 7), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(10, 7), Pair(20, 18), Pair(57, 5), Pair(78, -12), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(25, -14), Pair(40, -15), Pair(55, -3), Pair(58, 9), Pair(21, 19), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(6, 20), Pair(28, 7), Pair(46, 23), Pair(105, -1), Pair(146, -1), Pair(157, 14), Pair(77, 24)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(12, 2), Pair(25, -7), Pair(61, -28), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(11, 3), Pair(17, 4), Pair(35, -16), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(12, 1), Pair(26, 5), Pair(50, -2), Pair(53, -17), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(18, -5), Pair(28, -4), Pair(25, 17), Pair(23, 22), Pair(2, 44), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-10, 187), Pair(12, 192), Pair(32, 193), Pair(97, 173), Pair(131, 165), Pair(159, 163), Pair(86, 104)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 2
    {
      Pair(0, 0), Pair(15, 0), Pair(30, -2), Pair(62, -12), Pair(71, -44), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(20, 5), Pair(30, 3), Pair(39, -4), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(19, 0), Pair(33, 4), Pair(58, 0), Pair(22, 1), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(14, -1), Pair(25, 2), Pair(22, 19), Pair(12, 30), Pair(-25, 48), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-22, 163), Pair(8, 163), Pair(55, 160), Pair(113, 150), Pair(133, 146), Pair(156, 153), Pair(101, 127)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 3
    {
      Pair(0, 0), Pair(21, -20), Pair(35, -20), Pair(51, -14), Pair(80, -17), Pair(91, -26), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(19, 7), Pair(29, 6), Pair(31, 8), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(10, 7), Pair(17, 12), Pair(22, 13), Pair(6, 14), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(6, 2), Pair(24, 5), Pair(-7, 30), Pair(7, 38), Pair(-15, 51), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(57, 181), Pair(110, 178), Pair(142, 184), Pair(178, 189), Pair(179, 184), Pair(175, 182), Pair(97, 139)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 4
    {
      Pair(0, 0), Pair(2, 14), Pair(10, 25), Pair(29, 31), Pair(74, 14), Pair(110, 10), Pair(173, -13), Pair(232, -63)
    },
    {
      Pair(0, 0), Pair(19, 9), Pair(19, 10), Pair(15, 11), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(8, 11), Pair(11, 17), Pair(22, 19), Pair(13, 36), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-32, 22), Pair(2, 21), Pair(-5, 40), Pair(8, 47), Pair(4, 59), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(136, 192), Pair(169, 190), Pair(182, 200), Pair(180, 195), Pair(180, 190), Pair(165, 185), Pair(71, 116)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 5
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(25, 10), Pair(48, 9), Pair(12, 12), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(40, 11), Pair(36, 20), Pair(20, 22), Pair(7, 31), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-35, 23), Pair(16, 22), Pair(10, 42), Pair(14, 53), Pair(8, 60), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(164, 184), Pair(173, 181), Pair(186, 192), Pair(175, 182), Pair(179, 185), Pair(170, 183), Pair(85, 131)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 6
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(22, 18), Pair(30, 15), Pair(11, 16), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(54, 25), Pair(46, 26), Pair(41, 42), Pair(6, 20), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(0, 20), Pair(20, 33), Pair(32, 45), Pair(16, 45), Pair(28, 69), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(150, 172), Pair(157, 164), Pair(160, 170), Pair(143, 166), Pair(139, 162), Pair(136, 163), Pair(64, 112)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }}
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {{
  {
      Pair(0, 0), Pair(37, 11), Pair(15, 19), Pair(34, 5), Pair(1, 89), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(24, 16), Pair(13, 18), Pair(15, 28), Pair(8, 60), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(54, 8), Pair(21, 18), Pair(8, 28), Pair(-8, 87), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(39, 9), Pair(6, 23), Pair(-43, 42), Pair(3, 78), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, 11), Pair(-27, 34), Pair(-88, 50), Pair(8, 70), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-10, 10), Pair(-47, 34), Pair(-100, 44), Pair(1, 67), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-46, 15), Pair(-45, 30), Pair(-137, 27), Pair(-22, 64), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {{ // Bucket 0
    {
      Pair(-24, 1), Pair(-22, 9)
    },
    {
      Pair(-72, -21), Pair(-58, -29)
    },
    {
      Pair(-52, -45), Pair(-63, -55)
    },
    {
      Pair(-74, 7), Pair(-66, -12)
    },
    {
      Pair(-62, 33), Pair(-66, 12)
    },
    {
      Pair(8, 14), Pair(-39, 14)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-19, 4), Pair(-15, 8)
    },
    {
      Pair(-54, -25), Pair(-54, -27)
    },
    {
      Pair(-58, -50), Pair(-66, -54)
    },
    {
      Pair(-89, 30), Pair(-74, -9)
    },
    {
      Pair(-33, -11), Pair(-65, 16)
    },
    {
      Pair(-11, 10), Pair(17, 19)
    }
  }},
  {{ // Bucket 2
    {
      Pair(-18, 3), Pair(-18, 12)
    },
    {
      Pair(-65, -21), Pair(-58, -35)
    },
    {
      Pair(-58, -46), Pair(-52, -71)
    },
    {
      Pair(-81, 13), Pair(-58, -28)
    },
    {
      Pair(-53, 40), Pair(-57, -16)
    },
    {
      Pair(-8, -2), Pair(-18, -15)
    }
  }},
  {{ // Bucket 3
    {
      Pair(-27, -4), Pair(-14, 12)
    },
    {
      Pair(-56, -14), Pair(-39, -48)
    },
    {
      Pair(-67, -55), Pair(-50, -60)
    },
    {
      Pair(-44, 14), Pair(-30, -33)
    },
    {
      Pair(-17, 10), Pair(-11, 0)
    },
    {
      Pair(-15, 0), Pair(-9, 0)
    }
  }},
  {{ // Bucket 4
    {
      Pair(-68, -1), Pair(-31, 17)
    },
    {
      Pair(-24, -21), Pair(12, -20)
    },
    {
      Pair(-22, -40), Pair(-19, -34)
    },
    {
      Pair(-26, -7), Pair(-21, -32)
    },
    {
      Pair(-3, -2), Pair(3, 3)
    },
    {
      Pair(-4, 18), Pair(-7, -9)
    }
  }},
  {{ // Bucket 5
    {
      Pair(-26, 7), Pair(-34, 20)
    },
    {
      Pair(0, -17), Pair(-15, -14)
    },
    {
      Pair(-14, -33), Pair(-16, -23)
    },
    {
      Pair(-14, -6), Pair(-5, -6)
    },
    {
      Pair(-1, 1), Pair(-1, -2)
    },
    {
      Pair(-6, 13), Pair(-3, -1)
    }
  }},
  {{ // Bucket 6
    {
      Pair(-13, 1), Pair(-32, 13)
    },
    {
      Pair(-4, -2), Pair(1, 8)
    },
    {
      Pair(-1, 2), Pair(0, 0)
    },
    {
      Pair(-10, -14), Pair(-4, -12)
    },
    {
      Pair(-1, 0), Pair(0, 0)
    },
    {
      Pair(-5, -27), Pair(1, 1)
    }
  }}
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {{
  {
      Pair(0, 0), Pair(19, 33), Pair(20, 27), Pair(29, 17), Pair(23, -8), Pair(104, -82)
  },
  {
      Pair(0, 0), Pair(17, 29), Pair(25, 20), Pair(32, 3), Pair(35, -94), Pair(22, -27)
  },
  {
      Pair(0, 0), Pair(26, 31), Pair(26, 19), Pair(33, 9), Pair(43, -73), Pair(41, -13)
  },
  {
      Pair(0, 0), Pair(28, 34), Pair(13, 26), Pair(45, 4), Pair(45, -57), Pair(3, 13)
  },
  {
      Pair(0, 0), Pair(59, 26), Pair(17, 14), Pair(42, 9), Pair(-1, -28), Pair(-34, 26)
  },
  {
      Pair(0, 0), Pair(24, 38), Pair(2, 21), Pair(16, 22), Pair(-12, -36), Pair(3, 24)
  },
  {
      Pair(0, 0), Pair(-4, 17), Pair(-4, -3), Pair(6, 10), Pair(-5, -13), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {{ // Bucket 0
    {
      Pair(-3, -18), Pair(7, -6)
    },
    {
      Pair(-22, -1), Pair(-5, 0)
    },
    {
      Pair(-34, -30), Pair(-24, -34)
    },
    {
      Pair(-66, 1), Pair(-53, -10)
    },
    {
      Pair(-52, 51), Pair(-52, 53)
    },
    {
      Pair(-39, -22), Pair(-56, -50)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-1, -21), Pair(9, -9)
    },
    {
      Pair(-11, -4), Pair(-4, -5)
    },
    {
      Pair(-27, -30), Pair(-27, -32)
    },
    {
      Pair(-71, -4), Pair(-51, -11)
    },
    {
      Pair(-37, 50), Pair(-45, 60)
    },
    {
      Pair(-75, -11), Pair(-74, -11)
    }
  }},
  {{ // Bucket 2
    {
      Pair(4, -26), Pair(6, -6)
    },
    {
      Pair(-28, -3), Pair(2, -7)
    },
    {
      Pair(-34, -25), Pair(-27, -27)
    },
    {
      Pair(-74, 9), Pair(-45, -17)
    },
    {
      Pair(-54, 76), Pair(-35, 8)
    },
    {
      Pair(-53, -5), Pair(-68, -27)
    }
  }},
  {{ // Bucket 3
    {
      Pair(9, -27), Pair(-3, -2)
    },
    {
      Pair(-18, 5), Pair(-20, 9)
    },
    {
      Pair(-62, -17), Pair(-30, -29)
    },
    {
      Pair(-64, 5), Pair(-53, -13)
    },
    {
      Pair(-21, 47), Pair(-6, 20)
    },
    {
      Pair(-23, -12), Pair(-27, -22)
    }
  }},
  {{ // Bucket 4
    {
      Pair(-12, -21), Pair(-11, -7)
    },
    {
      Pair(-9, -23), Pair(11, 13)
    },
    {
      Pair(-25, -17), Pair(-46, -25)
    },
    {
      Pair(-35, 4), Pair(-12, -6)
    },
    {
      Pair(16, 36), Pair(5, 6)
    },
    {
      Pair(-16, -14), Pair(-5, -14)
    }
  }},
  {{ // Bucket 5
    {
      Pair(-11, -18), Pair(4, -15)
    },
    {
      Pair(-6, -17), Pair(2, 7)
    },
    {
      Pair(-10, -20), Pair(-31, -24)
    },
    {
      Pair(-18, -4), Pair(-7, -3)
    },
    {
      Pair(16, 32), Pair(5, 6)
    },
    {
      Pair(-9, 5), Pair(-4, -9)
    }
  }},
  {{ // Bucket 6
    {
      Pair(-16, -15), Pair(-21, -11)
    },
    {
      Pair(-9, -37), Pair(-7, -15)
    },
    {
      Pair(-3, -12), Pair(-5, -10)
    },
    {
      Pair(-5, -4), Pair(0, 1)
    },
    {
      Pair(4, 11), Pair(0, 2)
    },
    {
      Pair(-5, 5), Pair(1, 3)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {{ // Bucket 0
    {
      Pair(-13, -16), Pair(1, -4)
    },
    {
      Pair(-42, -30), Pair(-24, -37)
    },
    {
      Pair(-10, -4), Pair(-2, -19)
    },
    {
      Pair(-67, 3), Pair(-49, -5)
    },
    {
      Pair(-74, 44), Pair(-52, -6)
    },
    {
      Pair(-29, -32), Pair(-65, -14)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-14, -13), Pair(-2, -2)
    },
    {
      Pair(-48, -11), Pair(-23, -19)
    },
    {
      Pair(-5, -28), Pair(-7, -5)
    },
    {
      Pair(-66, 5), Pair(-44, -4)
    },
    {
      Pair(-68, 21), Pair(-48, -14)
    },
    {
      Pair(0, -4), Pair(-38, -15)
    }
  }},
  {{ // Bucket 2
    {
      Pair(-9, -20), Pair(-4, -4)
    },
    {
      Pair(-44, -17), Pair(-26, -26)
    },
    {
      Pair(-20, -15), Pair(-1, -18)
    },
    {
      Pair(-71, 5), Pair(-40, -18)
    },
    {
      Pair(-69, 25), Pair(-78, -23)
    },
    {
      Pair(-44, -13), Pair(-51, -31)
    }
  }},
  {{ // Bucket 3
    {
      Pair(12, -26), Pair(-10, -3)
    },
    {
      Pair(-40, -19), Pair(-21, -27)
    },
    {
      Pair(0, -16), Pair(-33, -7)
    },
    {
      Pair(-73, 14), Pair(-35, -15)
    },
    {
      Pair(-44, 7), Pair(-34, -11)
    },
    {
      Pair(-5, -14), Pair(-18, -31)
    }
  }},
  {{ // Bucket 4
    {
      Pair(-1, -19), Pair(-8, -13)
    },
    {
      Pair(-29, -21), Pair(-15, -33)
    },
    {
      Pair(-8, -16), Pair(-18, -20)
    },
    {
      Pair(-16, 17), Pair(-24, 1)
    },
    {
      Pair(-9, 15), Pair(-7, 0)
    },
    {
      Pair(-6, -12), Pair(1, 6)
    }
  }},
  {{ // Bucket 5
    {
      Pair(8, -29), Pair(7, -20)
    },
    {
      Pair(-17, -41), Pair(-17, -36)
    },
    {
      Pair(-1, -27), Pair(-7, -9)
    },
    {
      Pair(-9, 2), Pair(-9, 1)
    },
    {
      Pair(5, 21), Pair(-1, 3)
    },
    {
      Pair(-8, 7), Pair(-3, -10)
    }
  }},
  {{ // Bucket 6
    {
      Pair(-30, -43), Pair(-34, -28)
    },
    {
      Pair(-10, -21), Pair(-9, -30)
    },
    {
      Pair(-7, -22), Pair(-4, -3)
    },
    {
      Pair(-10, -15), Pair(-4, -7)
    },
    {
      Pair(5, 12), Pair(0, 0)
    },
    {
      Pair(-4, -10), Pair(1, 5)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {{ // Bucket 0
    {
      Pair(-1, -24), Pair(8, 0)
    },
    {
      Pair(-29, -31), Pair(-3, -14)
    },
    {
      Pair(-20, -29), Pair(-8, -9)
    },
    {
      Pair(-8, -7), Pair(3, 9)
    },
    {
      Pair(-82, 76), Pair(-56, 20)
    },
    {
      Pair(5, -33), Pair(-53, -15)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, -29), Pair(14, -11)
    },
    {
      Pair(-32, -22), Pair(4, -17)
    },
    {
      Pair(-14, -23), Pair(-10, 0)
    },
    {
      Pair(16, -20), Pair(2, 2)
    },
    {
      Pair(-90, 71), Pair(-60, -7)
    },
    {
      Pair(-51, -1), Pair(-44, -21)
    }
  }},
  {{ // Bucket 2
    {
      Pair(8, -30), Pair(10, -7)
    },
    {
      Pair(-20, -21), Pair(-1, -10)
    },
    {
      Pair(-16, -24), Pair(-13, -5)
    },
    {
      Pair(-13, -3), Pair(12, 4)
    },
    {
      Pair(-101, 100), Pair(-65, 20)
    },
    {
      Pair(-43, 1), Pair(-67, -16)
    }
  }},
  {{ // Bucket 3
    {
      Pair(36, -36), Pair(10, -9)
    },
    {
      Pair(-9, -18), Pair(-16, -2)
    },
    {
      Pair(-14, -24), Pair(-13, -2)
    },
    {
      Pair(10, -10), Pair(-9, 18)
    },
    {
      Pair(-47, 87), Pair(-28, 10)
    },
    {
      Pair(-35, -8), Pair(-40, -29)
    }
  }},
  {{ // Bucket 4
    {
      Pair(-2, -21), Pair(12, -9)
    },
    {
      Pair(8, -20), Pair(3, -3)
    },
    {
      Pair(-19, -23), Pair(-10, -2)
    },
    {
      Pair(-7, -6), Pair(-31, 19)
    },
    {
      Pair(-5, 38), Pair(-25, -7)
    },
    {
      Pair(-22, 7), Pair(-15, -21)
    }
  }},
  {{ // Bucket 5
    {
      Pair(12, -25), Pair(2, -7)
    },
    {
      Pair(-3, -23), Pair(-17, -12)
    },
    {
      Pair(4, -29), Pair(11, -10)
    },
    {
      Pair(19, -20), Pair(-20, 12)
    },
    {
      Pair(8, 59), Pair(-8, 9)
    },
    {
      Pair(-19, 1), Pair(-11, -5)
    }
  }},
  {{ // Bucket 6
    {
      Pair(-8, -33), Pair(-42, -18)
    },
    {
      Pair(-26, -36), Pair(-8, -21)
    },
    {
      Pair(-15, -38), Pair(-1, -11)
    },
    {
      Pair(-18, -33), Pair(-16, -13)
    },
    {
      Pair(5, 31), Pair(-4, 0)
    },
    {
      Pair(-10, -2), Pair(-13, -22)
    }
  }}
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {{
  {
      Pair(21, 15), Pair(25, 16), Pair(36, 32), Pair(46, 24), Pair(32, 47), Pair(44, 38), Pair(38, 32), Pair(34, 36),
      Pair(23, -6), Pair(18, 13), Pair(25, 10), Pair(2, 56), Pair(7, 27), Pair(8, 21), Pair(13, 19), Pair(5, 9),
      Pair(9, 4), Pair(9, 0), Pair(4, 18), Pair(12, 24), Pair(2, 25), Pair(-4, 22), Pair(3, -10), Pair(1, 2)
  },
  {
      Pair(9, 19), Pair(14, 19), Pair(39, 25), Pair(34, 21), Pair(38, 23), Pair(53, 40), Pair(23, 37), Pair(1, 16),
      Pair(19, 14), Pair(10, 21), Pair(15, 23), Pair(0, 34), Pair(17, 22), Pair(28, 12), Pair(16, 21), Pair(12, 23),
      Pair(18, 12), Pair(22, 12), Pair(8, 21), Pair(7, 15), Pair(4, 9), Pair(-6, 17), Pair(-7, 25), Pair(4, 19)
  },
  {
      Pair(9, 13), Pair(20, 15), Pair(41, 20), Pair(28, 20), Pair(18, 33), Pair(20, 30), Pair(20, 38), Pair(19, 15),
      Pair(-27, 34), Pair(15, 12), Pair(13, 25), Pair(24, 28), Pair(7, 26), Pair(-3, 21), Pair(8, 14), Pair(-6, 17),
      Pair(5, 11), Pair(25, -3), Pair(17, 7), Pair(8, 22), Pair(13, 8), Pair(-3, 20), Pair(-18, 6), Pair(7, -4)
  },
  {
      Pair(2, 9), Pair(5, 35), Pair(32, 24), Pair(33, 23), Pair(35, 26), Pair(35, 32), Pair(4, 18), Pair(13, 8),
      Pair(6, 16), Pair(4, 15), Pair(13, 25), Pair(29, 28), Pair(17, 28), Pair(19, 21), Pair(-7, 29), Pair(44, 19),
      Pair(31, 1), Pair(-3, 9), Pair(14, 16), Pair(23, 11), Pair(4, 14), Pair(4, 10), Pair(8, 16), Pair(0, 3)
  },
  {
      Pair(-3, 1), Pair(6, 20), Pair(-2, 8), Pair(3, 24), Pair(13, 23), Pair(7, 31), Pair(17, 21), Pair(1, -1),
      Pair(5, 22), Pair(6, 27), Pair(10, 27), Pair(-9, 23), Pair(-5, 21), Pair(12, 33), Pair(-8, 18), Pair(-2, 13),
      Pair(14, 24), Pair(14, 25), Pair(3, 18), Pair(25, 18), Pair(23, 28), Pair(-11, 6), Pair(8, 21), Pair(-1, 5)
  },
  {
      Pair(3, 3), Pair(5, 14), Pair(5, 7), Pair(16, 31), Pair(-5, -5), Pair(1, 10), Pair(-2, 6), Pair(2, 9),
      Pair(7, 13), Pair(6, 30), Pair(-2, 24), Pair(-5, 22), Pair(-10, 17), Pair(7, 21), Pair(4, 27), Pair(5, 16),
      Pair(1, 8), Pair(-1, -1), Pair(19, 23), Pair(1, 24), Pair(2, 29), Pair(0, 32), Pair(-7, 11), Pair(7, 11)
  },
  {
      Pair(1, 3), Pair(0, 2), Pair(0, -3), Pair(5, 15), Pair(1, -1), Pair(4, 17), Pair(4, 14), Pair(0, 0),
      Pair(3, 9), Pair(-2, 2), Pair(9, 25), Pair(6, 27), Pair(2, -1), Pair(5, 12), Pair(-1, -5), Pair(1, 6),
      Pair(0, -4), Pair(0, 4), Pair(6, 22), Pair(1, 5), Pair(-11, -17), Pair(4, 16), Pair(-1, -1), Pair(2, 4)
  }
}};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {{
  {
      Pair(-6, 34), Pair(14, 19), Pair(26, 4), Pair(38, 14), Pair(55, 6), Pair(65, -15), Pair(13, 18), Pair(11, 5),
      Pair(-24, -8), Pair(23, 11), Pair(27, -7), Pair(28, 13), Pair(11, 22), Pair(9, 11), Pair(14, 19), Pair(8, -15),
      Pair(-30, 14), Pair(11, 10), Pair(5, 22), Pair(19, 16), Pair(18, 24), Pair(-3, 12), Pair(2, 0), Pair(-29, -12)
  },
  {
      Pair(16, 9), Pair(39, 3), Pair(33, -1), Pair(40, 9), Pair(35, 5), Pair(36, 8), Pair(27, 24), Pair(-35, -8),
      Pair(4, -9), Pair(16, 18), Pair(-2, 2), Pair(23, 5), Pair(13, 12), Pair(39, -7), Pair(11, 13), Pair(-30, -15),
      Pair(1, 20), Pair(-13, 7), Pair(9, 13), Pair(12, 0), Pair(16, 10), Pair(5, 2), Pair(7, -8), Pair(-80, -5)
  },
  {
      Pair(-17, 24), Pair(24, 10), Pair(41, 1), Pair(43, 2), Pair(34, 5), Pair(30, 21), Pair(18, 2), Pair(-10, -25),
      Pair(1, -19), Pair(34, -5), Pair(9, 3), Pair(26, 14), Pair(28, 5), Pair(24, -1), Pair(3, 13), Pair(1, -4),
      Pair(7, 9), Pair(25, 3), Pair(3, 6), Pair(21, 8), Pair(38, 6), Pair(2, -2), Pair(10, 2), Pair(-25, -8)
  },
  {
      Pair(13, 22), Pair(14, -4), Pair(5, -5), Pair(31, 5), Pair(19, -5), Pair(6, 14), Pair(10, 16), Pair(13, -1),
      Pair(-13, 2), Pair(41, 4), Pair(12, -8), Pair(14, -1), Pair(-1, 0), Pair(33, -2), Pair(11, 9), Pair(7, 6),
      Pair(-8, 17), Pair(43, -3), Pair(20, 5), Pair(20, 8), Pair(37, 10), Pair(-12, 12), Pair(12, 6), Pair(-19, -14)
  },
  {
      Pair(2, 10), Pair(-2, -4), Pair(9, -6), Pair(33, 11), Pair(1, -12), Pair(15, 4), Pair(12, 4), Pair(-2, 5),
      Pair(1, -14), Pair(-5, 7), Pair(2, -1), Pair(4, 2), Pair(26, -1), Pair(23, 8), Pair(12, 23), Pair(-2, 15),
      Pair(-6, 10), Pair(11, -3), Pair(2, 1), Pair(29, -5), Pair(29, -3), Pair(-2, 11), Pair(12, 15), Pair(-6, -5)
  },
  {
      Pair(3, 23), Pair(-1, -6), Pair(6, 6), Pair(9, -4), Pair(3, -24), Pair(8, 2), Pair(12, -3), Pair(-5, -15),
      Pair(0, 17), Pair(-2, 8), Pair(4, 4), Pair(1, 7), Pair(0, 11), Pair(4, -7), Pair(8, 22), Pair(0, 13),
      Pair(0, 16), Pair(1, 5), Pair(16, 1), Pair(-4, 3), Pair(12, 19), Pair(-6, 8), Pair(5, 26), Pair(-6, -8)
  },
  {
      Pair(4, 16), Pair(2, 0), Pair(1, -20), Pair(3, 2), Pair(2, 13), Pair(5, -3), Pair(1, -4), Pair(1, 2),
      Pair(0, 5), Pair(12, 29), Pair(4, -3), Pair(-1, 2), Pair(2, 3), Pair(-4, 2), Pair(0, 22), Pair(2, 1),
      Pair(2, 14), Pair(6, 20), Pair(8, 16), Pair(8, 5), Pair(11, 19), Pair(-1, 7), Pair(4, 10), Pair(3, 6)
  }
}};

constexpr KingBuckets<ScorePair> kBishopPairBonus = {{
  {
      Pair(37, 39)
  },
  {
      Pair(46, 33)
  },
  {
      Pair(43, 46)
  },
  {
      Pair(41, 50)
  },
  {
      Pair(52, 54)
  },
  {
      Pair(43, 80)
  },
  {
      Pair(37, 96)
  }
}};


constexpr ScorePair kTempoBonus = Pair(22, 15);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H