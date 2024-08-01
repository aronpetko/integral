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
using PieceSquareTable = PieceTable<SquareTable<T>>;

// [is_our_piece][pawn_position][piece_position]
template <typename T>
using PawnRelativePSQT = SideTable<SquareTable<PieceTable<SquareTable<T>>>>;

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
  Pair(75, 104), Pair(347, 292), Pair(401, 369), Pair(528, 696), Pair(1149, 1189), Pair(0, 0)
};

constexpr PawnRelativePSQT<ScorePair> kPawnPieceSquareTable = {{
  {{ // Bucket 0
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 7
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 8
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(25, -4), Pair(-42, 1), Pair(-47, -3), Pair(28, -9), Pair(-23, 16), Pair(-43, 6), Pair(35, -9),
        Pair(1, 36), Pair(22, 2), Pair(34, -32), Pair(9, -17), Pair(-23, -9), Pair(-20, 0), Pair(17, -2), Pair(-5, 5),
        Pair(-51, -8), Pair(2, -9), Pair(-19, -1), Pair(-20, -16), Pair(-18, -1), Pair(-8, -11), Pair(-6, -3), Pair(22, -7),
        Pair(13, 55), Pair(34, -33), Pair(34, -30), Pair(-2, -14), Pair(-1, -18), Pair(-8, -9), Pair(-8, -12), Pair(-29, 4),
        Pair(-103, 60), Pair(15, -20), Pair(16, -35), Pair(-3, -18), Pair(-8, -10), Pair(4, -12), Pair(-21, -17), Pair(-19, -9),
        Pair(0, 0), Pair(-9, 33), Pair(7, -8), Pair(-13, -1), Pair(4, -9), Pair(5, -16), Pair(11, -21), Pair(-28, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-102, -185), Pair(5, -14), Pair(125, -23), Pair(-26, 71), Pair(-128, -191), Pair(164, -172), Pair(52, -251), Pair(5, -51),
        Pair(54, 53), Pair(12, -34), Pair(109, -30), Pair(54, -57), Pair(-11, -42), Pair(-72, -115), Pair(14, -79), Pair(137, -13),
        Pair(48, -65), Pair(102, -128), Pair(-22, -5), Pair(0, 23), Pair(24, -58), Pair(54, -92), Pair(-29, -41), Pair(-47, 25),
        Pair(123, -16), Pair(85, -36), Pair(43, 2), Pair(-22, -14), Pair(58, -21), Pair(134, -79), Pair(154, -105), Pair(-56, -83),
        Pair(-35, -160), Pair(-45, -20), Pair(-33, -1), Pair(93, -52), Pair(-18, 9), Pair(154, -138), Pair(130, -95), Pair(2, -58),
        Pair(33, -70), Pair(-20, 42), Pair(31, 11), Pair(100, -19), Pair(61, -54), Pair(57, -79), Pair(88, -127), Pair(-12, -128),
        Pair(0, 0), Pair(54, -82), Pair(-131, 73), Pair(23, -42), Pair(54, -29), Pair(-110, -47), Pair(122, -128), Pair(83, -21),
        Pair(115, 93), Pair(96, 20), Pair(87, 65), Pair(13, -116), Pair(-54, -97), Pair(-16, -46), Pair(-137, -5), Pair(-29, -82)
      },
      { // Piece 2
        Pair(-55, -87), Pair(-81, 100), Pair(-14, -94), Pair(-97, 104), Pair(9, -63), Pair(-166, -58), Pair(-5, -183), Pair(38, 240),
        Pair(27, 102), Pair(-186, 20), Pair(98, 30), Pair(-11, -110), Pair(-67, 140), Pair(-155, 67), Pair(-209, 158), Pair(-81, 26),
        Pair(17, -16), Pair(1, 144), Pair(26, -36), Pair(-20, 30), Pair(105, 2), Pair(-85, 162), Pair(29, 22), Pair(6, 16),
        Pair(-27, 28), Pair(39, -44), Pair(101, 59), Pair(42, 23), Pair(50, 123), Pair(-4, 26), Pair(-197, 57), Pair(-121, -7),
        Pair(0, -132), Pair(129, -36), Pair(-88, 52), Pair(-21, 140), Pair(58, -67), Pair(-36, 75), Pair(18, 24), Pair(-76, 23),
        Pair(-113, 78), Pair(148, 7), Pair(-97, 168), Pair(-24, 21), Pair(-12, 78), Pair(58, -63), Pair(120, 8), Pair(-20, 7),
        Pair(0, 0), Pair(31, 156), Pair(87, -22), Pair(-97, 90), Pair(-20, 6), Pair(-43, -4), Pair(18, -25), Pair(28, 19),
        Pair(94, 183), Pair(-2, 143), Pair(-6, 45), Pair(-45, 12), Pair(9, 24), Pair(-53, 15), Pair(-114, -145), Pair(-159, -31)
      },
      { // Piece 3
        Pair(108, 51), Pair(161, 8), Pair(98, 5), Pair(-61, 4), Pair(-65, 74), Pair(132, -13), Pair(230, -16), Pair(166, 5),
        Pair(87, 66), Pair(244, -49), Pair(43, 4), Pair(187, 2), Pair(94, -39), Pair(228, -57), Pair(164, 21), Pair(12, 30),
        Pair(31, 91), Pair(190, -62), Pair(63, -3), Pair(8, 17), Pair(49, 9), Pair(-95, 88), Pair(-21, 80), Pair(-9, 13),
        Pair(-14, 82), Pair(-33, 35), Pair(69, 34), Pair(24, 56), Pair(120, -51), Pair(-20, 67), Pair(59, 23), Pair(30, 4),
        Pair(-92, 88), Pair(10, 28), Pair(-14, 50), Pair(163, -63), Pair(13, -5), Pair(29, 11), Pair(-116, 78), Pair(46, -3),
        Pair(29, 60), Pair(-91, 71), Pair(16, 32), Pair(-24, 46), Pair(67, -54), Pair(162, -60), Pair(46, -22), Pair(-25, 58),
        Pair(0, 0), Pair(0, 71), Pair(90, -12), Pair(15, 20), Pair(-31, 77), Pair(136, -58), Pair(60, 125), Pair(33, 39),
        Pair(49, 121), Pair(26, 33), Pair(20, 102), Pair(0, 87), Pair(15, 115), Pair(33, 78), Pair(131, 26), Pair(19, 89)
      },
      { // Piece 4
        Pair(31, -72), Pair(78, 7), Pair(77, -9), Pair(89, -80), Pair(117, -9), Pair(7, 69), Pair(-96, 21), Pair(104, 21),
        Pair(-29, 53), Pair(-19, 62), Pair(29, 108), Pair(-33, -33), Pair(13, 66), Pair(81, -131), Pair(6, 75), Pair(22, -97),
        Pair(14, -145), Pair(5, -31), Pair(-82, 29), Pair(-47, 133), Pair(0, 22), Pair(85, 24), Pair(-170, 65), Pair(-2, 24),
        Pair(93, -23), Pair(4, -48), Pair(-19, 129), Pair(-76, 134), Pair(-46, 83), Pair(39, -30), Pair(92, -77), Pair(10, 36),
        Pair(132, -208), Pair(-89, 44), Pair(-17, -65), Pair(-58, 35), Pair(-76, -3), Pair(89, -87), Pair(-43, 4), Pair(59, 32),
        Pair(-162, -155), Pair(91, 40), Pair(-16, -48), Pair(-80, -41), Pair(-89, 91), Pair(-6, -31), Pair(-160, 55), Pair(49, -87),
        Pair(0, 0), Pair(-16, 7), Pair(-8, -12), Pair(-6, -165), Pair(-101, 4), Pair(-10, -234), Pair(25, -21), Pair(-217, -81),
        Pair(-39, -84), Pair(4, -37), Pair(-66, 137), Pair(-66, 144), Pair(-78, -44), Pair(-129, 16), Pair(-152, 2), Pair(-86, -28)
      },
      { // Piece 5
        Pair(-3, -28), Pair(-29, -16), Pair(11, -92), Pair(17, -39), Pair(93, -103), Pair(-26, -11), Pair(-56, -91), Pair(2, -53),
        Pair(-94, -176), Pair(33, -49), Pair(-58, 14), Pair(-29, -5), Pair(-46, -42), Pair(130, 41), Pair(8, -72), Pair(-13, -65),
        Pair(-69, -163), Pair(-78, 17), Pair(76, -3), Pair(-36, -25), Pair(96, -38), Pair(142, -51), Pair(149, -45), Pair(32, -13),
        Pair(-110, -12), Pair(-80, 36), Pair(-46, 36), Pair(55, 7), Pair(-2, 25), Pair(-127, -9), Pair(-39, -8), Pair(58, -63),
        Pair(57, -8), Pair(-133, 91), Pair(148, -14), Pair(111, 22), Pair(5, 21), Pair(94, 1), Pair(31, -21), Pair(-10, -70),
        Pair(-95, 130), Pair(-45, 139), Pair(138, 46), Pair(-12, 53), Pair(71, 20), Pair(-46, 4), Pair(-45, -30), Pair(-23, 7),
        Pair(0, 0), Pair(-129, 192), Pair(27, 73), Pair(103, 33), Pair(5, 12), Pair(-56, 12), Pair(-24, 1), Pair(-11, -53),
        Pair(181, 134), Pair(49, 125), Pair(-73, 109), Pair(-65, -41), Pair(-42, -36), Pair(28, -78), Pair(-24, -65), Pair(-40, -54)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-25, 4), Pair(0, 0), Pair(23, -27), Pair(9, -3), Pair(58, -25), Pair(-34, 23), Pair(-110, -3), Pair(3, -8),
        Pair(-13, 1), Pair(-116, 11), Pair(-39, 7), Pair(31, -29), Pair(-49, 8), Pair(2, -12), Pair(-6, 2), Pair(-8, -15),
        Pair(30, -25), Pair(-1, -20), Pair(11, -21), Pair(-12, -3), Pair(-5, -10), Pair(-26, 6), Pair(-14, -5), Pair(-18, 4),
        Pair(24, -25), Pair(-30, -10), Pair(-12, 3), Pair(-4, -12), Pair(-8, -12), Pair(-22, -10), Pair(-48, -7), Pair(18, -19),
        Pair(14, -12), Pair(7, -21), Pair(13, -16), Pair(-17, -12), Pair(-15, -8), Pair(-17, -11), Pair(-28, -9), Pair(21, -16),
        Pair(7, -6), Pair(0, 0), Pair(6, -1), Pair(43, -34), Pair(-25, -24), Pair(3, -15), Pair(-31, -6), Pair(-9, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-37, -28), Pair(-9, -38), Pair(42, -59), Pair(-82, -103), Pair(-30, 86), Pair(120, -86), Pair(-9, -81), Pair(105, 36),
        Pair(-15, -177), Pair(-72, -7), Pair(135, 35), Pair(0, -54), Pair(81, -16), Pair(-35, -53), Pair(-17, -106), Pair(3, -182),
        Pair(91, 13), Pair(60, -26), Pair(-58, 38), Pair(-47, 60), Pair(145, -77), Pair(112, -53), Pair(-86, 19), Pair(12, -71),
        Pair(-140, 45), Pair(19, -33), Pair(9, 11), Pair(79, -42), Pair(151, -84), Pair(121, -26), Pair(51, -34), Pair(221, -85),
        Pair(213, -10), Pair(-70, 84), Pair(117, -47), Pair(46, -19), Pair(38, -28), Pair(-10, 35), Pair(-113, 14), Pair(-48, -56),
        Pair(-15, 133), Pair(68, -109), Pair(10, 94), Pair(-159, 10), Pair(-116, 19), Pair(14, -6), Pair(-36, 23), Pair(-53, -100),
        Pair(-131, -190), Pair(0, 0), Pair(-64, 10), Pair(-60, 111), Pair(57, -51), Pair(135, -132), Pair(-9, 14), Pair(-24, 156),
        Pair(0, 0), Pair(-2, 146), Pair(-201, -79), Pair(-30, -99), Pair(2, 35), Pair(-107, 38), Pair(-28, -145), Pair(-92, -8)
      },
      { // Piece 2
        Pair(-59, 61), Pair(-22, 73), Pair(-171, 35), Pair(-55, 15), Pair(-316, 44), Pair(7, -29), Pair(-51, 47), Pair(14, 70),
        Pair(-124, 30), Pair(25, 114), Pair(-17, 27), Pair(-153, 67), Pair(-26, 16), Pair(-7, 31), Pair(-59, 49), Pair(-123, 157),
        Pair(104, 12), Pair(-83, 110), Pair(-36, 95), Pair(44, 0), Pair(-70, 107), Pair(167, -2), Pair(22, 157), Pair(77, -108),
        Pair(-1, -8), Pair(-18, 95), Pair(37, -65), Pair(18, 64), Pair(63, 14), Pair(33, 162), Pair(-11, -72), Pair(-91, 61),
        Pair(120, -10), Pair(8, -93), Pair(71, 7), Pair(84, 18), Pair(-39, 163), Pair(20, -49), Pair(14, 63), Pair(81, -54),
        Pair(-161, 36), Pair(-113, 176), Pair(20, 65), Pair(-44, 160), Pair(50, 15), Pair(-59, 66), Pair(-9, 43), Pair(41, 8),
        Pair(20, 173), Pair(0, 0), Pair(-73, 153), Pair(7, -57), Pair(14, -31), Pair(-67, -9), Pair(-2, -9), Pair(16, -79),
        Pair(6, 4), Pair(-37, 241), Pair(-76, 78), Pair(0, 103), Pair(73, -21), Pair(-79, 52), Pair(-89, -79), Pair(25, 188)
      },
      { // Piece 3
        Pair(109, -131), Pair(124, 22), Pair(-90, 20), Pair(120, -17), Pair(63, -40), Pair(20, 72), Pair(149, 22), Pair(230, -40),
        Pair(14, 9), Pair(15, 34), Pair(118, -28), Pair(127, -49), Pair(146, -17), Pair(151, -25), Pair(108, -26), Pair(-96, 117),
        Pair(48, -1), Pair(72, 45), Pair(-39, -4), Pair(-43, -2), Pair(63, -39), Pair(-17, 33), Pair(-28, 28), Pair(88, 3),
        Pair(154, -66), Pair(9, 58), Pair(49, -16), Pair(26, 0), Pair(22, 7), Pair(-133, -11), Pair(72, 23), Pair(87, 24),
        Pair(-16, -47), Pair(-12, 50), Pair(-84, 99), Pair(-53, 20), Pair(-140, 34), Pair(137, 27), Pair(-190, 86), Pair(-68, 36),
        Pair(68, 18), Pair(-7, 55), Pair(-61, 39), Pair(116, -29), Pair(5, 95), Pair(-28, 76), Pair(25, -68), Pair(73, 2),
        Pair(120, -75), Pair(0, 0), Pair(-42, 48), Pair(-104, 128), Pair(-38, 42), Pair(196, -84), Pair(108, -50), Pair(188, -111),
        Pair(-3, 54), Pair(65, 85), Pair(-79, 24), Pair(-27, 65), Pair(28, 73), Pair(-45, 81), Pair(-50, 81), Pair(6, 4)
      },
      { // Piece 4
        Pair(115, 65), Pair(-36, 53), Pair(201, 49), Pair(20, 40), Pair(66, 34), Pair(53, -34), Pair(-64, -43), Pair(225, 46),
        Pair(-2, -10), Pair(-257, 125), Pair(78, 49), Pair(-137, 7), Pair(13, 96), Pair(-83, 129), Pair(-65, -57), Pair(-54, -120),
        Pair(-74, 127), Pair(-56, 91), Pair(-51, -94), Pair(21, 182), Pair(-33, 33), Pair(54, 162), Pair(-56, 28), Pair(73, -79),
        Pair(-111, 34), Pair(-159, 25), Pair(-91, -42), Pair(-37, 81), Pair(66, 51), Pair(98, -28), Pair(68, 51), Pair(164, -160),
        Pair(-47, 145), Pair(34, 0), Pair(-105, 77), Pair(-99, -58), Pair(-34, 78), Pair(-58, 61), Pair(-12, -103), Pair(154, -202),
        Pair(-126, -109), Pair(-106, -68), Pair(54, -51), Pair(-6, 82), Pair(-95, -7), Pair(-26, 13), Pair(73, -199), Pair(-6, -125),
        Pair(-18, -150), Pair(0, 0), Pair(-17, 3), Pair(-49, -154), Pair(0, -114), Pair(44, 55), Pair(120, -6), Pair(-76, -21),
        Pair(-61, -67), Pair(-31, 9), Pair(-104, -120), Pair(-89, 5), Pair(15, -219), Pair(-55, 27), Pair(-175, -53), Pair(-87, 89)
      },
      { // Piece 5
        Pair(-21, -63), Pair(-5, -24), Pair(1, 17), Pair(10, -98), Pair(49, -31), Pair(68, 108), Pair(-25, -12), Pair(-2, -139),
        Pair(-2, -10), Pair(-18, 8), Pair(5, -65), Pair(0, 2), Pair(-1, -86), Pair(-12, -27), Pair(45, -97), Pair(59, 43),
        Pair(-48, -90), Pair(6, -42), Pair(5, 41), Pair(20, -21), Pair(11, -52), Pair(41, -41), Pair(2, -30), Pair(83, -6),
        Pair(-46, -25), Pair(-27, 41), Pair(-80, 19), Pair(98, 27), Pair(77, 16), Pair(-74, -5), Pair(-33, -18), Pair(-48, -19),
        Pair(1, -23), Pair(-30, 24), Pair(58, 17), Pair(-73, 42), Pair(13, -4), Pair(130, -18), Pair(116, -59), Pair(37, -4),
        Pair(34, 61), Pair(68, 20), Pair(44, 73), Pair(35, 33), Pair(-39, 28), Pair(51, -5), Pair(62, -40), Pair(77, -126),
        Pair(-30, 183), Pair(0, 0), Pair(-88, 117), Pair(-49, 64), Pair(39, 3), Pair(61, -14), Pair(28, -37), Pair(-52, -28),
        Pair(-17, -12), Pair(19, 127), Pair(-13, 57), Pair(-277, 78), Pair(-58, -20), Pair(-26, -46), Pair(-20, -59), Pair(46, -128)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(43, 0), Pair(-23, 27), Pair(0, 0), Pair(-29, -2), Pair(-3, 19), Pair(63, 30), Pair(-13, 13), Pair(23, 17),
        Pair(-48, 18), Pair(-36, 0), Pair(25, 1), Pair(63, -14), Pair(37, -23), Pair(37, -11), Pair(-5, 7), Pair(-20, -7),
        Pair(21, -7), Pair(-10, -17), Pair(13, -4), Pair(0, -3), Pair(2, -5), Pair(-36, -5), Pair(-26, -2), Pair(-65, 13),
        Pair(2, -11), Pair(4, 1), Pair(-1, 10), Pair(30, -14), Pair(11, -18), Pair(23, -22), Pair(1, -17), Pair(-43, -4),
        Pair(37, -19), Pair(-5, -2), Pair(28, -52), Pair(-3, -24), Pair(3, -13), Pair(-6, -13), Pair(-12, -9), Pair(-46, -2),
        Pair(27, -11), Pair(33, -17), Pair(0, 0), Pair(-17, -40), Pair(3, -18), Pair(15, -19), Pair(17, -20), Pair(-40, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-77, -133), Pair(-8, -46), Pair(83, 74), Pair(192, 173), Pair(-52, -149), Pair(-76, -39), Pair(-67, 78), Pair(-101, -228),
        Pair(-57, -83), Pair(-109, -38), Pair(-112, 48), Pair(-90, -13), Pair(-44, 87), Pair(30, 16), Pair(38, 16), Pair(-92, -61),
        Pair(-131, -7), Pair(11, 12), Pair(-101, 95), Pair(89, -136), Pair(-39, 46), Pair(200, -24), Pair(-31, 3), Pair(-119, 84),
        Pair(-39, 38), Pair(31, -32), Pair(43, -37), Pair(-149, 91), Pair(-13, 21), Pair(37, 29), Pair(-108, 61), Pair(82, 62),
        Pair(-20, 58), Pair(112, -36), Pair(50, 102), Pair(-33, 59), Pair(94, -53), Pair(-75, 69), Pair(33, 19), Pair(-60, -24),
        Pair(-28, -80), Pair(-13, 138), Pair(111, -106), Pair(-51, 118), Pair(-29, 68), Pair(-35, -4), Pair(-103, 93), Pair(21, 11),
        Pair(-121, 63), Pair(-146, -4), Pair(0, 0), Pair(-40, 39), Pair(-169, 146), Pair(99, -25), Pair(-100, 45), Pair(-8, -119),
        Pair(-14, 1), Pair(1, -143), Pair(-49, 189), Pair(1, -64), Pair(35, 79), Pair(81, -69), Pair(63, -74), Pair(-12, 29)
      },
      { // Piece 2
        Pair(13, 106), Pair(-20, -30), Pair(-133, 27), Pair(-28, -155), Pair(-22, 166), Pair(-16, 122), Pair(-21, 3), Pair(-77, -35),
        Pair(-86, -38), Pair(-35, -14), Pair(-90, 74), Pair(-139, -30), Pair(1, 121), Pair(-22, 11), Pair(30, 115), Pair(177, 9),
        Pair(71, -26), Pair(101, 33), Pair(-38, 4), Pair(-197, 136), Pair(-62, 59), Pair(-84, 89), Pair(-71, 93), Pair(76, 88),
        Pair(-186, 109), Pair(-6, 7), Pair(168, -35), Pair(133, -12), Pair(74, 71), Pair(135, 28), Pair(-70, 144), Pair(204, -88),
        Pair(-25, 55), Pair(89, 31), Pair(-55, 12), Pair(100, 77), Pair(130, -58), Pair(-127, 200), Pair(-22, -7), Pair(-132, -76),
        Pair(-101, 166), Pair(-148, 78), Pair(-34, 124), Pair(175, -45), Pair(-37, 151), Pair(-20, 12), Pair(-75, 20), Pair(58, -38),
        Pair(-40, -6), Pair(27, 154), Pair(0, 0), Pair(-54, 165), Pair(-42, -16), Pair(-45, 89), Pair(103, -101), Pair(-71, -129),
        Pair(79, 97), Pair(-9, -32), Pair(46, 225), Pair(-119, 116), Pair(153, 0), Pair(-49, 7), Pair(36, 23), Pair(160, 70)
      },
      { // Piece 3
        Pair(-37, 43), Pair(-5, -13), Pair(184, 30), Pair(79, 3), Pair(34, 69), Pair(58, 51), Pair(102, 10), Pair(94, -11),
        Pair(118, -66), Pair(33, 31), Pair(69, 38), Pair(78, -3), Pair(66, 15), Pair(-45, 125), Pair(33, 0), Pair(137, -35),
        Pair(54, -76), Pair(139, -90), Pair(25, 69), Pair(7, 17), Pair(86, -34), Pair(320, -87), Pair(60, 18), Pair(-108, 79),
        Pair(159, -38), Pair(87, 5), Pair(36, 47), Pair(-5, 73), Pair(-90, 67), Pair(58, 24), Pair(-130, 16), Pair(-209, 94),
        Pair(-27, 74), Pair(218, -76), Pair(-94, 92), Pair(93, -50), Pair(80, -61), Pair(15, -23), Pair(131, -28), Pair(-146, 23),
        Pair(8, 38), Pair(72, 32), Pair(8, 16), Pair(45, 26), Pair(29, -20), Pair(-98, 67), Pair(-79, -6), Pair(-39, -56),
        Pair(-145, 55), Pair(-38, 91), Pair(0, 0), Pair(126, -8), Pair(75, 84), Pair(75, -13), Pair(-164, 27), Pair(12, -33),
        Pair(-37, 72), Pair(55, -2), Pair(39, 136), Pair(73, -27), Pair(-5, 80), Pair(68, 72), Pair(1, 119), Pair(-1, 99)
      },
      { // Piece 4
        Pair(27, -47), Pair(180, -11), Pair(-166, 147), Pair(4, -40), Pair(-47, -127), Pair(-7, -76), Pair(48, 79), Pair(-32, 149),
        Pair(-65, 64), Pair(-20, -33), Pair(-66, 42), Pair(-120, -44), Pair(-23, 30), Pair(-21, 90), Pair(-95, 145), Pair(-54, 20),
        Pair(-7, 24), Pair(10, 96), Pair(21, -30), Pair(0, -15), Pair(-56, 36), Pair(-67, 112), Pair(-18, 38), Pair(-7, 56),
        Pair(-18, 135), Pair(81, -144), Pair(20, 100), Pair(-189, 160), Pair(47, -18), Pair(-22, 65), Pair(89, -80), Pair(37, 25),
        Pair(-59, -150), Pair(-104, 40), Pair(96, -155), Pair(65, -86), Pair(-123, 102), Pair(-24, 46), Pair(19, -73), Pair(68, -207),
        Pair(-92, 24), Pair(33, -129), Pair(-3, 8), Pair(37, -34), Pair(104, -80), Pair(63, -143), Pair(-100, 65), Pair(-40, -20),
        Pair(29, -45), Pair(-44, 16), Pair(0, 0), Pair(76, -110), Pair(-98, 16), Pair(-25, 25), Pair(49, -191), Pair(-70, 66),
        Pair(-13, -12), Pair(74, -11), Pair(21, -98), Pair(-159, -113), Pair(-88, 50), Pair(61, -151), Pair(28, 19), Pair(-81, -106)
      },
      { // Piece 5
        Pair(-1, 66), Pair(-2, -46), Pair(-28, -166), Pair(-22, -54), Pair(-2, -153), Pair(-22, -173), Pair(27, -190), Pair(6, -35),
        Pair(-8, -13), Pair(-12, -61), Pair(-12, 21), Pair(2, 19), Pair(-35, -118), Pair(35, -57), Pair(-24, -39), Pair(-10, -34),
        Pair(-130, -162), Pair(43, 61), Pair(-106, -51), Pair(88, -23), Pair(-5, -44), Pair(59, -2), Pair(13, 21), Pair(34, -56),
        Pair(8, -92), Pair(22, -44), Pair(4, -29), Pair(78, 64), Pair(-26, 54), Pair(166, 6), Pair(42, -15), Pair(-76, 29),
        Pair(28, -22), Pair(35, 4), Pair(-43, 38), Pair(-45, 28), Pair(68, 16), Pair(185, -21), Pair(155, -46), Pair(-57, -4),
        Pair(-100, -39), Pair(13, 57), Pair(-106, 66), Pair(-54, 87), Pair(129, 19), Pair(18, 12), Pair(-108, 10), Pair(49, -45),
        Pair(116, -103), Pair(-37, 150), Pair(0, 0), Pair(-139, 131), Pair(8, 39), Pair(8, 25), Pair(14, -9), Pair(57, -70),
        Pair(-140, 82), Pair(34, -60), Pair(-241, 211), Pair(-7, -22), Pair(19, 20), Pair(-27, 21), Pair(-10, -40), Pair(11, -72)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(47, 3), Pair(-9, 2), Pair(29, 2), Pair(0, 0), Pair(-21, 34), Pair(2, 13), Pair(128, -7), Pair(69, -9),
        Pair(49, -28), Pair(-7, -11), Pair(-26, -1), Pair(19, -10), Pair(43, -5), Pair(21, 2), Pair(103, -21), Pair(49, -19),
        Pair(-3, -9), Pair(-34, -1), Pair(30, -16), Pair(-15, 0), Pair(40, -20), Pair(-4, 0), Pair(-39, -10), Pair(-4, 0),
        Pair(0, -11), Pair(-31, -1), Pair(-10, -5), Pair(3, 1), Pair(5, -17), Pair(0, -12), Pair(4, -16), Pair(-3, -11),
        Pair(-11, 1), Pair(-10, 0), Pair(10, 3), Pair(-11, 27), Pair(2, -14), Pair(12, -6), Pair(-20, -7), Pair(-1, -6),
        Pair(4, -11), Pair(-32, 6), Pair(22, 7), Pair(0, 0), Pair(-27, 1), Pair(-3, -3), Pair(-5, -13), Pair(-2, -15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-39, -22), Pair(-1, -59), Pair(-6, 49), Pair(-133, -95), Pair(131, 194), Pair(45, -39), Pair(-45, -108), Pair(22, 8),
        Pair(70, -73), Pair(42, 21), Pair(-17, 5), Pair(-20, 31), Pair(62, -53), Pair(133, -9), Pair(-40, 75), Pair(-5, -9),
        Pair(-19, 18), Pair(90, 11), Pair(13, 18), Pair(4, 43), Pair(17, -32), Pair(-47, -11), Pair(14, -23), Pair(-125, 98),
        Pair(-169, 83), Pair(-47, -82), Pair(46, -23), Pair(139, -24), Pair(-110, 101), Pair(169, -47), Pair(149, -124), Pair(71, -70),
        Pair(-19, -15), Pair(65, 51), Pair(-26, 49), Pair(88, 5), Pair(40, -13), Pair(164, -133), Pair(-102, 89), Pair(190, -99),
        Pair(-32, 34), Pair(122, -29), Pair(72, 97), Pair(-103, 77), Pair(-36, 112), Pair(12, 35), Pair(11, 53), Pair(-205, 13),
        Pair(-118, 20), Pair(-143, 163), Pair(-146, 18), Pair(0, 0), Pair(-57, 135), Pair(-65, 141), Pair(56, -96), Pair(-74, 46),
        Pair(-72, -108), Pair(32, -11), Pair(-81, 5), Pair(87, 154), Pair(123, -87), Pair(-121, 176), Pair(-96, -4), Pair(16, -45)
      },
      { // Piece 2
        Pair(22, 189), Pair(-113, 3), Pair(-108, 35), Pair(19, -13), Pair(85, 63), Pair(74, -145), Pair(55, 123), Pair(66, -92),
        Pair(-109, 61), Pair(120, 16), Pair(116, -23), Pair(-38, 45), Pair(-42, 13), Pair(-58, 104), Pair(110, 34), Pair(5, 107),
        Pair(-48, 12), Pair(-16, -3), Pair(-149, 122), Pair(59, -45), Pair(-86, 39), Pair(178, -105), Pair(-29, 57), Pair(-39, 34),
        Pair(-36, 36), Pair(-76, 39), Pair(155, 22), Pair(-20, 22), Pair(-30, 4), Pair(-115, 70), Pair(70, -30), Pair(-183, 183),
        Pair(-40, 101), Pair(-114, 59), Pair(109, 25), Pair(131, -5), Pair(77, 5), Pair(145, -38), Pair(-51, 188), Pair(-73, 97),
        Pair(-73, -1), Pair(-77, 160), Pair(5, 1), Pair(-37, 91), Pair(5, 15), Pair(14, 133), Pair(-149, 41), Pair(-16, 62),
        Pair(-3, -23), Pair(-40, 24), Pair(14, 129), Pair(0, 0), Pair(-15, 134), Pair(-36, -1), Pair(52, 0), Pair(-26, -10),
        Pair(-85, -104), Pair(3, 48), Pair(79, 66), Pair(98, 172), Pair(-6, -7), Pair(67, 0), Pair(-71, -7), Pair(-125, 93)
      },
      { // Piece 3
        Pair(181, -64), Pair(62, -47), Pair(94, 22), Pair(122, 9), Pair(7, -21), Pair(117, 0), Pair(71, -13), Pair(156, -43),
        Pair(-82, 31), Pair(12, 45), Pair(67, -3), Pair(6, 23), Pair(-39, -2), Pair(128, -58), Pair(138, -57), Pair(42, 6),
        Pair(-20, 3), Pair(16, -40), Pair(112, 4), Pair(-49, 58), Pair(-108, 52), Pair(174, -20), Pair(17, 13), Pair(370, -143),
        Pair(-27, 53), Pair(45, 2), Pair(-93, -6), Pair(21, 23), Pair(-8, 17), Pair(-18, -16), Pair(125, -56), Pair(23, -23),
        Pair(-155, 18), Pair(194, -126), Pair(26, -34), Pair(-27, 47), Pair(50, -51), Pair(94, -100), Pair(-75, 13), Pair(56, 18),
        Pair(-139, 63), Pair(-171, 68), Pair(-28, -52), Pair(-96, 53), Pair(90, -60), Pair(81, -4), Pair(-106, 50), Pair(50, 1),
        Pair(141, -51), Pair(-78, 55), Pair(102, -79), Pair(0, 0), Pair(-79, -3), Pair(142, -97), Pair(43, 19), Pair(28, -45),
        Pair(18, 36), Pair(-45, 77), Pair(54, 55), Pair(17, 119), Pair(-25, 47), Pair(-36, 68), Pair(46, 12), Pair(22, 37)
      },
      { // Piece 4
        Pair(150, -60), Pair(-55, -42), Pair(2, 28), Pair(-23, 36), Pair(60, 73), Pair(81, -48), Pair(-17, -103), Pair(62, 15),
        Pair(45, 48), Pair(-71, 43), Pair(-43, 4), Pair(-31, 103), Pair(-149, 56), Pair(-24, 23), Pair(53, -32), Pair(105, -46),
        Pair(1, 4), Pair(-10, 41), Pair(6, -11), Pair(106, -92), Pair(20, 185), Pair(52, 26), Pair(236, -185), Pair(-5, -44),
        Pair(-44, -34), Pair(1, -148), Pair(-45, -41), Pair(107, -15), Pair(98, -41), Pair(116, -96), Pair(113, -120), Pair(-91, 156),
        Pair(-20, -82), Pair(-31, 38), Pair(7, -182), Pair(11, 68), Pair(-5, -139), Pair(81, -68), Pair(-36, -57), Pair(121, -101),
        Pair(-112, -110), Pair(25, -29), Pair(58, 83), Pair(63, 59), Pair(-29, 66), Pair(-46, 41), Pair(44, -149), Pair(-9, -112),
        Pair(-10, -156), Pair(-64, -88), Pair(-63, 21), Pair(0, 0), Pair(15, -105), Pair(-29, 22), Pair(-104, -18), Pair(-38, 27),
        Pair(-193, 66), Pair(2, 104), Pair(-95, 18), Pair(13, -123), Pair(-110, -114), Pair(-47, -120), Pair(17, -43), Pair(-20, 6)
      },
      { // Piece 5
        Pair(-18, -75), Pair(-5, -67), Pair(13, 61), Pair(-2, -21), Pair(-1, -3), Pair(-54, -151), Pair(-10, -52), Pair(-4, 17),
        Pair(-5, -10), Pair(-58, -96), Pair(-21, -248), Pair(1, 5), Pair(14, -29), Pair(-18, -53), Pair(-42, -16), Pair(-14, -130),
        Pair(15, -23), Pair(-1, -2), Pair(42, -78), Pair(-3, -71), Pair(85, -31), Pair(64, -7), Pair(76, -44), Pair(17, -58),
        Pair(-13, -84), Pair(18, -7), Pair(106, -81), Pair(-135, 47), Pair(-65, 44), Pair(60, 4), Pair(68, 24), Pair(105, -17),
        Pair(-90, -74), Pair(56, 87), Pair(-1, -12), Pair(130, -36), Pair(-151, 54), Pair(-37, 28), Pair(39, -16), Pair(21, -21),
        Pair(0, 17), Pair(92, -51), Pair(-19, 57), Pair(-146, 115), Pair(-28, 62), Pair(77, 20), Pair(-29, 40), Pair(3, -7),
        Pair(93, -14), Pair(-129, -53), Pair(-20, 109), Pair(0, 0), Pair(-93, 113), Pair(8, 29), Pair(7, 4), Pair(60, -47),
        Pair(-86, -31), Pair(0, -36), Pair(-70, -120), Pair(-174, 191), Pair(78, 15), Pair(42, 14), Pair(1, -15), Pair(-30, -7)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-28, 9), Pair(-58, 25), Pair(3, -19), Pair(21, -34), Pair(0, 0), Pair(6, -38), Pair(38, -24), Pair(-39, 1),
        Pair(40, -14), Pair(-28, -10), Pair(12, -6), Pair(46, -23), Pair(124, -43), Pair(59, -4), Pair(60, -11), Pair(-74, 5),
        Pair(-19, -8), Pair(2, -12), Pair(24, -23), Pair(-8, -3), Pair(28, -13), Pair(-46, 5), Pair(-43, 4), Pair(-38, -5),
        Pair(-18, -11), Pair(-12, -23), Pair(9, -32), Pair(4, -3), Pair(-49, 15), Pair(-6, -3), Pair(18, -14), Pair(-2, -5),
        Pair(-42, 9), Pair(-13, -13), Pair(-23, -11), Pair(47, -40), Pair(25, -8), Pair(-2, -5), Pair(-22, 0), Pair(-8, -11),
        Pair(4, -16), Pair(-15, -11), Pair(42, -25), Pair(-19, -56), Pair(0, 0), Pair(7, -24), Pair(-19, 12), Pair(-7, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-82, -218), Pair(28, -97), Pair(-8, 8), Pair(160, -28), Pair(35, 62), Pair(-43, -85), Pair(-23, -141), Pair(7, 90),
        Pair(85, 3), Pair(8, 37), Pair(2, 31), Pair(-79, 19), Pair(-188, 33), Pair(-112, 77), Pair(49, -38), Pair(-2, -80),
        Pair(-171, 15), Pair(-26, -92), Pair(25, 4), Pair(-91, -54), Pair(114, -74), Pair(84, -9), Pair(156, -64), Pair(56, -98),
        Pair(-7, -108), Pair(2, -96), Pair(-41, -16), Pair(-136, 35), Pair(53, 23), Pair(55, -20), Pair(68, 48), Pair(-64, 12),
        Pair(-44, -58), Pair(-66, 66), Pair(-28, 42), Pair(65, 21), Pair(-39, -24), Pair(67, 0), Pair(44, -58), Pair(-3, 118),
        Pair(-10, 49), Pair(51, -72), Pair(-12, 74), Pair(-111, 135), Pair(-31, 127), Pair(55, 63), Pair(-62, -24), Pair(86, -169),
        Pair(-96, -54), Pair(4, -15), Pair(-164, 163), Pair(-18, -3), Pair(0, 0), Pair(-28, -37), Pair(-78, 97), Pair(-1, 14),
        Pair(-20, -138), Pair(-94, 152), Pair(194, -123), Pair(-48, -124), Pair(-85, 170), Pair(59, -37), Pair(-25, -29), Pair(17, 53)
      },
      { // Piece 2
        Pair(143, -54), Pair(2, 74), Pair(-4, 17), Pair(-115, 19), Pair(-56, -61), Pair(-37, 72), Pair(2, -21), Pair(25, 1),
        Pair(-127, 130), Pair(128, -57), Pair(-41, 26), Pair(88, 3), Pair(-65, 109), Pair(10, 13), Pair(-92, 20), Pair(-34, -74),
        Pair(97, -25), Pair(-52, 33), Pair(-42, 20), Pair(-69, 67), Pair(-65, 46), Pair(-150, 82), Pair(-120, -30), Pair(24, 49),
        Pair(-141, 193), Pair(-38, 117), Pair(46, 92), Pair(168, -37), Pair(-37, 27), Pair(-225, 91), Pair(-80, 51), Pair(-103, 2),
        Pair(-184, -68), Pair(-153, 131), Pair(-117, 60), Pair(157, 54), Pair(76, 51), Pair(139, -36), Pair(50, 45), Pair(-74, 87),
        Pair(141, -109), Pair(59, -45), Pair(-68, 150), Pair(36, 47), Pair(110, 83), Pair(-3, -25), Pair(147, 15), Pair(42, -113),
        Pair(243, -79), Pair(28, -13), Pair(-33, -22), Pair(72, 113), Pair(0, 0), Pair(-97, 145), Pair(45, -81), Pair(-107, 48),
        Pair(-60, -95), Pair(158, -72), Pair(56, 71), Pair(37, 34), Pair(-5, 221), Pair(-61, -111), Pair(-2, 133), Pair(-5, 52)
      },
      { // Piece 3
        Pair(-120, 12), Pair(-55, -13), Pair(148, -20), Pair(22, -12), Pair(64, -19), Pair(-52, -62), Pair(2, -32), Pair(1, -13),
        Pair(103, -35), Pair(-20, -34), Pair(-146, 30), Pair(-258, 75), Pair(23, 62), Pair(-12, 7), Pair(-71, 7), Pair(-113, 54),
        Pair(57, -49), Pair(-34, -32), Pair(-58, 71), Pair(-12, -45), Pair(32, -1), Pair(207, -107), Pair(104, -46), Pair(-157, 17),
        Pair(250, -61), Pair(23, -35), Pair(30, -24), Pair(-38, 13), Pair(82, -17), Pair(46, -62), Pair(-19, 3), Pair(-18, -10),
        Pair(64, -44), Pair(-98, 16), Pair(-94, -46), Pair(-21, -51), Pair(51, 1), Pair(-66, 18), Pair(184, -86), Pair(-102, 46),
        Pair(-119, 100), Pair(-155, -45), Pair(126, -132), Pair(68, -39), Pair(9, 36), Pair(15, 29), Pair(8, -25), Pair(172, 6),
        Pair(42, 36), Pair(78, -127), Pair(52, 41), Pair(74, -24), Pair(0, 0), Pair(-17, 124), Pair(18, 40), Pair(-9, -120),
        Pair(-50, 56), Pair(2, 8), Pair(-99, 73), Pair(-26, -18), Pair(25, 85), Pair(-17, -13), Pair(2, 39), Pair(-51, 11)
      },
      { // Piece 4
        Pair(6, 50), Pair(-17, -20), Pair(-23, 52), Pair(-48, 55), Pair(-47, -13), Pair(50, -36), Pair(-38, -105), Pair(101, -62),
        Pair(-109, 127), Pair(13, 10), Pair(77, -41), Pair(-98, 64), Pair(64, 59), Pair(106, 196), Pair(-27, 16), Pair(-15, 63),
        Pair(84, -22), Pair(127, 142), Pair(-50, -52), Pair(-22, -13), Pair(-79, -9), Pair(162, 71), Pair(7, -126), Pair(105, -13),
        Pair(-48, 59), Pair(-101, 115), Pair(-10, -58), Pair(169, -13), Pair(110, -58), Pair(75, 48), Pair(125, -136), Pair(115, 53),
        Pair(23, 187), Pair(52, 15), Pair(-40, 19), Pair(-118, -71), Pair(-88, 8), Pair(12, -38), Pair(46, -43), Pair(-24, 34),
        Pair(-250, -141), Pair(51, -111), Pair(26, -32), Pair(45, -235), Pair(163, 19), Pair(-170, 13), Pair(57, 67), Pair(-118, -23),
        Pair(-12, -51), Pair(-167, 30), Pair(28, -81), Pair(-115, 89), Pair(0, 0), Pair(-52, -37), Pair(-108, -10), Pair(-54, -113),
        Pair(20, -126), Pair(-135, -52), Pair(57, -146), Pair(7, -26), Pair(13, -92), Pair(2, 42), Pair(-163, -74), Pair(-76, -24)
      },
      { // Piece 5
        Pair(-45, -44), Pair(-15, -167), Pair(2, -49), Pair(-66, -193), Pair(34, 24), Pair(-22, -107), Pair(-11, -1), Pair(23, 34),
        Pair(16, -41), Pair(26, 67), Pair(-41, -43), Pair(14, -81), Pair(29, -13), Pair(28, 31), Pair(-77, -6), Pair(-8, -4),
        Pair(60, -60), Pair(-35, -43), Pair(-8, -9), Pair(-8, 3), Pair(26, 24), Pair(82, -10), Pair(73, 29), Pair(-56, 46),
        Pair(-42, -63), Pair(11, -26), Pair(-60, 50), Pair(-13, -17), Pair(-78, -10), Pair(16, 2), Pair(47, -25), Pair(-81, -15),
        Pair(78, -211), Pair(75, -9), Pair(-49, 2), Pair(-85, 8), Pair(-65, 47), Pair(-96, 65), Pair(-25, -1), Pair(-66, 68),
        Pair(0, 13), Pair(19, -29), Pair(-77, 50), Pair(-48, 96), Pair(65, 83), Pair(-33, 83), Pair(61, 24), Pair(110, -75),
        Pair(36, -30), Pair(-25, 26), Pair(79, -43), Pair(-171, 123), Pair(0, 0), Pair(-41, 93), Pair(-4, 39), Pair(56, 1),
        Pair(162, -51), Pair(71, -41), Pair(-82, 70), Pair(-10, -31), Pair(-65, 134), Pair(14, -30), Pair(65, -4), Pair(84, -41)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(23, -16), Pair(34, -23), Pair(-63, -30), Pair(-2, -13), Pair(-6, 38), Pair(0, 0), Pair(-106, 74), Pair(-112, 17),
        Pair(37, -28), Pair(-47, 10), Pair(-53, 20), Pair(67, -27), Pair(44, -18), Pair(-7, -33), Pair(-78, 40), Pair(74, -12),
        Pair(-37, 3), Pair(-20, -8), Pair(-60, 2), Pair(21, -27), Pair(42, -21), Pair(26, -49), Pair(-43, -9), Pair(43, -9),
        Pair(-23, -4), Pair(-34, -11), Pair(5, -19), Pair(-20, 6), Pair(-10, -15), Pair(28, -10), Pair(-42, -6), Pair(-3, -13),
        Pair(-13, -14), Pair(-24, -10), Pair(-10, 0), Pair(27, -22), Pair(23, -21), Pair(40, 11), Pair(2, -9), Pair(16, -12),
        Pair(-43, -12), Pair(-15, -31), Pair(-19, -16), Pair(-44, -10), Pair(-3, 8), Pair(0, 0), Pair(26, -23), Pair(35, -11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-116, -11), Pair(-131, -295), Pair(-51, 24), Pair(102, 107), Pair(0, 66), Pair(14, 2), Pair(-14, -87), Pair(20, 66),
        Pair(-50, -116), Pair(-146, -94), Pair(149, 40), Pair(-12, -106), Pair(-21, -10), Pair(5, -29), Pair(-45, -170), Pair(-99, -121),
        Pair(109, -98), Pair(-186, -36), Pair(-29, 81), Pair(22, 18), Pair(48, 11), Pair(-27, -95), Pair(87, -46), Pair(-14, 66),
        Pair(93, -61), Pair(15, -66), Pair(31, -104), Pair(115, -47), Pair(19, -4), Pair(43, 21), Pair(57, -89), Pair(-86, -45),
        Pair(-50, -127), Pair(-173, 70), Pair(-199, 129), Pair(145, -37), Pair(152, -16), Pair(122, -34), Pair(66, -153), Pair(-67, -181),
        Pair(42, -241), Pair(131, -20), Pair(-14, 72), Pair(-1, -11), Pair(-13, 60), Pair(58, -99), Pair(29, 40), Pair(123, -26),
        Pair(-14, -100), Pair(-96, -213), Pair(-98, -62), Pair(-138, 123), Pair(64, -77), Pair(0, 0), Pair(-35, 37), Pair(26, 120),
        Pair(38, 94), Pair(-98, -101), Pair(-33, -55), Pair(-112, -44), Pair(-39, -4), Pair(-28, 150), Pair(54, 45), Pair(91, 76)
      },
      { // Piece 2
        Pair(-51, -34), Pair(-21, -95), Pair(11, 80), Pair(-158, 28), Pair(-45, 127), Pair(-125, -246), Pair(29, 167), Pair(-29, -111),
        Pair(5, 104), Pair(194, 56), Pair(-85, -33), Pair(-18, 104), Pair(26, -79), Pair(-72, 89), Pair(67, -26), Pair(11, -99),
        Pair(-113, 139), Pair(141, -133), Pair(-134, 99), Pair(109, -84), Pair(-185, 101), Pair(13, -43), Pair(76, 78), Pair(7, -44),
        Pair(-3, -61), Pair(-107, 138), Pair(-134, 153), Pair(54, -8), Pair(111, -70), Pair(159, 28), Pair(116, 17), Pair(-112, 36),
        Pair(21, 98), Pair(20, 34), Pair(-4, 123), Pair(20, -24), Pair(136, -24), Pair(-21, -73), Pair(87, 29), Pair(105, 95),
        Pair(-5, -50), Pair(-58, -25), Pair(49, -28), Pair(24, 124), Pair(92, -2), Pair(178, 4), Pair(-96, -21), Pair(-189, 107),
        Pair(-256, -235), Pair(96, -53), Pair(-101, 14), Pair(-75, -2), Pair(-128, 171), Pair(0, 0), Pair(-64, 82), Pair(-65, -81),
        Pair(6, 104), Pair(-78, -133), Pair(9, -132), Pair(31, -2), Pair(-10, -133), Pair(-104, 189), Pair(-23, -64), Pair(32, -25)
      },
      { // Piece 3
        Pair(31, 30), Pair(-24, 114), Pair(-41, -64), Pair(30, 6), Pair(144, -18), Pair(134, -36), Pair(-38, -26), Pair(141, 71),
        Pair(-14, 24), Pair(-22, -13), Pair(-32, -47), Pair(-98, -78), Pair(16, 48), Pair(115, -26), Pair(-77, 16), Pair(72, -57),
        Pair(-6, 20), Pair(-44, -36), Pair(22, -44), Pair(193, -55), Pair(-49, 27), Pair(-5, 28), Pair(59, -63), Pair(56, 0),
        Pair(65, -17), Pair(11, -11), Pair(97, -69), Pair(8, -31), Pair(0, 26), Pair(4, 31), Pair(78, -33), Pair(188, -104),
        Pair(43, -2), Pair(-10, 45), Pair(18, 65), Pair(-78, 62), Pair(100, 4), Pair(77, 19), Pair(-30, -14), Pair(-45, -57),
        Pair(72, 10), Pair(-155, -13), Pair(58, -69), Pair(88, -115), Pair(53, -19), Pair(54, -15), Pair(-88, 41), Pair(-63, -37),
        Pair(183, -43), Pair(-102, -27), Pair(23, 86), Pair(15, -16), Pair(68, 34), Pair(0, 0), Pair(156, -96), Pair(-157, 64),
        Pair(-37, 81), Pair(-56, -15), Pair(-43, 56), Pair(-57, 61), Pair(14, 21), Pair(3, 94), Pair(-171, 135), Pair(-38, 65)
      },
      { // Piece 4
        Pair(-49, -99), Pair(30, 17), Pair(-171, -128), Pair(-67, 36), Pair(116, -116), Pair(-6, -32), Pair(-77, -231), Pair(61, 74),
        Pair(-38, 133), Pair(-94, 14), Pair(34, 46), Pair(-40, 121), Pair(21, -47), Pair(120, 3), Pair(44, 61), Pair(3, -98),
        Pair(84, -58), Pair(64, 83), Pair(20, -113), Pair(-10, -84), Pair(-61, 66), Pair(-66, 59), Pair(-62, 29), Pair(21, -155),
        Pair(-5, 77), Pair(74, -104), Pair(-66, -16), Pair(48, 15), Pair(-10, 72), Pair(-39, -93), Pair(-67, 26), Pair(-87, -201),
        Pair(-20, -144), Pair(-12, 53), Pair(23, 11), Pair(59, 21), Pair(-76, 154), Pair(77, -44), Pair(-70, -1), Pair(-49, 112),
        Pair(27, 45), Pair(-3, -92), Pair(99, 49), Pair(-58, -67), Pair(-58, -108), Pair(-137, 10), Pair(138, 35), Pair(-71, 26),
        Pair(25, -18), Pair(4, 62), Pair(10, -102), Pair(-11, 161), Pair(-26, 53), Pair(0, 0), Pair(-48, 12), Pair(-45, -17),
        Pair(40, -33), Pair(-34, -19), Pair(-79, -30), Pair(91, -130), Pair(-54, -82), Pair(-59, -49), Pair(-9, -48), Pair(-6, -23)
      },
      { // Piece 5
        Pair(6, -11), Pair(-15, -152), Pair(11, -216), Pair(-33, -99), Pair(-15, -27), Pair(-16, -41), Pair(-12, -76), Pair(32, 112),
        Pair(-2, -74), Pair(-57, -62), Pair(61, -143), Pair(20, -52), Pair(-45, -142), Pair(13, -58), Pair(-21, -48), Pair(14, -111),
        Pair(-12, -37), Pair(55, 11), Pair(165, -16), Pair(117, -98), Pair(10, -63), Pair(-113, 25), Pair(21, 71), Pair(14, -23),
        Pair(20, 8), Pair(-97, -42), Pair(-15, 13), Pair(114, -57), Pair(-8, 36), Pair(-21, -37), Pair(-70, -16), Pair(-18, 13),
        Pair(-72, -62), Pair(-76, -43), Pair(2, -13), Pair(27, 14), Pair(206, -2), Pair(73, 58), Pair(227, 0), Pair(138, -55),
        Pair(-58, -83), Pair(-145, 5), Pair(28, -40), Pair(77, 40), Pair(-34, 64), Pair(-31, 62), Pair(-65, 109), Pair(-119, 39),
        Pair(-165, 61), Pair(44, -61), Pair(119, -15), Pair(-45, -6), Pair(53, 89), Pair(0, 0), Pair(-100, 135), Pair(-32, 31),
        Pair(-33, -34), Pair(51, -53), Pair(-73, 16), Pair(143, -9), Pair(81, 113), Pair(-115, 158), Pair(85, 21), Pair(-116, 94)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(43, -6), Pair(110, 3), Pair(13, -13), Pair(-128, 7), Pair(-38, 24), Pair(106, -74), Pair(0, 0), Pair(76, -37),
        Pair(-87, 13), Pair(-57, 8), Pair(50, -36), Pair(-41, -5), Pair(59, 1), Pair(-60, 3), Pair(-58, 13), Pair(-62, -3),
        Pair(4, -10), Pair(-30, -11), Pair(-4, -22), Pair(0, -24), Pair(-2, -10), Pair(8, -4), Pair(73, -38), Pair(68, -7),
        Pair(28, -15), Pair(35, -21), Pair(-3, -19), Pair(-1, -14), Pair(21, -18), Pair(9, -23), Pair(-58, 28), Pair(46, -9),
        Pair(1, -1), Pair(-20, -11), Pair(10, -11), Pair(30, -37), Pair(28, -25), Pair(53, -12), Pair(-4, -2), Pair(21, 3),
        Pair(21, -1), Pair(-12, -8), Pair(39, -31), Pair(-11, 43), Pair(31, -9), Pair(42, -16), Pair(0, 0), Pair(17, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(108, 106), Pair(-163, -167), Pair(59, -76), Pair(40, -33), Pair(110, 60), Pair(124, -51), Pair(-10, -40), Pair(-10, 18),
        Pair(-80, -79), Pair(-157, -77), Pair(350, -203), Pair(-156, -9), Pair(-99, 4), Pair(-102, -26), Pair(-57, 107), Pair(-42, -34),
        Pair(55, -76), Pair(129, -99), Pair(-7, 20), Pair(142, -61), Pair(90, -63), Pair(68, -113), Pair(59, 108), Pair(88, -151),
        Pair(79, -36), Pair(-77, -57), Pair(-121, 53), Pair(45, -75), Pair(73, 32), Pair(-20, 63), Pair(46, 32), Pair(130, -9),
        Pair(-26, -146), Pair(57, -140), Pair(-30, 18), Pair(-99, 48), Pair(18, -93), Pair(-89, -12), Pair(-190, 111), Pair(8, 200),
        Pair(55, 9), Pair(-30, -4), Pair(107, -4), Pair(0, 56), Pair(116, 55), Pair(-28, 103), Pair(-60, 155), Pair(-115, 110),
        Pair(-115, -98), Pair(149, 59), Pair(58, 1), Pair(-59, 32), Pair(-69, 115), Pair(244, -158), Pair(0, 0), Pair(81, -16),
        Pair(0, 0), Pair(93, -123), Pair(-109, -33), Pair(-106, -21), Pair(-111, 28), Pair(87, 11), Pair(29, 117), Pair(-23, -39)
      },
      { // Piece 2
        Pair(13, 45), Pair(-103, 47), Pair(-44, -150), Pair(-37, 110), Pair(-28, 28), Pair(-108, 86), Pair(-55, -50), Pair(64, -1),
        Pair(-134, 100), Pair(15, 149), Pair(-124, 68), Pair(-30, -60), Pair(-31, 67), Pair(-28, -92), Pair(49, 58), Pair(80, -91),
        Pair(-72, 14), Pair(-144, 147), Pair(-85, 184), Pair(-67, 91), Pair(80, -18), Pair(48, 26), Pair(10, -19), Pair(-134, 35),
        Pair(-184, 106), Pair(101, -43), Pair(-44, 139), Pair(87, -28), Pair(28, -10), Pair(41, -86), Pair(-56, 23), Pair(191, -3),
        Pair(-18, 112), Pair(-165, 44), Pair(-98, 5), Pair(-54, 144), Pair(-24, 17), Pair(-119, 32), Pair(215, 23), Pair(87, 122),
        Pair(-208, 105), Pair(36, -42), Pair(-30, 63), Pair(40, -30), Pair(12, 101), Pair(-133, -14), Pair(-23, 66), Pair(16, 15),
        Pair(-1, 45), Pair(-28, 78), Pair(-95, -13), Pair(-58, -19), Pair(14, -35), Pair(190, 152), Pair(0, 0), Pair(-125, 176),
        Pair(106, 24), Pair(87, 18), Pair(-79, -3), Pair(-100, -175), Pair(-173, 36), Pair(-54, 13), Pair(-14, 228), Pair(0, 0)
      },
      { // Piece 3
        Pair(-238, 99), Pair(-69, -14), Pair(15, -54), Pair(-74, 42), Pair(233, -79), Pair(8, -4), Pair(73, 13), Pair(166, -30),
        Pair(-18, 40), Pair(-96, 47), Pair(106, -28), Pair(102, -19), Pair(-17, -41), Pair(107, -81), Pair(104, -22), Pair(-116, 26),
        Pair(-66, -8), Pair(81, -22), Pair(-221, 20), Pair(28, 3), Pair(-37, -51), Pair(-1, -39), Pair(7, 0), Pair(24, -21),
        Pair(49, -45), Pair(22, -119), Pair(-133, -51), Pair(-29, 55), Pair(78, -81), Pair(-52, 9), Pair(82, -28), Pair(34, -22),
        Pair(-121, -109), Pair(97, 3), Pair(162, -44), Pair(-13, -138), Pair(-16, -16), Pair(139, -120), Pair(43, -32), Pair(108, 48),
        Pair(-14, -41), Pair(169, -108), Pair(131, 16), Pair(87, -48), Pair(48, 42), Pair(131, -102), Pair(243, -54), Pair(-144, -45),
        Pair(-54, -28), Pair(-115, 46), Pair(-7, 1), Pair(-77, -21), Pair(-55, 42), Pair(100, -55), Pair(0, 0), Pair(-5, -84),
        Pair(-50, 27), Pair(54, 52), Pair(17, 5), Pair(-56, 99), Pair(59, -4), Pair(-23, 41), Pair(33, 89), Pair(-166, 56)
      },
      { // Piece 4
        Pair(52, 167), Pair(-64, -1), Pair(-117, -26), Pair(-34, 28), Pair(-95, -122), Pair(-31, -47), Pair(-116, -151), Pair(30, -49),
        Pair(44, -6), Pair(-110, -72), Pair(-159, -14), Pair(-30, 21), Pair(120, 122), Pair(3, 38), Pair(128, 127), Pair(-66, -1),
        Pair(-93, -195), Pair(107, -7), Pair(-115, -52), Pair(46, 60), Pair(55, 38), Pair(-74, -29), Pair(-58, -14), Pair(151, -41),
        Pair(14, 18), Pair(-28, -125), Pair(13, -45), Pair(73, 28), Pair(-70, 22), Pair(161, 32), Pair(-123, 128), Pair(55, 19),
        Pair(-38, -181), Pair(-156, -177), Pair(-108, -68), Pair(47, 11), Pair(-51, 46), Pair(-106, -60), Pair(89, -90), Pair(37, -9),
        Pair(-106, -114), Pair(10, -119), Pair(-60, 98), Pair(-19, 14), Pair(78, -114), Pair(30, -112), Pair(69, 78), Pair(-110, -97),
        Pair(-7, 12), Pair(-38, -84), Pair(-7, -9), Pair(-63, 17), Pair(-102, 125), Pair(38, 161), Pair(0, 0), Pair(-95, -34),
        Pair(-49, 1), Pair(101, 24), Pair(-5, -118), Pair(7, -140), Pair(-16, -65), Pair(-134, -68), Pair(120, -90), Pair(0, 0)
      },
      { // Piece 5
        Pair(2, -179), Pair(-20, -98), Pair(-19, -76), Pair(-17, -199), Pair(-14, 46), Pair(12, 36), Pair(-9, -89), Pair(-18, -17),
        Pair(-32, -189), Pair(-51, -7), Pair(76, -53), Pair(-10, -117), Pair(-40, -57), Pair(19, -5), Pair(-43, -162), Pair(7, 2),
        Pair(-45, -112), Pair(-16, -64), Pair(42, 17), Pair(-60, -17), Pair(130, -71), Pair(82, 18), Pair(-38, 16), Pair(-40, -105),
        Pair(28, -105), Pair(-11, -31), Pair(22, -38), Pair(-9, 6), Pair(-24, -25), Pair(85, 85), Pair(93, -69), Pair(12, 46),
        Pair(-46, 35), Pair(-50, -107), Pair(71, -34), Pair(-43, 40), Pair(117, -42), Pair(67, 3), Pair(69, 5), Pair(19, 43),
        Pair(41, -47), Pair(-64, -84), Pair(80, 4), Pair(-209, 78), Pair(-102, 92), Pair(23, 100), Pair(-100, 24), Pair(44, 48),
        Pair(-12, -76), Pair(-56, 38), Pair(26, -2), Pair(-62, 44), Pair(-5, 48), Pair(19, 147), Pair(0, 0), Pair(84, 130),
        Pair(-69, -77), Pair(-146, -55), Pair(56, -41), Pair(102, 21), Pair(-94, 83), Pair(-23, 40), Pair(39, 179), Pair(174, 21)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-35, 9), Pair(-3, 8), Pair(-23, -17), Pair(-69, 9), Pair(39, -1), Pair(112, -17), Pair(-76, 37), Pair(0, 0),
        Pair(-36, 12), Pair(63, -10), Pair(-1, 7), Pair(-67, -6), Pair(5, -7), Pair(41, -23), Pair(-47, 8), Pair(96, 34),
        Pair(45, -15), Pair(5, -2), Pair(39, -13), Pair(-9, 0), Pair(-31, -7), Pair(-18, -1), Pair(4, -24), Pair(-92, 34),
        Pair(19, -22), Pair(-18, -11), Pair(-18, -8), Pair(-9, -11), Pair(-7, -9), Pair(-4, -4), Pair(25, -19), Pair(-16, -78),
        Pair(20, -14), Pair(2, -20), Pair(18, -25), Pair(-21, -23), Pair(-7, -14), Pair(-1, -12), Pair(25, -24), Pair(-70, -43),
        Pair(15, -13), Pair(-19, -17), Pair(-30, -1), Pair(-12, -40), Pair(5, 13), Pair(24, -11), Pair(21, -17), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-82, -84), Pair(0, -188), Pair(-8, -169), Pair(-113, -44), Pair(63, 76), Pair(-26, -116), Pair(0, -79), Pair(-18, -96),
        Pair(-2, 20), Pair(-57, -90), Pair(78, -105), Pair(-5, -28), Pair(82, 45), Pair(-72, -62), Pair(237, 51), Pair(-40, -48),
        Pair(-87, -39), Pair(107, -90), Pair(-139, -71), Pair(-90, -64), Pair(-198, -17), Pair(-69, -28), Pair(-25, -47), Pair(-55, -138),
        Pair(5, -67), Pair(34, -155), Pair(-26, -103), Pair(42, -19), Pair(76, -19), Pair(107, -57), Pair(327, -197), Pair(53, -136),
        Pair(-230, -163), Pair(7, -49), Pair(-13, 48), Pair(19, -64), Pair(150, -102), Pair(10, -22), Pair(9, -133), Pair(247, -14),
        Pair(-27, -14), Pair(184, -215), Pair(92, -18), Pair(-145, -3), Pair(72, -75), Pair(-99, 90), Pair(-2, 37), Pair(27, -22),
        Pair(-61, -48), Pair(-81, -47), Pair(-26, -139), Pair(15, -139), Pair(7, -36), Pair(-54, 62), Pair(30, -104), Pair(0, 0),
        Pair(-7, -39), Pair(-59, -30), Pair(-210, -64), Pair(130, -160), Pair(-64, -100), Pair(-121, -50), Pair(-49, -130), Pair(-149, 123)
      },
      { // Piece 2
        Pair(-77, 117), Pair(-57, -77), Pair(24, -8), Pair(123, 7), Pair(30, 97), Pair(65, 26), Pair(5, 97), Pair(-132, -214),
        Pair(115, -87), Pair(-54, 125), Pair(-100, -64), Pair(-65, 64), Pair(-44, 32), Pair(-124, 11), Pair(-33, 92), Pair(17, 48),
        Pair(34, 116), Pair(143, -50), Pair(-49, 135), Pair(28, 37), Pair(-35, 113), Pair(41, -47), Pair(64, 35), Pair(-33, 64),
        Pair(110, -135), Pair(-19, 33), Pair(-1, -22), Pair(146, 65), Pair(78, 19), Pair(-125, 79), Pair(-26, 0), Pair(51, -21),
        Pair(-76, -82), Pair(-51, 21), Pair(25, -12), Pair(25, -31), Pair(5, 106), Pair(-26, 39), Pair(39, -56), Pair(156, 48),
        Pair(-21, -136), Pair(20, -14), Pair(136, -37), Pair(27, 32), Pair(12, -90), Pair(-38, 140), Pair(-151, 50), Pair(75, 46),
        Pair(112, 70), Pair(-58, 61), Pair(13, -68), Pair(-77, -4), Pair(44, -15), Pair(188, -190), Pair(10, 137), Pair(0, 0),
        Pair(-89, -16), Pair(102, 25), Pair(-54, 5), Pair(-32, 27), Pair(52, -139), Pair(-111, 89), Pair(-15, -104), Pair(37, 201)
      },
      { // Piece 3
        Pair(198, -40), Pair(-15, -83), Pair(-29, 9), Pair(72, 3), Pair(-44, 23), Pair(-13, 19), Pair(88, -105), Pair(121, -25),
        Pair(111, -63), Pair(-113, -24), Pair(126, -92), Pair(8, -48), Pair(-74, 22), Pair(-158, 40), Pair(43, -1), Pair(-16, 14),
        Pair(110, -50), Pair(37, -18), Pair(63, -56), Pair(-11, -45), Pair(104, -66), Pair(43, -94), Pair(22, -17), Pair(-14, -30),
        Pair(18, -74), Pair(-38, -26), Pair(-92, -20), Pair(-30, -40), Pair(-106, -27), Pair(8, -46), Pair(112, -118), Pair(-85, 31),
        Pair(165, -67), Pair(53, -98), Pair(185, -6), Pair(-68, -21), Pair(-125, -15), Pair(203, -33), Pair(-41, -56), Pair(-14, 29),
        Pair(100, -113), Pair(14, 1), Pair(206, -134), Pair(38, -36), Pair(-67, 49), Pair(-105, 86), Pair(43, -13), Pair(63, 1),
        Pair(75, -75), Pair(-14, -4), Pair(-61, 67), Pair(-42, 52), Pair(-87, 147), Pair(118, -94), Pair(160, -33), Pair(0, 0),
        Pair(-21, 69), Pair(-53, 79), Pair(-125, 81), Pair(-85, 73), Pair(11, 12), Pair(49, 41), Pair(199, 37), Pair(-36, 133)
      },
      { // Piece 4
        Pair(-3, -69), Pair(-14, -19), Pair(-44, -55), Pair(-87, -31), Pair(-46, -129), Pair(35, -25), Pair(24, -13), Pair(65, 42),
        Pair(-36, 101), Pair(-88, 39), Pair(-83, 68), Pair(9, 196), Pair(-6, 9), Pair(115, 23), Pair(61, -16), Pair(4, -5),
        Pair(176, -8), Pair(-18, -42), Pair(86, -143), Pair(28, -2), Pair(-101, -8), Pair(11, -71), Pair(195, 192), Pair(-68, 41),
        Pair(-126, -55), Pair(49, -105), Pair(32, 46), Pair(33, 32), Pair(-142, -104), Pair(28, -134), Pair(-43, 51), Pair(31, -86),
        Pair(-18, -156), Pair(42, 3), Pair(-86, 49), Pair(40, -44), Pair(-90, -40), Pair(16, -49), Pair(-51, -46), Pair(175, 24),
        Pair(60, 45), Pair(13, 12), Pair(-49, -7), Pair(-74, 84), Pair(-12, -56), Pair(-71, 37), Pair(69, 2), Pair(47, -83),
        Pair(129, -3), Pair(52, -7), Pair(33, -178), Pair(-50, -178), Pair(35, 103), Pair(22, 101), Pair(-56, -125), Pair(0, 0),
        Pair(17, -115), Pair(-218, 68), Pair(114, -63), Pair(-28, 90), Pair(-53, -107), Pair(-38, 76), Pair(-70, -38), Pair(-118, -86)
      },
      { // Piece 5
        Pair(3, -49), Pair(17, -177), Pair(-5, -115), Pair(-11, -110), Pair(25, 167), Pair(-33, -153), Pair(0, 1), Pair(-18, -81),
        Pair(77, -120), Pair(-12, -84), Pair(-33, -94), Pair(-24, 24), Pair(-58, -27), Pair(-3, -4), Pair(-17, -49), Pair(-16, -101),
        Pair(-14, -31), Pair(-74, -30), Pair(-11, -22), Pair(-28, -56), Pair(218, -38), Pair(118, 15), Pair(50, 20), Pair(-22, -68),
        Pair(67, -109), Pair(66, -15), Pair(-110, 21), Pair(85, -10), Pair(38, 12), Pair(97, 21), Pair(123, -41), Pair(-14, -120),
        Pair(-5, -28), Pair(-103, -44), Pair(270, -74), Pair(-34, -12), Pair(1, 27), Pair(5, 52), Pair(-105, 58), Pair(39, 62),
        Pair(-6, -48), Pair(-16, -66), Pair(-42, -33), Pair(191, -45), Pair(-32, 24), Pair(30, 66), Pair(-147, 132), Pair(-88, 132),
        Pair(-90, 36), Pair(-62, -18), Pair(55, -48), Pair(-154, 23), Pair(-97, 85), Pair(-71, 82), Pair(-257, 202), Pair(0, 0),
        Pair(-10, -125), Pair(-14, -56), Pair(-37, -83), Pair(45, -57), Pair(-127, -65), Pair(-225, 110), Pair(119, 64), Pair(131, 159)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, -36), Pair(13, -1), Pair(48, -18), Pair(-49, 29), Pair(-40, 13), Pair(-38, 28), Pair(86, -12), Pair(37, -11),
        Pair(0, 0), Pair(-3, -9), Pair(0, -7), Pair(-9, 7), Pair(-24, 7), Pair(-23, 4), Pair(-24, 10), Pair(-12, 4),
        Pair(36, -13), Pair(-1, -3), Pair(11, -11), Pair(5, -8), Pair(3, -4), Pair(-11, 1), Pair(-10, 3), Pair(-19, 11),
        Pair(-20, 2), Pair(3, -1), Pair(0, -7), Pair(-1, -10), Pair(-5, 0), Pair(-12, 2), Pair(-7, -3), Pair(-14, 0),
        Pair(0, 0), Pair(-2, -9), Pair(-1, -8), Pair(-2, -14), Pair(-10, -6), Pair(-11, -2), Pair(-8, -8), Pair(-10, -5),
        Pair(22, 29), Pair(-7, -15), Pair(3, -10), Pair(5, -17), Pair(-3, -6), Pair(-7, -6), Pair(-10, -5), Pair(-5, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(14, 11), Pair(35, 34), Pair(93, -4), Pair(55, -113), Pair(232, -107), Pair(-52, -10), Pair(-71, -136), Pair(-121, -12),
        Pair(-64, 24), Pair(83, -59), Pair(157, -67), Pair(45, -40), Pair(-14, 32), Pair(48, -23), Pair(31, -24), Pair(116, -46),
        Pair(202, -16), Pair(36, -26), Pair(22, 11), Pair(7, -3), Pair(8, -16), Pair(120, -65), Pair(69, -55), Pair(-30, -19),
        Pair(-58, 31), Pair(40, -9), Pair(57, -15), Pair(39, -23), Pair(17, -6), Pair(36, -26), Pair(30, -54), Pair(53, -64),
        Pair(4, -28), Pair(-12, 29), Pair(20, -21), Pair(4, 5), Pair(4, -6), Pair(44, -39), Pair(46, -53), Pair(29, -51),
        Pair(0, 0), Pair(-17, 13), Pair(0, 34), Pair(-5, 0), Pair(5, -12), Pair(11, -9), Pair(-4, -6), Pair(-12, -34),
        Pair(69, 72), Pair(-57, -144), Pair(27, -17), Pair(0, -9), Pair(6, -20), Pair(8, -71), Pair(0, -29), Pair(0, -19),
        Pair(-278, 72), Pair(4, 0), Pair(35, -2), Pair(-46, -56), Pair(12, -10), Pair(11, -46), Pair(26, -28), Pair(-48, -50)
      },
      { // Piece 2
        Pair(-168, 107), Pair(136, -17), Pair(-155, 83), Pair(-109, 46), Pair(136, 43), Pair(25, 67), Pair(-189, 140), Pair(111, 29),
        Pair(34, -14), Pair(-46, 16), Pair(146, -22), Pair(-53, 51), Pair(9, 63), Pair(6, 108), Pair(118, 53), Pair(16, 14),
        Pair(-1, 5), Pair(-19, 45), Pair(-47, 25), Pair(-13, 79), Pair(-88, 107), Pair(42, 40), Pair(25, 16), Pair(35, 13),
        Pair(22, 16), Pair(0, 7), Pair(8, 31), Pair(2, 64), Pair(43, 34), Pair(-13, 26), Pair(42, 9), Pair(18, 1),
        Pair(-19, 21), Pair(7, 51), Pair(-15, 69), Pair(9, 33), Pair(28, -6), Pair(10, 3), Pair(-16, 30), Pair(15, -11),
        Pair(0, 0), Pair(-20, 82), Pair(16, 48), Pair(2, 4), Pair(10, 30), Pair(3, -20), Pair(5, 22), Pair(-7, -5),
        Pair(15, 148), Pair(2, 49), Pair(-11, -11), Pair(24, 28), Pair(-10, 11), Pair(-9, 14), Pair(-8, -17), Pair(-6, 22),
        Pair(2, 18), Pair(-48, 112), Pair(-9, 24), Pair(-11, 17), Pair(22, 1), Pair(-7, -8), Pair(12, 37), Pair(43, 45)
      },
      { // Piece 3
        Pair(14, 82), Pair(31, 45), Pair(7, 32), Pair(48, 30), Pair(36, 55), Pair(194, -4), Pair(152, -1), Pair(133, 0),
        Pair(-16, 97), Pair(-16, 60), Pair(22, 38), Pair(-7, 74), Pair(29, 44), Pair(-12, 45), Pair(-55, 73), Pair(65, 23),
        Pair(6, 83), Pair(37, 8), Pair(6, 59), Pair(73, -1), Pair(76, 30), Pair(69, 20), Pair(46, 12), Pair(7, 46),
        Pair(29, 85), Pair(-33, 55), Pair(-19, 44), Pair(2, 23), Pair(28, 20), Pair(39, 10), Pair(7, 37), Pair(17, 30),
        Pair(-42, 75), Pair(7, 40), Pair(63, 15), Pair(0, 28), Pair(-1, 23), Pair(13, 26), Pair(12, 20), Pair(-12, 34),
        Pair(0, 0), Pair(-9, 68), Pair(23, 52), Pair(-19, 24), Pair(12, 21), Pair(62, 0), Pair(31, 10), Pair(59, -31),
        Pair(16, 68), Pair(109, -9), Pair(-10, 52), Pair(1, 35), Pair(-2, 50), Pair(21, 46), Pair(-14, 61), Pair(8, 27),
        Pair(-13, 69), Pair(7, 18), Pair(-1, 45), Pair(11, 29), Pair(2, 47), Pair(10, 27), Pair(53, -2), Pair(33, 27)
      },
      { // Piece 4
        Pair(91, -61), Pair(226, -133), Pair(51, 91), Pair(2, 58), Pair(-26, 75), Pair(77, 70), Pair(169, 0), Pair(3, 83),
        Pair(-43, 118), Pair(-41, 177), Pair(28, 34), Pair(-82, 123), Pair(53, 86), Pair(134, -5), Pair(17, 62), Pair(49, 54),
        Pair(-175, 243), Pair(63, -84), Pair(16, 59), Pair(56, 64), Pair(-27, 102), Pair(62, -1), Pair(110, -69), Pair(2, 82),
        Pair(16, 82), Pair(36, 27), Pair(2, 9), Pair(-12, 115), Pair(39, 24), Pair(20, 90), Pair(47, 19), Pair(34, 41),
        Pair(-11, 61), Pair(-42, 136), Pair(-26, 83), Pair(2, 71), Pair(-31, 83), Pair(9, 69), Pair(40, -16), Pair(28, 10),
        Pair(0, 0), Pair(15, 37), Pair(15, 19), Pair(14, 1), Pair(14, -5), Pair(19, 2), Pair(30, -2), Pair(79, -78),
        Pair(-79, 81), Pair(17, 39), Pair(12, 13), Pair(4, 4), Pair(4, 25), Pair(-19, 67), Pair(-24, 70), Pair(36, -95),
        Pair(-25, 62), Pair(4, 28), Pair(12, 5), Pair(5, 17), Pair(-24, 44), Pair(-18, 66), Pair(-88, 91), Pair(16, 113)
      },
      { // Piece 5
        Pair(1, 52), Pair(6, -29), Pair(-4, 38), Pair(90, 132), Pair(32, -102), Pair(-6, -170), Pair(6, -191), Pair(77, -25),
        Pair(27, -89), Pair(-46, -100), Pair(-44, -30), Pair(-55, -6), Pair(91, -100), Pair(11, -100), Pair(84, -99), Pair(0, -27),
        Pair(17, -58), Pair(-37, 18), Pair(62, -22), Pair(10, -12), Pair(253, -82), Pair(-3, -55), Pair(105, -90), Pair(-99, -34),
        Pair(28, -85), Pair(153, -5), Pair(-55, 17), Pair(132, -37), Pair(186, -38), Pair(204, -56), Pair(39, -46), Pair(73, -52),
        Pair(-59, -26), Pair(-104, 82), Pair(62, 5), Pair(42, -9), Pair(6, -4), Pair(84, -32), Pair(16, -48), Pair(128, -63),
        Pair(0, 0), Pair(-145, 105), Pair(-51, 42), Pair(-64, 25), Pair(17, -16), Pair(63, -37), Pair(43, -43), Pair(88, -63),
        Pair(55, 90), Pair(39, -15), Pair(-58, 54), Pair(2, -4), Pair(-25, -6), Pair(8, -38), Pair(-1, -39), Pair(10, -32),
        Pair(5, 62), Pair(-63, 90), Pair(-87, 52), Pair(-87, 7), Pair(-38, -14), Pair(15, -48), Pair(-1, -48), Pair(6, -56)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-22, -2), Pair(117, -11), Pair(36, 1), Pair(7, 11), Pair(29, 10), Pair(47, -9), Pair(57, -8), Pair(-63, 10),
        Pair(2, 8), Pair(0, 0), Pair(33, -23), Pair(6, -6), Pair(20, -8), Pair(-14, 16), Pair(16, 3), Pair(-9, 3),
        Pair(8, -10), Pair(14, -17), Pair(5, -4), Pair(5, -10), Pair(-6, 0), Pair(-7, -1), Pair(0, 4), Pair(8, 5),
        Pair(7, -4), Pair(15, -10), Pair(6, -9), Pair(9, -10), Pair(0, -5), Pair(-11, -2), Pair(0, -6), Pair(8, -4),
        Pair(17, -6), Pair(0, 0), Pair(15, -6), Pair(10, -12), Pair(2, -5), Pair(-5, -7), Pair(-14, -6), Pair(1, -11),
        Pair(13, -14), Pair(37, 27), Pair(-16, 6), Pair(17, -30), Pair(6, -10), Pair(-15, -6), Pair(-4, -7), Pair(-1, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(42, -98), Pair(-34, -8), Pair(58, -32), Pair(15, -54), Pair(-91, -33), Pair(106, -54), Pair(-27, -88), Pair(-53, -97),
        Pair(246, -52), Pair(34, -14), Pair(59, 7), Pair(-16, -38), Pair(90, -56), Pair(-73, 3), Pair(-81, 10), Pair(117, -70),
        Pair(162, -35), Pair(-20, 33), Pair(-7, 1), Pair(51, 7), Pair(46, 37), Pair(70, -22), Pair(3, -27), Pair(116, -38),
        Pair(3, 76), Pair(-35, 62), Pair(-22, 42), Pair(32, 8), Pair(5, 25), Pair(69, -21), Pair(50, -2), Pair(62, 14),
        Pair(-64, 112), Pair(51, -21), Pair(-15, 90), Pair(7, 34), Pair(35, 20), Pair(23, -30), Pair(28, 7), Pair(41, -42),
        Pair(9, -10), Pair(0, 0), Pair(-8, 37), Pair(-14, 76), Pair(-9, 34), Pair(28, 1), Pair(12, -21), Pair(55, -26),
        Pair(11, -61), Pair(50, 128), Pair(-89, -24), Pair(17, 13), Pair(15, -11), Pair(-29, -8), Pair(16, -54), Pair(-23, 41),
        Pair(-165, -19), Pair(-9, 31), Pair(87, -109), Pair(9, 39), Pair(22, -8), Pair(9, -58), Pair(-121, 11), Pair(-88, -176)
      },
      { // Piece 2
        Pair(34, -13), Pair(16, 38), Pair(-116, 47), Pair(-22, 27), Pair(-62, 23), Pair(45, 86), Pair(1, -37), Pair(0, 118),
        Pair(259, -12), Pair(-38, -4), Pair(-113, 43), Pair(-187, 84), Pair(-15, 61), Pair(103, 65), Pair(-24, 147), Pair(-25, 95),
        Pair(42, 3), Pair(37, -24), Pair(-15, 8), Pair(-11, 67), Pair(12, 44), Pair(50, 97), Pair(-92, 96), Pair(25, 10),
        Pair(-34, 0), Pair(-7, 18), Pair(-4, 50), Pair(-23, 53), Pair(-30, 96), Pair(-8, 62), Pair(6, 32), Pair(68, 5),
        Pair(-148, 42), Pair(10, -6), Pair(60, 2), Pair(-19, 107), Pair(15, 48), Pair(-26, 36), Pair(0, 45), Pair(-26, -19),
        Pair(9, 121), Pair(0, 0), Pair(-7, 73), Pair(4, 44), Pair(-14, 41), Pair(18, 14), Pair(-18, 62), Pair(17, -2),
        Pair(-161, 126), Pair(32, 160), Pair(46, 66), Pair(-5, 25), Pair(-3, 26), Pair(-30, 26), Pair(19, 13), Pair(17, -62),
        Pair(1, 136), Pair(-37, 29), Pair(-30, 61), Pair(-31, 11), Pair(-41, 29), Pair(23, 16), Pair(-87, 76), Pair(23, 16)
      },
      { // Piece 3
        Pair(31, 22), Pair(-45, 67), Pair(-40, 54), Pair(207, -45), Pair(88, -18), Pair(225, -62), Pair(-172, 103), Pair(86, 26),
        Pair(32, 41), Pair(68, 50), Pair(28, 35), Pair(31, 69), Pair(60, 36), Pair(155, -10), Pair(128, 1), Pair(156, -11),
        Pair(-16, 46), Pair(34, 63), Pair(28, 36), Pair(68, 23), Pair(163, -36), Pair(131, 3), Pair(222, -47), Pair(129, -24),
        Pair(12, 36), Pair(-28, 77), Pair(2, 22), Pair(82, -26), Pair(11, 16), Pair(18, 25), Pair(73, -4), Pair(145, -19),
        Pair(-13, 19), Pair(54, 55), Pair(-1, 30), Pair(-27, 26), Pair(15, 2), Pair(-11, 25), Pair(-16, 18), Pair(28, 10),
        Pair(-50, 35), Pair(0, 0), Pair(-7, 60), Pair(56, 28), Pair(-3, 30), Pair(26, 1), Pair(14, 63), Pair(94, -21),
        Pair(-24, 117), Pair(3, 72), Pair(-24, 13), Pair(-42, 64), Pair(6, 42), Pair(28, 41), Pair(19, 85), Pair(44, 50),
        Pair(-14, 31), Pair(-20, 63), Pair(-4, 37), Pair(-6, 38), Pair(4, 31), Pair(1, 37), Pair(22, 42), Pair(23, 20)
      },
      { // Piece 4
        Pair(102, -96), Pair(-47, 54), Pair(-77, 105), Pair(30, -23), Pair(-35, 96), Pair(61, -26), Pair(24, 25), Pair(64, 102),
        Pair(89, 23), Pair(12, 6), Pair(82, -90), Pair(-31, 164), Pair(85, -62), Pair(68, 119), Pair(-9, 78), Pair(41, 37),
        Pair(90, 1), Pair(94, -20), Pair(139, -140), Pair(-74, 139), Pair(153, -23), Pair(-13, 57), Pair(36, 102), Pair(61, -48),
        Pair(62, -46), Pair(29, 24), Pair(-131, 188), Pair(-42, 106), Pair(3, 81), Pair(23, 94), Pair(33, 32), Pair(77, -8),
        Pair(-48, -7), Pair(91, 6), Pair(-61, 82), Pair(43, 53), Pair(27, -5), Pair(33, -39), Pair(21, 11), Pair(42, 48),
        Pair(62, -190), Pair(0, 0), Pair(-34, 113), Pair(-3, 27), Pair(-3, 2), Pair(31, 25), Pair(6, 19), Pair(-30, 161),
        Pair(-9, 11), Pair(-38, 60), Pair(34, -31), Pair(5, 34), Pair(18, 3), Pair(-3, 20), Pair(43, -88), Pair(8, -11),
        Pair(10, -100), Pair(-43, 20), Pair(4, -22), Pair(4, -39), Pair(21, -7), Pair(-11, -68), Pair(59, -52), Pair(-31, -2)
      },
      { // Piece 5
        Pair(-45, -160), Pair(-63, -157), Pair(62, 12), Pair(-76, -99), Pair(4, 31), Pair(-13, -123), Pair(-62, -126), Pair(-1, -58),
        Pair(-7, -15), Pair(-7, -62), Pair(7, 0), Pair(10, 71), Pair(115, -22), Pair(26, -60), Pair(59, -67), Pair(-52, -76),
        Pair(-1, -80), Pair(87, -55), Pair(38, -6), Pair(67, 4), Pair(119, -53), Pair(133, -36), Pair(-29, -76), Pair(30, -64),
        Pair(-60, -77), Pair(89, -31), Pair(225, -18), Pair(-66, -2), Pair(5, -16), Pair(5, -2), Pair(67, -37), Pair(87, -80),
        Pair(77, 42), Pair(-53, 27), Pair(4, 31), Pair(94, -8), Pair(-28, 8), Pair(9, 0), Pair(1, -40), Pair(88, -84),
        Pair(-243, 147), Pair(0, 0), Pair(-128, 75), Pair(-24, 24), Pair(-84, 25), Pair(26, -20), Pair(22, -47), Pair(33, -33),
        Pair(104, 33), Pair(-170, 118), Pair(-19, 34), Pair(-95, 49), Pair(-11, -2), Pair(-30, -10), Pair(6, -34), Pair(-7, -25),
        Pair(-62, 50), Pair(-81, 66), Pair(-55, 60), Pair(-102, 5), Pair(-40, -5), Pair(-32, -32), Pair(4, -45), Pair(42, -100)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-34, 32), Pair(39, -7), Pair(-26, -1), Pair(26, 1), Pair(-12, 6), Pair(53, -20), Pair(-50, 36), Pair(1, -7),
        Pair(1, 8), Pair(-33, 23), Pair(0, 0), Pair(-21, -5), Pair(8, -8), Pair(10, -4), Pair(-16, 14), Pair(-21, 15),
        Pair(-8, 3), Pair(-3, -5), Pair(-21, 8), Pair(6, -3), Pair(-4, -2), Pair(-10, 0), Pair(-18, 9), Pair(-4, 4),
        Pair(-3, -4), Pair(4, -2), Pair(1, -3), Pair(1, 2), Pair(-4, 4), Pair(-8, -1), Pair(-7, 1), Pair(-5, -4),
        Pair(-6, -3), Pair(-1, 1), Pair(0, 0), Pair(5, -1), Pair(-10, 0), Pair(-19, 3), Pair(-13, -5), Pair(-10, 1),
        Pair(-3, 2), Pair(9, -15), Pair(27, 25), Pair(-29, -44), Pair(0, -3), Pair(-6, -2), Pair(-13, 0), Pair(-8, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-25, -10), Pair(114, -3), Pair(-37, 22), Pair(9, -42), Pair(86, 35), Pair(-39, 76), Pair(53, -112), Pair(-99, 4),
        Pair(-47, 16), Pair(-39, 9), Pair(7, -42), Pair(69, -7), Pair(76, 26), Pair(51, -28), Pair(61, -52), Pair(31, -139),
        Pair(241, -69), Pair(0, -38), Pair(22, 49), Pair(24, 38), Pair(39, 1), Pair(16, -7), Pair(30, 40), Pair(1, 28),
        Pair(42, -11), Pair(83, -6), Pair(31, 41), Pair(21, 50), Pair(25, 24), Pair(-1, 28), Pair(57, -32), Pair(92, -27),
        Pair(35, -2), Pair(-17, 88), Pair(1, 44), Pair(-1, 86), Pair(31, 26), Pair(36, 13), Pair(66, 21), Pair(55, 21),
        Pair(-90, 109), Pair(6, 4), Pair(0, 0), Pair(35, 29), Pair(-13, 87), Pair(34, -4), Pair(53, -6), Pair(36, -34),
        Pair(17, -44), Pair(67, -317), Pair(18, 143), Pair(27, -108), Pair(38, 33), Pair(19, 24), Pair(38, -4), Pair(-36, 41),
        Pair(18, 94), Pair(2, -36), Pair(32, 33), Pair(37, -53), Pair(-80, 112), Pair(-28, 15), Pair(16, -28), Pair(40, -127)
      },
      { // Piece 2
        Pair(43, 24), Pair(-51, 2), Pair(157, 28), Pair(20, 34), Pair(-84, 45), Pair(-72, 128), Pair(37, 70), Pair(33, -10),
        Pair(-22, 64), Pair(-54, 49), Pair(38, -3), Pair(66, 46), Pair(19, 19), Pair(-110, 47), Pair(-171, 128), Pair(49, 114),
        Pair(36, 29), Pair(-45, 26), Pair(28, 38), Pair(4, 46), Pair(-1, 37), Pair(-77, 104), Pair(87, 78), Pair(8, 67),
        Pair(-19, 52), Pair(24, 24), Pair(30, 52), Pair(35, 53), Pair(13, 27), Pair(46, 92), Pair(-12, 53), Pair(-2, 48),
        Pair(-121, 115), Pair(-2, 24), Pair(18, 28), Pair(-5, 66), Pair(7, 87), Pair(-17, 69), Pair(19, 14), Pair(18, 31),
        Pair(17, 1), Pair(0, 110), Pair(0, 0), Pair(5, 107), Pair(-4, 58), Pair(7, 28), Pair(7, 23), Pair(-13, 15),
        Pair(-30, -1), Pair(7, -83), Pair(32, 162), Pair(54, -32), Pair(5, 29), Pair(47, -1), Pair(23, 4), Pair(27, -8),
        Pair(-97, 7), Pair(-106, 117), Pair(3, 20), Pair(-65, 124), Pair(-39, 24), Pair(1, 54), Pair(47, 80), Pair(-68, 27)
      },
      { // Piece 3
        Pair(-34, 27), Pair(120, -8), Pair(108, 35), Pair(21, 37), Pair(37, 12), Pair(-114, 76), Pair(33, 15), Pair(-62, 58),
        Pair(13, 22), Pair(27, 52), Pair(85, 52), Pair(42, 19), Pair(43, 15), Pair(171, -9), Pair(253, -8), Pair(119, 12),
        Pair(15, 24), Pair(6, 18), Pair(12, 54), Pair(30, 27), Pair(25, 17), Pair(-94, 63), Pair(12, 15), Pair(64, -10),
        Pair(4, 34), Pair(32, 3), Pair(66, 28), Pair(21, 21), Pair(-25, 72), Pair(3, 8), Pair(113, -25), Pair(99, 2),
        Pair(-10, 24), Pair(22, 9), Pair(67, 31), Pair(-19, 58), Pair(-14, 43), Pair(-6, 43), Pair(28, 3), Pair(30, 1),
        Pair(-10, 20), Pair(-78, 133), Pair(0, 0), Pair(-72, 113), Pair(-56, 50), Pair(6, 29), Pair(-20, 71), Pair(-28, 28),
        Pair(-101, 88), Pair(-78, 83), Pair(-5, 92), Pair(-22, 108), Pair(12, 64), Pair(4, 62), Pair(9, 44), Pair(-9, 42),
        Pair(-5, 45), Pair(-1, 2), Pair(-33, 71), Pair(-9, 41), Pair(4, 33), Pair(10, 30), Pair(38, 18), Pair(6, 29)
      },
      { // Piece 4
        Pair(91, 2), Pair(108, 0), Pair(-95, 100), Pair(-33, 47), Pair(92, 15), Pair(72, -39), Pair(133, -25), Pair(-44, 79),
        Pair(46, -29), Pair(-53, 154), Pair(-9, 73), Pair(88, 25), Pair(-167, 301), Pair(51, 82), Pair(50, -49), Pair(101, -34),
        Pair(-59, 82), Pair(36, -45), Pair(-53, 163), Pair(-56, 157), Pair(9, 39), Pair(-55, 104), Pair(41, 87), Pair(68, -53),
        Pair(66, -76), Pair(65, -57), Pair(-15, 60), Pair(-42, 108), Pair(0, 41), Pair(-47, 130), Pair(50, -29), Pair(39, 71),
        Pair(29, -11), Pair(48, 48), Pair(80, -61), Pair(27, -28), Pair(-89, 163), Pair(58, -41), Pair(8, 64), Pair(-26, 121),
        Pair(-60, -5), Pair(39, -57), Pair(0, 0), Pair(-11, 71), Pair(-25, 32), Pair(-18, 30), Pair(66, -87), Pair(3, -28),
        Pair(-8, 43), Pair(15, 23), Pair(-3, 32), Pair(-9, 100), Pair(-8, 24), Pair(23, -35), Pair(-17, 91), Pair(-4, -27),
        Pair(2, -55), Pair(-67, 89), Pair(-28, 55), Pair(-8, 1), Pair(-40, 51), Pair(-47, 100), Pair(59, -15), Pair(62, 109)
      },
      { // Piece 5
        Pair(-16, -30), Pair(-100, -198), Pair(-31, -103), Pair(48, 123), Pair(3, -40), Pair(-26, -86), Pair(27, -69), Pair(-19, -151),
        Pair(-34, -250), Pair(2, 0), Pair(-100, -67), Pair(24, -10), Pair(14, -65), Pair(-85, -66), Pair(87, -89), Pair(-50, -114),
        Pair(0, 7), Pair(-8, -76), Pair(43, -47), Pair(49, -69), Pair(95, -35), Pair(67, -42), Pair(141, -52), Pair(-40, -119),
        Pair(61, 20), Pair(52, -38), Pair(75, 11), Pair(186, -30), Pair(69, -24), Pair(115, -11), Pair(86, -47), Pair(-115, -37),
        Pair(174, -18), Pair(79, 15), Pair(49, 6), Pair(95, 24), Pair(60, -7), Pair(24, -12), Pair(-6, -15), Pair(71, -95),
        Pair(-110, 67), Pair(-231, 117), Pair(0, 0), Pair(-20, 53), Pair(-43, 16), Pair(-31, 5), Pair(22, -15), Pair(-25, -30),
        Pair(-166, 61), Pair(35, 86), Pair(-132, 105), Pair(-35, 173), Pair(-55, 23), Pair(24, -12), Pair(-4, -22), Pair(-9, -25),
        Pair(-177, 118), Pair(-38, 3), Pair(-135, 92), Pair(-146, 99), Pair(-36, -3), Pair(17, -11), Pair(4, -53), Pair(28, -95)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 17), Pair(-31, 30), Pair(-63, 14), Pair(-19, 10), Pair(-46, 23), Pair(-67, 27), Pair(41, 5), Pair(67, 6),
        Pair(8, -6), Pair(-7, 6), Pair(21, 5), Pair(0, 0), Pair(16, 4), Pair(-7, 6), Pair(36, 0), Pair(-19, 10),
        Pair(-1, 2), Pair(-1, -9), Pair(4, -3), Pair(12, -10), Pair(2, -7), Pair(0, -6), Pair(13, -9), Pair(9, -3),
        Pair(-2, -10), Pair(3, -14), Pair(-4, -4), Pair(3, -14), Pair(6, -5), Pair(-2, -1), Pair(6, -7), Pair(-10, 0),
        Pair(2, -6), Pair(-4, -3), Pair(-6, 3), Pair(0, 0), Pair(3, -3), Pair(-5, -1), Pair(3, -4), Pair(-10, -3),
        Pair(4, -10), Pair(-5, -3), Pair(14, -40), Pair(24, 16), Pair(-4, -18), Pair(-6, -1), Pair(6, -10), Pair(-4, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-81, -21), Pair(-211, 105), Pair(182, -70), Pair(103, 39), Pair(-34, 77), Pair(123, -46), Pair(14, -37), Pair(-14, -107),
        Pair(-30, 10), Pair(-63, 49), Pair(-41, 45), Pair(198, -39), Pair(12, 1), Pair(97, -29), Pair(219, -75), Pair(-8, 83),
        Pair(15, -80), Pair(65, -5), Pair(-37, 11), Pair(18, 1), Pair(-4, 44), Pair(34, -24), Pair(39, -1), Pair(39, 43),
        Pair(-53, 25), Pair(22, 39), Pair(-16, 25), Pair(25, -15), Pair(51, 2), Pair(55, -12), Pair(31, -9), Pair(4, 15),
        Pair(18, 58), Pair(-62, 82), Pair(-8, 106), Pair(1, 40), Pair(17, 92), Pair(-15, 24), Pair(27, 21), Pair(33, 25),
        Pair(-47, -23), Pair(-16, 97), Pair(-9, 34), Pair(0, 0), Pair(-20, 56), Pair(-6, 79), Pair(-8, 2), Pair(20, 26),
        Pair(-64, 75), Pair(26, 52), Pair(9, -53), Pair(13, 153), Pair(-35, 10), Pair(-21, 15), Pair(53, -4), Pair(7, 40),
        Pair(-100, -158), Pair(-36, 96), Pair(-98, 110), Pair(-66, 85), Pair(25, 33), Pair(-5, 110), Pair(19, -76), Pair(-52, -113)
      },
      { // Piece 2
        Pair(-59, 142), Pair(-167, 117), Pair(40, 33), Pair(43, 98), Pair(109, -8), Pair(-90, 56), Pair(-34, -134), Pair(123, 131),
        Pair(53, 9), Pair(2, 26), Pair(-79, 40), Pair(119, 78), Pair(-42, 94), Pair(-19, 89), Pair(46, 57), Pair(-99, 106),
        Pair(-11, -34), Pair(-44, 57), Pair(12, 56), Pair(-27, 61), Pair(-67, 108), Pair(92, 32), Pair(-29, 87), Pair(-38, 83),
        Pair(12, 95), Pair(-37, 34), Pair(40, 1), Pair(34, 51), Pair(24, 42), Pair(-66, 87), Pair(-16, 127), Pair(-25, 25),
        Pair(4, 44), Pair(9, 100), Pair(6, 32), Pair(36, 5), Pair(-41, 73), Pair(-16, 98), Pair(19, 23), Pair(77, 7),
        Pair(-22, 65), Pair(-9, 60), Pair(17, 89), Pair(0, 0), Pair(2, 104), Pair(1, 50), Pair(19, -9), Pair(-23, 42),
        Pair(8, 27), Pair(-7, 12), Pair(-49, 52), Pair(18, 164), Pair(35, -120), Pair(40, -31), Pair(1, 17), Pair(13, 24),
        Pair(4, 72), Pair(19, -51), Pair(-36, 91), Pair(-9, 43), Pair(-45, 139), Pair(1, -64), Pair(72, -10), Pair(0, 42)
      },
      { // Piece 3
        Pair(75, -12), Pair(-32, 58), Pair(84, 3), Pair(72, 39), Pair(-26, 53), Pair(119, 0), Pair(165, 9), Pair(-87, 74),
        Pair(-5, 36), Pair(12, 35), Pair(-4, 27), Pair(-88, 87), Pair(2, 47), Pair(69, 10), Pair(-25, 46), Pair(130, 7),
        Pair(54, 7), Pair(36, -7), Pair(0, 39), Pair(3, 69), Pair(47, 26), Pair(93, -14), Pair(56, 22), Pair(-5, 43),
        Pair(72, 3), Pair(12, 38), Pair(1, 51), Pair(39, 32), Pair(-1, 12), Pair(-13, 38), Pair(93, -12), Pair(12, 13),
        Pair(35, 11), Pair(-6, 25), Pair(17, 63), Pair(9, 83), Pair(15, 12), Pair(-22, 48), Pair(-4, 17), Pair(-62, 46),
        Pair(-42, 71), Pair(17, 18), Pair(-1, 38), Pair(0, 0), Pair(5, 49), Pair(108, -5), Pair(33, 20), Pair(-14, 16),
        Pair(-37, 75), Pair(-76, 102), Pair(131, 3), Pair(-24, 110), Pair(-134, 102), Pair(-9, 74), Pair(-46, 73), Pair(-1, 44),
        Pair(6, 37), Pair(-6, 47), Pair(-11, 43), Pair(-11, 86), Pair(8, 24), Pair(10, 41), Pair(34, 40), Pair(13, 24)
      },
      { // Piece 4
        Pair(60, 2), Pair(-29, 81), Pair(7, -12), Pair(-26, 78), Pair(35, 51), Pair(93, 98), Pair(23, 36), Pair(106, -35),
        Pair(67, -73), Pair(-23, 32), Pair(76, -68), Pair(38, 13), Pair(82, -43), Pair(-37, 148), Pair(143, 10), Pair(60, -90),
        Pair(10, -73), Pair(-33, 22), Pair(3, 11), Pair(-29, 70), Pair(-64, 187), Pair(31, 126), Pair(-74, 81), Pair(-19, 105),
        Pair(-2, 82), Pair(13, 11), Pair(33, -25), Pair(-13, 40), Pair(54, 37), Pair(-66, 141), Pair(21, 38), Pair(18, 54),
        Pair(-9, 26), Pair(-6, 66), Pair(26, -69), Pair(28, 94), Pair(-2, 61), Pair(33, -12), Pair(4, 7), Pair(-60, 137),
        Pair(64, -138), Pair(-12, 13), Pair(-2, 54), Pair(0, 0), Pair(13, -5), Pair(-9, 41), Pair(-4, 14), Pair(12, -51),
        Pair(-28, 73), Pair(-41, 94), Pair(-34, 29), Pair(6, 22), Pair(-6, 6), Pair(-2, 38), Pair(-78, 83), Pair(59, -143),
        Pair(-34, 49), Pair(18, -79), Pair(-19, 19), Pair(-9, 13), Pair(-12, 62), Pair(44, -76), Pair(119, -87), Pair(0, -66)
      },
      { // Piece 5
        Pair(-15, -103), Pair(-12, -51), Pair(-3, -39), Pair(-1, -80), Pair(0, -20), Pair(-2, -80), Pair(-57, -113), Pair(-101, -63),
        Pair(2, 13), Pair(-23, -54), Pair(13, -33), Pair(7, -97), Pair(-98, -11), Pair(-60, -5), Pair(-69, -24), Pair(19, 28),
        Pair(14, -158), Pair(-38, 0), Pair(-33, 43), Pair(-22, -50), Pair(107, 12), Pair(31, -39), Pair(-77, -8), Pair(-47, -75),
        Pair(58, 8), Pair(106, -45), Pair(222, -73), Pair(-7, -67), Pair(-25, -18), Pair(86, -48), Pair(-18, -6), Pair(-165, -4),
        Pair(-39, -190), Pair(10, -6), Pair(17, 35), Pair(-38, 38), Pair(114, 10), Pair(24, 2), Pair(19, -2), Pair(-29, -35),
        Pair(24, 27), Pair(-181, 50), Pair(-34, 63), Pair(0, 0), Pair(-59, 56), Pair(-25, 22), Pair(-9, 17), Pair(-23, -38),
        Pair(107, -19), Pair(-53, 8), Pair(-66, -139), Pair(-99, 88), Pair(151, 6), Pair(-17, 12), Pair(-5, 1), Pair(47, -37),
        Pair(99, -65), Pair(-18, 17), Pair(-93, 81), Pair(-37, 61), Pair(-33, 74), Pair(-42, 13), Pair(6, -9), Pair(9, -36)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, 10), Pair(49, -9), Pair(-37, 23), Pair(-42, 5), Pair(-124, 43), Pair(-44, 18), Pair(-59, -1), Pair(-5, 7),
        Pair(24, -7), Pair(-20, 7), Pair(-9, 8), Pair(-16, -4), Pair(0, 0), Pair(-3, -8), Pair(-10, 5), Pair(-15, -2),
        Pair(5, -11), Pair(-4, -5), Pair(-12, -11), Pair(-2, -5), Pair(-6, 2), Pair(14, -18), Pair(6, -1), Pair(-15, 5),
        Pair(2, -12), Pair(5, -13), Pair(-3, -4), Pair(-2, -1), Pair(10, -6), Pair(-4, 9), Pair(-2, -6), Pair(9, -8),
        Pair(2, -13), Pair(1, -9), Pair(-3, -9), Pair(6, -6), Pair(0, 0), Pair(6, -3), Pair(2, -5), Pair(-1, -2),
        Pair(-1, -6), Pair(-5, -1), Pair(0, 5), Pair(30, -95), Pair(32, 2), Pair(-6, -27), Pair(10, -6), Pair(11, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-93, -156), Pair(1, 19), Pair(170, -44), Pair(-56, 16), Pair(-165, -84), Pair(70, -24), Pair(69, 44), Pair(102, -104),
        Pair(179, -96), Pair(-101, 19), Pair(55, 13), Pair(37, -35), Pair(-186, 79), Pair(-27, 44), Pair(-43, -56), Pair(300, -94),
        Pair(-112, 132), Pair(-15, -30), Pair(-57, 9), Pair(-37, 3), Pair(-55, 31), Pair(93, 7), Pair(6, 8), Pair(53, 25),
        Pair(-43, 68), Pair(-33, 45), Pair(-39, 49), Pair(-4, -5), Pair(0, -10), Pair(8, 49), Pair(-9, 24), Pair(97, -53),
        Pair(10, -59), Pair(-42, 21), Pair(8, -9), Pair(-21, 79), Pair(-16, 23), Pair(24, 66), Pair(41, 92), Pair(39, 46),
        Pair(-14, 50), Pair(-73, 61), Pair(-15, 62), Pair(-32, 31), Pair(0, 0), Pair(3, 39), Pair(-7, 29), Pair(-21, 1),
        Pair(-45, -21), Pair(-14, 42), Pair(-4, 43), Pair(-43, -79), Pair(-10, 133), Pair(-60, 38), Pair(7, 13), Pair(-42, 17),
        Pair(-147, 54), Pair(-7, -30), Pair(-66, 125), Pair(-54, -9), Pair(26, -10), Pair(11, -65), Pair(-20, 59), Pair(-199, -18)
      },
      { // Piece 2
        Pair(-34, 43), Pair(-20, 18), Pair(117, 1), Pair(-29, 24), Pair(-223, 89), Pair(-170, 13), Pair(-22, 50), Pair(223, 201),
        Pair(23, 28), Pair(-86, 45), Pair(38, -2), Pair(-39, 30), Pair(98, 47), Pair(65, 13), Pair(-42, 68), Pair(-110, 32),
        Pair(-20, 114), Pair(-57, 38), Pair(-17, 40), Pair(52, -30), Pair(58, 17), Pair(-46, 24), Pair(72, 2), Pair(65, -3),
        Pair(-7, 50), Pair(-25, 89), Pair(-38, 69), Pair(-51, 69), Pair(-48, 38), Pair(48, -3), Pair(-22, 36), Pair(41, 48),
        Pair(-37, 10), Pair(-22, 48), Pair(-15, 100), Pair(-69, 34), Pair(63, -16), Pair(-54, 70), Pair(0, 65), Pair(32, -4),
        Pair(-10, 66), Pair(0, -20), Pair(11, 42), Pair(0, 94), Pair(0, 0), Pair(-4, 78), Pair(-41, 72), Pair(-35, 33),
        Pair(-97, 11), Pair(4, 18), Pair(-30, 35), Pair(-21, -66), Pair(1, 132), Pair(10, 42), Pair(-7, 4), Pair(8, 46),
        Pair(116, -17), Pair(22, -41), Pair(-26, -34), Pair(-15, 55), Pair(8, 27), Pair(-56, 75), Pair(43, -61), Pair(126, -58)
      },
      { // Piece 3
        Pair(74, 3), Pair(-49, 50), Pair(-6, 0), Pair(118, -12), Pair(-5, 28), Pair(176, -21), Pair(-99, 25), Pair(-29, 26),
        Pair(47, -13), Pair(-9, 13), Pair(6, 6), Pair(-3, 6), Pair(27, -2), Pair(-29, 9), Pair(62, 8), Pair(38, -1),
        Pair(42, -24), Pair(65, -20), Pair(94, -55), Pair(61, -47), Pair(59, -12), Pair(-17, -5), Pair(55, -26), Pair(-48, -3),
        Pair(60, -19), Pair(34, -28), Pair(-38, -10), Pair(12, 9), Pair(48, 8), Pair(32, -66), Pair(49, -13), Pair(1, 15),
        Pair(-13, 8), Pair(8, -18), Pair(35, -24), Pair(21, -20), Pair(-44, 48), Pair(-26, 19), Pair(50, -4), Pair(111, -24),
        Pair(-22, -41), Pair(3, -39), Pair(65, -14), Pair(-71, 44), Pair(0, 0), Pair(8, 69), Pair(81, -70), Pair(58, -95),
        Pair(-52, 45), Pair(-37, 47), Pair(-32, 33), Pair(-74, 60), Pair(-11, 78), Pair(-41, 49), Pair(41, 5), Pair(91, -17),
        Pair(-24, 6), Pair(-6, 2), Pair(-9, 3), Pair(-13, 28), Pair(-24, 45), Pair(-1, -1), Pair(23, 17), Pair(35, 16)
      },
      { // Piece 4
        Pair(-62, 32), Pair(-89, 20), Pair(-185, 103), Pair(115, 10), Pair(-88, 142), Pair(-43, 170), Pair(-117, 43), Pair(64, -52),
        Pair(9, -29), Pair(-54, 117), Pair(-55, 52), Pair(-117, 104), Pair(9, -9), Pair(146, -100), Pair(14, 36), Pair(145, -71),
        Pair(4, 37), Pair(5, -16), Pair(110, -162), Pair(5, -83), Pair(38, 46), Pair(-5, 137), Pair(-12, -15), Pair(-54, 52),
        Pair(-80, 67), Pair(-55, 114), Pair(-89, 74), Pair(-30, 61), Pair(24, -23), Pair(39, 2), Pair(179, -124), Pair(-10, 29),
        Pair(2, -50), Pair(17, -80), Pair(-50, 137), Pair(-34, -4), Pair(75, -59), Pair(92, -156), Pair(-5, 10), Pair(-10, 67),
        Pair(-4, -47), Pair(-18, -42), Pair(-7, -57), Pair(39, -32), Pair(0, 0), Pair(-44, 51), Pair(-37, 12), Pair(1, -13),
        Pair(-2, -60), Pair(8, 13), Pair(-32, 1), Pair(-39, -121), Pair(-17, 50), Pair(-38, -6), Pair(-73, 112), Pair(-98, 172),
        Pair(9, -102), Pair(-12, -69), Pair(6, -62), Pair(-5, -25), Pair(-6, -67), Pair(-10, -39), Pair(16, -27), Pair(-38, -89)
      },
      { // Piece 5
        Pair(-13, -161), Pair(18, -169), Pair(-19, -89), Pair(-85, -121), Pair(-55, -103), Pair(-7, 82), Pair(27, -64), Pair(9, -157),
        Pair(-1, -265), Pair(50, -69), Pair(23, -66), Pair(-10, -116), Pair(5, -78), Pair(11, -21), Pair(-9, -78), Pair(-38, -146),
        Pair(7, -106), Pair(-22, -37), Pair(65, -68), Pair(146, -115), Pair(43, -57), Pair(190, -56), Pair(4, -41), Pair(39, 5),
        Pair(-71, -68), Pair(-68, -44), Pair(-29, -18), Pair(-10, -42), Pair(-26, -17), Pair(231, -14), Pair(56, -55), Pair(24, -10),
        Pair(150, -103), Pair(-87, -11), Pair(-24, -14), Pair(-63, 49), Pair(-106, 63), Pair(108, 20), Pair(-44, 7), Pair(108, -40),
        Pair(147, -97), Pair(-38, -4), Pair(43, 19), Pair(-103, 74), Pair(0, 0), Pair(-50, 57), Pair(-6, 9), Pair(51, -7),
        Pair(4, 9), Pair(-44, 25), Pair(27, 7), Pair(-34, 25), Pair(-147, 100), Pair(0, 124), Pair(-27, 32), Pair(7, 14),
        Pair(-3, -2), Pair(-5, -41), Pair(-17, -22), Pair(-55, 63), Pair(-21, 74), Pair(-80, 72), Pair(-31, 19), Pair(-13, 15)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(20, 0), Pair(-2, 12), Pair(-38, 11), Pair(-21, -2), Pair(-59, 4), Pair(7, 33), Pair(60, -3), Pair(-41, 23),
        Pair(22, -5), Pair(13, -16), Pair(-10, 4), Pair(7, -6), Pair(3, 8), Pair(0, 0), Pair(25, 11), Pair(29, -13),
        Pair(4, -8), Pair(-4, -15), Pair(0, -16), Pair(3, -6), Pair(9, -14), Pair(6, -3), Pair(20, -6), Pair(20, -5),
        Pair(8, -13), Pair(-1, -11), Pair(-5, -12), Pair(-4, -12), Pair(-11, -5), Pair(-4, -7), Pair(8, -3), Pair(10, -5),
        Pair(8, -15), Pair(-2, -9), Pair(-4, -9), Pair(0, -3), Pair(-2, -8), Pair(0, 0), Pair(7, -3), Pair(22, -5),
        Pair(8, -13), Pair(-7, -6), Pair(-4, -17), Pair(2, -3), Pair(17, -47), Pair(17, -3), Pair(12, -16), Pair(19, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(26, -190), Pair(-16, -6), Pair(74, -34), Pair(167, -56), Pair(-194, -28), Pair(-11, -3), Pair(-59, -1), Pair(77, 69),
        Pair(-86, 69), Pair(83, -95), Pair(-31, -10), Pair(41, 23), Pair(145, -51), Pair(102, -78), Pair(-14, -57), Pair(-153, -28),
        Pair(128, -62), Pair(-72, 14), Pair(-11, 18), Pair(68, 1), Pair(39, -40), Pair(119, 45), Pair(52, 5), Pair(-139, 41),
        Pair(3, -36), Pair(-36, -9), Pair(-7, 8), Pair(31, -25), Pair(39, 0), Pair(5, 17), Pair(85, -10), Pair(91, -14),
        Pair(-63, -34), Pair(-75, 15), Pair(-2, -3), Pair(-27, 21), Pair(-24, 71), Pair(5, 19), Pair(19, 23), Pair(-19, 20),
        Pair(-21, -50), Pair(-54, 71), Pair(-32, 12), Pair(-30, 68), Pair(15, 4), Pair(0, 0), Pair(-20, 9), Pair(-60, -56),
        Pair(54, -34), Pair(-96, 31), Pair(-59, 32), Pair(-29, 8), Pair(-57, -19), Pair(-18, 115), Pair(23, -11), Pair(-58, 54),
        Pair(-31, -105), Pair(-6, -8), Pair(-107, 35), Pair(-26, 29), Pair(65, -44), Pair(7, 1), Pair(-52, -91), Pair(-171, 97)
      },
      { // Piece 2
        Pair(-71, 35), Pair(72, -30), Pair(134, -26), Pair(-23, 53), Pair(-7, 54), Pair(-52, -12), Pair(-50, -24), Pair(-117, 12),
        Pair(-155, 50), Pair(7, 64), Pair(-97, 43), Pair(-166, 75), Pair(-142, 68), Pair(-5, 59), Pair(-30, 38), Pair(-203, 18),
        Pair(-10, 8), Pair(-56, 43), Pair(14, 46), Pair(-93, 49), Pair(-36, 60), Pair(8, 59), Pair(32, 69), Pair(-39, 5),
        Pair(-4, 1), Pair(33, 36), Pair(-10, 42), Pair(22, 35), Pair(-7, 14), Pair(18, 79), Pair(-15, 38), Pair(29, -36),
        Pair(-76, 53), Pair(2, -6), Pair(0, 2), Pair(-19, 15), Pair(-28, 19), Pair(-32, 41), Pair(-45, 48), Pair(-48, 51),
        Pair(-33, -3), Pair(28, 18), Pair(-26, 39), Pair(-25, 55), Pair(-64, 47), Pair(0, 0), Pair(-26, 71), Pair(36, -17),
        Pair(5, -4), Pair(-37, -10), Pair(-43, 81), Pair(-49, 13), Pair(8, -66), Pair(-9, 118), Pair(-3, -73), Pair(-37, 9),
        Pair(-47, -19), Pair(7, 50), Pair(-39, -30), Pair(-69, 28), Pair(-86, 50), Pair(-3, -13), Pair(-192, 107), Pair(-112, -82)
      },
      { // Piece 3
        Pair(-7, 6), Pair(31, -2), Pair(14, 16), Pair(3, 10), Pair(98, -10), Pair(133, -4), Pair(21, 36), Pair(-13, 36),
        Pair(-11, 11), Pair(-14, -4), Pair(61, -3), Pair(10, 13), Pair(-35, 40), Pair(-20, 40), Pair(-39, 17), Pair(129, -56),
        Pair(-30, 1), Pair(23, -13), Pair(-8, -13), Pair(65, -16), Pair(-20, 9), Pair(8, 35), Pair(57, -7), Pair(97, -44),
        Pair(-13, -10), Pair(-99, 22), Pair(-29, 9), Pair(-22, 1), Pair(-35, 5), Pair(64, 8), Pair(161, -54), Pair(4, -9),
        Pair(-34, -23), Pair(-43, 22), Pair(-30, 0), Pair(-25, 21), Pair(-7, 8), Pair(81, 46), Pair(61, -24), Pair(40, -29),
        Pair(-16, -11), Pair(39, -60), Pair(-10, -15), Pair(-17, 20), Pair(26, -44), Pair(0, 0), Pair(118, 1), Pair(90, -67),
        Pair(-89, 26), Pair(-38, 9), Pair(6, -1), Pair(21, -20), Pair(51, -55), Pair(-35, 77), Pair(68, -46), Pair(-76, 35),
        Pair(3, -28), Pair(-14, -12), Pair(-7, -18), Pair(-10, 6), Pair(-9, 10), Pair(-27, 18), Pair(30, -23), Pair(0, 4)
      },
      { // Piece 4
        Pair(-62, -133), Pair(38, 51), Pair(21, 2), Pair(45, -34), Pair(-90, 22), Pair(58, 49), Pair(28, 33), Pair(19, 3),
        Pair(22, -19), Pair(-9, -72), Pair(-65, 66), Pair(-10, -33), Pair(-130, 136), Pair(70, 15), Pair(-8, 3), Pair(43, -43),
        Pair(66, -171), Pair(-51, 56), Pair(-36, 88), Pair(-31, 85), Pair(61, -41), Pair(177, -111), Pair(71, -109), Pair(-12, -84),
        Pair(24, -22), Pair(-34, -7), Pair(-128, 68), Pair(-101, 132), Pair(21, -70), Pair(-22, -36), Pair(23, -78), Pair(-11, 33),
        Pair(-60, 46), Pair(-26, -71), Pair(-21, 6), Pair(-74, 56), Pair(-95, 78), Pair(-23, -8), Pair(-82, 140), Pair(-32, -16),
        Pair(-68, 71), Pair(-70, 1), Pair(14, -62), Pair(-55, 27), Pair(16, -29), Pair(0, 0), Pair(-15, -73), Pair(31, -67),
        Pair(5, -167), Pair(-77, -8), Pair(-31, -95), Pair(-94, 101), Pair(-92, 58), Pair(-101, 95), Pair(-142, 21), Pair(-54, 71),
        Pair(-71, -25), Pair(5, -176), Pair(-31, -15), Pair(-18, -94), Pair(-66, 9), Pair(-3, -33), Pair(-128, 139), Pair(-101, 49)
      },
      { // Piece 5
        Pair(25, -116), Pair(-19, -93), Pair(-20, -140), Pair(-82, -57), Pair(-73, -114), Pair(-6, -117), Pair(-20, -197), Pair(-9, -72),
        Pair(-27, -89), Pair(-9, -111), Pair(112, -36), Pair(99, -75), Pair(-22, -66), Pair(-33, -131), Pair(6, -32), Pair(57, 24),
        Pair(32, -125), Pair(5, -65), Pair(27, -47), Pair(11, -69), Pair(-66, 26), Pair(13, 1), Pair(42, -18), Pair(0, -75),
        Pair(-193, -52), Pair(129, -64), Pair(70, -55), Pair(106, -31), Pair(246, -84), Pair(48, -1), Pair(17, 9), Pair(149, -29),
        Pair(-95, -72), Pair(96, -56), Pair(130, -46), Pair(110, -33), Pair(106, 2), Pair(-96, 48), Pair(113, 31), Pair(-52, 11),
        Pair(-97, -40), Pair(80, -34), Pair(44, -8), Pair(20, -2), Pair(0, 44), Pair(0, 0), Pair(-22, 43), Pair(35, 29),
        Pair(29, 4), Pair(50, -34), Pair(53, -21), Pair(22, 11), Pair(-6, 110), Pair(-120, 80), Pair(-117, 75), Pair(-67, 55),
        Pair(44, -56), Pair(-31, 1), Pair(1, -3), Pair(73, -30), Pair(-24, 29), Pair(-100, 69), Pair(-35, 24), Pair(-48, 15)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 3), Pair(7, -1), Pair(5, -5), Pair(-103, 21), Pair(-60, 12), Pair(78, -40), Pair(58, -13), Pair(47, -8),
        Pair(24, -9), Pair(-16, -3), Pair(16, -14), Pair(-36, 0), Pair(10, -4), Pair(-25, -11), Pair(0, 0), Pair(-12, -5),
        Pair(10, -12), Pair(-14, -9), Pair(-4, -8), Pair(-2, -6), Pair(-4, 3), Pair(-3, -2), Pair(0, -14), Pair(11, -11),
        Pair(11, -20), Pair(-2, -25), Pair(9, -9), Pair(-10, -7), Pair(-7, -5), Pair(-6, -5), Pair(0, -6), Pair(12, -2),
        Pair(-2, -18), Pair(-4, -13), Pair(-14, -12), Pair(-9, 0), Pair(9, -10), Pair(-9, -1), Pair(0, 0), Pair(16, -3),
        Pair(6, -21), Pair(-7, -5), Pair(14, -11), Pair(-4, 18), Pair(-7, -1), Pair(-21, -16), Pair(1, 0), Pair(9, -9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(94, -88), Pair(142, -175), Pair(-16, -41), Pair(-109, 26), Pair(-58, 26), Pair(10, -38), Pair(-23, -181), Pair(94, 9),
        Pair(29, -8), Pair(-8, -90), Pair(67, 15), Pair(1, 4), Pair(80, 7), Pair(-24, -52), Pair(28, -64), Pair(82, -56),
        Pair(-82, 4), Pair(-12, -81), Pair(-37, -19), Pair(1, -4), Pair(43, -11), Pair(71, -23), Pair(13, -57), Pair(106, -53),
        Pair(-33, -52), Pair(-48, 22), Pair(61, -27), Pair(8, -20), Pair(64, -23), Pair(89, -27), Pair(24, 55), Pair(120, -86),
        Pair(21, -78), Pair(-116, -17), Pair(28, -41), Pair(23, -17), Pair(74, -37), Pair(2, 63), Pair(6, -10), Pair(-18, 25),
        Pair(-8, 38), Pair(18, -48), Pair(-7, 6), Pair(23, -24), Pair(-78, 59), Pair(42, -26), Pair(0, 0), Pair(7, 35),
        Pair(-35, 15), Pair(-72, -96), Pair(-26, -16), Pair(-31, 0), Pair(30, 11), Pair(24, -155), Pair(-16, 52), Pair(40, -200),
        Pair(-51, -41), Pair(-25, -43), Pair(32, -35), Pair(-22, -2), Pair(-58, 51), Pair(-15, -4), Pair(58, -76), Pair(-75, -132)
      },
      { // Piece 2
        Pair(-117, 149), Pair(17, 9), Pair(-114, 65), Pair(-42, 23), Pair(-25, 61), Pair(76, 48), Pair(-92, 13), Pair(171, -56),
        Pair(-154, 72), Pair(27, 82), Pair(86, -16), Pair(-124, 56), Pair(-58, 35), Pair(-188, 4), Pair(-215, 82), Pair(146, -3),
        Pair(123, -18), Pair(-123, 58), Pair(-46, 91), Pair(-94, 70), Pair(-12, 48), Pair(-21, 24), Pair(-7, 16), Pair(30, 16),
        Pair(-26, -47), Pair(-67, 47), Pair(-6, -2), Pair(-64, 62), Pair(-51, 8), Pair(37, 3), Pair(18, -51), Pair(-8, -71),
        Pair(-4, 15), Pair(-67, 27), Pair(9, -12), Pair(-15, 15), Pair(-43, 67), Pair(12, 32), Pair(67, 20), Pair(19, -27),
        Pair(-28, 7), Pair(-8, 15), Pair(-11, 5), Pair(-46, 22), Pair(-44, 28), Pair(2, 51), Pair(0, 0), Pair(87, 35),
        Pair(-76, 6), Pair(1, -31), Pair(-17, -51), Pair(-33, 28), Pair(-11, 3), Pair(-75, -40), Pair(8, 120), Pair(87, 16),
        Pair(47, -35), Pair(51, -22), Pair(-43, -5), Pair(-53, 11), Pair(74, -32), Pair(-37, 31), Pair(-99, 22), Pair(-98, 128)
      },
      { // Piece 3
        Pair(1, 20), Pair(122, -83), Pair(74, -53), Pair(130, -42), Pair(-89, 3), Pair(-146, 33), Pair(169, -34), Pair(-128, -10),
        Pair(61, -18), Pair(116, -65), Pair(81, -37), Pair(91, -54), Pair(26, -2), Pair(117, -48), Pair(211, -48), Pair(-1, -36),
        Pair(38, -18), Pair(97, -75), Pair(-6, -10), Pair(110, -60), Pair(61, -71), Pair(65, -15), Pair(29, -22), Pair(110, -58),
        Pair(45, -39), Pair(-23, -21), Pair(124, -65), Pair(58, -49), Pair(33, -14), Pair(59, -63), Pair(-82, 43), Pair(169, -80),
        Pair(-34, -15), Pair(-24, -6), Pair(49, -38), Pair(-22, 12), Pair(24, -59), Pair(-28, -42), Pair(-21, 28), Pair(74, -23),
        Pair(3, -10), Pair(26, -7), Pair(-91, 31), Pair(101, -77), Pair(-59, 37), Pair(-18, -23), Pair(0, 0), Pair(-89, -3),
        Pair(36, -18), Pair(51, -50), Pair(8, 17), Pair(-29, 18), Pair(76, -32), Pair(51, -64), Pair(-34, 8), Pair(233, -146),
        Pair(14, -23), Pair(35, -47), Pair(15, -32), Pair(10, -39), Pair(5, -6), Pair(39, -28), Pair(-36, 14), Pair(-7, -29)
      },
      { // Piece 4
        Pair(-21, 60), Pair(-66, -26), Pair(27, 67), Pair(133, -67), Pair(60, -22), Pair(-70, 46), Pair(-4, -92), Pair(68, -64),
        Pair(-8, -13), Pair(12, -23), Pair(-55, 96), Pair(-70, -17), Pair(-71, 66), Pair(-16, 69), Pair(24, -105), Pair(96, -197),
        Pair(-82, -5), Pair(38, -129), Pair(-59, 20), Pair(-35, 65), Pair(41, 54), Pair(94, -107), Pair(11, 18), Pair(68, 25),
        Pair(-67, -15), Pair(-112, -6), Pair(-70, 49), Pair(60, -156), Pair(51, -23), Pair(-52, 69), Pair(19, 58), Pair(34, -111),
        Pair(-32, 8), Pair(-119, 56), Pair(58, -69), Pair(-136, 126), Pair(-56, -1), Pair(-118, 108), Pair(9, 30), Pair(9, -64),
        Pair(6, -43), Pair(-55, -10), Pair(-8, -74), Pair(-12, -141), Pair(-85, -20), Pair(-85, 109), Pair(0, 0), Pair(-98, -112),
        Pair(29, -151), Pair(7, -18), Pair(-27, -54), Pair(-18, -80), Pair(-53, -17), Pair(-215, 1), Pair(-110, 165), Pair(-151, -11),
        Pair(-56, 97), Pair(-95, -115), Pair(-21, -107), Pair(-6, -170), Pair(-12, -60), Pair(7, -30), Pair(80, -182), Pair(-129, -87)
      },
      { // Piece 5
        Pair(-33, -158), Pair(83, -65), Pair(-9, -216), Pair(-11, -85), Pair(-28, -80), Pair(-9, -84), Pair(-88, -145), Pair(-1, -3),
        Pair(4, -139), Pair(-47, -96), Pair(-45, -136), Pair(-94, -40), Pair(7, -25), Pair(22, -22), Pair(58, -70), Pair(44, 81),
        Pair(85, -120), Pair(91, -29), Pair(193, -55), Pair(90, -34), Pair(-8, 13), Pair(79, 12), Pair(77, -39), Pair(-21, -1),
        Pair(103, -52), Pair(212, -74), Pair(5, -26), Pair(15, 16), Pair(124, -25), Pair(144, -13), Pair(108, -3), Pair(113, -84),
        Pair(3, -83), Pair(132, -54), Pair(-127, 0), Pair(167, -32), Pair(207, -23), Pair(139, 41), Pair(-54, 26), Pair(23, 14),
        Pair(-54, -43), Pair(159, -73), Pair(59, -29), Pair(-6, 17), Pair(-16, 13), Pair(-32, 56), Pair(0, 0), Pair(-93, 83),
        Pair(-2, -42), Pair(24, -43), Pair(-32, 2), Pair(-22, 0), Pair(-21, 40), Pair(-27, 69), Pair(-79, 85), Pair(-147, 67),
        Pair(0, -11), Pair(42, -75), Pair(-25, -28), Pair(-25, -69), Pair(-78, 35), Pair(-29, 60), Pair(-70, 73), Pair(-100, 70)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(4, -5), Pair(8, 14), Pair(21, 6), Pair(-49, 19), Pair(75, -5), Pair(-74, 12), Pair(62, 3), Pair(-96, -34),
        Pair(12, -4), Pair(9, -4), Pair(21, -16), Pair(20, -9), Pair(15, 2), Pair(-30, 12), Pair(12, 5), Pair(0, 0),
        Pair(4, -10), Pair(14, -21), Pair(14, -12), Pair(7, -16), Pair(2, -7), Pair(-2, -5), Pair(17, -6), Pair(0, 24),
        Pair(7, -13), Pair(4, -13), Pair(5, -14), Pair(7, -9), Pair(2, -8), Pair(5, -4), Pair(1, -7), Pair(-12, 17),
        Pair(8, -17), Pair(6, -20), Pair(11, -11), Pair(10, -20), Pair(4, -9), Pair(1, -3), Pair(0, -5), Pair(0, 0),
        Pair(5, -15), Pair(4, -15), Pair(6, -20), Pair(12, -21), Pair(5, -17), Pair(-4, -7), Pair(0, -26), Pair(-8, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(116, -103), Pair(-38, -3), Pair(175, -119), Pair(-56, -37), Pair(64, -83), Pair(-17, 15), Pair(-16, -88), Pair(-38, -60),
        Pair(-100, -28), Pair(68, -103), Pair(-71, -13), Pair(129, -137), Pair(24, 11), Pair(204, -93), Pair(137, -81), Pair(66, -45),
        Pair(34, -46), Pair(40, -80), Pair(25, -43), Pair(-5, -12), Pair(112, -54), Pair(67, -38), Pair(99, -68), Pair(-21, -18),
        Pair(56, -60), Pair(23, -36), Pair(34, -53), Pair(51, -40), Pair(79, -33), Pair(61, -33), Pair(29, -12), Pair(-17, 32),
        Pair(30, -31), Pair(-13, -38), Pair(20, -12), Pair(32, -28), Pair(41, -38), Pair(26, -11), Pair(48, -17), Pair(-3, 51),
        Pair(15, -54), Pair(-2, -14), Pair(35, -45), Pair(8, -9), Pair(25, -37), Pair(20, 21), Pair(28, -64), Pair(0, 0),
        Pair(69, -112), Pair(2, -71), Pair(23, -21), Pair(21, -16), Pair(0, -4), Pair(35, -27), Pair(-143, -12), Pair(27, 76),
        Pair(115, -144), Pair(31, -99), Pair(9, 7), Pair(42, -30), Pair(30, -39), Pair(-39, 47), Pair(-37, -28), Pair(-127, 37)
      },
      { // Piece 2
        Pair(35, -5), Pair(-85, 62), Pair(25, 76), Pair(-73, 41), Pair(-213, 43), Pair(97, 40), Pair(-9, 95), Pair(-238, 21),
        Pair(70, 20), Pair(68, -18), Pair(-144, 100), Pair(-58, 22), Pair(-18, 37), Pair(-20, 47), Pair(-28, -10), Pair(-4, 60),
        Pair(-61, -22), Pair(-2, 3), Pair(5, 20), Pair(32, 68), Pair(14, 39), Pair(63, -20), Pair(-8, 43), Pair(51, 3),
        Pair(-13, -17), Pair(17, 10), Pair(-34, 33), Pair(4, 19), Pair(-13, 44), Pair(-91, 87), Pair(23, 3), Pair(-5, 23),
        Pair(-32, 34), Pair(17, -15), Pair(26, 15), Pair(21, -24), Pair(38, 18), Pair(15, 27), Pair(73, -17), Pair(38, 61),
        Pair(-13, -12), Pair(53, -29), Pair(47, -24), Pair(8, 1), Pair(26, -4), Pair(22, 20), Pair(21, 38), Pair(0, 0),
        Pair(53, -8), Pair(15, -23), Pair(2, 30), Pair(26, -26), Pair(21, -18), Pair(-1, -1), Pair(14, 39), Pair(14, 110),
        Pair(35, -35), Pair(-76, -24), Pair(-12, 10), Pair(63, -31), Pair(15, -31), Pair(1, 6), Pair(-67, 80), Pair(29, -22)
      },
      { // Piece 3
        Pair(82, -21), Pair(-61, 26), Pair(27, 10), Pair(-118, 25), Pair(139, -42), Pair(4, -8), Pair(-59, 43), Pair(24, 13),
        Pair(32, -18), Pair(-34, 4), Pair(19, -31), Pair(6, 0), Pair(22, -21), Pair(39, -32), Pair(90, -66), Pair(40, 10),
        Pair(4, -23), Pair(51, -34), Pair(-21, 2), Pair(26, -16), Pair(54, -36), Pair(-7, -19), Pair(40, 16), Pair(22, 22),
        Pair(-1, -14), Pair(67, -49), Pair(55, -25), Pair(37, -21), Pair(45, -17), Pair(68, -18), Pair(-15, -8), Pair(80, 5),
        Pair(37, -35), Pair(58, -29), Pair(12, -14), Pair(6, 7), Pair(-20, -19), Pair(0, 16), Pair(47, -6), Pair(-6, 36),
        Pair(4, -19), Pair(31, -45), Pair(-13, -24), Pair(27, -42), Pair(10, 4), Pair(24, -2), Pair(37, 45), Pair(0, 0),
        Pair(-19, 4), Pair(13, 14), Pair(-17, 19), Pair(-54, 43), Pair(0, 4), Pair(13, 22), Pair(-79, 10), Pair(-61, 66),
        Pair(7, -14), Pair(10, -9), Pair(21, -11), Pair(20, -32), Pair(8, -12), Pair(26, -27), Pair(1, 7), Pair(-25, 25)
      },
      { // Piece 4
        Pair(-120, 115), Pair(-48, 111), Pair(-87, 48), Pair(13, -1), Pair(-8, -4), Pair(125, 62), Pair(-62, -55), Pair(10, -37),
        Pair(34, -82), Pair(-23, -46), Pair(7, -44), Pair(-76, 47), Pair(-62, 37), Pair(-98, 93), Pair(-25, 2), Pair(-40, 33),
        Pair(65, -138), Pair(-14, 46), Pair(-8, 11), Pair(-70, 120), Pair(-152, 144), Pair(-85, 143), Pair(-76, 50), Pair(32, -103),
        Pair(121, -259), Pair(4, -81), Pair(82, -146), Pair(-59, 7), Pair(9, -60), Pair(-32, 40), Pair(-43, 125), Pair(-13, 50),
        Pair(8, -75), Pair(-39, 0), Pair(19, -46), Pair(12, -41), Pair(-7, 12), Pair(-12, -59), Pair(-58, 145), Pair(42, -44),
        Pair(36, -128), Pair(17, -160), Pair(23, -65), Pair(-56, 72), Pair(12, -74), Pair(25, -66), Pair(-34, -79), Pair(0, 0),
        Pair(-8, -15), Pair(-35, -13), Pair(-16, -39), Pair(-28, 22), Pair(-15, -38), Pair(3, -48), Pair(-27, 52), Pair(-125, -15),
        Pair(-7, 45), Pair(-41, 101), Pair(-42, 21), Pair(4, -94), Pair(-22, -25), Pair(-70, 69), Pair(-162, 82), Pair(-167, 52)
      },
      { // Piece 5
        Pair(-42, -174), Pair(19, -149), Pair(52, -91), Pair(17, -132), Pair(-31, -120), Pair(61, -87), Pair(-20, -34), Pair(8, 70),
        Pair(-55, -104), Pair(8, -112), Pair(182, -101), Pair(33, -94), Pair(14, -40), Pair(-81, -12), Pair(67, -52), Pair(41, -116),
        Pair(-21, -93), Pair(207, -86), Pair(-2, -43), Pair(229, -77), Pair(199, -73), Pair(175, -44), Pair(138, -53), Pair(43, -54),
        Pair(3, -62), Pair(73, -62), Pair(94, -62), Pair(45, -13), Pair(72, -8), Pair(53, -4), Pair(87, -19), Pair(93, -28),
        Pair(58, -71), Pair(-88, -28), Pair(101, -79), Pair(63, -30), Pair(-56, 18), Pair(74, -3), Pair(83, 41), Pair(37, -6),
        Pair(-24, -40), Pair(75, -68), Pair(132, -68), Pair(117, -49), Pair(36, 12), Pair(-46, 24), Pair(-85, 77), Pair(0, 0),
        Pair(81, -28), Pair(-19, -25), Pair(30, -42), Pair(6, -16), Pair(-9, 4), Pair(-71, 38), Pair(50, 33), Pair(26, 70),
        Pair(-4, -64), Pair(-47, -8), Pair(-30, -35), Pair(-73, -37), Pair(-54, 4), Pair(-118, 52), Pair(-38, 51), Pair(-19, 55)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(51, 8), Pair(-31, 25), Pair(-21, 8), Pair(2, 8), Pair(19, 8), Pair(37, -3), Pair(-4, 9), Pair(-45, 16),
        Pair(-36, 13), Pair(-8, 9), Pair(9, -3), Pair(3, -1), Pair(-4, 11), Pair(-5, 6), Pair(-11, 11), Pair(-4, 11),
        Pair(0, 0), Pair(-1, -6), Pair(0, -2), Pair(3, -3), Pair(2, 0), Pair(-7, 6), Pair(-3, 3), Pair(-1, 3),
        Pair(0, 0), Pair(2, -6), Pair(3, -4), Pair(0, -5), Pair(-1, -1), Pair(-2, 1), Pair(0, -2), Pair(-5, -1),
        Pair(10, 9), Pair(-4, -2), Pair(2, -2), Pair(3, -5), Pair(-1, -2), Pair(-5, 1), Pair(0, -6), Pair(-4, -4),
        Pair(7, 5), Pair(-9, -8), Pair(1, -3), Pair(4, -5), Pair(-2, -6), Pair(-3, -5), Pair(-1, -7), Pair(-2, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(34, 37), Pair(79, -37), Pair(101, -34), Pair(145, -30), Pair(59, -14), Pair(39, -2), Pair(-38, 106), Pair(82, -64),
        Pair(0, -6), Pair(-19, 13), Pair(50, -11), Pair(45, -6), Pair(100, -38), Pair(56, 6), Pair(29, -39), Pair(7, 0),
        Pair(57, 8), Pair(43, 15), Pair(17, 8), Pair(46, -9), Pair(31, 7), Pair(78, -20), Pair(67, -37), Pair(42, -3),
        Pair(-18, 3), Pair(6, 16), Pair(4, 0), Pair(20, 3), Pair(20, -1), Pair(38, -3), Pair(26, 2), Pair(40, -36),
        Pair(0, 0), Pair(-8, 22), Pair(11, 16), Pair(8, 13), Pair(26, 12), Pair(8, 8), Pair(38, -21), Pair(29, -4),
        Pair(14, 45), Pair(11, -102), Pair(1, 9), Pair(10, 11), Pair(4, 13), Pair(8, 1), Pair(6, -3), Pair(7, 1),
        Pair(14, 13), Pair(-15, -14), Pair(7, 7), Pair(1, -17), Pair(2, 2), Pair(21, -19), Pair(-4, -8), Pair(-2, -18),
        Pair(-126, 39), Pair(-6, -12), Pair(3, -13), Pair(24, 2), Pair(-6, 2), Pair(9, -4), Pair(-1, 10), Pair(38, -118)
      },
      { // Piece 2
        Pair(51, 59), Pair(-32, 12), Pair(-157, 63), Pair(4, 24), Pair(-69, 90), Pair(43, 76), Pair(22, 3), Pair(9, 46),
        Pair(-56, 50), Pair(-14, 44), Pair(1, 40), Pair(-36, 60), Pair(-19, 76), Pair(-50, 66), Pair(62, 35), Pair(39, 18),
        Pair(1, 42), Pair(0, 50), Pair(-3, 60), Pair(-17, 70), Pair(-41, 69), Pair(34, 58), Pair(-29, 39), Pair(14, 23),
        Pair(37, 23), Pair(8, 47), Pair(-23, 63), Pair(5, 43), Pair(7, 39), Pair(-7, 26), Pair(0, 33), Pair(24, 6),
        Pair(0, 0), Pair(-4, 44), Pair(7, 33), Pair(-3, 36), Pair(14, 29), Pair(11, 32), Pair(-5, 29), Pair(12, 16),
        Pair(18, 93), Pair(34, -31), Pair(2, 37), Pair(11, 26), Pair(0, 34), Pair(-3, 16), Pair(-8, 39), Pair(5, 10),
        Pair(7, 67), Pair(-7, 36), Pair(3, 36), Pair(1, 31), Pair(-7, 33), Pair(-4, 32), Pair(2, 12), Pair(-3, 20),
        Pair(12, 5), Pair(1, 20), Pair(-5, 32), Pair(-1, 24), Pair(-32, 44), Pair(-2, 26), Pair(10, 27), Pair(-5, 32)
      },
      { // Piece 3
        Pair(68, 59), Pair(64, 40), Pair(57, 53), Pair(-30, 69), Pair(81, 32), Pair(-123, 118), Pair(31, 52), Pair(-18, 60),
        Pair(63, 73), Pair(22, 60), Pair(14, 65), Pair(5, 61), Pair(4, 59), Pair(48, 43), Pair(100, 38), Pair(-1, 77),
        Pair(14, 85), Pair(6, 60), Pair(28, 54), Pair(12, 62), Pair(55, 39), Pair(57, 39), Pair(-1, 51), Pair(5, 53),
        Pair(-9, 83), Pair(2, 46), Pair(-10, 60), Pair(-3, 66), Pair(13, 43), Pair(20, 40), Pair(-19, 63), Pair(8, 52),
        Pair(0, 0), Pair(13, 50), Pair(5, 62), Pair(17, 38), Pair(-2, 56), Pair(6, 61), Pair(25, 41), Pair(-9, 59),
        Pair(10, 44), Pair(-67, 80), Pair(-4, 55), Pair(9, 44), Pair(3, 40), Pair(4, 41), Pair(17, 55), Pair(8, 46),
        Pair(-41, 46), Pair(9, 39), Pair(-15, 55), Pair(0, 34), Pair(11, 38), Pair(17, 35), Pair(-12, 62), Pair(35, 12),
        Pair(-4, 34), Pair(-8, 41), Pair(-3, 45), Pair(-2, 42), Pair(4, 42), Pair(8, 45), Pair(11, 41), Pair(12, 53)
      },
      { // Piece 4
        Pair(21, 99), Pair(86, 53), Pair(60, 107), Pair(157, -5), Pair(-32, 171), Pair(-3, 139), Pair(-95, 227), Pair(20, 100),
        Pair(71, 70), Pair(8, 117), Pair(10, 102), Pair(-20, 103), Pair(46, 85), Pair(20, 137), Pair(36, 95), Pair(109, 76),
        Pair(44, 59), Pair(61, 70), Pair(11, 132), Pair(26, 46), Pair(45, 41), Pair(28, 71), Pair(54, 77), Pair(32, 99),
        Pair(29, 81), Pair(14, 92), Pair(11, 106), Pair(0, 104), Pair(18, 121), Pair(53, 80), Pair(18, 107), Pair(36, 102),
        Pair(0, 0), Pair(14, 124), Pair(18, 96), Pair(13, 91), Pair(6, 98), Pair(44, 46), Pair(47, 25), Pair(31, 78),
        Pair(9, 53), Pair(25, 162), Pair(13, 82), Pair(11, 75), Pair(14, 70), Pair(8, 86), Pair(24, 52), Pair(17, 100),
        Pair(-4, 47), Pair(16, 85), Pair(14, 65), Pair(9, 89), Pair(9, 98), Pair(8, 67), Pair(33, 20), Pair(-12, 143),
        Pair(9, 50), Pair(14, 53), Pair(11, 52), Pair(10, 69), Pair(14, 69), Pair(-6, 65), Pair(28, 12), Pair(-20, 66)
      },
      { // Piece 5
        Pair(-26, 54), Pair(-33, -53), Pair(21, 23), Pair(43, -97), Pair(28, -88), Pair(-24, -104), Pair(-32, -47), Pair(37, -59),
        Pair(70, 52), Pair(-61, -107), Pair(185, -35), Pair(-179, -27), Pair(-127, -20), Pair(-22, -40), Pair(77, -52), Pair(60, 4),
        Pair(-25, -4), Pair(83, -14), Pair(177, -37), Pair(70, -45), Pair(56, -14), Pair(-7, -18), Pair(-58, -15), Pair(97, -46),
        Pair(113, -6), Pair(-103, 30), Pair(69, -6), Pair(83, -4), Pair(166, -41), Pair(-65, 6), Pair(26, -20), Pair(21, -18),
        Pair(0, 0), Pair(-98, 19), Pair(-63, 14), Pair(-26, 14), Pair(22, -4), Pair(1, -6), Pair(86, -30), Pair(11, -10),
        Pair(19, 11), Pair(-14, 64), Pair(-87, 34), Pair(5, -1), Pair(9, 2), Pair(28, -18), Pair(-20, -6), Pair(25, -16),
        Pair(35, 19), Pair(23, 35), Pair(-44, 20), Pair(-48, 21), Pair(13, -13), Pair(18, -18), Pair(2, -18), Pair(8, -13),
        Pair(15, -1), Pair(38, 3), Pair(-31, 41), Pair(-19, 12), Pair(-9, -20), Pair(-23, -10), Pair(2, -18), Pair(4, -11)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-2, 9), Pair(1, 19), Pair(10, 17), Pair(34, 1), Pair(-1, 11), Pair(20, 7), Pair(31, 11), Pair(-5, 2),
        Pair(2, 3), Pair(-14, 17), Pair(3, 5), Pair(0, 8), Pair(4, 5), Pair(4, 16), Pair(12, 9), Pair(-14, 20),
        Pair(1, 6), Pair(0, 0), Pair(-3, 2), Pair(1, -1), Pair(2, 1), Pair(-2, 2), Pair(1, 3), Pair(-1, 5),
        Pair(8, -1), Pair(0, 0), Pair(0, -3), Pair(1, -3), Pair(-1, 0), Pair(-4, 0), Pair(-5, -3), Pair(-3, 0),
        Pair(3, 1), Pair(8, 10), Pair(1, -2), Pair(4, -4), Pair(-1, -3), Pair(-6, -2), Pair(-8, -3), Pair(-2, 0),
        Pair(5, -10), Pair(11, 5), Pair(-4, -8), Pair(6, -15), Pair(-1, -7), Pair(-5, -5), Pair(-7, -7), Pair(-2, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-86, 39), Pair(148, -58), Pair(-28, -20), Pair(68, -23), Pair(176, -18), Pair(239, -66), Pair(98, 17), Pair(-79, -41),
        Pair(-23, 47), Pair(-56, 50), Pair(92, -17), Pair(53, 5), Pair(109, -25), Pair(5, 4), Pair(35, 0), Pair(73, -10),
        Pair(6, 5), Pair(4, 25), Pair(7, 30), Pair(25, 26), Pair(14, 21), Pair(69, 21), Pair(11, 5), Pair(58, -34),
        Pair(8, 37), Pair(-11, 24), Pair(9, 45), Pair(13, 11), Pair(12, 38), Pair(18, 9), Pair(28, 16), Pair(4, 33),
        Pair(-7, 13), Pair(0, 0), Pair(9, 48), Pair(7, 32), Pair(18, 19), Pair(13, 32), Pair(41, 7), Pair(19, 31),
        Pair(-20, -36), Pair(15, 77), Pair(-9, -16), Pair(8, 32), Pair(8, 22), Pair(11, 28), Pair(8, 12), Pair(3, 9),
        Pair(15, -68), Pair(-14, 37), Pair(3, 4), Pair(8, 29), Pair(-2, 16), Pair(13, -1), Pair(2, 23), Pair(11, 18),
        Pair(-79, 55), Pair(-24, -107), Pair(-20, 48), Pair(-11, 0), Pair(13, 21), Pair(8, -3), Pair(3, 7), Pair(60, 25)
      },
      { // Piece 2
        Pair(3, 17), Pair(-3, 47), Pair(-7, 13), Pair(-68, 61), Pair(-22, 60), Pair(-18, 66), Pair(-62, 86), Pair(-1, 60),
        Pair(-43, 30), Pair(-49, 45), Pair(-26, 63), Pair(-34, 86), Pair(-44, 67), Pair(6, 65), Pair(15, 44), Pair(23, 66),
        Pair(-24, 45), Pair(6, 31), Pair(-28, 56), Pair(-14, 56), Pair(4, 67), Pair(-14, 59), Pair(-3, 58), Pair(15, 28),
        Pair(-7, 0), Pair(-5, 51), Pair(-5, 57), Pair(-22, 59), Pair(11, 50), Pair(7, 43), Pair(10, 30), Pair(11, 30),
        Pair(3, 68), Pair(0, 0), Pair(-12, 55), Pair(-5, 42), Pair(2, 36), Pair(-3, 33), Pair(-13, 19), Pair(9, 2),
        Pair(6, -69), Pair(3, 105), Pair(-16, 25), Pair(5, 41), Pair(-3, 33), Pair(-4, 35), Pair(12, 8), Pair(1, 34),
        Pair(-18, 89), Pair(2, 12), Pair(-2, 55), Pair(-8, 20), Pair(-11, 43), Pair(-2, 25), Pair(4, 23), Pair(0, 31),
        Pair(1, 18), Pair(-30, 86), Pair(-1, 21), Pair(4, 36), Pair(-11, 14), Pair(-7, 21), Pair(-15, 47), Pair(-13, 64)
      },
      { // Piece 3
        Pair(12, 34), Pair(31, 59), Pair(-9, 48), Pair(21, 55), Pair(38, 39), Pair(91, 17), Pair(-10, 57), Pair(10, 60),
        Pair(5, 66), Pair(-46, 84), Pair(1, 56), Pair(-9, 67), Pair(4, 68), Pair(29, 48), Pair(45, 33), Pair(-18, 52),
        Pair(10, 45), Pair(-71, 94), Pair(28, 47), Pair(19, 39), Pair(-6, 64), Pair(34, 26), Pair(-14, 42), Pair(15, 26),
        Pair(11, 36), Pair(29, 46), Pair(12, 39), Pair(-2, 52), Pair(-9, 57), Pair(-2, 39), Pair(12, 46), Pair(38, 12),
        Pair(-1, 26), Pair(0, 0), Pair(-10, 45), Pair(-3, 56), Pair(1, 56), Pair(-5, 53), Pair(-1, 56), Pair(19, 37),
        Pair(17, -29), Pair(-16, 59), Pair(-18, -20), Pair(5, 29), Pair(-18, 52), Pair(17, 29), Pair(13, 10), Pair(21, 19),
        Pair(-15, 30), Pair(-32, 38), Pair(3, 26), Pair(3, 28), Pair(4, 21), Pair(26, 17), Pair(29, 12), Pair(-51, 68),
        Pair(-7, 37), Pair(-8, 18), Pair(-9, 40), Pair(-2, 38), Pair(-2, 42), Pair(-1, 39), Pair(2, 43), Pair(13, 37)
      },
      { // Piece 4
        Pair(181, -84), Pair(-14, 93), Pair(-60, 165), Pair(127, -12), Pair(7, 87), Pair(33, 34), Pair(66, 55), Pair(28, 50),
        Pair(7, 68), Pair(-8, 64), Pair(-10, 117), Pair(51, 35), Pair(24, 119), Pair(17, 112), Pair(-11, 104), Pair(9, 104),
        Pair(16, 42), Pair(27, 45), Pair(-6, 132), Pair(-4, 78), Pair(28, 94), Pair(58, 54), Pair(29, 80), Pair(29, 79),
        Pair(26, 6), Pair(18, 45), Pair(47, -7), Pair(25, 41), Pair(15, 60), Pair(-8, 112), Pair(26, 71), Pair(46, -2),
        Pair(25, 4), Pair(0, 0), Pair(-3, 96), Pair(6, 55), Pair(15, 52), Pair(9, 53), Pair(4, 74), Pair(41, 31),
        Pair(17, -2), Pair(5, 32), Pair(25, 69), Pair(10, 25), Pair(15, 50), Pair(9, 56), Pair(21, 41), Pair(-1, 88),
        Pair(14, 13), Pair(0, 18), Pair(5, 15), Pair(5, 40), Pair(11, 35), Pair(9, 8), Pair(27, 17), Pair(-33, 113),
        Pair(1, 29), Pair(12, 8), Pair(23, 12), Pair(3, 43), Pair(17, -6), Pair(-10, 66), Pair(30, -33), Pair(-21, 122)
      },
      { // Piece 5
        Pair(-41, -191), Pair(-54, -102), Pair(24, -28), Pair(9, 45), Pair(16, 94), Pair(-74, -32), Pair(16, -85), Pair(-35, -134),
        Pair(96, -8), Pair(79, -129), Pair(19, -49), Pair(52, 28), Pair(-108, -19), Pair(5, -15), Pair(-66, 7), Pair(-92, -50),
        Pair(-19, -19), Pair(-21, -15), Pair(248, -47), Pair(134, -26), Pair(-8, 1), Pair(-16, -5), Pair(6, -26), Pair(28, -35),
        Pair(-39, -16), Pair(-14, -14), Pair(-25, 13), Pair(209, -36), Pair(81, -5), Pair(48, -3), Pair(129, -25), Pair(-33, -10),
        Pair(2, 25), Pair(0, 0), Pair(58, -5), Pair(11, 9), Pair(12, -3), Pair(23, 3), Pair(-8, 0), Pair(67, -38),
        Pair(27, 31), Pair(-70, -4), Pair(-31, 5), Pair(21, 8), Pair(-5, 6), Pair(12, -2), Pair(0, -12), Pair(47, -31),
        Pair(-31, 19), Pair(-23, 16), Pair(11, 12), Pair(-17, -3), Pair(-18, 16), Pair(3, -4), Pair(-2, -11), Pair(1, -6),
        Pair(-35, 59), Pair(4, -15), Pair(-2, 11), Pair(13, -17), Pair(-18, 2), Pair(7, -13), Pair(-2, -16), Pair(1, -4)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(18, 0), Pair(-11, 21), Pair(-13, 4), Pair(-31, 17), Pair(-24, 23), Pair(60, -2), Pair(4, 22), Pair(-39, 13),
        Pair(-12, 10), Pair(-5, 4), Pair(21, -8), Pair(-3, 4), Pair(11, 10), Pair(1, 16), Pair(5, 9), Pair(-15, 11),
        Pair(0, 2), Pair(3, -2), Pair(0, 0), Pair(1, -3), Pair(1, 1), Pair(-5, 1), Pair(0, 2), Pair(1, 5),
        Pair(1, 0), Pair(0, -3), Pair(0, 0), Pair(-1, 0), Pair(-5, 3), Pair(-1, 2), Pair(-4, -5), Pair(-5, 1),
        Pair(2, 1), Pair(12, -25), Pair(10, 12), Pair(4, -7), Pair(-6, -1), Pair(-8, -3), Pair(-9, -2), Pair(-6, -4),
        Pair(1, -4), Pair(0, -11), Pair(10, 4), Pair(-10, -9), Pair(2, -10), Pair(-5, -6), Pair(-5, -7), Pair(-3, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-122, 191), Pair(-32, 54), Pair(36, 20), Pair(66, 5), Pair(0, -15), Pair(163, -9), Pair(2, 127), Pair(-115, 81),
        Pair(-8, 4), Pair(-32, 27), Pair(-4, 13), Pair(-12, 48), Pair(-25, 65), Pair(-38, 46), Pair(-5, 24), Pair(126, -48),
        Pair(-54, 41), Pair(20, 8), Pair(3, 31), Pair(7, 29), Pair(-3, 50), Pair(52, 2), Pair(24, 11), Pair(6, 37),
        Pair(-22, 13), Pair(0, 50), Pair(7, 24), Pair(6, 41), Pair(15, 13), Pair(17, 30), Pair(14, 20), Pair(39, 10),
        Pair(-1, 26), Pair(2, 31), Pair(0, 0), Pair(-9, 52), Pair(8, 50), Pair(-2, 34), Pair(50, 4), Pair(16, 15),
        Pair(5, 30), Pair(-16, -49), Pair(12, 87), Pair(-31, -3), Pair(19, 17), Pair(10, 24), Pair(8, 22), Pair(19, -2),
        Pair(14, 32), Pair(15, -13), Pair(9, 44), Pair(0, 10), Pair(15, 40), Pair(-3, 23), Pair(23, -6), Pair(16, -1),
        Pair(-131, -36), Pair(-12, 71), Pair(-69, 50), Pair(4, -10), Pair(-3, -2), Pair(7, 47), Pair(-4, 67), Pair(-7, -77)
      },
      { // Piece 2
        Pair(40, 52), Pair(44, 18), Pair(-8, 21), Pair(115, 22), Pair(-9, 27), Pair(-1, 38), Pair(-113, 79), Pair(188, 77),
        Pair(-12, 40), Pair(22, 24), Pair(-25, 57), Pair(-52, 67), Pair(43, 40), Pair(-12, 39), Pair(-15, 63), Pair(-5, 71),
        Pair(-23, 15), Pair(-15, 34), Pair(-4, 25), Pair(-19, 40), Pair(-44, 73), Pair(13, 57), Pair(-12, 49), Pair(9, 28),
        Pair(-10, 45), Pair(-29, 25), Pair(-23, 64), Pair(13, 29), Pair(-3, 64), Pair(-14, 51), Pair(-2, 50), Pair(4, 25),
        Pair(-17, 36), Pair(5, 53), Pair(0, 0), Pair(-10, 56), Pair(-7, 23), Pair(5, 43), Pair(8, 23), Pair(7, 16),
        Pair(-14, 21), Pair(-70, -46), Pair(10, 88), Pair(-12, 0), Pair(-9, 40), Pair(-1, 15), Pair(13, 7), Pair(9, 8),
        Pair(-55, -25), Pair(-9, 23), Pair(-5, 17), Pair(-5, 31), Pair(-6, -5), Pair(-15, 29), Pair(6, 8), Pair(24, -18),
        Pair(-26, 77), Pair(6, 22), Pair(6, 27), Pair(6, 10), Pair(-12, 46), Pair(-10, 13), Pair(-29, -20), Pair(-45, 72)
      },
      { // Piece 3
        Pair(36, 30), Pair(-1, 34), Pair(33, 38), Pair(-45, 73), Pair(125, -28), Pair(-32, 48), Pair(16, 47), Pair(73, 9),
        Pair(-3, 44), Pair(2, 47), Pair(8, 57), Pair(18, 40), Pair(62, 25), Pair(28, 32), Pair(53, 16), Pair(4, 35),
        Pair(20, 35), Pair(12, 42), Pair(-38, 53), Pair(26, 40), Pair(25, 39), Pair(49, 21), Pair(-18, 53), Pair(-30, 44),
        Pair(5, 40), Pair(17, 33), Pair(-35, 82), Pair(-2, 35), Pair(3, 48), Pair(36, 16), Pair(39, 19), Pair(60, 0),
        Pair(-14, 50), Pair(14, 23), Pair(0, 0), Pair(7, 31), Pair(-4, 42), Pair(2, 34), Pair(34, 14), Pair(35, 22),
        Pair(-24, 35), Pair(52, -15), Pair(-20, 55), Pair(70, -65), Pair(2, 41), Pair(-8, 48), Pair(29, 16), Pair(-14, 46),
        Pair(-24, 43), Pair(2, 29), Pair(-19, 18), Pair(-2, 16), Pair(10, 10), Pair(0, 45), Pair(26, 11), Pair(-17, 38),
        Pair(-6, 40), Pair(-7, 32), Pair(-8, 28), Pair(-2, 27), Pair(5, 29), Pair(10, 25), Pair(21, 27), Pair(11, 41)
      },
      { // Piece 4
        Pair(-3, 44), Pair(-38, 78), Pair(-53, 125), Pair(21, 97), Pair(124, 48), Pair(57, 94), Pair(41, 49), Pair(37, 51),
        Pair(36, 62), Pair(20, 61), Pair(43, 74), Pair(-34, 130), Pair(-14, 143), Pair(35, 71), Pair(26, 90), Pair(12, 57),
        Pair(-5, 71), Pair(12, 59), Pair(9, 64), Pair(9, 67), Pair(32, 88), Pair(40, 59), Pair(-1, 64), Pair(59, -1),
        Pair(9, 61), Pair(-19, 50), Pair(18, 65), Pair(28, 55), Pair(-9, 134), Pair(13, 81), Pair(41, 7), Pair(24, 66),
        Pair(8, 8), Pair(20, 30), Pair(0, 0), Pair(-1, 88), Pair(9, 43), Pair(18, 58), Pair(22, 62), Pair(45, 25),
        Pair(9, 17), Pair(54, -11), Pair(25, 17), Pair(29, -7), Pair(24, 36), Pair(16, 37), Pair(40, -9), Pair(23, 63),
        Pair(-10, 107), Pair(-18, 99), Pair(12, 13), Pair(14, 26), Pair(21, 10), Pair(14, 42), Pair(43, 7), Pair(38, 108),
        Pair(11, 5), Pair(7, 64), Pair(27, 7), Pair(22, 0), Pair(19, 47), Pair(-16, 68), Pair(5, 75), Pair(0, 71)
      },
      { // Piece 5
        Pair(-15, -114), Pair(0, -5), Pair(-70, -58), Pair(1, -92), Pair(-68, -123), Pair(-32, -29), Pair(58, -135), Pair(-47, -46),
        Pair(11, -16), Pair(6, -29), Pair(-142, -21), Pair(-31, -46), Pair(136, 14), Pair(37, -48), Pair(228, -88), Pair(-30, 49),
        Pair(-132, -14), Pair(-32, -12), Pair(5, -24), Pair(117, -44), Pair(58, -31), Pair(170, -41), Pair(-101, 0), Pair(28, -46),
        Pair(-13, -23), Pair(117, 7), Pair(153, -20), Pair(-26, 12), Pair(-19, 3), Pair(179, -26), Pair(3, 3), Pair(-59, -9),
        Pair(-23, 25), Pair(-129, 5), Pair(0, 0), Pair(104, -25), Pair(-72, 28), Pair(53, 3), Pair(57, -14), Pair(-8, 12),
        Pair(-37, 7), Pair(49, 39), Pair(-52, 3), Pair(-112, 110), Pair(-6, 12), Pair(9, 16), Pair(9, -1), Pair(43, -17),
        Pair(-72, 51), Pair(-19, 16), Pair(-23, 14), Pair(-6, 17), Pair(-19, 13), Pair(20, 3), Pair(9, -1), Pair(11, 1),
        Pair(-44, 39), Pair(-27, 9), Pair(-45, 29), Pair(22, 12), Pair(-11, 17), Pair(16, 7), Pair(3, 6), Pair(8, 1)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(20, 15), Pair(11, 2), Pair(-1, 2), Pair(13, 0), Pair(8, 3), Pair(-22, 27), Pair(0, 24), Pair(9, -1),
        Pair(-7, 7), Pair(-5, 10), Pair(-6, 3), Pair(-13, 10), Pair(2, 5), Pair(-3, 6), Pair(0, 5), Pair(-6, 17),
        Pair(-4, 2), Pair(-1, 1), Pair(-3, 3), Pair(0, 0), Pair(2, 1), Pair(1, 5), Pair(7, 1), Pair(5, 4),
        Pair(0, 0), Pair(3, -6), Pair(-2, -2), Pair(0, 0), Pair(-1, -2), Pair(-1, 1), Pair(4, -4), Pair(3, -2),
        Pair(-2, -7), Pair(0, -3), Pair(-1, -28), Pair(11, 12), Pair(0, -30), Pair(-2, -2), Pair(2, -4), Pair(-1, -2),
        Pair(-1, -2), Pair(-1, -2), Pair(-3, -14), Pair(1, 8), Pair(-13, -11), Pair(-3, -1), Pair(2, -3), Pair(3, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(52, -36), Pair(50, -67), Pair(-27, -16), Pair(-90, 52), Pair(-75, 32), Pair(-59, 74), Pair(41, -71), Pair(99, 112),
        Pair(-3, 58), Pair(-21, 61), Pair(23, 14), Pair(-23, 40), Pair(75, -11), Pair(45, 11), Pair(69, 29), Pair(-15, 46),
        Pair(-4, 9), Pair(14, 24), Pair(16, 15), Pair(9, 24), Pair(28, 29), Pair(17, 37), Pair(-5, 13), Pair(30, 28),
        Pair(-7, 34), Pair(-11, -20), Pair(-9, 43), Pair(-15, 33), Pair(5, 40), Pair(3, 10), Pair(13, 27), Pair(28, 29),
        Pair(-13, -8), Pair(-28, 58), Pair(-1, 43), Pair(0, 0), Pair(8, 42), Pair(-9, 41), Pair(2, 21), Pair(8, 39),
        Pair(-8, 1), Pair(-3, 10), Pair(-21, -25), Pair(18, 91), Pair(-39, 13), Pair(3, 17), Pair(5, -2), Pair(0, 53),
        Pair(-16, -46), Pair(-36, 63), Pair(-8, 8), Pair(3, 30), Pair(-4, -2), Pair(-8, 38), Pair(2, -25), Pair(12, 22),
        Pair(41, 18), Pair(-6, -12), Pair(-13, 19), Pair(-44, -32), Pair(-7, 37), Pair(-14, 27), Pair(1, 35), Pair(70, -55)
      },
      { // Piece 2
        Pair(-1, 50), Pair(-121, 30), Pair(42, 23), Pair(-84, 56), Pair(-116, 73), Pair(13, 45), Pair(-88, 123), Pair(-2, 22),
        Pair(-13, 36), Pair(-9, 39), Pair(-9, 37), Pair(4, 51), Pair(-62, 75), Pair(11, 44), Pair(35, 12), Pair(-3, 74),
        Pair(-15, 85), Pair(-19, 47), Pair(-10, 52), Pair(-32, 50), Pair(4, 51), Pair(17, 22), Pair(-6, 59), Pair(11, 1),
        Pair(-8, 28), Pair(0, 60), Pair(-20, 30), Pair(-5, 47), Pair(-24, 28), Pair(20, 30), Pair(-6, 38), Pair(6, 51),
        Pair(-3, 28), Pair(-5, 28), Pair(1, 55), Pair(0, 0), Pair(5, 44), Pair(0, 34), Pair(3, 44), Pair(6, 28),
        Pair(-8, 11), Pair(-4, 48), Pair(-44, -47), Pair(13, 95), Pair(-13, 7), Pair(0, 30), Pair(8, 19), Pair(9, 13),
        Pair(7, 21), Pair(-38, -38), Pair(-29, 59), Pair(-1, 9), Pair(-9, 31), Pair(-31, 7), Pair(1, 19), Pair(14, -8),
        Pair(-59, -92), Pair(11, 42), Pair(-6, 12), Pair(-10, 39), Pair(-17, 9), Pair(-7, 28), Pair(-63, 8), Pair(-10, 49)
      },
      { // Piece 3
        Pair(-26, 58), Pair(-18, 57), Pair(-49, 54), Pair(-46, 50), Pair(29, 12), Pair(30, 27), Pair(47, -1), Pair(-4, 41),
        Pair(17, 29), Pair(-1, 37), Pair(1, 38), Pair(-6, 60), Pair(-15, 46), Pair(25, 45), Pair(-35, 66), Pair(-15, 49),
        Pair(6, 30), Pair(3, 42), Pair(19, 30), Pair(-23, 49), Pair(0, 37), Pair(-13, 47), Pair(29, 34), Pair(37, 21),
        Pair(-13, 28), Pair(-20, 40), Pair(1, 38), Pair(-32, 59), Pair(-5, 43), Pair(-16, 48), Pair(24, 21), Pair(19, 43),
        Pair(-7, 22), Pair(16, 13), Pair(9, 13), Pair(0, 0), Pair(-5, 38), Pair(-28, 54), Pair(-5, 26), Pair(16, 22),
        Pair(-28, 35), Pair(-12, 34), Pair(-9, 26), Pair(-11, 43), Pair(-44, -5), Pair(-11, 20), Pair(12, 13), Pair(1, 30),
        Pair(13, 24), Pair(-8, 28), Pair(5, 17), Pair(-22, 35), Pair(-6, 31), Pair(-4, 32), Pair(14, 21), Pair(14, 22),
        Pair(-2, 23), Pair(-11, 28), Pair(-6, 28), Pair(-15, 15), Pair(-7, 31), Pair(-1, 34), Pair(3, 19), Pair(9, 29)
      },
      { // Piece 4
        Pair(-15, 102), Pair(102, 6), Pair(2, 73), Pair(104, 25), Pair(70, 47), Pair(75, 107), Pair(51, 75), Pair(-13, 111),
        Pair(42, 12), Pair(0, 91), Pair(16, 57), Pair(65, 40), Pair(-1, 92), Pair(-37, 133), Pair(6, 127), Pair(25, 72),
        Pair(1, 73), Pair(23, 53), Pair(25, 53), Pair(-22, 85), Pair(26, 72), Pair(1, 79), Pair(60, 65), Pair(15, 67),
        Pair(7, 78), Pair(22, 74), Pair(16, 43), Pair(31, 50), Pair(26, 30), Pair(4, 104), Pair(19, 97), Pair(21, 63),
        Pair(2, 92), Pair(18, 7), Pair(12, 26), Pair(0, 0), Pair(12, 58), Pair(20, 38), Pair(5, 105), Pair(2, 95),
        Pair(1, 60), Pair(6, 30), Pair(2, 46), Pair(14, 50), Pair(44, -123), Pair(13, 53), Pair(23, 29), Pair(7, 57),
        Pair(6, 65), Pair(9, 16), Pair(-2, 34), Pair(4, 34), Pair(6, 54), Pair(2, 54), Pair(3, 58), Pair(24, -1),
        Pair(3, 52), Pair(5, 51), Pair(-1, 53), Pair(11, 36), Pair(22, 12), Pair(-6, 36), Pair(3, 40), Pair(-5, 83)
      },
      { // Piece 5
        Pair(-34, -110), Pair(-46, 36), Pair(8, -37), Pair(-57, -44), Pair(28, -7), Pair(40, -34), Pair(30, -29), Pair(3, -84),
        Pair(-16, 1), Pair(-46, -45), Pair(100, -51), Pair(-39, -121), Pair(16, 12), Pair(-100, -78), Pair(65, -23), Pair(-84, 3),
        Pair(-65, -60), Pair(51, -51), Pair(70, -9), Pair(72, -52), Pair(-4, -35), Pair(164, -25), Pair(33, -21), Pair(95, -1),
        Pair(-52, -22), Pair(76, -19), Pair(228, -31), Pair(20, -6), Pair(-13, 16), Pair(95, -19), Pair(144, -28), Pair(27, -17),
        Pair(121, -4), Pair(-63, 25), Pair(-46, -17), Pair(0, 0), Pair(55, -35), Pair(30, -6), Pair(78, -15), Pair(-11, 0),
        Pair(-126, 60), Pair(-54, 23), Pair(82, -43), Pair(-68, -3), Pair(88, -32), Pair(-33, 13), Pair(31, -1), Pair(38, -1),
        Pair(1, 20), Pair(-42, 16), Pair(-24, 11), Pair(-33, 11), Pair(-1, 1), Pair(-32, 21), Pair(-5, 16), Pair(10, 2),
        Pair(-76, 62), Pair(-28, 23), Pair(-19, 26), Pair(-3, -9), Pair(-7, 4), Pair(-25, 20), Pair(1, 10), Pair(-1, 8)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(18, 2), Pair(5, 11), Pair(-1, 6), Pair(-40, 20), Pair(-28, 13), Pair(-42, 21), Pair(2, 10), Pair(30, 7),
        Pair(-1, 4), Pair(6, -1), Pair(4, 2), Pair(-3, 7), Pair(6, -1), Pair(-9, 13), Pair(4, -3), Pair(-1, 6),
        Pair(0, -1), Pair(0, -1), Pair(-2, -2), Pair(-1, 1), Pair(0, 0), Pair(-7, 5), Pair(-3, 5), Pair(2, 4),
        Pair(2, -3), Pair(1, -8), Pair(2, -8), Pair(-2, -5), Pair(0, 0), Pair(1, 0), Pair(4, -1), Pair(3, 1),
        Pair(-2, -7), Pair(-1, -5), Pair(1, -6), Pair(7, -17), Pair(8, 6), Pair(-3, -19), Pair(-2, -1), Pair(4, 0),
        Pair(1, -5), Pair(-3, -6), Pair(2, -7), Pair(-2, -14), Pair(11, -6), Pair(-6, -12), Pair(1, 3), Pair(6, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-40, -11), Pair(-124, 64), Pair(-75, 72), Pair(27, 0), Pair(-15, 67), Pair(87, -4), Pair(-39, 84), Pair(-92, -99),
        Pair(-21, 59), Pair(-12, 42), Pair(8, 35), Pair(-29, 31), Pair(29, 3), Pair(-39, 56), Pair(-27, 43), Pair(-81, 42),
        Pair(4, 18), Pair(7, 16), Pair(-1, 30), Pair(8, 8), Pair(-10, 51), Pair(14, 5), Pair(5, 11), Pair(-33, 54),
        Pair(10, 23), Pair(-4, 24), Pair(4, 3), Pair(-6, 47), Pair(-8, 42), Pair(-12, 56), Pair(-14, 13), Pair(0, 15),
        Pair(6, 25), Pair(-14, 15), Pair(-2, 37), Pair(3, 46), Pair(0, 0), Pair(-5, 48), Pair(10, 49), Pair(-18, 13),
        Pair(6, 26), Pair(-8, 29), Pair(3, 19), Pair(-13, -42), Pair(12, 83), Pair(-27, -22), Pair(-5, 27), Pair(-2, 33),
        Pair(-1, 42), Pair(-32, 44), Pair(-5, 34), Pair(-9, 4), Pair(2, 35), Pair(-3, -9), Pair(7, 19), Pair(-18, -11),
        Pair(56, -12), Pair(1, 28), Pair(24, -29), Pair(-16, 26), Pair(-26, -16), Pair(-8, 39), Pair(-13, 2), Pair(-58, -39)
      },
      { // Piece 2
        Pair(-100, 73), Pair(38, 33), Pair(-111, 73), Pair(-40, 64), Pair(1, 35), Pair(-83, 66), Pair(41, 47), Pair(-74, 71),
        Pair(-9, 33), Pair(-44, 44), Pair(16, 25), Pair(-33, 46), Pair(-47, 60), Pair(-38, 63), Pair(2, 46), Pair(12, 28),
        Pair(-4, 33), Pair(-21, 51), Pair(-25, 41), Pair(-9, 37), Pair(-23, 26), Pair(11, 33), Pair(-58, 39), Pair(-1, 51),
        Pair(3, 39), Pair(-12, 35), Pair(0, 43), Pair(-26, 36), Pair(11, 29), Pair(-19, 31), Pair(2, 50), Pair(-4, 27),
        Pair(-22, 36), Pair(10, 22), Pair(-12, 42), Pair(2, 33), Pair(0, 0), Pair(10, 54), Pair(-8, 26), Pair(-8, 45),
        Pair(1, 23), Pair(-2, 16), Pair(6, 18), Pair(-5, -99), Pair(8, 85), Pair(-61, -13), Pair(12, 31), Pair(-22, 41),
        Pair(-26, 50), Pair(0, 23), Pair(-21, 14), Pair(-4, 18), Pair(-2, 15), Pair(-23, 44), Pair(-36, -17), Pair(15, 25),
        Pair(-23, 50), Pair(-16, -14), Pair(-5, 25), Pair(-1, 24), Pair(-1, 38), Pair(-9, 21), Pair(-69, 81), Pair(-24, -80)
      },
      { // Piece 3
        Pair(-5, 34), Pair(13, 24), Pair(-23, 45), Pair(72, 11), Pair(-16, 46), Pair(68, 6), Pair(-2, 44), Pair(10, 28),
        Pair(-1, 28), Pair(-6, 36), Pair(9, 22), Pair(37, 14), Pair(-14, 51), Pair(13, 23), Pair(25, 24), Pair(54, 16),
        Pair(1, 32), Pair(-13, 35), Pair(7, 35), Pair(5, 32), Pair(-7, 42), Pair(21, 18), Pair(21, 35), Pair(10, 24),
        Pair(8, 19), Pair(-1, 21), Pair(4, 27), Pair(-1, 37), Pair(16, 20), Pair(28, 8), Pair(-4, 25), Pair(23, 16),
        Pair(2, 20), Pair(-5, 17), Pair(-7, 30), Pair(-17, 32), Pair(0, 0), Pair(7, 17), Pair(-2, 34), Pair(4, 24),
        Pair(4, 16), Pair(-9, 22), Pair(-10, 12), Pair(-27, 15), Pair(7, 36), Pair(-23, -15), Pair(11, 16), Pair(-2, 16),
        Pair(-17, 39), Pair(24, -1), Pair(-3, 21), Pair(0, 5), Pair(-17, 13), Pair(18, 11), Pair(22, 1), Pair(4, -1),
        Pair(4, 21), Pair(-3, 24), Pair(-6, 33), Pair(-5, 18), Pair(-9, 14), Pair(1, 22), Pair(12, 13), Pair(3, 20)
      },
      { // Piece 4
        Pair(-30, 65), Pair(-2, 62), Pair(11, 62), Pair(13, 79), Pair(13, 45), Pair(-51, 109), Pair(10, 60), Pair(69, 21),
        Pair(20, 22), Pair(9, 36), Pair(21, 29), Pair(-4, 86), Pair(-2, 78), Pair(-2, 70), Pair(32, 34), Pair(-8, 27),
        Pair(7, 69), Pair(2, 60), Pair(12, 7), Pair(11, 51), Pair(7, 53), Pair(27, 67), Pair(18, 9), Pair(19, 85),
        Pair(22, 18), Pair(-2, 48), Pair(-2, 57), Pair(0, 22), Pair(-2, 57), Pair(6, 44), Pair(8, 52), Pair(-2, 86),
        Pair(-1, 59), Pair(1, 72), Pair(-3, 24), Pair(14, 33), Pair(0, 0), Pair(8, 47), Pair(3, 91), Pair(20, 33),
        Pair(-2, 31), Pair(0, 44), Pair(-1, 54), Pair(39, -68), Pair(2, 63), Pair(-2, -14), Pair(-6, 82), Pair(-16, 103),
        Pair(7, 31), Pair(3, 51), Pair(2, 28), Pair(-4, 26), Pair(3, 31), Pair(-9, 78), Pair(2, 41), Pair(17, 72),
        Pair(-7, 29), Pair(3, 27), Pair(2, 38), Pair(4, 11), Pair(5, 39), Pair(-4, 22), Pair(14, 3), Pair(26, -17)
      },
      { // Piece 5
        Pair(-90, -105), Pair(-21, -74), Pair(157, -106), Pair(-44, -9), Pair(-14, -105), Pair(54, -79), Pair(-56, 38), Pair(8, -53),
        Pair(-75, -10), Pair(65, -57), Pair(-53, -56), Pair(48, -68), Pair(113, -58), Pair(25, -28), Pair(43, -48), Pair(-49, 6),
        Pair(-27, 8), Pair(59, -31), Pair(17, -3), Pair(98, -60), Pair(154, -65), Pair(152, -29), Pair(146, -46), Pair(-177, 17),
        Pair(23, -16), Pair(36, 5), Pair(194, -56), Pair(-116, 14), Pair(73, -25), Pair(3, 16), Pair(10, 1), Pair(112, -15),
        Pair(28, 16), Pair(79, 0), Pair(-11, 3), Pair(51, -49), Pair(0, 0), Pair(112, -45), Pair(50, -2), Pair(47, 7),
        Pair(28, 6), Pair(87, -9), Pair(9, 11), Pair(-159, 1), Pair(-44, -4), Pair(24, 0), Pair(5, 14), Pair(-7, 23),
        Pair(-2, 13), Pair(36, -2), Pair(10, 10), Pair(50, -3), Pair(4, 9), Pair(24, -7), Pair(-18, 25), Pair(0, 23),
        Pair(33, -27), Pair(7, 7), Pair(9, 21), Pair(7, 16), Pair(-8, 8), Pair(-6, 10), Pair(-7, 24), Pair(-1, 21)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 11), Pair(26, -6), Pair(36, 6), Pair(4, 0), Pair(46, -5), Pair(-26, 49), Pair(-8, 4), Pair(18, 1),
        Pair(10, -1), Pair(7, 1), Pair(10, -1), Pair(-1, 6), Pair(-14, 18), Pair(-6, 3), Pair(3, 2), Pair(2, 4),
        Pair(8, -5), Pair(1, -3), Pair(7, -2), Pair(-1, -6), Pair(7, -5), Pair(0, 0), Pair(9, -6), Pair(7, 1),
        Pair(7, -8), Pair(3, -4), Pair(1, -6), Pair(-1, -2), Pair(3, -1), Pair(0, 0), Pair(6, -7), Pair(2, -3),
        Pair(5, -12), Pair(1, -7), Pair(1, -7), Pair(2, -2), Pair(-5, 5), Pair(16, 3), Pair(-6, -19), Pair(6, 0),
        Pair(4, -12), Pair(3, -9), Pair(-2, -5), Pair(11, -11), Pair(-4, -9), Pair(9, -2), Pair(-1, -13), Pair(6, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-33, -57), Pair(21, -35), Pair(-31, 24), Pair(-35, -22), Pair(59, -9), Pair(-96, 22), Pair(113, -90), Pair(-86, 97),
        Pair(-17, 29), Pair(1, -2), Pair(91, -24), Pair(-20, 48), Pair(-14, 23), Pair(-44, 33), Pair(-7, 57), Pair(-57, 3),
        Pair(-26, 4), Pair(15, 7), Pair(38, 11), Pair(32, 7), Pair(28, 2), Pair(64, 13), Pair(-14, 20), Pair(5, 31),
        Pair(-33, 18), Pair(17, 3), Pair(-2, 2), Pair(10, -9), Pair(31, 27), Pair(19, 14), Pair(31, 4), Pair(-39, -59),
        Pair(2, 0), Pair(24, 1), Pair(-6, 9), Pair(11, 22), Pair(14, 25), Pair(0, 0), Pair(6, 11), Pair(12, 17),
        Pair(1, -29), Pair(-10, 10), Pair(8, -1), Pair(23, -2), Pair(-19, -29), Pair(24, 53), Pair(-18, -32), Pair(12, 15),
        Pair(-55, 22), Pair(-8, 22), Pair(-7, 16), Pair(7, 10), Pair(-4, -15), Pair(30, 11), Pair(-4, -8), Pair(0, 13),
        Pair(-38, -49), Pair(-16, 4), Pair(-24, 7), Pair(-2, -7), Pair(8, 10), Pair(-25, -31), Pair(19, 42), Pair(-40, 15)
      },
      { // Piece 2
        Pair(-13, 35), Pair(68, -21), Pair(-80, 60), Pair(54, 16), Pair(-192, 64), Pair(-26, 18), Pair(0, 7), Pair(144, 7),
        Pair(-57, 29), Pair(-23, 42), Pair(-16, 12), Pair(-3, 19), Pair(-9, 15), Pair(-60, 20), Pair(76, 8), Pair(-54, 69),
        Pair(-22, 23), Pair(-42, 27), Pair(-5, 38), Pair(-50, 39), Pair(-9, 21), Pair(-33, 44), Pair(7, 19), Pair(-11, -4),
        Pair(-17, 27), Pair(2, 21), Pair(-14, 31), Pair(5, 35), Pair(-9, 12), Pair(-20, 37), Pair(7, 10), Pair(-1, 48),
        Pair(1, 1), Pair(-10, 25), Pair(3, 24), Pair(-10, 16), Pair(13, 25), Pair(0, 0), Pair(1, 36), Pair(-15, -1),
        Pair(-3, 1), Pair(-9, 26), Pair(-9, 14), Pair(7, 17), Pair(-36, 10), Pair(16, 77), Pair(-19, -108), Pair(7, 19),
        Pair(0, 14), Pair(-3, 2), Pair(-5, 21), Pair(-17, -14), Pair(2, 23), Pair(-3, 3), Pair(5, 12), Pair(-61, -87),
        Pair(-24, 32), Pair(-38, 44), Pair(-31, -12), Pair(11, 31), Pair(-14, 15), Pair(5, 10), Pair(-12, 11), Pair(-42, 77)
      },
      { // Piece 3
        Pair(29, 10), Pair(-24, 34), Pair(58, 10), Pair(-10, 40), Pair(-16, 26), Pair(-5, 27), Pair(-62, 42), Pair(-22, 45),
        Pair(-13, 13), Pair(-18, 9), Pair(39, -2), Pair(2, 15), Pair(8, 32), Pair(-9, 27), Pair(103, -10), Pair(-24, 31),
        Pair(1, 12), Pair(25, -4), Pair(29, -6), Pair(46, -2), Pair(43, 3), Pair(-26, 23), Pair(6, 22), Pair(-16, 10),
        Pair(19, 13), Pair(-9, 10), Pair(3, 25), Pair(-4, 16), Pair(26, 1), Pair(49, 30), Pair(-37, 17), Pair(16, 8),
        Pair(-23, 13), Pair(-3, 3), Pair(13, -12), Pair(-3, -14), Pair(36, -3), Pair(0, 0), Pair(10, -37), Pair(26, 20),
        Pair(11, 7), Pair(24, -8), Pair(-31, 18), Pair(12, -1), Pair(35, -61), Pair(-15, 30), Pair(50, -35), Pair(-30, 39),
        Pair(6, -8), Pair(13, 15), Pair(-6, 11), Pair(15, 1), Pair(1, 6), Pair(-11, -5), Pair(27, 29), Pair(70, -38),
        Pair(1, 14), Pair(-3, 16), Pair(4, 6), Pair(-1, 20), Pair(1, 8), Pair(-5, -2), Pair(6, -3), Pair(0, 9)
      },
      { // Piece 4
        Pair(16, -15), Pair(-42, 63), Pair(58, 79), Pair(-78, 122), Pair(147, -96), Pair(-57, 95), Pair(-68, 129), Pair(33, 12),
        Pair(5, 27), Pair(-21, 69), Pair(25, 6), Pair(-17, 63), Pair(-7, 38), Pair(2, 14), Pair(-36, 92), Pair(-36, 74),
        Pair(5, -4), Pair(31, 14), Pair(-3, -10), Pair(14, 16), Pair(-28, 83), Pair(-54, 85), Pair(19, 25), Pair(-8, -11),
        Pair(10, 6), Pair(23, 28), Pair(-21, 76), Pair(13, 26), Pair(6, 37), Pair(-14, 60), Pair(-1, 20), Pair(-1, 20),
        Pair(2, 16), Pair(34, -23), Pair(-9, 48), Pair(6, 4), Pair(5, 65), Pair(0, 0), Pair(14, -13), Pair(-3, -9),
        Pair(-8, 62), Pair(-20, 64), Pair(8, 3), Pair(-8, 27), Pair(-4, 33), Pair(-3, 42), Pair(36, -156), Pair(-2, 21),
        Pair(22, -7), Pair(-15, 45), Pair(-5, 42), Pair(-9, 24), Pair(-17, 44), Pair(0, 5), Pair(3, 31), Pair(-30, 5),
        Pair(-22, 12), Pair(-11, 25), Pair(-1, -20), Pair(-4, 20), Pair(-10, 20), Pair(-26, 15), Pair(87, -174), Pair(-46, 54)
      },
      { // Piece 5
        Pair(-26, -55), Pair(95, -51), Pair(-98, -90), Pair(29, -57), Pair(15, -70), Pair(-78, -21), Pair(-48, 26), Pair(58, 1),
        Pair(-84, -79), Pair(87, -64), Pair(62, -71), Pair(55, -96), Pair(-19, -55), Pair(125, -50), Pair(-2, -33), Pair(33, -22),
        Pair(-37, -14), Pair(-40, -28), Pair(80, -23), Pair(-1, -30), Pair(31, -17), Pair(237, -61), Pair(149, -41), Pair(37, -12),
        Pair(-179, -10), Pair(-74, -5), Pair(62, -20), Pair(49, -5), Pair(-41, 18), Pair(74, -5), Pair(23, 28), Pair(-84, 45),
        Pair(65, -20), Pair(63, -11), Pair(101, -7), Pair(21, -6), Pair(60, -27), Pair(0, 0), Pair(29, -8), Pair(-101, 34),
        Pair(8, -15), Pair(36, -7), Pair(45, 6), Pair(16, 9), Pair(107, 14), Pair(-34, -7), Pair(-18, 21), Pair(-4, 27),
        Pair(47, -22), Pair(29, -7), Pair(28, -5), Pair(-22, 8), Pair(31, 5), Pair(-1, 14), Pair(7, 15), Pair(-24, 26),
        Pair(5, 9), Pair(20, -19), Pair(-1, 17), Pair(34, 13), Pair(-10, 14), Pair(-42, 24), Pair(-13, 21), Pair(-17, 35)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, 3), Pair(14, 5), Pair(27, 3), Pair(39, 10), Pair(43, -4), Pair(43, 9), Pair(-73, 38), Pair(-3, 24),
        Pair(11, -2), Pair(0, -4), Pair(20, -9), Pair(-13, 9), Pair(-5, 0), Pair(-20, 6), Pair(-1, 14), Pair(-16, 5),
        Pair(2, -3), Pair(-1, -4), Pair(0, -3), Pair(-8, -2), Pair(2, -5), Pair(-8, 6), Pair(0, 0), Pair(4, 4),
        Pair(5, -5), Pair(-1, -6), Pair(1, -7), Pair(-4, -2), Pair(-1, -3), Pair(-7, 1), Pair(0, 0), Pair(12, 1),
        Pair(4, -8), Pair(3, -9), Pair(-3, -6), Pair(-5, -1), Pair(-1, -5), Pair(-3, -1), Pair(4, 3), Pair(3, 2),
        Pair(1, -8), Pair(1, -7), Pair(-2, -6), Pair(-6, 0), Pair(-7, -3), Pair(-4, -6), Pair(-4, 2), Pair(0, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(49, -108), Pair(-76, 11), Pair(-161, 29), Pair(114, -71), Pair(-54, 36), Pair(-107, -8), Pair(106, 85), Pair(97, -172),
        Pair(60, -22), Pair(34, 4), Pair(41, -4), Pair(-56, 29), Pair(100, 7), Pair(43, -3), Pair(3, 28), Pair(11, -8),
        Pair(-4, -3), Pair(27, -2), Pair(-17, 10), Pair(22, 11), Pair(35, 23), Pair(-33, 23), Pair(27, 38), Pair(-10, 35),
        Pair(-10, 0), Pair(-8, 16), Pair(14, 21), Pair(33, 1), Pair(29, 18), Pair(14, 23), Pair(-7, 20), Pair(13, 0),
        Pair(-2, 6), Pair(0, 24), Pair(8, 7), Pair(32, 10), Pair(22, 19), Pair(17, 15), Pair(0, 0), Pair(-5, 13),
        Pair(-16, 47), Pair(-3, 25), Pair(4, 27), Pair(12, 5), Pair(26, 9), Pair(-21, -14), Pair(18, 57), Pair(-7, -30),
        Pair(-18, 47), Pair(-29, 32), Pair(10, 0), Pair(0, 12), Pair(3, 11), Pair(-13, 10), Pair(17, 13), Pair(-10, -18),
        Pair(-169, 99), Pair(-8, -37), Pair(-23, 6), Pair(-12, 25), Pair(1, 0), Pair(21, 0), Pair(-29, -43), Pair(-9, 6)
      },
      { // Piece 2
        Pair(-41, 4), Pair(-60, 65), Pair(-278, 76), Pair(-196, 55), Pair(-58, 38), Pair(20, 20), Pair(31, 8), Pair(8, 34),
        Pair(-35, 34), Pair(-54, 45), Pair(-13, 29), Pair(-22, 55), Pair(16, 29), Pair(-18, 34), Pair(22, 29), Pair(-28, 72),
        Pair(-34, 49), Pair(19, 18), Pair(-27, 49), Pair(-9, 30), Pair(12, 30), Pair(6, 22), Pair(-28, 31), Pair(2, 15),
        Pair(14, 7), Pair(8, 20), Pair(-7, 25), Pair(-5, 43), Pair(6, 15), Pair(-7, 31), Pair(13, 21), Pair(-98, 35),
        Pair(-18, 41), Pair(-1, 20), Pair(-8, 13), Pair(14, 14), Pair(13, 14), Pair(11, 18), Pair(0, 0), Pair(-6, 40),
        Pair(-1, 7), Pair(35, 3), Pair(10, 20), Pair(6, 15), Pair(5, 21), Pair(9, -41), Pair(21, 64), Pair(-57, -17),
        Pair(-33, 19), Pair(6, 2), Pair(13, 3), Pair(4, 12), Pair(-17, 17), Pair(-23, 39), Pair(17, -4), Pair(17, -54),
        Pair(0, 22), Pair(35, 2), Pair(5, -3), Pair(-43, 20), Pair(17, -1), Pair(3, 12), Pair(-10, 8), Pair(-52, 29)
      },
      { // Piece 3
        Pair(29, 10), Pair(32, 20), Pair(-19, 31), Pair(87, 0), Pair(10, 21), Pair(11, 27), Pair(-53, 45), Pair(-108, 51),
        Pair(-13, 15), Pair(15, 4), Pair(4, 18), Pair(-17, 16), Pair(-20, 11), Pair(1, 3), Pair(-68, 33), Pair(12, 1),
        Pair(31, 8), Pair(-7, 7), Pair(-32, 21), Pair(-10, 19), Pair(-36, 19), Pair(49, 1), Pair(27, 7), Pair(30, -3),
        Pair(19, -7), Pair(-22, 20), Pair(-7, 15), Pair(70, -3), Pair(38, -5), Pair(8, 5), Pair(37, 21), Pair(-27, 5),
        Pair(5, 17), Pair(-12, 9), Pair(17, 12), Pair(20, -5), Pair(21, 5), Pair(24, 25), Pair(0, 0), Pair(-2, 1),
        Pair(-4, -8), Pair(-7, 11), Pair(5, 5), Pair(6, 3), Pair(-9, 19), Pair(14, -117), Pair(6, -2), Pair(18, -2),
        Pair(30, -14), Pair(9, -5), Pair(16, -5), Pair(-7, 3), Pair(7, -5), Pair(9, 4), Pair(-6, -12), Pair(10, -30),
        Pair(11, 7), Pair(-6, 20), Pair(2, 19), Pair(8, 5), Pair(-3, 10), Pair(3, 12), Pair(-2, -4), Pair(-6, -10)
      },
      { // Piece 4
        Pair(-28, 21), Pair(70, -45), Pair(81, -70), Pair(71, 3), Pair(68, 9), Pair(252, -162), Pair(-103, -5), Pair(-80, 79),
        Pair(11, -18), Pair(12, 15), Pair(-5, 29), Pair(43, -42), Pair(-42, -6), Pair(-3, -1), Pair(63, -70), Pair(-97, 94),
        Pair(19, -27), Pair(-8, 20), Pair(-2, 24), Pair(7, 48), Pair(-1, 7), Pair(7, 59), Pair(-30, 30), Pair(33, -33),
        Pair(-3, -4), Pair(-3, 16), Pair(9, 32), Pair(4, 11), Pair(-7, 21), Pair(64, -17), Pair(-23, 71), Pair(-5, -71),
        Pair(7, -35), Pair(24, -35), Pair(-12, 37), Pair(-27, 74), Pair(13, 14), Pair(6, 40), Pair(0, 0), Pair(-67, 106),
        Pair(-6, -2), Pair(-5, 24), Pair(8, -15), Pair(16, -45), Pair(2, -5), Pair(-32, -3), Pair(-1, 25), Pair(-9, -25),
        Pair(-12, 7), Pair(-12, -5), Pair(0, 6), Pair(5, -11), Pair(-10, 13), Pair(0, -29), Pair(-12, 39), Pair(-61, 109),
        Pair(5, 10), Pair(9, -23), Pair(16, -26), Pair(7, -44), Pair(-13, -9), Pair(-14, -9), Pair(-98, 41), Pair(3, -2)
      },
      { // Piece 5
        Pair(17, -78), Pair(-13, -17), Pair(-32, -87), Pair(54, 10), Pair(112, 27), Pair(-19, 1), Pair(-55, -43), Pair(-30, -300),
        Pair(-89, -59), Pair(27, -62), Pair(175, -85), Pair(55, -107), Pair(-11, -64), Pair(110, -24), Pair(98, -80), Pair(-9, -13),
        Pair(264, -55), Pair(-29, -31), Pair(-97, -5), Pair(-4, -7), Pair(75, -9), Pair(175, -29), Pair(84, -25), Pair(208, -10),
        Pair(-28, -2), Pair(93, -30), Pair(42, -30), Pair(25, -7), Pair(-70, 11), Pair(197, -20), Pair(31, 6), Pair(-35, 13),
        Pair(-107, -19), Pair(142, -36), Pair(54, -23), Pair(46, -8), Pair(32, 2), Pair(57, -18), Pair(0, 0), Pair(-80, 5),
        Pair(66, -31), Pair(16, -17), Pair(21, -15), Pair(44, 2), Pair(-19, 11), Pair(166, -52), Pair(3, -22), Pair(14, 21),
        Pair(-33, 6), Pair(-7, -20), Pair(13, -7), Pair(-18, 13), Pair(-15, 11), Pair(39, 0), Pair(-11, 11), Pair(-2, 10),
        Pair(-24, 2), Pair(0, -22), Pair(-16, -15), Pair(18, -12), Pair(-29, 16), Pair(22, 6), Pair(-6, 6), Pair(-9, 10)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, 8), Pair(17, -4), Pair(65, -13), Pair(4, 0), Pair(39, 6), Pair(-43, 9), Pair(-68, 7), Pair(92, -34),
        Pair(19, -11), Pair(-7, -4), Pair(4, -4), Pair(-11, 3), Pair(15, -5), Pair(-21, 5), Pair(-10, 10), Pair(0, -24),
        Pair(0, -3), Pair(1, -5), Pair(-2, -6), Pair(-6, -2), Pair(-2, -3), Pair(-6, -1), Pair(-5, -4), Pair(0, 0),
        Pair(2, -5), Pair(2, -8), Pair(-3, -5), Pair(-1, -8), Pair(-3, -6), Pair(0, -2), Pair(2, -10), Pair(0, 0),
        Pair(0, -8), Pair(2, -6), Pair(0, -9), Pair(-2, -4), Pair(1, -7), Pair(-2, 0), Pair(-18, -10), Pair(4, 7),
        Pair(-1, -6), Pair(1, -8), Pair(-3, -8), Pair(-3, -5), Pair(-2, -4), Pair(-1, -3), Pair(-10, -10), Pair(-8, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-23, -10), Pair(150, -50), Pair(-13, -26), Pair(-53, -32), Pair(-44, -13), Pair(-135, 12), Pair(67, -8), Pair(100, -95),
        Pair(-23, -24), Pair(-23, -22), Pair(8, -4), Pair(97, -15), Pair(6, -3), Pair(-60, 6), Pair(15, 11), Pair(33, 24),
        Pair(36, -58), Pair(40, -9), Pair(3, -12), Pair(45, -10), Pair(44, -12), Pair(23, 14), Pair(56, -14), Pair(-28, 53),
        Pair(50, -44), Pair(16, -12), Pair(18, -1), Pair(31, -20), Pair(49, -11), Pair(43, -11), Pair(20, -7), Pair(23, 16),
        Pair(23, -28), Pair(-2, -22), Pair(12, -2), Pair(37, 2), Pair(21, -1), Pair(29, 11), Pair(51, -29), Pair(0, 0),
        Pair(-3, -26), Pair(9, -29), Pair(15, -4), Pair(33, -11), Pair(15, -7), Pair(29, -13), Pair(-3, -38), Pair(24, 72),
        Pair(-26, -17), Pair(9, -15), Pair(16, -14), Pair(14, -5), Pair(14, -2), Pair(0, 6), Pair(-18, 7), Pair(34, -32),
        Pair(71, 40), Pair(-23, -2), Pair(18, -43), Pair(15, -27), Pair(36, -2), Pair(-14, 4), Pair(-5, -9), Pair(-5, -62)
      },
      { // Piece 2
        Pair(46, 16), Pair(-145, 37), Pair(-156, 59), Pair(122, 13), Pair(-278, 64), Pair(-7, 13), Pair(-170, 28), Pair(-12, -2),
        Pair(-2, 17), Pair(-19, 30), Pair(1, 43), Pair(-80, 68), Pair(-32, 62), Pair(-62, 38), Pair(-17, 25), Pair(32, 30),
        Pair(-55, 54), Pair(-19, 44), Pair(-20, 39), Pair(0, 29), Pair(34, 40), Pair(-9, 60), Pair(-26, 21), Pair(9, 30),
        Pair(-8, 9), Pair(-5, 10), Pair(-1, 25), Pair(4, 18), Pair(34, 29), Pair(-11, 30), Pair(41, -3), Pair(13, 24),
        Pair(-41, 16), Pair(-8, 3), Pair(6, 11), Pair(-9, 24), Pair(16, 11), Pair(9, 33), Pair(16, 17), Pair(0, 0),
        Pair(3, 15), Pair(14, 17), Pair(5, 22), Pair(5, 15), Pair(15, 7), Pair(2, 29), Pair(27, 26), Pair(21, 73),
        Pair(-20, 18), Pair(11, 17), Pair(8, -12), Pair(-2, 23), Pair(13, 12), Pair(8, 8), Pair(16, 10), Pair(20, -17),
        Pair(-1, -6), Pair(28, -6), Pair(-5, 12), Pair(-8, 22), Pair(-7, 15), Pair(10, 6), Pair(32, -8), Pair(24, 20)
      },
      { // Piece 3
        Pair(18, 6), Pair(-46, 28), Pair(-12, 17), Pair(7, 9), Pair(-93, 39), Pair(16, 15), Pair(-15, 25), Pair(75, 17),
        Pair(22, -5), Pair(2, 8), Pair(37, 3), Pair(-28, 20), Pair(9, 5), Pair(-13, 13), Pair(62, -13), Pair(3, 20),
        Pair(2, 14), Pair(28, -4), Pair(11, 8), Pair(12, 7), Pair(42, -5), Pair(-29, 28), Pair(10, 23), Pair(150, 0),
        Pair(2, 15), Pair(14, -5), Pair(40, -1), Pair(39, -21), Pair(27, 10), Pair(21, 10), Pair(25, 1), Pair(79, 20),
        Pair(5, 15), Pair(47, -7), Pair(21, 4), Pair(-11, 17), Pair(15, 12), Pair(22, 22), Pair(22, 12), Pair(0, 0),
        Pair(-10, 25), Pair(4, 15), Pair(36, 2), Pair(10, -4), Pair(28, -16), Pair(-2, 25), Pair(52, -95), Pair(-26, 39),
        Pair(21, -3), Pair(25, -2), Pair(7, -5), Pair(1, 6), Pair(-16, 25), Pair(11, 8), Pair(12, 12), Pair(-46, 4),
        Pair(8, 13), Pair(10, 16), Pair(11, 14), Pair(5, 11), Pair(11, 8), Pair(14, 14), Pair(-10, 16), Pair(-27, 25)
      },
      { // Piece 4
        Pair(43, -40), Pair(136, -85), Pair(-9, -12), Pair(110, -64), Pair(131, -70), Pair(80, -50), Pair(-56, 78), Pair(10, 10),
        Pair(1, 2), Pair(-13, 13), Pair(30, -15), Pair(-5, -15), Pair(42, -3), Pair(-26, 27), Pair(64, -34), Pair(-69, 48),
        Pair(20, -7), Pair(71, -60), Pair(-14, 64), Pair(65, -31), Pair(41, 6), Pair(36, 26), Pair(7, 6), Pair(5, 7),
        Pair(2, 1), Pair(41, -39), Pair(-5, 22), Pair(4, 20), Pair(9, 18), Pair(25, 14), Pair(12, -13), Pair(35, 4),
        Pair(1, 20), Pair(6, 10), Pair(-8, 48), Pair(-22, 39), Pair(-6, 68), Pair(5, 23), Pair(0, 24), Pair(0, 0),
        Pair(-2, -22), Pair(-6, 4), Pair(13, -6), Pair(-3, 22), Pair(4, 4), Pair(-3, 38), Pair(18, 1), Pair(-50, 111),
        Pair(-11, 26), Pair(16, -10), Pair(1, 13), Pair(11, -19), Pair(-5, 12), Pair(17, -33), Pair(31, -61), Pair(-37, -18),
        Pair(3, 42), Pair(-10, 48), Pair(15, -18), Pair(3, -11), Pair(24, 4), Pair(-69, 55), Pair(65, -87), Pair(-69, 17)
      },
      { // Piece 5
        Pair(-19, -167), Pair(7, 42), Pair(109, -117), Pair(76, -30), Pair(47, -116), Pair(76, -51), Pair(39, -22), Pair(-20, -109),
        Pair(98, -92), Pair(-37, -78), Pair(-20, -56), Pair(-34, -50), Pair(-12, -36), Pair(82, -49), Pair(-18, -58), Pair(15, -81),
        Pair(-42, -66), Pair(-44, -30), Pair(70, -49), Pair(-46, -31), Pair(148, -53), Pair(77, -27), Pair(-52, -30), Pair(161, -56),
        Pair(11, -57), Pair(69, -31), Pair(164, -63), Pair(87, -30), Pair(18, -17), Pair(110, -16), Pair(74, 19), Pair(93, -23),
        Pair(84, -46), Pair(110, -55), Pair(24, -19), Pair(78, -25), Pair(4, -1), Pair(-54, 16), Pair(1, -7), Pair(0, 0),
        Pair(25, -47), Pair(-30, -15), Pair(43, -36), Pair(55, -15), Pair(24, 0), Pair(-41, 26), Pair(-10, -3), Pair(59, -10),
        Pair(-41, 26), Pair(-15, -26), Pair(1, -17), Pair(-16, -4), Pair(-10, 16), Pair(-19, 18), Pair(6, 31), Pair(13, 17),
        Pair(-18, -20), Pair(-6, -35), Pair(-22, -14), Pair(14, 1), Pair(-19, 5), Pair(-41, 28), Pair(5, 7), Pair(0, 2)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, -55), Pair(-23, 25), Pair(-4, 10), Pair(0, 11), Pair(19, 12), Pair(23, 4), Pair(-29, 14), Pair(-19, 22),
        Pair(20, -2), Pair(-7, 5), Pair(4, 3), Pair(0, 9), Pair(-2, 12), Pair(-8, 14), Pair(-12, 20), Pair(-8, 13),
        Pair(0, 0), Pair(-10, 0), Pair(-3, -2), Pair(-1, 1), Pair(-3, 2), Pair(-5, 7), Pair(-4, 5), Pair(-2, 5),
        Pair(0, 0), Pair(-8, -5), Pair(-2, -1), Pair(-3, 2), Pair(-4, 5), Pair(-7, 6), Pair(-4, 1), Pair(-4, 2),
        Pair(2, 5), Pair(-5, -1), Pair(1, -2), Pair(-1, 0), Pair(-2, 0), Pair(-6, 0), Pair(-3, -1), Pair(-5, -5),
        Pair(6, 3), Pair(-4, -3), Pair(3, -2), Pair(-3, 0), Pair(-2, 0), Pair(-4, -2), Pair(0, 0), Pair(-2, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-86, 81), Pair(-117, 39), Pair(28, 13), Pair(-4, 16), Pair(-76, 57), Pair(81, 52), Pair(-123, 44), Pair(-34, -32),
        Pair(32, 39), Pair(4, 19), Pair(13, 11), Pair(33, 31), Pair(13, 23), Pair(16, 24), Pair(143, -9), Pair(59, 2),
        Pair(71, -29), Pair(7, 29), Pair(5, 26), Pair(11, 33), Pair(11, 22), Pair(66, 11), Pair(61, -19), Pair(2, 32),
        Pair(0, 0), Pair(0, 40), Pair(5, 30), Pair(7, 20), Pair(9, 29), Pair(20, 18), Pair(21, 11), Pair(43, -2),
        Pair(2, 59), Pair(-78, -5), Pair(4, 30), Pair(5, 23), Pair(13, 27), Pair(5, 18), Pair(17, 18), Pair(12, 17),
        Pair(-5, 45), Pair(-3, 19), Pair(-6, 31), Pair(-8, 35), Pair(1, 21), Pair(3, 24), Pair(1, 24), Pair(8, 13),
        Pair(-2, -12), Pair(7, 12), Pair(-4, 12), Pair(-3, 28), Pair(-5, 21), Pair(6, 9), Pair(-12, 3), Pair(-5, 23),
        Pair(-127, 14), Pair(-5, 51), Pair(4, 3), Pair(34, -4), Pair(4, 6), Pair(-2, 21), Pair(-1, 51), Pair(-12, -104)
      },
      { // Piece 2
        Pair(-70, 48), Pair(-51, 69), Pair(-81, 68), Pair(-99, 102), Pair(-25, 72), Pair(-69, 83), Pair(25, 49), Pair(78, 43),
        Pair(-9, 69), Pair(-23, 39), Pair(-19, 55), Pair(-69, 68), Pair(-18, 71), Pair(-4, 50), Pair(38, 64), Pair(-29, 47),
        Pair(6, 31), Pair(-13, 68), Pair(-55, 64), Pair(4, 61), Pair(-5, 56), Pair(2, 80), Pair(-6, 56), Pair(11, 36),
        Pair(0, 0), Pair(-14, 48), Pair(3, 62), Pair(-11, 43), Pair(10, 68), Pair(-15, 47), Pair(8, 55), Pair(3, 30),
        Pair(-8, 82), Pair(-71, 57), Pair(-10, 43), Pair(-7, 59), Pair(-2, 32), Pair(7, 53), Pair(-16, 43), Pair(2, 44),
        Pair(5, 52), Pair(-10, 35), Pair(-6, 53), Pair(-5, 39), Pair(3, 43), Pair(-8, 27), Pair(-2, 47), Pair(-8, 20),
        Pair(-10, 42), Pair(4, 56), Pair(-6, 37), Pair(-1, 40), Pair(-10, 31), Pair(-8, 46), Pair(-4, 22), Pair(6, 36),
        Pair(1, 75), Pair(-10, 40), Pair(1, 52), Pair(-17, 41), Pair(-29, 68), Pair(-6, 24), Pair(9, 40), Pair(-15, 27)
      },
      { // Piece 3
        Pair(44, 72), Pair(-21, 89), Pair(-29, 91), Pair(-12, 74), Pair(19, 66), Pair(-39, 88), Pair(79, 51), Pair(47, 50),
        Pair(1, 104), Pair(-12, 77), Pair(-6, 86), Pair(-3, 79), Pair(-8, 85), Pair(29, 61), Pair(37, 64), Pair(7, 66),
        Pair(4, 85), Pair(0, 68), Pair(8, 70), Pair(5, 73), Pair(31, 68), Pair(38, 68), Pair(9, 66), Pair(-15, 75),
        Pair(0, 0), Pair(-3, 82), Pair(-2, 83), Pair(-6, 78), Pair(3, 64), Pair(3, 69), Pair(6, 64), Pair(54, 49),
        Pair(-4, 69), Pair(4, -6), Pair(-10, 69), Pair(-12, 63), Pair(-7, 60), Pair(-10, 73), Pair(6, 61), Pair(-9, 66),
        Pair(-29, 61), Pair(-21, 62), Pair(-12, 62), Pair(-8, 56), Pair(0, 59), Pair(7, 50), Pair(3, 59), Pair(2, 61),
        Pair(-7, 42), Pair(-23, 77), Pair(-12, 51), Pair(-21, 68), Pair(-4, 55), Pair(2, 51), Pair(-1, 65), Pair(-3, 59),
        Pair(-16, 53), Pair(-17, 61), Pair(-16, 64), Pair(-10, 55), Pair(-8, 64), Pair(-5, 56), Pair(0, 68), Pair(2, 65)
      },
      { // Piece 4
        Pair(-14, 149), Pair(9, 143), Pair(23, 115), Pair(-31, 165), Pair(41, 92), Pair(64, 69), Pair(89, 17), Pair(20, 142),
        Pair(11, 154), Pair(31, 115), Pair(12, 142), Pair(15, 128), Pair(1, 154), Pair(12, 154), Pair(-36, 120), Pair(104, 16),
        Pair(14, 148), Pair(34, 120), Pair(6, 134), Pair(19, 95), Pair(39, 122), Pair(53, 109), Pair(79, 90), Pair(32, 114),
        Pair(0, 0), Pair(16, 128), Pair(50, 76), Pair(6, 145), Pair(20, 112), Pair(40, 119), Pair(34, 109), Pair(30, 110),
        Pair(16, 106), Pair(70, -18), Pair(9, 106), Pair(21, 101), Pair(24, 89), Pair(30, 97), Pair(42, 89), Pair(37, 92),
        Pair(4, 117), Pair(11, 97), Pair(15, 99), Pair(18, 95), Pair(10, 97), Pair(21, 84), Pair(25, 93), Pair(19, 76),
        Pair(18, 88), Pair(18, 82), Pair(14, 92), Pair(7, 110), Pair(15, 96), Pair(16, 87), Pair(22, 95), Pair(21, 125),
        Pair(19, 116), Pair(12, 115), Pair(13, 101), Pair(13, 88), Pair(20, 70), Pair(17, 67), Pair(-6, 118), Pair(47, -48)
      },
      { // Piece 5
        Pair(-11, 98), Pair(-52, -92), Pair(-78, 42), Pair(37, -8), Pair(-79, 2), Pair(-43, -31), Pair(-54, -38), Pair(-3, 17),
        Pair(36, -2), Pair(-114, -34), Pair(92, -36), Pair(192, -58), Pair(77, -10), Pair(123, -42), Pair(-85, -2), Pair(29, -13),
        Pair(-123, 6), Pair(49, 14), Pair(93, -36), Pair(20, -3), Pair(121, -17), Pair(-60, 13), Pair(-23, -9), Pair(-23, 12),
        Pair(0, 0), Pair(159, -51), Pair(-34, 12), Pair(38, -3), Pair(34, -8), Pair(80, -12), Pair(12, -6), Pair(30, -6),
        Pair(-30, -43), Pair(50, -73), Pair(5, 1), Pair(-7, -3), Pair(36, -7), Pair(22, 3), Pair(27, 1), Pair(41, -6),
        Pair(-34, 3), Pair(-32, 17), Pair(-28, -4), Pair(-20, 5), Pair(6, -4), Pair(16, -8), Pair(10, -10), Pair(13, 0),
        Pair(36, -19), Pair(-9, 2), Pair(-12, 15), Pair(18, -2), Pair(3, -4), Pair(4, -6), Pair(3, -2), Pair(8, -6),
        Pair(-2, 14), Pair(11, 3), Pair(2, 9), Pair(-11, 5), Pair(10, -10), Pair(6, -10), Pair(4, -10), Pair(6, 0)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-35, 32), Pair(30, 10), Pair(-4, -1), Pair(32, 2), Pair(13, 23), Pair(33, 11), Pair(-34, 22), Pair(19, 10),
        Pair(-3, 2), Pair(-15, 11), Pair(-3, 2), Pair(-2, 13), Pair(-4, 14), Pair(-1, 11), Pair(1, 24), Pair(-4, 12),
        Pair(-3, 6), Pair(0, 0), Pair(0, 3), Pair(-4, 5), Pair(-1, 8), Pair(-2, 4), Pair(2, 7), Pair(-1, 8),
        Pair(9, 6), Pair(0, 0), Pair(-1, 13), Pair(1, 2), Pair(-4, 4), Pair(-3, 3), Pair(-6, 7), Pair(-1, 5),
        Pair(8, -1), Pair(2, 3), Pair(0, 6), Pair(0, 1), Pair(-3, 2), Pair(-6, 1), Pair(-7, 1), Pair(-3, 2),
        Pair(5, 1), Pair(8, 6), Pair(0, 2), Pair(3, -2), Pair(-3, -4), Pair(-5, -3), Pair(-6, -3), Pair(-2, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, 42), Pair(11, -10), Pair(-7, 67), Pair(-67, 71), Pair(64, 8), Pair(39, 50), Pair(-104, 82), Pair(92, 86),
        Pair(10, 29), Pair(-1, 55), Pair(46, 23), Pair(45, 16), Pair(5, 32), Pair(55, 22), Pair(111, 7), Pair(61, 35),
        Pair(-2, 41), Pair(8, -3), Pair(17, 39), Pair(9, 23), Pair(46, 29), Pair(44, 49), Pair(32, 31), Pair(66, 15),
        Pair(-15, 39), Pair(0, 0), Pair(14, 42), Pair(-3, 55), Pair(17, 28), Pair(17, 39), Pair(25, 29), Pair(22, 19),
        Pair(-10, -20), Pair(21, 74), Pair(-29, 3), Pair(8, 29), Pair(8, 36), Pair(12, 36), Pair(34, 43), Pair(18, 31),
        Pair(-10, -13), Pair(8, 36), Pair(-3, 20), Pair(14, 29), Pair(-4, 34), Pair(9, 32), Pair(18, 32), Pair(8, 57),
        Pair(33, 2), Pair(-36, -15), Pair(9, 43), Pair(2, 20), Pair(13, 35), Pair(14, 6), Pair(9, 36), Pair(6, 48),
        Pair(96, 68), Pair(3, 40), Pair(-8, 49), Pair(-2, 27), Pair(7, 32), Pair(7, 22), Pair(4, 35), Pair(-79, 25)
      },
      { // Piece 2
        Pair(-9, 5), Pair(-48, 79), Pair(54, 23), Pair(26, 51), Pair(-3, 69), Pair(-40, 69), Pair(54, 63), Pair(43, 46),
        Pair(-7, 35), Pair(-37, 64), Pair(29, 40), Pair(-44, 74), Pair(19, 63), Pair(16, 57), Pair(60, 51), Pair(18, 43),
        Pair(-69, 38), Pair(3, 51), Pair(21, 55), Pair(-24, 66), Pair(8, 66), Pair(-25, 79), Pair(-10, 84), Pair(24, 26),
        Pair(21, 35), Pair(0, 0), Pair(19, 51), Pair(1, 58), Pair(16, 48), Pair(-6, 57), Pair(7, 54), Pair(13, 45),
        Pair(-20, 97), Pair(9, 65), Pair(6, -19), Pair(-5, 50), Pair(13, 46), Pair(1, 45), Pair(8, 32), Pair(12, 29),
        Pair(-19, 35), Pair(0, 47), Pair(-7, 46), Pair(9, 33), Pair(3, 41), Pair(4, 44), Pair(14, 29), Pair(13, 33),
        Pair(0, 40), Pair(6, 31), Pair(1, 45), Pair(4, 32), Pair(2, 35), Pair(-1, 35), Pair(12, 37), Pair(5, -9),
        Pair(0, 65), Pair(8, 57), Pair(9, 35), Pair(16, 32), Pair(10, 31), Pair(8, 15), Pair(16, 31), Pair(6, 55)
      },
      { // Piece 3
        Pair(17, 60), Pair(78, 44), Pair(0, 69), Pair(23, 64), Pair(-33, 78), Pair(-26, 78), Pair(-2, 79), Pair(-18, 51),
        Pair(7, 71), Pair(6, 82), Pair(-18, 78), Pair(4, 78), Pair(3, 65), Pair(41, 56), Pair(27, 57), Pair(2, 72),
        Pair(4, 57), Pair(-16, 75), Pair(16, 66), Pair(10, 69), Pair(12, 60), Pair(56, 39), Pair(21, 51), Pair(7, 63),
        Pair(-6, 50), Pair(0, 0), Pair(15, 71), Pair(12, 65), Pair(-3, 71), Pair(-6, 63), Pair(6, 60), Pair(9, 66),
        Pair(-53, -5), Pair(-20, 62), Pair(-82, 73), Pair(-11, 57), Pair(4, 49), Pair(-7, 59), Pair(-14, 65), Pair(-1, 68),
        Pair(-16, 65), Pair(-9, 43), Pair(-23, 56), Pair(14, 43), Pair(-6, 56), Pair(-2, 56), Pair(5, 57), Pair(6, 64),
        Pair(-8, 37), Pair(0, 27), Pair(-1, 61), Pair(-2, 48), Pair(7, 48), Pair(-2, 46), Pair(-5, 58), Pair(11, 62),
        Pair(-3, 51), Pair(-8, 48), Pair(-6, 57), Pair(-1, 59), Pair(-1, 55), Pair(1, 61), Pair(2, 68), Pair(11, 57)
      },
      { // Piece 4
        Pair(49, 63), Pair(25, 80), Pair(41, 88), Pair(-5, 106), Pair(-18, 146), Pair(141, 3), Pair(-26, 114), Pair(2, 131),
        Pair(46, 63), Pair(30, 99), Pair(50, 53), Pair(32, 99), Pair(1, 115), Pair(26, 110), Pair(33, 75), Pair(47, 70),
        Pair(43, 16), Pair(-1, 128), Pair(1, 96), Pair(23, 97), Pair(51, 95), Pair(55, 117), Pair(35, 107), Pair(46, 105),
        Pair(34, 50), Pair(0, 0), Pair(15, 98), Pair(22, 112), Pair(51, 91), Pair(20, 124), Pair(46, 108), Pair(38, 86),
        Pair(64, -74), Pair(29, 67), Pair(77, -8), Pair(21, 90), Pair(14, 100), Pair(34, 86), Pair(30, 53), Pair(38, 86),
        Pair(26, 30), Pair(16, 74), Pair(17, 62), Pair(12, 95), Pair(16, 86), Pair(12, 87), Pair(39, 52), Pair(7, 123),
        Pair(16, 79), Pair(12, 83), Pair(17, 80), Pair(20, 69), Pair(21, 65), Pair(16, 78), Pair(48, 30), Pair(-8, 129),
        Pair(48, 22), Pair(38, 43), Pair(26, 58), Pair(21, 71), Pair(21, 56), Pair(14, 118), Pair(82, -1), Pair(0, 56)
      },
      { // Piece 5
        Pair(0, -53), Pair(73, -38), Pair(56, -78), Pair(60, -11), Pair(-16, 76), Pair(-70, -9), Pair(55, -20), Pair(16, -83),
        Pair(-2, -4), Pair(-76, -20), Pair(-24, -31), Pair(63, -23), Pair(43, -2), Pair(-96, 47), Pair(-11, -25), Pair(-4, -25),
        Pair(22, 12), Pair(-9, 15), Pair(125, -2), Pair(170, -11), Pair(247, -45), Pair(85, -19), Pair(162, -25), Pair(122, -5),
        Pair(11, 0), Pair(0, 0), Pair(97, -42), Pair(43, -15), Pair(123, -14), Pair(-47, 14), Pair(-1, 9), Pair(-22, -4),
        Pair(-15, 19), Pair(-8, -57), Pair(8, 117), Pair(-31, 0), Pair(59, -12), Pair(50, -8), Pair(-10, -4), Pair(8, -14),
        Pair(-76, -1), Pair(-43, -14), Pair(-15, -13), Pair(16, -11), Pair(0, 5), Pair(21, -4), Pair(32, -18), Pair(52, -15),
        Pair(-49, 16), Pair(-19, 5), Pair(3, -2), Pair(3, -3), Pair(5, -2), Pair(11, -5), Pair(14, -10), Pair(8, -4),
        Pair(-23, 4), Pair(0, -1), Pair(-2, 1), Pair(43, 5), Pair(-3, 13), Pair(25, -9), Pair(5, -7), Pair(9, -7)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-34, 30), Pair(12, -3), Pair(1, -10), Pair(9, 5), Pair(-9, 32), Pair(-5, 18), Pair(3, 19), Pair(18, 8),
        Pair(0, 6), Pair(-5, 8), Pair(-3, 2), Pair(4, 3), Pair(4, 5), Pair(4, 13), Pair(-7, 11), Pair(-5, 13),
        Pair(-1, 5), Pair(2, 2), Pair(0, 0), Pair(2, 0), Pair(-3, 5), Pair(0, 4), Pair(-2, 7), Pair(3, 4),
        Pair(2, 0), Pair(1, -13), Pair(0, 0), Pair(-4, 2), Pair(-2, 3), Pair(-4, 4), Pair(-2, 3), Pair(-2, 5),
        Pair(0, -1), Pair(0, -6), Pair(1, 4), Pair(-3, 0), Pair(-3, 0), Pair(-9, 2), Pair(-5, 0), Pair(-3, 1),
        Pair(1, -1), Pair(0, -9), Pair(7, 7), Pair(-8, -1), Pair(-1, -4), Pair(-6, -1), Pair(-3, -2), Pair(-2, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, 76), Pair(26, 36), Pair(66, 3), Pair(53, 6), Pair(-37, 43), Pair(-1, 76), Pair(-37, 91), Pair(-64, 65),
        Pair(-6, 44), Pair(6, 34), Pair(27, 28), Pair(-10, 46), Pair(55, 26), Pair(41, 14), Pair(51, 12), Pair(1, 35),
        Pair(-38, -7), Pair(-20, 59), Pair(-18, 45), Pair(-1, 49), Pair(-9, 28), Pair(-30, 78), Pair(27, 38), Pair(-4, 36),
        Pair(-2, 52), Pair(-6, 32), Pair(0, 0), Pair(2, 45), Pair(1, 52), Pair(6, 36), Pair(11, 54), Pair(9, 36),
        Pair(1, 21), Pair(-40, 39), Pair(9, 90), Pair(-34, 21), Pair(3, 34), Pair(-2, 45), Pair(10, 50), Pair(11, 39),
        Pair(-4, 48), Pair(-21, 20), Pair(2, 41), Pair(4, 31), Pair(-1, 45), Pair(-5, 31), Pair(-1, 36), Pair(8, 36),
        Pair(5, -48), Pair(-15, 65), Pair(-6, 2), Pair(-1, 41), Pair(-1, 27), Pair(7, 38), Pair(-6, 34), Pair(3, 36),
        Pair(-9, 30), Pair(4, 44), Pair(0, 41), Pair(12, 32), Pair(-10, 43), Pair(15, 27), Pair(-6, 56), Pair(-14, 122)
      },
      { // Piece 2
        Pair(50, 36), Pair(50, 9), Pair(17, 35), Pair(10, 31), Pair(5, 53), Pair(-68, 80), Pair(61, 57), Pair(80, 22),
        Pair(-98, 36), Pair(-22, 53), Pair(-24, 54), Pair(-25, 60), Pair(-10, 42), Pair(-7, 58), Pair(-30, 35), Pair(-10, 37),
        Pair(-11, 62), Pair(-33, 35), Pair(-25, 51), Pair(-24, 46), Pair(-11, 58), Pair(-21, 58), Pair(-3, 47), Pair(-6, 45),
        Pair(1, 27), Pair(0, 44), Pair(0, 0), Pair(-2, 57), Pair(-5, 47), Pair(-10, 57), Pair(-11, 45), Pair(3, 37),
        Pair(-15, 39), Pair(-49, -96), Pair(9, 84), Pair(-50, -60), Pair(5, 36), Pair(-10, 44), Pair(-4, 39), Pair(-2, 34),
        Pair(-18, -3), Pair(-20, 41), Pair(-9, 28), Pair(-4, 37), Pair(-11, 20), Pair(-5, 35), Pair(8, 22), Pair(-3, 47),
        Pair(-38, 9), Pair(-6, 9), Pair(-1, 46), Pair(-2, 20), Pair(0, 26), Pair(-21, 35), Pair(0, 28), Pair(10, 29),
        Pair(-4, 26), Pair(-1, 47), Pair(-2, 22), Pair(1, 32), Pair(-4, 21), Pair(-3, 34), Pair(-36, 33), Pair(-29, 77)
      },
      { // Piece 3
        Pair(0, 49), Pair(29, 45), Pair(68, 42), Pair(-3, 56), Pair(18, 39), Pair(37, 39), Pair(40, 37), Pair(-43, 68),
        Pair(-9, 61), Pair(-5, 49), Pair(-32, 77), Pair(-9, 70), Pair(8, 50), Pair(14, 53), Pair(20, 47), Pair(-2, 58),
        Pair(-6, 56), Pair(-6, 46), Pair(21, 48), Pair(2, 47), Pair(14, 43), Pair(33, 46), Pair(-5, 43), Pair(-19, 49),
        Pair(-11, 50), Pair(-2, 44), Pair(0, 0), Pair(1, 51), Pair(-5, 60), Pair(-1, 47), Pair(10, 48), Pair(48, 26),
        Pair(-14, 45), Pair(-51, 91), Pair(-9, 34), Pair(-25, 24), Pair(-8, 33), Pair(-13, 47), Pair(5, 41), Pair(-6, 40),
        Pair(-6, 48), Pair(-13, 33), Pair(-28, 42), Pair(-4, 33), Pair(-12, 55), Pair(-10, 48), Pair(2, 36), Pair(-2, 40),
        Pair(6, 37), Pair(3, 40), Pair(-20, 41), Pair(-10, 27), Pair(-5, 38), Pair(2, 35), Pair(6, 37), Pair(10, 29),
        Pair(-9, 47), Pair(-10, 37), Pair(-12, 31), Pair(-11, 41), Pair(-7, 41), Pair(-6, 43), Pair(10, 27), Pair(7, 42)
      },
      { // Piece 4
        Pair(19, 41), Pair(6, 82), Pair(46, 58), Pair(-15, 107), Pair(71, 51), Pair(24, 83), Pair(3, 126), Pair(7, 136),
        Pair(6, 76), Pair(1, 99), Pair(2, 105), Pair(20, 73), Pair(-22, 145), Pair(56, 66), Pair(22, 66), Pair(32, 70),
        Pair(13, 81), Pair(10, 63), Pair(2, 86), Pair(44, 49), Pair(17, 91), Pair(24, 75), Pair(52, 69), Pair(27, 72),
        Pair(12, 61), Pair(4, 88), Pair(0, 0), Pair(25, 48), Pair(6, 88), Pair(17, 75), Pair(20, 87), Pair(17, 88),
        Pair(10, 90), Pair(-8, 74), Pair(20, 59), Pair(26, -8), Pair(13, 82), Pair(21, 51), Pair(17, 76), Pair(15, 94),
        Pair(0, 33), Pair(2, 60), Pair(18, 43), Pair(9, 57), Pair(12, 49), Pair(8, 73), Pair(16, 83), Pair(10, 106),
        Pair(7, 109), Pair(11, 43), Pair(15, 68), Pair(6, 74), Pair(12, 59), Pair(8, 67), Pair(20, 55), Pair(6, 48),
        Pair(23, 34), Pair(13, 60), Pair(12, 52), Pair(13, 52), Pair(6, 71), Pair(19, 40), Pair(39, -17), Pair(-24, 50)
      },
      { // Piece 5
        Pair(-19, -56), Pair(-2, -112), Pair(68, -34), Pair(0, -17), Pair(14, -43), Pair(55, -64), Pair(23, -24), Pair(-10, -85),
        Pair(-34, -35), Pair(-33, -9), Pair(-194, 44), Pair(-90, -45), Pair(-17, -2), Pair(-38, 10), Pair(39, -5), Pair(-18, -13),
        Pair(78, -30), Pair(106, -14), Pair(-9, 18), Pair(121, -13), Pair(-4, -8), Pair(-77, -2), Pair(-49, 12), Pair(-13, -12),
        Pair(-150, -15), Pair(46, -42), Pair(0, 0), Pair(50, -36), Pair(34, -6), Pair(-27, 13), Pair(41, 4), Pair(-62, 19),
        Pair(-31, -10), Pair(-75, -70), Pair(-35, -39), Pair(-40, 7), Pair(26, -11), Pair(23, 8), Pair(28, -3), Pair(2, -5),
        Pair(-3, 11), Pair(9, -13), Pair(3, -18), Pair(64, -21), Pair(-3, -4), Pair(-6, 11), Pair(-7, 6), Pair(8, 2),
        Pair(-39, 16), Pair(-20, -7), Pair(-2, -6), Pair(15, -8), Pair(-8, 5), Pair(16, 3), Pair(2, 3), Pair(2, 3),
        Pair(-15, 27), Pair(-12, 8), Pair(-11, 11), Pair(10, 6), Pair(1, 13), Pair(3, 15), Pair(5, 5), Pair(6, -6)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(2, 13), Pair(5, 12), Pair(-29, 14), Pair(-3, -1), Pair(-4, 2), Pair(19, -5), Pair(2, 15), Pair(10, 10),
        Pair(2, 11), Pair(-7, 10), Pair(-1, -2), Pair(-3, 15), Pair(3, 1), Pair(3, 11), Pair(10, 8), Pair(-6, 8),
        Pair(1, 3), Pair(2, 5), Pair(0, -1), Pair(0, 0), Pair(4, 4), Pair(1, 2), Pair(3, 0), Pair(2, 7),
        Pair(3, -2), Pair(0, -3), Pair(4, -1), Pair(0, 0), Pair(-2, -3), Pair(-2, 2), Pair(4, -2), Pair(2, 2),
        Pair(3, -4), Pair(1, -2), Pair(2, -4), Pair(2, 4), Pair(-1, 0), Pair(-3, 1), Pair(0, -2), Pair(-1, 1),
        Pair(2, -1), Pair(1, 0), Pair(-2, -7), Pair(5, 5), Pair(-3, -4), Pair(-3, 3), Pair(1, -2), Pair(1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-69, 51), Pair(-99, 55), Pair(-38, 37), Pair(29, 54), Pair(30, 49), Pair(-8, 81), Pair(-66, 51), Pair(79, -36),
        Pair(-25, 36), Pair(10, 31), Pair(7, 35), Pair(-27, 38), Pair(34, 8), Pair(-66, 88), Pair(-6, 41), Pair(26, 21),
        Pair(31, 22), Pair(-18, 8), Pair(-31, 58), Pair(-8, 41), Pair(8, 54), Pair(3, 22), Pair(-12, 50), Pair(10, 39),
        Pair(-7, 26), Pair(-9, 35), Pair(-6, 43), Pair(0, 0), Pair(-4, 47), Pair(-1, 54), Pair(3, 35), Pair(3, 51),
        Pair(-2, 21), Pair(7, 26), Pair(-26, -5), Pair(18, 67), Pair(-46, 11), Pair(-2, 29), Pair(-4, 40), Pair(0, 35),
        Pair(-8, 3), Pair(-2, 37), Pair(-10, 7), Pair(1, 37), Pair(-15, 18), Pair(2, 36), Pair(-12, 27), Pair(5, 27),
        Pair(7, 31), Pair(-31, 16), Pair(0, 36), Pair(-11, 11), Pair(3, 30), Pair(-6, 21), Pair(14, 29), Pair(0, 41),
        Pair(-19, 58), Pair(0, 18), Pair(18, 17), Pair(-14, 26), Pair(-2, 26), Pair(13, 18), Pair(3, 44), Pair(32, 37)
      },
      { // Piece 2
        Pair(-93, -12), Pair(-105, 59), Pair(-42, 35), Pair(-25, 45), Pair(-136, 82), Pair(36, 20), Pair(-41, 71), Pair(-2, 85),
        Pair(21, 35), Pair(-59, 18), Pair(3, 40), Pair(2, 47), Pair(-54, 51), Pair(-62, 57), Pair(12, 69), Pair(11, 12),
        Pair(-19, 36), Pair(-28, 50), Pair(-58, 36), Pair(-22, 38), Pair(-14, 40), Pair(-1, 37), Pair(-19, 46), Pair(24, 19),
        Pair(-11, 53), Pair(-15, 30), Pair(0, 42), Pair(0, 0), Pair(1, 40), Pair(-23, 51), Pair(-4, 45), Pair(-14, 27),
        Pair(-30, 48), Pair(-7, 23), Pair(-16, -38), Pair(18, 62), Pair(-54, -130), Pair(-3, 37), Pair(-1, 9), Pair(0, 46),
        Pair(-8, 43), Pair(-31, 28), Pair(-15, 30), Pair(-5, 18), Pair(-5, 21), Pair(-22, 15), Pair(2, 21), Pair(-9, 26),
        Pair(-36, -13), Pair(-3, 15), Pair(-6, 17), Pair(3, 25), Pair(-5, 9), Pair(1, 25), Pair(-11, 2), Pair(0, 10),
        Pair(-20, 41), Pair(4, 14), Pair(0, 29), Pair(-11, 35), Pair(-5, 32), Pair(-7, 5), Pair(-17, 27), Pair(-33, -3)
      },
      { // Piece 3
        Pair(6, 43), Pair(-18, 53), Pair(-6, 50), Pair(8, 43), Pair(-12, 44), Pair(42, 42), Pair(-37, 61), Pair(47, 35),
        Pair(2, 43), Pair(-16, 50), Pair(-25, 68), Pair(-33, 77), Pair(-13, 52), Pair(34, 38), Pair(-22, 57), Pair(-10, 53),
        Pair(-11, 47), Pair(-11, 50), Pair(-1, 43), Pair(14, 51), Pair(6, 39), Pair(25, 45), Pair(43, 28), Pair(9, 32),
        Pair(-7, 50), Pair(-13, 35), Pair(3, 36), Pair(0, 0), Pair(-6, 46), Pair(8, 37), Pair(5, 34), Pair(3, 36),
        Pair(-8, 42), Pair(-10, 38), Pair(16, -66), Pair(-7, 30), Pair(-59, 65), Pair(-11, 31), Pair(-28, 53), Pair(-9, 40),
        Pair(-3, 38), Pair(-1, 34), Pair(-9, 30), Pair(-25, 44), Pair(-6, 39), Pair(4, 36), Pair(-1, 36), Pair(0, 45),
        Pair(7, 24), Pair(4, 31), Pair(-2, 27), Pair(-15, 26), Pair(-5, 26), Pair(2, 32), Pair(-14, 35), Pair(-12, 43),
        Pair(-3, 35), Pair(-6, 38), Pair(-7, 35), Pair(-9, 28), Pair(-3, 31), Pair(-1, 35), Pair(3, 30), Pair(11, 28)
      },
      { // Piece 4
        Pair(-22, 44), Pair(-31, 82), Pair(40, 63), Pair(-44, 114), Pair(9, 99), Pair(-17, 102), Pair(-20, 163), Pair(85, 41),
        Pair(12, 80), Pair(4, 41), Pair(-12, 104), Pair(-7, 81), Pair(-3, 87), Pair(-16, 152), Pair(32, 97), Pair(19, 91),
        Pair(-7, 62), Pair(-1, 86), Pair(7, 50), Pair(-2, 88), Pair(-6, 108), Pair(-5, 109), Pair(14, 67), Pair(11, 101),
        Pair(4, 74), Pair(-1, 75), Pair(-2, 40), Pair(0, 0), Pair(9, 69), Pair(16, 60), Pair(12, 97), Pair(3, 87),
        Pair(11, 34), Pair(5, 65), Pair(74, -167), Pair(20, 58), Pair(39, -26), Pair(27, 30), Pair(12, 63), Pair(13, 66),
        Pair(8, 81), Pair(5, 37), Pair(0, 65), Pair(10, 54), Pair(-1, 80), Pair(1, 54), Pair(0, 77), Pair(13, 65),
        Pair(-7, 83), Pair(6, 62), Pair(7, 42), Pair(7, 62), Pair(6, 54), Pair(11, 43), Pair(8, 52), Pair(21, 57),
        Pair(4, 51), Pair(14, 27), Pair(5, 70), Pair(11, 51), Pair(15, 47), Pair(-1, 59), Pair(23, 56), Pair(-8, 107)
      },
      { // Piece 5
        Pair(86, 204), Pair(-28, 10), Pair(-70, 19), Pair(-16, -96), Pair(50, 35), Pair(46, -117), Pair(13, -32), Pair(121, -8),
        Pair(22, 86), Pair(-35, -38), Pair(52, -47), Pair(54, 2), Pair(-26, 11), Pair(-51, -27), Pair(45, -36), Pair(3, -30),
        Pair(5, -25), Pair(-100, 26), Pair(73, -15), Pair(61, -38), Pair(28, -6), Pair(114, -15), Pair(1, -8), Pair(47, -10),
        Pair(70, -6), Pair(60, 3), Pair(79, -56), Pair(0, 0), Pair(80, -60), Pair(-79, 8), Pair(-67, 24), Pair(77, -3),
        Pair(98, 36), Pair(-25, 2), Pair(-32, -14), Pair(4, -53), Pair(26, -8), Pair(7, 4), Pair(-2, 18), Pair(85, -5),
        Pair(3, 26), Pair(-35, 7), Pair(50, -24), Pair(33, -33), Pair(17, -22), Pair(-18, 5), Pair(5, 7), Pair(28, 0),
        Pair(-19, 26), Pair(-20, 14), Pair(-1, 9), Pair(6, -10), Pair(-2, 0), Pair(-12, 19), Pair(0, 13), Pair(7, 6),
        Pair(-13, 9), Pair(-13, 35), Pair(-10, 2), Pair(-2, -15), Pair(-4, -5), Pair(-6, 21), Pair(-2, 16), Pair(4, 8)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(2, 19), Pair(7, 11), Pair(-12, 18), Pair(-6, 16), Pair(49, -14), Pair(10, 15), Pair(-21, 18), Pair(8, 8),
        Pair(5, 1), Pair(0, 5), Pair(4, -4), Pair(-7, 4), Pair(-8, 5), Pair(12, 5), Pair(8, 5), Pair(-1, 7),
        Pair(0, -1), Pair(3, 1), Pair(4, -3), Pair(1, 2), Pair(0, 0), Pair(-2, 4), Pair(1, 4), Pair(2, 7),
        Pair(3, -3), Pair(4, -4), Pair(2, -4), Pair(2, 6), Pair(0, 0), Pair(-3, -10), Pair(2, 0), Pair(-2, 3),
        Pair(2, -6), Pair(2, -3), Pair(-1, -2), Pair(1, -1), Pair(0, 3), Pair(-1, -1), Pair(-4, -1), Pair(-1, 1),
        Pair(4, -2), Pair(3, -4), Pair(0, -1), Pair(1, -5), Pair(2, 7), Pair(-5, -3), Pair(0, 4), Pair(-1, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, -8), Pair(-102, 71), Pair(140, -16), Pair(71, 4), Pair(-37, 58), Pair(-108, 58), Pair(-100, 15), Pair(63, -74),
        Pair(-14, 19), Pair(20, 26), Pair(26, 37), Pair(-18, 31), Pair(-12, 56), Pair(-59, 49), Pair(-39, 45), Pair(51, 37),
        Pair(46, 31), Pair(-3, 35), Pair(-8, 9), Pair(-13, 45), Pair(-24, 41), Pair(-1, 38), Pair(-39, 11), Pair(16, 27),
        Pair(8, 22), Pair(-7, 29), Pair(-3, 48), Pair(-1, 38), Pair(0, 0), Pair(-17, 39), Pair(-7, 35), Pair(-25, 12),
        Pair(0, 39), Pair(2, 9), Pair(0, 31), Pair(-45, -2), Pair(6, 76), Pair(-26, -6), Pair(0, 33), Pair(0, 28),
        Pair(-3, 28), Pair(-17, 30), Pair(-3, 38), Pair(-11, 18), Pair(1, 37), Pair(-7, -2), Pair(-3, 34), Pair(-19, 3),
        Pair(-4, 29), Pair(10, 24), Pair(3, 10), Pair(-1, 30), Pair(-15, -4), Pair(6, 33), Pair(-11, 23), Pair(2, 21),
        Pair(-44, 44), Pair(6, 27), Pair(2, 15), Pair(19, 26), Pair(-4, 26), Pair(17, 22), Pair(-4, 15), Pair(97, -68)
      },
      { // Piece 2
        Pair(-7, 56), Pair(101, -22), Pair(-25, 54), Pair(-108, 56), Pair(-79, 50), Pair(-73, 54), Pair(187, 15), Pair(10, 56),
        Pair(-29, 48), Pair(-9, 40), Pair(-14, 37), Pair(15, 36), Pair(-60, 54), Pair(-6, 33), Pair(26, 14), Pair(1, 55),
        Pair(4, 29), Pair(-25, 31), Pair(-30, 43), Pair(-42, 37), Pair(14, 19), Pair(-37, 26), Pair(-22, 48), Pair(6, 15),
        Pair(-8, 30), Pair(-1, 29), Pair(-20, 34), Pair(6, 36), Pair(0, 0), Pair(-19, 46), Pair(-13, 31), Pair(-1, 32),
        Pair(-9, 32), Pair(-3, 28), Pair(-5, 26), Pair(-21, -78), Pair(5, 74), Pair(13, -61), Pair(4, 33), Pair(-16, 22),
        Pair(-9, 29), Pair(-13, 40), Pair(-11, 8), Pair(-8, 32), Pair(-8, 17), Pair(-9, 19), Pair(-21, -10), Pair(-3, 31),
        Pair(-6, 37), Pair(-11, 1), Pair(-6, 36), Pair(-6, 22), Pair(3, 19), Pair(-8, 16), Pair(-2, 17), Pair(-16, -47),
        Pair(-41, 18), Pair(-10, 40), Pair(0, 13), Pair(8, 23), Pair(-15, 26), Pair(-1, 29), Pair(-31, 38), Pair(-20, 37)
      },
      { // Piece 3
        Pair(20, 38), Pair(-19, 51), Pair(-15, 47), Pair(-3, 36), Pair(-30, 30), Pair(-22, 46), Pair(-82, 61), Pair(-4, 44),
        Pair(4, 38), Pair(9, 41), Pair(-14, 55), Pair(-5, 37), Pair(12, 45), Pair(13, 45), Pair(39, 16), Pair(-16, 46),
        Pair(0, 30), Pair(18, 34), Pair(-10, 43), Pair(-10, 45), Pair(5, 43), Pair(30, 17), Pair(36, 29), Pair(6, 28),
        Pair(8, 36), Pair(3, 21), Pair(-2, 34), Pair(15, 24), Pair(0, 0), Pair(2, 15), Pair(-5, 39), Pair(18, 31),
        Pair(0, 32), Pair(-1, 31), Pair(-10, 31), Pair(-72, 23), Pair(0, 23), Pair(30, -59), Pair(-14, 27), Pair(-1, 12),
        Pair(-2, 39), Pair(12, 25), Pair(2, 25), Pair(-5, 32), Pair(-7, 17), Pair(-3, 25), Pair(3, 19), Pair(15, 28),
        Pair(16, 23), Pair(6, 22), Pair(-1, 36), Pair(-2, 19), Pair(-6, 29), Pair(9, 22), Pair(10, 17), Pair(29, -6),
        Pair(5, 32), Pair(-2, 32), Pair(1, 38), Pair(-5, 31), Pair(-3, 25), Pair(1, 28), Pair(7, 27), Pair(4, 33)
      },
      { // Piece 4
        Pair(10, 53), Pair(-8, 71), Pair(-41, 127), Pair(57, 16), Pair(-26, 110), Pair(-21, 155), Pair(37, 54), Pair(36, 4),
        Pair(28, 46), Pair(2, 83), Pair(34, 23), Pair(14, 86), Pair(1, 69), Pair(0, 97), Pair(-41, 150), Pair(-18, 112),
        Pair(13, 64), Pair(30, 38), Pair(26, 50), Pair(1, 68), Pair(16, 79), Pair(-14, 144), Pair(-22, 130), Pair(31, 62),
        Pair(21, 45), Pair(9, 94), Pair(13, 30), Pair(15, 64), Pair(0, 0), Pair(-3, 91), Pair(-18, 74), Pair(19, 68),
        Pair(10, 75), Pair(1, 105), Pair(10, 55), Pair(4, 94), Pair(28, 36), Pair(38, 20), Pair(10, 76), Pair(3, 81),
        Pair(10, 79), Pair(8, 52), Pair(3, 54), Pair(-6, 72), Pair(5, 59), Pair(11, 49), Pair(3, 42), Pair(-11, 81),
        Pair(31, 35), Pair(6, 51), Pair(7, 58), Pair(-1, 53), Pair(17, 49), Pair(4, 60), Pair(20, 26), Pair(7, 46),
        Pair(-3, 73), Pair(9, 72), Pair(7, 18), Pair(10, 41), Pair(16, 30), Pair(6, 40), Pair(-8, 77), Pair(29, 27)
      },
      { // Piece 5
        Pair(-116, -71), Pair(-48, -10), Pair(-59, -88), Pair(-49, 37), Pair(58, 43), Pair(25, 110), Pair(14, -43), Pair(3, -73),
        Pair(-48, -71), Pair(2, -18), Pair(85, -35), Pair(65, 37), Pair(31, -1), Pair(21, 3), Pair(9, -27), Pair(138, 2),
        Pair(1, -28), Pair(-34, 25), Pair(-24, -7), Pair(86, -31), Pair(105, -6), Pair(269, -34), Pair(29, 13), Pair(17, -12),
        Pair(-10, 1), Pair(128, -8), Pair(-121, 21), Pair(16, -44), Pair(0, 0), Pair(127, -57), Pair(-4, 2), Pair(0, 16),
        Pair(-28, 6), Pair(50, 12), Pair(-54, 22), Pair(57, -105), Pair(-61, -28), Pair(17, -30), Pair(-14, 8), Pair(-27, 24),
        Pair(46, 4), Pair(15, -1), Pair(-8, 3), Pair(43, -17), Pair(57, -26), Pair(55, -18), Pair(0, 9), Pair(3, 14),
        Pair(22, 4), Pair(-16, 14), Pair(10, 13), Pair(14, 3), Pair(21, -7), Pair(7, 7), Pair(-6, 20), Pair(4, 18),
        Pair(-21, 18), Pair(-3, 25), Pair(-1, 25), Pair(33, -11), Pair(-1, 6), Pair(15, 5), Pair(-2, 24), Pair(2, 26)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, 11), Pair(20, 9), Pair(-25, 20), Pair(0, 11), Pair(5, 3), Pair(-28, 10), Pair(-8, 23), Pair(4, 3),
        Pair(12, 0), Pair(12, 2), Pair(9, 1), Pair(2, 1), Pair(2, -11), Pair(5, 7), Pair(5, 6), Pair(-3, 4),
        Pair(3, 1), Pair(4, -2), Pair(1, 1), Pair(-1, -2), Pair(0, 1), Pair(0, 0), Pair(6, -1), Pair(1, 2),
        Pair(7, -5), Pair(2, -3), Pair(4, -3), Pair(3, -3), Pair(2, 9), Pair(0, 0), Pair(2, -8), Pair(2, -1),
        Pair(4, -5), Pair(4, -2), Pair(1, -4), Pair(3, -4), Pair(-1, 1), Pair(3, 3), Pair(-4, -4), Pair(1, -1),
        Pair(3, -4), Pair(2, -2), Pair(1, -5), Pair(3, 0), Pair(0, -4), Pair(6, 0), Pair(-1, -6), Pair(1, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(51, 1), Pair(97, -31), Pair(-16, 13), Pair(-85, 64), Pair(78, -17), Pair(-94, 66), Pair(51, -13), Pair(-54, 65),
        Pair(-12, 27), Pair(3, 10), Pair(13, 33), Pair(-20, 30), Pair(20, 17), Pair(-9, 30), Pair(17, 7), Pair(1, 60),
        Pair(-9, 30), Pair(10, 23), Pair(14, 24), Pair(13, 16), Pair(8, 26), Pair(2, 29), Pair(9, 31), Pair(-10, -13),
        Pair(14, 9), Pair(10, 24), Pair(6, 21), Pair(7, 30), Pair(4, 37), Pair(0, 0), Pair(-5, 21), Pair(1, 17),
        Pair(7, 9), Pair(1, 24), Pair(6, 21), Pair(12, 15), Pair(-30, -30), Pair(12, 54), Pair(-24, -33), Pair(3, 23),
        Pair(2, 30), Pair(0, 25), Pair(-2, 27), Pair(8, 16), Pair(-6, 4), Pair(10, 27), Pair(-17, 0), Pair(4, 32),
        Pair(3, 7), Pair(-23, 54), Pair(6, 29), Pair(-5, 21), Pair(7, 19), Pair(-8, 7), Pair(3, 38), Pair(-12, 0),
        Pair(-67, 46), Pair(5, 23), Pair(2, 27), Pair(-3, 27), Pair(-6, 31), Pair(-6, 25), Pair(-9, 37), Pair(21, -10)
      },
      { // Piece 2
        Pair(4, 39), Pair(26, 40), Pair(52, 7), Pair(-85, 55), Pair(-34, 59), Pair(-7, 32), Pair(-53, 50), Pair(-39, 50),
        Pair(-27, 40), Pair(-34, 47), Pair(6, 30), Pair(-4, 48), Pair(-18, 39), Pair(-58, 60), Pair(24, 23), Pair(-111, 33),
        Pair(-6, 36), Pair(4, 34), Pair(-14, 37), Pair(-15, 31), Pair(-27, 32), Pair(0, 45), Pair(-35, 17), Pair(9, 29),
        Pair(1, 31), Pair(-5, 38), Pair(-4, 37), Pair(-9, 28), Pair(7, 33), Pair(0, 0), Pair(-1, 27), Pair(-12, 23),
        Pair(-14, 45), Pair(9, 17), Pair(-6, 30), Pair(8, 17), Pair(-64, 1), Pair(17, 54), Pair(-46, -3), Pair(4, 14),
        Pair(12, 19), Pair(6, 28), Pair(6, 21), Pair(-4, 9), Pair(-4, 15), Pair(-7, 26), Pair(-6, 19), Pair(-18, 1),
        Pair(-2, 29), Pair(10, 23), Pair(-8, 15), Pair(9, 18), Pair(2, 9), Pair(-2, 26), Pair(-6, 6), Pair(-7, 35),
        Pair(-7, 38), Pair(-20, 23), Pair(4, 21), Pair(11, 12), Pair(3, 16), Pair(-2, 17), Pair(-22, 40), Pair(-27, 48)
      },
      { // Piece 3
        Pair(18, 26), Pair(21, 30), Pair(-13, 38), Pair(17, 31), Pair(26, 27), Pair(3, 37), Pair(-23, 26), Pair(1, 38),
        Pair(9, 27), Pair(16, 19), Pair(11, 25), Pair(-7, 28), Pair(4, 35), Pair(-20, 55), Pair(63, 8), Pair(13, 24),
        Pair(12, 17), Pair(23, 23), Pair(21, 15), Pair(18, 25), Pair(-4, 25), Pair(40, 39), Pair(-15, 32), Pair(13, 27),
        Pair(17, 17), Pair(-1, 28), Pair(4, 28), Pair(7, 29), Pair(13, 21), Pair(0, 0), Pair(7, 11), Pair(10, 26),
        Pair(6, 18), Pair(2, 26), Pair(2, 18), Pair(-21, 30), Pair(-34, -11), Pair(8, 28), Pair(-64, 26), Pair(-4, 14),
        Pair(6, 22), Pair(12, 17), Pair(-2, 24), Pair(11, 13), Pair(-5, 16), Pair(-3, 18), Pair(-1, 19), Pair(-8, 2),
        Pair(1, 31), Pair(15, 14), Pair(6, 21), Pair(15, 14), Pair(-4, 16), Pair(2, 18), Pair(1, 32), Pair(15, 8),
        Pair(6, 27), Pair(0, 33), Pair(6, 27), Pair(5, 27), Pair(4, 22), Pair(2, 22), Pair(-1, 27), Pair(1, 26)
      },
      { // Piece 4
        Pair(4, 30), Pair(35, 41), Pair(19, 23), Pair(-34, 85), Pair(16, 75), Pair(46, 57), Pair(176, -18), Pair(-5, 67),
        Pair(19, 66), Pair(-1, 36), Pair(11, 58), Pair(34, 47), Pair(-8, 82), Pair(9, 82), Pair(-3, 96), Pair(-5, 80),
        Pair(-3, 56), Pair(3, 75), Pair(16, 30), Pair(20, 37), Pair(22, 52), Pair(42, 59), Pair(44, -24), Pair(-10, 101),
        Pair(35, 19), Pair(8, 62), Pair(13, 48), Pair(25, 42), Pair(17, 55), Pair(0, 0), Pair(26, 41), Pair(7, 27),
        Pair(13, 19), Pair(25, 43), Pair(13, 42), Pair(19, 37), Pair(4, -37), Pair(20, 36), Pair(15, 121), Pair(16, 75),
        Pair(3, 85), Pair(1, 47), Pair(3, 48), Pair(-3, 52), Pair(10, 11), Pair(15, 32), Pair(10, 40), Pair(-10, 33),
        Pair(12, 52), Pair(7, 55), Pair(9, 36), Pair(2, 64), Pair(3, 43), Pair(14, 38), Pair(2, 47), Pair(48, 0),
        Pair(-4, 63), Pair(-10, 71), Pair(7, 36), Pair(8, 36), Pair(19, 32), Pair(19, -3), Pair(13, -8), Pair(26, 70)
      },
      { // Piece 5
        Pair(133, -22), Pair(-25, -32), Pair(-42, -49), Pair(19, -57), Pair(5, -33), Pair(48, -104), Pair(-97, 12), Pair(-85, -5),
        Pair(-77, 33), Pair(-43, 0), Pair(116, -37), Pair(-113, -17), Pair(30, -55), Pair(-103, 13), Pair(53, -14), Pair(-98, 50),
        Pair(-6, 3), Pair(126, -15), Pair(-124, 27), Pair(119, -27), Pair(36, -14), Pair(227, -24), Pair(78, -16), Pair(64, -22),
        Pair(-57, 8), Pair(-153, 55), Pair(107, -4), Pair(-66, 12), Pair(94, -45), Pair(0, 0), Pair(151, -51), Pair(-22, 21),
        Pair(137, -19), Pair(19, 15), Pair(71, -7), Pair(0, -1), Pair(41, -120), Pair(-17, -37), Pair(-69, -93), Pair(30, 2),
        Pair(-14, 6), Pair(25, -8), Pair(40, 2), Pair(32, -4), Pair(14, -12), Pair(39, -13), Pair(6, -6), Pair(-41, 25),
        Pair(29, -12), Pair(3, -3), Pair(33, -4), Pair(2, 11), Pair(8, 2), Pair(13, 0), Pair(7, 5), Pair(1, 15),
        Pair(-11, 7), Pair(-9, 16), Pair(-2, 7), Pair(1, 16), Pair(3, 16), Pair(-6, 11), Pair(-5, 8), Pair(1, 16)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, 13), Pair(47, 7), Pair(-2, 17), Pair(-4, 17), Pair(-17, 14), Pair(42, 5), Pair(58, -28), Pair(-25, 18),
        Pair(7, 3), Pair(0, 6), Pair(7, 0), Pair(-6, 9), Pair(2, 6), Pair(-9, 2), Pair(0, 6), Pair(-2, 7),
        Pair(1, 3), Pair(2, 1), Pair(5, 3), Pair(-4, 4), Pair(-2, 2), Pair(-3, 7), Pair(0, 0), Pair(0, 13),
        Pair(4, -2), Pair(8, -6), Pair(2, -1), Pair(-3, 2), Pair(-4, -1), Pair(-2, 8), Pair(0, 0), Pair(5, 9),
        Pair(1, -1), Pair(2, -4), Pair(-1, -1), Pair(-2, -3), Pair(-1, -1), Pair(-3, 3), Pair(-2, 4), Pair(1, 3),
        Pair(3, -5), Pair(5, -9), Pair(-2, -2), Pair(5, -4), Pair(-1, -2), Pair(-3, 2), Pair(4, 0), Pair(-2, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-57, 44), Pair(-56, 11), Pair(-98, 30), Pair(-160, 50), Pair(66, 9), Pair(-104, 43), Pair(6, 29), Pair(-71, -6),
        Pair(-18, 47), Pair(21, 26), Pair(2, 22), Pair(-31, 38), Pair(55, 9), Pair(45, 10), Pair(-99, 35), Pair(8, -29),
        Pair(-8, 13), Pair(19, 2), Pair(14, 12), Pair(17, 27), Pair(24, 6), Pair(-4, 31), Pair(0, 7), Pair(-9, 28),
        Pair(12, 5), Pair(5, 19), Pair(19, 19), Pair(12, 16), Pair(25, 28), Pair(25, 19), Pair(0, 0), Pair(-11, 9),
        Pair(7, 2), Pair(-27, 29), Pair(10, 24), Pair(8, 23), Pair(10, 10), Pair(-16, -33), Pair(28, 59), Pair(-22, 0),
        Pair(-3, 36), Pair(3, 28), Pair(2, 21), Pair(-8, 27), Pair(11, 26), Pair(-1, 5), Pair(13, 33), Pair(-13, -14),
        Pair(5, 46), Pair(-30, 34), Pair(5, 19), Pair(-1, 24), Pair(-8, 25), Pair(4, 20), Pair(-22, -12), Pair(3, 26),
        Pair(-13, 32), Pair(-8, 17), Pair(14, 10), Pair(-7, 18), Pair(14, 2), Pair(7, 16), Pair(-9, 21), Pair(-43, 10)
      },
      { // Piece 2
        Pair(-31, 52), Pair(-12, 18), Pair(-84, 60), Pair(-80, 49), Pair(-18, 41), Pair(-31, 20), Pair(134, 8), Pair(3, 37),
        Pair(7, 43), Pair(36, 18), Pair(-36, 39), Pair(-51, 63), Pair(-73, 48), Pair(-33, 35), Pair(-54, 55), Pair(11, 2),
        Pair(-4, 19), Pair(-15, 40), Pair(-7, 50), Pair(-1, 30), Pair(20, 37), Pair(23, 28), Pair(-18, 28), Pair(-66, -12),
        Pair(-12, 33), Pair(17, 25), Pair(10, 35), Pair(0, 33), Pair(8, 25), Pair(-11, 45), Pair(0, 0), Pair(-12, 41),
        Pair(28, 32), Pair(0, 28), Pair(13, 28), Pair(3, 27), Pair(4, 18), Pair(-14, -8), Pair(23, 56), Pair(-35, -33),
        Pair(-7, 34), Pair(21, 20), Pair(-3, 32), Pair(7, 13), Pair(-2, 20), Pair(-2, 20), Pair(-11, 26), Pair(-4, 25),
        Pair(1, 33), Pair(2, 29), Pair(8, 28), Pair(-15, 23), Pair(5, 23), Pair(-13, 43), Pair(12, 14), Pair(-11, 7),
        Pair(-6, 36), Pair(-2, 30), Pair(-9, 17), Pair(6, 25), Pair(-24, 33), Pair(12, 14), Pair(-31, 28), Pair(4, 27)
      },
      { // Piece 3
        Pair(4, 34), Pair(-20, 46), Pair(-19, 49), Pair(-27, 41), Pair(-21, 39), Pair(-101, 60), Pair(52, 16), Pair(-26, 51),
        Pair(19, 19), Pair(37, 16), Pair(23, 27), Pair(8, 33), Pair(13, 27), Pair(46, 8), Pair(88, 28), Pair(-1, 31),
        Pair(15, 16), Pair(9, 24), Pair(20, 21), Pair(10, 34), Pair(23, 4), Pair(-1, 24), Pair(37, 25), Pair(-16, 39),
        Pair(21, 23), Pair(-1, 26), Pair(11, 23), Pair(33, 24), Pair(49, 19), Pair(30, 3), Pair(0, 0), Pair(-11, 12),
        Pair(0, 24), Pair(0, 31), Pair(10, 22), Pair(-8, 34), Pair(-1, 27), Pair(-9, -2), Pair(-17, 21), Pair(-33, -22),
        Pair(-7, 17), Pair(25, 13), Pair(7, 26), Pair(15, 16), Pair(17, 18), Pair(-3, 27), Pair(-2, 14), Pair(-18, 21),
        Pair(-10, 30), Pair(29, 11), Pair(19, 27), Pair(8, 22), Pair(12, 16), Pair(20, 0), Pair(-1, 21), Pair(43, -24),
        Pair(14, 25), Pair(9, 23), Pair(7, 22), Pair(13, 24), Pair(12, 17), Pair(9, 16), Pair(1, 29), Pair(-6, 17)
      },
      { // Piece 4
        Pair(-11, 51), Pair(17, 13), Pair(-57, 67), Pair(39, -34), Pair(-21, 68), Pair(8, 58), Pair(8, 22), Pair(-25, 58),
        Pair(36, 4), Pair(25, 12), Pair(12, 17), Pair(11, 24), Pair(-45, 43), Pair(26, 36), Pair(-79, 115), Pair(19, 37),
        Pair(27, 6), Pair(32, 1), Pair(29, 4), Pair(5, 32), Pair(-43, 73), Pair(12, 30), Pair(-27, 69), Pair(7, -26),
        Pair(14, 19), Pair(9, 49), Pair(0, 50), Pair(-6, 44), Pair(6, 37), Pair(-2, 46), Pair(0, 0), Pair(-24, 49),
        Pair(4, 31), Pair(-18, 69), Pair(1, 55), Pair(1, 58), Pair(35, 3), Pair(-7, 59), Pair(18, 1), Pair(5, -7),
        Pair(1, 44), Pair(1, 28), Pair(0, 57), Pair(9, 39), Pair(-4, 18), Pair(4, 16), Pair(4, 15), Pair(-19, 45),
        Pair(0, 35), Pair(-8, 32), Pair(10, 9), Pair(9, 15), Pair(12, 23), Pair(-3, 25), Pair(10, 19), Pair(4, -8),
        Pair(16, -7), Pair(5, 25), Pair(19, 0), Pair(12, 11), Pair(10, 16), Pair(-27, 71), Pair(-66, 71), Pair(35, 50)
      },
      { // Piece 5
        Pair(-17, 27), Pair(-29, -40), Pair(50, -111), Pair(77, -54), Pair(56, -41), Pair(-4, -13), Pair(-32, -28), Pair(-21, -180),
        Pair(93, -33), Pair(-46, -13), Pair(217, -70), Pair(160, -31), Pair(280, -107), Pair(101, -76), Pair(96, -18), Pair(53, -9),
        Pair(163, -29), Pair(36, -25), Pair(46, -26), Pair(-51, 0), Pair(11, 8), Pair(21, -24), Pair(175, -31), Pair(-80, -36),
        Pair(105, -36), Pair(-17, 4), Pair(11, -3), Pair(43, -17), Pair(-71, -6), Pair(92, -45), Pair(0, 0), Pair(-8, -18),
        Pair(107, -33), Pair(29, -25), Pair(42, -17), Pair(-44, 2), Pair(-28, 0), Pair(-139, -54), Pair(-33, -49), Pair(-177, -64),
        Pair(19, -14), Pair(32, -3), Pair(15, -12), Pair(33, -11), Pair(-30, -2), Pair(41, -19), Pair(11, -18), Pair(-38, -6),
        Pair(13, 2), Pair(-36, -4), Pair(-6, -9), Pair(30, -11), Pair(-5, 3), Pair(17, 1), Pair(-8, 2), Pair(4, -2),
        Pair(-2, -43), Pair(3, -21), Pair(1, -12), Pair(-33, 18), Pair(-1, 14), Pair(1, 0), Pair(-5, 3), Pair(-6, -4)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(28, -4), Pair(-18, 18), Pair(41, 2), Pair(3, 11), Pair(1, 4), Pair(4, 13), Pair(-46, 10), Pair(16, 78),
        Pair(14, 2), Pair(-8, 4), Pair(4, 4), Pair(12, 0), Pair(-7, 10), Pair(-10, 6), Pair(-12, 3), Pair(12, -18),
        Pair(4, -1), Pair(2, 2), Pair(3, 0), Pair(-2, 0), Pair(-6, -2), Pair(-4, 2), Pair(-10, -2), Pair(0, 0),
        Pair(3, -4), Pair(3, -3), Pair(3, -3), Pair(-1, -2), Pair(2, -3), Pair(-2, 1), Pair(-6, -8), Pair(0, 0),
        Pair(2, -4), Pair(1, -7), Pair(-1, -4), Pair(-2, -4), Pair(1, -3), Pair(-1, -1), Pair(-3, -4), Pair(3, 3),
        Pair(2, -3), Pair(2, -3), Pair(-2, -6), Pair(3, -8), Pair(0, -3), Pair(4, -3), Pair(0, -5), Pair(0, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-93, 38), Pair(-69, -2), Pair(23, 10), Pair(60, -24), Pair(102, -2), Pair(9, 55), Pair(53, -12), Pair(17, 8),
        Pair(32, -29), Pair(4, -3), Pair(-29, 13), Pair(55, 3), Pair(11, 16), Pair(15, 30), Pair(-6, -11), Pair(44, 35),
        Pair(59, -21), Pair(15, -10), Pair(8, 12), Pair(36, -7), Pair(26, 21), Pair(38, 4), Pair(-29, 33), Pair(19, 8),
        Pair(30, -6), Pair(5, 9), Pair(18, 11), Pair(23, 0), Pair(29, 9), Pair(22, 21), Pair(11, 19), Pair(0, 0),
        Pair(2, 6), Pair(13, 4), Pair(10, 6), Pair(8, 24), Pair(25, 11), Pair(36, -3), Pair(2, -11), Pair(16, 56),
        Pair(3, -1), Pair(-4, 15), Pair(13, 12), Pair(7, 13), Pair(14, 11), Pair(10, 18), Pair(14, 6), Pair(21, 31),
        Pair(-2, -15), Pair(7, 6), Pair(1, 5), Pair(6, 11), Pair(7, 23), Pair(1, 17), Pair(1, 23), Pair(0, -21),
        Pair(-16, -72), Pair(-3, 5), Pair(1, -2), Pair(26, -19), Pair(12, 19), Pair(-9, 23), Pair(8, 38), Pair(27, -63)
      },
      { // Piece 2
        Pair(-21, 45), Pair(47, 37), Pair(-13, 51), Pair(-33, 49), Pair(-88, 68), Pair(20, 24), Pair(-50, 63), Pair(47, 0),
        Pair(0, 20), Pair(35, 22), Pair(-12, 47), Pair(-43, 75), Pair(-28, 53), Pair(-27, 63), Pair(-26, 33), Pair(62, 22),
        Pair(-25, 45), Pair(-30, 26), Pair(-24, 50), Pair(-18, 40), Pair(13, 33), Pair(-12, 46), Pair(-25, 56), Pair(23, 21),
        Pair(-14, 18), Pair(-1, 43), Pair(1, 28), Pair(4, 38), Pair(27, 20), Pair(4, 44), Pair(1, 33), Pair(0, 0),
        Pair(-14, 33), Pair(-5, 18), Pair(-9, 40), Pair(5, 25), Pair(20, 24), Pair(9, 20), Pair(-60, -46), Pair(14, 62),
        Pair(0, 30), Pair(11, 39), Pair(7, 19), Pair(7, 26), Pair(8, 11), Pair(-3, 34), Pair(-4, 25), Pair(0, 41),
        Pair(13, 19), Pair(6, 17), Pair(-11, 29), Pair(-4, 21), Pair(-2, 31), Pair(2, 18), Pair(12, 25), Pair(10, 3),
        Pair(1, 26), Pair(4, 27), Pair(1, 10), Pair(5, 34), Pair(-19, 26), Pair(1, 27), Pair(-2, 19), Pair(13, 7)
      },
      { // Piece 3
        Pair(12, 31), Pair(8, 39), Pair(-25, 48), Pair(25, 35), Pair(-10, 38), Pair(65, 28), Pair(-35, 56), Pair(43, 41),
        Pair(11, 28), Pair(6, 35), Pair(25, 32), Pair(31, 21), Pair(23, 30), Pair(-3, 32), Pair(58, 25), Pair(62, 41),
        Pair(15, 27), Pair(12, 29), Pair(14, 33), Pair(0, 32), Pair(-8, 30), Pair(-16, 39), Pair(25, 24), Pair(44, 44),
        Pair(20, 35), Pair(17, 29), Pair(28, 27), Pair(30, 18), Pair(32, 27), Pair(-6, 50), Pair(22, 41), Pair(0, 0),
        Pair(-2, 40), Pair(21, 27), Pair(15, 25), Pair(-4, 21), Pair(10, 24), Pair(-6, 29), Pair(20, -95), Pair(-16, 45),
        Pair(-4, 23), Pair(31, 26), Pair(14, 23), Pair(20, 24), Pair(6, 17), Pair(-3, 32), Pair(0, 29), Pair(-21, 22),
        Pair(22, 11), Pair(17, 17), Pair(9, 24), Pair(9, 30), Pair(12, 28), Pair(13, 18), Pair(27, 5), Pair(-18, 34),
        Pair(8, 30), Pair(-1, 44), Pair(6, 33), Pair(2, 34), Pair(6, 27), Pair(8, 27), Pair(-2, 36), Pair(-12, 35)
      },
      { // Piece 4
        Pair(37, 31), Pair(9, 34), Pair(46, -16), Pair(9, 1), Pair(6, 22), Pair(8, 69), Pair(22, 59), Pair(68, 10),
        Pair(33, 6), Pair(-4, 43), Pair(36, 17), Pair(-12, 68), Pair(17, 44), Pair(-36, 90), Pair(-24, 37), Pair(107, 63),
        Pair(5, 40), Pair(12, 26), Pair(5, 30), Pair(32, 18), Pair(-8, 41), Pair(54, 31), Pair(-16, 65), Pair(9, 72),
        Pair(-6, 32), Pair(12, 10), Pair(16, 32), Pair(4, 57), Pair(16, 44), Pair(3, 52), Pair(5, 46), Pair(0, 0),
        Pair(12, 23), Pair(0, 44), Pair(-1, 39), Pair(15, 40), Pair(9, 60), Pair(13, 29), Pair(44, -40), Pair(12, 27),
        Pair(-11, 50), Pair(6, 26), Pair(14, 28), Pair(7, 43), Pair(18, 13), Pair(5, 50), Pair(8, 20), Pair(1, -6),
        Pair(-16, 85), Pair(8, 33), Pair(5, 25), Pair(8, 16), Pair(8, 32), Pair(22, 12), Pair(30, -17), Pair(-31, 127),
        Pair(8, 17), Pair(11, 24), Pair(8, 11), Pair(8, 20), Pair(18, -3), Pair(-7, 64), Pair(22, 30), Pair(-12, 51)
      },
      { // Piece 5
        Pair(-56, -107), Pair(11, -103), Pair(246, -52), Pair(-119, -38), Pair(24, -14), Pair(77, -31), Pair(-58, -36), Pair(46, 128),
        Pair(-5, -26), Pair(-13, -5), Pair(35, -10), Pair(-57, -31), Pair(-48, -22), Pair(62, -46), Pair(-6, -30), Pair(-9, -24),
        Pair(29, -3), Pair(117, -21), Pair(95, -15), Pair(78, -26), Pair(60, -13), Pair(120, -39), Pair(5, 7), Pair(47, -30),
        Pair(77, -36), Pair(56, -23), Pair(29, -16), Pair(34, -10), Pair(27, -10), Pair(-51, -1), Pair(56, -42), Pair(0, 0),
        Pair(-3, -9), Pair(113, -32), Pair(74, -25), Pair(29, -6), Pair(-25, 8), Pair(1, 2), Pair(-236, -9), Pair(132, -66),
        Pair(-18, 1), Pair(44, -30), Pair(73, -27), Pair(48, -11), Pair(44, -7), Pair(-22, 7), Pair(24, 5), Pair(-4, 9),
        Pair(23, -25), Pair(7, -18), Pair(21, -19), Pair(4, 3), Pair(2, 5), Pair(-6, 14), Pair(-2, 11), Pair(-3, 6),
        Pair(2, -27), Pair(-11, -15), Pair(-9, -13), Pair(9, -1), Pair(-3, 13), Pair(-14, 18), Pair(1, 6), Pair(0, 3)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(103, -60), Pair(-13, 12), Pair(-38, 18), Pair(12, -1), Pair(43, -7), Pair(13, 14), Pair(-1, 2), Pair(-21, 14),
        Pair(0, 0), Pair(-15, 6), Pair(5, 3), Pair(-2, 6), Pair(-1, 12), Pair(-9, 15), Pair(3, 18), Pair(-10, 14),
        Pair(-8, -10), Pair(-6, -2), Pair(-2, -1), Pair(0, 5), Pair(-1, 6), Pair(-6, 10), Pair(-2, 6), Pair(-1, 8),
        Pair(-4, -4), Pair(-7, 0), Pair(1, 0), Pair(-3, 2), Pair(-3, 4), Pair(-3, 5), Pair(-1, 1), Pair(-1, 4),
        Pair(0, 0), Pair(-5, -1), Pair(1, -1), Pair(-1, -2), Pair(-2, 3), Pair(-4, 2), Pair(-4, -1), Pair(-2, 0),
        Pair(6, -2), Pair(-2, -2), Pair(0, -2), Pair(0, -4), Pair(-2, 1), Pair(-4, -2), Pair(-2, -2), Pair(-3, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, 14), Pair(119, 9), Pair(-54, 35), Pair(100, -5), Pair(-24, 40), Pair(-17, 54), Pair(130, -30), Pair(-18, 18),
        Pair(-10, -21), Pair(6, 43), Pair(27, -1), Pair(22, 25), Pair(44, 3), Pair(28, -9), Pair(18, -2), Pair(8, -6),
        Pair(0, 0), Pair(12, 29), Pair(8, 34), Pair(6, 26), Pair(-10, 31), Pair(56, -8), Pair(56, 1), Pair(23, 39),
        Pair(17, 60), Pair(-33, -5), Pair(8, 28), Pair(6, 29), Pair(12, 25), Pair(27, 16), Pair(26, 17), Pair(34, 6),
        Pair(-4, 29), Pair(-23, 45), Pair(5, 25), Pair(4, 24), Pair(13, 22), Pair(9, 21), Pair(15, 18), Pair(14, 25),
        Pair(-14, 0), Pair(1, 31), Pair(-12, 33), Pair(10, 24), Pair(6, 14), Pair(4, 22), Pair(8, 27), Pair(12, 15),
        Pair(4, 44), Pair(11, 18), Pair(5, 16), Pair(4, 20), Pair(4, 16), Pair(12, 6), Pair(4, -6), Pair(-6, 51),
        Pair(-103, 109), Pair(0, 21), Pair(-1, 5), Pair(21, 15), Pair(5, 17), Pair(8, 24), Pair(-2, 8), Pair(-20, 35)
      },
      { // Piece 2
        Pair(16, 32), Pair(-27, 68), Pair(26, 68), Pair(-22, 59), Pair(28, 24), Pair(-13, 72), Pair(50, 48), Pair(-43, 20),
        Pair(10, 43), Pair(-7, 58), Pair(-21, 59), Pair(-3, 57), Pair(-43, 61), Pair(-37, 79), Pair(29, 43), Pair(15, 44),
        Pair(0, 0), Pair(-8, 52), Pair(-13, 63), Pair(6, 52), Pair(-13, 61), Pair(14, 57), Pair(7, 56), Pair(15, 34),
        Pair(29, 64), Pair(-24, -15), Pair(10, 44), Pair(0, 60), Pair(5, 48), Pair(-4, 61), Pair(11, 47), Pair(7, 31),
        Pair(-14, 60), Pair(-27, 47), Pair(-8, 51), Pair(-6, 49), Pair(3, 46), Pair(13, 42), Pair(-6, 49), Pair(17, 45),
        Pair(2, 55), Pair(6, 46), Pair(-3, 45), Pair(3, 34), Pair(4, 33), Pair(1, 31), Pair(2, 29), Pair(6, 39),
        Pair(3, 49), Pair(3, 50), Pair(-2, 50), Pair(5, 38), Pair(-1, 38), Pair(-2, 31), Pair(10, 28), Pair(7, 35),
        Pair(12, 37), Pair(10, 52), Pair(2, 50), Pair(-12, 38), Pair(-14, 38), Pair(-2, 42), Pair(15, 44), Pair(7, 52)
      },
      { // Piece 3
        Pair(32, 79), Pair(-53, 100), Pair(6, 72), Pair(-33, 86), Pair(-1, 68), Pair(-30, 83), Pair(53, 72), Pair(31, 64),
        Pair(53, 71), Pair(-7, 77), Pair(0, 85), Pair(-11, 82), Pair(2, 75), Pair(-8, 84), Pair(51, 49), Pair(-11, 94),
        Pair(0, 0), Pair(-5, 84), Pair(2, 83), Pair(8, 72), Pair(2, 80), Pair(-13, 85), Pair(-5, 84), Pair(-33, 82),
        Pair(5, 72), Pair(127, -194), Pair(-11, 70), Pair(-10, 83), Pair(0, 75), Pair(6, 72), Pair(3, 63), Pair(15, 60),
        Pair(-2, 57), Pair(-36, 88), Pair(-15, 69), Pair(-14, 61), Pair(3, 60), Pair(5, 67), Pair(4, 52), Pair(1, 71),
        Pair(-13, 52), Pair(-15, 73), Pair(-12, 73), Pair(-7, 67), Pair(-11, 64), Pair(0, 59), Pair(2, 64), Pair(12, 50),
        Pair(-8, 57), Pair(-6, 78), Pair(-13, 63), Pair(-8, 55), Pair(-2, 59), Pair(6, 58), Pair(9, 48), Pair(-6, 67),
        Pair(-9, 57), Pair(-11, 61), Pair(-5, 55), Pair(-6, 62), Pair(-3, 62), Pair(0, 58), Pair(5, 66), Pair(3, 75)
      },
      { // Piece 4
        Pair(11, 148), Pair(-20, 154), Pair(13, 136), Pair(-11, 149), Pair(33, 142), Pair(-77, 205), Pair(58, 48), Pair(142, 15),
        Pair(18, 152), Pair(24, 154), Pair(7, 131), Pair(-3, 135), Pair(12, 160), Pair(1, 111), Pair(-28, 97), Pair(55, 109),
        Pair(0, 0), Pair(37, 125), Pair(-6, 179), Pair(12, 162), Pair(9, 158), Pair(46, 74), Pair(53, 79), Pair(42, 82),
        Pair(16, 120), Pair(36, 4), Pair(44, 75), Pair(2, 136), Pair(7, 137), Pair(22, 134), Pair(35, 109), Pair(27, 106),
        Pair(20, 75), Pair(16, 88), Pair(10, 119), Pair(17, 116), Pair(27, 97), Pair(26, 96), Pair(42, 68), Pair(49, 88),
        Pair(7, 121), Pair(11, 90), Pair(10, 112), Pair(18, 96), Pair(15, 100), Pair(16, 114), Pair(23, 101), Pair(33, 79),
        Pair(4, 89), Pair(12, 86), Pair(13, 93), Pair(11, 93), Pair(19, 95), Pair(14, 81), Pair(14, 98), Pair(25, 64),
        Pair(13, 109), Pair(11, 109), Pair(13, 108), Pair(11, 97), Pair(16, 92), Pair(18, 92), Pair(11, 112), Pair(-21, 63)
      },
      { // Piece 5
        Pair(-3, 69), Pair(60, 166), Pair(122, -24), Pair(128, 8), Pair(-17, -55), Pair(88, -23), Pair(62, 36), Pair(-39, -26),
        Pair(-44, -7), Pair(-84, -30), Pair(122, -24), Pair(75, -30), Pair(-31, 44), Pair(-53, -21), Pair(-67, -17), Pair(-88, 60),
        Pair(0, 0), Pair(-106, -24), Pair(-28, 7), Pair(65, 0), Pair(35, -20), Pair(-1, 1), Pair(-58, 14), Pair(-84, 9),
        Pair(-11, -64), Pair(-63, -63), Pair(-135, 9), Pair(44, 2), Pair(13, 2), Pair(79, -6), Pair(-3, 7), Pair(12, 3),
        Pair(9, -25), Pair(-19, -6), Pair(31, -27), Pair(32, -7), Pair(45, -5), Pair(-7, 8), Pair(66, -11), Pair(21, 3),
        Pair(16, -31), Pair(-12, -9), Pair(-22, -1), Pair(4, -6), Pair(15, -7), Pair(31, -5), Pair(-12, 13), Pair(-10, 6),
        Pair(-6, -10), Pair(-9, -4), Pair(-10, 10), Pair(4, 7), Pair(13, 0), Pair(4, 2), Pair(-4, 3), Pair(0, 12),
        Pair(10, 0), Pair(16, -3), Pair(12, 12), Pair(10, -12), Pair(5, -2), Pair(-10, 8), Pair(-1, -3), Pair(-3, 3)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 21), Pair(-7, 21), Pair(5, 1), Pair(10, 1), Pair(12, 13), Pair(25, 12), Pair(21, 12), Pair(-4, 20),
        Pair(2, 9), Pair(0, 0), Pair(1, -2), Pair(4, 3), Pair(0, 10), Pair(3, 9), Pair(4, 14), Pair(-7, 18),
        Pair(5, 4), Pair(-10, -11), Pair(-12, 24), Pair(1, 4), Pair(3, 6), Pair(-1, 6), Pair(-3, 11), Pair(-1, 7),
        Pair(5, 2), Pair(-2, -4), Pair(0, 7), Pair(0, 4), Pair(-2, 3), Pair(-2, 7), Pair(-2, 3), Pair(-2, 6),
        Pair(2, 0), Pair(0, 0), Pair(2, 4), Pair(-1, 0), Pair(-2, 0), Pair(-5, 0), Pair(-4, 1), Pair(-2, 3),
        Pair(0, -2), Pair(4, 1), Pair(0, 2), Pair(2, -2), Pair(-1, 1), Pair(-6, -1), Pair(-4, -3), Pair(-1, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-48, 12), Pair(31, 15), Pair(-49, 45), Pair(29, 19), Pair(1, 59), Pair(57, 41), Pair(132, 0), Pair(-55, 37),
        Pair(-11, 26), Pair(-33, -34), Pair(6, 44), Pair(26, 14), Pair(7, 45), Pair(27, 28), Pair(5, 19), Pair(-2, 51),
        Pair(-8, -14), Pair(0, 0), Pair(-1, 29), Pair(2, 32), Pair(19, 16), Pair(28, 39), Pair(33, 12), Pair(44, 27),
        Pair(-28, 31), Pair(0, 64), Pair(-67, 17), Pair(-4, 31), Pair(6, 26), Pair(17, 36), Pair(13, 21), Pair(19, 16),
        Pair(-22, 5), Pair(2, 41), Pair(-19, 29), Pair(1, 31), Pair(1, 28), Pair(1, 31), Pair(22, 20), Pair(14, 31),
        Pair(2, 21), Pair(-20, 1), Pair(-3, 34), Pair(-9, 30), Pair(-3, 29), Pair(3, 27), Pair(9, 25), Pair(4, 31),
        Pair(10, 23), Pair(-9, 31), Pair(9, 25), Pair(1, 20), Pair(4, 34), Pair(8, 20), Pair(3, 37), Pair(9, 45),
        Pair(55, -65), Pair(4, 28), Pair(-3, 22), Pair(-12, 26), Pair(8, 32), Pair(10, 21), Pair(2, 55), Pair(-40, 119)
      },
      { // Piece 2
        Pair(4, 48), Pair(-79, 66), Pair(-136, 56), Pair(-55, 60), Pair(-146, 76), Pair(-112, 87), Pair(-36, 57), Pair(32, 69),
        Pair(-114, -15), Pair(-29, 51), Pair(-18, 47), Pair(-15, 72), Pair(-15, 52), Pair(26, 53), Pair(3, 40), Pair(17, 52),
        Pair(17, 48), Pair(0, 0), Pair(-9, 51), Pair(-18, 49), Pair(-5, 61), Pair(1, 56), Pair(12, 45), Pair(14, 32),
        Pair(15, -36), Pair(-1, 71), Pair(-100, -2), Pair(-6, 53), Pair(-4, 50), Pair(-2, 61), Pair(8, 43), Pair(11, 41),
        Pair(-17, 39), Pair(-18, 29), Pair(-17, 48), Pair(-20, 38), Pair(5, 31), Pair(1, 35), Pair(0, 42), Pair(14, 29),
        Pair(-2, 23), Pair(1, 36), Pair(-10, 46), Pair(-3, 45), Pair(-5, 31), Pair(-1, 38), Pair(11, 28), Pair(7, 37),
        Pair(0, 61), Pair(6, 23), Pair(-7, 46), Pair(-3, 26), Pair(-1, 33), Pair(-6, 25), Pair(6, 30), Pair(11, 7),
        Pair(-11, 59), Pair(5, 46), Pair(3, 33), Pair(-3, 45), Pair(-14, 32), Pair(3, 32), Pair(-17, 12), Pair(9, 40)
      },
      { // Piece 3
        Pair(-6, 62), Pair(-58, 69), Pair(-14, 57), Pair(-34, 73), Pair(42, 42), Pair(-10, 63), Pair(-35, 81), Pair(62, 33),
        Pair(-5, 60), Pair(-8, 68), Pair(-15, 65), Pair(-6, 64), Pair(-8, 69), Pair(43, 46), Pair(-11, 63), Pair(0, 64),
        Pair(-20, 56), Pair(0, 0), Pair(-6, 65), Pair(-1, 64), Pair(5, 60), Pair(33, 43), Pair(21, 38), Pair(26, 39),
        Pair(43, -14), Pair(-11, 37), Pair(-58, 48), Pair(-15, 58), Pair(-17, 53), Pair(-3, 43), Pair(-3, 53), Pair(0, 50),
        Pair(-8, 31), Pair(-18, 43), Pair(-17, 42), Pair(-20, 53), Pair(4, 37), Pair(-8, 58), Pair(1, 49), Pair(30, 44),
        Pair(-19, 50), Pair(-12, 44), Pair(-18, 51), Pair(-9, 48), Pair(-7, 45), Pair(-12, 48), Pair(-1, 37), Pair(11, 62),
        Pair(-2, 46), Pair(-5, 29), Pair(-9, 51), Pair(1, 40), Pair(-7, 47), Pair(0, 52), Pair(-5, 51), Pair(6, 61),
        Pair(-10, 46), Pair(-9, 36), Pair(-11, 43), Pair(-5, 46), Pair(-4, 44), Pair(-2, 48), Pair(11, 49), Pair(8, 55)
      },
      { // Piece 4
        Pair(45, 59), Pair(38, 94), Pair(-11, 115), Pair(39, 55), Pair(-20, 131), Pair(54, 60), Pair(-85, 168), Pair(39, 65),
        Pair(9, 69), Pair(17, 91), Pair(18, 79), Pair(18, 88), Pair(0, 93), Pair(23, 88), Pair(-5, 78), Pair(-32, 128),
        Pair(23, 10), Pair(0, 0), Pair(-8, 121), Pair(38, 63), Pair(62, 37), Pair(34, 63), Pair(3, 82), Pair(34, 64),
        Pair(-23, 306), Pair(9, 85), Pair(-14, 209), Pair(32, 52), Pair(34, 67), Pair(23, 90), Pair(44, 75), Pair(30, 56),
        Pair(15, 47), Pair(5, 66), Pair(8, 67), Pair(7, 81), Pair(5, 84), Pair(16, 86), Pair(23, 71), Pair(30, 84),
        Pair(17, 66), Pair(11, 78), Pair(10, 57), Pair(6, 67), Pair(21, 62), Pair(11, 72), Pair(25, 65), Pair(24, 76),
        Pair(27, 58), Pair(13, 61), Pair(10, 62), Pair(12, 61), Pair(10, 76), Pair(7, 74), Pair(24, 58), Pair(-20, 112),
        Pair(8, 94), Pair(14, 96), Pair(14, 70), Pair(12, 66), Pair(17, 65), Pair(10, 56), Pair(8, 13), Pair(5, 116)
      },
      { // Piece 5
        Pair(-58, -348), Pair(-62, -89), Pair(-18, 13), Pair(-33, -30), Pair(106, 92), Pair(42, -1), Pair(-13, 64), Pair(29, -45),
        Pair(-3, 2), Pair(57, -57), Pair(25, -38), Pair(113, -11), Pair(-227, 36), Pair(-136, -23), Pair(3, 9), Pair(-71, 35),
        Pair(-191, -2), Pair(0, 0), Pair(10, -29), Pair(126, -16), Pair(-22, 20), Pair(55, -6), Pair(-5, -2), Pair(25, 2),
        Pair(0, 0), Pair(50, -100), Pair(0, 60), Pair(-55, -2), Pair(-54, 4), Pair(33, 2), Pair(19, -3), Pair(41, -15),
        Pair(97, -79), Pair(-33, -46), Pair(120, -36), Pair(-20, -15), Pair(18, -13), Pair(44, -8), Pair(12, 3), Pair(9, -1),
        Pair(76, -37), Pair(56, -44), Pair(-17, -7), Pair(27, -13), Pair(5, -3), Pair(6, 0), Pair(4, 1), Pair(21, -5),
        Pair(-19, 4), Pair(18, -23), Pair(17, -16), Pair(0, 2), Pair(15, -3), Pair(16, -3), Pair(2, -3), Pair(1, 2),
        Pair(41, -50), Pair(12, -12), Pair(23, -6), Pair(19, -1), Pair(0, 8), Pair(17, -8), Pair(3, -1), Pair(-1, -2)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 34), Pair(-14, 15), Pair(-28, 52), Pair(-10, -3), Pair(23, 10), Pair(9, -1), Pair(-10, 10), Pair(-16, 25),
        Pair(2, 7), Pair(-15, 7), Pair(0, 0), Pair(6, -3), Pair(4, 8), Pair(4, 7), Pair(15, 12), Pair(-10, 12),
        Pair(-4, 2), Pair(-2, 4), Pair(-11, -11), Pair(1, 29), Pair(-2, 5), Pair(-1, 7), Pair(2, 6), Pair(1, 8),
        Pair(-1, 2), Pair(2, -5), Pair(-2, -5), Pair(0, 5), Pair(1, 3), Pair(-1, 4), Pair(2, 2), Pair(-1, 4),
        Pair(-1, 2), Pair(-1, -4), Pair(0, 0), Pair(2, 3), Pair(-1, 2), Pair(-5, 3), Pair(0, 0), Pair(-2, 3),
        Pair(0, 2), Pair(-4, -7), Pair(3, 1), Pair(-1, 3), Pair(3, -3), Pair(-4, -1), Pair(1, -1), Pair(-1, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(37, 43), Pair(108, 25), Pair(98, -19), Pair(-51, 48), Pair(18, -13), Pair(242, -11), Pair(14, 69), Pair(-37, 22),
        Pair(-60, -59), Pair(0, 28), Pair(24, -17), Pair(40, 32), Pair(50, -35), Pair(22, 28), Pair(52, 7), Pair(31, 25),
        Pair(19, 22), Pair(-6, 21), Pair(0, 0), Pair(-2, 38), Pair(-8, 38), Pair(-12, 40), Pair(25, 15), Pair(11, 3),
        Pair(-7, 27), Pair(5, 3), Pair(6, 70), Pair(-60, 7), Pair(9, 26), Pair(12, 18), Pair(13, 29), Pair(15, 26),
        Pair(6, 27), Pair(-22, 13), Pair(-2, 42), Pair(-19, 31), Pair(7, 34), Pair(-1, 19), Pair(2, 32), Pair(12, 37),
        Pair(-14, 8), Pair(-1, 42), Pair(-12, 15), Pair(6, 37), Pair(-9, 22), Pair(6, 31), Pair(4, 24), Pair(3, 47),
        Pair(-5, 77), Pair(1, 48), Pair(0, 40), Pair(3, 34), Pair(6, 23), Pair(6, 18), Pair(3, 39), Pair(15, 10),
        Pair(16, 17), Pair(1, 33), Pair(-2, 21), Pair(7, 13), Pair(5, 28), Pair(15, 23), Pair(10, 38), Pair(4, 39)
      },
      { // Piece 2
        Pair(-159, -17), Pair(-52, 28), Pair(30, 51), Pair(-111, 71), Pair(-17, -1), Pair(-19, 72), Pair(81, 9), Pair(61, 17),
        Pair(-7, 35), Pair(-104, 13), Pair(-6, 41), Pair(-17, 36), Pair(29, 45), Pair(7, 57), Pair(9, 42), Pair(2, -8),
        Pair(-4, 22), Pair(2, 40), Pair(0, 0), Pair(-4, 34), Pair(-11, 41), Pair(46, 37), Pair(14, 42), Pair(11, 32),
        Pair(14, 25), Pair(-10, 5), Pair(22, 59), Pair(-7, -74), Pair(5, 27), Pair(8, 32), Pair(6, 42), Pair(2, 23),
        Pair(-12, -6), Pair(-15, 33), Pair(-14, 22), Pair(-19, 33), Pair(1, 19), Pair(4, 38), Pair(-22, 46), Pair(7, 41),
        Pair(5, 27), Pair(-8, 29), Pair(5, 38), Pair(0, 19), Pair(4, 37), Pair(-6, 14), Pair(13, 16), Pair(-1, 12),
        Pair(-20, 39), Pair(13, 22), Pair(-1, 31), Pair(11, 31), Pair(2, 10), Pair(15, 24), Pair(-1, -1), Pair(15, 37),
        Pair(17, 38), Pair(27, 14), Pair(12, 38), Pair(2, 25), Pair(-2, 33), Pair(-1, 12), Pair(-2, 12), Pair(-16, 33)
      },
      { // Piece 3
        Pair(9, 32), Pair(9, 35), Pair(79, 16), Pair(4, 41), Pair(39, 30), Pair(1, 44), Pair(-84, 71), Pair(-25, 57),
        Pair(0, 44), Pair(7, 33), Pair(16, 31), Pair(-17, 44), Pair(17, 39), Pair(43, 23), Pair(37, 18), Pair(24, 20),
        Pair(-1, 39), Pair(-6, 25), Pair(0, 0), Pair(16, 32), Pair(15, 33), Pair(12, 40), Pair(-9, 51), Pair(-29, 41),
        Pair(-2, 26), Pair(-19, -46), Pair(21, 18), Pair(64, -75), Pair(-11, 55), Pair(3, 28), Pair(26, 17), Pair(-10, 40),
        Pair(12, 16), Pair(-18, 37), Pair(-1, 14), Pair(-15, 23), Pair(-4, 32), Pair(-3, 43), Pair(7, 35), Pair(3, 37),
        Pair(9, 16), Pair(-12, 29), Pair(-11, 26), Pair(-6, 34), Pair(-11, 40), Pair(0, 32), Pair(-10, 30), Pair(-3, 44),
        Pair(5, 26), Pair(7, 19), Pair(-6, 31), Pair(-7, 30), Pair(-3, 41), Pair(12, 12), Pair(11, 31), Pair(-4, 21),
        Pair(0, 28), Pair(-2, 28), Pair(0, 20), Pair(-5, 25), Pair(1, 32), Pair(0, 33), Pair(11, 22), Pair(8, 39)
      },
      { // Piece 4
        Pair(7, 67), Pair(20, 82), Pair(116, -30), Pair(-26, 126), Pair(45, 61), Pair(45, 51), Pair(99, 28), Pair(24, 69),
        Pair(-2, 116), Pair(0, 68), Pair(1, 116), Pair(40, 36), Pair(-11, 136), Pair(-8, 86), Pair(31, 68), Pair(-6, 82),
        Pair(19, 29), Pair(22, 56), Pair(0, 0), Pair(23, 33), Pair(4, 101), Pair(43, 35), Pair(32, 84), Pair(29, 57),
        Pair(16, 69), Pair(-40, 141), Pair(37, 40), Pair(-51, 235), Pair(23, 54), Pair(14, 90), Pair(46, 25), Pair(16, 78),
        Pair(26, 21), Pair(1, 77), Pair(16, 58), Pair(10, 55), Pair(27, 34), Pair(26, 52), Pair(22, 48), Pair(22, 94),
        Pair(6, 62), Pair(6, 49), Pair(27, 42), Pair(11, 58), Pair(19, 36), Pair(14, 51), Pair(23, 45), Pair(37, -2),
        Pair(3, 55), Pair(12, 49), Pair(19, 47), Pair(12, 53), Pair(11, 63), Pair(15, 47), Pair(16, 24), Pair(-14, 115),
        Pair(10, 63), Pair(10, 76), Pair(22, 43), Pair(14, 56), Pair(9, 75), Pair(14, 60), Pair(38, -26), Pair(6, 31)
      },
      { // Piece 5
        Pair(1, 27), Pair(23, 47), Pair(-123, -20), Pair(3, -64), Pair(68, 38), Pair(46, 61), Pair(-6, 2), Pair(28, -40),
        Pair(-17, -65), Pair(-25, -48), Pair(81, -48), Pair(116, -82), Pair(-36, 23), Pair(58, 1), Pair(-51, -12), Pair(-55, 56),
        Pair(-83, -24), Pair(-60, -35), Pair(0, 0), Pair(283, -98), Pair(98, 14), Pair(-40, 27), Pair(-166, 27), Pair(-43, 17),
        Pair(-13, -7), Pair(0, 0), Pair(20, -72), Pair(0, 0), Pair(-191, 15), Pair(-23, 21), Pair(47, 9), Pair(37, 9),
        Pair(-85, -11), Pair(49, -27), Pair(41, -50), Pair(50, -32), Pair(-56, 1), Pair(15, 11), Pair(22, 6), Pair(0, 15),
        Pair(69, 1), Pair(-14, -8), Pair(-28, 0), Pair(31, -10), Pair(15, 1), Pair(-17, 13), Pair(-18, 13), Pair(52, -9),
        Pair(-31, 20), Pair(12, -19), Pair(1, -5), Pair(-10, 1), Pair(5, 7), Pair(3, 13), Pair(2, 6), Pair(3, 4),
        Pair(12, 6), Pair(-7, -4), Pair(-7, 8), Pair(13, 4), Pair(0, 14), Pair(6, 6), Pair(0, 7), Pair(6, 9)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(2, 18), Pair(17, 11), Pair(2, 23), Pair(11, -27), Pair(-47, 40), Pair(-27, 21), Pair(-28, 37), Pair(19, 23),
        Pair(1, 12), Pair(-10, 12), Pair(-6, 3), Pair(0, 0), Pair(-7, 5), Pair(-1, 3), Pair(9, -1), Pair(-12, 21),
        Pair(-3, 6), Pair(-3, 4), Pair(-4, 7), Pair(-12, -12), Pair(-9, 16), Pair(-2, 2), Pair(5, 2), Pair(3, 3),
        Pair(2, 4), Pair(0, -2), Pair(2, -3), Pair(-5, -6), Pair(-2, 3), Pair(-2, 4), Pair(2, 3), Pair(1, 5),
        Pair(-1, 0), Pair(-1, 0), Pair(-2, -4), Pair(0, 0), Pair(-2, 0), Pair(-3, 0), Pair(-2, 1), Pair(0, 5),
        Pair(0, -1), Pair(-2, 0), Pair(-3, -5), Pair(2, -1), Pair(-1, -4), Pair(0, 0), Pair(1, 0), Pair(-1, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-66, 41), Pair(21, 7), Pair(-51, 10), Pair(-102, 58), Pair(-39, 37), Pair(85, 65), Pair(-83, 140), Pair(18, 35),
        Pair(-15, 56), Pair(-33, -11), Pair(-5, 27), Pair(55, -35), Pair(-29, 41), Pair(-4, 21), Pair(19, -7), Pair(19, 24),
        Pair(24, 21), Pair(4, 24), Pair(-31, 43), Pair(0, 0), Pair(3, 26), Pair(-22, 59), Pair(0, 32), Pair(37, 20),
        Pair(-15, 27), Pair(-2, 20), Pair(-96, -1), Pair(-6, 70), Pair(-66, 53), Pair(-11, 50), Pair(-1, 35), Pair(1, 30),
        Pair(-10, 6), Pair(-3, 10), Pair(-28, 15), Pair(-6, 46), Pair(-9, 20), Pair(-3, 39), Pair(-5, 20), Pair(-8, 54),
        Pair(-2, 39), Pair(-2, -4), Pair(-1, 30), Pair(-19, 24), Pair(-11, 43), Pair(-13, 22), Pair(-2, 36), Pair(-1, 39),
        Pair(-4, 1), Pair(-3, 19), Pair(2, 26), Pair(-5, 17), Pair(3, 35), Pair(0, 18), Pair(7, 23), Pair(8, 17),
        Pair(17, -58), Pair(5, 27), Pair(16, 9), Pair(9, 28), Pair(-6, 27), Pair(0, 25), Pair(-6, 44), Pair(-60, 159)
      },
      { // Piece 2
        Pair(-44, 51), Pair(-115, 19), Pair(-26, 53), Pair(-25, 62), Pair(-51, 54), Pair(-52, 9), Pair(-6, 45), Pair(38, -42),
        Pair(-30, 15), Pair(-4, 57), Pair(-45, 11), Pair(-24, 64), Pair(-16, -12), Pair(-30, 40), Pair(-7, 16), Pair(32, 37),
        Pair(9, 47), Pair(-22, 32), Pair(-25, 67), Pair(0, 0), Pair(-18, 46), Pair(-16, 48), Pair(2, 37), Pair(11, 26),
        Pair(6, 8), Pair(-11, 44), Pair(-109, -11), Pair(7, 67), Pair(-20, -174), Pair(-9, 49), Pair(-9, 32), Pair(-14, 57),
        Pair(-16, 53), Pair(-5, 7), Pair(-15, 29), Pair(-8, 12), Pair(-8, 24), Pair(-7, 10), Pair(-9, 34), Pair(2, 8),
        Pair(-5, 6), Pair(-8, 32), Pair(-10, 26), Pair(-3, 35), Pair(-5, 23), Pair(-8, 35), Pair(-14, 7), Pair(-8, 43),
        Pair(-12, 15), Pair(-3, 10), Pair(1, 24), Pair(1, 13), Pair(-1, 29), Pair(-4, 25), Pair(1, 25), Pair(-1, -25),
        Pair(-15, 20), Pair(8, 34), Pair(3, 5), Pair(2, 38), Pair(-12, 19), Pair(4, 23), Pair(-25, 31), Pair(-8, 47)
      },
      { // Piece 3
        Pair(-22, 49), Pair(4, 33), Pair(-16, 34), Pair(30, 35), Pair(10, 36), Pair(-70, 66), Pair(64, 15), Pair(27, 34),
        Pair(6, 23), Pair(0, 40), Pair(-11, 29), Pair(-28, 53), Pair(-38, 54), Pair(18, 37), Pair(1, 38), Pair(18, 24),
        Pair(-9, 25), Pair(-16, 42), Pair(-1, 33), Pair(0, 0), Pair(-12, 40), Pair(24, 39), Pair(-26, 44), Pair(8, 17),
        Pair(10, 12), Pair(-25, 27), Pair(29, -45), Pair(10, 9), Pair(-167, 129), Pair(-1, 21), Pair(19, 8), Pair(0, 14),
        Pair(-14, 38), Pair(-12, 31), Pair(-11, 36), Pair(-4, 14), Pair(-11, 23), Pair(-18, 29), Pair(-4, 41), Pair(16, 31),
        Pair(2, 40), Pair(-10, 27), Pair(-15, 23), Pair(-5, 27), Pair(-14, 28), Pair(6, 12), Pair(7, 11), Pair(-5, 43),
        Pair(8, 14), Pair(-5, 34), Pair(-1, 14), Pair(-9, 19), Pair(-9, 19), Pair(12, 10), Pair(13, 20), Pair(18, 27),
        Pair(-3, 26), Pair(-4, 28), Pair(-2, 17), Pair(-4, 23), Pair(0, 15), Pair(2, 25), Pair(0, 24), Pair(9, 26)
      },
      { // Piece 4
        Pair(-9, 34), Pair(88, -49), Pair(-11, 59), Pair(-25, 101), Pair(44, 44), Pair(-123, 193), Pair(112, -31), Pair(-6, 67),
        Pair(31, 40), Pair(26, 25), Pair(-1, 48), Pair(-30, 82), Pair(-29, 51), Pair(25, 64), Pair(58, 11), Pair(-30, 80),
        Pair(-5, 50), Pair(31, 13), Pair(-9, 59), Pair(0, 0), Pair(-4, 92), Pair(13, 92), Pair(13, 59), Pair(12, 51),
        Pair(12, 42), Pair(5, 44), Pair(104, 17), Pair(31, 26), Pair(24, -19), Pair(4, 62), Pair(21, 62), Pair(9, 74),
        Pair(5, 49), Pair(13, 43), Pair(9, 49), Pair(8, 52), Pair(9, 44), Pair(23, 31), Pair(-10, 102), Pair(27, 55),
        Pair(-6, 55), Pair(2, 46), Pair(10, 22), Pair(13, 47), Pair(10, 37), Pair(7, 28), Pair(5, 62), Pair(18, 60),
        Pair(4, 51), Pair(4, 50), Pair(10, 18), Pair(8, 50), Pair(4, 41), Pair(1, 43), Pair(-4, 85), Pair(32, -6),
        Pair(11, 26), Pair(17, 16), Pair(5, 53), Pair(11, 48), Pair(18, 45), Pair(8, 50), Pair(35, -21), Pair(-10, 28)
      },
      { // Piece 5
        Pair(23, -13), Pair(-109, -45), Pair(5, -69), Pair(28, -62), Pair(33, -13), Pair(-25, -9), Pair(10, 15), Pair(25, -83),
        Pair(16, 62), Pair(62, -27), Pair(187, -94), Pair(-24, -47), Pair(-76, -2), Pair(29, 8), Pair(80, -8), Pair(34, 26),
        Pair(34, -11), Pair(-2, -29), Pair(64, -88), Pair(0, 0), Pair(107, -102), Pair(180, -13), Pair(23, -4), Pair(46, 6),
        Pair(14, 20), Pair(-53, 3), Pair(0, 0), Pair(63, -86), Pair(0, 0), Pair(-115, 22), Pair(78, -3), Pair(75, -6),
        Pair(-3, -6), Pair(16, -11), Pair(85, -45), Pair(51, -55), Pair(114, -41), Pair(59, -25), Pair(-14, 8), Pair(-12, 4),
        Pair(-52, -4), Pair(-37, 8), Pair(-30, -9), Pair(9, -15), Pair(-3, -9), Pair(2, 4), Pair(-4, 5), Pair(-13, 18),
        Pair(3, 8), Pair(-8, -6), Pair(-25, -3), Pair(-10, -2), Pair(-1, -7), Pair(-2, 12), Pair(-4, 14), Pair(6, 13),
        Pair(-20, 45), Pair(-17, 22), Pair(-9, 2), Pair(5, -11), Pair(0, -8), Pair(-3, 10), Pair(-3, 16), Pair(-1, 5)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, 9), Pair(17, 9), Pair(-3, 11), Pair(0, 14), Pair(-25, 8), Pair(-23, 21), Pair(-30, 26), Pair(7, 14),
        Pair(8, 5), Pair(-2, 6), Pair(9, -2), Pair(-4, 4), Pair(0, 0), Pair(1, 8), Pair(-7, 13), Pair(-5, 6),
        Pair(1, 1), Pair(1, 3), Pair(6, -1), Pair(0, 29), Pair(-7, -5), Pair(6, -5), Pair(4, 6), Pair(-1, 8),
        Pair(4, -1), Pair(4, -2), Pair(3, 1), Pair(4, 5), Pair(1, -1), Pair(-1, 0), Pair(1, 2), Pair(-1, 4),
        Pair(3, -1), Pair(2, -1), Pair(1, 0), Pair(3, -1), Pair(0, 0), Pair(1, 0), Pair(-2, 3), Pair(-2, 1),
        Pair(2, 0), Pair(3, 0), Pair(1, -2), Pair(4, -5), Pair(4, -1), Pair(-3, -5), Pair(-3, 1), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, -60), Pair(20, -1), Pair(-13, 25), Pair(-10, 30), Pair(-6, 39), Pair(42, 32), Pair(-46, 36), Pair(-23, 30),
        Pair(-10, 32), Pair(4, 36), Pair(-17, -2), Pair(-29, 49), Pair(9, -8), Pair(-20, 42), Pair(-38, 11), Pair(-12, 70),
        Pair(7, 10), Pair(-12, 10), Pair(-4, 37), Pair(-13, 35), Pair(0, 0), Pair(8, 33), Pair(-19, 31), Pair(-23, 15),
        Pair(17, 17), Pair(-8, 21), Pair(-1, 24), Pair(-60, -75), Pair(2, 57), Pair(-47, 79), Pair(2, 20), Pair(-4, 21),
        Pair(-2, 24), Pair(-30, 40), Pair(-6, 33), Pair(-24, 14), Pair(-5, 39), Pair(-24, 8), Pair(4, 31), Pair(-7, 21),
        Pair(-11, 33), Pair(-9, 28), Pair(-12, 17), Pair(-6, 31), Pair(-26, 16), Pair(0, 22), Pair(-18, 17), Pair(0, 36),
        Pair(-6, 28), Pair(6, 38), Pair(2, 12), Pair(-4, 33), Pair(-5, 22), Pair(-1, 22), Pair(4, 26), Pair(3, 44),
        Pair(31, -42), Pair(4, 27), Pair(-6, 10), Pair(7, 12), Pair(12, 21), Pair(9, 20), Pair(-4, 27), Pair(16, -33)
      },
      { // Piece 2
        Pair(-29, 37), Pair(-119, 66), Pair(-80, 48), Pair(-75, 63), Pair(25, 28), Pair(-137, 68), Pair(30, -86), Pair(-20, 130),
        Pair(-12, 39), Pair(-37, 31), Pair(32, 32), Pair(-84, 32), Pair(-4, 44), Pair(71, -23), Pair(16, 48), Pair(-34, 8),
        Pair(1, 7), Pair(-10, 44), Pair(-40, 34), Pair(-13, 35), Pair(0, 0), Pair(-19, 56), Pair(-18, 28), Pair(13, 33),
        Pair(4, 29), Pair(-17, 27), Pair(11, 28), Pair(-77, -28), Pair(2, 66), Pair(-117, 15), Pair(0, 31), Pair(-17, 18),
        Pair(-14, 22), Pair(4, 26), Pair(-22, 14), Pair(-26, 28), Pair(-19, 18), Pair(-5, 20), Pair(-18, 16), Pair(-7, 28),
        Pair(6, 43), Pair(-25, 8), Pair(3, 19), Pair(-12, 19), Pair(-1, 29), Pair(-21, 15), Pair(-2, 22), Pair(-27, -9),
        Pair(-28, 5), Pair(5, 23), Pair(-6, 19), Pair(5, 29), Pair(-9, 14), Pair(-4, 34), Pair(-22, 14), Pair(9, 7),
        Pair(-9, 42), Pair(-17, 22), Pair(7, 36), Pair(-14, 17), Pair(-6, 32), Pair(-11, 13), Pair(-6, 15), Pair(-11, 16)
      },
      { // Piece 3
        Pair(15, 32), Pair(0, 27), Pair(-1, 33), Pair(-36, 41), Pair(59, 16), Pair(52, 9), Pair(-57, 38), Pair(1, 26),
        Pair(9, 23), Pair(-3, 39), Pair(8, 32), Pair(-15, 37), Pair(5, 41), Pair(9, 12), Pair(-18, 35), Pair(23, 22),
        Pair(-1, 25), Pair(-4, 28), Pair(7, 28), Pair(-11, 19), Pair(0, 0), Pair(-9, 28), Pair(-9, 24), Pair(1, 25),
        Pair(5, 24), Pair(-12, 28), Pair(14, 18), Pair(20, -21), Pair(13, 7), Pair(18, -29), Pair(-3, 20), Pair(5, 28),
        Pair(10, 22), Pair(-13, 31), Pair(10, 15), Pair(-6, 20), Pair(0, 11), Pair(-2, 18), Pair(-12, 19), Pair(7, 16),
        Pair(-7, 26), Pair(-5, 26), Pair(-7, 36), Pair(-2, 10), Pair(-8, 14), Pair(1, 19), Pair(-2, 35), Pair(15, 23),
        Pair(-6, 28), Pair(13, 19), Pair(-2, 27), Pair(-12, 22), Pair(-2, 24), Pair(3, 18), Pair(2, 24), Pair(9, 10),
        Pair(0, 24), Pair(-1, 25), Pair(1, 27), Pair(-7, 19), Pair(1, 18), Pair(-1, 24), Pair(-4, 22), Pair(7, 24)
      },
      { // Piece 4
        Pair(-38, 72), Pair(1, 92), Pair(-6, 49), Pair(-1, 94), Pair(39, 27), Pair(29, 80), Pair(133, -44), Pair(7, 66),
        Pair(23, 72), Pair(-1, 84), Pair(41, 60), Pair(19, 26), Pair(-18, 84), Pair(2, 28), Pair(24, 42), Pair(28, 50),
        Pair(16, 39), Pair(21, 47), Pair(12, 55), Pair(9, 21), Pair(0, 0), Pair(33, 54), Pair(-7, 71), Pair(52, 15),
        Pair(22, 44), Pair(25, 31), Pair(13, 61), Pair(-49, -13), Pair(42, 33), Pair(153, -34), Pair(23, 61), Pair(24, 58),
        Pair(8, 68), Pair(2, 75), Pair(6, 77), Pair(12, 39), Pair(38, 10), Pair(16, 48), Pair(8, 58), Pair(16, 54),
        Pair(21, 44), Pair(11, 40), Pair(6, 54), Pair(11, 40), Pair(18, 38), Pair(15, 29), Pair(19, 23), Pair(31, -35),
        Pair(19, 13), Pair(9, 46), Pair(6, 59), Pair(4, 47), Pair(18, 44), Pair(3, 76), Pair(-3, 79), Pair(-13, 92),
        Pair(2, 76), Pair(16, 49), Pair(7, 61), Pair(10, 53), Pair(20, 44), Pair(15, 19), Pair(0, 121), Pair(15, 62)
      },
      { // Piece 5
        Pair(-7, 47), Pair(-12, -18), Pair(55, -12), Pair(58, -68), Pair(-9, -40), Pair(-2, -13), Pair(-71, -51), Pair(-60, 6),
        Pair(89, 67), Pair(139, 23), Pair(27, 12), Pair(-31, -9), Pair(72, -46), Pair(100, -56), Pair(-16, -41), Pair(-156, 94),
        Pair(3, -5), Pair(139, 2), Pair(71, -9), Pair(77, -63), Pair(0, 0), Pair(58, -67), Pair(85, -11), Pair(69, -22),
        Pair(190, -38), Pair(147, -12), Pair(76, -13), Pair(5, 4), Pair(32, -69), Pair(-5, -64), Pair(-11, -5), Pair(14, -5),
        Pair(62, -12), Pair(90, -21), Pair(8, -6), Pair(28, -24), Pair(34, -32), Pair(52, -27), Pair(-24, 8), Pair(-26, 20),
        Pair(41, -8), Pair(54, -3), Pair(3, 8), Pair(9, 1), Pair(5, -8), Pair(4, -1), Pair(-2, 17), Pair(9, 1),
        Pair(31, -6), Pair(-6, 12), Pair(13, 14), Pair(-1, 8), Pair(7, 2), Pair(13, 1), Pair(-1, 17), Pair(6, 10),
        Pair(2, 22), Pair(-4, 16), Pair(4, 19), Pair(11, 17), Pair(-5, 13), Pair(15, 5), Pair(4, 16), Pair(0, 20)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 12), Pair(17, 10), Pair(7, 13), Pair(-11, 8), Pair(2, 4), Pair(-40, -11), Pair(-51, 13), Pair(1, 13),
        Pair(11, 3), Pair(6, 8), Pair(18, -4), Pair(4, 1), Pair(-7, 4), Pair(0, 0), Pair(9, 1), Pair(-3, 1),
        Pair(5, -1), Pair(3, 2), Pair(8, 2), Pair(0, 1), Pair(6, 20), Pair(-14, -2), Pair(2, 1), Pair(2, 2),
        Pair(5, 0), Pair(5, -1), Pair(8, -3), Pair(3, 2), Pair(2, 4), Pair(-2, -3), Pair(2, -2), Pair(2, 1),
        Pair(3, -1), Pair(4, 0), Pair(4, -2), Pair(3, 1), Pair(0, 1), Pair(0, 0), Pair(-4, -3), Pair(-3, -1),
        Pair(4, -2), Pair(3, -2), Pair(3, -2), Pair(2, -1), Pair(2, -2), Pair(4, -3), Pair(-1, -7), Pair(-4, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(47, 4), Pair(-43, 22), Pair(43, 27), Pair(19, 24), Pair(121, -25), Pair(63, 19), Pair(-167, 46), Pair(21, 100),
        Pair(-11, 55), Pair(51, 37), Pair(66, 16), Pair(-39, 20), Pair(54, 7), Pair(-12, 28), Pair(73, 25), Pair(-96, 20),
        Pair(-10, 38), Pair(40, 31), Pair(1, 34), Pair(15, 44), Pair(24, 25), Pair(0, 0), Pair(27, 10), Pair(28, 22),
        Pair(21, 18), Pair(15, 31), Pair(29, 21), Pair(18, 14), Pair(-33, -3), Pair(40, 54), Pair(0, -28), Pair(19, 7),
        Pair(11, 25), Pair(10, 20), Pair(7, 22), Pair(21, 33), Pair(-7, 21), Pair(9, 45), Pair(5, -8), Pair(15, 36),
        Pair(4, 47), Pair(6, 40), Pair(14, 24), Pair(7, 21), Pair(7, 27), Pair(-5, 21), Pair(7, 47), Pair(-4, 13),
        Pair(2, 16), Pair(-5, 67), Pair(21, 27), Pair(5, 20), Pair(14, 29), Pair(-5, 34), Pair(13, 46), Pair(5, 15),
        Pair(-55, 11), Pair(13, 45), Pair(17, 28), Pair(9, 21), Pair(2, 28), Pair(23, 11), Pair(-8, 46), Pair(-19, 76)
      },
      { // Piece 2
        Pair(8, 20), Pair(61, 13), Pair(30, 47), Pair(18, 24), Pair(2, 54), Pair(-51, 49), Pair(32, 43), Pair(-79, -98),
        Pair(-37, 44), Pair(-15, 49), Pair(-19, 44), Pair(19, 55), Pair(13, 24), Pair(-3, 48), Pair(-4, -17), Pair(-17, 75),
        Pair(25, 31), Pair(-24, 49), Pair(23, 40), Pair(-3, 33), Pair(19, 46), Pair(0, 0), Pair(17, 35), Pair(7, 23),
        Pair(-2, 21), Pair(18, 35), Pair(6, 39), Pair(18, 35), Pair(-68, 24), Pair(31, 61), Pair(-14, -9), Pair(21, 28),
        Pair(0, 56), Pair(-15, 44), Pair(24, 30), Pair(-6, 29), Pair(-23, 31), Pair(7, 18), Pair(5, 37), Pair(2, 13),
        Pair(11, 22), Pair(14, 43), Pair(4, 14), Pair(16, 23), Pair(-2, 21), Pair(15, 35), Pair(-14, 30), Pair(17, 24),
        Pair(5, 46), Pair(4, 9), Pair(16, 22), Pair(1, 21), Pair(17, 22), Pair(-6, 28), Pair(18, 24), Pair(-8, 18),
        Pair(-17, 16), Pair(19, 48), Pair(1, 20), Pair(9, 35), Pair(10, 11), Pair(18, 26), Pair(16, 10), Pair(19, 53)
      },
      { // Piece 3
        Pair(20, 37), Pair(21, 41), Pair(-5, 52), Pair(12, 46), Pair(-7, 35), Pair(40, 16), Pair(9, 41), Pair(-52, 50),
        Pair(24, 31), Pair(21, 29), Pair(43, 21), Pair(14, 33), Pair(1, 41), Pair(26, 43), Pair(-27, 44), Pair(69, 8),
        Pair(33, 25), Pair(5, 34), Pair(6, 32), Pair(51, 20), Pair(-11, 48), Pair(0, 0), Pair(21, 18), Pair(-32, 45),
        Pair(25, 21), Pair(2, 31), Pair(34, 26), Pair(-16, 47), Pair(59, -22), Pair(25, 17), Pair(39, 25), Pair(-5, 28),
        Pair(15, 27), Pair(4, 26), Pair(10, 32), Pair(-13, 36), Pair(-15, 39), Pair(2, 36), Pair(34, 37), Pair(12, 34),
        Pair(11, 30), Pair(11, 23), Pair(-1, 43), Pair(11, 34), Pair(-1, 23), Pair(5, 26), Pair(26, 25), Pair(1, 49),
        Pair(10, 22), Pair(30, 29), Pair(10, 35), Pair(21, 21), Pair(7, 15), Pair(22, 18), Pair(7, 22), Pair(-7, 41),
        Pair(12, 36), Pair(12, 36), Pair(7, 38), Pair(12, 28), Pair(9, 25), Pair(10, 31), Pair(14, 19), Pair(1, 47)
      },
      { // Piece 4
        Pair(-31, 38), Pair(14, 28), Pair(18, 45), Pair(12, 49), Pair(28, 18), Pair(81, -8), Pair(78, 50), Pair(68, -32),
        Pair(28, 34), Pair(36, 32), Pair(18, 56), Pair(26, 58), Pair(9, 58), Pair(-8, 47), Pair(49, 4), Pair(31, 52),
        Pair(13, 48), Pair(3, 59), Pair(19, 42), Pair(12, 36), Pair(8, 30), Pair(0, 0), Pair(30, 8), Pair(17, 32),
        Pair(18, 35), Pair(29, 55), Pair(23, 21), Pair(3, 52), Pair(32, -52), Pair(58, -6), Pair(-23, 51), Pair(32, 23),
        Pair(31, -20), Pair(16, 61), Pair(26, 27), Pair(15, 35), Pair(24, 25), Pair(32, 16), Pair(36, 35), Pair(41, 25),
        Pair(28, -7), Pair(8, 30), Pair(17, 34), Pair(16, 34), Pair(12, 41), Pair(32, 16), Pair(29, 12), Pair(12, 52),
        Pair(14, 29), Pair(25, 23), Pair(19, 10), Pair(15, 35), Pair(9, 37), Pair(18, 38), Pair(13, 54), Pair(53, -56),
        Pair(16, 7), Pair(18, 25), Pair(13, 25), Pair(17, 26), Pair(30, 13), Pair(5, 45), Pair(-10, 78), Pair(48, -18)
      },
      { // Piece 5
        Pair(-99, -43), Pair(-9, -49), Pair(-92, 8), Pair(30, 17), Pair(7, 22), Pair(-27, -80), Pair(-39, 32), Pair(38, -54),
        Pair(-43, 40), Pair(-70, -2), Pair(-154, 11), Pair(-59, 4), Pair(45, -35), Pair(179, -90), Pair(17, -40), Pair(161, -57),
        Pair(67, -9), Pair(147, -29), Pair(129, -26), Pair(-104, -4), Pair(-174, -46), Pair(0, 0), Pair(78, -59), Pair(13, -6),
        Pair(-141, 52), Pair(83, -7), Pair(7, 0), Pair(-7, -13), Pair(-150, -245), Pair(-9, -60), Pair(-1, -9), Pair(-27, -8),
        Pair(-10, -6), Pair(128, -18), Pair(12, 3), Pair(25, -11), Pair(31, -26), Pair(57, -34), Pair(23, -17), Pair(-3, -15),
        Pair(43, -14), Pair(49, -9), Pair(66, -13), Pair(42, -6), Pair(43, -10), Pair(0, -2), Pair(20, -9), Pair(5, 4),
        Pair(7, 3), Pair(21, -4), Pair(18, 8), Pair(22, 1), Pair(15, -4), Pair(31, -10), Pair(-3, 1), Pair(9, 12),
        Pair(5, -3), Pair(-3, 2), Pair(3, 5), Pair(34, -9), Pair(-4, 14), Pair(-8, 10), Pair(-3, 7), Pair(16, 1)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(21, 18), Pair(27, 7), Pair(13, 10), Pair(21, 7), Pair(22, 0), Pair(-4, 7), Pair(3, 2), Pair(-24, 25),
        Pair(9, 7), Pair(15, 7), Pair(13, 5), Pair(-2, 5), Pair(-5, 4), Pair(-8, 2), Pair(0, 0), Pair(-1, 5),
        Pair(2, 8), Pair(7, 2), Pair(10, 2), Pair(-2, 5), Pair(1, 0), Pair(6, 19), Pair(-4, -4), Pair(19, 10),
        Pair(3, 2), Pair(7, -2), Pair(2, 0), Pair(1, 2), Pair(-1, -1), Pair(2, 3), Pair(1, -3), Pair(7, 5),
        Pair(2, -3), Pair(4, 0), Pair(0, 0), Pair(-1, -2), Pair(2, -1), Pair(4, 2), Pair(0, 0), Pair(1, 3),
        Pair(3, -1), Pair(3, -4), Pair(-3, -1), Pair(3, -5), Pair(0, 0), Pair(4, 1), Pair(0, -3), Pair(-3, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-43, 32), Pair(-143, 60), Pair(-54, 13), Pair(-105, 41), Pair(-40, 46), Pair(-73, 47), Pair(-140, 25), Pair(126, -44),
        Pair(-8, 19), Pair(19, 27), Pair(19, 27), Pair(-10, 33), Pair(26, -16), Pair(29, 9), Pair(-67, -16), Pair(29, 26),
        Pair(-34, 11), Pair(11, 25), Pair(4, 27), Pair(10, 23), Pair(18, 41), Pair(10, 38), Pair(0, 0), Pair(-67, 47),
        Pair(15, 15), Pair(3, 20), Pair(14, 24), Pair(3, 23), Pair(21, 10), Pair(-24, -21), Pair(7, 63), Pair(-13, 89),
        Pair(-2, 26), Pair(-9, 26), Pair(4, 24), Pair(-5, 29), Pair(9, 30), Pair(-20, 17), Pair(-1, 42), Pair(-26, 5),
        Pair(-2, 20), Pair(3, 19), Pair(1, 25), Pair(6, 25), Pair(-13, 24), Pair(3, 27), Pair(-19, 8), Pair(5, 31),
        Pair(9, 18), Pair(-16, 28), Pair(-7, 27), Pair(-2, 30), Pair(-4, 22), Pair(2, 15), Pair(-1, 26), Pair(0, 28),
        Pair(-16, -12), Pair(0, 9), Pair(0, 5), Pair(-6, 19), Pair(8, 18), Pair(4, 17), Pair(1, 25), Pair(-26, 78)
      },
      { // Piece 2
        Pair(-22, 62), Pair(-62, 54), Pair(-43, 33), Pair(-38, 56), Pair(-73, 56), Pair(-74, 69), Pair(-16, 65), Pair(45, 45),
        Pair(-8, 53), Pair(-8, 36), Pair(8, 51), Pair(-55, 63), Pair(-78, 76), Pair(-29, 30), Pair(-73, 53), Pair(-134, -1),
        Pair(-1, 27), Pair(-4, 45), Pair(4, 40), Pair(-15, 45), Pair(3, 29), Pair(5, 44), Pair(0, 0), Pair(-8, 39),
        Pair(-6, 45), Pair(6, 31), Pair(18, 44), Pair(7, 29), Pair(0, 37), Pair(-63, -25), Pair(2, 61), Pair(-38, 48),
        Pair(-14, 40), Pair(12, 33), Pair(-5, 39), Pair(4, 38), Pair(0, 11), Pair(-5, 38), Pair(-22, 32), Pair(-31, 47),
        Pair(0, 35), Pair(8, 27), Pair(5, 33), Pair(-11, 23), Pair(-1, 33), Pair(0, 25), Pair(7, 36), Pair(-11, 23),
        Pair(-18, 45), Pair(2, 38), Pair(-4, 16), Pair(-3, 33), Pair(-2, 17), Pair(-8, 38), Pair(2, 24), Pair(13, 20),
        Pair(-5, 38), Pair(-18, 15), Pair(5, 24), Pair(-16, 20), Pair(-7, 40), Pair(5, 18), Pair(15, 37), Pair(-24, 57)
      },
      { // Piece 3
        Pair(6, 46), Pair(15, 42), Pair(-18, 49), Pair(9, 43), Pair(21, 33), Pair(-52, 45), Pair(-25, 51), Pair(-50, 53),
        Pair(-5, 43), Pair(25, 30), Pair(10, 39), Pair(7, 41), Pair(-19, 51), Pair(-12, 41), Pair(39, 45), Pair(17, 36),
        Pair(5, 34), Pair(8, 35), Pair(5, 32), Pair(-2, 39), Pair(-23, 42), Pair(-4, 44), Pair(0, 0), Pair(-9, 34),
        Pair(14, 33), Pair(0, 31), Pair(6, 31), Pair(13, 38), Pair(10, 22), Pair(-70, -30), Pair(-20, 40), Pair(136, -78),
        Pair(3, 26), Pair(3, 43), Pair(14, 28), Pair(-4, 38), Pair(-4, 40), Pair(-16, 41), Pair(12, 21), Pair(-24, 26),
        Pair(5, 33), Pair(9, 31), Pair(8, 35), Pair(4, 41), Pair(9, 22), Pair(-6, 38), Pair(9, 37), Pair(3, 24),
        Pair(-5, 41), Pair(16, 34), Pair(9, 30), Pair(7, 27), Pair(10, 28), Pair(8, 28), Pair(-7, 22), Pair(24, 11),
        Pair(8, 36), Pair(4, 38), Pair(2, 42), Pair(4, 34), Pair(2, 33), Pair(2, 33), Pair(10, 26), Pair(-4, 32)
      },
      { // Piece 4
        Pair(-17, 51), Pair(-60, 106), Pair(-69, 101), Pair(43, 15), Pair(33, 14), Pair(13, 101), Pair(-69, 85), Pair(43, 66),
        Pair(16, 26), Pair(-1, 47), Pair(4, 54), Pair(-10, 69), Pair(-61, 110), Pair(15, 68), Pair(-21, 130), Pair(29, 27),
        Pair(-2, 43), Pair(27, 5), Pair(-3, 41), Pair(-10, 28), Pair(-4, 31), Pair(-1, 19), Pair(0, 0), Pair(-42, 6),
        Pair(20, 13), Pair(-1, 53), Pair(1, 38), Pair(-7, 51), Pair(-39, 92), Pair(12, 1), Pair(2, -13), Pair(36, -32),
        Pair(0, 34), Pair(-12, 71), Pair(0, 32), Pair(-11, 69), Pair(-1, 48), Pair(-4, 37), Pair(-6, 35), Pair(1, 47),
        Pair(-6, 67), Pair(-1, 44), Pair(5, 39), Pair(3, 48), Pair(-2, 30), Pair(-3, 45), Pair(21, 7), Pair(-10, 37),
        Pair(-5, 66), Pair(-8, 40), Pair(1, 29), Pair(1, 33), Pair(-6, 46), Pair(0, 32), Pair(5, 14), Pair(-26, 76),
        Pair(-12, 24), Pair(12, -2), Pair(0, 18), Pair(6, 20), Pair(0, 48), Pair(-27, 52), Pair(-14, 37), Pair(14, 48)
      },
      { // Piece 5
        Pair(217, -20), Pair(52, -44), Pair(-58, -27), Pair(56, 16), Pair(-2, -39), Pair(23, -16), Pair(71, -63), Pair(-35, -95),
        Pair(28, -1), Pair(11, -24), Pair(213, -7), Pair(84, -15), Pair(163, -53), Pair(-8, -22), Pair(-3, -10), Pair(151, -12),
        Pair(122, -14), Pair(206, -28), Pair(-17, -2), Pair(34, -19), Pair(6, -13), Pair(-17, -35), Pair(0, 0), Pair(185, -61),
        Pair(126, -21), Pair(76, -10), Pair(25, -6), Pair(110, -26), Pair(-44, -2), Pair(15, 60), Pair(72, -71), Pair(-26, -182),
        Pair(124, -11), Pair(49, -4), Pair(52, 0), Pair(51, -7), Pair(-10, -8), Pair(18, -14), Pair(3, -15), Pair(-22, -22),
        Pair(62, -13), Pair(23, -4), Pair(24, -7), Pair(65, -9), Pair(-13, 8), Pair(27, -1), Pair(-8, 2), Pair(-40, 17),
        Pair(-3, 5), Pair(-17, 8), Pair(-6, 6), Pair(2, 8), Pair(0, 12), Pair(9, 4), Pair(0, 5), Pair(3, 5),
        Pair(-37, 2), Pair(-19, 3), Pair(-18, 9), Pair(-21, 12), Pair(-9, 11), Pair(-3, 12), Pair(-3, 5), Pair(-4, 4)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(19, 10), Pair(-23, 16), Pair(45, 1), Pair(2, 6), Pair(8, 11), Pair(-16, 12), Pair(-21, -1), Pair(70, 43),
        Pair(9, 5), Pair(-4, 10), Pair(9, -1), Pair(11, 2), Pair(2, 3), Pair(-24, 2), Pair(-18, 4), Pair(0, 0),
        Pair(4, 4), Pair(4, 3), Pair(4, 4), Pair(0, 3), Pair(-4, 1), Pair(-6, 0), Pair(-3, -4), Pair(0, -3),
        Pair(2, -1), Pair(4, -2), Pair(4, -1), Pair(-1, -2), Pair(1, 0), Pair(0, 2), Pair(-2, -3), Pair(-1, -2),
        Pair(1, -3), Pair(3, -2), Pair(0, -4), Pair(1, -4), Pair(1, 0), Pair(0, 0), Pair(1, -4), Pair(0, 0),
        Pair(0, -3), Pair(2, -4), Pair(-1, -3), Pair(5, -9), Pair(-1, -2), Pair(2, -4), Pair(2, -4), Pair(0, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-60, 38), Pair(-87, 20), Pair(-34, 11), Pair(27, 24), Pair(-75, 46), Pair(26, 79), Pair(2, 34), Pair(15, -15),
        Pair(1, 0), Pair(3, 8), Pair(-32, 27), Pair(40, 17), Pair(9, 28), Pair(-47, 13), Pair(-33, 28), Pair(11, -43),
        Pair(21, 0), Pair(-4, 7), Pair(2, 20), Pair(18, 23), Pair(13, 16), Pair(22, 32), Pair(-8, 49), Pair(0, 0),
        Pair(5, 0), Pair(-2, 19), Pair(7, 20), Pair(13, 17), Pair(21, 19), Pair(16, 15), Pair(-20, -8), Pair(30, 50),
        Pair(2, 11), Pair(-1, -6), Pair(4, 20), Pair(7, 25), Pair(7, 29), Pair(20, 16), Pair(4, 8), Pair(-3, 39),
        Pair(-8, -2), Pair(-4, 8), Pair(4, 12), Pair(1, 14), Pair(12, 21), Pair(-3, 22), Pair(10, 29), Pair(-16, -13),
        Pair(10, 7), Pair(-6, 13), Pair(-13, 21), Pair(-2, 14), Pair(6, 16), Pair(-2, 24), Pair(-3, 41), Pair(2, 23),
        Pair(70, -27), Pair(-9, 22), Pair(-7, 14), Pair(6, 8), Pair(-2, 26), Pair(-9, 33), Pair(-9, 42), Pair(-52, 6)
      },
      { // Piece 2
        Pair(14, 52), Pair(-33, 59), Pair(4, 56), Pair(-94, 53), Pair(-62, 50), Pair(-79, 82), Pair(-47, 55), Pair(-1, 8),
        Pair(-12, 41), Pair(3, 44), Pair(-11, 47), Pair(-85, 80), Pair(-25, 55), Pair(-17, 51), Pair(-35, 46), Pair(37, 41),
        Pair(-25, 54), Pair(-31, 41), Pair(-19, 58), Pair(-22, 45), Pair(6, 50), Pair(-42, 50), Pair(-20, 51), Pair(0, 0),
        Pair(-35, 45), Pair(8, 34), Pair(-10, 46), Pair(3, 47), Pair(16, 35), Pair(-20, 42), Pair(-6, -26), Pair(21, 66),
        Pair(2, 32), Pair(-17, 43), Pair(2, 43), Pair(-4, 39), Pair(5, 40), Pair(1, 34), Pair(6, 27), Pair(-18, 34),
        Pair(-3, 28), Pair(11, 39), Pair(3, 38), Pair(-1, 36), Pair(-1, 26), Pair(2, 40), Pair(3, 27), Pair(8, 41),
        Pair(3, 48), Pair(2, 29), Pair(4, 26), Pair(-13, 31), Pair(-1, 37), Pair(-4, 33), Pair(10, 35), Pair(9, 16),
        Pair(13, 25), Pair(21, 36), Pair(-10, 23), Pair(6, 27), Pair(-14, 37), Pair(4, 39), Pair(-23, 38), Pair(1, 34)
      },
      { // Piece 3
        Pair(3, 58), Pair(11, 53), Pair(-35, 69), Pair(20, 54), Pair(-48, 67), Pair(59, 46), Pair(2, 59), Pair(-18, 58),
        Pair(16, 50), Pair(5, 52), Pair(19, 49), Pair(27, 42), Pair(35, 40), Pair(-13, 60), Pair(35, 41), Pair(97, 65),
        Pair(8, 52), Pair(5, 52), Pair(3, 55), Pair(-4, 59), Pair(9, 59), Pair(15, 58), Pair(36, 48), Pair(0, 0),
        Pair(16, 54), Pair(18, 43), Pair(18, 54), Pair(23, 45), Pair(16, 53), Pair(-7, 51), Pair(4, -1), Pair(3, 51),
        Pair(7, 49), Pair(25, 44), Pair(22, 43), Pair(-10, 50), Pair(10, 35), Pair(3, 42), Pair(12, 35), Pair(-41, 59),
        Pair(0, 54), Pair(20, 42), Pair(19, 49), Pair(19, 40), Pair(8, 40), Pair(4, 41), Pair(19, 46), Pair(-15, 49),
        Pair(22, 37), Pair(23, 38), Pair(9, 46), Pair(6, 49), Pair(8, 45), Pair(7, 46), Pair(14, 31), Pair(-15, 30),
        Pair(9, 50), Pair(2, 57), Pair(10, 52), Pair(7, 47), Pair(5, 49), Pair(10, 42), Pair(2, 52), Pair(-5, 53)
      },
      { // Piece 4
        Pair(21, 61), Pair(-14, 75), Pair(24, 67), Pair(-12, 69), Pair(28, 62), Pair(26, 56), Pair(145, 3), Pair(-70, 111),
        Pair(13, 48), Pair(-13, 82), Pair(31, 47), Pair(-43, 104), Pair(-7, 97), Pair(-49, 138), Pair(-39, 141), Pair(10, 92),
        Pair(27, 27), Pair(16, 43), Pair(8, 75), Pair(26, 38), Pair(0, 78), Pair(5, 100), Pair(-38, 90), Pair(0, 0),
        Pair(9, 67), Pair(-1, 75), Pair(-1, 70), Pair(-15, 106), Pair(-2, 95), Pair(13, 84), Pair(-41, 22), Pair(7, 40),
        Pair(9, 64), Pair(6, 73), Pair(-3, 69), Pair(7, 75), Pair(3, 88), Pair(10, 77), Pair(11, 50), Pair(1, 43),
        Pair(6, 54), Pair(-3, 61), Pair(11, 48), Pair(10, 62), Pair(8, 56), Pair(-4, 83), Pair(20, 35), Pair(-7, 62),
        Pair(-8, 53), Pair(2, 60), Pair(3, 50), Pair(6, 47), Pair(3, 56), Pair(14, 45), Pair(34, -6), Pair(-7, 52),
        Pair(13, 13), Pair(2, 53), Pair(0, 59), Pair(8, 51), Pair(8, 57), Pair(-16, 63), Pair(-15, 88), Pair(12, 3)
      },
      { // Piece 5
        Pair(-82, -91), Pair(-51, -63), Pair(-113, 13), Pair(-123, 30), Pair(179, -1), Pair(-211, -96), Pair(117, 64), Pair(2, -60),
        Pair(66, -2), Pair(47, -27), Pair(-54, 16), Pair(-200, 1), Pair(-190, 42), Pair(39, -34), Pair(-103, 1), Pair(60, 46),
        Pair(-29, 38), Pair(22, 1), Pair(-69, 21), Pair(75, -7), Pair(-22, 0), Pair(17, -13), Pair(-49, -42), Pair(0, 0),
        Pair(141, -9), Pair(97, -22), Pair(129, -21), Pair(47, -10), Pair(24, -9), Pair(-45, 5), Pair(-45, -27), Pair(142, -80),
        Pair(92, -25), Pair(51, -21), Pair(115, -28), Pair(72, -11), Pair(-13, 3), Pair(-14, -7), Pair(46, -13), Pair(46, -23),
        Pair(42, -31), Pair(34, -8), Pair(82, -26), Pair(65, -14), Pair(39, -10), Pair(-2, 2), Pair(16, -4), Pair(-6, -1),
        Pair(14, -7), Pair(-2, 1), Pair(8, -4), Pair(22, -2), Pair(-1, 10), Pair(3, 7), Pair(-4, 7), Pair(0, 2),
        Pair(-20, 13), Pair(-15, -4), Pair(-6, -1), Pair(21, -4), Pair(-1, 7), Pair(-10, 11), Pair(6, 6), Pair(-2, 7)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(-8, 6), Pair(-26, 12), Pair(-4, 13), Pair(-2, 17), Pair(43, 12), Pair(-21, 1), Pair(-16, 13),
        Pair(-23, -30), Pair(-13, 14), Pair(2, -3), Pair(-1, 7), Pair(-1, 4), Pair(-9, 13), Pair(-4, 21), Pair(-6, 13),
        Pair(-7, -7), Pair(-6, 8), Pair(-2, 4), Pair(2, 3), Pair(1, 8), Pair(-5, 9), Pair(-3, 5), Pair(2, 8),
        Pair(-5, -1), Pair(-5, 2), Pair(-3, -1), Pair(-1, 1), Pair(1, 6), Pair(-4, 5), Pair(-3, 3), Pair(1, 3),
        Pair(0, 1), Pair(-2, 2), Pair(1, -1), Pair(-1, -2), Pair(-1, 4), Pair(-4, 3), Pair(-3, 1), Pair(-2, 0),
        Pair(0, 0), Pair(2, 1), Pair(0, -1), Pair(-3, 1), Pair(0, -2), Pair(-4, 2), Pair(-3, 5), Pair(0, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-67, -33), Pair(104, 57), Pair(-105, 65), Pair(54, 12), Pair(113, -32), Pair(-147, 57), Pair(66, -29), Pair(-8, 4),
        Pair(0, 0), Pair(17, 32), Pair(19, 22), Pair(34, 2), Pair(4, 21), Pair(10, 28), Pair(46, -16), Pair(34, 8),
        Pair(-1, 83), Pair(-139, -5), Pair(13, 37), Pair(14, 20), Pair(6, 32), Pair(52, 9), Pair(64, -7), Pair(44, 6),
        Pair(23, 32), Pair(-13, 42), Pair(7, 27), Pair(8, 31), Pair(14, 23), Pair(25, 28), Pair(23, 21), Pair(26, 26),
        Pair(-13, 13), Pair(-23, 47), Pair(-8, 34), Pair(5, 38), Pair(12, 27), Pair(13, 25), Pair(21, 3), Pair(13, 32),
        Pair(-4, 43), Pair(7, 27), Pair(-6, 38), Pair(9, 21), Pair(3, 22), Pair(5, 26), Pair(6, 23), Pair(15, 16),
        Pair(16, 52), Pair(6, 22), Pair(11, 14), Pair(4, 20), Pair(4, 26), Pair(9, 19), Pair(5, 18), Pair(-3, 37),
        Pair(-188, 141), Pair(-1, 31), Pair(-10, 31), Pair(7, 24), Pair(6, 5), Pair(12, 26), Pair(0, 36), Pair(0, 86)
      },
      { // Piece 2
        Pair(-8, 42), Pair(-18, 70), Pair(96, 38), Pair(42, 39), Pair(-34, 74), Pair(-21, 88), Pair(-22, 51), Pair(-4, 56),
        Pair(0, 0), Pair(-18, 57), Pair(-13, 46), Pair(-44, 78), Pair(-16, 85), Pair(23, 51), Pair(49, 40), Pair(5, 14),
        Pair(19, 68), Pair(-326, 211), Pair(-27, 54), Pair(-5, 58), Pair(-8, 45), Pair(30, 42), Pair(1, 49), Pair(9, 36),
        Pair(31, 30), Pair(-21, 53), Pair(10, 74), Pair(-1, 49), Pair(10, 56), Pair(-1, 56), Pair(8, 52), Pair(11, 27),
        Pair(-10, 64), Pair(-20, 50), Pair(-4, 48), Pair(-4, 62), Pair(1, 45), Pair(9, 54), Pair(-6, 52), Pair(8, 56),
        Pair(-2, 65), Pair(-1, 47), Pair(-1, 50), Pair(2, 40), Pair(1, 46), Pair(-1, 35), Pair(-1, 54), Pair(5, 38),
        Pair(11, 52), Pair(4, 47), Pair(3, 41), Pair(2, 50), Pair(-1, 36), Pair(0, 54), Pair(9, 33), Pair(7, 47),
        Pair(14, 56), Pair(-17, 68), Pair(2, 56), Pair(4, 36), Pair(-10, 56), Pair(0, 39), Pair(-6, 48), Pair(-2, 45)
      },
      { // Piece 3
        Pair(-33, 100), Pair(0, 96), Pair(-31, 89), Pair(-23, 84), Pair(-23, 94), Pair(-22, 80), Pair(-2, 86), Pair(-5, 89),
        Pair(0, 0), Pair(-16, 93), Pair(-2, 100), Pair(-4, 93), Pair(-17, 97), Pair(-1, 99), Pair(12, 88), Pair(-18, 84),
        Pair(-3, 97), Pair(36, -225), Pair(8, 72), Pair(-3, 79), Pair(-4, 87), Pair(18, 74), Pair(-24, 76), Pair(-40, 92),
        Pair(-2, 79), Pair(-23, 86), Pair(2, 74), Pair(0, 73), Pair(4, 82), Pair(-2, 73), Pair(-7, 65), Pair(27, 63),
        Pair(-1, 64), Pair(-22, 46), Pair(-3, 75), Pair(-27, 74), Pair(-1, 65), Pair(0, 76), Pair(-6, 73), Pair(5, 67),
        Pair(-9, 53), Pair(-21, 84), Pair(-17, 78), Pair(-10, 69), Pair(-8, 75), Pair(8, 62), Pair(8, 62), Pair(4, 88),
        Pair(-9, 51), Pair(-10, 51), Pair(-14, 70), Pair(-12, 71), Pair(0, 71), Pair(3, 66), Pair(5, 64), Pair(11, 52),
        Pair(-11, 71), Pair(-17, 74), Pair(-15, 70), Pair(-11, 65), Pair(-7, 72), Pair(-6, 70), Pair(-3, 77), Pair(-1, 82)
      },
      { // Piece 4
        Pair(-101, 213), Pair(83, 57), Pair(-27, 192), Pair(-42, 175), Pair(-7, 143), Pair(77, 51), Pair(10, 153), Pair(30, 127),
        Pair(0, 0), Pair(22, 153), Pair(0, 168), Pair(-1, 176), Pair(18, 150), Pair(-35, 213), Pair(-44, 93), Pair(56, 117),
        Pair(9, 164), Pair(-82, -37), Pair(-7, 146), Pair(7, 123), Pair(22, 137), Pair(20, 134), Pair(27, 129), Pair(38, 110),
        Pair(39, 72), Pair(5, 123), Pair(35, 86), Pair(12, 133), Pair(10, 144), Pair(20, 133), Pair(25, 137), Pair(28, 119),
        Pair(16, 127), Pair(13, 105), Pair(2, 130), Pair(16, 132), Pair(9, 137), Pair(24, 103), Pair(29, 104), Pair(26, 154),
        Pair(10, 137), Pair(5, 113), Pair(2, 118), Pair(8, 128), Pair(5, 128), Pair(14, 120), Pair(13, 118), Pair(8, 104),
        Pair(8, 122), Pair(7, 113), Pair(9, 112), Pair(5, 109), Pair(12, 117), Pair(7, 115), Pair(7, 129), Pair(13, 127),
        Pair(18, 85), Pair(1, 124), Pair(12, 96), Pair(4, 118), Pair(13, 91), Pair(1, 125), Pair(-2, 156), Pair(36, 23)
      },
      { // Piece 5
        Pair(21, 3), Pair(-40, -26), Pair(-13, -31), Pair(85, 39), Pair(71, 22), Pair(81, -4), Pair(3, -16), Pair(42, 10),
        Pair(0, 0), Pair(7, -53), Pair(-35, 5), Pair(-18, 9), Pair(42, -36), Pair(12, 18), Pair(200, 12), Pair(67, -3),
        Pair(21, -49), Pair(0, 0), Pair(-137, -5), Pair(-47, -4), Pair(-147, 23), Pair(55, -10), Pair(134, -25), Pair(-82, 8),
        Pair(-108, -11), Pair(60, -33), Pair(15, -42), Pair(53, -32), Pair(94, -23), Pair(46, -4), Pair(6, 8), Pair(26, -12),
        Pair(-31, -18), Pair(8, -22), Pair(-58, -4), Pair(55, -24), Pair(-12, 4), Pair(-5, 6), Pair(7, -9), Pair(86, -11),
        Pair(38, -44), Pair(-18, -16), Pair(-21, -4), Pair(-23, -1), Pair(-14, -6), Pair(9, -7), Pair(6, -7), Pair(18, 4),
        Pair(-10, 7), Pair(-2, -16), Pair(-19, -4), Pair(-7, 0), Pair(-1, -4), Pair(12, -12), Pair(0, -5), Pair(2, 0),
        Pair(3, 24), Pair(8, 8), Pair(3, 19), Pair(5, -10), Pair(9, -14), Pair(2, -8), Pair(0, -7), Pair(-2, 5)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, -33), Pair(0, 0), Pair(-32, 18), Pair(34, -4), Pair(16, 12), Pair(14, 30), Pair(10, 7), Pair(17, 17),
        Pair(8, 16), Pair(-35, -24), Pair(-8, 15), Pair(5, 3), Pair(5, 1), Pair(7, 6), Pair(8, 6), Pair(-3, 16),
        Pair(7, 5), Pair(-10, -5), Pair(1, 12), Pair(1, 1), Pair(-2, 7), Pair(-3, 9), Pair(-2, 8), Pair(0, 8),
        Pair(5, 1), Pair(-7, -7), Pair(2, 7), Pair(-1, 1), Pair(-1, 2), Pair(-1, 3), Pair(-4, 9), Pair(-1, 7),
        Pair(6, 1), Pair(-3, -1), Pair(1, 6), Pair(-1, -2), Pair(-2, 3), Pair(-4, 0), Pair(-5, 2), Pair(-4, 4),
        Pair(2, 1), Pair(0, 0), Pair(2, 1), Pair(-2, 6), Pair(-2, -4), Pair(-3, -1), Pair(-4, 2), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-32, 47), Pair(-76, -94), Pair(-23, 41), Pair(-102, 45), Pair(44, -18), Pair(110, -53), Pair(-144, 64), Pair(23, 57),
        Pair(-30, -22), Pair(0, 0), Pair(5, 23), Pair(-60, 63), Pair(9, 16), Pair(6, 17), Pair(10, 7), Pair(-32, 50),
        Pair(142, -3), Pair(-2, 68), Pair(-206, 190), Pair(15, 24), Pair(11, 29), Pair(48, 23), Pair(5, 24), Pair(34, 16),
        Pair(-4, 52), Pair(-3, 38), Pair(-31, 44), Pair(-11, 44), Pair(1, 22), Pair(8, 31), Pair(12, 21), Pair(18, 20),
        Pair(-4, 33), Pair(-19, 3), Pair(-17, 46), Pair(-6, 26), Pair(3, 32), Pair(3, 28), Pair(17, 28), Pair(1, 35),
        Pair(3, 10), Pair(-4, 25), Pair(1, 31), Pair(-2, 28), Pair(-1, 26), Pair(3, 27), Pair(7, 24), Pair(-2, 48),
        Pair(27, 28), Pair(3, 28), Pair(9, 34), Pair(3, 28), Pair(10, 20), Pair(8, 15), Pair(-9, 31), Pair(0, 41),
        Pair(75, -30), Pair(4, 34), Pair(-6, 37), Pair(-5, 26), Pair(8, 27), Pair(11, 14), Pair(0, 52), Pair(-19, 47)
      },
      { // Piece 2
        Pair(0, 0), Pair(-35, 57), Pair(-3, 32), Pair(22, 45), Pair(-62, 90), Pair(-132, 65), Pair(-37, 42), Pair(50, 59),
        Pair(-19, 31), Pair(0, 0), Pair(0, 28), Pair(-46, 96), Pair(-5, 48), Pair(24, 53), Pair(-28, 42), Pair(6, 36),
        Pair(37, 23), Pair(-2, 59), Pair(-106, -74), Pair(-24, 54), Pair(-3, 59), Pair(11, 48), Pair(-22, 54), Pair(2, 43),
        Pair(5, 37), Pair(-7, 52), Pair(-30, 50), Pair(-16, 66), Pair(-3, 46), Pair(-23, 65), Pair(7, 43), Pair(-4, 41),
        Pair(-11, 40), Pair(-7, 31), Pair(-26, 50), Pair(-15, 43), Pair(2, 31), Pair(0, 34), Pair(-15, 54), Pair(6, 20),
        Pair(3, 37), Pair(-3, 54), Pair(-3, 49), Pair(-4, 41), Pair(2, 37), Pair(-7, 45), Pair(9, 35), Pair(-7, 44),
        Pair(-8, 72), Pair(6, 39), Pair(-11, 51), Pair(3, 27), Pair(-5, 37), Pair(-3, 38), Pair(1, 39), Pair(9, 23),
        Pair(-6, 48), Pair(0, 45), Pair(4, 45), Pair(-5, 56), Pair(11, 31), Pair(0, 34), Pair(5, 14), Pair(2, 42)
      },
      { // Piece 3
        Pair(-3, 42), Pair(-31, 50), Pair(-1, 49), Pair(29, 39), Pair(34, 28), Pair(-22, 43), Pair(45, 32), Pair(19, 42),
        Pair(-8, 43), Pair(0, 0), Pair(-21, 68), Pair(0, 70), Pair(-7, 75), Pair(9, 56), Pair(-54, 77), Pair(-26, 81),
        Pair(-158, 24), Pair(-18, 52), Pair(-218, -17), Pair(-8, 53), Pair(3, 42), Pair(13, 35), Pair(16, 42), Pair(13, 49),
        Pair(6, 30), Pair(0, 40), Pair(-8, 43), Pair(-19, 56), Pair(-24, 57), Pair(-22, 50), Pair(-6, 37), Pair(2, 40),
        Pair(-20, 38), Pair(-8, 41), Pair(-29, 44), Pair(-10, 52), Pair(-2, 39), Pair(-6, 42), Pair(5, 51), Pair(17, 36),
        Pair(-19, 39), Pair(-11, 50), Pair(-20, 49), Pair(-11, 46), Pair(-2, 31), Pair(-7, 47), Pair(20, 26), Pair(17, 46),
        Pair(-17, 60), Pair(-6, 28), Pair(-10, 50), Pair(-9, 41), Pair(5, 33), Pair(1, 45), Pair(-1, 50), Pair(-14, 71),
        Pair(-12, 47), Pair(-7, 43), Pair(-15, 45), Pair(-9, 45), Pair(-6, 49), Pair(-2, 49), Pair(-5, 55), Pair(11, 51)
      },
      { // Piece 4
        Pair(40, 32), Pair(-1, 81), Pair(24, 93), Pair(24, 104), Pair(46, 64), Pair(119, 43), Pair(-94, 158), Pair(66, 42),
        Pair(22, 76), Pair(0, 0), Pair(22, 113), Pair(-11, 118), Pair(11, 100), Pair(17, 106), Pair(10, 60), Pair(-5, 98),
        Pair(-287, -51), Pair(35, 55), Pair(-169, -114), Pair(30, 52), Pair(20, 91), Pair(47, 54), Pair(7, 88), Pair(22, 82),
        Pair(22, 85), Pair(19, 62), Pair(-1, 98), Pair(28, 74), Pair(9, 125), Pair(6, 106), Pair(15, 90), Pair(26, 73),
        Pair(5, 93), Pair(21, 66), Pair(12, 69), Pair(7, 99), Pair(12, 101), Pair(12, 97), Pair(6, 126), Pair(8, 126),
        Pair(14, 70), Pair(13, 74), Pair(17, 56), Pair(8, 83), Pair(16, 69), Pair(10, 87), Pair(17, 88), Pair(-6, 153),
        Pair(24, 108), Pair(6, 104), Pair(9, 85), Pair(11, 70), Pair(4, 101), Pair(4, 99), Pair(25, 71), Pair(10, 69),
        Pair(16, 66), Pair(29, 78), Pair(17, 62), Pair(9, 79), Pair(15, 69), Pair(6, 94), Pair(4, 125), Pair(-48, 130)
      },
      { // Piece 5
        Pair(2, 28), Pair(6, -154), Pair(-81, -56), Pair(39, -97), Pair(10, -3), Pair(95, -31), Pair(-71, -80), Pair(26, -133),
        Pair(-45, 6), Pair(0, 0), Pair(-42, -33), Pair(59, -32), Pair(-26, 25), Pair(-49, 44), Pair(-72, 7), Pair(17, -9),
        Pair(0, 0), Pair(-113, -67), Pair(0, 0), Pair(-3, -20), Pair(-223, 29), Pair(56, -9), Pair(20, 20), Pair(14, -1),
        Pair(-14, -43), Pair(4, -51), Pair(44, -16), Pair(-212, 8), Pair(141, -22), Pair(50, -3), Pair(-77, 28), Pair(109, -35),
        Pair(-126, -18), Pair(-36, -27), Pair(-31, -12), Pair(-34, 1), Pair(5, -16), Pair(-12, 9), Pair(-31, 8), Pair(-8, -6),
        Pair(-119, 19), Pair(3, -13), Pair(-13, -9), Pair(-9, -1), Pair(11, 0), Pair(-3, 6), Pair(11, 1), Pair(7, 9),
        Pair(-23, 5), Pair(-20, -9), Pair(27, -22), Pair(8, 7), Pair(2, 2), Pair(19, -1), Pair(6, 0), Pair(2, 3),
        Pair(-2, -7), Pair(-2, 11), Pair(7, -1), Pair(23, 3), Pair(1, 6), Pair(22, -4), Pair(1, 0), Pair(8, -1)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, 8), Pair(-6, 1), Pair(0, 0), Pair(-22, -7), Pair(-42, 24), Pair(19, 16), Pair(-38, 31), Pair(29, 0),
        Pair(-3, 13), Pair(17, -6), Pair(-26, -24), Pair(-14, 41), Pair(0, -4), Pair(5, 19), Pair(-13, 14), Pair(-7, 18),
        Pair(-3, 3), Pair(4, 9), Pair(-9, -3), Pair(2, 13), Pair(-4, 8), Pair(3, 5), Pair(4, 6), Pair(3, 9),
        Pair(-2, 2), Pair(2, -4), Pair(-8, -6), Pair(0, 8), Pair(-2, 1), Pair(0, 5), Pair(3, 2), Pair(1, 6),
        Pair(0, 3), Pair(-1, -2), Pair(-3, -1), Pair(2, 3), Pair(-2, 4), Pair(-4, 3), Pair(2, 2), Pair(1, 3),
        Pair(-2, 3), Pair(-3, -2), Pair(0, 0), Pair(-2, 6), Pair(1, -5), Pair(-4, -1), Pair(4, -1), Pair(3, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-55, 22), Pair(46, 47), Pair(-4, 14), Pair(-47, 17), Pair(78, -69), Pair(-128, 68), Pair(71, 45), Pair(-45, 95),
        Pair(-23, 46), Pair(14, 7), Pair(0, 0), Pair(-51, 37), Pair(-9, 51), Pair(-13, 31), Pair(-13, 20), Pair(33, -20),
        Pair(4, 4), Pair(29, -161), Pair(5, 64), Pair(-335, 292), Pair(-1, 34), Pair(8, 13), Pair(7, 51), Pair(-11, 35),
        Pair(-9, 35), Pair(-22, 15), Pair(-4, 48), Pair(-31, 28), Pair(-3, 45), Pair(8, 14), Pair(10, 26), Pair(0, 11),
        Pair(-7, 32), Pair(-21, 53), Pair(-10, 25), Pair(-20, 31), Pair(-10, 41), Pair(-1, 47), Pair(7, 32), Pair(7, 10),
        Pair(-6, 17), Pair(1, 46), Pair(-4, 35), Pair(3, 39), Pair(-6, 28), Pair(0, 23), Pair(0, 22), Pair(7, 16),
        Pair(0, 34), Pair(-28, 42), Pair(2, 24), Pair(-3, 34), Pair(4, 29), Pair(1, 24), Pair(14, -3), Pair(1, 47),
        Pair(-11, 4), Pair(-2, 49), Pair(11, 11), Pair(4, 27), Pair(10, 12), Pair(10, 24), Pair(7, 32), Pair(65, -10)
      },
      { // Piece 2
        Pair(35, 53), Pair(-80, 26), Pair(22, 39), Pair(-12, 35), Pair(-31, 78), Pair(-33, 44), Pair(-117, 106), Pair(48, 53),
        Pair(-6, 8), Pair(-22, 37), Pair(0, 0), Pair(-36, 78), Pair(-3, -3), Pair(-20, 55), Pair(11, 42), Pair(-18, 31),
        Pair(4, 48), Pair(51, -87), Pair(-15, 69), Pair(-345, -10), Pair(-3, 50), Pair(-7, 62), Pair(-19, 70), Pair(-14, 43),
        Pair(13, 22), Pair(-12, 36), Pair(-2, 40), Pair(-26, 41), Pair(0, 45), Pair(3, 39), Pair(-13, 47), Pair(16, 44),
        Pair(-6, 63), Pair(-36, 48), Pair(-7, 51), Pair(-27, 51), Pair(-5, 41), Pair(-12, 51), Pair(-7, 40), Pair(-6, 36),
        Pair(-3, 18), Pair(-9, 51), Pair(-3, 38), Pair(-6, 48), Pair(-11, 38), Pair(-3, 31), Pair(4, 18), Pair(-1, 33),
        Pair(-32, 108), Pair(-1, 29), Pair(5, 48), Pair(-5, 38), Pair(3, 40), Pair(-4, 39), Pair(8, 30), Pair(13, 26),
        Pair(12, 21), Pair(-22, 92), Pair(-5, 37), Pair(-6, 60), Pair(6, 13), Pair(3, 39), Pair(-17, 2), Pair(-9, 58)
      },
      { // Piece 3
        Pair(-10, 28), Pair(-27, 39), Pair(-42, 58), Pair(-41, 56), Pair(-20, 60), Pair(-36, 75), Pair(-9, 40), Pair(-163, 93),
        Pair(-3, 35), Pair(-42, 33), Pair(0, 0), Pair(-17, 41), Pair(-19, 65), Pair(-16, 56), Pair(-27, 56), Pair(-8, 51),
        Pair(-11, 18), Pair(52, -191), Pair(11, 31), Pair(-13, 71), Pair(-23, 37), Pair(41, 21), Pair(-32, 48), Pair(-40, 50),
        Pair(-23, 44), Pair(-11, 17), Pair(5, 30), Pair(-22, 29), Pair(0, 28), Pair(-26, 64), Pair(24, 28), Pair(-4, 48),
        Pair(6, 22), Pair(-15, 15), Pair(-8, 21), Pair(-33, 35), Pair(-7, 28), Pair(-10, 40), Pair(9, 34), Pair(1, 47),
        Pair(-22, 28), Pair(-22, 30), Pair(-8, 29), Pair(-27, 47), Pair(-7, 40), Pair(-6, 37), Pair(-4, 38), Pair(-8, 47),
        Pair(-14, 36), Pair(-19, 36), Pair(-4, 31), Pair(-17, 31), Pair(-1, 28), Pair(2, 33), Pair(7, 37), Pair(20, 31),
        Pair(-15, 41), Pair(-15, 35), Pair(-12, 35), Pair(-14, 30), Pair(-9, 36), Pair(-10, 42), Pair(-3, 27), Pair(-5, 45)
      },
      { // Piece 4
        Pair(2, 42), Pair(-75, 64), Pair(37, 18), Pair(-23, 78), Pair(6, 74), Pair(-205, 203), Pair(-38, 132), Pair(0, 80),
        Pair(2, 81), Pair(-3, 31), Pair(0, 0), Pair(-23, 104), Pair(20, 57), Pair(-30, 103), Pair(-25, 84), Pair(2, 33),
        Pair(12, 60), Pair(-214, -12), Pair(18, 80), Pair(-123, -24), Pair(25, 41), Pair(-32, 101), Pair(19, 37), Pair(6, 74),
        Pair(21, 64), Pair(7, 46), Pair(30, 38), Pair(-1, 68), Pair(16, 65), Pair(-6, 88), Pair(18, 61), Pair(9, 62),
        Pair(12, 29), Pair(-9, 73), Pair(1, 62), Pair(-4, 72), Pair(19, 41), Pair(12, 26), Pair(2, 52), Pair(-2, 103),
        Pair(11, 19), Pair(-1, 52), Pair(10, 47), Pair(-1, 55), Pair(4, 43), Pair(3, 46), Pair(10, 36), Pair(10, 39),
        Pair(-12, 46), Pair(1, 57), Pair(9, 54), Pair(0, 50), Pair(-1, 60), Pair(-5, 75), Pair(0, 51), Pair(-5, 8),
        Pair(7, 26), Pair(5, 23), Pair(11, 28), Pair(3, 30), Pair(1, 66), Pair(0, 26), Pair(27, -19), Pair(3, -9)
      },
      { // Piece 5
        Pair(28, 108), Pair(-14, -23), Pair(40, -83), Pair(-3, -16), Pair(43, 8), Pair(-26, 28), Pair(78, 55), Pair(-63, -1),
        Pair(-48, -95), Pair(42, -88), Pair(0, 0), Pair(88, -92), Pair(-34, -27), Pair(-158, 49), Pair(-139, 60), Pair(6, 24),
        Pair(-3, -50), Pair(0, 0), Pair(-179, -20), Pair(0, 0), Pair(32, -27), Pair(29, -19), Pair(-28, 18), Pair(-63, -3),
        Pair(-220, -41), Pair(-206, 20), Pair(-162, -23), Pair(-10, -21), Pair(-94, 5), Pair(11, -20), Pair(-1, 13), Pair(-47, -9),
        Pair(87, -32), Pair(-151, 16), Pair(-67, -6), Pair(-23, -24), Pair(14, -6), Pair(-19, 12), Pair(-38, 14), Pair(16, -3),
        Pair(20, 19), Pair(-37, -1), Pair(2, -25), Pair(7, -9), Pair(10, -1), Pair(-17, 1), Pair(-16, 2), Pair(-6, 6),
        Pair(-8, 1), Pair(-9, -4), Pair(-23, 2), Pair(-5, 5), Pair(-6, 7), Pair(12, -4), Pair(4, -7), Pair(8, -4),
        Pair(24, -34), Pair(9, -18), Pair(-1, 6), Pair(19, -17), Pair(6, 5), Pair(-1, 7), Pair(1, 0), Pair(-1, -3)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(13, 2), Pair(-43, 34), Pair(17, 40), Pair(0, 0), Pair(19, 56), Pair(44, 10), Pair(11, -43), Pair(11, 40),
        Pair(-5, 19), Pair(-17, 30), Pair(29, 44), Pair(-23, -16), Pair(-30, 96), Pair(-1, 3), Pair(4, -17), Pair(-12, 20),
        Pair(-3, 6), Pair(-5, 16), Pair(8, 9), Pair(-2, -8), Pair(2, 14), Pair(-10, 12), Pair(5, -1), Pair(2, 5),
        Pair(4, 4), Pair(-3, 2), Pair(7, 1), Pair(-4, -4), Pair(-3, 5), Pair(-5, 0), Pair(-4, 6), Pair(-3, 8),
        Pair(2, 5), Pair(-2, 3), Pair(0, -2), Pair(-3, 0), Pair(-5, 5), Pair(-2, 1), Pair(-4, 4), Pair(-5, 8),
        Pair(2, -2), Pair(2, -6), Pair(0, -7), Pair(0, 0), Pair(-1, -11), Pair(-4, -1), Pair(-3, -3), Pair(-3, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-23, 72), Pair(-28, -189), Pair(-81, 111), Pair(-21, -118), Pair(15, -23), Pair(-44, -85), Pair(1, 42), Pair(76, 2),
        Pair(-20, -45), Pair(-51, 74), Pair(10, 0), Pair(0, 0), Pair(-28, -16), Pair(-12, -55), Pair(8, -31), Pair(33, -71),
        Pair(-19, 13), Pair(25, 14), Pair(-388, -35), Pair(22, 34), Pair(-82, -14), Pair(-65, 30), Pair(-25, -21), Pair(-20, 19),
        Pair(7, 10), Pair(3, 28), Pair(-1, 2), Pair(-17, 42), Pair(-25, -4), Pair(9, 41), Pair(10, -11), Pair(7, -3),
        Pair(7, 10), Pair(-29, 21), Pair(-16, 25), Pair(-7, 23), Pair(-1, 21), Pair(8, 13), Pair(-37, 76), Pair(-8, 43),
        Pair(-4, 24), Pair(1, 12), Pair(6, 2), Pair(-4, 4), Pair(13, 12), Pair(-2, -5), Pair(-8, 38), Pair(-2, 53),
        Pair(40, -91), Pair(6, 33), Pair(3, 18), Pair(6, 3), Pair(6, 4), Pair(24, -31), Pair(32, -74), Pair(-22, 24),
        Pair(-21, 42), Pair(1, 28), Pair(-21, -27), Pair(-10, -21), Pair(6, 21), Pair(8, 40), Pair(3, 7), Pair(-87, 189)
      },
      { // Piece 2
        Pair(-11, -46), Pair(-110, 57), Pair(-39, -72), Pair(13, -5), Pair(-60, 0), Pair(216, 9), Pair(53, 18), Pair(48, -51),
        Pair(-58, 93), Pair(-14, 33), Pair(-10, 28), Pair(0, 0), Pair(-70, 88), Pair(-62, 86), Pair(-19, 65), Pair(35, -85),
        Pair(-23, 27), Pair(15, 23), Pair(-271, -262), Pair(24, 71), Pair(-45, 31), Pair(-52, 29), Pair(15, 2), Pair(12, -7),
        Pair(18, 6), Pair(-9, 8), Pair(-23, 40), Pair(6, -32), Pair(0, 36), Pair(9, 19), Pair(0, 28), Pair(-25, 53),
        Pair(-30, 71), Pair(2, 28), Pair(-22, 15), Pair(-12, 67), Pair(6, -4), Pair(1, 23), Pair(-32, 51), Pair(1, 13),
        Pair(11, 29), Pair(-6, -26), Pair(2, 22), Pair(-3, 12), Pair(0, 26), Pair(-2, 7), Pair(-2, 78), Pair(-17, 21),
        Pair(4, -36), Pair(10, 19), Pair(-6, 29), Pair(8, 5), Pair(-6, 15), Pair(4, 18), Pair(8, -1), Pair(-5, -43),
        Pair(7, 48), Pair(-14, 15), Pair(5, 27), Pair(-20, 64), Pair(-1, 33), Pair(-11, -3), Pair(15, -11), Pair(-15, -28)
      },
      { // Piece 3
        Pair(-16, 38), Pair(-50, 35), Pair(151, -29), Pair(-92, 20), Pair(-38, 44), Pair(99, -21), Pair(-200, 120), Pair(-3, 12),
        Pair(-22, 32), Pair(-1, 10), Pair(-1, 0), Pair(0, 0), Pair(-79, 48), Pair(8, 55), Pair(16, 2), Pair(-47, 19),
        Pair(-39, 29), Pair(-12, 19), Pair(-28, -23), Pair(40, -11), Pair(42, 47), Pair(15, 7), Pair(5, 16), Pair(-24, 22),
        Pair(-9, -9), Pair(26, 8), Pair(-4, 6), Pair(11, -9), Pair(-36, 38), Pair(-34, -8), Pair(14, 16), Pair(-6, 8),
        Pair(3, 8), Pair(-43, 58), Pair(-15, 11), Pair(14, -9), Pair(-23, 30), Pair(-14, 2), Pair(-51, 56), Pair(36, 3),
        Pair(-2, 21), Pair(7, 0), Pair(1, -5), Pair(-11, 20), Pair(0, -3), Pair(13, 24), Pair(-5, 9), Pair(-30, 31),
        Pair(-7, -7), Pair(7, -14), Pair(-28, 13), Pair(0, -14), Pair(-16, -3), Pair(-11, 15), Pair(6, 11), Pair(11, -70),
        Pair(-9, 13), Pair(-14, 8), Pair(-11, 2), Pair(-11, 13), Pair(-11, 20), Pair(-5, 11), Pair(5, -12), Pair(-2, 16)
      },
      { // Piece 4
        Pair(-16, 68), Pair(39, 3), Pair(76, -102), Pair(69, -84), Pair(-111, 144), Pair(-40, 81), Pair(25, 29), Pair(145, 7),
        Pair(-22, 37), Pair(-38, 130), Pair(69, -56), Pair(0, 0), Pair(-64, 103), Pair(-17, 177), Pair(-10, 96), Pair(23, 52),
        Pair(-37, 53), Pair(1, -32), Pair(72, 13), Pair(18, 9), Pair(37, 4), Pair(-3, 117), Pair(77, -113), Pair(24, 10),
        Pair(-27, 72), Pair(16, 6), Pair(8, 33), Pair(13, 0), Pair(9, 45), Pair(13, 45), Pair(10, 21), Pair(31, -59),
        Pair(-10, 50), Pair(-14, 83), Pair(12, -53), Pair(12, 49), Pair(17, 34), Pair(29, 11), Pair(12, 28), Pair(16, -28),
        Pair(0, -3), Pair(-9, 61), Pair(-5, 14), Pair(13, -14), Pair(2, -7), Pair(16, -30), Pair(-13, 57), Pair(1, 83),
        Pair(16, -54), Pair(-8, 43), Pair(0, 3), Pair(14, -22), Pair(1, 33), Pair(14, -38), Pair(19, -40), Pair(83, -224),
        Pair(-33, 88), Pair(10, -6), Pair(-6, 76), Pair(3, 28), Pair(8, -53), Pair(-40, 134), Pair(74, 50), Pair(-81, -16)
      },
      { // Piece 5
        Pair(0, 0), Pair(6, -76), Pair(14, 55), Pair(-7, -2), Pair(-2, 56), Pair(0, 8), Pair(0, -51), Pair(-42, -80),
        Pair(8, -35), Pair(-19, -23), Pair(73, 57), Pair(0, 0), Pair(-22, -13), Pair(2, -17), Pair(-44, -45), Pair(-85, -169),
        Pair(-62, -156), Pair(12, 40), Pair(0, 0), Pair(17, -127), Pair(0, 0), Pair(60, 24), Pair(114, -25), Pair(-19, 22),
        Pair(-32, 6), Pair(-38, 7), Pair(-107, -1), Pair(63, -48), Pair(6, 1), Pair(154, -45), Pair(-105, 30), Pair(-45, 18),
        Pair(-145, -42), Pair(-17, 2), Pair(73, -7), Pair(-20, -20), Pair(-42, -8), Pair(-112, 11), Pair(115, -23), Pair(116, -23),
        Pair(-157, 57), Pair(-74, 19), Pair(-13, -8), Pair(42, -23), Pair(-43, 24), Pair(39, 3), Pair(3, 9), Pair(-42, 6),
        Pair(34, -12), Pair(-35, 14), Pair(-18, 21), Pair(44, -38), Pair(-13, 13), Pair(-10, 20), Pair(7, 7), Pair(0, -3),
        Pair(28, -16), Pair(20, -13), Pair(-4, 13), Pair(31, -31), Pair(3, -18), Pair(4, 16), Pair(-1, 16), Pair(2, 19)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 8), Pair(25, 24), Pair(-2, 18), Pair(27, -1), Pair(0, 0), Pair(3, -8), Pair(-31, 9), Pair(-5, -13),
        Pair(3, 5), Pair(-5, 11), Pair(-1, 1), Pair(3, 20), Pair(-34, -2), Pair(-16, 47), Pair(7, 1), Pair(-4, 18),
        Pair(1, 6), Pair(1, 8), Pair(-1, 12), Pair(13, 10), Pair(-10, 7), Pair(3, 8), Pair(8, 3), Pair(2, 4),
        Pair(6, 4), Pair(2, 4), Pair(0, 6), Pair(2, 4), Pair(-3, -6), Pair(-2, 4), Pair(1, 1), Pair(0, 1),
        Pair(2, -1), Pair(4, 2), Pair(-2, 4), Pair(2, 6), Pair(-6, 1), Pair(-4, 1), Pair(1, 1), Pair(1, 1),
        Pair(1, 1), Pair(2, 6), Pair(0, 5), Pair(3, 11), Pair(0, 0), Pair(-3, -3), Pair(1, 0), Pair(1, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(47, 29), Pair(24, 13), Pair(-14, -24), Pair(-149, 119), Pair(-28, -39), Pair(-97, -36), Pair(-25, 18), Pair(66, -192),
        Pair(-11, 44), Pair(18, 36), Pair(-20, 37), Pair(3, 22), Pair(0, 0), Pair(-7, 55), Pair(13, -80), Pair(-50, 50),
        Pair(71, 34), Pair(-12, 51), Pair(-20, 17), Pair(-22, 9), Pair(-25, 67), Pair(-438, 277), Pair(18, -1), Pair(-28, -15),
        Pair(21, 2), Pair(-11, 31), Pair(-1, 33), Pair(-23, 10), Pair(-6, 29), Pair(-30, 0), Pair(2, 24), Pair(-21, -21),
        Pair(-2, 45), Pair(-28, 24), Pair(-14, 42), Pair(-23, 31), Pair(2, 23), Pair(-10, 25), Pair(-10, 36), Pair(8, 16),
        Pair(-8, 2), Pair(-14, 33), Pair(-8, 12), Pair(-7, 26), Pair(-12, 26), Pair(1, 16), Pair(-11, 23), Pair(-8, 35),
        Pair(-12, 15), Pair(9, 2), Pair(6, 20), Pair(-6, 14), Pair(-4, 22), Pair(0, -16), Pair(27, -2), Pair(15, -2),
        Pair(-82, 22), Pair(3, 20), Pair(3, 12), Pair(-3, 24), Pair(28, 9), Pair(-6, 1), Pair(0, 24), Pair(-37, -16)
      },
      { // Piece 2
        Pair(37, -13), Pair(88, -30), Pair(12, 98), Pair(73, -24), Pair(-70, 75), Pair(-59, -23), Pair(-17, -4), Pair(-89, 128),
        Pair(-7, 31), Pair(2, 16), Pair(-14, 33), Pair(-63, 80), Pair(0, 0), Pair(-25, 75), Pair(-7, 11), Pair(-61, 60),
        Pair(-16, 51), Pair(-24, 61), Pair(-29, 32), Pair(-361, 121), Pair(16, 63), Pair(-263, 221), Pair(50, 22), Pair(-9, 11),
        Pair(-24, 40), Pair(9, 27), Pair(11, 12), Pair(-38, 31), Pair(0, 20), Pair(-37, 74), Pair(4, 11), Pair(0, 34),
        Pair(6, 0), Pair(5, 8), Pair(-15, 32), Pair(-33, 35), Pair(-14, 46), Pair(-17, 15), Pair(5, 8), Pair(-10, 9),
        Pair(2, 10), Pair(-18, 30), Pair(-6, 31), Pair(-9, 42), Pair(-9, 17), Pair(-15, 46), Pair(-5, -6), Pair(2, 28),
        Pair(-17, 13), Pair(-7, 32), Pair(-1, 32), Pair(-8, 22), Pair(1, 26), Pair(-3, 28), Pair(-6, 35), Pair(-13, 24),
        Pair(-28, 32), Pair(-3, 12), Pair(-5, 23), Pair(6, 43), Pair(-20, 46), Pair(-2, 28), Pair(-17, 32), Pair(-4, 81)
      },
      { // Piece 3
        Pair(-19, 11), Pair(-46, 34), Pair(-113, 74), Pair(13, 15), Pair(-27, 24), Pair(41, 22), Pair(35, 16), Pair(-11, 48),
        Pair(8, 10), Pair(-20, 25), Pair(-7, 19), Pair(-63, 50), Pair(0, 0), Pair(-50, 23), Pair(-25, 65), Pair(-41, 30),
        Pair(26, 18), Pair(12, -4), Pair(20, 5), Pair(-148, 6), Pair(42, 17), Pair(111, -24), Pair(13, -1), Pair(12, 17),
        Pair(13, 26), Pair(6, 18), Pair(13, 4), Pair(2, -2), Pair(18, 8), Pair(-49, 42), Pair(5, 14), Pair(15, 13),
        Pair(-9, 23), Pair(-12, 27), Pair(-11, 13), Pair(-28, 11), Pair(6, -10), Pair(6, 3), Pair(-22, 1), Pair(0, 1),
        Pair(-26, 36), Pair(-4, 7), Pair(-16, 29), Pair(-2, 10), Pair(0, -10), Pair(7, -7), Pair(19, 19), Pair(-25, 24),
        Pair(-11, 29), Pair(9, 0), Pair(-8, 19), Pair(-16, 27), Pair(-1, 13), Pair(5, 2), Pair(-16, 15), Pair(27, -3),
        Pair(3, 8), Pair(-5, 16), Pair(7, 9), Pair(-2, 3), Pair(4, 19), Pair(2, 11), Pair(-8, 9), Pair(5, 22)
      },
      { // Piece 4
        Pair(12, 57), Pair(-4, 42), Pair(25, 21), Pair(45, -21), Pair(-55, 1), Pair(-10, 44), Pair(100, 10), Pair(-109, 111),
        Pair(23, -10), Pair(14, 24), Pair(44, -92), Pair(83, -91), Pair(0, 0), Pair(31, 40), Pair(46, -156), Pair(24, -28),
        Pair(27, -69), Pair(4, 43), Pair(9, 67), Pair(25, 5), Pair(43, 33), Pair(18, 6), Pair(-2, 75), Pair(10, 33),
        Pair(11, -3), Pair(3, 74), Pair(27, -43), Pair(12, -18), Pair(50, -13), Pair(-3, 72), Pair(16, 44), Pair(15, 46),
        Pair(-3, 17), Pair(2, 49), Pair(-11, 48), Pair(23, -40), Pair(22, -15), Pair(6, 47), Pair(-18, 50), Pair(11, -1),
        Pair(26, 0), Pair(-6, 12), Pair(-3, 33), Pair(-13, 47), Pair(3, 18), Pair(3, 6), Pair(4, 24), Pair(12, -42),
        Pair(3, -15), Pair(-2, 6), Pair(-3, 25), Pair(-7, 19), Pair(9, -3), Pair(11, -35), Pair(3, -8), Pair(-20, -8),
        Pair(-15, 100), Pair(-5, 41), Pair(0, 17), Pair(-1, 22), Pair(13, 13), Pair(22, 40), Pair(64, -96), Pair(18, -69)
      },
      { // Piece 5
        Pair(7, 133), Pair(3, 18), Pair(-13, -54), Pair(7, 69), Pair(-9, -52), Pair(-10, -126), Pair(26, 125), Pair(0, 0),
        Pair(10, 68), Pair(-37, 26), Pair(-13, -188), Pair(-36, -102), Pair(0, 0), Pair(62, -100), Pair(-70, -39), Pair(-27, 14),
        Pair(-18, -15), Pair(-13, 28), Pair(-31, 4), Pair(0, 0), Pair(136, -100), Pair(0, 0), Pair(-24, -51), Pair(159, -36),
        Pair(72, -32), Pair(-105, -2), Pair(-140, 10), Pair(-65, -41), Pair(66, -44), Pair(124, -33), Pair(-217, 48), Pair(-87, 17),
        Pair(-98, 19), Pair(-9, 24), Pair(-17, 26), Pair(-90, 3), Pair(21, -8), Pair(1, 2), Pair(-29, 10), Pair(-158, 43),
        Pair(70, 9), Pair(-9, 11), Pair(-1, 19), Pair(12, -16), Pair(15, -13), Pair(-8, 0), Pair(-3, 3), Pair(-34, 32),
        Pair(-68, 44), Pair(-34, 24), Pair(-15, 29), Pair(-2, 11), Pair(-4, 7), Pair(24, -2), Pair(0, 7), Pair(3, 9),
        Pair(-43, 60), Pair(-10, -10), Pair(-4, -1), Pair(41, -23), Pair(-1, -8), Pair(5, 4), Pair(3, 4), Pair(3, 8)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 17), Pair(-2, 18), Pair(-15, 17), Pair(4, 4), Pair(-7, 24), Pair(0, 0), Pair(-43, 17), Pair(-25, 11),
        Pair(7, 5), Pair(12, 7), Pair(7, 2), Pair(5, 0), Pair(7, 28), Pair(-18, 2), Pair(20, 15), Pair(4, 6),
        Pair(0, 1), Pair(4, 2), Pair(5, 6), Pair(4, 2), Pair(5, 12), Pair(-9, 1), Pair(2, 4), Pair(1, 3),
        Pair(8, 3), Pair(3, 3), Pair(5, 3), Pair(2, -2), Pair(3, 4), Pair(-5, -3), Pair(3, -2), Pair(-3, 5),
        Pair(3, 0), Pair(6, 1), Pair(3, 1), Pair(4, 1), Pair(-1, 4), Pair(-4, 4), Pair(-2, 1), Pair(-4, 1),
        Pair(4, 2), Pair(3, 2), Pair(3, -1), Pair(3, 0), Pair(4, 4), Pair(0, 0), Pair(-2, -3), Pair(-5, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-1, 37), Pair(-25, 64), Pair(2, 44), Pair(-141, 63), Pair(27, 31), Pair(-67, -43), Pair(29, 64), Pair(-108, -19),
        Pair(-13, 48), Pair(5, 31), Pair(9, 34), Pair(-27, 35), Pair(-10, 48), Pair(0, 0), Pair(-10, 25), Pair(8, 36),
        Pair(-54, 60), Pair(24, 28), Pair(6, 35), Pair(8, 12), Pair(-301, 89), Pair(29, 54), Pair(-149, 85), Pair(-19, 33),
        Pair(2, 25), Pair(4, 32), Pair(-1, 35), Pair(-6, 45), Pair(-37, 26), Pair(14, 51), Pair(-15, -5), Pair(8, 27),
        Pair(3, 16), Pair(-11, 38), Pair(-4, 40), Pair(-6, 40), Pair(-24, 31), Pair(-8, 34), Pair(3, 38), Pair(-1, 30),
        Pair(6, 37), Pair(-3, 33), Pair(1, 38), Pair(-7, 29), Pair(-3, 41), Pair(-2, 28), Pair(-8, 46), Pair(-14, 28),
        Pair(8, 31), Pair(-15, 57), Pair(1, 36), Pair(-2, 32), Pair(-4, 32), Pair(2, 45), Pair(3, 40), Pair(-4, 44),
        Pair(-34, 34), Pair(5, 37), Pair(3, 31), Pair(6, 33), Pair(-5, 39), Pair(9, 27), Pair(-6, 34), Pair(42, -96)
      },
      { // Piece 2
        Pair(-17, 46), Pair(17, 45), Pair(-120, 72), Pair(-27, 82), Pair(-98, 45), Pair(-32, 54), Pair(-211, -29), Pair(-93, 102),
        Pair(-37, 63), Pair(-31, 53), Pair(-13, 67), Pair(-41, 54), Pair(-33, 57), Pair(0, 0), Pair(-8, 57), Pair(0, 14),
        Pair(-20, 40), Pair(-7, 59), Pair(-34, 53), Pair(-2, 53), Pair(-124, -49), Pair(33, 81), Pair(-123, 46), Pair(-1, 53),
        Pair(-4, 48), Pair(-17, 46), Pair(-13, 63), Pair(-23, 40), Pair(-31, 50), Pair(-12, 38), Pair(-9, 42), Pair(-10, 21),
        Pair(-16, 40), Pair(1, 49), Pair(-22, 43), Pair(-6, 39), Pair(-39, 34), Pair(5, 44), Pair(-35, 39), Pair(17, 36),
        Pair(2, 39), Pair(-9, 38), Pair(0, 47), Pair(-17, 29), Pair(-4, 48), Pair(-14, 39), Pair(-6, 50), Pair(-18, 29),
        Pair(-26, 40), Pair(5, 36), Pair(-19, 44), Pair(1, 43), Pair(-13, 33), Pair(-1, 49), Pair(-12, 25), Pair(1, 58),
        Pair(-14, 48), Pair(-21, 66), Pair(5, 44), Pair(-11, 36), Pair(3, 42), Pair(-11, 36), Pair(-21, 59), Pair(-23, 61)
      },
      { // Piece 3
        Pair(-19, 63), Pair(-19, 62), Pair(-30, 67), Pair(-31, 60), Pair(-10, 58), Pair(-160, 90), Pair(-18, 67), Pair(8, 47),
        Pair(4, 47), Pair(-2, 42), Pair(1, 49), Pair(-12, 50), Pair(-33, 62), Pair(0, 0), Pair(2, 38), Pair(18, 41),
        Pair(10, 42), Pair(-15, 53), Pair(-7, 51), Pair(3, 51), Pair(-167, 43), Pair(42, 34), Pair(38, -28), Pair(-3, 46),
        Pair(11, 41), Pair(-5, 45), Pair(4, 56), Pair(-12, 62), Pair(-21, 52), Pair(13, 42), Pair(17, 45), Pair(-9, 59),
        Pair(2, 50), Pair(7, 48), Pair(5, 42), Pair(-15, 50), Pair(-10, 27), Pair(5, 42), Pair(-4, 33), Pair(-10, 51),
        Pair(8, 42), Pair(11, 44), Pair(-11, 52), Pair(6, 42), Pair(-9, 47), Pair(5, 44), Pair(15, 25), Pair(-7, 58),
        Pair(9, 47), Pair(16, 34), Pair(1, 54), Pair(8, 45), Pair(-8, 45), Pair(16, 27), Pair(18, 31), Pair(-4, 42),
        Pair(7, 50), Pair(1, 49), Pair(5, 43), Pair(6, 45), Pair(4, 39), Pair(7, 46), Pair(2, 33), Pair(3, 40)
      },
      { // Piece 4
        Pair(4, 30), Pair(36, 41), Pair(29, 34), Pair(-27, 80), Pair(-27, 39), Pair(-9, 12), Pair(-92, 201), Pair(-15, 97),
        Pair(17, 66), Pair(3, 67), Pair(1, 59), Pair(22, 30), Pair(14, -10), Pair(0, 0), Pair(-54, 152), Pair(-15, 123),
        Pair(1, 52), Pair(6, 71), Pair(13, 60), Pair(16, 28), Pair(-77, 7), Pair(42, 31), Pair(-59, 72), Pair(32, 81),
        Pair(13, 41), Pair(14, 69), Pair(-7, 80), Pair(11, 61), Pair(19, 59), Pair(20, 50), Pair(34, 65), Pair(22, 55),
        Pair(6, 38), Pair(15, 61), Pair(2, 73), Pair(18, 64), Pair(3, 78), Pair(28, 34), Pair(19, 81), Pair(17, 83),
        Pair(-1, 74), Pair(-1, 63), Pair(5, 56), Pair(-2, 76), Pair(8, 51), Pair(25, 34), Pair(23, 71), Pair(17, 80),
        Pair(11, 34), Pair(8, 43), Pair(5, 52), Pair(7, 54), Pair(5, 58), Pair(18, 39), Pair(4, 91), Pair(54, 33),
        Pair(8, 44), Pair(-1, 77), Pair(13, 50), Pair(8, 46), Pair(20, 43), Pair(3, 60), Pair(6, 53), Pair(24, 79)
      },
      { // Piece 5
        Pair(3, -68), Pair(6, -18), Pair(91, 25), Pair(-30, -39), Pair(-123, -58), Pair(37, -114), Pair(-71, -32), Pair(-53, -100),
        Pair(115, -32), Pair(5, -6), Pair(-145, 3), Pair(88, -39), Pair(-27, -73), Pair(0, 0), Pair(-8, -64), Pair(-39, -26),
        Pair(85, -14), Pair(-159, 35), Pair(2, -12), Pair(-72, -2), Pair(0, 0), Pair(-165, -37), Pair(0, 0), Pair(42, -38),
        Pair(1, -7), Pair(-24, 7), Pair(24, -15), Pair(-93, -2), Pair(-34, -27), Pair(-71, -30), Pair(-21, -29), Pair(-77, -12),
        Pair(14, -7), Pair(47, -7), Pair(65, -18), Pair(-34, 3), Pair(-7, -17), Pair(-10, -12), Pair(-25, -8), Pair(-41, 4),
        Pair(44, -10), Pair(25, -6), Pair(24, 4), Pair(31, -3), Pair(-6, -6), Pair(16, -8), Pair(-14, -6), Pair(3, 3),
        Pair(-15, 20), Pair(-13, 4), Pair(-1, 6), Pair(4, 3), Pair(-11, 5), Pair(7, -4), Pair(-4, 4), Pair(3, 3),
        Pair(-13, 10), Pair(-10, 8), Pair(-9, 6), Pair(5, 3), Pair(1, -4), Pair(-14, 9), Pair(-7, -6), Pair(15, -6)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, 24), Pair(31, 7), Pair(-16, 19), Pair(7, 14), Pair(20, -10), Pair(-26, 22), Pair(0, 0), Pair(-21, 17),
        Pair(10, 7), Pair(3, 8), Pair(10, 1), Pair(-8, 8), Pair(-10, 8), Pair(-13, 16), Pair(0, -1), Pair(-1, 25),
        Pair(2, 7), Pair(6, 5), Pair(4, 6), Pair(-2, 3), Pair(-2, 0), Pair(-1, 12), Pair(4, -3), Pair(11, 11),
        Pair(5, 3), Pair(6, 3), Pair(4, 2), Pair(0, 1), Pair(1, 3), Pair(0, 6), Pair(-5, -2), Pair(-1, 6),
        Pair(3, -1), Pair(3, 1), Pair(0, 3), Pair(1, 1), Pair(1, 0), Pair(1, 7), Pair(-2, 3), Pair(-5, 4),
        Pair(4, 1), Pair(5, 0), Pair(-2, 1), Pair(2, 3), Pair(-2, -1), Pair(2, 2), Pair(0, 0), Pair(-7, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-42, 25), Pair(-186, 63), Pair(-111, 30), Pair(-212, 83), Pair(-123, 21), Pair(-20, 50), Pair(-8, 11), Pair(-74, 81),
        Pair(1, 5), Pair(26, 24), Pair(11, 12), Pair(-24, 19), Pair(-13, 27), Pair(62, 1), Pair(0, 0), Pair(-9, -44),
        Pair(-40, 15), Pair(15, 20), Pair(-6, 22), Pair(6, 22), Pair(-12, 15), Pair(-410, 218), Pair(28, 48), Pair(-56, 69),
        Pair(3, 15), Pair(5, 15), Pair(1, 25), Pair(12, 24), Pair(8, 27), Pair(-34, 21), Pair(1, 36), Pair(-21, -5),
        Pair(-2, 32), Pair(-8, 22), Pair(0, 29), Pair(-7, 32), Pair(17, 20), Pair(-26, 19), Pair(19, 1), Pair(-21, 35),
        Pair(3, 17), Pair(-4, 31), Pair(-2, 29), Pair(-1, 23), Pair(-9, 25), Pair(0, 25), Pair(-5, 23), Pair(-3, 32),
        Pair(-10, 19), Pair(-4, 15), Pair(-1, 21), Pair(-4, 26), Pair(-4, 21), Pair(-4, 0), Pair(5, 19), Pair(-6, 28),
        Pair(3, 1), Pair(-3, 24), Pair(1, 29), Pair(-7, 26), Pair(18, 13), Pair(6, 19), Pair(-2, 24), Pair(-38, 7)
      },
      { // Piece 2
        Pair(-21, 72), Pair(36, 29), Pair(2, 48), Pair(-115, 56), Pair(-78, 76), Pair(-100, 36), Pair(114, 47), Pair(0, 0),
        Pair(-44, 45), Pair(16, 42), Pair(-17, 40), Pair(-54, 77), Pair(-76, 50), Pair(-28, 59), Pair(0, 0), Pair(-7, 29),
        Pair(5, 47), Pair(-25, 41), Pair(17, 47), Pair(-35, 38), Pair(2, 58), Pair(-234, 52), Pair(4, 66), Pair(-26, -15),
        Pair(-14, 25), Pair(12, 44), Pair(-7, 30), Pair(-2, 59), Pair(-7, 11), Pair(-42, 54), Pair(9, 26), Pair(-26, 46),
        Pair(-5, 46), Pair(-14, 37), Pair(0, 53), Pair(-12, 20), Pair(4, 33), Pair(-17, 18), Pair(-5, 41), Pair(-35, 25),
        Pair(-13, 17), Pair(13, 44), Pair(-13, 21), Pair(-3, 41), Pair(-11, 26), Pair(1, 45), Pair(-7, 26), Pair(-4, 50),
        Pair(-21, 81), Pair(-14, 16), Pair(8, 33), Pair(-15, 24), Pair(4, 37), Pair(-25, 37), Pair(7, 44), Pair(-11, 19),
        Pair(-25, 34), Pair(-1, 28), Pair(-8, 15), Pair(-9, 47), Pair(-28, 33), Pair(8, 40), Pair(7, 11), Pair(-8, 75)
      },
      { // Piece 3
        Pair(6, 49), Pair(11, 55), Pair(-50, 76), Pair(-26, 61), Pair(20, 35), Pair(-30, 57), Pair(127, 9), Pair(-49, 75),
        Pair(-13, 51), Pair(12, 40), Pair(-4, 53), Pair(-13, 55), Pair(-28, 60), Pair(-52, 55), Pair(0, 0), Pair(-3, 21),
        Pair(6, 39), Pair(6, 42), Pair(-2, 42), Pair(1, 50), Pair(-17, 43), Pair(34, -65), Pair(0, 66), Pair(307, -163),
        Pair(16, 37), Pair(-15, 50), Pair(2, 46), Pair(0, 45), Pair(-5, 44), Pair(-15, 41), Pair(-10, 44), Pair(-6, 39),
        Pair(-5, 39), Pair(-11, 51), Pair(7, 32), Pair(-11, 53), Pair(-6, 36), Pair(-11, 26), Pair(1, 30), Pair(15, 6),
        Pair(-3, 45), Pair(9, 40), Pair(2, 43), Pair(-4, 45), Pair(-1, 37), Pair(7, 33), Pair(20, 24), Pair(-5, 34),
        Pair(-2, 52), Pair(8, 42), Pair(5, 41), Pair(1, 38), Pair(10, 34), Pair(13, 30), Pair(12, 22), Pair(15, 27),
        Pair(11, 40), Pair(3, 43), Pair(1, 46), Pair(5, 40), Pair(2, 39), Pair(4, 32), Pair(6, 32), Pair(-6, 36)
      },
      { // Piece 4
        Pair(-25, 66), Pair(-60, 110), Pair(-61, 120), Pair(-9, 57), Pair(38, 47), Pair(-1, 67), Pair(-77, 56), Pair(13, 4),
        Pair(7, 37), Pair(-4, 46), Pair(-26, 74), Pair(-18, 69), Pair(-19, 59), Pair(28, -8), Pair(0, 0), Pair(46, 10),
        Pair(-8, 43), Pair(26, 36), Pair(-18, 63), Pair(-1, 49), Pair(2, 30), Pair(30, -80), Pair(35, -5), Pair(29, -65),
        Pair(-3, 52), Pair(-4, 54), Pair(-5, 72), Pair(-4, 63), Pair(-12, 55), Pair(-16, 66), Pair(11, 8), Pair(-8, 70),
        Pair(-5, 45), Pair(-13, 72), Pair(-6, 50), Pair(-3, 67), Pair(-9, 78), Pair(5, 54), Pair(-3, 43), Pair(14, 48),
        Pair(-5, 55), Pair(-7, 55), Pair(2, 54), Pair(-10, 71), Pair(-14, 56), Pair(-2, 64), Pair(15, 21), Pair(15, 35),
        Pair(7, 38), Pair(-12, 61), Pair(-4, 33), Pair(-5, 58), Pair(-6, 54), Pair(-3, 48), Pair(4, 24), Pair(-24, 83),
        Pair(-11, 47), Pair(7, 16), Pair(-1, 34), Pair(1, 35), Pair(-3, 47), Pair(-29, 96), Pair(30, -41), Pair(22, 36)
      },
      { // Piece 5
        Pair(-112, -33), Pair(41, 24), Pair(43, -66), Pair(-15, 36), Pair(40, -61), Pair(81, 1), Pair(105, -25), Pair(16, 56),
        Pair(-135, -16), Pair(53, -28), Pair(-35, 14), Pair(-13, 25), Pair(103, -36), Pair(-10, -64), Pair(0, 0), Pair(5, -88),
        Pair(35, -4), Pair(103, -24), Pair(115, -14), Pair(61, -4), Pair(-21, -6), Pair(0, 0), Pair(59, -74), Pair(0, 0),
        Pair(-121, 5), Pair(84, -6), Pair(36, -16), Pair(-12, 0), Pair(-157, 10), Pair(-40, -15), Pair(-22, -22), Pair(-59, -4),
        Pair(-12, 14), Pair(32, -5), Pair(41, -5), Pair(-38, 6), Pair(-8, -5), Pair(8, -10), Pair(-48, 2), Pair(8, -12),
        Pair(27, -16), Pair(-7, -3), Pair(40, -17), Pair(46, -7), Pair(-5, -1), Pair(-1, -3), Pair(-12, -4), Pair(-17, 2),
        Pair(9, -9), Pair(8, -12), Pair(12, -2), Pair(14, -2), Pair(4, 4), Pair(14, -1), Pair(-8, 1), Pair(-2, 4),
        Pair(-23, 24), Pair(-7, -13), Pair(-3, -3), Pair(-3, 6), Pair(4, 3), Pair(1, 4), Pair(-6, 7), Pair(-5, -2)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(27, 4), Pair(11, 9), Pair(41, 10), Pair(0, 13), Pair(8, -6), Pair(-36, 12), Pair(-17, 1), Pair(0, 0),
        Pair(5, 10), Pair(1, 6), Pair(9, 3), Pair(4, 3), Pair(-10, 6), Pair(-19, 6), Pair(-10, 9), Pair(5, -11),
        Pair(3, 4), Pair(3, 3), Pair(4, 4), Pair(-1, 2), Pair(-7, 2), Pair(-5, 1), Pair(0, 3), Pair(9, -6),
        Pair(4, 2), Pair(3, -1), Pair(2, -2), Pair(0, 0), Pair(-2, 3), Pair(0, 2), Pair(1, -2), Pair(0, -2),
        Pair(0, 0), Pair(0, -2), Pair(0, -2), Pair(-3, -4), Pair(2, -1), Pair(3, 1), Pair(2, 2), Pair(0, 1),
        Pair(1, 2), Pair(1, -1), Pair(-1, -3), Pair(2, -3), Pair(-2, 2), Pair(5, -4), Pair(2, -2), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-65, 16), Pair(-44, -3), Pair(41, -19), Pair(110, 33), Pair(-65, 66), Pair(-122, 21), Pair(13, 62), Pair(-36, -140),
        Pair(-13, 29), Pair(-4, 6), Pair(-12, 25), Pair(40, 16), Pair(-4, 30), Pair(-20, 48), Pair(-23, 12), Pair(0, 0),
        Pair(42, -11), Pair(-5, 15), Pair(7, 22), Pair(2, 30), Pair(1, 18), Pair(26, 9), Pair(-56, -145), Pair(10, 70),
        Pair(-2, 12), Pair(2, 23), Pair(9, 25), Pair(13, 20), Pair(11, 31), Pair(13, 31), Pair(-12, 26), Pair(19, 46),
        Pair(6, 11), Pair(10, 5), Pair(3, 19), Pair(9, 29), Pair(11, 26), Pair(27, 24), Pair(-7, 30), Pair(-6, 13),
        Pair(-2, 17), Pair(-1, 19), Pair(7, 20), Pair(-1, 19), Pair(13, 20), Pair(3, 27), Pair(7, 36), Pair(-1, 44),
        Pair(17, 4), Pair(3, 13), Pair(-14, 32), Pair(0, 17), Pair(4, 24), Pair(-1, 30), Pair(-4, 33), Pair(5, 25),
        Pair(56, -66), Pair(-5, 30), Pair(-26, 36), Pair(10, 3), Pair(4, 28), Pair(-7, 27), Pair(-8, 44), Pair(-6, 33)
      },
      { // Piece 2
        Pair(-11, 59), Pair(-47, 79), Pair(-56, 65), Pair(-82, 58), Pair(-72, 25), Pair(-71, 90), Pair(-27, 63), Pair(-6, 25),
        Pair(-3, 53), Pair(10, 46), Pair(-28, 59), Pair(-57, 86), Pair(-30, 62), Pair(-38, 44), Pair(-17, 48), Pair(0, 0),
        Pair(-31, 54), Pair(-30, 51), Pair(-20, 56), Pair(-17, 68), Pair(-15, 56), Pair(-9, 61), Pair(-33, -130), Pair(11, 78),
        Pair(-35, 48), Pair(-2, 39), Pair(3, 48), Pair(-4, 53), Pair(13, 50), Pair(-19, 55), Pair(-16, 47), Pair(4, 44),
        Pair(-9, 37), Pair(-20, 50), Pair(-2, 45), Pair(1, 37), Pair(-5, 45), Pair(3, 48), Pair(0, 28), Pair(-3, 36),
        Pair(2, 50), Pair(12, 45), Pair(6, 43), Pair(-9, 41), Pair(4, 41), Pair(2, 42), Pair(5, 41), Pair(6, 49),
        Pair(8, 48), Pair(6, 34), Pair(-15, 25), Pair(-8, 38), Pair(-4, 44), Pair(3, 37), Pair(11, 37), Pair(16, 5),
        Pair(10, 36), Pair(-3, 36), Pair(-3, 34), Pair(-3, 36), Pair(-5, 23), Pair(-3, 39), Pair(-14, 38), Pair(4, 39)
      },
      { // Piece 3
        Pair(38, 54), Pair(-10, 80), Pair(-29, 83), Pair(-6, 73), Pair(-43, 77), Pair(3, 74), Pair(18, 67), Pair(-163, 117),
        Pair(12, 72), Pair(5, 70), Pair(12, 64), Pair(15, 68), Pair(31, 60), Pair(-5, 79), Pair(43, 52), Pair(0, 0),
        Pair(9, 62), Pair(0, 66), Pair(-5, 70), Pair(8, 67), Pair(5, 68), Pair(-33, 91), Pair(-78, -80), Pair(-4, 75),
        Pair(7, 66), Pair(21, 61), Pair(12, 72), Pair(17, 52), Pair(11, 70), Pair(-2, 59), Pair(9, 65), Pair(-3, 66),
        Pair(6, 64), Pair(16, 65), Pair(17, 61), Pair(-11, 65), Pair(10, 63), Pair(2, 58), Pair(-32, 62), Pair(-26, 56),
        Pair(3, 63), Pair(21, 50), Pair(14, 52), Pair(14, 51), Pair(2, 51), Pair(4, 57), Pair(18, 42), Pair(-25, 68),
        Pair(30, 40), Pair(21, 50), Pair(5, 62), Pair(9, 60), Pair(5, 61), Pair(6, 57), Pair(1, 81), Pair(0, 52),
        Pair(10, 67), Pair(2, 70), Pair(11, 65), Pair(8, 61), Pair(5, 60), Pair(8, 60), Pair(-18, 68), Pair(-7, 62)
      },
      { // Piece 4
        Pair(-33, 152), Pair(-23, 149), Pair(55, 53), Pair(-68, 164), Pair(13, 72), Pair(-107, 193), Pair(218, -9), Pair(-42, 118),
        Pair(-4, 104), Pair(-15, 114), Pair(17, 86), Pair(-39, 147), Pair(-28, 159), Pair(0, 114), Pair(-16, 137), Pair(0, 0),
        Pair(21, 79), Pair(9, 100), Pair(-6, 118), Pair(7, 115), Pair(-29, 173), Pair(-20, 153), Pair(26, 29), Pair(17, 66),
        Pair(-10, 114), Pair(0, 113), Pair(-11, 125), Pair(-3, 125), Pair(-10, 142), Pair(4, 123), Pair(-31, 143), Pair(-6, 102),
        Pair(4, 109), Pair(-4, 108), Pair(0, 87), Pair(3, 120), Pair(-8, 136), Pair(2, 113), Pair(-1, 93), Pair(-8, 117),
        Pair(-8, 117), Pair(-1, 100), Pair(14, 82), Pair(0, 109), Pair(-1, 101), Pair(-7, 117), Pair(7, 103), Pair(1, 96),
        Pair(3, 93), Pair(9, 66), Pair(3, 77), Pair(7, 70), Pair(2, 83), Pair(13, 83), Pair(33, 36), Pair(47, -37),
        Pair(19, 60), Pair(-3, 90), Pair(10, 91), Pair(8, 79), Pair(12, 64), Pair(-18, 123), Pair(-10, 134), Pair(3, 98)
      },
      { // Piece 5
        Pair(-68, 70), Pair(64, 16), Pair(127, -139), Pair(-52, -94), Pair(-50, 81), Pair(65, 18), Pair(-29, 2), Pair(0, 14),
        Pair(-138, -6), Pair(110, -51), Pair(-110, 49), Pair(-88, -15), Pair(86, 6), Pair(-190, -33), Pair(-35, -81), Pair(0, 0),
        Pair(19, -19), Pair(-7, 1), Pair(-55, 8), Pair(74, -26), Pair(-43, -5), Pair(-95, -18), Pair(0, 0), Pair(89, -50),
        Pair(81, -13), Pair(34, -21), Pair(1, -9), Pair(-15, 0), Pair(22, -11), Pair(-63, -13), Pair(-52, -1), Pair(-120, 16),
        Pair(-24, 4), Pair(73, -25), Pair(45, -17), Pair(15, -4), Pair(18, 0), Pair(-6, 2), Pair(-25, -9), Pair(-29, -12),
        Pair(-39, 18), Pair(37, -12), Pair(27, -15), Pair(41, -5), Pair(39, -9), Pair(-14, 11), Pair(5, -3), Pair(-29, 7),
        Pair(11, -5), Pair(-5, -1), Pair(18, -7), Pair(2, 0), Pair(-7, 7), Pair(9, 6), Pair(-6, 11), Pair(-8, 7),
        Pair(8, 5), Pair(-10, -2), Pair(-1, -9), Pair(29, -8), Pair(8, -2), Pair(5, 10), Pair(0, 16), Pair(-5, 23)
      }
    }},
    {{ // Bucket 56
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 57
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 58
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 59
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 60
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 61
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 62
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 63
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
  }},
  {{ // Bucket 1
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 7
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 8
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-22, 12), Pair(-132, 83), Pair(32, 52), Pair(-16, 42), Pair(89, 85), Pair(-100, 33), Pair(-38, 31), Pair(69, 47),
        Pair(17, -93), Pair(-80, 37), Pair(-32, 45), Pair(-31, 39), Pair(-69, 48), Pair(-8, 43), Pair(56, 8), Pair(-51, 17),
        Pair(-3, 9), Pair(-5, 35), Pair(16, 2), Pair(3, 3), Pair(58, 11), Pair(-27, 12), Pair(-18, 9), Pair(25, -4),
        Pair(23, -1), Pair(-18, 29), Pair(-11, 12), Pair(7, 10), Pair(-12, 11), Pair(-3, 6), Pair(-18, 20), Pair(11, 7),
        Pair(32, 17), Pair(-10, 12), Pair(3, 10), Pair(-13, 5), Pair(-1, 13), Pair(17, -3), Pair(-31, 20), Pair(-6, 14),
        Pair(39, 0), Pair(-5, 23), Pair(-4, 22), Pair(-29, 2), Pair(8, 7), Pair(11, 8), Pair(-13, 23), Pair(-19, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-26, 41), Pair(6, 60), Pair(151, 48), Pair(-17, 61), Pair(43, 2), Pair(-33, 14), Pair(11, 121), Pair(-3, -21),
        Pair(0, 0), Pair(-25, 3), Pair(-71, 4), Pair(-32, -10), Pair(-30, 99), Pair(-53, -72), Pair(37, 153), Pair(-105, -86),
        Pair(122, 60), Pair(-123, 71), Pair(38, 1), Pair(82, 15), Pair(158, -52), Pair(181, -61), Pair(56, -44), Pair(-7, 50),
        Pair(-67, 60), Pair(23, 8), Pair(59, -17), Pair(-41, 107), Pair(74, -4), Pair(41, -17), Pair(4, -3), Pair(138, -37),
        Pair(-107, 74), Pair(7, 1), Pair(43, -31), Pair(44, 20), Pair(103, -49), Pair(28, -19), Pair(75, -38), Pair(101, -110),
        Pair(20, -60), Pair(53, -62), Pair(-70, 22), Pair(208, -86), Pair(-60, -5), Pair(71, -53), Pair(71, 41), Pair(138, -94),
        Pair(-76, 0), Pair(-49, 43), Pair(72, 9), Pair(-54, -22), Pair(-122, 21), Pair(26, 45), Pair(22, 28), Pair(128, -83),
        Pair(-82, -12), Pair(34, -43), Pair(22, 60), Pair(-48, 27), Pair(63, 25), Pair(44, -109), Pair(-107, 61), Pair(43, -131)
      },
      { // Piece 2
        Pair(-43, -77), Pair(144, -2), Pair(39, 30), Pair(71, -96), Pair(22, -61), Pair(-41, -82), Pair(74, 2), Pair(-38, -100),
        Pair(0, 0), Pair(66, 77), Pair(216, -72), Pair(30, -40), Pair(100, -70), Pair(31, -69), Pair(199, -117), Pair(47, -88),
        Pair(57, -31), Pair(88, -15), Pair(-29, 56), Pair(170, -56), Pair(-37, -21), Pair(135, -71), Pair(123, -14), Pair(10, -3),
        Pair(-115, -6), Pair(8, 12), Pair(56, 4), Pair(2, 44), Pair(267, -117), Pair(-53, 15), Pair(-8, -76), Pair(3, -18),
        Pair(-52, 8), Pair(81, -59), Pair(10, 15), Pair(160, -12), Pair(116, 52), Pair(-12, -18), Pair(-1, 3), Pair(9, -57),
        Pair(-44, -79), Pair(54, -91), Pair(-33, -22), Pair(-34, 27), Pair(62, -26), Pair(-12, -3), Pair(55, -22), Pair(-38, 60),
        Pair(20, -118), Pair(21, -48), Pair(-178, 70), Pair(-51, 7), Pair(63, 10), Pair(52, -22), Pair(48, -20), Pair(-170, -13),
        Pair(164, -109), Pair(35, -57), Pair(0, 19), Pair(95, -81), Pair(81, -8), Pair(12, 13), Pair(70, -60), Pair(-91, 195)
      },
      { // Piece 3
        Pair(92, -161), Pair(39, 129), Pair(4, 61), Pair(-82, 6), Pair(-53, 89), Pair(-18, 55), Pair(36, 40), Pair(24, 70),
        Pair(0, 0), Pair(105, -2), Pair(195, -36), Pair(174, -34), Pair(178, -53), Pair(155, -20), Pair(1, 28), Pair(163, -18),
        Pair(22, 20), Pair(52, 21), Pair(13, 44), Pair(-77, 90), Pair(-119, 110), Pair(-7, 64), Pair(79, 45), Pair(29, 35),
        Pair(8, 19), Pair(-4, 72), Pair(65, 28), Pair(36, 7), Pair(247, -28), Pair(-11, 21), Pair(-220, 115), Pair(-234, 137),
        Pair(-57, 55), Pair(105, 39), Pair(-69, 61), Pair(95, -1), Pair(-122, 99), Pair(-5, -106), Pair(57, 62), Pair(66, -12),
        Pair(38, 9), Pair(-38, 82), Pair(72, 8), Pair(-66, 61), Pair(-135, 181), Pair(-118, 34), Pair(35, 16), Pair(105, -5),
        Pair(-6, 23), Pair(24, 56), Pair(-50, 75), Pair(41, 25), Pair(-68, 83), Pair(-115, 23), Pair(-35, 53), Pair(-29, 44),
        Pair(-1, -7), Pair(77, 5), Pair(75, -24), Pair(54, -11), Pair(-63, 62), Pair(-23, 32), Pair(22, 77), Pair(-3, -3)
      },
      { // Piece 4
        Pair(-87, -212), Pair(37, -123), Pair(17, 43), Pair(-71, -97), Pair(43, 66), Pair(-113, -101), Pair(121, 76), Pair(-95, -71),
        Pair(0, 0), Pair(-62, 84), Pair(-49, 10), Pair(155, -135), Pair(23, -15), Pair(-121, 28), Pair(-2, 29), Pair(-3, -82),
        Pair(-5, 50), Pair(-28, 26), Pair(36, -75), Pair(-70, 101), Pair(-49, -87), Pair(18, 76), Pair(153, 11), Pair(24, -40),
        Pair(-84, 8), Pair(-25, 59), Pair(-24, -65), Pair(19, 124), Pair(20, 39), Pair(29, -124), Pair(-54, -96), Pair(-14, -136),
        Pair(-56, 54), Pair(-111, 140), Pair(-26, 20), Pair(53, -53), Pair(95, -248), Pair(47, -58), Pair(-220, 18), Pair(152, 75),
        Pair(-61, 130), Pair(74, -91), Pair(-56, -51), Pair(0, -1), Pair(-83, 65), Pair(-35, 74), Pair(61, -57), Pair(35, -19),
        Pair(62, -140), Pair(6, -147), Pair(39, -159), Pair(-27, -78), Pair(-3, -50), Pair(4, -133), Pair(-39, 8), Pair(19, -127),
        Pair(-18, -17), Pair(-45, -90), Pair(-52, 49), Pair(4, 85), Pair(98, -141), Pair(45, -161), Pair(-66, -45), Pair(-25, -23)
      },
      { // Piece 5
        Pair(-92, -150), Pair(-54, 51), Pair(89, 121), Pair(29, 64), Pair(5, 18), Pair(-4, -36), Pair(-8, 19), Pair(22, 83),
        Pair(0, 0), Pair(-7, 118), Pair(-47, 56), Pair(48, 23), Pair(76, 80), Pair(-108, -56), Pair(25, -14), Pair(2, 11),
        Pair(-75, -26), Pair(68, 59), Pair(69, 54), Pair(-138, 18), Pair(-154, -18), Pair(33, -29), Pair(-44, -44), Pair(10, 101),
        Pair(60, -1), Pair(50, 43), Pair(41, 14), Pair(-35, 82), Pair(111, -19), Pair(-16, 27), Pair(-24, -36), Pair(-192, 4),
        Pair(-130, 45), Pair(12, 58), Pair(35, 18), Pair(76, 4), Pair(101, -29), Pair(-26, -15), Pair(23, -42), Pair(-57, -39),
        Pair(-221, 100), Pair(-116, 59), Pair(128, 1), Pair(-85, 19), Pair(134, -29), Pair(68, -30), Pair(-26, -32), Pair(-12, -39),
        Pair(-74, 42), Pair(211, -18), Pair(50, -17), Pair(-125, 21), Pair(-69, 6), Pair(14, -19), Pair(6, -29), Pair(-26, -15),
        Pair(-150, -44), Pair(122, -66), Pair(-14, -1), Pair(-56, 6), Pair(4, -22), Pair(82, -69), Pair(10, -47), Pair(-43, -36)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-132, 83), Pair(-16, 22), Pair(74, -64), Pair(-93, 39), Pair(-54, 15), Pair(-4, -13), Pair(-1, 18), Pair(37, 23),
        Pair(-41, 9), Pair(-50, -71), Pair(13, -29), Pair(-9, 53), Pair(-45, 22), Pair(30, 39), Pair(48, 42), Pair(54, 17),
        Pair(-2, 37), Pair(4, -10), Pair(-4, 16), Pair(-5, 15), Pair(6, 25), Pair(-35, 15), Pair(-24, 24), Pair(44, -9),
        Pair(-16, 41), Pair(-3, -22), Pair(-32, 31), Pair(-5, 9), Pair(10, -3), Pair(0, 13), Pair(23, -3), Pair(34, 8),
        Pair(-28, 20), Pair(-43, 13), Pair(-61, 17), Pair(-3, 2), Pair(-1, 10), Pair(-19, 7), Pair(11, 0), Pair(6, 12),
        Pair(-17, 24), Pair(-18, 13), Pair(-66, 29), Pair(-42, 11), Pair(40, 13), Pair(-26, 20), Pair(5, 9), Pair(-17, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-33, -55), Pair(34, 148), Pair(-27, 8), Pair(28, 21), Pair(-14, -129), Pair(-10, 61), Pair(-54, -137), Pair(-14, -48),
        Pair(-16, -41), Pair(0, 0), Pair(139, -41), Pair(104, 102), Pair(46, -40), Pair(28, 45), Pair(41, 162), Pair(73, 116),
        Pair(-7, 70), Pair(66, 6), Pair(276, 4), Pair(20, -1), Pair(160, -23), Pair(50, 11), Pair(-209, 22), Pair(109, 7),
        Pair(68, 14), Pair(28, 52), Pair(-20, 36), Pair(108, 3), Pair(9, 53), Pair(-143, 57), Pair(-47, -29), Pair(108, 50),
        Pair(-92, 32), Pair(153, 123), Pair(119, -1), Pair(63, 3), Pair(14, 36), Pair(68, -41), Pair(10, 9), Pair(-25, -50),
        Pair(-52, -98), Pair(-22, 43), Pair(34, -7), Pair(-40, 77), Pair(-8, 26), Pair(82, 22), Pair(-108, 102), Pair(-25, 109),
        Pair(12, -25), Pair(101, 8), Pair(-170, 19), Pair(-17, 12), Pair(24, 4), Pair(-13, 1), Pair(24, -37), Pair(110, -65),
        Pair(-41, -42), Pair(-172, 129), Pair(27, 46), Pair(113, -20), Pair(-196, 49), Pair(45, -76), Pair(7, -116), Pair(33, 54)
      },
      { // Piece 2
        Pair(-146, -240), Pair(48, -93), Pair(127, -4), Pair(-21, 28), Pair(27, -93), Pair(21, 43), Pair(5, -80), Pair(63, 91),
        Pair(98, -18), Pair(0, 0), Pair(-87, 51), Pair(-66, -92), Pair(97, 77), Pair(34, -70), Pair(-93, 60), Pair(-134, -76),
        Pair(59, -27), Pair(132, 99), Pair(183, -59), Pair(-59, 152), Pair(119, -87), Pair(109, 36), Pair(80, -89), Pair(-99, 51),
        Pair(3, 45), Pair(115, -81), Pair(-112, 108), Pair(160, -22), Pair(162, 42), Pair(287, -96), Pair(-27, 26), Pair(201, -150),
        Pair(114, -115), Pair(139, -69), Pair(72, -43), Pair(8, -13), Pair(135, -30), Pair(72, 31), Pair(8, -8), Pair(-27, 96),
        Pair(14, -26), Pair(15, -70), Pair(-64, 39), Pair(37, -37), Pair(29, 10), Pair(51, -13), Pair(170, -25), Pair(103, -54),
        Pair(106, -99), Pair(-13, -6), Pair(-110, -71), Pair(-16, 6), Pair(-10, 22), Pair(-8, -19), Pair(80, -26), Pair(-103, 116),
        Pair(-50, 52), Pair(50, -128), Pair(14, -25), Pair(93, -62), Pair(69, -80), Pair(132, -77), Pair(150, -86), Pair(18, -16)
      },
      { // Piece 3
        Pair(-5, 79), Pair(21, -178), Pair(234, 36), Pair(-47, 130), Pair(-76, 18), Pair(14, 55), Pair(110, 31), Pair(3, 106),
        Pair(13, 27), Pair(0, 0), Pair(101, -8), Pair(104, -6), Pair(199, -65), Pair(5, 20), Pair(-135, 57), Pair(-7, 12),
        Pair(-68, 53), Pair(9, 21), Pair(38, 6), Pair(151, -32), Pair(-51, 46), Pair(11, 65), Pair(102, -30), Pair(24, 11),
        Pair(11, 53), Pair(169, -17), Pair(31, 57), Pair(-35, 36), Pair(-150, 90), Pair(58, 55), Pair(102, 24), Pair(34, 39),
        Pair(-99, 83), Pair(121, 30), Pair(30, 31), Pair(-74, 48), Pair(147, -8), Pair(8, 81), Pair(21, 47), Pair(-99, 49),
        Pair(-81, 80), Pair(-80, 34), Pair(75, 66), Pair(144, -53), Pair(-87, 30), Pair(-35, 60), Pair(-77, 43), Pair(-16, -93),
        Pair(37, -26), Pair(35, 2), Pair(-6, -37), Pair(149, -87), Pair(47, 21), Pair(-37, 13), Pair(135, -86), Pair(75, -7),
        Pair(6, 33), Pair(-36, 12), Pair(-1, 37), Pair(-31, 86), Pair(-58, 82), Pair(15, 3), Pair(-50, 63), Pair(-5, -65)
      },
      { // Piece 4
        Pair(119, -141), Pair(-89, -59), Pair(73, -11), Pair(120, -6), Pair(2, 10), Pair(-32, -78), Pair(-43, -87), Pair(-9, -68),
        Pair(72, -149), Pair(0, 0), Pair(11, 23), Pair(-59, -26), Pair(56, -32), Pair(85, -68), Pair(-74, -124), Pair(-65, -164),
        Pair(12, -52), Pair(65, 7), Pair(20, 45), Pair(148, 114), Pair(-29, -3), Pair(-48, -17), Pair(-52, -9), Pair(-46, 21),
        Pair(61, -66), Pair(-101, 74), Pair(-100, 30), Pair(-52, 123), Pair(82, 67), Pair(106, -40), Pair(-61, -33), Pair(30, -166),
        Pair(98, -12), Pair(-61, -60), Pair(55, 75), Pair(55, -22), Pair(-78, 34), Pair(1, 14), Pair(-13, -43), Pair(-162, -17),
        Pair(136, -257), Pair(38, -38), Pair(-112, -49), Pair(60, -33), Pair(68, -55), Pair(-16, 55), Pair(-137, 37), Pair(-46, 46),
        Pair(-112, 2), Pair(-110, 168), Pair(-78, 71), Pair(-3, -48), Pair(22, -46), Pair(51, -90), Pair(-104, 108), Pair(-35, -36),
        Pair(-23, -223), Pair(-109, 17), Pair(47, -206), Pair(-72, 51), Pair(-134, 35), Pair(-48, 18), Pair(58, 12), Pair(83, 15)
      },
      { // Piece 5
        Pair(28, 157), Pair(29, 27), Pair(61, 38), Pair(113, 230), Pair(-17, -107), Pair(-1, 16), Pair(-4, -59), Pair(-1, -2),
        Pair(27, 143), Pair(0, 0), Pair(131, 80), Pair(-40, 19), Pair(80, -63), Pair(-1, -14), Pair(-38, -7), Pair(-2, -25),
        Pair(31, 82), Pair(3, 31), Pair(72, 53), Pair(10, 21), Pair(47, -42), Pair(25, -13), Pair(-50, -53), Pair(-20, 50),
        Pair(11, 86), Pair(107, 10), Pair(70, 33), Pair(114, -9), Pair(95, -18), Pair(147, -53), Pair(-5, -19), Pair(-59, 5),
        Pair(-55, -14), Pair(107, -61), Pair(55, 21), Pair(87, -17), Pair(36, -17), Pair(-110, 26), Pair(-49, -20), Pair(36, -52),
        Pair(-11, -36), Pair(-162, 37), Pair(34, -55), Pair(-64, 7), Pair(-109, 1), Pair(-67, -15), Pair(-173, -29), Pair(-157, -20),
        Pair(117, -51), Pair(175, 23), Pair(-18, 38), Pair(-31, 34), Pair(-146, 13), Pair(-159, 21), Pair(-24, -23), Pair(-60, -39),
        Pair(-2, 8), Pair(-45, 4), Pair(159, 21), Pair(30, -41), Pair(-131, -25), Pair(-125, -8), Pair(-28, -50), Pair(-12, -72)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(32, 52), Pair(74, -64), Pair(25, 16), Pair(124, -7), Pair(-47, 46), Pair(36, 72), Pair(-4, -24), Pair(-8, 3),
        Pair(-30, 35), Pair(57, 11), Pair(18, -91), Pair(-44, 16), Pair(-90, -12), Pair(-65, 35), Pair(-206, 79), Pair(127, -29),
        Pair(20, 14), Pair(-52, 52), Pair(-38, -3), Pair(-36, 56), Pair(-22, 21), Pair(-5, 15), Pair(60, 0), Pair(31, 20),
        Pair(12, 8), Pair(-16, 22), Pair(-39, 0), Pair(12, 15), Pair(-22, 17), Pair(16, 10), Pair(30, 2), Pair(13, 3),
        Pair(8, 17), Pair(-65, 27), Pair(-102, 37), Pair(-7, 9), Pair(11, 9), Pair(1, -1), Pair(17, -1), Pair(11, 12),
        Pair(-20, 20), Pair(-6, 11), Pair(-14, 13), Pair(-46, -7), Pair(-12, 28), Pair(-18, 4), Pair(2, 3), Pair(3, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(172, 46), Pair(17, 34), Pair(31, 63), Pair(-6, 4), Pair(117, -10), Pair(52, 95), Pair(-9, -86), Pair(3, 7),
        Pair(2, 64), Pair(4, 67), Pair(0, 0), Pair(18, -111), Pair(59, 192), Pair(-42, 67), Pair(-9, -99), Pair(-134, -159),
        Pair(20, 13), Pair(-71, 99), Pair(103, 103), Pair(18, 95), Pair(14, 38), Pair(106, 56), Pair(69, -11), Pair(17, 4),
        Pair(179, -18), Pair(7, 34), Pair(-100, 85), Pair(184, -12), Pair(26, 27), Pair(-51, 129), Pair(-43, 72), Pair(-66, -24),
        Pair(-15, 102), Pair(-151, 56), Pair(-23, 42), Pair(45, -5), Pair(68, -3), Pair(80, 36), Pair(33, 40), Pair(-27, 109),
        Pair(8, 24), Pair(75, -2), Pair(17, 43), Pair(-46, 104), Pair(18, -2), Pair(65, -9), Pair(56, 8), Pair(-79, 105),
        Pair(60, -47), Pair(-62, 14), Pair(105, -39), Pair(-30, 37), Pair(-50, 4), Pair(157, -38), Pair(40, -33), Pair(-84, -27),
        Pair(-53, -19), Pair(-44, 41), Pair(-126, 24), Pair(35, -125), Pair(-73, 70), Pair(-82, 58), Pair(48, -117), Pair(-1, 54)
      },
      { // Piece 2
        Pair(6, 71), Pair(8, -25), Pair(-8, -46), Pair(200, -29), Pair(22, 51), Pair(78, 27), Pair(-11, -30), Pair(-36, -74),
        Pair(181, -29), Pair(-204, 94), Pair(0, 0), Pair(25, -17), Pair(136, -1), Pair(-15, 107), Pair(37, -27), Pair(93, 72),
        Pair(216, 43), Pair(120, -15), Pair(-26, 97), Pair(80, -33), Pair(93, 92), Pair(125, -65), Pair(107, -5), Pair(57, -104),
        Pair(30, 2), Pair(63, 37), Pair(68, -57), Pair(146, -51), Pair(168, -19), Pair(229, -62), Pair(119, 10), Pair(5, 81),
        Pair(-39, -53), Pair(198, -85), Pair(-53, 8), Pair(162, -28), Pair(-21, 53), Pair(103, 1), Pair(15, 103), Pair(5, -128),
        Pair(69, 16), Pair(44, -57), Pair(-9, -47), Pair(-85, 19), Pair(125, -52), Pair(58, -13), Pair(82, -10), Pair(114, 91),
        Pair(-3, -74), Pair(119, -72), Pair(-28, -62), Pair(-92, -2), Pair(10, 35), Pair(45, -15), Pair(16, 26), Pair(-48, 43),
        Pair(-151, -31), Pair(-30, -82), Pair(52, -79), Pair(88, 29), Pair(97, 18), Pair(48, 31), Pair(31, -114), Pair(83, 42)
      },
      { // Piece 3
        Pair(72, 66), Pair(-83, 161), Pair(97, -159), Pair(253, 17), Pair(19, 42), Pair(75, 74), Pair(77, 107), Pair(63, -7),
        Pair(9, 53), Pair(67, 5), Pair(0, 0), Pair(7, 22), Pair(-81, 34), Pair(10, 49), Pair(206, 22), Pair(29, 32),
        Pair(31, 29), Pair(-42, 73), Pair(51, 3), Pair(47, 9), Pair(-142, 111), Pair(32, 28), Pair(-15, 30), Pair(-82, 157),
        Pair(-60, 87), Pair(37, 77), Pair(25, 65), Pair(18, 62), Pair(17, 113), Pair(-43, 141), Pair(123, 40), Pair(5, 14),
        Pair(49, 31), Pair(117, 30), Pair(-53, 67), Pair(-44, 54), Pair(59, 5), Pair(-47, 19), Pair(72, 84), Pair(48, 37),
        Pair(45, 46), Pair(99, 69), Pair(-48, 62), Pair(73, 5), Pair(80, -10), Pair(37, -11), Pair(-24, -16), Pair(-33, 89),
        Pair(-54, 23), Pair(6, 91), Pair(90, 2), Pair(3, 53), Pair(206, -34), Pair(-80, 76), Pair(-69, 43), Pair(-82, 47),
        Pair(-28, 27), Pair(81, 25), Pair(20, 5), Pair(16, 16), Pair(76, -19), Pair(7, 14), Pair(17, 34), Pair(-42, 32)
      },
      { // Piece 4
        Pair(-43, -66), Pair(34, -27), Pair(-177, -171), Pair(-18, -91), Pair(113, 88), Pair(96, 70), Pair(-91, -124), Pair(47, 26),
        Pair(86, -67), Pair(-149, 45), Pair(0, 0), Pair(72, 25), Pair(-22, -5), Pair(110, -35), Pair(47, 82), Pair(47, -12),
        Pair(85, -94), Pair(33, -1), Pair(40, 20), Pair(-22, 82), Pair(83, 36), Pair(10, -51), Pair(5, -17), Pair(-122, -183),
        Pair(41, -72), Pair(-137, 106), Pair(73, 24), Pair(60, 16), Pair(-49, 1), Pair(82, -72), Pair(140, -43), Pair(10, 15),
        Pair(21, -157), Pair(-36, 5), Pair(71, -43), Pair(-54, 89), Pair(-73, 17), Pair(126, -94), Pair(-33, -29), Pair(20, 96),
        Pair(-48, 101), Pair(-46, -22), Pair(76, -100), Pair(-54, -95), Pair(-67, 13), Pair(-15, -88), Pair(88, -169), Pair(89, 74),
        Pair(-150, -67), Pair(1, -31), Pair(-8, -110), Pair(16, 91), Pair(-37, 54), Pair(0, -48), Pair(-15, -135), Pair(92, -14),
        Pair(-54, -55), Pair(-47, 6), Pair(-47, -98), Pair(-61, -63), Pair(-43, -144), Pair(-104, 30), Pair(-116, -17), Pair(5, 2)
      },
      { // Piece 5
        Pair(20, 195), Pair(96, 60), Pair(-18, -71), Pair(-36, 56), Pair(-18, 99), Pair(28, 48), Pair(28, 78), Pair(6, 83),
        Pair(-30, 87), Pair(19, 119), Pair(0, 0), Pair(40, 73), Pair(-5, 19), Pair(-19, -69), Pair(-26, -18), Pair(8, -45),
        Pair(84, 156), Pair(-56, 134), Pair(-10, 65), Pair(189, 50), Pair(-2, 30), Pair(137, -61), Pair(89, -22), Pair(28, -36),
        Pair(113, 31), Pair(157, 52), Pair(53, 37), Pair(114, -11), Pair(98, -8), Pair(64, 60), Pair(-111, -12), Pair(6, 5),
        Pair(38, 77), Pair(24, -7), Pair(-21, 6), Pair(-101, 19), Pair(-123, 35), Pair(44, -24), Pair(-45, -21), Pair(-43, -56),
        Pair(-245, -11), Pair(29, 8), Pair(70, -61), Pair(-3, -6), Pair(3, 6), Pair(-72, -48), Pair(-62, -26), Pair(-69, -61),
        Pair(-143, -46), Pair(137, -60), Pair(28, 19), Pair(13, -10), Pair(-27, -53), Pair(-32, -42), Pair(-87, -24), Pair(-1, -50),
        Pair(78, 17), Pair(103, -1), Pair(-127, -56), Pair(-87, 31), Pair(-33, -48), Pair(-93, -43), Pair(-20, -61), Pair(25, -68)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, 42), Pair(-93, 39), Pair(124, -7), Pair(33, -4), Pair(-101, 44), Pair(-3, 63), Pair(62, -11), Pair(-149, 40),
        Pair(35, 20), Pair(-83, 28), Pair(23, 6), Pair(-16, -50), Pair(0, 27), Pair(44, 42), Pair(30, 35), Pair(-10, 12),
        Pair(26, 8), Pair(2, 12), Pair(10, 25), Pair(-30, 8), Pair(7, 27), Pair(41, 25), Pair(42, 4), Pair(50, 4),
        Pair(-16, 23), Pair(-13, 25), Pair(-16, 11), Pair(1, 8), Pair(-23, 16), Pair(-3, 4), Pair(12, 19), Pair(-17, 10),
        Pair(-6, 15), Pair(-1, 6), Pair(4, 11), Pair(-56, 26), Pair(-20, 15), Pair(10, -4), Pair(-4, 5), Pair(-10, 3),
        Pair(-13, 12), Pair(-17, 13), Pair(3, -18), Pair(20, 34), Pair(57, -27), Pair(-13, 6), Pair(-11, 20), Pair(-11, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-76, -70), Pair(25, -44), Pair(9, 28), Pair(-32, -122), Pair(7, -7), Pair(67, 107), Pair(-22, -114), Pair(0, 0),
        Pair(29, 134), Pair(75, 77), Pair(-62, 98), Pair(0, 0), Pair(151, 136), Pair(-23, 161), Pair(13, 132), Pair(-85, 8),
        Pair(-50, -26), Pair(-18, 63), Pair(78, 26), Pair(145, 56), Pair(128, 28), Pair(141, -17), Pair(75, 23), Pair(100, 17),
        Pair(-77, 97), Pair(62, -3), Pair(34, 55), Pair(199, -23), Pair(37, 59), Pair(-23, 17), Pair(10, 8), Pair(10, 24),
        Pair(63, 20), Pair(18, 62), Pair(-24, 72), Pair(87, 61), Pair(32, 23), Pair(116, -89), Pair(76, -1), Pair(53, -40),
        Pair(-138, 83), Pair(62, 17), Pair(32, -13), Pair(31, 52), Pair(-58, 94), Pair(36, -7), Pair(115, -41), Pair(-35, 122),
        Pair(-73, -135), Pair(-2, -120), Pair(37, 112), Pair(89, 3), Pair(-8, 126), Pair(92, 41), Pair(41, 64), Pair(16, 136),
        Pair(-22, -20), Pair(-20, -11), Pair(143, 119), Pair(-54, 79), Pair(-8, -71), Pair(55, 54), Pair(78, -72), Pair(7, -51)
      },
      { // Piece 2
        Pair(68, -68), Pair(-52, -27), Pair(7, -2), Pair(-213, -162), Pair(17, -33), Pair(-54, 27), Pair(0, -149), Pair(-67, -143),
        Pair(-18, 151), Pair(103, 58), Pair(9, 161), Pair(0, 0), Pair(75, -74), Pair(119, -119), Pair(47, -20), Pair(-10, 0),
        Pair(-31, -47), Pair(93, 112), Pair(41, 1), Pair(189, -26), Pair(175, -23), Pair(75, 36), Pair(20, -107), Pair(254, 43),
        Pair(123, 64), Pair(63, -31), Pair(-59, 95), Pair(-2, -1), Pair(-16, 51), Pair(136, -8), Pair(46, 93), Pair(44, -54),
        Pair(93, -34), Pair(112, 17), Pair(11, -6), Pair(13, 101), Pair(107, -46), Pair(6, 54), Pair(35, 22), Pair(51, 105),
        Pair(106, -35), Pair(-97, -63), Pair(27, 13), Pair(107, -55), Pair(70, -51), Pair(31, -26), Pair(69, -9), Pair(97, -6),
        Pair(-151, -41), Pair(81, -91), Pair(32, -82), Pair(-78, 137), Pair(-62, -15), Pair(-35, 41), Pair(40, 1), Pair(6, -8),
        Pair(79, -33), Pair(-73, -96), Pair(62, -15), Pair(155, -39), Pair(-13, 95), Pair(181, -48), Pair(-45, -201), Pair(101, -119)
      },
      { // Piece 3
        Pair(22, 48), Pair(-17, 91), Pair(67, 62), Pair(-56, -108), Pair(65, 72), Pair(-17, 228), Pair(49, 51), Pair(85, 70),
        Pair(34, 11), Pair(74, 7), Pair(2, 32), Pair(0, 0), Pair(66, 0), Pair(20, 22), Pair(-98, 68), Pair(47, -19),
        Pair(54, 30), Pair(-41, 84), Pair(-22, 19), Pair(-39, 44), Pair(-5, 70), Pair(-10, -11), Pair(57, 26), Pair(-17, 19),
        Pair(-7, 50), Pair(204, -45), Pair(115, -58), Pair(36, 42), Pair(-121, 100), Pair(40, 66), Pair(48, -17), Pair(145, 39),
        Pair(76, -19), Pair(-61, 62), Pair(60, -19), Pair(-14, 39), Pair(-49, 40), Pair(18, 48), Pair(19, 11), Pair(7, 38),
        Pair(17, -32), Pair(-192, 124), Pair(-28, 119), Pair(-57, 39), Pair(10, 59), Pair(14, 40), Pair(-82, 44), Pair(-231, 107),
        Pair(23, 3), Pair(-12, 34), Pair(-112, 91), Pair(18, -14), Pair(7, 53), Pair(-101, 137), Pair(-139, 120), Pair(-43, 58),
        Pair(-121, 28), Pair(-20, 54), Pair(-8, 38), Pair(17, 17), Pair(19, 62), Pair(-76, 61), Pair(-55, 60), Pair(-66, 40)
      },
      { // Piece 4
        Pair(9, 91), Pair(-76, -42), Pair(-62, 55), Pair(-79, -100), Pair(-40, -52), Pair(3, 2), Pair(-34, -29), Pair(-60, -58),
        Pair(15, 90), Pair(1, 48), Pair(-49, 112), Pair(0, 0), Pair(112, -71), Pair(-12, 17), Pair(-16, -63), Pair(17, -117),
        Pair(21, -8), Pair(-33, 23), Pair(107, -91), Pair(48, -85), Pair(0, -1), Pair(123, 5), Pair(72, 83), Pair(-98, -96),
        Pair(39, -68), Pair(52, 32), Pair(75, -11), Pair(53, -4), Pair(-37, 45), Pair(105, -1), Pair(40, 137), Pair(10, 69),
        Pair(-129, 41), Pair(-91, 52), Pair(4, -5), Pair(63, 9), Pair(17, 137), Pair(-148, 160), Pair(31, -71), Pair(80, 40),
        Pair(-85, 19), Pair(-48, 88), Pair(-44, -67), Pair(-96, 104), Pair(-47, 18), Pair(-68, 4), Pair(-50, -23), Pair(-65, -73),
        Pair(104, -54), Pair(-110, 49), Pair(-6, -7), Pair(-73, 92), Pair(-40, 100), Pair(-66, 89), Pair(-42, -95), Pair(36, -9),
        Pair(28, -35), Pair(115, -73), Pair(-121, -37), Pair(106, -128), Pair(-38, -83), Pair(-78, -106), Pair(-43, -97), Pair(1, -28)
      },
      { // Piece 5
        Pair(22, 130), Pair(44, 189), Pair(-23, -1), Pair(104, 3), Pair(-10, 31), Pair(-2, 57), Pair(-6, -33), Pair(7, 100),
        Pair(-1, 14), Pair(-18, 28), Pair(191, 88), Pair(0, 0), Pair(-13, 110), Pair(3, 41), Pair(-27, -154), Pair(16, 65),
        Pair(-37, 33), Pair(16, 64), Pair(95, 53), Pair(47, 46), Pair(65, 55), Pair(18, 16), Pair(8, -12), Pair(-11, 4),
        Pair(58, -32), Pair(107, -17), Pair(115, -7), Pair(91, -6), Pair(181, -23), Pair(-25, -22), Pair(59, -6), Pair(41, -61),
        Pair(-61, 32), Pair(-44, 18), Pair(-9, 24), Pair(10, 7), Pair(235, -66), Pair(112, -50), Pair(-124, 8), Pair(-108, -17),
        Pair(45, -47), Pair(45, -39), Pair(64, -63), Pair(50, -22), Pair(-65, -18), Pair(-67, -16), Pair(-104, 4), Pair(-18, -38),
        Pair(151, 9), Pair(-18, 7), Pair(-181, 1), Pair(-194, 43), Pair(-146, 17), Pair(-49, -40), Pair(-66, -20), Pair(-69, -9),
        Pair(135, -92), Pair(26, -77), Pair(-49, 21), Pair(-63, -22), Pair(-107, 53), Pair(-15, -54), Pair(-14, -54), Pair(2, -44)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(89, 85), Pair(-54, 15), Pair(-47, 46), Pair(-101, 44), Pair(-7, 18), Pair(57, 105), Pair(-57, 27), Pair(102, 35),
        Pair(-151, 44), Pair(-57, 21), Pair(-132, 67), Pair(79, -16), Pair(146, -62), Pair(54, -11), Pair(36, 31), Pair(-10, -5),
        Pair(25, 10), Pair(6, 19), Pair(86, 4), Pair(-9, 56), Pair(29, 0), Pair(-60, 44), Pair(8, 19), Pair(36, -19),
        Pair(10, -5), Pair(34, -7), Pair(18, -1), Pair(-12, 21), Pair(-88, 23), Pair(14, -10), Pair(-17, 8), Pair(-22, 9),
        Pair(5, -2), Pair(-38, 25), Pair(4, 7), Pair(14, -5), Pair(7, -20), Pair(14, 17), Pair(17, 7), Pair(10, -6),
        Pair(-3, 13), Pair(9, -11), Pair(40, -22), Pair(-118, 95), Pair(-61, 5), Pair(-9, 19), Pair(12, -8), Pair(-12, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(28, 0), Pair(-55, 104), Pair(48, 16), Pair(142, 82), Pair(-4, 74), Pair(143, 78), Pair(9, 18), Pair(2, 8),
        Pair(-193, -57), Pair(-98, 233), Pair(124, -87), Pair(52, 11), Pair(0, 0), Pair(-39, 62), Pair(62, 96), Pair(36, 33),
        Pair(114, 186), Pair(38, 80), Pair(20, -12), Pair(-54, 21), Pair(34, 80), Pair(71, 88), Pair(33, 0), Pair(-7, -59),
        Pair(-103, -14), Pair(236, -51), Pair(-110, 107), Pair(26, 18), Pair(215, -40), Pair(-17, 73), Pair(-7, -9), Pair(202, 16),
        Pair(-71, -94), Pair(-55, -73), Pair(49, -20), Pair(43, 12), Pair(-88, 92), Pair(18, 58), Pair(-45, 80), Pair(50, 18),
        Pair(-10, 42), Pair(-79, 29), Pair(-51, 68), Pair(51, 25), Pair(246, -42), Pair(-47, 38), Pair(121, -24), Pair(170, -91),
        Pair(-4, 9), Pair(-133, -74), Pair(193, 41), Pair(-47, -21), Pair(94, 7), Pair(-31, -32), Pair(145, 37), Pair(-36, -77),
        Pair(-42, 7), Pair(26, -66), Pair(-3, 125), Pair(164, -66), Pair(-139, 15), Pair(-46, -46), Pair(98, 78), Pair(-6, -18)
      },
      { // Piece 2
        Pair(50, -15), Pair(-83, -89), Pair(-20, 5), Pair(139, -47), Pair(10, -59), Pair(56, -95), Pair(14, -28), Pair(5, -17),
        Pair(76, 106), Pair(-14, 48), Pair(-18, 9), Pair(149, 93), Pair(0, 0), Pair(-66, 13), Pair(-54, -6), Pair(56, -44),
        Pair(-127, 68), Pair(-18, -45), Pair(-3, 74), Pair(155, -48), Pair(-39, -8), Pair(-5, 38), Pair(52, 14), Pair(2, -70),
        Pair(29, -44), Pair(-68, 91), Pair(27, -22), Pair(-173, 109), Pair(70, -39), Pair(14, -13), Pair(61, -5), Pair(-7, 21),
        Pair(32, 128), Pair(104, -30), Pair(86, 64), Pair(-38, 5), Pair(107, -4), Pair(88, -18), Pair(73, -34), Pair(-23, 9),
        Pair(12, -54), Pair(-5, -29), Pair(-58, -6), Pair(114, -33), Pair(84, -69), Pair(127, -7), Pair(-11, -86), Pair(-67, 58),
        Pair(-109, 104), Pair(-42, 0), Pair(106, -172), Pair(-29, -7), Pair(61, -8), Pair(-11, 30), Pair(6, 81), Pair(-186, -52),
        Pair(180, -109), Pair(106, -50), Pair(158, -71), Pair(-108, 17), Pair(27, 113), Pair(2, 50), Pair(117, -171), Pair(-128, -27)
      },
      { // Piece 3
        Pair(-91, 90), Pair(79, 66), Pair(27, 12), Pair(28, 55), Pair(-85, -101), Pair(112, 73), Pair(70, 11), Pair(29, 49),
        Pair(6, 12), Pair(-133, 29), Pair(-57, 4), Pair(17, -28), Pair(0, 0), Pair(151, -36), Pair(113, 9), Pair(55, -35),
        Pair(19, -42), Pair(-32, 71), Pair(13, 16), Pair(110, -46), Pair(-1, 4), Pair(-37, 2), Pair(-19, 77), Pair(-88, -17),
        Pair(0, 12), Pair(57, -66), Pair(-13, 45), Pair(93, -10), Pair(133, -52), Pair(35, 17), Pair(-37, 47), Pair(16, 58),
        Pair(183, 18), Pair(-32, 13), Pair(-7, -62), Pair(-7, -68), Pair(-16, 5), Pair(75, -62), Pair(-116, 4), Pair(-185, 58),
        Pair(50, -105), Pair(58, -14), Pair(68, 118), Pair(93, -44), Pair(1, 8), Pair(-80, 36), Pair(33, 71), Pair(-19, 19),
        Pair(91, -2), Pair(1, -23), Pair(-62, 37), Pair(91, -59), Pair(-7, 9), Pair(11, 72), Pair(-21, -12), Pair(-17, 25),
        Pair(-79, 12), Pair(9, 8), Pair(102, -64), Pair(16, -60), Pair(-39, 6), Pair(26, 11), Pair(-29, -21), Pair(72, -57)
      },
      { // Piece 4
        Pair(-18, -46), Pair(41, 31), Pair(63, 107), Pair(-15, -51), Pair(-218, -199), Pair(-47, -117), Pair(-65, -89), Pair(-20, -23),
        Pair(-15, 3), Pair(-68, 71), Pair(121, -33), Pair(70, -110), Pair(0, 0), Pair(95, -143), Pair(-52, -47), Pair(-46, 31),
        Pair(-107, 4), Pair(73, 18), Pair(-25, 60), Pair(-34, -4), Pair(10, 46), Pair(-17, -36), Pair(125, 47), Pair(70, 24),
        Pair(-87, -113), Pair(20, 65), Pair(42, -49), Pair(16, 5), Pair(-14, 43), Pair(19, -21), Pair(-57, 15), Pair(-58, 21),
        Pair(-166, 48), Pair(30, -32), Pair(36, 15), Pair(155, -87), Pair(124, -154), Pair(-46, 9), Pair(118, -98), Pair(64, -120),
        Pair(-91, -110), Pair(-172, 12), Pair(26, 74), Pair(69, -101), Pair(-11, 122), Pair(-8, 27), Pair(43, -98), Pair(-46, -34),
        Pair(-161, -80), Pair(80, -64), Pair(-2, -78), Pair(59, 0), Pair(-46, 26), Pair(-89, 83), Pair(-12, -20), Pair(61, 17),
        Pair(-154, -35), Pair(65, -147), Pair(-42, -136), Pair(-111, 67), Pair(-90, -101), Pair(-99, -39), Pair(-40, -67), Pair(4, 4)
      },
      { // Piece 5
        Pair(-2, -19), Pair(-24, -124), Pair(-22, 50), Pair(-9, 100), Pair(-7, -66), Pair(9, -29), Pair(63, 87), Pair(12, 80),
        Pair(-54, -19), Pair(31, 3), Pair(19, 131), Pair(-5, 123), Pair(0, 0), Pair(41, 94), Pair(86, 111), Pair(39, 82),
        Pair(16, 53), Pair(88, -19), Pair(29, 46), Pair(5, 3), Pair(18, 53), Pair(35, 41), Pair(95, 15), Pair(30, -32),
        Pair(-70, -73), Pair(-21, 28), Pair(153, 9), Pair(-27, 43), Pair(-22, 24), Pair(121, -6), Pair(115, -29), Pair(-72, -42),
        Pair(-61, -84), Pair(50, -40), Pair(10, 15), Pair(114, 10), Pair(-122, 55), Pair(14, -29), Pair(-22, -13), Pair(28, -20),
        Pair(-79, -45), Pair(-62, -9), Pair(114, -75), Pair(-125, 25), Pair(-114, 5), Pair(-56, -5), Pair(-22, 1), Pair(-43, -16),
        Pair(-184, 46), Pair(34, -31), Pair(32, -8), Pair(31, -52), Pair(-286, 28), Pair(-5, -54), Pair(16, -74), Pair(115, -58),
        Pair(-91, 43), Pair(-29, -41), Pair(-52, -70), Pair(-11, 11), Pair(-20, -67), Pair(-48, -51), Pair(17, -74), Pair(56, -66)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-100, 33), Pair(-4, -13), Pair(36, 72), Pair(-3, 63), Pair(57, 105), Pair(-16, 8), Pair(40, 11), Pair(57, 24),
        Pair(100, -13), Pair(-23, 45), Pair(-45, 61), Pair(-43, 52), Pair(-109, 31), Pair(18, -46), Pair(14, -21), Pair(26, -6),
        Pair(7, 31), Pair(-14, 17), Pair(-74, 45), Pair(6, -8), Pair(-20, 19), Pair(-4, 6), Pair(7, 19), Pair(42, -11),
        Pair(3, 1), Pair(33, 20), Pair(0, 11), Pair(-45, 26), Pair(-28, -15), Pair(-50, 4), Pair(-29, 10), Pair(-19, 12),
        Pair(-43, 13), Pair(8, -7), Pair(-42, 4), Pair(5, -8), Pair(-32, -8), Pair(64, -24), Pair(-24, 14), Pair(-5, -1),
        Pair(-25, 6), Pair(18, 3), Pair(-47, 20), Pair(-5, -22), Pair(-84, 51), Pair(-41, 24), Pair(5, -1), Pair(23, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 38), Pair(-3, -24), Pair(-29, -7), Pair(80, -79), Pair(67, 139), Pair(65, 3), Pair(89, 125), Pair(-3, -33),
        Pair(-2, 33), Pair(13, 29), Pair(-38, -67), Pair(-85, 36), Pair(-170, -88), Pair(0, 0), Pair(12, -47), Pair(-2, 24),
        Pair(36, 114), Pair(-65, -34), Pair(-98, 38), Pair(94, -62), Pair(149, -38), Pair(32, -13), Pair(134, 165), Pair(38, -11),
        Pair(-31, -65), Pair(-209, 23), Pair(-131, 53), Pair(74, 6), Pair(211, 9), Pair(41, -26), Pair(76, 3), Pair(149, -54),
        Pair(34, -74), Pair(-99, -49), Pair(88, -104), Pair(-134, 53), Pair(-8, 30), Pair(140, 21), Pair(-119, -1), Pair(91, -52),
        Pair(16, -101), Pair(24, -21), Pair(91, -118), Pair(-59, -17), Pair(-46, -3), Pair(-31, 124), Pair(136, -69), Pair(-20, -3),
        Pair(-29, 65), Pair(-6, -23), Pair(116, -197), Pair(-49, -48), Pair(46, -88), Pair(-173, 27), Pair(148, -99), Pair(54, -55),
        Pair(-4, -40), Pair(-92, 64), Pair(-134, 128), Pair(37, -86), Pair(-204, -60), Pair(-132, 36), Pair(-45, 51), Pair(42, 7)
      },
      { // Piece 2
        Pair(-52, -97), Pair(-30, 101), Pair(-42, 35), Pair(30, 103), Pair(56, -2), Pair(-33, 132), Pair(70, 16), Pair(8, 28),
        Pair(-46, -42), Pair(132, -26), Pair(76, 116), Pair(61, -106), Pair(-127, 65), Pair(0, 0), Pair(70, -13), Pair(46, -72),
        Pair(-181, -89), Pair(-94, -25), Pair(72, -108), Pair(113, 58), Pair(52, -43), Pair(105, -25), Pair(-6, -11), Pair(109, 0),
        Pair(-43, 44), Pair(-41, -22), Pair(-53, -40), Pair(142, -45), Pair(119, -44), Pair(24, -68), Pair(-68, 24), Pair(6, -48),
        Pair(-3, -100), Pair(-47, 54), Pair(16, -26), Pair(206, 83), Pair(-17, -52), Pair(210, 59), Pair(87, -148), Pair(-21, 14),
        Pair(71, 79), Pair(62, -46), Pair(74, -27), Pair(-90, -71), Pair(99, 53), Pair(5, -29), Pair(32, 13), Pair(31, 23),
        Pair(-275, -21), Pair(6, 23), Pair(-31, -91), Pair(9, 1), Pair(-60, 35), Pair(-71, 107), Pair(113, -129), Pair(55, -86),
        Pair(44, -4), Pair(-95, -27), Pair(81, 32), Pair(-186, -6), Pair(94, -50), Pair(-40, -131), Pair(107, 56), Pair(91, -128)
      },
      { // Piece 3
        Pair(58, 65), Pair(-10, 50), Pair(152, 114), Pair(120, 53), Pair(60, 88), Pair(-13, -86), Pair(-80, 46), Pair(99, 23),
        Pair(39, 4), Pair(-26, 14), Pair(62, 1), Pair(96, 26), Pair(75, -5), Pair(0, 0), Pair(38, -1), Pair(-91, 23),
        Pair(-131, 76), Pair(40, 20), Pair(84, 5), Pair(-81, -84), Pair(-74, 44), Pair(142, -71), Pair(37, -1), Pair(-5, 62),
        Pair(163, -5), Pair(107, -29), Pair(-13, -65), Pair(105, 4), Pair(15, 20), Pair(123, -20), Pair(4, -45), Pair(37, 21),
        Pair(139, 41), Pair(40, -74), Pair(-91, 18), Pair(133, 151), Pair(96, 14), Pair(77, 35), Pair(-59, -22), Pair(-88, 24),
        Pair(45, -32), Pair(-100, 65), Pair(-6, -123), Pair(-153, 64), Pair(-129, 21), Pair(-111, 67), Pair(-70, 16), Pair(83, -35),
        Pair(-10, -59), Pair(-91, 146), Pair(-8, 0), Pair(-234, 43), Pair(55, 90), Pair(-18, 68), Pair(106, -35), Pair(116, -69),
        Pair(-36, 20), Pair(50, -1), Pair(-113, 82), Pair(9, -22), Pair(2, -24), Pair(28, 10), Pair(-16, 17), Pair(-52, 54)
      },
      { // Piece 4
        Pair(-22, -10), Pair(5, 9), Pair(-96, -136), Pair(55, 98), Pair(72, -12), Pair(-146, -220), Pair(-62, -47), Pair(-104, -82),
        Pair(62, -41), Pair(40, 57), Pair(-79, -2), Pair(96, 198), Pair(104, -127), Pair(0, 0), Pair(37, 25), Pair(88, 151),
        Pair(30, -45), Pair(1, -345), Pair(145, 92), Pair(0, -33), Pair(-62, 34), Pair(-20, -108), Pair(-103, 65), Pair(-84, -89),
        Pair(-86, -157), Pair(-28, -29), Pair(23, -12), Pair(30, -40), Pair(179, 126), Pair(35, -89), Pair(-26, -159), Pair(63, 160),
        Pair(-108, -78), Pair(-51, -33), Pair(41, -35), Pair(77, 89), Pair(-69, -205), Pair(155, 106), Pair(-56, 66), Pair(106, 62),
        Pair(-121, -102), Pair(-113, -53), Pair(-60, -50), Pair(79, 30), Pair(-43, -50), Pair(26, -16), Pair(27, 22), Pair(-78, 43),
        Pair(-87, -146), Pair(-65, -2), Pair(-23, -103), Pair(128, -98), Pair(-50, -22), Pair(35, 39), Pair(-239, 78), Pair(-68, -9),
        Pair(205, 56), Pair(-92, -34), Pair(-140, 4), Pair(-11, -95), Pair(-47, -48), Pair(-44, -10), Pair(-56, -73), Pair(-109, -67)
      },
      { // Piece 5
        Pair(-2, -42), Pair(0, 0), Pair(-29, -116), Pair(51, 44), Pair(46, 33), Pair(3, -24), Pair(28, 60), Pair(-12, 62),
        Pair(19, 105), Pair(-12, 35), Pair(13, 34), Pair(53, 15), Pair(5, 41), Pair(0, 0), Pair(30, 51), Pair(-33, 58),
        Pair(7, 23), Pair(38, 0), Pair(-29, 63), Pair(-69, 17), Pair(-7, 69), Pair(27, 55), Pair(92, 60), Pair(12, 42),
        Pair(1, 92), Pair(-69, -29), Pair(18, 59), Pair(75, -49), Pair(23, 24), Pair(149, -7), Pair(27, 49), Pair(-20, 70),
        Pair(-51, -26), Pair(-65, -89), Pair(-61, -37), Pair(57, -23), Pair(-24, 8), Pair(-3, 23), Pair(130, -6), Pair(18, -16),
        Pair(-56, -13), Pair(-11, -25), Pair(89, -45), Pair(249, -43), Pair(2, -13), Pair(84, -17), Pair(-105, 2), Pair(52, -53),
        Pair(4, -50), Pair(-208, 23), Pair(88, -34), Pair(-123, 35), Pair(-122, -58), Pair(22, 11), Pair(45, -74), Pair(15, -9),
        Pair(-147, 24), Pair(62, -83), Pair(-21, -24), Pair(-26, -47), Pair(-79, -54), Pair(-174, 65), Pair(-18, -55), Pair(-44, 89)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-38, 31), Pair(-1, 18), Pair(-4, -24), Pair(62, -11), Pair(-57, 27), Pair(40, 11), Pair(-20, 25), Pair(-24, -124),
        Pair(-7, 23), Pair(28, 94), Pair(-49, 7), Pair(108, -7), Pair(-54, 46), Pair(-4, -8), Pair(196, -150), Pair(61, -34),
        Pair(26, 21), Pair(-69, 29), Pair(31, 17), Pair(31, -1), Pair(32, -26), Pair(-8, 38), Pair(8, -5), Pair(6, 27),
        Pair(9, 17), Pair(15, 13), Pair(32, -7), Pair(39, -11), Pair(25, 19), Pair(-21, 20), Pair(25, -17), Pair(8, 10),
        Pair(36, -6), Pair(25, 18), Pair(26, 8), Pair(63, -31), Pair(-5, 19), Pair(-18, 1), Pair(3, -13), Pair(0, 0),
        Pair(12, 11), Pair(25, 6), Pair(-5, 18), Pair(65, -13), Pair(-53, 31), Pair(-14, 11), Pair(-10, 16), Pair(-11, 24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-31, 5), Pair(5, 6), Pair(-52, -157), Pair(-44, 7), Pair(70, -44), Pair(-156, -20), Pair(-7, -30), Pair(7, 18),
        Pair(-71, -48), Pair(-104, -62), Pair(-17, -43), Pair(115, 45), Pair(123, 186), Pair(224, -15), Pair(0, 0), Pair(278, 24),
        Pair(8, -27), Pair(-6, 27), Pair(0, 47), Pair(30, -31), Pair(88, -86), Pair(89, -3), Pair(133, -48), Pair(73, 142),
        Pair(19, -95), Pair(124, 72), Pair(-33, 27), Pair(76, 59), Pair(74, 7), Pair(69, 57), Pair(4, 9), Pair(-31, 67),
        Pair(-8, 141), Pair(189, 89), Pair(165, -96), Pair(16, -32), Pair(-64, -13), Pair(-66, -66), Pair(-34, 54), Pair(150, -56),
        Pair(-121, -38), Pair(-26, 76), Pair(126, -162), Pair(-98, -75), Pair(63, 25), Pair(-36, 95), Pair(-9, -48), Pair(143, -163),
        Pair(175, -20), Pair(72, -127), Pair(-71, 78), Pair(-4, -45), Pair(-85, 142), Pair(-2, -96), Pair(113, -50), Pair(-12, 46),
        Pair(-88, -62), Pair(-102, -103), Pair(-184, 106), Pair(-119, 8), Pair(152, -13), Pair(-270, -53), Pair(-176, -54), Pair(6, 32)
      },
      { // Piece 2
        Pair(-37, 12), Pair(30, 57), Pair(-33, 17), Pair(18, -109), Pair(5, -73), Pair(-66, -38), Pair(-127, -98), Pair(-57, -133),
        Pair(-23, 56), Pair(23, 5), Pair(49, -95), Pair(92, -48), Pair(143, -78), Pair(-4, 152), Pair(0, 0), Pair(-29, -3),
        Pair(75, 1), Pair(150, -118), Pair(-34, 13), Pair(4, -124), Pair(111, 136), Pair(42, -10), Pair(9, 94), Pair(-20, -14),
        Pair(-127, -46), Pair(62, 94), Pair(1, -50), Pair(154, -32), Pair(177, -72), Pair(70, 49), Pair(-48, -127), Pair(13, 62),
        Pair(-70, 94), Pair(77, -142), Pair(50, 9), Pair(70, 19), Pair(-107, 24), Pair(-75, -127), Pair(178, -113), Pair(41, -193),
        Pair(1, -38), Pair(120, -46), Pair(46, -1), Pair(84, -74), Pair(143, -88), Pair(9, -37), Pair(-10, -28), Pair(81, -95),
        Pair(99, -50), Pair(51, -4), Pair(-76, 17), Pair(23, -77), Pair(53, -20), Pair(-114, -27), Pair(-58, -11), Pair(-110, 127),
        Pair(102, -45), Pair(-3, -16), Pair(40, -78), Pair(-56, 20), Pair(-1, 11), Pair(-52, 32), Pair(1, -66), Pair(1, 10)
      },
      { // Piece 3
        Pair(-71, 50), Pair(87, -15), Pair(48, -66), Pair(31, 15), Pair(4, -14), Pair(109, 37), Pair(-87, -137), Pair(138, -55),
        Pair(197, -35), Pair(103, -61), Pair(3, -44), Pair(106, -64), Pair(-46, -9), Pair(-36, -40), Pair(0, 0), Pair(-106, 61),
        Pair(32, 8), Pair(36, -52), Pair(64, -63), Pair(60, -18), Pair(75, -105), Pair(-30, 14), Pair(43, 48), Pair(165, 7),
        Pair(-240, 69), Pair(121, -16), Pair(-28, 105), Pair(-109, -4), Pair(-65, -53), Pair(7, -40), Pair(10, -67), Pair(-69, 70),
        Pair(-137, 83), Pair(54, -85), Pair(39, -86), Pair(-71, -10), Pair(75, 70), Pair(108, 7), Pair(277, 2), Pair(-142, 190),
        Pair(-309, 26), Pair(-88, -37), Pair(-215, 164), Pair(-3, 113), Pair(-5, -15), Pair(63, -72), Pair(117, -3), Pair(-206, 100),
        Pair(-90, -43), Pair(-96, -108), Pair(84, -47), Pair(59, -11), Pair(135, -56), Pair(-130, 43), Pair(72, -68), Pair(-31, -57),
        Pair(-66, -28), Pair(18, 64), Pair(-77, -28), Pair(22, -83), Pair(-9, -20), Pair(-58, -16), Pair(57, 4), Pair(-25, 10)
      },
      { // Piece 4
        Pair(134, 43), Pair(-224, -214), Pair(-7, 13), Pair(-50, -43), Pair(-67, -74), Pair(141, -2), Pair(-2, -19), Pair(157, -127),
        Pair(-81, -128), Pair(-9, -72), Pair(-107, -99), Pair(24, 31), Pair(-36, -247), Pair(23, -72), Pair(0, 0), Pair(-111, -145),
        Pair(116, 34), Pair(-168, -171), Pair(70, 24), Pair(68, 149), Pair(3, -51), Pair(84, -167), Pair(-98, 19), Pair(9, 91),
        Pair(209, 58), Pair(-66, -11), Pair(74, -14), Pair(4, -11), Pair(-27, -75), Pair(69, 79), Pair(23, 74), Pair(102, 105),
        Pair(17, -16), Pair(-148, -72), Pair(-44, -37), Pair(-45, 29), Pair(39, 58), Pair(-114, 91), Pair(-141, 64), Pair(-51, -138),
        Pair(-57, -144), Pair(-147, -72), Pair(38, -71), Pair(61, -33), Pair(-199, 145), Pair(-92, 79), Pair(136, 41), Pair(285, 212),
        Pair(127, 65), Pair(-49, -49), Pair(2, 95), Pair(-142, 99), Pair(-67, -135), Pair(-7, -27), Pair(-118, -95), Pair(141, 29),
        Pair(-79, -164), Pair(33, -5), Pair(-91, -13), Pair(-53, 60), Pair(41, -67), Pair(-37, -22), Pair(-276, -11), Pair(232, 110)
      },
      { // Piece 5
        Pair(2, -13), Pair(-14, -139), Pair(15, 57), Pair(29, 112), Pair(-23, 68), Pair(-23, 96), Pair(-30, 26), Pair(15, 27),
        Pair(-2, 29), Pair(7, 54), Pair(-36, -107), Pair(-7, -101), Pair(4, 4), Pair(-125, 66), Pair(0, 0), Pair(-112, 150),
        Pair(-108, -86), Pair(-7, 5), Pair(-35, 24), Pair(-48, -103), Pair(27, 116), Pair(17, 39), Pair(121, 29), Pair(-54, 99),
        Pair(-24, -38), Pair(17, -69), Pair(-16, -75), Pair(95, -27), Pair(17, 54), Pair(43, 66), Pair(75, 56), Pair(117, 21),
        Pair(38, 0), Pair(49, -49), Pair(-46, 31), Pair(-10, -10), Pair(36, -20), Pair(93, 13), Pair(13, 20), Pair(-116, -24),
        Pair(-98, -61), Pair(-3, 32), Pair(79, -32), Pair(13, -2), Pair(125, -4), Pair(7, 32), Pair(24, 39), Pair(-30, 33),
        Pair(28, -17), Pair(21, -37), Pair(31, 32), Pair(-62, -32), Pair(-96, 4), Pair(-44, -14), Pair(-10, 32), Pair(76, 25),
        Pair(12, -207), Pair(-109, 50), Pair(-35, -6), Pair(-93, -2), Pair(32, -7), Pair(22, 28), Pair(9, -16), Pair(74, 6)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(69, 47), Pair(37, 23), Pair(-8, 3), Pair(-149, 40), Pair(102, 35), Pair(57, 24), Pair(-24, -124), Pair(-51, -6),
        Pair(-130, 63), Pair(-29, 32), Pair(-96, 37), Pair(56, 16), Pair(34, -3), Pair(-29, 17), Pair(15, -38), Pair(41, -80),
        Pair(53, 8), Pair(-30, 16), Pair(46, -3), Pair(-72, 44), Pair(8, 8), Pair(14, 9), Pair(-24, 33), Pair(11, 18),
        Pair(-2, 8), Pair(-6, 4), Pair(-7, 9), Pair(7, 1), Pair(-12, 12), Pair(2, 15), Pair(-31, 8), Pair(43, -21),
        Pair(7, 15), Pair(-1, 3), Pair(29, 8), Pair(11, -8), Pair(11, 3), Pair(14, -1), Pair(6, 2), Pair(12, 10),
        Pair(-7, 31), Pair(-7, 20), Pair(6, 11), Pair(-30, 25), Pair(0, 12), Pair(-21, 14), Pair(-26, 21), Pair(46, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(9, 88), Pair(0, -3), Pair(-22, -76), Pair(-2, -40), Pair(23, 71), Pair(15, 47), Pair(-28, 20), Pair(69, 104),
        Pair(90, 91), Pair(64, 101), Pair(-6, -145), Pair(27, 31), Pair(91, 41), Pair(83, 24), Pair(-42, 51), Pair(0, 0),
        Pair(-139, -36), Pair(83, 53), Pair(5, 12), Pair(113, -82), Pair(171, 104), Pair(60, 8), Pair(-11, -53), Pair(-41, -89),
        Pair(-81, -17), Pair(-23, 52), Pair(79, -41), Pair(-18, 32), Pair(1, 25), Pair(37, -8), Pair(178, -35), Pair(210, 18),
        Pair(81, 103), Pair(-80, 31), Pair(-26, -18), Pair(5, 15), Pair(174, -88), Pair(120, -5), Pair(-24, 39), Pair(200, -72),
        Pair(-2, -62), Pair(58, -66), Pair(4, -27), Pair(91, 0), Pair(-2, 7), Pair(-32, 3), Pair(93, -84), Pair(15, 170),
        Pair(27, 32), Pair(-42, -33), Pair(20, -86), Pair(30, 40), Pair(29, 76), Pair(37, -40), Pair(-6, -55), Pair(-75, 19),
        Pair(-66, -45), Pair(-131, 7), Pair(7, -11), Pair(-30, -10), Pair(-291, -76), Pair(-64, 15), Pair(18, -49), Pair(-80, -54)
      },
      { // Piece 2
        Pair(29, -91), Pair(1, 14), Pair(69, 33), Pair(-1, -57), Pair(32, -10), Pair(66, 110), Pair(118, -1), Pair(-3, -105),
        Pair(-98, 23), Pair(64, -99), Pair(-23, -46), Pair(-90, -112), Pair(155, 42), Pair(187, -5), Pair(38, 38), Pair(0, 0),
        Pair(73, -91), Pair(64, 38), Pair(-102, 5), Pair(-9, -22), Pair(125, -30), Pair(-21, 54), Pair(153, -10), Pair(150, 35),
        Pair(35, -40), Pair(173, -42), Pair(-9, 10), Pair(85, -71), Pair(153, -69), Pair(10, -15), Pair(25, 34), Pair(-20, 82),
        Pair(82, -103), Pair(-139, -52), Pair(3, -27), Pair(59, 44), Pair(172, -11), Pair(70, -9), Pair(-136, 52), Pair(50, 21),
        Pair(-69, 90), Pair(42, -11), Pair(226, -5), Pair(41, -27), Pair(-9, 25), Pair(133, -3), Pair(126, 26), Pair(164, -138),
        Pair(-120, 59), Pair(-13, 106), Pair(88, -45), Pair(13, 26), Pair(5, -41), Pair(-16, -76), Pair(-30, -53), Pair(-31, -309),
        Pair(-96, 16), Pair(118, -65), Pair(-50, -53), Pair(134, -50), Pair(-276, 23), Pair(-3, -59), Pair(-22, -138), Pair(41, -50)
      },
      { // Piece 3
        Pair(-7, 91), Pair(-8, 49), Pair(-99, 30), Pair(36, -8), Pair(84, 31), Pair(43, -6), Pair(11, 66), Pair(145, -164),
        Pair(36, -22), Pair(66, 8), Pair(-58, 37), Pair(41, 11), Pair(241, -50), Pair(16, 0), Pair(-10, 6), Pair(0, 0),
        Pair(197, -79), Pair(136, -33), Pair(188, -39), Pair(33, -28), Pair(229, -74), Pair(-48, -6), Pair(27, 16), Pair(-74, 55),
        Pair(-14, 33), Pair(112, -42), Pair(118, -79), Pair(57, -33), Pair(141, -64), Pair(97, -72), Pair(-102, 53), Pair(-160, 74),
        Pair(-119, 30), Pair(-69, 22), Pair(-55, 44), Pair(94, -11), Pair(14, -3), Pair(-26, 28), Pair(104, 29), Pair(-136, 38),
        Pair(55, -12), Pair(-29, 51), Pair(65, 32), Pair(-138, -65), Pair(-47, -90), Pair(-78, -4), Pair(71, 68), Pair(-56, 81),
        Pair(-62, 82), Pair(31, 10), Pair(10, 5), Pair(-50, -48), Pair(33, -20), Pair(-55, -83), Pair(14, 34), Pair(-173, 92),
        Pair(-28, -30), Pair(84, -17), Pair(-22, -20), Pair(-25, -15), Pair(-53, -44), Pair(-23, -58), Pair(-18, 22), Pair(41, -57)
      },
      { // Piece 4
        Pair(-71, -77), Pair(-131, -117), Pair(53, 59), Pair(-59, -100), Pair(121, 119), Pair(12, 4), Pair(-61, 8), Pair(-53, -129),
        Pair(130, 75), Pair(98, -47), Pair(30, -25), Pair(89, -90), Pair(22, -41), Pair(-29, -58), Pair(28, -45), Pair(0, 0),
        Pair(-48, -107), Pair(41, -12), Pair(82, 0), Pair(-30, 2), Pair(96, 39), Pair(-14, -3), Pair(27, 13), Pair(-3, 237),
        Pair(12, 21), Pair(57, -65), Pair(111, 38), Pair(42, 70), Pair(81, -23), Pair(23, 97), Pair(99, -94), Pair(60, -111),
        Pair(108, -135), Pair(-299, -76), Pair(-222, -137), Pair(96, 59), Pair(121, -111), Pair(-7, -3), Pair(-27, 67), Pair(16, -157),
        Pair(-117, -34), Pair(-149, 10), Pair(-64, -83), Pair(25, -146), Pair(-138, 159), Pair(-133, 57), Pair(105, -72), Pair(-127, -203),
        Pair(-10, 25), Pair(-85, -27), Pair(-33, 133), Pair(-106, -27), Pair(-17, -199), Pair(-11, -55), Pair(-71, 123), Pair(-100, -37),
        Pair(6, -41), Pair(47, 107), Pair(-4, -40), Pair(-103, 81), Pair(-109, -53), Pair(-98, 9), Pair(-102, -82), Pair(-9, -1)
      },
      { // Piece 5
        Pair(24, 79), Pair(4, 176), Pair(19, 63), Pair(15, 54), Pair(21, 42), Pair(-29, 90), Pair(25, 48), Pair(4, -279),
        Pair(32, 82), Pair(48, -68), Pair(-94, -62), Pair(-68, -47), Pair(47, -43), Pair(-42, 63), Pair(85, 86), Pair(0, 0),
        Pair(17, 50), Pair(38, -14), Pair(25, -33), Pair(-8, 77), Pair(44, 33), Pair(-32, 90), Pair(66, 21), Pair(6, 39),
        Pair(156, 82), Pair(-60, 37), Pair(70, 0), Pair(94, -12), Pair(-5, 52), Pair(54, 16), Pair(70, 29), Pair(51, -35),
        Pair(-7, -51), Pair(-17, 30), Pair(35, -14), Pair(94, -7), Pair(-50, -2), Pair(-136, 69), Pair(10, 28), Pair(-15, 7),
        Pair(-92, -58), Pair(31, -20), Pair(78, 19), Pair(166, -19), Pair(53, -38), Pair(-59, 6), Pair(-61, 38), Pair(111, -43),
        Pair(-196, -18), Pair(-13, -1), Pair(-56, -21), Pair(113, -38), Pair(-4, 1), Pair(-125, 47), Pair(46, -4), Pair(-20, -15),
        Pair(-51, 42), Pair(31, -34), Pair(-104, -62), Pair(-141, -15), Pair(-5, -61), Pair(-61, 19), Pair(-20, 18), Pair(14, -45)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, -93), Pair(-41, 9), Pair(-30, 36), Pair(35, 20), Pair(-151, 44), Pair(100, -13), Pair(-7, 23), Pair(-130, 63),
        Pair(0, 36), Pair(-6, -13), Pair(-6, 13), Pair(-14, 41), Pair(17, 27), Pair(12, 11), Pair(-27, 2), Pair(9, 2),
        Pair(34, -30), Pair(-9, -2), Pair(-2, 9), Pair(-4, 14), Pair(10, 5), Pair(2, 11), Pair(-7, 13), Pair(-10, 13),
        Pair(-14, 6), Pair(-6, 17), Pair(-2, 14), Pair(-3, 3), Pair(-1, 6), Pair(-4, 7), Pair(0, 10), Pair(-7, 12),
        Pair(-9, 36), Pair(-10, 15), Pair(-4, 8), Pair(-7, 18), Pair(-5, 10), Pair(8, 8), Pair(-4, 14), Pair(-4, 16),
        Pair(-18, 30), Pair(-10, 18), Pair(-7, 6), Pair(7, -4), Pair(-5, 8), Pair(-5, 15), Pair(-2, 14), Pair(-5, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(129, -31), Pair(-198, 10), Pair(68, 43), Pair(58, -20), Pair(-68, -1), Pair(79, -39), Pair(75, 104), Pair(88, 78),
        Pair(92, -145), Pair(35, 16), Pair(52, 12), Pair(-26, 15), Pair(203, -18), Pair(301, -92), Pair(-75, 84), Pair(-142, 48),
        Pair(0, 0), Pair(50, 34), Pair(86, 4), Pair(28, 26), Pair(71, -3), Pair(64, 6), Pair(60, 9), Pair(-10, 20),
        Pair(32, -11), Pair(26, 45), Pair(40, 2), Pair(20, 41), Pair(35, 11), Pair(20, 13), Pair(16, -8), Pair(38, -38),
        Pair(3, 17), Pair(56, -2), Pair(8, 31), Pair(26, 7), Pair(5, 15), Pair(40, 1), Pair(-9, 9), Pair(8, 32),
        Pair(30, 10), Pair(9, 20), Pair(19, 3), Pair(36, 13), Pair(19, 7), Pair(26, 4), Pair(32, -36), Pair(-2, 1),
        Pair(-103, -49), Pair(14, -17), Pair(-12, 8), Pair(10, 12), Pair(5, 0), Pair(30, -23), Pair(-7, 3), Pair(12, -9),
        Pair(-154, -105), Pair(-7, -8), Pair(21, -18), Pair(-68, 44), Pair(30, -10), Pair(-3, -2), Pair(3, -74), Pair(-138, -102)
      },
      { // Piece 2
        Pair(68, -56), Pair(205, -12), Pair(229, -70), Pair(59, 18), Pair(72, -63), Pair(3, -78), Pair(56, -42), Pair(62, -35),
        Pair(34, -55), Pair(94, -11), Pair(146, -41), Pair(219, -64), Pair(-22, -10), Pair(-70, -15), Pair(119, -53), Pair(146, -32),
        Pair(0, 0), Pair(119, -7), Pair(122, -26), Pair(52, 53), Pair(35, -17), Pair(-58, 1), Pair(-46, -23), Pair(-61, 48),
        Pair(9, 62), Pair(62, -6), Pair(9, 47), Pair(43, -17), Pair(59, 1), Pair(-10, -48), Pair(29, 40), Pair(25, -22),
        Pair(15, -38), Pair(12, 9), Pair(33, -18), Pair(26, 17), Pair(54, -4), Pair(14, 16), Pair(-15, -22), Pair(11, 10),
        Pair(6, 12), Pair(16, -16), Pair(3, 9), Pair(32, -18), Pair(14, 29), Pair(38, -24), Pair(41, -23), Pair(2, -7),
        Pair(41, -70), Pair(11, -3), Pair(3, -14), Pair(19, -8), Pair(32, -6), Pair(35, -5), Pair(38, -16), Pair(87, -23),
        Pair(46, -32), Pair(30, -2), Pair(1, -1), Pair(13, 3), Pair(17, 9), Pair(30, 2), Pair(147, -14), Pair(14, 12)
      },
      { // Piece 3
        Pair(53, -34), Pair(17, 35), Pair(12, 40), Pair(104, 10), Pair(5, 23), Pair(-129, 30), Pair(36, 10), Pair(-83, 63),
        Pair(0, -83), Pair(65, 46), Pair(-43, 68), Pair(59, 20), Pair(67, -22), Pair(86, 7), Pair(-39, 41), Pair(51, 48),
        Pair(0, 0), Pair(72, 11), Pair(45, 22), Pair(77, 17), Pair(118, -15), Pair(-14, 35), Pair(36, 25), Pair(-55, 68),
        Pair(-39, 7), Pair(-26, 53), Pair(6, 47), Pair(12, 10), Pair(-1, 27), Pair(-40, 45), Pair(71, 13), Pair(71, 20),
        Pair(-37, 26), Pair(-7, 51), Pair(16, 33), Pair(-20, 81), Pair(6, 45), Pair(-16, 20), Pair(4, 4), Pair(72, 25),
        Pair(-40, 23), Pair(7, 48), Pair(20, 24), Pair(20, 18), Pair(0, 18), Pair(46, -28), Pair(26, 58), Pair(16, 16),
        Pair(-72, 25), Pair(42, 19), Pair(-25, 62), Pair(24, 19), Pair(-13, 25), Pair(-4, 27), Pair(-35, 56), Pair(35, -8),
        Pair(-17, -2), Pair(4, 18), Pair(7, 24), Pair(16, 17), Pair(16, 13), Pair(3, 14), Pair(-1, 38), Pair(5, 11)
      },
      { // Piece 4
        Pair(70, -58), Pair(-14, 48), Pair(2, 64), Pair(-42, 63), Pair(75, -54), Pair(-1, -48), Pair(-103, -46), Pair(-60, 49),
        Pair(15, -169), Pair(33, 28), Pair(26, 24), Pair(-77, 72), Pair(41, 23), Pair(130, -92), Pair(-133, 201), Pair(37, -21),
        Pair(0, 0), Pair(52, 1), Pair(-19, 104), Pair(-33, 74), Pair(15, -33), Pair(38, 0), Pair(-12, 53), Pair(-59, 40),
        Pair(42, -80), Pair(13, 64), Pair(-4, 71), Pair(10, 31), Pair(47, 34), Pair(62, 1), Pair(-23, 36), Pair(47, -18),
        Pair(-1, 20), Pair(12, 30), Pair(10, 43), Pair(36, -34), Pair(-16, 74), Pair(35, 11), Pair(15, 23), Pair(33, -49),
        Pair(4, 77), Pair(3, 64), Pair(29, -3), Pair(4, 32), Pair(-23, 75), Pair(21, -11), Pair(3, 16), Pair(33, -59),
        Pair(-2, 20), Pair(24, -1), Pair(-7, 40), Pair(18, -3), Pair(2, 65), Pair(3, 13), Pair(8, 17), Pair(38, -50),
        Pair(-5, -20), Pair(17, 39), Pair(8, -4), Pair(2, 29), Pair(2, 21), Pair(32, -12), Pair(-12, -28), Pair(-24, -158)
      },
      { // Piece 5
        Pair(-6, -72), Pair(-50, 117), Pair(-107, 108), Pair(13, -53), Pair(-45, -102), Pair(-19, -33), Pair(13, 40), Pair(-10, -59),
        Pair(-42, -41), Pair(-141, 137), Pair(-15, 98), Pair(50, 72), Pair(81, 34), Pair(12, -29), Pair(79, -75), Pair(114, -4),
        Pair(0, 0), Pair(57, 97), Pair(163, 63), Pair(132, 48), Pair(56, -35), Pair(73, 27), Pair(38, -22), Pair(-33, 44),
        Pair(184, 24), Pair(99, 57), Pair(73, 68), Pair(273, -6), Pair(-53, 67), Pair(112, -16), Pair(-56, 18), Pair(39, 2),
        Pair(8, 16), Pair(125, 34), Pair(155, 29), Pair(170, 24), Pair(42, 13), Pair(81, 8), Pair(-5, 11), Pair(-148, 25),
        Pair(82, 41), Pair(-52, 78), Pair(12, 36), Pair(-15, 35), Pair(-73, 42), Pair(-19, 12), Pair(-8, -5), Pair(-66, 8),
        Pair(-7, 37), Pair(57, 37), Pair(30, 23), Pair(-18, 24), Pair(-15, 23), Pair(-52, 23), Pair(-18, 9), Pair(-13, -8),
        Pair(61, 17), Pair(89, -6), Pair(84, 10), Pair(3, 30), Pair(-16, -7), Pair(-23, 4), Pair(-12, 1), Pair(-27, -7)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-79, 37), Pair(-50, -71), Pair(57, 11), Pair(-83, 28), Pair(-57, 21), Pair(-23, 45), Pair(28, 94), Pair(-29, 32),
        Pair(-7, -13), Pair(10, 39), Pair(9, 21), Pair(-10, 15), Pair(23, 17), Pair(-40, 29), Pair(45, 10), Pair(14, 9),
        Pair(16, 7), Pair(9, -33), Pair(13, 14), Pair(-13, 18), Pair(-2, 16), Pair(-4, 14), Pair(-8, 6), Pair(-3, 20),
        Pair(-3, 23), Pair(10, 7), Pair(-6, 15), Pair(4, 7), Pair(0, 4), Pair(1, 7), Pair(5, 10), Pair(-7, 16),
        Pair(-5, 17), Pair(13, 8), Pair(9, 12), Pair(9, 1), Pair(-1, 9), Pair(5, 9), Pair(3, 13), Pair(2, 10),
        Pair(-12, 22), Pair(2, -9), Pair(-21, 21), Pair(19, -3), Pair(-14, 11), Pair(-2, 12), Pair(-1, 16), Pair(-3, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-85, -56), Pair(-250, 92), Pair(99, -8), Pair(43, -15), Pair(-175, -17), Pair(71, 45), Pair(-65, 38), Pair(10, 168),
        Pair(8, 4), Pair(105, -101), Pair(-28, 28), Pair(35, 60), Pair(-56, 77), Pair(8, -4), Pair(158, 67), Pair(9, -67),
        Pair(-136, 86), Pair(0, 0), Pair(73, 35), Pair(-10, 38), Pair(86, -8), Pair(-29, 6), Pair(171, -90), Pair(38, 44),
        Pair(99, 11), Pair(5, 58), Pair(70, 43), Pair(56, 20), Pair(41, 37), Pair(28, 49), Pair(-14, 21), Pair(-69, 26),
        Pair(-16, 32), Pair(43, 38), Pair(56, 12), Pair(22, 6), Pair(34, 3), Pair(20, 23), Pair(8, 74), Pair(24, -38),
        Pair(-82, 82), Pair(32, 17), Pair(21, 22), Pair(-27, 33), Pair(57, 4), Pair(28, 2), Pair(53, -9), Pair(-5, 31),
        Pair(-136, -2), Pair(120, -80), Pair(17, -29), Pair(5, 6), Pair(-8, 3), Pair(-11, 59), Pair(52, -48), Pair(33, -48),
        Pair(118, -91), Pair(-48, 28), Pair(-14, 34), Pair(33, -36), Pair(0, 1), Pair(52, 3), Pair(48, -74), Pair(16, -14)
      },
      { // Piece 2
        Pair(88, -57), Pair(0, 8), Pair(-51, 30), Pair(84, -19), Pair(-14, -5), Pair(49, -33), Pair(-38, -34), Pair(39, -23),
        Pair(-113, 14), Pair(-2, -41), Pair(83, -11), Pair(121, -45), Pair(288, -85), Pair(-155, 46), Pair(144, -72), Pair(-61, 66),
        Pair(67, 5), Pair(0, 0), Pair(211, -21), Pair(67, -13), Pair(38, 26), Pair(128, -41), Pair(114, -2), Pair(88, -48),
        Pair(18, 0), Pair(34, 53), Pair(49, -12), Pair(47, 21), Pair(47, -19), Pair(118, -51), Pair(52, -26), Pair(16, 4),
        Pair(-13, 32), Pair(28, -6), Pair(75, 9), Pair(46, 3), Pair(38, 32), Pair(57, -13), Pair(17, 25), Pair(-44, 78),
        Pair(8, 8), Pair(-1, 14), Pair(25, -23), Pair(46, 14), Pair(48, -3), Pair(48, 25), Pair(53, 15), Pair(31, -10),
        Pair(62, 15), Pair(-1, 2), Pair(-8, 37), Pair(31, -19), Pair(7, 30), Pair(74, -19), Pair(32, 36), Pair(51, -38),
        Pair(45, -46), Pair(22, -13), Pair(-5, -17), Pair(44, 16), Pair(17, -21), Pair(31, 16), Pair(39, -27), Pair(-9, -53)
      },
      { // Piece 3
        Pair(91, 39), Pair(18, -17), Pair(-112, 94), Pair(-36, 73), Pair(113, 32), Pair(22, 14), Pair(62, 20), Pair(166, -16),
        Pair(21, 47), Pair(-71, -50), Pair(77, 37), Pair(39, 40), Pair(59, 30), Pair(31, -8), Pair(43, 40), Pair(43, 46),
        Pair(29, 43), Pair(0, 0), Pair(51, 34), Pair(24, 59), Pair(-9, 43), Pair(67, 22), Pair(-10, 46), Pair(79, 52),
        Pair(30, 36), Pair(9, 31), Pair(-4, 67), Pair(35, 45), Pair(45, 22), Pair(133, -18), Pair(14, 73), Pair(69, 30),
        Pair(-30, 81), Pair(-11, 35), Pair(-18, 76), Pair(55, 33), Pair(13, 27), Pair(73, 5), Pair(-3, 8), Pair(17, 50),
        Pair(-18, 53), Pair(-26, 49), Pair(23, 71), Pair(28, 32), Pair(25, 10), Pair(58, 19), Pair(48, 48), Pair(23, 23),
        Pair(-13, 11), Pair(-26, 45), Pair(11, 48), Pair(26, 58), Pair(-20, 53), Pair(12, 36), Pair(16, 26), Pair(77, 26),
        Pair(5, 30), Pair(16, 20), Pair(20, 36), Pair(26, 16), Pair(3, 39), Pair(31, 20), Pair(24, 12), Pair(-3, 15)
      },
      { // Piece 4
        Pair(-25, -2), Pair(12, 19), Pair(8, 35), Pair(3, 95), Pair(70, -29), Pair(0, -23), Pair(69, 38), Pair(35, -47),
        Pair(-82, 7), Pair(-117, 5), Pair(29, 23), Pair(96, -23), Pair(-34, 107), Pair(74, 21), Pair(-97, 46), Pair(22, 24),
        Pair(-2, 57), Pair(0, 0), Pair(13, 52), Pair(8, 68), Pair(154, -31), Pair(-100, 125), Pair(60, 48), Pair(-21, 12),
        Pair(19, 18), Pair(-5, 34), Pair(73, 13), Pair(26, 73), Pair(44, 10), Pair(-16, 118), Pair(-39, 13), Pair(-40, 156),
        Pair(18, -5), Pair(2, 56), Pair(58, -21), Pair(16, 40), Pair(-38, 89), Pair(-20, 127), Pair(-29, 20), Pair(23, 31),
        Pair(-25, 134), Pair(29, -31), Pair(-10, 74), Pair(-6, 6), Pair(8, 61), Pair(41, -57), Pair(8, -5), Pair(40, 1),
        Pair(-19, 108), Pair(21, -29), Pair(8, 30), Pair(6, 78), Pair(45, -30), Pair(-25, 87), Pair(8, 80), Pair(98, 7),
        Pair(-32, 89), Pair(-19, 37), Pair(-27, 83), Pair(3, 38), Pair(8, -25), Pair(26, -10), Pair(-91, -3), Pair(40, 2)
      },
      { // Piece 5
        Pair(-4, 158), Pair(91, 139), Pair(64, 282), Pair(-17, -37), Pair(-9, -77), Pair(13, 25), Pair(-75, -33), Pair(-35, -44),
        Pair(17, 138), Pair(87, 19), Pair(98, 51), Pair(37, 95), Pair(79, 19), Pair(-80, -20), Pair(64, 9), Pair(-24, -14),
        Pair(148, 81), Pair(0, 0), Pair(151, 89), Pair(22, 100), Pair(61, -31), Pair(25, -26), Pair(-76, 36), Pair(-117, 26),
        Pair(4, 104), Pair(26, 60), Pair(220, 43), Pair(121, 55), Pair(98, 6), Pair(-2, 13), Pair(195, -37), Pair(-110, -22),
        Pair(97, 68), Pair(18, 27), Pair(37, 43), Pair(98, 9), Pair(-3, 7), Pair(-45, 1), Pair(-245, 45), Pair(-17, -6),
        Pair(-21, 34), Pair(-7, 21), Pair(-9, 40), Pair(76, 7), Pair(10, 8), Pair(2, -19), Pair(-44, -1), Pair(-92, -1),
        Pair(146, -37), Pair(136, -17), Pair(21, 15), Pair(-22, 14), Pair(-2, -13), Pair(-66, 17), Pair(-45, -5), Pair(-39, -7),
        Pair(-41, 135), Pair(67, 29), Pair(-4, 70), Pair(20, -42), Pair(8, -35), Pair(-40, -10), Pair(-12, -8), Pair(-15, -28)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 45), Pair(14, -28), Pair(18, -91), Pair(23, 7), Pair(-132, 67), Pair(-45, 61), Pair(-49, 7), Pair(-96, 37),
        Pair(-6, 12), Pair(9, 21), Pair(3, 28), Pair(-26, 48), Pair(16, 10), Pair(43, 14), Pair(-26, 10), Pair(-75, 41),
        Pair(-3, 10), Pair(16, 24), Pair(-36, -22), Pair(14, 27), Pair(1, 18), Pair(15, 13), Pair(-10, 18), Pair(33, 11),
        Pair(-1, 15), Pair(-13, 25), Pair(-15, 1), Pair(-9, 21), Pair(-4, 13), Pair(2, 12), Pair(-1, 10), Pair(-5, 9),
        Pair(-6, 15), Pair(-10, 16), Pair(-12, -1), Pair(8, 6), Pair(0, 6), Pair(18, 6), Pair(-7, 14), Pair(0, 11),
        Pair(-5, 19), Pair(-12, 17), Pair(-14, 5), Pair(-13, 11), Pair(-11, 19), Pair(-2, 11), Pair(-7, 14), Pair(-3, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-101, 58), Pair(72, -59), Pair(1, 11), Pair(-75, 19), Pair(23, 68), Pair(-91, -91), Pair(21, 103), Pair(12, 73),
        Pair(-134, 73), Pair(82, 47), Pair(-34, -28), Pair(79, 27), Pair(121, 19), Pair(102, -24), Pair(82, -6), Pair(28, 18),
        Pair(43, 7), Pair(44, 7), Pair(0, 0), Pair(66, 4), Pair(175, -17), Pair(89, 11), Pair(15, 43), Pair(-28, 146),
        Pair(-19, 62), Pair(63, 43), Pair(37, 66), Pair(64, 65), Pair(29, 6), Pair(91, -4), Pair(27, 34), Pair(90, -26),
        Pair(50, -21), Pair(67, 10), Pair(1, 26), Pair(37, 42), Pair(-22, 52), Pair(7, 71), Pair(-52, 82), Pair(51, -24),
        Pair(49, 15), Pair(4, 28), Pair(17, 37), Pair(22, 23), Pair(32, 10), Pair(12, 33), Pair(0, 42), Pair(70, -63),
        Pair(44, -57), Pair(73, -77), Pair(7, 64), Pair(14, 16), Pair(2, 36), Pair(46, -4), Pair(-50, 64), Pair(27, -10),
        Pair(3, 45), Pair(0, 22), Pair(-131, 26), Pair(-61, -4), Pair(-44, 63), Pair(-27, 33), Pair(-12, 86), Pair(-32, 33)
      },
      { // Piece 2
        Pair(-63, -79), Pair(52, 41), Pair(82, -25), Pair(82, 33), Pair(-53, 29), Pair(146, -17), Pair(63, -85), Pair(156, -23),
        Pair(-86, 107), Pair(75, -42), Pair(-15, -63), Pair(111, -40), Pair(150, -6), Pair(183, -62), Pair(-23, -17), Pair(-67, -47),
        Pair(79, -31), Pair(206, -42), Pair(0, 0), Pair(84, 35), Pair(76, -32), Pair(170, -30), Pair(70, -66), Pair(37, -39),
        Pair(93, 8), Pair(45, -26), Pair(-20, 86), Pair(39, 14), Pair(34, 29), Pair(64, -43), Pair(73, -24), Pair(105, -25),
        Pair(-7, 1), Pair(64, 20), Pair(-2, -6), Pair(38, 22), Pair(31, 0), Pair(51, 17), Pair(52, 2), Pair(81, -61),
        Pair(24, 6), Pair(82, -77), Pair(24, 53), Pair(18, 27), Pair(-9, 42), Pair(39, -2), Pair(37, -7), Pair(8, 20),
        Pair(44, -28), Pair(30, 1), Pair(51, -27), Pair(48, -11), Pair(18, -4), Pair(66, 19), Pair(44, -4), Pair(66, 73),
        Pair(55, -14), Pair(-57, 0), Pair(32, -11), Pair(12, 20), Pair(-13, 61), Pair(22, -2), Pair(58, 7), Pair(-21, -26)
      },
      { // Piece 3
        Pair(48, 49), Pair(123, 64), Pair(25, -2), Pair(-172, 134), Pair(132, -14), Pair(-93, 74), Pair(-149, 66), Pair(-25, 41),
        Pair(-9, 64), Pair(25, 55), Pair(-11, -68), Pair(75, 24), Pair(28, 41), Pair(82, 58), Pair(56, 40), Pair(111, 47),
        Pair(28, 40), Pair(19, 50), Pair(0, 0), Pair(25, 29), Pair(117, 1), Pair(35, -3), Pair(105, 7), Pair(122, 1),
        Pair(1, 55), Pair(7, 52), Pair(29, 21), Pair(-37, 60), Pair(-29, 27), Pair(-2, 71), Pair(-135, 113), Pair(20, 23),
        Pair(8, 57), Pair(-56, 79), Pair(5, 37), Pair(-51, 66), Pair(16, 35), Pair(-44, 37), Pair(52, 36), Pair(-21, 11),
        Pair(-5, 60), Pair(23, -2), Pair(-77, 51), Pair(8, 50), Pair(14, 27), Pair(35, 31), Pair(-9, 24), Pair(57, 20),
        Pair(9, 29), Pair(38, 39), Pair(-8, 12), Pair(-6, 63), Pair(-44, 69), Pair(-60, 43), Pair(3, 64), Pair(55, 21),
        Pair(11, 19), Pair(3, 37), Pair(6, 13), Pair(10, 26), Pair(10, 55), Pair(12, 26), Pair(-46, 61), Pair(1, -11)
      },
      { // Piece 4
        Pair(-22, 23), Pair(48, 92), Pair(8, 37), Pair(78, -31), Pair(142, -67), Pair(-77, -48), Pair(-59, -69), Pair(134, -39),
        Pair(94, -63), Pair(73, -27), Pair(78, -132), Pair(0, 43), Pair(162, -92), Pair(144, -90), Pair(40, 204), Pair(65, -4),
        Pair(56, -36), Pair(5, 28), Pair(0, 0), Pair(-28, 89), Pair(0, 23), Pair(104, 2), Pair(-104, 139), Pair(27, 1),
        Pair(-16, 106), Pair(13, 14), Pair(-9, 80), Pair(-63, 94), Pair(78, -14), Pair(-2, 65), Pair(47, -54), Pair(-40, 141),
        Pair(19, 32), Pair(15, 5), Pair(-17, 63), Pair(34, -1), Pair(-57, 97), Pair(-19, 129), Pair(-32, 52), Pair(34, 44),
        Pair(29, -67), Pair(9, 40), Pair(44, -17), Pair(33, -26), Pair(41, -13), Pair(31, 71), Pair(21, 9), Pair(-59, 161),
        Pair(30, -82), Pair(19, -32), Pair(-5, 45), Pair(-18, 48), Pair(5, 17), Pair(24, -20), Pair(27, -36), Pair(9, 67),
        Pair(40, -9), Pair(59, -1), Pair(18, -22), Pair(25, 3), Pair(30, -63), Pair(54, -40), Pair(81, -102), Pair(-43, 43)
      },
      { // Piece 5
        Pair(-4, 30), Pair(20, 126), Pair(118, 110), Pair(8, 109), Pair(15, 9), Pair(-1, -42), Pair(-4, 60), Pair(5, 52),
        Pair(-9, 128), Pair(100, 74), Pair(126, 13), Pair(15, 38), Pair(136, 51), Pair(-13, 39), Pair(13, -36), Pair(47, 5),
        Pair(97, 43), Pair(152, 80), Pair(0, 0), Pair(36, 86), Pair(102, 26), Pair(-125, 33), Pair(13, -4), Pair(67, 43),
        Pair(-149, 125), Pair(107, 64), Pair(23, 71), Pair(25, 62), Pair(89, 27), Pair(-33, 66), Pair(-48, 12), Pair(-109, 20),
        Pair(94, 3), Pair(84, 43), Pair(-11, 49), Pair(46, 53), Pair(174, -9), Pair(79, -3), Pair(-5, -7), Pair(-224, 46),
        Pair(30, 77), Pair(-11, 50), Pair(42, 11), Pair(-21, 30), Pair(-6, 30), Pair(-17, 0), Pair(15, -7), Pair(23, -37),
        Pair(55, 62), Pair(12, 10), Pair(5, 12), Pair(-136, 43), Pair(-18, 2), Pair(-32, -1), Pair(-29, -4), Pair(-49, -2),
        Pair(150, 27), Pair(19, 29), Pair(3, 12), Pair(-129, 9), Pair(-6, 10), Pair(-18, -19), Pair(-31, -3), Pair(-30, -10)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-31, 40), Pair(-9, 53), Pair(-43, 16), Pair(-16, -50), Pair(79, -16), Pair(-43, 52), Pair(108, -7), Pair(56, 16),
        Pair(-14, 40), Pair(-10, 16), Pair(-25, 48), Pair(11, 12), Pair(16, 22), Pair(55, -8), Pair(-33, 18), Pair(-19, 21),
        Pair(10, 17), Pair(4, 14), Pair(13, 33), Pair(-3, -26), Pair(14, 37), Pair(13, 10), Pair(13, 13), Pair(-2, 15),
        Pair(4, 8), Pair(11, 8), Pair(-11, 21), Pair(-5, 5), Pair(0, 15), Pair(9, 6), Pair(1, 4), Pair(0, 7),
        Pair(-3, 9), Pair(1, 3), Pair(-3, 6), Pair(-2, 5), Pair(6, 8), Pair(6, 8), Pair(-3, 4), Pair(3, 6),
        Pair(-8, 16), Pair(-6, 13), Pair(-9, 12), Pair(14, -2), Pair(-3, 16), Pair(-2, 9), Pair(5, 2), Pair(2, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(20, 18), Pair(36, 71), Pair(-17, 20), Pair(66, -10), Pair(-97, 91), Pair(-103, -16), Pair(-138, 57), Pair(44, 131),
        Pair(117, 38), Pair(72, 51), Pair(-6, 89), Pair(39, -35), Pair(61, 3), Pair(-52, 117), Pair(-85, -57), Pair(34, -75),
        Pair(-67, 66), Pair(-35, 71), Pair(3, 80), Pair(0, 0), Pair(65, 89), Pair(123, 32), Pair(99, 40), Pair(-59, 109),
        Pair(33, 64), Pair(19, 62), Pair(59, 64), Pair(18, 81), Pair(34, 75), Pair(60, 38), Pair(42, 20), Pair(4, 118),
        Pair(71, 3), Pair(83, 24), Pair(23, 34), Pair(-29, 59), Pair(23, 56), Pair(9, 56), Pair(-5, 35), Pair(24, 21),
        Pair(-6, 99), Pair(8, 31), Pair(10, 13), Pair(41, 29), Pair(62, 24), Pair(-9, 41), Pair(12, 1), Pair(-6, 51),
        Pair(-41, 24), Pair(3, -8), Pair(35, -20), Pair(-6, 54), Pair(-9, 47), Pair(19, 62), Pair(62, -14), Pair(-46, 0),
        Pair(110, 79), Pair(-13, 61), Pair(28, -13), Pair(102, -52), Pair(-46, 16), Pair(7, 6), Pair(-25, -46), Pair(4, -54)
      },
      { // Piece 2
        Pair(220, -64), Pair(-52, 8), Pair(279, -11), Pair(42, 1), Pair(-28, 94), Pair(-106, -20), Pair(-83, 15), Pair(59, -21),
        Pair(31, 0), Pair(-9, 14), Pair(81, -9), Pair(-6, 5), Pair(104, -11), Pair(157, -35), Pair(7, -5), Pair(22, 74),
        Pair(24, 70), Pair(53, -37), Pair(38, 27), Pair(0, 0), Pair(140, 4), Pair(140, -15), Pair(63, 5), Pair(51, -6),
        Pair(-3, 27), Pair(41, 36), Pair(-11, 37), Pair(111, 34), Pair(26, 26), Pair(81, 13), Pair(17, -1), Pair(65, 1),
        Pair(29, 36), Pair(36, 19), Pair(34, 57), Pair(70, -16), Pair(33, 23), Pair(33, 15), Pair(10, 53), Pair(40, -15),
        Pair(-25, 25), Pair(16, 34), Pair(32, -2), Pair(47, 29), Pair(26, 18), Pair(41, 18), Pair(24, 6), Pair(48, 35),
        Pair(-39, -14), Pair(7, 32), Pair(11, 45), Pair(0, 4), Pair(25, 36), Pair(32, 0), Pair(33, 15), Pair(23, 8),
        Pair(3, 3), Pair(-16, 47), Pair(12, -5), Pair(-14, 70), Pair(29, -23), Pair(22, 33), Pair(5, 41), Pair(-4, -9)
      },
      { // Piece 3
        Pair(-32, 101), Pair(-75, 94), Pair(19, 64), Pair(30, 27), Pair(31, 53), Pair(131, 29), Pair(-68, 66), Pair(-53, 94),
        Pair(48, 62), Pair(45, 72), Pair(90, 29), Pair(-117, -10), Pair(129, 35), Pair(136, 20), Pair(50, 62), Pair(153, 17),
        Pair(-26, 56), Pair(59, 14), Pair(-47, 71), Pair(0, 0), Pair(116, 23), Pair(-73, 84), Pair(136, 27), Pair(-54, 97),
        Pair(-6, 78), Pair(19, 57), Pair(5, 50), Pair(27, 25), Pair(-4, 66), Pair(-3, 53), Pair(-39, 101), Pair(28, 12),
        Pair(3, 72), Pair(-5, 79), Pair(42, 27), Pair(20, 37), Pair(44, 37), Pair(55, 56), Pair(-83, 56), Pair(51, 6),
        Pair(6, 53), Pair(21, 28), Pair(-42, 70), Pair(26, 39), Pair(-13, 61), Pair(15, 67), Pair(54, -31), Pair(-4, 97),
        Pair(5, 43), Pair(24, 27), Pair(12, 26), Pair(-6, 56), Pair(16, 30), Pair(43, 14), Pair(9, 44), Pair(-65, 69),
        Pair(1, 51), Pair(18, 28), Pair(-12, 66), Pair(19, 33), Pair(11, 59), Pair(9, 34), Pair(40, 50), Pair(-1, 30)
      },
      { // Piece 4
        Pair(-83, 42), Pair(-30, 70), Pair(137, -77), Pair(44, 0), Pair(-81, 48), Pair(-28, 24), Pair(95, 48), Pair(99, -51),
        Pair(-65, 162), Pair(50, 8), Pair(-38, 95), Pair(-37, -23), Pair(30, -26), Pair(136, -77), Pair(92, 94), Pair(5, 134),
        Pair(35, 28), Pair(70, -20), Pair(-11, 45), Pair(0, 0), Pair(98, -15), Pair(-56, 91), Pair(-33, 188), Pair(92, -9),
        Pair(28, 39), Pair(-20, 83), Pair(32, 61), Pair(27, 23), Pair(16, 61), Pair(42, 5), Pair(77, -25), Pair(47, 24),
        Pair(15, -9), Pair(21, 8), Pair(50, -36), Pair(5, 82), Pair(1, 107), Pair(-22, 76), Pair(28, 52), Pair(4, 24),
        Pair(18, 27), Pair(58, -64), Pair(10, 23), Pair(38, 16), Pair(44, 53), Pair(37, 9), Pair(44, -25), Pair(78, -113),
        Pair(24, 35), Pair(-12, 117), Pair(39, -17), Pair(30, 9), Pair(0, 73), Pair(6, 16), Pair(9, 32), Pair(3, 40),
        Pair(25, -100), Pair(58, -37), Pair(36, 37), Pair(-4, 51), Pair(37, 20), Pair(36, 12), Pair(-37, -15), Pair(14, -48)
      },
      { // Piece 5
        Pair(21, -27), Pair(11, 210), Pair(28, 115), Pair(68, 37), Pair(13, 199), Pair(24, -77), Pair(-3, -44), Pair(5, 26),
        Pair(28, 48), Pair(14, 107), Pair(6, 73), Pair(-78, -6), Pair(64, 82), Pair(25, 102), Pair(44, 26), Pair(29, -43),
        Pair(28, 85), Pair(36, 5), Pair(168, 66), Pair(0, 0), Pair(122, 93), Pair(96, 30), Pair(20, 18), Pair(-38, 16),
        Pair(-79, 35), Pair(85, -2), Pair(132, 59), Pair(-8, 81), Pair(90, 32), Pair(47, 36), Pair(-85, 4), Pair(48, -62),
        Pair(44, 14), Pair(22, 27), Pair(167, -16), Pair(67, 24), Pair(-58, 38), Pair(119, -26), Pair(-65, 35), Pair(-204, 12),
        Pair(-158, 112), Pair(47, -29), Pair(95, -21), Pair(-103, 21), Pair(36, -20), Pair(51, -19), Pair(-45, -14), Pair(-5, -44),
        Pair(41, -26), Pair(-12, -19), Pair(-82, -15), Pair(-76, 8), Pair(-69, -12), Pair(-60, 3), Pair(21, -37), Pair(5, -22),
        Pair(-4, 30), Pair(16, 3), Pair(-10, -7), Pair(-47, 18), Pair(-28, -32), Pair(-5, -40), Pair(5, -30), Pair(-16, -23)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-69, 48), Pair(-45, 21), Pair(-90, -12), Pair(0, 27), Pair(146, -62), Pair(-109, 31), Pair(-54, 46), Pair(34, -3),
        Pair(17, 26), Pair(23, 17), Pair(16, 10), Pair(16, 22), Pair(10, 5), Pair(15, 15), Pair(7, 5), Pair(-3, 27),
        Pair(2, 5), Pair(7, 3), Pair(13, -2), Pair(8, 34), Pair(-21, -29), Pair(23, 27), Pair(4, 9), Pair(9, 7),
        Pair(-1, 7), Pair(4, 11), Pair(16, -1), Pair(-2, 20), Pair(6, -10), Pair(2, 14), Pair(2, 3), Pair(-6, 12),
        Pair(3, 7), Pair(5, 6), Pair(6, 12), Pair(3, 8), Pair(-1, 10), Pair(6, 2), Pair(-5, 10), Pair(-7, 10),
        Pair(-3, 13), Pair(10, 2), Pair(14, 0), Pair(-11, 36), Pair(2, 10), Pair(2, 15), Pair(-9, 11), Pair(-8, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(69, 108), Pair(-60, 67), Pair(-46, -32), Pair(-40, 17), Pair(59, 33), Pair(73, 104), Pair(119, 30), Pair(-38, 173),
        Pair(39, -13), Pair(-120, 88), Pair(-24, 70), Pair(78, 20), Pair(-105, -19), Pair(5, 37), Pair(129, 52), Pair(78, 44),
        Pair(104, 56), Pair(45, 126), Pair(65, -3), Pair(39, 30), Pair(0, 0), Pair(114, -6), Pair(40, 68), Pair(-40, 58),
        Pair(-53, 52), Pair(-8, 43), Pair(0, 43), Pair(86, 67), Pair(6, 49), Pair(49, 56), Pair(28, 10), Pair(39, 76),
        Pair(-3, 28), Pair(237, 5), Pair(20, -3), Pair(31, 40), Pair(-12, 48), Pair(27, 28), Pair(118, -18), Pair(6, 8),
        Pair(-3, 68), Pair(15, -2), Pair(1, 45), Pair(-4, 9), Pair(27, -2), Pair(15, 36), Pair(-21, 31), Pair(-2, -12),
        Pair(-103, -17), Pair(-25, -55), Pair(18, 3), Pair(-5, 23), Pair(22, -3), Pair(-2, 72), Pair(27, 59), Pair(-18, -27),
        Pair(-61, -66), Pair(-1, 0), Pair(62, -72), Pair(6, 17), Pair(-69, 30), Pair(-73, 126), Pair(-21, -68), Pair(-38, 8)
      },
      { // Piece 2
        Pair(129, -76), Pair(44, 14), Pair(82, 16), Pair(240, -56), Pair(96, -65), Pair(45, -11), Pair(28, -31), Pair(27, 31),
        Pair(-82, 43), Pair(91, 14), Pair(21, 2), Pair(104, -41), Pair(25, -84), Pair(72, -35), Pair(-12, 16), Pair(151, -58),
        Pair(27, -32), Pair(156, -53), Pair(42, -53), Pair(93, 10), Pair(0, 0), Pair(143, -14), Pair(58, -66), Pair(-2, 59),
        Pair(23, 40), Pair(-13, 30), Pair(47, 3), Pair(12, -5), Pair(38, 51), Pair(73, -17), Pair(40, 24), Pair(-16, -21),
        Pair(122, -52), Pair(8, 3), Pair(33, 0), Pair(-16, 65), Pair(52, -18), Pair(23, 16), Pair(55, -14), Pair(-31, -28),
        Pair(-15, 18), Pair(35, -8), Pair(36, 9), Pair(59, -5), Pair(15, 9), Pair(13, 8), Pair(-5, 32), Pair(-52, 6),
        Pair(-17, -18), Pair(7, 33), Pair(87, -58), Pair(7, 18), Pair(18, -3), Pair(19, 38), Pair(17, 0), Pair(-39, 50),
        Pair(-16, 53), Pair(1, -1), Pair(-23, 44), Pair(46, -24), Pair(-32, 35), Pair(3, 1), Pair(54, 4), Pair(19, -111)
      },
      { // Piece 3
        Pair(-115, 84), Pair(68, 3), Pair(-51, 69), Pair(40, 17), Pair(-66, 35), Pair(-5, 23), Pair(-208, 96), Pair(-79, 79),
        Pair(53, 27), Pair(-20, 68), Pair(11, 27), Pair(49, 20), Pair(70, -141), Pair(136, -6), Pair(33, 49), Pair(56, 21),
        Pair(-38, 51), Pair(71, -13), Pair(8, 12), Pair(106, -14), Pair(0, 0), Pair(-82, 63), Pair(-35, 54), Pair(50, 19),
        Pair(18, 36), Pair(82, -33), Pair(27, 38), Pair(43, -13), Pair(60, -18), Pair(4, 29), Pair(55, 39), Pair(68, 22),
        Pair(-46, 5), Pair(142, -83), Pair(7, 43), Pair(-38, 35), Pair(-40, 16), Pair(34, 17), Pair(87, 25), Pair(55, -9),
        Pair(-64, 28), Pair(51, -1), Pair(6, -1), Pair(55, -62), Pair(50, -25), Pair(44, -6), Pair(16, -3), Pair(-26, 8),
        Pair(-75, 52), Pair(-29, 1), Pair(6, -4), Pair(13, 3), Pair(-27, 28), Pair(-9, 45), Pair(3, 41), Pair(-91, 58),
        Pair(-40, 32), Pair(-4, 18), Pair(4, 9), Pair(-3, -5), Pair(18, 5), Pair(1, 33), Pair(-1, 43), Pair(1, 28)
      },
      { // Piece 4
        Pair(-40, 17), Pair(-75, 44), Pair(-11, -9), Pair(150, -82), Pair(-31, -10), Pair(91, -29), Pair(-21, 40), Pair(47, 61),
        Pair(92, -87), Pair(-28, 90), Pair(140, -122), Pair(-60, 89), Pair(-114, 39), Pair(88, 22), Pair(105, 79), Pair(35, -26),
        Pair(40, -98), Pair(62, -33), Pair(33, -178), Pair(71, -45), Pair(0, 0), Pair(181, -85), Pair(16, -19), Pair(93, 29),
        Pair(14, 59), Pair(-30, 63), Pair(24, -5), Pair(18, -3), Pair(-30, 39), Pair(87, -2), Pair(17, -9), Pair(45, 23),
        Pair(-41, 42), Pair(114, -207), Pair(1, 48), Pair(-13, 57), Pair(-69, 138), Pair(26, 17), Pair(53, -44), Pair(-23, 80),
        Pair(32, -130), Pair(18, -31), Pair(-25, 49), Pair(40, -56), Pair(-10, 15), Pair(52, -44), Pair(33, 7), Pair(-29, 59),
        Pair(60, -111), Pair(-19, -1), Pair(-38, 176), Pair(-30, 33), Pair(-6, -21), Pair(6, 13), Pair(-7, 55), Pair(9, -58),
        Pair(2, -7), Pair(72, -74), Pair(17, -40), Pair(0, 44), Pair(-22, 24), Pair(-23, 162), Pair(97, -14), Pair(101, -39)
      },
      { // Piece 5
        Pair(42, 75), Pair(11, -43), Pair(-4, 2), Pair(45, 137), Pair(47, -39), Pair(-10, 126), Pair(-4, 46), Pair(-3, 89),
        Pair(14, 51), Pair(5, 18), Pair(24, 38), Pair(-52, 15), Pair(27, -24), Pair(-46, 36), Pair(-24, -2), Pair(-26, -28),
        Pair(63, 25), Pair(-49, 40), Pair(106, 30), Pair(106, 39), Pair(0, 0), Pair(149, 60), Pair(116, 1), Pair(-29, 6),
        Pair(83, 9), Pair(119, -17), Pair(-68, 57), Pair(250, 15), Pair(-52, 69), Pair(61, 41), Pair(48, 6), Pair(-50, 7),
        Pair(110, -15), Pair(-161, 50), Pair(-133, 43), Pair(-92, 62), Pair(-5, 23), Pair(37, 5), Pair(10, -9), Pair(-62, 16),
        Pair(-201, -9), Pair(160, -52), Pair(32, -11), Pair(-21, -3), Pair(-48, 19), Pair(71, -19), Pair(49, -38), Pair(27, -26),
        Pair(-4, -15), Pair(9, 5), Pair(-68, -9), Pair(-63, 4), Pair(0, -31), Pair(3, -19), Pair(32, -35), Pair(32, -36),
        Pair(25, -53), Pair(-2, -7), Pair(-16, 15), Pair(31, -51), Pair(-7, -50), Pair(32, -45), Pair(11, -39), Pair(43, -58)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 43), Pair(30, 39), Pair(-65, 35), Pair(44, 42), Pair(54, -12), Pair(18, -46), Pair(-4, -8), Pair(-29, 17),
        Pair(12, 11), Pair(-40, 29), Pair(43, 14), Pair(55, -7), Pair(14, 15), Pair(24, 5), Pair(0, -24), Pair(-45, -3),
        Pair(-9, 14), Pair(14, 6), Pair(37, -3), Pair(6, 10), Pair(26, 5), Pair(7, -20), Pair(-13, 13), Pair(-13, 4),
        Pair(0, 6), Pair(-10, 16), Pair(-4, 13), Pair(3, 10), Pair(3, 12), Pair(-9, 12), Pair(-12, 14), Pair(-8, 11),
        Pair(5, 6), Pair(3, 10), Pair(5, 2), Pair(0, 5), Pair(-6, 8), Pair(5, 11), Pair(0, 5), Pair(-8, 10),
        Pair(-2, 7), Pair(1, 6), Pair(3, 2), Pair(-2, 3), Pair(-46, 50), Pair(-7, 11), Pair(-4, 9), Pair(-8, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(18, -8), Pair(9, 68), Pair(-17, 64), Pair(64, 13), Pair(-6, 47), Pair(-37, 37), Pair(-83, 75), Pair(-67, -15),
        Pair(-142, -98), Pair(137, -20), Pair(-6, 46), Pair(136, -2), Pair(112, -20), Pair(-131, 12), Pair(132, 19), Pair(-54, -1),
        Pair(-107, 66), Pair(-74, 15), Pair(-62, 45), Pair(27, 26), Pair(43, 12), Pair(0, 0), Pair(284, -53), Pair(24, 37),
        Pair(-74, -1), Pair(-5, 17), Pair(-53, 54), Pair(45, 39), Pair(53, 47), Pair(110, -25), Pair(16, 45), Pair(-4, 10),
        Pair(15, -16), Pair(-109, 47), Pair(-53, 41), Pair(-10, 25), Pair(67, 19), Pair(-61, 62), Pair(38, 34), Pair(5, -6),
        Pair(-39, 17), Pair(-39, 62), Pair(-31, 47), Pair(7, 18), Pair(-7, 39), Pair(-19, 43), Pair(0, -10), Pair(7, 59),
        Pair(41, -31), Pair(65, 7), Pair(-56, 70), Pair(-18, -9), Pair(23, -33), Pair(-4, 5), Pair(-5, 12), Pair(-57, 8),
        Pair(-39, -46), Pair(-50, -16), Pair(-37, 95), Pair(-16, 1), Pair(-63, -15), Pair(-64, 34), Pair(5, -57), Pair(77, 21)
      },
      { // Piece 2
        Pair(24, -50), Pair(122, -96), Pair(104, -61), Pair(59, 17), Pair(-41, -39), Pair(10, -29), Pair(38, 51), Pair(-20, -84),
        Pair(257, -76), Pair(61, -47), Pair(36, -65), Pair(152, -28), Pair(198, -94), Pair(104, -73), Pair(108, -42), Pair(-13, 22),
        Pair(103, -9), Pair(222, -100), Pair(101, -14), Pair(77, -64), Pair(103, 4), Pair(0, 0), Pair(116, -32), Pair(-48, -11),
        Pair(-45, -24), Pair(99, -11), Pair(46, -59), Pair(30, 15), Pair(46, -31), Pair(20, 30), Pair(19, -24), Pair(66, -18),
        Pair(-4, 19), Pair(35, -36), Pair(44, -11), Pair(27, -1), Pair(-11, 53), Pair(-16, -53), Pair(71, -5), Pair(39, -37),
        Pair(-27, -31), Pair(14, -8), Pair(0, -28), Pair(14, 9), Pair(5, -38), Pair(16, 1), Pair(45, -26), Pair(-25, 17),
        Pair(67, -39), Pair(-3, -17), Pair(88, -22), Pair(-8, -22), Pair(-8, 14), Pair(17, -66), Pair(5, 3), Pair(-8, -46),
        Pair(24, -31), Pair(14, -25), Pair(-38, -18), Pair(-20, -3), Pair(21, -40), Pair(-32, 21), Pair(146, -162), Pair(17, -112)
      },
      { // Piece 3
        Pair(42, 43), Pair(-32, 61), Pair(39, 20), Pair(-104, 89), Pair(36, 56), Pair(78, -19), Pair(10, 2), Pair(25, 42),
        Pair(34, 39), Pair(60, 12), Pair(76, 22), Pair(78, 11), Pair(55, 28), Pair(71, -90), Pair(74, 20), Pair(237, -42),
        Pair(-35, 22), Pair(95, 10), Pair(31, 2), Pair(14, 4), Pair(-12, 39), Pair(0, 0), Pair(94, -1), Pair(-108, 44),
        Pair(-14, 45), Pair(-36, 58), Pair(83, 13), Pair(3, 24), Pair(12, 24), Pair(6, -6), Pair(118, -3), Pair(29, 0),
        Pair(-3, 11), Pair(79, -7), Pair(-10, 23), Pair(56, 1), Pair(50, 4), Pair(96, -22), Pair(77, 9), Pair(74, -69),
        Pair(-18, 23), Pair(-16, 26), Pair(-46, 34), Pair(-16, 37), Pair(19, 14), Pair(54, -38), Pair(-24, 4), Pair(87, -18),
        Pair(-22, 5), Pair(17, 33), Pair(-12, 17), Pair(7, -20), Pair(7, 25), Pair(10, -23), Pair(11, 31), Pair(-158, 81),
        Pair(-3, 10), Pair(0, 2), Pair(-3, 6), Pair(-7, -6), Pair(13, -12), Pair(16, -20), Pair(-1, 15), Pair(0, 31)
      },
      { // Piece 4
        Pair(67, -14), Pair(66, -63), Pair(-129, 163), Pair(40, -12), Pair(95, -91), Pair(1, 0), Pair(55, -73), Pair(196, -127),
        Pair(-14, -46), Pair(-90, 79), Pair(133, -76), Pair(61, -98), Pair(121, 34), Pair(177, -236), Pair(-20, 72), Pair(49, -135),
        Pair(-61, 38), Pair(12, 18), Pair(38, -20), Pair(37, 49), Pair(-146, 208), Pair(0, 0), Pair(22, -55), Pair(132, 54),
        Pair(-84, -18), Pair(-57, 34), Pair(40, -74), Pair(-7, -19), Pair(-21, 84), Pair(44, -37), Pair(31, 29), Pair(146, -44),
        Pair(-68, -46), Pair(113, -103), Pair(-62, 105), Pair(-48, 63), Pair(9, -10), Pair(39, -11), Pair(35, -45), Pair(45, -70),
        Pair(-29, -44), Pair(-99, 175), Pair(41, -77), Pair(32, -119), Pair(-13, 15), Pair(18, -12), Pair(4, -71), Pair(-35, 115),
        Pair(22, -81), Pair(9, -63), Pair(-16, 13), Pair(-15, 32), Pair(-21, -39), Pair(19, -89), Pair(20, -82), Pair(55, -109),
        Pair(15, -30), Pair(14, 2), Pair(-42, -20), Pair(-28, -6), Pair(-34, 2), Pair(-10, -14), Pair(38, -128), Pair(39, 45)
      },
      { // Piece 5
        Pair(-10, 66), Pair(15, 75), Pair(1, 98), Pair(25, -15), Pair(-40, 131), Pair(57, 4), Pair(18, 192), Pair(-52, -62),
        Pair(17, -130), Pair(-69, -3), Pair(-57, -59), Pair(25, 54), Pair(89, 61), Pair(12, 20), Pair(87, 34), Pair(54, 92),
        Pair(18, 5), Pair(108, -33), Pair(47, 32), Pair(84, 18), Pair(-61, 81), Pair(0, 0), Pair(210, 8), Pair(47, 46),
        Pair(19, 22), Pair(-99, 0), Pair(40, -3), Pair(44, 30), Pair(180, 7), Pair(-36, 42), Pair(-20, 32), Pair(3, 47),
        Pair(-145, -37), Pair(17, 21), Pair(10, 24), Pair(52, 9), Pair(1, 27), Pair(62, 23), Pair(64, 3), Pair(-63, 24),
        Pair(66, 3), Pair(-80, -9), Pair(-54, 8), Pair(-10, 16), Pair(70, -13), Pair(46, 3), Pair(-26, -5), Pair(19, 7),
        Pair(-104, 46), Pair(-90, 25), Pair(32, -26), Pair(29, -8), Pair(27, -49), Pair(-21, 7), Pair(2, -20), Pair(-3, 2),
        Pair(-21, -34), Pair(-16, -57), Pair(13, -17), Pair(-100, -27), Pair(-1, -43), Pair(-43, 5), Pair(21, -31), Pair(15, -7)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(56, 8), Pair(48, 42), Pair(-206, 79), Pair(30, 35), Pair(36, 31), Pair(14, -21), Pair(196, -150), Pair(16, -38),
        Pair(-27, 2), Pair(45, 11), Pair(-26, 9), Pair(-33, 18), Pair(8, 5), Pair(0, -25), Pair(15, 30), Pair(-12, -31),
        Pair(-14, 9), Pair(13, 4), Pair(3, 16), Pair(6, 14), Pair(20, -1), Pair(-6, 3), Pair(19, -33), Pair(-19, 1),
        Pair(2, -1), Pair(-4, 12), Pair(3, 14), Pair(-5, 4), Pair(0, 13), Pair(-18, 19), Pair(-17, -10), Pair(-13, 14),
        Pair(-9, 3), Pair(-8, 6), Pair(8, 3), Pair(-12, 10), Pair(-14, 10), Pair(-5, 17), Pair(7, -6), Pair(-5, 11),
        Pair(-4, 7), Pair(-3, 14), Pair(-3, 9), Pair(4, 8), Pair(-23, 37), Pair(-13, 13), Pair(-8, -9), Pair(2, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(29, -74), Pair(14, 104), Pair(-130, 90), Pair(113, 42), Pair(48, -5), Pair(-21, 42), Pair(-32, 4), Pair(-17, -83),
        Pair(-173, -6), Pair(-151, 34), Pair(-121, 23), Pair(-15, 48), Pair(98, 9), Pair(81, 2), Pair(-1, -57), Pair(-121, -3),
        Pair(33, -61), Pair(-39, 71), Pair(-61, 38), Pair(-33, 48), Pair(170, -14), Pair(112, -20), Pair(0, 0), Pair(97, -52),
        Pair(-206, -7), Pair(-19, 19), Pair(-24, 22), Pair(74, 4), Pair(44, 16), Pair(129, 14), Pair(99, -15), Pair(86, -25),
        Pair(31, -74), Pair(-46, 7), Pair(25, -20), Pair(-23, 7), Pair(67, -19), Pair(32, 20), Pair(65, 6), Pair(5, 8),
        Pair(-49, -64), Pair(18, -62), Pair(7, -25), Pair(-40, 30), Pair(-102, 18), Pair(-7, 21), Pair(3, -35), Pair(13, 40),
        Pair(-130, 23), Pair(-96, -29), Pair(-11, -13), Pair(2, -46), Pair(-43, 25), Pair(-42, -15), Pair(-127, 42), Pair(24, -146),
        Pair(-20, 16), Pair(-16, -35), Pair(-44, -15), Pair(-64, 100), Pair(-76, 72), Pair(-73, -13), Pair(7, -4), Pair(-117, -81)
      },
      { // Piece 2
        Pair(-67, -63), Pair(75, -55), Pair(-116, -58), Pair(16, -51), Pair(10, -24), Pair(31, -97), Pair(-23, 42), Pair(28, 8),
        Pair(5, -9), Pair(43, -111), Pair(43, 9), Pair(100, -62), Pair(89, 12), Pair(105, -32), Pair(-163, -28), Pair(-38, -33),
        Pair(75, -74), Pair(177, -15), Pair(-151, -36), Pair(161, -23), Pair(160, -83), Pair(138, 22), Pair(0, 0), Pair(-3, -12),
        Pair(6, 39), Pair(22, -48), Pair(-127, 33), Pair(40, -49), Pair(36, 65), Pair(92, -38), Pair(32, -24), Pair(13, -76),
        Pair(7, -24), Pair(25, -10), Pair(32, -26), Pair(-21, 33), Pair(47, -39), Pair(-25, 37), Pair(15, -62), Pair(94, -29),
        Pair(4, 43), Pair(61, -98), Pair(43, 7), Pair(13, -37), Pair(8, 2), Pair(-29, -32), Pair(-29, 68), Pair(-9, -3),
        Pair(85, -13), Pair(3, -6), Pair(4, -41), Pair(21, -35), Pair(-6, -20), Pair(-25, 43), Pair(-10, -54), Pair(-19, -126),
        Pair(-23, -21), Pair(-65, -49), Pair(-19, 10), Pair(-20, -12), Pair(-95, -8), Pair(-56, 8), Pair(-19, -39), Pair(-58, 8)
      },
      { // Piece 3
        Pair(41, 13), Pair(86, -10), Pair(-26, 64), Pair(137, -43), Pair(151, 3), Pair(-51, 50), Pair(92, -43), Pair(-11, 15),
        Pair(35, 18), Pair(-36, 30), Pair(-45, 25), Pair(119, -49), Pair(-94, 11), Pair(54, -5), Pair(-70, -76), Pair(-18, 29),
        Pair(-46, 35), Pair(35, -11), Pair(-30, 23), Pair(23, -3), Pair(-7, 32), Pair(165, -44), Pair(0, 0), Pair(37, -13),
        Pair(-4, 18), Pair(82, 2), Pair(18, 27), Pair(-60, 51), Pair(32, -46), Pair(-28, 14), Pair(41, -3), Pair(3, -13),
        Pair(-72, 33), Pair(-172, 110), Pair(70, -1), Pair(-7, 36), Pair(-14, 33), Pair(99, -33), Pair(-5, -28), Pair(-2, -2),
        Pair(69, -70), Pair(-44, 9), Pair(26, 2), Pair(3, -23), Pair(-51, 23), Pair(-58, 46), Pair(34, -25), Pair(-28, 48),
        Pair(-38, 11), Pair(83, -45), Pair(11, -25), Pair(-22, 13), Pair(-16, 9), Pair(-27, -32), Pair(25, -19), Pair(-99, 10),
        Pair(-36, -9), Pair(-10, -6), Pair(-77, 37), Pair(-2, -4), Pair(-15, 7), Pair(25, -31), Pair(16, -16), Pair(24, -35)
      },
      { // Piece 4
        Pair(-21, -28), Pair(-156, -36), Pair(-66, -80), Pair(35, -27), Pair(-70, 33), Pair(99, 40), Pair(145, 17), Pair(-14, 60),
        Pair(-161, 235), Pair(-37, 117), Pair(66, -38), Pair(-74, 25), Pair(67, -42), Pair(-34, 8), Pair(94, -252), Pair(117, -33),
        Pair(-62, -33), Pair(-8, -142), Pair(-63, 18), Pair(52, -31), Pair(9, -2), Pair(164, -90), Pair(0, 0), Pair(57, -106),
        Pair(65, -37), Pair(42, 4), Pair(104, 57), Pair(76, -102), Pair(114, -35), Pair(-31, -46), Pair(76, -121), Pair(74, -83),
        Pair(-62, 43), Pair(-160, 198), Pair(-8, -24), Pair(-15, -9), Pair(-12, 4), Pair(-44, 52), Pair(81, -66), Pair(42, 12),
        Pair(-40, 99), Pair(-61, 140), Pair(114, -115), Pair(-1, -27), Pair(13, 6), Pair(4, -36), Pair(-10, -4), Pair(90, -109),
        Pair(103, -95), Pair(-81, 80), Pair(-17, -64), Pair(1, -144), Pair(-14, -80), Pair(-51, 15), Pair(-51, 25), Pair(-57, 9),
        Pair(-43, -162), Pair(-45, -93), Pair(-40, -92), Pair(3, -118), Pair(-20, -90), Pair(-9, -6), Pair(14, -38), Pair(76, -32)
      },
      { // Piece 5
        Pair(17, 249), Pair(49, 65), Pair(45, 257), Pair(-19, 1), Pair(5, -65), Pair(49, 85), Pair(-2, 77), Pair(-29, 65),
        Pair(7, 51), Pair(49, -22), Pair(-44, -16), Pair(35, 14), Pair(-134, 13), Pair(100, 2), Pair(-21, 28), Pair(69, 58),
        Pair(-120, -61), Pair(59, 8), Pair(125, -46), Pair(24, -9), Pair(164, -31), Pair(158, 29), Pair(0, 0), Pair(70, 42),
        Pair(46, 6), Pair(-1, 23), Pair(-42, -1), Pair(185, -27), Pair(64, 2), Pair(89, 11), Pair(-22, 40), Pair(-30, 43),
        Pair(-143, 16), Pair(-56, 4), Pair(165, -41), Pair(-17, -25), Pair(58, -4), Pair(21, 16), Pair(39, 12), Pair(50, 21),
        Pair(-130, -4), Pair(27, 0), Pair(-80, 5), Pair(-71, 1), Pair(14, -9), Pair(15, -15), Pair(59, 0), Pair(-28, 27),
        Pair(-54, -36), Pair(-84, -11), Pair(31, -19), Pair(-70, -9), Pair(-11, -15), Pair(-34, 13), Pair(26, -3), Pair(35, -31),
        Pair(39, -72), Pair(-55, 16), Pair(-76, 5), Pair(-31, -35), Pair(-9, -52), Pair(31, -15), Pair(22, -1), Pair(-6, 9)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-51, 17), Pair(54, 17), Pair(127, -29), Pair(-10, 11), Pair(-10, -5), Pair(26, -6), Pair(61, -34), Pair(41, -80),
        Pair(10, 3), Pair(14, 9), Pair(-75, 41), Pair(-20, 21), Pair(-3, 27), Pair(-45, -2), Pair(-12, -30), Pair(4, 21),
        Pair(10, 13), Pair(6, 7), Pair(-6, 11), Pair(18, -5), Pair(-1, 8), Pair(-15, 3), Pair(-13, -1), Pair(18, -32),
        Pair(1, 12), Pair(1, 12), Pair(5, 0), Pair(-4, 10), Pair(2, 4), Pair(-1, 7), Pair(5, 14), Pair(25, -5),
        Pair(6, 10), Pair(0, 7), Pair(4, 6), Pair(-8, 3), Pair(-4, 1), Pair(-11, 9), Pair(6, 6), Pair(7, -10),
        Pair(-4, 15), Pair(-1, 5), Pair(4, 5), Pair(-13, 3), Pair(6, -5), Pair(-1, 6), Pair(8, 11), Pair(0, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-2, -130), Pair(33, 108), Pair(58, 14), Pair(-167, -24), Pair(-30, 45), Pair(230, -24), Pair(23, 34), Pair(61, -29),
        Pair(50, -27), Pair(-19, 12), Pair(-39, -27), Pair(-22, 26), Pair(81, 4), Pair(-76, 18), Pair(34, 0), Pair(69, -81),
        Pair(54, -125), Pair(110, -82), Pair(6, 46), Pair(8, 4), Pair(-9, 6), Pair(66, -2), Pair(158, -9), Pair(0, 0),
        Pair(18, -40), Pair(20, -12), Pair(59, -5), Pair(75, -23), Pair(38, 15), Pair(57, -22), Pair(34, 25), Pair(47, 10),
        Pair(21, -24), Pair(10, -27), Pair(16, -1), Pair(15, -3), Pair(37, 3), Pair(25, 13), Pair(48, -23), Pair(16, -53),
        Pair(52, -66), Pair(34, -51), Pair(11, -13), Pair(29, -13), Pair(62, -20), Pair(27, -34), Pair(12, -5), Pair(-24, -33),
        Pair(36, -52), Pair(31, -30), Pair(25, -22), Pair(6, -28), Pair(25, -14), Pair(40, -26), Pair(18, 10), Pair(43, -90),
        Pair(41, -62), Pair(-18, -28), Pair(12, -28), Pair(-13, 42), Pair(21, -35), Pair(-26, -20), Pair(1, -9), Pair(-95, 9)
      },
      { // Piece 2
        Pair(133, -40), Pair(126, -90), Pair(-12, -55), Pair(93, -64), Pair(161, -24), Pair(50, -18), Pair(-57, 31), Pair(-194, -28),
        Pair(82, -73), Pair(-6, -56), Pair(-41, -33), Pair(-41, -28), Pair(-26, -38), Pair(11, 12), Pair(100, -26), Pair(-124, 5),
        Pair(48, 1), Pair(147, -56), Pair(93, -43), Pair(95, -46), Pair(100, -39), Pair(95, -55), Pair(191, -41), Pair(0, 0),
        Pair(36, -7), Pair(47, -29), Pair(-9, -27), Pair(70, -38), Pair(72, -32), Pair(-3, 2), Pair(52, -18), Pair(71, -4),
        Pair(136, -45), Pair(3, -41), Pair(69, -38), Pair(39, 4), Pair(89, -38), Pair(31, -9), Pair(28, -19), Pair(29, -41),
        Pair(-11, -36), Pair(34, -19), Pair(49, -38), Pair(32, -56), Pair(49, -30), Pair(-11, -2), Pair(13, -15), Pair(29, -45),
        Pair(11, 1), Pair(31, -11), Pair(52, -51), Pair(35, -36), Pair(7, -4), Pair(10, -29), Pair(24, -15), Pair(-56, 47),
        Pair(50, -78), Pair(1, -10), Pair(17, -24), Pair(35, -45), Pair(25, -58), Pair(11, -11), Pair(-48, -79), Pair(47, -127)
      },
      { // Piece 3
        Pair(-152, 49), Pair(90, -8), Pair(18, 27), Pair(216, -40), Pair(33, 9), Pair(17, 30), Pair(159, -17), Pair(66, -27),
        Pair(6, 11), Pair(-29, 38), Pair(-7, 20), Pair(174, -31), Pair(-69, 43), Pair(36, 9), Pair(-14, 26), Pair(181, -135),
        Pair(-46, 8), Pair(-44, 14), Pair(-26, 9), Pair(7, 10), Pair(58, -10), Pair(112, -30), Pair(115, -23), Pair(0, 0),
        Pair(14, -1), Pair(33, -22), Pair(41, -12), Pair(-75, 33), Pair(23, -16), Pair(2, 42), Pair(-89, 27), Pair(-48, -35),
        Pair(-29, 19), Pair(-28, 4), Pair(1, 5), Pair(60, -23), Pair(-38, 37), Pair(23, -39), Pair(-28, 27), Pair(-47, 10),
        Pair(-18, 8), Pair(31, -35), Pair(22, 4), Pair(59, -65), Pair(62, -35), Pair(0, -3), Pair(-17, 4), Pair(-34, -21),
        Pair(-9, 20), Pair(-44, 0), Pair(20, -42), Pair(-31, -10), Pair(-5, -24), Pair(43, -18), Pair(-24, 15), Pair(-85, 33),
        Pair(0, -22), Pair(12, -26), Pair(9, 2), Pair(-2, -2), Pair(-8, 7), Pair(-3, 8), Pair(-9, -3), Pair(-37, -39)
      },
      { // Piece 4
        Pair(-82, -46), Pair(-107, 59), Pair(72, 5), Pair(6, -83), Pair(166, -5), Pair(10, -41), Pair(143, -50), Pair(2, -52),
        Pair(5, 49), Pair(-33, -1), Pair(61, -63), Pair(-62, 16), Pair(109, -136), Pair(76, 64), Pair(-27, 94), Pair(-151, -57),
        Pair(-111, 146), Pair(41, 0), Pair(-30, -68), Pair(86, -29), Pair(56, 18), Pair(16, -40), Pair(79, -51), Pair(0, 0),
        Pair(-129, 129), Pair(-41, 45), Pair(43, -26), Pair(-67, 149), Pair(135, -138), Pair(2, -4), Pair(42, 7), Pair(46, -78),
        Pair(-32, 51), Pair(49, -98), Pair(-17, 50), Pair(19, 10), Pair(-26, 7), Pair(48, 2), Pair(13, 0), Pair(26, 4),
        Pair(66, -208), Pair(10, -64), Pair(-13, 50), Pair(-25, -13), Pair(16, -4), Pair(0, -57), Pair(-1, -71), Pair(-13, 5),
        Pair(-62, 90), Pair(-18, 27), Pair(6, -99), Pair(-3, 13), Pair(9, -109), Pair(-10, -29), Pair(-13, 31), Pair(-27, -8),
        Pair(22, -5), Pair(-37, -26), Pair(14, -14), Pair(-12, -35), Pair(-64, 67), Pair(71, -50), Pair(21, -70), Pair(-31, -68)
      },
      { // Piece 5
        Pair(-20, -72), Pair(-26, 71), Pair(23, 67), Pair(-3, -145), Pair(47, -6), Pair(-1, 54), Pair(-159, 63), Pair(90, -31),
        Pair(-29, -29), Pair(61, 83), Pair(94, -57), Pair(-25, 118), Pair(142, 1), Pair(-18, 28), Pair(21, 55), Pair(-1, -74),
        Pair(-11, 39), Pair(-14, 0), Pair(27, 25), Pair(-36, 20), Pair(29, 7), Pair(175, 6), Pair(168, 26), Pair(0, 0),
        Pair(-81, 15), Pair(-28, 20), Pair(149, -18), Pair(-124, 43), Pair(40, 6), Pair(105, 11), Pair(42, 11), Pair(138, -42),
        Pair(137, -11), Pair(-78, 30), Pair(-118, 20), Pair(22, 20), Pair(-54, 28), Pair(88, 1), Pair(90, 13), Pair(-12, 1),
        Pair(-178, 6), Pair(-31, -11), Pair(-55, 19), Pair(-77, 13), Pair(53, -5), Pair(67, 4), Pair(14, 5), Pair(12, 14),
        Pair(1, -34), Pair(-49, 6), Pair(-20, 5), Pair(-6, -10), Pair(8, -2), Pair(-14, 17), Pair(-7, 23), Pair(-23, 20),
        Pair(-31, 40), Pair(-21, 5), Pair(-18, -8), Pair(2, -24), Pair(-8, -18), Pair(-2, -13), Pair(6, 16), Pair(13, -9)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 9), Pair(-2, 37), Pair(20, 14), Pair(26, 8), Pair(25, 10), Pair(7, 31), Pair(26, 22), Pair(53, 8),
        Pair(34, -31), Pair(16, 8), Pair(-3, 10), Pair(10, 17), Pair(2, 5), Pair(-8, 14), Pair(-14, 9), Pair(11, 13),
        Pair(-4, 9), Pair(-10, -2), Pair(-4, 4), Pair(8, 6), Pair(4, 5), Pair(6, 9), Pair(0, 9), Pair(-7, 11),
        Pair(1, -11), Pair(-7, 0), Pair(3, 6), Pair(3, 8), Pair(5, 9), Pair(3, 5), Pair(3, 8), Pair(-1, 9),
        Pair(6, 14), Pair(-5, 10), Pair(-1, 12), Pair(2, 5), Pair(1, 9), Pair(5, 7), Pair(4, 11), Pair(0, 11),
        Pair(11, 9), Pair(-7, 10), Pair(-1, 6), Pair(0, -3), Pair(-1, 11), Pair(-3, 14), Pair(0, 12), Pair(-2, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(12, -19), Pair(-155, 24), Pair(6, 40), Pair(24, -7), Pair(-2, 26), Pair(-62, 27), Pair(90, 38), Pair(113, -10),
        Pair(44, 17), Pair(-13, 11), Pair(-1, 36), Pair(13, 20), Pair(61, 41), Pair(-71, 82), Pair(16, 7), Pair(55, -4),
        Pair(21, -29), Pair(-11, 18), Pair(36, 25), Pair(-14, 40), Pair(17, 26), Pair(-26, 56), Pair(-18, 21), Pair(40, -12),
        Pair(0, 0), Pair(14, 22), Pair(9, 28), Pair(32, 17), Pair(16, 30), Pair(11, 15), Pair(-6, 30), Pair(-3, 22),
        Pair(0, 78), Pair(29, 30), Pair(26, 18), Pair(9, 28), Pair(12, 24), Pair(13, 23), Pair(11, 16), Pair(17, 7),
        Pair(14, 28), Pair(2, 21), Pair(7, 16), Pair(6, 32), Pair(16, 21), Pair(8, 17), Pair(1, 18), Pair(16, -16),
        Pair(-31, 40), Pair(46, -18), Pair(-7, 13), Pair(1, 20), Pair(2, 22), Pair(2, 27), Pair(-3, 15), Pair(-21, 23),
        Pair(4, -81), Pair(-7, -14), Pair(-8, 20), Pair(35, 12), Pair(5, 28), Pair(6, 5), Pair(9, -23), Pair(87, -142)
      },
      { // Piece 2
        Pair(-149, 64), Pair(103, -33), Pair(-103, 50), Pair(-26, -18), Pair(60, 3), Pair(14, -21), Pair(118, 22), Pair(-132, -41),
        Pair(27, 4), Pair(16, 49), Pair(36, -17), Pair(-21, 15), Pair(8, -19), Pair(-5, 12), Pair(-31, -8), Pair(-48, 75),
        Pair(7, 20), Pair(19, 1), Pair(13, 24), Pair(42, -17), Pair(30, 6), Pair(41, -13), Pair(-4, 8), Pair(13, 1),
        Pair(0, 0), Pair(-12, 41), Pair(17, 0), Pair(29, 20), Pair(17, -1), Pair(8, 19), Pair(27, -16), Pair(15, 32),
        Pair(8, 48), Pair(15, 1), Pair(35, 10), Pair(19, 2), Pair(10, 43), Pair(16, 7), Pair(27, 16), Pair(-9, -7),
        Pair(-1, -18), Pair(6, 31), Pair(18, 6), Pair(6, 37), Pair(22, 9), Pair(13, 26), Pair(11, 5), Pair(14, -9),
        Pair(23, -17), Pair(6, -3), Pair(16, -10), Pair(5, 0), Pair(7, 35), Pair(17, 15), Pair(8, 30), Pair(17, 8),
        Pair(22, -39), Pair(-46, 33), Pair(-3, 12), Pair(15, 18), Pair(6, 1), Pair(-1, 33), Pair(20, 5), Pair(-26, 40)
      },
      { // Piece 3
        Pair(31, -1), Pair(-3, 49), Pair(-2, 53), Pair(-54, 69), Pair(-62, 82), Pair(41, 22), Pair(-55, 58), Pair(42, 41),
        Pair(-2, 10), Pair(16, 39), Pair(20, 43), Pair(13, 39), Pair(3, 37), Pair(-37, 51), Pair(25, 40), Pair(28, 28),
        Pair(-47, 11), Pair(17, 53), Pair(5, 58), Pair(21, 56), Pair(23, 46), Pair(38, 34), Pair(38, 12), Pair(2, 63),
        Pair(0, 0), Pair(-9, 64), Pair(10, 46), Pair(5, 47), Pair(3, 50), Pair(27, 45), Pair(34, 46), Pair(-8, 47),
        Pair(-25, 33), Pair(17, 35), Pair(22, 48), Pair(14, 37), Pair(0, 48), Pair(1, 56), Pair(-30, 60), Pair(1, 53),
        Pair(-12, 36), Pair(8, 37), Pair(8, 24), Pair(7, 49), Pair(20, 38), Pair(29, 4), Pair(5, 31), Pair(28, 25),
        Pair(-35, 21), Pair(1, 44), Pair(4, 37), Pair(20, 15), Pair(3, 39), Pair(10, 29), Pair(9, 39), Pair(-59, 23),
        Pair(-19, 9), Pair(0, 42), Pair(7, 38), Pair(3, 41), Pair(5, 33), Pair(3, 33), Pair(16, 24), Pair(27, 3)
      },
      { // Piece 4
        Pair(-13, 35), Pair(60, -1), Pair(-86, 130), Pair(-57, 94), Pair(-51, 63), Pair(95, 9), Pair(178, -38), Pair(-16, 164),
        Pair(-19, 36), Pair(19, 35), Pair(-8, 89), Pair(-24, 63), Pair(-12, 83), Pair(38, 101), Pair(73, 71), Pair(51, 24),
        Pair(-30, 17), Pair(-11, 103), Pair(-4, 58), Pair(-25, 112), Pair(35, 48), Pair(-20, 158), Pair(42, 1), Pair(-8, 93),
        Pair(0, 0), Pair(-3, 97), Pair(-14, 113), Pair(8, 87), Pair(21, 60), Pair(23, 60), Pair(45, 37), Pair(32, 45),
        Pair(-7, 70), Pair(5, 93), Pair(17, 81), Pair(17, 60), Pair(-5, 83), Pair(16, 74), Pair(40, -6), Pair(17, 31),
        Pair(10, 77), Pair(20, 57), Pair(-1, 93), Pair(1, 76), Pair(19, 76), Pair(14, 75), Pair(2, 60), Pair(65, -43),
        Pair(0, 75), Pair(19, 48), Pair(14, 53), Pair(8, 78), Pair(12, 62), Pair(31, 16), Pair(26, 2), Pair(29, -5),
        Pair(18, 7), Pair(3, 21), Pair(12, 55), Pair(17, 49), Pair(8, 61), Pair(54, -4), Pair(8, 34), Pair(-3, 93)
      },
      { // Piece 5
        Pair(-17, -37), Pair(69, 80), Pair(-32, 69), Pair(100, -25), Pair(3, 152), Pair(-16, 42), Pair(61, -30), Pair(51, 7),
        Pair(-136, 93), Pair(41, 118), Pair(-22, 73), Pair(8, 53), Pair(-32, 16), Pair(-16, 42), Pair(44, -28), Pair(116, -56),
        Pair(67, 17), Pair(123, 51), Pair(72, 60), Pair(8, 48), Pair(123, 11), Pair(80, -4), Pair(-54, 25), Pair(-39, 15),
        Pair(0, 0), Pair(51, 59), Pair(35, 60), Pair(-33, 56), Pair(127, 19), Pair(-12, 21), Pair(-19, 3), Pair(-70, 2),
        Pair(-11, -6), Pair(44, 33), Pair(-29, 57), Pair(-44, 50), Pair(-27, 42), Pair(28, 7), Pair(-35, 9), Pair(-99, 21),
        Pair(91, -10), Pair(7, 46), Pair(-1, 31), Pair(-52, 44), Pair(-61, 41), Pair(-35, 14), Pair(-14, 2), Pair(-42, -5),
        Pair(93, -29), Pair(52, 41), Pair(-23, 36), Pair(-12, 18), Pair(-25, 20), Pair(-32, 17), Pair(-16, 5), Pair(-14, -7),
        Pair(83, 6), Pair(58, 2), Pair(9, 11), Pair(-32, 23), Pair(-23, 13), Pair(-16, 3), Pair(-1, -12), Pair(-3, -11)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 35), Pair(4, -10), Pair(-52, 52), Pair(2, 11), Pair(6, 19), Pair(-14, 17), Pair(-69, 29), Pair(-30, 15),
        Pair(-10, -2), Pair(10, -33), Pair(16, 24), Pair(3, 13), Pair(7, 3), Pair(13, 6), Pair(14, 5), Pair(7, 6),
        Pair(-8, -3), Pair(-1, 15), Pair(0, 2), Pair(-3, -4), Pair(6, 5), Pair(9, 4), Pair(3, 14), Pair(4, 10),
        Pair(1, 3), Pair(7, -11), Pair(4, 3), Pair(6, 3), Pair(4, 9), Pair(11, 6), Pair(6, 7), Pair(1, 9),
        Pair(-3, 12), Pair(8, 4), Pair(-3, 6), Pair(4, 9), Pair(2, 6), Pair(3, 7), Pair(5, 11), Pair(0, 13),
        Pair(-3, 9), Pair(5, 3), Pair(-4, 11), Pair(5, -1), Pair(-3, 13), Pair(4, 10), Pair(1, 10), Pair(0, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(86, 63), Pair(88, -27), Pair(-81, 68), Pair(-5, 82), Pair(-79, 30), Pair(-232, 99), Pair(40, -77), Pair(-66, -229),
        Pair(18, 17), Pair(-2, 42), Pair(-32, 59), Pair(5, 53), Pair(31, 31), Pair(27, -21), Pair(-75, 51), Pair(-57, 30),
        Pair(14, 25), Pair(-6, 18), Pair(56, 1), Pair(19, 40), Pair(-11, 39), Pair(-23, 67), Pair(-7, 45), Pair(-16, 11),
        Pair(23, 31), Pair(0, 0), Pair(34, 42), Pair(3, 39), Pair(1, 43), Pair(-3, 36), Pair(7, 23), Pair(-15, 50),
        Pair(5, 55), Pair(22, 55), Pair(14, 45), Pair(7, 38), Pair(3, 48), Pair(12, 43), Pair(-3, 34), Pair(-1, 35),
        Pair(-16, 1), Pair(16, 31), Pair(2, 26), Pair(2, 36), Pair(8, 38), Pair(7, 26), Pair(2, 34), Pair(13, 5),
        Pair(-20, -10), Pair(16, -6), Pair(1, 26), Pair(3, 32), Pair(1, 25), Pair(-12, 21), Pair(-8, 42), Pair(-3, 33),
        Pair(-22, 11), Pair(-2, 3), Pair(-27, -7), Pair(-14, 56), Pair(6, 17), Pair(7, 28), Pair(7, -17), Pair(70, -54)
      },
      { // Piece 2
        Pair(58, 5), Pair(49, 16), Pair(24, 2), Pair(-85, 63), Pair(-50, -12), Pair(57, -8), Pair(101, -37), Pair(101, -51),
        Pair(57, 7), Pair(-9, 1), Pair(-15, 63), Pair(-51, -4), Pair(10, 6), Pair(8, -21), Pair(14, 19), Pair(20, 11),
        Pair(-12, 3), Pair(34, 2), Pair(70, -11), Pair(40, 6), Pair(52, -16), Pair(27, -5), Pair(53, -22), Pair(8, 8),
        Pair(2, 37), Pair(0, 0), Pair(6, 25), Pair(23, 1), Pair(22, 18), Pair(40, -30), Pair(-2, 35), Pair(8, 8),
        Pair(-36, -27), Pair(19, 35), Pair(13, 4), Pair(16, 27), Pair(14, 18), Pair(7, 24), Pair(28, -16), Pair(10, 17),
        Pair(3, 8), Pair(2, 10), Pair(14, 3), Pair(8, -1), Pair(6, 40), Pair(10, 14), Pair(21, 45), Pair(8, -5),
        Pair(-11, 2), Pair(9, 17), Pair(10, 1), Pair(6, 23), Pair(4, 7), Pair(22, 35), Pair(9, 10), Pair(-5, 68),
        Pair(17, 4), Pair(27, -24), Pair(-6, 17), Pair(6, -5), Pair(10, 21), Pair(-4, 17), Pair(12, 32), Pair(15, -26)
      },
      { // Piece 3
        Pair(8, 34), Pair(-50, 35), Pair(30, 23), Pair(-53, 85), Pair(-48, 64), Pair(-76, 45), Pair(2, 74), Pair(20, 31),
        Pair(1, 44), Pair(-3, 17), Pair(16, 31), Pair(10, 46), Pair(-13, 48), Pair(-55, 69), Pair(-45, 53), Pair(-52, 65),
        Pair(-17, 62), Pair(-53, 14), Pair(0, 55), Pair(-2, 57), Pair(-12, 55), Pair(-78, 89), Pair(12, 54), Pair(4, 62),
        Pair(-44, 65), Pair(0, 0), Pair(10, 51), Pair(-18, 52), Pair(12, 33), Pair(28, 46), Pair(-23, 67), Pair(1, 40),
        Pair(-22, 54), Pair(-14, 61), Pair(2, 49), Pair(8, 53), Pair(-3, 51), Pair(-10, 34), Pair(-8, 66), Pair(1, 44),
        Pair(5, 31), Pair(-20, 9), Pair(18, 27), Pair(15, 27), Pair(-4, 31), Pair(-8, 42), Pair(-17, 32), Pair(13, 13),
        Pair(10, 27), Pair(-18, 27), Pair(-5, 39), Pair(-2, 37), Pair(13, 15), Pair(2, 19), Pair(3, 40), Pair(-5, 27),
        Pair(-5, 38), Pair(-15, 27), Pair(1, 35), Pair(0, 40), Pair(-5, 36), Pair(-5, 38), Pair(2, 32), Pair(8, 20)
      },
      { // Piece 4
        Pair(14, 10), Pair(48, -41), Pair(-41, 95), Pair(-138, 113), Pair(76, -54), Pair(119, -72), Pair(13, 4), Pair(61, -51),
        Pair(15, 5), Pair(0, -1), Pair(-5, 9), Pair(-1, 74), Pair(29, 45), Pair(34, 10), Pair(49, -7), Pair(34, -32),
        Pair(-13, 6), Pair(-13, -11), Pair(19, 12), Pair(7, 56), Pair(-18, 71), Pair(0, 57), Pair(15, 21), Pair(-12, 40),
        Pair(-12, 38), Pair(0, 0), Pair(5, 38), Pair(-19, 59), Pair(-12, 51), Pair(21, 20), Pair(-2, 21), Pair(0, 83),
        Pair(-13, 48), Pair(2, 23), Pair(19, 23), Pair(16, 22), Pair(-1, 51), Pair(-15, 38), Pair(-2, 34), Pair(4, 17),
        Pair(-8, 50), Pair(11, -8), Pair(-4, 44), Pair(1, 37), Pair(10, 11), Pair(-9, 55), Pair(-5, 14), Pair(8, 18),
        Pair(12, -12), Pair(-7, 24), Pair(5, 22), Pair(-2, 44), Pair(2, 14), Pair(22, 3), Pair(-12, 42), Pair(41, -49),
        Pair(-10, 12), Pair(0, -5), Pair(8, 12), Pair(-2, 34), Pair(-21, 58), Pair(-8, 58), Pair(75, -48), Pair(59, -95)
      },
      { // Piece 5
        Pair(26, 166), Pair(37, 155), Pair(41, 171), Pair(65, 116), Pair(-8, 150), Pair(31, -13), Pair(55, -19), Pair(14, 9),
        Pair(-205, 94), Pair(-304, 142), Pair(-25, 104), Pair(62, 32), Pair(233, 20), Pair(-26, 30), Pair(72, 7), Pair(72, -4),
        Pair(148, 2), Pair(-2, 51), Pair(242, 4), Pair(-101, 73), Pair(-5, 19), Pair(28, 37), Pair(84, 5), Pair(-33, 15),
        Pair(132, 65), Pair(0, 0), Pair(126, 48), Pair(-38, 54), Pair(14, 33), Pair(-48, 22), Pair(-146, 25), Pair(-111, 10),
        Pair(76, 31), Pair(94, 23), Pair(78, 32), Pair(-76, 60), Pair(15, 22), Pair(-60, 25), Pair(16, -5), Pair(-101, 3),
        Pair(-28, 67), Pair(60, 15), Pair(31, 30), Pair(-20, 28), Pair(-6, 15), Pair(-37, 15), Pair(-33, 10), Pair(-29, 7),
        Pair(94, 1), Pair(53, 17), Pair(15, 18), Pair(9, 9), Pair(-24, 7), Pair(-41, 19), Pair(-19, 6), Pair(-12, -7),
        Pair(-17, 52), Pair(39, -7), Pair(23, -1), Pair(10, 6), Pair(-17, 0), Pair(-18, 1), Pair(0, -13), Pair(-2, -19)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(15, 1), Pair(-4, 17), Pair(-38, -3), Pair(10, 25), Pair(86, 4), Pair(-74, 45), Pair(31, 17), Pair(46, -3),
        Pair(-1, 8), Pair(14, 14), Pair(-36, -22), Pair(13, 33), Pair(13, -2), Pair(37, -4), Pair(3, 16), Pair(-6, 10),
        Pair(-5, 4), Pair(0, 3), Pair(-2, 3), Pair(5, 6), Pair(5, 0), Pair(12, 6), Pair(0, 12), Pair(3, 11),
        Pair(0, 9), Pair(7, 8), Pair(-10, -27), Pair(9, 11), Pair(4, 5), Pair(8, 7), Pair(0, 7), Pair(-1, 9),
        Pair(2, 12), Pair(-2, 8), Pair(-4, 2), Pair(-5, 12), Pair(4, 8), Pair(3, 5), Pair(0, 12), Pair(4, 7),
        Pair(2, 7), Pair(-5, 10), Pair(-3, -5), Pair(-2, 15), Pair(1, 12), Pair(2, 10), Pair(0, 8), Pair(5, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-103, 71), Pair(4, 68), Pair(50, -9), Pair(111, -3), Pair(-48, 93), Pair(220, 1), Pair(4, 26), Pair(-7, -16),
        Pair(45, 58), Pair(-4, 41), Pair(13, 32), Pair(14, 20), Pair(71, -9), Pair(32, 28), Pair(-47, 91), Pair(9, -18),
        Pair(-11, 24), Pair(-27, 23), Pair(-13, 22), Pair(48, 19), Pair(32, 13), Pair(49, 18), Pair(0, 70), Pair(-59, 25),
        Pair(-16, 51), Pair(-4, 44), Pair(0, 0), Pair(42, 52), Pair(14, 35), Pair(45, 20), Pair(1, 28), Pair(-3, 22),
        Pair(-16, 9), Pair(42, 47), Pair(25, 63), Pair(12, 56), Pair(9, 38), Pair(13, 25), Pair(32, 18), Pair(18, 11),
        Pair(4, 31), Pair(4, 24), Pair(11, 28), Pair(10, 29), Pair(2, 49), Pair(5, 24), Pair(4, 23), Pair(12, 23),
        Pair(10, -2), Pair(-1, 16), Pair(2, 20), Pair(-2, 37), Pair(6, 26), Pair(22, 11), Pair(-9, 34), Pair(6, 25),
        Pair(-5, -59), Pair(-3, 23), Pair(-12, 12), Pair(-30, 51), Pair(-2, 43), Pair(-4, 26), Pair(8, 31), Pair(70, 77)
      },
      { // Piece 2
        Pair(43, 19), Pair(34, -14), Pair(193, -7), Pair(3, -8), Pair(-50, 18), Pair(52, -34), Pair(72, 2), Pair(69, 26),
        Pair(50, 12), Pair(28, 43), Pair(-9, -1), Pair(13, 43), Pair(39, -27), Pair(65, 7), Pair(41, -38), Pair(12, 41),
        Pair(20, 14), Pair(-58, -3), Pair(11, -20), Pair(28, -18), Pair(17, 14), Pair(10, 10), Pair(48, 8), Pair(0, 14),
        Pair(-18, 9), Pair(15, 13), Pair(0, 0), Pair(23, 21), Pair(29, 2), Pair(25, 27), Pair(7, 0), Pair(0, 35),
        Pair(24, 26), Pair(-9, 5), Pair(34, 49), Pair(6, 13), Pair(3, 41), Pair(14, 12), Pair(8, 28), Pair(18, -22),
        Pair(-7, -25), Pair(16, 19), Pair(11, 0), Pair(3, 39), Pair(-2, 4), Pair(13, 30), Pair(28, 4), Pair(20, 22),
        Pair(12, -28), Pair(0, 5), Pair(19, 35), Pair(2, 2), Pair(11, 18), Pair(-5, 5), Pair(16, 29), Pair(27, 0),
        Pair(-1, 5), Pair(-6, 39), Pair(-9, -7), Pair(6, 12), Pair(10, 6), Pair(13, 15), Pair(-48, 63), Pair(20, 39)
      },
      { // Piece 3
        Pair(-8, 74), Pair(4, 40), Pair(-9, 17), Pair(-44, 52), Pair(-4, 47), Pair(-171, 80), Pair(-70, 44), Pair(114, 23),
        Pair(27, 31), Pair(8, 40), Pair(-11, 18), Pair(39, 40), Pair(24, 30), Pair(-48, 64), Pair(18, 63), Pair(35, 33),
        Pair(23, 39), Pair(32, 38), Pair(-13, 8), Pair(3, 53), Pair(39, 49), Pair(-20, 61), Pair(19, 22), Pair(63, 43),
        Pair(-10, 33), Pair(17, 29), Pair(0, 0), Pair(25, 26), Pair(-3, 45), Pair(18, 42), Pair(7, 62), Pair(46, 23),
        Pair(17, 46), Pair(21, 45), Pair(-11, 44), Pair(-2, 54), Pair(-13, 44), Pair(-16, 33), Pair(-19, 28), Pair(5, 32),
        Pair(22, 39), Pair(-18, 52), Pair(6, -4), Pair(13, 14), Pair(-4, 41), Pair(-14, 28), Pair(3, 50), Pair(52, 11),
        Pair(-6, 49), Pair(4, 27), Pair(11, 2), Pair(-2, 34), Pair(10, 23), Pair(-13, 45), Pair(12, 21), Pair(-4, 35),
        Pair(2, 33), Pair(6, 36), Pair(-4, 15), Pair(6, 21), Pair(1, 33), Pair(0, 23), Pair(7, 21), Pair(15, 6)
      },
      { // Piece 4
        Pair(29, -18), Pair(70, -36), Pair(-67, 71), Pair(9, 18), Pair(-24, 21), Pair(82, -3), Pair(106, -51), Pair(36, 10),
        Pair(3, -12), Pair(4, 26), Pair(-35, 43), Pair(23, 58), Pair(36, 15), Pair(62, -52), Pair(110, -24), Pair(10, 12),
        Pair(-34, 96), Pair(-27, 72), Pair(-13, -29), Pair(-28, 135), Pair(9, 34), Pair(-16, 85), Pair(-25, 75), Pair(-42, 65),
        Pair(-22, 68), Pair(-13, 59), Pair(0, 0), Pair(-12, 70), Pair(-15, 63), Pair(23, 18), Pair(-14, 61), Pair(-4, 8),
        Pair(-11, 63), Pair(17, 9), Pair(0, 27), Pair(8, 30), Pair(-9, 49), Pair(-13, 63), Pair(-26, 76), Pair(0, -13),
        Pair(-1, 18), Pair(1, 54), Pair(-4, 28), Pair(10, 12), Pair(-13, 58), Pair(-4, 45), Pair(-3, 62), Pair(-10, 24),
        Pair(-20, 59), Pair(-11, 33), Pair(-5, 36), Pair(-6, 51), Pair(-1, 27), Pair(-3, 30), Pair(-20, 44), Pair(77, -110),
        Pair(16, -38), Pair(-27, 68), Pair(-21, 60), Pair(-5, 31), Pair(0, 28), Pair(20, -10), Pair(5, 7), Pair(-22, 83)
      },
      { // Piece 5
        Pair(-18, 17), Pair(42, 90), Pair(45, 138), Pair(23, 124), Pair(10, -13), Pair(223, -30), Pair(-23, 27), Pair(-45, -14),
        Pair(11, -8), Pair(30, 139), Pair(166, 47), Pair(-36, 125), Pair(32, -34), Pair(-45, 54), Pair(-207, 73), Pair(-78, -15),
        Pair(58, 74), Pair(154, 26), Pair(136, 27), Pair(132, 56), Pair(-9, 75), Pair(37, 27), Pair(-5, 32), Pair(-68, 62),
        Pair(92, 56), Pair(41, 53), Pair(0, 0), Pair(151, 29), Pair(133, 7), Pair(172, -21), Pair(-26, 9), Pair(-8, -24),
        Pair(-26, 58), Pair(19, 33), Pair(6, 50), Pair(96, 18), Pair(-67, 36), Pair(-6, 2), Pair(-43, 5), Pair(-55, -1),
        Pair(3, 23), Pair(-21, 19), Pair(-40, 23), Pair(22, 16), Pair(-7, 10), Pair(-6, -5), Pair(-4, -3), Pair(-35, -1),
        Pair(35, 9), Pair(22, 4), Pair(7, -9), Pair(21, -5), Pair(-15, -6), Pair(1, -18), Pair(-10, -13), Pair(-9, -8),
        Pair(0, 6), Pair(13, -14), Pair(4, 3), Pair(6, 1), Pair(-11, -20), Pair(-16, -14), Pair(1, -23), Pair(-3, -36)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(3, 3), Pair(-5, 15), Pair(-35, 56), Pair(-30, 8), Pair(-9, 56), Pair(5, -10), Pair(31, -1), Pair(-72, 44),
        Pair(-5, 14), Pair(-12, 18), Pair(13, 26), Pair(-2, -26), Pair(7, 34), Pair(6, 10), Pair(6, 14), Pair(19, -4),
        Pair(7, 6), Pair(-2, -4), Pair(6, 6), Pair(2, -10), Pair(1, 17), Pair(-1, 2), Pair(5, 11), Pair(5, 5),
        Pair(-1, 9), Pair(1, 2), Pair(3, 8), Pair(-4, -1), Pair(9, 14), Pair(5, 5), Pair(4, 3), Pair(1, 5),
        Pair(-3, 8), Pair(4, 8), Pair(-5, 12), Pair(6, 9), Pair(0, 13), Pair(6, 9), Pair(4, 6), Pair(3, 6),
        Pair(-4, 10), Pair(0, 6), Pair(-1, 8), Pair(3, 13), Pair(-1, 24), Pair(-3, 10), Pair(1, 8), Pair(2, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(79, -17), Pair(-52, 89), Pair(30, 27), Pair(65, 55), Pair(-103, 60), Pair(-73, 26), Pair(192, -5), Pair(-104, 126),
        Pair(23, 53), Pair(-46, 70), Pair(-2, 23), Pair(-3, 79), Pair(46, 35), Pair(48, 39), Pair(-41, 88), Pair(-77, 69),
        Pair(6, -8), Pair(21, 47), Pair(45, 14), Pair(1, -15), Pair(34, 31), Pair(14, 17), Pair(6, 41), Pair(3, 33),
        Pair(37, 32), Pair(11, 40), Pair(31, 45), Pair(0, 0), Pair(21, 48), Pair(22, 40), Pair(3, 64), Pair(-1, 55),
        Pair(12, 41), Pair(7, 44), Pair(24, 42), Pair(22, 54), Pair(14, 60), Pair(6, 21), Pair(-22, 43), Pair(10, 18),
        Pair(1, 26), Pair(-2, 38), Pair(0, 27), Pair(7, 43), Pair(5, 20), Pair(6, 37), Pair(10, 24), Pair(14, 14),
        Pair(-33, 66), Pair(38, 3), Pair(5, 19), Pair(7, 54), Pair(5, 36), Pair(3, 25), Pair(-15, 55), Pair(-5, 35),
        Pair(115, -5), Pair(-2, -3), Pair(-3, 12), Pair(12, 10), Pair(-7, 42), Pair(3, 48), Pair(-3, 6), Pair(84, -100)
      },
      { // Piece 2
        Pair(-96, -69), Pair(-11, 21), Pair(210, -66), Pair(49, 4), Pair(26, -28), Pair(17, 0), Pair(-5, -34), Pair(17, 3),
        Pair(44, 6), Pair(-23, -46), Pair(48, 16), Pair(-1, -23), Pair(59, 40), Pair(48, -43), Pair(-2, 21), Pair(-53, -28),
        Pair(5, -22), Pair(21, 30), Pair(-8, -28), Pair(21, -25), Pair(37, 10), Pair(10, 24), Pair(6, -16), Pair(7, 25),
        Pair(10, 36), Pair(9, 9), Pair(12, 5), Pair(0, 0), Pair(13, 27), Pair(21, -21), Pair(11, 40), Pair(0, -1),
        Pair(26, -30), Pair(9, 28), Pair(7, -11), Pair(40, 33), Pair(-3, -2), Pair(14, 25), Pair(6, -5), Pair(9, 32),
        Pair(10, 29), Pair(-18, -8), Pair(17, 13), Pair(7, -4), Pair(10, 29), Pair(-3, -7), Pair(23, 11), Pair(21, -18),
        Pair(-4, -39), Pair(9, 24), Pair(12, -11), Pair(17, 28), Pair(1, -1), Pair(5, 17), Pair(-10, 0), Pair(8, 32),
        Pair(29, -18), Pair(11, 5), Pair(6, 31), Pair(2, -22), Pair(7, 30), Pair(-5, 5), Pair(30, -3), Pair(10, -30)
      },
      { // Piece 3
        Pair(7, 33), Pair(12, 42), Pair(-20, 55), Pair(-41, 24), Pair(-75, 69), Pair(-124, 75), Pair(-86, 68), Pair(69, 13),
        Pair(-4, 50), Pair(4, 47), Pair(5, 28), Pair(-18, 20), Pair(23, 20), Pair(13, 22), Pair(61, 9), Pair(-45, 45),
        Pair(8, 37), Pair(-8, 53), Pair(4, 42), Pair(-37, -15), Pair(23, 43), Pair(-12, 54), Pair(6, 47), Pair(13, 51),
        Pair(-4, 38), Pair(1, 37), Pair(-14, 23), Pair(0, 0), Pair(-11, 41), Pair(21, 21), Pair(43, 18), Pair(22, 26),
        Pair(-1, 34), Pair(7, 28), Pair(4, 31), Pair(43, -2), Pair(7, 32), Pair(15, 22), Pair(-5, 43), Pair(-4, 23),
        Pair(-2, 30), Pair(9, 31), Pair(3, 43), Pair(1, 14), Pair(23, 17), Pair(-6, 35), Pair(13, 38), Pair(2, 27),
        Pair(10, 26), Pair(-7, 35), Pair(3, 12), Pair(-7, 18), Pair(1, 30), Pair(-10, 22), Pair(-10, 31), Pair(1, 21),
        Pair(0, 26), Pair(5, 14), Pair(-2, 36), Pair(9, 11), Pair(1, 28), Pair(-1, 27), Pair(3, 24), Pair(5, 15)
      },
      { // Piece 4
        Pair(-89, 76), Pair(-49, 104), Pair(-27, 63), Pair(-92, 123), Pair(-84, 128), Pair(82, -27), Pair(143, -28), Pair(59, 68),
        Pair(4, 7), Pair(2, 1), Pair(30, 15), Pair(48, 7), Pair(-10, 66), Pair(15, 32), Pair(109, -90), Pair(38, 56),
        Pair(-13, 80), Pair(21, 36), Pair(-5, 38), Pair(-29, -27), Pair(-10, 48), Pair(-26, 73), Pair(-20, 74), Pair(8, -15),
        Pair(-36, 95), Pair(-8, 35), Pair(-16, 44), Pair(0, 0), Pair(-13, 76), Pair(5, 35), Pair(0, 25), Pair(5, 21),
        Pair(-10, 94), Pair(12, 42), Pair(-1, 51), Pair(12, 26), Pair(-22, 67), Pair(15, 31), Pair(4, 35), Pair(17, 15),
        Pair(47, -48), Pair(11, 27), Pair(10, 38), Pair(-1, 52), Pair(-6, 57), Pair(-4, 61), Pair(8, -5), Pair(-3, 48),
        Pair(-1, 0), Pair(7, 43), Pair(-1, 61), Pair(13, 14), Pair(-1, 47), Pair(12, 23), Pair(-24, 53), Pair(18, -20),
        Pair(12, 35), Pair(7, 6), Pair(0, 48), Pair(4, 34), Pair(-3, 33), Pair(2, 33), Pair(5, 59), Pair(-51, 58)
      },
      { // Piece 5
        Pair(-14, 35), Pair(82, 149), Pair(-7, 68), Pair(-109, 3), Pair(46, -10), Pair(81, -40), Pair(-18, 51), Pair(-22, 2),
        Pair(24, 13), Pair(142, 66), Pair(109, 74), Pair(61, 111), Pair(-129, 66), Pair(-14, 53), Pair(-19, -1), Pair(47, -65),
        Pair(-67, 36), Pair(113, 38), Pair(123, 45), Pair(-12, 19), Pair(161, 1), Pair(39, 41), Pair(71, 5), Pair(-148, 45),
        Pair(106, 33), Pair(54, 21), Pair(2, 77), Pair(0, 0), Pair(3, 63), Pair(42, 30), Pair(-70, 27), Pair(88, -17),
        Pair(-56, 34), Pair(-18, 39), Pair(-18, 41), Pair(-47, 64), Pair(-26, 29), Pair(-73, 25), Pair(-26, 2), Pair(-9, 12),
        Pair(118, 2), Pair(8, 13), Pair(9, 14), Pair(-84, 44), Pair(-37, 21), Pair(-27, 10), Pair(-2, 2), Pair(16, -17),
        Pair(16, 13), Pair(-5, 18), Pair(2, -10), Pair(-18, 9), Pair(-5, -16), Pair(-13, -3), Pair(-3, -7), Pair(2, -15),
        Pair(12, 4), Pair(-13, 0), Pair(-5, -14), Pair(-42, -16), Pair(8, -48), Pair(9, -21), Pair(1, -21), Pair(-1, -20)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(58, 12), Pair(6, 25), Pair(-22, 21), Pair(7, 27), Pair(28, 0), Pair(-18, 19), Pair(31, -26), Pair(7, 9),
        Pair(10, 3), Pair(-3, 16), Pair(1, 18), Pair(14, 38), Pair(-21, -29), Pair(27, 5), Pair(20, -1), Pair(0, 9),
        Pair(4, 6), Pair(6, 5), Pair(5, 0), Pair(0, 17), Pair(4, -11), Pair(1, 8), Pair(-14, 0), Pair(4, 8),
        Pair(-1, 10), Pair(5, 7), Pair(7, 6), Pair(11, 7), Pair(1, -2), Pair(10, 7), Pair(5, 8), Pair(0, 8),
        Pair(2, 10), Pair(7, 8), Pair(5, 7), Pair(0, 10), Pair(8, 10), Pair(-1, 10), Pair(-2, 9), Pair(-2, 7),
        Pair(-1, 9), Pair(4, 6), Pair(5, 7), Pair(-9, 23), Pair(5, 8), Pair(-6, 16), Pair(-4, 9), Pair(-3, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-31, 41), Pair(-79, 32), Pair(-22, 26), Pair(5, 20), Pair(173, 30), Pair(72, 19), Pair(-133, 82), Pair(-85, 30),
        Pair(-10, 63), Pair(-5, 53), Pair(-38, 42), Pair(81, 10), Pair(-22, 52), Pair(23, 29), Pair(12, 75), Pair(-61, 45),
        Pair(1, 57), Pair(-6, 39), Pair(20, 37), Pair(46, 31), Pair(6, 35), Pair(-34, 49), Pair(19, 27), Pair(32, 19),
        Pair(-19, 60), Pair(7, 50), Pair(8, 51), Pair(8, 53), Pair(0, 0), Pair(26, 29), Pair(15, 35), Pair(15, 32),
        Pair(6, 39), Pair(24, 28), Pair(17, 39), Pair(11, 57), Pair(21, 72), Pair(29, 48), Pair(5, 21), Pair(8, 33),
        Pair(3, 22), Pair(6, 39), Pair(0, 37), Pair(-4, 40), Pair(17, 31), Pair(1, 30), Pair(13, 16), Pair(7, 49),
        Pair(-16, -1), Pair(3, 11), Pair(7, 29), Pair(0, 36), Pair(7, 40), Pair(-8, 42), Pair(1, 39), Pair(3, 3),
        Pair(13, 12), Pair(-3, 27), Pair(0, 12), Pair(5, 24), Pair(-4, 22), Pair(-11, 44), Pair(13, 16), Pair(-14, 110)
      },
      { // Piece 2
        Pair(-29, 29), Pair(-151, 4), Pair(-60, 37), Pair(119, -38), Pair(-32, 49), Pair(87, -18), Pair(145, -28), Pair(65, -74),
        Pair(-4, -19), Pair(-6, 42), Pair(8, -26), Pair(60, 2), Pair(40, -20), Pair(-4, 37), Pair(-43, -11), Pair(19, 37),
        Pair(9, 39), Pair(6, -6), Pair(8, 35), Pair(2, -19), Pair(18, -21), Pair(-12, -2), Pair(52, 4), Pair(16, -2),
        Pair(6, -13), Pair(11, 35), Pair(11, -18), Pair(13, 33), Pair(0, 0), Pair(62, 17), Pair(14, 2), Pair(23, 25),
        Pair(15, 20), Pair(0, 1), Pair(29, 28), Pair(-7, 6), Pair(21, 49), Pair(5, -13), Pair(24, 34), Pair(-1, 14),
        Pair(4, -3), Pair(-9, 48), Pair(-8, 6), Pair(18, 33), Pair(0, 5), Pair(13, 36), Pair(-12, -7), Pair(10, 46),
        Pair(23, 11), Pair(-18, 9), Pair(22, 16), Pair(0, 3), Pair(10, 24), Pair(0, -6), Pair(8, 25), Pair(-25, -3),
        Pair(-36, -2), Pair(31, -1), Pair(-10, 8), Pair(2, 27), Pair(1, -19), Pair(2, 31), Pair(-10, 19), Pair(34, -23)
      },
      { // Piece 3
        Pair(26, 35), Pair(67, 21), Pair(-9, 41), Pair(90, 10), Pair(-160, 73), Pair(-35, 50), Pair(98, 16), Pair(20, 32),
        Pair(10, 37), Pair(15, 46), Pair(-8, 41), Pair(17, 32), Pair(-1, 27), Pair(-40, 57), Pair(-24, 40), Pair(-14, 64),
        Pair(22, 35), Pair(7, 41), Pair(-7, 49), Pair(27, 41), Pair(-33, -1), Pair(62, 34), Pair(52, 35), Pair(71, 33),
        Pair(10, 17), Pair(-1, 43), Pair(-10, 29), Pair(12, 21), Pair(0, 0), Pair(40, 3), Pair(21, 28), Pair(-5, 39),
        Pair(-5, 38), Pair(-29, 50), Pair(-11, 45), Pair(10, 39), Pair(20, 17), Pair(17, 39), Pair(14, 37), Pair(14, 35),
        Pair(5, 31), Pair(2, 33), Pair(6, 26), Pair(-2, 32), Pair(11, 8), Pair(11, 26), Pair(-5, 31), Pair(-5, 55),
        Pair(9, 21), Pair(-13, 37), Pair(7, 24), Pair(3, 24), Pair(8, 4), Pair(2, 16), Pair(-6, 23), Pair(15, 19),
        Pair(1, 23), Pair(6, 25), Pair(-2, 30), Pair(3, 24), Pair(9, 5), Pair(-2, 30), Pair(18, 15), Pair(7, 32)
      },
      { // Piece 4
        Pair(-12, 88), Pair(-7, 17), Pair(17, 76), Pair(23, 41), Pair(-79, 79), Pair(114, -86), Pair(-37, 81), Pair(66, -64),
        Pair(17, -7), Pair(32, 2), Pair(2, 0), Pair(65, 9), Pair(37, -5), Pair(40, 8), Pair(35, 9), Pair(20, 21),
        Pair(25, -14), Pair(12, 21), Pair(8, 25), Pair(-2, 59), Pair(11, -28), Pair(44, 39), Pair(4, 91), Pair(25, 75),
        Pair(3, 45), Pair(20, 7), Pair(2, 36), Pair(17, 29), Pair(0, 0), Pair(33, 2), Pair(-10, 84), Pair(24, 31),
        Pair(-3, 40), Pair(15, 9), Pair(7, 15), Pair(-14, 75), Pair(5, 46), Pair(12, 54), Pair(24, 22), Pair(8, 79),
        Pair(2, 24), Pair(15, 22), Pair(1, 49), Pair(12, 35), Pair(10, 31), Pair(17, 27), Pair(17, 16), Pair(-8, 73),
        Pair(-36, 74), Pair(7, 20), Pair(16, 23), Pair(11, 37), Pair(15, 8), Pair(12, 25), Pair(18, 14), Pair(17, -31),
        Pair(4, 9), Pair(18, -14), Pair(7, 12), Pair(7, 36), Pair(-2, 34), Pair(-2, 70), Pair(11, 25), Pair(47, -85)
      },
      { // Piece 5
        Pair(3, 63), Pair(-93, -41), Pair(3, 88), Pair(-29, 18), Pair(-102, 79), Pair(42, 89), Pair(13, 45), Pair(-57, 23),
        Pair(-65, -60), Pair(88, 34), Pair(89, -2), Pair(159, 58), Pair(68, 56), Pair(39, 84), Pair(133, 3), Pair(-56, -33),
        Pair(207, -24), Pair(-12, 31), Pair(-68, 61), Pair(-63, 40), Pair(-36, 28), Pair(68, 10), Pair(0, 31), Pair(116, 17),
        Pair(-17, 14), Pair(134, -15), Pair(-39, 38), Pair(-133, 50), Pair(0, 0), Pair(40, 24), Pair(-3, 15), Pair(29, 30),
        Pair(-165, 23), Pair(-112, 27), Pair(6, 17), Pair(-35, 25), Pair(-26, 37), Pair(-17, 14), Pair(23, -4), Pair(61, -28),
        Pair(-49, 3), Pair(-4, -9), Pair(-29, 7), Pair(-71, 18), Pair(-40, 24), Pair(-34, 4), Pair(10, -17), Pair(1, -17),
        Pair(-14, -20), Pair(-2, -21), Pair(-33, -1), Pair(-22, -6), Pair(-2, -14), Pair(-6, -18), Pair(8, -21), Pair(11, -21),
        Pair(8, -69), Pair(-11, -12), Pair(-12, -30), Pair(-47, -12), Pair(-5, -47), Pair(2, -45), Pair(8, -31), Pair(15, -47)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-27, 13), Pair(-34, 15), Pair(-5, 15), Pair(40, 25), Pair(-60, 44), Pair(-4, 6), Pair(-8, 39), Pair(14, 9),
        Pair(1, 10), Pair(-4, 14), Pair(14, 14), Pair(13, 10), Pair(23, 27), Pair(8, -19), Pair(-6, 3), Pair(-16, 3),
        Pair(5, 8), Pair(11, 5), Pair(12, 5), Pair(-1, 1), Pair(2, 9), Pair(3, -8), Pair(-17, 2), Pair(-21, 3),
        Pair(3, 6), Pair(0, 11), Pair(9, 8), Pair(2, 12), Pair(12, 4), Pair(0, -3), Pair(0, 0), Pair(2, 3),
        Pair(3, 9), Pair(6, 5), Pair(4, 5), Pair(2, 9), Pair(6, 11), Pair(6, 7), Pair(-9, 6), Pair(-2, 10),
        Pair(-1, 11), Pair(2, 7), Pair(-1, 11), Pair(-4, 15), Pair(5, 21), Pair(5, 13), Pair(-11, 11), Pair(-6, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(31, -75), Pair(143, 22), Pair(-167, 76), Pair(26, 55), Pair(161, 27), Pair(36, 34), Pair(-161, 31), Pair(51, -66),
        Pair(8, 14), Pair(35, 6), Pair(33, 19), Pair(95, 23), Pair(61, 22), Pair(100, -14), Pair(51, 35), Pair(43, 76),
        Pair(17, 29), Pair(8, 34), Pair(51, 16), Pair(25, 24), Pair(52, 14), Pair(-25, 17), Pair(11, 19), Pair(18, -12),
        Pair(-27, 33), Pair(5, 20), Pair(11, 29), Pair(21, 42), Pair(39, 30), Pair(0, 0), Pair(7, 36), Pair(7, 29),
        Pair(-20, 27), Pair(7, 58), Pair(1, 21), Pair(6, 20), Pair(37, 37), Pair(40, 33), Pair(30, 53), Pair(-2, -10),
        Pair(-5, -12), Pair(6, 6), Pair(4, 22), Pair(-6, 22), Pair(16, 23), Pair(4, 33), Pair(13, 1), Pair(6, 51),
        Pair(-23, 36), Pair(-28, 3), Pair(-22, -5), Pair(-9, 18), Pair(-8, 31), Pair(14, 3), Pair(-7, -19), Pair(-3, 32),
        Pair(-60, -2), Pair(0, -7), Pair(20, -17), Pair(-12, 12), Pair(-19, 19), Pair(-28, 36), Pair(-6, 24), Pair(4, -129)
      },
      { // Piece 2
        Pair(-75, -47), Pair(-90, 16), Pair(-88, -41), Pair(68, 1), Pair(41, -33), Pair(-100, 29), Pair(145, -48), Pair(-18, 12),
        Pair(-18, 36), Pair(-26, -8), Pair(45, -11), Pair(40, -31), Pair(47, 9), Pair(-14, -25), Pair(9, 30), Pair(-32, -21),
        Pair(7, -20), Pair(26, 25), Pair(5, -23), Pair(39, 6), Pair(43, 8), Pair(45, -16), Pair(-61, -2), Pair(25, 21),
        Pair(-4, 16), Pair(27, -25), Pair(55, 1), Pair(31, -25), Pair(15, 25), Pair(0, 0), Pair(28, 1), Pair(-6, 6),
        Pair(17, -24), Pair(16, 6), Pair(11, -11), Pair(37, 21), Pair(3, 11), Pair(16, 43), Pair(-16, -2), Pair(18, 21),
        Pair(10, 31), Pair(1, -22), Pair(12, 14), Pair(-11, -8), Pair(19, 18), Pair(6, -12), Pair(16, -8), Pair(-14, -36),
        Pair(-12, 9), Pair(10, 21), Pair(-11, -11), Pair(12, 19), Pair(-2, -13), Pair(23, 0), Pair(-9, -9), Pair(0, 45),
        Pair(5, 32), Pair(-6, -31), Pair(11, -1), Pair(-11, -12), Pair(22, 17), Pair(-6, -16), Pair(17, 40), Pair(19, -44)
      },
      { // Piece 3
        Pair(49, 30), Pair(-3, 31), Pair(41, 31), Pair(58, 24), Pair(19, 37), Pair(32, 19), Pair(182, -7), Pair(54, 32),
        Pair(4, 42), Pair(53, 19), Pair(21, 14), Pair(63, 19), Pair(34, 23), Pair(-56, 40), Pair(-14, 34), Pair(54, 17),
        Pair(22, 23), Pair(5, 29), Pair(31, 15), Pair(13, 13), Pair(48, 21), Pair(65, -38), Pair(6, 26), Pair(42, 14),
        Pair(-23, 48), Pair(21, 36), Pair(5, 30), Pair(-20, 42), Pair(3, 23), Pair(0, 0), Pair(13, -7), Pair(6, 29),
        Pair(20, 32), Pair(33, 21), Pair(17, 5), Pair(29, 8), Pair(20, 25), Pair(37, -10), Pair(40, 11), Pair(57, -1),
        Pair(-10, 52), Pair(3, 23), Pair(34, 16), Pair(11, 21), Pair(30, 6), Pair(17, -12), Pair(10, 23), Pair(39, 2),
        Pair(-39, 54), Pair(-6, 38), Pair(6, 19), Pair(0, 28), Pair(-3, 45), Pair(12, -6), Pair(18, 10), Pair(52, 4),
        Pair(10, 20), Pair(12, 8), Pair(16, 13), Pair(10, 17), Pair(13, 13), Pair(21, -16), Pair(25, 11), Pair(19, 16)
      },
      { // Piece 4
        Pair(69, 0), Pair(7, 85), Pair(20, 37), Pair(139, 7), Pair(-18, 99), Pair(84, -38), Pair(37, 27), Pair(107, -17),
        Pair(54, -18), Pair(31, 3), Pair(42, 3), Pair(124, -89), Pair(66, -11), Pair(55, -61), Pair(-2, 147), Pair(24, -25),
        Pair(-13, 26), Pair(38, 61), Pair(10, 11), Pair(6, 136), Pair(18, 15), Pair(81, -76), Pair(-26, 46), Pair(38, 11),
        Pair(-13, 51), Pair(-43, 55), Pair(40, 3), Pair(17, 23), Pair(11, 60), Pair(0, 0), Pair(14, 15), Pair(19, 8),
        Pair(2, 57), Pair(40, 8), Pair(-4, 22), Pair(20, 30), Pair(8, 32), Pair(1, 58), Pair(15, 2), Pair(41, -8),
        Pair(-17, 42), Pair(8, 18), Pair(20, -9), Pair(3, -2), Pair(24, 14), Pair(26, -27), Pair(5, 32), Pair(52, -68),
        Pair(16, -15), Pair(14, 4), Pair(6, 19), Pair(20, 23), Pair(14, 6), Pair(13, 4), Pair(16, -1), Pair(5, 54),
        Pair(15, -13), Pair(-7, 32), Pair(17, 17), Pair(8, 33), Pair(12, -4), Pair(18, -68), Pair(-34, 46), Pair(-1, -19)
      },
      { // Piece 5
        Pair(-42, -30), Pair(-116, 112), Pair(-88, -2), Pair(-24, 74), Pair(-56, 69), Pair(-12, -89), Pair(-29, 76), Pair(40, 55),
        Pair(-5, 3), Pair(-80, 48), Pair(114, 25), Pair(-6, 12), Pair(-67, 55), Pair(105, 47), Pair(-113, 109), Pair(102, 11),
        Pair(156, -29), Pair(67, -8), Pair(17, 13), Pair(-97, 39), Pair(75, 2), Pair(-23, 23), Pair(159, -4), Pair(109, 17),
        Pair(-198, -3), Pair(32, -1), Pair(-56, 27), Pair(69, 7), Pair(111, 8), Pair(0, 0), Pair(2, 19), Pair(56, 14),
        Pair(34, -7), Pair(-32, -2), Pair(-15, 4), Pair(-37, 16), Pair(41, 7), Pair(-26, 25), Pair(-4, 11), Pair(19, 8),
        Pair(-40, 0), Pair(-61, -8), Pair(-97, 23), Pair(-40, 1), Pair(-18, 13), Pair(-66, 26), Pair(-23, 3), Pair(-7, -2),
        Pair(-52, 7), Pair(-31, -12), Pair(-11, -8), Pair(-2, -13), Pair(-4, -13), Pair(-29, -1), Pair(10, -26), Pair(10, -12),
        Pair(-13, -39), Pair(-19, -7), Pair(-11, -42), Pair(-58, 2), Pair(-4, -39), Pair(-1, -25), Pair(16, -43), Pair(3, -19)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, 9), Pair(-24, 24), Pair(60, -1), Pair(42, 4), Pair(9, 21), Pair(7, 18), Pair(8, -5), Pair(-23, 34),
        Pair(-8, 13), Pair(-6, 6), Pair(-11, 17), Pair(12, 12), Pair(6, 8), Pair(-15, 13), Pair(19, -33), Pair(-14, -1),
        Pair(0, 9), Pair(4, 14), Pair(1, 12), Pair(5, 11), Pair(-14, 0), Pair(-17, 2), Pair(8, 3), Pair(-12, -6),
        Pair(-2, 10), Pair(-2, 11), Pair(-1, 6), Pair(-2, 12), Pair(2, 6), Pair(1, -3), Pair(6, -19), Pair(3, 0),
        Pair(-2, 12), Pair(4, 8), Pair(2, 7), Pair(-1, 9), Pair(7, 9), Pair(1, 5), Pair(3, -2), Pair(-3, 11),
        Pair(0, 8), Pair(3, 13), Pair(-1, 10), Pair(-3, 3), Pair(3, 15), Pair(-3, 9), Pair(5, 0), Pair(-9, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(167, -54), Pair(60, -27), Pair(-25, 20), Pair(144, -19), Pair(-20, 31), Pair(-211, 72), Pair(-5, -1), Pair(-82, 1),
        Pair(-2, -3), Pair(-18, 18), Pair(10, 27), Pair(78, 13), Pair(75, -8), Pair(112, -27), Pair(95, -9), Pair(66, -9),
        Pair(-116, 60), Pair(-29, 23), Pair(3, 27), Pair(59, 15), Pair(29, 21), Pair(9, 17), Pair(57, -30), Pair(15, -38),
        Pair(2, 13), Pair(16, 17), Pair(14, 22), Pair(26, 41), Pair(34, 27), Pair(61, 13), Pair(0, 0), Pair(41, -5),
        Pair(7, 15), Pair(-11, 10), Pair(12, 13), Pair(19, 25), Pair(44, 28), Pair(31, 21), Pair(72, 27), Pair(33, 14),
        Pair(-11, 15), Pair(-14, 21), Pair(12, 6), Pair(-1, 24), Pair(13, 33), Pair(1, 28), Pair(18, 24), Pair(-23, 19),
        Pair(46, -7), Pair(19, -12), Pair(-4, 35), Pair(-5, 18), Pair(9, 16), Pair(-6, 15), Pair(13, 11), Pair(8, 13),
        Pair(68, -26), Pair(-6, -14), Pair(-36, 19), Pair(14, 8), Pair(-10, 12), Pair(5, -2), Pair(-10, 18), Pair(27, 1)
      },
      { // Piece 2
        Pair(2, -15), Pair(-15, -29), Pair(226, -23), Pair(147, -36), Pair(225, -31), Pair(71, -46), Pair(14, 11), Pair(-136, 2),
        Pair(-34, -35), Pair(7, 15), Pair(48, -31), Pair(113, -48), Pair(113, -32), Pair(69, -12), Pair(26, -35), Pair(112, -32),
        Pair(-7, -28), Pair(29, -29), Pair(27, -4), Pair(52, -25), Pair(51, -8), Pair(45, -2), Pair(15, -4), Pair(-17, -6),
        Pair(6, -35), Pair(23, 9), Pair(10, -11), Pair(29, 13), Pair(38, -12), Pair(70, 0), Pair(0, 0), Pair(40, -6),
        Pair(-24, 2), Pair(20, -7), Pair(25, 2), Pair(35, -5), Pair(43, 17), Pair(9, 4), Pair(31, 9), Pair(-57, -16),
        Pair(18, -16), Pair(16, 0), Pair(15, -3), Pair(26, 8), Pair(13, -5), Pair(15, 1), Pair(16, -23), Pair(33, -15),
        Pair(-1, -26), Pair(16, -1), Pair(28, 6), Pair(3, -8), Pair(7, 9), Pair(10, -10), Pair(28, 1), Pair(-20, 2),
        Pair(37, -39), Pair(13, 15), Pair(6, -16), Pair(-7, 25), Pair(-22, 9), Pair(11, 5), Pair(26, -83), Pair(5, 29)
      },
      { // Piece 3
        Pair(-29, 42), Pair(12, 30), Pair(119, -16), Pair(-9, 23), Pair(182, -11), Pair(18, 45), Pair(-4, 6), Pair(-34, 36),
        Pair(-19, 38), Pair(26, 22), Pair(41, 12), Pair(25, 20), Pair(117, -29), Pair(-5, 9), Pair(31, 4), Pair(-59, 47),
        Pair(5, 28), Pair(15, 27), Pair(28, 22), Pair(68, 1), Pair(76, -9), Pair(28, 20), Pair(80, -48), Pair(26, 15),
        Pair(21, 11), Pair(27, 17), Pair(14, 7), Pair(12, 31), Pair(21, 10), Pair(4, 14), Pair(0, 0), Pair(-54, 33),
        Pair(5, 33), Pair(8, 18), Pair(17, 21), Pair(-41, 37), Pair(27, 20), Pair(7, 20), Pair(51, -24), Pair(18, 29),
        Pair(-1, 29), Pair(-48, 49), Pair(-38, 27), Pair(-11, 30), Pair(10, 20), Pair(7, 16), Pair(-24, 3), Pair(5, 18),
        Pair(-22, 20), Pair(-6, 26), Pair(1, 8), Pair(-9, 17), Pair(11, 7), Pair(13, 7), Pair(11, -30), Pair(-2, 7),
        Pair(-2, 11), Pair(-1, 9), Pair(-4, 14), Pair(-2, 13), Pair(11, 2), Pair(1, 18), Pair(11, -14), Pair(2, -5)
      },
      { // Piece 4
        Pair(43, -2), Pair(-80, 72), Pair(-124, 84), Pair(-5, 42), Pair(119, -2), Pair(-151, 43), Pair(59, -137), Pair(-8, -60),
        Pair(12, -56), Pair(8, 36), Pair(55, -40), Pair(12, -2), Pair(44, 6), Pair(15, -42), Pair(-7, -73), Pair(52, -76),
        Pair(-34, 28), Pair(35, -39), Pair(0, 50), Pair(35, 55), Pair(-25, 111), Pair(38, 8), Pair(44, -99), Pair(33, 7),
        Pair(0, 17), Pair(-34, -1), Pair(16, 10), Pair(11, 17), Pair(36, 7), Pair(27, -54), Pair(0, 0), Pair(9, -37),
        Pair(0, -31), Pair(-41, 41), Pair(-12, 40), Pair(16, 9), Pair(-14, 28), Pair(-2, 46), Pair(-8, -16), Pair(-16, 9),
        Pair(41, -102), Pair(2, -35), Pair(-7, 19), Pair(9, -12), Pair(18, -25), Pair(-7, 4), Pair(7, -19), Pair(-4, 53),
        Pair(2, -51), Pair(-9, 15), Pair(-2, 13), Pair(-3, -11), Pair(5, -25), Pair(-9, -9), Pair(-10, -35), Pair(20, 18),
        Pair(28, -32), Pair(-38, 39), Pair(-26, 14), Pair(-13, 3), Pair(-5, -23), Pair(-33, 80), Pair(-34, -14), Pair(-19, 92)
      },
      { // Piece 5
        Pair(32, -161), Pair(-93, 1), Pair(-14, -7), Pair(30, 63), Pair(57, -2), Pair(-49, 112), Pair(-23, 89), Pair(70, 40),
        Pair(-44, -50), Pair(28, -1), Pair(-154, 16), Pair(-47, -10), Pair(22, 6), Pair(29, 52), Pair(6, 96), Pair(82, 95),
        Pair(18, 16), Pair(-66, 11), Pair(-53, 29), Pair(244, -17), Pair(147, 6), Pair(122, 9), Pair(52, 45), Pair(38, 11),
        Pair(-128, 18), Pair(2, 22), Pair(17, 10), Pair(-138, 39), Pair(-33, 18), Pair(49, 11), Pair(0, 0), Pair(-34, 40),
        Pair(-189, 36), Pair(-15, 3), Pair(-16, 5), Pair(-45, 20), Pair(-28, 25), Pair(23, 4), Pair(28, 15), Pair(-56, 20),
        Pair(-49, 14), Pair(-64, -9), Pair(-23, -3), Pair(-41, 14), Pair(31, -3), Pair(-18, 12), Pair(26, 1), Pair(14, 9),
        Pair(-46, 1), Pair(-21, -13), Pair(-48, 8), Pair(-55, 1), Pair(-4, -4), Pair(5, -11), Pair(16, -5), Pair(4, -9),
        Pair(-18, -41), Pair(-26, -6), Pair(-19, -22), Pair(-53, 13), Pair(-12, -30), Pair(1, -22), Pair(12, -11), Pair(-1, -42)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(25, -3), Pair(43, -9), Pair(31, 20), Pair(50, 4), Pair(36, -19), Pair(42, -12), Pair(6, 28), Pair(12, 18),
        Pair(-10, 12), Pair(-2, 21), Pair(32, 12), Pair(-3, 16), Pair(10, 8), Pair(-13, 4), Pair(-19, 1), Pair(17, -31),
        Pair(-7, 12), Pair(4, 11), Pair(3, 9), Pair(4, 5), Pair(4, 7), Pair(-21, 3), Pair(-12, -7), Pair(0, 5),
        Pair(-1, 11), Pair(2, 14), Pair(-2, 13), Pair(4, 6), Pair(2, 5), Pair(-1, 3), Pair(-2, -7), Pair(11, -5),
        Pair(-3, 13), Pair(1, 11), Pair(1, 6), Pair(-3, 8), Pair(4, 1), Pair(3, 3), Pair(1, 7), Pair(18, 5),
        Pair(-4, 13), Pair(2, 9), Pair(-4, 8), Pair(-12, 16), Pair(-2, 6), Pair(-1, 7), Pair(-3, 8), Pair(6, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-57, 170), Pair(124, 21), Pair(164, 4), Pair(161, -31), Pair(139, -22), Pair(-114, 17), Pair(95, -8), Pair(-131, 104),
        Pair(-38, -7), Pair(-31, 3), Pair(37, -2), Pair(104, -8), Pair(-98, 31), Pair(-6, 29), Pair(-15, -18), Pair(-14, 11),
        Pair(-65, 10), Pair(23, -2), Pair(-18, 20), Pair(39, 4), Pair(-4, 19), Pair(46, 25), Pair(38, -23), Pair(53, -22),
        Pair(-1, 0), Pair(2, 6), Pair(0, -5), Pair(25, 13), Pair(42, 15), Pair(26, 14), Pair(25, 17), Pair(0, 0),
        Pair(-3, -1), Pair(-4, 27), Pair(23, -5), Pair(19, 13), Pair(23, 13), Pair(32, 13), Pair(32, 5), Pair(24, 8),
        Pair(20, -19), Pair(5, -7), Pair(7, 3), Pair(4, 6), Pair(28, 7), Pair(6, 10), Pair(16, 0), Pair(-26, 55),
        Pair(-14, 1), Pair(-34, -1), Pair(6, -15), Pair(1, 7), Pair(10, -4), Pair(19, 1), Pair(-27, 15), Pair(6, 11),
        Pair(-80, 7), Pair(-12, 5), Pair(-40, 22), Pair(-28, 11), Pair(-4, -15), Pair(-16, -7), Pair(-11, -1), Pair(3, 44)
      },
      { // Piece 2
        Pair(17, -42), Pair(-3, -7), Pair(147, -57), Pair(48, -18), Pair(41, -52), Pair(-98, 17), Pair(193, -54), Pair(-7, -7),
        Pair(84, -34), Pair(34, -35), Pair(0, -4), Pair(90, -51), Pair(15, -38), Pair(90, -38), Pair(7, 4), Pair(53, -22),
        Pair(22, -32), Pair(8, -4), Pair(10, -23), Pair(-9, 15), Pair(28, -34), Pair(33, -4), Pair(12, -33), Pair(18, 6),
        Pair(21, 10), Pair(14, -26), Pair(34, -8), Pair(35, -38), Pair(10, 22), Pair(39, -23), Pair(22, 7), Pair(0, 0),
        Pair(57, -43), Pair(16, -14), Pair(16, -15), Pair(14, 4), Pair(30, -18), Pair(17, 6), Pair(-2, -5), Pair(32, 15),
        Pair(-2, 7), Pair(22, -22), Pair(15, -1), Pair(22, -14), Pair(17, 12), Pair(17, -20), Pair(14, 12), Pair(27, -34),
        Pair(28, -37), Pair(15, -4), Pair(27, -16), Pair(9, 12), Pair(10, -17), Pair(7, 17), Pair(8, -26), Pair(22, -11),
        Pair(35, -15), Pair(30, -38), Pair(-4, 4), Pair(9, -20), Pair(-11, 0), Pair(1, -32), Pair(2, 14), Pair(28, -61)
      },
      { // Piece 3
        Pair(5, 20), Pair(44, 10), Pair(89, -7), Pair(72, -5), Pair(77, -8), Pair(110, -6), Pair(-53, 33), Pair(19, -27),
        Pair(38, -3), Pair(27, 9), Pair(3, 9), Pair(86, -6), Pair(93, -34), Pair(37, 4), Pair(23, 5), Pair(8, -13),
        Pair(-4, 25), Pair(49, -4), Pair(-3, 19), Pair(35, 2), Pair(44, -5), Pair(17, 13), Pair(7, 10), Pair(110, -61),
        Pair(5, 9), Pair(42, -1), Pair(7, 13), Pair(45, 0), Pair(20, 0), Pair(38, -1), Pair(25, 15), Pair(0, 0),
        Pair(57, -12), Pair(-10, 16), Pair(7, 19), Pair(-2, 18), Pair(10, 13), Pair(-9, 31), Pair(0, 14), Pair(-39, 2),
        Pair(10, -2), Pair(4, 6), Pair(-16, 2), Pair(-38, 2), Pair(-2, 12), Pair(1, 0), Pair(-11, 12), Pair(-56, 5),
        Pair(-7, -4), Pair(-36, 17), Pair(-14, -2), Pair(-5, -2), Pair(-13, 22), Pair(-14, 3), Pair(-50, 30), Pair(-90, 26),
        Pair(-2, -7), Pair(-1, -10), Pair(-9, 4), Pair(0, 1), Pair(2, 3), Pair(4, 0), Pair(-2, -2), Pair(-34, -18)
      },
      { // Piece 4
        Pair(-44, 48), Pair(-81, 15), Pair(18, -25), Pair(34, -32), Pair(114, -55), Pair(1, 26), Pair(-129, 23), Pair(84, -51),
        Pair(34, -67), Pair(-14, -6), Pair(-42, 14), Pair(-76, 43), Pair(-67, 77), Pair(-16, 23), Pair(52, -80), Pair(88, -134),
        Pair(-43, 47), Pair(-1, -15), Pair(9, 1), Pair(-2, 19), Pair(42, 3), Pair(68, -50), Pair(30, 26), Pair(15, -53),
        Pair(4, -41), Pair(68, -122), Pair(26, -21), Pair(-14, 28), Pair(-21, -1), Pair(32, -33), Pair(48, -61), Pair(0, 0),
        Pair(-5, -26), Pair(-24, 28), Pair(0, 8), Pair(-23, 18), Pair(5, -2), Pair(-8, 12), Pair(13, -5), Pair(2, -54),
        Pair(-9, -44), Pair(-3, 4), Pair(-11, 36), Pair(8, -7), Pair(0, -29), Pair(-6, 1), Pair(2, -20), Pair(4, -72),
        Pair(40, -69), Pair(-4, 2), Pair(-3, -15), Pair(-1, -11), Pair(-14, 7), Pair(-23, 45), Pair(15, -75), Pair(21, -91),
        Pair(3, -34), Pair(-18, 5), Pair(-47, 79), Pair(-11, -3), Pair(-10, -18), Pair(57, -99), Pair(1, -41), Pair(-25, 25)
      },
      { // Piece 5
        Pair(60, 118), Pair(64, 51), Pair(-71, -43), Pair(38, -6), Pair(138, 27), Pair(-89, 73), Pair(-31, 71), Pair(57, 82),
        Pair(67, -3), Pair(-21, -10), Pair(-27, 11), Pair(-58, -22), Pair(-43, -6), Pair(-16, 47), Pair(-98, 83), Pair(-134, 36),
        Pair(-14, -36), Pair(34, 10), Pair(-58, 2), Pair(-15, 21), Pair(176, 6), Pair(160, 5), Pair(110, 10), Pair(-47, -10),
        Pair(-61, 6), Pair(-82, 14), Pair(-171, 35), Pair(-32, 14), Pair(34, 8), Pair(29, 15), Pair(23, 4), Pair(0, 0),
        Pair(-172, 19), Pair(-33, 19), Pair(-111, 18), Pair(-1, 26), Pair(-77, 23), Pair(-1, 18), Pair(-1, -5), Pair(-59, -15),
        Pair(-64, 5), Pair(-31, 3), Pair(-52, 11), Pair(-52, 18), Pair(21, 4), Pair(2, 4), Pair(3, 4), Pair(-24, -5),
        Pair(-64, 17), Pair(-24, -5), Pair(-23, 5), Pair(-9, -6), Pair(-11, -2), Pair(-24, 9), Pair(17, -5), Pair(10, -14),
        Pair(-38, 2), Pair(-34, 3), Pair(-31, -6), Pair(-73, -12), Pair(-14, -14), Pair(6, -10), Pair(14, -14), Pair(13, -20)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(23, -1), Pair(-16, 39), Pair(13, 8), Pair(-17, 23), Pair(10, -5), Pair(3, 2), Pair(10, 18), Pair(-2, 8),
        Pair(-14, 6), Pair(-4, 22), Pair(-3, 15), Pair(1, 5), Pair(-1, 8), Pair(0, 6), Pair(0, -2), Pair(1, 13),
        Pair(0, -10), Pair(0, 3), Pair(-2, 9), Pair(-3, 9), Pair(-2, 9), Pair(4, 7), Pair(-3, 11), Pair(0, 11),
        Pair(-7, 10), Pair(-8, 3), Pair(0, 5), Pair(0, 10), Pair(0, 8), Pair(-2, 8), Pair(0, 13), Pair(-3, 10),
        Pair(3, 11), Pair(-3, 2), Pair(0, 8), Pair(-3, 12), Pair(-3, 9), Pair(-1, 10), Pair(-1, 13), Pair(1, 15),
        Pair(6, 11), Pair(-5, 8), Pair(-3, 6), Pair(0, 6), Pair(-6, 11), Pair(-5, 15), Pair(-3, 12), Pair(-2, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-35, -19), Pair(-11, -4), Pair(-75, 83), Pair(-1, 26), Pair(-19, 22), Pair(-86, 13), Pair(-26, 24), Pair(-44, 103),
        Pair(-2, 27), Pair(8, 16), Pair(6, 23), Pair(-10, 33), Pair(1, 35), Pair(1, 15), Pair(-62, 59), Pair(1, -14),
        Pair(11, 5), Pair(-29, 38), Pair(11, 35), Pair(0, 29), Pair(2, 36), Pair(-34, 42), Pair(-3, 19), Pair(13, 11),
        Pair(-6, 7), Pair(4, 28), Pair(4, 44), Pair(3, 42), Pair(3, 46), Pair(5, 29), Pair(1, 35), Pair(-16, 38),
        Pair(0, 0), Pair(12, 30), Pair(5, 39), Pair(2, 42), Pair(-5, 44), Pair(9, 38), Pair(-8, 54), Pair(0, 25),
        Pair(-3, 36), Pair(1, 31), Pair(2, 23), Pair(6, 32), Pair(3, 44), Pair(1, 32), Pair(0, 39), Pair(-1, 26),
        Pair(-22, 14), Pair(9, 19), Pair(-5, 34), Pair(-3, 35), Pair(-2, 29), Pair(-13, 50), Pair(0, 31), Pair(-2, 25),
        Pair(42, 62), Pair(-10, 7), Pair(5, 38), Pair(-12, 52), Pair(-11, 42), Pair(0, 35), Pair(-1, 12), Pair(-11, 83)
      },
      { // Piece 2
        Pair(-68, 26), Pair(53, 43), Pair(2, -12), Pair(-88, 43), Pair(8, -7), Pair(64, -12), Pair(-115, 27), Pair(-18, 27),
        Pair(-5, 19), Pair(22, 18), Pair(6, 35), Pair(64, -14), Pair(25, 19), Pair(21, -7), Pair(-36, 44), Pair(-20, 41),
        Pair(6, 9), Pair(17, 27), Pair(49, 11), Pair(13, 21), Pair(8, 12), Pair(-10, 17), Pair(14, 2), Pair(-11, 46),
        Pair(-7, 11), Pair(23, 26), Pair(-3, 35), Pair(6, 14), Pair(4, 27), Pair(9, 11), Pair(6, 29), Pair(1, 19),
        Pair(0, 0), Pair(8, 28), Pair(16, 18), Pair(15, 27), Pair(9, 26), Pair(0, 30), Pair(7, 18), Pair(3, 25),
        Pair(-3, 48), Pair(10, 10), Pair(9, 29), Pair(5, 27), Pair(4, 40), Pair(5, 31), Pair(0, 38), Pair(10, 22),
        Pair(10, -19), Pair(0, 22), Pair(1, 18), Pair(0, 36), Pair(2, 40), Pair(-3, 33), Pair(6, 27), Pair(3, 29),
        Pair(3, 7), Pair(-9, -6), Pair(-3, 22), Pair(12, 10), Pair(4, 21), Pair(0, 28), Pair(-2, 19), Pair(5, 44)
      },
      { // Piece 3
        Pair(-22, 29), Pair(-11, 62), Pair(-10, 49), Pair(-23, 51), Pair(-9, 67), Pair(5, 44), Pair(-135, 90), Pair(-11, 78),
        Pair(-40, 29), Pair(3, 52), Pair(-9, 49), Pair(-10, 56), Pair(-34, 60), Pair(-9, 45), Pair(-4, 59), Pair(-14, 50),
        Pair(-35, 45), Pair(-1, 50), Pair(3, 53), Pair(5, 54), Pair(-5, 46), Pair(3, 54), Pair(-17, 57), Pair(2, 49),
        Pair(-31, 22), Pair(-9, 66), Pair(-1, 60), Pair(-12, 60), Pair(4, 63), Pair(-9, 52), Pair(3, 55), Pair(-20, 55),
        Pair(0, 0), Pair(8, 58), Pair(8, 53), Pair(8, 48), Pair(-8, 66), Pair(2, 44), Pair(-7, 53), Pair(8, 59),
        Pair(-28, 29), Pair(-9, 55), Pair(4, 47), Pair(8, 44), Pair(-10, 57), Pair(-2, 46), Pair(-6, 68), Pair(16, 38),
        Pair(-49, 26), Pair(4, 53), Pair(-6, 56), Pair(2, 46), Pair(-4, 44), Pair(-7, 46), Pair(-6, 46), Pair(-6, 39),
        Pair(-29, 23), Pair(-8, 50), Pair(-4, 52), Pair(-6, 54), Pair(-5, 50), Pair(-5, 52), Pair(-3, 49), Pair(5, 38)
      },
      { // Piece 4
        Pair(33, 33), Pair(-21, 82), Pair(23, 86), Pair(-64, 123), Pair(-12, 80), Pair(-58, 151), Pair(-44, 106), Pair(-37, 94),
        Pair(-30, 86), Pair(-6, 66), Pair(17, 59), Pair(-27, 124), Pair(55, 39), Pair(49, 5), Pair(14, 81), Pair(-9, 94),
        Pair(6, 49), Pair(6, 66), Pair(21, 55), Pair(7, 80), Pair(-7, 89), Pair(4, 64), Pair(-13, 123), Pair(-8, 110),
        Pair(-7, 47), Pair(1, 96), Pair(-10, 108), Pair(16, 74), Pair(15, 81), Pair(18, 41), Pair(4, 71), Pair(15, 78),
        Pair(0, 0), Pair(13, 84), Pair(11, 87), Pair(16, 77), Pair(2, 101), Pair(18, 69), Pair(6, 73), Pair(20, 35),
        Pair(12, 40), Pair(13, 79), Pair(10, 88), Pair(7, 86), Pair(2, 97), Pair(15, 81), Pair(17, 66), Pair(35, 44),
        Pair(-14, 93), Pair(17, 61), Pair(11, 79), Pair(10, 82), Pair(11, 80), Pair(16, 84), Pair(15, 60), Pair(19, 64),
        Pair(-9, 66), Pair(-7, 73), Pair(8, 74), Pair(10, 79), Pair(-2, 99), Pair(10, 79), Pair(-20, 94), Pair(3, 111)
      },
      { // Piece 5
        Pair(31, 136), Pair(2, 116), Pair(-48, 1), Pair(21, 25), Pair(-111, -39), Pair(39, 33), Pair(-117, 0), Pair(-10, 32),
        Pair(-26, 1), Pair(187, 53), Pair(15, 77), Pair(32, 45), Pair(-25, -5), Pair(54, 24), Pair(89, 4), Pair(9, -50),
        Pair(-88, 47), Pair(-200, 103), Pair(85, 50), Pair(-77, 65), Pair(7, 14), Pair(-54, 22), Pair(-39, 4), Pair(-90, 29),
        Pair(45, 3), Pair(-49, 33), Pair(13, 61), Pair(23, 31), Pair(-18, 33), Pair(-41, 12), Pair(30, 13), Pair(-43, 8),
        Pair(0, 0), Pair(1, 31), Pair(-41, 41), Pair(25, 32), Pair(-59, 29), Pair(-4, 15), Pair(-45, 8), Pair(-19, -8),
        Pair(-24, -20), Pair(-43, 32), Pair(48, 12), Pair(-15, 18), Pair(-7, 15), Pair(-13, 11), Pair(-25, 4), Pair(-38, -5),
        Pair(36, -38), Pair(46, 12), Pair(5, 12), Pair(-1, 6), Pair(-14, 15), Pair(-22, 12), Pair(-14, 1), Pair(-12, -10),
        Pair(38, -52), Pair(95, -14), Pair(29, -10), Pair(4, 6), Pair(-5, -9), Pair(-7, 0), Pair(-5, -9), Pair(-8, -23)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, 30), Pair(-2, -21), Pair(-16, 23), Pair(-13, 24), Pair(34, -6), Pair(33, 20), Pair(15, 14), Pair(-6, 3),
        Pair(-7, 17), Pair(9, 7), Pair(-12, 24), Pair(11, 9), Pair(4, 10), Pair(-10, 15), Pair(-4, 12), Pair(2, 15),
        Pair(-6, 2), Pair(7, -11), Pair(7, 7), Pair(3, 5), Pair(6, 6), Pair(0, 12), Pair(-2, 11), Pair(2, 12),
        Pair(-6, 3), Pair(-5, 10), Pair(-6, 6), Pair(0, 3), Pair(1, 12), Pair(6, 10), Pair(3, 12), Pair(-1, 16),
        Pair(6, 7), Pair(0, -8), Pair(5, 11), Pair(-1, 12), Pair(-2, 12), Pair(5, 6), Pair(3, 16), Pair(1, 13),
        Pair(-4, 12), Pair(-3, 7), Pair(-1, 18), Pair(3, 12), Pair(-5, 12), Pair(2, 15), Pair(3, 16), Pair(2, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(7, 21), Pair(147, -12), Pair(167, 10), Pair(-129, 46), Pair(22, 59), Pair(-24, 24), Pair(-10, 2), Pair(34, -8),
        Pair(-4, 48), Pair(13, 18), Pair(-25, 32), Pair(38, 48), Pair(18, 34), Pair(66, 25), Pair(70, 25), Pair(-35, 42),
        Pair(12, 29), Pair(-8, 35), Pair(19, 39), Pair(17, 46), Pair(7, 43), Pair(-3, 61), Pair(-6, 44), Pair(-39, 34),
        Pair(20, 17), Pair(5, 15), Pair(24, 36), Pair(16, 45), Pair(17, 47), Pair(6, 46), Pair(4, 44), Pair(3, 47),
        Pair(-2, 50), Pair(0, 0), Pair(9, 44), Pair(17, 47), Pair(7, 39), Pair(16, 50), Pair(-6, 37), Pair(7, 42),
        Pair(6, 33), Pair(27, 53), Pair(9, 36), Pair(18, 39), Pair(18, 32), Pair(13, 42), Pair(10, 34), Pair(17, 13),
        Pair(-16, -2), Pair(30, 19), Pair(5, 41), Pair(10, 30), Pair(7, 44), Pair(22, 45), Pair(-2, 44), Pair(13, 26),
        Pair(-1, 8), Pair(5, 18), Pair(27, 24), Pair(15, 26), Pair(6, 48), Pair(-3, 49), Pair(0, 26), Pair(-51, -27)
      },
      { // Piece 2
        Pair(142, 19), Pair(64, -1), Pair(-42, 17), Pair(-13, -11), Pair(-46, 34), Pair(23, 5), Pair(-6, -25), Pair(-69, 14),
        Pair(2, 1), Pair(4, 29), Pair(8, 15), Pair(-14, 27), Pair(62, -14), Pair(32, -6), Pair(-35, 13), Pair(15, 28),
        Pair(11, 37), Pair(1, 6), Pair(2, 27), Pair(5, 5), Pair(40, 18), Pair(61, -24), Pair(18, 30), Pair(-10, 29),
        Pair(18, 1), Pair(-9, 29), Pair(22, 24), Pair(3, 22), Pair(24, 15), Pair(31, 7), Pair(0, 10), Pair(16, 33),
        Pair(22, 8), Pair(0, 0), Pair(11, 31), Pair(25, 15), Pair(12, 34), Pair(11, 10), Pair(7, 19), Pair(7, 24),
        Pair(-5, -20), Pair(27, 33), Pair(9, 15), Pair(8, 39), Pair(8, 21), Pair(20, 39), Pair(11, 29), Pair(11, 37),
        Pair(18, 3), Pair(3, 18), Pair(7, 37), Pair(5, 24), Pair(10, 42), Pair(9, 27), Pair(12, 37), Pair(-1, 32),
        Pair(5, -13), Pair(5, 28), Pair(0, 13), Pair(-3, 49), Pair(4, 27), Pair(2, 47), Pair(12, 9), Pair(6, 23)
      },
      { // Piece 3
        Pair(-37, 75), Pair(10, 27), Pair(-51, 72), Pair(-23, 62), Pair(-21, 70), Pair(-2, 68), Pair(-106, 84), Pair(-37, 64),
        Pair(-11, 63), Pair(-6, 34), Pair(-8, 59), Pair(6, 58), Pair(-2, 63), Pair(-28, 64), Pair(-3, 66), Pair(-19, 61),
        Pair(9, 59), Pair(-3, 36), Pair(5, 53), Pair(19, 58), Pair(11, 54), Pair(-10, 64), Pair(-8, 72), Pair(25, 41),
        Pair(-8, 72), Pair(-47, 36), Pair(-1, 64), Pair(-5, 62), Pair(12, 46), Pair(2, 58), Pair(-21, 76), Pair(31, 52),
        Pair(-5, 41), Pair(0, 0), Pair(0, 56), Pair(22, 59), Pair(9, 60), Pair(4, 56), Pair(16, 43), Pair(0, 43),
        Pair(2, 54), Pair(-1, 36), Pair(32, 52), Pair(7, 49), Pair(5, 63), Pair(1, 54), Pair(-13, 59), Pair(-10, 53),
        Pair(5, 54), Pair(1, 36), Pair(6, 56), Pair(9, 63), Pair(10, 48), Pair(5, 36), Pair(4, 55), Pair(26, 46),
        Pair(3, 48), Pair(-5, 27), Pair(5, 58), Pair(9, 48), Pair(10, 49), Pair(6, 54), Pair(0, 56), Pair(8, 35)
      },
      { // Piece 4
        Pair(2, 61), Pair(-55, 81), Pair(51, 12), Pair(-9, 63), Pair(-16, 51), Pair(-81, 98), Pair(-94, 97), Pair(-11, 88),
        Pair(-27, 61), Pair(-27, 48), Pair(-19, 97), Pair(6, 44), Pair(20, 37), Pair(-8, 52), Pair(32, 36), Pair(24, 58),
        Pair(-4, 92), Pair(-23, 51), Pair(10, 31), Pair(-17, 65), Pair(-4, 88), Pair(-30, 49), Pair(5, 52), Pair(5, 27),
        Pair(-21, 99), Pair(3, 35), Pair(8, 78), Pair(-12, 61), Pair(9, 58), Pair(2, 54), Pair(-26, 71), Pair(-13, 75),
        Pair(-11, 77), Pair(0, 0), Pair(12, 54), Pair(14, 47), Pair(-7, 81), Pair(8, 78), Pair(-1, 78), Pair(2, 38),
        Pair(-10, 61), Pair(14, 37), Pair(4, 71), Pair(2, 90), Pair(-7, 97), Pair(5, 73), Pair(-4, 92), Pair(28, 25),
        Pair(8, 60), Pair(9, 29), Pair(10, 50), Pair(7, 75), Pair(9, 72), Pair(2, 80), Pair(25, 50), Pair(8, 10),
        Pair(4, 71), Pair(12, -11), Pair(-4, 98), Pair(5, 71), Pair(5, 85), Pair(6, 59), Pair(-1, 98), Pair(42, 47)
      },
      { // Piece 5
        Pair(-16, -5), Pair(-46, 37), Pair(0, 100), Pair(145, 79), Pair(48, 17), Pair(17, 22), Pair(-35, -73), Pair(30, 28),
        Pair(-64, 126), Pair(-133, 109), Pair(21, 97), Pair(82, 121), Pair(47, 6), Pair(78, -10), Pair(-21, 28), Pair(85, -65),
        Pair(90, 84), Pair(79, 40), Pair(285, 42), Pair(4, 43), Pair(49, 44), Pair(56, 12), Pair(-59, 8), Pair(-77, 2),
        Pair(88, 40), Pair(40, 26), Pair(83, 26), Pair(-41, 49), Pair(29, 46), Pair(-55, 36), Pair(80, -6), Pair(44, -7),
        Pair(-65, 83), Pair(0, 0), Pair(-16, 50), Pair(-12, 40), Pair(8, 26), Pair(-34, 18), Pair(-27, 11), Pair(-84, 13),
        Pair(-24, 45), Pair(7, 20), Pair(-17, 40), Pair(2, 26), Pair(-25, 20), Pair(-18, 14), Pair(-32, 12), Pair(-53, 8),
        Pair(114, -11), Pair(43, 19), Pair(30, 23), Pair(3, 12), Pair(-16, 19), Pair(-5, 9), Pair(-11, 1), Pair(-13, -10),
        Pair(90, -69), Pair(66, -27), Pair(34, -12), Pair(-32, 9), Pair(-1, 0), Pair(1, -6), Pair(-6, -7), Pair(-7, -21)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, 12), Pair(-32, 30), Pair(-38, -1), Pair(-14, 11), Pair(17, -2), Pair(-1, 11), Pair(32, -6), Pair(-7, 10),
        Pair(-3, 14), Pair(-6, 17), Pair(-14, 2), Pair(-11, 21), Pair(15, 0), Pair(-4, 13), Pair(4, 14), Pair(5, -2),
        Pair(1, 6), Pair(2, 2), Pair(-9, -26), Pair(3, 8), Pair(5, 4), Pair(8, 7), Pair(0, 7), Pair(-4, 11),
        Pair(-1, 4), Pair(-6, 6), Pair(6, -1), Pair(-5, 17), Pair(-2, 3), Pair(5, 8), Pair(3, 8), Pair(0, 13),
        Pair(2, 5), Pair(5, 6), Pair(-10, -16), Pair(3, 12), Pair(-1, 9), Pair(4, 6), Pair(-2, 10), Pair(1, 7),
        Pair(0, 7), Pair(-1, 10), Pair(-2, -5), Pair(-2, 15), Pair(-3, 18), Pair(-1, 12), Pair(-2, 12), Pair(2, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-123, 122), Pair(-27, 27), Pair(68, -4), Pair(132, 36), Pair(-26, 43), Pair(-9, -4), Pair(-60, 39), Pair(-36, 14),
        Pair(-2, 35), Pair(24, 26), Pair(-3, 58), Pair(-50, 52), Pair(-31, 46), Pair(-29, 63), Pair(17, 18), Pair(25, 1),
        Pair(-7, 70), Pair(1, 32), Pair(-22, 52), Pair(10, 31), Pair(4, 42), Pair(-15, 68), Pair(-25, 64), Pair(-28, 27),
        Pair(-33, 30), Pair(-6, 39), Pair(-4, 24), Pair(19, 60), Pair(-10, 50), Pair(-2, 37), Pair(-6, 39), Pair(3, 28),
        Pair(-5, 31), Pair(2, 45), Pair(0, 0), Pair(-2, 37), Pair(-1, 46), Pair(6, 43), Pair(0, 51), Pair(2, 35),
        Pair(-6, 5), Pair(1, 41), Pair(7, 55), Pair(4, 35), Pair(4, 37), Pair(2, 42), Pair(8, 29), Pair(16, 17),
        Pair(-15, 15), Pair(6, 1), Pair(-4, 35), Pair(-3, 35), Pair(2, 39), Pair(6, 43), Pair(4, 41), Pair(-6, 41),
        Pair(13, 37), Pair(-3, 19), Pair(-16, 29), Pair(-13, 31), Pair(0, 37), Pair(-3, 32), Pair(1, 8), Pair(-18, -12)
      },
      { // Piece 2
        Pair(17, 4), Pair(42, 21), Pair(0, 6), Pair(-64, 36), Pair(73, -13), Pair(106, -25), Pair(-61, -9), Pair(-4, 39),
        Pair(-1, 32), Pair(13, 12), Pair(-2, 38), Pair(0, 8), Pair(24, 15), Pair(63, -28), Pair(24, 25), Pair(23, -1),
        Pair(-26, -30), Pair(14, 13), Pair(22, -10), Pair(25, 24), Pair(7, -17), Pair(28, 3), Pair(-7, 4), Pair(-4, 33),
        Pair(2, 30), Pair(-17, -7), Pair(3, 11), Pair(34, -33), Pair(6, 24), Pair(8, -7), Pair(-2, 28), Pair(5, 2),
        Pair(-11, 7), Pair(7, 38), Pair(0, 0), Pair(6, 39), Pair(-7, 19), Pair(4, 26), Pair(12, 3), Pair(6, 17),
        Pair(-8, 26), Pair(-22, -8), Pair(12, 43), Pair(-4, -4), Pair(2, 32), Pair(6, 12), Pair(2, 40), Pair(1, 16),
        Pair(-17, -31), Pair(-3, 41), Pair(-5, 7), Pair(1, 34), Pair(-4, 11), Pair(6, 24), Pair(-4, 26), Pair(-4, 38),
        Pair(9, -3), Pair(10, -6), Pair(0, 25), Pair(-4, -2), Pair(5, 21), Pair(-6, 2), Pair(-11, 36), Pair(7, -4)
      },
      { // Piece 3
        Pair(-35, 57), Pair(-48, 53), Pair(-41, 33), Pair(-36, 52), Pair(-65, 64), Pair(-20, 39), Pair(23, 38), Pair(22, 34),
        Pair(-16, 55), Pair(-14, 51), Pair(-14, 16), Pair(-12, 45), Pair(12, 40), Pair(-1, 36), Pair(-7, 43), Pair(-17, 51),
        Pair(-16, 57), Pair(-8, 48), Pair(-51, 41), Pair(-28, 48), Pair(-20, 60), Pair(-25, 54), Pair(24, 34), Pair(0, 46),
        Pair(-10, 45), Pair(4, 42), Pair(5, 11), Pair(-7, 57), Pair(0, 35), Pair(-3, 46), Pair(-7, 46), Pair(-21, 64),
        Pair(-4, 22), Pair(-13, 43), Pair(0, 0), Pair(1, 40), Pair(3, 44), Pair(8, 23), Pair(4, 31), Pair(-5, 30),
        Pair(-3, 39), Pair(4, 37), Pair(3, 11), Pair(6, 33), Pair(-11, 52), Pair(-2, 40), Pair(-15, 44), Pair(11, 33),
        Pair(-7, 25), Pair(0, 28), Pair(0, 2), Pair(-11, 52), Pair(4, 30), Pair(-12, 36), Pair(-5, 38), Pair(-34, 64),
        Pair(-4, 37), Pair(0, 40), Pair(-2, 6), Pair(-2, 35), Pair(-7, 43), Pair(-4, 36), Pair(-7, 37), Pair(-10, 42)
      },
      { // Piece 4
        Pair(-4, 53), Pair(-45, 85), Pair(33, -9), Pair(34, 34), Pair(-42, 104), Pair(19, 39), Pair(-30, 79), Pair(17, 8),
        Pair(-3, 50), Pair(7, 34), Pair(-43, 64), Pair(11, 19), Pair(30, 15), Pair(17, 53), Pair(-15, 104), Pair(15, 10),
        Pair(2, 0), Pair(-19, 65), Pair(-8, 9), Pair(-13, 59), Pair(-3, 45), Pair(1, 56), Pair(13, 46), Pair(-1, 66),
        Pair(-14, 76), Pair(-1, 31), Pair(1, 6), Pair(-14, 80), Pair(12, 47), Pair(7, 37), Pair(-11, 75), Pair(-3, 59),
        Pair(-1, 21), Pair(6, 27), Pair(0, 0), Pair(-2, 64), Pair(-3, 57), Pair(7, 58), Pair(2, 51), Pair(-1, 12),
        Pair(2, 34), Pair(8, 39), Pair(4, 49), Pair(9, 43), Pair(-1, 76), Pair(6, 61), Pair(-3, 58), Pair(5, 61),
        Pair(-8, 14), Pair(2, 51), Pair(7, 27), Pair(10, 41), Pair(7, 52), Pair(17, 24), Pair(11, 44), Pair(-21, 110),
        Pair(20, 14), Pair(13, 32), Pair(13, 11), Pair(6, 51), Pair(5, 53), Pair(6, 37), Pair(-5, 84), Pair(-13, 90)
      },
      { // Piece 5
        Pair(-8, 67), Pair(-24, 129), Pair(37, 107), Pair(91, 131), Pair(100, 22), Pair(-64, -11), Pair(-51, -83), Pair(-6, 46),
        Pair(30, 88), Pair(124, 50), Pair(-10, 97), Pair(64, 77), Pair(163, 40), Pair(-64, 46), Pair(63, 23), Pair(-152, 29),
        Pair(16, 41), Pair(25, 74), Pair(188, 20), Pair(5, 61), Pair(78, 4), Pair(65, 28), Pair(22, 10), Pair(-42, 17),
        Pair(239, 45), Pair(48, 10), Pair(80, 15), Pair(36, 31), Pair(33, 27), Pair(-15, 32), Pair(-81, 27), Pair(-26, 0),
        Pair(-109, 87), Pair(58, 25), Pair(0, 0), Pair(6, 36), Pair(-11, 32), Pair(-16, 7), Pair(-37, 12), Pair(17, -8),
        Pair(61, 12), Pair(-32, 33), Pair(15, 19), Pair(-34, 26), Pair(4, 13), Pair(6, 2), Pair(12, -4), Pair(-12, -3),
        Pair(-6, 17), Pair(-14, 22), Pair(0, 9), Pair(-9, 14), Pair(-3, 2), Pair(-8, 2), Pair(-3, 0), Pair(-9, -4),
        Pair(21, -6), Pair(18, -30), Pair(21, -24), Pair(16, -26), Pair(11, -15), Pair(-5, -7), Pair(-6, -13), Pair(-5, -19)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 12), Pair(-4, 9), Pair(12, 14), Pair(2, 9), Pair(-13, 21), Pair(-45, 26), Pair(39, -11), Pair(7, 1),
        Pair(-2, 4), Pair(1, 4), Pair(-11, 21), Pair(-5, 3), Pair(-2, 18), Pair(2, 11), Pair(-5, 4), Pair(-3, 12),
        Pair(3, 7), Pair(5, 3), Pair(10, 11), Pair(-4, -1), Pair(10, 5), Pair(0, 12), Pair(-1, 12), Pair(1, 6),
        Pair(1, 9), Pair(2, 6), Pair(-4, 16), Pair(3, -14), Pair(-1, 17), Pair(1, 2), Pair(4, 11), Pair(0, 8),
        Pair(1, 9), Pair(3, 4), Pair(8, 14), Pair(2, -1), Pair(4, 17), Pair(2, 5), Pair(3, 12), Pair(2, 8),
        Pair(1, 9), Pair(4, 7), Pair(1, 16), Pair(6, 1), Pair(1, 17), Pair(0, 12), Pair(0, 14), Pair(3, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-17, -57), Pair(-10, 78), Pair(19, 13), Pair(17, -3), Pair(-9, 44), Pair(-76, 57), Pair(-76, 69), Pair(-145, 159),
        Pair(12, 41), Pair(-15, 47), Pair(-11, 69), Pair(-27, 53), Pair(6, 38), Pair(9, 23), Pair(-40, 32), Pair(-12, 59),
        Pair(-22, 50), Pair(0, 39), Pair(-7, 37), Pair(-12, 39), Pair(9, 18), Pair(-29, 60), Pair(7, 52), Pair(8, 33),
        Pair(-9, 39), Pair(-3, 39), Pair(15, 36), Pair(-16, 23), Pair(5, 34), Pair(-5, 44), Pair(-6, 38), Pair(-18, 30),
        Pair(6, 37), Pair(17, 33), Pair(4, 39), Pair(0, 0), Pair(-7, 46), Pair(3, 48), Pair(-18, 49), Pair(6, 31),
        Pair(-1, 32), Pair(-4, 27), Pair(5, 44), Pair(16, 72), Pair(15, 41), Pair(1, 36), Pair(1, 44), Pair(6, 28),
        Pair(-5, 46), Pair(33, 17), Pair(-4, 26), Pair(7, 33), Pair(1, 34), Pair(3, 44), Pair(-2, 50), Pair(-2, 32),
        Pair(-55, 78), Pair(1, 34), Pair(4, 52), Pair(12, 26), Pair(2, 44), Pair(-1, 27), Pair(1, 35), Pair(-11, 136)
      },
      { // Piece 2
        Pair(20, 24), Pair(109, -30), Pair(21, 15), Pair(19, -26), Pair(-88, 40), Pair(33, -27), Pair(-50, 41), Pair(-12, -110),
        Pair(-16, -28), Pair(19, 28), Pair(11, -12), Pair(-22, 23), Pair(15, -5), Pair(7, 17), Pair(-90, -21), Pair(-15, 55),
        Pair(5, 16), Pair(15, -33), Pair(26, 2), Pair(8, 3), Pair(33, 4), Pair(-4, -20), Pair(3, 15), Pair(-23, 9),
        Pair(-8, -8), Pair(6, 23), Pair(-15, 1), Pair(4, 13), Pair(-5, -8), Pair(1, 15), Pair(-7, 5), Pair(2, 18),
        Pair(22, 14), Pair(3, 8), Pair(11, 24), Pair(0, 0), Pair(-2, 31), Pair(-3, 10), Pair(19, 20), Pair(1, -1),
        Pair(-4, -6), Pair(6, 18), Pair(-26, -27), Pair(14, 51), Pair(-8, -2), Pair(12, 29), Pair(-5, 18), Pair(12, 33),
        Pair(6, 35), Pair(-28, -30), Pair(12, 20), Pair(-2, 4), Pair(8, 29), Pair(-9, -6), Pair(0, 32), Pair(-2, 18),
        Pair(-31, -52), Pair(15, 24), Pair(-10, -2), Pair(15, 12), Pair(6, -5), Pair(2, 31), Pair(0, -6), Pair(-6, -6)
      },
      { // Piece 3
        Pair(8, 35), Pair(8, 38), Pair(-40, 55), Pair(16, 16), Pair(-60, 75), Pair(-14, 48), Pair(-5, 44), Pair(2, 46),
        Pair(-8, 60), Pair(-9, 49), Pair(1, 45), Pair(-20, 37), Pair(-23, 58), Pair(13, 50), Pair(6, 33), Pair(-15, 51),
        Pair(3, 52), Pair(4, 45), Pair(-13, 47), Pair(-13, 31), Pair(-32, 60), Pair(-6, 34), Pair(29, 36), Pair(7, 38),
        Pair(5, 36), Pair(8, 52), Pair(-2, 43), Pair(-1, 14), Pair(7, 44), Pair(3, 33), Pair(-25, 48), Pair(0, 53),
        Pair(-1, 25), Pair(10, 38), Pair(-11, 46), Pair(0, 0), Pair(-11, 48), Pair(-11, 34), Pair(8, 20), Pair(-10, 39),
        Pair(10, 37), Pair(2, 45), Pair(22, 31), Pair(9, 12), Pair(5, 40), Pair(-2, 28), Pair(-4, 37), Pair(10, 26),
        Pair(19, 30), Pair(-11, 56), Pair(8, 24), Pair(-4, 12), Pair(-5, 43), Pair(-4, 41), Pair(-4, 35), Pair(2, 51),
        Pair(2, 37), Pair(2, 35), Pair(-3, 42), Pair(7, 10), Pair(-4, 42), Pair(-4, 39), Pair(-2, 42), Pair(3, 29)
      },
      { // Piece 4
        Pair(53, 20), Pair(35, 31), Pair(14, -5), Pair(36, 21), Pair(5, 47), Pair(34, 66), Pair(-43, 45), Pair(-6, 53),
        Pair(-30, 59), Pair(0, 61), Pair(18, 30), Pair(25, 32), Pair(-26, 57), Pair(5, 94), Pair(-25, 73), Pair(-13, 89),
        Pair(7, 62), Pair(-11, 33), Pair(21, -4), Pair(-2, 42), Pair(2, 76), Pair(4, 52), Pair(-6, 88), Pair(3, 45),
        Pair(2, 41), Pair(-1, 50), Pair(21, 22), Pair(-9, 19), Pair(6, 55), Pair(3, 49), Pair(3, 25), Pair(13, 6),
        Pair(4, 38), Pair(13, 9), Pair(6, 1), Pair(0, 0), Pair(-13, 58), Pair(-6, 65), Pair(-14, 66), Pair(-7, 46),
        Pair(-2, 57), Pair(8, 55), Pair(0, 42), Pair(6, 45), Pair(1, 50), Pair(1, 74), Pair(2, 53), Pair(3, 62),
        Pair(19, 7), Pair(11, 19), Pair(8, 47), Pair(6, 41), Pair(5, 45), Pair(11, 31), Pair(3, 31), Pair(10, -13),
        Pair(23, 4), Pair(15, 30), Pair(7, 50), Pair(6, 34), Pair(-1, 61), Pair(-10, 84), Pair(44, -59), Pair(-21, 30)
      },
      { // Piece 5
        Pair(-43, -14), Pair(-40, 54), Pair(-91, 63), Pair(-23, 135), Pair(-38, 94), Pair(65, 121), Pair(-12, -7), Pair(50, -1),
        Pair(-107, 36), Pair(11, 73), Pair(19, 59), Pair(7, 52), Pair(39, 55), Pair(91, 70), Pair(-66, 105), Pair(0, -27),
        Pair(-204, 108), Pair(-71, 36), Pair(135, 19), Pair(68, 33), Pair(-24, 61), Pair(-128, 59), Pair(-77, 33), Pair(95, 3),
        Pair(-136, 51), Pair(-16, 30), Pair(-29, 22), Pair(20, 4), Pair(51, -5), Pair(17, 23), Pair(33, -19), Pair(-26, -4),
        Pair(2, -3), Pair(-70, 40), Pair(-17, 43), Pair(0, 0), Pair(-10, 33), Pair(-6, 9), Pair(57, -22), Pair(-96, 14),
        Pair(-30, 10), Pair(12, -1), Pair(-21, 12), Pair(-91, 45), Pair(-64, 21), Pair(15, -4), Pair(-2, -3), Pair(-18, -2),
        Pair(20, -7), Pair(5, 4), Pair(-14, 0), Pair(-58, 20), Pair(-19, -4), Pair(4, -13), Pair(-1, -10), Pair(3, -17),
        Pair(20, -25), Pair(-3, -16), Pair(-1, -22), Pair(-29, -4), Pair(9, -43), Pair(4, -17), Pair(0, -20), Pair(5, -28)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, 11), Pair(10, -5), Pair(-22, 18), Pair(-22, 18), Pair(-87, 23), Pair(-28, -15), Pair(26, 19), Pair(-10, 12),
        Pair(-1, 6), Pair(1, 3), Pair(-3, 12), Pair(-2, 14), Pair(6, -10), Pair(2, 12), Pair(-3, 10), Pair(1, 5),
        Pair(2, 6), Pair(4, 9), Pair(4, 5), Pair(8, 14), Pair(3, -1), Pair(13, 6), Pair(0, 5), Pair(1, 4),
        Pair(1, 8), Pair(2, 12), Pair(-2, 4), Pair(0, 17), Pair(-3, -11), Pair(4, 9), Pair(-3, 6), Pair(2, 8),
        Pair(1, 9), Pair(3, 11), Pair(2, 5), Pair(10, 12), Pair(1, -2), Pair(18, 10), Pair(1, 8), Pair(2, 7),
        Pair(3, 10), Pair(2, 11), Pair(2, 11), Pair(3, 16), Pair(2, 7), Pair(5, 22), Pair(2, 12), Pair(3, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-50, 80), Pair(-3, 39), Pair(-71, 83), Pair(67, 60), Pair(-3, 27), Pair(181, 11), Pair(19, -29), Pair(-31, 22),
        Pair(0, 32), Pair(-32, 36), Pair(-20, 37), Pair(16, 45), Pair(-26, 46), Pair(27, 20), Pair(-59, 61), Pair(-54, 41),
        Pair(33, 26), Pair(-15, 65), Pair(-2, 41), Pair(-8, 44), Pair(-19, 47), Pair(1, 35), Pair(-12, 53), Pair(-22, 73),
        Pair(8, 45), Pair(-2, 43), Pair(-1, 29), Pair(-1, 60), Pair(-22, 30), Pair(-3, 30), Pair(-12, 33), Pair(0, 32),
        Pair(5, 24), Pair(29, 44), Pair(13, 37), Pair(9, 39), Pair(0, 0), Pair(8, 33), Pair(-13, 36), Pair(2, 28),
        Pair(6, 35), Pair(5, 41), Pair(2, 27), Pair(7, 49), Pair(17, 59), Pair(4, 48), Pair(0, 16), Pair(-2, 32),
        Pair(23, 22), Pair(13, 14), Pair(-5, 33), Pair(2, 34), Pair(6, 30), Pair(1, 32), Pair(1, 27), Pair(-9, 57),
        Pair(40, -69), Pair(2, 53), Pair(2, 49), Pair(5, 35), Pair(2, 38), Pair(-9, 44), Pair(1, 26), Pair(-12, 20)
      },
      { // Piece 2
        Pair(-138, 2), Pair(39, 16), Pair(-2, -33), Pair(70, -10), Pair(145, -26), Pair(4, 3), Pair(-38, -11), Pair(3, -1),
        Pair(33, -10), Pair(15, -22), Pair(0, 13), Pair(21, -5), Pair(54, -14), Pair(-1, 3), Pair(-13, -3), Pair(-133, -8),
        Pair(-9, 10), Pair(15, 1), Pair(8, -20), Pair(29, 16), Pair(-19, 8), Pair(32, 5), Pair(-4, -21), Pair(-8, 26),
        Pair(14, 22), Pair(-5, 9), Pair(2, 14), Pair(17, -24), Pair(-12, 14), Pair(27, -10), Pair(3, 24), Pair(-3, -18),
        Pair(8, 3), Pair(17, 17), Pair(-4, 10), Pair(11, 16), Pair(0, 0), Pair(5, 26), Pair(-4, 4), Pair(-1, 34),
        Pair(9, 26), Pair(-3, 4), Pair(2, 31), Pair(-4, -1), Pair(10, 41), Pair(-27, -8), Pair(3, 34), Pair(-7, 7),
        Pair(16, -15), Pair(-1, 24), Pair(-9, -6), Pair(3, 26), Pair(-3, 5), Pair(6, 19), Pair(-28, -15), Pair(-18, 68),
        Pair(16, 16), Pair(-18, -34), Pair(0, 23), Pair(-3, 6), Pair(18, 6), Pair(-12, 7), Pair(10, 11), Pair(-25, -65)
      },
      { // Piece 3
        Pair(26, 36), Pair(9, 34), Pair(-20, 44), Pair(18, 47), Pair(80, 7), Pair(3, 44), Pair(114, 7), Pair(66, 18),
        Pair(-3, 49), Pair(-21, 51), Pair(-8, 49), Pair(-2, 37), Pair(9, 9), Pair(0, 28), Pair(-70, 74), Pair(45, 37),
        Pair(28, 34), Pair(17, 38), Pair(17, 39), Pair(19, 28), Pair(26, 20), Pair(-10, 26), Pair(11, 46), Pair(33, 33),
        Pair(10, 41), Pair(21, 38), Pair(-1, 51), Pair(14, 35), Pair(23, 5), Pair(14, 48), Pair(22, 23), Pair(-2, 31),
        Pair(14, 26), Pair(4, 35), Pair(-5, 41), Pair(15, 24), Pair(0, 0), Pair(-5, 31), Pair(-9, 17), Pair(8, 36),
        Pair(15, 12), Pair(-5, 53), Pair(-2, 33), Pair(0, 39), Pair(7, 4), Pair(8, 32), Pair(-11, 34), Pair(12, 12),
        Pair(7, 30), Pair(-3, 35), Pair(8, 22), Pair(2, 30), Pair(6, -10), Pair(-10, 43), Pair(-12, 32), Pair(8, 39),
        Pair(5, 34), Pair(5, 33), Pair(4, 33), Pair(4, 36), Pair(7, 7), Pair(-2, 37), Pair(10, 29), Pair(16, 27)
      },
      { // Piece 4
        Pair(-30, 71), Pair(-15, 67), Pair(21, 33), Pair(-24, 82), Pair(31, 28), Pair(-42, 58), Pair(-92, 141), Pair(-19, 90),
        Pair(-25, 94), Pair(-14, 57), Pair(11, 70), Pair(31, 12), Pair(17, 33), Pair(-13, 69), Pair(44, -3), Pair(-10, 101),
        Pair(10, 64), Pair(-12, 56), Pair(-17, 62), Pair(-9, 75), Pair(4, 35), Pair(-12, 74), Pair(-12, 38), Pair(-20, 110),
        Pair(2, 62), Pair(6, 23), Pair(-6, 73), Pair(5, 41), Pair(5, 23), Pair(15, 28), Pair(2, 81), Pair(0, 62),
        Pair(7, 1), Pair(15, 8), Pair(-3, 52), Pair(-2, 62), Pair(0, 0), Pair(-9, 52), Pair(-1, 51), Pair(-18, 83),
        Pair(5, 50), Pair(6, 75), Pair(2, 53), Pair(4, 54), Pair(7, 38), Pair(-1, 57), Pair(7, 65), Pair(-2, 53),
        Pair(-14, 68), Pair(17, 37), Pair(9, 42), Pair(11, 43), Pair(7, 44), Pair(3, 34), Pair(7, 34), Pair(28, 17),
        Pair(11, 47), Pair(3, 40), Pair(7, 58), Pair(8, 49), Pair(5, 32), Pair(-17, 120), Pair(-9, 80), Pair(49, 10)
      },
      { // Piece 5
        Pair(-47, 45), Pair(-93, -33), Pair(76, 101), Pair(-163, 103), Pair(125, 2), Pair(93, 65), Pair(25, 136), Pair(40, -130),
        Pair(49, 21), Pair(-88, 11), Pair(-32, 52), Pair(-2, 36), Pair(27, 108), Pair(7, 56), Pair(110, 26), Pair(-111, 91),
        Pair(49, 10), Pair(-29, 36), Pair(-68, 43), Pair(14, 34), Pair(57, 32), Pair(-15, 48), Pair(-20, 10), Pair(-93, 38),
        Pair(-83, 2), Pair(-107, 40), Pair(30, 0), Pair(1, -1), Pair(19, 12), Pair(-5, -3), Pair(38, -11), Pair(-20, 10),
        Pair(57, -24), Pair(-7, -7), Pair(-13, 17), Pair(-46, 30), Pair(0, 0), Pair(-39, 16), Pair(15, 8), Pair(17, -8),
        Pair(31, -16), Pair(44, -3), Pair(-15, 4), Pair(-49, 23), Pair(-68, 32), Pair(-37, 10), Pair(-1, -4), Pair(31, -14),
        Pair(4, -5), Pair(-13, -7), Pair(-13, -5), Pair(-26, 5), Pair(-52, 16), Pair(-32, 1), Pair(3, -16), Pair(12, -19),
        Pair(-4, -54), Pair(-10, -27), Pair(-7, -29), Pair(-17, -10), Pair(-5, -23), Pair(-4, -21), Pair(5, -25), Pair(10, -32)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 7), Pair(0, 10), Pair(16, 10), Pair(-2, 5), Pair(15, -10), Pair(-50, 4), Pair(-19, 22), Pair(1, 14),
        Pair(-3, 9), Pair(1, 5), Pair(2, 11), Pair(10, 8), Pair(0, 12), Pair(-9, 12), Pair(-19, 19), Pair(1, 8),
        Pair(4, 5), Pair(9, 4), Pair(7, 4), Pair(7, 9), Pair(10, 4), Pair(0, -4), Pair(-1, -5), Pair(-1, 2),
        Pair(2, 7), Pair(6, 9), Pair(6, 8), Pair(-1, 3), Pair(4, 11), Pair(-2, -4), Pair(6, -5), Pair(-1, 1),
        Pair(-1, 9), Pair(4, 9), Pair(6, 6), Pair(1, 7), Pair(16, 7), Pair(4, -1), Pair(8, 1), Pair(-1, 4),
        Pair(1, 12), Pair(6, 9), Pair(2, 8), Pair(-4, 13), Pair(12, 13), Pair(5, 7), Pair(4, 11), Pair(-2, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(72, -23), Pair(-92, 98), Pair(31, 31), Pair(97, 1), Pair(16, 22), Pair(135, -24), Pair(192, -39), Pair(-7, 35),
        Pair(17, 53), Pair(23, 7), Pair(26, 17), Pair(16, 45), Pair(39, 21), Pair(9, 35), Pair(19, 17), Pair(-6, -5),
        Pair(18, 33), Pair(10, 30), Pair(20, 37), Pair(2, 35), Pair(12, 33), Pair(-37, 51), Pair(-4, 23), Pair(-18, 50),
        Pair(-23, 39), Pair(17, 26), Pair(21, 31), Pair(6, 41), Pair(19, 25), Pair(-23, 32), Pair(-8, 22), Pair(-12, 35),
        Pair(1, 25), Pair(9, 17), Pair(17, 39), Pair(24, 27), Pair(3, 34), Pair(0, 0), Pair(-13, 45), Pair(5, 31),
        Pair(8, 41), Pair(10, 17), Pair(10, 32), Pair(9, 36), Pair(25, 42), Pair(10, 57), Pair(20, 41), Pair(-5, -10),
        Pair(10, 25), Pair(14, 11), Pair(9, 18), Pair(7, 20), Pair(-1, 38), Pair(12, 21), Pair(-4, 23), Pair(9, 27),
        Pair(-116, 57), Pair(10, 5), Pair(2, 35), Pair(16, 21), Pair(14, 17), Pair(10, 14), Pair(8, -4), Pair(24, 57)
      },
      { // Piece 2
        Pair(2, -11), Pair(-39, -18), Pair(-26, 6), Pair(99, -31), Pair(83, -8), Pair(-25, -6), Pair(38, 2), Pair(23, -13),
        Pair(21, -9), Pair(13, 0), Pair(23, -7), Pair(30, 5), Pair(45, -24), Pair(11, 15), Pair(11, -5), Pair(-4, 27),
        Pair(-5, 18), Pair(-13, -3), Pair(32, 1), Pair(30, -4), Pair(32, 7), Pair(-9, -12), Pair(-2, 24), Pair(-34, -16),
        Pair(-13, 19), Pair(28, 7), Pair(1, -1), Pair(23, 5), Pair(15, -16), Pair(0, 8), Pair(-21, 14), Pair(10, 26),
        Pair(10, 10), Pair(0, 7), Pair(22, 14), Pair(19, 11), Pair(17, 21), Pair(0, 0), Pair(3, 20), Pair(-13, 19),
        Pair(-2, 4), Pair(8, 14), Pair(-3, 13), Pair(20, 19), Pair(-1, 8), Pair(28, 32), Pair(-14, -18), Pair(10, 32),
        Pair(-10, 20), Pair(0, 6), Pair(16, 15), Pair(-9, 12), Pair(13, 19), Pair(12, 0), Pair(9, 23), Pair(-33, -27),
        Pair(10, 3), Pair(18, 9), Pair(-17, 10), Pair(8, 16), Pair(8, 10), Pair(14, 17), Pair(-9, 21), Pair(33, -36)
      },
      { // Piece 3
        Pair(52, 23), Pair(25, 21), Pair(56, 24), Pair(39, 13), Pair(2, 30), Pair(84, -11), Pair(10, 34), Pair(74, 17),
        Pair(31, 23), Pair(12, 34), Pair(15, 27), Pair(20, 21), Pair(6, 22), Pair(5, 22), Pair(40, 18), Pair(19, 28),
        Pair(20, 26), Pair(33, 19), Pair(33, 20), Pair(46, 16), Pair(17, 21), Pair(-19, 17), Pair(37, 2), Pair(-2, 25),
        Pair(4, 31), Pair(30, 24), Pair(18, 30), Pair(26, 14), Pair(20, 33), Pair(20, -5), Pair(20, 29), Pair(8, 41),
        Pair(16, 28), Pair(18, 22), Pair(1, 37), Pair(21, 21), Pair(2, 34), Pair(0, 0), Pair(-3, 30), Pair(7, 9),
        Pair(-3, 28), Pair(10, 28), Pair(-2, 27), Pair(9, 28), Pair(16, 25), Pair(6, 14), Pair(1, 25), Pair(7, 21),
        Pair(-5, 29), Pair(-1, 13), Pair(13, 21), Pair(20, 19), Pair(9, 19), Pair(1, 13), Pair(12, 24), Pair(0, 45),
        Pair(11, 24), Pair(16, 23), Pair(14, 20), Pair(16, 24), Pair(10, 21), Pair(10, -2), Pair(9, 24), Pair(8, 18)
      },
      { // Piece 4
        Pair(-21, 97), Pair(21, -7), Pair(-34, 80), Pair(13, 37), Pair(-33, 92), Pair(36, -1), Pair(-13, -7), Pair(-22, 72),
        Pair(14, 53), Pair(27, 22), Pair(25, 46), Pair(33, 28), Pair(50, 14), Pair(44, -54), Pair(-12, 105), Pair(-15, 98),
        Pair(5, 59), Pair(8, 32), Pair(15, 33), Pair(-16, 80), Pair(4, 30), Pair(-72, 72), Pair(0, 38), Pair(-15, 37),
        Pair(-4, 47), Pair(11, 47), Pair(-9, 50), Pair(-8, 83), Pair(-3, 57), Pair(6, 9), Pair(-27, 53), Pair(-2, 69),
        Pair(9, 67), Pair(11, 51), Pair(14, 33), Pair(7, 51), Pair(15, 28), Pair(0, 0), Pair(0, 43), Pair(16, -6),
        Pair(3, 32), Pair(9, 49), Pair(15, 47), Pair(12, 36), Pair(-5, 72), Pair(13, 36), Pair(-4, 43), Pair(11, 12),
        Pair(20, 33), Pair(18, 17), Pair(10, 43), Pair(9, 45), Pair(7, 54), Pair(5, 33), Pair(9, 29), Pair(35, -11),
        Pair(6, 53), Pair(-13, 95), Pair(15, 11), Pair(6, 46), Pair(4, 41), Pair(9, 22), Pair(-12, 51), Pair(17, 39)
      },
      { // Piece 5
        Pair(70, -81), Pair(-56, 10), Pair(-57, 22), Pair(68, 55), Pair(-102, 96), Pair(-61, 59), Pair(-39, 94), Pair(-29, 73),
        Pair(-69, 19), Pair(93, -13), Pair(134, -3), Pair(-36, 24), Pair(-59, 61), Pair(-48, 73), Pair(190, 34), Pair(-76, 7),
        Pair(-94, 10), Pair(-66, 27), Pair(-31, 20), Pair(-88, 49), Pair(18, 42), Pair(-51, 45), Pair(-65, 47), Pair(-72, 27),
        Pair(-89, 6), Pair(-35, 16), Pair(-29, 25), Pair(-34, 32), Pair(35, 7), Pair(61, -4), Pair(-24, 8), Pair(-10, 22),
        Pair(-90, 7), Pair(-15, 11), Pair(2, 15), Pair(9, 18), Pair(30, 5), Pair(0, 0), Pair(11, -1), Pair(-4, 25),
        Pair(32, -18), Pair(-7, 6), Pair(4, 3), Pair(5, 5), Pair(-16, 16), Pair(-31, 22), Pair(-18, 5), Pair(38, -9),
        Pair(-43, -1), Pair(-27, 7), Pair(2, -6), Pair(-25, 11), Pair(-2, 3), Pair(-63, 27), Pair(-17, 9), Pair(13, -1),
        Pair(-18, -14), Pair(-17, -10), Pair(-19, -9), Pair(-2, -24), Pair(0, -26), Pair(-16, -10), Pair(8, -27), Pair(10, -24)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-19, 20), Pair(24, -2), Pair(30, 3), Pair(12, 19), Pair(-17, 8), Pair(-29, 10), Pair(25, -17), Pair(-33, 7),
        Pair(-1, 10), Pair(5, 10), Pair(1, 11), Pair(0, 5), Pair(1, 2), Pair(-11, 15), Pair(-18, -10), Pair(4, 13),
        Pair(3, 8), Pair(6, 8), Pair(0, 7), Pair(5, 4), Pair(6, 8), Pair(1, 3), Pair(6, -19), Pair(-2, -7),
        Pair(-2, 12), Pair(3, 12), Pair(3, 8), Pair(3, 11), Pair(-3, 5), Pair(6, -4), Pair(2, 4), Pair(9, -8),
        Pair(-1, 14), Pair(2, 11), Pair(1, 11), Pair(0, 11), Pair(1, 8), Pair(15, 3), Pair(-1, -5), Pair(9, 2),
        Pair(-3, 14), Pair(2, 13), Pair(-1, 12), Pair(-1, 13), Pair(-2, 12), Pair(9, 15), Pair(4, -1), Pair(1, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-13, 67), Pair(57, 16), Pair(-56, 39), Pair(38, 8), Pair(21, 36), Pair(-26, -2), Pair(-50, 48), Pair(70, -53),
        Pair(-14, 48), Pair(-44, 24), Pair(13, 17), Pair(46, 15), Pair(74, 12), Pair(51, 5), Pair(-30, 8), Pair(0, 37),
        Pair(-16, 41), Pair(8, 15), Pair(7, 23), Pair(22, 24), Pair(31, 15), Pair(25, 18), Pair(19, 13), Pair(31, -2),
        Pair(-4, 27), Pair(13, 17), Pair(7, 33), Pair(24, 25), Pair(18, 29), Pair(26, 14), Pair(8, 14), Pair(-25, -10),
        Pair(-11, 39), Pair(15, 20), Pair(6, 27), Pair(16, 32), Pair(22, 29), Pair(22, 22), Pair(0, 0), Pair(8, 36),
        Pair(-13, 47), Pair(13, 17), Pair(5, 32), Pair(12, 34), Pair(18, 23), Pair(11, 36), Pair(17, 37), Pair(22, 42),
        Pair(-24, 1), Pair(-19, 17), Pair(4, 18), Pair(3, 38), Pair(1, 29), Pair(0, 32), Pair(-2, 18), Pair(3, -1),
        Pair(16, -19), Pair(-12, -1), Pair(-5, 17), Pair(-9, 24), Pair(-2, 29), Pair(3, 16), Pair(1, 8), Pair(-90, 134)
      },
      { // Piece 2
        Pair(-55, -23), Pair(2, -6), Pair(8, -3), Pair(43, -3), Pair(-31, -9), Pair(17, -4), Pair(230, -23), Pair(-45, 47),
        Pair(-4, 9), Pair(4, -2), Pair(-4, 7), Pair(30, -21), Pair(29, 3), Pair(-7, -10), Pair(8, 18), Pair(33, 7),
        Pair(-16, 4), Pair(35, -2), Pair(47, -18), Pair(46, -6), Pair(32, -12), Pair(69, -2), Pair(-16, 7), Pair(8, 14),
        Pair(18, 2), Pair(12, 1), Pair(4, 11), Pair(18, 0), Pair(1, 21), Pair(45, -15), Pair(3, 2), Pair(-54, -5),
        Pair(21, -7), Pair(5, 15), Pair(15, -5), Pair(12, 20), Pair(19, 9), Pair(7, 20), Pair(0, 0), Pair(15, 9),
        Pair(-2, 24), Pair(-2, 3), Pair(8, 16), Pair(13, 12), Pair(13, 21), Pair(7, 4), Pair(19, 20), Pair(-17, -49),
        Pair(5, -1), Pair(6, 19), Pair(7, 17), Pair(11, 15), Pair(-5, 9), Pair(20, -3), Pair(9, 0), Pair(0, 12),
        Pair(18, 3), Pair(27, -16), Pair(6, 24), Pair(-26, 14), Pair(21, 12), Pair(-5, 9), Pair(-15, 24), Pair(14, -25)
      },
      { // Piece 3
        Pair(14, 27), Pair(77, 6), Pair(83, 7), Pair(102, -7), Pair(-11, 40), Pair(-34, 46), Pair(113, -8), Pair(29, 23),
        Pair(34, 17), Pair(-1, 30), Pair(24, 12), Pair(16, 18), Pair(52, 15), Pair(39, 15), Pair(41, 6), Pair(0, 19),
        Pair(-20, 38), Pair(13, 20), Pair(21, 20), Pair(20, 13), Pair(18, 16), Pair(12, 22), Pair(40, -6), Pair(-9, 26),
        Pair(-5, 36), Pair(27, 21), Pair(0, 24), Pair(43, 10), Pair(17, 28), Pair(-9, 43), Pair(39, -10), Pair(-7, 40),
        Pair(11, 28), Pair(0, 24), Pair(9, 23), Pair(39, 10), Pair(18, 20), Pair(14, 26), Pair(0, 0), Pair(-42, 11),
        Pair(1, 25), Pair(4, 28), Pair(0, 22), Pair(17, 9), Pair(3, 17), Pair(6, 14), Pair(-6, -14), Pair(-12, 17),
        Pair(0, 16), Pair(-6, 27), Pair(-7, 16), Pair(9, 21), Pair(18, 17), Pair(8, 14), Pair(-5, -14), Pair(1, 14),
        Pair(6, 20), Pair(12, 20), Pair(10, 14), Pair(12, 15), Pair(10, 16), Pair(6, 23), Pair(6, -25), Pair(0, 8)
      },
      { // Piece 4
        Pair(-3, 17), Pair(20, 30), Pair(19, 25), Pair(69, 4), Pair(-49, 58), Pair(95, 2), Pair(36, -4), Pair(88, -56),
        Pair(-5, 36), Pair(-2, 24), Pair(20, 20), Pair(-13, 52), Pair(11, 45), Pair(61, -27), Pair(37, -55), Pair(25, 14),
        Pair(-32, 48), Pair(-31, 51), Pair(13, -2), Pair(9, 17), Pair(37, -16), Pair(34, -10), Pair(26, -23), Pair(9, -12),
        Pair(-1, -8), Pair(-15, 23), Pair(19, 33), Pair(30, -9), Pair(2, 24), Pair(-14, 35), Pair(15, 12), Pair(8, -31),
        Pair(17, -32), Pair(15, -18), Pair(15, 9), Pair(12, 21), Pair(23, 0), Pair(-19, 47), Pair(0, 0), Pair(-2, 7),
        Pair(-9, 20), Pair(16, 12), Pair(7, 38), Pair(4, 29), Pair(11, 31), Pair(9, 2), Pair(3, 30), Pair(16, -53),
        Pair(12, 6), Pair(-5, 20), Pair(12, 26), Pair(10, 24), Pair(8, 9), Pair(-2, 15), Pair(-6, 2), Pair(-5, 68),
        Pair(-8, 50), Pair(-5, 49), Pair(-7, 12), Pair(2, 53), Pair(0, 31), Pair(34, -41), Pair(13, -66), Pair(-41, 65)
      },
      { // Piece 5
        Pair(-89, -98), Pair(-25, 44), Pair(9, -6), Pair(-4, 2), Pair(-5, 7), Pair(124, 21), Pair(21, 32), Pair(63, 312),
        Pair(-44, -8), Pair(-5, 16), Pair(5, 21), Pair(8, 20), Pair(64, 27), Pair(41, 48), Pair(227, 39), Pair(51, 49),
        Pair(-136, 10), Pair(-120, 30), Pair(-69, 24), Pair(-132, 41), Pair(47, 8), Pair(24, 52), Pair(120, 37), Pair(17, 55),
        Pair(-110, 15), Pair(-17, 5), Pair(-1, 16), Pair(-10, 28), Pair(37, 28), Pair(-1, 3), Pair(36, 10), Pair(-49, 7),
        Pair(-94, 2), Pair(-20, 18), Pair(-60, 24), Pair(-21, 23), Pair(17, 19), Pair(-10, 12), Pair(0, 0), Pair(-17, 4),
        Pair(-13, -23), Pair(-6, -5), Pair(-14, 8), Pair(-68, 26), Pair(-8, 11), Pair(-3, 8), Pair(3, 8), Pair(-38, 9),
        Pair(-29, -9), Pair(-26, -2), Pair(-39, 10), Pair(-42, 10), Pair(-10, 8), Pair(-17, 10), Pair(6, 0), Pair(-27, 13),
        Pair(8, -62), Pair(-19, -5), Pair(-22, -5), Pair(-8, -15), Pair(-6, -7), Pair(16, -23), Pair(16, -12), Pair(-7, -30)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(12, 8), Pair(33, 9), Pair(14, 2), Pair(-16, 8), Pair(-23, 9), Pair(-19, 11), Pair(8, 10), Pair(43, -20),
        Pair(-7, 13), Pair(-6, 17), Pair(-4, 9), Pair(-1, 7), Pair(-5, 12), Pair(-8, 11), Pair(-13, 16), Pair(24, -5),
        Pair(-1, 9), Pair(1, 10), Pair(1, 7), Pair(1, 5), Pair(-2, 6), Pair(1, 4), Pair(2, 0), Pair(10, -5),
        Pair(-1, 11), Pair(-2, 13), Pair(-3, 11), Pair(0, 8), Pair(2, 7), Pair(-1, 1), Pair(7, -7), Pair(9, 2),
        Pair(-1, 13), Pair(-1, 12), Pair(0, 10), Pair(1, 9), Pair(6, 9), Pair(5, 3), Pair(8, -2), Pair(4, 6),
        Pair(-1, 15), Pair(0, 9), Pair(-4, 10), Pair(-2, 10), Pair(2, 8), Pair(3, 7), Pair(2, 9), Pair(10, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(130, -18), Pair(254, -26), Pair(-83, 46), Pair(69, 10), Pair(87, 2), Pair(104, -9), Pair(48, 16), Pair(-50, -64),
        Pair(3, 11), Pair(-41, 35), Pair(0, 36), Pair(46, 20), Pair(56, 12), Pair(6, 8), Pair(-33, 51), Pair(-51, 35),
        Pair(-40, 38), Pair(-2, 25), Pair(15, 17), Pair(17, 27), Pair(-2, 29), Pair(15, 16), Pair(47, -5), Pair(14, 1),
        Pair(-32, 28), Pair(7, 18), Pair(-6, 28), Pair(26, 22), Pair(20, 20), Pair(29, 16), Pair(19, 12), Pair(4, 15),
        Pair(2, 30), Pair(12, 19), Pair(15, 21), Pair(16, 14), Pair(8, 27), Pair(16, 23), Pair(18, 5), Pair(0, 0),
        Pair(-8, 22), Pair(4, 13), Pair(1, 22), Pair(-2, 30), Pair(8, 33), Pair(5, 27), Pair(4, 23), Pair(4, 50),
        Pair(-10, 43), Pair(-6, -1), Pair(-3, 13), Pair(-1, 27), Pair(1, 26), Pair(-3, 30), Pair(-12, 7), Pair(3, 15),
        Pair(-12, 33), Pair(-10, -6), Pair(2, 30), Pair(-33, 41), Pair(-9, 13), Pair(-9, 20), Pair(3, 7), Pair(-2, -87)
      },
      { // Piece 2
        Pair(68, -10), Pair(-28, 9), Pair(-55, 1), Pair(-2, -2), Pair(76, -15), Pair(-140, 30), Pair(-105, 5), Pair(52, -4),
        Pair(17, -6), Pair(47, -3), Pair(4, -13), Pair(45, -23), Pair(-21, -10), Pair(2, -8), Pair(-22, 13), Pair(-1, 0),
        Pair(26, 0), Pair(26, 2), Pair(26, 1), Pair(16, -9), Pair(32, 5), Pair(22, -9), Pair(66, -5), Pair(6, 9),
        Pair(-17, 17), Pair(5, 2), Pair(19, -6), Pair(19, 5), Pair(7, 14), Pair(30, 2), Pair(-13, 35), Pair(-1, 3),
        Pair(12, 3), Pair(-7, 5), Pair(25, -3), Pair(8, 7), Pair(17, 18), Pair(5, 16), Pair(6, 9), Pair(0, 0),
        Pair(-12, 4), Pair(21, 9), Pair(6, 9), Pair(15, 11), Pair(11, 14), Pair(5, 15), Pair(15, 10), Pair(12, 18),
        Pair(25, -18), Pair(2, 15), Pair(15, 18), Pair(0, 17), Pair(3, 24), Pair(7, 15), Pair(10, 15), Pair(15, -4),
        Pair(14, -8), Pair(19, 1), Pair(2, 18), Pair(2, 19), Pair(2, 10), Pair(-3, 14), Pair(21, -1), Pair(12, 21)
      },
      { // Piece 3
        Pair(-11, 31), Pair(11, 27), Pair(55, 13), Pair(2, 26), Pair(52, 13), Pair(91, -5), Pair(34, 20), Pair(40, -4),
        Pair(20, 28), Pair(19, 22), Pair(28, 19), Pair(12, 23), Pair(47, 9), Pair(12, 19), Pair(-21, 24), Pair(44, -9),
        Pair(-6, 41), Pair(21, 25), Pair(12, 25), Pair(23, 16), Pair(37, 16), Pair(30, 29), Pair(-13, 21), Pair(47, -6),
        Pair(-9, 32), Pair(21, 26), Pair(7, 26), Pair(28, 22), Pair(11, 27), Pair(18, 25), Pair(-2, 35), Pair(18, -7),
        Pair(10, 24), Pair(-14, 24), Pair(4, 31), Pair(4, 32), Pair(15, 24), Pair(0, 32), Pair(10, 34), Pair(0, 0),
        Pair(28, 15), Pair(-5, 28), Pair(21, 13), Pair(-13, 32), Pair(5, 26), Pair(3, 26), Pair(-7, 20), Pair(-55, 13),
        Pair(-15, 28), Pair(-16, 31), Pair(-8, 24), Pair(7, 17), Pair(-8, 35), Pair(-7, 28), Pair(-10, 34), Pair(-53, 8),
        Pair(4, 15), Pair(8, 14), Pair(4, 19), Pair(9, 15), Pair(7, 20), Pair(9, 19), Pair(-9, 32), Pair(-29, -13)
      },
      { // Piece 4
        Pair(14, -4), Pair(88, -30), Pair(-29, 31), Pair(-32, 56), Pair(97, -22), Pair(-45, 55), Pair(12, 32), Pair(10, 14),
        Pair(16, 3), Pair(-14, 25), Pair(17, -5), Pair(30, -41), Pair(15, 2), Pair(-3, 36), Pair(40, -33), Pair(19, -72),
        Pair(9, -5), Pair(20, -5), Pair(15, 16), Pair(41, -14), Pair(10, 28), Pair(17, -35), Pair(20, 19), Pair(-10, -10),
        Pair(-17, 38), Pair(27, -33), Pair(0, 39), Pair(-7, 21), Pair(0, 15), Pair(11, 32), Pair(-2, 49), Pair(2, -11),
        Pair(10, 19), Pair(7, 5), Pair(11, 36), Pair(-10, 36), Pair(-6, 26), Pair(-3, 43), Pair(10, 30), Pair(0, 0),
        Pair(12, 18), Pair(14, -1), Pair(3, 36), Pair(4, 36), Pair(-5, 34), Pair(3, 27), Pair(17, -10), Pair(17, -6),
        Pair(24, -20), Pair(4, 30), Pair(6, 23), Pair(6, 23), Pair(4, 24), Pair(-3, 18), Pair(7, 4), Pair(9, -18),
        Pair(20, -5), Pair(-11, 52), Pair(-4, 47), Pair(4, 33), Pair(17, -4), Pair(25, 8), Pair(-58, 29), Pair(8, -88)
      },
      { // Piece 5
        Pair(-67, 4), Pair(-91, 92), Pair(-27, 10), Pair(-164, 36), Pair(-16, 40), Pair(-9, 36), Pair(-58, 104), Pair(21, -20),
        Pair(-47, 35), Pair(-12, 35), Pair(-44, -14), Pair(-29, 38), Pair(25, -2), Pair(-148, 77), Pair(-183, 81), Pair(-23, 17),
        Pair(-13, 14), Pair(-59, 15), Pair(-117, 20), Pair(-3, 16), Pair(18, 35), Pair(6, 33), Pair(34, 41), Pair(-57, 14),
        Pair(-83, -2), Pair(-27, 8), Pair(4, 15), Pair(-4, 25), Pair(-66, 27), Pair(-9, 20), Pair(-29, 9), Pair(-38, -7),
        Pair(13, -21), Pair(-35, 1), Pair(-56, 14), Pair(-44, 22), Pair(-16, 16), Pair(1, 15), Pair(-29, -15), Pair(0, 0),
        Pair(-114, 16), Pair(-39, 18), Pair(-81, 22), Pair(-62, 17), Pair(-17, 12), Pair(5, 0), Pair(-26, -10), Pair(-51, -22),
        Pair(-65, 7), Pair(-59, 11), Pair(-20, 2), Pair(-30, 8), Pair(-19, 1), Pair(-17, 1), Pair(-3, -8), Pair(-7, -21),
        Pair(-41, -8), Pair(-28, 0), Pair(-34, 5), Pair(-34, -8), Pair(-10, -8), Pair(-15, -7), Pair(16, -12), Pair(2, -33)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(32, 17), Pair(-28, 20), Pair(7, 17), Pair(-5, 17), Pair(5, 0), Pair(-43, 12), Pair(36, -5), Pair(7, 17),
        Pair(-9, 36), Pair(-6, 16), Pair(-6, 14), Pair(-3, 7), Pair(2, 5), Pair(6, 5), Pair(-10, 1), Pair(7, 10),
        Pair(6, 14), Pair(-1, 14), Pair(1, 11), Pair(-1, 8), Pair(1, 10), Pair(5, 11), Pair(-2, 11), Pair(-3, 12),
        Pair(3, 12), Pair(6, 7), Pair(2, 5), Pair(1, 7), Pair(1, 8), Pair(3, 10), Pair(-3, 11), Pair(-1, 12),
        Pair(-5, 2), Pair(-1, 3), Pair(-4, 9), Pair(2, 12), Pair(0, 11), Pair(2, 8), Pair(-1, 14), Pair(-3, 15),
        Pair(6, 0), Pair(3, 17), Pair(-6, 9), Pair(-1, 7), Pair(-5, 14), Pair(1, 16), Pair(0, 17), Pair(-1, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(55, -33), Pair(-150, 31), Pair(-47, 40), Pair(-67, 22), Pair(-107, 61), Pair(87, -9), Pair(-13, 26), Pair(-54, -13),
        Pair(1, 13), Pair(20, 5), Pair(-12, 39), Pair(-18, 41), Pair(0, 32), Pair(5, 47), Pair(-42, 74), Pair(14, 2),
        Pair(47, -10), Pair(1, 28), Pair(4, 33), Pair(-16, 45), Pair(10, 38), Pair(-40, 50), Pair(-41, 64), Pair(-21, -1),
        Pair(2, 23), Pair(10, 33), Pair(-1, 36), Pair(3, 39), Pair(2, 46), Pair(6, 31), Pair(0, 35), Pair(-12, 52),
        Pair(-1, 21), Pair(10, 30), Pair(6, 40), Pair(6, 31), Pair(2, 37), Pair(9, 38), Pair(-6, 22), Pair(3, 16),
        Pair(0, 0), Pair(-3, 48), Pair(5, 25), Pair(5, 35), Pair(9, 43), Pair(3, 32), Pair(2, 38), Pair(2, 26),
        Pair(-7, 49), Pair(7, 43), Pair(-7, 28), Pair(0, 44), Pair(1, 33), Pair(-12, 50), Pair(5, 36), Pair(-1, 8),
        Pair(85, -2), Pair(-8, 30), Pair(-3, 22), Pair(-1, 32), Pair(-13, 49), Pair(0, 25), Pair(-1, 15), Pair(78, -9)
      },
      { // Piece 2
        Pair(-19, 40), Pair(-29, 24), Pair(-88, 38), Pair(-71, 27), Pair(-7, 15), Pair(-36, 0), Pair(-74, 27), Pair(-21, 26),
        Pair(23, 22), Pair(17, 22), Pair(17, 20), Pair(31, -4), Pair(-7, -4), Pair(10, -1), Pair(-15, 10), Pair(-25, 21),
        Pair(-20, 15), Pair(3, 17), Pair(14, 27), Pair(32, -1), Pair(18, 23), Pair(-17, 2), Pair(-12, 20), Pair(-10, 28),
        Pair(-9, 37), Pair(7, 30), Pair(6, 11), Pair(2, 28), Pair(9, 16), Pair(14, 13), Pair(8, 18), Pair(-2, 33),
        Pair(7, 18), Pair(41, 24), Pair(12, 18), Pair(17, 8), Pair(10, 32), Pair(4, 21), Pair(14, 20), Pair(-7, 28),
        Pair(0, 0), Pair(-1, 22), Pair(8, 20), Pair(4, 31), Pair(9, 23), Pair(7, 35), Pair(5, 10), Pair(4, 24),
        Pair(19, 13), Pair(6, 18), Pair(6, 29), Pair(1, 24), Pair(4, 37), Pair(2, 28), Pair(5, 33), Pair(6, 32),
        Pair(7, 28), Pair(-4, 25), Pair(-4, 21), Pair(3, 32), Pair(3, 17), Pair(-6, 43), Pair(-1, 14), Pair(-4, 41)
      },
      { // Piece 3
        Pair(-25, 32), Pair(-3, 44), Pair(-44, 69), Pair(-11, 51), Pair(-41, 75), Pair(29, 33), Pair(44, 53), Pair(-29, 70),
        Pair(-36, 28), Pair(-5, 50), Pair(-6, 54), Pair(-15, 51), Pair(-12, 42), Pair(-4, 43), Pair(-2, 36), Pair(29, 33),
        Pair(-12, 32), Pair(1, 47), Pair(-13, 63), Pair(7, 31), Pair(-9, 52), Pair(-18, 63), Pair(-5, 42), Pair(0, 53),
        Pair(-45, 50), Pair(-6, 59), Pair(4, 49), Pair(-3, 52), Pair(-1, 44), Pair(-3, 68), Pair(11, 55), Pair(11, 29),
        Pair(-33, 38), Pair(19, 46), Pair(-14, 59), Pair(8, 50), Pair(-2, 58), Pair(-4, 45), Pair(-29, 74), Pair(17, 46),
        Pair(0, 0), Pair(-4, 55), Pair(5, 47), Pair(4, 45), Pair(-4, 49), Pair(-1, 51), Pair(-7, 57), Pair(25, 28),
        Pair(-36, 24), Pair(2, 43), Pair(0, 51), Pair(6, 42), Pair(-5, 53), Pair(-5, 44), Pair(-1, 42), Pair(-9, 54),
        Pair(-28, 21), Pair(-5, 47), Pair(-3, 50), Pair(-3, 52), Pair(-2, 46), Pair(-3, 41), Pair(2, 40), Pair(7, 33)
      },
      { // Piece 4
        Pair(50, 32), Pair(-1, 69), Pair(-41, 96), Pair(-42, 98), Pair(-25, 91), Pair(-18, 71), Pair(-108, 174), Pair(-52, 97),
        Pair(-27, 76), Pair(-4, 78), Pair(25, 32), Pair(-5, 100), Pair(17, 55), Pair(-6, 95), Pair(23, 38), Pair(22, 34),
        Pair(-45, 124), Pair(3, 61), Pair(12, 67), Pair(-4, 91), Pair(5, 69), Pair(-13, 102), Pair(0, 71), Pair(-27, 121),
        Pair(10, 49), Pair(1, 86), Pair(1, 78), Pair(12, 61), Pair(27, 39), Pair(10, 74), Pair(-1, 81), Pair(7, 79),
        Pair(-11, 56), Pair(10, 92), Pair(2, 94), Pair(12, 75), Pair(4, 88), Pair(4, 80), Pair(-2, 79), Pair(7, 76),
        Pair(0, 0), Pair(15, 63), Pair(7, 84), Pair(9, 70), Pair(3, 107), Pair(8, 86), Pair(7, 89), Pair(37, -9),
        Pair(-4, 71), Pair(12, 83), Pair(11, 79), Pair(8, 81), Pair(4, 80), Pair(17, 67), Pair(20, 43), Pair(17, 27),
        Pair(-5, 72), Pair(-12, 97), Pair(2, 75), Pair(5, 88), Pair(4, 71), Pair(18, 74), Pair(6, 67), Pair(30, -8)
      },
      { // Piece 5
        Pair(-19, 78), Pair(112, 57), Pair(75, 105), Pair(20, -19), Pair(-9, 117), Pair(-49, 42), Pair(-12, 7), Pair(-136, -102),
        Pair(-101, 0), Pair(-95, 57), Pair(134, 5), Pair(-22, 79), Pair(29, -28), Pair(20, -25), Pair(-66, 11), Pair(-47, -12),
        Pair(-61, 11), Pair(24, 35), Pair(23, 48), Pair(-74, 66), Pair(-253, 61), Pair(88, -13), Pair(-42, 12), Pair(-39, 2),
        Pair(60, -11), Pair(94, 22), Pair(-61, 31), Pair(-52, 36), Pair(-79, 37), Pair(-25, 19), Pair(-26, 0), Pair(-10, 5),
        Pair(-48, -15), Pair(-78, 16), Pair(-52, 41), Pair(-39, 29), Pair(-72, 28), Pair(-1, 9), Pair(-25, 9), Pair(-4, -16),
        Pair(0, 0), Pair(-7, 13), Pair(48, 6), Pair(-27, 22), Pair(-20, 13), Pair(-18, 11), Pair(-5, 0), Pair(-45, -6),
        Pair(33, -59), Pair(13, -4), Pair(7, 7), Pair(9, 10), Pair(-7, 5), Pair(-19, 14), Pair(-17, 5), Pair(-20, 2),
        Pair(49, -34), Pair(71, -8), Pair(52, -11), Pair(1, -9), Pair(3, -8), Pair(-6, 3), Pair(-5, -4), Pair(-4, -16)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 11), Pair(-43, 13), Pair(-64, 29), Pair(0, 7), Pair(-38, 26), Pair(8, -8), Pair(23, 17), Pair(1, 3),
        Pair(-9, 15), Pair(13, 9), Pair(-11, 16), Pair(1, 3), Pair(3, 4), Pair(4, 9), Pair(-9, 5), Pair(1, 5),
        Pair(-4, 9), Pair(8, 6), Pair(-1, 9), Pair(2, 9), Pair(4, 3), Pair(5, 5), Pair(3, 8), Pair(0, 10),
        Pair(0, 2), Pair(2, -8), Pair(4, 6), Pair(5, 5), Pair(1, 8), Pair(6, 9), Pair(3, 12), Pair(-1, 10),
        Pair(-2, 3), Pair(-6, 1), Pair(-2, 11), Pair(-2, 11), Pair(1, 10), Pair(4, 9), Pair(4, 12), Pair(1, 10),
        Pair(2, 16), Pair(-1, -4), Pair(7, 20), Pair(1, 8), Pair(1, 11), Pair(0, 14), Pair(5, 16), Pair(1, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-65, 49), Pair(1, 67), Pair(-50, 69), Pair(-106, 67), Pair(39, 16), Pair(-85, 41), Pair(-166, 49), Pair(-74, 94),
        Pair(-9, 34), Pair(-4, 29), Pair(-15, 32), Pair(-23, 50), Pair(-44, 56), Pair(-29, 49), Pair(-82, 64), Pair(-5, 47),
        Pair(-20, 27), Pair(-4, 31), Pair(-16, 44), Pair(-8, 43), Pair(-24, 49), Pair(-6, 26), Pair(-21, 42), Pair(-28, 40),
        Pair(-21, 35), Pair(3, 19), Pair(5, 36), Pair(-6, 40), Pair(-1, 45), Pair(-10, 41), Pair(-12, 49), Pair(-12, 45),
        Pair(-3, 25), Pair(-3, 34), Pair(-2, 21), Pair(1, 40), Pair(-10, 43), Pair(2, 40), Pair(-5, 44), Pair(-2, 28),
        Pair(-4, 44), Pair(0, 0), Pair(1, 40), Pair(6, 36), Pair(1, 44), Pair(0, 37), Pair(-4, 49), Pair(11, 35),
        Pair(-15, 55), Pair(12, 52), Pair(2, 39), Pair(-6, 36), Pair(0, 47), Pair(0, 57), Pair(0, 44), Pair(-2, 35),
        Pair(23, 23), Pair(-3, 12), Pair(-9, 37), Pair(-5, 55), Pair(-4, 41), Pair(-2, 44), Pair(-1, 29), Pair(-19, -41)
      },
      { // Piece 2
        Pair(44, 19), Pair(-144, 61), Pair(-48, 23), Pair(37, 27), Pair(55, -12), Pair(-38, 41), Pair(-33, -10), Pair(-2, -29),
        Pair(-7, 27), Pair(-15, 23), Pair(1, 32), Pair(7, 2), Pair(32, 6), Pair(-35, 26), Pair(-11, 27), Pair(6, 10),
        Pair(-19, 15), Pair(3, 33), Pair(21, -2), Pair(8, 28), Pair(6, 2), Pair(5, 18), Pair(27, -9), Pair(-18, 30),
        Pair(-10, 29), Pair(2, 3), Pair(-2, 27), Pair(7, 14), Pair(5, 16), Pair(9, 5), Pair(-2, 11), Pair(-13, 30),
        Pair(-71, -23), Pair(9, 36), Pair(-4, 24), Pair(4, 24), Pair(0, 21), Pair(2, 33), Pair(8, 20), Pair(10, 24),
        Pair(2, 16), Pair(0, 0), Pair(5, 26), Pair(1, 20), Pair(-1, 38), Pair(4, 21), Pair(1, 46), Pair(1, 21),
        Pair(-62, -24), Pair(7, 38), Pair(-8, 12), Pair(1, 41), Pair(-3, 28), Pair(14, 24), Pair(-2, 26), Pair(-6, 55),
        Pair(8, -12), Pair(-4, 19), Pair(-2, 18), Pair(-7, 21), Pair(5, 33), Pair(0, 33), Pair(-4, 31), Pair(21, -17)
      },
      { // Piece 3
        Pair(-6, 39), Pair(-13, 40), Pair(-27, 49), Pair(1, 33), Pair(-7, 48), Pair(-4, 59), Pair(10, 45), Pair(-8, 35),
        Pair(-18, 38), Pair(-31, 34), Pair(-9, 41), Pair(18, 33), Pair(21, 34), Pair(-35, 69), Pair(-29, 51), Pair(15, 35),
        Pair(-11, 41), Pair(-32, 46), Pair(-4, 42), Pair(-7, 52), Pair(-10, 42), Pair(-38, 59), Pair(-8, 35), Pair(-9, 40),
        Pair(-7, 39), Pair(-16, 47), Pair(-16, 49), Pair(-6, 45), Pair(2, 39), Pair(-2, 46), Pair(19, 32), Pair(-17, 55),
        Pair(-12, 52), Pair(-26, 35), Pair(-3, 60), Pair(-6, 59), Pair(-11, 51), Pair(-5, 44), Pair(-9, 54), Pair(-1, 40),
        Pair(-8, 20), Pair(0, 0), Pair(-5, 46), Pair(4, 46), Pair(2, 47), Pair(-15, 53), Pair(-3, 45), Pair(-4, 36),
        Pair(-2, 23), Pair(-15, 5), Pair(-5, 49), Pair(11, 37), Pair(0, 44), Pair(-16, 57), Pair(-2, 61), Pair(6, 47),
        Pair(-6, 39), Pair(-17, 16), Pair(-6, 45), Pair(-1, 42), Pair(-3, 40), Pair(-4, 42), Pair(1, 50), Pair(4, 34)
      },
      { // Piece 4
        Pair(-53, 106), Pair(-76, 91), Pair(-13, 62), Pair(-48, 63), Pair(-33, 86), Pair(-40, 46), Pair(-63, 105), Pair(5, 45),
        Pair(-11, 34), Pair(-9, 29), Pair(7, 37), Pair(13, 44), Pair(-39, 64), Pair(-28, 52), Pair(17, 60), Pair(-50, 122),
        Pair(3, 43), Pair(-36, 65), Pair(-11, 43), Pair(-18, 85), Pair(-31, 54), Pair(-23, 76), Pair(-8, 57), Pair(7, 37),
        Pair(-7, 51), Pair(-8, 41), Pair(-12, 78), Pair(-16, 88), Pair(-6, 49), Pair(-16, 65), Pair(-5, 44), Pair(-10, 64),
        Pair(-13, 71), Pair(-13, 59), Pair(8, 57), Pair(-3, 62), Pair(-9, 74), Pair(-8, 56), Pair(-10, 55), Pair(-8, 53),
        Pair(-4, 11), Pair(0, 0), Pair(7, 47), Pair(-1, 72), Pair(12, 50), Pair(5, 67), Pair(-4, 58), Pair(13, 52),
        Pair(-6, 62), Pair(0, 45), Pair(7, 42), Pair(5, 60), Pair(8, 58), Pair(9, 48), Pair(2, 61), Pair(0, 65),
        Pair(4, 25), Pair(14, 2), Pair(2, 60), Pair(3, 55), Pair(-7, 104), Pair(20, 38), Pair(0, 82), Pair(67, 7)
      },
      { // Piece 5
        Pair(47, 45), Pair(25, 59), Pair(41, 51), Pair(-28, -35), Pair(23, -62), Pair(46, 113), Pair(-94, -109), Pair(-24, 50),
        Pair(101, 4), Pair(20, 64), Pair(-30, 46), Pair(181, 21), Pair(64, 18), Pair(-11, 13), Pair(11, -10), Pair(-139, 53),
        Pair(-154, 68), Pair(109, 22), Pair(-6, 46), Pair(126, 10), Pair(-91, 40), Pair(-4, 12), Pair(138, -12), Pair(-138, 22),
        Pair(71, 50), Pair(55, 10), Pair(29, 36), Pair(38, 20), Pair(-127, 51), Pair(-44, 13), Pair(10, 7), Pair(-69, 16),
        Pair(19, 21), Pair(11, 14), Pair(12, 9), Pair(-62, 38), Pair(-51, 37), Pair(-52, 24), Pair(21, 1), Pair(-65, 15),
        Pair(-49, 46), Pair(0, 0), Pair(-8, 24), Pair(3, 19), Pair(0, 18), Pair(-4, 6), Pair(-19, 7), Pair(-50, 9),
        Pair(46, -2), Pair(31, 0), Pair(-11, 15), Pair(-11, 16), Pair(10, 6), Pair(-14, 10), Pair(-10, 3), Pair(-8, -4),
        Pair(62, -35), Pair(61, -18), Pair(43, -6), Pair(-5, 11), Pair(-3, 6), Pair(-11, 5), Pair(-6, -2), Pair(-7, -14)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(4, 10), Pair(-61, 18), Pair(-102, 38), Pair(3, 11), Pair(6, 8), Pair(-41, 4), Pair(25, 9), Pair(29, 8),
        Pair(-5, 9), Pair(10, 13), Pair(-13, -1), Pair(-1, 7), Pair(5, 10), Pair(4, 3), Pair(8, 4), Pair(4, 7),
        Pair(-1, 11), Pair(-2, 9), Pair(-4, 2), Pair(-4, 13), Pair(5, 7), Pair(6, 5), Pair(0, 5), Pair(-1, 5),
        Pair(0, 7), Pair(5, 11), Pair(-10, -18), Pair(7, 15), Pair(2, 6), Pair(5, 4), Pair(2, 10), Pair(-1, 10),
        Pair(-4, 7), Pair(-1, 12), Pair(-2, -6), Pair(0, 20), Pair(-7, 8), Pair(4, 9), Pair(2, 12), Pair(0, 9),
        Pair(-1, 7), Pair(8, 23), Pair(-10, -20), Pair(1, 20), Pair(-6, 16), Pair(-2, 8), Pair(1, 13), Pair(0, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(6, -42), Pair(-207, 107), Pair(-31, 41), Pair(-88, 67), Pair(27, 45), Pair(-43, 43), Pair(-65, -37), Pair(103, -60),
        Pair(5, 10), Pair(8, 25), Pair(-4, 18), Pair(-10, 37), Pair(12, 28), Pair(18, 22), Pair(11, 36), Pair(-40, 58),
        Pair(1, 48), Pair(3, 30), Pair(-18, 34), Pair(9, 28), Pair(-10, 22), Pair(-18, 47), Pair(-9, 39), Pair(28, 13),
        Pair(-10, 44), Pair(1, 18), Pair(4, 28), Pair(28, 34), Pair(2, 30), Pair(10, 36), Pair(-2, 33), Pair(8, 30),
        Pair(-6, 7), Pair(7, 27), Pair(11, 14), Pair(7, 34), Pair(7, 33), Pair(9, 40), Pair(-4, 46), Pair(11, 18),
        Pair(-1, 30), Pair(4, 32), Pair(0, 0), Pair(8, 36), Pair(16, 31), Pair(7, 42), Pair(10, 22), Pair(7, 28),
        Pair(-22, -28), Pair(2, 21), Pair(5, 58), Pair(9, 40), Pair(-2, 30), Pair(3, 39), Pair(7, 43), Pair(-3, 62),
        Pair(95, 14), Pair(-1, 6), Pair(4, 27), Pair(-2, 46), Pair(2, 33), Pair(1, 25), Pair(-2, 30), Pair(-6, 45)
      },
      { // Piece 2
        Pair(-23, 55), Pair(98, -33), Pair(87, 26), Pair(13, 2), Pair(44, 10), Pair(41, -50), Pair(114, -8), Pair(-18, -26),
        Pair(-17, 26), Pair(11, 10), Pair(31, 5), Pair(74, -28), Pair(-33, 7), Pair(20, -3), Pair(6, 0), Pair(9, 10),
        Pair(10, 20), Pair(33, -16), Pair(28, 16), Pair(22, -6), Pair(10, 13), Pair(5, -8), Pair(35, 4), Pair(-1, 5),
        Pair(3, -8), Pair(7, 15), Pair(-9, 2), Pair(20, 17), Pair(4, -5), Pair(17, 4), Pair(-3, 9), Pair(10, 28),
        Pair(20, 9), Pair(10, 7), Pair(5, 25), Pair(25, 12), Pair(6, 13), Pair(6, 6), Pair(10, 36), Pair(9, 8),
        Pair(1, -9), Pair(16, 4), Pair(0, 0), Pair(12, 21), Pair(2, 11), Pair(18, 24), Pair(6, 16), Pair(9, 31),
        Pair(24, -10), Pair(-16, -37), Pair(17, 50), Pair(-4, 7), Pair(8, 36), Pair(8, 1), Pair(10, 38), Pair(4, 22),
        Pair(-26, -94), Pair(22, 10), Pair(-2, 4), Pair(0, 25), Pair(-5, -14), Pair(8, 34), Pair(0, 25), Pair(20, 28)
      },
      { // Piece 3
        Pair(-41, 60), Pair(-6, 44), Pair(-44, 34), Pair(-20, 40), Pair(-7, 37), Pair(64, 11), Pair(34, 22), Pair(-4, 52),
        Pair(-3, 38), Pair(5, 35), Pair(-26, 29), Pair(-6, 38), Pair(-9, 41), Pair(-9, 46), Pair(-8, 46), Pair(-8, 32),
        Pair(-9, 40), Pair(-18, 52), Pair(14, 21), Pair(-13, 39), Pair(-6, 43), Pair(-17, 30), Pair(-4, 33), Pair(27, 23),
        Pair(0, 49), Pair(12, 25), Pair(-5, 23), Pair(-28, 44), Pair(4, 31), Pair(-5, 56), Pair(3, 20), Pair(-17, 47),
        Pair(-13, 47), Pair(17, 17), Pair(-21, 29), Pair(18, 45), Pair(-4, 43), Pair(2, 41), Pair(-10, 38), Pair(1, 39),
        Pair(4, 14), Pair(-13, 18), Pair(0, 0), Pair(3, 29), Pair(11, 19), Pair(4, 28), Pair(-9, 38), Pair(6, 31),
        Pair(-7, 42), Pair(-11, 28), Pair(-10, 20), Pair(-1, 39), Pair(8, 30), Pair(-3, 34), Pair(9, 33), Pair(-17, 47),
        Pair(1, 36), Pair(4, 26), Pair(2, -1), Pair(-1, 33), Pair(2, 35), Pair(1, 31), Pair(-1, 36), Pair(3, 33)
      },
      { // Piece 4
        Pair(-14, 74), Pair(-49, 111), Pair(-68, 78), Pair(-71, 127), Pair(-31, 46), Pair(40, 1), Pair(10, 129), Pair(61, 21),
        Pair(-11, 32), Pair(6, 33), Pair(-26, 67), Pair(25, 14), Pair(2, 56), Pair(25, 28), Pair(44, -75), Pair(11, 20),
        Pair(4, 13), Pair(-10, 58), Pair(-28, 99), Pair(-19, 66), Pair(-27, 94), Pair(-20, 93), Pair(-8, 97), Pair(-22, 84),
        Pair(3, -1), Pair(0, 49), Pair(17, 13), Pair(-13, 77), Pair(-4, 29), Pair(-9, 38), Pair(-12, 76), Pair(-11, 64),
        Pair(-7, 66), Pair(10, 12), Pair(0, 63), Pair(5, 49), Pair(-14, 72), Pair(-3, 64), Pair(-4, 63), Pair(-6, 35),
        Pair(-15, 40), Pair(5, 26), Pair(0, 0), Pair(9, 35), Pair(10, 41), Pair(5, 55), Pair(-1, 73), Pair(-8, 124),
        Pair(14, 15), Pair(-6, 43), Pair(-2, 34), Pair(7, 52), Pair(3, 63), Pair(12, 38), Pair(-11, 69), Pair(14, 46),
        Pair(9, 39), Pair(2, 41), Pair(0, 36), Pair(1, 64), Pair(3, 28), Pair(5, 60), Pair(19, 32), Pair(7, 19)
      },
      { // Piece 5
        Pair(-41, -36), Pair(29, 106), Pair(-73, 45), Pair(-133, 57), Pair(51, 111), Pair(0, -23), Pair(-52, -148), Pair(4, -117),
        Pair(77, -56), Pair(30, 58), Pair(120, 29), Pair(-49, 124), Pair(-10, 79), Pair(-15, 4), Pair(79, 19), Pair(36, -51),
        Pair(-133, 95), Pair(53, 30), Pair(-129, 56), Pair(-2, 13), Pair(96, 4), Pair(21, 27), Pair(112, -21), Pair(5, -12),
        Pair(73, 6), Pair(-122, 52), Pair(-92, 44), Pair(-83, 46), Pair(80, 0), Pair(-112, 32), Pair(-4, -4), Pair(-52, -5),
        Pair(46, 21), Pair(-64, 1), Pair(-34, 11), Pair(-13, 1), Pair(-37, 19), Pair(-50, 13), Pair(-39, 12), Pair(-66, 14),
        Pair(19, 20), Pair(-3, 10), Pair(0, 0), Pair(-11, 16), Pair(-28, 11), Pair(-9, 0), Pair(-6, 2), Pair(-2, -9),
        Pair(45, -12), Pair(14, 7), Pair(-29, 9), Pair(-19, 10), Pair(-4, -4), Pair(-8, 0), Pair(-8, -8), Pair(-2, -13),
        Pair(41, -17), Pair(-11, -11), Pair(-11, -14), Pair(-19, 9), Pair(7, -8), Pair(2, -20), Pair(0, -17), Pair(-2, -23)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, 6), Pair(-3, 3), Pair(-7, 9), Pair(-54, 26), Pair(14, -5), Pair(6, -8), Pair(62, -31), Pair(11, -8),
        Pair(-9, 18), Pair(6, -1), Pair(7, 6), Pair(-3, 5), Pair(2, 10), Pair(1, 6), Pair(-13, 10), Pair(-8, 1),
        Pair(1, 7), Pair(4, 11), Pair(-4, 13), Pair(9, 11), Pair(2, 12), Pair(4, 10), Pair(-4, 7), Pair(-5, 8),
        Pair(-2, 12), Pair(-2, 9), Pair(4, 13), Pair(1, 2), Pair(9, 11), Pair(4, 8), Pair(0, 10), Pair(-1, 8),
        Pair(-2, 11), Pair(-2, 9), Pair(0, 20), Pair(5, -12), Pair(2, 21), Pair(-8, 6), Pair(1, 11), Pair(-1, 9),
        Pair(-3, 10), Pair(-2, 4), Pair(7, 26), Pair(-9, 1), Pair(9, 34), Pair(-8, 14), Pair(-1, 9), Pair(1, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(35, -55), Pair(6, 26), Pair(-98, 88), Pair(-99, 67), Pair(84, -4), Pair(-87, 18), Pair(-57, 142), Pair(-29, 3),
        Pair(0, 29), Pair(-28, 62), Pair(-2, 34), Pair(4, 59), Pair(-54, 58), Pair(-50, 72), Pair(-96, 73), Pair(-2, 5),
        Pair(-65, 65), Pair(-10, 22), Pair(7, 19), Pair(-31, 47), Pair(-10, 39), Pair(-18, 24), Pair(-9, 59), Pair(-22, 46),
        Pair(-4, 25), Pair(-2, 30), Pair(-1, 22), Pair(-28, 49), Pair(-2, 40), Pair(-5, 49), Pair(-14, 49), Pair(-14, 34),
        Pair(1, 19), Pair(-24, 45), Pair(-4, 29), Pair(-3, 33), Pair(11, 46), Pair(-3, 47), Pair(-16, 33), Pair(1, 23),
        Pair(1, 22), Pair(5, 25), Pair(-4, 36), Pair(0, 0), Pair(1, 28), Pair(4, 41), Pair(-10, 52), Pair(1, 27),
        Pair(-1, 32), Pair(-8, 4), Pair(-2, 38), Pair(4, 59), Pair(5, 41), Pair(-8, 19), Pair(2, 33), Pair(0, 19),
        Pair(-32, 18), Pair(-6, 20), Pair(-15, 16), Pair(1, 22), Pair(-1, 11), Pair(-14, 54), Pair(7, 35), Pair(-60, 140)
      },
      { // Piece 2
        Pair(-48, 25), Pair(187, -24), Pair(-24, 14), Pair(-43, 22), Pair(44, -31), Pair(-45, -5), Pair(18, -31), Pair(-20, 0),
        Pair(13, 12), Pair(1, 18), Pair(21, 0), Pair(29, -16), Pair(44, -4), Pair(-14, 2), Pair(-37, 47), Pair(69, -68),
        Pair(2, -5), Pair(24, 3), Pair(-8, 2), Pair(11, 15), Pair(-25, 18), Pair(-16, 25), Pair(4, -7), Pair(-14, 42),
        Pair(3, 12), Pair(-27, 7), Pair(2, 13), Pair(-16, 11), Pair(4, 26), Pair(-12, 5), Pair(3, 15), Pair(-16, 3),
        Pair(10, -1), Pair(11, 19), Pair(-13, 20), Pair(-3, 21), Pair(27, 11), Pair(5, 15), Pair(1, 10), Pair(1, 18),
        Pair(7, 28), Pair(-5, 5), Pair(9, 25), Pair(0, 0), Pair(1, 30), Pair(2, 5), Pair(-7, 26), Pair(3, 3),
        Pair(8, 37), Pair(-4, 33), Pair(-13, -35), Pair(11, 41), Pair(-5, -11), Pair(0, 14), Pair(0, 12), Pair(0, 26),
        Pair(11, 11), Pair(-23, -34), Pair(0, 28), Pair(-1, -4), Pair(3, 30), Pair(-11, -19), Pair(39, -14), Pair(20, -12)
      },
      { // Piece 3
        Pair(19, 25), Pair(9, 26), Pair(-60, 60), Pair(26, 15), Pair(59, 12), Pair(70, 9), Pair(-30, 46), Pair(25, 24),
        Pair(-15, 42), Pair(-4, 46), Pair(-35, 41), Pair(0, 27), Pair(-29, 61), Pair(24, 1), Pair(27, 3), Pair(-14, 21),
        Pair(-3, 46), Pair(-12, 40), Pair(5, 37), Pair(-1, 15), Pair(-9, 36), Pair(-19, 30), Pair(-5, 37), Pair(5, 32),
        Pair(-8, 35), Pair(2, 42), Pair(-17, 34), Pair(19, 15), Pair(-5, 30), Pair(8, 32), Pair(-7, 40), Pair(-6, 22),
        Pair(0, 30), Pair(-2, 36), Pair(-9, 47), Pair(11, 27), Pair(7, 41), Pair(0, 44), Pair(2, 52), Pair(-3, 25),
        Pair(4, 12), Pair(-17, 31), Pair(-4, 35), Pair(0, 0), Pair(1, 25), Pair(0, 19), Pair(-14, 30), Pair(5, 20),
        Pair(-9, 49), Pair(-3, 33), Pair(-2, 16), Pair(-14, 13), Pair(-4, 24), Pair(-5, 31), Pair(-20, 38), Pair(18, 24),
        Pair(-2, 24), Pair(4, 35), Pair(-9, 39), Pair(4, -6), Pair(-5, 28), Pair(-2, 29), Pair(-2, 32), Pair(2, 22)
      },
      { // Piece 4
        Pair(-21, 59), Pair(7, 49), Pair(45, 18), Pair(-85, 86), Pair(-29, 53), Pair(23, 32), Pair(51, 15), Pair(101, -60),
        Pair(-11, 45), Pair(-4, 44), Pair(-8, 34), Pair(24, 23), Pair(-21, 64), Pair(-25, 57), Pair(-10, 30), Pair(-14, 21),
        Pair(-18, 49), Pair(-27, 67), Pair(-14, 75), Pair(-2, 34), Pair(-31, 88), Pair(-10, 30), Pair(-32, 79), Pair(-13, 37),
        Pair(-9, 32), Pair(-15, 62), Pair(3, 17), Pair(-2, 21), Pair(-20, 50), Pair(0, 8), Pair(-5, 13), Pair(-3, 56),
        Pair(-10, 35), Pair(2, 36), Pair(-13, 37), Pair(-4, 32), Pair(7, 49), Pair(-11, 63), Pair(-9, 51), Pair(-3, 59),
        Pair(-18, 50), Pair(4, 6), Pair(-9, 40), Pair(0, 0), Pair(-3, 40), Pair(-2, 43), Pair(-5, 34), Pair(-9, 65),
        Pair(10, -1), Pair(8, 13), Pair(-1, 20), Pair(8, 25), Pair(0, 37), Pair(10, 39), Pair(-2, 87), Pair(38, -1),
        Pair(13, -6), Pair(5, -7), Pair(-3, 47), Pair(3, 19), Pair(0, 50), Pair(9, 34), Pair(19, 59), Pair(-5, 124)
      },
      { // Piece 5
        Pair(-11, 2), Pair(38, 165), Pair(3, -20), Pair(41, 101), Pair(22, -44), Pair(17, -21), Pair(0, -86), Pair(3, 17),
        Pair(-15, 30), Pair(-134, 49), Pair(67, 42), Pair(-46, 137), Pair(-55, 4), Pair(50, 91), Pair(124, 3), Pair(-107, -14),
        Pair(-86, 37), Pair(76, 35), Pair(-15, 40), Pair(71, 44), Pair(57, 27), Pair(115, -6), Pair(-104, 16), Pair(19, -21),
        Pair(-136, 62), Pair(115, -20), Pair(-106, 55), Pair(54, 3), Pair(58, -8), Pair(-34, -2), Pair(-172, 37), Pair(-36, 8),
        Pair(151, -21), Pair(-63, 17), Pair(0, -18), Pair(23, -7), Pair(-9, -21), Pair(13, -18), Pair(-40, 11), Pair(23, -17),
        Pair(29, -8), Pair(36, -1), Pair(-45, 24), Pair(0, 0), Pair(-58, 24), Pair(-13, -6), Pair(-4, -8), Pair(-7, -13),
        Pair(-32, 6), Pair(9, -13), Pair(-34, -9), Pair(-76, 18), Pair(-37, -5), Pair(-3, -18), Pair(0, -14), Pair(-3, -15),
        Pair(20, -51), Pair(-20, -3), Pair(-35, -6), Pair(-74, 11), Pair(-13, -24), Pair(11, -26), Pair(-1, -21), Pair(1, -20)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(1, 13), Pair(-1, 10), Pair(12, 9), Pair(-21, 16), Pair(8, -19), Pair(-32, -9), Pair(-4, 20), Pair(11, 2),
        Pair(-3, 10), Pair(-1, 8), Pair(1, 7), Pair(5, 7), Pair(-2, 11), Pair(-7, 8), Pair(-13, 10), Pair(-4, 2),
        Pair(2, 8), Pair(1, 8), Pair(3, 11), Pair(1, 14), Pair(4, 7), Pair(5, 9), Pair(7, 8), Pair(5, 2),
        Pair(0, 16), Pair(0, 13), Pair(-1, 11), Pair(10, 18), Pair(0, -2), Pair(14, 4), Pair(2, 11), Pair(1, 5),
        Pair(0, 11), Pair(3, 11), Pair(-6, 7), Pair(0, 22), Pair(1, -10), Pair(11, 9), Pair(-1, 4), Pair(7, 9),
        Pair(-1, 15), Pair(0, 11), Pair(-2, 11), Pair(9, 33), Pair(4, -12), Pair(17, 27), Pair(5, 7), Pair(7, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(14, 58), Pair(77, -6), Pair(-63, 38), Pair(7, 36), Pair(-10, 38), Pair(-14, 24), Pair(171, -63), Pair(127, 10),
        Pair(24, 10), Pair(-22, 51), Pair(-7, 32), Pair(18, 32), Pair(-28, 51), Pair(-18, 25), Pair(-21, 46), Pair(-28, -14),
        Pair(-18, 28), Pair(-13, 43), Pair(18, 26), Pair(-17, 45), Pair(-30, 48), Pair(-6, 22), Pair(-34, 36), Pair(0, 9),
        Pair(-2, 32), Pair(0, 37), Pair(-7, 36), Pair(-9, 41), Pair(-15, 38), Pair(-13, 34), Pair(-10, 28), Pair(-6, 38),
        Pair(2, 37), Pair(20, 21), Pair(4, 22), Pair(11, 34), Pair(-7, 30), Pair(1, 28), Pair(-20, 27), Pair(-3, 20),
        Pair(3, -1), Pair(5, 36), Pair(5, 31), Pair(2, 31), Pair(0, 0), Pair(-3, 34), Pair(1, 33), Pair(-2, 28),
        Pair(7, 34), Pair(11, 27), Pair(-8, 17), Pair(7, 32), Pair(4, 57), Pair(3, 35), Pair(-7, -8), Pair(-4, 32),
        Pair(40, -12), Pair(8, 28), Pair(4, 41), Pair(7, 23), Pair(-2, 27), Pair(-12, 29), Pair(4, -18), Pair(-27, 24)
      },
      { // Piece 2
        Pair(-25, 27), Pair(38, -25), Pair(86, -8), Pair(47, -25), Pair(6, 13), Pair(-25, 32), Pair(-8, 0), Pair(-7, -20),
        Pair(-23, 3), Pair(2, 9), Pair(-16, -1), Pair(56, -4), Pair(2, 0), Pair(-27, 13), Pair(-29, -5), Pair(12, 8),
        Pair(10, 12), Pair(0, -6), Pair(9, 11), Pair(-4, 7), Pair(-1, 19), Pair(-24, -3), Pair(13, 5), Pair(-32, -4),
        Pair(-5, 12), Pair(3, 17), Pair(-23, 12), Pair(4, 15), Pair(-18, 7), Pair(9, 23), Pair(-24, 11), Pair(2, 21),
        Pair(18, 0), Pair(-6, 13), Pair(1, 16), Pair(15, 6), Pair(1, 26), Pair(-24, 0), Pair(8, 18), Pair(-15, -3),
        Pair(-16, 13), Pair(6, 17), Pair(-10, 18), Pair(0, 28), Pair(0, 0), Pair(9, 21), Pair(-13, 5), Pair(2, 24),
        Pair(18, 2), Pair(-15, 13), Pair(-1, 23), Pair(-20, -5), Pair(9, 38), Pair(-28, -22), Pair(0, 31), Pair(-16, 29),
        Pair(-9, 25), Pair(1, 25), Pair(-28, -16), Pair(-1, 19), Pair(-9, 7), Pair(-1, 20), Pair(-46, -29), Pair(10, 17)
      },
      { // Piece 3
        Pair(0, 31), Pair(0, 38), Pair(-35, 37), Pair(-24, 37), Pair(2, 9), Pair(-1, 31), Pair(33, 25), Pair(-6, 37),
        Pair(1, 29), Pair(-2, 37), Pair(-8, 35), Pair(-3, 33), Pair(9, 17), Pair(-30, 28), Pair(-22, 32), Pair(2, 33),
        Pair(1, 37), Pair(12, 23), Pair(-16, 39), Pair(-4, 27), Pair(4, 14), Pair(-50, 42), Pair(0, 31), Pair(3, 30),
        Pair(-3, 34), Pair(11, 28), Pair(7, 27), Pair(-7, 27), Pair(17, 20), Pair(-1, 24), Pair(17, 16), Pair(-7, 33),
        Pair(2, 27), Pair(0, 32), Pair(-5, 34), Pair(19, 26), Pair(-8, 17), Pair(11, 25), Pair(-25, 31), Pair(6, 38),
        Pair(-5, 25), Pair(3, 22), Pair(-3, 21), Pair(-18, 29), Pair(0, 0), Pair(-15, 24), Pair(-14, 13), Pair(-9, 17),
        Pair(11, 24), Pair(-12, 35), Pair(1, 30), Pair(-3, 34), Pair(-4, -6), Pair(0, 18), Pair(-4, 34), Pair(26, 17),
        Pair(2, 25), Pair(4, 24), Pair(1, 24), Pair(-3, 28), Pair(-2, -8), Pair(-8, 26), Pair(3, 18), Pair(4, 29)
      },
      { // Piece 4
        Pair(-19, 96), Pair(-48, 97), Pair(-13, 55), Pair(19, 45), Pair(45, 20), Pair(86, -7), Pair(-13, 78), Pair(-77, 79),
        Pair(-14, 60), Pair(-6, 63), Pair(-23, 59), Pair(14, 46), Pair(-13, 60), Pair(-50, 100), Pair(1, 17), Pair(-23, 69),
        Pair(-6, 63), Pair(-8, 52), Pair(-20, 89), Pair(-7, 57), Pair(3, 35), Pair(-44, 80), Pair(-12, 53), Pair(-32, 28),
        Pair(-6, 56), Pair(3, 31), Pair(-7, 45), Pair(-19, 67), Pair(-5, 51), Pair(-8, 51), Pair(-22, 91), Pair(-8, 41),
        Pair(2, 61), Pair(5, 31), Pair(-12, 59), Pair(-5, 59), Pair(-15, 74), Pair(-12, 42), Pair(-8, 31), Pair(-23, 69),
        Pair(12, 32), Pair(6, 46), Pair(8, 17), Pair(-3, 42), Pair(0, 0), Pair(-8, 54), Pair(-8, 40), Pair(-24, 47),
        Pair(-12, 86), Pair(14, 23), Pair(4, 43), Pair(-1, 41), Pair(3, 35), Pair(-3, 50), Pair(-2, 46), Pair(-9, 51),
        Pair(5, 59), Pair(11, 38), Pair(-9, 53), Pair(-1, 45), Pair(-6, 34), Pair(10, 43), Pair(-49, 133), Pair(50, -24)
      },
      { // Piece 5
        Pair(48, 33), Pair(-5, 71), Pair(-57, 108), Pair(-12, 3), Pair(-68, -45), Pair(-30, 42), Pair(-46, 39), Pair(32, -12),
        Pair(59, 22), Pair(-62, 39), Pair(-263, 57), Pair(-57, 77), Pair(75, 52), Pair(17, 21), Pair(77, 11), Pair(8, 5),
        Pair(-12, -3), Pair(92, -22), Pair(-18, 22), Pair(61, 37), Pair(20, 43), Pair(8, 39), Pair(-29, 12), Pair(45, 5),
        Pair(-31, 39), Pair(-77, 4), Pair(45, 1), Pair(20, 24), Pair(-31, 28), Pair(1, 17), Pair(-3, -3), Pair(-155, 26),
        Pair(73, -40), Pair(-84, 15), Pair(-54, 16), Pair(-70, 4), Pair(-35, 13), Pair(-5, -18), Pair(20, -8), Pair(-44, 3),
        Pair(4, 6), Pair(2, 0), Pair(5, 1), Pair(-61, 21), Pair(0, 0), Pair(-31, 1), Pair(10, -4), Pair(20, -17),
        Pair(28, -23), Pair(0, -10), Pair(-14, -2), Pair(-22, 7), Pair(-47, 18), Pair(-26, 1), Pair(4, -13), Pair(11, -16),
        Pair(7, -32), Pair(1, -21), Pair(4, -15), Pair(-26, 5), Pair(-33, 6), Pair(-26, -4), Pair(7, -16), Pair(4, -19)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(18, -3), Pair(-20, 8), Pair(1, -1), Pair(10, -5), Pair(14, 17), Pair(64, -25), Pair(-18, 1), Pair(15, -1),
        Pair(9, 9), Pair(4, 11), Pair(17, 5), Pair(2, 4), Pair(7, 3), Pair(5, 11), Pair(-3, 18), Pair(-12, 8),
        Pair(5, 8), Pair(5, 8), Pair(4, 6), Pair(5, 9), Pair(1, 12), Pair(6, 8), Pair(0, 5), Pair(4, 4),
        Pair(0, 12), Pair(5, 7), Pair(2, 8), Pair(6, 8), Pair(18, 9), Pair(5, -2), Pair(15, 2), Pair(5, 3),
        Pair(2, 8), Pair(6, 11), Pair(3, 8), Pair(-8, 6), Pair(11, 11), Pair(2, 1), Pair(11, 5), Pair(-2, 5),
        Pair(1, 12), Pair(2, 12), Pair(1, 8), Pair(-7, 10), Pair(11, 20), Pair(6, -3), Pair(12, 17), Pair(1, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(49, -30), Pair(112, 9), Pair(-6, 57), Pair(24, 55), Pair(51, 25), Pair(56, 13), Pair(-35, -23), Pair(-23, -62),
        Pair(8, 29), Pair(21, 30), Pair(-13, 31), Pair(32, 9), Pair(27, 30), Pair(10, 20), Pair(73, 17), Pair(-103, 27),
        Pair(18, 25), Pair(17, 23), Pair(31, 22), Pair(13, 24), Pair(18, 34), Pair(18, 27), Pair(32, 31), Pair(-51, 30),
        Pair(-17, 45), Pair(21, 32), Pair(25, 22), Pair(15, 44), Pair(26, 24), Pair(2, 25), Pair(2, 35), Pair(0, 38),
        Pair(8, 38), Pair(26, 33), Pair(21, 33), Pair(23, 28), Pair(30, 39), Pair(7, 35), Pair(5, 29), Pair(-7, 9),
        Pair(17, 26), Pair(15, 26), Pair(14, 33), Pair(15, 38), Pair(15, 33), Pair(0, 0), Pair(8, 23), Pair(-3, 22),
        Pair(12, 24), Pair(7, 32), Pair(12, 30), Pair(7, 26), Pair(9, 38), Pair(12, 49), Pair(16, 50), Pair(-21, 18),
        Pair(-51, 33), Pair(-9, 33), Pair(-2, 30), Pair(9, 41), Pair(-3, 39), Pair(-9, 32), Pair(-6, 4), Pair(3, 22)
      },
      { // Piece 2
        Pair(-5, 3), Pair(41, 11), Pair(-44, 22), Pair(87, -5), Pair(37, -7), Pair(34, 27), Pair(22, -11), Pair(122, -20),
        Pair(-18, 15), Pair(6, -3), Pair(48, 1), Pair(54, -13), Pair(52, 10), Pair(-8, 16), Pair(66, -5), Pair(29, -3),
        Pair(3, 5), Pair(26, 9), Pair(21, 3), Pair(40, -1), Pair(3, -10), Pair(50, -14), Pair(56, -21), Pair(11, 22),
        Pair(23, 23), Pair(16, 0), Pair(6, 13), Pair(15, -2), Pair(23, 20), Pair(23, -6), Pair(16, 15), Pair(-25, 1),
        Pair(-2, 15), Pair(15, 24), Pair(12, -2), Pair(21, 20), Pair(47, 1), Pair(6, 19), Pair(-14, 38), Pair(9, 33),
        Pair(18, 29), Pair(6, 14), Pair(25, 16), Pair(3, 22), Pair(20, 25), Pair(0, 0), Pair(11, 24), Pair(-3, 26),
        Pair(14, -10), Pair(16, 23), Pair(10, 6), Pair(12, 30), Pair(4, 5), Pair(35, 22), Pair(-17, -12), Pair(28, 18),
        Pair(12, 6), Pair(1, 6), Pair(11, 38), Pair(-27, 18), Pair(49, 16), Pair(1, 9), Pair(52, -25), Pair(-25, -91)
      },
      { // Piece 3
        Pair(28, 30), Pair(42, 17), Pair(64, 11), Pair(34, 16), Pair(18, 26), Pair(140, -7), Pair(4, 31), Pair(100, 4),
        Pair(21, 27), Pair(27, 26), Pair(21, 23), Pair(41, 17), Pair(20, 33), Pair(78, -10), Pair(-11, 32), Pair(27, 8),
        Pair(20, 30), Pair(20, 33), Pair(26, 27), Pair(24, 29), Pair(17, 24), Pair(17, 31), Pair(0, 22), Pair(35, 27),
        Pair(23, 25), Pair(26, 30), Pair(16, 20), Pair(35, 23), Pair(29, 19), Pair(41, 14), Pair(23, 25), Pair(38, 11),
        Pair(24, 33), Pair(6, 29), Pair(-1, 37), Pair(25, 29), Pair(31, 35), Pair(6, 18), Pair(15, 45), Pair(4, 37),
        Pair(23, 24), Pair(-16, 33), Pair(22, 17), Pair(14, 17), Pair(2, 37), Pair(0, 0), Pair(-8, 33), Pair(-18, 3),
        Pair(-2, 36), Pair(18, 21), Pair(21, 29), Pair(16, 30), Pair(6, 26), Pair(7, 15), Pair(3, 26), Pair(-31, 46),
        Pair(16, 24), Pair(18, 28), Pair(13, 32), Pair(16, 27), Pair(6, 32), Pair(4, 10), Pair(-3, 36), Pair(9, 20)
      },
      { // Piece 4
        Pair(-25, 67), Pair(21, 32), Pair(54, -6), Pair(-73, 94), Pair(-61, 86), Pair(12, 4), Pair(-74, 63), Pair(-32, 48),
        Pair(-20, 59), Pair(12, 6), Pair(-5, 28), Pair(-7, 62), Pair(-22, 59), Pair(12, -1), Pair(10, 39), Pair(-43, 43),
        Pair(-9, 54), Pair(0, 37), Pair(1, 27), Pair(-4, 60), Pair(-25, 59), Pair(-51, 80), Pair(-17, 56), Pair(-11, 29),
        Pair(-9, 43), Pair(-23, 78), Pair(-14, 57), Pair(-6, 40), Pair(-29, 86), Pair(-15, 37), Pair(8, 2), Pair(-49, 63),
        Pair(1, 73), Pair(-8, 54), Pair(3, 20), Pair(-15, 57), Pair(14, 39), Pair(-14, 46), Pair(-12, 43), Pair(-26, 37),
        Pair(-1, 14), Pair(2, 54), Pair(4, 38), Pair(0, 32), Pair(-7, 48), Pair(0, 0), Pair(-22, 31), Pair(-18, 0),
        Pair(-22, 65), Pair(1, 42), Pair(4, 25), Pair(11, 31), Pair(-1, 33), Pair(-7, 40), Pair(-8, 47), Pair(10, 19),
        Pair(-17, 61), Pair(-22, 98), Pair(4, 23), Pair(-1, 39), Pair(-7, 41), Pair(25, -27), Pair(27, 34), Pair(-5, -29)
      },
      { // Piece 5
        Pair(-87, 89), Pair(-27, -73), Pair(130, 70), Pair(29, 39), Pair(80, -46), Pair(71, 41), Pair(-44, 37), Pair(62, -27),
        Pair(4, 46), Pair(-85, 21), Pair(4, 0), Pair(139, 1), Pair(0, 93), Pair(128, -5), Pair(-21, 38), Pair(-190, -9),
        Pair(61, -9), Pair(-52, 13), Pair(-85, 23), Pair(-111, 38), Pair(92, -3), Pair(174, 17), Pair(-86, 44), Pair(58, -4),
        Pair(-32, 20), Pair(-1, -2), Pair(-61, 20), Pair(-84, 29), Pair(-66, 32), Pair(-56, 31), Pair(4, 12), Pair(27, -10),
        Pair(-153, 28), Pair(49, -11), Pair(-8, 5), Pair(-10, 7), Pair(-36, -5), Pair(13, -1), Pair(31, -29), Pair(61, -8),
        Pair(-37, 3), Pair(-29, 4), Pair(-3, 1), Pair(-17, 9), Pair(15, -2), Pair(0, 0), Pair(5, -14), Pair(37, -7),
        Pair(-23, -9), Pair(10, -8), Pair(18, -5), Pair(-6, -3), Pair(0, 1), Pair(-64, 22), Pair(-6, 0), Pair(17, -10),
        Pair(-12, -7), Pair(-1, -16), Pair(3, -15), Pair(-5, -12), Pair(-12, -1), Pair(-36, 2), Pair(-4, 0), Pair(31, -22)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-30, 22), Pair(9, 0), Pair(16, -3), Pair(-6, 1), Pair(17, 6), Pair(-24, 13), Pair(4, -12), Pair(7, 2),
        Pair(-6, 13), Pair(4, 13), Pair(-5, 16), Pair(-1, 5), Pair(-4, 10), Pair(-1, 4), Pair(8, -6), Pair(6, 5),
        Pair(2, 10), Pair(5, 8), Pair(-2, 9), Pair(2, 4), Pair(1, 9), Pair(-10, 6), Pair(2, -1), Pair(2, 7),
        Pair(1, 11), Pair(1, 14), Pair(2, 11), Pair(1, 8), Pair(3, 11), Pair(11, 5), Pair(-1, -6), Pair(7, -4),
        Pair(1, 15), Pair(3, 14), Pair(1, 10), Pair(1, 11), Pair(1, 7), Pair(10, 5), Pair(1, 0), Pair(-1, 3),
        Pair(0, 12), Pair(3, 14), Pair(-1, 11), Pair(3, 9), Pair(1, 10), Pair(15, 18), Pair(-12, -6), Pair(2, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(7, 31), Pair(97, -9), Pair(102, 14), Pair(61, 1), Pair(-57, 45), Pair(61, -1), Pair(82, 5), Pair(148, 27),
        Pair(-26, 57), Pair(-8, 28), Pair(25, 16), Pair(8, 28), Pair(-6, 41), Pair(10, 14), Pair(14, 10), Pair(3, 28),
        Pair(-24, 35), Pair(-12, 42), Pair(-4, 43), Pair(8, 33), Pair(11, 27), Pair(-14, 40), Pair(-2, 26), Pair(24, 10),
        Pair(5, 26), Pair(10, 33), Pair(11, 29), Pair(15, 39), Pair(1, 45), Pair(12, 29), Pair(9, 23), Pair(-19, 39),
        Pair(3, 30), Pair(2, 35), Pair(3, 36), Pair(7, 38), Pair(7, 35), Pair(9, 27), Pair(1, 35), Pair(4, 9),
        Pair(-3, 23), Pair(3, 30), Pair(3, 33), Pair(7, 38), Pair(6, 32), Pair(3, 35), Pair(0, 0), Pair(-7, 20),
        Pair(-9, 28), Pair(-12, 39), Pair(0, 34), Pair(4, 37), Pair(-13, 32), Pair(-2, 31), Pair(-2, 55), Pair(-7, 25),
        Pair(-37, 84), Pair(-9, 29), Pair(12, 6), Pair(3, 41), Pair(-8, 25), Pair(-3, 18), Pair(5, -1), Pair(-53, 90)
      },
      { // Piece 2
        Pair(-40, 6), Pair(0, 8), Pair(-24, 34), Pair(115, -22), Pair(-2, 9), Pair(44, -10), Pair(51, -6), Pair(-16, 8),
        Pair(-4, 6), Pair(3, 21), Pair(-18, 9), Pair(46, -12), Pair(19, -4), Pair(25, 17), Pair(-3, 15), Pair(-19, 38),
        Pair(10, 23), Pair(29, 1), Pair(35, 10), Pair(10, 9), Pair(14, 12), Pair(-25, 13), Pair(28, 18), Pair(3, -4),
        Pair(9, 11), Pair(11, 28), Pair(-6, 8), Pair(21, 17), Pair(-15, 23), Pair(13, 18), Pair(0, 2), Pair(10, 22),
        Pair(4, 13), Pair(6, 14), Pair(13, 21), Pair(8, 15), Pair(14, 34), Pair(-19, 18), Pair(7, 32), Pair(33, -28),
        Pair(3, 12), Pair(4, 16), Pair(-1, 15), Pair(6, 38), Pair(1, 18), Pair(12, 24), Pair(0, 0), Pair(14, 19),
        Pair(4, 16), Pair(-1, 12), Pair(4, 17), Pair(1, 12), Pair(-2, 36), Pair(13, 0), Pair(15, 43), Pair(-66, -58),
        Pair(15, 5), Pair(2, 29), Pair(-3, 15), Pair(-6, 39), Pair(7, 14), Pair(10, 23), Pair(23, -16), Pair(13, 14)
      },
      { // Piece 3
        Pair(4, 45), Pair(9, 36), Pair(83, 13), Pair(23, 28), Pair(-27, 51), Pair(-14, 42), Pair(31, 13), Pair(39, 33),
        Pair(29, 32), Pair(6, 40), Pair(21, 34), Pair(23, 37), Pair(29, 36), Pair(32, 25), Pair(94, -6), Pair(6, 38),
        Pair(14, 37), Pair(18, 32), Pair(15, 42), Pair(16, 29), Pair(30, 29), Pair(-18, 36), Pair(96, 0), Pair(-3, 43),
        Pair(10, 38), Pair(10, 35), Pair(0, 41), Pair(20, 25), Pair(19, 39), Pair(-1, 39), Pair(15, 30), Pair(-14, 49),
        Pair(7, 39), Pair(10, 42), Pair(1, 38), Pair(13, 37), Pair(6, 39), Pair(28, 40), Pair(12, 11), Pair(9, 42),
        Pair(1, 46), Pair(8, 30), Pair(-3, 40), Pair(3, 34), Pair(13, 37), Pair(-10, 49), Pair(0, 0), Pair(-3, 8),
        Pair(6, 42), Pair(2, 45), Pair(7, 37), Pair(7, 39), Pair(12, 35), Pair(-4, 38), Pair(-4, -1), Pair(-23, 35),
        Pair(10, 30), Pair(19, 27), Pair(14, 27), Pair(9, 34), Pair(11, 33), Pair(6, 32), Pair(-16, -2), Pair(-9, 32)
      },
      { // Piece 4
        Pair(27, 42), Pair(-3, 29), Pair(26, 45), Pair(24, 32), Pair(-13, 71), Pair(39, 0), Pair(52, -5), Pair(46, -1),
        Pair(-2, 54), Pair(7, 43), Pair(-4, 43), Pair(-40, 100), Pair(19, 51), Pair(49, 5), Pair(72, -38), Pair(4, 38),
        Pair(8, 55), Pair(-2, 61), Pair(-2, 56), Pair(5, 66), Pair(1, 51), Pair(54, 15), Pair(30, 45), Pair(-2, 18),
        Pair(9, 50), Pair(-1, 72), Pair(-6, 67), Pair(9, 57), Pair(8, 51), Pair(-12, 68), Pair(5, 38), Pair(3, 23),
        Pair(18, 37), Pair(19, 38), Pair(3, 68), Pair(5, 45), Pair(13, 35), Pair(-10, 59), Pair(4, 36), Pair(-29, 50),
        Pair(15, 40), Pair(19, 64), Pair(10, 65), Pair(12, 47), Pair(14, 55), Pair(2, 61), Pair(0, 0), Pair(7, -36),
        Pair(32, 29), Pair(10, 58), Pair(15, 58), Pair(15, 61), Pair(13, 50), Pair(7, 31), Pair(-6, 31), Pair(-16, -2),
        Pair(12, 75), Pair(16, 50), Pair(3, 63), Pair(9, 68), Pair(1, 62), Pair(4, 48), Pair(0, 39), Pair(-48, 78)
      },
      { // Piece 5
        Pair(-46, 60), Pair(-38, 49), Pair(-32, -11), Pair(-13, 22), Pair(-46, 41), Pair(-230, 15), Pair(-41, 33), Pair(-85, 87),
        Pair(-96, -6), Pair(-169, 87), Pair(-143, 25), Pair(-155, 50), Pair(-50, 62), Pair(-193, 64), Pair(103, 35), Pair(-30, 31),
        Pair(-95, -2), Pair(-1, -5), Pair(-108, 19), Pair(-140, 41), Pair(1, 17), Pair(36, 30), Pair(28, 59), Pair(-120, 57),
        Pair(45, -18), Pair(-174, 38), Pair(-99, 31), Pair(-39, 26), Pair(4, 25), Pair(6, 31), Pair(-2, 40), Pair(25, 32),
        Pair(-50, 19), Pair(-44, 20), Pair(-24, 15), Pair(-45, 25), Pair(18, 15), Pair(-43, 0), Pair(29, 7), Pair(-47, -7),
        Pair(-46, -10), Pair(-42, 19), Pair(-30, 23), Pair(-36, 16), Pair(15, 11), Pair(-12, 3), Pair(0, 0), Pair(16, -19),
        Pair(-33, 2), Pair(-44, 18), Pair(-55, 24), Pair(-19, 10), Pair(0, 2), Pair(-23, 1), Pair(-2, -2), Pair(-13, -9),
        Pair(-57, 7), Pair(-41, 10), Pair(-32, 10), Pair(-24, -7), Pair(5, -14), Pair(-17, 0), Pair(11, -7), Pair(-28, -9)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 15), Pair(8, 13), Pair(12, 12), Pair(-8, 5), Pair(10, -7), Pair(-6, -3), Pair(1, 0), Pair(12, 11),
        Pair(-4, 16), Pair(2, 12), Pair(0, 9), Pair(5, 8), Pair(-8, 9), Pair(-7, 11), Pair(-5, 12), Pair(7, -9),
        Pair(-1, 13), Pair(0, 13), Pair(5, 7), Pair(3, 6), Pair(0, 5), Pair(-3, 9), Pair(-3, 11), Pair(15, 4),
        Pair(-3, 12), Pair(3, 12), Pair(3, 10), Pair(1, 7), Pair(1, 7), Pair(1, 5), Pair(8, 2), Pair(3, 7),
        Pair(1, 15), Pair(0, 11), Pair(0, 10), Pair(1, 9), Pair(6, 8), Pair(1, 4), Pair(-3, 1), Pair(-5, -13),
        Pair(-2, 14), Pair(-2, 12), Pair(0, 12), Pair(1, 4), Pair(6, 9), Pair(-5, 7), Pair(9, 15), Pair(-10, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(39, -33), Pair(-23, 40), Pair(-135, 93), Pair(-3, 18), Pair(96, -21), Pair(12, 15), Pair(-4, 18), Pair(-8, 21),
        Pair(-5, 14), Pair(-15, 20), Pair(-16, 34), Pair(-4, 38), Pair(10, 34), Pair(32, 17), Pair(-56, 53), Pair(-6, 7),
        Pair(-19, 45), Pair(-7, 38), Pair(-2, 32), Pair(11, 19), Pair(5, 41), Pair(32, 6), Pair(-2, 23), Pair(34, 15),
        Pair(-13, 36), Pair(0, 36), Pair(-2, 32), Pair(15, 33), Pair(6, 32), Pair(14, 28), Pair(7, 35), Pair(-10, 36),
        Pair(-13, 49), Pair(-2, 37), Pair(14, 30), Pair(11, 26), Pair(3, 38), Pair(3, 35), Pair(-1, 29), Pair(-10, 26),
        Pair(-6, 25), Pair(-1, 32), Pair(-1, 31), Pair(-1, 41), Pair(-1, 39), Pair(-2, 37), Pair(4, 22), Pair(0, 0),
        Pair(-20, 43), Pair(-10, 32), Pair(-7, 25), Pair(-3, 36), Pair(-3, 35), Pair(-3, 30), Pair(-4, 25), Pair(-6, 30),
        Pair(-30, 55), Pair(-16, 23), Pair(-22, 40), Pair(-33, 50), Pair(-14, 30), Pair(-13, 28), Pair(-5, 25), Pair(-47, 22)
      },
      { // Piece 2
        Pair(25, 9), Pair(9, 16), Pair(-41, 6), Pair(10, 15), Pair(114, -20), Pair(53, 23), Pair(-39, 13), Pair(-97, 50),
        Pair(6, 23), Pair(11, 7), Pair(22, 7), Pair(56, -26), Pair(20, 6), Pair(10, 17), Pair(-22, 36), Pair(-1, 10),
        Pair(11, 13), Pair(33, 17), Pair(13, 5), Pair(-5, 21), Pair(-8, 13), Pair(10, 11), Pair(35, 8), Pair(10, 24),
        Pair(1, 16), Pair(2, 12), Pair(3, 20), Pair(11, 10), Pair(8, 33), Pair(28, 1), Pair(-4, 30), Pair(-2, 2),
        Pair(-8, 15), Pair(3, 23), Pair(16, 5), Pair(14, 24), Pair(7, 18), Pair(-4, 27), Pair(6, 39), Pair(11, 18),
        Pair(-5, 29), Pair(-1, 14), Pair(6, 26), Pair(4, 19), Pair(6, 34), Pair(-3, 20), Pair(6, 25), Pair(0, 0),
        Pair(29, -24), Pair(3, 27), Pair(4, 19), Pair(4, 27), Pair(-9, 33), Pair(16, 33), Pair(7, 19), Pair(3, 53),
        Pair(12, 27), Pair(-9, 10), Pair(2, 24), Pair(-2, 18), Pair(15, 25), Pair(-1, 16), Pair(12, 26), Pair(19, -9)
      },
      { // Piece 3
        Pair(7, 44), Pair(1, 41), Pair(48, 22), Pair(1, 41), Pair(12, 43), Pair(94, 12), Pair(90, 26), Pair(49, 8),
        Pair(11, 50), Pair(17, 46), Pair(33, 36), Pair(26, 41), Pair(41, 24), Pair(41, 31), Pair(3, 42), Pair(64, 0),
        Pair(7, 51), Pair(24, 43), Pair(16, 43), Pair(31, 39), Pair(45, 30), Pair(49, 36), Pair(17, 39), Pair(32, 14),
        Pair(7, 47), Pair(33, 43), Pair(11, 40), Pair(22, 41), Pair(25, 30), Pair(23, 46), Pair(1, 44), Pair(9, 25),
        Pair(10, 45), Pair(-2, 44), Pair(0, 55), Pair(25, 35), Pair(14, 50), Pair(3, 39), Pair(9, 56), Pair(13, 17),
        Pair(24, 41), Pair(9, 41), Pair(22, 36), Pair(8, 38), Pair(7, 47), Pair(11, 27), Pair(4, 38), Pair(0, 0),
        Pair(-1, 49), Pair(-10, 46), Pair(6, 45), Pair(4, 47), Pair(0, 49), Pair(-7, 53), Pair(8, 30), Pair(-80, 45),
        Pair(11, 33), Pair(16, 29), Pair(12, 33), Pair(13, 35), Pair(16, 33), Pair(17, 38), Pair(-4, 36), Pair(-26, 2)
      },
      { // Piece 4
        Pair(36, 26), Pair(35, 28), Pair(38, 29), Pair(10, 55), Pair(8, 74), Pair(-94, 119), Pair(-17, 92), Pair(45, 27),
        Pair(12, 55), Pair(7, 41), Pair(11, 41), Pair(-17, 58), Pair(11, 41), Pair(13, 71), Pair(0, 67), Pair(7, 31),
        Pair(13, 52), Pair(-14, 80), Pair(26, 37), Pair(27, 48), Pair(29, 42), Pair(27, 44), Pair(-10, 139), Pair(5, 60),
        Pair(8, 23), Pair(25, 27), Pair(25, 42), Pair(-8, 70), Pair(8, 57), Pair(24, 64), Pair(19, 72), Pair(13, 40),
        Pair(21, 28), Pair(4, 56), Pair(30, 35), Pair(6, 53), Pair(-3, 73), Pair(-5, 66), Pair(23, 33), Pair(-7, 46),
        Pair(15, 50), Pair(19, 52), Pair(7, 84), Pair(16, 43), Pair(12, 68), Pair(10, 57), Pair(6, 56), Pair(0, 0),
        Pair(23, 45), Pair(5, 81), Pair(9, 71), Pair(13, 54), Pair(12, 45), Pair(13, 40), Pair(17, 35), Pair(-38, 80),
        Pair(15, 60), Pair(-3, 60), Pair(4, 56), Pair(11, 63), Pair(15, 47), Pair(51, 1), Pair(-22, 73), Pair(9, -65)
      },
      { // Piece 5
        Pair(-29, -28), Pair(-180, -78), Pair(35, 2), Pair(-97, -39), Pair(-40, 35), Pair(96, 74), Pair(32, -19), Pair(-42, 55),
        Pair(6, -8), Pair(46, 35), Pair(12, 18), Pair(-24, 50), Pair(-156, 54), Pair(181, 35), Pair(28, 25), Pair(-159, 40),
        Pair(3, -7), Pair(-59, 39), Pair(-2, 17), Pair(32, 15), Pair(32, 19), Pair(-57, 60), Pair(-118, 70), Pair(-111, 46),
        Pair(-84, 34), Pair(-39, 17), Pair(-96, 35), Pair(-149, 37), Pair(-120, 38), Pair(52, 18), Pair(23, 20), Pair(-8, 10),
        Pair(2, -4), Pair(-36, 26), Pair(-80, 30), Pair(-31, 24), Pair(-3, 21), Pair(35, 11), Pair(-19, -8), Pair(-37, -5),
        Pair(-122, 33), Pair(-36, 15), Pair(-56, 27), Pair(-25, 22), Pair(-4, 12), Pair(-2, 12), Pair(-50, -5), Pair(0, 0),
        Pair(-55, 7), Pair(-44, 22), Pair(-19, 24), Pair(-33, 18), Pair(-7, 6), Pair(-27, 10), Pair(-32, -7), Pair(-21, -25),
        Pair(-33, -5), Pair(-36, 18), Pair(-38, 18), Pair(-36, 3), Pair(0, -11), Pair(0, -4), Pair(10, -4), Pair(13, -33)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(39, 1), Pair(-18, 22), Pair(-19, 21), Pair(-11, 13), Pair(-2, 12), Pair(-24, 7), Pair(13, 9), Pair(-8, 30),
        Pair(-19, 30), Pair(-14, 20), Pair(-5, 19), Pair(-8, 16), Pair(-3, 13), Pair(-1, 7), Pair(-6, 5), Pair(-4, 14),
        Pair(9, 7), Pair(-3, 9), Pair(3, 7), Pair(-4, 13), Pair(0, 9), Pair(0, 15), Pair(1, 7), Pair(-4, 14),
        Pair(7, 6), Pair(-3, 14), Pair(1, 9), Pair(-1, 9), Pair(1, 8), Pair(-1, 8), Pair(-2, 14), Pair(-4, 14),
        Pair(3, -1), Pair(4, 19), Pair(-2, 7), Pair(-2, 10), Pair(-2, 7), Pair(-1, 11), Pair(2, 13), Pair(-1, 17),
        Pair(-2, 1), Pair(-4, 5), Pair(-7, 9), Pair(-1, 8), Pair(-3, 13), Pair(-7, 16), Pair(2, 15), Pair(-2, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-83, -2), Pair(-43, 21), Pair(-97, 45), Pair(-40, 58), Pair(-96, 80), Pair(-26, 27), Pair(-117, 17), Pair(15, -96),
        Pair(18, 9), Pair(-13, 34), Pair(-31, 48), Pair(-10, 48), Pair(5, 30), Pair(12, 40), Pair(7, 87), Pair(-17, 32),
        Pair(33, 34), Pair(-25, 45), Pair(-8, 38), Pair(0, 42), Pair(1, 36), Pair(-40, 65), Pair(-8, 50), Pair(-4, 20),
        Pair(6, 25), Pair(0, 45), Pair(-1, 43), Pair(-1, 47), Pair(2, 52), Pair(-8, 58), Pair(-1, 47), Pair(-5, 48),
        Pair(6, 38), Pair(14, 36), Pair(4, 39), Pair(2, 41), Pair(3, 51), Pair(8, 47), Pair(-7, 35), Pair(3, 32),
        Pair(-11, 17), Pair(7, 35), Pair(7, 39), Pair(3, 47), Pair(6, 48), Pair(3, 39), Pair(3, 49), Pair(6, 26),
        Pair(0, 0), Pair(1, 32), Pair(-6, 37), Pair(-4, 49), Pair(4, 35), Pair(-7, 52), Pair(-6, 49), Pair(-2, 44),
        Pair(12, 3), Pair(-5, -6), Pair(24, 20), Pair(4, 44), Pair(0, 53), Pair(-8, 46), Pair(-2, 13), Pair(38, 10)
      },
      { // Piece 2
        Pair(8, 15), Pair(-4, 23), Pair(62, -23), Pair(16, -3), Pair(62, -9), Pair(38, -51), Pair(-57, 11), Pair(-40, 9),
        Pair(23, 8), Pair(10, 29), Pair(8, 18), Pair(44, -11), Pair(16, -19), Pair(33, 0), Pair(-29, 21), Pair(-18, 52),
        Pair(-4, 31), Pair(11, 22), Pair(23, 18), Pair(19, 21), Pair(31, 2), Pair(1, 6), Pair(-15, 35), Pair(1, 30),
        Pair(2, 35), Pair(12, 28), Pair(3, 26), Pair(17, 11), Pair(10, 17), Pair(14, 14), Pair(9, 26), Pair(-9, 33),
        Pair(-1, 34), Pair(24, 11), Pair(10, 16), Pair(14, 18), Pair(10, 37), Pair(3, 31), Pair(9, 26), Pair(-3, 45),
        Pair(-5, 17), Pair(13, 38), Pair(10, 14), Pair(3, 35), Pair(6, 37), Pair(8, 41), Pair(2, 43), Pair(9, 40),
        Pair(0, 0), Pair(5, 24), Pair(11, 26), Pair(0, 34), Pair(6, 37), Pair(3, 39), Pair(6, 38), Pair(8, 35),
        Pair(3, 33), Pair(-8, 24), Pair(1, 39), Pair(12, 26), Pair(12, 21), Pair(-3, 43), Pair(10, 15), Pair(0, 29)
      },
      { // Piece 3
        Pair(-61, 52), Pair(-8, 50), Pair(-2, 55), Pair(-29, 60), Pair(-6, 59), Pair(-66, 69), Pair(33, 58), Pair(-22, 72),
        Pair(-52, 47), Pair(-19, 59), Pair(-17, 60), Pair(-11, 55), Pair(-32, 61), Pair(-19, 45), Pair(-35, 69), Pair(12, 41),
        Pair(-31, 54), Pair(-9, 63), Pair(-19, 62), Pair(-3, 58), Pair(-10, 54), Pair(-18, 58), Pair(1, 53), Pair(16, 54),
        Pair(-26, 52), Pair(-10, 64), Pair(-15, 64), Pair(0, 53), Pair(-10, 66), Pair(-6, 72), Pair(-1, 67), Pair(0, 45),
        Pair(-19, 56), Pair(12, 52), Pair(-11, 55), Pair(-6, 66), Pair(-8, 64), Pair(-14, 60), Pair(-7, 56), Pair(11, 64),
        Pair(-25, 25), Pair(-7, 52), Pair(13, 38), Pair(-4, 61), Pair(-3, 52), Pair(-13, 57), Pair(-3, 65), Pair(16, 40),
        Pair(0, 0), Pair(-12, 67), Pair(-1, 55), Pair(7, 52), Pair(-5, 50), Pair(-6, 53), Pair(-3, 44), Pair(4, 47),
        Pair(-30, 30), Pair(-11, 53), Pair(-7, 58), Pair(-5, 57), Pair(-5, 53), Pair(-7, 51), Pair(-4, 52), Pair(5, 47)
      },
      { // Piece 4
        Pair(39, 72), Pair(-8, 85), Pair(28, 31), Pair(-8, 81), Pair(-43, 107), Pair(13, 109), Pair(2, 91), Pair(-9, 105),
        Pair(-15, 87), Pair(-6, 91), Pair(0, 87), Pair(-19, 120), Pair(22, 70), Pair(-12, 95), Pair(8, 22), Pair(10, 63),
        Pair(-17, 119), Pair(14, 50), Pair(6, 114), Pair(-7, 106), Pair(7, 91), Pair(-27, 124), Pair(-12, 93), Pair(1, 75),
        Pair(-5, 118), Pair(-5, 123), Pair(0, 111), Pair(13, 79), Pair(24, 64), Pair(15, 76), Pair(-2, 96), Pair(1, 118),
        Pair(-10, 107), Pair(15, 74), Pair(11, 89), Pair(8, 93), Pair(7, 108), Pair(8, 98), Pair(12, 90), Pair(23, 40),
        Pair(4, 72), Pair(19, 86), Pair(5, 111), Pair(9, 91), Pair(3, 121), Pair(11, 111), Pair(7, 102), Pair(22, 46),
        Pair(0, 0), Pair(16, 82), Pair(12, 94), Pair(13, 101), Pair(9, 99), Pair(19, 99), Pair(21, 86), Pair(13, 75),
        Pair(7, 71), Pair(-7, 113), Pair(6, 106), Pair(8, 107), Pair(4, 96), Pair(29, 65), Pair(-11, 114), Pair(26, 127)
      },
      { // Piece 5
        Pair(-44, 17), Pair(-39, 102), Pair(-80, 14), Pair(76, 32), Pair(79, -35), Pair(90, 28), Pair(-33, 37), Pair(-39, 10),
        Pair(50, 55), Pair(9, 143), Pair(-119, 77), Pair(90, 26), Pair(-111, 18), Pair(145, 36), Pair(-184, 57), Pair(-44, -31),
        Pair(-138, 50), Pair(-38, 63), Pair(-2, 38), Pair(-133, 57), Pair(-39, 28), Pair(-194, 49), Pair(-150, 41), Pair(-267, 38),
        Pair(-171, 60), Pair(-151, 76), Pair(-60, 55), Pair(-194, 74), Pair(-35, 41), Pair(-86, 23), Pair(-107, 23), Pair(-108, 26),
        Pair(-58, 5), Pair(-51, 27), Pair(-65, 25), Pair(-25, 37), Pair(-43, 32), Pair(18, 3), Pair(-46, 21), Pair(-104, 23),
        Pair(-40, -18), Pair(-26, -2), Pair(16, 9), Pair(-41, 26), Pair(-68, 36), Pair(-35, 25), Pair(-34, 17), Pair(-22, -6),
        Pair(0, 0), Pair(2, -1), Pair(24, -13), Pair(9, 4), Pair(-7, 11), Pair(-21, 17), Pair(-12, 11), Pair(-15, 0),
        Pair(-5, -67), Pair(44, -29), Pair(53, -20), Pair(0, -10), Pair(2, -1), Pair(-10, 9), Pair(-6, 5), Pair(-8, -5)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-6, 21), Pair(-18, 14), Pair(-6, 13), Pair(-13, 14), Pair(8, -11), Pair(19, 2), Pair(24, 5), Pair(-7, 21),
        Pair(-9, 16), Pair(2, -7), Pair(-12, 17), Pair(-6, 10), Pair(8, -2), Pair(1, 7), Pair(-2, 13), Pair(-4, 3),
        Pair(-6, 12), Pair(5, 4), Pair(-5, 10), Pair(3, 7), Pair(3, 8), Pair(3, 8), Pair(2, 11), Pair(3, 9),
        Pair(-4, 10), Pair(-1, 6), Pair(1, 10), Pair(4, 6), Pair(2, 11), Pair(3, 11), Pair(3, 16), Pair(-1, 11),
        Pair(-4, 11), Pair(-1, -6), Pair(7, 22), Pair(0, 7), Pair(-1, 12), Pair(2, 12), Pair(2, 11), Pair(3, 13),
        Pair(-5, 6), Pair(2, 9), Pair(3, 11), Pair(1, -36), Pair(-2, 11), Pair(1, 15), Pair(1, 16), Pair(0, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-19, 69), Pair(23, 54), Pair(-81, 93), Pair(-31, 47), Pair(-36, 48), Pair(-69, 34), Pair(-16, 122), Pair(-148, 147),
        Pair(19, 5), Pair(4, 17), Pair(-19, 40), Pair(-14, 34), Pair(-62, 59), Pair(-29, 62), Pair(-37, 39), Pair(-14, 32),
        Pair(-38, 49), Pair(4, 34), Pair(-4, 51), Pair(-12, 38), Pair(-13, 47), Pair(-18, 38), Pair(-40, 43), Pair(-41, 75),
        Pair(16, 21), Pair(6, 33), Pair(-5, 43), Pair(-2, 41), Pair(-4, 44), Pair(-22, 37), Pair(-9, 54), Pair(-17, 51),
        Pair(-5, 37), Pair(12, 34), Pair(4, 39), Pair(3, 34), Pair(-7, 39), Pair(3, 37), Pair(-16, 54), Pair(-4, 51),
        Pair(12, 36), Pair(1, 32), Pair(11, 36), Pair(8, 33), Pair(2, 48), Pair(1, 42), Pair(3, 36), Pair(8, 33),
        Pair(-21, 52), Pair(0, 0), Pair(0, 36), Pair(0, 37), Pair(2, 45), Pair(5, 41), Pair(4, 21), Pair(1, 30),
        Pair(-18, 57), Pair(1, 40), Pair(-1, 36), Pair(-11, 64), Pair(-10, 51), Pair(-5, 41), Pair(3, 31), Pair(-4, -46)
      },
      { // Piece 2
        Pair(0, 31), Pair(-42, 48), Pair(-57, 30), Pair(-26, 17), Pair(19, 3), Pair(-22, -2), Pair(4, 20), Pair(-82, -4),
        Pair(4, 13), Pair(0, 16), Pair(-2, 19), Pair(-14, 33), Pair(2, 10), Pair(29, 0), Pair(29, -10), Pair(5, 26),
        Pair(-15, 37), Pair(4, 27), Pair(2, 18), Pair(-7, 22), Pair(7, 10), Pair(2, 11), Pair(-1, 22), Pair(-9, 20),
        Pair(-9, 33), Pair(0, 18), Pair(-3, 18), Pair(3, 27), Pair(3, 18), Pair(10, 20), Pair(-4, 11), Pair(-18, 28),
        Pair(15, 4), Pair(0, 23), Pair(7, 21), Pair(-3, 26), Pair(-2, 31), Pair(3, 30), Pair(11, 26), Pair(0, 24),
        Pair(-20, 15), Pair(-5, 13), Pair(7, 41), Pair(-1, 28), Pair(1, 29), Pair(4, 42), Pair(3, 37), Pair(0, 30),
        Pair(4, 38), Pair(0, 0), Pair(7, 24), Pair(0, 45), Pair(1, 31), Pair(7, 28), Pair(0, 38), Pair(-6, 42),
        Pair(0, 0), Pair(4, 36), Pair(-7, 12), Pair(10, 30), Pair(4, 43), Pair(-2, 37), Pair(5, 38), Pair(24, -4)
      },
      { // Piece 3
        Pair(-27, 54), Pair(-24, 36), Pair(7, 25), Pair(-15, 34), Pair(-16, 39), Pair(-14, 58), Pair(55, 9), Pair(-14, 45),
        Pair(-3, 36), Pair(-14, 28), Pair(-22, 46), Pair(-10, 43), Pair(-3, 44), Pair(-61, 70), Pair(-30, 55), Pair(17, 31),
        Pair(-15, 44), Pair(-11, 29), Pair(-8, 33), Pair(-4, 35), Pair(0, 39), Pair(-28, 40), Pair(13, 33), Pair(6, 32),
        Pair(-9, 46), Pair(-12, 34), Pair(-11, 52), Pair(-16, 48), Pair(-5, 37), Pair(1, 34), Pair(-2, 25), Pair(-4, 39),
        Pair(-9, 36), Pair(-4, 39), Pair(-13, 55), Pair(15, 36), Pair(-11, 58), Pair(-11, 41), Pair(-2, 44), Pair(10, 23),
        Pair(-5, 21), Pair(-20, 17), Pair(10, 34), Pair(3, 36), Pair(-7, 45), Pair(-13, 50), Pair(-5, 44), Pair(19, 34),
        Pair(-11, 7), Pair(0, 0), Pair(-10, 51), Pair(-2, 48), Pair(0, 43), Pair(-8, 50), Pair(6, 47), Pair(11, 38),
        Pair(-6, 33), Pair(-14, 7), Pair(-7, 39), Pair(-4, 42), Pair(-6, 42), Pair(-8, 41), Pair(0, 37), Pair(-1, 40)
      },
      { // Piece 4
        Pair(-15, 69), Pair(-15, 66), Pair(29, 24), Pair(21, 51), Pair(-135, 170), Pair(2, 38), Pair(42, 74), Pair(-38, 57),
        Pair(4, 43), Pair(-6, 52), Pair(-18, 76), Pair(-10, 81), Pair(-46, 73), Pair(-11, 26), Pair(11, 100), Pair(-47, 87),
        Pair(-10, 93), Pair(-24, 74), Pair(16, 12), Pair(-10, 84), Pair(-14, 64), Pair(-34, 116), Pair(-1, 67), Pair(-7, 83),
        Pair(-5, 89), Pair(0, 72), Pair(-6, 86), Pair(-17, 92), Pair(-2, 36), Pair(-15, 60), Pair(-11, 72), Pair(-2, 58),
        Pair(3, 69), Pair(-8, 78), Pair(13, 44), Pair(-4, 71), Pair(-1, 61), Pair(-12, 79), Pair(-2, 71), Pair(0, 63),
        Pair(-11, 89), Pair(-1, 44), Pair(4, 75), Pair(-2, 94), Pair(11, 68), Pair(6, 67), Pair(0, 80), Pair(9, 61),
        Pair(-13, 29), Pair(0, 0), Pair(6, 65), Pair(6, 72), Pair(9, 77), Pair(3, 89), Pair(-2, 92), Pair(-14, 121),
        Pair(-5, 61), Pair(10, -12), Pair(0, 88), Pair(4, 81), Pair(-1, 86), Pair(7, 71), Pair(-2, 102), Pair(28, 134)
      },
      { // Piece 5
        Pair(-92, 25), Pair(81, 20), Pair(-102, 50), Pair(-19, -10), Pair(56, -70), Pair(-2, 23), Pair(-3, -71), Pair(-45, -104),
        Pair(-25, 18), Pair(95, 28), Pair(-92, 32), Pair(34, 47), Pair(33, -53), Pair(-148, 100), Pair(-58, 24), Pair(-128, -1),
        Pair(-252, 130), Pair(-3, 50), Pair(23, 37), Pair(-113, 82), Pair(32, 15), Pair(41, 17), Pair(-21, -4), Pair(43, -5),
        Pair(-57, 41), Pair(-17, 40), Pair(104, 25), Pair(-38, 24), Pair(-141, 50), Pair(-33, 25), Pair(-79, 12), Pair(-108, 26),
        Pair(-6, 17), Pair(77, 2), Pair(27, 38), Pair(-99, 40), Pair(-35, 32), Pair(-43, 20), Pair(-60, 27), Pair(-15, 6),
        Pair(96, -36), Pair(-21, -3), Pair(-28, 9), Pair(-35, 21), Pair(5, 17), Pair(-1, 6), Pair(-15, 9), Pair(-41, 6),
        Pair(71, 1), Pair(0, 0), Pair(-2, 3), Pair(6, 7), Pair(4, 12), Pair(-11, 11), Pair(-13, 5), Pair(-7, -9),
        Pair(75, -28), Pair(42, -22), Pair(33, -10), Pair(12, 5), Pair(5, 9), Pair(-2, 4), Pair(-7, -3), Pair(-7, -15)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 22), Pair(-65, 29), Pair(-14, 13), Pair(2, -18), Pair(40, -23), Pair(-46, 20), Pair(-5, 18), Pair(6, 10),
        Pair(-7, 6), Pair(-21, 22), Pair(-13, 5), Pair(-9, 13), Pair(15, -1), Pair(4, 2), Pair(-2, 10), Pair(5, 6),
        Pair(0, 7), Pair(-7, 12), Pair(-3, -4), Pair(-1, 5), Pair(4, 8), Pair(0, 12), Pair(-3, 10), Pair(-5, 9),
        Pair(-2, 10), Pair(-3, 15), Pair(-4, -8), Pair(2, 16), Pair(0, 8), Pair(4, 11), Pair(0, 14), Pair(-2, 13),
        Pair(-6, 9), Pair(4, 19), Pair(-7, -18), Pair(6, 26), Pair(-4, 10), Pair(2, 10), Pair(-2, 12), Pair(-1, 11),
        Pair(-5, 8), Pair(3, 11), Pair(-2, 2), Pair(-3, 13), Pair(-6, 10), Pair(-1, 12), Pair(-3, 15), Pair(1, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-62, 25), Pair(104, -84), Pair(66, -4), Pair(99, -4), Pair(-162, 98), Pair(-14, 3), Pair(-112, 152), Pair(35, -27),
        Pair(19, 10), Pair(-13, 76), Pair(12, 27), Pair(1, 50), Pair(-2, 12), Pair(11, 18), Pair(53, 17), Pair(38, -40),
        Pair(-9, 8), Pair(-11, 29), Pair(-8, 21), Pair(4, 35), Pair(-19, 38), Pair(-5, 12), Pair(-6, 50), Pair(0, 11),
        Pair(9, 37), Pair(1, 39), Pair(-6, 28), Pair(10, 41), Pair(-7, 36), Pair(2, 48), Pair(-10, 51), Pair(-4, 29),
        Pair(-4, 41), Pair(26, 18), Pair(8, 25), Pair(0, 40), Pair(-2, 36), Pair(2, 34), Pair(-7, 32), Pair(3, 18),
        Pair(-4, 48), Pair(2, 43), Pair(-1, 24), Pair(2, 37), Pair(10, 42), Pair(1, 39), Pair(10, 27), Pair(6, 7),
        Pair(-25, 34), Pair(11, 11), Pair(0, 0), Pair(2, 48), Pair(-1, 38), Pair(2, 44), Pair(3, 36), Pair(-5, 58),
        Pair(44, -60), Pair(-5, 16), Pair(4, 22), Pair(3, 36), Pair(-1, 28), Pair(-7, 29), Pair(-4, 26), Pair(41, -62)
      },
      { // Piece 2
        Pair(34, 25), Pair(-76, 66), Pair(-17, 40), Pair(19, -12), Pair(3, 7), Pair(73, -19), Pair(-68, -5), Pair(-8, 18),
        Pair(2, 26), Pair(1, 14), Pair(-18, 28), Pair(-25, 8), Pair(22, 2), Pair(1, -1), Pair(13, 6), Pair(9, 15),
        Pair(-16, 25), Pair(19, 31), Pair(15, 29), Pair(20, 10), Pair(-2, 5), Pair(-7, 18), Pair(8, 10), Pair(9, 25),
        Pair(9, 21), Pair(-2, 24), Pair(20, 19), Pair(-2, 12), Pair(-2, 23), Pair(7, 5), Pair(2, 19), Pair(-1, 17),
        Pair(-10, 27), Pair(17, 11), Pair(4, 12), Pair(17, 27), Pair(7, 16), Pair(6, 17), Pair(2, 26), Pair(9, 0),
        Pair(10, 10), Pair(6, 17), Pair(-1, 13), Pair(2, 51), Pair(0, 29), Pair(6, 27), Pair(3, 25), Pair(-1, 22),
        Pair(4, -33), Pair(6, 40), Pair(0, 0), Pair(3, 31), Pair(-4, 30), Pair(-1, 37), Pair(-2, 30), Pair(3, 44),
        Pair(-7, 34), Pair(-89, -63), Pair(4, 53), Pair(8, -6), Pair(-6, 35), Pair(-2, 23), Pair(22, 19), Pair(-7, 50)
      },
      { // Piece 3
        Pair(-37, 55), Pair(-20, 42), Pair(11, 10), Pair(-50, 50), Pair(-33, 49), Pair(17, 27), Pair(36, 20), Pair(63, 18),
        Pair(-15, 44), Pair(-7, 40), Pair(-16, 22), Pair(-16, 33), Pair(16, 12), Pair(-10, 23), Pair(-22, 34), Pair(13, 26),
        Pair(-20, 40), Pair(-4, 45), Pair(-14, 30), Pair(-36, 41), Pair(-9, 40), Pair(-8, 33), Pair(3, 42), Pair(17, 37),
        Pair(-9, 55), Pair(-12, 42), Pair(4, 25), Pair(-22, 41), Pair(-2, 21), Pair(2, 22), Pair(-48, 55), Pair(-9, 34),
        Pair(-3, 29), Pair(-3, 37), Pair(17, 17), Pair(3, 32), Pair(-11, 38), Pair(0, 19), Pair(15, 18), Pair(0, 37),
        Pair(8, 41), Pair(13, 26), Pair(30, 5), Pair(0, 35), Pair(5, 32), Pair(-10, 42), Pair(-21, 44), Pair(14, 22),
        Pair(-29, 28), Pair(-12, 9), Pair(0, 0), Pair(-6, 42), Pair(-8, 38), Pair(-7, 32), Pair(1, 18), Pair(-13, 52),
        Pair(-8, 37), Pair(0, 28), Pair(-9, -5), Pair(-6, 36), Pair(-7, 36), Pair(-7, 32), Pair(-5, 37), Pair(-13, 42)
      },
      { // Piece 4
        Pair(52, 33), Pair(13, 25), Pair(-5, 30), Pair(39, 25), Pair(-55, 103), Pair(19, -6), Pair(75, -118), Pair(-36, 59),
        Pair(-7, 39), Pair(2, 55), Pair(-8, 40), Pair(-7, 44), Pair(43, -4), Pair(33, 28), Pair(-23, 131), Pair(-8, 99),
        Pair(-9, 61), Pair(-4, 53), Pair(17, 9), Pair(-20, 76), Pair(3, 57), Pair(-41, 119), Pair(-7, 58), Pair(-13, 69),
        Pair(12, 27), Pair(5, 43), Pair(17, 14), Pair(-9, 72), Pair(4, 62), Pair(9, 15), Pair(-4, 37), Pair(-19, 58),
        Pair(-11, 86), Pair(5, 36), Pair(-4, 64), Pair(2, 67), Pair(-5, 59), Pair(-7, 56), Pair(-2, 47), Pair(1, 5),
        Pair(-15, 64), Pair(6, 45), Pair(-8, 73), Pair(8, 49), Pair(9, 43), Pair(9, 42), Pair(-4, 63), Pair(-25, 109),
        Pair(12, -40), Pair(-2, 33), Pair(0, 0), Pair(4, 73), Pair(3, 54), Pair(12, 51), Pair(0, 56), Pair(-30, 136),
        Pair(10, 24), Pair(5, 44), Pair(-1, 21), Pair(1, 37), Pair(-1, 56), Pair(5, 68), Pair(21, 35), Pair(-26, 84)
      },
      { // Piece 5
        Pair(14, 76), Pair(51, 110), Pair(14, -95), Pair(-1, -24), Pair(52, 19), Pair(18, 125), Pair(51, -42), Pair(36, 37),
        Pair(29, 32), Pair(-40, 62), Pair(-135, 92), Pair(-11, 17), Pair(73, 62), Pair(-83, 31), Pair(-58, 41), Pair(-84, -87),
        Pair(-71, 118), Pair(131, 5), Pair(-158, 73), Pair(78, 76), Pair(60, 69), Pair(-56, 30), Pair(-151, 44), Pair(43, -6),
        Pair(50, 11), Pair(-196, 75), Pair(249, -6), Pair(97, 16), Pair(-137, 49), Pair(-161, 47), Pair(-7, -4), Pair(-56, 10),
        Pair(-78, 30), Pair(-95, 47), Pair(33, 13), Pair(65, 16), Pair(-3, 0), Pair(-79, 21), Pair(-20, 7), Pair(-67, 16),
        Pair(10, 37), Pair(-47, 4), Pair(-19, 0), Pair(-50, 5), Pair(6, 4), Pair(-25, 11), Pair(-13, 3), Pair(-17, 14),
        Pair(66, 15), Pair(45, -8), Pair(0, 0), Pair(-5, 8), Pair(4, -6), Pair(-2, 3), Pair(-9, -2), Pair(-4, -11),
        Pair(27, -3), Pair(8, 7), Pair(0, 4), Pair(-11, 4), Pair(13, 7), Pair(17, -14), Pair(-5, -8), Pair(-5, -11)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-29, 3), Pair(-42, 11), Pair(-47, -7), Pair(20, 34), Pair(-118, 96), Pair(-5, -22), Pair(66, -13), Pair(-30, 25),
        Pair(7, -4), Pair(20, -2), Pair(-13, 12), Pair(14, -3), Pair(-12, 36), Pair(-2, 2), Pair(4, 8), Pair(-11, 4),
        Pair(0, -2), Pair(4, -2), Pair(-3, 14), Pair(3, 12), Pair(-10, 22), Pair(-4, 15), Pair(-3, 2), Pair(-11, 19),
        Pair(0, 8), Pair(2, 11), Pair(-3, 14), Pair(7, 2), Pair(3, 17), Pair(-4, 12), Pair(-1, 14), Pair(-1, 9),
        Pair(0, 8), Pair(1, 8), Pair(2, 20), Pair(-10, 1), Pair(10, 34), Pair(-8, 10), Pair(3, 10), Pair(1, 2),
        Pair(-2, 7), Pair(2, -37), Pair(-3, 12), Pair(-2, -5), Pair(3, 28), Pair(-8, 9), Pair(-2, 17), Pair(-1, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-1, 30), Pair(-187, -172), Pair(44, -65), Pair(-88, 43), Pair(-70, -88), Pair(-45, 16), Pair(-142, 57), Pair(27, -124),
        Pair(-22, 7), Pair(-3, -4), Pair(-52, 57), Pair(-79, 97), Pair(-164, 134), Pair(-35, -1), Pair(-32, -20), Pair(-14, -15),
        Pair(-63, 123), Pair(-23, 107), Pair(-22, 20), Pair(-17, 32), Pair(85, -52), Pair(-13, 4), Pair(42, -62), Pair(7, 56),
        Pair(-43, 33), Pair(-7, 21), Pair(2, 6), Pair(-15, 64), Pair(-4, 54), Pair(1, -10), Pair(0, 44), Pair(-20, 54),
        Pair(6, 13), Pair(22, 33), Pair(0, 12), Pair(-7, 24), Pair(3, 45), Pair(6, -9), Pair(-3, 73), Pair(-5, 41),
        Pair(1, 1), Pair(-1, -25), Pair(3, 14), Pair(6, -3), Pair(3, 37), Pair(-2, 33), Pair(0, 20), Pair(-3, 26),
        Pair(-8, -44), Pair(-12, 45), Pair(4, -4), Pair(0, 0), Pair(-2, 36), Pair(-1, 44), Pair(-19, 42), Pair(-18, 41),
        Pair(-7, 26), Pair(-10, -6), Pair(43, -6), Pair(-13, 55), Pair(1, 50), Pair(-7, -9), Pair(-8, 28), Pair(-20, -39)
      },
      { // Piece 2
        Pair(-18, -47), Pair(-31, -6), Pair(-154, 116), Pair(-201, 12), Pair(-10, 19), Pair(-58, 39), Pair(-11, -35), Pair(-87, 14),
        Pair(39, -72), Pair(-6, -1), Pair(30, 19), Pair(-16, -33), Pair(51, -85), Pair(22, -23), Pair(-25, 21), Pair(-13, 48),
        Pair(-12, -25), Pair(31, -10), Pair(-14, 41), Pair(16, 17), Pair(-11, -8), Pair(-59, 40), Pair(-53, 2), Pair(-22, 20),
        Pair(-22, -39), Pair(1, 27), Pair(-19, 31), Pair(-13, 26), Pair(-9, 19), Pair(25, -17), Pair(1, -48), Pair(-17, 37),
        Pair(41, -18), Pair(-20, -8), Pair(-3, 7), Pair(-5, 35), Pair(-7, 49), Pair(14, -44), Pair(7, -6), Pair(8, -26),
        Pair(-2, -20), Pair(6, -28), Pair(14, 10), Pair(-17, 11), Pair(-11, 23), Pair(1, 23), Pair(-36, 101), Pair(6, 5),
        Pair(20, 69), Pair(-4, 2), Pair(5, -26), Pair(0, 0), Pair(2, 21), Pair(-16, 48), Pair(-5, 35), Pair(-75, -65),
        Pair(15, -34), Pair(8, -58), Pair(-10, -44), Pair(33, 12), Pair(131, -67), Pair(-7, 45), Pair(-93, 19), Pair(-7, -4)
      },
      { // Piece 3
        Pair(-38, 58), Pair(53, 13), Pair(-18, 11), Pair(-73, 58), Pair(49, 21), Pair(158, 27), Pair(16, 14), Pair(-59, 68),
        Pair(19, 4), Pair(5, 32), Pair(-52, 67), Pair(-114, 59), Pair(-32, 39), Pair(-31, 78), Pair(-85, 63), Pair(-23, 46),
        Pair(12, 16), Pair(48, -20), Pair(15, -2), Pair(87, -33), Pair(-25, 43), Pair(-69, 49), Pair(-8, 20), Pair(12, 54),
        Pair(-1, 34), Pair(3, 40), Pair(-11, 42), Pair(4, 44), Pair(-7, 31), Pair(5, 13), Pair(-57, 16), Pair(7, 21),
        Pair(-1, 53), Pair(-18, 38), Pair(-20, 30), Pair(56, -7), Pair(-5, 10), Pair(-15, 31), Pair(-17, 62), Pair(28, -18),
        Pair(3, 31), Pair(22, 18), Pair(0, 42), Pair(-39, 39), Pair(26, -7), Pair(-16, 24), Pair(6, 15), Pair(23, 4),
        Pair(-22, 13), Pair(-36, 41), Pair(15, -6), Pair(0, 0), Pair(-48, 47), Pair(-14, 21), Pair(-17, 39), Pair(26, 3),
        Pair(-7, 11), Pair(3, -6), Pair(-10, 20), Pair(-9, -29), Pair(-17, 24), Pair(-1, -2), Pair(3, 7), Pair(-2, 28)
      },
      { // Piece 4
        Pair(-38, 57), Pair(4, 59), Pair(99, -99), Pair(64, -1), Pair(-148, 54), Pair(38, 27), Pair(-5, 45), Pair(0, -58),
        Pair(-11, 6), Pair(-50, 128), Pair(8, 24), Pair(110, -173), Pair(-42, 22), Pair(-54, 143), Pair(-8, 92), Pair(7, -78),
        Pair(1, -25), Pair(-35, 153), Pair(-2, -33), Pair(22, -9), Pair(18, -50), Pair(-31, 119), Pair(2, 82), Pair(-21, 40),
        Pair(37, -7), Pair(-33, 65), Pair(13, -39), Pair(35, -48), Pair(-19, 46), Pair(6, 19), Pair(15, 35), Pair(7, 5),
        Pair(-10, 9), Pair(8, -13), Pair(-21, 78), Pair(-6, 27), Pair(-9, 52), Pair(-15, 85), Pair(-27, 110), Pair(-19, 61),
        Pair(-18, 41), Pair(-12, 36), Pair(20, -15), Pair(0, 4), Pair(25, 9), Pair(-5, 24), Pair(-16, 55), Pair(-9, 73),
        Pair(-7, 58), Pair(11, 4), Pair(2, 24), Pair(0, 0), Pair(5, -19), Pair(6, 7), Pair(-16, 131), Pair(-54, 257),
        Pair(12, 6), Pair(0, -14), Pair(5, -21), Pair(3, -24), Pair(-13, -7), Pair(15, -28), Pair(-6, 154), Pair(21, 6)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(3, 16), Pair(29, 88), Pair(-15, -91), Pair(-29, -133), Pair(-55, -55), Pair(-21, 7),
        Pair(8, 104), Pair(29, 230), Pair(-2, 63), Pair(5, -45), Pair(65, 74), Pair(6, 19), Pair(-8, -24), Pair(4, 15),
        Pair(-36, -2), Pair(88, 32), Pair(6, 58), Pair(13, 79), Pair(-98, -41), Pair(-22, -2), Pair(7, 52), Pair(40, 47),
        Pair(68, -16), Pair(7, 104), Pair(-76, 29), Pair(1, 50), Pair(42, 16), Pair(-5, 9), Pair(-178, 71), Pair(63, -56),
        Pair(-70, 62), Pair(10, 16), Pair(-2, 29), Pair(57, -7), Pair(-15, 48), Pair(-114, 32), Pair(-37, 0), Pair(-22, 21),
        Pair(-40, 59), Pair(-15, 40), Pair(53, -42), Pair(-56, 8), Pair(-17, -3), Pair(-7, 17), Pair(58, -25), Pair(2, -2),
        Pair(0, 16), Pair(-42, 51), Pair(-63, 23), Pair(0, 0), Pair(-73, 25), Pair(-23, 6), Pair(0, -14), Pair(0, -3),
        Pair(107, -56), Pair(-1, 31), Pair(0, 1), Pair(-98, 18), Pair(-10, -24), Pair(-12, 2), Pair(8, -15), Pair(-1, -26)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, 7), Pair(40, 13), Pair(-12, 28), Pair(56, -28), Pair(-61, 5), Pair(-84, 51), Pair(-53, 31), Pair(0, 12),
        Pair(-6, 9), Pair(-13, 11), Pair(-11, 19), Pair(-2, 16), Pair(2, 10), Pair(-47, 50), Pair(-25, 37), Pair(7, -4),
        Pair(-1, 10), Pair(-1, 12), Pair(0, 10), Pair(-2, 26), Pair(3, 7), Pair(5, 21), Pair(3, 14), Pair(-1, 6),
        Pair(-6, 11), Pair(-5, 12), Pair(-4, 16), Pair(1, 19), Pair(1, 5), Pair(7, 13), Pair(-1, 11), Pair(3, 7),
        Pair(-5, 16), Pair(0, 11), Pair(-7, 16), Pair(7, 34), Pair(3, -11), Pair(10, 20), Pair(3, 11), Pair(3, 8),
        Pair(-4, 13), Pair(0, 11), Pair(-6, 10), Pair(3, 29), Pair(-2, -4), Pair(6, 15), Pair(2, -31), Pair(6, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(16, 14), Pair(72, 49), Pair(-11, 12), Pair(195, -45), Pair(-16, 17), Pair(-33, -62), Pair(50, -67), Pair(-112, 45),
        Pair(40, -53), Pair(-22, 31), Pair(-21, 40), Pair(-21, 51), Pair(-55, 59), Pair(19, 23), Pair(94, -18), Pair(25, -7),
        Pair(25, -4), Pair(-29, 63), Pair(1, 22), Pair(-9, 30), Pair(-36, 43), Pair(-7, 31), Pair(-54, 85), Pair(-42, 39),
        Pair(-14, 58), Pair(1, 31), Pair(-5, 23), Pair(5, 33), Pair(-18, 33), Pair(13, 30), Pair(-22, 49), Pair(14, 67),
        Pair(5, 30), Pair(11, 40), Pair(2, 20), Pair(-2, 34), Pair(-6, 22), Pair(-7, 48), Pair(-38, 59), Pair(-1, 16),
        Pair(3, 20), Pair(7, 31), Pair(7, 36), Pair(-12, 45), Pair(3, 8), Pair(-6, 43), Pair(-5, 45), Pair(-1, 3),
        Pair(0, 76), Pair(29, 23), Pair(-4, 29), Pair(5, 22), Pair(0, 0), Pair(-3, 31), Pair(-16, 31), Pair(-13, 50),
        Pair(-17, 53), Pair(1, 50), Pair(14, 40), Pair(-3, 36), Pair(-5, 62), Pair(-5, 38), Pair(-4, 3), Pair(-109, -63)
      },
      { // Piece 2
        Pair(-31, 33), Pair(-51, 42), Pair(68, -28), Pair(-31, 11), Pair(-151, 41), Pair(127, -38), Pair(-61, 20), Pair(57, 25),
        Pair(1, -5), Pair(-11, 21), Pair(-29, 23), Pair(26, -24), Pair(67, -13), Pair(3, 3), Pair(-79, 82), Pair(-51, 27),
        Pair(-4, -20), Pair(-18, 7), Pair(12, 14), Pair(21, -16), Pair(17, -5), Pair(-32, 52), Pair(25, 19), Pair(-9, 28),
        Pair(3, 8), Pair(-21, 47), Pair(-12, 12), Pair(-13, 9), Pair(-15, 21), Pair(0, 3), Pair(2, 12), Pair(-22, 9),
        Pair(-53, 27), Pair(7, 6), Pair(40, 19), Pair(13, 12), Pair(-2, 14), Pair(2, -4), Pair(6, 8), Pair(-3, 58),
        Pair(3, 26), Pair(22, 17), Pair(3, 15), Pair(1, 42), Pair(-12, -3), Pair(8, 15), Pair(-9, 13), Pair(-9, 5),
        Pair(-5, 33), Pair(3, 22), Pair(11, -7), Pair(-5, 27), Pair(0, 0), Pair(4, 11), Pair(-8, 15), Pair(1, -9),
        Pair(12, -4), Pair(7, 20), Pair(-1, 14), Pair(126, -103), Pair(-4, 35), Pair(-15, -20), Pair(10, 13), Pair(-12, 10)
      },
      { // Piece 3
        Pair(76, 11), Pair(-33, 31), Pair(28, 18), Pair(10, 4), Pair(30, 7), Pair(-103, 68), Pair(-187, 78), Pair(38, 17),
        Pair(-18, 34), Pair(-20, 25), Pair(19, 17), Pair(21, -3), Pair(-53, 39), Pair(-86, 72), Pair(1, 22), Pair(12, 19),
        Pair(-8, 34), Pair(-2, 29), Pair(-17, 25), Pair(12, 14), Pair(-64, 54), Pair(39, 5), Pair(29, 31), Pair(17, 12),
        Pair(12, 23), Pair(-7, 43), Pair(-3, 18), Pair(8, 0), Pair(-19, 30), Pair(-15, 42), Pair(44, 6), Pair(31, -3),
        Pair(0, 25), Pair(-3, 34), Pair(-5, 32), Pair(-7, 27), Pair(33, 0), Pair(-3, 10), Pair(-3, 24), Pair(3, 42),
        Pair(19, 21), Pair(14, -2), Pair(-15, 44), Pair(-4, 37), Pair(15, -15), Pair(12, 11), Pair(2, 18), Pair(5, 23),
        Pair(-6, 40), Pair(-23, 45), Pair(-3, 24), Pair(-14, 22), Pair(0, 0), Pair(-15, 6), Pair(0, -41), Pair(17, -30),
        Pair(-1, 21), Pair(-1, 14), Pair(-3, 20), Pair(-5, 12), Pair(-2, -13), Pair(-8, 16), Pair(-10, 27), Pair(6, 7)
      },
      { // Piece 4
        Pair(20, 34), Pair(-27, 71), Pair(12, 36), Pair(49, -43), Pair(-11, -2), Pair(128, 61), Pair(3, 28), Pair(-183, 125),
        Pair(-36, 49), Pair(-26, 68), Pair(-15, 48), Pair(-20, 59), Pair(12, -13), Pair(10, 110), Pair(-82, 92), Pair(-19, 67),
        Pair(-5, 31), Pair(-40, 85), Pair(-19, 69), Pair(1, 109), Pair(-2, 22), Pair(-51, 101), Pair(-8, -22), Pair(-42, 62),
        Pair(-2, 57), Pair(-9, 34), Pair(-3, 32), Pair(-10, -4), Pair(-23, 52), Pair(-25, 70), Pair(-3, -3), Pair(-23, -13),
        Pair(0, 38), Pair(-2, 44), Pair(0, 34), Pair(-11, 58), Pair(-26, 102), Pair(-10, 19), Pair(-59, 95), Pair(-22, 79),
        Pair(17, -7), Pair(5, 30), Pair(1, 30), Pair(-3, 30), Pair(-4, 5), Pair(-4, 23), Pair(10, 23), Pair(-39, 72),
        Pair(11, -76), Pair(21, -11), Pair(6, 19), Pair(-1, 24), Pair(0, 0), Pair(4, -17), Pair(6, -51), Pair(-24, 127),
        Pair(-5, 58), Pair(13, -4), Pair(-1, 10), Pair(-1, -3), Pair(-10, -1), Pair(25, 16), Pair(22, 93), Pair(67, -54)
      },
      { // Piece 5
        Pair(20, 131), Pair(-24, -40), Pair(50, 120), Pair(34, 148), Pair(-21, -83), Pair(-9, 27), Pair(-2, -12), Pair(-15, -46),
        Pair(-36, -3), Pair(29, 59), Pair(5, 102), Pair(-40, 2), Pair(2, -90), Pair(-72, 34), Pair(-7, 62), Pair(8, -39),
        Pair(-47, -26), Pair(-102, -20), Pair(60, 52), Pair(-121, 41), Pair(8, 49), Pair(-103, 27), Pair(-70, -8), Pair(16, 73),
        Pair(-29, -29), Pair(33, -22), Pair(0, 54), Pair(-123, 31), Pair(1, 36), Pair(-13, -17), Pair(2, -14), Pair(-7, 9),
        Pair(13, 31), Pair(34, -28), Pair(-60, 15), Pair(14, 39), Pair(45, -3), Pair(104, -28), Pair(-137, 39), Pair(-54, 25),
        Pair(13, -9), Pair(-38, 40), Pair(22, -8), Pair(13, -22), Pair(-18, -2), Pair(22, -26), Pair(-5, 22), Pair(26, -9),
        Pair(-23, 14), Pair(-8, -10), Pair(-12, 2), Pair(-20, -4), Pair(0, 0), Pair(-58, 17), Pair(13, -8), Pair(10, 0),
        Pair(-12, -51), Pair(-16, -6), Pair(-8, 6), Pair(-21, 8), Pair(-48, 24), Pair(-32, 13), Pair(9, -14), Pair(4, -13)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, 7), Pair(-23, 20), Pair(-19, 2), Pair(-11, 9), Pair(-7, 20), Pair(-41, 24), Pair(-15, 12), Pair(-20, 12),
        Pair(-6, 14), Pair(-2, 13), Pair(-1, 12), Pair(0, 11), Pair(3, 14), Pair(-7, 12), Pair(-13, 14), Pair(0, 7),
        Pair(-2, 14), Pair(2, 10), Pair(1, 9), Pair(0, 10), Pair(-5, 14), Pair(5, 13), Pair(-3, 10), Pair(-1, 8),
        Pair(-5, 13), Pair(2, 12), Pair(-2, 9), Pair(0, 11), Pair(1, 14), Pair(5, 7), Pair(8, 14), Pair(3, 6),
        Pair(-5, 14), Pair(2, 16), Pair(1, 9), Pair(-5, 12), Pair(9, 25), Pair(4, -5), Pair(15, 16), Pair(3, 10),
        Pair(-1, 16), Pair(0, 15), Pair(-2, 11), Pair(-9, 9), Pair(5, 14), Pair(7, 0), Pair(4, 6), Pair(0, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(31, -38), Pair(91, -2), Pair(60, 5), Pair(80, 7), Pair(51, 12), Pair(39, 24), Pair(-37, 11), Pair(-62, 69),
        Pair(12, 22), Pair(-28, 34), Pair(-8, 29), Pair(9, 25), Pair(-13, 47), Pair(-21, 39), Pair(-23, 35), Pair(-16, 40),
        Pair(31, 32), Pair(9, 27), Pair(13, 29), Pair(-16, 39), Pair(7, 33), Pair(-4, 30), Pair(-8, 43), Pair(-19, 19),
        Pair(-23, 52), Pair(6, 39), Pair(5, 35), Pair(-6, 40), Pair(1, 35), Pair(-19, 30), Pair(-11, 46), Pair(-12, 36),
        Pair(-8, 35), Pair(8, 37), Pair(4, 40), Pair(9, 35), Pair(1, 37), Pair(1, 33), Pair(-8, 39), Pair(-14, 31),
        Pair(3, 35), Pair(5, 35), Pair(0, 38), Pair(3, 36), Pair(6, 41), Pair(-4, 29), Pair(7, 37), Pair(-14, 15),
        Pair(-13, 18), Pair(-3, 26), Pair(5, 32), Pair(3, 35), Pair(-3, 44), Pair(0, 0), Pair(-8, 29), Pair(0, 21),
        Pair(-81, -2), Pair(6, 26), Pair(-15, 52), Pair(-13, 36), Pair(3, 45), Pair(-8, 55), Pair(-2, 9), Pair(-79, 70)
      },
      { // Piece 2
        Pair(4, 21), Pair(-17, 20), Pair(94, -19), Pair(41, -10), Pair(80, 7), Pair(37, 17), Pair(24, 7), Pair(-32, 42),
        Pair(-1, 11), Pair(-7, 19), Pair(7, 18), Pair(15, 10), Pair(33, 16), Pair(-41, 34), Pair(-18, 21), Pair(18, 18),
        Pair(-4, 14), Pair(-13, 19), Pair(28, 7), Pair(16, 8), Pair(5, 23), Pair(-7, 13), Pair(6, 23), Pair(-33, 33),
        Pair(-11, 19), Pair(14, 16), Pair(-11, 20), Pair(10, 16), Pair(-7, 23), Pair(22, 9), Pair(-5, 15), Pair(3, 27),
        Pair(6, 24), Pair(-9, 21), Pair(10, 22), Pair(-10, 35), Pair(11, 26), Pair(-11, 27), Pair(14, 18), Pair(-17, 12),
        Pair(-2, 22), Pair(-1, 22), Pair(-11, 27), Pair(5, 28), Pair(-2, 38), Pair(10, 19), Pair(-8, 17), Pair(0, 31),
        Pair(4, 22), Pair(-8, 32), Pair(2, 30), Pair(-12, 33), Pair(12, 22), Pair(0, 0), Pair(4, 35), Pair(-18, 15),
        Pair(-4, 19), Pair(19, 3), Pair(-10, 37), Pair(-1, 25), Pair(-9, 13), Pair(10, 39), Pair(-24, -99), Pair(31, -13)
      },
      { // Piece 3
        Pair(27, 35), Pair(35, 27), Pair(49, 28), Pair(29, 40), Pair(43, 35), Pair(45, 22), Pair(21, 31), Pair(66, 20),
        Pair(16, 40), Pair(1, 48), Pair(-1, 46), Pair(17, 41), Pair(16, 37), Pair(35, 21), Pair(-17, 51), Pair(15, 32),
        Pair(13, 47), Pair(23, 39), Pair(16, 39), Pair(16, 41), Pair(13, 37), Pair(29, 28), Pair(-38, 57), Pair(17, 35),
        Pair(-2, 45), Pair(18, 42), Pair(10, 40), Pair(23, 33), Pair(7, 37), Pair(31, 27), Pair(-23, 56), Pair(21, 31),
        Pair(13, 45), Pair(13, 37), Pair(4, 55), Pair(25, 38), Pair(3, 50), Pair(40, 14), Pair(15, 45), Pair(18, 42),
        Pair(10, 46), Pair(-3, 48), Pair(1, 44), Pair(0, 47), Pair(8, 52), Pair(8, 27), Pair(-7, 54), Pair(-18, 54),
        Pair(-5, 49), Pair(1, 34), Pair(5, 40), Pair(9, 36), Pair(0, 43), Pair(0, 0), Pair(-31, 23), Pair(-26, 42),
        Pair(8, 40), Pair(9, 41), Pair(8, 40), Pair(5, 41), Pair(0, 39), Pair(-8, 25), Pair(-12, 35), Pair(0, 33)
      },
      { // Piece 4
        Pair(20, 85), Pair(28, 43), Pair(24, 67), Pair(74, 37), Pair(8, 65), Pair(-26, 68), Pair(26, 45), Pair(5, 91),
        Pair(1, 65), Pair(0, 94), Pair(-12, 94), Pair(28, 43), Pair(23, 65), Pair(30, 10), Pair(22, 79), Pair(11, 107),
        Pair(3, 89), Pair(6, 47), Pair(1, 84), Pair(-15, 111), Pair(-16, 114), Pair(-63, 126), Pair(-6, 97), Pair(-20, 93),
        Pair(-15, 100), Pair(-1, 96), Pair(0, 63), Pair(4, 81), Pair(-13, 77), Pair(-13, 76), Pair(-7, 65), Pair(-11, 88),
        Pair(6, 106), Pair(4, 64), Pair(14, 68), Pair(2, 73), Pair(13, 53), Pair(-6, 81), Pair(3, 66), Pair(-9, 70),
        Pair(23, 39), Pair(10, 89), Pair(8, 69), Pair(12, 60), Pair(10, 69), Pair(2, 54), Pair(-17, 90), Pair(-13, 90),
        Pair(1, 67), Pair(20, 54), Pair(11, 74), Pair(12, 65), Pair(13, 72), Pair(0, 0), Pair(6, 25), Pair(38, 7),
        Pair(5, 97), Pair(-4, 102), Pair(20, 55), Pair(9, 84), Pair(-4, 69), Pair(19, 12), Pair(49, -25), Pair(18, 44)
      },
      { // Piece 5
        Pair(-13, -24), Pair(63, -67), Pair(-52, 112), Pair(63, 64), Pair(26, -2), Pair(-34, 133), Pair(-103, -4), Pair(-44, -5),
        Pair(-152, 40), Pair(81, -11), Pair(-64, 56), Pair(26, 40), Pair(-131, 80), Pair(-40, 93), Pair(-171, 99), Pair(-71, 0),
        Pair(15, -9), Pair(38, 23), Pair(-58, 30), Pair(-37, 40), Pair(-57, 39), Pair(-25, 54), Pair(-41, 72), Pair(-62, 26),
        Pair(-132, 41), Pair(-91, 20), Pair(-262, 60), Pair(-104, 40), Pair(-11, 42), Pair(-84, 65), Pair(43, 16), Pair(-40, 27),
        Pair(-84, 12), Pair(-42, 25), Pair(-148, 46), Pair(-58, 25), Pair(14, 21), Pair(-61, 37), Pair(48, 9), Pair(14, 7),
        Pair(-21, 4), Pair(-33, 8), Pair(-35, 20), Pair(-14, 17), Pair(-24, -6), Pair(-15, -3), Pair(-14, -15), Pair(30, 0),
        Pair(-36, 4), Pair(-1, 15), Pair(-10, 12), Pair(-13, 9), Pair(1, -1), Pair(0, 0), Pair(21, -13), Pair(32, -1),
        Pair(-18, 8), Pair(-4, -6), Pair(-1, 5), Pair(-13, 5), Pair(-4, -7), Pair(-43, 18), Pair(6, 4), Pair(25, 4)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 21), Pair(4, 7), Pair(1, 5), Pair(-10, 19), Pair(12, -8), Pair(4, -1), Pair(-10, 16), Pair(-26, 20),
        Pair(-2, 15), Pair(-3, 13), Pair(-7, 15), Pair(8, 5), Pair(-9, 13), Pair(-5, 8), Pair(-6, -9), Pair(7, 9),
        Pair(4, 14), Pair(3, 12), Pair(1, 9), Pair(0, 8), Pair(1, 11), Pair(-13, 8), Pair(6, 1), Pair(-2, 10),
        Pair(2, 12), Pair(0, 13), Pair(-1, 13), Pair(0, 12), Pair(-1, 11), Pair(0, 15), Pair(5, -2), Pair(1, 12),
        Pair(0, 13), Pair(-1, 12), Pair(2, 13), Pair(2, 9), Pair(1, 10), Pair(11, 18), Pair(-10, -1), Pair(11, 15),
        Pair(-1, 15), Pair(2, 14), Pair(-2, 13), Pair(-3, 18), Pair(-1, -31), Pair(5, 7), Pair(7, 1), Pair(-1, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-27, 46), Pair(-44, 65), Pair(131, -21), Pair(54, 22), Pair(-36, 27), Pair(-43, 8), Pair(-9, 24), Pair(79, -24),
        Pair(-23, 39), Pair(-23, 33), Pair(11, 27), Pair(6, 36), Pair(-7, 34), Pair(50, -3), Pair(15, -11), Pair(18, 11),
        Pair(-49, 41), Pair(-18, 37), Pair(-3, 38), Pair(1, 35), Pair(11, 18), Pair(-6, 23), Pair(-10, 17), Pair(23, -6),
        Pair(4, 29), Pair(8, 19), Pair(4, 38), Pair(6, 34), Pair(1, 32), Pair(9, 36), Pair(3, 25), Pair(-3, 35),
        Pair(2, 29), Pair(-2, 41), Pair(1, 30), Pair(3, 34), Pair(3, 27), Pair(4, 34), Pair(1, 25), Pair(1, 19),
        Pair(-8, 44), Pair(9, 16), Pair(2, 35), Pair(-1, 38), Pair(1, 31), Pair(4, 35), Pair(-3, 19), Pair(-7, 7),
        Pair(-11, 33), Pair(-11, 41), Pair(-8, 37), Pair(1, 37), Pair(-12, 36), Pair(-15, 35), Pair(0, 0), Pair(-8, 28),
        Pair(-62, 104), Pair(-15, 42), Pair(7, 16), Pair(-5, 35), Pair(-3, 19), Pair(0, 27), Pair(-1, 45), Pair(-24, 161)
      },
      { // Piece 2
        Pair(-75, -15), Pair(-10, 2), Pair(-50, 14), Pair(79, 10), Pair(5, 2), Pair(70, -22), Pair(70, -17), Pair(-25, 23),
        Pair(15, 9), Pair(-22, 19), Pair(-5, 3), Pair(25, -21), Pair(30, 6), Pair(21, -2), Pair(-3, 15), Pair(-44, 14),
        Pair(5, -1), Pair(19, 11), Pair(23, -2), Pair(20, 16), Pair(-3, 10), Pair(10, 29), Pair(-8, 16), Pair(12, 11),
        Pair(5, 21), Pair(-4, 20), Pair(2, 11), Pair(-10, 21), Pair(2, 22), Pair(8, 5), Pair(11, 10), Pair(-10, 22),
        Pair(11, 5), Pair(11, 23), Pair(-3, 19), Pair(11, 23), Pair(-2, 20), Pair(1, 17), Pair(-9, 13), Pair(3, 13),
        Pair(9, 18), Pair(-3, 12), Pair(-1, 30), Pair(0, 19), Pair(2, 27), Pair(-5, 23), Pair(0, 12), Pair(-15, -12),
        Pair(0, 14), Pair(6, 30), Pair(-2, 11), Pair(5, 28), Pair(-14, 26), Pair(17, 7), Pair(0, 0), Pair(-4, 4),
        Pair(27, 10), Pair(5, 3), Pair(5, 31), Pair(-10, 20), Pair(13, 28), Pair(-20, 19), Pair(42, 36), Pair(0, 0)
      },
      { // Piece 3
        Pair(25, 37), Pair(19, 37), Pair(41, 32), Pair(53, 20), Pair(34, 33), Pair(28, 38), Pair(-21, 35), Pair(72, 17),
        Pair(12, 41), Pair(1, 43), Pair(14, 35), Pair(0, 39), Pair(19, 32), Pair(37, 18), Pair(38, 15), Pair(10, 39),
        Pair(6, 38), Pair(15, 37), Pair(15, 39), Pair(-1, 33), Pair(1, 42), Pair(19, 14), Pair(43, 9), Pair(2, 32),
        Pair(4, 43), Pair(-1, 39), Pair(1, 33), Pair(-5, 46), Pair(28, 28), Pair(-1, 46), Pair(31, 11), Pair(-3, 40),
        Pair(19, 35), Pair(6, 35), Pair(6, 42), Pair(5, 41), Pair(12, 35), Pair(15, 38), Pair(47, 9), Pair(1, 38),
        Pair(6, 40), Pair(7, 37), Pair(-6, 40), Pair(-2, 41), Pair(9, 38), Pair(12, 42), Pair(12, 14), Pair(-6, 41),
        Pair(5, 43), Pair(-3, 41), Pair(12, 25), Pair(6, 34), Pair(5, 40), Pair(3, 37), Pair(0, 0), Pair(-20, 5),
        Pair(8, 39), Pair(16, 29), Pair(10, 31), Pair(9, 36), Pair(9, 39), Pair(4, 37), Pair(-11, 18), Pair(-13, 22)
      },
      { // Piece 4
        Pair(22, 41), Pair(9, 57), Pair(-4, 78), Pair(50, 36), Pair(47, 16), Pair(44, 36), Pair(59, -18), Pair(46, 28),
        Pair(-9, 79), Pair(-7, 65), Pair(-13, 86), Pair(-17, 80), Pair(28, 54), Pair(39, 37), Pair(48, 43), Pair(25, 44),
        Pair(4, 67), Pair(-14, 85), Pair(8, 66), Pair(3, 74), Pair(3, 53), Pair(28, 58), Pair(22, 55), Pair(7, 52),
        Pair(7, 74), Pair(-3, 73), Pair(-4, 73), Pair(16, 45), Pair(-4, 73), Pair(-17, 66), Pair(1, 95), Pair(6, 53),
        Pair(17, 43), Pair(17, 61), Pair(13, 63), Pair(4, 62), Pair(16, 43), Pair(-5, 71), Pair(11, 46), Pair(-8, 70),
        Pair(19, 48), Pair(26, 61), Pair(9, 81), Pair(19, 53), Pair(14, 69), Pair(10, 51), Pair(3, 68), Pair(-7, 46),
        Pair(36, 31), Pair(14, 69), Pair(18, 65), Pair(13, 86), Pair(16, 58), Pair(10, 70), Pair(0, 0), Pair(0, 44),
        Pair(9, 98), Pair(19, 69), Pair(12, 60), Pair(12, 71), Pair(14, 65), Pair(15, 27), Pair(-4, 35), Pair(9, -25)
      },
      { // Piece 5
        Pair(31, 114), Pair(-113, 153), Pair(-65, -25), Pair(-72, 49), Pair(6, 83), Pair(57, -16), Pair(14, 33), Pair(-16, -8),
        Pair(-119, -9), Pair(14, 27), Pair(-9, 72), Pair(37, 0), Pair(-67, 13), Pair(-42, 56), Pair(3, 80), Pair(57, 20),
        Pair(-102, 40), Pair(12, 22), Pair(-14, 24), Pair(-234, 70), Pair(-197, 66), Pair(-197, 78), Pair(4, 41), Pair(-64, 44),
        Pair(-188, 32), Pair(-111, 56), Pair(-131, 54), Pair(-76, 49), Pair(-34, 38), Pair(-124, 52), Pair(-68, 52), Pair(-7, 38),
        Pair(38, 4), Pair(-127, 31), Pair(-34, 30), Pair(-42, 39), Pair(-23, 31), Pair(-17, 22), Pair(74, 9), Pair(21, 13),
        Pair(-131, 18), Pair(-18, 18), Pair(-49, 33), Pair(-53, 35), Pair(6, 8), Pair(-43, 2), Pair(-1, -1), Pair(-9, -26),
        Pair(-44, -6), Pair(-26, 12), Pair(-26, 24), Pair(-22, 23), Pair(4, 6), Pair(-16, -7), Pair(0, 0), Pair(1, -4),
        Pair(-23, -47), Pair(-31, 5), Pair(-20, 5), Pair(-9, 17), Pair(26, -10), Pair(-16, 3), Pair(8, -3), Pair(-15, -11)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-19, 20), Pair(-18, 17), Pair(3, 10), Pair(-12, 9), Pair(-11, 9), Pair(23, -7), Pair(-11, 25), Pair(48, 4),
        Pair(-5, 17), Pair(-5, 13), Pair(-2, 14), Pair(1, 6), Pair(-7, 15), Pair(-9, 3), Pair(2, -1), Pair(0, 7),
        Pair(-2, 15), Pair(0, 10), Pair(4, 8), Pair(1, 5), Pair(-2, 8), Pair(-4, 8), Pair(-9, 16), Pair(6, 9),
        Pair(0, 15), Pair(2, 14), Pair(0, 11), Pair(1, 8), Pair(0, 3), Pair(-2, 4), Pair(-2, 10), Pair(8, 5),
        Pair(-4, 13), Pair(1, 13), Pair(1, 12), Pair(-2, 10), Pair(5, 5), Pair(-1, 5), Pair(4, 17), Pair(-9, 3),
        Pair(-3, 16), Pair(0, 15), Pair(-2, 10), Pair(-1, 15), Pair(6, 10), Pair(-3, 7), Pair(-2, 5), Pair(4, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(61, -19), Pair(-48, 17), Pair(-88, 65), Pair(-23, 2), Pair(37, 21), Pair(0, -5), Pair(44, 15), Pair(22, -49),
        Pair(-3, 20), Pair(-38, 41), Pair(-7, 39), Pair(4, 42), Pair(-1, 23), Pair(-6, 8), Pair(-19, 52), Pair(-10, 27),
        Pair(-10, 16), Pair(-5, 46), Pair(-2, 33), Pair(4, 32), Pair(1, 39), Pair(11, 16), Pair(-16, 27), Pair(28, 7),
        Pair(-10, 50), Pair(3, 32), Pair(3, 44), Pair(11, 34), Pair(4, 35), Pair(9, 30), Pair(1, 34), Pair(-7, 39),
        Pair(-5, 38), Pair(-1, 52), Pair(12, 33), Pair(12, 27), Pair(-3, 40), Pair(-2, 41), Pair(18, 18), Pair(-5, 16),
        Pair(-6, 33), Pair(-3, 37), Pair(-2, 34), Pair(0, 38), Pair(-2, 43), Pair(-1, 35), Pair(4, 38), Pair(-22, 29),
        Pair(-31, 67), Pair(-8, 37), Pair(-3, 33), Pair(-4, 42), Pair(-8, 39), Pair(-4, 28), Pair(6, 1), Pair(0, 0),
        Pair(43, 30), Pair(-13, 22), Pair(-5, 41), Pair(-24, 48), Pair(-14, 32), Pair(-14, 35), Pair(-11, 31), Pair(17, 8)
      },
      { // Piece 2
        Pair(28, 12), Pair(13, 11), Pair(-19, 14), Pair(-13, 11), Pair(114, -14), Pair(7, 34), Pair(-40, 54), Pair(22, 29),
        Pair(1, 30), Pair(6, 22), Pair(16, 7), Pair(46, -2), Pair(-2, 7), Pair(21, 14), Pair(-25, 28), Pair(3, 13),
        Pair(19, 12), Pair(21, 26), Pair(7, 23), Pair(-3, 25), Pair(4, 20), Pair(28, 12), Pair(41, 7), Pair(-1, 28),
        Pair(1, 22), Pair(2, 19), Pair(10, 15), Pair(13, 18), Pair(6, 28), Pair(27, 18), Pair(-9, 26), Pair(7, 26),
        Pair(2, 18), Pair(2, 19), Pair(14, 21), Pair(8, 26), Pair(8, 36), Pair(-5, 24), Pair(11, 18), Pair(11, 22),
        Pair(-7, 35), Pair(-1, 28), Pair(1, 32), Pair(7, 29), Pair(3, 31), Pair(-5, 35), Pair(3, 37), Pair(3, 4),
        Pair(27, -3), Pair(0, 38), Pair(6, 30), Pair(0, 36), Pair(-4, 44), Pair(2, 36), Pair(1, 30), Pair(0, 0),
        Pair(16, 23), Pair(-7, 5), Pair(-1, 32), Pair(-7, 38), Pair(15, 19), Pair(3, 25), Pair(7, 37), Pair(18, 19)
      },
      { // Piece 3
        Pair(-5, 57), Pair(5, 44), Pair(31, 46), Pair(18, 55), Pair(21, 46), Pair(39, 47), Pair(-8, 36), Pair(22, 22),
        Pair(7, 56), Pair(11, 50), Pair(-2, 63), Pair(18, 50), Pair(25, 39), Pair(14, 48), Pair(-8, 49), Pair(7, 26),
        Pair(10, 53), Pair(22, 50), Pair(1, 57), Pair(8, 54), Pair(37, 43), Pair(20, 42), Pair(-8, 44), Pair(-1, 36),
        Pair(-2, 56), Pair(17, 60), Pair(8, 49), Pair(33, 44), Pair(12, 42), Pair(31, 38), Pair(1, 56), Pair(-9, 47),
        Pair(10, 49), Pair(-10, 52), Pair(-3, 64), Pair(33, 38), Pair(3, 58), Pair(5, 48), Pair(9, 50), Pair(-9, 34),
        Pair(22, 49), Pair(0, 62), Pair(2, 55), Pair(-9, 57), Pair(3, 48), Pair(0, 40), Pair(-8, 63), Pair(-12, 11),
        Pair(-5, 62), Pair(-13, 56), Pair(2, 51), Pair(4, 48), Pair(-4, 60), Pair(-9, 56), Pair(5, 39), Pair(0, 0),
        Pair(9, 48), Pair(13, 50), Pair(9, 45), Pair(9, 45), Pair(12, 49), Pair(16, 51), Pair(-8, 65), Pair(-16, 17)
      },
      { // Piece 4
        Pair(12, 30), Pair(58, 15), Pair(-32, 93), Pair(49, 46), Pair(18, 70), Pair(54, 1), Pair(-11, 86), Pair(-75, 156),
        Pair(13, 67), Pair(6, 49), Pair(18, 41), Pair(11, 47), Pair(14, 55), Pair(0, 88), Pair(-23, 96), Pair(-2, 76),
        Pair(13, 69), Pair(-15, 81), Pair(23, 69), Pair(28, 29), Pair(25, 49), Pair(33, 33), Pair(27, 95), Pair(6, 67),
        Pair(2, 62), Pair(39, 3), Pair(10, 81), Pair(0, 85), Pair(6, 66), Pair(14, 74), Pair(8, 94), Pair(18, 46),
        Pair(19, 50), Pair(9, 66), Pair(14, 80), Pair(0, 74), Pair(4, 67), Pair(-3, 80), Pair(19, 51), Pair(7, 55),
        Pair(20, 34), Pair(14, 81), Pair(4, 100), Pair(13, 59), Pair(10, 70), Pair(-1, 77), Pair(7, 75), Pair(17, 80),
        Pair(20, 56), Pair(9, 99), Pair(9, 83), Pair(10, 82), Pair(13, 57), Pair(8, 49), Pair(2, 85), Pair(0, 0),
        Pair(14, 60), Pair(2, 76), Pair(1, 85), Pair(10, 74), Pair(11, 62), Pair(36, 30), Pair(10, 4), Pair(36, -85)
      },
      { // Piece 5
        Pair(-41, -21), Pair(-204, 38), Pair(-67, 14), Pair(-48, 56), Pair(-4, 41), Pair(35, 81), Pair(45, 95), Pair(-40, 11),
        Pair(-16, 39), Pair(-148, 95), Pair(162, 21), Pair(-65, 30), Pair(-104, 62), Pair(1, 72), Pair(-27, 74), Pair(-44, 1),
        Pair(-165, 25), Pair(23, 31), Pair(34, 28), Pair(-78, 59), Pair(-206, 72), Pair(-113, 66), Pair(-156, 73), Pair(-100, 66),
        Pair(-16, 24), Pair(-63, 39), Pair(-43, 44), Pair(-99, 53), Pair(-133, 59), Pair(1, 30), Pair(60, 31), Pair(-7, 17),
        Pair(-69, 26), Pair(-107, 45), Pair(-111, 45), Pair(-37, 41), Pair(-68, 36), Pair(13, 17), Pair(11, 13), Pair(-47, 11),
        Pair(-76, 19), Pair(-97, 46), Pair(-83, 49), Pair(-13, 30), Pair(-3, 22), Pair(17, 5), Pair(-20, -10), Pair(-27, -11),
        Pair(-50, 19), Pair(-40, 22), Pair(-23, 31), Pair(-5, 16), Pair(-2, 12), Pair(4, 5), Pair(-25, -21), Pair(0, 0),
        Pair(-33, 34), Pair(-24, 26), Pair(-26, 22), Pair(-25, 21), Pair(13, -5), Pair(17, -3), Pair(7, -27), Pair(22, -56)
      }
    }},
    {{ // Bucket 56
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 57
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 58
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 59
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 60
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 61
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 62
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
    {{ // Bucket 63
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
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
  }}
}};

constexpr PieceSquareTable<ScorePair> kNormalPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-3, -18), Pair(-43, -175), Pair(-12, -93), Pair(-25, -112), Pair(-21, -95), Pair(-9, -111), Pair(0, -98), Pair(-8, -81),
      Pair(-3, -56), Pair(-20, -129), Pair(-22, -165), Pair(-33, -129), Pair(-52, -152), Pair(-60, -185), Pair(-14, -114), Pair(-38, -159),
      Pair(-21, -149), Pair(-29, -151), Pair(3, -163), Pair(-40, -176), Pair(-49, -171), Pair(0, -168), Pair(-37, -165), Pair(-6, -158),
      Pair(-16, -160), Pair(-32, -171), Pair(5, -155), Pair(-50, -135), Pair(16, -155), Pair(1, -175), Pair(-17, -165), Pair(4, -156),
      Pair(-20, -185), Pair(-28, -182), Pair(3, -146), Pair(4, -141), Pair(2, -173), Pair(46, -180), Pair(12, -166), Pair(24, -159),
      Pair(6, -88), Pair(-20, -138), Pair(-10, -147), Pair(-10, -200), Pair(-4, -167), Pair(26, -163), Pair(-4, -115), Pair(-39, -207),
      Pair(-17, -160), Pair(11, -102), Pair(-68, -152), Pair(2, -145), Pair(-24, -172), Pair(7, -124), Pair(-35, -209), Pair(-13, -143),
      Pair(-14, -118), Pair(-12, -105), Pair(-9, -115), Pair(-6, -73), Pair(3, -114), Pair(-9, -93), Pair(-37, -170), Pair(-4, -63)
  },
  {
      Pair(-3, -56), Pair(-6, -127), Pair(-14, -69), Pair(-1, -2), Pair(1, -24), Pair(-28, -108), Pair(-44, -125), Pair(-33, -96),
      Pair(-18, -152), Pair(-44, -182), Pair(-58, -149), Pair(-59, -171), Pair(-42, -89), Pair(-52, -202), Pair(-34, -68), Pair(-25, -178),
      Pair(-34, -136), Pair(-42, -158), Pair(-47, -158), Pair(-15, -173), Pair(-37, -165), Pair(-10, -132), Pair(-41, -172), Pair(-34, -193),
      Pair(-14, -69), Pair(-53, -190), Pair(-44, -193), Pair(-48, -185), Pair(-43, -162), Pair(0, -200), Pair(-54, -174), Pair(-39, -180),
      Pair(2, -173), Pair(-37, -245), Pair(-29, -203), Pair(-24, -172), Pair(-6, -180), Pair(9, -184), Pair(-28, -182), Pair(-40, -151),
      Pair(-16, -192), Pair(-56, -206), Pair(-64, -205), Pair(-72, -181), Pair(13, -188), Pair(-34, -177), Pair(-3, -188), Pair(-54, -193),
      Pair(18, -232), Pair(-35, -215), Pair(-64, -227), Pair(-26, -183), Pair(-26, -190), Pair(-41, -172), Pair(-22, -202), Pair(-34, -256),
      Pair(-15, -257), Pair(-28, -200), Pair(-37, -131), Pair(-19, -145), Pair(-20, -185), Pair(-36, -235), Pair(0, -135), Pair(-13, -180)
  },
  {
      Pair(-32, -177), Pair(11, -209), Pair(-16, -208), Pair(47, -227), Pair(-13, -238), Pair(-32, -202), Pair(37, -218), Pair(-11, -204),
      Pair(-45, -183), Pair(-71, -187), Pair(-62, -189), Pair(-21, -173), Pair(-76, -204), Pair(-27, -192), Pair(-34, -199), Pair(-43, -205),
      Pair(-10, -198), Pair(13, -184), Pair(55, -217), Pair(-20, -180), Pair(-25, -191), Pair(3, -221), Pair(-87, -176), Pair(-28, -205),
      Pair(29, -200), Pair(-40, -177), Pair(-37, -205), Pair(-31, -185), Pair(-22, -181), Pair(34, -222), Pair(-20, -211), Pair(-55, -214),
      Pair(-30, -191), Pair(-70, -196), Pair(-73, -197), Pair(-56, -180), Pair(-35, -193), Pair(-36, -193), Pair(-12, -198), Pair(-43, -203),
      Pair(-58, -180), Pair(-101, -167), Pair(-37, -186), Pair(-45, -166), Pair(-56, -177), Pair(-2, -195), Pair(-55, -169), Pair(-18, -206),
      Pair(-65, -196), Pair(-76, -175), Pair(-57, -188), Pair(-46, -195), Pair(-63, -169), Pair(-68, -169), Pair(-57, -185), Pair(-68, -200),
      Pair(-50, -135), Pair(-32, -145), Pair(-15, -173), Pair(-44, -183), Pair(-53, -181), Pair(-24, -181), Pair(-99, -179), Pair(-54, -196)
  },
  {
      Pair(-29, -67), Pair(-30, -64), Pair(1, -45), Pair(32, -34), Pair(-70, -89), Pair(-7, -68), Pair(-42, -28), Pair(-37, -14),
      Pair(-20, -40), Pair(-10, -19), Pair(-14, -47), Pair(-9, -12), Pair(-2, -5), Pair(-61, -63), Pair(-7, -13), Pair(-26, -50),
      Pair(-9, -21), Pair(-12, -21), Pair(-4, -11), Pair(-40, -77), Pair(23, 32), Pair(33, 51), Pair(28, 34), Pair(-8, -9),
      Pair(-41, -74), Pair(6, 20), Pair(-6, -11), Pair(-5, -23), Pair(-46, -26), Pair(-11, -41), Pair(-2, -48), Pair(10, 4),
      Pair(-19, -31), Pair(0, 6), Pair(-7, -15), Pair(8, 9), Pair(-31, -62), Pair(-47, -68), Pair(-45, -83), Pair(-50, -71),
      Pair(0, -1), Pair(-31, -53), Pair(4, 1), Pair(47, 75), Pair(-11, -14), Pair(21, 36), Pair(11, 26), Pair(-9, -17),
      Pair(-25, -54), Pair(-35, -55), Pair(-43, -69), Pair(-9, -19), Pair(0, 0), Pair(13, 26), Pair(6, 5), Pair(8, 16),
      Pair(1, 2), Pair(-12, -29), Pair(-29, -55), Pair(-31, -61), Pair(14, 22), Pair(-24, -47), Pair(0, 0), Pair(-5, -12)
  },
  {
      Pair(43, 30), Pair(-10, 73), Pair(28, 61), Pair(-42, -71), Pair(5, -10), Pair(-30, -38), Pair(-25, 6), Pair(-15, -13),
      Pair(-5, 49), Pair(-22, -6), Pair(-19, 21), Pair(14, 16), Pair(-15, -13), Pair(17, -11), Pair(40, 4), Pair(5, -3),
      Pair(-24, 10), Pair(0, 42), Pair(-20, 19), Pair(64, -20), Pair(-4, -14), Pair(35, 0), Pair(43, -19), Pair(-37, 26),
      Pair(5, 32), Pair(24, 5), Pair(-42, 16), Pair(13, -10), Pair(40, -23), Pair(7, -7), Pair(-47, 1), Pair(-50, -5),
      Pair(31, 48), Pair(-54, 14), Pair(16, 11), Pair(-7, -10), Pair(-19, -7), Pair(25, -14), Pair(25, -10), Pair(-53, 4),
      Pair(-39, 18), Pair(-28, -3), Pair(34, 6), Pair(-4, -1), Pair(18, -21), Pair(63, -26), Pair(-2, -19), Pair(-53, 17),
      Pair(-12, 9), Pair(-24, 0), Pair(43, -5), Pair(-25, -4), Pair(6, -23), Pair(77, -32), Pair(38, -31), Pair(15, -4),
      Pair(10, 35), Pair(-67, 8), Pair(8, 1), Pair(0, -24), Pair(-7, -18), Pair(-10, -37), Pair(6, -22), Pair(5, -10)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(11, 56), Pair(19, 34), Pair(21, 44), Pair(22, 51), Pair(23, 58), Pair(25, 65), Pair(28, 67), Pair(33, 67),
  Pair(39, 60)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-7, 13), Pair(0, -20), Pair(4, -4), Pair(7, 8), Pair(10, 18), Pair(12, 25), Pair(12, 29), Pair(13, 30),
  Pair(14, 36), Pair(21, 31), Pair(29, 29), Pair(52, 19), Pair(66, 29), Pair(66, 9)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-41, -74), Pair(-33, -71), Pair(-27, -38), Pair(-26, -11), Pair(-25, 3), Pair(-21, 6), Pair(-17, 14), Pair(-11, 18),
  Pair(-8, 21), Pair(-2, 25), Pair(1, 29), Pair(3, 32), Pair(9, 30), Pair(33, 17), Pair(69, -3)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-36, 199), Pair(-17, 158), Pair(-9, 111), Pair(-1, 96), Pair(-1, 118), Pair(0, 137), Pair(2, 156), Pair(3, 165),
  Pair(5, 172), Pair(6, 180), Pair(8, 182), Pair(9, 182), Pair(11, 182), Pair(14, 179), Pair(13, 175), Pair(15, 173),
  Pair(16, 165), Pair(21, 154), Pair(33, 131), Pair(41, 119), Pair(48, 97), Pair(56, 85), Pair(80, 66), Pair(90, 43),
  Pair(-62, 132), Pair(160, -2), Pair(200, -4), Pair(221, -37)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-29, -102), Pair(-23, -84), Pair(-11, -57), Pair(14, -22), Pair(10, 41), Pair(157, 152), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(8, 10), Pair(18, 15), Pair(18, 39), Pair(43, 94), Pair(128, 176), Pair(10, 330), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(7, -5), Pair(4, 18), Pair(17, 33), Pair(46, 55), Pair(205, 104), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-29, -60), Pair(-10, -20), Pair(6, 11), Pair(-13, -12), Pair(-11, -10), Pair(-13, -13), Pair(-15, 0), Pair(-20, -43)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-6, -4), Pair(-11, -10), Pair(-10, -6), Pair(-8, -4), Pair(-5, -6), Pair(-2, -10), Pair(-9, -7), Pair(3, -10)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(2, -17), Pair(17, -15), Pair(28, -15), Pair(33, -11), Pair(36, -12), Pair(59, -16), Pair(56, -20), Pair(12, -9)
  },
  {
      Pair(-11, 1), Pair(-1, 4), Pair(13, -6), Pair(18, -4), Pair(19, -11), Pair(23, -12), Pair(30, -19), Pair(-14, 3)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(21, -10), Pair(36, -11), Pair(27, -10),
  Pair(44, -14), Pair(48, -15), Pair(43, -14),
  Pair(63, -3), Pair(0, 0), Pair(57, -2),
  Pair(39, 21), Pair(13, 16), Pair(44, 22)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-5, -4), Pair(-15, 10), Pair(-5, -2),
  Pair(-5, -3), Pair(-18, 2), Pair(-4, -3),
  Pair(0, -11), Pair(-7, -6), Pair(5, -13),
  Pair(17, -13), Pair(1, -9), Pair(23, -14),
  Pair(63, -24), Pair(65, -22), Pair(53, -20),
  Pair(19, -33), Pair(-17, -61), Pair(71, -45),
  Pair(65, -81), Pair(0, 0), Pair(65, -81)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-1, 84), Pair(-10, 75), Pair(-5, 63), Pair(4, 50), Pair(1, 42), Pair(10, 38), Pair(12, 30)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-4, 0), Pair(-23, 27), Pair(-4, 49), Pair(3, 60), Pair(11, 65), Pair(16, 73), Pair(15, 88)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-509, 95);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-66, -48), Pair(-10, -32), Pair(-23, -15), Pair(-57, -7), Pair(-34, -1), Pair(-53, 3), Pair(-19, -2), Pair(-19, -27)
  },
  {
      Pair(-50, 15), Pair(7, 13), Pair(4, 10), Pair(-50, 24), Pair(-15, 14), Pair(-34, 21), Pair(4, 20), Pair(-15, 6)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(24, 0), Pair(40, -5), Pair(94, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 2), Pair(33, -3), Pair(67, -11), Pair(94, -34), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(26, -11), Pair(41, -13), Pair(69, -12), Pair(127, -22), Pair(185, -42), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, 23), Pair(26, 43), Pair(50, 58), Pair(112, 46), Pair(147, 57), Pair(259, 19), Pair(477, -50)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(34, 3), Pair(6, 6), Pair(31, -3), Pair(17, 19), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(0, 30), Pair(4, 35)
  },
  {
      Pair(-42, -16), Pair(-33, -21)
  },
  {
      Pair(-51, -20), Pair(-43, -45)
  },
  {
      Pair(-50, 21), Pair(-52, 3)
  },
  {
      Pair(-70, 51), Pair(-60, 19)
  },
  {
      Pair(36, 22), Pair(-73, 51)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 29), Pair(11, 22), Pair(14, 25), Pair(10, 8), Pair(16, -4)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-10, -32), Pair(1, -14)
  },
  {
      Pair(-13, 6), Pair(-2, -10)
  },
  {
      Pair(-28, -40), Pair(-23, -56)
  },
  {
      Pair(-58, -20), Pair(-44, -36)
  },
  {
      Pair(-42, -32), Pair(-48, -6)
  },
  {
      Pair(-87, -13), Pair(-23, -56)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-9, -17), Pair(0, 0)
  },
  {
      Pair(-36, -32), Pair(-21, -47)
  },
  {
      Pair(-15, -26), Pair(-14, -30)
  },
  {
      Pair(-49, -23), Pair(-40, -40)
  },
  {
      Pair(-44, -3), Pair(-38, -30)
  },
  {
      Pair(-26, -21), Pair(-2, -47)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-4, -15), Pair(6, 3)
  },
  {
      Pair(-29, -22), Pair(1, -8)
  },
  {
      Pair(-26, -22), Pair(-5, -4)
  },
  {
      Pair(13, -29), Pair(8, -30)
  },
  {
      Pair(-49, -8), Pair(-40, -27)
  },
  {
      Pair(-1, -29), Pair(-19, -42)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(8, 60), Pair(48, 43), Pair(5, 53), Pair(-4, 49), Pair(26, 33), Pair(64, 15), Pair(37, 29), Pair(115, 36),
  Pair(17, 10), Pair(16, 28), Pair(11, 26), Pair(19, 11), Pair(8, 28), Pair(10, 37), Pair(4, 35), Pair(44, 58),
  Pair(-1, 25), Pair(3, 21), Pair(10, 25), Pair(2, 22), Pair(-6, 6), Pair(-1, 30), Pair(6, 17), Pair(3, 28)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-31, 1), Pair(40, 15), Pair(17, 9), Pair(52, 22), Pair(36, -31), Pair(63, -15), Pair(88, 12), Pair(-48, -11),
  Pair(-21, -9), Pair(2, 6), Pair(22, 1), Pair(7, 51), Pair(3, 30), Pair(2, 22), Pair(25, -13), Pair(49, -5),
  Pair(63, 11), Pair(-8, 6), Pair(16, 8), Pair(-1, 15), Pair(-20, 22), Pair(13, 14), Pair(8, -14), Pair(-64, 39)
};

constexpr ScorePair kBishopPairBonus = Pair(21, 83);

constexpr ScorePair kTempoBonus = Pair(21, 21);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H