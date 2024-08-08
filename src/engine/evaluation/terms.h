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

// [is_our_piece][pawn_position][piece][piece_position]
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
  Pair(96, 52), Pair(410, 193), Pair(481, 235), Pair(659, 456), Pair(1559, 565), Pair(0, 0)
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
        Pair(0, 0), Pair(-6, -9), Pair(154, -38), Pair(40, -30), Pair(144, -59), Pair(42, -22), Pair(53, -5), Pair(20, -28),
        Pair(-8, -97), Pair(104, -42), Pair(64, -49), Pair(21, -41), Pair(23, -35), Pair(11, -6), Pair(4, -20), Pair(-36, 16),
        Pair(-67, -39), Pair(37, -16), Pair(-14, -20), Pair(-7, -42), Pair(-24, -5), Pair(-14, -23), Pair(-71, 6), Pair(-12, -10),
        Pair(108, -41), Pair(34, -16), Pair(-18, -11), Pair(1, -23), Pair(-40, -7), Pair(-18, -4), Pair(-26, -8), Pair(-3, -9),
        Pair(-84, 60), Pair(73, -49), Pair(3, -15), Pair(-13, -39), Pair(-6, -23), Pair(-15, -13), Pair(-33, 4), Pair(-4, -18),
        Pair(0, 0), Pair(76, -9), Pair(-13, 15), Pair(-18, -24), Pair(-9, -27), Pair(-16, -21), Pair(-12, -22), Pair(-25, -18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-194, -227), Pair(-70, -105), Pair(79, -176), Pair(-109, -63), Pair(36, -127), Pair(211, -105), Pair(59, -148), Pair(-103, -195),
        Pair(8, -82), Pair(115, -126), Pair(84, -70), Pair(122, -66), Pair(108, -94), Pair(-120, -106), Pair(-57, -107), Pair(-169, -159),
        Pair(69, -62), Pair(95, -29), Pair(-56, -58), Pair(183, -121), Pair(20, -123), Pair(111, -104), Pair(33, -93), Pair(-13, -148),
        Pair(41, -16), Pair(17, 18), Pair(119, -60), Pair(187, -22), Pair(168, -159), Pair(128, -111), Pair(19, -113), Pair(33, -116),
        Pair(-27, -114), Pair(32, 21), Pair(30, 6), Pair(89, -32), Pair(-37, -3), Pair(26, -67), Pair(132, -103), Pair(12, -60),
        Pair(94, 13), Pair(27, 55), Pair(41, 62), Pair(72, -19), Pair(10, 29), Pair(18, -51), Pair(102, -124), Pair(-35, -37),
        Pair(0, 0), Pair(64, -185), Pair(-96, 95), Pair(-57, 20), Pair(19, -47), Pair(-10, -28), Pair(52, -159), Pair(-7, 9),
        Pair(-34, 86), Pair(-46, -15), Pair(202, 147), Pair(-94, -166), Pair(76, -68), Pair(-20, -79), Pair(-107, 23), Pair(68, -16)
      },
      { // Piece 2
        Pair(-94, -127), Pair(-268, 113), Pair(14, -73), Pair(-95, 103), Pair(-82, 40), Pair(-59, 102), Pair(117, 14), Pair(-138, 230),
        Pair(-113, -17), Pair(-135, -30), Pair(-116, 120), Pair(81, -62), Pair(-40, 94), Pair(-58, 66), Pair(85, 188), Pair(12, -72),
        Pair(14, -29), Pair(-87, 101), Pair(-63, -16), Pair(-95, 85), Pair(73, -8), Pair(-133, 215), Pair(45, 1), Pair(53, 45),
        Pair(50, 71), Pair(-141, 80), Pair(22, 38), Pair(54, -23), Pair(-34, 152), Pair(199, -101), Pair(-199, 168), Pair(-25, -35),
        Pair(-102, 40), Pair(-239, 130), Pair(216, 37), Pair(18, 144), Pair(44, 2), Pair(-41, 47), Pair(-101, 34), Pair(-70, 105),
        Pair(-93, 108), Pair(85, 90), Pair(-38, 174), Pair(-41, 20), Pair(-128, 135), Pair(43, -37), Pair(27, 70), Pair(76, -110),
        Pair(0, 0), Pair(-14, 217), Pair(-68, 57), Pair(-40, 169), Pair(-5, -9), Pair(123, 52), Pair(39, -82), Pair(49, 39),
        Pair(94, 231), Pair(-11, 95), Pair(-76, 191), Pair(73, 79), Pair(43, 117), Pair(-11, 20), Pair(38, 38), Pair(-206, -1)
      },
      { // Piece 3
        Pair(-98, 160), Pair(75, 128), Pair(-2, 75), Pair(40, 69), Pair(-96, 102), Pair(138, 18), Pair(162, 26), Pair(185, -42),
        Pair(107, 85), Pair(178, 39), Pair(9, 104), Pair(95, 30), Pair(128, 23), Pair(127, -63), Pair(152, 13), Pair(244, -55),
        Pair(-39, 145), Pair(40, 77), Pair(83, 50), Pair(-203, 186), Pair(70, 28), Pair(-107, 22), Pair(-81, 87), Pair(26, 4),
        Pair(-40, 148), Pair(-41, 96), Pair(-80, 107), Pair(-64, 52), Pair(-36, 123), Pair(-54, 6), Pair(-65, 102), Pair(-17, -6),
        Pair(3, 136), Pair(34, 104), Pair(84, -13), Pair(100, 8), Pair(-3, 30), Pair(-2, 55), Pair(-2, 95), Pair(35, 5),
        Pair(-31, 163), Pair(48, 18), Pair(81, 22), Pair(217, -65), Pair(17, 3), Pair(53, 39), Pair(-113, 107), Pair(156, 64),
        Pair(0, 0), Pair(111, 203), Pair(346, 26), Pair(156, 39), Pair(151, 51), Pair(26, -22), Pair(-118, 115), Pair(62, 98),
        Pair(231, 58), Pair(101, 36), Pair(111, 39), Pair(78, 45), Pair(127, 62), Pair(83, 72), Pair(12, 94), Pair(110, 50)
      },
      { // Piece 4
        Pair(13, 42), Pair(47, 2), Pair(-50, -48), Pair(76, 17), Pair(78, -77), Pair(67, 89), Pair(50, -24), Pair(36, -98),
        Pair(15, 43), Pair(2, 150), Pair(80, 42), Pair(-1, 81), Pair(1, 37), Pair(-4, -44), Pair(17, 112), Pair(25, -182),
        Pair(-51, -58), Pair(79, 43), Pair(-115, -23), Pair(39, 59), Pair(50, 73), Pair(121, 15), Pair(-38, 56), Pair(-21, -55),
        Pair(99, -43), Pair(-8, -41), Pair(-167, 101), Pair(26, 67), Pair(-89, 141), Pair(-25, -17), Pair(27, -39), Pair(-57, 34),
        Pair(102, -84), Pair(-10, 87), Pair(-6, -97), Pair(-80, 159), Pair(-135, 148), Pair(-13, -49), Pair(-56, -46), Pair(-70, -51),
        Pair(-6, 86), Pair(-79, 65), Pair(-105, 127), Pair(-36, -2), Pair(-153, 179), Pair(-83, 77), Pair(-106, 89), Pair(-45, -29),
        Pair(0, 0), Pair(3, 81), Pair(30, -138), Pair(-54, 43), Pair(-34, 110), Pair(98, -93), Pair(-188, 104), Pair(-193, -101),
        Pair(15, 25), Pair(83, -61), Pair(-46, 124), Pair(-64, -104), Pair(-139, -13), Pair(-195, 101), Pair(-26, 106), Pair(-31, 74)
      },
      { // Piece 5
        Pair(-35, -119), Pair(-11, 62), Pair(-24, -220), Pair(-4, -101), Pair(86, -35), Pair(-10, -80), Pair(4, -32), Pair(82, 96),
        Pair(-85, -166), Pair(65, -44), Pair(-53, -46), Pair(-48, 43), Pair(-54, -131), Pair(181, -80), Pair(93, -47), Pair(96, 39),
        Pair(-35, -66), Pair(-87, 53), Pair(121, -74), Pair(51, 12), Pair(32, -10), Pair(-6, -55), Pair(68, -59), Pair(177, -26),
        Pair(-126, -90), Pair(-65, 48), Pair(98, 11), Pair(20, -12), Pair(-22, -9), Pair(-87, 6), Pair(81, -57), Pair(111, -105),
        Pair(-15, -49), Pair(-121, 84), Pair(16, 53), Pair(90, 9), Pair(29, 20), Pair(25, -33), Pair(5, -23), Pair(113, -85),
        Pair(-196, 116), Pair(63, 41), Pair(-38, 77), Pair(-34, 60), Pair(34, 22), Pair(-26, 15), Pair(27, -18), Pair(-1, -68),
        Pair(0, 0), Pair(-45, 209), Pair(-78, 98), Pair(-245, 141), Pair(-31, -10), Pair(-68, -22), Pair(-85, 69), Pair(-3, 8),
        Pair(212, 227), Pair(73, 109), Pair(-289, 170), Pair(-82, 63), Pair(-52, -72), Pair(-22, -100), Pair(-9, -74), Pair(60, -126)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 9), Pair(0, 0), Pair(-138, -8), Pair(45, -8), Pair(120, -18), Pair(97, 13), Pair(44, -3), Pair(-5, -1),
        Pair(-16, 3), Pair(94, -36), Pair(-31, 34), Pair(-3, -6), Pair(-36, 2), Pair(84, -6), Pair(9, 8), Pair(27, -19),
        Pair(-22, -14), Pair(-14, -2), Pair(36, -10), Pair(53, -47), Pair(-27, -24), Pair(-66, 18), Pair(-28, -15), Pair(-67, 17),
        Pair(1, -30), Pair(13, -12), Pair(39, -17), Pair(-1, -14), Pair(-38, 3), Pair(-28, 5), Pair(-35, 14), Pair(-38, -10),
        Pair(24, 0), Pair(38, 36), Pair(37, -20), Pair(15, -33), Pair(38, -35), Pair(-27, 0), Pair(-27, -9), Pair(-22, -18),
        Pair(16, 2), Pair(0, 0), Pair(20, 15), Pair(46, 0), Pair(-45, -7), Pair(-19, -11), Pair(-24, -16), Pair(-35, -31),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-30, -10), Pair(-53, -23), Pair(60, -102), Pair(-15, 6), Pair(-51, -57), Pair(105, 59), Pair(-30, -145), Pair(51, -21),
        Pair(-5, -110), Pair(-139, -66), Pair(232, -10), Pair(-21, -61), Pair(125, -56), Pair(-141, 106), Pair(-84, -1), Pair(29, 12),
        Pair(81, -19), Pair(81, 132), Pair(-56, -11), Pair(-44, -38), Pair(60, -41), Pair(20, -50), Pair(118, -107), Pair(-78, -103),
        Pair(-254, 60), Pair(98, 72), Pair(19, 53), Pair(140, -103), Pair(71, 11), Pair(120, -106), Pair(8, -65), Pair(66, -38),
        Pair(-28, 72), Pair(-25, -62), Pair(37, 76), Pair(8, 3), Pair(81, -7), Pair(35, 21), Pair(-80, -9), Pair(-93, 73),
        Pair(-153, 138), Pair(-150, -7), Pair(-43, 102), Pair(57, 84), Pair(129, 58), Pair(-77, 92), Pair(81, 6), Pair(-34, -20),
        Pair(30, -8), Pair(0, 0), Pair(82, -17), Pair(38, 101), Pair(-1, -37), Pair(75, -79), Pair(74, 23), Pair(-92, 42),
        Pair(-65, -75), Pair(30, 126), Pair(-210, -161), Pair(65, 185), Pair(-22, 49), Pair(-11, 18), Pair(-121, 41), Pair(-76, -31)
      },
      { // Piece 2
        Pair(-254, -99), Pair(-53, 53), Pair(-102, 43), Pair(-105, -58), Pair(-226, 187), Pair(-22, -51), Pair(-40, 88), Pair(-28, 2),
        Pair(52, 21), Pair(70, -38), Pair(-21, -22), Pair(-347, 153), Pair(-28, -10), Pair(-183, 134), Pair(-111, 15), Pair(-88, 212),
        Pair(-68, -61), Pair(-97, -103), Pair(66, -46), Pair(85, -7), Pair(26, 54), Pair(22, 70), Pair(51, 171), Pair(-47, -206),
        Pair(-5, -106), Pair(150, 11), Pair(104, -143), Pair(-81, 90), Pair(16, 50), Pair(40, 168), Pair(162, -51), Pair(-29, 92),
        Pair(39, 21), Pair(9, -37), Pair(-77, 156), Pair(109, 14), Pair(-15, 166), Pair(156, -82), Pair(148, 56), Pair(19, -187),
        Pair(-6, -10), Pair(-19, 182), Pair(-6, 259), Pair(-43, 183), Pair(47, -63), Pair(4, 120), Pair(-19, 104), Pair(12, 132),
        Pair(-224, 210), Pair(0, 0), Pair(61, 200), Pair(13, -32), Pair(-80, 55), Pair(42, -88), Pair(-4, 40), Pair(104, -121),
        Pair(12, -26), Pair(45, 158), Pair(11, 22), Pair(-20, 182), Pair(124, -82), Pair(-11, 81), Pair(-5, 22), Pair(-120, -27)
      },
      { // Piece 3
        Pair(44, 69), Pair(147, 76), Pair(79, 61), Pair(56, 12), Pair(168, -147), Pair(7, 10), Pair(81, 33), Pair(256, -49),
        Pair(-80, 62), Pair(-120, 159), Pair(-28, 56), Pair(59, -10), Pair(-36, 13), Pair(2, 30), Pair(161, 36), Pair(-83, 114),
        Pair(-26, 68), Pair(126, 103), Pair(11, 48), Pair(-18, 45), Pair(81, -102), Pair(76, -65), Pair(39, 29), Pair(343, -78),
        Pair(112, 92), Pair(-31, 157), Pair(34, 18), Pair(-42, 17), Pair(30, 20), Pair(-17, 66), Pair(50, 20), Pair(136, -59),
        Pair(36, 38), Pair(91, 117), Pair(28, 48), Pair(169, 3), Pair(-25, 25), Pair(-7, 113), Pair(51, 24), Pair(30, 36),
        Pair(79, -3), Pair(-87, 175), Pair(-62, 18), Pair(-62, 23), Pair(76, -48), Pair(50, 80), Pair(10, 23), Pair(151, -117),
        Pair(195, 7), Pair(0, 0), Pair(-123, 170), Pair(-85, 140), Pair(215, 2), Pair(185, -33), Pair(-27, 159), Pair(-5, 145),
        Pair(118, 5), Pair(124, 87), Pair(-11, 1), Pair(81, 29), Pair(100, 39), Pair(38, -7), Pair(-4, 73), Pair(5, 53)
      },
      { // Piece 4
        Pair(-51, 5), Pair(124, 55), Pair(81, -36), Pair(33, 55), Pair(-90, -40), Pair(-49, -51), Pair(-108, -99), Pair(-50, -65),
        Pair(2, -40), Pair(-57, 63), Pair(-39, 4), Pair(-38, 112), Pair(6, 43), Pair(-90, 51), Pair(63, 8), Pair(-12, 26),
        Pair(-72, 55), Pair(20, 80), Pair(42, 39), Pair(69, -1), Pair(29, 91), Pair(22, 16), Pair(-2, -55), Pair(-23, -92),
        Pair(-133, 0), Pair(-64, 159), Pair(76, -95), Pair(24, 52), Pair(56, -11), Pair(-68, 32), Pair(7, 52), Pair(115, -174),
        Pair(-74, 134), Pair(-30, -153), Pair(-31, 71), Pair(-3, 63), Pair(10, 72), Pair(17, 123), Pair(45, -121), Pair(-44, -118),
        Pair(183, -19), Pair(5, 12), Pair(182, -111), Pair(85, -12), Pair(-48, -101), Pair(61, -108), Pair(-85, -82), Pair(-64, -127),
        Pair(-24, -205), Pair(0, 0), Pair(13, 58), Pair(18, -17), Pair(81, -185), Pair(-100, -64), Pair(70, -64), Pair(-125, -51),
        Pair(-76, -54), Pair(-190, -177), Pair(-144, -143), Pair(-41, -64), Pair(-41, -181), Pair(-147, -56), Pair(-161, -18), Pair(-132, 84)
      },
      { // Piece 5
        Pair(-22, -78), Pair(-27, -56), Pair(-10, 12), Pair(-20, -147), Pair(61, -72), Pair(-11, -219), Pair(-37, -139), Pair(0, -130),
        Pair(-39, -79), Pair(-48, 7), Pair(-28, -62), Pair(-34, 7), Pair(29, 10), Pair(-5, -53), Pair(44, -23), Pair(46, 2),
        Pair(-64, -90), Pair(-6, -11), Pair(-8, 13), Pair(121, -30), Pair(-16, -25), Pair(-20, -7), Pair(-85, 67), Pair(80, -20),
        Pair(-31, 45), Pair(-83, -4), Pair(-34, 26), Pair(53, 18), Pair(46, 32), Pair(-122, 31), Pair(-106, 46), Pair(-8, 3),
        Pair(-39, -77), Pair(-21, -23), Pair(84, 28), Pair(-3, -12), Pair(35, -1), Pair(62, -10), Pair(29, 19), Pair(-5, -101),
        Pair(107, 194), Pair(35, -6), Pair(156, 28), Pair(-127, 98), Pair(-22, 23), Pair(19, -2), Pair(91, -20), Pair(220, -133),
        Pair(-27, 115), Pair(0, 0), Pair(-143, 168), Pair(-139, 136), Pair(-162, 98), Pair(51, 7), Pair(81, -26), Pair(42, 15),
        Pair(-5, 6), Pair(175, 123), Pair(14, 61), Pair(-198, -21), Pair(-100, -48), Pair(-31, -58), Pair(-21, 7), Pair(122, -101)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-154, 39), Pair(138, 8), Pair(0, 0), Pair(-41, 46), Pair(-72, 26), Pair(33, -39), Pair(156, -39), Pair(69, 16),
        Pair(-21, 12), Pair(-118, 9), Pair(-143, 87), Pair(22, -11), Pair(-14, -14), Pair(92, -29), Pair(28, -27), Pair(-8, -6),
        Pair(-14, 2), Pair(25, -42), Pair(105, -19), Pair(27, -11), Pair(51, -14), Pair(-35, 4), Pair(-3, -24), Pair(-56, 21),
        Pair(-11, -28), Pair(14, 4), Pair(35, -53), Pair(-18, -2), Pair(43, -25), Pair(21, -27), Pair(-33, -6), Pair(-51, 12),
        Pair(29, -40), Pair(-26, 17), Pair(19, 8), Pair(-67, 11), Pair(59, -39), Pair(-5, -3), Pair(4, -21), Pair(-10, -9),
        Pair(15, 12), Pair(15, -15), Pair(0, 0), Pair(-16, 15), Pair(-4, 17), Pair(-6, -26), Pair(-55, 0), Pair(-39, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, 28), Pair(12, -27), Pair(181, 29), Pair(104, 27), Pair(-71, -167), Pair(-96, -134), Pair(-51, 98), Pair(94, -127),
        Pair(181, -8), Pair(-89, 70), Pair(-119, -10), Pair(-173, -64), Pair(100, 46), Pair(-152, 17), Pair(124, 40), Pair(-150, -192),
        Pair(-84, 101), Pair(2, 4), Pair(-31, -8), Pair(86, -3), Pair(-33, 93), Pair(81, -85), Pair(118, -26), Pair(-187, 61),
        Pair(74, 29), Pair(275, -57), Pair(-76, 11), Pair(-23, 60), Pair(24, -5), Pair(-129, 1), Pair(106, -111), Pair(15, 20),
        Pair(-118, -26), Pair(112, 2), Pair(99, 85), Pair(71, 44), Pair(153, -69), Pair(-21, 11), Pair(-45, 77), Pair(-30, 187),
        Pair(84, -51), Pair(-150, 217), Pair(69, -12), Pair(-57, 128), Pair(-44, 25), Pair(-41, 88), Pair(-182, 157), Pair(6, -45),
        Pair(22, 149), Pair(-93, -62), Pair(0, 0), Pair(31, 32), Pair(-5, 102), Pair(53, -10), Pair(46, 55), Pair(174, -132),
        Pair(3, 17), Pair(-28, -34), Pair(-50, 174), Pair(-118, -94), Pair(119, 92), Pair(0, -7), Pair(-21, -77), Pair(-168, -34)
      },
      { // Piece 2
        Pair(-54, -30), Pair(-107, -44), Pair(-158, -25), Pair(15, 29), Pair(-27, 12), Pair(40, 185), Pair(-40, -50), Pair(-59, 73),
        Pair(-53, -31), Pair(74, -107), Pair(-92, 114), Pair(-158, 89), Pair(-54, 183), Pair(5, -1), Pair(-132, 161), Pair(291, -12),
        Pair(103, 2), Pair(-33, 43), Pair(-143, -31), Pair(-135, 159), Pair(-51, 29), Pair(67, 144), Pair(39, 27), Pair(123, 116),
        Pair(66, 169), Pair(144, -59), Pair(128, 4), Pair(56, 32), Pair(-82, 108), Pair(-62, 5), Pair(96, 151), Pair(-130, -8),
        Pair(15, 177), Pair(-82, 91), Pair(114, -54), Pair(-90, 117), Pair(65, 49), Pair(-1, 192), Pair(-49, 75), Pair(-170, -62),
        Pair(44, 180), Pair(-35, 103), Pair(12, 178), Pair(134, 46), Pair(15, 164), Pair(-32, 38), Pair(51, 3), Pair(-20, -130),
        Pair(-97, -42), Pair(-37, 217), Pair(0, 0), Pair(31, 211), Pair(21, 59), Pair(-18, 44), Pair(1, -42), Pair(-16, -64),
        Pair(-171, 145), Pair(-51, -56), Pair(-21, 288), Pair(-182, 49), Pair(59, 123), Pair(10, 46), Pair(-64, -32), Pair(42, 22)
      },
      { // Piece 3
        Pair(-33, 41), Pair(91, 14), Pair(1, 90), Pair(65, 27), Pair(69, -1), Pair(70, 22), Pair(152, 68), Pair(186, -50),
        Pair(69, 22), Pair(21, 99), Pair(87, 92), Pair(-20, 99), Pair(-55, 40), Pair(103, -6), Pair(85, 39), Pair(181, -39),
        Pair(165, -32), Pair(49, 91), Pair(117, 46), Pair(-34, 59), Pair(3, 75), Pair(112, -127), Pair(-30, 29), Pair(-4, 55),
        Pair(37, 102), Pair(0, 68), Pair(-78, 158), Pair(31, 4), Pair(1, 56), Pair(-33, 68), Pair(32, 47), Pair(-107, 79),
        Pair(-63, 77), Pair(80, -12), Pair(-56, 188), Pair(174, -18), Pair(145, 56), Pair(60, -11), Pair(27, -33), Pair(1, -5),
        Pair(-199, 111), Pair(16, -43), Pair(95, 124), Pair(67, 48), Pair(-61, 102), Pair(81, 1), Pair(-93, 20), Pair(29, 72),
        Pair(78, 84), Pair(33, 119), Pair(0, 0), Pair(6, 162), Pair(109, 57), Pair(10, 50), Pair(19, 143), Pair(56, 56),
        Pair(9, 89), Pair(-22, -18), Pair(15, 118), Pair(0, -41), Pair(-57, 111), Pair(50, 89), Pair(-116, 121), Pair(68, 64)
      },
      { // Piece 4
        Pair(-20, -30), Pair(160, 19), Pair(-74, 143), Pair(-7, -80), Pair(96, -40), Pair(2, -86), Pair(99, 134), Pair(-68, 99),
        Pair(-14, 121), Pair(-14, 17), Pair(-147, 140), Pair(-34, 114), Pair(-162, 1), Pair(-2, 7), Pair(29, 137), Pair(-21, 66),
        Pair(-141, -17), Pair(24, 50), Pair(-54, 26), Pair(-32, 36), Pair(27, 37), Pair(-96, -8), Pair(2, 86), Pair(71, -68),
        Pair(-12, 53), Pair(106, -129), Pair(-11, 38), Pair(-33, 35), Pair(65, -46), Pair(-18, 42), Pair(53, -118), Pair(32, 82),
        Pair(61, -116), Pair(31, 127), Pair(205, -89), Pair(52, -81), Pair(9, 54), Pair(-4, -11), Pair(20, -141), Pair(17, -99),
        Pair(-28, 78), Pair(35, -50), Pair(44, 25), Pair(31, -30), Pair(-55, 51), Pair(-81, -2), Pair(-74, 90), Pair(-26, -127),
        Pair(67, -72), Pair(11, -15), Pair(0, 0), Pair(63, -164), Pair(33, -58), Pair(29, -48), Pair(-139, -153), Pair(-274, -25),
        Pair(31, 11), Pair(25, -65), Pair(6, 73), Pair(-7, -69), Pair(-5, 161), Pair(-85, -42), Pair(118, 17), Pair(-21, -79)
      },
      { // Piece 5
        Pair(-25, -47), Pair(-5, -46), Pair(-32, -170), Pair(-13, 16), Pair(-8, -102), Pair(28, 4), Pair(49, -150), Pair(-44, -128),
        Pair(4, 166), Pair(-30, -94), Pair(-38, -34), Pair(-1, 23), Pair(5, 22), Pair(32, -33), Pair(-8, -99), Pair(-20, -112),
        Pair(-133, -93), Pair(-6, -79), Pair(-89, -48), Pair(100, 21), Pair(95, 16), Pair(68, -32), Pair(-78, 5), Pair(55, -76),
        Pair(-35, -66), Pair(-44, -31), Pair(56, -18), Pair(-1, -50), Pair(12, 9), Pair(60, 4), Pair(4, -26), Pair(-87, -33),
        Pair(29, -16), Pair(47, 32), Pair(-20, -6), Pair(67, -22), Pair(102, -33), Pair(-28, 5), Pair(19, 6), Pair(42, -23),
        Pair(-31, 173), Pair(54, 127), Pair(-73, 81), Pair(64, 36), Pair(-17, 39), Pair(40, -6), Pair(-44, -23), Pair(57, -84),
        Pair(-21, -10), Pair(-261, 182), Pair(0, 0), Pair(14, 117), Pair(-39, 44), Pair(7, -5), Pair(17, -28), Pair(-24, -48),
        Pair(-52, 112), Pair(118, -31), Pair(-37, 141), Pair(-3, -8), Pair(-119, 105), Pair(51, -78), Pair(24, -54), Pair(54, -152)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-40, 30), Pair(-45, 7), Pair(41, -46), Pair(0, 0), Pair(-2, -32), Pair(59, -68), Pair(21, -11), Pair(-13, -23),
        Pair(-58, 30), Pair(-42, -1), Pair(-78, 34), Pair(76, -51), Pair(-55, 66), Pair(4, 21), Pair(-79, 60), Pair(-30, 16),
        Pair(28, -26), Pair(8, -49), Pair(-27, 3), Pair(35, -7), Pair(59, -15), Pair(20, -12), Pair(-25, -1), Pair(52, -23),
        Pair(10, -23), Pair(48, -39), Pair(-14, 2), Pair(4, -21), Pair(37, -46), Pair(20, -17), Pair(27, -8), Pair(50, -23),
        Pair(45, -40), Pair(89, -48), Pair(41, 3), Pair(12, -84), Pair(21, -8), Pair(-15, 16), Pair(14, -15), Pair(27, -20),
        Pair(-9, -23), Pair(36, -50), Pair(-4, -3), Pair(0, 0), Pair(-70, -53), Pair(3, -11), Pair(-2, 16), Pair(31, -29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, -57), Pair(-73, -156), Pair(-24, -23), Pair(-59, -17), Pair(9, -31), Pair(10, -92), Pair(-48, -96), Pair(25, -51),
        Pair(-7, -111), Pair(32, -50), Pair(-139, -56), Pair(30, 33), Pair(5, -134), Pair(227, -115), Pair(-64, -20), Pair(85, -52),
        Pair(-41, 72), Pair(25, 48), Pair(26, 51), Pair(-38, 20), Pair(19, 11), Pair(-36, -69), Pair(65, -59), Pair(-193, 20),
        Pair(-101, 24), Pair(-36, 110), Pair(176, 26), Pair(211, -16), Pair(59, 35), Pair(115, -30), Pair(173, -46), Pair(24, -76),
        Pair(1, 107), Pair(0, 61), Pair(118, 3), Pair(-18, -30), Pair(305, -12), Pair(75, 30), Pair(-85, -16), Pair(81, 25),
        Pair(-59, -97), Pair(93, 126), Pair(-98, 103), Pair(-75, -5), Pair(-9, 125), Pair(89, 52), Pair(-8, 16), Pair(-56, -11),
        Pair(-118, 18), Pair(-90, 179), Pair(-130, 86), Pair(0, 0), Pair(-154, 152), Pair(-23, 104), Pair(-13, -42), Pair(-26, 73),
        Pair(-62, -63), Pair(41, 131), Pair(-112, -161), Pair(-43, 190), Pair(28, -94), Pair(39, 128), Pair(-264, -171), Pair(25, -31)
      },
      { // Piece 2
        Pair(-101, 80), Pair(-75, -69), Pair(-95, 59), Pair(51, -65), Pair(24, 62), Pair(-4, -120), Pair(55, 92), Pair(-27, -25),
        Pair(-90, 11), Pair(67, 76), Pair(131, 58), Pair(-60, -7), Pair(-6, -3), Pair(-61, 93), Pair(134, -17), Pair(-37, 191),
        Pair(-78, 5), Pair(-162, 15), Pair(-36, 121), Pair(169, -31), Pair(-2, 55), Pair(172, -104), Pair(14, 120), Pair(-28, 78),
        Pair(-31, -8), Pair(61, 109), Pair(109, -49), Pair(126, 78), Pair(-43, 2), Pair(-2, 106), Pair(-24, -20), Pair(-13, 214),
        Pair(-80, 218), Pair(79, 64), Pair(15, 63), Pair(-44, -91), Pair(-71, 149), Pair(164, -36), Pair(-76, 229), Pair(85, 99),
        Pair(84, -118), Pair(-152, 214), Pair(120, 50), Pair(109, 137), Pair(109, 41), Pair(30, 192), Pair(-39, 32), Pair(-61, 40),
        Pair(-6, 7), Pair(78, -28), Pair(-39, 241), Pair(0, 0), Pair(-85, 235), Pair(16, -59), Pair(55, -52), Pair(-53, 134),
        Pair(-84, -42), Pair(-58, 67), Pair(0, -20), Pair(13, 250), Pair(-85, -72), Pair(-13, 7), Pair(-105, -36), Pair(-282, 73)
      },
      { // Piece 3
        Pair(124, 46), Pair(19, 87), Pair(30, 14), Pair(72, 74), Pair(7, 54), Pair(101, 6), Pair(53, 28), Pair(29, 47),
        Pair(7, 49), Pair(-78, 80), Pair(-60, 111), Pair(69, 121), Pair(-125, 98), Pair(234, -5), Pair(107, -71), Pair(91, -38),
        Pair(27, 28), Pair(-74, 148), Pair(109, 83), Pair(72, 68), Pair(41, 80), Pair(136, -57), Pair(-68, -31), Pair(216, -124),
        Pair(-92, 60), Pair(52, 21), Pair(-88, 31), Pair(85, 118), Pair(94, -26), Pair(35, 22), Pair(-25, 46), Pair(126, 3),
        Pair(73, 78), Pair(58, 12), Pair(-50, 38), Pair(170, 87), Pair(64, 5), Pair(7, 57), Pair(-70, 19), Pair(32, -25),
        Pair(-121, 128), Pair(99, 25), Pair(-74, 70), Pair(-86, 181), Pair(153, -26), Pair(77, 76), Pair(-164, 13), Pair(230, 40),
        Pair(22, 14), Pair(-66, 94), Pair(60, 53), Pair(0, 0), Pair(-42, -16), Pair(23, 93), Pair(45, 99), Pair(91, 92),
        Pair(-24, 81), Pair(46, 43), Pair(-38, -9), Pair(91, 77), Pair(57, 16), Pair(56, 21), Pair(29, 45), Pair(-40, 119)
      },
      { // Piece 4
        Pair(6, -117), Pair(-108, 19), Pair(-96, -56), Pair(-49, 6), Pair(43, -40), Pair(57, -47), Pair(43, -75), Pair(6, -19),
        Pair(-77, -58), Pair(-92, -11), Pair(-21, -26), Pair(-61, 31), Pair(3, 33), Pair(-75, 39), Pair(85, 45), Pair(64, -12),
        Pair(-48, -27), Pair(-50, 55), Pair(2, 17), Pair(2, -121), Pair(-53, 53), Pair(4, -77), Pair(79, -194), Pair(30, -115),
        Pair(28, 8), Pair(75, 24), Pair(-4, -89), Pair(-69, 117), Pair(1, -79), Pair(86, 29), Pair(-87, -27), Pair(-108, 83),
        Pair(130, -39), Pair(15, 41), Pair(182, -63), Pair(-40, 8), Pair(129, 29), Pair(57, -29), Pair(-32, 105), Pair(150, -129),
        Pair(-55, -44), Pair(-23, -21), Pair(109, 41), Pair(93, 93), Pair(128, 55), Pair(-40, 13), Pair(-39, -140), Pair(48, -11),
        Pair(105, -121), Pair(48, -93), Pair(55, 58), Pair(0, 0), Pair(120, -126), Pair(-45, 95), Pair(-59, 42), Pair(-28, -8),
        Pair(-177, 31), Pair(-74, -19), Pair(-191, -38), Pair(42, -195), Pair(-79, -107), Pair(-130, -107), Pair(28, 53), Pair(-5, 82)
      },
      { // Piece 5
        Pair(-12, -34), Pair(-26, -150), Pair(18, 78), Pair(-12, -68), Pair(15, 33), Pair(-60, -118), Pair(55, 13), Pair(3, 18),
        Pair(-25, -128), Pair(-48, -67), Pair(16, -39), Pair(53, 88), Pair(18, 53), Pair(-3, -50), Pair(-66, -195), Pair(16, -18),
        Pair(-2, -41), Pair(86, -127), Pair(74, 102), Pair(-25, -66), Pair(31, -108), Pair(-30, -134), Pair(118, -27), Pair(13, -63),
        Pair(64, 75), Pair(53, -33), Pair(76, 66), Pair(-131, 12), Pair(-31, -29), Pair(36, 21), Pair(4, 1), Pair(46, -43),
        Pair(66, -65), Pair(-71, 56), Pair(-62, 34), Pair(64, 9), Pair(-86, 60), Pair(-68, 52), Pair(-140, 15), Pair(-28, -27),
        Pair(84, -114), Pair(12, 12), Pair(-33, 126), Pair(-182, 103), Pair(35, 63), Pair(34, 25), Pair(31, -41), Pair(100, -103),
        Pair(-18, 4), Pair(42, 19), Pair(78, 71), Pair(0, 0), Pair(-9, 73), Pair(0, -7), Pair(-14, 21), Pair(-2, -56),
        Pair(-205, -23), Pair(-94, 75), Pair(-66, -111), Pair(-44, 103), Pair(62, 61), Pair(-109, 56), Pair(-17, -28), Pair(52, -115)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-144, 59), Pair(-120, 18), Pair(72, -26), Pair(2, 32), Pair(0, 0), Pair(13, -6), Pair(-56, -44), Pair(85, -12),
        Pair(17, -1), Pair(-11, -15), Pair(-3, 11), Pair(43, -24), Pair(83, -5), Pair(-112, -12), Pair(-6, -27), Pair(-10, 22),
        Pair(-61, -8), Pair(-8, -40), Pair(-64, 24), Pair(5, -38), Pair(34, -31), Pair(39, 3), Pair(69, -28), Pair(-54, 21),
        Pair(-20, -24), Pair(-1, -40), Pair(28, -12), Pair(24, -34), Pair(-46, 9), Pair(45, 5), Pair(20, -23), Pair(26, -28),
        Pair(1, -26), Pair(-34, -11), Pair(-1, -9), Pair(84, -27), Pair(100, -22), Pair(-41, 32), Pair(11, -12), Pair(-10, 3),
        Pair(-5, -5), Pair(-17, -11), Pair(-9, 9), Pair(38, 30), Pair(0, 0), Pair(41, -28), Pair(12, -8), Pair(45, -38),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-21, -147), Pair(48, -121), Pair(-5, -30), Pair(81, -181), Pair(-32, -91), Pair(20, -67), Pair(-11, -118), Pair(-257, -24),
        Pair(15, -117), Pair(11, -113), Pair(-24, -94), Pair(-33, 36), Pair(-25, 83), Pair(35, 42), Pair(-16, -117), Pair(129, -51),
        Pair(-162, -9), Pair(-62, -71), Pair(-86, -39), Pair(-132, -119), Pair(75, 80), Pair(32, -112), Pair(67, 163), Pair(111, -71),
        Pair(-8, -37), Pair(-19, -108), Pair(47, 79), Pair(183, -5), Pair(46, 26), Pair(64, 64), Pair(20, 57), Pair(89, 122),
        Pair(-21, 2), Pair(-157, 37), Pair(4, -38), Pair(-38, 55), Pair(37, 22), Pair(54, 107), Pair(61, -51), Pair(18, 18),
        Pair(27, -100), Pair(17, 192), Pair(-132, 87), Pair(8, 86), Pair(-32, 89), Pair(67, 78), Pair(-52, 19), Pair(70, -95),
        Pair(-113, -59), Pair(-11, 66), Pair(-99, 155), Pair(-29, 66), Pair(0, 0), Pair(71, 0), Pair(-136, 184), Pair(33, -50),
        Pair(-9, -107), Pair(-123, -20), Pair(182, -20), Pair(-114, -148), Pair(223, 106), Pair(-53, -146), Pair(121, 42), Pair(4, 10)
      },
      { // Piece 2
        Pair(250, -60), Pair(-70, -33), Pair(15, -33), Pair(-108, 176), Pair(-148, -94), Pair(32, 44), Pair(-72, -105), Pair(72, 73),
        Pair(-170, 54), Pair(-86, -15), Pair(-91, 59), Pair(61, -24), Pair(-56, 139), Pair(-49, -94), Pair(-108, 50), Pair(-19, 5),
        Pair(8, -69), Pair(-119, 89), Pair(-122, -56), Pair(-41, 105), Pair(37, -23), Pair(-34, 142), Pair(-106, -16), Pair(58, 73),
        Pair(-207, 151), Pair(22, 42), Pair(54, 85), Pair(225, -135), Pair(-66, 45), Pair(-60, -24), Pair(8, 132), Pair(-35, 54),
        Pair(-111, 45), Pair(-135, 246), Pair(150, -1), Pair(-63, 97), Pair(149, -108), Pair(58, 146), Pair(29, 44), Pair(-134, 127),
        Pair(119, -121), Pair(21, -90), Pair(-64, 187), Pair(173, 66), Pair(60, 104), Pair(62, 23), Pair(81, 146), Pair(103, -131),
        Pair(101, -124), Pair(-88, 166), Pair(-63, 33), Pair(-71, 185), Pair(0, 0), Pair(-20, 218), Pair(-42, 28), Pair(-99, 76),
        Pair(18, 50), Pair(123, -37), Pair(-119, 183), Pair(-14, 4), Pair(79, 215), Pair(-174, -179), Pair(-107, -20), Pair(-59, 12)
      },
      { // Piece 3
        Pair(-151, 96), Pair(-18, 79), Pair(108, 55), Pair(-15, 116), Pair(160, 85), Pair(93, 57), Pair(-84, 69), Pair(170, 12),
        Pair(117, -16), Pair(41, -55), Pair(-19, -22), Pair(-90, -24), Pair(113, 56), Pair(97, -79), Pair(45, -49), Pair(-81, 2),
        Pair(-62, -30), Pair(-37, 4), Pair(-158, 29), Pair(-1, 88), Pair(39, 33), Pair(42, -101), Pair(110, -80), Pair(-41, -1),
        Pair(101, 4), Pair(-95, 67), Pair(-146, 85), Pair(-50, 23), Pair(85, 87), Pair(64, -80), Pair(-110, 58), Pair(-55, -40),
        Pair(115, 72), Pair(-124, 0), Pair(51, 107), Pair(34, 53), Pair(25, 78), Pair(151, 24), Pair(158, -7), Pair(4, 33),
        Pair(-70, 15), Pair(-237, 73), Pair(56, -40), Pair(93, -9), Pair(147, 142), Pair(24, 49), Pair(25, 117), Pair(32, -55),
        Pair(-41, -3), Pair(-83, -40), Pair(9, 31), Pair(160, -61), Pair(0, 0), Pair(-4, 68), Pair(-45, 131), Pair(128, -26),
        Pair(-23, 61), Pair(41, 0), Pair(-53, 107), Pair(-51, -47), Pair(115, 74), Pair(-111, 36), Pair(-94, 104), Pair(-64, 109)
      },
      { // Piece 4
        Pair(-58, 46), Pair(-91, -48), Pair(48, 120), Pair(-26, 84), Pair(11, 12), Pair(60, -30), Pair(-71, -21), Pair(76, -23),
        Pair(49, -36), Pair(-46, -80), Pair(13, -122), Pair(12, 140), Pair(137, 29), Pair(-34, 103), Pair(39, 52), Pair(-160, -25),
        Pair(-60, -73), Pair(54, -17), Pair(-65, -59), Pair(-21, 30), Pair(59, 80), Pair(220, 51), Pair(67, -72), Pair(27, -69),
        Pair(-114, 31), Pair(-65, 41), Pair(35, -53), Pair(18, -181), Pair(142, -127), Pair(-111, -64), Pair(50, 37), Pair(-115, -32),
        Pair(-128, -27), Pair(-38, 53), Pair(-14, 50), Pair(56, 115), Pair(-58, 148), Pair(81, 9), Pair(67, -25), Pair(55, 30),
        Pair(-102, -4), Pair(-23, -200), Pair(40, 41), Pair(64, -216), Pair(12, -49), Pair(-24, 47), Pair(-130, -15), Pair(-12, -10),
        Pair(102, 18), Pair(-68, 42), Pair(-14, -113), Pair(-109, 89), Pair(0, 0), Pair(33, -19), Pair(-156, -3), Pair(107, -130),
        Pair(-40, -143), Pair(-10, -6), Pair(48, -161), Pair(-95, -54), Pair(-132, -97), Pair(-72, -18), Pair(-182, 4), Pair(-66, 12)
      },
      { // Piece 5
        Pair(-47, -12), Pair(-23, -165), Pair(14, -6), Pair(-56, -127), Pair(26, 7), Pair(-24, -113), Pair(10, -191), Pair(8, -45),
        Pair(30, -80), Pair(-13, -58), Pair(-55, 72), Pair(57, 79), Pair(-19, -104), Pair(32, -81), Pair(-119, -196), Pair(31, -24),
        Pair(75, 32), Pair(-131, -57), Pair(-13, -46), Pair(-29, 20), Pair(-40, -29), Pair(65, 4), Pair(80, -127), Pair(-94, -55),
        Pair(-74, -66), Pair(-18, 0), Pair(-33, -2), Pair(5, -45), Pair(-103, 12), Pair(14, 17), Pair(93, -32), Pair(-69, -33),
        Pair(15, -111), Pair(35, 37), Pair(69, -24), Pair(-19, 32), Pair(-32, 116), Pair(-33, 84), Pair(53, 14), Pair(-85, 5),
        Pair(-92, -75), Pair(-30, 71), Pair(-162, 102), Pair(-34, 104), Pair(33, 129), Pair(72, 124), Pair(107, 56), Pair(99, 10),
        Pair(-59, 29), Pair(-21, 68), Pair(-52, 77), Pair(-2, 105), Pair(0, 0), Pair(20, 159), Pair(48, 55), Pair(113, 12),
        Pair(-67, -82), Pair(98, -171), Pair(-44, 26), Pair(-2, 9), Pair(74, 156), Pair(30, 28), Pair(-82, 91), Pair(35, -53)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-42, 22), Pair(-97, -14), Pair(-33, 39), Pair(-59, 68), Pair(-13, 6), Pair(0, 0), Pair(-136, 30), Pair(-49, 24),
        Pair(-38, 0), Pair(-22, -23), Pair(-107, 36), Pair(-17, 15), Pair(107, -22), Pair(-82, -31), Pair(16, -22), Pair(-69, 27),
        Pair(-8, -12), Pair(-11, -8), Pair(-43, -31), Pair(-1, 13), Pair(-3, -19), Pair(55, -15), Pair(-31, 3), Pair(-18, -3),
        Pair(13, -39), Pair(6, -20), Pair(17, -40), Pair(17, -26), Pair(-17, 27), Pair(-1, -21), Pair(-52, -7), Pair(-30, -15),
        Pair(41, -32), Pair(38, -14), Pair(-11, -25), Pair(-16, -24), Pair(70, -70), Pair(112, -77), Pair(-24, 20), Pair(-46, 23),
        Pair(4, -15), Pair(27, -9), Pair(18, -68), Pair(-112, 19), Pair(-5, -124), Pair(0, 0), Pair(34, -18), Pair(-36, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(30, 38), Pair(-104, -206), Pair(-138, -57), Pair(46, 22), Pair(13, 57), Pair(4, -18), Pair(-112, -36), Pair(-21, -16),
        Pair(-119, -133), Pair(-131, -57), Pair(93, 45), Pair(-64, -90), Pair(-92, -129), Pair(-59, -38), Pair(30, -90), Pair(-88, -124),
        Pair(57, -155), Pair(-62, 111), Pair(-57, -38), Pair(1, 16), Pair(149, -62), Pair(-26, 127), Pair(131, 53), Pair(-79, -43),
        Pair(-37, -65), Pair(60, -69), Pair(-47, 92), Pair(-64, 113), Pair(51, -29), Pair(64, 26), Pair(-2, -34), Pair(56, -11),
        Pair(5, -157), Pair(-195, 48), Pair(-33, -16), Pair(58, -99), Pair(101, 77), Pair(-8, 39), Pair(117, 133), Pair(16, -54),
        Pair(56, -181), Pair(18, 59), Pair(-3, 23), Pair(28, -11), Pair(-106, 155), Pair(80, 51), Pair(-11, 107), Pair(-4, 81),
        Pair(-89, -148), Pair(0, -93), Pair(-91, -5), Pair(7, 103), Pair(21, 43), Pair(0, 0), Pair(-29, 50), Pair(-55, 62),
        Pair(-54, 45), Pair(-167, 62), Pair(-183, -115), Pair(-61, 74), Pair(-51, -25), Pair(-30, 132), Pair(-100, -47), Pair(72, 102)
      },
      { // Piece 2
        Pair(10, 141), Pair(-46, -10), Pair(-9, 49), Pair(-275, 101), Pair(-76, -9), Pair(-121, -77), Pair(-55, 69), Pair(-181, -124),
        Pair(-4, 152), Pair(51, 89), Pair(-153, 102), Pair(-156, 33), Pair(2, 14), Pair(-55, -52), Pair(152, 28), Pair(2, 41),
        Pair(-26, 148), Pair(76, 79), Pair(-84, 110), Pair(-185, -5), Pair(-183, 96), Pair(1, 73), Pair(19, -32), Pair(-7, -14),
        Pair(-48, 8), Pair(206, 79), Pair(-34, 148), Pair(-35, 43), Pair(181, -10), Pair(128, 12), Pair(21, 3), Pair(-19, 162),
        Pair(-104, -8), Pair(-121, -20), Pair(38, 138), Pair(194, 89), Pair(1, 70), Pair(109, -91), Pair(1, 144), Pair(17, -10),
        Pair(109, 126), Pair(-123, 59), Pair(110, -103), Pair(-46, 175), Pair(54, -119), Pair(4, 95), Pair(32, 117), Pair(-128, 224),
        Pair(-252, -104), Pair(-3, -32), Pair(-200, -8), Pair(35, -46), Pair(-78, 207), Pair(0, 0), Pair(74, 134), Pair(-127, -105),
        Pair(27, 46), Pair(-45, -11), Pair(2, -35), Pair(-90, 91), Pair(-14, -85), Pair(44, 188), Pair(-19, -65), Pair(-30, -53)
      },
      { // Piece 3
        Pair(25, -17), Pair(1, 44), Pair(-12, -47), Pair(14, 23), Pair(-36, 34), Pair(15, 92), Pair(19, 56), Pair(33, 51),
        Pair(88, -63), Pair(-114, -17), Pair(72, 24), Pair(-14, 33), Pair(-112, 80), Pair(30, 30), Pair(92, 22), Pair(-17, -13),
        Pair(92, -4), Pair(-106, 49), Pair(-128, -79), Pair(84, -58), Pair(74, -42), Pair(-39, 85), Pair(-8, -42), Pair(4, -43),
        Pair(-92, 8), Pair(75, -103), Pair(-14, -80), Pair(-31, 30), Pair(-39, 26), Pair(75, 94), Pair(31, 3), Pair(212, -74),
        Pair(173, 23), Pair(-86, -78), Pair(-126, -116), Pair(-55, 131), Pair(162, -48), Pair(98, 47), Pair(-157, -51), Pair(-88, 9),
        Pair(-9, -9), Pair(-6, -92), Pair(-109, -5), Pair(-41, 85), Pair(-2, -14), Pair(-33, 159), Pair(31, 99), Pair(52, -6),
        Pair(82, -22), Pair(-113, -65), Pair(-38, -77), Pair(10, 24), Pair(67, 61), Pair(0, 0), Pair(187, -139), Pair(-75, 79),
        Pair(-88, 97), Pair(69, -14), Pair(-99, 99), Pair(-13, 5), Pair(10, -68), Pair(60, 57), Pair(-14, -30), Pair(-26, 75)
      },
      { // Piece 4
        Pair(15, -80), Pair(-169, -177), Pair(-92, -40), Pair(18, 53), Pair(85, -90), Pair(30, -64), Pair(-48, -104), Pair(193, 83),
        Pair(-89, 66), Pair(-53, 108), Pair(25, 109), Pair(-177, 17), Pair(5, 39), Pair(71, -23), Pair(78, 26), Pair(6, -103),
        Pair(-45, -98), Pair(-39, -65), Pair(-23, -10), Pair(-181, -46), Pair(49, 45), Pair(-2, 40), Pair(50, 119), Pair(14, -113),
        Pair(-62, 57), Pair(-3, -75), Pair(87, 15), Pair(-21, 112), Pair(10, 111), Pair(126, 22), Pair(148, 110), Pair(2, -50),
        Pair(-99, -122), Pair(-93, -10), Pair(67, -4), Pair(102, 121), Pair(21, 71), Pair(93, 69), Pair(74, 72), Pair(-101, 72),
        Pair(-75, 102), Pair(3, -38), Pair(48, 48), Pair(-34, 11), Pair(9, -32), Pair(120, 140), Pair(121, 59), Pair(-44, 77),
        Pair(0, -83), Pair(64, 43), Pair(-77, -14), Pair(-97, 120), Pair(-41, 163), Pair(0, 0), Pair(31, 61), Pair(-38, -17),
        Pair(20, 13), Pair(-38, 31), Pair(-10, -100), Pair(-27, -65), Pair(-94, -93), Pair(43, -132), Pair(-7, -56), Pair(22, 1)
      },
      { // Piece 5
        Pair(43, 132), Pair(-31, -42), Pair(27, -38), Pair(-5, -34), Pair(-37, -60), Pair(7, -3), Pair(3, -58), Pair(16, 54),
        Pair(11, -16), Pair(-103, -80), Pair(59, -70), Pair(-17, -87), Pair(-48, -116), Pair(119, 64), Pair(-26, -170), Pair(7, -103),
        Pair(71, 112), Pair(-6, -22), Pair(54, 15), Pair(84, -125), Pair(15, 1), Pair(-105, -53), Pair(-26, -192), Pair(74, -40),
        Pair(15, 20), Pair(-76, -33), Pair(-107, -38), Pair(107, -71), Pair(-28, 49), Pair(44, 20), Pair(47, 92), Pair(60, 15),
        Pair(-127, -119), Pair(-76, -43), Pair(54, -47), Pair(-6, -41), Pair(111, -30), Pair(130, 32), Pair(88, -16), Pair(231, -65),
        Pair(-156, -79), Pair(-63, -48), Pair(-3, -38), Pair(-117, 58), Pair(-17, 14), Pair(39, 72), Pair(49, 49), Pair(-16, 31),
        Pair(-182, 99), Pair(-29, -17), Pair(-47, 0), Pair(-8, 63), Pair(138, 66), Pair(0, 0), Pair(-40, 145), Pair(32, 10),
        Pair(-70, -169), Pair(2, -68), Pair(-80, -7), Pair(12, -73), Pair(94, 128), Pair(114, 81), Pair(76, 64), Pair(-119, 63)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-53, 5), Pair(-44, 2), Pair(-156, 39), Pair(-21, 11), Pair(56, 44), Pair(136, -30), Pair(0, 0), Pair(39, -66),
        Pair(-47, -8), Pair(54, 2), Pair(28, -24), Pair(-1, -12), Pair(14, 2), Pair(48, 18), Pair(-2, -47), Pair(-40, -12),
        Pair(-45, -14), Pair(-31, -6), Pair(-17, -10), Pair(-34, -51), Pair(10, -4), Pair(20, 1), Pair(12, 3), Pair(57, -8),
        Pair(-10, -33), Pair(-54, 11), Pair(22, -47), Pair(16, -61), Pair(13, -21), Pair(37, -7), Pair(-121, 42), Pair(68, -14),
        Pair(-38, -6), Pair(-86, -25), Pair(25, -20), Pair(-43, -12), Pair(-24, -15), Pair(-36, 3), Pair(23, -108), Pair(54, -11),
        Pair(-39, -8), Pair(-39, 11), Pair(-4, -40), Pair(-13, -5), Pair(-25, -21), Pair(6, 21), Pair(0, 0), Pair(25, 32),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(108, 7), Pair(-140, -68), Pair(-90, -155), Pair(-18, -70), Pair(65, 10), Pair(99, -143), Pair(-46, -42), Pair(41, -13),
        Pair(-106, -111), Pair(-251, -51), Pair(189, -182), Pair(-161, -34), Pair(-18, -93), Pair(-89, 31), Pair(24, 84), Pair(-80, -149),
        Pair(46, 4), Pair(103, -18), Pair(-94, -32), Pair(-42, -34), Pair(-18, -20), Pair(50, -137), Pair(26, -22), Pair(32, -177),
        Pair(-47, -67), Pair(-5, 6), Pair(46, -66), Pair(52, 51), Pair(128, -110), Pair(-111, 95), Pair(-21, -124), Pair(107, -85),
        Pair(-61, 33), Pair(101, -5), Pair(83, -64), Pair(-60, 11), Pair(-56, 60), Pair(-16, 83), Pair(-109, 30), Pair(-174, 307),
        Pair(34, -6), Pair(-50, 33), Pair(-48, -36), Pair(-130, 27), Pair(-74, 86), Pair(36, 67), Pair(-25, 121), Pair(-261, 175),
        Pair(-85, -78), Pair(-61, -98), Pair(121, 34), Pair(3, -60), Pair(-76, 120), Pair(-43, -155), Pair(0, 0), Pair(-73, 65),
        Pair(-72, -69), Pair(-174, 4), Pair(-163, 30), Pair(-151, -32), Pair(45, 107), Pair(-112, -160), Pair(145, 121), Pair(-13, -17)
      },
      { // Piece 2
        Pair(31, 35), Pair(-159, 48), Pair(-29, -30), Pair(-37, 119), Pair(-14, -32), Pair(-46, 83), Pair(-30, 17), Pair(-36, -57),
        Pair(-179, 205), Pair(51, -45), Pair(-145, 166), Pair(-2, -73), Pair(199, 79), Pair(25, -2), Pair(-154, 38), Pair(41, -162),
        Pair(-15, -113), Pair(-259, 222), Pair(17, -15), Pair(-90, 145), Pair(75, -25), Pair(-75, 81), Pair(-103, -2), Pair(53, 9),
        Pair(8, 50), Pair(65, -57), Pair(-156, 146), Pair(-161, 15), Pair(-39, 96), Pair(140, -30), Pair(-70, 158), Pair(78, -26),
        Pair(-29, -42), Pair(-106, 16), Pair(53, -29), Pair(-58, 161), Pair(110, 61), Pair(41, 90), Pair(69, 18), Pair(172, 72),
        Pair(-117, 160), Pair(-166, -32), Pair(-108, 40), Pair(-59, -36), Pair(-8, 111), Pair(-55, 157), Pair(11, -49), Pair(238, -26),
        Pair(-7, -38), Pair(-17, 158), Pair(-28, -33), Pair(4, -86), Pair(35, -126), Pair(67, 192), Pair(0, 0), Pair(-55, 216),
        Pair(3, 198), Pair(-68, -224), Pair(-65, -8), Pair(-35, -12), Pair(-120, 115), Pair(-30, -67), Pair(17, 192), Pair(-51, 0)
      },
      { // Piece 3
        Pair(-177, 64), Pair(-44, 16), Pair(85, 22), Pair(-17, 32), Pair(125, -1), Pair(46, 102), Pair(87, 81), Pair(333, -34),
        Pair(204, -70), Pair(8, -57), Pair(177, -211), Pair(216, -145), Pair(-33, 22), Pair(154, -55), Pair(157, 57), Pair(4, -26),
        Pair(-147, -10), Pair(-69, -17), Pair(-236, 29), Pair(-15, -50), Pair(10, -23), Pair(59, 10), Pair(-25, 82), Pair(26, -58),
        Pair(143, -79), Pair(19, -37), Pair(-15, -29), Pair(89, -54), Pair(0, 35), Pair(43, 13), Pair(160, 72), Pair(-13, -7),
        Pair(-118, 62), Pair(148, -103), Pair(-90, -25), Pair(-35, -35), Pair(31, 66), Pair(129, -125), Pair(77, 79), Pair(230, -102),
        Pair(-144, 52), Pair(-64, -82), Pair(-10, 90), Pair(87, 3), Pair(78, 28), Pair(31, -24), Pair(101, 88), Pair(-41, 27),
        Pair(-10, -56), Pair(-145, 86), Pair(-134, 39), Pair(-163, 15), Pair(186, 36), Pair(132, -35), Pair(0, 0), Pair(43, -20),
        Pair(-45, 69), Pair(-113, 94), Pair(52, -21), Pair(-53, 49), Pair(101, 15), Pair(-34, -65), Pair(228, 29), Pair(112, -73)
      },
      { // Piece 4
        Pair(-149, 44), Pair(7, 62), Pair(-70, 20), Pair(27, 42), Pair(12, 22), Pair(-62, -61), Pair(-16, -49), Pair(-77, -49),
        Pair(167, -27), Pair(26, -2), Pair(-10, 135), Pair(-1, -4), Pair(-7, -4), Pair(-50, -19), Pair(92, -6), Pair(94, 22),
        Pair(-44, -195), Pair(-42, -16), Pair(57, 70), Pair(18, 109), Pair(-52, 6), Pair(-93, -8), Pair(72, -68), Pair(-17, -100),
        Pair(-83, -64), Pair(33, -22), Pair(105, -90), Pair(89, 144), Pair(-36, 0), Pair(28, 72), Pair(40, 64), Pair(142, -64),
        Pair(-132, -77), Pair(43, -41), Pair(33, 25), Pair(3, 55), Pair(-97, -41), Pair(-31, -34), Pair(-36, -106), Pair(-162, -32),
        Pair(-124, -97), Pair(-77, -170), Pair(-9, 162), Pair(48, 22), Pair(-80, 50), Pair(41, -37), Pair(65, 83), Pair(9, -126),
        Pair(-58, 21), Pair(-84, -4), Pair(-7, 70), Pair(88, 22), Pair(-138, 45), Pair(-37, 216), Pair(0, 0), Pair(-149, -78),
        Pair(-65, -49), Pair(-97, -73), Pair(-10, -98), Pair(-32, -17), Pair(59, -67), Pair(-160, -85), Pair(102, 39), Pair(-10, -14)
      },
      { // Piece 5
        Pair(8, -116), Pair(-11, -135), Pair(-16, -85), Pair(3, -144), Pair(-30, -54), Pair(28, 51), Pair(31, 17), Pair(-11, 10),
        Pair(9, -99), Pair(-24, -36), Pair(3, -130), Pair(19, -91), Pair(-14, -19), Pair(7, -62), Pair(16, 20), Pair(-8, -45),
        Pair(-69, -49), Pair(-55, 16), Pair(41, -25), Pair(-38, -21), Pair(147, -44), Pair(68, -49), Pair(-58, -86), Pair(18, 29),
        Pair(-72, -49), Pair(-46, -77), Pair(-14, -14), Pair(29, -84), Pair(-10, -28), Pair(33, 14), Pair(78, -65), Pair(-12, -34),
        Pair(-18, -62), Pair(-103, 22), Pair(68, -68), Pair(28, -38), Pair(25, -6), Pair(-11, 33), Pair(117, 63), Pair(15, 75),
        Pair(28, -15), Pair(68, -48), Pair(-48, 19), Pair(-80, 13), Pair(59, 8), Pair(-85, 69), Pair(-2, 108), Pair(77, 89),
        Pair(-54, -37), Pair(-10, 28), Pair(-106, 5), Pair(-61, 31), Pair(43, 4), Pair(-47, 131), Pair(0, 0), Pair(-10, 153),
        Pair(-108, -199), Pair(-80, -69), Pair(41, -131), Pair(10, -50), Pair(-97, 47), Pair(17, 105), Pair(164, 119), Pair(142, 19)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, 28), Pair(5, 1), Pair(-69, -16), Pair(13, 23), Pair(-85, 12), Pair(49, -24), Pair(-39, 66), Pair(0, 0),
        Pair(36, -8), Pair(5, -22), Pair(-16, -44), Pair(16, -13), Pair(-44, -25), Pair(1, -33), Pair(40, -12), Pair(100, -18),
        Pair(-6, -35), Pair(44, -16), Pair(-1, -11), Pair(13, -14), Pair(-53, -14), Pair(15, -20), Pair(-58, 29), Pair(-216, 11),
        Pair(20, -24), Pair(-24, -8), Pair(-33, -23), Pair(2, -23), Pair(-16, -4), Pair(11, -14), Pair(7, 2), Pair(117, 39),
        Pair(-1, -43), Pair(-42, -8), Pair(31, -30), Pair(-12, -30), Pair(-4, -22), Pair(-20, 4), Pair(57, -24), Pair(27, 25),
        Pair(-11, -38), Pair(-19, -15), Pair(21, -39), Pair(-30, -41), Pair(-29, -19), Pair(1, -15), Pair(-5, -2), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(14, 90), Pair(-27, -63), Pair(76, -38), Pair(-119, -43), Pair(103, -7), Pair(-64, -258), Pair(-35, -119), Pair(89, -48),
        Pair(-41, -134), Pair(-7, -50), Pair(-151, -123), Pair(84, -79), Pair(83, -125), Pair(-39, -56), Pair(167, -206), Pair(-49, -72),
        Pair(-151, -215), Pair(229, -28), Pair(9, -82), Pair(162, -142), Pair(77, -4), Pair(-51, 35), Pair(131, -152), Pair(-54, -60),
        Pair(80, -166), Pair(8, -152), Pair(110, -33), Pair(66, -98), Pair(-46, 5), Pair(75, -47), Pair(128, 9), Pair(126, -119),
        Pair(34, -211), Pair(86, -80), Pair(-49, -22), Pair(-79, -63), Pair(140, -80), Pair(-49, -52), Pair(-156, 35), Pair(165, -164),
        Pair(-169, -41), Pair(21, -136), Pair(21, -44), Pair(-201, 49), Pair(-114, -10), Pair(-19, 28), Pair(34, -17), Pair(-130, 49),
        Pair(-132, -152), Pair(-25, -50), Pair(1, -309), Pair(-14, -33), Pair(55, -13), Pair(111, 15), Pair(-143, -84), Pair(0, 0),
        Pair(-29, -69), Pair(-55, -125), Pair(-253, -44), Pair(49, -95), Pair(-60, -37), Pair(-54, -61), Pair(-119, -125), Pair(-12, 103)
      },
      { // Piece 2
        Pair(-14, 202), Pair(-44, 4), Pair(29, 75), Pair(126, -106), Pair(57, -1), Pair(22, -102), Pair(-32, 81), Pair(-28, -153),
        Pair(2, -101), Pair(-35, 184), Pair(-5, -19), Pair(-131, 80), Pair(-130, -56), Pair(-77, 19), Pair(-61, -73), Pair(20, 110),
        Pair(46, 37), Pair(246, -117), Pair(31, 157), Pair(108, 37), Pair(12, 16), Pair(-261, -131), Pair(46, 106), Pair(-75, -80),
        Pair(119, -43), Pair(33, 94), Pair(-40, 5), Pair(-114, 182), Pair(-23, -27), Pair(-55, 130), Pair(77, -204), Pair(-54, 74),
        Pair(-37, 89), Pair(-68, -80), Pair(57, -20), Pair(-11, -28), Pair(-59, 166), Pair(126, -109), Pair(63, 20), Pair(224, -59),
        Pair(-68, 14), Pair(-21, -102), Pair(141, -64), Pair(27, 32), Pair(45, -54), Pair(-12, 150), Pair(-59, 8), Pair(-72, -20),
        Pair(39, 4), Pair(163, -143), Pair(91, -6), Pair(48, -53), Pair(26, 92), Pair(105, -193), Pair(36, 146), Pair(0, 0),
        Pair(-37, -127), Pair(65, 56), Pair(-64, -77), Pair(-206, -28), Pair(53, -125), Pair(-70, 180), Pair(-27, -100), Pair(7, 203)
      },
      { // Piece 3
        Pair(-4, -64), Pair(56, 58), Pair(-63, 26), Pair(76, 19), Pair(-88, 48), Pair(59, -2), Pair(152, 26), Pair(103, 36),
        Pair(147, -130), Pair(-6, -3), Pair(221, -113), Pair(138, -21), Pair(-15, -45), Pair(-27, -22), Pair(-1, -13), Pair(53, 42),
        Pair(160, -134), Pair(38, 21), Pair(69, -105), Pair(-33, -77), Pair(14, -133), Pair(39, -41), Pair(50, 41), Pair(165, 30),
        Pair(76, -70), Pair(-48, -54), Pair(-80, 11), Pair(54, -29), Pair(-133, -73), Pair(241, -112), Pair(56, -37), Pair(-45, 82),
        Pair(72, -32), Pair(102, -51), Pair(65, -118), Pair(-23, 26), Pair(-7, 0), Pair(193, -29), Pair(-81, 68), Pair(11, 62),
        Pair(124, 80), Pair(-91, 46), Pair(-2, 24), Pair(31, -73), Pair(44, 76), Pair(-125, 51), Pair(-64, 93), Pair(51, 106),
        Pair(87, 4), Pair(-23, 54), Pair(144, 69), Pair(31, 61), Pair(72, 2), Pair(91, -30), Pair(121, 68), Pair(0, 0),
        Pair(-6, 38), Pair(29, 44), Pair(44, 32), Pair(17, -2), Pair(47, 18), Pair(83, 8), Pair(133, -55), Pair(184, 45)
      },
      { // Piece 4
        Pair(-71, 82), Pair(-48, -71), Pair(-52, -75), Pair(-38, -42), Pair(38, -25), Pair(43, -56), Pair(-71, -16), Pair(32, 32),
        Pair(23, 89), Pair(27, 89), Pair(1, 84), Pair(-22, 41), Pair(-73, -29), Pair(40, -75), Pair(186, 88), Pair(66, -22),
        Pair(86, -167), Pair(35, 120), Pair(184, -32), Pair(130, -36), Pair(-109, 130), Pair(45, -76), Pair(-2, 87), Pair(-73, 112),
        Pair(-121, 15), Pair(81, -77), Pair(-9, 24), Pair(-122, 102), Pair(35, -1), Pair(-25, -31), Pair(-7, 15), Pair(107, -146),
        Pair(-155, -165), Pair(-153, 19), Pair(-255, 46), Pair(50, -76), Pair(-27, 70), Pair(103, -67), Pair(104, 49), Pair(120, -92),
        Pair(71, 69), Pair(-52, -102), Pair(-11, -33), Pair(-53, 140), Pair(40, -31), Pair(-27, -31), Pair(-15, -35), Pair(-1, -172),
        Pair(-63, -62), Pair(50, 12), Pair(-151, 23), Pair(-22, -129), Pair(-68, 21), Pair(-58, 87), Pair(24, -41), Pair(0, 0),
        Pair(-156, -156), Pair(-128, -15), Pair(-86, -63), Pair(-90, -53), Pair(22, -46), Pair(-26, 49), Pair(-92, -71), Pair(-75, 23)
      },
      { // Piece 5
        Pair(60, -34), Pair(2, -223), Pair(46, -46), Pair(-18, -153), Pair(-42, -50), Pair(-34, -88), Pair(-19, -34), Pair(-18, -82),
        Pair(42, 6), Pair(23, -36), Pair(-1, -39), Pair(-25, -58), Pair(4, 7), Pair(78, 45), Pair(2, 38), Pair(-6, -69),
        Pair(-25, -154), Pair(17, -38), Pair(-68, -43), Pair(-51, 19), Pair(222, -82), Pair(124, -50), Pair(48, 29), Pair(-43, -114),
        Pair(141, -95), Pair(22, -61), Pair(-65, -38), Pair(8, -33), Pair(33, -9), Pair(9, 32), Pair(28, -29), Pair(-3, -82),
        Pair(53, -53), Pair(-17, -37), Pair(101, -48), Pair(11, -30), Pair(-31, 38), Pair(94, -5), Pair(-133, 77), Pair(28, -1),
        Pair(-68, -72), Pair(175, -139), Pair(-27, -29), Pair(27, -5), Pair(-150, 41), Pair(-166, 123), Pair(-162, 180), Pair(-160, 82),
        Pair(-84, 150), Pair(-67, 75), Pair(-8, -55), Pair(-101, 0), Pair(-68, 87), Pair(-103, 99), Pair(-99, 172), Pair(0, 0),
        Pair(-134, -191), Pair(44, -152), Pair(-29, -81), Pair(-142, -48), Pair(-26, -28), Pair(-220, 146), Pair(99, 89), Pair(201, 172)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 97), Pair(16, -4), Pair(21, -12), Pair(58, -30), Pair(-17, 1), Pair(38, 0), Pair(46, 8), Pair(-35, 9),
        Pair(0, 0), Pair(-25, -8), Pair(40, -17), Pair(1, -17), Pair(54, -23), Pair(19, -3), Pair(32, -7), Pair(-10, 18),
        Pair(-1, -4), Pair(-21, 5), Pair(14, 3), Pair(0, -20), Pair(7, -18), Pair(-18, -4), Pair(-11, 1), Pair(-4, 5),
        Pair(-34, 0), Pair(-6, -7), Pair(9, -4), Pair(1, -16), Pair(-3, 4), Pair(-14, 1), Pair(-17, 2), Pair(-10, -10),
        Pair(0, 0), Pair(-4, -5), Pair(1, -11), Pair(3, -19), Pair(-8, -16), Pair(6, -13), Pair(-6, -8), Pair(-6, -10),
        Pair(15, 25), Pair(-34, 13), Pair(-1, -9), Pair(-2, -12), Pair(-2, -27), Pair(-1, -15), Pair(2, -9), Pair(-6, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(24, 23), Pair(-98, 37), Pair(83, -41), Pair(87, -60), Pair(201, -105), Pair(-41, -82), Pair(-44, -25), Pair(-102, -14),
        Pair(-123, 49), Pair(112, -17), Pair(39, 44), Pair(100, -17), Pair(-60, -28), Pair(58, -41), Pair(74, -38), Pair(105, -116),
        Pair(220, -45), Pair(34, -36), Pair(-13, 33), Pair(53, -25), Pair(30, -22), Pair(86, -23), Pair(-18, -45), Pair(46, -92),
        Pair(-63, 39), Pair(77, 2), Pair(24, 10), Pair(50, -25), Pair(1, -8), Pair(-9, -37), Pair(44, -46), Pair(27, -22),
        Pair(61, 4), Pair(94, 15), Pair(28, 10), Pair(66, -3), Pair(47, -22), Pair(16, -39), Pair(112, -66), Pair(13, -71),
        Pair(0, 0), Pair(-46, 38), Pair(3, 39), Pair(22, -16), Pair(27, -8), Pair(7, -7), Pair(30, -24), Pair(2, 0),
        Pair(-128, 50), Pair(13, -160), Pair(34, 41), Pair(8, 23), Pair(14, -23), Pair(6, -47), Pair(61, -28), Pair(83, -222),
        Pair(-163, 46), Pair(16, -41), Pair(-156, 30), Pair(-8, -25), Pair(-18, -15), Pair(27, -42), Pair(-16, -7), Pair(-100, -58)
      },
      { // Piece 2
        Pair(18, 46), Pair(-14, 7), Pair(-74, -43), Pair(-66, 80), Pair(66, 38), Pair(12, 58), Pair(-238, 214), Pair(-15, 22),
        Pair(22, -5), Pair(-12, 27), Pair(-14, 28), Pair(-116, 50), Pair(38, 129), Pair(88, 131), Pair(11, 79), Pair(-19, 37),
        Pair(-149, 39), Pair(-34, 41), Pair(3, 66), Pair(-9, 140), Pair(-81, 127), Pair(-1, 80), Pair(1, 34), Pair(41, 53),
        Pair(-43, 101), Pair(27, 54), Pair(41, 45), Pair(45, 98), Pair(59, 60), Pair(22, 2), Pair(66, -41), Pair(37, 29),
        Pair(-110, 19), Pair(75, 7), Pair(19, 85), Pair(14, 67), Pair(71, 14), Pair(48, 28), Pair(47, -23), Pair(-9, 24),
        Pair(0, 0), Pair(56, 64), Pair(29, 58), Pair(21, 27), Pair(23, 31), Pair(53, -5), Pair(54, 57), Pair(80, -38),
        Pair(-12, 202), Pair(14, -14), Pair(13, 63), Pair(53, 24), Pair(-20, 20), Pair(41, -33), Pair(40, -18), Pair(45, 6),
        Pair(88, 55), Pair(-63, 96), Pair(49, 48), Pair(-53, 26), Pair(17, 98), Pair(13, -5), Pair(75, -20), Pair(10, -101)
      },
      { // Piece 3
        Pair(38, 93), Pair(-1, 78), Pair(30, 68), Pair(-11, 58), Pair(52, 46), Pair(223, -3), Pair(36, 56), Pair(158, 35),
        Pair(112, 103), Pair(-30, 100), Pair(52, 61), Pair(34, 83), Pair(-20, 88), Pair(-38, 81), Pair(101, 58), Pair(58, 55),
        Pair(97, 138), Pair(28, 98), Pair(104, 90), Pair(-27, 91), Pair(-13, 72), Pair(110, 57), Pair(137, -2), Pair(19, 57),
        Pair(6, 142), Pair(46, 88), Pair(17, 64), Pair(-10, 53), Pair(-30, 97), Pair(46, 30), Pair(109, 44), Pair(144, 23),
        Pair(86, 108), Pair(-23, 125), Pair(36, 115), Pair(54, -2), Pair(5, 45), Pair(-41, 58), Pair(33, 40), Pair(-65, 83),
        Pair(0, 0), Pair(32, 119), Pair(38, 119), Pair(14, 117), Pair(2, 64), Pair(16, 78), Pair(42, 89), Pair(69, 24),
        Pair(56, 72), Pair(38, 16), Pair(13, 81), Pair(12, 78), Pair(77, 55), Pair(60, 43), Pair(69, 62), Pair(-43, 129),
        Pair(-4, 73), Pair(-7, 108), Pair(13, 89), Pair(46, 59), Pair(16, 56), Pair(32, 58), Pair(3, 103), Pair(6, 79)
      },
      { // Piece 4
        Pair(66, 78), Pair(261, -26), Pair(9, 135), Pair(-69, 157), Pair(16, 162), Pair(127, 67), Pair(65, 156), Pair(215, 26),
        Pair(83, 136), Pair(16, 108), Pair(38, 146), Pair(-20, 225), Pair(40, 71), Pair(-9, 230), Pair(-35, 70), Pair(57, 97),
        Pair(-40, 183), Pair(-62, 95), Pair(112, 34), Pair(3, 173), Pair(47, 193), Pair(44, 103), Pair(53, 29), Pair(37, 72),
        Pair(38, 4), Pair(26, 60), Pair(96, 152), Pair(-26, 223), Pair(19, 186), Pair(76, 134), Pair(66, 1), Pair(66, 53),
        Pair(39, 20), Pair(39, 119), Pair(33, 113), Pair(34, 85), Pair(40, 99), Pair(14, 115), Pair(86, 7), Pair(51, -39),
        Pair(0, 0), Pair(11, 138), Pair(-22, 180), Pair(1, 132), Pair(26, 137), Pair(-2, 170), Pair(22, -42), Pair(104, -33),
        Pair(-10, 80), Pair(-51, 21), Pair(-7, 131), Pair(-12, 142), Pair(0, 97), Pair(25, 93), Pair(14, 81), Pair(-4, 63),
        Pair(8, 59), Pair(1, 105), Pair(-38, 220), Pair(-7, 81), Pair(-20, 81), Pair(123, 163), Pair(51, 157), Pair(61, 153)
      },
      { // Piece 5
        Pair(-42, -74), Pair(11, -52), Pair(3, -15), Pair(14, -164), Pair(1, -178), Pair(42, -60), Pair(45, -41), Pair(130, 58),
        Pair(69, -80), Pair(18, 23), Pair(60, -119), Pair(96, -110), Pair(92, -23), Pair(121, -50), Pair(219, -41), Pair(84, 6),
        Pair(106, -62), Pair(2, -20), Pair(107, -89), Pair(84, -37), Pair(176, -83), Pair(-88, -8), Pair(114, -12), Pair(88, -23),
        Pair(52, -42), Pair(32, -6), Pair(-84, 33), Pair(42, -30), Pair(129, -45), Pair(218, -83), Pair(-111, -14), Pair(-98, -11),
        Pair(-53, 2), Pair(-156, 87), Pair(97, -14), Pair(-13, 7), Pair(115, -41), Pair(-6, -31), Pair(-102, 3), Pair(27, -53),
        Pair(0, 0), Pair(71, 41), Pair(-78, 65), Pair(-66, 49), Pair(-59, -10), Pair(-42, -22), Pair(80, -61), Pair(-41, -18),
        Pair(56, 101), Pair(36, 6), Pair(-142, 86), Pair(-16, 38), Pair(-27, 2), Pair(-12, -40), Pair(12, -51), Pair(31, -62),
        Pair(12, 67), Pair(-39, 70), Pair(-73, 55), Pair(-9, 2), Pair(-27, -21), Pair(-14, -52), Pair(-9, -57), Pair(0, -48)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-104, 42), Pair(-94, 36), Pair(118, -7), Pair(42, 1), Pair(11, 15), Pair(22, 24), Pair(-54, -2), Pair(-5, 22),
        Pair(25, 7), Pair(0, 0), Pair(20, -11), Pair(28, 5), Pair(-8, 7), Pair(50, -4), Pair(-79, 39), Pair(8, 12),
        Pair(16, -17), Pair(-16, 8), Pair(11, -2), Pair(5, -23), Pair(-14, 3), Pair(7, -5), Pair(-12, 12), Pair(-22, 11),
        Pair(14, -5), Pair(1, 49), Pair(-4, 1), Pair(10, -10), Pair(7, -5), Pair(-35, 19), Pair(-8, 4), Pair(-10, 8),
        Pair(2, 34), Pair(0, 0), Pair(-11, -9), Pair(13, -21), Pair(-10, -9), Pair(-24, -1), Pair(0, -11), Pair(-27, 6),
        Pair(-9, 28), Pair(16, 33), Pair(-12, -52), Pair(-20, 17), Pair(-15, -1), Pair(-31, -7), Pair(-15, -10), Pair(-29, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-6, -96), Pair(-75, 60), Pair(55, 34), Pair(-57, 48), Pair(-58, 22), Pair(48, -85), Pair(33, -11), Pair(-93, -134),
        Pair(195, -129), Pair(136, -187), Pair(-2, 24), Pair(11, 66), Pair(195, 22), Pair(-13, -12), Pair(-1, 24), Pair(73, 89),
        Pair(144, -20), Pair(-134, 85), Pair(131, 11), Pair(32, -6), Pair(193, -74), Pair(28, 44), Pair(2, 14), Pair(-81, -68),
        Pair(82, -8), Pair(74, 107), Pair(128, 21), Pair(69, -1), Pair(10, 42), Pair(60, 11), Pair(62, -65), Pair(39, 3),
        Pair(14, 123), Pair(138, -80), Pair(39, 100), Pair(26, 44), Pair(7, 66), Pair(10, 44), Pair(29, -38), Pair(-27, -53),
        Pair(51, 78), Pair(0, 0), Pair(67, 69), Pair(13, 93), Pair(23, 32), Pair(56, 5), Pair(-7, 19), Pair(43, -95),
        Pair(6, -40), Pair(-143, 181), Pair(-24, 47), Pair(22, 39), Pair(-29, 29), Pair(74, 52), Pair(-103, -4), Pair(137, -111),
        Pair(110, 56), Pair(47, 79), Pair(-2, 61), Pair(-13, 137), Pair(36, 29), Pair(92, -2), Pair(-15, -38), Pair(-142, -121)
      },
      { // Piece 2
        Pair(-80, 85), Pair(-105, 42), Pair(-71, 11), Pair(24, 114), Pair(13, 122), Pair(70, 74), Pair(-68, 26), Pair(-72, 159),
        Pair(186, -125), Pair(-61, 42), Pair(36, 84), Pair(50, 40), Pair(47, 130), Pair(-254, 134), Pair(-118, 189), Pair(-17, 22),
        Pair(68, 23), Pair(70, 30), Pair(-18, 93), Pair(-44, 75), Pair(86, 90), Pair(-31, 151), Pair(-16, 87), Pair(19, 12),
        Pair(-60, 25), Pair(35, 74), Pair(30, 101), Pair(-46, 118), Pair(23, 128), Pair(23, 83), Pair(-5, 74), Pair(105, -14),
        Pair(12, -67), Pair(-76, 177), Pair(-11, 125), Pair(-9, 115), Pair(50, 68), Pair(-23, 67), Pair(-19, 35), Pair(-195, 115),
        Pair(57, 126), Pair(0, 0), Pair(-35, 139), Pair(5, 100), Pair(17, 54), Pair(64, 45), Pair(13, -1), Pair(11, 27),
        Pair(-109, -33), Pair(39, 157), Pair(-48, -5), Pair(-29, 112), Pair(16, 54), Pair(-24, 98), Pair(-8, 89), Pair(-62, 1),
        Pair(7, 129), Pair(47, 49), Pair(-13, 91), Pair(-93, 108), Pair(25, 66), Pair(11, 21), Pair(10, 43), Pair(8, 54)
      },
      { // Piece 3
        Pair(-102, 125), Pair(81, 118), Pair(-4, 96), Pair(57, 79), Pair(150, 59), Pair(181, 24), Pair(-192, 146), Pair(167, 61),
        Pair(4, 60), Pair(130, 113), Pair(48, 75), Pair(108, 65), Pair(113, 49), Pair(128, 22), Pair(112, 4), Pair(80, 46),
        Pair(-3, 58), Pair(87, 163), Pair(-33, 92), Pair(65, 85), Pair(-40, 88), Pair(191, -11), Pair(139, -9), Pair(3, 63),
        Pair(27, 76), Pair(-3, 173), Pair(-55, 125), Pair(-50, 81), Pair(66, 69), Pair(-19, 73), Pair(107, 36), Pair(-35, 86),
        Pair(-68, 98), Pair(69, 182), Pair(-14, 86), Pair(51, 70), Pair(-4, 50), Pair(49, 84), Pair(79, 71), Pair(51, 49),
        Pair(-28, 53), Pair(0, 0), Pair(68, 70), Pair(128, 61), Pair(6, 56), Pair(104, 73), Pair(75, 107), Pair(-33, 50),
        Pair(-65, -79), Pair(27, 91), Pair(90, -17), Pair(-12, 86), Pair(30, 97), Pair(5, 37), Pair(11, 111), Pair(61, 101),
        Pair(-18, 99), Pair(10, 100), Pair(1, 71), Pair(36, 87), Pair(27, 44), Pair(5, 95), Pair(17, 82), Pair(16, 93)
      },
      { // Piece 4
        Pair(37, 46), Pair(135, 87), Pair(-135, 91), Pair(-18, 75), Pair(62, 118), Pair(72, 17), Pair(15, 19), Pair(11, 149),
        Pair(77, 22), Pair(78, 15), Pair(-30, 79), Pair(8, 91), Pair(91, 35), Pair(-14, 115), Pair(102, -32), Pair(106, -12),
        Pair(34, 23), Pair(43, 2), Pair(-3, 109), Pair(16, 94), Pair(28, 98), Pair(61, 82), Pair(-27, 21), Pair(148, -59),
        Pair(70, 21), Pair(-4, 93), Pair(50, 4), Pair(17, 70), Pair(40, 52), Pair(26, 26), Pair(68, 0), Pair(35, 15),
        Pair(104, -31), Pair(10, 138), Pair(95, 105), Pair(13, 127), Pair(66, 29), Pair(50, 51), Pair(89, -15), Pair(47, -62),
        Pair(21, 5), Pair(0, 0), Pair(102, 16), Pair(-25, 145), Pair(30, 53), Pair(-16, 156), Pair(108, -85), Pair(53, 101),
        Pair(-67, 19), Pair(74, 15), Pair(-82, 4), Pair(34, -11), Pair(-31, 174), Pair(-49, 23), Pair(93, 7), Pair(-26, 91),
        Pair(-43, 192), Pair(36, -56), Pair(2, -104), Pair(2, -41), Pair(20, 64), Pair(52, -8), Pair(69, -52), Pair(46, 29)
      },
      { // Piece 5
        Pair(-43, -156), Pair(-52, -116), Pair(39, 22), Pair(-54, -123), Pair(28, 7), Pair(-35, -63), Pair(-27, -53), Pair(-13, -121),
        Pair(10, 37), Pair(19, -56), Pair(18, -69), Pair(-22, 1), Pair(174, -118), Pair(26, -60), Pair(67, -76), Pair(-26, -119),
        Pair(44, 33), Pair(49, -8), Pair(50, -16), Pair(97, -45), Pair(177, -60), Pair(80, -21), Pair(93, -89), Pair(15, -95),
        Pair(-50, -8), Pair(28, -109), Pair(83, 21), Pair(40, -36), Pair(90, -48), Pair(52, -51), Pair(94, -46), Pair(113, -8),
        Pair(150, -17), Pair(-103, 23), Pair(-135, 96), Pair(-77, 20), Pair(-26, -6), Pair(69, -36), Pair(38, -49), Pair(198, -74),
        Pair(-88, 120), Pair(0, 0), Pair(-164, 56), Pair(-218, 61), Pair(-5, -10), Pair(34, -42), Pair(12, -50), Pair(186, -70),
        Pair(79, 42), Pair(-83, 79), Pair(0, 96), Pair(-139, 49), Pair(-21, -30), Pair(-57, -22), Pair(21, -74), Pair(-5, -47),
        Pair(-152, 33), Pair(-52, 29), Pair(-137, 102), Pair(-170, 11), Pair(-82, 41), Pair(15, -65), Pair(0, -37), Pair(71, -81)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-64, 49), Pair(31, -34), Pair(142, -87), Pair(78, -34), Pair(3, -11), Pair(107, -35), Pair(-28, 24), Pair(15, 44),
        Pair(-40, 19), Pair(-21, 10), Pair(0, 0), Pair(7, 7), Pair(4, -1), Pair(-2, 17), Pair(-28, 11), Pair(24, -3),
        Pair(-8, -1), Pair(-7, -15), Pair(57, -22), Pair(-15, -5), Pair(23, -10), Pair(24, 1), Pair(6, 1), Pair(7, -4),
        Pair(-8, -3), Pair(7, -6), Pair(5, -31), Pair(18, -4), Pair(19, -17), Pair(6, -13), Pair(-7, 1), Pair(7, -2),
        Pair(-16, -4), Pair(3, 9), Pair(0, 0), Pair(1, -9), Pair(0, -15), Pair(8, 2), Pair(0, 2), Pair(-5, -12),
        Pair(-6, -8), Pair(-2, 14), Pair(16, 23), Pair(11, -23), Pair(-10, -18), Pair(2, -7), Pair(-8, 10), Pair(5, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-181, -48), Pair(49, -68), Pair(-17, -166), Pair(40, -86), Pair(106, -129), Pair(-69, 39), Pair(97, -82), Pair(-164, -57),
        Pair(5, 29), Pair(72, -18), Pair(-10, 34), Pair(93, 6), Pair(155, -1), Pair(143, -27), Pair(-84, -24), Pair(142, -37),
        Pair(-14, -68), Pair(222, -24), Pair(96, -17), Pair(21, 21), Pair(41, 35), Pair(4, -17), Pair(-3, -47), Pair(3, 38),
        Pair(-66, 20), Pair(67, 83), Pair(56, 33), Pair(35, 59), Pair(24, 9), Pair(50, 60), Pair(4, 29), Pair(151, -134),
        Pair(-57, 142), Pair(50, 115), Pair(-8, 63), Pair(7, 84), Pair(46, -21), Pair(17, 35), Pair(-21, 129), Pair(110, 5),
        Pair(-16, 114), Pair(-6, 87), Pair(0, 0), Pair(3, 80), Pair(-81, 150), Pair(18, 23), Pair(9, -6), Pair(-8, 51),
        Pair(33, -24), Pair(-112, -91), Pair(-7, 138), Pair(-35, 41), Pair(26, 37), Pair(-55, 114), Pair(42, 47), Pair(56, -39),
        Pair(-155, 73), Pair(-41, -22), Pair(8, 49), Pair(23, 115), Pair(60, 104), Pair(44, -9), Pair(-9, 74), Pair(86, -192)
      },
      { // Piece 2
        Pair(-6, 75), Pair(64, -1), Pair(91, 35), Pair(-67, -74), Pair(-219, 154), Pair(-27, 77), Pair(58, 41), Pair(-158, 67),
        Pair(9, 30), Pair(18, 47), Pair(-105, 96), Pair(79, 45), Pair(54, 76), Pair(-54, 121), Pair(-67, 121), Pair(44, 160),
        Pair(1, 156), Pair(-117, 48), Pair(-34, 47), Pair(188, 27), Pair(9, 80), Pair(-9, 101), Pair(-10, 155), Pair(6, 32),
        Pair(-52, -1), Pair(-18, 84), Pair(101, -37), Pair(1, 7), Pair(100, 60), Pair(-30, 148), Pair(45, 5), Pair(-48, 11),
        Pair(-1, 157), Pair(83, 1), Pair(81, 28), Pair(28, 63), Pair(36, 115), Pair(47, 48), Pair(67, 14), Pair(-90, 103),
        Pair(6, -22), Pair(-20, 163), Pair(0, 0), Pair(24, 113), Pair(-4, 78), Pair(27, 23), Pair(29, 19), Pair(35, 39),
        Pair(-202, 91), Pair(-21, -58), Pair(57, 154), Pair(-33, -87), Pair(15, 29), Pair(-92, 46), Pair(41, -20), Pair(-79, -77),
        Pair(-96, 127), Pair(-51, 132), Pair(17, 45), Pair(-51, 147), Pair(-50, 72), Pair(6, 57), Pair(-38, 78), Pair(-86, 130)
      },
      { // Piece 3
        Pair(84, 16), Pair(-43, 124), Pair(10, 111), Pair(13, 119), Pair(-43, 120), Pair(-20, 92), Pair(-43, 85), Pair(12, 80),
        Pair(25, 59), Pair(45, 67), Pair(118, 62), Pair(19, 72), Pair(79, 56), Pair(117, 45), Pair(27, 65), Pair(-15, 64),
        Pair(91, 61), Pair(71, 78), Pair(85, 96), Pair(-146, 130), Pair(-33, 52), Pair(78, 15), Pair(-54, 63), Pair(37, 67),
        Pair(-25, 67), Pair(40, 35), Pair(37, 118), Pair(-11, 79), Pair(54, 91), Pair(-32, 75), Pair(27, 74), Pair(-14, 68),
        Pair(-78, 125), Pair(38, 108), Pair(2, 166), Pair(-80, 106), Pair(-29, 106), Pair(-77, 106), Pair(92, 26), Pair(29, 112),
        Pair(-71, 127), Pair(16, 79), Pair(0, 0), Pair(32, 137), Pair(20, 124), Pair(-80, 136), Pair(73, 27), Pair(29, 84),
        Pair(-44, 103), Pair(17, 98), Pair(7, 101), Pair(-53, 94), Pair(-46, 122), Pair(-9, 78), Pair(162, 13), Pair(-46, 77),
        Pair(-29, 99), Pair(-2, 64), Pair(-18, 92), Pair(9, 68), Pair(12, 81), Pair(17, 77), Pair(-25, 90), Pair(-19, 86)
      },
      { // Piece 4
        Pair(116, 5), Pair(97, 56), Pair(58, 54), Pair(64, 94), Pair(117, 5), Pair(47, 38), Pair(123, -68), Pair(-73, -12),
        Pair(-36, 38), Pair(12, 165), Pair(98, 4), Pair(64, 72), Pair(-36, 148), Pair(77, 79), Pair(39, -67), Pair(-1, 43),
        Pair(-25, 50), Pair(-70, 51), Pair(-6, 155), Pair(94, 45), Pair(45, 11), Pair(73, 128), Pair(43, 100), Pair(4, -47),
        Pair(83, -72), Pair(32, 36), Pair(-9, 129), Pair(29, 78), Pair(82, 109), Pair(57, 56), Pair(72, 128), Pair(0, 145),
        Pair(16, -83), Pair(68, -10), Pair(88, 36), Pair(71, 51), Pair(-35, 132), Pair(16, 78), Pair(31, 85), Pair(50, -30),
        Pair(-53, 41), Pair(86, -53), Pair(0, 0), Pair(36, 102), Pair(80, 0), Pair(49, 82), Pair(36, 79), Pair(81, 89),
        Pair(33, 18), Pair(50, -50), Pair(56, -41), Pair(-28, 54), Pair(-7, 31), Pair(-8, 34), Pair(14, 119), Pair(66, -34),
        Pair(-69, 129), Pair(-70, 136), Pair(-34, -50), Pair(17, -14), Pair(53, -125), Pair(-30, 75), Pair(-32, 98), Pair(-121, 17)
      },
      { // Piece 5
        Pair(-24, -44), Pair(-95, -183), Pair(1, -59), Pair(15, 29), Pair(-11, -27), Pair(-12, -79), Pair(0, -161), Pair(-54, -138),
        Pair(-19, -116), Pair(-23, -115), Pair(-27, -2), Pair(-25, 1), Pair(-5, 16), Pair(-14, -47), Pair(47, -71), Pair(-80, -59),
        Pair(65, 82), Pair(4, 7), Pair(-8, -16), Pair(117, -48), Pair(62, -22), Pair(33, -9), Pair(78, -19), Pair(27, -41),
        Pair(99, -38), Pair(90, -77), Pair(107, -47), Pair(175, -32), Pair(145, -73), Pair(-50, 18), Pair(45, -23), Pair(-67, -12),
        Pair(118, -61), Pair(92, 8), Pair(69, 37), Pair(-98, 53), Pair(-37, 24), Pair(129, -69), Pair(42, -23), Pair(133, -38),
        Pair(-61, 36), Pair(-125, 89), Pair(0, 0), Pair(33, 13), Pair(-110, 48), Pair(25, 12), Pair(56, -45), Pair(104, -70),
        Pair(4, 20), Pair(35, 94), Pair(-88, 61), Pair(-30, 99), Pair(-65, 63), Pair(-65, 21), Pair(17, -23), Pair(0, -59),
        Pair(-282, 64), Pair(-63, 52), Pair(-165, 108), Pair(-95, 115), Pair(-42, -7), Pair(-5, 23), Pair(-8, -38), Pair(-18, -65)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, 41), Pair(3, 7), Pair(-22, 11), Pair(-76, 51), Pair(-43, 24), Pair(17, -15), Pair(1, 12), Pair(-16, 12),
        Pair(-3, 17), Pair(-29, -4), Pair(-7, -7), Pair(0, 0), Pair(-31, 12), Pair(-35, 32), Pair(58, -5), Pair(-21, 9),
        Pair(-20, -2), Pair(-11, -17), Pair(16, -6), Pair(12, 5), Pair(11, -4), Pair(29, -19), Pair(-14, -2), Pair(-32, 4),
        Pair(6, -10), Pair(-11, -8), Pair(0, -16), Pair(8, 14), Pair(5, -4), Pair(16, -6), Pair(-20, 2), Pair(-7, -4),
        Pair(-13, 7), Pair(-7, 1), Pair(-13, 9), Pair(0, 0), Pair(20, -5), Pair(-1, 2), Pair(-32, 15), Pair(-13, 6),
        Pair(2, -4), Pair(-12, 17), Pair(-30, -11), Pair(-36, 40), Pair(-13, -37), Pair(-13, -7), Pair(-21, 2), Pair(-20, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-165, -13), Pair(-275, -43), Pair(-3, -111), Pair(15, 47), Pair(-67, 20), Pair(62, -57), Pair(3, -98), Pair(-227, -153),
        Pair(-21, 42), Pair(220, -107), Pair(-51, -37), Pair(25, 59), Pair(-45, -29), Pair(77, -29), Pair(-20, -102), Pair(4, 18),
        Pair(-34, -62), Pair(25, 29), Pair(35, 43), Pair(69, -14), Pair(-78, 76), Pair(90, -49), Pair(-19, 56), Pair(-46, -47),
        Pair(-58, 35), Pair(-22, 33), Pair(60, 24), Pair(54, 31), Pair(49, 9), Pair(26, 34), Pair(37, 30), Pair(63, -9),
        Pair(-15, 46), Pair(5, 78), Pair(7, 105), Pair(18, 58), Pair(55, 63), Pair(44, 3), Pair(141, 27), Pair(30, 23),
        Pair(-29, 28), Pair(-19, 124), Pair(-6, 63), Pair(0, 0), Pair(60, 65), Pair(6, 99), Pair(7, 105), Pair(57, -27),
        Pair(-103, 81), Pair(126, 53), Pair(18, -33), Pair(24, 131), Pair(-18, -68), Pair(117, -13), Pair(-48, 14), Pair(-24, 47),
        Pair(174, 13), Pair(4, 52), Pair(-89, 17), Pair(-17, 99), Pair(-19, 20), Pair(5, 105), Pair(19, 57), Pair(13, -60)
      },
      { // Piece 2
        Pair(-63, 64), Pair(-221, 143), Pair(-39, 88), Pair(-5, 70), Pair(11, 108), Pair(-50, 147), Pair(69, 47), Pair(29, 70),
        Pair(23, 97), Pair(-90, 150), Pair(-2, 56), Pair(-124, 45), Pair(-46, 112), Pair(109, 16), Pair(-11, 114), Pair(-75, 91),
        Pair(1, 84), Pair(-93, 120), Pair(-7, 117), Pair(-86, 77), Pair(-1, 53), Pair(36, 97), Pair(-44, 62), Pair(65, 149),
        Pair(-30, 140), Pair(36, 63), Pair(-65, 108), Pair(58, 72), Pair(53, 35), Pair(22, 104), Pair(-4, 185), Pair(-47, 126),
        Pair(22, 104), Pair(-84, 159), Pair(-14, 63), Pair(77, 98), Pair(64, 159), Pair(-7, 125), Pair(16, 60), Pair(-63, 48),
        Pair(17, 39), Pair(-62, 110), Pair(11, 138), Pair(0, 0), Pair(-23, 132), Pair(18, 67), Pair(2, 104), Pair(-66, 26),
        Pair(50, 130), Pair(7, 104), Pair(-127, 51), Pair(20, 175), Pair(-105, 8), Pair(12, 69), Pair(-5, 67), Pair(-77, 105),
        Pair(49, 87), Pair(-216, 159), Pair(-37, 90), Pair(-8, 78), Pair(-43, 135), Pair(-29, 42), Pair(38, 173), Pair(-10, 93)
      },
      { // Piece 3
        Pair(3, 46), Pair(57, 56), Pair(75, 30), Pair(117, 75), Pair(39, 64), Pair(52, 66), Pair(192, -19), Pair(60, 59),
        Pair(47, 38), Pair(-58, 112), Pair(12, 59), Pair(-68, 132), Pair(-28, 60), Pair(-4, 40), Pair(145, 29), Pair(40, 75),
        Pair(41, 15), Pair(-106, 111), Pair(-4, 20), Pair(-23, 105), Pair(74, 20), Pair(64, 47), Pair(44, 41), Pair(88, -22),
        Pair(8, 21), Pair(22, 85), Pair(41, 11), Pair(23, 142), Pair(-1, 112), Pair(23, 21), Pair(-32, 67), Pair(-45, 52),
        Pair(34, 73), Pair(23, 92), Pair(118, 21), Pair(60, 138), Pair(51, 63), Pair(37, 39), Pair(11, 24), Pair(31, 67),
        Pair(-48, 115), Pair(30, 81), Pair(54, 70), Pair(0, 0), Pair(66, 32), Pair(7, 42), Pair(-31, 67), Pair(59, 69),
        Pair(12, 55), Pair(-43, 119), Pair(-38, -66), Pair(34, 120), Pair(-12, -26), Pair(22, 78), Pair(-1, 64), Pair(-8, 134),
        Pair(-32, 81), Pair(-22, 94), Pair(-11, 45), Pair(-16, 92), Pair(-8, 57), Pair(-11, 69), Pair(7, 79), Pair(22, 50)
      },
      { // Piece 4
        Pair(108, -9), Pair(-11, 35), Pair(49, 16), Pair(110, 117), Pair(-11, 82), Pair(-15, 75), Pair(82, 101), Pair(29, 108),
        Pair(68, -12), Pair(-22, 35), Pair(139, 44), Pair(92, 108), Pair(30, 131), Pair(11, -22), Pair(49, -40), Pair(121, -48),
        Pair(114, -98), Pair(73, -2), Pair(24, 24), Pair(-7, 127), Pair(-47, 161), Pair(31, 129), Pair(49, 94), Pair(38, 6),
        Pair(4, 101), Pair(66, 104), Pair(82, 24), Pair(92, 6), Pair(44, 72), Pair(67, 31), Pair(41, 13), Pair(41, 63),
        Pair(4, 118), Pair(13, 128), Pair(101, 66), Pair(210, -73), Pair(98, -37), Pair(17, 73), Pair(45, 89), Pair(40, 46),
        Pair(55, -25), Pair(-11, 171), Pair(18, 39), Pair(0, 0), Pair(52, 114), Pair(70, 77), Pair(100, -30), Pair(9, 203),
        Pair(110, -68), Pair(64, 51), Pair(-24, -119), Pair(20, 47), Pair(-21, -16), Pair(76, 0), Pair(14, -19), Pair(-4, 2),
        Pair(65, 46), Pair(-27, 1), Pair(49, 41), Pair(46, -19), Pair(41, -69), Pair(68, -49), Pair(58, -16), Pair(14, -83)
      },
      { // Piece 5
        Pair(-5, -111), Pair(-13, -60), Pair(37, -3), Pair(22, -63), Pair(16, -4), Pair(-58, -163), Pair(6, -48), Pair(-39, 15),
        Pair(-3, 35), Pair(-51, -48), Pair(6, -33), Pair(4, -69), Pair(-86, -51), Pair(-74, -87), Pair(4, -18), Pair(83, -21),
        Pair(-2, -151), Pair(-120, -47), Pair(-31, -20), Pair(57, -22), Pair(109, 15), Pair(39, -5), Pair(-54, 0), Pair(-80, -38),
        Pair(17, 42), Pair(29, -22), Pair(223, -70), Pair(38, -53), Pair(0, 2), Pair(-51, -14), Pair(-85, 9), Pair(-185, -36),
        Pair(73, -72), Pair(-54, 77), Pair(13, 55), Pair(56, 84), Pair(-77, 77), Pair(-1, 11), Pair(107, -21), Pair(20, -36),
        Pair(85, -42), Pair(-136, 67), Pair(43, 34), Pair(0, 0), Pair(100, 0), Pair(11, 20), Pair(-21, 34), Pair(-115, 15),
        Pair(-34, -11), Pair(-85, 62), Pair(-49, -67), Pair(-98, 73), Pair(103, -41), Pair(-50, 36), Pair(11, 1), Pair(6, -40),
        Pair(-66, -13), Pair(-34, 15), Pair(-45, 80), Pair(-35, 76), Pair(16, 33), Pair(-49, 4), Pair(-2, -5), Pair(32, -40)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-22, 35), Pair(36, -3), Pair(14, 14), Pair(56, -66), Pair(-83, 5), Pair(-107, 22), Pair(-14, -2), Pair(44, 24),
        Pair(-54, 22), Pair(8, -7), Pair(-4, 1), Pair(31, -12), Pair(0, 0), Pair(15, 1), Pair(-13, 8), Pair(28, 12),
        Pair(-23, 16), Pair(-2, -11), Pair(7, 2), Pair(19, -16), Pair(25, -24), Pair(32, 0), Pair(14, -12), Pair(-27, 11),
        Pair(-6, -6), Pair(5, -11), Pair(0, -8), Pair(1, -3), Pair(15, -8), Pair(11, 3), Pair(-9, -5), Pair(4, -8),
        Pair(5, -4), Pair(-18, -3), Pair(3, -19), Pair(-8, -3), Pair(0, 0), Pair(15, -13), Pair(5, -2), Pair(-2, 0),
        Pair(-15, -7), Pair(-6, 4), Pair(3, 7), Pair(-11, 5), Pair(-4, 24), Pair(-48, 11), Pair(8, -13), Pair(-3, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-58, -13), Pair(-81, -67), Pair(113, -27), Pair(-10, 24), Pair(-207, 4), Pair(-24, -6), Pair(66, 3), Pair(184, -87),
        Pair(-48, -49), Pair(80, -100), Pair(161, -11), Pair(106, -6), Pair(29, 25), Pair(52, 37), Pair(-53, -13), Pair(14, 5),
        Pair(-105, 40), Pair(-12, 90), Pair(105, -2), Pair(-20, 27), Pair(-5, 59), Pair(35, 3), Pair(-20, 64), Pair(11, 91),
        Pair(25, 16), Pair(18, 49), Pair(32, 16), Pair(-10, 65), Pair(90, 42), Pair(114, 5), Pair(-52, 72), Pair(-98, 116),
        Pair(16, 17), Pair(-58, 94), Pair(64, 17), Pair(53, 89), Pair(7, 66), Pair(34, 91), Pair(-13, 47), Pair(2, 58),
        Pair(-19, -3), Pair(-58, 48), Pair(27, 84), Pair(-13, 77), Pair(0, 0), Pair(16, 62), Pair(31, 76), Pair(-29, 23),
        Pair(23, -10), Pair(-73, -14), Pair(6, 101), Pair(5, -5), Pair(38, 92), Pair(-98, 31), Pair(70, 59), Pair(18, 35),
        Pair(-222, 85), Pair(-14, 1), Pair(-58, 56), Pair(31, 4), Pair(61, 40), Pair(-79, 37), Pair(4, 47), Pair(-271, -63)
      },
      { // Piece 2
        Pair(1, 104), Pair(-49, 87), Pair(-93, 103), Pair(-66, -12), Pair(-173, 163), Pair(-50, 52), Pair(-132, 33), Pair(-110, 154),
        Pair(-31, -101), Pair(-38, 86), Pair(-77, -24), Pair(-51, 101), Pair(-103, 21), Pair(-99, 65), Pair(-41, 59), Pair(-52, 128),
        Pair(-182, 166), Pair(10, -2), Pair(-106, 106), Pair(13, 33), Pair(-164, 123), Pair(-108, 20), Pair(20, 88), Pair(-10, -86),
        Pair(31, -16), Pair(-2, 158), Pair(39, 34), Pair(-25, 115), Pair(3, 23), Pair(74, 88), Pair(11, -13), Pair(-82, 123),
        Pair(-42, 58), Pair(107, 5), Pair(-66, 150), Pair(-98, 102), Pair(0, 87), Pair(40, 2), Pair(16, 118), Pair(28, 11),
        Pair(10, 46), Pair(-45, 56), Pair(-1, 51), Pair(-39, 130), Pair(0, 0), Pair(-7, 136), Pair(-9, 98), Pair(-26, 42),
        Pair(-129, 48), Pair(0, 10), Pair(-145, 125), Pair(-76, -21), Pair(-23, 177), Pair(-263, -129), Pair(-18, 68), Pair(-74, 69),
        Pair(-136, 110), Pair(-88, 95), Pair(9, -66), Pair(-38, 143), Pair(66, 11), Pair(-81, 108), Pair(-37, 55), Pair(92, 127)
      },
      { // Piece 3
        Pair(-78, 48), Pair(-27, 49), Pair(-43, 63), Pair(-91, 107), Pair(118, 40), Pair(58, 66), Pair(-184, 119), Pair(-37, 41),
        Pair(-38, 27), Pair(25, 19), Pair(-8, -11), Pair(-121, 61), Pair(51, 64), Pair(91, 24), Pair(129, 0), Pair(45, 11),
        Pair(101, -56), Pair(57, 19), Pair(32, -2), Pair(-18, 37), Pair(81, 34), Pair(-40, 33), Pair(-16, 46), Pair(-20, 50),
        Pair(-60, 15), Pair(109, -9), Pair(39, 15), Pair(76, 13), Pair(32, 95), Pair(-1, 65), Pair(-42, 30), Pair(19, 14),
        Pair(4, 55), Pair(-82, 91), Pair(29, 40), Pair(-37, 59), Pair(-52, 128), Pair(68, 9), Pair(-32, 83), Pair(49, -2),
        Pair(-109, -2), Pair(54, 3), Pair(-18, 60), Pair(-24, 74), Pair(0, 0), Pair(-9, 158), Pair(-61, 94), Pair(-18, -25),
        Pair(-34, 44), Pair(39, -9), Pair(10, 20), Pair(64, 29), Pair(5, 68), Pair(-23, 1), Pair(-50, 141), Pair(22, -7),
        Pair(-30, 37), Pair(19, -10), Pair(-29, 40), Pair(-32, 57), Pair(-48, 70), Pair(-24, 55), Pair(-1, 38), Pair(-17, 28)
      },
      { // Piece 4
        Pair(-3, 9), Pair(-26, 28), Pair(-102, 29), Pair(135, 13), Pair(-102, 151), Pair(-60, 94), Pair(92, 89), Pair(-35, 19),
        Pair(-3, -55), Pair(50, -8), Pair(63, -38), Pair(21, 118), Pair(73, 22), Pair(50, -34), Pair(39, -53), Pair(88, 117),
        Pair(43, -56), Pair(3, 97), Pair(14, -24), Pair(48, 69), Pair(-137, 39), Pair(72, 140), Pair(56, -23), Pair(78, -34),
        Pair(43, 40), Pair(39, 47), Pair(7, -60), Pair(3, 113), Pair(-16, 104), Pair(85, 8), Pair(22, 122), Pair(9, 32),
        Pair(-24, 137), Pair(-55, 144), Pair(9, 44), Pair(81, 19), Pair(41, 86), Pair(-43, 67), Pair(40, -30), Pair(53, -27),
        Pair(78, -11), Pair(-37, 86), Pair(30, 22), Pair(22, 91), Pair(0, 0), Pair(57, 17), Pair(22, 49), Pair(-32, -19),
        Pair(-38, 50), Pair(48, -130), Pair(-53, 114), Pair(-16, -109), Pair(-16, 52), Pair(-60, -73), Pair(-31, 16), Pair(5, 94),
        Pair(-17, 13), Pair(-104, 148), Pair(52, -75), Pair(-31, 67), Pair(-7, -59), Pair(-36, 36), Pair(-121, 1), Pair(23, 20)
      },
      { // Piece 5
        Pair(11, 61), Pair(18, -128), Pair(-31, -136), Pair(-73, -30), Pair(-79, -191), Pair(-36, 25), Pair(4, -96), Pair(-6, -142),
        Pair(69, -59), Pair(30, -46), Pair(0, 45), Pair(-26, -135), Pair(-32, -105), Pair(40, 18), Pair(-22, -74), Pair(-36, -74),
        Pair(71, 56), Pair(32, -50), Pair(71, -67), Pair(157, -98), Pair(183, -35), Pair(152, -43), Pair(41, -12), Pair(107, -68),
        Pair(-90, -23), Pair(79, -32), Pair(-66, -71), Pair(15, 4), Pair(-119, -7), Pair(295, -86), Pair(9, -53), Pair(29, 6),
        Pair(58, -34), Pair(137, -29), Pair(-38, 38), Pair(64, 5), Pair(-99, 94), Pair(209, 17), Pair(-148, 21), Pair(13, -60),
        Pair(94, -69), Pair(48, -10), Pair(-28, -17), Pair(-11, 25), Pair(0, 0), Pair(21, 23), Pair(-88, 22), Pair(-7, -10),
        Pair(24, -22), Pair(-57, -40), Pair(-35, 14), Pair(-51, 53), Pair(-11, 22), Pair(15, 55), Pair(-37, 33), Pair(-19, -23),
        Pair(-139, 19), Pair(-61, -53), Pair(-31, -14), Pair(-40, 40), Pair(-32, 57), Pair(-23, 42), Pair(-63, -4), Pair(-45, -3)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 7), Pair(-84, 6), Pair(-93, 29), Pair(-4, -20), Pair(112, 12), Pair(82, 31), Pair(-48, -18), Pair(-1, 33),
        Pair(-20, 2), Pair(-50, 4), Pair(2, -17), Pair(35, -32), Pair(-15, -1), Pair(0, 0), Pair(6, -9), Pair(-41, 13),
        Pair(-6, -12), Pair(0, -10), Pair(17, -22), Pair(27, -28), Pair(33, -5), Pair(6, -33), Pair(-29, 11), Pair(-2, -1),
        Pair(-10, -12), Pair(-14, -12), Pair(-2, -15), Pair(11, -19), Pair(8, -18), Pair(58, -24), Pair(-8, -1), Pair(18, -14),
        Pair(-23, -2), Pair(6, -7), Pair(-18, 0), Pair(6, -25), Pair(35, -34), Pair(0, 0), Pair(-1, -11), Pair(4, -12),
        Pair(-14, -5), Pair(-12, 0), Pair(3, -20), Pair(-6, -14), Pair(11, -18), Pair(11, -2), Pair(-32, -4), Pair(13, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-39, -161), Pair(-49, -46), Pair(31, -34), Pair(158, -123), Pair(-69, 59), Pair(-62, -110), Pair(-71, 3), Pair(-48, -59),
        Pair(-119, 9), Pair(148, -28), Pair(-4, -61), Pair(38, 45), Pair(-84, -35), Pair(132, -48), Pair(81, 87), Pair(-31, 67),
        Pair(79, -5), Pair(92, -31), Pair(-86, 38), Pair(41, 11), Pair(7, 18), Pair(41, -20), Pair(255, -82), Pair(-19, -47),
        Pair(20, -65), Pair(-30, -6), Pair(-27, 10), Pair(36, -29), Pair(30, 45), Pair(58, -2), Pair(40, -57), Pair(49, -60),
        Pair(-71, 33), Pair(35, 44), Pair(45, -17), Pair(47, -74), Pair(25, 61), Pair(44, -1), Pair(4, 10), Pair(17, 26),
        Pair(-84, -55), Pair(-151, 75), Pair(-58, 59), Pair(7, 61), Pair(57, 13), Pair(0, 0), Pair(-35, 9), Pair(-43, 36),
        Pair(155, -213), Pair(33, 42), Pair(-10, -8), Pair(55, 15), Pair(-44, -29), Pair(-10, 92), Pair(-132, 3), Pair(60, -172),
        Pair(82, -133), Pair(-24, 32), Pair(-52, -13), Pair(-57, 73), Pair(-69, -49), Pair(193, -27), Pair(-11, -83), Pair(-133, 14)
      },
      { // Piece 2
        Pair(-185, 131), Pair(-14, 57), Pair(-104, -42), Pair(-107, 81), Pair(-60, -2), Pair(-118, 79), Pair(-47, 13), Pair(-102, 21),
        Pair(40, 59), Pair(43, 42), Pair(-66, 89), Pair(-35, -34), Pair(-172, 101), Pair(31, 11), Pair(-22, 21), Pair(-34, 14),
        Pair(154, -107), Pair(-48, 78), Pair(-84, 68), Pair(58, 49), Pair(52, 14), Pair(-115, 71), Pair(76, -43), Pair(46, -22),
        Pair(75, 7), Pair(12, -15), Pair(17, 61), Pair(-70, 86), Pair(5, 4), Pair(-21, 45), Pair(102, 20), Pair(29, -14),
        Pair(45, -71), Pair(-132, 40), Pair(-38, -6), Pair(30, 73), Pair(19, -27), Pair(15, 61), Pair(24, 24), Pair(-253, 127),
        Pair(28, -20), Pair(11, 15), Pair(-28, 14), Pair(47, 3), Pair(29, 52), Pair(0, 0), Pair(-10, 129), Pair(-32, -8),
        Pair(-357, 8), Pair(7, -35), Pair(-15, -46), Pair(-70, 11), Pair(37, -115), Pair(37, 111), Pair(-130, -108), Pair(-329, 18),
        Pair(-49, -25), Pair(-16, -110), Pair(-29, 15), Pair(-116, -10), Pair(-203, 154), Pair(-26, -20), Pair(-164, 130), Pair(-127, -53)
      },
      { // Piece 3
        Pair(-43, 8), Pair(-110, 45), Pair(-68, 50), Pair(-30, 28), Pair(-157, 95), Pair(29, 60), Pair(7, 85), Pair(-49, 95),
        Pair(94, -26), Pair(25, -30), Pair(37, -22), Pair(-53, -9), Pair(10, 24), Pair(78, 28), Pair(47, 5), Pair(-49, -24),
        Pair(28, -26), Pair(47, -23), Pair(6, 4), Pair(41, 0), Pair(-30, 1), Pair(56, 27), Pair(57, 14), Pair(-63, 17),
        Pair(-62, 32), Pair(100, -33), Pair(-110, 26), Pair(46, -23), Pair(80, 1), Pair(88, -6), Pair(17, 20), Pair(10, 0),
        Pair(35, 4), Pair(-51, 34), Pair(-21, 40), Pair(-67, 30), Pair(-4, 62), Pair(-12, 74), Pair(-54, 54), Pair(41, 14),
        Pair(-174, 93), Pair(8, -35), Pair(14, -36), Pair(-59, -12), Pair(-36, -2), Pair(0, 0), Pair(58, 40), Pair(91, 36),
        Pair(-136, 61), Pair(-90, 38), Pair(-117, 22), Pair(-100, 91), Pair(-50, -118), Pair(-24, 62), Pair(-74, -82), Pair(-9, -9),
        Pair(-37, 11), Pair(-44, -2), Pair(-34, -24), Pair(-18, -7), Pair(-4, 30), Pair(-43, 36), Pair(10, -2), Pair(-40, 15)
      },
      { // Piece 4
        Pair(-72, -4), Pair(-78, -82), Pair(-3, -40), Pair(43, -11), Pair(-127, 54), Pair(-56, -37), Pair(137, 35), Pair(117, 1),
        Pair(28, -16), Pair(93, -7), Pair(151, 4), Pair(-23, 77), Pair(12, 126), Pair(120, -68), Pair(95, 152), Pair(120, -44),
        Pair(68, -114), Pair(-36, 124), Pair(23, 67), Pair(24, -2), Pair(-43, 91), Pair(45, -52), Pair(57, -122), Pair(35, -57),
        Pair(-45, -3), Pair(-7, -117), Pair(13, 23), Pair(-66, 40), Pair(11, 53), Pair(76, 79), Pair(6, 69), Pair(65, 0),
        Pair(37, -65), Pair(2, -21), Pair(-73, 156), Pair(2, 148), Pair(87, 49), Pair(104, -41), Pair(111, -67), Pair(39, -32),
        Pair(-46, 73), Pair(-19, 7), Pair(-22, -14), Pair(-22, 35), Pair(-58, 79), Pair(0, 0), Pair(90, -85), Pair(87, -25),
        Pair(-55, -5), Pair(-41, -29), Pair(5, 41), Pair(-2, -47), Pair(-85, 18), Pair(-36, -23), Pair(-97, 32), Pair(36, -139),
        Pair(18, -10), Pair(-125, 75), Pair(-55, -57), Pair(-43, -98), Pair(9, 4), Pair(-77, -37), Pair(-24, 3), Pair(-38, 39)
      },
      { // Piece 5
        Pair(41, -27), Pair(-6, 21), Pair(-31, -47), Pair(-120, -146), Pair(-101, -179), Pair(-39, -138), Pair(1, -98), Pair(-22, -85),
        Pair(15, -35), Pair(-5, -46), Pair(103, -96), Pair(17, -92), Pair(-41, -30), Pair(31, 4), Pair(9, -77), Pair(62, 73),
        Pair(225, -54), Pair(18, -29), Pair(-20, -4), Pair(-13, -52), Pair(-56, -63), Pair(-15, -63), Pair(37, 6), Pair(-2, -126),
        Pair(-18, 39), Pair(196, -69), Pair(-49, -34), Pair(86, -68), Pair(113, -44), Pair(54, 17), Pair(-69, -29), Pair(122, -139),
        Pair(-11, -52), Pair(-26, -10), Pair(123, -26), Pair(30, -9), Pair(108, 1), Pair(-30, 43), Pair(113, 30), Pair(20, -18),
        Pair(21, -34), Pair(107, -60), Pair(125, -52), Pair(-105, 16), Pair(57, -1), Pair(0, 0), Pair(21, 46), Pair(40, 38),
        Pair(57, -51), Pair(83, -55), Pair(-5, 1), Pair(3, 13), Pair(45, 59), Pair(6, 25), Pair(-73, 54), Pair(6, 40),
        Pair(13, -184), Pair(-63, -4), Pair(-50, 36), Pair(-78, 28), Pair(-7, 15), Pair(-123, 94), Pair(-57, 60), Pair(-107, 47)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 21), Pair(-8, -8), Pair(-28, 28), Pair(79, -60), Pair(6, 28), Pair(-16, 22), Pair(2, 47), Pair(-40, 12),
        Pair(-31, 8), Pair(79, -39), Pair(28, -11), Pair(-59, 5), Pair(13, -6), Pair(-7, 9), Pair(0, 0), Pair(-34, 7),
        Pair(9, -8), Pair(-11, -13), Pair(17, -15), Pair(-9, -13), Pair(-1, -27), Pair(15, -19), Pair(-26, 4), Pair(5, -16),
        Pair(-11, -8), Pair(-2, -8), Pair(-7, -18), Pair(8, -24), Pair(8, -20), Pair(11, -16), Pair(-11, 3), Pair(26, -15),
        Pair(7, -18), Pair(-7, -11), Pair(-9, -24), Pair(3, -26), Pair(7, -13), Pair(8, -11), Pair(0, 0), Pair(32, -11),
        Pair(5, -16), Pair(-7, -14), Pair(-3, -27), Pair(11, -16), Pair(2, 0), Pair(-36, -19), Pair(-15, 4), Pair(-8, -14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-164, -105), Pair(98, -66), Pair(-128, 10), Pair(-106, -34), Pair(-97, -58), Pair(118, -85), Pair(-31, -129), Pair(-144, -316),
        Pair(-15, -69), Pair(-20, -11), Pair(28, -25), Pair(83, -8), Pair(59, -25), Pair(-65, 49), Pair(-83, 34), Pair(228, -39),
        Pair(-150, -23), Pair(31, -84), Pair(-33, -1), Pair(35, -17), Pair(10, -10), Pair(-2, -7), Pair(-75, 14), Pair(-38, -54),
        Pair(93, -114), Pair(33, -64), Pair(28, -85), Pair(6, 43), Pair(23, -12), Pair(63, 1), Pair(-4, 31), Pair(79, 0),
        Pair(22, -98), Pair(-26, -27), Pair(-17, -32), Pair(-28, 37), Pair(55, 1), Pair(24, 48), Pair(14, -41), Pair(-10, 78),
        Pair(3, -95), Pair(0, -46), Pair(-5, 36), Pair(-26, 2), Pair(4, 22), Pair(40, -41), Pair(0, 0), Pair(34, 11),
        Pair(-85, -121), Pair(23, -82), Pair(-8, 33), Pair(21, -18), Pair(13, -7), Pair(-68, -26), Pair(132, 31), Pair(23, -10),
        Pair(-69, -117), Pair(-13, -115), Pair(-150, -31), Pair(-59, 34), Pair(-11, 39), Pair(32, -17), Pair(20, 22), Pair(-224, 220)
      },
      { // Piece 2
        Pair(16, 129), Pair(-130, 108), Pair(-101, 30), Pair(-188, 10), Pair(-1, 26), Pair(88, -18), Pair(-100, -71), Pair(24, -15),
        Pair(-144, 54), Pair(-79, 60), Pair(-96, -8), Pair(-185, 49), Pair(12, 25), Pair(51, 33), Pair(-30, -81), Pair(88, -13),
        Pair(70, -2), Pair(-100, 56), Pair(-53, 76), Pair(-71, 28), Pair(132, -26), Pair(-65, 52), Pair(23, -59), Pair(61, -78),
        Pair(83, -41), Pair(12, -19), Pair(-22, 52), Pair(38, 74), Pair(-67, 53), Pair(88, 30), Pair(-35, 11), Pair(-26, 7),
        Pair(-46, -8), Pair(-73, 39), Pair(26, -32), Pair(-34, 59), Pair(13, 55), Pair(67, 22), Pair(-12, -35), Pair(-63, -2),
        Pair(-7, 32), Pair(-21, -63), Pair(-49, 27), Pair(53, -27), Pair(5, 25), Pair(-1, 48), Pair(0, 0), Pair(80, 93),
        Pair(-56, -21), Pair(-85, 78), Pair(9, -35), Pair(-36, 48), Pair(-9, 6), Pair(-150, -52), Pair(-2, 120), Pair(-31, -38),
        Pair(-99, 92), Pair(-20, 35), Pair(-20, -16), Pair(81, -55), Pair(-71, 50), Pair(-47, 41), Pair(5, -37), Pair(-112, 111)
      },
      { // Piece 3
        Pair(-2, 10), Pair(-78, 39), Pair(150, -22), Pair(-206, 75), Pair(136, 10), Pair(-27, 61), Pair(96, 30), Pair(18, 36),
        Pair(65, -66), Pair(53, -18), Pair(-15, -8), Pair(90, -57), Pair(40, -42), Pair(175, -51), Pair(109, 6), Pair(53, -6),
        Pair(28, -45), Pair(-36, 25), Pair(-10, -5), Pair(88, -37), Pair(-21, -2), Pair(43, -3), Pair(121, -26), Pair(-10, -36),
        Pair(45, -45), Pair(39, -6), Pair(-53, 8), Pair(-53, 24), Pair(93, -31), Pair(-43, 16), Pair(31, 79), Pair(21, -43),
        Pair(-21, -11), Pair(-35, 4), Pair(-79, 33), Pair(38, 18), Pair(4, 54), Pair(15, -6), Pair(-66, 120), Pair(60, -32),
        Pair(41, -51), Pair(126, -30), Pair(-82, -22), Pair(17, -12), Pair(130, -12), Pair(55, 26), Pair(0, 0), Pair(-91, -5),
        Pair(-70, -19), Pair(-20, -2), Pair(70, -53), Pair(29, -72), Pair(3, 13), Pair(23, -169), Pair(5, -6), Pair(-3, -88),
        Pair(-23, 0), Pair(-51, -19), Pair(-5, -37), Pair(-20, 28), Pair(33, -7), Pair(26, -16), Pair(42, -6), Pair(8, -50)
      },
      { // Piece 4
        Pair(-66, 33), Pair(-17, 48), Pair(90, 75), Pair(86, -63), Pair(31, -15), Pair(-104, 29), Pair(-14, 7), Pair(118, 35),
        Pair(111, -18), Pair(46, -30), Pair(111, 45), Pair(-13, 22), Pair(-165, 117), Pair(-62, 61), Pair(152, -51), Pair(125, -129),
        Pair(-6, -5), Pair(207, -190), Pair(20, 32), Pair(-10, 3), Pair(-46, 2), Pair(48, 84), Pair(-59, 48), Pair(50, -49),
        Pair(74, -6), Pair(-9, -134), Pair(-62, -2), Pair(-45, 55), Pair(52, 1), Pair(62, -80), Pair(-94, 135), Pair(12, 0),
        Pair(-82, 84), Pair(-52, 111), Pair(18, -101), Pair(-16, 21), Pair(-27, 15), Pair(-19, 42), Pair(-45, 176), Pair(71, -74),
        Pair(-46, 59), Pair(-58, 138), Pair(-14, 41), Pair(19, -117), Pair(-10, 10), Pair(34, -32), Pair(0, 0), Pair(-63, -39),
        Pair(20, -153), Pair(-38, -49), Pair(-49, -56), Pair(-44, -5), Pair(-1, -41), Pair(-70, 69), Pair(-81, -26), Pair(-142, -34),
        Pair(-70, -10), Pair(12, -79), Pair(-35, -99), Pair(-37, 19), Pair(10, 65), Pair(-52, -61), Pair(38, -249), Pair(-87, -76)
      },
      { // Piece 5
        Pair(-39, -165), Pair(100, -97), Pair(67, -5), Pair(49, 38), Pair(21, -16), Pair(14, -5), Pair(1, 13), Pair(38, 98),
        Pair(10, -33), Pair(44, -112), Pair(-13, -85), Pair(-16, 46), Pair(-23, -62), Pair(50, 5), Pair(90, -83), Pair(4, 0),
        Pair(167, -91), Pair(80, -53), Pair(80, -85), Pair(149, -89), Pair(38, 19), Pair(105, -57), Pair(153, -52), Pair(-39, -84),
        Pair(30, -71), Pair(176, -35), Pair(-35, 0), Pair(-30, 7), Pair(85, -45), Pair(219, -69), Pair(72, -31), Pair(67, -60),
        Pair(94, -75), Pair(56, -13), Pair(-105, 4), Pair(23, 12), Pair(48, -10), Pair(-8, 88), Pair(8, -18), Pair(26, -3),
        Pair(-11, -62), Pair(49, -60), Pair(-6, -30), Pair(-111, 41), Pair(-35, 29), Pair(-3, 38), Pair(0, 0), Pair(-50, 55),
        Pair(-114, 23), Pair(-43, -27), Pair(-6, -38), Pair(-81, 38), Pair(-90, 41), Pair(-8, 91), Pair(4, 46), Pair(-56, 130),
        Pair(4, -141), Pair(-57, -3), Pair(-69, 18), Pair(-104, -12), Pair(-102, 33), Pair(-47, 51), Pair(-13, 42), Pair(-24, 1)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(35, -16), Pair(-27, 18), Pair(8, 5), Pair(29, -16), Pair(10, -22), Pair(69, -27), Pair(40, 11), Pair(-100, 18),
        Pair(10, -18), Pair(-8, -13), Pair(-25, 2), Pair(22, -8), Pair(-28, -13), Pair(41, -16), Pair(34, -7), Pair(0, 0),
        Pair(-1, -10), Pair(9, -13), Pair(1, -8), Pair(2, -18), Pair(10, -7), Pair(-10, 5), Pair(-25, 22), Pair(9, 4),
        Pair(10, -20), Pair(8, -12), Pair(-8, -14), Pair(4, -7), Pair(-10, -9), Pair(10, -7), Pair(9, -4), Pair(-25, -3),
        Pair(8, -24), Pair(3, -19), Pair(-7, -10), Pair(11, -6), Pair(-1, -11), Pair(14, -16), Pair(-7, -15), Pair(0, 0),
        Pair(1, -24), Pair(4, -12), Pair(-9, -22), Pair(-4, -10), Pair(-24, -4), Pair(1, -11), Pair(-26, -14), Pair(-24, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-32, 34), Pair(77, -55), Pair(51, -83), Pair(68, -58), Pair(-39, -50), Pair(10, -40), Pair(16, -64), Pair(55, -123),
        Pair(163, -25), Pair(-69, -35), Pair(46, -93), Pair(55, -95), Pair(67, -89), Pair(83, -118), Pair(234, -142), Pair(12, -154),
        Pair(85, -73), Pair(35, -80), Pair(97, -78), Pair(169, -105), Pair(120, -100), Pair(106, -78), Pair(67, -80), Pair(-139, 19),
        Pair(25, -29), Pair(97, -36), Pair(43, -43), Pair(27, -23), Pair(52, -45), Pair(54, -56), Pair(60, -48), Pair(128, -97),
        Pair(-8, -90), Pair(68, -82), Pair(52, -66), Pair(48, -49), Pair(53, -35), Pair(66, -66), Pair(50, -16), Pair(40, 31),
        Pair(16, 33), Pair(15, -37), Pair(27, -23), Pair(11, -51), Pair(43, -47), Pair(21, 2), Pair(8, -48), Pair(0, 0),
        Pair(-2, -106), Pair(-24, -52), Pair(-5, -16), Pair(37, -8), Pair(6, -8), Pair(19, 5), Pair(-64, -41), Pair(-31, 9),
        Pair(56, -167), Pair(13, -14), Pair(8, -44), Pair(30, -62), Pair(-35, -73), Pair(-176, 46), Pair(7, -18), Pair(52, -55)
      },
      { // Piece 2
        Pair(-41, 47), Pair(-105, 143), Pair(-170, 84), Pair(-125, 52), Pair(-193, 43), Pair(110, -17), Pair(-15, 27), Pair(78, -68),
        Pair(-24, -3), Pair(-29, 32), Pair(9, 82), Pair(36, 43), Pair(76, 15), Pair(137, -72), Pair(4, -32), Pair(28, -10),
        Pair(47, -43), Pair(-3, -14), Pair(-17, 34), Pair(-48, 103), Pair(120, 16), Pair(26, 26), Pair(-55, 95), Pair(34, -54),
        Pair(5, -53), Pair(46, -48), Pair(21, -18), Pair(-31, 37), Pair(34, 53), Pair(5, 70), Pair(28, -36), Pair(-50, 3),
        Pair(29, -10), Pair(14, -13), Pair(72, -44), Pair(9, -10), Pair(29, 9), Pair(61, 33), Pair(10, 65), Pair(-86, -25),
        Pair(37, -78), Pair(37, 5), Pair(25, -15), Pair(19, 18), Pair(20, -37), Pair(21, 59), Pair(33, 73), Pair(0, 0),
        Pair(-54, 71), Pair(44, -73), Pair(5, 38), Pair(38, -29), Pair(9, 27), Pair(-45, -4), Pair(-27, -63), Pair(2, 167),
        Pair(8, -121), Pair(84, 45), Pair(8, -15), Pair(-48, 55), Pair(144, -74), Pair(37, -22), Pair(-136, 25), Pair(34, 44)
      },
      { // Piece 3
        Pair(-73, 42), Pair(-58, 41), Pair(16, -7), Pair(-32, -1), Pair(17, -19), Pair(-28, 21), Pair(220, -9), Pair(94, 12),
        Pair(0, -5), Pair(-57, 29), Pair(57, -33), Pair(107, -69), Pair(100, -20), Pair(78, -56), Pair(-8, 40), Pair(222, -15),
        Pair(10, -14), Pair(-46, -7), Pair(18, -53), Pair(98, -86), Pair(-33, -16), Pair(111, -20), Pair(38, 4), Pair(114, 4),
        Pair(17, 1), Pair(23, -33), Pair(66, -39), Pair(67, -27), Pair(85, -86), Pair(26, -27), Pair(18, -14), Pair(176, 7),
        Pair(24, -15), Pair(26, -15), Pair(-14, 1), Pair(50, 2), Pair(20, -21), Pair(2, -2), Pair(65, -24), Pair(87, 30),
        Pair(32, -30), Pair(8, -15), Pair(-76, 27), Pair(-42, 34), Pair(86, -35), Pair(64, 25), Pair(41, 85), Pair(0, 0),
        Pair(5, 16), Pair(48, -2), Pair(142, -39), Pair(-2, 9), Pair(91, -76), Pair(42, -2), Pair(-87, -10), Pair(31, -3),
        Pair(45, -4), Pair(42, -24), Pair(67, -14), Pair(46, 0), Pair(75, -48), Pair(71, -43), Pair(55, -18), Pair(-18, -2)
      },
      { // Piece 4
        Pair(49, 27), Pair(-57, 20), Pair(-31, 78), Pair(20, 47), Pair(24, 71), Pair(43, -65), Pair(48, 118), Pair(123, 21),
        Pair(38, -16), Pair(66, 6), Pair(5, -11), Pair(-28, 39), Pair(82, -17), Pair(41, -21), Pair(63, -36), Pair(15, 84),
        Pair(46, 25), Pair(-59, 139), Pair(-30, 38), Pair(64, 2), Pair(-127, 99), Pair(-32, 132), Pair(-72, 147), Pair(108, -23),
        Pair(-53, -30), Pair(-63, -29), Pair(-43, 56), Pair(100, -106), Pair(-13, 103), Pair(-34, 149), Pair(-59, 123), Pair(36, 109),
        Pair(26, -82), Pair(-103, 210), Pair(4, 23), Pair(65, -96), Pair(-8, 80), Pair(13, 31), Pair(24, 74), Pair(98, 27),
        Pair(-5, -113), Pair(-69, 105), Pair(-33, 128), Pair(-43, 89), Pair(-15, 85), Pair(-34, 93), Pair(-22, 107), Pair(0, 0),
        Pair(-18, -1), Pair(-46, 40), Pair(-4, -62), Pair(-7, 71), Pair(-34, 135), Pair(-22, 27), Pair(-59, -2), Pair(-165, 132),
        Pair(-11, 120), Pair(-107, -33), Pair(-40, 20), Pair(8, -117), Pair(-36, -87), Pair(36, -27), Pair(-132, 173), Pair(-98, 81)
      },
      { // Piece 5
        Pair(-6, 58), Pair(-44, -63), Pair(85, -52), Pair(62, -24), Pair(19, -66), Pair(61, -187), Pair(-12, -30), Pair(-35, -162),
        Pair(-37, 17), Pair(86, -54), Pair(174, -103), Pair(127, -77), Pair(58, -59), Pair(31, -142), Pair(36, -98), Pair(79, -47),
        Pair(-17, -41), Pair(145, -46), Pair(-14, -38), Pair(130, -38), Pair(129, -42), Pair(134, -73), Pair(175, -113), Pair(8, -10),
        Pair(41, -32), Pair(64, -79), Pair(86, -41), Pair(122, -55), Pair(273, -49), Pair(48, -8), Pair(124, -33), Pair(85, -120),
        Pair(142, -60), Pair(88, -40), Pair(19, -36), Pair(200, -69), Pair(-64, 12), Pair(31, 15), Pair(186, 22), Pair(156, -43),
        Pair(-157, 28), Pair(52, -42), Pair(19, -23), Pair(-63, -14), Pair(-65, 50), Pair(82, 7), Pair(-19, 43), Pair(0, 0),
        Pair(31, -66), Pair(-20, -16), Pair(-115, -21), Pair(-100, 6), Pair(-25, 22), Pair(-85, 76), Pair(23, 52), Pair(46, 73),
        Pair(-190, 7), Pair(12, -51), Pair(2, -64), Pair(-16, -64), Pair(-75, 29), Pair(-148, 67), Pair(-45, 59), Pair(-34, 67)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(67, 39), Pair(21, 13), Pair(13, -3), Pair(-28, 26), Pair(61, 7), Pair(8, 13), Pair(45, 13), Pair(7, 35),
        Pair(1, 4), Pair(-16, 16), Pair(9, 1), Pair(22, 3), Pair(24, -17), Pair(5, 10), Pair(-10, 8), Pair(0, 11),
        Pair(0, 0), Pair(-19, 5), Pair(6, 0), Pair(2, -7), Pair(9, -2), Pair(-6, 4), Pair(-6, 6), Pair(5, 6),
        Pair(0, 0), Pair(-12, -4), Pair(6, -3), Pair(0, -11), Pair(-2, -2), Pair(-7, 5), Pair(-5, 5), Pair(1, -2),
        Pair(11, 11), Pair(-22, -7), Pair(1, -9), Pair(-5, -6), Pair(-7, -4), Pair(-2, -11), Pair(-6, -6), Pair(0, 1),
        Pair(10, 2), Pair(-19, -3), Pair(3, -6), Pair(-2, -11), Pair(-5, -9), Pair(-10, -8), Pair(-9, -13), Pair(-2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-36, 34), Pair(21, 38), Pair(202, -70), Pair(89, -24), Pair(64, -31), Pair(105, -36), Pair(-20, -78), Pair(-44, -20),
        Pair(-97, 46), Pair(47, 49), Pair(21, -9), Pair(65, 17), Pair(19, 4), Pair(58, -14), Pair(153, -70), Pair(90, -15),
        Pair(-9, 8), Pair(45, 31), Pair(53, 33), Pair(7, 45), Pair(72, -3), Pair(37, -8), Pair(57, -43), Pair(95, -73),
        Pair(61, 7), Pair(19, 42), Pair(38, 9), Pair(28, 30), Pair(14, 14), Pair(30, 7), Pair(19, 2), Pair(44, -29),
        Pair(0, 0), Pair(39, 5), Pair(3, 55), Pair(24, -9), Pair(39, 10), Pair(20, -2), Pair(38, 6), Pair(24, -8),
        Pair(14, 86), Pair(-54, 29), Pair(14, 21), Pair(0, 21), Pair(3, 49), Pair(12, 8), Pair(12, 16), Pair(2, 40),
        Pair(3, 26), Pair(-50, 54), Pair(1, 60), Pair(-4, 23), Pair(-1, 19), Pair(-2, 9), Pair(47, -21), Pair(0, -40),
        Pair(-46, 72), Pair(7, 16), Pair(32, -44), Pair(22, 4), Pair(89, -8), Pair(6, 45), Pair(-14, -1), Pair(28, 0)
      },
      { // Piece 2
        Pair(64, 6), Pair(-189, 115), Pair(-277, 147), Pair(-95, 73), Pair(-225, 164), Pair(12, 116), Pair(32, 36), Pair(93, 72),
        Pair(-56, 80), Pair(-82, 76), Pair(37, 56), Pair(-129, 126), Pair(-39, 118), Pair(-30, 112), Pair(-60, 121), Pair(-2, 56),
        Pair(-1, 42), Pair(-23, 52), Pair(-10, 75), Pair(42, 82), Pair(15, 105), Pair(3, 82), Pair(59, 75), Pair(-10, 63),
        Pair(72, 3), Pair(3, 98), Pair(64, 64), Pair(-26, 83), Pair(35, 64), Pair(6, 73), Pair(18, 47), Pair(-65, 78),
        Pair(0, 0), Pair(35, 72), Pair(0, 85), Pair(17, 44), Pair(37, 36), Pair(30, 33), Pair(-35, 54), Pair(-5, 18),
        Pair(28, 158), Pair(-62, 53), Pair(34, 43), Pair(6, 59), Pair(2, 43), Pair(11, 64), Pair(-14, 61), Pair(-14, 87),
        Pair(7, 86), Pair(0, 97), Pair(10, 67), Pair(9, 51), Pair(-8, 57), Pair(-1, 42), Pair(5, 47), Pair(86, 15),
        Pair(51, 37), Pair(17, 85), Pair(1, 59), Pair(-14, 52), Pair(17, 42), Pair(10, 51), Pair(18, 30), Pair(-22, 15)
      },
      { // Piece 3
        Pair(41, 113), Pair(66, 105), Pair(-58, 147), Pair(102, 53), Pair(-30, 97), Pair(130, 70), Pair(63, 77), Pair(-2, 119),
        Pair(103, 118), Pair(-19, 134), Pair(3, 110), Pair(35, 129), Pair(79, 95), Pair(76, 75), Pair(79, 58), Pair(31, 84),
        Pair(48, 134), Pair(6, 108), Pair(4, 128), Pair(-34, 142), Pair(-17, 109), Pair(40, 96), Pair(-15, 114), Pair(10, 81),
        Pair(61, 141), Pair(65, 108), Pair(19, 117), Pair(-27, 131), Pair(38, 82), Pair(70, 69), Pair(53, 96), Pair(75, 60),
        Pair(0, 0), Pair(4, 118), Pair(29, 103), Pair(35, 90), Pair(-45, 123), Pair(-6, 75), Pair(64, 73), Pair(59, 45),
        Pair(27, 93), Pair(10, 51), Pair(-11, 112), Pair(29, 67), Pair(42, 82), Pair(6, 85), Pair(59, 55), Pair(51, 49),
        Pair(-41, 58), Pair(42, 89), Pair(7, 72), Pair(-5, 68), Pair(12, 74), Pair(15, 51), Pair(32, 72), Pair(-2, 117),
        Pair(-3, 77), Pair(-12, 113), Pair(6, 94), Pair(17, 86), Pair(-3, 96), Pair(2, 102), Pair(14, 104), Pair(21, 85)
      },
      { // Piece 4
        Pair(123, 130), Pair(69, 114), Pair(135, 157), Pair(210, 31), Pair(-32, 252), Pair(74, 160), Pair(33, 191), Pair(135, 202),
        Pair(66, 143), Pair(19, 232), Pair(-23, 266), Pair(-7, 254), Pair(27, 223), Pair(60, 246), Pair(-26, 201), Pair(88, 223),
        Pair(65, 84), Pair(-1, 221), Pair(-53, 328), Pair(66, 201), Pair(80, 145), Pair(27, 169), Pair(80, 156), Pair(113, 122),
        Pair(14, 196), Pair(1, 175), Pair(40, 207), Pair(-9, 203), Pair(39, 200), Pair(68, 142), Pair(72, 123), Pair(55, 189),
        Pair(0, 0), Pair(26, 247), Pair(6, 237), Pair(18, 183), Pair(40, 210), Pair(45, 191), Pair(71, 106), Pair(44, 173),
        Pair(46, 99), Pair(19, 168), Pair(34, 127), Pair(22, 168), Pair(40, 181), Pair(33, 223), Pair(65, 112), Pair(69, 199),
        Pair(1, 168), Pair(10, 208), Pair(22, 250), Pair(20, 191), Pair(29, 194), Pair(40, 152), Pair(92, 28), Pair(49, 117),
        Pair(46, 178), Pair(31, 150), Pair(27, 212), Pair(20, 207), Pair(24, 177), Pair(42, 164), Pair(42, 89), Pair(1, 236)
      },
      { // Piece 5
        Pair(9, 0), Pair(17, -24), Pair(63, -62), Pair(137, -33), Pair(45, -104), Pair(-7, 12), Pair(-10, 78), Pair(59, 35),
        Pair(76, -50), Pair(42, -36), Pair(239, -104), Pair(-97, 32), Pair(4, -34), Pair(24, -52), Pair(93, -107), Pair(59, -25),
        Pair(10, -60), Pair(116, -60), Pair(163, -62), Pair(-2, -17), Pair(230, -71), Pair(117, -42), Pair(-100, 38), Pair(131, -79),
        Pair(146, -105), Pair(87, -28), Pair(47, -22), Pair(-31, 11), Pair(98, -46), Pair(81, -21), Pair(-65, 15), Pair(-46, 22),
        Pair(0, 0), Pair(-77, 27), Pair(-164, 37), Pair(-14, 10), Pair(58, -16), Pair(14, -12), Pair(-18, 7), Pair(-52, 0),
        Pair(-145, 31), Pair(-29, 32), Pair(-66, 51), Pair(-24, 26), Pair(-37, 11), Pair(17, -16), Pair(-7, -21), Pair(-2, -12),
        Pair(-16, 42), Pair(23, 67), Pair(-55, 25), Pair(0, 16), Pair(-41, 4), Pair(-8, -23), Pair(15, -34), Pair(33, -38),
        Pair(-19, 34), Pair(-8, 38), Pair(-39, 38), Pair(-31, 4), Pair(-18, -5), Pair(14, -40), Pair(8, -45), Pair(27, -53)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-37, 16), Pair(14, 1), Pair(-26, 43), Pair(-8, 49), Pair(8, 40), Pair(12, 7), Pair(32, 6), Pair(-44, 17),
        Pair(22, -3), Pair(15, -9), Pair(7, 15), Pair(10, 17), Pair(2, 12), Pair(1, 11), Pair(10, 13), Pair(-9, 12),
        Pair(19, -4), Pair(0, 0), Pair(-1, -1), Pair(2, 0), Pair(4, 3), Pair(-3, 7), Pair(-9, 8), Pair(-10, 8),
        Pair(11, 0), Pair(0, 0), Pair(-5, 9), Pair(3, 1), Pair(3, -7), Pair(-14, 4), Pair(-6, 3), Pair(-7, -2),
        Pair(14, 5), Pair(5, 11), Pair(-10, -12), Pair(-2, 1), Pair(-3, -15), Pair(-9, 3), Pair(-6, -11), Pair(-11, 3),
        Pair(7, -15), Pair(13, 11), Pair(-7, -4), Pair(0, -5), Pair(-6, -4), Pair(-13, -8), Pair(-8, -8), Pair(-9, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(1, -33), Pair(83, 58), Pair(-32, 23), Pair(17, 19), Pair(-4, 29), Pair(-19, 10), Pair(100, -45), Pair(11, -70),
        Pair(-30, 40), Pair(8, 45), Pair(6, 23), Pair(67, -5), Pair(42, 66), Pair(-113, 58), Pair(1, 31), Pair(30, 50),
        Pair(-30, 60), Pair(-41, 74), Pair(-5, 76), Pair(56, 26), Pair(37, 26), Pair(113, 23), Pair(3, 5), Pair(22, 30),
        Pair(25, 50), Pair(-8, 43), Pair(16, 59), Pair(1, 13), Pair(29, 49), Pair(38, 29), Pair(24, -5), Pair(-11, 25),
        Pair(0, 31), Pair(0, 0), Pair(4, 69), Pair(20, 69), Pair(19, 34), Pair(28, 38), Pair(33, 18), Pair(41, -18),
        Pair(-9, 45), Pair(32, 81), Pair(-25, 8), Pair(10, 59), Pair(-8, 42), Pair(2, 53), Pair(22, 7), Pair(1, -36),
        Pair(16, -17), Pair(42, 60), Pair(4, 33), Pair(1, 55), Pair(0, 48), Pair(0, 30), Pair(-16, 100), Pair(23, 72),
        Pair(-181, 138), Pair(-16, -15), Pair(26, 43), Pair(4, 47), Pair(-2, 68), Pair(-12, 34), Pair(-2, 9), Pair(-44, 2)
      },
      { // Piece 2
        Pair(-6, 89), Pair(-72, 60), Pair(-50, 24), Pair(-73, 110), Pair(-123, 128), Pair(-173, 119), Pair(-85, 152), Pair(46, 33),
        Pair(-41, 67), Pair(19, 22), Pair(-21, 53), Pair(28, 63), Pair(-34, 110), Pair(-37, 150), Pair(39, 76), Pair(17, 100),
        Pair(-31, 74), Pair(12, 49), Pair(6, 76), Pair(-11, 90), Pair(-10, 136), Pair(-17, 92), Pair(57, 75), Pair(16, 71),
        Pair(-37, 67), Pair(8, 74), Pair(-10, 98), Pair(34, 95), Pair(25, 53), Pair(29, 88), Pair(-5, 84), Pair(-31, 70),
        Pair(3, 113), Pair(0, 0), Pair(10, 86), Pair(-3, 82), Pair(-4, 77), Pair(3, 57), Pair(15, 38), Pair(-21, 52),
        Pair(-36, -3), Pair(8, 169), Pair(-73, -8), Pair(16, 69), Pair(-4, 71), Pair(5, 76), Pair(27, -31), Pair(24, 54),
        Pair(22, 76), Pair(9, 59), Pair(24, 119), Pair(-17, 68), Pair(1, 52), Pair(1, 63), Pair(4, 52), Pair(-17, -17),
        Pair(-19, 24), Pair(14, 93), Pair(-6, 49), Pair(-45, 88), Pair(-59, 69), Pair(1, 64), Pair(-130, 97), Pair(56, -25)
      },
      { // Piece 3
        Pair(-38, 113), Pair(58, 119), Pair(31, 100), Pair(-81, 126), Pair(30, 75), Pair(23, 96), Pair(-22, 77), Pair(47, 52),
        Pair(7, 90), Pair(124, 102), Pair(2, 102), Pair(12, 104), Pair(39, 84), Pair(49, 45), Pair(-68, 71), Pair(9, 57),
        Pair(3, 93), Pair(16, 147), Pair(-9, 125), Pair(-5, 88), Pair(24, 95), Pair(-6, 73), Pair(-47, 114), Pair(20, 66),
        Pair(-5, 82), Pair(31, 150), Pair(-32, 128), Pair(-25, 127), Pair(24, 88), Pair(74, 47), Pair(1, 87), Pair(35, 44),
        Pair(-32, 75), Pair(0, 0), Pair(-8, 127), Pair(18, 101), Pair(-23, 91), Pair(11, 84), Pair(-7, 72), Pair(34, 57),
        Pair(22, 10), Pair(5, 62), Pair(-10, 13), Pair(-35, 127), Pair(6, 64), Pair(-3, 91), Pair(25, 60), Pair(36, 44),
        Pair(-24, 56), Pair(-21, 84), Pair(-13, 72), Pair(-12, 68), Pair(-1, 88), Pair(-3, 72), Pair(6, 129), Pair(12, 90),
        Pair(-20, 97), Pair(-30, 81), Pair(-9, 83), Pair(-12, 89), Pair(6, 79), Pair(6, 69), Pair(22, 58), Pair(15, 72)
      },
      { // Piece 4
        Pair(22, 72), Pair(-48, 174), Pair(35, 121), Pair(34, 192), Pair(-78, 165), Pair(9, 150), Pair(15, 149), Pair(128, 69),
        Pair(37, 145), Pair(25, 151), Pair(29, 103), Pair(-41, 218), Pair(16, 146), Pair(59, 109), Pair(85, 10), Pair(36, 96),
        Pair(-35, 217), Pair(83, 83), Pair(28, 139), Pair(9, 193), Pair(65, 134), Pair(10, 120), Pair(40, 116), Pair(77, 60),
        Pair(-7, 114), Pair(28, 173), Pair(56, 57), Pair(-12, 197), Pair(54, 91), Pair(49, 138), Pair(25, 214), Pair(52, 147),
        Pair(9, 177), Pair(0, 0), Pair(11, 155), Pair(31, 146), Pair(31, 136), Pair(0, 151), Pair(40, 75), Pair(26, 121),
        Pair(12, -47), Pair(37, 102), Pair(69, 21), Pair(15, 152), Pair(35, 109), Pair(26, 123), Pair(48, 71), Pair(57, 69),
        Pair(-67, 200), Pair(14, 120), Pair(14, 140), Pair(23, 122), Pair(24, 134), Pair(7, 168), Pair(25, 122), Pair(-21, 187),
        Pair(-20, 177), Pair(4, 74), Pair(16, 66), Pair(17, 121), Pair(32, 84), Pair(55, 22), Pair(52, 25), Pair(-30, 154)
      },
      { // Piece 5
        Pair(-33, -126), Pair(-34, -67), Pair(69, -107), Pair(-23, -54), Pair(-20, 33), Pair(-36, -8), Pair(26, -77), Pair(-2, -16),
        Pair(77, -87), Pair(141, -131), Pair(39, -8), Pair(-25, -36), Pair(-71, 64), Pair(-35, 0), Pair(-42, -30), Pair(-57, -40),
        Pair(152, -179), Pair(-71, -7), Pair(171, -19), Pair(55, -13), Pair(69, -27), Pair(-71, 9), Pair(-84, -33), Pair(-38, -69),
        Pair(80, -91), Pair(63, -39), Pair(-4, 1), Pair(-15, 10), Pair(68, 1), Pair(-85, 20), Pair(22, -22), Pair(6, -32),
        Pair(-5, -31), Pair(0, 0), Pair(30, -17), Pair(69, -2), Pair(34, 10), Pair(32, -7), Pair(-20, 26), Pair(122, -78),
        Pair(26, 19), Pair(-52, -21), Pair(-32, -22), Pair(-7, 25), Pair(21, 4), Pair(20, -11), Pair(-23, -10), Pair(67, -14),
        Pair(26, 26), Pair(-23, 16), Pair(-25, 27), Pair(-55, 24), Pair(-19, 14), Pair(-17, -9), Pair(-7, -14), Pair(-2, 3),
        Pair(-37, 11), Pair(13, -39), Pair(10, 8), Pair(-66, 33), Pair(-14, 4), Pair(-20, -13), Pair(-5, -6), Pair(7, -38)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, 19), Pair(-36, 10), Pair(-105, 19), Pair(25, -3), Pair(64, -24), Pair(44, 30), Pair(17, 11), Pair(1, 11),
        Pair(-14, -3), Pair(-12, 1), Pair(-57, 22), Pair(-14, 6), Pair(-8, -3), Pair(-15, 23), Pair(-17, 16), Pair(-2, 6),
        Pair(-8, -1), Pair(2, -1), Pair(0, 0), Pair(4, -4), Pair(1, 6), Pair(2, 5), Pair(3, -5), Pair(6, -5),
        Pair(-4, 3), Pair(-4, -3), Pair(0, 0), Pair(-4, -9), Pair(-4, 4), Pair(-4, 5), Pair(1, -10), Pair(-1, 0),
        Pair(-6, -1), Pair(2, -20), Pair(1, 15), Pair(-11, -2), Pair(-3, -2), Pair(-5, -2), Pair(-11, 3), Pair(-5, -9),
        Pair(-4, 4), Pair(1, -17), Pair(6, 8), Pair(-20, -14), Pair(-6, -11), Pair(-5, -11), Pair(-16, -8), Pair(-6, -13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-31, 19), Pair(-48, 75), Pair(132, -1), Pair(117, 37), Pair(19, 65), Pair(210, -2), Pair(-13, -22), Pair(15, 65),
        Pair(-4, 23), Pair(17, 42), Pair(82, 26), Pair(82, 69), Pair(-23, 80), Pair(-24, 34), Pair(40, 30), Pair(-106, 58),
        Pair(5, 29), Pair(7, 49), Pair(32, 18), Pair(76, 32), Pair(49, 13), Pair(79, 17), Pair(42, 71), Pair(95, 121),
        Pair(-27, 25), Pair(45, 76), Pair(22, 45), Pair(51, 65), Pair(45, 14), Pair(7, 46), Pair(37, 15), Pair(36, 24),
        Pair(13, 43), Pair(-16, 57), Pair(0, 0), Pair(32, 52), Pair(26, 72), Pair(32, 29), Pair(56, 12), Pair(48, -9),
        Pair(33, 84), Pair(-44, 25), Pair(26, 97), Pair(15, 28), Pair(61, 54), Pair(22, 39), Pair(53, 18), Pair(25, 56),
        Pair(10, 26), Pair(58, -21), Pair(30, 44), Pair(13, 48), Pair(5, 55), Pair(37, 15), Pair(-7, 15), Pair(53, 3),
        Pair(54, 4), Pair(20, 84), Pair(4, 28), Pair(3, 60), Pair(30, 1), Pair(43, -20), Pair(11, 25), Pair(20, -149)
      },
      { // Piece 2
        Pair(-23, 50), Pair(9, 45), Pair(-83, 82), Pair(103, 37), Pair(89, 54), Pair(11, 121), Pair(-159, 105), Pair(-50, 162),
        Pair(-25, 56), Pair(48, 32), Pair(-93, 81), Pair(-17, 14), Pair(-89, 110), Pair(168, 44), Pair(-64, 129), Pair(-69, 93),
        Pair(-19, 96), Pair(35, 83), Pair(48, 37), Pair(20, 78), Pair(22, 49), Pair(-61, 140), Pair(-34, 111), Pair(-3, 79),
        Pair(2, 101), Pair(-52, 72), Pair(6, 62), Pair(40, 51), Pair(18, 83), Pair(-32, 58), Pair(25, 60), Pair(-17, 70),
        Pair(-17, 9), Pair(10, 89), Pair(0, 0), Pair(26, 84), Pair(-17, 69), Pair(4, 65), Pair(-5, 51), Pair(21, 80),
        Pair(-3, 51), Pair(-89, -7), Pair(43, 124), Pair(-61, -47), Pair(-14, 86), Pair(1, 45), Pair(3, 37), Pair(25, 18),
        Pair(-54, 18), Pair(12, 49), Pair(-4, 71), Pair(0, 74), Pair(-18, 15), Pair(-2, 97), Pair(11, 63), Pair(-22, 62),
        Pair(-62, 103), Pair(22, 68), Pair(2, 78), Pair(32, 5), Pair(48, 49), Pair(-8, 43), Pair(-50, 132), Pair(15, 55)
      },
      { // Piece 3
        Pair(-129, 141), Pair(-18, 112), Pair(-92, 117), Pair(-45, 114), Pair(-31, 115), Pair(-64, 105), Pair(-3, 85), Pair(52, 98),
        Pair(-1, 82), Pair(-16, 106), Pair(115, 82), Pair(14, 85), Pair(35, 65), Pair(-29, 88), Pair(6, 79), Pair(-36, 83),
        Pair(57, 80), Pair(36, 66), Pair(27, 100), Pair(7, 65), Pair(23, 74), Pair(105, 20), Pair(76, 56), Pair(23, 58),
        Pair(-2, 97), Pair(23, 70), Pair(-16, 99), Pair(-10, 109), Pair(51, 48), Pair(-44, 97), Pair(42, 65), Pair(16, 65),
        Pair(-33, 120), Pair(34, 116), Pair(0, 0), Pair(-16, 114), Pair(13, 81), Pair(0, 71), Pair(49, 50), Pair(3, 67),
        Pair(-31, 116), Pair(37, 31), Pair(-4, 55), Pair(-78, 7), Pair(1, 60), Pair(3, 51), Pair(26, 90), Pair(-13, 64),
        Pair(-6, 48), Pair(-34, 77), Pair(-71, 94), Pair(-51, 110), Pair(14, 78), Pair(-25, 78), Pair(17, 49), Pair(6, 57),
        Pair(-22, 100), Pair(-16, 102), Pair(-31, 63), Pair(-7, 83), Pair(-9, 80), Pair(-8, 98), Pair(-13, 88), Pair(-12, 84)
      },
      { // Piece 4
        Pair(82, 112), Pair(92, 45), Pair(118, 59), Pair(6, 258), Pair(200, -19), Pair(85, 73), Pair(51, 103), Pair(19, 203),
        Pair(64, 92), Pair(72, 74), Pair(123, 124), Pair(57, 87), Pair(27, 110), Pair(177, 95), Pair(139, 69), Pair(72, 148),
        Pair(47, 25), Pair(42, 143), Pair(78, 87), Pair(-17, 162), Pair(72, 133), Pair(13, 155), Pair(71, 70), Pair(61, 146),
        Pair(43, 107), Pair(10, 225), Pair(78, 73), Pair(58, 189), Pair(48, 134), Pair(5, 198), Pair(65, 90), Pair(54, 144),
        Pair(48, 10), Pair(42, 42), Pair(0, 0), Pair(43, 100), Pair(47, 148), Pair(42, 157), Pair(65, 67), Pair(40, 116),
        Pair(-15, 147), Pair(13, 109), Pair(26, 84), Pair(-23, -17), Pair(35, 62), Pair(24, 125), Pair(20, 136), Pair(64, 95),
        Pair(-10, 214), Pair(-14, 181), Pair(32, 73), Pair(-7, 141), Pair(27, 109), Pair(-4, 212), Pair(74, 89), Pair(-10, 128),
        Pair(-5, 142), Pair(-4, 72), Pair(23, 52), Pair(21, 41), Pair(33, 136), Pair(24, 102), Pair(-54, 312), Pair(55, 52)
      },
      { // Piece 5
        Pair(-16, 9), Pair(-37, -104), Pair(-69, -78), Pair(-29, -92), Pair(-43, 54), Pair(-4, 104), Pair(57, 39), Pair(-36, -23),
        Pair(18, 11), Pair(7, -48), Pair(-100, -24), Pair(-11, -19), Pair(175, -48), Pair(63, -72), Pair(84, -90), Pair(27, -1),
        Pair(-103, -1), Pair(19, -27), Pair(-51, -1), Pair(151, -29), Pair(51, -40), Pair(51, 15), Pair(-66, 16), Pair(94, -77),
        Pair(-132, 55), Pair(-27, 4), Pair(264, -43), Pair(155, -21), Pair(262, -39), Pair(31, -10), Pair(28, -8), Pair(-4, 10),
        Pair(-56, 70), Pair(-77, 25), Pair(0, 0), Pair(27, -19), Pair(39, 10), Pair(54, 4), Pair(-46, -8), Pair(-83, -3),
        Pair(-5, -3), Pair(50, 0), Pair(-90, -1), Pair(-127, 32), Pair(16, 11), Pair(25, 10), Pair(-15, -9), Pair(10, -40),
        Pair(-136, 112), Pair(-64, 35), Pair(-3, 30), Pair(30, 1), Pair(17, 1), Pair(8, 9), Pair(20, -6), Pair(34, -27),
        Pair(-24, 83), Pair(-50, 55), Pair(-27, -12), Pair(-14, 18), Pair(0, 11), Pair(21, 7), Pair(2, 8), Pair(26, -9)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 42), Pair(-54, 45), Pair(-27, 11), Pair(-36, 7), Pair(-5, 38), Pair(-1, -14), Pair(33, 50), Pair(-13, 13),
        Pair(-1, 22), Pair(-3, 22), Pair(15, 5), Pair(-13, -5), Pair(-18, 17), Pair(-27, 27), Pair(7, 12), Pair(-1, 19),
        Pair(-5, 5), Pair(0, 2), Pair(-5, 4), Pair(0, 0), Pair(-4, 3), Pair(7, -1), Pair(-10, 10), Pair(-1, 2),
        Pair(-1, -2), Pair(0, 1), Pair(-5, -6), Pair(0, 0), Pair(-7, 5), Pair(1, 2), Pair(-4, 4), Pair(2, -7),
        Pair(-1, -10), Pair(-3, -4), Pair(-3, -31), Pair(6, 13), Pair(-5, -25), Pair(-2, 9), Pair(-10, -1), Pair(-3, 0),
        Pair(2, -5), Pair(-6, -3), Pair(-5, -17), Pair(-12, 7), Pair(-18, -15), Pair(-2, -3), Pair(-8, 2), Pair(-1, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-20, 86), Pair(81, 50), Pair(136, 33), Pair(-120, 62), Pair(30, 44), Pair(-47, 27), Pair(64, -54), Pair(-15, -45),
        Pair(27, 31), Pair(130, -2), Pair(10, 69), Pair(-81, 54), Pair(11, 58), Pair(-1, 116), Pair(9, 34), Pair(0, 56),
        Pair(42, 14), Pair(35, 52), Pair(-12, 58), Pair(-4, 105), Pair(-30, 68), Pair(-34, 48), Pair(-38, 105), Pair(-28, 74),
        Pair(15, 64), Pair(-8, 27), Pair(47, 42), Pair(-4, 74), Pair(31, 52), Pair(-7, 26), Pair(17, 47), Pair(-5, 50),
        Pair(-36, 16), Pair(-43, 97), Pair(21, 60), Pair(0, 0), Pair(7, 69), Pair(-8, 88), Pair(27, 26), Pair(16, 47),
        Pair(-8, 33), Pair(-3, 52), Pair(-37, 22), Pair(26, 94), Pair(-10, -19), Pair(10, 39), Pair(3, 47), Pair(19, 48),
        Pair(-22, 22), Pair(26, 18), Pair(-15, 41), Pair(-9, 80), Pair(-2, 10), Pair(11, 94), Pair(33, 3), Pair(9, 82),
        Pair(-18, 96), Pair(-20, 12), Pair(-14, 101), Pair(-65, 27), Pair(-22, 141), Pair(-14, 23), Pair(17, 50), Pair(-1, -30)
      },
      { // Piece 2
        Pair(42, 63), Pair(40, 17), Pair(45, 102), Pair(22, 64), Pair(-123, 97), Pair(-116, 81), Pair(-90, 121), Pair(-45, 10),
        Pair(-188, 91), Pair(0, 66), Pair(6, 53), Pair(-73, 74), Pair(-140, 103), Pair(6, 97), Pair(37, 32), Pair(-24, 118),
        Pair(13, 83), Pair(-53, 36), Pair(-20, 86), Pair(26, 43), Pair(-9, 90), Pair(-90, 119), Pair(-33, 141), Pair(17, 34),
        Pair(-57, 63), Pair(2, 94), Pair(-40, 60), Pair(21, 84), Pair(-30, 55), Pair(19, 100), Pair(-17, 58), Pair(16, 74),
        Pair(-14, 89), Pair(-47, 81), Pair(18, 97), Pair(0, 0), Pair(9, 100), Pair(-11, 56), Pair(-30, 56), Pair(-3, 19),
        Pair(-32, 63), Pair(-11, 90), Pair(-82, -27), Pair(7, 147), Pair(-33, -33), Pair(12, 65), Pair(-7, 43), Pair(5, 66),
        Pair(-5, 85), Pair(-49, 4), Pair(-72, 141), Pair(-5, 44), Pair(-19, 89), Pair(-31, 17), Pair(-4, 90), Pair(28, 14),
        Pair(-117, -9), Pair(-16, 106), Pair(-12, 42), Pair(7, 65), Pair(-42, 49), Pair(-16, 86), Pair(8, -68), Pair(25, 76)
      },
      { // Piece 3
        Pair(-2, 77), Pair(-68, 117), Pair(17, 105), Pair(-40, 126), Pair(25, 98), Pair(-43, 131), Pair(100, 63), Pair(-16, 108),
        Pair(-32, 89), Pair(-6, 78), Pair(3, 69), Pair(93, 79), Pair(28, 82), Pair(-36, 96), Pair(-3, 62), Pair(45, 68),
        Pair(42, 57), Pair(-27, 80), Pair(5, 63), Pair(51, 117), Pair(-54, 125), Pair(-40, 94), Pair(3, 90), Pair(85, 43),
        Pair(-26, 94), Pair(-22, 93), Pair(10, 87), Pair(-3, 102), Pair(19, 74), Pair(-1, 80), Pair(58, 79), Pair(35, 57),
        Pair(-48, 107), Pair(-76, 137), Pair(24, 69), Pair(0, 0), Pair(-20, 96), Pair(-33, 122), Pair(-5, 50), Pair(2, 72),
        Pair(-42, 88), Pair(-2, 77), Pair(-49, 73), Pair(-8, 72), Pair(38, 50), Pair(3, 74), Pair(-4, 45), Pair(10, 72),
        Pair(-35, 69), Pair(-28, 85), Pair(-26, 44), Pair(-65, 67), Pair(-27, 91), Pair(-20, 54), Pair(14, 39), Pair(-7, 94),
        Pair(-11, 81), Pair(-14, 79), Pair(-11, 67), Pair(-30, 72), Pair(-13, 72), Pair(-11, 82), Pair(10, 42), Pair(1, 59)
      },
      { // Piece 4
        Pair(44, 167), Pair(-56, 244), Pair(133, 42), Pair(148, 48), Pair(33, 136), Pair(78, 116), Pair(-18, 153), Pair(80, 3),
        Pair(8, 120), Pair(45, 131), Pair(4, 187), Pair(16, 216), Pair(2, 136), Pair(52, 193), Pair(4, 194), Pair(36, 137),
        Pair(26, 157), Pair(53, 141), Pair(9, 152), Pair(24, 109), Pair(52, 57), Pair(28, 107), Pair(37, 150), Pair(-15, 194),
        Pair(8, 149), Pair(22, 163), Pair(34, 121), Pair(47, 158), Pair(27, 129), Pair(33, 173), Pair(16, 100), Pair(16, 131),
        Pair(18, 148), Pair(8, 146), Pair(38, 134), Pair(0, 0), Pair(16, 142), Pair(47, 130), Pair(28, 202), Pair(67, 111),
        Pair(45, 133), Pair(34, 66), Pair(-12, -8), Pair(25, 119), Pair(-19, -7), Pair(18, 183), Pair(20, 150), Pair(37, 120),
        Pair(-4, 58), Pair(-22, 126), Pair(2, 120), Pair(18, 123), Pair(6, 179), Pair(-13, 195), Pair(26, 74), Pair(22, 21),
        Pair(31, 83), Pair(0, 151), Pair(19, 22), Pair(22, 147), Pair(16, 102), Pair(59, 63), Pair(-1, 185), Pair(-35, 232)
      },
      { // Piece 5
        Pair(-25, -65), Pair(-50, 23), Pair(62, 82), Pair(-63, 22), Pair(63, -3), Pair(23, -59), Pair(22, -143), Pair(29, -71),
        Pair(-102, -8), Pair(-86, -21), Pair(81, -19), Pair(19, 70), Pair(56, 71), Pair(-90, -103), Pair(-10, -92), Pair(-73, -5),
        Pair(-107, -29), Pair(93, -47), Pair(166, -27), Pair(40, -21), Pair(-2, 45), Pair(97, 23), Pair(13, -27), Pair(-22, -51),
        Pair(27, 0), Pair(40, 7), Pair(89, -16), Pair(-59, 34), Pair(-31, 22), Pair(61, 7), Pair(57, 38), Pair(-44, 16),
        Pair(21, -5), Pair(-83, -8), Pair(-151, 3), Pair(0, 0), Pair(124, -38), Pair(59, 0), Pair(110, -11), Pair(-48, 12),
        Pair(14, 45), Pair(-74, 5), Pair(90, 9), Pair(-93, -3), Pair(121, -34), Pair(-1, -14), Pair(5, 4), Pair(61, -8),
        Pair(-40, 39), Pair(-87, 26), Pair(-11, 18), Pair(6, 3), Pair(26, -2), Pair(-24, 13), Pair(-4, 8), Pair(-4, -1),
        Pair(19, -42), Pair(-11, 13), Pair(-17, 19), Pair(6, -6), Pair(12, -15), Pair(-14, 10), Pair(4, 5), Pair(-7, 0)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, 7), Pair(27, 25), Pair(-50, 14), Pair(-59, 15), Pair(-34, 31), Pair(2, 19), Pair(-10, 4), Pair(53, 13),
        Pair(-5, 20), Pair(13, -4), Pair(-22, 10), Pair(-14, 3), Pair(-26, 25), Pair(-34, 3), Pair(1, 26), Pair(-11, 5),
        Pair(-8, 0), Pair(-1, -3), Pair(-3, -6), Pair(5, -3), Pair(0, 0), Pair(-2, 5), Pair(0, -3), Pair(-8, 10),
        Pair(-7, -2), Pair(-7, -4), Pair(1, -9), Pair(-9, 1), Pair(0, 0), Pair(-4, 1), Pair(5, 1), Pair(-2, 6),
        Pair(-8, -1), Pair(-10, 5), Pair(-9, 5), Pair(8, -36), Pair(9, -1), Pair(12, -23), Pair(-8, 5), Pair(-5, -1),
        Pair(-7, -5), Pair(-10, -7), Pair(-2, -10), Pair(-12, -10), Pair(1, -17), Pair(-9, -13), Pair(-5, 5), Pair(-5, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(84, -52), Pair(-222, 39), Pair(-23, 40), Pair(-73, 21), Pair(4, 42), Pair(-3, 67), Pair(-132, 70), Pair(160, -2),
        Pair(-51, 75), Pair(31, 40), Pair(-28, 108), Pair(-16, 69), Pair(2, 37), Pair(-20, 67), Pair(3, 96), Pair(-6, -46),
        Pair(-7, 73), Pair(51, 39), Pair(9, 43), Pair(-16, 44), Pair(41, 37), Pair(-21, 23), Pair(2, 22), Pair(28, 65),
        Pair(20, 2), Pair(28, 52), Pair(-6, 11), Pair(9, 71), Pair(-1, 67), Pair(-8, 65), Pair(-20, -1), Pair(-12, 66),
        Pair(4, 66), Pair(-50, 43), Pair(-1, 81), Pair(-12, 80), Pair(0, 0), Pair(7, 48), Pair(33, 54), Pair(-21, -4),
        Pair(-1, 85), Pair(-10, -1), Pair(7, 49), Pair(7, -55), Pair(7, 102), Pair(-34, -12), Pair(-2, 78), Pair(2, 28),
        Pair(41, 7), Pair(6, -9), Pair(-8, 43), Pair(-6, 28), Pair(1, 46), Pair(12, -30), Pair(-3, 8), Pair(-34, -36),
        Pair(86, -111), Pair(1, 53), Pair(-27, 28), Pair(4, 61), Pair(3, -59), Pair(15, 55), Pair(-15, -39), Pair(-9, 22)
      },
      { // Piece 2
        Pair(32, -7), Pair(52, 79), Pair(-227, 109), Pair(-37, 84), Pair(-135, 130), Pair(-132, 98), Pair(-53, 50), Pair(60, 78),
        Pair(1, 92), Pair(7, 33), Pair(13, 66), Pair(-112, 106), Pair(-39, 60), Pair(-19, 76), Pair(-8, 44), Pair(95, -1),
        Pair(-70, 32), Pair(-28, 98), Pair(-12, 57), Pair(-23, 75), Pair(-11, 80), Pair(-8, 92), Pair(-64, 84), Pair(18, 81),
        Pair(-70, 73), Pair(-20, 48), Pair(27, 84), Pair(-19, 45), Pair(11, 56), Pair(-19, 82), Pair(11, 102), Pair(-8, 39),
        Pair(17, 37), Pair(-2, 82), Pair(-15, 48), Pair(20, 74), Pair(0, 0), Pair(8, 96), Pair(1, 44), Pair(-11, 52),
        Pair(-17, 67), Pair(-26, 62), Pair(-15, 76), Pair(-34, -80), Pair(17, 98), Pair(-86, -30), Pair(6, 58), Pair(-27, 62),
        Pair(0, 62), Pair(-4, 70), Pair(-29, 23), Pair(-11, 59), Pair(-20, 35), Pair(-37, 130), Pair(-37, -4), Pair(-8, 64),
        Pair(-13, 98), Pair(-71, 49), Pair(4, 49), Pair(26, 27), Pair(-30, 82), Pair(-17, 47), Pair(-54, 139), Pair(-33, 10)
      },
      { // Piece 3
        Pair(-38, 74), Pair(-48, 100), Pair(-8, 58), Pair(-4, 78), Pair(-6, 85), Pair(124, 26), Pair(-25, 104), Pair(-67, 99),
        Pair(14, 32), Pair(1, 51), Pair(-7, 65), Pair(-91, 94), Pair(0, 68), Pair(1, 63), Pair(107, 25), Pair(3, 47),
        Pair(37, 35), Pair(-11, 66), Pair(50, 28), Pair(-13, 58), Pair(70, 73), Pair(38, 33), Pair(-75, 88), Pair(46, 36),
        Pair(6, 28), Pair(12, 66), Pair(11, 66), Pair(-20, 68), Pair(57, 74), Pair(5, 75), Pair(-25, 77), Pair(-29, 87),
        Pair(-4, 55), Pair(16, 38), Pair(-3, 51), Pair(-15, 48), Pair(0, 0), Pair(-27, 75), Pair(-65, 107), Pair(22, 17),
        Pair(-30, 80), Pair(-7, 39), Pair(-24, 45), Pair(-91, 61), Pair(-24, 63), Pair(-18, -31), Pair(-13, 47), Pair(7, 26),
        Pair(-7, 9), Pair(-12, 29), Pair(-15, 31), Pair(-44, 70), Pair(-55, 61), Pair(-16, 70), Pair(-40, 75), Pair(-9, 65),
        Pair(-17, 63), Pair(-9, 51), Pair(-17, 64), Pair(-19, 54), Pair(-45, 47), Pair(-15, 67), Pair(-11, 71), Pair(-4, 48)
      },
      { // Piece 4
        Pair(65, 151), Pair(73, 112), Pair(68, 93), Pair(59, 103), Pair(78, 52), Pair(94, 101), Pair(-53, 99), Pair(39, 149),
        Pair(25, 101), Pair(49, 50), Pair(48, 117), Pair(50, 93), Pair(28, 97), Pair(77, 18), Pair(60, 81), Pair(29, 60),
        Pair(23, 96), Pair(-6, 131), Pair(50, 33), Pair(39, 141), Pair(36, 87), Pair(-28, 166), Pair(27, 95), Pair(23, 179),
        Pair(12, 105), Pair(35, 71), Pair(-2, 156), Pair(64, 30), Pair(85, 68), Pair(10, 131), Pair(37, 173), Pair(25, 115),
        Pair(10, 164), Pair(18, 143), Pair(34, 51), Pair(61, 31), Pair(0, 0), Pair(56, 66), Pair(52, 81), Pair(30, 91),
        Pair(-8, 199), Pair(32, 82), Pair(12, 103), Pair(2, 95), Pair(29, 95), Pair(58, -74), Pair(3, 179), Pair(2, 126),
        Pair(-12, 184), Pair(29, 61), Pair(21, 102), Pair(6, 152), Pair(29, 93), Pair(-8, 156), Pair(26, 42), Pair(22, 145),
        Pair(51, 54), Pair(43, 52), Pair(-12, 160), Pair(23, 92), Pair(15, 76), Pair(40, 88), Pair(73, 42), Pair(17, 68)
      },
      { // Piece 5
        Pair(-99, -25), Pair(-20, -92), Pair(138, -151), Pair(-20, -106), Pair(14, -41), Pair(31, -164), Pair(-89, -43), Pair(-15, -100),
        Pair(-9, -96), Pair(73, -31), Pair(78, -77), Pair(180, -70), Pair(156, -74), Pair(75, -51), Pair(26, -76), Pair(-76, -72),
        Pair(-31, -11), Pair(115, -19), Pair(12, -18), Pair(191, -96), Pair(196, -30), Pair(282, -66), Pair(9, -36), Pair(-154, -50),
        Pair(180, -40), Pair(4, -16), Pair(30, -22), Pair(41, -23), Pair(129, -1), Pair(123, -23), Pair(129, -26), Pair(-1, -24),
        Pair(-36, 46), Pair(-45, 5), Pair(-93, 13), Pair(73, -21), Pair(0, 0), Pair(142, -50), Pair(-111, 42), Pair(-3, 53),
        Pair(-12, -16), Pair(37, -12), Pair(-5, 7), Pair(-128, 11), Pair(4, -28), Pair(-51, -14), Pair(-39, 31), Pair(-42, 56),
        Pair(23, -45), Pair(-26, 8), Pair(-49, 20), Pair(61, -5), Pair(36, 6), Pair(39, -2), Pair(-4, 15), Pair(2, 17),
        Pair(12, 35), Pair(-9, 16), Pair(-14, 20), Pair(0, -1), Pair(-8, 2), Pair(2, 9), Pair(-13, 31), Pair(9, 28)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, 23), Pair(68, -17), Pair(36, -4), Pair(-20, 12), Pair(-39, -3), Pair(-55, 15), Pair(-20, -1), Pair(-15, 20),
        Pair(18, 3), Pair(-6, 5), Pair(-23, -1), Pair(-31, 19), Pair(-31, 1), Pair(-7, 32), Pair(-15, 19), Pair(10, -7),
        Pair(7, -2), Pair(2, -7), Pair(0, -4), Pair(-6, 2), Pair(1, -5), Pair(0, 0), Pair(12, -6), Pair(-3, 8),
        Pair(18, -8), Pair(-1, -19), Pair(-1, -8), Pair(-2, -4), Pair(-4, -10), Pair(0, 0), Pair(5, -4), Pair(3, -3),
        Pair(4, -9), Pair(-5, -15), Pair(-12, -7), Pair(4, -5), Pair(-5, -21), Pair(11, 9), Pair(-12, -19), Pair(0, -6),
        Pair(-1, -10), Pair(-5, -10), Pair(-7, -10), Pair(0, -7), Pair(-15, -21), Pair(7, -10), Pair(-14, -17), Pair(1, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(47, 45), Pair(-69, -20), Pair(-44, 46), Pair(-107, 34), Pair(-37, 74), Pair(129, -23), Pair(79, -132), Pair(5, 45),
        Pair(48, -44), Pair(16, 5), Pair(-27, 38), Pair(-49, 23), Pair(18, -9), Pair(-56, 21), Pair(54, 2), Pair(-14, 45),
        Pair(-82, 25), Pair(53, 14), Pair(-4, 31), Pair(13, 4), Pair(-1, -9), Pair(-45, 40), Pair(73, -14), Pair(100, -28),
        Pair(-7, 26), Pair(12, 2), Pair(-24, 36), Pair(4, -43), Pair(45, 41), Pair(-11, 38), Pair(30, 37), Pair(-74, -10),
        Pair(15, 28), Pair(4, 2), Pair(-4, -18), Pair(17, 31), Pair(16, 31), Pair(0, 0), Pair(-11, 13), Pair(-2, 67),
        Pair(2, 80), Pair(-22, 37), Pair(0, -1), Pair(8, 9), Pair(-31, -25), Pair(22, 61), Pair(-59, 26), Pair(21, 47),
        Pair(-26, -15), Pair(8, -20), Pair(-9, 1), Pair(-3, 43), Pair(-7, 6), Pair(-16, 50), Pair(7, 41), Pair(-12, 37),
        Pair(-169, -109), Pair(3, 13), Pair(25, 48), Pair(-33, -1), Pair(-15, 69), Pair(-98, 45), Pair(9, 69), Pair(-66, -91)
      },
      { // Piece 2
        Pair(-2, 74), Pair(66, -18), Pair(-20, 47), Pair(-8, 68), Pair(-38, 51), Pair(102, -51), Pair(-124, 65), Pair(-78, 6),
        Pair(24, -17), Pair(-3, 88), Pair(-58, 47), Pair(51, 29), Pair(-36, 32), Pair(-87, 65), Pair(-99, 51), Pair(62, 31),
        Pair(32, 16), Pair(5, 26), Pair(-47, 75), Pair(-11, 5), Pair(-72, 59), Pair(9, 8), Pair(-8, 24), Pair(37, -42),
        Pair(75, -2), Pair(4, 39), Pair(54, -4), Pair(-15, 54), Pair(-14, 52), Pair(-20, 38), Pair(3, 34), Pair(-12, 52),
        Pair(7, 40), Pair(11, 3), Pair(-9, 27), Pair(57, 11), Pair(26, 40), Pair(0, 0), Pair(42, 47), Pair(-2, 31),
        Pair(8, 21), Pair(-26, 50), Pair(14, 5), Pair(-1, 37), Pair(-85, -49), Pair(-1, 107), Pair(-104, -106), Pair(17, 15),
        Pair(-85, 53), Pair(-7, 32), Pair(49, 18), Pair(-11, -5), Pair(-12, 43), Pair(10, -10), Pair(0, 28), Pair(-89, -54),
        Pair(-64, 8), Pair(-85, 62), Pair(-14, 30), Pair(-100, 97), Pair(-52, -11), Pair(-1, 47), Pair(-84, -11), Pair(-67, 56)
      },
      { // Piece 3
        Pair(-20, 40), Pair(-57, 58), Pair(-9, 48), Pair(11, 46), Pair(3, 55), Pair(-4, 56), Pair(9, 49), Pair(33, 36),
        Pair(45, 24), Pair(13, 36), Pair(-9, 33), Pair(12, 17), Pair(58, 14), Pair(104, 8), Pair(-6, 19), Pair(-5, 31),
        Pair(54, 1), Pair(75, 20), Pair(104, -10), Pair(-52, 55), Pair(-3, 30), Pair(76, 26), Pair(-27, 49), Pair(34, 26),
        Pair(19, 24), Pair(-16, 29), Pair(54, 23), Pair(87, 2), Pair(-9, 44), Pair(-94, 69), Pair(-24, 22), Pair(18, -10),
        Pair(67, -9), Pair(-29, 27), Pair(11, 4), Pair(64, 7), Pair(18, 13), Pair(0, 0), Pair(-56, 43), Pair(-16, -6),
        Pair(-24, 33), Pair(16, 21), Pair(10, -22), Pair(-55, 49), Pair(-25, -68), Pair(-29, 28), Pair(-22, 8), Pair(-33, 25),
        Pair(1, -11), Pair(-32, 30), Pair(5, -3), Pair(13, -3), Pair(8, 3), Pair(1, -8), Pair(-15, 6), Pair(-5, 31),
        Pair(-3, 22), Pair(-4, 16), Pair(14, 13), Pair(-6, 37), Pair(-6, 19), Pair(-24, 25), Pair(-10, 11), Pair(-24, 33)
      },
      { // Piece 4
        Pair(-21, 104), Pair(-5, 134), Pair(-84, 113), Pair(78, 28), Pair(64, 36), Pair(22, 171), Pair(28, 107), Pair(-106, 186),
        Pair(57, -29), Pair(36, 4), Pair(72, 25), Pair(4, 100), Pair(-30, 121), Pair(101, -1), Pair(52, 73), Pair(7, 94),
        Pair(74, -28), Pair(14, 76), Pair(-2, 141), Pair(32, 74), Pair(57, 2), Pair(40, 23), Pair(-56, 140), Pair(106, -113),
        Pair(41, -13), Pair(5, 132), Pair(36, -33), Pair(45, 40), Pair(82, 74), Pair(39, 142), Pair(51, -72), Pair(29, 72),
        Pair(22, 58), Pair(27, -11), Pair(29, 76), Pair(23, 12), Pair(-11, 99), Pair(0, 0), Pair(18, 76), Pair(14, 72),
        Pair(14, 39), Pair(19, 47), Pair(29, 46), Pair(18, 71), Pair(-55, -9), Pair(20, 40), Pair(21, -93), Pair(52, 58),
        Pair(-7, 35), Pair(14, 123), Pair(9, 154), Pair(4, 61), Pair(7, 127), Pair(20, 2), Pair(4, 0), Pair(8, -108),
        Pair(51, -9), Pair(-44, 131), Pair(-4, 106), Pair(4, 126), Pair(36, 53), Pair(31, 4), Pair(55, 151), Pair(-63, 66)
      },
      { // Piece 5
        Pair(42, 77), Pair(53, -99), Pair(-43, -3), Pair(29, 41), Pair(-4, -95), Pair(-81, 5), Pair(-79, -80), Pair(26, -52),
        Pair(-52, -76), Pair(0, -30), Pair(38, -60), Pair(-29, -14), Pair(32, -62), Pair(23, -38), Pair(47, 0), Pair(86, -47),
        Pair(-103, -101), Pair(-7, 3), Pair(68, -14), Pair(17, -12), Pair(32, -23), Pair(165, -70), Pair(103, -44), Pair(48, -94),
        Pair(-12, 22), Pair(16, -4), Pair(28, -4), Pair(99, -19), Pair(141, -35), Pair(11, 7), Pair(96, -21), Pair(-156, 45),
        Pair(-82, 0), Pair(186, -35), Pair(10, 19), Pair(118, -21), Pair(15, -14), Pair(0, 0), Pair(57, -17), Pair(2, -9),
        Pair(84, -32), Pair(21, -9), Pair(57, -5), Pair(-16, 27), Pair(90, -3), Pair(-43, -6), Pair(7, -3), Pair(-62, 40),
        Pair(-3, -13), Pair(45, -28), Pair(-3, 1), Pair(2, -2), Pair(24, 13), Pair(37, 20), Pair(-3, 35), Pair(-55, 65),
        Pair(37, -60), Pair(42, -28), Pair(3, 4), Pair(-21, 3), Pair(-8, 9), Pair(-27, 8), Pair(-23, 33), Pair(-32, 56)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(70, -6), Pair(28, 15), Pair(4, 27), Pair(25, 1), Pair(-69, 28), Pair(31, -3), Pair(-12, -3), Pair(59, -29),
        Pair(12, 1), Pair(11, -10), Pair(-5, -2), Pair(15, 3), Pair(-13, 11), Pair(30, -11), Pair(26, -4), Pair(27, -23),
        Pair(4, -6), Pair(8, -10), Pair(-4, 3), Pair(9, -10), Pair(-2, 3), Pair(-10, 6), Pair(0, 0), Pair(8, -3),
        Pair(-1, -7), Pair(4, -9), Pair(-4, -11), Pair(1, -16), Pair(1, -4), Pair(-2, -3), Pair(0, 0), Pair(18, -4),
        Pair(3, -14), Pair(-2, -13), Pair(-2, -12), Pair(2, -8), Pair(0, -11), Pair(-2, 1), Pair(6, 0), Pair(13, -2),
        Pair(-4, -7), Pair(-2, -11), Pair(-3, -10), Pair(-6, -8), Pair(-6, 5), Pair(-3, -13), Pair(4, -6), Pair(8, -22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(71, -35), Pair(-125, -12), Pair(49, -58), Pair(34, 13), Pair(-11, 20), Pair(72, -7), Pair(69, 43), Pair(-145, -10),
        Pair(26, -1), Pair(59, 0), Pair(-22, -3), Pair(-34, 38), Pair(2, 7), Pair(-27, 15), Pair(41, 70), Pair(-119, 18),
        Pair(-73, 17), Pair(22, 4), Pair(0, 33), Pair(50, 14), Pair(-55, 57), Pair(-65, 37), Pair(-18, 34), Pair(24, 44),
        Pair(53, -48), Pair(24, 7), Pair(-22, 28), Pair(33, 7), Pair(-3, -1), Pair(-17, 26), Pair(-14, 53), Pair(19, 67),
        Pair(-10, 12), Pair(35, -24), Pair(4, 15), Pair(-2, 11), Pair(8, 44), Pair(9, 51), Pair(0, 0), Pair(-42, 46),
        Pair(-4, -7), Pair(24, -12), Pair(8, 12), Pair(15, 18), Pair(11, 7), Pair(-65, 7), Pair(37, 75), Pair(-27, -78),
        Pair(-72, 55), Pair(-19, 35), Pair(4, -8), Pair(-5, 21), Pair(-2, 43), Pair(-20, 12), Pair(-28, 28), Pair(-30, -39),
        Pair(-155, 44), Pair(-12, -12), Pair(16, -47), Pair(-2, 12), Pair(-25, 35), Pair(10, 44), Pair(-21, -31), Pair(-57, 96)
      },
      { // Piece 2
        Pair(75, 35), Pair(-278, 130), Pair(-189, 97), Pair(-75, 39), Pair(-188, 97), Pair(-105, 57), Pair(82, -70), Pair(64, 64),
        Pair(-12, 13), Pair(-30, 43), Pair(-92, 111), Pair(-43, 79), Pair(-54, 48), Pair(-12, 69), Pair(-60, 15), Pair(60, 31),
        Pair(8, 31), Pair(8, 27), Pair(-12, 63), Pair(-14, 78), Pair(-26, 80), Pair(-45, 38), Pair(26, 27), Pair(16, 5),
        Pair(23, 12), Pair(17, 33), Pair(-5, 7), Pair(-9, 35), Pair(4, 27), Pair(-53, 48), Pair(4, 15), Pair(8, 2),
        Pair(-27, 63), Pair(-2, 44), Pair(0, 26), Pair(25, 19), Pair(5, 45), Pair(7, 35), Pair(0, 0), Pair(32, 36),
        Pair(22, 26), Pair(6, 22), Pair(31, 17), Pair(-7, 49), Pair(9, 25), Pair(-59, -45), Pair(15, 96), Pair(-82, -34),
        Pair(12, 17), Pair(23, 14), Pair(-25, 27), Pair(7, 16), Pair(-25, 37), Pair(2, 0), Pair(14, 14), Pair(-34, 41),
        Pair(-18, 58), Pair(-114, 123), Pair(6, 33), Pair(13, 8), Pair(16, 37), Pair(-10, 19), Pair(124, 1), Pair(30, -2)
      },
      { // Piece 3
        Pair(50, 36), Pair(-45, 57), Pair(-103, 64), Pair(41, 46), Pair(-11, 60), Pair(-90, 73), Pair(61, 39), Pair(-39, 53),
        Pair(20, 28), Pair(12, 32), Pair(-17, 40), Pair(-5, 48), Pair(70, 3), Pair(-54, 51), Pair(-40, 108), Pair(5, 56),
        Pair(-8, 47), Pair(-3, 49), Pair(-37, 53), Pair(64, 10), Pair(30, 40), Pair(71, 17), Pair(43, 59), Pair(-11, 35),
        Pair(39, 42), Pair(-21, 70), Pair(20, 64), Pair(31, 52), Pair(40, 57), Pair(-16, 65), Pair(-21, 121), Pair(-20, 48),
        Pair(4, 24), Pair(30, 23), Pair(-2, 35), Pair(-23, 43), Pair(42, 43), Pair(34, 62), Pair(0, 0), Pair(-23, 29),
        Pair(13, 19), Pair(14, 42), Pair(-7, 38), Pair(-6, 38), Pair(-28, 65), Pair(-40, -3), Pair(-24, 29), Pair(-61, 15),
        Pair(9, 25), Pair(-6, 23), Pair(1, 11), Pair(-6, 31), Pair(-7, 38), Pair(-6, 57), Pair(-11, 57), Pair(-31, -2),
        Pair(-5, 51), Pair(-11, 47), Pair(0, 33), Pair(-4, 51), Pair(-7, 43), Pair(4, 40), Pair(-13, 12), Pair(-15, 34)
      },
      { // Piece 4
        Pair(-6, 42), Pair(-155, 164), Pair(24, 19), Pair(34, 20), Pair(32, 17), Pair(137, -70), Pair(27, 40), Pair(162, -55),
        Pair(33, 38), Pair(47, 18), Pair(18, 61), Pair(92, -19), Pair(83, -20), Pair(0, 116), Pair(15, 120), Pair(28, 10),
        Pair(6, -16), Pair(-16, 127), Pair(26, 36), Pair(44, 69), Pair(-49, 50), Pair(49, -27), Pair(55, 32), Pair(-32, 127),
        Pair(39, -15), Pair(16, -19), Pair(45, 5), Pair(8, 65), Pair(-31, 159), Pair(0, 41), Pair(25, 19), Pair(-12, 79),
        Pair(4, 53), Pair(26, 36), Pair(0, 98), Pair(16, 71), Pair(18, 94), Pair(-7, 93), Pair(0, 0), Pair(27, 0),
        Pair(9, 20), Pair(-5, 92), Pair(6, 86), Pair(10, 28), Pair(12, 58), Pair(-35, -41), Pair(4, 130), Pair(-25, -2),
        Pair(-42, 118), Pair(-2, 45), Pair(-4, 79), Pair(-7, 55), Pair(4, 64), Pair(-14, 98), Pair(-48, 28), Pair(-57, 97),
        Pair(23, 29), Pair(-20, 48), Pair(9, -10), Pair(-3, 17), Pair(10, 86), Pair(-7, 37), Pair(17, 98), Pair(-26, 78)
      },
      { // Piece 5
        Pair(-5, 67), Pair(20, 1), Pair(26, -33), Pair(16, -100), Pair(101, 5), Pair(-10, -58), Pair(-67, -160), Pair(-8, -179),
        Pair(11, -35), Pair(62, -49), Pair(143, -33), Pair(-63, -20), Pair(44, -80), Pair(64, -31), Pair(37, -92), Pair(-62, 6),
        Pair(158, -68), Pair(-39, -31), Pair(-52, -7), Pair(18, -43), Pair(-58, -1), Pair(306, -69), Pair(272, -98), Pair(139, -76),
        Pair(-81, 23), Pair(136, -19), Pair(-21, -7), Pair(2, -8), Pair(-24, 18), Pair(139, -11), Pair(-20, 16), Pair(106, -43),
        Pair(-8, -34), Pair(-65, -4), Pair(64, -17), Pair(69, -18), Pair(126, -28), Pair(53, -9), Pair(0, 0), Pair(-41, 29),
        Pair(11, -5), Pair(-12, -16), Pair(0, -12), Pair(-34, 20), Pair(-21, 9), Pair(145, -13), Pair(-21, -2), Pair(8, 16),
        Pair(-29, -25), Pair(-19, -2), Pair(5, -15), Pair(-11, -7), Pair(-20, 5), Pair(13, 9), Pair(19, 8), Pair(53, -18),
        Pair(11, 15), Pair(-30, -8), Pair(-32, -14), Pair(12, 2), Pair(-29, 8), Pair(-14, 10), Pair(-12, 0), Pair(-13, 0)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(13, 10), Pair(66, -16), Pair(56, -21), Pair(-52, 23), Pair(55, -21), Pair(17, 3), Pair(-57, 8), Pair(216, -11),
        Pair(5, -4), Pair(25, -9), Pair(-8, 4), Pair(30, -5), Pair(27, -12), Pair(1, 0), Pair(-5, 17), Pair(-9, -5),
        Pair(-6, -5), Pair(10, -8), Pair(-7, 3), Pair(2, -2), Pair(9, -9), Pair(4, -8), Pair(-9, 3), Pair(0, 0),
        Pair(5, -18), Pair(-2, -10), Pair(-6, -11), Pair(-3, -3), Pair(3, -18), Pair(0, -5), Pair(8, -12), Pair(0, 0),
        Pair(-1, -16), Pair(0, -16), Pair(-4, -16), Pair(1, -8), Pair(3, -16), Pair(0, -4), Pair(-43, -7), Pair(15, 1),
        Pair(4, -14), Pair(-6, -13), Pair(-3, -18), Pair(-8, -14), Pair(-5, -11), Pair(-1, -3), Pair(-10, -23), Pair(1, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(170, 88), Pair(0, -73), Pair(57, -21), Pair(89, -36), Pair(-44, -6), Pair(-132, 2), Pair(-57, -9), Pair(-60, -46),
        Pair(45, -51), Pair(64, -4), Pair(67, -48), Pair(-29, -20), Pair(13, 4), Pair(-34, -21), Pair(-13, -5), Pair(7, -13),
        Pair(50, -94), Pair(69, -58), Pair(40, -48), Pair(81, -43), Pair(82, -36), Pair(20, -4), Pair(110, -12), Pair(-74, -4),
        Pair(-16, -36), Pair(19, -10), Pair(13, -18), Pair(35, -11), Pair(38, -4), Pair(15, -37), Pair(29, 8), Pair(5, 13),
        Pair(25, -72), Pair(-1, -21), Pair(13, -27), Pair(38, -28), Pair(-1, -6), Pair(30, -7), Pair(26, -20), Pair(0, 0),
        Pair(-9, -59), Pair(25, -37), Pair(15, -14), Pair(5, -6), Pair(6, -3), Pair(23, 8), Pair(-36, -65), Pair(34, 8),
        Pair(-36, 7), Pair(11, -32), Pair(14, -52), Pair(8, -18), Pair(12, -24), Pair(10, 0), Pair(17, 8), Pair(-26, 16),
        Pair(90, -208), Pair(4, -21), Pair(2, -64), Pair(-5, -13), Pair(42, -35), Pair(24, -40), Pair(14, -7), Pair(63, -178)
      },
      { // Piece 2
        Pair(92, -5), Pair(-93, 64), Pair(-144, 102), Pair(-116, 77), Pair(-90, 54), Pair(175, 5), Pair(4, 38), Pair(-6, -9),
        Pair(-114, 48), Pair(-25, 34), Pair(-32, 54), Pair(-78, 81), Pair(-75, 73), Pair(-56, 37), Pair(-46, 13), Pair(-8, -15),
        Pair(41, -6), Pair(20, 26), Pair(37, 36), Pair(-53, 62), Pair(-66, 64), Pair(-110, 86), Pair(-28, 50), Pair(1, 29),
        Pair(20, 47), Pair(15, 25), Pair(13, 12), Pair(32, -5), Pair(19, 25), Pair(15, 59), Pair(3, 55), Pair(8, 27),
        Pair(-2, 8), Pair(30, 30), Pair(34, -5), Pair(33, 15), Pair(13, 8), Pair(6, 18), Pair(6, 53), Pair(0, 0),
        Pair(-19, 39), Pair(24, 6), Pair(-1, 9), Pair(8, 13), Pair(8, 29), Pair(15, 13), Pair(-55, -43), Pair(35, 81),
        Pair(16, 38), Pair(5, 9), Pair(-2, -2), Pair(3, 44), Pair(1, 12), Pair(-26, 34), Pair(8, 21), Pair(62, -4),
        Pair(-10, -59), Pair(2, 29), Pair(-1, 53), Pair(-10, 19), Pair(-2, 38), Pair(3, 34), Pair(37, 0), Pair(17, 55)
      },
      { // Piece 3
        Pair(-19, 37), Pair(13, 24), Pair(-31, 27), Pair(42, 37), Pair(-102, 59), Pair(-74, 55), Pair(-4, 53), Pair(-13, 67),
        Pair(62, -6), Pair(65, -7), Pair(45, -1), Pair(85, -30), Pair(44, -10), Pair(51, 6), Pair(26, 32), Pair(128, 20),
        Pair(45, 21), Pair(9, 4), Pair(40, -1), Pair(-18, 25), Pair(-5, 18), Pair(62, 2), Pair(41, -3), Pair(108, 48),
        Pair(0, 25), Pair(22, 17), Pair(10, 29), Pair(63, -2), Pair(64, -2), Pair(56, 21), Pair(0, 41), Pair(79, 54),
        Pair(41, 24), Pair(35, -2), Pair(49, 14), Pair(40, 14), Pair(54, 1), Pair(46, 7), Pair(12, 38), Pair(0, 0),
        Pair(75, 5), Pair(39, 6), Pair(-21, 15), Pair(16, 4), Pair(22, 8), Pair(37, 37), Pair(-70, 57), Pair(-13, 46),
        Pair(2, -4), Pair(37, -5), Pair(38, -17), Pair(22, -8), Pair(-16, -1), Pair(14, -20), Pair(-27, 37), Pair(-66, 12),
        Pair(27, 18), Pair(21, 6), Pair(24, 30), Pair(18, 23), Pair(42, 13), Pair(26, 17), Pair(-1, 46), Pair(-20, 21)
      },
      { // Piece 4
        Pair(34, 22), Pair(0, 4), Pair(-61, 83), Pair(36, 21), Pair(-49, 49), Pair(-58, 49), Pair(43, 28), Pair(62, -5),
        Pair(10, 50), Pair(14, 50), Pair(28, 47), Pair(-25, 90), Pair(58, 11), Pair(62, 10), Pair(85, 31), Pair(55, 12),
        Pair(13, 100), Pair(104, -46), Pair(39, 67), Pair(-11, -6), Pair(17, 18), Pair(4, 102), Pair(3, -38), Pair(17, 75),
        Pair(1, 62), Pair(12, 27), Pair(-15, 106), Pair(20, 46), Pair(84, -5), Pair(46, 67), Pair(17, 78), Pair(36, 65),
        Pair(37, 81), Pair(45, -20), Pair(38, 15), Pair(13, 72), Pair(13, 43), Pair(-9, 56), Pair(31, 31), Pair(0, 0),
        Pair(5, -4), Pair(3, 59), Pair(8, 55), Pair(-5, 58), Pair(0, 69), Pair(3, 75), Pair(-50, -13), Pair(-14, -12),
        Pair(-21, 122), Pair(11, 62), Pair(16, 19), Pair(-8, 84), Pair(6, 53), Pair(-14, 66), Pair(-1, 95), Pair(-21, -2),
        Pair(-23, 151), Pair(33, -7), Pair(-17, 160), Pair(16, -6), Pair(-21, 118), Pair(-12, 101), Pair(-12, -25), Pair(106, 40)
      },
      { // Piece 5
        Pair(19, -33), Pair(-42, -89), Pair(86, -96), Pair(74, -43), Pair(152, -90), Pair(60, -42), Pair(-39, -113), Pair(-8, -127),
        Pair(125, -2), Pair(-157, -82), Pair(-23, -23), Pair(40, -64), Pair(-5, -69), Pair(40, -111), Pair(61, -36), Pair(16, -97),
        Pair(125, -65), Pair(-134, 19), Pair(98, -94), Pair(142, -90), Pair(218, -79), Pair(198, -91), Pair(60, -28), Pair(149, -59),
        Pair(-78, 4), Pair(-23, -15), Pair(-40, -24), Pair(138, -21), Pair(99, -23), Pair(-17, 5), Pair(59, -23), Pair(83, 18),
        Pair(27, -15), Pair(-64, -4), Pair(118, -45), Pair(-17, -1), Pair(62, -1), Pair(31, 4), Pair(-119, 3), Pair(0, 0),
        Pair(-120, 49), Pair(128, -59), Pair(33, -28), Pair(-13, 10), Pair(7, 5), Pair(-49, 47), Pair(-25, -9), Pair(17, -17),
        Pair(28, -28), Pair(-5, -30), Pair(-28, -16), Pair(-39, 6), Pair(-33, 17), Pair(-56, 40), Pair(27, 36), Pair(44, 10),
        Pair(-16, -2), Pair(0, 1), Pair(-2, -40), Pair(-8, -37), Pair(-21, 22), Pair(-33, 45), Pair(-6, 38), Pair(-1, 24)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-108, 41), Pair(0, 30), Pair(9, 27), Pair(-10, 24), Pair(21, 25), Pair(-12, 39), Pair(9, 32), Pair(-20, 24),
        Pair(34, 0), Pair(-14, 5), Pair(9, 3), Pair(-9, 7), Pair(6, 6), Pair(10, 10), Pair(10, 8), Pair(-9, 18),
        Pair(0, 0), Pair(-12, 1), Pair(3, -4), Pair(-1, 2), Pair(6, 4), Pair(-18, 7), Pair(1, 4), Pair(-5, 17),
        Pair(0, 0), Pair(-25, 2), Pair(0, -4), Pair(-4, 0), Pair(0, 2), Pair(-4, 7), Pair(-6, 5), Pair(-3, 3),
        Pair(4, 6), Pair(-11, -3), Pair(3, -4), Pair(-4, 4), Pair(-5, 0), Pair(-2, -1), Pair(-12, 3), Pair(-7, -3),
        Pair(12, -1), Pair(-9, -3), Pair(8, -3), Pair(-5, -1), Pair(-1, 0), Pair(-6, -4), Pair(-6, 0), Pair(0, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-53, 99), Pair(-15, 46), Pair(3, 83), Pair(-16, 80), Pair(-41, 80), Pair(54, 21), Pair(-66, 47), Pair(-35, 151),
        Pair(14, 53), Pair(19, 41), Pair(4, 38), Pair(116, 10), Pair(48, 52), Pair(78, 42), Pair(72, 20), Pair(51, 43),
        Pair(27, 4), Pair(-46, 87), Pair(-27, 67), Pair(3, 64), Pair(62, 51), Pair(29, 41), Pair(31, 45), Pair(25, 41),
        Pair(0, 0), Pair(20, 67), Pair(12, 60), Pair(36, 29), Pair(31, 45), Pair(3, 36), Pair(9, 42), Pair(30, 20),
        Pair(0, 67), Pair(-27, -44), Pair(2, 62), Pair(6, 47), Pair(19, 53), Pair(14, 34), Pair(9, 56), Pair(16, 12),
        Pair(11, 76), Pair(-22, 76), Pair(10, 50), Pair(12, 46), Pair(2, 52), Pair(9, 30), Pair(17, 33), Pair(10, 32),
        Pair(-65, 9), Pair(-15, 45), Pair(-19, 48), Pair(-6, 74), Pair(3, 29), Pair(-8, 42), Pair(-3, 31), Pair(-25, 52),
        Pair(-73, 148), Pair(-4, 49), Pair(-9, 20), Pair(-11, 38), Pair(14, 19), Pair(-3, 65), Pair(0, 36), Pair(22, -15)
      },
      { // Piece 2
        Pair(-64, 50), Pair(-106, 138), Pair(-88, 100), Pair(-42, 165), Pair(-116, 150), Pair(-89, 111), Pair(-64, 145), Pair(147, -42),
        Pair(2, 74), Pair(-40, 88), Pair(6, 103), Pair(-72, 125), Pair(-68, 106), Pair(-25, 133), Pair(5, 89), Pair(-51, 115),
        Pair(7, 67), Pair(-23, 90), Pair(-24, 106), Pair(8, 77), Pair(-28, 102), Pair(24, 102), Pair(-4, 100), Pair(-30, 85),
        Pair(0, 0), Pair(-15, 98), Pair(5, 60), Pair(-17, 88), Pair(11, 92), Pair(15, 70), Pair(18, 70), Pair(-15, 79),
        Pair(-24, 131), Pair(-59, -26), Pair(-5, 80), Pair(3, 71), Pair(14, 67), Pair(20, 74), Pair(-32, 74), Pair(4, 58),
        Pair(8, 94), Pair(-34, 97), Pair(1, 84), Pair(5, 67), Pair(-2, 81), Pair(-2, 70), Pair(16, 82), Pair(3, 65),
        Pair(24, 62), Pair(3, 98), Pair(3, 88), Pair(2, 66), Pair(-13, 65), Pair(5, 77), Pair(-3, 64), Pair(9, 91),
        Pair(19, 68), Pair(18, 81), Pair(2, 87), Pair(-19, 68), Pair(7, 96), Pair(-2, 66), Pair(46, 48), Pair(-25, 19)
      },
      { // Piece 3
        Pair(-2, 131), Pair(-30, 172), Pair(-39, 141), Pair(12, 116), Pair(-74, 157), Pair(-87, 165), Pair(31, 126), Pair(46, 128),
        Pair(35, 137), Pair(25, 132), Pair(-15, 149), Pair(76, 101), Pair(-23, 149), Pair(-38, 148), Pair(67, 97), Pair(16, 106),
        Pair(16, 154), Pair(-30, 137), Pair(2, 153), Pair(-18, 137), Pair(60, 114), Pair(43, 84), Pair(7, 111), Pair(-26, 124),
        Pair(0, 0), Pair(1, 148), Pair(11, 143), Pair(-21, 135), Pair(-31, 129), Pair(-2, 113), Pair(56, 94), Pair(17, 114),
        Pair(-54, 137), Pair(-31, 66), Pair(-14, 137), Pair(-40, 132), Pair(-30, 137), Pair(-9, 108), Pair(21, 102), Pair(22, 89),
        Pair(-25, 100), Pair(-20, 149), Pair(5, 102), Pair(-4, 94), Pair(-1, 99), Pair(4, 90), Pair(34, 95), Pair(17, 105),
        Pair(-47, 96), Pair(-19, 125), Pair(-18, 118), Pair(-5, 81), Pair(-31, 87), Pair(4, 74), Pair(18, 116), Pair(3, 88),
        Pair(-27, 97), Pair(-27, 128), Pair(-27, 138), Pair(-10, 123), Pair(-13, 107), Pair(-16, 119), Pair(-4, 120), Pair(-7, 126)
      },
      { // Piece 4
        Pair(-34, 238), Pair(151, 158), Pair(77, 243), Pair(11, 254), Pair(34, 206), Pair(160, 137), Pair(75, 155), Pair(116, 147),
        Pair(123, 198), Pair(15, 216), Pair(52, 191), Pair(-10, 265), Pair(62, 182), Pair(27, 254), Pair(58, 200), Pair(54, 191),
        Pair(54, 211), Pair(49, 185), Pair(3, 257), Pair(22, 221), Pair(7, 229), Pair(16, 210), Pair(59, 225), Pair(86, 154),
        Pair(0, 0), Pair(39, 175), Pair(32, 233), Pair(16, 224), Pair(46, 249), Pair(31, 219), Pair(53, 228), Pair(50, 221),
        Pair(40, 200), Pair(36, -4), Pair(34, 219), Pair(40, 213), Pair(63, 164), Pair(28, 268), Pair(31, 257), Pair(45, 170),
        Pair(19, 294), Pair(32, 210), Pair(33, 207), Pair(23, 216), Pair(35, 174), Pair(37, 230), Pair(61, 139), Pair(46, 186),
        Pair(28, 174), Pair(33, 250), Pair(37, 216), Pair(31, 212), Pair(34, 208), Pair(21, 236), Pair(61, 200), Pair(27, 230),
        Pair(42, 201), Pair(34, 176), Pair(31, 193), Pair(22, 250), Pair(38, 177), Pair(2, 246), Pair(82, 124), Pair(-26, 243)
      },
      { // Piece 5
        Pair(-176, -49), Pair(-55, 11), Pair(-24, -61), Pair(14, 17), Pair(-45, 1), Pair(-37, -42), Pair(-40, -62), Pair(-21, 2),
        Pair(34, -40), Pair(-38, -3), Pair(123, -21), Pair(91, -2), Pair(128, -37), Pair(85, -48), Pair(-83, -27), Pair(-20, -33),
        Pair(-11, 20), Pair(169, -56), Pair(112, -19), Pair(131, 0), Pair(-6, 7), Pair(-71, 9), Pair(57, -69), Pair(139, -27),
        Pair(0, 0), Pair(-39, -17), Pair(-71, 33), Pair(-76, 30), Pair(-3, 5), Pair(-30, -2), Pair(16, -16), Pair(66, -15),
        Pair(-130, -16), Pair(47, -82), Pair(6, 8), Pair(55, 6), Pair(21, -1), Pair(23, -13), Pair(23, -3), Pair(27, -30),
        Pair(-59, 8), Pair(25, 1), Pair(-35, 10), Pair(-19, 9), Pair(-11, 1), Pair(-24, 2), Pair(31, -20), Pair(-33, 12),
        Pair(-19, -1), Pair(-47, 27), Pair(-2, 22), Pair(7, 11), Pair(2, -1), Pair(22, -24), Pair(6, -8), Pair(11, -15),
        Pair(-17, 61), Pair(2, 8), Pair(2, 12), Pair(-12, 27), Pair(13, -8), Pair(22, -25), Pair(10, -15), Pair(17, -30)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-35, 16), Pair(-13, 12), Pair(-13, -5), Pair(-47, 40), Pair(1, 40), Pair(-7, 21), Pair(55, -10), Pair(24, 6),
        Pair(6, 6), Pair(-2, -49), Pair(-7, 6), Pair(13, 9), Pair(-5, 10), Pair(12, 12), Pair(0, 7), Pair(-7, 12),
        Pair(11, 3), Pair(0, 0), Pair(4, 3), Pair(-1, -1), Pair(6, 8), Pair(3, 21), Pair(-1, 10), Pair(4, 10),
        Pair(26, 1), Pair(0, 0), Pair(6, 5), Pair(-1, -2), Pair(-1, -3), Pair(-10, 11), Pair(4, 5), Pair(5, 4),
        Pair(10, -5), Pair(1, 5), Pair(-5, 15), Pair(-4, -2), Pair(-3, -1), Pair(-3, 2), Pair(-6, -2), Pair(-1, -4),
        Pair(6, 0), Pair(11, 5), Pair(-3, -2), Pair(1, -5), Pair(-5, 6), Pair(-9, -4), Pair(-5, 2), Pair(-2, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-62, 51), Pair(5, 41), Pair(-130, 67), Pair(60, 44), Pair(8, 80), Pair(1, 42), Pair(12, 33), Pair(77, 65),
        Pair(-112, 141), Pair(6, 84), Pair(-54, 113), Pair(89, 5), Pair(-54, 99), Pair(88, 18), Pair(-19, 89), Pair(-43, 110),
        Pair(103, 67), Pair(-31, 48), Pair(-36, 103), Pair(26, 47), Pair(45, 64), Pair(84, 28), Pair(-7, 51), Pair(36, 51),
        Pair(24, 33), Pair(0, 0), Pair(29, 65), Pair(-3, 83), Pair(23, 31), Pair(13, 77), Pair(20, 56), Pair(20, 33),
        Pair(-44, 35), Pair(50, 108), Pair(-49, -33), Pair(12, 53), Pair(23, 46), Pair(25, 57), Pair(33, 30), Pair(33, 42),
        Pair(-13, 47), Pair(8, 75), Pair(-8, 55), Pair(-15, 94), Pair(22, 26), Pair(5, 62), Pair(25, 49), Pair(9, 54),
        Pair(8, 164), Pair(-22, 77), Pair(15, 55), Pair(14, 39), Pair(1, 80), Pair(16, 79), Pair(35, 12), Pair(-19, 44),
        Pair(-7, 14), Pair(0, 49), Pair(8, 87), Pair(13, 65), Pair(15, 48), Pair(-7, 49), Pair(-1, 69), Pair(29, 83)
      },
      { // Piece 2
        Pair(87, 12), Pair(-48, 100), Pair(13, 120), Pair(129, 77), Pair(-167, 155), Pair(-34, 144), Pair(-197, 101), Pair(12, 131),
        Pair(31, 62), Pair(11, 94), Pair(16, 52), Pair(-149, 164), Pair(-89, 156), Pair(-109, 133), Pair(23, 110), Pair(37, 101),
        Pair(-194, 105), Pair(22, 58), Pair(22, 93), Pair(-23, 132), Pair(2, 106), Pair(9, 119), Pair(-23, 117), Pair(31, 51),
        Pair(12, 89), Pair(0, 0), Pair(-11, 123), Pair(18, 79), Pair(16, 91), Pair(7, 104), Pair(12, 83), Pair(18, 110),
        Pair(-59, 25), Pair(-8, 130), Pair(-26, 82), Pair(-25, 85), Pair(-23, 94), Pair(8, 79), Pair(-1, 85), Pair(-3, 81),
        Pair(-24, 120), Pair(1, 115), Pair(-31, 95), Pair(6, 62), Pair(0, 74), Pair(1, 83), Pair(13, 57), Pair(11, 76),
        Pair(32, 62), Pair(9, 92), Pair(0, 71), Pair(-1, 85), Pair(-7, 82), Pair(-19, 62), Pair(4, 71), Pair(-46, 122),
        Pair(-21, 119), Pair(33, 64), Pair(0, 77), Pair(5, 77), Pair(-7, 63), Pair(-5, 80), Pair(-62, 50), Pair(-20, 88)
      },
      { // Piece 3
        Pair(-10, 123), Pair(3, 123), Pair(-34, 132), Pair(-26, 145), Pair(-25, 141), Pair(-27, 147), Pair(-48, 142), Pair(144, 74),
        Pair(-6, 124), Pair(55, 127), Pair(-7, 147), Pair(3, 130), Pair(17, 124), Pair(-19, 138), Pair(-10, 108), Pair(18, 111),
        Pair(47, 109), Pair(-47, 188), Pair(10, 118), Pair(-18, 152), Pair(-40, 156), Pair(7, 129), Pair(-48, 121), Pair(97, 67),
        Pair(-43, 115), Pair(0, 0), Pair(1, 129), Pair(-11, 129), Pair(-16, 130), Pair(12, 119), Pair(16, 90), Pair(29, 83),
        Pair(38, 9), Pair(6, 108), Pair(13, 40), Pair(-30, 134), Pair(-5, 90), Pair(-8, 125), Pair(20, 86), Pair(2, 115),
        Pair(-2, 119), Pair(-11, 101), Pair(-23, 108), Pair(-26, 130), Pair(20, 78), Pair(22, 89), Pair(24, 78), Pair(9, 90),
        Pair(-21, 128), Pair(1, 86), Pair(-10, 106), Pair(-1, 103), Pair(-18, 104), Pair(-12, 101), Pair(4, 109), Pair(17, 95),
        Pair(-3, 106), Pair(-3, 101), Pair(-20, 131), Pair(15, 112), Pair(6, 108), Pair(-4, 128), Pair(6, 102), Pair(7, 113)
      },
      { // Piece 4
        Pair(-26, 197), Pair(106, 91), Pair(-59, 243), Pair(117, 189), Pair(-22, 193), Pair(58, 172), Pair(-28, 226), Pair(-4, 213),
        Pair(44, 168), Pair(35, 158), Pair(30, 228), Pair(89, 112), Pair(15, 261), Pair(7, 211), Pair(2, 190), Pair(99, 153),
        Pair(56, 201), Pair(64, 127), Pair(41, 205), Pair(84, 167), Pair(44, 216), Pair(98, 153), Pair(20, 199), Pair(57, 78),
        Pair(15, 167), Pair(0, 0), Pair(-3, 201), Pair(21, 215), Pair(74, 127), Pair(60, 210), Pair(42, 216), Pair(45, 212),
        Pair(22, 132), Pair(45, 169), Pair(-5, 113), Pair(27, 195), Pair(9, 219), Pair(48, 128), Pair(19, 193), Pair(16, 231),
        Pair(3, 252), Pair(19, 143), Pair(6, 208), Pair(42, 172), Pair(37, 160), Pair(29, 171), Pair(58, 138), Pair(42, 183),
        Pair(22, 186), Pair(40, 144), Pair(33, 155), Pair(31, 194), Pair(35, 160), Pair(52, 139), Pair(33, 153), Pair(38, 189),
        Pair(56, 162), Pair(34, 166), Pair(23, 199), Pair(27, 174), Pair(55, 170), Pair(11, 195), Pair(74, 138), Pair(12, 274)
      },
      { // Piece 5
        Pair(14, -25), Pair(122, 45), Pair(69, -3), Pair(112, 29), Pair(10, 38), Pair(-83, 5), Pair(-29, -5), Pair(-16, -32),
        Pair(-50, -61), Pair(14, -47), Pair(-58, -3), Pair(86, -28), Pair(50, -15), Pair(-82, 11), Pair(-13, -12), Pair(-44, -32),
        Pair(76, -38), Pair(3, -24), Pair(160, -37), Pair(111, -31), Pair(94, 8), Pair(17, -9), Pair(-120, -10), Pair(82, -40),
        Pair(-69, -51), Pair(0, 0), Pair(13, -32), Pair(-21, 9), Pair(60, 2), Pair(-41, 6), Pair(-83, 37), Pair(-20, -21),
        Pair(-17, -2), Pair(-1, -49), Pair(-23, 30), Pair(-80, 19), Pair(3, 6), Pair(27, -2), Pair(25, -13), Pair(59, -30),
        Pair(54, -60), Pair(-68, -1), Pair(54, -11), Pair(-32, -1), Pair(37, -2), Pair(59, -13), Pair(-23, 4), Pair(34, -20),
        Pair(-9, 13), Pair(-30, 1), Pair(-10, 7), Pair(-5, 15), Pair(10, -3), Pair(17, -6), Pair(4, -5), Pair(16, -12),
        Pair(4, -24), Pair(-3, -11), Pair(-17, 1), Pair(-2, 1), Pair(12, 7), Pair(20, -16), Pair(14, -18), Pair(36, -16)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(18, 10), Pair(-39, 16), Pair(-35, 53), Pair(13, -3), Pair(-28, 12), Pair(-16, 39), Pair(-22, 47), Pair(33, 23),
        Pair(-10, 1), Pair(4, -3), Pair(-6, 31), Pair(0, 15), Pair(0, 11), Pair(2, 14), Pair(7, 20), Pair(9, 13),
        Pair(-4, 5), Pair(9, -11), Pair(0, 0), Pair(7, 6), Pair(-2, 5), Pair(3, 6), Pair(3, 8), Pair(6, 12),
        Pair(-1, 0), Pair(-5, -5), Pair(0, 0), Pair(-18, 16), Pair(-2, 0), Pair(-1, 7), Pair(-1, 7), Pair(4, 7),
        Pair(-1, -1), Pair(2, -12), Pair(1, 4), Pair(-8, -1), Pair(-5, -7), Pair(-3, 2), Pair(-7, 5), Pair(2, -2),
        Pair(-2, 0), Pair(-3, -13), Pair(7, 4), Pair(-12, 3), Pair(-4, 0), Pair(-9, -5), Pair(-4, -7), Pair(1, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(12, -3), Pair(121, -9), Pair(149, 33), Pair(30, 40), Pair(13, 91), Pair(23, 67), Pair(22, 14), Pair(86, -3),
        Pair(25, 37), Pair(-55, 55), Pair(86, 25), Pair(51, 11), Pair(23, 47), Pair(34, 79), Pair(-46, 51), Pair(-35, 83),
        Pair(-72, 93), Pair(-15, 119), Pair(-17, 84), Pair(15, 88), Pair(10, 56), Pair(-4, 61), Pair(5, 45), Pair(-30, 80),
        Pair(6, 72), Pair(-7, 80), Pair(0, 0), Pair(35, 60), Pair(9, 80), Pair(-20, 73), Pair(0, 67), Pair(27, 34),
        Pair(9, 45), Pair(-46, 14), Pair(18, 101), Pair(-49, -22), Pair(-2, 67), Pair(5, 55), Pair(8, 54), Pair(8, 55),
        Pair(6, 68), Pair(-30, 21), Pair(-2, 94), Pair(-3, 54), Pair(6, 81), Pair(-4, 57), Pair(8, 80), Pair(13, 70),
        Pair(-24, 42), Pair(48, 30), Pair(-3, 43), Pair(3, 88), Pair(-14, 50), Pair(-1, 90), Pair(-12, 71), Pair(-29, 56),
        Pair(47, 53), Pair(2, 83), Pair(-33, 15), Pair(5, 109), Pair(10, 54), Pair(-1, 68), Pair(-7, 66), Pair(13, 63)
      },
      { // Piece 2
        Pair(10, 80), Pair(19, 86), Pair(-47, 87), Pair(-203, 110), Pair(7, 82), Pair(-64, 127), Pair(-30, 122), Pair(17, 57),
        Pair(36, 42), Pair(-28, 67), Pair(11, 74), Pair(-81, 96), Pair(-108, 128), Pair(16, 95), Pair(-6, 76), Pair(58, 63),
        Pair(-16, 94), Pair(-63, 42), Pair(25, 61), Pair(6, 77), Pair(-11, 96), Pair(13, 89), Pair(-4, 86), Pair(-10, 50),
        Pair(-14, 86), Pair(-9, 91), Pair(0, 0), Pair(22, 75), Pair(-6, 70), Pair(-16, 78), Pair(-2, 75), Pair(20, 80),
        Pair(2, 68), Pair(-92, -8), Pair(7, 122), Pair(-76, 11), Pair(1, 77), Pair(6, 56), Pair(-10, 83), Pair(10, 77),
        Pair(-15, 12), Pair(-24, 50), Pair(-15, 71), Pair(-12, 81), Pair(-21, 49), Pair(-2, 70), Pair(23, 76), Pair(-2, 94),
        Pair(-69, 143), Pair(-9, 60), Pair(-11, 94), Pair(0, 59), Pair(-17, 78), Pair(-11, 48), Pair(-1, 80), Pair(1, 42),
        Pair(-1, 62), Pair(-20, 77), Pair(1, 69), Pair(4, 64), Pair(14, 53), Pair(-5, 71), Pair(-75, 79), Pair(7, 56)
      },
      { // Piece 3
        Pair(-2, 143), Pair(-10, 147), Pair(14, 123), Pair(-55, 125), Pair(53, 106), Pair(-90, 150), Pair(33, 99), Pair(-13, 120),
        Pair(24, 109), Pair(-22, 129), Pair(32, 116), Pair(70, 104), Pair(59, 93), Pair(46, 87), Pair(1, 115), Pair(42, 83),
        Pair(26, 96), Pair(47, 76), Pair(36, 119), Pair(7, 111), Pair(3, 118), Pair(22, 97), Pair(49, 72), Pair(5, 90),
        Pair(2, 95), Pair(-37, 92), Pair(0, 0), Pair(-5, 111), Pair(45, 85), Pair(23, 89), Pair(29, 82), Pair(-4, 98),
        Pair(0, 90), Pair(-29, 46), Pair(-55, 101), Pair(-5, -11), Pair(-2, 110), Pair(-38, 116), Pair(7, 80), Pair(-8, 108),
        Pair(1, 102), Pair(-15, 98), Pair(-27, 50), Pair(-33, 107), Pair(-7, 88), Pair(11, 81), Pair(5, 113), Pair(-1, 85),
        Pair(-19, 82), Pair(-29, 119), Pair(-43, 88), Pair(-13, 88), Pair(24, 79), Pair(-3, 77), Pair(13, 88), Pair(-5, 90),
        Pair(-13, 107), Pair(-14, 100), Pair(-26, 76), Pair(3, 82), Pair(-10, 95), Pair(-4, 102), Pair(-3, 112), Pair(0, 96)
      },
      { // Piece 4
        Pair(41, 199), Pair(30, 152), Pair(90, 96), Pair(21, 194), Pair(44, 129), Pair(-14, 229), Pair(55, 130), Pair(36, 194),
        Pair(29, 117), Pair(16, 178), Pair(73, 187), Pair(35, 187), Pair(63, 126), Pair(18, 195), Pair(37, 154), Pair(14, 209),
        Pair(3, 177), Pair(-29, 172), Pair(28, 157), Pair(40, 178), Pair(-6, 166), Pair(56, 133), Pair(88, 99), Pair(59, 165),
        Pair(32, 78), Pair(22, 98), Pair(0, 0), Pair(18, 180), Pair(52, 120), Pair(16, 205), Pair(67, 95), Pair(31, 227),
        Pair(19, 159), Pair(85, -80), Pair(40, 78), Pair(-12, 60), Pair(17, 173), Pair(25, 160), Pair(26, 173), Pair(36, 168),
        Pair(13, 156), Pair(6, 153), Pair(33, 83), Pair(8, 162), Pair(23, 136), Pair(20, 152), Pair(11, 199), Pair(28, 142),
        Pair(12, 152), Pair(-3, 193), Pair(31, 135), Pair(13, 148), Pair(10, 207), Pair(23, 130), Pair(8, 215), Pair(33, 131),
        Pair(-8, 209), Pair(3, 118), Pair(13, 136), Pair(18, 172), Pair(14, 134), Pair(3, 180), Pair(42, 92), Pair(-4, 199)
      },
      { // Piece 5
        Pair(-11, -64), Pair(-5, -59), Pair(26, 18), Pair(0, -19), Pair(5, -10), Pair(91, -10), Pair(61, 18), Pair(21, 12),
        Pair(-93, -5), Pair(17, 12), Pair(-29, -10), Pair(-50, 0), Pair(-3, -52), Pair(-60, 71), Pair(88, 25), Pair(48, -13),
        Pair(10, -13), Pair(223, 3), Pair(127, -37), Pair(111, -60), Pair(-93, 32), Pair(-16, 15), Pair(37, -20), Pair(-150, 6),
        Pair(-128, 59), Pair(122, -53), Pair(0, 0), Pair(181, -71), Pair(26, -3), Pair(-55, 14), Pair(-30, 16), Pair(-7, -2),
        Pair(-71, 32), Pair(-77, -36), Pair(-93, -43), Pair(-57, -66), Pair(-37, 15), Pair(-15, 16), Pair(-92, 42), Pair(-91, 35),
        Pair(-158, 54), Pair(-12, 3), Pair(1, -22), Pair(57, -22), Pair(-19, 4), Pair(6, -1), Pair(-41, 15), Pair(-6, 24),
        Pair(-29, 11), Pair(6, -2), Pair(-12, -7), Pair(5, -10), Pair(-13, 22), Pair(9, -8), Pair(-11, 14), Pair(0, -3),
        Pair(-13, 16), Pair(-46, 15), Pair(-15, -2), Pair(18, -18), Pair(7, 24), Pair(13, -6), Pair(5, -1), Pair(-5, 5)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 22), Pair(2, 13), Pair(19, 1), Pair(-4, 21), Pair(-25, 33), Pair(-16, 27), Pair(-17, 62), Pair(-1, 23),
        Pair(1, 17), Pair(-8, 10), Pair(-20, 3), Pair(-10, -13), Pair(1, 3), Pair(-12, 20), Pair(-10, 24), Pair(-1, 7),
        Pair(-1, 11), Pair(6, 6), Pair(0, 5), Pair(0, 0), Pair(8, -6), Pair(2, 2), Pair(-4, 16), Pair(5, 3),
        Pair(3, -1), Pair(2, 1), Pair(17, -18), Pair(0, 0), Pair(-1, -2), Pair(-1, 4), Pair(6, 3), Pair(7, -3),
        Pair(1, -10), Pair(0, -3), Pair(1, -13), Pair(4, -11), Pair(-1, -2), Pair(-2, 1), Pair(-2, 1), Pair(0, -5),
        Pair(7, 1), Pair(1, -3), Pair(-3, -17), Pair(8, -1), Pair(-9, -3), Pair(-5, -2), Pair(-4, -4), Pair(5, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-1, 47), Pair(32, 84), Pair(-143, 60), Pair(-61, 84), Pair(-47, 30), Pair(50, 70), Pair(-24, 18), Pair(41, -2),
        Pair(1, 64), Pair(-6, 76), Pair(-45, 78), Pair(-31, 89), Pair(-65, 57), Pair(-9, 71), Pair(-52, 83), Pair(-60, 49),
        Pair(-73, 66), Pair(13, -19), Pair(-12, 96), Pair(-29, 54), Pair(-17, 87), Pair(-26, 57), Pair(15, 62), Pair(7, 10),
        Pair(-3, 46), Pair(-4, 61), Pair(1, 77), Pair(0, 0), Pair(2, 73), Pair(-6, 69), Pair(-11, 62), Pair(25, 55),
        Pair(-7, 74), Pair(11, 37), Pair(-22, -10), Pair(21, 90), Pair(-35, 12), Pair(-4, 66), Pair(15, 81), Pair(8, 54),
        Pair(-19, 41), Pair(-7, 75), Pair(-15, 22), Pair(13, 74), Pair(-19, 38), Pair(0, 73), Pair(10, 30), Pair(13, 56),
        Pair(-6, 49), Pair(15, 44), Pair(-7, 60), Pair(-13, 23), Pair(15, 62), Pair(1, 49), Pair(12, 63), Pair(4, 41),
        Pair(-70, 107), Pair(-8, 52), Pair(42, 19), Pair(-8, 49), Pair(-1, 76), Pair(-2, 40), Pair(16, 44), Pair(69, 74)
      },
      { // Piece 2
        Pair(-35, -16), Pair(-80, 82), Pair(6, 99), Pair(-64, 81), Pair(-111, 120), Pair(-87, 111), Pair(-91, 92), Pair(51, 100),
        Pair(36, 72), Pair(-8, 30), Pair(0, 46), Pair(-26, 101), Pair(-105, 106), Pair(-69, 101), Pair(50, 61), Pair(-75, 150),
        Pair(-35, 68), Pair(-8, 107), Pair(-56, 68), Pair(13, 63), Pair(33, 54), Pair(-18, 109), Pair(-50, 102), Pair(38, 36),
        Pair(16, 46), Pair(-23, 76), Pair(11, 99), Pair(0, 0), Pair(11, 76), Pair(-21, 80), Pair(6, 78), Pair(5, 34),
        Pair(-26, 50), Pair(-23, 90), Pair(-22, 9), Pair(14, 122), Pair(-68, -59), Pair(7, 75), Pair(8, 61), Pair(7, 58),
        Pair(4, 82), Pair(-35, 30), Pair(-9, 57), Pair(-12, 57), Pair(-7, 68), Pair(-31, 16), Pair(-20, 82), Pair(-11, 66),
        Pair(-9, -54), Pair(-7, 69), Pair(-24, 48), Pair(10, 56), Pair(-20, 42), Pair(5, 88), Pair(-23, 17), Pair(21, 85),
        Pair(-19, 29), Pair(-48, 59), Pair(9, 67), Pair(-22, 67), Pair(-3, 46), Pair(-15, 44), Pair(-50, 121), Pair(-22, 25)
      },
      { // Piece 3
        Pair(-11, 100), Pair(-3, 94), Pair(-35, 118), Pair(-16, 116), Pair(-101, 131), Pair(-8, 101), Pair(-74, 109), Pair(-33, 110),
        Pair(-10, 94), Pair(1, 102), Pair(13, 93), Pair(-14, 111), Pair(-4, 109), Pair(86, 67), Pair(-19, 117), Pair(49, 79),
        Pair(15, 86), Pair(-9, 90), Pair(-10, 91), Pair(24, 122), Pair(18, 105), Pair(43, 65), Pair(4, 77), Pair(13, 74),
        Pair(-5, 96), Pair(-5, 90), Pair(-16, 110), Pair(0, 0), Pair(21, 74), Pair(33, 60), Pair(51, 78), Pair(13, 76),
        Pair(2, 71), Pair(-22, 81), Pair(-68, 141), Pair(-4, 78), Pair(7, 6), Pair(-3, 87), Pair(5, 78), Pair(-2, 96),
        Pair(-9, 72), Pair(7, 98), Pair(-12, 83), Pair(-11, 83), Pair(-4, 97), Pair(-2, 108), Pair(7, 70), Pair(2, 100),
        Pair(4, 85), Pair(-28, 98), Pair(-5, 77), Pair(-28, 54), Pair(1, 78), Pair(-5, 81), Pair(5, 75), Pair(19, 70),
        Pair(-2, 95), Pair(-7, 88), Pair(-3, 77), Pair(-3, 66), Pair(-15, 89), Pair(0, 88), Pair(0, 94), Pair(13, 75)
      },
      { // Piece 4
        Pair(-39, 79), Pair(54, 145), Pair(36, 155), Pair(-65, 162), Pair(-18, 206), Pair(25, 221), Pair(62, 156), Pair(31, 174),
        Pair(1, 188), Pair(19, 158), Pair(54, 158), Pair(26, 165), Pair(-53, 250), Pair(32, 247), Pair(41, 199), Pair(32, 245),
        Pair(43, 121), Pair(39, 120), Pair(5, 162), Pair(19, 219), Pair(11, 139), Pair(4, 236), Pair(-3, 183), Pair(9, 188),
        Pair(8, 144), Pair(-4, 176), Pair(17, 134), Pair(0, 0), Pair(12, 210), Pair(64, 116), Pair(4, 209), Pair(17, 195),
        Pair(6, 163), Pair(36, 148), Pair(-16, -4), Pair(50, 129), Pair(-17, -121), Pair(17, 145), Pair(10, 197), Pair(11, 217),
        Pair(14, 204), Pair(6, 157), Pair(12, 159), Pair(15, 151), Pair(-6, 230), Pair(16, 153), Pair(27, 172), Pair(56, 95),
        Pair(9, 129), Pair(3, 159), Pair(10, 151), Pair(29, 145), Pair(8, 180), Pair(-6, 221), Pair(20, 98), Pair(28, 162),
        Pair(27, 169), Pair(30, 134), Pair(13, 151), Pair(31, 125), Pair(22, 141), Pair(-3, 198), Pair(32, 271), Pair(29, 6)
      },
      { // Piece 5
        Pair(66, 57), Pair(-22, -116), Pair(-125, -74), Pair(-21, 17), Pair(67, 56), Pair(149, -80), Pair(61, -59), Pair(128, 37),
        Pair(36, 77), Pair(-54, 12), Pair(-47, -45), Pair(71, -45), Pair(22, 4), Pair(-10, -56), Pair(215, -84), Pair(52, -56),
        Pair(-27, -9), Pair(-32, 19), Pair(100, -35), Pair(82, -15), Pair(-1, -20), Pair(163, -55), Pair(63, -7), Pair(35, 11),
        Pair(-91, 20), Pair(67, 8), Pair(88, -62), Pair(0, 0), Pair(70, -54), Pair(1, 8), Pair(30, 17), Pair(15, 5),
        Pair(-3, 35), Pair(-67, 51), Pair(-43, -7), Pair(-55, -45), Pair(17, 3), Pair(41, -3), Pair(13, 6), Pair(-17, 38),
        Pair(-93, 22), Pair(-40, 28), Pair(73, -24), Pair(18, -17), Pair(49, -24), Pair(-25, 13), Pair(-51, 18), Pair(-1, 1),
        Pair(-32, 32), Pair(-51, 36), Pair(13, -1), Pair(1, -12), Pair(4, -6), Pair(-12, 18), Pair(2, 17), Pair(10, 14),
        Pair(-26, 62), Pair(-16, 47), Pair(-27, 24), Pair(21, 0), Pair(-5, 5), Pair(-1, 5), Pair(-1, 21), Pair(16, 5)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(41, 9), Pair(39, -2), Pair(-43, 26), Pair(-37, 44), Pair(46, -8), Pair(17, -27), Pair(-13, 21), Pair(19, 4),
        Pair(3, -4), Pair(-7, 5), Pair(-21, 14), Pair(-6, 4), Pair(-12, 9), Pair(-8, 18), Pair(-5, 19), Pair(11, 8),
        Pair(0, 0), Pair(-3, 6), Pair(4, -2), Pair(7, -7), Pair(0, 0), Pair(5, 13), Pair(-1, 7), Pair(-4, 20),
        Pair(1, 0), Pair(0, 0), Pair(1, -5), Pair(1, 5), Pair(0, 0), Pair(5, -6), Pair(1, 7), Pair(2, 4),
        Pair(-2, -9), Pair(-2, -2), Pair(-5, 0), Pair(2, -8), Pair(2, -5), Pair(-7, -2), Pair(-6, 3), Pair(-1, -2),
        Pair(4, 1), Pair(-4, -11), Pair(-1, -3), Pair(-4, -11), Pair(6, -5), Pair(-9, -16), Pair(-2, 5), Pair(-3, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, 89), Pair(-94, 134), Pair(1, 50), Pair(-13, 26), Pair(12, 19), Pair(67, 56), Pair(-89, 82), Pair(62, 3),
        Pair(9, 41), Pair(19, 69), Pair(-70, 75), Pair(-18, 42), Pair(-40, 78), Pair(-70, 62), Pair(6, 72), Pair(-6, 89),
        Pair(41, 49), Pair(38, 36), Pair(-16, 46), Pair(14, 45), Pair(47, 9), Pair(-36, 67), Pair(-6, 14), Pair(47, 46),
        Pair(40, 11), Pair(-5, 41), Pair(15, 67), Pair(-8, 73), Pair(0, 0), Pair(-19, 73), Pair(-12, 38), Pair(-23, 35),
        Pair(12, 60), Pair(-42, 41), Pair(7, 42), Pair(-34, -20), Pair(20, 69), Pair(-33, -17), Pair(21, 52), Pair(-9, 39),
        Pair(10, 64), Pair(-16, 51), Pair(-6, 79), Pair(-23, 21), Pair(-16, 62), Pair(-23, 22), Pair(-4, 65), Pair(-21, 12),
        Pair(5, 39), Pair(6, 65), Pair(-2, 19), Pair(-1, 74), Pair(-16, 6), Pair(-3, 54), Pair(-37, 45), Pair(-23, 52),
        Pair(-22, 63), Pair(8, 88), Pair(-31, 14), Pair(-2, 66), Pair(-2, 56), Pair(-12, 80), Pair(-9, 30), Pair(36, 19)
      },
      { // Piece 2
        Pair(31, 100), Pair(-74, 98), Pair(-68, 97), Pair(-74, 88), Pair(-7, 65), Pair(-65, 80), Pair(-47, 59), Pair(-28, 25),
        Pair(12, 19), Pair(-43, 112), Pair(-61, 42), Pair(-20, 40), Pair(32, 60), Pair(-18, 94), Pair(4, 3), Pair(57, 86),
        Pair(-42, 80), Pair(-28, 41), Pair(-17, 72), Pair(-26, 61), Pair(-22, 45), Pair(-50, 52), Pair(-11, 101), Pair(2, 33),
        Pair(-53, 43), Pair(8, 50), Pair(-44, 44), Pair(-26, 70), Pair(0, 0), Pair(13, 79), Pair(-30, 65), Pair(11, 65),
        Pair(15, 46), Pair(-6, 36), Pair(0, 46), Pair(-80, -61), Pair(6, 87), Pair(-18, -65), Pair(-3, 59), Pair(-17, 65),
        Pair(-10, 23), Pair(1, 45), Pair(-27, 32), Pair(-4, 61), Pair(-13, 30), Pair(-26, 47), Pair(-28, 24), Pair(-15, 66),
        Pair(0, 29), Pair(-28, 18), Pair(10, 69), Pair(-20, 47), Pair(-5, 47), Pair(-17, 32), Pair(-12, 40), Pair(-20, -43),
        Pair(-60, 37), Pair(-23, 83), Pair(-12, 52), Pair(-6, 74), Pair(2, 17), Pair(-1, 44), Pair(-67, 39), Pair(5, 13)
      },
      { // Piece 3
        Pair(29, 76), Pair(-8, 88), Pair(43, 62), Pair(-79, 99), Pair(7, 69), Pair(2, 74), Pair(-20, 85), Pair(-61, 95),
        Pair(28, 69), Pair(7, 68), Pair(10, 63), Pair(-69, 104), Pair(1, 88), Pair(44, 48), Pair(-27, 68), Pair(-8, 60),
        Pair(52, 56), Pair(16, 67), Pair(1, 92), Pair(-37, 100), Pair(-57, 118), Pair(-8, 66), Pair(33, 61), Pair(10, 64),
        Pair(1, 60), Pair(21, 59), Pair(2, 51), Pair(6, 65), Pair(0, 0), Pair(-4, 58), Pair(1, 47), Pair(-15, 54),
        Pair(16, 56), Pair(8, 61), Pair(-13, 56), Pair(-3, -25), Pair(19, 25), Pair(13, -32), Pair(-6, 58), Pair(7, 40),
        Pair(7, 77), Pair(27, 43), Pair(13, 66), Pair(-25, 72), Pair(-41, 59), Pair(-12, 57), Pair(-29, 79), Pair(13, 48),
        Pair(18, 35), Pair(-6, 57), Pair(25, 56), Pair(3, 58), Pair(-12, 58), Pair(-7, 55), Pair(-23, 77), Pair(8, 53),
        Pair(14, 54), Pair(11, 54), Pair(7, 65), Pair(2, 44), Pair(-12, 46), Pair(5, 50), Pair(16, 57), Pair(7, 50)
      },
      { // Piece 4
        Pair(38, 115), Pair(46, 103), Pair(47, 154), Pair(83, 165), Pair(17, 185), Pair(138, 45), Pair(-93, 298), Pair(93, 89),
        Pair(46, 143), Pair(9, 196), Pair(54, 124), Pair(-8, 215), Pair(106, 97), Pair(24, 184), Pair(60, 175), Pair(34, 184),
        Pair(28, 173), Pair(-2, 213), Pair(30, 89), Pair(3, 168), Pair(39, 148), Pair(-8, 153), Pair(18, 174), Pair(35, 141),
        Pair(0, 165), Pair(24, 142), Pair(41, 120), Pair(9, 167), Pair(0, 0), Pair(30, 132), Pair(28, 182), Pair(27, 130),
        Pair(18, 153), Pair(25, 211), Pair(12, 122), Pair(7, 26), Pair(71, 47), Pair(-28, 99), Pair(9, 137), Pair(8, 152),
        Pair(23, 157), Pair(16, 198), Pair(29, 83), Pair(-3, 111), Pair(14, 110), Pair(14, 137), Pair(-3, 169), Pair(-7, 221),
        Pair(-5, 205), Pair(22, 171), Pair(24, 148), Pair(7, 136), Pair(36, 135), Pair(-1, 185), Pair(22, 163), Pair(-17, 96),
        Pair(-22, 211), Pair(20, 97), Pair(13, 127), Pair(20, 120), Pair(23, 149), Pair(47, 165), Pair(27, 149), Pair(81, 34)
      },
      { // Piece 5
        Pair(-128, -89), Pair(-72, -4), Pair(-42, -135), Pair(-33, 14), Pair(41, -7), Pair(-10, -72), Pair(-5, -104), Pair(-12, -69),
        Pair(-11, 83), Pair(-19, -28), Pair(17, -8), Pair(-23, -49), Pair(52, -71), Pair(-39, -19), Pair(-25, 4), Pair(95, -20),
        Pair(52, -3), Pair(144, -6), Pair(-15, -7), Pair(73, -49), Pair(151, -75), Pair(286, -27), Pair(-70, -8), Pair(-41, 60),
        Pair(139, 29), Pair(-83, 51), Pair(-49, 14), Pair(51, -46), Pair(0, 0), Pair(74, -34), Pair(68, 1), Pair(164, -40),
        Pair(15, 7), Pair(19, 3), Pair(46, -12), Pair(76, -67), Pair(-60, -36), Pair(10, -47), Pair(-16, 10), Pair(-54, 34),
        Pair(-18, 9), Pair(-49, 39), Pair(46, -8), Pair(35, -10), Pair(29, -20), Pair(76, -35), Pair(-44, 25), Pair(-21, 10),
        Pair(29, -26), Pair(-16, 19), Pair(2, 23), Pair(10, -3), Pair(35, -14), Pair(14, -7), Pair(-2, 22), Pair(13, 10),
        Pair(-15, 8), Pair(-10, 45), Pair(-5, 33), Pair(24, -6), Pair(2, 18), Pair(4, 11), Pair(-4, 31), Pair(-2, 37)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(20, 6), Pair(29, -5), Pair(-22, 27), Pair(-20, 16), Pair(-46, -5), Pair(1, 21), Pair(-37, 7), Pair(-11, 13),
        Pair(12, -1), Pair(34, -21), Pair(-6, 14), Pair(-14, 5), Pair(-15, -7), Pair(-57, 23), Pair(-11, 17), Pair(-8, 7),
        Pair(4, -3), Pair(12, -8), Pair(4, -4), Pair(-4, -5), Pair(8, 0), Pair(0, 0), Pair(-2, 2), Pair(0, 4),
        Pair(7, -3), Pair(8, -10), Pair(2, -7), Pair(1, -6), Pair(-6, 4), Pair(0, 0), Pair(-6, -3), Pair(3, -4),
        Pair(3, -7), Pair(10, -10), Pair(-1, -9), Pair(5, -11), Pair(-3, -2), Pair(2, -1), Pair(-10, -10), Pair(0, -9),
        Pair(1, -11), Pair(1, -11), Pair(1, -7), Pair(1, -11), Pair(-11, -9), Pair(8, -10), Pair(-7, -12), Pair(-1, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-30, 82), Pair(121, 41), Pair(38, 19), Pair(63, 53), Pair(84, 14), Pair(-49, 82), Pair(29, 28), Pair(71, -30),
        Pair(49, 35), Pair(39, 28), Pair(1, 48), Pair(46, 16), Pair(47, 4), Pair(24, 61), Pair(27, 39), Pair(1, 50),
        Pair(-19, 46), Pair(55, 36), Pair(-14, 80), Pair(6, 11), Pair(-14, 76), Pair(11, 22), Pair(39, 65), Pair(-21, -9),
        Pair(1, 41), Pair(14, 60), Pair(-1, 43), Pair(17, 36), Pair(19, 50), Pair(0, 0), Pair(-27, 74), Pair(4, 78),
        Pair(30, 23), Pair(6, 36), Pair(-10, 39), Pair(9, 30), Pair(-65, -2), Pair(29, 59), Pair(-62, -7), Pair(-22, 49),
        Pair(2, 52), Pair(-3, 54), Pair(7, 25), Pair(-1, 64), Pair(-8, 28), Pair(-4, 55), Pair(-25, 3), Pair(12, 64),
        Pair(13, 32), Pair(-7, 36), Pair(9, 37), Pair(-12, 43), Pair(10, 53), Pair(-17, 24), Pair(23, 77), Pair(-35, 38),
        Pair(-46, 76), Pair(-2, 40), Pair(-24, 31), Pair(-6, 49), Pair(20, 69), Pair(8, 10), Pair(7, 52), Pair(-30, 35)
      },
      { // Piece 2
        Pair(-48, 35), Pair(-75, 67), Pair(-127, 70), Pair(-112, 69), Pair(-60, 69), Pair(-167, 90), Pair(-87, 37), Pair(-30, 23),
        Pair(4, 41), Pair(-84, 72), Pair(-28, 73), Pair(30, 45), Pair(-87, 45), Pair(-21, 49), Pair(27, 21), Pair(-134, -17),
        Pair(-36, 42), Pair(-35, 69), Pair(-74, 78), Pair(-41, 75), Pair(-23, 65), Pair(39, 38), Pair(-44, 15), Pair(-20, 70),
        Pair(62, 20), Pair(-10, 63), Pair(-2, 50), Pair(-39, 47), Pair(-12, 50), Pair(0, 0), Pair(2, 75), Pair(-35, 40),
        Pair(-3, 62), Pair(4, 60), Pair(-9, 53), Pair(12, 50), Pair(-73, -26), Pair(21, 85), Pair(-66, -46), Pair(-27, 81),
        Pair(10, 34), Pair(-9, 61), Pair(18, 44), Pair(-29, 33), Pair(-6, 40), Pair(-16, 44), Pair(-19, 49), Pair(-37, 9),
        Pair(-40, 69), Pair(8, 33), Pair(-34, 24), Pair(6, 66), Pair(-20, 40), Pair(27, 40), Pair(-25, 24), Pair(-21, 4),
        Pair(-34, 53), Pair(-12, 18), Pair(15, 62), Pair(4, 45), Pair(-37, 82), Pair(-15, 36), Pair(-25, 70), Pair(-9, 37)
      },
      { // Piece 3
        Pair(25, 59), Pair(-54, 100), Pair(-26, 78), Pair(45, 48), Pair(3, 76), Pair(-32, 88), Pair(-6, 96), Pair(-33, 87),
        Pair(20, 55), Pair(-3, 66), Pair(24, 49), Pair(40, 52), Pair(60, 49), Pair(44, 57), Pair(34, 43), Pair(81, 33),
        Pair(47, 42), Pair(6, 57), Pair(10, 53), Pair(53, 46), Pair(-15, 77), Pair(-37, 98), Pair(-20, 32), Pair(41, 47),
        Pair(42, 28), Pair(6, 44), Pair(-5, 64), Pair(51, 36), Pair(31, 52), Pair(0, 0), Pair(-11, 50), Pair(6, 49),
        Pair(0, 62), Pair(12, 48), Pair(-3, 49), Pair(-9, 53), Pair(-31, -53), Pair(26, 33), Pair(38, -78), Pair(14, 35),
        Pair(12, 60), Pair(9, 45), Pair(48, 9), Pair(-2, 52), Pair(0, 33), Pair(1, 53), Pair(8, 24), Pair(22, 31),
        Pair(24, 33), Pair(-2, 62), Pair(33, 13), Pair(33, 27), Pair(8, 29), Pair(-10, 39), Pair(29, 16), Pair(9, 33),
        Pair(18, 54), Pair(16, 48), Pair(14, 50), Pair(18, 45), Pair(-2, 50), Pair(5, 40), Pair(12, 35), Pair(10, 38)
      },
      { // Piece 4
        Pair(-26, 93), Pair(-8, 140), Pair(77, 113), Pair(43, 83), Pair(-57, 205), Pair(103, 54), Pair(65, 88), Pair(89, 59),
        Pair(31, 116), Pair(5, 155), Pair(-4, 153), Pair(-14, 102), Pair(41, 164), Pair(51, 144), Pair(67, 66), Pair(96, 12),
        Pair(27, 113), Pair(-21, 186), Pair(44, 112), Pair(17, 174), Pair(18, 117), Pair(87, 94), Pair(-3, 106), Pair(21, 128),
        Pair(29, 127), Pair(1, 180), Pair(-3, 143), Pair(7, 89), Pair(78, 86), Pair(0, 0), Pair(47, 79), Pair(10, 107),
        Pair(30, 111), Pair(-5, 175), Pair(15, 117), Pair(24, 100), Pair(4, 2), Pair(5, 146), Pair(-29, 13), Pair(29, 49),
        Pair(44, 63), Pair(26, 157), Pair(22, 144), Pair(4, 153), Pair(-12, 160), Pair(21, 75), Pair(-12, 174), Pair(19, 76),
        Pair(28, 90), Pair(10, 163), Pair(22, 131), Pair(30, 95), Pair(16, 113), Pair(18, 153), Pair(-27, 137), Pair(-33, 164),
        Pair(40, 62), Pair(-6, 118), Pair(22, 71), Pair(19, 119), Pair(11, 96), Pair(33, 87), Pair(-29, 155), Pair(107, -136)
      },
      { // Piece 5
        Pair(53, 20), Pair(1, -63), Pair(-42, 38), Pair(-4, -30), Pair(54, 35), Pair(31, 8), Pair(-77, 95), Pair(-79, 65),
        Pair(-40, -33), Pair(4, 2), Pair(177, -47), Pair(-134, 15), Pair(0, -11), Pair(-51, -13), Pair(-16, 6), Pair(-100, -27),
        Pair(-44, 9), Pair(-21, 6), Pair(-76, 2), Pair(-14, 9), Pair(35, -8), Pair(88, -5), Pair(-21, 9), Pair(70, -26),
        Pair(-64, -15), Pair(-25, 6), Pair(-3, 14), Pair(12, 13), Pair(66, -37), Pair(0, 0), Pair(17, -36), Pair(-46, 42),
        Pair(52, -18), Pair(68, 0), Pair(16, 5), Pair(61, -6), Pair(29, -56), Pair(-40, -28), Pair(-72, -54), Pair(-76, 17),
        Pair(-79, 31), Pair(-56, 18), Pair(24, -5), Pair(-50, 6), Pair(40, -13), Pair(15, 6), Pair(1, 11), Pair(-76, 40),
        Pair(-7, -15), Pair(2, 13), Pair(44, -9), Pair(21, 4), Pair(24, -16), Pair(15, -8), Pair(15, 5), Pair(6, 28),
        Pair(-21, -6), Pair(-1, 14), Pair(0, 18), Pair(2, 27), Pair(-2, 1), Pair(16, 8), Pair(-2, 8), Pair(-7, 48)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(28, 10), Pair(36, -13), Pair(32, 6), Pair(-27, 8), Pair(-18, 23), Pair(52, 6), Pair(121, -42), Pair(-7, -2),
        Pair(17, -3), Pair(8, -4), Pair(6, 0), Pair(20, -2), Pair(8, 5), Pair(7, 1), Pair(11, -3), Pair(-10, 4),
        Pair(6, -3), Pair(2, -6), Pair(-3, 6), Pair(5, -2), Pair(-3, -3), Pair(-4, 6), Pair(0, 0), Pair(-8, 13),
        Pair(4, -8), Pair(0, 0), Pair(-2, -2), Pair(-7, -2), Pair(-2, -5), Pair(6, 3), Pair(0, 0), Pair(30, -5),
        Pair(2, -8), Pair(-2, -8), Pair(-5, -13), Pair(-6, -10), Pair(1, -6), Pair(-1, 5), Pair(-9, 10), Pair(6, 0),
        Pair(4, -12), Pair(-2, -11), Pair(-6, -7), Pair(-9, 7), Pair(-1, -14), Pair(0, -6), Pair(-6, -1), Pair(4, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, 74), Pair(-33, 43), Pair(66, -8), Pair(-123, 79), Pair(-109, 95), Pair(-153, 72), Pair(-17, 60), Pair(103, -38),
        Pair(21, 19), Pair(12, 37), Pair(41, 19), Pair(116, 19), Pair(77, 14), Pair(36, 41), Pair(-36, 70), Pair(-154, 83),
        Pair(-80, 45), Pair(48, 16), Pair(-6, 60), Pair(2, 62), Pair(44, 21), Pair(-15, 56), Pair(16, -68), Pair(-58, 99),
        Pair(12, 30), Pair(21, 16), Pair(8, 38), Pair(6, 28), Pair(10, 45), Pair(-13, 67), Pair(0, 0), Pair(-11, 26),
        Pair(-3, 54), Pair(-5, 50), Pair(11, 49), Pair(8, 48), Pair(14, 29), Pair(-53, -12), Pair(23, 72), Pair(-76, 20),
        Pair(-6, 37), Pair(26, 24), Pair(3, 38), Pair(4, 44), Pair(0, 48), Pair(-15, 38), Pair(-2, 56), Pair(-32, 37),
        Pair(-38, 28), Pair(-36, 61), Pair(1, 36), Pair(0, 34), Pair(-4, 20), Pair(19, 62), Pair(-11, -4), Pair(17, 27),
        Pair(-10, 133), Pair(-11, 92), Pair(6, 2), Pair(18, 15), Pair(-10, 43), Pair(4, 53), Pair(-6, 40), Pair(58, 87)
      },
      { // Piece 2
        Pair(52, 73), Pair(-57, 65), Pair(-72, 119), Pair(-185, 122), Pair(-153, 111), Pair(-66, 40), Pair(-92, 86), Pair(37, 57),
        Pair(42, 3), Pair(5, 67), Pair(-87, 96), Pair(-77, 115), Pair(-1, 97), Pair(-3, 66), Pair(33, 16), Pair(-25, 40),
        Pair(-46, 78), Pair(33, 36), Pair(-37, 86), Pair(-71, 66), Pair(-8, 58), Pair(16, 70), Pair(-43, 81), Pair(-50, -24),
        Pair(-34, 73), Pair(18, 65), Pair(0, 43), Pair(-9, 42), Pair(6, 52), Pair(-11, 62), Pair(0, 0), Pair(-22, 100),
        Pair(27, 58), Pair(1, 49), Pair(10, 43), Pair(-1, 55), Pair(-6, 64), Pair(-35, -52), Pair(17, 89), Pair(-48, -85),
        Pair(22, 58), Pair(-11, 51), Pair(9, 58), Pair(5, 52), Pair(2, 32), Pair(7, 56), Pair(-41, 69), Pair(-26, 92),
        Pair(-11, 23), Pair(22, 22), Pair(19, 52), Pair(4, 32), Pair(2, 55), Pair(2, 22), Pair(2, 58), Pair(0, 73),
        Pair(17, 19), Pair(-52, 64), Pair(10, 41), Pair(2, 75), Pair(-22, 47), Pair(4, 53), Pair(61, 6), Pair(13, 52)
      },
      { // Piece 3
        Pair(22, 56), Pair(-105, 90), Pair(-71, 94), Pair(7, 42), Pair(26, 58), Pair(63, 48), Pair(60, 64), Pair(-110, 86),
        Pair(6, 61), Pair(33, 65), Pair(0, 74), Pair(18, 57), Pair(-14, 76), Pair(30, 58), Pair(259, 7), Pair(62, 35),
        Pair(36, 55), Pair(35, 59), Pair(0, 74), Pair(56, 62), Pair(70, 48), Pair(70, 33), Pair(146, 35), Pair(63, 27),
        Pair(21, 50), Pair(40, 59), Pair(-31, 71), Pair(26, 65), Pair(96, 22), Pair(32, 40), Pair(0, 0), Pair(-46, 66),
        Pair(14, 53), Pair(-13, 68), Pair(24, 56), Pair(26, 51), Pair(-34, 70), Pair(6, 22), Pair(26, 47), Pair(-78, 14),
        Pair(37, 43), Pair(37, 55), Pair(-8, 54), Pair(31, 35), Pair(8, 49), Pair(-2, 70), Pair(-26, 86), Pair(-34, 61),
        Pair(19, 50), Pair(8, 72), Pair(-4, 59), Pair(7, 57), Pair(-1, 60), Pair(22, 44), Pair(17, 54), Pair(-13, 24),
        Pair(20, 56), Pair(17, 51), Pair(4, 74), Pair(10, 53), Pair(24, 52), Pair(17, 67), Pair(3, 43), Pair(4, 33)
      },
      { // Piece 4
        Pair(-92, 154), Pair(-49, 198), Pair(-37, 144), Pair(54, 49), Pair(122, 62), Pair(36, 59), Pair(-34, 79), Pair(-1, 142),
        Pair(80, 44), Pair(40, 101), Pair(6, 78), Pair(67, 79), Pair(78, -7), Pair(31, 104), Pair(-27, 90), Pair(17, 84),
        Pair(42, 73), Pair(-24, 153), Pair(33, 96), Pair(-20, 152), Pair(20, 94), Pair(38, 122), Pair(5, 153), Pair(-4, 77),
        Pair(3, 63), Pair(34, -10), Pair(32, 77), Pair(38, 70), Pair(-1, 102), Pair(11, 38), Pair(0, 0), Pair(13, 93),
        Pair(4, 44), Pair(-14, 93), Pair(38, 107), Pair(24, 118), Pair(24, 97), Pair(-62, 69), Pair(31, 94), Pair(-16, -10),
        Pair(-7, 42), Pair(35, 50), Pair(9, 84), Pair(9, 79), Pair(23, 90), Pair(-4, 68), Pair(20, 60), Pair(-46, 150),
        Pair(29, 40), Pair(12, 64), Pair(19, 83), Pair(14, 96), Pair(23, 66), Pair(45, 52), Pair(-4, 17), Pair(40, 28),
        Pair(16, 47), Pair(2, 101), Pair(25, 23), Pair(15, 72), Pair(31, -9), Pair(15, 54), Pair(50, 59), Pair(-25, 81)
      },
      { // Piece 5
        Pair(68, -56), Pair(-48, -34), Pair(204, -59), Pair(49, -57), Pair(92, -51), Pair(-38, -146), Pair(-36, -160), Pair(-14, -162),
        Pair(148, -41), Pair(94, -37), Pair(145, -36), Pair(111, -41), Pair(197, -120), Pair(52, -21), Pair(186, -86), Pair(59, -138),
        Pair(170, -65), Pair(-49, 2), Pair(11, -34), Pair(55, -25), Pair(-23, -20), Pair(136, 2), Pair(78, -60), Pair(90, -32),
        Pair(-61, -16), Pair(65, -5), Pair(65, -14), Pair(122, -41), Pair(-7, -3), Pair(-15, -31), Pair(0, 0), Pair(-9, -53),
        Pair(1, -12), Pair(-19, -1), Pair(77, -19), Pair(-42, 14), Pair(45, -12), Pair(-128, -35), Pair(13, -60), Pair(-229, -85),
        Pair(40, -33), Pair(30, -23), Pair(45, -21), Pair(24, -3), Pair(-28, 8), Pair(73, -18), Pair(-37, -2), Pair(5, -5),
        Pair(32, -37), Pair(15, -31), Pair(-9, -6), Pair(-14, -4), Pair(-14, 9), Pair(18, -14), Pair(-2, -17), Pair(21, -24),
        Pair(-18, -80), Pair(-17, -2), Pair(7, -18), Pair(22, -6), Pair(-1, 8), Pair(12, -14), Pair(-9, -7), Pair(-28, -4)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(4, 10), Pair(37, 8), Pair(49, -13), Pair(-51, 21), Pair(-28, 26), Pair(30, 15), Pair(-69, 15), Pair(-117, -39),
        Pair(10, 11), Pair(9, -8), Pair(-6, 3), Pair(6, 5), Pair(-4, 9), Pair(-16, 16), Pair(-25, 15), Pair(25, 2),
        Pair(-4, -2), Pair(6, 3), Pair(2, 3), Pair(0, 3), Pair(0, -5), Pair(-4, 6), Pair(-16, 2), Pair(0, 0),
        Pair(4, -6), Pair(-3, -1), Pair(-3, -6), Pair(-4, 4), Pair(0, -2), Pair(-5, 3), Pair(-30, 6), Pair(0, 0),
        Pair(4, -5), Pair(-2, -4), Pair(-1, -6), Pair(-1, -9), Pair(3, -12), Pair(3, 1), Pair(-14, -5), Pair(6, -3),
        Pair(2, -8), Pair(-4, -6), Pair(-8, -10), Pair(-4, -9), Pair(-1, -1), Pair(0, -3), Pair(-3, -15), Pair(3, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(4, 0), Pair(11, 42), Pair(42, 17), Pair(-53, 22), Pair(92, 24), Pair(-99, 83), Pair(-97, 13), Pair(-112, 40),
        Pair(93, -16), Pair(17, 42), Pair(60, -20), Pair(26, 18), Pair(19, 38), Pair(-53, 26), Pair(122, 18), Pair(34, 81),
        Pair(38, -9), Pair(45, -15), Pair(-6, 37), Pair(67, 5), Pair(72, 26), Pair(42, 10), Pair(0, 28), Pair(-99, 43),
        Pair(7, -1), Pair(26, 4), Pair(22, 10), Pair(9, 27), Pair(28, 14), Pair(16, 27), Pair(19, 45), Pair(0, 0),
        Pair(15, 3), Pair(30, 29), Pair(8, 8), Pair(10, 32), Pair(19, 27), Pair(37, 1), Pair(-19, 41), Pair(35, 46),
        Pair(-6, -4), Pair(14, 21), Pair(7, 20), Pair(30, 12), Pair(2, 16), Pair(13, 31), Pair(-5, 17), Pair(15, 34),
        Pair(-4, 13), Pair(14, -15), Pair(7, 21), Pair(-1, 35), Pair(14, 28), Pair(10, -8), Pair(19, 26), Pair(-3, -14),
        Pair(-57, -42), Pair(-7, 39), Pair(26, 11), Pair(3, 33), Pair(-21, 55), Pair(11, 5), Pair(8, 20), Pair(42, 18)
      },
      { // Piece 2
        Pair(128, 27), Pair(-92, 83), Pair(-77, 114), Pair(-10, 92), Pair(-128, 107), Pair(-71, 59), Pair(-13, 88), Pair(-7, 50),
        Pair(69, 9), Pair(-3, 56), Pair(-35, 53), Pair(-45, 95), Pair(34, 50), Pair(-49, 106), Pair(-67, 60), Pair(19, 43),
        Pair(45, 48), Pair(-15, 54), Pair(0, 61), Pair(-12, 75), Pair(36, 48), Pair(-86, 85), Pair(-25, 99), Pair(19, 11),
        Pair(-2, 20), Pair(28, 45), Pair(-9, 40), Pair(32, 52), Pair(-5, 51), Pair(21, 54), Pair(-11, 70), Pair(0, 0),
        Pair(2, 58), Pair(1, 45), Pair(28, 46), Pair(13, 50), Pair(14, 59), Pair(-4, 42), Pair(-121, 7), Pair(-24, 76),
        Pair(-12, 68), Pair(1, 51), Pair(4, 39), Pair(16, 45), Pair(0, 13), Pair(-9, 45), Pair(-11, 45), Pair(15, 77),
        Pair(43, 45), Pair(-3, 48), Pair(20, 52), Pair(-9, 37), Pair(4, 52), Pair(-24, 64), Pair(23, 60), Pair(-10, 103),
        Pair(-35, 40), Pair(30, 55), Pair(-10, 60), Pair(-39, 54), Pair(23, 50), Pair(6, 60), Pair(46, 8), Pair(12, 74)
      },
      { // Piece 3
        Pair(-31, 70), Pair(11, 79), Pair(-17, 90), Pair(53, 69), Pair(-58, 88), Pair(-5, 87), Pair(-36, 102), Pair(133, 58),
        Pair(46, 51), Pair(67, 33), Pair(32, 56), Pair(20, 56), Pair(37, 51), Pair(-26, 82), Pair(35, 71), Pair(92, 68),
        Pair(29, 49), Pair(24, 52), Pair(47, 53), Pair(14, 43), Pair(8, 55), Pair(-7, 75), Pair(11, 60), Pair(118, 80),
        Pair(12, 57), Pair(32, 55), Pair(19, 61), Pair(6, 65), Pair(37, 30), Pair(12, 58), Pair(11, 93), Pair(0, 0),
        Pair(10, 53), Pair(-20, 70), Pair(31, 49), Pair(33, 54), Pair(-1, 42), Pair(-6, 51), Pair(-21, -21), Pair(-34, 96),
        Pair(21, 44), Pair(8, 49), Pair(15, 45), Pair(-5, 60), Pair(13, 58), Pair(13, 50), Pair(-19, 81), Pair(-44, 90),
        Pair(19, 28), Pair(4, 49), Pair(25, 46), Pair(16, 40), Pair(-12, 43), Pair(19, 35), Pair(-3, 78), Pair(-35, 51),
        Pair(18, 49), Pair(10, 57), Pair(18, 66), Pair(9, 67), Pair(9, 52), Pair(7, 57), Pair(-3, 80), Pair(-10, 57)
      },
      { // Piece 4
        Pair(21, 153), Pair(-13, 121), Pair(-31, 188), Pair(71, 34), Pair(50, 48), Pair(-11, 166), Pair(125, 46), Pair(170, -20),
        Pair(36, 70), Pair(41, 90), Pair(40, 72), Pair(55, 84), Pair(85, 88), Pair(4, 112), Pair(95, 97), Pair(139, 20),
        Pair(1, 136), Pair(-12, 143), Pair(58, 94), Pair(64, 58), Pair(39, 74), Pair(1, 79), Pair(-1, 141), Pair(-27, 182),
        Pair(18, 105), Pair(51, 101), Pair(10, 143), Pair(43, 65), Pair(35, 120), Pair(66, 32), Pair(-30, 202), Pair(0, 0),
        Pair(19, 115), Pair(43, 57), Pair(22, 100), Pair(21, 113), Pair(44, 69), Pair(15, 89), Pair(-17, -2), Pair(28, 124),
        Pair(-7, 103), Pair(30, 45), Pair(10, 141), Pair(18, 103), Pair(9, 127), Pair(15, 117), Pair(13, 48), Pair(16, 5),
        Pair(48, 55), Pair(13, 52), Pair(20, 85), Pair(15, 103), Pair(17, 111), Pair(21, 76), Pair(19, 134), Pair(-14, 119),
        Pair(57, 35), Pair(28, 91), Pair(19, 114), Pair(22, 95), Pair(2, 112), Pair(-1, 116), Pair(28, -57), Pair(84, -9)
      },
      { // Piece 5
        Pair(9, 41), Pair(128, -61), Pair(238, -53), Pair(-67, -67), Pair(53, -20), Pair(91, -73), Pair(21, -76), Pair(-44, -208),
        Pair(104, -3), Pair(125, 29), Pair(-3, 7), Pair(118, -26), Pair(-10, -21), Pair(18, -56), Pair(146, -99), Pair(26, -51),
        Pair(24, 29), Pair(-36, 1), Pair(35, -21), Pair(1, -3), Pair(158, -67), Pair(186, -51), Pair(132, -49), Pair(195, -65),
        Pair(40, -48), Pair(-26, -2), Pair(52, -23), Pair(-3, -6), Pair(21, 5), Pair(-78, 34), Pair(-85, -5), Pair(0, 0),
        Pair(23, -30), Pair(-24, 6), Pair(24, -4), Pair(54, -15), Pair(35, 1), Pair(2, 14), Pair(-246, -25), Pair(-17, -54),
        Pair(-37, 9), Pair(22, -24), Pair(32, -11), Pair(14, -10), Pair(-9, 12), Pair(-8, 8), Pair(17, 3), Pair(23, -7),
        Pair(-5, -25), Pair(-12, -4), Pair(-14, -16), Pair(-7, 1), Pair(4, 8), Pair(-15, 26), Pair(15, 12), Pair(-4, -7),
        Pair(-4, -50), Pair(-3, -13), Pair(0, -14), Pair(0, 2), Pair(2, 21), Pair(3, 41), Pair(1, 16), Pair(9, 13)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(84, -60), Pair(-24, 0), Pair(-30, 38), Pair(-43, 40), Pair(-1, 28), Pair(-40, 34), Pair(37, 7), Pair(0, 43),
        Pair(0, 0), Pair(0, -33), Pair(17, 4), Pair(16, -7), Pair(-5, 2), Pair(23, 5), Pair(-6, 17), Pair(-11, 22),
        Pair(-15, -15), Pair(-17, -8), Pair(4, -1), Pair(-1, 9), Pair(8, -1), Pair(-8, 8), Pair(0, 11), Pair(-2, 13),
        Pair(-6, -5), Pair(-10, -1), Pair(4, 1), Pair(-3, 5), Pair(0, 7), Pair(0, 9), Pair(-2, 11), Pair(-2, 8),
        Pair(0, 0), Pair(-5, -4), Pair(5, -4), Pair(-3, -6), Pair(-1, 2), Pair(-2, 0), Pair(-6, 1), Pair(-5, 3),
        Pair(7, -9), Pair(-1, -13), Pair(4, -6), Pair(-3, 0), Pair(0, -6), Pair(-7, 3), Pair(-12, 0), Pair(-2, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-59, 90), Pair(-39, 60), Pair(48, 117), Pair(255, 46), Pair(-72, 82), Pair(-6, 94), Pair(138, 28), Pair(-75, 26),
        Pair(-13, -45), Pair(49, 49), Pair(-11, 29), Pair(46, 76), Pair(61, 6), Pair(24, 64), Pair(56, 63), Pair(94, -22),
        Pair(0, 0), Pair(-26, 74), Pair(14, 77), Pair(28, 5), Pair(51, 36), Pair(-26, 82), Pair(51, 23), Pair(56, 18),
        Pair(46, 76), Pair(-42, 7), Pair(5, 56), Pair(23, 48), Pair(24, 55), Pair(19, 37), Pair(14, 48), Pair(24, 49),
        Pair(-9, 64), Pair(27, 25), Pair(10, 62), Pair(3, 54), Pair(21, 52), Pair(16, 47), Pair(1, 71), Pair(16, 10),
        Pair(-10, 23), Pair(5, 69), Pair(1, 39), Pair(16, 57), Pair(2, 61), Pair(6, 39), Pair(20, 56), Pair(16, 21),
        Pair(-17, -6), Pair(19, 6), Pair(-23, 60), Pair(3, 61), Pair(8, 42), Pair(2, 54), Pair(18, 62), Pair(-29, 33),
        Pair(61, 108), Pair(-12, 49), Pair(6, 24), Pair(5, 28), Pair(17, 37), Pair(7, 15), Pair(1, 25), Pair(11, -9)
      },
      { // Piece 2
        Pair(-97, 100), Pair(-109, 108), Pair(26, 107), Pair(-72, 120), Pair(-70, 91), Pair(-102, 105), Pair(48, 42), Pair(-72, 136),
        Pair(50, 68), Pair(-54, 101), Pair(0, 89), Pair(-20, 95), Pair(-13, 108), Pair(-66, 114), Pair(-19, 93), Pair(-33, 135),
        Pair(0, 0), Pair(-24, 115), Pair(6, 75), Pair(56, 54), Pair(-15, 114), Pair(-12, 114), Pair(3, 95), Pair(-8, 67),
        Pair(48, 83), Pair(-5, -39), Pair(20, 78), Pair(-2, 107), Pair(15, 76), Pair(18, 87), Pair(21, 56), Pair(5, 91),
        Pair(2, 51), Pair(-5, 87), Pair(-4, 79), Pair(-5, 81), Pair(31, 78), Pair(8, 80), Pair(-45, 102), Pair(-15, 84),
        Pair(6, 109), Pair(-13, 73), Pair(3, 84), Pair(9, 77), Pair(-1, 76), Pair(7, 86), Pair(27, 78), Pair(6, 55),
        Pair(29, 98), Pair(1, 90), Pair(-12, 102), Pair(6, 72), Pair(-7, 69), Pair(-11, 81), Pair(10, 70), Pair(24, 73),
        Pair(25, 67), Pair(-19, 115), Pair(0, 89), Pair(-14, 91), Pair(14, 82), Pair(0, 68), Pair(24, 76), Pair(-13, 53)
      },
      { // Piece 3
        Pair(39, 126), Pair(12, 128), Pair(11, 152), Pair(-64, 179), Pair(8, 144), Pair(16, 140), Pair(-5, 131), Pair(88, 137),
        Pair(85, 145), Pair(-3, 150), Pair(-5, 152), Pair(-5, 139), Pair(-22, 162), Pair(39, 125), Pair(47, 120), Pair(-42, 151),
        Pair(0, 0), Pair(-50, 161), Pair(-10, 184), Pair(-27, 167), Pair(8, 136), Pair(-9, 136), Pair(-3, 150), Pair(25, 116),
        Pair(-31, 158), Pair(-2, 33), Pair(-20, 149), Pair(-49, 153), Pair(8, 124), Pair(40, 103), Pair(23, 129), Pair(16, 129),
        Pair(-46, 162), Pair(-36, 148), Pair(-32, 141), Pair(-49, 141), Pair(-18, 126), Pair(-10, 118), Pair(26, 108), Pair(21, 113),
        Pair(-25, 101), Pair(-21, 158), Pair(-4, 127), Pair(-12, 109), Pair(18, 99), Pair(9, 111), Pair(30, 114), Pair(6, 133),
        Pair(-26, 107), Pair(-7, 96), Pair(-6, 141), Pair(12, 84), Pair(-20, 119), Pair(19, 95), Pair(-10, 142), Pair(-9, 135),
        Pair(-22, 114), Pair(-24, 132), Pair(-14, 135), Pair(-12, 133), Pair(-2, 120), Pair(-1, 123), Pair(-6, 131), Pair(-2, 138)
      },
      { // Piece 4
        Pair(2, 245), Pair(83, 216), Pair(50, 203), Pair(-7, 259), Pair(-12, 255), Pair(-14, 260), Pair(62, 211), Pair(89, 213),
        Pair(67, 212), Pair(24, 228), Pair(-3, 289), Pair(58, 220), Pair(23, 285), Pair(82, 197), Pair(1, 282), Pair(59, 238),
        Pair(0, 0), Pair(86, 197), Pair(30, 242), Pair(93, 178), Pair(65, 205), Pair(12, 261), Pair(17, 312), Pair(95, 172),
        Pair(85, 169), Pair(32, 25), Pair(50, 207), Pair(9, 228), Pair(40, 230), Pair(69, 183), Pair(47, 207), Pair(53, 187),
        Pair(31, 223), Pair(33, 215), Pair(22, 250), Pair(23, 280), Pair(45, 194), Pair(38, 251), Pair(43, 237), Pair(47, 178),
        Pair(41, 211), Pair(37, 168), Pair(38, 217), Pair(20, 254), Pair(39, 209), Pair(38, 244), Pair(56, 178), Pair(66, 167),
        Pair(65, 142), Pair(45, 196), Pair(32, 223), Pair(31, 214), Pair(40, 225), Pair(39, 188), Pair(45, 232), Pair(15, 272),
        Pair(64, 197), Pair(31, 244), Pair(37, 226), Pair(24, 215), Pair(20, 207), Pair(74, 130), Pair(74, 170), Pair(-1, 177)
      },
      { // Piece 5
        Pair(-41, -51), Pair(89, -2), Pair(77, -51), Pair(135, 14), Pair(8, 31), Pair(64, 94), Pair(3, 51), Pair(-58, -50),
        Pair(-18, -53), Pair(-62, 21), Pair(137, -19), Pair(128, -34), Pair(-134, 51), Pair(126, -38), Pair(-70, 66), Pair(-18, -1),
        Pair(0, 0), Pair(-101, -11), Pair(-147, 33), Pair(-20, 20), Pair(-13, 44), Pair(-38, 6), Pair(-99, 11), Pair(100, -75),
        Pair(-95, -88), Pair(-62, -60), Pair(-108, 25), Pair(-84, 18), Pair(-15, 7), Pair(-140, 51), Pair(-61, 12), Pair(-76, -16),
        Pair(2, -28), Pair(-83, 26), Pair(-16, -3), Pair(-78, 17), Pair(34, -12), Pair(-49, 5), Pair(1, 5), Pair(62, -28),
        Pair(-93, -18), Pair(6, -7), Pair(-58, 5), Pair(-29, 12), Pair(-22, -2), Pair(-6, -9), Pair(3, -8), Pair(50, -19),
        Pair(-15, 9), Pair(-34, 21), Pair(-12, 13), Pair(17, -7), Pair(-1, 11), Pair(10, -14), Pair(-5, -4), Pair(0, 9),
        Pair(-57, 69), Pair(3, 1), Pair(3, 13), Pair(5, 3), Pair(9, 0), Pair(7, -28), Pair(0, -7), Pair(-6, -5)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-72, 50), Pair(-38, -36), Pair(26, -18), Pair(-89, 49), Pair(32, 12), Pair(-37, 16), Pair(86, 25), Pair(41, 9),
        Pair(5, 5), Pair(0, 0), Pair(-3, -9), Pair(6, -3), Pair(17, 4), Pair(-3, 8), Pair(5, 10), Pair(-5, 18),
        Pair(23, 9), Pair(-8, -14), Pair(-4, 18), Pair(3, 3), Pair(9, -2), Pair(4, 16), Pair(-1, 16), Pair(2, 18),
        Pair(9, 2), Pair(-3, -10), Pair(0, 13), Pair(0, 5), Pair(2, 2), Pair(-7, 16), Pair(2, 7), Pair(2, 4),
        Pair(3, 4), Pair(0, 0), Pair(-3, 8), Pair(-2, -1), Pair(-4, -2), Pair(-4, 1), Pair(-4, 0), Pair(-6, 3),
        Pair(3, -2), Pair(5, 0), Pair(-2, -4), Pair(0, 0), Pair(-3, -4), Pair(-12, 0), Pair(-11, -2), Pair(-5, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-58, 114), Pair(38, 69), Pair(-33, 116), Pair(136, 36), Pair(54, 102), Pair(40, 37), Pair(-66, 109), Pair(16, 113),
        Pair(-43, 116), Pair(-93, 32), Pair(-37, 89), Pair(1, 50), Pair(93, 66), Pair(15, 90), Pair(-44, 67), Pair(4, 80),
        Pair(26, 27), Pair(0, 0), Pair(6, 60), Pair(18, 79), Pair(16, 65), Pair(47, 47), Pair(-27, 83), Pair(35, 92),
        Pair(1, 1), Pair(13, 81), Pair(-52, 3), Pair(14, 73), Pair(11, 80), Pair(9, 89), Pair(19, 54), Pair(34, 69),
        Pair(-36, 78), Pair(35, 60), Pair(7, 52), Pair(8, 51), Pair(10, 52), Pair(11, 75), Pair(19, 49), Pair(27, 45),
        Pair(0, 64), Pair(-28, 27), Pair(0, 71), Pair(-7, 44), Pair(16, 59), Pair(1, 72), Pair(16, 61), Pair(7, 48),
        Pair(-6, 44), Pair(-27, 74), Pair(9, 72), Pair(4, 50), Pair(4, 70), Pair(-11, 86), Pair(13, 62), Pair(0, 94),
        Pair(6, 107), Pair(-3, 91), Pair(34, 18), Pair(9, 50), Pair(25, 45), Pair(1, 76), Pair(0, 83), Pair(28, 92)
      },
      { // Piece 2
        Pair(86, 22), Pair(8, 128), Pair(-67, 122), Pair(-100, 139), Pair(-203, 157), Pair(8, 66), Pair(1, 78), Pair(24, 107),
        Pair(-249, 27), Pair(-4, 95), Pair(-35, 109), Pair(-93, 154), Pair(2, 90), Pair(-33, 94), Pair(43, 96), Pair(33, 89),
        Pair(-36, 137), Pair(0, 0), Pair(-27, 104), Pair(-40, 116), Pair(-14, 112), Pair(-25, 128), Pair(16, 92), Pair(2, 75),
        Pair(-36, -2), Pair(-6, 117), Pair(-37, -48), Pair(-11, 101), Pair(1, 110), Pair(-8, 99), Pair(-10, 84), Pair(-13, 100),
        Pair(-21, 98), Pair(-30, 94), Pair(-10, 99), Pair(-22, 95), Pair(2, 90), Pair(-4, 90), Pair(19, 99), Pair(-7, 108),
        Pair(0, 84), Pair(-29, 116), Pair(-21, 82), Pair(4, 104), Pair(-16, 82), Pair(9, 92), Pair(-7, 78), Pair(21, 74),
        Pair(-14, 137), Pair(9, 89), Pair(51, 56), Pair(-10, 87), Pair(-5, 100), Pair(-31, 76), Pair(8, 86), Pair(10, 94),
        Pair(-14, 120), Pair(48, 72), Pair(-2, 84), Pair(-3, 91), Pair(-10, 76), Pair(5, 93), Pair(-36, 90), Pair(13, 57)
      },
      { // Piece 3
        Pair(10, 112), Pair(-128, 177), Pair(-88, 153), Pair(-16, 137), Pair(68, 93), Pair(-55, 144), Pair(-26, 128), Pair(14, 119),
        Pair(-14, 122), Pair(77, 129), Pair(27, 120), Pair(25, 123), Pair(51, 113), Pair(31, 114), Pair(-7, 128), Pair(-30, 135),
        Pair(-21, 112), Pair(0, 0), Pair(11, 124), Pair(-2, 143), Pair(23, 109), Pair(48, 120), Pair(35, 101), Pair(57, 95),
        Pair(-55, 82), Pair(-21, 112), Pair(-67, 41), Pair(15, 97), Pair(-10, 124), Pair(3, 94), Pair(35, 87), Pair(31, 97),
        Pair(-24, 116), Pair(-61, 152), Pair(-75, 162), Pair(-6, 99), Pair(-27, 111), Pair(-12, 105), Pair(-3, 114), Pair(-17, 127),
        Pair(-32, 108), Pair(-34, 99), Pair(-29, 100), Pair(-25, 109), Pair(-9, 112), Pair(-9, 126), Pair(5, 101), Pair(0, 98),
        Pair(-48, 124), Pair(-11, 105), Pair(-33, 95), Pair(0, 98), Pair(-3, 107), Pair(-10, 97), Pair(-23, 123), Pair(19, 100),
        Pair(-21, 120), Pair(-18, 100), Pair(-31, 130), Pair(-4, 119), Pair(-11, 128), Pair(-11, 121), Pair(7, 102), Pair(-2, 127)
      },
      { // Piece 4
        Pair(-47, 242), Pair(94, 65), Pair(-22, 208), Pair(102, 79), Pair(58, 111), Pair(129, 124), Pair(-3, 120), Pair(-71, 260),
        Pair(-9, 212), Pair(43, 207), Pair(53, 143), Pair(46, 168), Pair(26, 183), Pair(40, 182), Pair(23, 157), Pair(62, 154),
        Pair(22, 181), Pair(0, 0), Pair(49, 194), Pair(59, 120), Pair(-1, 197), Pair(33, 181), Pair(-5, 232), Pair(57, 147),
        Pair(-10, 145), Pair(54, 115), Pair(8, 37), Pair(22, 151), Pair(39, 188), Pair(34, 184), Pair(49, 135), Pair(46, 171),
        Pair(13, 154), Pair(21, 103), Pair(-19, 195), Pair(14, 174), Pair(23, 209), Pair(30, 157), Pair(31, 183), Pair(35, 179),
        Pair(20, 131), Pair(22, 139), Pair(19, 139), Pair(10, 201), Pair(28, 173), Pair(23, 208), Pair(52, 116), Pair(64, 148),
        Pair(11, 215), Pair(24, 126), Pair(22, 187), Pair(14, 178), Pair(20, 173), Pair(22, 184), Pair(27, 133), Pair(7, 208),
        Pair(-16, 267), Pair(27, 192), Pair(27, 141), Pair(19, 161), Pair(16, 151), Pair(31, 165), Pair(92, 62), Pair(38, 247)
      },
      { // Piece 5
        Pair(-20, -84), Pair(-16, 0), Pair(-102, -15), Pair(0, -31), Pair(118, 3), Pair(118, -89), Pair(-18, 23), Pair(48, -90),
        Pair(-52, -53), Pair(-81, -10), Pair(-35, -29), Pair(112, -56), Pair(-212, 27), Pair(-1, 19), Pair(58, -1), Pair(-115, 69),
        Pair(-69, -44), Pair(0, 0), Pair(-76, -12), Pair(-42, 14), Pair(-8, 15), Pair(-21, 29), Pair(-25, 2), Pair(-18, 11),
        Pair(2, 4), Pair(45, -55), Pair(4, 55), Pair(-127, 12), Pair(-72, 17), Pair(-25, 12), Pair(45, 12), Pair(-64, 9),
        Pair(143, -44), Pair(-38, -34), Pair(-44, -12), Pair(-112, 2), Pair(-18, 2), Pair(8, -1), Pair(-51, 25), Pair(-17, 10),
        Pair(-25, -21), Pair(-11, -33), Pair(-14, -11), Pair(-54, 10), Pair(38, -10), Pair(42, -17), Pair(14, -13), Pair(-53, 6),
        Pair(-1, -28), Pair(15, -26), Pair(4, -22), Pair(19, -2), Pair(3, -8), Pair(21, -21), Pair(5, -19), Pair(12, -27),
        Pair(56, -30), Pair(18, -19), Pair(9, -9), Pair(11, -19), Pair(5, -2), Pair(19, -8), Pair(3, -16), Pair(3, -15)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 15), Pair(-37, 19), Pair(-19, -8), Pair(-41, -3), Pair(1, 9), Pair(10, 24), Pair(-26, 20), Pair(-29, 30),
        Pair(1, 10), Pair(13, 12), Pair(0, 0), Pair(13, -8), Pair(-3, 15), Pair(16, -2), Pair(9, 24), Pair(9, 12),
        Pair(-6, 5), Pair(7, 15), Pair(-2, -12), Pair(3, 31), Pair(8, -8), Pair(13, 8), Pair(-1, 10), Pair(6, 19),
        Pair(-2, 4), Pair(7, -13), Pair(-3, -5), Pair(-1, 11), Pair(2, -2), Pair(-1, 7), Pair(6, 14), Pair(-1, 8),
        Pair(-5, 6), Pair(3, -8), Pair(0, 0), Pair(1, 1), Pair(-2, -3), Pair(4, -1), Pair(3, 2), Pair(-2, 1),
        Pair(0, -1), Pair(-1, -15), Pair(4, 0), Pair(-1, -6), Pair(-2, 1), Pair(-1, -5), Pair(-2, -4), Pair(0, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-23, 130), Pair(23, 58), Pair(-101, 52), Pair(-136, 132), Pair(-66, 60), Pair(77, 12), Pair(90, 46), Pair(112, 24),
        Pair(-113, -24), Pair(28, 96), Pair(-63, 62), Pair(43, 91), Pair(59, 39), Pair(-5, 59), Pair(0, 67), Pair(2, 49),
        Pair(-77, 97), Pair(9, 82), Pair(0, 0), Pair(-7, 76), Pair(46, 48), Pair(26, 59), Pair(8, 69), Pair(-29, 82),
        Pair(26, 48), Pair(-47, -15), Pair(11, 89), Pair(-47, 2), Pair(10, 73), Pair(-6, 48), Pair(16, 46), Pair(5, 63),
        Pair(-4, 77), Pair(-48, 55), Pair(0, 75), Pair(-7, 43), Pair(15, 67), Pair(-4, 57), Pair(34, 42), Pair(18, 65),
        Pair(-9, 23), Pair(7, 61), Pair(-9, 30), Pair(18, 86), Pair(3, 37), Pair(8, 68), Pair(7, 64), Pair(18, 45),
        Pair(-2, 67), Pair(65, 47), Pair(2, 35), Pair(5, 75), Pair(-8, 52), Pair(17, 47), Pair(16, 18), Pair(-15, 31),
        Pair(15, -34), Pair(-8, 55), Pair(-22, 97), Pair(1, 71), Pair(22, 44), Pair(10, 45), Pair(5, 74), Pair(8, 106)
      },
      { // Piece 2
        Pair(-100, -63), Pair(-62, 104), Pair(-88, 103), Pair(-67, 82), Pair(-130, 143), Pair(-17, 114), Pair(-68, 34), Pair(9, 123),
        Pair(-2, 96), Pair(-133, 47), Pair(-14, 79), Pair(-127, 116), Pair(21, 90), Pair(-5, 74), Pair(-17, 104), Pair(54, 108),
        Pair(-32, 64), Pair(17, 73), Pair(0, 0), Pair(52, 73), Pair(-26, 90), Pair(-21, 114), Pair(-21, 87), Pair(38, 76),
        Pair(12, 66), Pair(-23, -21), Pair(-8, 87), Pair(-74, 1), Pair(-14, 92), Pair(-25, 77), Pair(8, 96), Pair(5, 69),
        Pair(-17, 76), Pair(-7, 80), Pair(-13, 79), Pair(-24, 101), Pair(-22, 76), Pair(14, 87), Pair(-5, 76), Pair(25, 52),
        Pair(6, 42), Pair(-40, 90), Pair(6, 91), Pair(-5, 59), Pair(5, 82), Pair(-6, 58), Pair(38, 83), Pair(-3, 83),
        Pair(17, 11), Pair(11, 83), Pair(-11, 89), Pair(18, 74), Pair(-14, 56), Pair(7, 74), Pair(-9, 52), Pair(41, 16),
        Pair(19, 81), Pair(-22, 99), Pair(17, 88), Pair(-34, 91), Pair(25, 59), Pair(-9, 63), Pair(-2, 104), Pair(-16, 23)
      },
      { // Piece 3
        Pair(-49, 116), Pair(-3, 103), Pair(12, 114), Pair(7, 109), Pair(81, 81), Pair(-79, 146), Pair(17, 88), Pair(11, 98),
        Pair(8, 98), Pair(-3, 98), Pair(43, 86), Pair(-4, 113), Pair(40, 89), Pair(43, 84), Pair(-6, 101), Pair(41, 76),
        Pair(13, 81), Pair(22, 61), Pair(0, 0), Pair(34, 65), Pair(10, 80), Pair(21, 87), Pair(58, 84), Pair(31, 66),
        Pair(-37, 101), Pair(64, -47), Pair(-49, 123), Pair(25, -7), Pair(-8, 101), Pair(4, 86), Pair(15, 93), Pair(4, 83),
        Pair(-6, 103), Pair(-36, 106), Pair(-38, 104), Pair(-11, 93), Pair(50, 75), Pair(-23, 103), Pair(57, 67), Pair(8, 101),
        Pair(-12, 87), Pair(2, 62), Pair(-3, 84), Pair(-14, 91), Pair(23, 68), Pair(6, 105), Pair(6, 109), Pair(10, 81),
        Pair(1, 71), Pair(5, 88), Pair(-18, 72), Pair(-2, 63), Pair(-6, 100), Pair(11, 78), Pair(-2, 92), Pair(16, 65),
        Pair(-2, 110), Pair(-1, 83), Pair(-1, 64), Pair(-7, 84), Pair(8, 84), Pair(0, 87), Pair(10, 79), Pair(10, 101)
      },
      { // Piece 4
        Pair(45, 137), Pair(52, 208), Pair(21, 144), Pair(25, 255), Pair(155, 58), Pair(33, 174), Pair(57, 89), Pair(31, 117),
        Pair(42, 167), Pair(67, 132), Pair(86, 115), Pair(185, 43), Pair(106, 93), Pair(61, 85), Pair(-34, 169), Pair(27, 187),
        Pair(31, 170), Pair(71, 144), Pair(0, 0), Pair(17, 189), Pair(41, 144), Pair(23, 142), Pair(87, 45), Pair(64, 107),
        Pair(24, 170), Pair(22, 114), Pair(89, 104), Pair(12, 90), Pair(36, 133), Pair(12, 202), Pair(57, 120), Pair(55, 118),
        Pair(42, 146), Pair(47, 183), Pair(60, 85), Pair(40, 123), Pair(35, 131), Pair(38, 168), Pair(32, 173), Pair(51, 141),
        Pair(47, 145), Pair(23, 129), Pair(60, 112), Pair(17, 168), Pair(40, 133), Pair(34, 115), Pair(29, 130), Pair(67, 163),
        Pair(17, 143), Pair(31, 132), Pair(63, 75), Pair(33, 174), Pair(30, 162), Pair(27, 177), Pair(41, 160), Pair(22, 233),
        Pair(55, 79), Pair(36, 114), Pair(47, 139), Pair(29, 160), Pair(25, 235), Pair(37, 157), Pair(63, 195), Pair(25, 133)
      },
      { // Piece 5
        Pair(9, -42), Pair(149, 69), Pair(-37, 15), Pair(20, -16), Pair(73, 33), Pair(-19, 6), Pair(-11, 12), Pair(-9, -111),
        Pair(57, -24), Pair(82, 10), Pair(230, -65), Pair(194, -16), Pair(-53, -11), Pair(11, 49), Pair(-132, 39), Pair(-80, -83),
        Pair(-91, -3), Pair(8, -33), Pair(0, 0), Pair(171, -95), Pair(169, -38), Pair(-243, 96), Pair(-151, -1), Pair(-188, 55),
        Pair(98, 0), Pair(1, 15), Pair(34, -83), Pair(-2, -12), Pair(-10, -4), Pair(12, -12), Pair(-46, 17), Pair(-47, 21),
        Pair(-90, -3), Pair(34, -26), Pair(-70, -36), Pair(-143, 4), Pair(-35, -23), Pair(21, -8), Pair(64, -11), Pair(63, -23),
        Pair(38, 2), Pair(13, -19), Pair(6, -21), Pair(-7, -14), Pair(6, 0), Pair(43, -7), Pair(43, -10), Pair(6, -16),
        Pair(-52, 39), Pair(4, 1), Pair(11, -8), Pair(0, -6), Pair(-1, 8), Pair(-4, 5), Pair(-4, 1), Pair(-10, 8),
        Pair(3, -38), Pair(-13, 3), Pair(0, -8), Pair(12, 11), Pair(1, 16), Pair(-2, 13), Pair(0, 3), Pair(16, -15)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(13, 40), Pair(-14, 33), Pair(67, -12), Pair(-12, 84), Pair(-84, 26), Pair(17, 24), Pair(45, 12), Pair(12, 31),
        Pair(-2, 16), Pair(-14, 22), Pair(-1, 12), Pair(0, 0), Pair(6, 2), Pair(-6, 26), Pair(-4, 25), Pair(-11, 7),
        Pair(5, 8), Pair(2, -2), Pair(10, 3), Pair(-6, -15), Pair(-11, 34), Pair(-4, 6), Pair(0, 9), Pair(1, 10),
        Pair(2, -5), Pair(2, -4), Pair(3, -2), Pair(-9, 2), Pair(-4, 7), Pair(-2, 12), Pair(7, 10), Pair(0, 12),
        Pair(1, 4), Pair(3, 2), Pair(-2, -2), Pair(0, 0), Pair(-5, -2), Pair(-1, 3), Pair(-7, 10), Pair(0, -3),
        Pair(3, -5), Pair(-2, -5), Pair(-4, -3), Pair(1, -6), Pair(-2, -5), Pair(-3, -3), Pair(-5, 8), Pair(3, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(42, 75), Pair(57, 35), Pair(-165, 80), Pair(159, 49), Pair(7, 36), Pair(-5, 70), Pair(-74, 172), Pair(141, 73),
        Pair(-58, 103), Pair(9, 29), Pair(17, 59), Pair(0, 54), Pair(-29, 74), Pair(-1, 61), Pair(-60, 114), Pair(-6, 44),
        Pair(-19, 5), Pair(48, 65), Pair(33, 50), Pair(0, 0), Pair(1, 52), Pair(53, 44), Pair(-3, 44), Pair(-12, 65),
        Pair(-25, 70), Pair(2, 40), Pair(-21, -51), Pair(15, 89), Pair(-48, 25), Pair(-12, 41), Pair(2, 57), Pair(27, 24),
        Pair(-11, 44), Pair(-12, 64), Pair(-18, 30), Pair(2, 74), Pair(-5, 26), Pair(4, 61), Pair(-12, 35), Pair(14, 41),
        Pair(-5, 85), Pair(7, 4), Pair(5, 69), Pair(-20, 15), Pair(7, 62), Pair(-4, 34), Pair(2, 54), Pair(8, 61),
        Pair(29, 33), Pair(32, -15), Pair(17, 57), Pair(-4, 64), Pair(18, 47), Pair(-12, 23), Pair(13, 45), Pair(6, 48),
        Pair(-102, 69), Pair(10, 53), Pair(-29, 10), Pair(-29, 70), Pair(7, 19), Pair(29, 59), Pair(8, 33), Pair(26, 25)
      },
      { // Piece 2
        Pair(5, 28), Pair(-96, 61), Pair(-65, 70), Pair(-52, 78), Pair(58, 111), Pair(41, 3), Pair(-70, 88), Pair(-1, 45),
        Pair(24, 50), Pair(15, 41), Pair(-47, 41), Pair(24, 83), Pair(-166, 99), Pair(-20, 130), Pair(-16, 27), Pair(-1, 108),
        Pair(10, 35), Pair(-12, 40), Pair(19, 75), Pair(0, 0), Pair(10, 99), Pair(-58, 82), Pair(-43, 119), Pair(15, 32),
        Pair(-1, 39), Pair(-8, 83), Pair(12, -106), Pair(-3, 88), Pair(-21, -93), Pair(-16, 90), Pair(-6, 72), Pair(34, 74),
        Pair(-14, 54), Pair(-16, 60), Pair(-15, 62), Pair(2, 50), Pair(-13, 67), Pair(-21, 50), Pair(-4, 100), Pair(-13, 63),
        Pair(-2, 48), Pair(-31, 62), Pair(-17, 54), Pair(1, 71), Pair(-12, 51), Pair(-11, 85), Pair(-19, -1), Pair(14, 79),
        Pair(-25, 109), Pair(-13, 45), Pair(1, 67), Pair(6, 61), Pair(-5, 61), Pair(-27, 69), Pair(-13, 82), Pair(36, 9),
        Pair(-18, 40), Pair(-1, 125), Pair(5, 51), Pair(1, 89), Pair(6, 36), Pair(1, 69), Pair(4, 19), Pair(-13, 130)
      },
      { // Piece 3
        Pair(24, 53), Pair(39, 49), Pair(62, 32), Pair(29, 79), Pair(20, 96), Pair(-85, 99), Pair(19, 68), Pair(-48, 98),
        Pair(4, 76), Pair(-6, 100), Pair(28, 26), Pair(-19, 77), Pair(-29, 80), Pair(-16, 92), Pair(52, 58), Pair(-8, 86),
        Pair(40, 43), Pair(6, 87), Pair(10, 28), Pair(0, 0), Pair(-23, 97), Pair(64, 27), Pair(22, 66), Pair(31, 50),
        Pair(9, 39), Pair(-28, 64), Pair(52, -3), Pair(-39, 76), Pair(-13, 14), Pair(34, 50), Pair(10, 65), Pair(-7, 68),
        Pair(-10, 70), Pair(13, 59), Pair(-21, 65), Pair(-51, 94), Pair(2, 60), Pair(-23, 82), Pair(13, 52), Pair(-4, 93),
        Pair(11, 44), Pair(18, 56), Pair(11, 26), Pair(6, 34), Pair(-6, 76), Pair(-2, 86), Pair(7, 72), Pair(11, 53),
        Pair(-9, 81), Pair(-15, 41), Pair(-40, 70), Pair(-22, 57), Pair(13, 50), Pair(-31, 84), Pair(4, 68), Pair(25, 64),
        Pair(-2, 78), Pair(-6, 63), Pair(-8, 61), Pair(-4, 56), Pair(-8, 60), Pair(2, 66), Pair(15, 53), Pair(14, 68)
      },
      { // Piece 4
        Pair(-26, 198), Pair(69, 156), Pair(28, 155), Pair(87, 106), Pair(-40, 172), Pair(9, 168), Pair(89, 173), Pair(45, 74),
        Pair(-35, 229), Pair(7, 171), Pair(66, -9), Pair(27, 125), Pair(37, 100), Pair(55, 126), Pair(19, 139), Pair(113, 52),
        Pair(64, 107), Pair(47, 136), Pair(1, 156), Pair(0, 0), Pair(43, 121), Pair(45, 85), Pair(27, 128), Pair(-4, 152),
        Pair(8, 105), Pair(12, 165), Pair(10, 37), Pair(62, 78), Pair(16, -60), Pair(16, 159), Pair(-29, 201), Pair(8, 165),
        Pair(16, 142), Pair(4, 197), Pair(14, 125), Pair(34, 46), Pair(-4, 108), Pair(25, 39), Pair(20, 157), Pair(3, 181),
        Pair(20, 107), Pair(7, 104), Pair(21, 76), Pair(26, 99), Pair(1, 116), Pair(16, 132), Pair(23, 62), Pair(36, 103),
        Pair(2, 182), Pair(0, 125), Pair(9, 107), Pair(28, 79), Pair(7, 133), Pair(-20, 151), Pair(-7, 129), Pair(63, 55),
        Pair(-5, 173), Pair(10, 82), Pair(-6, 189), Pair(25, 112), Pair(6, 123), Pair(-33, 226), Pair(28, 105), Pair(41, 140)
      },
      { // Piece 5
        Pair(23, -14), Pair(-75, -128), Pair(-8, -125), Pair(-7, -60), Pair(38, -51), Pair(-18, -40), Pair(25, -160), Pair(34, 14),
        Pair(-10, 81), Pair(80, 14), Pair(216, -8), Pair(30, 34), Pair(-14, 24), Pair(93, -93), Pair(62, -47), Pair(43, -40),
        Pair(14, 46), Pair(-51, 38), Pair(74, -77), Pair(0, 0), Pair(68, -37), Pair(47, -18), Pair(65, -9), Pair(34, -25),
        Pair(14, -9), Pair(103, 10), Pair(-4, -24), Pair(77, -69), Pair(2, 8), Pair(-73, 37), Pair(-27, -23), Pair(-58, 28),
        Pair(33, 16), Pair(-51, 18), Pair(50, -36), Pair(-49, -30), Pair(16, -27), Pair(-73, -18), Pair(-130, 40), Pair(-1, 9),
        Pair(-56, 31), Pair(-25, 17), Pair(38, -18), Pair(-13, -20), Pair(-26, -21), Pair(-7, 17), Pair(-23, 9), Pair(12, 7),
        Pair(-61, 70), Pair(-5, 27), Pair(-46, 9), Pair(1, -1), Pair(-22, -9), Pair(-9, 10), Pair(-7, 12), Pair(-7, 8),
        Pair(22, -34), Pair(-15, 26), Pair(-12, -7), Pair(6, -12), Pair(1, -10), Pair(-5, 8), Pair(2, 14), Pair(0, 20)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 22), Pair(-37, 37), Pair(-60, 39), Pair(-20, 8), Pair(-100, 22), Pair(-70, 71), Pair(22, 16), Pair(5, 23),
        Pair(5, 13), Pair(9, 11), Pair(0, 13), Pair(-21, 6), Pair(0, 0), Pair(-34, 35), Pair(-3, 16), Pair(1, 8),
        Pair(7, 2), Pair(0, 12), Pair(5, 0), Pair(5, 28), Pair(-7, 5), Pair(4, 20), Pair(-2, 11), Pair(-1, 20),
        Pair(6, 0), Pair(3, 5), Pair(5, 9), Pair(6, 10), Pair(-1, 5), Pair(-1, 7), Pair(2, 12), Pair(0, 12),
        Pair(3, 5), Pair(4, 2), Pair(0, 5), Pair(5, 0), Pair(0, 0), Pair(-1, 9), Pair(-7, 6), Pair(-3, 9),
        Pair(2, 0), Pair(1, -4), Pair(3, 3), Pair(-2, 0), Pair(2, 2), Pair(-6, -3), Pair(-11, 1), Pair(-2, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-54, 177), Pair(80, 52), Pair(19, 50), Pair(85, 55), Pair(71, 4), Pair(23, 22), Pair(-4, 6), Pair(-61, 85),
        Pair(24, 50), Pair(60, 78), Pair(-86, 58), Pair(9, 66), Pair(-34, -12), Pair(-7, 100), Pair(44, -25), Pair(5, 60),
        Pair(44, 41), Pair(-16, 52), Pair(33, 43), Pair(-14, 92), Pair(0, 0), Pair(19, 40), Pair(8, 68), Pair(62, 44),
        Pair(25, 72), Pair(-2, 47), Pair(12, 57), Pair(-48, -50), Pair(10, 94), Pair(-18, 41), Pair(1, 57), Pair(2, 41),
        Pair(5, 39), Pair(-26, 56), Pair(15, 75), Pair(-14, 16), Pair(-3, 62), Pair(-19, 19), Pair(-7, 35), Pair(-3, 4),
        Pair(14, 77), Pair(4, 47), Pair(-6, 32), Pair(9, 68), Pair(-24, 25), Pair(0, 68), Pair(-9, 37), Pair(-3, 86),
        Pair(13, 62), Pair(-12, 89), Pair(-5, 25), Pair(7, 63), Pair(-5, 29), Pair(2, 57), Pair(-5, 17), Pair(12, 97),
        Pair(-15, 59), Pair(8, 46), Pair(-36, 45), Pair(-23, 54), Pair(24, 39), Pair(4, 52), Pair(8, 42), Pair(-21, 57)
      },
      { // Piece 2
        Pair(-44, 66), Pair(-211, 134), Pair(-240, 131), Pair(-105, 103), Pair(-125, 101), Pair(-138, 106), Pair(-99, -66), Pair(-17, 105),
        Pair(25, 22), Pair(6, 88), Pair(-65, 110), Pair(-142, 99), Pair(38, 84), Pair(-139, 45), Pair(30, 85), Pair(-17, 59),
        Pair(-14, 62), Pair(21, 54), Pair(-47, 77), Pair(-16, 104), Pair(0, 0), Pair(-47, 111), Pair(-59, 75), Pair(-10, 76),
        Pair(-30, 100), Pair(-20, 85), Pair(3, 70), Pair(-101, 60), Pair(2, 119), Pair(-44, -132), Pair(3, 77), Pair(-25, 59),
        Pair(-12, 76), Pair(28, 88), Pair(-27, 48), Pair(-23, 88), Pair(-26, 67), Pair(-10, 82), Pair(-5, 24), Pair(16, 51),
        Pair(21, 69), Pair(-46, 61), Pair(-8, 88), Pair(-16, 42), Pair(0, 80), Pair(-24, 51), Pair(-5, 100), Pair(-25, 32),
        Pair(-42, 49), Pair(-6, 88), Pair(6, 40), Pair(9, 87), Pair(-17, 54), Pair(-4, 80), Pair(-25, 49), Pair(38, -12),
        Pair(-18, 69), Pair(-22, 41), Pair(14, 92), Pair(-19, 73), Pair(34, 83), Pair(-14, 44), Pair(-38, 44), Pair(-32, 34)
      },
      { // Piece 3
        Pair(64, 73), Pair(18, 97), Pair(18, 72), Pair(37, 60), Pair(120, 56), Pair(3, 73), Pair(50, 71), Pair(-17, 93),
        Pair(13, 85), Pair(9, 96), Pair(37, 73), Pair(-13, 80), Pair(27, 97), Pair(42, 70), Pair(9, 82), Pair(-7, 92),
        Pair(41, 75), Pair(19, 69), Pair(52, 53), Pair(26, 37), Pair(0, 0), Pair(-44, 113), Pair(-14, 95), Pair(22, 52),
        Pair(-17, 78), Pair(23, 61), Pair(23, 61), Pair(-14, 9), Pair(-2, 13), Pair(-17, -27), Pair(-6, 84), Pair(-15, 68),
        Pair(11, 72), Pair(11, 61), Pair(3, 89), Pair(14, 68), Pair(-20, 38), Pair(-32, 61), Pair(9, 63), Pair(39, 37),
        Pair(-2, 70), Pair(26, 79), Pair(-6, 72), Pair(-12, 60), Pair(-24, 66), Pair(22, 36), Pair(-20, 98), Pair(9, 68),
        Pair(21, 66), Pair(-1, 73), Pair(2, 58), Pair(3, 45), Pair(16, 35), Pair(6, 52), Pair(-35, 98), Pair(7, 92),
        Pair(13, 73), Pair(13, 78), Pair(11, 74), Pair(3, 63), Pair(-8, 66), Pair(-7, 81), Pair(12, 60), Pair(5, 87)
      },
      { // Piece 4
        Pair(28, 124), Pair(80, 133), Pair(-37, 152), Pair(101, 50), Pair(63, 83), Pair(14, 124), Pair(-34, 125), Pair(111, 13),
        Pair(73, 78), Pair(59, 125), Pair(34, 180), Pair(6, 142), Pair(33, 79), Pair(59, 81), Pair(58, 102), Pair(101, 71),
        Pair(19, 167), Pair(10, 174), Pair(54, 108), Pair(11, 128), Pair(0, 0), Pair(37, 125), Pair(44, 81), Pair(80, 40),
        Pair(-6, 162), Pair(51, 127), Pair(44, 107), Pair(67, -80), Pair(98, 12), Pair(47, 49), Pair(54, 104), Pair(27, 123),
        Pair(28, 229), Pair(-1, 208), Pair(16, 138), Pair(14, 130), Pair(49, 74), Pair(29, 136), Pair(40, 90), Pair(58, 93),
        Pair(49, 96), Pair(30, 109), Pair(12, 173), Pair(19, 124), Pair(35, 119), Pair(23, 135), Pair(36, 76), Pair(34, 120),
        Pair(-2, 170), Pair(17, 159), Pair(30, 102), Pair(16, 165), Pair(50, 87), Pair(14, 134), Pair(17, 170), Pair(7, 127),
        Pair(29, 155), Pair(20, 139), Pair(21, 162), Pair(26, 138), Pair(30, 134), Pair(62, 99), Pair(48, 175), Pair(-45, 214)
      },
      { // Piece 5
        Pair(-46, -6), Pair(-3, 26), Pair(109, 12), Pair(122, -89), Pair(34, -61), Pair(22, -26), Pair(-45, -117), Pair(-57, 36),
        Pair(114, 4), Pair(189, -13), Pair(94, -15), Pair(58, -67), Pair(43, -57), Pair(157, -76), Pair(-65, -21), Pair(-142, 93),
        Pair(141, -5), Pair(225, -20), Pair(31, -13), Pair(-42, -46), Pair(0, 0), Pair(159, -85), Pair(-30, 6), Pair(137, -41),
        Pair(141, 1), Pair(-3, 26), Pair(-21, 13), Pair(7, 39), Pair(-44, -73), Pair(-2, -52), Pair(-101, 10), Pair(0, -22),
        Pair(65, -1), Pair(-67, 18), Pair(86, -42), Pair(47, -43), Pair(0, -58), Pair(-58, -22), Pair(-2, -14), Pair(0, 7),
        Pair(11, 31), Pair(8, 36), Pair(-62, 26), Pair(9, -26), Pair(-2, -39), Pair(43, -40), Pair(-65, 27), Pair(-10, 28),
        Pair(-9, 8), Pair(12, 15), Pair(6, 11), Pair(29, -14), Pair(40, -19), Pair(1, -15), Pair(-13, 15), Pair(10, 1),
        Pair(15, 6), Pair(3, 4), Pair(4, 16), Pair(29, -12), Pair(1, 19), Pair(-8, 4), Pair(4, 9), Pair(5, 19)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, 14), Pair(27, -1), Pair(6, 3), Pair(16, -14), Pair(41, -32), Pair(-112, 77), Pair(37, -3), Pair(19, -3),
        Pair(-5, 11), Pair(27, 1), Pair(-8, -4), Pair(2, 0), Pair(-15, 12), Pair(0, 0), Pair(-9, 9), Pair(-16, 15),
        Pair(3, 10), Pair(6, -3), Pair(6, 3), Pair(1, -12), Pair(-8, 24), Pair(-7, -7), Pair(4, 1), Pair(-1, 3),
        Pair(2, 2), Pair(2, -2), Pair(2, -7), Pair(3, 1), Pair(4, -3), Pair(-3, 0), Pair(-1, -4), Pair(3, 1),
        Pair(0, 1), Pair(5, -1), Pair(-2, 1), Pair(0, -2), Pair(3, -8), Pair(0, 0), Pair(-9, -3), Pair(-2, -1),
        Pair(0, -1), Pair(-3, -2), Pair(-1, -10), Pair(1, 1), Pair(-5, -18), Pair(5, -7), Pair(-3, -11), Pair(-3, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-66, 133), Pair(-61, 42), Pair(-40, 77), Pair(94, 8), Pair(160, -18), Pair(124, -36), Pair(-40, 153), Pair(101, 18),
        Pair(69, 60), Pair(74, 1), Pair(57, 36), Pair(34, -5), Pair(139, 6), Pair(13, 10), Pair(-27, 82), Pair(-98, -77),
        Pair(46, 12), Pair(39, 39), Pair(8, 34), Pair(16, 58), Pair(8, 44), Pair(0, 0), Pair(29, -28), Pair(56, 44),
        Pair(18, 40), Pair(27, 58), Pair(7, 36), Pair(22, 24), Pair(-49, -20), Pair(17, 61), Pair(-78, -14), Pair(-3, 45),
        Pair(32, 39), Pair(21, 33), Pair(-5, 35), Pair(10, 63), Pair(0, 16), Pair(10, 52), Pair(-30, -6), Pair(2, 48),
        Pair(11, 72), Pair(6, 43), Pair(17, 52), Pair(-10, 33), Pair(21, 41), Pair(-11, 24), Pair(0, 66), Pair(-14, 55),
        Pair(-26, 42), Pair(18, 1), Pair(24, 54), Pair(4, 31), Pair(15, 55), Pair(8, 31), Pair(52, 39), Pair(-48, 70),
        Pair(81, -25), Pair(13, 25), Pair(-37, 59), Pair(13, 72), Pair(-2, 53), Pair(27, 38), Pair(-9, 74), Pair(-35, 26)
      },
      { // Piece 2
        Pair(-74, 97), Pair(55, 46), Pair(-156, 119), Pair(-133, 85), Pair(-50, 93), Pair(-144, 90), Pair(-1, -10), Pair(-219, -14),
        Pair(9, 44), Pair(15, 77), Pair(-61, 62), Pair(-65, 106), Pair(-68, 77), Pair(7, 81), Pair(-113, 17), Pair(41, 121),
        Pair(17, 79), Pair(-12, 58), Pair(14, 85), Pair(-5, 30), Pair(-2, 85), Pair(0, 0), Pair(9, 68), Pair(-39, 52),
        Pair(1, 48), Pair(9, 71), Pair(31, 44), Pair(20, 72), Pair(-72, -43), Pair(6, 102), Pair(-50, -14), Pair(17, 38),
        Pair(0, 74), Pair(6, 68), Pair(16, 52), Pair(-2, 45), Pair(-2, 63), Pair(1, 44), Pair(-20, 84), Pair(-42, 36),
        Pair(0, 54), Pair(7, 64), Pair(-3, 48), Pair(8, 74), Pair(-16, 46), Pair(24, 50), Pair(-44, 31), Pair(5, 76),
        Pair(7, 44), Pair(-11, 24), Pair(6, 98), Pair(-6, 62), Pair(11, 88), Pair(2, 26), Pair(9, 74), Pair(-31, 25),
        Pair(-64, 44), Pair(36, 64), Pair(6, 50), Pair(58, 65), Pair(-60, 76), Pair(14, 82), Pair(13, 10), Pair(11, 96)
      },
      { // Piece 3
        Pair(29, 52), Pair(14, 61), Pair(9, 62), Pair(75, 36), Pair(30, 49), Pair(75, 41), Pair(85, 23), Pair(-91, 80),
        Pair(55, 39), Pair(37, 45), Pair(53, 42), Pair(102, 26), Pair(54, 39), Pair(149, 22), Pair(8, 52), Pair(78, 28),
        Pair(75, 18), Pair(38, 30), Pair(-2, 42), Pair(46, 26), Pair(16, 35), Pair(0, 0), Pair(-9, 60), Pair(44, 38),
        Pair(56, 22), Pair(18, 52), Pair(48, 42), Pair(51, 27), Pair(-7, 11), Pair(78, -5), Pair(13, -56), Pair(14, 40),
        Pair(36, 34), Pair(15, 55), Pair(19, 63), Pair(26, 40), Pair(8, 60), Pair(31, 19), Pair(-1, 41), Pair(10, 68),
        Pair(17, 60), Pair(25, 47), Pair(33, 37), Pair(-2, 65), Pair(23, 24), Pair(20, 23), Pair(23, 34), Pair(26, 37),
        Pair(30, 39), Pair(8, 54), Pair(21, 47), Pair(46, 29), Pair(-8, 54), Pair(29, 18), Pair(10, 42), Pair(4, 26),
        Pair(29, 68), Pair(21, 69), Pair(31, 51), Pair(22, 51), Pair(20, 43), Pair(22, 43), Pair(18, 34), Pair(22, 50)
      },
      { // Piece 4
        Pair(54, 54), Pair(68, 64), Pair(41, 112), Pair(-22, 136), Pair(59, 69), Pair(100, 18), Pair(83, 92), Pair(31, 46),
        Pair(28, 81), Pair(41, 102), Pair(114, 16), Pair(31, 65), Pair(20, 91), Pair(94, 64), Pair(111, -44), Pair(36, 106),
        Pair(75, -6), Pair(65, 58), Pair(63, 44), Pair(92, 36), Pair(35, 112), Pair(0, 0), Pair(45, 40), Pair(39, 121),
        Pair(32, 74), Pair(38, 102), Pair(85, 28), Pair(29, 167), Pair(-12, 74), Pair(111, 8), Pair(-7, 138), Pair(38, 117),
        Pair(60, 22), Pair(52, 128), Pair(33, 121), Pair(40, 97), Pair(21, 119), Pair(70, 57), Pair(36, 117), Pair(51, 55),
        Pair(50, 113), Pair(44, 83), Pair(35, 51), Pair(42, 77), Pair(26, 113), Pair(39, 124), Pair(28, 68), Pair(31, 109),
        Pair(25, 88), Pair(46, 36), Pair(47, 96), Pair(36, 76), Pair(41, 92), Pair(23, 162), Pair(0, 150), Pair(7, 146),
        Pair(62, 13), Pair(18, 125), Pair(24, 124), Pair(42, 104), Pair(47, 78), Pair(89, 13), Pair(105, 16), Pair(43, 104)
      },
      { // Piece 5
        Pair(-56, 59), Pair(-25, 60), Pair(-21, 7), Pair(93, 32), Pair(14, 29), Pair(-21, -13), Pair(-70, -34), Pair(40, -30),
        Pair(-83, 38), Pair(-12, 16), Pair(-197, 36), Pair(-137, 19), Pair(85, -8), Pair(53, -63), Pair(87, -74), Pair(75, -5),
        Pair(44, -34), Pair(2, 51), Pair(-61, 19), Pair(-7, -31), Pair(-70, -60), Pair(0, 0), Pair(-114, -36), Pair(-3, -11),
        Pair(-80, 17), Pair(-102, 35), Pair(-70, 25), Pair(24, -3), Pair(-150, -201), Pair(-99, -48), Pair(-10, -46), Pair(-105, 8),
        Pair(-63, 7), Pair(-40, 18), Pair(-32, 1), Pair(7, -14), Pair(-8, -13), Pair(-10, -30), Pair(-81, 7), Pair(-105, 31),
        Pair(57, -5), Pair(-11, -21), Pair(-39, 11), Pair(-7, 4), Pair(23, -23), Pair(-14, -8), Pair(-37, 8), Pair(-72, 28),
        Pair(19, -22), Pair(-1, -1), Pair(20, -11), Pair(-3, 18), Pair(2, -10), Pair(19, -2), Pair(-7, 3), Pair(-5, 19),
        Pair(-16, 17), Pair(7, -19), Pair(3, 4), Pair(10, 12), Pair(2, 13), Pair(-1, 14), Pair(-4, 14), Pair(-2, 16)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(34, -3), Pair(26, 7), Pair(-3, 22), Pair(-13, 12), Pair(-10, 12), Pair(22, -24), Pair(-24, 108), Pair(-56, 25),
        Pair(6, 3), Pair(1, 15), Pair(1, -2), Pair(32, -15), Pair(-10, 1), Pair(1, 9), Pair(0, 0), Pair(4, 13),
        Pair(8, 7), Pair(4, 9), Pair(14, -4), Pair(8, -1), Pair(8, -9), Pair(12, 21), Pair(-8, -3), Pair(46, 9),
        Pair(9, -2), Pair(7, -1), Pair(1, -3), Pair(3, -1), Pair(3, -1), Pair(10, 9), Pair(10, -6), Pair(17, 3),
        Pair(5, -8), Pair(5, 1), Pair(1, 1), Pair(6, -8), Pair(7, -3), Pair(8, 1), Pair(0, 0), Pair(10, 2),
        Pair(8, -5), Pair(1, -1), Pair(-2, -3), Pair(5, -3), Pair(4, -7), Pair(6, -5), Pair(5, -14), Pair(6, -11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(18, 120), Pair(-110, 96), Pair(-67, 80), Pair(-81, 106), Pair(83, 40), Pair(-13, 68), Pair(-104, 65), Pair(98, 20),
        Pair(21, 74), Pair(26, 51), Pair(54, 52), Pair(-12, 73), Pair(-68, 37), Pair(34, 51), Pair(-38, 34), Pair(8, 79),
        Pair(44, 53), Pair(31, 41), Pair(12, 58), Pair(-6, 51), Pair(-2, 59), Pair(36, 63), Pair(0, 0), Pair(-59, 49),
        Pair(12, 58), Pair(25, 34), Pair(33, 49), Pair(13, 50), Pair(13, 50), Pair(-37, -45), Pair(9, 82), Pair(-17, 43),
        Pair(9, 21), Pair(9, 47), Pair(11, 60), Pair(7, 48), Pair(11, 75), Pair(-1, 22), Pair(-36, 96), Pair(-48, 45),
        Pair(10, 31), Pair(30, 42), Pair(15, 45), Pair(6, 64), Pair(-3, 44), Pair(-3, 91), Pair(-23, 28), Pair(-5, 107),
        Pair(-39, 39), Pair(-21, 63), Pair(1, 22), Pair(11, 56), Pair(-3, 50), Pair(6, 92), Pair(-29, 10), Pair(4, 66),
        Pair(-26, -155), Pair(13, 49), Pair(-10, 30), Pair(33, 1), Pair(-6, 53), Pair(8, 65), Pair(-1, 76), Pair(37, 85)
      },
      { // Piece 2
        Pair(-29, 43), Pair(-36, 88), Pair(-38, 101), Pair(-55, 125), Pair(-95, 105), Pair(-57, 111), Pair(-62, 101), Pair(-67, 113),
        Pair(42, 76), Pair(10, 70), Pair(24, 86), Pair(-80, 109), Pair(-69, 143), Pair(-87, 91), Pair(13, 119), Pair(-238, -50),
        Pair(-6, 56), Pair(22, 92), Pair(-27, 91), Pair(-34, 97), Pair(-77, 77), Pair(-36, 128), Pair(0, 0), Pair(7, 89),
        Pair(25, 85), Pair(12, 58), Pair(-4, 94), Pair(-1, 74), Pair(30, 68), Pair(-62, 8), Pair(2, 93), Pair(-29, -60),
        Pair(-12, 86), Pair(22, 64), Pair(3, 72), Pair(18, 71), Pair(5, 46), Pair(6, 97), Pair(-18, 64), Pair(-24, 88),
        Pair(13, 81), Pair(5, 49), Pair(13, 99), Pair(3, 42), Pair(9, 81), Pair(-11, 72), Pair(1, 67), Pair(11, 63),
        Pair(-27, 95), Pair(23, 69), Pair(-1, 46), Pair(13, 79), Pair(-8, 56), Pair(-2, 66), Pair(11, 60), Pair(13, 69),
        Pair(25, 71), Pair(-44, 41), Pair(17, 77), Pair(21, 48), Pair(14, 72), Pair(0, 63), Pair(-43, 56), Pair(15, 85)
      },
      { // Piece 3
        Pair(49, 63), Pair(-3, 95), Pair(-65, 117), Pair(-75, 115), Pair(-53, 91), Pair(3, 88), Pair(-44, 100), Pair(15, 67),
        Pair(21, 83), Pair(10, 93), Pair(27, 79), Pair(-9, 94), Pair(40, 81), Pair(50, 61), Pair(127, 69), Pair(19, 73),
        Pair(16, 69), Pair(33, 62), Pair(27, 81), Pair(-38, 102), Pair(62, 62), Pair(-4, 73), Pair(0, 0), Pair(-32, 92),
        Pair(19, 72), Pair(28, 77), Pair(2, 90), Pair(28, 62), Pair(2, 94), Pair(-5, 20), Pair(-22, 73), Pair(10, 22),
        Pair(15, 71), Pair(18, 73), Pair(8, 84), Pair(19, 80), Pair(-13, 78), Pair(-10, 71), Pair(-13, 60), Pair(-38, 75),
        Pair(18, 75), Pair(31, 67), Pair(-4, 62), Pair(26, 78), Pair(4, 66), Pair(-6, 57), Pair(4, 86), Pair(-16, 72),
        Pair(25, 76), Pair(15, 67), Pair(25, 74), Pair(32, 64), Pair(20, 66), Pair(15, 60), Pair(24, 38), Pair(-9, 57),
        Pair(22, 96), Pair(21, 84), Pair(5, 89), Pair(8, 85), Pair(15, 76), Pair(9, 80), Pair(-6, 82), Pair(4, 65)
      },
      { // Piece 4
        Pair(17, 102), Pair(28, 103), Pair(-7, 82), Pair(-5, 143), Pair(141, 32), Pair(119, 96), Pair(133, 18), Pair(-37, 147),
        Pair(71, 92), Pair(47, 67), Pair(-18, 154), Pair(76, 89), Pair(-12, 161), Pair(53, 107), Pair(106, 73), Pair(24, 63),
        Pair(33, 89), Pair(13, 121), Pair(8, 99), Pair(14, 114), Pair(29, 95), Pair(18, 112), Pair(0, 0), Pair(15, 55),
        Pair(-6, 119), Pair(6, 112), Pair(12, 121), Pair(8, 131), Pair(10, 124), Pair(-4, 70), Pair(2, 84), Pair(-17, 95),
        Pair(7, 162), Pair(15, 129), Pair(26, 117), Pair(11, 167), Pair(10, 126), Pair(-21, 166), Pair(12, 94), Pair(13, 101),
        Pair(21, 140), Pair(24, 129), Pair(25, 123), Pair(-12, 154), Pair(-9, 163), Pair(-18, 140), Pair(13, 94), Pair(6, 152),
        Pair(19, 81), Pair(-31, 157), Pair(2, 143), Pair(0, 119), Pair(-12, 162), Pair(-6, 185), Pair(-6, 92), Pair(12, 178),
        Pair(-12, 132), Pair(8, 113), Pair(-1, 75), Pair(-1, 136), Pair(5, 138), Pair(2, 131), Pair(-5, 105), Pair(1, 138)
      },
      { // Piece 5
        Pair(288, -5), Pair(157, -5), Pair(80, 18), Pair(86, 18), Pair(24, -7), Pair(4, -13), Pair(66, -141), Pair(-8, 40),
        Pair(75, -15), Pair(42, -5), Pair(108, -42), Pair(126, -41), Pair(169, -35), Pair(44, -41), Pair(-44, -30), Pair(131, -22),
        Pair(88, -9), Pair(6, 3), Pair(-38, -2), Pair(32, -16), Pair(-32, -22), Pair(-53, -17), Pair(0, 0), Pair(28, -67),
        Pair(32, -2), Pair(68, 8), Pair(11, 18), Pair(-11, -2), Pair(-46, 8), Pair(8, 27), Pair(-145, -43), Pair(-70, -262),
        Pair(141, -34), Pair(-4, 14), Pair(39, -11), Pair(35, -8), Pair(-72, 9), Pair(-28, -12), Pair(-51, -14), Pair(-50, -17),
        Pair(78, -8), Pair(19, -28), Pair(-102, 16), Pair(13, -4), Pair(3, 2), Pair(-5, -4), Pair(-68, 1), Pair(-51, 16),
        Pair(-19, -4), Pair(10, 0), Pair(-46, 12), Pair(-9, 1), Pair(-7, 7), Pair(2, -10), Pair(13, -13), Pair(-5, -4),
        Pair(38, -50), Pair(-18, -13), Pair(-10, -4), Pair(15, -14), Pair(-6, 7), Pair(8, -5), Pair(-6, 4), Pair(-9, 13)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(4, 17), Pair(20, 17), Pair(9, 8), Pair(-26, 21), Pair(11, -2), Pair(45, -21), Pair(-55, 13), Pair(-27, -25),
        Pair(7, 12), Pair(21, -7), Pair(3, 11), Pair(16, -6), Pair(2, 1), Pair(-1, 12), Pair(-32, 12), Pair(0, 0),
        Pair(1, 3), Pair(11, 1), Pair(3, 9), Pair(0, 2), Pair(3, -2), Pair(-6, 4), Pair(-14, 1), Pair(-12, 3),
        Pair(1, -9), Pair(3, 3), Pair(-2, 1), Pair(-4, 3), Pair(3, 8), Pair(3, 9), Pair(-4, -1), Pair(-4, 2),
        Pair(4, -3), Pair(3, -3), Pair(-4, -4), Pair(-1, 2), Pair(2, -6), Pair(0, 3), Pair(-7, 0), Pair(0, 0),
        Pair(0, -8), Pair(-5, 1), Pair(-4, -12), Pair(0, -6), Pair(-5, 2), Pair(3, -2), Pair(0, -10), Pair(3, -11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-38, 93), Pair(-36, 28), Pair(-33, 47), Pair(65, 21), Pair(83, 23), Pair(-36, 48), Pair(-36, 114), Pair(131, 17),
        Pair(41, 19), Pair(-2, 44), Pair(39, 15), Pair(65, 32), Pair(89, 10), Pair(-28, -3), Pair(11, 48), Pair(9, -14),
        Pair(106, -34), Pair(56, 12), Pair(7, 31), Pair(35, 46), Pair(61, 41), Pair(-14, 71), Pair(-2, 56), Pair(0, 0),
        Pair(-1, 47), Pair(21, 37), Pair(36, 21), Pair(21, 47), Pair(16, 23), Pair(34, 11), Pair(-41, -44), Pair(37, 79),
        Pair(7, 14), Pair(39, 18), Pair(6, 29), Pair(23, 46), Pair(15, 27), Pair(26, 49), Pair(20, 27), Pair(10, 51),
        Pair(-9, 36), Pair(7, 29), Pair(6, 42), Pair(17, 33), Pair(13, 30), Pair(3, 41), Pair(20, 53), Pair(-17, 22),
        Pair(-24, 47), Pair(50, -26), Pair(11, 36), Pair(-3, 45), Pair(11, 44), Pair(-1, 26), Pair(6, 73), Pair(9, 28),
        Pair(25, 3), Pair(-6, 69), Pair(4, 9), Pair(12, 25), Pair(-2, 30), Pair(12, 19), Pair(-9, 39), Pair(16, 17)
      },
      { // Piece 2
        Pair(9, 77), Pair(-79, 84), Pair(-135, 157), Pair(-123, 74), Pair(-123, 114), Pair(-12, 80), Pair(56, 49), Pair(-26, 60),
        Pair(4, 48), Pair(12, 65), Pair(13, 60), Pair(-71, 116), Pair(-101, 108), Pair(8, 92), Pair(-56, 81), Pair(-41, 93),
        Pair(26, 83), Pair(-39, 81), Pair(2, 96), Pair(16, 69), Pair(-6, 75), Pair(-79, 95), Pair(17, 93), Pair(0, 0),
        Pair(11, 22), Pair(28, 57), Pair(-29, 71), Pair(40, 70), Pair(3, 58), Pair(-3, 95), Pair(-40, -66), Pair(19, 109),
        Pair(-4, 76), Pair(3, 66), Pair(30, 65), Pair(8, 61), Pair(7, 75), Pair(-8, 49), Pair(-2, 90), Pair(5, 33),
        Pair(6, 73), Pair(17, 82), Pair(14, 50), Pair(12, 78), Pair(-5, 42), Pair(1, 67), Pair(0, 45), Pair(15, 89),
        Pair(25, 86), Pair(10, 68), Pair(3, 79), Pair(-2, 44), Pair(8, 75), Pair(-15, 64), Pair(14, 74), Pair(14, 55),
        Pair(-16, 35), Pair(30, 97), Pair(-6, 60), Pair(-9, 87), Pair(17, 53), Pair(10, 82), Pair(-36, 108), Pair(10, 105)
      },
      { // Piece 3
        Pair(20, 109), Pair(-31, 128), Pair(-27, 118), Pair(10, 119), Pair(48, 93), Pair(38, 99), Pair(-5, 111), Pair(57, 118),
        Pair(31, 97), Pair(81, 76), Pair(36, 93), Pair(45, 88), Pair(25, 103), Pair(31, 95), Pair(-18, 115), Pair(22, 148),
        Pair(11, 106), Pair(13, 101), Pair(28, 92), Pair(8, 101), Pair(-7, 96), Pair(1, 120), Pair(56, 95), Pair(0, 0),
        Pair(-1, 113), Pair(14, 120), Pair(12, 111), Pair(29, 95), Pair(17, 95), Pair(28, 95), Pair(29, 39), Pair(3, 96),
        Pair(9, 92), Pair(21, 91), Pair(36, 95), Pair(42, 83), Pair(17, 84), Pair(19, 88), Pair(-8, 106), Pair(-8, 96),
        Pair(11, 95), Pair(42, 71), Pair(20, 89), Pair(0, 117), Pair(22, 74), Pair(15, 101), Pair(-1, 88), Pair(-1, 78),
        Pair(17, 103), Pair(44, 79), Pair(38, 86), Pair(20, 88), Pair(-3, 101), Pair(9, 89), Pair(-6, 129), Pair(-8, 93),
        Pair(15, 108), Pair(15, 92), Pair(17, 113), Pair(7, 106), Pair(17, 92), Pair(17, 83), Pair(8, 88), Pair(10, 76)
      },
      { // Piece 4
        Pair(-23, 282), Pair(13, 162), Pair(18, 163), Pair(-28, 249), Pair(31, 181), Pair(122, 114), Pair(69, 130), Pair(-59, 223),
        Pair(27, 178), Pair(11, 205), Pair(47, 172), Pair(114, 129), Pair(33, 193), Pair(44, 171), Pair(138, 138), Pair(78, 157),
        Pair(22, 242), Pair(-34, 280), Pair(54, 199), Pair(50, 138), Pair(54, 147), Pair(-3, 181), Pair(-9, 196), Pair(0, 0),
        Pair(17, 200), Pair(35, 201), Pair(4, 246), Pair(32, 220), Pair(55, 188), Pair(3, 193), Pair(30, 37), Pair(10, 217),
        Pair(32, 152), Pair(27, 220), Pair(6, 234), Pair(30, 204), Pair(24, 203), Pair(16, 202), Pair(25, 183), Pair(15, 184),
        Pair(0, 198), Pair(25, 178), Pair(15, 242), Pair(13, 185), Pair(16, 226), Pair(16, 191), Pair(26, 139), Pair(60, 25),
        Pair(30, 201), Pair(1, 203), Pair(22, 168), Pair(11, 187), Pair(12, 189), Pair(-1, 192), Pair(28, 150), Pair(6, 245),
        Pair(44, 189), Pair(6, 203), Pair(15, 218), Pair(24, 190), Pair(10, 213), Pair(23, 217), Pair(22, 129), Pair(23, 194)
      },
      { // Piece 5
        Pair(-89, -42), Pair(-66, -4), Pair(-51, -25), Pair(26, 10), Pair(73, -14), Pair(-166, -67), Pair(42, -172), Pair(-7, -149),
        Pair(157, 0), Pair(81, -26), Pair(48, -6), Pair(-32, 9), Pair(-64, 1), Pair(49, -63), Pair(-273, -30), Pair(36, -122),
        Pair(-11, 0), Pair(-70, 11), Pair(83, -24), Pair(44, 2), Pair(16, -30), Pair(25, -13), Pair(-260, 43), Pair(0, 0),
        Pair(-51, 11), Pair(61, -46), Pair(-103, 15), Pair(0, 8), Pair(92, -27), Pair(-73, 28), Pair(-79, -103), Pair(20, -53),
        Pair(80, -43), Pair(48, -28), Pair(-7, -20), Pair(2, -8), Pair(8, 6), Pair(-71, 5), Pair(27, -22), Pair(-47, -19),
        Pair(14, 26), Pair(61, -40), Pair(62, -28), Pair(2, 6), Pair(10, 3), Pair(-32, 19), Pair(-27, 3), Pair(0, -27),
        Pair(13, -28), Pair(1, 3), Pair(-17, -6), Pair(2, -7), Pair(-5, 12), Pair(2, 11), Pair(-3, 4), Pair(12, -13),
        Pair(-18, 23), Pair(-10, -5), Pair(5, -12), Pair(2, 1), Pair(0, 11), Pair(-1, 23), Pair(11, 8), Pair(12, 21)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(-16, -1), Pair(-13, -11), Pair(9, 24), Pair(8, 7), Pair(-5, 14), Pair(39, 9), Pair(10, 37),
        Pair(-13, -24), Pair(11, -27), Pair(3, 3), Pair(-2, 0), Pair(12, 3), Pair(12, 4), Pair(-5, 13), Pair(-1, 23),
        Pair(-11, -8), Pair(-9, 12), Pair(2, -5), Pair(2, 6), Pair(9, 5), Pair(0, 3), Pair(2, 4), Pair(0, 16),
        Pair(-4, 0), Pair(-4, 7), Pair(2, 1), Pair(-1, 0), Pair(5, 4), Pair(0, 13), Pair(-4, 8), Pair(4, 7),
        Pair(-4, 8), Pair(-3, 7), Pair(5, 3), Pair(-6, -1), Pair(-1, 2), Pair(0, 2), Pair(-6, 7), Pair(-2, 5),
        Pair(0, 0), Pair(1, -2), Pair(3, -5), Pair(-7, 2), Pair(2, -13), Pair(-5, 2), Pair(-12, 1), Pair(-2, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-48, -108), Pair(126, 8), Pair(-101, 65), Pair(152, 34), Pair(8, 85), Pair(-77, 32), Pair(-16, 24), Pair(36, -5),
        Pair(0, 0), Pair(66, 29), Pair(-7, 88), Pair(9, 78), Pair(38, 62), Pair(36, 37), Pair(61, 65), Pair(46, 34),
        Pair(59, 104), Pair(-63, 13), Pair(-49, 100), Pair(2, 69), Pair(72, 40), Pair(4, 66), Pair(49, 18), Pair(2, 44),
        Pair(20, 87), Pair(-8, 75), Pair(20, 58), Pair(26, 49), Pair(34, 44), Pair(14, 47), Pair(19, 46), Pair(32, 27),
        Pair(-14, 28), Pair(-1, 66), Pair(15, 47), Pair(14, 62), Pair(22, 36), Pair(21, 37), Pair(5, 64), Pair(27, 39),
        Pair(0, 83), Pair(0, 89), Pair(6, 59), Pair(7, 47), Pair(4, 59), Pair(14, 47), Pair(17, 68), Pair(16, 45),
        Pair(-3, 40), Pair(-26, 42), Pair(-16, 70), Pair(7, 58), Pair(7, 61), Pair(-4, 58), Pair(44, 12), Pair(-21, 92),
        Pair(-75, 47), Pair(-4, 52), Pair(13, 13), Pair(-8, 53), Pair(15, 42), Pair(11, 27), Pair(6, 42), Pair(-23, 34)
      },
      { // Piece 2
        Pair(-11, 72), Pair(-96, 130), Pair(7, 126), Pair(-146, 136), Pair(-57, 148), Pair(-32, 136), Pair(-59, 164), Pair(-7, 33),
        Pair(0, 0), Pair(-16, 92), Pair(-6, 86), Pair(-60, 134), Pair(-35, 102), Pair(-85, 148), Pair(4, 139), Pair(-40, 121),
        Pair(56, 66), Pair(-56, 49), Pair(-3, 97), Pair(39, 98), Pair(-22, 144), Pair(5, 106), Pair(-13, 106), Pair(11, 101),
        Pair(51, 87), Pair(-21, 124), Pair(9, 98), Pair(8, 90), Pair(29, 113), Pair(25, 105), Pair(24, 77), Pair(-14, 99),
        Pair(-28, 101), Pair(-14, 89), Pair(-6, 95), Pair(-5, 101), Pair(28, 79), Pair(29, 92), Pair(-51, 110), Pair(4, 49),
        Pair(17, 116), Pair(-19, 113), Pair(10, 93), Pair(10, 84), Pair(7, 86), Pair(6, 90), Pair(21, 77), Pair(1, 95),
        Pair(54, 77), Pair(12, 109), Pair(-10, 109), Pair(14, 86), Pair(-10, 93), Pair(-1, 91), Pair(8, 84), Pair(32, 135),
        Pair(18, 82), Pair(14, 75), Pair(8, 94), Pair(18, 63), Pair(-8, 97), Pair(2, 90), Pair(33, 92), Pair(-16, 78)
      },
      { // Piece 3
        Pair(-151, 242), Pair(-30, 167), Pair(1, 169), Pair(19, 138), Pair(-20, 170), Pair(-4, 148), Pair(36, 156), Pair(42, 173),
        Pair(0, 0), Pair(-17, 171), Pair(-20, 185), Pair(-7, 181), Pair(-10, 181), Pair(19, 152), Pair(13, 158), Pair(-3, 157),
        Pair(-10, 156), Pair(9, -182), Pair(-10, 173), Pair(-10, 163), Pair(26, 169), Pair(0, 148), Pair(-26, 171), Pair(-15, 169),
        Pair(-38, 167), Pair(-16, 179), Pair(0, 156), Pair(-3, 156), Pair(-7, 133), Pair(17, 141), Pair(22, 146), Pair(30, 144),
        Pair(-37, 164), Pair(-34, 128), Pair(-2, 152), Pair(-28, 159), Pair(-26, 142), Pair(-30, 160), Pair(30, 131), Pair(5, 152),
        Pair(-12, 118), Pair(-2, 146), Pair(-1, 134), Pair(-3, 145), Pair(34, 108), Pair(11, 148), Pair(16, 160), Pair(3, 155),
        Pair(-14, 112), Pair(-8, 132), Pair(4, 134), Pair(-19, 138), Pair(-2, 138), Pair(4, 130), Pair(2, 152), Pair(6, 138),
        Pair(-17, 124), Pair(-16, 134), Pair(-16, 158), Pair(-4, 144), Pair(-8, 137), Pair(-10, 154), Pair(-4, 154), Pair(0, 166)
      },
      { // Piece 4
        Pair(-79, 418), Pair(50, 346), Pair(56, 253), Pair(-17, 360), Pair(13, 331), Pair(67, 288), Pair(-15, 385), Pair(29, 352),
        Pair(0, 0), Pair(8, 317), Pair(0, 360), Pair(32, 306), Pair(23, 275), Pair(51, 319), Pair(8, 344), Pair(12, 325),
        Pair(79, 271), Pair(-124, -66), Pair(9, 320), Pair(36, 302), Pair(49, 333), Pair(12, 305), Pair(21, 375), Pair(67, 260),
        Pair(31, 350), Pair(36, 230), Pair(65, 264), Pair(0, 336), Pair(32, 301), Pair(28, 316), Pair(23, 387), Pair(18, 378),
        Pair(53, 215), Pair(51, 242), Pair(39, 262), Pair(25, 299), Pair(38, 283), Pair(38, 295), Pair(33, 297), Pair(32, 320),
        Pair(22, 339), Pair(28, 283), Pair(41, 249), Pair(21, 311), Pair(30, 282), Pair(38, 286), Pair(45, 266), Pair(31, 315),
        Pair(35, 292), Pair(22, 313), Pair(32, 283), Pair(24, 285), Pair(32, 250), Pair(12, 296), Pair(56, 291), Pair(25, 279),
        Pair(72, 222), Pair(33, 267), Pair(15, 303), Pair(17, 328), Pair(34, 198), Pair(-10, 345), Pair(37, 250), Pair(-52, 435)
      },
      { // Piece 5
        Pair(29, 19), Pair(-9, 29), Pair(51, -41), Pair(40, 54), Pair(76, -15), Pair(52, -66), Pair(4, 1), Pair(47, -44),
        Pair(0, 0), Pair(-89, -75), Pair(-159, 65), Pair(-47, -3), Pair(-9, -41), Pair(125, 58), Pair(11, 31), Pair(38, 19),
        Pair(-170, 26), Pair(0, 0), Pair(-272, 49), Pair(-118, 43), Pair(-51, -11), Pair(0, 1), Pair(-76, 36), Pair(-67, -28),
        Pair(-162, 13), Pair(-168, 16), Pair(-124, -8), Pair(-115, 48), Pair(-14, 4), Pair(-100, -3), Pair(-37, 0), Pair(-19, -6),
        Pair(-260, 33), Pair(-145, 6), Pair(-19, -9), Pair(-10, -21), Pair(31, -20), Pair(-11, -14), Pair(12, -8), Pair(57, -64),
        Pair(-65, 1), Pair(-117, 13), Pair(25, -12), Pair(-33, 3), Pair(12, -21), Pair(15, -10), Pair(-8, 0), Pair(14, -15),
        Pair(-35, 36), Pair(-67, 16), Pair(-11, 6), Pair(2, -5), Pair(-6, 0), Pair(24, -28), Pair(11, -6), Pair(14, -13),
        Pair(7, 23), Pair(11, -5), Pair(6, -4), Pair(-7, -13), Pair(9, -16), Pair(8, -19), Pair(10, -14), Pair(24, -34)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-77, 9), Pair(0, 0), Pair(-14, 16), Pair(-34, 51), Pair(18, 11), Pair(-29, 9), Pair(37, -12), Pair(19, 17),
        Pair(35, -12), Pair(-15, -30), Pair(2, -15), Pair(11, -17), Pair(7, -5), Pair(13, 1), Pair(7, 12), Pair(-4, 11),
        Pair(19, 0), Pair(-14, -13), Pair(-1, 19), Pair(2, 0), Pair(3, 9), Pair(3, 14), Pair(2, 11), Pair(8, 13),
        Pair(13, 4), Pair(-9, -6), Pair(5, 14), Pair(-3, -1), Pair(1, 3), Pair(-2, 14), Pair(3, 12), Pair(7, 9),
        Pair(3, 9), Pair(-7, 0), Pair(-5, 10), Pair(-5, 0), Pair(0, 10), Pair(1, 1), Pair(-1, 4), Pair(-4, -1),
        Pair(1, -2), Pair(0, 0), Pair(-1, 2), Pair(0, 0), Pair(-3, -2), Pair(-4, -1), Pair(-3, -2), Pair(-1, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(62, 138), Pair(-142, -104), Pair(27, 50), Pair(-207, 58), Pair(17, 13), Pair(-171, 75), Pair(-81, 12), Pair(15, 171),
        Pair(-15, 59), Pair(0, 0), Pair(0, 74), Pair(-8, 32), Pair(19, 55), Pair(40, 76), Pair(-2, 84), Pair(-41, 84),
        Pair(59, -85), Pair(10, 97), Pair(-199, 105), Pair(25, 50), Pair(1, 82), Pair(11, 41), Pair(-8, 93), Pair(47, 69),
        Pair(29, 35), Pair(7, 79), Pair(7, 40), Pair(25, 51), Pair(8, 50), Pair(20, 58), Pair(15, 47), Pair(29, 67),
        Pair(-14, 83), Pair(29, 27), Pair(1, 65), Pair(-5, 73), Pair(10, 68), Pair(20, 50), Pair(9, 35), Pair(32, 45),
        Pair(-1, 105), Pair(-5, 76), Pair(5, 77), Pair(5, 64), Pair(16, 40), Pair(6, 68), Pair(27, 38), Pair(6, 69),
        Pair(-34, 122), Pair(-6, 137), Pair(13, 39), Pair(9, 55), Pair(8, 55), Pair(6, 64), Pair(-2, 62), Pair(4, 64),
        Pair(-43, 93), Pair(2, 91), Pair(-5, 71), Pair(16, 39), Pair(11, 35), Pair(2, 73), Pair(6, 88), Pair(32, -40)
      },
      { // Piece 2
        Pair(0, 0), Pair(-46, 145), Pair(-98, 118), Pair(-101, 136), Pair(-188, 137), Pair(-29, 129), Pair(-37, 79), Pair(26, 118),
        Pair(19, 33), Pair(0, 0), Pair(-21, 125), Pair(-35, 101), Pair(12, 140), Pair(-53, 117), Pair(36, 126), Pair(5, 78),
        Pair(-49, 117), Pair(-1, 125), Pair(-348, 41), Pair(-6, 119), Pair(-17, 100), Pair(6, 114), Pair(0, 85), Pair(-2, 81),
        Pair(15, 73), Pair(-28, 96), Pair(-20, 116), Pair(5, 75), Pair(11, 111), Pair(-4, 107), Pair(12, 107), Pair(-32, 122),
        Pair(-46, 58), Pair(-13, 100), Pair(-14, 76), Pair(0, 89), Pair(-21, 82), Pair(9, 104), Pair(-13, 111), Pair(5, 106),
        Pair(25, 90), Pair(-3, 120), Pair(1, 86), Pair(-10, 86), Pair(9, 76), Pair(-7, 89), Pair(7, 88), Pair(3, 95),
        Pair(4, 104), Pair(21, 88), Pair(1, 98), Pair(5, 103), Pair(-12, 85), Pair(0, 79), Pair(-5, 91), Pair(16, 90),
        Pair(0, 91), Pair(3, 102), Pair(16, 97), Pair(-26, 114), Pair(-1, 94), Pair(-7, 93), Pair(-92, 85), Pair(-27, 99)
      },
      { // Piece 3
        Pair(-28, 119), Pair(-44, 169), Pair(-35, 130), Pair(-36, 160), Pair(76, 107), Pair(-15, 147), Pair(-28, 160), Pair(27, 142),
        Pair(-83, 155), Pair(0, 0), Pair(-13, 153), Pair(17, 151), Pair(68, 123), Pair(-3, 139), Pair(-62, 158), Pair(-24, 151),
        Pair(-83, 13), Pair(26, 112), Pair(-30, -9), Pair(-8, 157), Pair(11, 147), Pair(26, 122), Pair(-34, 139), Pair(12, 119),
        Pair(-17, 127), Pair(8, 137), Pair(-65, 130), Pair(7, 113), Pair(15, 105), Pair(22, 108), Pair(1, 119), Pair(2, 127),
        Pair(5, 80), Pair(2, 111), Pair(-40, 95), Pair(1, 96), Pair(-20, 115), Pair(-13, 120), Pair(-19, 120), Pair(0, 125),
        Pair(-19, 104), Pair(-5, 126), Pair(-39, 130), Pair(-6, 121), Pair(23, 95), Pair(1, 121), Pair(11, 113), Pair(-1, 116),
        Pair(-31, 162), Pair(10, 97), Pair(-12, 114), Pair(1, 126), Pair(-13, 130), Pair(-14, 120), Pair(-1, 120), Pair(13, 116),
        Pair(-13, 125), Pair(-5, 108), Pair(-29, 133), Pair(3, 121), Pair(-4, 133), Pair(-2, 129), Pair(7, 127), Pair(9, 127)
      },
      { // Piece 4
        Pair(20, 134), Pair(-75, 296), Pair(73, 223), Pair(-15, 250), Pair(94, 99), Pair(84, 231), Pair(-18, 221), Pair(6, 263),
        Pair(71, 129), Pair(0, 0), Pair(64, 174), Pair(52, 191), Pair(46, 204), Pair(14, 243), Pair(23, 226), Pair(44, 158),
        Pair(68, 72), Pair(35, 184), Pair(-123, -98), Pair(57, 191), Pair(18, 201), Pair(12, 227), Pair(22, 255), Pair(65, 157),
        Pair(10, 229), Pair(47, 175), Pair(25, 238), Pair(-15, 296), Pair(27, 256), Pair(53, 174), Pair(39, 201), Pair(42, 211),
        Pair(19, 160), Pair(48, 151), Pair(-1, 210), Pair(12, 219), Pair(12, 237), Pair(13, 249), Pair(13, 219), Pair(6, 226),
        Pair(14, 136), Pair(28, 169), Pair(16, 246), Pair(10, 207), Pair(28, 198), Pair(12, 219), Pair(29, 259), Pair(44, 204),
        Pair(28, 185), Pair(38, 188), Pair(19, 229), Pair(17, 226), Pair(9, 243), Pair(28, 183), Pair(20, 189), Pair(18, 234),
        Pair(39, 132), Pair(34, 171), Pair(14, 180), Pair(16, 189), Pair(34, 176), Pair(26, 188), Pair(64, 87), Pair(8, 279)
      },
      { // Piece 5
        Pair(-11, -56), Pair(23, -98), Pair(-55, 3), Pair(21, 47), Pair(-14, -68), Pair(64, -45), Pair(7, 30), Pair(41, -26),
        Pair(12, -49), Pair(0, 0), Pair(-5, -84), Pair(52, 13), Pair(-46, -32), Pair(33, -14), Pair(130, -36), Pair(65, 4),
        Pair(0, 0), Pair(-92, -39), Pair(0, 0), Pair(28, -7), Pair(-120, 25), Pair(6, -15), Pair(67, 0), Pair(79, 34),
        Pair(-83, -23), Pair(-35, -60), Pair(-60, -19), Pair(-88, -22), Pair(-44, 11), Pair(-34, 14), Pair(-105, 18), Pair(-24, 42),
        Pair(-108, -29), Pair(-115, -1), Pair(-79, -21), Pair(-72, 15), Pair(-21, -24), Pair(-31, 4), Pair(-21, 12), Pair(-26, -7),
        Pair(-49, -21), Pair(-38, -4), Pair(-27, -5), Pair(-49, 7), Pair(17, -7), Pair(15, -2), Pair(-33, 2), Pair(-16, 1),
        Pair(-29, 4), Pair(-18, -8), Pair(-16, -5), Pair(9, -11), Pair(-2, -4), Pair(12, -7), Pair(9, -18), Pair(8, -17),
        Pair(25, -17), Pair(3, 5), Pair(8, -3), Pair(16, -19), Pair(10, 1), Pair(23, -23), Pair(-2, -19), Pair(18, -7)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(12, -16), Pair(-20, -16), Pair(0, 0), Pair(5, 3), Pair(10, -9), Pair(-19, 67), Pair(4, 39), Pair(-22, 38),
        Pair(2, 13), Pair(13, 52), Pair(-15, -22), Pair(30, 12), Pair(-2, -7), Pair(0, 22), Pair(5, 29), Pair(8, 20),
        Pair(-5, 4), Pair(8, 6), Pair(-6, -10), Pair(3, 15), Pair(2, 9), Pair(7, 8), Pair(5, 6), Pair(3, 19),
        Pair(-5, 6), Pair(4, -1), Pair(-10, 2), Pair(-1, 18), Pair(-4, 4), Pair(2, 9), Pair(7, 8), Pair(4, 8),
        Pair(-4, 9), Pair(-1, -1), Pair(-5, 3), Pair(-1, -2), Pair(-3, -1), Pair(-2, 10), Pair(0, 4), Pair(1, 6),
        Pair(-7, 8), Pair(-3, -5), Pair(0, 0), Pair(1, 5), Pair(-2, 5), Pair(-4, 2), Pair(3, -9), Pair(1, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(28, -64), Pair(-56, 114), Pair(-191, 25), Pair(-125, 85), Pair(68, -47), Pair(-1, 121), Pair(-130, 124), Pair(-63, -17),
        Pair(21, 37), Pair(17, 42), Pair(0, 0), Pair(-20, 78), Pair(46, 22), Pair(22, 12), Pair(-21, 63), Pair(-20, 104),
        Pair(-52, 70), Pair(51, -192), Pair(-15, 89), Pair(-150, 137), Pair(14, 39), Pair(-6, 64), Pair(21, 74), Pair(39, 16),
        Pair(-14, 66), Pair(-19, 14), Pair(9, 97), Pair(-26, 34), Pair(-1, 65), Pair(-4, 36), Pair(3, 51), Pair(9, 47),
        Pair(-10, 72), Pair(-2, 45), Pair(2, 47), Pair(-28, 80), Pair(7, 42), Pair(-8, 87), Pair(3, 66), Pair(-1, 54),
        Pair(-7, 52), Pair(2, 73), Pair(-10, 72), Pair(8, 79), Pair(-19, 54), Pair(-4, 62), Pair(-1, 55), Pair(4, 100),
        Pair(30, -64), Pair(37, 92), Pair(4, 34), Pair(-2, 64), Pair(-11, 66), Pair(1, 64), Pair(13, 23), Pair(-24, 18),
        Pair(16, -7), Pair(-9, 76), Pair(6, 52), Pair(-13, 122), Pair(23, 69), Pair(-36, 97), Pair(-7, 79), Pair(-14, 27)
      },
      { // Piece 2
        Pair(54, 78), Pair(-245, -155), Pair(-33, 96), Pair(-281, 178), Pair(-121, 140), Pair(-187, 130), Pair(-84, 104), Pair(-20, 109),
        Pair(15, 3), Pair(-2, 48), Pair(0, 0), Pair(-60, 111), Pair(-55, 117), Pair(23, 113), Pair(-40, 115), Pair(37, 116),
        Pair(-4, 52), Pair(33, -167), Pair(34, 84), Pair(-246, -7), Pair(-12, 92), Pair(-27, 95), Pair(-43, 112), Pair(-22, 58),
        Pair(-9, 68), Pair(-12, 76), Pair(-35, 74), Pair(-16, 83), Pair(-7, 76), Pair(-16, 70), Pair(-7, 93), Pair(11, 76),
        Pair(-10, 124), Pair(-29, 84), Pair(-7, 101), Pair(-43, 89), Pair(-4, 94), Pair(-7, 71), Pair(-3, 94), Pair(6, 65),
        Pair(-7, 56), Pair(-14, 94), Pair(-20, 89), Pair(-8, 80), Pair(-25, 84), Pair(3, 98), Pair(-1, 79), Pair(0, 93),
        Pair(-4, 127), Pair(-12, 65), Pair(11, 88), Pair(-11, 87), Pair(-9, 88), Pair(-7, 64), Pair(7, 84), Pair(-10, 24),
        Pair(-34, 118), Pair(-33, 94), Pair(-15, 87), Pair(13, 82), Pair(5, 89), Pair(-5, 104), Pair(-35, 142), Pair(17, 33)
      },
      { // Piece 3
        Pair(8, 58), Pair(58, 72), Pair(-38, 124), Pair(-21, 99), Pair(-3, 126), Pair(-14, 112), Pair(-75, 123), Pair(-20, 107),
        Pair(-4, 77), Pair(-45, 63), Pair(0, 0), Pair(-21, 102), Pair(43, 82), Pair(-34, 101), Pair(-21, 89), Pair(51, 57),
        Pair(-25, 83), Pair(48, -27), Pair(-26, 89), Pair(-136, 35), Pair(32, 67), Pair(-30, 124), Pair(22, 54), Pair(-16, 86),
        Pair(0, 83), Pair(-73, 104), Pair(-19, 95), Pair(-57, 120), Pair(3, 86), Pair(-30, 100), Pair(1, 103), Pair(2, 82),
        Pair(-20, 78), Pair(-40, 92), Pair(-14, 90), Pair(-22, 94), Pair(-1, 95), Pair(-28, 108), Pair(-8, 86), Pair(-15, 94),
        Pair(0, 63), Pair(-14, 60), Pair(-10, 61), Pair(-16, 79), Pair(3, 78), Pair(-4, 95), Pair(0, 79), Pair(7, 78),
        Pair(-16, 56), Pair(-27, 76), Pair(-45, 100), Pair(-26, 70), Pair(-3, 90), Pair(-24, 94), Pair(-3, 96), Pair(-6, 98),
        Pair(-15, 88), Pair(-24, 67), Pair(-15, 75), Pair(-7, 57), Pair(-9, 85), Pair(-13, 95), Pair(-1, 77), Pair(-4, 96)
      },
      { // Piece 4
        Pair(51, 56), Pair(-57, 199), Pair(82, 95), Pair(103, 40), Pair(34, 154), Pair(2, 210), Pair(-47, 175), Pair(-31, 178),
        Pair(80, 83), Pair(56, 108), Pair(0, 0), Pair(12, 152), Pair(1, 152), Pair(22, 103), Pair(5, 121), Pair(34, 75),
        Pair(47, 115), Pair(-28, 22), Pair(99, 81), Pair(65, 3), Pair(52, 55), Pair(30, 134), Pair(35, 88), Pair(24, 92),
        Pair(12, 118), Pair(-5, 193), Pair(64, 116), Pair(6, 186), Pair(23, 121), Pair(-26, 199), Pair(30, 139), Pair(25, 150),
        Pair(16, 175), Pair(27, 163), Pair(27, 119), Pair(16, 155), Pair(14, 131), Pair(11, 117), Pair(10, 141), Pair(8, 195),
        Pair(-9, 302), Pair(1, 255), Pair(24, 162), Pair(7, 150), Pair(6, 163), Pair(7, 178), Pair(12, 139), Pair(52, 65),
        Pair(27, 167), Pair(-1, 190), Pair(37, 118), Pair(12, 170), Pair(12, 161), Pair(6, 127), Pair(23, 121), Pair(21, 111),
        Pair(9, 182), Pair(11, 74), Pair(14, 152), Pair(7, 160), Pair(4, 122), Pair(0, 123), Pair(-1, 243), Pair(9, 203)
      },
      { // Piece 5
        Pair(6, 49), Pair(-119, -163), Pair(17, -115), Pair(-14, 5), Pair(25, 37), Pair(-10, -70), Pair(31, -25), Pair(-53, 50),
        Pair(-97, -25), Pair(-41, -60), Pair(0, 0), Pair(-5, -7), Pair(-176, -4), Pair(9, 39), Pair(-68, 70), Pair(32, -35),
        Pair(61, 16), Pair(0, 0), Pair(-205, -14), Pair(0, 0), Pair(-170, 40), Pair(-27, 5), Pair(-73, -3), Pair(-135, 41),
        Pair(-208, 5), Pair(-241, 32), Pair(-197, -26), Pair(-307, 37), Pair(-131, -8), Pair(-87, 29), Pair(-68, -20), Pair(56, -4),
        Pair(-196, 79), Pair(-221, 35), Pair(-192, 33), Pair(-212, 14), Pair(-65, 12), Pair(7, -16), Pair(-33, 4), Pair(-142, 19),
        Pair(-2, -4), Pair(-92, 20), Pair(-29, -23), Pair(-26, -13), Pair(-5, -5), Pair(12, -5), Pair(-40, 19), Pair(-30, 7),
        Pair(12, -1), Pair(15, -22), Pair(-3, -17), Pair(4, -10), Pair(-3, -9), Pair(8, -11), Pair(-9, -8), Pair(8, -23),
        Pair(-7, 11), Pair(3, -14), Pair(0, -7), Pair(12, -15), Pair(9, -8), Pair(9, -14), Pair(0, 2), Pair(7, -22)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, 23), Pair(-46, 0), Pair(16, -15), Pair(0, 0), Pair(-38, -30), Pair(111, -19), Pair(13, 5), Pair(30, 41),
        Pair(-2, 13), Pair(19, -16), Pair(-12, 23), Pair(37, -39), Pair(11, -5), Pair(7, 13), Pair(-10, 17), Pair(4, 11),
        Pair(3, 14), Pair(3, 6), Pair(18, 13), Pair(9, -9), Pair(13, 9), Pair(0, 7), Pair(1, 4), Pair(7, 14),
        Pair(7, 3), Pair(-2, 5), Pair(11, -3), Pair(-4, 4), Pair(4, 9), Pair(-6, 6), Pair(9, -7), Pair(4, 6),
        Pair(3, 4), Pair(-1, -2), Pair(1, 5), Pair(-1, 5), Pair(-1, -2), Pair(-1, -5), Pair(-7, 1), Pair(-1, 3),
        Pair(4, -6), Pair(3, 0), Pair(1, -3), Pair(0, 0), Pair(0, -13), Pair(-4, 1), Pair(-4, -13), Pair(3, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(63, 8), Pair(28, -127), Pair(-107, 32), Pair(-37, -115), Pair(3, 33), Pair(-143, -16), Pair(-135, 140), Pair(131, 120),
        Pair(8, 22), Pair(-78, 58), Pair(-2, 31), Pair(0, 0), Pair(-66, -8), Pair(-74, 71), Pair(-2, 102), Pair(-40, 108),
        Pair(-2, 33), Pair(12, 75), Pair(-190, -75), Pair(3, 71), Pair(-33, -5), Pair(-33, 38), Pair(-4, 2), Pair(28, 30),
        Pair(41, -37), Pair(16, 13), Pair(-13, -40), Pair(21, 18), Pair(-28, -1), Pair(-35, 91), Pair(-13, 8), Pair(19, 32),
        Pair(6, 15), Pair(1, 28), Pair(-13, 77), Pair(-5, 16), Pair(-1, 47), Pair(9, 0), Pair(21, 0), Pair(2, 53),
        Pair(-5, 53), Pair(-12, 5), Pair(5, 43), Pair(-19, 31), Pair(3, 35), Pair(-11, 20), Pair(10, -7), Pair(0, 40),
        Pair(11, 84), Pair(56, -51), Pair(9, -24), Pair(-7, 36), Pair(14, -13), Pair(-21, 75), Pair(0, 21), Pair(-39, 35),
        Pair(-81, -98), Pair(8, 34), Pair(11, 46), Pair(5, 2), Pair(-22, 82), Pair(20, 62), Pair(3, -4), Pair(-9, 19)
      },
      { // Piece 2
        Pair(-31, 60), Pair(-44, 89), Pair(49, 27), Pair(14, 31), Pair(-239, 151), Pair(-16, 35), Pair(39, 14), Pair(7, 154),
        Pair(-73, 85), Pair(-20, 41), Pair(27, 44), Pair(0, 0), Pair(-87, 89), Pair(-17, 97), Pair(35, 28), Pair(3, 24),
        Pair(-61, 11), Pair(-54, 52), Pair(-120, -57), Pair(46, 96), Pair(-90, -1), Pair(2, 29), Pair(-49, 141), Pair(29, 29),
        Pair(-4, 61), Pair(-26, 104), Pair(-9, 65), Pair(23, 15), Pair(-20, 82), Pair(-51, 51), Pair(-3, 47), Pair(10, 97),
        Pair(-15, 78), Pair(-7, 43), Pair(-20, 75), Pair(-20, 89), Pair(-14, 47), Pair(-7, 51), Pair(-29, 41), Pair(25, 31),
        Pair(7, 94), Pair(-38, 124), Pair(-14, 125), Pair(-19, 67), Pair(7, 32), Pair(-9, 29), Pair(-8, 37), Pair(-8, 0),
        Pair(28, 15), Pair(1, 92), Pair(-30, 114), Pair(12, 69), Pair(-21, 54), Pair(10, 24), Pair(-18, 46), Pair(13, 45),
        Pair(-24, 128), Pair(-44, 42), Pair(10, 49), Pair(-32, 124), Pair(-35, 154), Pair(-16, 61), Pair(-28, 30), Pair(-47, 132)
      },
      { // Piece 3
        Pair(-14, 34), Pair(-89, 62), Pair(43, -14), Pair(39, 17), Pair(103, -11), Pair(-88, 81), Pair(-15, 40), Pair(22, 49),
        Pair(-7, 30), Pair(-55, 79), Pair(-44, 25), Pair(0, 0), Pair(-27, 82), Pair(22, 9), Pair(-30, 29), Pair(-18, 24),
        Pair(34, 0), Pair(-9, 37), Pair(-19, -71), Pair(24, 33), Pair(-84, 55), Pair(-18, -9), Pair(-4, 43), Pair(14, 32),
        Pair(-25, 49), Pair(-6, 53), Pair(-17, 46), Pair(79, 12), Pair(8, 42), Pair(-2, 15), Pair(29, 59), Pair(12, 60),
        Pair(1, 55), Pair(-2, 79), Pair(-18, 42), Pair(4, 25), Pair(-22, 40), Pair(-21, 74), Pair(-9, 50), Pair(-18, 75),
        Pair(2, 83), Pair(11, 39), Pair(0, -2), Pair(10, 53), Pair(-28, 64), Pair(-25, 77), Pair(-11, 82), Pair(-1, 90),
        Pair(-12, 57), Pair(-28, 52), Pair(-18, 56), Pair(-18, 55), Pair(-2, -14), Pair(-29, 24), Pair(2, 47), Pair(2, -14),
        Pair(-6, 46), Pair(-6, 56), Pair(-22, 42), Pair(-10, 39), Pair(-23, 52), Pair(-10, 60), Pair(-8, 42), Pair(-6, 55)
      },
      { // Piece 4
        Pair(-41, 87), Pair(-33, 114), Pair(9, 42), Pair(219, -118), Pair(-75, 132), Pair(-80, 191), Pair(-24, 110), Pair(23, 113),
        Pair(-9, 55), Pair(-62, 99), Pair(42, -12), Pair(0, 0), Pair(49, 55), Pair(54, 42), Pair(8, 96), Pair(40, 30),
        Pair(19, 19), Pair(92, 14), Pair(49, -5), Pair(77, 96), Pair(18, 9), Pair(0, -20), Pair(19, 28), Pair(20, 96),
        Pair(-26, 125), Pair(3, 93), Pair(8, 4), Pair(68, 90), Pair(18, 77), Pair(23, -26), Pair(-7, 122), Pair(30, 94),
        Pair(6, 1), Pair(48, 47), Pair(8, 85), Pair(26, 18), Pair(25, 41), Pair(12, 68), Pair(5, 67), Pair(19, 89),
        Pair(1, 108), Pair(6, 21), Pair(29, -38), Pair(12, 58), Pair(22, 39), Pair(4, 38), Pair(12, 43), Pair(34, -24),
        Pair(8, 41), Pair(1, 115), Pair(8, 30), Pair(20, 44), Pair(1, 78), Pair(0, 65), Pair(18, 15), Pair(21, 23),
        Pair(22, -48), Pair(25, 55), Pair(-4, -57), Pair(21, 20), Pair(1, 97), Pair(-19, 94), Pair(13, -45), Pair(-15, 60)
      },
      { // Piece 5
        Pair(3, 49), Pair(15, -44), Pair(38, 88), Pair(-21, -53), Pair(-10, 6), Pair(11, 6), Pair(30, 10), Pair(-59, -130),
        Pair(19, 14), Pair(-18, -13), Pair(29, -80), Pair(0, 0), Pair(-84, -97), Pair(13, -73), Pair(-30, -21), Pair(-42, -62),
        Pair(-39, -30), Pair(-49, 73), Pair(0, 0), Pair(-95, -44), Pair(0, 0), Pair(64, -60), Pair(135, -28), Pair(24, -1),
        Pair(-93, -15), Pair(105, -62), Pair(-106, -9), Pair(-2, -76), Pair(134, -26), Pair(-22, 14), Pair(14, 4), Pair(-92, 73),
        Pair(33, 23), Pair(75, -30), Pair(152, -68), Pair(-31, 8), Pair(56, 9), Pair(2, 3), Pair(-3, 8), Pair(168, 27),
        Pair(-291, 71), Pair(0, -39), Pair(24, 12), Pair(-4, 3), Pair(-14, 4), Pair(38, 11), Pair(17, -5), Pair(-28, 22),
        Pair(-66, 8), Pair(-7, 22), Pair(-42, 3), Pair(1, 20), Pair(-20, 13), Pair(7, 35), Pair(0, 9), Pair(1, -7),
        Pair(-18, 28), Pair(-4, 30), Pair(6, 15), Pair(13, -3), Pair(-1, 11), Pair(14, 7), Pair(-3, 15), Pair(-8, 6)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 25), Pair(45, 7), Pair(3, -17), Pair(71, 53), Pair(0, 0), Pair(4, 124), Pair(24, 21), Pair(29, 19),
        Pair(1, 27), Pair(14, 3), Pair(8, 16), Pair(13, 38), Pair(4, -20), Pair(-12, 18), Pair(-1, 0), Pair(25, 5),
        Pair(6, 11), Pair(6, 5), Pair(6, 14), Pair(18, 15), Pair(0, 16), Pair(15, 23), Pair(7, -3), Pair(6, 11),
        Pair(1, 7), Pair(4, -3), Pair(2, 3), Pair(6, 2), Pair(-5, 8), Pair(11, 12), Pair(3, 13), Pair(4, 4),
        Pair(1, 8), Pair(6, 8), Pair(2, -3), Pair(5, 9), Pair(-5, 0), Pair(2, 17), Pair(-5, 10), Pair(4, -2),
        Pair(2, 9), Pair(1, 4), Pair(3, -2), Pair(3, 15), Pair(0, 0), Pair(0, 6), Pair(-6, 1), Pair(-2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(42, 71), Pair(4, 33), Pair(258, -55), Pair(80, 21), Pair(4, 20), Pair(60, 42), Pair(-42, 36), Pair(135, -114),
        Pair(23, 9), Pair(16, -1), Pair(-16, 54), Pair(98, 26), Pair(0, 0), Pair(7, 124), Pair(66, 47), Pair(13, 65),
        Pair(-22, 86), Pair(15, 36), Pair(24, 28), Pair(5, -8), Pair(72, 24), Pair(-299, 304), Pair(2, 57), Pair(107, 29),
        Pair(4, 72), Pair(5, 32), Pair(7, 68), Pair(-19, 21), Pair(25, 88), Pair(-6, -6), Pair(19, 31), Pair(15, -10),
        Pair(26, -6), Pair(14, 0), Pair(22, 40), Pair(-11, 42), Pair(6, 34), Pair(-6, 56), Pair(25, 15), Pair(12, 20),
        Pair(14, 59), Pair(4, 32), Pair(0, 28), Pair(17, 55), Pair(-23, 23), Pair(6, 67), Pair(-9, 13), Pair(0, 49),
        Pair(21, -76), Pair(14, 11), Pair(6, -17), Pair(8, 26), Pair(9, 28), Pair(15, 44), Pair(1, 61), Pair(2, 99),
        Pair(54, 27), Pair(12, 17), Pair(-9, -30), Pair(4, 45), Pair(29, 82), Pair(-20, 47), Pair(16, 40), Pair(-17, 10)
      },
      { // Piece 2
        Pair(1, 121), Pair(-154, 75), Pair(-73, 161), Pair(-147, 12), Pair(-84, 70), Pair(-151, 16), Pair(-58, 160), Pair(18, 52),
        Pair(-19, 73), Pair(-3, 59), Pair(5, 27), Pair(-28, 100), Pair(0, 0), Pair(-13, 14), Pair(-31, 105), Pair(10, 66),
        Pair(15, 85), Pair(13, 52), Pair(-4, 67), Pair(-88, 20), Pair(32, 90), Pair(-230, 0), Pair(-21, 106), Pair(-5, 65),
        Pair(-82, 51), Pair(13, 63), Pair(-42, 40), Pair(-26, 84), Pair(4, 51), Pair(-27, 121), Pair(-20, 23), Pair(10, 26),
        Pair(27, 46), Pair(-24, 57), Pair(4, 57), Pair(-7, 34), Pair(-4, 92), Pair(-21, 39), Pair(17, 113), Pair(-20, 58),
        Pair(0, 14), Pair(-15, 79), Pair(-8, 43), Pair(13, 82), Pair(-12, 43), Pair(18, 54), Pair(-26, 80), Pair(6, 83),
        Pair(-17, 115), Pair(-26, 58), Pair(4, 89), Pair(-6, 38), Pair(20, 84), Pair(-3, 44), Pair(7, 88), Pair(-7, 58),
        Pair(-68, 100), Pair(9, 48), Pair(-7, 60), Pair(22, 24), Pair(-35, 66), Pair(17, 81), Pair(-65, 81), Pair(-1, -45)
      },
      { // Piece 3
        Pair(-21, 59), Pair(-78, 72), Pair(-51, 58), Pair(3, 46), Pair(-104, 110), Pair(228, -22), Pair(-79, 81), Pair(24, 86),
        Pair(-6, 31), Pair(54, 23), Pair(10, 62), Pair(-43, 65), Pair(0, 0), Pair(-55, 24), Pair(-9, -2), Pair(-23, 63),
        Pair(52, 29), Pair(24, -1), Pair(4, 30), Pair(-92, 7), Pair(-13, 39), Pair(-49, -137), Pair(-25, 18), Pair(56, 23),
        Pair(-4, 43), Pair(31, 36), Pair(16, 49), Pair(-56, 69), Pair(-35, 89), Pair(-5, 58), Pair(-41, 79), Pair(13, 16),
        Pair(4, 85), Pair(-34, 78), Pair(-27, 67), Pair(-4, 25), Pair(-6, 51), Pair(0, 22), Pair(0, 50), Pair(17, 50),
        Pair(-10, 85), Pair(15, 95), Pair(-23, 87), Pair(-40, 47), Pair(-21, 68), Pair(-3, 53), Pair(-19, 85), Pair(5, 73),
        Pair(17, 72), Pair(-1, 100), Pair(-10, 42), Pair(-14, 21), Pair(-41, 70), Pair(19, 29), Pair(-14, 61), Pair(-3, 18),
        Pair(11, 57), Pair(17, 31), Pair(12, 50), Pair(9, 12), Pair(-6, 39), Pair(-11, 67), Pair(12, 50), Pair(6, 35)
      },
      { // Piece 4
        Pair(53, 8), Pair(57, 10), Pair(-55, 136), Pair(-18, -63), Pair(-112, 2), Pair(-28, 53), Pair(40, 178), Pair(49, -59),
        Pair(60, -82), Pair(72, -4), Pair(69, -48), Pair(15, 63), Pair(0, 0), Pair(-27, -23), Pair(20, 85), Pair(97, 25),
        Pair(22, 52), Pair(-20, 103), Pair(47, -23), Pair(90, 12), Pair(113, -31), Pair(78, 34), Pair(3, -39), Pair(47, -46),
        Pair(14, 40), Pair(0, 92), Pair(39, -52), Pair(-19, 103), Pair(42, -48), Pair(17, 25), Pair(32, 12), Pair(4, 9),
        Pair(9, 74), Pair(6, 46), Pair(18, 119), Pair(11, 76), Pair(20, 51), Pair(4, -4), Pair(3, -5), Pair(34, 22),
        Pair(8, 52), Pair(2, 68), Pair(-19, 110), Pair(-4, 111), Pair(5, 42), Pair(-7, 41), Pair(-1, 52), Pair(-15, -17),
        Pair(12, 106), Pair(2, 57), Pair(4, 85), Pair(3, 45), Pair(21, 60), Pair(0, 117), Pair(22, 47), Pair(-26, -100),
        Pair(-15, 131), Pair(-2, 95), Pair(15, 41), Pair(1, 59), Pair(2, 158), Pair(24, 122), Pair(13, 222), Pair(46, -86)
      },
      { // Piece 5
        Pair(19, 156), Pair(14, 5), Pair(-15, -96), Pair(12, 66), Pair(-45, -139), Pair(16, -58), Pair(27, 110), Pair(1, -21),
        Pair(1, 69), Pair(13, 28), Pair(-21, -32), Pair(-52, -42), Pair(0, 0), Pair(-34, -34), Pair(-190, -120), Pair(-43, -14),
        Pair(-66, -22), Pair(-60, -3), Pair(-32, 14), Pair(0, 0), Pair(-2, -47), Pair(0, 0), Pair(-106, 46), Pair(127, -58),
        Pair(95, -62), Pair(-15, 18), Pair(-97, 11), Pair(-110, 38), Pair(39, -92), Pair(-84, -39), Pair(-355, 13), Pair(-151, 35),
        Pair(-166, 100), Pair(-2, 25), Pair(20, -11), Pair(-202, 39), Pair(-76, -25), Pair(-140, -4), Pair(-11, -1), Pair(-4, -18),
        Pair(52, 4), Pair(-38, 42), Pair(59, -16), Pair(46, -20), Pair(-29, -30), Pair(-42, -12), Pair(49, -48), Pair(-56, 23),
        Pair(-84, 38), Pair(-22, -5), Pair(-8, 24), Pair(8, -7), Pair(29, -4), Pair(-4, 7), Pair(6, -6), Pair(4, -11),
        Pair(58, 83), Pair(-14, 3), Pair(-9, 21), Pair(0, -4), Pair(-2, 2), Pair(-17, 7), Pair(8, -7), Pair(-15, -21)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(18, 21), Pair(19, 13), Pair(7, 27), Pair(-3, 14), Pair(-41, 27), Pair(0, 0), Pair(-5, -20), Pair(-3, 16),
        Pair(1, 14), Pair(30, 10), Pair(-1, 7), Pair(12, 4), Pair(50, -9), Pair(-14, 0), Pair(35, 20), Pair(-1, 12),
        Pair(8, 4), Pair(13, 6), Pair(5, 6), Pair(6, 0), Pair(11, 17), Pair(-10, 8), Pair(-2, 10), Pair(-1, 5),
        Pair(12, 7), Pair(9, 2), Pair(5, 2), Pair(3, -7), Pair(7, 11), Pair(-9, 13), Pair(2, 9), Pair(2, 13),
        Pair(7, -3), Pair(10, 1), Pair(1, 2), Pair(10, 1), Pair(6, 9), Pair(-2, 13), Pair(-5, 12), Pair(-2, 4),
        Pair(6, 6), Pair(5, 2), Pair(2, -2), Pair(3, 0), Pair(2, -2), Pair(0, 0), Pair(-5, -1), Pair(-2, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(61, 39), Pair(37, 69), Pair(-141, 121), Pair(-160, 100), Pair(-59, 135), Pair(-103, 14), Pair(121, 100), Pair(154, -209),
        Pair(21, 74), Pair(72, 41), Pair(11, 61), Pair(-28, 104), Pair(37, 40), Pair(0, 0), Pair(-4, 54), Pair(-81, 55),
        Pair(20, 49), Pair(12, 82), Pair(22, 83), Pair(26, 41), Pair(-75, -56), Pair(17, 101), Pair(-100, 30), Pair(22, 52),
        Pair(20, 80), Pair(17, 86), Pair(-9, 80), Pair(9, 77), Pair(-20, 50), Pair(33, 90), Pair(-45, 48), Pair(19, 69),
        Pair(29, 58), Pair(-5, 52), Pair(-3, 79), Pair(13, 78), Pair(-7, 76), Pair(-2, 59), Pair(5, 69), Pair(-12, 70),
        Pair(6, 86), Pair(-5, 87), Pair(9, 88), Pair(-5, 81), Pair(25, 79), Pair(-10, 82), Pair(14, 91), Pair(-11, 97),
        Pair(4, 37), Pair(44, 47), Pair(17, 68), Pair(-1, 88), Pair(3, 81), Pair(12, 65), Pair(4, 69), Pair(-32, 68),
        Pair(-19, 99), Pair(3, 114), Pair(-14, 95), Pair(15, 79), Pair(27, 62), Pair(-11, 122), Pair(1, 94), Pair(25, 83)
      },
      { // Piece 2
        Pair(-36, 103), Pair(-16, 114), Pair(-91, 105), Pair(-26, 108), Pair(-178, 120), Pair(-145, 155), Pair(-116, -14), Pair(34, 50),
        Pair(-37, 108), Pair(-36, 104), Pair(2, 111), Pair(-48, 99), Pair(-42, 114), Pair(0, 0), Pair(-26, 95), Pair(21, 47),
        Pair(-36, 108), Pair(-16, 91), Pair(-41, 113), Pair(-17, 101), Pair(-202, 72), Pair(74, 104), Pair(-23, -24), Pair(-7, 96),
        Pair(27, 87), Pair(-11, 97), Pair(8, 92), Pair(-18, 89), Pair(-25, 115), Pair(-16, 107), Pair(6, 99), Pair(-28, 80),
        Pair(-9, 102), Pair(8, 106), Pair(-26, 86), Pair(19, 88), Pair(-35, 80), Pair(12, 98), Pair(-56, 97), Pair(-5, 99),
        Pair(10, 97), Pair(-25, 109), Pair(16, 103), Pair(-22, 86), Pair(6, 81), Pair(-17, 93), Pair(-17, 98), Pair(-24, 71),
        Pair(-45, 91), Pair(13, 89), Pair(-16, 98), Pair(8, 113), Pair(-23, 82), Pair(16, 80), Pair(-17, 88), Pair(-2, 82),
        Pair(-3, 67), Pair(-23, 69), Pair(14, 109), Pair(1, 98), Pair(-17, 87), Pair(-13, 90), Pair(-38, 125), Pair(-8, 118)
      },
      { // Piece 3
        Pair(2, 107), Pair(-46, 139), Pair(-76, 146), Pair(-40, 131), Pair(-49, 114), Pair(-43, 108), Pair(46, 99), Pair(-109, 128),
        Pair(27, 94), Pair(-20, 117), Pair(-12, 119), Pair(10, 105), Pair(-37, 108), Pair(0, 0), Pair(-35, 123), Pair(-30, 93),
        Pair(32, 90), Pair(5, 86), Pair(-70, 131), Pair(12, 101), Pair(-12, 31), Pair(32, 92), Pair(135, -208), Pair(1, 96),
        Pair(25, 105), Pair(-13, 109), Pair(-6, 115), Pair(-1, 101), Pair(-20, 131), Pair(14, 106), Pair(12, 83), Pair(-6, 109),
        Pair(16, 92), Pair(14, 102), Pair(1, 117), Pair(-8, 106), Pair(1, 100), Pair(10, 98), Pair(-3, 80), Pair(17, 97),
        Pair(7, 115), Pair(1, 103), Pair(14, 81), Pair(-6, 104), Pair(5, 97), Pair(-11, 118), Pair(16, 89), Pair(12, 87),
        Pair(14, 98), Pair(14, 121), Pair(19, 110), Pair(14, 111), Pair(-13, 105), Pair(1, 90), Pair(17, 91), Pair(4, 98),
        Pair(12, 119), Pair(14, 92), Pair(12, 104), Pair(11, 100), Pair(2, 100), Pair(9, 101), Pair(4, 92), Pair(14, 93)
      },
      { // Piece 4
        Pair(-7, 234), Pair(-13, 221), Pair(-31, 188), Pair(22, 212), Pair(-28, 102), Pair(99, 107), Pair(26, 162), Pair(52, 153),
        Pair(22, 146), Pair(-6, 203), Pair(23, 175), Pair(-50, 213), Pair(7, 168), Pair(0, 0), Pair(77, 151), Pair(34, 135),
        Pair(28, 111), Pair(4, 169), Pair(-13, 185), Pair(51, 156), Pair(18, 26), Pair(104, 84), Pair(39, 122), Pair(68, 128),
        Pair(19, 176), Pair(-1, 177), Pair(6, 232), Pair(15, 196), Pair(59, 161), Pair(22, 204), Pair(34, 172), Pair(39, 141),
        Pair(24, 136), Pair(14, 176), Pair(-10, 211), Pair(28, 191), Pair(19, 186), Pair(48, 157), Pair(28, 209), Pair(23, 196),
        Pair(9, 207), Pair(21, 158), Pair(21, 166), Pair(3, 171), Pair(19, 188), Pair(24, 178), Pair(21, 182), Pair(10, 211),
        Pair(-22, 188), Pair(12, 185), Pair(24, 171), Pair(19, 161), Pair(14, 177), Pair(14, 183), Pair(6, 202), Pair(15, 153),
        Pair(31, 105), Pair(2, 156), Pair(27, 113), Pair(17, 152), Pair(23, 108), Pair(60, 114), Pair(10, 207), Pair(0, 166)
      },
      { // Piece 5
        Pair(-46, -26), Pair(65, -34), Pair(100, -23), Pair(16, 6), Pair(-88, -9), Pair(129, 11), Pair(-21, -60), Pair(-60, -39),
        Pair(122, -31), Pair(63, -7), Pair(-120, 38), Pair(17, -57), Pair(-60, -51), Pair(0, 0), Pair(40, -105), Pair(-71, -33),
        Pair(22, 15), Pair(-130, -8), Pair(-72, -11), Pair(-190, -3), Pair(0, 0), Pair(-158, -35), Pair(0, 0), Pair(-118, -3),
        Pair(-5, -29), Pair(-116, 42), Pair(-108, 14), Pair(-83, -21), Pair(-142, -4), Pair(-33, -36), Pair(13, -64), Pair(-58, -31),
        Pair(14, -21), Pair(-53, 13), Pair(19, -16), Pair(35, -1), Pair(-20, -28), Pair(-48, -23), Pair(-79, -3), Pair(-72, -9),
        Pair(33, -35), Pair(-67, 14), Pair(-54, 24), Pair(-68, 19), Pair(-25, -6), Pair(-2, -11), Pair(-19, -8), Pair(-33, 9),
        Pair(22, -24), Pair(-19, 4), Pair(-8, 14), Pair(2, -2), Pair(-18, -6), Pair(1, 10), Pair(7, -12), Pair(12, -9),
        Pair(-37, 44), Pair(-9, -11), Pair(-24, 13), Pair(-6, -17), Pair(-7, -8), Pair(-3, 7), Pair(-4, -3), Pair(10, -4)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, 25), Pair(25, 17), Pair(54, -4), Pair(6, -12), Pair(-12, 8), Pair(-34, 17), Pair(0, 0), Pair(6, 2),
        Pair(1, 9), Pair(12, 8), Pair(6, -9), Pair(19, -4), Pair(-8, 15), Pair(31, 5), Pair(15, -7), Pair(25, 13),
        Pair(7, 11), Pair(7, 4), Pair(13, 6), Pair(9, 2), Pair(11, 1), Pair(9, 14), Pair(-5, 5), Pair(12, 24),
        Pair(13, 4), Pair(8, 1), Pair(5, 10), Pair(1, -1), Pair(3, 4), Pair(12, 23), Pair(4, 1), Pair(-1, 14),
        Pair(8, -5), Pair(4, -2), Pair(-2, -2), Pair(5, -10), Pair(3, -2), Pair(4, 16), Pair(-10, 7), Pair(0, 10),
        Pair(3, -5), Pair(0, 0), Pair(-5, 2), Pair(2, 10), Pair(3, 0), Pair(2, 1), Pair(0, 0), Pair(-3, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-57, 45), Pair(-43, 45), Pair(-182, 96), Pair(-86, 152), Pair(-127, 81), Pair(-107, 141), Pair(17, 59), Pair(57, 150),
        Pair(49, 17), Pair(-19, 111), Pair(23, 62), Pair(-78, 123), Pair(-62, 86), Pair(4, 81), Pair(0, 0), Pair(39, -24),
        Pair(-23, 66), Pair(7, 65), Pair(27, 85), Pair(-13, 82), Pair(-10, 51), Pair(-45, 77), Pair(11, 88), Pair(1, 18),
        Pair(50, 62), Pair(28, 33), Pair(-2, 93), Pair(26, 46), Pair(17, 90), Pair(-30, 56), Pair(12, 81), Pair(-8, 45),
        Pair(3, 45), Pair(1, 62), Pair(13, 67), Pair(4, 65), Pair(12, 67), Pair(-3, 60), Pair(-14, 80), Pair(-42, 64),
        Pair(7, 57), Pair(30, 46), Pair(11, 52), Pair(12, 73), Pair(2, 61), Pair(1, 79), Pair(-14, 67), Pair(-5, 106),
        Pair(-10, 12), Pair(-8, 60), Pair(6, 54), Pair(8, 77), Pair(1, 56), Pair(3, 66), Pair(6, 49), Pair(9, 44),
        Pair(-2, -103), Pair(12, 51), Pair(-15, 50), Pair(44, 25), Pair(-8, 72), Pair(4, 76), Pair(1, 75), Pair(24, 92)
      },
      { // Piece 2
        Pair(16, 104), Pair(-43, 106), Pair(-19, 105), Pair(-194, 137), Pair(-24, 142), Pair(-88, 133), Pair(-17, 85), Pair(1, 0),
        Pair(43, 75), Pair(46, 89), Pair(-31, 113), Pair(-16, 122), Pair(-150, 156), Pair(-48, 144), Pair(0, 0), Pair(52, 51),
        Pair(21, 53), Pair(-30, 98), Pair(-11, 119), Pair(-57, 106), Pair(-14, 99), Pair(-237, 59), Pair(6, 108), Pair(-42, 10),
        Pair(-25, 86), Pair(33, 94), Pair(-45, 106), Pair(17, 105), Pair(1, 78), Pair(-22, 100), Pair(-22, 81), Pair(5, 86),
        Pair(21, 118), Pair(-36, 103), Pair(18, 97), Pair(-19, 68), Pair(20, 90), Pair(-17, 76), Pair(-8, 97), Pair(-50, 68),
        Pair(-5, 73), Pair(13, 98), Pair(-6, 79), Pair(23, 77), Pair(-21, 69), Pair(5, 95), Pair(-23, 95), Pair(21, 99),
        Pair(4, 129), Pair(-12, 65), Pair(51, 69), Pair(-17, 95), Pair(9, 98), Pair(2, 59), Pair(22, 96), Pair(-19, 142),
        Pair(-8, 45), Pair(18, 97), Pair(-14, 95), Pair(44, 89), Pair(-19, 62), Pair(14, 102), Pair(-30, 91), Pair(29, 65)
      },
      { // Piece 3
        Pair(63, 112), Pair(-3, 140), Pair(-42, 142), Pair(-54, 149), Pair(9, 117), Pair(-34, 135), Pair(16, 125), Pair(-2, 102),
        Pair(16, 122), Pair(2, 135), Pair(-4, 135), Pair(-16, 143), Pair(-16, 142), Pair(-66, 134), Pair(0, 0), Pair(-111, 113),
        Pair(41, 110), Pair(-15, 138), Pair(21, 122), Pair(-4, 137), Pair(32, 94), Pair(135, -61), Pair(5, 127), Pair(128, -56),
        Pair(0, 131), Pair(24, 104), Pair(17, 125), Pair(-33, 133), Pair(12, 114), Pair(-36, 137), Pair(4, 129), Pair(-32, 101),
        Pair(25, 114), Pair(-5, 136), Pair(8, 132), Pair(-12, 129), Pair(-25, 121), Pair(-33, 127), Pair(-48, 122), Pair(-35, 121),
        Pair(18, 124), Pair(36, 112), Pair(-21, 123), Pair(15, 100), Pair(15, 104), Pair(-19, 90), Pair(3, 108), Pair(8, 94),
        Pair(18, 94), Pair(6, 111), Pair(4, 128), Pair(1, 118), Pair(10, 113), Pair(1, 107), Pair(29, 79), Pair(-16, 106),
        Pair(25, 128), Pair(16, 111), Pair(5, 137), Pair(10, 104), Pair(12, 113), Pair(6, 108), Pair(5, 119), Pair(0, 95)
      },
      { // Piece 4
        Pair(15, 103), Pair(-35, 210), Pair(37, 174), Pair(-10, 106), Pair(-1, 176), Pair(89, 34), Pair(-111, 245), Pair(-41, 193),
        Pair(50, 98), Pair(53, 109), Pair(3, 154), Pair(-1, 178), Pair(19, 109), Pair(3, 99), Pair(0, 0), Pair(34, 121),
        Pair(38, 104), Pair(17, 132), Pair(16, 170), Pair(17, 146), Pair(16, 125), Pair(8, -165), Pair(-2, 166), Pair(101, -57),
        Pair(-1, 118), Pair(14, 130), Pair(3, 178), Pair(-4, 157), Pair(1, 151), Pair(-8, 160), Pair(30, 97), Pair(-1, 124),
        Pair(10, 158), Pair(11, 98), Pair(27, 151), Pair(5, 158), Pair(3, 192), Pair(-17, 210), Pair(19, 115), Pair(13, 125),
        Pair(23, 163), Pair(23, 158), Pair(16, 108), Pair(-2, 143), Pair(-10, 176), Pair(-9, 161), Pair(19, 124), Pair(21, 120),
        Pair(27, 77), Pair(-11, 150), Pair(1, 128), Pair(-8, 156), Pair(-13, 194), Pair(-14, 197), Pair(14, 48), Pair(-22, 173),
        Pair(-1, 108), Pair(-4, 143), Pair(-2, 82), Pair(2, 134), Pair(2, 139), Pair(-10, 175), Pair(20, 43), Pair(16, 176)
      },
      { // Piece 5
        Pair(35, -76), Pair(10, -18), Pair(62, -52), Pair(116, 56), Pair(110, 9), Pair(94, 36), Pair(99, -79), Pair(10, 27),
        Pair(-138, -36), Pair(65, -14), Pair(12, -8), Pair(68, -1), Pair(100, -61), Pair(-14, -49), Pair(0, 0), Pair(64, -120),
        Pair(205, -41), Pair(60, -2), Pair(-137, 20), Pair(-102, 1), Pair(-208, 8), Pair(0, 0), Pair(29, -93), Pair(0, 0),
        Pair(38, 23), Pair(-7, -2), Pair(86, -27), Pair(-113, -7), Pair(-149, -4), Pair(-139, -2), Pair(-136, -18), Pair(-165, -19),
        Pair(78, 15), Pair(19, -33), Pair(32, -5), Pair(-11, -16), Pair(-23, -14), Pair(-62, -22), Pair(-90, -15), Pair(-109, -7),
        Pair(24, -37), Pair(98, -36), Pair(-34, -12), Pair(-11, -8), Pair(-24, -3), Pair(-28, -13), Pair(-63, -6), Pair(-16, -15),
        Pair(1, 13), Pair(34, -38), Pair(-11, -7), Pair(-6, -15), Pair(-8, -6), Pair(9, -14), Pair(-1, -6), Pair(-6, -12),
        Pair(24, -34), Pair(-3, -16), Pair(0, -21), Pair(10, -14), Pair(4, -10), Pair(5, -6), Pair(-11, 5), Pair(-11, 14)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(25, 18), Pair(39, 36), Pair(40, -8), Pair(-33, 27), Pair(-44, 39), Pair(34, -23), Pair(-25, -33), Pair(0, 0),
        Pair(7, 8), Pair(28, -4), Pair(-4, 6), Pair(18, 9), Pair(2, -1), Pair(-12, -8), Pair(7, 14), Pair(22, -17),
        Pair(7, 3), Pair(11, 4), Pair(6, 12), Pair(3, 4), Pair(1, -2), Pair(1, -7), Pair(-11, 18), Pair(-1, -6),
        Pair(5, 5), Pair(1, 4), Pair(0, -1), Pair(-2, 10), Pair(2, 6), Pair(2, 4), Pair(-5, 9), Pair(-3, 2),
        Pair(4, 3), Pair(1, -5), Pair(-1, 0), Pair(-4, 0), Pair(6, -2), Pair(1, 6), Pair(-9, 13), Pair(-5, 4),
        Pair(-3, 0), Pair(-4, -6), Pair(-1, -8), Pair(-4, 2), Pair(0, -1), Pair(7, 2), Pair(1, -1), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-54, 56), Pair(-62, 88), Pair(-36, 84), Pair(-33, 59), Pair(-7, 47), Pair(-126, 43), Pair(-15, 47), Pair(49, -222),
        Pair(63, 9), Pair(18, 84), Pair(20, 42), Pair(65, 48), Pair(44, 38), Pair(0, 73), Pair(30, 57), Pair(0, 0),
        Pair(-15, 26), Pair(13, 45), Pair(29, 43), Pair(29, 44), Pair(70, 35), Pair(19, 29), Pair(-9, -10), Pair(49, 45),
        Pair(9, 42), Pair(27, 42), Pair(11, 54), Pair(22, 57), Pair(10, 67), Pair(19, 49), Pair(-14, 40), Pair(39, 76),
        Pair(15, 36), Pair(28, 37), Pair(7, 48), Pair(20, 42), Pair(8, 72), Pair(24, 52), Pair(0, 56), Pair(-10, 45),
        Pair(-11, 45), Pair(11, 43), Pair(11, 61), Pair(8, 66), Pair(6, 47), Pair(4, 56), Pair(16, 71), Pair(-6, 57),
        Pair(-12, 31), Pair(1, 20), Pair(16, 36), Pair(4, 71), Pair(11, 42), Pair(9, 40), Pair(-18, 48), Pair(5, 51),
        Pair(26, 76), Pair(0, 61), Pair(29, 8), Pair(-6, 57), Pair(13, 45), Pair(-9, 64), Pair(0, 49), Pair(14, -51)
      },
      { // Piece 2
        Pair(59, 126), Pair(68, 59), Pair(-58, 117), Pair(-30, 88), Pair(-188, 152), Pair(-160, 106), Pair(-53, 137), Pair(4, 84),
        Pair(54, 46), Pair(-16, 115), Pair(-11, 82), Pair(-63, 131), Pair(-27, 94), Pair(-29, 100), Pair(-10, 71), Pair(0, 0),
        Pair(26, 88), Pair(-33, 96), Pair(-12, 124), Pair(21, 109), Pair(-9, 95), Pair(-25, 110), Pair(-66, -16), Pair(53, 84),
        Pair(21, 32), Pair(14, 82), Pair(-29, 102), Pair(35, 91), Pair(9, 80), Pair(4, 80), Pair(-8, 76), Pair(10, 87),
        Pair(-10, 110), Pair(21, 78), Pair(21, 82), Pair(11, 98), Pair(-9, 101), Pair(6, 79), Pair(-1, 49), Pair(-11, 79),
        Pair(4, 95), Pair(22, 76), Pair(23, 66), Pair(-2, 91), Pair(10, 73), Pair(-9, 100), Pair(-14, 83), Pair(22, 88),
        Pair(25, 70), Pair(17, 78), Pair(-13, 109), Pair(8, 67), Pair(2, 82), Pair(-3, 77), Pair(9, 80), Pair(22, 41),
        Pair(-1, 108), Pair(-10, 120), Pair(8, 89), Pair(-25, 113), Pair(7, 73), Pair(2, 85), Pair(-44, 72), Pair(-14, 121)
      },
      { // Piece 3
        Pair(50, 135), Pair(-33, 172), Pair(0, 147), Pair(15, 158), Pair(-16, 164), Pair(-3, 140), Pair(48, 124), Pair(-47, 193),
        Pair(50, 138), Pair(83, 128), Pair(37, 143), Pair(-2, 153), Pair(10, 147), Pair(47, 144), Pair(9, 170), Pair(0, 0),
        Pair(31, 153), Pair(-11, 161), Pair(2, 171), Pair(33, 146), Pair(24, 116), Pair(7, 144), Pair(-30, -65), Pair(7, 159),
        Pair(31, 152), Pair(22, 154), Pair(7, 156), Pair(12, 161), Pair(22, 137), Pair(9, 148), Pair(-28, 153), Pair(10, 153),
        Pair(6, 156), Pair(4, 149), Pair(31, 125), Pair(34, 124), Pair(-8, 152), Pair(18, 130), Pair(-6, 129), Pair(0, 135),
        Pair(28, 136), Pair(32, 137), Pair(11, 150), Pair(-4, 147), Pair(23, 149), Pair(-6, 162), Pair(2, 105), Pair(6, 145),
        Pair(26, 124), Pair(27, 143), Pair(55, 106), Pair(18, 137), Pair(6, 125), Pair(14, 145), Pair(-3, 125), Pair(-6, 128),
        Pair(21, 145), Pair(22, 132), Pair(31, 136), Pair(10, 146), Pair(18, 141), Pair(17, 134), Pair(-2, 137), Pair(14, 125)
      },
      { // Piece 4
        Pair(-14, 310), Pair(-91, 325), Pair(61, 245), Pair(-47, 298), Pair(52, 203), Pair(70, 149), Pair(-67, 231), Pair(-135, 438),
        Pair(17, 280), Pair(4, 323), Pair(14, 300), Pair(-18, 327), Pair(16, 328), Pair(-16, 306), Pair(10, 278), Pair(0, 0),
        Pair(3, 279), Pair(-47, 382), Pair(2, 317), Pair(31, 230), Pair(-13, 266), Pair(-65, 373), Pair(86, 68), Pair(16, 196),
        Pair(13, 225), Pair(21, 258), Pair(-2, 303), Pair(17, 257), Pair(20, 272), Pair(-20, 283), Pair(-11, 246), Pair(20, 181),
        Pair(18, 260), Pair(10, 277), Pair(0, 285), Pair(-1, 308), Pair(29, 219), Pair(6, 250), Pair(9, 221), Pair(4, 239),
        Pair(-19, 293), Pair(18, 221), Pair(-2, 309), Pair(-12, 239), Pair(5, 269), Pair(3, 240), Pair(3, 191), Pair(27, 113),
        Pair(18, 229), Pair(9, 207), Pair(12, 246), Pair(3, 269), Pair(3, 248), Pair(2, 259), Pair(-9, 212), Pair(-12, 238),
        Pair(42, 202), Pair(1, 197), Pair(18, 237), Pair(12, 243), Pair(-4, 268), Pair(-8, 288), Pair(18, 280), Pair(27, 313)
      },
      { // Piece 5
        Pair(-101, -82), Pair(31, 25), Pair(145, -3), Pair(-70, 20), Pair(-30, -41), Pair(50, -73), Pair(-17, -21), Pair(-34, -79),
        Pair(-109, 58), Pair(52, -9), Pair(-55, 85), Pair(-137, 24), Pair(-10, 17), Pair(-165, -3), Pair(-49, -67), Pair(0, 0),
        Pair(81, 25), Pair(6, 5), Pair(-30, 21), Pair(-163, 42), Pair(-102, -6), Pair(-196, 18), Pair(0, 0), Pair(-154, 39),
        Pair(-77, -51), Pair(-25, 7), Pair(-53, 23), Pair(-56, 6), Pair(-94, 10), Pair(-72, 26), Pair(-180, 9), Pair(-39, -34),
        Pair(-31, -62), Pair(19, -19), Pair(12, -2), Pair(11, -5), Pair(-37, -2), Pair(-16, 0), Pair(-109, 9), Pair(-30, -36),
        Pair(30, -13), Pair(71, -33), Pair(91, -24), Pair(-48, 7), Pair(-17, 4), Pair(9, -2), Pair(-36, 4), Pair(-19, -16),
        Pair(20, -25), Pair(12, -32), Pair(-12, -8), Pair(4, 0), Pair(-10, 4), Pair(1, -1), Pair(-11, 8), Pair(2, 9),
        Pair(6, -21), Pair(0, -19), Pair(5, -15), Pair(9, -7), Pair(7, -5), Pair(7, 4), Pair(9, 2), Pair(2, 31)
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
        Pair(42, -27), Pair(6, 127), Pair(-83, 61), Pair(87, -6), Pair(87, 75), Pair(-121, 87), Pair(13, 77), Pair(168, -5),
        Pair(-34, -29), Pair(-34, 31), Pair(78, -20), Pair(191, -20), Pair(-70, 72), Pair(-86, 59), Pair(-124, 27), Pair(34, 12),
        Pair(10, -11), Pair(10, 71), Pair(-62, 40), Pair(11, -3), Pair(16, 22), Pair(-86, 50), Pair(-42, 30), Pair(19, 14),
        Pair(-54, 41), Pair(-2, 48), Pair(-32, 41), Pair(-23, 12), Pair(-17, 15), Pair(-30, 52), Pair(-68, 34), Pair(-9, 15),
        Pair(36, 84), Pair(8, 39), Pair(-20, 23), Pair(-35, 8), Pair(1, 7), Pair(20, 6), Pair(-24, 33), Pair(40, 7),
        Pair(-19, 33), Pair(-53, 62), Pair(-48, 29), Pair(-13, 58), Pair(-10, 35), Pair(16, 23), Pair(-7, 37), Pair(13, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, 19), Pair(4, 35), Pair(110, -19), Pair(-66, 33), Pair(106, 142), Pair(-37, 35), Pair(26, 147), Pair(19, 27),
        Pair(0, 0), Pair(-50, 31), Pair(-115, 246), Pair(79, 33), Pair(-56, 82), Pair(-57, 44), Pair(-21, 142), Pair(-70, -42),
        Pair(182, 36), Pair(44, 180), Pair(139, -81), Pair(44, 93), Pair(144, 36), Pair(126, 51), Pair(94, -2), Pair(14, 21),
        Pair(-25, 163), Pair(27, 20), Pair(184, 25), Pair(131, 86), Pair(102, -44), Pair(28, 64), Pair(141, -2), Pair(132, -74),
        Pair(49, 81), Pair(20, 10), Pair(20, 55), Pair(42, 33), Pair(13, 23), Pair(89, 41), Pair(75, 117), Pair(3, 65),
        Pair(-61, 50), Pair(-73, 10), Pair(42, -7), Pair(60, -27), Pair(-153, 55), Pair(64, -4), Pair(-66, -2), Pair(45, 11),
        Pair(9, 83), Pair(-56, -26), Pair(94, -40), Pair(-39, 74), Pair(-42, 16), Pair(76, -117), Pair(14, 13), Pair(-176, 61),
        Pair(-71, -15), Pair(-97, -4), Pair(11, 113), Pair(35, -3), Pair(70, 52), Pair(-30, -59), Pair(-37, 31), Pair(-12, -92)
      },
      { // Piece 2
        Pair(28, 11), Pair(147, 21), Pair(-11, 37), Pair(118, -74), Pair(35, -20), Pair(-9, -23), Pair(21, -111), Pair(-13, -29),
        Pair(0, 0), Pair(372, 151), Pair(308, -76), Pair(146, -29), Pair(125, -30), Pair(62, 28), Pair(219, -84), Pair(8, -22),
        Pair(-14, 114), Pair(163, 1), Pair(163, 140), Pair(22, -43), Pair(77, -4), Pair(323, -20), Pair(180, -51), Pair(118, -78),
        Pair(237, -15), Pair(13, 71), Pair(216, -16), Pair(176, 141), Pair(187, -33), Pair(-18, -10), Pair(140, -60), Pair(31, 73),
        Pair(-4, 52), Pair(103, -25), Pair(56, 93), Pair(98, -17), Pair(18, 99), Pair(129, -26), Pair(25, 51), Pair(51, -19),
        Pair(44, 39), Pair(-8, 64), Pair(130, -108), Pair(-10, 32), Pair(124, -4), Pair(-2, 1), Pair(145, -63), Pair(-17, 40),
        Pair(-11, -36), Pair(61, -67), Pair(95, 5), Pair(44, 11), Pair(0, 19), Pair(147, -37), Pair(75, 67), Pair(-158, 93),
        Pair(-78, -45), Pair(-38, -23), Pair(44, -64), Pair(-22, 2), Pair(208, -106), Pair(-10, 42), Pair(88, -19), Pair(-50, 6)
      },
      { // Piece 3
        Pair(264, -252), Pair(215, 59), Pair(-17, 116), Pair(15, 131), Pair(-86, 71), Pair(-27, 166), Pair(22, 115), Pair(53, 109),
        Pair(0, 0), Pair(230, 11), Pair(175, -16), Pair(196, -45), Pair(385, -105), Pair(89, -8), Pair(128, -29), Pair(157, -18),
        Pair(-31, 61), Pair(-69, 140), Pair(78, 43), Pair(63, 58), Pair(-64, 93), Pair(-81, 127), Pair(-114, 134), Pair(22, 104),
        Pair(-97, 82), Pair(102, 123), Pair(54, 101), Pair(-22, 15), Pair(-17, 77), Pair(-86, 97), Pair(-96, 142), Pair(-134, 170),
        Pair(-113, 98), Pair(-27, 192), Pair(-143, 159), Pair(-139, 82), Pair(-59, 12), Pair(71, 41), Pair(-21, 56), Pair(212, -30),
        Pair(-31, 65), Pair(20, 113), Pair(-5, 34), Pair(35, 76), Pair(23, 45), Pair(-47, 109), Pair(-12, -30), Pair(18, 0),
        Pair(-6, 33), Pair(70, 90), Pair(-92, 88), Pair(17, 1), Pair(-24, 83), Pair(53, -14), Pair(-118, 8), Pair(-67, 79),
        Pair(-15, 31), Pair(59, 60), Pair(79, 14), Pair(-9, 49), Pair(-55, 104), Pair(-31, 54), Pair(-19, 24), Pair(-9, 2)
      },
      { // Piece 4
        Pair(67, -38), Pair(233, -38), Pair(63, 133), Pair(-52, -49), Pair(45, 79), Pair(-26, -18), Pair(112, 20), Pair(-62, -22),
        Pair(0, 0), Pair(-4, 157), Pair(33, -88), Pair(204, -126), Pair(64, 103), Pair(-138, 9), Pair(34, -52), Pair(73, 19),
        Pair(43, -59), Pair(83, 71), Pair(-61, -34), Pair(19, -12), Pair(46, 73), Pair(-44, -16), Pair(-90, -101), Pair(55, 37),
        Pair(3, 23), Pair(47, 46), Pair(37, -33), Pair(-16, 88), Pair(55, 47), Pair(139, -3), Pair(89, 35), Pair(-42, -92),
        Pair(1, -87), Pair(-7, 94), Pair(-49, 44), Pair(-39, -77), Pair(55, -98), Pair(36, -76), Pair(16, 110), Pair(104, -62),
        Pair(8, 68), Pair(103, -27), Pair(-68, 21), Pair(0, -41), Pair(-14, -1), Pair(-5, 79), Pair(88, -18), Pair(-17, -247),
        Pair(9, -91), Pair(57, -135), Pair(0, -48), Pair(14, -84), Pair(-31, 61), Pair(134, -178), Pair(144, 155), Pair(112, -56),
        Pair(-16, -16), Pair(-130, 20), Pair(89, 24), Pair(57, -78), Pair(20, -201), Pair(-36, -87), Pair(21, -24), Pair(-16, -40)
      },
      { // Piece 5
        Pair(96, -323), Pair(-78, 146), Pair(31, 111), Pair(4, -27), Pair(1, -41), Pair(7, -55), Pair(-16, -74), Pair(11, 101),
        Pair(0, 0), Pair(-2, 137), Pair(-68, 95), Pair(24, -8), Pair(84, -16), Pair(-35, -7), Pair(60, -26), Pair(15, 134),
        Pair(-154, 68), Pair(53, -18), Pair(73, 30), Pair(-59, -2), Pair(-133, 28), Pair(13, -8), Pair(3, 49), Pair(10, 82),
        Pair(-28, 32), Pair(46, 23), Pair(113, 7), Pair(-42, -29), Pair(49, -27), Pair(-37, 13), Pair(0, 62), Pair(-46, -27),
        Pair(-31, 63), Pair(93, 4), Pair(79, -10), Pair(114, -19), Pair(193, -34), Pair(-32, 22), Pair(53, -28), Pair(135, 14),
        Pair(-87, 110), Pair(123, -35), Pair(22, -5), Pair(-28, 2), Pair(163, -38), Pair(17, -38), Pair(-122, -16), Pair(30, -76),
        Pair(-138, 90), Pair(95, -20), Pair(71, 0), Pair(73, -19), Pair(39, -44), Pair(5, -42), Pair(9, -53), Pair(-79, -39),
        Pair(-120, 20), Pair(-35, 16), Pair(7, 6), Pair(-43, -4), Pair(-92, -23), Pair(32, -55), Pair(-76, -22), Pair(-103, 10)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 127), Pair(61, 27), Pair(69, -13), Pair(-3, 66), Pair(-61, 81), Pair(-18, 74), Pair(48, 86), Pair(23, 55),
        Pair(-52, -3), Pair(-20, -116), Pair(44, 43), Pair(-22, -8), Pair(90, -8), Pair(9, 73), Pair(1, -28), Pair(60, 11),
        Pair(92, 26), Pair(91, -60), Pair(-34, 64), Pair(-6, 22), Pair(24, 11), Pair(7, -6), Pair(18, 6), Pair(7, 17),
        Pair(-58, 35), Pair(40, -22), Pair(-28, 47), Pair(22, 37), Pair(-22, 31), Pair(-13, -3), Pair(-36, 18), Pair(-9, 22),
        Pair(-10, 24), Pair(11, 23), Pair(-52, 42), Pair(4, -2), Pair(-14, 23), Pair(-22, 21), Pair(-29, 31), Pair(-29, 25),
        Pair(-14, 34), Pair(1, 33), Pair(-38, 34), Pair(-47, 25), Pair(-31, 6), Pair(-16, 18), Pair(-23, 41), Pair(-4, 33),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-42, -58), Pair(-50, 70), Pair(-55, 42), Pair(7, 51), Pair(-1, -59), Pair(-57, -83), Pair(-35, -104), Pair(-103, -154),
        Pair(56, 131), Pair(0, 0), Pair(145, 32), Pair(89, 171), Pair(76, -30), Pair(26, 50), Pair(6, 106), Pair(-38, -55),
        Pair(124, 131), Pair(69, 55), Pair(189, 84), Pair(-108, 89), Pair(34, 64), Pair(124, -8), Pair(-208, -94), Pair(52, -62),
        Pair(203, -2), Pair(-31, 189), Pair(-21, 108), Pair(46, 36), Pair(169, 67), Pair(-128, 5), Pair(-14, 130), Pair(-15, 11),
        Pair(-69, 63), Pair(158, 132), Pair(32, 63), Pair(49, 53), Pair(116, 7), Pair(125, 47), Pair(-83, 54), Pair(-92, 66),
        Pair(-47, 126), Pair(258, -18), Pair(-21, 34), Pair(24, 130), Pair(-47, 34), Pair(5, 25), Pair(89, -18), Pair(-10, 70),
        Pair(-27, -24), Pair(1, -59), Pair(47, 53), Pair(62, -44), Pair(-2, -25), Pair(-33, 49), Pair(57, -86), Pair(8, -77),
        Pair(-36, -9), Pair(-71, -59), Pair(106, 100), Pair(-122, -48), Pair(-13, -64), Pair(-70, -31), Pair(-57, -18), Pair(-13, 41)
      },
      { // Piece 2
        Pair(-130, -219), Pair(70, -50), Pair(41, -104), Pair(-52, -47), Pair(36, -43), Pair(51, 0), Pair(33, -38), Pair(39, 58),
        Pair(271, 107), Pair(0, 0), Pair(180, 260), Pair(69, -55), Pair(-14, -19), Pair(11, 6), Pair(-42, -25), Pair(-31, -122),
        Pair(68, 6), Pair(126, 28), Pair(157, -60), Pair(31, 204), Pair(46, -111), Pair(119, -84), Pair(190, 3), Pair(-3, -1),
        Pair(5, -81), Pair(79, -59), Pair(-46, 80), Pair(259, -31), Pair(168, 40), Pair(322, -169), Pair(-121, 190), Pair(47, 46),
        Pair(177, -85), Pair(125, -12), Pair(68, -51), Pair(-30, 72), Pair(269, -38), Pair(96, 108), Pair(91, -20), Pair(-47, -29),
        Pair(9, 1), Pair(-86, -80), Pair(45, 32), Pair(177, -92), Pair(-26, 85), Pair(62, 25), Pair(168, -60), Pair(-61, -8),
        Pair(41, -181), Pair(126, -104), Pair(-57, -69), Pair(13, 22), Pair(43, -39), Pair(139, 11), Pair(99, -17), Pair(54, -1),
        Pair(12, 67), Pair(84, -108), Pair(27, 34), Pair(86, -108), Pair(6, 57), Pair(11, -41), Pair(63, -75), Pair(255, -76)
      },
      { // Piece 3
        Pair(-50, 260), Pair(133, -246), Pair(177, 119), Pair(5, 154), Pair(-52, 158), Pair(-20, 94), Pair(66, 113), Pair(48, 120),
        Pair(0, 62), Pair(0, 0), Pair(216, -29), Pair(146, -18), Pair(190, 10), Pair(59, -29), Pair(146, -21), Pair(173, -45),
        Pair(-15, 66), Pair(15, 21), Pair(-59, 127), Pair(95, 80), Pair(-15, 85), Pair(51, -20), Pair(79, 39), Pair(-62, 96),
        Pair(10, 83), Pair(78, -4), Pair(36, 95), Pair(46, 108), Pair(153, 85), Pair(154, 48), Pair(86, 40), Pair(178, 6),
        Pair(-33, 53), Pair(22, -25), Pair(53, 34), Pair(-115, 47), Pair(127, 12), Pair(38, -24), Pair(-30, 45), Pair(46, 10),
        Pair(-4, 64), Pair(43, 24), Pair(-151, 127), Pair(65, 21), Pair(-36, 52), Pair(69, 29), Pair(-40, 156), Pair(177, 54),
        Pair(-201, 99), Pair(-49, -8), Pair(-32, 69), Pair(-19, 67), Pair(25, 17), Pair(-81, 12), Pair(27, -102), Pair(-132, 39),
        Pair(5, -6), Pair(-11, 36), Pair(24, 37), Pair(54, 65), Pair(-12, -30), Pair(-7, -36), Pair(-110, 42), Pair(-57, 12)
      },
      { // Piece 4
        Pair(28, -117), Pair(-32, 34), Pair(-2, 40), Pair(99, -59), Pair(-12, 21), Pair(39, 17), Pair(-67, -156), Pair(-45, -80),
        Pair(63, -147), Pair(0, 0), Pair(50, 157), Pair(-76, 63), Pair(86, 56), Pair(69, -82), Pair(-100, -63), Pair(-22, -36),
        Pair(42, -60), Pair(-51, 34), Pair(43, 95), Pair(-73, 55), Pair(-17, 50), Pair(-17, 13), Pair(-53, -46), Pair(-126, 13),
        Pair(71, -81), Pair(-55, 177), Pair(-27, 161), Pair(-51, 101), Pair(33, 4), Pair(97, -95), Pair(-175, -18), Pair(24, -58),
        Pair(79, -87), Pair(-10, 26), Pair(-58, 122), Pair(4, -4), Pair(44, 85), Pair(-41, 144), Pair(-109, -114), Pair(-10, 13),
        Pair(-9, -234), Pair(-8, 65), Pair(-84, 66), Pair(31, -23), Pair(-43, -39), Pair(-48, 84), Pair(-96, 59), Pair(-92, 38),
        Pair(-4, 40), Pair(-60, 16), Pair(-58, 119), Pair(-80, 85), Pair(-84, 54), Pair(-12, -117), Pair(28, 83), Pair(-21, -78),
        Pair(36, -271), Pair(3, 21), Pair(80, -87), Pair(-8, -29), Pair(103, 72), Pair(33, 32), Pair(-93, -50), Pair(15, 4)
      },
      { // Piece 5
        Pair(59, 37), Pair(-59, 28), Pair(-86, 13), Pair(69, -30), Pair(27, 8), Pair(-36, -85), Pair(7, 69), Pair(-6, -6),
        Pair(9, 49), Pair(0, 0), Pair(226, 120), Pair(0, -29), Pair(43, -42), Pair(18, 4), Pair(-51, 12), Pair(-26, -76),
        Pair(147, 41), Pair(185, 10), Pair(44, 10), Pair(19, 30), Pair(89, -11), Pair(-10, -7), Pair(-63, 36), Pair(-28, -79),
        Pair(60, -7), Pair(261, -69), Pair(176, -3), Pair(72, -14), Pair(40, 10), Pair(152, -3), Pair(-57, -6), Pair(-35, -43),
        Pair(-40, 44), Pair(179, -27), Pair(205, -14), Pair(156, -20), Pair(30, 14), Pair(-76, 22), Pair(-214, 39), Pair(-76, 18),
        Pair(-39, 58), Pair(108, -36), Pair(-76, 45), Pair(45, -39), Pair(-22, 20), Pair(-4, -35), Pair(-106, 6), Pair(-169, 18),
        Pair(-96, 48), Pair(115, 31), Pair(-59, 6), Pair(-1, 1), Pair(-102, -8), Pair(-64, -32), Pair(-135, -19), Pair(-128, 3),
        Pair(8, 106), Pair(137, -80), Pair(77, 25), Pair(-43, 14), Pair(-130, -20), Pair(-103, 19), Pair(-117, 10), Pair(-136, 13)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-83, 61), Pair(69, -13), Pair(32, 17), Pair(116, 72), Pair(-32, 109), Pair(46, 93), Pair(20, 43), Pair(16, 113),
        Pair(80, -24), Pair(20, 0), Pair(-99, -47), Pair(-19, 2), Pair(-52, 141), Pair(-165, 25), Pair(-74, -10), Pair(-40, 8),
        Pair(-46, 25), Pair(7, 31), Pair(-39, 0), Pair(12, 56), Pair(14, 31), Pair(11, 32), Pair(-30, 35), Pair(-54, 45),
        Pair(30, 4), Pair(-36, 24), Pair(-35, 21), Pair(-46, 18), Pair(-35, 46), Pair(-17, 28), Pair(0, 8), Pair(11, 33),
        Pair(-35, 52), Pair(-2, 35), Pair(-15, 23), Pair(-25, -1), Pair(12, -14), Pair(-61, 24), Pair(41, -1), Pair(-9, 20),
        Pair(-12, 25), Pair(35, -9), Pair(-8, -12), Pair(-19, -4), Pair(-12, 16), Pair(-4, 14), Pair(27, 6), Pair(17, 27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(250, 41), Pair(92, 72), Pair(-72, -133), Pair(58, 71), Pair(-133, 28), Pair(36, 78), Pair(3, -43), Pair(4, 0),
        Pair(129, 96), Pair(52, 58), Pair(0, 0), Pair(111, 77), Pair(124, 135), Pair(-28, 81), Pair(8, -109), Pair(3, 11),
        Pair(123, 15), Pair(170, 229), Pair(174, -8), Pair(52, 218), Pair(196, -154), Pair(96, 35), Pair(16, 97), Pair(28, 83),
        Pair(38, 124), Pair(-9, 131), Pair(106, 33), Pair(108, 42), Pair(-30, 16), Pair(138, 45), Pair(-3, -61), Pair(137, -52),
        Pair(131, 45), Pair(-39, 62), Pair(82, 38), Pair(-55, 35), Pair(103, 60), Pair(-38, -13), Pair(97, -9), Pair(75, 127),
        Pair(-11, 45), Pair(21, -53), Pair(36, 38), Pair(167, -64), Pair(86, 4), Pair(-5, -85), Pair(-43, 38), Pair(-47, 19),
        Pair(119, 14), Pair(-31, 79), Pair(97, -17), Pair(-134, 19), Pair(-38, 30), Pair(119, -66), Pair(-10, 36), Pair(-93, 8),
        Pair(-92, -80), Pair(-45, 45), Pair(-29, 195), Pair(111, 26), Pair(6, -12), Pair(-121, 3), Pair(0, -57), Pair(-7, -113)
      },
      { // Piece 2
        Pair(-108, 34), Pair(20, -23), Pair(24, 98), Pair(291, -139), Pair(31, 100), Pair(8, -46), Pair(50, 66), Pair(-19, -77),
        Pair(191, -69), Pair(-10, 163), Pair(0, 0), Pair(105, 161), Pair(115, -138), Pair(57, 50), Pair(90, 11), Pair(100, 41),
        Pair(257, 127), Pair(217, -39), Pair(-53, 85), Pair(264, -63), Pair(108, 126), Pair(232, -79), Pair(134, 113), Pair(48, -25),
        Pair(80, 60), Pair(-47, 121), Pair(132, -51), Pair(91, 22), Pair(332, -61), Pair(302, 136), Pair(36, 6), Pair(-45, 79),
        Pair(45, 120), Pair(202, -1), Pair(1, 103), Pair(196, -74), Pair(-49, 44), Pair(155, -9), Pair(21, 122), Pair(123, -110),
        Pair(198, -106), Pair(25, 42), Pair(58, -31), Pair(-21, 81), Pair(74, 11), Pair(-42, 73), Pair(180, -30), Pair(118, 84),
        Pair(-1, -25), Pair(145, -110), Pair(-20, -25), Pair(86, -81), Pair(-98, 35), Pair(51, -10), Pair(-39, 94), Pair(82, -28),
        Pair(12, -128), Pair(-119, 112), Pair(-14, -29), Pair(-22, 110), Pair(92, -34), Pair(-63, 32), Pair(73, -101), Pair(32, -93)
      },
      { // Piece 3
        Pair(150, 83), Pair(148, 92), Pair(25, -170), Pair(139, 122), Pair(84, 100), Pair(53, 67), Pair(125, 42), Pair(100, 30),
        Pair(-126, 25), Pair(75, -34), Pair(0, 0), Pair(106, 70), Pair(10, 35), Pair(-19, -25), Pair(216, -51), Pair(160, -31),
        Pair(-14, 44), Pair(79, 97), Pair(106, -42), Pair(12, 107), Pair(-58, 138), Pair(-53, 90), Pair(-34, 92), Pair(-79, 105),
        Pair(-132, 102), Pair(35, 68), Pair(107, 29), Pair(49, 103), Pair(-26, 80), Pair(63, 87), Pair(24, 58), Pair(27, 5),
        Pair(85, -32), Pair(-15, 42), Pair(-129, 81), Pair(-5, 138), Pair(-32, 110), Pair(144, 15), Pair(-10, 66), Pair(89, -72),
        Pair(27, -11), Pair(202, -67), Pair(9, 11), Pair(-38, 69), Pair(-16, 1), Pair(-69, 36), Pair(7, 79), Pair(-122, 43),
        Pair(-48, 60), Pair(70, 81), Pair(-47, 79), Pair(-43, 119), Pair(19, -89), Pair(-97, 112), Pair(-77, 15), Pair(102, 4),
        Pair(-41, 11), Pair(-112, 140), Pair(-45, 71), Pair(42, 69), Pair(-138, 112), Pair(-52, 120), Pair(-99, 74), Pair(-147, 97)
      },
      { // Piece 4
        Pair(-61, -30), Pair(21, 64), Pair(-91, -131), Pair(85, 114), Pair(40, 25), Pair(79, 43), Pair(-45, -93), Pair(-26, -34),
        Pair(104, -10), Pair(-125, 120), Pair(0, 0), Pair(118, 181), Pair(133, 237), Pair(107, 31), Pair(74, 37), Pair(79, -25),
        Pair(-158, -116), Pair(26, -9), Pair(-65, 44), Pair(-70, 169), Pair(15, 24), Pair(104, 28), Pair(-24, -40), Pair(125, -20),
        Pair(23, -37), Pair(-80, 133), Pair(25, -46), Pair(-114, 1), Pair(-64, 75), Pair(82, -51), Pair(151, -39), Pair(109, -112),
        Pair(24, -14), Pair(-39, 8), Pair(84, 53), Pair(12, 91), Pair(-39, 77), Pair(-35, -33), Pair(-22, 61), Pair(-7, 134),
        Pair(-85, 8), Pair(113, -66), Pair(67, -2), Pair(5, -55), Pair(-17, 12), Pair(25, -3), Pair(-93, -35), Pair(112, 125),
        Pair(73, 10), Pair(-93, -9), Pair(-70, 119), Pair(104, -123), Pair(-33, 17), Pair(-5, -164), Pair(-95, -88), Pair(-75, -124),
        Pair(90, 29), Pair(-101, -38), Pair(65, -48), Pair(0, -153), Pair(103, -127), Pair(-130, 18), Pair(-19, 25), Pair(-17, -24)
      },
      { // Piece 5
        Pair(-43, 97), Pair(89, 103), Pair(-109, 17), Pair(-41, 30), Pair(-89, -53), Pair(17, -37), Pair(10, 26), Pair(15, 36),
        Pair(-26, 87), Pair(24, 125), Pair(0, 0), Pair(34, 106), Pair(-15, 41), Pair(7, 10), Pair(-65, -38), Pair(17, 3),
        Pair(45, 26), Pair(83, 49), Pair(63, 69), Pair(234, 28), Pair(-48, 69), Pair(170, 17), Pair(103, -74), Pair(60, 50),
        Pair(83, -34), Pair(64, 21), Pair(107, 41), Pair(169, -11), Pair(125, 0), Pair(78, -4), Pair(-95, 106), Pair(13, 12),
        Pair(93, 11), Pair(15, -14), Pair(56, -51), Pair(6, -22), Pair(139, -71), Pair(44, -43), Pair(-50, 11), Pair(6, 5),
        Pair(-229, 67), Pair(77, 71), Pair(16, -48), Pair(81, -25), Pair(-15, -60), Pair(-84, -20), Pair(-108, -43), Pair(1, -29),
        Pair(36, 2), Pair(106, 4), Pair(19, -6), Pair(-42, -25), Pair(1, -89), Pair(-158, -42), Pair(-121, 3), Pair(-60, 14),
        Pair(-91, -68), Pair(-39, 40), Pair(-11, -32), Pair(-19, -29), Pair(-31, 18), Pair(-36, -55), Pair(-138, 4), Pair(-138, 46)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(87, -6), Pair(-3, 66), Pair(116, 72), Pair(105, -50), Pair(-34, 41), Pair(17, 29), Pair(79, 12), Pair(-61, 82),
        Pair(-56, 82), Pair(36, -19), Pair(32, 18), Pair(-165, -91), Pair(-91, 52), Pair(-31, 33), Pair(-47, 11), Pair(-90, 38),
        Pair(-16, 51), Pair(-10, -4), Pair(9, 81), Pair(5, 2), Pair(-3, 40), Pair(26, -2), Pair(-17, 11), Pair(7, 26),
        Pair(51, 2), Pair(-47, 12), Pair(-25, 62), Pair(-9, -22), Pair(85, -18), Pair(19, 2), Pair(60, -23), Pair(10, 22),
        Pair(-16, 2), Pair(-48, 29), Pair(116, -24), Pair(-83, 11), Pair(-35, 39), Pair(-25, 36), Pair(-17, 34), Pair(16, 21),
        Pair(15, 6), Pair(72, -19), Pair(3, -14), Pair(32, -44), Pair(-30, 28), Pair(-12, 29), Pair(36, 11), Pair(17, 22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-64, -61), Pair(18, -14), Pair(56, 75), Pair(-60, -64), Pair(72, -89), Pair(7, -2), Pair(2, -26), Pair(21, 34),
        Pair(130, 117), Pair(99, 193), Pair(76, 119), Pair(0, 0), Pair(36, -16), Pair(47, 158), Pair(32, 28), Pair(-48, 45),
        Pair(-111, 42), Pair(19, -21), Pair(127, 159), Pair(39, 50), Pair(237, 64), Pair(99, -17), Pair(66, 115), Pair(151, 72),
        Pair(-63, 50), Pair(51, -36), Pair(110, 30), Pair(81, -21), Pair(237, 54), Pair(91, -7), Pair(142, 62), Pair(145, 131),
        Pair(102, 31), Pair(55, 11), Pair(-49, 2), Pair(-5, 94), Pair(24, 50), Pair(-30, 90), Pair(23, 71), Pair(-18, -18),
        Pair(-30, 5), Pair(-56, 92), Pair(77, -7), Pair(-14, 31), Pair(85, -65), Pair(64, 37), Pair(111, -49), Pair(-42, -44),
        Pair(83, -62), Pair(-57, -70), Pair(-101, -48), Pair(-84, -8), Pair(166, 23), Pair(-142, 15), Pair(43, 73), Pair(-36, -54),
        Pair(-18, -102), Pair(-196, 113), Pair(118, -52), Pair(-109, 49), Pair(104, -14), Pair(-24, -31), Pair(-180, -9), Pair(23, -27)
      },
      { // Piece 2
        Pair(127, -6), Pair(-22, 33), Pair(105, -70), Pair(-213, 11), Pair(-28, -30), Pair(-84, -38), Pair(21, -82), Pair(-50, -4),
        Pair(2, 125), Pair(157, 3), Pair(-77, 217), Pair(0, 0), Pair(81, 88), Pair(87, -80), Pair(75, 4), Pair(-1, 20),
        Pair(169, -58), Pair(160, 243), Pair(108, -8), Pair(153, 51), Pair(94, -29), Pair(112, -1), Pair(66, -97), Pair(225, -30),
        Pair(213, 181), Pair(169, 16), Pair(111, 82), Pair(68, 1), Pair(92, 61), Pair(124, -40), Pair(-78, 214), Pair(129, -13),
        Pair(152, 16), Pair(122, 62), Pair(105, -17), Pair(55, 3), Pair(186, -67), Pair(-39, 148), Pair(227, -52), Pair(105, 143),
        Pair(135, 40), Pair(-3, -86), Pair(95, 91), Pair(-37, -62), Pair(107, 95), Pair(94, -63), Pair(58, 73), Pair(159, -63),
        Pair(-53, 77), Pair(88, 77), Pair(-143, -30), Pair(126, 34), Pair(-76, -81), Pair(-139, 89), Pair(101, -28), Pair(-78, 71),
        Pair(44, -56), Pair(12, -51), Pair(-96, 62), Pair(42, -87), Pair(48, 5), Pair(34, -83), Pair(19, -17), Pair(-22, -32)
      },
      { // Piece 3
        Pair(31, 122), Pair(68, 125), Pair(41, 157), Pair(28, -102), Pair(240, 100), Pair(20, 172), Pair(116, 53), Pair(134, 157),
        Pair(-37, 101), Pair(147, -29), Pair(2, 48), Pair(0, 0), Pair(64, 97), Pair(-7, 74), Pair(-181, 66), Pair(-53, 77),
        Pair(35, 26), Pair(-77, 58), Pair(-52, 147), Pair(194, -97), Pair(81, 155), Pair(49, 77), Pair(49, 84), Pair(-38, 150),
        Pair(1, 13), Pair(203, 83), Pair(64, 86), Pair(-13, 90), Pair(61, 185), Pair(155, -15), Pair(89, 0), Pair(139, 27),
        Pair(-152, 66), Pair(-80, 52), Pair(-116, 172), Pair(69, 70), Pair(43, 151), Pair(50, 89), Pair(21, 41), Pair(-113, 14),
        Pair(-176, 99), Pair(-112, 90), Pair(-117, 112), Pair(-4, 23), Pair(-56, 122), Pair(77, -2), Pair(-123, 83), Pair(-88, 98),
        Pair(-85, 33), Pair(87, -24), Pair(-70, 67), Pair(66, 26), Pair(18, 94), Pair(-124, 171), Pair(-116, 180), Pair(-37, 68),
        Pair(-81, 41), Pair(-22, 82), Pair(-10, 98), Pair(106, 15), Pair(-2, 90), Pair(-23, 93), Pair(-2, 79), Pair(-136, 104)
      },
      { // Piece 4
        Pair(-83, -4), Pair(-16, 31), Pair(98, 179), Pair(-116, -176), Pair(116, 72), Pair(-4, -8), Pair(-63, -19), Pair(-51, -42),
        Pair(-149, 20), Pair(-43, 7), Pair(-55, 98), Pair(0, 0), Pair(87, -88), Pair(49, 115), Pair(-16, -55), Pair(-4, -94),
        Pair(-18, 29), Pair(-25, 107), Pair(113, -27), Pair(113, 69), Pair(62, 13), Pair(-4, -43), Pair(94, 97), Pair(-96, -22),
        Pair(28, -59), Pair(-40, -2), Pair(40, -9), Pair(55, 29), Pair(55, 43), Pair(82, -54), Pair(-91, 62), Pair(26, 51),
        Pair(-90, -76), Pair(-144, -3), Pair(93, -18), Pair(32, 87), Pair(119, 43), Pair(-51, 210), Pair(-51, -120), Pair(84, 9),
        Pair(-106, -22), Pair(-86, -21), Pair(33, -66), Pair(8, 34), Pair(35, 95), Pair(-132, 106), Pair(51, 19), Pair(-92, -28),
        Pair(43, -105), Pair(-191, 42), Pair(62, -20), Pair(15, -42), Pair(-40, 65), Pair(85, 101), Pair(-46, -143), Pair(107, -32),
        Pair(82, -36), Pair(40, -84), Pair(-16, -20), Pair(-19, 38), Pair(-45, -14), Pair(-24, -4), Pair(8, -49), Pair(-16, -58)
      },
      { // Piece 5
        Pair(17, 172), Pair(36, 129), Pair(98, 159), Pair(197, 0), Pair(-35, -1), Pair(20, 105), Pair(-9, -55), Pair(6, 108),
        Pair(-65, 33), Pair(21, 109), Pair(129, 149), Pair(0, 0), Pair(-10, 187), Pair(1, 61), Pair(7, -86), Pair(10, 17),
        Pair(-43, 19), Pair(15, 78), Pair(91, 53), Pair(64, 25), Pair(52, 52), Pair(-29, 61), Pair(-22, -5), Pair(-32, -30),
        Pair(140, 63), Pair(20, -6), Pair(169, 52), Pair(131, -8), Pair(224, -33), Pair(-52, -23), Pair(27, -20), Pair(26, -50),
        Pair(-78, -2), Pair(-78, 21), Pair(73, -15), Pair(-41, -38), Pair(93, -55), Pair(-14, -33), Pair(-48, -82), Pair(-76, -21),
        Pair(102, -40), Pair(109, -51), Pair(116, -70), Pair(10, -55), Pair(-27, -46), Pair(-50, -50), Pair(78, -88), Pair(49, -87),
        Pair(91, -119), Pair(-55, -39), Pair(75, -32), Pair(-127, -23), Pair(-58, -10), Pair(10, -44), Pair(-74, -26), Pair(-112, 3),
        Pair(85, -104), Pair(-159, 31), Pair(-72, 18), Pair(-96, -70), Pair(-221, 10), Pair(-44, -52), Pair(26, -83), Pair(-101, -32)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(87, 75), Pair(-61, 81), Pair(-32, 109), Pair(-34, 41), Pair(81, 10), Pair(40, -4), Pair(31, 129), Pair(61, 75),
        Pair(-113, 76), Pair(71, 21), Pair(-26, 61), Pair(92, -27), Pair(50, -78), Pair(34, -1), Pair(-15, 87), Pair(-54, 65),
        Pair(63, 12), Pair(-68, 23), Pair(23, -4), Pair(14, 43), Pair(89, -28), Pair(-33, 64), Pair(24, 8), Pair(-92, 46),
        Pair(-19, 17), Pair(15, 4), Pair(-40, 24), Pair(-50, 55), Pair(17, -17), Pair(-40, 62), Pair(10, -9), Pair(-11, 19),
        Pair(-22, -7), Pair(22, -14), Pair(30, 21), Pair(-29, 64), Pair(14, -14), Pair(-106, 54), Pair(-4, 0), Pair(1, 16),
        Pair(-16, 37), Pair(22, -12), Pair(-5, 2), Pair(-45, 77), Pair(68, 40), Pair(-37, 24), Pair(0, 30), Pair(-1, 36),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(40, 68), Pair(-82, 41), Pair(83, 87), Pair(122, 41), Pair(-6, 59), Pair(205, 111), Pair(22, 34), Pair(1, -15),
        Pair(-235, -148), Pair(-238, 64), Pair(220, 205), Pair(78, 70), Pair(0, 0), Pair(36, 104), Pair(128, 110), Pair(-29, -109),
        Pair(201, 49), Pair(-55, 71), Pair(6, 0), Pair(145, 251), Pair(141, 171), Pair(95, 131), Pair(96, 29), Pair(36, 79),
        Pair(-192, 22), Pair(185, -34), Pair(-106, 42), Pair(125, 75), Pair(232, 12), Pair(171, 40), Pair(91, -47), Pair(176, 64),
        Pair(-109, -29), Pair(100, 32), Pair(106, 86), Pair(-14, 62), Pair(112, 57), Pair(-99, 101), Pair(46, 160), Pair(-14, 9),
        Pair(20, 14), Pair(-9, 19), Pair(94, 98), Pair(-81, -5), Pair(86, -20), Pair(70, -4), Pair(71, 54), Pair(34, 81),
        Pair(-38, -122), Pair(-102, -103), Pair(65, -103), Pair(111, -56), Pair(-33, -13), Pair(24, -21), Pair(61, -103), Pair(-25, -67),
        Pair(-62, -44), Pair(14, -107), Pair(8, 8), Pair(167, -73), Pair(-171, -62), Pair(-102, -30), Pair(8, 74), Pair(-83, -9)
      },
      { // Piece 2
        Pair(99, 34), Pair(-53, -42), Pair(6, 1), Pair(-96, -112), Pair(53, 72), Pair(130, -168), Pair(-11, 47), Pair(9, 55),
        Pair(13, -6), Pair(-18, 33), Pair(23, 41), Pair(161, 86), Pair(0, 0), Pair(93, 228), Pair(-9, -11), Pair(119, 3),
        Pair(-183, 97), Pair(12, -100), Pair(43, 190), Pair(104, 3), Pair(60, 105), Pair(140, -10), Pair(76, 176), Pair(-103, -53),
        Pair(-43, -20), Pair(129, 272), Pair(137, -1), Pair(74, 104), Pair(271, -42), Pair(188, 103), Pair(135, -15), Pair(5, 52),
        Pair(13, 200), Pair(9, 2), Pair(10, 65), Pair(106, -78), Pair(110, 45), Pair(39, -52), Pair(80, -15), Pair(201, 1),
        Pair(21, -53), Pair(36, 106), Pair(65, -15), Pair(-10, 49), Pair(9, -82), Pair(214, -90), Pair(-11, -72), Pair(68, 69),
        Pair(-214, 73), Pair(1, -31), Pair(71, 19), Pair(-11, -65), Pair(39, 54), Pair(151, -86), Pair(-64, 53), Pair(-204, -120),
        Pair(139, -194), Pair(136, -14), Pair(-63, -45), Pair(-35, 114), Pair(-20, -39), Pair(64, -16), Pair(127, -175), Pair(-34, 179)
      },
      { // Piece 3
        Pair(-73, 66), Pair(47, 42), Pair(70, 144), Pair(85, 75), Pair(26, -205), Pair(175, 103), Pair(110, -11), Pair(144, 194),
        Pair(47, -11), Pair(-9, 15), Pair(-22, 73), Pair(161, 3), Pair(0, 0), Pair(259, -40), Pair(-7, -11), Pair(-165, 78),
        Pair(67, 11), Pair(49, -29), Pair(15, 26), Pair(88, 50), Pair(232, -31), Pair(75, 52), Pair(-116, 69), Pair(-74, 99),
        Pair(-47, 39), Pair(33, -60), Pair(-133, 16), Pair(73, 105), Pair(124, -64), Pair(-40, 36), Pair(-53, 150), Pair(-71, 14),
        Pair(-1, -34), Pair(49, 124), Pair(-28, 32), Pair(65, 65), Pair(-77, 80), Pair(19, 130), Pair(-60, 67), Pair(-138, 171),
        Pair(132, -27), Pair(97, 79), Pair(-14, 64), Pair(-75, 22), Pair(82, 44), Pair(-126, 154), Pair(-135, 58), Pair(-134, 98),
        Pair(81, -69), Pair(-20, -11), Pair(-108, -37), Pair(73, -17), Pair(16, 9), Pair(80, 90), Pair(-109, -91), Pair(-89, 46),
        Pair(-97, 39), Pair(-60, -16), Pair(-111, 87), Pair(-12, 10), Pair(157, -57), Pair(-113, 64), Pair(-17, -22), Pair(-39, -35)
      },
      { // Piece 4
        Pair(-80, -113), Pair(70, 71), Pair(29, 39), Pair(-21, -56), Pair(-120, -45), Pair(27, -65), Pair(-28, -63), Pair(-55, -32),
        Pair(126, 54), Pair(-21, 1), Pair(66, -47), Pair(143, -97), Pair(0, 0), Pair(90, -66), Pair(-187, -88), Pair(-188, -4),
        Pair(-87, 29), Pair(-92, -85), Pair(81, 24), Pair(-91, 100), Pair(18, -32), Pair(99, 14), Pair(104, 16), Pair(110, -6),
        Pair(-14, -82), Pair(-7, 53), Pair(172, 83), Pair(66, -49), Pair(4, -71), Pair(26, -109), Pair(-37, -79), Pair(48, 78),
        Pair(-139, 56), Pair(31, -40), Pair(-31, 1), Pair(25, -115), Pair(114, -40), Pair(-4, -27), Pair(-102, -179), Pair(128, -52),
        Pair(36, -53), Pair(115, 61), Pair(-87, -40), Pair(-34, -113), Pair(-132, -20), Pair(-25, -29), Pair(133, -112), Pair(118, 84),
        Pair(-24, -32), Pair(15, -98), Pair(-22, -29), Pair(12, -26), Pair(-9, -35), Pair(-89, 52), Pair(14, -41), Pair(-81, -104),
        Pair(-51, 25), Pair(95, -93), Pair(7, -83), Pair(-37, 50), Pair(-43, 49), Pair(-53, 16), Pair(8, -57), Pair(-12, -48)
      },
      { // Piece 5
        Pair(16, -1), Pair(45, 8), Pair(2, -5), Pair(-11, 39), Pair(1, 44), Pair(-27, -31), Pair(50, -32), Pair(12, 90),
        Pair(-47, 66), Pair(4, -1), Pair(29, 24), Pair(-26, 187), Pair(0, 0), Pair(125, 144), Pair(130, 30), Pair(26, -19),
        Pair(-17, -46), Pair(97, 7), Pair(28, 57), Pair(-45, 56), Pair(35, 27), Pair(69, 67), Pair(99, 13), Pair(87, 61),
        Pair(-63, -77), Pair(-84, 19), Pair(48, -32), Pair(-45, -33), Pair(-73, 17), Pair(38, 42), Pair(179, -60), Pair(-4, 60),
        Pair(-85, -135), Pair(78, 5), Pair(2, -21), Pair(94, -36), Pair(-32, -28), Pair(-18, -3), Pair(-70, 3), Pair(30, -30),
        Pair(45, -68), Pair(-44, 28), Pair(166, -30), Pair(-7, -13), Pair(-158, -21), Pair(-24, -37), Pair(113, -97), Pair(-11, -2),
        Pair(-80, -25), Pair(60, -46), Pair(-58, -20), Pair(-50, -32), Pair(-14, -46), Pair(-24, -32), Pair(19, -35), Pair(17, -11),
        Pair(-183, 60), Pair(31, 59), Pair(-14, -30), Pair(-54, 15), Pair(-111, -26), Pair(-213, 38), Pair(2, -55), Pair(107, -118)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-121, 87), Pair(-18, 74), Pair(46, 93), Pair(17, 29), Pair(40, -4), Pair(-79, 23), Pair(29, 51), Pair(-5, 127),
        Pair(-13, 71), Pair(-8, -2), Pair(-107, 97), Pair(54, 66), Pair(58, 0), Pair(96, -221), Pair(-16, -25), Pair(26, 11),
        Pair(16, 64), Pair(2, 23), Pair(5, 44), Pair(0, 5), Pair(30, 31), Pair(6, 14), Pair(-60, 41), Pair(4, 36),
        Pair(90, -13), Pair(65, -45), Pair(56, -9), Pair(17, -9), Pair(-35, 13), Pair(45, -62), Pair(-60, 30), Pair(-17, 26),
        Pair(8, 17), Pair(74, -11), Pair(48, -19), Pair(-12, 29), Pair(-4, 32), Pair(9, 36), Pair(-47, 25), Pair(-26, 6),
        Pair(32, 16), Pair(25, -6), Pair(-20, -1), Pair(-71, 66), Pair(-33, 83), Pair(-17, 51), Pair(-35, 22), Pair(-27, 38),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(30, 89), Pair(-28, -38), Pair(-13, 16), Pair(104, -56), Pair(52, 57), Pair(61, -4), Pair(90, 72), Pair(56, -22),
        Pair(-7, 62), Pair(16, -117), Pair(14, 25), Pair(-2, 145), Pair(-87, 76), Pair(0, 0), Pair(78, 35), Pair(94, 140),
        Pair(17, 82), Pair(-50, -29), Pair(-36, 36), Pair(191, -101), Pair(129, 34), Pair(22, 82), Pair(72, 92), Pair(5, -53),
        Pair(-21, -62), Pair(-324, 59), Pair(-21, 168), Pair(13, 18), Pair(279, 39), Pair(-42, 61), Pair(37, 43), Pair(200, -63),
        Pair(33, -71), Pair(21, -29), Pair(149, -2), Pair(58, 13), Pair(39, -8), Pair(120, -72), Pair(21, -42), Pair(71, -35),
        Pair(-89, 50), Pair(-128, -10), Pair(51, -111), Pair(31, 27), Pair(-96, 70), Pair(-33, 26), Pair(-60, -123), Pair(-36, -39),
        Pair(-83, 56), Pair(-6, 44), Pair(-131, 17), Pair(-25, -32), Pair(39, -115), Pair(-70, 35), Pair(37, -139), Pair(-6, -42),
        Pair(-142, -43), Pair(13, -19), Pair(-69, 60), Pair(81, 10), Pair(-124, 54), Pair(-165, 42), Pair(-138, 0), Pair(-36, -85)
      },
      { // Piece 2
        Pair(-12, -106), Pair(-30, 107), Pair(-173, -99), Pair(40, -5), Pair(144, -41), Pair(-2, 190), Pair(-25, -275), Pair(48, -56),
        Pair(51, 35), Pair(120, -116), Pair(54, 4), Pair(71, -83), Pair(-82, 163), Pair(0, 0), Pair(283, 165), Pair(-122, -82),
        Pair(-152, -126), Pair(-39, 6), Pair(69, -76), Pair(131, 102), Pair(205, -43), Pair(137, 55), Pair(74, -95), Pair(113, 64),
        Pair(-17, -47), Pair(54, -36), Pair(42, 177), Pair(306, -59), Pair(47, 67), Pair(-70, -28), Pair(167, 14), Pair(29, -74),
        Pair(29, -81), Pair(-53, 125), Pair(240, -33), Pair(202, 38), Pair(14, -19), Pair(109, 76), Pair(-36, -76), Pair(-44, 54),
        Pair(31, 32), Pair(18, 32), Pair(-113, 104), Pair(14, -74), Pair(71, 60), Pair(63, -81), Pair(66, 25), Pair(20, -84),
        Pair(9, -43), Pair(51, -89), Pair(-39, 30), Pair(90, -12), Pair(-49, -26), Pair(-172, -8), Pair(-42, -63), Pair(-1, -174),
        Pair(68, 78), Pair(-106, 13), Pair(-53, 119), Pair(78, -13), Pair(36, -47), Pair(70, -9), Pair(9, -31), Pair(79, -35)
      },
      { // Piece 3
        Pair(101, 50), Pair(6, 101), Pair(135, 128), Pair(115, 79), Pair(33, 84), Pair(40, -204), Pair(-38, 122), Pair(168, 101),
        Pair(76, -27), Pair(-35, -56), Pair(55, -54), Pair(73, -48), Pair(161, -24), Pair(0, 0), Pair(-126, 13), Pair(-42, 38),
        Pair(-60, 65), Pair(81, -2), Pair(70, 53), Pair(5, 34), Pair(99, 16), Pair(104, -97), Pair(73, 24), Pair(53, 39),
        Pair(-5, 31), Pair(40, 48), Pair(25, 0), Pair(148, 92), Pair(99, 97), Pair(200, 9), Pair(40, 15), Pair(41, -13),
        Pair(65, -43), Pair(76, 1), Pair(-64, 50), Pair(-6, 72), Pair(122, 56), Pair(-46, 28), Pair(-23, 25), Pair(7, 95),
        Pair(-2, 52), Pair(-99, 148), Pair(-41, 18), Pair(-5, 31), Pair(-134, 115), Pair(24, 9), Pair(24, -12), Pair(111, -130),
        Pair(0, -29), Pair(-54, 76), Pair(131, 9), Pair(-54, 22), Pair(20, 119), Pair(217, -122), Pair(-45, -63), Pair(115, -77),
        Pair(-56, 8), Pair(10, -11), Pair(-45, 60), Pair(-11, -23), Pair(-85, 66), Pair(39, -43), Pair(-73, 22), Pair(-3, -19)
      },
      { // Piece 4
        Pair(-23, -17), Pair(-11, -22), Pair(29, -58), Pair(16, 31), Pair(122, -84), Pair(-100, -142), Pair(-122, -173), Pair(33, 19),
        Pair(85, -2), Pair(5, 6), Pair(-43, 34), Pair(-79, 51), Pair(133, 45), Pair(0, 0), Pair(-118, -116), Pair(-142, -63),
        Pair(-68, -49), Pair(13, -286), Pair(161, 97), Pair(85, 43), Pair(50, 153), Pair(68, -44), Pair(142, 51), Pair(71, -27),
        Pair(-117, -108), Pair(-88, -15), Pair(103, -49), Pair(99, 87), Pair(110, 155), Pair(65, -52), Pair(208, -43), Pair(-62, -125),
        Pair(-149, -23), Pair(-86, -40), Pair(-26, 11), Pair(-66, -17), Pair(160, -72), Pair(35, 43), Pair(22, -18), Pair(47, -68),
        Pair(-52, -58), Pair(-78, -31), Pair(-57, -3), Pair(90, -40), Pair(-178, -103), Pair(-121, -13), Pair(167, 13), Pair(-84, 24),
        Pair(-21, -81), Pair(-85, -107), Pair(-41, -126), Pair(-14, -123), Pair(-106, -64), Pair(-78, -19), Pair(63, 139), Pair(-14, 17),
        Pair(118, -21), Pair(-70, 30), Pair(-52, 87), Pair(-37, -230), Pair(-87, -116), Pair(-97, -136), Pair(8, -98), Pair(-99, -54)
      },
      { // Piece 5
        Pair(-6, -33), Pair(13, 47), Pair(-11, -48), Pair(-1, 19), Pair(32, 95), Pair(63, 54), Pair(37, 125), Pair(-28, 45),
        Pair(15, 24), Pair(-52, -96), Pair(-37, -61), Pair(61, 69), Pair(53, 120), Pair(0, 0), Pair(-51, 110), Pair(-11, 67),
        Pair(43, 129), Pair(36, 3), Pair(-25, -43), Pair(-66, 91), Pair(-57, 45), Pair(71, 15), Pair(125, -20), Pair(54, 130),
        Pair(-47, 54), Pair(-71, 20), Pair(0, -23), Pair(78, -47), Pair(60, -7), Pair(38, -20), Pair(78, -14), Pair(19, 55),
        Pair(-56, 15), Pair(-81, 18), Pair(-82, 10), Pair(-145, 19), Pair(-19, -31), Pair(60, -53), Pair(127, -7), Pair(-14, 15),
        Pair(-100, -15), Pair(-20, 2), Pair(-20, 8), Pair(68, -58), Pair(-13, -45), Pair(116, -73), Pair(-38, -16), Pair(-18, 54),
        Pair(-102, 41), Pair(-75, 61), Pair(57, -2), Pair(-146, -20), Pair(-42, -44), Pair(-101, -20), Pair(40, -21), Pair(166, -69),
        Pair(-42, -63), Pair(-72, 21), Pair(-73, 35), Pair(-30, -99), Pair(-33, -69), Pair(36, -63), Pair(111, -72), Pair(-26, -37)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(13, 77), Pair(48, 86), Pair(20, 43), Pair(79, 12), Pair(31, 129), Pair(29, 51), Pair(-62, 48), Pair(71, 24),
        Pair(-66, 26), Pair(-3, 6), Pair(-42, 48), Pair(67, -10), Pair(-22, 46), Pair(170, -47), Pair(-8, -82), Pair(0, -20),
        Pair(-9, 4), Pair(-13, 12), Pair(34, 9), Pair(-22, 20), Pair(-7, 5), Pair(-2, 51), Pair(10, -16), Pair(56, 9),
        Pair(-30, 19), Pair(-29, 11), Pair(9, -5), Pair(-34, 13), Pair(18, 12), Pair(-27, 27), Pair(-37, -42), Pair(-21, 60),
        Pair(4, 23), Pair(32, -4), Pair(47, -12), Pair(33, -46), Pair(32, 16), Pair(13, 0), Pair(27, -3), Pair(-5, 39),
        Pair(-6, 43), Pair(1, 5), Pair(-29, 42), Pair(-49, 3), Pair(-15, 18), Pair(-31, 52), Pair(35, 3), Pair(6, 31),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(45, 49), Pair(12, 32), Pair(-33, -130), Pair(-48, -6), Pair(56, 56), Pair(-146, 96), Pair(-9, -95), Pair(-37, -23),
        Pair(-75, -11), Pair(-101, -80), Pair(61, -72), Pair(74, 61), Pair(123, 94), Pair(88, -26), Pair(0, 0), Pair(241, -53),
        Pair(53, 20), Pair(79, 18), Pair(-162, 54), Pair(-8, -11), Pair(-1, -14), Pair(24, 130), Pair(-4, 37), Pair(135, 188),
        Pair(-9, -58), Pair(11, 34), Pair(-36, -43), Pair(132, -15), Pair(-6, 46), Pair(233, 56), Pair(109, 62), Pair(-5, 66),
        Pair(-152, -80), Pair(95, -68), Pair(36, -37), Pair(13, 19), Pair(5, 52), Pair(75, -24), Pair(127, -31), Pair(-4, 65),
        Pair(-150, 25), Pair(-29, -39), Pair(13, -7), Pair(-49, -35), Pair(-81, 3), Pair(-5, -10), Pair(12, -21), Pair(-35, -34),
        Pair(-19, -99), Pair(1, -62), Pair(101, -53), Pair(-40, -76), Pair(68, -32), Pair(135, -117), Pair(-78, -114), Pair(158, 13),
        Pair(-120, -151), Pair(-113, -129), Pair(-73, 105), Pair(-30, -38), Pair(120, -97), Pair(-75, -44), Pair(-38, -24), Pair(-66, -72)
      },
      { // Piece 2
        Pair(-74, 36), Pair(44, -79), Pair(-2, 96), Pair(-27, -179), Pair(-4, 5), Pair(200, -24), Pair(-80, 9), Pair(32, 41),
        Pair(-59, -29), Pair(-76, 69), Pair(11, -106), Pair(114, -43), Pair(232, -110), Pair(113, 2), Pair(0, 0), Pair(62, 30),
        Pair(14, -68), Pair(96, -129), Pair(-57, -10), Pair(122, -10), Pair(106, 100), Pair(207, -9), Pair(91, 119), Pair(15, -42),
        Pair(-123, -65), Pair(-11, 18), Pair(-32, -67), Pair(252, 72), Pair(136, -43), Pair(-27, 57), Pair(39, 14), Pair(14, 66),
        Pair(-48, 11), Pair(135, -118), Pair(55, -69), Pair(239, -73), Pair(63, 36), Pair(-105, 28), Pair(16, 10), Pair(138, -125),
        Pair(96, -72), Pair(60, -8), Pair(-45, 4), Pair(135, -122), Pair(109, -68), Pair(-20, -3), Pair(106, -77), Pair(-59, 57),
        Pair(124, -10), Pair(49, -25), Pair(63, 7), Pair(83, -49), Pair(85, -72), Pair(-171, 9), Pair(66, 72), Pair(-63, -21),
        Pair(142, 35), Pair(93, -59), Pair(22, -85), Pair(-24, 45), Pair(-188, -66), Pair(-30, -64), Pair(38, -57), Pair(157, 102)
      },
      { // Piece 3
        Pair(-44, 78), Pair(119, 42), Pair(144, 69), Pair(36, 90), Pair(27, 80), Pair(42, 79), Pair(26, -295), Pair(67, 144),
        Pair(218, -95), Pair(61, -28), Pair(56, -30), Pair(191, -84), Pair(122, -66), Pair(85, -21), Pair(0, 0), Pair(-92, 45),
        Pair(-14, 28), Pair(122, -34), Pair(80, -36), Pair(80, -108), Pair(97, 13), Pair(75, 69), Pair(-35, -13), Pair(130, 1),
        Pair(-247, 176), Pair(32, 41), Pair(-18, 84), Pair(-88, 18), Pair(37, 55), Pair(-61, 170), Pair(54, -38), Pair(-44, 70),
        Pair(26, 37), Pair(-184, 21), Pair(123, -76), Pair(105, -56), Pair(94, -50), Pair(-77, 18), Pair(88, -53), Pair(-252, 119),
        Pair(-82, 52), Pair(-87, 30), Pair(-177, 119), Pair(-103, 102), Pair(-91, -16), Pair(-137, 47), Pair(-7, 10), Pair(-99, 25),
        Pair(109, -46), Pair(73, 3), Pair(-71, 57), Pair(26, -52), Pair(-25, -93), Pair(-115, 94), Pair(30, 4), Pair(-49, 120),
        Pair(-80, -53), Pair(14, -23), Pair(15, 38), Pair(33, -53), Pair(-83, 74), Pair(47, -20), Pair(-98, 30), Pair(-80, 25)
      },
      { // Piece 4
        Pair(164, -13), Pair(-147, -139), Pair(-11, -50), Pair(-39, -64), Pair(-45, -31), Pair(215, -120), Pair(3, -5), Pair(162, -74),
        Pair(-35, 48), Pair(23, -51), Pair(53, 70), Pair(43, 58), Pair(13, -100), Pair(221, 31), Pair(0, 0), Pair(-1, -71),
        Pair(90, 27), Pair(-79, -86), Pair(-5, -35), Pair(-66, -1), Pair(63, 6), Pair(56, -4), Pair(1, 56), Pair(91, -1),
        Pair(30, -60), Pair(-32, -33), Pair(-45, -153), Pair(148, -36), Pair(111, -55), Pair(-160, 93), Pair(-15, -65), Pair(-44, 48),
        Pair(80, 2), Pair(-205, -142), Pair(-13, -53), Pair(67, 68), Pair(5, -75), Pair(98, 107), Pair(-148, 131), Pair(182, -73),
        Pair(126, -61), Pair(-116, -3), Pair(-98, -54), Pair(-81, 32), Pair(-29, -6), Pair(-97, 27), Pair(-30, -9), Pair(110, 92),
        Pair(-89, -19), Pair(81, -143), Pair(-147, 44), Pair(-161, 15), Pair(-135, 67), Pair(83, -96), Pair(-31, -66), Pair(35, -34),
        Pair(10, -81), Pair(-94, -94), Pair(-46, 74), Pair(-112, -52), Pair(-94, -216), Pair(33, 34), Pair(-211, -52), Pair(112, 113)
      },
      { // Piece 5
        Pair(2, -17), Pair(11, -58), Pair(27, 86), Pair(26, 119), Pair(19, 145), Pair(-23, 123), Pair(-26, 21), Pair(57, 182),
        Pair(-38, -11), Pair(-27, 3), Pair(56, 12), Pair(60, 99), Pair(17, 55), Pair(-165, 157), Pair(0, 0), Pair(-107, 169),
        Pair(-91, 73), Pair(-35, 9), Pair(-29, 56), Pair(83, -13), Pair(48, 3), Pair(56, -5), Pair(-18, 7), Pair(-21, 39),
        Pair(-39, -55), Pair(9, 30), Pair(-11, 23), Pair(131, -36), Pair(77, -32), Pair(5, 10), Pair(-4, -24), Pair(149, 48),
        Pair(-5, -90), Pair(90, -63), Pair(-43, 26), Pair(10, -42), Pair(2, -48), Pair(49, -72), Pair(22, -18), Pair(84, -50),
        Pair(-76, 40), Pair(47, 96), Pair(-20, -34), Pair(115, -78), Pair(53, -42), Pair(-22, -43), Pair(35, -41), Pair(-15, -44),
        Pair(16, -41), Pair(15, -31), Pair(-57, -13), Pair(39, -50), Pair(53, -81), Pair(43, -66), Pair(-102, -46), Pair(-100, 10),
        Pair(-104, 7), Pair(58, 1), Pair(-40, -4), Pair(-183, 55), Pair(10, 0), Pair(-70, 49), Pair(-55, -5), Pair(-21, -116)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(168, -5), Pair(23, 55), Pair(16, 113), Pair(-61, 82), Pair(61, 75), Pair(-5, 127), Pair(71, 24), Pair(-4, -65),
        Pair(74, 7), Pair(-106, 73), Pair(125, 15), Pair(-25, 68), Pair(-5, 47), Pair(-178, 65), Pair(-91, 1), Pair(38, -2),
        Pair(12, 3), Pair(-27, 9), Pair(23, 34), Pair(31, 11), Pair(12, 21), Pair(141, -42), Pair(24, 27), Pair(42, -35),
        Pair(-24, 57), Pair(-47, 43), Pair(-67, 62), Pair(-9, 12), Pair(16, 16), Pair(18, 4), Pair(-38, 42), Pair(61, -27),
        Pair(6, 40), Pair(-43, 9), Pair(7, 26), Pair(-3, 34), Pair(6, 16), Pair(22, 10), Pair(-46, 49), Pair(7, -59),
        Pair(-23, 32), Pair(11, 17), Pair(-36, 14), Pair(6, 8), Pair(-2, 31), Pair(15, 29), Pair(0, 32), Pair(26, -20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(16, 123), Pair(-4, -29), Pair(8, 56), Pair(25, 99), Pair(83, 53), Pair(4, 95), Pair(28, 36), Pair(80, 120),
        Pair(78, 58), Pair(-16, 32), Pair(-10, 84), Pair(96, 79), Pair(244, -29), Pair(161, 115), Pair(-190, 74), Pair(0, 0),
        Pair(-51, 5), Pair(57, 42), Pair(59, 5), Pair(-23, 132), Pair(171, 77), Pair(162, -21), Pair(180, 107), Pair(79, 16),
        Pair(-33, -3), Pair(153, -48), Pair(185, -97), Pair(221, -52), Pair(109, 103), Pair(142, -58), Pair(192, -101), Pair(21, -14),
        Pair(-87, -54), Pair(-61, 94), Pair(8, -3), Pair(105, -38), Pair(59, -15), Pair(214, -39), Pair(-143, 93), Pair(26, -2),
        Pair(-137, -109), Pair(16, -19), Pair(32, -208), Pair(173, -65), Pair(114, -92), Pair(62, -14), Pair(-13, -79), Pair(42, -29),
        Pair(79, 82), Pair(164, 106), Pair(-7, -3), Pair(2, 37), Pair(-21, -47), Pair(-65, 19), Pair(42, 118), Pair(-198, -79),
        Pair(35, 7), Pair(-26, -134), Pair(86, -15), Pair(20, -24), Pair(-198, -24), Pair(-165, 133), Pair(-22, -149), Pair(-69, -31)
      },
      { // Piece 2
        Pair(16, -135), Pair(-102, -132), Pair(103, -73), Pair(-5, -37), Pair(14, -85), Pair(-19, -117), Pair(136, 28), Pair(11, -19),
        Pair(15, 210), Pair(48, -153), Pair(57, 68), Pair(-143, -94), Pair(110, 9), Pair(219, -52), Pair(59, 101), Pair(0, 0),
        Pair(-49, 18), Pair(48, -4), Pair(-86, -58), Pair(22, 5), Pair(227, -69), Pair(71, 99), Pair(76, 1), Pair(117, -5),
        Pair(-98, 7), Pair(9, -56), Pair(65, 28), Pair(132, -95), Pair(176, 15), Pair(282, -64), Pair(140, -61), Pair(-34, -83),
        Pair(89, -92), Pair(-52, -49), Pair(142, -28), Pair(68, 142), Pair(205, -65), Pair(8, 23), Pair(114, -66), Pair(57, -23),
        Pair(250, -141), Pair(-26, -74), Pair(-100, 31), Pair(68, -52), Pair(2, 16), Pair(-58, -107), Pair(35, 69), Pair(29, -69),
        Pair(-50, -6), Pair(142, 4), Pair(95, -22), Pair(-37, -73), Pair(45, -83), Pair(71, -54), Pair(87, -135), Pair(-163, -132),
        Pair(71, 152), Pair(92, -39), Pair(37, -14), Pair(141, -86), Pair(-277, 69), Pair(-50, -24), Pair(44, 1), Pair(169, -83)
      },
      { // Piece 3
        Pair(10, 57), Pair(4, 76), Pair(-144, 111), Pair(44, 56), Pair(138, 82), Pair(28, 96), Pair(143, 80), Pair(350, -251),
        Pair(127, -66), Pair(93, -83), Pair(82, -66), Pair(237, -125), Pair(135, -52), Pair(180, -56), Pair(20, 40), Pair(0, 0),
        Pair(49, 64), Pair(95, -15), Pair(54, 25), Pair(28, -3), Pair(3, 13), Pair(-42, 73), Pair(-59, 67), Pair(-30, -41),
        Pair(-62, 6), Pair(-105, 27), Pair(-102, 59), Pair(-22, 32), Pair(65, -51), Pair(11, 16), Pair(20, 33), Pair(77, -26),
        Pair(-72, 82), Pair(-26, -49), Pair(-83, 30), Pair(197, -26), Pair(-5, 49), Pair(38, -1), Pair(-76, 122), Pair(6, -5),
        Pair(-47, 99), Pair(-53, -37), Pair(-137, -17), Pair(-124, 98), Pair(-64, 33), Pair(-10, 28), Pair(-6, 54), Pair(102, -29),
        Pair(-110, 21), Pair(61, -6), Pair(-64, 44), Pair(-33, 41), Pair(-10, 11), Pair(11, 38), Pair(37, -2), Pair(26, -58),
        Pair(-58, -16), Pair(-79, -17), Pair(18, -72), Pair(-24, 30), Pair(37, 4), Pair(-66, 37), Pair(-32, 30), Pair(31, -21)
      },
      { // Piece 4
        Pair(56, 52), Pair(25, 50), Pair(0, 33), Pair(-59, -92), Pair(72, 21), Pair(30, 23), Pair(-20, 49), Pair(-2, -112),
        Pair(28, 41), Pair(-20, -152), Pair(-6, 33), Pair(77, -113), Pair(97, 127), Pair(-41, -9), Pair(216, 56), Pair(0, 0),
        Pair(-50, -145), Pair(111, 30), Pair(125, -17), Pair(103, 71), Pair(31, 46), Pair(123, 101), Pair(154, -42), Pair(103, -18),
        Pair(-27, 9), Pair(97, -62), Pair(62, 22), Pair(26, -78), Pair(61, -72), Pair(25, -18), Pair(20, -97), Pair(-99, -102),
        Pair(-81, -143), Pair(-89, 7), Pair(-71, 20), Pair(-19, 39), Pair(189, -36), Pair(0, 0), Pair(-115, 127), Pair(78, -157),
        Pair(-177, -39), Pair(-287, 24), Pair(-64, 71), Pair(23, 31), Pair(133, 110), Pair(-58, 53), Pair(59, -71), Pair(44, -51),
        Pair(-81, -83), Pair(-71, -5), Pair(-77, -113), Pair(7, -92), Pair(-37, -97), Pair(-32, -90), Pair(82, 144), Pair(2, -59),
        Pair(-62, -71), Pair(-169, 23), Pair(-88, -77), Pair(-81, -53), Pair(-187, -10), Pair(-74, 0), Pair(-160, -117), Pair(-60, -42)
      },
      { // Piece 5
        Pair(42, -57), Pair(-8, 56), Pair(-7, -30), Pair(13, 56), Pair(20, -35), Pair(-90, 10), Pair(-8, 83), Pair(-27, -309),
        Pair(74, 10), Pair(42, -39), Pair(-66, -8), Pair(-65, -2), Pair(54, -76), Pair(-145, 55), Pair(120, 149), Pair(0, 0),
        Pair(80, -74), Pair(73, -2), Pair(98, -18), Pair(-37, -15), Pair(-7, -54), Pair(-9, 30), Pair(139, 6), Pair(-95, 51),
        Pair(99, 31), Pair(-104, 12), Pair(74, 2), Pair(28, -3), Pair(4, -43), Pair(-30, 31), Pair(58, 54), Pair(132, 22),
        Pair(28, 33), Pair(-46, 13), Pair(3, 14), Pair(54, -11), Pair(92, -25), Pair(56, 7), Pair(53, 18), Pair(87, -27),
        Pair(-57, 10), Pair(-121, 2), Pair(3, -16), Pair(117, -17), Pair(56, -21), Pair(97, -10), Pair(81, 35), Pair(-75, 41),
        Pair(69, -49), Pair(-137, 69), Pair(-102, 2), Pair(-50, 6), Pair(-19, 10), Pair(18, -5), Pair(-23, 47), Pair(-6, 53),
        Pair(107, 84), Pair(-27, -28), Pair(-106, 21), Pair(-112, 16), Pair(-60, -47), Pair(-58, 42), Pair(20, 5), Pair(31, 84)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-34, -29), Pair(-52, -4), Pair(80, -23), Pair(-56, 81), Pair(-113, 76), Pair(-13, 71), Pair(-66, 26), Pair(74, 7),
        Pair(0, 30), Pair(78, -60), Pair(-49, 14), Pair(2, 36), Pair(-20, 48), Pair(-21, 37), Pair(17, 17), Pair(-7, 16),
        Pair(64, -79), Pair(18, 4), Pair(-3, 3), Pair(-3, 12), Pair(-19, 34), Pair(-44, 33), Pair(2, 8), Pair(-17, 14),
        Pair(17, -12), Pair(8, 31), Pair(-3, 20), Pair(-9, 15), Pair(-5, 26), Pair(-16, 17), Pair(13, 11), Pair(4, 8),
        Pair(0, 50), Pair(-15, 13), Pair(-8, 6), Pair(-11, 17), Pair(-6, 15), Pair(-13, 18), Pair(1, 13), Pair(8, 13),
        Pair(3, 22), Pair(-8, 20), Pair(-13, 24), Pair(-8, 27), Pair(0, 21), Pair(-8, 32), Pair(-7, 19), Pair(3, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(287, -35), Pair(-260, 29), Pair(-1, 74), Pair(140, 26), Pair(-142, 87), Pair(162, -87), Pair(32, -48), Pair(14, -144),
        Pair(-5, 38), Pair(122, -42), Pair(-23, 89), Pair(-31, 52), Pair(-18, 131), Pair(-31, 62), Pair(-158, 72), Pair(-15, 105),
        Pair(0, 0), Pair(-61, 119), Pair(76, 61), Pair(35, 57), Pair(79, 51), Pair(42, 16), Pair(126, -9), Pair(-55, -11),
        Pair(2, 108), Pair(53, 80), Pair(6, 21), Pair(66, 69), Pair(30, 38), Pair(64, 20), Pair(1, 8), Pair(-46, 46),
        Pair(-76, 54), Pair(59, 54), Pair(-28, 86), Pair(50, 22), Pair(-7, 35), Pair(43, 36), Pair(-94, 50), Pair(21, -60),
        Pair(40, 77), Pair(0, 17), Pair(10, 17), Pair(-4, 38), Pair(12, 47), Pair(20, 10), Pair(17, -6), Pair(5, -16),
        Pair(1, 129), Pair(53, 58), Pair(30, 48), Pair(9, -10), Pair(20, 62), Pair(-16, 37), Pair(-158, 143), Pair(-23, 49),
        Pair(-153, 59), Pair(4, -45), Pair(-23, 31), Pair(100, -111), Pair(7, 56), Pair(18, -27), Pair(-18, -7), Pair(-69, 28)
      },
      { // Piece 2
        Pair(-3, -35), Pair(196, 57), Pair(145, -11), Pair(32, 91), Pair(229, -75), Pair(-27, 7), Pair(16, -68), Pair(-54, -4),
        Pair(-115, 81), Pair(118, 54), Pair(92, 21), Pair(316, -51), Pair(15, -6), Pair(123, -64), Pair(-14, -9), Pair(38, -7),
        Pair(0, 0), Pair(64, 67), Pair(83, -34), Pair(-17, 49), Pair(43, -55), Pair(-24, 28), Pair(112, -64), Pair(3, 46),
        Pair(54, 47), Pair(103, -2), Pair(55, 39), Pair(71, 3), Pair(36, 64), Pair(47, -16), Pair(56, 87), Pair(78, -4),
        Pair(65, 37), Pair(68, 23), Pair(62, 27), Pair(57, 49), Pair(80, -14), Pair(64, 63), Pair(172, -54), Pair(83, -42),
        Pair(28, 99), Pair(40, -9), Pair(36, 32), Pair(66, -7), Pair(62, 60), Pair(86, -23), Pair(17, 17), Pair(47, -10),
        Pair(-58, -96), Pair(45, -26), Pair(83, -33), Pair(30, 32), Pair(66, -6), Pair(44, 22), Pair(50, -13), Pair(38, -25),
        Pair(138, -58), Pair(25, -46), Pair(5, -1), Pair(-6, -14), Pair(27, 41), Pair(48, 21), Pair(108, -38), Pair(-15, 32)
      },
      { // Piece 3
        Pair(-8, -2), Pair(31, 158), Pair(-58, 122), Pair(54, 115), Pair(64, 49), Pair(58, 55), Pair(20, 51), Pair(-68, 96),
        Pair(49, -41), Pair(130, 90), Pair(-29, 122), Pair(72, 118), Pair(-63, 130), Pair(-10, 103), Pair(31, 108), Pair(38, 110),
        Pair(0, 0), Pair(149, 64), Pair(114, 20), Pair(118, 16), Pair(61, 21), Pair(125, 36), Pair(32, 54), Pair(-1, 77),
        Pair(-11, 22), Pair(42, 86), Pair(-2, 87), Pair(-20, 44), Pair(-2, 67), Pair(-11, 90), Pair(13, 36), Pair(-25, 52),
        Pair(-45, 32), Pair(39, 73), Pair(39, 100), Pair(-99, 117), Pair(49, 45), Pair(-78, 121), Pair(58, 77), Pair(-44, 76),
        Pair(-23, 27), Pair(-9, 107), Pair(-4, 72), Pair(56, 72), Pair(-26, 115), Pair(29, 27), Pair(28, 9), Pair(-6, 61),
        Pair(-9, 53), Pair(46, 34), Pair(-68, 118), Pair(10, 85), Pair(-49, 78), Pair(-32, 97), Pair(6, 75), Pair(-44, 77),
        Pair(-11, 26), Pair(-34, 123), Pair(19, 66), Pair(7, 73), Pair(-15, 90), Pair(5, 43), Pair(-8, 91), Pair(-13, 52)
      },
      { // Piece 4
        Pair(166, 147), Pair(-41, 180), Pair(-1, 162), Pair(3, 125), Pair(77, 31), Pair(8, 77), Pair(-75, 74), Pair(107, 143),
        Pair(-23, 104), Pair(58, 153), Pair(172, 23), Pair(41, 100), Pair(136, 132), Pair(193, 58), Pair(33, 96), Pair(52, 83),
        Pair(0, 0), Pair(19, 63), Pair(53, 59), Pair(79, 48), Pair(19, 161), Pair(46, 110), Pair(146, -9), Pair(10, 79),
        Pair(95, 104), Pair(76, 61), Pair(62, 114), Pair(122, 142), Pair(78, 139), Pair(86, 76), Pair(23, 112), Pair(25, 93),
        Pair(100, -95), Pair(72, 63), Pair(60, 77), Pair(-26, 177), Pair(109, 89), Pair(69, -12), Pair(-8, 146), Pair(71, 9),
        Pair(-25, 89), Pair(69, -15), Pair(87, 117), Pair(28, 130), Pair(48, 135), Pair(59, 79), Pair(-49, 174), Pair(-49, 171),
        Pair(64, 65), Pair(89, 106), Pair(14, 81), Pair(28, 54), Pair(79, 28), Pair(86, -9), Pair(-32, -14), Pair(9, 79),
        Pair(21, 144), Pair(67, 139), Pair(90, -70), Pair(52, -24), Pair(64, 104), Pair(30, 67), Pair(-15, 35), Pair(41, -95)
      },
      { // Piece 5
        Pair(45, -151), Pair(-120, 87), Pair(-7, 30), Pair(-22, -1), Pair(19, -66), Pair(-24, -130), Pair(-72, -43), Pair(12, -20),
        Pair(-150, -14), Pair(-65, 112), Pair(-83, 64), Pair(45, -11), Pair(51, 12), Pair(-5, -49), Pair(85, -51), Pair(140, -13),
        Pair(0, 0), Pair(218, 49), Pair(185, -13), Pair(-5, 38), Pair(129, 11), Pair(-5, 10), Pair(-46, 15), Pair(-62, 152),
        Pair(95, 12), Pair(201, 1), Pair(-4, 76), Pair(98, 23), Pair(67, 55), Pair(61, 39), Pair(-1, 7), Pair(61, 18),
        Pair(-20, 47), Pair(74, 55), Pair(235, -2), Pair(18, 30), Pair(-59, 42), Pair(34, 23), Pair(-90, 44), Pair(-101, 68),
        Pair(29, 14), Pair(78, 20), Pair(84, 29), Pair(40, 27), Pair(52, 14), Pair(-77, 25), Pair(-117, 45), Pair(9, 3),
        Pair(53, 37), Pair(104, 34), Pair(85, -1), Pair(35, 6), Pair(13, 12), Pair(16, 13), Pair(-29, 10), Pair(-34, 11),
        Pair(39, 98), Pair(66, 4), Pair(-24, 42), Pair(31, 6), Pair(1, -5), Pair(-64, 25), Pair(-17, 15), Pair(-51, 32)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 31), Pair(-20, -116), Pair(20, 0), Pair(36, -19), Pair(71, 21), Pair(-8, -2), Pair(-3, 6), Pair(-106, 73),
        Pair(77, -59), Pair(3, 58), Pair(26, 58), Pair(107, -18), Pair(29, 23), Pair(-3, 47), Pair(16, 38), Pair(-3, 22),
        Pair(29, 43), Pair(66, -97), Pair(6, 23), Pair(-29, 22), Pair(15, 15), Pair(-42, 45), Pair(5, 16), Pair(-29, 35),
        Pair(2, 39), Pair(3, 32), Pair(-9, 40), Pair(1, 17), Pair(-29, 31), Pair(-18, 29), Pair(12, 7), Pair(-12, 18),
        Pair(0, 36), Pair(15, 2), Pair(-11, 34), Pair(4, 20), Pair(-13, 25), Pair(-2, 5), Pair(4, 16), Pair(-23, 34),
        Pair(3, 29), Pair(8, 30), Pair(-27, 37), Pair(-6, 31), Pair(-10, -2), Pair(-8, 29), Pair(-2, 22), Pair(-32, 42),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-24, -64), Pair(-250, -108), Pair(116, -12), Pair(-3, 60), Pair(-127, 27), Pair(9, -13), Pair(-96, -4), Pair(-17, 123),
        Pair(320, -34), Pair(104, -80), Pair(70, 21), Pair(-174, 150), Pair(91, -40), Pair(10, 32), Pair(103, -12), Pair(134, -85),
        Pair(-34, 120), Pair(0, 0), Pair(69, 67), Pair(176, 64), Pair(-5, 23), Pair(188, 58), Pair(85, 25), Pair(49, 90),
        Pair(105, 74), Pair(-17, 121), Pair(25, 123), Pair(117, -41), Pair(85, 76), Pair(97, 50), Pair(72, 12), Pair(124, -14),
        Pair(86, 27), Pair(-17, 133), Pair(104, 62), Pair(20, 27), Pair(42, 16), Pair(33, 29), Pair(-17, 18), Pair(40, 15),
        Pair(-36, 54), Pair(68, 23), Pair(54, -3), Pair(76, 71), Pair(19, 24), Pair(77, -30), Pair(32, 16), Pair(95, -54),
        Pair(-167, 129), Pair(-54, -52), Pair(-46, 43), Pair(64, 15), Pair(-8, 23), Pair(-41, 5), Pair(-84, 129), Pair(19, 34),
        Pair(32, -133), Pair(-40, -40), Pair(104, 68), Pair(-25, 22), Pair(48, -20), Pair(49, -22), Pair(-19, 55), Pair(3, -78)
      },
      { // Piece 2
        Pair(151, 43), Pair(120, 23), Pair(11, -5), Pair(-15, 56), Pair(35, 0), Pair(207, -67), Pair(-7, -10), Pair(-46, -39),
        Pair(34, 101), Pair(47, 79), Pair(77, 53), Pair(-99, -38), Pair(158, -14), Pair(-34, 53), Pair(190, -26), Pair(103, -75),
        Pair(102, 40), Pair(0, 0), Pair(116, 81), Pair(12, 1), Pair(209, -25), Pair(124, 7), Pair(-70, 32), Pair(29, -17),
        Pair(-93, 98), Pair(86, 37), Pair(68, -2), Pair(144, 69), Pair(156, -24), Pair(185, -34), Pair(28, 16), Pair(-24, 20),
        Pair(-48, 30), Pair(-43, 51), Pair(36, 54), Pair(76, 32), Pair(65, 50), Pair(1, 25), Pair(151, -22), Pair(153, 68),
        Pair(109, -36), Pair(10, -7), Pair(49, 35), Pair(87, -6), Pair(56, 20), Pair(40, 50), Pair(16, -39), Pair(-22, 45),
        Pair(-80, 7), Pair(50, -43), Pair(-45, 43), Pair(30, -10), Pair(45, 49), Pair(197, 12), Pair(58, 57), Pair(74, -45),
        Pair(43, 2), Pair(-56, 19), Pair(2, -9), Pair(14, -19), Pair(79, -31), Pair(9, 63), Pair(-98, 21), Pair(-25, 25)
      },
      { // Piece 3
        Pair(115, 87), Pair(34, -10), Pair(19, 132), Pair(-44, 97), Pair(44, 108), Pair(48, 136), Pair(211, 11), Pair(72, 93),
        Pair(-10, 149), Pair(38, -33), Pair(24, 150), Pair(21, 148), Pair(48, 118), Pair(122, 116), Pair(103, 73), Pair(-72, 174),
        Pair(-105, 120), Pair(0, 0), Pair(90, 75), Pair(119, 52), Pair(-26, 104), Pair(189, 32), Pair(54, 87), Pair(122, 38),
        Pair(91, 30), Pair(79, 2), Pair(47, 104), Pair(-45, 154), Pair(100, 97), Pair(109, 62), Pair(90, 80), Pair(-12, 94),
        Pair(52, 70), Pair(-12, 73), Pair(-25, 113), Pair(-62, 145), Pair(0, 121), Pair(4, 120), Pair(-51, 104), Pair(-69, 113),
        Pair(-15, 125), Pair(-41, 67), Pair(-61, 136), Pair(-165, 183), Pair(-68, 137), Pair(-14, 71), Pair(-67, 80), Pair(-63, 115),
        Pair(-98, 172), Pair(21, 67), Pair(-81, 137), Pair(-27, 95), Pair(48, 90), Pair(83, 57), Pair(-24, 101), Pair(8, 107),
        Pair(-19, 92), Pair(-2, 49), Pair(1, 113), Pair(-6, 124), Pair(-1, 103), Pair(-19, 93), Pair(28, 82), Pair(-10, 51)
      },
      { // Piece 4
        Pair(60, -3), Pair(138, 41), Pair(64, 97), Pair(71, -34), Pair(96, 38), Pair(48, 70), Pair(75, -49), Pair(-121, -33),
        Pair(15, 190), Pair(99, 3), Pair(53, 136), Pair(36, 80), Pair(65, 74), Pair(158, 122), Pair(12, 70), Pair(-62, 51),
        Pair(55, 216), Pair(0, 0), Pair(98, 203), Pair(68, 127), Pair(56, 12), Pair(31, 71), Pair(87, -48), Pair(42, 44),
        Pair(-20, 103), Pair(-61, 100), Pair(-48, 211), Pair(27, 121), Pair(46, 127), Pair(62, 107), Pair(27, 4), Pair(-72, 77),
        Pair(-38, 89), Pair(-42, 15), Pair(-41, 114), Pair(-7, 154), Pair(35, 177), Pair(-86, 171), Pair(3, 40), Pair(112, -30),
        Pair(66, 92), Pair(-37, 57), Pair(0, 138), Pair(16, 156), Pair(39, 39), Pair(77, 12), Pair(130, -68), Pair(30, 19),
        Pair(-29, 14), Pair(-26, 45), Pair(-35, 81), Pair(2, 124), Pair(-22, -35), Pair(1, 77), Pair(-45, 70), Pair(149, -4),
        Pair(-29, 71), Pair(42, 51), Pair(38, 35), Pair(27, -16), Pair(19, -9), Pair(-127, 210), Pair(-37, -89), Pair(216, 1)
      },
      { // Piece 5
        Pair(-73, 190), Pair(71, 50), Pair(84, 245), Pair(46, -2), Pair(21, 90), Pair(28, 57), Pair(-53, -104), Pair(32, 122),
        Pair(132, -1), Pair(122, 5), Pair(37, 66), Pair(65, 2), Pair(86, -23), Pair(-14, 110), Pair(197, 25), Pair(22, 166),
        Pair(177, 22), Pair(0, 0), Pair(66, 81), Pair(156, 15), Pair(144, 66), Pair(-3, 37), Pair(7, 46), Pair(-102, 61),
        Pair(128, 9), Pair(277, -13), Pair(203, 7), Pair(249, 16), Pair(159, 10), Pair(-19, 75), Pair(49, -12), Pair(-66, 56),
        Pair(130, 14), Pair(127, 1), Pair(-53, 66), Pair(103, 8), Pair(-56, 56), Pair(-39, 47), Pair(-138, 54), Pair(-70, 58),
        Pair(91, 23), Pair(-30, 0), Pair(56, 48), Pair(56, 2), Pair(-78, 29), Pair(-202, 53), Pair(-174, 56), Pair(-124, 17),
        Pair(-40, 44), Pair(88, -13), Pair(-83, 44), Pair(-22, 20), Pair(-35, 7), Pair(-115, 20), Pair(-75, -1), Pair(-33, 5),
        Pair(46, 90), Pair(64, 24), Pair(57, 9), Pair(-34, -14), Pair(-64, 32), Pair(-91, 24), Pair(-26, -11), Pair(4, -23)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(78, -20), Pair(45, 44), Pair(-99, -47), Pair(32, 20), Pair(-26, 61), Pair(-107, 97), Pair(-42, 48), Pair(125, 15),
        Pair(-49, 13), Pair(26, 58), Pair(9, 19), Pair(31, 7), Pair(47, 16), Pair(-49, 35), Pair(-8, 72), Pair(-25, 7),
        Pair(-40, 26), Pair(23, 32), Pair(36, -40), Pair(13, 40), Pair(5, 18), Pair(-25, 34), Pair(18, 25), Pair(-23, 28),
        Pair(-8, 19), Pair(-1, 30), Pair(14, 12), Pair(-9, 46), Pair(30, 14), Pair(5, 19), Pair(-11, 30), Pair(5, 16),
        Pair(-16, 21), Pair(0, 21), Pair(9, 2), Pair(-7, 21), Pair(23, -14), Pair(14, 14), Pair(10, 1), Pair(2, 18),
        Pair(-10, 16), Pair(11, 20), Pair(-5, 2), Pair(-16, 5), Pair(2, 18), Pair(22, 13), Pair(7, 18), Pair(7, 32),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(117, 226), Pair(69, 66), Pair(-85, 100), Pair(-70, 12), Pair(-2, 134), Pair(66, 64), Pair(51, 101), Pair(12, -53),
        Pair(-14, 118), Pair(-155, 177), Pair(-43, 12), Pair(182, -36), Pair(110, 29), Pair(103, -1), Pair(23, -4), Pair(-7, 46),
        Pair(-95, 165), Pair(13, 99), Pair(0, 0), Pair(95, 84), Pair(146, 56), Pair(61, 41), Pair(-161, 82), Pair(13, 22),
        Pair(-17, 38), Pair(50, 157), Pair(-67, 62), Pair(121, 61), Pair(91, 19), Pair(168, 4), Pair(31, 121), Pair(-27, 10),
        Pair(-98, 68), Pair(-68, 144), Pair(-15, 64), Pair(63, 38), Pair(-70, 73), Pair(17, 73), Pair(137, -40), Pair(104, -7),
        Pair(-1, 7), Pair(-35, 36), Pair(41, 77), Pair(23, 33), Pair(-1, 27), Pair(21, -12), Pair(46, 15), Pair(10, 38),
        Pair(28, 32), Pair(-62, 19), Pair(67, 89), Pair(-18, 44), Pair(50, 54), Pair(55, 32), Pair(47, -62), Pair(59, -62),
        Pair(-170, -69), Pair(-3, 25), Pair(-50, 59), Pair(25, 15), Pair(77, 6), Pair(99, 55), Pair(-41, 69), Pair(103, 55)
      },
      { // Piece 2
        Pair(17, -55), Pair(48, 43), Pair(163, -72), Pair(217, 31), Pair(-12, 28), Pair(66, -25), Pair(15, 13), Pair(103, 64),
        Pair(-193, 99), Pair(-100, 82), Pair(17, 82), Pair(183, -37), Pair(149, 19), Pair(110, -11), Pair(-21, 55), Pair(55, -23),
        Pair(230, -80), Pair(51, 138), Pair(0, 0), Pair(151, 77), Pair(183, 1), Pair(50, 37), Pair(200, -84), Pair(-103, 0),
        Pair(18, 178), Pair(26, 32), Pair(-13, 57), Pair(92, 7), Pair(27, 77), Pair(49, -13), Pair(72, 5), Pair(59, -1),
        Pair(-1, 4), Pair(32, 69), Pair(83, -14), Pair(49, 45), Pair(44, 5), Pair(84, 54), Pair(83, 8), Pair(165, 43),
        Pair(-12, 54), Pair(38, -10), Pair(93, 13), Pair(62, 7), Pair(64, 41), Pair(29, -8), Pair(12, 112), Pair(11, 0),
        Pair(181, -102), Pair(55, 55), Pair(-11, 43), Pair(50, 47), Pair(47, -11), Pair(17, 28), Pair(35, -26), Pair(147, 75),
        Pair(-12, 40), Pair(90, -9), Pair(6, 14), Pair(30, -8), Pair(-41, 67), Pair(-2, -16), Pair(31, 28), Pair(-84, -13)
      },
      { // Piece 3
        Pair(80, 154), Pair(41, 76), Pair(19, 21), Pair(-52, 149), Pair(100, 53), Pair(-120, 124), Pair(-12, 92), Pair(-15, 109),
        Pair(11, 152), Pair(4, 152), Pair(13, 11), Pair(-10, 141), Pair(54, 158), Pair(128, 60), Pair(42, 69), Pair(59, 118),
        Pair(-69, 156), Pair(-39, 139), Pair(0, 0), Pair(26, 133), Pair(-15, 71), Pair(-7, 134), Pair(75, 60), Pair(157, 43),
        Pair(-46, 151), Pair(34, 101), Pair(-62, 59), Pair(-217, 225), Pair(131, 61), Pair(155, 29), Pair(-106, 112), Pair(-17, 146),
        Pair(25, 76), Pair(-86, 119), Pair(-14, 57), Pair(-68, 157), Pair(-74, 129), Pair(92, 59), Pair(39, 108), Pair(46, 87),
        Pair(-65, 122), Pair(-46, 143), Pair(76, 39), Pair(-22, 165), Pair(3, 53), Pair(6, 90), Pair(42, 79), Pair(-63, 69),
        Pair(-14, 88), Pair(-15, 137), Pair(-37, 92), Pair(39, 142), Pair(36, 9), Pair(-30, 83), Pair(-83, 70), Pair(48, 43),
        Pair(-60, 114), Pair(-35, 161), Pair(-6, 62), Pair(-41, 149), Pair(-36, 122), Pair(13, 54), Pair(-30, 107), Pair(-13, 77)
      },
      { // Piece 4
        Pair(103, -27), Pair(17, 111), Pair(65, -5), Pair(77, 26), Pair(62, 41), Pair(9, 48), Pair(9, 35), Pair(93, -106),
        Pair(84, -11), Pair(-31, 127), Pair(-180, -80), Pair(187, 73), Pair(236, -4), Pair(215, 94), Pair(39, 208), Pair(-16, 20),
        Pair(-96, 180), Pair(-34, 109), Pair(0, 0), Pair(-175, 285), Pair(42, 133), Pair(-26, 55), Pair(111, 20), Pair(139, -51),
        Pair(30, 21), Pair(10, 76), Pair(63, 43), Pair(-1, 120), Pair(7, 199), Pair(50, 85), Pair(-61, 108), Pair(43, -26),
        Pair(65, -101), Pair(47, -17), Pair(13, 167), Pair(39, 57), Pair(-55, 182), Pair(-64, 179), Pair(-69, 187), Pair(33, 15),
        Pair(49, -1), Pair(9, 55), Pair(7, 123), Pair(19, 81), Pair(-36, 63), Pair(9, 110), Pair(-31, 187), Pair(38, -95),
        Pair(126, -109), Pair(33, -34), Pair(57, -57), Pair(23, -14), Pair(-14, 29), Pair(69, -107), Pair(165, -80), Pair(-66, -10),
        Pair(0, -5), Pair(-7, -121), Pair(-11, 88), Pair(26, -17), Pair(50, -58), Pair(6, -62), Pair(-43, -117), Pair(-42, -20)
      },
      { // Piece 5
        Pair(25, 101), Pair(-38, 158), Pair(101, 82), Pair(20, 115), Pair(-7, -23), Pair(10, -9), Pair(-22, 61), Pair(34, 65),
        Pair(-27, 112), Pair(77, 49), Pair(56, 58), Pair(86, 65), Pair(201, 17), Pair(-106, 24), Pair(16, 48), Pair(9, -16),
        Pair(85, 91), Pair(278, 28), Pair(0, 0), Pair(144, 94), Pair(177, 10), Pair(-83, 68), Pair(-21, 35), Pair(24, -8),
        Pair(-9, 110), Pair(-45, 78), Pair(156, 47), Pair(280, 12), Pair(112, 62), Pair(24, 50), Pair(-88, 88), Pair(-129, 66),
        Pair(57, 74), Pair(164, 19), Pair(-77, 47), Pair(61, 60), Pair(155, -14), Pair(-75, 47), Pair(-101, 45), Pair(-99, -14),
        Pair(199, -3), Pair(89, 0), Pair(-18, 9), Pair(9, 32), Pair(60, 8), Pair(-31, -1), Pair(1, -33), Pair(-49, -1),
        Pair(127, -16), Pair(115, -12), Pair(41, 11), Pair(5, 12), Pair(-141, 54), Pair(-32, -21), Pair(-47, 7), Pair(-35, 1),
        Pair(146, -131), Pair(5, 21), Pair(-31, 36), Pair(-19, -45), Pair(-68, -26), Pair(-65, 4), Pair(-55, 0), Pair(-41, 7)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(191, -20), Pair(-22, -8), Pair(-20, 2), Pair(-165, -91), Pair(91, -28), Pair(54, 66), Pair(67, -10), Pair(-25, 68),
        Pair(2, 35), Pair(107, -17), Pair(32, 7), Pair(14, 23), Pair(-10, 10), Pair(-8, 19), Pair(30, 26), Pair(-23, 31),
        Pair(40, 19), Pair(9, 17), Pair(45, 27), Pair(3, -41), Pair(41, 35), Pair(16, 27), Pair(6, 24), Pair(-4, 21),
        Pair(-5, 19), Pair(-6, 12), Pair(-14, 44), Pair(1, -2), Pair(-17, 49), Pair(-8, 25), Pair(6, 7), Pair(-13, 23),
        Pair(-16, 26), Pair(0, 7), Pair(1, 5), Pair(-32, 22), Pair(-4, 26), Pair(3, 3), Pair(-16, 14), Pair(-4, 9),
        Pair(-11, 19), Pair(-11, 27), Pair(-6, 20), Pair(-8, 19), Pair(-25, 58), Pair(-3, 9), Pair(0, 11), Pair(-4, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(120, 34), Pair(67, 80), Pair(127, 86), Pair(-29, 61), Pair(-61, 70), Pair(-11, 198), Pair(-60, 58), Pair(119, 208),
        Pair(-21, -20), Pair(35, 96), Pair(80, 117), Pair(97, -41), Pair(102, 94), Pair(154, 98), Pair(-11, 92), Pair(161, 34),
        Pair(-74, 99), Pair(121, 56), Pair(65, 105), Pair(0, 0), Pair(159, 126), Pair(62, 102), Pair(105, 143), Pair(243, -16),
        Pair(-13, 46), Pair(62, 38), Pair(82, 132), Pair(78, 103), Pair(44, 135), Pair(100, 26), Pair(41, 128), Pair(-57, 138),
        Pair(27, 143), Pair(20, 16), Pair(46, 91), Pair(34, 80), Pair(59, 118), Pair(-25, 63), Pair(19, 111), Pair(90, 0),
        Pair(-4, 52), Pair(82, 60), Pair(2, 52), Pair(-46, 170), Pair(32, 48), Pair(27, 42), Pair(28, 58), Pair(26, 61),
        Pair(-15, -40), Pair(-15, 78), Pair(4, 62), Pair(-15, 77), Pair(-3, 77), Pair(-9, 70), Pair(17, -71), Pair(-13, -18),
        Pair(-80, 49), Pair(-33, 35), Pair(52, 72), Pair(-41, 19), Pair(85, -10), Pair(24, -12), Pair(0, -25), Pair(107, -43)
      },
      { // Piece 2
        Pair(100, 61), Pair(76, -63), Pair(300, 70), Pair(72, -23), Pair(97, 87), Pair(76, 58), Pair(20, 86), Pair(95, 30),
        Pair(14, 7), Pair(38, 19), Pair(-29, 124), Pair(81, -4), Pair(176, 20), Pair(55, 56), Pair(169, -37), Pair(7, -79),
        Pair(57, 51), Pair(2, 23), Pair(70, 88), Pair(0, 0), Pair(233, 57), Pair(44, 54), Pair(29, 30), Pair(-19, 4),
        Pair(87, -8), Pair(12, 130), Pair(-26, 92), Pair(65, 90), Pair(67, 15), Pair(61, 81), Pair(19, 48), Pair(58, 76),
        Pair(79, 133), Pair(-2, 85), Pair(36, 61), Pair(74, 3), Pair(42, 90), Pair(3, 30), Pair(-30, 139), Pair(59, 32),
        Pair(7, 31), Pair(50, 102), Pair(2, 13), Pair(12, 30), Pair(21, 1), Pair(47, 32), Pair(26, 55), Pair(-8, 82),
        Pair(9, 11), Pair(-14, 16), Pair(106, 23), Pair(16, 0), Pair(-4, 74), Pair(26, 6), Pair(32, 64), Pair(58, 42),
        Pair(28, -88), Pair(2, 43), Pair(-14, -24), Pair(91, 70), Pair(1, -26), Pair(-11, 38), Pair(-16, 70), Pair(101, -40)
      },
      { // Piece 3
        Pair(-22, 186), Pair(81, 118), Pair(56, 152), Pair(-14, 68), Pair(-14, 147), Pair(-34, 157), Pair(-25, 130), Pair(-78, 108),
        Pair(-21, 165), Pair(28, 111), Pair(-3, 154), Pair(-155, 46), Pair(-10, 159), Pair(12, 165), Pair(-16, 110), Pair(21, 126),
        Pair(-49, 117), Pair(3, 58), Pair(17, 86), Pair(0, 0), Pair(66, 119), Pair(46, 64), Pair(116, 38), Pair(-114, 145),
        Pair(-42, 113), Pair(-6, 75), Pair(-78, 138), Pair(-34, 64), Pair(-124, 165), Pair(82, 39), Pair(-24, 50), Pair(21, 76),
        Pair(-21, 67), Pair(-8, 79), Pair(-13, 96), Pair(-83, 106), Pair(-71, 140), Pair(80, 75), Pair(-54, 157), Pair(16, 60),
        Pair(-39, 66), Pair(-26, 119), Pair(-50, 158), Pair(16, 48), Pair(-38, 127), Pair(23, 57), Pair(-16, 72), Pair(-31, 100),
        Pair(2, 48), Pair(-7, 99), Pair(-2, 103), Pair(-2, 63), Pair(-78, 140), Pair(-97, 117), Pair(43, 43), Pair(-84, 135),
        Pair(-35, 89), Pair(4, 70), Pair(-25, 94), Pair(16, 64), Pair(-37, 115), Pair(-10, 41), Pair(-30, 80), Pair(-29, 89)
      },
      { // Piece 4
        Pair(4, 177), Pair(-37, 96), Pair(318, 11), Pair(62, 7), Pair(-60, 244), Pair(29, 45), Pair(9, 28), Pair(44, 53),
        Pair(-19, 104), Pair(49, 102), Pair(113, 91), Pair(26, 155), Pair(-30, 222), Pair(65, 225), Pair(22, 19), Pair(35, 143),
        Pair(-69, 126), Pair(-91, 183), Pair(-4, 266), Pair(0, 0), Pair(5, 200), Pair(-7, 168), Pair(14, 116), Pair(212, -149),
        Pair(75, 42), Pair(-26, 134), Pair(-23, 55), Pair(23, 25), Pair(75, -14), Pair(8, 138), Pair(64, 45), Pair(31, 136),
        Pair(7, 60), Pair(104, -1), Pair(-31, 142), Pair(42, 106), Pair(-34, 175), Pair(-29, 65), Pair(27, 153), Pair(-40, 123),
        Pair(41, -15), Pair(12, 82), Pair(-16, 130), Pair(30, 78), Pair(-71, 200), Pair(-20, 83), Pair(85, -11), Pair(54, -32),
        Pair(40, 54), Pair(-7, 50), Pair(64, 25), Pair(33, -14), Pair(-9, 163), Pair(56, 21), Pair(-70, 52), Pair(55, -58),
        Pair(67, -4), Pair(-9, 63), Pair(7, 69), Pair(4, 55), Pair(22, -66), Pair(52, -80), Pair(131, -33), Pair(14, -124)
      },
      { // Piece 5
        Pair(47, 25), Pair(51, 56), Pair(77, 155), Pair(114, 102), Pair(4, 103), Pair(80, 103), Pair(19, 87), Pair(17, 60),
        Pair(27, -3), Pair(73, 4), Pair(163, 38), Pair(-82, 57), Pair(34, 63), Pair(55, 94), Pair(-18, 37), Pair(26, 30),
        Pair(101, -29), Pair(116, -21), Pair(-50, 106), Pair(0, 0), Pair(177, 27), Pair(-136, 115), Pair(30, 26), Pair(-54, 62),
        Pair(27, -35), Pair(74, 23), Pair(214, 23), Pair(84, 57), Pair(139, -3), Pair(74, 18), Pair(-14, 55), Pair(35, 41),
        Pair(-65, 20), Pair(128, -32), Pair(-21, 45), Pair(45, 3), Pair(-66, 61), Pair(-1, -15), Pair(-153, 12), Pair(-97, 1),
        Pair(50, -18), Pair(37, -13), Pair(-69, 13), Pair(32, -15), Pair(-11, 28), Pair(-62, 6), Pair(-39, 0), Pair(-162, 7),
        Pair(-53, -33), Pair(-5, -10), Pair(-34, 4), Pair(-22, -17), Pair(-37, 8), Pair(-8, -4), Pair(-41, -29), Pair(37, -34),
        Pair(-56, 120), Pair(30, -81), Pair(28, -19), Pair(-26, -39), Pair(5, -26), Pair(-12, -44), Pair(13, -16), Pair(1, -72)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-70, 72), Pair(90, -9), Pair(-52, 141), Pair(-91, 52), Pair(50, -78), Pair(58, 0), Pair(-23, 46), Pair(-5, 47),
        Pair(-20, 48), Pair(29, 22), Pair(47, 16), Pair(-10, 10), Pair(13, 17), Pair(-51, 69), Pair(1, 15), Pair(-24, 25),
        Pair(-20, 42), Pair(-25, 44), Pair(21, -10), Pair(13, 38), Pair(7, -10), Pair(49, 29), Pair(-35, 30), Pair(13, -3),
        Pair(-13, 34), Pair(-8, 30), Pair(6, 9), Pair(-4, 35), Pair(7, -8), Pair(-19, 51), Pair(-20, 24), Pair(-3, -2),
        Pair(-12, 38), Pair(-5, 11), Pair(-1, 15), Pair(6, 15), Pair(7, -13), Pair(-9, 33), Pair(-15, 11), Pair(-25, 14),
        Pair(-13, 26), Pair(-4, 18), Pair(-12, 7), Pair(0, 19), Pair(-3, 30), Pair(-1, 14), Pair(-6, 33), Pair(-17, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-25, -3), Pair(-87, 40), Pair(163, 192), Pair(59, -7), Pair(26, 63), Pair(-62, 36), Pair(143, 119), Pair(-28, 323),
        Pair(-42, -12), Pair(-17, 20), Pair(49, 21), Pair(75, 92), Pair(-17, 53), Pair(56, 26), Pair(195, 97), Pair(201, -39),
        Pair(19, 14), Pair(210, 64), Pair(122, 40), Pair(48, 91), Pair(0, 0), Pair(3, 75), Pair(89, 75), Pair(144, 39),
        Pair(22, 31), Pair(3, 54), Pair(107, -12), Pair(76, 134), Pair(104, -12), Pair(218, 88), Pair(38, 47), Pair(-4, 111),
        Pair(-32, 105), Pair(36, -2), Pair(63, 0), Pair(47, 69), Pair(49, 64), Pair(61, 65), Pair(44, 30), Pair(33, 72),
        Pair(-39, 30), Pair(-37, 42), Pair(-17, 40), Pair(-90, 42), Pair(24, 58), Pair(1, 22), Pair(45, 28), Pair(-43, 123),
        Pair(-48, 90), Pair(-18, -1), Pair(55, 37), Pair(-15, 13), Pair(17, 9), Pair(54, -29), Pair(36, 32), Pair(29, 0),
        Pair(69, -6), Pair(-40, -59), Pair(80, -17), Pair(-152, 36), Pair(-148, 131), Pair(57, -48), Pair(-49, 71), Pair(-57, -28)
      },
      { // Piece 2
        Pair(56, -103), Pair(30, 12), Pair(-38, -90), Pair(172, 70), Pair(67, -6), Pair(-10, -16), Pair(212, -30), Pair(-30, 112),
        Pair(-4, 77), Pair(65, -78), Pair(67, -1), Pair(-17, 101), Pair(48, 22), Pair(33, 25), Pair(-28, 58), Pair(-103, -72),
        Pair(56, -92), Pair(73, 36), Pair(19, -4), Pair(291, -1), Pair(0, 0), Pair(89, 50), Pair(86, 11), Pair(76, 95),
        Pair(43, 29), Pair(56, -16), Pair(74, 30), Pair(102, 1), Pair(90, 66), Pair(16, 12), Pair(-13, 133), Pair(-70, 7),
        Pair(-60, 25), Pair(12, 78), Pair(45, 0), Pair(4, 81), Pair(106, -23), Pair(28, 88), Pair(20, -22), Pair(52, 121),
        Pair(56, 70), Pair(17, 3), Pair(-6, 79), Pair(39, -21), Pair(29, 23), Pair(57, -20), Pair(-7, 47), Pair(42, -36),
        Pair(99, 12), Pair(4, 75), Pair(-31, -41), Pair(13, 12), Pair(31, -21), Pair(-13, 42), Pair(57, -21), Pair(-76, -56),
        Pair(6, -38), Pair(116, 7), Pair(7, 30), Pair(130, -50), Pair(19, -3), Pair(32, -14), Pair(78, -54), Pair(10, 73)
      },
      { // Piece 3
        Pair(-67, 115), Pair(-50, 110), Pair(45, 120), Pair(-6, 144), Pair(60, -35), Pair(-52, 125), Pair(-69, 130), Pair(-77, 103),
        Pair(17, 98), Pair(65, 101), Pair(205, 38), Pair(-87, 161), Pair(-189, 6), Pair(7, 82), Pair(-40, 95), Pair(-42, 160),
        Pair(-2, 87), Pair(-27, 50), Pair(204, -29), Pair(198, 17), Pair(0, 0), Pair(26, 77), Pair(26, 108), Pair(25, 81),
        Pair(-59, 130), Pair(-1, 85), Pair(49, 59), Pair(45, 102), Pair(131, -56), Pair(-86, 88), Pair(56, 30), Pair(-4, 72),
        Pair(28, 41), Pair(-58, 21), Pair(30, 39), Pair(59, 43), Pair(8, 64), Pair(57, 56), Pair(126, 24), Pair(-5, 56),
        Pair(-104, 113), Pair(-100, 76), Pair(-15, 64), Pair(-119, 141), Pair(78, -15), Pair(24, 35), Pair(-54, 62), Pair(-45, 3),
        Pair(-40, 126), Pair(-92, 72), Pair(43, 38), Pair(-109, 126), Pair(7, 27), Pair(-56, 95), Pair(-62, 81), Pair(-43, 92),
        Pair(-44, 59), Pair(-7, 16), Pair(-25, 49), Pair(-80, 107), Pair(56, -16), Pair(-52, 105), Pair(-35, 54), Pair(-23, 43)
      },
      { // Piece 4
        Pair(53, 113), Pair(62, 88), Pair(93, 70), Pair(134, 12), Pair(127, 7), Pair(83, 36), Pair(-66, 132), Pair(50, 59),
        Pair(-10, -57), Pair(47, 56), Pair(6, 50), Pair(103, 166), Pair(73, -25), Pair(75, 55), Pair(90, 101), Pair(87, 50),
        Pair(-74, 71), Pair(-22, 60), Pair(13, 34), Pair(114, -15), Pair(0, 0), Pair(163, 102), Pair(48, -43), Pair(11, 92),
        Pair(4, 43), Pair(-32, 46), Pair(24, 106), Pair(46, -65), Pair(-4, 122), Pair(85, -28), Pair(90, 94), Pair(91, -89),
        Pair(38, -154), Pair(-15, 39), Pair(74, 66), Pair(-31, 87), Pair(34, -53), Pair(11, 131), Pair(13, -75), Pair(-37, 171),
        Pair(65, -107), Pair(-10, 14), Pair(18, 33), Pair(62, -3), Pair(30, 36), Pair(-34, 21), Pair(124, 2), Pair(35, -73),
        Pair(71, 42), Pair(-93, 52), Pair(16, -101), Pair(-18, 128), Pair(-6, 29), Pair(3, -24), Pair(46, -44), Pair(-21, 11),
        Pair(-119, 55), Pair(88, 45), Pair(5, -129), Pair(-25, 116), Pair(23, -43), Pair(-35, -69), Pair(-41, -99), Pair(53, -227)
      },
      { // Piece 5
        Pair(-10, -84), Pair(-6, -126), Pair(40, -43), Pair(29, 93), Pair(61, 90), Pair(-26, 198), Pair(34, 78), Pair(19, 126),
        Pair(2, 15), Pair(11, -24), Pair(117, 31), Pair(-14, 93), Pair(-77, 65), Pair(32, 87), Pair(40, 41), Pair(30, -18),
        Pair(43, 20), Pair(-3, 51), Pair(4, 10), Pair(-8, 98), Pair(0, 0), Pair(175, 51), Pair(233, -44), Pair(31, 8),
        Pair(80, 104), Pair(21, 2), Pair(-126, 59), Pair(66, 26), Pair(9, 32), Pair(276, -28), Pair(-20, 45), Pair(25, -45),
        Pair(85, -20), Pair(-123, 35), Pair(-155, 27), Pair(-43, 26), Pair(-59, 22), Pair(14, 17), Pair(-45, 13), Pair(-186, 54),
        Pair(-67, -17), Pair(129, -52), Pair(-34, 5), Pair(91, -24), Pair(-32, -12), Pair(13, -14), Pair(56, -52), Pair(-83, 3),
        Pair(-45, 31), Pair(14, -36), Pair(-10, -31), Pair(-81, 30), Pair(-53, -22), Pair(22, -34), Pair(41, -27), Pair(21, -36),
        Pair(-29, -3), Pair(46, -56), Pair(52, -86), Pair(-30, -34), Pair(-71, 43), Pair(-55, 8), Pair(43, -65), Pair(82, -38)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-86, 60), Pair(9, 73), Pair(-165, 25), Pair(-31, 33), Pair(34, -4), Pair(96, -221), Pair(170, -47), Pair(-178, 65),
        Pair(-21, 37), Pair(-4, 47), Pair(-49, 35), Pair(-8, 18), Pair(-52, 69), Pair(7, -13), Pair(29, -8), Pair(-32, 13),
        Pair(-10, 18), Pair(-60, 45), Pair(-14, 23), Pair(-3, 4), Pair(29, 41), Pair(-93, -23), Pair(27, 22), Pair(-24, 18),
        Pair(-3, 19), Pair(2, 12), Pair(8, 0), Pair(29, 18), Pair(19, 24), Pair(-5, 3), Pair(-14, 36), Pair(-6, 20),
        Pair(0, 12), Pair(-22, 15), Pair(2, 7), Pair(2, 5), Pair(0, 33), Pair(-55, 16), Pair(-11, 17), Pair(-17, 13),
        Pair(2, 21), Pair(-14, 6), Pair(3, 5), Pair(-3, 20), Pair(0, 32), Pair(-18, 7), Pair(13, 15), Pair(-10, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-22, -98), Pair(7, 68), Pair(-100, -2), Pair(146, 71), Pair(16, 1), Pair(-81, -45), Pair(-112, 42), Pair(12, 88),
        Pair(33, 38), Pair(80, -23), Pair(-6, 45), Pair(4, 57), Pair(79, 24), Pair(-23, -20), Pair(-153, 115), Pair(154, 63),
        Pair(-46, 37), Pair(3, 27), Pair(-33, 64), Pair(32, 84), Pair(38, 43), Pair(0, 0), Pair(73, 85), Pair(-71, 134),
        Pair(-255, 84), Pair(-27, 42), Pair(80, 24), Pair(26, 27), Pair(111, 97), Pair(125, 9), Pair(16, 102), Pair(16, 19),
        Pair(-97, 69), Pair(73, 23), Pair(-25, 70), Pair(-5, 43), Pair(22, 67), Pair(-27, 64), Pair(-40, 60), Pair(-15, 0),
        Pair(-57, 3), Pair(-52, 12), Pair(-25, 63), Pair(20, 49), Pair(-47, 47), Pair(6, 33), Pair(25, 3), Pair(35, -72),
        Pair(113, 28), Pair(59, -71), Pair(-36, 29), Pair(4, 24), Pair(7, 15), Pair(-79, 67), Pair(-66, -17), Pair(123, -25),
        Pair(-91, 57), Pair(-21, -17), Pair(-41, 0), Pair(-94, 32), Pair(15, -18), Pair(-57, -20), Pair(-17, -68), Pair(82, -17)
      },
      { // Piece 2
        Pair(-125, -108), Pair(29, -148), Pair(80, -28), Pair(95, 4), Pair(-51, 146), Pair(31, -38), Pair(62, -11), Pair(-3, 27),
        Pair(56, -70), Pair(114, -2), Pair(72, -36), Pair(152, -76), Pair(54, 5), Pair(151, -21), Pair(73, -47), Pair(65, 5),
        Pair(-4, 32), Pair(9, -25), Pair(13, 41), Pair(21, -10), Pair(147, 12), Pair(0, 0), Pair(70, 17), Pair(-27, 19),
        Pair(43, -45), Pair(60, -9), Pair(28, -8), Pair(102, 57), Pair(-25, 11), Pair(-88, 84), Pair(-30, -6), Pair(-27, 79),
        Pair(-103, 3), Pair(53, -73), Pair(16, 56), Pair(62, 11), Pair(0, 86), Pair(-22, 10), Pair(33, 38), Pair(14, 16),
        Pair(63, -100), Pair(52, -2), Pair(52, -30), Pair(-36, 61), Pair(14, -32), Pair(71, 28), Pair(-120, 24), Pair(117, -93),
        Pair(194, -28), Pair(-33, -13), Pair(73, -59), Pair(-11, -71), Pair(18, 0), Pair(2, -33), Pair(30, 48), Pair(-63, -43),
        Pair(-67, 14), Pair(-143, 95), Pair(-47, -17), Pair(69, -26), Pair(-133, -27), Pair(-14, 21), Pair(67, -10), Pair(47, 8)
      },
      { // Piece 3
        Pair(215, 41), Pair(-37, 72), Pair(138, 29), Pair(-57, 112), Pair(3, 100), Pair(121, -13), Pair(-14, 129), Pair(137, 26),
        Pair(11, 71), Pair(69, 34), Pair(5, 61), Pair(51, 49), Pair(-91, 118), Pair(-138, -15), Pair(-85, 97), Pair(4, 52),
        Pair(-23, 50), Pair(65, -6), Pair(48, 27), Pair(30, 9), Pair(82, 63), Pair(0, 0), Pair(-66, 126), Pair(7, 84),
        Pair(108, 24), Pair(-44, 33), Pair(108, 20), Pair(-55, 25), Pair(-58, 81), Pair(-68, 46), Pair(143, -14), Pair(-2, 25),
        Pair(-51, 55), Pair(-1, -10), Pair(-94, 83), Pair(-69, 62), Pair(-158, 122), Pair(17, 9), Pair(-76, 87), Pair(-26, -11),
        Pair(-55, 137), Pair(-22, 35), Pair(-109, 70), Pair(-113, 99), Pair(47, -6), Pair(4, 27), Pair(55, -2), Pair(3, 35),
        Pair(-148, 39), Pair(-144, 92), Pair(-77, 17), Pair(34, -2), Pair(-3, 83), Pair(-6, 17), Pair(12, 15), Pair(-10, 20),
        Pair(-101, 56), Pair(-54, 85), Pair(-70, 48), Pair(-30, 40), Pair(-22, 39), Pair(43, -48), Pair(18, 44), Pair(-12, 68)
      },
      { // Piece 4
        Pair(35, -79), Pair(118, 29), Pair(-89, 97), Pair(137, 36), Pair(113, 60), Pair(-55, -4), Pair(6, 94), Pair(49, -140),
        Pair(53, 5), Pair(-20, 55), Pair(41, 17), Pair(17, 5), Pair(99, 134), Pair(102, -168), Pair(21, 30), Pair(4, -9),
        Pair(12, 27), Pair(-107, 59), Pair(-74, -14), Pair(82, 200), Pair(-18, 99), Pair(0, 0), Pair(62, -11), Pair(29, -8),
        Pair(82, 21), Pair(-38, 130), Pair(5, -60), Pair(-92, 162), Pair(-33, 176), Pair(69, -65), Pair(102, 112), Pair(86, 85),
        Pair(19, -40), Pair(-24, 25), Pair(-11, 90), Pair(119, 4), Pair(69, -8), Pair(16, 68), Pair(8, 89), Pair(54, -69),
        Pair(-82, 97), Pair(-118, 193), Pair(-38, 63), Pair(38, -18), Pair(-7, 1), Pair(4, -24), Pair(12, 52), Pair(39, -10),
        Pair(30, 27), Pair(5, 0), Pair(48, 11), Pair(0, 89), Pair(-13, 15), Pair(48, -149), Pair(12, -74), Pair(165, -34),
        Pair(36, -3), Pair(-31, 107), Pair(-67, 0), Pair(-16, -31), Pair(30, -14), Pair(-108, 121), Pair(122, -4), Pair(-17, 28)
      },
      { // Piece 5
        Pair(1, 64), Pair(35, 89), Pair(-36, 24), Pair(88, -79), Pair(-114, 50), Pair(-13, 119), Pair(42, 144), Pair(-58, 85),
        Pair(-42, -66), Pair(-53, 16), Pair(27, -2), Pair(-7, 58), Pair(75, 38), Pair(-132, 83), Pair(56, 87), Pair(1, 111),
        Pair(11, 60), Pair(69, -22), Pair(96, 19), Pair(113, -2), Pair(-63, 62), Pair(0, 0), Pair(193, 47), Pair(340, -5),
        Pair(7, -25), Pair(-67, 55), Pair(192, -23), Pair(27, 31), Pair(121, 13), Pair(-18, 5), Pair(57, 26), Pair(56, 16),
        Pair(-117, -33), Pair(12, 12), Pair(-42, 18), Pair(70, -19), Pair(39, 14), Pair(24, 39), Pair(6, 45), Pair(89, 11),
        Pair(51, -61), Pair(-28, -19), Pair(-47, -17), Pair(-68, -12), Pair(101, -37), Pair(91, -22), Pair(8, -3), Pair(-45, 32),
        Pair(-14, -39), Pair(-108, -18), Pair(-74, -10), Pair(-75, 2), Pair(38, -45), Pair(-2, -11), Pair(-39, 4), Pair(25, -10),
        Pair(-42, -164), Pair(-24, -45), Pair(28, -90), Pair(-31, -67), Pair(-5, -14), Pair(-47, -20), Pair(40, -10), Pair(-12, -5)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-124, 27), Pair(1, -28), Pair(-74, -10), Pair(-47, 11), Pair(-15, 87), Pair(-16, -25), Pair(-8, -82), Pair(-90, 1),
        Pair(17, 17), Pair(16, 39), Pair(-9, 71), Pair(31, 26), Pair(3, 15), Pair(29, -9), Pair(9, 29), Pair(-41, -11),
        Pair(-9, 25), Pair(12, 24), Pair(36, 9), Pair(18, -1), Pair(-20, 32), Pair(7, 15), Pair(28, -20), Pair(29, 11),
        Pair(20, 16), Pair(16, 8), Pair(2, -1), Pair(11, 4), Pair(5, -4), Pair(-8, 39), Pair(34, -22), Pair(18, 30),
        Pair(-2, 36), Pair(-2, 14), Pair(10, 16), Pair(10, -12), Pair(-2, -1), Pair(-35, 34), Pair(13, -8), Pair(1, 53),
        Pair(0, 15), Pair(7, 1), Pair(-6, 12), Pair(5, -17), Pair(1, 12), Pair(-17, 29), Pair(5, 9), Pair(12, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(17, -33), Pair(-30, 43), Pair(-137, -69), Pair(148, 40), Pair(68, 130), Pair(-21, -27), Pair(-29, 19), Pair(74, -19),
        Pair(-289, -27), Pair(-216, 37), Pair(0, 60), Pair(-41, 65), Pair(-33, 4), Pair(142, 2), Pair(32, -43), Pair(100, -22),
        Pair(36, 48), Pair(-69, 8), Pair(34, -34), Pair(-18, 23), Pair(36, 34), Pair(9, 28), Pair(0, 0), Pair(169, -18),
        Pair(17, -1), Pair(-91, 84), Pair(25, -4), Pair(74, 29), Pair(-12, -25), Pair(29, 118), Pair(0, 41), Pair(49, 22),
        Pair(-81, 37), Pair(39, 32), Pair(-10, -7), Pair(13, 30), Pair(-12, 38), Pair(19, 6), Pair(24, 94), Pair(24, 32),
        Pair(-45, 34), Pair(-93, -7), Pair(0, -5), Pair(-17, 5), Pair(-36, 53), Pair(-15, 22), Pair(-60, 42), Pair(-73, 105),
        Pair(-212, 126), Pair(-95, 83), Pair(-42, -25), Pair(-41, 20), Pair(-16, 16), Pair(-49, -16), Pair(-122, 38), Pair(0, -57),
        Pair(-157, 92), Pair(-57, -30), Pair(-99, 38), Pair(50, -5), Pair(-88, 3), Pair(-96, -50), Pair(-24, -55), Pair(52, -101)
      },
      { // Piece 2
        Pair(29, -114), Pair(273, 67), Pair(-22, -73), Pair(-54, -54), Pair(-74, -37), Pair(53, 16), Pair(-46, 75), Pair(27, 141),
        Pair(-52, -17), Pair(123, -93), Pair(19, 33), Pair(173, -96), Pair(-116, 2), Pair(17, -12), Pair(-16, 4), Pair(13, -7),
        Pair(26, 38), Pair(199, -117), Pair(-74, 9), Pair(28, 1), Pair(136, -93), Pair(206, 9), Pair(0, 0), Pair(83, -4),
        Pair(17, 12), Pair(94, -41), Pair(-16, -3), Pair(-39, -26), Pair(124, 28), Pair(43, -43), Pair(-9, -34), Pair(-20, -42),
        Pair(22, -44), Pair(-3, -35), Pair(2, -29), Pair(54, 7), Pair(21, -28), Pair(-74, 74), Pair(45, -77), Pair(12, -6),
        Pair(23, 33), Pair(-44, -30), Pair(38, -6), Pair(37, -12), Pair(-25, 2), Pair(14, -53), Pair(-107, 58), Pair(3, -2),
        Pair(257, -69), Pair(5, 3), Pair(84, -60), Pair(-15, -5), Pair(-23, -51), Pair(-96, 10), Pair(-27, -44), Pair(45, -58),
        Pair(166, 8), Pair(17, -55), Pair(-36, -35), Pair(62, -56), Pair(95, -138), Pair(-13, -20), Pair(31, -25), Pair(-6, -71)
      },
      { // Piece 3
        Pair(-42, 26), Pair(-30, 41), Pair(100, 13), Pair(89, 30), Pair(19, 9), Pair(45, 43), Pair(110, -54), Pair(-74, 92),
        Pair(59, 59), Pair(31, 44), Pair(-37, 56), Pair(57, 29), Pair(13, 53), Pair(78, 28), Pair(57, -63), Pair(60, 32),
        Pair(-29, 0), Pair(-82, 26), Pair(133, -9), Pair(42, -26), Pair(131, -39), Pair(70, 24), Pair(0, 0), Pair(-66, 38),
        Pair(-55, 11), Pair(-96, 57), Pair(94, -13), Pair(-133, 45), Pair(-84, 88), Pair(-41, 67), Pair(-81, 1), Pair(-77, -15),
        Pair(-63, 6), Pair(-120, 56), Pair(89, -4), Pair(-13, 1), Pair(-34, 56), Pair(66, -37), Pair(-3, 15), Pair(-36, 56),
        Pair(50, -5), Pair(-56, 90), Pair(62, -39), Pair(-105, 39), Pair(-5, 61), Pair(-36, 19), Pair(11, -20), Pair(-67, 33),
        Pair(38, 0), Pair(-45, 6), Pair(37, -18), Pair(-40, 4), Pair(29, 23), Pair(74, 33), Pair(-16, 6), Pair(37, -15),
        Pair(-25, -32), Pair(-8, -53), Pair(-7, -24), Pair(-78, 31), Pair(7, -5), Pair(-53, -7), Pair(-18, -26), Pair(-29, 27)
      },
      { // Piece 4
        Pair(-46, -73), Pair(76, 138), Pair(23, 43), Pair(42, -16), Pair(-15, -10), Pair(84, 5), Pair(-5, -53), Pair(-18, 60),
        Pair(-177, 104), Pair(-38, 32), Pair(103, 23), Pair(-14, -1), Pair(97, 72), Pair(-35, 169), Pair(108, -264), Pair(-17, -55),
        Pair(-80, 37), Pair(-8, -82), Pair(43, -25), Pair(-27, 103), Pair(59, 48), Pair(209, -52), Pair(0, 0), Pair(170, -176),
        Pair(-96, 3), Pair(12, -31), Pair(52, 29), Pair(7, 65), Pair(71, 0), Pair(2, 45), Pair(27, 11), Pair(57, 24),
        Pair(-51, -128), Pair(-8, 3), Pair(38, -46), Pair(-3, 16), Pair(14, 54), Pair(50, -109), Pair(25, 19), Pair(70, -104),
        Pair(-53, -81), Pair(52, -135), Pair(-42, -21), Pair(-16, 0), Pair(-64, -6), Pair(68, -35), Pair(33, -57), Pair(18, -52),
        Pair(0, -23), Pair(-16, -39), Pair(-12, -58), Pair(-15, 53), Pair(17, -146), Pair(-3, -97), Pair(52, -77), Pair(-23, 92),
        Pair(-81, -71), Pair(-104, 23), Pair(-100, 76), Pair(-17, -86), Pair(10, -129), Pair(-66, 28), Pair(-64, -65), Pair(-81, -145)
      },
      { // Piece 5
        Pair(9, 68), Pair(30, 36), Pair(-6, 66), Pair(-62, 12), Pair(70, -45), Pair(34, 101), Pair(-8, 67), Pair(-64, 113),
        Pair(-69, 54), Pair(78, 33), Pair(-44, 0), Pair(14, 47), Pair(-32, 59), Pair(29, 9), Pair(-21, 60), Pair(87, 30),
        Pair(-103, 9), Pair(18, 13), Pair(124, 38), Pair(32, 51), Pair(209, -21), Pair(155, 23), Pair(0, 0), Pair(178, 47),
        Pair(51, 21), Pair(-60, 16), Pair(-43, 54), Pair(87, -1), Pair(-63, 30), Pair(142, -14), Pair(157, -20), Pair(199, -26),
        Pair(-133, 12), Pair(-56, -22), Pair(65, -3), Pair(-24, -4), Pair(21, 1), Pair(62, 24), Pair(141, -22), Pair(40, -4),
        Pair(-98, 20), Pair(-35, -3), Pair(-72, -5), Pair(39, -5), Pair(24, -7), Pair(0, 15), Pair(108, -20), Pair(7, -11),
        Pair(57, 3), Pair(-51, 7), Pair(-72, -11), Pair(-100, -21), Pair(11, -4), Pair(-21, 4), Pair(11, -3), Pair(57, -30),
        Pair(38, -31), Pair(-10, -25), Pair(-17, -43), Pair(-140, 21), Pair(-35, -16), Pair(-26, 17), Pair(5, -8), Pair(3, 20)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(34, 11), Pair(60, 11), Pair(-40, 7), Pair(-90, 37), Pair(-54, 65), Pair(26, 11), Pair(1, -20), Pair(38, -2),
        Pair(-7, 16), Pair(-3, 21), Pair(-25, 7), Pair(-23, 31), Pair(-25, 25), Pair(-32, 15), Pair(-40, -11), Pair(8, 2),
        Pair(-12, 15), Pair(8, 20), Pair(-13, 9), Pair(-9, 29), Pair(-16, 9), Pair(1, -28), Pair(15, 16), Pair(54, -77),
        Pair(-8, 9), Pair(-15, 20), Pair(-20, 15), Pair(-10, 16), Pair(-9, 12), Pair(7, -10), Pair(2, 36), Pair(40, -29),
        Pair(-12, 21), Pair(0, 9), Pair(-5, 11), Pair(-4, 24), Pair(2, 3), Pair(-2, 1), Pair(11, 27), Pair(5, -5),
        Pair(-11, 17), Pair(5, 21), Pair(-10, 14), Pair(-16, 18), Pair(-6, 11), Pair(-13, 16), Pair(6, 18), Pair(11, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(27, -56), Pair(-9, 14), Pair(54, 26), Pair(-62, 60), Pair(1, -13), Pair(178, 69), Pair(-41, 27), Pair(122, 140),
        Pair(-135, -28), Pair(-88, -6), Pair(46, 28), Pair(-2, 31), Pair(4, 64), Pair(0, 89), Pair(31, 15), Pair(59, -79),
        Pair(79, 61), Pair(26, -3), Pair(18, 16), Pair(76, -10), Pair(-61, 58), Pair(84, 41), Pair(88, 72), Pair(0, 0),
        Pair(-108, -14), Pair(2, -24), Pair(19, -38), Pair(50, 64), Pair(41, 27), Pair(79, -41), Pair(23, 112), Pair(-17, 86),
        Pair(-6, 1), Pair(75, -18), Pair(89, -20), Pair(-33, 16), Pair(51, 36), Pair(63, -2), Pair(74, 16), Pair(64, 10),
        Pair(23, -136), Pair(35, -69), Pair(19, -6), Pair(30, 23), Pair(56, -10), Pair(31, 18), Pair(67, -30), Pair(27, -48),
        Pair(151, 5), Pair(90, -13), Pair(45, -52), Pair(36, -63), Pair(-6, -2), Pair(23, 5), Pair(-11, -4), Pair(36, -56),
        Pair(-107, -157), Pair(17, -67), Pair(34, 3), Pair(40, -30), Pair(-35, 1), Pair(144, -104), Pair(14, -19), Pair(-30, -4)
      },
      { // Piece 2
        Pair(168, -75), Pair(66, -33), Pair(108, -58), Pair(119, -34), Pair(111, -58), Pair(42, -32), Pair(-26, 42), Pair(-232, 90),
        Pair(-30, -51), Pair(-23, 1), Pair(9, -34), Pair(137, -67), Pair(259, -33), Pair(151, -42), Pair(22, 60), Pair(-36, 12),
        Pair(99, -8), Pair(27, -57), Pair(135, -88), Pair(-4, -8), Pair(122, -39), Pair(47, -28), Pair(74, 20), Pair(0, 0),
        Pair(114, -32), Pair(50, 3), Pair(105, -10), Pair(80, -25), Pair(27, 19), Pair(41, 16), Pair(86, 3), Pair(93, -35),
        Pair(121, -51), Pair(88, -38), Pair(14, -3), Pair(97, -25), Pair(51, 15), Pair(33, 5), Pair(39, 13), Pair(122, -34),
        Pair(-11, -18), Pair(24, 10), Pair(19, -48), Pair(53, -7), Pair(57, -20), Pair(24, -31), Pair(39, -22), Pair(-3, 21),
        Pair(22, -22), Pair(14, -39), Pair(99, -56), Pair(0, -3), Pair(31, -24), Pair(-5, -84), Pair(46, -10), Pair(-117, 94),
        Pair(-14, -11), Pair(122, -113), Pair(13, -37), Pair(51, -38), Pair(17, -45), Pair(5, -15), Pair(-10, 4), Pair(118, -127)
      },
      { // Piece 3
        Pair(69, 9), Pair(191, -25), Pair(146, 28), Pair(203, -13), Pair(-10, 6), Pair(169, 26), Pair(-1, 52), Pair(108, -61),
        Pair(9, 73), Pair(-21, 56), Pair(12, 63), Pair(-13, 68), Pair(28, 69), Pair(163, 55), Pair(24, 80), Pair(164, -87),
        Pair(-111, 65), Pair(-60, 34), Pair(184, -54), Pair(178, -42), Pair(27, -3), Pair(48, -4), Pair(139, -32), Pair(0, 0),
        Pair(12, 36), Pair(41, 38), Pair(14, 30), Pair(121, -9), Pair(-89, 51), Pair(-34, 53), Pair(1, 29), Pair(-14, -56),
        Pair(-58, 38), Pair(112, -6), Pair(-3, 10), Pair(-32, 15), Pair(63, -26), Pair(4, 43), Pair(-94, 75), Pair(-40, -9),
        Pair(-8, 12), Pair(-18, -12), Pair(51, 7), Pair(-55, 53), Pair(-13, 22), Pair(-31, 50), Pair(-68, 24), Pair(-48, -36),
        Pair(14, -7), Pair(29, 11), Pair(-21, 21), Pair(12, -1), Pair(-108, 31), Pair(-2, -8), Pair(-43, 51), Pair(-52, -33),
        Pair(13, -27), Pair(-12, 23), Pair(-21, 24), Pair(16, 1), Pair(-9, 25), Pair(18, -8), Pair(-30, 16), Pair(-38, -26)
      },
      { // Piece 4
        Pair(-67, 166), Pair(-154, 114), Pair(98, 30), Pair(144, 12), Pair(222, -31), Pair(49, 43), Pair(195, 121), Pair(-84, 59),
        Pair(-24, 63), Pair(-35, 74), Pair(86, -54), Pair(-85, 131), Pair(176, -2), Pair(139, -165), Pair(155, 116), Pair(40, 35),
        Pair(-6, 185), Pair(-34, 110), Pair(87, -56), Pair(62, 80), Pair(59, 44), Pair(71, 95), Pair(166, -45), Pair(0, 0),
        Pair(17, 102), Pair(-52, 5), Pair(43, -26), Pair(61, 71), Pair(66, 3), Pair(-31, 50), Pair(121, -21), Pair(85, -163),
        Pair(50, 19), Pair(-31, 107), Pair(5, -1), Pair(17, 57), Pair(16, -59), Pair(82, -34), Pair(-4, 83), Pair(38, -111),
        Pair(29, -75), Pair(28, -62), Pair(77, 11), Pair(20, 9), Pair(22, 44), Pair(64, 9), Pair(11, 173), Pair(8, -23),
        Pair(25, -61), Pair(-92, 186), Pair(19, -10), Pair(12, 58), Pair(24, 22), Pair(83, -200), Pair(-11, 129), Pair(20, -158),
        Pair(16, 17), Pair(-3, -82), Pair(34, 3), Pair(19, -52), Pair(3, 128), Pair(-2, -57), Pair(-96, -1), Pair(-19, -123)
      },
      { // Piece 5
        Pair(-30, -6), Pair(-130, 2), Pair(35, -40), Pair(14, -32), Pair(31, -56), Pair(102, -51), Pair(-88, 82), Pair(136, -78),
        Pair(10, 93), Pair(13, -34), Pair(105, -45), Pair(-1, -28), Pair(122, -63), Pair(-79, 25), Pair(-95, 53), Pair(85, -70),
        Pair(-5, 82), Pair(-10, 33), Pair(74, -13), Pair(13, -17), Pair(151, -22), Pair(169, -39), Pair(457, -76), Pair(0, 0),
        Pair(-45, 30), Pair(-226, 37), Pair(59, -2), Pair(20, 4), Pair(-61, -6), Pair(165, -10), Pair(248, -26), Pair(82, -8),
        Pair(-26, 6), Pair(-90, 24), Pair(-2, -4), Pair(-33, -1), Pair(-38, 14), Pair(86, -19), Pair(91, 8), Pair(53, -10),
        Pair(-4, -25), Pair(-90, 36), Pair(39, 10), Pair(19, -2), Pair(-26, 21), Pair(-1, 11), Pair(100, -11), Pair(-103, 24),
        Pair(-9, 29), Pair(-32, 0), Pair(11, 0), Pair(-37, 13), Pair(-23, -3), Pair(0, 9), Pair(-10, 13), Pair(29, -5),
        Pair(-4, 35), Pair(-28, 37), Pair(-40, 6), Pair(-53, -16), Pair(-2, -36), Pair(-13, 27), Pair(5, 10), Pair(-37, 24)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, -12), Pair(92, 27), Pair(-45, 25), Pair(-16, 50), Pair(63, 12), Pair(16, 64), Pair(-9, 4), Pair(12, 4),
        Pair(65, -80), Pair(29, 44), Pair(-40, 26), Pair(40, 18), Pair(-20, 42), Pair(-9, 19), Pair(-8, 26), Pair(-11, 15),
        Pair(4, 13), Pair(-23, 4), Pair(-6, -5), Pair(5, 7), Pair(-9, 15), Pair(-4, 21), Pair(-9, 8), Pair(-4, 9),
        Pair(17, -14), Pair(-7, 20), Pair(4, 2), Pair(6, 7), Pair(-4, 19), Pair(2, 10), Pair(-3, 11), Pair(-6, 13),
        Pair(7, 8), Pair(-12, 20), Pair(0, 10), Pair(-1, 12), Pair(1, 12), Pair(-7, 14), Pair(0, 13), Pair(-1, 22),
        Pair(-6, 5), Pair(-12, 30), Pair(-2, 14), Pair(-11, 13), Pair(-2, 8), Pair(-4, 17), Pair(-6, 18), Pair(-4, 24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-317, 163), Pair(-95, 114), Pair(162, 84), Pair(3, 33), Pair(-46, 25), Pair(-43, 82), Pair(146, -25), Pair(69, -99),
        Pair(-56, 45), Pair(-70, 61), Pair(20, 67), Pair(18, 23), Pair(19, 47), Pair(-18, 16), Pair(100, 44), Pair(33, 77),
        Pair(-108, 65), Pair(-8, 78), Pair(63, 40), Pair(63, 47), Pair(-32, 89), Pair(52, 34), Pair(37, 16), Pair(37, 47),
        Pair(0, 0), Pair(-8, 57), Pair(-2, 81), Pair(45, 65), Pair(10, 51), Pair(12, 39), Pair(11, 36), Pair(-5, 35),
        Pair(15, 97), Pair(38, 102), Pair(27, 55), Pair(25, 46), Pair(26, 47), Pair(25, 49), Pair(16, 22), Pair(9, 47),
        Pair(7, 85), Pair(13, 36), Pair(18, 56), Pair(-6, 80), Pair(27, 11), Pair(14, 33), Pair(20, 30), Pair(11, 36),
        Pair(34, 29), Pair(-57, 27), Pair(29, 51), Pair(5, 38), Pair(11, 63), Pair(1, 28), Pair(-8, 9), Pair(30, 36),
        Pair(71, 61), Pair(-6, 11), Pair(8, 32), Pair(16, -16), Pair(22, 20), Pair(1, 59), Pair(0, 43), Pair(-126, 9)
      },
      { // Piece 2
        Pair(-27, 76), Pair(110, 0), Pair(249, -7), Pair(22, 40), Pair(64, -11), Pair(177, 2), Pair(120, 10), Pair(-134, 20),
        Pair(96, 7), Pair(61, 94), Pair(46, 39), Pair(1, 22), Pair(70, 3), Pair(51, 44), Pair(53, 21), Pair(-19, 39),
        Pair(20, 23), Pair(77, 171), Pair(-5, 95), Pair(62, 47), Pair(34, 27), Pair(51, -15), Pair(25, 25), Pair(-27, 78),
        Pair(0, 0), Pair(43, 72), Pair(-21, 48), Pair(25, 88), Pair(14, 27), Pair(-14, 47), Pair(36, 24), Pair(-12, 10),
        Pair(24, 50), Pair(41, 20), Pair(27, 66), Pair(25, 39), Pair(13, 61), Pair(30, 19), Pair(75, -3), Pair(37, 5),
        Pair(41, 11), Pair(22, 13), Pair(14, 22), Pair(17, 44), Pair(30, 44), Pair(23, 52), Pair(-4, 50), Pair(50, 23),
        Pair(-104, 21), Pair(8, 38), Pair(5, 26), Pair(23, 34), Pair(21, 62), Pair(44, 47), Pair(22, 53), Pair(29, -4),
        Pair(32, 37), Pair(-20, 20), Pair(9, -15), Pair(-10, 48), Pair(17, 16), Pair(13, 30), Pair(92, 23), Pair(-41, 112)
      },
      { // Piece 3
        Pair(-106, 77), Pair(-73, 128), Pair(30, 99), Pair(-31, 103), Pair(105, 67), Pair(-146, 135), Pair(-19, 94), Pair(64, 60),
        Pair(111, -3), Pair(19, 103), Pair(21, 106), Pair(13, 79), Pair(23, 87), Pair(22, 93), Pair(-12, 106), Pair(7, 115),
        Pair(-19, 41), Pair(40, 108), Pair(33, 112), Pair(-24, 125), Pair(18, 92), Pair(10, 100), Pair(-12, 104), Pair(-81, 142),
        Pair(0, 0), Pair(52, 91), Pair(39, 96), Pair(22, 92), Pair(-25, 119), Pair(-8, 82), Pair(-27, 123), Pair(19, 89),
        Pair(-19, 51), Pair(2, 128), Pair(32, 120), Pair(-31, 121), Pair(-3, 91), Pair(18, 72), Pair(-10, 86), Pair(9, 71),
        Pair(-1, 66), Pair(-14, 147), Pair(1, 104), Pair(43, 93), Pair(-2, 130), Pair(32, 63), Pair(-7, 81), Pair(37, 59),
        Pair(-15, 79), Pair(55, 89), Pair(-17, 102), Pair(-36, 118), Pair(-2, 101), Pair(26, 85), Pair(10, 83), Pair(-15, 129),
        Pair(-20, 51), Pair(8, 111), Pair(21, 75), Pair(1, 103), Pair(-1, 95), Pair(15, 69), Pair(-18, 98), Pair(2, 82)
      },
      { // Piece 4
        Pair(73, 124), Pair(80, 197), Pair(-20, 247), Pair(131, 140), Pair(44, 144), Pair(8, 162), Pair(38, 214), Pair(-23, 147),
        Pair(42, 170), Pair(41, 178), Pair(43, 154), Pair(17, 190), Pair(92, 121), Pair(42, 218), Pair(7, 102), Pair(33, 81),
        Pair(-29, 158), Pair(29, 204), Pair(57, 238), Pair(54, 116), Pair(8, 206), Pair(55, 222), Pair(111, 83), Pair(69, 62),
        Pair(0, 0), Pair(93, 164), Pair(119, 123), Pair(33, 252), Pair(31, 166), Pair(40, 112), Pair(69, 196), Pair(4, 183),
        Pair(59, 153), Pair(56, 150), Pair(71, 177), Pair(38, 189), Pair(60, 146), Pair(34, 162), Pair(31, 118), Pair(93, 110),
        Pair(37, 186), Pair(37, 127), Pair(72, 111), Pair(23, 221), Pair(26, 229), Pair(0, 254), Pair(16, 188), Pair(29, 112),
        Pair(31, 89), Pair(52, 209), Pair(55, 106), Pair(52, 144), Pair(58, 136), Pair(61, 157), Pair(34, 116), Pair(8, 81),
        Pair(1, 121), Pair(-14, 213), Pair(52, 114), Pair(36, 157), Pair(64, 115), Pair(59, 108), Pair(-1, 153), Pair(64, -6)
      },
      { // Piece 5
        Pair(64, -59), Pair(95, 73), Pair(27, 124), Pair(175, -33), Pair(53, 5), Pair(-30, 7), Pair(51, 33), Pair(58, -9),
        Pair(-95, 60), Pair(31, 130), Pair(65, 86), Pair(114, 39), Pair(103, -1), Pair(182, 5), Pair(52, -48), Pair(88, 13),
        Pair(93, -36), Pair(90, 33), Pair(131, 103), Pair(343, 7), Pair(135, 8), Pair(189, -23), Pair(-8, 35), Pair(-10, 31),
        Pair(0, 0), Pair(227, 13), Pair(121, 16), Pair(141, 55), Pair(265, -26), Pair(34, 36), Pair(-4, 43), Pair(-32, 26),
        Pair(216, -59), Pair(160, 5), Pair(29, 62), Pair(64, 41), Pair(16, 52), Pair(-77, 49), Pair(-109, 48), Pair(-206, 72),
        Pair(21, 26), Pair(18, 49), Pair(72, 30), Pair(41, 21), Pair(40, 29), Pair(-84, 39), Pair(-55, 32), Pair(-64, 4),
        Pair(135, -31), Pair(78, 0), Pair(-4, 34), Pair(-1, 27), Pair(-36, 25), Pair(-54, 31), Pair(-38, 17), Pair(-53, 17),
        Pair(140, -37), Pair(84, -3), Pair(34, 8), Pair(-17, 23), Pair(-18, 3), Pair(-50, 28), Pair(-30, 17), Pair(-45, 7)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, 71), Pair(91, -60), Pair(8, 31), Pair(-11, -5), Pair(-68, 23), Pair(2, 23), Pair(-12, 12), Pair(-27, 9),
        Pair(18, 5), Pair(66, -97), Pair(22, 33), Pair(9, 16), Pair(-23, 46), Pair(-60, 45), Pair(12, 24), Pair(9, 21),
        Pair(-22, 3), Pair(1, 19), Pair(-7, 8), Pair(-12, 8), Pair(-1, 14), Pair(-2, 15), Pair(-3, 25), Pair(-9, 5),
        Pair(0, 26), Pair(4, -5), Pair(4, 24), Pair(0, 8), Pair(-3, 7), Pair(2, 9), Pair(1, 19), Pair(-4, 25),
        Pair(-6, 18), Pair(10, 17), Pair(-3, 27), Pair(3, 12), Pair(1, 15), Pair(-3, 5), Pair(4, 15), Pair(-3, 21),
        Pair(-4, 28), Pair(13, 28), Pair(-6, 23), Pair(-6, 16), Pair(-8, 22), Pair(2, 19), Pair(0, 23), Pair(-3, 26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-53, 86), Pair(80, 51), Pair(-15, 82), Pair(45, 50), Pair(-45, 21), Pair(-220, 150), Pair(6, 112), Pair(114, -35),
        Pair(-6, 63), Pair(97, 28), Pair(1, 32), Pair(-17, 103), Pair(-49, 110), Pair(6, 42), Pair(-128, 39), Pair(-49, 31),
        Pair(-10, 14), Pair(-44, 67), Pair(57, 12), Pair(10, 63), Pair(53, 41), Pair(59, 18), Pair(11, 51), Pair(-6, 52),
        Pair(13, 35), Pair(0, 0), Pair(17, 76), Pair(14, 55), Pair(20, 83), Pair(30, 54), Pair(7, 59), Pair(-5, 26),
        Pair(22, 72), Pair(61, 39), Pair(18, 82), Pair(21, 48), Pair(22, 49), Pair(11, 40), Pair(29, 45), Pair(-5, 68),
        Pair(-10, 18), Pair(-6, 72), Pair(0, 54), Pair(-1, 91), Pair(0, 79), Pair(9, 67), Pair(9, 9), Pair(6, -28),
        Pair(50, 4), Pair(22, 28), Pair(33, 58), Pair(3, 48), Pair(0, 69), Pair(29, 23), Pair(-6, 70), Pair(17, 43),
        Pair(137, -5), Pair(-7, -6), Pair(-20, 43), Pair(-2, 53), Pair(-40, 55), Pair(31, 1), Pair(-3, -12), Pair(34, -20)
      },
      { // Piece 2
        Pair(97, 56), Pair(3, 14), Pair(156, -17), Pair(143, 2), Pair(41, 21), Pair(86, -12), Pair(96, 29), Pair(-53, 20),
        Pair(57, 59), Pair(24, 39), Pair(104, 48), Pair(22, 48), Pair(3, 26), Pair(-2, 20), Pair(5, 29), Pair(60, 21),
        Pair(-16, 26), Pair(106, 12), Pair(-15, 67), Pair(2, 51), Pair(35, -1), Pair(34, 46), Pair(34, 23), Pair(-4, 27),
        Pair(-15, 66), Pair(0, 0), Pair(48, 40), Pair(33, 49), Pair(27, 40), Pair(13, 28), Pair(20, 47), Pair(24, 28),
        Pair(-85, -4), Pair(39, 42), Pair(25, 21), Pair(33, 18), Pair(15, 38), Pair(17, 48), Pair(31, 48), Pair(25, 32),
        Pair(9, 53), Pair(-5, 41), Pair(2, 73), Pair(10, 45), Pair(13, 58), Pair(13, 39), Pair(5, 16), Pair(4, 28),
        Pair(62, -32), Pair(21, 16), Pair(8, 41), Pair(22, 38), Pair(10, 25), Pair(6, 69), Pair(19, 37), Pair(2, 21),
        Pair(24, 20), Pair(-16, 29), Pair(8, 27), Pair(-20, 31), Pair(-42, 45), Pair(2, 19), Pair(-33, 37), Pair(-5, 6)
      },
      { // Piece 3
        Pair(-73, 139), Pair(74, 25), Pair(9, 122), Pair(23, 103), Pair(-5, 89), Pair(-72, 138), Pair(0, 109), Pair(68, 67),
        Pair(-5, 108), Pair(-55, 50), Pair(43, 93), Pair(-59, 113), Pair(27, 80), Pair(-36, 116), Pair(-2, 94), Pair(13, 99),
        Pair(2, 94), Pair(-53, 49), Pair(27, 141), Pair(57, 102), Pair(-40, 110), Pair(5, 98), Pair(131, 67), Pair(-43, 126),
        Pair(-88, 97), Pair(0, 0), Pair(40, 92), Pair(-13, 98), Pair(-23, 112), Pair(9, 64), Pair(-71, 138), Pair(-27, 84),
        Pair(4, 92), Pair(-38, 70), Pair(47, 72), Pair(21, 82), Pair(19, 69), Pair(6, 68), Pair(-4, 91), Pair(-23, 79),
        Pair(23, 67), Pair(4, 51), Pair(-43, 124), Pair(10, 80), Pair(8, 85), Pair(-13, 98), Pair(-23, 94), Pair(6, 77),
        Pair(5, 81), Pair(-8, 63), Pair(-2, 117), Pair(4, 92), Pair(-49, 130), Pair(-3, 88), Pair(15, 42), Pair(-34, 86),
        Pair(1, 85), Pair(5, 35), Pair(2, 94), Pair(-8, 90), Pair(-8, 85), Pair(-3, 72), Pair(-15, 98), Pair(-8, 76)
      },
      { // Piece 4
        Pair(68, 26), Pair(-36, 100), Pair(66, 100), Pair(-77, 153), Pair(60, 71), Pair(124, -13), Pair(73, 78), Pair(89, 16),
        Pair(-9, 236), Pair(22, 92), Pair(24, 77), Pair(-101, 188), Pair(10, 187), Pair(-56, 143), Pair(75, 10), Pair(24, 88),
        Pair(7, 96), Pair(13, 67), Pair(47, 104), Pair(25, 114), Pair(42, 121), Pair(58, 179), Pair(9, 95), Pair(71, 6),
        Pair(17, 99), Pair(0, 0), Pair(37, 106), Pair(55, 106), Pair(4, 99), Pair(4, 159), Pair(-4, 160), Pair(0, 126),
        Pair(4, 51), Pair(6, 137), Pair(27, 144), Pair(40, 112), Pair(38, 111), Pair(26, 104), Pair(11, 90), Pair(48, 10),
        Pair(2, 123), Pair(29, 26), Pair(26, 122), Pair(39, 151), Pair(49, 95), Pair(27, 74), Pair(23, 55), Pair(51, 66),
        Pair(46, 60), Pair(13, 111), Pair(18, 143), Pair(12, 147), Pair(15, 119), Pair(40, -11), Pair(38, 24), Pair(8, 102),
        Pair(47, 59), Pair(16, 50), Pair(57, 16), Pair(13, 91), Pair(39, 24), Pair(34, 45), Pair(46, 121), Pair(33, 169)
      },
      { // Piece 5
        Pair(34, 165), Pair(126, 62), Pair(51, 17), Pair(57, 21), Pair(63, 80), Pair(73, -12), Pair(54, -1), Pair(29, 12),
        Pair(-125, 123), Pair(1, 77), Pair(-13, 95), Pair(-25, 28), Pair(185, -6), Pair(123, -33), Pair(46, 23), Pair(136, -57),
        Pair(-98, 62), Pair(46, 29), Pair(306, -4), Pair(-24, 67), Pair(197, -12), Pair(100, 8), Pair(73, 5), Pair(-160, 63),
        Pair(302, 32), Pair(0, 0), Pair(209, 40), Pair(78, 39), Pair(165, 21), Pair(-53, 53), Pair(-23, 51), Pair(-24, -13),
        Pair(112, 7), Pair(204, 5), Pair(4, 28), Pair(-113, 65), Pair(-141, 61), Pair(32, 33), Pair(30, 21), Pair(-152, 39),
        Pair(66, 30), Pair(68, 29), Pair(53, 17), Pair(46, 5), Pair(-44, 29), Pair(-65, 31), Pair(-87, 37), Pair(-48, 15),
        Pair(155, -14), Pair(52, 21), Pair(73, 19), Pair(14, 21), Pair(-19, 9), Pair(-17, 9), Pair(-18, 16), Pair(-43, 16),
        Pair(10, 24), Pair(81, -32), Pair(27, -4), Pair(-10, 22), Pair(-8, 5), Pair(-15, 7), Pair(-13, 3), Pair(-13, 2)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-63, 39), Pair(-34, 65), Pair(-39, 0), Pair(9, 81), Pair(22, -4), Pair(5, 44), Pair(34, 8), Pair(23, 34),
        Pair(-2, 2), Pair(7, 24), Pair(36, -40), Pair(44, 28), Pair(21, -12), Pair(-13, 22), Pair(37, 8), Pair(-13, 8),
        Pair(-7, -5), Pair(-7, 8), Pair(-3, 3), Pair(6, 14), Pair(-3, -8), Pair(-2, 19), Pair(7, 9), Pair(12, 11),
        Pair(-5, 7), Pair(12, 15), Pair(-15, -5), Pair(13, 35), Pair(-4, 9), Pair(9, 20), Pair(3, 14), Pair(1, 20),
        Pair(-5, 13), Pair(0, 4), Pair(6, -1), Pair(-4, 20), Pair(3, 6), Pair(0, 9), Pair(10, 3), Pair(7, 12),
        Pair(-6, 11), Pair(-1, 22), Pair(-8, 3), Pair(1, 20), Pair(0, 9), Pair(-1, 20), Pair(3, 20), Pair(5, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-70, 92), Pair(35, 154), Pair(46, 71), Pair(1, 72), Pair(11, 92), Pair(147, 11), Pair(-36, 65), Pair(-37, 26),
        Pair(25, 101), Pair(24, 37), Pair(18, 67), Pair(-26, 35), Pair(17, 98), Pair(92, 58), Pair(-1, 41), Pair(15, 41),
        Pair(-68, 103), Pair(11, 68), Pair(-18, 46), Pair(10, 41), Pair(19, 69), Pair(58, 47), Pair(-52, 101), Pair(92, -21),
        Pair(18, 74), Pair(12, 79), Pair(0, 0), Pair(55, 89), Pair(29, 41), Pair(80, 53), Pair(27, 37), Pair(-27, 77),
        Pair(19, -6), Pair(18, 86), Pair(37, 94), Pair(45, 118), Pair(38, 70), Pair(43, 60), Pair(5, 55), Pair(8, 96),
        Pair(-8, 53), Pair(3, 63), Pair(20, 53), Pair(32, 52), Pair(62, 54), Pair(19, 63), Pair(24, 63), Pair(9, 24),
        Pair(44, -33), Pair(16, 74), Pair(22, 79), Pair(13, 90), Pair(8, 84), Pair(29, 60), Pair(42, 20), Pair(11, 44),
        Pair(-117, 72), Pair(-14, 26), Pair(-19, 50), Pair(36, 16), Pair(24, 37), Pair(24, 121), Pair(6, 20), Pair(75, 1)
      },
      { // Piece 2
        Pair(152, 15), Pair(151, 20), Pair(-7, 66), Pair(17, 50), Pair(159, 17), Pair(27, 8), Pair(126, 57), Pair(-25, -41),
        Pair(95, 72), Pair(72, 75), Pair(37, 24), Pair(58, 50), Pair(106, 4), Pair(96, 41), Pair(30, -21), Pair(-50, 103),
        Pair(-31, 59), Pair(-76, 164), Pair(104, 6), Pair(118, 137), Pair(-2, 72), Pair(54, -11), Pair(24, 25), Pair(20, 9),
        Pair(-61, 45), Pair(29, 66), Pair(0, 0), Pair(130, 45), Pair(63, 21), Pair(61, 53), Pair(26, 17), Pair(-21, 46),
        Pair(31, 25), Pair(-42, 32), Pair(37, 85), Pair(36, 4), Pair(21, 94), Pair(25, 23), Pair(-30, 71), Pair(25, 4),
        Pair(-28, 30), Pair(29, 39), Pair(32, 20), Pair(21, 87), Pair(2, 38), Pair(38, 53), Pair(63, 6), Pair(7, 72),
        Pair(89, 46), Pair(5, 36), Pair(23, 49), Pair(-5, 30), Pair(25, 51), Pair(36, 6), Pair(20, 74), Pair(39, 38),
        Pair(24, -18), Pair(36, -7), Pair(-3, 16), Pair(-1, 63), Pair(14, 29), Pair(6, 86), Pair(59, 20), Pair(52, 58)
      },
      { // Piece 3
        Pair(31, 112), Pair(25, 129), Pair(129, 15), Pair(40, 118), Pair(-41, 96), Pair(50, 45), Pair(143, 82), Pair(56, 76),
        Pair(69, 79), Pair(1, 114), Pair(-43, 91), Pair(-9, 108), Pair(-39, 108), Pair(28, 93), Pair(26, 98), Pair(83, 86),
        Pair(-9, 106), Pair(34, 112), Pair(-81, 55), Pair(-28, 130), Pair(-41, 104), Pair(-24, 112), Pair(40, 101), Pair(35, 95),
        Pair(30, 67), Pair(-31, 116), Pair(0, 0), Pair(-20, 116), Pair(-43, 128), Pair(-8, 98), Pair(-15, 114), Pair(31, 84),
        Pair(-4, 83), Pair(-9, 85), Pair(-25, 75), Pair(-3, 132), Pair(-24, 109), Pair(11, 102), Pair(-16, 74), Pair(9, 73),
        Pair(6, 96), Pair(-81, 126), Pair(-3, 53), Pair(-14, 102), Pair(-49, 119), Pair(-56, 100), Pair(-63, 115), Pair(-39, 117),
        Pair(-23, 82), Pair(-29, 95), Pair(-1, 62), Pair(-47, 116), Pair(34, 90), Pair(-1, 89), Pair(-5, 118), Pair(35, 33),
        Pair(-23, 88), Pair(-15, 102), Pair(-2, 62), Pair(-11, 100), Pair(-19, 119), Pair(-21, 109), Pair(2, 86), Pair(2, 51)
      },
      { // Piece 4
        Pair(38, 130), Pair(-26, 178), Pair(-55, 130), Pair(-76, 191), Pair(-115, 185), Pair(21, 77), Pair(-15, -40), Pair(-36, 163),
        Pair(43, -4), Pair(10, 129), Pair(22, 81), Pair(-65, 221), Pair(8, 128), Pair(-2, 130), Pair(7, 177), Pair(-45, 89),
        Pair(2, 101), Pair(-46, 89), Pair(30, -1), Pair(7, 103), Pair(-2, 214), Pair(27, 114), Pair(19, 78), Pair(-60, 170),
        Pair(16, 95), Pair(22, 54), Pair(0, 0), Pair(1, 188), Pair(-53, 161), Pair(62, -9), Pair(7, 62), Pair(30, 24),
        Pair(1, 13), Pair(-21, 96), Pair(36, 17), Pair(29, 94), Pair(-3, 142), Pair(3, 127), Pair(-5, -19), Pair(23, 27),
        Pair(-42, 226), Pair(7, 88), Pair(-4, 103), Pair(0, 103), Pair(25, 65), Pair(-10, 75), Pair(1, 82), Pair(12, 50),
        Pair(30, 40), Pair(-5, 97), Pair(6, 42), Pair(13, 70), Pair(-5, 99), Pair(45, 31), Pair(-30, 185), Pair(-28, 185),
        Pair(-57, 136), Pair(-15, 161), Pair(-2, 49), Pair(-1, 32), Pair(11, -27), Pair(3, 32), Pair(85, -3), Pair(-52, 92)
      },
      { // Piece 5
        Pair(0, -58), Pair(52, -63), Pair(87, -9), Pair(-33, 7), Pair(22, 15), Pair(195, -37), Pair(27, -27), Pair(-54, 79),
        Pair(80, -57), Pair(217, 79), Pair(123, 77), Pair(72, 35), Pair(15, 91), Pair(-68, -10), Pair(-79, 40), Pair(-37, 46),
        Pair(216, 36), Pair(263, 6), Pair(185, -20), Pair(102, 29), Pair(-27, 55), Pair(-9, 41), Pair(30, 59), Pair(25, -35),
        Pair(172, -4), Pair(170, 11), Pair(0, 0), Pair(244, 22), Pair(90, 36), Pair(-37, 44), Pair(-251, 60), Pair(-56, -46),
        Pair(92, 44), Pair(79, 25), Pair(61, 34), Pair(34, 39), Pair(35, 46), Pair(-77, 35), Pair(-57, 19), Pair(-120, 25),
        Pair(113, 14), Pair(55, 35), Pair(-39, 35), Pair(33, 31), Pair(20, 13), Pair(-35, 1), Pair(-72, 19), Pair(-56, 26),
        Pair(52, -23), Pair(55, 0), Pair(68, -9), Pair(-10, 16), Pair(-34, 14), Pair(1, -10), Pair(-6, -16), Pair(0, -18),
        Pair(47, -66), Pair(12, -6), Pair(6, -32), Pair(-41, -20), Pair(-10, -12), Pair(-23, -32), Pair(-6, -26), Pair(-17, -17)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(11, -3), Pair(-6, 23), Pair(13, 55), Pair(5, 2), Pair(14, 43), Pair(-1, 5), Pair(-22, 21), Pair(31, 11),
        Pair(-5, 11), Pair(-29, 21), Pair(13, 40), Pair(4, -41), Pair(12, 39), Pair(-4, 3), Pair(18, -1), Pair(-8, 30),
        Pair(3, 6), Pair(-11, 8), Pair(7, 14), Pair(5, -4), Pair(0, 17), Pair(-5, -1), Pair(2, 15), Pair(-5, 15),
        Pair(2, 11), Pair(-2, 4), Pair(8, 28), Pair(-5, -7), Pair(6, 41), Pair(6, 6), Pair(-1, 9), Pair(-3, 18),
        Pair(0, 11), Pair(2, 15), Pair(-1, 27), Pair(4, -15), Pair(0, 33), Pair(7, 16), Pair(3, 8), Pair(-1, 12),
        Pair(1, 9), Pair(-3, 13), Pair(1, 35), Pair(-6, 18), Pair(-2, 34), Pair(-3, 13), Pair(0, 13), Pair(-1, 24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(125, -68), Pair(12, 107), Pair(56, 99), Pair(47, 12), Pair(32, 85), Pair(-22, 68), Pair(-72, -12), Pair(-120, 8),
        Pair(35, 61), Pair(44, 99), Pair(16, 99), Pair(27, 75), Pair(24, 51), Pair(53, 114), Pair(29, 51), Pair(-43, 94),
        Pair(-159, 193), Pair(-20, 66), Pair(5, 34), Pair(-65, 122), Pair(27, 36), Pair(29, 69), Pair(64, 42), Pair(8, 56),
        Pair(10, 91), Pair(-10, 94), Pair(17, 90), Pair(0, 0), Pair(-3, 120), Pair(21, 82), Pair(11, 118), Pair(-31, 98),
        Pair(-13, 74), Pair(15, 57), Pair(22, 112), Pair(27, 99), Pair(12, 125), Pair(6, 63), Pair(1, 61), Pair(2, 56),
        Pair(0, 49), Pair(-10, 66), Pair(1, 47), Pair(15, 90), Pair(2, 90), Pair(5, 73), Pair(15, 42), Pair(3, 24),
        Pair(43, 122), Pair(35, 112), Pair(-19, 89), Pair(7, 77), Pair(2, 36), Pair(2, 45), Pair(19, 27), Pair(-8, 28),
        Pair(-107, 27), Pair(-9, 35), Pair(-10, 82), Pair(-15, 65), Pair(18, 24), Pair(-6, 34), Pair(-7, 75), Pair(-41, 87)
      },
      { // Piece 2
        Pair(41, 8), Pair(144, -1), Pair(69, -15), Pair(-31, 62), Pair(-84, -4), Pair(166, 8), Pair(-35, 22), Pair(67, 65),
        Pair(3, 86), Pair(15, 29), Pair(72, 66), Pair(81, -10), Pair(82, 23), Pair(-1, -25), Pair(65, 6), Pair(-90, -38),
        Pair(-18, 34), Pair(11, 82), Pair(-27, 50), Pair(68, 22), Pair(38, -21), Pair(25, 43), Pair(13, -31), Pair(47, 26),
        Pair(-35, 100), Pair(-6, 21), Pair(4, 73), Pair(0, 0), Pair(27, 78), Pair(41, -20), Pair(8, 55), Pair(-6, -17),
        Pair(8, 10), Pair(7, 69), Pair(-9, 11), Pair(-4, 79), Pair(-5, 16), Pair(12, 93), Pair(28, -43), Pair(27, 14),
        Pair(-7, 66), Pair(6, -9), Pair(9, 35), Pair(-9, 14), Pair(9, 84), Pair(6, -8), Pair(11, 107), Pair(3, -14),
        Pair(10, 14), Pair(0, 31), Pair(-7, 13), Pair(10, 54), Pair(-1, 6), Pair(4, 53), Pair(-12, 5), Pair(46, 55),
        Pair(24, 31), Pair(-38, 1), Pair(0, 51), Pair(-7, -6), Pair(41, 11), Pair(-13, -1), Pair(-37, 86), Pair(5, -25)
      },
      { // Piece 3
        Pair(14, 104), Pair(5, 118), Pair(81, 73), Pair(156, 0), Pair(-67, 115), Pair(10, 110), Pair(122, 75), Pair(22, 88),
        Pair(-22, 124), Pair(-37, 124), Pair(8, 108), Pair(49, 45), Pair(-18, 105), Pair(-38, 117), Pair(-54, 104), Pair(-42, 113),
        Pair(-17, 122), Pair(-33, 129), Pair(14, 93), Pair(-46, 15), Pair(25, 131), Pair(18, 102), Pair(67, 114), Pair(-8, 99),
        Pair(-36, 97), Pair(-39, 118), Pair(6, 61), Pair(0, 0), Pair(-53, 116), Pair(28, 76), Pair(-2, 89), Pair(-12, 75),
        Pair(18, 71), Pair(3, 76), Pair(16, 74), Pair(24, 11), Pair(2, 93), Pair(37, 67), Pair(-14, 92), Pair(-42, 98),
        Pair(-17, 85), Pair(18, 57), Pair(1, 75), Pair(-19, 66), Pair(-23, 87), Pair(26, 63), Pair(-8, 115), Pair(-6, 75),
        Pair(-11, 91), Pair(-49, 99), Pair(-10, 91), Pair(-10, 21), Pair(7, 87), Pair(-22, 74), Pair(-7, 109), Pair(-31, 91),
        Pair(-13, 92), Pair(-14, 119), Pair(-21, 101), Pair(28, 40), Pair(-19, 99), Pair(-22, 97), Pair(-4, 86), Pair(0, 67)
      },
      { // Piece 4
        Pair(-16, 143), Pair(-58, 96), Pair(-26, 134), Pair(-62, 131), Pair(-43, 187), Pair(108, 17), Pair(-56, 133), Pair(9, 100),
        Pair(-14, 135), Pair(8, 105), Pair(-31, 182), Pair(-20, 133), Pair(29, 125), Pair(22, 153), Pair(33, 63), Pair(-2, 185),
        Pair(-19, 141), Pair(-82, 155), Pair(-9, 126), Pair(41, 11), Pair(-13, 147), Pair(-49, 106), Pair(1, 183), Pair(-25, 168),
        Pair(31, 57), Pair(32, 77), Pair(34, 162), Pair(0, 0), Pair(35, 130), Pair(28, 107), Pair(7, 87), Pair(3, 96),
        Pair(24, 142), Pair(33, 110), Pair(11, 124), Pair(32, 111), Pair(4, 126), Pair(35, 140), Pair(38, 101), Pair(22, 124),
        Pair(10, 100), Pair(17, 20), Pair(19, 127), Pair(24, 92), Pair(19, 118), Pair(16, 115), Pair(22, 108), Pair(16, 84),
        Pair(21, 41), Pair(11, 95), Pair(14, 101), Pair(14, 100), Pair(21, 77), Pair(-10, 123), Pair(-10, 92), Pair(-52, 149),
        Pair(-11, 123), Pair(39, 59), Pair(22, 75), Pair(17, 90), Pair(31, 101), Pair(6, 92), Pair(2, 23), Pair(29, -60)
      },
      { // Piece 5
        Pair(39, 66), Pair(38, 166), Pair(59, 75), Pair(-132, 153), Pair(61, 6), Pair(98, 43), Pair(24, 47), Pair(-23, -22),
        Pair(89, -20), Pair(84, -4), Pair(27, 158), Pair(30, 121), Pair(-79, 124), Pair(94, 75), Pair(74, 82), Pair(130, -7),
        Pair(18, 7), Pair(18, 65), Pair(65, 68), Pair(45, 45), Pair(170, 7), Pair(41, 68), Pair(133, 30), Pair(-112, 35),
        Pair(165, 31), Pair(147, -15), Pair(89, 52), Pair(0, 0), Pair(148, 19), Pair(38, 13), Pair(-10, 25), Pair(34, -1),
        Pair(1, -3), Pair(143, 4), Pair(46, 17), Pair(-88, 54), Pair(-11, 25), Pair(61, 20), Pair(-42, 22), Pair(-74, 44),
        Pair(137, -39), Pair(48, 4), Pair(-27, 26), Pair(-35, 34), Pair(4, 33), Pair(-40, 6), Pair(-7, -1), Pair(17, -9),
        Pair(-27, -13), Pair(-31, 6), Pair(40, -13), Pair(-19, 10), Pair(-2, 5), Pair(-15, 1), Pair(8, -3), Pair(-4, -4),
        Pair(27, -37), Pair(-12, -1), Pair(-9, -12), Pair(-18, -12), Pair(-5, -25), Pair(-12, -27), Pair(2, -19), Pair(5, -32)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, 24), Pair(23, 10), Pair(13, 31), Pair(-3, 40), Pair(88, -28), Pair(31, 31), Pair(-7, 6), Pair(12, 22),
        Pair(-19, 33), Pair(14, 15), Pair(5, 17), Pair(41, 35), Pair(8, -10), Pair(30, 41), Pair(-20, 33), Pair(-16, 11),
        Pair(-6, 19), Pair(-2, 13), Pair(-3, -9), Pair(-1, 17), Pair(4, -11), Pair(-5, 20), Pair(-4, -4), Pair(-7, 16),
        Pair(-5, 15), Pair(3, 9), Pair(-6, 12), Pair(11, 32), Pair(-13, -10), Pair(16, 28), Pair(-4, 5), Pair(-10, 12),
        Pair(-7, 19), Pair(4, 10), Pair(-1, 13), Pair(1, 19), Pair(3, 20), Pair(-1, 30), Pair(-3, 6), Pair(-7, 14),
        Pair(-6, 21), Pair(3, 19), Pair(1, 11), Pair(-1, 19), Pair(-4, 26), Pair(-7, 35), Pair(-6, 11), Pair(-10, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-60, -5), Pair(-26, 71), Pair(191, 86), Pair(55, 36), Pair(-64, 173), Pair(41, 40), Pair(-49, 148), Pair(225, 47),
        Pair(87, 7), Pair(13, 126), Pair(27, 90), Pair(-38, 38), Pair(-30, 74), Pair(40, 13), Pair(-81, 109), Pair(60, 96),
        Pair(79, 97), Pair(12, 88), Pair(-9, 26), Pair(8, 60), Pair(20, 27), Pair(35, 82), Pair(32, 68), Pair(4, 68),
        Pair(-29, 70), Pair(16, 94), Pair(28, 70), Pair(30, 79), Pair(0, 0), Pair(39, 96), Pair(2, 91), Pair(-15, 100),
        Pair(-20, 89), Pair(3, 98), Pair(10, 51), Pair(7, 107), Pair(29, 82), Pair(12, 100), Pair(41, 39), Pair(2, 86),
        Pair(6, 40), Pair(26, 52), Pair(-9, 68), Pair(0, 63), Pair(17, 45), Pair(11, 52), Pair(-3, 35), Pair(8, 65),
        Pair(20, 132), Pair(-4, 53), Pair(8, 69), Pair(10, 40), Pair(2, 104), Pair(-8, 65), Pair(-46, 91), Pair(8, 80),
        Pair(60, 153), Pair(-4, 22), Pair(53, 33), Pair(-3, 58), Pair(-22, 82), Pair(14, 39), Pair(-2, 46), Pair(11, 89)
      },
      { // Piece 2
        Pair(214, 18), Pair(-113, 38), Pair(27, 22), Pair(-20, 10), Pair(81, 40), Pair(-29, 35), Pair(212, 32), Pair(-91, 65),
        Pair(46, 29), Pair(55, 6), Pair(91, -18), Pair(54, 65), Pair(9, 5), Pair(78, 67), Pair(-146, 52), Pair(-16, 41),
        Pair(20, 85), Pair(54, -24), Pair(36, 26), Pair(106, 124), Pair(50, 34), Pair(121, 126), Pair(31, 45), Pair(-22, 10),
        Pair(13, -14), Pair(13, 59), Pair(-25, 43), Pair(26, 89), Pair(0, 0), Pair(20, 68), Pair(-19, 39), Pair(-6, 43),
        Pair(28, 55), Pair(21, -16), Pair(11, 72), Pair(-22, 17), Pair(50, 50), Pair(-17, 15), Pair(22, 82), Pair(-41, 54),
        Pair(-1, 16), Pair(6, 63), Pair(-11, 4), Pair(12, 71), Pair(0, 26), Pair(9, 51), Pair(-8, -20), Pair(4, 67),
        Pair(57, 30), Pair(-17, -5), Pair(15, 53), Pair(-15, 26), Pair(21, 77), Pair(-25, 0), Pair(-2, 69), Pair(-68, 10),
        Pair(-15, 5), Pair(-27, 135), Pair(-14, 11), Pair(5, 60), Pair(-18, 4), Pair(5, 23), Pair(29, -33), Pair(2, 60)
      },
      { // Piece 3
        Pair(7, 85), Pair(160, 37), Pair(48, 70), Pair(63, 77), Pair(-64, 51), Pair(77, 63), Pair(-29, 92), Pair(135, 34),
        Pair(7, 97), Pair(28, 75), Pair(3, 75), Pair(-59, 122), Pair(-5, 64), Pair(-32, 90), Pair(-38, 116), Pair(-32, 112),
        Pair(-68, 96), Pair(22, 97), Pair(-13, 95), Pair(-28, 126), Pair(96, -5), Pair(22, 115), Pair(-24, 97), Pair(-51, 154),
        Pair(-18, 50), Pair(19, 61), Pair(-6, 63), Pair(-20, 61), Pair(0, 0), Pair(2, 64), Pair(-44, 91), Pair(-2, 76),
        Pair(-21, 84), Pair(-54, 105), Pair(-19, 85), Pair(-44, 82), Pair(41, -8), Pair(19, 71), Pair(37, 69), Pair(-25, 91),
        Pair(-43, 93), Pair(-17, 68), Pair(5, 58), Pair(-49, 74), Pair(-7, 42), Pair(-40, 102), Pair(6, 49), Pair(5, 51),
        Pair(-32, 74), Pair(6, 45), Pair(-64, 103), Pair(-48, 114), Pair(5, 41), Pair(-21, 103), Pair(-24, 89), Pair(25, 46),
        Pair(-20, 53), Pair(-18, 75), Pair(-34, 83), Pair(-33, 82), Pair(18, 15), Pair(-30, 65), Pair(-6, 76), Pair(-1, 56)
      },
      { // Piece 4
        Pair(50, 78), Pair(65, 9), Pair(4, 144), Pair(32, 137), Pair(19, 147), Pair(-52, 167), Pair(-57, 129), Pair(-71, 161),
        Pair(-17, 192), Pair(-44, 168), Pair(-23, 61), Pair(-21, 101), Pair(-25, 152), Pair(27, 32), Pair(6, 12), Pair(-2, 86),
        Pair(-10, 165), Pair(44, 31), Pair(50, 62), Pair(6, 128), Pair(62, 36), Pair(-7, 196), Pair(27, 166), Pair(5, 141),
        Pair(53, 33), Pair(-2, 107), Pair(32, 46), Pair(20, 94), Pair(0, 0), Pair(73, 70), Pair(16, 137), Pair(32, 60),
        Pair(9, 94), Pair(35, 97), Pair(13, 119), Pair(3, 139), Pair(24, 84), Pair(40, 108), Pair(30, 94), Pair(-2, 208),
        Pair(-13, 63), Pair(8, 120), Pair(17, 27), Pair(34, 93), Pair(29, 52), Pair(24, 59), Pair(31, 75), Pair(-18, 136),
        Pair(55, 72), Pair(34, 1), Pair(17, 94), Pair(20, 65), Pair(15, 82), Pair(34, 31), Pair(-10, 102), Pair(26, 25),
        Pair(-15, 195), Pair(17, 79), Pair(20, 149), Pair(18, 67), Pair(11, 30), Pair(58, -54), Pair(-52, 200), Pair(40, 161)
      },
      { // Piece 5
        Pair(-2, 94), Pair(-32, -40), Pair(84, -44), Pair(98, -64), Pair(-25, 82), Pair(44, 4), Pair(143, 292), Pair(-6, 80),
        Pair(-54, 35), Pair(84, 51), Pair(77, -21), Pair(225, 50), Pair(58, 62), Pair(61, 49), Pair(61, 39), Pair(16, 111),
        Pair(44, -30), Pair(-86, 39), Pair(11, 76), Pair(-25, 49), Pair(67, 25), Pair(102, 8), Pair(54, 108), Pair(102, 29),
        Pair(19, 5), Pair(-1, 8), Pair(67, 33), Pair(125, -6), Pair(0, 0), Pair(286, -19), Pair(167, 5), Pair(53, 33),
        Pair(-201, 19), Pair(24, 9), Pair(75, 0), Pair(19, 4), Pair(-69, 57), Pair(-1, 5), Pair(27, 17), Pair(57, 8),
        Pair(-2, 10), Pair(26, -30), Pair(21, -6), Pair(13, -2), Pair(-74, 24), Pair(-38, 24), Pair(44, -21), Pair(-29, -2),
        Pair(-5, -13), Pair(-35, -11), Pair(0, -19), Pair(-23, -9), Pair(-15, -16), Pair(2, -12), Pair(9, -11), Pair(14, -20),
        Pair(-53, -27), Pair(-30, -31), Pair(-26, -32), Pair(-20, -47), Pair(-24, -31), Pair(-19, -39), Pair(12, -33), Pair(15, -60)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-86, 51), Pair(7, -6), Pair(11, 32), Pair(25, -2), Pair(-33, 64), Pair(6, 15), Pair(-2, 51), Pair(142, -42),
        Pair(-45, 32), Pair(-43, 46), Pair(-24, 35), Pair(18, 28), Pair(49, 29), Pair(-93, -23), Pair(7, 14), Pair(-2, -27),
        Pair(-5, 20), Pair(0, 15), Pair(-1, 17), Pair(-4, -1), Pair(-4, 23), Pair(-9, -6), Pair(3, 4), Pair(-11, -12),
        Pair(3, 11), Pair(0, 10), Pair(7, 8), Pair(4, 8), Pair(13, 23), Pair(-16, -10), Pair(8, 15), Pair(-8, 0),
        Pair(-6, 15), Pair(10, 11), Pair(5, 5), Pair(8, 14), Pair(4, 31), Pair(8, 5), Pair(-3, 18), Pair(-6, 11),
        Pair(-11, 20), Pair(3, 8), Pair(-1, 13), Pair(-1, 8), Pair(-4, 52), Pair(2, 18), Pair(-7, 25), Pair(-10, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(8, -61), Pair(38, -86), Pair(-59, 31), Pair(50, 50), Pair(51, 61), Pair(65, 73), Pair(-57, -8), Pair(189, 99),
        Pair(-108, 84), Pair(62, -2), Pair(-2, 44), Pair(53, 7), Pair(5, 47), Pair(27, 76), Pair(48, 32), Pair(-56, 72),
        Pair(130, 13), Pair(49, 30), Pair(46, 38), Pair(41, 30), Pair(21, 14), Pair(32, 32), Pair(19, 126), Pair(-133, 75),
        Pair(-21, 22), Pair(-5, 50), Pair(-2, 25), Pair(42, 20), Pair(55, 54), Pair(0, 0), Pair(5, 105), Pair(19, 70),
        Pair(15, -40), Pair(20, 1), Pair(10, 51), Pair(30, 13), Pair(31, 61), Pair(11, 67), Pair(31, 45), Pair(12, 13),
        Pair(13, 25), Pair(5, -30), Pair(14, 35), Pair(25, 43), Pair(23, 25), Pair(16, 49), Pair(18, 47), Pair(1, 52),
        Pair(78, 45), Pair(29, 26), Pair(11, 13), Pair(18, 31), Pair(-5, 31), Pair(-3, 48), Pair(44, 6), Pair(36, 72),
        Pair(-272, 91), Pair(-9, 9), Pair(34, 78), Pair(-32, 32), Pair(-34, 19), Pair(-15, 40), Pair(-19, 12), Pair(57, 26)
      },
      { // Piece 2
        Pair(49, -100), Pair(-83, 16), Pair(-32, -4), Pair(-104, 42), Pair(57, -67), Pair(21, 41), Pair(184, -49), Pair(147, -12),
        Pair(70, 38), Pair(57, -35), Pair(-6, 34), Pair(12, -20), Pair(184, -21), Pair(47, -40), Pair(134, 30), Pair(-93, 10),
        Pair(18, -29), Pair(15, 55), Pair(81, -44), Pair(-40, 98), Pair(45, -13), Pair(38, 46), Pair(-92, 24), Pair(11, 9),
        Pair(-19, 21), Pair(24, -32), Pair(-40, 71), Pair(48, -15), Pair(85, 31), Pair(0, 0), Pair(43, 41), Pair(-33, 6),
        Pair(90, -42), Pair(-8, 37), Pair(26, -12), Pair(28, 60), Pair(45, 1), Pair(14, 61), Pair(-26, 11), Pair(28, 53),
        Pair(21, 36), Pair(22, -1), Pair(24, 36), Pair(17, -32), Pair(2, 70), Pair(15, -7), Pair(51, 22), Pair(-11, -96),
        Pair(-30, -25), Pair(-14, 38), Pair(-3, -24), Pair(5, 42), Pair(1, -23), Pair(27, 34), Pair(7, -30), Pair(71, 19),
        Pair(-20, 20), Pair(29, -22), Pair(2, 52), Pair(35, -44), Pair(-3, 30), Pair(13, -54), Pair(-48, 61), Pair(7, -7)
      },
      { // Piece 3
        Pair(69, 77), Pair(27, 66), Pair(77, 51), Pair(22, 76), Pair(-83, 121), Pair(97, -11), Pair(-131, 101), Pair(-43, 71),
        Pair(-10, 80), Pair(17, 57), Pair(25, 35), Pair(-19, 82), Pair(-25, 88), Pair(-56, 52), Pair(-38, 71), Pair(64, 43),
        Pair(-86, 77), Pair(-37, 66), Pair(-67, 86), Pair(-6, 56), Pair(33, 59), Pair(27, -19), Pair(59, 51), Pair(68, 39),
        Pair(-18, 77), Pair(-11, 50), Pair(58, 34), Pair(-5, 63), Pair(-46, 93), Pair(0, 0), Pair(-21, 53), Pair(31, 56),
        Pair(2, 42), Pair(-46, 69), Pair(-57, 65), Pair(25, 47), Pair(19, 36), Pair(114, -67), Pair(-3, 74), Pair(67, -1),
        Pair(-20, 72), Pair(-54, 50), Pair(-48, 89), Pair(43, 26), Pair(8, 40), Pair(60, -40), Pair(24, 17), Pair(36, 37),
        Pair(-27, 68), Pair(-22, 74), Pair(-1, 27), Pair(0, 51), Pair(-13, 65), Pair(38, 20), Pair(-29, 47), Pair(7, 58),
        Pair(-20, 38), Pair(-14, 51), Pair(-9, 28), Pair(-23, 63), Pair(-30, 76), Pair(21, 4), Pair(5, 47), Pair(-12, 57)
      },
      { // Piece 4
        Pair(206, -88), Pair(-3, 23), Pair(37, -1), Pair(73, 71), Pair(47, 19), Pair(35, -35), Pair(7, 124), Pair(-73, 136),
        Pair(46, -35), Pair(-15, 114), Pair(23, 116), Pair(48, 30), Pair(-30, 75), Pair(31, 7), Pair(75, 108), Pair(-29, 20),
        Pair(-21, 212), Pair(-3, 168), Pair(-30, 116), Pair(-54, 183), Pair(64, 73), Pair(76, 69), Pair(-35, 54), Pair(15, 153),
        Pair(9, 147), Pair(-1, 108), Pair(-39, 171), Pair(66, 24), Pair(-13, 129), Pair(0, 0), Pair(41, -7), Pair(34, 18),
        Pair(3, 11), Pair(59, 1), Pair(24, 115), Pair(34, 132), Pair(15, 166), Pair(83, -42), Pair(49, 66), Pair(31, -38),
        Pair(-10, 93), Pair(24, 35), Pair(17, 108), Pair(39, 72), Pair(38, 2), Pair(44, 38), Pair(35, 4), Pair(56, -73),
        Pair(26, 105), Pair(-11, 135), Pair(25, 33), Pair(57, -32), Pair(25, 60), Pair(39, -92), Pair(51, 50), Pair(18, 133),
        Pair(-20, 235), Pair(28, 95), Pair(15, 20), Pair(24, 101), Pair(45, -78), Pair(25, 54), Pair(3, 12), Pair(6, -55)
      },
      { // Piece 5
        Pair(29, 8), Pair(-45, 31), Pair(-113, -21), Pair(64, 33), Pair(-106, 19), Pair(-12, 7), Pair(-6, 29), Pair(54, 143),
        Pair(89, -25), Pair(-78, 14), Pair(90, 9), Pair(37, -17), Pair(-41, 90), Pair(9, 71), Pair(-7, 103), Pair(166, 16),
        Pair(263, -63), Pair(57, -15), Pair(107, -18), Pair(-76, 50), Pair(-146, 60), Pair(0, -8), Pair(116, 36), Pair(63, 46),
        Pair(-61, 38), Pair(30, 12), Pair(-81, 21), Pair(24, 12), Pair(187, -13), Pair(0, 0), Pair(171, 10), Pair(126, -8),
        Pair(9, -3), Pair(-52, 10), Pair(-24, 6), Pair(28, -2), Pair(-53, 23), Pair(-29, 27), Pair(99, -21), Pair(97, 9),
        Pair(-116, 6), Pair(19, -4), Pair(-49, -16), Pair(-6, -7), Pair(-28, 11), Pair(-64, 23), Pair(-8, 23), Pair(26, -19),
        Pair(-67, -20), Pair(-13, -53), Pair(-10, -9), Pair(-25, -20), Pair(-22, -10), Pair(-22, -11), Pair(1, -18), Pair(-13, -15),
        Pair(-37, -56), Pair(-37, -19), Pair(-31, -49), Pair(6, -46), Pair(-23, -26), Pair(-14, -29), Pair(-7, -34), Pair(12, -38)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-42, 30), Pair(18, 6), Pair(-30, 34), Pair(-17, 11), Pair(25, 9), Pair(-60, 40), Pair(10, -16), Pair(24, 27),
        Pair(4, 8), Pair(7, 16), Pair(18, 25), Pair(4, 23), Pair(-35, 29), Pair(24, 22), Pair(28, -20), Pair(13, 15),
        Pair(-8, 8), Pair(-1, 25), Pair(7, 7), Pair(2, 16), Pair(-6, -5), Pair(3, 3), Pair(17, 0), Pair(-12, 7),
        Pair(-6, 18), Pair(0, 14), Pair(2, 13), Pair(-2, 18), Pair(2, 3), Pair(11, 17), Pair(3, -12), Pair(12, 16),
        Pair(-2, 13), Pair(-2, 12), Pair(1, 14), Pair(1, 8), Pair(6, 10), Pair(3, 17), Pair(23, -3), Pair(0, 32),
        Pair(-5, 19), Pair(3, 19), Pair(1, 16), Pair(-9, 12), Pair(5, 19), Pair(-5, 34), Pair(15, 8), Pair(-1, 23),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-21, -15), Pair(124, -42), Pair(-98, 6), Pair(104, -24), Pair(-43, 59), Pair(-120, 48), Pair(131, 111), Pair(-164, 76),
        Pair(-8, 34), Pair(-19, 33), Pair(15, 46), Pair(54, 43), Pair(40, 59), Pair(13, 71), Pair(53, 59), Pair(149, -7),
        Pair(74, 38), Pair(-19, 6), Pair(28, 24), Pair(-54, 79), Pair(26, 69), Pair(107, 5), Pair(34, 7), Pair(-6, 3),
        Pair(52, -10), Pair(-9, 13), Pair(11, 50), Pair(16, 49), Pair(7, 49), Pair(34, 114), Pair(0, 0), Pair(9, 76),
        Pair(-12, 10), Pair(74, 22), Pair(9, 31), Pair(8, 54), Pair(33, 30), Pair(28, 68), Pair(60, 42), Pair(21, 53),
        Pair(5, -10), Pair(-2, 26), Pair(-7, 27), Pair(-1, 46), Pair(24, 61), Pair(10, 55), Pair(22, 10), Pair(-6, -8),
        Pair(-19, 65), Pair(-22, 11), Pair(9, 36), Pair(-4, 31), Pair(18, 17), Pair(-8, 25), Pair(63, 39), Pair(-5, 22),
        Pair(147, 32), Pair(-18, -14), Pair(-38, 27), Pair(-37, 36), Pair(9, 34), Pair(34, -59), Pair(-4, 18), Pair(-53, 11)
      },
      { // Piece 2
        Pair(-12, 30), Pair(15, -71), Pair(-19, 0), Pair(83, -32), Pair(274, -28), Pair(34, -24), Pair(-12, 16), Pair(62, 35),
        Pair(25, -92), Pair(3, 24), Pair(-34, -28), Pair(153, -41), Pair(31, -14), Pair(172, -10), Pair(-25, 18), Pair(-11, 82),
        Pair(33, -2), Pair(24, -32), Pair(78, -6), Pair(40, -11), Pair(102, 10), Pair(158, 97), Pair(25, 19), Pair(-45, 0),
        Pair(-10, -6), Pair(29, 21), Pair(-3, -10), Pair(24, 33), Pair(-4, -1), Pair(59, 72), Pair(0, 0), Pair(10, 15),
        Pair(30, 19), Pair(20, -15), Pair(24, 8), Pair(16, -6), Pair(53, 31), Pair(-3, -6), Pair(26, 52), Pair(-26, -50),
        Pair(-11, 12), Pair(50, 36), Pair(17, -3), Pair(51, 27), Pair(-1, 13), Pair(21, 26), Pair(44, -1), Pair(8, 37),
        Pair(-6, -7), Pair(22, -22), Pair(19, 33), Pair(-5, -5), Pair(29, 18), Pair(16, -4), Pair(33, 21), Pair(-7, -41),
        Pair(11, 8), Pair(-29, 33), Pair(-14, -16), Pair(46, 9), Pair(-26, 6), Pair(16, 11), Pair(132, -73), Pair(41, -10)
      },
      { // Piece 3
        Pair(65, 57), Pair(21, 62), Pair(25, 58), Pair(131, 53), Pair(125, 66), Pair(-40, 97), Pair(39, 33), Pair(-36, 82),
        Pair(15, 79), Pair(-43, 105), Pair(9, 70), Pair(-6, 97), Pair(35, 71), Pair(-34, 103), Pair(-154, 95), Pair(-11, 93),
        Pair(20, 75), Pair(13, 81), Pair(-13, 86), Pair(104, 48), Pair(-51, 123), Pair(25, 86), Pair(81, -9), Pair(-34, 88),
        Pair(24, 56), Pair(36, 67), Pair(12, 52), Pair(7, 57), Pair(9, 62), Pair(7, 43), Pair(0, 0), Pair(-47, 62),
        Pair(-9, 70), Pair(7, 66), Pair(-12, 64), Pair(12, 57), Pair(-23, 89), Pair(44, 61), Pair(15, 14), Pair(-29, 64),
        Pair(-39, 72), Pair(-16, 44), Pair(17, 56), Pair(46, 22), Pair(18, 49), Pair(-3, 55), Pair(13, -9), Pair(-30, 37),
        Pair(-1, 72), Pair(-13, 5), Pair(-12, 82), Pair(-18, 46), Pair(-42, 70), Pair(1, 65), Pair(-38, 9), Pair(-18, 51),
        Pair(0, 33), Pair(4, 38), Pair(3, 56), Pair(-9, 53), Pair(-9, 78), Pair(-3, 46), Pair(5, -1), Pair(-21, 59)
      },
      { // Piece 4
        Pair(-20, 83), Pair(4, 14), Pair(64, -5), Pair(152, -107), Pair(21, 77), Pair(28, 27), Pair(19, -39), Pair(-29, 106),
        Pair(9, -40), Pair(27, 42), Pair(-33, 187), Pair(102, -21), Pair(46, 4), Pair(-19, 81), Pair(-37, -1), Pair(-62, 189),
        Pair(-65, 65), Pair(46, 2), Pair(10, 134), Pair(-11, 88), Pair(39, 97), Pair(31, 55), Pair(-26, 57), Pair(-42, 9),
        Pair(7, 65), Pair(11, 6), Pair(-20, 130), Pair(14, 60), Pair(49, 14), Pair(40, 70), Pair(0, 0), Pair(-23, 22),
        Pair(22, 7), Pair(-30, 109), Pair(22, 47), Pair(31, 15), Pair(25, 19), Pair(38, 24), Pair(28, 60), Pair(-33, 23),
        Pair(52, 36), Pair(-20, 62), Pair(-8, 106), Pair(30, -12), Pair(36, -1), Pair(9, 46), Pair(37, 27), Pair(-43, 100),
        Pair(-46, 88), Pair(-8, 100), Pair(2, 64), Pair(22, 10), Pair(22, 3), Pair(25, -10), Pair(-6, 1), Pair(14, -30),
        Pair(-38, 88), Pair(-8, 141), Pair(26, 9), Pair(11, 26), Pair(23, 46), Pair(-1, -68), Pair(19, -96), Pair(-61, 69)
      },
      { // Piece 5
        Pair(103, 51), Pair(-75, -39), Pair(-4, -41), Pair(35, 31), Pair(15, -5), Pair(4, 7), Pair(-21, 92), Pair(38, 65),
        Pair(39, 52), Pair(48, 30), Pair(-147, 7), Pair(50, -6), Pair(91, -47), Pair(-30, 82), Pair(34, 96), Pair(103, 78),
        Pair(-27, 78), Pair(-26, 36), Pair(60, 25), Pair(189, -19), Pair(197, -4), Pair(161, 1), Pair(109, 17), Pair(-37, 54),
        Pair(-159, 39), Pair(-47, 21), Pair(34, 19), Pair(152, -8), Pair(67, -7), Pair(309, -27), Pair(0, 0), Pair(293, -45),
        Pair(-157, 28), Pair(-179, 61), Pair(-89, 29), Pair(-108, 20), Pair(-59, 34), Pair(12, -10), Pair(78, -9), Pair(25, -19),
        Pair(-211, 50), Pair(-83, 6), Pair(4, 3), Pair(-31, -1), Pair(-6, 9), Pair(-17, 10), Pair(48, -12), Pair(61, -19),
        Pair(-87, 22), Pair(-92, 25), Pair(-80, 10), Pair(-28, 1), Pair(-5, -11), Pair(21, -17), Pair(40, -21), Pair(18, -28),
        Pair(-46, 25), Pair(-45, 0), Pair(-39, -6), Pair(-60, 13), Pair(-10, -25), Pair(9, -39), Pair(26, -27), Pair(-17, -26)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(20, 15), Pair(7, 18), Pair(-53, 45), Pair(6, 26), Pair(-93, 46), Pair(4, 35), Pair(56, 9), Pair(43, -35),
        Pair(-18, 11), Pair(-30, 35), Pair(-23, 28), Pair(-5, 22), Pair(14, -3), Pair(-23, 18), Pair(30, 11), Pair(54, -77),
        Pair(-3, 10), Pair(-8, 5), Pair(12, 9), Pair(-6, 15), Pair(-8, 15), Pair(-10, -12), Pair(-12, 6), Pair(7, -13),
        Pair(3, 7), Pair(-2, 15), Pair(-7, 17), Pair(-3, 13), Pair(1, 10), Pair(1, -8), Pair(5, 14), Pair(1, -23),
        Pair(-1, 11), Pair(-5, 8), Pair(-1, 11), Pair(-5, 6), Pair(-2, 5), Pair(10, -7), Pair(-2, 26), Pair(10, 0),
        Pair(1, 9), Pair(-1, 10), Pair(-7, 15), Pair(-5, 4), Pair(0, 8), Pair(6, 3), Pair(-2, 37), Pair(-2, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(43, 86), Pair(86, -56), Pair(177, -14), Pair(60, -16), Pair(57, -61), Pair(10, 17), Pair(109, 46), Pair(-25, -22),
        Pair(-100, 40), Pair(102, -31), Pair(51, -30), Pair(-7, -5), Pair(46, -17), Pair(44, 39), Pair(-48, 7), Pair(3, 51),
        Pair(12, 33), Pair(39, 18), Pair(57, 9), Pair(67, 16), Pair(60, 15), Pair(71, 25), Pair(78, 32), Pair(-3, 8),
        Pair(52, -30), Pair(9, -22), Pair(33, -22), Pair(28, 32), Pair(17, 43), Pair(25, 24), Pair(33, 19), Pair(0, 0),
        Pair(-10, 2), Pair(-2, 30), Pair(14, 42), Pair(11, 25), Pair(11, 30), Pair(41, 9), Pair(50, 28), Pair(66, 31),
        Pair(-4, -48), Pair(16, -3), Pair(1, 0), Pair(15, 19), Pair(19, 41), Pair(16, 25), Pair(14, 27), Pair(20, -5),
        Pair(-27, 13), Pair(81, -20), Pair(-19, 21), Pair(12, 1), Pair(6, 23), Pair(21, 6), Pair(21, -30), Pair(2, 41),
        Pair(7, 73), Pair(-10, -42), Pair(41, -17), Pair(9, -8), Pair(-43, 35), Pair(-20, 27), Pair(-4, 3), Pair(11, -3)
      },
      { // Piece 2
        Pair(131, -22), Pair(-38, -52), Pair(130, -93), Pair(147, -42), Pair(244, -50), Pair(48, 2), Pair(216, -6), Pair(-1, 30),
        Pair(-5, 10), Pair(93, -50), Pair(9, -22), Pair(41, -44), Pair(98, -3), Pair(147, -38), Pair(39, 58), Pair(26, 11),
        Pair(63, -15), Pair(-41, 16), Pair(17, -11), Pair(23, 2), Pair(43, 2), Pair(126, 8), Pair(51, 45), Pair(25, 6),
        Pair(-7, -2), Pair(18, -32), Pair(-4, 17), Pair(36, -18), Pair(24, 39), Pair(75, -2), Pair(16, 31), Pair(0, 0),
        Pair(68, -35), Pair(-10, 29), Pair(23, -25), Pair(15, 10), Pair(46, -9), Pair(26, 15), Pair(37, -7), Pair(55, 52),
        Pair(-12, -1), Pair(58, -19), Pair(-17, 21), Pair(41, -2), Pair(20, 18), Pair(40, -9), Pair(16, 4), Pair(66, -37),
        Pair(68, 7), Pair(18, 27), Pair(77, -26), Pair(-4, 18), Pair(30, -11), Pair(3, 2), Pair(37, -17), Pair(-53, -11),
        Pair(61, -23), Pair(45, -3), Pair(10, 1), Pair(0, -23), Pair(-1, 21), Pair(21, -46), Pair(84, -30), Pair(8, -14)
      },
      { // Piece 3
        Pair(59, 2), Pair(165, -32), Pair(100, 3), Pair(38, 19), Pair(135, -8), Pair(-31, 50), Pair(136, -34), Pair(142, -47),
        Pair(38, 26), Pair(18, 37), Pair(40, 31), Pair(13, 29), Pair(87, 6), Pair(14, 40), Pair(74, 21), Pair(99, -35),
        Pair(-10, 37), Pair(-4, 46), Pair(69, 15), Pair(8, 39), Pair(26, 40), Pair(0, 71), Pair(31, 27), Pair(40, -10),
        Pair(57, 11), Pair(18, 26), Pair(16, 21), Pair(44, 18), Pair(-22, 65), Pair(42, 30), Pair(-2, 30), Pair(0, 0),
        Pair(13, 14), Pair(89, -10), Pair(-13, 26), Pair(42, 2), Pair(26, 36), Pair(24, 31), Pair(14, 49), Pair(13, 4),
        Pair(7, 20), Pair(-57, 76), Pair(17, 16), Pair(14, 43), Pair(-1, 55), Pair(26, 32), Pair(-12, 68), Pair(-15, -27),
        Pair(14, 1), Pair(-2, 45), Pair(50, 6), Pair(39, 26), Pair(5, 46), Pair(4, 28), Pair(37, 9), Pair(-17, -37),
        Pair(10, -4), Pair(9, 37), Pair(23, 0), Pair(7, 26), Pair(-7, 27), Pair(4, 38), Pair(-7, 35), Pair(-41, 11)
      },
      { // Piece 4
        Pair(38, -26), Pair(69, 21), Pair(-41, 57), Pair(1, 49), Pair(152, -17), Pair(72, 9), Pair(46, 91), Pair(101, -28),
        Pair(-11, 51), Pair(35, 68), Pair(17, 28), Pair(88, -45), Pair(43, -25), Pair(-7, -65), Pair(-42, 77), Pair(-13, 93),
        Pair(48, -7), Pair(-21, 91), Pair(9, -12), Pair(-11, 83), Pair(66, 3), Pair(65, 24), Pair(85, -16), Pair(52, -52),
        Pair(41, 25), Pair(2, 22), Pair(17, 104), Pair(40, 9), Pair(37, 25), Pair(33, 41), Pair(4, 86), Pair(0, 0),
        Pair(24, -43), Pair(32, 0), Pair(28, -6), Pair(10, 78), Pair(24, 2), Pair(29, 76), Pair(39, 39), Pair(-35, 73),
        Pair(50, -47), Pair(4, 75), Pair(20, 41), Pair(42, -6), Pair(5, 11), Pair(30, -5), Pair(40, -10), Pair(4, 98),
        Pair(10, 7), Pair(38, -43), Pair(18, 8), Pair(23, 63), Pair(29, -17), Pair(54, -54), Pair(28, 93), Pair(-8, -11),
        Pair(13, -53), Pair(21, 51), Pair(44, 46), Pair(16, 5), Pair(7, -35), Pair(-5, 17), Pair(14, -4), Pair(-10, 68)
      },
      { // Piece 5
        Pair(31, 51), Pair(1, -77), Pair(3, -54), Pair(21, -73), Pair(164, -24), Pair(-66, 92), Pair(5, 172), Pair(0, -70),
        Pair(83, 15), Pair(-66, -73), Pair(138, -78), Pair(105, -69), Pair(160, -70), Pair(23, 44), Pair(-29, 116), Pair(-28, -24),
        Pair(7, 30), Pair(-108, 55), Pair(61, -31), Pair(74, -19), Pair(304, -36), Pair(201, 8), Pair(226, -41), Pair(51, -44),
        Pair(-26, 22), Pair(-78, -3), Pair(-201, 32), Pair(6, 2), Pair(-37, 50), Pair(111, -22), Pair(283, -37), Pair(0, 0),
        Pair(-228, 10), Pair(-320, 74), Pair(-81, 20), Pair(-17, 11), Pair(40, 1), Pair(47, 23), Pair(5, 0), Pair(110, -64),
        Pair(-105, 4), Pair(-98, 24), Pair(-118, 30), Pair(-24, 12), Pair(-63, 14), Pair(27, -9), Pair(92, -20), Pair(-1, -24),
        Pair(-51, -29), Pair(-100, 19), Pair(-51, 0), Pair(-62, 18), Pair(-48, 2), Pair(-1, 0), Pair(22, -2), Pair(23, -33),
        Pair(-40, -15), Pair(-41, 12), Pair(-34, -5), Pair(-46, -18), Pair(-21, -24), Pair(-12, -18), Pair(-10, -3), Pair(-10, -24)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-54, 41), Pair(-59, 32), Pair(30, 4), Pair(49, 2), Pair(-18, 17), Pair(90, -13), Pair(-29, 20), Pair(-24, 57),
        Pair(16, -12), Pair(3, 39), Pair(-8, 20), Pair(-8, 15), Pair(-11, 35), Pair(-3, 19), Pair(17, 14), Pair(-5, 12),
        Pair(17, -14), Pair(1, 27), Pair(-5, 8), Pair(-1, 11), Pair(-5, 14), Pair(5, 14), Pair(-6, 19), Pair(4, 8),
        Pair(-1, 15), Pair(-14, 3), Pair(0, 4), Pair(-1, 10), Pair(0, 18), Pair(1, 15), Pair(1, 17), Pair(-4, 11),
        Pair(21, -17), Pair(2, 11), Pair(3, 9), Pair(-3, 11), Pair(3, 13), Pair(0, 17), Pair(2, 17), Pair(1, 21),
        Pair(10, 10), Pair(-2, 24), Pair(-1, 8), Pair(-5, 12), Pair(-4, 13), Pair(0, 28), Pair(-3, 22), Pair(-3, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-62, -18), Pair(-82, 98), Pair(91, 54), Pair(48, 81), Pair(-72, 93), Pair(-67, 94), Pair(26, 15), Pair(-78, 50),
        Pair(28, 78), Pair(-71, 101), Pair(24, 57), Pair(-24, 112), Pair(4, 63), Pair(-9, 51), Pair(75, 73), Pair(-45, 97),
        Pair(38, 17), Pair(-7, 65), Pair(31, 85), Pair(-8, 80), Pair(-32, 83), Pair(-46, 109), Pair(16, 76), Pair(-61, 66),
        Pair(-61, 81), Pair(15, 53), Pair(-4, 104), Pair(-1, 74), Pair(-2, 86), Pair(5, 76), Pair(-5, 55), Pair(-19, 55),
        Pair(0, 0), Pair(-17, 119), Pair(-9, 83), Pair(-1, 88), Pair(-4, 65), Pair(1, 81), Pair(-20, 82), Pair(-11, 60),
        Pair(4, 41), Pair(26, 74), Pair(5, 60), Pair(-4, 84), Pair(4, 69), Pair(3, 68), Pair(7, 50), Pair(-7, 69),
        Pair(27, 60), Pair(-9, 71), Pair(-9, 74), Pair(0, 65), Pair(5, 62), Pair(2, 66), Pair(-3, 58), Pair(8, 32),
        Pair(14, -52), Pair(-10, 29), Pair(-4, 84), Pair(7, 43), Pair(19, 59), Pair(12, 38), Pair(-9, 42), Pair(-108, 74)
      },
      { // Piece 2
        Pair(-109, 100), Pair(0, 57), Pair(137, 43), Pair(-66, 42), Pair(88, 30), Pair(-41, 59), Pair(14, 31), Pair(-16, 96),
        Pair(-33, 74), Pair(62, 66), Pair(37, 43), Pair(49, 52), Pair(52, 20), Pair(42, 26), Pair(56, 39), Pair(-18, 29),
        Pair(32, 66), Pair(39, 83), Pair(32, 63), Pair(15, 58), Pair(50, 45), Pair(12, 28), Pair(16, 38), Pair(8, 61),
        Pair(8, 30), Pair(-6, 140), Pair(21, 62), Pair(8, 61), Pair(16, 63), Pair(9, 44), Pair(10, 58), Pair(22, 45),
        Pair(0, 0), Pair(14, 69), Pair(10, 68), Pair(-16, 87), Pair(-11, 71), Pair(6, 67), Pair(43, 41), Pair(20, 54),
        Pair(9, 53), Pair(18, 59), Pair(7, 91), Pair(9, 59), Pair(11, 81), Pair(16, 57), Pair(-2, 75), Pair(5, 66),
        Pair(-17, 49), Pair(10, 45), Pair(-11, 70), Pair(6, 72), Pair(9, 57), Pair(5, 88), Pair(10, 70), Pair(0, 30),
        Pair(24, 55), Pair(-29, 81), Pair(-7, 66), Pair(10, 59), Pair(8, 75), Pair(3, 68), Pair(5, 42), Pair(-9, 93)
      },
      { // Piece 3
        Pair(-105, 91), Pair(-29, 92), Pair(13, 91), Pair(-4, 100), Pair(39, 88), Pair(7, 81), Pair(10, 84), Pair(3, 88),
        Pair(-59, 79), Pair(-33, 108), Pair(-43, 115), Pair(-35, 113), Pair(-21, 111), Pair(-9, 112), Pair(54, 87), Pair(11, 107),
        Pair(-93, 88), Pair(-40, 127), Pair(-16, 107), Pair(27, 94), Pair(-42, 110), Pair(-71, 124), Pair(-19, 104), Pair(-4, 95),
        Pair(-73, 87), Pair(-20, 128), Pair(-32, 134), Pair(3, 121), Pair(-23, 109), Pair(-15, 118), Pair(18, 85), Pair(22, 94),
        Pair(0, 0), Pair(-7, 122), Pair(3, 100), Pair(-20, 110), Pair(-18, 120), Pair(13, 102), Pair(-11, 106), Pair(-15, 105),
        Pair(-35, 67), Pair(-21, 94), Pair(-39, 129), Pair(-11, 124), Pair(-31, 127), Pair(-4, 88), Pair(-22, 115), Pair(4, 99),
        Pair(-69, 58), Pair(-28, 132), Pair(-39, 120), Pair(-20, 125), Pair(-8, 117), Pair(-7, 123), Pair(-21, 124), Pair(8, 109),
        Pair(-47, 49), Pair(-42, 126), Pair(-10, 96), Pair(-15, 103), Pair(-20, 102), Pair(-6, 85), Pair(-10, 99), Pair(-10, 83)
      },
      { // Piece 4
        Pair(13, 195), Pair(-50, 232), Pair(61, 175), Pair(53, 161), Pair(-25, 226), Pair(-49, 195), Pair(148, 151), Pair(85, 124),
        Pair(6, 206), Pair(-21, 257), Pair(-32, 236), Pair(16, 232), Pair(19, 201), Pair(18, 202), Pair(25, 200), Pair(39, 170),
        Pair(-44, 253), Pair(-8, 288), Pair(-8, 231), Pair(56, 162), Pair(41, 247), Pair(-29, 231), Pair(37, 214), Pair(40, 123),
        Pair(-9, 207), Pair(9, 222), Pair(21, 218), Pair(11, 212), Pair(15, 211), Pair(3, 209), Pair(10, 218), Pair(27, 165),
        Pair(0, 0), Pair(9, 230), Pair(19, 212), Pair(-2, 207), Pair(14, 210), Pair(6, 216), Pair(33, 133), Pair(43, 154),
        Pair(19, 196), Pair(19, 215), Pair(30, 177), Pair(27, 171), Pair(31, 213), Pair(25, 202), Pair(-3, 226), Pair(37, 162),
        Pair(36, 108), Pair(11, 163), Pair(24, 178), Pair(27, 172), Pair(28, 182), Pair(34, 161), Pair(12, 199), Pair(28, 103),
        Pair(-9, 170), Pair(10, 217), Pair(23, 249), Pair(22, 175), Pair(48, 149), Pair(19, 207), Pair(-12, 204), Pair(50, 98)
      },
      { // Piece 5
        Pair(-125, 76), Pair(-42, 1), Pair(61, 11), Pair(13, 33), Pair(-93, 19), Pair(14, -1), Pair(-84, -23), Pair(-8, 87),
        Pair(23, 53), Pair(-21, 37), Pair(152, 31), Pair(-32, 27), Pair(-1, 13), Pair(19, 11), Pair(11, 8), Pair(101, -4),
        Pair(-6, -15), Pair(61, 75), Pair(233, -23), Pair(70, 53), Pair(10, 22), Pair(-32, 22), Pair(-27, 15), Pair(-223, 34),
        Pair(87, -28), Pair(117, -17), Pair(-16, 63), Pair(-30, 42), Pair(29, 29), Pair(-83, 28), Pair(-51, 17), Pair(-146, 24),
        Pair(0, 0), Pair(21, 16), Pair(-26, 38), Pair(-53, 48), Pair(12, 31), Pair(13, 11), Pair(-39, 18), Pair(-82, 27),
        Pair(-3, -12), Pair(20, 9), Pair(61, 19), Pair(-12, 32), Pair(-4, 13), Pair(-43, 25), Pair(-38, 16), Pair(-25, 4),
        Pair(75, -18), Pair(41, -1), Pair(32, 14), Pair(4, 23), Pair(-8, 14), Pair(-33, 20), Pair(-25, 5), Pair(-20, -7),
        Pair(35, -40), Pair(74, -24), Pair(32, -9), Pair(-9, 12), Pair(2, -6), Pair(-27, 8), Pair(-17, -4), Pair(-27, -2)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 49), Pair(42, -20), Pair(-36, 25), Pair(-46, 11), Pair(14, 4), Pair(65, -46), Pair(-29, 11), Pair(-47, 43),
        Pair(6, 31), Pair(2, 31), Pair(0, 30), Pair(-9, 11), Pair(-9, 28), Pair(2, 12), Pair(17, 10), Pair(-15, 22),
        Pair(-6, 22), Pair(3, -5), Pair(13, 14), Pair(2, 6), Pair(5, 10), Pair(1, 10), Pair(-1, 13), Pair(-3, 13),
        Pair(-12, 5), Pair(6, 18), Pair(-4, 8), Pair(-5, 2), Pair(-2, 23), Pair(12, 7), Pair(-2, 14), Pair(-6, 28),
        Pair(9, 16), Pair(-2, 36), Pair(17, 20), Pair(-4, 17), Pair(0, 22), Pair(3, 13), Pair(3, 17), Pair(-5, 22),
        Pair(-11, 27), Pair(5, 33), Pair(0, 25), Pair(-11, 21), Pair(-3, 29), Pair(5, 18), Pair(-1, 23), Pair(-3, 23),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-16, 1), Pair(67, 41), Pair(-68, 68), Pair(80, 53), Pair(-107, 92), Pair(14, 33), Pair(-50, 34), Pair(-112, 111),
        Pair(-5, 26), Pair(0, 91), Pair(12, 79), Pair(-4, 69), Pair(96, 24), Pair(-21, 87), Pair(3, 19), Pair(-35, 68),
        Pair(-80, 85), Pair(10, 61), Pair(34, 71), Pair(37, 76), Pair(44, 45), Pair(63, 56), Pair(-11, 72), Pair(-6, 29),
        Pair(20, 30), Pair(-10, 87), Pair(28, 75), Pair(19, 69), Pair(2, 80), Pair(20, 84), Pair(17, 62), Pair(-16, 54),
        Pair(24, 56), Pair(0, 0), Pair(24, 85), Pair(26, 87), Pair(4, 94), Pair(18, 64), Pair(6, 82), Pair(15, 44),
        Pair(10, 52), Pair(22, 70), Pair(14, 79), Pair(4, 73), Pair(1, 74), Pair(24, 58), Pair(14, 50), Pair(14, 49),
        Pair(-2, 117), Pair(25, 44), Pair(36, 96), Pair(7, 49), Pair(20, 77), Pair(27, 31), Pair(18, 92), Pair(21, 67),
        Pair(-19, 163), Pair(-2, 22), Pair(62, 50), Pair(3, 54), Pair(-9, 90), Pair(-12, 69), Pair(11, 50), Pair(119, -123)
      },
      { // Piece 2
        Pair(61, 86), Pair(-8, 55), Pair(70, 23), Pair(143, 9), Pair(165, -26), Pair(46, 26), Pair(98, 13), Pair(13, -27),
        Pair(-60, 69), Pair(-9, 94), Pair(17, 61), Pair(58, 37), Pair(78, 29), Pair(12, 49), Pair(-58, 45), Pair(37, 5),
        Pair(-31, 107), Pair(-1, 33), Pair(-1, 76), Pair(2, 41), Pair(45, 33), Pair(69, -15), Pair(20, 58), Pair(5, 42),
        Pair(-55, -28), Pair(13, 60), Pair(23, 73), Pair(20, 94), Pair(27, 48), Pair(26, 45), Pair(18, 30), Pair(20, 41),
        Pair(41, 50), Pair(0, 0), Pair(8, 75), Pair(41, 44), Pair(10, 75), Pair(34, 34), Pair(54, 43), Pair(31, 52),
        Pair(-24, 11), Pair(33, 48), Pair(8, 51), Pair(18, 77), Pair(25, 56), Pair(25, 71), Pair(6, 50), Pair(17, 69),
        Pair(-17, 91), Pair(15, 64), Pair(17, 74), Pair(10, 57), Pair(24, 69), Pair(45, 52), Pair(15, 74), Pair(6, 8),
        Pair(16, 3), Pair(26, 50), Pair(3, 49), Pair(22, 42), Pair(31, 46), Pair(12, 59), Pair(25, 38), Pair(1, 54)
      },
      { // Piece 3
        Pair(-70, 124), Pair(34, 38), Pair(7, 116), Pair(10, 97), Pair(-58, 114), Pair(42, 87), Pair(85, 77), Pair(30, 92),
        Pair(7, 110), Pair(-32, 64), Pair(-15, 115), Pair(29, 108), Pair(-54, 121), Pair(38, 85), Pair(24, 94), Pair(-43, 117),
        Pair(-51, 149), Pair(39, 76), Pair(-14, 127), Pair(-9, 135), Pair(52, 89), Pair(41, 105), Pair(104, 93), Pair(0, 111),
        Pair(17, 122), Pair(-48, 85), Pair(5, 133), Pair(3, 124), Pair(6, 113), Pair(-4, 112), Pair(-26, 113), Pair(-18, 113),
        Pair(-20, 102), Pair(0, 0), Pair(-6, 119), Pair(13, 121), Pair(24, 128), Pair(-20, 133), Pair(-24, 122), Pair(-21, 121),
        Pair(-3, 131), Pair(2, 55), Pair(4, 112), Pair(1, 118), Pair(-18, 114), Pair(5, 91), Pair(-10, 106), Pair(-20, 118),
        Pair(-10, 136), Pair(-20, 42), Pair(-8, 121), Pair(11, 122), Pair(-28, 128), Pair(2, 130), Pair(0, 102), Pair(-2, 87),
        Pair(-13, 117), Pair(-6, 48), Pair(-2, 112), Pair(-1, 115), Pair(-1, 114), Pair(-1, 105), Pair(1, 116), Pair(-1, 89)
      },
      { // Piece 4
        Pair(45, 127), Pair(-13, 184), Pair(65, 95), Pair(11, 189), Pair(-72, 250), Pair(53, 104), Pair(-163, 205), Pair(9, 167),
        Pair(3, 186), Pair(18, 122), Pair(32, 119), Pair(8, 218), Pair(-12, 185), Pair(-22, 170), Pair(8, 110), Pair(-14, 242),
        Pair(32, 128), Pair(-5, 106), Pair(28, 212), Pair(44, 186), Pair(24, 178), Pair(52, 126), Pair(25, 126), Pair(7, 134),
        Pair(6, 227), Pair(17, 112), Pair(8, 197), Pair(22, 205), Pair(-25, 256), Pair(50, 148), Pair(23, 159), Pair(10, 165),
        Pair(6, 180), Pair(0, 0), Pair(43, 167), Pair(12, 173), Pair(40, 185), Pair(6, 214), Pair(41, 153), Pair(42, 101),
        Pair(29, 46), Pair(36, 129), Pair(45, 142), Pair(40, 181), Pair(25, 179), Pair(38, 159), Pair(14, 162), Pair(9, 144),
        Pair(58, 96), Pair(48, 69), Pair(26, 157), Pair(33, 152), Pair(27, 183), Pair(34, 111), Pair(42, 155), Pair(38, 114),
        Pair(19, 172), Pair(32, 90), Pair(2, 173), Pair(24, 144), Pair(23, 178), Pair(-3, 196), Pair(7, 111), Pair(-10, 68)
      },
      { // Piece 5
        Pair(-22, 73), Pair(69, 21), Pair(42, 152), Pair(166, -12), Pair(78, 16), Pair(-3, -5), Pair(-68, -1), Pair(24, -37),
        Pair(-16, 91), Pair(2, 128), Pair(156, 25), Pair(97, 26), Pair(103, -18), Pair(2, 36), Pair(-104, 2), Pair(34, -49),
        Pair(21, 80), Pair(129, 55), Pair(190, 86), Pair(35, 68), Pair(13, 50), Pair(-11, -7), Pair(-58, 61), Pair(-14, 13),
        Pair(251, -22), Pair(137, -5), Pair(-33, 49), Pair(-84, 72), Pair(-17, 50), Pair(-5, 31), Pair(-5, 24), Pair(-112, 58),
        Pair(-30, 51), Pair(0, 0), Pair(62, 37), Pair(-5, 43), Pair(-35, 54), Pair(-28, 37), Pair(-64, 46), Pair(-16, 22),
        Pair(74, -5), Pair(81, 3), Pair(8, 11), Pair(30, 16), Pair(-38, 33), Pair(-19, 14), Pair(-4, 23), Pair(-28, -7),
        Pair(54, 25), Pair(67, 5), Pair(27, 28), Pair(1, 19), Pair(8, 1), Pair(-16, 5), Pair(-21, 9), Pair(-24, 3),
        Pair(44, -62), Pair(83, -12), Pair(40, -3), Pair(12, -5), Pair(0, 4), Pair(-9, 8), Pair(-13, 6), Pair(-13, -22)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-33, 43), Pair(-29, 46), Pair(-36, 19), Pair(-24, 61), Pair(-42, 24), Pair(55, -9), Pair(10, -5), Pair(-68, 63),
        Pair(-4, 20), Pair(-8, 44), Pair(15, 14), Pair(-14, 45), Pair(7, 12), Pair(6, 0), Pair(3, 0), Pair(-19, 15),
        Pair(3, 0), Pair(3, 20), Pair(-15, -4), Pair(6, 26), Pair(-8, 11), Pair(6, 9), Pair(1, 13), Pair(-9, 15),
        Pair(-3, 5), Pair(-4, 7), Pair(6, -5), Pair(-1, 23), Pair(0, 0), Pair(6, 15), Pair(2, 17), Pair(-1, 17),
        Pair(8, -1), Pair(13, 16), Pair(-11, -6), Pair(8, 29), Pair(2, 12), Pair(2, 14), Pair(5, 10), Pair(1, 15),
        Pair(4, 8), Pair(5, 23), Pair(-5, 8), Pair(2, 31), Pair(-1, 26), Pair(3, 25), Pair(0, 18), Pair(-1, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-122, 132), Pair(-15, 28), Pair(-119, 111), Pair(-77, 83), Pair(44, 67), Pair(59, 110), Pair(-29, 49), Pair(-57, -4),
        Pair(7, 119), Pair(-82, 88), Pair(-32, 110), Pair(-46, 99), Pair(8, 74), Pair(-10, 37), Pair(-8, 156), Pair(24, 76),
        Pair(-18, 81), Pair(7, 51), Pair(-18, 39), Pair(-34, 90), Pair(-7, 103), Pair(27, 85), Pair(-29, 100), Pair(-16, 44),
        Pair(-40, 68), Pair(-17, 93), Pair(-36, 97), Pair(-5, 101), Pair(-6, 74), Pair(10, 82), Pair(-3, 79), Pair(-21, 79),
        Pair(-7, 101), Pair(8, 79), Pair(0, 0), Pair(-8, 80), Pair(1, 93), Pair(-12, 106), Pair(2, 86), Pair(4, 80),
        Pair(-5, 33), Pair(4, 94), Pair(4, 72), Pair(3, 103), Pair(17, 64), Pair(-2, 86), Pair(1, 97), Pair(2, 79),
        Pair(7, 138), Pair(-61, 69), Pair(17, 61), Pair(-2, 77), Pair(-4, 96), Pair(29, 97), Pair(16, 37), Pair(13, 60),
        Pair(15, 55), Pair(-1, 42), Pair(25, 65), Pair(23, 45), Pair(-6, 73), Pair(18, 70), Pair(-2, 85), Pair(55, 63)
      },
      { // Piece 2
        Pair(33, 42), Pair(-43, 52), Pair(62, 18), Pair(-56, 95), Pair(-6, -3), Pair(-113, 97), Pair(-101, 24), Pair(-6, 114),
        Pair(8, 69), Pair(19, 26), Pair(-5, 64), Pair(86, -3), Pair(23, 70), Pair(9, 19), Pair(-49, 79), Pair(-40, 44),
        Pair(-34, 64), Pair(-12, 63), Pair(-3, 42), Pair(39, 75), Pair(-15, 43), Pair(-17, 64), Pair(21, 12), Pair(-7, 81),
        Pair(-14, 60), Pair(-35, 77), Pair(21, 64), Pair(61, -34), Pair(-11, 92), Pair(22, 22), Pair(9, 63), Pair(0, 20),
        Pair(-17, 20), Pair(-8, 82), Pair(0, 0), Pair(16, 78), Pair(7, 58), Pair(6, 73), Pair(23, 11), Pair(6, 97),
        Pair(-9, 82), Pair(-18, -1), Pair(25, 76), Pair(-13, 55), Pair(6, 68), Pair(5, 35), Pair(9, 76), Pair(1, 38),
        Pair(-50, 17), Pair(9, 74), Pair(16, 10), Pair(-2, 81), Pair(-1, 45), Pair(20, 53), Pair(-1, 55), Pair(-3, 62),
        Pair(23, 89), Pair(6, 20), Pair(1, 54), Pair(7, 13), Pair(-1, 68), Pair(-11, 47), Pair(71, 50), Pair(18, 59)
      },
      { // Piece 3
        Pair(-57, 148), Pair(-55, 115), Pair(107, 24), Pair(43, 76), Pair(3, 93), Pair(47, 81), Pair(0, 97), Pair(29, 95),
        Pair(-39, 124), Pair(-28, 122), Pair(-41, 83), Pair(-97, 155), Pair(-50, 125), Pair(-42, 118), Pair(9, 104), Pair(5, 107),
        Pair(-51, 124), Pair(-37, 122), Pair(-26, 74), Pair(-76, 131), Pair(-56, 113), Pair(-4, 98), Pair(-4, 117), Pair(9, 88),
        Pair(-23, 108), Pair(0, 117), Pair(-29, 83), Pair(-21, 137), Pair(-23, 105), Pair(-7, 84), Pair(-10, 98), Pair(-15, 91),
        Pair(1, 74), Pair(17, 38), Pair(0, 0), Pair(-35, 127), Pair(-15, 119), Pair(-17, 103), Pair(14, 78), Pair(5, 71),
        Pair(-22, 126), Pair(-10, 107), Pair(-31, 91), Pair(8, 110), Pair(-10, 113), Pair(-21, 108), Pair(16, 73), Pair(-21, 133),
        Pair(15, 110), Pair(-19, 114), Pair(-3, 55), Pair(-31, 109), Pair(-14, 115), Pair(-6, 116), Pair(21, 79), Pair(17, 103),
        Pair(-21, 103), Pair(-23, 120), Pair(-4, 30), Pair(-28, 108), Pair(-21, 109), Pair(-10, 103), Pair(-4, 101), Pair(3, 76)
      },
      { // Piece 4
        Pair(5, 126), Pair(-1, 176), Pair(0, 147), Pair(-5, 154), Pair(-17, 217), Pair(-18, 198), Pair(64, 122), Pair(-24, 176),
        Pair(-4, 146), Pair(-17, 139), Pair(-20, 131), Pair(17, 129), Pair(-11, 88), Pair(26, 170), Pair(-4, 106), Pair(-4, 185),
        Pair(21, 93), Pair(-16, 108), Pair(38, 78), Pair(-14, 142), Pair(-21, 127), Pair(31, 240), Pair(-26, 140), Pair(-8, 134),
        Pair(41, 90), Pair(5, 133), Pair(6, 96), Pair(0, 156), Pair(-34, 188), Pair(19, 125), Pair(8, 152), Pair(5, 128),
        Pair(-4, 81), Pair(-11, 74), Pair(0, 0), Pair(10, 150), Pair(14, 130), Pair(28, 113), Pair(-4, 141), Pair(4, 154),
        Pair(3, 73), Pair(-3, 113), Pair(-4, 121), Pair(25, 137), Pair(8, 130), Pair(-3, 163), Pair(2, 164), Pair(26, 93),
        Pair(16, -5), Pair(21, 72), Pair(8, 84), Pair(11, 133), Pair(10, 110), Pair(24, 136), Pair(40, 62), Pair(44, 117),
        Pair(3, 120), Pair(15, 158), Pair(14, 51), Pair(4, 112), Pair(8, 180), Pair(29, 132), Pair(10, 132), Pair(39, 19)
      },
      { // Piece 5
        Pair(3, -60), Pair(6, 50), Pair(2, 15), Pair(110, 50), Pair(137, 80), Pair(-53, 42), Pair(18, -76), Pair(15, 130),
        Pair(37, -8), Pair(50, 45), Pair(-10, 79), Pair(83, 47), Pair(180, 34), Pair(62, -27), Pair(81, 5), Pair(-101, 106),
        Pair(5, 4), Pair(-31, 104), Pair(94, 55), Pair(95, 84), Pair(105, 3), Pair(69, 45), Pair(220, -18), Pair(34, 8),
        Pair(161, 7), Pair(-29, 16), Pair(70, 5), Pair(58, 9), Pair(-95, 90), Pair(94, -3), Pair(101, 21), Pair(-11, -2),
        Pair(-12, 69), Pair(28, 35), Pair(0, 0), Pair(-14, 39), Pair(-18, 32), Pair(17, 27), Pair(21, -5), Pair(-51, 24),
        Pair(127, -20), Pair(-9, 25), Pair(-55, 47), Pair(-7, 22), Pair(-25, 26), Pair(-30, 15), Pair(-47, 11), Pair(-26, 7),
        Pair(27, 4), Pair(-32, 22), Pair(19, -4), Pair(13, 5), Pair(8, 7), Pair(-8, 5), Pair(-6, -8), Pair(-14, -4),
        Pair(17, -12), Pair(15, -4), Pair(17, -15), Pair(9, -12), Pair(-2, -20), Pair(-24, -5), Pair(-8, -22), Pair(-10, -17)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 13), Pair(22, 38), Pair(-47, 18), Pair(-8, -22), Pair(-52, 55), Pair(17, -9), Pair(-34, 14), Pair(-9, 11),
        Pair(-8, 15), Pair(-2, 15), Pair(-12, 46), Pair(1, -4), Pair(-4, 33), Pair(29, 17), Pair(8, 3), Pair(-7, 20),
        Pair(4, 7), Pair(1, 8), Pair(11, 32), Pair(-4, -7), Pair(9, 29), Pair(1, 7), Pair(-1, 18), Pair(-5, 12),
        Pair(3, 14), Pair(-4, 5), Pair(0, 18), Pair(8, -22), Pair(-1, 22), Pair(-1, 2), Pair(1, 14), Pair(-4, 18),
        Pair(4, 9), Pair(-7, 15), Pair(16, 32), Pair(12, -27), Pair(15, 31), Pair(-2, 11), Pair(4, 17), Pair(-1, 19),
        Pair(7, 12), Pair(1, 23), Pair(7, 27), Pair(-2, 7), Pair(10, 27), Pair(-2, 17), Pair(7, 13), Pair(2, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, -47), Pair(-36, 67), Pair(76, 56), Pair(-106, 121), Pair(57, 90), Pair(-22, 138), Pair(-50, 76), Pair(8, 69),
        Pair(0, 5), Pair(-3, 92), Pair(36, 82), Pair(38, 88), Pair(55, 75), Pair(43, 80), Pair(-63, 73), Pair(-8, 127),
        Pair(6, 135), Pair(-24, 123), Pair(-28, 65), Pair(-6, 86), Pair(-17, 94), Pair(-13, 113), Pair(7, 105), Pair(-23, 132),
        Pair(-40, 87), Pair(-2, 76), Pair(27, 90), Pair(-8, 68), Pair(-2, 92), Pair(0, 80), Pair(10, 77), Pair(-11, 75),
        Pair(2, 85), Pair(-25, 108), Pair(6, 84), Pair(0, 0), Pair(1, 87), Pair(6, 88), Pair(23, 81), Pair(8, 94),
        Pair(9, 78), Pair(-1, 70), Pair(16, 90), Pair(19, 75), Pair(29, 86), Pair(13, 60), Pair(8, 57), Pair(11, 62),
        Pair(41, 119), Pair(-24, 114), Pair(19, 44), Pair(20, 65), Pair(10, 77), Pair(10, 71), Pair(10, 81), Pair(27, 24),
        Pair(-7, 47), Pair(18, 47), Pair(3, 76), Pair(18, 73), Pair(4, 48), Pair(9, 77), Pair(13, 54), Pair(-3, -28)
      },
      { // Piece 2
        Pair(30, 35), Pair(57, 14), Pair(-21, 61), Pair(13, 19), Pair(187, -4), Pair(66, 13), Pair(44, 56), Pair(4, 74),
        Pair(-124, 61), Pair(11, 89), Pair(39, 33), Pair(18, 41), Pair(25, 26), Pair(61, 18), Pair(-28, 22), Pair(4, 14),
        Pair(30, 48), Pair(-28, 14), Pair(28, 64), Pair(-2, 46), Pair(35, 54), Pair(-16, 23), Pair(8, 71), Pair(7, 52),
        Pair(-19, 48), Pair(7, 57), Pair(-52, 51), Pair(6, 45), Pair(1, 53), Pair(27, 61), Pair(-6, 33), Pair(26, 43),
        Pair(9, 37), Pair(-37, 31), Pair(12, 75), Pair(0, 0), Pair(23, 88), Pair(-11, 22), Pair(-1, 56), Pair(-13, 33),
        Pair(-17, 18), Pair(23, 78), Pair(-31, -9), Pair(21, 80), Pair(-10, 26), Pair(18, 75), Pair(3, 44), Pair(6, 59),
        Pair(55, 85), Pair(-28, -19), Pair(-1, 87), Pair(1, 28), Pair(14, 55), Pair(-18, 28), Pair(4, 87), Pair(12, 15),
        Pair(-41, -1), Pair(35, 43), Pair(-13, 30), Pair(55, 42), Pair(-21, 38), Pair(9, 66), Pair(-62, 58), Pair(15, 60)
      },
      { // Piece 3
        Pair(-32, 141), Pair(-41, 113), Pair(15, 95), Pair(91, 31), Pair(-5, 118), Pair(-11, 111), Pair(40, 111), Pair(9, 99),
        Pair(-13, 134), Pair(-16, 124), Pair(-42, 122), Pair(51, 49), Pair(-60, 102), Pair(-58, 110), Pair(-20, 85), Pair(-8, 105),
        Pair(-5, 103), Pair(-25, 117), Pair(-29, 109), Pair(17, 44), Pair(-40, 118), Pair(-43, 121), Pair(32, 100), Pair(15, 81),
        Pair(-4, 87), Pair(-5, 101), Pair(39, 88), Pair(-10, 71), Pair(16, 102), Pair(-17, 108), Pair(-12, 92), Pair(22, 93),
        Pair(6, 112), Pair(-7, 95), Pair(-18, 99), Pair(0, 0), Pair(-36, 116), Pair(-10, 87), Pair(-12, 100), Pair(-29, 118),
        Pair(-1, 105), Pair(16, 78), Pair(4, 110), Pair(14, 54), Pair(-18, 118), Pair(-13, 69), Pair(7, 84), Pair(-2, 123),
        Pair(2, 99), Pair(-20, 119), Pair(3, 100), Pair(45, 32), Pair(-2, 111), Pair(-13, 104), Pair(27, 86), Pair(9, 62),
        Pair(2, 90), Pair(-6, 113), Pair(-16, 115), Pair(35, 23), Pair(-10, 101), Pair(-2, 93), Pair(6, 92), Pair(13, 93)
      },
      { // Piece 4
        Pair(58, 137), Pair(55, 59), Pair(4, 157), Pair(85, 112), Pair(-106, 259), Pair(-39, 200), Pair(74, 128), Pair(47, 54),
        Pair(-46, 206), Pair(-27, 193), Pair(-36, 213), Pair(-7, 155), Pair(-18, 219), Pair(-7, 171), Pair(13, 233), Pair(-36, 216),
        Pair(6, 185), Pair(-16, 178), Pair(-45, 234), Pair(-14, 125), Pair(0, 165), Pair(4, 130), Pair(-12, 205), Pair(11, 178),
        Pair(8, 179), Pair(11, 154), Pair(-4, 153), Pair(32, 97), Pair(5, 166), Pair(-11, 191), Pair(-9, 191), Pair(9, 148),
        Pair(4, 95), Pair(0, 144), Pair(7, 127), Pair(0, 0), Pair(0, 121), Pair(0, 151), Pair(23, 130), Pair(21, 108),
        Pair(10, 60), Pair(15, 124), Pair(1, 161), Pair(34, 69), Pair(23, 112), Pair(13, 165), Pair(-1, 200), Pair(-32, 262),
        Pair(16, 153), Pair(25, 84), Pair(4, 162), Pair(18, 89), Pair(7, 119), Pair(13, 152), Pair(6, 151), Pair(31, 65),
        Pair(-26, 134), Pair(40, 82), Pair(2, 152), Pair(16, 100), Pair(7, 129), Pair(25, 95), Pair(-31, 109), Pair(62, 119)
      },
      { // Piece 5
        Pair(-25, 49), Pair(40, 58), Pair(50, 37), Pair(-44, 96), Pair(-25, 56), Pair(75, 29), Pair(31, 20), Pair(102, 101),
        Pair(-50, -8), Pair(13, 56), Pair(134, 65), Pair(149, 46), Pair(-7, 11), Pair(96, 27), Pair(37, 104), Pair(50, 59),
        Pair(-101, 46), Pair(165, 27), Pair(123, 75), Pair(-43, 69), Pair(-16, 84), Pair(-15, 58), Pair(32, 33), Pair(62, 10),
        Pair(-134, 27), Pair(30, 23), Pair(22, 38), Pair(-63, 45), Pair(-120, 63), Pair(-92, 54), Pair(-51, 60), Pair(-31, 4),
        Pair(119, -24), Pair(117, -16), Pair(-29, 50), Pair(0, 0), Pair(-14, 31), Pair(-61, 47), Pair(-59, 17), Pair(-163, 65),
        Pair(15, -3), Pair(-8, 0), Pair(-43, 21), Pair(-65, 44), Pair(-48, 19), Pair(-6, 0), Pair(27, -6), Pair(-7, -24),
        Pair(13, -22), Pair(3, -18), Pair(-11, 4), Pair(-62, 13), Pair(-24, 8), Pair(18, -18), Pair(12, -25), Pair(-4, -18),
        Pair(-5, -4), Pair(-14, 8), Pair(-9, -4), Pair(-29, -28), Pair(4, -49), Pair(1, -36), Pair(5, -32), Pair(-7, -47)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 15), Pair(-23, 29), Pair(-35, 47), Pair(85, -16), Pair(17, -17), Pair(-37, 14), Pair(19, 13), Pair(17, 15),
        Pair(-3, 29), Pair(-28, 32), Pair(31, 13), Pair(-20, 47), Pair(5, -10), Pair(17, 24), Pair(5, -5), Pair(-8, 13),
        Pair(-6, 16), Pair(-2, 7), Pair(-2, 8), Pair(4, 38), Pair(-10, -10), Pair(15, 28), Pair(1, 4), Pair(-2, 8),
        Pair(-2, 16), Pair(0, 20), Pair(-3, 2), Pair(-3, 22), Pair(-2, -8), Pair(9, 14), Pair(-5, 0), Pair(-4, 12),
        Pair(1, 15), Pair(5, 10), Pair(0, 10), Pair(16, 24), Pair(-2, -5), Pair(19, 20), Pair(-5, 0), Pair(3, 13),
        Pair(2, 21), Pair(7, 14), Pair(3, 8), Pair(12, 28), Pair(-5, 10), Pair(9, 38), Pair(0, 10), Pair(4, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-2, 75), Pair(26, 5), Pair(-34, 112), Pair(20, 57), Pair(73, 33), Pair(-67, 64), Pair(-69, 103), Pair(-21, 9),
        Pair(-27, 47), Pair(-139, 103), Pair(28, 80), Pair(-79, 85), Pair(-24, 108), Pair(48, 26), Pair(68, 40), Pair(24, -24),
        Pair(-35, 67), Pair(-19, 107), Pair(-36, 105), Pair(2, 57), Pair(17, 68), Pair(16, 47), Pair(9, 60), Pair(-11, 130),
        Pair(-21, 68), Pair(0, 61), Pair(-9, 84), Pair(1, 80), Pair(-28, 50), Pair(7, 53), Pair(-4, 44), Pair(0, 80),
        Pair(0, 66), Pair(8, 95), Pair(9, 67), Pair(3, 56), Pair(0, 0), Pair(-7, 100), Pair(9, 73), Pair(5, 88),
        Pair(8, 45), Pair(-13, 80), Pair(2, 38), Pair(29, 77), Pair(16, 97), Pair(12, 62), Pair(2, 37), Pair(14, 46),
        Pair(19, 69), Pair(16, 67), Pair(-1, 71), Pair(7, 54), Pair(2, 69), Pair(19, 46), Pair(-26, 76), Pair(37, 98),
        Pair(94, 15), Pair(7, 55), Pair(46, 29), Pair(32, 69), Pair(-11, 76), Pair(1, 77), Pair(7, 62), Pair(32, 93)
      },
      { // Piece 2
        Pair(199, -32), Pair(-32, -6), Pair(46, -41), Pair(91, -12), Pair(142, -20), Pair(94, 26), Pair(-88, 42), Pair(51, 36),
        Pair(25, 32), Pair(11, -11), Pair(52, 26), Pair(51, -13), Pair(73, -24), Pair(5, -8), Pair(62, 46), Pair(-108, 49),
        Pair(-14, 38), Pair(-4, 58), Pair(-34, 4), Pair(33, 50), Pair(50, 4), Pair(72, 14), Pair(-2, -2), Pair(21, 50),
        Pair(17, 44), Pair(-8, 15), Pair(28, 58), Pair(12, -45), Pair(-13, 53), Pair(77, -8), Pair(6, 45), Pair(-15, -7),
        Pair(-4, 14), Pair(-1, 59), Pair(-21, 31), Pair(8, 68), Pair(0, 0), Pair(8, 57), Pair(22, 0), Pair(25, 78),
        Pair(6, 66), Pair(-4, 41), Pair(7, 46), Pair(-28, 33), Pair(21, 63), Pair(-25, -8), Pair(8, 75), Pair(-19, 35),
        Pair(31, 46), Pair(5, 59), Pair(-31, 24), Pair(1, 42), Pair(0, 22), Pair(3, 83), Pair(-37, -15), Pair(13, 51),
        Pair(43, 1), Pair(-35, 35), Pair(3, 41), Pair(-24, 33), Pair(15, 59), Pair(-17, 30), Pair(77, 20), Pair(-42, 1)
      },
      { // Piece 3
        Pair(-8, 88), Pair(63, 51), Pair(29, 75), Pair(-35, 79), Pair(32, 27), Pair(107, 27), Pair(-54, 100), Pair(29, 55),
        Pair(5, 83), Pair(-41, 86), Pair(0, 76), Pair(16, 60), Pair(87, 24), Pair(11, 64), Pair(-34, 117), Pair(-3, 76),
        Pair(-1, 60), Pair(-37, 84), Pair(44, 64), Pair(-6, 69), Pair(119, 14), Pair(33, 29), Pair(-49, 91), Pair(-4, 77),
        Pair(-4, 73), Pair(-18, 67), Pair(-14, 79), Pair(0, 102), Pair(52, 34), Pair(-16, 101), Pair(-24, 91), Pair(15, 68),
        Pair(0, 69), Pair(9, 52), Pair(-11, 65), Pair(-27, 64), Pair(0, 0), Pair(-19, 44), Pair(-4, 73), Pair(1, 64),
        Pair(-4, 65), Pair(-20, 87), Pair(0, 82), Pair(8, 56), Pair(37, 5), Pair(4, 68), Pair(-4, 56), Pair(-9, 71),
        Pair(17, 96), Pair(25, 57), Pair(-4, 88), Pair(12, 44), Pair(46, 4), Pair(8, 50), Pair(-6, 69), Pair(8, 71),
        Pair(0, 67), Pair(-1, 70), Pair(-6, 73), Pair(-15, 77), Pair(42, -16), Pair(-9, 65), Pair(5, 74), Pair(14, 67)
      },
      { // Piece 4
        Pair(40, -11), Pair(109, 61), Pair(54, 79), Pair(43, 95), Pair(61, 86), Pair(-66, 216), Pair(2, 102), Pair(-21, 190),
        Pair(-2, 120), Pair(29, 51), Pair(10, 136), Pair(18, 92), Pair(-61, 186), Pair(-52, 168), Pair(40, 66), Pair(-18, 93),
        Pair(4, 125), Pair(17, 86), Pair(1, 85), Pair(-46, 215), Pair(32, 87), Pair(32, 178), Pair(25, 137), Pair(18, 193),
        Pair(40, 103), Pair(9, 130), Pair(4, 161), Pair(11, 132), Pair(4, 132), Pair(11, 155), Pair(16, 156), Pair(17, 62),
        Pair(18, 91), Pair(23, 34), Pair(18, 124), Pair(-5, 160), Pair(0, 0), Pair(-8, 121), Pair(5, 178), Pair(1, 109),
        Pair(25, 109), Pair(23, 120), Pair(2, 146), Pair(10, 121), Pair(18, 109), Pair(11, 86), Pair(22, 135), Pair(9, 156),
        Pair(43, 122), Pair(33, 115), Pair(26, 47), Pair(14, 140), Pair(11, 79), Pair(14, 154), Pair(9, 82), Pair(33, 169),
        Pair(58, 76), Pair(21, 93), Pair(18, 132), Pair(12, 135), Pair(1, 126), Pair(45, 93), Pair(-70, 262), Pair(-23, 234)
      },
      { // Piece 5
        Pair(-83, 8), Pair(-116, 2), Pair(6, 74), Pair(-139, 3), Pair(112, -30), Pair(98, 5), Pair(44, 17), Pair(126, 28),
        Pair(-30, 9), Pair(-33, 70), Pair(-76, 61), Pair(-62, 81), Pair(65, 15), Pair(32, 31), Pair(114, 61), Pair(133, 28),
        Pair(88, -7), Pair(-45, 26), Pair(-29, 44), Pair(-80, 105), Pair(-29, 89), Pair(-170, 120), Pair(72, 55), Pair(-135, 68),
        Pair(-201, 75), Pair(-29, 9), Pair(-46, 41), Pair(-125, 38), Pair(98, 5), Pair(46, 10), Pair(98, 9), Pair(-50, 46),
        Pair(-209, 77), Pair(-62, 29), Pair(-83, 55), Pair(2, 20), Pair(0, 0), Pair(-13, 26), Pair(-5, 25), Pair(-47, 28),
        Pair(-84, 20), Pair(19, -2), Pair(-20, 18), Pair(-37, 2), Pair(-77, 41), Pair(-46, 21), Pair(45, -14), Pair(-13, 6),
        Pair(30, -18), Pair(-18, -1), Pair(14, -10), Pair(-13, 10), Pair(-50, 17), Pair(-16, 10), Pair(1, -5), Pair(13, -12),
        Pair(-15, 13), Pair(-20, -16), Pair(-9, -21), Pair(3, -11), Pair(-16, -26), Pair(9, -18), Pair(7, -33), Pair(17, -46)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 50), Pair(-14, -4), Pair(-17, 28), Pair(20, 3), Pair(-38, 62), Pair(45, -62), Pair(-24, 29), Pair(18, 4),
        Pair(-14, 19), Pair(-17, 29), Pair(3, 18), Pair(-7, 27), Pair(-20, 49), Pair(-4, 4), Pair(-9, 37), Pair(7, -8),
        Pair(4, 11), Pair(0, 8), Pair(5, 17), Pair(6, 8), Pair(12, 22), Pair(-16, -11), Pair(8, 14), Pair(3, -10),
        Pair(1, 14), Pair(15, 5), Pair(6, 15), Pair(-1, 4), Pair(7, 14), Pair(-8, -10), Pair(5, 2), Pair(-1, -10),
        Pair(4, 12), Pair(4, 11), Pair(5, 12), Pair(1, 13), Pair(25, 19), Pair(-11, -3), Pair(17, 9), Pair(-3, 3),
        Pair(7, 18), Pair(10, 7), Pair(4, 13), Pair(1, 12), Pair(19, 32), Pair(5, 7), Pair(8, 25), Pair(-5, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-2, 47), Pair(-82, 114), Pair(-127, -6), Pair(39, 38), Pair(-35, 71), Pair(26, 72), Pair(-114, 86), Pair(-63, 128),
        Pair(-31, -8), Pair(-4, 41), Pair(-39, 64), Pair(-12, 60), Pair(-9, 69), Pair(-14, 59), Pair(-59, 92), Pair(-62, 89),
        Pair(-57, 69), Pair(-2, 47), Pair(-7, 80), Pair(0, 63), Pair(-28, 65), Pair(-31, 71), Pair(-40, 78), Pair(-33, 56),
        Pair(24, 16), Pair(-3, 43), Pair(-5, 65), Pair(-2, 58), Pair(28, 40), Pair(-31, 55), Pair(11, 52), Pair(-10, 48),
        Pair(-7, 61), Pair(-10, 57), Pair(3, 57), Pair(29, 45), Pair(4, 62), Pair(0, 0), Pair(-2, 98), Pair(7, 45),
        Pair(9, 19), Pair(5, 51), Pair(-1, 65), Pair(18, 47), Pair(15, 96), Pair(22, 48), Pair(14, 98), Pair(11, -44),
        Pair(-16, 34), Pair(-11, 92), Pair(4, 64), Pair(2, 51), Pair(3, 63), Pair(14, 42), Pair(-4, 89), Pair(14, 72),
        Pair(-4, 3), Pair(2, 39), Pair(-35, 85), Pair(1, 98), Pair(-44, 76), Pair(-17, 86), Pair(3, 9), Pair(-5, 129)
      },
      { // Piece 2
        Pair(-37, 73), Pair(30, 1), Pair(150, -17), Pair(104, -28), Pair(75, 27), Pair(-128, 21), Pair(83, 15), Pair(100, -59),
        Pair(-53, 33), Pair(34, 26), Pair(48, -16), Pair(63, 10), Pair(111, -30), Pair(84, -28), Pair(27, -5), Pair(-22, 47),
        Pair(4, 36), Pair(67, -42), Pair(0, 40), Pair(3, -8), Pair(50, 35), Pair(0, -1), Pair(-8, 43), Pair(-18, -1),
        Pair(-15, 21), Pair(5, 58), Pair(-2, 13), Pair(12, 31), Pair(29, 25), Pair(27, 24), Pair(-33, 47), Pair(30, 51),
        Pair(16, 27), Pair(-15, 21), Pair(7, 47), Pair(15, 7), Pair(8, 58), Pair(0, 0), Pair(26, 35), Pair(27, -16),
        Pair(-14, 26), Pair(17, 26), Pair(-4, 28), Pair(19, 45), Pair(-1, 28), Pair(27, 53), Pair(-45, 9), Pair(14, 26),
        Pair(27, 24), Pair(-19, 28), Pair(10, 54), Pair(-20, 12), Pair(28, 38), Pair(1, 24), Pair(14, 34), Pair(-71, 50),
        Pair(-18, 45), Pair(32, 53), Pair(-26, 1), Pair(43, 16), Pair(1, -19), Pair(23, 25), Pair(-3, 40), Pair(10, 31)
      },
      { // Piece 3
        Pair(20, 53), Pair(85, 32), Pair(105, 23), Pair(92, 17), Pair(17, 54), Pair(131, -22), Pair(73, 1), Pair(112, 18),
        Pair(-10, 60), Pair(17, 47), Pair(-1, 52), Pair(53, 44), Pair(-20, 59), Pair(-1, 45), Pair(-7, 68), Pair(-7, 63),
        Pair(-9, 61), Pair(39, 29), Pair(70, 26), Pair(27, 31), Pair(5, 43), Pair(89, -8), Pair(19, 52), Pair(55, 39),
        Pair(43, 50), Pair(21, 39), Pair(15, 45), Pair(6, 51), Pair(27, 60), Pair(23, 44), Pair(52, 44), Pair(11, 50),
        Pair(12, 51), Pair(25, 44), Pair(-8, 44), Pair(-22, 52), Pair(14, 55), Pair(0, 0), Pair(6, 41), Pair(28, 12),
        Pair(15, 61), Pair(12, 49), Pair(29, 49), Pair(-2, 69), Pair(21, 39), Pair(15, 19), Pair(7, 60), Pair(20, 41),
        Pair(19, 60), Pair(25, 59), Pair(14, 56), Pair(-12, 64), Pair(-4, 48), Pair(45, -18), Pair(11, 50), Pair(28, 57),
        Pair(16, 48), Pair(14, 52), Pair(12, 45), Pair(4, 47), Pair(9, 42), Pair(31, -9), Pair(10, 51), Pair(1, 59)
      },
      { // Piece 4
        Pair(40, 110), Pair(-38, 128), Pair(51, 91), Pair(30, 108), Pair(41, 115), Pair(50, 42), Pair(89, 69), Pair(-10, 183),
        Pair(-35, 133), Pair(12, 54), Pair(2, 109), Pair(68, 92), Pair(-11, 105), Pair(0, 78), Pair(-97, 217), Pair(1, 95),
        Pair(1, 135), Pair(31, 92), Pair(14, 111), Pair(8, 103), Pair(35, 80), Pair(-39, 149), Pair(-37, 127), Pair(-24, 141),
        Pair(-16, 146), Pair(13, 108), Pair(-26, 172), Pair(-3, 155), Pair(-24, 141), Pair(11, 84), Pair(-27, 110), Pair(6, 104),
        Pair(-3, 135), Pair(18, 96), Pair(3, 140), Pair(7, 96), Pair(5, 133), Pair(0, 0), Pair(0, 94), Pair(-29, 127),
        Pair(35, 73), Pair(14, 121), Pair(14, 109), Pair(20, 101), Pair(28, 75), Pair(12, 84), Pair(10, 78), Pair(-20, 89),
        Pair(23, 85), Pair(22, 115), Pair(12, 94), Pair(22, 59), Pair(11, 107), Pair(22, 76), Pair(15, 81), Pair(14, 53),
        Pair(40, 84), Pair(10, 137), Pair(28, 112), Pair(12, 149), Pair(13, 87), Pair(-20, 123), Pair(11, 75), Pair(5, 89)
      },
      { // Piece 5
        Pair(-4, -49), Pair(0, 5), Pair(-21, 35), Pair(117, 16), Pair(2, 105), Pair(-30, -28), Pair(-8, 88), Pair(-12, -6),
        Pair(30, 3), Pair(-22, 76), Pair(31, 21), Pair(60, 71), Pair(159, 33), Pair(125, 34), Pair(275, 16), Pair(11, 6),
        Pair(-105, 46), Pair(44, 24), Pair(-103, 61), Pair(-7, 47), Pair(79, 44), Pair(58, 41), Pair(103, 52), Pair(174, 6),
        Pair(-30, 20), Pair(-46, 51), Pair(-29, 23), Pair(-21, 35), Pair(69, -7), Pair(128, -38), Pair(166, -16), Pair(80, -1),
        Pair(-17, 7), Pair(-8, -2), Pair(-58, 33), Pair(11, 22), Pair(3, 15), Pair(0, 0), Pair(38, 18), Pair(87, 15),
        Pair(-69, 32), Pair(-93, 10), Pair(-46, 13), Pair(66, -7), Pair(7, 7), Pair(-23, 20), Pair(13, 8), Pair(39, -4),
        Pair(-34, -9), Pair(-41, -1), Pair(-11, -12), Pair(-20, -6), Pair(-4, 18), Pair(-37, 14), Pair(-14, 12), Pair(18, -10),
        Pair(-57, -29), Pair(-9, -32), Pair(-25, -6), Pair(13, -41), Pair(-4, -23), Pair(-6, -18), Pair(-7, -11), Pair(1, -37)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-69, 33), Pair(-34, 20), Pair(1, 10), Pair(61, -23), Pair(9, -10), Pair(-60, 30), Pair(-37, -42), Pair(-39, 41),
        Pair(12, 12), Pair(14, 7), Pair(-9, 31), Pair(7, 10), Pair(-21, 24), Pair(-11, 36), Pair(35, -21), Pair(1, 35),
        Pair(-2, 10), Pair(2, 19), Pair(4, 14), Pair(-2, 6), Pair(-3, 3), Pair(8, 19), Pair(4, -12), Pair(6, 14),
        Pair(-2, 14), Pair(-1, 12), Pair(2, 16), Pair(2, 14), Pair(-6, -1), Pair(4, 3), Pair(4, 7), Pair(0, 4),
        Pair(3, 20), Pair(0, 14), Pair(1, 18), Pair(2, 16), Pair(-4, 12), Pair(20, 12), Pair(12, -8), Pair(17, 17),
        Pair(-1, 22), Pair(9, 9), Pair(-4, 16), Pair(-1, 9), Pair(-2, 13), Pair(3, 35), Pair(14, -1), Pair(2, 34),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-30, 66), Pair(79, 56), Pair(136, 10), Pair(75, 71), Pair(-75, 69), Pair(143, -8), Pair(-1, 9), Pair(153, -18),
        Pair(-41, 84), Pair(-1, 25), Pair(4, 61), Pair(23, 46), Pair(25, 73), Pair(81, 33), Pair(37, 66), Pair(43, 12),
        Pair(-2, 45), Pair(-35, 47), Pair(-20, 50), Pair(3, 46), Pair(-25, 70), Pair(-19, 66), Pair(8, 52), Pair(62, 26),
        Pair(4, 18), Pair(-8, 43), Pair(20, 39), Pair(18, 63), Pair(0, 61), Pair(11, 51), Pair(18, 65), Pair(-30, 8),
        Pair(5, 60), Pair(22, 39), Pair(17, 45), Pair(11, 60), Pair(16, 60), Pair(14, 56), Pair(0, 0), Pair(-1, 123),
        Pair(10, 33), Pair(6, 25), Pair(3, 53), Pair(13, 48), Pair(15, 71), Pair(9, 67), Pair(18, 68), Pair(5, 44),
        Pair(12, 39), Pair(13, 69), Pair(-11, 74), Pair(4, 59), Pair(15, 51), Pair(13, 65), Pair(-11, 56), Pair(-5, 93),
        Pair(79, 85), Pair(-2, 6), Pair(20, 55), Pair(-7, 81), Pair(6, 42), Pair(12, 60), Pair(2, 18), Pair(11, -1)
      },
      { // Piece 2
        Pair(6, 19), Pair(69, 10), Pair(24, -12), Pair(78, -6), Pair(119, -7), Pair(61, 7), Pair(194, -8), Pair(61, -18),
        Pair(-8, 22), Pair(18, -15), Pair(-37, 18), Pair(80, -8), Pair(55, -3), Pair(-58, 38), Pair(8, 46), Pair(40, 8),
        Pair(21, -3), Pair(75, 5), Pair(63, 15), Pair(28, 15), Pair(35, 25), Pair(68, 27), Pair(46, 1), Pair(-28, 48),
        Pair(29, 29), Pair(5, 14), Pair(20, 48), Pair(16, 10), Pair(9, 37), Pair(129, 8), Pair(-30, 56), Pair(-108, -124),
        Pair(-34, 48), Pair(7, 30), Pair(25, 6), Pair(-8, 56), Pair(15, 32), Pair(4, 53), Pair(0, 0), Pair(4, 25),
        Pair(-9, 37), Pair(18, 23), Pair(3, 40), Pair(27, 25), Pair(1, 52), Pair(31, 14), Pair(24, 29), Pair(-25, -66),
        Pair(20, -5), Pair(6, 22), Pair(33, 9), Pair(-9, 32), Pair(21, 21), Pair(11, 46), Pair(20, 42), Pair(-21, 61),
        Pair(3, 42), Pair(66, -9), Pair(-6, 35), Pair(1, 18), Pair(21, 42), Pair(-2, 14), Pair(-96, 52), Pair(-11, 28)
      },
      { // Piece 3
        Pair(45, 44), Pair(-40, 69), Pair(90, 30), Pair(20, 48), Pair(77, 36), Pair(39, 60), Pair(27, 22), Pair(50, 41),
        Pair(-26, 82), Pair(-5, 63), Pair(7, 49), Pair(20, 64), Pair(24, 68), Pair(-33, 58), Pair(22, 45), Pair(-62, 82),
        Pair(-10, 80), Pair(5, 63), Pair(-9, 59), Pair(41, 44), Pair(29, 55), Pair(-13, 82), Pair(-2, 40), Pair(-4, 69),
        Pair(4, 69), Pair(2, 53), Pair(26, 46), Pair(-5, 59), Pair(10, 65), Pair(7, 86), Pair(-24, 51), Pair(-1, 68),
        Pair(32, 37), Pair(11, 43), Pair(-11, 56), Pair(25, 49), Pair(4, 80), Pair(-6, 76), Pair(0, 0), Pair(23, 65),
        Pair(7, 48), Pair(-14, 52), Pair(-43, 67), Pair(27, 45), Pair(-7, 85), Pair(15, 49), Pair(32, 10), Pair(-26, 59),
        Pair(0, 68), Pair(5, 57), Pair(40, 33), Pair(29, 51), Pair(-10, 68), Pair(5, 59), Pair(25, -31), Pair(-6, 33),
        Pair(8, 41), Pair(20, 40), Pair(12, 61), Pair(4, 55), Pair(4, 69), Pair(-4, 67), Pair(19, -11), Pair(-4, 41)
      },
      { // Piece 4
        Pair(-30, 86), Pair(39, 9), Pair(72, -26), Pair(151, -51), Pair(34, 41), Pair(-10, 96), Pair(97, 44), Pair(-39, 15),
        Pair(-53, 92), Pair(-19, 64), Pair(47, 6), Pair(95, 27), Pair(25, 124), Pair(-35, 156), Pair(-62, 88), Pair(37, 4),
        Pair(2, 40), Pair(34, -27), Pair(12, 46), Pair(-3, 83), Pair(-22, 113), Pair(2, 103), Pair(44, 3), Pair(-32, 87),
        Pair(-1, 124), Pair(6, 96), Pair(-44, 119), Pair(17, 104), Pair(2, 129), Pair(29, 52), Pair(40, 60), Pair(-16, -17),
        Pair(19, 56), Pair(29, 43), Pair(19, 68), Pair(28, 51), Pair(21, 68), Pair(28, 36), Pair(0, 0), Pair(-19, 96),
        Pair(69, 6), Pair(11, 34), Pair(5, 62), Pair(23, 88), Pair(28, 31), Pair(37, 25), Pair(10, 82), Pair(-6, 62),
        Pair(-35, 152), Pair(4, 14), Pair(25, 75), Pair(26, 57), Pair(35, 12), Pair(25, 53), Pair(21, -17), Pair(15, 86),
        Pair(27, 14), Pair(11, 100), Pair(21, 45), Pair(23, 36), Pair(31, 23), Pair(-29, 45), Pair(12, -149), Pair(73, -143)
      },
      { // Piece 5
        Pair(-62, 43), Pair(-50, 69), Pair(34, 13), Pair(-11, -4), Pair(19, -24), Pair(115, 117), Pair(24, 133), Pair(37, 147),
        Pair(-125, 34), Pair(33, 19), Pair(37, 18), Pair(89, -28), Pair(24, 49), Pair(139, -1), Pair(99, 89), Pair(-9, 92),
        Pair(-103, 46), Pair(-43, 16), Pair(92, 6), Pair(6, 26), Pair(76, 16), Pair(72, 57), Pair(12, 66), Pair(35, 118),
        Pair(-73, -7), Pair(-107, 60), Pair(-63, 17), Pair(1, 21), Pair(-85, 60), Pair(118, -8), Pair(168, -26), Pair(75, -7),
        Pair(-67, 20), Pair(-101, 21), Pair(-84, 45), Pair(-31, 34), Pair(-54, 28), Pair(63, 9), Pair(0, 0), Pair(6, 1),
        Pair(-139, 25), Pair(-100, 32), Pair(-53, 14), Pair(-27, 24), Pair(26, 17), Pair(-40, 16), Pair(28, 2), Pair(9, -5),
        Pair(-69, 31), Pair(-47, 1), Pair(-53, 23), Pair(-47, 10), Pair(-20, 12), Pair(-14, 10), Pair(7, 0), Pair(-21, 13),
        Pair(-54, 7), Pair(-46, 6), Pair(-38, -2), Pair(-24, 2), Pair(-17, -9), Pair(6, -7), Pair(43, -32), Pair(-21, -22)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 14), Pair(-9, 24), Pair(12, 33), Pair(10, 20), Pair(-11, 19), Pair(-17, 27), Pair(-21, 61), Pair(61, -27),
        Pair(4, 8), Pair(-10, 21), Pair(6, 14), Pair(-15, 23), Pair(-4, -3), Pair(-6, 21), Pair(17, 32), Pair(38, -29),
        Pair(-4, 14), Pair(-4, 24), Pair(3, 16), Pair(-3, 21), Pair(-12, 11), Pair(-10, 3), Pair(10, 19), Pair(-1, -24),
        Pair(1, 14), Pair(-9, 22), Pair(-5, 14), Pair(-3, 26), Pair(-3, 11), Pair(-3, -10), Pair(0, 6), Pair(9, -5),
        Pair(-6, 21), Pair(-3, 15), Pair(-2, 17), Pair(-3, 19), Pair(5, 10), Pair(11, -4), Pair(17, 15), Pair(3, 2),
        Pair(-3, 20), Pair(-3, 19), Pair(-8, 19), Pair(-8, 17), Pair(-6, 13), Pair(5, 10), Pair(3, 31), Pair(0, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(22, 29), Pair(42, 43), Pair(-70, 51), Pair(-6, 3), Pair(-17, 66), Pair(90, 53), Pair(122, -1), Pair(-208, -21),
        Pair(3, 48), Pair(-2, 40), Pair(3, 30), Pair(9, 56), Pair(-18, 51), Pair(21, 49), Pair(-103, 38), Pair(7, 37),
        Pair(-14, 60), Pair(-12, 50), Pair(63, 16), Pair(26, 36), Pair(25, 45), Pair(45, 57), Pair(49, 28), Pair(20, 49),
        Pair(-23, 53), Pair(-8, 46), Pair(-2, 44), Pair(14, 75), Pair(7, 48), Pair(39, 46), Pair(52, 25), Pair(-12, 60),
        Pair(-6, 87), Pair(-15, 67), Pair(18, 34), Pair(16, 57), Pair(12, 51), Pair(15, 74), Pair(45, 34), Pair(0, 0),
        Pair(-2, 21), Pair(16, 53), Pair(5, 50), Pair(-4, 63), Pair(37, 32), Pair(20, 39), Pair(13, 54), Pair(24, 31),
        Pair(2, 27), Pair(17, 68), Pair(6, 34), Pair(9, 33), Pair(12, 55), Pair(14, 16), Pair(16, 41), Pair(14, 42),
        Pair(68, 9), Pair(4, 24), Pair(5, 30), Pair(16, 11), Pair(-18, 54), Pair(-21, 58), Pair(2, 11), Pair(-22, 61)
      },
      { // Piece 2
        Pair(-35, 79), Pair(74, -15), Pair(96, -11), Pair(52, -4), Pair(145, -5), Pair(44, 34), Pair(10, 42), Pair(78, 3),
        Pair(-95, 52), Pair(33, 37), Pair(67, 11), Pair(14, 17), Pair(13, 26), Pair(-43, 42), Pair(11, 15), Pair(5, 52),
        Pair(8, 54), Pair(7, 17), Pair(33, 15), Pair(62, 3), Pair(37, 17), Pair(124, -4), Pair(80, 26), Pair(33, 54),
        Pair(0, 37), Pair(-6, 42), Pair(27, 10), Pair(1, 29), Pair(24, 25), Pair(14, 54), Pair(30, 53), Pair(-4, 43),
        Pair(8, 29), Pair(28, 14), Pair(6, 42), Pair(20, 21), Pair(7, 37), Pair(11, 35), Pair(0, 54), Pair(0, 0),
        Pair(-3, 6), Pair(37, 17), Pair(4, 13), Pair(8, 43), Pair(6, 44), Pair(24, 53), Pair(28, 45), Pair(17, 46),
        Pair(25, 39), Pair(6, 31), Pair(9, 33), Pair(-1, 25), Pair(12, 47), Pair(49, 27), Pair(16, 22), Pair(67, -27),
        Pair(37, 19), Pair(7, -9), Pair(6, 17), Pair(6, 23), Pair(31, 27), Pair(1, 31), Pair(-36, 36), Pair(1, 26)
      },
      { // Piece 3
        Pair(-33, 67), Pair(97, 10), Pair(123, 1), Pair(63, 5), Pair(78, 9), Pair(42, 13), Pair(-80, 49), Pair(17, 1),
        Pair(6, 63), Pair(-18, 78), Pair(37, 52), Pair(3, 51), Pair(21, 44), Pair(-16, 69), Pair(16, 37), Pair(51, 13),
        Pair(-6, 63), Pair(-6, 64), Pair(55, 37), Pair(43, 40), Pair(10, 35), Pair(12, 38), Pair(-33, 63), Pair(-55, 45),
        Pair(23, 51), Pair(30, 51), Pair(41, 30), Pair(24, 40), Pair(2, 56), Pair(20, 70), Pair(16, 67), Pair(-3, 35),
        Pair(2, 69), Pair(75, 30), Pair(48, 37), Pair(29, 41), Pair(46, 43), Pair(-3, 70), Pair(-5, 75), Pair(0, 0),
        Pair(26, 40), Pair(-14, 74), Pair(24, 54), Pair(25, 30), Pair(6, 70), Pair(6, 73), Pair(-28, 67), Pair(-29, 14),
        Pair(-2, 64), Pair(23, 46), Pair(41, 31), Pair(34, 44), Pair(35, 34), Pair(4, 70), Pair(-7, 61), Pair(-46, 3),
        Pair(15, 24), Pair(17, 36), Pair(24, 29), Pair(12, 33), Pair(4, 56), Pair(12, 39), Pair(-1, 41), Pair(-33, 6)
      },
      { // Piece 4
        Pair(49, -6), Pair(119, -13), Pair(43, 31), Pair(4, 55), Pair(112, 6), Pair(-30, 82), Pair(-29, 84), Pair(-12, 101),
        Pair(-2, 104), Pair(-13, 97), Pair(-10, 63), Pair(11, 56), Pair(37, 49), Pair(17, 79), Pair(-59, 176), Pair(-12, 75),
        Pair(57, 23), Pair(-31, 130), Pair(-23, 104), Pair(-39, 112), Pair(32, 83), Pair(-8, 143), Pair(27, 129), Pair(6, 89),
        Pair(2, 114), Pair(8, 113), Pair(-8, 75), Pair(44, 37), Pair(-13, 104), Pair(5, 138), Pair(27, 60), Pair(7, 55),
        Pair(17, 48), Pair(-2, 60), Pair(18, 76), Pair(-7, 93), Pair(-9, 97), Pair(32, 58), Pair(23, 42), Pair(0, 0),
        Pair(4, 50), Pair(13, 92), Pair(20, 78), Pair(23, 80), Pair(13, 81), Pair(46, 34), Pair(20, 89), Pair(10, -10),
        Pair(26, 72), Pair(8, 171), Pair(7, 111), Pair(8, 126), Pair(19, 71), Pair(40, 49), Pair(34, 73), Pair(-4, 4),
        Pair(-2, 85), Pair(30, 48), Pair(3, 94), Pair(15, 70), Pair(10, 76), Pair(10, 97), Pair(-6, 165), Pair(59, -90)
      },
      { // Piece 5
        Pair(-6, 80), Pair(2, -15), Pair(9, 3), Pair(-110, 132), Pair(-129, 14), Pair(6, 21), Pair(-39, 108), Pair(72, 60),
        Pair(1, 45), Pair(3, -63), Pair(-25, 17), Pair(-1, 11), Pair(49, 7), Pair(-194, 104), Pair(-140, 88), Pair(82, 34),
        Pair(-37, 14), Pair(-62, -9), Pair(-76, 41), Pair(-153, 14), Pair(-40, 49), Pair(-4, 32), Pair(22, 57), Pair(-80, 46),
        Pair(-26, 12), Pair(-115, 13), Pair(-130, 23), Pair(-90, 46), Pair(-16, 21), Pair(42, 25), Pair(104, -10), Pair(124, -67),
        Pair(-95, 16), Pair(-50, -3), Pair(-10, 2), Pair(-24, 16), Pair(-60, 31), Pair(23, 9), Pair(-30, 8), Pair(0, 0),
        Pair(-127, 15), Pair(-45, 20), Pair(-66, 18), Pair(10, 0), Pair(-9, 3), Pair(-8, 1), Pair(16, -16), Pair(-37, -12),
        Pair(-97, 12), Pair(-68, -1), Pair(-39, -7), Pair(-25, 3), Pair(-7, -7), Pair(0, -4), Pair(-30, 7), Pair(-14, -16),
        Pair(-83, -26), Pair(-50, 2), Pair(-48, 6), Pair(-41, -3), Pair(-12, -17), Pair(-13, -12), Pair(7, -22), Pair(-3, -48)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(36, 84), Pair(-9, 23), Pair(-35, 52), Pair(-14, 4), Pair(-20, -5), Pair(8, 17), Pair(4, 23), Pair(7, 42),
        Pair(0, 48), Pair(-1, 35), Pair(-16, 19), Pair(-16, 25), Pair(-13, 36), Pair(1, 13), Pair(-3, 37), Pair(-11, 20),
        Pair(8, 8), Pair(-1, 24), Pair(-4, 11), Pair(1, 11), Pair(-6, 22), Pair(-2, 19), Pair(-1, 11), Pair(0, 9),
        Pair(22, -15), Pair(9, 21), Pair(4, -3), Pair(5, 9), Pair(2, 11), Pair(7, 11), Pair(4, 15), Pair(-6, 20),
        Pair(-1, 13), Pair(-5, 5), Pair(-2, 5), Pair(3, 25), Pair(6, 15), Pair(1, 21), Pair(0, 21), Pair(-7, 19),
        Pair(-1, 9), Pair(4, 31), Pair(-4, 12), Pair(0, 24), Pair(6, 8), Pair(7, 24), Pair(3, 30), Pair(-6, 24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-136, 60), Pair(-109, 93), Pair(34, 123), Pair(-72, 135), Pair(-75, 111), Pair(76, 15), Pair(146, 86), Pair(-169, 108),
        Pair(30, 21), Pair(-56, 54), Pair(11, 73), Pair(-83, 89), Pair(-2, 62), Pair(-2, 82), Pair(41, 5), Pair(-12, 37),
        Pair(-102, 119), Pair(-35, 101), Pair(32, 30), Pair(15, 88), Pair(-49, 60), Pair(4, 86), Pair(16, 59), Pair(-80, 103),
        Pair(-40, 95), Pair(18, 70), Pair(-34, 103), Pair(0, 63), Pair(5, 83), Pair(12, 76), Pair(1, 86), Pair(2, 42),
        Pair(-2, 93), Pair(41, 96), Pair(4, 79), Pair(7, 63), Pair(2, 72), Pair(12, 76), Pair(-11, 97), Pair(5, 75),
        Pair(0, 0), Pair(8, 65), Pair(9, 71), Pair(1, 90), Pair(7, 82), Pair(7, 73), Pair(14, 54), Pair(-1, 82),
        Pair(36, 53), Pair(3, 103), Pair(0, 60), Pair(4, 62), Pair(13, 68), Pair(-10, 62), Pair(8, 64), Pair(18, 108),
        Pair(-96, 12), Pair(-3, 74), Pair(-28, 112), Pair(18, 51), Pair(0, 72), Pair(16, 47), Pair(0, 59), Pair(-72, 32)
      },
      { // Piece 2
        Pair(-105, 99), Pair(189, -19), Pair(77, 52), Pair(49, 28), Pair(-63, 38), Pair(11, 4), Pair(-143, 120), Pair(-6, -8),
        Pair(48, 32), Pair(11, 72), Pair(56, 44), Pair(132, 14), Pair(83, -8), Pair(40, 36), Pair(52, 4), Pair(-22, 55),
        Pair(32, 24), Pair(87, 55), Pair(60, 62), Pair(33, 24), Pair(9, 40), Pair(52, 10), Pair(-16, 45), Pair(1, 60),
        Pair(20, 72), Pair(6, 59), Pair(47, 13), Pair(9, 81), Pair(19, 45), Pair(-4, 65), Pair(28, 40), Pair(6, 47),
        Pair(11, 77), Pair(81, 46), Pair(12, 55), Pair(18, 61), Pair(16, 51), Pair(21, 45), Pair(20, 74), Pair(5, 67),
        Pair(0, 0), Pair(23, 72), Pair(12, 60), Pair(7, 60), Pair(22, 73), Pair(17, 69), Pair(11, 51), Pair(5, 59),
        Pair(-19, 92), Pair(20, 51), Pair(-1, 76), Pair(20, 66), Pair(8, 68), Pair(12, 54), Pair(6, 65), Pair(-11, 21),
        Pair(23, 58), Pair(-16, 121), Pair(4, 57), Pair(-6, 96), Pair(31, 47), Pair(3, 71), Pair(16, 57), Pair(21, 74)
      },
      { // Piece 3
        Pair(-99, 82), Pair(1, 95), Pair(44, 84), Pair(0, 94), Pair(14, 91), Pair(-134, 124), Pair(-31, 106), Pair(14, 76),
        Pair(-61, 87), Pair(-28, 106), Pair(-61, 136), Pair(-20, 102), Pair(22, 96), Pair(-24, 92), Pair(-6, 120), Pair(-2, 103),
        Pair(-38, 63), Pair(-28, 113), Pair(-69, 131), Pair(-6, 94), Pair(-24, 106), Pair(-57, 124), Pair(5, 94), Pair(-43, 118),
        Pair(-53, 95), Pair(-44, 107), Pair(-7, 105), Pair(-1, 123), Pair(27, 112), Pair(-15, 103), Pair(-26, 110), Pair(10, 87),
        Pair(-51, 86), Pair(23, 114), Pair(-4, 127), Pair(-17, 122), Pair(-7, 106), Pair(-14, 111), Pair(-25, 130), Pair(0, 108),
        Pair(0, 0), Pair(-14, 90), Pair(-21, 144), Pair(2, 104), Pair(-31, 137), Pair(29, 93), Pair(-21, 111), Pair(14, 89),
        Pair(-58, 78), Pair(-46, 136), Pair(-21, 107), Pair(-24, 120), Pair(-4, 113), Pair(-18, 120), Pair(-22, 105), Pair(14, 116),
        Pair(-48, 53), Pair(-34, 114), Pair(-16, 104), Pair(-15, 113), Pair(-7, 113), Pair(-11, 82), Pair(-13, 106), Pair(-13, 102)
      },
      { // Piece 4
        Pair(47, 92), Pair(1, 240), Pair(27, 167), Pair(-6, 202), Pair(4, 207), Pair(62, 140), Pair(53, 210), Pair(25, 202),
        Pair(-18, 203), Pair(-22, 204), Pair(0, 174), Pair(-34, 258), Pair(31, 204), Pair(5, 193), Pair(34, 164), Pair(29, 194),
        Pair(-56, 264), Pair(21, 174), Pair(-17, 228), Pair(37, 197), Pair(-16, 275), Pair(48, 173), Pair(39, 206), Pair(30, 188),
        Pair(1, 196), Pair(4, 220), Pair(45, 153), Pair(7, 180), Pair(52, 151), Pair(4, 188), Pair(39, 196), Pair(33, 148),
        Pair(9, 179), Pair(-29, 255), Pair(30, 150), Pair(-7, 230), Pair(36, 144), Pair(2, 230), Pair(3, 187), Pair(38, 184),
        Pair(0, 0), Pair(4, 222), Pair(28, 169), Pair(36, 172), Pair(20, 216), Pair(23, 206), Pair(9, 217), Pair(47, 107),
        Pair(37, 51), Pair(-4, 243), Pair(21, 182), Pair(29, 185), Pair(13, 214), Pair(30, 164), Pair(20, 240), Pair(61, 203),
        Pair(-9, 233), Pair(8, 233), Pair(13, 190), Pair(8, 196), Pair(32, 208), Pair(29, 179), Pair(-2, 246), Pair(-38, 238)
      },
      { // Piece 5
        Pair(27, 86), Pair(55, -24), Pair(47, -10), Pair(80, -75), Pair(-54, -8), Pair(-123, 15), Pair(-47, -28), Pair(-91, 66),
        Pair(-36, -12), Pair(-43, 65), Pair(116, 45), Pair(67, -38), Pair(58, 3), Pair(80, 44), Pair(-85, 32), Pair(-87, 2),
        Pair(41, -48), Pair(61, 3), Pair(-22, 42), Pair(-8, 34), Pair(-67, 64), Pair(16, -19), Pair(-30, 11), Pair(-113, 33),
        Pair(24, 13), Pair(-36, 54), Pair(-41, 33), Pair(57, 15), Pair(-69, 33), Pair(-23, 18), Pair(-6, 25), Pair(-117, 43),
        Pair(-133, 28), Pair(-46, -44), Pair(11, 35), Pair(91, 26), Pair(-33, 33), Pair(-33, 21), Pair(-1, -1), Pair(8, -5),
        Pair(0, 0), Pair(0, 4), Pair(14, 12), Pair(7, 26), Pair(-47, 28), Pair(-33, 11), Pair(-36, 12), Pair(-63, 18),
        Pair(64, -29), Pair(13, -19), Pair(59, -12), Pair(-4, 25), Pair(-18, 9), Pair(-29, 20), Pair(-19, 2), Pair(-15, 3),
        Pair(74, -63), Pair(73, -30), Pair(54, -23), Pair(-14, 5), Pair(9, 2), Pair(-21, 2), Pair(-15, 3), Pair(-23, -19)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 37), Pair(11, 23), Pair(0, 37), Pair(-48, 28), Pair(20, -14), Pair(74, -11), Pair(30, -4), Pair(-40, 10),
        Pair(-13, 12), Pair(14, 2), Pair(-5, 19), Pair(-3, 6), Pair(-8, 6), Pair(-18, 17), Pair(-4, 13), Pair(0, 6),
        Pair(-10, 21), Pair(12, 20), Pair(2, 5), Pair(4, 18), Pair(2, 7), Pair(7, 9), Pair(-2, 12), Pair(-4, 7),
        Pair(2, 10), Pair(-2, 35), Pair(10, 12), Pair(-1, 16), Pair(4, 9), Pair(9, 15), Pair(1, 14), Pair(-3, 14),
        Pair(-4, 6), Pair(-10, 12), Pair(6, 13), Pair(-4, 12), Pair(7, 15), Pair(3, 17), Pair(2, 16), Pair(-3, 19),
        Pair(-1, 26), Pair(22, 7), Pair(11, 35), Pair(-10, 17), Pair(6, 11), Pair(-2, 21), Pair(5, 22), Pair(-3, 24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(101, -48), Pair(105, 104), Pair(115, 50), Pair(25, 91), Pair(-190, 120), Pair(-44, 58), Pair(50, 129), Pair(-37, 99),
        Pair(-17, 55), Pair(6, 45), Pair(-44, 83), Pair(-32, 80), Pair(-110, 135), Pair(13, 59), Pair(-42, 91), Pair(70, 20),
        Pair(-102, 89), Pair(-17, 98), Pair(13, 80), Pair(-25, 71), Pair(-19, 100), Pair(10, 71), Pair(-18, 103), Pair(45, 57),
        Pair(1, 61), Pair(-11, 86), Pair(32, 67), Pair(-2, 91), Pair(0, 75), Pair(6, 87), Pair(6, 80), Pair(-6, 93),
        Pair(12, 55), Pair(4, 57), Pair(18, 61), Pair(8, 91), Pair(-15, 94), Pair(6, 97), Pair(-5, 71), Pair(9, 83),
        Pair(1, 119), Pair(0, 0), Pair(4, 87), Pair(20, 67), Pair(-11, 85), Pair(4, 92), Pair(0, 77), Pair(8, 67),
        Pair(2, 133), Pair(24, 109), Pair(16, 105), Pair(-2, 71), Pair(0, 90), Pair(17, 57), Pair(-17, 144), Pair(7, 116),
        Pair(-76, -16), Pair(-12, 48), Pair(52, 63), Pair(7, 66), Pair(34, 110), Pair(-3, 81), Pair(4, 100), Pair(-15, 41)
      },
      { // Piece 2
        Pair(19, 53), Pair(91, 43), Pair(-44, 69), Pair(177, 26), Pair(-22, 31), Pair(42, 61), Pair(70, 39), Pair(-1, 77),
        Pair(-33, 86), Pair(7, 61), Pair(14, 100), Pair(25, 47), Pair(69, 36), Pair(-26, 38), Pair(16, 30), Pair(51, 17),
        Pair(-13, 69), Pair(7, 83), Pair(11, 57), Pair(-14, 73), Pair(10, 57), Pair(71, 15), Pair(48, 21), Pair(17, 69),
        Pair(-47, 100), Pair(-6, 42), Pair(30, 62), Pair(8, 50), Pair(-4, 83), Pair(15, 46), Pair(15, 73), Pair(-14, 53),
        Pair(-94, -11), Pair(25, 68), Pair(15, 45), Pair(19, 61), Pair(6, 45), Pair(5, 85), Pair(29, 53), Pair(12, 70),
        Pair(9, 40), Pair(0, 0), Pair(16, 55), Pair(0, 63), Pair(31, 74), Pair(1, 63), Pair(28, 79), Pair(-12, 64),
        Pair(102, 19), Pair(22, 73), Pair(-13, 66), Pair(8, 92), Pair(-1, 73), Pair(21, 58), Pair(2, 71), Pair(8, 42),
        Pair(13, 15), Pair(38, -14), Pair(2, 81), Pair(-15, 78), Pair(5, 59), Pair(-3, 58), Pair(90, 108), Pair(14, 71)
      },
      { // Piece 3
        Pair(-43, 117), Pair(47, 32), Pair(41, 84), Pair(-9, 121), Pair(-73, 144), Pair(78, 74), Pair(1, 95), Pair(32, 96),
        Pair(-27, 129), Pair(-34, 81), Pair(8, 103), Pair(-27, 122), Pair(36, 96), Pair(53, 88), Pair(-31, 134), Pair(1, 128),
        Pair(-28, 134), Pair(-48, 108), Pair(21, 95), Pair(-44, 135), Pair(-11, 116), Pair(-4, 117), Pair(12, 105), Pair(-26, 128),
        Pair(-21, 122), Pair(-30, 99), Pair(22, 106), Pair(-20, 119), Pair(-7, 114), Pair(-9, 130), Pair(-52, 132), Pair(-18, 129),
        Pair(-8, 122), Pair(29, 58), Pair(24, 98), Pair(-6, 136), Pair(-6, 123), Pair(-11, 115), Pair(15, 107), Pair(-3, 121),
        Pair(-34, 99), Pair(0, 0), Pair(16, 122), Pair(-11, 153), Pair(-13, 132), Pair(-5, 115), Pair(-9, 113), Pair(-10, 116),
        Pair(-26, 136), Pair(-20, 26), Pair(-9, 130), Pair(-5, 157), Pair(-12, 132), Pair(-30, 146), Pair(-3, 85), Pair(-2, 114),
        Pair(-9, 91), Pair(-22, 46), Pair(-8, 123), Pair(-6, 116), Pair(-11, 119), Pair(-9, 117), Pair(-1, 108), Pair(-6, 111)
      },
      { // Piece 4
        Pair(92, 133), Pair(-17, 206), Pair(-32, 181), Pair(-55, 180), Pair(-92, 284), Pair(-78, 236), Pair(-63, 223), Pair(-36, 193),
        Pair(-18, 188), Pair(18, 142), Pair(15, 184), Pair(-18, 194), Pair(-24, 200), Pair(-4, 147), Pair(-68, 210), Pair(11, 184),
        Pair(-30, 183), Pair(36, 162), Pair(-12, 176), Pair(10, 212), Pair(10, 201), Pair(-9, 213), Pair(-1, 217), Pair(-50, 224),
        Pair(26, 126), Pair(-16, 198), Pair(-17, 194), Pair(10, 174), Pair(4, 156), Pair(20, 148), Pair(15, 119), Pair(0, 160),
        Pair(-34, 100), Pair(2, 127), Pair(7, 153), Pair(7, 156), Pair(20, 190), Pair(19, 137), Pair(10, 164), Pair(-5, 229),
        Pair(-15, 80), Pair(0, 0), Pair(26, 156), Pair(34, 162), Pair(16, 166), Pair(31, 145), Pair(1, 206), Pair(33, 184),
        Pair(6, 114), Pair(1, 163), Pair(4, 156), Pair(33, 111), Pair(18, 152), Pair(22, 168), Pair(45, 150), Pair(18, 202),
        Pair(29, 91), Pair(-18, 190), Pair(-12, 200), Pair(4, 151), Pair(8, 187), Pair(31, 98), Pair(41, 167), Pair(62, 17)
      },
      { // Piece 5
        Pair(-50, -24), Pair(24, 11), Pair(124, 26), Pair(-2, -82), Pair(72, -78), Pair(2, 27), Pair(-57, -13), Pair(-36, 13),
        Pair(-29, -15), Pair(22, -12), Pair(-11, 49), Pair(64, -39), Pair(12, 60), Pair(0, 18), Pair(-116, 65), Pair(-130, 53),
        Pair(-45, 10), Pair(73, -6), Pair(-34, 22), Pair(-27, 27), Pair(-155, 55), Pair(-79, 42), Pair(81, 16), Pair(-200, 22),
        Pair(148, 49), Pair(165, -12), Pair(66, 48), Pair(137, 5), Pair(-21, 21), Pair(-24, 20), Pair(38, 12), Pair(-69, 13),
        Pair(41, -4), Pair(-10, 13), Pair(73, -6), Pair(113, 14), Pair(55, 17), Pair(-49, 33), Pair(-3, 8), Pair(-218, 57),
        Pair(61, -12), Pair(0, 0), Pair(14, 7), Pair(23, 14), Pair(-34, 34), Pair(-30, 20), Pair(-27, 25), Pair(-40, 19),
        Pair(114, -40), Pair(94, -25), Pair(33, 1), Pair(31, -1), Pair(-15, 28), Pair(-25, 21), Pair(-19, 16), Pair(-25, -4),
        Pair(20, -18), Pair(93, -31), Pair(55, 14), Pair(9, 15), Pair(6, 9), Pair(-2, 13), Pair(-12, 8), Pair(-16, -1)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, 23), Pair(-52, 43), Pair(-16, 22), Pair(115, -26), Pair(33, 22), Pair(48, -19), Pair(45, -12), Pair(7, 26),
        Pair(-6, 10), Pair(-11, 33), Pair(8, 2), Pair(5, 6), Pair(-1, 14), Pair(0, 8), Pair(7, 16), Pair(-5, 11),
        Pair(0, 7), Pair(-1, 32), Pair(5, 1), Pair(-1, 29), Pair(1, 13), Pair(7, 3), Pair(-3, 8), Pair(-2, 9),
        Pair(2, 8), Pair(14, 14), Pair(-12, -7), Pair(17, 34), Pair(0, 13), Pair(5, 11), Pair(-1, 17), Pair(-5, 12),
        Pair(-4, 3), Pair(5, 13), Pair(-7, -5), Pair(5, 27), Pair(-9, 9), Pair(5, 16), Pair(3, 17), Pair(-1, 16),
        Pair(0, 5), Pair(21, 34), Pair(-14, -9), Pair(10, 34), Pair(-2, 15), Pair(5, 18), Pair(1, 20), Pair(3, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, 65), Pair(-45, 70), Pair(-118, 122), Pair(-59, 51), Pair(90, 13), Pair(17, 90), Pair(-85, -106), Pair(-82, 113),
        Pair(7, 48), Pair(-15, 63), Pair(9, 61), Pair(80, 24), Pair(75, 22), Pair(11, 40), Pair(-48, 51), Pair(51, 8),
        Pair(-46, 77), Pair(47, 70), Pair(-22, 87), Pair(-8, 57), Pair(-56, 95), Pair(12, 87), Pair(-7, 54), Pair(-2, 73),
        Pair(-26, 124), Pair(-10, 89), Pair(3, 73), Pair(22, 64), Pair(6, 66), Pair(27, 54), Pair(15, 80), Pair(-22, 102),
        Pair(-4, 67), Pair(21, 77), Pair(16, 82), Pair(6, 94), Pair(8, 78), Pair(6, 82), Pair(12, 81), Pair(12, 77),
        Pair(4, 82), Pair(-5, 110), Pair(0, 0), Pair(9, 63), Pair(24, 71), Pair(10, 80), Pair(9, 90), Pair(18, 72),
        Pair(-2, -20), Pair(-6, 55), Pair(22, 82), Pair(16, 97), Pair(-2, 83), Pair(30, 86), Pair(26, 83), Pair(20, 63),
        Pair(-13, 49), Pair(-7, 57), Pair(-4, 108), Pair(-13, 73), Pair(8, 72), Pair(30, 72), Pair(3, 61), Pair(76, 85)
      },
      { // Piece 2
        Pair(-46, 95), Pair(119, 31), Pair(163, 15), Pair(-86, 76), Pair(43, 27), Pair(14, -14), Pair(46, 97), Pair(-37, 7),
        Pair(-25, 65), Pair(3, 87), Pair(6, 64), Pair(60, 44), Pair(62, 19), Pair(91, 2), Pair(-37, 20), Pair(23, 43),
        Pair(20, 56), Pair(21, 58), Pair(24, 50), Pair(3, 61), Pair(36, 37), Pair(73, -6), Pair(-17, 52), Pair(5, 30),
        Pair(-48, 54), Pair(10, 72), Pair(4, 60), Pair(25, 63), Pair(1, 55), Pair(19, 53), Pair(8, 53), Pair(14, 84),
        Pair(-8, 109), Pair(31, 33), Pair(27, 53), Pair(18, 72), Pair(22, 66), Pair(7, 59), Pair(41, 62), Pair(8, 52),
        Pair(-15, 13), Pair(26, 56), Pair(0, 0), Pair(18, 84), Pair(2, 61), Pair(20, 54), Pair(26, 43), Pair(27, 66),
        Pair(42, 8), Pair(-11, -28), Pair(22, 78), Pair(-5, 54), Pair(23, 79), Pair(-3, 49), Pair(22, 57), Pair(7, 81),
        Pair(12, -92), Pair(27, 37), Pair(-1, 44), Pair(21, 55), Pair(-13, 64), Pair(22, 81), Pair(63, -5), Pair(59, 74)
      },
      { // Piece 3
        Pair(-7, 109), Pair(-45, 113), Pair(-14, 57), Pair(9, 96), Pair(71, 70), Pair(65, 72), Pair(-56, 116), Pair(-15, 97),
        Pair(-3, 102), Pair(-6, 112), Pair(11, 50), Pair(5, 84), Pair(28, 83), Pair(3, 84), Pair(19, 75), Pair(5, 87),
        Pair(13, 98), Pair(4, 82), Pair(74, 55), Pair(-31, 118), Pair(-18, 109), Pair(0, 90), Pair(14, 106), Pair(38, 102),
        Pair(-3, 103), Pair(-2, 97), Pair(10, 91), Pair(-2, 96), Pair(29, 63), Pair(16, 98), Pair(-15, 84), Pair(-7, 115),
        Pair(23, 103), Pair(-20, 115), Pair(-14, 79), Pair(8, 120), Pair(8, 98), Pair(8, 95), Pair(-4, 94), Pair(9, 87),
        Pair(-15, 84), Pair(-22, 91), Pair(0, 0), Pair(19, 89), Pair(-7, 102), Pair(27, 59), Pair(14, 67), Pair(26, 92),
        Pair(8, 107), Pair(-4, 88), Pair(7, 27), Pair(1, 96), Pair(2, 85), Pair(23, 62), Pair(35, 74), Pair(27, 100),
        Pair(5, 98), Pair(3, 92), Pair(10, 29), Pair(-15, 113), Pair(13, 83), Pair(13, 77), Pair(13, 90), Pair(19, 86)
      },
      { // Piece 4
        Pair(49, 214), Pair(-24, 150), Pair(-30, 188), Pair(-107, 235), Pair(-2, 174), Pair(25, 167), Pair(47, 172), Pair(2, 207),
        Pair(9, 190), Pair(-8, 209), Pair(-37, 202), Pair(-4, 224), Pair(-29, 221), Pair(-11, 168), Pair(-37, 110), Pair(-14, 182),
        Pair(-18, 183), Pair(-19, 159), Pair(6, 158), Pair(-29, 188), Pair(-19, 225), Pair(21, 231), Pair(-16, 198), Pair(-21, 202),
        Pair(-28, 137), Pair(-2, 167), Pair(3, 147), Pair(1, 178), Pair(-21, 183), Pair(1, 178), Pair(5, 160), Pair(5, 104),
        Pair(-7, 115), Pair(-17, 216), Pair(12, 150), Pair(18, 147), Pair(3, 161), Pair(34, 121), Pair(-15, 193), Pair(20, 140),
        Pair(-7, 112), Pair(3, 118), Pair(0, 0), Pair(18, 189), Pair(15, 180), Pair(11, 159), Pair(16, 145), Pair(21, 169),
        Pair(24, 75), Pair(20, 94), Pair(6, 81), Pair(10, 168), Pair(13, 164), Pair(16, 206), Pair(38, 143), Pair(49, 205),
        Pair(1, 71), Pair(8, 224), Pair(8, 89), Pair(-3, 189), Pair(14, 119), Pair(20, 102), Pair(35, 66), Pair(12, 267)
      },
      { // Piece 5
        Pair(-29, 39), Pair(11, 29), Pair(-59, 92), Pair(-145, 37), Pair(38, 37), Pair(33, -37), Pair(-4, -26), Pair(23, -32),
        Pair(9, 26), Pair(48, 88), Pair(-28, 57), Pair(-75, 68), Pair(3, 24), Pair(14, 19), Pair(113, -4), Pair(34, -42),
        Pair(-48, 48), Pair(-76, 45), Pair(9, 63), Pair(-112, 72), Pair(-49, 51), Pair(75, 10), Pair(47, 10), Pair(-81, -13),
        Pair(-104, 51), Pair(-92, 77), Pair(-25, 47), Pair(-42, 51), Pair(78, -13), Pair(-89, 22), Pair(-153, 38), Pair(-72, -11),
        Pair(147, -29), Pair(-39, -11), Pair(14, 8), Pair(-55, 23), Pair(-35, 22), Pair(28, 15), Pair(13, -5), Pair(-9, -15),
        Pair(117, -2), Pair(30, -2), Pair(0, 0), Pair(-35, 32), Pair(-41, 22), Pair(20, 4), Pair(-10, 14), Pair(18, -1),
        Pair(62, -35), Pair(10, 1), Pair(1, 7), Pair(-6, 12), Pair(-4, 11), Pair(-9, 16), Pair(-11, -6), Pair(-15, 2),
        Pair(56, -32), Pair(-13, 11), Pair(-13, 15), Pair(-20, 27), Pair(6, -6), Pair(-5, 6), Pair(-2, -14), Pair(-17, -3)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-34, 10), Pair(3, -3), Pair(-25, -1), Pair(-81, 11), Pair(-29, 64), Pair(-10, 28), Pair(33, -46), Pair(-3, 35),
        Pair(-11, 16), Pair(1, 17), Pair(-7, 21), Pair(-34, 23), Pair(7, 16), Pair(2, 7), Pair(9, -12), Pair(-3, 22),
        Pair(-3, 13), Pair(3, 14), Pair(-4, 22), Pair(7, -15), Pair(6, 19), Pair(13, 17), Pair(-2, 5), Pair(-5, 9),
        Pair(0, 14), Pair(-5, 16), Pair(10, 30), Pair(12, -24), Pair(14, 21), Pair(2, 14), Pair(3, 14), Pair(-9, 15),
        Pair(-1, 22), Pair(-5, 10), Pair(3, 25), Pair(8, -16), Pair(10, 31), Pair(-12, 14), Pair(7, 12), Pair(-2, 17),
        Pair(3, 19), Pair(-4, 5), Pair(9, 42), Pair(-16, -21), Pair(18, 44), Pair(-9, 24), Pair(-1, 21), Pair(1, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(36, -5), Pair(8, -28), Pair(-167, 70), Pair(-82, 157), Pair(-79, 32), Pair(-142, 138), Pair(-19, 74), Pair(27, 118),
        Pair(-63, 138), Pair(-55, 79), Pair(-54, 91), Pair(74, 77), Pair(-30, 92), Pair(-17, 74), Pair(-40, 41), Pair(-10, 95),
        Pair(-69, 41), Pair(-23, 102), Pair(-7, 93), Pair(-70, 136), Pair(-61, 108), Pair(-1, 90), Pair(0, 85), Pair(6, 41),
        Pair(-39, 106), Pair(-11, 104), Pair(-19, 81), Pair(-34, 108), Pair(7, 78), Pair(6, 102), Pair(5, 89), Pair(8, 93),
        Pair(-23, 85), Pair(-33, 65), Pair(-10, 97), Pair(-6, 95), Pair(-13, 75), Pair(6, 78), Pair(35, 70), Pair(3, 111),
        Pair(7, 62), Pair(-4, 68), Pair(4, 85), Pair(0, 0), Pair(-8, 91), Pair(10, 97), Pair(-3, 85), Pair(17, 69),
        Pair(1, 20), Pair(-76, 55), Pair(18, 70), Pair(12, 85), Pair(11, 92), Pair(10, 54), Pair(-21, 132), Pair(37, 28),
        Pair(-53, 30), Pair(7, 57), Pair(-30, 15), Pair(-21, 87), Pair(-18, 82), Pair(13, 86), Pair(20, 85), Pair(-7, 148)
      },
      { // Piece 2
        Pair(-13, 25), Pair(-7, 104), Pair(51, 8), Pair(-17, 48), Pair(78, 21), Pair(-32, 79), Pair(-44, 43), Pair(-73, 141),
        Pair(-11, 100), Pair(-25, 20), Pair(44, 84), Pair(-9, 78), Pair(22, 33), Pair(-30, 78), Pair(-30, 56), Pair(-101, 68),
        Pair(-22, 83), Pair(1, 67), Pair(-11, 52), Pair(15, 69), Pair(22, 29), Pair(-12, 58), Pair(16, -45), Pair(-25, 59),
        Pair(5, 85), Pair(6, 35), Pair(5, 79), Pair(-14, 63), Pair(20, 48), Pair(14, 36), Pair(12, 54), Pair(0, 31),
        Pair(-3, 24), Pair(10, 65), Pair(6, 24), Pair(17, 34), Pair(28, 45), Pair(-1, 73), Pair(18, 34), Pair(-5, 39),
        Pair(8, 37), Pair(10, 21), Pair(15, 58), Pair(0, 0), Pair(12, 65), Pair(-2, 63), Pair(9, 73), Pair(-6, 56),
        Pair(34, -7), Pair(12, 57), Pair(2, -58), Pair(27, 59), Pair(-4, 13), Pair(-7, 94), Pair(-11, 54), Pair(-26, 58),
        Pair(25, 78), Pair(-66, -11), Pair(18, 25), Pair(14, 40), Pair(-15, 60), Pair(-10, 2), Pair(77, 43), Pair(-22, 72)
      },
      { // Piece 3
        Pair(27, 66), Pair(-24, 133), Pair(-26, 90), Pair(-84, 81), Pair(-18, 92), Pair(63, 69), Pair(48, 72), Pair(51, 79),
        Pair(-11, 93), Pair(-26, 119), Pair(-71, 144), Pair(-14, 53), Pair(-57, 115), Pair(-83, 117), Pair(4, 95), Pair(32, 82),
        Pair(-34, 136), Pair(17, 106), Pair(-8, 97), Pair(-31, 81), Pair(-8, 77), Pair(1, 94), Pair(41, 74), Pair(21, 85),
        Pair(-17, 91), Pair(15, 81), Pair(-4, 96), Pair(81, 27), Pair(-43, 128), Pair(9, 118), Pair(-63, 117), Pair(0, 111),
        Pair(-9, 112), Pair(-4, 96), Pair(-8, 86), Pair(-23, 55), Pair(1, 85), Pair(13, 93), Pair(-15, 95), Pair(-13, 105),
        Pair(-17, 88), Pair(2, 64), Pair(-14, 72), Pair(0, 0), Pair(-11, 78), Pair(5, 69), Pair(4, 65), Pair(18, 74),
        Pair(-18, 103), Pair(-3, 98), Pair(6, 65), Pair(-5, 66), Pair(-18, 87), Pair(6, 108), Pair(34, 108), Pair(2, 84),
        Pair(-9, 100), Pair(-2, 104), Pair(-23, 97), Pair(15, 38), Pair(-5, 72), Pair(-1, 83), Pair(1, 100), Pair(17, 81)
      },
      { // Piece 4
        Pair(-53, 240), Pair(-11, 185), Pair(-50, 196), Pair(20, 86), Pair(-52, 196), Pair(-53, 155), Pair(135, 14), Pair(-50, 268),
        Pair(-50, 210), Pair(-30, 136), Pair(-9, 165), Pair(49, 59), Pair(73, 178), Pair(16, 150), Pair(35, 144), Pair(-45, 205),
        Pair(-65, 156), Pair(-10, 98), Pair(8, 167), Pair(-6, 160), Pair(22, 169), Pair(-21, 180), Pair(-25, 120), Pair(-50, 225),
        Pair(1, 66), Pair(-35, 130), Pair(-7, 171), Pair(42, 52), Pair(5, 161), Pair(-6, 136), Pair(-13, 137), Pair(-6, 159),
        Pair(7, 104), Pair(4, 108), Pair(-4, 142), Pair(1, 118), Pair(8, 136), Pair(27, 100), Pair(5, 100), Pair(18, 115),
        Pair(16, 10), Pair(-1, 76), Pair(-21, 159), Pair(0, 0), Pair(-13, 171), Pair(1, 119), Pair(28, 89), Pair(-2, 124),
        Pair(17, 144), Pair(30, 65), Pair(-7, 96), Pair(8, 62), Pair(10, 74), Pair(16, 143), Pair(-2, 193), Pair(38, 115),
        Pair(-13, 124), Pair(14, 45), Pair(-18, 166), Pair(5, 50), Pair(12, 95), Pair(-3, 86), Pair(4, 192), Pair(34, 175)
      },
      { // Piece 5
        Pair(-35, -97), Pair(38, 100), Pair(28, -8), Pair(19, 51), Pair(18, 28), Pair(38, 23), Pair(53, 119), Pair(13, 35),
        Pair(-51, 72), Pair(-26, 112), Pair(65, 45), Pair(10, 84), Pair(16, 152), Pair(-18, 10), Pair(124, -33), Pair(-61, 43),
        Pair(-48, 107), Pair(-34, 113), Pair(115, 50), Pair(-12, 90), Pair(43, 4), Pair(21, 45), Pair(-119, 72), Pair(-176, 83),
        Pair(-123, 63), Pair(31, -15), Pair(33, 68), Pair(-84, 73), Pair(28, 9), Pair(-186, 43), Pair(-130, 57), Pair(-68, -19),
        Pair(178, -51), Pair(81, -21), Pair(-59, 19), Pair(-56, 5), Pair(-143, 12), Pair(-28, 8), Pair(-75, 18), Pair(32, 8),
        Pair(-52, -25), Pair(-9, -7), Pair(-47, 0), Pair(0, 0), Pair(-78, 23), Pair(-43, 16), Pair(38, -15), Pair(-40, -8),
        Pair(-33, 10), Pair(-6, -7), Pair(-15, -4), Pair(-80, 23), Pair(-30, -13), Pair(-3, -19), Pair(-11, -22), Pair(-11, -18),
        Pair(-17, -32), Pair(-17, -18), Pair(-30, -13), Pair(-69, 9), Pair(-19, -22), Pair(1, -28), Pair(2, -42), Pair(2, -43)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 7), Pair(-11, 24), Pair(13, -12), Pair(-36, 41), Pair(15, -13), Pair(-4, 30), Pair(32, 17), Pair(4, 14),
        Pair(-7, 16), Pair(-12, 26), Pair(21, -15), Pair(-7, 22), Pair(7, -12), Pair(0, 34), Pair(-1, 0), Pair(4, 4),
        Pair(0, 8), Pair(2, 14), Pair(-2, 8), Pair(1, 33), Pair(-1, 18), Pair(3, 30), Pair(5, 6), Pair(-2, 5),
        Pair(3, 18), Pair(1, 24), Pair(2, 14), Pair(16, 32), Pair(0, -3), Pair(24, 20), Pair(-1, 11), Pair(-3, 3),
        Pair(7, 16), Pair(9, 15), Pair(-9, 7), Pair(10, 33), Pair(0, -6), Pair(12, 22), Pair(-2, 6), Pair(6, 13),
        Pair(4, 16), Pair(-2, 20), Pair(-2, 19), Pair(22, 45), Pair(-9, 1), Pair(22, 47), Pair(2, 12), Pair(4, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, -31), Pair(10, 33), Pair(58, 57), Pair(-64, 107), Pair(-39, 77), Pair(-35, 80), Pair(-120, 103), Pair(13, 6),
        Pair(-6, 97), Pair(-27, 109), Pair(1, 59), Pair(-64, 101), Pair(15, 129), Pair(1, 82), Pair(114, 42), Pair(59, 33),
        Pair(6, 45), Pair(4, 75), Pair(-20, 80), Pair(-6, 83), Pair(-37, 95), Pair(-36, 125), Pair(-13, 87), Pair(-5, 78),
        Pair(-41, 88), Pair(-3, 76), Pair(4, 70), Pair(-1, 74), Pair(-9, 67), Pair(10, 77), Pair(-11, 70), Pair(-4, 89),
        Pair(13, 67), Pair(21, 68), Pair(-6, 77), Pair(15, 90), Pair(-8, 93), Pair(6, 79), Pair(14, 28), Pair(-5, 68),
        Pair(3, 46), Pair(0, 107), Pair(4, 82), Pair(12, 86), Pair(0, 0), Pair(12, 76), Pair(1, 85), Pair(14, 66),
        Pair(39, 44), Pair(-20, 123), Pair(-18, 70), Pair(15, 81), Pair(13, 100), Pair(11, 88), Pair(-18, 49), Pair(12, 133),
        Pair(24, 24), Pair(14, 79), Pair(29, 108), Pair(-5, 63), Pair(-19, 83), Pair(-15, 64), Pair(12, 97), Pair(-38, 64)
      },
      { // Piece 2
        Pair(-2, 21), Pair(42, 27), Pair(175, -8), Pair(-37, 45), Pair(-45, 27), Pair(15, 29), Pair(60, 43), Pair(-8, -28),
        Pair(-25, 53), Pair(-10, 73), Pair(16, 36), Pair(16, 40), Pair(38, 40), Pair(20, 50), Pair(-40, 73), Pair(-15, 27),
        Pair(21, 48), Pair(-23, 70), Pair(-15, 56), Pair(-16, 30), Pair(18, 67), Pair(11, 26), Pair(-1, 66), Pair(-22, 38),
        Pair(-16, 46), Pair(12, 39), Pair(8, 51), Pair(6, 66), Pair(-25, 52), Pair(12, 56), Pair(1, 9), Pair(-5, 72),
        Pair(-16, 46), Pair(5, 22), Pair(-3, 56), Pair(1, 64), Pair(16, 59), Pair(-8, 91), Pair(6, 85), Pair(31, 10),
        Pair(-17, 18), Pair(-1, 44), Pair(-17, 36), Pair(13, 75), Pair(0, 0), Pair(19, 67), Pair(-5, 58), Pair(5, 55),
        Pair(0, 43), Pair(-20, 51), Pair(14, 58), Pair(-30, 22), Pair(28, 68), Pair(-14, -18), Pair(0, 81), Pair(-5, 78),
        Pair(8, 39), Pair(26, 81), Pair(-38, -3), Pair(10, 74), Pair(-5, 35), Pair(17, 44), Pair(38, -106), Pair(17, 71)
      },
      { // Piece 3
        Pair(8, 88), Pair(51, 78), Pair(-7, 107), Pair(-9, 78), Pair(72, 41), Pair(-56, 101), Pair(28, 69), Pair(77, 60),
        Pair(10, 98), Pair(-23, 92), Pair(-13, 99), Pair(-50, 95), Pair(94, 33), Pair(-93, 124), Pair(1, 64), Pair(-18, 105),
        Pair(-24, 103), Pair(-36, 114), Pair(4, 108), Pair(-26, 101), Pair(-61, 82), Pair(-53, 110), Pair(9, 110), Pair(-14, 112),
        Pair(-8, 103), Pair(-3, 95), Pair(0, 97), Pair(-25, 96), Pair(-9, 64), Pair(-29, 95), Pair(-13, 94), Pair(-3, 81),
        Pair(-2, 92), Pair(-10, 92), Pair(-16, 91), Pair(12, 90), Pair(38, 53), Pair(21, 87), Pair(5, 79), Pair(3, 72),
        Pair(-11, 84), Pair(-6, 74), Pair(-6, 78), Pair(-22, 74), Pair(0, 0), Pair(-26, 71), Pair(-28, 95), Pair(-22, 92),
        Pair(6, 92), Pair(25, 82), Pair(-22, 127), Pair(-1, 106), Pair(26, 34), Pair(-4, 106), Pair(-24, 102), Pair(-10, 103),
        Pair(0, 85), Pair(7, 88), Pair(-4, 88), Pair(-11, 93), Pair(33, -14), Pair(-4, 75), Pair(11, 91), Pair(11, 88)
      },
      { // Piece 4
        Pair(18, 135), Pair(32, 71), Pair(53, 114), Pair(-58, 224), Pair(132, 97), Pair(-19, 194), Pair(49, 75), Pair(-6, 190),
        Pair(-26, 139), Pair(19, 101), Pair(-11, 156), Pair(-24, 202), Pair(26, 145), Pair(3, 142), Pair(-53, 188), Pair(-17, 145),
        Pair(-7, 153), Pair(2, 105), Pair(-16, 181), Pair(15, 119), Pair(34, 153), Pair(-16, 187), Pair(3, 152), Pair(-25, 97),
        Pair(-6, 130), Pair(-1, 155), Pair(24, 122), Pair(-15, 168), Pair(0, 110), Pair(-24, 184), Pair(-19, 144), Pair(-11, 143),
        Pair(-7, 165), Pair(11, 103), Pair(-4, 142), Pair(2, 160), Pair(7, 119), Pair(10, 109), Pair(-5, 115), Pair(-8, 132),
        Pair(30, 94), Pair(6, 101), Pair(-10, 118), Pair(10, 109), Pair(0, 0), Pair(-8, 124), Pair(8, 109), Pair(-12, 55),
        Pair(25, 123), Pair(17, 111), Pair(9, 132), Pair(-5, 80), Pair(2, 100), Pair(2, 96), Pair(8, 112), Pair(50, 50),
        Pair(5, 124), Pair(14, 117), Pair(-14, 127), Pair(-3, 150), Pair(-19, 104), Pair(17, 93), Pair(-8, 114), Pair(-41, 304)
      },
      { // Piece 5
        Pair(75, 72), Pair(-3, -34), Pair(-44, 100), Pair(13, 10), Pair(-42, 71), Pair(-49, 6), Pair(-116, 95), Pair(81, 108),
        Pair(2, 48), Pair(-52, 44), Pair(-72, 81), Pair(46, 44), Pair(68, -24), Pair(-72, 24), Pair(87, 22), Pair(32, 47),
        Pair(-5, 58), Pair(-44, 10), Pair(78, 16), Pair(108, -14), Pair(22, 36), Pair(-11, 2), Pair(-166, 91), Pair(186, 62),
        Pair(-35, 76), Pair(-158, 31), Pair(-56, 7), Pair(10, 44), Pair(-56, 14), Pair(-54, 47), Pair(-73, 38), Pair(-100, 38),
        Pair(53, -50), Pair(-16, 32), Pair(-147, 40), Pair(-62, 3), Pair(-61, 6), Pair(2, -10), Pair(57, -17), Pair(93, -25),
        Pair(53, -9), Pair(-1, 15), Pair(25, 3), Pair(-52, 17), Pair(0, 0), Pair(-7, 11), Pair(65, -17), Pair(19, 2),
        Pair(4, 3), Pair(-36, 21), Pair(5, 0), Pair(-28, 5), Pair(-44, 25), Pair(-24, 10), Pair(10, -1), Pair(6, -5),
        Pair(42, -69), Pair(-10, -29), Pair(4, -11), Pair(-28, 26), Pair(-42, 13), Pair(-5, -5), Pair(13, -7), Pair(4, -28)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(22, 5), Pair(-22, 20), Pair(-60, 24), Pair(-25, 35), Pair(-106, 54), Pair(9, 36), Pair(13, 0), Pair(24, 11),
        Pair(-13, 19), Pair(-5, 7), Pair(13, 12), Pair(1, -1), Pair(-7, 35), Pair(-56, 16), Pair(-33, 35), Pair(0, 0),
        Pair(-6, 16), Pair(0, 7), Pair(-1, 9), Pair(5, 12), Pair(-4, 33), Pair(7, 7), Pair(4, 19), Pair(12, -5),
        Pair(-1, 20), Pair(6, 14), Pair(1, 17), Pair(0, 14), Pair(21, 16), Pair(-13, -5), Pair(18, 11), Pair(8, -8),
        Pair(2, 24), Pair(3, 18), Pair(3, 15), Pair(-12, 15), Pair(12, 25), Pair(1, -11), Pair(15, 12), Pair(-2, 4),
        Pair(2, 18), Pair(0, 16), Pair(1, 7), Pair(-6, 13), Pair(19, 34), Pair(3, 4), Pair(18, 31), Pair(0, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-19, 25), Pair(43, 6), Pair(-96, 50), Pair(22, 66), Pair(167, 29), Pair(-135, 15), Pair(82, 65), Pair(-140, 179),
        Pair(-69, 50), Pair(6, 61), Pair(-28, 65), Pair(9, 25), Pair(50, 71), Pair(-43, 100), Pair(46, 49), Pair(50, 39),
        Pair(14, 98), Pair(-14, 74), Pair(-17, 72), Pair(-12, 94), Pair(-19, 80), Pair(-28, 72), Pair(-29, 98), Pair(-71, 125),
        Pair(7, 66), Pair(5, 54), Pair(15, 66), Pair(-1, 68), Pair(29, 68), Pair(8, 77), Pair(-1, 65), Pair(7, 72),
        Pair(19, 87), Pair(21, 59), Pair(4, 73), Pair(17, 73), Pair(9, 67), Pair(0, 78), Pair(-8, 70), Pair(13, 57),
        Pair(17, 84), Pair(3, 73), Pair(7, 80), Pair(21, 82), Pair(13, 63), Pair(0, 0), Pair(6, 89), Pair(10, 55),
        Pair(22, 95), Pair(10, 75), Pair(21, 86), Pair(-3, 69), Pair(16, 92), Pair(9, 92), Pair(18, 96), Pair(-4, 19),
        Pair(22, 108), Pair(1, 31), Pair(16, 106), Pair(-5, 83), Pair(43, 16), Pair(26, 37), Pair(-7, 42), Pair(-1, -8)
      },
      { // Piece 2
        Pair(54, 6), Pair(-48, 90), Pair(-137, 21), Pair(146, 27), Pair(97, -6), Pair(25, 40), Pair(144, -5), Pair(42, 37),
        Pair(-42, 119), Pair(49, 6), Pair(16, 43), Pair(11, 24), Pair(32, 41), Pair(46, 6), Pair(53, 24), Pair(1, 31),
        Pair(-17, 4), Pair(38, 27), Pair(28, 10), Pair(34, 38), Pair(21, 35), Pair(41, 30), Pair(10, 26), Pair(-11, 68),
        Pair(19, 51), Pair(1, 32), Pair(18, 45), Pair(-1, 40), Pair(15, 35), Pair(-31, 44), Pair(13, 55), Pair(-58, 52),
        Pair(7, 12), Pair(21, 47), Pair(1, 34), Pair(27, 48), Pair(18, 50), Pair(8, 61), Pair(34, -38), Pair(52, 5),
        Pair(29, 58), Pair(22, 30), Pair(27, 62), Pair(-6, 33), Pair(48, 61), Pair(0, 0), Pair(39, 36), Pair(-15, 13),
        Pair(43, 32), Pair(24, 45), Pair(-12, 49), Pair(30, 47), Pair(7, 24), Pair(47, 44), Pair(-19, -25), Pair(11, 56),
        Pair(29, 82), Pair(17, 40), Pair(24, 44), Pair(-41, 12), Pair(35, 71), Pair(2, 32), Pair(85, 35), Pair(-57, -55)
      },
      { // Piece 3
        Pair(14, 62), Pair(51, 57), Pair(42, 56), Pair(47, 65), Pair(45, 44), Pair(48, 25), Pair(31, 44), Pair(35, 45),
        Pair(20, 48), Pair(39, 60), Pair(24, 53), Pair(73, 33), Pair(-55, 68), Pair(88, 3), Pair(23, 49), Pair(73, 29),
        Pair(30, 45), Pair(49, 55), Pair(42, 31), Pair(15, 40), Pair(31, 50), Pair(63, 34), Pair(15, 59), Pair(33, 52),
        Pair(25, 55), Pair(37, 51), Pair(30, 54), Pair(26, 53), Pair(16, 60), Pair(54, 31), Pair(30, 43), Pair(31, 59),
        Pair(23, 63), Pair(23, 57), Pair(33, 35), Pair(6, 67), Pair(35, 52), Pair(27, 25), Pair(49, 48), Pair(20, 56),
        Pair(33, 70), Pair(14, 52), Pair(30, 65), Pair(22, 53), Pair(14, 39), Pair(0, 0), Pair(15, 23), Pair(41, 24),
        Pair(18, 77), Pair(18, 81), Pair(4, 48), Pair(-26, 92), Pair(34, 54), Pair(54, -4), Pair(21, 30), Pair(24, 60),
        Pair(27, 53), Pair(26, 63), Pair(21, 48), Pair(14, 64), Pair(13, 47), Pair(25, 8), Pair(18, 45), Pair(16, 61)
      },
      { // Piece 4
        Pair(2, 126), Pair(-32, 144), Pair(-22, 129), Pair(21, 118), Pair(-16, 198), Pair(-10, 28), Pair(-105, 167), Pair(-20, 209),
        Pair(-18, 121), Pair(-11, 116), Pair(-39, 198), Pair(10, 113), Pair(22, 163), Pair(-45, 98), Pair(36, 135), Pair(-40, 121),
        Pair(34, 42), Pair(18, 114), Pair(45, 68), Pair(-12, 179), Pair(-45, 204), Pair(-6, 156), Pair(12, 57), Pair(30, 100),
        Pair(-15, 158), Pair(-12, 137), Pair(30, 71), Pair(-9, 152), Pair(-30, 203), Pair(-5, 70), Pair(-7, 119), Pair(3, 79),
        Pair(12, 108), Pair(19, 120), Pair(1, 172), Pair(16, 95), Pair(-10, 144), Pair(6, 96), Pair(-5, 111), Pair(-20, 177),
        Pair(27, 108), Pair(19, 110), Pair(26, 126), Pair(21, 125), Pair(15, 117), Pair(0, 0), Pair(-6, 74), Pair(-18, 94),
        Pair(4, 139), Pair(23, 52), Pair(3, 110), Pair(28, 83), Pair(3, 124), Pair(23, 35), Pair(-14, 107), Pair(20, 89),
        Pair(12, 178), Pair(30, 122), Pair(20, 127), Pair(13, 121), Pair(-1, 168), Pair(30, -47), Pair(41, 39), Pair(60, -48)
      },
      { // Piece 5
        Pair(-59, 46), Pair(6, 42), Pair(138, 103), Pair(58, 83), Pair(50, -2), Pair(107, 22), Pair(47, 101), Pair(79, -13),
        Pair(29, 3), Pair(-152, 52), Pair(104, 18), Pair(93, 50), Pair(129, 73), Pair(51, 36), Pair(45, 111), Pair(-59, 86),
        Pair(54, -11), Pair(62, 8), Pair(-182, 81), Pair(-18, 43), Pair(-21, 71), Pair(-95, 70), Pair(90, 21), Pair(84, 10),
        Pair(83, -43), Pair(-85, 13), Pair(79, -6), Pair(-162, 52), Pair(-27, 37), Pair(12, 38), Pair(-28, 66), Pair(-36, 26),
        Pair(-6, 5), Pair(16, -31), Pair(-27, 12), Pair(-24, 8), Pair(-110, -8), Pair(7, -11), Pair(-4, -37), Pair(62, 15),
        Pair(28, -50), Pair(-30, -5), Pair(41, -10), Pair(22, -8), Pair(-6, -15), Pair(0, 0), Pair(-12, -9), Pair(29, -4),
        Pair(-61, 44), Pair(4, -17), Pair(13, -22), Pair(8, -22), Pair(-6, -21), Pair(-43, 8), Pair(-17, -11), Pair(11, -12),
        Pair(5, -87), Pair(-6, -14), Pair(-4, -34), Pair(27, -32), Pair(-17, 3), Pair(-29, -16), Pair(-16, -4), Pair(35, -32)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 35), Pair(-30, 29), Pair(38, -3), Pair(-19, 31), Pair(-2, -2), Pair(-47, 24), Pair(27, -3), Pair(-46, 47),
        Pair(0, 12), Pair(8, 18), Pair(15, 6), Pair(-12, 17), Pair(-14, 12), Pair(-9, 16), Pair(15, -8), Pair(11, 27),
        Pair(1, 16), Pair(2, 10), Pair(7, 1), Pair(0, 3), Pair(4, 7), Pair(-3, 21), Pair(23, 1), Pair(-1, 26),
        Pair(5, 19), Pair(2, 16), Pair(9, 15), Pair(5, 11), Pair(2, 7), Pair(21, 13), Pair(11, -12), Pair(17, 9),
        Pair(2, 28), Pair(2, 21), Pair(2, 15), Pair(10, 15), Pair(1, 9), Pair(16, 14), Pair(-2, 5), Pair(4, 16),
        Pair(-1, 24), Pair(5, 27), Pair(1, 27), Pair(6, 2), Pair(3, 5), Pair(21, 31), Pair(-5, 2), Pair(14, 30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-35, 104), Pair(127, 76), Pair(97, 59), Pair(43, 87), Pair(28, 75), Pair(60, 47), Pair(60, 74), Pair(-47, 121),
        Pair(-35, 107), Pair(48, 33), Pair(50, 71), Pair(-52, 86), Pair(41, 56), Pair(-15, 79), Pair(-33, 56), Pair(39, 84),
        Pair(52, 43), Pair(2, 57), Pair(20, 67), Pair(-21, 84), Pair(-7, 59), Pair(25, 61), Pair(-14, 96), Pair(-39, 65),
        Pair(-5, 75), Pair(4, 72), Pair(22, 70), Pair(27, 77), Pair(8, 87), Pair(19, 86), Pair(7, 72), Pair(-4, 58),
        Pair(19, 67), Pair(18, 77), Pair(17, 79), Pair(2, 67), Pair(11, 76), Pair(17, 29), Pair(16, 66), Pair(12, 35),
        Pair(13, 65), Pair(26, 36), Pair(12, 74), Pair(9, 81), Pair(18, 75), Pair(16, 64), Pair(0, 0), Pair(-1, 89),
        Pair(10, 63), Pair(-33, 76), Pair(9, 55), Pair(14, 68), Pair(8, 60), Pair(8, 98), Pair(4, 95), Pair(22, 76),
        Pair(58, 110), Pair(21, 48), Pair(15, 90), Pair(16, 78), Pair(29, 42), Pair(7, 49), Pair(1, 64), Pair(52, -3)
      },
      { // Piece 2
        Pair(-48, 64), Pair(-13, 28), Pair(53, 57), Pair(79, 28), Pair(-48, 57), Pair(144, 1), Pair(76, 37), Pair(-13, 61),
        Pair(20, 48), Pair(19, 54), Pair(-14, 33), Pair(103, 43), Pair(56, 33), Pair(31, 57), Pair(-30, 63), Pair(24, 40),
        Pair(-26, 80), Pair(31, 38), Pair(67, 48), Pair(-13, 44), Pair(-7, 63), Pair(44, 32), Pair(63, 42), Pair(-27, 70),
        Pair(48, 33), Pair(21, 64), Pair(19, 50), Pair(-7, 60), Pair(-4, 68), Pair(48, 63), Pair(-6, 52), Pair(19, 37),
        Pair(14, 48), Pair(14, 39), Pair(20, 74), Pair(12, 55), Pair(27, 71), Pair(-9, 94), Pair(26, 28), Pair(-154, -70),
        Pair(-1, 47), Pair(22, 50), Pair(9, 54), Pair(35, 75), Pair(6, 58), Pair(26, 70), Pair(0, 0), Pair(23, 56),
        Pair(27, 14), Pair(-4, 69), Pair(5, 56), Pair(-6, 46), Pair(37, 66), Pair(29, 49), Pair(40, 64), Pair(-11, -70),
        Pair(25, 70), Pair(38, 58), Pair(7, 41), Pair(-15, 86), Pair(-37, 32), Pair(19, 73), Pair(20, 38), Pair(29, 0)
      },
      { // Piece 3
        Pair(52, 75), Pair(-16, 90), Pair(-2, 87), Pair(-14, 76), Pair(-49, 108), Pair(-77, 108), Pair(15, 45), Pair(-12, 79),
        Pair(16, 88), Pair(23, 80), Pair(23, 86), Pair(35, 81), Pair(-17, 98), Pair(8, 82), Pair(-2, 55), Pair(54, 62),
        Pair(-26, 112), Pair(21, 95), Pair(10, 88), Pair(42, 76), Pair(1, 100), Pair(32, 81), Pair(104, 48), Pair(-10, 90),
        Pair(31, 82), Pair(13, 85), Pair(17, 86), Pair(46, 76), Pair(13, 89), Pair(-1, 88), Pair(38, 40), Pair(-20, 96),
        Pair(18, 69), Pair(-2, 89), Pair(2, 88), Pair(33, 78), Pair(12, 102), Pair(38, 90), Pair(-12, 89), Pair(-6, 102),
        Pair(36, 71), Pair(5, 83), Pair(13, 83), Pair(55, 62), Pair(13, 86), Pair(1, 72), Pair(0, 0), Pair(-25, 58),
        Pair(30, 91), Pair(11, 88), Pair(6, 95), Pair(15, 94), Pair(18, 94), Pair(5, 96), Pair(-28, 50), Pair(-36, 84),
        Pair(17, 84), Pair(28, 75), Pair(24, 74), Pair(5, 85), Pair(23, 84), Pair(11, 75), Pair(-38, 55), Pair(-5, 70)
      },
      { // Piece 4
        Pair(23, 122), Pair(37, 57), Pair(85, 111), Pair(15, 153), Pair(-48, 149), Pair(12, 133), Pair(28, 169), Pair(-22, 107),
        Pair(-2, 144), Pair(30, 92), Pair(36, 100), Pair(57, 108), Pair(22, 115), Pair(-14, 209), Pair(2, 189), Pair(-29, 175),
        Pair(37, 102), Pair(102, 64), Pair(47, 124), Pair(16, 146), Pair(22, 169), Pair(8, 169), Pair(13, 140), Pair(-20, 182),
        Pair(32, 150), Pair(16, 160), Pair(12, 170), Pair(18, 160), Pair(-10, 132), Pair(5, 168), Pair(0, 166), Pair(10, 154),
        Pair(41, 147), Pair(31, 173), Pair(29, 143), Pair(16, 159), Pair(-2, 172), Pair(-1, 160), Pair(21, 121), Pair(-10, 145),
        Pair(32, 118), Pair(28, 156), Pair(22, 135), Pair(32, 166), Pair(29, 137), Pair(24, 131), Pair(0, 0), Pair(-58, 240),
        Pair(18, 217), Pair(32, 149), Pair(31, 177), Pair(39, 156), Pair(38, 138), Pair(35, 83), Pair(-10, 179), Pair(77, 6),
        Pair(29, 115), Pair(41, 169), Pair(59, 132), Pair(42, 145), Pair(29, 132), Pair(-39, 221), Pair(-52, 128), Pair(-18, 191)
      },
      { // Piece 5
        Pair(-34, -32), Pair(-5, 22), Pair(14, 60), Pair(-50, 49), Pair(-93, 26), Pair(-149, 51), Pair(24, -7), Pair(-84, 127),
        Pair(-74, -24), Pair(-51, 53), Pair(-54, -8), Pair(-107, 14), Pair(-146, 65), Pair(-214, 69), Pair(-97, 56), Pair(7, 35),
        Pair(-171, 57), Pair(43, 26), Pair(-23, 14), Pair(-18, 8), Pair(-25, 54), Pair(-57, 44), Pair(-10, 53), Pair(6, 26),
        Pair(-40, 40), Pair(-101, 60), Pair(52, 2), Pair(-22, 40), Pair(-25, 27), Pair(21, 31), Pair(143, 2), Pair(-21, 81),
        Pair(-175, 60), Pair(-21, 8), Pair(-17, 29), Pair(-85, 45), Pair(-28, 28), Pair(30, -19), Pair(51, -13), Pair(28, -24),
        Pair(-27, 25), Pair(-125, 35), Pair(-49, 22), Pair(-14, 22), Pair(9, 14), Pair(-21, 5), Pair(0, 0), Pair(58, -37),
        Pair(-3, -21), Pair(-40, 18), Pair(-66, 20), Pair(-63, 25), Pair(-23, 10), Pair(-20, 3), Pair(15, -2), Pair(-8, -8),
        Pair(-82, 57), Pair(-62, 4), Pair(-38, 12), Pair(-28, -2), Pair(7, -15), Pair(-10, 6), Pair(21, -7), Pair(-32, 10)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(40, 10), Pair(-26, 26), Pair(-9, 21), Pair(17, 22), Pair(1, 16), Pair(-27, 4), Pair(-3, 39), Pair(7, -58),
        Pair(8, 13), Pair(-25, 35), Pair(2, 19), Pair(-3, 11), Pair(-25, 13), Pair(-15, 12), Pair(3, 55), Pair(6, -5),
        Pair(-2, 25), Pair(-5, 19), Pair(1, 10), Pair(0, 11), Pair(-2, 12), Pair(-8, 8), Pair(-3, 31), Pair(7, -2),
        Pair(-3, 16), Pair(2, 24), Pair(2, 19), Pair(-4, 17), Pair(0, 12), Pair(0, 1), Pair(15, 19), Pair(2, 6),
        Pair(1, 19), Pair(-3, 16), Pair(-2, 14), Pair(1, 16), Pair(5, 14), Pair(2, 4), Pair(1, 16), Pair(5, -20),
        Pair(-3, 22), Pair(-5, 16), Pair(-1, 28), Pair(-3, 17), Pair(2, 11), Pair(-6, 14), Pair(13, 37), Pair(-5, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-73, 21), Pair(32, 62), Pair(-69, 116), Pair(-119, 58), Pair(29, -10), Pair(-29, 73), Pair(5, 112), Pair(-76, 2),
        Pair(-27, 121), Pair(-8, 42), Pair(20, 63), Pair(136, -5), Pair(-60, 99), Pair(43, 36), Pair(-58, 96), Pair(40, 61),
        Pair(2, 66), Pair(-32, 76), Pair(23, 47), Pair(33, 43), Pair(8, 61), Pair(31, 56), Pair(25, 37), Pair(13, 90),
        Pair(-15, 80), Pair(-2, 71), Pair(11, 52), Pair(-2, 88), Pair(3, 54), Pair(13, 70), Pair(41, 53), Pair(-7, 62),
        Pair(7, 71), Pair(12, 71), Pair(8, 55), Pair(16, 73), Pair(22, 73), Pair(22, 75), Pair(23, 64), Pair(19, 57),
        Pair(-6, 47), Pair(10, 56), Pair(4, 64), Pair(14, 62), Pair(19, 47), Pair(20, 55), Pair(12, 50), Pair(0, 0),
        Pair(0, 92), Pair(2, 92), Pair(-9, 82), Pair(8, 53), Pair(9, 69), Pair(1, 53), Pair(9, 58), Pair(21, 16),
        Pair(140, 60), Pair(2, 61), Pair(16, 26), Pair(7, 57), Pair(-14, 80), Pair(-3, 61), Pair(13, 61), Pair(-41, 105)
      },
      { // Piece 2
        Pair(-81, 53), Pair(148, 10), Pair(78, -17), Pair(41, 17), Pair(106, -18), Pair(36, 28), Pair(-66, 20), Pair(-43, 89),
        Pair(-30, 94), Pair(30, 12), Pair(-1, 60), Pair(107, -11), Pair(126, -1), Pair(78, 12), Pair(2, 53), Pair(4, 55),
        Pair(8, 35), Pair(14, 71), Pair(45, 8), Pair(29, 45), Pair(95, 16), Pair(68, 32), Pair(70, 27), Pair(24, 58),
        Pair(-17, 75), Pair(-6, 51), Pair(43, 47), Pair(26, 29), Pair(29, 50), Pair(22, 31), Pair(11, 67), Pair(7, 25),
        Pair(11, 52), Pair(8, 75), Pair(13, 53), Pair(24, 44), Pair(13, 37), Pair(7, 46), Pair(16, 10), Pair(30, 63),
        Pair(2, 50), Pair(25, 40), Pair(6, 57), Pair(16, 46), Pair(19, 72), Pair(27, 43), Pair(25, 86), Pair(0, 0),
        Pair(18, 47), Pair(12, 55), Pair(8, 26), Pair(6, 51), Pair(6, 57), Pair(48, 65), Pair(23, 36), Pair(29, 70),
        Pair(-16, 93), Pair(-2, 19), Pair(15, 37), Pair(-10, 40), Pair(37, 81), Pair(-4, 50), Pair(73, 72), Pair(-2, 37)
      },
      { // Piece 3
        Pair(26, 96), Pair(72, 53), Pair(66, 73), Pair(56, 59), Pair(29, 82), Pair(31, 60), Pair(93, 36), Pair(50, 30),
        Pair(24, 85), Pair(-9, 103), Pair(4, 98), Pair(36, 78), Pair(11, 86), Pair(40, 77), Pair(-39, 80), Pair(10, 44),
        Pair(22, 87), Pair(22, 100), Pair(11, 104), Pair(44, 73), Pair(6, 92), Pair(-3, 115), Pair(10, 86), Pair(-22, 77),
        Pair(35, 100), Pair(12, 104), Pair(27, 84), Pair(33, 88), Pair(-2, 105), Pair(28, 92), Pair(21, 89), Pair(-2, 75),
        Pair(24, 97), Pair(31, 103), Pair(29, 88), Pair(32, 92), Pair(27, 86), Pair(14, 97), Pair(14, 102), Pair(32, 63),
        Pair(26, 100), Pair(-14, 102), Pair(39, 89), Pair(21, 74), Pair(-12, 118), Pair(30, 97), Pair(1, 71), Pair(0, 0),
        Pair(1, 132), Pair(7, 124), Pair(6, 96), Pair(-3, 113), Pair(18, 95), Pair(14, 103), Pair(3, 77), Pair(-50, 53),
        Pair(20, 73), Pair(12, 95), Pair(23, 71), Pair(16, 77), Pair(7, 85), Pair(11, 89), Pair(-18, 76), Pair(-38, 42)
      },
      { // Piece 4
        Pair(67, 164), Pair(64, 140), Pair(20, 209), Pair(-66, 260), Pair(48, 142), Pair(60, 179), Pair(-34, 199), Pair(80, 218),
        Pair(6, 246), Pair(-13, 225), Pair(11, 211), Pair(12, 216), Pair(52, 167), Pair(18, 168), Pair(39, 211), Pair(-16, 236),
        Pair(37, 179), Pair(-10, 236), Pair(16, 188), Pair(3, 232), Pair(-19, 191), Pair(51, 178), Pair(63, 183), Pair(36, 183),
        Pair(36, 174), Pair(25, 206), Pair(20, 188), Pair(53, 175), Pair(12, 179), Pair(15, 219), Pair(22, 219), Pair(23, 176),
        Pair(26, 185), Pair(10, 203), Pair(29, 202), Pair(20, 181), Pair(19, 208), Pair(8, 211), Pair(23, 193), Pair(-6, 242),
        Pair(5, 188), Pair(24, 207), Pair(16, 223), Pair(35, 150), Pair(24, 183), Pair(36, 184), Pair(41, 199), Pair(0, 0),
        Pair(27, 151), Pair(44, 209), Pair(23, 211), Pair(23, 228), Pair(44, 176), Pair(41, 144), Pair(48, 174), Pair(32, 122),
        Pair(30, 157), Pair(60, 129), Pair(29, 219), Pair(40, 169), Pair(30, 188), Pair(27, 182), Pair(13, 167), Pair(77, 34)
      },
      { // Piece 5
        Pair(64, 7), Pair(-187, 48), Pair(55, 4), Pair(-20, 26), Pair(-36, 7), Pair(64, 163), Pair(4, 151), Pair(-46, 80),
        Pair(99, 10), Pair(-151, 0), Pair(32, 23), Pair(17, 39), Pair(-145, 39), Pair(123, 97), Pair(42, 94), Pair(-161, 62),
        Pair(60, -14), Pair(-71, 41), Pair(-150, 85), Pair(4, 12), Pair(-10, 47), Pair(88, 48), Pair(11, 5), Pair(-106, 74),
        Pair(-152, 80), Pair(22, 29), Pair(-54, 59), Pair(45, 20), Pair(-79, 44), Pair(145, -11), Pair(68, 27), Pair(112, 3),
        Pair(-79, 16), Pair(-30, 30), Pair(5, 25), Pair(-51, 49), Pair(41, 15), Pair(9, 16), Pair(21, -17), Pair(33, -37),
        Pair(-34, 11), Pair(-89, 54), Pair(-60, 33), Pair(-18, 38), Pair(-21, 17), Pair(27, -8), Pair(13, -19), Pair(0, 0),
        Pair(-22, 18), Pair(-50, 28), Pair(-35, 26), Pair(-17, 21), Pair(4, 3), Pair(6, 2), Pair(-46, -1), Pair(0, -24),
        Pair(-4, -44), Pair(-33, -3), Pair(-30, 8), Pair(-37, 26), Pair(0, -22), Pair(-15, 3), Pair(9, -10), Pair(22, -36)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, 34), Pair(-16, 32), Pair(-10, 25), Pair(20, 7), Pair(-16, 37), Pair(33, 18), Pair(-5, 42), Pair(-24, 32),
        Pair(3, 23), Pair(0, 27), Pair(-7, 18), Pair(-10, 18), Pair(-16, 25), Pair(3, 19), Pair(0, 14), Pair(-10, 16),
        Pair(-7, 4), Pair(-4, 31), Pair(-6, 7), Pair(-1, 5), Pair(-5, 19), Pair(-6, 23), Pair(-7, 17), Pair(0, 9),
        Pair(13, 7), Pair(-6, 34), Pair(1, 4), Pair(3, 10), Pair(0, 16), Pair(5, 13), Pair(0, 19), Pair(-5, 24),
        Pair(-4, 8), Pair(6, 33), Pair(-1, 1), Pair(3, 18), Pair(6, 8), Pair(-1, 19), Pair(4, 26), Pair(-3, 23),
        Pair(-2, 12), Pair(-6, 14), Pair(-10, 13), Pair(1, 13), Pair(4, 22), Pair(-3, 25), Pair(1, 26), Pair(-1, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-200, 89), Pair(-151, 110), Pair(70, 84), Pair(-197, 119), Pair(84, 98), Pair(-22, 116), Pair(18, 94), Pair(-63, 93),
        Pair(-6, 35), Pair(-71, 92), Pair(15, 114), Pair(-91, 132), Pair(-9, 126), Pair(12, 92), Pair(-55, 112), Pair(-12, 76),
        Pair(18, 97), Pair(-16, 71), Pair(17, 84), Pair(17, 96), Pair(-21, 100), Pair(30, 99), Pair(15, 108), Pair(-43, 91),
        Pair(-43, 89), Pair(18, 78), Pair(-15, 89), Pair(8, 88), Pair(4, 91), Pair(2, 112), Pair(0, 105), Pair(-1, 83),
        Pair(6, 81), Pair(2, 104), Pair(-6, 83), Pair(8, 88), Pair(3, 98), Pair(15, 78), Pair(12, 87), Pair(-7, 98),
        Pair(-5, 53), Pair(19, 64), Pair(19, 82), Pair(3, 90), Pair(8, 95), Pair(4, 86), Pair(14, 67), Pair(-3, 88),
        Pair(0, 0), Pair(12, 42), Pair(0, 106), Pair(-2, 92), Pair(18, 87), Pair(1, 74), Pair(-15, 75), Pair(9, 79),
        Pair(-81, 7), Pair(54, 61), Pair(-27, 133), Pair(19, 87), Pair(-5, 110), Pair(36, 64), Pair(-4, 84), Pair(-95, 104)
      },
      { // Piece 2
        Pair(-58, 76), Pair(58, 19), Pair(-84, 113), Pair(125, 30), Pair(49, 64), Pair(1, 56), Pair(33, -1), Pair(-39, -10),
        Pair(-10, 101), Pair(1, 91), Pair(26, 56), Pair(41, 48), Pair(56, 26), Pair(75, 20), Pair(48, 17), Pair(-23, 47),
        Pair(18, 73), Pair(52, 62), Pair(28, 65), Pair(31, 52), Pair(26, 50), Pair(11, 49), Pair(45, 66), Pair(-11, 93),
        Pair(-17, 117), Pair(14, 72), Pair(8, 94), Pair(18, 81), Pair(12, 54), Pair(5, 64), Pair(21, 62), Pair(13, 67),
        Pair(9, 54), Pair(33, 78), Pair(20, 63), Pair(11, 90), Pair(7, 75), Pair(20, 59), Pair(30, 94), Pair(21, 56),
        Pair(1, 65), Pair(27, 97), Pair(11, 79), Pair(13, 77), Pair(14, 93), Pair(10, 92), Pair(12, 80), Pair(18, 52),
        Pair(0, 0), Pair(13, 63), Pair(29, 70), Pair(19, 74), Pair(17, 77), Pair(8, 114), Pair(18, 81), Pair(-3, 45),
        Pair(29, 62), Pair(23, 81), Pair(-1, 104), Pair(0, 99), Pair(12, 97), Pair(9, 78), Pair(24, 50), Pair(22, 87)
      },
      { // Piece 3
        Pair(30, 84), Pair(8, 137), Pair(-57, 145), Pair(-3, 137), Pair(-35, 164), Pair(63, 98), Pair(14, 109), Pair(-22, 141),
        Pair(-39, 96), Pair(-11, 117), Pair(-43, 154), Pair(-62, 153), Pair(-45, 131), Pair(-12, 123), Pair(-2, 131), Pair(-5, 130),
        Pair(-35, 124), Pair(-1, 123), Pair(-38, 136), Pair(34, 121), Pair(-49, 174), Pair(-16, 134), Pair(-17, 146), Pair(-45, 158),
        Pair(-56, 131), Pair(-40, 146), Pair(-26, 141), Pair(-35, 153), Pair(19, 122), Pair(-46, 147), Pair(-2, 105), Pair(0, 147),
        Pair(-29, 116), Pair(-31, 149), Pair(10, 129), Pair(-15, 153), Pair(17, 132), Pair(-10, 136), Pair(-11, 138), Pair(13, 131),
        Pair(-5, 71), Pair(5, 136), Pair(-24, 163), Pair(3, 133), Pair(-25, 143), Pair(-11, 127), Pair(-5, 143), Pair(28, 87),
        Pair(0, 0), Pair(-6, 120), Pair(-16, 149), Pair(-22, 157), Pair(2, 144), Pair(-7, 168), Pair(-25, 141), Pair(10, 190),
        Pair(-40, 79), Pair(-25, 128), Pair(-11, 120), Pair(-8, 135), Pair(-3, 127), Pair(-3, 123), Pair(-5, 128), Pair(-9, 121)
      },
      { // Piece 4
        Pair(-8, 248), Pair(-68, 356), Pair(-26, 332), Pair(47, 256), Pair(128, 220), Pair(90, 192), Pair(85, 187), Pair(13, 283),
        Pair(-13, 299), Pair(-14, 322), Pair(-6, 300), Pair(-23, 332), Pair(33, 299), Pair(65, 243), Pair(66, 241), Pair(21, 263),
        Pair(-25, 284), Pair(25, 272), Pair(10, 254), Pair(22, 260), Pair(14, 333), Pair(8, 263), Pair(27, 290), Pair(5, 292),
        Pair(23, 254), Pair(9, 273), Pair(4, 334), Pair(11, 300), Pair(33, 238), Pair(9, 306), Pair(28, 256), Pair(25, 235),
        Pair(22, 256), Pair(-18, 325), Pair(24, 280), Pair(-2, 294), Pair(17, 298), Pair(10, 308), Pair(13, 271), Pair(67, 195),
        Pair(8, 245), Pair(23, 247), Pair(16, 279), Pair(34, 250), Pair(28, 255), Pair(26, 276), Pair(0, 338), Pair(15, 255),
        Pair(0, 0), Pair(31, 264), Pair(26, 264), Pair(23, 287), Pair(29, 261), Pair(36, 243), Pair(9, 281), Pair(101, 136),
        Pair(-63, 368), Pair(1, 270), Pair(31, 222), Pair(16, 258), Pair(44, 253), Pair(25, 222), Pair(-11, 256), Pair(4, 247)
      },
      { // Piece 5
        Pair(-48, 70), Pair(-42, 50), Pair(12, 64), Pair(95, 50), Pair(-1, -100), Pair(127, 121), Pair(41, 163), Pair(-94, 9),
        Pair(8, 44), Pair(-26, 96), Pair(-70, 119), Pair(53, 71), Pair(-141, 99), Pair(4, 27), Pair(-94, 68), Pair(-50, 36),
        Pair(-81, 69), Pair(73, 14), Pair(123, 34), Pair(-93, 117), Pair(25, 56), Pair(-283, 118), Pair(-52, -8), Pair(-68, 69),
        Pair(-163, 52), Pair(25, 32), Pair(-123, 76), Pair(-15, 40), Pair(-27, 57), Pair(-23, 21), Pair(-242, 68), Pair(-191, 49),
        Pair(-79, 17), Pair(20, 33), Pair(-44, 46), Pair(-31, 51), Pair(0, 35), Pair(-60, 37), Pair(-50, 20), Pair(-85, 43),
        Pair(-71, 8), Pair(-39, -21), Pair(1, 23), Pair(39, 26), Pair(-11, 20), Pair(-67, 39), Pair(-41, 25), Pair(-39, 9),
        Pair(0, 0), Pair(-11, -16), Pair(25, 0), Pair(-8, 33), Pair(-9, 16), Pair(-29, 23), Pair(-24, 14), Pair(-30, 13),
        Pair(11, -62), Pair(21, -37), Pair(49, -21), Pair(-14, 5), Pair(11, -6), Pair(-23, 16), Pair(-11, -1), Pair(-18, -8)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-54, 60), Pair(0, 32), Pair(36, -8), Pair(75, -17), Pair(22, -11), Pair(27, -6), Pair(3, 4), Pair(11, 17),
        Pair(-6, 20), Pair(6, 30), Pair(15, 20), Pair(-11, 22), Pair(-7, 15), Pair(-16, 8), Pair(8, -1), Pair(1, 19),
        Pair(-15, 29), Pair(14, 29), Pair(0, 21), Pair(0, 13), Pair(2, 16), Pair(4, 12), Pair(1, 14), Pair(-2, 9),
        Pair(-7, 24), Pair(11, 35), Pair(7, 30), Pair(-1, 19), Pair(4, 13), Pair(6, 12), Pair(8, 14), Pair(0, 17),
        Pair(-1, 26), Pair(19, 4), Pair(15, 31), Pair(0, 10), Pair(0, 20), Pair(4, 17), Pair(5, 21), Pair(4, 20),
        Pair(-6, 18), Pair(11, 25), Pair(3, 18), Pair(-9, 6), Pair(3, 30), Pair(2, 22), Pair(1, 26), Pair(4, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(26, -74), Pair(-126, 156), Pair(2, 70), Pair(30, -20), Pair(3, 94), Pair(-45, 80), Pair(58, 105), Pair(-222, 163),
        Pair(14, 13), Pair(54, 11), Pair(-9, 58), Pair(-41, 98), Pair(-26, 109), Pair(-34, 85), Pair(-57, 78), Pair(18, 64),
        Pair(-36, 69), Pair(21, 55), Pair(16, 57), Pair(-18, 82), Pair(-23, 87), Pair(2, 79), Pair(-20, 106), Pair(30, 31),
        Pair(19, 59), Pair(2, 60), Pair(6, 76), Pair(-6, 82), Pair(0, 100), Pair(2, 75), Pair(11, 87), Pair(-20, 100),
        Pair(13, 48), Pair(10, 51), Pair(22, 72), Pair(3, 75), Pair(-4, 90), Pair(14, 78), Pair(-5, 71), Pair(9, 83),
        Pair(16, 61), Pair(4, 53), Pair(24, 89), Pair(3, 83), Pair(-4, 87), Pair(11, 88), Pair(4, 85), Pair(13, 57),
        Pair(3, 72), Pair(0, 0), Pair(19, 104), Pair(5, 72), Pair(5, 78), Pair(12, 55), Pair(12, 119), Pair(34, 61),
        Pair(-5, 130), Pair(2, 76), Pair(15, 71), Pair(-1, 75), Pair(3, 98), Pair(19, 65), Pair(8, 75), Pair(-17, 64)
      },
      { // Piece 2
        Pair(-42, 85), Pair(76, 54), Pair(107, 28), Pair(64, 52), Pair(72, -3), Pair(-64, 26), Pair(60, -11), Pair(15, 84),
        Pair(-34, 73), Pair(-21, 51), Pair(32, 64), Pair(78, 7), Pair(31, 12), Pair(-2, 34), Pair(68, 44), Pair(23, 57),
        Pair(16, 70), Pair(12, 43), Pair(9, 85), Pair(-3, 77), Pair(3, 47), Pair(24, 51), Pair(50, 12), Pair(11, 65),
        Pair(-22, 75), Pair(25, 41), Pair(17, 68), Pair(-7, 70), Pair(-7, 81), Pair(22, 36), Pair(11, 66), Pair(13, 75),
        Pair(5, 77), Pair(-24, 59), Pair(13, 76), Pair(6, 65), Pair(9, 73), Pair(7, 78), Pair(24, 81), Pair(9, 97),
        Pair(23, 44), Pair(29, 27), Pair(20, 112), Pair(4, 73), Pair(7, 85), Pair(13, 65), Pair(7, 67), Pair(6, 59),
        Pair(4, 102), Pair(0, 0), Pair(23, 48), Pair(-4, 82), Pair(19, 70), Pair(2, 89), Pair(8, 77), Pair(-19, 113),
        Pair(0, 0), Pair(51, 10), Pair(-16, 67), Pair(19, 72), Pair(9, 86), Pair(10, 70), Pair(66, 85), Pair(4, 88)
      },
      { // Piece 3
        Pair(-48, 127), Pair(-18, 69), Pair(37, 83), Pair(-39, 127), Pair(-56, 128), Pair(41, 94), Pair(32, 93), Pair(22, 82),
        Pair(-18, 109), Pair(11, 52), Pair(-18, 114), Pair(-18, 133), Pair(-29, 124), Pair(-40, 133), Pair(-12, 129), Pair(-14, 137),
        Pair(-27, 113), Pair(25, 79), Pair(25, 96), Pair(14, 91), Pair(23, 83), Pair(-23, 107), Pair(-16, 132), Pair(-24, 128),
        Pair(-34, 127), Pair(10, 102), Pair(-10, 119), Pair(-32, 116), Pair(-21, 118), Pair(-40, 123), Pair(-37, 133), Pair(-7, 114),
        Pair(-14, 111), Pair(17, 78), Pair(12, 100), Pair(12, 117), Pair(28, 103), Pair(-6, 101), Pair(-11, 139), Pair(-1, 111),
        Pair(-4, 108), Pair(-27, 82), Pair(13, 102), Pair(-28, 139), Pair(-14, 123), Pair(-21, 114), Pair(-16, 115), Pair(-9, 139),
        Pair(-35, 55), Pair(0, 0), Pair(-5, 116), Pair(-11, 150), Pair(-1, 117), Pair(-22, 137), Pair(13, 109), Pair(20, 116),
        Pair(-12, 90), Pair(-25, 54), Pair(-12, 113), Pair(-5, 115), Pair(-4, 106), Pair(-2, 103), Pair(6, 107), Pair(5, 106)
      },
      { // Piece 4
        Pair(31, 179), Pair(-13, 220), Pair(35, 198), Pair(-8, 178), Pair(53, 181), Pair(-1, 243), Pair(-31, 194), Pair(0, 131),
        Pair(16, 148), Pair(26, 169), Pair(16, 183), Pair(-29, 214), Pair(-26, 181), Pair(-11, 186), Pair(-6, 191), Pair(14, 250),
        Pair(6, 165), Pair(9, 172), Pair(21, 146), Pair(-1, 254), Pair(-9, 230), Pair(32, 184), Pair(4, 217), Pair(-39, 256),
        Pair(22, 188), Pair(6, 196), Pair(-18, 240), Pair(28, 186), Pair(-10, 231), Pair(-6, 219), Pair(1, 151), Pair(7, 209),
        Pair(-5, 242), Pair(-21, 229), Pair(11, 204), Pair(6, 172), Pair(14, 211), Pair(1, 198), Pair(-4, 258), Pair(6, 203),
        Pair(-8, 223), Pair(3, 195), Pair(13, 217), Pair(14, 199), Pair(2, 205), Pair(25, 174), Pair(5, 198), Pair(16, 274),
        Pair(5, 196), Pair(0, 0), Pair(10, 198), Pair(20, 168), Pair(23, 178), Pair(19, 202), Pair(31, 209), Pair(-8, 215),
        Pair(-20, 170), Pair(27, 31), Pair(-11, 254), Pair(7, 181), Pair(16, 163), Pair(14, 210), Pair(-4, 175), Pair(34, 184)
      },
      { // Piece 5
        Pair(-40, 27), Pair(45, 13), Pair(-185, -33), Pair(-65, -11), Pair(66, 65), Pair(-25, -22), Pair(-26, -14), Pair(-37, 28),
        Pair(58, 36), Pair(46, 55), Pair(-86, 45), Pair(88, -20), Pair(19, 21), Pair(-162, 91), Pair(-56, -13), Pair(-168, -37),
        Pair(-180, 56), Pair(-24, 41), Pair(140, 59), Pair(-84, 23), Pair(-55, 42), Pair(-62, 42), Pair(-61, 83), Pair(-16, -4),
        Pair(26, 86), Pair(32, 59), Pair(-31, 64), Pair(23, 72), Pair(-23, 30), Pair(-103, 56), Pair(-64, 13), Pair(-129, 33),
        Pair(-26, 52), Pair(94, 10), Pair(26, 32), Pair(2, 23), Pair(-17, 30), Pair(-30, 20), Pair(-6, -1), Pair(-148, 73),
        Pair(103, -30), Pair(-8, -2), Pair(-44, 13), Pair(55, 1), Pair(-33, 36), Pair(-9, 6), Pair(-31, 26), Pair(-11, 19),
        Pair(94, -22), Pair(0, 0), Pair(1, 1), Pair(11, 4), Pair(11, 19), Pair(-21, 22), Pair(-26, 13), Pair(-33, 16),
        Pair(91, -44), Pair(75, -14), Pair(39, -12), Pair(-4, 28), Pair(14, 15), Pair(1, 3), Pair(-8, 3), Pair(-6, -4)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-49, 29), Pair(-36, 33), Pair(-8, -12), Pair(2, -14), Pair(-5, 1), Pair(-18, -1), Pair(-28, 42), Pair(-34, 13),
        Pair(-13, 23), Pair(-27, 36), Pair(-7, 2), Pair(-5, 21), Pair(-11, 5), Pair(3, 5), Pair(-5, 16), Pair(-12, 13),
        Pair(-3, 16), Pair(-8, 29), Pair(-7, 4), Pair(0, 27), Pair(-1, 9), Pair(-1, 13), Pair(-4, 13), Pair(-9, 20),
        Pair(-3, 18), Pair(1, 23), Pair(-9, 1), Pair(8, 25), Pair(2, 9), Pair(6, 16), Pair(-1, 23), Pair(-8, 23),
        Pair(-4, 11), Pair(7, 34), Pair(-10, -6), Pair(8, 46), Pair(-7, 19), Pair(2, 12), Pair(3, 23), Pair(-8, 21),
        Pair(-8, 13), Pair(2, 16), Pair(1, 3), Pair(-1, 28), Pair(-2, 14), Pair(2, 18), Pair(-1, 28), Pair(-7, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-91, 41), Pair(57, 90), Pair(-61, 133), Pair(235, 24), Pair(45, 28), Pair(-33, 119), Pair(-36, 37), Pair(-15, -49),
        Pair(-23, 80), Pair(-39, 79), Pair(15, 72), Pair(28, 84), Pair(-10, 58), Pair(35, 48), Pair(3, 91), Pair(13, 76),
        Pair(-14, 125), Pair(16, 26), Pair(6, 87), Pair(-25, 102), Pair(-49, 109), Pair(-22, 86), Pair(-16, 75), Pair(33, 34),
        Pair(-1, 64), Pair(-13, 95), Pair(-31, 108), Pair(-2, 91), Pair(-15, 84), Pair(8, 86), Pair(4, 95), Pair(3, 79),
        Pair(-1, 81), Pair(2, 109), Pair(0, 76), Pair(1, 86), Pair(-2, 81), Pair(5, 76), Pair(-3, 81), Pair(6, 58),
        Pair(7, 42), Pair(8, 85), Pair(-4, 67), Pair(0, 93), Pair(29, 85), Pair(0, 72), Pair(-7, 105), Pair(5, 67),
        Pair(-19, 100), Pair(-3, 64), Pair(0, 0), Pair(2, 101), Pair(-1, 93), Pair(14, 87), Pair(15, 88), Pair(1, 75),
        Pair(76, -4), Pair(-3, 69), Pair(18, 74), Pair(15, 64), Pair(12, 39), Pair(34, 85), Pair(-1, 94), Pair(60, 156)
      },
      { // Piece 2
        Pair(58, 6), Pair(-11, 62), Pair(6, 28), Pair(102, 42), Pair(170, 37), Pair(2, 74), Pair(65, 28), Pair(11, 4),
        Pair(-17, 71), Pair(-35, 90), Pair(-36, 51), Pair(57, 66), Pair(16, 34), Pair(28, 40), Pair(-28, 81), Pair(1, -23),
        Pair(-35, 64), Pair(-17, 93), Pair(17, 52), Pair(-10, 66), Pair(41, 16), Pair(-5, 47), Pair(-13, 44), Pair(-13, 97),
        Pair(-35, 70), Pair(-9, 61), Pair(18, 73), Pair(11, 80), Pair(-4, 59), Pair(0, 34), Pair(18, 52), Pair(-3, 76),
        Pair(-13, 77), Pair(25, 24), Pair(-4, 44), Pair(26, 64), Pair(-4, 66), Pair(6, 65), Pair(-6, 59), Pair(6, 51),
        Pair(-7, 92), Pair(8, 32), Pair(20, 24), Pair(3, 104), Pair(5, 64), Pair(10, 43), Pair(15, 46), Pair(-3, 63),
        Pair(7, -40), Pair(17, 76), Pair(0, 0), Pair(6, 56), Pair(-2, 79), Pair(-3, 72), Pair(1, 60), Pair(-1, 70),
        Pair(32, 11), Pair(90, -249), Pair(3, 70), Pair(-33, 13), Pair(-25, 76), Pair(-5, 71), Pair(14, 64), Pair(25, 91)
      },
      { // Piece 3
        Pair(3, 101), Pair(-28, 81), Pair(-61, 83), Pair(30, 74), Pair(42, 70), Pair(89, 69), Pair(2, 103), Pair(35, 82),
        Pair(-28, 91), Pair(-25, 113), Pair(-77, 101), Pair(-31, 123), Pair(-13, 73), Pair(-32, 120), Pair(16, 77), Pair(-11, 112),
        Pair(-42, 113), Pair(-50, 111), Pair(-41, 100), Pair(6, 67), Pair(-32, 113), Pair(-15, 100), Pair(-14, 86), Pair(46, 91),
        Pair(-3, 107), Pair(-26, 105), Pair(-12, 94), Pair(-12, 98), Pair(-20, 111), Pair(-8, 119), Pair(-20, 109), Pair(-11, 100),
        Pair(5, 83), Pair(-12, 104), Pair(35, 56), Pair(5, 99), Pair(-32, 111), Pair(0, 107), Pair(1, 102), Pair(4, 100),
        Pair(-7, 67), Pair(-21, 106), Pair(8, 74), Pair(-8, 90), Pair(-32, 115), Pair(-34, 83), Pair(-6, 90), Pair(-7, 109),
        Pair(-19, 38), Pair(-32, 74), Pair(0, 0), Pair(-9, 98), Pair(-10, 103), Pair(4, 85), Pair(2, 49), Pair(5, 105),
        Pair(-15, 83), Pair(-16, 98), Pair(-15, -7), Pair(-17, 103), Pair(-15, 94), Pair(-6, 86), Pair(0, 88), Pair(-3, 98)
      },
      { // Piece 4
        Pair(18, 194), Pair(42, 223), Pair(46, 167), Pair(55, 134), Pair(14, 197), Pair(-6, 170), Pair(69, 136), Pair(4, 197),
        Pair(10, 222), Pair(1, 199), Pair(-11, 198), Pair(-4, 175), Pair(-36, 208), Pair(42, 182), Pair(-28, 229), Pair(14, 115),
        Pair(12, 129), Pair(30, 182), Pair(31, 155), Pair(-14, 200), Pair(7, 187), Pair(-7, 224), Pair(51, 85), Pair(-14, 230),
        Pair(40, 145), Pair(5, 169), Pair(18, 163), Pair(10, 159), Pair(-28, 266), Pair(13, 164), Pair(15, 132), Pair(1, 191),
        Pair(-13, 222), Pair(9, 179), Pair(11, 185), Pair(14, 165), Pair(21, 166), Pair(15, 175), Pair(-7, 167), Pair(37, 114),
        Pair(9, 123), Pair(-4, 169), Pair(14, 154), Pair(17, 181), Pair(9, 167), Pair(9, 185), Pair(19, 166), Pair(24, 166),
        Pair(-17, 145), Pair(8, 142), Pair(0, 0), Pair(7, 199), Pair(11, 182), Pair(25, 146), Pair(20, 180), Pair(43, 182),
        Pair(2, 116), Pair(-4, 139), Pair(9, 49), Pair(-5, 168), Pair(17, 153), Pair(-7, 234), Pair(21, 115), Pair(42, 92)
      },
      { // Piece 5
        Pair(-2, -131), Pair(39, 86), Pair(38, 6), Pair(-1, -57), Pair(61, 61), Pair(3, 80), Pair(67, 57), Pair(42, 27),
        Pair(-53, 17), Pair(-110, 83), Pair(-89, 62), Pair(-33, 33), Pair(59, -7), Pair(-20, 44), Pair(-55, 12), Pair(-89, 48),
        Pair(-147, 67), Pair(16, 54), Pair(-41, 27), Pair(16, 68), Pair(92, 67), Pair(-95, 17), Pair(-86, 43), Pair(-141, -30),
        Pair(-47, -9), Pair(-163, 60), Pair(28, 49), Pair(-8, 60), Pair(-195, 87), Pair(-134, 46), Pair(-239, 55), Pair(-128, 56),
        Pair(-37, 32), Pair(66, 20), Pair(-11, 14), Pair(-25, 38), Pair(-34, 17), Pair(-10, 41), Pair(-43, 14), Pair(24, -20),
        Pair(112, 8), Pair(-17, -3), Pair(-61, 11), Pair(-40, 12), Pair(-6, 8), Pair(-28, 38), Pair(-13, 13), Pair(-9, 15),
        Pair(73, -44), Pair(40, -9), Pair(0, 0), Pair(-45, 18), Pair(7, -10), Pair(-7, 13), Pair(-7, -7), Pair(-7, 2),
        Pair(17, 0), Pair(7, -2), Pair(-4, 11), Pair(-41, -5), Pair(10, 0), Pair(-4, 1), Pair(-1, -16), Pair(0, -8)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 59), Pair(-46, 25), Pair(-21, -5), Pair(32, -44), Pair(-45, 78), Pair(-71, 66), Pair(-48, 3), Pair(6, 9),
        Pair(-8, 27), Pair(-5, 31), Pair(-16, 4), Pair(-9, 18), Pair(1, 20), Pair(-3, 19), Pair(4, -18), Pair(-13, 20),
        Pair(-11, 14), Pair(-7, 15), Pair(-1, 19), Pair(-7, 15), Pair(-3, 18), Pair(2, 9), Pair(-12, 14), Pair(-5, 7),
        Pair(-5, 16), Pair(-14, 20), Pair(5, 27), Pair(-3, 5), Pair(8, 37), Pair(3, 15), Pair(1, 9), Pair(-7, 16),
        Pair(-2, 25), Pair(-10, 20), Pair(14, 39), Pair(-18, -23), Pair(21, 47), Pair(-8, 14), Pair(8, 6), Pair(-4, 17),
        Pair(0, 15), Pair(-11, 9), Pair(-1, 24), Pair(-4, -8), Pair(12, 36), Pair(-5, 6), Pair(5, 11), Pair(0, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(4, 94), Pair(-142, -37), Pair(34, -14), Pair(-29, 23), Pair(17, 45), Pair(-42, 72), Pair(-80, 5), Pair(-10, -12),
        Pair(-22, -34), Pair(-82, 36), Pair(19, 10), Pair(-65, 121), Pair(75, -54), Pair(-5, 77), Pair(-56, 124), Pair(-3, 71),
        Pair(46, -27), Pair(-60, 117), Pair(-43, 51), Pair(-16, 68), Pair(-12, 82), Pair(24, 66), Pair(-17, 88), Pair(15, 12),
        Pair(-39, 55), Pair(-12, 64), Pair(0, 88), Pair(-40, 101), Pair(4, 57), Pair(-1, 78), Pair(4, 115), Pair(-25, 101),
        Pair(-18, 96), Pair(-60, 59), Pair(-7, 73), Pair(-3, 72), Pair(-1, 99), Pair(-3, 52), Pair(31, 22), Pair(10, 83),
        Pair(10, 17), Pair(-16, 44), Pair(5, 66), Pair(-15, 21), Pair(4, 72), Pair(16, 65), Pair(2, 72), Pair(16, 74),
        Pair(28, 80), Pair(-39, 81), Pair(20, 35), Pair(0, 0), Pair(9, 72), Pair(13, 73), Pair(-19, 47), Pair(63, -30),
        Pair(5, 137), Pair(4, -8), Pair(24, 15), Pair(-7, 49), Pair(4, 36), Pair(17, 12), Pair(17, 41), Pair(-58, 79)
      },
      { // Piece 2
        Pair(-23, 59), Pair(64, 13), Pair(-132, 56), Pair(-254, 14), Pair(-127, 61), Pair(75, -40), Pair(-94, 61), Pair(23, 33),
        Pair(-72, 8), Pair(19, 42), Pair(30, 79), Pair(-21, 44), Pair(80, 17), Pair(-41, 79), Pair(-31, 72), Pair(-82, 122),
        Pair(22, 93), Pair(12, 34), Pair(14, 64), Pair(18, 51), Pair(5, 93), Pair(-18, 65), Pair(-15, -20), Pair(-53, 136),
        Pair(20, 46), Pair(-1, 52), Pair(-21, 59), Pair(-28, 85), Pair(2, 54), Pair(2, 33), Pair(18, 25), Pair(-12, 30),
        Pair(14, 15), Pair(-62, 74), Pair(-12, 61), Pair(-11, 40), Pair(24, 32), Pair(17, 59), Pair(-25, 76), Pair(20, 31),
        Pair(-17, 46), Pair(11, 25), Pair(6, 82), Pair(-28, 40), Pair(50, 96), Pair(-10, 61), Pair(-31, 139), Pair(-8, 65),
        Pair(15, 62), Pair(-5, 45), Pair(7, 52), Pair(0, 0), Pair(4, 54), Pair(-41, 76), Pair(2, 39), Pair(59, 61),
        Pair(-6, 68), Pair(5, 74), Pair(-15, -50), Pair(-39, 68), Pair(-85, -26), Pair(-1, 59), Pair(52, 60), Pair(-35, 17)
      },
      { // Piece 3
        Pair(3, 86), Pair(25, 33), Pair(131, 17), Pair(11, 34), Pair(39, 118), Pair(50, 44), Pair(-131, 127), Pair(-2, 126),
        Pair(-44, 110), Pair(7, 60), Pair(-33, 65), Pair(56, 31), Pair(-9, 78), Pair(-24, 80), Pair(-39, 80), Pair(-9, 102),
        Pair(-21, 83), Pair(26, 65), Pair(-22, 88), Pair(54, 5), Pair(-54, 130), Pair(44, 55), Pair(52, 62), Pair(7, 142),
        Pair(-4, 71), Pair(-16, 99), Pair(-15, 69), Pair(42, 21), Pair(-15, 67), Pair(29, 38), Pair(-44, 73), Pair(10, 106),
        Pair(-5, 105), Pair(-31, 87), Pair(15, 59), Pair(-39, 134), Pair(2, 90), Pair(-13, 106), Pair(-14, 93), Pair(-23, 117),
        Pair(-13, 93), Pair(-21, 53), Pair(-27, 115), Pair(6, 62), Pair(-25, 95), Pair(-8, 88), Pair(2, 71), Pair(-4, 67),
        Pair(-14, 88), Pair(-25, 73), Pair(0, 46), Pair(0, 0), Pair(25, 1), Pair(-9, 67), Pair(41, 56), Pair(5, 78),
        Pair(-11, 80), Pair(-14, 84), Pair(-11, 71), Pair(9, 16), Pair(-3, 27), Pair(-8, 55), Pair(1, 58), Pair(16, 63)
      },
      { // Piece 4
        Pair(29, 103), Pair(85, -20), Pair(-46, 114), Pair(111, -67), Pair(-55, 147), Pair(23, 90), Pair(6, 101), Pair(-3, 107),
        Pair(-53, 135), Pair(-45, 141), Pair(-84, 169), Pair(69, 9), Pair(-98, 176), Pair(12, 152), Pair(-24, 88), Pair(-11, 135),
        Pair(-28, 148), Pair(-10, 176), Pair(-22, 87), Pair(20, 64), Pair(-28, 54), Pair(-48, 153), Pair(-15, 138), Pair(-50, 189),
        Pair(-16, 45), Pair(-21, 166), Pair(-4, 59), Pair(25, 84), Pair(-21, 115), Pair(-1, 87), Pair(-11, 145), Pair(-2, 166),
        Pair(-11, 121), Pair(-27, 103), Pair(-14, 36), Pair(-20, 118), Pair(-22, 114), Pair(9, 93), Pair(-2, 51), Pair(-20, 96),
        Pair(-47, 142), Pair(-9, 57), Pair(14, 71), Pair(-13, 106), Pair(-4, 79), Pair(0, 117), Pair(-17, 164), Pair(-6, 88),
        Pair(-9, 64), Pair(1, 88), Pair(-5, 103), Pair(0, 0), Pair(8, 8), Pair(11, 45), Pair(4, 62), Pair(48, -19),
        Pair(-12, 104), Pair(36, 40), Pair(-4, 123), Pair(5, 5), Pair(-5, 153), Pair(19, 89), Pair(-7, 76), Pair(64, -14)
      },
      { // Piece 5
        Pair(8, 17), Pair(31, 62), Pair(4, 30), Pair(27, 65), Pair(-11, -73), Pair(-21, -75), Pair(-46, -25), Pair(-26, -7),
        Pair(35, 164), Pair(0, 70), Pair(66, 168), Pair(54, 79), Pair(70, 110), Pair(5, 98), Pair(-47, -25), Pair(-47, -80),
        Pair(22, 170), Pair(108, 33), Pair(-25, 106), Pair(48, 102), Pair(-77, 99), Pair(8, 7), Pair(41, 24), Pair(63, 85),
        Pair(19, -18), Pair(-107, 4), Pair(-43, 76), Pair(-27, -2), Pair(39, -25), Pair(-217, 56), Pair(-148, 15), Pair(-63, -34),
        Pair(-19, 64), Pair(-198, 28), Pair(-6, 35), Pair(-131, 36), Pair(83, 3), Pair(-9, 15), Pair(51, -21), Pair(-7, -37),
        Pair(46, -43), Pair(2, 40), Pair(-115, 11), Pair(-27, -24), Pair(-24, -14), Pair(-58, 9), Pair(1, -9), Pair(87, -5),
        Pair(23, -32), Pair(37, 17), Pair(-9, 8), Pair(0, 0), Pair(-31, 13), Pair(30, -29), Pair(25, -14), Pair(10, 3),
        Pair(112, -127), Pair(36, 8), Pair(13, -15), Pair(-43, 18), Pair(-23, -17), Pair(28, -34), Pair(28, -39), Pair(25, -40)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 36), Pair(-31, 6), Pair(-12, 15), Pair(-31, 27), Pair(68, 40), Pair(-33, 83), Pair(-15, 18), Pair(-1, 31),
        Pair(1, 24), Pair(-9, -3), Pair(1, 19), Pair(-25, 57), Pair(-1, 31), Pair(-1, 32), Pair(-1, 10), Pair(-3, 13),
        Pair(-3, 9), Pair(-8, 22), Pair(-2, 9), Pair(-4, 36), Pair(-6, 22), Pair(-4, 50), Pair(3, 17), Pair(0, 7),
        Pair(4, 20), Pair(-3, 28), Pair(0, 27), Pair(12, 33), Pair(-4, 9), Pair(16, 32), Pair(-4, 8), Pair(-3, 16),
        Pair(6, 9), Pair(5, 9), Pair(-4, 14), Pair(17, 43), Pair(-11, 2), Pair(20, 38), Pair(4, 7), Pair(0, 11),
        Pair(3, 21), Pair(4, 25), Pair(-3, 15), Pair(11, 36), Pair(-4, 2), Pair(9, 21), Pair(2, 0), Pair(0, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(75, -102), Pair(120, 17), Pair(21, 123), Pair(-65, -9), Pair(71, -51), Pair(-92, -47), Pair(-41, -18), Pair(-28, -6),
        Pair(-49, 116), Pair(-53, 91), Pair(35, 37), Pair(-25, 78), Pair(-78, 92), Pair(-25, 81), Pair(124, 3), Pair(24, 77),
        Pair(29, 60), Pair(46, 1), Pair(-57, 98), Pair(20, 72), Pair(-5, 60), Pair(6, 78), Pair(-8, 17), Pair(16, 104),
        Pair(32, 66), Pair(-2, 109), Pair(27, 73), Pair(-9, 106), Pair(-27, 79), Pair(-12, 113), Pair(-10, 81), Pair(12, 142),
        Pair(22, 61), Pair(25, 77), Pair(3, 88), Pair(2, 79), Pair(-6, 102), Pair(-11, 85), Pair(-32, 76), Pair(0, 43),
        Pair(15, 75), Pair(13, 92), Pair(12, 73), Pair(16, 56), Pair(-5, 57), Pair(7, 56), Pair(22, 53), Pair(18, 25),
        Pair(18, 8), Pair(-16, 162), Pair(-1, 88), Pair(11, 65), Pair(0, 0), Pair(9, 55), Pair(-58, 100), Pair(7, 70),
        Pair(-15, 62), Pair(14, 89), Pair(-45, 122), Pair(-2, 73), Pair(3, 11), Pair(14, 96), Pair(6, 14), Pair(-29, 39)
      },
      { // Piece 2
        Pair(153, -20), Pair(-35, 55), Pair(160, -55), Pair(-83, 67), Pair(-9, -25), Pair(161, -7), Pair(-7, 105), Pair(6, 107),
        Pair(-21, 63), Pair(16, 52), Pair(-15, 55), Pair(-23, 49), Pair(152, 11), Pair(-9, 68), Pair(36, 26), Pair(-49, 14),
        Pair(-39, 10), Pair(4, 35), Pair(18, 33), Pair(-27, 55), Pair(18, 61), Pair(0, 30), Pair(67, 6), Pair(8, 90),
        Pair(-43, 46), Pair(-37, 36), Pair(-6, 48), Pair(-16, 82), Pair(6, 36), Pair(0, 86), Pair(7, 48), Pair(-13, 25),
        Pair(62, 27), Pair(19, -6), Pair(-13, 93), Pair(21, 32), Pair(6, 36), Pair(2, 56), Pair(20, 48), Pair(13, 65),
        Pair(-3, 63), Pair(45, 57), Pair(-5, 63), Pair(-49, 116), Pair(-8, 44), Pair(20, 51), Pair(14, 60), Pair(-13, 40),
        Pair(-241, 209), Pair(11, 82), Pair(-30, 53), Pair(-1, 46), Pair(0, 0), Pair(-9, 70), Pair(-15, 53), Pair(27, 57),
        Pair(53, 76), Pair(-16, 39), Pair(-4, 60), Pair(-100, -50), Pair(50, 2), Pair(-9, -28), Pair(15, 33), Pair(-11, 3)
      },
      { // Piece 3
        Pair(-8, 88), Pair(32, 49), Pair(45, 46), Pair(-28, 62), Pair(7, 36), Pair(78, 57), Pair(-46, 101), Pair(40, 47),
        Pair(5, 62), Pair(-88, 126), Pair(2, 99), Pair(-66, 104), Pair(17, 40), Pair(-21, 78), Pair(-1, 110), Pair(-40, 111),
        Pair(-8, 96), Pair(-2, 97), Pair(-25, 103), Pair(-52, 84), Pair(-6, 76), Pair(-41, 78), Pair(-97, 148), Pair(-50, 121),
        Pair(17, 99), Pair(-3, 141), Pair(-3, 103), Pair(37, 42), Pair(-13, 99), Pair(7, 73), Pair(-28, 131), Pair(8, 81),
        Pair(1, 74), Pair(46, 73), Pair(-43, 103), Pair(-25, 81), Pair(18, 96), Pair(5, 86), Pair(-43, 146), Pair(9, 78),
        Pair(-11, 112), Pair(-13, 117), Pair(-14, 136), Pair(5, 58), Pair(4, 86), Pair(-9, 87), Pair(-24, 133), Pair(-27, 154),
        Pair(13, 46), Pair(36, 64), Pair(-33, 91), Pair(-52, 91), Pair(0, 0), Pair(-6, 78), Pair(-23, 64), Pair(-19, 83),
        Pair(6, 67), Pair(12, 87), Pair(-1, 92), Pair(-14, 68), Pair(39, -46), Pair(-8, 61), Pair(-5, 72), Pair(1, 70)
      },
      { // Piece 4
        Pair(73, 13), Pair(-37, 145), Pair(21, 43), Pair(44, 79), Pair(15, -12), Pair(57, 31), Pair(-64, 146), Pair(26, 54),
        Pair(-24, 81), Pair(-10, 150), Pair(-13, 64), Pair(-74, 99), Pair(-95, 71), Pair(8, 107), Pair(-71, 170), Pair(-63, 55),
        Pair(-19, 188), Pair(10, 33), Pair(-5, 34), Pair(-29, 188), Pair(20, 47), Pair(-18, 189), Pair(29, 148), Pair(2, 38),
        Pair(58, 10), Pair(34, 54), Pair(4, 116), Pair(-16, 48), Pair(-3, 103), Pair(8, 92), Pair(-39, 119), Pair(-6, -30),
        Pair(1, 62), Pair(-5, 140), Pair(12, 119), Pair(-6, 183), Pair(17, 49), Pair(2, 110), Pair(-17, 126), Pair(2, 140),
        Pair(46, 64), Pair(10, 98), Pair(7, 64), Pair(11, 88), Pair(-14, 164), Pair(-4, 69), Pair(-1, 23), Pair(23, -58),
        Pair(-16, 98), Pair(26, 2), Pair(13, 18), Pair(2, 108), Pair(0, 0), Pair(24, 124), Pair(-18, 62), Pair(21, 82),
        Pair(2, 156), Pair(-3, 86), Pair(9, 44), Pair(-1, 21), Pair(-9, -21), Pair(-17, 165), Pair(-14, 248), Pair(-20, 280)
      },
      { // Piece 5
        Pair(3, -21), Pair(-39, -110), Pair(65, 102), Pair(23, 117), Pair(-19, -47), Pair(11, 131), Pair(16, 14), Pair(-11, -19),
        Pair(-26, 103), Pair(-5, -8), Pair(23, 118), Pair(-16, 15), Pair(-47, -14), Pair(-54, 70), Pair(1, 120), Pair(29, 93),
        Pair(-33, 65), Pair(-4, 29), Pair(128, 28), Pair(-114, 46), Pair(48, 6), Pair(-91, 56), Pair(-30, 27), Pair(-4, 2),
        Pair(-179, 61), Pair(-58, 24), Pair(-97, 74), Pair(-142, 6), Pair(-15, 10), Pair(-54, 46), Pair(-147, 102), Pair(12, 62),
        Pair(-214, 23), Pair(-39, -13), Pair(-64, -3), Pair(20, -2), Pair(-103, 13), Pair(-73, 23), Pair(11, -8), Pair(-102, 11),
        Pair(-93, 1), Pair(22, 32), Pair(21, 13), Pair(-83, 1), Pair(-78, -14), Pair(-49, -12), Pair(74, -27), Pair(84, -13),
        Pair(-71, -7), Pair(-54, 1), Pair(-4, -3), Pair(-44, -5), Pair(0, 0), Pair(-37, 2), Pair(31, -22), Pair(37, -43),
        Pair(-9, -40), Pair(3, -20), Pair(7, -43), Pair(-18, -11), Pair(-52, 15), Pair(-18, -11), Pair(29, -15), Pair(41, -43)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(12, 20), Pair(-13, 18), Pair(-7, 13), Pair(-9, 32), Pair(-34, 25), Pair(-15, 52), Pair(-32, 54), Pair(15, 28),
        Pair(-6, 34), Pair(-8, 29), Pair(27, 17), Pair(-2, 10), Pair(-1, 15), Pair(-18, 9), Pair(-19, 35), Pair(-7, 21),
        Pair(0, 20), Pair(-2, 20), Pair(-4, 15), Pair(-2, 12), Pair(-7, 33), Pair(3, 17), Pair(-3, 34), Pair(6, 3),
        Pair(-3, 21), Pair(10, 13), Pair(3, 25), Pair(-4, 18), Pair(2, 32), Pair(12, 13), Pair(5, 34), Pair(6, 6),
        Pair(0, 19), Pair(5, 23), Pair(3, 16), Pair(-5, 21), Pair(6, 45), Pair(0, 4), Pair(24, 26), Pair(2, 15),
        Pair(5, 18), Pair(1, 22), Pair(2, 21), Pair(-5, 6), Pair(10, 21), Pair(10, 1), Pair(2, 20), Pair(-7, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(43, 58), Pair(9, 73), Pair(23, 110), Pair(123, 43), Pair(142, 76), Pair(-59, 116), Pair(13, 87), Pair(9, 50),
        Pair(-7, 61), Pair(-57, 87), Pair(-9, 110), Pair(38, 85), Pair(37, 76), Pair(41, 78), Pair(-23, 97), Pair(18, 69),
        Pair(24, 63), Pair(21, 85), Pair(-19, 101), Pair(14, 87), Pair(-2, 80), Pair(-39, 115), Pair(-37, 110), Pair(-77, 111),
        Pair(33, 69), Pair(8, 107), Pair(3, 102), Pair(-8, 109), Pair(9, 92), Pair(-19, 104), Pair(3, 106), Pair(-2, 76),
        Pair(0, 95), Pair(1, 86), Pair(6, 92), Pair(17, 96), Pair(15, 91), Pair(-6, 91), Pair(-25, 102), Pair(2, 94),
        Pair(20, 80), Pair(7, 102), Pair(2, 94), Pair(12, 78), Pair(14, 127), Pair(10, 68), Pair(16, 87), Pair(-14, 75),
        Pair(3, 112), Pair(1, 82), Pair(1, 116), Pair(14, 81), Pair(6, 99), Pair(0, 0), Pair(10, 122), Pair(11, 81),
        Pair(29, 59), Pair(13, 93), Pair(13, 97), Pair(-27, 131), Pair(25, 105), Pair(9, 88), Pair(-8, 91), Pair(-9, 4)
      },
      { // Piece 2
        Pair(27, 69), Pair(-19, 60), Pair(80, 46), Pair(68, 46), Pair(153, 12), Pair(87, 49), Pair(68, 60), Pair(-5, 88),
        Pair(-31, 111), Pair(30, 61), Pair(-7, 54), Pair(82, 35), Pair(60, 22), Pair(54, 36), Pair(9, 75), Pair(-32, 106),
        Pair(23, 53), Pair(16, 49), Pair(24, 51), Pair(23, 54), Pair(33, 60), Pair(-24, 57), Pair(23, 52), Pair(-22, 99),
        Pair(7, 86), Pair(12, 74), Pair(-12, 75), Pair(26, 64), Pair(3, 61), Pair(23, 50), Pair(-14, 78), Pair(13, 72),
        Pair(22, 38), Pair(17, 34), Pair(13, 64), Pair(-13, 66), Pair(14, 87), Pair(-15, 72), Pair(35, 63), Pair(9, 46),
        Pair(6, 86), Pair(29, 64), Pair(-8, 76), Pair(4, 84), Pair(7, 108), Pair(10, 53), Pair(16, 61), Pair(6, 69),
        Pair(19, 56), Pair(-4, 80), Pair(11, 79), Pair(-3, 80), Pair(29, 74), Pair(0, 0), Pair(20, 74), Pair(-9, 30),
        Pair(6, 67), Pair(14, 92), Pair(-9, 83), Pair(33, 45), Pair(-7, 35), Pair(22, 62), Pair(-64, -98), Pair(24, 62)
      },
      { // Piece 3
        Pair(37, 103), Pair(116, 82), Pair(109, 73), Pair(66, 93), Pair(86, 67), Pair(134, 40), Pair(38, 94), Pair(-13, 101),
        Pair(10, 106), Pair(11, 116), Pair(14, 105), Pair(64, 90), Pair(6, 103), Pair(69, 55), Pair(11, 90), Pair(14, 116),
        Pair(9, 110), Pair(42, 100), Pair(-1, 119), Pair(-26, 129), Pair(-19, 116), Pair(27, 104), Pair(-6, 114), Pair(14, 118),
        Pair(20, 111), Pair(25, 106), Pair(17, 96), Pair(15, 110), Pair(0, 103), Pair(20, 93), Pair(18, 91), Pair(38, 96),
        Pair(19, 113), Pair(29, 104), Pair(30, 106), Pair(-17, 119), Pair(14, 104), Pair(62, 68), Pair(31, 92), Pair(31, 104),
        Pair(-1, 121), Pair(2, 124), Pair(12, 106), Pair(-16, 120), Pair(11, 114), Pair(3, 89), Pair(20, 118), Pair(1, 109),
        Pair(35, 99), Pair(9, 111), Pair(10, 116), Pair(-3, 103), Pair(4, 94), Pair(0, 0), Pair(-6, 60), Pair(0, 89),
        Pair(17, 105), Pair(14, 109), Pair(14, 97), Pair(-1, 121), Pair(-3, 110), Pair(3, 65), Pair(4, 83), Pair(9, 102)
      },
      { // Piece 4
        Pair(34, 201), Pair(33, 236), Pair(75, 153), Pair(-31, 250), Pair(98, 184), Pair(-51, 230), Pair(-28, 269), Pair(32, 197),
        Pair(-32, 232), Pair(19, 205), Pair(12, 254), Pair(31, 188), Pair(0, 168), Pair(-22, 195), Pair(-31, 298), Pair(-2, 221),
        Pair(5, 261), Pair(15, 213), Pair(9, 240), Pair(-13, 239), Pair(-8, 230), Pair(9, 210), Pair(-14, 247), Pair(4, 228),
        Pair(21, 231), Pair(24, 225), Pair(-2, 188), Pair(-7, 238), Pair(-42, 275), Pair(7, 234), Pair(0, 174), Pair(1, 212),
        Pair(17, 216), Pair(21, 204), Pair(13, 216), Pair(21, 174), Pair(-6, 248), Pair(15, 168), Pair(10, 219), Pair(-23, 211),
        Pair(50, 227), Pair(17, 217), Pair(10, 219), Pair(17, 235), Pair(28, 169), Pair(11, 215), Pair(11, 204), Pair(-5, 228),
        Pair(35, 196), Pair(38, 175), Pair(17, 185), Pair(25, 178), Pair(17, 192), Pair(0, 0), Pair(4, 189), Pair(7, 175),
        Pair(35, 245), Pair(29, 208), Pair(31, 199), Pair(26, 209), Pair(3, 235), Pair(-12, 221), Pair(-12, 108), Pair(38, 158)
      },
      { // Piece 5
        Pair(-61, 0), Pair(84, 56), Pair(-23, 19), Pair(13, 25), Pair(-14, -14), Pair(-53, 87), Pair(-80, 167), Pair(-27, 151),
        Pair(-116, 84), Pair(57, 33), Pair(-13, 73), Pair(-28, 52), Pair(-160, 181), Pair(-25, 132), Pair(-119, 129), Pair(-46, 123),
        Pair(-173, 104), Pair(-109, 66), Pair(-59, 82), Pair(-1, 54), Pair(-24, 71), Pair(-42, 81), Pair(-106, 91), Pair(-19, 93),
        Pair(-285, 44), Pair(-251, 110), Pair(-37, 43), Pair(-82, 73), Pair(-94, 57), Pair(-92, 69), Pair(-124, 61), Pair(-10, 52),
        Pair(-28, 37), Pair(-102, 46), Pair(-135, 61), Pair(-62, 35), Pair(-11, 32), Pair(-58, 38), Pair(75, 7), Pair(46, 3),
        Pair(-109, 41), Pair(-42, 10), Pair(-20, 33), Pair(5, 28), Pair(-53, 2), Pair(-72, 8), Pair(15, -19), Pair(55, 2),
        Pair(-53, 23), Pair(-5, 2), Pair(-5, 2), Pair(22, 7), Pair(-40, 17), Pair(0, 0), Pair(6, -6), Pair(46, -1),
        Pair(-32, -29), Pair(-2, -19), Pair(4, 3), Pair(4, 19), Pair(-14, -4), Pair(-28, 18), Pair(20, -6), Pair(35, -11)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 35), Pair(-24, 38), Pair(26, 8), Pair(35, 9), Pair(-2, 29), Pair(-36, 20), Pair(37, 4), Pair(1, 33),
        Pair(-8, 19), Pair(-8, 17), Pair(6, 21), Pair(1, 11), Pair(-8, 38), Pair(13, 14), Pair(5, 8), Pair(9, 20),
        Pair(-2, 20), Pair(0, 24), Pair(-1, 18), Pair(-1, 13), Pair(3, 20), Pair(-9, 29), Pair(16, 7), Pair(-1, 37),
        Pair(6, 22), Pair(3, 25), Pair(5, 22), Pair(5, 11), Pair(-3, 10), Pair(7, 32), Pair(17, 0), Pair(4, 33),
        Pair(2, 21), Pair(-2, 23), Pair(5, 20), Pair(3, 25), Pair(-1, 18), Pair(16, 34), Pair(0, 8), Pair(15, 39),
        Pair(0, 28), Pair(10, 25), Pair(1, 26), Pair(8, 17), Pair(-1, -1), Pair(6, 23), Pair(15, 15), Pair(9, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-38, 23), Pair(35, 93), Pair(140, 30), Pair(46, 78), Pair(68, 77), Pair(154, 37), Pair(-89, 73), Pair(63, 101),
        Pair(-33, 106), Pair(-31, 95), Pair(-28, 109), Pair(12, 89), Pair(-60, 123), Pair(-10, 77), Pair(44, 26), Pair(-38, 119),
        Pair(94, 43), Pair(-3, 75), Pair(3, 90), Pair(-5, 81), Pair(2, 84), Pair(43, 38), Pair(9, 79), Pair(-39, 108),
        Pair(13, 77), Pair(-9, 111), Pair(12, 74), Pair(1, 108), Pair(-2, 81), Pair(18, 97), Pair(8, 76), Pair(17, 60),
        Pair(11, 83), Pair(18, 87), Pair(10, 84), Pair(-9, 95), Pair(-3, 77), Pair(3, 84), Pair(-1, 91), Pair(10, 74),
        Pair(7, 91), Pair(15, 81), Pair(4, 88), Pair(7, 71), Pair(7, 94), Pair(20, 89), Pair(-4, 63), Pair(-1, 76),
        Pair(15, 112), Pair(-22, 115), Pair(1, 90), Pair(10, 69), Pair(4, 79), Pair(16, 65), Pair(0, 0), Pair(27, 79),
        Pair(-17, 194), Pair(13, 70), Pair(-2, 100), Pair(-6, 91), Pair(2, 49), Pair(20, 43), Pair(4, 79), Pair(-5, 131)
      },
      { // Piece 2
        Pair(67, 11), Pair(23, 70), Pair(22, 32), Pair(105, 25), Pair(28, 68), Pair(93, 52), Pair(72, 52), Pair(55, 30),
        Pair(38, 60), Pair(-16, 53), Pair(-6, 69), Pair(49, 46), Pair(1, 38), Pair(56, 27), Pair(-7, 74), Pair(26, 16),
        Pair(-21, 84), Pair(32, 75), Pair(37, 38), Pair(6, 56), Pair(-8, 48), Pair(95, 19), Pair(12, 63), Pair(18, 44),
        Pair(36, 59), Pair(11, 56), Pair(21, 54), Pair(-28, 72), Pair(4, 64), Pair(5, 83), Pair(7, 41), Pair(8, 53),
        Pair(43, 45), Pair(21, 52), Pair(1, 77), Pair(7, 83), Pair(5, 61), Pair(7, 79), Pair(2, 45), Pair(11, 72),
        Pair(13, 62), Pair(13, 53), Pair(15, 70), Pair(3, 81), Pair(6, 82), Pair(-2, 106), Pair(12, 62), Pair(-54, 43),
        Pair(13, 29), Pair(9, 72), Pair(-15, 57), Pair(10, 59), Pair(9, 68), Pair(20, 83), Pair(0, 0), Pair(-15, 91),
        Pair(43, 78), Pair(37, 44), Pair(11, 71), Pair(-16, 57), Pair(37, 46), Pair(-29, 69), Pair(-14, 100), Pair(0, 0)
      },
      { // Piece 3
        Pair(50, 104), Pair(6, 133), Pair(57, 93), Pair(15, 109), Pair(-6, 128), Pair(30, 119), Pair(43, 67), Pair(0, 106),
        Pair(-22, 130), Pair(-9, 120), Pair(53, 103), Pair(17, 121), Pair(-1, 129), Pair(45, 94), Pair(10, 91), Pair(44, 94),
        Pair(-13, 128), Pair(23, 118), Pair(4, 110), Pair(21, 116), Pair(1, 129), Pair(-18, 117), Pair(52, 101), Pair(-43, 141),
        Pair(38, 104), Pair(10, 107), Pair(18, 99), Pair(5, 119), Pair(-1, 110), Pair(27, 99), Pair(63, 80), Pair(-17, 130),
        Pair(19, 104), Pair(13, 118), Pair(-12, 123), Pair(18, 105), Pair(-17, 133), Pair(12, 124), Pair(11, 111), Pair(-7, 114),
        Pair(27, 117), Pair(-2, 125), Pair(-6, 144), Pair(37, 102), Pair(0, 121), Pair(20, 110), Pair(17, 73), Pair(-8, 109),
        Pair(22, 133), Pair(33, 96), Pair(22, 126), Pair(23, 124), Pair(5, 136), Pair(6, 117), Pair(0, 0), Pair(-52, 47),
        Pair(24, 109), Pair(31, 116), Pair(28, 94), Pair(14, 107), Pair(28, 111), Pair(13, 101), Pair(-45, 54), Pair(-4, 76)
      },
      { // Piece 4
        Pair(-28, 179), Pair(-37, 163), Pair(28, 137), Pair(58, 139), Pair(3, 134), Pair(-82, 214), Pair(92, 133), Pair(11, 133),
        Pair(-1, 152), Pair(7, 123), Pair(20, 145), Pair(33, 109), Pair(6, 178), Pair(-40, 270), Pair(0, 146), Pair(-9, 178),
        Pair(-27, 193), Pair(57, 127), Pair(31, 129), Pair(-7, 190), Pair(33, 170), Pair(23, 150), Pair(34, 136), Pair(-7, 154),
        Pair(42, 134), Pair(3, 171), Pair(-2, 206), Pair(4, 162), Pair(11, 193), Pair(11, 166), Pair(19, 156), Pair(-2, 179),
        Pair(26, 181), Pair(27, 191), Pair(17, 130), Pair(13, 194), Pair(4, 169), Pair(15, 172), Pair(35, 159), Pair(8, 138),
        Pair(35, 131), Pair(20, 197), Pair(15, 155), Pair(22, 211), Pair(21, 176), Pair(27, 148), Pair(14, 185), Pair(-25, 221),
        Pair(13, 248), Pair(15, 180), Pair(21, 161), Pair(26, 184), Pair(17, 171), Pair(38, 130), Pair(0, 0), Pair(-37, 220),
        Pair(19, 165), Pair(10, 213), Pair(39, 200), Pair(32, 169), Pair(27, 210), Pair(-26, 177), Pair(-2, 178), Pair(-69, 199)
      },
      { // Piece 5
        Pair(-18, 2), Pair(-117, 101), Pair(-52, 127), Pair(-37, 36), Pair(12, 85), Pair(29, 53), Pair(-83, -19), Pair(-6, 179),
        Pair(-85, 29), Pair(-23, 119), Pair(3, 13), Pair(-33, 69), Pair(-66, 106), Pair(-132, 78), Pair(-160, 145), Pair(63, 122),
        Pair(-132, 54), Pair(-177, 90), Pair(-23, 12), Pair(-140, 147), Pair(-208, 96), Pair(-192, 118), Pair(-132, 108), Pair(-139, 117),
        Pair(-53, 42), Pair(-32, 26), Pair(-81, 56), Pair(-54, 62), Pair(-28, 56), Pair(63, 34), Pair(-20, 74), Pair(-117, 107),
        Pair(-50, -7), Pair(-80, 26), Pair(-3, 40), Pair(-98, 54), Pair(67, 5), Pair(7, 24), Pair(104, -14), Pair(76, 27),
        Pair(-88, 25), Pair(-30, 19), Pair(-65, 36), Pair(5, 29), Pair(35, 12), Pair(-47, -6), Pair(13, -26), Pair(53, -42),
        Pair(-58, 23), Pair(-53, 38), Pair(-35, 32), Pair(-22, 20), Pair(-9, 26), Pair(-47, 9), Pair(0, 0), Pair(-6, 13),
        Pair(-60, -30), Pair(-31, 27), Pair(-14, 2), Pair(8, 23), Pair(25, -17), Pair(-45, 18), Pair(18, 4), Pair(-3, 0)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(11, 21), Pair(-6, 34), Pair(17, 24), Pair(16, 22), Pair(2, 36), Pair(-26, 36), Pair(5, 32), Pair(27, -20),
        Pair(2, 16), Pair(-35, 39), Pair(6, 32), Pair(-7, 21), Pair(-17, 17), Pair(-11, 9), Pair(12, 25), Pair(9, -1),
        Pair(-7, 27), Pair(-4, 19), Pair(4, 14), Pair(-6, 14), Pair(-12, 22), Pair(-11, 9), Pair(-3, 22), Pair(-3, 12),
        Pair(-1, 17), Pair(-4, 23), Pair(0, 15), Pair(0, 12), Pair(-3, 11), Pair(-3, 4), Pair(-4, 29), Pair(-6, 0),
        Pair(-5, 19), Pair(0, 21), Pair(-1, 16), Pair(-4, 10), Pair(4, 16), Pair(3, 8), Pair(18, 29), Pair(-8, -5),
        Pair(-7, 23), Pair(-4, 19), Pair(-2, 26), Pair(4, 11), Pair(1, 21), Pair(-10, 12), Pair(1, 19), Pair(-3, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(25, 27), Pair(156, 94), Pair(-51, 92), Pair(-35, 104), Pair(55, 44), Pair(161, 58), Pair(-74, 61), Pair(-113, -43),
        Pair(-24, 108), Pair(-24, 51), Pair(-2, 64), Pair(25, 81), Pair(-19, 121), Pair(12, 80), Pair(18, 96), Pair(-24, 133),
        Pair(-5, 119), Pair(-19, 109), Pair(49, 76), Pair(27, 67), Pair(7, 80), Pair(11, 63), Pair(-14, 73), Pair(56, 16),
        Pair(-5, 74), Pair(-1, 82), Pair(-2, 61), Pair(-14, 113), Pair(-5, 95), Pair(8, 71), Pair(34, 92), Pair(5, 75),
        Pair(14, 79), Pair(3, 105), Pair(11, 79), Pair(19, 89), Pair(13, 75), Pair(15, 74), Pair(24, 81), Pair(28, 79),
        Pair(2, 62), Pair(19, 77), Pair(2, 83), Pair(10, 82), Pair(18, 72), Pair(24, 76), Pair(10, 87), Pair(8, 29),
        Pair(-2, 71), Pair(23, 87), Pair(-1, 70), Pair(12, 67), Pair(7, 76), Pair(12, 72), Pair(46, 42), Pair(0, 0),
        Pair(118, 131), Pair(3, 81), Pair(15, 103), Pair(16, 83), Pair(24, 79), Pair(-19, 83), Pair(62, 50), Pair(2, 97)
      },
      { // Piece 2
        Pair(-81, 133), Pair(100, 31), Pair(-54, 30), Pair(80, 29), Pair(157, -23), Pair(21, 52), Pair(150, 19), Pair(-39, 37),
        Pair(-49, 108), Pair(35, 34), Pair(37, 42), Pair(75, -3), Pair(47, 38), Pair(52, 27), Pair(-6, 26), Pair(21, 28),
        Pair(-4, 79), Pair(46, 52), Pair(-6, 61), Pair(46, 13), Pair(73, 37), Pair(52, 57), Pair(61, 0), Pair(10, 76),
        Pair(14, 61), Pair(1, 73), Pair(40, 80), Pair(19, 77), Pair(14, 61), Pair(26, 78), Pair(-1, 86), Pair(19, 61),
        Pair(28, 46), Pair(-1, 72), Pair(18, 70), Pair(16, 66), Pair(26, 48), Pair(-2, 71), Pair(12, 53), Pair(8, 85),
        Pair(0, 63), Pair(13, 74), Pair(2, 74), Pair(19, 73), Pair(6, 94), Pair(24, 78), Pair(27, 95), Pair(10, 64),
        Pair(11, 32), Pair(2, 82), Pair(21, 48), Pair(-6, 90), Pair(13, 86), Pair(43, 79), Pair(30, 66), Pair(0, 0),
        Pair(19, 81), Pair(-1, 19), Pair(5, 55), Pair(-20, 68), Pair(41, 70), Pair(2, 78), Pair(89, 50), Pair(17, 33)
      },
      { // Piece 3
        Pair(4, 152), Pair(77, 90), Pair(48, 119), Pair(69, 110), Pair(25, 141), Pair(144, 87), Pair(-12, 127), Pair(-13, 95),
        Pair(-19, 139), Pair(7, 132), Pair(20, 122), Pair(8, 138), Pair(-34, 165), Pair(8, 122), Pair(-14, 137), Pair(37, 83),
        Pair(9, 118), Pair(21, 122), Pair(37, 119), Pair(31, 125), Pair(32, 112), Pair(10, 122), Pair(-7, 100), Pair(33, 92),
        Pair(16, 138), Pair(6, 146), Pair(26, 108), Pair(21, 139), Pair(-49, 147), Pair(-19, 150), Pair(42, 110), Pair(-13, 121),
        Pair(8, 154), Pair(34, 123), Pair(-1, 133), Pair(10, 133), Pair(10, 126), Pair(17, 132), Pair(9, 134), Pair(-2, 108),
        Pair(15, 128), Pair(-26, 174), Pair(26, 150), Pair(32, 116), Pair(-20, 163), Pair(13, 135), Pair(11, 120), Pair(7, 91),
        Pair(18, 138), Pair(22, 129), Pair(-2, 160), Pair(24, 126), Pair(8, 137), Pair(18, 123), Pair(-3, 138), Pair(0, 0),
        Pair(21, 118), Pair(24, 120), Pair(24, 108), Pair(24, 109), Pair(7, 127), Pair(16, 124), Pair(-14, 122), Pair(-28, 71)
      },
      { // Piece 4
        Pair(59, 175), Pair(76, 164), Pair(-139, 346), Pair(-4, 251), Pair(43, 268), Pair(-16, 294), Pair(65, 191), Pair(4, 222),
        Pair(8, 230), Pair(-11, 257), Pair(-20, 288), Pair(9, 258), Pair(-24, 292), Pair(-8, 253), Pair(11, 270), Pair(-22, 270),
        Pair(-6, 248), Pair(12, 205), Pair(1, 228), Pair(-36, 290), Pair(-26, 296), Pair(-2, 287), Pair(24, 260), Pair(-27, 269),
        Pair(16, 236), Pair(22, 282), Pair(1, 208), Pair(50, 153), Pair(-10, 242), Pair(31, 235), Pair(6, 280), Pair(24, 193),
        Pair(16, 235), Pair(-4, 195), Pair(24, 203), Pair(5, 234), Pair(-6, 254), Pair(10, 242), Pair(19, 246), Pair(3, 224),
        Pair(-9, 234), Pair(22, 248), Pair(17, 203), Pair(36, 182), Pair(23, 218), Pair(31, 201), Pair(26, 225), Pair(-15, 242),
        Pair(20, 221), Pair(38, 237), Pair(15, 255), Pair(16, 217), Pair(37, 194), Pair(38, 151), Pair(29, 248), Pair(0, 0),
        Pair(11, 213), Pair(21, 230), Pair(32, 175), Pair(34, 211), Pair(32, 181), Pair(32, 169), Pair(4, 153), Pair(-24, -30)
      },
      { // Piece 5
        Pair(-38, 51), Pair(-74, 190), Pair(-55, 56), Pair(-11, 97), Pair(-56, -71), Pair(-29, 85), Pair(54, 100), Pair(-32, -75),
        Pair(94, 104), Pair(-68, 37), Pair(25, 66), Pair(-102, 99), Pair(-72, -1), Pair(111, 64), Pair(-121, 133), Pair(-48, 102),
        Pair(-284, 45), Pair(-125, 44), Pair(-71, 33), Pair(-225, 85), Pair(-142, 113), Pair(-73, 65), Pair(1, 41), Pair(-280, 108),
        Pair(-135, 60), Pair(-119, 34), Pair(-148, 53), Pair(-78, 56), Pair(-94, 59), Pair(-35, 27), Pair(38, 26), Pair(11, 38),
        Pair(93, 29), Pair(-58, 47), Pair(-43, 42), Pair(-97, 52), Pair(-41, 52), Pair(-91, 42), Pair(45, 20), Pair(-22, 16),
        Pair(-59, 33), Pair(-67, 44), Pair(-73, 46), Pair(-5, 24), Pair(-5, 30), Pair(29, 8), Pair(6, -27), Pair(-64, -20),
        Pair(-64, 19), Pair(-20, 7), Pair(-38, 32), Pair(-18, 33), Pair(3, 8), Pair(1, 15), Pair(-39, -5), Pair(0, 0),
        Pair(-52, 22), Pair(-29, 24), Pair(-21, 29), Pair(-19, 24), Pair(33, -22), Pair(-5, 5), Pair(-1, -16), Pair(18, -44)
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
      Pair(-285, -182), Pair(-45, -225), Pair(-69, -228), Pair(-67, -267), Pair(-49, -278), Pair(-30, -233), Pair(-76, -262), Pair(-201, -209),
      Pair(-21, -193), Pair(-76, -272), Pair(-73, -259), Pair(-38, -262), Pair(-132, -250), Pair(-120, -232), Pair(-63, -281), Pair(-53, -213),
      Pair(-11, -258), Pair(-137, -240), Pair(-9, -272), Pair(-64, -253), Pair(29, -273), Pair(-45, -253), Pair(-135, -238), Pair(-8, -268),
      Pair(-90, -258), Pair(-18, -233), Pair(115, -292), Pair(-5, -257), Pair(144, -294), Pair(-78, -261), Pair(-135, -240), Pair(-52, -250),
      Pair(-25, -278), Pair(-54, -258), Pair(-76, -234), Pair(9, -250), Pair(-43, -248), Pair(1, -261), Pair(0, -271), Pair(37, -280),
      Pair(-49, -243), Pair(16, -257), Pair(-17, -254), Pair(24, -266), Pair(-36, -254), Pair(-37, -267), Pair(25, -275), Pair(-48, -252),
      Pair(3, -225), Pair(-13, -255), Pair(-107, -246), Pair(8, -254), Pair(-67, -263), Pair(-100, -251), Pair(-37, -326), Pair(-56, -262),
      Pair(-28, -248), Pair(-79, -373), Pair(-70, -265), Pair(-97, -248), Pair(-33, -255), Pair(16, -269), Pair(-40, -247), Pair(-61, -225)
  },
  {
      Pair(-90, -269), Pair(-14, -276), Pair(15, -300), Pair(-13, -277), Pair(-56, -271), Pair(-25, -247), Pair(-55, -301), Pair(-187, -250),
      Pair(3, -299), Pair(-33, -297), Pair(-36, -296), Pair(41, -305), Pair(-71, -263), Pair(-15, -309), Pair(-64, -267), Pair(-49, -286),
      Pair(-30, -289), Pair(-66, -310), Pair(-112, -271), Pair(38, -318), Pair(33, -302), Pair(-13, -292), Pair(19, -313), Pair(-89, -290),
      Pair(-11, -291), Pair(-8, -294), Pair(-12, -302), Pair(27, -307), Pair(-66, -283), Pair(67, -315), Pair(-81, -309), Pair(-33, -308),
      Pair(16, -329), Pair(64, -294), Pair(45, -310), Pair(-25, -300), Pair(-35, -281), Pair(15, -309), Pair(53, -326), Pair(-32, -310),
      Pair(18, -298), Pair(3, -315), Pair(-10, -289), Pair(-35, -294), Pair(72, -305), Pair(-51, -278), Pair(-12, -337), Pair(-28, -301),
      Pair(66, -275), Pair(-64, -297), Pair(78, -310), Pair(-13, -318), Pair(39, -344), Pair(-19, -322), Pair(-34, -308), Pair(-23, -334),
      Pair(1, -318), Pair(-20, -331), Pair(-68, -296), Pair(-54, -312), Pair(-44, -305), Pair(-61, -311), Pair(-46, -345), Pair(-15, -304)
  },
  {
      Pair(-207, -426), Pair(-157, -456), Pair(-171, -459), Pair(-146, -453), Pair(-188, -449), Pair(-160, -469), Pair(-87, -489), Pair(-114, -481),
      Pair(-147, -453), Pair(-145, -449), Pair(-97, -467), Pair(-89, -465), Pair(-106, -467), Pair(-215, -453), Pair(-208, -456), Pair(-70, -478),
      Pair(-54, -465), Pair(-148, -449), Pair(19, -487), Pair(-81, -456), Pair(-88, -461), Pair(-97, -472), Pair(-186, -445), Pair(-86, -468),
      Pair(-65, -468), Pair(-137, -434), Pair(-42, -497), Pair(-42, -483), Pair(4, -495), Pair(-74, -484), Pair(-156, -454), Pair(-103, -493),
      Pair(-115, -457), Pair(-80, -462), Pair(-100, -471), Pair(-126, -471), Pair(-76, -481), Pair(-97, -480), Pair(-226, -446), Pair(-168, -466),
      Pair(-49, -479), Pair(-115, -450), Pair(-92, -469), Pair(-166, -455), Pair(-76, -474), Pair(-134, -482), Pair(-216, -452), Pair(-175, -475),
      Pair(-205, -436), Pair(-119, -450), Pair(-57, -469), Pair(-174, -427), Pair(-150, -443), Pair(-235, -450), Pair(-216, -436), Pair(-191, -452),
      Pair(-166, -448), Pair(-126, -464), Pair(-102, -466), Pair(-145, -442), Pair(-207, -436), Pair(-140, -482), Pair(-210, -445), Pair(-193, -451)
  },
  {
      Pair(-31, -95), Pair(-40, -86), Pair(-20, -95), Pair(-4, -112), Pair(-93, -128), Pair(-79, -164), Pair(-23, -8), Pair(-91, -120),
      Pair(-12, -56), Pair(-68, -87), Pair(-37, -89), Pair(-45, -65), Pair(-59, -102), Pair(-67, -88), Pair(0, -1), Pair(-58, -105),
      Pair(-43, -78), Pair(-34, -87), Pair(-22, -46), Pair(-62, -131), Pair(-59, -133), Pair(-17, -45), Pair(-12, -37), Pair(-105, -187),
      Pair(-54, -105), Pair(9, 16), Pair(-48, -87), Pair(-72, -128), Pair(-78, -70), Pair(-13, -54), Pair(-27, -101), Pair(-30, -66),
      Pair(-19, -38), Pair(-10, -24), Pair(-16, -36), Pair(-47, -113), Pair(-36, -80), Pair(-43, -64), Pair(-69, -134), Pair(-82, -131),
      Pair(-27, -61), Pair(-27, -48), Pair(-34, -81), Pair(-50, -102), Pair(-34, -80), Pair(-20, -53), Pair(-56, -93), Pair(-47, -88),
      Pair(-48, -109), Pair(-44, -84), Pair(-57, -97), Pair(-14, -31), Pair(19, 3), Pair(-21, -38), Pair(-35, -73), Pair(-18, -37),
      Pair(-23, -65), Pair(-29, -75), Pair(-41, -76), Pair(-32, -65), Pair(9, 5), Pair(-29, -59), Pair(-39, -88), Pair(-63, -118)
  },
  {
      Pair(35, 26), Pair(-20, 5), Pair(97, -21), Pair(-40, 3), Pair(14, -18), Pair(11, -19), Pair(-60, -7), Pair(-1, 12),
      Pair(52, 0), Pair(-67, 26), Pair(-73, 26), Pair(4, 4), Pair(44, -15), Pair(17, -12), Pair(6, -11), Pair(-20, 10),
      Pair(-58, 9), Pair(22, 2), Pair(2, 3), Pair(39, -3), Pair(56, -17), Pair(43, -12), Pair(19, -13), Pair(-4, -17),
      Pair(17, 6), Pair(73, -12), Pair(-34, 8), Pair(63, -16), Pair(43, -10), Pair(21, -10), Pair(-22, -7), Pair(-145, 49),
      Pair(-74, 17), Pair(-107, 19), Pair(-3, -2), Pair(69, -19), Pair(77, -32), Pair(29, -17), Pair(-24, 3), Pair(-34, 20),
      Pair(-40, 15), Pair(-108, 10), Pair(-18, -4), Pair(121, -29), Pair(74, -19), Pair(48, -17), Pair(112, -33), Pair(29, -4),
      Pair(-41, 8), Pair(-62, 18), Pair(-14, 9), Pair(0, -1), Pair(21, -9), Pair(-10, -3), Pair(-6, 0), Pair(38, 12),
      Pair(-69, 20), Pair(-7, 14), Pair(-21, 0), Pair(-24, 9), Pair(-6, -15), Pair(-64, -1), Pair(-22, -3), Pair(33, -2)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(6, -48), Pair(16, -38), Pair(22, -29), Pair(26, -21), Pair(32, -19), Pair(37, -13), Pair(44, -15), Pair(51, -16),
  Pair(52, -20)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(5, -90), Pair(16, -88), Pair(19, -68), Pair(21, -60), Pair(24, -56), Pair(25, -52), Pair(26, -51), Pair(26, -52),
  Pair(28, -53), Pair(28, -52), Pair(30, -56), Pair(46, -56), Pair(40, -52), Pair(126, -66)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-93, -146), Pair(-29, -123), Pair(-21, -95), Pair(-15, -71), Pair(-11, -59), Pair(-9, -49), Pair(-4, -44), Pair(-2, -40),
  Pair(2, -38), Pair(8, -36), Pair(12, -34), Pair(19, -37), Pair(34, -43), Pair(37, -44), Pair(55, -54)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-3, -13), Pair(-5, -20), Pair(-3, -50), Pair(-1, -34), Pair(0, 15), Pair(1, 27), Pair(0, 51), Pair(1, 59),
  Pair(3, 69), Pair(3, 71), Pair(6, 77), Pair(8, 87), Pair(11, 77), Pair(11, 81), Pair(18, 65), Pair(22, 50),
  Pair(25, 46), Pair(35, 22), Pair(54, 1), Pair(61, -18), Pair(82, -49), Pair(110, -92), Pair(140, -102), Pair(184, -166),
  Pair(219, -178), Pair(299, -252), Pair(211, -222), Pair(241, -211)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-29, -94), Pair(-27, -70), Pair(-6, -42), Pair(15, -16), Pair(66, 8), Pair(203, 143), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(10, 31), Pair(20, 27), Pair(31, 65), Pair(50, 116), Pair(136, 201), Pair(232, 489), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(3, 5), Pair(1, 27), Pair(16, 24), Pair(13, 55), Pair(235, 138), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-34, -61), Pair(-26, -46), Pair(0, 2), Pair(-29, 43), Pair(0, -14), Pair(-18, -7), Pair(-30, -27), Pair(-15, -33)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-10, 5), Pair(-11, 2), Pair(-3, 6), Pair(-11, 6), Pair(-6, 10), Pair(-7, 14), Pair(-9, 6), Pair(-3, 22)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(2, -41), Pair(21, -48), Pair(31, -39), Pair(61, -53), Pair(71, -52), Pair(68, -34), Pair(52, -39), Pair(20, -30)
  },
  {
      Pair(-5, -1), Pair(10, -28), Pair(33, -21), Pair(57, -38), Pair(67, -40), Pair(41, -23), Pair(27, -28), Pair(-2, -12)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(21, -14), Pair(47, -22), Pair(23, -15),
  Pair(51, -12), Pair(69, -31), Pair(53, -13),
  Pair(80, -12), Pair(0, 0), Pair(78, -11),
  Pair(68, 13), Pair(62, -3), Pair(70, 16)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-5, -1), Pair(-19, 15), Pair(-4, 0),
  Pair(-4, -9), Pair(-15, 6), Pair(-2, -8),
  Pair(-1, -17), Pair(-7, -16), Pair(0, -20),
  Pair(30, -30), Pair(5, -31), Pair(27, -27),
  Pair(87, -38), Pair(73, -30), Pair(81, -38),
  Pair(44, -31), Pair(-41, -57), Pair(29, -18),
  Pair(15, -57), Pair(0, 0), Pair(-3, -56)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(10, 74), Pair(-1, 66), Pair(-7, 55), Pair(5, 43), Pair(-1, 38), Pair(15, 28), Pair(16, 28)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(26, 3), Pair(-21, 36), Pair(-11, 64), Pair(7, 68), Pair(19, 70), Pair(19, 74), Pair(20, 81)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-391, 142);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-40, -38), Pair(9, -25), Pair(-18, -18), Pair(-38, -10), Pair(-36, -3), Pair(-20, -7), Pair(2, -19), Pair(-8, -36)
  },
  {
      Pair(-24, 18), Pair(25, 11), Pair(11, 10), Pair(-37, 8), Pair(-28, 14), Pair(-19, 9), Pair(30, 4), Pair(12, 1)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(18, 2), Pair(33, -6), Pair(74, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 4), Pair(24, 1), Pair(37, -2), Pair(-38, 8), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(19, -20), Pair(19, -11), Pair(43, -8), Pair(55, -7), Pair(28, -1), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 25), Pair(10, 43), Pair(31, 46), Pair(78, 23), Pair(126, 12), Pair(323, -88), Pair(303, -61)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(32, 4), Pair(10, 15), Pair(57, -9), Pair(17, 23), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-5, 19), Pair(3, 38)
  },
  {
      Pair(-26, 7), Pair(-39, 15)
  },
  {
      Pair(-44, 36), Pair(-42, -10)
  },
  {
      Pair(-77, 41), Pair(-73, 30)
  },
  {
      Pair(-41, 80), Pair(-45, 102)
  },
  {
      Pair(32, 38), Pair(-46, 33)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(11, 23), Pair(10, 43), Pair(9, 28), Pair(11, 3), Pair(25, 2)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-21, -40), Pair(-2, -20)
  },
  {
      Pair(-12, -54), Pair(-23, -78)
  },
  {
      Pair(-55, -8), Pair(-46, -53)
  },
  {
      Pair(-98, 16), Pair(-76, -29)
  },
  {
      Pair(-54, -12), Pair(-49, -61)
  },
  {
      Pair(-96, -13), Pair(-26, -61)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-17, -32), Pair(1, -5)
  },
  {
      Pair(-50, -14), Pair(-17, -53)
  },
  {
      Pair(-5, -109), Pair(6, -120)
  },
  {
      Pair(-54, -30), Pair(-55, -73)
  },
  {
      Pair(-51, -77), Pair(-52, -73)
  },
  {
      Pair(-21, -18), Pair(-9, -28)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-20, -15), Pair(5, 1)
  },
  {
      Pair(-51, -13), Pair(-9, -16)
  },
  {
      Pair(-47, -2), Pair(-16, -3)
  },
  {
      Pair(-12, -31), Pair(5, -27)
  },
  {
      Pair(-77, -17), Pair(-66, -70)
  },
  {
      Pair(11, -33), Pair(-15, -38)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-7, 55), Pair(26, 5), Pair(25, 61), Pair(41, 56), Pair(18, 66), Pair(-71, 45), Pair(28, -38), Pair(98, 75),
  Pair(12, 23), Pair(16, 5), Pair(7, 2), Pair(13, 16), Pair(22, 24), Pair(27, 38), Pair(13, 13), Pair(52, 50),
  Pair(9, 20), Pair(-26, 17), Pair(9, 26), Pair(16, 5), Pair(15, 35), Pair(5, 61), Pair(18, 30), Pair(8, 52)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-37, 24), Pair(-35, -94), Pair(60, -19), Pair(-39, -100), Pair(48, 13), Pair(-86, -95), Pair(72, -39), Pair(-48, -7),
  Pair(20, 87), Pair(33, -60), Pair(22, -1), Pair(-10, 92), Pair(4, 19), Pair(-76, 25), Pair(-1, -5), Pair(132, 111),
  Pair(75, 32), Pair(-30, 19), Pair(-6, 46), Pair(5, 10), Pair(-9, 26), Pair(8, -16), Pair(8, 39), Pair(107, 120)
};

constexpr ScorePair kBishopPairBonus = Pair(42, 52);

constexpr ScorePair kTempoBonus = Pair(26, 7);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H