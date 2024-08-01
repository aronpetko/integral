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
  Pair(73, 99), Pair(357, 278), Pair(409, 351), Pair(533, 666), Pair(1106, 1129), Pair(0, 0)
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
        Pair(0, 0), Pair(34, -9), Pair(18, -14), Pair(-23, 9), Pair(5, -4), Pair(3, 8), Pair(-8, 4), Pair(29, -2),
        Pair(-9, -3), Pair(23, -11), Pair(10, -18), Pair(-2, -20), Pair(-19, -9), Pair(-25, 5), Pair(29, -5), Pair(-23, 11),
        Pair(-42, 0), Pair(5, -13), Pair(8, -12), Pair(19, -28), Pair(-12, -8), Pair(-5, -7), Pair(-38, 10), Pair(-24, -2),
        Pair(-27, 15), Pair(10, -19), Pair(8, -25), Pair(-5, -14), Pair(1, -17), Pair(-6, -9), Pair(-21, -6), Pair(-14, -7),
        Pair(-90, 50), Pair(14, -21), Pair(18, -23), Pair(0, -18), Pair(1, -21), Pair(7, -18), Pair(-22, -7), Pair(-18, -11),
        Pair(0, 0), Pair(10, -10), Pair(-15, 4), Pair(9, -21), Pair(0, -22), Pair(1, -21), Pair(-20, -5), Pair(-17, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-95, -160), Pair(10, 1), Pair(128, -74), Pair(-46, -11), Pair(-71, -113), Pair(207, -81), Pair(71, -186), Pair(14, -90),
        Pair(36, -16), Pair(0, -70), Pair(92, -100), Pair(89, -62), Pair(85, -70), Pair(-24, -43), Pair(10, -60), Pair(124, -53),
        Pair(58, -33), Pair(82, -51), Pair(-2, -59), Pair(66, -49), Pair(89, -39), Pair(54, -36), Pair(56, -70), Pair(16, -78),
        Pair(56, -29), Pair(54, -50), Pair(83, -33), Pair(70, -40), Pair(22, -19), Pair(101, -86), Pair(124, -98), Pair(-17, -23),
        Pair(75, -39), Pair(34, -14), Pair(13, -8), Pair(33, -14), Pair(35, -36), Pair(47, -52), Pair(44, -64), Pair(4, -19),
        Pair(-5, -46), Pair(-7, 55), Pair(80, -24), Pair(69, -49), Pair(35, -31), Pair(37, -46), Pair(67, -55), Pair(20, -101),
        Pair(0, 0), Pair(64, -90), Pair(-16, 79), Pair(46, -35), Pair(44, -29), Pair(-2, -62), Pair(48, -122), Pair(16, -15),
        Pair(25, 101), Pair(10, -21), Pair(150, 36), Pair(30, -75), Pair(39, -24), Pair(15, -95), Pair(-39, 4), Pair(-1, -91)
      },
      { // Piece 2
        Pair(-39, -27), Pair(-99, 97), Pair(10, -41), Pair(-95, 95), Pair(27, 8), Pair(-128, 41), Pair(33, -54), Pair(-20, 170),
        Pair(1, 65), Pair(-89, 4), Pair(32, 46), Pair(27, -53), Pair(-69, 87), Pair(-111, 91), Pair(-149, 169), Pair(-74, 11),
        Pair(14, 28), Pair(-42, 71), Pair(-18, -10), Pair(-30, 65), Pair(38, -10), Pair(-125, 177), Pair(14, -13), Pair(34, -2),
        Pair(21, 44), Pair(39, -28), Pair(19, 34), Pair(5, 14), Pair(-52, 141), Pair(35, -12), Pair(-60, 84), Pair(-75, 5),
        Pair(-6, -48), Pair(27, 40), Pair(-16, 46), Pair(-51, 152), Pair(97, -52), Pair(-31, 39), Pair(22, 8), Pair(-67, 28),
        Pair(-40, 74), Pair(190, -22), Pair(-44, 164), Pair(2, 24), Pair(-5, 19), Pair(-19, -11), Pair(-17, 3), Pair(-23, -2),
        Pair(0, 0), Pair(-35, 173), Pair(24, 28), Pair(-2, 46), Pair(-21, -12), Pair(-90, 30), Pair(23, -26), Pair(19, 17),
        Pair(99, 196), Pair(-17, 84), Pair(-16, 66), Pair(-13, 1), Pair(-57, 38), Pair(-23, -18), Pair(-40, -41), Pair(-131, -1)
      },
      { // Piece 3
        Pair(113, 56), Pair(134, 0), Pair(98, -13), Pair(11, 52), Pair(-86, 77), Pair(100, -27), Pair(231, -4), Pair(171, -19),
        Pair(116, 58), Pair(124, -34), Pair(10, 48), Pair(133, 15), Pair(80, 22), Pair(225, -38), Pair(151, -25), Pair(66, 16),
        Pair(82, 70), Pair(79, 3), Pair(37, 21), Pair(-5, 54), Pair(35, -2), Pair(-53, 52), Pair(23, 9), Pair(76, 11),
        Pair(7, 77), Pair(9, 39), Pair(-29, 32), Pair(48, 24), Pair(48, -2), Pair(22, 4), Pair(49, 32), Pair(10, 23),
        Pair(8, 87), Pair(32, 12), Pair(14, 41), Pair(68, -31), Pair(44, -11), Pair(65, -44), Pair(-92, 59), Pair(16, 28),
        Pair(23, 80), Pair(-3, 37), Pair(50, 9), Pair(-23, 35), Pair(48, -32), Pair(89, -10), Pair(99, -19), Pair(-18, 4),
        Pair(0, 0), Pair(-7, 81), Pair(39, 40), Pair(42, 11), Pair(19, -4), Pair(32, 53), Pair(19, 23), Pair(10, 58),
        Pair(69, 119), Pair(-11, 32), Pair(1, 97), Pair(15, 83), Pair(23, 86), Pair(13, 79), Pair(18, 85), Pair(-28, 108)
      },
      { // Piece 4
        Pair(62, -55), Pair(9, 2), Pair(47, -58), Pair(84, -24), Pair(122, -14), Pair(13, 42), Pair(-60, 11), Pair(66, -66),
        Pair(-38, 24), Pair(-66, 115), Pair(-30, 36), Pair(32, 24), Pair(34, 47), Pair(99, -70), Pair(2, 44), Pair(33, -48),
        Pair(76, -67), Pair(31, -23), Pair(-8, 52), Pair(-91, 118), Pair(30, 50), Pair(46, 16), Pair(-43, 81), Pair(35, 8),
        Pair(47, -49), Pair(-14, -74), Pair(-40, 101), Pair(-66, 87), Pair(-37, 60), Pair(21, -19), Pair(74, -66), Pair(-34, 40),
        Pair(116, -173), Pair(-62, 54), Pair(-5, -37), Pair(-5, 67), Pair(-57, 38), Pair(29, -56), Pair(-15, -12), Pair(-17, 20),
        Pair(-62, -42), Pair(3, 9), Pair(-21, 15), Pair(-5, -57), Pair(-118, 96), Pair(-18, -3), Pair(-66, 77), Pair(-1, -71),
        Pair(0, 0), Pair(-26, 50), Pair(2, -45), Pair(9, -110), Pair(-36, -5), Pair(-18, -167), Pair(-38, -24), Pair(-149, -65),
        Pair(-78, 25), Pair(-10, -45), Pair(-50, 87), Pair(-71, 60), Pair(-91, -10), Pair(-81, 37), Pair(-119, 37), Pair(-56, 32)
      },
      { // Piece 5
        Pair(-5, -20), Pair(-25, -14), Pair(7, -82), Pair(33, -4), Pair(105, -88), Pair(-31, -64), Pair(-46, -86), Pair(-2, -89),
        Pair(-87, -162), Pair(43, -18), Pair(-74, -37), Pair(-21, -33), Pair(-37, -24), Pair(130, -60), Pair(38, -78), Pair(10, -31),
        Pair(-47, -111), Pair(-58, 27), Pair(66, 13), Pair(0, 8), Pair(82, -20), Pair(123, -33), Pair(152, -64), Pair(47, -37),
        Pair(-102, -22), Pair(-67, 51), Pair(-26, 32), Pair(39, 13), Pair(0, 9), Pair(-70, 1), Pair(20, -9), Pair(73, -56),
        Pair(59, 7), Pair(-122, 71), Pair(115, 27), Pair(67, 17), Pair(58, 4), Pair(35, -3), Pair(23, -6), Pair(9, -70),
        Pair(-116, 116), Pair(-34, 116), Pair(72, 42), Pair(-20, 48), Pair(17, 4), Pair(31, -10), Pair(-17, -25), Pair(-16, -33),
        Pair(0, 0), Pair(-158, 204), Pair(-14, 84), Pair(10, 43), Pair(-4, 13), Pair(-38, 10), Pair(-19, -6), Pair(18, -39),
        Pair(173, 133), Pair(73, 109), Pair(-167, 114), Pair(-42, -6), Pair(-85, -19), Pair(-20, -48), Pair(7, -77), Pair(-5, -79)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-34, 9), Pair(0, 0), Pair(-24, -11), Pair(38, -36), Pair(21, 0), Pair(-10, 11), Pair(-15, 8), Pair(13, 8),
        Pair(-29, 5), Pair(-23, 22), Pair(-3, -13), Pair(20, -19), Pair(-18, 1), Pair(13, -6), Pair(-13, 1), Pair(-16, 8),
        Pair(23, -21), Pair(-25, -14), Pair(-5, -5), Pair(8, -17), Pair(4, -15), Pair(-20, -6), Pair(9, -14), Pair(-2, -5),
        Pair(5, -8), Pair(-40, 15), Pair(-1, -9), Pair(-5, -9), Pair(-26, -9), Pair(-17, -11), Pair(-8, -10), Pair(-3, -11),
        Pair(15, -13), Pair(21, -30), Pair(14, -14), Pair(-5, -10), Pair(-9, -16), Pair(-21, -8), Pair(-12, -17), Pair(-7, -12),
        Pair(25, -16), Pair(0, 0), Pair(9, 3), Pair(14, -22), Pair(-2, -12), Pair(-3, -22), Pair(-17, -14), Pair(-9, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-6, 37), Pair(-42, -69), Pair(77, -84), Pair(-48, -59), Pair(-41, 1), Pair(91, -50), Pair(-4, -93), Pair(68, 0),
        Pair(17, -151), Pair(-91, -14), Pair(120, -38), Pair(48, -65), Pair(97, -28), Pair(3, 13), Pair(-13, -66), Pair(58, -54),
        Pair(79, 28), Pair(64, -2), Pair(-7, 3), Pair(-23, 27), Pair(43, -60), Pair(130, -50), Pair(19, -30), Pair(2, -57),
        Pair(-129, 40), Pair(15, 7), Pair(-31, 10), Pair(68, -40), Pair(90, -18), Pair(65, -46), Pair(36, -32), Pair(147, -83),
        Pair(92, -14), Pair(-37, 27), Pair(45, 27), Pair(16, -1), Pair(32, -14), Pair(2, -4), Pair(22, -13), Pair(-55, 2),
        Pair(-29, 87), Pair(19, -23), Pair(-36, 104), Pair(-63, 49), Pair(-20, 10), Pair(6, -1), Pair(-29, 43), Pair(-41, -48),
        Pair(-74, -106), Pair(0, 0), Pair(-12, 32), Pair(-71, 116), Pair(-13, -20), Pair(73, -99), Pair(-23, -48), Pair(-122, -3),
        Pair(-8, -18), Pair(-9, 156), Pair(-193, -55), Pair(14, 14), Pair(-40, -48), Pair(-77, 27), Pair(53, -110), Pair(-87, -23)
      },
      { // Piece 2
        Pair(-114, 90), Pair(-10, 32), Pair(-133, 109), Pair(-38, 18), Pair(-313, 146), Pair(33, 12), Pair(-36, 62), Pair(-37, 23),
        Pair(-53, 63), Pair(12, 69), Pair(5, 32), Pair(-166, 119), Pair(32, 45), Pair(26, 95), Pair(-19, 55), Pair(-102, 197),
        Pair(33, 35), Pair(-86, 56), Pair(-32, 75), Pair(38, -24), Pair(-37, 94), Pair(96, 23), Pair(29, 163), Pair(63, -21),
        Pair(-60, -30), Pair(-43, 62), Pair(-21, -37), Pair(-59, 81), Pair(78, 10), Pair(-52, 183), Pair(18, -19), Pair(-2, 56),
        Pair(67, 28), Pair(1, 0), Pair(-8, 75), Pair(33, 30), Pair(-102, 176), Pair(-17, 1), Pair(-14, 53), Pair(9, -63),
        Pair(-76, 66), Pair(-35, 115), Pair(10, 35), Pair(-25, 161), Pair(74, -61), Pair(-13, 22), Pair(-7, -33), Pair(35, 23),
        Pair(-48, 198), Pair(0, 0), Pair(-24, 184), Pair(18, -26), Pair(-6, 41), Pair(-20, 7), Pair(-15, 58), Pair(51, -50),
        Pair(3, -25), Pair(-6, 249), Pair(-91, 32), Pair(-62, 56), Pair(4, -59), Pair(-21, 51), Pair(-70, -47), Pair(-66, 100)
      },
      { // Piece 3
        Pair(109, -33), Pair(95, 26), Pair(-64, 21), Pair(123, -22), Pair(112, -26), Pair(61, 29), Pair(124, -19), Pair(238, -49),
        Pair(-58, 37), Pair(-17, 61), Pair(84, 8), Pair(74, -9), Pair(86, -3), Pair(137, -12), Pair(135, 1), Pair(-62, 46),
        Pair(31, -24), Pair(79, 31), Pair(11, 6), Pair(62, -7), Pair(102, -43), Pair(53, 6), Pair(59, -12), Pair(104, 16),
        Pair(51, -53), Pair(3, 58), Pair(65, -3), Pair(-7, 45), Pair(12, 17), Pair(-26, 39), Pair(84, -3), Pair(118, -63),
        Pair(16, -8), Pair(-55, 36), Pair(-31, 24), Pair(-39, 53), Pair(-5, 43), Pair(15, 3), Pair(-90, 72), Pair(-56, 8),
        Pair(22, -11), Pair(-22, 41), Pair(-40, -23), Pair(28, -16), Pair(-39, 14), Pair(-10, 22), Pair(32, -80), Pair(63, -66),
        Pair(106, -19), Pair(0, 0), Pair(-20, 40), Pair(-91, 104), Pair(13, -59), Pair(99, -45), Pair(85, 21), Pair(138, -68),
        Pair(-11, 34), Pair(31, 115), Pair(-3, 42), Pair(-35, 84), Pair(-37, 87), Pair(-26, 70), Pair(-15, 60), Pair(-33, 84)
      },
      { // Piece 4
        Pair(75, 24), Pair(-12, 49), Pair(100, -33), Pair(33, 11), Pair(54, 46), Pair(3, -63), Pair(-42, -7), Pair(140, -2),
        Pair(-29, 3), Pair(-141, 171), Pair(4, 19), Pair(-93, 40), Pair(5, 90), Pair(-50, 132), Pair(0, -6), Pair(38, -19),
        Pair(-95, 126), Pair(-50, 52), Pair(-24, -18), Pair(-57, 83), Pair(2, 55), Pair(-14, 90), Pair(-35, 46), Pair(54, -101),
        Pair(-96, 63), Pair(-69, 82), Pair(-80, -2), Pair(32, 12), Pair(68, 1), Pair(40, 32), Pair(20, 29), Pair(81, -150),
        Pair(-17, 80), Pair(-8, -20), Pair(-95, 67), Pair(-35, 14), Pair(-53, 84), Pair(-9, 55), Pair(23, -56), Pair(63, -186),
        Pair(-43, -78), Pair(-32, 27), Pair(33, -68), Pair(-68, 77), Pair(-4, -21), Pair(-31, 44), Pair(19, -143), Pair(-11, -115),
        Pair(-29, -142), Pair(0, 0), Pair(39, -55), Pair(-7, -76), Pair(-6, -82), Pair(-10, 23), Pair(57, -21), Pair(-81, -16),
        Pair(-77, -47), Pair(-53, -3), Pair(-89, -119), Pair(-8, -33), Pair(26, -153), Pair(-43, 15), Pair(-138, -2), Pair(-125, 70)
      },
      { // Piece 5
        Pair(-26, -86), Pair(-9, -32), Pair(-2, 1), Pair(6, -92), Pair(45, -74), Pair(29, -59), Pair(0, -21), Pair(19, -82),
        Pair(3, -12), Pair(-12, 48), Pair(21, -32), Pair(-12, -23), Pair(20, -25), Pair(-14, -63), Pair(73, -62), Pair(87, 4),
        Pair(-50, -84), Pair(11, -45), Pair(3, 17), Pair(31, -15), Pair(12, -9), Pair(30, -23), Pair(5, -38), Pair(57, -55),
        Pair(-40, -11), Pair(-51, -15), Pair(-63, 26), Pair(90, 7), Pair(65, -2), Pair(-79, 20), Pair(-23, -16), Pair(-86, -14),
        Pair(-9, -45), Pair(-24, 3), Pair(74, 38), Pair(-76, 46), Pair(42, 14), Pair(116, -13), Pair(64, -37), Pair(45, -61),
        Pair(39, 87), Pair(76, 54), Pair(36, 90), Pair(-25, 43), Pair(-6, 30), Pair(43, 0), Pair(-3, -21), Pair(66, -81),
        Pair(-64, 209), Pair(0, 0), Pair(-103, 156), Pair(-10, 47), Pair(-35, 41), Pair(42, -5), Pair(54, -43), Pair(19, -55),
        Pair(-5, 6), Pair(44, 141), Pair(14, 61), Pair(-285, 92), Pair(-70, -8), Pair(-15, -23), Pair(17, -74), Pair(42, -81)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, 14), Pair(24, 11), Pair(0, 0), Pair(-28, -2), Pair(-25, -6), Pair(54, -26), Pair(42, -6), Pair(2, 11),
        Pair(-5, -8), Pair(-6, -4), Pair(24, -8), Pair(-20, -4), Pair(18, -12), Pair(-5, 0), Pair(-25, 4), Pair(-11, -1),
        Pair(11, -12), Pair(-2, -17), Pair(-7, 5), Pair(4, -3), Pair(4, -3), Pair(-26, -4), Pair(-30, 0), Pair(-17, -3),
        Pair(-1, -9), Pair(12, -18), Pair(0, -4), Pair(5, -9), Pair(-6, -13), Pair(-25, -4), Pair(-21, -13), Pair(-21, -5),
        Pair(10, -20), Pair(10, -12), Pair(11, -5), Pair(-12, -14), Pair(2, -8), Pair(-14, -6), Pair(-34, -7), Pair(-28, -4),
        Pair(14, -10), Pair(20, -17), Pair(0, 0), Pair(-7, -27), Pair(-6, -9), Pair(-10, -16), Pair(-18, -13), Pair(-21, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-67, -117), Pair(10, -41), Pair(58, 18), Pair(169, 48), Pair(-37, -102), Pair(-79, -64), Pair(-69, 39), Pair(-80, -174),
        Pair(-3, -81), Pair(-106, 12), Pair(-122, 26), Pair(-54, 41), Pair(-30, 22), Pair(62, -21), Pair(43, -43), Pair(-40, -5),
        Pair(-87, 39), Pair(52, 40), Pair(-68, 58), Pair(51, -28), Pair(-23, 40), Pair(133, -73), Pair(-4, -2), Pair(-94, 53),
        Pair(6, 21), Pair(30, 24), Pair(10, 20), Pair(-62, 88), Pair(37, 2), Pair(1, -4), Pair(29, 7), Pair(58, 32),
        Pair(-16, 38), Pair(120, -30), Pair(34, -38), Pair(-32, 46), Pair(44, -18), Pair(-7, 49), Pair(23, -23), Pair(-27, 31),
        Pair(28, -16), Pair(-111, 172), Pair(23, -36), Pair(-41, 134), Pair(-59, 42), Pair(19, 25), Pair(-102, 104), Pair(1, -25),
        Pair(-57, 161), Pair(-88, 61), Pair(0, 0), Pair(45, -6), Pair(-39, 133), Pair(40, -42), Pair(-61, 14), Pair(34, -41),
        Pair(-18, -10), Pair(33, -146), Pair(-30, 196), Pair(24, -64), Pair(42, 88), Pair(93, -66), Pair(12, -39), Pair(-23, 7)
      },
      { // Piece 2
        Pair(-40, -5), Pair(2, 36), Pair(-142, 51), Pair(11, 35), Pair(-47, 53), Pair(-32, 88), Pair(15, 2), Pair(-71, 59),
        Pair(-25, 59), Pair(19, 16), Pair(-65, 129), Pair(-105, 57), Pair(-35, 117), Pair(3, 31), Pair(-31, 99), Pair(179, -3),
        Pair(78, 2), Pair(38, 41), Pair(-75, 31), Pair(-92, 142), Pair(-34, 48), Pair(-85, 99), Pair(-53, 65), Pair(-43, 159),
        Pair(-141, 85), Pair(-16, 41), Pair(125, -2), Pair(41, -1), Pair(17, 89), Pair(99, 34), Pair(-42, 172), Pair(144, -64),
        Pair(40, 66), Pair(85, 0), Pair(-12, 45), Pair(57, 54), Pair(44, 31), Pair(-36, 183), Pair(-20, 27), Pair(-49, 11),
        Pair(-57, 185), Pair(-116, 80), Pair(-24, 118), Pair(157, 34), Pair(-28, 177), Pair(22, 10), Pair(-56, 58), Pair(-7, -46),
        Pair(-13, -48), Pair(-44, 173), Pair(0, 0), Pair(-22, 186), Pair(42, 11), Pair(-93, 73), Pair(1, 0), Pair(1, -52),
        Pair(37, 48), Pair(-4, -22), Pair(41, 228), Pair(-144, 54), Pair(77, -6), Pair(-11, -9), Pair(40, 49), Pair(112, -17)
      },
      { // Piece 3
        Pair(-44, 56), Pair(36, -9), Pair(158, 14), Pair(68, 2), Pair(75, -1), Pair(43, -3), Pair(127, -48), Pair(93, -1),
        Pair(91, 12), Pair(-14, 24), Pair(101, 50), Pair(89, 8), Pair(28, 28), Pair(9, 65), Pair(15, 5), Pair(109, 2),
        Pair(86, -7), Pair(57, -18), Pair(71, 46), Pair(40, 25), Pair(92, -1), Pair(273, -121), Pair(48, -23), Pair(-85, 33),
        Pair(68, -8), Pair(46, 0), Pair(-2, 53), Pair(-16, 23), Pair(-79, 38), Pair(50, -6), Pair(-70, 61), Pair(-136, 59),
        Pair(-4, 17), Pair(112, -51), Pair(-50, 75), Pair(73, -18), Pair(76, -22), Pair(31, 19), Pair(86, -41), Pair(-86, 13),
        Pair(32, 4), Pair(94, -13), Pair(28, 27), Pair(26, 9), Pair(85, -43), Pair(-36, 10), Pair(3, 11), Pair(86, -24),
        Pair(-61, 62), Pair(-9, 92), Pair(0, 0), Pair(83, 3), Pair(89, -46), Pair(91, -19), Pair(-95, 79), Pair(19, 18),
        Pair(-36, 96), Pair(-39, 77), Pair(41, 135), Pair(16, 29), Pair(-2, 91), Pair(9, 75), Pair(-9, 80), Pair(-49, 111)
      },
      { // Piece 4
        Pair(-5, -39), Pair(97, -79), Pair(-156, 133), Pair(26, 9), Pair(75, 7), Pair(9, -30), Pair(10, 12), Pair(12, 130),
        Pair(-44, 44), Pair(11, 33), Pair(-41, 74), Pair(-45, 28), Pair(-18, 66), Pair(15, 48), Pair(-77, 79), Pair(-40, 15),
        Pair(-47, -10), Pair(29, 46), Pair(17, 24), Pair(-22, 3), Pair(-37, 90), Pair(27, 78), Pair(0, 60), Pair(28, 20),
        Pair(-54, 101), Pair(84, -151), Pair(-10, 58), Pair(-148, 126), Pair(32, -11), Pair(11, 32), Pair(99, -86), Pair(10, -2),
        Pair(-29, -104), Pair(-118, 10), Pair(81, -125), Pair(-11, -35), Pair(-50, 109), Pair(-17, 46), Pair(13, -66), Pair(22, -155),
        Pair(-48, 28), Pair(27, -103), Pair(40, 34), Pair(-4, -36), Pair(12, -44), Pair(21, -109), Pair(-80, 37), Pair(-50, -36),
        Pair(-2, -79), Pair(-38, 10), Pair(0, 0), Pair(32, -119), Pair(-25, 58), Pair(9, 14), Pair(27, -183), Pair(-93, 41),
        Pair(-54, -59), Pair(51, -39), Pair(45, -59), Pair(-67, -90), Pair(-65, 58), Pair(48, -120), Pair(-9, -29), Pair(-30, -65)
      },
      { // Piece 5
        Pair(-3, 44), Pair(-5, -45), Pair(-32, -172), Pair(-16, -24), Pair(-4, -123), Pair(-16, -140), Pair(32, -217), Pair(-1, -79),
        Pair(6, -8), Pair(-7, -56), Pair(-20, -23), Pair(2, -6), Pair(-27, -70), Pair(18, -49), Pair(-22, -80), Pair(-13, -91),
        Pair(-117, -89), Pair(14, -27), Pair(-93, -43), Pair(88, -5), Pair(13, -8), Pair(46, -27), Pair(-16, -15), Pair(76, -79),
        Pair(28, -11), Pair(26, 12), Pair(32, -46), Pair(52, 16), Pair(-17, 32), Pair(85, 6), Pair(46, -22), Pair(-91, -43),
        Pair(61, 63), Pair(42, 11), Pair(-33, 20), Pair(-44, 39), Pair(85, 3), Pair(97, -20), Pair(94, -28), Pair(-25, -25),
        Pair(-62, 61), Pair(18, 120), Pair(-96, 87), Pair(-6, 81), Pair(16, 31), Pair(11, 19), Pair(-20, -8), Pair(58, -83),
        Pair(128, -35), Pair(-123, 166), Pair(0, 0), Pair(-107, 130), Pair(2, 23), Pair(23, -8), Pair(2, -33), Pair(53, -69),
        Pair(-128, 110), Pair(118, -31), Pair(-155, 197), Pair(-3, -8), Pair(-28, 12), Pair(-10, -10), Pair(4, -61), Pair(71, -104)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(23, -9), Pair(-38, 35), Pair(28, 2), Pair(0, 0), Pair(11, 11), Pair(17, -4), Pair(91, -46), Pair(29, 4),
        Pair(19, -5), Pair(-5, -5), Pair(-24, 1), Pair(-19, -5), Pair(-9, 1), Pair(8, -18), Pair(24, -6), Pair(-8, -1),
        Pair(3, -12), Pair(-9, -12), Pair(1, -7), Pair(-15, 2), Pair(19, -9), Pair(0, -7), Pair(-10, -6), Pair(-16, -4),
        Pair(8, -19), Pair(-6, -11), Pair(6, -15), Pair(-23, -5), Pair(7, -10), Pair(-23, -4), Pair(-13, -5), Pair(3, -15),
        Pair(11, -17), Pair(7, -13), Pair(-12, 3), Pair(8, 17), Pair(-1, -3), Pair(10, 1), Pair(-16, -11), Pair(2, -14),
        Pair(5, -13), Pair(-14, 1), Pair(5, -11), Pair(0, 0), Pair(2, -23), Pair(-2, -12), Pair(1, -6), Pair(-10, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-54, -46), Pair(-4, -46), Pair(-23, -14), Pair(-125, -78), Pair(42, 32), Pair(40, -44), Pair(-34, -61), Pair(29, -13),
        Pair(72, -92), Pair(29, -15), Pair(-106, -8), Pair(-14, 17), Pair(74, -29), Pair(149, -61), Pair(10, 99), Pair(7, -18),
        Pair(-19, 74), Pair(19, -66), Pair(11, 18), Pair(30, -8), Pair(43, 7), Pair(30, 0), Pair(53, -11), Pair(-120, 124),
        Pair(-124, 79), Pair(-2, -26), Pair(52, -39), Pair(78, -21), Pair(-20, 86), Pair(65, -31), Pair(150, -106), Pair(58, -49),
        Pair(-73, 26), Pair(98, 31), Pair(-6, 50), Pair(63, -11), Pair(62, 21), Pair(72, -20), Pair(-52, 71), Pair(98, -36),
        Pair(-56, -27), Pair(42, -29), Pair(-47, 115), Pair(-120, 59), Pair(-19, 108), Pair(-1, 40), Pair(9, 14), Pair(-20, 83),
        Pair(-135, -20), Pair(-126, 155), Pair(-74, 32), Pair(0, 0), Pair(-39, 38), Pair(-29, 120), Pair(59, -63), Pair(-13, 122),
        Pair(-63, -66), Pair(94, -44), Pair(-73, -6), Pair(15, 162), Pair(76, -100), Pair(-81, 117), Pair(-66, 2), Pair(18, -36)
      },
      { // Piece 2
        Pair(9, 109), Pair(-69, 63), Pair(-97, 80), Pair(-5, -71), Pair(66, 75), Pair(25, -75), Pair(39, 46), Pair(93, -59),
        Pair(-73, 45), Pair(92, 30), Pair(73, -65), Pair(22, 102), Pair(-41, -18), Pair(-55, 105), Pair(91, -2), Pair(5, 72),
        Pair(-45, -7), Pair(6, 10), Pair(-81, 99), Pair(97, -15), Pair(-67, 91), Pair(156, -49), Pair(-29, 74), Pair(-37, 49),
        Pair(-10, 43), Pair(-114, 78), Pair(114, -23), Pair(-22, 58), Pair(-1, -11), Pair(-35, 67), Pair(43, 34), Pair(-65, 161),
        Pair(-80, 146), Pair(-59, 89), Pair(29, 44), Pair(85, -18), Pair(50, 35), Pair(37, 37), Pair(-67, 164), Pair(-32, 53),
        Pair(-1, -42), Pair(1, 149), Pair(-25, 68), Pair(-77, 78), Pair(38, 33), Pair(-42, 149), Pair(-67, 47), Pair(-16, 56),
        Pair(1, 3), Pair(13, -32), Pair(-68, 176), Pair(0, 0), Pair(-58, 147), Pair(3, -1), Pair(3, 44), Pair(-66, -1),
        Pair(-12, -20), Pair(5, 60), Pair(-21, -35), Pair(37, 211), Pair(-18, 18), Pair(40, 28), Pair(-73, 44), Pair(-108, 91)
      },
      { // Piece 3
        Pair(105, -38), Pair(64, -9), Pair(30, -2), Pair(104, 20), Pair(44, 21), Pair(147, -10), Pair(98, -4), Pair(126, -25),
        Pair(10, 10), Pair(12, 0), Pair(28, 0), Pair(50, 21), Pair(-7, 0), Pair(179, -37), Pair(89, -10), Pair(61, -25),
        Pair(45, -4), Pair(-16, 17), Pair(85, -46), Pair(31, 27), Pair(-70, 57), Pair(147, -43), Pair(32, 15), Pair(275, -92),
        Pair(-25, 42), Pair(-43, 12), Pair(-61, 51), Pair(33, 36), Pair(47, 11), Pair(-44, 53), Pair(78, -19), Pair(105, -24),
        Pair(-67, 32), Pair(125, -67), Pair(60, -39), Pair(28, 46), Pair(78, -48), Pair(42, -36), Pair(-65, -4), Pair(14, -19),
        Pair(-75, 69), Pair(-81, 64), Pair(36, 25), Pair(-120, 80), Pair(18, -33), Pair(51, 12), Pair(-99, 51), Pair(19, -37),
        Pair(114, -45), Pair(-73, 60), Pair(52, -21), Pair(0, 0), Pair(-13, 10), Pair(93, -35), Pair(30, 15), Pair(17, -31),
        Pair(-44, 83), Pair(-8, 75), Pair(-18, 22), Pair(29, 128), Pair(-2, 38), Pair(-16, 74), Pair(36, 59), Pair(-30, 68)
      },
      { // Piece 4
        Pair(86, -120), Pair(-18, 32), Pair(-24, 0), Pair(-14, 65), Pair(38, 0), Pair(74, -5), Pair(25, -69), Pair(30, -17),
        Pair(13, -13), Pair(-50, 39), Pair(-34, -2), Pair(-14, 51), Pair(-50, 93), Pair(24, 113), Pair(40, -8), Pair(80, -66),
        Pair(-4, -34), Pair(-78, 62), Pair(-62, -58), Pair(88, -45), Pair(-61, 66), Pair(47, 37), Pair(171, -163), Pair(0, -15),
        Pair(0, -9), Pair(23, -111), Pair(-39, -46), Pair(45, -34), Pair(49, -95), Pair(94, -51), Pair(70, -84), Pair(-45, 82),
        Pair(14, -17), Pair(-27, -1), Pair(49, -96), Pair(7, 30), Pair(56, -67), Pair(81, -87), Pair(31, 2), Pair(97, -70),
        Pair(-35, -34), Pair(-28, -7), Pair(-59, 35), Pair(38, 17), Pair(-2, -15), Pair(-43, 76), Pair(67, -100), Pair(-31, -114),
        Pair(4, -153), Pair(18, -92), Pair(-50, 45), Pair(0, 0), Pair(72, -64), Pair(-2, 32), Pair(-85, 2), Pair(-49, 26),
        Pair(-144, 103), Pair(-75, 24), Pair(-135, 17), Pair(49, -96), Pair(-125, -120), Pair(-54, -85), Pair(16, -36), Pair(-28, 27)
      },
      { // Piece 5
        Pair(-14, -78), Pair(-3, -70), Pair(13, 71), Pair(-6, -39), Pair(-7, -24), Pair(-58, -161), Pair(-14, -74), Pair(-10, -24),
        Pair(-4, -54), Pair(-48, -89), Pair(-3, -147), Pair(-8, -15), Pair(0, -41), Pair(-25, -89), Pair(-61, -67), Pair(-7, -108),
        Pair(8, -26), Pair(8, -14), Pair(47, -21), Pair(-6, -55), Pair(71, -49), Pair(56, -25), Pair(43, -44), Pair(15, -14),
        Pair(-9, -55), Pair(56, 20), Pair(111, -33), Pair(-146, 5), Pair(-26, 6), Pair(50, 6), Pair(30, -1), Pair(75, -36),
        Pair(-70, -43), Pair(37, 8), Pair(-6, 32), Pair(87, -7), Pair(-122, 48), Pair(4, 27), Pair(49, -25), Pair(-6, -27),
        Pair(-5, 5), Pair(88, -5), Pair(-55, 78), Pair(-118, 84), Pair(-4, 78), Pair(102, 15), Pair(43, -1), Pair(46, -62),
        Pair(31, -34), Pair(-76, 42), Pair(-17, 109), Pair(0, 0), Pair(-74, 106), Pair(30, 10), Pair(-6, 13), Pair(-11, -14),
        Pair(-70, 12), Pair(-42, 28), Pair(-66, -111), Pair(-84, 155), Pair(62, 61), Pair(-16, 14), Pair(-4, -29), Pair(23, -77)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 4), Pair(-21, 0), Pair(25, 6), Pair(-11, -11), Pair(0, 0), Pair(13, -13), Pair(2, 7), Pair(-27, 2),
        Pair(37, -15), Pair(2, -20), Pair(-25, -9), Pair(37, -29), Pair(74, -50), Pair(5, -6), Pair(27, -6), Pair(-24, -5),
        Pair(17, -21), Pair(-1, -13), Pair(-14, -10), Pair(4, -17), Pair(5, -17), Pair(-7, -6), Pair(8, -16), Pair(-15, -1),
        Pair(5, -21), Pair(1, -18), Pair(-9, -8), Pair(10, -13), Pair(-16, -15), Pair(10, -12), Pair(17, -20), Pair(-18, -8),
        Pair(-1, -8), Pair(-5, -18), Pair(-6, -16), Pair(-3, -14), Pair(5, -6), Pair(25, -19), Pair(13, -13), Pair(4, -10),
        Pair(16, -27), Pair(-4, -13), Pair(4, -7), Pair(-32, 10), Pair(0, 0), Pair(3, -24), Pair(23, -17), Pair(-8, -12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-55, -173), Pair(52, -83), Pair(-21, -36), Pair(129, -82), Pair(12, 18), Pair(-31, -70), Pair(-11, -116), Pair(-23, 67),
        Pair(38, -35), Pair(14, 12), Pair(-16, -25), Pair(-52, 10), Pair(-191, 39), Pair(-9, 86), Pair(29, -66), Pair(21, -52),
        Pair(-181, -31), Pair(-20, -33), Pair(-10, -46), Pair(-57, 3), Pair(109, -39), Pair(100, 32), Pair(149, -20), Pair(108, -34),
        Pair(-35, -29), Pair(16, -45), Pair(-2, -8), Pair(-46, 5), Pair(69, 0), Pair(97, 4), Pair(65, -34), Pair(-54, 32),
        Pair(-28, -18), Pair(-117, 11), Pair(-10, 13), Pair(77, 4), Pair(-16, 6), Pair(39, -2), Pair(98, 9), Pair(-40, 38),
        Pair(-7, -11), Pair(110, -31), Pair(-65, 74), Pair(-97, 102), Pair(28, 71), Pair(-58, 109), Pair(-7, 22), Pair(94, -121),
        Pair(-90, -38), Pair(-19, 1), Pair(-164, 161), Pair(-63, 21), Pair(0, 0), Pair(-56, -60), Pair(-39, 151), Pair(20, 0),
        Pair(-8, -95), Pair(-87, 48), Pair(141, -110), Pair(-61, -106), Pair(-25, 189), Pair(17, -80), Pair(26, -14), Pair(14, 37)
      },
      { // Piece 2
        Pair(185, -29), Pair(-3, 105), Pair(4, 47), Pair(-89, 68), Pair(-37, 13), Pair(7, 84), Pair(-12, -12), Pair(67, 81),
        Pair(-91, 78), Pair(88, -24), Pair(-7, 63), Pair(52, 11), Pair(-105, 75), Pair(29, -2), Pair(-46, 82), Pair(-19, -12),
        Pair(60, 4), Pair(-18, 38), Pair(0, 15), Pair(-7, 66), Pair(-42, 0), Pair(-114, 120), Pair(-49, 36), Pair(-5, 37),
        Pair(-115, 155), Pair(-69, 65), Pair(-1, 55), Pair(136, -64), Pair(-5, 25), Pair(-140, 99), Pair(31, 49), Pair(-62, 70),
        Pair(-142, 46), Pair(-91, 157), Pair(-81, 94), Pair(92, -5), Pair(25, 26), Pair(43, -9), Pair(-19, 62), Pair(-40, 155),
        Pair(63, -49), Pair(103, -10), Pair(-27, 121), Pair(-4, 94), Pair(35, 18), Pair(10, 41), Pair(-39, 107), Pair(59, -58),
        Pair(212, -89), Pair(-16, 10), Pair(-2, 60), Pair(-60, 139), Pair(0, 0), Pair(-89, 142), Pair(61, -63), Pair(-93, 36),
        Pair(9, -29), Pair(157, -66), Pair(-44, 29), Pair(19, 43), Pair(-1, 194), Pair(-89, -78), Pair(-13, 80), Pair(-2, 39)
      },
      { // Piece 3
        Pair(-74, 15), Pair(-58, 16), Pair(98, -45), Pair(13, -45), Pair(85, 0), Pair(-2, 15), Pair(9, 18), Pair(38, -27),
        Pair(52, -24), Pair(-7, -14), Pair(-58, 20), Pair(-124, 37), Pair(15, 9), Pair(0, -27), Pair(-30, 14), Pair(-69, 50),
        Pair(30, -55), Pair(25, 4), Pair(-80, 15), Pair(46, -27), Pair(68, -4), Pair(199, -97), Pair(128, -54), Pair(-88, 27),
        Pair(172, -80), Pair(-20, -6), Pair(13, -35), Pair(-75, -2), Pair(96, 2), Pair(79, -40), Pair(-23, 17), Pair(9, -52),
        Pair(-32, -5), Pair(-37, 7), Pair(-11, 4), Pair(-28, 14), Pair(62, 0), Pair(-45, -2), Pair(142, -83), Pair(-50, 58),
        Pair(-109, 80), Pair(-101, 25), Pair(141, -59), Pair(34, -35), Pair(39, 30), Pair(76, -46), Pair(3, -7), Pair(158, -53),
        Pair(43, 13), Pair(57, -50), Pair(23, 10), Pair(127, 7), Pair(0, 0), Pair(-49, 85), Pair(33, -24), Pair(3, -74),
        Pair(-72, 54), Pair(-100, 93), Pair(-70, 75), Pair(-70, -15), Pair(21, 103), Pair(-49, 32), Pair(16, 51), Pair(-32, 71)
      },
      { // Piece 4
        Pair(-17, 40), Pair(-32, -28), Pair(-14, 63), Pair(-31, 77), Pair(-43, -18), Pair(114, 15), Pair(-27, -60), Pair(71, -73),
        Pair(-90, 67), Pair(-42, -71), Pair(72, -27), Pair(-63, 81), Pair(65, 41), Pair(-22, 91), Pair(-16, 36), Pair(-30, 39),
        Pair(11, -74), Pair(1, 17), Pair(-27, -5), Pair(-49, 40), Pair(-3, 21), Pair(112, -25), Pair(111, -39), Pair(9, -75),
        Pair(-82, 52), Pair(-97, 130), Pair(-14, -53), Pair(33, -134), Pair(127, -85), Pair(34, 0), Pair(128, -109), Pair(52, -3),
        Pair(-82, 118), Pair(21, -1), Pair(7, 36), Pair(-3, -1), Pair(-51, 52), Pair(19, -3), Pair(10, -44), Pair(6, 11),
        Pair(-239, -89), Pair(52, -157), Pair(-13, -49), Pair(82, -232), Pair(63, -44), Pair(-103, 59), Pair(-8, 20), Pair(-90, -25),
        Pair(22, -69), Pair(-110, 65), Pair(24, -107), Pair(-32, 2), Pair(0, 0), Pair(-9, -7), Pair(-38, 18), Pair(-37, -89),
        Pair(26, -106), Pair(-125, -15), Pair(36, -208), Pair(-79, -34), Pair(4, -75), Pair(-25, 17), Pair(-112, -5), Pair(-44, -7)
      },
      { // Piece 5
        Pair(-52, -37), Pair(-12, -145), Pair(1, -53), Pair(-60, -169), Pair(32, 9), Pair(-19, -94), Pair(-7, 18), Pair(13, -11),
        Pair(13, -38), Pair(15, -44), Pair(-50, -76), Pair(33, -43), Pair(24, -21), Pair(23, -41), Pair(-77, -24), Pair(-6, -4),
        Pair(54, -73), Pair(-26, -34), Pair(-25, -2), Pair(-13, 24), Pair(16, 7), Pair(82, -42), Pair(49, -37), Pair(-79, 21),
        Pair(-49, -71), Pair(-15, 8), Pair(-54, 28), Pair(-20, 17), Pair(-75, 6), Pair(22, 17), Pair(56, 25), Pair(-53, -9),
        Pair(129, -83), Pair(68, -28), Pair(-12, 19), Pair(-72, 54), Pair(-68, 38), Pair(-58, 55), Pair(45, 16), Pair(-87, 25),
        Pair(1, -36), Pair(26, -10), Pair(-85, 45), Pair(-42, 83), Pair(56, 71), Pair(1, 75), Pair(37, 35), Pair(86, -9),
        Pair(83, -55), Pair(28, -11), Pair(116, 18), Pair(-142, 131), Pair(0, 0), Pair(-13, 97), Pair(18, 34), Pair(13, -8),
        Pair(68, -84), Pair(30, -48), Pair(-15, 29), Pair(-2, 9), Pair(-81, 166), Pair(30, 28), Pair(-16, 24), Pair(-16, -6)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, -8), Pair(10, -11), Pair(-54, 26), Pair(-17, 4), Pair(-13, 13), Pair(0, 0), Pair(-121, 27), Pair(-87, 18),
        Pair(11, -22), Pair(-28, -5), Pair(-47, -5), Pair(-2, -22), Pair(-20, 4), Pair(2, 24), Pair(-9, 17), Pair(43, -7),
        Pair(-13, -12), Pair(7, -13), Pair(-3, -14), Pair(-2, -16), Pair(4, -6), Pair(55, -10), Pair(4, -23), Pair(-8, -2),
        Pair(-20, -7), Pair(-8, -17), Pair(-18, -14), Pair(-5, -14), Pair(-16, -13), Pair(-21, -15), Pair(-3, -7), Pair(8, -11),
        Pair(5, -22), Pair(6, -16), Pair(-12, -15), Pair(13, -28), Pair(-7, -10), Pair(-6, -2), Pair(13, -15), Pair(13, -15),
        Pair(8, -19), Pair(9, -22), Pair(1, -17), Pair(-80, 17), Pair(16, -11), Pair(0, 0), Pair(12, -19), Pair(6, -15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-100, -34), Pair(-117, -232), Pair(-69, -13), Pair(99, 63), Pair(-19, 5), Pair(4, -6), Pair(-34, -73), Pair(16, 65),
        Pair(-74, -188), Pair(-80, -21), Pair(124, -20), Pair(-16, -92), Pair(23, 26), Pair(10, 21), Pair(-29, -182), Pair(-114, -108),
        Pair(105, -107), Pair(-146, 46), Pair(42, 4), Pair(-45, -2), Pair(33, 11), Pair(37, -26), Pair(120, 10), Pair(-25, 22),
        Pair(52, -95), Pair(24, -94), Pair(-10, -16), Pair(90, -74), Pair(58, 8), Pair(88, -9), Pair(79, -46), Pair(-21, -11),
        Pair(-43, -115), Pair(-182, 45), Pair(-77, 26), Pair(52, -54), Pair(36, -11), Pair(134, -47), Pair(137, -25), Pair(10, -64),
        Pair(23, -187), Pair(31, -31), Pair(-22, -2), Pair(-1, -2), Pair(0, 112), Pair(88, -22), Pair(-22, 80), Pair(65, -44),
        Pair(-19, -73), Pair(-67, -154), Pair(-56, -15), Pair(-66, 121), Pair(83, -6), Pair(0, 0), Pair(-57, -13), Pair(-37, 118),
        Pair(18, 68), Pair(-50, -22), Pair(-34, -67), Pair(-115, -47), Pair(-51, -13), Pair(-33, 146), Pair(1, 6), Pair(96, 76)
      },
      { // Piece 2
        Pair(-54, -3), Pair(-34, -110), Pair(14, 43), Pair(-171, 19), Pair(-68, 74), Pair(-87, -181), Pair(37, 135), Pair(-33, -104),
        Pair(-14, 45), Pair(71, 34), Pair(-51, 1), Pair(-77, 93), Pair(69, 4), Pair(-77, 94), Pair(52, -27), Pair(31, -36),
        Pair(-154, 146), Pair(146, -20), Pair(-122, 102), Pair(82, -26), Pair(-206, 121), Pair(35, -3), Pair(40, 62), Pair(20, -53),
        Pair(-15, -28), Pair(-90, 146), Pair(-140, 66), Pair(-9, 59), Pair(63, -42), Pair(164, -37), Pair(99, -77), Pair(-52, 78),
        Pair(-10, 76), Pair(-54, -54), Pair(-61, 155), Pair(20, 16), Pair(100, -9), Pair(8, -62), Pair(-17, 25), Pair(74, 46),
        Pair(10, 19), Pair(-90, 49), Pair(-5, 12), Pair(-27, 139), Pair(33, -31), Pair(140, -6), Pair(-63, -34), Pair(-197, 158),
        Pair(-203, -122), Pair(40, -39), Pair(-43, 59), Pair(-23, 15), Pair(-38, 135), Pair(0, 0), Pair(-1, 127), Pair(-67, -113),
        Pair(-39, 1), Pair(8, -19), Pair(26, -100), Pair(56, 36), Pair(11, -67), Pair(-54, 225), Pair(3, -46), Pair(53, 31)
      },
      { // Piece 3
        Pair(50, -8), Pair(-43, 18), Pair(-6, -28), Pair(34, 9), Pair(107, -69), Pair(108, -3), Pair(-20, -4), Pair(105, -21),
        Pair(3, -6), Pair(-15, -1), Pair(52, -3), Pair(-21, 22), Pair(-5, -20), Pair(111, 6), Pair(-21, 12), Pair(112, -44),
        Pair(9, 4), Pair(-59, 8), Pair(-8, -25), Pair(125, -40), Pair(6, -14), Pair(12, 3), Pair(43, -7), Pair(62, -25),
        Pair(19, -39), Pair(31, -36), Pair(-9, -34), Pair(-25, -7), Pair(16, -26), Pair(64, -7), Pair(64, -34), Pair(95, -88),
        Pair(17, -21), Pair(12, -15), Pair(-3, 22), Pair(-96, 40), Pair(70, -50), Pair(73, 15), Pair(-43, -24), Pair(-14, 22),
        Pair(25, -12), Pair(-131, 17), Pair(5, -34), Pair(82, -60), Pair(-7, -38), Pair(37, 32), Pair(-106, 62), Pair(13, -16),
        Pair(111, -64), Pair(-100, 17), Pair(-18, 5), Pair(-56, -2), Pair(41, 21), Pair(0, 0), Pair(253, -19), Pair(-88, 74),
        Pair(-36, 69), Pair(-23, 39), Pair(-13, 44), Pair(-33, 60), Pair(-35, -3), Pair(65, 85), Pair(-209, 83), Pair(-21, 41)
      },
      { // Piece 4
        Pair(12, -84), Pair(-28, -31), Pair(-119, -61), Pair(-10, 74), Pair(103, -109), Pair(0, -55), Pair(-14, -136), Pair(69, 73),
        Pair(-64, 107), Pair(-82, 34), Pair(9, 42), Pair(-48, 95), Pair(41, -11), Pair(103, -23), Pair(9, 19), Pair(12, -91),
        Pair(52, -92), Pair(33, -11), Pair(51, -62), Pair(5, -74), Pair(-73, 19), Pair(-124, 25), Pair(-39, 37), Pair(73, -103),
        Pair(-85, 49), Pair(32, -120), Pair(0, -5), Pair(42, -1), Pair(-78, 51), Pair(43, -30), Pair(-30, 59), Pair(7, -141),
        Pair(-15, -126), Pair(-19, 46), Pair(-36, -68), Pair(36, 20), Pair(-91, 108), Pair(132, -6), Pair(9, 51), Pair(-50, 100),
        Pair(-6, 31), Pair(6, -57), Pair(-23, -43), Pair(-32, 4), Pair(9, -48), Pair(-78, 46), Pair(112, 17), Pair(16, 14),
        Pair(9, -67), Pair(-62, 15), Pair(-34, -41), Pair(-53, 85), Pair(-86, 47), Pair(0, 0), Pair(-30, 30), Pair(-53, -42),
        Pair(-21, -80), Pair(-103, -71), Pair(-51, -9), Pair(-40, -148), Pair(-68, -66), Pair(-43, -77), Pair(-18, -61), Pair(-26, -51)
      },
      { // Piece 5
        Pair(-9, -77), Pair(-3, -92), Pair(26, -132), Pair(-16, -13), Pair(-39, -75), Pair(-30, -73), Pair(-3, -58), Pair(32, 109),
        Pair(-14, -123), Pair(-60, -91), Pair(67, -96), Pair(23, -72), Pair(-31, -78), Pair(34, -25), Pair(-32, -100), Pair(22, -45),
        Pair(-42, -100), Pair(50, -41), Pair(155, -47), Pair(118, -67), Pair(16, -11), Pair(-120, -25), Pair(39, -3), Pair(43, 25),
        Pair(3, -74), Pair(-78, -27), Pair(-3, -10), Pair(128, -30), Pair(-42, 2), Pair(4, -3), Pair(-52, -7), Pair(3, -3),
        Pair(-53, -23), Pair(-36, -23), Pair(28, -2), Pair(45, 1), Pair(154, -16), Pair(75, 3), Pair(199, -8), Pair(154, -29),
        Pair(-49, -18), Pair(-151, -4), Pair(68, -36), Pair(59, 18), Pair(-40, 62), Pair(-60, 89), Pair(-62, 94), Pair(-70, 70),
        Pair(-119, -11), Pair(43, -34), Pair(36, -23), Pair(-93, 72), Pair(-36, 121), Pair(0, 0), Pair(-53, 126), Pair(-29, 29),
        Pair(-50, -14), Pair(-4, -68), Pair(8, -41), Pair(45, -24), Pair(94, 128), Pair(-55, 153), Pair(76, 64), Pair(-116, 71)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, -4), Pair(15, -9), Pair(-42, 6), Pair(-91, 46), Pair(-2, -7), Pair(121, -27), Pair(0, 0), Pair(68, -13),
        Pair(-2, -15), Pair(4, -10), Pair(-3, -5), Pair(3, -15), Pair(-5, -2), Pair(-6, 16), Pair(6, -21), Pair(-30, 15),
        Pair(9, -19), Pair(-24, -14), Pair(-3, -9), Pair(-20, -22), Pair(-16, -8), Pair(15, -10), Pair(-4, -2), Pair(9, -21),
        Pair(10, -23), Pair(17, -14), Pair(-23, -10), Pair(-3, -15), Pair(7, -19), Pair(2, -6), Pair(-3, -26), Pair(18, -13),
        Pair(12, -20), Pair(-15, -14), Pair(18, -21), Pair(-21, -7), Pair(17, -25), Pair(11, -5), Pair(-4, -8), Pair(20, -3),
        Pair(18, -26), Pair(-17, -5), Pair(0, -14), Pair(-30, 23), Pair(13, -26), Pair(36, -14), Pair(0, 0), Pair(17, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(59, -2), Pair(-161, -133), Pair(59, -71), Pair(9, -43), Pair(96, 60), Pair(128, -56), Pair(-12, -29), Pair(-4, 12),
        Pair(-82, -101), Pair(-150, -53), Pair(252, -210), Pair(-125, 15), Pair(-25, -6), Pair(-135, -45), Pair(-74, 37), Pair(-46, -58),
        Pair(25, -30), Pair(107, -114), Pair(-23, 14), Pair(99, -55), Pair(49, -33), Pair(63, -28), Pair(18, 23), Pair(94, -150),
        Pair(33, -33), Pair(-6, -27), Pair(-37, 20), Pair(121, -15), Pair(81, -8), Pair(22, 27), Pair(33, -7), Pair(114, -27),
        Pair(-42, -40), Pair(68, -45), Pair(-37, -19), Pair(-38, 23), Pair(39, -13), Pair(44, 16), Pair(-146, 80), Pair(-33, 99),
        Pair(25, -10), Pair(-43, -14), Pair(55, -61), Pair(-54, 6), Pair(42, -16), Pair(-8, 79), Pair(-26, 63), Pair(-104, 110),
        Pair(-69, -59), Pair(152, 66), Pair(14, -20), Pair(-32, 59), Pair(-78, 96), Pair(158, -71), Pair(0, 0), Pair(11, -35),
        Pair(-15, -13), Pair(21, -128), Pair(-79, 3), Pair(-88, -28), Pair(-66, 29), Pair(14, -42), Pair(-28, 152), Pair(-22, -51)
      },
      { // Piece 2
        Pair(19, 55), Pair(-126, 48), Pair(-68, -74), Pair(-61, 116), Pair(-2, 9), Pair(-71, 125), Pair(-30, 1), Pair(27, -12),
        Pair(-170, 144), Pair(-70, 38), Pair(-125, 78), Pair(-17, -9), Pair(-31, 107), Pair(-38, -55), Pair(5, 50), Pair(84, -80),
        Pair(-41, -28), Pair(-223, 168), Pair(-73, 98), Pair(-7, 110), Pair(93, -29), Pair(70, 48), Pair(53, 0), Pair(-46, 22),
        Pair(-173, 94), Pair(-6, -1), Pair(-104, 140), Pair(52, 40), Pair(-36, 69), Pair(58, -12), Pair(-25, 67), Pair(141, -38),
        Pair(-35, -3), Pair(-163, 66), Pair(28, 16), Pair(-20, 122), Pair(13, 58), Pair(-70, 23), Pair(147, -57), Pair(18, 24),
        Pair(-87, 79), Pair(-1, -27), Pair(-51, 23), Pair(-23, -31), Pair(-75, 137), Pair(-13, 52), Pair(6, 44), Pair(51, 20),
        Pair(73, 44), Pair(-36, 56), Pair(-47, -15), Pair(-80, 21), Pair(-11, 3), Pair(66, 137), Pair(0, 0), Pair(-74, 156),
        Pair(96, 19), Pair(110, -12), Pair(-122, 64), Pair(5, -60), Pair(-167, 112), Pair(-50, -43), Pair(-1, 209), Pair(11, 5)
      },
      { // Piece 3
        Pair(-185, 62), Pair(-55, 1), Pair(21, -14), Pair(-35, 15), Pair(239, -59), Pair(14, 6), Pair(103, 5), Pair(196, -46),
        Pair(2, -20), Pair(-45, 9), Pair(54, -42), Pair(110, -72), Pair(33, -6), Pair(85, -50), Pair(113, 9), Pair(-75, 11),
        Pair(-62, -7), Pair(35, -30), Pair(-103, 29), Pair(29, -44), Pair(12, -14), Pair(36, -12), Pair(-2, 26), Pair(14, -11),
        Pair(49, -47), Pair(82, -40), Pair(-52, 12), Pair(-5, -17), Pair(89, -45), Pair(-25, -21), Pair(98, 0), Pair(81, -43),
        Pair(-82, -20), Pair(45, -44), Pair(60, -68), Pair(-16, -77), Pair(33, -22), Pair(166, -86), Pair(119, -6), Pair(64, -31),
        Pair(-33, -59), Pair(115, -73), Pair(89, -47), Pair(30, -27), Pair(16, -38), Pair(72, -107), Pair(186, -51), Pair(-16, -1),
        Pair(-96, 6), Pair(-87, 9), Pair(-43, 7), Pair(-86, 32), Pair(-11, -20), Pair(93, -27), Pair(0, 0), Pair(55, -61),
        Pair(-53, 52), Pair(-4, 62), Pair(-32, 54), Pair(-46, 58), Pair(-7, 48), Pair(-54, 15), Pair(-4, 105), Pair(-54, 27)
      },
      { // Piece 4
        Pair(-26, 92), Pair(-73, 14), Pair(-108, -9), Pair(-70, 1), Pair(-31, -33), Pair(1, -13), Pair(-120, -134), Pair(-6, -68),
        Pair(27, -16), Pair(-52, -13), Pair(-92, 66), Pair(-24, 0), Pair(12, 31), Pair(42, 16), Pair(67, 75), Pair(-48, 5),
        Pair(-53, -179), Pair(39, -54), Pair(-8, -15), Pair(-24, 29), Pair(-7, 37), Pair(-48, -17), Pair(-24, 1), Pair(94, -55),
        Pair(40, 11), Pair(30, -68), Pair(25, -57), Pair(27, 4), Pair(5, 62), Pair(40, -20), Pair(-129, 104), Pair(44, -7),
        Pair(-8, -120), Pair(-14, -48), Pair(23, -29), Pair(0, -7), Pair(-41, 67), Pair(-48, 32), Pair(64, -102), Pair(8, -74),
        Pair(-71, -85), Pair(-37, -71), Pair(-86, 116), Pair(-7, 23), Pair(32, -104), Pair(27, -89), Pair(1, -1), Pair(-26, -67),
        Pair(35, 10), Pair(-40, -96), Pair(-27, -15), Pair(-62, 36), Pair(-128, 109), Pair(45, 122), Pair(0, 0), Pair(-150, -58),
        Pair(-53, -11), Pair(68, -14), Pair(-5, -116), Pair(1, -104), Pair(36, -56), Pair(-171, -89), Pair(72, -132), Pair(1, 1)
      },
      { // Piece 5
        Pair(15, -99), Pair(-21, -127), Pair(-19, -75), Pair(-2, -119), Pair(-22, -23), Pair(14, 2), Pair(-10, -86), Pair(-17, -12),
        Pair(-6, -113), Pair(-36, -29), Pair(85, -90), Pair(-3, -72), Pair(-25, -45), Pair(27, -12), Pair(-17, -61), Pair(5, -16),
        Pair(-27, -18), Pair(-2, -50), Pair(17, -28), Pair(-62, -36), Pair(151, -17), Pair(98, 3), Pair(-47, -30), Pair(-25, -79),
        Pair(21, -89), Pair(5, -55), Pair(2, -6), Pair(-20, 12), Pair(-11, 36), Pair(71, 15), Pair(93, -22), Pair(-4, -16),
        Pair(-69, -50), Pair(2, -39), Pair(77, -38), Pair(-43, 7), Pair(163, -14), Pair(45, 49), Pair(80, 6), Pair(6, 6),
        Pair(-1, -111), Pair(-57, -23), Pair(47, -43), Pair(-171, 58), Pair(-83, 46), Pair(-16, 83), Pair(-107, 75), Pair(23, 82),
        Pair(4, -50), Pair(-83, -19), Pair(-18, -25), Pair(-12, 17), Pair(36, 34), Pair(-23, 136), Pair(0, 0), Pair(-36, 170),
        Pair(-18, -68), Pair(-46, -56), Pair(68, -97), Pair(38, -68), Pair(-74, 2), Pair(17, 105), Pair(18, 179), Pair(142, 19)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-29, 2), Pair(-13, -8), Pair(-2, -11), Pair(-29, -4), Pair(27, -2), Pair(87, -18), Pair(-68, 13), Pair(0, 0),
        Pair(0, -5), Pair(32, -18), Pair(-20, -4), Pair(-3, -10), Pair(11, -11), Pair(-17, -13), Pair(-20, 15), Pair(66, -1),
        Pair(16, -29), Pair(7, -18), Pair(31, -22), Pair(-12, -11), Pair(-7, -11), Pair(-34, -4), Pair(30, -16), Pair(-75, 29),
        Pair(0, -21), Pair(-8, -26), Pair(-14, -7), Pair(-9, -15), Pair(-2, -17), Pair(-20, -3), Pair(4, -21), Pair(42, -52),
        Pair(-9, -20), Pair(-8, -17), Pair(13, -22), Pair(-4, -10), Pair(11, -25), Pair(9, -18), Pair(8, -17), Pair(-23, -17),
        Pair(3, -26), Pair(2, -16), Pair(14, -27), Pair(20, -36), Pair(-15, -13), Pair(-8, -8), Pair(13, -6), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-124, -131), Pair(-1, -157), Pair(21, -146), Pair(-122, -53), Pair(43, -4), Pair(-29, -144), Pair(1, -89), Pair(9, -70),
        Pair(-43, -54), Pair(5, -111), Pair(39, -105), Pair(30, -50), Pair(101, -47), Pair(3, -59), Pair(214, -11), Pair(-65, -51),
        Pair(-69, -47), Pair(112, -121), Pair(-66, -12), Pair(-21, -36), Pair(-96, -11), Pair(-58, -28), Pair(-7, -71), Pair(-47, -99),
        Pair(-19, -68), Pair(92, -85), Pair(10, -41), Pair(36, -27), Pair(103, -34), Pair(150, -84), Pair(230, -124), Pair(119, -64),
        Pair(-58, -86), Pair(20, -60), Pair(-35, -3), Pair(61, -27), Pair(122, -73), Pair(23, -3), Pair(84, -44), Pair(157, -83),
        Pair(-90, -49), Pair(139, -136), Pair(13, -59), Pair(-86, 28), Pair(-29, -27), Pair(36, 14), Pair(-26, 42), Pair(37, -54),
        Pair(-91, -89), Pair(-63, -31), Pair(-62, -125), Pair(23, -55), Pair(14, -7), Pair(-53, 69), Pair(57, -65), Pair(0, 0),
        Pair(1, -18), Pair(-72, -26), Pair(-227, -27), Pair(98, -139), Pair(10, -37), Pair(-158, -18), Pair(-145, -167), Pair(-179, 147)
      },
      { // Piece 2
        Pair(-38, 153), Pair(-56, -25), Pair(36, 62), Pair(114, -25), Pair(24, 82), Pair(83, 9), Pair(5, 100), Pair(-97, -184),
        Pair(92, -86), Pair(-55, 160), Pair(-55, 55), Pair(-64, 90), Pair(-61, -2), Pair(-80, 101), Pair(-3, 11), Pair(12, 28),
        Pair(32, 73), Pair(150, -59), Pair(-59, 146), Pair(-13, 13), Pair(-7, 72), Pair(51, -16), Pair(19, 21), Pair(-33, 43),
        Pair(65, -51), Pair(-11, 78), Pair(42, -14), Pair(16, 119), Pair(27, 36), Pair(-64, 56), Pair(12, -98), Pair(35, 27),
        Pair(-15, 39), Pair(-31, -72), Pair(55, 13), Pair(23, -21), Pair(3, 111), Pair(-3, -6), Pair(61, -38), Pair(166, 19),
        Pair(-22, -21), Pair(-30, 22), Pair(7, -44), Pair(77, -4), Pair(7, -22), Pair(-17, 133), Pair(-107, 86), Pair(15, 20),
        Pair(40, 33), Pair(-11, 22), Pair(8, 33), Pair(-3, -41), Pair(-44, 34), Pair(120, -118), Pair(14, 136), Pair(0, 0),
        Pair(-132, -10), Pair(71, -27), Pair(-60, 6), Pair(-55, 28), Pair(21, -112), Pair(1, 60), Pair(-25, -99), Pair(74, 194)
      },
      { // Piece 3
        Pair(141, -47), Pair(-1, 3), Pair(-82, -5), Pair(34, -47), Pair(-76, 4), Pair(8, 11), Pair(114, -14), Pair(127, -2),
        Pair(25, -17), Pair(-51, 1), Pair(124, -71), Pair(39, -54), Pair(-64, 36), Pair(-115, 19), Pair(48, -21), Pair(44, 34),
        Pair(76, -40), Pair(18, -34), Pair(82, -6), Pair(28, -41), Pair(79, -49), Pair(68, -60), Pair(40, -10), Pair(19, 14),
        Pair(58, -25), Pair(-34, -12), Pair(-35, -5), Pair(43, -22), Pair(-75, 22), Pair(70, -5), Pair(64, -33), Pair(-53, 44),
        Pair(92, -92), Pair(19, -46), Pair(179, -86), Pair(-45, 9), Pair(-11, -15), Pair(122, -47), Pair(-38, -42), Pair(17, 4),
        Pair(86, -63), Pair(-20, -20), Pair(197, -111), Pair(27, -11), Pair(-47, 1), Pair(-75, 62), Pair(74, -35), Pair(27, 44),
        Pair(53, -51), Pair(46, -6), Pair(0, 34), Pair(-108, 11), Pair(-74, 62), Pair(80, -66), Pair(77, -34), Pair(0, 0),
        Pair(-25, 65), Pair(-32, 56), Pair(-57, 73), Pair(-16, 53), Pair(5, 56), Pair(36, 62), Pair(191, 14), Pair(-16, 124)
      },
      { // Piece 4
        Pair(47, -33), Pair(-38, -26), Pair(-18, -38), Pair(-73, -11), Pair(31, -26), Pair(41, -73), Pair(-10, -43), Pair(39, -2),
        Pair(-28, 82), Pair(-92, 72), Pair(-76, 82), Pair(-14, 142), Pair(-20, 4), Pair(79, 16), Pair(54, -33), Pair(-15, -45),
        Pair(43, -97), Pair(-37, 3), Pair(90, -136), Pair(-2, -26), Pair(-93, 48), Pair(85, -22), Pair(97, 103), Pair(-77, 39),
        Pair(-108, -68), Pair(83, -41), Pair(13, 43), Pair(-31, 45), Pair(-56, -25), Pair(34, -84), Pair(6, 67), Pair(57, -101),
        Pair(48, -132), Pair(-25, -4), Pair(-97, 37), Pair(35, -97), Pair(13, 40), Pair(-9, -73), Pair(-38, -26), Pair(107, -43),
        Pair(44, 55), Pair(-15, -19), Pair(-72, -2), Pair(-64, 53), Pair(12, -58), Pair(-21, 18), Pair(-4, -21), Pair(2, -77),
        Pair(98, -32), Pair(0, -22), Pair(30, -123), Pair(-42, -106), Pair(-47, 31), Pair(-27, 95), Pair(25, -58), Pair(0, 0),
        Pair(32, -98), Pair(-200, 35), Pair(5, -75), Pair(-31, -6), Pair(-31, -64), Pair(-61, 38), Pair(-85, -51), Pair(-91, -33)
      },
      { // Piece 5
        Pair(9, -79), Pair(40, -138), Pair(6, -84), Pair(-8, -125), Pair(7, 80), Pair(-12, -56), Pair(10, 7), Pair(-18, -82),
        Pair(76, -109), Pair(7, -85), Pair(-30, -53), Pair(-30, -68), Pair(-32, -32), Pair(11, -23), Pair(-20, -62), Pair(-10, -93),
        Pair(-17, -64), Pair(-49, -42), Pair(9, -38), Pair(-12, -21), Pair(236, -66), Pair(129, -23), Pair(51, -7), Pair(-12, -57),
        Pair(92, -98), Pair(29, -45), Pair(-95, -11), Pair(65, -27), Pair(46, 18), Pair(84, 28), Pair(113, 5), Pair(8, -41),
        Pair(-18, -62), Pair(-62, -37), Pair(210, -56), Pair(7, 7), Pair(-30, 41), Pair(25, 38), Pair(-67, 54), Pair(20, 4),
        Pair(26, -29), Pair(-16, -75), Pair(-3, -36), Pair(53, -6), Pair(-66, 48), Pair(26, 48), Pair(-150, 129), Pair(-85, 114),
        Pair(-56, -45), Pair(-23, -33), Pair(-21, -43), Pair(-111, 13), Pair(-94, 64), Pair(-37, 71), Pair(-136, 174), Pair(0, 0),
        Pair(-52, -125), Pair(-94, -73), Pair(-76, -53), Pair(-70, -9), Pair(-97, 37), Pair(-240, 105), Pair(99, 89), Pair(126, 142)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, 3), Pair(29, -6), Pair(5, 8), Pair(-19, 5), Pair(-37, 15), Pair(-11, 22), Pair(2, 15), Pair(1, 6),
        Pair(0, 0), Pair(-6, -2), Pair(18, -10), Pair(-1, -6), Pair(1, 0), Pair(-4, 3), Pair(-13, 9), Pair(-8, 13),
        Pair(30, -9), Pair(2, -2), Pair(2, -10), Pair(5, -15), Pair(-4, -4), Pair(-8, 1), Pair(-2, 5), Pair(-13, 5),
        Pair(-17, 11), Pair(1, -11), Pair(0, -6), Pair(6, -11), Pair(0, -3), Pair(-5, -4), Pair(-9, -2), Pair(-6, -2),
        Pair(0, 0), Pair(2, -7), Pair(-4, -9), Pair(2, -15), Pair(-7, -8), Pair(-10, -6), Pair(-3, -11), Pair(-6, -9),
        Pair(21, 35), Pair(-3, -23), Pair(-4, -5), Pair(-3, -9), Pair(-5, -9), Pair(-6, -11), Pair(-2, -8), Pair(-4, -14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-3, -41), Pair(-19, -55), Pair(66, -87), Pair(79, -78), Pair(171, -83), Pair(-15, -22), Pair(-55, -116), Pair(-143, -46),
        Pair(-53, 45), Pair(44, -51), Pair(76, -44), Pair(-11, 37), Pair(30, -6), Pair(31, -38), Pair(15, -55), Pair(97, -64),
        Pair(143, -6), Pair(42, -23), Pair(8, -3), Pair(57, -16), Pair(62, -10), Pair(72, -17), Pair(50, -50), Pair(73, -59),
        Pair(41, -10), Pair(36, 2), Pair(26, 3), Pair(45, -20), Pair(36, -8), Pair(48, -23), Pair(47, -25), Pair(64, -44),
        Pair(9, -34), Pair(-8, 42), Pair(16, -5), Pair(18, 4), Pair(40, -17), Pair(37, -22), Pair(41, -39), Pair(32, -22),
        Pair(0, 0), Pair(-10, 8), Pair(7, 44), Pair(5, -6), Pair(28, -5), Pair(16, -22), Pair(32, -25), Pair(0, 4),
        Pair(37, 89), Pair(27, -96), Pair(14, 16), Pair(16, -9), Pair(24, -18), Pair(-1, -32), Pair(21, -24), Pair(31, -64),
        Pair(-142, 48), Pair(0, 18), Pair(-45, 48), Pair(48, -70), Pair(13, -1), Pair(13, -35), Pair(33, -75), Pair(-43, -25)
      },
      { // Piece 2
        Pair(-130, 76), Pair(97, 30), Pair(-126, 68), Pair(-85, 76), Pair(68, 43), Pair(4, 47), Pair(-174, 152), Pair(74, 44),
        Pair(29, 15), Pair(-16, 33), Pair(27, 25), Pair(-51, 76), Pair(-1, 88), Pair(-42, 123), Pair(11, 61), Pair(-6, 17),
        Pair(-33, 43), Pair(22, 14), Pair(-21, 39), Pair(7, 63), Pair(-57, 121), Pair(1, 81), Pair(-45, 56), Pair(30, 30),
        Pair(40, 43), Pair(-1, 9), Pair(10, 66), Pair(-22, 100), Pair(25, 65), Pair(3, 40), Pair(38, 22), Pair(31, -1),
        Pair(16, 35), Pair(10, 56), Pair(-11, 84), Pair(17, 40), Pair(13, 13), Pair(8, 30), Pair(-10, 22), Pair(13, 29),
        Pair(0, 0), Pair(-20, 94), Pair(15, 55), Pair(-4, 34), Pair(19, 26), Pair(2, 7), Pair(13, 2), Pair(8, 4),
        Pair(7, 160), Pair(12, 36), Pair(9, 27), Pair(19, 34), Pair(-1, 11), Pair(7, 31), Pair(-5, 7), Pair(10, 12),
        Pair(12, 11), Pair(-10, 86), Pair(11, 22), Pair(-3, -3), Pair(6, 27), Pair(-12, 4), Pair(8, 25), Pair(2, 1)
      },
      { // Piece 3
        Pair(48, 90), Pair(9, 63), Pair(38, 54), Pair(18, 66), Pair(54, 54), Pair(173, 1), Pair(80, 27), Pair(112, 36),
        Pair(71, 92), Pair(12, 55), Pair(41, 63), Pair(20, 76), Pair(36, 44), Pair(57, 35), Pair(-7, 75), Pair(96, 39),
        Pair(12, 106), Pair(25, 47), Pair(28, 68), Pair(52, 40), Pair(52, 38), Pair(20, 57), Pair(50, 28), Pair(0, 58),
        Pair(-17, 110), Pair(27, 39), Pair(0, 55), Pair(15, 54), Pair(29, 41), Pair(49, 34), Pair(37, 41), Pair(34, 26),
        Pair(-1, 86), Pair(21, 52), Pair(-1, 57), Pair(4, 48), Pair(-2, 46), Pair(31, 41), Pair(38, 28), Pair(23, 43),
        Pair(0, 0), Pair(28, 72), Pair(-15, 73), Pair(10, 51), Pair(3, 55), Pair(14, 50), Pair(37, 25), Pair(59, 41),
        Pair(-2, 105), Pair(27, 7), Pair(-10, 80), Pair(-2, 62), Pair(-7, 60), Pair(6, 60), Pair(2, 79), Pair(-19, 95),
        Pair(-13, 77), Pair(6, 55), Pair(10, 53), Pair(8, 49), Pair(13, 48), Pair(13, 50), Pair(40, 32), Pair(27, 37)
      },
      { // Piece 4
        Pair(72, 31), Pair(180, -48), Pair(44, 53), Pair(-21, 106), Pair(39, 104), Pair(103, 59), Pair(96, -6), Pair(42, 77),
        Pair(26, 97), Pair(13, 95), Pair(14, 83), Pair(-18, 144), Pair(-25, 123), Pair(70, 45), Pair(39, 82), Pair(61, 59),
        Pair(-25, 131), Pair(20, 37), Pair(-15, 87), Pair(42, 77), Pair(39, 110), Pair(24, 52), Pair(74, -3), Pair(59, 39),
        Pair(29, 40), Pair(6, 56), Pair(0, 90), Pair(-11, 106), Pair(28, 69), Pair(19, 77), Pair(41, 49), Pair(41, 46),
        Pair(4, 88), Pair(-2, 100), Pair(11, 69), Pair(11, 48), Pair(15, 66), Pair(29, 9), Pair(33, 48), Pair(33, 39),
        Pair(0, 0), Pair(0, 71), Pair(-4, 73), Pair(11, 53), Pair(8, 40), Pair(15, 52), Pair(25, 31), Pair(37, 14),
        Pair(-26, 83), Pair(-4, 33), Pair(-4, 67), Pair(-1, 62), Pair(-1, 48), Pair(11, 27), Pair(12, 7), Pair(52, -20),
        Pair(-11, 58), Pair(0, 24), Pair(-10, 71), Pair(1, 36), Pair(5, 41), Pair(-17, 62), Pair(-4, 109), Pair(-48, 100)
      },
      { // Piece 5
        Pair(-19, -20), Pair(-7, -48), Pair(-3, 2), Pair(75, -23), Pair(40, -74), Pair(6, -130), Pair(52, -80), Pair(75, -89),
        Pair(26, -98), Pair(-66, -43), Pair(-21, -36), Pair(-30, -40), Pair(102, -47), Pair(80, -87), Pair(91, -105), Pair(18, -46),
        Pair(22, -44), Pair(3, -14), Pair(98, -35), Pair(48, -20), Pair(184, -56), Pair(62, -47), Pair(137, -76), Pair(-16, -55),
        Pair(25, -66), Pair(141, -18), Pair(-23, 17), Pair(84, -23), Pair(127, -41), Pair(185, -52), Pair(92, -62), Pair(49, -64),
        Pair(-48, 36), Pair(-139, 81), Pair(50, 0), Pair(30, -8), Pair(18, -12), Pair(45, -34), Pair(37, -57), Pair(77, -70),
        Pair(0, 0), Pair(-177, 120), Pair(-52, 29), Pair(-22, 10), Pair(4, -14), Pair(18, -27), Pair(24, -49), Pair(12, -56),
        Pair(-1, 100), Pair(36, 6), Pair(-74, 47), Pair(-37, 17), Pair(-13, -5), Pair(-15, -26), Pair(-15, -35), Pair(0, -41),
        Pair(-27, 75), Pair(-44, 65), Pair(-53, 10), Pair(8, -21), Pair(-35, -29), Pair(-3, -38), Pair(-1, -58), Pair(4, -58)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 11), Pair(23, -22), Pair(6, 6), Pair(5, 5), Pair(-2, 20), Pair(28, 6), Pair(-4, 10), Pair(-32, 18),
        Pair(6, 1), Pair(0, 0), Pair(-7, 4), Pair(5, -1), Pair(-6, 7), Pair(-12, 10), Pair(-14, 9), Pair(-16, 15),
        Pair(2, 1), Pair(5, -11), Pair(1, -4), Pair(0, -7), Pair(-5, 2), Pair(-6, 3), Pair(0, 1), Pair(-10, 7),
        Pair(2, -9), Pair(-16, -1), Pair(6, -9), Pair(3, -5), Pair(-3, -6), Pair(-10, -4), Pair(-8, -6), Pair(-6, -4),
        Pair(8, -2), Pair(0, 0), Pair(6, -8), Pair(-6, 0), Pair(-3, -5), Pair(-13, -7), Pair(-11, -4), Pair(-15, -5),
        Pair(7, -1), Pair(38, 38), Pair(7, -16), Pair(-8, 9), Pair(-12, -4), Pair(-13, -8), Pair(-9, -7), Pair(-10, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(59, -68), Pair(-70, -84), Pair(29, -10), Pair(-6, -44), Pair(-51, 5), Pair(94, -1), Pair(-19, -69), Pair(-19, -38),
        Pair(180, -30), Pair(63, -26), Pair(27, -19), Pair(98, -17), Pair(68, -6), Pair(27, -24), Pair(3, -24), Pair(82, -20),
        Pair(160, -46), Pair(35, -9), Pair(49, 0), Pair(38, -2), Pair(37, 7), Pair(57, 5), Pair(65, -38), Pair(74, -64),
        Pair(-18, 17), Pair(17, 7), Pair(41, 17), Pair(38, 5), Pair(46, 11), Pair(48, 6), Pair(54, -4), Pair(48, -14),
        Pair(8, 48), Pair(-2, 10), Pair(-3, 86), Pair(24, 7), Pair(47, 25), Pair(25, 4), Pair(55, -9), Pair(29, 0),
        Pair(20, 23), Pair(0, 0), Pair(22, 17), Pair(10, 84), Pair(17, 17), Pair(18, 17), Pair(27, -7), Pair(72, -33),
        Pair(1, -58), Pair(-1, 149), Pair(-43, 26), Pair(34, 9), Pair(12, 4), Pair(16, 2), Pair(32, -26), Pair(2, 19),
        Pair(-130, -35), Pair(-27, 66), Pair(24, -31), Pair(-37, 92), Pair(25, -54), Pair(7, 6), Pair(-13, 49), Pair(-38, -105)
      },
      { // Piece 2
        Pair(53, 8), Pair(4, 46), Pair(-83, 54), Pair(-17, 77), Pair(-106, 56), Pair(-26, 39), Pair(5, 53), Pair(21, 131),
        Pair(70, -2), Pair(-46, 74), Pair(-22, 51), Pair(-82, 67), Pair(-32, 73), Pair(19, 82), Pair(0, 125), Pair(16, 48),
        Pair(-4, 41), Pair(-41, 31), Pair(54, 22), Pair(-7, 47), Pair(27, 46), Pair(-16, 115), Pair(-37, 99), Pair(41, 18),
        Pair(27, 18), Pair(22, 30), Pair(-15, 58), Pair(-7, 65), Pair(5, 111), Pair(18, 78), Pair(8, 48), Pair(45, 17),
        Pair(-21, 40), Pair(35, 11), Pair(-7, 71), Pair(-6, 105), Pair(3, 71), Pair(-7, 26), Pair(6, 40), Pair(28, 18),
        Pair(3, 123), Pair(0, 0), Pair(-7, 89), Pair(-4, 53), Pair(12, 17), Pair(6, 31), Pair(6, -4), Pair(5, 14),
        Pair(-121, 114), Pair(34, 168), Pair(-20, -1), Pair(2, 25), Pair(-8, 36), Pair(7, 8), Pair(2, 27), Pair(4, -10),
        Pair(-41, 142), Pair(-28, 42), Pair(-36, 86), Pair(-16, 18), Pair(-45, 31), Pair(15, 35), Pair(-50, 42), Pair(24, 45)
      },
      { // Piece 3
        Pair(71, 33), Pair(15, 81), Pair(42, 48), Pair(85, 5), Pair(76, 16), Pair(184, 3), Pair(-45, 71), Pair(126, 15),
        Pair(40, 41), Pair(18, 89), Pair(8, 68), Pair(18, 52), Pair(43, 46), Pair(105, -4), Pair(109, 7), Pair(129, -7),
        Pair(11, 39), Pair(63, 77), Pair(10, 48), Pair(49, 48), Pair(42, 20), Pair(56, 36), Pair(110, 5), Pair(76, 10),
        Pair(10, 29), Pair(25, 83), Pair(-10, 42), Pair(42, 25), Pair(19, 48), Pair(33, 36), Pair(30, 32), Pair(63, 12),
        Pair(2, 34), Pair(-8, 90), Pair(14, 28), Pair(-25, 55), Pair(16, 41), Pair(-23, 54), Pair(50, 35), Pair(68, -22),
        Pair(-1, 13), Pair(0, 0), Pair(31, 34), Pair(26, 53), Pair(-2, 32), Pair(38, 28), Pair(46, 11), Pair(-2, 64),
        Pair(-56, 61), Pair(0, 94), Pair(-6, 49), Pair(-16, 61), Pair(3, 50), Pair(-11, 70), Pair(-13, 72), Pair(-23, 84),
        Pair(-9, 45), Pair(-24, 88), Pair(-10, 50), Pair(6, 32), Pair(12, 32), Pair(6, 51), Pair(10, 29), Pair(6, 40)
      },
      { // Piece 4
        Pair(139, -68), Pair(14, 51), Pair(-39, 101), Pair(38, 59), Pair(15, 91), Pair(106, 33), Pair(40, 34), Pair(61, 75),
        Pair(56, -8), Pair(32, 38), Pair(47, 6), Pair(-24, 116), Pair(85, 42), Pair(45, 106), Pair(13, 66), Pair(21, 79),
        Pair(9, 59), Pair(48, 1), Pair(80, -45), Pair(13, 88), Pair(56, 54), Pair(52, 98), Pair(45, 45), Pair(95, -13),
        Pair(49, -62), Pair(43, 26), Pair(-40, 147), Pair(26, 48), Pair(63, 46), Pair(19, 89), Pair(59, 5), Pair(48, 32),
        Pair(-41, 64), Pair(42, -16), Pair(-22, 123), Pair(-2, 92), Pair(14, 30), Pair(41, 14), Pair(25, 35), Pair(17, 74),
        Pair(22, -32), Pair(0, 0), Pair(5, 94), Pair(-4, 49), Pair(26, 19), Pair(27, 31), Pair(30, 29), Pair(16, 91),
        Pair(-33, -16), Pair(18, 14), Pair(27, -6), Pair(19, 36), Pair(12, 35), Pair(31, 4), Pair(24, -4), Pair(19, 3),
        Pair(20, 8), Pair(-2, 16), Pair(-13, 63), Pair(14, -37), Pair(20, 25), Pair(22, -47), Pair(58, -60), Pair(-21, -23)
      },
      { // Piece 5
        Pair(-43, -155), Pair(-61, -145), Pair(50, -30), Pair(-54, -73), Pair(-5, -25), Pair(-22, -118), Pair(-55, -81), Pair(2, -89),
        Pair(-13, -20), Pair(4, -38), Pair(-13, -50), Pair(-18, -1), Pair(115, -53), Pair(28, -65), Pair(34, -71), Pair(-5, -62),
        Pair(32, -19), Pair(69, -62), Pair(70, -15), Pair(72, -42), Pair(112, -28), Pair(102, -49), Pair(12, -53), Pair(49, -76),
        Pair(-26, -11), Pair(101, -73), Pair(167, -32), Pair(13, 1), Pair(64, -21), Pair(-27, -6), Pair(13, -33), Pair(112, -77),
        Pair(69, 15), Pair(-53, 32), Pair(-24, 43), Pair(24, -5), Pair(-45, 8), Pair(-6, -11), Pair(18, -42), Pair(94, -83),
        Pair(-218, 140), Pair(0, 0), Pair(-77, 77), Pair(2, 6), Pair(-21, 2), Pair(-10, -6), Pair(34, -48), Pair(32, -52),
        Pair(79, 42), Pair(-118, 103), Pair(0, 96), Pair(-90, 26), Pair(-27, 5), Pair(-15, -27), Pair(-11, -32), Pair(11, -48),
        Pair(-120, 89), Pair(-98, 69), Pair(-89, 80), Pair(-67, 5), Pair(-50, -2), Pair(-19, -34), Pair(3, -59), Pair(20, -70)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 18), Pair(3, 13), Pair(-25, 8), Pair(24, -1), Pair(25, 9), Pair(47, 6), Pair(3, 5), Pair(20, 4),
        Pair(-18, 12), Pair(6, -5), Pair(0, 0), Pair(-4, 0), Pair(4, 2), Pair(3, 3), Pair(-3, 13), Pair(-15, 5),
        Pair(0, -6), Pair(4, -10), Pair(1, -13), Pair(1, 1), Pair(1, -9), Pair(-3, -1), Pair(1, 1), Pair(-15, 6),
        Pair(-3, -8), Pair(0, -12), Pair(5, -12), Pair(0, -2), Pair(-1, -6), Pair(-4, -6), Pair(-10, -2), Pair(-11, -2),
        Pair(1, -3), Pair(0, 0), Pair(0, 0), Pair(1, -6), Pair(-5, 0), Pair(-12, -10), Pair(-9, -5), Pair(-14, -2),
        Pair(3, -5), Pair(10, -10), Pair(35, 36), Pair(7, -27), Pair(-6, 1), Pair(-6, -7), Pair(-6, -7), Pair(-9, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, -10), Pair(86, -45), Pair(-13, -13), Pair(6, -9), Pair(103, -20), Pair(6, 45), Pair(57, -138), Pair(-107, -20),
        Pair(-51, -12), Pair(60, -27), Pair(-4, 17), Pair(50, -8), Pair(46, 23), Pair(57, 22), Pair(28, 7), Pair(56, -80),
        Pair(129, -27), Pair(30, 12), Pair(22, 13), Pair(20, 33), Pair(53, -6), Pair(62, 5), Pair(37, 48), Pair(60, -33),
        Pair(4, 16), Pair(19, 19), Pair(62, 7), Pair(41, 27), Pair(32, 21), Pair(54, 14), Pair(28, -1), Pair(54, -5),
        Pair(1, 1), Pair(-1, 95), Pair(15, 36), Pair(15, 93), Pair(19, 32), Pair(22, 37), Pair(31, 14), Pair(30, 10),
        Pair(-23, 99), Pair(-5, 47), Pair(0, 0), Pair(14, 54), Pair(-12, 107), Pair(10, 19), Pair(21, 29), Pair(31, 24),
        Pair(44, 41), Pair(53, -223), Pair(22, 156), Pair(-2, -59), Pair(21, 44), Pair(25, 5), Pair(-2, 7), Pair(6, -1),
        Pair(-6, 56), Pair(-17, -93), Pair(-21, 90), Pair(-2, 14), Pair(-17, 88), Pair(-8, 11), Pair(-14, 38), Pair(136, -84)
      },
      { // Piece 2
        Pair(-1, 49), Pair(-11, 32), Pair(46, 29), Pair(-49, 39), Pair(-50, 65), Pair(1, 34), Pair(39, 59), Pair(11, -35),
        Pair(-24, 45), Pair(20, 46), Pair(-20, 45), Pair(12, 61), Pair(-18, 64), Pair(-55, 102), Pair(-81, 103), Pair(51, 106),
        Pair(22, 18), Pair(0, 54), Pair(13, 13), Pair(-35, 55), Pair(-1, 57), Pair(41, 54), Pair(-22, 130), Pair(27, 52),
        Pair(-32, 51), Pair(7, 34), Pair(9, 57), Pair(30, 39), Pair(20, 65), Pair(5, 114), Pair(-8, 51), Pair(42, 19),
        Pair(-31, 134), Pair(24, 9), Pair(26, 54), Pair(-2, 51), Pair(-4, 113), Pair(9, 64), Pair(0, 56), Pair(33, 13),
        Pair(-13, 41), Pair(2, 119), Pair(0, 0), Pair(3, 105), Pair(12, 57), Pair(1, 49), Pair(0, 40), Pair(13, 15),
        Pair(-38, 48), Pair(-7, -58), Pair(42, 170), Pair(18, -44), Pair(1, 40), Pair(-12, 48), Pair(6, 13), Pair(32, -21),
        Pair(-82, -39), Pair(-11, 113), Pair(-4, 31), Pair(-15, 118), Pair(-40, 44), Pair(10, 19), Pair(0, 47), Pair(36, 30)
      },
      { // Piece 3
        Pair(24, 54), Pair(53, 45), Pair(66, 60), Pair(88, 15), Pair(9, 49), Pair(0, 59), Pair(21, 47), Pair(-52, 76),
        Pair(21, 51), Pair(13, 47), Pair(73, 60), Pair(15, 57), Pair(-4, 45), Pair(52, 16), Pair(177, -26), Pair(79, 9),
        Pair(41, 27), Pair(0, 49), Pair(23, 73), Pair(13, 55), Pair(28, 50), Pair(-18, 56), Pair(-22, 46), Pair(74, 3),
        Pair(12, 26), Pair(9, 28), Pair(-22, 84), Pair(38, 18), Pair(-18, 42), Pair(29, 24), Pair(72, 12), Pair(70, -1),
        Pair(1, 39), Pair(8, 43), Pair(47, 74), Pair(5, 35), Pair(-2, 37), Pair(30, 28), Pair(3, 35), Pair(29, 35),
        Pair(-25, 67), Pair(-12, 52), Pair(0, 0), Pair(18, 44), Pair(27, 14), Pair(-9, 33), Pair(-1, 58), Pair(25, 12),
        Pair(-46, 93), Pair(-49, 19), Pair(-22, 130), Pair(-32, 64), Pair(-26, 80), Pair(-8, 82), Pair(33, 54), Pair(-23, 80),
        Pair(-17, 50), Pair(-9, 41), Pair(-42, 100), Pair(3, 44), Pair(8, 40), Pair(5, 46), Pair(21, 33), Pair(37, 15)
      },
      { // Piece 4
        Pair(46, -14), Pair(94, -21), Pair(-9, 123), Pair(38, 75), Pair(82, 41), Pair(43, -6), Pair(61, -44), Pair(11, 69),
        Pair(7, 11), Pair(21, 79), Pair(34, 74), Pair(37, 23), Pair(-57, 205), Pair(60, 37), Pair(86, -49), Pair(43, 30),
        Pair(5, 30), Pair(47, -2), Pair(-8, 98), Pair(-10, 109), Pair(30, 60), Pair(37, 87), Pair(39, 81), Pair(91, -42),
        Pair(75, -53), Pair(17, 47), Pair(5, 47), Pair(-12, 109), Pair(9, 63), Pair(23, 90), Pair(49, 7), Pair(54, 5),
        Pair(-11, 80), Pair(7, 55), Pair(47, -13), Pair(-24, 68), Pair(-8, 114), Pair(24, 45), Pair(20, 32), Pair(11, 62),
        Pair(-52, 41), Pair(-3, 30), Pair(0, 0), Pair(7, 75), Pair(7, 47), Pair(-3, 67), Pair(32, -7), Pair(3, 41),
        Pair(19, 21), Pair(-11, -32), Pair(8, 47), Pair(-1, 29), Pair(18, 29), Pair(2, 18), Pair(16, 55), Pair(54, 26),
        Pair(-46, 40), Pair(-22, 72), Pair(-10, 34), Pair(0, 32), Pair(25, -9), Pair(0, 29), Pair(21, -40), Pair(1, 70)
      },
      { // Piece 5
        Pair(-17, -12), Pair(-98, -195), Pair(-37, -141), Pair(32, 65), Pair(-5, -65), Pair(-25, -117), Pair(22, -122), Pair(-27, -164),
        Pair(-18, -144), Pair(1, -41), Pair(-66, -20), Pair(5, -54), Pair(10, -67), Pair(-77, -67), Pair(89, -96), Pair(-46, -74),
        Pair(20, -19), Pair(4, -25), Pair(95, -48), Pair(81, -28), Pair(103, -66), Pair(78, -19), Pair(123, -52), Pair(-19, -66),
        Pair(67, -23), Pair(82, -29), Pair(81, -13), Pair(166, -11), Pair(135, -31), Pair(81, -10), Pair(63, -40), Pair(-57, -31),
        Pair(164, -9), Pair(59, 18), Pair(32, 21), Pair(46, 42), Pair(30, -3), Pair(33, -1), Pair(-15, -15), Pair(2, -54),
        Pair(-88, 47), Pair(-125, 91), Pair(0, 0), Pair(-69, 70), Pair(-10, 15), Pair(5, 5), Pair(13, -27), Pair(12, -46),
        Pair(-159, 80), Pair(35, 94), Pair(-201, 122), Pair(-30, 99), Pair(-81, 33), Pair(-16, 6), Pair(-2, -21), Pair(19, -45),
        Pair(-124, 4), Pair(-95, 38), Pair(-157, 96), Pair(-87, 85), Pair(-63, 9), Pair(-23, 1), Pair(1, -38), Pair(20, -70)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(2, 20), Pair(-20, 20), Pair(20, 4), Pair(19, 5), Pair(-37, 29), Pair(2, 22), Pair(-3, 15), Pair(3, 10),
        Pair(0, 7), Pair(-6, 1), Pair(4, 0), Pair(0, 0), Pair(11, 1), Pair(-6, 8), Pair(17, 4), Pair(-7, 11),
        Pair(-3, -2), Pair(-4, -6), Pair(3, -3), Pair(0, -7), Pair(-3, 2), Pair(-1, 0), Pair(-11, 0), Pair(-5, 2),
        Pair(0, -9), Pair(-4, -12), Pair(1, -9), Pair(3, -4), Pair(-1, -4), Pair(-1, -2), Pair(-6, -5), Pair(-10, 1),
        Pair(1, -6), Pair(-3, -6), Pair(0, -7), Pair(0, 0), Pair(2, -1), Pair(-6, -1), Pair(-10, -6), Pair(-6, -4),
        Pair(-6, -7), Pair(0, -4), Pair(0, -28), Pair(13, 31), Pair(10, -42), Pair(-8, -1), Pair(0, -7), Pair(1, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-44, 29), Pair(-202, 116), Pair(114, -52), Pair(138, -15), Pair(-77, 31), Pair(112, -18), Pair(13, -89), Pair(44, -148),
        Pair(-14, 24), Pair(10, 22), Pair(26, 14), Pair(113, 5), Pair(22, 32), Pair(15, 31), Pair(117, -52), Pair(-13, 44),
        Pair(45, 7), Pair(-5, 29), Pair(1, 41), Pair(46, 13), Pair(25, 29), Pair(72, 24), Pair(39, 7), Pair(11, 17),
        Pair(0, 22), Pair(10, 40), Pair(14, 31), Pair(37, 25), Pair(28, 28), Pair(19, 32), Pair(31, 29), Pair(48, -6),
        Pair(16, 39), Pair(-47, 60), Pair(9, 100), Pair(22, 36), Pair(20, 104), Pair(14, 18), Pair(21, 57), Pair(12, 18),
        Pair(-36, 16), Pair(-6, 93), Pair(0, 63), Pair(0, 0), Pair(-17, 67), Pair(3, 100), Pair(14, 14), Pair(21, 12),
        Pair(20, 28), Pair(29, 28), Pair(-8, -18), Pair(20, 155), Pair(-30, -16), Pair(13, 47), Pair(16, 29), Pair(22, -22),
        Pair(-74, -98), Pair(-14, 62), Pair(-11, -47), Pair(5, 60), Pair(-2, 9), Pair(-21, 120), Pair(13, -54), Pair(-38, -69)
      },
      { // Piece 2
        Pair(-62, 66), Pair(-197, 97), Pair(67, 13), Pair(-27, 54), Pair(22, 61), Pair(-12, 71), Pair(-26, 31), Pair(92, 72),
        Pair(46, 36), Pair(4, 51), Pair(-24, 51), Pair(60, 48), Pair(-33, 81), Pair(-13, 63), Pair(-57, 79), Pair(-69, 58),
        Pair(8, 42), Pair(0, 54), Pair(-20, 42), Pair(1, 17), Pair(4, 53), Pair(5, 74), Pair(3, 68), Pair(18, 105),
        Pair(-10, 123), Pair(-67, 65), Pair(8, 47), Pair(11, 35), Pair(21, 49), Pair(-37, 91), Pair(-12, 121), Pair(-2, 76),
        Pair(-40, 64), Pair(-4, 115), Pair(-25, 68), Pair(17, 44), Pair(-4, 55), Pair(-7, 109), Pair(-23, 74), Pair(-21, 39),
        Pair(-3, 19), Pair(-2, 66), Pair(-10, 110), Pair(0, 0), Pair(-3, 108), Pair(-5, 58), Pair(11, 29), Pair(6, 29),
        Pair(-25, 45), Pair(9, 6), Pair(-38, -25), Pair(11, 168), Pair(5, -46), Pair(-11, 52), Pair(18, 22), Pair(12, -1),
        Pair(31, -15), Pair(-30, -14), Pair(-23, 89), Pair(-5, 52), Pair(-22, 113), Pair(4, -18), Pair(-13, -29), Pair(30, 18)
      },
      { // Piece 3
        Pair(55, 23), Pair(12, 52), Pair(13, 47), Pair(52, 49), Pair(-12, 61), Pair(97, 18), Pair(103, 5), Pair(10, 58),
        Pair(35, 30), Pair(8, 50), Pair(5, 56), Pair(-5, 83), Pair(35, 29), Pair(55, 33), Pair(-17, 61), Pair(23, 34),
        Pair(20, 44), Pair(3, 46), Pair(-3, 39), Pair(32, 51), Pair(21, 31), Pair(87, -2), Pair(55, 31), Pair(1, 61),
        Pair(-1, 28), Pair(-3, 33), Pair(13, 32), Pair(17, 65), Pair(31, 22), Pair(18, 37), Pair(34, 23), Pair(43, 30),
        Pair(-8, 34), Pair(14, 38), Pair(-7, 30), Pair(-27, 92), Pair(2, 41), Pair(13, 43), Pair(-14, 40), Pair(44, 14),
        Pair(-1, 26), Pair(-4, 39), Pair(-1, 40), Pair(0, 0), Pair(24, 16), Pair(22, 36), Pair(60, 18), Pair(34, 4),
        Pair(-31, 95), Pair(-18, 78), Pair(63, -39), Pair(3, 115), Pair(-15, 65), Pair(2, 93), Pair(-3, 92), Pair(14, 67),
        Pair(-10, 43), Pair(-8, 45), Pair(-10, 41), Pair(-27, 101), Pair(-1, 40), Pair(12, 43), Pair(16, 44), Pair(18, 27)
      },
      { // Piece 4
        Pair(30, 11), Pair(14, 75), Pair(44, 22), Pair(4, 104), Pair(3, 109), Pair(39, 59), Pair(28, 46), Pair(52, 8),
        Pair(37, 23), Pair(2, 69), Pair(38, 28), Pair(31, 49), Pair(17, 75), Pair(24, 99), Pair(65, -61), Pair(70, -19),
        Pair(61, -53), Pair(-3, 66), Pair(38, -6), Pair(0, 95), Pair(0, 133), Pair(-25, 110), Pair(-18, 83), Pair(24, 103),
        Pair(-1, 84), Pair(12, 38), Pair(20, 3), Pair(44, 48), Pair(0, 76), Pair(8, 102), Pair(9, 102), Pair(16, 54),
        Pair(-3, 22), Pair(-9, 89), Pair(49, -60), Pair(-1, 76), Pair(27, 55), Pair(19, 90), Pair(-2, 96), Pair(2, 100),
        Pair(30, -55), Pair(10, -22), Pair(1, 50), Pair(0, 0), Pair(6, 76), Pair(23, 19), Pair(40, -10), Pair(39, 5),
        Pair(-8, 12), Pair(-10, 23), Pair(9, -41), Pair(15, 34), Pair(-10, 30), Pair(16, 13), Pair(-36, 104), Pair(82, -41),
        Pair(-36, 65), Pair(3, -29), Pair(-23, 48), Pair(-7, 22), Pair(-1, 47), Pair(-14, -27), Pair(52, -89), Pair(45, -34)
      },
      { // Piece 5
        Pair(-18, -105), Pair(-12, -62), Pair(2, -58), Pair(-1, -72), Pair(-16, -74), Pair(-8, -60), Pair(-62, -117), Pair(-115, -79),
        Pair(9, 5), Pair(-13, -42), Pair(17, -6), Pair(13, -65), Pair(-89, 8), Pair(-66, -69), Pair(-64, -37), Pair(9, -32),
        Pair(42, -83), Pair(-48, -41), Pair(-16, -19), Pair(-6, -55), Pair(93, -66), Pair(25, -19), Pair(-73, -25), Pair(-36, -31),
        Pair(42, -46), Pair(80, -44), Pair(222, -51), Pair(47, -23), Pair(3, -6), Pair(73, -10), Pair(-1, -16), Pair(-116, -21),
        Pair(-20, -47), Pair(8, -29), Pair(-4, 26), Pair(-65, 43), Pair(26, 31), Pair(86, -9), Pair(36, -9), Pair(-22, -28),
        Pair(-2, -42), Pair(-88, 35), Pair(-68, 69), Pair(0, 0), Pair(-43, 57), Pair(-53, 21), Pair(31, -11), Pair(15, -37),
        Pair(23, -31), Pair(-76, 65), Pair(-49, -67), Pair(-90, 87), Pair(103, -41), Pair(-39, 20), Pair(-3, -3), Pair(29, -45),
        Pair(23, -26), Pair(-62, 23), Pair(-47, 82), Pair(-85, 77), Pair(-34, 65), Pair(-53, 9), Pair(7, -20), Pair(24, -47)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(20, 9), Pair(18, -2), Pair(-18, 13), Pair(10, -1), Pair(-74, 50), Pair(20, -4), Pair(5, 2), Pair(-11, 11),
        Pair(-1, -1), Pair(6, -7), Pair(-4, -2), Pair(-11, -1), Pair(0, 0), Pair(-4, -1), Pair(2, 0), Pair(12, -2),
        Pair(0, -11), Pair(-2, -9), Pair(-3, -12), Pair(0, -10), Pair(3, -4), Pair(1, -3), Pair(0, -7), Pair(5, -3),
        Pair(2, -10), Pair(5, -14), Pair(-3, -8), Pair(-7, -4), Pair(10, -12), Pair(3, -2), Pair(-1, -2), Pair(10, -5),
        Pair(0, -13), Pair(0, -13), Pair(-4, -12), Pair(7, -4), Pair(0, 0), Pair(-4, 4), Pair(-8, -2), Pair(2, -7),
        Pair(-3, -8), Pair(1, -10), Pair(4, -6), Pair(8, -44), Pair(29, 16), Pair(2, -25), Pair(10, -5), Pair(14, -12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-67, -38), Pair(-2, 57), Pair(74, -57), Pair(-83, 38), Pair(-138, 32), Pair(86, -7), Pair(59, 4), Pair(63, -152),
        Pair(59, -50), Pair(7, -5), Pair(15, 8), Pair(76, -15), Pair(-70, 35), Pair(5, 25), Pair(-51, -2), Pair(186, -68),
        Pair(-131, 60), Pair(-43, 13), Pair(20, 9), Pair(-10, 24), Pair(-2, 13), Pair(73, 4), Pair(66, -10), Pair(120, 18),
        Pair(-40, -11), Pair(7, 19), Pair(4, 21), Pair(18, 11), Pair(20, 19), Pair(51, 3), Pair(14, 17), Pair(22, 9),
        Pair(-25, 5), Pair(-46, 49), Pair(-7, 9), Pair(-11, 83), Pair(-22, 24), Pair(-3, 81), Pair(-3, 11), Pair(17, 21),
        Pair(-9, -6), Pair(-28, 15), Pair(-10, 77), Pair(-31, 52), Pair(0, 0), Pair(1, 33), Pair(-2, 88), Pair(-21, 24),
        Pair(-9, -27), Pair(-44, 12), Pair(22, 24), Pair(-17, -85), Pair(16, 130), Pair(-55, -4), Pair(-26, 39), Pair(11, 21),
        Pair(-128, 98), Pair(-40, -25), Pair(-36, 73), Pair(-30, -36), Pair(3, 45), Pair(-7, -19), Pair(-13, 56), Pair(-199, -19)
      },
      { // Piece 2
        Pair(-26, 37), Pair(-91, 41), Pair(13, 28), Pair(-43, 13), Pair(-176, 111), Pair(-126, 74), Pair(7, 16), Pair(166, 77),
        Pair(14, 29), Pair(-43, 55), Pair(38, 21), Pair(-31, 80), Pair(-26, 45), Pair(69, 54), Pair(-39, 54), Pair(-2, 51),
        Pair(-23, 97), Pair(-48, 90), Pair(-29, 47), Pair(22, 9), Pair(-27, 51), Pair(-5, 30), Pair(-30, 65), Pair(72, -6),
        Pair(-11, 43), Pair(-25, 105), Pair(-3, 39), Pair(13, 23), Pair(-15, 27), Pair(-1, 48), Pair(1, 51), Pair(-10, 76),
        Pair(0, 10), Pair(4, 40), Pair(-22, 97), Pair(-10, 37), Pair(-16, 51), Pair(-32, 32), Pair(-1, 92), Pair(-12, 39),
        Pair(14, -11), Pair(3, 20), Pair(-20, 49), Pair(3, 101), Pair(0, 0), Pair(4, 77), Pair(8, 25), Pair(0, 13),
        Pair(3, -21), Pair(16, 0), Pair(-22, 36), Pair(8, -22), Pair(-7, 138), Pair(-37, 9), Pair(-4, 13), Pair(25, -12),
        Pair(19, -6), Pair(16, 17), Pair(-18, -26), Pair(-7, 95), Pair(-28, 45), Pair(-46, 88), Pair(-53, -35), Pair(24, 28)
      },
      { // Piece 3
        Pair(23, 17), Pair(-9, 14), Pair(-35, 26), Pair(30, -3), Pair(0, 37), Pair(106, -2), Pair(-93, 67), Pair(5, 19),
        Pair(-24, 17), Pair(-3, -2), Pair(58, -16), Pair(40, -13), Pair(2, 21), Pair(41, -2), Pair(119, -41), Pair(50, -6),
        Pair(-27, 18), Pair(7, -3), Pair(-18, 22), Pair(22, -2), Pair(10, 17), Pair(-7, 8), Pair(92, -30), Pair(28, -11),
        Pair(-38, 14), Pair(9, 5), Pair(12, 7), Pair(5, 10), Pair(16, 30), Pair(49, -37), Pair(-8, 5), Pair(40, -15),
        Pair(-29, 9), Pair(9, -8), Pair(-21, 13), Pair(-8, 23), Pair(-36, 52), Pair(32, -5), Pair(57, -10), Pair(32, -39),
        Pair(-36, 22), Pair(2, 7), Pair(0, 5), Pair(-48, 11), Pair(0, 0), Pair(29, 5), Pair(51, -21), Pair(14, 0),
        Pair(-47, 49), Pair(-5, 29), Pair(-23, 49), Pair(-79, 39), Pair(-22, 84), Pair(-21, 6), Pair(13, 56), Pair(11, 6),
        Pair(-9, 6), Pair(-18, 7), Pair(-23, 34), Pair(-28, 17), Pair(-16, 56), Pair(-9, 13), Pair(20, -2), Pair(18, -4)
      },
      { // Piece 4
        Pair(-31, 45), Pair(-54, 14), Pair(-123, 133), Pair(66, -31), Pair(-67, 105), Pair(-81, 129), Pair(-48, 102), Pair(90, -42),
        Pair(-33, -16), Pair(-15, 46), Pair(-21, 26), Pair(-64, 85), Pair(-3, 6), Pair(69, -52), Pair(40, 16), Pair(48, -53),
        Pair(-24, 37), Pair(26, -17), Pair(63, -91), Pair(-21, 49), Pair(-30, 72), Pair(-19, 93), Pair(63, -42), Pair(39, 36),
        Pair(-12, 20), Pair(-33, 36), Pair(-13, 50), Pair(-10, 38), Pair(-2, 54), Pair(2, 53), Pair(66, -56), Pair(-24, 88),
        Pair(-18, -7), Pair(-35, 16), Pair(-31, 60), Pair(22, -39), Pair(-4, 0), Pair(27, -96), Pair(-15, 29), Pair(-5, 20),
        Pair(0, -19), Pair(14, -36), Pair(2, -20), Pair(19, -12), Pair(0, 0), Pair(-16, 50), Pair(-9, 37), Pair(-1, -7),
        Pair(18, -31), Pair(-10, 1), Pair(-15, 13), Pair(-10, -59), Pair(-12, 30), Pair(-1, -68), Pair(-57, 129), Pair(-49, 121),
        Pair(13, -33), Pair(-25, 37), Pair(-25, -30), Pair(-23, -10), Pair(-26, -34), Pair(-7, 16), Pair(-19, -10), Pair(-3, -61)
      },
      { // Piece 5
        Pair(-11, -136), Pair(15, -129), Pair(-32, -128), Pair(-79, -101), Pair(-61, -122), Pair(-13, 35), Pair(18, -81), Pair(7, -117),
        Pair(14, -151), Pair(28, -72), Pair(15, -67), Pair(3, -27), Pair(-17, -93), Pair(19, -63), Pair(-1, -62), Pair(-32, -107),
        Pair(-16, -57), Pair(-6, -31), Pair(85, -46), Pair(169, -69), Pair(75, -69), Pair(198, -50), Pair(-6, -42), Pair(36, -37),
        Pair(-68, -87), Pair(-31, -32), Pair(-3, -19), Pair(6, -39), Pair(-23, -22), Pair(181, -41), Pair(59, -16), Pair(5, -7),
        Pair(87, -68), Pair(-16, -14), Pair(-61, 0), Pair(-13, 22), Pair(-109, 65), Pair(41, 10), Pair(24, 0), Pair(57, -33),
        Pair(88, -70), Pair(3, -19), Pair(45, -15), Pair(-88, 59), Pair(0, 0), Pair(13, 36), Pair(3, 8), Pair(24, -14),
        Pair(54, -23), Pair(-15, 3), Pair(-33, 4), Pair(-51, 53), Pair(-122, 81), Pair(15, 55), Pair(-45, 28), Pair(-13, 10),
        Pair(8, -32), Pair(-13, -43), Pair(-38, -1), Pair(-55, 53), Pair(-50, 65), Pair(-46, 60), Pair(-40, 13), Pair(-21, 6)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(25, -4), Pair(-13, 6), Pair(4, 0), Pair(-8, 18), Pair(-5, 6), Pair(-2, -24), Pair(6, -16), Pair(17, 13),
        Pair(3, -4), Pair(12, -10), Pair(-2, -3), Pair(6, -8), Pair(4, 1), Pair(0, 0), Pair(7, -13), Pair(15, -6),
        Pair(3, -14), Pair(-1, -18), Pair(-6, -7), Pair(1, -5), Pair(3, -7), Pair(-24, 8), Pair(-1, -6), Pair(15, -8),
        Pair(8, -14), Pair(-3, -15), Pair(-2, -13), Pair(-5, -5), Pair(2, -4), Pair(8, -4), Pair(13, -5), Pair(11, -3),
        Pair(3, -14), Pair(-1, -14), Pair(-7, -15), Pair(-10, -1), Pair(4, -7), Pair(0, 0), Pair(13, -8), Pair(23, -7),
        Pair(5, -16), Pair(-3, -9), Pair(-2, -15), Pair(1, 3), Pair(13, -25), Pair(19, 1), Pair(21, -27), Pair(18, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(29, -107), Pair(13, -23), Pair(58, -14), Pair(110, -38), Pair(-122, -1), Pair(-20, -28), Pair(-55, 10), Pair(55, 0),
        Pair(-62, 16), Pair(-6, -26), Pair(-29, 2), Pair(-63, 32), Pair(58, -22), Pair(116, -46), Pair(-34, -20), Pair(-125, 48),
        Pair(21, -28), Pair(-21, -7), Pair(-44, 15), Pair(30, -14), Pair(14, 3), Pair(113, -38), Pair(34, 3), Pair(-59, 18),
        Pair(-36, -10), Pair(-17, -3), Pair(14, -9), Pair(8, -7), Pair(30, -6), Pair(49, 22), Pair(81, -3), Pair(75, -35),
        Pair(-36, 34), Pair(-13, -10), Pair(11, 6), Pair(24, -3), Pair(-1, 51), Pair(28, -3), Pair(26, 45), Pair(19, -17),
        Pair(-8, -24), Pair(-17, 3), Pair(-11, -6), Pair(-7, 50), Pair(-1, 46), Pair(0, 0), Pair(-8, 20), Pair(-16, -1),
        Pair(-7, -54), Pair(-39, 33), Pair(-22, 13), Pair(1, 18), Pair(-50, -29), Pair(7, 122), Pair(-7, -14), Pair(-1, 16),
        Pair(-33, -88), Pair(-26, 47), Pair(-50, -16), Pair(-71, 40), Pair(-13, -26), Pair(15, 9), Pair(-63, -96), Pair(-198, 123)
      },
      { // Piece 2
        Pair(-33, 74), Pair(-29, 27), Pair(27, 28), Pair(-66, 47), Pair(-78, 64), Pair(-66, 25), Pair(-23, 31), Pair(-130, 33),
        Pair(-63, 81), Pair(-38, 45), Pair(-48, 58), Pair(-60, 57), Pair(-103, 54), Pair(-54, 30), Pair(-65, 31), Pair(-40, 17),
        Pair(-4, 14), Pair(-73, 66), Pair(-19, 58), Pair(-9, 12), Pair(-41, 46), Pair(33, 18), Pair(-59, 55), Pair(-4, 2),
        Pair(-62, 10), Pair(-3, 19), Pair(-61, 56), Pair(-21, 58), Pair(28, 11), Pair(4, 62), Pair(-8, 17), Pair(-4, 16),
        Pair(-38, -4), Pair(-37, 9), Pair(-8, 25), Pair(-19, 44), Pair(31, 9), Pair(17, 17), Pair(-20, 35), Pair(-68, 69),
        Pair(-12, -6), Pair(-2, 17), Pair(-15, -3), Pair(-10, 32), Pair(-20, 33), Pair(0, 0), Pair(-9, 67), Pair(-1, 15),
        Pair(-26, -2), Pair(-17, -14), Pair(-8, 7), Pair(-22, 11), Pair(16, -54), Pair(1, 112), Pair(-23, -85), Pair(-51, 16),
        Pair(20, -12), Pair(-3, 47), Pair(-27, 2), Pair(-32, 3), Pair(-78, 43), Pair(-10, -13), Pair(-162, 95), Pair(-83, -112)
      },
      { // Piece 3
        Pair(-58, 29), Pair(-12, 11), Pair(34, 11), Pair(-43, 28), Pair(17, 17), Pair(71, 1), Pair(11, 39), Pair(37, 15),
        Pair(-18, 6), Pair(2, -2), Pair(45, -20), Pair(11, -4), Pair(-48, 21), Pair(19, 14), Pair(19, -5), Pair(60, -8),
        Pair(2, 0), Pair(-15, -3), Pair(32, -27), Pair(21, -2), Pair(23, 0), Pair(43, 14), Pair(15, -2), Pair(89, -35),
        Pair(-11, -7), Pair(12, -3), Pair(8, -8), Pair(-1, 3), Pair(2, -6), Pair(92, -8), Pair(64, -23), Pair(84, -24),
        Pair(-38, -6), Pair(-28, 6), Pair(-28, 9), Pair(16, -8), Pair(9, -3), Pair(45, 18), Pair(63, -25), Pair(28, 10),
        Pair(-2, 1), Pair(-11, -26), Pair(-17, -10), Pair(-37, 23), Pair(6, -8), Pair(0, 0), Pair(48, -14), Pair(27, -38),
        Pair(-17, 14), Pair(-44, 21), Pair(-48, 14), Pair(-15, 21), Pair(-9, -67), Pair(-9, 62), Pair(63, -20), Pair(-22, 10),
        Pair(-16, -5), Pair(-9, -15), Pair(-24, 3), Pair(-15, 6), Pair(-14, 6), Pair(-39, 16), Pair(-6, 16), Pair(-11, 3)
      },
      { // Piece 4
        Pair(-30, -50), Pair(-32, -13), Pair(-32, -9), Pair(22, -53), Pair(-46, 83), Pair(5, 2), Pair(17, 14), Pair(16, 43),
        Pair(-55, 21), Pair(-49, -12), Pair(-29, 54), Pair(-1, -34), Pair(-97, 88), Pair(49, 16), Pair(-26, 33), Pair(23, -131),
        Pair(-12, -79), Pair(-55, 22), Pair(-45, 35), Pair(-28, 15), Pair(-2, -35), Pair(106, -72), Pair(77, -63), Pair(37, -48),
        Pair(-17, -23), Pair(-22, -42), Pair(-32, 37), Pair(-53, 74), Pair(-11, -13), Pair(25, -1), Pair(26, -57), Pair(16, -19),
        Pair(-11, -59), Pair(-34, 6), Pair(-22, -23), Pair(-28, 44), Pair(-72, 66), Pair(4, -7), Pair(-44, 33), Pair(-12, -14),
        Pair(-26, -14), Pair(-51, -2), Pair(-15, 6), Pair(-37, 9), Pair(-6, -15), Pair(0, 0), Pair(-4, -38), Pair(10, -23),
        Pair(-34, -69), Pair(-72, 53), Pair(-51, -16), Pair(-45, 22), Pair(-59, 31), Pair(-78, 70), Pair(-101, 46), Pair(-46, 51),
        Pair(-60, 15), Pair(-16, -86), Pair(-40, -5), Pair(-15, -80), Pair(-46, 6), Pair(-10, -58), Pair(-65, 94), Pair(-71, 48)
      },
      { // Piece 5
        Pair(40, -67), Pair(-22, -118), Pair(-28, -108), Pair(-112, -117), Pair(-71, -95), Pair(-2, -99), Pair(-7, -160), Pair(-3, -39),
        Pair(-43, -147), Pair(21, -95), Pair(122, -81), Pair(91, -80), Pair(-10, -13), Pair(-19, -50), Pair(14, -60), Pair(52, -5),
        Pair(53, -101), Pair(-24, -59), Pair(39, -40), Pair(27, -27), Pair(-18, -43), Pair(68, -44), Pair(36, -32), Pair(16, -59),
        Pair(-87, -63), Pair(112, -73), Pair(54, -44), Pair(85, -43), Pair(224, -51), Pair(100, -18), Pair(38, -21), Pair(165, -39),
        Pair(1, -55), Pair(101, -64), Pair(76, -29), Pair(111, -32), Pair(67, 17), Pair(-17, 44), Pair(76, 24), Pair(-6, 3),
        Pair(-26, -43), Pair(143, -77), Pair(37, -21), Pair(-64, 15), Pair(-56, 55), Pair(0, 0), Pair(-27, 45), Pair(-55, 46),
        Pair(43, -46), Pair(78, -42), Pair(67, -28), Pair(-12, 9), Pair(45, 59), Pair(-127, 83), Pair(-73, 54), Pair(-92, 58),
        Pair(42, -65), Pair(35, -45), Pair(3, -10), Pair(-26, -5), Pair(-25, 32), Pair(-124, 73), Pair(-50, 38), Pair(-57, 27)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-29, 6), Pair(14, -1), Pair(25, -3), Pair(-24, 6), Pair(-27, 7), Pair(9, -17), Pair(-6, 21), Pair(20, -15),
        Pair(14, -8), Pair(14, -9), Pair(3, -13), Pair(-18, -4), Pair(-2, 2), Pair(-7, 13), Pair(0, 0), Pair(3, -1),
        Pair(7, -12), Pair(6, -9), Pair(-4, -12), Pair(-16, -6), Pair(-9, -1), Pair(2, -7), Pair(5, -3), Pair(10, -4),
        Pair(7, -19), Pair(7, -19), Pair(0, -11), Pair(-1, -14), Pair(4, -14), Pair(1, -7), Pair(-15, 3), Pair(6, -4),
        Pair(6, -23), Pair(0, -15), Pair(-4, -19), Pair(0, -10), Pair(2, -2), Pair(-15, 1), Pair(0, 0), Pair(18, -3),
        Pair(-1, -15), Pair(-1, -17), Pair(-7, -10), Pair(-5, -9), Pair(-3, 1), Pair(4, -25), Pair(15, 8), Pair(5, -9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(56, -102), Pair(107, -161), Pair(-31, -61), Pair(-108, -22), Pair(-18, 5), Pair(3, -12), Pair(10, -108), Pair(41, -22),
        Pair(-25, -54), Pair(42, -33), Pair(63, -15), Pair(13, -8), Pair(16, 2), Pair(-3, -27), Pair(21, -50), Pair(53, -71),
        Pair(-24, -36), Pair(-5, -11), Pair(28, -21), Pair(-3, -30), Pair(30, -4), Pair(26, -13), Pair(28, -18), Pair(66, -25),
        Pair(-3, -37), Pair(-32, -1), Pair(0, -16), Pair(5, 5), Pair(51, -15), Pair(4, -27), Pair(4, 16), Pair(37, -28),
        Pair(17, -50), Pair(-44, -19), Pair(-10, -14), Pair(24, -7), Pair(12, -9), Pair(18, 22), Pair(33, -6), Pair(-11, 13),
        Pair(-52, 18), Pair(-16, -47), Pair(-16, 5), Pair(-13, 1), Pair(-23, 42), Pair(-6, 7), Pair(0, 0), Pair(4, -24),
        Pair(20, -26), Pair(-49, -4), Pair(-29, -1), Pair(-17, 22), Pair(-11, -8), Pair(19, -86), Pair(-10, 92), Pair(-15, -89),
        Pair(-18, -47), Pair(-15, -84), Pair(4, -51), Pair(2, -76), Pair(-26, 14), Pair(-12, 19), Pair(-32, 3), Pair(-129, -114)
      },
      { // Piece 2
        Pair(-89, 126), Pair(17, 57), Pair(-177, 60), Pair(-120, 35), Pair(-79, 32), Pair(49, -6), Pair(-117, 37), Pair(44, -62),
        Pair(-119, 45), Pair(-23, 95), Pair(36, 1), Pair(-93, 56), Pair(-64, 56), Pair(-167, 62), Pair(-151, 51), Pair(25, -9),
        Pair(-36, -9), Pair(-86, 56), Pair(-59, 93), Pair(20, 27), Pair(16, 21), Pair(-37, 31), Pair(20, 10), Pair(-3, 11),
        Pair(-55, 12), Pair(-26, 30), Pair(3, 26), Pair(-17, 72), Pair(9, 29), Pair(19, 26), Pair(5, 15), Pair(7, -16),
        Pair(1, 7), Pair(-29, 47), Pair(-9, 2), Pair(2, 31), Pair(15, 52), Pair(-9, 25), Pair(41, 1), Pair(14, -22),
        Pair(-30, 10), Pair(-28, 17), Pair(-7, 20), Pair(1, -11), Pair(-16, 26), Pair(-8, 55), Pair(0, 0), Pair(50, 61),
        Pair(7, -17), Pair(-19, 15), Pair(-32, 15), Pair(-15, 12), Pair(-44, 27), Pair(-77, -17), Pair(20, 133), Pair(0, 12),
        Pair(36, -43), Pair(-12, -5), Pair(-31, 12), Pair(-16, 5), Pair(-30, -6), Pair(-30, 20), Pair(-42, 7), Pair(-14, 122)
      },
      { // Piece 3
        Pair(-3, -10), Pair(85, -21), Pair(100, -17), Pair(36, -25), Pair(-48, 18), Pair(-72, 29), Pair(121, -15), Pair(-102, 39),
        Pair(89, -54), Pair(33, -30), Pair(30, -31), Pair(25, -12), Pair(38, -25), Pair(105, -46), Pair(143, -23), Pair(69, -30),
        Pair(-4, -26), Pair(31, -25), Pair(38, -33), Pair(86, -47), Pair(11, -25), Pair(52, -21), Pair(66, -8), Pair(95, -36),
        Pair(53, -35), Pair(61, -49), Pair(29, -31), Pair(33, -19), Pair(72, -44), Pair(52, -38), Pair(-25, 14), Pair(20, -29),
        Pair(-11, -23), Pair(-14, -16), Pair(58, -59), Pair(-59, 27), Pair(14, -24), Pair(53, -38), Pair(18, 16), Pair(55, -36),
        Pair(7, -18), Pair(25, -21), Pair(11, -26), Pair(24, -38), Pair(13, -4), Pair(70, -40), Pair(0, 0), Pair(-22, 3),
        Pair(-24, 30), Pair(-19, 7), Pair(8, 22), Pair(35, -9), Pair(1, 10), Pair(15, -103), Pair(30, 26), Pair(159, -110),
        Pair(4, -3), Pair(15, -15), Pair(21, -34), Pair(7, -16), Pair(3, -6), Pair(35, -27), Pair(-24, 21), Pair(-5, -11)
      },
      { // Piece 4
        Pair(-56, 39), Pair(-51, -9), Pair(-8, 19), Pair(89, -68), Pair(56, -63), Pair(-97, 38), Pair(26, -45), Pair(65, -81),
        Pair(17, -78), Pair(-44, 3), Pair(-19, 25), Pair(-46, 15), Pair(-86, 70), Pair(10, 33), Pair(71, -89), Pair(96, -165),
        Pair(-20, -37), Pair(15, -75), Pair(-37, 0), Pair(-69, 62), Pair(-31, 22), Pair(38, -87), Pair(-39, -5), Pair(11, -7),
        Pair(-66, 2), Pair(-49, -14), Pair(-62, 29), Pair(3, -51), Pair(-1, -10), Pair(-36, 68), Pair(20, 22), Pair(47, -82),
        Pair(3, -41), Pair(-85, 77), Pair(-12, -30), Pair(-72, 73), Pair(-40, 48), Pair(-80, 72), Pair(-14, 9), Pair(-35, -25),
        Pair(-24, -75), Pair(-59, 7), Pair(-7, -33), Pair(-18, -40), Pair(-16, -29), Pair(-30, 50), Pair(0, 0), Pair(-46, -40),
        Pair(-26, -123), Pair(-23, -49), Pair(-33, -49), Pair(-44, -27), Pair(-51, 2), Pair(-84, 72), Pair(-132, 141), Pair(-68, 13),
        Pair(-72, 12), Pair(12, -103), Pair(-37, -57), Pair(-26, -71), Pair(-32, -81), Pair(-34, -44), Pair(-16, -225), Pair(-122, -84)
      },
      { // Piece 5
        Pair(-12, -138), Pair(85, -113), Pair(12, -135), Pair(-11, -22), Pair(-13, -59), Pair(-15, -75), Pair(-80, -129), Pair(-1, -3),
        Pair(20, -112), Pair(-10, -92), Pair(0, -77), Pair(-76, -30), Pair(4, -43), Pair(54, -23), Pair(90, -50), Pair(18, 27),
        Pair(118, -110), Pair(75, -67), Pair(138, -65), Pair(99, -59), Pair(14, -34), Pair(123, -16), Pair(77, -44), Pair(-41, -22),
        Pair(95, -91), Pair(209, -82), Pair(12, -37), Pair(65, -15), Pair(114, -28), Pair(142, -16), Pair(108, -24), Pair(114, -19),
        Pair(26, -52), Pair(154, -82), Pair(24, -17), Pair(93, -26), Pair(117, -9), Pair(113, 23), Pair(-15, 40), Pair(4, 27),
        Pair(28, -54), Pair(81, -63), Pair(72, -44), Pair(-3, 2), Pair(-14, 25), Pair(-21, 60), Pair(0, 0), Pair(-75, 72),
        Pair(6, -53), Pair(6, -50), Pair(-7, -24), Pair(3, -7), Pair(-87, 45), Pair(-8, 91), Pair(-81, 92), Pair(-56, 130),
        Pair(-68, -58), Pair(-47, -33), Pair(-42, -22), Pair(-46, -17), Pair(-100, 32), Pair(-83, 63), Pair(-86, 76), Pair(-80, 35)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(22, -11), Pair(16, -9), Pair(11, 0), Pair(7, 1), Pair(24, 5), Pair(-43, 7), Pair(30, -15), Pair(-66, 1),
        Pair(8, -13), Pair(16, -16), Pair(15, -6), Pair(8, -10), Pair(-12, 2), Pair(-15, 4), Pair(-3, 1), Pair(0, 0),
        Pair(12, -17), Pair(13, -17), Pair(8, -7), Pair(4, -14), Pair(5, -4), Pair(-1, -4), Pair(10, -3), Pair(-10, 7),
        Pair(8, -19), Pair(13, -20), Pair(7, -17), Pair(5, -10), Pair(4, -13), Pair(3, -3), Pair(1, -9), Pair(-15, 29),
        Pair(8, -21), Pair(5, -19), Pair(9, -15), Pair(6, -8), Pair(2, -8), Pair(1, -6), Pair(-4, -12), Pair(0, 0),
        Pair(11, -17), Pair(8, -16), Pair(4, -12), Pair(1, -10), Pair(-7, -13), Pair(-3, -5), Pair(-6, -24), Pair(-5, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(39, -158), Pair(-37, -28), Pair(135, -108), Pair(-61, -37), Pair(62, -46), Pair(-19, -20), Pair(7, -111), Pair(-67, -97),
        Pair(10, -76), Pair(34, -45), Pair(37, -46), Pair(140, -55), Pair(25, -15), Pair(122, -101), Pair(84, -88), Pair(88, -12),
        Pair(66, -82), Pair(53, -62), Pair(30, -43), Pair(53, -27), Pair(73, -45), Pair(21, -32), Pair(11, -31), Pair(22, 5),
        Pair(30, -61), Pair(35, -56), Pair(28, -24), Pair(60, -41), Pair(52, -26), Pair(50, -28), Pair(54, -22), Pair(26, 24),
        Pair(32, -70), Pair(16, -58), Pair(36, -36), Pair(41, -21), Pair(54, -14), Pair(55, -20), Pair(36, 16), Pair(27, -15),
        Pair(21, -54), Pair(5, -42), Pair(30, -23), Pair(28, -18), Pair(32, -14), Pair(32, 17), Pair(31, -47), Pair(0, 0),
        Pair(-26, -94), Pair(-19, -31), Pair(21, -24), Pair(25, -24), Pair(15, 0), Pair(44, -13), Pair(-88, -64), Pair(26, 83),
        Pair(28, -158), Pair(13, -76), Pair(23, -49), Pair(17, -7), Pair(14, -39), Pair(-19, 17), Pair(-25, 25), Pair(17, 1)
      },
      { // Piece 2
        Pair(10, 59), Pair(-89, 83), Pair(12, 54), Pair(-85, 30), Pair(-188, 61), Pair(-1, 13), Pair(-17, 16), Pair(-108, 37),
        Pair(-13, 2), Pair(17, 32), Pair(-97, 90), Pair(-56, 61), Pair(3, 14), Pair(45, -5), Pair(-3, 9), Pair(5, -9),
        Pair(27, 14), Pair(-13, 2), Pair(13, 51), Pair(-24, 71), Pair(58, 19), Pair(24, 4), Pair(1, 33), Pair(63, -22),
        Pair(2, -23), Pair(38, -5), Pair(-18, 15), Pair(28, 38), Pair(3, 47), Pair(53, 18), Pair(14, -1), Pair(48, 14),
        Pair(62, -28), Pair(-9, -14), Pair(42, 14), Pair(15, -8), Pair(31, 17), Pair(2, 35), Pair(45, 9), Pair(-9, -13),
        Pair(19, -21), Pair(28, -2), Pair(7, -17), Pair(35, 3), Pair(9, -9), Pair(44, 16), Pair(8, 48), Pair(0, 0),
        Pair(39, -41), Pair(4, -14), Pair(34, -2), Pair(-1, -2), Pair(36, 14), Pair(4, -6), Pair(-1, 20), Pair(-10, 120),
        Pair(18, -6), Pair(66, -36), Pair(1, -23), Pair(28, 15), Pair(-19, 0), Pair(17, 0), Pair(-91, 67), Pair(31, 11)
      },
      { // Piece 3
        Pair(16, -6), Pair(-13, 4), Pair(41, -22), Pair(-79, 33), Pair(64, -14), Pair(21, 15), Pair(13, 14), Pair(62, 18),
        Pair(48, -25), Pair(13, -9), Pair(15, -9), Pair(33, -11), Pair(35, -20), Pair(-1, 1), Pair(51, -21), Pair(70, 8),
        Pair(29, -27), Pair(57, -37), Pair(15, -22), Pair(32, -14), Pair(33, -15), Pair(22, -3), Pair(-13, 3), Pair(23, 26),
        Pair(25, -12), Pair(53, -33), Pair(3, -7), Pair(47, -21), Pair(46, -16), Pair(27, -11), Pair(17, -27), Pair(34, 26),
        Pair(36, -33), Pair(6, -18), Pair(54, -32), Pair(10, -7), Pair(29, -15), Pair(29, 14), Pair(29, -8), Pair(-14, 35),
        Pair(40, -22), Pair(12, 1), Pair(8, -21), Pair(6, -2), Pair(1, 3), Pair(18, 5), Pair(60, 13), Pair(0, 0),
        Pair(-32, 24), Pair(16, 31), Pair(-18, 34), Pair(8, 15), Pair(-5, 17), Pair(14, 32), Pair(-51, 40), Pair(-19, 49),
        Pair(15, -4), Pair(27, -18), Pair(24, -11), Pair(17, 3), Pair(12, -7), Pair(33, -9), Pair(22, 7), Pair(-15, 29)
      },
      { // Piece 4
        Pair(-84, 26), Pair(-61, 67), Pair(-29, 34), Pair(-24, 7), Pair(-6, 6), Pair(65, -14), Pair(2, -17), Pair(42, -38),
        Pair(25, -17), Pair(27, -99), Pair(-11, 19), Pair(-59, 63), Pair(-42, 93), Pair(-91, 109), Pair(-14, 37), Pair(-13, 56),
        Pair(51, -83), Pair(-25, -19), Pair(21, -11), Pair(-70, 94), Pair(-73, 160), Pair(-37, 53), Pair(-32, 58), Pair(55, -113),
        Pair(51, -151), Pair(-3, -36), Pair(34, -54), Pair(22, -5), Pair(-24, 50), Pair(-17, 89), Pair(-28, 73), Pair(-26, 78),
        Pair(27, -138), Pair(-39, 5), Pair(5, -54), Pair(-10, 26), Pair(7, -12), Pair(-21, 3), Pair(-40, 123), Pair(35, -48),
        Pair(54, -137), Pair(-22, -12), Pair(5, -74), Pair(-30, 23), Pair(-31, 20), Pair(12, -3), Pair(-4, 25), Pair(0, 0),
        Pair(-19, -41), Pair(-28, -49), Pair(-14, -19), Pair(-16, -6), Pair(-15, -15), Pair(-12, -3), Pair(-119, -3), Pair(-61, 33),
        Pair(-36, -15), Pair(-27, 4), Pair(-33, 9), Pair(-14, -32), Pair(-17, -69), Pair(-11, -10), Pair(-64, 63), Pair(-128, 74)
      },
      { // Piece 5
        Pair(-54, -122), Pair(19, -101), Pair(35, -113), Pair(5, -121), Pair(-20, -74), Pair(70, -121), Pair(-19, -28), Pair(10, 62),
        Pair(-48, -136), Pair(47, -106), Pair(147, -83), Pair(61, -75), Pair(11, -81), Pair(-61, -33), Pair(77, -46), Pair(46, -121),
        Pair(7, -81), Pair(169, -102), Pair(41, -70), Pair(218, -88), Pair(198, -63), Pair(181, -39), Pair(142, -51), Pair(66, -49),
        Pair(1, -104), Pair(77, -82), Pair(122, -73), Pair(44, -40), Pair(113, -25), Pair(103, -8), Pair(180, -8), Pair(117, -30),
        Pair(72, -88), Pair(24, -72), Pair(79, -45), Pair(76, -32), Pair(7, 0), Pair(87, 8), Pair(-4, 54), Pair(6, 4),
        Pair(1, -60), Pair(62, -69), Pair(24, -48), Pair(30, -27), Pair(13, 10), Pair(-32, 39), Pair(-66, 73), Pair(0, 0),
        Pair(-3, -47), Pair(6, -33), Pair(0, -46), Pair(-28, -20), Pair(-68, 29), Pair(-81, 45), Pair(23, 52), Pair(6, 85),
        Pair(-14, -64), Pair(-54, -20), Pair(-49, -35), Pair(-16, -54), Pair(-74, 19), Pair(-83, 28), Pair(-32, 53), Pair(-25, 60)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(42, 0), Pair(-24, 20), Pair(-11, 12), Pair(-3, 11), Pair(-17, 20), Pair(13, 12), Pair(-9, 18), Pair(-15, 29),
        Pair(-30, 9), Pair(-2, -1), Pair(1, 6), Pair(5, 4), Pair(1, 10), Pair(-4, 11), Pair(-8, 11), Pair(-13, 18),
        Pair(0, 0), Pair(-3, -3), Pair(-3, -1), Pair(3, -2), Pair(0, 1), Pair(-3, 6), Pair(-3, 4), Pair(-6, 8),
        Pair(0, 0), Pair(0, -3), Pair(1, -2), Pair(2, -5), Pair(-1, -5), Pair(-5, -1), Pair(-5, -1), Pair(-6, -2),
        Pair(8, 11), Pair(-4, -6), Pair(0, -5), Pair(5, -7), Pair(-3, -3), Pair(-2, -4), Pair(-6, -3), Pair(-4, -3),
        Pair(8, 4), Pair(-9, -9), Pair(0, -2), Pair(3, -5), Pair(-6, -4), Pair(-6, -6), Pair(-8, -6), Pair(-3, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-35, 13), Pair(66, -55), Pair(56, -14), Pair(195, -62), Pair(58, 6), Pair(12, 19), Pair(-20, -8), Pair(62, -5),
        Pair(45, 30), Pair(40, 4), Pair(44, 2), Pair(46, 7), Pair(54, 5), Pair(113, -47), Pair(29, -16), Pair(51, -20),
        Pair(75, -2), Pair(17, 23), Pair(23, 23), Pair(38, 20), Pair(55, 10), Pair(66, -4), Pair(56, -23), Pair(63, -20),
        Pair(-10, 19), Pair(18, 18), Pair(6, 22), Pair(30, 17), Pair(27, 18), Pair(30, 7), Pair(36, 2), Pair(36, -29),
        Pair(0, 0), Pair(7, 22), Pair(5, 25), Pair(13, 22), Pair(25, 18), Pair(18, 11), Pair(40, 1), Pair(26, -6),
        Pair(13, 69), Pair(-18, -42), Pair(9, 26), Pair(11, 13), Pair(10, 18), Pair(15, 16), Pair(18, 8), Pair(15, 18),
        Pair(24, 12), Pair(10, 28), Pair(12, 13), Pair(1, 6), Pair(8, 13), Pair(5, -5), Pair(0, -11), Pair(14, 8),
        Pair(-83, 33), Pair(-12, 21), Pair(4, 2), Pair(22, 5), Pair(3, -19), Pair(9, -13), Pair(10, 3), Pair(19, -70)
      },
      { // Piece 2
        Pair(26, 39), Pair(-51, 88), Pair(-88, 66), Pair(-63, 73), Pair(-4, 83), Pair(-4, 95), Pair(54, 37), Pair(62, 63),
        Pair(12, 50), Pair(-12, 47), Pair(9, 43), Pair(-46, 84), Pair(-42, 91), Pair(-13, 78), Pair(9, 69), Pair(20, 36),
        Pair(-9, 60), Pair(-2, 52), Pair(-17, 59), Pair(-6, 78), Pair(10, 71), Pair(11, 63), Pair(12, 47), Pair(25, 23),
        Pair(23, 41), Pair(1, 50), Pair(0, 63), Pair(5, 55), Pair(7, 61), Pair(6, 59), Pair(11, 35), Pair(3, 33),
        Pair(0, 0), Pair(0, 63), Pair(7, 47), Pair(-1, 46), Pair(12, 40), Pair(1, 36), Pair(7, 32), Pair(5, 35),
        Pair(21, 108), Pair(-19, 1), Pair(5, 46), Pair(7, 48), Pair(2, 32), Pair(2, 33), Pair(-2, 30), Pair(9, 17),
        Pair(11, 45), Pair(1, 39), Pair(9, 34), Pair(5, 35), Pair(-4, 37), Pair(2, 16), Pair(4, 20), Pair(-3, 12),
        Pair(9, 46), Pair(4, 70), Pair(0, 33), Pair(2, 37), Pair(-10, 31), Pair(13, 17), Pair(-28, 47), Pair(11, 43)
      },
      { // Piece 3
        Pair(0, 98), Pair(8, 85), Pair(20, 82), Pair(22, 80), Pair(34, 75), Pair(10, 76), Pair(18, 69), Pair(33, 70),
        Pair(16, 107), Pair(7, 76), Pair(3, 88), Pair(1, 87), Pair(18, 73), Pair(60, 59), Pair(76, 51), Pair(10, 72),
        Pair(12, 103), Pair(11, 74), Pair(17, 76), Pair(9, 76), Pair(41, 60), Pair(37, 64), Pair(52, 58), Pair(33, 58),
        Pair(-1, 101), Pair(-1, 72), Pair(-3, 79), Pair(-14, 74), Pair(-2, 72), Pair(18, 56), Pair(26, 60), Pair(19, 62),
        Pair(0, 0), Pair(-3, 81), Pair(-16, 88), Pair(-5, 74), Pair(-3, 73), Pair(0, 59), Pair(20, 52), Pair(31, 52),
        Pair(-7, 76), Pair(-7, 32), Pair(-20, 71), Pair(-9, 63), Pair(-4, 58), Pair(-7, 64), Pair(17, 62), Pair(10, 68),
        Pair(-32, 65), Pair(-1, 56), Pair(-12, 63), Pair(-15, 59), Pair(1, 55), Pair(-5, 59), Pair(9, 53), Pair(1, 57),
        Pair(-18, 55), Pair(-12, 62), Pair(-8, 65), Pair(-5, 64), Pair(-2, 64), Pair(1, 64), Pair(11, 72), Pair(3, 59)
      },
      { // Piece 4
        Pair(8, 148), Pair(86, 81), Pair(51, 145), Pair(118, 59), Pair(-4, 179), Pair(-17, 180), Pair(-20, 219), Pair(85, 111),
        Pair(41, 122), Pair(35, 124), Pair(15, 146), Pair(16, 165), Pair(48, 131), Pair(42, 139), Pair(48, 139), Pair(54, 109),
        Pair(28, 132), Pair(38, 112), Pair(26, 144), Pair(24, 148), Pair(55, 120), Pair(60, 102), Pair(66, 90), Pair(68, 101),
        Pair(7, 137), Pair(17, 129), Pair(26, 112), Pair(29, 119), Pair(25, 137), Pair(43, 142), Pair(41, 108), Pair(68, 78),
        Pair(0, 0), Pair(22, 143), Pair(29, 115), Pair(19, 131), Pair(21, 127), Pair(33, 112), Pair(38, 99), Pair(35, 118),
        Pair(0, 125), Pair(33, 60), Pair(12, 110), Pair(23, 91), Pair(27, 100), Pair(27, 97), Pair(41, 67), Pair(35, 104),
        Pair(10, 91), Pair(26, 71), Pair(19, 110), Pair(21, 99), Pair(25, 95), Pair(26, 91), Pair(25, 80), Pair(30, 125),
        Pair(23, 51), Pair(16, 115), Pair(10, 117), Pair(21, 105), Pair(20, 102), Pair(16, 70), Pair(27, 105), Pair(2, 118)
      },
      { // Piece 5
        Pair(-66, -29), Pair(-5, 0), Pair(21, -22), Pair(49, -27), Pair(26, -98), Pair(-28, -42), Pair(-20, -31), Pair(56, -41),
        Pair(53, 44), Pair(-37, -41), Pair(154, -38), Pair(-141, 24), Pair(-62, -4), Pair(-3, -36), Pair(37, -54), Pair(57, -51),
        Pair(-28, -70), Pair(104, -22), Pair(112, -20), Pair(66, -28), Pair(104, -32), Pair(20, -26), Pair(32, -29), Pair(78, -53),
        Pair(78, -26), Pair(-24, 26), Pair(62, -8), Pair(65, -8), Pair(87, -20), Pair(54, -9), Pair(98, -32), Pair(64, -23),
        Pair(0, 0), Pair(-38, 32), Pair(-1, 5), Pair(-2, 3), Pair(66, -15), Pair(39, -15), Pair(42, -23), Pair(72, -33),
        Pair(14, 11), Pair(-29, 32), Pair(-48, 15), Pair(15, 6), Pair(-4, 4), Pair(36, -13), Pair(11, -18), Pair(47, -27),
        Pair(-3, 27), Pair(-3, 41), Pair(-27, 23), Pair(-40, 17), Pair(-2, -5), Pair(8, -14), Pair(0, -14), Pair(2, -11),
        Pair(17, -3), Pair(29, -5), Pair(-26, 24), Pair(-16, 5), Pair(-14, -10), Pair(-2, -20), Pair(0, -24), Pair(11, -21)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 13), Pair(25, 13), Pair(1, 18), Pair(9, 12), Pair(1, 13), Pair(-7, 12), Pair(24, 14), Pair(-7, 19),
        Pair(-1, 3), Pair(-6, 10), Pair(-4, 10), Pair(3, 6), Pair(1, 9), Pair(2, 18), Pair(-7, 9), Pair(-14, 16),
        Pair(3, 4), Pair(0, 0), Pair(-1, 1), Pair(1, 3), Pair(1, 3), Pair(-5, 3), Pair(-4, 3), Pair(-6, 5),
        Pair(4, 1), Pair(0, 0), Pair(-1, 0), Pair(1, 3), Pair(0, -2), Pair(-5, -1), Pair(-8, 0), Pair(-6, 2),
        Pair(-1, -8), Pair(10, 10), Pair(-4, 0), Pair(0, -3), Pair(-5, -4), Pair(-10, 0), Pair(-9, -3), Pair(-8, 3),
        Pair(3, -11), Pair(10, 3), Pair(-5, -6), Pair(4, -14), Pair(-4, -4), Pair(-6, -6), Pair(-8, -6), Pair(-6, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-75, 31), Pair(83, 11), Pair(-16, 40), Pair(13, 24), Pair(64, 13), Pair(129, -35), Pair(63, -29), Pair(-2, 40),
        Pair(20, 27), Pair(4, 30), Pair(28, 30), Pair(41, 37), Pair(40, 48), Pair(51, 8), Pair(44, 23), Pair(42, 2),
        Pair(-17, 44), Pair(14, 40), Pair(-3, 55), Pair(21, 35), Pair(42, 18), Pair(38, 38), Pair(43, 14), Pair(30, 4),
        Pair(11, 37), Pair(-11, 18), Pair(12, 47), Pair(14, 29), Pair(23, 38), Pair(28, 28), Pair(30, 18), Pair(27, 11),
        Pair(-7, 19), Pair(0, 0), Pair(4, 60), Pair(7, 55), Pair(13, 29), Pair(13, 28), Pair(20, 27), Pair(22, 17),
        Pair(-19, -66), Pair(14, 81), Pair(-17, -38), Pair(12, 29), Pair(4, 24), Pair(10, 26), Pair(3, 26), Pair(9, 20),
        Pair(-10, -22), Pair(-23, 54), Pair(8, 27), Pair(2, 40), Pair(-5, 20), Pair(-3, 30), Pair(1, 23), Pair(16, 11),
        Pair(-101, 66), Pair(-28, -84), Pair(-5, 47), Pair(-3, 8), Pair(3, 25), Pair(0, 20), Pair(-7, 19), Pair(0, 22)
      },
      { // Piece 2
        Pair(-29, 47), Pair(-11, 69), Pair(-84, 58), Pair(-105, 79), Pair(-91, 88), Pair(-66, 86), Pair(-26, 102), Pair(-27, 84),
        Pair(-26, 61), Pair(-24, 58), Pair(-6, 59), Pair(-59, 73), Pair(-55, 73), Pair(6, 99), Pair(-8, 58), Pair(-4, 62),
        Pair(8, 44), Pair(-27, 67), Pair(-13, 64), Pair(-8, 55), Pair(-24, 92), Pair(-18, 80), Pair(7, 59), Pair(16, 41),
        Pair(-32, 21), Pair(-9, 54), Pair(-18, 57), Pair(-21, 74), Pair(11, 55), Pair(1, 57), Pair(0, 44), Pair(10, 35),
        Pair(-14, 80), Pair(0, 0), Pair(-7, 63), Pair(-4, 54), Pair(-1, 52), Pair(3, 46), Pair(-4, 42), Pair(15, 43),
        Pair(-17, -52), Pair(-3, 118), Pair(-15, 11), Pair(1, 51), Pair(2, 34), Pair(-7, 44), Pair(-2, 32), Pair(2, 28),
        Pair(-12, 63), Pair(4, 21), Pair(-4, 58), Pair(-6, 20), Pair(-5, 44), Pair(-1, 37), Pair(1, 34), Pair(-1, 35),
        Pair(3, 23), Pair(14, 46), Pair(-2, 23), Pair(-16, 53), Pair(-12, 21), Pair(-7, 44), Pair(22, 31), Pair(-6, 35)
      },
      { // Piece 3
        Pair(11, 58), Pair(38, 71), Pair(5, 74), Pair(32, 59), Pair(11, 73), Pair(18, 67), Pair(-27, 74), Pair(-3, 65),
        Pair(14, 66), Pair(24, 86), Pair(0, 69), Pair(13, 70), Pair(4, 68), Pair(42, 47), Pair(28, 46), Pair(26, 52),
        Pair(7, 61), Pair(4, 89), Pair(23, 68), Pair(4, 64), Pair(7, 65), Pair(16, 60), Pair(6, 51), Pair(24, 52),
        Pair(0, 53), Pair(-1, 84), Pair(-3, 59), Pair(-6, 69), Pair(-2, 62), Pair(2, 59), Pair(17, 48), Pair(22, 42),
        Pair(-7, 41), Pair(0, 0), Pair(-11, 68), Pair(-19, 76), Pair(-8, 54), Pair(-5, 58), Pair(3, 40), Pair(11, 42),
        Pair(-1, -20), Pair(-32, 78), Pair(12, -15), Pair(-3, 56), Pair(-5, 53), Pair(-8, 48), Pair(8, 50), Pair(3, 59),
        Pair(-24, 36), Pair(-26, 46), Pair(-11, 50), Pair(-10, 40), Pair(-1, 39), Pair(-4, 48), Pair(-4, 47), Pair(-5, 56),
        Pair(-10, 56), Pair(-10, 42), Pair(-8, 51), Pair(-5, 57), Pair(-4, 50), Pair(-2, 56), Pair(-2, 59), Pair(8, 52)
      },
      { // Piece 4
        Pair(61, 50), Pair(-34, 117), Pair(33, 91), Pair(81, 60), Pair(24, 95), Pair(34, 71), Pair(21, 115), Pair(48, 75),
        Pair(42, 67), Pair(37, 90), Pair(34, 102), Pair(14, 101), Pair(5, 129), Pair(2, 131), Pair(-29, 160), Pair(18, 113),
        Pair(42, 59), Pair(44, 79), Pair(26, 94), Pair(35, 85), Pair(40, 93), Pair(46, 82), Pair(47, 87), Pair(62, 48),
        Pair(26, 46), Pair(49, 44), Pair(29, 79), Pair(26, 84), Pair(34, 81), Pair(36, 107), Pair(41, 85), Pair(43, 87),
        Pair(19, 55), Pair(0, 0), Pair(15, 78), Pair(24, 85), Pair(20, 75), Pair(37, 74), Pair(30, 66), Pair(36, 57),
        Pair(50, 10), Pair(14, 71), Pair(33, 44), Pair(11, 70), Pair(19, 59), Pair(38, 50), Pair(25, 68), Pair(30, 102),
        Pair(6, 64), Pair(11, 52), Pair(9, 61), Pair(19, 60), Pair(19, 60), Pair(20, 51), Pair(29, 26), Pair(8, 113),
        Pair(2, 82), Pair(14, 54), Pair(15, 58), Pair(18, 52), Pair(11, 69), Pair(19, 49), Pair(59, 10), Pair(11, 88)
      },
      { // Piece 5
        Pair(-42, -183), Pair(-52, -101), Pair(22, -62), Pair(-6, 4), Pair(-28, 16), Pair(-72, -61), Pair(22, -78), Pair(-19, -117),
        Pair(82, -51), Pair(94, -59), Pair(2, -19), Pair(23, -35), Pair(-66, -2), Pair(-26, -24), Pair(-36, -18), Pair(-55, 0),
        Pair(33, -43), Pair(-7, -19), Pair(231, -43), Pair(91, -15), Pair(0, -18), Pair(-20, -7), Pair(-9, -9), Pair(41, -16),
        Pair(18, -5), Pair(14, -7), Pair(32, 19), Pair(93, -18), Pair(93, -12), Pair(68, -10), Pair(42, -13), Pair(57, -32),
        Pair(-22, 6), Pair(0, 0), Pair(28, -4), Pair(34, -3), Pair(32, -1), Pair(54, -17), Pair(13, -7), Pair(53, -34),
        Pair(26, 19), Pair(-76, -12), Pair(-32, -22), Pair(-19, 6), Pair(8, 3), Pair(3, 1), Pair(10, -19), Pair(38, -22),
        Pair(-47, 22), Pair(-50, 16), Pair(-4, 18), Pair(-33, 10), Pair(-10, 6), Pair(4, -11), Pair(-5, -10), Pair(-6, -6),
        Pair(-41, 26), Pair(-8, -16), Pair(2, 2), Pair(-16, 12), Pair(-11, -3), Pair(3, -6), Pair(-4, -14), Pair(10, -26)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 11), Pair(5, 5), Pair(7, -5), Pair(-3, 7), Pair(14, 10), Pair(4, 14), Pair(3, 10), Pair(-31, 22),
        Pair(-3, 10), Pair(-1, 3), Pair(-1, 13), Pair(-1, 4), Pair(3, 11), Pair(7, 7), Pair(4, 13), Pair(-8, 6),
        Pair(2, 0), Pair(1, -2), Pair(0, 0), Pair(-3, 1), Pair(-1, 4), Pair(-1, 2), Pair(-1, 1), Pair(-3, 1),
        Pair(3, -1), Pair(3, -2), Pair(0, 0), Pair(2, -5), Pair(-2, 1), Pair(-3, 0), Pair(3, -4), Pair(-6, 1),
        Pair(6, -1), Pair(5, -24), Pair(8, 15), Pair(6, -10), Pair(-1, -2), Pair(-10, -3), Pair(-3, -3), Pair(-8, -2),
        Pair(3, -1), Pair(0, -14), Pair(10, 5), Pair(-9, -5), Pair(1, -4), Pair(-7, -3), Pair(-4, -5), Pair(-5, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-37, 41), Pair(-2, 38), Pair(34, 24), Pair(37, 21), Pair(-14, 50), Pair(85, 28), Pair(49, 68), Pair(-84, 66),
        Pair(15, 25), Pair(1, 35), Pair(24, 48), Pair(34, 25), Pair(63, 37), Pair(30, 46), Pair(17, 47), Pair(29, 46),
        Pair(11, 50), Pair(-2, 37), Pair(-5, 37), Pair(7, 50), Pair(14, 43), Pair(15, 45), Pair(9, 37), Pair(44, 25),
        Pair(-25, -5), Pair(10, 55), Pair(-9, 27), Pair(10, 62), Pair(17, 26), Pair(31, 53), Pair(22, 32), Pair(31, 21),
        Pair(14, 31), Pair(-3, 40), Pair(0, 0), Pair(4, 59), Pair(12, 58), Pair(8, 39), Pair(28, 49), Pair(16, 32),
        Pair(6, 62), Pair(-28, -18), Pair(18, 103), Pair(-15, -39), Pair(16, 41), Pair(13, 30), Pair(16, 35), Pair(16, 50),
        Pair(-17, 69), Pair(-11, 51), Pair(9, 59), Pair(5, 23), Pair(12, 45), Pair(-6, 32), Pair(14, 35), Pair(25, 23),
        Pair(-75, -6), Pair(2, 48), Pair(-10, -11), Pair(-3, 56), Pair(1, 35), Pair(19, 37), Pair(4, 41), Pair(40, -5)
      },
      { // Piece 2
        Pair(-6, 30), Pair(11, 42), Pair(-27, 55), Pair(-28, 48), Pair(-57, 71), Pair(-12, 60), Pair(-113, 60), Pair(24, 82),
        Pair(-19, 36), Pair(-7, 48), Pair(-16, 53), Pair(-10, 44), Pair(-1, 61), Pair(0, 59), Pair(-13, 75), Pair(-15, 67),
        Pair(-29, 41), Pair(-16, 49), Pair(-23, 60), Pair(-1, 59), Pair(7, 52), Pair(9, 80), Pair(5, 58), Pair(23, 42),
        Pair(1, 67), Pair(-25, 42), Pair(-4, 53), Pair(19, 39), Pair(9, 66), Pair(-1, 48), Pair(7, 55), Pair(14, 31),
        Pair(-13, 37), Pair(-6, 70), Pair(0, 0), Pair(2, 64), Pair(-7, 55), Pair(6, 48), Pair(7, 26), Pair(18, 32),
        Pair(-4, 49), Pair(-50, -28), Pair(16, 109), Pair(-8, -28), Pair(-1, 51), Pair(5, 40), Pair(8, 36), Pair(9, 19),
        Pair(-58, -49), Pair(-6, 35), Pair(-1, 38), Pair(-2, 45), Pair(-4, 11), Pair(-7, 40), Pair(8, 26), Pair(16, 18),
        Pair(-9, 68), Pair(-6, 41), Pair(3, 35), Pair(-2, 30), Pair(0, 52), Pair(-3, 6), Pair(15, 24), Pair(12, 54)
      },
      { // Piece 3
        Pair(14, 64), Pair(41, 52), Pair(47, 57), Pair(-10, 75), Pair(39, 46), Pair(-19, 63), Pair(38, 53), Pair(22, 52),
        Pair(4, 61), Pair(3, 69), Pair(14, 74), Pair(17, 54), Pair(21, 65), Pair(36, 51), Pair(43, 40), Pair(33, 44),
        Pair(11, 59), Pair(11, 51), Pair(-13, 79), Pair(10, 50), Pair(2, 61), Pair(47, 41), Pair(36, 40), Pair(29, 37),
        Pair(-8, 59), Pair(-5, 53), Pair(-4, 84), Pair(-2, 54), Pair(10, 49), Pair(21, 54), Pair(39, 39), Pair(26, 40),
        Pair(-2, 60), Pair(-12, 62), Pair(0, 0), Pair(-2, 55), Pair(-3, 54), Pair(7, 50), Pair(32, 26), Pair(22, 37),
        Pair(-15, 60), Pair(18, -46), Pair(-31, 73), Pair(26, -5), Pair(-1, 56), Pair(-2, 47), Pair(10, 53), Pair(19, 33),
        Pair(-5, 32), Pair(-9, 39), Pair(-18, 39), Pair(-3, 38), Pair(4, 38), Pair(14, 39), Pair(17, 44), Pair(7, 31),
        Pair(-4, 46), Pair(-10, 49), Pair(-15, 41), Pair(0, 42), Pair(0, 58), Pair(2, 54), Pair(15, 46), Pair(7, 51)
      },
      { // Piece 4
        Pair(37, 63), Pair(33, 75), Pair(29, 112), Pair(24, 83), Pair(40, 94), Pair(28, 65), Pair(71, 79), Pair(48, 83),
        Pair(28, 89), Pair(13, 103), Pair(38, 64), Pair(-2, 108), Pair(22, 123), Pair(96, 87), Pair(39, 85), Pair(39, 130),
        Pair(10, 55), Pair(19, 77), Pair(27, 78), Pair(27, 83), Pair(12, 119), Pair(32, 114), Pair(29, 81), Pair(49, 85),
        Pair(23, 82), Pair(24, 50), Pair(22, 104), Pair(18, 102), Pair(27, 102), Pair(29, 104), Pair(54, 76), Pair(38, 102),
        Pair(19, 53), Pair(4, 87), Pair(0, 0), Pair(17, 100), Pair(23, 82), Pair(32, 78), Pair(36, 75), Pair(44, 74),
        Pair(19, 72), Pair(30, -2), Pair(23, 74), Pair(28, -22), Pair(20, 79), Pair(25, 72), Pair(26, 80), Pair(30, 72),
        Pair(-7, 115), Pair(17, 54), Pair(23, 45), Pair(17, 63), Pair(20, 54), Pair(39, 43), Pair(22, 73), Pair(40, 71),
        Pair(15, 68), Pair(19, 51), Pair(24, 29), Pair(21, 38), Pair(18, 70), Pair(20, 64), Pair(7, 114), Pair(29, 62)
      },
      { // Piece 5
        Pair(-31, -102), Pair(0, -16), Pair(-74, -84), Pair(1, -47), Pair(-79, -69), Pair(-30, -37), Pair(54, -70), Pair(-44, -53),
        Pair(9, -44), Pair(16, -19), Pair(-163, -46), Pair(11, 4), Pair(129, -65), Pair(60, -52), Pair(196, -84), Pair(-36, -21),
        Pair(-98, 8), Pair(-13, -3), Pair(25, -5), Pair(83, -17), Pair(78, -25), Pair(166, -39), Pair(-34, -8), Pair(87, -45),
        Pair(1, -28), Pair(109, -21), Pair(104, -15), Pair(6, 17), Pair(66, -11), Pair(125, -22), Pair(45, -16), Pair(32, -22),
        Pair(-24, 8), Pair(-41, 9), Pair(0, 0), Pair(91, -11), Pair(46, -2), Pair(18, 0), Pair(28, -1), Pair(43, -24),
        Pair(-13, 29), Pair(50, 0), Pair(-82, 12), Pair(-127, 32), Pair(-35, 17), Pair(24, 8), Pair(5, 0), Pair(22, -11),
        Pair(-61, 34), Pair(-42, 26), Pair(-32, 24), Pair(3, 11), Pair(-20, 7), Pair(1, 12), Pair(3, -3), Pair(17, -14),
        Pair(-28, 38), Pair(-34, 13), Pair(-40, 16), Pair(-9, 6), Pair(-10, 11), Pair(11, 0), Pair(5, -7), Pair(12, -13)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, 27), Pair(-9, 16), Pair(-4, 3), Pair(14, -2), Pair(-4, 17), Pair(0, 16), Pair(19, 21), Pair(12, 10),
        Pair(-6, 16), Pair(1, 7), Pair(-2, -1), Pair(-1, 7), Pair(1, 11), Pair(-1, 5), Pair(14, 5), Pair(-4, 15),
        Pair(-5, 1), Pair(0, -2), Pair(2, -1), Pair(0, 0), Pair(-1, 1), Pair(1, 3), Pair(2, 4), Pair(1, 6),
        Pair(-3, 0), Pair(3, -6), Pair(-1, -1), Pair(0, 0), Pair(-6, 1), Pair(-3, 1), Pair(0, -2), Pair(2, 0),
        Pair(-3, -2), Pair(3, -5), Pair(-4, -33), Pair(13, 12), Pair(-5, -26), Pair(-7, -1), Pair(-3, -1), Pair(-3, -4),
        Pair(-1, -2), Pair(-2, -4), Pair(-3, -13), Pair(0, -4), Pair(-13, -13), Pair(-4, -5), Pair(2, -1), Pair(3, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-61, 12), Pair(-4, 1), Pair(-31, 39), Pair(-59, 60), Pair(12, 35), Pair(-65, 60), Pair(37, -57), Pair(-11, 17),
        Pair(-13, 39), Pair(22, 17), Pair(9, 18), Pair(-18, 49), Pair(59, 12), Pair(25, 44), Pair(21, 1), Pair(-5, 57),
        Pair(61, 4), Pair(8, 38), Pair(-6, 37), Pair(21, 35), Pair(12, 32), Pair(17, 32), Pair(14, 39), Pair(16, 34),
        Pair(1, 36), Pair(-9, -10), Pair(1, 56), Pair(-6, 33), Pair(8, 52), Pair(-2, 30), Pair(12, 49), Pair(25, 33),
        Pair(-8, -2), Pair(-11, 52), Pair(2, 49), Pair(0, 0), Pair(3, 56), Pair(2, 58), Pair(2, 40), Pair(4, 42),
        Pair(-4, 23), Pair(-5, 27), Pair(-22, -31), Pair(20, 105), Pair(-29, -23), Pair(6, 29), Pair(2, 31), Pair(9, 33),
        Pair(-2, -42), Pair(-36, 43), Pair(-20, 10), Pair(2, 45), Pair(-10, 4), Pair(-7, 46), Pair(6, 0), Pair(8, 27),
        Pair(-69, 7), Pair(-14, -4), Pair(-15, 32), Pair(-46, -23), Pair(0, 33), Pair(-13, 16), Pair(4, 33), Pair(17, 21)
      },
      { // Piece 2
        Pair(2, 58), Pair(-62, 56), Pair(-29, 55), Pair(-71, 42), Pair(-60, 56), Pair(-37, 36), Pair(-60, 74), Pair(-56, 22),
        Pair(-42, 39), Pair(0, 49), Pair(5, 27), Pair(-47, 57), Pair(-25, 69), Pair(-11, 57), Pair(-35, 63), Pair(17, 65),
        Pair(10, 46), Pair(-16, 34), Pair(-9, 46), Pair(-3, 40), Pair(-13, 50), Pair(-13, 36), Pair(-6, 73), Pair(8, 20),
        Pair(-16, 36), Pair(-3, 62), Pair(-43, 39), Pair(-6, 54), Pair(8, 35), Pair(2, 58), Pair(-6, 35), Pair(3, 49),
        Pair(-7, 53), Pair(-19, 37), Pair(-3, 66), Pair(0, 0), Pair(0, 67), Pair(-3, 33), Pair(9, 45), Pair(0, 34),
        Pair(-12, 18), Pair(-12, 52), Pair(-38, -49), Pair(14, 115), Pair(-12, -47), Pair(-2, 51), Pair(4, 29), Pair(15, 22),
        Pair(-9, 46), Pair(-41, -29), Pair(-30, 59), Pair(0, 24), Pair(-17, 40), Pair(-20, 7), Pair(1, 33), Pair(-4, 14),
        Pair(-83, -56), Pair(-8, 62), Pair(-2, 16), Pair(-4, 38), Pair(-21, 38), Pair(-6, 46), Pair(-50, 10), Pair(6, 46)
      },
      { // Piece 3
        Pair(17, 46), Pair(-4, 52), Pair(23, 47), Pair(-15, 59), Pair(7, 55), Pair(13, 60), Pair(1, 52), Pair(-24, 71),
        Pair(0, 50), Pair(0, 55), Pair(7, 62), Pair(-17, 70), Pair(2, 59), Pair(8, 60), Pair(19, 50), Pair(5, 58),
        Pair(4, 47), Pair(14, 42), Pair(3, 50), Pair(8, 56), Pair(12, 41), Pair(25, 34), Pair(-6, 52), Pair(14, 42),
        Pair(3, 47), Pair(-5, 56), Pair(8, 44), Pair(-22, 72), Pair(2, 49), Pair(2, 53), Pair(27, 32), Pair(4, 43),
        Pair(-13, 36), Pair(-17, 64), Pair(-10, 42), Pair(0, 0), Pair(-3, 41), Pair(-16, 55), Pair(9, 38), Pair(22, 36),
        Pair(-16, 51), Pair(-18, 51), Pair(-18, 11), Pair(-30, 64), Pair(-28, 24), Pair(-16, 62), Pair(-4, 45), Pair(18, 26),
        Pair(1, 22), Pair(-19, 43), Pair(-4, 31), Pair(-33, 46), Pair(-9, 40), Pair(4, 35), Pair(17, 33), Pair(20, 32),
        Pair(-3, 42), Pair(-5, 47), Pair(-4, 38), Pair(-19, 42), Pair(-6, 45), Pair(1, 53), Pair(7, 34), Pair(13, 38)
      },
      { // Piece 4
        Pair(3, 95), Pair(29, 76), Pair(15, 113), Pair(52, 71), Pair(49, 69), Pair(29, 118), Pair(56, 96), Pair(26, 105),
        Pair(20, 65), Pair(18, 86), Pair(-1, 125), Pair(26, 72), Pair(38, 95), Pair(9, 134), Pair(13, 137), Pair(45, 76),
        Pair(21, 83), Pair(24, 52), Pair(24, 85), Pair(40, 74), Pair(21, 124), Pair(35, 108), Pair(11, 109), Pair(25, 92),
        Pair(10, 92), Pair(18, 78), Pair(22, 75), Pair(23, 83), Pair(27, 97), Pair(19, 114), Pair(26, 98), Pair(13, 107),
        Pair(10, 81), Pair(21, 53), Pair(13, 56), Pair(0, 0), Pair(11, 89), Pair(24, 85), Pair(22, 85), Pair(21, 91),
        Pair(1, 95), Pair(11, 53), Pair(15, 35), Pair(25, 79), Pair(15, -6), Pair(15, 86), Pair(19, 86), Pair(15, 98),
        Pair(0, 83), Pair(4, 55), Pair(2, 70), Pair(7, 81), Pair(13, 65), Pair(18, 60), Pair(20, 65), Pair(25, 48),
        Pair(4, 65), Pair(3, 93), Pair(15, 39), Pair(15, 70), Pair(15, 62), Pair(14, 78), Pair(5, 22), Pair(27, 41)
      },
      { // Piece 5
        Pair(-29, -58), Pair(-49, -28), Pair(6, -49), Pair(-58, -39), Pair(29, -14), Pair(23, -46), Pair(23, -62), Pair(3, -84),
        Pair(11, -51), Pair(-29, -47), Pair(92, -55), Pair(-14, -88), Pair(22, -35), Pair(-61, -21), Pair(65, -41), Pair(-80, -23),
        Pair(-13, -10), Pair(87, -42), Pair(82, -21), Pair(93, -33), Pair(36, -13), Pair(149, -18), Pair(65, -20), Pair(35, -37),
        Pair(-22, -14), Pair(79, -8), Pair(136, -23), Pair(70, -20), Pair(44, 13), Pair(120, -17), Pair(70, -16), Pair(55, -13),
        Pair(45, 0), Pair(-31, 13), Pair(28, -20), Pair(0, 0), Pair(60, -33), Pair(11, 9), Pair(20, 8), Pair(50, -23),
        Pair(-54, 35), Pair(2, 18), Pair(90, 9), Pair(-52, -6), Pair(121, -34), Pair(6, 10), Pair(13, 7), Pair(39, -7),
        Pair(-40, 45), Pair(-46, 24), Pair(4, 7), Pair(1, 5), Pair(-9, 12), Pair(-8, 14), Pair(2, 19), Pair(2, 16),
        Pair(-16, 23), Pair(-34, 29), Pair(-12, 21), Pair(-21, -3), Pair(2, -2), Pair(-2, 14), Pair(5, 11), Pair(6, 4)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(12, 10), Pair(-4, 16), Pair(-3, 4), Pair(-18, 9), Pair(-5, 17), Pair(-5, 6), Pair(16, 8), Pair(7, 10),
        Pair(5, 5), Pair(5, -3), Pair(0, 9), Pair(1, -3), Pair(-4, 5), Pair(-4, 5), Pair(9, 0), Pair(-6, 3),
        Pair(2, -2), Pair(1, -4), Pair(0, -4), Pair(2, 0), Pair(0, 0), Pair(0, 3), Pair(3, 0), Pair(3, 4),
        Pair(5, -2), Pair(-2, -7), Pair(3, -7), Pair(-1, -5), Pair(0, 0), Pair(0, 0), Pair(5, -4), Pair(3, -1),
        Pair(3, -9), Pair(0, -8), Pair(-3, -7), Pair(3, -13), Pair(8, 8), Pair(-5, -25), Pair(1, -4), Pair(4, -3),
        Pair(5, -5), Pair(-3, -7), Pair(3, -10), Pair(-3, -15), Pair(7, -7), Pair(-8, -11), Pair(5, 3), Pair(6, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-3, 7), Pair(-95, 47), Pair(-53, 45), Pair(5, 42), Pair(-16, 44), Pair(-17, 32), Pair(-46, 58), Pair(-23, -6),
        Pair(-1, 34), Pair(-1, 28), Pair(-6, 38), Pair(27, 29), Pair(-15, 46), Pair(-15, 51), Pair(6, 17), Pair(-1, 28),
        Pair(-12, 42), Pair(0, 41), Pair(3, 39), Pair(8, 25), Pair(15, 49), Pair(19, 28), Pair(-3, 32), Pair(-9, 32),
        Pair(3, 30), Pair(2, 35), Pair(0, 24), Pair(-8, 48), Pair(-4, 35), Pair(7, 43), Pair(-3, 1), Pair(8, 42),
        Pair(-2, 33), Pair(-7, 24), Pair(-6, 48), Pair(2, 44), Pair(0, 0), Pair(-11, 48), Pair(-1, 52), Pair(-14, -6),
        Pair(2, 31), Pair(-9, 34), Pair(2, 27), Pair(-30, -24), Pair(13, 83), Pair(-20, -45), Pair(-3, 36), Pair(2, 29),
        Pair(-2, 59), Pair(-16, 15), Pair(-8, 33), Pair(-9, 12), Pair(-5, 36), Pair(-12, 3), Pair(-12, 32), Pair(-8, -17),
        Pair(5, 11), Pair(6, 35), Pair(-7, 9), Pair(1, 30), Pair(-26, -30), Pair(-14, 33), Pair(-17, 12), Pair(-14, 54)
      },
      { // Piece 2
        Pair(-68, 46), Pair(-63, 49), Pair(-62, 69), Pair(-86, 61), Pair(-44, 61), Pair(-67, 57), Pair(-7, 46), Pair(-33, 31),
        Pair(11, 36), Pair(-20, 42), Pair(10, 34), Pair(-54, 64), Pair(-14, 50), Pair(4, 55), Pair(7, 28), Pair(-8, 15),
        Pair(-14, 39), Pair(-14, 57), Pair(-36, 47), Pair(-3, 49), Pair(-24, 53), Pair(18, 36), Pair(-51, 47), Pair(18, 45),
        Pair(-3, 37), Pair(-11, 40), Pair(-19, 52), Pair(-28, 45), Pair(-1, 48), Pair(-18, 35), Pair(-1, 45), Pair(-25, 37),
        Pair(-23, 38), Pair(-9, 37), Pair(-13, 43), Pair(5, 54), Pair(0, 0), Pair(4, 57), Pair(-9, 33), Pair(13, 31),
        Pair(-2, 28), Pair(-10, 31), Pair(-13, 44), Pair(-37, -28), Pair(5, 96), Pair(-38, -39), Pair(8, 34), Pair(-7, 23),
        Pair(-23, 51), Pair(-5, 32), Pair(-32, 18), Pair(-8, 22), Pair(-7, 21), Pair(-28, 45), Pair(-39, -20), Pair(12, 40),
        Pair(-14, 40), Pair(-39, -8), Pair(-7, 26), Pair(-14, 31), Pair(-10, 39), Pair(-3, 16), Pair(-36, 82), Pair(-70, -64)
      },
      { // Piece 3
        Pair(-5, 49), Pair(-1, 40), Pair(-6, 49), Pair(4, 44), Pair(-24, 62), Pair(22, 41), Pair(33, 41), Pair(33, 32),
        Pair(-5, 38), Pair(-10, 45), Pair(-2, 45), Pair(-1, 57), Pair(6, 51), Pair(9, 36), Pair(15, 36), Pair(29, 27),
        Pair(3, 44), Pair(-6, 40), Pair(1, 38), Pair(3, 40), Pair(27, 34), Pair(25, 36), Pair(0, 34), Pair(28, 27),
        Pair(-1, 33), Pair(-12, 50), Pair(-2, 41), Pair(-8, 39), Pair(7, 52), Pair(21, 29), Pair(23, 27), Pair(10, 40),
        Pair(9, 39), Pair(-1, 31), Pair(-10, 36), Pair(-2, 31), Pair(0, 0), Pair(-1, 40), Pair(3, 31), Pair(-5, 17),
        Pair(-2, 37), Pair(-6, 31), Pair(-9, 33), Pair(-13, -18), Pair(-11, 44), Pair(-16, -9), Pair(9, 21), Pair(6, 13),
        Pair(3, 23), Pair(-6, 30), Pair(-11, 33), Pair(-5, 27), Pair(-10, 21), Pair(11, 32), Pair(31, 29), Pair(24, 11),
        Pair(-2, 34), Pair(1, 32), Pair(-2, 37), Pair(-10, 33), Pair(-17, 31), Pair(1, 32), Pair(20, 29), Pair(7, 39)
      },
      { // Piece 4
        Pair(-14, 85), Pair(47, 47), Pair(-20, 105), Pair(-2, 85), Pair(44, 53), Pair(0, 83), Pair(36, 87), Pair(9, 59),
        Pair(13, 83), Pair(1, 75), Pair(4, 85), Pair(-2, 89), Pair(7, 91), Pair(-3, 117), Pair(-2, 114), Pair(31, 53),
        Pair(9, 68), Pair(3, 83), Pair(14, 49), Pair(11, 63), Pair(19, 67), Pair(25, 75), Pair(8, 60), Pair(4, 104),
        Pair(7, 49), Pair(12, 62), Pair(4, 78), Pair(7, 39), Pair(20, 78), Pair(15, 74), Pair(15, 74), Pair(11, 80),
        Pair(9, 56), Pair(15, 45), Pair(14, 34), Pair(18, 67), Pair(0, 0), Pair(17, 60), Pair(14, 58), Pair(27, 51),
        Pair(7, 55), Pair(8, 49), Pair(11, 56), Pair(16, -7), Pair(20, 56), Pair(19, -17), Pair(0, 82), Pair(16, 54),
        Pair(4, 64), Pair(7, 57), Pair(3, 47), Pair(1, 62), Pair(8, 45), Pair(0, 68), Pair(-6, 52), Pair(22, 108),
        Pair(8, 52), Pair(5, 39), Pair(4, 65), Pair(12, 28), Pair(2, 63), Pair(3, 50), Pair(45, 36), Pair(27, -19)
      },
      { // Piece 5
        Pair(-59, -53), Pair(1, -39), Pair(177, -54), Pair(-18, 12), Pair(0, -58), Pair(65, -53), Pair(-54, -20), Pair(8, -66),
        Pair(-56, -39), Pair(86, -33), Pair(-20, -38), Pair(89, -27), Pair(117, -84), Pair(55, -41), Pair(53, -40), Pair(-43, -26),
        Pair(-14, -38), Pair(27, -26), Pair(5, -27), Pair(111, -17), Pair(191, -54), Pair(216, -49), Pair(103, -35), Pair(-105, -5),
        Pair(82, -40), Pair(113, -31), Pair(104, -29), Pair(-41, 6), Pair(67, -13), Pair(113, -18), Pair(93, -14), Pair(93, -19),
        Pair(-2, 5), Pair(38, 4), Pair(-2, 1), Pair(68, -30), Pair(0, 0), Pair(87, -39), Pair(19, 2), Pair(21, 11),
        Pair(46, -4), Pair(40, -1), Pair(19, 4), Pair(-128, 11), Pair(-38, -14), Pair(-51, -14), Pair(3, 17), Pair(-12, 21),
        Pair(18, -8), Pair(8, 7), Pair(0, 5), Pair(50, -7), Pair(20, -5), Pair(33, -3), Pair(-17, 23), Pair(-3, 25),
        Pair(25, 2), Pair(-3, 24), Pair(-2, 20), Pair(25, -3), Pair(-13, 10), Pair(-4, 8), Pair(-12, 21), Pair(-5, 22)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, 7), Pair(21, 7), Pair(27, 4), Pair(0, 7), Pair(7, 6), Pair(-55, 10), Pair(-15, 10), Pair(34, 4),
        Pair(8, -2), Pair(7, -3), Pair(3, 0), Pair(-1, 0), Pair(0, 4), Pair(24, -8), Pair(-2, 7), Pair(1, 3),
        Pair(3, -5), Pair(4, -4), Pair(3, -1), Pair(1, -2), Pair(-1, -3), Pair(0, 0), Pair(11, -2), Pair(5, 5),
        Pair(5, -10), Pair(7, -4), Pair(-1, -7), Pair(-1, -2), Pair(4, -5), Pair(0, 0), Pair(2, -4), Pair(2, 1),
        Pair(-1, -6), Pair(4, -7), Pair(-5, -6), Pair(2, -4), Pair(-3, -6), Pair(20, 4), Pair(-6, -21), Pair(4, -3),
        Pair(4, -9), Pair(1, -8), Pair(4, -7), Pair(3, -13), Pair(-4, -15), Pair(7, -3), Pair(-1, -13), Pair(5, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-18, -4), Pair(42, 10), Pair(-69, 29), Pair(-17, 10), Pair(17, 18), Pair(-64, 45), Pair(103, -54), Pair(-69, 79),
        Pair(-13, 17), Pair(-4, 9), Pair(14, 19), Pair(22, 35), Pair(35, 23), Pair(23, 45), Pair(8, 17), Pair(-23, 30),
        Pair(12, -4), Pair(1, 20), Pair(8, 16), Pair(24, 17), Pair(35, 19), Pair(-5, 36), Pair(17, 15), Pair(-34, 32),
        Pair(1, 8), Pair(5, 6), Pair(12, 24), Pair(14, 11), Pair(30, 45), Pair(5, 18), Pair(27, 31), Pair(-27, -18),
        Pair(14, -5), Pair(4, 24), Pair(8, 12), Pair(13, 31), Pair(12, 31), Pair(0, 0), Pair(12, 13), Pair(6, 26),
        Pair(1, 7), Pair(4, 20), Pair(6, 11), Pair(18, 19), Pair(-19, -26), Pair(26, 66), Pair(-41, -44), Pair(4, 25),
        Pair(13, -11), Pair(-9, 17), Pair(-7, 12), Pair(7, 27), Pair(-7, 2), Pair(10, 31), Pair(-22, -9), Pair(3, 10),
        Pair(-77, -9), Pair(-2, 25), Pair(12, -13), Pair(-26, 1), Pair(6, 30), Pair(-20, -26), Pair(-1, 46), Pair(-34, -24)
      },
      { // Piece 2
        Pair(-26, 60), Pair(40, -2), Pair(-3, 44), Pair(-16, 47), Pair(-54, 53), Pair(-117, 42), Pair(-32, 39), Pair(46, -6),
        Pair(-20, 12), Pair(-7, 50), Pair(-32, 29), Pair(-21, 51), Pair(-47, 47), Pair(15, 28), Pair(-11, 34), Pair(8, 36),
        Pair(-14, 41), Pair(-30, 37), Pair(-5, 55), Pair(-25, 30), Pair(-7, 35), Pair(-23, 50), Pair(-9, 39), Pair(-53, 3),
        Pair(-8, 28), Pair(15, 28), Pair(1, 30), Pair(1, 40), Pair(-23, 34), Pair(-6, 49), Pair(-22, 9), Pair(-1, 45),
        Pair(-2, 29), Pair(-10, 25), Pair(-3, 24), Pair(-8, 29), Pair(23, 36), Pair(0, 0), Pair(1, 44), Pair(-44, 24),
        Pair(-10, 19), Pair(-4, 20), Pair(-1, 22), Pair(3, 29), Pair(-24, -33), Pair(11, 85), Pair(-72, -76), Pair(-5, 27),
        Pair(10, 26), Pair(-7, 21), Pair(-6, 29), Pair(-16, 5), Pair(4, 17), Pair(-12, 12), Pair(-1, 18), Pair(-61, -98),
        Pair(-1, 17), Pair(-1, 54), Pair(-19, -17), Pair(3, 31), Pair(-10, 27), Pair(7, 18), Pair(-32, 26), Pair(-26, 58)
      },
      { // Piece 3
        Pair(16, 27), Pair(19, 20), Pair(47, 23), Pair(17, 34), Pair(-9, 47), Pair(-23, 46), Pair(19, 47), Pair(1, 42),
        Pair(14, 11), Pair(1, 20), Pair(35, 17), Pair(17, 28), Pair(35, 22), Pair(27, 17), Pair(43, 17), Pair(28, 27),
        Pair(16, 25), Pair(7, 20), Pair(14, 21), Pair(27, 13), Pair(12, 26), Pair(24, 32), Pair(18, 20), Pair(18, 24),
        Pair(5, 18), Pair(8, 29), Pair(20, 16), Pair(24, 14), Pair(26, 19), Pair(62, 29), Pair(10, 19), Pair(12, 22),
        Pair(2, 22), Pair(13, 20), Pair(9, 17), Pair(-4, 25), Pair(8, 21), Pair(0, 0), Pair(7, 13), Pair(-1, 22),
        Pair(18, 8), Pair(7, 21), Pair(3, 14), Pair(16, 4), Pair(31, -81), Pair(-16, 43), Pair(46, -30), Pair(2, 21),
        Pair(15, 6), Pair(16, 12), Pair(12, 12), Pair(14, 6), Pair(17, 3), Pair(1, 12), Pair(29, 12), Pair(22, 9),
        Pair(10, 12), Pair(10, 20), Pair(11, 20), Pair(6, 19), Pair(6, 19), Pair(3, 17), Pair(19, 8), Pair(6, 15)
      },
      { // Piece 4
        Pair(35, 11), Pair(3, 44), Pair(10, 45), Pair(-24, 86), Pair(97, -41), Pair(-56, 99), Pair(23, 40), Pair(57, 59),
        Pair(3, 49), Pair(-14, 83), Pair(29, 11), Pair(-26, 84), Pair(-15, 79), Pair(15, 49), Pair(-40, 72), Pair(-30, 77),
        Pair(23, 32), Pair(1, 29), Pair(-6, 67), Pair(10, 34), Pair(13, 83), Pair(28, 34), Pair(28, 23), Pair(47, -25),
        Pair(-4, 65), Pair(1, 54), Pair(3, 42), Pair(10, 60), Pair(21, 29), Pair(8, 46), Pair(-7, 26), Pair(7, 27),
        Pair(-1, 55), Pair(-2, 54), Pair(10, 31), Pair(1, 53), Pair(0, 43), Pair(0, 0), Pair(-5, 54), Pair(-14, 61),
        Pair(1, 46), Pair(-1, 44), Pair(14, 40), Pair(0, 60), Pair(-23, -20), Pair(11, 23), Pair(44, -180), Pair(9, 35),
        Pair(-2, 56), Pair(-3, 64), Pair(4, 27), Pair(1, 30), Pair(-3, 37), Pair(3, 15), Pair(8, 24), Pair(-15, -5),
        Pair(3, 21), Pair(7, 45), Pair(14, -23), Pair(7, 6), Pair(-1, 2), Pair(-15, 58), Pair(23, -42), Pair(-16, 42)
      },
      { // Piece 5
        Pair(-23, -78), Pair(93, -49), Pair(-90, -93), Pair(13, -84), Pair(19, -59), Pair(-83, -22), Pair(-61, -46), Pair(45, -50),
        Pair(-53, -49), Pair(71, -68), Pair(62, -38), Pair(72, -55), Pair(17, -20), Pair(131, -48), Pair(-3, -15), Pair(24, -75),
        Pair(-48, -14), Pair(-11, -30), Pair(20, -24), Pair(-30, -21), Pair(55, -44), Pair(268, -50), Pair(142, -29), Pair(77, -18),
        Pair(-121, -6), Pair(-21, -12), Pair(54, -10), Pair(68, -16), Pair(12, 9), Pair(133, -4), Pair(25, 1), Pair(-49, 15),
        Pair(68, -23), Pair(55, -14), Pair(29, -16), Pair(16, 1), Pair(34, -15), Pair(0, 0), Pair(21, -8), Pair(-42, 25),
        Pair(59, -21), Pair(42, -15), Pair(62, -10), Pair(13, 5), Pair(90, -3), Pair(-43, -3), Pair(7, -3), Pair(-50, 33),
        Pair(30, -24), Pair(25, -14), Pair(20, 1), Pair(16, -1), Pair(14, 7), Pair(-1, 15), Pair(9, 14), Pair(-25, 27),
        Pair(11, 2), Pair(-2, 4), Pair(-3, 2), Pair(-7, 7), Pair(-15, 10), Pair(-22, 15), Pair(-12, 14), Pair(-14, 27)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(37, -10), Pair(-9, 15), Pair(31, 2), Pair(10, 6), Pair(-8, 16), Pair(-4, 23), Pair(4, 2), Pair(-29, 16),
        Pair(3, -3), Pair(-1, 0), Pair(0, -1), Pair(12, 0), Pair(0, 6), Pair(1, 6), Pair(-5, 3), Pair(-8, 2),
        Pair(1, -4), Pair(3, -4), Pair(0, -2), Pair(-3, -4), Pair(-4, 0), Pair(-10, 2), Pair(0, 0), Pair(-3, 4),
        Pair(4, -8), Pair(4, -9), Pair(1, -8), Pair(-6, -7), Pair(-7, -3), Pair(1, -2), Pair(0, 0), Pair(9, -1),
        Pair(5, -8), Pair(1, -9), Pair(-2, -6), Pair(-1, -8), Pair(5, -8), Pair(-5, -2), Pair(3, 0), Pair(-3, 4),
        Pair(2, -8), Pair(4, -9), Pair(0, -8), Pair(-7, -8), Pair(2, -8), Pair(-2, -6), Pair(-4, -1), Pair(1, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, -65), Pair(-91, 4), Pair(-142, 40), Pair(72, -5), Pair(-29, 23), Pair(-41, 33), Pair(69, 0), Pair(90, -82),
        Pair(32, 5), Pair(23, -1), Pair(7, 4), Pair(-17, 31), Pair(55, 14), Pair(15, 18), Pair(26, 12), Pair(33, -4),
        Pair(-26, 7), Pair(7, 2), Pair(16, 14), Pair(24, 12), Pair(24, 15), Pair(-1, 32), Pair(0, 30), Pair(67, -16),
        Pair(6, 13), Pair(13, 17), Pair(12, 11), Pair(30, 21), Pair(29, 7), Pair(22, 26), Pair(-12, 15), Pair(32, 6),
        Pair(10, 10), Pair(8, 6), Pair(16, 17), Pair(9, 19), Pair(14, 25), Pair(25, 21), Pair(0, 0), Pair(-5, 1),
        Pair(-5, 11), Pair(0, 14), Pair(3, 22), Pair(11, 17), Pair(10, 15), Pair(-19, -32), Pair(24, 65), Pair(-36, -24),
        Pair(7, 33), Pair(-10, 5), Pair(-9, 10), Pair(-6, 9), Pair(-2, 20), Pair(1, 18), Pair(-3, 42), Pair(-9, -33),
        Pair(-83, 25), Pair(-20, 1), Pair(-18, 20), Pair(-1, 12), Pair(-9, 10), Pair(5, 27), Pair(-35, -87), Pair(-22, 6)
      },
      { // Piece 2
        Pair(-24, 35), Pair(-47, 50), Pair(-182, 78), Pair(-105, 58), Pair(-80, 59), Pair(1, 42), Pair(71, 26), Pair(34, 35),
        Pair(-33, 37), Pair(-8, 34), Pair(-9, 52), Pair(-42, 49), Pair(-13, 42), Pair(-54, 61), Pair(-23, 45), Pair(-2, 44),
        Pair(-2, 27), Pair(-2, 22), Pair(-28, 53), Pair(-5, 45), Pair(-28, 59), Pair(0, 37), Pair(-38, 68), Pair(11, 17),
        Pair(-5, 24), Pair(4, 34), Pair(-8, 28), Pair(11, 41), Pair(21, 29), Pair(-25, 39), Pair(0, 31), Pair(-68, 10),
        Pair(-2, 22), Pair(-3, 19), Pair(14, 23), Pair(13, 20), Pair(10, 22), Pair(9, 29), Pair(0, 0), Pair(5, 29),
        Pair(1, 17), Pair(12, 20), Pair(-1, 23), Pair(1, 27), Pair(10, 10), Pair(-17, -11), Pair(11, 85), Pair(-21, -93),
        Pair(1, 22), Pair(6, 10), Pair(-8, 25), Pair(-6, 18), Pair(-10, 13), Pair(-16, 34), Pair(11, 9), Pair(-3, 1),
        Pair(5, 14), Pair(2, 22), Pair(-7, 10), Pair(-15, 15), Pair(5, 29), Pair(0, 12), Pair(-34, 35), Pair(-6, 14)
      },
      { // Piece 3
        Pair(14, 30), Pair(2, 39), Pair(-44, 51), Pair(3, 26), Pair(10, 35), Pair(-32, 44), Pair(-21, 45), Pair(-24, 52),
        Pair(7, 15), Pair(43, 3), Pair(4, 23), Pair(16, 14), Pair(11, 24), Pair(51, 0), Pair(59, 30), Pair(32, 13),
        Pair(23, 12), Pair(11, 24), Pair(19, 4), Pair(42, 10), Pair(24, 17), Pair(-13, 30), Pair(12, 35), Pair(14, 15),
        Pair(14, 14), Pair(-4, 27), Pair(18, 20), Pair(18, 21), Pair(20, 23), Pair(28, 14), Pair(46, 23), Pair(2, 12),
        Pair(-2, 21), Pair(16, 18), Pair(-6, 31), Pair(6, 15), Pair(4, 28), Pair(15, 21), Pair(0, 0), Pair(14, -7),
        Pair(7, 23), Pair(5, 14), Pair(-3, 18), Pair(-3, 18), Pair(14, 19), Pair(14, -60), Pair(-11, 45), Pair(-34, -6),
        Pair(5, 22), Pair(8, 8), Pair(6, 15), Pair(2, 20), Pair(2, 18), Pair(3, 14), Pair(-9, 13), Pair(7, -11),
        Pair(6, 21), Pair(7, 20), Pair(10, 19), Pair(8, 17), Pair(9, 19), Pair(6, 15), Pair(-11, 11), Pair(2, 16)
      },
      { // Piece 4
        Pair(50, -42), Pair(24, 15), Pair(38, -35), Pair(71, -11), Pair(15, 39), Pair(187, -112), Pair(-25, 62), Pair(-2, 42),
        Pair(6, 8), Pair(5, 2), Pair(2, 25), Pair(-10, 19), Pair(-14, 80), Pair(5, 21), Pair(46, -12), Pair(0, 56),
        Pair(8, -5), Pair(30, -16), Pair(-18, 31), Pair(-4, 17), Pair(-18, 51), Pair(-13, 48), Pair(-1, 50), Pair(10, 26),
        Pair(5, -3), Pair(9, 12), Pair(9, 12), Pair(-18, 50), Pair(-12, 67), Pair(10, 18), Pair(-18, 37), Pair(-34, 11),
        Pair(6, -6), Pair(2, 21), Pair(-4, 13), Pair(-8, 58), Pair(5, 34), Pair(17, 30), Pair(0, 0), Pair(-23, -9),
        Pair(-10, 30), Pair(-3, 21), Pair(-2, 14), Pair(-5, 11), Pair(9, 0), Pair(-22, 1), Pair(-11, 35), Pair(19, -16),
        Pair(-8, 37), Pair(-8, -7), Pair(7, -8), Pair(-13, 24), Pair(-5, 19), Pair(0, 21), Pair(-18, -44), Pair(-19, 17),
        Pair(-8, -21), Pair(15, -41), Pair(4, 0), Pair(0, -24), Pair(-8, -11), Pair(3, -38), Pair(-24, 39), Pair(-15, -19)
      },
      { // Piece 5
        Pair(30, -74), Pair(22, -44), Pair(-17, -66), Pair(51, -29), Pair(105, -9), Pair(-28, -57), Pair(-69, -68), Pair(-14, -223),
        Pair(-74, -39), Pair(5, -39), Pair(135, -79), Pair(72, -45), Pair(-6, -41), Pair(104, -67), Pair(85, -68), Pair(-6, -25),
        Pair(224, -60), Pair(16, -25), Pair(-27, -19), Pair(48, -44), Pair(44, -28), Pair(202, -42), Pair(126, -40), Pair(225, -43),
        Pair(26, -38), Pair(80, -32), Pair(109, -42), Pair(-26, -10), Pair(36, -10), Pair(96, 12), Pair(28, 8), Pair(-4, 16),
        Pair(-82, -8), Pair(99, -33), Pair(41, -16), Pair(51, -8), Pair(21, 2), Pair(59, -18), Pair(0, 0), Pair(-53, -1),
        Pair(74, -36), Pair(49, -34), Pair(31, -14), Pair(24, -6), Pair(-10, 6), Pair(145, -13), Pair(-32, -16), Pair(8, 16),
        Pair(-10, -17), Pair(-15, -8), Pair(-2, -4), Pair(11, 1), Pair(-32, 10), Pair(24, 5), Pair(1, 15), Pair(5, 9),
        Pair(-33, -8), Pair(-28, -21), Pair(-22, -8), Pair(-15, 4), Pair(-28, 11), Pair(6, 7), Pair(-10, 8), Pair(-16, 2)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(25, 2), Pair(1, 6), Pair(17, 3), Pair(16, 5), Pair(16, 1), Pair(7, 2), Pair(-9, 21), Pair(75, -29),
        Pair(13, -5), Pair(12, -6), Pair(14, -6), Pair(3, -3), Pair(-5, 3), Pair(-15, 8), Pair(-10, 4), Pair(10, -8),
        Pair(5, -8), Pair(7, -5), Pair(2, -2), Pair(0, -5), Pair(-2, -2), Pair(-4, -4), Pair(2, -4), Pair(0, 0),
        Pair(3, -10), Pair(3, -13), Pair(2, -6), Pair(-2, -6), Pair(0, -6), Pair(2, -3), Pair(-2, -8), Pair(0, 0),
        Pair(3, -12), Pair(7, -11), Pair(0, -11), Pair(3, -5), Pair(4, -6), Pair(-1, 0), Pair(-19, -14), Pair(7, 4),
        Pair(6, -8), Pair(3, -10), Pair(2, -14), Pair(-4, -11), Pair(-1, -3), Pair(0, -4), Pair(-10, -12), Pair(-6, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(45, -73), Pair(92, -20), Pair(39, 6), Pair(22, -15), Pair(-40, 22), Pair(-139, 49), Pair(74, -36), Pair(56, -50),
        Pair(-1, -8), Pair(18, -18), Pair(32, -15), Pair(41, 1), Pair(75, -20), Pair(98, -22), Pair(-18, -12), Pair(-19, 41),
        Pair(8, -5), Pair(16, -15), Pair(24, -6), Pair(46, -11), Pair(49, -8), Pair(1, 5), Pair(20, 10), Pair(-44, 56),
        Pair(22, -16), Pair(21, -9), Pair(31, -6), Pair(36, -7), Pair(55, -5), Pair(34, -3), Pair(17, 1), Pair(29, -11),
        Pair(16, -26), Pair(23, -16), Pair(15, -5), Pair(32, 2), Pair(18, -3), Pair(28, 4), Pair(40, 8), Pair(0, 0),
        Pair(-4, -15), Pair(9, 1), Pair(17, -4), Pair(15, -5), Pair(31, 1), Pair(24, 5), Pair(-19, -50), Pair(26, 44),
        Pair(10, -38), Pair(-14, -12), Pair(5, -17), Pair(9, -2), Pair(0, 3), Pair(5, 8), Pair(20, 18), Pair(19, 10),
        Pair(41, -76), Pair(5, -31), Pair(-1, 1), Pair(-1, -1), Pair(14, -6), Pair(6, -17), Pair(5, 13), Pair(-16, -103)
      },
      { // Piece 2
        Pair(-16, 31), Pair(-83, 44), Pair(-133, 70), Pair(-40, 37), Pair(-157, 60), Pair(34, 32), Pair(-123, 27), Pair(-32, 48),
        Pair(-7, 34), Pair(-4, 33), Pair(-5, 39), Pair(-110, 73), Pair(-84, 54), Pair(-25, 31), Pair(-7, 15), Pair(58, 7),
        Pair(-11, 19), Pair(-1, 29), Pair(-20, 38), Pair(14, 29), Pair(3, 45), Pair(-19, 42), Pair(-26, 30), Pair(12, 27),
        Pair(-3, 13), Pair(3, 19), Pair(-3, 23), Pair(8, 22), Pair(22, 25), Pair(-6, 30), Pair(5, 38), Pair(16, 21),
        Pair(-19, 19), Pair(2, 18), Pair(11, 17), Pair(24, 12), Pair(15, 14), Pair(10, 18), Pair(11, 23), Pair(0, 0),
        Pair(-1, 12), Pair(8, 18), Pair(20, 14), Pair(7, 11), Pair(16, 10), Pair(6, 20), Pair(-23, -21), Pair(4, 74),
        Pair(-14, 10), Pair(11, 2), Pair(-1, 10), Pair(9, 15), Pair(3, 7), Pair(2, 19), Pair(10, 9), Pair(23, -5),
        Pair(8, -5), Pair(-48, 22), Pair(1, 14), Pair(4, 6), Pair(6, 19), Pair(7, 13), Pair(24, 17), Pair(13, 46)
      },
      { // Piece 3
        Pair(3, 21), Pair(30, 17), Pair(-27, 39), Pair(-4, 31), Pair(-12, 22), Pair(-37, 45), Pair(9, 34), Pair(16, 43),
        Pair(35, 9), Pair(43, -2), Pair(8, 20), Pair(39, 9), Pair(-2, 24), Pair(35, 6), Pair(12, 25), Pair(92, 13),
        Pair(16, 10), Pair(16, 15), Pair(11, 9), Pair(27, 3), Pair(53, 0), Pair(-21, 36), Pair(30, 0), Pair(89, 15),
        Pair(12, 16), Pair(10, 13), Pair(11, 17), Pair(26, 11), Pair(19, 10), Pair(20, 12), Pair(18, 14), Pair(40, 28),
        Pair(13, 1), Pair(13, 20), Pair(21, 18), Pair(14, 19), Pair(19, 13), Pair(20, 28), Pair(31, 30), Pair(0, 0),
        Pair(-10, 26), Pair(9, 25), Pair(11, 16), Pair(8, 4), Pair(-1, 17), Pair(3, 19), Pair(-26, 4), Pair(-17, 41),
        Pair(-2, 12), Pair(15, 6), Pair(11, 0), Pair(12, 8), Pair(16, 9), Pair(18, 10), Pair(-8, 31), Pair(-1, 14),
        Pair(15, 7), Pair(8, 15), Pair(14, 11), Pair(12, 19), Pair(12, 13), Pair(14, 18), Pair(4, 20), Pair(-8, 10)
      },
      { // Piece 4
        Pair(11, -14), Pair(3, 15), Pair(44, -11), Pair(37, 11), Pair(78, -37), Pair(53, -17), Pair(-18, 27), Pair(25, 24),
        Pair(25, -5), Pair(10, -13), Pair(-14, 35), Pair(9, 32), Pair(34, 21), Pair(20, 19), Pair(-6, 19), Pair(37, 12),
        Pair(-7, 16), Pair(31, -18), Pair(7, 37), Pair(-25, 55), Pair(29, -9), Pair(24, 24), Pair(-32, 26), Pair(16, 8),
        Pair(-2, 8), Pair(6, 4), Pair(10, 4), Pair(14, 2), Pair(-5, 53), Pair(32, 14), Pair(-4, 18), Pair(13, 53),
        Pair(8, 12), Pair(1, 6), Pair(5, 22), Pair(12, 21), Pair(24, 18), Pair(13, 42), Pair(12, 16), Pair(0, 0),
        Pair(-1, -16), Pair(-4, 11), Pair(21, -4), Pair(6, 9), Pair(4, 21), Pair(-11, 33), Pair(32, -63), Pair(-27, 34),
        Pair(-1, 7), Pair(6, -5), Pair(6, 5), Pair(9, 7), Pair(1, 28), Pair(6, 27), Pair(15, -15), Pair(-32, -46),
        Pair(-2, -1), Pair(-16, 21), Pair(0, 10), Pair(5, 10), Pair(-1, 2), Pair(-28, 65), Pair(-4, -23), Pair(-30, 41)
      },
      { // Piece 5
        Pair(-9, -72), Pair(11, -55), Pair(91, -123), Pair(40, -66), Pair(58, -32), Pair(54, -71), Pair(10, -84), Pair(-19, -114),
        Pair(130, -66), Pair(3, -68), Pair(-26, -49), Pair(23, -46), Pair(3, -55), Pair(72, -50), Pair(-34, -45), Pair(19, -68),
        Pair(29, -69), Pair(21, -29), Pair(58, -45), Pair(18, -41), Pair(178, -51), Pair(126, -20), Pair(66, -43), Pair(171, -70),
        Pair(44, -41), Pair(43, -41), Pair(93, -34), Pair(109, -33), Pair(49, -15), Pair(95, -21), Pair(21, 12), Pair(61, -6),
        Pair(73, -58), Pair(93, -49), Pair(81, -38), Pair(75, -18), Pair(45, -1), Pair(32, 1), Pair(11, -9), Pair(0, 0),
        Pair(70, -55), Pair(27, -29), Pair(-13, -21), Pair(38, -14), Pair(8, 7), Pair(-27, 23), Pair(-25, -9), Pair(40, -14),
        Pair(-32, 6), Pair(-12, -22), Pair(6, -20), Pair(0, -5), Pair(-29, 15), Pair(-37, 24), Pair(-2, 31), Pair(19, 18),
        Pair(-12, -12), Pair(-26, -20), Pair(-26, -22), Pair(-36, -11), Pair(-30, 16), Pair(-48, 34), Pair(3, 14), Pair(-6, 8)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(27, -15), Pair(-4, 9), Pair(-1, 8), Pair(-7, 19), Pair(-4, 22), Pair(21, 7), Pair(-11, 22), Pair(-1, 22),
        Pair(17, -11), Pair(-2, 10), Pair(3, 7), Pair(-3, 7), Pair(-3, 10), Pair(-7, 14), Pair(-9, 18), Pair(-8, 20),
        Pair(0, 0), Pair(-5, -2), Pair(-5, 0), Pair(2, 1), Pair(-6, 2), Pair(-4, 9), Pair(-3, 7), Pair(-3, 9),
        Pair(0, 0), Pair(-4, -5), Pair(-3, -4), Pair(-3, 0), Pair(-3, 4), Pair(-5, 3), Pair(-4, 0), Pair(-4, 2),
        Pair(1, 6), Pair(-5, -1), Pair(0, -1), Pair(1, -3), Pair(-2, 1), Pair(-8, 2), Pair(-6, 0), Pair(-7, -4),
        Pair(8, 1), Pair(-3, -3), Pair(4, -2), Pair(-3, -1), Pair(-5, -3), Pair(-4, -1), Pair(-3, -2), Pair(-1, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-57, 19), Pair(-9, 9), Pair(17, 15), Pair(20, 37), Pair(-5, 34), Pair(-38, 65), Pair(-48, 67), Pair(-3, -4),
        Pair(35, 64), Pair(5, 32), Pair(15, 41), Pair(32, 35), Pair(-8, 49), Pair(60, 16), Pair(22, 8), Pair(55, 19),
        Pair(-8, 34), Pair(2, 32), Pair(0, 43), Pair(12, 45), Pair(21, 35), Pair(43, 31), Pair(28, 21), Pair(25, 10),
        Pair(0, 0), Pair(7, 40), Pair(-9, 53), Pair(8, 35), Pair(11, 37), Pair(20, 25), Pair(18, 31), Pair(29, 19),
        Pair(4, 75), Pair(-63, -31), Pair(4, 42), Pair(4, 39), Pair(9, 37), Pair(7, 28), Pair(25, 23), Pair(12, 28),
        Pair(-5, 49), Pair(-10, 38), Pair(-4, 43), Pair(-6, 35), Pair(2, 32), Pair(0, 33), Pair(8, 27), Pair(8, 34),
        Pair(-14, -1), Pair(-15, 56), Pair(-9, 28), Pair(-3, 43), Pair(0, 30), Pair(1, 22), Pair(-14, 34), Pair(4, 14),
        Pair(-41, 35), Pair(-3, 28), Pair(-3, 34), Pair(3, 33), Pair(-12, 33), Pair(3, 27), Pair(-1, 24), Pair(-6, 4)
      },
      { // Piece 2
        Pair(-14, 53), Pair(-42, 92), Pair(-45, 68), Pair(-45, 106), Pair(-39, 79), Pair(-13, 69), Pair(22, 61), Pair(-21, 67),
        Pair(11, 57), Pair(-21, 60), Pair(-4, 79), Pair(-45, 84), Pair(-6, 89), Pair(-17, 87), Pair(-2, 75), Pair(11, 44),
        Pair(-1, 58), Pair(-16, 91), Pair(-37, 75), Pair(-12, 85), Pair(-18, 76), Pair(1, 86), Pair(3, 68), Pair(15, 55),
        Pair(0, 0), Pair(-15, 62), Pair(-11, 75), Pair(-21, 62), Pair(4, 77), Pair(-10, 61), Pair(-1, 63), Pair(-10, 50),
        Pair(-9, 101), Pair(-113, 52), Pair(-10, 57), Pair(-4, 71), Pair(-6, 55), Pair(-5, 64), Pair(-19, 46), Pair(2, 56),
        Pair(2, 61), Pair(-22, 56), Pair(-11, 72), Pair(-13, 58), Pair(-1, 53), Pair(-17, 42), Pair(1, 52), Pair(-3, 36),
        Pair(-15, 85), Pair(0, 64), Pair(-6, 54), Pair(-9, 51), Pair(-18, 44), Pair(-15, 50), Pair(-10, 38), Pair(-1, 37),
        Pair(-8, 72), Pair(-3, 66), Pair(-3, 61), Pair(-22, 52), Pair(-15, 61), Pair(-13, 44), Pair(-15, 58), Pair(-17, 48)
      },
      { // Piece 3
        Pair(46, 90), Pair(-7, 93), Pair(-22, 97), Pair(2, 90), Pair(-4, 100), Pair(1, 92), Pair(34, 79), Pair(15, 89),
        Pair(3, 114), Pair(-16, 103), Pair(-15, 105), Pair(0, 90), Pair(-2, 104), Pair(30, 84), Pair(43, 83), Pair(28, 87),
        Pair(14, 109), Pair(-3, 91), Pair(-3, 99), Pair(-9, 87), Pair(-4, 92), Pair(22, 89), Pair(22, 79), Pair(22, 83),
        Pair(0, 0), Pair(-12, 104), Pair(-15, 114), Pair(-20, 101), Pair(-8, 95), Pair(-10, 83), Pair(2, 89), Pair(14, 83),
        Pair(-14, 94), Pair(28, -7), Pair(-40, 99), Pair(-23, 93), Pair(-23, 89), Pair(-20, 82), Pair(8, 84), Pair(11, 72),
        Pair(-39, 83), Pair(-19, 84), Pair(-25, 83), Pair(-17, 72), Pair(-16, 74), Pair(-8, 75), Pair(-2, 81), Pair(9, 78),
        Pair(-19, 72), Pair(-22, 79), Pair(-21, 82), Pair(-20, 74), Pair(-28, 85), Pair(-12, 78), Pair(-6, 91), Pair(-6, 79),
        Pair(-25, 75), Pair(-22, 82), Pair(-20, 84), Pair(-19, 84), Pair(-16, 80), Pair(-13, 80), Pair(-4, 78), Pair(-13, 83)
      },
      { // Piece 4
        Pair(-9, 171), Pair(58, 120), Pair(11, 189), Pair(-22, 226), Pair(44, 155), Pair(64, 125), Pair(114, 98), Pair(79, 129),
        Pair(21, 174), Pair(33, 150), Pair(36, 179), Pair(13, 176), Pair(33, 176), Pair(57, 142), Pair(36, 161), Pair(69, 121),
        Pair(24, 150), Pair(37, 152), Pair(22, 164), Pair(27, 161), Pair(41, 148), Pair(63, 146), Pair(62, 140), Pair(55, 160),
        Pair(0, 0), Pair(19, 154), Pair(38, 152), Pair(20, 158), Pair(23, 171), Pair(37, 173), Pair(49, 145), Pair(48, 136),
        Pair(24, 149), Pair(75, 20), Pair(21, 136), Pair(26, 143), Pair(28, 148), Pair(34, 136), Pair(27, 155), Pair(40, 145),
        Pair(15, 154), Pair(19, 128), Pair(28, 141), Pair(26, 131), Pair(22, 139), Pair(30, 131), Pair(35, 127), Pair(42, 121),
        Pair(31, 129), Pair(17, 145), Pair(22, 136), Pair(24, 136), Pair(26, 120), Pair(31, 121), Pair(18, 123), Pair(37, 124),
        Pair(20, 141), Pair(23, 131), Pair(16, 138), Pair(21, 130), Pair(23, 133), Pair(18, 129), Pair(35, 113), Pair(32, 105)
      },
      { // Piece 5
        Pair(-27, 45), Pair(-56, -84), Pair(-46, 13), Pair(26, 2), Pair(-92, -4), Pair(-45, -22), Pair(-41, 2), Pair(-10, -24),
        Pair(46, 12), Pair(-102, 6), Pair(116, -13), Pair(137, -46), Pair(95, -16), Pair(80, -27), Pair(-28, -9), Pair(37, -23),
        Pair(-79, -6), Pair(94, -8), Pair(66, -18), Pair(28, 2), Pair(127, -28), Pair(8, -6), Pair(20, -5), Pair(11, -7),
        Pair(0, 0), Pair(50, -35), Pair(28, -3), Pair(23, -10), Pair(82, -10), Pair(48, -3), Pair(43, -10), Pair(69, -10),
        Pair(30, -53), Pair(47, -82), Pair(-1, -3), Pair(30, -3), Pair(23, -2), Pair(26, -6), Pair(17, -1), Pair(58, -19),
        Pair(34, -18), Pair(8, 0), Pair(-7, -5), Pair(18, 5), Pair(17, 1), Pair(4, -3), Pair(14, -4), Pair(19, -3),
        Pair(5, -13), Pair(-1, 7), Pair(-8, 15), Pair(14, 2), Pair(9, -1), Pair(8, -7), Pair(0, -2), Pair(5, -3),
        Pair(-1, 3), Pair(16, 6), Pair(8, 13), Pair(12, 3), Pair(10, -12), Pair(6, -9), Pair(2, -11), Pair(7, -11)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 19), Pair(40, -15), Pair(-12, 17), Pair(7, 12), Pair(-1, 18), Pair(7, 17), Pair(-15, 15), Pair(9, 25),
        Pair(-1, 10), Pair(15, 1), Pair(0, 11), Pair(6, 13), Pair(-4, 14), Pair(1, 15), Pair(-7, 18), Pair(-13, 19),
        Pair(-1, 2), Pair(0, 0), Pair(-3, 2), Pair(-4, 6), Pair(1, 9), Pair(-5, 6), Pair(-2, 10), Pair(-2, 12),
        Pair(5, 6), Pair(0, 0), Pair(4, 9), Pair(0, 2), Pair(-4, 3), Pair(-6, 7), Pair(-1, 5), Pair(-3, 9),
        Pair(6, -2), Pair(3, 2), Pair(1, 9), Pair(1, 0), Pair(-5, 5), Pair(-8, 2), Pair(-6, -1), Pair(-3, 3),
        Pair(5, 4), Pair(12, 5), Pair(0, -3), Pair(1, -3), Pair(-6, 3), Pair(-7, -1), Pair(-4, -2), Pair(-4, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-37, 14), Pair(37, 46), Pair(-5, 48), Pair(-32, 78), Pair(10, 53), Pair(30, 51), Pair(-61, 43), Pair(-15, 4),
        Pair(-16, 44), Pair(10, 52), Pair(24, 31), Pair(54, 36), Pair(31, 48), Pair(44, 45), Pair(46, 32), Pair(40, 26),
        Pair(16, 53), Pair(17, 14), Pair(0, 63), Pair(22, 40), Pair(43, 46), Pair(45, 49), Pair(42, 38), Pair(44, 27),
        Pair(-8, 37), Pair(0, 0), Pair(5, 52), Pair(19, 60), Pair(14, 46), Pair(26, 47), Pair(26, 41), Pair(30, 32),
        Pair(-27, 2), Pair(13, 84), Pair(-26, 0), Pair(8, 49), Pair(11, 49), Pair(21, 44), Pair(28, 34), Pair(23, 35),
        Pair(-10, 12), Pair(9, 45), Pair(-3, 34), Pair(10, 48), Pair(2, 46), Pair(10, 46), Pair(12, 42), Pair(20, 49),
        Pair(9, 46), Pair(-24, -18), Pair(13, 48), Pair(4, 33), Pair(10, 48), Pair(8, 39), Pair(14, 31), Pair(10, 65),
        Pair(28, 36), Pair(-1, 33), Pair(10, 46), Pair(8, 35), Pair(15, 37), Pair(21, 38), Pair(8, 46), Pair(-33, 60)
      },
      { // Piece 2
        Pair(-9, 79), Pair(10, 69), Pair(-10, 77), Pair(-57, 87), Pair(-60, 91), Pair(-61, 102), Pair(-19, 76), Pair(-29, 79),
        Pair(8, 59), Pair(-23, 88), Pair(0, 68), Pair(-19, 97), Pair(-24, 97), Pair(14, 71), Pair(19, 78), Pair(3, 60),
        Pair(-54, 48), Pair(-11, 70), Pair(-4, 77), Pair(-5, 68), Pair(12, 80), Pair(17, 74), Pair(-5, 90), Pair(27, 41),
        Pair(2, 67), Pair(0, 0), Pair(-14, 79), Pair(0, 71), Pair(10, 68), Pair(14, 62), Pair(16, 64), Pair(24, 52),
        Pair(-46, 16), Pair(3, 96), Pair(-26, 10), Pair(4, 62), Pair(1, 73), Pair(6, 52), Pair(0, 62), Pair(21, 47),
        Pair(-8, 56), Pair(-9, 59), Pair(-10, 56), Pair(7, 51), Pair(7, 52), Pair(1, 65), Pair(6, 52), Pair(13, 49),
        Pair(0, 54), Pair(14, 53), Pair(10, 48), Pair(7, 47), Pair(-1, 42), Pair(9, 39), Pair(5, 53), Pair(4, 34),
        Pair(6, 80), Pair(14, 66), Pair(6, 54), Pair(3, 55), Pair(3, 48), Pair(-6, 44), Pair(7, 58), Pair(12, 50)
      },
      { // Piece 3
        Pair(3, 85), Pair(21, 90), Pair(-10, 104), Pair(5, 99), Pair(21, 84), Pair(-8, 107), Pair(-3, 89), Pair(40, 75),
        Pair(3, 97), Pair(47, 97), Pair(13, 100), Pair(7, 96), Pair(7, 88), Pair(22, 95), Pair(16, 91), Pair(11, 87),
        Pair(-4, 90), Pair(-5, 107), Pair(15, 80), Pair(1, 88), Pair(17, 86), Pair(23, 81), Pair(23, 73), Pair(19, 70),
        Pair(-2, 68), Pair(0, 0), Pair(7, 93), Pair(-10, 97), Pair(-11, 101), Pair(13, 82), Pair(19, 85), Pair(20, 73),
        Pair(0, 8), Pair(-12, 88), Pair(11, 34), Pair(-17, 84), Pair(-16, 77), Pair(0, 73), Pair(8, 75), Pair(22, 73),
        Pair(-21, 75), Pair(-20, 83), Pair(-18, 74), Pair(-2, 81), Pair(0, 75), Pair(3, 79), Pair(16, 72), Pair(23, 61),
        Pair(-4, 67), Pair(-16, 67), Pair(-8, 78), Pair(-1, 72), Pair(3, 80), Pair(5, 68), Pair(6, 81), Pair(13, 75),
        Pair(-8, 78), Pair(-3, 74), Pair(-8, 76), Pair(-2, 81), Pair(0, 77), Pair(-1, 78), Pair(4, 81), Pair(5, 76)
      },
      { // Piece 4
        Pair(14, 137), Pair(37, 125), Pair(21, 152), Pair(49, 137), Pair(38, 152), Pair(118, 59), Pair(19, 124), Pair(48, 165),
        Pair(30, 140), Pair(45, 136), Pair(34, 141), Pair(37, 148), Pair(25, 150), Pair(46, 140), Pair(26, 145), Pair(73, 94),
        Pair(31, 100), Pair(21, 152), Pair(33, 132), Pair(34, 148), Pair(36, 149), Pair(61, 119), Pair(49, 119), Pair(56, 120),
        Pair(33, 98), Pair(0, 0), Pair(34, 136), Pair(33, 127), Pair(21, 158), Pair(50, 140), Pair(44, 126), Pair(44, 124),
        Pair(46, -4), Pair(17, 135), Pair(35, 92), Pair(22, 117), Pair(31, 120), Pair(37, 127), Pair(38, 104), Pair(34, 124),
        Pair(9, 130), Pair(19, 121), Pair(21, 105), Pair(23, 119), Pair(26, 120), Pair(30, 122), Pair(31, 108), Pair(37, 123),
        Pair(27, 123), Pair(20, 116), Pair(23, 110), Pair(24, 106), Pair(26, 111), Pair(35, 102), Pair(35, 98), Pair(39, 89),
        Pair(23, 109), Pair(22, 99), Pair(27, 100), Pair(24, 103), Pair(23, 122), Pair(11, 120), Pair(55, 91), Pair(-7, 175)
      },
      { // Piece 5
        Pair(17, 0), Pair(77, -12), Pair(51, -50), Pair(45, -20), Pair(-27, 7), Pair(-104, -1), Pair(12, -29), Pair(28, -47),
        Pair(-8, -48), Pair(-21, -19), Pair(-37, -23), Pair(75, -29), Pair(30, -10), Pair(-49, 12), Pair(3, -14), Pair(-5, 15),
        Pair(31, -24), Pair(-1, 0), Pair(129, -8), Pair(162, -22), Pair(173, -33), Pair(100, -19), Pair(78, -18), Pair(78, -15),
        Pair(-14, -10), Pair(0, 0), Pair(92, -29), Pair(36, -11), Pair(68, -8), Pair(29, 0), Pair(33, -6), Pair(25, -6),
        Pair(-17, -2), Pair(15, -60), Pair(-23, 30), Pair(11, -14), Pair(28, -3), Pair(24, -3), Pair(40, -5), Pair(35, -4),
        Pair(-18, -16), Pair(4, -24), Pair(8, -6), Pair(-17, -1), Pair(19, -1), Pair(21, -7), Pair(20, -6), Pair(28, -16),
        Pair(-34, 16), Pair(-6, -7), Pair(7, -5), Pair(2, 1), Pair(11, -1), Pair(12, -6), Pair(10, -7), Pair(13, -13),
        Pair(-1, 15), Pair(2, -4), Pair(8, 5), Pair(9, 7), Pair(12, -3), Pair(23, -12), Pair(14, -11), Pair(14, -13)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 24), Pair(1, 8), Pair(0, 4), Pair(-7, 14), Pair(9, 8), Pair(18, 12), Pair(23, 10), Pair(14, 7),
        Pair(-1, 4), Pair(-6, 7), Pair(-6, 12), Pair(0, 9), Pair(4, 10), Pair(2, 13), Pair(1, 14), Pair(-8, 17),
        Pair(2, 3), Pair(4, -2), Pair(0, 0), Pair(2, 0), Pair(-3, 5), Pair(3, 5), Pair(-1, 6), Pair(-2, 7),
        Pair(2, 2), Pair(-4, -9), Pair(0, 0), Pair(-6, 5), Pair(-3, 1), Pair(-4, 4), Pair(-5, 4), Pair(0, 5),
        Pair(3, -1), Pair(1, -7), Pair(3, 3), Pair(-3, 1), Pair(-1, 1), Pair(-7, 0), Pair(-6, 1), Pair(-2, -1),
        Pair(3, 0), Pair(0, -9), Pair(7, 9), Pair(-8, -3), Pair(-1, 1), Pair(-7, -3), Pair(-2, -1), Pair(1, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-51, 31), Pair(41, -15), Pair(24, 43), Pair(11, 50), Pair(14, 45), Pair(-25, 78), Pair(0, 61), Pair(25, 38),
        Pair(3, 50), Pair(-13, 49), Pair(11, 53), Pair(0, 63), Pair(33, 38), Pair(2, 54), Pair(-20, 30), Pair(33, 28),
        Pair(-21, 11), Pair(-5, 58), Pair(-16, 47), Pair(4, 58), Pair(-5, 49), Pair(22, 50), Pair(11, 47), Pair(4, 51),
        Pair(-11, 56), Pair(-5, 52), Pair(0, 0), Pair(-1, 60), Pair(1, 60), Pair(2, 52), Pair(5, 55), Pair(18, 32),
        Pair(-9, 45), Pair(-43, 9), Pair(6, 93), Pair(-62, 19), Pair(1, 51), Pair(-5, 49), Pair(4, 59), Pair(10, 43),
        Pair(-6, 52), Pair(-23, 24), Pair(1, 49), Pair(-16, 39), Pair(-8, 52), Pair(-10, 43), Pair(2, 46), Pair(3, 47),
        Pair(-19, 26), Pair(-19, 58), Pair(-18, 18), Pair(-7, 57), Pair(-8, 34), Pair(8, 45), Pair(6, 42), Pair(2, 41),
        Pair(-1, 30), Pair(0, 50), Pair(-5, 34), Pair(2, 48), Pair(-10, 47), Pair(0, 46), Pair(-2, 59), Pair(9, 38)
      },
      { // Piece 2
        Pair(-33, 70), Pair(3, 58), Pair(-33, 71), Pair(-16, 72), Pair(-23, 81), Pair(-35, 45), Pair(-17, 80), Pair(6, 61),
        Pair(-61, 63), Pair(-6, 58), Pair(8, 50), Pair(-55, 71), Pair(-11, 67), Pair(-5, 73), Pair(-17, 55), Pair(12, 55),
        Pair(-10, 61), Pair(-55, 54), Pair(-34, 56), Pair(-17, 57), Pair(-7, 64), Pair(-3, 68), Pair(-2, 57), Pair(1, 48),
        Pair(-22, 59), Pair(-12, 67), Pair(0, 0), Pair(-6, 63), Pair(-8, 59), Pair(-16, 63), Pair(-11, 51), Pair(-7, 51),
        Pair(-9, 47), Pair(-59, -30), Pair(0, 95), Pair(-76, -11), Pair(-9, 54), Pair(-9, 49), Pair(-5, 41), Pair(-6, 47),
        Pair(-23, -7), Pair(-22, 41), Pair(-13, 41), Pair(-10, 47), Pair(-16, 29), Pair(-8, 50), Pair(-4, 41), Pair(-7, 54),
        Pair(-30, 65), Pair(-11, 30), Pair(-7, 53), Pair(-11, 41), Pair(-9, 45), Pair(-24, 37), Pair(-3, 39), Pair(5, 36),
        Pair(-16, 39), Pair(0, 51), Pair(-7, 34), Pair(-7, 47), Pair(-11, 43), Pair(-4, 39), Pair(-24, 23), Pair(-8, 53)
      },
      { // Piece 3
        Pair(5, 68), Pair(9, 64), Pair(-40, 85), Pair(13, 61), Pair(-18, 77), Pair(-4, 70), Pair(26, 60), Pair(16, 74),
        Pair(-11, 86), Pair(-7, 83), Pair(-17, 89), Pair(-7, 76), Pair(-4, 75), Pair(32, 57), Pair(7, 64), Pair(22, 54),
        Pair(-11, 70), Pair(-15, 74), Pair(-17, 81), Pair(4, 63), Pair(9, 71), Pair(26, 57), Pair(-1, 62), Pair(27, 62),
        Pair(-25, 73), Pair(-23, 62), Pair(0, 0), Pair(-7, 71), Pair(-7, 69), Pair(0, 62), Pair(2, 58), Pair(2, 65),
        Pair(-15, 70), Pair(-3, -5), Pair(-24, 69), Pair(-10, -8), Pair(-17, 63), Pair(-9, 55), Pair(-4, 67), Pair(-1, 61),
        Pair(-17, 57), Pair(-15, 59), Pair(-31, 59), Pair(-6, 51), Pair(-15, 59), Pair(-4, 56), Pair(6, 46), Pair(9, 42),
        Pair(-4, 52), Pair(-19, 56), Pair(-26, 48), Pair(-11, 52), Pair(-10, 60), Pair(-2, 51), Pair(3, 55), Pair(2, 57),
        Pair(-15, 63), Pair(-14, 61), Pair(-18, 54), Pair(-14, 56), Pair(-14, 57), Pair(-10, 62), Pair(-4, 68), Pair(-3, 58)
      },
      { // Piece 4
        Pair(25, 104), Pair(34, 87), Pair(54, 88), Pair(9, 121), Pair(77, 59), Pair(72, 74), Pair(28, 105), Pair(43, 91),
        Pair(25, 84), Pair(19, 112), Pair(20, 123), Pair(22, 103), Pair(35, 126), Pair(47, 138), Pair(-3, 124), Pair(29, 115),
        Pair(16, 98), Pair(20, 84), Pair(22, 116), Pair(45, 97), Pair(34, 108), Pair(20, 133), Pair(27, 107), Pair(32, 121),
        Pair(10, 99), Pair(13, 99), Pair(0, 0), Pair(29, 106), Pair(25, 117), Pair(23, 122), Pair(33, 104), Pair(33, 113),
        Pair(15, 88), Pair(24, 41), Pair(25, 87), Pair(28, 21), Pair(20, 101), Pair(28, 97), Pair(20, 111), Pair(25, 97),
        Pair(7, 79), Pair(7, 94), Pair(25, 82), Pair(13, 87), Pair(15, 99), Pair(12, 99), Pair(19, 104), Pair(28, 124),
        Pair(13, 90), Pair(11, 81), Pair(17, 90), Pair(16, 84), Pair(15, 97), Pair(21, 82), Pair(8, 117), Pair(28, 99),
        Pair(11, 94), Pair(15, 101), Pair(18, 76), Pair(18, 83), Pair(12, 101), Pair(29, 68), Pair(22, 41), Pair(23, 93)
      },
      { // Piece 5
        Pair(-7, -125), Pair(10, -67), Pair(78, -39), Pair(10, -34), Pair(25, -3), Pair(54, -37), Pair(24, -13), Pair(13, -65),
        Pair(-14, -2), Pair(-12, 8), Pair(-169, 12), Pair(-75, -14), Pair(42, -37), Pair(-4, -14), Pair(45, -10), Pair(-18, -10),
        Pair(44, -35), Pair(81, -13), Pair(-40, 12), Pair(131, -22), Pair(32, -7), Pair(9, 4), Pair(-41, 6), Pair(-27, 4),
        Pair(-168, 29), Pair(64, -45), Pair(0, 0), Pair(37, -31), Pair(66, -7), Pair(60, -1), Pair(44, -3), Pair(34, -6),
        Pair(-26, 21), Pair(-77, -36), Pair(-21, -46), Pair(-57, -66), Pair(5, 1), Pair(23, 5), Pair(3, 4), Pair(4, -2),
        Pair(-74, 31), Pair(0, -14), Pair(15, -22), Pair(22, -21), Pair(-21, 2), Pair(3, 8), Pair(5, 0), Pair(22, 3),
        Pair(-29, 17), Pair(-11, 0), Pair(-3, -7), Pair(-5, -2), Pair(-5, 14), Pair(12, 5), Pair(5, 4), Pair(6, 2),
        Pair(-20, 27), Pair(-13, -6), Pair(-6, 4), Pair(9, 5), Pair(2, 19), Pair(12, 6), Pair(4, 4), Pair(2, 3)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(3, 12), Pair(6, 8), Pair(-4, 9), Pair(23, 5), Pair(-10, 12), Pair(5, 15), Pair(3, 16), Pair(10, 15),
        Pair(-6, 12), Pair(-1, 5), Pair(-1, 1), Pair(-4, 5), Pair(8, 4), Pair(3, 5), Pair(0, 15), Pair(-4, 9),
        Pair(-3, 3), Pair(5, 1), Pair(-3, 3), Pair(0, 0), Pair(2, 2), Pair(1, 0), Pair(4, 6), Pair(4, 6),
        Pair(2, 0), Pair(2, -4), Pair(7, -5), Pair(0, 0), Pair(-3, -3), Pair(-3, 1), Pair(6, 1), Pair(1, 2),
        Pair(2, -1), Pair(2, -3), Pair(2, -3), Pair(1, 3), Pair(-1, 1), Pair(-3, 0), Pair(0, 0), Pair(0, -2),
        Pair(4, -1), Pair(3, -1), Pair(-1, -5), Pair(3, 7), Pair(-4, 1), Pair(-4, 0), Pair(2, -2), Pair(3, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-78, 31), Pair(-11, 66), Pair(-25, 52), Pair(-23, 59), Pair(-31, 46), Pair(16, 37), Pair(-49, 42), Pair(7, 56),
        Pair(-5, 52), Pair(-11, 44), Pair(6, 43), Pair(-3, 41), Pair(7, 55), Pair(11, 56), Pair(-1, 44), Pair(1, 51),
        Pair(-8, 55), Pair(-17, 16), Pair(-18, 61), Pair(-24, 54), Pair(5, 53), Pair(-3, 35), Pair(6, 46), Pair(18, 37),
        Pair(-8, 42), Pair(-6, 43), Pair(-1, 49), Pair(0, 0), Pair(-8, 54), Pair(-1, 62), Pair(-3, 41), Pair(-11, 56),
        Pair(-5, 41), Pair(7, 40), Pair(-31, -22), Pair(13, 88), Pair(-69, 28), Pair(-6, 47), Pair(6, 45), Pair(1, 50),
        Pair(-7, 1), Pair(-11, 48), Pair(-8, 18), Pair(0, 45), Pair(-10, 31), Pair(0, 51), Pair(-9, 36), Pair(0, 46),
        Pair(3, 41), Pair(-31, 30), Pair(-6, 42), Pair(-16, 14), Pair(0, 48), Pair(-6, 25), Pair(-1, 56), Pair(0, 60),
        Pair(14, 58), Pair(1, 26), Pair(16, 42), Pair(-10, 35), Pair(-1, 57), Pair(-4, 42), Pair(8, 55), Pair(-3, 48)
      },
      { // Piece 2
        Pair(-73, 23), Pair(-57, 61), Pair(-60, 75), Pair(-32, 56), Pair(-37, 62), Pair(-71, 73), Pair(-121, 73), Pair(-35, 63),
        Pair(11, 53), Pair(-30, 36), Pair(-12, 41), Pair(-39, 67), Pair(-16, 55), Pair(1, 41), Pair(-3, 54), Pair(-13, 44),
        Pair(-22, 41), Pair(-11, 47), Pair(-63, 38), Pair(-8, 57), Pair(-25, 53), Pair(-38, 71), Pair(-30, 61), Pair(10, 38),
        Pair(-11, 51), Pair(-22, 42), Pair(-4, 56), Pair(0, 0), Pair(-5, 60), Pair(-12, 54), Pair(-2, 47), Pair(-19, 45),
        Pair(-15, 36), Pair(-7, 43), Pair(-45, -11), Pair(10, 83), Pair(-69, -103), Pair(-4, 43), Pair(-19, 45), Pair(-2, 28),
        Pair(-2, 43), Pair(-31, 11), Pair(-11, 32), Pair(-11, 36), Pair(-4, 31), Pair(-19, 17), Pair(-6, 43), Pair(-8, 40),
        Pair(-34, 2), Pair(-5, 27), Pair(-12, 30), Pair(-1, 35), Pair(-16, 26), Pair(-9, 39), Pair(-18, 5), Pair(-7, 37),
        Pair(-16, 35), Pair(-3, 40), Pair(-1, 40), Pair(-14, 23), Pair(0, 32), Pair(-10, 20), Pair(-14, 38), Pair(-31, 7)
      },
      { // Piece 3
        Pair(12, 54), Pair(-4, 56), Pair(-5, 58), Pair(12, 58), Pair(3, 54), Pair(15, 60), Pair(-15, 56), Pair(2, 59),
        Pair(5, 59), Pair(-9, 64), Pair(-17, 75), Pair(-33, 84), Pair(-13, 73), Pair(17, 57), Pair(-15, 66), Pair(-3, 60),
        Pair(-6, 58), Pair(-8, 62), Pair(-3, 62), Pair(9, 60), Pair(4, 60), Pair(17, 53), Pair(-5, 57), Pair(-4, 55),
        Pair(-10, 57), Pair(-15, 62), Pair(-2, 50), Pair(0, 0), Pair(0, 53), Pair(-15, 67), Pair(4, 45), Pair(7, 42),
        Pair(-6, 51), Pair(-11, 47), Pair(2, -38), Pair(-11, 52), Pair(10, 2), Pair(-12, 48), Pair(-3, 42), Pair(4, 48),
        Pair(-10, 54), Pair(-9, 50), Pair(-17, 44), Pair(-20, 45), Pair(-17, 43), Pair(2, 47), Pair(-4, 54), Pair(14, 44),
        Pair(1, 40), Pair(-6, 53), Pair(-7, 43), Pair(-17, 42), Pair(-10, 51), Pair(-6, 43), Pair(-12, 54), Pair(9, 42),
        Pair(-6, 54), Pair(-5, 50), Pair(-11, 49), Pair(-17, 46), Pair(-12, 45), Pair(-8, 53), Pair(-2, 47), Pair(10, 42)
      },
      { // Piece 4
        Pair(5, 68), Pair(34, 85), Pair(7, 106), Pair(26, 91), Pair(6, 109), Pair(-16, 167), Pair(35, 106), Pair(12, 126),
        Pair(14, 110), Pair(15, 87), Pair(22, 105), Pair(26, 83), Pair(11, 131), Pair(-16, 166), Pair(16, 125), Pair(-4, 126),
        Pair(20, 94), Pair(9, 101), Pair(6, 70), Pair(15, 98), Pair(21, 107), Pair(22, 138), Pair(-5, 141), Pair(24, 122),
        Pair(8, 104), Pair(13, 87), Pair(-3, 104), Pair(0, 0), Pair(21, 91), Pair(8, 106), Pair(21, 104), Pair(11, 109),
        Pair(10, 90), Pair(11, 96), Pair(26, -41), Pair(33, 81), Pair(35, -15), Pair(24, 100), Pair(13, 102), Pair(12, 111),
        Pair(15, 101), Pair(12, 83), Pair(15, 86), Pair(16, 89), Pair(5, 91), Pair(12, 77), Pair(17, 86), Pair(16, 90),
        Pair(11, 89), Pair(10, 93), Pair(11, 74), Pair(18, 91), Pair(9, 81), Pair(15, 83), Pair(14, 65), Pair(34, 63),
        Pair(12, 77), Pair(16, 67), Pair(13, 82), Pair(19, 82), Pair(16, 85), Pair(18, 65), Pair(24, 62), Pair(5, 97)
      },
      { // Piece 5
        Pair(58, 119), Pair(-39, -36), Pair(-71, -38), Pair(-5, -42), Pair(40, 19), Pair(57, -61), Pair(14, -8), Pair(125, 4),
        Pair(23, 25), Pair(-45, 10), Pair(39, -4), Pair(60, -51), Pair(-33, -20), Pair(0, -20), Pair(41, -13), Pair(17, -18),
        Pair(22, 36), Pair(-14, 10), Pair(66, -22), Pair(90, -32), Pair(28, -12), Pair(101, -21), Pair(2, 11), Pair(43, -10),
        Pair(58, -8), Pair(62, -4), Pair(15, -47), Pair(0, 0), Pair(94, -52), Pair(2, 3), Pair(25, 10), Pair(0, 8),
        Pair(24, 18), Pair(-25, 9), Pair(-43, -7), Pair(-29, -54), Pair(17, 3), Pair(22, 1), Pair(12, 5), Pair(26, 8),
        Pair(-19, 21), Pair(-23, 11), Pair(42, -20), Pair(35, -38), Pair(35, -24), Pair(-16, 8), Pair(9, 6), Pair(30, -2),
        Pair(-7, 19), Pair(-19, 23), Pair(-13, 1), Pair(0, -4), Pair(-4, -1), Pair(-7, 18), Pair(-1, 12), Pair(5, 11),
        Pair(-1, 18), Pair(-11, 21), Pair(-13, 0), Pair(4, -5), Pair(-8, -4), Pair(0, 18), Pair(-2, 15), Pair(7, 8)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 19), Pair(26, 9), Pair(5, 13), Pair(-7, 9), Pair(16, 16), Pair(16, 13), Pair(-7, 19), Pair(3, 16),
        Pair(2, 5), Pair(1, 4), Pair(0, 5), Pair(0, 4), Pair(-7, 12), Pair(-2, 4), Pair(-2, 14), Pair(-3, 12),
        Pair(-1, 3), Pair(0, -1), Pair(1, 0), Pair(5, -3), Pair(0, 0), Pair(-2, 7), Pair(8, 5), Pair(-1, 9),
        Pair(3, -4), Pair(3, -5), Pair(3, -5), Pair(3, 7), Pair(0, 0), Pair(-3, -6), Pair(2, 1), Pair(0, 4),
        Pair(1, -2), Pair(4, -4), Pair(-3, -1), Pair(0, -2), Pair(1, 3), Pair(-5, -3), Pair(-2, 1), Pair(0, 0),
        Pair(5, 1), Pair(5, -7), Pair(2, 0), Pair(-2, -1), Pair(5, 7), Pair(-5, -3), Pair(4, 5), Pair(0, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-34, 49), Pair(-121, 68), Pair(10, 39), Pair(56, 18), Pair(-21, 47), Pair(-23, 43), Pair(-97, 73), Pair(-35, 39),
        Pair(-14, 43), Pair(-13, 50), Pair(3, 46), Pair(28, 32), Pair(-30, 70), Pair(-53, 67), Pair(29, 33), Pair(-14, 65),
        Pair(-11, 39), Pair(4, 39), Pair(-2, 19), Pair(-9, 58), Pair(-8, 37), Pair(-21, 58), Pair(-19, 21), Pair(19, 41),
        Pair(-3, 38), Pair(-10, 28), Pair(2, 52), Pair(-6, 41), Pair(0, 0), Pair(-8, 47), Pair(-3, 43), Pair(-25, 29),
        Pair(1, 44), Pair(-10, 36), Pair(-1, 38), Pair(-49, -10), Pair(11, 77), Pair(-19, -5), Pair(5, 37), Pair(-1, 21),
        Pair(4, 36), Pair(-10, 29), Pair(-6, 44), Pair(-18, 40), Pair(-2, 48), Pair(-10, 18), Pair(-6, 36), Pair(-14, 7),
        Pair(-6, 51), Pair(-2, 41), Pair(-10, 24), Pair(-3, 38), Pair(-20, 9), Pair(-2, 44), Pair(-16, 18), Pair(-2, 37),
        Pair(-32, 44), Pair(10, 50), Pair(1, 37), Pair(14, 44), Pair(-7, 27), Pair(-6, 44), Pair(-3, 23), Pair(31, 20)
      },
      { // Piece 2
        Pair(-22, 71), Pair(-23, 29), Pair(-59, 64), Pair(-42, 52), Pair(-85, 64), Pair(-71, 58), Pair(50, 35), Pair(-25, 3),
        Pair(-16, 34), Pair(-13, 54), Pair(-22, 45), Pair(-55, 51), Pair(-24, 63), Pair(-12, 53), Pair(41, 1), Pair(21, 61),
        Pair(-4, 46), Pair(-26, 55), Pair(-15, 49), Pair(-36, 44), Pair(-6, 45), Pair(-62, 28), Pair(-19, 60), Pair(-8, 35),
        Pair(-20, 41), Pair(-14, 47), Pair(-12, 45), Pair(-4, 46), Pair(0, 0), Pair(-12, 64), Pair(-12, 47), Pair(4, 41),
        Pair(-12, 46), Pair(-10, 41), Pair(-10, 45), Pair(-57, -45), Pair(7, 77), Pair(-18, -7), Pair(-2, 42), Pair(-17, 30),
        Pair(-4, 31), Pair(-6, 40), Pair(-18, 20), Pair(-11, 31), Pair(-13, 31), Pair(-7, 31), Pair(-23, 0), Pair(-4, 33),
        Pair(-9, 51), Pair(-13, 9), Pair(-10, 42), Pair(-6, 29), Pair(-1, 32), Pair(-15, 28), Pair(-7, 23), Pair(-27, -24),
        Pair(-32, 5), Pair(-7, 32), Pair(-6, 25), Pair(-8, 44), Pair(-15, 31), Pair(-1, 41), Pair(-7, 36), Pair(-6, 43)
      },
      { // Piece 3
        Pair(1, 47), Pair(17, 55), Pair(-11, 62), Pair(-7, 57), Pair(-3, 54), Pair(-16, 51), Pair(-41, 66), Pair(-26, 67),
        Pair(-5, 54), Pair(-3, 60), Pair(0, 58), Pair(-3, 61), Pair(-6, 66), Pair(9, 48), Pair(1, 58), Pair(-7, 54),
        Pair(6, 46), Pair(3, 49), Pair(13, 49), Pair(-3, 49), Pair(18, 54), Pair(20, 37), Pair(8, 43), Pair(-10, 49),
        Pair(2, 46), Pair(-3, 51), Pair(-11, 52), Pair(8, 40), Pair(0, 0), Pair(-2, 43), Pair(-7, 59), Pair(-3, 35),
        Pair(1, 56), Pair(-1, 43), Pair(-11, 48), Pair(-5, -5), Pair(-2, 31), Pair(0, -16), Pair(-9, 39), Pair(3, 36),
        Pair(4, 47), Pair(5, 36), Pair(-4, 42), Pair(-15, 41), Pair(-18, 37), Pair(-2, 40), Pair(3, 36), Pair(12, 40),
        Pair(16, 33), Pair(-3, 41), Pair(2, 40), Pair(-4, 32), Pair(-13, 35), Pair(2, 40), Pair(6, 42), Pair(17, 26),
        Pair(1, 45), Pair(1, 44), Pair(0, 43), Pair(-9, 40), Pair(-7, 39), Pair(-1, 37), Pair(9, 35), Pair(0, 49)
      },
      { // Piece 4
        Pair(0, 122), Pair(-17, 97), Pair(-15, 141), Pair(12, 117), Pair(-24, 118), Pair(-33, 143), Pair(35, 98), Pair(10, 86),
        Pair(27, 84), Pair(10, 104), Pair(-3, 126), Pair(6, 119), Pair(14, 97), Pair(-7, 152), Pair(5, 100), Pair(7, 116),
        Pair(16, 93), Pair(19, 88), Pair(13, 115), Pair(16, 77), Pair(19, 96), Pair(27, 95), Pair(4, 118), Pair(26, 111),
        Pair(17, 78), Pair(18, 113), Pair(13, 79), Pair(17, 80), Pair(0, 0), Pair(6, 120), Pair(11, 98), Pair(20, 95),
        Pair(12, 79), Pair(8, 92), Pair(20, 72), Pair(26, 37), Pair(26, 85), Pair(45, -8), Pair(13, 100), Pair(4, 93),
        Pair(23, 99), Pair(12, 95), Pair(8, 97), Pair(9, 93), Pair(10, 85), Pair(20, 67), Pair(7, 64), Pair(25, 86),
        Pair(15, 75), Pair(13, 76), Pair(15, 84), Pair(9, 76), Pair(23, 78), Pair(16, 72), Pair(8, 79), Pair(16, 65),
        Pair(2, 91), Pair(11, 90), Pair(12, 75), Pair(17, 78), Pair(20, 74), Pair(24, 88), Pair(5, 71), Pair(19, 90)
      },
      { // Piece 5
        Pair(-118, -40), Pair(-50, 12), Pair(-22, -12), Pair(-46, 33), Pair(38, -8), Pair(4, 22), Pair(17, -32), Pair(6, -39),
        Pair(-12, 16), Pair(-1, 2), Pair(48, -7), Pair(48, -38), Pair(40, -48), Pair(5, -14), Pair(15, -12), Pair(123, -37),
        Pair(-8, 10), Pair(9, 10), Pair(0, 8), Pair(103, -2), Pair(87, -17), Pair(169, -34), Pair(57, -3), Pair(42, 2),
        Pair(38, -3), Pair(41, 5), Pair(-27, 3), Pair(99, -58), Pair(0, 0), Pair(96, -51), Pair(63, -11), Pair(33, 4),
        Pair(-4, 14), Pair(-37, 23), Pair(16, 9), Pair(76, -67), Pair(9, -47), Pair(10, -47), Pair(19, 3), Pair(35, 10),
        Pair(-2, 12), Pair(32, 1), Pair(-1, 1), Pair(71, -24), Pair(48, -24), Pair(54, -22), Pair(-6, 14), Pair(11, 14),
        Pair(23, 13), Pair(-2, 18), Pair(6, 19), Pair(27, -7), Pair(12, -6), Pair(13, 0), Pair(-7, 25), Pair(7, 21),
        Pair(5, 11), Pair(-3, 17), Pair(0, 22), Pair(21, 1), Pair(-2, 16), Pair(16, 2), Pair(-4, 26), Pair(8, 23)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, 11), Pair(16, 10), Pair(24, 3), Pair(23, 2), Pair(-11, 12), Pair(21, 15), Pair(-2, 6), Pair(20, 2),
        Pair(3, 5), Pair(11, 3), Pair(4, 6), Pair(3, 2), Pair(-5, -1), Pair(-7, 3), Pair(-2, 8), Pair(-2, 4),
        Pair(5, 1), Pair(4, -2), Pair(3, 2), Pair(1, -2), Pair(2, 0), Pair(0, 0), Pair(-2, 1), Pair(-1, 2),
        Pair(7, -1), Pair(3, -6), Pair(5, -2), Pair(4, -3), Pair(2, 4), Pair(0, 0), Pair(-3, -7), Pair(-1, 0),
        Pair(6, -4), Pair(6, -5), Pair(2, -4), Pair(5, -7), Pair(-1, 0), Pair(4, 1), Pair(-4, -6), Pair(0, 1),
        Pair(4, -6), Pair(5, -6), Pair(3, -3), Pair(5, 1), Pair(2, 0), Pair(5, 2), Pair(-1, -6), Pair(-1, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-20, 42), Pair(17, 26), Pair(-29, 17), Pair(-54, 54), Pair(21, 23), Pair(-23, 61), Pair(52, 10), Pair(-25, 86),
        Pair(-18, 46), Pair(1, 33), Pair(14, 29), Pair(18, 30), Pair(-9, 42), Pair(-2, 49), Pair(-28, 31), Pair(23, 32),
        Pair(-8, 24), Pair(10, 28), Pair(13, 40), Pair(11, 20), Pair(-7, 50), Pair(-8, 30), Pair(-11, 39), Pair(-19, -15),
        Pair(10, 33), Pair(9, 32), Pair(0, 32), Pair(9, 39), Pair(1, 44), Pair(0, 0), Pair(-4, 29), Pair(-5, 30),
        Pair(12, 28), Pair(1, 35), Pair(8, 28), Pair(7, 22), Pair(-54, -6), Pair(11, 67), Pair(-12, -19), Pair(1, 28),
        Pair(3, 25), Pair(-5, 39), Pair(-1, 33), Pair(0, 41), Pair(-8, 20), Pair(9, 36), Pair(-16, 7), Pair(-4, 34),
        Pair(3, 26), Pair(-2, 35), Pair(0, 38), Pair(-6, 26), Pair(3, 34), Pair(-14, 7), Pair(6, 41), Pair(-12, -3),
        Pair(0, 8), Pair(3, 26), Pair(-4, 38), Pair(-2, 24), Pair(-3, 47), Pair(0, 31), Pair(3, 43), Pair(-16, 11)
      },
      { // Piece 2
        Pair(-25, 52), Pair(2, 29), Pair(-10, 34), Pair(-9, 48), Pair(-79, 63), Pair(-88, 58), Pair(-63, 53), Pair(48, 35),
        Pair(1, 20), Pair(-8, 37), Pair(-8, 40), Pair(-44, 47), Pair(-36, 49), Pair(-7, 54), Pair(11, 36), Pair(-59, 38),
        Pair(-12, 39), Pair(-10, 47), Pair(-8, 47), Pair(6, 42), Pair(-14, 46), Pair(10, 37), Pair(-38, 27), Pair(2, 36),
        Pair(5, 33), Pair(-9, 49), Pair(8, 33), Pair(-11, 36), Pair(7, 36), Pair(0, 0), Pair(-4, 50), Pair(-17, 37),
        Pair(-1, 35), Pair(11, 34), Pair(-12, 44), Pair(0, 33), Pair(-47, -27), Pair(12, 73), Pair(-30, -53), Pair(-11, 32),
        Pair(3, 18), Pair(-3, 34), Pair(10, 27), Pair(-7, 22), Pair(-7, 21), Pair(-4, 26), Pair(-9, 26), Pair(-32, -2),
        Pair(0, 16), Pair(7, 37), Pair(-17, 25), Pair(6, 28), Pair(-6, 23), Pair(-1, 35), Pair(-17, 21), Pair(-2, 20),
        Pair(13, 34), Pair(-34, 17), Pair(6, 24), Pair(-2, 24), Pair(8, 30), Pair(-4, 32), Pair(-27, 41), Pair(-26, 43)
      },
      { // Piece 3
        Pair(24, 38), Pair(7, 45), Pair(-10, 53), Pair(3, 44), Pair(35, 32), Pair(-5, 50), Pair(9, 39), Pair(6, 49),
        Pair(19, 32), Pair(14, 38), Pair(27, 32), Pair(16, 44), Pair(9, 45), Pair(29, 49), Pair(36, 31), Pair(16, 39),
        Pair(17, 31), Pair(17, 36), Pair(14, 37), Pair(26, 38), Pair(13, 31), Pair(51, 27), Pair(33, 19), Pair(11, 41),
        Pair(14, 30), Pair(17, 32), Pair(15, 35), Pair(14, 38), Pair(16, 34), Pair(0, 0), Pair(11, 24), Pair(1, 35),
        Pair(10, 33), Pair(11, 32), Pair(2, 33), Pair(-13, 40), Pair(9, -33), Pair(4, 36), Pair(8, -41), Pair(-6, 33),
        Pair(15, 30), Pair(6, 33), Pair(7, 35), Pair(5, 28), Pair(8, 27), Pair(3, 23), Pair(-8, 40), Pair(3, 39),
        Pair(-3, 37), Pair(3, 31), Pair(11, 31), Pair(7, 28), Pair(5, 21), Pair(5, 25), Pair(18, 23), Pair(7, 26),
        Pair(9, 36), Pair(11, 33), Pair(12, 32), Pair(7, 35), Pair(8, 29), Pair(7, 31), Pair(9, 27), Pair(5, 40)
      },
      { // Piece 4
        Pair(40, 43), Pair(21, 64), Pair(50, 39), Pair(13, 90), Pair(32, 67), Pair(8, 53), Pair(72, 58), Pair(42, 59),
        Pair(24, 76), Pair(4, 86), Pair(13, 84), Pair(29, 69), Pair(20, 95), Pair(27, 71), Pair(-5, 105), Pair(-3, 98),
        Pair(27, 62), Pair(19, 72), Pair(14, 60), Pair(23, 74), Pair(18, 64), Pair(38, 63), Pair(0, 44), Pair(24, 55),
        Pair(24, 74), Pair(20, 61), Pair(20, 66), Pair(15, 80), Pair(10, 75), Pair(0, 0), Pair(8, 87), Pair(17, 29),
        Pair(16, 57), Pair(7, 73), Pair(1, 82), Pair(6, 78), Pair(-3, 35), Pair(28, 38), Pair(19, 5), Pair(8, 64),
        Pair(18, 69), Pair(9, 67), Pair(20, 64), Pair(10, 63), Pair(8, 49), Pair(20, 41), Pair(15, 58), Pair(14, 9),
        Pair(12, 75), Pair(8, 82), Pair(16, 48), Pair(12, 58), Pair(14, 51), Pair(15, 31), Pair(13, 41), Pair(10, 54),
        Pair(22, 46), Pair(12, 32), Pair(21, 47), Pair(16, 50), Pair(21, 56), Pair(20, 37), Pair(0, 55), Pair(17, 73)
      },
      { // Piece 5
        Pair(111, -15), Pair(-9, -75), Pair(-84, -2), Pair(23, -37), Pair(-11, -9), Pair(45, -70), Pair(-118, -25), Pair(-77, -15),
        Pair(-80, -9), Pair(-11, -3), Pair(35, -14), Pair(-86, -19), Pair(71, -35), Pair(-44, -8), Pair(20, -19), Pair(-83, -8),
        Pair(11, -8), Pair(112, -26), Pair(-54, 6), Pair(72, -15), Pair(-3, -3), Pair(173, -23), Pair(14, 10), Pair(16, -2),
        Pair(-51, 11), Pair(-9, 6), Pair(75, -7), Pair(-11, -1), Pair(58, -35), Pair(0, 0), Pair(89, -45), Pair(-1, 3),
        Pair(56, -19), Pair(59, -6), Pair(74, -6), Pair(21, 3), Pair(29, -56), Pair(-17, -39), Pair(-72, -54), Pair(-27, 17),
        Pair(65, -8), Pair(32, -12), Pair(14, 0), Pair(27, -4), Pair(66, -21), Pair(32, -12), Pair(14, -7), Pair(-39, 18),
        Pair(2, -6), Pair(20, -3), Pair(26, -3), Pair(14, 8), Pair(7, -3), Pair(4, 0), Pair(0, 6), Pair(-2, 17),
        Pair(5, 0), Pair(-5, 12), Pair(-3, 16), Pair(12, 10), Pair(-6, 8), Pair(4, 9), Pair(-4, 6), Pair(-2, 21)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(22, 7), Pair(9, 10), Pair(20, 12), Pair(13, 6), Pair(-16, 20), Pair(3, 6), Pair(3, 26), Pair(-4, 21),
        Pair(9, 1), Pair(8, 5), Pair(9, 2), Pair(6, 6), Pair(1, 3), Pair(-13, 6), Pair(15, -3), Pair(-2, 9),
        Pair(6, 3), Pair(4, -2), Pair(-3, 2), Pair(-1, 3), Pair(-3, 4), Pair(0, 5), Pair(0, 0), Pair(3, 9),
        Pair(3, -2), Pair(5, -2), Pair(3, 0), Pair(-5, 0), Pair(-4, -1), Pair(2, 7), Pair(0, 0), Pair(4, 6),
        Pair(2, -3), Pair(4, -6), Pair(3, -5), Pair(-1, -1), Pair(0, 2), Pair(-1, 5), Pair(-7, 6), Pair(1, 2),
        Pair(0, -7), Pair(5, -7), Pair(1, -4), Pair(6, -5), Pair(1, 3), Pair(6, -1), Pair(2, 2), Pair(0, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-4, -2), Pair(-62, 24), Pair(-92, 58), Pair(-84, 62), Pair(17, 23), Pair(-66, 51), Pair(12, 44), Pair(-12, -20),
        Pair(17, 15), Pair(2, 31), Pair(30, 30), Pair(3, 44), Pair(20, 25), Pair(20, 18), Pair(-30, 61), Pair(-19, 20),
        Pair(10, 11), Pair(4, 24), Pair(31, 28), Pair(34, 21), Pair(27, 21), Pair(30, 41), Pair(-8, 3), Pair(32, 22),
        Pair(14, 28), Pair(18, 20), Pair(20, 27), Pair(16, 24), Pair(22, 31), Pair(17, 33), Pair(0, 0), Pair(-17, 26),
        Pair(2, 22), Pair(5, 30), Pair(16, 25), Pair(21, 23), Pair(15, 17), Pair(-20, -17), Pair(27, 64), Pair(-32, -12),
        Pair(6, 20), Pair(7, 20), Pair(7, 16), Pair(-5, 37), Pair(12, 30), Pair(5, 13), Pair(11, 37), Pair(-23, -15),
        Pair(-5, 37), Pair(2, 21), Pair(2, 28), Pair(6, 28), Pair(-10, 23), Pair(15, 37), Pair(-13, -18), Pair(12, 40),
        Pair(-17, 29), Pair(-2, 45), Pair(-9, 23), Pair(-2, 21), Pair(7, 15), Pair(17, 34), Pair(-2, 22), Pair(-34, 75)
      },
      { // Piece 2
        Pair(-3, 40), Pair(-58, 52), Pair(-63, 75), Pair(-103, 74), Pair(-47, 62), Pair(-106, 60), Pair(60, 33), Pair(3, 62),
        Pair(-6, 47), Pair(6, 48), Pair(-51, 55), Pair(-33, 64), Pair(-37, 60), Pair(-54, 68), Pair(-9, 55), Pair(14, 40),
        Pair(4, 38), Pair(-11, 46), Pair(8, 55), Pair(-20, 52), Pair(-7, 56), Pair(-4, 44), Pair(-6, 48), Pair(-70, 25),
        Pair(-3, 39), Pair(12, 36), Pair(-17, 51), Pair(7, 42), Pair(5, 41), Pair(-2, 53), Pair(0, 0), Pair(-3, 40),
        Pair(2, 33), Pair(-1, 40), Pair(8, 37), Pair(11, 38), Pair(-2, 43), Pair(-37, -7), Pair(14, 77), Pair(-46, -54),
        Pair(-8, 34), Pair(15, 35), Pair(5, 33), Pair(7, 33), Pair(-8, 26), Pair(2, 30), Pair(-8, 29), Pair(1, 15),
        Pair(12, 48), Pair(8, 30), Pair(11, 25), Pair(0, 25), Pair(3, 30), Pair(-7, 30), Pair(16, 27), Pair(-15, 19),
        Pair(15, 27), Pair(3, 30), Pair(-6, 12), Pair(-2, 35), Pair(-2, 36), Pair(5, 31), Pair(-20, 33), Pair(-11, 54)
      },
      { // Piece 3
        Pair(2, 54), Pair(13, 49), Pair(-14, 56), Pair(8, 49), Pair(2, 44), Pair(-36, 65), Pair(20, 55), Pair(-17, 60),
        Pair(36, 32), Pair(24, 35), Pair(23, 41), Pair(33, 35), Pair(19, 46), Pair(19, 37), Pair(120, 30), Pair(9, 49),
        Pair(23, 41), Pair(21, 39), Pair(32, 32), Pair(22, 39), Pair(38, 30), Pair(18, 37), Pair(33, 47), Pair(-14, 49),
        Pair(17, 39), Pair(14, 41), Pair(29, 40), Pair(7, 47), Pair(48, 35), Pair(20, 32), Pair(0, 0), Pair(-26, 45),
        Pair(5, 36), Pair(4, 42), Pair(7, 40), Pair(4, 43), Pair(16, 31), Pair(-6, -15), Pair(-13, 51), Pair(-22, 3),
        Pair(14, 39), Pair(16, 36), Pair(18, 36), Pair(12, 36), Pair(13, 34), Pair(2, 33), Pair(-8, 35), Pair(-6, 33),
        Pair(15, 37), Pair(16, 33), Pair(25, 34), Pair(19, 34), Pair(26, 34), Pair(18, 24), Pair(16, 17), Pair(7, 15),
        Pair(16, 34), Pair(14, 37), Pair(19, 35), Pair(16, 40), Pair(13, 40), Pair(13, 36), Pair(-2, 38), Pair(1, 30)
      },
      { // Piece 4
        Pair(16, 48), Pair(59, 21), Pair(7, 54), Pair(34, 35), Pair(-31, 96), Pair(26, 71), Pair(23, 73), Pair(13, 64),
        Pair(30, 36), Pair(10, 56), Pair(27, 34), Pair(7, 77), Pair(-10, 79), Pair(50, 52), Pair(-39, 122), Pair(32, 59),
        Pair(30, 26), Pair(29, 34), Pair(17, 62), Pair(26, 33), Pair(2, 79), Pair(6, 57), Pair(-6, 76), Pair(-38, 62),
        Pair(31, 12), Pair(30, 35), Pair(35, 44), Pair(13, 63), Pair(13, 82), Pair(-1, 65), Pair(0, 0), Pair(0, 52),
        Pair(17, 26), Pair(11, 59), Pair(16, 62), Pair(18, 63), Pair(9, 70), Pair(13, 24), Pair(7, 54), Pair(5, 4),
        Pair(7, 66), Pair(8, 59), Pair(19, 61), Pair(12, 54), Pair(10, 50), Pair(11, 56), Pair(11, 22), Pair(-2, 73),
        Pair(12, 38), Pair(3, 52), Pair(16, 39), Pair(10, 38), Pair(9, 51), Pair(19, 27), Pair(6, 32), Pair(0, 74),
        Pair(2, 75), Pair(15, 22), Pair(20, -1), Pair(17, 38), Pair(11, 54), Pair(5, 53), Pair(-12, 58), Pair(6, 49)
      },
      { // Piece 5
        Pair(-17, -3), Pair(-13, -46), Pair(86, -42), Pair(105, -27), Pair(47, -33), Pair(-20, -59), Pair(-47, -25), Pair(-29, -218),
        Pair(75, -32), Pair(17, -29), Pair(157, -47), Pair(140, -35), Pair(226, -60), Pair(74, -26), Pair(69, -43), Pair(50, -65),
        Pair(122, -28), Pair(45, -27), Pair(63, -20), Pair(60, -23), Pair(-2, -15), Pair(43, -16), Pair(168, -34), Pair(31, 4),
        Pair(66, -40), Pair(27, -12), Pair(52, -15), Pair(16, -6), Pair(24, -16), Pair(43, -38), Pair(0, 0), Pair(14, -41),
        Pair(90, -37), Pair(53, -27), Pair(34, -18), Pair(85, -21), Pair(-9, -13), Pair(-128, -35), Pair(-8, -60), Pair(-229, -85),
        Pair(61, -35), Pair(34, -21), Pair(28, -20), Pair(28, -13), Pair(-9, -5), Pair(48, -20), Pair(9, -23), Pair(-13, -15),
        Pair(-7, 0), Pair(-19, -10), Pair(-4, -8), Pair(30, -18), Pair(-8, -1), Pair(24, -9), Pair(-6, -4), Pair(-6, -1),
        Pair(-9, -23), Pair(-12, -12), Pair(0, -10), Pair(-5, 2), Pair(-1, -1), Pair(2, -7), Pair(-5, -3), Pair(-10, -7)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, 8), Pair(3, 10), Pair(19, 4), Pair(-3, 14), Pair(17, 7), Pair(-8, 11), Pair(-19, 14), Pair(-42, 52),
        Pair(6, 4), Pair(5, 3), Pair(11, 3), Pair(10, -1), Pair(-8, 7), Pair(-11, 4), Pair(-6, 5), Pair(15, -30),
        Pair(5, -1), Pair(3, 0), Pair(5, 0), Pair(0, -3), Pair(-5, 0), Pair(-3, 1), Pair(-7, 0), Pair(0, 0),
        Pair(5, -3), Pair(4, -6), Pair(2, -4), Pair(1, -2), Pair(1, -3), Pair(-1, -2), Pair(-4, -6), Pair(0, 0),
        Pair(4, -2), Pair(1, -5), Pair(3, -6), Pair(-2, -6), Pair(1, -3), Pair(3, 0), Pair(-4, -6), Pair(6, 0),
        Pair(4, -4), Pair(3, -6), Pair(-4, -5), Pair(-3, -8), Pair(1, -7), Pair(4, -3), Pair(1, -9), Pair(1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-15, -1), Pair(-69, 33), Pair(-15, 17), Pair(59, 11), Pair(-47, 26), Pair(-42, 47), Pair(44, 24), Pair(-43, 54),
        Pair(-9, 22), Pair(15, 12), Pair(36, 9), Pair(41, 19), Pair(47, 10), Pair(14, 30), Pair(9, 15), Pair(37, 65),
        Pair(35, 0), Pair(5, 10), Pair(14, 13), Pair(37, 12), Pair(33, 18), Pair(24, 22), Pair(-11, 19), Pair(-29, 9),
        Pair(12, 1), Pair(15, 13), Pair(19, 18), Pair(25, 17), Pair(23, 24), Pair(17, 33), Pair(2, 32), Pair(0, 0),
        Pair(8, 12), Pair(3, 16), Pair(16, 10), Pair(18, 17), Pair(22, 21), Pair(28, 21), Pair(-15, -5), Pair(24, 56),
        Pair(1, 3), Pair(-2, 19), Pair(11, 15), Pair(9, 20), Pair(7, 18), Pair(12, 24), Pair(2, 21), Pair(3, 41),
        Pair(11, -10), Pair(-9, 22), Pair(7, 12), Pair(4, 23), Pair(6, 29), Pair(-3, 25), Pair(21, 14), Pair(-9, -7),
        Pair(51, -39), Pair(-1, 13), Pair(-2, 9), Pair(12, 12), Pair(4, 20), Pair(1, 16), Pair(0, 20), Pair(18, -9)
      },
      { // Piece 2
        Pair(-10, 55), Pair(-18, 54), Pair(-55, 66), Pair(-71, 66), Pair(-80, 80), Pair(-26, 49), Pair(-22, 61), Pair(0, 45),
        Pair(-41, 47), Pair(-9, 62), Pair(-2, 45), Pair(-39, 71), Pair(-39, 61), Pair(-24, 60), Pair(-29, 41), Pair(20, 70),
        Pair(-14, 53), Pair(-14, 42), Pair(-7, 64), Pair(-6, 46), Pair(8, 50), Pair(-16, 51), Pair(-5, 64), Pair(27, 34),
        Pair(2, 27), Pair(2, 53), Pair(-8, 35), Pair(16, 43), Pair(9, 37), Pair(3, 45), Pair(-5, 37), Pair(0, 0),
        Pair(-11, 42), Pair(-2, 31), Pair(4, 42), Pair(5, 25), Pair(15, 39), Pair(5, 30), Pair(-37, -51), Pair(6, 69),
        Pair(1, 30), Pair(5, 31), Pair(5, 25), Pair(4, 38), Pair(4, 20), Pair(3, 39), Pair(-3, 29), Pair(11, 40),
        Pair(-7, 34), Pair(7, 20), Pair(2, 35), Pair(0, 26), Pair(-1, 35), Pair(3, 21), Pair(15, 34), Pair(4, 22),
        Pair(3, 34), Pair(-3, 35), Pair(-2, 23), Pair(-5, 38), Pair(7, 28), Pair(5, 37), Pair(-8, 37), Pair(-2, 59)
      },
      { // Piece 3
        Pair(2, 48), Pair(-14, 61), Pair(8, 50), Pair(-8, 54), Pair(8, 48), Pair(-9, 60), Pair(15, 53), Pair(42, 58),
        Pair(21, 44), Pair(24, 44), Pair(12, 49), Pair(22, 43), Pair(14, 55), Pair(37, 37), Pair(40, 41), Pair(139, 38),
        Pair(15, 45), Pair(25, 40), Pair(11, 48), Pair(20, 41), Pair(37, 38), Pair(4, 49), Pair(8, 45), Pair(69, 51),
        Pair(8, 41), Pair(2, 44), Pair(10, 50), Pair(13, 41), Pair(5, 48), Pair(22, 54), Pair(22, 52), Pair(0, 0),
        Pair(12, 37), Pair(6, 46), Pair(13, 45), Pair(0, 45), Pair(2, 42), Pair(-4, 42), Pair(59, -25), Pair(-12, 53),
        Pair(5, 35), Pair(15, 37), Pair(20, 31), Pair(11, 35), Pair(2, 39), Pair(14, 35), Pair(1, 46), Pair(-29, 51),
        Pair(5, 36), Pair(11, 44), Pair(11, 31), Pair(11, 33), Pair(14, 34), Pair(9, 36), Pair(5, 50), Pair(-8, 36),
        Pair(12, 42), Pair(6, 44), Pair(11, 44), Pair(9, 44), Pair(7, 37), Pair(12, 30), Pair(-4, 55), Pair(-12, 44)
      },
      { // Piece 4
        Pair(18, 63), Pair(30, 50), Pair(31, 35), Pair(9, 63), Pair(4, 62), Pair(63, 44), Pair(19, 49), Pair(54, 39),
        Pair(19, 57), Pair(-2, 74), Pair(38, 50), Pair(-32, 96), Pair(16, 82), Pair(-3, 97), Pair(-6, 117), Pair(31, 77),
        Pair(30, 38), Pair(6, 61), Pair(27, 55), Pair(25, 67), Pair(15, 55), Pair(3, 89), Pair(-25, 108), Pair(9, 107),
        Pair(13, 29), Pair(13, 69), Pair(16, 70), Pair(15, 81), Pair(13, 77), Pair(33, 86), Pair(1, 73), Pair(0, 0),
        Pair(13, 56), Pair(15, 63), Pair(13, 68), Pair(13, 57), Pair(20, 61), Pair(10, 59), Pair(4, 10), Pair(3, 31),
        Pair(7, 59), Pair(9, 56), Pair(20, 51), Pair(20, 52), Pair(18, 63), Pair(13, 67), Pair(14, 38), Pair(-1, 63),
        Pair(16, 47), Pair(18, 31), Pair(15, 37), Pair(14, 42), Pair(11, 55), Pair(6, 70), Pair(21, 38), Pair(23, 57),
        Pair(24, 39), Pair(15, 37), Pair(11, 43), Pair(14, 43), Pair(18, 31), Pair(8, 79), Pair(-12, 61), Pair(-16, 68)
      },
      { // Piece 5
        Pair(-5, -9), Pair(81, -28), Pair(212, -67), Pair(-64, -22), Pair(35, -54), Pair(53, -54), Pair(-33, -35), Pair(36, 116),
        Pair(50, -27), Pair(32, -27), Pair(7, -18), Pair(-21, -18), Pair(-75, -11), Pair(67, -35), Pair(25, -47), Pair(14, -32),
        Pair(11, -28), Pair(101, -33), Pair(97, -24), Pair(48, -19), Pair(61, -17), Pair(127, -26), Pair(30, -5), Pair(21, -2),
        Pair(71, -29), Pair(59, -23), Pair(81, -22), Pair(44, -9), Pair(38, -4), Pair(-47, 5), Pair(39, -41), Pair(0, 0),
        Pair(36, -35), Pair(53, -21), Pair(83, -19), Pair(52, -11), Pair(36, -4), Pair(12, -3), Pair(-246, -25), Pair(96, -64),
        Pair(9, -7), Pair(58, -24), Pair(42, -13), Pair(37, -7), Pair(16, 4), Pair(-6, 5), Pair(27, 5), Pair(30, -1),
        Pair(12, -25), Pair(-6, -11), Pair(16, -13), Pair(16, -5), Pair(15, 5), Pair(-6, 14), Pair(7, 7), Pair(2, 4),
        Pair(-11, -8), Pair(-11, -19), Pair(-12, -3), Pair(4, -1), Pair(-3, 11), Pair(-5, 14), Pair(3, 8), Pair(-8, 4)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(90, -50), Pair(-15, 13), Pair(-10, 18), Pair(-9, 17), Pair(1, 9), Pair(-5, 23), Pair(-13, 21), Pair(8, 21),
        Pair(0, 0), Pair(-6, 2), Pair(-1, 3), Pair(1, 6), Pair(1, 12), Pair(-4, 15), Pair(-4, 23), Pair(-11, 19),
        Pair(-9, -12), Pair(-2, 7), Pair(-7, -1), Pair(1, 1), Pair(-4, 7), Pair(-3, 5), Pair(-2, 6), Pair(-5, 11),
        Pair(-4, -5), Pair(-5, -2), Pair(0, 2), Pair(-1, -1), Pair(-2, 0), Pair(-4, 4), Pair(-3, 3), Pair(-2, 4),
        Pair(0, 0), Pair(-4, -1), Pair(-1, 3), Pair(-1, -2), Pair(-1, 5), Pair(-5, 1), Pair(-5, -1), Pair(-4, 0),
        Pair(8, -5), Pair(-1, -3), Pair(1, -2), Pair(-1, 1), Pair(-2, 0), Pair(-5, -2), Pair(-4, -2), Pair(-4, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-27, 41), Pair(35, 67), Pair(0, 42), Pair(97, 9), Pair(30, 26), Pair(-6, 52), Pair(120, -1), Pair(5, 10),
        Pair(-1, -13), Pair(-1, 38), Pair(-3, 40), Pair(13, 38), Pair(36, 34), Pair(53, 19), Pair(26, 19), Pair(44, 13),
        Pair(0, 0), Pair(0, 48), Pair(8, 44), Pair(19, 36), Pair(26, 41), Pair(55, 16), Pair(38, 20), Pair(31, 5),
        Pair(25, 70), Pair(-30, -8), Pair(7, 45), Pair(13, 33), Pair(22, 42), Pair(25, 23), Pair(27, 23), Pair(25, 17),
        Pair(0, 56), Pair(-20, 50), Pair(4, 38), Pair(3, 34), Pair(12, 35), Pair(14, 30), Pair(24, 31), Pair(17, 30),
        Pair(-16, 13), Pair(-3, 39), Pair(-12, 46), Pair(10, 32), Pair(10, 29), Pair(6, 35), Pair(11, 31), Pair(13, 31),
        Pair(2, 31), Pair(-3, 50), Pair(1, 29), Pair(3, 32), Pair(3, 29), Pair(9, 25), Pair(-5, 37), Pair(13, 25),
        Pair(-68, 50), Pair(-4, 23), Pair(3, 34), Pair(14, 16), Pair(-1, 28), Pair(10, 28), Pair(7, 44), Pair(-7, 59)
      },
      { // Piece 2
        Pair(11, 74), Pair(-25, 77), Pair(4, 73), Pair(-39, 79), Pair(-35, 80), Pair(-39, 85), Pair(10, 86), Pair(-16, 41),
        Pair(31, 53), Pair(-17, 73), Pair(3, 62), Pair(-21, 68), Pair(-27, 78), Pair(-16, 89), Pair(13, 72), Pair(-2, 59),
        Pair(0, 0), Pair(-1, 68), Pair(-22, 71), Pair(1, 67), Pair(-12, 84), Pair(12, 69), Pair(17, 63), Pair(21, 36),
        Pair(19, 84), Pair(-28, -18), Pair(-3, 67), Pair(-6, 68), Pair(11, 69), Pair(-1, 64), Pair(9, 47), Pair(5, 54),
        Pair(-4, 68), Pair(-24, 60), Pair(-8, 57), Pair(0, 60), Pair(6, 56), Pair(2, 56), Pair(-9, 62), Pair(5, 57),
        Pair(7, 63), Pair(-7, 61), Pair(-2, 54), Pair(0, 61), Pair(4, 49), Pair(-2, 56), Pair(9, 51), Pair(4, 41),
        Pair(4, 92), Pair(2, 53), Pair(-6, 57), Pair(1, 50), Pair(-5, 46), Pair(-2, 44), Pair(4, 44), Pair(1, 50),
        Pair(2, 62), Pair(-1, 73), Pair(5, 63), Pair(-9, 58), Pair(3, 49), Pair(-6, 40), Pair(5, 58), Pair(8, 65)
      },
      { // Piece 3
        Pair(19, 92), Pair(-5, 94), Pair(-10, 101), Pair(-7, 90), Pair(-14, 103), Pair(2, 85), Pair(41, 89), Pair(5, 100),
        Pair(25, 92), Pair(7, 92), Pair(-13, 110), Pair(3, 100), Pair(-18, 104), Pair(1, 101), Pair(24, 87), Pair(10, 94),
        Pair(0, 0), Pair(5, 108), Pair(4, 120), Pair(-10, 110), Pair(-14, 108), Pair(10, 97), Pair(13, 91), Pair(14, 85),
        Pair(-16, 101), Pair(13, -47), Pair(-9, 94), Pair(-21, 97), Pair(-12, 96), Pair(8, 85), Pair(8, 83), Pair(13, 84),
        Pair(-22, 84), Pair(-19, 88), Pair(-25, 91), Pair(-9, 87), Pair(-11, 91), Pair(-11, 86), Pair(7, 84), Pair(19, 81),
        Pair(-27, 88), Pair(-16, 80), Pair(-20, 84), Pair(-12, 80), Pair(-13, 85), Pair(1, 79), Pair(-6, 86), Pair(13, 78),
        Pair(-17, 68), Pair(-8, 83), Pair(-19, 83), Pair(-14, 76), Pair(-16, 83), Pair(-4, 77), Pair(-1, 80), Pair(13, 76),
        Pair(-12, 78), Pair(-9, 79), Pair(-8, 82), Pair(-7, 84), Pair(-8, 83), Pair(-7, 83), Pair(-1, 80), Pair(-1, 92)
      },
      { // Piece 4
        Pair(-33, 210), Pair(-13, 188), Pair(-6, 216), Pair(-4, 201), Pair(-4, 187), Pair(-23, 193), Pair(50, 141), Pair(50, 161),
        Pair(35, 148), Pair(30, 167), Pair(27, 165), Pair(18, 176), Pair(13, 180), Pair(18, 168), Pair(9, 186), Pair(34, 158),
        Pair(0, 0), Pair(31, 177), Pair(27, 194), Pair(11, 198), Pair(32, 148), Pair(46, 163), Pair(35, 154), Pair(58, 148),
        Pair(30, 159), Pair(18, 19), Pair(15, 159), Pair(19, 177), Pair(16, 176), Pair(32, 173), Pair(44, 164), Pair(46, 147),
        Pair(19, 150), Pair(23, 134), Pair(23, 151), Pair(21, 156), Pair(23, 148), Pair(27, 154), Pair(34, 133), Pair(32, 161),
        Pair(26, 149), Pair(17, 152), Pair(19, 146), Pair(21, 153), Pair(20, 134), Pair(24, 133), Pair(30, 136), Pair(36, 148),
        Pair(28, 141), Pair(21, 127), Pair(19, 132), Pair(17, 143), Pair(27, 132), Pair(21, 137), Pair(22, 116), Pair(34, 143),
        Pair(29, 119), Pair(20, 131), Pair(18, 152), Pair(19, 127), Pair(18, 132), Pair(16, 131), Pair(30, 119), Pair(27, 99)
      },
      { // Piece 5
        Pair(-8, 40), Pair(29, 24), Pair(91, -46), Pair(105, 4), Pair(-4, -40), Pair(62, -53), Pair(45, 11), Pair(-45, -13),
        Pair(-41, -34), Pair(-43, 4), Pair(82, -19), Pair(82, -23), Pair(-49, 2), Pair(14, 9), Pair(-63, 9), Pair(-88, 9),
        Pair(0, 0), Pair(-44, -38), Pair(-22, 4), Pair(63, -9), Pair(-2, 4), Pair(40, 4), Pair(-11, 13), Pair(-21, 6),
        Pair(-8, -76), Pair(-62, -60), Pair(-96, 6), Pair(53, -6), Pair(-11, 6), Pair(-8, 13), Pair(28, 5), Pair(22, -5),
        Pair(51, -35), Pair(-12, -7), Pair(-38, -2), Pair(-4, 6), Pair(-2, 5), Pair(1, 7), Pair(21, -2), Pair(37, -7),
        Pair(-53, -21), Pair(-9, -5), Pair(-18, 6), Pair(22, 0), Pair(-3, 6), Pair(2, 3), Pair(-4, 5), Pair(4, 3),
        Pair(-25, -6), Pair(-24, 14), Pair(-11, 9), Pair(13, 6), Pair(11, 0), Pair(5, 0), Pair(0, 2), Pair(-2, 5),
        Pair(-9, 11), Pair(12, 3), Pair(8, 5), Pair(14, 8), Pair(0, 4), Pair(8, -5), Pair(-5, -1), Pair(3, -4)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 22), Pair(-21, 30), Pair(-10, 11), Pair(-7, 14), Pair(3, 18), Pair(-5, 18), Pair(16, 15), Pair(7, 18),
        Pair(-1, 7), Pair(0, 0), Pair(0, 0), Pair(2, 4), Pair(0, 14), Pair(3, 15), Pair(-1, 17), Pair(-6, 18),
        Pair(5, 7), Pair(-12, -12), Pair(-6, 23), Pair(-2, 6), Pair(1, 10), Pair(-4, 8), Pair(-1, 11), Pair(-5, 13),
        Pair(3, 2), Pair(-4, -5), Pair(2, 7), Pair(-2, 4), Pair(-4, 5), Pair(-5, 9), Pair(-4, 5), Pair(-1, 5),
        Pair(2, 1), Pair(0, 0), Pair(0, 4), Pair(-2, 5), Pair(-3, 3), Pair(-6, 3), Pair(-4, 3), Pair(-4, 2),
        Pair(0, 0), Pair(3, -1), Pair(-1, 3), Pair(-3, 3), Pair(-2, -2), Pair(-8, -1), Pair(-8, -2), Pair(-4, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-44, 32), Pair(0, 19), Pair(-15, 45), Pair(17, 33), Pair(7, 46), Pair(157, -19), Pair(59, 13), Pair(-5, 51),
        Pair(-7, 46), Pair(-42, -16), Pair(7, 37), Pair(6, 17), Pair(20, 52), Pair(21, 38), Pair(-14, 41), Pair(18, 35),
        Pair(-35, 29), Pair(0, 0), Pair(-7, 44), Pair(5, 51), Pair(-4, 43), Pair(12, 49), Pair(19, 39), Pair(23, 37),
        Pair(-31, 15), Pair(-1, 74), Pair(-45, -3), Pair(6, 44), Pair(3, 53), Pair(5, 49), Pair(15, 40), Pair(8, 37),
        Pair(-22, 31), Pair(-14, 53), Pair(-27, 47), Pair(-8, 50), Pair(-5, 42), Pair(1, 42), Pair(17, 42), Pair(14, 32),
        Pair(4, 49), Pair(-22, 17), Pair(-5, 49), Pair(-13, 43), Pair(-2, 46), Pair(-1, 41), Pair(2, 41), Pair(5, 53),
        Pair(2, 73), Pair(1, 43), Pair(10, 42), Pair(-1, 41), Pair(-5, 45), Pair(-1, 45), Pair(7, 30), Pair(7, 38),
        Pair(-7, 46), Pair(4, 33), Pair(14, 29), Pair(1, 48), Pair(2, 45), Pair(-3, 44), Pair(5, 36), Pair(-7, 46)
      },
      { // Piece 2
        Pair(3, 60), Pair(-15, 53), Pair(-64, 76), Pair(-38, 66), Pair(-76, 97), Pair(-63, 65), Pair(17, 67), Pair(-50, 90),
        Pair(-122, -14), Pair(-29, 65), Pair(-19, 65), Pair(-58, 91), Pair(-34, 69), Pair(-19, 85), Pair(-2, 64), Pair(5, 68),
        Pair(0, 63), Pair(0, 0), Pair(-29, 75), Pair(-12, 60), Pair(-19, 74), Pair(0, 79), Pair(-8, 77), Pair(6, 49),
        Pair(-7, -47), Pair(-11, 86), Pair(-96, -19), Pair(-9, 68), Pair(1, 64), Pair(-1, 67), Pair(-3, 57), Pair(16, 50),
        Pair(-21, 59), Pair(-20, 49), Pair(-24, 66), Pair(-19, 63), Pair(-4, 60), Pair(-5, 50), Pair(-4, 66), Pair(7, 56),
        Pair(-7, 52), Pair(-12, 68), Pair(-17, 48), Pair(-5, 61), Pair(-7, 38), Pair(-4, 52), Pair(-5, 51), Pair(3, 47),
        Pair(-2, 50), Pair(0, 52), Pair(-10, 63), Pair(-4, 42), Pair(-7, 48), Pair(-5, 38), Pair(2, 46), Pair(-2, 43),
        Pair(6, 52), Pair(8, 62), Pair(0, 51), Pair(-10, 58), Pair(-13, 41), Pair(4, 53), Pair(-9, 43), Pair(8, 57)
      },
      { // Piece 3
        Pair(6, 68), Pair(6, 83), Pair(-18, 86), Pair(-5, 76), Pair(17, 71), Pair(6, 72), Pair(14, 70), Pair(30, 72),
        Pair(-14, 78), Pair(18, 85), Pair(-8, 78), Pair(-8, 88), Pair(8, 73), Pair(5, 75), Pair(1, 74), Pair(-6, 75),
        Pair(-36, 85), Pair(0, 0), Pair(-10, 87), Pair(12, 75), Pair(7, 78), Pair(12, 75), Pair(4, 70), Pair(8, 71),
        Pair(-12, -28), Pair(-22, 70), Pair(-11, -26), Pair(-9, 75), Pair(-13, 75), Pair(4, 64), Pair(4, 73), Pair(9, 56),
        Pair(-18, 62), Pair(-24, 75), Pair(-33, 73), Pair(-9, 66), Pair(-12, 70), Pair(-13, 73), Pair(6, 54), Pair(14, 59),
        Pair(-14, 62), Pair(-20, 61), Pair(-25, 67), Pair(-7, 61), Pair(-16, 72), Pair(-7, 66), Pair(14, 63), Pair(13, 67),
        Pair(-7, 57), Pair(-13, 58), Pair(-21, 62), Pair(-10, 64), Pair(-10, 56), Pair(-3, 57), Pair(0, 63), Pair(3, 67),
        Pair(-13, 65), Pair(-14, 61), Pair(-19, 66), Pair(-11, 68), Pair(-9, 67), Pair(-8, 72), Pair(-3, 68), Pair(-10, 76)
      },
      { // Piece 4
        Pair(46, 93), Pair(5, 128), Pair(-12, 140), Pair(41, 116), Pair(16, 133), Pair(18, 112), Pair(-21, 177), Pair(46, 93),
        Pair(28, 81), Pair(11, 136), Pair(29, 115), Pair(36, 127), Pair(16, 140), Pair(29, 115), Pair(19, 131), Pair(56, 84),
        Pair(28, 74), Pair(0, 0), Pair(24, 105), Pair(23, 130), Pair(39, 119), Pair(29, 132), Pair(39, 108), Pair(45, 113),
        Pair(4, 227), Pair(31, 98), Pair(-27, 154), Pair(23, 110), Pair(21, 109), Pair(35, 112), Pair(37, 108), Pair(40, 120),
        Pair(11, 98), Pair(12, 106), Pair(12, 106), Pair(22, 109), Pair(19, 109), Pair(29, 115), Pair(34, 103), Pair(25, 117),
        Pair(12, 127), Pair(16, 107), Pair(20, 86), Pair(11, 111), Pair(15, 104), Pair(15, 108), Pair(26, 114), Pair(23, 114),
        Pair(21, 123), Pair(23, 93), Pair(15, 108), Pair(15, 100), Pair(17, 99), Pair(26, 87), Pair(22, 97), Pair(33, 96),
        Pair(27, 92), Pair(22, 110), Pair(21, 97), Pair(20, 92), Pair(9, 105), Pair(23, 85), Pair(26, 67), Pair(8, 116)
      },
      { // Piece 5
        Pair(-33, -309), Pair(-37, -36), Pair(-16, 12), Pair(-17, 14), Pair(78, -6), Pair(50, -5), Pair(-37, 24), Pair(37, -106),
        Pair(33, -23), Pair(47, -47), Pair(63, -43), Pair(114, -29), Pair(-207, 54), Pair(-14, 14), Pair(-42, 3), Pair(-41, 10),
        Pair(-74, -37), Pair(0, 0), Pair(3, -37), Pair(152, -44), Pair(10, -8), Pair(37, -3), Pair(20, 1), Pair(24, -4),
        Pair(2, 4), Pair(71, -95), Pair(4, 55), Pair(12, -11), Pair(-5, 2), Pair(18, 1), Pair(57, -2), Pair(47, -10),
        Pair(66, -55), Pair(8, -60), Pair(16, -26), Pair(17, -26), Pair(18, -7), Pair(28, -5), Pair(-6, 5), Pair(22, -8),
        Pair(18, -20), Pair(2, -36), Pair(8, -17), Pair(8, -9), Pair(20, -5), Pair(9, 1), Pair(12, -4), Pair(21, -3),
        Pair(-10, -11), Pair(-5, -14), Pair(7, -8), Pair(23, -5), Pair(8, 1), Pair(14, -7), Pair(-1, -2), Pair(-3, 3),
        Pair(25, -17), Pair(19, -20), Pair(25, -13), Pair(19, -1), Pair(7, -2), Pair(16, -5), Pair(-2, -1), Pair(0, -5)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, 23), Pair(-14, 13), Pair(-11, 5), Pair(12, -3), Pair(6, 16), Pair(11, 14), Pair(-18, 21), Pair(-11, 22),
        Pair(4, 7), Pair(-6, 9), Pair(0, 0), Pair(-1, 7), Pair(4, 10), Pair(6, 15), Pair(4, 19), Pair(-8, 15),
        Pair(-4, 1), Pair(1, 2), Pair(-8, -14), Pair(3, 33), Pair(2, 4), Pair(5, 7), Pair(0, 5), Pair(1, 12),
        Pair(1, 0), Pair(2, -7), Pair(-4, -4), Pair(-1, 5), Pair(2, 1), Pair(-2, 4), Pair(-2, 6), Pair(-4, 7),
        Pair(2, -1), Pair(0, -4), Pair(0, 0), Pair(0, 6), Pair(-2, 3), Pair(-3, 3), Pair(-2, 3), Pair(-5, 3),
        Pair(1, -1), Pair(-4, -8), Pair(4, 2), Pair(-2, 2), Pair(2, 0), Pair(-5, -1), Pair(-2, 0), Pair(-4, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-39, 55), Pair(72, 27), Pair(18, 29), Pair(-31, 70), Pair(77, 25), Pair(93, 16), Pair(62, 18), Pair(14, -29),
        Pair(-12, -50), Pair(-7, 44), Pair(8, 2), Pair(14, 48), Pair(6, 14), Pair(2, 28), Pair(-13, 44), Pair(30, 33),
        Pair(23, 51), Pair(-13, 41), Pair(0, 0), Pair(3, 55), Pair(6, 56), Pair(9, 49), Pair(25, 29), Pair(10, 34),
        Pair(3, 50), Pair(-18, -20), Pair(6, 81), Pair(-48, 1), Pair(17, 35), Pair(9, 35), Pair(18, 37), Pair(18, 24),
        Pair(3, 39), Pair(-26, 41), Pair(7, 50), Pair(-19, 36), Pair(7, 40), Pair(0, 33), Pair(14, 46), Pair(12, 45),
        Pair(1, 11), Pair(0, 51), Pair(-10, 24), Pair(5, 43), Pair(-16, 35), Pair(5, 49), Pair(6, 39), Pair(10, 40),
        Pair(5, 22), Pair(0, 46), Pair(4, 32), Pair(4, 46), Pair(7, 35), Pair(10, 38), Pair(11, 35), Pair(14, 27),
        Pair(20, 7), Pair(7, 47), Pair(15, 37), Pair(19, 24), Pair(14, 44), Pair(7, 39), Pair(17, 51), Pair(24, 18)
      },
      { // Piece 2
        Pair(-125, -51), Pair(-30, 73), Pair(30, 32), Pair(-3, 46), Pair(16, 48), Pair(-22, 72), Pair(39, 20), Pair(36, 42),
        Pair(-6, 55), Pair(-56, 23), Pair(3, 61), Pair(-16, 43), Pair(4, 63), Pair(-7, 62), Pair(-15, 58), Pair(-17, 64),
        Pair(-9, 48), Pair(-6, 57), Pair(0, 0), Pair(1, 48), Pair(-2, 45), Pair(16, 56), Pair(-8, 60), Pair(19, 43),
        Pair(-1, 49), Pair(-19, -50), Pair(8, 72), Pair(-65, -41), Pair(13, 51), Pair(-7, 54), Pair(4, 52), Pair(4, 39),
        Pair(-22, 20), Pair(-16, 48), Pair(-11, 38), Pair(-25, 50), Pair(-7, 37), Pair(8, 47), Pair(-7, 47), Pair(12, 49),
        Pair(6, 29), Pair(-10, 36), Pair(6, 45), Pair(-1, 32), Pair(4, 46), Pair(-1, 30), Pair(13, 45), Pair(0, 35),
        Pair(-8, 30), Pair(13, 33), Pair(4, 41), Pair(8, 42), Pair(-4, 31), Pair(8, 40), Pair(-4, 15), Pair(11, 45),
        Pair(11, 42), Pair(9, 40), Pair(9, 52), Pair(-5, 36), Pair(15, 40), Pair(1, 34), Pair(13, 47), Pair(-11, 26)
      },
      { // Piece 3
        Pair(18, 44), Pair(2, 57), Pair(12, 52), Pair(-9, 66), Pair(23, 57), Pair(13, 57), Pair(22, 51), Pair(-24, 76),
        Pair(-2, 62), Pair(-2, 51), Pair(-7, 69), Pair(-5, 57), Pair(5, 59), Pair(19, 55), Pair(17, 48), Pair(12, 58),
        Pair(-5, 56), Pair(-15, 50), Pair(0, 0), Pair(-4, 58), Pair(18, 55), Pair(30, 53), Pair(9, 55), Pair(22, 45),
        Pair(-12, 48), Pair(57, -29), Pair(4, 45), Pair(-25, 10), Pair(-13, 55), Pair(4, 51), Pair(12, 51), Pair(14, 43),
        Pair(-1, 55), Pair(4, 34), Pair(-13, 45), Pair(-6, 42), Pair(-3, 49), Pair(2, 52), Pair(9, 43), Pair(15, 50),
        Pair(2, 47), Pair(-1, 39), Pair(-12, 51), Pair(-3, 43), Pair(3, 47), Pair(10, 37), Pair(11, 53), Pair(25, 43),
        Pair(10, 31), Pair(-4, 46), Pair(-7, 45), Pair(-5, 37), Pair(0, 51), Pair(7, 45), Pair(9, 48), Pair(11, 40),
        Pair(-3, 50), Pair(-4, 48), Pair(0, 40), Pair(-5, 48), Pair(0, 44), Pair(0, 50), Pair(15, 45), Pair(7, 51)
      },
      { // Piece 4
        Pair(35, 52), Pair(-18, 134), Pair(54, 78), Pair(-18, 134), Pair(60, 86), Pair(-9, 102), Pair(58, 50), Pair(20, 61),
        Pair(29, 72), Pair(17, 62), Pair(22, 103), Pair(17, 90), Pair(26, 119), Pair(36, 79), Pair(-21, 98), Pair(16, 82),
        Pair(25, 57), Pair(25, 73), Pair(0, 0), Pair(32, 80), Pair(24, 101), Pair(0, 136), Pair(3, 113), Pair(40, 85),
        Pair(18, 88), Pair(1, 159), Pair(42, 70), Pair(7, 179), Pair(13, 105), Pair(31, 89), Pair(12, 94), Pair(24, 87),
        Pair(20, 77), Pair(13, 99), Pair(18, 74), Pair(13, 77), Pair(12, 77), Pair(21, 91), Pair(27, 77), Pair(24, 78),
        Pair(19, 86), Pair(15, 77), Pair(27, 84), Pair(17, 84), Pair(13, 78), Pair(23, 76), Pair(19, 77), Pair(28, 86),
        Pair(14, 81), Pair(18, 73), Pair(22, 79), Pair(15, 80), Pair(21, 82), Pair(22, 78), Pair(20, 71), Pair(35, 61),
        Pair(19, 100), Pair(20, 67), Pair(22, 81), Pair(18, 68), Pair(16, 74), Pair(19, 79), Pair(8, 93), Pair(18, 75)
      },
      { // Piece 5
        Pair(-2, 26), Pair(11, 27), Pair(-120, -60), Pair(-1, -114), Pair(44, -14), Pair(17, -12), Pair(-16, -31), Pair(55, -39),
        Pair(14, -22), Pair(35, -12), Pair(75, -40), Pair(120, -34), Pair(-12, -10), Pair(44, -5), Pair(15, 11), Pair(-66, 6),
        Pair(-100, -14), Pair(-21, -54), Pair(0, 0), Pair(176, -80), Pair(90, -25), Pair(19, 8), Pair(-62, 22), Pair(-39, 24),
        Pair(37, -17), Pair(1, 15), Pair(-3, -67), Pair(-2, -12), Pair(-103, 17), Pair(22, 3), Pair(45, 6), Pair(27, -2),
        Pair(-16, -17), Pair(34, -15), Pair(36, -39), Pair(48, -34), Pair(22, -15), Pair(-7, 10), Pair(7, 7), Pair(-6, 7),
        Pair(29, -11), Pair(-20, -6), Pair(-12, -11), Pair(-3, -9), Pair(-7, 2), Pair(14, 4), Pair(11, 2), Pair(4, 9),
        Pair(-12, 11), Pair(-4, -5), Pair(5, -8), Pair(-5, -4), Pair(-4, 6), Pair(9, 6), Pair(2, 9), Pair(7, 4),
        Pair(6, 10), Pair(-9, 0), Pair(-10, 6), Pair(20, 1), Pair(1, 14), Pair(8, 12), Pair(0, 8), Pair(9, -1)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 17), Pair(5, 9), Pair(12, 14), Pair(-8, -17), Pair(3, 14), Pair(-13, 27), Pair(23, 7), Pair(3, 10),
        Pair(-1, 12), Pair(6, 0), Pair(-2, 8), Pair(0, 0), Pair(-8, 3), Pair(10, 1), Pair(1, 10), Pair(-6, 10),
        Pair(-6, 8), Pair(0, 2), Pair(-6, 10), Pair(-12, -12), Pair(-5, 11), Pair(-3, 5), Pair(1, 8), Pair(-2, 6),
        Pair(-2, 4), Pair(-3, -3), Pair(2, -1), Pair(-6, -7), Pair(-1, 1), Pair(-4, 7), Pair(2, 2), Pair(1, 8),
        Pair(0, 0), Pair(3, -1), Pair(0, -6), Pair(0, 0), Pair(-2, -1), Pair(-3, 0), Pair(-3, 4), Pair(0, 2),
        Pair(0, -1), Pair(-2, -6), Pair(-3, -8), Pair(0, -2), Pair(-1, -2), Pair(-1, 0), Pair(-2, 3), Pair(0, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-62, 60), Pair(26, 14), Pair(-73, 64), Pair(-52, 53), Pair(-6, 28), Pair(-45, 54), Pair(-96, 25), Pair(29, -38),
        Pair(-3, 55), Pair(-33, 11), Pair(7, 28), Pair(-36, 9), Pair(-30, 82), Pair(-26, 11), Pair(-15, 66), Pair(19, 36),
        Pair(-27, 12), Pair(-13, 45), Pair(-29, 51), Pair(0, 0), Pair(-15, 52), Pair(-32, 66), Pair(-16, 41), Pair(6, 47),
        Pair(-11, 30), Pair(3, 37), Pair(-61, 26), Pair(-4, 87), Pair(-72, 47), Pair(-15, 49), Pair(-7, 34), Pair(4, 40),
        Pair(-12, -4), Pair(-7, 40), Pair(-25, 30), Pair(-8, 49), Pair(-18, 35), Pair(-6, 46), Pair(-14, 28), Pair(0, 45),
        Pair(-3, 49), Pair(-16, 15), Pair(-5, 45), Pair(-24, 28), Pair(-5, 46), Pair(-15, 31), Pair(-4, 54), Pair(-2, 35),
        Pair(11, 36), Pair(-6, 30), Pair(0, 27), Pair(-8, 35), Pair(-3, 31), Pair(-8, 33), Pair(-3, 37), Pair(0, 29),
        Pair(-9, 28), Pair(3, 32), Pair(11, 4), Pair(-4, 35), Pair(-8, 33), Pair(-5, 32), Pair(-1, 43), Pair(-19, 93)
      },
      { // Piece 2
        Pair(-25, 52), Pair(-37, 44), Pair(-45, 66), Pair(-19, 55), Pair(-79, 78), Pair(-64, 25), Pair(-29, 48), Pair(-16, 33),
        Pair(-7, 31), Pair(-11, 51), Pair(-33, 31), Pair(-78, 85), Pair(-55, 38), Pair(-7, 72), Pair(-15, 31), Pair(-8, 45),
        Pair(-12, 57), Pair(-23, 36), Pair(-19, 59), Pair(0, 0), Pair(-23, 66), Pair(-39, 62), Pair(-17, 59), Pair(6, 28),
        Pair(-7, 36), Pair(-16, 45), Pair(-94, -70), Pair(-1, 79), Pair(-67, -97), Pair(-13, 51), Pair(-8, 45), Pair(-9, 48),
        Pair(-4, 37), Pair(-9, 15), Pair(-22, 46), Pair(-17, 33), Pair(-25, 45), Pair(-8, 25), Pair(-9, 52), Pair(1, 25),
        Pair(-6, 10), Pair(-13, 35), Pair(-10, 24), Pair(-6, 40), Pair(-5, 24), Pair(-4, 42), Pair(-13, 9), Pair(-1, 36),
        Pair(-24, 17), Pair(-7, 16), Pair(0, 44), Pair(-4, 27), Pair(-8, 36), Pair(-8, 20), Pair(-4, 31), Pair(-18, 0),
        Pair(-17, 25), Pair(-2, 35), Pair(0, 28), Pair(-11, 46), Pair(-10, 32), Pair(1, 40), Pair(-12, 28), Pair(10, 29)
      },
      { // Piece 3
        Pair(-12, 42), Pair(1, 37), Pair(-5, 40), Pair(35, 27), Pair(-18, 51), Pair(23, 37), Pair(-18, 43), Pair(17, 44),
        Pair(-1, 35), Pair(0, 42), Pair(-16, 43), Pair(-35, 58), Pair(-15, 44), Pair(31, 37), Pair(17, 39), Pair(1, 49),
        Pair(-9, 32), Pair(-21, 51), Pair(-1, 33), Pair(0, 0), Pair(-1, 47), Pair(49, 29), Pair(0, 46), Pair(11, 31),
        Pair(-6, 33), Pair(-14, 33), Pair(2, -106), Pair(-1, 24), Pair(-141, 83), Pair(-18, 32), Pair(4, 30), Pair(-3, 39),
        Pair(-6, 38), Pair(-14, 32), Pair(-13, 27), Pair(-8, 25), Pair(-14, 32), Pair(-7, 36), Pair(-5, 41), Pair(10, 35),
        Pair(-4, 29), Pair(-7, 35), Pair(-11, 27), Pair(-6, 24), Pair(-8, 32), Pair(-5, 33), Pair(1, 44), Pair(1, 52),
        Pair(2, 29), Pair(-4, 32), Pair(-12, 33), Pair(-5, 19), Pair(-15, 34), Pair(-6, 31), Pair(-3, 43), Pair(16, 25),
        Pair(-9, 37), Pair(-6, 31), Pair(-8, 31), Pair(-10, 35), Pair(-13, 35), Pair(-7, 38), Pair(-3, 44), Pair(4, 28)
      },
      { // Piece 4
        Pair(-8, 89), Pair(37, 7), Pair(31, 67), Pair(-5, 95), Pair(30, 72), Pair(-101, 156), Pair(28, 67), Pair(35, 56),
        Pair(15, 66), Pair(16, 84), Pair(6, 45), Pair(1, 71), Pair(-1, 76), Pair(46, 81), Pair(-7, 126), Pair(20, 90),
        Pair(8, 75), Pair(9, 65), Pair(-3, 75), Pair(0, 0), Pair(16, 91), Pair(16, 97), Pair(16, 66), Pair(37, 81),
        Pair(18, 63), Pair(12, 67), Pair(37, -11), Pair(30, 59), Pair(-21, -17), Pair(9, 91), Pair(19, 78), Pair(12, 89),
        Pair(11, 60), Pair(7, 80), Pair(4, 62), Pair(16, 51), Pair(6, 66), Pair(14, 50), Pair(13, 88), Pair(11, 96),
        Pair(4, 86), Pair(7, 66), Pair(9, 67), Pair(18, 67), Pair(10, 61), Pair(5, 74), Pair(11, 62), Pair(10, 95),
        Pair(5, 82), Pair(10, 58), Pair(10, 60), Pair(18, 68), Pair(8, 58), Pair(8, 66), Pair(7, 62), Pair(28, 20),
        Pair(12, 67), Pair(17, 76), Pair(10, 69), Pair(16, 67), Pair(18, 44), Pair(13, 72), Pair(30, 42), Pair(34, 46)
      },
      { // Piece 5
        Pair(22, -7), Pair(-91, -47), Pair(-5, -97), Pair(30, -49), Pair(31, -43), Pair(-22, -35), Pair(0, -6), Pair(28, -50),
        Pair(27, 60), Pair(32, -18), Pair(193, -60), Pair(-38, -38), Pair(-44, -29), Pair(40, -10), Pair(79, -18), Pair(46, -26),
        Pair(29, 3), Pair(-31, 10), Pair(93, -72), Pair(0, 0), Pair(92, -75), Pair(114, -6), Pair(-10, 11), Pair(66, -9),
        Pair(-6, -6), Pair(37, -4), Pair(-4, -24), Pair(68, -99), Pair(2, 8), Pair(-38, 0), Pair(63, -9), Pair(34, -5),
        Pair(-33, -12), Pair(-7, -9), Pair(56, -39), Pair(28, -46), Pair(10, -27), Pair(-9, -4), Pair(-33, 10), Pair(-16, 12),
        Pair(-41, 26), Pair(-34, 6), Pair(-6, -15), Pair(2, -23), Pair(-19, -13), Pair(-5, 7), Pair(15, 9), Pair(24, -1),
        Pair(-7, 12), Pair(-26, 21), Pair(-27, 4), Pair(18, -20), Pair(-17, -1), Pair(14, 5), Pair(-3, 9), Pair(4, 9),
        Pair(-24, 33), Pair(-16, 15), Pair(-12, -5), Pair(-6, -3), Pair(1, -12), Pair(-8, 16), Pair(-2, 16), Pair(2, 10)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-2, 20), Pair(10, 17), Pair(-3, 7), Pair(2, 3), Pair(-5, 6), Pair(7, 10), Pair(-19, 26), Pair(-10, 26),
        Pair(4, 6), Pair(3, 7), Pair(4, -2), Pair(-3, 2), Pair(0, 0), Pair(-4, 8), Pair(0, 6), Pair(-3, 5),
        Pair(3, 2), Pair(4, 3), Pair(2, 0), Pair(5, 27), Pair(-8, -5), Pair(2, 5), Pair(-4, 8), Pair(-3, 9),
        Pair(4, -2), Pair(5, -1), Pair(2, 2), Pair(5, 5), Pair(0, -1), Pair(-3, 2), Pair(2, 3), Pair(0, 3),
        Pair(3, 1), Pair(3, -2), Pair(0, -1), Pair(3, 0), Pair(0, 0), Pair(0, 1), Pair(-4, 2), Pair(-3, 0),
        Pair(4, 0), Pair(3, 0), Pair(2, -1), Pair(0, -2), Pair(1, 1), Pair(-3, -2), Pair(-6, -1), Pair(-2, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-33, 14), Pair(-25, 29), Pair(19, 32), Pair(-42, 44), Pair(33, -2), Pair(-35, 29), Pair(-97, 41), Pair(25, 38),
        Pair(-1, 37), Pair(-10, 39), Pair(-17, 2), Pair(-12, 44), Pair(-32, 23), Pair(-57, 51), Pair(-24, -5), Pair(-23, 56),
        Pair(-17, 35), Pair(-18, 29), Pair(-13, 45), Pair(-15, 42), Pair(0, 0), Pair(-11, 44), Pair(-19, 45), Pair(-15, 31),
        Pair(6, 31), Pair(-12, 32), Pair(0, 26), Pair(-88, 24), Pair(-4, 70), Pair(-51, 8), Pair(0, 28), Pair(-10, 31),
        Pair(0, 30), Pair(-16, 29), Pair(-5, 41), Pair(-31, 28), Pair(-12, 41), Pair(-24, 9), Pair(-6, 38), Pair(-9, -1),
        Pair(-2, 33), Pair(-7, 33), Pair(-15, 27), Pair(-10, 41), Pair(-24, 18), Pair(-7, 40), Pair(-17, 25), Pair(-8, 42),
        Pair(-1, 39), Pair(-13, 49), Pair(-11, 23), Pair(-4, 38), Pair(-12, 24), Pair(-10, 32), Pair(-6, 36), Pair(-3, 26),
        Pair(2, 46), Pair(-1, 25), Pair(4, 28), Pair(-7, 37), Pair(-2, 26), Pair(-6, 27), Pair(-10, 41), Pair(20, -2)
      },
      { // Piece 2
        Pair(-31, 29), Pair(2, 47), Pair(-14, 32), Pair(-45, 55), Pair(-21, 47), Pair(-52, 51), Pair(8, 10), Pair(11, 35),
        Pair(5, 34), Pair(-24, 39), Pair(-1, 49), Pair(-94, 53), Pair(-20, 58), Pair(-77, 26), Pair(-18, 51), Pair(-26, 30),
        Pair(-13, 32), Pair(-15, 56), Pair(-30, 39), Pair(-7, 48), Pair(0, 0), Pair(-25, 61), Pair(-33, 38), Pair(8, 32),
        Pair(-4, 47), Pair(-25, 38), Pair(-8, 45), Pair(-145, -40), Pair(1, 68), Pair(-88, -44), Pair(-4, 43), Pair(-16, 31),
        Pair(-26, 31), Pair(2, 34), Pair(-26, 21), Pair(-25, 37), Pair(-23, 28), Pair(-11, 27), Pair(-21, 18), Pair(-6, 42),
        Pair(4, 45), Pair(-22, 20), Pair(-8, 44), Pair(-16, 26), Pair(-5, 37), Pair(-20, 27), Pair(-9, 36), Pair(-25, 13),
        Pair(-30, 13), Pair(-2, 39), Pair(-16, 27), Pair(4, 40), Pair(-16, 25), Pair(-2, 31), Pair(-23, 17), Pair(-7, 27),
        Pair(-17, 35), Pair(-12, 32), Pair(3, 45), Pair(-21, 30), Pair(-1, 40), Pair(-12, 22), Pair(-10, 50), Pair(-16, 22)
      },
      { // Piece 3
        Pair(7, 42), Pair(-2, 42), Pair(-7, 49), Pair(-10, 44), Pair(26, 42), Pair(-3, 33), Pair(-21, 43), Pair(-17, 52),
        Pair(0, 42), Pair(-5, 45), Pair(10, 39), Pair(-8, 40), Pair(-8, 45), Pair(-14, 33), Pair(-10, 51), Pair(-17, 49),
        Pair(3, 37), Pair(-18, 48), Pair(8, 39), Pair(-18, 45), Pair(0, 0), Pair(20, 23), Pair(0, 30), Pair(-25, 41),
        Pair(-1, 37), Pair(-11, 34), Pair(-8, 40), Pair(-52, -33), Pair(5, 30), Pair(32, -52), Pair(5, 30), Pair(-5, 31),
        Pair(1, 34), Pair(-10, 40), Pair(-1, 33), Pair(-14, 27), Pair(-3, 30), Pair(-20, 36), Pair(-12, 48), Pair(8, 33),
        Pair(1, 42), Pair(-2, 26), Pair(-11, 39), Pair(-16, 35), Pair(-6, 25), Pair(-2, 28), Pair(0, 29), Pair(6, 35),
        Pair(9, 25), Pair(-5, 36), Pair(-6, 29), Pair(-8, 25), Pair(-5, 21), Pair(-6, 25), Pair(4, 43), Pair(16, 12),
        Pair(-4, 35), Pair(-6, 36), Pair(-6, 33), Pair(-10, 31), Pair(-4, 34), Pair(-6, 36), Pair(-3, 37), Pair(-2, 38)
      },
      { // Piece 4
        Pair(21, 65), Pair(-1, 110), Pair(25, 54), Pair(26, 89), Pair(33, 58), Pair(28, 84), Pair(68, 26), Pair(19, 70),
        Pair(27, 78), Pair(17, 80), Pair(22, 85), Pair(-11, 80), Pair(13, 74), Pair(7, 67), Pair(28, 87), Pair(29, 68),
        Pair(29, 58), Pair(19, 61), Pair(12, 63), Pair(4, 60), Pair(0, 0), Pair(9, 83), Pair(19, 53), Pair(42, 53),
        Pair(23, 46), Pair(13, 76), Pair(18, 74), Pair(-7, -8), Pair(30, 59), Pair(74, -29), Pair(26, 66), Pair(27, 83),
        Pair(13, 73), Pair(13, 69), Pair(11, 69), Pair(14, 63), Pair(21, 55), Pair(27, 72), Pair(17, 52), Pair(25, 78),
        Pair(14, 88), Pair(16, 65), Pair(8, 89), Pair(8, 73), Pair(22, 63), Pair(15, 61), Pair(14, 61), Pair(13, 33),
        Pair(17, 64), Pair(11, 74), Pair(12, 71), Pair(10, 73), Pair(22, 58), Pair(15, 80), Pair(7, 55), Pair(28, 78),
        Pair(9, 85), Pair(10, 72), Pair(11, 66), Pair(13, 71), Pair(13, 65), Pair(19, 69), Pair(6, 92), Pair(7, 88)
      },
      { // Piece 5
        Pair(-18, 9), Pair(13, -8), Pair(63, -6), Pair(64, -52), Pair(13, -42), Pair(-24, -63), Pair(-85, -10), Pair(-39, -12),
        Pair(96, -6), Pair(120, 7), Pair(3, 17), Pair(12, -22), Pair(67, -39), Pair(115, -45), Pair(-24, -11), Pair(-170, 27),
        Pair(-13, 17), Pair(132, -13), Pair(108, -16), Pair(54, -81), Pair(0, 0), Pair(110, -73), Pair(30, -8), Pair(35, -7),
        Pair(93, -13), Pair(69, 0), Pair(13, 3), Pair(7, 39), Pair(8, -65), Pair(-2, -52), Pair(20, -5), Pair(12, 0),
        Pair(24, 0), Pair(6, 15), Pair(21, -14), Pair(64, -33), Pair(35, -36), Pair(62, -33), Pair(-8, -2), Pair(10, 7),
        Pair(105, -9), Pair(16, 4), Pair(-14, 17), Pair(34, -10), Pair(10, -15), Pair(14, -3), Pair(-2, 11), Pair(0, 10),
        Pair(4, 21), Pair(-2, 16), Pair(5, 16), Pair(8, 0), Pair(13, -1), Pair(9, 1), Pair(-1, 21), Pair(-2, 18),
        Pair(5, 19), Pair(-6, 24), Pair(-5, 20), Pair(33, -10), Pair(-3, 6), Pair(13, 5), Pair(1, 18), Pair(1, 17)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 18), Pair(20, 7), Pair(15, 6), Pair(-9, 1), Pair(-25, 19), Pair(6, 2), Pair(-10, 5), Pair(-9, 19),
        Pair(10, 5), Pair(14, 7), Pair(13, 10), Pair(6, 2), Pair(4, -4), Pair(0, 0), Pair(15, -2), Pair(-3, 4),
        Pair(3, 4), Pair(6, 0), Pair(10, 4), Pair(6, -1), Pair(7, 25), Pair(-16, -2), Pair(5, 2), Pair(1, 1),
        Pair(6, 0), Pair(6, -3), Pair(6, -1), Pair(4, 2), Pair(3, 1), Pair(-4, -1), Pair(0, -3), Pair(1, 0),
        Pair(4, 0), Pair(7, -2), Pair(4, -2), Pair(3, 1), Pair(2, 1), Pair(0, 0), Pair(-7, -2), Pair(-4, -2),
        Pair(4, -1), Pair(4, -6), Pair(4, -3), Pair(7, 1), Pair(4, 1), Pair(4, -3), Pair(1, -5), Pair(-5, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(24, 15), Pair(-10, 31), Pair(2, 44), Pair(-21, 44), Pair(50, 5), Pair(82, 26), Pair(-154, 55), Pair(7, 76),
        Pair(6, 34), Pair(10, 38), Pair(7, 36), Pair(7, 3), Pair(44, 44), Pair(16, 21), Pair(3, 54), Pair(-72, -36),
        Pair(17, 25), Pair(16, 34), Pair(-1, 40), Pair(43, 33), Pair(27, 42), Pair(0, 0), Pair(6, 30), Pair(10, 53),
        Pair(18, 29), Pair(25, 41), Pair(25, 31), Pair(30, 21), Pair(-36, -25), Pair(53, 58), Pair(2, -32), Pair(30, 22),
        Pair(11, 38), Pair(19, 40), Pair(13, 31), Pair(12, 40), Pair(-6, 37), Pair(22, 45), Pair(3, 1), Pair(19, 35),
        Pair(14, 53), Pair(25, 31), Pair(16, 36), Pair(0, 34), Pair(17, 40), Pair(0, 20), Pair(12, 40), Pair(-7, 30),
        Pair(5, 40), Pair(13, 37), Pair(9, 39), Pair(11, 31), Pair(10, 40), Pair(6, 33), Pair(21, 42), Pair(8, 31),
        Pair(22, 40), Pair(14, 41), Pair(-4, 40), Pair(11, 37), Pair(15, 27), Pair(16, 28), Pair(-4, 48), Pair(-2, 41)
      },
      { // Piece 2
        Pair(6, 60), Pair(-15, 25), Pair(35, 59), Pair(-43, 35), Pair(-31, 60), Pair(-30, 47), Pair(-38, 56), Pair(-151, -27),
        Pair(-2, 39), Pair(1, 49), Pair(-4, 42), Pair(-23, 66), Pair(-30, 44), Pair(25, 58), Pair(-63, 8), Pair(16, 39),
        Pair(5, 51), Pair(-8, 50), Pair(15, 51), Pair(12, 31), Pair(9, 53), Pair(0, 0), Pair(2, 55), Pair(12, 20),
        Pair(5, 31), Pair(18, 47), Pair(3, 41), Pair(14, 45), Pair(-17, -17), Pair(31, 71), Pair(0, -34), Pair(14, 45),
        Pair(31, 33), Pair(6, 35), Pair(23, 41), Pair(4, 39), Pair(-2, 44), Pair(1, 34), Pair(16, 38), Pair(2, -5),
        Pair(5, 39), Pair(25, 41), Pair(2, 27), Pair(15, 42), Pair(2, 32), Pair(27, 39), Pair(-11, 35), Pair(11, 45),
        Pair(16, 40), Pair(4, 21), Pair(17, 41), Pair(2, 28), Pair(18, 36), Pair(8, 27), Pair(18, 31), Pair(-6, 17),
        Pair(-9, 28), Pair(15, 37), Pair(5, 29), Pair(10, 41), Pair(0, 37), Pair(20, 39), Pair(9, 33), Pair(8, 43)
      },
      { // Piece 3
        Pair(25, 49), Pair(12, 55), Pair(27, 49), Pair(30, 40), Pair(44, 39), Pair(19, 34), Pair(-2, 46), Pair(20, 50),
        Pair(31, 39), Pair(22, 44), Pair(37, 39), Pair(33, 48), Pair(42, 32), Pair(52, 55), Pair(19, 35), Pair(29, 42),
        Pair(25, 35), Pair(22, 37), Pair(21, 32), Pair(32, 33), Pair(16, 34), Pair(0, 0), Pair(22, 36), Pair(5, 50),
        Pair(17, 42), Pair(26, 42), Pair(22, 46), Pair(12, 39), Pair(-6, -2), Pair(40, 31), Pair(11, -53), Pair(1, 46),
        Pair(22, 44), Pair(21, 40), Pair(16, 42), Pair(13, 42), Pair(11, 40), Pair(13, 36), Pair(8, 44), Pair(24, 46),
        Pair(20, 40), Pair(22, 42), Pair(15, 45), Pair(33, 32), Pair(16, 40), Pair(22, 30), Pair(25, 38), Pair(16, 56),
        Pair(11, 44), Pair(8, 49), Pair(17, 41), Pair(20, 36), Pair(9, 38), Pair(29, 32), Pair(17, 32), Pair(20, 32),
        Pair(21, 47), Pair(19, 46), Pair(21, 39), Pair(18, 42), Pair(15, 36), Pair(19, 36), Pair(26, 35), Pair(14, 44)
      },
      { // Piece 4
        Pair(38, 57), Pair(22, 67), Pair(24, 83), Pair(71, 10), Pair(18, 84), Pair(20, 45), Pair(11, 120), Pair(74, -16),
        Pair(46, 51), Pair(27, 65), Pair(42, 78), Pair(28, 90), Pair(27, 71), Pair(37, 65), Pair(47, 56), Pair(34, 91),
        Pair(44, 50), Pair(35, 48), Pair(29, 58), Pair(51, 41), Pair(29, 43), Pair(0, 0), Pair(54, 24), Pair(51, 16),
        Pair(38, 45), Pair(38, 46), Pair(28, 61), Pair(25, 72), Pair(38, -35), Pair(68, 11), Pair(18, 78), Pair(45, 64),
        Pair(43, 36), Pair(22, 81), Pair(22, 54), Pair(22, 72), Pair(26, 65), Pair(54, 26), Pair(35, 79), Pair(38, 58),
        Pair(32, 58), Pair(28, 59), Pair(34, 65), Pair(21, 77), Pair(27, 60), Pair(50, 48), Pair(44, 36), Pair(38, 55),
        Pair(31, 56), Pair(29, 56), Pair(35, 48), Pair(30, 68), Pair(31, 48), Pair(35, 58), Pair(28, 73), Pair(45, 15),
        Pair(44, 16), Pair(36, 41), Pair(33, 43), Pair(33, 50), Pair(38, 33), Pair(28, 35), Pair(26, 39), Pair(24, 30)
      },
      { // Piece 5
        Pair(-78, 1), Pair(-18, -42), Pair(-56, -12), Pair(29, -8), Pair(4, -21), Pair(-15, -73), Pair(-53, -31), Pair(12, -110),
        Pair(-32, -14), Pair(-34, 5), Pair(-153, 23), Pair(-41, 3), Pair(28, -39), Pair(145, -66), Pair(-11, -28), Pair(114, -56),
        Pair(58, 0), Pair(74, -2), Pair(60, -6), Pair(-41, -7), Pair(-45, -66), Pair(0, 0), Pair(68, -61), Pair(43, -19),
        Pair(11, 7), Pair(71, -9), Pair(44, -2), Pair(4, -18), Pair(-150, -201), Pair(-25, -60), Pair(-10, -46), Pair(22, -19),
        Pair(12, -7), Pair(54, -10), Pair(25, 0), Pair(17, -7), Pair(45, -28), Pair(37, -25), Pair(27, -22), Pair(-9, -4),
        Pair(54, -13), Pair(36, -6), Pair(31, 1), Pair(26, -3), Pair(19, -14), Pair(3, -9), Pair(7, -5), Pair(-11, 8),
        Pair(8, -5), Pair(13, -5), Pair(15, 5), Pair(26, 1), Pair(6, -3), Pair(33, -7), Pair(-1, 1), Pair(6, 16),
        Pair(4, 9), Pair(-5, 6), Pair(3, 5), Pair(18, 7), Pair(-8, 19), Pair(-7, 16), Pair(-1, 6), Pair(10, 10)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(22, 8), Pair(11, 15), Pair(35, 7), Pair(17, 9), Pair(-12, 14), Pair(-14, 12), Pair(3, 8), Pair(-7, 18),
        Pair(4, 8), Pair(12, 7), Pair(9, 5), Pair(9, 7), Pair(5, 1), Pair(-13, 6), Pair(0, 0), Pair(3, 11),
        Pair(8, 4), Pair(7, 2), Pair(5, 4), Pair(2, 2), Pair(-2, 0), Pair(6, 22), Pair(-3, -2), Pair(20, 14),
        Pair(6, 3), Pair(7, -2), Pair(2, -1), Pair(1, -2), Pair(-1, 2), Pair(2, 5), Pair(8, -3), Pair(7, 4),
        Pair(4, -3), Pair(4, -1), Pair(4, -2), Pair(2, -3), Pair(4, 0), Pair(6, 0), Pair(0, 0), Pair(1, 3),
        Pair(3, -1), Pair(5, -3), Pair(0, -3), Pair(1, 2), Pair(5, -3), Pair(6, 1), Pair(3, -5), Pair(-2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-49, 35), Pair(-147, 57), Pair(-15, 40), Pair(-88, 70), Pair(31, 26), Pair(-91, 65), Pair(-89, 55), Pair(20, -4),
        Pair(6, 25), Pair(1, 37), Pair(33, 27), Pair(30, 37), Pair(-7, 11), Pair(27, 33), Pair(-58, 0), Pair(2, 62),
        Pair(-12, 33), Pair(12, 29), Pair(10, 37), Pair(3, 36), Pair(7, 47), Pair(18, 44), Pair(0, 0), Pair(-31, 36),
        Pair(12, 22), Pair(11, 28), Pair(16, 36), Pair(7, 34), Pair(14, 27), Pair(-47, 23), Pair(7, 77), Pair(-26, 23),
        Pair(1, 27), Pair(3, 35), Pair(7, 31), Pair(-3, 38), Pair(4, 43), Pair(-16, 30), Pair(-6, 50), Pair(-19, 8),
        Pair(-3, 28), Pair(-3, 31), Pair(2, 34), Pair(0, 37), Pair(-11, 39), Pair(2, 40), Pair(-21, 20), Pair(-2, 37),
        Pair(5, 33), Pair(-7, 29), Pair(-9, 30), Pair(-1, 36), Pair(-8, 30), Pair(7, 38), Pair(8, 26), Pair(8, 40),
        Pair(-21, 32), Pair(-4, 32), Pair(-4, 31), Pair(-3, 24), Pair(-2, 40), Pair(0, 38), Pair(-1, 45), Pair(-9, 40)
      },
      { // Piece 2
        Pair(-32, 49), Pair(-22, 56), Pair(-33, 54), Pair(-32, 65), Pair(-114, 72), Pair(-37, 66), Pair(-5, 56), Pair(54, 36),
        Pair(-6, 54), Pair(-9, 55), Pair(-5, 61), Pair(-48, 62), Pair(-27, 77), Pair(-46, 54), Pair(-76, 73), Pair(-103, 1),
        Pair(7, 44), Pair(-10, 60), Pair(-3, 53), Pair(-9, 69), Pair(-14, 47), Pair(0, 58), Pair(0, 0), Pair(-7, 59),
        Pair(-6, 59), Pair(-2, 47), Pair(-2, 60), Pair(-6, 49), Pair(2, 53), Pair(-46, -30), Pair(-7, 81), Pair(-24, -34),
        Pair(-2, 39), Pair(-7, 57), Pair(-3, 46), Pair(0, 53), Pair(-12, 38), Pair(-15, 50), Pair(-17, 39), Pair(-21, 55),
        Pair(-1, 52), Pair(-2, 43), Pair(3, 50), Pair(-8, 38), Pair(-2, 50), Pair(-3, 40), Pair(0, 45), Pair(-7, 24),
        Pair(1, 42), Pair(9, 44), Pair(-8, 21), Pair(-2, 44), Pair(-11, 36), Pair(3, 48), Pair(4, 33), Pair(3, 53),
        Pair(7, 38), Pair(-18, 28), Pair(6, 41), Pair(-8, 33), Pair(5, 47), Pair(4, 32), Pair(-6, 54), Pair(-2, 56)
      },
      { // Piece 3
        Pair(3, 66), Pair(-11, 71), Pair(-14, 73), Pair(-10, 70), Pair(8, 55), Pair(23, 46), Pair(-10, 55), Pair(34, 47),
        Pair(18, 55), Pair(15, 60), Pair(11, 61), Pair(19, 61), Pair(14, 58), Pair(4, 49), Pair(129, 41), Pair(16, 53),
        Pair(15, 43), Pair(6, 50), Pair(17, 50), Pair(11, 51), Pair(3, 66), Pair(3, 51), Pair(0, 0), Pair(-23, 61),
        Pair(17, 47), Pair(13, 55), Pair(18, 52), Pair(2, 58), Pair(15, 39), Pair(13, -51), Pair(14, 57), Pair(32, -44),
        Pair(-4, 55), Pair(9, 51), Pair(-3, 56), Pair(0, 56), Pair(4, 49), Pair(-1, 49), Pair(-16, 56), Pair(-23, 49),
        Pair(9, 50), Pair(9, 54), Pair(9, 56), Pair(6, 49), Pair(5, 50), Pair(-6, 50), Pair(1, 49), Pair(-6, 50),
        Pair(11, 52), Pair(14, 44), Pair(11, 55), Pair(15, 47), Pair(13, 48), Pair(12, 38), Pair(6, 38), Pair(7, 36),
        Pair(11, 54), Pair(7, 55), Pair(11, 50), Pair(8, 53), Pair(8, 48), Pair(8, 47), Pair(4, 51), Pair(5, 42)
      },
      { // Piece 4
        Pair(-19, 75), Pair(-31, 94), Pair(-13, 91), Pair(0, 82), Pair(-14, 72), Pair(42, 109), Pair(-16, 101), Pair(24, 108),
        Pair(14, 63), Pair(-3, 78), Pair(5, 78), Pair(-20, 109), Pair(-23, 121), Pair(6, 89), Pair(50, 67), Pair(28, 58),
        Pair(8, 64), Pair(12, 53), Pair(-1, 79), Pair(12, 52), Pair(5, 59), Pair(-24, 80), Pair(0, 0), Pair(-26, 35),
        Pair(6, 59), Pair(2, 70), Pair(8, 60), Pair(4, 82), Pair(-12, 97), Pair(-29, 66), Pair(-8, 40), Pair(-1, 38),
        Pair(6, 59), Pair(4, 71), Pair(6, 73), Pair(-6, 96), Pair(-2, 90), Pair(2, 60), Pair(-5, 68), Pair(-16, 90),
        Pair(5, 69), Pair(1, 77), Pair(1, 80), Pair(-9, 96), Pair(1, 72), Pair(-10, 96), Pair(12, 53), Pair(3, 73),
        Pair(-6, 62), Pair(-4, 68), Pair(1, 60), Pair(1, 70), Pair(-4, 73), Pair(4, 75), Pair(6, 72), Pair(13, 73),
        Pair(-2, 83), Pair(3, 54), Pair(6, 45), Pair(4, 53), Pair(5, 69), Pair(0, 65), Pair(-5, 62), Pair(-10, 108)
      },
      { // Piece 5
        Pair(235, -70), Pair(75, -32), Pair(-35, -13), Pair(108, -8), Pair(6, -7), Pair(29, -20), Pair(87, -45), Pair(-31, -127),
        Pair(103, -11), Pair(33, -12), Pair(157, -35), Pair(78, -20), Pair(130, -45), Pair(14, -24), Pair(-32, -16), Pair(152, -44),
        Pair(134, -17), Pair(120, -7), Pair(5, 0), Pair(29, -10), Pair(23, -20), Pair(7, -45), Pair(0, 0), Pair(117, -61),
        Pair(26, 0), Pair(93, -8), Pair(83, -10), Pair(70, -12), Pair(-12, -7), Pair(8, 27), Pair(20, -69), Pair(-70, -262),
        Pair(118, -12), Pair(54, -12), Pair(39, -8), Pair(16, -3), Pair(16, -9), Pair(45, -18), Pair(1, -19), Pair(-22, -18),
        Pair(68, -8), Pair(45, -11), Pair(14, 0), Pair(31, -1), Pair(3, 4), Pair(18, -2), Pair(-6, -5), Pair(-36, 13),
        Pair(8, 0), Pair(-5, 4), Pair(1, 6), Pair(10, 0), Pair(-12, 16), Pair(12, -1), Pair(-1, 3), Pair(-3, 8),
        Pair(-28, 5), Pair(-22, 6), Pair(-16, 7), Pair(-9, 11), Pair(-7, 4), Pair(-5, 4), Pair(-4, 9), Pair(-4, 6)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(19, 11), Pair(5, 11), Pair(27, 3), Pair(-1, 15), Pair(-4, 10), Pair(-13, 16), Pair(-21, 5), Pair(23, 17),
        Pair(6, 9), Pair(10, 4), Pair(13, 2), Pair(8, 4), Pair(-3, 8), Pair(-22, 5), Pair(-19, 5), Pair(0, 0),
        Pair(5, 6), Pair(8, 0), Pair(7, 2), Pair(1, 4), Pair(-6, 2), Pair(-8, 2), Pair(3, -6), Pair(-4, -1),
        Pair(2, -3), Pair(5, -3), Pair(3, 0), Pair(-3, 0), Pair(1, 3), Pair(1, 0), Pair(-2, -4), Pair(-4, 1),
        Pair(3, -3), Pair(3, -3), Pair(2, -4), Pair(-1, -4), Pair(1, 1), Pair(2, 2), Pair(0, -3), Pair(0, 0),
        Pair(1, -2), Pair(-3, -3), Pair(-3, -3), Pair(-3, -5), Pair(1, 1), Pair(2, -1), Pair(4, -3), Pair(-2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-81, 13), Pair(-88, 51), Pair(-94, 45), Pair(-22, 28), Pair(-27, 54), Pair(24, 65), Pair(-15, 55), Pair(31, 74),
        Pair(-15, 26), Pair(4, 23), Pair(9, 26), Pair(9, 36), Pair(36, 34), Pair(-7, 14), Pair(12, 12), Pair(-22, 22),
        Pair(14, 14), Pair(7, 11), Pair(-1, 29), Pair(11, 35), Pair(8, 25), Pair(7, 48), Pair(-15, 48), Pair(0, 0),
        Pair(-3, 24), Pair(12, 22), Pair(14, 27), Pair(16, 34), Pair(14, 33), Pair(10, 34), Pair(-32, -10), Pair(28, 64),
        Pair(1, 17), Pair(8, 18), Pair(6, 21), Pair(7, 27), Pair(7, 33), Pair(18, 32), Pair(-12, 43), Pair(-3, 44),
        Pair(-4, 21), Pair(-3, 17), Pair(6, 25), Pair(3, 26), Pair(10, 30), Pair(-4, 33), Pair(9, 43), Pair(-20, 1),
        Pair(13, 14), Pair(-5, 37), Pair(3, 13), Pair(-2, 25), Pair(1, 36), Pair(-6, 29), Pair(8, 33), Pair(-4, 49),
        Pair(-17, 4), Pair(-1, 10), Pair(-1, 16), Pair(-4, 25), Pair(-9, 29), Pair(2, 27), Pair(-9, 33), Pair(15, 23)
      },
      { // Piece 2
        Pair(-36, 72), Pair(-89, 76), Pair(-58, 64), Pair(-93, 65), Pair(-77, 86), Pair(-62, 65), Pair(-20, 59), Pair(20, 53),
        Pair(-44, 65), Pair(-4, 60), Pair(-21, 64), Pair(-45, 77), Pair(-47, 64), Pair(-18, 66), Pair(-47, 68), Pair(29, 57),
        Pair(-1, 54), Pair(-13, 51), Pair(-6, 73), Pair(-6, 59), Pair(4, 68), Pair(-39, 75), Pair(0, 59), Pair(0, 0),
        Pair(-10, 44), Pair(2, 54), Pair(-17, 53), Pair(3, 59), Pair(-5, 60), Pair(0, 53), Pair(-22, -30), Pair(14, 69),
        Pair(-5, 48), Pair(-7, 48), Pair(6, 49), Pair(3, 44), Pair(9, 56), Pair(-3, 36), Pair(-7, 51), Pair(-7, 44),
        Pair(-4, 33), Pair(8, 51), Pair(3, 41), Pair(6, 49), Pair(-3, 35), Pair(6, 54), Pair(-2, 44), Pair(17, 54),
        Pair(-10, 49), Pair(5, 36), Pair(2, 51), Pair(-11, 33), Pair(-4, 49), Pair(-2, 36), Pair(11, 47), Pair(6, 26),
        Pair(-3, 36), Pair(-4, 51), Pair(-8, 35), Pair(-4, 50), Pair(1, 43), Pair(13, 46), Pair(-3, 45), Pair(12, 57)
      },
      { // Piece 3
        Pair(1, 73), Pair(-8, 79), Pair(-17, 82), Pair(-8, 77), Pair(30, 65), Pair(4, 74), Pair(9, 75), Pair(70, 62),
        Pair(15, 74), Pair(16, 71), Pair(7, 73), Pair(19, 68), Pair(7, 78), Pair(16, 63), Pair(43, 58), Pair(149, 56),
        Pair(15, 67), Pair(17, 72), Pair(7, 65), Pair(19, 66), Pair(25, 61), Pair(-5, 76), Pair(7, 73), Pair(0, 0),
        Pair(13, 63), Pair(2, 73), Pair(10, 72), Pair(18, 67), Pair(4, 72), Pair(-1, 73), Pair(26, -23), Pair(-10, 68),
        Pair(16, 64), Pair(5, 65), Pair(9, 68), Pair(4, 66), Pair(-2, 66), Pair(11, 57), Pair(10, 68), Pair(-13, 61),
        Pair(11, 59), Pair(15, 64), Pair(21, 57), Pair(12, 60), Pair(7, 62), Pair(1, 67), Pair(8, 70), Pair(-11, 60),
        Pair(17, 57), Pair(0, 69), Pair(9, 59), Pair(18, 52), Pair(15, 56), Pair(11, 57), Pair(9, 67), Pair(1, 55),
        Pair(12, 65), Pair(5, 61), Pair(13, 62), Pair(9, 64), Pair(9, 61), Pair(11, 55), Pair(8, 66), Pair(-4, 64)
      },
      { // Piece 4
        Pair(-8, 116), Pair(-25, 131), Pair(-2, 121), Pair(13, 106), Pair(22, 104), Pair(11, 125), Pair(106, 68), Pair(-33, 137),
        Pair(14, 107), Pair(15, 102), Pair(18, 113), Pair(-34, 145), Pair(5, 138), Pair(-18, 167), Pair(6, 135), Pair(21, 109),
        Pair(12, 93), Pair(6, 107), Pair(18, 108), Pair(4, 128), Pair(-5, 147), Pair(-4, 161), Pair(-38, 151), Pair(0, 0),
        Pair(16, 83), Pair(11, 110), Pair(18, 104), Pair(5, 132), Pair(13, 122), Pair(21, 140), Pair(24, 12), Pair(14, 89),
        Pair(7, 106), Pair(13, 100), Pair(-1, 119), Pair(4, 132), Pair(17, 115), Pair(11, 127), Pair(11, 97), Pair(7, 81),
        Pair(14, 96), Pair(4, 95), Pair(12, 110), Pair(14, 102), Pair(11, 108), Pair(8, 114), Pair(20, 92), Pair(16, 52),
        Pair(5, 108), Pair(14, 81), Pair(9, 85), Pair(16, 91), Pair(8, 104), Pair(12, 95), Pair(22, 85), Pair(28, 64),
        Pair(13, 80), Pair(9, 90), Pair(7, 96), Pair(15, 84), Pair(14, 79), Pair(3, 110), Pair(-12, 78), Pair(14, 53)
      },
      { // Piece 5
        Pair(-22, -21), Pair(-3, -42), Pair(-115, -5), Pair(-59, -18), Pair(90, -67), Pair(-182, -12), Pair(85, -81), Pair(14, -54),
        Pair(77, -5), Pair(53, 2), Pair(-45, 13), Pair(-104, 0), Pair(-166, 4), Pair(56, -32), Pair(-91, 3), Pair(45, -50),
        Pair(1, -32), Pair(-25, 5), Pair(43, -11), Pair(105, -20), Pair(-43, 10), Pair(3, -18), Pair(-48, -34), Pair(0, 0),
        Pair(111, -20), Pair(79, -14), Pair(63, -20), Pair(18, -5), Pair(45, -1), Pair(-41, 3), Pair(-79, -103), Pair(119, -78),
        Pair(0, -14), Pair(89, -23), Pair(67, -17), Pair(55, -4), Pair(16, -5), Pair(8, -9), Pair(57, -19), Pair(39, -25),
        Pair(51, -17), Pair(34, -17), Pair(31, -8), Pair(26, -4), Pair(27, -3), Pair(8, 1), Pair(20, -5), Pair(9, -8),
        Pair(-13, 13), Pair(-4, -9), Pair(12, -6), Pair(15, -4), Pair(-6, 11), Pair(9, 7), Pair(-3, 5), Pair(-1, 5),
        Pair(-4, -17), Pair(-20, -5), Pair(-7, 5), Pair(15, -4), Pair(1, 8), Pair(-5, 13), Pair(6, 6), Pair(-4, 7)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(-25, 17), Pair(-12, 11), Pair(-5, 14), Pair(-14, 29), Pair(-8, 18), Pair(-19, 26), Pair(-3, 25),
        Pair(-22, -36), Pair(-6, 2), Pair(-4, 2), Pair(8, 5), Pair(2, 6), Pair(-5, 16), Pair(2, 13), Pair(-11, 16),
        Pair(-9, -6), Pair(-4, 10), Pair(-4, 3), Pair(2, 0), Pair(-3, 7), Pair(-4, 6), Pair(-2, 6), Pair(-2, 11),
        Pair(-6, 3), Pair(-2, 5), Pair(-3, 3), Pair(-1, 3), Pair(5, 4), Pair(-2, 7), Pair(-1, 4), Pair(1, 4),
        Pair(-2, 4), Pair(1, 3), Pair(0, 1), Pair(-1, -1), Pair(-1, 6), Pair(-4, 2), Pair(-2, 2), Pair(-3, 1),
        Pair(0, 0), Pair(3, 3), Pair(-1, 0), Pair(-5, 0), Pair(-2, 0), Pair(-5, 1), Pair(-3, 4), Pair(-1, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-79, -21), Pair(84, 21), Pair(-84, 86), Pair(-2, 50), Pair(23, 30), Pair(-51, 62), Pair(51, 29), Pair(35, -40),
        Pair(0, 0), Pair(9, 49), Pair(24, 44), Pair(23, 26), Pair(20, 46), Pair(39, 37), Pair(13, 27), Pair(51, 14),
        Pair(33, 65), Pair(-131, 78), Pair(-3, 59), Pair(13, 48), Pair(26, 33), Pair(49, 30), Pair(30, 25), Pair(34, 15),
        Pair(18, 49), Pair(-11, 57), Pair(1, 53), Pair(7, 46), Pair(18, 42), Pair(21, 43), Pair(22, 36), Pair(21, 30),
        Pair(-7, 29), Pair(-16, 51), Pair(-5, 45), Pair(8, 52), Pair(16, 42), Pair(15, 38), Pair(24, 41), Pair(13, 42),
        Pair(-3, 50), Pair(-4, 49), Pair(-2, 49), Pair(4, 43), Pair(8, 36), Pair(5, 43), Pair(13, 40), Pair(14, 48),
        Pair(5, 36), Pair(-13, 48), Pair(2, 35), Pair(3, 38), Pair(5, 39), Pair(2, 48), Pair(1, 38), Pair(7, 46),
        Pair(-113, 89), Pair(-4, 48), Pair(-3, 54), Pair(3, 29), Pair(0, 43), Pair(9, 23), Pair(8, 41), Pair(-5, 70)
      },
      { // Piece 2
        Pair(7, 63), Pair(-25, 103), Pair(-5, 81), Pair(-40, 88), Pair(-60, 88), Pair(-34, 86), Pair(8, 74), Pair(-47, 77),
        Pair(0, 0), Pair(-10, 67), Pair(3, 66), Pair(-43, 95), Pair(-24, 90), Pair(-1, 84), Pair(-10, 91), Pair(4, 59),
        Pair(9, 92), Pair(-198, 221), Pair(-28, 82), Pair(-9, 85), Pair(-11, 80), Pair(21, 68), Pair(16, 69), Pair(13, 54),
        Pair(16, 62), Pair(-29, 74), Pair(-3, 80), Pair(-1, 66), Pair(5, 82), Pair(6, 72), Pair(9, 65), Pair(3, 51),
        Pair(-8, 67), Pair(-19, 69), Pair(-6, 67), Pair(-2, 70), Pair(1, 59), Pair(1, 70), Pair(-4, 67), Pair(6, 59),
        Pair(6, 72), Pair(-5, 71), Pair(-1, 67), Pair(0, 68), Pair(3, 62), Pair(-4, 54), Pair(6, 66), Pair(9, 46),
        Pair(-3, 93), Pair(4, 66), Pair(1, 61), Pair(1, 63), Pair(-4, 58), Pair(-1, 57), Pair(5, 51), Pair(10, 64),
        Pair(-1, 71), Pair(-10, 73), Pair(2, 69), Pair(-3, 62), Pair(2, 61), Pair(-4, 59), Pair(1, 68), Pair(4, 44)
      },
      { // Piece 3
        Pair(-6, 113), Pair(-24, 122), Pair(-17, 118), Pair(-14, 112), Pair(-12, 105), Pair(6, 111), Pair(12, 103), Pair(4, 116),
        Pair(0, 0), Pair(-18, 131), Pair(-25, 137), Pair(-10, 121), Pair(-15, 127), Pair(-12, 122), Pair(18, 101), Pair(8, 115),
        Pair(-13, 127), Pair(42, -186), Pair(-17, 113), Pair(-14, 107), Pair(-15, 107), Pair(0, 103), Pair(-2, 105), Pair(2, 106),
        Pair(-23, 121), Pair(-23, 108), Pair(-17, 109), Pair(-28, 114), Pair(-17, 114), Pair(-4, 96), Pair(13, 93), Pair(-5, 109),
        Pair(-28, 103), Pair(-38, 90), Pair(-28, 109), Pair(-20, 105), Pair(-21, 105), Pair(-11, 97), Pair(13, 96), Pair(3, 89),
        Pair(-25, 106), Pair(-20, 96), Pair(-26, 106), Pair(-18, 105), Pair(-19, 98), Pair(-8, 95), Pair(1, 103), Pair(7, 101),
        Pair(-18, 100), Pair(-22, 103), Pair(-21, 109), Pair(-19, 88), Pair(-18, 103), Pair(-13, 106), Pair(-4, 105), Pair(7, 93),
        Pair(-20, 100), Pair(-20, 93), Pair(-15, 97), Pair(-16, 99), Pair(-14, 102), Pair(-14, 102), Pair(-11, 110), Pair(-6, 105)
      },
      { // Piece 4
        Pair(-80, 248), Pair(4, 193), Pair(-7, 219), Pair(-2, 205), Pair(32, 193), Pair(-2, 198), Pair(43, 175), Pair(38, 199),
        Pair(0, 0), Pair(29, 196), Pair(12, 231), Pair(-3, 224), Pair(3, 233), Pair(7, 233), Pair(21, 191), Pair(36, 179),
        Pair(32, 191), Pair(-126, -52), Pair(15, 195), Pair(5, 203), Pair(20, 186), Pair(30, 185), Pair(45, 151), Pair(40, 183),
        Pair(22, 183), Pair(18, 171), Pair(19, 195), Pair(9, 199), Pair(7, 211), Pair(27, 202), Pair(31, 186), Pair(38, 176),
        Pair(15, 183), Pair(9, 166), Pair(6, 185), Pair(13, 183), Pair(15, 179), Pair(25, 174), Pair(24, 179), Pair(28, 174),
        Pair(17, 190), Pair(11, 173), Pair(12, 178), Pair(12, 180), Pair(10, 177), Pair(17, 175), Pair(32, 166), Pair(25, 178),
        Pair(14, 177), Pair(10, 169), Pair(12, 172), Pair(11, 173), Pair(17, 166), Pair(11, 179), Pair(10, 151), Pair(53, 125),
        Pair(9, 185), Pair(10, 142), Pair(7, 184), Pair(10, 166), Pair(7, 169), Pair(6, 172), Pair(46, 99), Pair(30, 133)
      },
      { // Piece 5
        Pair(35, 25), Pair(-37, 24), Pair(-22, 12), Pair(40, -15), Pair(30, -48), Pair(81, -25), Pair(27, -32), Pair(59, 64),
        Pair(0, 0), Pair(8, -59), Pair(-67, 30), Pair(-29, -14), Pair(2, -10), Pair(39, -8), Pair(117, -14), Pair(70, -38),
        Pair(-4, -86), Pair(0, 0), Pair(-132, 7), Pair(-52, 13), Pair(-89, 14), Pair(20, 2), Pair(35, -5), Pair(-37, -9),
        Pair(-126, -39), Pair(-32, -18), Pair(-57, -21), Pair(-6, -10), Pair(27, -9), Pair(-1, -1), Pair(-11, 0), Pair(-31, 5),
        Pair(-4, -37), Pair(-56, -9), Pair(-19, -8), Pair(-39, -8), Pair(8, -9), Pair(3, -1), Pair(-5, 0), Pair(4, -9),
        Pair(-27, -18), Pair(-40, -12), Pair(-15, -5), Pair(1, -7), Pair(-16, -6), Pair(-7, 0), Pair(2, -8), Pair(-8, 7),
        Pair(-15, -9), Pair(-10, 1), Pair(-2, 1), Pair(6, -7), Pair(-2, -5), Pair(18, -12), Pair(-2, -2), Pair(2, -9),
        Pair(-21, 35), Pair(7, 8), Pair(8, 3), Pair(15, -5), Pair(8, -11), Pair(14, -11), Pair(3, -10), Pair(5, -13)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 10), Pair(0, 0), Pair(-19, 19), Pair(15, -1), Pair(5, 14), Pair(-10, 22), Pair(14, 4), Pair(-3, 16),
        Pair(4, 24), Pair(-35, -34), Pair(-9, 9), Pair(0, 5), Pair(0, 8), Pair(5, 12), Pair(1, 17), Pair(-7, 17),
        Pair(7, 5), Pair(-10, -5), Pair(0, 15), Pair(-2, 2), Pair(-4, 9), Pair(-1, 9), Pair(-4, 9), Pair(-1, 10),
        Pair(5, 2), Pair(-9, -5), Pair(4, 5), Pair(-3, 2), Pair(-5, 4), Pair(-3, 6), Pair(-4, 5), Pair(-2, 8),
        Pair(3, 3), Pair(-4, 1), Pair(-1, 6), Pair(-4, 1), Pair(-3, 3), Pair(-5, 2), Pair(-6, 5), Pair(-7, 1),
        Pair(1, 0), Pair(0, 0), Pair(1, 0), Pair(-1, 0), Pair(-4, -1), Pair(-6, 0), Pair(-5, 1), Pair(-2, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-34, 55), Pair(-125, -105), Pair(8, 54), Pair(-49, 35), Pair(34, 29), Pair(0, 37), Pair(-133, 51), Pair(-36, 71),
        Pair(-15, -1), Pair(0, 0), Pair(-18, 38), Pair(-10, 55), Pair(3, 34), Pair(3, 53), Pair(5, 47), Pair(23, 21),
        Pair(76, -36), Pair(14, 69), Pair(-260, 152), Pair(8, 40), Pair(5, 46), Pair(14, 45), Pair(4, 45), Pair(14, 32),
        Pair(-8, 50), Pair(-6, 52), Pair(-30, 60), Pair(-1, 55), Pair(-3, 37), Pair(9, 50), Pair(4, 43), Pair(3, 49),
        Pair(-9, 50), Pair(-21, 21), Pair(-25, 57), Pair(-10, 48), Pair(2, 50), Pair(3, 39), Pair(12, 41), Pair(11, 41),
        Pair(4, 56), Pair(-5, 41), Pair(-3, 48), Pair(-4, 42), Pair(-2, 38), Pair(2, 39), Pair(0, 45), Pair(5, 41),
        Pair(9, 58), Pair(-8, 45), Pair(5, 38), Pair(-2, 46), Pair(2, 42), Pair(1, 35), Pair(2, 25), Pair(4, 38),
        Pair(31, -9), Pair(2, 43), Pair(17, 40), Pair(3, 46), Pair(6, 43), Pair(5, 41), Pair(2, 58), Pair(-17, 40)
      },
      { // Piece 2
        Pair(0, 0), Pair(-5, 70), Pair(-66, 86), Pair(-19, 62), Pair(-34, 74), Pair(-24, 71), Pair(-41, 95), Pair(-27, 99),
        Pair(-9, 46), Pair(0, 0), Pair(-11, 67), Pair(-72, 88), Pair(-17, 80), Pair(-8, 83), Pair(6, 71), Pair(-13, 57),
        Pair(-56, 10), Pair(-4, 76), Pair(-195, -41), Pair(-12, 64), Pair(-26, 81), Pair(-4, 66), Pair(-21, 74), Pair(11, 51),
        Pair(-12, 53), Pair(-19, 68), Pair(-50, 67), Pair(-23, 79), Pair(3, 69), Pair(-8, 72), Pair(-1, 57), Pair(-5, 61),
        Pair(-24, 55), Pair(-14, 56), Pair(-31, 63), Pair(-7, 54), Pair(-9, 66), Pair(-5, 56), Pair(-16, 61), Pair(9, 53),
        Pair(-2, 53), Pair(-14, 67), Pair(-5, 58), Pair(-9, 57), Pair(-2, 45), Pair(-9, 61), Pair(-2, 51), Pair(-3, 54),
        Pair(-11, 74), Pair(5, 52), Pair(-15, 61), Pair(-3, 52), Pair(-9, 57), Pair(2, 40), Pair(0, 47), Pair(-5, 49),
        Pair(5, 57), Pair(7, 58), Pair(2, 59), Pair(-13, 68), Pair(-1, 56), Pair(-5, 56), Pair(3, 46), Pair(-7, 66)
      },
      { // Piece 3
        Pair(-2, 61), Pair(-21, 95), Pair(3, 76), Pair(27, 63), Pair(6, 72), Pair(-25, 89), Pair(-53, 84), Pair(-10, 81),
        Pair(-25, 78), Pair(0, 0), Pair(-16, 94), Pair(5, 90), Pair(-10, 85), Pair(-13, 89), Pair(-18, 86), Pair(-19, 85),
        Pair(-160, -12), Pair(-15, 87), Pair(-111, 33), Pair(-2, 65), Pair(-4, 75), Pair(-3, 73), Pair(1, 67), Pair(1, 74),
        Pair(-15, 67), Pair(-12, 83), Pair(-33, 72), Pair(-15, 82), Pair(-13, 80), Pair(-5, 72), Pair(4, 75), Pair(8, 59),
        Pair(-15, 52), Pair(-15, 79), Pair(-32, 67), Pair(-18, 72), Pair(-19, 76), Pair(-10, 75), Pair(-3, 63), Pair(11, 63),
        Pair(-12, 58), Pair(-12, 71), Pair(-21, 72), Pair(-12, 68), Pair(-9, 70), Pair(-7, 73), Pair(12, 63), Pair(13, 67),
        Pair(-15, 75), Pair(4, 58), Pair(-26, 65), Pair(-5, 64), Pair(-12, 65), Pair(-5, 64), Pair(-4, 78), Pair(-9, 76),
        Pair(-14, 71), Pair(-6, 66), Pair(-21, 64), Pair(-10, 71), Pair(-11, 71), Pair(-8, 72), Pair(-8, 79), Pair(-1, 80)
      },
      { // Piece 4
        Pair(14, 100), Pair(7, 138), Pair(11, 139), Pair(15, 157), Pair(39, 109), Pair(17, 132), Pair(-46, 162), Pair(26, 120),
        Pair(39, 95), Pair(0, 0), Pair(15, 132), Pair(25, 135), Pair(16, 152), Pair(-18, 174), Pair(10, 140), Pair(33, 106),
        Pair(-164, -2), Pair(18, 116), Pair(-189, -109), Pair(27, 127), Pair(20, 130), Pair(21, 134), Pair(31, 122), Pair(31, 140),
        Pair(24, 96), Pair(25, 112), Pair(12, 133), Pair(23, 121), Pair(22, 133), Pair(11, 148), Pair(23, 131), Pair(26, 133),
        Pair(15, 103), Pair(12, 127), Pair(5, 118), Pair(9, 135), Pair(17, 121), Pair(15, 134), Pair(17, 120), Pair(14, 136),
        Pair(16, 114), Pair(13, 129), Pair(17, 109), Pair(10, 114), Pair(11, 111), Pair(14, 128), Pair(14, 131), Pair(18, 133),
        Pair(17, 103), Pair(15, 113), Pair(8, 121), Pair(12, 112), Pair(13, 115), Pair(19, 108), Pair(12, 127), Pair(8, 150),
        Pair(18, 118), Pair(15, 127), Pair(12, 105), Pair(15, 112), Pair(5, 120), Pair(10, 111), Pair(26, 103), Pair(15, 126)
      },
      { // Piece 5
        Pair(-5, 1), Pair(40, -76), Pair(-61, -16), Pair(17, -23), Pair(-32, -17), Pair(96, -25), Pair(-50, -20), Pair(38, -74),
        Pair(-57, -41), Pair(0, 0), Pair(-37, -58), Pair(63, -38), Pair(-21, -15), Pair(-3, 8), Pair(-26, -8), Pair(38, 21),
        Pair(0, 0), Pair(-102, -71), Pair(0, 0), Pair(-104, -4), Pair(-166, 16), Pair(30, -12), Pair(-10, 0), Pair(37, -13),
        Pair(-78, -24), Pair(-50, -58), Pair(-24, -28), Pair(-140, -11), Pair(-1, 0), Pair(6, 0), Pair(-28, 6), Pair(8, -1),
        Pair(-34, -27), Pair(-58, -32), Pair(-14, -30), Pair(-30, -7), Pair(-4, -11), Pair(32, -9), Pair(2, -1), Pair(57, -9),
        Pair(-4, -12), Pair(-22, -37), Pair(-22, -14), Pair(5, -10), Pair(6, -6), Pair(2, 2), Pair(2, 2), Pair(8, 2),
        Pair(-32, -8), Pair(-22, -15), Pair(5, -14), Pair(11, 0), Pair(6, -5), Pair(15, -9), Pair(4, -5), Pair(7, -2),
        Pair(20, -14), Pair(1, -3), Pair(11, -7), Pair(11, 1), Pair(6, -3), Pair(21, -8), Pair(0, -5), Pair(4, -2)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, -5), Pair(-9, -3), Pair(0, 0), Pair(-4, 11), Pair(-4, 6), Pair(-1, 17), Pair(0, 13), Pair(-15, 26),
        Pair(5, 9), Pair(-6, 16), Pair(-34, -35), Pair(-1, 29), Pair(-3, 8), Pair(4, 18), Pair(8, 12), Pair(-5, 10),
        Pair(-1, 2), Pair(6, 8), Pair(-9, -5), Pair(2, 12), Pair(-5, 10), Pair(-1, 7), Pair(2, 9), Pair(-3, 13),
        Pair(-2, 2), Pair(1, -1), Pair(-10, -7), Pair(-1, 7), Pair(-5, 1), Pair(-1, 6), Pair(0, 4), Pair(2, 5),
        Pair(-2, 3), Pair(-4, -3), Pair(-5, -3), Pair(-3, 4), Pair(-2, 3), Pair(-5, 3), Pair(-3, 3), Pair(-2, 1),
        Pair(-2, 4), Pair(-4, -2), Pair(0, 0), Pair(-6, -2), Pair(-2, -2), Pair(-6, -1), Pair(2, 1), Pair(2, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-115, 11), Pair(-7, 60), Pair(-52, -34), Pair(-49, 22), Pair(44, -26), Pair(-42, 74), Pair(-13, 43), Pair(35, 20),
        Pair(6, 26), Pair(-21, 17), Pair(0, 0), Pair(-19, 58), Pair(-1, 44), Pair(-7, 24), Pair(14, 47), Pair(37, 26),
        Pair(34, 29), Pair(74, -105), Pair(-15, 77), Pair(-346, 170), Pair(0, 35), Pair(-6, 53), Pair(9, 34), Pair(-8, 46),
        Pair(-6, 52), Pair(-26, 26), Pair(6, 44), Pair(-38, 45), Pair(-3, 47), Pair(-3, 47), Pair(4, 41), Pair(4, 32),
        Pair(-11, 30), Pair(-14, 57), Pair(-11, 34), Pair(-26, 43), Pair(-10, 34), Pair(-3, 48), Pair(-4, 33), Pair(-1, 38),
        Pair(-8, 41), Pair(-2, 45), Pair(-7, 44), Pair(-5, 57), Pair(-7, 37), Pair(-4, 35), Pair(1, 40), Pair(3, 39),
        Pair(2, 33), Pair(-12, 29), Pair(-6, 34), Pair(-6, 42), Pair(-4, 39), Pair(-3, 33), Pair(6, 33), Pair(-1, 29),
        Pair(27, 12), Pair(-6, 51), Pair(10, 35), Pair(-13, 46), Pair(6, 50), Pair(0, 30), Pair(4, 43), Pair(-11, -16)
      },
      { // Piece 2
        Pair(-2, 48), Pair(-34, -8), Pair(-20, 85), Pair(-81, 42), Pair(-16, 72), Pair(-44, 50), Pair(-112, 74), Pair(-30, 66),
        Pair(15, -15), Pair(-20, 51), Pair(0, 0), Pair(-51, 85), Pair(-11, 59), Pair(9, 66), Pair(-16, 67), Pair(-11, 54),
        Pair(-1, 45), Pair(22, -68), Pair(-2, 87), Pair(-354, 90), Pair(-16, 75), Pair(-20, 53), Pair(-9, 59), Pair(5, 37),
        Pair(3, 34), Pair(-30, 65), Pair(-18, 42), Pair(-33, 56), Pair(-7, 51), Pair(-12, 63), Pair(-5, 57), Pair(-1, 63),
        Pair(-5, 42), Pair(-23, 46), Pair(-14, 63), Pair(-37, 54), Pair(-6, 60), Pair(-15, 52), Pair(-3, 58), Pair(5, 43),
        Pair(-10, 30), Pair(-11, 58), Pair(-10, 53), Pair(-9, 59), Pair(-12, 43), Pair(-3, 52), Pair(-3, 46), Pair(-5, 51),
        Pair(-24, 92), Pair(-1, 40), Pair(8, 55), Pair(-6, 46), Pair(-4, 58), Pair(-11, 41), Pair(2, 43), Pair(-1, 52),
        Pair(-5, 55), Pair(2, 63), Pair(-8, 49), Pair(-5, 64), Pair(-5, 45), Pair(-2, 56), Pair(-10, 65), Pair(1, 36)
      },
      { // Piece 3
        Pair(-19, 52), Pair(-32, 68), Pair(-28, 60), Pair(-36, 63), Pair(-2, 50), Pair(2, 62), Pair(-26, 65), Pair(-51, 74),
        Pair(-13, 61), Pair(-30, 59), Pair(0, 0), Pair(-36, 80), Pair(-7, 65), Pair(-31, 82), Pair(-40, 69), Pair(-29, 60),
        Pair(-26, 53), Pair(82, -142), Pair(-19, 68), Pair(-86, 27), Pair(-16, 57), Pair(-8, 56), Pair(-29, 63), Pair(-11, 63),
        Pair(-19, 62), Pair(-25, 56), Pair(-11, 55), Pair(-37, 58), Pair(-14, 59), Pair(-2, 61), Pair(1, 44), Pair(-1, 57),
        Pair(-15, 55), Pair(-17, 42), Pair(-15, 43), Pair(-35, 44), Pair(-11, 60), Pair(-24, 55), Pair(-8, 54), Pair(-5, 59),
        Pair(-17, 59), Pair(-16, 53), Pair(-20, 59), Pair(-28, 62), Pair(-16, 61), Pair(-12, 55), Pair(-13, 49), Pair(4, 58),
        Pair(-11, 48), Pair(-22, 52), Pair(-11, 48), Pair(-25, 52), Pair(-18, 59), Pair(-11, 58), Pair(-5, 59), Pair(12, 40),
        Pair(-18, 50), Pair(-20, 52), Pair(-16, 52), Pair(-20, 47), Pair(-19, 56), Pair(-16, 60), Pair(-11, 55), Pair(-9, 58)
      },
      { // Piece 4
        Pair(52, 45), Pair(-22, 77), Pair(75, 20), Pair(-17, 106), Pair(-14, 114), Pair(-119, 199), Pair(-18, 93), Pair(-38, 86),
        Pair(17, 88), Pair(5, 88), Pair(0, 0), Pair(16, 73), Pair(-5, 142), Pair(-17, 108), Pair(-31, 67), Pair(-9, 56),
        Pair(30, 49), Pair(-152, 3), Pair(22, 110), Pair(-145, -36), Pair(15, 79), Pair(21, 62), Pair(-6, 73), Pair(13, 74),
        Pair(18, 87), Pair(10, 94), Pair(28, 65), Pair(14, 97), Pair(20, 83), Pair(13, 93), Pair(7, 83), Pair(22, 70),
        Pair(13, 82), Pair(11, 74), Pair(18, 79), Pair(4, 75), Pair(6, 84), Pair(16, 80), Pair(2, 99), Pair(10, 81),
        Pair(10, 73), Pair(0, 90), Pair(20, 75), Pair(2, 88), Pair(5, 81), Pair(7, 77), Pair(10, 80), Pair(14, 71),
        Pair(-1, 84), Pair(8, 75), Pair(11, 72), Pair(4, 75), Pair(2, 79), Pair(11, 94), Pair(1, 83), Pair(23, 68),
        Pair(4, 84), Pair(7, 53), Pair(7, 80), Pair(5, 76), Pair(4, 86), Pair(6, 79), Pair(7, 28), Pair(-8, 106)
      },
      { // Piece 5
        Pair(17, 115), Pair(-19, -40), Pair(38, -99), Pair(-17, -56), Pair(53, 42), Pair(-24, 21), Pair(46, -7), Pair(-51, 20),
        Pair(-55, -70), Pair(52, -106), Pair(0, 0), Pair(89, -56), Pair(-24, 37), Pair(-106, 24), Pair(-113, 7), Pair(6, 4),
        Pair(10, -27), Pair(0, 0), Pair(-174, -38), Pair(0, 0), Pair(-2, -15), Pair(-2, -6), Pair(11, 9), Pair(-105, 12),
        Pair(-165, 11), Pair(-140, -7), Pair(-166, -22), Pair(-32, -23), Pair(-72, -5), Pair(-2, 6), Pair(-50, 16), Pair(-48, 13),
        Pair(-9, -14), Pair(-37, -16), Pair(-70, -17), Pair(-41, -18), Pair(-14, -3), Pair(-6, 7), Pair(-10, 9), Pair(-35, 5),
        Pair(-11, -7), Pair(-19, -14), Pair(-12, -16), Pair(-5, -8), Pair(-10, 4), Pair(-1, 5), Pair(-4, -5), Pair(-6, 6),
        Pair(-12, 4), Pair(4, -4), Pair(-2, -6), Pair(3, -7), Pair(0, 9), Pair(5, 4), Pair(-1, -1), Pair(6, -1),
        Pair(13, -13), Pair(4, -18), Pair(3, -8), Pair(14, -8), Pair(4, 5), Pair(8, 5), Pair(1, -3), Pair(0, -7)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 21), Pair(-14, 22), Pair(7, 27), Pair(0, 0), Pair(32, -10), Pair(80, -17), Pair(30, -23), Pair(-20, 36),
        Pair(1, 11), Pair(7, -8), Pair(-7, 27), Pair(-11, -29), Pair(-8, 44), Pair(0, -3), Pair(4, 9), Pair(-1, 10),
        Pair(-3, 5), Pair(-3, 15), Pair(8, 6), Pair(-2, 3), Pair(3, 14), Pair(-1, 14), Pair(6, 6), Pair(3, 11),
        Pair(5, 4), Pair(-2, 3), Pair(6, 1), Pair(-1, -6), Pair(1, 2), Pair(-6, -1), Pair(-5, 6), Pair(2, 6),
        Pair(3, 1), Pair(2, -2), Pair(2, -2), Pair(-2, 0), Pair(-1, 2), Pair(-5, -1), Pair(-2, -2), Pair(2, 3),
        Pair(3, -1), Pair(1, 0), Pair(4, 1), Pair(0, 0), Pair(-2, 2), Pair(-5, -1), Pair(-8, -2), Pair(2, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, 71), Pair(-26, -184), Pair(-21, 69), Pair(4, -87), Pair(18, 34), Pair(-23, -49), Pair(-36, 17), Pair(60, -14),
        Pair(-3, 9), Pair(-23, 54), Pair(-13, 44), Pair(0, 0), Pair(4, -13), Pair(11, 42), Pair(31, -21), Pair(48, 0),
        Pair(-51, 86), Pair(-1, 34), Pair(-288, -5), Pair(11, 61), Pair(-15, 28), Pair(9, 35), Pair(-5, 38), Pair(55, 17),
        Pair(-15, 22), Pair(3, 39), Pair(-36, 25), Pair(-10, 71), Pair(-35, 36), Pair(3, 42), Pair(-4, 1), Pair(-7, 36),
        Pair(-3, 12), Pair(-12, 28), Pair(-16, 28), Pair(-10, 12), Pair(-12, 37), Pair(-9, 38), Pair(5, 29), Pair(5, 11),
        Pair(3, 14), Pair(-6, 10), Pair(-3, 35), Pair(-11, 23), Pair(-7, 34), Pair(-8, 16), Pair(4, 14), Pair(5, 33),
        Pair(9, 33), Pair(9, -3), Pair(2, -11), Pair(-1, 28), Pair(0, 5), Pair(-3, 38), Pair(9, 13), Pair(-5, 14),
        Pair(-1, 13), Pair(5, 12), Pair(-4, 27), Pair(20, -7), Pair(-5, 6), Pair(-2, 34), Pair(-1, 0), Pair(-17, 103)
      },
      { // Piece 2
        Pair(20, -13), Pair(-94, 49), Pair(-3, -27), Pair(20, 28), Pair(-80, -15), Pair(136, -53), Pair(101, -9), Pair(1, -39),
        Pair(4, 65), Pair(-39, 58), Pair(-32, 59), Pair(0, 0), Pair(-17, 65), Pair(6, 48), Pair(-24, 79), Pair(-1, 16),
        Pair(-23, 10), Pair(-16, 43), Pair(-117, -206), Pair(3, 65), Pair(-14, 11), Pair(-32, 65), Pair(-40, 44), Pair(14, 31),
        Pair(-21, 57), Pair(-23, 21), Pair(-41, 67), Pair(-12, 46), Pair(-27, 46), Pair(3, 8), Pair(-5, 53), Pair(-21, 52),
        Pair(-24, 16), Pair(-25, 62), Pair(-33, 14), Pair(-6, 36), Pair(-15, 26), Pair(-5, 34), Pair(-26, 32), Pair(4, 24),
        Pair(-2, 25), Pair(-21, 23), Pair(-6, 33), Pair(-14, 35), Pair(-4, 34), Pair(-9, 41), Pair(5, 12), Pair(-20, 29),
        Pair(-15, 13), Pair(-2, 34), Pair(-12, 34), Pair(0, 24), Pair(-13, 28), Pair(-16, 38), Pair(-1, 9), Pair(-4, 54),
        Pair(-4, 17), Pair(-26, 10), Pair(1, 33), Pair(-25, 42), Pair(1, 27), Pair(-7, 14), Pair(-24, 23), Pair(-30, 29)
      },
      { // Piece 3
        Pair(-47, 15), Pair(-17, 27), Pair(76, -19), Pair(-87, 29), Pair(11, 14), Pair(78, -5), Pair(-145, 75), Pair(1, 16),
        Pair(-25, 25), Pair(1, 23), Pair(-23, 8), Pair(0, 0), Pair(14, -1), Pair(5, 15), Pair(-41, 34), Pair(6, 29),
        Pair(-22, 22), Pair(-11, 22), Pair(-26, 30), Pair(16, 4), Pair(46, 58), Pair(35, -7), Pair(13, 18), Pair(36, -14),
        Pair(-17, 19), Pair(-17, 5), Pair(-17, -8), Pair(-17, 16), Pair(-12, -6), Pair(-18, 7), Pair(-9, 29), Pair(-5, 38),
        Pair(-21, 18), Pair(-29, 26), Pair(-19, 1), Pair(-5, 1), Pair(-6, 3), Pair(-4, 18), Pair(-7, 22), Pair(-1, 14),
        Pair(-11, 21), Pair(-22, 30), Pair(-26, 25), Pair(-4, -10), Pair(-23, 9), Pair(-3, 29), Pair(-5, 17), Pair(-28, 53),
        Pair(-2, -2), Pair(8, -27), Pair(-8, -12), Pair(3, -19), Pair(-13, -20), Pair(-3, 13), Pair(-9, 23), Pair(28, 3),
        Pair(-10, 7), Pair(-14, 11), Pair(-13, 1), Pair(-17, 14), Pair(-14, 13), Pair(-14, 15), Pair(-16, 5), Pair(-8, 7)
      },
      { // Piece 4
        Pair(21, 31), Pair(39, -9), Pair(100, -57), Pair(63, -42), Pair(-69, 130), Pair(-20, 83), Pair(15, 3), Pair(32, -23),
        Pair(20, -2), Pair(-18, 47), Pair(20, -29), Pair(0, 0), Pair(-20, 46), Pair(9, 107), Pair(-18, 66), Pair(-21, 75),
        Pair(1, 31), Pair(29, -26), Pair(50, 9), Pair(34, 29), Pair(-2, -7), Pair(5, 33), Pair(30, 29), Pair(29, 43),
        Pair(8, 46), Pair(10, 30), Pair(3, 53), Pair(40, -1), Pair(2, 57), Pair(22, 38), Pair(26, 9), Pair(15, 60),
        Pair(4, 21), Pair(2, 5), Pair(19, -2), Pair(15, 42), Pair(9, 36), Pair(28, -22), Pair(0, 55), Pair(-8, 51),
        Pair(-6, 32), Pair(4, 42), Pair(17, -4), Pair(5, 37), Pair(10, 8), Pair(-3, 38), Pair(1, 54), Pair(7, 53),
        Pair(8, -37), Pair(-2, 36), Pair(9, 7), Pair(14, 18), Pair(1, 19), Pair(-5, 32), Pair(12, 51), Pair(41, -112),
        Pair(7, 16), Pair(-3, 9), Pair(11, -14), Pair(13, 10), Pair(8, 32), Pair(-6, 29), Pair(8, 12), Pair(6, 28)
      },
      { // Piece 5
        Pair(-3, 30), Pair(7, -66), Pair(14, 58), Pair(-11, -14), Pair(-4, 31), Pair(4, 31), Pair(-1, -61), Pair(-41, -77),
        Pair(8, -21), Pair(-28, -26), Pair(51, -11), Pair(0, 0), Pair(-25, -31), Pair(1, 11), Pair(-19, -30), Pair(-70, -131),
        Pair(-34, -56), Pair(-3, -8), Pair(0, 0), Pair(14, -81), Pair(0, 0), Pair(33, -18), Pair(111, -19), Pair(-19, 10),
        Pair(-37, 7), Pair(-67, 9), Pair(-120, -1), Pair(33, -64), Pair(41, -27), Pair(145, -13), Pair(-80, 29), Pair(-28, 3),
        Pair(-76, 18), Pair(-16, -16), Pair(71, -36), Pair(-6, -10), Pair(-59, -19), Pair(-68, 21), Pair(26, -6), Pair(118, -49),
        Pair(-160, 44), Pair(-22, -8), Pair(-5, -8), Pair(16, -20), Pair(-22, 17), Pair(0, 17), Pair(5, 5), Pair(-8, 11),
        Pair(18, -27), Pair(-4, 16), Pair(9, -15), Pair(3, -8), Pair(1, -3), Pair(-3, 13), Pair(7, -1), Pair(9, 10),
        Pair(19, 22), Pair(0, -2), Pair(7, 0), Pair(8, -39), Pair(1, -1), Pair(13, 14), Pair(-1, 12), Pair(11, -15)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 20), Pair(2, 12), Pair(6, 9), Pair(-2, 23), Pair(0, 0), Pair(-16, 11), Pair(-13, 26), Pair(15, 13),
        Pair(5, 8), Pair(13, 5), Pair(5, -3), Pair(-11, 44), Pair(-30, -14), Pair(-13, 25), Pair(3, -1), Pair(8, 15),
        Pair(6, 5), Pair(5, 5), Pair(-1, 6), Pair(14, 12), Pair(-6, 8), Pair(4, 15), Pair(-1, 8), Pair(2, 2),
        Pair(7, 7), Pair(5, -3), Pair(0, 2), Pair(2, 1), Pair(-5, -6), Pair(-2, 2), Pair(1, -4), Pair(0, 5),
        Pair(2, -2), Pair(5, 6), Pair(-3, -1), Pair(3, 4), Pair(-4, 0), Pair(-7, -2), Pair(-5, 4), Pair(-1, 0),
        Pair(4, 0), Pair(4, 4), Pair(3, 3), Pair(5, -2), Pair(0, 0), Pair(-4, -3), Pair(-1, -2), Pair(-4, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-28, 1), Pair(38, 31), Pair(0, 39), Pair(-58, 87), Pair(-38, -65), Pair(-32, 50), Pair(-23, 10), Pair(72, -94),
        Pair(-16, 40), Pair(-30, 19), Pair(-6, 20), Pair(-7, 17), Pair(0, 0), Pair(-62, 48), Pair(2, -14), Pair(-40, -2),
        Pair(-11, 21), Pair(-1, 32), Pair(-8, 20), Pair(-83, -10), Pair(8, 54), Pair(-453, 275), Pair(2, 14), Pair(9, 16),
        Pair(-2, 41), Pair(-6, 13), Pair(3, 27), Pair(-33, 24), Pair(-3, 30), Pair(-35, 45), Pair(-1, 14), Pair(-4, 32),
        Pair(-2, 23), Pair(-12, 22), Pair(-7, 20), Pair(-31, 16), Pair(5, 16), Pair(-12, 18), Pair(11, 23), Pair(5, 18),
        Pair(-3, 24), Pair(-2, 18), Pair(-10, 20), Pair(-9, 33), Pair(-16, 21), Pair(-4, 22), Pair(-9, 26), Pair(-7, 19),
        Pair(3, -1), Pair(-3, 27), Pair(-7, 21), Pair(-3, 20), Pair(-3, 25), Pair(-2, 23), Pair(1, 12), Pair(5, 24),
        Pair(28, -25), Pair(4, 33), Pair(5, 10), Pair(-6, 22), Pair(4, 28), Pair(-6, 9), Pair(-5, 25), Pair(34, -43)
      },
      { // Piece 2
        Pair(-11, 55), Pair(44, 9), Pair(-38, 62), Pair(-27, -5), Pair(-82, 74), Pair(-128, -15), Pair(31, 45), Pair(-54, 43),
        Pair(-14, 30), Pair(-2, 39), Pair(-10, 32), Pair(-77, 78), Pair(0, 0), Pair(-4, 33), Pair(-51, 16), Pair(37, 6),
        Pair(-2, 30), Pair(-22, 54), Pair(-19, 43), Pair(-288, 146), Pair(-18, 73), Pair(-264, 198), Pair(-27, 40), Pair(-8, 11),
        Pair(-4, 26), Pair(-11, 57), Pair(-2, 26), Pair(-35, 54), Pair(-1, 25), Pair(-42, 56), Pair(4, 13), Pair(10, 26),
        Pair(-24, 55), Pair(-8, 22), Pair(-16, 42), Pair(-27, 23), Pair(0, 33), Pair(-25, 13), Pair(-9, 39), Pair(-16, 31),
        Pair(-2, 12), Pair(-13, 39), Pair(-13, 38), Pair(-6, 47), Pair(-12, 28), Pair(-11, 42), Pair(-23, 17), Pair(-3, 26),
        Pair(-11, 27), Pair(-8, 29), Pair(-8, 42), Pair(-7, 19), Pair(-3, 40), Pair(-22, 41), Pair(1, 29), Pair(-15, 20),
        Pair(-18, 39), Pair(-6, 64), Pair(-11, 24), Pair(-12, 44), Pair(-10, 20), Pair(-6, 35), Pair(-15, 29), Pair(-3, 50)
      },
      { // Piece 3
        Pair(-16, 27), Pair(-27, 28), Pair(-38, 54), Pair(-46, 46), Pair(-19, 40), Pair(22, 17), Pair(35, 10), Pair(-82, 64),
        Pair(-8, 28), Pair(1, 40), Pair(10, 37), Pair(-2, 18), Pair(0, 0), Pair(19, 15), Pair(-47, 45), Pair(-26, 14),
        Pair(-2, 28), Pair(-15, 32), Pair(1, 27), Pair(-162, -19), Pair(40, 9), Pair(49, -60), Pair(-41, 19), Pair(0, 18),
        Pair(10, 28), Pair(-7, 31), Pair(-6, 22), Pair(-23, 29), Pair(17, 12), Pair(-17, 27), Pair(9, 12), Pair(5, 9),
        Pair(-6, 16), Pair(-2, 26), Pair(-1, 29), Pair(-15, 3), Pair(1, 9), Pair(9, -10), Pair(-13, 37), Pair(11, 19),
        Pair(-5, 25), Pair(-11, 17), Pair(-8, 18), Pair(-13, 16), Pair(-9, 19), Pair(17, -5), Pair(-13, 19), Pair(16, 9),
        Pair(-3, 21), Pair(6, 17), Pair(1, 18), Pair(-12, 11), Pair(-8, 18), Pair(-4, 1), Pair(-20, 44), Pair(1, 21),
        Pair(-3, 19), Pair(-3, 20), Pair(-3, 17), Pair(-10, 12), Pair(2, 18), Pair(0, 21), Pair(-3, 19), Pair(2, 22)
      },
      { // Piece 4
        Pair(34, 1), Pair(24, 47), Pair(50, 3), Pair(18, -33), Pair(12, 20), Pair(-14, 48), Pair(107, -23), Pair(-59, 126),
        Pair(18, 33), Pair(11, 40), Pair(47, 2), Pair(34, 0), Pair(0, 0), Pair(-25, 26), Pair(51, -81), Pair(-10, 43),
        Pair(16, 8), Pair(-7, 53), Pair(13, 28), Pair(27, 7), Pair(50, -2), Pair(-1, -5), Pair(14, 38), Pair(9, 72),
        Pair(9, 5), Pair(12, 39), Pair(15, 31), Pair(1, 13), Pair(26, 27), Pair(6, 62), Pair(24, 47), Pair(14, 65),
        Pair(0, 36), Pair(12, 44), Pair(5, 25), Pair(12, 32), Pair(13, 20), Pair(27, 9), Pair(9, 42), Pair(23, 34),
        Pair(17, -23), Pair(-3, 43), Pair(-2, 39), Pair(2, 31), Pair(4, 22), Pair(4, 37), Pair(10, 9), Pair(18, -24),
        Pair(3, 23), Pair(-5, 49), Pair(2, 20), Pair(-2, 29), Pair(8, 12), Pair(4, 23), Pair(-10, 38), Pair(20, -13),
        Pair(13, 17), Pair(0, 1), Pair(1, 27), Pair(0, 26), Pair(6, 20), Pair(15, 9), Pair(27, -30), Pair(32, -38)
      },
      { // Piece 5
        Pair(3, 112), Pair(0, 20), Pair(-14, -35), Pair(11, 66), Pair(-8, -31), Pair(-9, -125), Pair(16, 79), Pair(-4, 8),
        Pair(17, 87), Pair(-54, -12), Pair(18, -69), Pair(-33, -115), Pair(0, 0), Pair(60, -67), Pair(-83, -37), Pair(-20, -24),
        Pair(-48, -5), Pair(-17, 18), Pair(-32, 2), Pair(0, 0), Pair(130, -90), Pair(0, 0), Pair(-6, -5), Pair(160, -53),
        Pair(73, 35), Pair(-53, 39), Pair(-138, 23), Pair(-46, -22), Pair(40, -50), Pair(110, -48), Pair(-142, 17), Pair(-100, 0),
        Pair(-79, 17), Pair(-34, -8), Pair(-2, 1), Pair(-43, -13), Pair(-3, -21), Pair(-36, -13), Pair(-30, 11), Pair(-79, 7),
        Pair(48, -7), Pair(-22, 6), Pair(1, 10), Pair(18, -10), Pair(14, -5), Pair(8, -8), Pair(19, 3), Pair(-2, 4),
        Pair(-41, 20), Pair(-30, 23), Pair(-3, 8), Pair(13, -6), Pair(13, -9), Pair(5, -7), Pair(2, 0), Pair(2, 8),
        Pair(-17, -3), Pair(-18, 4), Pair(-7, 26), Pair(26, -6), Pair(-5, -10), Pair(7, 0), Pair(-3, 3), Pair(3, -1)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 22), Pair(3, 23), Pair(11, 16), Pair(3, 14), Pair(-2, 23), Pair(0, 0), Pair(-35, 15), Pair(7, 8),
        Pair(6, 9), Pair(12, 11), Pair(6, 8), Pair(7, -1), Pair(0, 28), Pair(-19, -1), Pair(-5, 25), Pair(3, 5),
        Pair(3, 3), Pair(6, 3), Pair(7, 4), Pair(6, 4), Pair(9, 12), Pair(-8, 3), Pair(-1, 5), Pair(-2, 4),
        Pair(9, 3), Pair(8, 2), Pair(5, 3), Pair(3, -1), Pair(3, 6), Pair(-6, -2), Pair(-4, 1), Pair(-1, 7),
        Pair(7, 0), Pair(7, 1), Pair(3, 0), Pair(4, 4), Pair(3, 6), Pair(-3, 3), Pair(-5, 2), Pair(-2, 3),
        Pair(5, 6), Pair(7, 1), Pair(5, -1), Pair(3, 0), Pair(4, 6), Pair(0, 0), Pair(-5, -2), Pair(-2, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-33, 58), Pair(-49, 67), Pair(-85, 74), Pair(-111, 56), Pair(18, 49), Pair(-83, 17), Pair(12, 76), Pair(-40, -43),
        Pair(-17, 65), Pair(-4, 56), Pair(0, 45), Pair(-27, 61), Pair(-37, 65), Pair(0, 0), Pair(-11, 48), Pair(34, 37),
        Pair(-5, 44), Pair(4, 52), Pair(-1, 56), Pair(-1, 31), Pair(-285, 100), Pair(22, 79), Pair(-87, 95), Pair(-14, 37),
        Pair(3, 51), Pair(0, 53), Pair(-7, 53), Pair(-5, 61), Pair(-41, 43), Pair(13, 65), Pair(-25, 16), Pair(8, 49),
        Pair(-1, 50), Pair(-5, 54), Pair(-1, 58), Pair(-15, 53), Pair(-31, 53), Pair(-12, 53), Pair(0, 47), Pair(-3, 47),
        Pair(3, 56), Pair(-7, 53), Pair(-2, 53), Pair(-13, 55), Pair(-3, 55), Pair(-4, 43), Pair(-7, 50), Pair(-16, 49),
        Pair(7, 49), Pair(-5, 54), Pair(-7, 52), Pair(-4, 52), Pair(-8, 52), Pair(-13, 58), Pair(0, 50), Pair(-9, 57),
        Pair(-21, 35), Pair(2, 54), Pair(0, 50), Pair(3, 57), Pair(-5, 48), Pair(1, 53), Pair(-11, 45), Pair(-7, 14)
      },
      { // Piece 2
        Pair(-59, 81), Pair(-17, 69), Pair(-81, 81), Pair(-58, 93), Pair(-122, 66), Pair(-85, 75), Pair(-173, 30), Pair(-1, 68),
        Pair(-14, 74), Pair(-35, 67), Pair(-4, 69), Pair(-53, 72), Pair(-28, 83), Pair(0, 0), Pair(-33, 88), Pair(-11, 46),
        Pair(-32, 61), Pair(-17, 79), Pair(-25, 72), Pair(-11, 76), Pair(-128, -66), Pair(19, 100), Pair(-73, -39), Pair(9, 63),
        Pair(-8, 67), Pair(-16, 67), Pair(-16, 79), Pair(-18, 49), Pair(-38, 71), Pair(-20, 66), Pair(-15, 59), Pair(-10, 31),
        Pair(-12, 47), Pair(-5, 71), Pair(-20, 55), Pair(-4, 66), Pair(-43, 56), Pair(-2, 69), Pair(-35, 48), Pair(5, 62),
        Pair(-8, 54), Pair(-17, 57), Pair(-3, 64), Pair(-17, 52), Pair(-5, 67), Pair(-14, 56), Pair(-9, 65), Pair(-25, 47),
        Pair(-20, 57), Pair(2, 53), Pair(-17, 53), Pair(-2, 65), Pair(-21, 49), Pair(-5, 61), Pair(-18, 45), Pair(-14, 69),
        Pair(1, 58), Pair(-21, 54), Pair(-1, 62), Pair(-15, 56), Pair(4, 73), Pair(-14, 50), Pair(-15, 74), Pair(-22, 62)
      },
      { // Piece 3
        Pair(-16, 77), Pair(-17, 84), Pair(-37, 85), Pair(-41, 84), Pair(-18, 75), Pair(-60, 77), Pair(-17, 76), Pair(-28, 92),
        Pair(-1, 69), Pair(-11, 74), Pair(-1, 76), Pair(-9, 79), Pair(-19, 75), Pair(0, 0), Pair(-29, 61), Pair(-8, 69),
        Pair(-7, 67), Pair(-6, 70), Pair(-8, 76), Pair(5, 68), Pair(-212, 48), Pair(28, 55), Pair(54, -36), Pair(2, 64),
        Pair(4, 67), Pair(-1, 67), Pair(1, 70), Pair(-7, 75), Pair(-10, 66), Pair(11, 69), Pair(18, 54), Pair(1, 65),
        Pair(1, 76), Pair(-4, 69), Pair(3, 66), Pair(-7, 70), Pair(-13, 48), Pair(4, 55), Pair(-10, 51), Pair(-2, 66),
        Pair(7, 71), Pair(4, 67), Pair(-12, 70), Pair(-5, 71), Pair(-1, 64), Pair(11, 59), Pair(6, 57), Pair(-1, 68),
        Pair(6, 69), Pair(0, 69), Pair(0, 71), Pair(3, 68), Pair(-1, 58), Pair(13, 54), Pair(11, 57), Pair(7, 55),
        Pair(5, 71), Pair(6, 68), Pair(5, 65), Pair(0, 66), Pair(3, 57), Pair(5, 69), Pair(5, 63), Pair(3, 64)
      },
      { // Piece 4
        Pair(-14, 112), Pair(3, 117), Pair(-18, 117), Pair(-3, 119), Pair(0, 67), Pair(44, 1), Pair(-13, 138), Pair(6, 119),
        Pair(16, 97), Pair(3, 109), Pair(29, 89), Pair(27, 67), Pair(-3, 55), Pair(0, 0), Pair(-8, 165), Pair(16, 108),
        Pair(16, 78), Pair(13, 90), Pair(14, 89), Pair(24, 86), Pair(-88, -7), Pair(59, 41), Pair(11, 121), Pair(44, 89),
        Pair(10, 101), Pair(9, 99), Pair(7, 109), Pair(18, 91), Pair(18, 106), Pair(34, 72), Pair(29, 107), Pair(32, 94),
        Pair(16, 91), Pair(5, 100), Pair(10, 92), Pair(17, 109), Pair(5, 105), Pair(35, 75), Pair(12, 130), Pair(24, 106),
        Pair(3, 110), Pair(4, 100), Pair(14, 99), Pair(7, 110), Pair(17, 86), Pair(29, 82), Pair(26, 107), Pair(33, 56),
        Pair(8, 80), Pair(7, 90), Pair(14, 82), Pair(8, 98), Pair(11, 103), Pair(18, 83), Pair(16, 97), Pair(21, 84),
        Pair(20, 77), Pair(12, 75), Pair(23, 77), Pair(14, 89), Pair(18, 89), Pair(16, 87), Pair(-2, 113), Pair(25, 79)
      },
      { // Piece 5
        Pair(5, -5), Pair(59, -24), Pair(42, -8), Pair(28, -43), Pair(-102, -37), Pair(55, -89), Pair(-53, -46), Pair(-38, -34),
        Pair(112, -25), Pair(27, -19), Pair(-70, 5), Pair(81, -37), Pair(-64, -84), Pair(0, 0), Pair(38, -60), Pair(-26, -15),
        Pair(29, -10), Pair(-44, 15), Pair(-2, -6), Pair(-84, -20), Pair(0, 0), Pair(-108, -44), Pair(0, 0), Pair(-50, -19),
        Pair(9, 1), Pair(-26, -2), Pair(14, -9), Pair(-25, -22), Pair(-20, -34), Pair(-7, -37), Pair(-79, -19), Pair(-89, -14),
        Pair(23, -17), Pair(-10, 1), Pair(18, -6), Pair(-4, 1), Pair(-18, -22), Pair(-26, -9), Pair(-6, -14), Pair(-60, -1),
        Pair(-9, -6), Pair(15, -6), Pair(10, 0), Pair(13, -1), Pair(-1, -8), Pair(5, -9), Pair(-7, -8), Pair(-8, 3),
        Pair(-1, -4), Pair(-2, 2), Pair(-2, 12), Pair(5, 8), Pair(-10, -1), Pair(9, 2), Pair(-7, -2), Pair(-2, 2),
        Pair(-10, 0), Pair(-10, 5), Pair(-12, 13), Pair(0, 0), Pair(-3, -7), Pair(-9, 6), Pair(-9, -9), Pair(11, -5)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, 9), Pair(16, 14), Pair(18, 12), Pair(2, 9), Pair(-22, 18), Pair(-12, 18), Pair(0, 0), Pair(-13, 6),
        Pair(4, 9), Pair(10, 8), Pair(3, 8), Pair(-1, 6), Pair(-11, 6), Pair(-22, 27), Pair(-13, -8), Pair(5, 23),
        Pair(6, 6), Pair(8, 4), Pair(2, 5), Pair(-2, 4), Pair(0, 3), Pair(-2, 11), Pair(3, -1), Pair(12, 13),
        Pair(8, 3), Pair(7, 5), Pair(2, 2), Pair(-1, 1), Pair(0, 5), Pair(0, 9), Pair(-2, -3), Pair(-3, 7),
        Pair(3, -1), Pair(1, -1), Pair(1, 0), Pair(2, -2), Pair(-2, 1), Pair(1, 6), Pair(-7, 2), Pair(-4, 6),
        Pair(0, 2), Pair(4, 0), Pair(1, 1), Pair(5, 0), Pair(-2, 1), Pair(3, 1), Pair(0, 0), Pair(-7, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-42, 25), Pair(-113, 70), Pair(-24, 35), Pair(-124, 87), Pair(-77, 21), Pair(-29, 59), Pair(-22, -19), Pair(-24, 68),
        Pair(5, 34), Pair(-12, 37), Pair(3, 35), Pair(-7, 36), Pair(-21, 47), Pair(22, 21), Pair(0, 0), Pair(-23, -4),
        Pair(-18, 33), Pair(-3, 37), Pair(-1, 41), Pair(4, 33), Pair(-4, 27), Pair(-364, 266), Pair(11, 76), Pair(-9, 110),
        Pair(0, 29), Pair(7, 28), Pair(4, 38), Pair(16, 34), Pair(3, 46), Pair(-39, 36), Pair(0, 59), Pair(-20, 17),
        Pair(-5, 34), Pair(-7, 35), Pair(4, 33), Pair(-5, 41), Pair(11, 37), Pair(-29, 42), Pair(14, 18), Pair(-17, 38),
        Pair(4, 24), Pair(-5, 39), Pair(-1, 34), Pair(-4, 38), Pair(-11, 39), Pair(-1, 37), Pair(-8, 36), Pair(-2, 52),
        Pair(3, 31), Pair(3, 31), Pair(-6, 33), Pair(-2, 37), Pair(-7, 42), Pair(9, 32), Pair(9, 21), Pair(9, 34),
        Pair(-24, 45), Pair(-2, 45), Pair(-11, 39), Pair(0, 20), Pair(2, 32), Pair(2, 36), Pair(-3, 41), Pair(-23, 54)
      },
      { // Piece 2
        Pair(-30, 72), Pair(-35, 52), Pair(-61, 82), Pair(-88, 69), Pair(-110, 86), Pair(-95, 57), Pair(131, 42), Pair(1, 0),
        Pair(-36, 54), Pair(1, 71), Pair(-33, 58), Pair(-53, 87), Pair(-54, 64), Pair(-34, 72), Pair(0, 0), Pair(-10, 63),
        Pair(5, 68), Pair(-48, 64), Pair(1, 77), Pair(-30, 58), Pair(-7, 72), Pair(-234, 58), Pair(0, 100), Pair(-13, -51),
        Pair(-24, 49), Pair(1, 64), Pair(-31, 56), Pair(-8, 75), Pair(-16, 36), Pair(-47, 77), Pair(0, 47), Pair(-13, 58),
        Pair(-1, 53), Pair(-30, 48), Pair(5, 63), Pair(-11, 37), Pair(-1, 59), Pair(-33, 32), Pair(-5, 59), Pair(-33, 40),
        Pair(-17, 36), Pair(3, 59), Pair(-16, 40), Pair(-1, 55), Pair(-13, 42), Pair(2, 55), Pair(-10, 36), Pair(2, 59),
        Pair(14, 65), Pair(-13, 35), Pair(8, 42), Pair(-12, 35), Pair(-1, 56), Pair(-18, 41), Pair(12, 54), Pair(-18, 37),
        Pair(-11, 24), Pair(0, 54), Pair(-11, 38), Pair(4, 54), Pair(-18, 46), Pair(3, 56), Pair(-37, 63), Pair(-2, 74)
      },
      { // Piece 3
        Pair(-7, 76), Pair(-31, 82), Pair(-39, 88), Pair(-25, 84), Pair(-33, 76), Pair(-31, 70), Pair(6, 61), Pair(-9, 73),
        Pair(4, 61), Pair(1, 60), Pair(-10, 72), Pair(-2, 63), Pair(0, 68), Pair(-25, 67), Pair(0, 0), Pair(-18, 55),
        Pair(8, 60), Pair(1, 63), Pair(6, 63), Pair(6, 62), Pair(6, 52), Pair(-24, 10), Pair(4, 76), Pair(228, -174),
        Pair(13, 60), Pair(-3, 65), Pair(7, 66), Pair(-11, 72), Pair(5, 65), Pair(-3, 55), Pair(-14, 69), Pair(-2, 58),
        Pair(0, 64), Pair(3, 65), Pair(-1, 63), Pair(0, 66), Pair(-6, 56), Pair(-6, 39), Pair(-13, 64), Pair(3, 46),
        Pair(6, 71), Pair(3, 62), Pair(2, 59), Pair(0, 59), Pair(-1, 61), Pair(8, 46), Pair(-7, 55), Pair(12, 50),
        Pair(14, 53), Pair(9, 55), Pair(7, 59), Pair(7, 57), Pair(10, 58), Pair(11, 47), Pair(3, 52), Pair(7, 53),
        Pair(12, 59), Pair(3, 61), Pair(7, 62), Pair(6, 58), Pair(4, 56), Pair(7, 53), Pair(3, 50), Pair(-1, 58)
      },
      { // Piece 4
        Pair(-41, 126), Pair(-24, 100), Pair(-27, 138), Pair(22, 93), Pair(9, 116), Pair(12, 61), Pair(10, 104), Pair(11, 63),
        Pair(4, 86), Pair(-16, 103), Pair(-2, 91), Pair(-13, 99), Pair(0, 105), Pair(35, 14), Pair(0, 0), Pair(32, 61),
        Pair(6, 76), Pair(5, 78), Pair(-12, 98), Pair(12, 75), Pair(29, 58), Pair(-9, -116), Pair(21, 58), Pair(23, -54),
        Pair(-4, 74), Pair(-7, 97), Pair(0, 89), Pair(-6, 116), Pair(8, 83), Pair(-10, 109), Pair(4, 67), Pair(7, 81),
        Pair(4, 69), Pair(-7, 88), Pair(-2, 90), Pair(2, 95), Pair(-5, 108), Pair(15, 77), Pair(3, 68), Pair(8, 92),
        Pair(0, 78), Pair(-6, 101), Pair(-2, 98), Pair(-11, 98), Pair(-1, 96), Pair(-3, 104), Pair(11, 54), Pair(17, 75),
        Pair(-8, 72), Pair(-5, 85), Pair(-6, 66), Pair(-6, 101), Pair(-3, 80), Pair(-8, 97), Pair(6, 60), Pair(16, 71),
        Pair(0, 88), Pair(-4, 65), Pair(5, 75), Pair(-1, 71), Pair(1, 79), Pair(2, 77), Pair(11, 71), Pair(-5, 96)
      },
      { // Piece 5
        Pair(-60, -5), Pair(54, -54), Pair(28, -48), Pair(-13, 16), Pair(55, 4), Pair(78, -8), Pair(118, -12), Pair(14, 41),
        Pair(-137, 48), Pair(109, -31), Pair(25, -7), Pair(64, -17), Pair(59, -35), Pair(-36, -60), Pair(0, 0), Pair(16, -66),
        Pair(66, -1), Pair(51, -4), Pair(-8, 6), Pair(23, -7), Pair(-63, -11), Pair(0, 0), Pair(-24, -59), Pair(0, 0),
        Pair(-51, 12), Pair(13, -6), Pair(29, -9), Pair(14, -6), Pair(-68, -13), Pair(-51, -8), Pair(-31, -30), Pair(-60, -18),
        Pair(52, -19), Pair(45, -10), Pair(31, -10), Pair(38, -10), Pair(-1, -6), Pair(1, -13), Pair(-28, -9), Pair(-104, 8),
        Pair(34, -17), Pair(14, -13), Pair(22, -7), Pair(14, 0), Pair(4, 5), Pair(-13, 0), Pair(-21, -5), Pair(-16, 1),
        Pair(6, 2), Pair(9, -10), Pair(2, 3), Pair(14, -9), Pair(-8, 9), Pair(8, -9), Pair(-11, 4), Pair(-3, -1),
        Pair(-13, 11), Pair(-11, 5), Pair(-1, -2), Pair(2, 2), Pair(6, -5), Pair(-2, 4), Pair(-8, 9), Pair(-7, 0)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(16, 7), Pair(12, 14), Pair(22, 6), Pair(8, 5), Pair(9, 13), Pair(-7, 16), Pair(-16, -1), Pair(0, 0),
        Pair(4, 13), Pair(11, 8), Pair(11, 5), Pair(-2, 7), Pair(-14, 7), Pair(-17, 7), Pair(-6, 9), Pair(3, -18),
        Pair(4, 5), Pair(6, 0), Pair(6, 3), Pair(-2, 3), Pair(-8, 4), Pair(-4, 1), Pair(-2, 3), Pair(6, -5),
        Pair(4, 3), Pair(4, -3), Pair(1, -1), Pair(0, 2), Pair(-1, 3), Pair(1, 1), Pair(-2, 2), Pair(-2, -2),
        Pair(2, 0), Pair(1, -2), Pair(-1, -1), Pair(-3, -1), Pair(4, 1), Pair(5, 4), Pair(-1, 2), Pair(2, -1),
        Pair(2, 3), Pair(0, -4), Pair(0, -6), Pair(-2, -2), Pair(3, -2), Pair(7, 2), Pair(3, -2), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-66, 22), Pair(2, 33), Pair(-20, 18), Pair(47, 18), Pair(-82, 76), Pair(-99, 5), Pair(-40, 42), Pair(-50, -60),
        Pair(-23, 35), Pair(4, 23), Pair(14, 39), Pair(4, 46), Pair(14, 26), Pair(32, 38), Pair(45, 10), Pair(0, 0),
        Pair(30, 19), Pair(2, 23), Pair(2, 36), Pair(12, 36), Pair(3, 40), Pair(5, 26), Pair(-126, -15), Pair(9, 85),
        Pair(-3, 25), Pair(9, 28), Pair(4, 37), Pair(13, 37), Pair(7, 45), Pair(-1, 55), Pair(-25, 34), Pair(21, 45),
        Pair(7, 17), Pair(1, 24), Pair(8, 32), Pair(7, 34), Pair(9, 39), Pair(21, 38), Pair(-22, 50), Pair(-4, 27),
        Pair(-6, 34), Pair(-2, 27), Pair(6, 31), Pair(4, 32), Pair(10, 34), Pair(2, 40), Pair(4, 47), Pair(-6, 38),
        Pair(16, 5), Pair(13, 22), Pair(9, 26), Pair(-1, 30), Pair(3, 34), Pair(-4, 39), Pair(11, 28), Pair(2, 39),
        Pair(25, 2), Pair(0, 25), Pair(3, 11), Pair(3, 28), Pair(0, 26), Pair(2, 36), Pair(-6, 32), Pair(27, 44)
      },
      { // Piece 2
        Pair(-46, 75), Pair(-48, 80), Pair(-53, 70), Pair(-76, 87), Pair(-111, 83), Pair(-74, 74), Pair(-63, 80), Pair(-8, 60),
        Pair(-39, 74), Pair(-3, 69), Pair(-15, 70), Pair(-44, 88), Pair(-32, 81), Pair(-14, 58), Pair(-34, 59), Pair(0, 0),
        Pair(-10, 56), Pair(-12, 61), Pair(-17, 70), Pair(-9, 69), Pair(-10, 66), Pair(-34, 80), Pair(-55, -50), Pair(20, 91),
        Pair(-11, 50), Pair(-3, 61), Pair(-8, 55), Pair(-3, 68), Pair(-5, 59), Pair(-1, 40), Pair(-22, 60), Pair(9, 55),
        Pair(-15, 51), Pair(-3, 55), Pair(-1, 61), Pair(3, 58), Pair(4, 56), Pair(0, 57), Pair(-9, 46), Pair(1, 61),
        Pair(-4, 49), Pair(2, 55), Pair(3, 49), Pair(-5, 51), Pair(2, 46), Pair(2, 58), Pair(5, 54), Pair(2, 62),
        Pair(-13, 56), Pair(6, 47), Pair(-10, 52), Pair(-5, 53), Pair(-5, 51), Pair(1, 51), Pair(8, 58), Pair(4, 51),
        Pair(2, 54), Pair(-28, 56), Pair(-4, 53), Pair(-12, 51), Pair(3, 61), Pair(2, 52), Pair(-4, 48), Pair(4, 81)
      },
      { // Piece 3
        Pair(-1, 92), Pair(4, 90), Pair(-15, 95), Pair(0, 94), Pair(-14, 95), Pair(-48, 112), Pair(14, 86), Pair(-104, 134),
        Pair(14, 91), Pair(14, 90), Pair(1, 90), Pair(-2, 92), Pair(-7, 101), Pair(38, 93), Pair(19, 100), Pair(0, 0),
        Pair(10, 84), Pair(19, 88), Pair(6, 93), Pair(5, 95), Pair(20, 90), Pair(-25, 97), Pair(30, -65), Pair(-16, 99),
        Pair(7, 87), Pair(2, 91), Pair(8, 87), Pair(6, 93), Pair(4, 90), Pair(-1, 90), Pair(-9, 95), Pair(-2, 83),
        Pair(16, 82), Pair(13, 85), Pair(12, 86), Pair(8, 87), Pair(-1, 85), Pair(11, 71), Pair(-13, 87), Pair(-8, 71),
        Pair(13, 87), Pair(11, 86), Pair(25, 75), Pair(10, 73), Pair(0, 84), Pair(8, 80), Pair(-3, 86), Pair(-21, 76),
        Pair(19, 81), Pair(1, 94), Pair(14, 80), Pair(14, 77), Pair(14, 75), Pair(9, 80), Pair(5, 87), Pair(3, 83),
        Pair(15, 82), Pair(8, 86), Pair(12, 82), Pair(7, 81), Pair(9, 81), Pair(11, 75), Pair(-7, 83), Pair(-2, 81)
      },
      { // Piece 4
        Pair(-28, 170), Pair(-1, 159), Pair(13, 131), Pair(-10, 176), Pair(-3, 154), Pair(-26, 209), Pair(133, 39), Pair(-102, 212),
        Pair(0, 156), Pair(3, 149), Pair(3, 169), Pair(-37, 176), Pair(-18, 202), Pair(-16, 232), Pair(16, 183), Pair(0, 0),
        Pair(13, 140), Pair(8, 157), Pair(2, 171), Pair(1, 168), Pair(-24, 194), Pair(-25, 203), Pair(-76, 23), Pair(16, 119),
        Pair(12, 112), Pair(-2, 151), Pair(7, 151), Pair(-9, 178), Pair(1, 182), Pair(6, 180), Pair(-5, 163), Pair(-3, 146),
        Pair(3, 146), Pair(-1, 162), Pair(-2, 162), Pair(2, 163), Pair(3, 150), Pair(3, 159), Pair(-4, 147), Pair(-7, 137),
        Pair(6, 157), Pair(2, 142), Pair(8, 144), Pair(-1, 144), Pair(2, 159), Pair(2, 150), Pair(3, 156), Pair(0, 125),
        Pair(-4, 152), Pair(4, 129), Pair(5, 130), Pair(6, 137), Pair(0, 147), Pair(3, 134), Pair(14, 136), Pair(-2, 112),
        Pair(15, 114), Pair(9, 117), Pair(3, 135), Pair(8, 124), Pair(11, 124), Pair(-7, 151), Pair(-28, 167), Pair(-8, 161)
      },
      { // Piece 5
        Pair(-45, 24), Pair(54, -31), Pair(128, -73), Pair(-53, -14), Pair(-98, 9), Pair(54, -54), Pair(-33, -36), Pair(4, 29),
        Pair(-124, 36), Pair(99, -27), Pair(-97, -7), Pair(-81, 14), Pair(23, -29), Pair(-129, -2), Pair(-87, -34), Pair(0, 0),
        Pair(-33, -17), Pair(17, -5), Pair(-27, 10), Pair(-1, -15), Pair(-38, -8), Pair(-97, -5), Pair(0, 0), Pair(80, -58),
        Pair(85, -38), Pair(57, -12), Pair(43, -9), Pair(-19, -7), Pair(24, -4), Pair(-61, -1), Pair(-28, -1), Pair(-25, -16),
        Pair(4, -13), Pair(29, -4), Pair(54, -12), Pair(46, -15), Pair(11, -7), Pair(5, 0), Pair(-21, -10), Pair(-46, -17),
        Pair(34, -23), Pair(47, -24), Pair(33, -9), Pair(17, 0), Pair(-1, 6), Pair(-2, 2), Pair(-3, -6), Pair(-24, 5),
        Pair(0, 3), Pair(-4, -1), Pair(12, -9), Pair(8, -2), Pair(0, 7), Pair(15, 2), Pair(-6, 9), Pair(-6, 6),
        Pair(-7, 6), Pair(-16, 3), Pair(-3, -6), Pair(8, -10), Pair(9, 0), Pair(1, 8), Pair(3, 16), Pair(-13, 22)
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
        Pair(-9, 12), Pair(-80, 7), Pair(5, 20), Pair(-5, 43), Pair(61, 45), Pair(-75, 46), Pair(-33, 34), Pair(53, 5),
        Pair(-18, -82), Pair(-74, 6), Pair(7, 13), Pair(5, 35), Pair(-85, 38), Pair(-33, 31), Pair(12, 5), Pair(-11, 37),
        Pair(-15, 16), Pair(-11, 39), Pair(15, 10), Pair(8, 8), Pair(-6, 12), Pair(-15, 20), Pair(-15, 12), Pair(20, 7),
        Pair(-31, 18), Pair(-18, 25), Pair(6, 13), Pair(-15, 15), Pair(-17, 15), Pair(1, 10), Pair(4, 8), Pair(12, 3),
        Pair(-22, 30), Pair(-22, 20), Pair(-14, 19), Pair(-6, 9), Pair(-13, 13), Pair(14, 3), Pair(6, 6), Pair(0, 13),
        Pair(-14, 25), Pair(-29, 28), Pair(-21, 17), Pair(-5, -7), Pair(-45, 30), Pair(2, 20), Pair(-12, 24), Pair(1, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-44, 43), Pair(3, 50), Pair(111, -9), Pair(1, 56), Pair(49, -1), Pair(-42, 1), Pair(7, 78), Pair(-3, -20),
        Pair(0, 0), Pair(-2, -7), Pair(-38, 56), Pair(21, -5), Pair(-40, 54), Pair(-45, 14), Pair(14, 86), Pair(-94, -26),
        Pair(92, 32), Pair(-38, 77), Pair(106, -9), Pair(80, -21), Pair(141, -36), Pair(131, -16), Pair(108, 36), Pair(-7, 6),
        Pair(-58, 13), Pair(22, 17), Pair(65, -3), Pair(-10, 74), Pair(49, 11), Pair(30, 12), Pair(6, 1), Pair(94, -51),
        Pair(-71, 67), Pair(7, 17), Pair(28, 12), Pair(26, 8), Pair(32, 10), Pair(16, 0), Pair(16, -32), Pair(47, -9),
        Pair(14, -62), Pair(-1, 11), Pair(-28, 46), Pair(108, -19), Pair(-10, 17), Pair(30, -18), Pair(32, -1), Pair(9, -16),
        Pair(-22, 29), Pair(-85, -23), Pair(75, -32), Pair(5, -21), Pair(-14, 8), Pair(45, -28), Pair(-14, -15), Pair(71, -40),
        Pair(-79, -20), Pair(-62, -8), Pair(3, -15), Pair(-57, 37), Pair(21, -42), Pair(12, -23), Pair(-110, 24), Pair(63, -66)
      },
      { // Piece 2
        Pair(-7, -72), Pair(170, -1), Pair(-10, -17), Pair(90, -56), Pair(11, -8), Pair(-28, -74), Pair(77, -4), Pair(-59, -156),
        Pair(0, 0), Pair(43, 73), Pair(205, -48), Pair(16, 6), Pair(72, -85), Pair(40, -18), Pair(253, -91), Pair(52, -29),
        Pair(142, 7), Pair(125, -28), Pair(43, 70), Pair(138, -37), Pair(9, 15), Pair(147, -59), Pair(125, -13), Pair(-7, -19),
        Pair(7, -9), Pair(6, 14), Pair(147, -18), Pair(8, 46), Pair(174, -70), Pair(-38, 20), Pair(76, -52), Pair(24, -4),
        Pair(-43, 55), Pair(86, -60), Pair(14, 18), Pair(72, -5), Pair(25, 51), Pair(12, -30), Pair(11, 44), Pair(68, -54),
        Pair(30, -40), Pair(46, -15), Pair(35, -36), Pair(16, 16), Pair(66, -3), Pair(15, 4), Pair(56, -31), Pair(33, 26),
        Pair(14, -92), Pair(51, -57), Pair(-41, 33), Pair(51, -22), Pair(6, 22), Pair(125, -35), Pair(35, 22), Pair(-72, 23),
        Pair(69, -93), Pair(3, -15), Pair(19, -28), Pair(74, -26), Pair(36, -41), Pair(-12, 5), Pair(104, -40), Pair(-73, 89)
      },
      { // Piece 3
        Pair(65, -169), Pair(42, 104), Pair(-12, 53), Pair(-39, 70), Pair(-67, 78), Pair(-34, 29), Pair(-13, 61), Pair(-5, 52),
        Pair(0, 0), Pair(166, -15), Pair(94, -7), Pair(126, -23), Pair(174, -35), Pair(139, -5), Pair(44, -2), Pair(124, -14),
        Pair(-11, 22), Pair(-2, 39), Pair(-11, 44), Pair(-14, 37), Pair(-81, 64), Pair(28, 52), Pair(66, 22), Pair(48, 34),
        Pair(-8, 44), Pair(-1, 77), Pair(74, 9), Pair(92, 29), Pair(132, -17), Pair(-3, 51), Pair(-154, 109), Pair(-211, 105),
        Pair(-1, 28), Pair(50, 50), Pair(-61, 67), Pair(103, -27), Pair(-33, 84), Pair(64, -12), Pair(55, 96), Pair(31, -2),
        Pair(3, 20), Pair(-21, 54), Pair(78, -4), Pair(-52, 69), Pair(-78, 79), Pair(-1, 46), Pair(1, 33), Pair(53, -8),
        Pair(52, -11), Pair(16, 27), Pair(-70, 73), Pair(-3, 20), Pair(1, 40), Pair(-69, 46), Pair(10, -13), Pair(-5, -4),
        Pair(-5, 4), Pair(23, 34), Pair(29, 1), Pair(9, 23), Pair(-6, 26), Pair(-8, 17), Pair(11, 11), Pair(-19, 68)
      },
      { // Piece 4
        Pair(-62, -185), Pair(102, -49), Pair(-8, 12), Pair(-29, -24), Pair(17, 50), Pair(-63, -59), Pair(85, 13), Pair(-71, -33),
        Pair(0, 0), Pair(-22, 60), Pair(-34, 54), Pair(159, -112), Pair(-7, -23), Pair(-154, 32), Pair(-18, -14), Pair(40, -55),
        Pair(23, -6), Pair(-58, 70), Pair(47, -21), Pair(-63, 45), Pair(44, -32), Pair(-19, 38), Pair(118, -43), Pair(23, -28),
        Pair(-33, 23), Pair(-5, 28), Pair(-11, 18), Pair(-84, 72), Pair(3, 22), Pair(37, -112), Pair(3, -50), Pair(-22, -125),
        Pair(-7, 32), Pair(-59, 105), Pair(-33, 25), Pair(21, -20), Pair(80, -205), Pair(51, -21), Pair(-64, 105), Pair(48, -9),
        Pair(-83, 47), Pair(-13, -34), Pair(-43, -2), Pair(-13, -35), Pair(-38, 21), Pair(-37, 54), Pair(26, -85), Pair(55, -72),
        Pair(35, -92), Pair(44, -92), Pair(28, -87), Pair(-5, -76), Pair(9, -40), Pair(25, -80), Pair(-89, 17), Pair(-13, -119),
        Pair(27, -42), Pair(-70, -52), Pair(-13, -4), Pair(-47, 20), Pair(93, -107), Pair(87, -137), Pair(-23, -21), Pair(-45, -24)
      },
      { // Piece 5
        Pair(-88, -197), Pair(-45, 88), Pair(56, 76), Pair(17, 48), Pair(13, 0), Pair(14, -23), Pair(-8, 24), Pair(21, 95),
        Pair(0, 0), Pair(5, 111), Pair(-44, 41), Pair(54, -15), Pair(66, -15), Pair(-86, -20), Pair(48, -24), Pair(4, 3),
        Pair(-46, 48), Pair(55, 49), Pair(72, 46), Pair(-130, 23), Pair(-123, 40), Pair(38, -52), Pair(-26, 19), Pair(-17, 11),
        Pair(52, -1), Pair(23, 50), Pair(22, 19), Pair(-51, 34), Pair(122, -40), Pair(7, 3), Pair(-4, -1), Pair(-164, 15),
        Pair(-156, 42), Pair(51, 32), Pair(41, 3), Pair(66, -7), Pair(71, -11), Pair(19, -18), Pair(17, -31), Pair(-61, -10),
        Pair(-202, 52), Pair(-2, 32), Pair(88, -23), Pair(-41, 16), Pair(71, -19), Pair(20, -21), Pair(-14, -22), Pair(-53, -24),
        Pair(-38, 61), Pair(117, -13), Pair(41, -6), Pair(-49, 6), Pair(-21, -1), Pair(-21, -7), Pair(-23, -23), Pair(-34, -27),
        Pair(-124, 19), Pair(133, -17), Pair(-4, 14), Pair(-71, 9), Pair(-2, -28), Pair(-40, -25), Pair(16, -45), Pair(-21, -37)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-80, 7), Pair(1, 30), Pair(72, -11), Pair(-61, 38), Pair(-24, 47), Pair(-18, 46), Pair(-10, 20), Pair(38, 35),
        Pair(31, -11), Pair(-16, -89), Pair(-7, 2), Pair(-5, 31), Pair(-30, 31), Pair(19, 42), Pair(15, 14), Pair(31, 12),
        Pair(20, 26), Pair(8, -13), Pair(24, 27), Pair(-16, 30), Pair(12, 7), Pair(-10, 13), Pair(-14, 21), Pair(-15, 5),
        Pair(10, 22), Pair(-24, -2), Pair(5, 20), Pair(-11, 13), Pair(-21, 26), Pair(-2, 6), Pair(-11, 21), Pair(-14, 16),
        Pair(-15, 27), Pair(-26, 18), Pair(-43, 20), Pair(-21, 11), Pair(-13, 15), Pair(1, 7), Pair(12, 13), Pair(-7, 16),
        Pair(-14, 27), Pair(-25, 25), Pair(-21, 1), Pair(-19, 12), Pair(-2, 7), Pair(-2, 12), Pair(-3, 17), Pair(-13, 23),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-31, -51), Pair(18, 105), Pair(-26, 29), Pair(19, -8), Pair(-22, -87), Pair(-14, 22), Pair(-60, -151), Pair(-14, -44),
        Pair(-14, 47), Pair(0, 0), Pair(130, -2), Pair(73, 58), Pair(72, 23), Pair(-5, 59), Pair(5, 58), Pair(51, 52),
        Pair(34, 68), Pair(35, 41), Pair(182, -3), Pair(23, 6), Pair(139, -21), Pair(15, -6), Pair(-164, 73), Pair(97, -11),
        Pair(44, 5), Pair(-2, 22), Pair(77, 26), Pair(26, 36), Pair(24, 50), Pair(-132, 73), Pair(-67, 28), Pair(74, 5),
        Pair(7, 69), Pair(122, 26), Pair(26, 38), Pair(-39, 28), Pair(102, -17), Pair(-22, 53), Pair(9, -8), Pair(-15, 10),
        Pair(-5, -19), Pair(-5, 21), Pair(-22, -16), Pair(47, 28), Pair(32, -6), Pair(21, 0), Pair(-27, 11), Pair(-8, 88),
        Pair(10, -20), Pair(100, -32), Pair(-96, 34), Pair(-19, -3), Pair(0, 24), Pair(1, 2), Pair(-35, -8), Pair(77, -45),
        Pair(-49, -46), Pair(-112, 103), Pair(-22, -15), Pair(55, -39), Pair(-67, 34), Pair(25, -13), Pair(-8, -80), Pair(14, -5)
      },
      { // Piece 2
        Pair(-82, -103), Pair(53, -93), Pair(158, -25), Pair(-18, 46), Pair(44, -67), Pair(19, 72), Pair(17, -81), Pair(54, 69),
        Pair(132, 44), Pair(0, 0), Pair(-9, 78), Pair(4, -84), Pair(50, 10), Pair(36, -71), Pair(-88, 68), Pair(-63, -47),
        Pair(39, -6), Pair(98, 16), Pair(164, -38), Pair(-45, 99), Pair(137, -53), Pair(142, 11), Pair(121, -104), Pair(-25, 62),
        Pair(50, 7), Pair(101, -77), Pair(-3, 39), Pair(144, -29), Pair(89, 4), Pair(244, -118), Pair(-29, 17), Pair(167, -104),
        Pair(121, -74), Pair(49, -9), Pair(77, -47), Pair(-33, 39), Pair(136, -26), Pair(0, 71), Pair(47, -37), Pair(42, 16),
        Pair(-6, 49), Pair(20, -87), Pair(-11, 37), Pair(114, -54), Pair(35, 36), Pair(64, -14), Pair(125, -35), Pair(85, -25),
        Pair(120, -117), Pair(-27, 24), Pair(-5, -42), Pair(-18, 33), Pair(25, -24), Pair(71, -30), Pair(97, -36), Pair(-30, 109),
        Pair(-62, 49), Pair(72, -130), Pair(-10, 20), Pair(45, -53), Pair(27, 13), Pair(47, -28), Pair(145, -62), Pair(113, -29)
      },
      { // Piece 3
        Pair(19, 102), Pair(29, -164), Pair(169, 31), Pair(-46, 60), Pair(-52, 58), Pair(-20, 24), Pair(95, 22), Pair(7, 44),
        Pair(26, 24), Pair(0, 0), Pair(56, 10), Pair(126, -28), Pair(214, -54), Pair(-18, 22), Pair(-90, 36), Pair(36, 20),
        Pair(-18, 49), Pair(42, -7), Pair(54, 41), Pair(114, -14), Pair(-66, 45), Pair(16, 13), Pair(96, 27), Pair(36, 34),
        Pair(58, 34), Pair(74, -14), Pair(9, 55), Pair(-13, 50), Pair(-54, 70), Pair(-29, 22), Pair(95, 23), Pair(16, 43),
        Pair(-72, 105), Pair(66, -18), Pair(32, 35), Pair(-35, 55), Pair(106, -25), Pair(28, 18), Pair(-7, 24), Pair(-69, 68),
        Pair(-56, 63), Pair(-18, 16), Pair(50, 11), Pair(117, -8), Pair(-68, 54), Pair(-44, 80), Pair(-49, 114), Pair(-56, -14),
        Pair(54, -10), Pair(-13, 23), Pair(7, 44), Pair(58, -7), Pair(85, 15), Pair(11, 18), Pair(84, -28), Pair(34, -13),
        Pair(20, 26), Pair(14, -10), Pair(11, 37), Pair(2, 33), Pair(-11, 26), Pair(11, 2), Pair(-35, 24), Pair(-36, 23)
      },
      { // Piece 4
        Pair(44, -183), Pair(-94, -94), Pair(61, -64), Pair(142, 29), Pair(-28, -33), Pair(-22, -70), Pair(-53, -86), Pair(31, -31),
        Pair(5, -17), Pair(0, 0), Pair(-12, 29), Pair(-20, -2), Pair(19, -47), Pair(52, -121), Pair(-73, -99), Pair(28, -94),
        Pair(48, -28), Pair(31, 4), Pair(-27, 41), Pair(99, 51), Pair(-45, 22), Pair(-18, -4), Pair(-76, -35), Pair(-90, -5),
        Pair(44, -80), Pair(-84, 136), Pair(-78, 48), Pair(-48, 69), Pair(17, 19), Pair(99, -31), Pair(-56, 3), Pair(59, -136),
        Pair(31, -38), Pair(-4, 32), Pair(17, 76), Pair(39, -40), Pair(-26, 35), Pair(-27, 3), Pair(36, -34), Pair(-81, -11),
        Pair(142, -253), Pair(-61, 53), Pair(-22, 30), Pair(11, -24), Pair(59, -86), Pair(-35, 15), Pair(-22, 123), Pair(-82, 3),
        Pair(-43, 28), Pair(-48, 82), Pair(-57, 40), Pair(-20, 10), Pair(34, -30), Pair(41, -91), Pair(-35, 38), Pair(-49, -43),
        Pair(51, -156), Pair(-63, 56), Pair(69, -182), Pair(-44, 69), Pair(-95, 43), Pair(-59, 36), Pair(16, -45), Pair(88, 3)
      },
      { // Piece 5
        Pair(28, 198), Pair(36, -30), Pair(68, 55), Pair(92, 110), Pair(-13, -53), Pair(-4, 2), Pair(-9, -68), Pair(1, 16),
        Pair(0, 142), Pair(0, 0), Pair(90, 66), Pair(-25, 68), Pair(84, -49), Pair(10, 2), Pair(-36, -20), Pair(-10, -61),
        Pair(23, 100), Pair(45, 44), Pair(118, 25), Pair(12, 37), Pair(68, -30), Pair(20, -21), Pair(-16, -27), Pair(-28, 32),
        Pair(28, 69), Pair(91, -15), Pair(73, 25), Pair(111, -46), Pair(69, -23), Pair(134, -40), Pair(-41, -9), Pair(-54, -32),
        Pair(-15, 15), Pair(116, -6), Pair(51, 3), Pair(92, -27), Pair(70, -35), Pair(-126, 8), Pair(-97, -11), Pair(-24, -40),
        Pair(18, 41), Pair(-76, -34), Pair(17, 12), Pair(-14, -11), Pair(-94, -1), Pair(-16, -30), Pair(-80, -11), Pair(-131, -36),
        Pair(84, 15), Pair(95, 12), Pair(-13, 19), Pair(-55, -15), Pair(-38, -36), Pair(-136, -8), Pair(-40, -33), Pair(-82, -33),
        Pair(-21, 70), Pair(-18, -33), Pair(31, 62), Pair(-1, -34), Pair(-70, -26), Pair(-120, -10), Pair(-67, -37), Pair(-71, -26)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, 20), Pair(72, -11), Pair(-23, 33), Pair(98, -28), Pair(-51, 49), Pair(42, 50), Pair(-2, 31), Pair(10, 16),
        Pair(-19, 15), Pair(10, 3), Pair(-21, -73), Pair(-46, 35), Pair(-30, 32), Pair(-70, 54), Pair(-154, 48), Pair(74, 4),
        Pair(1, 6), Pair(1, 34), Pair(-70, 3), Pair(-19, 37), Pair(-15, 22), Pair(35, 4), Pair(-6, 7), Pair(0, 11),
        Pair(1, 20), Pair(3, 20), Pair(-26, 8), Pair(-20, 20), Pair(-21, 13), Pair(-4, 8), Pair(-21, 14), Pair(10, 5),
        Pair(4, 14), Pair(-33, 22), Pair(-24, 9), Pair(-32, 28), Pair(-8, 7), Pair(-4, 6), Pair(0, 15), Pair(11, 3),
        Pair(-15, 24), Pair(-17, 5), Pair(-32, -2), Pair(-2, -17), Pair(-5, 18), Pair(-7, 13), Pair(-7, 11), Pair(9, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(151, -30), Pair(38, 60), Pair(-8, -30), Pair(29, 72), Pair(124, 22), Pair(15, 23), Pair(-8, -78), Pair(5, 8),
        Pair(-1, 62), Pair(59, 8), Pair(0, 0), Pair(90, 1), Pair(69, 94), Pair(-61, 54), Pair(17, -45), Pair(-115, -103),
        Pair(4, 32), Pair(-24, 87), Pair(112, 48), Pair(18, 84), Pair(61, 35), Pair(87, 41), Pair(80, 3), Pair(6, 31),
        Pair(84, -2), Pair(13, 77), Pair(-60, 97), Pair(140, 3), Pair(-19, 57), Pair(-65, 69), Pair(-22, 39), Pair(-13, 38),
        Pair(15, 47), Pair(-41, 59), Pair(2, 37), Pair(53, 32), Pair(-13, 75), Pair(95, -6), Pair(-5, 35), Pair(5, 95),
        Pair(21, 8), Pair(2, 16), Pair(47, 42), Pair(-20, 59), Pair(-11, 41), Pair(21, -17), Pair(74, -55), Pair(-29, 34),
        Pair(90, 6), Pair(-56, 56), Pair(86, -29), Pair(-5, 29), Pair(7, 48), Pair(117, -16), Pair(-11, -18), Pair(-26, -17),
        Pair(-75, -27), Pair(-19, 11), Pair(-88, 67), Pair(27, -33), Pair(-56, 30), Pair(-79, 13), Pair(47, -72), Pair(2, 43)
      },
      { // Piece 2
        Pair(-28, 68), Pair(30, -9), Pair(-18, -18), Pair(258, -15), Pair(-10, 24), Pair(98, -19), Pair(-18, -30), Pair(-26, -99),
        Pair(155, -45), Pair(-132, 165), Pair(0, 0), Pair(35, 35), Pair(118, -37), Pair(26, 55), Pair(50, -35), Pair(93, 46),
        Pair(178, 29), Pair(120, -20), Pair(-3, 85), Pair(125, -15), Pair(67, 44), Pair(143, -34), Pair(89, -1), Pair(54, -26),
        Pair(13, 12), Pair(30, 43), Pair(145, -25), Pair(93, 20), Pair(191, -27), Pair(234, -15), Pair(110, -14), Pair(-25, 62),
        Pair(-8, 25), Pair(82, -13), Pair(-2, 56), Pair(110, -63), Pair(50, 55), Pair(104, -7), Pair(-18, 56), Pair(55, -29),
        Pair(12, -35), Pair(16, 11), Pair(68, -2), Pair(-1, 35), Pair(64, -36), Pair(66, 11), Pair(114, -23), Pair(88, 0),
        Pair(47, -48), Pair(64, -54), Pair(-17, -18), Pair(-2, -18), Pair(8, 24), Pair(38, -12), Pair(59, 10), Pair(-2, 31),
        Pair(-52, -12), Pair(-42, -2), Pair(29, -32), Pair(31, 31), Pair(70, -26), Pair(-35, 62), Pair(48, -32), Pair(106, 29)
      },
      { // Piece 3
        Pair(36, 69), Pair(-74, 132), Pair(110, -147), Pair(188, 44), Pair(32, 16), Pair(55, 11), Pair(49, 52), Pair(98, 22),
        Pair(-11, 52), Pair(52, 37), Pair(0, 0), Pair(66, 20), Pair(-8, 45), Pair(41, 29), Pair(135, 1), Pair(95, 17),
        Pair(21, 46), Pair(-1, 66), Pair(79, 1), Pair(48, 31), Pair(-95, 92), Pair(41, 67), Pair(-37, 65), Pair(-59, 106),
        Pair(-26, 61), Pair(-1, 54), Pair(74, 22), Pair(22, 58), Pair(-29, 75), Pair(-69, 58), Pair(66, 18), Pair(33, 27),
        Pair(25, 24), Pair(43, 2), Pair(20, 10), Pair(-44, 88), Pair(62, 59), Pair(20, 43), Pair(67, 62), Pair(8, 35),
        Pair(11, 21), Pair(62, 24), Pair(64, -8), Pair(68, 21), Pair(48, -9), Pair(26, 17), Pair(-14, 28), Pair(-30, 100),
        Pair(-82, 49), Pair(39, 24), Pair(40, 31), Pair(-36, 84), Pair(85, -16), Pair(-76, 70), Pair(-27, 71), Pair(-81, 27),
        Pair(-28, 57), Pair(22, 14), Pair(16, 16), Pair(30, 40), Pair(29, 30), Pair(-17, 50), Pair(-12, 19), Pair(-11, -3)
      },
      { // Piece 4
        Pair(-72, -40), Pair(-1, -50), Pair(-122, -161), Pair(33, -22), Pair(63, 19), Pair(55, 22), Pair(-66, -105), Pair(2, -33),
        Pair(51, -65), Pair(-61, 58), Pair(0, 0), Pair(10, 15), Pair(-14, 9), Pair(32, -108), Pair(32, 49), Pair(17, -41),
        Pair(46, -102), Pair(-9, -16), Pair(-15, 18), Pair(-31, 76), Pair(37, -18), Pair(56, -12), Pair(-53, -31), Pair(-32, -101),
        Pair(38, -60), Pair(-123, 143), Pair(-22, 2), Pair(-18, 2), Pair(2, 30), Pair(65, -69), Pair(74, -82), Pair(-22, -35),
        Pair(64, -106), Pair(21, 3), Pair(19, -37), Pair(-51, 59), Pair(-55, 86), Pair(51, -81), Pair(-26, 12), Pair(-1, 75),
        Pair(-38, 86), Pair(-48, -24), Pair(46, -46), Pair(22, -83), Pair(-6, 11), Pair(-8, -49), Pair(83, -115), Pair(101, 41),
        Pair(-54, -16), Pair(-2, -27), Pair(47, -90), Pair(-57, -28), Pair(-33, 32), Pair(21, -70), Pair(21, -110), Pair(68, -18),
        Pair(-15, -4), Pair(-32, 6), Pair(-7, -52), Pair(-39, 2), Pair(12, -110), Pair(-137, -1), Pair(-70, 38), Pair(-27, -18)
      },
      { // Piece 5
        Pair(14, 167), Pair(105, 77), Pair(-12, 23), Pair(-38, 59), Pair(-22, 76), Pair(29, 26), Pair(25, 74), Pair(5, 66),
        Pair(-19, 171), Pair(21, 119), Pair(0, 0), Pair(31, 78), Pair(-16, 4), Pair(-8, 0), Pair(-36, -60), Pair(14, -6),
        Pair(60, 85), Pair(-7, 85), Pair(28, 45), Pair(198, 23), Pair(-19, 25), Pair(145, -36), Pair(89, -23), Pair(22, -20),
        Pair(118, 18), Pair(151, 51), Pair(65, -12), Pair(132, 1), Pair(88, -15), Pair(59, -26), Pair(-97, -12), Pair(18, -33),
        Pair(29, 35), Pair(39, 22), Pair(14, -10), Pair(-105, 1), Pair(-73, 1), Pair(32, -23), Pair(-29, -46), Pair(-20, -48),
        Pair(-222, 46), Pair(-38, 22), Pair(51, -21), Pair(-5, -24), Pair(1, -32), Pair(-105, -18), Pair(-38, -48), Pair(-124, -29),
        Pair(-85, 52), Pair(136, -37), Pair(0, 3), Pair(-26, -1), Pair(-30, -43), Pair(-45, -36), Pair(-34, -36), Pair(-41, -38),
        Pair(5, -28), Pair(13, 39), Pair(-70, -26), Pair(-75, 40), Pair(-78, -24), Pair(-72, -36), Pair(-28, -53), Pair(-66, -40)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 43), Pair(-61, 38), Pair(98, -28), Pair(35, -5), Pair(-64, 8), Pair(-27, 28), Pair(72, -5), Pair(-140, 68),
        Pair(15, 28), Pair(-74, 47), Pair(60, 6), Pair(-23, -54), Pair(1, 4), Pair(58, 19), Pair(-20, 42), Pair(-37, 26),
        Pair(2, 12), Pair(8, 10), Pair(20, 21), Pair(-11, -11), Pair(-6, 37), Pair(0, 20), Pair(-9, 19), Pair(25, 5),
        Pair(6, 11), Pair(2, 15), Pair(-6, 15), Pair(12, -19), Pair(6, 17), Pair(3, 6), Pair(-2, 5), Pair(13, 4),
        Pair(9, 19), Pair(2, 6), Pair(-1, 13), Pair(-4, 8), Pair(1, 1), Pair(13, 4), Pair(-14, 11), Pair(13, 4),
        Pair(3, 10), Pair(-12, 12), Pair(-13, 3), Pair(-44, 19), Pair(-3, 10), Pair(-2, 9), Pair(-2, 11), Pair(-11, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-79, -66), Pair(28, 23), Pair(21, 64), Pair(-58, -77), Pair(41, 42), Pair(57, 95), Pair(-17, -66), Pair(-1, -1),
        Pair(21, 77), Pair(37, 75), Pair(-84, 60), Pair(0, 0), Pair(40, 36), Pair(-41, 57), Pair(28, 72), Pair(-71, 62),
        Pair(-29, 20), Pair(95, 25), Pair(36, 77), Pair(125, 15), Pair(109, 56), Pair(146, -23), Pair(74, 79), Pair(88, 1),
        Pair(-59, 101), Pair(-11, 30), Pair(85, 38), Pair(137, 5), Pair(39, 47), Pair(98, 14), Pair(55, 33), Pair(-3, 15),
        Pair(60, 55), Pair(41, 62), Pair(43, 21), Pair(65, 46), Pair(40, 45), Pair(45, 55), Pair(57, -9), Pair(60, 19),
        Pair(-47, 86), Pair(-1, 20), Pair(22, -26), Pair(61, 32), Pair(7, 4), Pair(27, 14), Pair(32, 22), Pair(10, 34),
        Pair(-6, -44), Pair(10, -58), Pair(-6, 8), Pair(-27, 26), Pair(0, 41), Pair(68, 16), Pair(-36, 43), Pair(8, 71),
        Pair(-5, 8), Pair(-8, -45), Pair(91, 82), Pair(-58, 32), Pair(-25, -21), Pair(-34, -9), Pair(20, -49), Pair(7, -49)
      },
      { // Piece 2
        Pair(110, -12), Pair(-16, 1), Pair(27, -12), Pair(-189, -53), Pair(0, -26), Pair(-64, 2), Pair(18, -64), Pair(-55, -76),
        Pair(-50, 90), Pair(88, -64), Pair(-54, 53), Pair(0, 0), Pair(133, 39), Pair(99, -73), Pair(83, 27), Pair(-27, -54),
        Pair(37, -14), Pair(28, 74), Pair(107, -21), Pair(181, 27), Pair(130, -30), Pair(112, 69), Pair(38, -35), Pair(226, -35),
        Pair(64, 77), Pair(91, -18), Pair(10, 61), Pair(51, -31), Pair(-6, 73), Pair(115, -20), Pair(34, 59), Pair(110, -26),
        Pair(77, -24), Pair(75, 11), Pair(35, -20), Pair(30, 6), Pair(94, -17), Pair(-19, 78), Pair(55, -11), Pair(92, 88),
        Pair(137, -23), Pair(-2, -1), Pair(76, 7), Pair(25, -33), Pair(11, 48), Pair(10, -1), Pair(58, 11), Pair(66, -14),
        Pair(-99, 2), Pair(70, -26), Pair(-19, -9), Pair(-51, 88), Pair(-2, -9), Pair(-17, 14), Pair(30, -15), Pair(26, 22),
        Pair(41, -11), Pair(-6, -11), Pair(35, 10), Pair(103, -49), Pair(-25, 25), Pair(42, -45), Pair(42, -108), Pair(119, -72)
      },
      { // Piece 3
        Pair(0, 79), Pair(-40, 61), Pair(61, 69), Pair(-38, -114), Pair(105, 81), Pair(-63, 83), Pair(59, 46), Pair(81, 75),
        Pair(25, 39), Pair(50, 40), Pair(3, 45), Pair(0, 0), Pair(50, 24), Pair(11, 37), Pair(-121, 64), Pair(49, 54),
        Pair(44, 29), Pair(12, 49), Pair(13, 65), Pair(83, -16), Pair(-37, 66), Pair(27, 27), Pair(38, 54), Pair(-10, 41),
        Pair(29, 50), Pair(175, -15), Pair(101, 7), Pair(7, 47), Pair(-70, 89), Pair(39, 71), Pair(85, -2), Pair(99, 11),
        Pair(57, 1), Pair(-60, 70), Pair(44, 65), Pair(17, 34), Pair(-80, 84), Pair(9, 49), Pair(84, 65), Pair(-14, 57),
        Pair(-40, 58), Pair(-187, 131), Pair(-44, 57), Pair(2, 27), Pair(10, 42), Pair(12, 13), Pair(-39, 61), Pair(-123, 118),
        Pair(33, -12), Pair(-25, 43), Pair(-110, 82), Pair(41, 5), Pair(0, 51), Pair(-40, 60), Pair(-101, 68), Pair(-27, 35),
        Pair(-33, 37), Pair(-11, 29), Pair(13, 19), Pair(38, 16), Pair(17, 22), Pair(-29, 55), Pair(-23, 37), Pair(-67, 35)
      },
      { // Piece 4
        Pair(3, 91), Pair(-43, -3), Pair(-45, 37), Pair(-116, -133), Pair(1, -50), Pair(-18, -18), Pair(-42, -32), Pair(-64, -57),
        Pair(-28, 53), Pair(-25, -5), Pair(-53, 81), Pair(0, 0), Pair(61, -60), Pair(39, 23), Pair(-46, -95), Pair(49, -78),
        Pair(44, -1), Pair(-81, 13), Pair(95, -100), Pair(21, -52), Pair(15, -6), Pair(86, -9), Pair(40, 52), Pair(-51, -46),
        Pair(87, -37), Pair(-3, 11), Pair(47, -63), Pair(20, -4), Pair(-36, 40), Pair(74, -45), Pair(-17, 82), Pair(30, 81),
        Pair(-42, 47), Pair(-69, 36), Pair(24, 9), Pair(34, 1), Pair(8, 78), Pair(-107, 136), Pair(21, -53), Pair(7, -37),
        Pair(-76, -8), Pair(-62, 51), Pair(37, -21), Pair(-29, 51), Pair(-15, 47), Pair(-14, 35), Pair(12, 20), Pair(-30, -19),
        Pair(29, -107), Pair(-85, 65), Pair(-17, 25), Pair(-66, 100), Pair(-53, 78), Pair(0, 62), Pair(-37, -97), Pair(11, -41),
        Pair(71, -48), Pair(108, -47), Pair(-13, 44), Pair(8, -85), Pair(8, -27), Pair(-64, -100), Pair(-16, -77), Pair(1, -33)
      },
      { // Piece 5
        Pair(6, 98), Pair(40, 148), Pair(-1, 64), Pair(99, -42), Pair(-15, 40), Pair(-3, 80), Pair(-7, -47), Pair(6, 108),
        Pair(-1, 2), Pair(-1, 61), Pair(167, 76), Pair(0, 0), Pair(-28, 99), Pair(6, 40), Pair(-1, -46), Pair(17, 53),
        Pair(-4, 79), Pair(18, 45), Pair(77, 57), Pair(59, 37), Pair(74, 29), Pair(23, 21), Pair(-11, -16), Pair(-16, 2),
        Pair(98, 13), Pair(102, 0), Pair(122, 13), Pair(89, 5), Pair(179, -22), Pair(21, -22), Pair(48, -26), Pair(55, -44),
        Pair(-61, 43), Pair(-38, 15), Pair(-26, 13), Pair(26, -5), Pair(175, -55), Pair(54, -28), Pair(-104, -1), Pair(-138, -16),
        Pair(55, -24), Pair(53, -27), Pair(52, -13), Pair(-6, -10), Pair(-59, -26), Pair(-28, -18), Pair(-63, -12), Pair(-71, -24),
        Pair(81, -46), Pair(-21, -1), Pair(-54, 5), Pair(-123, 24), Pair(-116, -18), Pair(-52, -33), Pair(-30, -32), Pair(-12, -50),
        Pair(117, -123), Pair(2, -43), Pair(-78, 2), Pair(-31, -40), Pair(-184, 37), Pair(-42, -48), Pair(-45, -36), Pair(-37, -56)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(61, 45), Pair(-24, 47), Pair(-51, 49), Pair(-64, 8), Pair(41, 9), Pair(47, -3), Pair(-41, 46), Pair(91, 23),
        Pair(-51, 53), Pair(-36, 19), Pair(-117, 71), Pair(-1, 6), Pair(117, -70), Pair(76, -16), Pair(5, 22), Pair(0, 14),
        Pair(10, 14), Pair(-15, 24), Pair(-21, 23), Pair(-9, 40), Pair(13, -7), Pair(8, 20), Pair(24, -3), Pair(-11, 10),
        Pair(-5, 14), Pair(22, 4), Pair(-11, 12), Pair(3, 19), Pair(-21, 6), Pair(-3, 20), Pair(18, -5), Pair(-18, 8),
        Pair(10, 12), Pair(-6, 13), Pair(-11, 16), Pair(1, 6), Pair(-3, 3), Pair(-9, 10), Pair(-8, 3), Pair(-15, 12),
        Pair(6, 4), Pair(14, -1), Pair(-11, 10), Pair(-91, 54), Pair(-24, -20), Pair(-4, 8), Pair(-9, 10), Pair(-18, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(35, 17), Pair(-71, 74), Pair(58, -13), Pair(119, 49), Pair(-14, 11), Pair(147, 30), Pair(21, 49), Pair(-5, -8),
        Pair(-180, -34), Pair(-134, 158), Pair(133, -26), Pair(89, 54), Pair(0, 0), Pair(-46, 60), Pair(55, 78), Pair(12, -36),
        Pair(83, 108), Pair(12, 45), Pair(56, 19), Pair(-2, 36), Pair(58, 48), Pair(59, 14), Pair(95, -25), Pair(14, 11),
        Pair(-129, 41), Pair(138, -16), Pair(-78, 79), Pair(58, 42), Pair(157, -3), Pair(62, 72), Pair(1, 17), Pair(173, -16),
        Pair(-83, -85), Pair(-29, -58), Pair(54, -15), Pair(-2, 35), Pair(-44, 96), Pair(9, 49), Pair(-28, 22), Pair(68, 34),
        Pair(-44, -22), Pair(-110, 19), Pair(-44, 26), Pair(16, 6), Pair(152, -32), Pair(-7, 1), Pair(116, 8), Pair(135, -103),
        Pair(28, -7), Pair(-72, -46), Pair(92, -33), Pair(-28, -3), Pair(20, -22), Pair(27, 6), Pair(109, 29), Pair(-15, -40),
        Pair(-41, -24), Pair(-42, -52), Pair(-9, 77), Pair(131, -62), Pair(-112, 2), Pair(-14, -43), Pair(67, 27), Pair(-7, -3)
      },
      { // Piece 2
        Pair(94, 28), Pair(-74, -52), Pair(-17, 2), Pair(153, -19), Pair(24, 8), Pair(67, -44), Pair(-24, -50), Pair(1, -7),
        Pair(30, 3), Pair(28, 38), Pair(-7, -31), Pair(147, 86), Pair(0, 0), Pair(-35, 63), Pair(-23, -28), Pair(124, 29),
        Pair(-101, 91), Pair(9, -44), Pair(-34, 48), Pair(130, -41), Pair(-32, 37), Pair(-11, 3), Pair(55, 51), Pair(0, -62),
        Pair(18, -23), Pair(-75, 94), Pair(77, -31), Pair(-106, 60), Pair(133, -66), Pair(71, -27), Pair(118, -26), Pair(16, 68),
        Pair(-33, 55), Pair(107, -38), Pair(32, 34), Pair(39, -24), Pair(112, -13), Pair(39, -42), Pair(81, -18), Pair(32, -4),
        Pair(86, -28), Pair(45, -9), Pair(44, -49), Pair(27, -2), Pair(91, -14), Pair(86, -41), Pair(75, -48), Pair(14, 29),
        Pair(-114, 91), Pair(-19, -4), Pair(197, -72), Pair(-8, -24), Pair(43, -14), Pair(25, 19), Pair(24, 9), Pair(-97, 1),
        Pair(160, -106), Pair(65, -40), Pair(-19, -43), Pair(-111, -9), Pair(-50, -34), Pair(-11, -30), Pair(141, -105), Pair(-135, 23)
      },
      { // Piece 3
        Pair(-102, 93), Pair(48, 12), Pair(-9, 15), Pair(23, 44), Pair(-96, -105), Pair(126, 25), Pair(69, 6), Pair(37, 23),
        Pair(3, 21), Pair(-52, 28), Pair(-10, 11), Pair(55, -13), Pair(0, 0), Pair(96, -21), Pair(60, -6), Pair(6, 9),
        Pair(39, 47), Pair(30, -3), Pair(12, -8), Pair(102, -6), Pair(76, -41), Pair(1, 18), Pair(-74, 12), Pair(-24, 56),
        Pair(-32, 3), Pair(71, -10), Pair(3, 53), Pair(85, 37), Pair(93, -29), Pair(6, 47), Pair(-49, 52), Pair(12, 32),
        Pair(130, -30), Pair(-4, 45), Pair(-43, -1), Pair(-60, 29), Pair(6, 9), Pair(76, -25), Pair(-47, 82), Pair(-116, 61),
        Pair(69, -35), Pair(57, -3), Pair(25, 42), Pair(65, 5), Pair(-18, 18), Pair(-49, 20), Pair(-3, 6), Pair(-32, -23),
        Pair(93, -16), Pair(29, -9), Pair(-31, -13), Pair(14, -3), Pair(35, -30), Pair(-38, 40), Pair(-54, 2), Pair(-42, 9),
        Pair(-54, 11), Pair(-5, -4), Pair(27, -15), Pair(48, -3), Pair(-2, 9), Pair(-19, 26), Pair(0, 1), Pair(-4, -20)
      },
      { // Piece 4
        Pair(-31, -55), Pair(75, 63), Pair(28, 62), Pair(-2, -6), Pair(-170, -118), Pair(-24, -64), Pair(-56, -93), Pair(-30, -39),
        Pair(4, -29), Pair(-47, 25), Pair(27, -74), Pair(28, -87), Pair(0, 0), Pair(140, -98), Pair(-56, -58), Pair(-53, 39),
        Pair(-47, 70), Pair(51, 8), Pair(-6, 28), Pair(-23, -15), Pair(-10, -11), Pair(21, -1), Pair(84, 43), Pair(38, 21),
        Pair(-68, -86), Pair(-24, 26), Pair(55, -13), Pair(39, 1), Pair(4, 31), Pair(17, -36), Pair(7, 33), Pair(3, 30),
        Pair(-120, 59), Pair(54, -45), Pair(24, 17), Pair(101, -109), Pair(96, -109), Pair(32, 66), Pair(107, -122), Pair(53, -145),
        Pair(-19, -68), Pair(-72, 61), Pair(-6, 27), Pair(61, -52), Pair(-65, 86), Pair(-50, 8), Pair(15, -86), Pair(-62, -32),
        Pair(-94, -41), Pair(8, -95), Pair(-30, -56), Pair(8, -42), Pair(-42, -19), Pair(-38, 72), Pair(-25, -39), Pair(-18, -28),
        Pair(-111, -21), Pair(89, -102), Pair(-63, -116), Pair(-107, 73), Pair(-23, -43), Pair(-51, -7), Pair(-21, -45), Pair(12, 4)
      },
      { // Piece 5
        Pair(16, -6), Pair(-27, -127), Pair(-9, 63), Pair(-36, 22), Pair(-6, -66), Pair(28, 35), Pair(58, 81), Pair(10, 72),
        Pair(-61, -23), Pair(19, -44), Pair(-3, 28), Pair(-40, 94), Pair(0, 0), Pair(43, 118), Pair(75, 57), Pair(38, 59),
        Pair(-4, 4), Pair(90, -48), Pair(20, 48), Pair(15, 53), Pair(61, 53), Pair(46, 52), Pair(96, 22), Pair(41, -40),
        Pair(-64, -13), Pair(-18, 34), Pair(103, -26), Pair(-5, 16), Pair(-36, 10), Pair(79, 13), Pair(88, -47), Pair(-49, -17),
        Pair(-46, 0), Pair(58, -17), Pair(-18, 29), Pair(124, -18), Pair(-103, 15), Pair(71, -26), Pair(-10, -13), Pair(-15, -43),
        Pair(-53, -4), Pair(-50, 3), Pair(130, -50), Pair(-134, 16), Pair(-111, 10), Pair(-35, -37), Pair(10, -42), Pair(8, -40),
        Pair(-175, 68), Pair(14, -39), Pair(6, -17), Pair(50, -46), Pair(-201, 18), Pair(-38, -38), Pair(29, -56), Pair(54, -60),
        Pair(-45, 76), Pair(10, -19), Pair(-140, 9), Pair(-10, -1), Pair(-59, -65), Pair(-30, -6), Pair(49, -60), Pair(36, -77)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-75, 46), Pair(-18, 46), Pair(42, 50), Pair(-27, 28), Pair(47, -3), Pair(8, 5), Pair(32, 4), Pair(47, 16),
        Pair(64, -8), Pair(-40, 24), Pair(-27, 36), Pair(-19, 45), Pair(-26, -9), Pair(16, -61), Pair(33, -20), Pair(12, 5),
        Pair(19, 14), Pair(-5, 15), Pair(-72, 45), Pair(35, -8), Pair(-22, 36), Pair(10, -19), Pair(30, 6), Pair(-25, 10),
        Pair(-7, 15), Pair(50, -5), Pair(21, 6), Pair(-3, 7), Pair(-8, 8), Pair(-10, -15), Pair(15, 3), Pair(-35, 11),
        Pair(0, 17), Pair(3, 9), Pair(3, -5), Pair(12, 4), Pair(-25, 18), Pair(-36, 4), Pair(-13, 7), Pair(-6, 1),
        Pair(6, 3), Pair(-2, 11), Pair(-14, 16), Pair(13, -7), Pair(-41, 39), Pair(-6, 3), Pair(-4, 9), Pair(-4, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(2, 46), Pair(-3, -25), Pair(-17, 30), Pair(101, -31), Pair(60, 88), Pair(73, -3), Pair(79, 32), Pair(-9, -60),
        Pair(9, 60), Pair(-1, -17), Pair(-12, -29), Pair(-45, 18), Pair(-132, -8), Pair(0, 0), Pair(34, 4), Pair(3, 66),
        Pair(20, 64), Pair(-26, 16), Pair(-103, 75), Pair(120, -31), Pair(122, -77), Pair(8, 11), Pair(128, 100), Pair(58, -45),
        Pair(-64, -101), Pair(-141, 34), Pair(-101, 27), Pair(26, 17), Pair(105, -5), Pair(27, 24), Pair(80, -8), Pair(151, -28),
        Pair(37, -17), Pair(-63, -17), Pair(34, -45), Pair(24, 14), Pair(11, 23), Pair(100, -28), Pair(-36, 41), Pair(71, -83),
        Pair(-41, -48), Pair(29, -23), Pair(37, -48), Pair(-13, 58), Pair(-50, 43), Pair(-4, 37), Pair(45, -63), Pair(4, 11),
        Pair(-17, 68), Pair(29, 3), Pair(74, -134), Pair(-29, -26), Pair(26, -51), Pair(-151, 6), Pair(126, -99), Pair(16, -89),
        Pair(-8, -27), Pair(-35, 37), Pair(-109, 71), Pair(76, -32), Pair(-217, -49), Pair(-127, 46), Pair(6, 86), Pair(28, -29)
      },
      { // Piece 2
        Pair(-51, -84), Pair(-28, 80), Pair(-58, -13), Pair(4, 44), Pair(51, -31), Pair(-52, 85), Pair(63, -40), Pair(-6, 7),
        Pair(-19, -12), Pair(95, -61), Pair(79, 123), Pair(63, -117), Pair(-113, 75), Pair(0, 0), Pair(74, 9), Pair(90, -73),
        Pair(-145, -109), Pair(-57, -6), Pair(48, -83), Pair(117, 69), Pair(150, -69), Pair(123, 55), Pair(70, -35), Pair(94, 2),
        Pair(-42, 29), Pair(-35, -58), Pair(-50, 28), Pair(86, -25), Pair(63, -1), Pair(19, -35), Pair(-31, 45), Pair(52, -25),
        Pair(-32, -66), Pair(-82, 25), Pair(39, -27), Pair(202, -23), Pair(-12, -17), Pair(97, -2), Pair(79, -94), Pair(37, 44),
        Pair(43, 30), Pair(70, -52), Pair(7, -2), Pair(4, -48), Pair(30, 20), Pair(60, -58), Pair(46, 46), Pair(58, -55),
        Pair(-155, -3), Pair(7, 38), Pair(26, -47), Pair(47, 2), Pair(-8, -18), Pair(-22, 87), Pair(8, -75), Pair(109, -47),
        Pair(48, 17), Pair(-13, -69), Pair(-29, 20), Pair(-124, 15), Pair(117, -11), Pair(20, -29), Pair(83, 22), Pair(99, -112)
      },
      { // Piece 3
        Pair(49, 60), Pair(-26, 30), Pair(119, 35), Pair(114, 64), Pair(50, 49), Pair(-17, -126), Pair(-90, 82), Pair(101, 51),
        Pair(-13, 4), Pair(10, 8), Pair(63, -2), Pair(55, 3), Pair(40, -11), Pair(0, 0), Pair(2, 20), Pair(-51, 49),
        Pair(-65, 19), Pair(72, 7), Pair(72, -10), Pair(-24, -14), Pair(-48, 61), Pair(94, -51), Pair(89, 37), Pair(-10, 19),
        Pair(118, -48), Pair(150, -43), Pair(11, -18), Pair(90, 1), Pair(7, 58), Pair(84, 14), Pair(36, -3), Pair(19, 32),
        Pair(84, -32), Pair(57, -14), Pair(-62, -7), Pair(26, 6), Pair(59, 24), Pair(44, 1), Pair(-10, 58), Pair(-43, 54),
        Pair(29, -28), Pair(-96, 39), Pair(-23, -56), Pair(-54, 45), Pair(-92, 64), Pair(-13, 12), Pair(-32, 64), Pair(47, -59),
        Pair(-15, -30), Pair(-110, 19), Pair(-35, 12), Pair(-155, 86), Pair(-14, 49), Pair(-20, -8), Pair(53, -50), Pair(107, -44),
        Pair(-52, 21), Pair(-18, -12), Pair(-37, 26), Pair(-38, 6), Pair(16, 0), Pair(35, -17), Pair(-7, 18), Pair(6, -14)
      },
      { // Piece 4
        Pair(-25, -9), Pair(-38, -51), Pair(-73, -130), Pair(30, 64), Pair(47, -57), Pair(-99, -144), Pair(-67, -87), Pair(-44, -69),
        Pair(63, -18), Pair(18, 54), Pair(-90, 13), Pair(8, 121), Pair(108, -81), Pair(0, 0), Pair(1, -61), Pair(29, 102),
        Pair(31, -53), Pair(82, -267), Pair(110, 41), Pair(-10, -59), Pair(17, 110), Pair(69, -52), Pair(-35, 56), Pair(-65, -67),
        Pair(-22, -111), Pair(-61, -72), Pair(15, -48), Pair(-3, -83), Pair(53, 15), Pair(28, -82), Pair(85, -134), Pair(-5, 63),
        Pair(-54, -22), Pair(-100, -62), Pair(39, -51), Pair(8, 28), Pair(-18, -144), Pair(30, 50), Pair(-14, 76), Pair(21, 14),
        Pair(-63, -57), Pair(-82, -16), Pair(3, -18), Pair(53, -27), Pair(-21, -60), Pair(1, -27), Pair(-22, -12), Pair(-60, 34),
        Pair(-21, -94), Pair(-35, -20), Pair(-36, -59), Pair(60, -71), Pair(-32, -42), Pair(-6, -42), Pair(-142, 128), Pair(-69, -34),
        Pair(178, 48), Pair(-88, -1), Pair(-122, 15), Pair(-38, -107), Pair(33, -16), Pair(-68, -9), Pair(-72, -75), Pair(-102, -49)
      },
      { // Piece 5
        Pair(-8, -45), Pair(-2, -14), Pair(-17, -106), Pair(45, 21), Pair(44, 24), Pair(1, -42), Pair(25, 50), Pair(-10, 74),
        Pair(14, 67), Pair(-24, -30), Pair(1, -21), Pair(71, 45), Pair(29, 88), Pair(0, 0), Pair(50, 90), Pair(-8, 130),
        Pair(10, -3), Pair(38, -21), Pair(-21, -3), Pair(-57, 63), Pair(8, 36), Pair(25, 47), Pair(154, 17), Pair(17, 41),
        Pair(-5, 67), Pair(-64, -28), Pair(-7, 6), Pair(93, -11), Pair(29, 24), Pair(138, 13), Pair(38, 19), Pair(-6, 27),
        Pair(-43, -18), Pair(-59, 19), Pair(-73, 1), Pair(8, -1), Pair(-20, 11), Pair(35, 10), Pair(118, -18), Pair(-10, 1),
        Pair(-69, -7), Pair(-44, -28), Pair(80, -44), Pair(216, -38), Pair(-17, -31), Pair(44, -13), Pair(-112, 6), Pair(39, -39),
        Pair(15, -34), Pair(-169, 56), Pair(91, -38), Pair(-129, -4), Pair(-64, -14), Pair(-33, -21), Pair(28, -31), Pair(56, -34),
        Pair(-151, -6), Pair(-7, 19), Pair(5, -32), Pair(-86, -53), Pair(-47, -4), Pair(-92, 59), Pair(0, -46), Pair(-37, 5)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-33, 34), Pair(-10, 20), Pair(-2, 31), Pair(72, -5), Pair(-41, 46), Pair(32, 4), Pair(-44, 22), Pair(-2, -66),
        Pair(-19, 15), Pair(4, 25), Pair(-60, 29), Pair(93, -15), Pair(-21, 25), Pair(25, -14), Pair(151, -122), Pair(58, -33),
        Pair(29, -10), Pair(-45, 30), Pair(32, 5), Pair(-2, 18), Pair(17, 4), Pair(-26, 22), Pair(24, -18), Pair(-3, 33),
        Pair(-3, 2), Pair(-9, 7), Pair(3, 7), Pair(3, 8), Pair(-11, 20), Pair(-24, 16), Pair(10, -21), Pair(8, 20),
        Pair(1, -4), Pair(-1, 11), Pair(9, 4), Pair(11, -8), Pair(-8, 10), Pair(42, -4), Pair(3, -8), Pair(-12, 14),
        Pair(-12, 20), Pair(4, 5), Pair(-12, 21), Pair(0, 13), Pair(-22, 24), Pair(-11, 17), Pair(11, -8), Pair(-26, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-10, 15), Pair(6, 9), Pair(-33, -106), Pair(-36, 36), Pair(90, 14), Pair(-153, 36), Pair(27, -20), Pair(5, 18),
        Pair(-70, -41), Pair(-85, 7), Pair(12, 3), Pair(76, 2), Pair(105, 75), Pair(192, -56), Pair(0, 0), Pair(237, -51),
        Pair(14, -21), Pair(-14, -7), Pair(-31, 12), Pair(76, 27), Pair(127, -17), Pair(84, -2), Pair(111, -25), Pair(44, 54),
        Pair(-8, -99), Pair(81, 37), Pair(-2, 16), Pair(108, 72), Pair(13, -9), Pair(135, -8), Pair(15, -9), Pair(28, 11),
        Pair(-94, 56), Pair(136, 18), Pair(76, -49), Pair(-11, 5), Pair(48, 29), Pair(3, 5), Pair(38, 63), Pair(59, -42),
        Pair(-33, 35), Pair(-57, 35), Pair(60, -88), Pair(-27, 23), Pair(-34, 19), Pair(0, 3), Pair(-17, 20), Pair(121, -160),
        Pair(150, -31), Pair(89, -34), Pair(-106, -2), Pair(-79, 15), Pair(-45, -5), Pair(-34, -49), Pair(31, -87), Pair(47, 6),
        Pair(-88, -94), Pair(-44, -43), Pair(-148, 84), Pair(-117, 54), Pair(98, -33), Pair(-129, -38), Pair(-31, -20), Pair(6, 30)
      },
      { // Piece 2
        Pair(-40, -8), Pair(31, 13), Pair(-32, 11), Pair(18, -152), Pair(-8, -49), Pair(-32, 27), Pair(-134, -92), Pair(-64, -137),
        Pair(-71, -45), Pair(7, 27), Pair(94, -81), Pair(87, -58), Pair(165, -59), Pair(-10, 70), Pair(0, 0), Pair(-30, 18),
        Pair(85, -10), Pair(140, -114), Pair(-21, -3), Pair(49, -80), Pair(89, 68), Pair(122, -43), Pair(35, 110), Pair(-8, -12),
        Pair(-114, -70), Pair(20, 47), Pair(14, -72), Pair(118, -88), Pair(154, -48), Pair(18, 5), Pair(57, -60), Pair(16, 19),
        Pair(-117, 19), Pair(101, -79), Pair(20, -9), Pair(117, -53), Pair(-46, 64), Pair(9, -33), Pair(106, -59), Pair(72, -108),
        Pair(-24, -9), Pair(134, -40), Pair(79, -39), Pair(73, -33), Pair(49, -84), Pair(54, 29), Pair(-14, -36), Pair(36, -32),
        Pair(39, -70), Pair(58, -14), Pair(-60, 36), Pair(10, -47), Pair(19, -14), Pair(-30, -26), Pair(-3, 9), Pair(-118, 97),
        Pair(78, -29), Pair(62, -37), Pair(-8, -71), Pair(-24, 28), Pair(-46, -41), Pair(-55, 7), Pair(-6, -103), Pair(12, -35)
      },
      { // Piece 3
        Pair(-90, 37), Pair(98, 8), Pair(55, -4), Pair(27, 60), Pair(12, 37), Pair(79, 43), Pair(-76, -110), Pair(155, 41),
        Pair(231, -60), Pair(84, -24), Pair(39, -13), Pair(92, -37), Pair(-15, 6), Pair(-7, -4), Pair(0, 0), Pair(-28, 20),
        Pair(11, -4), Pair(63, -37), Pair(57, -29), Pair(139, -44), Pair(92, -38), Pair(-16, 13), Pair(26, -24), Pair(161, -35),
        Pair(-200, 85), Pair(73, -43), Pair(-94, 32), Pair(-81, -7), Pair(-9, -11), Pair(7, 13), Pair(9, -1), Pair(-37, 48),
        Pair(-79, 74), Pair(45, -44), Pair(21, -61), Pair(0, 19), Pair(48, 19), Pair(16, -2), Pair(191, -79), Pair(-106, 89),
        Pair(-218, 57), Pair(-84, 29), Pair(-215, 150), Pair(-30, 74), Pair(25, 21), Pair(52, -22), Pair(60, -3), Pair(-125, 49),
        Pair(-72, -19), Pair(-69, -12), Pair(8, -22), Pair(21, -46), Pair(77, -46), Pair(-50, 63), Pair(76, -9), Pair(-2, 17),
        Pair(-20, -50), Pair(-72, -1), Pair(-28, -10), Pair(-18, -4), Pair(-9, 0), Pair(-21, 0), Pair(66, -27), Pair(20, -2)
      },
      { // Piece 4
        Pair(134, 9), Pair(-190, -172), Pair(-9, 7), Pair(-49, -43), Pair(-43, -36), Pair(118, -66), Pair(-15, -27), Pair(103, -190),
        Pair(-38, -87), Pair(23, -70), Pair(-80, -34), Pair(41, 41), Pair(20, -201), Pair(63, -57), Pair(0, 0), Pair(-37, -109),
        Pair(70, 12), Pair(-128, -143), Pair(91, 21), Pair(-1, 104), Pair(52, -19), Pair(91, -138), Pair(-24, 44), Pair(23, 67),
        Pair(146, -5), Pair(-58, -16), Pair(79, -14), Pair(39, 5), Pair(-19, -78), Pair(40, 57), Pair(-16, 6), Pair(67, 51),
        Pair(6, -50), Pair(-121, -78), Pair(-49, -59), Pair(-32, -9), Pair(7, 22), Pair(-110, 59), Pair(-79, 98), Pair(-3, -87),
        Pair(-10, -129), Pair(-127, -48), Pair(-8, -34), Pair(70, -43), Pair(-122, 111), Pair(-54, 65), Pair(-17, -35), Pair(79, 89),
        Pair(14, 16), Pair(-39, -76), Pair(-18, 27), Pair(-85, 47), Pair(-66, -79), Pair(-35, -29), Pair(-38, -47), Pair(72, -30),
        Pair(-37, -131), Pair(-49, -48), Pair(-108, 33), Pair(-116, 120), Pair(-35, -101), Pair(-29, -22), Pair(-203, 29), Pair(209, 85)
      },
      { // Piece 5
        Pair(0, -26), Pair(-11, -129), Pair(17, 48), Pair(26, 135), Pair(4, 107), Pair(-40, 39), Pair(-43, -1), Pair(13, 29),
        Pair(-15, 11), Pair(1, 24), Pair(-22, -47), Pair(4, -82), Pair(17, 21), Pair(-97, 103), Pair(0, 0), Pair(-101, 92),
        Pair(-102, -24), Pair(-20, -10), Pair(-29, 7), Pair(-16, -12), Pair(23, 40), Pair(60, 41), Pair(99, 48), Pair(-62, 92),
        Pair(-40, -46), Pair(14, 3), Pair(0, -2), Pair(122, -5), Pair(15, -20), Pair(71, 33), Pair(31, 25), Pair(97, 32),
        Pair(28, -36), Pair(69, -28), Pair(-62, 17), Pair(-8, -27), Pair(6, -8), Pair(83, -11), Pair(33, 26), Pair(-90, 34),
        Pair(-75, -10), Pair(-8, 11), Pair(47, -36), Pair(3, 21), Pair(84, -20), Pair(-40, -7), Pair(25, -8), Pair(-64, 6),
        Pair(44, -15), Pair(15, -19), Pair(-21, 7), Pair(-43, -24), Pair(-67, 0), Pair(6, 16), Pair(42, -3), Pair(39, 18),
        Pair(30, -79), Pair(-66, 4), Pair(-64, 11), Pair(-113, 0), Pair(-29, -11), Pair(-15, 14), Pair(31, -34), Pair(55, -25)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(53, 5), Pair(38, 35), Pair(10, 16), Pair(-140, 68), Pair(91, 23), Pair(47, 16), Pair(-2, -66), Pair(-54, -7),
        Pair(-24, 26), Pair(-61, 52), Pair(-46, 51), Pair(37, 13), Pair(30, 9), Pair(31, -3), Pair(-44, -21), Pair(47, -95),
        Pair(-30, 20), Pair(-2, 18), Pair(-11, 17), Pair(11, 15), Pair(1, 10), Pair(17, 20), Pair(2, 30), Pair(20, -3),
        Pair(12, 8), Pair(-3, 10), Pair(-14, 19), Pair(-3, 4), Pair(1, 4), Pair(6, 4), Pair(-7, 18), Pair(38, -13),
        Pair(-24, 24), Pair(-10, 8), Pair(11, -1), Pair(11, -3), Pair(5, 4), Pair(1, 8), Pair(-12, 6), Pair(15, 10),
        Pair(-22, 21), Pair(-10, 10), Pair(-17, 17), Pair(-16, 2), Pair(-2, 5), Pair(4, 5), Pair(-21, 13), Pair(20, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(11, 95), Pair(-1, 0), Pair(-18, -40), Pair(-9, -48), Pair(22, 85), Pair(-12, -12), Pair(-10, 37), Pair(72, 105),
        Pair(75, 41), Pair(33, 51), Pair(13, -55), Pair(16, 7), Pair(79, -31), Pair(89, 39), Pair(-80, 16), Pair(0, 0),
        Pair(-129, 4), Pair(48, 11), Pair(36, -12), Pair(59, -11), Pair(157, 9), Pair(55, -6), Pair(28, 34), Pair(1, -3),
        Pair(-68, -23), Pair(-22, 15), Pair(58, -3), Pair(46, 24), Pair(113, 30), Pair(99, -19), Pair(88, -5), Pair(124, 41),
        Pair(-49, 17), Pair(-133, -14), Pair(26, -14), Pair(58, -44), Pair(150, -31), Pair(118, -15), Pair(42, -5), Pair(100, -64),
        Pair(-41, -83), Pair(-5, -56), Pair(36, -82), Pair(104, -21), Pair(-40, -21), Pair(3, 5), Pair(53, -60), Pair(7, 75),
        Pair(8, 5), Pair(2, -20), Pair(-34, -9), Pair(-40, -10), Pair(10, -3), Pair(-2, -11), Pair(-12, -19), Pair(-76, -15),
        Pair(-66, -29), Pair(-69, -13), Pair(-24, -46), Pair(-46, -22), Pair(-177, -14), Pair(-87, 34), Pair(-23, -81), Pair(-63, -25)
      },
      { // Piece 2
        Pair(25, -119), Pair(-8, -23), Pair(58, -50), Pair(-10, -44), Pair(19, -51), Pair(45, 70), Pair(86, -27), Pair(16, -68),
        Pair(-103, 19), Pair(47, -105), Pair(18, -7), Pair(-79, -91), Pair(157, 3), Pair(159, -90), Pair(38, 32), Pair(0, 0),
        Pair(8, -99), Pair(14, 10), Pair(-84, -34), Pair(2, 31), Pair(155, -69), Pair(4, 48), Pair(94, -13), Pair(119, 83),
        Pair(29, 11), Pair(155, -76), Pair(-28, 15), Pair(64, -58), Pair(144, -8), Pair(100, -25), Pair(28, 42), Pair(-49, 34),
        Pair(64, -31), Pair(-119, -3), Pair(55, -75), Pair(83, 10), Pair(179, -50), Pair(57, 27), Pair(-41, 0), Pair(18, -44),
        Pair(-30, 41), Pair(3, -42), Pair(103, -50), Pair(81, -42), Pair(2, 8), Pair(15, -52), Pair(63, -44), Pair(165, -86),
        Pair(-111, -25), Pair(69, -3), Pair(69, -47), Pair(-3, -3), Pair(48, -68), Pair(14, -38), Pair(-9, -46), Pair(11, -222),
        Pair(-13, 70), Pair(96, -54), Pair(23, -1), Pair(111, -97), Pair(-235, 56), Pair(-2, -47), Pair(11, -75), Pair(64, -38)
      },
      { // Piece 3
        Pair(-48, 39), Pair(-25, 39), Pair(-91, 69), Pair(36, 15), Pair(71, 5), Pair(54, 12), Pair(20, 61), Pair(166, -154),
        Pair(64, -28), Pair(145, -17), Pair(-36, 14), Pair(51, -7), Pair(212, -66), Pair(77, -4), Pair(39, 5), Pair(0, 0),
        Pair(189, -30), Pair(102, -31), Pair(147, -9), Pair(31, -8), Pair(164, -54), Pair(22, 17), Pair(8, 34), Pair(-61, 25),
        Pair(-12, 12), Pair(130, -6), Pair(129, -58), Pair(67, -14), Pair(107, -61), Pair(148, -17), Pair(-4, 28), Pair(-25, 28),
        Pair(-92, 37), Pair(-48, 48), Pair(-54, 59), Pair(113, -30), Pair(43, 9), Pair(-36, 0), Pair(72, 10), Pair(-82, 50),
        Pair(14, -1), Pair(-52, -13), Pair(82, 43), Pair(-51, 28), Pair(-32, -16), Pair(-72, 3), Pair(19, 5), Pair(-95, 32),
        Pair(-109, 44), Pair(54, 23), Pair(-2, -1), Pair(-26, -6), Pair(32, 15), Pair(11, 17), Pair(1, 16), Pair(-74, 24),
        Pair(-40, -11), Pair(-7, 3), Pair(-47, 7), Pair(-11, 10), Pair(38, 7), Pair(14, -20), Pair(-30, 37), Pair(5, -18)
      },
      { // Piece 4
        Pair(-59, -47), Pair(-98, -89), Pair(48, 53), Pair(-50, -85), Pair(103, 87), Pair(-14, -30), Pair(-58, -26), Pair(-84, -173),
        Pair(97, 30), Pair(60, -132), Pair(4, -58), Pair(65, -118), Pair(41, -11), Pair(-18, -36), Pair(45, -28), Pair(0, 0),
        Pair(-39, -94), Pair(48, -24), Pair(19, -42), Pair(-8, 19), Pair(4, -32), Pair(-37, -56), Pair(-21, -62), Pair(38, 193),
        Pair(7, -9), Pair(65, -22), Pair(104, 19), Pair(-4, -8), Pair(92, -6), Pair(11, 32), Pair(25, -87), Pair(-6, -11),
        Pair(44, -143), Pair(-186, -26), Pair(-98, -35), Pair(43, 27), Pair(72, -89), Pair(-40, 20), Pair(-32, 61), Pair(112, -122),
        Pair(-92, -24), Pair(-63, 33), Pair(-26, -53), Pair(18, -66), Pair(-48, 160), Pair(-42, 90), Pair(16, -129), Pair(5, -154),
        Pair(-39, -2), Pair(-111, -17), Pair(-54, 71), Pair(-59, 2), Pair(-4, -124), Pair(-30, -60), Pair(-87, 54), Pair(-91, -46),
        Pair(1, -36), Pair(-45, 60), Pair(9, -49), Pair(-39, 52), Pair(-85, -23), Pair(-84, 0), Pair(-46, -59), Pair(-46, -14)
      },
      { // Piece 5
        Pair(15, 50), Pair(-15, 123), Pair(15, 70), Pair(1, 5), Pair(10, 9), Pair(-40, 58), Pair(33, 49), Pair(36, -205),
        Pair(33, 72), Pair(33, -44), Pair(-79, 7), Pair(-59, 18), Pair(47, 4), Pair(-34, 52), Pair(101, 87), Pair(0, 0),
        Pair(29, 80), Pair(44, 40), Pair(49, -17), Pair(-29, 3), Pair(43, -14), Pair(-43, 47), Pair(90, 21), Pair(-44, 36),
        Pair(161, 85), Pair(-52, -9), Pair(70, 6), Pair(53, -19), Pair(-2, 15), Pair(61, 11), Pair(80, 18), Pair(91, 13),
        Pair(-1, -31), Pair(-18, -7), Pair(47, -16), Pair(72, -14), Pair(-26, -2), Pair(-103, 30), Pair(-2, 24), Pair(-13, -9),
        Pair(-93, -19), Pair(-14, 4), Pair(58, -21), Pair(111, -21), Pair(-40, 9), Pair(-13, -2), Pair(-30, 9), Pair(53, -14),
        Pair(-122, 1), Pair(-9, -15), Pair(-14, -4), Pair(75, -38), Pair(-92, 11), Pair(-56, 9), Pair(-6, 16), Pair(3, 11),
        Pair(-43, -50), Pair(-15, -31), Pair(-95, 3), Pair(-69, -29), Pair(-33, -15), Pair(30, -21), Pair(-33, 18), Pair(-8, -41)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, -82), Pair(31, -12), Pair(-19, 16), Pair(15, 27), Pair(-51, 53), Pair(64, -8), Pair(-19, 15), Pair(-24, 26),
        Pair(1, 51), Pair(-27, -7), Pair(-3, 10), Pair(3, 25), Pair(6, 21), Pair(-13, 18), Pair(-13, 14), Pair(-16, 23),
        Pair(0, -21), Pair(-10, -5), Pair(8, 11), Pair(-3, 14), Pair(5, 13), Pair(0, 14), Pair(-11, 18), Pair(-7, 13),
        Pair(7, 6), Pair(2, 18), Pair(-1, 11), Pair(-7, 10), Pair(1, 7), Pair(-3, 8), Pair(-1, 12), Pair(0, 10),
        Pair(1, 25), Pair(-11, 17), Pair(-4, 12), Pair(1, 4), Pair(0, 8), Pair(3, 8), Pair(2, 16), Pair(-5, 15),
        Pair(-2, 21), Pair(-9, 17), Pair(-9, 12), Pair(1, 9), Pair(-10, 19), Pair(-1, 17), Pair(-3, 18), Pair(-5, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(136, -37), Pair(-163, 56), Pair(63, 18), Pair(51, 7), Pair(-20, 62), Pair(74, 12), Pair(55, 37), Pair(101, 33),
        Pair(17, -72), Pair(57, 4), Pair(50, 4), Pair(6, 36), Pair(66, 2), Pair(160, -29), Pair(-54, 94), Pair(-98, 51),
        Pair(0, 0), Pair(39, 21), Pair(45, 39), Pair(27, 28), Pair(12, 38), Pair(28, 11), Pair(-15, 41), Pair(13, 18),
        Pair(30, 46), Pair(31, 52), Pair(35, 15), Pair(34, 39), Pair(19, 26), Pair(25, 3), Pair(-3, 13), Pair(19, 25),
        Pair(2, 14), Pair(35, 16), Pair(21, 16), Pair(20, 28), Pair(17, 21), Pair(14, 16), Pair(-6, 20), Pair(3, 20),
        Pair(24, 10), Pair(15, 23), Pair(16, 19), Pair(28, 12), Pair(12, 16), Pair(19, 1), Pair(8, 0), Pair(3, -27),
        Pair(-14, 16), Pair(6, 28), Pair(15, 24), Pair(17, 0), Pair(15, 20), Pair(27, 8), Pair(3, -8), Pair(-11, 14),
        Pair(-152, -56), Pair(-6, -6), Pair(-13, -7), Pair(14, -3), Pair(-10, 17), Pair(-1, -2), Pair(-4, 0), Pair(-62, -27)
      },
      { // Piece 2
        Pair(68, -17), Pair(179, -6), Pair(94, -27), Pair(46, 24), Pair(78, -49), Pair(-16, 21), Pair(71, -46), Pair(27, -10),
        Pair(56, -71), Pair(115, 2), Pair(71, 5), Pair(111, -47), Pair(55, -33), Pair(-7, 0), Pair(67, -12), Pair(64, -19),
        Pair(0, 0), Pair(56, 24), Pair(106, -28), Pair(32, 2), Pair(78, -33), Pair(-1, 8), Pair(50, -39), Pair(-4, 46),
        Pair(14, 35), Pair(63, -4), Pair(54, 38), Pair(82, -10), Pair(21, 17), Pair(47, -21), Pair(24, 6), Pair(35, -6),
        Pair(49, -24), Pair(37, 22), Pair(41, -4), Pair(28, 12), Pair(52, 0), Pair(29, 33), Pair(49, -22), Pair(19, 20),
        Pair(21, 5), Pair(44, -5), Pair(23, 7), Pair(37, -9), Pair(29, 36), Pair(47, -8), Pair(38, -3), Pair(17, -12),
        Pair(0, -64), Pair(13, -2), Pair(42, -14), Pair(21, 8), Pair(32, 5), Pair(42, 14), Pair(30, 2), Pair(47, -15),
        Pair(14, -25), Pair(18, -20), Pair(13, -1), Pair(31, -10), Pair(28, 5), Pair(34, -5), Pair(58, -25), Pair(35, -9)
      },
      { // Piece 3
        Pair(59, -17), Pair(27, 65), Pair(-33, 69), Pair(52, 48), Pair(31, 40), Pair(-23, 46), Pair(37, 49), Pair(-27, 50),
        Pair(35, -77), Pair(55, 61), Pair(5, 73), Pair(69, 48), Pair(46, 44), Pair(61, 28), Pair(6, 58), Pair(73, 30),
        Pair(0, 0), Pair(63, 36), Pair(31, 43), Pair(50, 35), Pair(107, 13), Pair(40, 43), Pair(46, 45), Pair(27, 48),
        Pair(-33, 30), Pair(0, 73), Pair(13, 58), Pair(39, 49), Pair(29, 29), Pair(41, 46), Pair(19, 45), Pair(5, 60),
        Pair(-19, 33), Pair(13, 72), Pair(10, 53), Pair(15, 54), Pair(25, 46), Pair(33, 32), Pair(28, 43), Pair(-1, 52),
        Pair(-8, 10), Pair(-13, 72), Pair(22, 34), Pair(51, 24), Pair(15, 44), Pair(-10, 66), Pair(37, 31), Pair(26, 45),
        Pair(-31, 39), Pair(7, 48), Pair(10, 44), Pair(1, 40), Pair(28, 40), Pair(13, 38), Pair(-9, 20), Pair(-18, 51),
        Pair(-12, 24), Pair(2, 60), Pair(18, 38), Pair(21, 44), Pair(18, 33), Pair(14, 25), Pair(6, 34), Pair(24, 26)
      },
      { // Piece 4
        Pair(77, -31), Pair(14, 50), Pair(13, 56), Pair(10, 43), Pair(100, -34), Pair(-4, 14), Pair(-39, 45), Pair(4, 76),
        Pair(28, -111), Pair(33, 74), Pair(51, 25), Pair(0, 76), Pair(43, 3), Pair(117, -43), Pair(-26, 127), Pair(41, 40),
        Pair(0, 0), Pair(-8, 111), Pair(16, 67), Pair(11, 57), Pair(-10, 37), Pair(42, 9), Pair(0, 48), Pair(-5, -2),
        Pair(31, -3), Pair(9, 71), Pair(9, 30), Pair(35, 28), Pair(8, 53), Pair(29, 42), Pair(27, 20), Pair(23, -3),
        Pair(19, 17), Pair(33, 53), Pair(21, 63), Pair(18, 55), Pair(17, 77), Pair(7, 64), Pair(22, 26), Pair(35, 20),
        Pair(-22, 64), Pair(29, 27), Pair(4, 58), Pair(32, 18), Pair(38, 20), Pair(4, 76), Pair(24, 5), Pair(25, -41),
        Pair(16, 32), Pair(26, 37), Pair(23, 19), Pair(39, 8), Pair(28, 35), Pair(47, -9), Pair(35, 15), Pair(21, -52),
        Pair(21, 27), Pair(11, 31), Pair(15, 35), Pair(30, 12), Pair(29, 19), Pair(21, -5), Pair(30, 10), Pair(46, -121)
      },
      { // Piece 5
        Pair(27, 30), Pair(-47, 103), Pair(-101, 90), Pair(26, 19), Pair(-23, -43), Pair(-4, -2), Pair(4, 26), Pair(3, -43),
        Pair(-16, -70), Pair(-82, 126), Pair(-24, 113), Pair(36, 55), Pair(78, 25), Pair(63, 12), Pair(121, 16), Pair(108, -11),
        Pair(0, 0), Pair(53, 83), Pair(124, 56), Pair(146, 29), Pair(99, 0), Pair(74, 13), Pair(72, -13), Pair(-79, 33),
        Pair(108, 26), Pair(159, 51), Pair(67, 65), Pair(254, 5), Pair(-62, 53), Pair(64, 4), Pair(-54, 18), Pair(-32, 7),
        Pair(-13, 29), Pair(119, 48), Pair(164, 26), Pair(72, 35), Pair(-3, 32), Pair(37, 5), Pair(-32, 22), Pair(-67, 10),
        Pair(7, 30), Pair(37, 58), Pair(58, 33), Pair(9, 41), Pair(-16, 23), Pair(-31, 21), Pair(-41, 7), Pair(-44, -2),
        Pair(22, 30), Pair(113, 18), Pair(20, 33), Pair(-11, 24), Pair(-23, 17), Pair(-42, 23), Pair(-27, 8), Pair(-23, -1),
        Pair(104, 15), Pair(78, 11), Pair(17, 16), Pair(9, 16), Pair(-27, 3), Pair(-24, 9), Pair(-13, -3), Pair(-12, -7)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-73, 6), Pair(-16, -89), Pair(10, 3), Pair(-74, 47), Pair(-36, 19), Pair(-40, 24), Pair(4, 25), Pair(-61, 52),
        Pair(-28, -6), Pair(-3, 62), Pair(-5, 12), Pair(-24, 26), Pair(-16, 29), Pair(-19, 17), Pair(15, 23), Pair(15, 18),
        Pair(3, 11), Pair(6, -25), Pair(9, 1), Pair(-1, 18), Pair(1, 11), Pair(-8, 11), Pair(-4, 9), Pair(-12, 21),
        Pair(-3, 21), Pair(4, 8), Pair(-10, 17), Pair(5, 12), Pair(0, 8), Pair(3, 6), Pair(-1, 12), Pair(-3, 17),
        Pair(-10, 22), Pair(-7, 10), Pair(-13, 21), Pair(-6, 14), Pair(-1, 9), Pair(5, 11), Pair(0, 9), Pair(-2, 18),
        Pair(-8, 23), Pair(-11, 10), Pair(-16, 16), Pair(-1, 3), Pair(-4, 8), Pair(0, 16), Pair(3, 12), Pair(-6, 22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-4, 4), Pair(-217, 76), Pair(46, 20), Pair(27, 26), Pair(-96, 74), Pair(53, 32), Pair(-64, 50), Pair(22, 192),
        Pair(58, 10), Pair(-20, -50), Pair(21, 62), Pair(66, 29), Pair(17, 45), Pair(-24, 45), Pair(69, -4), Pair(38, -22),
        Pair(-75, 82), Pair(0, 0), Pair(53, 45), Pair(49, 35), Pair(27, 40), Pair(44, 56), Pair(114, -28), Pair(-12, 22),
        Pair(58, 42), Pair(28, 60), Pair(56, 56), Pair(48, 31), Pair(21, 48), Pair(41, 27), Pair(37, 16), Pair(-11, 58),
        Pair(2, 25), Pair(64, 43), Pair(41, 32), Pair(17, 44), Pair(26, 41), Pair(9, 42), Pair(8, 28), Pair(20, 2),
        Pair(3, 7), Pair(40, 32), Pair(4, 34), Pair(33, 25), Pair(18, 45), Pair(28, 11), Pair(14, 25), Pair(7, 0),
        Pair(-40, 40), Pair(22, 15), Pair(21, 32), Pair(18, 23), Pair(4, 20), Pair(24, 15), Pair(11, 13), Pair(2, 38),
        Pair(63, -77), Pair(-19, -4), Pair(-36, 6), Pair(-48, 24), Pair(9, 18), Pair(39, 10), Pair(4, -5), Pair(14, 31)
      },
      { // Piece 2
        Pair(98, 21), Pair(17, -41), Pair(-9, 2), Pair(71, -20), Pair(-9, 6), Pair(127, -48), Pair(-45, -5), Pair(14, -44),
        Pair(-22, 12), Pair(5, -39), Pair(83, 0), Pair(100, 3), Pair(191, -69), Pair(-79, 18), Pair(71, -39), Pair(23, 16),
        Pair(53, 48), Pair(0, 0), Pair(139, 7), Pair(83, -10), Pair(79, -2), Pair(169, -53), Pair(25, 12), Pair(16, -23),
        Pair(11, -2), Pair(47, 34), Pair(56, -8), Pair(76, 33), Pair(63, -13), Pair(79, 5), Pair(54, -36), Pair(30, 31),
        Pair(21, 23), Pair(29, 17), Pair(45, 21), Pair(66, -2), Pair(47, 35), Pair(84, -20), Pair(29, 0), Pair(28, -17),
        Pair(28, -12), Pair(27, 5), Pair(22, -8), Pair(38, 17), Pair(48, 3), Pair(56, 32), Pair(51, -4), Pair(45, 9),
        Pair(51, -25), Pair(26, -15), Pair(39, 3), Pair(23, -2), Pair(35, 14), Pair(38, -13), Pair(55, 25), Pair(65, 3),
        Pair(14, -28), Pair(18, -15), Pair(5, -3), Pair(32, 4), Pair(10, 1), Pair(31, 12), Pair(28, -23), Pair(48, -13)
      },
      { // Piece 3
        Pair(4, 65), Pair(2, 0), Pair(-18, 91), Pair(-12, 57), Pair(54, 37), Pair(38, 41), Pair(49, 51), Pair(121, 9),
        Pair(6, 70), Pair(-10, -61), Pair(33, 75), Pair(62, 45), Pair(49, 29), Pair(97, 40), Pair(29, 60), Pair(11, 71),
        Pair(7, 40), Pair(0, 0), Pair(63, 34), Pair(15, 50), Pair(15, 55), Pair(59, 45), Pair(33, 57), Pair(107, 37),
        Pair(22, 54), Pair(-7, 37), Pair(16, 66), Pair(46, 41), Pair(32, 62), Pair(116, 9), Pair(-5, 53), Pair(16, 52),
        Pair(39, 40), Pair(-16, 44), Pair(24, 52), Pair(35, 47), Pair(31, 48), Pair(48, 33), Pair(-8, 25), Pair(-8, 54),
        Pair(19, 41), Pair(-9, 46), Pair(27, 41), Pair(35, 44), Pair(11, 57), Pair(32, 32), Pair(45, 26), Pair(53, 45),
        Pair(-7, 53), Pair(-19, 53), Pair(27, 58), Pair(14, 36), Pair(29, 31), Pair(36, 0), Pair(43, 2), Pair(40, 58),
        Pair(22, 34), Pair(-7, 34), Pair(19, 41), Pair(30, 38), Pair(18, 42), Pair(13, 42), Pair(21, 29), Pair(16, 25)
      },
      { // Piece 4
        Pair(-12, 81), Pair(31, 6), Pair(6, 38), Pair(-6, 45), Pair(66, 2), Pair(35, 22), Pair(49, 4), Pair(40, 14),
        Pair(-27, 46), Pair(3, -68), Pair(10, 78), Pair(58, 20), Pair(-5, 48), Pair(41, 49), Pair(-57, 106), Pair(-32, 38),
        Pair(-10, 73), Pair(0, 0), Pair(33, 39), Pair(20, 88), Pair(104, -29), Pair(-58, 143), Pair(69, -14), Pair(24, 28),
        Pair(34, 33), Pair(6, 66), Pair(27, 42), Pair(0, 81), Pair(8, 52), Pair(-1, 46), Pair(31, -10), Pair(-32, 132),
        Pair(10, 44), Pair(36, 16), Pair(30, 45), Pair(35, 15), Pair(-4, 96), Pair(1, 78), Pair(3, 72), Pair(22, -17),
        Pair(-18, 53), Pair(5, 19), Pair(-5, 93), Pair(4, 43), Pair(-10, 46), Pair(25, -8), Pair(14, 42), Pair(42, 25),
        Pair(13, 17), Pair(20, 45), Pair(3, 31), Pair(5, 59), Pair(12, 59), Pair(22, 49), Pair(12, 29), Pair(29, -17),
        Pair(-4, 52), Pair(-14, 49), Pair(14, 46), Pair(-3, 44), Pair(17, 15), Pair(30, 4), Pair(0, -4), Pair(42, -12)
      },
      { // Piece 5
        Pair(-4, 217), Pair(84, 117), Pair(16, 195), Pair(8, 37), Pair(-2, -19), Pair(16, 29), Pair(-70, -8), Pair(-33, -30),
        Pair(45, 118), Pair(121, 20), Pair(128, 59), Pair(27, 72), Pair(90, 2), Pair(-57, 29), Pair(58, -10), Pair(-24, 12),
        Pair(64, 98), Pair(0, 0), Pair(157, 64), Pair(12, 58), Pair(68, 31), Pair(24, -6), Pair(-56, 43), Pair(-117, 21),
        Pair(24, 97), Pair(102, 41), Pair(206, 44), Pair(92, 46), Pair(107, 1), Pair(-7, 17), Pair(145, -15), Pair(-99, 12),
        Pair(117, 67), Pair(84, 24), Pair(91, 50), Pair(108, 18), Pair(47, 12), Pair(-7, 18), Pair(-143, 28), Pair(-78, -4),
        Pair(23, 64), Pair(54, 5), Pair(35, 43), Pair(0, 26), Pair(-25, 16), Pair(-28, 11), Pair(-46, 0), Pair(-139, 24),
        Pair(45, 30), Pair(39, -1), Pair(9, 30), Pair(-5, 11), Pair(-29, 9), Pair(-16, 7), Pair(-33, 3), Pair(-29, -10),
        Pair(-20, 72), Pair(49, 44), Pair(3, 52), Pair(-26, 17), Pair(-45, 3), Pair(-45, -6), Pair(-27, -8), Pair(-29, -25)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, 13), Pair(-6, 3), Pair(-21, -73), Pair(60, 7), Pair(-117, 71), Pair(-27, 36), Pair(-60, 29), Pair(-46, 51),
        Pair(-3, 9), Pair(-5, 12), Pair(10, 38), Pair(-9, 40), Pair(9, 25), Pair(0, 24), Pair(10, 30), Pair(-20, 24),
        Pair(12, 10), Pair(8, 20), Pair(-15, -40), Pair(0, 24), Pair(-1, 13), Pair(5, 12), Pair(-15, 19), Pair(10, 14),
        Pair(2, 16), Pair(-3, 23), Pair(-5, 1), Pair(-10, 22), Pair(3, 11), Pair(8, 8), Pair(-6, 11), Pair(2, 14),
        Pair(0, 11), Pair(-6, 9), Pair(1, -6), Pair(-7, 15), Pair(1, 4), Pair(8, 10), Pair(3, 9), Pair(6, 12),
        Pair(-10, 20), Pair(-18, 12), Pair(-11, 3), Pair(-9, 17), Pair(-2, 15), Pair(-4, 13), Pair(0, 17), Pair(-3, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-71, 88), Pair(93, 15), Pair(27, 58), Pair(-83, 59), Pair(-8, 34), Pair(-51, -29), Pair(19, 80), Pair(24, 60),
        Pair(-23, 85), Pair(36, 61), Pair(13, -34), Pair(24, 49), Pair(76, 35), Pair(42, 7), Pair(131, 32), Pair(22, 31),
        Pair(55, 34), Pair(92, 11), Pair(0, 0), Pair(80, 60), Pair(100, 25), Pair(80, 19), Pair(58, 41), Pair(-3, 68),
        Pair(-28, 36), Pair(35, 95), Pair(26, 66), Pair(51, 62), Pair(24, 46), Pair(66, 50), Pair(19, 35), Pair(62, 26),
        Pair(7, 28), Pair(32, 34), Pair(22, 52), Pair(31, 49), Pair(31, 41), Pair(35, 43), Pair(57, 17), Pair(-3, 42),
        Pair(21, 8), Pair(-3, 23), Pair(30, 44), Pair(24, 33), Pair(28, 30), Pair(20, 30), Pair(35, 31), Pair(-6, 46),
        Pair(33, -25), Pair(56, -29), Pair(30, 29), Pair(8, 20), Pair(15, 41), Pair(12, 23), Pair(-30, 65), Pair(23, 3),
        Pair(20, -26), Pair(10, -5), Pair(-37, 29), Pair(8, 46), Pair(29, -10), Pair(-21, 33), Pair(3, -6), Pair(-1, 32)
      },
      { // Piece 2
        Pair(-54, -81), Pair(42, 13), Pair(118, -58), Pair(83, 19), Pair(-9, -21), Pair(124, -33), Pair(69, -29), Pair(137, -17),
        Pair(14, 53), Pair(58, -23), Pair(50, -59), Pair(99, -17), Pair(82, 0), Pair(105, -53), Pair(9, 8), Pair(-4, -2),
        Pair(20, 11), Pair(97, 17), Pair(0, 0), Pair(126, 5), Pair(76, -33), Pair(106, -19), Pair(63, -47), Pair(38, -6),
        Pair(14, 66), Pair(27, 9), Pair(33, 60), Pair(76, 4), Pair(85, 35), Pair(106, -21), Pair(58, 16), Pair(29, -11),
        Pair(64, -14), Pair(43, 22), Pair(41, -2), Pair(40, 29), Pair(80, 0), Pair(57, 36), Pair(59, -12), Pair(97, -12),
        Pair(18, 16), Pair(34, -3), Pair(28, 26), Pair(29, 1), Pair(37, 33), Pair(51, 3), Pair(41, 27), Pair(41, -3),
        Pair(36, -36), Pair(23, 12), Pair(13, -10), Pair(20, 38), Pair(23, 9), Pair(57, 11), Pair(39, 14), Pair(25, 52),
        Pair(35, -45), Pair(-2, 2), Pair(16, 34), Pair(-21, -12), Pair(16, 18), Pair(19, 37), Pair(83, -39), Pair(34, -10)
      },
      { // Piece 3
        Pair(7, 72), Pair(113, 37), Pair(31, 3), Pair(-91, 105), Pair(107, 41), Pair(-31, 75), Pair(-130, 91), Pair(20, 51),
        Pair(-7, 84), Pair(55, 57), Pair(-37, -54), Pair(62, 52), Pair(40, 39), Pair(29, 51), Pair(-27, 68), Pair(51, 63),
        Pair(31, 57), Pair(0, 74), Pair(0, 0), Pair(40, 48), Pair(53, 49), Pair(44, 56), Pair(65, 58), Pair(56, 41),
        Pair(57, 39), Pair(44, 64), Pair(16, 30), Pair(-21, 76), Pair(32, 33), Pair(40, 55), Pair(-60, 106), Pair(-12, 77),
        Pair(7, 55), Pair(5, 66), Pair(36, 41), Pair(-7, 58), Pair(12, 60), Pair(-1, 41), Pair(13, 35), Pair(-9, 39),
        Pair(-4, 61), Pair(35, 37), Pair(-13, 46), Pair(7, 61), Pair(31, 44), Pair(30, 26), Pair(19, 39), Pair(-23, 84),
        Pair(-18, 63), Pair(6, 45), Pair(3, 30), Pair(-8, 67), Pair(39, 24), Pair(18, 62), Pair(7, 27), Pair(6, 58),
        Pair(7, 42), Pair(0, 53), Pair(15, 30), Pair(10, 52), Pair(8, 51), Pair(0, 41), Pair(-24, 63), Pair(-4, 24)
      },
      { // Piece 4
        Pair(12, 24), Pair(-8, 91), Pair(21, -11), Pair(111, -23), Pair(97, -42), Pair(-18, 42), Pair(0, -5), Pair(161, -55),
        Pair(27, -15), Pair(14, 25), Pair(54, -132), Pair(19, 58), Pair(124, -57), Pair(102, -45), Pair(21, 178), Pair(74, 14),
        Pair(20, 13), Pair(10, 35), Pair(0, 0), Pair(-22, 100), Pair(29, 87), Pair(72, 14), Pair(7, 103), Pair(42, -9),
        Pair(6, 45), Pair(23, 28), Pair(-5, 95), Pair(-7, 77), Pair(3, 37), Pair(15, 124), Pair(15, 47), Pair(-32, 79),
        Pair(17, -15), Pair(7, 47), Pair(12, 40), Pair(22, 63), Pair(39, 9), Pair(-23, 96), Pair(-7, 95), Pair(7, 27),
        Pair(30, -34), Pair(21, 39), Pair(20, 10), Pair(19, 25), Pair(-11, 73), Pair(23, 36), Pair(23, 54), Pair(-17, 79),
        Pair(56, -22), Pair(40, -30), Pair(9, 31), Pair(22, -1), Pair(11, 42), Pair(21, 13), Pair(7, 14), Pair(-5, 86),
        Pair(35, -21), Pair(11, -28), Pair(25, 16), Pair(0, 59), Pair(-2, 27), Pair(54, -57), Pair(96, -91), Pair(-21, 52)
      },
      { // Piece 5
        Pair(29, 50), Pair(40, 208), Pair(111, 64), Pair(4, 90), Pair(14, 33), Pair(-1, -14), Pair(-13, 21), Pair(3, 19),
        Pair(-4, 140), Pair(137, 82), Pair(145, 20), Pair(87, 61), Pair(164, 77), Pair(-14, 49), Pair(17, 22), Pair(23, -58),
        Pair(124, 100), Pair(172, 89), Pair(0, 0), Pair(94, 89), Pair(114, 43), Pair(-108, 43), Pair(41, 22), Pair(47, 9),
        Pair(-79, 99), Pair(147, 67), Pair(71, 70), Pair(91, 62), Pair(108, 35), Pair(-18, 24), Pair(-71, 35), Pair(-103, 17),
        Pair(93, 43), Pair(55, 74), Pair(39, 38), Pair(48, 52), Pair(64, 16), Pair(4, 10), Pair(9, 8), Pair(-166, 14),
        Pair(42, 27), Pair(-6, 36), Pair(31, 6), Pair(-26, 27), Pair(-30, 20), Pair(-56, 17), Pair(-48, 2), Pair(-48, -13),
        Pair(60, 17), Pair(-30, 27), Pair(15, 15), Pair(-63, 30), Pair(-61, 19), Pair(-53, 7), Pair(-41, 1), Pair(-42, 1),
        Pair(57, 7), Pair(18, 20), Pair(-29, 22), Pair(-61, 14), Pair(-18, -8), Pair(-34, -9), Pair(-33, -12), Pair(-23, -16)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, 35), Pair(-5, 31), Pair(-46, 35), Pair(-23, -54), Pair(-1, 6), Pair(-19, 45), Pair(93, -15), Pair(37, 13),
        Pair(3, 25), Pair(-24, 27), Pair(-8, 40), Pair(13, 26), Pair(-2, 31), Pair(1, 20), Pair(-64, 38), Pair(12, 11),
        Pair(-2, 13), Pair(4, 16), Pair(16, 31), Pair(-6, -29), Pair(10, 26), Pair(0, 14), Pair(11, 7), Pair(8, 8),
        Pair(-3, 17), Pair(4, 12), Pair(-8, 15), Pair(4, 9), Pair(-3, 27), Pair(2, 7), Pair(-1, 8), Pair(-6, 10),
        Pair(-9, 16), Pair(-5, 11), Pair(-10, 11), Pair(-5, 9), Pair(-10, 21), Pair(1, 15), Pair(-7, 9), Pair(0, 4),
        Pair(-3, 16), Pair(-3, 13), Pair(-10, 14), Pair(0, 8), Pair(-12, 22), Pair(-9, 10), Pair(-5, 7), Pair(-2, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(12, -14), Pair(1, 44), Pair(-10, 53), Pair(47, 7), Pair(-78, 79), Pair(-109, 27), Pair(-128, 61), Pair(57, 155),
        Pair(59, 28), Pair(27, 78), Pair(35, 68), Pair(11, -25), Pair(111, 26), Pair(-29, 64), Pair(-23, 79), Pair(69, 32),
        Pair(16, 80), Pair(24, 64), Pair(33, 50), Pair(0, 0), Pair(81, 37), Pair(69, 43), Pair(70, 51), Pair(40, 83),
        Pair(1, 67), Pair(36, 34), Pair(48, 79), Pair(42, 76), Pair(30, 94), Pair(50, 47), Pair(31, 52), Pair(-5, 51),
        Pair(25, 25), Pair(65, 29), Pair(35, 38), Pair(13, 56), Pair(30, 53), Pair(24, 59), Pair(18, 24), Pair(16, 17),
        Pair(20, 22), Pair(10, 35), Pair(24, 36), Pair(9, 59), Pair(30, 41), Pair(27, 36), Pair(-4, 68), Pair(31, 24),
        Pair(-3, 29), Pair(20, 25), Pair(16, 21), Pair(17, 46), Pair(8, 36), Pair(11, 34), Pair(8, -1), Pair(23, 28),
        Pair(53, 9), Pair(2, 9), Pair(16, 30), Pair(-14, 47), Pair(8, 37), Pair(-7, 55), Pair(-8, 22), Pair(-22, -64)
      },
      { // Piece 2
        Pair(84, 23), Pair(-36, 31), Pair(229, -18), Pair(-11, -16), Pair(-31, 76), Pair(-76, 47), Pair(-80, 48), Pair(54, -30),
        Pair(48, -30), Pair(18, 29), Pair(73, 5), Pair(4, -54), Pair(130, -28), Pair(120, -8), Pair(-2, 11), Pair(-2, 57),
        Pair(74, 14), Pair(70, -4), Pair(47, 38), Pair(0, 0), Pair(111, 3), Pair(97, -4), Pair(64, 36), Pair(35, 24),
        Pair(63, 2), Pair(31, 50), Pair(24, 24), Pair(53, 45), Pair(49, 19), Pair(83, 40), Pair(43, 7), Pair(65, 23),
        Pair(58, 5), Pair(36, 21), Pair(42, 30), Pair(49, 1), Pair(39, 28), Pair(33, 22), Pair(39, 45), Pair(30, 23),
        Pair(15, 12), Pair(14, 19), Pair(42, 9), Pair(25, 31), Pair(32, 15), Pair(29, 33), Pair(35, 10), Pair(37, 43),
        Pair(44, 9), Pair(25, 19), Pair(38, -5), Pair(19, 8), Pair(14, 40), Pair(26, 9), Pair(24, 30), Pair(17, 22),
        Pair(18, 2), Pair(40, 19), Pair(8, 10), Pair(32, 4), Pair(33, 6), Pair(-7, 44), Pair(32, -14), Pair(72, 19)
      },
      { // Piece 3
        Pair(21, 76), Pair(-31, 96), Pair(38, 91), Pair(0, 24), Pair(102, 71), Pair(77, 49), Pair(-53, 87), Pair(-53, 105),
        Pair(30, 77), Pair(-3, 81), Pair(32, 71), Pair(-63, -40), Pair(57, 54), Pair(71, 72), Pair(95, 54), Pair(56, 78),
        Pair(0, 77), Pair(8, 63), Pair(8, 62), Pair(0, 0), Pair(69, 45), Pair(7, 56), Pair(54, 52), Pair(44, 67),
        Pair(34, 63), Pair(43, 51), Pair(27, 63), Pair(34, 44), Pair(17, 74), Pair(29, 54), Pair(-3, 44), Pair(17, 89),
        Pair(-14, 85), Pair(20, 76), Pair(16, 55), Pair(36, 45), Pair(-3, 71), Pair(39, 51), Pair(25, 40), Pair(-3, 70),
        Pair(3, 62), Pair(-13, 70), Pair(-7, 76), Pair(27, 44), Pair(28, 63), Pair(22, 45), Pair(17, 52), Pair(51, 16),
        Pair(7, 53), Pair(34, 40), Pair(18, 58), Pair(9, 53), Pair(9, 49), Pair(0, 62), Pair(-11, 63), Pair(-49, 83),
        Pair(0, 55), Pair(4, 57), Pair(8, 59), Pair(24, 40), Pair(10, 57), Pair(10, 47), Pair(13, 48), Pair(17, 23)
      },
      { // Piece 4
        Pair(-4, 62), Pair(-27, 41), Pair(116, -19), Pair(23, 32), Pair(-25, 117), Pair(-9, -1), Pair(82, 12), Pair(124, -36),
        Pair(36, 66), Pair(65, 24), Pair(38, 47), Pair(-39, -19), Pair(56, 15), Pair(138, -15), Pair(61, 44), Pair(4, 113),
        Pair(18, 36), Pair(64, 21), Pair(3, 88), Pair(0, 0), Pair(7, 64), Pair(32, 131), Pair(-2, 149), Pair(75, 12),
        Pair(34, 59), Pair(-10, 104), Pair(9, 77), Pair(23, 71), Pair(33, 59), Pair(55, 2), Pair(38, 82), Pair(22, 59),
        Pair(49, 19), Pair(29, 63), Pair(22, 69), Pair(18, 84), Pair(-4, 96), Pair(28, 46), Pair(45, 18), Pair(41, 9),
        Pair(16, -8), Pair(17, 23), Pair(33, 39), Pair(29, 45), Pair(11, 82), Pair(17, 70), Pair(66, -23), Pair(80, -66),
        Pair(26, 10), Pair(28, 44), Pair(20, 32), Pair(33, 33), Pair(11, 44), Pair(14, 62), Pair(12, 36), Pair(4, 36),
        Pair(44, -65), Pair(38, -42), Pair(28, 10), Pair(24, 66), Pair(56, -56), Pair(12, 4), Pair(-1, -18), Pair(-1, -61)
      },
      { // Piece 5
        Pair(32, -11), Pair(-12, 124), Pair(46, 174), Pair(58, 72), Pair(8, 137), Pair(25, -36), Pair(1, -6), Pair(-7, -24),
        Pair(26, 33), Pair(30, 103), Pair(66, 80), Pair(-55, 22), Pair(57, 56), Pair(24, 85), Pair(45, -19), Pair(20, -66),
        Pair(29, 104), Pair(93, 45), Pair(156, 80), Pair(0, 0), Pair(68, 72), Pair(109, 13), Pair(42, -5), Pair(-49, 7),
        Pair(-46, 41), Pair(62, 34), Pair(117, 46), Pair(15, 85), Pair(103, 39), Pair(-20, 43), Pair(-18, 15), Pair(22, -7),
        Pair(32, 20), Pair(50, 23), Pair(78, 28), Pair(0, 44), Pair(-24, 33), Pair(43, 5), Pair(-44, 12), Pair(-109, 9),
        Pair(-74, 12), Pair(7, -6), Pair(14, 3), Pair(-49, 26), Pair(-9, 0), Pair(-5, -3), Pair(-3, -4), Pair(-23, -22),
        Pair(-18, 3), Pair(22, -15), Pair(7, -14), Pair(-67, 16), Pair(-27, -14), Pair(-8, -4), Pair(1, -24), Pair(12, -25),
        Pair(-20, -3), Pair(4, -1), Pair(-32, -18), Pair(-94, 8), Pair(-26, -19), Pair(-26, -16), Pair(13, -31), Pair(8, -34)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-85, 38), Pair(-30, 30), Pair(-30, 32), Pair(1, 4), Pair(117, -70), Pair(-26, -9), Pair(-21, 25), Pair(30, 9),
        Pair(6, 21), Pair(-16, 29), Pair(9, 25), Pair(-2, 31), Pair(17, 20), Pair(3, 7), Pair(-28, 21), Pair(2, 12),
        Pair(13, 2), Pair(12, 2), Pair(3, 9), Pair(11, 25), Pair(5, -40), Pair(20, 12), Pair(6, 8), Pair(11, 1),
        Pair(0, 11), Pair(10, 12), Pair(14, 6), Pair(-5, 25), Pair(8, 1), Pair(-9, 19), Pair(1, 9), Pair(-7, 10),
        Pair(3, 11), Pair(-2, 10), Pair(0, 8), Pair(-7, 11), Pair(6, 0), Pair(3, 11), Pair(-8, 13), Pair(-6, 11),
        Pair(-2, 8), Pair(7, 9), Pair(2, 0), Pair(-5, 16), Pair(0, 5), Pair(0, 10), Pair(-9, 9), Pair(-6, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(49, 92), Pair(-56, 77), Pair(-6, 78), Pair(-1, -2), Pair(27, 47), Pair(36, 4), Pair(119, 30), Pair(-84, 158),
        Pair(-10, 37), Pair(-115, 75), Pair(22, 71), Pair(73, 36), Pair(-5, -7), Pair(2, 40), Pair(117, 27), Pair(68, 69),
        Pair(87, 26), Pair(4, 54), Pair(50, 37), Pair(59, 28), Pair(0, 0), Pair(27, 37), Pair(13, 62), Pair(21, 23),
        Pair(-14, 35), Pair(0, 57), Pair(22, 31), Pair(66, 44), Pair(26, 51), Pair(80, 57), Pair(21, 37), Pair(42, 25),
        Pair(-19, 45), Pair(111, -1), Pair(-3, 32), Pair(29, 42), Pair(28, 40), Pair(26, 43), Pair(54, 3), Pair(34, 18),
        Pair(-6, -7), Pair(-13, 10), Pair(2, 3), Pair(13, 24), Pair(16, 62), Pair(12, 18), Pair(-1, 58), Pair(9, 22),
        Pair(-44, 33), Pair(-9, 22), Pair(-26, 9), Pair(-12, 30), Pair(6, 17), Pair(26, 10), Pair(-1, 50), Pair(6, -14),
        Pair(-50, -5), Pair(-6, -12), Pair(40, -51), Pair(-2, -20), Pair(-54, 30), Pair(24, 27), Pair(-23, 2), Pair(-39, -5)
      },
      { // Piece 2
        Pair(129, -104), Pair(31, -23), Pair(76, -18), Pair(217, -56), Pair(115, -82), Pair(56, 7), Pair(31, -38), Pair(24, 19),
        Pair(-14, 45), Pair(22, -26), Pair(24, 13), Pair(60, 3), Pair(19, -67), Pair(71, -26), Pair(54, 2), Pair(79, -58),
        Pair(36, -21), Pair(135, -8), Pair(103, -34), Pair(84, -1), Pair(0, 0), Pair(120, 0), Pair(56, -31), Pair(33, 16),
        Pair(8, 19), Pair(51, -25), Pair(70, 3), Pair(46, -12), Pair(30, 33), Pair(63, -13), Pair(23, 50), Pair(26, -16),
        Pair(44, -51), Pair(2, 46), Pair(34, -7), Pair(38, 16), Pair(59, -30), Pair(23, 17), Pair(34, -7), Pair(47, 21),
        Pair(30, 22), Pair(-3, 8), Pair(39, 16), Pair(36, -14), Pair(0, 30), Pair(25, 0), Pair(20, 3), Pair(8, -4),
        Pair(20, 4), Pair(20, 22), Pair(12, -32), Pair(4, 24), Pair(15, -9), Pair(21, 9), Pair(19, 4), Pair(-26, 58),
        Pair(30, -2), Pair(43, -40), Pair(6, 14), Pair(25, -8), Pair(0, 8), Pair(-2, 0), Pair(-11, 5), Pair(38, -38)
      },
      { // Piece 3
        Pair(-40, 61), Pair(-3, 49), Pair(11, 57), Pair(5, 79), Pair(-46, 20), Pair(26, 46), Pair(-210, 105), Pair(-65, 77),
        Pair(15, 42), Pair(12, 60), Pair(36, 25), Pair(17, 52), Pair(24, -75), Pair(56, 37), Pair(75, 33), Pair(81, 28),
        Pair(35, 24), Pair(4, 37), Pair(9, 13), Pair(55, 12), Pair(0, 0), Pair(5, 47), Pair(44, 13), Pair(7, 37),
        Pair(20, 31), Pair(25, 23), Pair(54, 1), Pair(-38, 47), Pair(39, -16), Pair(13, 37), Pair(55, 4), Pair(-16, 48),
        Pair(-10, 20), Pair(12, 21), Pair(-43, 36), Pair(17, 30), Pair(-2, 23), Pair(32, 35), Pair(46, 23), Pair(-5, 31),
        Pair(1, 9), Pair(19, 18), Pair(-1, 20), Pair(-27, 29), Pair(28, -6), Pair(-15, 42), Pair(11, 41), Pair(13, 14),
        Pair(-40, 18), Pair(0, 18), Pair(7, 5), Pair(-25, 23), Pair(1, 21), Pair(-2, 35), Pair(-12, 9), Pair(-66, 53),
        Pair(-13, 15), Pair(-17, 27), Pair(-7, 31), Pair(-5, 29), Pair(11, 17), Pair(-12, 33), Pair(-6, 27), Pair(0, 14)
      },
      { // Piece 4
        Pair(-17, 24), Pair(-31, 90), Pair(19, 6), Pair(132, -76), Pair(0, -19), Pair(93, -17), Pair(-12, 34), Pair(14, 47),
        Pair(14, -19), Pair(0, 49), Pair(89, -66), Pair(4, 60), Pair(-62, -13), Pair(47, 15), Pair(54, 32), Pair(63, 9),
        Pair(5, -37), Pair(60, -22), Pair(65, -67), Pair(41, -5), Pair(0, 0), Pair(107, -16), Pair(67, -36), Pair(49, 22),
        Pair(41, 48), Pair(40, 10), Pair(55, 11), Pair(15, 15), Pair(28, 30), Pair(68, -36), Pair(59, 72), Pair(67, 49),
        Pair(-19, 33), Pair(117, -116), Pair(35, 0), Pair(-4, 53), Pair(7, 64), Pair(26, 44), Pair(20, 43), Pair(13, 57),
        Pair(60, -64), Pair(25, -37), Pair(12, -16), Pair(28, 10), Pair(11, 8), Pair(26, 3), Pair(53, -57), Pair(1, 37),
        Pair(-6, -63), Pair(-3, 54), Pair(13, 8), Pair(11, -12), Pair(14, 22), Pair(10, 5), Pair(13, 5), Pair(9, 8),
        Pair(11, -27), Pair(30, -46), Pair(13, -94), Pair(9, 39), Pair(21, -14), Pair(-24, 46), Pair(31, -46), Pair(96, -73)
      },
      { // Piece 5
        Pair(38, 53), Pair(19, -16), Pair(2, 14), Pair(25, 59), Pair(74, 40), Pair(-2, 147), Pair(-5, 49), Pair(-9, 56),
        Pair(-6, -15), Pair(16, 17), Pair(20, 38), Pair(-5, 40), Pair(27, -25), Pair(24, 28), Pair(16, 43), Pair(-18, 6),
        Pair(47, -41), Pair(-38, 29), Pair(134, -1), Pair(62, 60), Pair(0, 0), Pair(93, 57), Pair(108, -2), Pair(-8, 41),
        Pair(91, 10), Pair(118, -11), Pair(-46, 41), Pair(148, 18), Pair(-45, 55), Pair(88, 18), Pair(3, 18), Pair(-58, 24),
        Pair(87, -26), Pair(-152, 47), Pair(-36, 13), Pair(-7, 26), Pair(28, 15), Pair(13, 14), Pair(54, -19), Pair(-70, 6),
        Pair(-179, 30), Pair(58, -2), Pair(-9, -10), Pair(38, 7), Pair(18, -3), Pair(15, -11), Pair(-18, -1), Pair(43, -38),
        Pair(21, -9), Pair(15, -35), Pair(15, -3), Pair(-27, -9), Pair(-28, -15), Pair(10, -26), Pair(3, -11), Pair(4, -23),
        Pair(-31, -30), Pair(31, -27), Pair(-6, -18), Pair(-30, -23), Pair(-48, 7), Pair(2, -51), Pair(18, -28), Pair(17, -22)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-33, 31), Pair(19, 42), Pair(-70, 54), Pair(58, 19), Pair(76, -18), Pair(16, -61), Pair(25, -14), Pair(31, -3),
        Pair(-13, 18), Pair(-20, 17), Pair(0, 24), Pair(1, 20), Pair(2, 7), Pair(16, 16), Pair(-3, -8), Pair(-72, 12),
        Pair(5, 5), Pair(4, 5), Pair(8, 15), Pair(14, 12), Pair(13, 6), Pair(-10, -21), Pair(-2, 1), Pair(-21, 8),
        Pair(-2, 9), Pair(6, 10), Pair(3, 10), Pair(10, 15), Pair(-9, 19), Pair(-4, 11), Pair(-4, 17), Pair(-8, 8),
        Pair(8, 3), Pair(1, 6), Pair(5, 3), Pair(3, 10), Pair(-8, 12), Pair(3, 5), Pair(3, 10), Pair(-14, 14),
        Pair(-4, 12), Pair(2, 2), Pair(-2, 8), Pair(15, -1), Pair(-24, 30), Pair(-10, 14), Pair(-2, 12), Pair(-14, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(1, -19), Pair(4, 48), Pair(-17, -27), Pair(65, -11), Pair(-22, 17), Pair(-34, 28), Pair(-77, 55), Pair(-81, -47),
        Pair(-58, 30), Pair(113, -9), Pair(39, 22), Pair(79, -5), Pair(84, 41), Pair(-96, 1), Pair(5, 9), Pair(28, 31),
        Pair(-81, 54), Pair(-44, 44), Pair(23, 33), Pair(3, 35), Pair(69, 21), Pair(0, 0), Pair(202, -14), Pair(45, 18),
        Pair(-65, 25), Pair(0, 15), Pair(27, 42), Pair(32, 24), Pair(90, 40), Pair(39, 31), Pair(58, 54), Pair(-47, 15),
        Pair(-27, 27), Pair(-33, 41), Pair(20, 10), Pair(-3, 35), Pair(33, 37), Pair(-11, 27), Pair(64, -2), Pair(4, 25),
        Pair(-57, 28), Pair(-2, 37), Pair(-20, 6), Pair(14, 11), Pair(20, 9), Pair(10, 22), Pair(-7, 7), Pair(5, 11),
        Pair(-29, 12), Pair(27, -65), Pair(-49, 15), Pair(-21, 12), Pair(1, 3), Pair(23, 11), Pair(-19, -2), Pair(-18, 15),
        Pair(-55, 13), Pair(-43, 16), Pair(-34, 14), Pair(-24, 23), Pair(11, -8), Pair(-28, 19), Pair(22, -33), Pair(54, -10)
      },
      { // Piece 2
        Pair(23, -19), Pair(116, -90), Pair(78, -40), Pair(49, -9), Pair(-70, 2), Pair(34, -60), Pair(14, -2), Pair(-9, -25),
        Pair(128, -94), Pair(119, -36), Pair(26, -76), Pair(158, -35), Pair(117, -50), Pair(142, -101), Pair(155, -68), Pair(32, 7),
        Pair(25, -18), Pair(85, -73), Pair(70, -5), Pair(62, -55), Pair(109, -13), Pair(0, 0), Pair(198, -45), Pair(-16, -16),
        Pair(-31, -9), Pair(7, 32), Pair(86, -56), Pair(62, 21), Pair(39, -8), Pair(55, 27), Pair(36, -24), Pair(43, 11),
        Pair(30, 20), Pair(18, -53), Pair(55, 25), Pair(27, -21), Pair(60, 16), Pair(3, -25), Pair(50, -9), Pair(-13, -22),
        Pair(-3, -46), Pair(5, 6), Pair(8, -14), Pair(3, 16), Pair(21, -41), Pair(27, -5), Pair(0, -8), Pair(-6, 5),
        Pair(61, -41), Pair(-4, -14), Pair(45, -6), Pair(-14, -35), Pair(-1, -1), Pair(15, -31), Pair(11, -1), Pair(9, -62),
        Pair(-31, -14), Pair(27, -18), Pair(0, -49), Pair(25, -12), Pair(-16, -36), Pair(-20, -1), Pair(111, -95), Pair(-27, -65)
      },
      { // Piece 3
        Pair(48, 51), Pair(-11, 53), Pair(40, 38), Pair(-22, 61), Pair(71, 30), Pair(56, -3), Pair(6, 39), Pair(5, 46),
        Pair(35, 35), Pair(35, 26), Pair(13, 34), Pair(71, 3), Pair(73, 2), Pair(11, -72), Pair(9, 43), Pair(91, 12),
        Pair(12, 25), Pair(39, 6), Pair(31, 2), Pair(46, 5), Pair(7, 31), Pair(0, 0), Pair(96, 14), Pair(-12, 36),
        Pair(-17, 44), Pair(31, 26), Pair(31, 13), Pair(56, 7), Pair(16, 27), Pair(7, -2), Pair(19, 35), Pair(38, 5),
        Pair(-70, 34), Pair(-2, 14), Pair(-39, 28), Pair(-11, 29), Pair(2, 25), Pair(0, 10), Pair(51, 3), Pair(79, -19),
        Pair(-32, 39), Pair(-33, 4), Pair(-19, 5), Pair(-37, 28), Pair(-21, 25), Pair(23, -6), Pair(-7, 5), Pair(40, -4),
        Pair(2, 6), Pair(-1, 1), Pair(-53, 38), Pair(15, 3), Pair(-30, 38), Pair(27, -15), Pair(1, 13), Pair(-19, 61),
        Pair(-15, 7), Pair(-21, 25), Pair(-22, 15), Pair(-7, -2), Pair(-9, 16), Pair(13, -9), Pair(-9, 18), Pair(-1, 20)
      },
      { // Piece 4
        Pair(63, -11), Pair(55, -17), Pair(-133, 127), Pair(76, -42), Pair(126, -27), Pair(8, -31), Pair(81, -79), Pair(118, -193),
        Pair(-2, 16), Pair(-46, 72), Pair(66, -75), Pair(92, -57), Pair(74, -12), Pair(122, -248), Pair(50, 44), Pair(107, -51),
        Pair(-12, 16), Pair(20, 24), Pair(4, -8), Pair(0, 19), Pair(-121, 136), Pair(0, 0), Pair(100, -21), Pair(92, -31),
        Pair(-51, 19), Pair(-24, 23), Pair(59, -18), Pair(1, 15), Pair(-4, -6), Pair(93, -79), Pair(85, 10), Pair(101, -29),
        Pair(2, -1), Pair(27, -41), Pair(-44, 64), Pair(-36, 72), Pair(1, 7), Pair(27, 0), Pair(44, -18), Pair(27, 32),
        Pair(-56, -26), Pair(-45, 97), Pair(-2, -29), Pair(11, -40), Pair(-10, 23), Pair(21, -13), Pair(-13, 25), Pair(2, 47),
        Pair(36, -31), Pair(-29, -8), Pair(-21, -7), Pair(26, -83), Pair(-25, 23), Pair(24, -75), Pair(3, -9), Pair(82, -123),
        Pair(19, -13), Pair(-32, -26), Pair(-12, 19), Pair(-25, -2), Pair(-13, 6), Pair(-28, 13), Pair(18, -87), Pair(-38, 30)
      },
      { // Piece 5
        Pair(1, 55), Pair(21, 8), Pair(-10, 72), Pair(40, 53), Pair(-58, 49), Pair(67, 66), Pair(4, 132), Pair(-42, -27),
        Pair(25, -8), Pair(-71, 2), Pair(-13, 21), Pair(39, 32), Pair(104, 15), Pair(19, 18), Pair(62, 48), Pair(47, 74),
        Pair(9, 24), Pair(94, -17), Pair(29, 18), Pair(89, 11), Pair(-16, 48), Pair(0, 0), Pair(206, 25), Pair(37, 36),
        Pair(11, 6), Pair(-115, 38), Pair(64, 2), Pair(1, 37), Pair(131, 10), Pair(-1, 51), Pair(24, 26), Pair(37, 41),
        Pair(-147, 21), Pair(15, -3), Pair(-53, 17), Pair(0, 14), Pair(4, 27), Pair(-7, 30), Pair(18, 22), Pair(5, 21),
        Pair(41, -28), Pair(-103, 1), Pair(-15, 9), Pair(57, -9), Pair(39, -19), Pair(14, 7), Pair(32, -16), Pair(8, 5),
        Pair(-5, -4), Pair(16, -20), Pair(-23, -14), Pair(-46, 1), Pair(-17, -30), Pair(-34, -8), Pair(16, -31), Pair(15, -8),
        Pair(-13, -39), Pair(-17, -36), Pair(-30, -12), Pair(-38, -7), Pair(-3, -35), Pair(-41, -21), Pair(35, -34), Pair(20, -27)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(12, 5), Pair(15, 14), Pair(-154, 48), Pair(-20, 42), Pair(5, 22), Pair(33, -20), Pair(151, -122), Pair(-43, -21),
        Pair(-13, 14), Pair(15, 24), Pair(9, 29), Pair(-64, 38), Pair(-27, 21), Pair(-3, -9), Pair(17, 36), Pair(-28, -35),
        Pair(-6, 8), Pair(4, 9), Pair(0, 11), Pair(-14, 18), Pair(-12, 16), Pair(-1, -3), Pair(20, -49), Pair(-7, -2),
        Pair(-6, 9), Pair(-3, 8), Pair(3, 9), Pair(-6, 15), Pair(-3, 14), Pair(-11, 15), Pair(0, -13), Pair(-10, 17),
        Pair(0, 12), Pair(-3, 12), Pair(11, -2), Pair(-7, 11), Pair(0, 8), Pair(3, 10), Pair(-13, 1), Pair(-16, 18),
        Pair(-10, 12), Pair(-6, 13), Pair(-4, 8), Pair(-8, 2), Pair(-24, 2), Pair(-12, 18), Pair(-2, -7), Pair(-12, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-16, -110), Pair(-12, 58), Pair(-136, 32), Pair(102, -3), Pair(6, -1), Pair(-23, 22), Pair(-42, 4), Pair(-7, -55),
        Pair(-162, 44), Pair(-118, 14), Pair(-45, 58), Pair(-11, 55), Pair(98, -7), Pair(94, -7), Pair(-5, -35), Pair(-37, 36),
        Pair(61, -67), Pair(-84, 20), Pair(-9, 16), Pair(-4, 23), Pair(43, 12), Pair(82, 12), Pair(0, 0), Pair(85, -27),
        Pair(-96, 28), Pair(-18, 45), Pair(33, 1), Pair(43, 1), Pair(48, -4), Pair(74, 26), Pair(34, 12), Pair(46, 12),
        Pair(-23, -27), Pair(-24, -5), Pair(-13, 0), Pair(16, -1), Pair(0, 16), Pair(25, 18), Pair(10, 13), Pair(-1, 17),
        Pair(-42, -30), Pair(-43, 44), Pair(-14, -1), Pair(-39, 19), Pair(-14, -12), Pair(-16, 21), Pair(-8, -19), Pair(-33, -57),
        Pair(-37, -20), Pair(-79, -18), Pair(-28, -8), Pair(-26, -6), Pair(-36, 18), Pair(-1, -25), Pair(-68, 19), Pair(9, -64),
        Pair(-54, 15), Pair(-34, -15), Pair(20, -37), Pair(-94, 64), Pair(-53, -7), Pair(-36, 17), Pair(-12, -17), Pair(-102, -86)
      },
      { // Piece 2
        Pair(-74, -87), Pair(64, -55), Pair(-95, -59), Pair(-4, -13), Pair(40, -48), Pair(80, -8), Pair(-28, -43), Pair(10, 17),
        Pair(2, -47), Pair(42, -67), Pair(-10, -28), Pair(79, -79), Pair(84, 12), Pair(115, -41), Pair(-97, -17), Pair(-86, -52),
        Pair(73, -85), Pair(90, -37), Pair(-14, -42), Pair(79, -13), Pair(99, -76), Pair(108, -3), Pair(0, 0), Pair(67, -5),
        Pair(-30, 10), Pair(17, -55), Pair(4, 21), Pair(134, -64), Pair(72, 12), Pair(45, -30), Pair(28, 35), Pair(-16, -10),
        Pair(-13, -38), Pair(-43, 8), Pair(42, -43), Pair(47, 13), Pair(35, -25), Pair(-9, 35), Pair(-3, -32), Pair(-18, -11),
        Pair(-27, 24), Pair(15, -49), Pair(5, 2), Pair(17, -33), Pair(6, 5), Pair(14, -50), Pair(24, 5), Pair(-12, -38),
        Pair(51, -60), Pair(-8, 9), Pair(-15, -25), Pair(0, -14), Pair(-5, -40), Pair(-29, 8), Pair(19, -23), Pair(-7, -20),
        Pair(-1, -17), Pair(17, -29), Pair(-16, 10), Pair(-15, -35), Pair(-52, -3), Pair(-7, -35), Pair(-41, -17), Pair(22, -103)
      },
      { // Piece 3
        Pair(34, 15), Pair(91, 3), Pair(13, 22), Pair(110, -10), Pair(115, -5), Pair(-33, 42), Pair(87, -21), Pair(47, 48),
        Pair(79, 14), Pair(50, 13), Pair(76, 12), Pair(163, -37), Pair(-12, 39), Pair(85, 9), Pair(-27, -56), Pair(25, 21),
        Pair(15, 13), Pair(21, 20), Pair(66, 5), Pair(19, 0), Pair(63, 3), Pair(81, 0), Pair(0, 0), Pair(-58, 56),
        Pair(-4, 24), Pair(37, 5), Pair(48, 4), Pair(-27, 25), Pair(46, -13), Pair(-10, 44), Pair(-8, 11), Pair(25, 9),
        Pair(-42, 30), Pair(-49, 49), Pair(-53, 37), Pair(-15, 17), Pair(-8, 26), Pair(3, 25), Pair(-18, 13), Pair(28, -2),
        Pair(10, 9), Pair(-14, 13), Pair(-36, 10), Pair(-37, 40), Pair(-20, 36), Pair(5, 6), Pair(7, -7), Pair(-48, 32),
        Pair(-32, 3), Pair(-2, -12), Pair(-39, 48), Pair(-44, 22), Pair(-26, 21), Pair(4, -20), Pair(17, -45), Pair(-30, 19),
        Pair(-22, -12), Pair(-9, 15), Pair(-21, 22), Pair(-4, 8), Pair(6, -16), Pair(-4, 7), Pair(10, -18), Pair(-13, -2)
      },
      { // Piece 4
        Pair(-9, -61), Pair(-103, 24), Pair(-15, -41), Pair(42, -41), Pair(-29, 24), Pair(53, -15), Pair(4, -64), Pair(5, 14),
        Pair(-107, 175), Pair(2, 27), Pair(69, -52), Pair(-19, 23), Pair(121, -38), Pair(7, 21), Pair(152, -281), Pair(63, -83),
        Pair(35, -19), Pair(46, -80), Pair(-32, 56), Pair(5, -29), Pair(41, -15), Pair(148, -133), Pair(0, 0), Pair(83, -136),
        Pair(1, -91), Pair(-46, -33), Pair(15, -22), Pair(60, -15), Pair(60, -56), Pair(43, -15), Pair(23, -52), Pair(32, -8),
        Pair(-21, -18), Pair(-66, 195), Pair(36, -29), Pair(-11, 18), Pair(-14, 19), Pair(-39, 18), Pair(4, -36), Pair(31, -19),
        Pair(-47, -8), Pair(-38, 42), Pair(11, -104), Pair(22, -35), Pair(-26, -22), Pair(-3, -29), Pair(-4, -22), Pair(86, -159),
        Pair(36, -98), Pair(-38, -30), Pair(-15, 0), Pair(-11, -60), Pair(9, -62), Pair(-32, -17), Pair(-28, -12), Pair(-26, 24),
        Pair(-9, -98), Pair(-30, -80), Pair(-34, -21), Pair(-26, -64), Pair(-4, -95), Pair(-61, -32), Pair(-35, -51), Pair(42, -58)
      },
      { // Piece 5
        Pair(7, 187), Pair(43, 48), Pair(20, 136), Pair(-24, -12), Pair(-3, -17), Pair(41, 137), Pair(1, 72), Pair(-25, 96),
        Pair(-3, 19), Pair(53, -49), Pair(-25, -17), Pair(38, -16), Pair(-118, 42), Pair(103, 10), Pair(27, 30), Pair(80, 66),
        Pair(-116, 18), Pair(42, 16), Pair(117, -42), Pair(36, -25), Pair(119, -11), Pair(119, 22), Pair(0, 0), Pair(56, 56),
        Pair(46, 6), Pair(-13, 0), Pair(-39, 5), Pair(167, -28), Pair(30, 16), Pair(30, 17), Pair(64, 23), Pair(-20, 40),
        Pair(-152, -17), Pair(-51, 7), Pair(130, -20), Pair(4, 0), Pair(47, 0), Pair(5, 20), Pair(29, 20), Pair(65, 8),
        Pair(-99, -16), Pair(-42, -13), Pair(-86, 18), Pair(13, -14), Pair(-24, 6), Pair(21, -9), Pair(-6, 9), Pair(17, 7),
        Pair(-24, -39), Pair(1, -4), Pair(-30, -6), Pair(-38, -7), Pair(-38, -3), Pair(12, -10), Pair(28, -3), Pair(20, -2),
        Pair(-87, -30), Pair(-16, -11), Pair(-25, -15), Pair(-22, -24), Pair(-7, -28), Pair(-17, 3), Pair(29, -9), Pair(21, -6)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 36), Pair(31, 12), Pair(74, 4), Pair(-37, 25), Pair(0, 14), Pair(12, 5), Pair(59, -33), Pair(47, -95),
        Pair(-16, 24), Pair(15, 18), Pair(-21, 24), Pair(12, 10), Pair(2, 12), Pair(-72, 14), Pair(-27, -35), Pair(4, 29),
        Pair(1, 9), Pair(-2, 16), Pair(-4, 17), Pair(-1, 17), Pair(-5, 8), Pair(-3, 7), Pair(-9, -12), Pair(28, -42),
        Pair(-3, 9), Pair(4, 10), Pair(2, 13), Pair(-4, 12), Pair(-1, 9), Pair(-8, 9), Pair(6, 16), Pair(20, -9),
        Pair(0, 15), Pair(3, 13), Pair(0, 7), Pair(-2, 5), Pair(0, 1), Pair(-1, 8), Pair(8, 14), Pair(17, -5),
        Pair(-1, 19), Pair(5, 6), Pair(0, 7), Pair(-2, -5), Pair(-8, 6), Pair(-6, 10), Pair(-1, 14), Pair(13, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(10, -88), Pair(12, 65), Pair(23, 25), Pair(-138, 16), Pair(9, 8), Pair(190, -29), Pair(9, 56), Pair(47, -23),
        Pair(-4, -24), Pair(-53, 32), Pair(-40, 23), Pair(24, 40), Pair(68, -11), Pair(-2, 20), Pair(23, 34), Pair(74, -74),
        Pair(34, -15), Pair(34, 11), Pair(49, -7), Pair(68, -1), Pair(58, -16), Pair(19, 9), Pair(67, 27), Pair(0, 0),
        Pair(21, 6), Pair(5, 1), Pair(34, 23), Pair(58, 7), Pair(46, 18), Pair(41, -3), Pair(54, 35), Pair(51, -2),
        Pair(21, -4), Pair(42, 9), Pair(18, -5), Pair(26, 5), Pair(46, 2), Pair(23, 16), Pair(56, -10), Pair(23, -18),
        Pair(-3, 7), Pair(1, -27), Pair(16, -10), Pair(12, -1), Pair(14, 4), Pair(16, 10), Pair(21, -19), Pair(29, -11),
        Pair(-13, 0), Pair(39, -35), Pair(8, -2), Pair(3, -19), Pair(18, -34), Pair(21, 11), Pair(-12, -17), Pair(6, -2),
        Pair(51, -112), Pair(1, -5), Pair(-46, 0), Pair(16, -11), Pair(7, -27), Pair(2, -53), Pair(10, -26), Pair(-97, 33)
      },
      { // Piece 2
        Pair(128, -20), Pair(99, -43), Pair(2, -17), Pair(107, -55), Pair(169, -46), Pair(59, -46), Pair(-30, 15), Pair(-108, 20),
        Pair(22, -47), Pair(57, -44), Pair(-10, -15), Pair(35, -39), Pair(54, -26), Pair(16, -3), Pair(113, -26), Pair(-52, -45),
        Pair(20, -32), Pair(81, -72), Pair(61, -41), Pair(70, -46), Pair(76, -22), Pair(60, -31), Pair(134, -35), Pair(0, 0),
        Pair(-36, -11), Pair(39, -22), Pair(28, -19), Pair(52, -28), Pair(55, -25), Pair(78, -8), Pair(76, -29), Pair(90, -12),
        Pair(11, 0), Pair(47, -44), Pair(52, -18), Pair(61, -31), Pair(45, -4), Pair(47, -17), Pair(25, 0), Pair(31, -41),
        Pair(17, -44), Pair(21, -23), Pair(31, -36), Pair(28, -22), Pair(30, -25), Pair(21, -30), Pair(11, -26), Pair(42, -34),
        Pair(43, -49), Pair(33, -30), Pair(46, -36), Pair(28, -36), Pair(26, -25), Pair(18, -29), Pair(28, -40), Pair(-12, 50),
        Pair(34, -43), Pair(42, -35), Pair(20, -18), Pair(37, -29), Pair(26, -38), Pair(6, -19), Pair(4, -38), Pair(59, -74)
      },
      { // Piece 3
        Pair(-17, 23), Pair(47, 14), Pair(16, 35), Pair(165, -33), Pair(75, -1), Pair(47, 26), Pair(152, -9), Pair(67, -31),
        Pair(50, 19), Pair(36, 12), Pair(50, 14), Pair(103, -8), Pair(59, 8), Pair(37, 15), Pair(32, 26), Pair(124, -126),
        Pair(12, 13), Pair(52, 1), Pair(7, 9), Pair(84, -3), Pair(69, -8), Pair(77, -6), Pair(84, -22), Pair(0, 0),
        Pair(-23, 31), Pair(4, -5), Pair(17, 6), Pair(36, 9), Pair(40, -8), Pair(33, 11), Pair(-46, 24), Pair(-21, -38),
        Pair(-15, 16), Pair(11, 12), Pair(7, 19), Pair(-3, 19), Pair(26, -15), Pair(-3, 29), Pair(-42, 20), Pair(-36, -2),
        Pair(5, 0), Pair(4, 13), Pair(2, -9), Pair(-1, -7), Pair(-25, 18), Pair(-5, 7), Pair(-23, 13), Pair(-31, -11),
        Pair(-30, 17), Pair(20, -31), Pair(19, -12), Pair(-20, 1), Pair(2, -9), Pair(2, 6), Pair(-19, 14), Pair(-45, 2),
        Pair(10, -5), Pair(7, 1), Pair(12, 5), Pair(4, -20), Pair(12, -1), Pair(3, 14), Pair(-1, 2), Pair(-32, -23)
      },
      { // Piece 4
        Pair(19, 27), Pair(-38, 76), Pair(72, -24), Pair(38, -36), Pair(95, -80), Pair(50, -14), Pair(55, -102), Pair(44, -10),
        Pair(-41, 95), Pair(-19, 14), Pair(29, -60), Pair(-30, 92), Pair(97, -65), Pair(42, -24), Pair(14, 45), Pair(-42, -93),
        Pair(-23, 105), Pair(-15, -1), Pair(-3, 6), Pair(22, 12), Pair(46, -11), Pair(114, -19), Pair(54, -53), Pair(0, 0),
        Pair(-54, 52), Pair(-18, 58), Pair(27, -20), Pair(-16, 73), Pair(43, -21), Pair(49, -7), Pair(45, 2), Pair(41, -122),
        Pair(-17, -26), Pair(5, -44), Pair(-32, 63), Pair(17, -28), Pair(-14, 20), Pair(39, -25), Pair(17, -32), Pair(1, 24),
        Pair(41, -163), Pair(-12, 16), Pair(-13, 41), Pair(5, -24), Pair(2, 19), Pair(12, -31), Pair(24, -34), Pair(-9, -18),
        Pair(-70, 9), Pair(-5, -24), Pair(9, -54), Pair(4, -9), Pair(9, -39), Pair(-7, -42), Pair(-1, -40), Pair(-11, -46),
        Pair(-1, 80), Pair(-37, -54), Pair(-17, -7), Pair(-8, -20), Pair(-26, 57), Pair(0, -43), Pair(41, -62), Pair(-1, -59)
      },
      { // Piece 5
        Pair(-15, -41), Pair(-43, 27), Pair(10, 20), Pair(-10, -75), Pair(55, 22), Pair(-1, 65), Pair(-147, 86), Pair(104, -45),
        Pair(-31, 6), Pair(60, 12), Pair(93, -4), Pair(-26, 21), Pair(130, -48), Pair(-12, 68), Pair(15, 59), Pair(33, -101),
        Pair(-30, 44), Pair(11, -13), Pair(14, 3), Pair(25, -5), Pair(55, 17), Pair(107, 17), Pair(141, 13), Pair(0, 0),
        Pair(-77, 25), Pair(-24, -3), Pair(126, -21), Pair(-85, 38), Pair(51, 8), Pair(97, 31), Pair(92, 8), Pair(83, -12),
        Pair(56, -41), Pair(-32, 6), Pair(-116, 33), Pair(1, 15), Pair(6, 20), Pair(87, 8), Pair(26, 25), Pair(6, 4),
        Pair(-185, 40), Pair(-28, 17), Pair(-8, 3), Pair(4, 7), Pair(23, 3), Pair(-5, 14), Pair(15, 16), Pair(-3, -4),
        Pair(-4, -9), Pair(-33, 7), Pair(-32, 13), Pair(-19, 4), Pair(-19, 13), Pair(-16, 25), Pair(-7, 16), Pair(-8, 14),
        Pair(-32, 11), Pair(-12, -7), Pair(-16, -7), Pair(-31, -3), Pair(6, -17), Pair(-2, -8), Pair(17, 21), Pair(9, -16)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 16), Pair(20, 27), Pair(1, 6), Pair(2, 12), Pair(10, 14), Pair(19, 14), Pair(29, -10), Pair(-30, 21),
        Pair(1, -22), Pair(3, 11), Pair(12, 10), Pair(-2, 13), Pair(13, 3), Pair(6, 6), Pair(-5, 8), Pair(2, 9),
        Pair(-6, 13), Pair(-11, -2), Pair(-3, 2), Pair(8, 10), Pair(5, 6), Pair(5, 11), Pair(-3, 8), Pair(-3, 13),
        Pair(-7, -4), Pair(-4, 2), Pair(2, 10), Pair(1, 11), Pair(4, 12), Pair(3, 9), Pair(-1, 14), Pair(-1, 14),
        Pair(7, 13), Pair(-5, 11), Pair(4, 11), Pair(1, 6), Pair(-1, 10), Pair(3, 10), Pair(1, 10), Pair(-3, 16),
        Pair(7, 16), Pair(-7, 12), Pair(0, 9), Pair(1, 11), Pair(-3, 14), Pair(-3, 16), Pair(-6, 16), Pair(-2, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-14, 19), Pair(-117, 54), Pair(-28, 56), Pair(65, 12), Pair(-39, 28), Pair(-16, 22), Pair(74, 17), Pair(67, -4),
        Pair(4, 15), Pair(12, 14), Pair(17, 16), Pair(30, 23), Pair(45, 12), Pair(7, 40), Pair(-26, 53), Pair(-11, 32),
        Pair(-35, -3), Pair(-2, 30), Pair(20, 39), Pair(28, 26), Pair(-10, 31), Pair(-3, 34), Pair(-12, 35), Pair(8, 36),
        Pair(0, 0), Pair(1, 34), Pair(16, 33), Pair(30, 41), Pair(10, 42), Pair(13, 22), Pair(8, 26), Pair(3, 19),
        Pair(25, 53), Pair(16, 43), Pair(22, 27), Pair(13, 29), Pair(15, 28), Pair(10, 32), Pair(8, 37), Pair(7, 17),
        Pair(-2, 28), Pair(7, 21), Pair(15, 22), Pair(11, 33), Pair(14, 34), Pair(13, 21), Pair(7, 18), Pair(17, -1),
        Pair(6, 5), Pair(32, -15), Pair(5, 28), Pair(10, 32), Pair(6, 36), Pair(2, 21), Pair(9, 22), Pair(-4, 37),
        Pair(-1, -6), Pair(-1, 3), Pair(-12, 11), Pair(2, 21), Pair(-6, 32), Pair(4, 11), Pair(6, 4), Pair(51, -97)
      },
      { // Piece 2
        Pair(-30, 54), Pair(83, -9), Pair(-80, 54), Pair(53, -11), Pair(0, 15), Pair(63, -19), Pair(40, -5), Pair(-12, -12),
        Pair(35, 9), Pair(28, 43), Pair(43, -2), Pair(50, 14), Pair(37, -13), Pair(18, 17), Pair(10, -15), Pair(0, 27),
        Pair(6, 8), Pair(37, 26), Pair(42, 29), Pair(18, 7), Pair(24, 17), Pair(19, -13), Pair(25, 20), Pair(8, 13),
        Pair(0, 0), Pair(21, 29), Pair(34, 5), Pair(31, 37), Pair(13, 2), Pair(29, 42), Pair(17, -3), Pair(12, 31),
        Pair(39, 40), Pair(29, 11), Pair(29, 30), Pair(14, 9), Pair(20, 38), Pair(20, 4), Pair(32, 15), Pair(23, -17),
        Pair(13, -11), Pair(27, 19), Pair(20, 9), Pair(21, 25), Pair(15, 23), Pair(18, 29), Pair(20, 8), Pair(17, 40),
        Pair(23, -29), Pair(7, -10), Pair(10, 26), Pair(12, 16), Pair(14, 34), Pair(8, 15), Pair(15, 38), Pair(28, -7),
        Pair(22, -22), Pair(-15, 11), Pair(1, -8), Pair(20, 16), Pair(16, 14), Pair(14, 39), Pair(-10, 17), Pair(6, 20)
      },
      { // Piece 3
        Pair(-3, 30), Pair(-22, 73), Pair(-4, 63), Pair(2, 62), Pair(-57, 86), Pair(17, 59), Pair(-42, 75), Pair(3, 53),
        Pair(-33, 36), Pair(7, 68), Pair(16, 58), Pair(-18, 61), Pair(23, 55), Pair(5, 50), Pair(-16, 72), Pair(34, 56),
        Pair(-38, 16), Pair(20, 57), Pair(34, 59), Pair(0, 59), Pair(16, 52), Pair(-22, 61), Pair(43, 42), Pair(29, 55),
        Pair(0, 0), Pair(9, 63), Pair(12, 65), Pair(15, 48), Pair(17, 49), Pair(2, 68), Pair(-8, 64), Pair(16, 67),
        Pair(-29, 43), Pair(-6, 77), Pair(11, 64), Pair(5, 67), Pair(17, 55), Pair(7, 50), Pair(4, 49), Pair(2, 62),
        Pair(-22, 36), Pair(-3, 71), Pair(9, 53), Pair(4, 56), Pair(12, 54), Pair(3, 49), Pair(3, 41), Pair(2, 53),
        Pair(-44, 47), Pair(-8, 52), Pair(8, 42), Pair(-1, 61), Pair(9, 52), Pair(4, 52), Pair(-6, 50), Pair(-2, 63),
        Pair(-21, 30), Pair(1, 57), Pair(5, 51), Pair(4, 45), Pair(6, 49), Pair(6, 45), Pair(2, 52), Pair(6, 29)
      },
      { // Piece 4
        Pair(11, 81), Pair(41, 57), Pair(7, 100), Pair(-48, 123), Pair(-26, 136), Pair(52, 50), Pair(155, 1), Pair(-28, 128),
        Pair(-25, 110), Pair(5, 85), Pair(30, 82), Pair(37, 61), Pair(47, 52), Pair(23, 83), Pair(22, 110), Pair(95, 22),
        Pair(-17, 52), Pair(13, 121), Pair(11, 100), Pair(13, 82), Pair(18, 76), Pair(4, 105), Pair(18, 56), Pair(4, 83),
        Pair(0, 0), Pair(6, 106), Pair(28, 91), Pair(11, 92), Pair(14, 81), Pair(24, 74), Pair(-1, 100), Pair(14, 56),
        Pair(15, 89), Pair(17, 103), Pair(8, 102), Pair(18, 104), Pair(24, 80), Pair(10, 90), Pair(-1, 117), Pair(34, 37),
        Pair(11, 104), Pair(19, 73), Pair(9, 106), Pair(22, 71), Pair(25, 91), Pair(18, 97), Pair(24, 68), Pair(39, 36),
        Pair(6, 65), Pair(29, 61), Pair(16, 79), Pair(19, 97), Pair(20, 97), Pair(20, 81), Pair(35, 60), Pair(24, 41),
        Pair(8, 71), Pair(17, 56), Pair(18, 67), Pair(18, 83), Pair(23, 86), Pair(37, 41), Pair(-25, 137), Pair(-19, 116)
      },
      { // Piece 5
        Pair(0, -22), Pair(62, 85), Pair(-47, 67), Pair(72, 15), Pair(-20, 71), Pair(-19, 43), Pair(51, -11), Pair(50, -26),
        Pair(-118, 79), Pair(16, 123), Pair(-14, 88), Pair(5, 73), Pair(-34, 26), Pair(-2, 4), Pair(82, -12), Pair(108, -26),
        Pair(18, 4), Pair(54, 66), Pair(93, 75), Pair(36, 57), Pair(76, 20), Pair(57, 12), Pair(-56, 31), Pair(-63, 4),
        Pair(0, 0), Pair(21, 71), Pair(30, 64), Pair(13, 57), Pair(61, 27), Pair(-19, 33), Pair(-8, 12), Pair(-87, 16),
        Pair(-38, 17), Pair(18, 47), Pair(15, 56), Pair(13, 40), Pair(-14, 40), Pair(-4, 24), Pair(-12, 15), Pair(-73, 26),
        Pair(54, -7), Pair(65, 40), Pair(44, 25), Pair(-4, 34), Pair(-15, 30), Pair(-12, 15), Pair(-17, 14), Pair(-49, 8),
        Pair(12, 31), Pair(78, 28), Pair(27, 25), Pair(-23, 25), Pair(-5, 19), Pair(-33, 19), Pair(-17, 10), Pair(-19, 1),
        Pair(69, -60), Pair(81, -4), Pair(12, 12), Pair(-27, 10), Pair(-17, 14), Pair(-20, 12), Pair(-10, 0), Pair(-10, -7)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 39), Pair(8, -13), Pair(1, 34), Pair(8, 9), Pair(-15, 24), Pair(-5, 15), Pair(-45, 30), Pair(-2, 17),
        Pair(-11, -4), Pair(7, -25), Pair(7, 20), Pair(4, 14), Pair(13, 3), Pair(4, 5), Pair(4, 10), Pair(-1, 16),
        Pair(-9, -2), Pair(-2, 21), Pair(-7, 6), Pair(-8, 1), Pair(3, 12), Pair(7, 6), Pair(2, 13), Pair(0, 11),
        Pair(0, 5), Pair(1, -11), Pair(1, 8), Pair(1, 6), Pair(2, 10), Pair(5, 9), Pair(-2, 14), Pair(0, 11),
        Pair(-5, 9), Pair(3, 9), Pair(-3, 8), Pair(3, 11), Pair(2, 10), Pair(4, 8), Pair(2, 15), Pair(2, 12),
        Pair(-4, 15), Pair(6, 3), Pair(-8, 15), Pair(-1, 9), Pair(-1, 15), Pair(3, 13), Pair(-1, 14), Pair(0, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-10, 10), Pair(138, 7), Pair(11, 50), Pair(15, 57), Pair(-25, 30), Pair(-138, 93), Pair(62, -5), Pair(62, -66),
        Pair(13, 34), Pair(-3, 25), Pair(-1, 43), Pair(18, 46), Pair(15, 49), Pair(-8, 47), Pair(4, 37), Pair(-57, 42),
        Pair(7, 12), Pair(-16, 26), Pair(52, 33), Pair(-8, 61), Pair(7, 46), Pair(39, 33), Pair(-2, 36), Pair(-26, 52),
        Pair(3, 49), Pair(0, 0), Pair(18, 44), Pair(16, 54), Pair(9, 50), Pair(12, 44), Pair(2, 37), Pair(11, 29),
        Pair(9, 70), Pair(42, 49), Pair(14, 55), Pair(10, 39), Pair(12, 46), Pair(16, 44), Pair(1, 46), Pair(-2, 37),
        Pair(-20, 0), Pair(22, 38), Pair(2, 38), Pair(10, 38), Pair(16, 39), Pair(7, 40), Pair(8, 33), Pair(5, -3),
        Pair(-37, 9), Pair(4, 36), Pair(0, 26), Pair(1, 38), Pair(6, 41), Pair(12, 34), Pair(9, 42), Pair(3, 42),
        Pair(-18, 19), Pair(-9, 8), Pair(-2, 25), Pair(7, 28), Pair(4, 33), Pair(7, 35), Pair(-11, 14), Pair(25, -24)
      },
      { // Piece 2
        Pair(71, 3), Pair(9, 51), Pair(79, -18), Pair(-23, 54), Pair(-11, -18), Pair(-1, 29), Pair(87, -28), Pair(-15, 27),
        Pair(16, 42), Pair(2, 12), Pair(0, 45), Pair(0, -2), Pair(31, 21), Pair(6, 2), Pair(34, 13), Pair(30, -24),
        Pair(-1, -1), Pair(1, 20), Pair(57, -6), Pair(10, 24), Pair(44, -15), Pair(11, 25), Pair(38, -17), Pair(-9, 20),
        Pair(-11, 39), Pair(0, 0), Pair(4, 35), Pair(33, -1), Pair(15, 29), Pair(28, -2), Pair(13, 29), Pair(5, 25),
        Pair(-5, -7), Pair(17, 56), Pair(19, 2), Pair(15, 32), Pair(22, 5), Pair(8, 35), Pair(10, 11), Pair(4, 19),
        Pair(2, 30), Pair(7, 9), Pair(12, 23), Pair(7, 6), Pair(10, 53), Pair(9, 16), Pair(18, 33), Pair(10, 9),
        Pair(19, -1), Pair(11, 23), Pair(10, -1), Pair(4, 33), Pair(8, 14), Pair(11, 47), Pair(16, 19), Pair(3, 59),
        Pair(-4, 15), Pair(7, 9), Pair(-5, 35), Pair(4, 13), Pair(4, 14), Pair(3, 13), Pair(16, 23), Pair(18, -3)
      },
      { // Piece 3
        Pair(4, 65), Pair(-47, 35), Pair(-13, 66), Pair(-2, 59), Pair(-45, 80), Pair(-42, 80), Pair(17, 75), Pair(-1, 62),
        Pair(-6, 58), Pair(-42, 38), Pair(1, 46), Pair(7, 56), Pair(5, 64), Pair(-22, 67), Pair(19, 51), Pair(-2, 53),
        Pair(-18, 74), Pair(-71, 23), Pair(11, 72), Pair(-12, 77), Pair(-12, 67), Pair(-11, 74), Pair(15, 40), Pair(11, 66),
        Pair(-29, 59), Pair(0, 0), Pair(1, 58), Pair(4, 57), Pair(-3, 64), Pair(-4, 52), Pair(-5, 71), Pair(10, 63),
        Pair(2, 63), Pair(-9, 26), Pair(9, 63), Pair(7, 59), Pair(-8, 56), Pair(3, 48), Pair(-19, 58), Pair(-10, 72),
        Pair(5, 50), Pair(-33, 45), Pair(-1, 50), Pair(4, 55), Pair(13, 40), Pair(4, 37), Pair(-19, 45), Pair(1, 36),
        Pair(-17, 54), Pair(-38, 35), Pair(-1, 59), Pair(-3, 53), Pair(-8, 52), Pair(3, 44), Pair(-20, 61), Pair(-38, 58),
        Pair(-4, 51), Pair(-20, 26), Pair(-4, 52), Pair(-1, 55), Pair(0, 49), Pair(-4, 40), Pair(-8, 46), Pair(0, 39)
      },
      { // Piece 4
        Pair(21, 28), Pair(35, 16), Pair(4, 54), Pair(-78, 100), Pair(9, 48), Pair(104, -12), Pair(18, 19), Pair(61, 1),
        Pair(6, 23), Pair(-23, 34), Pair(26, 20), Pair(13, 42), Pair(-14, 74), Pair(12, 48), Pair(27, 43), Pair(-33, 77),
        Pair(0, 33), Pair(-19, -13), Pair(4, 54), Pair(-6, 66), Pair(0, 71), Pair(-31, 106), Pair(-6, 70), Pair(-22, 66),
        Pair(-2, 52), Pair(0, 0), Pair(-13, 69), Pair(5, 69), Pair(10, 39), Pair(-6, 63), Pair(-3, 56), Pair(-1, 40),
        Pair(-4, 63), Pair(10, 30), Pair(15, 60), Pair(-1, 63), Pair(8, 58), Pair(-6, 75), Pair(1, 55), Pair(16, 12),
        Pair(7, 34), Pair(12, 29), Pair(0, 53), Pair(5, 69), Pair(7, 56), Pair(8, 59), Pair(9, 33), Pair(5, 32),
        Pair(12, 7), Pair(7, 26), Pair(7, 43), Pair(7, 51), Pair(0, 64), Pair(8, 56), Pair(28, 27), Pair(41, 16),
        Pair(-2, 38), Pair(0, 26), Pair(3, 42), Pair(5, 47), Pair(10, 47), Pair(0, 52), Pair(18, 25), Pair(26, -3)
      },
      { // Piece 5
        Pair(1, 90), Pair(30, 76), Pair(22, 118), Pair(72, 71), Pair(-25, 95), Pair(40, -2), Pair(42, -12), Pair(8, 13),
        Pair(-171, 148), Pair(-202, 126), Pair(30, 107), Pair(76, 23), Pair(184, 25), Pair(29, 29), Pair(52, 3), Pair(78, 28),
        Pair(108, 50), Pair(-3, 57), Pair(207, 24), Pair(-77, 92), Pair(86, 50), Pair(9, 39), Pair(31, 16), Pair(-62, 18),
        Pair(80, 90), Pair(0, 0), Pair(101, 70), Pair(44, 52), Pair(12, 44), Pair(-32, 28), Pair(-49, 23), Pair(-80, 15),
        Pair(12, 70), Pair(54, 32), Pair(74, 27), Pair(7, 43), Pair(-7, 30), Pair(-52, 23), Pair(-23, 14), Pair(1, -10),
        Pair(-9, 56), Pair(33, 26), Pair(12, 40), Pair(-16, 30), Pair(-22, 26), Pair(-30, 14), Pair(-38, 10), Pair(-56, 7),
        Pair(65, 20), Pair(25, 21), Pair(10, 27), Pair(-25, 23), Pair(-14, 9), Pair(-24, 13), Pair(-11, 0), Pair(-9, -7),
        Pair(50, -1), Pair(54, -12), Pair(18, 9), Pair(-24, 15), Pair(-14, -1), Pair(-22, 0), Pair(-4, -4), Pair(-8, -14)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, 9), Pair(24, 28), Pair(-70, 3), Pair(20, 21), Pair(-21, 23), Pair(-72, 45), Pair(32, 4), Pair(-11, 17),
        Pair(10, 10), Pair(10, 2), Pair(-15, -41), Pair(16, 31), Pair(3, 8), Pair(8, 14), Pair(0, 10), Pair(-4, 16),
        Pair(-4, 2), Pair(-7, 6), Pair(1, 9), Pair(5, 9), Pair(3, 1), Pair(14, 7), Pair(3, 8), Pair(6, 14),
        Pair(-1, 7), Pair(11, 10), Pair(-4, -24), Pair(9, 14), Pair(1, 11), Pair(8, 9), Pair(2, 8), Pair(3, 12),
        Pair(1, 11), Pair(-3, 12), Pair(4, -1), Pair(-6, 13), Pair(3, 10), Pair(6, 7), Pair(4, 11), Pair(4, 11),
        Pair(-1, 13), Pair(-4, 13), Pair(0, -5), Pair(3, 19), Pair(-2, 11), Pair(4, 13), Pair(6, 10), Pair(0, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-57, 139), Pair(10, 61), Pair(75, 18), Pair(71, 32), Pair(-44, 58), Pair(114, 14), Pair(-45, 22), Pair(29, 47),
        Pair(10, 49), Pair(9, 42), Pair(37, 32), Pair(11, 44), Pair(44, 34), Pair(70, 24), Pair(-42, 50), Pair(66, 12),
        Pair(-10, 46), Pair(-26, 51), Pair(-9, 19), Pair(50, 48), Pair(17, 34), Pair(0, 51), Pair(0, 50), Pair(-6, 34),
        Pair(-6, 51), Pair(11, 49), Pair(0, 0), Pair(34, 48), Pair(17, 56), Pair(36, 46), Pair(10, 46), Pair(3, 52),
        Pair(-1, 23), Pair(42, 54), Pair(34, 75), Pair(27, 65), Pair(18, 43), Pair(12, 42), Pair(6, 40), Pair(8, 47),
        Pair(-1, 48), Pair(7, 36), Pair(9, 37), Pair(11, 41), Pair(14, 49), Pair(10, 47), Pair(5, 46), Pair(10, 33),
        Pair(-4, 45), Pair(13, 12), Pair(12, 47), Pair(12, 41), Pair(5, 42), Pair(15, 36), Pair(4, 40), Pair(0, 23),
        Pair(43, 27), Pair(0, 11), Pair(-10, 35), Pair(2, 39), Pair(11, 32), Pair(8, 32), Pair(4, 11), Pair(41, 1)
      },
      { // Piece 2
        Pair(-7, 52), Pair(59, -14), Pair(91, 26), Pair(-21, 12), Pair(-10, 19), Pair(19, -22), Pair(65, 9), Pair(86, -52),
        Pair(-6, -6), Pair(38, 38), Pair(14, 4), Pair(44, 7), Pair(39, -28), Pair(-27, 33), Pair(23, -14), Pair(34, 29),
        Pair(19, 35), Pair(-42, 22), Pair(9, 7), Pair(54, 9), Pair(27, 26), Pair(21, 0), Pair(35, 5), Pair(11, 27),
        Pair(2, 2), Pair(22, 17), Pair(0, 0), Pair(36, 38), Pair(31, -5), Pair(33, 18), Pair(7, 13), Pair(15, 26),
        Pair(35, 39), Pair(-3, 2), Pair(38, 53), Pair(19, 11), Pair(29, 38), Pair(26, 11), Pair(23, 28), Pair(22, 17),
        Pair(-17, -8), Pair(30, 21), Pair(2, 15), Pair(11, 36), Pair(2, 19), Pair(19, 38), Pair(29, 2), Pair(6, 31),
        Pair(19, 17), Pair(2, 14), Pair(26, 29), Pair(7, 10), Pair(14, 36), Pair(9, 13), Pair(21, 39), Pair(18, 15),
        Pair(0, 12), Pair(25, 0), Pair(1, 8), Pair(7, 30), Pair(11, 14), Pair(7, 36), Pair(-17, 6), Pair(28, 22)
      },
      { // Piece 3
        Pair(-2, 62), Pair(-9, 52), Pair(-10, 34), Pair(3, 61), Pair(-23, 62), Pair(-50, 77), Pair(15, 50), Pair(36, 45),
        Pair(-2, 67), Pair(24, 45), Pair(-41, 49), Pair(-18, 71), Pair(-4, 64), Pair(-2, 65), Pair(11, 62), Pair(13, 57),
        Pair(8, 58), Pair(14, 59), Pair(-25, 2), Pair(41, 52), Pair(5, 59), Pair(12, 60), Pair(23, 52), Pair(19, 49),
        Pair(-2, 48), Pair(-14, 57), Pair(0, 0), Pair(16, 42), Pair(8, 39), Pair(8, 53), Pair(0, 50), Pair(13, 52),
        Pair(14, 42), Pair(4, 56), Pair(12, 27), Pair(3, 56), Pair(-2, 52), Pair(-5, 43), Pair(-6, 56), Pair(-2, 50),
        Pair(-2, 52), Pair(5, 52), Pair(-15, 32), Pair(-6, 60), Pair(-3, 49), Pair(-6, 49), Pair(-4, 43), Pair(8, 53),
        Pair(-12, 68), Pair(1, 55), Pair(-10, 40), Pair(-9, 51), Pair(0, 47), Pair(6, 41), Pair(-18, 51), Pair(-2, 44),
        Pair(2, 46), Pair(4, 44), Pair(-4, 27), Pair(0, 41), Pair(2, 49), Pair(1, 41), Pair(7, 37), Pair(3, 34)
      },
      { // Piece 4
        Pair(46, -6), Pair(19, 54), Pair(-18, 32), Pair(-25, 61), Pair(-6, 58), Pair(52, 16), Pair(74, 34), Pair(34, 37),
        Pair(-8, 35), Pair(13, 40), Pair(0, 21), Pair(-15, 89), Pair(11, 32), Pair(26, 40), Pair(23, 78), Pair(20, 61),
        Pair(-9, 68), Pair(-11, 51), Pair(-3, -30), Pair(8, 65), Pair(7, 71), Pair(-27, 112), Pair(14, 76), Pair(9, 53),
        Pair(-1, 52), Pair(-2, 54), Pair(0, 0), Pair(16, 68), Pair(16, 58), Pair(-15, 91), Pair(1, 71), Pair(-11, 70),
        Pair(7, 53), Pair(9, 54), Pair(7, 47), Pair(14, 42), Pair(5, 74), Pair(-11, 83), Pair(2, 68), Pair(2, 53),
        Pair(1, 29), Pair(13, 55), Pair(-6, 56), Pair(7, 47), Pair(0, 74), Pair(5, 68), Pair(1, 76), Pair(9, 57),
        Pair(5, 69), Pair(3, 60), Pair(8, 35), Pair(11, 39), Pair(6, 59), Pair(9, 36), Pair(18, 19), Pair(14, 17),
        Pair(2, 52), Pair(3, 50), Pair(6, 35), Pair(3, 45), Pair(6, 56), Pair(11, 39), Pair(18, -6), Pair(13, 51)
      },
      { // Piece 5
        Pair(-17, 41), Pair(33, 93), Pair(36, 57), Pair(35, 116), Pair(1, 15), Pair(211, -41), Pair(-16, 45), Pair(-40, 6),
        Pair(47, 52), Pair(51, 112), Pair(137, 81), Pair(7, 122), Pair(77, 24), Pair(-48, 16), Pair(-175, 28), Pair(-76, -9),
        Pair(94, 76), Pair(186, 16), Pair(108, 39), Pair(139, 22), Pair(11, 50), Pair(62, 18), Pair(16, 19), Pair(-73, 34),
        Pair(115, 42), Pair(42, 67), Pair(0, 0), Pair(102, 51), Pair(91, 23), Pair(100, 3), Pair(-13, 3), Pair(-44, 19),
        Pair(-34, 63), Pair(77, 26), Pair(23, 41), Pair(12, 31), Pair(-43, 36), Pair(-37, 21), Pair(-49, 7), Pair(-28, -9),
        Pair(31, 29), Pair(-15, 34), Pair(10, 22), Pair(-23, 32), Pair(8, 5), Pair(-3, -1), Pair(-13, -2), Pair(-23, -4),
        Pair(28, 6), Pair(40, -5), Pair(4, -6), Pair(16, -7), Pair(-11, 0), Pair(-13, 0), Pair(-11, -8), Pair(-10, -18),
        Pair(23, 21), Pair(12, -7), Pair(22, -12), Pair(-13, -18), Pair(1, -21), Pair(-7, -18), Pair(0, -16), Pair(-4, -24)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 8), Pair(-16, 31), Pair(-18, 37), Pair(-11, -11), Pair(-9, 40), Pair(34, -9), Pair(-2, 18), Pair(11, 15),
        Pair(-4, 14), Pair(-1, 18), Pair(-1, 23), Pair(-5, -29), Pair(10, 25), Pair(13, 11), Pair(-15, 18), Pair(0, 18),
        Pair(6, 9), Pair(-7, 1), Pair(6, 9), Pair(4, -9), Pair(-1, 17), Pair(4, 1), Pair(11, 11), Pair(3, 6),
        Pair(0, 8), Pair(5, 5), Pair(2, 13), Pair(0, -2), Pair(9, 17), Pair(8, 7), Pair(6, 7), Pair(2, 8),
        Pair(-3, 11), Pair(6, 11), Pair(-2, 13), Pair(10, 6), Pair(-2, 16), Pair(9, 10), Pair(2, 9), Pair(3, 9),
        Pair(-3, 13), Pair(1, 14), Pair(-3, 17), Pair(12, 6), Pair(0, 19), Pair(-2, 12), Pair(1, 7), Pair(2, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-10, 39), Pair(-26, 93), Pair(9, 53), Pair(-1, 66), Pair(-24, 70), Pair(-37, 57), Pair(146, 23), Pair(-77, 74),
        Pair(1, 65), Pair(13, 62), Pair(-16, 33), Pair(4, 50), Pair(15, 43), Pair(18, 55), Pair(28, 25), Pair(-6, 88),
        Pair(47, 37), Pair(5, 30), Pair(51, 42), Pair(-25, 28), Pair(34, 56), Pair(49, 33), Pair(6, 41), Pair(14, 24),
        Pair(39, 59), Pair(5, 54), Pair(6, 55), Pair(0, 0), Pair(0, 58), Pair(19, 56), Pair(-1, 57), Pair(-2, 33),
        Pair(1, 40), Pair(5, 38), Pair(25, 67), Pair(21, 71), Pair(12, 70), Pair(2, 44), Pair(-4, 43), Pair(4, 47),
        Pair(4, 34), Pair(5, 46), Pair(0, 33), Pair(19, 34), Pair(6, 36), Pair(6, 49), Pair(4, 46), Pair(6, 28),
        Pair(-7, 17), Pair(14, 33), Pair(-4, 40), Pair(8, 50), Pair(2, 43), Pair(6, 37), Pair(3, 38), Pair(-1, 37),
        Pair(3, 43), Pair(-8, 31), Pair(-20, 47), Pair(11, 22), Pair(6, 41), Pair(5, 43), Pair(-3, 28), Pair(61, -62)
      },
      { // Piece 2
        Pair(-76, -9), Pair(-28, 34), Pair(83, -45), Pair(27, 34), Pair(50, -33), Pair(18, -10), Pair(-13, 0), Pair(-26, -10),
        Pair(12, 22), Pair(6, -30), Pair(29, 38), Pair(37, -29), Pair(68, 15), Pair(8, -19), Pair(18, 21), Pair(-15, 13),
        Pair(13, -14), Pair(22, 28), Pair(6, -29), Pair(-13, 1), Pair(48, 16), Pair(35, 27), Pair(36, -5), Pair(-5, 47),
        Pair(15, 35), Pair(13, 1), Pair(24, 20), Pair(0, 0), Pair(16, 40), Pair(16, -8), Pair(11, 35), Pair(-2, 3),
        Pair(-1, 3), Pair(25, 32), Pair(2, -9), Pair(28, 50), Pair(0, 10), Pair(10, 34), Pair(6, 0), Pair(2, 43),
        Pair(13, 41), Pair(-4, -4), Pair(15, 33), Pair(5, 10), Pair(11, 37), Pair(-5, 2), Pair(10, 26), Pair(6, 5),
        Pair(-24, 12), Pair(10, 37), Pair(-3, 0), Pair(14, 36), Pair(-1, 13), Pair(20, 20), Pair(-11, 2), Pair(6, 56),
        Pair(8, 13), Pair(-3, 16), Pair(7, 30), Pair(7, -6), Pair(14, 20), Pair(-10, 7), Pair(26, 11), Pair(-26, -9)
      },
      { // Piece 3
        Pair(-3, 51), Pair(-18, 64), Pair(-21, 65), Pair(12, 37), Pair(4, 65), Pair(-11, 64), Pair(-14, 72), Pair(60, 45),
        Pair(-11, 68), Pair(-3, 54), Pair(-8, 58), Pair(-18, 39), Pair(-7, 58), Pair(1, 58), Pair(-18, 72), Pair(-4, 66),
        Pair(-3, 65), Pair(9, 61), Pair(0, 63), Pair(-28, -6), Pair(33, 48), Pair(-11, 65), Pair(5, 66), Pair(2, 53),
        Pair(-5, 50), Pair(-1, 45), Pair(-13, 50), Pair(0, 0), Pair(5, 51), Pair(-4, 53), Pair(5, 44), Pair(18, 44),
        Pair(2, 45), Pair(0, 51), Pair(16, 53), Pair(15, 26), Pair(-5, 66), Pair(-3, 44), Pair(6, 43), Pair(11, 33),
        Pair(4, 49), Pair(4, 46), Pair(3, 51), Pair(-3, 22), Pair(5, 41), Pair(2, 42), Pair(-10, 61), Pair(15, 32),
        Pair(-9, 47), Pair(2, 44), Pair(-5, 47), Pair(-13, 37), Pair(-1, 49), Pair(-11, 48), Pair(-1, 36), Pair(-4, 38),
        Pair(-1, 45), Pair(-2, 55), Pair(-3, 48), Pair(3, 33), Pair(1, 47), Pair(-4, 49), Pair(4, 44), Pair(6, 36)
      },
      { // Piece 4
        Pair(-32, 62), Pair(-9, 84), Pair(20, 47), Pair(-28, 70), Pair(-48, 121), Pair(120, 23), Pair(100, 16), Pair(35, 31),
        Pair(7, 61), Pair(11, 32), Pair(24, 50), Pair(9, 41), Pair(6, 64), Pair(17, 52), Pair(67, 15), Pair(10, 73),
        Pair(13, 55), Pair(10, 73), Pair(-8, 80), Pair(-23, -4), Pair(-26, 98), Pair(24, 82), Pair(7, 89), Pair(3, 65),
        Pair(-1, 57), Pair(-5, 63), Pair(13, 38), Pair(0, 0), Pair(2, 80), Pair(11, 64), Pair(3, 63), Pair(-2, 61),
        Pair(6, 67), Pair(15, 75), Pair(7, 81), Pair(16, 49), Pair(-9, 69), Pair(4, 90), Pair(3, 78), Pair(14, 46),
        Pair(14, 59), Pair(16, 41), Pair(11, 65), Pair(10, 51), Pair(9, 61), Pair(6, 57), Pair(16, 66), Pair(-2, 54),
        Pair(8, 37), Pair(19, 45), Pair(10, 57), Pair(7, 43), Pair(5, 72), Pair(4, 58), Pair(10, 51), Pair(6, 44),
        Pair(7, 46), Pair(6, 39), Pair(13, 39), Pair(7, 62), Pair(9, 53), Pair(-1, 69), Pair(11, 36), Pair(-19, 79)
      },
      { // Piece 5
        Pair(2, 74), Pair(68, 116), Pair(34, 131), Pair(-93, 71), Pair(60, 59), Pair(86, 11), Pair(-24, 10), Pair(-17, 14),
        Pair(50, 10), Pair(135, 27), Pair(32, 102), Pair(58, 68), Pair(-92, 72), Pair(-11, 17), Pair(-9, 24), Pair(86, 3),
        Pair(-83, 57), Pair(68, 54), Pair(152, 17), Pair(2, 40), Pair(94, 29), Pair(61, 20), Pair(66, 0), Pair(-122, 30),
        Pair(53, 8), Pair(76, 35), Pair(-26, 69), Pair(0, 0), Pair(-57, 70), Pair(4, 20), Pair(-61, 24), Pair(-58, 9),
        Pair(-19, 37), Pair(34, 30), Pair(-26, 46), Pair(-73, 64), Pair(-19, 29), Pair(-35, 19), Pair(-16, 8), Pair(-3, -2),
        Pair(23, 3), Pair(42, -1), Pair(-15, 27), Pair(-63, 42), Pair(-22, 17), Pair(-3, 2), Pair(-16, -2), Pair(-8, -12),
        Pair(5, -4), Pair(9, -3), Pair(13, -14), Pair(-40, 22), Pair(3, -17), Pair(-6, -7), Pair(3, -5), Pair(6, -15),
        Pair(-4, -23), Pair(-9, 0), Pair(3, -25), Pair(-52, -5), Pair(1, -41), Pair(-14, -12), Pair(2, -18), Pair(1, -25)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 13), Pair(12, 6), Pair(-16, 22), Pair(-6, 37), Pair(12, -7), Pair(-21, 36), Pair(17, 4), Pair(1, 11),
        Pair(5, 11), Pair(-1, 11), Pair(-2, 12), Pair(10, 27), Pair(6, -40), Pair(14, 6), Pair(-12, 16), Pair(-5, 10),
        Pair(6, 8), Pair(3, 11), Pair(3, 0), Pair(-1, 17), Pair(7, -12), Pair(7, 6), Pair(-13, 0), Pair(3, 12),
        Pair(2, 11), Pair(4, 8), Pair(4, 9), Pair(11, 10), Pair(-3, -8), Pair(10, 9), Pair(4, 8), Pair(-2, 11),
        Pair(2, 8), Pair(6, 11), Pair(7, 7), Pair(1, 16), Pair(12, 6), Pair(1, 13), Pair(-2, 9), Pair(-5, 9),
        Pair(0, 12), Pair(3, 10), Pair(2, 10), Pair(3, 16), Pair(4, 15), Pair(-5, 13), Pair(-7, 13), Pair(-5, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(5, -4), Pair(-38, 79), Pair(15, 71), Pair(25, 54), Pair(88, 54), Pair(35, 29), Pair(-106, 105), Pair(-59, 51),
        Pair(5, 32), Pair(23, 53), Pair(4, 51), Pair(3, 46), Pair(9, 40), Pair(34, 17), Pair(14, 71), Pair(-13, 45),
        Pair(1, 62), Pair(4, 55), Pair(16, 37), Pair(49, 51), Pair(8, 23), Pair(-13, 56), Pair(14, 41), Pair(36, 31),
        Pair(1, 36), Pair(11, 53), Pair(4, 54), Pair(15, 48), Pair(0, 0), Pair(25, 44), Pair(16, 45), Pair(18, 43),
        Pair(1, 50), Pair(11, 37), Pair(8, 37), Pair(10, 61), Pair(24, 84), Pair(21, 51), Pair(12, 33), Pair(11, 49),
        Pair(-8, 37), Pair(11, 36), Pair(-1, 43), Pair(-4, 38), Pair(17, 44), Pair(-2, 39), Pair(9, 34), Pair(-3, 57),
        Pair(-2, 19), Pair(24, 26), Pair(-3, 46), Pair(-3, 32), Pair(3, 51), Pair(-2, 41), Pair(11, 30), Pair(-4, 36),
        Pair(73, -11), Pair(-8, 40), Pair(13, 28), Pair(9, 28), Pair(6, 39), Pair(-7, 36), Pair(0, 16), Pair(-7, 87)
      },
      { // Piece 2
        Pair(5, 28), Pair(-57, -9), Pair(-4, 7), Pair(70, -22), Pair(57, 12), Pair(31, -7), Pair(123, -1), Pair(67, -24),
        Pair(-9, -3), Pair(14, 16), Pair(-1, -14), Pair(37, 22), Pair(27, -17), Pair(61, 22), Pair(44, -35), Pair(31, 8),
        Pair(13, 23), Pair(10, -1), Pair(25, 25), Pair(21, 7), Pair(-12, 5), Pair(12, -1), Pair(31, 29), Pair(4, 12),
        Pair(11, -8), Pair(14, 25), Pair(20, -2), Pair(19, 27), Pair(0, 0), Pair(48, 22), Pair(1, 10), Pair(8, 39),
        Pair(20, 10), Pair(8, 9), Pair(13, 35), Pair(-6, 10), Pair(35, 56), Pair(4, -4), Pair(22, 34), Pair(14, 4),
        Pair(-6, 7), Pair(15, 34), Pair(-7, 0), Pair(13, 23), Pair(2, 18), Pair(14, 25), Pair(-11, -9), Pair(9, 40),
        Pair(16, 22), Pair(-15, -3), Pair(24, 25), Pair(-1, 7), Pair(10, 34), Pair(7, -9), Pair(1, 37), Pair(-24, -13),
        Pair(-24, 4), Pair(15, 14), Pair(-4, 9), Pair(5, 27), Pair(-6, -12), Pair(-3, 34), Pair(14, -1), Pair(4, 28)
      },
      { // Piece 3
        Pair(19, 49), Pair(36, 44), Pair(27, 45), Pair(43, 36), Pair(-40, 54), Pair(-20, 68), Pair(63, 46), Pair(69, 32),
        Pair(7, 54), Pair(-2, 59), Pair(6, 45), Pair(-3, 50), Pair(-22, 45), Pair(8, 48), Pair(19, 43), Pair(-2, 70),
        Pair(1, 51), Pair(14, 44), Pair(-4, 59), Pair(3, 51), Pair(-31, 2), Pair(41, 51), Pair(35, 47), Pair(34, 53),
        Pair(3, 40), Pair(8, 38), Pair(5, 42), Pair(2, 39), Pair(0, 0), Pair(9, 29), Pair(-2, 42), Pair(9, 55),
        Pair(5, 42), Pair(3, 45), Pair(2, 55), Pair(3, 47), Pair(23, 27), Pair(11, 39), Pair(24, 39), Pair(10, 55),
        Pair(-6, 36), Pair(4, 50), Pair(13, 30), Pair(3, 44), Pair(9, 16), Pair(-2, 37), Pair(16, 34), Pair(-3, 55),
        Pair(-6, 32), Pair(3, 36), Pair(-5, 44), Pair(-3, 42), Pair(4, 14), Pair(-2, 48), Pair(-1, 37), Pair(-9, 38),
        Pair(0, 35), Pair(-1, 40), Pair(-2, 40), Pair(1, 43), Pair(10, 18), Pair(0, 41), Pair(0, 39), Pair(11, 36)
      },
      { // Piece 4
        Pair(1, 78), Pair(-3, 44), Pair(45, 42), Pair(-3, 89), Pair(-28, 54), Pair(93, 16), Pair(-8, 92), Pair(92, 17),
        Pair(2, 31), Pair(11, 47), Pair(3, 28), Pair(14, 54), Pair(19, 28), Pair(39, 10), Pair(18, 42), Pair(-16, 129),
        Pair(0, 68), Pair(21, 31), Pair(12, 56), Pair(-4, 73), Pair(0, -13), Pair(43, 69), Pair(31, 101), Pair(36, 90),
        Pair(-8, 69), Pair(13, 32), Pair(8, 39), Pair(18, 37), Pair(0, 0), Pair(22, 53), Pair(17, 85), Pair(20, 44),
        Pair(20, 20), Pair(11, 62), Pair(14, 36), Pair(8, 52), Pair(29, 54), Pair(13, 54), Pair(26, 69), Pair(18, 74),
        Pair(14, 61), Pair(14, 51), Pair(4, 49), Pair(19, 47), Pair(8, 63), Pair(22, 44), Pair(16, 23), Pair(20, 73),
        Pair(8, 26), Pair(10, 34), Pair(20, 41), Pair(16, 40), Pair(17, 40), Pair(11, 37), Pair(22, 4), Pair(15, -5),
        Pair(-4, 56), Pair(13, 56), Pair(17, 39), Pair(13, 51), Pair(24, 17), Pair(14, 28), Pair(25, 38), Pair(65, -35)
      },
      { // Piece 5
        Pair(-20, 33), Pair(-71, 40), Pair(25, 78), Pair(-20, 41), Pair(-102, 74), Pair(34, 92), Pair(14, 34), Pair(-52, -19),
        Pair(-38, 14), Pair(98, 4), Pair(56, 10), Pair(131, 63), Pair(88, 51), Pair(19, 90), Pair(96, 17), Pair(-7, 21),
        Pair(146, -11), Pair(-1, 9), Pair(-40, 24), Pair(-31, 34), Pair(-7, 32), Pair(51, 5), Pair(43, 31), Pair(65, 10),
        Pair(-16, 21), Pair(19, 11), Pair(-15, 20), Pair(-29, 34), Pair(0, 0), Pair(16, 24), Pair(45, 5), Pair(26, 6),
        Pair(-88, 17), Pair(-3, 10), Pair(-33, 24), Pair(-31, 21), Pair(-23, 35), Pair(-32, 14), Pair(11, 2), Pair(-2, 3),
        Pair(-68, 17), Pair(-7, -9), Pair(1, -3), Pair(-29, 20), Pair(-34, 17), Pair(-24, 5), Pair(11, -15), Pair(13, -23),
        Pair(-9, -24), Pair(-25, -9), Pair(-7, -19), Pair(-18, -12), Pair(1, -14), Pair(1, -16), Pair(6, -24), Pair(20, -23),
        Pair(-31, -25), Pair(-7, -24), Pair(-11, -23), Pair(-8, -36), Pair(-12, -46), Pair(-3, -46), Pair(9, -29), Pair(13, -39)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 21), Pair(-10, 13), Pair(35, 4), Pair(-1, 21), Pair(8, 20), Pair(10, -19), Pair(-26, 22), Pair(18, 20),
        Pair(-1, 13), Pair(-9, 12), Pair(5, 13), Pair(1, 14), Pair(20, 12), Pair(-10, -21), Pair(0, -4), Pair(-5, 7),
        Pair(4, 9), Pair(9, 7), Pair(15, 5), Pair(4, 0), Pair(8, 8), Pair(-6, -1), Pair(-12, 0), Pair(-19, 0),
        Pair(1, 7), Pair(7, 11), Pair(9, 7), Pair(5, 6), Pair(14, 6), Pair(-2, -3), Pair(12, -2), Pair(2, 4),
        Pair(-1, 8), Pair(7, 7), Pair(5, 8), Pair(8, 8), Pair(5, 12), Pair(9, 6), Pair(-4, 9), Pair(-5, 10),
        Pair(-1, 12), Pair(4, 8), Pair(3, 7), Pair(3, 6), Pair(7, 16), Pair(3, 15), Pair(-4, 12), Pair(-8, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(20, -73), Pair(116, -38), Pair(-111, 43), Pair(16, 6), Pair(118, 12), Pair(39, 21), Pair(-85, 45), Pair(44, 8),
        Pair(-23, -5), Pair(19, 19), Pair(27, 16), Pair(34, 31), Pair(66, 17), Pair(-32, 51), Pair(13, 26), Pair(-4, 18),
        Pair(16, 24), Pair(29, 19), Pair(9, 34), Pair(25, 40), Pair(59, 25), Pair(19, 8), Pair(8, 15), Pair(15, 20),
        Pair(-17, 17), Pair(9, 15), Pair(24, 34), Pair(7, 41), Pair(39, 38), Pair(0, 0), Pair(21, 34), Pair(5, 35),
        Pair(-17, 39), Pair(2, 26), Pair(14, 34), Pair(9, 39), Pair(28, 44), Pair(26, 64), Pair(32, 43), Pair(-10, 24),
        Pair(-16, 33), Pair(0, 32), Pair(2, 31), Pair(3, 28), Pair(4, 35), Pair(14, 31), Pair(7, 29), Pair(-1, 20),
        Pair(-6, 13), Pair(-2, 8), Pair(-9, 17), Pair(0, 32), Pair(6, 20), Pair(14, 32), Pair(-3, 19), Pair(3, 21),
        Pair(-113, 4), Pair(-13, 5), Pair(3, 17), Pair(-14, 21), Pair(12, 1), Pair(-2, 27), Pair(0, 21), Pair(-29, -38)
      },
      { // Piece 2
        Pair(-10, -40), Pair(-21, 9), Pair(15, -19), Pair(44, 5), Pair(63, -36), Pair(-38, 36), Pair(118, -39), Pair(40, 1),
        Pair(13, 6), Pair(25, -24), Pair(2, -3), Pair(60, -39), Pair(48, 3), Pair(27, -25), Pair(86, 6), Pair(-38, 0),
        Pair(7, -18), Pair(17, 10), Pair(42, -22), Pair(25, 11), Pair(68, 12), Pair(57, -7), Pair(-55, -4), Pair(20, 35),
        Pair(20, 9), Pair(21, -13), Pair(34, 16), Pair(38, -20), Pair(38, 19), Pair(0, 0), Pair(22, 25), Pair(-3, -1),
        Pair(-5, -5), Pair(17, 14), Pair(20, -15), Pair(38, 20), Pair(3, 0), Pair(35, 47), Pair(1, -19), Pair(27, 32),
        Pair(16, 15), Pair(15, -19), Pair(20, 30), Pair(3, -6), Pair(19, 22), Pair(7, -1), Pair(20, 10), Pair(-13, -36),
        Pair(5, -10), Pair(8, 18), Pair(6, 6), Pair(18, 22), Pair(4, -3), Pair(21, 9), Pair(2, -7), Pair(4, 31),
        Pair(16, 1), Pair(-17, -11), Pair(11, 18), Pair(11, -13), Pair(18, 13), Pair(-10, -14), Pair(9, 1), Pair(9, -19)
      },
      { // Piece 3
        Pair(69, 34), Pair(61, 29), Pair(64, 31), Pair(44, 36), Pair(38, 37), Pair(13, 30), Pair(102, 23), Pair(38, 39),
        Pair(32, 41), Pair(31, 40), Pair(41, 25), Pair(47, 27), Pair(38, 29), Pair(-49, 41), Pair(-7, 41), Pair(1, 38),
        Pair(3, 47), Pair(29, 32), Pair(39, 27), Pair(25, 40), Pair(48, 26), Pair(77, -30), Pair(93, 15), Pair(46, 31),
        Pair(1, 50), Pair(20, 28), Pair(34, 29), Pair(23, 31), Pair(13, 32), Pair(0, 0), Pair(19, 36), Pair(23, 34),
        Pair(4, 32), Pair(13, 32), Pair(12, 27), Pair(29, 30), Pair(32, 35), Pair(30, 13), Pair(14, 36), Pair(22, 40),
        Pair(11, 14), Pair(20, 21), Pair(13, 30), Pair(26, 19), Pair(17, 30), Pair(16, 16), Pair(24, 29), Pair(23, 29),
        Pair(6, 28), Pair(16, 22), Pair(0, 24), Pair(2, 35), Pair(1, 39), Pair(13, -3), Pair(21, 12), Pair(-4, 32),
        Pair(13, 14), Pair(17, 27), Pair(10, 21), Pair(13, 28), Pair(16, 25), Pair(20, 10), Pair(17, 26), Pair(12, 20)
      },
      { // Piece 4
        Pair(114, -34), Pair(-1, 37), Pair(43, -15), Pair(55, 8), Pair(53, 48), Pair(69, -30), Pair(84, 10), Pair(59, -48),
        Pair(3, 38), Pair(-8, 45), Pair(34, 19), Pair(64, -34), Pair(35, 33), Pair(8, -29), Pair(-2, 52), Pair(33, 15),
        Pair(22, 13), Pair(4, 75), Pair(11, 40), Pair(42, 0), Pair(20, 65), Pair(81, -67), Pair(30, 62), Pair(40, 16),
        Pair(27, 3), Pair(6, 37), Pair(22, 17), Pair(8, 51), Pair(17, 36), Pair(0, 0), Pair(21, 40), Pair(28, 11),
        Pair(3, 42), Pair(37, -12), Pair(-2, 71), Pair(12, 49), Pair(11, 31), Pair(3, 44), Pair(17, 33), Pair(52, -2),
        Pair(1, 14), Pair(3, 44), Pair(26, 15), Pair(7, 39), Pair(9, 40), Pair(12, 4), Pair(14, 34), Pair(25, -18),
        Pair(12, 27), Pair(18, -3), Pair(20, 22), Pair(21, 17), Pair(17, 15), Pair(9, -2), Pair(27, 3), Pair(9, 18),
        Pair(22, 35), Pair(19, 3), Pair(10, 29), Pair(17, 29), Pair(15, 22), Pair(20, -29), Pair(51, 2), Pair(44, -48)
      },
      { // Piece 5
        Pair(-29, -4), Pair(-127, 75), Pair(-77, 18), Pair(-28, 20), Pair(-74, 34), Pair(25, 27), Pair(-24, 42), Pair(47, 64),
        Pair(9, 49), Pair(-124, 31), Pair(102, -6), Pair(38, 10), Pair(-52, 79), Pair(83, 49), Pair(-115, 87), Pair(123, 38),
        Pair(146, -23), Pair(50, -1), Pair(21, 12), Pair(-108, 48), Pair(16, 1), Pair(-7, 18), Pair(103, -3), Pair(46, 26),
        Pair(-143, 24), Pair(9, -4), Pair(-43, 24), Pair(60, 11), Pair(47, 22), Pair(0, 0), Pair(28, 14), Pair(60, 17),
        Pair(16, -13), Pair(-26, 4), Pair(-15, 3), Pair(-35, 18), Pair(7, 23), Pair(-39, 33), Pair(10, 7), Pair(21, 13),
        Pair(-81, 5), Pair(-18, 12), Pair(-5, -11), Pair(-19, 5), Pair(-19, 14), Pair(-51, 23), Pair(-8, 4), Pair(16, 4),
        Pair(-20, -11), Pair(-31, -4), Pair(-40, -11), Pair(-41, 1), Pair(-18, -14), Pair(-29, -4), Pair(5, -25), Pair(5, -8),
        Pair(-17, -18), Pair(-11, -21), Pair(-35, -20), Pair(-27, -22), Pair(-16, -31), Pair(-26, -20), Pair(9, -44), Pair(4, -24)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 12), Pair(-14, 21), Pair(-6, 6), Pair(-9, 20), Pair(25, -2), Pair(30, 5), Pair(24, -18), Pair(2, 30),
        Pair(-10, 18), Pair(-2, 10), Pair(-16, 19), Pair(10, 6), Pair(7, 7), Pair(-4, 1), Pair(20, -49), Pair(-10, -12),
        Pair(-3, 8), Pair(3, 12), Pair(4, 8), Pair(11, 12), Pair(-14, 0), Pair(-12, 0), Pair(15, 2), Pair(-13, -4),
        Pair(-5, 13), Pair(2, 10), Pair(1, 8), Pair(-1, 9), Pair(-2, 9), Pair(8, -1), Pair(16, -22), Pair(3, -1),
        Pair(-2, 11), Pair(-2, 13), Pair(2, 9), Pair(-4, 13), Pair(-1, 11), Pair(3, 6), Pair(12, -7), Pair(0, 14),
        Pair(-1, 18), Pair(-1, 16), Pair(4, 9), Pair(4, 16), Pair(-7, 10), Pair(-5, 15), Pair(5, -3), Pair(-10, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(100, -71), Pair(92, -44), Pair(-35, 40), Pair(56, 6), Pair(80, 37), Pair(-160, 73), Pair(18, 14), Pair(-36, -39),
        Pair(24, 4), Pair(-16, 26), Pair(5, 16), Pair(53, 27), Pair(48, 34), Pair(44, -3), Pair(44, 7), Pair(47, -15),
        Pair(0, 29), Pair(-19, 26), Pair(12, 24), Pair(38, 35), Pair(50, 18), Pair(28, 31), Pair(53, -5), Pair(-11, -20),
        Pair(-25, 32), Pair(7, 26), Pair(18, 26), Pair(32, 34), Pair(39, 22), Pair(28, 27), Pair(0, 0), Pair(33, 30),
        Pair(-9, 11), Pair(15, 25), Pair(10, 27), Pair(14, 32), Pair(49, 18), Pair(28, 39), Pair(81, 33), Pair(15, 34),
        Pair(-6, 0), Pair(7, 14), Pair(9, 23), Pair(2, 22), Pair(13, 29), Pair(-1, 36), Pair(28, 20), Pair(-28, 16),
        Pair(-21, 8), Pair(13, 3), Pair(7, 17), Pair(-1, 14), Pair(8, 15), Pair(-1, 10), Pair(-3, 30), Pair(-2, -1),
        Pair(84, -17), Pair(-17, -1), Pair(-13, 7), Pair(-1, 14), Pair(6, 4), Pair(-3, 17), Pair(-14, 0), Pair(-17, -4)
      },
      { // Piece 2
        Pair(-5, 7), Pair(1, -21), Pair(88, -25), Pair(50, -22), Pair(183, -36), Pair(78, -35), Pair(3, -11), Pair(-14, 32),
        Pair(31, -30), Pair(47, -20), Pair(0, -16), Pair(76, -16), Pair(58, -24), Pair(83, -18), Pair(25, -6), Pair(26, 18),
        Pair(4, 9), Pair(20, -27), Pair(58, -10), Pair(20, -5), Pair(48, 14), Pair(63, 10), Pair(47, -19), Pair(7, -15),
        Pair(11, -13), Pair(15, 7), Pair(33, -10), Pair(44, 5), Pair(50, -8), Pair(42, 16), Pair(0, 0), Pair(10, 12),
        Pair(6, 7), Pair(30, -14), Pair(34, 19), Pair(33, -6), Pair(39, 15), Pair(14, 4), Pair(26, 29), Pair(-19, -12),
        Pair(17, 2), Pair(23, -6), Pair(20, 2), Pair(11, 26), Pair(9, -2), Pair(17, 11), Pair(20, -2), Pair(9, 12),
        Pair(12, 5), Pair(10, -3), Pair(5, 25), Pair(1, 0), Pair(3, 12), Pair(-4, -7), Pair(16, 14), Pair(17, -29),
        Pair(25, -20), Pair(18, -2), Pair(-7, -4), Pair(4, 17), Pair(2, -22), Pair(0, -1), Pair(-3, -41), Pair(-1, -15)
      },
      { // Piece 3
        Pair(26, 43), Pair(21, 46), Pair(64, 21), Pair(46, 35), Pair(59, 25), Pair(11, 50), Pair(67, 17), Pair(-13, 45),
        Pair(30, 22), Pair(16, 39), Pair(60, 17), Pair(74, 0), Pair(64, 18), Pair(0, 31), Pair(-7, 28), Pair(-27, 44),
        Pair(7, 34), Pair(34, 16), Pair(11, 30), Pair(40, 15), Pair(54, 12), Pair(28, 39), Pair(45, -22), Pair(7, 33),
        Pair(1, 39), Pair(8, 35), Pair(-19, 38), Pair(30, 22), Pair(15, 38), Pair(12, 37), Pair(0, 0), Pair(-15, 25),
        Pair(-12, 37), Pair(-7, 43), Pair(6, 32), Pair(7, 28), Pair(7, 47), Pair(18, 26), Pair(10, 15), Pair(-8, 40),
        Pair(-1, 21), Pair(7, 27), Pair(3, 22), Pair(6, 31), Pair(10, 19), Pair(5, 27), Pair(9, 9), Pair(5, 24),
        Pair(-17, 24), Pair(2, 21), Pair(0, 30), Pair(-10, 34), Pair(-11, 40), Pair(17, 9), Pair(0, 11), Pair(-32, 53),
        Pair(7, 18), Pair(6, 21), Pair(6, 15), Pair(9, 24), Pair(5, 27), Pair(6, 18), Pair(9, -5), Pair(-2, 22)
      },
      { // Piece 4
        Pair(-3, 21), Pair(-62, 76), Pair(-58, 83), Pair(27, 28), Pair(80, -2), Pair(-35, 58), Pair(75, -122), Pair(58, -41),
        Pair(-19, 11), Pair(8, 19), Pair(-20, 55), Pair(-12, 50), Pair(23, 6), Pair(60, -10), Pair(30, -84), Pair(47, 1),
        Pair(-14, 8), Pair(24, -23), Pair(-4, 26), Pair(11, 32), Pair(42, 45), Pair(74, -8), Pair(43, -64), Pair(50, -19),
        Pair(12, -8), Pair(-11, 27), Pair(7, 34), Pair(26, 2), Pair(36, -2), Pair(30, 0), Pair(0, 0), Pair(21, -34),
        Pair(4, -36), Pair(-11, 36), Pair(1, 20), Pair(22, 14), Pair(0, 40), Pair(8, 37), Pair(5, -14), Pair(6, 11),
        Pair(25, -59), Pair(-13, 18), Pair(2, 27), Pair(13, 0), Pair(0, 0), Pair(9, 9), Pair(-17, 25), Pair(24, -23),
        Pair(-13, 7), Pair(9, 5), Pair(3, -6), Pair(-8, 10), Pair(4, -10), Pair(6, 11), Pair(-2, -14), Pair(16, -7),
        Pair(-9, 20), Pair(-13, 37), Pair(-15, 13), Pair(-12, 7), Pair(-8, -12), Pair(-11, 9), Pair(3, -44), Pair(-1, 16)
      },
      { // Piece 5
        Pair(56, -60), Pair(-87, 26), Pair(-6, 26), Pair(38, 8), Pair(21, 21), Pair(-62, 45), Pair(-16, 46), Pair(57, 15),
        Pair(-45, 1), Pair(-24, 12), Pair(-142, 33), Pair(-3, 6), Pair(61, 19), Pair(45, 51), Pair(57, 63), Pair(44, 63),
        Pair(-32, -7), Pair(-74, 12), Pair(-34, 13), Pair(153, -4), Pair(73, 14), Pair(85, 16), Pair(71, 33), Pair(50, 14),
        Pair(-158, 18), Pair(-40, 19), Pair(-22, 15), Pair(-102, 40), Pair(56, 13), Pair(58, 9), Pair(0, 0), Pair(-49, 39),
        Pair(-120, 13), Pair(-65, 12), Pair(-29, 19), Pair(-70, 23), Pair(1, 21), Pair(5, 2), Pair(39, 7), Pair(-27, 10),
        Pair(-48, 0), Pair(-59, 6), Pair(-37, 15), Pair(-12, -2), Pair(-8, 10), Pair(-5, 4), Pair(15, 4), Pair(-5, 3),
        Pair(-26, -20), Pair(-31, 0), Pair(-49, 10), Pair(-35, 0), Pair(-20, -3), Pair(-7, -12), Pair(16, -11), Pair(2, -15),
        Pair(-34, -2), Pair(-18, -14), Pair(-28, -16), Pair(-31, -9), Pair(-3, -27), Pair(-15, -27), Pair(13, -18), Pair(-2, -38)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(21, 8), Pair(-16, 5), Pair(1, 11), Pair(24, 5), Pair(-11, 10), Pair(-25, 9), Pair(-3, 33), Pair(21, -3),
        Pair(-7, 11), Pair(-12, 22), Pair(9, 14), Pair(7, 9), Pair(13, 2), Pair(-20, 9), Pair(-7, -2), Pair(28, -42),
        Pair(-3, 14), Pair(0, 12), Pair(6, 12), Pair(2, 6), Pair(2, 11), Pair(-19, 0), Pair(-13, -5), Pair(4, -2),
        Pair(-4, 12), Pair(2, 13), Pair(3, 10), Pair(4, 9), Pair(3, 8), Pair(2, 7), Pair(2, -3), Pair(25, -8),
        Pair(-5, 14), Pair(0, 11), Pair(-2, 8), Pair(0, 10), Pair(-1, 7), Pair(4, 1), Pair(3, 11), Pair(17, 6),
        Pair(-3, 13), Pair(-1, 10), Pair(0, 10), Pair(-3, 8), Pair(-1, 10), Pair(0, 8), Pair(0, 15), Pair(15, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, 62), Pair(111, -47), Pair(110, -1), Pair(62, 19), Pair(121, -24), Pair(10, 6), Pair(77, -11), Pair(-131, 51),
        Pair(42, 2), Pair(-19, 23), Pair(28, -6), Pair(61, 12), Pair(52, 2), Pair(45, 10), Pair(11, 13), Pair(-2, 8),
        Pair(-17, 17), Pair(-8, 28), Pair(7, 21), Pair(55, 11), Pair(27, 23), Pair(50, 14), Pair(15, -1), Pair(21, -3),
        Pair(-27, 15), Pair(2, 16), Pair(8, 7), Pair(24, 16), Pair(48, 19), Pair(24, 7), Pair(43, 18), Pair(0, 0),
        Pair(-2, 14), Pair(1, 20), Pair(7, 14), Pair(18, 9), Pair(29, 10), Pair(31, 18), Pair(24, 16), Pair(32, 35),
        Pair(-1, -5), Pair(3, 14), Pair(5, 6), Pair(17, 16), Pair(18, 14), Pair(7, 13), Pair(11, 5), Pair(9, 6),
        Pair(-7, -4), Pair(-15, 13), Pair(-7, 13), Pair(3, 13), Pair(3, 5), Pair(-10, 23), Pair(-3, 22), Pair(-2, 4),
        Pair(-80, 18), Pair(-11, -7), Pair(-26, 1), Pair(4, -5), Pair(0, 0), Pair(0, -18), Pair(1, -7), Pair(8, -21)
      },
      { // Piece 2
        Pair(45, -52), Pair(22, -6), Pair(115, -52), Pair(6, -12), Pair(58, -47), Pair(-22, 16), Pair(106, -46), Pair(4, 5),
        Pair(41, -8), Pair(30, -40), Pair(4, -20), Pair(27, -48), Pair(6, -2), Pair(58, -41), Pair(33, 7), Pair(-5, -20),
        Pair(-5, -30), Pair(-7, 8), Pair(51, -46), Pair(28, -5), Pair(56, -34), Pair(84, -3), Pair(1, -25), Pair(5, 3),
        Pair(9, 16), Pair(12, -26), Pair(25, 6), Pair(57, -32), Pair(42, 6), Pair(39, -19), Pair(16, 8), Pair(0, 0),
        Pair(28, -30), Pair(25, 2), Pair(32, -27), Pair(30, 14), Pair(36, -25), Pair(21, 20), Pair(31, -12), Pair(38, 23),
        Pair(11, 12), Pair(28, -19), Pair(9, 10), Pair(29, -15), Pair(16, 9), Pair(20, -18), Pair(-1, 12), Pair(23, -27),
        Pair(14, -32), Pair(14, 13), Pair(25, -25), Pair(10, 21), Pair(16, -8), Pair(3, 3), Pair(17, -28), Pair(7, -3),
        Pair(18, 16), Pair(62, -26), Pair(6, 9), Pair(18, -22), Pair(2, 1), Pair(11, -36), Pair(2, -16), Pair(46, -63)
      },
      { // Piece 3
        Pair(43, 22), Pair(-5, 36), Pair(82, 4), Pair(9, 23), Pair(53, 8), Pair(109, 0), Pair(27, 19), Pair(37, -13),
        Pair(49, 12), Pair(22, 15), Pair(58, 7), Pair(31, 9), Pair(77, 1), Pair(62, 6), Pair(-16, 25), Pair(-14, 3),
        Pair(6, 23), Pair(22, 22), Pair(29, 19), Pair(19, 7), Pair(48, 7), Pair(43, 12), Pair(22, 18), Pair(2, -26),
        Pair(8, 23), Pair(4, 25), Pair(13, 14), Pair(26, 9), Pair(19, 14), Pair(30, 13), Pair(19, 9), Pair(0, 0),
        Pair(13, 16), Pair(3, 17), Pair(25, -2), Pair(2, 18), Pair(-7, 25), Pair(27, 19), Pair(4, 21), Pair(-40, 6),
        Pair(-11, 9), Pair(-12, 22), Pair(-9, 18), Pair(-6, 9), Pair(11, 8), Pair(-1, 10), Pair(-6, 12), Pair(-43, -10),
        Pair(-12, 8), Pair(-11, 19), Pair(12, 12), Pair(-8, 23), Pair(-3, 23), Pair(0, 12), Pair(-20, 8), Pair(-66, 21),
        Pair(6, 8), Pair(0, 11), Pair(5, 12), Pair(8, 4), Pair(9, -1), Pair(5, 5), Pair(-13, 17), Pair(-21, -17)
      },
      { // Piece 4
        Pair(51, -6), Pair(-1, 11), Pair(51, -36), Pair(15, -19), Pair(93, -27), Pair(-4, 23), Pair(-59, 57), Pair(86, -95),
        Pair(15, -28), Pair(-12, 21), Pair(1, 11), Pair(3, 12), Pair(21, -23), Pair(23, -1), Pair(70, -118), Pair(-13, -10),
        Pair(-3, 4), Pair(-14, 18), Pair(2, 3), Pair(41, -45), Pair(49, -26), Pair(58, -15), Pair(33, 41), Pair(20, -81),
        Pair(0, -12), Pair(8, -18), Pair(12, -14), Pair(-6, 12), Pair(4, 22), Pair(23, -11), Pair(32, -42), Pair(0, 0),
        Pair(1, -10), Pair(-7, 9), Pair(0, 5), Pair(18, -28), Pair(10, 10), Pair(13, 13), Pair(9, -12), Pair(6, -37),
        Pair(34, -60), Pair(7, -32), Pair(-2, 3), Pair(8, 4), Pair(-1, -12), Pair(9, -3), Pair(19, -29), Pair(-19, -9),
        Pair(-1, -17), Pair(8, -18), Pair(8, 13), Pair(2, -2), Pair(2, -7), Pair(-3, -12), Pair(20, -46), Pair(-17, -16),
        Pair(5, -18), Pair(7, 6), Pair(0, -3), Pair(-6, 4), Pair(0, 6), Pair(12, -38), Pair(15, -52), Pair(-16, 24)
      },
      { // Piece 5
        Pair(20, -9), Pair(54, -21), Pair(-60, -6), Pair(25, -10), Pair(100, -13), Pair(-74, 58), Pair(-31, 61), Pair(33, 26),
        Pair(73, -68), Pair(-18, -23), Pair(-19, 9), Pair(-12, 21), Pair(-41, 5), Pair(-4, 15), Pair(-83, 94), Pair(-107, 38),
        Pair(8, 8), Pair(19, 3), Pair(24, -16), Pair(11, 22), Pair(118, 8), Pair(72, 37), Pair(38, 16), Pair(-55, -15),
        Pair(-34, 10), Pair(-69, 10), Pair(-105, 36), Pair(-54, 26), Pair(-1, 24), Pair(76, 6), Pair(-4, -1), Pair(0, 0),
        Pair(-71, 17), Pair(-109, 18), Pair(-48, 17), Pair(-58, 20), Pair(-13, 18), Pair(50, 11), Pair(-14, -4), Pair(12, -30),
        Pair(-106, 2), Pair(-41, 15), Pair(-30, -2), Pair(-31, 16), Pair(-18, 5), Pair(18, -1), Pair(11, 1), Pair(-4, -11),
        Pair(-45, 5), Pair(-51, 12), Pair(-59, 13), Pair(-47, 8), Pair(-18, 1), Pair(-20, 6), Pair(12, 0), Pair(12, -23),
        Pair(-41, 4), Pair(-41, 7), Pair(-33, -8), Pair(-34, -7), Pair(-20, -10), Pair(-12, -3), Pair(9, -11), Pair(4, -20)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-31, 18), Pair(9, 20), Pair(1, 20), Pair(4, 11), Pair(-4, 14), Pair(-7, 15), Pair(-2, 3), Pair(12, 8),
        Pair(6, 6), Pair(-4, 20), Pair(1, 16), Pair(-6, 13), Pair(2, 12), Pair(-2, 9), Pair(-8, 8), Pair(-2, 10),
        Pair(-7, -4), Pair(-1, 6), Pair(-2, 7), Pair(-3, 8), Pair(1, 10), Pair(1, 8), Pair(-5, 14), Pair(-4, 13),
        Pair(0, 12), Pair(-6, -1), Pair(0, 7), Pair(-3, 10), Pair(1, 13), Pair(1, 10), Pair(-2, 16), Pair(-7, 14),
        Pair(1, 6), Pair(-2, 3), Pair(2, 9), Pair(-2, 11), Pair(-3, 9), Pair(0, 12), Pair(-4, 14), Pair(-2, 19),
        Pair(7, 9), Pair(-4, 12), Pair(-4, 7), Pair(1, 5), Pair(-5, 10), Pair(-2, 17), Pair(-6, 16), Pair(-3, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(1, 4), Pair(-34, 48), Pair(-13, 55), Pair(-58, 55), Pair(-52, 42), Pair(-67, 54), Pair(-1, 28), Pair(-1, 55),
        Pair(-7, 25), Pair(-13, 41), Pair(-26, 46), Pair(-18, 54), Pair(20, 27), Pair(-17, 59), Pair(-37, 40), Pair(-18, 50),
        Pair(-29, 29), Pair(7, 40), Pair(6, 53), Pair(-3, 57), Pair(-4, 43), Pair(-13, 50), Pair(-8, 47), Pair(-16, 64),
        Pair(-21, 27), Pair(2, 36), Pair(3, 50), Pair(-6, 62), Pair(-5, 58), Pair(1, 45), Pair(-12, 47), Pair(-8, 51),
        Pair(0, 0), Pair(-6, 44), Pair(-1, 50), Pair(-3, 50), Pair(3, 53), Pair(1, 54), Pair(-7, 56), Pair(-4, 42),
        Pair(-8, 58), Pair(-4, 47), Pair(-3, 38), Pair(-5, 49), Pair(-4, 57), Pair(-2, 47), Pair(-9, 42), Pair(-9, 40),
        Pair(-14, 38), Pair(0, 35), Pair(-8, 45), Pair(-8, 45), Pair(-7, 46), Pair(-11, 53), Pair(-7, 50), Pair(-12, 59),
        Pair(65, -2), Pair(-15, 30), Pair(-11, 33), Pair(-19, 44), Pair(-11, 46), Pair(-8, 35), Pair(-11, 35), Pair(-17, -14)
      },
      { // Piece 2
        Pair(-12, 39), Pair(51, 21), Pair(23, 8), Pair(-5, 37), Pair(-8, 11), Pair(-17, 35), Pair(-26, 33), Pair(-23, 51),
        Pair(-28, 67), Pair(6, 28), Pair(-6, 42), Pair(59, 4), Pair(16, 14), Pair(0, 5), Pair(4, 26), Pair(-8, 21),
        Pair(-3, 34), Pair(26, 34), Pair(39, 15), Pair(7, 33), Pair(9, 19), Pair(-5, 35), Pair(3, 15), Pair(-16, 51),
        Pair(-14, 33), Pair(11, 38), Pair(6, 34), Pair(5, 29), Pair(-6, 46), Pair(4, 24), Pair(1, 35), Pair(-7, 30),
        Pair(0, 0), Pair(11, 29), Pair(8, 32), Pair(-4, 44), Pair(-1, 36), Pair(0, 43), Pair(9, 31), Pair(-11, 42),
        Pair(8, 50), Pair(11, 25), Pair(2, 47), Pair(0, 35), Pair(-6, 55), Pair(0, 42), Pair(8, 44), Pair(4, 48),
        Pair(6, -4), Pair(-4, 35), Pair(3, 24), Pair(-5, 48), Pair(-1, 44), Pair(-1, 56), Pair(1, 41), Pair(2, 40),
        Pair(-9, 31), Pair(5, 8), Pair(-9, 39), Pair(1, 38), Pair(0, 50), Pair(1, 38), Pair(-10, 62), Pair(3, 32)
      },
      { // Piece 3
        Pair(-66, 64), Pair(-28, 88), Pair(-17, 84), Pair(-20, 82), Pair(-31, 79), Pair(-4, 76), Pair(-47, 80), Pair(-9, 72),
        Pair(-43, 53), Pair(-22, 79), Pair(-10, 70), Pair(-25, 84), Pair(-5, 75), Pair(-26, 77), Pair(-27, 89), Pair(-6, 65),
        Pair(-45, 61), Pair(-2, 68), Pair(6, 74), Pair(-13, 80), Pair(-6, 66), Pair(-42, 84), Pair(-21, 73), Pair(-22, 80),
        Pair(-50, 48), Pair(-7, 84), Pair(3, 75), Pair(4, 73), Pair(-4, 72), Pair(-11, 80), Pair(-11, 73), Pair(9, 66),
        Pair(0, 0), Pair(-2, 82), Pair(-4, 75), Pair(-7, 79), Pair(-9, 80), Pair(-3, 78), Pair(-22, 83), Pair(-11, 74),
        Pair(-30, 32), Pair(-18, 82), Pair(-1, 65), Pair(-8, 75), Pair(-11, 78), Pair(-15, 67), Pair(-16, 74), Pair(-15, 58),
        Pair(-61, 61), Pair(-11, 76), Pair(-5, 67), Pair(-10, 68), Pair(-5, 67), Pair(-13, 67), Pair(-22, 64), Pair(10, 65),
        Pair(-31, 40), Pair(-16, 75), Pair(-12, 73), Pair(-9, 70), Pair(-13, 71), Pair(-12, 67), Pair(-19, 70), Pair(-5, 56)
      },
      { // Piece 4
        Pair(-13, 142), Pair(12, 119), Pair(22, 89), Pair(4, 118), Pair(-22, 136), Pair(-20, 138), Pair(-49, 154), Pair(26, 105),
        Pair(-11, 107), Pair(-3, 116), Pair(7, 95), Pair(20, 109), Pair(14, 84), Pair(3, 123), Pair(24, 112), Pair(15, 124),
        Pair(-4, 121), Pair(3, 115), Pair(10, 117), Pair(12, 124), Pair(-2, 117), Pair(5, 128), Pair(19, 97), Pair(4, 113),
        Pair(9, 66), Pair(0, 159), Pair(1, 127), Pair(5, 123), Pair(9, 119), Pair(13, 107), Pair(10, 113), Pair(6, 103),
        Pair(0, 0), Pair(12, 125), Pair(15, 125), Pair(13, 128), Pair(9, 132), Pair(15, 117), Pair(11, 107), Pair(22, 94),
        Pair(1, 115), Pair(14, 125), Pair(10, 124), Pair(16, 125), Pair(24, 119), Pair(15, 129), Pair(18, 106), Pair(34, 70),
        Pair(6, 90), Pair(16, 106), Pair(13, 116), Pair(12, 120), Pair(17, 136), Pair(17, 115), Pair(25, 109), Pair(28, 64),
        Pair(5, 93), Pair(11, 102), Pair(15, 113), Pair(15, 114), Pair(20, 116), Pair(26, 94), Pair(-6, 145), Pair(5, 103)
      },
      { // Piece 5
        Pair(13, 71), Pair(-27, 130), Pair(-28, 35), Pair(-5, 12), Pair(-104, -4), Pair(22, 25), Pair(-110, 10), Pair(-34, -2),
        Pair(-14, 34), Pair(119, 61), Pair(11, 54), Pair(17, 39), Pair(2, 24), Pair(104, -13), Pair(54, 3), Pair(19, -31),
        Pair(-51, 26), Pair(-92, 85), Pair(99, 28), Pair(-130, 71), Pair(15, 23), Pair(-79, 34), Pair(34, 0), Pair(-56, 6),
        Pair(27, 15), Pair(-20, 35), Pair(-21, 63), Pair(-11, 36), Pair(-18, 25), Pair(-10, 18), Pair(-62, 12), Pair(-94, 8),
        Pair(0, 0), Pair(24, 30), Pair(7, 34), Pair(-57, 40), Pair(-51, 34), Pair(-28, 17), Pair(-27, 10), Pair(-63, 0),
        Pair(-12, -15), Pair(11, 4), Pair(-6, 26), Pair(-15, 22), Pair(-15, 16), Pair(-25, 15), Pair(-21, 4), Pair(-49, 6),
        Pair(32, -27), Pair(57, 1), Pair(3, 7), Pair(-14, 14), Pair(-5, 10), Pair(-20, 9), Pair(-14, 1), Pair(-10, -11),
        Pair(13, -27), Pair(104, -12), Pair(38, -10), Pair(-15, 8), Pair(-5, -7), Pair(-20, -1), Pair(-6, -13), Pair(-7, -20)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 26), Pair(-23, 0), Pair(3, 21), Pair(2, 14), Pair(21, 4), Pair(50, -5), Pair(-9, 7), Pair(-3, 10),
        Pair(0, 18), Pair(3, 7), Pair(-1, 23), Pair(2, 12), Pair(10, 11), Pair(6, 9), Pair(-2, 9), Pair(5, 13),
        Pair(-3, 4), Pair(0, -11), Pair(11, 9), Pair(6, 6), Pair(6, 8), Pair(7, 11), Pair(1, 9), Pair(2, 11),
        Pair(-4, 1), Pair(-4, 19), Pair(-1, 5), Pair(-4, 9), Pair(0, 14), Pair(3, 11), Pair(1, 14), Pair(4, 16),
        Pair(8, 8), Pair(-3, 2), Pair(7, 13), Pair(-2, 13), Pair(0, 14), Pair(4, 12), Pair(3, 17), Pair(-1, 16),
        Pair(-1, 14), Pair(-2, 6), Pair(1, 21), Pair(1, 14), Pair(-3, 14), Pair(-1, 19), Pair(2, 17), Pair(1, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-77, 87), Pair(80, -13), Pair(47, 36), Pair(-27, 37), Pair(-7, 52), Pair(-87, 37), Pair(-38, 32), Pair(-42, 60),
        Pair(4, 41), Pair(1, 44), Pair(4, 59), Pair(-5, 51), Pair(-7, 51), Pair(4, 43), Pair(-6, 55), Pair(-31, 64),
        Pair(-27, 46), Pair(-5, 56), Pair(25, 51), Pair(-2, 59), Pair(11, 49), Pair(11, 61), Pair(-4, 41), Pair(3, 52),
        Pair(7, 31), Pair(-6, 32), Pair(18, 50), Pair(5, 59), Pair(9, 57), Pair(16, 53), Pair(2, 68), Pair(8, 53),
        Pair(7, 48), Pair(0, 0), Pair(15, 54), Pair(15, 56), Pair(9, 54), Pair(17, 58), Pair(1, 51), Pair(15, 44),
        Pair(1, 46), Pair(16, 68), Pair(10, 52), Pair(11, 59), Pair(17, 52), Pair(11, 50), Pair(8, 44), Pair(6, 25),
        Pair(-14, 38), Pair(14, 52), Pair(11, 57), Pair(9, 47), Pair(9, 56), Pair(13, 48), Pair(17, 47), Pair(11, 39),
        Pair(-6, 53), Pair(-6, 31), Pair(4, 34), Pair(6, 56), Pair(-5, 50), Pair(10, 50), Pair(-3, 43), Pair(9, -1)
      },
      { // Piece 2
        Pair(51, 12), Pair(22, 23), Pair(-12, 39), Pair(30, 7), Pair(7, 30), Pair(88, -10), Pair(-16, 34), Pair(-8, 11),
        Pair(14, 33), Pair(13, 44), Pair(11, 19), Pair(37, 24), Pair(52, 3), Pair(11, 35), Pair(3, 24), Pair(2, 29),
        Pair(10, 45), Pair(10, 26), Pair(33, 42), Pair(9, 23), Pair(31, 17), Pair(33, 7), Pair(36, 26), Pair(2, 31),
        Pair(3, -13), Pair(14, 29), Pair(57, 2), Pair(19, 44), Pair(16, 23), Pair(23, 37), Pair(14, 16), Pair(8, 48),
        Pair(21, 40), Pair(0, 0), Pair(25, 39), Pair(17, 25), Pair(25, 45), Pair(14, 34), Pair(20, 46), Pair(5, 40),
        Pair(-9, -11), Pair(19, 56), Pair(10, 29), Pair(11, 52), Pair(9, 34), Pair(13, 50), Pair(17, 34), Pair(14, 42),
        Pair(3, 53), Pair(7, 36), Pair(12, 41), Pair(0, 36), Pair(15, 50), Pair(16, 40), Pair(15, 55), Pair(10, 42),
        Pair(1, 8), Pair(11, 35), Pair(1, 24), Pair(15, 36), Pair(0, 37), Pair(6, 57), Pair(26, 12), Pair(26, 25)
      },
      { // Piece 3
        Pair(-11, 78), Pair(-6, 56), Pair(-15, 80), Pair(4, 72), Pair(-6, 74), Pair(-37, 83), Pair(-43, 89), Pair(19, 66),
        Pair(-12, 81), Pair(-32, 63), Pair(0, 73), Pair(-5, 78), Pair(13, 74), Pair(0, 72), Pair(-9, 83), Pair(8, 64),
        Pair(-2, 78), Pair(-8, 68), Pair(-6, 79), Pair(7, 78), Pair(13, 76), Pair(-14, 91), Pair(-9, 93), Pair(-10, 90),
        Pair(1, 92), Pair(-37, 47), Pair(12, 80), Pair(13, 77), Pair(20, 69), Pair(15, 64), Pair(9, 68), Pair(11, 84),
        Pair(-1, 58), Pair(0, 0), Pair(5, 81), Pair(13, 76), Pair(17, 75), Pair(13, 74), Pair(-17, 73), Pair(3, 72),
        Pair(9, 69), Pair(-13, 57), Pair(16, 77), Pair(14, 84), Pair(9, 74), Pair(-9, 78), Pair(0, 72), Pair(12, 55),
        Pair(5, 71), Pair(-17, 51), Pair(10, 67), Pair(16, 68), Pair(10, 61), Pair(-2, 72), Pair(-5, 77), Pair(-4, 66),
        Pair(-1, 72), Pair(-11, 47), Pair(3, 77), Pair(6, 68), Pair(6, 72), Pair(1, 73), Pair(4, 63), Pair(3, 64)
      },
      { // Piece 4
        Pair(8, 85), Pair(-35, 118), Pair(1, 85), Pair(-42, 124), Pair(1, 97), Pair(-22, 143), Pair(12, 88), Pair(-17, 102),
        Pair(4, 91), Pair(-6, 85), Pair(27, 69), Pair(24, 90), Pair(15, 95), Pair(25, 86), Pair(4, 63), Pair(-2, 99),
        Pair(6, 102), Pair(19, 58), Pair(12, 80), Pair(8, 79), Pair(12, 97), Pair(21, 71), Pair(16, 74), Pair(-3, 109),
        Pair(-12, 116), Pair(4, 64), Pair(-8, 117), Pair(4, 113), Pair(20, 91), Pair(-7, 102), Pair(16, 90), Pair(2, 87),
        Pair(7, 66), Pair(0, 0), Pair(13, 104), Pair(19, 102), Pair(10, 107), Pair(5, 119), Pair(12, 96), Pair(17, 92),
        Pair(2, 75), Pair(17, 68), Pair(18, 107), Pair(15, 99), Pair(13, 116), Pair(11, 119), Pair(11, 91), Pair(9, 89),
        Pair(14, 95), Pair(10, 91), Pair(17, 92), Pair(14, 105), Pair(12, 107), Pair(16, 116), Pair(14, 80), Pair(23, 55),
        Pair(1, 102), Pair(8, 65), Pair(10, 102), Pair(12, 95), Pair(11, 98), Pair(5, 98), Pair(-4, 112), Pair(4, 119)
      },
      { // Piece 5
        Pair(-3, 115), Pair(-48, 43), Pair(-22, 158), Pair(118, 26), Pair(31, 24), Pair(-13, 15), Pair(-42, -24), Pair(44, -10),
        Pair(-58, 113), Pair(-51, 74), Pair(3, 83), Pair(73, 46), Pair(66, 16), Pair(113, 2), Pair(12, 12), Pair(61, -49),
        Pair(23, 88), Pair(95, 47), Pair(176, 46), Pair(21, 58), Pair(67, 34), Pair(3, 25), Pair(-38, 29), Pair(-32, -8),
        Pair(72, 31), Pair(57, 16), Pair(44, 31), Pair(-24, 54), Pair(2, 31), Pair(-19, 29), Pair(8, 5), Pair(-62, 7),
        Pair(-61, 81), Pair(0, 0), Pair(10, 49), Pair(-38, 48), Pair(-9, 27), Pair(-41, 24), Pair(-23, 11), Pair(-83, 7),
        Pair(34, 22), Pair(38, 4), Pair(-1, 28), Pair(-1, 28), Pair(-6, 15), Pair(-8, 8), Pair(-32, 10), Pair(-51, 2),
        Pair(73, 18), Pair(40, 4), Pair(31, 15), Pair(14, 13), Pair(8, 10), Pair(-15, 11), Pair(-16, 2), Pair(-11, -7),
        Pair(61, -13), Pair(51, -14), Pair(31, 5), Pair(-3, 6), Pair(-6, 3), Pair(-4, 3), Pair(-5, -5), Pair(-15, -23)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, 14), Pair(5, 19), Pair(-26, 7), Pair(-5, 14), Pair(-13, 11), Pair(20, 6), Pair(4, 7), Pair(-14, 20),
        Pair(-2, 11), Pair(-8, 19), Pair(-4, 2), Pair(-9, 15), Pair(14, 8), Pair(2, 10), Pair(4, 10), Pair(2, 11),
        Pair(1, 10), Pair(0, 6), Pair(-4, -23), Pair(0, 12), Pair(3, 9), Pair(8, 7), Pair(1, 8), Pair(1, 8),
        Pair(-2, 8), Pair(-2, 4), Pair(9, 0), Pair(-5, 17), Pair(-3, 6), Pair(5, 8), Pair(2, 11), Pair(0, 14),
        Pair(1, 9), Pair(6, 11), Pair(-7, -11), Pair(2, 15), Pair(-1, 8), Pair(3, 6), Pair(0, 11), Pair(0, 9),
        Pair(2, 11), Pair(1, 12), Pair(2, -5), Pair(2, 13), Pair(0, 15), Pair(0, 14), Pair(0, 11), Pair(1, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-38, 81), Pair(6, 78), Pair(3, 45), Pair(49, 42), Pair(-47, 33), Pair(-102, 66), Pair(-42, 32), Pair(-18, 24),
        Pair(-18, 46), Pair(0, 51), Pair(-16, 46), Pair(-13, 43), Pair(-29, 72), Pair(-7, 61), Pair(-34, 79), Pair(-6, 47),
        Pair(-32, 53), Pair(-16, 41), Pair(-27, 57), Pair(1, 40), Pair(-5, 52), Pair(-12, 55), Pair(-9, 51), Pair(-22, 38),
        Pair(-36, 41), Pair(-12, 43), Pair(-16, 35), Pair(12, 50), Pair(-13, 60), Pair(-10, 55), Pair(-15, 56), Pair(-6, 48),
        Pair(-8, 55), Pair(-7, 47), Pair(0, 0), Pair(-5, 56), Pair(-4, 53), Pair(-1, 56), Pair(-8, 53), Pair(-13, 60),
        Pair(-13, 12), Pair(3, 47), Pair(4, 71), Pair(3, 59), Pair(2, 48), Pair(-4, 49), Pair(-3, 50), Pair(6, 42),
        Pair(-21, 43), Pair(-8, 39), Pair(1, 38), Pair(-10, 45), Pair(-3, 48), Pair(0, 53), Pair(-5, 48), Pair(-7, 62),
        Pair(25, 43), Pair(-8, 33), Pair(-5, 38), Pair(-9, 51), Pair(-6, 47), Pair(-4, 50), Pair(-7, 32), Pair(2, 24)
      },
      { // Piece 2
        Pair(-5, 10), Pair(-1, 34), Pair(36, 0), Pair(19, 10), Pair(42, -18), Pair(-6, 27), Pair(-43, -6), Pair(30, -1),
        Pair(-3, 36), Pair(13, 22), Pair(-3, 36), Pair(45, -8), Pair(11, 18), Pair(31, -22), Pair(-20, 40), Pair(1, 8),
        Pair(-31, 11), Pair(7, 32), Pair(4, 9), Pair(14, 35), Pair(3, 4), Pair(-5, 28), Pair(11, -1), Pair(-7, 32),
        Pair(-3, 47), Pair(-27, 5), Pair(-4, 27), Pair(34, -9), Pair(-5, 36), Pair(-2, 14), Pair(-1, 41), Pair(-9, 23),
        Pair(3, -1), Pair(3, 26), Pair(0, 0), Pair(4, 30), Pair(-2, 19), Pair(5, 34), Pair(0, 16), Pair(-4, 37),
        Pair(-9, 46), Pair(-23, -8), Pair(9, 56), Pair(-11, 15), Pair(-1, 45), Pair(-1, 23), Pair(-1, 47), Pair(-14, 27),
        Pair(-34, -15), Pair(-3, 45), Pair(-2, 15), Pair(-4, 45), Pair(-8, 17), Pair(0, 49), Pair(-8, 37), Pair(2, 46),
        Pair(0, 36), Pair(-7, 12), Pair(-2, 33), Pair(-8, 18), Pair(0, 43), Pair(-14, 15), Pair(9, 28), Pair(3, 16)
      },
      { // Piece 3
        Pair(-12, 64), Pair(-19, 71), Pair(3, 42), Pair(-38, 73), Pair(-34, 64), Pair(24, 54), Pair(-18, 64), Pair(-40, 66),
        Pair(-12, 67), Pair(-14, 66), Pair(-19, 44), Pair(-13, 70), Pair(-8, 67), Pair(-43, 91), Pair(-26, 66), Pair(-16, 67),
        Pair(-19, 66), Pair(-10, 63), Pair(-16, 52), Pair(-19, 65), Pair(-13, 63), Pair(-17, 69), Pair(-2, 62), Pair(-19, 70),
        Pair(-6, 64), Pair(-1, 61), Pair(-20, 36), Pair(-8, 72), Pair(-1, 55), Pair(-7, 69), Pair(-14, 65), Pair(-4, 61),
        Pair(-6, 48), Pair(-14, 59), Pair(0, 0), Pair(-6, 62), Pair(-3, 60), Pair(-5, 65), Pair(-4, 59), Pair(-14, 64),
        Pair(-7, 70), Pair(5, 49), Pair(-10, 28), Pair(0, 62), Pair(-7, 60), Pair(-14, 62), Pair(-17, 65), Pair(-10, 55),
        Pair(-8, 58), Pair(-13, 66), Pair(-14, 29), Pair(-8, 65), Pair(0, 53), Pair(-8, 65), Pair(-11, 53), Pair(-12, 66),
        Pair(-9, 59), Pair(-8, 64), Pair(-11, 30), Pair(-10, 62), Pair(-7, 62), Pair(-6, 57), Pair(-2, 53), Pair(-8, 57)
      },
      { // Piece 4
        Pair(17, 67), Pair(-8, 111), Pair(-5, 66), Pair(20, 65), Pair(-7, 94), Pair(21, 79), Pair(51, 53), Pair(-5, 111),
        Pair(-3, 83), Pair(1, 82), Pair(-10, 81), Pair(1, 91), Pair(12, 66), Pair(31, 40), Pair(19, 67), Pair(14, 65),
        Pair(0, 55), Pair(-1, 81), Pair(1, 59), Pair(2, 76), Pair(-10, 82), Pair(-11, 89), Pair(8, 76), Pair(-12, 74),
        Pair(-6, 91), Pair(-2, 88), Pair(-9, 55), Pair(3, 100), Pair(1, 106), Pair(1, 91), Pair(0, 93), Pair(7, 76),
        Pair(5, 61), Pair(4, 61), Pair(0, 0), Pair(-5, 94), Pair(6, 91), Pair(0, 92), Pair(13, 73), Pair(2, 77),
        Pair(11, 66), Pair(12, 68), Pair(2, 86), Pair(6, 78), Pair(11, 83), Pair(9, 92), Pair(4, 78), Pair(11, 87),
        Pair(3, 64), Pair(4, 85), Pair(8, 67), Pair(9, 83), Pair(10, 88), Pair(6, 87), Pair(16, 71), Pair(-3, 100),
        Pair(9, 78), Pair(7, 73), Pair(7, 63), Pair(7, 90), Pair(11, 76), Pair(14, 71), Pair(18, 75), Pair(12, 80)
      },
      { // Piece 5
        Pair(3, 54), Pair(-28, 104), Pair(32, 51), Pair(93, 101), Pair(94, -9), Pair(-61, 19), Pair(-16, 4), Pair(-8, 22),
        Pair(37, 60), Pair(108, 65), Pair(46, 71), Pair(69, 62), Pair(163, 9), Pair(-31, 46), Pair(12, 10), Pair(-124, 43),
        Pair(6, 60), Pair(48, 65), Pair(140, 45), Pair(38, 57), Pair(80, 34), Pair(77, 20), Pair(-2, 13), Pair(-63, 17),
        Pair(157, 51), Pair(40, 23), Pair(58, 18), Pair(30, 22), Pair(-9, 34), Pair(-20, 25), Pair(-14, 13), Pair(-60, 8),
        Pair(-54, 70), Pair(63, 31), Pair(0, 0), Pair(28, 34), Pair(-16, 29), Pair(-13, 17), Pair(1, 4), Pair(-37, -7),
        Pair(64, 14), Pair(-27, 33), Pair(2, 23), Pair(-18, 20), Pair(4, 10), Pair(-19, 2), Pair(-24, 3), Pair(-26, -6),
        Pair(36, 1), Pair(-1, 15), Pair(-7, 8), Pair(-12, 23), Pair(7, 3), Pair(-8, 2), Pair(-3, -6), Pair(-7, -12),
        Pair(37, -20), Pair(11, -18), Pair(17, -25), Pair(5, -20), Pair(6, -5), Pair(-3, -7), Pair(-4, -13), Pair(-7, -16)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 16), Pair(-11, 14), Pair(-20, 20), Pair(13, -19), Pair(1, 19), Pair(-3, 7), Pair(3, 8), Pair(-3, 4),
        Pair(-7, 10), Pair(2, 10), Pair(-13, 21), Pair(4, 7), Pair(-6, 23), Pair(9, 15), Pair(-7, 15), Pair(-1, 15),
        Pair(0, 11), Pair(2, 7), Pair(9, 13), Pair(0, -2), Pair(11, 8), Pair(4, 6), Pair(2, 9), Pair(1, 8),
        Pair(1, 12), Pair(-2, 12), Pair(-5, 15), Pair(4, -16), Pair(-3, 20), Pair(-1, 3), Pair(5, 10), Pair(0, 10),
        Pair(1, 12), Pair(1, 6), Pair(11, 17), Pair(5, -6), Pair(5, 19), Pair(-1, 10), Pair(1, 12), Pair(1, 11),
        Pair(0, 10), Pair(2, 13), Pair(1, 18), Pair(11, -1), Pair(3, 18), Pair(1, 14), Pair(0, 15), Pair(2, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-20, 34), Pair(-84, 63), Pair(13, 46), Pair(-25, 49), Pair(-45, 59), Pair(-58, 65), Pair(-13, 61), Pair(-57, 104),
        Pair(13, 43), Pair(-8, 54), Pair(-19, 49), Pair(-23, 85), Pair(32, 32), Pair(-17, 54), Pair(10, 45), Pair(-21, 28),
        Pair(10, 53), Pair(-6, 57), Pair(4, 41), Pair(-18, 57), Pair(2, 48), Pair(-12, 53), Pair(-1, 50), Pair(-6, 49),
        Pair(-4, 43), Pair(-9, 45), Pair(9, 55), Pair(-17, 43), Pair(1, 61), Pair(-10, 55), Pair(-13, 60), Pair(-14, 59),
        Pair(7, 56), Pair(12, 46), Pair(0, 52), Pair(0, 0), Pair(-12, 64), Pair(-5, 57), Pair(-10, 65), Pair(0, 43),
        Pair(-4, 48), Pair(-4, 39), Pair(1, 55), Pair(17, 75), Pair(4, 60), Pair(1, 40), Pair(0, 45), Pair(2, 44),
        Pair(-3, 51), Pair(7, 32), Pair(2, 48), Pair(4, 47), Pair(-2, 41), Pair(4, 50), Pair(9, 46), Pair(4, 38),
        Pair(-19, 46), Pair(0, 39), Pair(5, 56), Pair(9, 43), Pair(5, 45), Pair(-3, 48), Pair(6, 37), Pair(13, 46)
      },
      { // Piece 2
        Pair(36, 17), Pair(38, -6), Pair(-3, 28), Pair(-15, -3), Pair(40, 9), Pair(8, -4), Pair(-3, 18), Pair(7, -12),
        Pair(-61, 14), Pair(13, 41), Pair(3, 5), Pair(39, 12), Pair(-12, 6), Pair(11, 15), Pair(26, -27), Pair(13, 19),
        Pair(6, 35), Pair(-8, 2), Pair(9, 34), Pair(-7, 6), Pair(27, 24), Pair(-6, -15), Pair(29, 15), Pair(-16, 23),
        Pair(-19, 16), Pair(13, 29), Pair(19, -14), Pair(-7, 14), Pair(-14, 8), Pair(6, 34), Pair(-8, 14), Pair(3, 37),
        Pair(14, 26), Pair(-5, 6), Pair(8, 38), Pair(0, 0), Pair(2, 36), Pair(-6, 23), Pair(11, 36), Pair(-1, 8),
        Pair(-12, 15), Pair(7, 40), Pair(-28, -11), Pair(11, 54), Pair(-14, 11), Pair(7, 39), Pair(-5, 17), Pair(-1, 51),
        Pair(10, 38), Pair(-34, -22), Pair(3, 35), Pair(-7, 17), Pair(7, 41), Pair(-12, 3), Pair(-1, 48), Pair(-8, 23),
        Pair(-46, -39), Pair(12, 15), Pair(-13, 11), Pair(9, 41), Pair(-11, 10), Pair(1, 43), Pair(-23, 20), Pair(-1, 33)
      },
      { // Piece 3
        Pair(-4, 62), Pair(0, 65), Pair(-19, 64), Pair(-27, 62), Pair(-31, 71), Pair(6, 62), Pair(18, 58), Pair(24, 47),
        Pair(-7, 71), Pair(-11, 67), Pair(-15, 70), Pair(-11, 62), Pair(-15, 65), Pair(0, 57), Pair(-10, 63), Pair(-12, 55),
        Pair(-6, 71), Pair(6, 59), Pair(-7, 70), Pair(-1, 44), Pair(-19, 60), Pair(-3, 63), Pair(-12, 64), Pair(3, 50),
        Pair(6, 61), Pair(7, 65), Pair(3, 58), Pair(-6, 32), Pair(0, 65), Pair(-10, 67), Pair(-22, 56), Pair(4, 59),
        Pair(1, 52), Pair(-2, 56), Pair(-7, 47), Pair(0, 0), Pair(-7, 50), Pair(-11, 55), Pair(-17, 61), Pair(-3, 43),
        Pair(11, 48), Pair(0, 60), Pair(3, 53), Pair(6, 28), Pair(3, 59), Pair(-3, 51), Pair(-3, 50), Pair(-8, 53),
        Pair(11, 52), Pair(3, 54), Pair(-4, 52), Pair(-10, 41), Pair(-4, 51), Pair(0, 55), Pair(-1, 41), Pair(4, 43),
        Pair(0, 55), Pair(-1, 58), Pair(-3, 60), Pair(4, 23), Pair(-2, 56), Pair(-6, 53), Pair(0, 56), Pair(5, 50)
      },
      { // Piece 4
        Pair(-6, 95), Pair(-7, 90), Pair(17, 81), Pair(49, 34), Pair(20, 69), Pair(24, 80), Pair(-6, 148), Pair(45, 43),
        Pair(-2, 66), Pair(3, 92), Pair(4, 85), Pair(25, 69), Pair(-4, 72), Pair(10, 98), Pair(27, 51), Pair(9, 88),
        Pair(-16, 106), Pair(-2, 65), Pair(3, 94), Pair(-3, 67), Pair(-8, 109), Pair(-4, 77), Pair(-14, 139), Pair(0, 100),
        Pair(10, 78), Pair(6, 83), Pair(5, 71), Pair(5, 55), Pair(3, 95), Pair(2, 75), Pair(4, 85), Pair(2, 90),
        Pair(6, 63), Pair(12, 64), Pair(7, 62), Pair(0, 0), Pair(4, 78), Pair(-7, 96), Pair(10, 78), Pair(9, 64),
        Pair(4, 77), Pair(14, 63), Pair(6, 93), Pair(19, 65), Pair(11, 84), Pair(12, 85), Pair(6, 102), Pair(16, 70),
        Pair(15, 56), Pair(14, 62), Pair(13, 84), Pair(10, 71), Pair(11, 76), Pair(12, 69), Pair(13, 82), Pair(-8, 116),
        Pair(12, 55), Pair(15, 92), Pair(12, 75), Pair(12, 66), Pair(12, 83), Pair(15, 81), Pair(-2, 66), Pair(12, 67)
      },
      { // Piece 5
        Pair(-45, -27), Pair(-25, 82), Pair(-66, 82), Pair(-12, 118), Pair(-43, 29), Pair(48, 73), Pair(-18, 44), Pair(62, -13),
        Pair(-140, 35), Pair(8, 37), Pair(27, 58), Pair(50, 74), Pair(43, 35), Pair(134, 18), Pair(-40, 40), Pair(22, -17),
        Pair(-207, 69), Pair(24, 37), Pair(83, 50), Pair(26, 48), Pair(-38, 55), Pair(-73, 44), Pair(-28, 37), Pair(50, 2),
        Pair(-56, 32), Pair(-31, 36), Pair(-42, 19), Pair(-38, 26), Pair(-49, 19), Pair(75, 8), Pair(10, 13), Pair(-37, 10),
        Pair(13, 11), Pair(15, 21), Pair(-20, 45), Pair(0, 0), Pair(-19, 33), Pair(-26, 13), Pair(5, 3), Pair(-39, -3),
        Pair(-62, 16), Pair(-1, 19), Pair(-46, 24), Pair(-76, 44), Pair(-43, 13), Pair(9, -5), Pair(-2, -3), Pair(1, -11),
        Pair(25, -11), Pair(9, -1), Pair(-18, 3), Pair(-70, 24), Pair(-24, 2), Pair(8, -16), Pair(-3, -12), Pair(9, -20),
        Pair(5, -8), Pair(-2, -7), Pair(-2, -25), Pair(-48, 2), Pair(4, -31), Pair(3, -19), Pair(3, -21), Pair(5, -22)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 15), Pair(-22, 24), Pair(-21, 14), Pair(6, 18), Pair(-21, 6), Pair(-9, 9), Pair(-10, 20), Pair(2, 3),
        Pair(3, 9), Pair(1, 7), Pair(4, 10), Pair(-6, 25), Pair(7, 1), Pair(-11, 19), Pair(-4, 12), Pair(0, 10),
        Pair(2, 8), Pair(3, 11), Pair(2, 10), Pair(7, 16), Pair(0, -6), Pair(15, 9), Pair(-3, 9), Pair(1, 8),
        Pair(1, 12), Pair(2, 13), Pair(-4, 8), Pair(-4, 20), Pair(-1, -7), Pair(4, 6), Pair(-3, 8), Pair(2, 7),
        Pair(2, 9), Pair(2, 11), Pair(2, 8), Pair(13, 14), Pair(4, -3), Pair(18, 15), Pair(-2, 8), Pair(3, 10),
        Pair(2, 15), Pair(2, 16), Pair(1, 11), Pair(6, 17), Pair(5, 0), Pair(6, 24), Pair(4, 15), Pair(4, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-29, 47), Pair(-1, 19), Pair(-27, 57), Pair(70, 16), Pair(14, 39), Pair(67, 22), Pair(60, 33), Pair(-36, 35),
        Pair(-3, 32), Pair(-13, 51), Pair(-10, 50), Pair(1, 54), Pair(-14, 63), Pair(16, 0), Pair(10, 48), Pair(-18, 17),
        Pair(25, 24), Pair(-4, 58), Pair(15, 52), Pair(0, 46), Pair(-3, 50), Pair(4, 38), Pair(-7, 52), Pair(-24, 45),
        Pair(-10, 60), Pair(-2, 43), Pair(-13, 48), Pair(-3, 55), Pair(-21, 47), Pair(-4, 51), Pair(-12, 47), Pair(-12, 53),
        Pair(-5, 50), Pair(10, 48), Pair(3, 50), Pair(4, 48), Pair(0, 0), Pair(0, 57), Pair(-15, 49), Pair(-10, 65),
        Pair(-2, 49), Pair(2, 43), Pair(-5, 39), Pair(13, 46), Pair(3, 79), Pair(2, 56), Pair(-3, 29), Pair(-7, 45),
        Pair(-3, 49), Pair(10, 39), Pair(-1, 44), Pair(-1, 38), Pair(7, 42), Pair(8, 43), Pair(2, 40), Pair(-3, 54),
        Pair(56, 10), Pair(-2, 32), Pair(8, 39), Pair(-5, 37), Pair(1, 49), Pair(-5, 46), Pair(-3, 51), Pair(-3, 71)
      },
      { // Piece 2
        Pair(5, -21), Pair(-7, 9), Pair(52, -16), Pair(53, 8), Pair(70, -25), Pair(36, 30), Pair(-59, 6), Pair(85, -6),
        Pair(6, 18), Pair(0, -6), Pair(17, 23), Pair(33, -11), Pair(13, 16), Pair(26, -12), Pair(-14, 26), Pair(-84, 15),
        Pair(5, -1), Pair(28, 15), Pair(3, 2), Pair(21, 23), Pair(-3, 1), Pair(12, 21), Pair(-4, -16), Pair(-12, 35),
        Pair(11, 16), Pair(3, 7), Pair(16, 21), Pair(15, -8), Pair(-7, 24), Pair(45, -7), Pair(3, 25), Pair(-8, 11),
        Pair(-2, 8), Pair(12, 27), Pair(1, 15), Pair(9, 31), Pair(0, 0), Pair(8, 36), Pair(-1, 5), Pair(-5, 27),
        Pair(9, 38), Pair(0, 6), Pair(2, 40), Pair(-6, 2), Pair(8, 60), Pair(-24, -8), Pair(0, 53), Pair(-15, 18),
        Pair(15, 0), Pair(-1, 40), Pair(-16, -1), Pair(4, 30), Pair(-3, 12), Pair(4, 36), Pair(-29, -8), Pair(5, 22),
        Pair(0, 37), Pair(-14, -9), Pair(4, 36), Pair(-8, 9), Pair(14, 28), Pair(-11, 15), Pair(5, 49), Pair(-32, -31)
      },
      { // Piece 3
        Pair(11, 53), Pair(1, 55), Pair(2, 52), Pair(1, 43), Pair(37, 32), Pair(-13, 55), Pair(60, 48), Pair(53, 37),
        Pair(-3, 56), Pair(-18, 63), Pair(-3, 54), Pair(-12, 59), Pair(-13, 40), Pair(-24, 57), Pair(-12, 55), Pair(11, 52),
        Pair(7, 52), Pair(11, 50), Pair(-2, 53), Pair(-11, 56), Pair(9, 37), Pair(-21, 54), Pair(-3, 59), Pair(10, 49),
        Pair(4, 57), Pair(10, 47), Pair(3, 56), Pair(5, 49), Pair(1, 19), Pair(-1, 60), Pair(-7, 53), Pair(6, 56),
        Pair(6, 45), Pair(8, 45), Pair(6, 41), Pair(6, 43), Pair(0, 0), Pair(-6, 41), Pair(12, 31), Pair(-4, 46),
        Pair(4, 49), Pair(6, 38), Pair(2, 55), Pair(18, 38), Pair(4, 21), Pair(3, 44), Pair(-6, 48), Pair(3, 48),
        Pair(3, 44), Pair(1, 44), Pair(4, 41), Pair(-5, 53), Pair(1, 11), Pair(-12, 53), Pair(-1, 40), Pair(19, 48),
        Pair(4, 45), Pair(6, 44), Pair(2, 50), Pair(2, 49), Pair(8, 23), Pair(-4, 50), Pair(1, 47), Pair(17, 46)
      },
      { // Piece 4
        Pair(10, 58), Pair(42, 58), Pair(-5, 77), Pair(2, 92), Pair(0, 76), Pair(-7, 106), Pair(-69, 164), Pair(-28, 128),
        Pair(-1, 87), Pair(2, 63), Pair(14, 79), Pair(17, 85), Pair(15, 55), Pair(4, 80), Pair(8, 116), Pair(-33, 122),
        Pair(1, 98), Pair(7, 79), Pair(-8, 70), Pair(6, 88), Pair(0, 73), Pair(-19, 117), Pair(-2, 69), Pair(-16, 92),
        Pair(10, 85), Pair(11, 67), Pair(11, 79), Pair(3, 88), Pair(1, 57), Pair(2, 68), Pair(2, 94), Pair(0, 71),
        Pair(5, 85), Pair(17, 53), Pair(0, 88), Pair(14, 71), Pair(0, 0), Pair(-16, 97), Pair(5, 76), Pair(16, 58),
        Pair(17, 76), Pair(12, 82), Pair(11, 84), Pair(9, 75), Pair(11, 77), Pair(9, 75), Pair(11, 80), Pair(9, 72),
        Pair(5, 78), Pair(9, 86), Pair(17, 63), Pair(14, 73), Pair(12, 66), Pair(12, 62), Pair(13, 67), Pair(8, 55),
        Pair(16, 63), Pair(6, 73), Pair(16, 80), Pair(11, 84), Pair(17, 56), Pair(15, 72), Pair(0, 88), Pair(10, 48)
      },
      { // Piece 5
        Pair(-60, -17), Pair(-85, 18), Pair(39, 29), Pair(-169, 65), Pair(155, 35), Pair(78, 27), Pair(6, 81), Pair(60, -37),
        Pair(51, -8), Pair(-56, 26), Pair(-13, 42), Pair(-3, 65), Pair(72, 62), Pair(11, 57), Pair(75, 36), Pair(-72, 43),
        Pair(25, 17), Pair(-24, 14), Pair(-50, 39), Pair(46, 31), Pair(1, 37), Pair(-9, 43), Pair(49, 21), Pair(-100, 34),
        Pair(-63, 12), Pair(-92, 20), Pair(-7, 18), Pair(-13, 9), Pair(9, 11), Pair(-29, 3), Pair(20, 10), Pair(-3, 17),
        Pair(-25, -2), Pair(-30, 7), Pair(-5, 11), Pair(-39, 33), Pair(0, 0), Pair(-21, 16), Pair(5, 10), Pair(11, -2),
        Pair(38, -17), Pair(-16, 11), Pair(-6, 2), Pair(-40, 10), Pair(-33, 26), Pair(-30, 6), Pair(7, -9), Pair(2, -9),
        Pair(15, -14), Pair(-7, -5), Pair(7, -14), Pair(-38, 10), Pair(-33, 5), Pair(-32, 0), Pair(4, -14), Pair(11, -19),
        Pair(0, -33), Pair(-12, -16), Pair(-11, -18), Pair(-1, -9), Pair(-9, -23), Pair(-7, -14), Pair(4, -19), Pair(7, -28)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 10), Pair(-3, 4), Pair(-5, 8), Pair(4, 7), Pair(-1, 20), Pair(-10, -15), Pair(-22, 18), Pair(6, 3),
        Pair(-1, 11), Pair(4, 7), Pair(7, 7), Pair(5, 10), Pair(-10, 17), Pair(-4, 12), Pair(-12, 14), Pair(-7, 11),
        Pair(2, 9), Pair(4, 8), Pair(6, 5), Pair(8, 9), Pair(7, 3), Pair(-3, -5), Pair(4, -3), Pair(3, 5),
        Pair(1, 7), Pair(7, 12), Pair(6, 9), Pair(-1, 5), Pair(3, 8), Pair(-6, -3), Pair(3, -5), Pair(-2, 2),
        Pair(-2, 13), Pair(3, 11), Pair(4, 9), Pair(2, 7), Pair(14, 9), Pair(2, 2), Pair(11, 0), Pair(-2, 6),
        Pair(2, 13), Pair(5, 12), Pair(-1, 9), Pair(-1, 13), Pair(11, 12), Pair(4, 7), Pair(6, 11), Pair(-4, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(7, 5), Pair(-100, 49), Pair(-51, 42), Pair(61, 15), Pair(29, 32), Pair(49, 18), Pair(125, 10), Pair(-18, 12),
        Pair(2, 26), Pair(15, 37), Pair(-7, 50), Pair(16, 42), Pair(29, 35), Pair(-11, 38), Pair(-1, 42), Pair(-33, 43),
        Pair(1, 40), Pair(2, 46), Pair(25, 39), Pair(8, 44), Pair(9, 31), Pair(-30, 52), Pair(17, 26), Pair(9, 36),
        Pair(-4, 41), Pair(9, 39), Pair(17, 42), Pair(11, 45), Pair(23, 47), Pair(0, 35), Pair(-9, 42), Pair(-26, 38),
        Pair(8, 32), Pair(22, 37), Pair(13, 44), Pair(19, 44), Pair(3, 45), Pair(0, 0), Pair(-18, 57), Pair(0, 50),
        Pair(6, 27), Pair(14, 36), Pair(7, 40), Pair(22, 37), Pair(14, 46), Pair(11, 56), Pair(14, 47), Pair(-7, 6),
        Pair(-5, 21), Pair(9, 22), Pair(11, 41), Pair(10, 32), Pair(5, 36), Pair(11, 27), Pair(-7, 43), Pair(-1, 28),
        Pair(-21, 52), Pair(0, 19), Pair(-14, 41), Pair(3, 30), Pair(8, 32), Pair(6, 33), Pair(2, 18), Pair(-6, 31)
      },
      { // Piece 2
        Pair(25, 1), Pair(6, 0), Pair(21, 14), Pair(45, -14), Pair(5, 21), Pair(33, -4), Pair(111, 2), Pair(-2, 8),
        Pair(7, 6), Pair(20, 17), Pair(0, 0), Pair(60, -1), Pair(17, -13), Pair(-16, 22), Pair(28, -2), Pair(19, 23),
        Pair(6, 20), Pair(20, 0), Pair(28, 14), Pair(17, -1), Pair(31, 17), Pair(-3, 10), Pair(21, 16), Pair(-24, 3),
        Pair(0, 5), Pair(29, 14), Pair(12, 8), Pair(22, 23), Pair(14, 6), Pair(16, 20), Pair(-19, 22), Pair(3, 30),
        Pair(26, 30), Pair(9, 5), Pair(19, 17), Pair(15, 13), Pair(12, 31), Pair(0, 0), Pair(11, 21), Pair(-1, 15),
        Pair(-3, 21), Pair(13, 22), Pair(-3, 23), Pair(18, 28), Pair(1, 11), Pair(25, 42), Pair(-5, -4), Pair(11, 28),
        Pair(12, 26), Pair(-4, 23), Pair(19, 22), Pair(-8, 8), Pair(14, 26), Pair(1, 9), Pair(11, 30), Pair(-24, -39),
        Pair(4, 20), Pair(19, 19), Pair(-14, 8), Pair(6, 25), Pair(-5, 12), Pair(4, 28), Pair(2, 11), Pair(26, 2)
      },
      { // Piece 3
        Pair(44, 36), Pair(36, 34), Pair(37, 32), Pair(55, 30), Pair(15, 45), Pair(88, 13), Pair(50, 29), Pair(46, 35),
        Pair(23, 40), Pair(27, 40), Pair(30, 33), Pair(29, 41), Pair(17, 45), Pair(35, 22), Pair(20, 46), Pair(30, 37),
        Pair(22, 35), Pair(27, 31), Pair(31, 36), Pair(24, 35), Pair(1, 42), Pair(46, 16), Pair(18, 34), Pair(33, 33),
        Pair(13, 42), Pair(21, 42), Pair(20, 42), Pair(32, 32), Pair(25, 43), Pair(6, 15), Pair(10, 46), Pair(19, 49),
        Pair(16, 38), Pair(17, 43), Pair(21, 41), Pair(21, 36), Pair(18, 42), Pair(0, 0), Pair(19, 23), Pair(-4, 39),
        Pair(20, 38), Pair(25, 29), Pair(16, 40), Pair(25, 30), Pair(18, 32), Pair(9, 13), Pair(11, 35), Pair(4, 36),
        Pair(-2, 43), Pair(18, 26), Pair(23, 36), Pair(14, 35), Pair(10, 38), Pair(20, 12), Pair(15, 33), Pair(19, 23),
        Pair(15, 33), Pair(19, 35), Pair(20, 35), Pair(20, 28), Pair(15, 39), Pair(18, 14), Pair(11, 37), Pair(18, 38)
      },
      { // Piece 4
        Pair(29, 62), Pair(30, 52), Pair(-3, 94), Pair(38, 38), Pair(-7, 105), Pair(21, 43), Pair(-54, 119), Pair(20, 45),
        Pair(-9, 86), Pair(-1, 82), Pair(8, 61), Pair(20, 56), Pair(-12, 81), Pair(-17, 58), Pair(-37, 91), Pair(-5, 77),
        Pair(-3, 78), Pair(-6, 90), Pair(15, 71), Pair(9, 63), Pair(2, 73), Pair(-7, 57), Pair(15, 62), Pair(-3, 50),
        Pair(-4, 79), Pair(4, 79), Pair(12, 60), Pair(-8, 99), Pair(7, 84), Pair(4, 44), Pair(-17, 99), Pair(-3, 95),
        Pair(11, 70), Pair(17, 65), Pair(10, 77), Pair(6, 76), Pair(9, 72), Pair(0, 0), Pair(-7, 89), Pair(6, 50),
        Pair(-3, 76), Pair(10, 79), Pair(14, 71), Pair(9, 68), Pair(4, 73), Pair(10, 58), Pair(5, 64), Pair(8, 80),
        Pair(17, 52), Pair(16, 60), Pair(10, 70), Pair(11, 62), Pair(10, 61), Pair(18, 41), Pair(0, 102), Pair(-8, 32),
        Pair(2, 74), Pair(5, 74), Pair(0, 64), Pair(8, 81), Pair(16, 58), Pair(6, 51), Pair(13, 71), Pair(10, 84)
      },
      { // Piece 5
        Pair(76, -47), Pair(-55, 24), Pair(-55, -6), Pair(71, 9), Pair(-112, 55), Pair(-43, 46), Pair(-36, 69), Pair(-23, 41),
        Pair(-18, 21), Pair(58, 19), Pair(53, 8), Pair(-18, 41), Pair(-54, 68), Pair(-51, 67), Pair(143, 23), Pair(-27, 47),
        Pair(-86, 50), Pair(-4, 18), Pair(3, 23), Pair(-74, 43), Pair(63, 43), Pair(23, 53), Pair(-9, 46), Pair(-34, 42),
        Pair(-78, 9), Pair(-37, 14), Pair(-53, 29), Pair(-37, 27), Pair(-8, 10), Pair(35, 4), Pair(15, -7), Pair(-12, 32),
        Pair(-56, 5), Pair(23, 1), Pair(-37, 16), Pair(-44, 23), Pair(15, 10), Pair(0, 0), Pair(28, -3), Pair(23, 11),
        Pair(-35, -9), Pair(-56, 14), Pair(-19, 8), Pair(-5, 11), Pair(-16, 14), Pair(-45, 21), Pair(-11, 3), Pair(18, -6),
        Pair(-28, -1), Pair(-15, 1), Pair(-17, 2), Pair(-10, 7), Pair(-10, 12), Pair(-70, 31), Pair(-17, 4), Pair(17, -2),
        Pair(-14, -15), Pair(-14, -11), Pair(-14, -9), Pair(-17, -14), Pair(-1, -25), Pair(-25, -10), Pair(10, -29), Pair(11, -24)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(3, 7), Pair(-10, 23), Pair(-20, 16), Pair(-1, 5), Pair(17, -5), Pair(15, 3), Pair(10, -21), Pair(-8, 17),
        Pair(-1, 13), Pair(-2, 12), Pair(-4, 12), Pair(0, 10), Pair(0, 9), Pair(-2, 17), Pair(0, -13), Pair(5, 14),
        Pair(-1, 14), Pair(-2, 14), Pair(2, 7), Pair(5, 5), Pair(5, 7), Pair(13, 1), Pair(16, -21), Pair(3, -3),
        Pair(-5, 14), Pair(2, 13), Pair(3, 10), Pair(4, 10), Pair(-4, 6), Pair(2, -5), Pair(5, 5), Pair(11, -6),
        Pair(-1, 17), Pair(2, 14), Pair(0, 15), Pair(1, 11), Pair(-2, 10), Pair(20, 4), Pair(5, -10), Pair(16, 6),
        Pair(-3, 17), Pair(1, 11), Pair(-7, 15), Pair(1, 15), Pair(-3, 17), Pair(9, 17), Pair(1, -2), Pair(6, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-22, 22), Pair(83, 15), Pair(-20, 38), Pair(85, -4), Pair(-16, 43), Pair(26, 26), Pair(-39, 33), Pair(35, -32),
        Pair(-4, 13), Pair(-4, 26), Pair(21, 31), Pair(65, 12), Pair(41, 28), Pair(23, 20), Pair(3, 37), Pair(31, 17),
        Pair(-18, 23), Pair(2, 38), Pair(6, 37), Pair(5, 39), Pair(12, 36), Pair(41, 19), Pair(15, 32), Pair(42, -2),
        Pair(-16, 30), Pair(4, 25), Pair(15, 35), Pair(19, 36), Pair(21, 30), Pair(29, 10), Pair(25, 17), Pair(-24, -14),
        Pair(-5, 29), Pair(15, 35), Pair(12, 37), Pair(22, 36), Pair(28, 38), Pair(16, 35), Pair(0, 0), Pair(-1, 28),
        Pair(-12, 16), Pair(9, 33), Pair(8, 41), Pair(12, 40), Pair(12, 32), Pair(8, 42), Pair(20, 52), Pair(5, 47),
        Pair(-28, 36), Pair(-4, 29), Pair(-10, 33), Pair(5, 41), Pair(7, 31), Pair(9, 23), Pair(-8, 25), Pair(-20, 15),
        Pair(-53, 8), Pair(-20, 20), Pair(8, 8), Pair(-12, 42), Pair(-7, 39), Pair(-3, 27), Pair(3, -8), Pair(-26, 15)
      },
      { // Piece 2
        Pair(0, 4), Pair(-26, 19), Pair(46, -21), Pair(56, 5), Pair(43, -11), Pair(57, 10), Pair(137, -20), Pair(-37, 17),
        Pair(24, 10), Pair(31, -12), Pair(13, 10), Pair(63, -18), Pair(47, 3), Pair(41, -23), Pair(54, 10), Pair(-12, 6),
        Pair(2, 3), Pair(20, 8), Pair(27, -5), Pair(21, 15), Pair(13, 3), Pair(53, 17), Pair(11, 8), Pair(10, 19),
        Pair(8, 17), Pair(15, 6), Pair(28, 11), Pair(30, -2), Pair(13, 22), Pair(64, -5), Pair(14, 13), Pair(-67, -18),
        Pair(0, 13), Pair(22, 21), Pair(21, 1), Pair(13, 30), Pair(30, 10), Pair(16, 32), Pair(0, 0), Pair(12, 17),
        Pair(9, 32), Pair(23, 5), Pair(12, 31), Pair(17, 10), Pair(18, 24), Pair(9, 7), Pair(32, 28), Pair(-10, -28),
        Pair(15, -19), Pair(4, 38), Pair(14, 13), Pair(9, 33), Pair(2, 10), Pair(10, 29), Pair(7, 10), Pair(13, 30),
        Pair(13, 21), Pair(17, 2), Pair(4, 33), Pair(-13, 18), Pair(12, 16), Pair(3, 3), Pair(16, 19), Pair(10, -13)
      },
      { // Piece 3
        Pair(24, 42), Pair(38, 38), Pair(26, 32), Pair(48, 32), Pair(38, 31), Pair(20, 48), Pair(149, -9), Pair(31, 34),
        Pair(40, 34), Pair(22, 34), Pair(29, 30), Pair(41, 25), Pair(50, 28), Pair(32, 30), Pair(51, 12), Pair(11, 28),
        Pair(20, 38), Pair(39, 25), Pair(32, 31), Pair(41, 21), Pair(35, 37), Pair(25, 33), Pair(40, 20), Pair(14, 33),
        Pair(8, 48), Pair(23, 32), Pair(8, 43), Pair(46, 30), Pair(32, 35), Pair(28, 44), Pair(44, 0), Pair(7, 46),
        Pair(14, 35), Pair(7, 41), Pair(17, 36), Pair(24, 31), Pair(35, 30), Pair(1, 47), Pair(0, 0), Pair(-20, 26),
        Pair(0, 33), Pair(4, 37), Pair(9, 41), Pair(14, 33), Pair(12, 30), Pair(2, 43), Pair(17, 3), Pair(-15, 35),
        Pair(-11, 37), Pair(24, 31), Pair(8, 30), Pair(13, 37), Pair(17, 37), Pair(14, 30), Pair(9, -3), Pair(3, 34),
        Pair(11, 29), Pair(15, 37), Pair(16, 35), Pair(18, 33), Pair(20, 30), Pair(16, 27), Pair(27, -7), Pair(7, 31)
      },
      { // Piece 4
        Pair(37, 27), Pair(55, 23), Pair(32, 14), Pair(34, 37), Pair(17, 56), Pair(76, 21), Pair(76, -30), Pair(57, 14),
        Pair(5, 42), Pair(5, 34), Pair(-11, 41), Pair(9, 30), Pair(22, 45), Pair(4, 64), Pair(14, -9), Pair(77, -60),
        Pair(12, 35), Pair(19, 39), Pair(23, 13), Pair(11, 42), Pair(24, 38), Pair(30, 20), Pair(15, -3), Pair(23, 1),
        Pair(4, 37), Pair(3, 36), Pair(3, 65), Pair(8, 64), Pair(19, 32), Pair(-3, 53), Pair(1, 26), Pair(-3, 5),
        Pair(20, -6), Pair(19, 36), Pair(30, 30), Pair(6, 50), Pair(16, 39), Pair(10, 41), Pair(0, 0), Pair(19, 1),
        Pair(9, 26), Pair(16, 45), Pair(9, 36), Pair(17, 33), Pair(15, 43), Pair(11, 38), Pair(11, 22), Pair(5, 27),
        Pair(21, 30), Pair(15, 45), Pair(17, 41), Pair(9, 39), Pair(16, 26), Pair(17, 32), Pair(-3, 40), Pair(-5, 53),
        Pair(13, 21), Pair(3, 46), Pair(6, 54), Pair(2, 57), Pair(14, 42), Pair(11, 30), Pair(12, -51), Pair(2, 64)
      },
      { // Piece 5
        Pair(-57, -15), Pair(-39, 45), Pair(-10, -7), Pair(0, 22), Pair(-36, 24), Pair(101, 46), Pair(18, 60), Pair(51, 182),
        Pair(-72, 1), Pair(-4, -6), Pair(1, 1), Pair(-3, 12), Pair(31, 36), Pair(36, 34), Pair(215, 44), Pair(35, 67),
        Pair(-95, 15), Pair(-109, 27), Pair(-75, 23), Pair(-68, 27), Pair(16, 24), Pair(98, 34), Pair(72, 54), Pair(44, 39),
        Pair(-79, 21), Pair(-32, 10), Pair(-35, 26), Pair(-43, 34), Pair(-25, 29), Pair(55, 1), Pair(72, 3), Pair(-76, 21),
        Pair(-56, 9), Pair(-14, -1), Pair(-32, 18), Pair(-66, 27), Pair(7, 27), Pair(17, 6), Pair(0, 0), Pair(-20, 9),
        Pair(-77, 4), Pair(-50, 11), Pair(-18, 8), Pair(-28, 15), Pair(6, 12), Pair(-30, 8), Pair(-10, 12), Pair(-35, 1),
        Pair(-29, -9), Pair(-29, 9), Pair(-23, 5), Pair(-35, 12), Pair(-10, 5), Pair(-24, 10), Pair(6, -1), Pair(-27, 9),
        Pair(-28, -26), Pair(-20, -4), Pair(-27, -7), Pair(-30, 0), Pair(-8, -12), Pair(4, -19), Pair(17, -18), Pair(-4, -32)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(13, 3), Pair(-15, 17), Pair(11, 5), Pair(13, 2), Pair(-18, 8), Pair(-35, 11), Pair(7, 20), Pair(38, -13),
        Pair(0, 11), Pair(-1, 19), Pair(4, 12), Pair(-7, 10), Pair(-6, 11), Pair(-8, 9), Pair(-11, 18), Pair(19, -9),
        Pair(-1, 14), Pair(1, 12), Pair(4, 9), Pair(2, 9), Pair(-4, 9), Pair(1, 6), Pair(3, 0), Pair(24, -9),
        Pair(-5, 15), Pair(1, 11), Pair(-2, 11), Pair(1, 12), Pair(3, 6), Pair(-3, 2), Pair(11, -4), Pair(10, 1),
        Pair(-3, 15), Pair(0, 15), Pair(2, 10), Pair(-1, 14), Pair(8, 10), Pair(7, 5), Pair(11, 4), Pair(3, 7),
        Pair(-2, 17), Pair(0, 13), Pair(-5, 13), Pair(-1, 8), Pair(-2, 9), Pair(2, 10), Pair(3, 13), Pair(4, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(61, 15), Pair(167, -16), Pair(-66, 46), Pair(-3, 19), Pair(36, 10), Pair(46, 26), Pair(101, 7), Pair(-5, -28),
        Pair(15, 10), Pair(-10, 32), Pair(3, 21), Pair(18, 22), Pair(27, 26), Pair(14, 24), Pair(-4, 37), Pair(16, 8),
        Pair(-14, 27), Pair(-5, 31), Pair(7, 27), Pair(20, 29), Pair(24, 31), Pair(38, 16), Pair(25, 14), Pair(-10, 18),
        Pair(-11, 30), Pair(4, 30), Pair(2, 27), Pair(19, 28), Pair(22, 27), Pair(25, 26), Pair(19, 8), Pair(7, 7),
        Pair(-6, 29), Pair(-8, 38), Pair(8, 32), Pair(16, 31), Pair(14, 27), Pair(14, 28), Pair(30, 18), Pair(0, 0),
        Pair(-11, 25), Pair(-4, 28), Pair(8, 26), Pair(5, 24), Pair(14, 31), Pair(4, 31), Pair(12, 26), Pair(9, 37),
        Pair(-35, 40), Pair(-7, 25), Pair(-3, 24), Pair(0, 29), Pair(-1, 28), Pair(-1, 25), Pair(-14, 35), Pair(0, 19),
        Pair(-39, 23), Pair(-13, 15), Pair(-21, 26), Pair(-3, 41), Pair(7, 26), Pair(-7, 14), Pair(-1, 12), Pair(-20, 12)
      },
      { // Piece 2
        Pair(18, -7), Pair(30, -12), Pair(-5, 13), Pair(48, -9), Pair(78, -4), Pair(-3, 6), Pair(-73, 17), Pair(-8, 10),
        Pair(8, 8), Pair(16, -3), Pair(-1, 4), Pair(53, -16), Pair(9, -6), Pair(-3, 16), Pair(3, 11), Pair(-20, 28),
        Pair(4, 12), Pair(20, 2), Pair(24, 3), Pair(16, -5), Pair(31, 4), Pair(35, 0), Pair(17, 9), Pair(1, 12),
        Pair(12, 9), Pair(19, 8), Pair(4, 7), Pair(26, 13), Pair(25, 3), Pair(17, 15), Pair(1, 38), Pair(8, 3),
        Pair(2, 23), Pair(19, 0), Pair(17, 13), Pair(18, 10), Pair(16, 18), Pair(10, 20), Pair(15, 14), Pair(0, 0),
        Pair(9, 18), Pair(23, 9), Pair(6, 12), Pair(8, 21), Pair(12, 11), Pair(10, 22), Pair(16, 16), Pair(17, 35),
        Pair(6, 2), Pair(7, 16), Pair(11, 20), Pair(3, 13), Pair(12, 20), Pair(0, 20), Pair(15, 15), Pair(6, 4),
        Pair(18, 6), Pair(17, 2), Pair(0, 20), Pair(6, 18), Pair(1, 19), Pair(-1, 20), Pair(18, -14), Pair(6, 2)
      },
      { // Piece 3
        Pair(24, 40), Pair(37, 25), Pair(38, 31), Pair(6, 38), Pair(50, 20), Pair(43, 31), Pair(13, 36), Pair(32, 11),
        Pair(22, 34), Pair(25, 27), Pair(21, 32), Pair(16, 32), Pair(20, 30), Pair(21, 34), Pair(-9, 36), Pair(57, -3),
        Pair(1, 46), Pair(25, 32), Pair(23, 28), Pair(24, 37), Pair(28, 27), Pair(51, 26), Pair(3, 36), Pair(27, 18),
        Pair(8, 46), Pair(11, 35), Pair(7, 39), Pair(25, 30), Pair(24, 31), Pair(25, 34), Pair(19, 41), Pair(-7, 11),
        Pair(13, 31), Pair(14, 30), Pair(14, 37), Pair(7, 31), Pair(12, 38), Pair(18, 50), Pair(-1, 51), Pair(0, 0),
        Pair(-3, 35), Pair(1, 34), Pair(-5, 34), Pair(1, 34), Pair(5, 35), Pair(2, 40), Pair(-10, 39), Pair(-31, 7),
        Pair(-6, 29), Pair(-2, 30), Pair(18, 29), Pair(2, 32), Pair(6, 34), Pair(1, 31), Pair(-6, 26), Pair(-48, 27),
        Pair(7, 31), Pair(8, 30), Pair(12, 29), Pair(11, 29), Pair(14, 28), Pair(11, 25), Pair(-4, 27), Pair(-22, 5)
      },
      { // Piece 4
        Pair(21, 44), Pair(62, -1), Pair(52, -3), Pair(29, 0), Pair(55, 17), Pair(20, 29), Pair(35, 20), Pair(49, 4),
        Pair(13, 24), Pair(10, 29), Pair(12, 22), Pair(21, 15), Pair(6, 43), Pair(46, 32), Pair(24, 5), Pair(20, 9),
        Pair(1, 36), Pair(13, 34), Pair(7, 38), Pair(29, 35), Pair(32, 32), Pair(46, 16), Pair(60, -9), Pair(-1, 19),
        Pair(8, 37), Pair(15, 33), Pair(11, 42), Pair(8, 53), Pair(16, 31), Pair(22, 30), Pair(33, 39), Pair(4, 6),
        Pair(13, 39), Pair(15, 19), Pair(2, 50), Pair(10, 40), Pair(8, 52), Pair(10, 57), Pair(22, 29), Pair(0, 0),
        Pair(19, 25), Pair(19, 31), Pair(8, 34), Pair(6, 44), Pair(12, 46), Pair(9, 40), Pair(11, 20), Pair(-13, 6),
        Pair(8, 50), Pair(9, 52), Pair(12, 53), Pair(11, 55), Pair(11, 43), Pair(10, 37), Pair(9, 34), Pair(-15, -34),
        Pair(5, 42), Pair(4, 55), Pair(6, 58), Pair(8, 59), Pair(0, 62), Pair(15, 30), Pair(-4, 73), Pair(18, -34)
      },
      { // Piece 5
        Pair(-29, 31), Pair(-85, -8), Pair(-55, 0), Pair(-137, 28), Pair(-34, 35), Pair(-13, 34), Pair(-63, 62), Pair(22, -13),
        Pair(-34, -25), Pair(-8, 1), Pair(-110, 16), Pair(-12, 21), Pair(-21, 27), Pair(-120, 61), Pair(-110, 74), Pair(-54, 22),
        Pair(32, 11), Pair(-83, 11), Pair(-75, 26), Pair(-59, 29), Pair(-35, 45), Pair(-10, 34), Pair(-17, 45), Pair(-13, 15),
        Pair(-48, 12), Pair(-65, 19), Pair(-102, 29), Pair(-87, 32), Pair(-64, 28), Pair(-27, 30), Pair(1, 3), Pair(-42, -8),
        Pair(-31, -2), Pair(-69, 23), Pair(-71, 26), Pair(-46, 22), Pair(-41, 22), Pair(11, 13), Pair(-18, -9), Pair(0, 0),
        Pair(-68, 9), Pair(-38, 15), Pair(-46, 11), Pair(-35, 11), Pair(-5, 6), Pair(5, 4), Pair(-34, -8), Pair(-47, -18),
        Pair(-47, -1), Pair(-58, 16), Pair(-38, 6), Pair(-42, 15), Pair(-21, 3), Pair(-25, 7), Pair(-4, -3), Pair(-3, -24),
        Pair(-53, 0), Pair(-30, 2), Pair(-28, 3), Pair(-23, -9), Pair(-11, -12), Pair(-19, -4), Pair(12, -8), Pair(5, -36)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-22, 30), Pair(-14, 26), Pair(4, 14), Pair(11, 21), Pair(11, 14), Pair(0, 16), Pair(1, -4), Pair(-24, 26),
        Pair(1, 24), Pair(-12, 21), Pair(0, 10), Pair(-10, 14), Pair(2, 9), Pair(9, 3), Pair(-2, 11), Pair(0, 14),
        Pair(7, 12), Pair(-1, 14), Pair(-1, 10), Pair(-1, 11), Pair(2, 8), Pair(1, 12), Pair(-1, 10), Pair(-3, 13),
        Pair(1, 7), Pair(8, 8), Pair(0, 9), Pair(1, 8), Pair(3, 7), Pair(2, 14), Pair(-3, 14), Pair(-4, 14),
        Pair(-3, 6), Pair(-3, 3), Pair(-4, 10), Pair(2, 14), Pair(-1, 12), Pair(-2, 13), Pair(-2, 14), Pair(-8, 17),
        Pair(2, 1), Pair(4, 21), Pair(-5, 13), Pair(3, 11), Pair(-2, 10), Pair(3, 20), Pair(0, 21), Pair(-3, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(1, -5), Pair(-96, 53), Pair(-21, 47), Pair(-64, 50), Pair(-79, 59), Pair(25, 8), Pair(2, 20), Pair(-41, 54),
        Pair(9, 20), Pair(-14, 46), Pair(-6, 48), Pair(-6, 54), Pair(-7, 37), Pair(-11, 49), Pair(7, 31), Pair(-5, 45),
        Pair(-22, 28), Pair(-7, 41), Pair(0, 49), Pair(-3, 51), Pair(-9, 46), Pair(1, 48), Pair(-17, 53), Pair(3, 50),
        Pair(2, 31), Pair(0, 45), Pair(-1, 45), Pair(0, 54), Pair(-2, 53), Pair(5, 52), Pair(-6, 53), Pair(-3, 60),
        Pair(-12, 33), Pair(20, 49), Pair(3, 50), Pair(8, 50), Pair(1, 51), Pair(2, 51), Pair(-5, 55), Pair(4, 50),
        Pair(0, 0), Pair(0, 40), Pair(-1, 41), Pair(9, 45), Pair(1, 58), Pair(1, 47), Pair(-1, 45), Pair(-1, 33),
        Pair(-4, 66), Pair(-3, 56), Pair(-6, 51), Pair(-5, 49), Pair(2, 53), Pair(-7, 55), Pair(-2, 55), Pair(-9, 50),
        Pair(56, -27), Pair(-11, 24), Pair(-22, 37), Pair(-3, 52), Pair(-11, 60), Pair(-8, 48), Pair(-11, 54), Pair(-3, 52)
      },
      { // Piece 2
        Pair(-7, 35), Pair(36, 12), Pair(-2, 47), Pair(3, 19), Pair(-29, 37), Pair(52, -21), Pair(-31, 51), Pair(-26, 3),
        Pair(13, 28), Pair(6, 33), Pair(15, 19), Pair(27, 30), Pair(22, 4), Pair(-18, 40), Pair(7, 9), Pair(4, 37),
        Pair(11, 19), Pair(20, 15), Pair(32, 22), Pair(8, 16), Pair(21, 27), Pair(11, 16), Pair(18, 25), Pair(-6, 39),
        Pair(5, 24), Pair(11, 41), Pair(19, 12), Pair(4, 39), Pair(5, 22), Pair(5, 34), Pair(-2, 27), Pair(1, 44),
        Pair(2, 31), Pair(34, 37), Pair(2, 39), Pair(9, 29), Pair(1, 43), Pair(7, 31), Pair(15, 40), Pair(5, 28),
        Pair(0, 0), Pair(19, 31), Pair(5, 33), Pair(7, 37), Pair(4, 37), Pair(7, 44), Pair(8, 36), Pair(3, 45),
        Pair(16, 37), Pair(4, 24), Pair(11, 37), Pair(-1, 39), Pair(7, 48), Pair(4, 39), Pair(4, 50), Pair(5, 36),
        Pair(4, 14), Pair(5, 22), Pair(-5, 32), Pair(12, 37), Pair(2, 39), Pair(-1, 54), Pair(5, 25), Pair(10, 43)
      },
      { // Piece 3
        Pair(-22, 53), Pair(-22, 79), Pair(-11, 71), Pair(-26, 73), Pair(-34, 73), Pair(19, 63), Pair(-36, 86), Pair(-14, 74),
        Pair(-32, 55), Pair(-17, 75), Pair(-9, 67), Pair(-8, 69), Pair(-10, 77), Pair(-14, 71), Pair(-3, 70), Pair(0, 71),
        Pair(-40, 56), Pair(-1, 64), Pair(-8, 68), Pair(-8, 73), Pair(-3, 66), Pair(-16, 76), Pair(-6, 64), Pair(-22, 75),
        Pair(-39, 65), Pair(-4, 71), Pair(-2, 72), Pair(4, 67), Pair(2, 68), Pair(-7, 76), Pair(-11, 77), Pair(1, 72),
        Pair(-30, 48), Pair(4, 80), Pair(-3, 80), Pair(2, 75), Pair(-3, 71), Pair(-6, 71), Pair(-11, 66), Pair(-13, 72),
        Pair(0, 0), Pair(-5, 77), Pair(11, 69), Pair(1, 67), Pair(-4, 75), Pair(-4, 71), Pair(-9, 73), Pair(-5, 69),
        Pair(-45, 46), Pair(-4, 62), Pair(5, 59), Pair(-3, 68), Pair(5, 65), Pair(-11, 71), Pair(-4, 65), Pair(9, 68),
        Pair(-26, 34), Pair(-8, 65), Pair(-4, 71), Pair(-3, 66), Pair(-3, 68), Pair(-5, 63), Pair(-9, 65), Pair(-3, 58)
      },
      { // Piece 4
        Pair(1, 117), Pair(-7, 110), Pair(-21, 122), Pair(-40, 140), Pair(-10, 117), Pair(-3, 114), Pair(-3, 107), Pair(-13, 115),
        Pair(-24, 115), Pair(1, 110), Pair(1, 114), Pair(25, 87), Pair(0, 118), Pair(12, 88), Pair(24, 104), Pair(34, 66),
        Pair(-7, 116), Pair(1, 106), Pair(-2, 120), Pair(-5, 111), Pair(11, 99), Pair(1, 132), Pair(20, 96), Pair(0, 119),
        Pair(2, 106), Pair(-3, 126), Pair(0, 121), Pair(9, 106), Pair(20, 95), Pair(3, 110), Pair(10, 115), Pair(7, 103),
        Pair(-12, 130), Pair(10, 125), Pair(11, 116), Pair(14, 118), Pair(5, 127), Pair(3, 121), Pair(12, 105), Pair(30, 93),
        Pair(0, 0), Pair(12, 121), Pair(6, 120), Pair(8, 120), Pair(11, 135), Pair(11, 118), Pair(12, 113), Pair(28, 81),
        Pair(-5, 108), Pair(17, 109), Pair(11, 116), Pair(11, 117), Pair(10, 124), Pair(14, 126), Pair(16, 115), Pair(18, 86),
        Pair(10, 74), Pair(10, 105), Pair(6, 123), Pair(9, 117), Pair(17, 115), Pair(10, 142), Pair(-2, 116), Pair(32, 63)
      },
      { // Piece 5
        Pair(-36, 34), Pair(93, 44), Pair(20, 26), Pair(24, 30), Pair(-56, 9), Pair(-86, 9), Pair(23, 11), Pair(-110, -67),
        Pair(-114, 29), Pair(-64, 83), Pair(101, 32), Pair(-11, 27), Pair(40, 16), Pair(-9, 28), Pair(-37, 17), Pair(-73, -8),
        Pair(-57, 7), Pair(-28, 60), Pair(-13, 40), Pair(-70, 44), Pair(-197, 54), Pair(29, -1), Pair(-90, 19), Pair(-79, 8),
        Pair(-57, 29), Pair(-2, 42), Pair(12, 25), Pair(-47, 49), Pair(-59, 25), Pair(-46, 14), Pair(-48, 14), Pair(-88, 14),
        Pair(-54, -1), Pair(-28, 7), Pair(-22, 37), Pair(-36, 36), Pair(-54, 32), Pair(-9, 10), Pair(-31, 15), Pair(-43, 8),
        Pair(0, 0), Pair(-6, 10), Pair(-1, 14), Pair(-22, 18), Pair(-14, 14), Pair(-22, 16), Pair(-24, 11), Pair(-45, 9),
        Pair(16, -41), Pair(21, -21), Pair(11, 1), Pair(3, 7), Pair(-4, 9), Pair(-19, 13), Pair(-18, 8), Pair(-11, -7),
        Pair(59, -71), Pair(90, -17), Pair(49, -11), Pair(-6, -1), Pair(6, -9), Pair(-7, 1), Pair(-8, -3), Pair(-9, -13)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 19), Pair(-26, 18), Pair(-32, 24), Pair(3, 6), Pair(-7, 13), Pair(3, 9), Pair(-2, 11), Pair(-7, 9),
        Pair(-10, 18), Pair(-8, 10), Pair(-8, 9), Pair(-7, 11), Pair(-4, 7), Pair(2, 6), Pair(-5, 11), Pair(2, 10),
        Pair(-3, 14), Pair(5, 12), Pair(-2, 13), Pair(5, 12), Pair(3, 6), Pair(4, 6), Pair(-2, 13), Pair(-2, 9),
        Pair(0, 3), Pair(-2, 1), Pair(2, 6), Pair(4, 7), Pair(1, 9), Pair(7, 14), Pair(3, 14), Pair(-1, 13),
        Pair(-2, 4), Pair(-9, 7), Pair(1, 7), Pair(-3, 11), Pair(0, 14), Pair(1, 15), Pair(2, 13), Pair(1, 15),
        Pair(2, 18), Pair(6, -4), Pair(7, 24), Pair(1, 15), Pair(0, 13), Pair(-1, 16), Pair(2, 19), Pair(0, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-48, 61), Pair(-68, 61), Pair(-23, 36), Pair(0, 42), Pair(-52, 58), Pair(-74, 47), Pair(-107, 50), Pair(-92, 82),
        Pair(-7, 35), Pair(-25, 50), Pair(-27, 61), Pair(-19, 53), Pair(-23, 49), Pair(-12, 41), Pair(4, 50), Pair(-19, 30),
        Pair(-23, 44), Pair(-21, 49), Pair(-4, 46), Pair(-26, 59), Pair(-27, 67), Pair(-20, 44), Pair(-17, 61), Pair(-19, 55),
        Pair(-18, 47), Pair(-14, 46), Pair(1, 48), Pair(-8, 57), Pair(-9, 51), Pair(-13, 66), Pair(-15, 55), Pair(-10, 54),
        Pair(4, 38), Pair(-8, 46), Pair(-6, 39), Pair(0, 54), Pair(-6, 54), Pair(5, 57), Pair(-12, 54), Pair(0, 43),
        Pair(-16, 52), Pair(0, 0), Pair(-2, 47), Pair(5, 56), Pair(2, 56), Pair(-4, 57), Pair(-7, 57), Pair(0, 46),
        Pair(-15, 69), Pair(15, 81), Pair(-2, 60), Pair(-7, 45), Pair(-5, 54), Pair(-3, 58), Pair(2, 54), Pair(-7, 54),
        Pair(26, -22), Pair(-11, 33), Pair(-18, 49), Pair(-13, 54), Pair(-9, 64), Pair(-1, 53), Pair(-2, 52), Pair(39, 7)
      },
      { // Piece 2
        Pair(15, 18), Pair(-37, 43), Pair(2, 24), Pair(3, 35), Pair(-18, 6), Pair(-1, 22), Pair(-14, 20), Pair(-13, 38),
        Pair(-1, 47), Pair(-9, 31), Pair(8, 46), Pair(29, 10), Pair(-10, 32), Pair(28, 4), Pair(-10, 37), Pair(-17, 24),
        Pair(-15, 29), Pair(15, 44), Pair(16, 18), Pair(2, 37), Pair(7, 15), Pair(11, 19), Pair(17, 9), Pair(-11, 39),
        Pair(0, 37), Pair(-4, 26), Pair(11, 30), Pair(4, 24), Pair(-1, 23), Pair(3, 21), Pair(-2, 33), Pair(-12, 34),
        Pair(-58, -3), Pair(-6, 39), Pair(-8, 34), Pair(-2, 31), Pair(4, 31), Pair(4, 40), Pair(0, 41), Pair(0, 34),
        Pair(2, 34), Pair(0, 0), Pair(7, 32), Pair(-6, 31), Pair(0, 48), Pair(3, 37), Pair(1, 48), Pair(-6, 46),
        Pair(-51, -40), Pair(1, 56), Pair(-6, 22), Pair(0, 45), Pair(-5, 42), Pair(4, 52), Pair(-2, 41), Pair(1, 53),
        Pair(1, 26), Pair(-12, 26), Pair(-2, 30), Pair(-1, 26), Pair(-4, 46), Pair(-5, 47), Pair(1, 35), Pair(-2, 29)
      },
      { // Piece 3
        Pair(-34, 68), Pair(-29, 50), Pair(-42, 79), Pair(-17, 65), Pair(-29, 83), Pair(-13, 56), Pair(-35, 77), Pair(-3, 57),
        Pair(-27, 66), Pair(-36, 48), Pair(-12, 60), Pair(-9, 61), Pair(-6, 61), Pair(-11, 61), Pair(-51, 83), Pair(-13, 64),
        Pair(-8, 68), Pair(-22, 56), Pair(-26, 71), Pair(-2, 67), Pair(-6, 65), Pair(-23, 67), Pair(3, 57), Pair(-6, 62),
        Pair(-9, 62), Pair(-41, 71), Pair(-12, 59), Pair(15, 58), Pair(-7, 68), Pair(0, 56), Pair(-9, 65), Pair(-12, 73),
        Pair(-10, 67), Pair(-41, 60), Pair(3, 66), Pair(-1, 68), Pair(-2, 66), Pair(-5, 66), Pair(-14, 62), Pair(-8, 60),
        Pair(-3, 39), Pair(0, 0), Pair(-5, 67), Pair(-3, 68), Pair(-3, 68), Pair(-11, 71), Pair(-23, 72), Pair(-13, 69),
        Pair(-13, 68), Pair(-27, 31), Pair(-3, 72), Pair(2, 64), Pair(-3, 66), Pair(-9, 63), Pair(-11, 71), Pair(-25, 61),
        Pair(-10, 51), Pair(-20, 28), Pair(-12, 62), Pair(-6, 60), Pair(-9, 64), Pair(-6, 62), Pair(-4, 57), Pair(-9, 66)
      },
      { // Piece 4
        Pair(-27, 120), Pair(9, 83), Pair(-33, 103), Pair(-30, 92), Pair(-49, 132), Pair(-34, 127), Pair(-1, 84), Pair(4, 94),
        Pair(-15, 95), Pair(-10, 81), Pair(-11, 93), Pair(6, 90), Pair(-12, 87), Pair(9, 66), Pair(4, 66), Pair(-16, 101),
        Pair(-3, 74), Pair(-3, 80), Pair(4, 79), Pair(-1, 79), Pair(-2, 91), Pair(-15, 111), Pair(0, 89), Pair(-16, 84),
        Pair(-5, 94), Pair(1, 83), Pair(-14, 87), Pair(-8, 97), Pair(-14, 94), Pair(-7, 80), Pair(1, 87), Pair(-3, 93),
        Pair(-20, 100), Pair(-6, 72), Pair(-1, 98), Pair(-3, 93), Pair(2, 102), Pair(-7, 103), Pair(10, 73), Pair(10, 66),
        Pair(-8, 52), Pair(0, 0), Pair(1, 103), Pair(4, 93), Pair(3, 99), Pair(4, 107), Pair(4, 93), Pair(0, 89),
        Pair(-4, 109), Pair(-1, 76), Pair(4, 82), Pair(7, 100), Pair(5, 98), Pair(5, 100), Pair(14, 85), Pair(1, 108),
        Pair(4, 66), Pair(-1, 83), Pair(2, 98), Pair(6, 86), Pair(3, 88), Pair(-2, 112), Pair(-2, 101), Pair(7, 64)
      },
      { // Piece 5
        Pair(54, 62), Pair(24, 47), Pair(34, 59), Pair(-18, -4), Pair(39, -9), Pair(-3, 16), Pair(-71, -16), Pair(-30, 6),
        Pair(99, 27), Pair(45, 42), Pair(-23, 60), Pair(160, 11), Pair(58, 31), Pair(8, 24), Pair(-17, 14), Pair(-116, 17),
        Pair(-74, 84), Pair(54, 34), Pair(15, 43), Pair(60, 35), Pair(-118, 47), Pair(-29, 33), Pair(52, -2), Pair(-64, 14),
        Pair(47, 48), Pair(94, 5), Pair(28, 46), Pair(3, 30), Pair(-68, 37), Pair(-52, 23), Pair(-28, 13), Pair(-40, 9),
        Pair(15, 16), Pair(12, 7), Pair(14, 8), Pair(6, 30), Pair(-7, 25), Pair(-22, 18), Pair(-16, 14), Pair(-67, 15),
        Pair(12, 20), Pair(0, 0), Pair(-7, 19), Pair(6, 21), Pair(-4, 17), Pair(-2, 9), Pair(-17, 10), Pair(-30, 8),
        Pair(61, -4), Pair(33, -13), Pair(2, 13), Pair(12, 8), Pair(5, 10), Pair(-11, 13), Pair(-12, 9), Pair(-11, -3),
        Pair(60, -27), Pair(61, -27), Pair(42, -4), Pair(9, -3), Pair(0, 5), Pair(-14, 6), Pair(-8, -3), Pair(-13, -13)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 19), Pair(-43, 21), Pair(-25, 9), Pair(-2, 12), Pair(-9, 17), Pair(3, -5), Pair(9, 5), Pair(11, -1),
        Pair(-4, 13), Pair(-12, 22), Pair(0, -7), Pair(-8, 12), Pair(-2, 7), Pair(4, 4), Pair(10, -2), Pair(0, 7),
        Pair(3, 10), Pair(-2, 11), Pair(3, -1), Pair(-1, 15), Pair(8, 6), Pair(8, 7), Pair(0, 5), Pair(-2, 7),
        Pair(2, 10), Pair(7, 11), Pair(-9, -13), Pair(10, 18), Pair(3, 9), Pair(3, 8), Pair(-1, 13), Pair(0, 9),
        Pair(-5, 8), Pair(1, 9), Pair(-7, -3), Pair(1, 18), Pair(-8, 9), Pair(3, 12), Pair(2, 14), Pair(0, 15),
        Pair(0, 10), Pair(11, 31), Pair(-5, -20), Pair(6, 29), Pair(-3, 8), Pair(-2, 17), Pair(-1, 14), Pair(2, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(23, 15), Pair(-128, 91), Pair(-28, 61), Pair(1, 30), Pair(-10, 28), Pair(-18, 17), Pair(7, 14), Pair(7, -31),
        Pair(-14, 48), Pair(2, 50), Pair(-15, 38), Pair(-24, 54), Pair(6, 35), Pair(-1, 43), Pair(-15, 31), Pair(-35, 28),
        Pair(-6, 21), Pair(2, 42), Pair(-5, 50), Pair(5, 41), Pair(-7, 45), Pair(-1, 46), Pair(3, 39), Pair(-18, 62),
        Pair(-4, 46), Pair(-8, 51), Pair(2, 38), Pair(18, 39), Pair(1, 46), Pair(4, 44), Pair(-2, 49), Pair(-3, 53),
        Pair(-13, 35), Pair(14, 46), Pair(7, 41), Pair(8, 51), Pair(2, 51), Pair(6, 49), Pair(-5, 35), Pair(5, 38),
        Pair(-3, 42), Pair(5, 48), Pair(0, 0), Pair(4, 53), Pair(14, 48), Pair(4, 50), Pair(5, 44), Pair(7, 42),
        Pair(-1, -7), Pair(-1, 46), Pair(3, 72), Pair(8, 56), Pair(0, 43), Pair(8, 53), Pair(9, 52), Pair(2, 48),
        Pair(11, 41), Pair(-1, 18), Pair(-17, 44), Pair(-1, 46), Pair(1, 49), Pair(13, 44), Pair(2, 32), Pair(27, 27)
      },
      { // Piece 2
        Pair(45, 21), Pair(-26, 15), Pair(27, 13), Pair(29, -8), Pair(24, 22), Pair(44, -10), Pair(52, 18), Pair(-79, 38),
        Pair(-2, 30), Pair(10, 40), Pair(0, 8), Pair(45, 19), Pair(21, 6), Pair(31, 18), Pair(-16, -2), Pair(22, 15),
        Pair(7, 24), Pair(8, 12), Pair(22, 18), Pair(14, 5), Pair(18, 19), Pair(-5, 9), Pair(42, 1), Pair(-2, 12),
        Pair(-6, 8), Pair(23, 19), Pair(11, 16), Pair(20, 37), Pair(2, 9), Pair(12, 15), Pair(4, 18), Pair(15, 30),
        Pair(19, 27), Pair(11, 17), Pair(14, 28), Pair(24, 18), Pair(9, 32), Pair(6, 19), Pair(17, 37), Pair(5, 23),
        Pair(-2, 9), Pair(16, 38), Pair(0, 0), Pair(16, 24), Pair(2, 25), Pair(15, 34), Pair(13, 25), Pair(3, 55),
        Pair(19, 3), Pair(-15, -47), Pair(25, 41), Pair(-4, 16), Pair(11, 41), Pair(4, 31), Pair(9, 47), Pair(6, 39),
        Pair(-30, -96), Pair(16, 1), Pair(1, 16), Pair(17, 32), Pair(-13, 12), Pair(13, 45), Pair(15, 21), Pair(11, 51)
      },
      { // Piece 3
        Pair(-27, 71), Pair(-19, 56), Pair(1, 33), Pair(-24, 61), Pair(-7, 52), Pair(-35, 65), Pair(-19, 60), Pair(25, 54),
        Pair(-4, 56), Pair(1, 54), Pair(-8, 39), Pair(-18, 58), Pair(-10, 56), Pair(-7, 49), Pair(-7, 52), Pair(-3, 59),
        Pair(-8, 59), Pair(-3, 55), Pair(-2, 36), Pair(-16, 62), Pair(-13, 59), Pair(-25, 64), Pair(26, 39), Pair(7, 46),
        Pair(2, 57), Pair(-3, 54), Pair(12, 44), Pair(6, 49), Pair(12, 52), Pair(2, 49), Pair(-8, 58), Pair(2, 58),
        Pair(4, 51), Pair(5, 58), Pair(-14, 49), Pair(5, 63), Pair(7, 55), Pair(-3, 59), Pair(2, 52), Pair(0, 63),
        Pair(-4, 36), Pair(1, 32), Pair(0, 0), Pair(-1, 49), Pair(7, 48), Pair(-5, 53), Pair(-1, 53), Pair(10, 52),
        Pair(-20, 66), Pair(-1, 53), Pair(-11, 27), Pair(1, 57), Pair(4, 52), Pair(0, 48), Pair(0, 57), Pair(-5, 65),
        Pair(1, 52), Pair(1, 52), Pair(-5, 23), Pair(2, 52), Pair(2, 52), Pair(0, 49), Pair(6, 52), Pair(4, 54)
      },
      { // Piece 4
        Pair(14, 81), Pair(-27, 111), Pair(-36, 90), Pair(-31, 99), Pair(-35, 102), Pair(45, 54), Pair(40, 43), Pair(3, 56),
        Pair(3, 61), Pair(-1, 55), Pair(-23, 68), Pair(12, 73), Pair(4, 56), Pair(5, 55), Pair(-8, 69), Pair(12, 65),
        Pair(-11, 80), Pair(-4, 73), Pair(-5, 69), Pair(-3, 76), Pair(-9, 70), Pair(-28, 89), Pair(1, 71), Pair(-14, 82),
        Pair(-3, 62), Pair(3, 79), Pair(-5, 61), Pair(5, 70), Pair(3, 74), Pair(-5, 76), Pair(-9, 82), Pair(-4, 79),
        Pair(5, 75), Pair(-1, 67), Pair(-2, 66), Pair(8, 87), Pair(-6, 99), Pair(-9, 88), Pair(7, 77), Pair(10, 68),
        Pair(4, 13), Pair(13, 32), Pair(0, 0), Pair(7, 85), Pair(5, 86), Pair(4, 77), Pair(10, 82), Pair(-7, 124),
        Pair(8, 46), Pair(2, 57), Pair(2, 67), Pair(7, 69), Pair(5, 88), Pair(2, 85), Pair(19, 63), Pair(8, 68),
        Pair(7, 42), Pair(7, 68), Pair(5, 51), Pair(4, 76), Pair(5, 72), Pair(16, 86), Pair(5, 57), Pair(33, 22)
      },
      { // Piece 5
        Pair(-52, -59), Pair(37, 118), Pair(-75, 56), Pair(-165, 24), Pair(42, 91), Pair(9, 39), Pair(-22, -53), Pair(26, -60),
        Pair(85, 19), Pair(35, 38), Pair(79, 25), Pair(-33, 67), Pair(-12, 48), Pair(0, 18), Pair(33, 5), Pair(65, -23),
        Pair(-113, 57), Pair(4, 44), Pair(-103, 61), Pair(-28, 47), Pair(46, 34), Pair(-61, 27), Pair(84, -20), Pair(21, -1),
        Pair(69, 2), Pair(-63, 47), Pair(5, 27), Pair(20, 26), Pair(-5, 16), Pair(-64, 29), Pair(-28, 8), Pair(-30, 3),
        Pair(30, 13), Pair(-55, 1), Pair(34, -1), Pair(-10, 2), Pair(-23, 18), Pair(-6, 6), Pair(-3, -2), Pair(-34, -4),
        Pair(-6, 22), Pair(3, 16), Pair(0, 0), Pair(-22, 18), Pair(-17, 10), Pair(1, -1), Pair(-16, 3), Pair(-6, -4),
        Pair(35, -18), Pair(-5, 2), Pair(-23, 12), Pair(-20, 7), Pair(0, 0), Pair(-2, 0), Pair(-7, -7), Pair(-3, -12),
        Pair(30, -17), Pair(-19, -1), Pair(-16, -4), Pair(-22, -1), Pair(3, -3), Pair(-9, -11), Pair(-1, -12), Pair(-2, -20)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 10), Pair(-21, 11), Pair(-32, 28), Pair(-2, 8), Pair(1, 6), Pair(14, 3), Pair(10, -8), Pair(11, -2),
        Pair(0, 3), Pair(-9, 11), Pair(-8, 15), Pair(-6, 10), Pair(-8, 11), Pair(4, 12), Pair(-8, 11), Pair(-1, 3),
        Pair(0, 8), Pair(4, 14), Pair(-4, 15), Pair(11, 6), Pair(5, 18), Pair(11, 11), Pair(-6, 11), Pair(-2, 11),
        Pair(0, 9), Pair(0, 14), Pair(5, 19), Pair(6, -2), Pair(11, 12), Pair(4, 8), Pair(1, 8), Pair(-4, 11),
        Pair(-3, 10), Pair(-4, 9), Pair(0, 18), Pair(4, -13), Pair(2, 21), Pair(-5, 9), Pair(2, 12), Pair(-2, 11),
        Pair(-2, 14), Pair(-7, 7), Pair(10, 33), Pair(-4, -10), Pair(11, 39), Pair(-5, 15), Pair(-3, 11), Pair(0, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(26, -30), Pair(-20, 46), Pair(-45, 46), Pair(-88, 69), Pair(62, 28), Pair(-62, 85), Pair(-33, 110), Pair(-72, 67),
        Pair(1, 30), Pair(-8, 39), Pair(-25, 51), Pair(-11, 42), Pair(-85, 88), Pair(-29, 60), Pair(0, 39), Pair(-16, 26),
        Pair(-32, 40), Pair(-21, 39), Pair(1, 44), Pair(-35, 54), Pair(-16, 53), Pair(-53, 60), Pair(-20, 41), Pair(-13, 22),
        Pair(-14, 52), Pair(-16, 44), Pair(-10, 41), Pair(-24, 52), Pair(-13, 50), Pair(-1, 38), Pair(-17, 57), Pair(-21, 50),
        Pair(-4, 30), Pair(0, 36), Pair(-6, 41), Pair(-6, 42), Pair(1, 38), Pair(-8, 42), Pair(-17, 53), Pair(-9, 56),
        Pair(-2, 22), Pair(2, 34), Pair(-8, 45), Pair(0, 0), Pair(-1, 46), Pair(3, 55), Pair(-11, 61), Pair(-4, 57),
        Pair(-4, 31), Pair(-12, 9), Pair(2, 42), Pair(-2, 69), Pair(-2, 51), Pair(-6, 34), Pair(-12, 41), Pair(-5, 42),
        Pair(28, 38), Pair(-5, 29), Pair(-14, 15), Pair(-6, 23), Pair(-9, 37), Pair(0, 39), Pair(-2, 47), Pair(-2, 43)
      },
      { // Piece 2
        Pair(-4, 6), Pair(25, 26), Pair(-19, 15), Pair(-23, 40), Pair(82, -22), Pair(2, 17), Pair(23, -42), Pair(-89, 54),
        Pair(-9, 37), Pair(-8, 24), Pair(0, 33), Pair(19, 8), Pair(1, 17), Pair(-1, -4), Pair(-8, 9), Pair(-4, 4),
        Pair(-15, 4), Pair(2, 14), Pair(1, 19), Pair(3, 34), Pair(-5, 11), Pair(-20, 27), Pair(7, -14), Pair(-16, 48),
        Pair(-2, 23), Pair(-16, 1), Pair(-3, 25), Pair(-14, 15), Pair(0, 30), Pair(8, -11), Pair(-1, 25), Pair(-9, 16),
        Pair(-10, 2), Pair(5, 23), Pair(-14, 18), Pair(-11, 23), Pair(21, 27), Pair(-1, 34), Pair(-9, 17), Pair(-9, 30),
        Pair(-3, 34), Pair(-7, 10), Pair(1, 27), Pair(0, 0), Pair(-1, 36), Pair(-7, 20), Pair(-4, 48), Pair(-11, 18),
        Pair(12, -2), Pair(-5, 32), Pair(-15, -19), Pair(8, 43), Pair(-6, 0), Pair(3, 38), Pair(-11, 32), Pair(-4, 51),
        Pair(-2, 31), Pair(-46, -25), Pair(-2, 28), Pair(1, -1), Pair(4, 8), Pair(-13, -24), Pair(3, 22), Pair(-16, 36)
      },
      { // Piece 3
        Pair(-11, 56), Pair(-2, 50), Pair(-34, 54), Pair(25, 22), Pair(-6, 44), Pair(-61, 58), Pair(9, 38), Pair(15, 44),
        Pair(-8, 46), Pair(-15, 50), Pair(-25, 48), Pair(-3, 34), Pair(-31, 52), Pair(6, 37), Pair(-23, 47), Pair(-17, 41),
        Pair(-2, 51), Pair(-5, 46), Pair(-24, 65), Pair(2, 36), Pair(-47, 66), Pair(-19, 53), Pair(-34, 56), Pair(-11, 47),
        Pair(-2, 50), Pair(4, 48), Pair(-8, 50), Pair(11, 35), Pair(-17, 42), Pair(3, 48), Pair(-24, 46), Pair(14, 47),
        Pair(-7, 48), Pair(-4, 43), Pair(2, 52), Pair(11, 25), Pair(-1, 52), Pair(-6, 50), Pair(3, 43), Pair(-2, 49),
        Pair(1, 26), Pair(-8, 32), Pair(-7, 36), Pair(0, 0), Pair(-7, 37), Pair(2, 29), Pair(-17, 42), Pair(-5, 23),
        Pair(-13, 52), Pair(0, 41), Pair(-5, 39), Pair(-13, 15), Pair(-1, 45), Pair(-7, 42), Pair(-14, 37), Pair(2, 39),
        Pair(-3, 38), Pair(-2, 42), Pair(-7, 46), Pair(4, 1), Pair(-7, 40), Pair(-6, 42), Pair(-10, 43), Pair(-1, 37)
      },
      { // Piece 4
        Pair(-8, 70), Pair(-9, 84), Pair(-20, 80), Pair(-36, 76), Pair(-28, 99), Pair(-3, 57), Pair(15, 26), Pair(-12, 88),
        Pair(-12, 81), Pair(-12, 78), Pair(-2, 60), Pair(-7, 76), Pair(-30, 75), Pair(-25, 82), Pair(-2, 68), Pair(-1, 47),
        Pair(-19, 72), Pair(-10, 74), Pair(-5, 53), Pair(-11, 48), Pair(-12, 63), Pair(-11, 84), Pair(-17, 75), Pair(-20, 86),
        Pair(7, 54), Pair(-14, 74), Pair(-11, 82), Pair(-15, 76), Pair(-11, 78), Pair(2, 53), Pair(-15, 73), Pair(-9, 82),
        Pair(6, 67), Pair(0, 72), Pair(6, 41), Pair(-12, 86), Pair(3, 76), Pair(-9, 78), Pair(-1, 66), Pair(-1, 76),
        Pair(-7, 39), Pair(4, 23), Pair(5, 48), Pair(0, 0), Pair(6, 60), Pair(-1, 73), Pair(-3, 80), Pair(0, 59),
        Pair(5, 66), Pair(10, 49), Pair(1, 35), Pair(3, 45), Pair(-1, 66), Pair(4, 68), Pair(8, 73), Pair(-13, 106),
        Pair(10, 33), Pair(1, 41), Pair(1, 58), Pair(2, 43), Pair(4, 66), Pair(4, 57), Pair(14, 90), Pair(-8, 69)
      },
      { // Piece 5
        Pair(-8, -12), Pair(37, 148), Pair(5, 5), Pair(34, 65), Pair(27, -23), Pair(19, -6), Pair(15, -37), Pair(4, -10),
        Pair(12, 72), Pair(-105, 96), Pair(20, 46), Pair(-48, 58), Pair(-29, 64), Pair(40, 14), Pair(98, 0), Pair(-93, -9),
        Pair(-70, 30), Pair(57, 20), Pair(-33, 35), Pair(-22, 23), Pair(90, -4), Pair(86, -11), Pair(-66, 12), Pair(-26, 10),
        Pair(-137, 42), Pair(88, 1), Pair(-84, 39), Pair(-44, 27), Pair(26, 12), Pair(0, 4), Pair(-87, 26), Pair(-45, -8),
        Pair(75, -18), Pair(-39, 14), Pair(-64, -10), Pair(-28, 8), Pair(-10, -21), Pair(5, -10), Pair(16, -9), Pair(-38, 9),
        Pair(14, -25), Pair(-24, 17), Pair(-24, 15), Pair(0, 0), Pair(-52, 20), Pair(-23, 1), Pair(3, -13), Pair(-12, -8),
        Pair(-3, -12), Pair(-8, -3), Pair(-40, 3), Pair(-88, 18), Pair(-33, -14), Pair(-18, -11), Pair(-4, -15), Pair(3, -20),
        Pair(-11, -14), Pair(-11, -7), Pair(-35, -9), Pair(-75, 10), Pair(-19, -21), Pair(0, -20), Pair(-3, -20), Pair(-4, -24)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, 13), Pair(-12, 15), Pair(-8, 7), Pair(0, 2), Pair(-2, 4), Pair(-25, 17), Pair(-7, 11), Pair(4, 2),
        Pair(-1, 9), Pair(0, 9), Pair(-1, 3), Pair(-12, 19), Pair(5, 1), Pair(-9, 13), Pair(1, 8), Pair(0, 2),
        Pair(-1, 9), Pair(0, 8), Pair(0, 10), Pair(0, 17), Pair(8, 4), Pair(3, 11), Pair(-3, 9), Pair(0, 7),
        Pair(-1, 17), Pair(0, 13), Pair(-1, 10), Pair(11, 21), Pair(4, -2), Pair(13, 8), Pair(1, 12), Pair(2, 3),
        Pair(1, 12), Pair(1, 15), Pair(-8, 7), Pair(2, 24), Pair(3, -12), Pair(10, 12), Pair(-6, 7), Pair(5, 11),
        Pair(-2, 16), Pair(-3, 14), Pair(-2, 7), Pair(14, 32), Pair(3, -11), Pair(18, 32), Pair(0, 9), Pair(7, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-16, 18), Pair(63, 36), Pair(-33, 45), Pair(17, 29), Pair(-25, 46), Pair(-30, 37), Pair(162, -24), Pair(-10, -11),
        Pair(-6, 32), Pair(-8, 39), Pair(-7, 40), Pair(-40, 50), Pair(-27, 36), Pair(-15, 26), Pair(-11, 43), Pair(-20, 17),
        Pair(8, 30), Pair(-10, 40), Pair(-6, 35), Pair(-13, 45), Pair(-36, 51), Pair(1, 37), Pair(-25, 39), Pair(-42, 59),
        Pair(0, 42), Pair(-8, 46), Pair(1, 44), Pair(-13, 41), Pair(-17, 44), Pair(-14, 42), Pair(-17, 45), Pair(-26, 54),
        Pair(0, 40), Pair(-2, 36), Pair(-4, 38), Pair(6, 51), Pair(-13, 44), Pair(-9, 45), Pair(-17, 28), Pair(-12, 35),
        Pair(-9, 39), Pair(4, 49), Pair(-3, 50), Pair(1, 44), Pair(0, 0), Pair(-6, 42), Pair(-5, 47), Pair(-5, 37),
        Pair(-2, 55), Pair(-4, 42), Pair(-19, 33), Pair(0, 44), Pair(1, 70), Pair(7, 50), Pair(-20, 7), Pair(-12, 43),
        Pair(-12, 25), Pair(0, 41), Pair(1, 35), Pair(-11, 48), Pair(-4, 33), Pair(-8, 29), Pair(-13, 22), Pair(-8, 43)
      },
      { // Piece 2
        Pair(-19, 16), Pair(40, -8), Pair(9, 9), Pair(26, -4), Pair(19, 18), Pair(35, -3), Pair(10, 11), Pair(-18, 6),
        Pair(-36, 4), Pair(-10, 21), Pair(6, -2), Pair(20, 14), Pair(-9, 7), Pair(5, 15), Pair(-32, 18), Pair(-14, 18),
        Pair(2, 16), Pair(-5, 7), Pair(6, 22), Pair(-17, 8), Pair(-3, 23), Pair(-37, 19), Pair(-2, 17), Pair(-58, 20),
        Pair(-10, 9), Pair(8, 17), Pair(-6, 6), Pair(5, 17), Pair(-19, 8), Pair(8, 21), Pair(-23, 4), Pair(2, 22),
        Pair(2, 18), Pair(-6, 13), Pair(0, 24), Pair(6, 7), Pair(-3, 26), Pair(-18, 0), Pair(6, 20), Pair(-20, 10),
        Pair(-19, 14), Pair(-1, 27), Pair(-12, 17), Pair(1, 32), Pair(0, 0), Pair(3, 29), Pair(-18, 24), Pair(-2, 34),
        Pair(0, 23), Pair(-17, 18), Pair(-8, 38), Pair(-22, 0), Pair(8, 48), Pair(-23, -10), Pair(-2, 40), Pair(-5, 15),
        Pair(0, 21), Pair(-1, 35), Pair(-29, -16), Pair(11, 21), Pair(-10, 9), Pair(-11, 32), Pair(-17, -29), Pair(8, 17)
      },
      { // Piece 3
        Pair(3, 43), Pair(13, 41), Pair(3, 42), Pair(-2, 38), Pair(-26, 38), Pair(-37, 56), Pair(10, 55), Pair(10, 34),
        Pair(-10, 48), Pair(-12, 44), Pair(-13, 51), Pair(-8, 41), Pair(-3, 28), Pair(-39, 53), Pair(-14, 48), Pair(0, 37),
        Pair(-8, 52), Pair(-2, 49), Pair(-11, 47), Pair(-19, 53), Pair(-7, 36), Pair(-33, 59), Pair(-5, 40), Pair(-2, 45),
        Pair(-4, 47), Pair(7, 41), Pair(9, 42), Pair(0, 40), Pair(2, 30), Pair(-1, 32), Pair(-15, 56), Pair(-2, 50),
        Pair(-3, 42), Pair(2, 39), Pair(5, 39), Pair(7, 49), Pair(11, 22), Pair(1, 41), Pair(-12, 51), Pair(4, 37),
        Pair(-7, 35), Pair(-6, 42), Pair(7, 27), Pair(-14, 36), Pair(0, 0), Pair(-12, 33), Pair(-29, 34), Pair(-11, 19),
        Pair(-12, 49), Pair(0, 46), Pair(5, 41), Pair(-3, 42), Pair(-7, 14), Pair(-15, 40), Pair(-7, 33), Pair(-5, 47),
        Pair(-1, 38), Pair(0, 41), Pair(-1, 39), Pair(-3, 44), Pair(-5, 9), Pair(-11, 37), Pair(-11, 38), Pair(2, 35)
      },
      { // Piece 4
        Pair(28, 50), Pair(-26, 95), Pair(-29, 94), Pair(-22, 84), Pair(3, 61), Pair(48, 30), Pair(-73, 148), Pair(-57, 124),
        Pair(-9, 68), Pair(-4, 78), Pair(-5, 77), Pair(-10, 96), Pair(4, 50), Pair(-8, 72), Pair(-23, 83), Pair(-15, 81),
        Pair(-4, 77), Pair(-5, 72), Pair(-9, 80), Pair(-14, 92), Pair(-15, 71), Pair(-42, 84), Pair(-13, 87), Pair(-36, 80),
        Pair(-7, 101), Pair(-4, 78), Pair(-5, 69), Pair(-11, 81), Pair(-8, 66), Pair(-16, 82), Pair(-13, 72), Pair(-14, 63),
        Pair(-2, 85), Pair(4, 78), Pair(-3, 75), Pair(3, 69), Pair(-6, 78), Pair(-22, 97), Pair(-12, 78), Pair(-16, 83),
        Pair(9, 52), Pair(9, 58), Pair(6, 63), Pair(3, 67), Pair(0, 0), Pair(-2, 67), Pair(-12, 72), Pair(-15, 86),
        Pair(5, 87), Pair(5, 67), Pair(10, 66), Pair(-2, 72), Pair(2, 66), Pair(-2, 58), Pair(14, 69), Pair(-11, 96),
        Pair(6, 63), Pair(4, 84), Pair(-1, 52), Pair(0, 72), Pair(-1, 57), Pair(3, 80), Pair(1, 92), Pair(7, 84)
      },
      { // Piece 5
        Pair(53, 25), Pair(-32, -8), Pair(-63, 49), Pair(9, 73), Pair(-62, 2), Pair(-40, 56), Pair(-48, 14), Pair(26, -33),
        Pair(16, -13), Pair(-81, 33), Pair(-198, 32), Pair(-54, 28), Pair(77, 51), Pair(14, 32), Pair(33, 3), Pair(-8, 27),
        Pair(-30, 25), Pair(12, 17), Pair(-47, 33), Pair(96, 7), Pair(3, 52), Pair(12, 34), Pair(-91, 38), Pair(84, -3),
        Pair(23, 1), Pair(-95, 26), Pair(0, 10), Pair(26, 19), Pair(-45, 31), Pair(22, 11), Pair(3, 4), Pair(-18, 11),
        Pair(36, -9), Pair(-49, 13), Pair(4, 5), Pair(-9, -12), Pair(9, -1), Pair(16, -21), Pair(44, -1), Pair(0, -2),
        Pair(-48, 16), Pair(-8, -3), Pair(-22, 10), Pair(-56, 18), Pair(0, 0), Pair(-37, 5), Pair(3, -2), Pair(4, -13),
        Pair(11, -6), Pair(-15, 9), Pair(-8, -1), Pair(-23, 0), Pair(-53, 19), Pair(-25, -2), Pair(7, -16), Pair(6, -12),
        Pair(1, -24), Pair(-7, -10), Pair(4, -15), Pair(-21, 2), Pair(-29, -3), Pair(-37, -2), Pair(7, -14), Pair(5, -28)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(16, 3), Pair(1, 7), Pair(-4, 5), Pair(13, 3), Pair(-9, 10), Pair(-36, 4), Pair(41, -4), Pair(2, 8),
        Pair(3, 9), Pair(3, 12), Pair(7, 8), Pair(-2, 12), Pair(4, 12), Pair(2, 5), Pair(4, 11), Pair(0, 7),
        Pair(3, 11), Pair(7, 11), Pair(7, 8), Pair(5, 7), Pair(0, 16), Pair(8, 7), Pair(3, 7), Pair(6, 4),
        Pair(1, 15), Pair(5, 12), Pair(1, 8), Pair(3, 12), Pair(16, 11), Pair(0, -1), Pair(18, 3), Pair(6, 3),
        Pair(0, 14), Pair(2, 15), Pair(1, 12), Pair(-5, 9), Pair(10, 14), Pair(5, -1), Pair(15, 4), Pair(-3, 6),
        Pair(1, 16), Pair(4, 12), Pair(-1, 13), Pair(-5, 15), Pair(15, 19), Pair(5, -4), Pair(15, 21), Pair(-3, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(4, 18), Pair(33, -17), Pair(-38, 37), Pair(70, 11), Pair(11, 50), Pair(53, 27), Pair(-7, 47), Pair(-93, -2),
        Pair(1, 30), Pair(9, 33), Pair(3, 28), Pair(30, 25), Pair(30, 23), Pair(16, 34), Pair(28, 28), Pair(1, 24),
        Pair(-3, 41), Pair(11, 40), Pair(29, 32), Pair(7, 44), Pair(31, 33), Pair(-11, 52), Pair(22, 35), Pair(-4, 31),
        Pair(10, 30), Pair(17, 40), Pair(21, 36), Pair(11, 39), Pair(26, 36), Pair(13, 32), Pair(4, 43), Pair(-6, 43),
        Pair(17, 31), Pair(26, 38), Pair(25, 32), Pair(19, 45), Pair(33, 35), Pair(8, 44), Pair(-13, 46), Pair(-18, 37),
        Pair(13, 35), Pair(17, 43), Pair(13, 44), Pair(33, 35), Pair(17, 41), Pair(0, 0), Pair(8, 44), Pair(4, 35),
        Pair(8, 32), Pair(2, 47), Pair(18, 42), Pair(10, 31), Pair(19, 40), Pair(12, 60), Pair(3, 55), Pair(-1, 2),
        Pair(9, 41), Pair(-4, 42), Pair(8, 51), Pair(-5, 47), Pair(12, 31), Pair(6, 31), Pair(-2, 13), Pair(23, 15)
      },
      { // Piece 2
        Pair(20, -8), Pair(-1, 26), Pair(-35, 22), Pair(29, 6), Pair(79, 6), Pair(54, 14), Pair(5, 8), Pair(-29, 43),
        Pair(11, 22), Pair(-29, 11), Pair(31, 12), Pair(42, -14), Pair(29, 11), Pair(-3, 7), Pair(64, 8), Pair(4, 0),
        Pair(18, 4), Pair(41, 6), Pair(9, 8), Pair(35, 15), Pair(27, 1), Pair(12, 19), Pair(10, 4), Pair(3, 23),
        Pair(24, 16), Pair(24, 1), Pair(21, 22), Pair(26, 13), Pair(31, 24), Pair(18, 1), Pair(18, 29), Pair(-19, 19),
        Pair(20, 10), Pair(33, 18), Pair(16, 7), Pair(27, 25), Pair(46, 16), Pair(19, 17), Pair(2, 26), Pair(14, 22),
        Pair(12, 40), Pair(11, 21), Pair(31, 30), Pair(13, 18), Pair(24, 34), Pair(0, 0), Pair(27, 30), Pair(-2, 11),
        Pair(5, 23), Pair(22, 36), Pair(14, 21), Pair(14, 33), Pair(11, 16), Pair(31, 44), Pair(-18, -13), Pair(29, 31),
        Pair(26, 20), Pair(12, 14), Pair(17, 42), Pair(-13, 17), Pair(22, 23), Pair(2, 14), Pair(23, 17), Pair(-17, -111)
      },
      { // Piece 3
        Pair(24, 44), Pair(35, 36), Pair(40, 35), Pair(57, 30), Pair(34, 41), Pair(58, 25), Pair(58, 31), Pair(51, 32),
        Pair(15, 46), Pair(24, 43), Pair(28, 33), Pair(46, 31), Pair(26, 37), Pair(57, 12), Pair(33, 37), Pair(34, 33),
        Pair(18, 42), Pair(32, 39), Pair(22, 41), Pair(18, 43), Pair(29, 37), Pair(50, 20), Pair(32, 35), Pair(39, 41),
        Pair(26, 44), Pair(34, 35), Pair(30, 35), Pair(32, 35), Pair(15, 43), Pair(40, 26), Pair(17, 38), Pair(30, 43),
        Pair(25, 37), Pair(5, 53), Pair(25, 41), Pair(12, 52), Pair(30, 48), Pair(38, 15), Pair(16, 58), Pair(8, 50),
        Pair(12, 39), Pair(22, 36), Pair(18, 40), Pair(18, 36), Pair(16, 43), Pair(0, 0), Pair(20, 20), Pair(10, 11),
        Pair(17, 47), Pair(24, 36), Pair(18, 39), Pair(18, 41), Pair(21, 40), Pair(20, 16), Pair(-5, 50), Pair(14, 43),
        Pair(22, 35), Pair(23, 40), Pair(20, 39), Pair(23, 36), Pair(20, 41), Pair(17, 17), Pair(8, 42), Pair(22, 36)
      },
      { // Piece 4
        Pair(11, 59), Pair(27, 48), Pair(38, 55), Pair(-3, 80), Pair(-5, 94), Pair(0, 72), Pair(38, 48), Pair(-9, 62),
        Pair(0, 85), Pair(-4, 74), Pair(-27, 97), Pair(9, 72), Pair(-8, 87), Pair(16, 21), Pair(-18, 82), Pair(-8, 73),
        Pair(-13, 95), Pair(7, 66), Pair(6, 51), Pair(-23, 96), Pair(3, 75), Pair(-15, 75), Pair(5, 59), Pair(-21, 87),
        Pair(-8, 90), Pair(0, 97), Pair(2, 91), Pair(-8, 86), Pair(-8, 94), Pair(15, 50), Pair(-4, 77), Pair(-21, 74),
        Pair(9, 64), Pair(3, 90), Pair(5, 84), Pair(-9, 96), Pair(14, 74), Pair(-18, 87), Pair(-9, 79), Pair(-11, 76),
        Pair(-6, 100), Pair(16, 69), Pair(8, 78), Pair(7, 76), Pair(-2, 74), Pair(0, 0), Pair(-12, 73), Pair(-9, 27),
        Pair(14, 74), Pair(7, 71), Pair(13, 75), Pair(13, 73), Pair(6, 70), Pair(-2, 54), Pair(9, 54), Pair(-6, 88),
        Pair(6, 83), Pair(6, 88), Pair(-1, 83), Pair(7, 68), Pair(1, 80), Pair(7, 17), Pair(23, 56), Pair(-1, 55)
      },
      { // Piece 5
        Pair(-81, -21), Pair(-24, 19), Pair(139, 10), Pair(37, 37), Pair(74, 20), Pair(84, 35), Pair(-62, 5), Pair(61, -37),
        Pair(-19, -16), Pair(-63, 21), Pair(49, 11), Pair(144, 13), Pair(22, 43), Pair(99, 24), Pair(-4, 40), Pair(-164, 45),
        Pair(-1, -11), Pair(-50, 9), Pair(-75, 26), Pair(-106, 51), Pair(120, 19), Pair(51, 39), Pair(-47, 34), Pair(74, -2),
        Pair(-41, 3), Pair(-54, 12), Pair(-94, 18), Pair(-53, 21), Pair(-31, 28), Pair(1, 17), Pair(13, 15), Pair(-6, 3),
        Pair(-95, 11), Pair(-33, 11), Pair(-40, 20), Pair(-56, 21), Pair(-68, 4), Pair(-17, 2), Pair(4, -30), Pair(38, -2),
        Pair(-51, -4), Pair(-35, 5), Pair(-17, 4), Pair(-26, 14), Pair(-12, 1), Pair(0, 0), Pair(14, -11), Pair(24, -6),
        Pair(-22, 3), Pair(-1, -13), Pair(11, -8), Pair(-8, 3), Pair(-20, 3), Pair(-71, 23), Pair(-8, -8), Pair(22, -11),
        Pair(3, -24), Pair(7, -15), Pair(2, -18), Pair(-5, -11), Pair(-15, -3), Pair(-49, 13), Pair(1, -4), Pair(29, -16)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 8), Pair(11, 12), Pair(-2, 13), Pair(-16, 8), Pair(-7, 1), Pair(-14, 6), Pair(3, -8), Pair(-11, 5),
        Pair(0, 16), Pair(2, 10), Pair(6, 13), Pair(-3, 11), Pair(-7, 13), Pair(3, 9), Pair(-11, 1), Pair(7, 12),
        Pair(0, 11), Pair(0, 11), Pair(1, 9), Pair(-1, 4), Pair(4, 10), Pair(-2, 10), Pair(12, -5), Pair(5, 11),
        Pair(0, 16), Pair(3, 17), Pair(5, 14), Pair(2, 8), Pair(7, 14), Pair(16, 6), Pair(5, -11), Pair(10, -1),
        Pair(0, 19), Pair(2, 17), Pair(1, 11), Pair(3, 13), Pair(-1, 11), Pair(16, 5), Pair(1, 6), Pair(3, 4),
        Pair(-3, 17), Pair(1, 19), Pair(-3, 13), Pair(3, 12), Pair(-2, 11), Pair(18, 21), Pair(-9, -11), Pair(4, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(35, -3), Pair(5, 26), Pair(40, 46), Pair(57, 11), Pair(-45, 59), Pair(30, 19), Pair(5, 38), Pair(70, -42),
        Pair(-7, 33), Pair(-9, 36), Pair(4, 39), Pair(8, 47), Pair(19, 38), Pair(15, 26), Pair(-22, 47), Pair(14, 18),
        Pair(-10, 52), Pair(0, 45), Pair(8, 40), Pair(0, 48), Pair(5, 36), Pair(5, 36), Pair(-8, 42), Pair(15, 23),
        Pair(-5, 40), Pair(5, 42), Pair(4, 44), Pair(10, 46), Pair(9, 42), Pair(10, 36), Pair(13, 43), Pair(-15, 43),
        Pair(-6, 39), Pair(10, 46), Pair(3, 52), Pair(7, 53), Pair(12, 40), Pair(10, 35), Pair(11, 34), Pair(1, 19),
        Pair(0, 35), Pair(5, 43), Pair(2, 43), Pair(6, 49), Pair(7, 48), Pair(8, 45), Pair(0, 0), Pair(-6, 55),
        Pair(-28, 38), Pair(-8, 43), Pair(-6, 45), Pair(3, 47), Pair(-8, 46), Pair(6, 40), Pair(-5, 58), Pair(-18, 46),
        Pair(-43, 50), Pair(-11, 43), Pair(-15, 48), Pair(-13, 59), Pair(-5, 40), Pair(-4, 31), Pair(7, 21), Pair(-61, 18)
      },
      { // Piece 2
        Pair(32, 30), Pair(-7, 23), Pair(-2, 25), Pair(19, -4), Pair(42, 6), Pair(52, 8), Pair(22, 26), Pair(7, 5),
        Pair(17, 9), Pair(13, 24), Pair(-8, 19), Pair(46, 14), Pair(20, 11), Pair(18, 17), Pair(-5, 33), Pair(4, 21),
        Pair(-1, 30), Pair(16, 11), Pair(20, 24), Pair(0, 15), Pair(14, 25), Pair(9, 12), Pair(2, 26), Pair(-14, 23),
        Pair(0, 21), Pair(15, 28), Pair(19, 19), Pair(15, 30), Pair(-2, 21), Pair(18, 24), Pair(5, 20), Pair(0, 33),
        Pair(5, 34), Pair(1, 22), Pair(10, 35), Pair(2, 25), Pair(18, 29), Pair(-3, 20), Pair(11, 27), Pair(-33, -37),
        Pair(-5, 25), Pair(-5, 41), Pair(2, 27), Pair(7, 39), Pair(0, 30), Pair(16, 30), Pair(0, 0), Pair(11, 33),
        Pair(5, 32), Pair(-5, 26), Pair(3, 44), Pair(-5, 29), Pair(7, 41), Pair(9, 17), Pair(19, 52), Pair(-43, -75),
        Pair(0, 27), Pair(12, 31), Pair(-5, 29), Pair(-6, 43), Pair(-8, 18), Pair(11, 24), Pair(11, 13), Pair(17, 0)
      },
      { // Piece 3
        Pair(22, 57), Pair(29, 54), Pair(34, 49), Pair(23, 50), Pair(12, 53), Pair(22, 63), Pair(66, 33), Pair(12, 57),
        Pair(20, 51), Pair(15, 59), Pair(27, 45), Pair(39, 48), Pair(43, 44), Pair(12, 50), Pair(38, 31), Pair(12, 50),
        Pair(18, 57), Pair(27, 49), Pair(23, 56), Pair(25, 46), Pair(19, 53), Pair(7, 56), Pair(52, 31), Pair(-3, 63),
        Pair(10, 59), Pair(30, 53), Pair(20, 48), Pair(28, 46), Pair(32, 54), Pair(3, 48), Pair(20, 42), Pair(-7, 61),
        Pair(10, 56), Pair(14, 58), Pair(9, 60), Pair(25, 47), Pair(23, 54), Pair(19, 59), Pair(31, 32), Pair(-10, 64),
        Pair(12, 51), Pair(5, 56), Pair(13, 55), Pair(9, 56), Pair(16, 50), Pair(6, 59), Pair(0, 0), Pair(-27, 43),
        Pair(5, 59), Pair(26, 46), Pair(6, 60), Pair(13, 56), Pair(10, 57), Pair(3, 61), Pair(-3, 24), Pair(-16, 57),
        Pair(15, 49), Pair(16, 50), Pair(20, 51), Pair(14, 50), Pair(16, 51), Pair(12, 54), Pair(-1, 15), Pair(-4, 45)
      },
      { // Piece 4
        Pair(23, 73), Pair(21, 62), Pair(22, 71), Pair(29, 65), Pair(44, 58), Pair(14, 94), Pair(82, 21), Pair(88, 15),
        Pair(22, 66), Pair(2, 70), Pair(18, 58), Pair(24, 72), Pair(21, 72), Pair(34, 62), Pair(43, 16), Pair(52, 30),
        Pair(3, 92), Pair(22, 90), Pair(23, 72), Pair(15, 71), Pair(16, 94), Pair(32, 44), Pair(26, 81), Pair(-8, 86),
        Pair(17, 71), Pair(14, 83), Pair(15, 84), Pair(15, 83), Pair(20, 64), Pair(0, 101), Pair(4, 83), Pair(6, 86),
        Pair(23, 68), Pair(27, 82), Pair(23, 92), Pair(9, 83), Pair(12, 84), Pair(5, 78), Pair(13, 80), Pair(-5, 72),
        Pair(30, 55), Pair(25, 88), Pair(19, 81), Pair(18, 83), Pair(11, 82), Pair(14, 79), Pair(0, 0), Pair(-4, 29),
        Pair(23, 80), Pair(20, 102), Pair(21, 98), Pair(17, 88), Pair(25, 78), Pair(16, 56), Pair(3, 77), Pair(-7, 66),
        Pair(17, 99), Pair(10, 107), Pair(16, 98), Pair(14, 100), Pair(10, 92), Pair(12, 103), Pair(22, 44), Pair(-20, 101)
      },
      { // Piece 5
        Pair(-40, 40), Pair(-16, -14), Pair(-59, 13), Pair(-11, -8), Pair(-83, 30), Pair(-181, 69), Pair(-46, 37), Pair(-103, 49),
        Pair(-86, -13), Pair(-144, 35), Pair(-118, 30), Pair(-112, 49), Pair(-71, 51), Pair(-142, 55), Pair(29, 60), Pair(-31, 46),
        Pair(-89, 24), Pair(-11, 12), Pair(-58, 21), Pair(-71, 33), Pair(-42, 43), Pair(-3, 43), Pair(28, 52), Pair(-103, 57),
        Pair(-13, -4), Pair(-89, 23), Pair(-92, 30), Pair(-70, 34), Pair(-28, 28), Pair(10, 26), Pair(0, 35), Pair(-21, 39),
        Pair(-31, 8), Pair(-6, 8), Pair(-9, 16), Pair(-55, 31), Pair(-26, 27), Pair(-31, 2), Pair(4, 13), Pair(-39, 1),
        Pair(-84, 15), Pair(-43, 15), Pair(-12, 15), Pair(-5, 13), Pair(-12, 17), Pair(-4, -1), Pair(0, 0), Pair(-2, -15),
        Pair(-45, 6), Pair(-49, 15), Pair(-19, 5), Pair(-24, 13), Pair(-2, 3), Pair(-29, 1), Pair(1, -7), Pair(-14, -13),
        Pair(-52, -2), Pair(-41, 2), Pair(-34, 9), Pair(-15, -4), Pair(11, -10), Pair(-15, 2), Pair(13, -7), Pair(-31, -8)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 15), Pair(-4, 17), Pair(11, 4), Pair(14, 5), Pair(-15, 12), Pair(-8, -1), Pair(-10, 14), Pair(15, 11),
        Pair(-5, 15), Pair(-2, 19), Pair(5, 11), Pair(1, 7), Pair(-6, 10), Pair(-12, 14), Pair(-15, 19), Pair(17, -5),
        Pair(-4, 16), Pair(1, 11), Pair(2, 11), Pair(3, 8), Pair(-1, 7), Pair(-5, 9), Pair(-2, 13), Pair(15, 4),
        Pair(-4, 14), Pair(3, 16), Pair(1, 15), Pair(0, 10), Pair(0, 8), Pair(0, 6), Pair(13, 4), Pair(2, 10),
        Pair(0, 15), Pair(2, 15), Pair(0, 12), Pair(1, 12), Pair(3, 11), Pair(1, 6), Pair(1, 3), Pair(-2, -10),
        Pair(-2, 15), Pair(-1, 14), Pair(-2, 15), Pair(-1, 12), Pair(0, 17), Pair(-9, 10), Pair(10, 22), Pair(-9, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(33, 14), Pair(28, 24), Pair(-46, 45), Pair(-13, 35), Pair(47, 22), Pair(46, 25), Pair(109, 23), Pair(12, 9),
        Pair(8, 33), Pair(-4, 44), Pair(-13, 30), Pair(10, 37), Pair(7, 38), Pair(7, 41), Pair(-10, 52), Pair(25, 13),
        Pair(-22, 44), Pair(-12, 47), Pair(12, 35), Pair(3, 41), Pair(-2, 47), Pair(13, 39), Pair(7, 34), Pair(5, 23),
        Pair(-16, 48), Pair(2, 37), Pair(5, 43), Pair(5, 48), Pair(7, 38), Pair(12, 34), Pair(13, 37), Pair(0, 35),
        Pair(-12, 47), Pair(-6, 43), Pair(6, 45), Pair(12, 40), Pair(10, 40), Pair(3, 46), Pair(3, 36), Pair(-4, 35),
        Pair(-13, 47), Pair(-8, 43), Pair(-1, 46), Pair(1, 48), Pair(5, 44), Pair(-2, 42), Pair(7, 28), Pair(0, 0),
        Pair(-29, 31), Pair(-21, 45), Pair(-11, 40), Pair(-4, 49), Pair(-1, 40), Pair(-18, 33), Pair(-18, 42), Pair(-12, 43),
        Pair(-56, 57), Pair(-11, 43), Pair(-17, 46), Pair(-13, 44), Pair(-8, 42), Pair(-6, 31), Pair(-9, 23), Pair(-56, 16)
      },
      { // Piece 2
        Pair(36, -8), Pair(16, 14), Pair(-34, 6), Pair(14, 29), Pair(80, -3), Pair(-22, 34), Pair(-68, 32), Pair(-17, 54),
        Pair(5, 33), Pair(-2, 14), Pair(7, 15), Pair(65, -12), Pair(22, 18), Pair(24, 6), Pair(18, 42), Pair(-23, 32),
        Pair(-7, 18), Pair(16, 27), Pair(25, 7), Pair(14, 29), Pair(6, 11), Pair(35, 27), Pair(5, 20), Pair(-3, 39),
        Pair(2, 41), Pair(6, 19), Pair(11, 35), Pair(22, 14), Pair(18, 31), Pair(9, 15), Pair(10, 41), Pair(-2, 25),
        Pair(3, 26), Pair(14, 30), Pair(9, 24), Pair(12, 37), Pair(12, 22), Pair(1, 37), Pair(4, 44), Pair(-2, 36),
        Pair(5, 37), Pair(13, 18), Pair(7, 33), Pair(6, 27), Pair(5, 39), Pair(1, 25), Pair(2, 44), Pair(0, 0),
        Pair(2, 18), Pair(2, 36), Pair(-2, 25), Pair(2, 37), Pair(3, 30), Pair(16, 38), Pair(9, 26), Pair(4, 55),
        Pair(18, 31), Pair(16, 9), Pair(1, 38), Pair(-12, 29), Pair(4, 36), Pair(-2, 23), Pair(23, 20), Pair(2, -7)
      },
      { // Piece 3
        Pair(13, 66), Pair(34, 54), Pair(54, 43), Pair(11, 55), Pair(17, 56), Pair(54, 47), Pair(48, 44), Pair(40, 27),
        Pair(22, 57), Pair(21, 57), Pair(24, 58), Pair(25, 57), Pair(18, 59), Pair(24, 47), Pair(20, 50), Pair(51, 26),
        Pair(11, 61), Pair(17, 64), Pair(23, 55), Pair(29, 58), Pair(12, 56), Pair(29, 55), Pair(15, 57), Pair(31, 35),
        Pair(10, 63), Pair(14, 61), Pair(16, 53), Pair(30, 57), Pair(22, 58), Pair(15, 55), Pair(11, 50), Pair(6, 42),
        Pair(10, 54), Pair(32, 53), Pair(16, 58), Pair(10, 55), Pair(13, 58), Pair(4, 68), Pair(20, 59), Pair(11, 29),
        Pair(9, 61), Pair(9, 55), Pair(11, 51), Pair(-2, 64), Pair(15, 59), Pair(9, 62), Pair(6, 59), Pair(0, 0),
        Pair(7, 59), Pair(1, 60), Pair(16, 53), Pair(8, 59), Pair(13, 59), Pair(-2, 60), Pair(-4, 49), Pair(-66, 44),
        Pair(13, 54), Pair(16, 53), Pair(12, 55), Pair(15, 50), Pair(16, 50), Pair(17, 57), Pair(-8, 60), Pair(-25, 18)
      },
      { // Piece 4
        Pair(49, 73), Pair(20, 86), Pair(44, 53), Pair(21, 81), Pair(21, 85), Pair(8, 105), Pair(-2, 103), Pair(16, 84),
        Pair(13, 86), Pair(6, 100), Pair(12, 85), Pair(23, 68), Pair(7, 87), Pair(28, 78), Pair(20, 78), Pair(30, 76),
        Pair(19, 85), Pair(13, 97), Pair(22, 75), Pair(24, 92), Pair(16, 87), Pair(28, 94), Pair(38, 95), Pair(13, 81),
        Pair(22, 79), Pair(18, 91), Pair(8, 97), Pair(12, 90), Pair(10, 97), Pair(10, 86), Pair(41, 80), Pair(15, 86),
        Pair(16, 97), Pair(21, 91), Pair(11, 104), Pair(15, 95), Pair(14, 93), Pair(8, 97), Pair(25, 84), Pair(8, 81),
        Pair(28, 75), Pair(29, 84), Pair(15, 96), Pair(19, 100), Pair(14, 91), Pair(22, 88), Pair(8, 99), Pair(0, 0),
        Pair(22, 103), Pair(19, 101), Pair(21, 110), Pair(22, 98), Pair(19, 91), Pair(14, 81), Pair(33, 67), Pair(-16, 64),
        Pair(26, 88), Pair(16, 99), Pair(16, 100), Pair(21, 101), Pair(11, 105), Pair(23, 68), Pair(16, 89), Pair(15, 36)
      },
      { // Piece 5
        Pair(-10, -21), Pair(-144, 3), Pair(61, 25), Pair(-55, 24), Pair(-78, 30), Pair(41, 74), Pair(2, 56), Pair(-62, -3),
        Pair(-5, -3), Pair(-5, 19), Pair(-28, 25), Pair(-12, 23), Pair(-120, 64), Pair(117, 33), Pair(0, 60), Pair(-185, 42),
        Pair(-2, 24), Pair(-9, 27), Pair(-72, 30), Pair(16, 17), Pair(-6, 40), Pair(-35, 51), Pair(-55, 61), Pair(-31, 19),
        Pair(-70, 23), Pair(-46, 24), Pair(-96, 38), Pair(-80, 35), Pair(-104, 46), Pair(-16, 32), Pair(7, 26), Pair(-34, 23),
        Pair(-49, 24), Pair(-93, 31), Pair(-67, 38), Pair(-62, 34), Pair(-26, 27), Pair(-2, 20), Pair(9, -9), Pair(-33, -4),
        Pair(-73, 11), Pair(-66, 35), Pair(-38, 26), Pair(-26, 31), Pair(2, 15), Pair(-7, 16), Pair(-44, -8), Pair(0, 0),
        Pair(-42, 9), Pair(-44, 22), Pair(-35, 24), Pair(-49, 24), Pair(-12, 5), Pair(-19, 12), Pair(-29, -12), Pair(-18, -28),
        Pair(-42, -1), Pair(-40, 20), Pair(-37, 20), Pair(-28, 8), Pair(5, -12), Pair(1, -2), Pair(11, -3), Pair(15, -35)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 27), Pair(-16, 25), Pair(-13, 25), Pair(5, 10), Pair(7, 4), Pair(7, 5), Pair(-12, 18), Pair(-23, 20),
        Pair(-3, 22), Pair(-11, 20), Pair(-8, 21), Pair(-4, 16), Pair(-4, 7), Pair(-2, 12), Pair(-11, 9), Pair(-2, 17),
        Pair(5, 16), Pair(-4, 15), Pair(-1, 12), Pair(-4, 13), Pair(1, 8), Pair(2, 15), Pair(-1, 16), Pair(-2, 13),
        Pair(9, 6), Pair(0, 18), Pair(-1, 10), Pair(-3, 10), Pair(0, 10), Pair(0, 11), Pair(0, 15), Pair(-7, 19),
        Pair(-1, 1), Pair(8, 23), Pair(0, 7), Pair(0, 13), Pair(-1, 8), Pair(-2, 15), Pair(1, 18), Pair(-2, 16),
        Pair(-1, 8), Pair(-4, 6), Pair(-8, 11), Pair(1, 12), Pair(-1, 15), Pair(-4, 21), Pair(1, 19), Pair(1, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(11, -30), Pair(-85, 58), Pair(-20, 66), Pair(-89, 70), Pair(-57, 58), Pair(-17, 42), Pair(-78, 48), Pair(-8, 10),
        Pair(0, 35), Pair(-11, 44), Pair(-13, 55), Pair(-12, 59), Pair(-23, 53), Pair(-2, 58), Pair(-17, 71), Pair(-30, 67),
        Pair(-8, 42), Pair(8, 49), Pair(0, 56), Pair(-3, 60), Pair(-10, 51), Pair(-2, 54), Pair(-23, 73), Pair(-11, 60),
        Pair(-11, 60), Pair(4, 55), Pair(-2, 59), Pair(-2, 71), Pair(-2, 58), Pair(2, 61), Pair(-7, 67), Pair(-10, 58),
        Pair(0, 55), Pair(3, 48), Pair(1, 62), Pair(4, 58), Pair(5, 59), Pair(4, 59), Pair(-11, 62), Pair(-2, 56),
        Pair(-16, 42), Pair(7, 49), Pair(4, 56), Pair(3, 57), Pair(0, 65), Pair(1, 56), Pair(3, 61), Pair(-1, 53),
        Pair(0, 0), Pair(1, 55), Pair(-4, 48), Pair(-6, 63), Pair(1, 66), Pair(-4, 63), Pair(0, 61), Pair(-9, 64),
        Pair(41, 38), Pair(-5, 12), Pair(-9, 46), Pair(-3, 62), Pair(-9, 57), Pair(-6, 57), Pair(-13, 57), Pair(-7, 49)
      },
      { // Piece 2
        Pair(5, 50), Pair(34, 16), Pair(13, 26), Pair(-36, 50), Pair(49, 7), Pair(23, 1), Pair(-21, 10), Pair(-36, 28),
        Pair(11, 40), Pair(7, 33), Pair(18, 37), Pair(34, 23), Pair(10, 18), Pair(15, 5), Pair(12, 31), Pair(-2, 27),
        Pair(0, 44), Pair(15, 34), Pair(27, 30), Pair(15, 30), Pair(20, 15), Pair(26, 18), Pair(19, 23), Pair(-4, 57),
        Pair(-2, 48), Pair(8, 47), Pair(5, 34), Pair(7, 38), Pair(-2, 35), Pair(4, 40), Pair(3, 46), Pair(-13, 55),
        Pair(4, 38), Pair(9, 45), Pair(7, 36), Pair(3, 38), Pair(8, 45), Pair(8, 45), Pair(4, 47), Pair(2, 44),
        Pair(-1, 34), Pair(22, 48), Pair(4, 44), Pair(0, 46), Pair(4, 52), Pair(3, 56), Pair(12, 46), Pair(8, 48),
        Pair(0, 0), Pair(3, 46), Pair(5, 47), Pair(0, 53), Pair(3, 53), Pair(3, 49), Pair(7, 56), Pair(9, 45),
        Pair(7, 36), Pair(13, 22), Pair(-2, 51), Pair(15, 46), Pair(-1, 52), Pair(-4, 59), Pair(-11, 61), Pair(1, 53)
      },
      { // Piece 3
        Pair(-49, 67), Pair(-30, 90), Pair(-15, 84), Pair(-2, 82), Pair(-31, 86), Pair(-70, 109), Pair(-44, 97), Pair(-22, 77),
        Pair(-38, 73), Pair(-23, 85), Pair(-15, 82), Pair(-17, 88), Pair(-16, 84), Pair(-23, 91), Pair(-4, 82), Pair(16, 73),
        Pair(-27, 72), Pair(1, 80), Pair(-22, 79), Pair(-23, 92), Pair(4, 75), Pair(-34, 94), Pair(-10, 84), Pair(-11, 82),
        Pair(-28, 82), Pair(-9, 91), Pair(-7, 83), Pair(-8, 87), Pair(-4, 79), Pair(-15, 82), Pair(-15, 82), Pair(-2, 78),
        Pair(-29, 76), Pair(-13, 89), Pair(-1, 80), Pair(1, 83), Pair(-3, 81), Pair(-18, 92), Pair(-14, 85), Pair(-12, 93),
        Pair(-29, 49), Pair(-2, 87), Pair(-4, 81), Pair(-5, 88), Pair(-3, 87), Pair(-15, 85), Pair(-12, 78), Pair(-13, 84),
        Pair(0, 0), Pair(1, 81), Pair(5, 80), Pair(-9, 87), Pair(-4, 86), Pair(-11, 87), Pair(-22, 90), Pair(11, 71),
        Pair(-30, 55), Pair(-11, 81), Pair(-11, 83), Pair(-7, 80), Pair(-9, 82), Pair(-10, 78), Pair(-14, 86), Pair(-5, 65)
      },
      { // Piece 4
        Pair(-2, 141), Pair(3, 121), Pair(-7, 139), Pair(-21, 144), Pair(-19, 133), Pair(10, 145), Pair(-31, 168), Pair(-18, 152),
        Pair(-14, 143), Pair(-7, 138), Pair(5, 122), Pair(21, 117), Pair(10, 110), Pair(1, 151), Pair(17, 122), Pair(3, 127),
        Pair(-14, 155), Pair(-11, 147), Pair(0, 147), Pair(11, 133), Pair(0, 150), Pair(2, 123), Pair(0, 133), Pair(5, 127),
        Pair(-1, 150), Pair(1, 163), Pair(-5, 149), Pair(3, 144), Pair(12, 114), Pair(-2, 140), Pair(5, 134), Pair(2, 135),
        Pair(-4, 149), Pair(16, 133), Pair(11, 141), Pair(5, 154), Pair(6, 152), Pair(11, 145), Pair(3, 148), Pair(25, 125),
        Pair(-16, 151), Pair(14, 135), Pair(5, 145), Pair(12, 155), Pair(16, 150), Pair(14, 151), Pair(10, 143), Pair(27, 101),
        Pair(0, 0), Pair(14, 133), Pair(14, 138), Pair(16, 148), Pair(11, 155), Pair(13, 153), Pair(18, 139), Pair(30, 114),
        Pair(3, 111), Pair(14, 134), Pair(8, 131), Pair(9, 150), Pair(10, 167), Pair(8, 154), Pair(22, 152), Pair(8, 132)
      },
      { // Piece 5
        Pair(-54, 13), Pair(-54, 61), Pair(-65, 53), Pair(51, 13), Pair(55, -32), Pair(84, 19), Pair(-35, 43), Pair(-50, 28),
        Pair(35, 38), Pair(8, 82), Pair(-146, 113), Pair(57, 66), Pair(-108, 48), Pair(105, 8), Pair(-162, 54), Pair(-49, -3),
        Pair(-100, 49), Pair(-57, 74), Pair(-5, 58), Pair(-134, 65), Pair(-77, 59), Pair(-174, 54), Pair(-80, 31), Pair(-167, 38),
        Pair(-80, 39), Pair(-57, 62), Pair(-90, 55), Pair(-116, 53), Pair(-95, 43), Pair(-64, 32), Pair(-75, 26), Pair(-99, 24),
        Pair(-35, 9), Pair(-63, 44), Pair(-54, 40), Pair(-48, 37), Pair(-91, 45), Pair(-49, 26), Pair(-63, 26), Pair(-77, 24),
        Pair(-57, -11), Pair(-44, -5), Pair(-13, 20), Pair(-36, 35), Pair(-30, 27), Pair(-43, 25), Pair(-19, 16), Pair(-63, 20),
        Pair(0, 0), Pair(10, -18), Pair(18, 2), Pair(-5, 8), Pair(-11, 13), Pair(-18, 18), Pair(-12, 12), Pair(-13, -1),
        Pair(19, -78), Pair(57, -41), Pair(53, -15), Pair(-6, 10), Pair(4, -1), Pair(-5, 8), Pair(-9, 6), Pair(-5, -2)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-30, 26), Pair(-25, 25), Pair(-16, 7), Pair(-8, 14), Pair(14, -1), Pair(-1, 10), Pair(4, 4), Pair(-9, 12),
        Pair(-8, 15), Pair(-11, 13), Pair(-16, 14), Pair(-4, 9), Pair(5, 6), Pair(1, 4), Pair(-5, 13), Pair(1, 4),
        Pair(-7, 14), Pair(8, 4), Pair(-3, 14), Pair(3, 13), Pair(2, 9), Pair(5, 11), Pair(-1, 15), Pair(0, 10),
        Pair(-4, 13), Pair(2, 8), Pair(-1, 13), Pair(1, 10), Pair(-1, 14), Pair(2, 13), Pair(2, 14), Pair(1, 14),
        Pair(-2, 17), Pair(2, -9), Pair(8, 26), Pair(1, 13), Pair(-3, 14), Pair(5, 12), Pair(0, 14), Pair(3, 15),
        Pair(-4, 9), Pair(1, 11), Pair(1, 11), Pair(-5, -18), Pair(-2, 16), Pair(1, 16), Pair(-2, 19), Pair(0, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-15, 27), Pair(4, 55), Pair(-17, 63), Pair(-43, 50), Pair(-4, 45), Pair(-75, 44), Pair(5, 15), Pair(-81, 66),
        Pair(-3, 38), Pair(-10, 32), Pair(-6, 44), Pair(-35, 66), Pair(-22, 45), Pair(-15, 50), Pair(-6, 38), Pair(-41, 61),
        Pair(-26, 55), Pair(-13, 56), Pair(-13, 53), Pair(-23, 56), Pair(-25, 57), Pair(-36, 56), Pair(-28, 77), Pair(-25, 52),
        Pair(-2, 42), Pair(-5, 52), Pair(1, 53), Pair(-12, 51), Pair(-7, 55), Pair(-14, 54), Pair(-11, 61), Pair(-9, 44),
        Pair(-5, 47), Pair(3, 47), Pair(3, 49), Pair(1, 48), Pair(-1, 53), Pair(3, 59), Pair(-17, 56), Pair(-5, 53),
        Pair(0, 41), Pair(2, 38), Pair(5, 50), Pair(-1, 57), Pair(4, 57), Pair(-2, 56), Pair(-5, 52), Pair(4, 50),
        Pair(-18, 61), Pair(0, 0), Pair(-3, 57), Pair(-2, 52), Pair(0, 54), Pair(0, 49), Pair(-7, 56), Pair(-5, 56),
        Pair(7, 57), Pair(-9, 79), Pair(-1, 50), Pair(-6, 65), Pair(-9, 58), Pair(-5, 60), Pair(-11, 51), Pair(24, 42)
      },
      { // Piece 2
        Pair(-5, 29), Pair(-9, 34), Pair(8, 37), Pair(-12, 30), Pair(18, 17), Pair(-17, 13), Pair(33, 15), Pair(2, 27),
        Pair(-12, 41), Pair(1, 27), Pair(-10, 33), Pair(11, 28), Pair(5, 15), Pair(10, 19), Pair(-15, 34), Pair(-5, 10),
        Pair(-12, 46), Pair(3, 41), Pair(13, 44), Pair(2, 27), Pair(2, 24), Pair(2, 31), Pair(-1, 26), Pair(-12, 42),
        Pair(-12, 46), Pair(3, 38), Pair(8, 32), Pair(-1, 30), Pair(2, 28), Pair(-3, 38), Pair(-2, 32), Pair(-8, 47),
        Pair(5, 39), Pair(-7, 38), Pair(7, 36), Pair(-3, 36), Pair(5, 33), Pair(5, 41), Pair(6, 37), Pair(-2, 31),
        Pair(-8, 30), Pair(-9, 25), Pair(5, 65), Pair(-5, 41), Pair(-1, 47), Pair(-1, 48), Pair(-1, 41), Pair(-4, 44),
        Pair(3, 34), Pair(0, 0), Pair(5, 45), Pair(-4, 51), Pair(2, 49), Pair(-3, 52), Pair(-3, 49), Pair(4, 44),
        Pair(0, 0), Pair(-3, 57), Pair(-9, 29), Pair(11, 50), Pair(-2, 50), Pair(-7, 55), Pair(12, 38), Pair(6, 31)
      },
      { // Piece 3
        Pair(-40, 74), Pair(-19, 44), Pair(-16, 65), Pair(-33, 71), Pair(-27, 69), Pair(-19, 67), Pair(0, 56), Pair(7, 47),
        Pair(-24, 69), Pair(-19, 48), Pair(-16, 67), Pair(-25, 75), Pair(-29, 68), Pair(-17, 52), Pair(-58, 75), Pair(-15, 58),
        Pair(-5, 65), Pair(-34, 56), Pair(-24, 69), Pair(-3, 63), Pair(-8, 59), Pair(-31, 70), Pair(-32, 69), Pair(-5, 62),
        Pair(-13, 62), Pair(-17, 56), Pair(-7, 63), Pair(-5, 57), Pair(1, 57), Pair(-8, 63), Pair(-2, 53), Pair(-5, 71),
        Pair(-8, 56), Pair(-15, 57), Pair(-6, 62), Pair(2, 58), Pair(-2, 64), Pair(-12, 65), Pair(-20, 69), Pair(-9, 62),
        Pair(-2, 57), Pair(-23, 46), Pair(-2, 62), Pair(-13, 67), Pair(-8, 67), Pair(-10, 66), Pair(-16, 61), Pair(-6, 63),
        Pair(-19, 37), Pair(0, 0), Pair(-4, 65), Pair(0, 70), Pair(-6, 65), Pair(-4, 65), Pair(-8, 66), Pair(-20, 77),
        Pair(-11, 55), Pair(-22, 30), Pair(-10, 68), Pair(-5, 61), Pair(-10, 62), Pair(-8, 57), Pair(0, 50), Pair(-4, 64)
      },
      { // Piece 4
        Pair(-15, 107), Pair(12, 90), Pair(23, 64), Pair(-13, 106), Pair(-8, 108), Pair(24, 90), Pair(-18, 78), Pair(-24, 118),
        Pair(-20, 104), Pair(-9, 101), Pair(-14, 96), Pair(-11, 118), Pair(-12, 106), Pair(-10, 85), Pair(8, 63), Pair(-32, 118),
        Pair(-19, 129), Pair(-13, 101), Pair(-3, 93), Pair(-10, 103), Pair(-3, 91), Pair(-17, 102), Pair(-12, 121), Pair(-24, 96),
        Pair(-20, 133), Pair(7, 93), Pair(-5, 92), Pair(3, 87), Pair(-7, 90), Pair(2, 83), Pair(-6, 96), Pair(0, 88),
        Pair(2, 101), Pair(1, 97), Pair(7, 100), Pair(-2, 104), Pair(4, 99), Pair(-5, 97), Pair(5, 89), Pair(-2, 97),
        Pair(-4, 95), Pair(1, 82), Pair(-1, 120), Pair(6, 104), Pair(4, 110), Pair(3, 104), Pair(1, 108), Pair(-2, 108),
        Pair(-12, 69), Pair(0, 0), Pair(5, 98), Pair(4, 119), Pair(7, 120), Pair(3, 118), Pair(14, 106), Pair(4, 91),
        Pair(2, 81), Pair(7, 64), Pair(0, 112), Pair(4, 104), Pair(4, 120), Pair(2, 106), Pair(-17, 148), Pair(15, 109)
      },
      { // Piece 5
        Pair(-120, 42), Pair(68, 27), Pair(-117, 22), Pair(-51, 9), Pair(46, -50), Pair(-20, 9), Pair(10, 5), Pair(-31, -15),
        Pair(-5, 75), Pair(94, 53), Pair(-50, 58), Pair(44, 21), Pair(47, 28), Pair(-128, 37), Pair(-109, 46), Pair(-145, 43),
        Pair(-243, 88), Pair(-42, 55), Pair(25, 46), Pair(-185, 62), Pair(-43, 57), Pair(-24, 40), Pair(-62, 38), Pair(-3, 15),
        Pair(11, 67), Pair(33, 18), Pair(-5, 48), Pair(-75, 42), Pair(-115, 45), Pair(-102, 35), Pair(-130, 39), Pair(-54, 10),
        Pair(58, 30), Pair(41, 2), Pair(-52, 47), Pair(-55, 32), Pair(-62, 35), Pair(-52, 25), Pair(-30, 16), Pair(-103, 28),
        Pair(6, 1), Pair(12, -6), Pair(-10, 1), Pair(-1, 12), Pair(-8, 17), Pair(0, 8), Pair(-24, 15), Pair(-20, 1),
        Pair(80, -3), Pair(0, 0), Pair(-11, 7), Pair(9, 9), Pair(13, 9), Pair(-9, 11), Pair(-9, 5), Pair(-11, 3),
        Pair(66, -18), Pair(36, -15), Pair(34, -13), Pair(6, 2), Pair(11, 7), Pair(-2, 9), Pair(-5, -3), Pair(-11, -9)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, 17), Pair(-19, 0), Pair(-32, -2), Pair(-14, 2), Pair(-11, 9), Pair(-13, 16), Pair(-12, 21), Pair(-17, 16),
        Pair(-10, 12), Pair(-17, 18), Pair(-11, 3), Pair(-9, 15), Pair(2, -1), Pair(0, 8), Pair(-3, 9), Pair(1, 9),
        Pair(0, 9), Pair(-9, 17), Pair(-1, -4), Pair(-3, 13), Pair(1, 9), Pair(5, 9), Pair(0, 7), Pair(-1, 12),
        Pair(-2, 13), Pair(0, 19), Pair(-3, -11), Pair(1, 16), Pair(0, 10), Pair(2, 13), Pair(-4, 18), Pair(-4, 17),
        Pair(-5, 11), Pair(3, 22), Pair(0, -17), Pair(6, 33), Pair(-6, 6), Pair(-1, 13), Pair(-3, 12), Pair(-3, 12),
        Pair(-7, 11), Pair(1, 11), Pair(1, 4), Pair(0, 18), Pair(-5, 8), Pair(-4, 16), Pair(-4, 16), Pair(-5, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(8, -10), Pair(37, 12), Pair(-13, 47), Pair(60, 27), Pair(-89, 49), Pair(-75, 58), Pair(-106, 71), Pair(-5, 0),
        Pair(-4, 32), Pair(14, 41), Pair(7, 19), Pair(-37, 56), Pair(-23, 42), Pair(19, 31), Pair(-28, 59), Pair(-14, 37),
        Pair(-27, 53), Pair(-1, 50), Pair(-17, 50), Pair(-3, 48), Pair(-5, 41), Pair(-10, 35), Pair(-7, 39), Pair(-18, 38),
        Pair(-4, 43), Pair(-2, 52), Pair(-8, 43), Pair(4, 49), Pair(-15, 56), Pair(-7, 51), Pair(-13, 49), Pair(-11, 59),
        Pair(-2, 45), Pair(10, 38), Pair(-2, 47), Pair(2, 49), Pair(-7, 54), Pair(-1, 41), Pair(-13, 52), Pair(-10, 51),
        Pair(-9, 47), Pair(2, 50), Pair(-5, 34), Pair(0, 50), Pair(4, 56), Pair(-7, 50), Pair(0, 43), Pair(-1, 33),
        Pair(-3, 40), Pair(5, 41), Pair(0, 0), Pair(2, 48), Pair(-3, 41), Pair(-1, 56), Pair(-14, 65), Pair(-9, 49),
        Pair(-2, -27), Pair(-4, 43), Pair(-5, 74), Pair(2, 50), Pair(-12, 46), Pair(-6, 50), Pair(-12, 56), Pair(-13, 46)
      },
      { // Piece 2
        Pair(17, 16), Pair(-15, 44), Pair(19, 12), Pair(34, 18), Pair(-1, 14), Pair(4, 32), Pair(-69, 58), Pair(25, -18),
        Pair(-12, 40), Pair(4, 28), Pair(5, 25), Pair(33, 20), Pair(27, -2), Pair(-5, 10), Pair(-12, 32), Pair(13, -1),
        Pair(7, 30), Pair(12, 38), Pair(1, 40), Pair(4, 28), Pair(4, 15), Pair(8, 23), Pair(5, 24), Pair(-3, 21),
        Pair(0, 33), Pair(8, 28), Pair(6, 37), Pair(8, 27), Pair(1, 28), Pair(-2, 24), Pair(0, 27), Pair(-9, 33),
        Pair(3, 17), Pair(11, 31), Pair(2, 23), Pair(8, 28), Pair(-5, 32), Pair(9, 36), Pair(7, 26), Pair(-5, 31),
        Pair(-6, 44), Pair(7, 28), Pair(2, 20), Pair(4, 53), Pair(-4, 43), Pair(-5, 34), Pair(0, 37), Pair(-7, 37),
        Pair(-3, -11), Pair(2, 53), Pair(0, 0), Pair(2, 47), Pair(-5, 41), Pair(1, 42), Pair(-3, 43), Pair(-2, 65),
        Pair(3, 40), Pair(-71, -110), Pair(1, 61), Pair(-1, 8), Pair(-15, 48), Pair(-9, 42), Pair(-9, 36), Pair(9, 33)
      },
      { // Piece 3
        Pair(-17, 59), Pair(5, 46), Pair(34, 28), Pair(-6, 54), Pair(-31, 64), Pair(31, 38), Pair(6, 48), Pair(0, 47),
        Pair(-6, 47), Pair(-5, 56), Pair(-23, 46), Pair(-14, 56), Pair(-20, 55), Pair(-21, 55), Pair(-33, 58), Pair(5, 37),
        Pair(-26, 70), Pair(-17, 49), Pair(-8, 38), Pair(-12, 47), Pair(-18, 61), Pair(-30, 60), Pair(12, 45), Pair(-6, 53),
        Pair(0, 62), Pair(-4, 49), Pair(-13, 45), Pair(-16, 62), Pair(-6, 49), Pair(-12, 53), Pair(-22, 52), Pair(-14, 60),
        Pair(-1, 47), Pair(11, 45), Pair(11, 41), Pair(-19, 63), Pair(-10, 47), Pair(-10, 46), Pair(-12, 52), Pair(-11, 49),
        Pair(-11, 66), Pair(-5, 68), Pair(-13, 38), Pair(-4, 52), Pair(-8, 54), Pair(-24, 63), Pair(-13, 48), Pair(-19, 61),
        Pair(-20, 37), Pair(-17, 34), Pair(0, 0), Pair(-11, 52), Pair(-16, 57), Pair(-15, 56), Pair(-16, 52), Pair(-25, 62),
        Pair(-16, 52), Pair(-15, 56), Pair(-22, 18), Pair(-12, 54), Pair(-15, 60), Pair(-12, 49), Pair(-5, 52), Pair(-12, 63)
      },
      { // Piece 4
        Pair(27, 63), Pair(-29, 112), Pair(56, 29), Pair(28, 55), Pair(-16, 73), Pair(10, 78), Pair(43, 0), Pair(-22, 73),
        Pair(6, 67), Pair(7, 72), Pair(4, 64), Pair(-2, 65), Pair(3, 52), Pair(14, 13), Pair(-6, 103), Pair(-14, 85),
        Pair(3, 78), Pair(10, 81), Pair(-5, 80), Pair(-8, 102), Pair(-16, 96), Pair(-34, 106), Pair(2, 71), Pair(-12, 100),
        Pair(3, 97), Pair(2, 86), Pair(9, 70), Pair(-2, 80), Pair(-4, 88), Pair(4, 52), Pair(-5, 87), Pair(-18, 92),
        Pair(-3, 83), Pair(12, 82), Pair(2, 88), Pair(-2, 74), Pair(5, 83), Pair(0, 64), Pair(-7, 92), Pair(-4, 65),
        Pair(-2, 65), Pair(-4, 70), Pair(-7, 79), Pair(5, 85), Pair(7, 75), Pair(4, 77), Pair(7, 81), Pair(4, 81),
        Pair(0, 41), Pair(3, 28), Pair(0, 0), Pair(6, 76), Pair(5, 80), Pair(7, 80), Pair(14, 81), Pair(1, 73),
        Pair(4, 58), Pair(-5, 73), Pair(0, 36), Pair(0, 77), Pair(14, 58), Pair(10, 89), Pair(10, 102), Pair(17, 84)
      },
      { // Piece 5
        Pair(19, 126), Pair(49, 107), Pair(21, -47), Pair(-6, -52), Pair(55, -8), Pair(-8, 64), Pair(55, 13), Pair(38, 42),
        Pair(18, 53), Pair(-53, 78), Pair(-148, 62), Pair(-17, 61), Pair(61, 23), Pair(-58, 34), Pair(-31, 35), Pair(-63, 3),
        Pair(-84, 42), Pair(113, 49), Pair(-105, 66), Pair(31, 52), Pair(24, 33), Pair(-67, 25), Pair(-118, 30), Pair(-21, -7),
        Pair(51, 33), Pair(-101, 59), Pair(143, -8), Pair(20, 33), Pair(-122, 34), Pair(-159, 38), Pair(-57, 20), Pair(-89, 13),
        Pair(-58, 13), Pair(27, 26), Pair(15, 7), Pair(-17, 24), Pair(-98, 29), Pair(-29, 16), Pair(-36, 27), Pair(-39, 16),
        Pair(16, 21), Pair(13, -22), Pair(-9, -16), Pair(-30, -12), Pair(-8, 12), Pair(-11, 7), Pair(-15, 4), Pair(-19, -4),
        Pair(57, -4), Pair(39, -6), Pair(0, 0), Pair(-13, 13), Pair(9, -3), Pair(-5, 6), Pair(-13, 2), Pair(-4, -6),
        Pair(35, -14), Pair(6, 0), Pair(-5, 6), Pair(-23, 3), Pair(10, 6), Pair(5, -3), Pair(-1, -7), Pair(-2, -5)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, -6), Pair(-19, 12), Pair(-3, -17), Pair(-44, 19), Pair(-91, 55), Pair(13, -7), Pair(1, 13), Pair(-16, 2),
        Pair(2, 9), Pair(0, 3), Pair(-9, 17), Pair(0, 7), Pair(-5, 16), Pair(15, -2), Pair(-7, 2), Pair(-1, -4),
        Pair(2, 11), Pair(-2, 7), Pair(3, 18), Pair(11, 4), Pair(1, 14), Pair(4, 7), Pair(2, 14), Pair(-2, 12),
        Pair(3, 9), Pair(-2, 13), Pair(0, 13), Pair(12, 1), Pair(4, 17), Pair(0, 13), Pair(0, 15), Pair(-1, 6),
        Pair(3, 12), Pair(0, 15), Pair(8, 33), Pair(-4, -10), Pair(14, 32), Pair(-7, 13), Pair(3, 13), Pair(-1, 11),
        Pair(-1, 10), Pair(-3, -19), Pair(0, 16), Pair(-4, -1), Pair(6, 33), Pair(-3, 7), Pair(-2, 19), Pair(-2, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(29, -16), Pair(-99, -78), Pair(5, -3), Pair(-45, 50), Pair(12, 18), Pair(-2, -28), Pair(-129, 22), Pair(-12, -36),
        Pair(-14, 30), Pair(-6, 1), Pair(-24, 43), Pair(-104, 75), Pair(-84, 78), Pair(-25, 38), Pair(-44, -8), Pair(-35, -7),
        Pair(-39, 34), Pair(3, 15), Pair(-25, 57), Pair(-36, 39), Pair(9, 21), Pair(-39, 52), Pair(-25, 43), Pair(7, 23),
        Pair(-11, 15), Pair(-9, 34), Pair(-12, 29), Pair(-25, 48), Pair(-7, 45), Pair(-21, 35), Pair(-11, 32), Pair(-11, 23),
        Pair(-3, 28), Pair(-13, 39), Pair(-17, 25), Pair(-8, 32), Pair(-3, 30), Pair(-1, 37), Pair(-5, 29), Pair(-9, 44),
        Pair(0, -15), Pair(-1, -3), Pair(-3, 33), Pair(-8, 9), Pair(2, 41), Pair(-2, 34), Pair(-3, 37), Pair(-4, 31),
        Pair(-15, 50), Pair(5, 9), Pair(7, 19), Pair(0, 0), Pair(-4, 35), Pair(-9, 58), Pair(0, 23), Pair(-5, 25),
        Pair(-10, 49), Pair(-15, -8), Pair(13, 7), Pair(9, 25), Pair(-14, 36), Pair(-3, -7), Pair(-8, 22), Pair(10, -18)
      },
      { // Piece 2
        Pair(-19, 5), Pair(-4, -10), Pair(-88, 47), Pair(-116, 23), Pair(-14, -27), Pair(-12, 2), Pair(-44, 6), Pair(11, 28),
        Pair(-14, 6), Pair(9, 14), Pair(-20, 30), Pair(-9, 19), Pair(0, 4), Pair(5, -3), Pair(-1, 34), Pair(-14, -29),
        Pair(-10, 11), Pair(-2, 32), Pair(-2, 16), Pair(11, 6), Pair(9, 32), Pair(-17, -4), Pair(19, -26), Pair(-39, -10),
        Pair(5, -9), Pair(0, 10), Pair(-17, 29), Pair(-14, 37), Pair(-7, 14), Pair(11, 27), Pair(-18, 3), Pair(1, 18),
        Pair(13, 8), Pair(-6, -8), Pair(0, 6), Pair(-9, -2), Pair(7, 30), Pair(-3, 8), Pair(11, 13), Pair(-16, -2),
        Pair(-5, 7), Pair(7, 18), Pair(6, 19), Pair(-17, 5), Pair(-5, 17), Pair(-8, 25), Pair(-18, -6), Pair(-6, 11),
        Pair(12, 20), Pair(-7, 9), Pair(8, 11), Pair(0, 0), Pair(0, 30), Pair(13, -24), Pair(-5, 29), Pair(-17, -65),
        Pair(-14, 19), Pair(-21, 35), Pair(-7, -47), Pair(18, -10), Pair(48, -131), Pair(-7, 36), Pair(-83, 11), Pair(7, 31)
      },
      { // Piece 3
        Pair(16, 25), Pair(13, 15), Pair(-31, 32), Pair(-72, 43), Pair(-24, 29), Pair(74, -7), Pair(-41, 27), Pair(12, 17),
        Pair(-12, 27), Pair(-20, 46), Pair(-8, 20), Pair(-57, 43), Pair(-11, 26), Pair(-39, 40), Pair(-30, 47), Pair(-9, 45),
        Pair(3, 18), Pair(1, 34), Pair(-5, 19), Pair(44, -12), Pair(-14, 11), Pair(-33, 42), Pair(-18, 19), Pair(-24, 47),
        Pair(-4, 22), Pair(14, 28), Pair(-9, 23), Pair(36, -20), Pair(4, 27), Pair(-17, 42), Pair(-11, 46), Pair(7, 39),
        Pair(-9, 36), Pair(-23, 31), Pair(7, 7), Pair(22, -3), Pair(-6, 45), Pair(-16, 15), Pair(16, 27), Pair(-2, 19),
        Pair(-3, 30), Pair(-2, 27), Pair(-19, 56), Pair(8, -16), Pair(-1, 25), Pair(-11, 19), Pair(-7, 30), Pair(-6, 24),
        Pair(-12, 12), Pair(-15, 0), Pair(-9, 11), Pair(0, 0), Pair(-3, -4), Pair(-16, 13), Pair(-13, 24), Pair(-16, 34),
        Pair(-12, 20), Pair(-14, 33), Pair(-20, 34), Pair(-12, -16), Pair(-13, 24), Pair(-15, 26), Pair(-5, 18), Pair(-2, 26)
      },
      { // Piece 4
        Pair(-23, 77), Pair(21, 63), Pair(63, -27), Pair(35, 18), Pair(-79, 104), Pair(78, 67), Pair(-19, 27), Pair(-36, 22),
        Pair(-21, 81), Pair(-16, 64), Pair(-15, 12), Pair(45, -56), Pair(-10, -3), Pair(-20, 40), Pair(-32, 58), Pair(-16, 10),
        Pair(-23, 86), Pair(-20, 47), Pair(4, 21), Pair(-3, -2), Pair(-24, 33), Pair(-27, 70), Pair(-33, 122), Pair(-34, 92),
        Pair(-22, 24), Pair(-4, 30), Pair(-21, 48), Pair(-1, 40), Pair(-20, 52), Pair(-5, 27), Pair(-16, 76), Pair(-16, 71),
        Pair(-7, 26), Pair(-1, -16), Pair(3, 26), Pair(1, 17), Pair(0, 44), Pair(-9, 71), Pair(-1, 31), Pair(-12, 44),
        Pair(3, 21), Pair(3, 11), Pair(2, 10), Pair(-18, 59), Pair(-5, 49), Pair(3, 19), Pair(-4, 18), Pair(-17, 94),
        Pair(0, 11), Pair(15, 3), Pair(2, 13), Pair(0, 0), Pair(4, 33), Pair(-5, 21), Pair(-2, 42), Pair(-32, 147),
        Pair(-15, 27), Pair(13, 7), Pair(1, 13), Pair(0, 8), Pair(1, 20), Pair(11, 1), Pair(-4, 101), Pair(-8, 29)
      },
      { // Piece 5
        Pair(1, 8), Pair(9, 6), Pair(5, 29), Pair(30, 96), Pair(-15, -85), Pair(-27, -120), Pair(-56, -52), Pair(-22, -1),
        Pair(2, 115), Pair(13, 162), Pair(1, 61), Pair(12, 7), Pair(63, 95), Pair(-7, 49), Pair(-10, 23), Pair(-17, 1),
        Pair(-38, 15), Pair(71, -8), Pair(-4, 45), Pair(2, 40), Pair(-76, 65), Pair(-13, 28), Pair(-17, 6), Pair(51, 67),
        Pair(42, -22), Pair(2, 49), Pair(-74, 41), Pair(-9, 16), Pair(50, 44), Pair(-19, 39), Pair(-156, 34), Pair(31, -19),
        Pair(-80, -7), Pair(-25, 8), Pair(4, 8), Pair(-23, 16), Pair(-30, 12), Pair(-92, 20), Pair(5, -3), Pair(-37, 18),
        Pair(-36, 10), Pair(-56, 23), Pair(11, -37), Pair(-97, 13), Pair(-40, -21), Pair(-24, 15), Pair(-22, 8), Pair(-23, -1),
        Pair(42, -21), Pair(18, 7), Pair(-50, 37), Pair(0, 0), Pair(-59, 28), Pair(-2, -6), Pair(8, -9), Pair(9, -17),
        Pair(24, -19), Pair(-4, 12), Pair(-8, 4), Pair(-68, 17), Pair(-16, -7), Pair(1, -11), Pair(13, -21), Pair(2, -18)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-46, 30), Pair(-2, 7), Pair(-5, 18), Pair(-4, 9), Pair(-24, -20), Pair(-41, 39), Pair(-22, 24), Pair(-2, 5),
        Pair(-9, 22), Pair(-3, 7), Pair(-3, 16), Pair(-11, 22), Pair(1, 5), Pair(-25, 30), Pair(-26, 1), Pair(-6, 7),
        Pair(-4, 12), Pair(-1, 13), Pair(-3, 11), Pair(-1, 22), Pair(3, 13), Pair(8, 16), Pair(-9, 8), Pair(0, 10),
        Pair(-3, 14), Pair(-3, 13), Pair(-2, 13), Pair(4, 23), Pair(4, -2), Pair(7, 13), Pair(-4, 15), Pair(1, 10),
        Pair(-3, 11), Pair(-2, 13), Pair(-4, 9), Pair(10, 40), Pair(1, -9), Pair(16, 22), Pair(-1, 12), Pair(-4, 14),
        Pair(-4, 15), Pair(-1, 14), Pair(-5, 8), Pair(6, 34), Pair(-3, 0), Pair(7, 14), Pair(-8, -21), Pair(0, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, 20), Pair(-10, 31), Pair(24, 40), Pair(79, 7), Pair(-43, 61), Pair(-13, 14), Pair(39, -37), Pair(-100, 64),
        Pair(0, -3), Pair(-2, 22), Pair(-12, 34), Pair(-30, 43), Pair(-21, 10), Pair(-40, 43), Pair(23, 48), Pair(-33, 24),
        Pair(14, -10), Pair(-7, 25), Pair(1, 23), Pair(0, 26), Pair(-34, 30), Pair(-21, 39), Pair(-32, 19), Pair(-31, 38),
        Pair(0, 24), Pair(-5, 36), Pair(0, 32), Pair(-7, 24), Pair(-19, 32), Pair(-5, 24), Pair(-15, 30), Pair(-4, 32),
        Pair(5, 33), Pair(-8, 34), Pair(-6, 29), Pair(1, 35), Pair(-4, 27), Pair(-11, 39), Pair(-33, 40), Pair(-12, 20),
        Pair(0, 22), Pair(5, 41), Pair(2, 39), Pair(-2, 35), Pair(-13, 21), Pair(-5, 35), Pair(-4, 29), Pair(-4, 4),
        Pair(-5, 4), Pair(21, 23), Pair(-7, 36), Pair(1, 31), Pair(0, 0), Pair(-1, 30), Pair(-9, 23), Pair(-6, 11),
        Pair(-27, 62), Pair(5, 25), Pair(-7, 12), Pair(2, 49), Pair(-8, 58), Pair(-5, 26), Pair(-7, 2), Pair(-41, -14)
      },
      { // Piece 2
        Pair(-10, 23), Pair(-40, 26), Pair(80, -35), Pair(-33, 17), Pair(-50, 25), Pair(45, 7), Pair(37, 71), Pair(17, 12),
        Pair(0, 2), Pair(-19, 13), Pair(6, 6), Pair(16, -1), Pair(-14, -9), Pair(-3, 11), Pair(-33, 17), Pair(-30, -2),
        Pair(-10, 9), Pair(9, 10), Pair(-5, 16), Pair(-3, 19), Pair(-18, 7), Pair(-59, 57), Pair(2, 6), Pair(-22, -4),
        Pair(-5, 10), Pair(19, 6), Pair(-1, 18), Pair(-4, 9), Pair(-9, 9), Pair(-1, -8), Pair(-5, 17), Pair(-5, 11),
        Pair(4, 27), Pair(11, -3), Pair(16, 8), Pair(3, 20), Pair(-1, 4), Pair(-3, 13), Pair(-16, 15), Pair(-9, 26),
        Pair(0, 26), Pair(31, 2), Pair(-5, 13), Pair(10, 21), Pair(-16, 8), Pair(9, 16), Pair(-11, 20), Pair(-3, 4),
        Pair(-25, -3), Pair(2, 24), Pair(36, -3), Pair(-5, 23), Pair(0, 0), Pair(4, 23), Pair(-8, 13), Pair(8, 27),
        Pair(-6, 28), Pair(13, 2), Pair(-5, 27), Pair(113, -113), Pair(2, 19), Pair(-19, -29), Pair(7, -5), Pair(2, 2)
      },
      { // Piece 3
        Pair(21, 23), Pair(43, 14), Pair(8, 27), Pair(-25, 41), Pair(32, 11), Pair(-56, 47), Pair(-56, 54), Pair(65, 11),
        Pair(0, 40), Pair(-9, 42), Pair(1, 32), Pair(-9, 36), Pair(-1, 22), Pair(-39, 55), Pair(-2, 14), Pair(9, 16),
        Pair(-4, 40), Pair(12, 26), Pair(-2, 37), Pair(-18, 25), Pair(-14, 35), Pair(-1, 10), Pair(18, 18), Pair(-11, 38),
        Pair(-6, 38), Pair(7, 41), Pair(3, 27), Pair(-15, 39), Pair(18, 19), Pair(-23, 31), Pair(-30, 55), Pair(0, 38),
        Pair(-6, 39), Pair(9, 28), Pair(6, 30), Pair(-11, 30), Pair(8, 14), Pair(-3, 36), Pair(-26, 47), Pair(0, 28),
        Pair(-6, 46), Pair(3, 22), Pair(0, 38), Pair(2, 33), Pair(-16, 2), Pair(-5, 50), Pair(-40, 71), Pair(-23, 47),
        Pair(-15, 46), Pair(-2, 25), Pair(0, 22), Pair(-6, 26), Pair(0, 0), Pair(0, -2), Pair(-20, 14), Pair(-11, 26),
        Pair(-4, 26), Pair(-7, 39), Pair(-2, 31), Pair(-6, 25), Pair(-8, -11), Pair(-14, 32), Pair(-19, 39), Pair(-2, 26)
      },
      { // Piece 4
        Pair(-9, 43), Pair(4, 60), Pair(-17, 64), Pair(69, -17), Pair(43, -8), Pair(41, 18), Pair(25, 51), Pair(-95, 120),
        Pair(-18, 70), Pair(-15, 41), Pair(-26, 86), Pair(11, 29), Pair(-11, 26), Pair(-12, 51), Pair(-32, 80), Pair(-32, 29),
        Pair(-8, 57), Pair(8, 55), Pair(-8, 87), Pair(-13, 53), Pair(-14, 56), Pair(-39, 74), Pair(-18, 112), Pair(-56, 94),
        Pair(-2, 36), Pair(-3, 47), Pair(6, 6), Pair(-2, 38), Pair(-8, 46), Pair(-21, 62), Pair(-18, 52), Pair(-18, 56),
        Pair(-8, 64), Pair(4, 32), Pair(-1, 71), Pair(8, 30), Pair(3, 60), Pair(-16, 33), Pair(0, 43), Pair(-14, 42),
        Pair(8, 55), Pair(5, 42), Pair(1, 33), Pair(5, 30), Pair(-13, 58), Pair(1, 53), Pair(-6, 71), Pair(-20, 51),
        Pair(11, 7), Pair(12, 28), Pair(7, 27), Pair(1, 32), Pair(0, 0), Pair(-9, 38), Pair(2, 54), Pair(4, 102),
        Pair(-3, 41), Pair(5, 56), Pair(6, 21), Pair(-1, 25), Pair(5, -8), Pair(-14, 41), Pair(4, 91), Pair(22, 22)
      },
      { // Piece 5
        Pair(13, 94), Pair(-18, -40), Pair(58, 155), Pair(33, 128), Pair(-22, -68), Pair(-6, 39), Pair(-9, -42), Pair(-19, -42),
        Pair(-39, 20), Pair(15, -10), Pair(-7, 40), Pair(-42, -7), Pair(1, -4), Pair(-64, 52), Pair(-21, 69), Pair(-2, -50),
        Pair(-47, -22), Pair(-74, 51), Pair(62, 26), Pair(-131, 65), Pair(0, 36), Pair(-89, 56), Pair(-48, 1), Pair(-10, 12),
        Pair(-28, 7), Pair(47, -3), Pair(-48, 29), Pair(-122, 63), Pair(-24, 34), Pair(-5, 27), Pair(-29, 26), Pair(-4, -7),
        Pair(14, -2), Pair(45, -5), Pair(-3, 13), Pair(-5, 10), Pair(33, 15), Pair(-3, 2), Pair(-16, 7), Pair(-44, 19),
        Pair(-52, 8), Pair(5, -3), Pair(-4, 6), Pair(-30, -7), Pair(-22, -17), Pair(-4, -25), Pair(9, -1), Pair(8, 2),
        Pair(-15, -6), Pair(-30, 18), Pair(14, 1), Pair(-66, 10), Pair(0, 0), Pair(-32, 5), Pair(13, -5), Pair(19, -8),
        Pair(-36, -22), Pair(-18, -7), Pair(-2, -7), Pair(-23, 2), Pair(-45, 10), Pair(-29, 8), Pair(10, -12), Pair(11, 5)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 18), Pair(0, 12), Pair(-10, 12), Pair(0, 12), Pair(-1, 9), Pair(-5, 2), Pair(-12, 18), Pair(4, 5),
        Pair(-2, 17), Pair(0, 17), Pair(-1, 14), Pair(-8, 11), Pair(0, 10), Pair(-11, 16), Pair(-12, 20), Pair(-4, 13),
        Pair(0, 18), Pair(0, 14), Pair(1, 10), Pair(2, 12), Pair(-5, 12), Pair(2, 14), Pair(-6, 15), Pair(2, 10),
        Pair(-2, 15), Pair(2, 16), Pair(-2, 11), Pair(0, 13), Pair(0, 17), Pair(7, 9), Pair(11, 16), Pair(3, 7),
        Pair(-3, 13), Pair(3, 16), Pair(-2, 15), Pair(-2, 11), Pair(8, 31), Pair(2, -4), Pair(18, 19), Pair(1, 15),
        Pair(3, 18), Pair(0, 16), Pair(-4, 17), Pair(-3, 8), Pair(7, 14), Pair(6, -1), Pair(4, 6), Pair(-1, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-10, 43), Pair(42, 32), Pair(10, 46), Pair(17, 32), Pair(37, 42), Pair(3, 29), Pair(38, 26), Pair(-85, 53),
        Pair(-9, 40), Pair(-7, 50), Pair(-3, 54), Pair(15, 43), Pair(-4, 56), Pair(-12, 46), Pair(-31, 58), Pair(-44, 50),
        Pair(-14, 49), Pair(-11, 59), Pair(3, 49), Pair(-12, 52), Pair(-3, 52), Pair(-31, 55), Pair(-13, 47), Pair(-37, 58),
        Pair(0, 43), Pair(-2, 57), Pair(-4, 59), Pair(-20, 66), Pair(0, 51), Pair(-17, 55), Pair(-3, 61), Pair(-23, 54),
        Pair(-5, 53), Pair(4, 54), Pair(0, 53), Pair(8, 56), Pair(-10, 57), Pair(-9, 55), Pair(-22, 56), Pair(-17, 60),
        Pair(-5, 43), Pair(7, 53), Pair(-4, 56), Pair(5, 53), Pair(0, 56), Pair(-8, 46), Pair(1, 57), Pair(-20, 31),
        Pair(-16, 42), Pair(-9, 42), Pair(1, 63), Pair(0, 51), Pair(0, 54), Pair(0, 0), Pair(-21, 70), Pair(-5, 32),
        Pair(-10, 39), Pair(-2, 49), Pair(-2, 51), Pair(-12, 50), Pair(10, 49), Pair(-6, 78), Pair(-11, 51), Pair(-25, -4)
      },
      { // Piece 2
        Pair(13, 34), Pair(-16, 37), Pair(28, 21), Pair(38, 22), Pair(48, 21), Pair(31, 19), Pair(0, 42), Pair(17, 31),
        Pair(-9, 38), Pair(4, 35), Pair(-12, 35), Pair(25, 25), Pair(-5, 24), Pair(-2, 34), Pair(4, 33), Pair(11, 30),
        Pair(10, 30), Pair(9, 28), Pair(12, 28), Pair(2, 34), Pair(17, 36), Pair(-26, 40), Pair(7, 39), Pair(-27, 50),
        Pair(-9, 30), Pair(12, 27), Pair(-3, 40), Pair(6, 40), Pair(-8, 40), Pair(6, 36), Pair(-11, 42), Pair(-3, 36),
        Pair(8, 34), Pair(-7, 38), Pair(7, 33), Pair(-6, 39), Pair(7, 41), Pair(-6, 36), Pair(8, 31), Pair(-14, 33),
        Pair(-11, 46), Pair(3, 39), Pair(-8, 47), Pair(4, 36), Pair(-7, 61), Pair(0, 33), Pair(-7, 34), Pair(-2, 42),
        Pair(4, 37), Pair(-12, 50), Pair(0, 42), Pair(-14, 55), Pair(9, 42), Pair(0, 0), Pair(2, 53), Pair(-12, 22),
        Pair(-11, 45), Pair(1, 44), Pair(-14, 56), Pair(1, 36), Pair(-26, 33), Pair(5, 54), Pair(-44, -51), Pair(3, 28)
      },
      { // Piece 3
        Pair(41, 56), Pair(40, 50), Pair(37, 53), Pair(40, 58), Pair(6, 70), Pair(57, 39), Pair(43, 53), Pair(24, 53),
        Pair(6, 63), Pair(10, 61), Pair(11, 63), Pair(15, 60), Pair(-1, 65), Pair(38, 38), Pair(-2, 62), Pair(25, 62),
        Pair(14, 65), Pair(19, 55), Pair(2, 66), Pair(1, 63), Pair(1, 58), Pair(46, 41), Pair(-3, 66), Pair(11, 57),
        Pair(16, 63), Pair(25, 59), Pair(10, 62), Pair(18, 61), Pair(2, 65), Pair(32, 45), Pair(-18, 71), Pair(16, 62),
        Pair(8, 60), Pair(7, 66), Pair(18, 64), Pair(8, 67), Pair(6, 66), Pair(34, 49), Pair(8, 58), Pair(9, 68),
        Pair(7, 56), Pair(12, 63), Pair(13, 69), Pair(13, 66), Pair(11, 65), Pair(12, 34), Pair(-1, 76), Pair(-4, 61),
        Pair(1, 66), Pair(5, 60), Pair(-3, 68), Pair(-4, 69), Pair(-8, 69), Pair(0, 0), Pair(-24, 35), Pair(-30, 42),
        Pair(5, 62), Pair(5, 68), Pair(2, 68), Pair(3, 62), Pair(-2, 64), Pair(-9, 45), Pair(-15, 59), Pair(1, 59)
      },
      { // Piece 4
        Pair(40, 107), Pair(37, 92), Pair(22, 110), Pair(17, 104), Pair(6, 123), Pair(-2, 137), Pair(-14, 118), Pair(33, 81),
        Pair(-10, 128), Pair(-6, 139), Pair(-19, 127), Pair(2, 123), Pair(-10, 114), Pair(1, 96), Pair(-3, 114), Pair(-29, 160),
        Pair(-8, 144), Pair(-7, 130), Pair(-7, 150), Pair(-20, 141), Pair(-4, 135), Pair(-32, 153), Pair(-4, 143), Pair(-28, 136),
        Pair(-4, 142), Pair(7, 139), Pair(-1, 111), Pair(-5, 129), Pair(-9, 129), Pair(7, 102), Pair(-10, 136), Pair(-9, 133),
        Pair(16, 128), Pair(10, 133), Pair(10, 121), Pair(7, 123), Pair(6, 119), Pair(-10, 115), Pair(5, 118), Pair(-8, 123),
        Pair(17, 111), Pair(16, 128), Pair(6, 112), Pair(16, 107), Pair(11, 118), Pair(-4, 110), Pair(0, 112), Pair(-5, 125),
        Pair(28, 95), Pair(20, 100), Pair(17, 104), Pair(12, 101), Pair(14, 107), Pair(0, 0), Pair(17, 60), Pair(2, 66),
        Pair(13, 114), Pair(6, 140), Pair(11, 117), Pair(14, 116), Pair(4, 95), Pair(9, 65), Pair(12, 90), Pair(-4, 123)
      },
      { // Piece 5
        Pair(-34, -17), Pair(105, 24), Pair(-90, 22), Pair(44, 36), Pair(25, 22), Pair(-39, 35), Pair(-102, 24), Pair(-64, 27),
        Pair(-155, 25), Pair(49, 37), Pair(-107, 81), Pair(21, 34), Pair(-139, 78), Pair(-6, 77), Pair(-151, 92), Pair(-62, 44),
        Pair(-29, 38), Pair(-8, 25), Pair(-46, 31), Pair(-91, 45), Pair(-94, 61), Pair(-55, 72), Pair(-84, 61), Pair(-2, 30),
        Pair(-179, 46), Pair(-81, 34), Pair(-184, 53), Pair(-68, 40), Pair(-35, 45), Pair(-79, 56), Pair(-24, 38), Pair(-36, 25),
        Pair(-97, 13), Pair(-43, 33), Pair(-82, 42), Pair(-65, 32), Pair(-22, 33), Pair(-36, 34), Pair(42, 9), Pair(23, 1),
        Pair(-91, 26), Pair(-27, 31), Pair(-24, 25), Pair(-15, 20), Pair(-31, -1), Pair(-15, -7), Pair(-6, -15), Pair(37, 4),
        Pair(-5, -4), Pair(-9, 10), Pair(2, 4), Pair(-1, 17), Pair(4, -3), Pair(0, 0), Pair(23, -10), Pair(34, 1),
        Pair(0, -6), Pair(-1, -13), Pair(3, 2), Pair(2, 2), Pair(-9, 0), Pair(-46, 23), Pair(8, -1), Pair(26, 2)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 23), Pair(-4, 14), Pair(-8, 12), Pair(-2, 10), Pair(-10, 9), Pair(-4, 8), Pair(12, -8), Pair(-20, 14),
        Pair(-3, 19), Pair(1, 10), Pair(-1, 19), Pair(-2, 11), Pair(-8, 13), Pair(-3, 10), Pair(0, -8), Pair(0, 13),
        Pair(-2, 19), Pair(0, 14), Pair(4, 9), Pair(1, 8), Pair(2, 19), Pair(-5, 13), Pair(4, -5), Pair(0, 13),
        Pair(1, 18), Pair(2, 15), Pair(2, 13), Pair(2, 13), Pair(-1, 11), Pair(3, 15), Pair(4, -2), Pair(4, 17),
        Pair(-1, 13), Pair(-3, 16), Pair(3, 13), Pair(1, 16), Pair(-2, 15), Pair(14, 22), Pair(-8, -7), Pair(13, 21),
        Pair(-2, 17), Pair(2, 18), Pair(-3, 14), Pair(-1, 21), Pair(-10, -21), Pair(6, 8), Pair(10, 3), Pair(-2, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(32, 20), Pair(12, 38), Pair(50, 48), Pair(65, 22), Pair(5, 38), Pair(4, 30), Pair(-4, 50), Pair(55, -62),
        Pair(-24, 39), Pair(-14, 43), Pair(-7, 51), Pair(-2, 36), Pair(11, 41), Pair(-11, 35), Pair(-13, 45), Pair(11, 23),
        Pair(-10, 44), Pair(-5, 47), Pair(0, 53), Pair(-4, 44), Pair(1, 39), Pair(13, 28), Pair(1, 34), Pair(24, 14),
        Pair(-10, 37), Pair(0, 47), Pair(2, 42), Pair(-2, 49), Pair(0, 47), Pair(12, 40), Pair(1, 41), Pair(-7, 46),
        Pair(-12, 39), Pair(-11, 56), Pair(0, 49), Pair(3, 47), Pair(6, 41), Pair(7, 41), Pair(9, 28), Pair(-9, 35),
        Pair(-5, 38), Pair(0, 48), Pair(-1, 47), Pair(-7, 48), Pair(-2, 41), Pair(5, 48), Pair(-5, 36), Pair(-8, 45),
        Pair(-25, 44), Pair(-5, 48), Pair(-12, 53), Pair(-3, 48), Pair(-9, 45), Pair(-11, 36), Pair(0, 0), Pair(-18, 42),
        Pair(-34, 52), Pair(-12, 43), Pair(-17, 48), Pair(-10, 56), Pair(-16, 41), Pair(-8, 28), Pair(-1, 49), Pair(-46, 59)
      },
      { // Piece 2
        Pair(-10, 28), Pair(16, 18), Pair(41, 2), Pair(49, 18), Pair(61, 1), Pair(87, 17), Pair(56, 15), Pair(17, 17),
        Pair(4, 14), Pair(-18, 24), Pair(1, 30), Pair(29, 10), Pair(49, 10), Pair(-9, 22), Pair(-3, 35), Pair(-27, 34),
        Pair(-9, 32), Pair(10, 22), Pair(-6, 15), Pair(9, 21), Pair(-10, 24), Pair(36, 15), Pair(-12, 25), Pair(-9, 33),
        Pair(3, 37), Pair(-3, 21), Pair(16, 23), Pair(-10, 29), Pair(9, 29), Pair(-2, 32), Pair(7, 25), Pair(-20, 37),
        Pair(-5, 36), Pair(3, 34), Pair(-4, 29), Pair(5, 39), Pair(2, 24), Pair(7, 38), Pair(-11, 27), Pair(-4, 31),
        Pair(3, 38), Pair(-5, 35), Pair(3, 42), Pair(-8, 35), Pair(1, 43), Pair(-4, 36), Pair(-1, 28), Pair(-22, 8),
        Pair(11, 23), Pair(0, 38), Pair(-5, 35), Pair(0, 45), Pair(-9, 40), Pair(11, 36), Pair(0, 0), Pair(6, 34),
        Pair(4, 36), Pair(4, 21), Pair(-1, 41), Pair(-14, 33), Pair(7, 31), Pair(-17, 24), Pair(19, 42), Pair(0, 0)
      },
      { // Piece 3
        Pair(11, 57), Pair(31, 51), Pair(21, 48), Pair(19, 53), Pair(13, 58), Pair(55, 51), Pair(34, 38), Pair(25, 53),
        Pair(12, 60), Pair(7, 62), Pair(18, 47), Pair(3, 57), Pair(29, 47), Pair(11, 55), Pair(44, 30), Pair(7, 54),
        Pair(16, 55), Pair(28, 46), Pair(7, 60), Pair(14, 56), Pair(6, 55), Pair(39, 40), Pair(40, 31), Pair(-5, 58),
        Pair(9, 61), Pair(20, 54), Pair(5, 58), Pair(13, 55), Pair(13, 50), Pair(10, 57), Pair(37, 31), Pair(-19, 65),
        Pair(8, 61), Pair(1, 61), Pair(6, 61), Pair(21, 51), Pair(18, 60), Pair(14, 59), Pair(51, 33), Pair(-14, 59),
        Pair(5, 60), Pair(7, 62), Pair(5, 64), Pair(1, 59), Pair(2, 57), Pair(15, 64), Pair(35, 12), Pair(-5, 46),
        Pair(-13, 65), Pair(15, 52), Pair(4, 67), Pair(3, 63), Pair(6, 58), Pair(-1, 62), Pair(0, 0), Pair(-50, 56),
        Pair(8, 63), Pair(10, 58), Pair(13, 55), Pair(9, 55), Pair(11, 59), Pair(6, 58), Pair(-8, 20), Pair(-15, 43)
      },
      { // Piece 4
        Pair(12, 78), Pair(41, 80), Pair(13, 95), Pair(44, 71), Pair(33, 76), Pair(58, 72), Pair(25, 79), Pair(38, 68),
        Pair(5, 100), Pair(3, 75), Pair(5, 96), Pair(18, 92), Pair(26, 82), Pair(34, 87), Pair(9, 100), Pair(35, 82),
        Pair(6, 107), Pair(18, 98), Pair(13, 81), Pair(13, 102), Pair(8, 108), Pair(30, 88), Pair(14, 129), Pair(1, 131),
        Pair(11, 99), Pair(17, 80), Pair(20, 96), Pair(16, 80), Pair(17, 91), Pair(6, 91), Pair(-1, 122), Pair(-1, 100),
        Pair(21, 92), Pair(19, 95), Pair(25, 92), Pair(9, 102), Pair(24, 85), Pair(6, 102), Pair(17, 98), Pair(4, 91),
        Pair(16, 79), Pair(24, 101), Pair(15, 95), Pair(22, 83), Pair(19, 99), Pair(17, 83), Pair(5, 99), Pair(1, 96),
        Pair(28, 74), Pair(23, 110), Pair(18, 105), Pair(18, 109), Pair(16, 98), Pair(18, 83), Pair(0, 0), Pair(-12, 108),
        Pair(12, 114), Pair(19, 109), Pair(20, 111), Pair(15, 108), Pair(19, 105), Pair(5, 102), Pair(18, 78), Pair(-3, 13)
      },
      { // Piece 5
        Pair(6, 53), Pair(-130, 61), Pair(-60, 35), Pair(-52, 40), Pair(-8, 32), Pair(48, 60), Pair(0, 55), Pair(-9, 73),
        Pair(-133, 1), Pair(-23, 48), Pair(-41, 46), Pair(3, 38), Pair(-44, 51), Pair(-52, 73), Pair(-55, 84), Pair(47, 41),
        Pair(-114, 32), Pair(-47, 40), Pair(-34, 39), Pair(-197, 77), Pair(-140, 60), Pair(-111, 76), Pair(-37, 69), Pair(-66, 44),
        Pair(-131, 37), Pair(-80, 41), Pair(-88, 48), Pair(-141, 57), Pair(-81, 44), Pair(-54, 49), Pair(-23, 48), Pair(-57, 51),
        Pair(-88, 18), Pair(-86, 30), Pair(-43, 41), Pair(-50, 40), Pair(-80, 47), Pair(2, 26), Pair(-3, 30), Pair(26, 14),
        Pair(-82, 24), Pair(-72, 35), Pair(-30, 24), Pair(-18, 29), Pair(2, 17), Pair(-27, -3), Pair(-17, 2), Pair(-20, -15),
        Pair(-31, 18), Pair(-35, 21), Pair(-15, 29), Pair(-21, 21), Pair(5, 12), Pair(-23, 0), Pair(0, 0), Pair(2, -6),
        Pair(-46, -6), Pair(-24, 6), Pair(-17, 9), Pair(-4, 11), Pair(28, -9), Pair(-16, -3), Pair(10, -6), Pair(-10, -15)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(1, 21), Pair(-14, 24), Pair(10, 6), Pair(-11, 17), Pair(-16, 12), Pair(-4, 4), Pair(-26, 21), Pair(21, 6),
        Pair(-5, 16), Pair(-9, 19), Pair(-5, 15), Pair(-6, 8), Pair(-6, 7), Pair(-15, 12), Pair(-12, 20), Pair(12, -1),
        Pair(-4, 17), Pair(-1, 12), Pair(0, 11), Pair(1, 8), Pair(-5, 10), Pair(-9, 11), Pair(-12, 19), Pair(15, 11),
        Pair(-3, 18), Pair(1, 16), Pair(0, 10), Pair(2, 14), Pair(0, 6), Pair(-2, 10), Pair(5, 13), Pair(2, 12),
        Pair(-5, 11), Pair(2, 17), Pair(-1, 12), Pair(-3, 12), Pair(4, 8), Pair(0, 7), Pair(6, 22), Pair(-10, 2),
        Pair(-4, 14), Pair(0, 19), Pair(-1, 17), Pair(0, 14), Pair(0, 17), Pair(-4, 8), Pair(-6, 8), Pair(2, -11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(46, 35), Pair(41, 41), Pair(-28, 41), Pair(38, 24), Pair(31, 29), Pair(33, 0), Pair(-21, 42), Pair(-30, 10),
        Pair(10, 43), Pair(-14, 58), Pair(-7, 45), Pair(4, 41), Pair(-14, 45), Pair(0, 41), Pair(-31, 53), Pair(-6, 26),
        Pair(-17, 47), Pair(-2, 53), Pair(2, 44), Pair(-2, 58), Pair(5, 45), Pair(13, 32), Pair(-5, 36), Pair(2, 33),
        Pair(-15, 53), Pair(-3, 53), Pair(3, 53), Pair(-1, 53), Pair(4, 50), Pair(0, 43), Pair(11, 33), Pair(0, 35),
        Pair(-7, 47), Pair(1, 57), Pair(2, 53), Pair(9, 51), Pair(7, 51), Pair(-5, 49), Pair(23, 26), Pair(-5, 37),
        Pair(-9, 48), Pair(-7, 51), Pair(1, 53), Pair(-3, 51), Pair(0, 52), Pair(-4, 49), Pair(7, 51), Pair(-7, 13),
        Pair(-23, 46), Pair(-10, 40), Pair(-4, 40), Pair(-3, 52), Pair(-6, 52), Pair(-12, 43), Pair(-19, 44), Pair(0, 0),
        Pair(-26, 35), Pair(-17, 50), Pair(-19, 59), Pair(-6, 53), Pair(0, 46), Pair(-13, 32), Pair(-3, 18), Pair(-30, 9)
      },
      { // Piece 2
        Pair(26, 2), Pair(19, 16), Pair(11, 26), Pair(10, 28), Pair(110, 9), Pair(-16, 34), Pair(34, 24), Pair(-25, 40),
        Pair(-7, 37), Pair(1, 28), Pair(3, 21), Pair(45, 4), Pair(13, 26), Pair(5, 20), Pair(1, 35), Pair(-19, 40),
        Pair(-7, 36), Pair(18, 32), Pair(20, 23), Pair(16, 22), Pair(12, 24), Pair(26, 21), Pair(1, 27), Pair(-8, 33),
        Pair(1, 38), Pair(7, 32), Pair(14, 36), Pair(14, 29), Pair(9, 31), Pair(-3, 44), Pair(4, 39), Pair(4, 33),
        Pair(-3, 43), Pair(10, 36), Pair(9, 37), Pair(10, 40), Pair(5, 35), Pair(-7, 42), Pair(10, 35), Pair(-3, 23),
        Pair(-1, 35), Pair(8, 42), Pair(1, 45), Pair(7, 45), Pair(2, 44), Pair(-5, 45), Pair(0, 52), Pair(-2, 28),
        Pair(-7, 17), Pair(0, 43), Pair(4, 37), Pair(-1, 40), Pair(6, 51), Pair(6, 46), Pair(4, 35), Pair(0, 0),
        Pair(13, 41), Pair(15, 34), Pair(-1, 41), Pair(4, 37), Pair(2, 35), Pair(1, 39), Pair(25, 8), Pair(10, 17)
      },
      { // Piece 3
        Pair(15, 82), Pair(7, 79), Pair(25, 75), Pair(-10, 79), Pair(18, 63), Pair(31, 61), Pair(22, 69), Pair(23, 51),
        Pair(19, 68), Pair(13, 72), Pair(21, 74), Pair(11, 72), Pair(5, 76), Pair(6, 69), Pair(-10, 73), Pair(18, 46),
        Pair(1, 83), Pair(7, 82), Pair(7, 75), Pair(15, 73), Pair(13, 65), Pair(26, 66), Pair(16, 58), Pair(11, 45),
        Pair(12, 73), Pair(15, 70), Pair(12, 71), Pair(25, 65), Pair(15, 68), Pair(19, 72), Pair(0, 75), Pair(-19, 64),
        Pair(13, 75), Pair(16, 73), Pair(7, 79), Pair(-2, 73), Pair(8, 71), Pair(0, 82), Pair(4, 65), Pair(3, 52),
        Pair(1, 82), Pair(7, 76), Pair(0, 78), Pair(1, 78), Pair(13, 75), Pair(-5, 73), Pair(11, 66), Pair(0, 30),
        Pair(5, 71), Pair(3, 75), Pair(7, 71), Pair(5, 77), Pair(5, 75), Pair(1, 68), Pair(3, 63), Pair(0, 0),
        Pair(13, 71), Pair(15, 70), Pair(14, 73), Pair(15, 66), Pair(16, 67), Pair(18, 71), Pair(-3, 66), Pair(-12, 33)
      },
      { // Piece 4
        Pair(30, 102), Pair(20, 94), Pair(19, 98), Pair(7, 107), Pair(10, 115), Pair(0, 114), Pair(-7, 101), Pair(-27, 118),
        Pair(15, 104), Pair(12, 110), Pair(16, 100), Pair(9, 124), Pair(3, 118), Pair(23, 104), Pair(15, 105), Pair(17, 95),
        Pair(8, 113), Pair(8, 114), Pair(21, 110), Pair(23, 106), Pair(18, 104), Pair(44, 100), Pair(38, 116), Pair(12, 119),
        Pair(13, 115), Pair(23, 115), Pair(16, 109), Pair(22, 112), Pair(14, 114), Pair(7, 114), Pair(27, 109), Pair(10, 98),
        Pair(17, 124), Pair(20, 101), Pair(18, 111), Pair(13, 119), Pair(9, 127), Pair(2, 120), Pair(23, 101), Pair(21, 105),
        Pair(20, 112), Pair(22, 121), Pair(20, 110), Pair(18, 117), Pair(12, 118), Pair(13, 103), Pair(11, 110), Pair(-6, 125),
        Pair(21, 113), Pair(19, 123), Pair(19, 133), Pair(17, 120), Pair(15, 118), Pair(14, 110), Pair(9, 115), Pair(0, 0),
        Pair(23, 114), Pair(15, 122), Pair(19, 117), Pair(16, 136), Pair(15, 115), Pair(18, 84), Pair(25, 61), Pair(18, -12)
      },
      { // Piece 5
        Pair(-42, -33), Pair(-180, 71), Pair(-78, 53), Pair(-17, 37), Pair(-14, 58), Pair(18, 96), Pair(30, 54), Pair(-25, 69),
        Pair(-8, 3), Pair(-111, 63), Pair(69, 20), Pair(-93, 61), Pair(-99, 71), Pair(8, 88), Pair(-74, 92), Pair(-49, 56),
        Pair(-168, 56), Pair(-39, 34), Pair(-4, 28), Pair(-54, 46), Pair(-145, 72), Pair(-63, 81), Pair(-91, 89), Pair(-144, 57),
        Pair(-54, 48), Pair(-109, 41), Pair(-19, 41), Pair(-76, 46), Pair(-120, 61), Pair(-53, 56), Pair(-28, 49), Pair(-16, 32),
        Pair(-93, 45), Pair(-63, 34), Pair(-108, 59), Pair(-66, 48), Pair(-10, 36), Pair(5, 21), Pair(32, 21), Pair(-16, 13),
        Pair(-40, 27), Pair(-39, 41), Pair(-22, 41), Pair(-25, 31), Pair(5, 26), Pair(21, 12), Pair(-1, -18), Pair(-3, -15),
        Pair(-21, 25), Pair(-33, 35), Pair(-32, 30), Pair(-28, 32), Pair(8, 13), Pair(1, 9), Pair(-18, -22), Pair(0, 0),
        Pair(-33, 17), Pair(-22, 30), Pair(-23, 30), Pair(-10, 27), Pair(19, -5), Pair(9, 2), Pair(7, -30), Pair(22, -52)
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
      Pair(-20, -114), Pair(-42, -217), Pair(-24, -175), Pair(-43, -200), Pair(-45, -205), Pair(-32, -202), Pair(-10, -195), Pair(-20, -150),
      Pair(-25, -181), Pair(-25, -225), Pair(7, -225), Pair(-57, -192), Pair(-59, -203), Pair(-58, -224), Pair(-39, -220), Pair(-56, -227),
      Pair(-26, -243), Pair(-43, -217), Pair(4, -222), Pair(-15, -223), Pair(-24, -203), Pair(-5, -209), Pair(-40, -219), Pair(-9, -246),
      Pair(-16, -215), Pair(-3, -233), Pair(25, -225), Pair(-28, -217), Pair(31, -213), Pair(17, -223), Pair(9, -238), Pair(6, -217),
      Pair(-14, -228), Pair(-23, -235), Pair(17, -212), Pair(18, -223), Pair(43, -220), Pair(27, -221), Pair(35, -234), Pair(32, -236),
      Pair(-10, -228), Pair(-28, -223), Pair(-9, -221), Pair(-4, -211), Pair(0, -218), Pair(58, -237), Pair(37, -228), Pair(-31, -235),
      Pair(-18, -231), Pair(1, -216), Pair(-68, -244), Pair(4, -223), Pair(-19, -221), Pair(-9, -238), Pair(-10, -256), Pair(-15, -249),
      Pair(-25, -229), Pair(-19, -215), Pair(-20, -213), Pair(-21, -185), Pair(0, -212), Pair(-31, -214), Pair(-36, -244), Pair(-12, -180)
  },
  {
      Pair(-24, -167), Pair(-16, -198), Pair(-49, -199), Pair(-43, -161), Pair(-60, -186), Pair(-54, -205), Pair(-71, -246), Pair(-51, -176),
      Pair(-15, -218), Pair(-59, -213), Pair(-66, -233), Pair(-64, -211), Pair(-95, -220), Pair(-48, -240), Pair(-69, -198), Pair(-40, -219),
      Pair(-41, -237), Pair(-51, -250), Pair(-56, -237), Pair(-26, -245), Pair(-30, -240), Pair(-27, -237), Pair(-68, -244), Pair(-40, -250),
      Pair(-55, -232), Pair(-36, -262), Pair(-32, -252), Pair(-39, -236), Pair(-44, -241), Pair(27, -265), Pair(-60, -249), Pair(-38, -264),
      Pair(-7, -273), Pair(-16, -261), Pair(-27, -257), Pair(-29, -251), Pair(-26, -242), Pair(37, -269), Pair(-11, -268), Pair(-51, -252),
      Pair(-7, -268), Pair(-53, -256), Pair(-64, -253), Pair(-72, -243), Pair(19, -265), Pair(-36, -252), Pair(-10, -277), Pair(-42, -251),
      Pair(46, -298), Pair(-41, -279), Pair(-58, -271), Pair(-26, -251), Pair(-17, -255), Pair(-22, -269), Pair(-4, -278), Pair(-19, -313),
      Pair(3, -293), Pair(-25, -291), Pair(-55, -269), Pair(-47, -277), Pair(-28, -254), Pair(-33, -271), Pair(-28, -265), Pair(-17, -299)
  },
  {
      Pair(-44, -333), Pair(4, -353), Pair(-21, -357), Pair(68, -390), Pair(15, -365), Pair(-30, -354), Pair(52, -365), Pair(-39, -348),
      Pair(-77, -336), Pair(-99, -329), Pair(-88, -332), Pair(-59, -337), Pair(-106, -322), Pair(-87, -343), Pair(-57, -348), Pair(-83, -338),
      Pair(2, -357), Pair(-43, -345), Pair(37, -364), Pair(-64, -341), Pair(-47, -344), Pair(-12, -363), Pair(-111, -334), Pair(-46, -362),
      Pair(-15, -351), Pair(-81, -339), Pair(-70, -345), Pair(-49, -343), Pair(-56, -345), Pair(15, -369), Pair(-63, -349), Pair(-53, -350),
      Pair(-63, -335), Pair(-78, -338), Pair(-112, -334), Pair(-88, -348), Pair(-60, -348), Pair(-76, -350), Pair(-56, -354), Pair(-78, -343),
      Pair(-102, -328), Pair(-138, -317), Pair(-76, -343), Pair(-91, -337), Pair(-100, -337), Pair(-47, -357), Pair(-97, -333), Pair(-69, -344),
      Pair(-126, -329), Pair(-115, -325), Pair(-81, -320), Pair(-77, -331), Pair(-109, -329), Pair(-112, -327), Pair(-94, -335), Pair(-107, -330),
      Pair(-109, -317), Pair(-95, -338), Pair(-60, -332), Pair(-89, -333), Pair(-94, -344), Pair(-74, -351), Pair(-143, -331), Pair(-91, -338)
  },
  {
      Pair(-16, -62), Pair(-56, -80), Pair(-12, -77), Pair(27, -57), Pair(-52, -62), Pair(1, -75), Pair(-66, -25), Pair(-64, -65),
      Pair(-19, -41), Pair(-54, -71), Pair(-16, -46), Pair(-9, -2), Pair(-1, -6), Pair(-54, -54), Pair(-5, -13), Pair(-39, -72),
      Pair(-29, -48), Pair(-28, -49), Pair(-8, -22), Pair(-58, -114), Pair(17, 13), Pair(18, 19), Pair(5, -4), Pair(-29, -54),
      Pair(-45, -84), Pair(-11, -4), Pair(-27, -47), Pair(-29, -61), Pair(-50, -33), Pair(-4, -36), Pair(-17, -75), Pair(-14, -38),
      Pair(-25, -41), Pair(-10, -13), Pair(-16, -35), Pair(9, 4), Pair(-21, -46), Pair(0, -19), Pair(-52, -99), Pair(-59, -88),
      Pair(-23, -42), Pair(-23, -39), Pair(-18, -39), Pair(25, 36), Pair(-19, -30), Pair(9, 16), Pair(1, 5), Pair(-4, -10),
      Pair(-29, -61), Pair(-53, -92), Pair(-40, -65), Pair(1, -6), Pair(-2, -7), Pair(6, 16), Pair(-9, -21), Pair(-2, -2),
      Pair(-7, -14), Pair(-11, -26), Pair(-30, -58), Pair(-26, -55), Pair(5, 4), Pair(-25, -50), Pair(-2, -4), Pair(-6, -13)
  },
  {
      Pair(45, 42), Pair(-36, 19), Pair(2, 4), Pair(-37, -4), Pair(11, -5), Pair(-39, -1), Pair(-38, -11), Pair(-24, 41),
      Pair(-9, 16), Pair(-18, 15), Pair(-19, 16), Pair(-15, -7), Pair(0, -4), Pair(6, -3), Pair(17, -14), Pair(-33, 8),
      Pair(-33, 28), Pair(28, 24), Pair(7, 10), Pair(86, -25), Pair(43, -21), Pair(82, -17), Pair(86, -17), Pair(-81, 19),
      Pair(28, 37), Pair(8, 21), Pair(14, 8), Pair(62, -21), Pair(25, -13), Pair(39, -15), Pair(-13, -6), Pair(-52, 6),
      Pair(12, 25), Pair(-66, 21), Pair(-10, 6), Pair(38, -17), Pair(23, -16), Pair(36, -22), Pair(-2, -16), Pair(-58, 13),
      Pair(-42, 33), Pair(-35, 3), Pair(47, -14), Pair(32, -14), Pair(32, -17), Pair(45, -24), Pair(-7, -28), Pair(-65, 11),
      Pair(5, 33), Pair(-15, 6), Pair(47, -15), Pair(-9, -8), Pair(5, -20), Pair(40, -29), Pair(33, -34), Pair(-25, 3),
      Pair(5, 36), Pair(-65, 6), Pair(-10, -3), Pair(1, -24), Pair(-16, -13), Pair(-4, -26), Pair(-65, -17), Pair(-56, 9)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(12, 38), Pair(20, 24), Pair(22, 30), Pair(23, 36), Pair(24, 41), Pair(25, 51), Pair(27, 54), Pair(31, 52),
  Pair(32, 48)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-8, 6), Pair(1, -32), Pair(4, -15), Pair(8, -4), Pair(10, 6), Pair(13, 17), Pair(13, 21), Pair(12, 23),
  Pair(16, 27), Pair(21, 23), Pair(26, 22), Pair(38, 14), Pair(43, 30), Pair(95, -3)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-49, -99), Pair(-35, -88), Pair(-33, -57), Pair(-30, -26), Pair(-29, -9), Pair(-25, -5), Pair(-20, 1), Pair(-14, 5),
  Pair(-11, 9), Pair(-7, 14), Pair(-4, 18), Pair(3, 20), Pair(6, 20), Pair(29, 8), Pair(66, -15)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-59, 236), Pair(-28, 145), Pair(-10, 104), Pair(-5, 84), Pair(-5, 108), Pair(-6, 127), Pair(-4, 139), Pair(-3, 157),
  Pair(-2, 170), Pair(1, 170), Pair(3, 179), Pair(5, 180), Pair(6, 178), Pair(9, 175), Pair(6, 174), Pair(9, 170),
  Pair(11, 164), Pair(11, 152), Pair(19, 135), Pair(36, 115), Pair(47, 97), Pair(64, 70), Pair(65, 65), Pair(100, 39),
  Pair(80, 46), Pair(156, -4), Pair(171, -1), Pair(220, -19)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-28, -101), Pair(-23, -85), Pair(-9, -56), Pair(19, -20), Pair(10, 30), Pair(154, 163), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(9, 14), Pair(20, 17), Pair(23, 46), Pair(47, 98), Pair(112, 185), Pair(75, 244), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(6, -8), Pair(4, 19), Pair(16, 37), Pair(54, 75), Pair(218, 112), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-34, -61), Pair(-14, -15), Pair(-3, 11), Pair(-17, -10), Pair(-14, -6), Pair(-12, -9), Pair(-14, 6), Pair(-23, -45)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-4, -3), Pair(-10, -10), Pair(-11, -6), Pair(-7, -2), Pair(-7, -6), Pair(0, -11), Pair(-7, -7), Pair(5, -5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(3, -13), Pair(15, -13), Pair(24, -11), Pair(36, -13), Pair(41, -13), Pair(63, -16), Pair(60, -20), Pair(16, -10)
  },
  {
      Pair(-9, 3), Pair(0, -3), Pair(8, -7), Pair(22, -2), Pair(16, -8), Pair(25, -13), Pair(39, -19), Pair(-9, 1)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(22, -11), Pair(37, -11), Pair(29, -10),
  Pair(47, -11), Pair(48, -15), Pair(47, -13),
  Pair(67, -2), Pair(0, 0), Pair(59, 1),
  Pair(41, 24), Pair(19, 18), Pair(37, 26)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, -2), Pair(-18, 10), Pair(-6, -2),
  Pair(-5, -5), Pair(-16, 4), Pair(-5, -6),
  Pair(0, -13), Pair(-5, -9), Pair(4, -14),
  Pair(18, -16), Pair(7, -14), Pair(24, -18),
  Pair(72, -23), Pair(76, -23), Pair(68, -26),
  Pair(44, -31), Pair(-18, -62), Pair(29, -18),
  Pair(75, -81), Pair(0, 0), Pair(63, -79)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-2, 84), Pair(-6, 73), Pair(-6, 61), Pair(3, 50), Pair(1, 41), Pair(13, 33), Pair(11, 26)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-15, 2), Pair(-22, 28), Pair(-4, 51), Pair(2, 62), Pair(13, 68), Pair(15, 74), Pair(12, 91)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-475, 103);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-51, -57), Pair(-10, -32), Pair(-21, -19), Pair(-64, -4), Pair(-42, -2), Pair(-57, 3), Pair(-16, -2), Pair(-22, -29)
  },
  {
      Pair(-45, 16), Pair(6, 10), Pair(-6, 12), Pair(-55, 29), Pair(-20, 18), Pair(-38, 17), Pair(2, 20), Pair(-18, 9)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(24, 3), Pair(42, -3), Pair(107, -27), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 1), Pair(35, -3), Pair(76, -10), Pair(101, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(26, -13), Pair(43, -12), Pair(70, -12), Pair(123, -23), Pair(200, -45), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, 24), Pair(25, 51), Pair(53, 62), Pair(116, 54), Pair(171, 50), Pair(299, -1), Pair(370, -1)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(36, 3), Pair(11, 6), Pair(29, -2), Pair(19, 22), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(3, 31), Pair(6, 39)
  },
  {
      Pair(-44, -5), Pair(-31, -19)
  },
  {
      Pair(-45, -13), Pair(-38, -36)
  },
  {
      Pair(-76, 49), Pair(-63, 22)
  },
  {
      Pair(-53, 54), Pair(-51, 34)
  },
  {
      Pair(32, 38), Pair(-46, 33)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(11, 33), Pair(11, 30), Pair(15, 26), Pair(12, 17), Pair(12, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-8, -30), Pair(2, -12)
  },
  {
      Pair(-13, -24), Pair(-7, -39)
  },
  {
      Pair(-28, -38), Pair(-26, -61)
  },
  {
      Pair(-61, -21), Pair(-44, -44)
  },
  {
      Pair(-44, -31), Pair(-41, -25)
  },
  {
      Pair(-96, -13), Pair(-26, -61)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-9, -20), Pair(0, -1)
  },
  {
      Pair(-42, -34), Pair(-23, -49)
  },
  {
      Pair(-16, -50), Pair(-13, -65)
  },
  {
      Pair(-55, -19), Pair(-37, -44)
  },
  {
      Pair(-45, -17), Pair(-36, -34)
  },
  {
      Pair(-21, -18), Pair(-9, -28)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-3, -17), Pair(4, 4)
  },
  {
      Pair(-32, -23), Pair(0, -9)
  },
  {
      Pair(-25, -25), Pair(-6, -5)
  },
  {
      Pair(5, -20), Pair(9, -20)
  },
  {
      Pair(-50, -13), Pair(-34, -34)
  },
  {
      Pair(11, -33), Pair(-15, -38)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(5, 48), Pair(54, 23), Pair(7, 29), Pair(10, 29), Pair(24, 26), Pair(45, 18), Pair(49, 40), Pair(77, 51),
  Pair(12, 35), Pair(13, 35), Pair(11, 25), Pair(17, 29), Pair(8, 25), Pair(2, 42), Pair(12, 29), Pair(40, 55),
  Pair(-5, 19), Pair(-6, 17), Pair(7, 27), Pair(5, 18), Pair(-9, 33), Pair(9, 27), Pair(17, 17), Pair(-4, 30)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-21, -3), Pair(26, -7), Pair(10, 10), Pair(16, 2), Pair(13, -26), Pair(49, -20), Pair(85, 5), Pair(-19, -22),
  Pair(-18, 27), Pair(17, 6), Pair(-13, 29), Pair(12, 36), Pair(12, 21), Pair(-16, 23), Pair(16, -12), Pair(58, 13),
  Pair(23, 22), Pair(-1, 2), Pair(17, 10), Pair(-4, 22), Pair(-14, 15), Pair(6, 25), Pair(6, -13), Pair(9, 46)
};

constexpr ScorePair kBishopPairBonus = Pair(23, 85);

constexpr ScorePair kTempoBonus = Pair(21, 23);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H