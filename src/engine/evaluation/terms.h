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
  Pair(74, 107), Pair(343, 305), Pair(400, 386), Pair(526, 729), Pair(1173, 1253), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kNormalPieceSquareTable = {};

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
        Pair(0, 0), Pair(10, -10), Pair(-69, 13), Pair(-54, 7), Pair(30, -25), Pair(-23, -6), Pair(-21, -6), Pair(57, 3),
        Pair(1, 50), Pair(35, 1), Pair(68, -44), Pair(0, -15), Pair(-14, -4), Pair(-27, 9), Pair(10, -1), Pair(-4, 6),
        Pair(-45, -3), Pair(5, -4), Pair(-27, -9), Pair(-25, -8), Pair(-32, 3), Pair(-29, 1), Pair(-13, 2), Pair(28, -11),
        Pair(7, 65), Pair(55, -40), Pair(25, -24), Pair(1, -17), Pair(-18, -7), Pair(-13, -6), Pair(-22, -8), Pair(-32, 4),
        Pair(-80, 36), Pair(33, -36), Pair(21, -40), Pair(16, -9), Pair(-8, -8), Pair(-6, -12), Pair(-32, -15), Pair(-18, -10),
        Pair(0, 0), Pair(-21, 47), Pair(-7, -15), Pair(-35, 6), Pair(18, -31), Pair(7, -12), Pair(5, -22), Pair(-23, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-78, -145), Pair(15, -13), Pair(69, -8), Pair(-9, 55), Pair(-104, -166), Pair(79, -164), Pair(15, -193), Pair(-3, -61),
        Pair(42, 46), Pair(-10, -37), Pair(58, -36), Pair(48, -65), Pair(-14, -48), Pair(-61, -82), Pair(3, -53), Pair(80, 6),
        Pair(12, -59), Pair(61, -123), Pair(-37, -32), Pair(-6, 13), Pair(35, -62), Pair(37, -110), Pair(-10, -20), Pair(-40, 49),
        Pair(78, -1), Pair(65, -59), Pair(14, 11), Pair(-30, -12), Pair(37, -8), Pair(139, -59), Pair(154, -101), Pair(-49, -116),
        Pair(-83, -114), Pair(-23, -3), Pair(-61, 5), Pair(112, -60), Pair(-21, 1), Pair(167, -79), Pair(136, -87), Pair(-17, -51),
        Pair(15, -61), Pair(-10, 35), Pair(35, 12), Pair(105, -21), Pair(58, -51), Pair(83, -107), Pair(46, -102), Pair(-56, -120),
        Pair(0, 0), Pair(51, -45), Pair(-123, 69), Pair(-28, -50), Pair(59, -67), Pair(-78, -55), Pair(123, -67), Pair(39, -60),
        Pair(106, 108), Pair(67, 46), Pair(42, 89), Pair(-3, -102), Pair(-31, -79), Pair(-47, -86), Pair(-171, -16), Pair(-23, -65)
      },
      { // Piece 2
        Pair(-50, -67), Pair(-54, 64), Pair(-15, -93), Pair(-27, 112), Pair(-6, -70), Pair(-109, -71), Pair(-16, -152), Pair(39, 262),
        Pair(10, 75), Pair(-134, 5), Pair(54, -8), Pair(-16, -117), Pair(-41, 109), Pair(-140, 25), Pair(-156, 130), Pair(-134, 12),
        Pair(-14, -5), Pair(-39, 135), Pair(5, -7), Pair(-14, 14), Pair(87, -35), Pair(-76, 174), Pair(85, 15), Pair(6, 8),
        Pair(-30, -14), Pair(15, -63), Pair(70, 40), Pair(14, 18), Pair(40, 141), Pair(-27, 37), Pair(-193, 59), Pair(-69, 26),
        Pair(-5, -129), Pair(102, -60), Pair(-92, 6), Pair(-47, 140), Pair(84, -36), Pair(-28, 51), Pair(10, 30), Pair(-108, -18),
        Pair(-50, 48), Pair(103, -8), Pair(-125, 158), Pair(26, 19), Pair(21, 41), Pair(42, -42), Pair(114, 9), Pair(-5, -25),
        Pair(0, 0), Pair(11, 143), Pair(52, -13), Pair(-96, 86), Pair(-10, -6), Pair(-13, 2), Pair(0, -30), Pair(19, -11),
        Pair(117, 166), Pair(12, 105), Pair(4, 48), Pair(-27, -12), Pair(32, 49), Pair(-19, -10), Pair(-110, -126), Pair(-134, -37)
      },
      { // Piece 3
        Pair(82, 46), Pair(123, -17), Pair(74, 6), Pair(-32, -17), Pair(-32, 40), Pair(76, -40), Pair(149, -12), Pair(70, -46),
        Pair(71, 61), Pair(193, -8), Pair(64, 3), Pair(162, -5), Pair(90, -46), Pair(159, -45), Pair(126, 14), Pair(31, 14),
        Pair(13, 80), Pair(156, -66), Pair(51, 3), Pair(-3, -27), Pair(37, 1), Pair(-76, 61), Pair(-21, 70), Pair(22, 24),
        Pair(-13, 65), Pair(-48, 4), Pair(72, 56), Pair(36, 29), Pair(88, -90), Pair(2, 73), Pair(59, 40), Pair(-12, -10),
        Pair(-69, 80), Pair(-12, -34), Pair(-60, 10), Pair(131, -48), Pair(24, -20), Pair(55, 20), Pair(-83, 63), Pair(29, -14),
        Pair(24, 28), Pair(-63, 43), Pair(27, 43), Pair(-9, 57), Pair(13, -80), Pair(112, -34), Pair(-11, -60), Pair(-54, -13),
        Pair(0, 0), Pair(-6, 93), Pair(53, -44), Pair(38, -21), Pair(-44, 105), Pair(87, -33), Pair(51, 83), Pair(23, 25),
        Pair(31, 121), Pair(3, 32), Pair(-12, 109), Pair(3, 74), Pair(27, 102), Pair(1, 99), Pair(167, 8), Pair(0, 94)
      },
      { // Piece 4
        Pair(26, -51), Pair(45, -9), Pair(51, -3), Pair(54, -56), Pair(98, 26), Pair(26, 61), Pair(-49, 3), Pair(75, 25),
        Pair(1, 30), Pair(-18, 36), Pair(25, 98), Pair(-72, -28), Pair(47, 85), Pair(82, -68), Pair(18, 52), Pair(-6, -45),
        Pair(1, -118), Pair(21, -44), Pair(-48, 8), Pair(-33, 69), Pair(10, -1), Pair(74, 20), Pair(-171, -12), Pair(-26, -32),
        Pair(68, -32), Pair(-34, -49), Pair(-34, 52), Pair(-39, 72), Pair(-52, 50), Pair(29, 16), Pair(10, -119), Pair(-34, 15),
        Pair(60, -196), Pair(-89, 7), Pair(-37, -70), Pair(-45, 52), Pair(-61, -11), Pair(38, -91), Pair(-5, 10), Pair(57, 22),
        Pair(-123, -128), Pair(124, 51), Pair(36, -11), Pair(-67, -40), Pair(-75, 63), Pair(-43, -10), Pair(-104, 34), Pair(43, -60),
        Pair(0, 0), Pair(44, 1), Pair(34, 26), Pair(15, -107), Pair(-115, -33), Pair(3, -159), Pair(21, 28), Pair(-131, -50),
        Pair(-35, -86), Pair(0, -29), Pair(-67, 92), Pair(-71, 118), Pair(-43, -46), Pair(-140, -42), Pair(-114, -23), Pair(-42, -3)
      },
      { // Piece 5
        Pair(-3, -32), Pair(-19, -25), Pair(8, -74), Pair(17, -22), Pair(59, -50), Pair(-17, -33), Pair(-46, -92), Pair(-4, -58),
        Pair(-70, -128), Pair(29, -45), Pair(-39, 8), Pair(-16, 2), Pair(-30, -35), Pair(85, 32), Pair(-18, -99), Pair(-13, -48),
        Pair(-43, -120), Pair(-65, -19), Pair(64, -4), Pair(-26, -52), Pair(65, -39), Pair(97, -31), Pair(90, -45), Pair(24, -13),
        Pair(-76, -12), Pair(-45, 28), Pair(-41, 4), Pair(64, 42), Pair(-3, 24), Pair(-84, -25), Pair(-55, -15), Pair(33, -71),
        Pair(40, 18), Pair(-78, 64), Pair(124, -5), Pair(94, 31), Pair(-18, 21), Pair(69, 5), Pair(30, -32), Pair(-35, -96),
        Pair(-51, 145), Pair(-19, 109), Pair(125, 40), Pair(-9, 55), Pair(75, 17), Pair(-47, 2), Pair(-5, -27), Pair(3, -8),
        Pair(0, 0), Pair(-108, 203), Pair(22, 42), Pair(86, 46), Pair(-12, 11), Pair(-38, 11), Pair(-29, -9), Pair(56, -77),
        Pair(170, 162), Pair(17, 70), Pair(-89, 51), Pair(-55, -12), Pair(-49, -15), Pair(4, -94), Pair(-32, -63), Pair(-76, -43)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 10), Pair(0, 0), Pair(14, -32), Pair(31, 8), Pair(22, -21), Pair(-7, 25), Pair(-84, 0), Pair(6, -28),
        Pair(-30, -5), Pair(-113, 21), Pair(-33, 9), Pair(43, -47), Pair(-48, 17), Pair(30, -16), Pair(-14, 16), Pair(-31, -5),
        Pair(15, -16), Pair(28, -34), Pair(11, -36), Pair(-13, 11), Pair(-17, -9), Pair(-10, 5), Pair(6, -24), Pair(-37, 9),
        Pair(29, -26), Pair(-11, -9), Pair(-20, 6), Pair(-1, -4), Pair(-9, -11), Pair(-29, -5), Pair(-26, -6), Pair(25, -19),
        Pair(26, -12), Pair(20, -16), Pair(-4, -12), Pair(-31, -4), Pair(-32, 1), Pair(-38, -7), Pair(-21, -8), Pair(39, -25),
        Pair(-6, -5), Pair(0, 0), Pair(6, 16), Pair(55, -36), Pair(-32, 0), Pair(8, -14), Pair(-23, -3), Pair(-14, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, -28), Pair(9, -27), Pair(-6, -43), Pair(-66, -90), Pair(-6, 62), Pair(52, -70), Pair(-11, -68), Pair(81, 33),
        Pair(-8, -163), Pair(-50, -47), Pair(117, 73), Pair(-28, -80), Pair(27, -30), Pair(-58, -52), Pair(-52, -119), Pair(-8, -167),
        Pair(51, -6), Pair(37, -42), Pair(-48, 36), Pair(-72, 33), Pair(119, -86), Pair(128, -39), Pair(-59, 11), Pair(17, -79),
        Pair(-127, -17), Pair(-2, -22), Pair(32, 2), Pair(34, -59), Pair(149, -100), Pair(91, -31), Pair(-7, -20), Pair(149, -92),
        Pair(193, 16), Pair(-57, 55), Pair(88, -68), Pair(64, 15), Pair(65, 5), Pair(-8, -1), Pair(-109, 11), Pair(-43, -69),
        Pair(22, 119), Pair(47, -94), Pair(-39, 119), Pair(-109, -4), Pair(-102, 24), Pair(38, 19), Pair(-60, -8), Pair(-45, -87),
        Pair(-76, -154), Pair(0, 0), Pair(-43, -6), Pair(-94, 114), Pair(89, -65), Pair(116, -100), Pair(22, 42), Pair(-38, 99),
        Pair(0, 0), Pair(-30, 127), Pair(-106, -55), Pair(-34, -87), Pair(4, 40), Pair(-65, 43), Pair(-59, -99), Pair(-63, -10)
      },
      { // Piece 2
        Pair(0, 21), Pair(-18, 45), Pair(-107, 31), Pair(-6, -5), Pair(-193, 12), Pair(34, -58), Pair(-42, 3), Pair(11, 24),
        Pair(-82, 17), Pair(14, 104), Pair(-22, 32), Pair(-108, 42), Pair(12, -34), Pair(10, 32), Pair(-13, 59), Pair(-78, 146),
        Pair(125, 18), Pair(-60, 108), Pair(-52, 48), Pair(48, 21), Pair(-80, 76), Pair(172, 66), Pair(31, 169), Pair(38, -120),
        Pair(-25, -38), Pair(24, 54), Pair(56, -80), Pair(16, 57), Pair(41, -55), Pair(37, 168), Pair(-11, -49), Pair(-82, 27),
        Pair(79, -18), Pair(-5, -128), Pair(80, -36), Pair(81, -1), Pair(-53, 142), Pair(9, -14), Pair(14, 36), Pair(87, -48),
        Pair(-102, -6), Pair(-96, 141), Pair(4, 47), Pair(-62, 153), Pair(56, 28), Pair(-43, 87), Pair(12, 34), Pair(59, -44),
        Pair(25, 172), Pair(0, 0), Pair(-47, 143), Pair(24, -36), Pair(-36, -70), Pair(-58, -23), Pair(-14, -19), Pair(-11, -57),
        Pair(-2, -5), Pair(-32, 227), Pair(-97, 48), Pair(-5, 57), Pair(37, 0), Pair(-79, 14), Pair(-68, -65), Pair(42, 152)
      },
      { // Piece 3
        Pair(64, -156), Pair(53, 20), Pair(-67, -13), Pair(61, -13), Pair(45, -41), Pair(-8, 16), Pair(84, 3), Pair(148, -15),
        Pair(-7, -14), Pair(5, 35), Pair(138, 3), Pair(106, -38), Pair(95, 37), Pair(110, -16), Pair(64, -22), Pair(-72, 71),
        Pair(40, -20), Pair(56, 38), Pair(-59, -23), Pair(-10, -21), Pair(78, -66), Pair(-12, -16), Pair(-10, 29), Pair(109, 15),
        Pair(132, -90), Pair(30, 35), Pair(33, -7), Pair(29, -23), Pair(21, -23), Pair(-90, -34), Pair(5, 14), Pair(55, 83),
        Pair(-23, -37), Pair(-1, 57), Pair(-47, 90), Pair(-34, -1), Pair(-87, 41), Pair(121, 45), Pair(-128, 40), Pair(-51, 5),
        Pair(67, -11), Pair(22, 42), Pair(-47, 27), Pair(73, -56), Pair(23, 85), Pair(-36, 41), Pair(44, -66), Pair(23, -26),
        Pair(78, -41), Pair(0, 0), Pair(-83, -8), Pair(-95, 79), Pair(-8, 42), Pair(182, -26), Pair(77, -21), Pair(137, -103),
        Pair(-38, 90), Pair(64, 70), Pair(-42, 22), Pair(-43, 59), Pair(40, 44), Pair(-37, 82), Pair(-26, 62), Pair(-7, 8)
      },
      { // Piece 4
        Pair(92, 63), Pair(-21, 39), Pair(164, 72), Pair(6, 5), Pair(50, 61), Pair(17, -19), Pair(-51, -35), Pair(168, 38),
        Pair(-28, -15), Pair(-183, 56), Pair(85, 25), Pair(-80, -22), Pair(48, 100), Pair(-17, 95), Pair(-28, -39), Pair(-58, -81),
        Pair(-38, 80), Pair(-11, 74), Pair(-76, -104), Pair(43, 119), Pair(-39, 3), Pair(95, 126), Pair(-43, -29), Pair(69, -57),
        Pair(-123, -8), Pair(-101, -7), Pair(-83, -17), Pair(-31, 49), Pair(97, 54), Pair(112, -20), Pair(50, 15), Pair(126, -97),
        Pair(-31, 167), Pair(17, -35), Pair(-121, 34), Pair(-92, -102), Pair(-11, 110), Pair(-21, 59), Pair(-26, -77), Pair(105, -137),
        Pair(-83, -74), Pair(-54, -69), Pair(32, -52), Pair(-21, 64), Pair(-73, -11), Pair(-30, -11), Pair(49, -145), Pair(3, -57),
        Pair(-21, -129), Pair(0, 0), Pair(14, -12), Pair(-64, -130), Pair(-37, -136), Pair(12, 43), Pair(67, 11), Pair(-81, -25),
        Pair(-44, -49), Pair(-29, -3), Pair(-113, -96), Pair(-82, -22), Pair(-51, -218), Pair(-61, 24), Pair(-98, -46), Pair(-58, 41)
      },
      { // Piece 5
        Pair(-11, -28), Pair(-3, -15), Pair(0, 4), Pair(9, -72), Pair(32, -16), Pair(48, 103), Pair(-22, -21), Pair(-11, -108),
        Pair(-1, -5), Pair(-14, 14), Pair(1, -45), Pair(2, 35), Pair(-11, -89), Pair(-14, -38), Pair(28, -132), Pair(29, 22),
        Pair(-35, -76), Pair(9, -35), Pair(15, 51), Pair(18, -13), Pair(-17, -78), Pair(16, -60), Pair(-45, -58), Pair(45, -26),
        Pair(-24, -20), Pair(-17, 26), Pair(-63, 5), Pair(67, 12), Pair(59, -4), Pair(-46, -1), Pair(-30, -42), Pair(-44, -7),
        Pair(-2, -16), Pair(-37, -16), Pair(45, 21), Pair(-51, 46), Pair(28, -2), Pair(105, -16), Pair(86, -59), Pair(21, -40),
        Pair(30, 75), Pair(55, 54), Pair(23, 66), Pair(6, 43), Pair(-23, 14), Pair(44, 4), Pair(51, -61), Pair(45, -83),
        Pair(-24, 191), Pair(0, 0), Pair(-52, 115), Pair(-25, 73), Pair(36, -1), Pair(82, -3), Pair(38, -33), Pair(-52, -11),
        Pair(-11, -7), Pair(54, 132), Pair(23, 37), Pair(-200, 65), Pair(-75, 16), Pair(-24, -43), Pair(-6, -80), Pair(10, -144)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(69, -13), Pair(-14, 32), Pair(0, 0), Pair(-36, -6), Pair(-3, 35), Pair(30, 20), Pair(20, 44), Pair(22, 13),
        Pair(-5, 1), Pair(-36, 26), Pair(30, 5), Pair(56, -33), Pair(49, -28), Pair(28, 6), Pair(4, 7), Pair(-46, -8),
        Pair(25, -8), Pair(9, -12), Pair(-11, 0), Pair(15, -9), Pair(-2, -5), Pair(-21, -7), Pair(-18, -5), Pair(-57, 3),
        Pair(12, -12), Pair(1, 5), Pair(27, 17), Pair(32, -12), Pair(-5, -9), Pair(12, -22), Pair(6, -22), Pair(-35, -6),
        Pair(51, -17), Pair(-7, -3), Pair(14, -75), Pair(1, -8), Pair(-21, -11), Pair(-24, -10), Pair(-20, -7), Pair(-41, -6),
        Pair(44, -11), Pair(9, 2), Pair(0, 0), Pair(23, -47), Pair(-5, -24), Pair(-11, -2), Pair(28, -26), Pair(-44, -15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-30, -90), Pair(1, -11), Pair(51, 66), Pair(115, 131), Pair(-55, -134), Pair(-70, -74), Pair(-47, 45), Pair(-53, -183),
        Pair(-79, -115), Pair(-77, -41), Pair(-79, -40), Pair(-64, -35), Pair(-32, 98), Pair(5, -3), Pair(30, 12), Pair(-77, -63),
        Pair(-114, -27), Pair(3, 18), Pair(-90, 70), Pair(61, -94), Pair(-13, 66), Pair(112, -42), Pair(-24, -48), Pair(-84, 6),
        Pair(-65, -20), Pair(-51, -31), Pair(71, -30), Pair(-86, 8), Pair(-32, 30), Pair(27, 40), Pair(-119, 14), Pair(76, 69),
        Pair(-17, 63), Pair(69, -46), Pair(36, 96), Pair(-15, 30), Pair(53, -58), Pair(-50, 38), Pair(66, 44), Pair(-49, 24),
        Pair(-38, -68), Pair(-32, 111), Pair(123, -94), Pair(-36, 95), Pair(-3, 78), Pair(-53, -26), Pair(-96, 80), Pair(16, -1),
        Pair(-64, 33), Pair(-85, -12), Pair(0, 0), Pair(-62, 46), Pair(-154, 127), Pair(60, 12), Pair(-54, 19), Pair(2, -121),
        Pair(-10, -4), Pair(-14, -82), Pair(-43, 162), Pair(21, -20), Pair(28, 30), Pair(37, -87), Pair(43, -68), Pair(0, 22)
      },
      { // Piece 2
        Pair(9, 63), Pair(-9, -68), Pair(-82, -3), Pair(-52, -129), Pair(-5, 125), Pair(-4, 97), Pair(-16, -12), Pair(-70, -56),
        Pair(-65, -36), Pair(-11, -21), Pair(-41, 30), Pair(-96, -58), Pair(10, 92), Pair(13, 9), Pair(25, 117), Pair(96, -16),
        Pair(19, -47), Pair(69, 22), Pair(-24, 13), Pair(-168, 118), Pair(-46, 21), Pair(-26, 94), Pair(-24, 73), Pair(70, 82),
        Pair(-121, 39), Pair(-25, -21), Pair(149, -19), Pair(107, -2), Pair(71, 54), Pair(111, 53), Pair(-70, 149), Pair(135, -60),
        Pair(-26, 35), Pair(-1, 8), Pair(-57, -23), Pair(118, 55), Pair(88, -41), Pair(-132, 186), Pair(-44, -36), Pair(-84, -101),
        Pair(-102, 133), Pair(-110, 66), Pair(-21, 139), Pair(178, -52), Pair(-48, 146), Pair(-27, 32), Pair(-79, -29), Pair(23, -65),
        Pair(-52, -37), Pair(26, 129), Pair(0, 0), Pair(-36, 126), Pair(-56, -44), Pair(-24, 113), Pair(98, -114), Pair(-66, -124),
        Pair(61, 81), Pair(-9, -31), Pair(1, 210), Pair(-87, 65), Pair(113, 4), Pair(-36, 13), Pair(16, 6), Pair(105, 37)
      },
      { // Piece 3
        Pair(-29, 4), Pair(-6, -42), Pair(127, 8), Pair(52, 35), Pair(13, 83), Pair(36, 68), Pair(68, 16), Pair(35, -47),
        Pair(84, -73), Pair(45, -5), Pair(69, 41), Pair(75, 5), Pair(54, 0), Pair(-14, 123), Pair(1, -7), Pair(95, 5),
        Pair(76, -27), Pair(68, -68), Pair(13, 51), Pair(11, 11), Pair(22, -74), Pair(224, -70), Pair(57, 11), Pair(-49, 36),
        Pair(128, -28), Pair(95, 23), Pair(27, 37), Pair(-10, 59), Pair(-56, 39), Pair(44, 14), Pair(-76, 31), Pair(-182, 43),
        Pair(-31, 50), Pair(159, -53), Pair(-50, 69), Pair(79, -21), Pair(45, -68), Pair(10, -38), Pair(96, -11), Pair(-146, -16),
        Pair(18, 33), Pair(52, -5), Pair(46, 13), Pair(59, 23), Pair(42, 15), Pair(-100, 8), Pair(-69, -51), Pair(-55, -73),
        Pair(-122, 29), Pair(5, 83), Pair(0, 0), Pair(60, -37), Pair(23, 33), Pair(87, -37), Pair(-121, -2), Pair(-1, -1),
        Pair(-31, 53), Pair(39, -53), Pair(47, 103), Pair(67, 13), Pair(6, 41), Pair(53, 61), Pair(-30, 121), Pair(-43, 71)
      },
      { // Piece 4
        Pair(31, -27), Pair(152, 11), Pair(-131, 81), Pair(12, 0), Pair(-64, -133), Pair(-23, -63), Pair(44, 57), Pair(-2, 113),
        Pair(-51, 77), Pair(-24, -9), Pair(-67, -4), Pair(-66, -25), Pair(-20, -6), Pair(-13, 48), Pair(-42, 125), Pair(-49, -14),
        Pair(9, 14), Pair(34, 102), Pair(27, -14), Pair(10, -32), Pair(-43, -3), Pair(-71, 94), Pair(-5, 26), Pair(0, 61),
        Pair(-32, 72), Pair(70, -100), Pair(36, 78), Pair(-159, 86), Pair(-12, -45), Pair(2, 65), Pair(38, -55), Pair(72, 37),
        Pair(-58, -86), Pair(-93, 23), Pair(39, -115), Pair(13, -121), Pair(-94, 73), Pair(-25, 21), Pair(55, -32), Pair(68, -136),
        Pair(-66, -38), Pair(13, -103), Pair(16, 7), Pair(-12, -41), Pair(32, -77), Pair(45, -106), Pair(-26, 69), Pair(-41, -8),
        Pair(21, -26), Pair(-65, 8), Pair(0, 0), Pair(42, -54), Pair(-69, -28), Pair(-34, 14), Pair(28, -116), Pair(-35, 48),
        Pair(-4, -21), Pair(55, -3), Pair(36, -116), Pair(-90, -79), Pair(-99, 1), Pair(37, -107), Pair(35, 3), Pair(-57, -76)
      },
      { // Piece 5
        Pair(0, 33), Pair(-1, -33), Pair(-20, -116), Pair(-15, -43), Pair(-3, -130), Pair(-19, -133), Pair(12, -151), Pair(0, -52),
        Pair(-5, -6), Pair(-8, -52), Pair(-7, 14), Pair(4, 25), Pair(-25, -74), Pair(16, -64), Pair(-11, -98), Pair(-10, -46),
        Pair(-94, -137), Pair(26, 48), Pair(-63, -61), Pair(66, -4), Pair(-1, -8), Pair(33, -16), Pair(14, 51), Pair(11, -37),
        Pair(0, -65), Pair(15, -18), Pair(-7, -5), Pair(42, 56), Pair(-14, 39), Pair(111, 15), Pair(12, -33), Pair(-53, 25),
        Pair(36, 4), Pair(15, -6), Pair(-31, 30), Pair(-13, 4), Pair(67, 35), Pair(126, -37), Pair(101, -34), Pair(-50, -49),
        Pair(-61, -1), Pair(13, 33), Pair(-57, -1), Pair(-37, 73), Pair(122, 18), Pair(40, 2), Pair(-94, 45), Pair(62, -36),
        Pair(65, -83), Pair(-17, 147), Pair(0, 0), Pair(-130, 132), Pair(27, 45), Pair(40, 44), Pair(34, -37), Pair(-1, -52),
        Pair(-104, 38), Pair(-6, -60), Pair(-224, 175), Pair(-6, -21), Pair(24, 58), Pair(-56, 37), Pair(-5, -39), Pair(-5, -75)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(54, -7), Pair(-31, -9), Pair(36, 6), Pair(0, 0), Pair(14, 11), Pair(14, 32), Pair(90, 14), Pair(56, 10),
        Pair(47, -25), Pair(-31, -3), Pair(-25, -21), Pair(-7, -11), Pair(34, -23), Pair(45, -17), Pair(85, -11), Pair(70, -10),
        Pair(-1, -4), Pair(-55, 9), Pair(15, -15), Pair(20, -11), Pair(30, -9), Pair(-4, 1), Pair(-48, -3), Pair(-8, 4),
        Pair(-19, 6), Pair(-16, 0), Pair(-20, 7), Pair(9, 18), Pair(2, -22), Pair(9, -19), Pair(48, -36), Pair(13, -19),
        Pair(-5, 0), Pair(-19, 7), Pair(-3, 26), Pair(-35, 33), Pair(-15, -4), Pair(-20, 8), Pair(-37, 1), Pair(-3, -2),
        Pair(5, -8), Pair(-27, -6), Pair(28, 6), Pair(0, 0), Pair(-30, 4), Pair(15, -21), Pair(-1, -11), Pair(4, -20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-24, -18), Pair(1, -22), Pair(15, 47), Pair(-108, -98), Pair(96, 138), Pair(23, -58), Pair(-30, -61), Pair(6, -4),
        Pair(36, -68), Pair(77, 43), Pair(-16, -8), Pair(-5, 26), Pair(36, -57), Pair(98, 5), Pair(0, 70), Pair(-14, -9),
        Pair(9, 20), Pair(40, -11), Pair(1, -27), Pair(-3, 41), Pair(40, -22), Pair(-40, -4), Pair(-9, -23), Pair(-74, 75),
        Pair(-120, 64), Pair(-102, -107), Pair(23, -29), Pair(97, 32), Pair(-116, 79), Pair(162, -61), Pair(69, -141), Pair(52, -60),
        Pair(-45, -24), Pair(48, 87), Pair(-9, 62), Pair(74, -62), Pair(43, -12), Pair(112, -138), Pair(-51, 106), Pair(108, -74),
        Pair(-40, 10), Pair(122, -8), Pair(81, 121), Pair(-90, 59), Pair(-5, 124), Pair(-41, 17), Pair(-27, -17), Pair(-151, -20),
        Pair(-62, 17), Pair(-94, 103), Pair(-99, -12), Pair(0, 0), Pair(-52, 143), Pair(-47, 81), Pair(35, -68), Pair(-56, 10),
        Pair(-37, -67), Pair(9, 10), Pair(-56, -5), Pair(108, 103), Pair(93, -36), Pair(-84, 118), Pair(-90, -14), Pair(10, -37)
      },
      { // Piece 2
        Pair(48, 138), Pair(-72, -25), Pair(-55, 24), Pair(5, -19), Pair(67, 63), Pair(32, -136), Pair(43, 115), Pair(40, -65),
        Pair(-66, 28), Pair(69, -56), Pair(79, -29), Pair(-38, 77), Pair(-26, 28), Pair(-61, 96), Pair(64, 26), Pair(3, 84),
        Pair(-34, 20), Pair(-13, -27), Pair(-99, 124), Pair(32, -57), Pair(-79, 15), Pair(147, -129), Pair(-45, 31), Pair(-32, 41),
        Pair(-32, 16), Pair(-50, 34), Pair(97, 4), Pair(-29, 22), Pair(-82, 15), Pair(-54, 55), Pair(117, 44), Pair(-183, 154),
        Pair(-33, 77), Pair(-87, 34), Pair(73, -28), Pair(94, -52), Pair(115, 6), Pair(132, -64), Pair(-5, 188), Pair(-42, 83),
        Pair(-56, -60), Pair(-34, 147), Pair(23, -10), Pair(-24, 17), Pair(3, -9), Pair(12, 106), Pair(-114, 38), Pair(-23, 16),
        Pair(-10, -56), Pair(-49, 15), Pair(73, 137), Pair(0, 0), Pair(17, 149), Pair(-10, 5), Pair(66, -33), Pair(-39, -27),
        Pair(-110, -113), Pair(-40, 9), Pair(62, 108), Pair(59, 156), Pair(-1, 3), Pair(24, -23), Pair(-61, -50), Pair(-75, 61)
      },
      { // Piece 3
        Pair(118, -47), Pair(65, -33), Pair(69, 42), Pair(99, 1), Pair(-31, -55), Pair(48, -29), Pair(33, -24), Pair(88, -5),
        Pair(-74, 29), Pair(10, 35), Pair(76, 54), Pair(16, 22), Pair(-22, 16), Pair(97, -40), Pair(102, -59), Pair(36, 10),
        Pair(-18, 15), Pair(0, -42), Pair(99, 35), Pair(-18, 43), Pair(-76, 32), Pair(139, -12), Pair(41, -35), Pair(259, -100),
        Pair(-36, 23), Pair(57, 33), Pair(-65, -29), Pair(54, 23), Pair(-4, 53), Pair(-15, -21), Pair(61, -75), Pair(37, 4),
        Pair(-117, -23), Pair(145, -82), Pair(21, -37), Pair(3, 15), Pair(54, -88), Pair(35, -141), Pair(-55, 12), Pair(33, 23),
        Pair(-115, -11), Pair(-163, 5), Pair(-45, -18), Pair(-99, 12), Pair(74, -52), Pair(83, 26), Pair(-93, -6), Pair(52, -6),
        Pair(125, -3), Pair(-29, 41), Pair(73, -42), Pair(0, 0), Pair(-96, -73), Pair(103, -86), Pair(24, -7), Pair(3, -68),
        Pair(-14, 16), Pair(-25, 60), Pair(32, 52), Pair(14, 93), Pair(-16, 79), Pair(-39, 50), Pair(28, -2), Pair(3, 32)
      },
      { // Piece 4
        Pair(125, -3), Pair(-73, -81), Pair(-2, 17), Pair(-20, 26), Pair(22, 41), Pair(46, -31), Pair(-41, -90), Pair(40, -3),
        Pair(53, 71), Pair(-89, 16), Pair(-28, -24), Pair(-6, 72), Pair(-90, 34), Pair(9, 27), Pair(41, -24), Pair(78, 4),
        Pair(-11, -8), Pair(32, 60), Pair(21, 0), Pair(63, -59), Pair(37, 135), Pair(20, -6), Pair(190, -81), Pair(23, -23),
        Pair(-4, -21), Pair(10, -84), Pair(-31, -12), Pair(50, -18), Pair(96, -1), Pair(74, -65), Pair(60, -103), Pair(-29, 163),
        Pair(-48, -94), Pair(-42, 4), Pair(-14, -128), Pair(16, 70), Pair(-11, -93), Pair(46, -35), Pair(-10, -11), Pair(109, -73),
        Pair(-122, -105), Pair(9, -14), Pair(34, 69), Pair(59, 76), Pair(-14, 17), Pair(-25, 48), Pair(22, -99), Pair(23, -74),
        Pair(-32, -106), Pair(-66, -85), Pair(-100, -17), Pair(0, 0), Pair(46, -80), Pair(-16, -9), Pair(-88, -45), Pair(-55, -3),
        Pair(-158, 14), Pair(38, 85), Pair(-71, 2), Pair(22, -165), Pair(-87, -86), Pair(-61, -140), Pair(28, -9), Pair(-21, -12)
      },
      { // Piece 5
        Pair(-15, -83), Pair(-4, -47), Pair(1, 16), Pair(-1, -7), Pair(-3, -29), Pair(-37, -117), Pair(-7, -49), Pair(-4, -14),
        Pair(-3, -14), Pair(-44, -111), Pair(-18, -201), Pair(-2, -11), Pair(0, -37), Pair(-7, -54), Pair(-22, -25), Pair(-14, -76),
        Pair(7, -18), Pair(3, 9), Pair(23, -76), Pair(-14, -76), Pair(55, -14), Pair(47, 9), Pair(31, -70), Pair(0, -74),
        Pair(-12, -67), Pair(1, -45), Pair(60, -64), Pair(-85, 28), Pair(-32, 67), Pair(39, 5), Pair(33, -19), Pair(78, 24),
        Pair(-72, -61), Pair(55, 130), Pair(15, -22), Pair(102, 22), Pair(-90, 40), Pair(-19, 26), Pair(27, -62), Pair(9, -45),
        Pair(-2, -9), Pair(29, -52), Pair(-11, 78), Pair(-101, 144), Pair(-20, 58), Pair(99, 30), Pair(-30, 54), Pair(18, -3),
        Pair(86, 19), Pair(-98, -96), Pair(-28, 107), Pair(0, 0), Pair(-99, 107), Pair(-11, 24), Pair(2, 5), Pair(55, -53),
        Pair(-54, -25), Pair(20, -34), Pair(-31, -75), Pair(-197, 182), Pair(51, 28), Pair(63, -6), Pair(24, -44), Pair(-34, -18)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-30, 25), Pair(-22, 21), Pair(3, -35), Pair(-14, -11), Pair(0, 0), Pair(6, -42), Pair(21, -30), Pair(-7, 8),
        Pair(18, -11), Pair(-13, -8), Pair(-9, -3), Pair(57, -12), Pair(104, -32), Pair(63, 12), Pair(62, -10), Pair(-50, -6),
        Pair(-35, 13), Pair(15, -22), Pair(-7, -14), Pair(9, 8), Pair(37, -6), Pair(-10, 2), Pair(-55, 12), Pair(-29, -11),
        Pair(15, -12), Pair(-17, -15), Pair(-13, -24), Pair(18, -5), Pair(-48, 22), Pair(10, -10), Pair(21, -5), Pair(-31, 3),
        Pair(-38, 5), Pair(-30, -10), Pair(-33, -11), Pair(68, -62), Pair(29, -5), Pair(-37, 14), Pair(-12, -5), Pair(-25, -1),
        Pair(5, -15), Pair(-40, -6), Pair(40, -24), Pair(-38, -57), Pair(0, 0), Pair(-4, -16), Pair(-35, 18), Pair(-25, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-69, -157), Pair(-5, -105), Pair(-4, -8), Pair(105, -30), Pair(29, 59), Pair(-29, -52), Pair(-11, -64), Pair(21, 57),
        Pair(55, 14), Pair(4, -26), Pair(-15, 33), Pair(-57, -12), Pair(-169, -4), Pair(-71, 50), Pair(18, -35), Pair(5, -48),
        Pair(-119, -13), Pair(-52, -113), Pair(3, 28), Pair(-76, -75), Pair(106, -41), Pair(56, -10), Pair(101, -57), Pair(13, -97),
        Pair(-34, -109), Pair(-4, -61), Pair(-33, -35), Pair(-69, 6), Pair(35, 22), Pair(47, -10), Pair(96, 27), Pair(-56, -11),
        Pair(-71, -69), Pair(-42, 42), Pair(9, 76), Pair(49, 20), Pair(-13, -30), Pair(18, 15), Pair(8, -85), Pair(-15, 81),
        Pair(6, 3), Pair(18, -15), Pair(-10, 85), Pair(-86, 102), Pair(-17, 95), Pair(43, 52), Pair(-24, -12), Pair(18, -132),
        Pair(-47, -29), Pair(-4, -12), Pair(-147, 145), Pair(-14, -26), Pair(0, 0), Pair(-23, -40), Pair(-74, 57), Pair(-28, -25),
        Pair(-13, -79), Pair(-88, 100), Pair(110, -89), Pair(-39, -91), Pair(-52, 145), Pair(59, -4), Pair(-13, -28), Pair(1, 15)
      },
      { // Piece 2
        Pair(89, -40), Pair(2, 34), Pair(-6, -19), Pair(-72, -8), Pair(-39, -79), Pair(-3, 20), Pair(-2, -25), Pair(9, -2),
        Pair(-60, 98), Pair(95, -21), Pair(-23, -4), Pair(58, 16), Pair(-72, 70), Pair(2, -22), Pair(-56, 10), Pair(-13, -59),
        Pair(56, -24), Pair(-35, 35), Pair(19, 27), Pair(-32, 93), Pair(-41, 18), Pair(-86, 77), Pair(-75, 5), Pair(24, 40),
        Pair(-91, 194), Pair(-18, 57), Pair(67, 130), Pair(111, -41), Pair(-40, -54), Pair(-134, 88), Pair(-57, 44), Pair(-63, -6),
        Pair(-121, -63), Pair(-104, 120), Pair(-84, 55), Pair(161, 71), Pair(66, 37), Pair(99, -25), Pair(6, 1), Pair(-46, 92),
        Pair(144, -53), Pair(44, -7), Pair(-29, 122), Pair(-10, -3), Pair(87, 128), Pair(-12, -45), Pair(133, 41), Pair(22, -81),
        Pair(156, -50), Pair(77, 3), Pair(-46, -32), Pair(61, 106), Pair(0, 0), Pair(-52, 124), Pair(84, -92), Pair(-80, 41),
        Pair(-46, -60), Pair(68, -34), Pair(39, 77), Pair(30, 34), Pair(-24, 226), Pair(-45, -79), Pair(-4, 84), Pair(10, 39)
      },
      { // Piece 3
        Pair(-68, -6), Pair(-60, -38), Pair(82, 1), Pair(18, 3), Pair(36, -34), Pair(-39, -109), Pair(-6, -35), Pair(16, 23),
        Pair(105, -33), Pair(-42, -40), Pair(-101, 10), Pair(-176, 67), Pair(51, 85), Pair(17, 25), Pair(-43, 24), Pair(-79, 9),
        Pair(49, -91), Pair(-6, -18), Pair(-21, 61), Pair(28, -31), Pair(25, 31), Pair(120, -125), Pair(86, -59), Pair(-110, -5),
        Pair(164, -25), Pair(-17, -49), Pair(14, -34), Pair(-27, -10), Pair(52, -25), Pair(0, -106), Pair(-23, 3), Pair(-56, -24),
        Pair(56, -45), Pair(-106, -45), Pair(-88, -62), Pair(-16, -52), Pair(25, -9), Pair(-55, -30), Pair(97, -110), Pair(-87, -9),
        Pair(-153, 65), Pair(-124, -86), Pair(97, -111), Pair(56, -52), Pair(39, 7), Pair(5, -7), Pair(-13, -19), Pair(150, 39),
        Pair(28, 15), Pair(47, -58), Pair(86, 87), Pair(52, -16), Pair(0, 0), Pair(-29, 79), Pair(-13, 2), Pair(-15, -105),
        Pair(-92, 87), Pair(32, -10), Pair(-108, 48), Pair(-49, -50), Pair(75, 57), Pair(30, 22), Pair(21, 23), Pair(-50, 5)
      },
      { // Piece 4
        Pair(16, 49), Pair(-35, -10), Pair(3, 53), Pair(-30, 66), Pair(-60, -3), Pair(23, -16), Pair(-28, -84), Pair(59, -29),
        Pair(-87, 45), Pair(21, 11), Pair(18, -45), Pair(-75, 38), Pair(53, 46), Pair(127, 189), Pair(-18, 8), Pair(-23, 33),
        Pair(41, -12), Pair(90, 112), Pair(-4, -38), Pair(-21, -30), Pair(-43, -26), Pair(114, 105), Pair(6, -76), Pair(36, 3),
        Pair(-28, 50), Pair(-59, 67), Pair(10, -5), Pair(127, 15), Pair(90, -5), Pair(45, 44), Pair(146, -57), Pair(128, 97),
        Pair(66, 119), Pair(32, 26), Pair(-31, 12), Pair(-96, -76), Pair(-55, -17), Pair(-4, -29), Pair(46, -10), Pair(-71, 11),
        Pair(-197, -109), Pair(30, -56), Pair(59, -4), Pair(-12, -156), Pair(96, 49), Pair(-94, -10), Pair(58, 64), Pair(-86, -15),
        Pair(-11, -33), Pair(-142, -12), Pair(94, -38), Pair(-101, 31), Pair(0, 0), Pair(-71, -13), Pair(-64, -12), Pair(-46, -75),
        Pair(5, -98), Pair(-106, -63), Pair(29, -111), Pair(7, -10), Pair(-17, -108), Pair(-1, 27), Pair(-104, -64), Pair(-52, -23)
      },
      { // Piece 5
        Pair(-33, -76), Pair(-10, -116), Pair(0, -31), Pair(-41, -126), Pair(17, 21), Pair(-14, -81), Pair(-6, 7), Pair(13, 17),
        Pair(14, -33), Pair(22, 53), Pair(-21, -39), Pair(6, -61), Pair(18, -7), Pair(20, 20), Pair(-45, -10), Pair(-5, -14),
        Pair(40, -59), Pair(-37, -92), Pair(-6, -29), Pair(-20, -37), Pair(22, 22), Pair(47, -14), Pair(51, 53), Pair(-22, 36),
        Pair(-51, -84), Pair(8, 0), Pair(-36, 67), Pair(-12, -37), Pair(-51, -73), Pair(14, 17), Pair(41, -46), Pair(-63, -39),
        Pair(9, -185), Pair(42, -5), Pair(-49, 29), Pair(-67, -2), Pair(-41, 73), Pair(-60, 47), Pair(-30, -10), Pair(-37, 83),
        Pair(-17, 1), Pair(28, -15), Pair(-45, 23), Pair(-39, 66), Pair(58, 95), Pair(-21, 114), Pair(50, 17), Pair(74, -105),
        Pair(-7, -69), Pair(-8, 4), Pair(49, -36), Pair(-117, 104), Pair(0, 0), Pair(-58, 84), Pair(2, 33), Pair(33, 19),
        Pair(104, -58), Pair(106, -33), Pair(-41, 97), Pair(-5, -16), Pair(-64, 134), Pair(28, -5), Pair(92, -19), Pair(27, 1)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(23, 6), Pair(7, -25), Pair(-30, -20), Pair(-14, -32), Pair(-6, 42), Pair(0, 0), Pair(-67, 92), Pair(-60, 24),
        Pair(43, -17), Pair(-28, 24), Pair(-43, 9), Pair(37, -25), Pair(43, -10), Pair(-44, -60), Pair(-53, 28), Pair(75, -30),
        Pair(-17, -13), Pair(-26, -11), Pair(-45, -1), Pair(-11, -22), Pair(46, -24), Pair(41, -54), Pair(-30, -19), Pair(58, -10),
        Pair(-51, 6), Pair(-26, -10), Pair(15, -11), Pair(-61, 19), Pair(-1, -17), Pair(10, 1), Pair(-35, -9), Pair(-9, -8),
        Pair(-17, -4), Pair(-54, 21), Pair(-41, 16), Pair(3, -15), Pair(8, -29), Pair(39, -39), Pair(5, -12), Pair(-9, -7),
        Pair(-22, -10), Pair(-1, -26), Pair(-27, -9), Pair(-49, -7), Pair(7, -40), Pair(0, 0), Pair(60, -46), Pair(8, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-64, 0), Pair(-109, -233), Pair(-28, -8), Pair(59, 62), Pair(-16, 52), Pair(5, -1), Pair(-9, -56), Pair(11, 36),
        Pair(-27, -85), Pair(-117, -122), Pair(112, 25), Pair(-12, -69), Pair(-38, -28), Pair(7, -18), Pair(-29, -102), Pair(-55, -65),
        Pair(94, -64), Pair(-130, -83), Pair(10, 64), Pair(28, -4), Pair(33, -52), Pair(-28, -85), Pair(86, -32), Pair(-4, 49),
        Pair(50, -36), Pair(15, -79), Pair(32, -79), Pair(107, -48), Pair(12, -18), Pair(16, 21), Pair(3, -104), Pair(-61, -57),
        Pair(-23, -92), Pair(-92, 86), Pair(-188, 81), Pair(123, -8), Pair(162, 26), Pair(115, -13), Pair(18, -150), Pair(-91, -157),
        Pair(-1, -231), Pair(126, 7), Pair(-59, 97), Pair(-28, -22), Pair(43, 106), Pair(-33, -67), Pair(14, -13), Pair(48, -32),
        Pair(5, -77), Pair(-74, -148), Pair(-78, -63), Pair(-158, 104), Pair(-7, -78), Pair(0, 0), Pair(2, 38), Pair(41, 100),
        Pair(26, 75), Pair(-98, -69), Pair(-16, -33), Pair(-125, -57), Pair(-40, -5), Pair(14, 119), Pair(16, 25), Pair(60, 50)
      },
      { // Piece 2
        Pair(-52, -52), Pair(-25, -90), Pair(10, 49), Pair(-104, 13), Pair(-16, 129), Pair(-89, -147), Pair(25, 156), Pair(-23, -83),
        Pair(13, 95), Pair(149, 59), Pair(-68, -20), Pair(-6, 96), Pair(1, -79), Pair(-54, 83), Pair(42, 6), Pair(14, -64),
        Pair(-66, 129), Pair(90, -122), Pair(-87, 95), Pair(58, -97), Pair(-139, 50), Pair(-9, -72), Pair(52, 116), Pair(9, -44),
        Pair(13, -38), Pair(-97, 162), Pair(-78, 110), Pair(23, -22), Pair(114, -51), Pair(106, 35), Pair(105, -16), Pair(-103, 22),
        Pair(22, 68), Pair(17, 51), Pair(28, 118), Pair(-16, -27), Pair(139, -12), Pair(-34, -63), Pair(82, -3), Pair(91, 83),
        Pair(-36, -54), Pair(-59, -51), Pair(15, -36), Pair(36, 111), Pair(78, 1), Pair(144, -12), Pair(-47, -24), Pair(-153, 83),
        Pair(-170, -165), Pair(105, -35), Pair(-70, -31), Pair(-106, -54), Pair(-90, 156), Pair(0, 0), Pair(-62, 51), Pair(-62, -65),
        Pair(16, 93), Pair(-51, -96), Pair(16, -108), Pair(54, -17), Pair(-14, -98), Pair(-89, 210), Pair(-15, -42), Pair(12, -11)
      },
      { // Piece 3
        Pair(46, 44), Pair(-39, 70), Pair(-27, -103), Pair(0, 2), Pair(89, 7), Pair(82, -46), Pair(-34, -58), Pair(100, 105),
        Pair(11, 78), Pair(-6, -18), Pair(-26, -94), Pair(-89, -124), Pair(19, 77), Pair(60, -13), Pair(-46, 15), Pair(34, -30),
        Pair(-9, 26), Pair(-84, -88), Pair(33, -42), Pair(124, -72), Pair(-24, 20), Pair(-23, 48), Pair(-15, -106), Pair(42, -41),
        Pair(22, -57), Pair(-24, -33), Pair(70, -23), Pair(-7, -7), Pair(31, 41), Pair(11, 22), Pair(78, -29), Pair(117, -67),
        Pair(22, -21), Pair(-5, 51), Pair(31, 81), Pair(-56, 48), Pair(69, -2), Pair(58, 23), Pair(-20, -28), Pair(-34, -32),
        Pair(60, 29), Pair(-72, -38), Pair(18, -67), Pair(66, -84), Pair(-4, -50), Pair(45, -16), Pair(-55, 55), Pair(-40, -51),
        Pair(133, -58), Pair(-83, -57), Pair(8, 23), Pair(40, 4), Pair(35, 16), Pair(0, 0), Pair(99, -84), Pair(-63, 13),
        Pair(-14, 29), Pair(-34, 16), Pair(-33, 24), Pair(-36, 25), Pair(19, 22), Pair(12, 73), Pair(-116, 147), Pair(-71, 68)
      },
      { // Piece 4
        Pair(-9, -61), Pair(35, 19), Pair(-114, -75), Pair(-51, 8), Pair(77, -77), Pair(7, -10), Pair(-60, -143), Pair(31, 42),
        Pair(9, 96), Pair(-66, -44), Pair(33, 30), Pair(-37, 79), Pair(20, -42), Pair(84, 7), Pair(49, 43), Pair(-29, -60),
        Pair(73, -33), Pair(67, 78), Pair(16, -63), Pair(-45, -46), Pair(-75, 34), Pair(-47, 24), Pair(-44, 17), Pair(18, -94),
        Pair(-7, 51), Pair(49, -49), Pair(-23, 8), Pair(11, -2), Pair(40, 79), Pair(-24, -50), Pair(-47, 31), Pair(-70, -155),
        Pair(5, -78), Pair(-3, 45), Pair(32, -9), Pair(43, 20), Pair(-17, 114), Pair(28, -48), Pair(-31, -8), Pair(4, 82),
        Pair(40, 38), Pair(6, -21), Pair(59, 51), Pair(1, -40), Pair(-61, -90), Pair(-80, 15), Pair(71, 33), Pair(-55, 4),
        Pair(34, -8), Pair(-31, 40), Pair(24, -57), Pair(38, 123), Pair(-5, 38), Pair(0, 0), Pair(-53, -4), Pair(-70, -24),
        Pair(11, -31), Pair(0, -3), Pair(-83, -9), Pair(13, -115), Pair(1, -40), Pair(-75, -64), Pair(-10, -32), Pair(-9, -17)
      },
      { // Piece 5
        Pair(2, -31), Pair(-18, -126), Pair(-3, -185), Pair(-19, -54), Pair(-9, -19), Pair(-6, -26), Pair(-3, -20), Pair(17, 49),
        Pair(-5, -87), Pair(-44, -108), Pair(6, -156), Pair(13, -41), Pair(-40, -116), Pair(9, -53), Pair(-7, -54), Pair(5, -86),
        Pair(-5, -17), Pair(21, 13), Pair(100, -49), Pair(76, -88), Pair(-7, -133), Pair(-74, 9), Pair(5, 57), Pair(1, -22),
        Pair(22, 11), Pair(-66, -74), Pair(1, 27), Pair(63, -46), Pair(-5, 13), Pair(-16, -49), Pair(-46, -22), Pair(-18, 13),
        Pair(-62, -82), Pair(-72, -32), Pair(13, 27), Pair(10, 61), Pair(113, -59), Pair(78, 111), Pair(173, 35), Pair(91, -24),
        Pair(-19, -78), Pair(-106, -17), Pair(0, -62), Pair(90, 39), Pair(6, 25), Pair(-16, 41), Pair(-22, 115), Pair(-78, 54),
        Pair(-95, 62), Pair(38, -91), Pair(126, -19), Pair(-36, -41), Pair(69, 115), Pair(0, 0), Pair(-58, 149), Pair(-44, 48),
        Pair(-42, -30), Pair(63, -78), Pair(-68, 2), Pair(102, -14), Pair(44, 78), Pair(-80, 161), Pair(75, 54), Pair(-71, 96)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(21, 6), Pair(84, 0), Pair(-20, -44), Pair(-90, -14), Pair(-21, 30), Pair(67, -92), Pair(0, 0), Pair(28, -8),
        Pair(-48, 0), Pair(-75, 4), Pair(24, -11), Pair(9, -19), Pair(21, -17), Pair(-85, 30), Pair(-11, -35), Pair(-37, 5),
        Pair(-19, 1), Pair(-32, -22), Pair(-9, -34), Pair(17, -16), Pair(5, -3), Pair(37, -27), Pair(71, -47), Pair(59, 3),
        Pair(16, -15), Pair(36, -28), Pair(-46, -5), Pair(-12, -20), Pair(47, -28), Pair(30, -41), Pair(-51, 22), Pair(58, 0),
        Pair(-27, 9), Pair(-3, -20), Pair(-22, -4), Pair(25, -30), Pair(27, -28), Pair(51, -2), Pair(-40, -6), Pair(19, 7),
        Pair(21, 1), Pair(-8, -20), Pair(39, -36), Pair(-16, 78), Pair(35, -28), Pair(48, -21), Pair(0, 0), Pair(45, -17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(95, 75), Pair(-115, -132), Pair(36, -57), Pair(20, -33), Pair(80, 69), Pair(70, -39), Pair(-6, -23), Pair(-2, 16),
        Pair(-72, -71), Pair(-143, -128), Pair(249, -154), Pair(-121, -29), Pair(-64, -16), Pair(-83, -71), Pair(-27, 66), Pair(-30, -12),
        Pair(25, -38), Pair(54, -76), Pair(-30, 11), Pair(127, -80), Pair(41, -26), Pair(50, -92), Pair(29, 90), Pair(32, -113),
        Pair(39, -37), Pair(-86, -47), Pair(-132, 24), Pair(-11, -94), Pair(79, 11), Pair(14, 68), Pair(41, 23), Pair(103, -18),
        Pair(25, -91), Pair(14, -120), Pair(-26, 4), Pair(-77, 43), Pair(25, -101), Pair(-129, -39), Pair(-114, 58), Pair(2, 162),
        Pair(22, 1), Pair(-47, -22), Pair(86, 36), Pair(31, 55), Pair(65, 41), Pair(-20, 78), Pair(-85, 134), Pair(-73, 111),
        Pair(-78, -71), Pair(114, 55), Pair(51, -15), Pair(-107, -2), Pair(-84, 136), Pair(177, -116), Pair(0, 0), Pair(73, 1),
        Pair(0, 0), Pair(87, -73), Pair(-86, -29), Pair(-83, -19), Pair(-79, 7), Pair(84, 0), Pair(39, 101), Pair(1, -14)
      },
      { // Piece 2
        Pair(8, 39), Pair(-49, 40), Pair(-35, -129), Pair(-12, 81), Pair(-14, 29), Pair(-76, 74), Pair(-36, -33), Pair(46, 9),
        Pair(-63, 45), Pair(-10, 134), Pair(-53, 55), Pair(-41, -70), Pair(-51, 43), Pair(-51, -120), Pair(37, 77), Pair(36, -60),
        Pair(-27, -19), Pair(-103, 140), Pair(-52, 183), Pair(-55, 102), Pair(57, 11), Pair(33, 62), Pair(2, -17), Pair(-107, 1),
        Pair(-95, 63), Pair(51, -41), Pair(-11, 135), Pair(57, 28), Pair(52, 20), Pair(45, -80), Pair(-23, 31), Pair(151, -21),
        Pair(21, 92), Pair(-109, 11), Pair(-67, -24), Pair(-33, 120), Pair(-12, -18), Pair(-118, 7), Pair(157, 50), Pair(138, 113),
        Pair(-156, 58), Pair(18, -90), Pair(-47, 12), Pair(51, 5), Pair(17, 68), Pair(-99, -46), Pair(8, 102), Pair(77, 13),
        Pair(-32, 6), Pair(-59, 48), Pair(-87, -55), Pair(-26, -43), Pair(-18, -23), Pair(177, 143), Pair(0, 0), Pair(-111, 121),
        Pair(87, 46), Pair(47, 28), Pair(-95, -37), Pair(-68, -151), Pair(-76, -18), Pair(-11, 17), Pair(46, 206), Pair(0, 0)
      },
      { // Piece 3
        Pair(-144, 78), Pair(-77, -21), Pair(8, -49), Pair(-32, 39), Pair(159, -28), Pair(26, 23), Pair(46, 5), Pair(128, -12),
        Pair(-52, 19), Pair(-64, 22), Pair(70, -64), Pair(39, -18), Pair(-38, -48), Pair(42, -98), Pair(49, -60), Pair(-63, 29),
        Pair(-48, -14), Pair(76, 4), Pair(-162, -10), Pair(23, 36), Pair(-28, -36), Pair(-7, -53), Pair(15, 19), Pair(-20, -9),
        Pair(20, -62), Pair(26, -90), Pair(-65, -7), Pair(-56, 45), Pair(18, -94), Pair(-37, -19), Pair(41, -31), Pair(10, 5),
        Pair(-103, -114), Pair(103, 23), Pair(118, -49), Pair(-41, -143), Pair(-8, -3), Pair(107, -107), Pair(-9, 9), Pair(47, 77),
        Pair(-14, -63), Pair(106, -88), Pair(93, 12), Pair(23, 2), Pair(55, 63), Pair(83, -55), Pair(205, -14), Pair(-68, -61),
        Pair(-40, -10), Pair(-79, 17), Pair(-7, 3), Pair(-48, -12), Pair(-37, 69), Pair(101, -11), Pair(0, 0), Pair(32, -64),
        Pair(-7, -2), Pair(14, 63), Pair(9, -22), Pair(-55, 118), Pair(62, -6), Pair(19, 73), Pair(35, 78), Pair(-114, 32)
      },
      { // Piece 4
        Pair(40, 112), Pair(-24, 7), Pair(-85, -30), Pair(-22, 22), Pair(-72, -82), Pair(-22, -32), Pair(-94, -122), Pair(31, -30),
        Pair(24, -8), Pair(-60, -32), Pair(-99, -44), Pair(31, 33), Pair(95, 85), Pair(39, 13), Pair(105, 108), Pair(-66, -7),
        Pair(-59, -128), Pair(84, 18), Pair(-80, -58), Pair(77, 48), Pair(50, 41), Pair(-61, -36), Pair(-5, 4), Pair(144, -19),
        Pair(46, 20), Pair(-91, -82), Pair(17, -33), Pair(63, 28), Pair(-96, -23), Pair(125, 50), Pair(-46, 74), Pair(22, 35),
        Pair(-84, -147), Pair(-135, -137), Pair(-115, -69), Pair(18, 16), Pair(-64, 19), Pair(-78, -47), Pair(38, -61), Pair(45, -1),
        Pair(-113, -109), Pair(-45, -64), Pair(-129, 41), Pair(-51, 5), Pair(98, -54), Pair(-6, -92), Pair(72, 89), Pair(-104, -87),
        Pair(-30, -2), Pair(27, -37), Pair(-21, -24), Pair(-100, -25), Pair(-69, 47), Pair(49, 130), Pair(0, 0), Pair(-69, -30),
        Pair(-12, 2), Pair(27, 13), Pair(-21, -76), Pair(79, -80), Pair(-17, -28), Pair(-68, -35), Pair(82, -62), Pair(0, 0)
      },
      { // Piece 5
        Pair(-6, -150), Pair(-16, -93), Pair(-15, -77), Pair(-15, -166), Pair(-6, 65), Pair(6, 19), Pair(-4, -49), Pair(-10, -14),
        Pair(-32, -162), Pair(-26, 0), Pair(50, -21), Pair(-7, -115), Pair(-38, -84), Pair(8, 1), Pair(-31, -134), Pair(3, -6),
        Pair(-38, -100), Pair(-11, -119), Pair(41, 34), Pair(-61, -22), Pair(68, -70), Pair(50, -1), Pair(-15, 31), Pair(-36, -105),
        Pair(15, -108), Pair(-7, -5), Pair(46, -10), Pair(5, 27), Pair(-21, -48), Pair(55, 73), Pair(56, -43), Pair(10, 46),
        Pair(-29, -16), Pair(-56, -134), Pair(65, -57), Pair(-39, 46), Pair(67, -39), Pair(68, 45), Pair(58, 41), Pair(2, 5),
        Pair(8, -37), Pair(-44, -54), Pair(72, 0), Pair(-155, 68), Pair(-66, 73), Pair(9, 87), Pair(-65, -10), Pair(64, 55),
        Pair(-26, -86), Pair(-25, -56), Pair(42, -6), Pair(-41, 57), Pair(21, 46), Pair(15, 149), Pair(0, 0), Pair(68, 150),
        Pair(-59, -95), Pair(-122, -68), Pair(33, -15), Pair(60, 21), Pair(-69, 87), Pair(-21, 11), Pair(61, 179), Pair(120, 41)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-57, -3), Pair(-6, 28), Pair(-22, -13), Pair(-56, -10), Pair(7, -8), Pair(60, -24), Pair(-28, 8), Pair(0, 0),
        Pair(-52, 15), Pair(31, -6), Pair(-59, 17), Pair(-15, -11), Pair(-21, -2), Pair(74, -28), Pair(-57, 13), Pair(62, 44),
        Pair(50, -32), Pair(-2, -1), Pair(26, -14), Pair(-4, 2), Pair(-40, 0), Pair(-1, -7), Pair(50, -36), Pair(-83, -11),
        Pair(18, -23), Pair(-2, -23), Pair(-23, -17), Pair(8, -13), Pair(-15, 3), Pair(-14, 4), Pair(35, -14), Pair(-28, -58),
        Pair(24, -20), Pair(22, -25), Pair(-10, -9), Pair(3, -20), Pair(-20, -10), Pair(-31, -21), Pair(12, -16), Pair(-66, -33),
        Pair(10, -14), Pair(-1, -17), Pair(-32, 0), Pair(-19, -27), Pair(3, 13), Pair(27, 0), Pair(20, 13), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-67, -89), Pair(-4, -163), Pair(-12, -149), Pair(-98, -40), Pair(40, 60), Pair(-22, -97), Pair(-7, -67), Pair(-11, -60),
        Pair(8, 1), Pair(-66, -101), Pair(36, -127), Pair(-4, -7), Pair(48, 58), Pair(-66, -86), Pair(159, 49), Pair(-18, -20),
        Pair(-61, -28), Pair(89, -73), Pair(-41, -117), Pair(-93, -115), Pair(-122, -2), Pair(-62, -61), Pair(2, -33), Pair(-54, -102),
        Pair(14, -73), Pair(23, -122), Pair(7, -105), Pair(64, -16), Pair(37, -21), Pair(76, -35), Pair(237, -187), Pair(-13, -135),
        Pair(-233, -164), Pair(26, -24), Pair(-41, 33), Pair(-14, -75), Pair(121, -129), Pair(-3, -75), Pair(13, -143), Pair(179, 2),
        Pair(-32, -34), Pair(167, -177), Pair(45, -33), Pair(-118, 36), Pair(37, -70), Pair(-82, 111), Pair(39, 10), Pair(29, -3),
        Pair(-30, -33), Pair(-68, -53), Pair(-74, -94), Pair(-26, -134), Pair(-38, -6), Pair(-39, 79), Pair(25, -71), Pair(0, 0),
        Pair(-4, -21), Pair(-28, -25), Pair(-156, -63), Pair(83, -108), Pair(-58, -64), Pair(-103, -36), Pair(-27, -101), Pair(-95, 114)
      },
      { // Piece 2
        Pair(-55, 93), Pair(-41, -79), Pair(15, 11), Pair(83, -14), Pair(17, 65), Pair(53, 47), Pair(7, 75), Pair(-97, -178),
        Pair(76, -83), Pair(-46, 128), Pair(-82, -73), Pair(-67, 66), Pair(-31, 20), Pair(-75, 4), Pair(-21, 63), Pair(11, 28),
        Pair(39, 92), Pair(84, 29), Pair(-38, 130), Pair(3, 20), Pair(-26, 117), Pair(41, -38), Pair(45, 33), Pair(-21, 49),
        Pair(89, -105), Pair(26, 76), Pair(-2, -31), Pair(112, 45), Pair(31, 18), Pair(-84, 84), Pair(-46, 1), Pair(5, -42),
        Pair(-48, -70), Pair(-31, 20), Pair(36, -28), Pair(-18, -26), Pair(-19, 97), Pair(20, 27), Pair(-4, -65), Pair(99, 43),
        Pair(-5, -118), Pair(3, -7), Pair(126, -71), Pair(7, 36), Pair(65, -114), Pair(2, 114), Pair(-94, 30), Pair(46, 1),
        Pair(87, 57), Pair(-53, 77), Pair(11, -111), Pair(-65, 30), Pair(81, -34), Pair(93, -166), Pair(-18, 122), Pair(0, 0),
        Pair(-60, -34), Pair(87, 35), Pair(-78, -7), Pair(-62, 27), Pair(33, -111), Pair(-73, 36), Pair(-9, -55), Pair(58, 152)
      },
      { // Piece 3
        Pair(108, -19), Pair(-11, -71), Pair(-16, -20), Pair(54, 9), Pair(-23, 10), Pair(-10, 2), Pair(29, -165), Pair(81, -25),
        Pair(97, -38), Pair(-100, -75), Pair(71, -67), Pair(10, -69), Pair(-60, -15), Pair(-106, 80), Pair(8, 11), Pair(0, 25),
        Pair(89, -13), Pair(-5, -30), Pair(55, -58), Pair(13, -102), Pair(47, -40), Pair(12, -107), Pair(20, -7), Pair(-16, -13),
        Pair(1, -114), Pair(-53, 0), Pair(0, -32), Pair(-41, -61), Pair(-100, -64), Pair(-47, -109), Pair(98, -105), Pair(-65, 33),
        Pair(107, -28), Pair(17, -122), Pair(93, 36), Pair(-1, -31), Pair(-91, -48), Pair(190, -23), Pair(-17, -74), Pair(-5, 38),
        Pair(89, -102), Pair(-25, -17), Pair(125, -76), Pair(10, 12), Pair(-60, 54), Pair(-29, 48), Pair(54, 14), Pair(31, -10),
        Pair(40, -67), Pair(-33, -32), Pair(-37, 70), Pair(24, 46), Pair(-65, 130), Pair(119, -71), Pair(104, -29), Pair(0, 0),
        Pair(-55, 93), Pair(-38, 65), Pair(-154, 85), Pair(-39, 84), Pair(-13, -25), Pair(73, 4), Pair(168, 83), Pair(-45, 119)
      },
      { // Piece 4
        Pair(-28, -80), Pair(-3, 0), Pair(-36, -44), Pair(-62, -31), Pair(-38, -88), Pair(38, -7), Pair(30, 19), Pair(38, 24),
        Pair(-3, 95), Pair(-37, 34), Pair(-64, 33), Pair(19, 134), Pair(7, 4), Pair(109, 48), Pair(28, 7), Pair(11, 7),
        Pair(116, 7), Pair(8, -19), Pair(39, -89), Pair(7, 11), Pair(-64, -20), Pair(-12, -63), Pair(191, 155), Pair(-31, 27),
        Pair(-132, -65), Pair(70, -68), Pair(49, 33), Pair(41, 16), Pair(-115, -79), Pair(6, -95), Pair(-37, 28), Pair(-15, -67),
        Pair(-2, -114), Pair(23, 6), Pair(-8, 39), Pair(82, 1), Pair(-69, -79), Pair(26, -39), Pair(-28, -39), Pair(126, 41),
        Pair(49, 37), Pair(16, 43), Pair(-1, 12), Pair(-57, 58), Pair(-37, -35), Pair(-51, -1), Pair(49, 7), Pair(64, -46),
        Pair(99, 21), Pair(25, 3), Pair(41, -105), Pair(-41, -118), Pair(37, 48), Pair(-7, 53), Pair(-56, -98), Pair(0, 0),
        Pair(-2, -67), Pair(-154, 48), Pair(90, -24), Pair(-23, 40), Pair(-51, -81), Pair(-5, 82), Pair(-39, -13), Pair(-91, -88)
      },
      { // Piece 5
        Pair(-2, -74), Pair(0, -156), Pair(-9, -99), Pair(-8, -90), Pair(19, 148), Pair(-23, -118), Pair(-4, -19), Pair(-10, -44),
        Pair(46, -104), Pair(-14, -55), Pair(-34, -90), Pair(-13, 50), Pair(-43, -44), Pair(-3, -1), Pair(-11, -54), Pair(-9, -53),
        Pair(-8, -52), Pair(-38, 25), Pair(-6, -56), Pair(-24, -86), Pair(145, -10), Pair(76, 20), Pair(27, 14), Pair(-22, -65),
        Pair(36, -116), Pair(53, 20), Pair(-78, 17), Pair(49, -15), Pair(1, 25), Pair(70, 5), Pair(69, -71), Pair(-32, -177),
        Pair(-15, -48), Pair(-88, -63), Pair(185, -36), Pair(-16, -4), Pair(-1, 23), Pair(12, 59), Pair(-82, 72), Pair(34, 29),
        Pair(-6, -14), Pair(5, -61), Pair(-27, 2), Pair(161, -21), Pair(-18, 24), Pair(25, 55), Pair(-101, 126), Pair(-46, 144),
        Pair(-73, -15), Pair(-39, -41), Pair(30, -61), Pair(-72, 22), Pair(-65, 87), Pair(-35, 87), Pair(-221, 207), Pair(0, 0),
        Pair(-19, -77), Pair(27, -93), Pair(-37, -108), Pair(37, -57), Pair(-134, -92), Pair(-154, 98), Pair(74, 18), Pair(126, 164)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, -50), Pair(30, 5), Pair(5, -1), Pair(-47, 25), Pair(-18, 11), Pair(-43, 17), Pair(48, 0), Pair(52, -14),
        Pair(0, 0), Pair(-1, -15), Pair(-13, 6), Pair(-10, 1), Pair(-23, 7), Pair(-19, -6), Pair(-20, 4), Pair(-15, 10),
        Pair(-16, -40), Pair(0, -6), Pair(10, -7), Pair(9, -12), Pair(8, -6), Pair(-9, -3), Pair(-10, 1), Pair(-16, 9),
        Pair(-3, -5), Pair(-1, 1), Pair(2, -8), Pair(0, -9), Pair(-3, -4), Pair(-13, 1), Pair(-6, -3), Pair(-14, 0),
        Pair(0, 0), Pair(-3, -7), Pair(4, -10), Pair(-1, -10), Pair(-5, -8), Pair(-1, -6), Pair(-7, -8), Pair(-9, -5),
        Pair(23, 22), Pair(-7, -27), Pair(2, -10), Pair(10, -13), Pair(3, -9), Pair(-6, -5), Pair(-14, -3), Pair(-8, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(24, 35), Pair(29, -3), Pair(59, 14), Pair(51, -82), Pair(137, -85), Pair(-19, -36), Pair(-57, -151), Pair(-69, -9),
        Pair(-105, -1), Pair(108, -75), Pair(98, -59), Pair(35, -54), Pair(-49, 33), Pair(39, -41), Pair(27, -42), Pair(108, -34),
        Pair(147, -15), Pair(0, -30), Pair(22, -30), Pair(27, -18), Pair(40, -34), Pair(111, -65), Pair(15, -80), Pair(-18, -50),
        Pair(-39, -2), Pair(35, -26), Pair(59, -33), Pair(31, -11), Pair(20, 0), Pair(31, -35), Pair(38, -78), Pair(78, -94),
        Pair(7, 4), Pair(-27, 9), Pair(9, -30), Pair(-8, 13), Pair(13, -18), Pair(48, -39), Pair(37, -90), Pair(31, -24),
        Pair(0, 0), Pair(-42, 10), Pair(-3, 37), Pair(-7, -1), Pair(7, -3), Pair(6, -5), Pair(-22, 0), Pair(-25, -67),
        Pair(67, 50), Pair(-58, -103), Pair(7, -16), Pair(-1, -19), Pair(5, -10), Pair(-8, -43), Pair(-20, -25), Pair(-18, -21),
        Pair(-203, 44), Pair(12, -47), Pair(-2, -14), Pair(-19, -16), Pair(-10, -29), Pair(11, -48), Pair(14, -40), Pair(-33, -6)
      },
      { // Piece 2
        Pair(-129, 138), Pair(103, 30), Pair(-53, 67), Pair(-72, 50), Pair(102, 50), Pair(-1, 59), Pair(-96, 106), Pair(65, -7),
        Pair(9, -64), Pair(-72, -7), Pair(124, -19), Pair(-8, 53), Pair(33, 81), Pair(-20, 104), Pair(117, 47), Pair(-23, -4),
        Pair(-10, -9), Pair(6, 34), Pair(-68, 42), Pair(-21, 41), Pair(-127, 111), Pair(81, 25), Pair(-30, 24), Pair(19, -48),
        Pair(16, 19), Pair(-20, 8), Pair(39, 4), Pair(-10, 61), Pair(37, 13), Pair(5, 27), Pair(32, 2), Pair(-4, -2),
        Pair(29, 23), Pair(17, 35), Pair(13, 55), Pair(20, 7), Pair(41, -13), Pair(29, -10), Pair(-46, 56), Pair(13, 1),
        Pair(0, 0), Pair(18, 56), Pair(17, 43), Pair(2, 12), Pair(1, 30), Pair(-1, -11), Pair(-12, 36), Pair(22, -60),
        Pair(-7, 156), Pair(1, 30), Pair(-26, -29), Pair(10, 18), Pair(-2, -4), Pair(-20, 26), Pair(-11, -19), Pair(-23, -6),
        Pair(-6, 8), Pair(-59, 122), Pair(-14, 21), Pair(0, 23), Pair(38, -30), Pair(-21, 0), Pair(-13, 31), Pair(27, 24)
      },
      { // Piece 3
        Pair(0, 61), Pair(7, 37), Pair(-3, 5), Pair(59, 22), Pair(-5, 18), Pair(161, 12), Pair(119, -11), Pair(112, -13),
        Pair(-22, 83), Pair(-18, 50), Pair(16, 27), Pair(-8, 60), Pair(32, 27), Pair(-23, 40), Pair(-49, 53), Pair(28, 21),
        Pair(5, 79), Pair(33, -14), Pair(6, 42), Pair(69, 2), Pair(86, 15), Pair(70, -12), Pair(76, -11), Pair(-19, 43),
        Pair(44, 66), Pair(-48, 45), Pair(4, 39), Pair(10, -3), Pair(37, 16), Pair(42, -2), Pair(18, 40), Pair(-29, 26),
        Pair(-30, 35), Pair(-14, 4), Pair(60, 9), Pair(0, 35), Pair(16, 3), Pair(-6, 14), Pair(-3, 28), Pair(18, 19),
        Pair(0, 0), Pair(-18, 58), Pair(45, 6), Pair(-9, 9), Pair(10, -5), Pair(61, -20), Pair(17, -19), Pair(65, -67),
        Pair(20, 42), Pair(122, 2), Pair(4, 19), Pair(8, 27), Pair(-15, 41), Pair(26, 29), Pair(-37, 48), Pair(39, 16),
        Pair(-15, 51), Pair(8, 6), Pair(-16, 51), Pair(8, 27), Pair(7, 37), Pair(3, 34), Pair(55, -9), Pair(20, 18)
      },
      { // Piece 4
        Pair(64, -33), Pair(122, -145), Pair(74, 119), Pair(-4, -6), Pair(-16, 51), Pair(52, 73), Pair(122, 23), Pair(20, 35),
        Pair(-17, 131), Pair(-30, 189), Pair(60, 33), Pair(-87, 35), Pair(63, 56), Pair(108, -33), Pair(9, 81), Pair(44, 79),
        Pair(-168, 175), Pair(47, -96), Pair(38, 54), Pair(32, 22), Pair(-71, 90), Pair(34, 5), Pair(100, -86), Pair(10, 76),
        Pair(34, 75), Pair(23, 28), Pair(-2, -5), Pair(-25, 91), Pair(62, 5), Pair(29, 72), Pair(21, -4), Pair(8, 16),
        Pair(-30, 38), Pair(-37, 126), Pair(-30, 61), Pair(8, 38), Pair(-42, 75), Pair(-5, 71), Pair(45, -26), Pair(1, -34),
        Pair(0, 0), Pair(20, -38), Pair(14, -7), Pair(8, -13), Pair(26, -22), Pair(-4, 14), Pair(27, 3), Pair(43, -64),
        Pair(-65, 24), Pair(60, 56), Pair(8, -30), Pair(-7, -2), Pair(-3, -19), Pair(-19, 6), Pair(-33, 25), Pair(25, -79),
        Pair(-57, 25), Pair(-9, 54), Pair(10, 29), Pair(-7, 38), Pair(-22, 3), Pair(-17, 41), Pair(-48, 38), Pair(-18, 92)
      },
      { // Piece 5
        Pair(2, 36), Pair(-1, -17), Pair(-16, 8), Pair(71, 117), Pair(34, -69), Pair(-21, -197), Pair(-15, -177), Pair(50, -9),
        Pair(8, -56), Pair(-36, -114), Pair(-48, -45), Pair(-38, 4), Pair(73, -75), Pair(-3, -103), Pair(38, -114), Pair(1, -11),
        Pair(3, -46), Pair(-16, 26), Pair(41, -7), Pair(8, -23), Pair(180, -83), Pair(21, -41), Pair(85, -85), Pair(-67, -22),
        Pair(-2, -93), Pair(118, 17), Pair(-25, 17), Pair(116, -36), Pair(151, -23), Pair(180, -38), Pair(28, -37), Pair(44, -62),
        Pair(-33, 5), Pair(-73, 62), Pair(50, -10), Pair(25, 6), Pair(21, 1), Pair(103, -25), Pair(0, -36), Pair(104, -55),
        Pair(0, 0), Pair(-103, 92), Pair(-40, 25), Pair(-72, 31), Pair(23, -14), Pair(59, -43), Pair(68, -49), Pair(95, -83),
        Pair(101, 86), Pair(17, -17), Pair(-59, 69), Pair(49, -8), Pair(-15, -10), Pair(-8, -30), Pair(-6, -36), Pair(8, -30),
        Pair(22, 55), Pair(-60, 102), Pair(-88, 59), Pair(-59, 4), Pair(-26, -23), Pair(12, -45), Pair(-2, -47), Pair(1, -54)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-35, -1), Pair(113, -21), Pair(36, -25), Pair(31, 3), Pair(13, 8), Pair(28, -23), Pair(75, -4), Pair(-31, 6),
        Pair(1, 15), Pair(0, 0), Pair(30, -7), Pair(4, -7), Pair(25, -14), Pair(5, 14), Pair(20, 0), Pair(1, 0),
        Pair(-4, -9), Pair(14, -18), Pair(19, -15), Pair(-8, -7), Pair(-5, -2), Pair(-20, 2), Pair(-1, 5), Pair(3, 8),
        Pair(4, -4), Pair(-14, -6), Pair(9, -11), Pair(9, -8), Pair(9, -5), Pair(-9, -4), Pair(2, -3), Pair(9, -5),
        Pair(9, 3), Pair(0, 0), Pair(17, -5), Pair(6, -8), Pair(1, 0), Pair(-7, -5), Pair(-20, -4), Pair(2, -10),
        Pair(12, -34), Pair(32, 17), Pair(-25, 12), Pair(11, -31), Pair(-5, -3), Pair(-18, -4), Pair(-5, -6), Pair(5, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(8, -92), Pair(-23, -11), Pair(23, -59), Pair(23, -95), Pair(-63, -40), Pair(49, -66), Pair(-19, -118), Pair(-32, -102),
        Pair(176, -38), Pair(5, -39), Pair(50, -3), Pair(-11, -34), Pair(41, -104), Pair(-41, -3), Pair(-87, 12), Pair(97, -66),
        Pair(135, -72), Pair(-2, 29), Pair(-49, 5), Pair(51, 2), Pair(4, 38), Pair(41, -18), Pair(-34, -6), Pair(156, -45),
        Pair(24, 96), Pair(-19, 26), Pair(-32, 27), Pair(38, -8), Pair(8, 17), Pair(61, -19), Pair(48, -10), Pair(17, 27),
        Pair(-38, 114), Pair(72, -12), Pair(11, 51), Pair(35, 23), Pair(30, 8), Pair(8, -13), Pair(-7, 0), Pair(11, 2),
        Pair(20, -57), Pair(0, 0), Pair(-22, 31), Pair(-8, 70), Pair(-17, 56), Pair(11, 5), Pair(3, -10), Pair(27, -71),
        Pair(25, -46), Pair(35, 118), Pair(-118, -36), Pair(19, -26), Pair(13, -46), Pair(-76, -26), Pair(21, -98), Pair(10, 15),
        Pair(-117, -20), Pair(-18, 2), Pair(71, -123), Pair(-17, 34), Pair(55, -37), Pair(-12, -45), Pair(-94, -9), Pair(-71, -143)
      },
      { // Piece 2
        Pair(26, -38), Pair(44, -16), Pair(-64, 59), Pair(-26, 14), Pair(-22, 11), Pair(66, 50), Pair(10, -35), Pair(27, 105),
        Pair(217, 18), Pair(-46, -9), Pair(-101, 26), Pair(-141, 79), Pair(-6, 35), Pair(101, 42), Pair(9, 126), Pair(-63, 95),
        Pair(-7, -23), Pair(22, -50), Pair(8, 7), Pair(-52, 88), Pair(13, 42), Pair(30, 103), Pair(-81, 70), Pair(-16, 36),
        Pair(-66, -6), Pair(-44, 30), Pair(-40, 51), Pair(-55, 37), Pair(-11, 72), Pair(-44, 63), Pair(-11, 5), Pair(29, -2),
        Pair(-172, -30), Pair(-17, -22), Pair(36, -5), Pair(-31, 91), Pair(37, 44), Pair(-60, 14), Pair(-35, 60), Pair(13, -44),
        Pair(-2, 108), Pair(0, 0), Pair(-15, 58), Pair(-4, 26), Pair(-18, 25), Pair(-7, 8), Pair(-36, 41), Pair(38, -24),
        Pair(-113, 88), Pair(6, 166), Pair(50, 83), Pair(-7, 14), Pair(-7, 20), Pair(-30, 37), Pair(29, -6), Pair(15, -93),
        Pair(5, 126), Pair(25, 8), Pair(-43, 56), Pair(-2, -16), Pair(-30, -29), Pair(35, 2), Pair(-105, 34), Pair(31, 28)
      },
      { // Piece 3
        Pair(8, 12), Pair(-53, 45), Pair(-35, 61), Pair(200, -54), Pair(69, -51), Pair(161, -54), Pair(-118, 83), Pair(58, 21),
        Pair(86, 21), Pair(66, 31), Pair(31, 32), Pair(15, 46), Pair(28, 54), Pair(133, -37), Pair(89, -5), Pair(147, -18),
        Pair(38, -1), Pair(38, 46), Pair(42, 12), Pair(63, 9), Pair(168, -45), Pair(137, -27), Pair(157, -29), Pair(131, -42),
        Pair(55, -14), Pair(-50, 52), Pair(20, 18), Pair(107, -40), Pair(39, 17), Pair(-31, 19), Pair(85, -23), Pair(133, -38),
        Pair(-4, 0), Pair(68, 41), Pair(25, -6), Pair(-18, 3), Pair(8, -2), Pair(48, 2), Pair(19, -4), Pair(-4, 13),
        Pair(-103, 39), Pair(0, 0), Pair(43, 0), Pair(76, 0), Pair(44, 13), Pair(-2, 10), Pair(15, 72), Pair(81, -10),
        Pair(-36, 66), Pair(-5, 54), Pair(-39, 10), Pair(-46, 54), Pair(0, 48), Pair(27, 39), Pair(23, 72), Pair(46, 53),
        Pair(-16, 16), Pair(-4, 36), Pair(-6, 24), Pair(-4, 19), Pair(2, 14), Pair(-2, 24), Pair(33, 30), Pair(7, 10)
      },
      { // Piece 4
        Pair(80, -63), Pair(-87, 3), Pair(-37, 119), Pair(11, -12), Pair(-35, 46), Pair(46, -39), Pair(3, -21), Pair(26, 72),
        Pair(60, -25), Pair(-9, -10), Pair(33, -135), Pair(0, 102), Pair(76, -45), Pair(46, 85), Pair(18, 21), Pair(15, 6),
        Pair(68, -28), Pair(106, -20), Pair(107, -113), Pair(-61, 122), Pair(127, 0), Pair(-45, 14), Pair(70, 114), Pair(45, -56),
        Pair(66, -28), Pair(-13, 4), Pair(-116, 103), Pair(-61, 51), Pair(29, 70), Pair(41, 92), Pair(39, 45), Pair(59, -43),
        Pair(-54, -8), Pair(41, -12), Pair(-34, 68), Pair(0, 56), Pair(30, -15), Pair(34, -34), Pair(27, 11), Pair(16, 52),
        Pair(18, -148), Pair(0, 0), Pair(-29, 90), Pair(-6, -11), Pair(-34, -25), Pair(27, 11), Pair(11, -23), Pair(3, 152),
        Pair(2, 10), Pair(-74, 90), Pair(23, -2), Pair(-11, 56), Pair(27, -54), Pair(-25, -18), Pair(48, -56), Pair(-26, -45),
        Pair(-5, -100), Pair(-49, 26), Pair(-20, 11), Pair(27, -84), Pair(24, 2), Pair(-31, -64), Pair(26, -62), Pair(-52, -10)
      },
      { // Piece 5
        Pair(-28, -106), Pair(-40, -118), Pair(37, 7), Pair(-52, -89), Pair(3, 4), Pair(-17, -119), Pair(-38, -93), Pair(-1, -68),
        Pair(-4, -4), Pair(-11, -49), Pair(-9, -29), Pair(13, 53), Pair(73, -50), Pair(12, -97), Pair(36, -42), Pair(-37, -49),
        Pair(-5, -66), Pair(54, -82), Pair(20, -11), Pair(51, 26), Pair(79, -59), Pair(106, -18), Pair(-5, -78), Pair(23, -21),
        Pair(-36, -77), Pair(55, -18), Pair(167, 14), Pair(-32, -13), Pair(-3, -4), Pair(14, -4), Pair(42, -32), Pair(55, -70),
        Pair(56, 55), Pair(-45, 9), Pair(-6, 35), Pair(77, 5), Pair(-26, 12), Pair(0, 1), Pair(18, -47), Pair(73, -61),
        Pair(-136, 122), Pair(0, 0), Pair(-129, 75), Pair(-54, 28), Pair(-68, 29), Pair(19, -8), Pair(24, -37), Pair(19, -23),
        Pair(44, 16), Pair(-165, 114), Pair(-9, 26), Pair(-76, 40), Pair(-21, 0), Pair(-25, -17), Pair(20, -37), Pair(-6, -14),
        Pair(-19, 45), Pair(-92, 63), Pair(-48, 49), Pair(-84, 31), Pair(-8, -35), Pair(-43, -29), Pair(4, -50), Pair(56, -125)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-68, 44), Pair(33, -9), Pair(-31, -5), Pair(25, 21), Pair(9, 3), Pair(43, -8), Pair(-24, 11), Pair(59, -17),
        Pair(13, -5), Pair(-30, 7), Pair(0, 0), Pair(-35, -1), Pair(-6, -18), Pair(18, -3), Pair(-29, 25), Pair(-12, 15),
        Pair(-11, 5), Pair(-1, -6), Pair(-13, -9), Pair(3, 1), Pair(0, -8), Pair(-14, 0), Pair(-22, 4), Pair(-10, 7),
        Pair(-7, -5), Pair(0, -9), Pair(-2, -4), Pair(-8, 8), Pair(-3, 3), Pair(-15, 4), Pair(-12, 4), Pair(-16, 1),
        Pair(-11, 2), Pair(-10, 9), Pair(0, 0), Pair(7, -1), Pair(-5, -2), Pair(-25, 7), Pair(-13, -5), Pair(-15, 2),
        Pair(-4, 0), Pair(14, -30), Pair(27, 16), Pair(-31, -23), Pair(-7, 3), Pair(-6, 0), Pair(-14, 2), Pair(-8, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-11, -32), Pair(72, -7), Pair(-8, 5), Pair(12, -35), Pair(73, 46), Pair(-34, 63), Pair(24, -108), Pair(-84, -38),
        Pair(-51, -11), Pair(-60, -35), Pair(-8, -61), Pair(48, -11), Pair(92, 39), Pair(58, 14), Pair(80, -32), Pair(-20, -122),
        Pair(156, -102), Pair(15, -13), Pair(43, 26), Pair(2, 42), Pair(64, 36), Pair(47, 3), Pair(16, 32), Pair(5, 52),
        Pair(0, -39), Pair(80, -20), Pair(47, 62), Pair(9, 46), Pair(21, 23), Pair(-38, 38), Pair(49, -46), Pair(54, 5),
        Pair(53, 11), Pair(-42, 56), Pair(-2, 50), Pair(-5, 82), Pair(15, 21), Pair(34, 11), Pair(42, -16), Pair(69, -23),
        Pair(-98, 86), Pair(-43, 4), Pair(0, 0), Pair(66, 7), Pair(-22, 71), Pair(39, -14), Pair(50, -28), Pair(29, -21),
        Pair(-8, -39), Pair(14, -255), Pair(18, 131), Pair(23, -70), Pair(35, 34), Pair(23, 13), Pair(-14, -4), Pair(-24, 21),
        Pair(36, 51), Pair(-40, -20), Pair(36, -22), Pair(49, -89), Pair(-77, 142), Pair(22, 17), Pair(-41, -27), Pair(-2, -86)
      },
      { // Piece 2
        Pair(24, 9), Pair(-16, -18), Pair(142, 42), Pair(20, -7), Pair(-38, 18), Pair(-90, 116), Pair(6, 76), Pair(-9, -41),
        Pair(1, 38), Pair(-8, 40), Pair(21, -21), Pair(44, 21), Pair(36, 36), Pair(-104, 18), Pair(-134, 90), Pair(15, 107),
        Pair(-49, 26), Pair(-15, 2), Pair(35, 31), Pair(-23, 48), Pair(3, 26), Pair(-81, 96), Pair(126, 61), Pair(58, 49),
        Pair(-36, 7), Pair(24, 36), Pair(17, 57), Pair(58, 0), Pair(3, -9), Pair(17, 97), Pair(-6, 39), Pair(19, 51),
        Pair(-146, 117), Pair(-23, 15), Pair(45, -24), Pair(3, 28), Pair(-7, 92), Pair(-9, 67), Pair(-1, 8), Pair(29, 25),
        Pair(-7, -32), Pair(1, 86), Pair(0, 0), Pair(23, 97), Pair(4, 40), Pair(5, 7), Pair(15, -24), Pair(-36, 36),
        Pair(4, -30), Pair(18, -67), Pair(29, 154), Pair(78, -12), Pair(5, 16), Pair(51, -19), Pair(19, 6), Pair(24, 7),
        Pair(-129, -6), Pair(-64, 110), Pair(-25, 20), Pair(-83, 127), Pair(-32, -26), Pair(18, 47), Pair(66, 48), Pair(-77, -19)
      },
      { // Piece 3
        Pair(-71, 30), Pair(118, -30), Pair(89, 31), Pair(27, 40), Pair(40, 8), Pair(-78, 44), Pair(46, 16), Pair(-44, 14),
        Pair(-3, 17), Pair(24, 27), Pair(77, 42), Pair(50, 18), Pair(38, 6), Pair(176, -4), Pair(189, 9), Pair(101, 9),
        Pair(-49, 35), Pair(17, 11), Pair(63, 27), Pair(-19, 30), Pair(49, -7), Pair(-90, 57), Pair(-11, -15), Pair(63, -10),
        Pair(5, 15), Pair(25, 28), Pair(71, 12), Pair(36, -31), Pair(-4, 79), Pair(22, -7), Pair(124, -44), Pair(63, 6),
        Pair(5, 0), Pair(9, 13), Pair(82, -10), Pair(23, 5), Pair(7, -13), Pair(-12, 53), Pair(-11, -7), Pair(39, -14),
        Pair(-20, 37), Pair(-26, 85), Pair(0, 0), Pair(-57, 89), Pair(-95, 39), Pair(30, 31), Pair(-12, 62), Pair(-43, 21),
        Pair(-102, 71), Pair(-34, 83), Pair(-8, 74), Pair(12, 122), Pair(16, 59), Pair(4, 60), Pair(-34, 23), Pair(-3, 41),
        Pair(4, 37), Pair(0, -15), Pair(-30, 64), Pair(-16, 25), Pair(19, 11), Pair(23, 26), Pair(27, -3), Pair(-1, 31)
      },
      { // Piece 4
        Pair(74, -4), Pair(75, 20), Pair(-65, 46), Pair(-62, -9), Pair(62, -33), Pair(53, -4), Pair(100, -3), Pair(-54, 34),
        Pair(5, -76), Pair(1, 148), Pair(20, 82), Pair(74, 12), Pair(-116, 233), Pair(-10, 40), Pair(83, -57), Pair(131, -38),
        Pair(-115, 19), Pair(40, -81), Pair(-30, 127), Pair(-65, 141), Pair(10, 6), Pair(-54, 69), Pair(36, 78), Pair(39, -52),
        Pair(97, -81), Pair(18, -85), Pair(-46, 18), Pair(-76, 87), Pair(-28, -3), Pair(4, 94), Pair(30, -27), Pair(46, 64),
        Pair(49, -19), Pair(21, 0), Pair(61, -88), Pair(-9, -56), Pair(-89, 109), Pair(62, -28), Pair(32, 13), Pair(6, 127),
        Pair(-70, -9), Pair(20, -105), Pair(0, 0), Pair(-39, 37), Pair(-29, -21), Pair(-22, -3), Pair(58, -87), Pair(5, -38),
        Pair(30, 36), Pair(2, 33), Pair(-12, -6), Pair(-13, 87), Pair(-23, 10), Pair(-10, -46), Pair(1, 77), Pair(-37, -53),
        Pair(-14, -39), Pair(-72, 61), Pair(-68, 66), Pair(-9, -9), Pair(-42, 36), Pair(-49, 77), Pair(15, -47), Pair(75, 87)
      },
      { // Piece 5
        Pair(-7, -15), Pair(-63, -151), Pair(-22, -78), Pair(27, 89), Pair(-2, -51), Pair(-17, -76), Pair(13, -58), Pair(-15, -123),
        Pair(-20, -168), Pair(-1, 7), Pair(-76, -94), Pair(12, -19), Pair(7, -49), Pair(-53, -41), Pair(41, -108), Pair(-42, -130),
        Pair(3, 23), Pair(-15, -95), Pair(10, -91), Pair(14, -93), Pair(62, -53), Pair(49, -37), Pair(110, -55), Pair(-42, -149),
        Pair(30, 16), Pair(25, -25), Pair(61, 1), Pair(114, -4), Pair(61, 3), Pair(107, -7), Pair(62, -16), Pair(-75, -46),
        Pair(103, -12), Pair(58, 2), Pair(50, 18), Pair(76, 44), Pair(73, -10), Pair(11, -18), Pair(1, -4), Pair(43, -89),
        Pair(-91, 54), Pair(-197, 110), Pair(0, 0), Pair(-13, 57), Pair(-49, 10), Pair(-29, 7), Pair(10, -12), Pair(-16, -29),
        Pair(-134, 45), Pair(23, 62), Pair(-136, 102), Pair(-26, 173), Pair(-67, 18), Pair(82, -15), Pair(9, -22), Pair(-13, -12),
        Pair(-159, 102), Pair(-54, 20), Pair(-94, 92), Pair(-132, 105), Pair(-27, 6), Pair(41, -5), Pair(0, -47), Pair(44, -109)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 15), Pair(-43, 48), Pair(-56, 33), Pair(7, 11), Pair(-57, 12), Pair(-37, 25), Pair(-9, 19), Pair(15, 11),
        Pair(9, 0), Pair(-5, 7), Pair(35, 1), Pair(0, 0), Pair(13, 5), Pair(-1, 9), Pair(39, -6), Pair(-32, 4),
        Pair(-9, 6), Pair(-4, -14), Pair(10, 2), Pair(6, -14), Pair(8, -7), Pair(3, -5), Pair(24, -11), Pair(14, -12),
        Pair(-5, -5), Pair(-3, -15), Pair(-4, -3), Pair(12, -22), Pair(10, -4), Pair(0, -5), Pair(0, -2), Pair(-9, 0),
        Pair(-5, -2), Pair(0, -2), Pair(-16, 12), Pair(0, 0), Pair(-1, -1), Pair(0, -5), Pair(6, -5), Pair(-16, 1),
        Pair(-1, -10), Pair(-4, -4), Pair(4, -41), Pair(25, 13), Pair(-4, -39), Pair(-2, -1), Pair(9, -8), Pair(-11, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-84, -37), Pair(-131, 80), Pair(140, -28), Pair(82, 28), Pair(-8, 27), Pair(58, -38), Pair(4, -23), Pair(-51, -110),
        Pair(-27, -44), Pair(-90, 56), Pair(-60, 40), Pair(155, 3), Pair(-15, -37), Pair(94, -89), Pair(177, -25), Pair(14, 28),
        Pair(-16, -60), Pair(23, -19), Pair(-23, 16), Pair(30, -11), Pair(23, 57), Pair(59, -44), Pair(34, -29), Pair(20, 5),
        Pair(-1, -29), Pair(12, 26), Pair(9, 0), Pair(29, -69), Pair(32, 6), Pair(19, -5), Pair(-3, -13), Pair(15, -32),
        Pair(8, 37), Pair(-48, 53), Pair(-14, 87), Pair(22, 14), Pair(10, 59), Pair(23, -18), Pair(69, -19), Pair(35, -10),
        Pair(-18, -67), Pair(-11, 62), Pair(-9, 4), Pair(0, 0), Pair(-29, 54), Pair(-16, 65), Pair(-17, -41), Pair(5, 19),
        Pair(-69, 52), Pair(21, 51), Pair(8, -41), Pair(19, 120), Pair(-31, 17), Pair(-34, 24), Pair(54, -31), Pair(-3, 38),
        Pair(-91, -135), Pair(-29, 104), Pair(-49, 123), Pair(-91, 108), Pair(20, 52), Pair(-15, 114), Pair(28, -42), Pair(-31, -81)
      },
      { // Piece 2
        Pair(-44, 101), Pair(-110, 19), Pair(54, 58), Pair(77, 115), Pair(64, 16), Pair(-60, 65), Pair(-25, -134), Pair(107, 116),
        Pair(34, -47), Pair(8, 20), Pair(-81, 46), Pair(109, 70), Pair(-63, 101), Pair(-2, 72), Pair(44, 60), Pair(-88, 85),
        Pair(8, -12), Pair(-56, 42), Pair(-6, 17), Pair(-39, 70), Pair(-29, 75), Pair(139, 23), Pair(-73, 40), Pair(13, 20),
        Pair(20, 69), Pair(-35, 27), Pair(20, -2), Pair(42, 44), Pair(-16, 77), Pair(-61, 98), Pair(-24, 114), Pair(-76, 43),
        Pair(20, 47), Pair(50, 83), Pair(49, 0), Pair(41, -1), Pair(-48, 60), Pair(-44, 102), Pair(23, 4), Pair(109, -32),
        Pair(-5, 30), Pair(8, 39), Pair(-5, 94), Pair(0, 0), Pair(13, 91), Pair(29, 18), Pair(-6, -3), Pair(-34, 47),
        Pair(22, -16), Pair(-16, 6), Pair(-14, 30), Pair(13, 153), Pair(59, -110), Pair(48, -53), Pair(-2, 6), Pair(44, -2),
        Pair(47, 81), Pair(9, -5), Pair(-43, 89), Pair(18, 41), Pair(-82, 143), Pair(20, -88), Pair(63, -24), Pair(9, 49)
      },
      { // Piece 3
        Pair(90, -9), Pair(-19, 57), Pair(68, -3), Pair(71, 13), Pair(-33, 25), Pair(80, -22), Pair(120, -7), Pair(-82, 65),
        Pair(-24, 40), Pair(-18, 28), Pair(7, 25), Pair(-82, 68), Pair(-34, 37), Pair(54, 13), Pair(-38, 44), Pair(132, 10),
        Pair(46, 4), Pair(76, -46), Pair(20, 19), Pair(23, 47), Pair(-2, 15), Pair(130, -34), Pair(83, -3), Pair(-13, 43),
        Pair(32, -11), Pair(38, 31), Pair(-31, 69), Pair(88, 5), Pair(47, -20), Pair(22, -5), Pair(65, -41), Pair(17, -12),
        Pair(59, 0), Pair(33, 16), Pair(-20, 90), Pair(-4, 33), Pair(24, -9), Pair(-27, 66), Pair(-19, 22), Pair(-15, 30),
        Pair(-49, 62), Pair(25, 24), Pair(-11, 2), Pair(0, 0), Pair(-5, 57), Pair(97, 30), Pair(81, -29), Pair(-36, 11),
        Pair(-41, 72), Pair(-101, 83), Pair(129, 15), Pair(-29, 96), Pair(-145, 102), Pair(-12, 67), Pair(-55, 80), Pair(42, 65),
        Pair(-18, 43), Pair(3, 2), Pair(-19, 35), Pair(-21, 70), Pair(25, 5), Pair(13, 27), Pair(48, -1), Pair(29, 39)
      },
      { // Piece 4
        Pair(19, -2), Pair(-30, 83), Pair(15, -16), Pair(-10, 25), Pair(34, 25), Pair(69, 42), Pair(3, 9), Pair(85, -11),
        Pair(73, -63), Pair(-56, 2), Pair(65, -84), Pair(6, -7), Pair(35, -75), Pair(-41, 125), Pair(63, 0), Pair(19, -85),
        Pair(17, -82), Pair(-17, -5), Pair(22, -1), Pair(-28, 32), Pair(-46, 136), Pair(42, 94), Pair(-32, 66), Pair(-41, 82),
        Pair(-19, 95), Pair(-16, 19), Pair(-3, -54), Pair(-35, 34), Pair(39, 24), Pair(-48, 109), Pair(39, -24), Pair(2, 48),
        Pair(-16, -7), Pair(-17, 62), Pair(34, -74), Pair(9, 76), Pair(-17, 21), Pair(53, -24), Pair(15, -30), Pair(-64, 95),
        Pair(60, -121), Pair(-16, -6), Pair(-10, 51), Pair(0, 0), Pair(0, 15), Pair(-44, 13), Pair(5, -27), Pair(3, -77),
        Pair(-55, 37), Pair(-68, 113), Pair(-35, 14), Pair(17, -18), Pair(-4, 9), Pair(16, -23), Pair(-100, 50), Pair(35, -118),
        Pair(-61, -14), Pair(44, -51), Pair(-45, -25), Pair(-29, -29), Pair(-12, 0), Pair(24, -105), Pair(97, -67), Pair(-51, -80)
      },
      { // Piece 5
        Pair(-7, -44), Pair(-6, -26), Pair(-2, -24), Pair(-2, -55), Pair(-3, -21), Pair(-3, -77), Pair(-44, -92), Pair(-67, -87),
        Pair(2, -3), Pair(-17, -52), Pair(2, -15), Pair(-1, -95), Pair(-64, -29), Pair(-39, 20), Pair(-41, -8), Pair(11, 25),
        Pair(2, -145), Pair(-40, -48), Pair(-49, -27), Pair(-19, -46), Pair(64, -16), Pair(28, -51), Pair(-50, 3), Pair(-53, -87),
        Pair(39, 29), Pair(68, -22), Pair(141, -57), Pair(-2, -64), Pair(-31, -8), Pair(55, -59), Pair(0, -5), Pair(-118, 8),
        Pair(-44, -181), Pair(22, 36), Pair(7, 31), Pair(-33, 35), Pair(103, 13), Pair(14, 2), Pair(16, 7), Pair(-16, -42),
        Pair(-5, 23), Pair(-148, 29), Pair(-47, 66), Pair(0, 0), Pair(-78, 54), Pair(-30, 19), Pair(-37, 28), Pair(-22, -21),
        Pair(126, -45), Pair(-25, -4), Pair(-55, -112), Pair(-138, 100), Pair(106, 13), Pair(2, 13), Pair(-10, 13), Pair(52, -26),
        Pair(71, -70), Pair(13, -39), Pair(-99, 86), Pair(1, 40), Pair(-49, 75), Pair(-2, 3), Pair(9, -4), Pair(3, -20)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(15, 4), Pair(48, -18), Pair(-49, 28), Pair(-33, 23), Pair(-104, 32), Pair(-43, 10), Pair(-21, 17), Pair(21, 2),
        Pair(23, -7), Pair(-25, 14), Pair(6, 18), Pair(-13, -5), Pair(0, 0), Pair(23, -17), Pair(-36, 3), Pair(-14, -8),
        Pair(4, -7), Pair(-7, -5), Pair(-1, -14), Pair(-4, -5), Pair(-3, 5), Pair(17, -26), Pair(1, 2), Pair(-21, 8),
        Pair(0, -17), Pair(3, -16), Pair(4, -1), Pair(-9, -2), Pair(15, -7), Pair(-6, 13), Pair(-6, -2), Pair(2, -3),
        Pair(4, -13), Pair(2, -6), Pair(1, -10), Pair(-1, -3), Pair(0, 0), Pair(7, -2), Pair(-1, -3), Pair(1, -5),
        Pair(1, -9), Pair(-7, 0), Pair(9, 0), Pair(18, -77), Pair(30, 2), Pair(-12, -26), Pair(8, -5), Pair(7, -9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-83, -126), Pair(-14, 7), Pair(129, 1), Pair(-12, 27), Pair(-148, -104), Pair(37, -1), Pair(41, 45), Pair(62, -74),
        Pair(143, -142), Pair(-71, -27), Pair(32, -10), Pair(33, 7), Pair(-127, 79), Pair(-14, 22), Pair(-40, -100), Pair(212, -99),
        Pair(-64, 102), Pair(-20, -1), Pair(-44, 39), Pair(-28, 2), Pair(-87, 15), Pair(69, -20), Pair(35, 10), Pair(38, 11),
        Pair(-11, 114), Pair(-20, 31), Pair(-23, 47), Pair(-3, -38), Pair(-18, -7), Pair(-8, 17), Pair(3, -9), Pair(53, -82),
        Pair(-8, -91), Pair(-69, 19), Pair(10, -15), Pair(-43, 79), Pair(-14, 5), Pair(21, 53), Pair(48, 45), Pair(33, 25),
        Pair(14, 52), Pair(-50, 89), Pair(-9, 74), Pair(-32, 24), Pair(0, 0), Pair(28, 30), Pair(6, -10), Pair(-24, -26),
        Pair(-60, -35), Pair(-37, -15), Pair(50, 30), Pair(-33, -50), Pair(-8, 119), Pair(-14, 49), Pair(29, 25), Pair(7, 18),
        Pair(-91, 28), Pair(9, -18), Pair(-61, 89), Pair(-83, -32), Pair(4, -2), Pair(-11, -41), Pair(-41, 102), Pair(-177, -43)
      },
      { // Piece 2
        Pair(-38, 59), Pair(-7, -15), Pair(96, -12), Pair(-24, -16), Pair(-127, 115), Pair(-105, -3), Pair(-7, 11), Pair(151, 174),
        Pair(45, 77), Pair(-65, 60), Pair(30, -21), Pair(-47, 10), Pair(91, 63), Pair(89, -27), Pair(-19, 49), Pair(-72, 9),
        Pair(5, 99), Pair(-28, 3), Pair(20, 40), Pair(39, -70), Pair(26, 41), Pair(-19, 12), Pair(46, 3), Pair(61, -49),
        Pair(-31, 82), Pair(-41, 102), Pair(9, 12), Pair(-62, 57), Pair(-12, 29), Pair(19, 24), Pair(-60, 42), Pair(55, 63),
        Pair(-37, -6), Pair(-56, 62), Pair(-44, 112), Pair(-68, -12), Pair(89, -40), Pair(-83, 67), Pair(2, 63), Pair(-28, -16),
        Pair(-18, 52), Pair(1, -12), Pair(42, 20), Pair(-10, 90), Pair(0, 0), Pair(5, 66), Pair(-42, 68), Pair(0, 6),
        Pair(-160, -39), Pair(4, 6), Pair(-20, 15), Pair(-20, -67), Pair(10, 111), Pair(35, 48), Pair(8, -26), Pair(49, 48),
        Pair(90, 15), Pair(31, -57), Pair(-43, -7), Pair(-4, 49), Pair(-1, 21), Pair(-45, 71), Pair(12, -87), Pair(88, -85)
      },
      { // Piece 3
        Pair(39, -1), Pair(-65, 57), Pair(-23, -18), Pair(116, -25), Pair(-15, 0), Pair(142, -1), Pair(-83, 13), Pair(0, 1),
        Pair(80, -23), Pair(29, -22), Pair(22, 5), Pair(26, -18), Pair(12, -2), Pair(-49, 8), Pair(52, -10), Pair(45, 4),
        Pair(35, -30), Pair(68, -45), Pair(47, -51), Pair(45, -39), Pair(59, -16), Pair(-24, 10), Pair(65, -70), Pair(-39, -22),
        Pair(25, 2), Pair(53, -40), Pair(-67, 3), Pair(-2, -7), Pair(57, 3), Pair(27, -100), Pair(42, -43), Pair(-17, -3),
        Pair(53, -18), Pair(37, -30), Pair(32, -28), Pair(45, 1), Pair(-22, 14), Pair(-28, -2), Pair(77, -8), Pair(84, -21),
        Pair(-2, -48), Pair(2, -85), Pair(83, -61), Pair(-74, 26), Pair(0, 0), Pair(15, 100), Pair(65, -80), Pair(55, -108),
        Pair(-80, 61), Pair(-53, 80), Pair(13, -13), Pair(-108, 38), Pair(-56, 86), Pair(-37, 37), Pair(51, -11), Pair(54, -34),
        Pair(-19, -18), Pair(-27, 28), Pair(5, -15), Pair(-25, 33), Pair(-32, 41), Pair(-10, -1), Pair(18, -6), Pair(23, 15)
      },
      { // Piece 4
        Pair(-33, 26), Pair(-62, 30), Pair(-117, 53), Pair(115, 38), Pair(-88, 80), Pair(-28, 104), Pair(-76, 26), Pair(63, -7),
        Pair(69, 4), Pair(-39, 132), Pair(-2, 72), Pair(-142, 52), Pair(15, -12), Pair(144, -20), Pair(23, 13), Pair(125, -59),
        Pair(-15, 22), Pair(-15, -48), Pair(122, -79), Pair(-25, -68), Pair(54, -2), Pair(-1, 107), Pair(-53, -30), Pair(-39, 42),
        Pair(-95, 36), Pair(-17, 78), Pair(-67, 70), Pair(-38, 35), Pair(3, -32), Pair(44, 0), Pair(154, -97), Pair(13, 41),
        Pair(-28, -28), Pair(-20, -159), Pair(-60, 115), Pair(-39, -2), Pair(40, -33), Pair(76, -131), Pair(-21, 30), Pair(21, 58),
        Pair(32, -13), Pair(2, -53), Pair(6, -40), Pair(18, -15), Pair(0, 0), Pair(-40, 23), Pair(-65, -25), Pair(-35, -7),
        Pair(-44, -71), Pair(23, 16), Pair(-14, -41), Pair(-47, -106), Pair(-10, 39), Pair(-57, -26), Pair(-75, 111), Pair(-71, 110),
        Pair(6, -77), Pair(5, -40), Pair(9, -77), Pair(-4, -47), Pair(-37, -47), Pair(-11, -44), Pair(27, -33), Pair(-40, -87)
      },
      { // Piece 5
        Pair(-10, -105), Pair(-3, -134), Pair(-16, -95), Pair(-62, -98), Pair(-39, -78), Pair(3, 64), Pair(14, -61), Pair(-6, -145),
        Pair(-17, -206), Pair(29, -88), Pair(14, -71), Pair(-13, -99), Pair(3, -48), Pair(11, -13), Pair(-17, -103), Pair(-43, -149),
        Pair(-9, -145), Pair(-15, -73), Pair(60, -57), Pair(88, -106), Pair(21, -60), Pair(111, -49), Pair(-41, -65), Pair(22, 5),
        Pair(-47, -53), Pair(-49, -60), Pair(-18, -15), Pair(-4, -56), Pair(-12, -4), Pair(159, -4), Pair(42, -34), Pair(11, 16),
        Pair(101, -94), Pair(-73, 11), Pair(-19, -48), Pair(-51, 52), Pair(-74, 50), Pair(93, 6), Pair(-41, 10), Pair(79, -22),
        Pair(84, -113), Pair(-17, -2), Pair(52, 55), Pair(-97, 79), Pair(0, 0), Pair(-39, 53), Pair(-14, 26), Pair(74, -10),
        Pair(36, 45), Pair(-6, 5), Pair(49, -16), Pair(-21, 36), Pair(-117, 86), Pair(34, 114), Pair(2, 22), Pair(11, 6),
        Pair(29, 19), Pair(0, -60), Pair(-24, -20), Pair(-54, 71), Pair(-24, 86), Pair(-43, 65), Pair(-30, 19), Pair(-18, 15)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(27, -9), Pair(-30, 16), Pair(-29, -6), Pair(-45, 17), Pair(-63, -12), Pair(44, 60), Pair(85, -30), Pair(-74, 28),
        Pair(18, 5), Pair(-5, -14), Pair(-18, 3), Pair(1, -9), Pair(-23, 17), Pair(0, 0), Pair(-23, 11), Pair(40, -16),
        Pair(10, -2), Pair(0, -16), Pair(-12, -18), Pair(12, -15), Pair(-3, -10), Pair(2, 2), Pair(18, 0), Pair(0, 1),
        Pair(-6, -6), Pair(6, -13), Pair(-11, -8), Pair(-4, -13), Pair(-9, -4), Pair(-8, -6), Pair(0, 5), Pair(6, -4),
        Pair(7, -8), Pair(-1, -5), Pair(-6, -7), Pair(-8, 3), Pair(-3, -7), Pair(0, 0), Pair(11, -3), Pair(21, -2),
        Pair(2, -4), Pair(-11, -6), Pair(-8, -17), Pair(-6, -11), Pair(23, -68), Pair(8, -5), Pair(14, -14), Pair(15, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-18, -172), Pair(-8, -34), Pair(61, -50), Pair(118, -40), Pair(-135, -56), Pair(-12, 22), Pair(-42, 2), Pair(73, 60),
        Pair(-76, 21), Pair(93, -89), Pair(-16, -16), Pair(30, 1), Pair(82, -55), Pair(91, -59), Pair(-16, -56), Pair(-105, -75),
        Pair(73, -86), Pair(-70, 15), Pair(-13, 19), Pair(63, -3), Pair(65, -42), Pair(109, 27), Pair(32, -13), Pair(-120, 0),
        Pair(10, -56), Pair(6, -19), Pair(16, -28), Pair(18, -50), Pair(37, 0), Pair(25, 1), Pair(99, -13), Pair(118, -39),
        Pair(-76, 0), Pair(-52, 17), Pair(10, -18), Pair(-39, 2), Pair(-2, 54), Pair(-9, 24), Pair(-21, 31), Pair(0, 28),
        Pair(-2, -41), Pair(11, 29), Pair(-28, 16), Pair(-46, 81), Pair(11, -17), Pair(0, 0), Pair(10, -33), Pair(-71, -66),
        Pair(13, -8), Pair(-57, 69), Pair(-35, 17), Pair(-1, -13), Pair(-23, -51), Pair(-57, 136), Pair(74, 38), Pair(-81, 61),
        Pair(-1, -69), Pair(-57, -15), Pair(-113, 17), Pair(-43, 27), Pair(16, -53), Pair(30, -34), Pair(-40, -106), Pair(-124, 78)
      },
      { // Piece 2
        Pair(-51, 11), Pair(62, -12), Pair(151, -16), Pair(-28, 34), Pair(11, 37), Pair(-63, -59), Pair(-31, -9), Pair(-108, 4),
        Pair(-141, 30), Pair(-20, 42), Pair(-65, 18), Pair(-133, 15), Pair(-124, 75), Pair(22, 10), Pair(-49, 39), Pair(-147, 21),
        Pair(-4, 5), Pair(-82, 32), Pair(-2, 36), Pair(-90, 65), Pair(-29, 29), Pair(23, 76), Pair(7, 70), Pair(-89, 16),
        Pair(-6, 10), Pair(47, 11), Pair(18, 43), Pair(26, 19), Pair(-25, 35), Pair(24, 73), Pair(-14, 27), Pair(1, -47),
        Pair(-113, 17), Pair(-47, 12), Pair(2, -1), Pair(5, 16), Pair(-22, 13), Pair(-40, 34), Pair(-8, 39), Pair(-89, 14),
        Pair(-23, 12), Pair(41, 54), Pair(-25, 57), Pair(-13, 41), Pair(-57, 28), Pair(0, 0), Pair(-23, 54), Pair(52, -35),
        Pair(-2, -32), Pair(-60, 10), Pair(-33, 100), Pair(-50, -21), Pair(18, -9), Pair(34, 91), Pair(-22, -58), Pair(-39, -6),
        Pair(-22, -19), Pair(20, 68), Pair(-34, -6), Pair(-3, 13), Pair(-116, 58), Pair(-8, -1), Pair(-174, 65), Pair(-70, -128)
      },
      { // Piece 3
        Pair(-41, 1), Pair(10, -7), Pair(-5, 15), Pair(0, -10), Pair(93, 7), Pair(112, 9), Pair(9, 11), Pair(-1, 59),
        Pair(25, -16), Pair(-7, -9), Pair(54, 2), Pair(-36, 27), Pair(-23, 32), Pair(-18, 29), Pair(-19, 16), Pair(111, -56),
        Pair(-28, -18), Pair(49, -1), Pair(-18, 0), Pair(82, -55), Pair(-34, 3), Pair(13, 31), Pair(26, -7), Pair(95, -69),
        Pair(-9, -6), Pair(-117, 35), Pair(-68, 6), Pair(-32, 9), Pair(-6, -8), Pair(48, 3), Pair(172, -80), Pair(2, -18),
        Pair(-80, 5), Pair(-50, 28), Pair(-21, -15), Pair(-29, 31), Pair(20, -13), Pair(78, 66), Pair(60, -6), Pair(3, -18),
        Pair(19, -37), Pair(-3, -36), Pair(12, 0), Pair(-39, -15), Pair(8, -55), Pair(0, 0), Pair(75, 12), Pair(80, -28),
        Pair(-78, 31), Pair(-84, 24), Pair(-31, 11), Pair(44, -25), Pair(32, -40), Pair(-16, 62), Pair(49, -55), Pair(-48, -6),
        Pair(-1, -38), Pair(-30, -12), Pair(-11, -19), Pair(-16, -1), Pair(-18, 33), Pair(-46, 13), Pair(5, 6), Pair(20, -3)
      },
      { // Piece 4
        Pair(-90, -143), Pair(55, 90), Pair(5, 18), Pair(1, -64), Pair(-68, 11), Pair(93, 103), Pair(-1, 14), Pair(4, 18),
        Pair(23, -20), Pair(-29, -81), Pair(-76, 3), Pair(-5, -24), Pair(-81, 111), Pair(56, -5), Pair(24, 10), Pair(14, -49),
        Pair(97, -133), Pair(-48, 66), Pair(-29, 67), Pair(-12, 82), Pair(82, -15), Pair(142, -59), Pair(77, -83), Pair(-18, -79),
        Pair(43, 3), Pair(-36, -19), Pair(-109, 59), Pair(-62, 134), Pair(16, -93), Pair(11, -12), Pair(12, -89), Pair(-28, 15),
        Pair(-83, 21), Pair(-23, -75), Pair(-13, 3), Pair(-64, 38), Pair(-82, 80), Pair(-20, -15), Pair(-67, 120), Pair(-5, -31),
        Pair(-63, 64), Pair(-58, -10), Pair(13, -87), Pair(-37, -9), Pair(28, -8), Pair(0, 0), Pair(-27, -51), Pair(67, -10),
        Pair(4, -146), Pair(-75, -6), Pair(-30, -94), Pair(-81, 111), Pair(-64, 72), Pair(-96, 113), Pair(-146, -11), Pair(-68, 41),
        Pair(-42, -49), Pair(-19, -133), Pair(-40, -31), Pair(-13, -74), Pair(-51, -10), Pair(2, -31), Pair(-40, 86), Pair(-103, 20)
      },
      { // Piece 5
        Pair(5, -132), Pair(-12, -119), Pair(-15, -87), Pair(-53, -72), Pair(-45, -68), Pair(-17, -107), Pair(-19, -159), Pair(-4, -39),
        Pair(-49, -109), Pair(1, -107), Pair(57, -92), Pair(52, -70), Pair(-14, -62), Pair(-43, -156), Pair(-10, -57), Pair(40, 21),
        Pair(7, -109), Pair(16, -87), Pair(13, -19), Pair(22, -109), Pair(-59, -13), Pair(10, 2), Pair(24, -29), Pair(13, -43),
        Pair(-131, -87), Pair(89, -58), Pair(48, -65), Pair(92, 2), Pair(166, -62), Pair(26, 16), Pair(21, 14), Pair(109, -13),
        Pair(-68, -40), Pair(66, -59), Pair(121, -24), Pair(80, -24), Pair(78, 21), Pair(-77, 30), Pair(115, 39), Pair(-35, 6),
        Pair(-77, -51), Pair(65, -51), Pair(45, -19), Pair(-20, 7), Pair(34, 33), Pair(0, 0), Pair(-26, 50), Pair(4, 40),
        Pair(-11, 30), Pair(31, -53), Pair(40, -10), Pair(51, 6), Pair(5, 129), Pair(-146, 87), Pair(-86, 75), Pair(-61, 60),
        Pair(84, -51), Pair(-30, 9), Pair(21, -24), Pair(15, 0), Pair(-7, 16), Pair(-70, 67), Pair(-23, 26), Pair(-29, 21)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 2), Pair(15, -15), Pair(-4, -6), Pair(-85, 11), Pair(-62, 11), Pair(53, -28), Pair(11, 35), Pair(57, -13),
        Pair(20, -4), Pair(-20, 0), Pair(29, -25), Pair(-39, 6), Pair(36, -2), Pair(23, -11), Pair(0, 0), Pair(15, -18),
        Pair(-14, -3), Pair(-7, -15), Pair(-1, -10), Pair(-6, -11), Pair(-3, 1), Pair(-7, 10), Pair(-19, 1), Pair(3, -20),
        Pair(15, -17), Pair(8, -18), Pair(14, -11), Pair(-8, -4), Pair(-6, 1), Pair(-6, 0), Pair(-15, 11), Pair(15, -5),
        Pair(-3, -22), Pair(3, -18), Pair(-22, -11), Pair(-16, 9), Pair(19, -8), Pair(-2, -2), Pair(0, 0), Pair(15, -2),
        Pair(2, -16), Pair(2, -11), Pair(9, -7), Pair(-5, 16), Pair(6, 7), Pair(-12, -12), Pair(2, -2), Pair(16, -36),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(77, -52), Pair(83, -146), Pair(-45, -69), Pair(-77, 12), Pair(-28, 21), Pair(-18, -59), Pair(-31, -127), Pair(48, -11),
        Pair(0, 24), Pair(44, -69), Pair(44, 30), Pair(23, -9), Pair(49, -22), Pair(-11, -65), Pair(-3, -53), Pair(41, -58),
        Pair(-67, -29), Pair(-24, -113), Pair(-38, -21), Pair(30, -7), Pair(31, -8), Pair(53, 12), Pair(14, -73), Pair(80, -76),
        Pair(-66, -101), Pair(-12, -7), Pair(31, -22), Pair(11, -24), Pair(25, -58), Pair(81, -53), Pair(42, 43), Pair(72, -105),
        Pair(-12, -58), Pair(-121, -3), Pair(11, -38), Pair(0, -5), Pair(55, -24), Pair(14, 79), Pair(43, 2), Pair(-14, -18),
        Pair(-45, 22), Pair(64, -64), Pair(-24, 22), Pair(-17, -4), Pair(-51, 77), Pair(39, -41), Pair(0, 0), Pair(31, 7),
        Pair(-5, 0), Pair(-21, -88), Pair(-33, 15), Pair(-2, -29), Pair(16, 24), Pair(54, -129), Pair(-20, 54), Pair(62, -131),
        Pair(-49, -39), Pair(-1, -50), Pair(-8, -54), Pair(7, -20), Pair(-70, 58), Pair(-2, -2), Pair(59, -100), Pair(-21, -126)
      },
      { // Piece 2
        Pair(-77, 111), Pair(21, -23), Pair(-63, 42), Pair(-12, 25), Pair(-19, 67), Pair(72, 52), Pair(-68, 14), Pair(114, -58),
        Pair(-155, 54), Pair(13, 62), Pair(75, -19), Pair(-90, 82), Pair(-21, 29), Pair(-157, -3), Pair(-164, 73), Pair(97, -54),
        Pair(86, -42), Pair(-103, 52), Pair(-40, 99), Pair(-73, 37), Pair(24, 67), Pair(1, 6), Pair(-28, 20), Pair(58, 58),
        Pair(20, -29), Pair(-113, 57), Pair(-36, 8), Pair(-106, 56), Pair(-13, -14), Pair(36, 16), Pair(-2, -25), Pair(24, -29),
        Pair(0, -9), Pair(-60, 8), Pair(-29, -21), Pair(-30, 5), Pair(-3, 72), Pair(64, -12), Pair(67, 2), Pair(4, -24),
        Pair(-75, 45), Pair(-29, -6), Pair(15, -16), Pair(-61, 17), Pair(-67, 23), Pair(3, 44), Pair(0, 0), Pair(137, 37),
        Pair(-109, -25), Pair(-11, -49), Pair(-49, -60), Pair(-53, 9), Pair(-3, -24), Pair(-44, -9), Pair(11, 114), Pair(88, 32),
        Pair(63, -45), Pair(116, -6), Pair(-18, -50), Pair(-40, -31), Pair(95, -53), Pair(-35, 36), Pair(-106, 23), Pair(-64, 115)
      },
      { // Piece 3
        Pair(-5, 20), Pair(70, -92), Pair(78, -48), Pair(86, -30), Pair(-103, 15), Pair(-98, 19), Pair(126, -12), Pair(-123, -6),
        Pair(47, 8), Pair(114, -63), Pair(59, -37), Pair(97, -48), Pair(35, -6), Pair(78, -38), Pair(130, -50), Pair(-6, -31),
        Pair(26, -41), Pair(125, -82), Pair(21, 2), Pair(69, -96), Pair(63, -82), Pair(84, -39), Pair(50, -16), Pair(85, -65),
        Pair(62, -47), Pair(-35, -38), Pair(84, -77), Pair(58, -31), Pair(6, -29), Pair(18, -34), Pair(-46, 32), Pair(153, -95),
        Pair(-62, -14), Pair(-22, -7), Pair(34, -43), Pair(-63, 7), Pair(1, -67), Pair(-14, -54), Pair(-28, -12), Pair(57, -42),
        Pair(-36, 18), Pair(-5, -6), Pair(-124, -43), Pair(93, -41), Pair(-81, 10), Pair(-13, -10), Pair(0, 0), Pair(-80, 1),
        Pair(-32, -33), Pair(37, -33), Pair(16, -1), Pair(-55, 14), Pair(82, -53), Pair(48, -18), Pair(-44, -30), Pair(167, -89),
        Pair(-1, -41), Pair(20, -33), Pair(19, -61), Pair(-4, -48), Pair(-18, 16), Pair(39, -43), Pair(-84, 58), Pair(-12, -53)
      },
      { // Piece 4
        Pair(-10, 101), Pair(-51, -30), Pair(62, 91), Pair(68, -41), Pair(35, 43), Pair(-48, 36), Pair(-42, -61), Pair(63, -25),
        Pair(-10, -3), Pair(27, 8), Pair(28, 117), Pair(-34, -1), Pair(-49, 52), Pair(74, 138), Pair(11, -60), Pair(61, -168),
        Pair(-49, -24), Pair(24, -108), Pair(-61, -2), Pair(28, 103), Pair(18, 27), Pair(111, -39), Pair(-19, 0), Pair(11, 8),
        Pair(-16, -12), Pair(-117, -8), Pair(-75, 39), Pair(113, -106), Pair(73, -1), Pair(-35, 38), Pair(29, 28), Pair(122, -36),
        Pair(-35, -12), Pair(-79, 24), Pair(21, -65), Pair(-72, 117), Pair(-46, -6), Pair(-140, 34), Pair(17, 4), Pair(-33, -70),
        Pair(-19, -55), Pair(-4, 0), Pair(5, -70), Pair(-31, -100), Pair(-67, 11), Pair(-51, 110), Pair(0, 0), Pair(-94, -101),
        Pair(58, -71), Pair(-17, -38), Pair(-2, -37), Pair(-14, -64), Pair(-42, 9), Pair(-158, -9), Pair(-117, 98), Pair(-126, -14),
        Pair(-76, 52), Pair(-132, -106), Pair(11, -52), Pair(11, -143), Pair(1, -31), Pair(17, -19), Pair(22, -142), Pair(-90, -97)
      },
      { // Piece 5
        Pair(-29, -144), Pair(44, -84), Pair(-31, -187), Pair(-10, -70), Pair(-21, -60), Pair(-6, -53), Pair(-61, -104), Pair(-1, -2),
        Pair(-3, -136), Pair(-33, -149), Pair(-40, -137), Pair(-69, -63), Pair(1, -40), Pair(9, -11), Pair(28, -93), Pair(27, 68),
        Pair(45, -150), Pair(76, -6), Pair(133, -62), Pair(35, -41), Pair(-33, -18), Pair(55, 33), Pair(52, -41), Pair(-11, 14),
        Pair(62, -46), Pair(146, -44), Pair(-12, -29), Pair(12, 34), Pair(78, -26), Pair(99, 29), Pair(62, 5), Pair(67, -75),
        Pair(34, -77), Pair(121, -48), Pair(-70, -3), Pair(123, -39), Pair(181, -8), Pair(121, 57), Pair(-44, 19), Pair(11, 6),
        Pair(-22, -66), Pair(137, -75), Pair(55, -33), Pair(2, 6), Pair(14, 1), Pair(-56, 62), Pair(0, 0), Pair(-114, 78),
        Pair(-10, -27), Pair(42, -58), Pair(15, 15), Pair(38, 3), Pair(-59, 54), Pair(-11, 90), Pair(-58, 90), Pair(-126, 31),
        Pair(4, -32), Pair(82, -104), Pair(27, -38), Pair(31, -72), Pair(-75, 41), Pair(-3, 40), Pair(-56, 78), Pair(-65, 71)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(3, -6), Pair(31, 4), Pair(47, 8), Pair(-70, 10), Pair(50, 6), Pair(-75, 30), Pair(37, -5), Pair(-62, -44),
        Pair(15, -10), Pair(-1, -1), Pair(12, -16), Pair(33, -3), Pair(14, 8), Pair(-40, 15), Pair(-15, 18), Pair(0, 0),
        Pair(-5, -9), Pair(14, -20), Pair(14, -4), Pair(1, -11), Pair(0, -7), Pair(-2, -4), Pair(24, -9), Pair(2, 8),
        Pair(11, -14), Pair(6, -14), Pair(4, -11), Pair(10, -13), Pair(2, -12), Pair(3, -3), Pair(4, -7), Pair(31, 11),
        Pair(5, -13), Pair(1, -18), Pair(18, -10), Pair(7, -21), Pair(0, -10), Pair(1, -4), Pair(6, -5), Pair(0, 0),
        Pair(6, -19), Pair(0, -11), Pair(10, -14), Pair(5, -21), Pair(9, -29), Pair(1, -7), Pair(-1, -31), Pair(-12, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(100, -100), Pair(-18, -28), Pair(99, -84), Pair(-35, 7), Pair(52, -76), Pair(-32, -14), Pair(-16, -101), Pair(-50, -64),
        Pair(-91, -36), Pair(24, -65), Pair(-97, -37), Pair(124, -147), Pair(18, 2), Pair(196, -59), Pair(116, -85), Pair(33, -31),
        Pair(-11, -32), Pair(-3, -72), Pair(36, -48), Pair(36, -48), Pair(115, -64), Pair(35, -11), Pair(64, -49), Pair(-5, -20),
        Pair(16, -13), Pair(15, -23), Pair(47, -73), Pair(87, -46), Pair(63, -2), Pair(69, -51), Pair(34, -49), Pair(29, 11),
        Pair(58, -41), Pair(-31, -26), Pair(21, -19), Pair(19, -51), Pair(39, -28), Pair(9, -17), Pair(72, -17), Pair(0, 12),
        Pair(-8, -28), Pair(-26, -16), Pair(28, -40), Pair(5, 5), Pair(-4, -32), Pair(14, 33), Pair(57, -76), Pair(0, 0),
        Pair(80, -121), Pair(-34, -68), Pair(53, -66), Pair(26, -40), Pair(-15, -27), Pair(-24, -6), Pair(-105, -17), Pair(20, 73),
        Pair(72, -100), Pair(36, -85), Pair(-27, 26), Pair(12, -38), Pair(30, -48), Pair(-32, 39), Pair(-29, -8), Pair(-103, 27)
      },
      { // Piece 2
        Pair(8, 20), Pair(-29, 39), Pair(13, 69), Pair(-54, 22), Pair(-141, 14), Pair(79, 42), Pair(-12, 77), Pair(-184, 1),
        Pair(55, 10), Pair(37, -18), Pair(-126, 88), Pair(-44, 31), Pair(8, 33), Pair(-9, 72), Pair(-33, 4), Pair(2, 29),
        Pair(-76, -45), Pair(27, -7), Pair(-8, 16), Pair(61, 77), Pair(16, 44), Pair(28, -15), Pair(-1, 70), Pair(26, -16),
        Pair(-17, -22), Pair(4, 21), Pair(-63, 50), Pair(8, 19), Pair(-65, 49), Pair(-56, 60), Pair(9, 9), Pair(45, 28),
        Pair(-82, 70), Pair(29, -27), Pair(31, 15), Pair(-3, -20), Pair(55, -12), Pair(9, 10), Pair(50, -5), Pair(36, 33),
        Pair(1, -2), Pair(46, -26), Pair(37, -30), Pair(8, -18), Pair(19, -38), Pair(23, 12), Pair(59, 5), Pair(0, 0),
        Pair(39, -49), Pair(19, -39), Pair(-3, 21), Pair(37, -42), Pair(17, -7), Pair(-5, 17), Pair(0, 68), Pair(-23, 127),
        Pair(28, -28), Pair(-102, -31), Pair(-16, 16), Pair(86, -77), Pair(3, -73), Pair(-3, 20), Pair(-92, 55), Pair(34, -49)
      },
      { // Piece 3
        Pair(69, -24), Pair(-68, 29), Pair(13, -24), Pair(-106, 34), Pair(102, -24), Pair(-12, -14), Pair(-40, 49), Pair(3, 26),
        Pair(46, -17), Pair(-85, 14), Pair(10, 2), Pair(12, -3), Pair(37, -17), Pair(12, -45), Pair(64, -84), Pair(44, 13),
        Pair(-26, -16), Pair(43, -36), Pair(-18, 12), Pair(33, -13), Pair(85, -32), Pair(-13, -31), Pair(64, 30), Pair(26, 19),
        Pair(34, -34), Pair(55, -59), Pair(45, -2), Pair(2, -35), Pair(30, -27), Pair(89, -45), Pair(-79, 7), Pair(59, 5),
        Pair(-1, -32), Pair(87, -26), Pair(54, 4), Pair(12, -3), Pair(15, -24), Pair(18, 0), Pair(23, 6), Pair(-17, 31),
        Pair(-35, -1), Pair(20, -40), Pair(5, -7), Pair(7, -39), Pair(25, -30), Pair(5, 18), Pair(32, 17), Pair(0, 0),
        Pair(-28, -13), Pair(50, -23), Pair(-28, 37), Pair(-48, 49), Pair(-6, 6), Pair(-24, 17), Pair(-76, -38), Pair(-82, 51),
        Pair(-2, -22), Pair(5, -17), Pair(15, -22), Pair(19, -52), Pair(-12, -10), Pair(15, -19), Pair(-20, 26), Pair(-41, 17)
      },
      { // Piece 4
        Pair(-89, 79), Pair(-28, 91), Pair(-37, 26), Pair(-20, -5), Pair(25, 31), Pair(104, 74), Pair(-31, -44), Pair(-34, -31),
        Pair(13, -92), Pair(-24, -27), Pair(24, -10), Pair(-47, 52), Pair(-70, 36), Pair(-67, 70), Pair(-25, 14), Pair(-63, 17),
        Pair(62, -105), Pair(-36, 50), Pair(15, 6), Pair(-106, 76), Pair(-126, 110), Pair(-99, 104), Pair(-34, -5), Pair(35, -72),
        Pair(108, -194), Pair(69, -38), Pair(68, -101), Pair(-82, 26), Pair(12, -59), Pair(-35, 7), Pair(-44, 101), Pair(-56, 48),
        Pair(5, -71), Pair(-27, 31), Pair(10, -41), Pair(36, -34), Pair(-37, 7), Pair(-3, -42), Pair(-48, 151), Pair(17, -65),
        Pair(-27, -156), Pair(20, -176), Pair(43, -51), Pair(-60, 79), Pair(1, -64), Pair(41, -90), Pair(-37, -40), Pair(0, 0),
        Pair(18, 25), Pair(-17, -4), Pair(-23, -34), Pair(-12, 45), Pair(-27, 14), Pair(6, -58), Pair(6, 46), Pair(-139, -8),
        Pair(-17, 42), Pair(-61, 65), Pair(-21, 17), Pair(13, -99), Pair(21, -12), Pair(-37, 39), Pair(-158, 42), Pair(-123, 2)
      },
      { // Piece 5
        Pair(-35, -200), Pair(1, -182), Pair(25, -92), Pair(6, -141), Pair(-21, -102), Pair(37, -89), Pair(-11, -32), Pair(6, 42),
        Pair(-42, -109), Pair(-3, -93), Pair(118, -144), Pair(13, -89), Pair(-8, -71), Pair(-43, -41), Pair(34, -26), Pair(25, -123),
        Pair(-29, -65), Pair(160, -79), Pair(10, -63), Pair(172, -62), Pair(120, -62), Pair(123, -26), Pair(97, -52), Pair(27, -28),
        Pair(28, -69), Pair(43, -40), Pair(78, -68), Pair(63, 2), Pair(62, 16), Pair(48, -7), Pair(79, -18), Pair(58, -16),
        Pair(20, -93), Pair(-60, -28), Pair(73, -70), Pair(37, -20), Pair(-46, 23), Pair(81, -3), Pair(81, 27), Pair(30, 15),
        Pair(-6, -54), Pair(59, -59), Pair(134, -79), Pair(81, -44), Pair(3, 4), Pair(-27, 38), Pair(-18, 59), Pair(0, 0),
        Pair(137, -51), Pair(16, -27), Pair(80, -62), Pair(30, -30), Pair(-18, 4), Pair(-52, 38), Pair(38, 20), Pair(29, 65),
        Pair(24, -33), Pair(-20, -33), Pair(-20, -34), Pair(-99, -15), Pair(-42, 4), Pair(-103, 59), Pair(-39, 51), Pair(-11, 53)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(45, 3), Pair(-16, 16), Pair(-25, 8), Pair(1, 3), Pair(35, -14), Pair(17, 13), Pair(19, -1), Pair(-50, 32),
        Pair(16, 40), Pair(4, 9), Pair(12, -5), Pair(10, -5), Pair(-4, 6), Pair(-10, 1), Pair(14, 3), Pair(5, 10),
        Pair(0, 0), Pair(-1, -6), Pair(0, -4), Pair(5, -2), Pair(2, 0), Pair(-7, 6), Pair(1, 1), Pair(0, 2),
        Pair(0, 0), Pair(4, -9), Pair(3, -3), Pair(-2, -4), Pair(0, -1), Pair(-2, 1), Pair(-1, 0), Pair(-4, 0),
        Pair(11, 11), Pair(-5, 1), Pair(3, -3), Pair(3, -6), Pair(-1, -1), Pair(-5, 0), Pair(1, -8), Pair(-2, -6),
        Pair(8, 6), Pair(-8, -8), Pair(0, 0), Pair(5, -8), Pair(-2, -6), Pair(-2, -4), Pair(-1, -7), Pair(-1, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(21, -16), Pair(54, -2), Pair(47, -95), Pair(111, -1), Pair(21, -6), Pair(39, -32), Pair(-16, 93), Pair(31, -61),
        Pair(-33, 11), Pair(-7, 21), Pair(27, 5), Pair(40, -15), Pair(114, -42), Pair(55, 12), Pair(59, -17), Pair(-26, 30),
        Pair(66, 19), Pair(57, -4), Pair(17, -4), Pair(45, -23), Pair(27, 9), Pair(99, -49), Pair(36, -34), Pair(45, -18),
        Pair(-24, 12), Pair(2, 12), Pair(-4, -1), Pair(19, -9), Pair(27, -7), Pair(40, -23), Pair(25, -2), Pair(33, -33),
        Pair(0, 0), Pair(-10, 28), Pair(6, -3), Pair(11, 6), Pair(26, -2), Pair(1, -4), Pair(14, -16), Pair(28, 5),
        Pair(6, 23), Pair(9, -71), Pair(-2, -2), Pair(17, 0), Pair(3, -2), Pair(8, -10), Pair(3, -13), Pair(15, 8),
        Pair(11, 11), Pair(20, -47), Pair(6, -3), Pair(-3, -9), Pair(-3, -12), Pair(16, -28), Pair(-6, -42), Pair(-7, -21),
        Pair(-111, -3), Pair(1, -41), Pair(-15, -8), Pair(17, 10), Pair(8, -3), Pair(6, -40), Pair(-7, 16), Pair(20, -105)
      },
      { // Piece 2
        Pair(13, 58), Pair(-48, 1), Pair(-138, 72), Pair(-1, 16), Pair(-34, 89), Pair(85, 49), Pair(-9, 1), Pair(3, 42),
        Pair(-51, 30), Pair(11, 34), Pair(-4, 18), Pair(1, 28), Pair(-68, 74), Pair(-65, 67), Pair(23, 36), Pair(71, -25),
        Pair(-16, 39), Pair(4, 21), Pair(21, 33), Pair(-35, 70), Pair(-64, 62), Pair(19, 40), Pair(-30, 6), Pair(21, -4),
        Pair(19, 19), Pair(3, 35), Pair(-27, 44), Pair(0, 23), Pair(0, 34), Pair(-8, 9), Pair(-4, 7), Pair(17, -16),
        Pair(0, 0), Pair(-8, 32), Pair(11, 3), Pair(1, 21), Pair(8, 11), Pair(7, 16), Pair(-10, 15), Pair(10, 2),
        Pair(14, 78), Pair(65, -13), Pair(-10, 34), Pair(3, 23), Pair(-7, 31), Pair(-4, 1), Pair(1, 34), Pair(-7, 5),
        Pair(1, 60), Pair(-12, 31), Pair(5, 13), Pair(-1, 24), Pair(-7, 21), Pair(-14, 27), Pair(-4, -1), Pair(-9, 11),
        Pair(22, -17), Pair(-20, 5), Pair(-5, 9), Pair(8, 20), Pair(-25, 47), Pair(-3, 10), Pair(5, 15), Pair(-26, 39)
      },
      { // Piece 3
        Pair(99, 22), Pair(30, 39), Pair(57, 37), Pair(-26, 46), Pair(100, -1), Pair(-73, 91), Pair(24, 45), Pair(21, 35),
        Pair(67, 43), Pair(36, 29), Pair(13, 43), Pair(12, 45), Pair(-13, 46), Pair(65, 8), Pair(128, 11), Pair(-19, 66),
        Pair(34, 64), Pair(0, 36), Pair(43, 31), Pair(-3, 48), Pair(42, 30), Pair(40, 5), Pair(-4, 27), Pair(-6, 42),
        Pair(20, 52), Pair(4, 23), Pair(-2, 45), Pair(9, 48), Pair(16, 22), Pair(6, 25), Pair(-34, 33), Pair(-24, 38),
        Pair(0, 0), Pair(7, 34), Pair(0, 40), Pair(14, 13), Pair(5, 17), Pair(13, 32), Pair(43, 13), Pair(12, 29),
        Pair(10, 27), Pair(-123, 52), Pair(-2, 34), Pair(-14, 32), Pair(6, 18), Pair(-3, 29), Pair(12, 31), Pair(-10, 37),
        Pair(-32, 23), Pair(-10, 31), Pair(-19, 42), Pair(-1, 16), Pair(10, 19), Pair(10, 18), Pair(3, 26), Pair(-7, 23),
        Pair(-5, 11), Pair(-8, 20), Pair(-5, 30), Pair(-5, 31), Pair(5, 16), Pair(5, 24), Pair(11, 31), Pair(4, 29)
      },
      { // Piece 4
        Pair(43, 75), Pair(65, 38), Pair(31, 66), Pair(135, -40), Pair(-47, 113), Pair(-1, 106), Pair(-57, 156), Pair(4, 69),
        Pair(30, 51), Pair(11, 74), Pair(17, 25), Pair(-22, 59), Pair(36, 46), Pair(7, 56), Pair(47, 69), Pair(107, 55),
        Pair(22, 28), Pair(46, 29), Pair(-7, 74), Pair(30, -7), Pair(59, -40), Pair(22, 18), Pair(15, 63), Pair(12, 98),
        Pair(-13, 35), Pair(3, 49), Pair(-8, 74), Pair(-31, 90), Pair(29, 91), Pair(41, 24), Pair(17, 69), Pair(36, 81),
        Pair(0, 0), Pair(-13, 119), Pair(19, 39), Pair(5, 50), Pair(-5, 77), Pair(32, 4), Pair(37, -1), Pair(29, 49),
        Pair(-6, 32), Pair(40, 137), Pair(-5, 52), Pair(-3, 31), Pair(7, 30), Pair(1, 60), Pair(20, 14), Pair(1, 48),
        Pair(-24, 65), Pair(7, 58), Pair(2, 28), Pair(4, 43), Pair(1, 50), Pair(-6, 24), Pair(25, -9), Pair(-6, 97),
        Pair(-3, 10), Pair(26, 16), Pair(-3, 23), Pair(2, 38), Pair(11, 28), Pair(-19, 55), Pair(9, -47), Pair(-13, 36)
      },
      { // Piece 5
        Pair(-19, 36), Pair(-24, -50), Pair(23, 18), Pair(15, -74), Pair(19, -82), Pair(-25, -93), Pair(-20, -40), Pair(20, -42),
        Pair(52, 50), Pair(-50, -98), Pair(137, -18), Pair(-101, 10), Pair(-94, -42), Pair(-35, -24), Pair(55, -37), Pair(34, -23),
        Pair(-14, -16), Pair(76, -6), Pair(130, -39), Pair(42, -45), Pair(45, 2), Pair(-3, -29), Pair(-46, -13), Pair(65, -31),
        Pair(86, -2), Pair(-73, 38), Pair(73, -11), Pair(72, -4), Pair(134, -35), Pair(-24, 1), Pair(50, -18), Pair(30, -13),
        Pair(0, 0), Pair(-121, 19), Pair(-32, 2), Pair(-20, 20), Pair(35, -1), Pair(23, 2), Pair(101, -25), Pair(-14, 1),
        Pair(18, 20), Pair(-5, 51), Pair(-66, 32), Pair(-36, 9), Pair(7, 7), Pair(10, -8), Pair(-21, -2), Pair(58, -31),
        Pair(30, 13), Pair(16, 33), Pair(-44, 30), Pair(-47, 22), Pair(18, -11), Pair(3, -16), Pair(7, -17), Pair(10, -10),
        Pair(40, 0), Pair(34, -3), Pair(-30, 44), Pair(-5, -7), Pair(-6, -21), Pair(-38, -6), Pair(2, -19), Pair(7, -19)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 4), Pair(-28, 33), Pair(-9, 13), Pair(55, -9), Pair(-14, 22), Pair(26, 11), Pair(32, 22), Pair(2, 1),
        Pair(0, 6), Pair(-14, 18), Pair(1, 6), Pair(3, 14), Pair(7, 5), Pair(0, 16), Pair(6, 15), Pair(-14, 19),
        Pair(1, 6), Pair(0, 0), Pair(-4, 4), Pair(3, 0), Pair(0, 3), Pair(-1, 2), Pair(-2, 2), Pair(3, 4),
        Pair(7, 2), Pair(0, 0), Pair(1, -3), Pair(1, 0), Pair(-1, -1), Pair(-5, 2), Pair(-7, 0), Pair(-2, 0),
        Pair(3, 4), Pair(7, 11), Pair(3, -5), Pair(5, -2), Pair(0, -4), Pair(-5, -1), Pair(-9, -2), Pair(-2, 0),
        Pair(4, -7), Pair(11, 6), Pair(-2, -6), Pair(8, -11), Pair(-1, -8), Pair(-4, -5), Pair(-8, -7), Pair(-1, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-74, 6), Pair(116, -61), Pair(-41, -42), Pair(89, -31), Pair(141, -42), Pair(229, -82), Pair(65, 29), Pair(-72, -43),
        Pair(5, 37), Pair(-50, 60), Pair(79, 2), Pair(32, 7), Pair(140, -42), Pair(53, -9), Pair(10, -34), Pair(81, -10),
        Pair(11, 0), Pair(-18, 34), Pair(-2, 34), Pair(44, 10), Pair(-5, 17), Pair(92, 8), Pair(37, -27), Pair(34, -7),
        Pair(19, 20), Pair(-14, 29), Pair(12, 39), Pair(7, 13), Pair(12, 34), Pair(16, 1), Pair(19, 21), Pair(4, 35),
        Pair(-1, -6), Pair(0, 0), Pair(5, 43), Pair(6, 25), Pair(22, 16), Pair(9, 31), Pair(42, 5), Pair(19, 37),
        Pair(-23, -65), Pair(7, 77), Pair(1, -12), Pair(7, 29), Pair(7, 15), Pair(10, 22), Pair(6, 12), Pair(7, -5),
        Pair(12, -67), Pair(-32, 41), Pair(-5, -9), Pair(7, 19), Pair(-3, 9), Pair(19, -16), Pair(10, 28), Pair(-1, 27),
        Pair(-57, 52), Pair(-20, -127), Pair(-31, 57), Pair(-20, 0), Pair(12, 17), Pair(24, -27), Pair(-1, -6), Pair(58, 28)
      },
      { // Piece 2
        Pair(23, -10), Pair(23, 18), Pair(27, -2), Pair(-69, 77), Pair(-9, 24), Pair(22, 87), Pair(-30, 63), Pair(2, 47),
        Pair(-11, -3), Pair(-55, 47), Pair(-50, 54), Pair(-13, 66), Pair(-20, 22), Pair(13, 61), Pair(-16, 23), Pair(51, 52),
        Pair(-1, 29), Pair(20, 20), Pair(-27, 53), Pair(-41, 59), Pair(25, 55), Pair(11, 37), Pair(35, 40), Pair(10, 14),
        Pair(21, -14), Pair(-8, 59), Pair(-24, 50), Pair(-19, 55), Pair(12, 39), Pair(8, 40), Pair(5, 38), Pair(-9, 30),
        Pair(-9, 79), Pair(0, 0), Pair(-10, 50), Pair(-8, 37), Pair(9, 21), Pair(-2, 27), Pair(-14, 12), Pair(21, -5),
        Pair(36, -77), Pair(-7, 98), Pair(-35, 70), Pair(8, 35), Pair(-7, 27), Pair(1, 23), Pair(18, -3), Pair(-4, 43),
        Pair(-1, 84), Pair(0, -1), Pair(-3, 46), Pair(-7, 14), Pair(-9, 39), Pair(-11, 15), Pair(5, 7), Pair(-5, -10),
        Pair(-12, 33), Pair(-2, 66), Pair(0, 7), Pair(7, 22), Pair(-5, -10), Pair(-5, 14), Pair(5, 9), Pair(-27, 44)
      },
      { // Piece 3
        Pair(2, 35), Pair(68, 45), Pair(-4, 48), Pair(31, 42), Pair(16, 36), Pair(101, 6), Pair(3, 38), Pair(21, 67),
        Pair(23, 57), Pair(-44, 75), Pair(3, 42), Pair(-16, 69), Pair(40, 51), Pair(26, 47), Pair(19, 35), Pair(-2, 49),
        Pair(15, 30), Pair(-67, 85), Pair(-5, 60), Pair(-8, 49), Pair(-7, 50), Pair(0, 20), Pair(-20, 31), Pair(12, 20),
        Pair(-16, 38), Pair(40, 26), Pair(-2, 47), Pair(2, 49), Pair(-19, 45), Pair(4, 32), Pair(37, 22), Pair(50, 5),
        Pair(-8, 20), Pair(0, 0), Pair(-8, 32), Pair(-2, 38), Pair(-12, 55), Pair(-7, 41), Pair(16, 48), Pair(52, 10),
        Pair(1, -30), Pair(-38, 55), Pair(-46, -17), Pair(14, 14), Pair(-32, 63), Pair(20, 18), Pair(-1, 12), Pair(34, 4),
        Pair(-2, 20), Pair(-28, 19), Pair(10, 8), Pair(-2, 26), Pair(26, -10), Pair(35, 10), Pair(13, -4), Pair(-82, 74),
        Pair(-5, 26), Pair(-6, 22), Pair(-6, 32), Pair(0, 25), Pair(-6, 35), Pair(-2, 28), Pair(-3, 31), Pair(18, 35)
      },
      { // Piece 4
        Pair(190, -59), Pair(-18, 88), Pair(-49, 127), Pair(102, -9), Pair(-9, 81), Pair(19, 39), Pair(57, 10), Pair(10, 42),
        Pair(30, 31), Pair(-2, 16), Pair(-5, 67), Pair(32, 30), Pair(27, 78), Pair(40, 88), Pair(17, 73), Pair(22, 77),
        Pair(26, 19), Pair(15, 27), Pair(-7, 121), Pair(1, 50), Pair(-4, 87), Pair(44, 24), Pair(-3, 73), Pair(12, 91),
        Pair(52, -56), Pair(24, 12), Pair(31, -31), Pair(14, 26), Pair(-4, 80), Pair(-13, 94), Pair(18, 36), Pair(46, -28),
        Pair(20, 3), Pair(0, 0), Pair(-9, 77), Pair(4, 28), Pair(15, 14), Pair(9, 17), Pair(16, 38), Pair(41, 13),
        Pair(26, -6), Pair(-8, 24), Pair(34, 66), Pair(-1, 35), Pair(11, 37), Pair(-2, 52), Pair(5, 50), Pair(-12, 96),
        Pair(13, -13), Pair(8, -23), Pair(-4, 2), Pair(3, 23), Pair(5, 19), Pair(9, -24), Pair(20, 8), Pair(-12, 87),
        Pair(3, 0), Pair(2, 13), Pair(20, -8), Pair(-3, 26), Pair(16, -16), Pair(6, 55), Pair(30, -53), Pair(-7, 112)
      },
      { // Piece 5
        Pair(-29, -135), Pair(-38, -50), Pair(14, -36), Pair(14, 40), Pair(20, 89), Pair(-43, -47), Pair(5, -85), Pair(-26, -124),
        Pair(66, 21), Pair(35, -118), Pair(-3, -89), Pair(36, 35), Pair(-64, 13), Pair(-3, -1), Pair(-39, 12), Pair(-61, -68),
        Pair(-17, 4), Pair(-14, -30), Pair(167, -52), Pair(93, -27), Pair(-3, 4), Pair(-22, -13), Pair(0, -22), Pair(-12, -48),
        Pair(-25, -37), Pair(-9, -25), Pair(-20, -4), Pair(186, -27), Pair(44, -13), Pair(21, 8), Pair(123, -21), Pair(-46, -9),
        Pair(16, 20), Pair(0, 0), Pair(31, -11), Pair(37, 1), Pair(14, -3), Pair(-2, 8), Pair(-38, 6), Pair(57, -36),
        Pair(12, 16), Pair(-92, -10), Pair(-25, -6), Pair(18, 8), Pair(-15, 8), Pair(0, -6), Pair(25, -22), Pair(44, -30),
        Pair(-32, 23), Pair(-50, 14), Pair(2, 24), Pair(-25, -9), Pair(-14, 15), Pair(-3, -1), Pair(1, -15), Pair(4, -5),
        Pair(-34, 68), Pair(9, -22), Pair(-3, -1), Pair(33, -22), Pair(-23, 1), Pair(0, -14), Pair(-1, -17), Pair(-2, -1)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(27, 8), Pair(-11, 36), Pair(11, 0), Pair(-16, 15), Pair(7, 14), Pair(46, 1), Pair(9, 35), Pair(-26, 14),
        Pair(-11, 7), Pair(-19, 15), Pair(13, 9), Pair(-9, -2), Pair(0, 13), Pair(12, 18), Pair(1, 10), Pair(-14, 4),
        Pair(0, 4), Pair(4, -4), Pair(0, 0), Pair(4, 0), Pair(1, 0), Pair(-3, 1), Pair(-4, 7), Pair(-1, 7),
        Pair(0, 3), Pair(-2, -1), Pair(0, 0), Pair(2, -1), Pair(-6, 3), Pair(1, 0), Pair(-5, -2), Pair(-6, 2),
        Pair(1, 3), Pair(10, -21), Pair(11, 12), Pair(8, -1), Pair(-5, -2), Pair(-8, 0), Pair(-8, -2), Pair(-4, -7),
        Pair(-1, -3), Pair(-1, -11), Pair(10, 3), Pair(-7, -11), Pair(1, -8), Pair(-1, -6), Pair(-6, -4), Pair(-4, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-74, 213), Pair(-27, 43), Pair(6, 27), Pair(65, -12), Pair(11, 18), Pair(126, -32), Pair(3, 113), Pair(-90, 49),
        Pair(-4, 9), Pair(-35, 37), Pair(-50, 10), Pair(-17, 25), Pair(-84, 56), Pair(5, 24), Pair(16, 29), Pair(111, -81),
        Pair(-10, 17), Pair(-19, 24), Pair(0, 12), Pair(7, 33), Pair(-39, 55), Pair(44, -15), Pair(-3, 33), Pair(-11, 46),
        Pair(-40, 15), Pair(1, 35), Pair(-1, 36), Pair(7, 36), Pair(18, 15), Pair(13, 28), Pair(14, 1), Pair(40, 6),
        Pair(-1, 14), Pair(11, 23), Pair(0, 0), Pair(-5, 48), Pair(17, 38), Pair(1, 28), Pair(41, -10), Pair(8, 29),
        Pair(27, 8), Pair(-5, -105), Pair(18, 77), Pair(-36, 29), Pair(16, 22), Pair(10, 21), Pair(7, 5), Pair(18, -23),
        Pair(-6, 39), Pair(15, -22), Pair(17, 35), Pair(1, 5), Pair(13, 21), Pair(-8, 37), Pair(26, -2), Pair(19, -27),
        Pair(-100, -41), Pair(-16, 59), Pair(-89, 60), Pair(2, -2), Pair(-8, -13), Pair(0, 30), Pair(9, 50), Pair(8, -41)
      },
      { // Piece 2
        Pair(78, 39), Pair(35, 25), Pair(-12, -6), Pair(137, 16), Pair(-13, 7), Pair(30, 51), Pair(-45, 32), Pair(163, 91),
        Pair(-29, 31), Pair(5, 56), Pair(26, 32), Pair(-31, 61), Pair(43, 27), Pair(19, 28), Pair(1, 36), Pair(-16, 74),
        Pair(-8, 5), Pair(-19, 44), Pair(-8, 33), Pair(-5, 29), Pair(-106, 104), Pair(30, 55), Pair(14, 27), Pair(8, 17),
        Pair(-30, 52), Pair(-33, 20), Pair(-12, 46), Pair(16, 22), Pair(-4, 58), Pair(-16, 54), Pair(-8, 43), Pair(7, 5),
        Pair(-25, 38), Pair(4, 39), Pair(0, 0), Pair(-6, 46), Pair(-3, 9), Pair(6, 40), Pair(14, 12), Pair(14, 6),
        Pair(-11, 29), Pair(-55, -18), Pair(-1, 88), Pair(0, 11), Pair(-4, 32), Pair(-1, 10), Pair(14, 4), Pair(13, -2),
        Pair(-82, -23), Pair(-10, 21), Pair(-2, 1), Pair(-4, 21), Pair(-4, -18), Pair(-13, 0), Pair(7, -4), Pair(25, -52),
        Pair(-16, 64), Pair(11, 14), Pair(8, 18), Pair(14, 0), Pair(-17, 46), Pair(-7, 11), Pair(-3, -8), Pair(-31, 42)
      },
      { // Piece 3
        Pair(-11, 45), Pair(11, 19), Pair(39, 16), Pair(-30, 60), Pair(124, -22), Pair(-7, 44), Pair(42, 25), Pair(51, 9),
        Pair(-12, 32), Pair(-17, 41), Pair(45, 29), Pair(38, 23), Pair(57, 27), Pair(17, 11), Pair(71, -10), Pair(-30, 38),
        Pair(35, 21), Pair(2, 30), Pair(-8, 30), Pair(-2, 36), Pair(66, 4), Pair(63, 3), Pair(-23, 26), Pair(-37, 36),
        Pair(13, 27), Pair(19, 7), Pair(-6, 63), Pair(0, 15), Pair(-11, 46), Pair(65, 5), Pair(29, 4), Pair(83, -25),
        Pair(-18, 39), Pair(21, 13), Pair(0, 0), Pair(10, 14), Pair(-8, 31), Pair(6, 18), Pair(32, -11), Pair(71, -7),
        Pair(-18, 20), Pair(67, 11), Pair(-27, 46), Pair(107, -81), Pair(12, 24), Pair(0, 40), Pair(38, 20), Pair(-15, 44),
        Pair(-25, 35), Pair(-10, 22), Pair(-16, 13), Pair(-3, -2), Pair(9, 0), Pair(4, 21), Pair(16, -3), Pair(-31, 14),
        Pair(-7, 26), Pair(-15, 20), Pair(-9, 17), Pair(-9, 23), Pair(7, 14), Pair(12, 8), Pair(24, 19), Pair(8, 35)
      },
      { // Piece 4
        Pair(8, -2), Pair(-69, 38), Pair(-72, 107), Pair(24, 103), Pair(122, 32), Pair(67, 70), Pair(29, -15), Pair(52, 30),
        Pair(53, 17), Pair(36, -3), Pair(41, 78), Pair(-46, 102), Pair(-21, 100), Pair(59, 60), Pair(53, 87), Pair(33, 35),
        Pair(1, 20), Pair(-2, 26), Pair(-1, 47), Pair(2, 48), Pair(48, 33), Pair(52, 44), Pair(-16, 72), Pair(54, 7),
        Pair(-3, 35), Pair(-31, 68), Pair(9, 38), Pair(27, 54), Pair(0, 95), Pair(20, 28), Pair(34, 1), Pair(16, 53),
        Pair(-1, 21), Pair(-1, 61), Pair(0, 0), Pair(-11, 83), Pair(-5, 51), Pair(4, 43), Pair(21, 43), Pair(59, -29),
        Pair(-3, 26), Pair(64, -22), Pair(16, 21), Pair(41, -8), Pair(28, 15), Pair(11, 32), Pair(33, -15), Pair(33, 13),
        Pair(-23, 61), Pair(-23, 90), Pair(7, 4), Pair(4, 19), Pair(17, -1), Pair(13, 26), Pair(28, -4), Pair(9, 73),
        Pair(5, -25), Pair(-9, 75), Pair(20, -11), Pair(12, -16), Pair(18, 17), Pair(-31, 80), Pair(18, 48), Pair(-35, 42)
      },
      { // Piece 5
        Pair(-9, -84), Pair(-3, -21), Pair(-49, -70), Pair(-4, -66), Pair(-46, -105), Pair(-23, -41), Pair(33, -123), Pair(-25, -44),
        Pair(3, -32), Pair(15, -29), Pair(-102, 10), Pair(-30, 10), Pair(78, -18), Pair(23, -12), Pair(156, -76), Pair(-23, 34),
        Pair(-104, -2), Pair(-30, -33), Pair(5, -12), Pair(72, -39), Pair(66, -3), Pair(125, -52), Pair(-83, 19), Pair(27, -46),
        Pair(-10, 7), Pair(88, -13), Pair(110, -19), Pair(-33, 4), Pair(-17, -3), Pair(135, -15), Pair(15, -17), Pair(-51, -14),
        Pair(-7, -21), Pair(-139, 11), Pair(0, 0), Pair(75, -26), Pair(-64, 32), Pair(50, -1), Pair(67, -15), Pair(17, 1),
        Pair(-48, 1), Pair(38, 42), Pair(-26, 6), Pair(-70, 88), Pair(4, 6), Pair(19, 14), Pair(30, -11), Pair(46, -18),
        Pair(-72, 54), Pair(-9, 5), Pair(-36, 17), Pair(18, 16), Pair(-6, 15), Pair(31, -5), Pair(9, 2), Pair(15, 6),
        Pair(-57, 24), Pair(-33, 12), Pair(-51, 30), Pair(43, 4), Pair(-11, 10), Pair(25, 10), Pair(3, 5), Pair(9, -8)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, 7), Pair(12, -11), Pair(-15, 9), Pair(-21, 11), Pair(-9, -8), Pair(10, 22), Pair(-17, 16), Pair(4, -3),
        Pair(-10, 12), Pair(8, 7), Pair(-3, -1), Pair(-7, 14), Pair(4, 5), Pair(-12, 15), Pair(5, 11), Pair(-1, 12),
        Pair(-6, 2), Pair(-3, 0), Pair(-5, 0), Pair(0, 0), Pair(2, 0), Pair(3, 0), Pair(4, 3), Pair(10, 0),
        Pair(-3, 1), Pair(2, -5), Pair(-3, -3), Pair(0, 0), Pair(-1, -2), Pair(0, 2), Pair(4, -5), Pair(3, -2),
        Pair(-5, -5), Pair(-1, -1), Pair(0, -34), Pair(11, 11), Pair(-1, -26), Pair(-2, -2), Pair(4, -6), Pair(0, -3),
        Pair(-4, 0), Pair(-3, 1), Pair(-2, -16), Pair(1, 1), Pair(-11, -11), Pair(-4, -3), Pair(3, -4), Pair(3, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(24, -10), Pair(43, -110), Pair(-47, -46), Pair(-33, 48), Pair(-25, 63), Pair(-13, 103), Pair(10, -58), Pair(115, 93),
        Pair(2, 62), Pair(14, 37), Pair(25, -4), Pair(-66, 36), Pair(38, 5), Pair(26, 18), Pair(87, 17), Pair(-44, 42),
        Pair(-35, 13), Pair(19, 9), Pair(4, 6), Pair(25, 10), Pair(17, 36), Pair(33, 38), Pair(14, -1), Pair(43, 11),
        Pair(-19, 42), Pair(-6, -27), Pair(-15, 56), Pair(-10, 28), Pair(-3, 44), Pair(3, -3), Pair(14, 10), Pair(22, 20),
        Pair(-12, -27), Pair(-14, 43), Pair(-3, 45), Pair(0, 0), Pair(17, 41), Pair(-3, 41), Pair(-1, 25), Pair(11, 16),
        Pair(0, -13), Pair(0, 7), Pair(-8, -46), Pair(10, 83), Pair(-16, 18), Pair(4, 9), Pair(11, -14), Pair(1, 56),
        Pair(-30, -34), Pair(-42, 65), Pair(-4, -10), Pair(2, 25), Pair(-2, -10), Pair(0, 32), Pair(19, -22), Pair(16, 6),
        Pair(38, 45), Pair(-3, -15), Pair(-47, 44), Pair(-46, -45), Pair(-10, 42), Pair(-16, 15), Pair(-5, 32), Pair(80, -36)
      },
      { // Piece 2
        Pair(41, 37), Pair(-67, 14), Pair(39, 12), Pair(-87, 76), Pair(-46, 50), Pair(60, 40), Pair(-54, 120), Pair(2, 45),
        Pair(5, 38), Pair(6, 26), Pair(-15, 32), Pair(41, 32), Pair(-42, 69), Pair(13, 18), Pair(87, 18), Pair(16, 69),
        Pair(-29, 96), Pair(0, 37), Pair(-25, 56), Pair(-31, 32), Pair(9, 39), Pair(19, 25), Pair(1, 64), Pair(-2, 16),
        Pair(-12, 35), Pair(6, 52), Pair(-24, 17), Pair(-9, 37), Pair(-19, 24), Pair(29, 26), Pair(-10, 45), Pair(-3, 42),
        Pair(-12, 22), Pair(-11, 28), Pair(-6, 57), Pair(0, 0), Pair(10, 35), Pair(3, 36), Pair(-1, 36), Pair(3, 30),
        Pair(-7, 9), Pair(2, 39), Pair(-42, -72), Pair(14, 88), Pair(13, -26), Pair(1, 29), Pair(13, 7), Pair(7, 12),
        Pair(-20, 54), Pair(-36, -43), Pair(-26, 58), Pair(-3, 2), Pair(-5, 24), Pair(-38, 1), Pair(-1, 14), Pair(14, -9),
        Pair(-60, -77), Pair(0, 57), Pair(-3, 7), Pair(-3, 40), Pair(-23, 6), Pair(-4, 23), Pair(-43, -42), Pair(-30, 73)
      },
      { // Piece 3
        Pair(-35, 62), Pair(-19, 49), Pair(-75, 53), Pair(-52, 38), Pair(56, 0), Pair(2, 35), Pair(48, -18), Pair(14, 31),
        Pair(11, 26), Pair(4, 26), Pair(-16, 51), Pair(-14, 47), Pair(18, 11), Pair(-1, 31), Pair(-22, 45), Pair(-20, 56),
        Pair(5, 28), Pair(10, 24), Pair(46, 9), Pair(-82, 47), Pair(-13, 32), Pair(54, 7), Pair(41, 22), Pair(9, 17),
        Pair(-19, 31), Pair(-10, 14), Pair(-2, 30), Pair(-45, 57), Pair(-10, 28), Pair(7, 22), Pair(55, 14), Pair(4, 26),
        Pair(1, 7), Pair(34, 3), Pair(15, 3), Pair(0, 0), Pair(-9, 25), Pair(-27, 28), Pair(24, 10), Pair(-3, 23),
        Pair(-45, 49), Pair(-7, 22), Pair(28, 13), Pair(-25, 31), Pair(-34, 29), Pair(-12, 16), Pair(5, -12), Pair(-34, 44),
        Pair(11, 11), Pair(11, 23), Pair(10, 2), Pair(-31, 31), Pair(4, 22), Pair(-2, 20), Pair(10, 20), Pair(-20, 39),
        Pair(1, 15), Pair(-9, 17), Pair(-3, 16), Pair(-16, 7), Pair(-6, 23), Pair(-3, 28), Pair(-2, 7), Pair(7, 19)
      },
      { // Piece 4
        Pair(6, 80), Pair(66, -5), Pair(-16, 73), Pair(95, 15), Pair(63, 22), Pair(55, 90), Pair(54, 41), Pair(37, 90),
        Pair(37, 0), Pair(-12, 90), Pair(2, 61), Pair(83, 10), Pair(7, 36), Pair(-41, 155), Pair(53, 143), Pair(8, 80),
        Pair(17, 42), Pair(11, 28), Pair(7, 50), Pair(-22, 62), Pair(20, 47), Pair(4, 48), Pair(58, 52), Pair(3, 50),
        Pair(-3, 71), Pair(7, 68), Pair(11, 27), Pair(5, 2), Pair(22, 43), Pair(-11, 100), Pair(5, 74), Pair(19, 40),
        Pair(-12, 95), Pair(10, -14), Pair(15, -7), Pair(0, 0), Pair(15, 34), Pair(0, 45), Pair(10, 95), Pair(1, 73),
        Pair(-12, 47), Pair(0, 9), Pair(-7, 32), Pair(14, 23), Pair(34, -92), Pair(8, 36), Pair(7, 44), Pair(6, 27),
        Pair(4, 46), Pair(3, -2), Pair(-2, 9), Pair(9, -1), Pair(4, 29), Pair(5, 25), Pair(4, 48), Pair(26, -6),
        Pair(8, 11), Pair(16, 13), Pair(-8, 53), Pair(7, 24), Pair(22, 2), Pair(-32, 44), Pair(-12, 2), Pair(8, 35)
      },
      { // Piece 5
        Pair(-20, -78), Pair(-25, 21), Pair(7, -7), Pair(-30, -29), Pair(14, -23), Pair(34, 7), Pair(15, -12), Pair(-1, -73),
        Pair(-6, 6), Pair(-49, -85), Pair(72, -11), Pair(-41, -118), Pair(14, 37), Pair(-60, -107), Pair(43, -12), Pair(-49, 41),
        Pair(-39, -93), Pair(18, -67), Pair(53, -12), Pair(37, -75), Pair(5, -60), Pair(135, -13), Pair(1, -12), Pair(65, 13),
        Pair(-30, -9), Pair(67, 8), Pair(165, -35), Pair(40, -25), Pair(-20, -7), Pair(72, -12), Pair(87, -14), Pair(18, -20),
        Pair(95, -15), Pair(-55, 19), Pair(-59, -19), Pair(0, 0), Pair(33, -34), Pair(15, -1), Pair(33, -11), Pair(0, 12),
        Pair(-126, 59), Pair(-72, 10), Pair(43, -4), Pair(-55, -4), Pair(50, -33), Pair(-23, 6), Pair(27, 7), Pair(32, 6),
        Pair(26, 18), Pair(-58, 4), Pair(-59, 17), Pair(-35, 8), Pair(13, 3), Pair(-34, 27), Pair(-9, 20), Pair(10, -6),
        Pair(-97, 48), Pair(-23, 21), Pair(-13, 19), Pair(24, -11), Pair(-1, -7), Pair(-29, 20), Pair(3, 9), Pair(-2, 6)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(32, -2), Pair(17, 10), Pair(2, 5), Pair(-30, 9), Pair(-37, 6), Pair(-46, 24), Pair(-5, 3), Pair(40, 0),
        Pair(-7, 6), Pair(5, 1), Pair(0, 8), Pair(-8, 7), Pair(3, -4), Pair(3, 9), Pair(3, -1), Pair(0, 6),
        Pair(-1, -1), Pair(1, -3), Pair(-2, 0), Pair(-1, 1), Pair(0, 0), Pair(-14, 6), Pair(1, 2), Pair(1, 4),
        Pair(2, -3), Pair(2, -8), Pair(3, -8), Pair(-3, -4), Pair(0, 0), Pair(2, -2), Pair(5, -1), Pair(4, 0),
        Pair(-1, -5), Pair(-1, -5), Pair(2, -4), Pair(7, -20), Pair(9, 5), Pair(-12, -14), Pair(-2, -2), Pair(5, -2),
        Pair(2, -4), Pair(0, -9), Pair(2, -5), Pair(-2, -15), Pair(11, -7), Pair(-5, -13), Pair(1, 2), Pair(6, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-31, -22), Pair(-69, 70), Pair(-20, 46), Pair(24, 12), Pair(-22, 72), Pair(85, 2), Pair(-6, 102), Pair(-42, -85),
        Pair(-31, 46), Pair(-10, 33), Pair(24, 11), Pair(-58, 38), Pair(13, 6), Pair(6, 58), Pair(-10, 4), Pair(-73, 27),
        Pair(29, 15), Pair(16, -7), Pair(5, 17), Pair(17, -3), Pair(-17, 52), Pair(37, 1), Pair(-6, 14), Pair(-23, 61),
        Pair(13, 18), Pair(-9, 23), Pair(5, -7), Pair(10, 36), Pair(-7, 49), Pair(-17, 51), Pair(-11, 15), Pair(-8, 32),
        Pair(11, 14), Pair(-14, 10), Pair(0, 25), Pair(4, 43), Pair(0, 0), Pair(2, 35), Pair(9, 61), Pair(-15, 4),
        Pair(11, 37), Pair(-4, 24), Pair(6, 9), Pair(6, -45), Pair(24, 70), Pair(-15, -6), Pair(0, 17), Pair(4, 30),
        Pair(-20, 34), Pair(-42, 46), Pair(-9, 33), Pair(-6, 2), Pair(0, 32), Pair(-4, -24), Pair(14, 7), Pair(-20, -8),
        Pair(54, -24), Pair(-1, 32), Pair(41, -59), Pair(-8, 12), Pair(-25, -17), Pair(-9, 32), Pair(-20, 2), Pair(-22, -36)
      },
      { // Piece 2
        Pair(-83, 52), Pair(62, 40), Pair(-114, 72), Pair(-56, 39), Pair(25, 39), Pair(-44, 66), Pair(91, 59), Pair(-45, 21),
        Pair(4, 33), Pair(-25, 41), Pair(7, 29), Pair(1, 26), Pair(-45, 42), Pair(-35, 34), Pair(0, 46), Pair(28, 34),
        Pair(-11, 23), Pair(-16, 38), Pair(-41, 31), Pair(2, 26), Pair(-5, 9), Pair(-12, 34), Pair(-20, 30), Pair(3, 33),
        Pair(-6, 32), Pair(-7, 31), Pair(3, 33), Pair(-24, 41), Pair(22, 17), Pair(-21, 21), Pair(1, 44), Pair(3, 15),
        Pair(-19, 17), Pair(15, 21), Pair(-10, 37), Pair(4, 23), Pair(0, 0), Pair(1, 59), Pair(4, 10), Pair(15, 24),
        Pair(5, 28), Pair(-3, 10), Pair(7, 7), Pair(21, -107), Pair(9, 71), Pair(-63, 41), Pair(1, 28), Pair(-28, 36),
        Pair(-36, 78), Pair(2, 21), Pair(-16, 4), Pair(-7, 20), Pair(-1, 16), Pair(-25, 29), Pair(-35, -16), Pair(21, 16),
        Pair(-17, 37), Pair(-14, -22), Pair(-4, 13), Pair(11, 14), Pair(-7, 42), Pair(-11, 21), Pair(-21, 85), Pair(-39, -110)
      },
      { // Piece 3
        Pair(-12, 25), Pair(13, 16), Pair(-44, 44), Pair(45, 11), Pair(-41, 33), Pair(72, -2), Pair(-26, 45), Pair(-19, 23),
        Pair(-3, 18), Pair(10, 15), Pair(16, 10), Pair(53, -1), Pair(-36, 58), Pair(-31, 37), Pair(-7, 35), Pair(81, -17),
        Pair(15, 13), Pair(-16, 25), Pair(23, 22), Pair(1, 27), Pair(-20, 32), Pair(44, -13), Pair(33, 24), Pair(1, 14),
        Pair(-11, 14), Pair(-4, 13), Pair(0, 16), Pair(-8, 35), Pair(-5, 22), Pair(26, -2), Pair(7, 4), Pair(16, 15),
        Pair(1, 14), Pair(-12, 16), Pair(-12, 20), Pair(-20, 18), Pair(0, 0), Pair(8, -8), Pair(15, 13), Pair(-12, 41),
        Pair(-11, 24), Pair(-17, 26), Pair(-11, -8), Pair(-62, 11), Pair(13, 27), Pair(2, -42), Pair(16, 9), Pair(6, -3),
        Pair(-39, 34), Pair(24, -6), Pair(-6, 1), Pair(-2, 3), Pair(-30, 25), Pair(24, -7), Pair(16, -17), Pair(49, -25),
        Pair(2, 10), Pair(-2, 10), Pair(-8, 24), Pair(-4, 7), Pair(-8, 4), Pair(2, 8), Pair(12, 4), Pair(4, 7)
      },
      { // Piece 4
        Pair(-69, 52), Pair(-29, 42), Pair(18, 35), Pair(-1, 49), Pair(-7, 29), Pair(-43, 85), Pair(36, 75), Pair(47, -2),
        Pair(14, -7), Pair(7, 32), Pair(-4, 42), Pair(35, 40), Pair(18, 22), Pair(48, -3), Pair(10, 2), Pair(-25, 22),
        Pair(-17, 90), Pair(6, 39), Pair(-8, 36), Pair(4, 66), Pair(20, 37), Pair(21, 79), Pair(-21, 28), Pair(4, 78),
        Pair(9, 10), Pair(0, 12), Pair(-6, 42), Pair(-15, 47), Pair(-23, 69), Pair(2, 44), Pair(25, 37), Pair(-1, 74),
        Pair(-5, 59), Pair(7, 46), Pair(-6, -10), Pair(15, 12), Pair(0, 0), Pair(-2, 46), Pair(-10, 83), Pair(17, 23),
        Pair(9, 24), Pair(-2, 17), Pair(-4, 50), Pair(33, -34), Pair(3, 40), Pair(-11, 13), Pair(-2, 50), Pair(-8, 69),
        Pair(-5, 49), Pair(3, 15), Pair(4, 8), Pair(-8, 13), Pair(7, 12), Pair(-9, 58), Pair(4, 9), Pair(27, 86),
        Pair(-10, 33), Pair(16, 11), Pair(1, 31), Pair(0, 13), Pair(8, 28), Pair(-5, 13), Pair(-1, -4), Pair(24, -13)
      },
      { // Piece 5
        Pair(-57, -118), Pair(-20, -77), Pair(87, -62), Pair(-21, 19), Pair(-10, -77), Pair(42, -78), Pair(-33, 31), Pair(3, -54),
        Pair(-59, 13), Pair(42, -74), Pair(-45, -32), Pair(21, -68), Pair(42, -53), Pair(14, -5), Pair(34, -49), Pair(-29, 18),
        Pair(-45, -50), Pair(53, -12), Pair(-13, -33), Pair(77, -68), Pair(89, -14), Pair(113, -23), Pair(109, -57), Pair(-116, -16),
        Pair(0, -34), Pair(23, 3), Pair(159, -52), Pair(-102, 16), Pair(67, -31), Pair(5, 20), Pair(-27, 3), Pair(68, -6),
        Pair(2, 36), Pair(95, 13), Pair(10, -1), Pair(31, -46), Pair(0, 0), Pair(131, -53), Pair(59, -7), Pair(68, 11),
        Pair(30, -2), Pair(117, -16), Pair(30, 8), Pair(-115, -21), Pair(-29, -6), Pair(-11, 8), Pair(13, 12), Pair(-20, 34),
        Pair(16, 13), Pair(40, -14), Pair(26, 5), Pair(36, 2), Pair(23, 4), Pair(21, -3), Pair(-18, 29), Pair(-2, 26),
        Pair(16, -30), Pair(-1, 0), Pair(10, 23), Pair(-12, 24), Pair(-7, 15), Pair(10, 8), Pair(-7, 26), Pair(-6, 26)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(29, -1), Pair(10, -5), Pair(21, 7), Pair(4, -1), Pair(10, -2), Pair(-41, 54), Pair(-37, 27), Pair(1, 7),
        Pair(9, 3), Pair(20, -2), Pair(14, -1), Pair(-4, 5), Pair(-16, 27), Pair(-2, -2), Pair(6, -11), Pair(1, 3),
        Pair(8, -5), Pair(1, -2), Pair(4, -1), Pair(-3, -1), Pair(13, -6), Pair(0, 0), Pair(6, -4), Pair(7, 1),
        Pair(7, -6), Pair(4, -2), Pair(2, -7), Pair(-2, 0), Pair(1, 0), Pair(0, 0), Pair(4, -7), Pair(2, -2),
        Pair(6, -12), Pair(-1, -6), Pair(-1, -2), Pair(2, -4), Pair(-1, 3), Pair(15, 3), Pair(-3, -22), Pair(7, -1),
        Pair(5, -11), Pair(3, -6), Pair(-2, -2), Pair(20, -12), Pair(-7, -1), Pair(7, -3), Pair(-2, -12), Pair(6, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, -5), Pair(17, 8), Pair(-41, 0), Pair(-20, -22), Pair(29, -1), Pair(-95, -8), Pair(75, -73), Pair(-58, 67),
        Pair(3, 41), Pair(-17, 10), Pair(85, -12), Pair(14, 39), Pair(-22, 32), Pair(-7, 31), Pair(17, 31), Pair(-28, 30),
        Pair(3, -16), Pair(20, 6), Pair(56, 7), Pair(13, 13), Pair(13, -1), Pair(82, 19), Pair(25, 19), Pair(31, 44),
        Pair(-36, 10), Pair(19, -20), Pair(15, -10), Pair(8, -19), Pair(23, 41), Pair(-4, 26), Pair(36, -13), Pair(-30, -75),
        Pair(-12, 19), Pair(22, -4), Pair(8, 8), Pair(3, 15), Pair(9, 20), Pair(0, 0), Pair(7, 10), Pair(8, 26),
        Pair(-7, -43), Pair(-12, 6), Pair(6, -2), Pair(28, -11), Pair(-21, -2), Pair(20, 49), Pair(10, -12), Pair(27, -6),
        Pair(-86, 52), Pair(-30, 58), Pair(-2, -8), Pair(8, 10), Pair(-8, -19), Pair(30, -12), Pair(-13, 15), Pair(-3, 38),
        Pair(-44, -69), Pair(-33, -25), Pair(-33, 7), Pair(-26, -10), Pair(-3, 19), Pair(-27, -42), Pair(7, 42), Pair(-65, 5)
      },
      { // Piece 2
        Pair(26, 37), Pair(52, -48), Pair(-57, 44), Pair(56, 11), Pair(-166, 67), Pair(-47, -11), Pair(4, 13), Pair(130, 22),
        Pair(-40, 16), Pair(-37, 45), Pair(34, -20), Pair(-29, 32), Pair(-1, -5), Pair(-122, 15), Pair(47, -10), Pair(-64, 75),
        Pair(-19, 26), Pair(-20, 23), Pair(-18, 42), Pair(-57, 38), Pair(-27, 1), Pair(-41, 57), Pair(-4, 4), Pair(-34, 4),
        Pair(10, 17), Pair(20, 3), Pair(22, 12), Pair(6, 29), Pair(-3, -2), Pair(-18, 25), Pair(20, 12), Pair(-10, 53),
        Pair(27, -3), Pair(-6, 15), Pair(12, 4), Pair(-16, 10), Pair(11, 13), Pair(0, 0), Pair(-3, 38), Pair(-15, 7),
        Pair(2, -14), Pair(3, 19), Pair(-11, 18), Pair(15, 11), Pair(-8, 16), Pair(20, 62), Pair(-1, -98), Pair(10, 12),
        Pair(-27, 24), Pair(-12, 5), Pair(0, 7), Pair(-15, -19), Pair(-2, 19), Pair(0, -4), Pair(8, 0), Pair(-78, -57),
        Pair(-23, 53), Pair(-46, 50), Pair(-37, -12), Pair(18, 9), Pair(0, -6), Pair(13, -11), Pair(4, 22), Pair(-35, 94)
      },
      { // Piece 3
        Pair(2, 20), Pair(-53, 28), Pair(65, 7), Pair(-22, 36), Pair(-28, 30), Pair(-2, 30), Pair(-53, 29), Pair(-42, 26),
        Pair(-13, 21), Pair(-44, 10), Pair(37, -6), Pair(-17, 13), Pair(21, 24), Pair(16, 6), Pair(113, -21), Pair(1, 15),
        Pair(19, 2), Pair(19, -12), Pair(33, -23), Pair(46, -15), Pair(5, 6), Pair(-52, 50), Pair(37, -4), Pair(-64, 25),
        Pair(20, 1), Pair(-33, 3), Pair(20, 18), Pair(-11, 15), Pair(38, -22), Pair(46, 32), Pair(-92, 35), Pair(32, 2),
        Pair(-16, 0), Pair(-19, 20), Pair(3, -12), Pair(-3, -31), Pair(26, -9), Pair(0, 0), Pair(2, -47), Pair(6, 35),
        Pair(6, -4), Pair(5, 6), Pair(-39, 18), Pair(1, -5), Pair(33, -80), Pair(-27, 19), Pair(38, -71), Pair(-51, 50),
        Pair(2, -30), Pair(-18, 32), Pair(-24, 8), Pair(29, -22), Pair(-7, 2), Pair(-26, -7), Pair(25, 7), Pair(32, -22),
        Pair(-3, 4), Pair(-11, 17), Pair(-4, -1), Pair(-4, 11), Pair(0, -2), Pair(-12, -7), Pair(-3, -11), Pair(0, 9)
      },
      { // Piece 4
        Pair(2, -14), Pair(-38, 66), Pair(3, 70), Pair(-31, 95), Pair(116, -115), Pair(-44, 80), Pair(-95, 42), Pair(40, 54),
        Pair(18, 3), Pair(-13, 7), Pair(2, 19), Pair(-17, 60), Pair(29, 19), Pair(39, 22), Pair(-17, 62), Pair(1, 79),
        Pair(-14, 10), Pair(63, 25), Pair(9, -33), Pair(1, -4), Pair(-12, 75), Pair(-33, 88), Pair(19, 8), Pair(-17, -10),
        Pair(-2, -3), Pair(15, 28), Pair(-46, 106), Pair(9, -3), Pair(-15, 33), Pair(-40, 73), Pair(28, 24), Pair(-13, 33),
        Pair(-9, 3), Pair(41, -34), Pair(-4, 59), Pair(25, -28), Pair(-20, 78), Pair(0, 0), Pair(-10, -4), Pair(-20, -12),
        Pair(8, 44), Pair(-27, 62), Pair(6, -22), Pair(-9, 6), Pair(-23, 48), Pair(-8, 45), Pair(17, -119), Pair(7, -14),
        Pair(23, -20), Pair(-19, 9), Pair(-4, 26), Pair(-13, 19), Pair(-22, 30), Pair(-21, 13), Pair(6, 12), Pair(-39, -15),
        Pair(-21, 29), Pair(-30, 46), Pair(-2, -19), Pair(-4, 24), Pair(-2, -13), Pair(-28, -14), Pair(102, -119), Pair(-57, 38)
      },
      { // Piece 5
        Pair(-14, -69), Pair(47, -62), Pair(-72, -148), Pair(31, -44), Pair(-1, -77), Pair(-58, -40), Pair(-30, 8), Pair(32, -2),
        Pair(-69, -106), Pair(56, -74), Pair(37, -19), Pair(29, -82), Pair(-27, -80), Pair(65, -94), Pair(-25, -71), Pair(10, -53),
        Pair(-31, -20), Pair(-16, -32), Pair(56, -49), Pair(-25, -13), Pair(28, -6), Pair(168, -63), Pair(110, -31), Pair(28, -2),
        Pair(-125, -5), Pair(-51, -8), Pair(47, -34), Pair(32, -3), Pair(-33, 34), Pair(41, 5), Pair(11, 28), Pair(-76, 35),
        Pair(14, -21), Pair(81, -3), Pair(107, -8), Pair(19, 0), Pair(88, -28), Pair(0, 0), Pair(7, -7), Pair(-122, 38),
        Pair(8, -29), Pair(54, 8), Pair(38, 12), Pair(30, 9), Pair(79, 48), Pair(-50, -1), Pair(-21, -19), Pair(-6, 37),
        Pair(64, -44), Pair(14, 9), Pair(13, -3), Pair(-2, 9), Pair(21, 11), Pair(-20, 16), Pair(-7, 18), Pair(-21, 25),
        Pair(41, -36), Pair(21, -28), Pair(1, 6), Pair(66, 4), Pair(-29, 22), Pair(-51, 28), Pair(-13, 19), Pair(-10, 34)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(13, -2), Pair(-6, 24), Pair(19, 6), Pair(48, 3), Pair(55, -12), Pair(30, 19), Pair(-71, 47), Pair(-49, 36),
        Pair(10, 0), Pair(1, -4), Pair(23, -4), Pair(-24, 11), Pair(-1, -3), Pair(-18, 0), Pair(19, -1), Pair(-23, 9),
        Pair(-1, -1), Pair(2, -2), Pair(3, -8), Pair(-5, -4), Pair(-2, -2), Pair(-6, 4), Pair(0, 0), Pair(13, 2),
        Pair(2, -3), Pair(-3, -4), Pair(1, -5), Pair(-8, 2), Pair(1, -6), Pair(-5, 0), Pair(0, 0), Pair(11, 4),
        Pair(3, -4), Pair(4, -9), Pair(-2, -4), Pair(-2, -2), Pair(-3, -5), Pair(1, 5), Pair(5, 2), Pair(0, 5),
        Pair(2, -7), Pair(3, -6), Pair(-5, -5), Pair(1, -8), Pair(-7, -3), Pair(-3, -5), Pair(-5, 2), Pair(1, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(36, -101), Pair(-26, 19), Pair(-153, -16), Pair(88, -106), Pair(-62, 35), Pair(-55, -54), Pair(80, 110), Pair(79, -175),
        Pair(-3, -10), Pair(34, -27), Pair(89, -23), Pair(-25, 25), Pair(103, 0), Pair(49, -28), Pair(43, 32), Pair(15, -47),
        Pair(-62, 18), Pair(36, -9), Pair(-33, 12), Pair(33, -11), Pair(86, 12), Pair(-25, 29), Pair(30, 19), Pair(5, 58),
        Pair(-43, 18), Pair(-14, 23), Pair(18, 20), Pair(37, -4), Pair(36, 19), Pair(2, 27), Pair(-17, 30), Pair(34, -17),
        Pair(-3, -1), Pair(-25, 28), Pair(8, 7), Pair(10, 19), Pair(24, 9), Pair(12, 19), Pair(0, 0), Pair(-8, 16),
        Pair(-27, 39), Pair(-8, 26), Pair(-2, 32), Pair(20, -5), Pair(20, 6), Pair(-9, 3), Pair(20, 47), Pair(-4, 10),
        Pair(1, 24), Pair(-2, 32), Pair(-7, 4), Pair(-1, 12), Pair(4, -4), Pair(-17, 7), Pair(14, 25), Pair(-15, 1),
        Pair(-112, 73), Pair(-5, -48), Pair(-32, -12), Pair(1, 32), Pair(0, -22), Pair(5, 12), Pair(-50, -47), Pair(26, 17)
      },
      { // Piece 2
        Pair(-38, -19), Pair(-11, 59), Pair(-231, 48), Pair(-149, 47), Pair(-39, 16), Pair(55, 4), Pair(35, -1), Pair(-21, 27),
        Pair(-20, 24), Pair(-41, 44), Pair(20, 31), Pair(10, 48), Pair(-9, 21), Pair(-6, 5), Pair(39, 26), Pair(-66, 78),
        Pair(-18, 15), Pair(47, -4), Pair(-8, 35), Pair(12, 20), Pair(60, 14), Pair(50, 0), Pair(-53, 36), Pair(24, 4),
        Pair(-3, 4), Pair(12, -1), Pair(-11, 27), Pair(-6, 27), Pair(-11, 15), Pair(10, 24), Pair(11, 30), Pair(-116, 16),
        Pair(-26, 6), Pair(15, 8), Pair(-2, 7), Pair(16, 13), Pair(2, 13), Pair(15, 14), Pair(0, 0), Pair(-41, 67),
        Pair(8, 3), Pair(26, -9), Pair(8, 16), Pair(5, 5), Pair(-6, 28), Pair(51, -62), Pair(20, 57), Pair(-56, -10),
        Pair(-30, 5), Pair(8, -12), Pair(24, -12), Pair(11, -7), Pair(-11, 1), Pair(-23, 18), Pair(12, 2), Pair(51, -55),
        Pair(-54, 41), Pair(37, -11), Pair(7, -8), Pair(-24, 14), Pair(7, 1), Pair(-3, -2), Pair(-19, 3), Pair(-46, 50)
      },
      { // Piece 3
        Pair(11, 17), Pair(34, 10), Pair(-56, 38), Pair(72, -2), Pair(-9, 24), Pair(14, 22), Pair(-33, 34), Pair(-107, 50),
        Pair(-27, 20), Pair(13, 5), Pair(24, -2), Pair(0, -3), Pair(-36, 11), Pair(-7, 14), Pair(-59, 32), Pair(14, -19),
        Pair(40, 1), Pair(-16, 3), Pair(-44, 36), Pair(-25, 9), Pair(-64, 10), Pair(77, -35), Pair(2, 9), Pair(13, -3),
        Pair(-2, 5), Pair(-16, 19), Pair(-12, -3), Pair(105, -31), Pair(53, -13), Pair(-19, 14), Pair(10, 26), Pair(-43, -8),
        Pair(-16, 12), Pair(-43, 13), Pair(16, 1), Pair(7, -22), Pair(51, -10), Pair(22, 21), Pair(0, 0), Pair(23, -37),
        Pair(17, -27), Pair(-13, -8), Pair(-17, 3), Pair(22, 9), Pair(-11, 6), Pair(44, -92), Pair(5, -14), Pair(11, -21),
        Pair(25, -14), Pair(13, -13), Pair(6, -4), Pair(-28, 9), Pair(3, 2), Pair(-9, 19), Pair(-30, -13), Pair(15, -53),
        Pair(12, 1), Pair(-14, 20), Pair(2, 12), Pair(2, 2), Pair(2, 3), Pair(-2, 9), Pair(-4, -8), Pair(-16, -8)
      },
      { // Piece 4
        Pair(-29, 11), Pair(79, -65), Pair(73, -59), Pair(49, -18), Pair(62, 14), Pair(182, -119), Pair(-84, -41), Pair(-60, 76),
        Pair(18, -50), Pair(12, 33), Pair(5, 45), Pair(27, -66), Pair(-63, -11), Pair(14, -29), Pair(38, -103), Pair(-71, 105),
        Pair(28, -40), Pair(2, 1), Pair(-16, 52), Pair(-1, 24), Pair(19, -5), Pair(10, 65), Pair(-18, 25), Pair(16, -20),
        Pair(-2, -41), Pair(-12, 28), Pair(27, 2), Pair(24, -15), Pair(25, -6), Pair(27, 25), Pair(0, 57), Pair(15, -49),
        Pair(1, -44), Pair(36, -52), Pair(-8, 20), Pair(-22, 102), Pair(-1, 11), Pair(-5, 37), Pair(0, 0), Pair(-52, 94),
        Pair(2, -22), Pair(3, 5), Pair(-2, -5), Pair(20, -58), Pair(1, -24), Pair(-35, 1), Pair(-5, 54), Pair(-41, -15),
        Pair(-42, -19), Pair(-14, -17), Pair(-1, 1), Pair(-2, -7), Pair(-20, 5), Pair(4, -53), Pair(-25, 12), Pair(7, 97),
        Pair(-15, 26), Pair(11, -47), Pair(-6, -1), Pair(0, -38), Pair(-6, -24), Pair(-9, -22), Pair(-100, 14), Pair(-7, 20)
      },
      { // Piece 5
        Pair(3, -86), Pair(-12, -63), Pair(-21, -94), Pair(41, 33), Pair(68, 38), Pair(-29, 3), Pair(-36, -54), Pair(-20, -202),
        Pair(-76, -87), Pair(0, -74), Pair(113, -86), Pair(3, -123), Pair(-12, -59), Pair(75, -2), Pair(80, -57), Pair(-7, 0),
        Pair(173, -13), Pair(-25, -47), Pair(-63, -19), Pair(-38, -3), Pair(44, 14), Pair(131, -23), Pair(50, -36), Pair(135, 25),
        Pair(-16, 0), Pair(80, -14), Pair(34, -18), Pair(36, 2), Pair(-59, 9), Pair(168, -17), Pair(26, 20), Pair(-24, 5),
        Pair(-59, -55), Pair(122, -23), Pair(52, -14), Pair(29, -6), Pair(31, 2), Pair(52, -19), Pair(0, 0), Pair(-72, 21),
        Pair(27, -23), Pair(11, -18), Pair(-14, -5), Pair(44, -1), Pair(-22, 16), Pair(113, -64), Pair(13, -25), Pair(-1, -26),
        Pair(-39, -11), Pair(-17, -15), Pair(-14, -1), Pair(-32, 22), Pair(-18, 10), Pair(35, 4), Pair(-8, 11), Pair(7, 6),
        Pair(2, 14), Pair(10, -34), Pair(1, -19), Pair(8, 0), Pair(-26, 16), Pair(22, 4), Pair(-3, 3), Pair(-12, 1)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-28, 11), Pair(36, -9), Pair(57, -3), Pair(8, -3), Pair(30, 11), Pair(-58, 10), Pair(-59, -3), Pair(83, 11),
        Pair(16, -8), Pair(-2, -8), Pair(10, -7), Pair(-15, 12), Pair(21, -8), Pair(-1, -2), Pair(-3, 20), Pair(-2, -8),
        Pair(-1, -2), Pair(-3, -4), Pair(0, -8), Pair(-10, 1), Pair(-1, -3), Pair(-7, -1), Pair(-14, -2), Pair(0, 0),
        Pair(4, -4), Pair(2, -7), Pair(-6, -3), Pair(2, -8), Pair(-6, -4), Pair(-2, -2), Pair(2, -8), Pair(0, 0),
        Pair(-1, -6), Pair(2, -6), Pair(1, -7), Pair(-2, -3), Pair(-2, -5), Pair(-5, 2), Pair(-18, -6), Pair(3, 4),
        Pair(-4, -5), Pair(2, -8), Pair(-7, -4), Pair(-6, -4), Pair(2, -4), Pair(-3, 0), Pair(-11, -9), Pair(-7, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(13, -3), Pair(117, -47), Pair(-5, -40), Pair(-19, -55), Pair(-20, -9), Pair(-91, -13), Pair(32, -26), Pair(37, -55),
        Pair(-7, -47), Pair(-9, -41), Pair(7, 16), Pair(73, -4), Pair(-18, -11), Pair(-47, 1), Pair(36, 5), Pair(-7, 17),
        Pair(57, -71), Pair(18, -19), Pair(-2, -19), Pair(51, -15), Pair(55, -14), Pair(42, 2), Pair(65, -20), Pair(-46, 35),
        Pair(32, -34), Pair(4, -17), Pair(32, 0), Pair(29, -17), Pair(41, -15), Pair(40, -10), Pair(23, -11), Pair(20, 3),
        Pair(31, -42), Pair(-11, -30), Pair(-4, -4), Pair(28, -2), Pair(22, 0), Pair(22, 20), Pair(45, -28), Pair(0, 0),
        Pair(4, -19), Pair(15, -35), Pair(13, -5), Pair(37, -4), Pair(14, -5), Pair(25, -22), Pair(15, -35), Pair(17, 54),
        Pair(6, -47), Pair(12, -18), Pair(15, -30), Pair(10, -8), Pair(22, -6), Pair(-5, 3), Pair(-30, 43), Pair(33, -34),
        Pair(39, 65), Pair(-18, -2), Pair(30, -28), Pair(13, -39), Pair(34, -33), Pair(-17, -22), Pair(-4, -30), Pair(-8, -63)
      },
      { // Piece 2
        Pair(20, -5), Pair(-103, 33), Pair(-136, 51), Pair(102, -7), Pair(-213, 48), Pair(20, 10), Pair(-106, 2), Pair(9, 28),
        Pair(-3, 33), Pair(-49, 26), Pair(-53, 50), Pair(-67, 68), Pair(-10, 43), Pair(-54, 42), Pair(-17, -6), Pair(62, 17),
        Pair(-45, 49), Pair(-22, 38), Pair(-52, 34), Pair(14, 33), Pair(40, 33), Pair(-3, 59), Pair(-8, 26), Pair(-3, 9),
        Pair(-3, 15), Pair(-8, 3), Pair(8, 9), Pair(-11, 18), Pair(15, 25), Pair(-22, 22), Pair(38, -4), Pair(41, 28),
        Pair(-15, -8), Pair(-35, 2), Pair(13, 10), Pair(-24, 33), Pair(5, 15), Pair(4, 25), Pair(-5, 6), Pair(0, 0),
        Pair(4, 13), Pair(9, 19), Pair(9, 17), Pair(2, 20), Pair(25, -2), Pair(-2, 29), Pair(45, -10), Pair(24, 61),
        Pair(-5, 30), Pair(19, -6), Pair(5, -9), Pair(-4, 30), Pair(11, 10), Pair(0, 23), Pair(4, 17), Pair(15, -17),
        Pair(-9, -13), Pair(31, -11), Pair(-2, 12), Pair(4, 0), Pair(-7, 8), Pair(10, -3), Pair(30, -36), Pair(26, 34)
      },
      { // Piece 3
        Pair(-14, 9), Pair(-44, 22), Pair(-50, 6), Pair(7, -8), Pair(-91, 35), Pair(39, 6), Pair(-24, 29), Pair(109, 12),
        Pair(45, -13), Pair(-22, 2), Pair(65, -16), Pair(-29, 18), Pair(19, -9), Pair(-11, 7), Pair(26, -8), Pair(-14, 33),
        Pair(6, 20), Pair(15, -6), Pair(42, -12), Pair(8, 1), Pair(36, -9), Pair(2, 11), Pair(28, 15), Pair(143, -2),
        Pair(9, 1), Pair(28, -19), Pair(30, -2), Pair(38, -13), Pair(16, 11), Pair(23, -4), Pair(-6, 3), Pair(49, 14),
        Pair(20, 10), Pair(40, -17), Pair(29, 8), Pair(-7, 19), Pair(-4, 20), Pair(10, 38), Pair(32, 26), Pair(0, 0),
        Pair(6, 23), Pair(-15, 19), Pair(57, -3), Pair(-13, 7), Pair(37, -17), Pair(0, 15), Pair(33, -86), Pair(-41, 46),
        Pair(16, -1), Pair(18, 6), Pair(-2, -16), Pair(12, 3), Pair(-27, 34), Pair(31, -6), Pair(-26, 10), Pair(-48, 25),
        Pair(3, 0), Pair(18, 6), Pair(9, 14), Pair(4, 6), Pair(3, 7), Pair(14, 12), Pair(-4, 8), Pair(-26, 16)
      },
      { // Piece 4
        Pair(1, -61), Pair(128, -62), Pair(-1, -16), Pair(114, -47), Pair(98, -68), Pair(66, -65), Pair(-52, 8), Pair(8, -7),
        Pair(-25, 42), Pair(-2, 12), Pair(11, -6), Pair(23, -5), Pair(29, -5), Pair(-20, -13), Pair(108, -31), Pair(-67, 21),
        Pair(36, -16), Pair(93, -102), Pair(-19, 53), Pair(25, -30), Pair(1, 36), Pair(22, 16), Pair(35, 41), Pair(-14, 14),
        Pair(-3, -8), Pair(34, -44), Pair(-15, 10), Pair(-9, -7), Pair(-4, -12), Pair(-17, 41), Pair(4, -12), Pair(33, 13),
        Pair(0, -35), Pair(15, 1), Pair(-1, 24), Pair(8, -1), Pair(-31, 70), Pair(33, -12), Pair(-16, 33), Pair(0, 0),
        Pair(23, -41), Pair(-13, 8), Pair(11, -18), Pair(-14, 29), Pair(-6, 25), Pair(-1, 19), Pair(86, 53), Pair(-20, 100),
        Pair(-20, 36), Pair(7, -7), Pair(-11, 25), Pair(12, -20), Pair(-2, -16), Pair(11, -19), Pair(34, -93), Pair(-35, -15),
        Pair(0, 27), Pair(-14, 81), Pair(16, 3), Pair(4, -9), Pair(31, -30), Pair(-53, 38), Pair(72, -63), Pair(-52, 3)
      },
      { // Piece 5
        Pair(-24, -155), Pair(3, 14), Pair(79, -87), Pair(51, -42), Pair(31, -101), Pair(34, -73), Pair(36, -19), Pair(-18, -85),
        Pair(40, -111), Pair(-26, -96), Pair(-22, -84), Pair(-2, -70), Pair(-21, -2), Pair(57, -31), Pair(-16, -77), Pair(-1, -92),
        Pair(-17, -48), Pair(-23, -29), Pair(74, -50), Pair(-54, -44), Pair(76, -54), Pair(62, -22), Pair(-35, -44), Pair(112, -64),
        Pair(-11, -57), Pair(40, -24), Pair(144, -60), Pair(79, -33), Pair(5, -1), Pair(106, -15), Pair(77, 24), Pair(71, -20),
        Pair(69, -15), Pair(75, -49), Pair(33, -28), Pair(49, -29), Pair(-17, 4), Pair(-72, 22), Pair(31, -12), Pair(0, 0),
        Pair(-3, -55), Pair(-23, -21), Pair(18, -35), Pair(35, -10), Pair(42, -7), Pair(-54, 31), Pair(-16, -25), Pair(75, -16),
        Pair(-38, 31), Pair(-9, -38), Pair(32, -29), Pair(-18, -9), Pair(-5, 10), Pair(-23, 22), Pair(16, 24), Pair(6, 18),
        Pair(-50, 4), Pair(-7, -33), Pair(-18, -11), Pair(42, -8), Pair(-14, -1), Pair(-42, 31), Pair(6, 6), Pair(-2, 3)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, -65), Pair(-28, 27), Pair(-13, 11), Pair(20, -6), Pair(-14, 13), Pair(51, -6), Pair(-17, 14), Pair(-19, 23),
        Pair(3, 5), Pair(-4, 5), Pair(7, 5), Pair(4, 4), Pair(0, 17), Pair(6, 6), Pair(-16, 17), Pair(-11, 14),
        Pair(0, 0), Pair(-8, -3), Pair(-1, -4), Pair(3, 0), Pair(-3, 3), Pair(-6, 5), Pair(-1, 3), Pair(-4, 4),
        Pair(0, 0), Pair(-8, -5), Pair(0, -1), Pair(-3, 1), Pair(-5, 6), Pair(-7, 3), Pair(-2, 2), Pair(-3, 4),
        Pair(3, 6), Pair(-4, -1), Pair(2, -2), Pair(0, -2), Pair(-2, 0), Pair(-5, -1), Pair(-2, -2), Pair(-4, -3),
        Pair(6, 3), Pair(-4, -2), Pair(2, -2), Pair(-1, -2), Pair(-3, 1), Pair(-4, -3), Pair(-1, -2), Pair(0, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-96, 20), Pair(-76, 31), Pair(27, 25), Pair(3, 25), Pair(-81, 62), Pair(40, 72), Pair(-112, -16), Pair(-40, -31),
        Pair(30, 27), Pair(13, 3), Pair(0, 15), Pair(54, 18), Pair(1, 26), Pair(4, 21), Pair(102, 3), Pair(63, -12),
        Pair(107, -69), Pair(1, 24), Pair(-11, 20), Pair(23, 19), Pair(23, -7), Pair(69, -5), Pair(54, -17), Pair(11, 1),
        Pair(0, 0), Pair(1, 24), Pair(3, 25), Pair(5, 16), Pair(9, 21), Pair(23, 6), Pair(21, 5), Pair(39, 1),
        Pair(4, 48), Pair(-53, -21), Pair(4, 19), Pair(6, 15), Pair(16, 10), Pair(7, 6), Pair(15, 3), Pair(16, 5),
        Pair(-12, 43), Pair(0, 14), Pair(-5, 18), Pair(-2, 19), Pair(-1, 10), Pair(4, 13), Pair(-1, 26), Pair(9, 12),
        Pair(-14, -21), Pair(25, -14), Pair(0, -8), Pair(-4, 12), Pair(-10, 19), Pair(3, 6), Pair(-10, -3), Pair(-12, 20),
        Pair(-113, -50), Pair(-2, 39), Pair(-11, 3), Pair(34, -11), Pair(7, -6), Pair(1, 17), Pair(0, 23), Pair(-3, -90)
      },
      { // Piece 2
        Pair(-86, 35), Pair(-21, 57), Pair(-75, 63), Pair(-38, 79), Pair(17, 53), Pair(-86, 61), Pair(-3, 27), Pair(61, 35),
        Pair(-33, 66), Pair(-18, 25), Pair(-16, 54), Pair(-88, 58), Pair(-34, 72), Pair(41, 18), Pair(30, 70), Pair(-25, 41),
        Pair(13, 17), Pair(-12, 53), Pair(-45, 47), Pair(-8, 55), Pair(-2, 53), Pair(-11, 69), Pair(-24, 44), Pair(9, 30),
        Pair(0, 0), Pair(-7, 35), Pair(8, 48), Pair(-15, 42), Pair(18, 47), Pair(-16, 27), Pair(6, 51), Pair(12, 15),
        Pair(-3, 66), Pair(-41, 70), Pair(-8, 32), Pair(-7, 50), Pair(0, 18), Pair(10, 41), Pair(-27, 36), Pair(-2, 20),
        Pair(8, 42), Pair(-10, 17), Pair(-6, 43), Pair(-3, 31), Pair(4, 29), Pair(-1, 9), Pair(6, 38), Pair(-9, 18),
        Pair(-12, 32), Pair(3, 46), Pair(-9, 25), Pair(-1, 38), Pair(-10, 19), Pair(-3, 33), Pair(-5, 10), Pair(10, 18),
        Pair(8, 62), Pair(-2, 24), Pair(4, 38), Pair(-18, 30), Pair(-20, 52), Pair(-6, 15), Pair(-3, 46), Pair(-19, 5)
      },
      { // Piece 3
        Pair(45, 53), Pair(-48, 93), Pair(-22, 74), Pair(-20, 63), Pair(19, 46), Pair(-44, 74), Pair(98, 32), Pair(36, 29),
        Pair(14, 82), Pair(-17, 60), Pair(-5, 73), Pair(14, 53), Pair(-20, 67), Pair(27, 51), Pair(31, 42), Pair(-7, 64),
        Pair(49, 52), Pair(-12, 61), Pair(4, 55), Pair(0, 56), Pair(34, 55), Pair(12, 60), Pair(-11, 50), Pair(7, 42),
        Pair(0, 0), Pair(11, 57), Pair(4, 66), Pair(-7, 58), Pair(-3, 55), Pair(0, 49), Pair(-8, 45), Pair(47, 27),
        Pair(10, 40), Pair(20, 12), Pair(-3, 54), Pair(-5, 42), Pair(-9, 35), Pair(3, 53), Pair(-10, 50), Pair(-5, 57),
        Pair(-26, 47), Pair(-24, 46), Pair(3, 33), Pair(-12, 41), Pair(0, 45), Pair(15, 25), Pair(14, 41), Pair(7, 36),
        Pair(10, 20), Pair(-13, 56), Pair(-7, 37), Pair(-9, 46), Pair(15, 26), Pair(1, 24), Pair(5, 40), Pair(21, 21),
        Pair(-10, 32), Pair(-11, 42), Pair(-12, 46), Pair(-6, 41), Pair(-3, 44), Pair(-1, 33), Pair(7, 47), Pair(3, 41)
      },
      { // Piece 4
        Pair(0, 86), Pair(6, 88), Pair(50, 66), Pair(-15, 129), Pair(5, 90), Pair(67, 15), Pair(94, 35), Pair(46, 105),
        Pair(-12, 139), Pair(28, 67), Pair(0, 114), Pair(0, 112), Pair(-22, 119), Pair(8, 89), Pair(-39, 78), Pair(86, -3),
        Pair(13, 101), Pair(19, 84), Pair(2, 108), Pair(20, 69), Pair(32, 109), Pair(20, 108), Pair(74, 49), Pair(20, 97),
        Pair(0, 0), Pair(1, 105), Pair(39, 48), Pair(3, 87), Pair(21, 78), Pair(30, 88), Pair(22, 75), Pair(18, 72),
        Pair(14, 68), Pair(58, -11), Pair(6, 70), Pair(14, 59), Pair(16, 58), Pair(31, 54), Pair(40, 50), Pair(36, 44),
        Pair(-4, 86), Pair(4, 50), Pair(11, 61), Pair(11, 62), Pair(3, 72), Pair(19, 45), Pair(26, 64), Pair(5, 53),
        Pair(19, 31), Pair(12, 57), Pair(8, 54), Pair(1, 77), Pair(9, 46), Pair(6, 41), Pair(15, 83), Pair(11, 116),
        Pair(11, 114), Pair(15, 49), Pair(5, 73), Pair(8, 46), Pair(13, 43), Pair(7, 39), Pair(-17, 104), Pair(4, -79)
      },
      { // Piece 5
        Pair(-6, 48), Pair(-15, -76), Pair(-41, 59), Pair(29, -18), Pair(-36, 14), Pair(-35, 0), Pair(-49, -74), Pair(4, 28),
        Pair(23, -2), Pair(-65, -55), Pair(52, -63), Pair(141, -29), Pair(55, -1), Pair(95, -38), Pair(-74, -7), Pair(13, 6),
        Pair(-99, -9), Pair(29, 21), Pair(85, -43), Pair(-6, 0), Pair(83, -19), Pair(-27, 13), Pair(-28, -13), Pair(-39, -4),
        Pair(0, 0), Pair(153, -51), Pair(-14, 12), Pair(46, -8), Pair(19, -7), Pair(47, -8), Pair(48, -18), Pair(1, -2),
        Pair(-29, -47), Pair(26, -63), Pair(-6, 3), Pair(-36, -4), Pair(31, -5), Pair(-7, 10), Pair(10, 4), Pair(25, 3),
        Pair(-59, 5), Pair(-31, 17), Pair(-60, 6), Pair(-23, 7), Pair(27, -7), Pair(15, -8), Pair(2, -9), Pair(15, -8),
        Pair(17, -22), Pair(-18, -3), Pair(4, 19), Pair(35, -5), Pair(1, -4), Pair(6, -7), Pair(4, -1), Pair(5, -12),
        Pair(4, 20), Pair(8, 7), Pair(1, 12), Pair(-10, -4), Pair(7, -11), Pair(-14, -9), Pair(-2, -8), Pair(6, -8)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-55, 40), Pair(11, 9), Pair(-1, -5), Pair(17, 1), Pair(18, 16), Pair(25, 10), Pair(-35, 29), Pair(2, 22),
        Pair(1, -1), Pair(14, 6), Pair(0, 9), Pair(5, 15), Pair(-3, 17), Pair(-6, 13), Pair(-9, 18), Pair(-5, 14),
        Pair(-5, 9), Pair(0, 0), Pair(2, 1), Pair(-2, 5), Pair(-2, 8), Pair(-3, 3), Pair(4, 4), Pair(-1, 7),
        Pair(9, 5), Pair(0, 0), Pair(0, 14), Pair(0, 3), Pair(-3, 3), Pair(-2, 3), Pair(-4, 5), Pair(-1, 3),
        Pair(6, 1), Pair(3, 3), Pair(0, 6), Pair(1, 2), Pair(-1, 3), Pair(-4, 1), Pair(-5, 0), Pair(-3, 1),
        Pair(3, 3), Pair(9, 6), Pair(1, 5), Pair(0, -3), Pair(-3, -4), Pair(-5, -4), Pair(-5, -3), Pair(-2, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-33, 11), Pair(-10, 5), Pair(-3, 55), Pair(-50, 45), Pair(13, 0), Pair(43, 43), Pair(-62, 34), Pair(85, 72),
        Pair(-27, -8), Pair(23, 35), Pair(6, 46), Pair(43, 0), Pair(40, 24), Pair(48, 15), Pair(135, 5), Pair(53, 27),
        Pair(23, 26), Pair(2, 5), Pair(38, 29), Pair(1, 21), Pair(49, 19), Pair(71, 19), Pair(30, 16), Pair(77, 10),
        Pair(-19, 32), Pair(0, 0), Pair(6, 33), Pair(-7, 37), Pair(12, 21), Pair(18, 28), Pair(21, 26), Pair(23, 3),
        Pair(1, 14), Pair(19, 60), Pair(-26, 7), Pair(6, 27), Pair(5, 25), Pair(4, 26), Pair(33, 42), Pair(20, 35),
        Pair(-7, -23), Pair(-2, 26), Pair(-4, 10), Pair(13, 22), Pair(-5, 18), Pair(9, 19), Pair(11, 37), Pair(9, 43),
        Pair(37, 0), Pair(-25, -11), Pair(6, 39), Pair(-4, 15), Pair(13, 30), Pair(8, 3), Pair(1, 21), Pair(1, 47),
        Pair(77, 58), Pair(-8, 26), Pair(-10, 32), Pair(-13, 29), Pair(16, 26), Pair(15, 15), Pair(-8, 16), Pair(-115, -14)
      },
      { // Piece 2
        Pair(-32, 19), Pair(-18, 74), Pair(66, 29), Pair(61, 34), Pair(-12, 74), Pair(-60, 57), Pair(45, 38), Pair(61, 62),
        Pair(17, 12), Pair(-29, 37), Pair(49, 31), Pair(-70, 63), Pair(34, 49), Pair(4, 43), Pair(97, 52), Pair(33, 4),
        Pair(-64, 33), Pair(-5, 39), Pair(1, 56), Pair(-51, 58), Pair(23, 46), Pair(-46, 69), Pair(-25, 85), Pair(24, 20),
        Pair(29, 23), Pair(0, 0), Pair(15, 38), Pair(-1, 48), Pair(10, 42), Pair(-12, 55), Pair(6, 51), Pair(4, 49),
        Pair(-11, 82), Pair(16, 51), Pair(25, -44), Pair(-1, 33), Pair(5, 41), Pair(7, 36), Pair(-3, 21), Pair(14, 22),
        Pair(-19, 33), Pair(2, 32), Pair(-6, 39), Pair(12, 17), Pair(1, 28), Pair(6, 34), Pair(7, 29), Pair(14, 25),
        Pair(2, 37), Pair(5, 28), Pair(9, 36), Pair(2, 25), Pair(-3, 32), Pair(-2, 33), Pair(10, 26), Pair(12, -44),
        Pair(3, 51), Pair(16, 50), Pair(7, 22), Pair(15, 30), Pair(6, 22), Pair(3, 11), Pair(35, -14), Pair(-28, 95)
      },
      { // Piece 3
        Pair(0, 41), Pair(88, 28), Pair(-31, 53), Pair(29, 47), Pair(-10, 56), Pair(10, 40), Pair(19, 60), Pair(5, 33),
        Pair(13, 51), Pair(35, 58), Pair(-3, 52), Pair(-10, 73), Pair(-2, 53), Pair(28, 41), Pair(74, 19), Pair(-11, 51),
        Pair(22, 36), Pair(-18, 72), Pair(3, 54), Pair(23, 44), Pair(2, 59), Pair(43, 30), Pair(47, 27), Pair(20, 33),
        Pair(-10, 34), Pair(0, 0), Pair(8, 55), Pair(8, 50), Pair(-7, 56), Pair(-6, 48), Pair(10, 53), Pair(1, 45),
        Pair(-63, -26), Pair(-9, 40), Pair(-83, 54), Pair(-21, 42), Pair(1, 32), Pair(-4, 41), Pair(-43, 64), Pair(-15, 60),
        Pair(-19, 47), Pair(8, 24), Pair(-30, 36), Pair(7, 30), Pair(6, 28), Pair(0, 30), Pair(-15, 59), Pair(16, 40),
        Pair(-20, 27), Pair(-3, 3), Pair(-1, 38), Pair(-5, 35), Pair(11, 27), Pair(2, 38), Pair(-11, 53), Pair(17, 29),
        Pair(-2, 35), Pair(-6, 33), Pair(-5, 41), Pair(-2, 43), Pair(-2, 44), Pair(2, 42), Pair(9, 37), Pair(12, 41)
      },
      { // Piece 4
        Pair(37, 39), Pair(12, 69), Pair(23, 56), Pair(-37, 110), Pair(14, 121), Pair(122, 4), Pair(-27, 35), Pair(-21, 123),
        Pair(28, 63), Pair(-2, 93), Pair(44, 25), Pair(55, 33), Pair(-34, 83), Pair(4, 69), Pair(23, 46), Pair(61, 11),
        Pair(31, 5), Pair(-6, 125), Pair(-8, 74), Pair(11, 80), Pair(35, 81), Pair(20, 105), Pair(30, 75), Pair(48, 53),
        Pair(34, 31), Pair(0, 0), Pair(16, 50), Pair(28, 68), Pair(58, 59), Pair(14, 112), Pair(45, 60), Pair(24, 65),
        Pair(40, -64), Pair(34, -8), Pair(77, -15), Pair(18, 57), Pair(20, 51), Pair(24, 66), Pair(16, 45), Pair(34, 63),
        Pair(17, 26), Pair(10, 60), Pair(12, 19), Pair(8, 63), Pair(10, 40), Pair(7, 49), Pair(30, 22), Pair(16, 78),
        Pair(-2, 65), Pair(15, 51), Pair(5, 62), Pair(13, 31), Pair(14, 27), Pair(7, 63), Pair(54, -15), Pair(-8, 99),
        Pair(24, 32), Pair(22, 3), Pair(27, -3), Pair(12, 48), Pair(6, 36), Pair(19, 128), Pair(76, 2), Pair(8, 26)
      },
      { // Piece 5
        Pair(1, -12), Pair(43, -17), Pair(23, -51), Pair(41, 0), Pair(-20, 39), Pair(-40, 28), Pair(20, -49), Pair(-13, -101),
        Pair(-9, -7), Pair(-70, -44), Pair(-22, -29), Pair(41, 0), Pair(35, -17), Pair(-59, 49), Pair(-7, -28), Pair(-18, -4),
        Pair(0, 4), Pair(3, 21), Pair(101, -8), Pair(141, -6), Pair(200, -15), Pair(73, -15), Pair(128, -17), Pair(80, 0),
        Pair(18, 1), Pair(0, 0), Pair(98, -34), Pair(36, -12), Pair(113, -18), Pair(-40, 21), Pair(40, 3), Pair(-20, -6),
        Pair(-10, 13), Pair(-34, -65), Pair(7, 94), Pair(-68, -1), Pair(70, -14), Pair(53, -9), Pair(12, -4), Pair(44, -30),
        Pair(-82, 11), Pair(-96, -10), Pair(-2, -10), Pair(20, -9), Pair(-39, 12), Pair(6, 4), Pair(32, -15), Pair(55, -16),
        Pair(-49, 13), Pair(-20, 3), Pair(29, -14), Pair(5, -5), Pair(2, 4), Pair(17, -4), Pair(11, -6), Pair(14, -6),
        Pair(-15, -13), Pair(1, -2), Pair(1, -10), Pair(33, 20), Pair(-4, 5), Pair(19, -7), Pair(5, -7), Pair(8, -5)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-25, 24), Pair(20, -7), Pair(-27, -17), Pair(19, -7), Pair(13, 24), Pair(-15, 10), Pair(46, 5), Pair(22, 16),
        Pair(-2, 7), Pair(-8, 10), Pair(1, 4), Pair(4, 2), Pair(-4, 1), Pair(11, 8), Pair(-13, 12), Pair(-4, 11),
        Pair(-2, 3), Pair(1, 2), Pair(0, 0), Pair(2, 1), Pair(-4, 6), Pair(-1, 6), Pair(-2, 5), Pair(7, 3),
        Pair(1, 1), Pair(1, -14), Pair(0, 0), Pair(-5, 3), Pair(-3, 4), Pair(-5, 3), Pair(-2, 4), Pair(-2, 5),
        Pair(-1, 0), Pair(1, -6), Pair(1, 4), Pair(-2, 1), Pair(-3, 1), Pair(-11, 2), Pair(-4, 0), Pair(-2, 0),
        Pair(0, 1), Pair(-1, -9), Pair(6, 5), Pair(-9, 4), Pair(0, -6), Pair(-8, -1), Pair(-4, -3), Pair(-1, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-26, 48), Pair(23, 60), Pair(61, -28), Pair(49, 7), Pair(-65, 38), Pair(2, 107), Pair(-35, 103), Pair(-15, 59),
        Pair(15, 23), Pair(1, 27), Pair(24, 15), Pair(-30, 40), Pair(36, 37), Pair(71, 15), Pair(34, -7), Pair(-9, 51),
        Pair(8, -17), Pair(-28, 58), Pair(-11, 34), Pair(2, 42), Pair(-10, 31), Pair(-40, 74), Pair(4, 50), Pair(-4, 33),
        Pair(13, 37), Pair(-9, 24), Pair(0, 0), Pair(1, 36), Pair(2, 47), Pair(13, 29), Pair(11, 59), Pair(3, 33),
        Pair(1, 4), Pair(-73, 68), Pair(9, 79), Pair(-16, 33), Pair(2, 28), Pair(2, 29), Pair(3, 50), Pair(10, 39),
        Pair(4, 27), Pair(-16, 5), Pair(1, 36), Pair(8, 20), Pair(-1, 42), Pair(-3, 26), Pair(-2, 42), Pair(10, 33),
        Pair(5, -25), Pair(-5, 64), Pair(-9, 17), Pair(-1, 32), Pair(-2, 15), Pair(2, 42), Pair(2, 11), Pair(1, 48),
        Pair(-45, -8), Pair(6, 28), Pair(12, 15), Pair(4, 24), Pair(-11, 35), Pair(16, 11), Pair(-8, 64), Pair(-19, 96)
      },
      { // Piece 2
        Pair(41, -1), Pair(38, 9), Pair(51, 21), Pair(4, 30), Pair(25, 42), Pair(-44, 21), Pair(36, 43), Pair(115, -16),
        Pair(-109, 41), Pair(-13, 49), Pair(-30, 47), Pair(6, 54), Pair(14, 30), Pair(18, 46), Pair(-57, 14), Pair(-6, 21),
        Pair(4, 48), Pair(-8, 19), Pair(-27, 38), Pair(-35, 36), Pair(-20, 50), Pair(-38, 56), Pair(-1, 37), Pair(-2, 34),
        Pair(-2, 16), Pair(6, 38), Pair(0, 0), Pair(-2, 51), Pair(3, 31), Pair(-2, 47), Pair(-3, 31), Pair(4, 30),
        Pair(-3, 33), Pair(-12, -104), Pair(9, 74), Pair(-32, -16), Pair(2, 34), Pair(-1, 22), Pair(-5, 33), Pair(-1, 27),
        Pair(-13, -14), Pair(-12, 40), Pair(-5, 16), Pair(-1, 28), Pair(-8, 8), Pair(-3, 32), Pair(8, 19), Pair(1, 25),
        Pair(-50, -6), Pair(-6, -1), Pair(2, 40), Pair(-1, 6), Pair(1, 18), Pair(-20, 22), Pair(1, 17), Pair(17, 15),
        Pair(-4, 18), Pair(5, 39), Pair(0, 12), Pair(7, 21), Pair(3, 1), Pair(-2, 29), Pair(-41, 20), Pair(-31, 42)
      },
      { // Piece 3
        Pair(-11, 38), Pair(74, 9), Pair(89, 22), Pair(18, 27), Pair(65, 12), Pair(17, 31), Pair(19, 45), Pair(-13, 48),
        Pair(-14, 49), Pair(4, 39), Pair(-27, 68), Pair(-20, 65), Pair(6, 45), Pair(27, 33), Pair(74, 22), Pair(-38, 57),
        Pair(1, 42), Pair(-6, 32), Pair(53, 21), Pair(20, 22), Pair(15, 32), Pair(14, 41), Pair(-22, 47), Pair(-31, 48),
        Pair(-13, 36), Pair(-5, 33), Pair(0, 0), Pair(0, 31), Pair(0, 38), Pair(2, 31), Pair(20, 36), Pair(64, 7),
        Pair(-14, 41), Pair(-11, 76), Pair(3, 15), Pair(29, -26), Pair(-3, 14), Pair(-9, 38), Pair(-12, 35), Pair(-5, 31),
        Pair(-5, 25), Pair(-15, 22), Pair(-28, 36), Pair(7, 11), Pair(6, 33), Pair(-6, 29), Pair(16, 19), Pair(1, 25),
        Pair(11, 27), Pair(-6, 29), Pair(-21, 37), Pair(-5, 17), Pair(9, 19), Pair(11, 22), Pair(21, 15), Pair(46, 9),
        Pair(-7, 37), Pair(-4, 19), Pair(-9, 28), Pair(-7, 30), Pair(-4, 26), Pair(-3, 28), Pair(10, 19), Pair(8, 27)
      },
      { // Piece 4
        Pair(6, 32), Pair(-7, 63), Pair(20, 51), Pair(-27, 96), Pair(22, 51), Pair(7, 75), Pair(4, 117), Pair(35, 88),
        Pair(5, 56), Pair(-3, 58), Pair(-32, 126), Pair(24, 40), Pair(-31, 111), Pair(42, 42), Pair(28, 23), Pair(47, 41),
        Pair(14, 58), Pair(6, 52), Pair(-21, 78), Pair(46, -2), Pair(-4, 100), Pair(20, 72), Pair(52, 55), Pair(18, 57),
        Pair(-5, 67), Pair(-17, 83), Pair(0, 0), Pair(17, 10), Pair(5, 62), Pair(20, 33), Pair(30, 45), Pair(10, 69),
        Pair(11, 35), Pair(-29, 85), Pair(7, 41), Pair(51, -17), Pair(7, 52), Pair(11, 29), Pair(15, 56), Pair(17, 56),
        Pair(-18, 29), Pair(-3, 38), Pair(11, 27), Pair(-1, 46), Pair(7, 30), Pair(6, 43), Pair(17, 38), Pair(8, 75),
        Pair(-8, 117), Pair(5, 23), Pair(9, 48), Pair(0, 51), Pair(4, 35), Pair(-2, 60), Pair(11, 29), Pair(-10, -3),
        Pair(27, -4), Pair(6, 40), Pair(6, 3), Pair(8, 28), Pair(0, 49), Pair(4, 22), Pair(28, -29), Pair(-31, 25)
      },
      { // Piece 5
        Pair(-5, -34), Pair(1, -69), Pair(31, -41), Pair(-6, -3), Pair(5, -52), Pair(26, -55), Pair(21, -14), Pair(-17, -88),
        Pair(-40, -61), Pair(-25, 38), Pair(-127, 60), Pair(-49, -77), Pair(-14, -25), Pair(-3, 34), Pair(34, -5), Pair(-3, -17),
        Pair(48, -31), Pair(84, -14), Pair(10, 16), Pair(93, 9), Pair(-20, -15), Pair(-65, -21), Pair(-35, 13), Pair(-15, 1),
        Pair(-117, -53), Pair(31, -45), Pair(0, 0), Pair(27, -30), Pair(68, -23), Pair(-34, 11), Pair(26, -6), Pair(-37, 21),
        Pair(-37, -8), Pair(-38, -25), Pair(-23, -40), Pair(-29, 3), Pair(-19, 2), Pair(15, 5), Pair(51, -8), Pair(-10, -1),
        Pair(-16, 31), Pair(5, -11), Pair(33, -16), Pair(33, -18), Pair(-28, 3), Pair(-18, 14), Pair(-5, 4), Pair(4, 6),
        Pair(-34, 20), Pair(-10, -9), Pair(-4, 3), Pair(1, 1), Pair(-7, 3), Pair(11, 2), Pair(-1, 0), Pair(0, 3),
        Pair(-5, 13), Pair(-16, -1), Pair(-21, 17), Pair(16, 14), Pair(4, 10), Pair(9, 12), Pair(6, 2), Pair(9, -13)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 16), Pair(2, 4), Pair(-31, 12), Pair(-9, -18), Pair(-18, 4), Pair(61, -18), Pair(13, 21), Pair(-7, 13),
        Pair(0, 10), Pair(-8, 8), Pair(8, -9), Pair(-12, 23), Pair(10, 2), Pair(3, 12), Pair(7, 4), Pair(-9, 12),
        Pair(2, 3), Pair(2, 2), Pair(-2, 1), Pair(0, 0), Pair(5, 4), Pair(3, 0), Pair(7, -3), Pair(-2, 7),
        Pair(2, -2), Pair(0, -4), Pair(5, -4), Pair(0, 0), Pair(0, -6), Pair(-1, 1), Pair(4, -3), Pair(3, 1),
        Pair(3, -5), Pair(1, -3), Pair(1, -3), Pair(3, 5), Pair(-1, -1), Pair(-1, 2), Pair(0, -4), Pair(-1, 1),
        Pair(2, -1), Pair(0, -3), Pair(-2, -6), Pair(3, 4), Pair(-6, 2), Pair(-2, 2), Pair(2, -3), Pair(0, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-55, 68), Pair(-85, 56), Pair(-36, 32), Pair(10, 27), Pair(16, 80), Pair(-1, 38), Pair(-60, 29), Pair(33, -73),
        Pair(-20, 28), Pair(15, 26), Pair(-19, 65), Pair(-42, 35), Pair(13, 10), Pair(-65, 95), Pair(-35, 12), Pair(42, 12),
        Pair(29, 32), Pair(-18, 0), Pair(-42, 63), Pair(-17, 48), Pair(17, 46), Pair(1, 20), Pair(-21, 57), Pair(8, 37),
        Pair(-24, 25), Pair(-10, 35), Pair(-4, 31), Pair(0, 0), Pair(-5, 44), Pair(-3, 49), Pair(5, 25), Pair(2, 37),
        Pair(0, 11), Pair(2, 22), Pair(-17, 21), Pair(20, 59), Pair(-43, -9), Pair(-3, 22), Pair(-8, 36), Pair(-3, 39),
        Pair(-1, -2), Pair(-2, 33), Pair(-8, -4), Pair(0, 34), Pair(-19, 12), Pair(1, 25), Pair(-11, 19), Pair(7, 11),
        Pair(4, 0), Pair(-42, 4), Pair(0, 33), Pair(-11, 8), Pair(1, 28), Pair(-7, 9), Pair(7, 34), Pair(-4, 45),
        Pair(-10, 83), Pair(-2, 5), Pair(6, 34), Pair(-14, 10), Pair(-2, 31), Pair(10, 16), Pair(-1, 29), Pair(35, 10)
      },
      { // Piece 2
        Pair(-80, -39), Pair(-65, 55), Pair(-15, 21), Pair(-3, 43), Pair(-149, 77), Pair(12, 28), Pair(5, 108), Pair(-18, 74),
        Pair(33, 28), Pair(-75, 15), Pair(-6, 23), Pair(24, 31), Pair(-64, 69), Pair(-62, 45), Pair(18, 50), Pair(11, 28),
        Pair(-4, 29), Pair(-25, 44), Pair(-90, 44), Pair(-18, 24), Pair(-8, 21), Pair(8, 20), Pair(13, 15), Pair(22, 5),
        Pair(-3, 52), Pair(-13, 24), Pair(1, 36), Pair(0, 0), Pair(5, 38), Pair(-24, 41), Pair(-2, 48), Pair(-11, 25),
        Pair(-32, 46), Pair(4, 16), Pair(-6, -17), Pair(16, 55), Pair(-40, -58), Pair(-5, 35), Pair(5, -5), Pair(0, 47),
        Pair(-3, 27), Pair(-28, 16), Pair(-12, 21), Pair(-4, 10), Pair(-4, 14), Pair(-17, 6), Pair(0, 3), Pair(-12, 20),
        Pair(-48, 9), Pair(-3, 1), Pair(-9, 17), Pair(3, 15), Pair(-4, -7), Pair(-3, 24), Pair(-7, -8), Pair(2, 3),
        Pair(-13, 35), Pair(6, 11), Pair(0, 28), Pair(-16, 30), Pair(5, 15), Pair(-5, -3), Pair(-47, 56), Pair(-46, 5)
      },
      { // Piece 3
        Pair(-4, 32), Pair(-24, 33), Pair(-17, 34), Pair(-31, 37), Pair(-17, 30), Pair(26, 40), Pair(-34, 43), Pair(80, 23),
        Pair(10, 33), Pair(-16, 39), Pair(-25, 63), Pair(-20, 51), Pair(-30, 37), Pair(59, 19), Pair(18, 40), Pair(-22, 46),
        Pair(-13, 41), Pair(-16, 39), Pair(-8, 36), Pair(36, 24), Pair(7, 35), Pair(18, 48), Pair(59, 14), Pair(23, 18),
        Pair(-22, 45), Pair(-28, 33), Pair(-9, 34), Pair(0, 0), Pair(-7, 45), Pair(-3, 21), Pair(15, 7), Pair(7, 24),
        Pair(-13, 29), Pair(-3, 25), Pair(-11, -75), Pair(-16, 24), Pair(-37, 58), Pair(-5, 11), Pair(4, 25), Pair(-18, 40),
        Pair(-15, 21), Pair(4, 20), Pair(-4, 18), Pair(-30, 31), Pair(-10, 33), Pair(-1, 25), Pair(0, 15), Pair(-3, 39),
        Pair(13, 12), Pair(-1, 22), Pair(-10, 23), Pair(-15, 13), Pair(-2, 20), Pair(2, 22), Pair(-1, 6), Pair(4, 35),
        Pair(-4, 24), Pair(-5, 27), Pair(-6, 26), Pair(-6, 15), Pair(-2, 18), Pair(1, 23), Pair(4, 21), Pair(15, 15)
      },
      { // Piece 4
        Pair(2, 19), Pair(-54, 78), Pair(58, 29), Pair(-39, 102), Pair(-1, 95), Pair(14, 56), Pair(-41, 118), Pair(69, 47),
        Pair(27, 48), Pair(-4, 42), Pair(-44, 120), Pair(6, 74), Pair(-10, 71), Pair(-38, 126), Pair(8, 82), Pair(58, 29),
        Pair(-3, 49), Pair(3, 48), Pair(7, 23), Pair(-35, 124), Pair(-9, 83), Pair(-19, 122), Pair(17, 49), Pair(17, 58),
        Pair(4, 53), Pair(-4, 61), Pair(-8, 21), Pair(0, 0), Pair(20, 34), Pair(12, 46), Pair(2, 91), Pair(7, 67),
        Pair(5, 24), Pair(2, 44), Pair(41, -142), Pair(18, 47), Pair(25, -27), Pair(19, 42), Pair(12, 52), Pair(-2, 69),
        Pair(6, 74), Pair(7, 13), Pair(-2, 56), Pair(7, 34), Pair(-5, 62), Pair(-4, 37), Pair(-13, 78), Pair(12, 43),
        Pair(-1, 48), Pair(4, 43), Pair(5, 23), Pair(5, 39), Pair(0, 40), Pair(7, 32), Pair(11, 28), Pair(28, 33),
        Pair(13, 8), Pair(20, -4), Pair(6, 62), Pair(8, 38), Pair(11, 29), Pair(1, 6), Pair(35, 22), Pair(-34, 124)
      },
      { // Piece 5
        Pair(69, 165), Pair(-11, 15), Pair(-45, -2), Pair(-20, -101), Pair(39, 60), Pair(23, -97), Pair(-4, -27), Pair(75, -34),
        Pair(14, 90), Pair(-22, -46), Pair(43, 12), Pair(47, 20), Pair(-20, 14), Pair(-16, -46), Pair(36, -6), Pair(-27, -55),
        Pair(-10, -54), Pair(-65, 25), Pair(52, -22), Pair(54, -17), Pair(26, -11), Pair(95, -12), Pair(-14, -26), Pair(67, -2),
        Pair(39, 2), Pair(40, 25), Pair(60, -47), Pair(0, 0), Pair(68, -61), Pair(-87, 14), Pair(-62, 34), Pair(71, 10),
        Pair(54, 53), Pair(-45, 0), Pair(-17, -19), Pair(14, -47), Pair(16, 8), Pair(24, -5), Pair(-7, 14), Pair(60, 18),
        Pair(-24, 33), Pair(-80, 16), Pair(92, -30), Pair(66, -38), Pair(24, -22), Pair(4, 2), Pair(-3, 10), Pair(24, 9),
        Pair(-9, 13), Pair(-20, 16), Pair(11, 11), Pair(6, -8), Pair(8, -7), Pair(-6, 18), Pair(-3, 16), Pair(9, 6),
        Pair(-14, 29), Pair(-19, 34), Pair(-13, -2), Pair(5, -12), Pair(-4, -6), Pair(-5, 18), Pair(-1, 15), Pair(7, 6)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(18, 7), Pair(9, 11), Pair(4, 9), Pair(-3, 21), Pair(48, -21), Pair(1, 18), Pair(-47, 28), Pair(16, -3),
        Pair(3, 5), Pair(-8, 5), Pair(3, -3), Pair(-10, 3), Pair(-13, 7), Pair(10, 4), Pair(7, -1), Pair(-1, 11),
        Pair(0, 0), Pair(2, 0), Pair(5, -3), Pair(1, 2), Pair(0, 0), Pair(0, 3), Pair(-1, 7), Pair(5, 6),
        Pair(4, -5), Pair(3, -3), Pair(4, -4), Pair(0, 9), Pair(0, 0), Pair(0, -10), Pair(1, 2), Pair(-1, 3),
        Pair(1, -4), Pair(3, -2), Pair(-1, -1), Pair(1, -2), Pair(1, 1), Pair(-3, -2), Pair(-4, 2), Pair(-1, 2),
        Pair(3, -2), Pair(3, -4), Pair(0, 0), Pair(3, -3), Pair(1, 9), Pair(-5, -3), Pair(0, 5), Pair(-2, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(4, -22), Pair(-94, 93), Pair(126, -24), Pair(52, 31), Pair(-18, 69), Pair(-111, 55), Pair(-95, 50), Pair(7, -72),
        Pair(-20, 13), Pair(20, 10), Pair(39, 31), Pair(-25, 28), Pair(-38, 51), Pair(-46, 64), Pair(-49, 54), Pair(92, -3),
        Pair(15, 33), Pair(5, 32), Pair(-13, -3), Pair(-16, 43), Pair(-21, 36), Pair(1, 32), Pair(-33, 2), Pair(41, 14),
        Pair(6, 15), Pair(-13, 30), Pair(-1, 41), Pair(1, 32), Pair(0, 0), Pair(-14, 29), Pair(-9, 36), Pair(-32, 14),
        Pair(-3, 45), Pair(2, -4), Pair(1, 30), Pair(-37, 17), Pair(9, 66), Pair(-5, -8), Pair(3, 21), Pair(-4, 30),
        Pair(7, 18), Pair(-11, 24), Pair(-2, 35), Pair(-15, 17), Pair(8, 28), Pair(-6, -7), Pair(-5, 27), Pair(-14, -5),
        Pair(-11, 26), Pair(19, 31), Pair(3, 10), Pair(1, 21), Pair(-19, -8), Pair(9, 35), Pair(-10, 21), Pair(-2, 15),
        Pair(-70, -4), Pair(10, 23), Pair(6, 21), Pair(29, 14), Pair(4, 13), Pair(14, 12), Pair(-2, 14), Pair(75, -93)
      },
      { // Piece 2
        Pair(46, 23), Pair(105, 1), Pair(-50, 67), Pair(-81, 55), Pair(-55, 38), Pair(-118, 82), Pair(174, 7), Pair(32, 46),
        Pair(-46, 46), Pair(-11, 42), Pair(-16, 39), Pair(52, 37), Pair(-17, 48), Pair(47, 8), Pair(25, 11), Pair(22, 18),
        Pair(13, 20), Pair(-12, 18), Pair(-30, 46), Pair(-33, 35), Pair(7, 26), Pair(-45, 38), Pair(-26, 42), Pair(22, 1),
        Pair(2, 24), Pair(-1, 28), Pair(-24, 33), Pair(-1, 30), Pair(0, 0), Pair(-15, 53), Pair(-11, 28), Pair(12, 24),
        Pair(-12, 13), Pair(2, 20), Pair(-2, 24), Pair(15, -96), Pair(11, 67), Pair(28, -46), Pair(7, 26), Pair(-10, 18),
        Pair(-7, 24), Pair(-18, 32), Pair(-10, 3), Pair(1, 21), Pair(-6, 7), Pair(-8, 21), Pair(-18, -23), Pair(7, 19),
        Pair(-9, 42), Pair(-6, -6), Pair(-6, 37), Pair(-1, 14), Pair(4, 21), Pair(-10, 16), Pair(0, 9), Pair(-14, -42),
        Pair(-42, 17), Pair(2, 29), Pair(3, 12), Pair(10, 17), Pair(-16, 17), Pair(0, 32), Pair(-10, 8), Pair(-25, 17)
      },
      { // Piece 3
        Pair(19, 36), Pair(-55, 52), Pair(-8, 47), Pair(5, 26), Pair(-56, 35), Pair(-19, 45), Pair(-51, 34), Pair(14, 39),
        Pair(16, 23), Pair(9, 35), Pair(-3, 40), Pair(4, 25), Pair(3, 43), Pair(23, 33), Pair(71, 0), Pair(-11, 37),
        Pair(8, 21), Pair(35, 17), Pair(-7, 36), Pair(-22, 37), Pair(15, 27), Pair(5, 18), Pair(5, 51), Pair(5, 15),
        Pair(-2, 31), Pair(-9, 24), Pair(7, 21), Pair(4, 17), Pair(0, 0), Pair(7, 7), Pair(25, 13), Pair(26, 22),
        Pair(-10, 36), Pair(-2, 23), Pair(-3, 14), Pair(-55, 15), Pair(1, 19), Pair(24, -58), Pair(-12, 20), Pair(-9, 15),
        Pair(-3, 24), Pair(12, 21), Pair(12, 18), Pair(-9, 25), Pair(1, 11), Pair(-5, 15), Pair(4, 21), Pair(8, 19),
        Pair(6, 14), Pair(-7, 13), Pair(-6, 32), Pair(-3, 19), Pair(-7, 28), Pair(6, 16), Pair(11, -2), Pair(27, -4),
        Pair(3, 29), Pair(-3, 28), Pair(4, 34), Pair(-5, 27), Pair(-2, 23), Pair(0, 24), Pair(8, 12), Pair(5, 21)
      },
      { // Piece 4
        Pair(28, 27), Pair(-30, 60), Pair(-30, 111), Pair(59, -16), Pair(2, 66), Pair(24, 119), Pair(51, 40), Pair(51, 0),
        Pair(32, 2), Pair(-7, 63), Pair(27, 12), Pair(9, 79), Pair(-16, 26), Pair(11, 89), Pair(-67, 173), Pair(-8, 87),
        Pair(-5, 64), Pair(24, 15), Pair(24, 52), Pair(4, 52), Pair(-3, 76), Pair(-16, 124), Pair(0, 61), Pair(35, 12),
        Pair(12, 42), Pair(3, 78), Pair(0, 33), Pair(1, 60), Pair(0, 0), Pair(11, 63), Pair(-28, 82), Pair(20, 36),
        Pair(8, 43), Pair(-3, 93), Pair(1, 57), Pair(-19, 87), Pair(23, 19), Pair(-1, 19), Pair(-1, 68), Pair(-5, 87),
        Pair(0, 80), Pair(5, 34), Pair(4, 25), Pair(-10, 59), Pair(7, 47), Pair(14, 17), Pair(-1, 21), Pair(-9, 63),
        Pair(25, -6), Pair(-4, 60), Pair(4, 35), Pair(-1, 35), Pair(12, 39), Pair(-1, 54), Pair(8, 18), Pair(29, -10),
        Pair(8, 18), Pair(10, 57), Pair(3, 13), Pair(9, 19), Pair(18, 27), Pair(12, 0), Pair(-7, 45), Pair(65, 37)
      },
      { // Piece 5
        Pair(-69, -32), Pair(-40, 11), Pair(-41, -70), Pair(-32, 44), Pair(42, 27), Pair(20, 81), Pair(6, -33), Pair(-6, -61),
        Pair(-35, -87), Pair(-32, -29), Pair(79, -2), Pair(52, 100), Pair(22, 1), Pair(10, -17), Pair(-2, -30), Pair(89, -27),
        Pair(5, -32), Pair(-23, 46), Pair(-23, 11), Pair(39, -33), Pair(58, -20), Pair(211, -33), Pair(32, 4), Pair(-8, -12),
        Pair(-50, -4), Pair(105, 8), Pair(-104, 23), Pair(30, -35), Pair(0, 0), Pair(120, -62), Pair(-16, 3), Pair(4, 15),
        Pair(-31, -2), Pair(35, -5), Pair(-56, 22), Pair(35, -96), Pair(-53, -29), Pair(12, -15), Pair(-44, 9), Pair(-61, 21),
        Pair(57, -12), Pair(0, -7), Pair(2, -1), Pair(58, -18), Pair(64, -26), Pair(45, -17), Pair(-20, 13), Pair(20, 10),
        Pair(11, -2), Pair(-12, 15), Pair(4, 8), Pair(21, 7), Pair(29, -7), Pair(16, 4), Pair(-7, 21), Pair(3, 19),
        Pair(-21, 9), Pair(-8, 21), Pair(-2, 23), Pair(48, -21), Pair(-4, 10), Pair(12, 7), Pair(-2, 22), Pair(3, 25)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, 7), Pair(27, 4), Pair(-14, 21), Pair(-9, 18), Pair(-11, 10), Pair(-10, -1), Pair(-29, 41), Pair(14, -4),
        Pair(13, 0), Pair(10, 5), Pair(15, -4), Pair(0, 5), Pair(5, -14), Pair(9, 6), Pair(6, 1), Pair(-2, 3),
        Pair(3, 0), Pair(4, -5), Pair(-1, 2), Pair(-2, -3), Pair(-1, 2), Pair(0, 0), Pair(4, 0), Pair(3, 2),
        Pair(7, -3), Pair(1, -3), Pair(5, -2), Pair(1, -2), Pair(0, 10), Pair(0, 0), Pair(2, -7), Pair(2, -1),
        Pair(3, -3), Pair(2, -3), Pair(1, -4), Pair(0, -2), Pair(0, 1), Pair(2, 3), Pair(-5, -3), Pair(2, -1),
        Pair(3, -2), Pair(1, -1), Pair(0, -7), Pair(5, -4), Pair(-3, -2), Pair(4, 0), Pair(-1, -5), Pair(2, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(72, -31), Pair(97, -36), Pair(2, 5), Pair(-87, 63), Pair(62, -23), Pair(-75, 28), Pair(47, 1), Pair(-56, 63),
        Pair(17, 33), Pair(-12, 17), Pair(33, 23), Pair(-72, 44), Pair(56, 8), Pair(13, 19), Pair(-30, -31), Pair(19, 47),
        Pair(-40, 28), Pair(3, 16), Pair(10, 20), Pair(1, 16), Pair(11, 19), Pair(-5, 36), Pair(17, 17), Pair(-13, -21),
        Pair(9, 10), Pair(9, 26), Pair(6, 14), Pair(-2, 30), Pair(5, 35), Pair(0, 0), Pair(2, 10), Pair(-4, 2),
        Pair(5, -8), Pair(7, 15), Pair(14, 11), Pair(12, 13), Pair(-30, -27), Pair(14, 44), Pair(-13, 1), Pair(-2, 16),
        Pair(-1, 35), Pair(-8, 28), Pair(-2, 23), Pair(2, 12), Pair(0, -4), Pair(10, 23), Pair(-14, -6), Pair(0, 32),
        Pair(-12, 13), Pair(-19, 34), Pair(2, 22), Pair(-5, 18), Pair(5, 15), Pair(-6, -7), Pair(11, 25), Pair(-2, -22),
        Pair(-53, 25), Pair(3, 20), Pair(-16, 34), Pair(-9, 43), Pair(-9, 22), Pair(-10, 15), Pair(-17, 35), Pair(-8, -50)
      },
      { // Piece 2
        Pair(9, 20), Pair(58, 19), Pair(53, -17), Pair(-42, 55), Pair(-31, 60), Pair(40, 7), Pair(-55, 72), Pair(-49, 47),
        Pair(-35, 39), Pair(-31, 36), Pair(9, 27), Pair(-28, 48), Pair(-29, 28), Pair(-103, 63), Pair(17, 19), Pair(-115, 33),
        Pair(-5, 39), Pair(-7, 30), Pair(-23, 36), Pair(-28, 37), Pair(-31, 24), Pair(16, 46), Pair(-8, 8), Pair(14, 35),
        Pair(11, 23), Pair(1, 25), Pair(-12, 34), Pair(0, 17), Pair(7, 26), Pair(0, 0), Pair(-3, 27), Pair(-1, 25),
        Pair(-25, 41), Pair(13, 10), Pair(-5, 18), Pair(1, 15), Pair(-52, -12), Pair(21, 50), Pair(-53, 49), Pair(7, 18),
        Pair(12, 13), Pair(5, 21), Pair(11, 15), Pair(-2, 4), Pair(-2, 9), Pair(-5, 23), Pair(2, 10), Pair(-6, -6),
        Pair(-6, 28), Pair(7, 16), Pair(-17, 10), Pair(10, 14), Pair(1, 6), Pair(1, 22), Pair(-3, -3), Pair(-22, 57),
        Pair(-3, 26), Pair(-32, 12), Pair(-1, 22), Pair(14, -2), Pair(8, 3), Pair(-3, 17), Pair(-11, 39), Pair(-14, 51)
      },
      { // Piece 3
        Pair(-9, 28), Pair(-7, 33), Pair(-7, 36), Pair(46, 6), Pair(2, 24), Pair(-34, 47), Pair(-18, 23), Pair(-31, 37),
        Pair(1, 19), Pair(7, 13), Pair(15, 16), Pair(-25, 28), Pair(23, 20), Pair(-3, 38), Pair(78, -5), Pair(32, 13),
        Pair(6, 15), Pair(24, 17), Pair(10, 12), Pair(18, 14), Pair(-9, 18), Pair(3, 57), Pair(-9, 31), Pair(2, 30),
        Pair(0, 18), Pair(-13, 27), Pair(1, 20), Pair(0, 23), Pair(7, 18), Pair(0, 0), Pair(-5, -1), Pair(18, 22),
        Pair(3, 10), Pair(9, 19), Pair(7, 7), Pair(-29, 23), Pair(-59, 40), Pair(13, 13), Pair(-86, 31), Pair(-3, 1),
        Pair(-13, 23), Pair(10, 14), Pair(-1, 22), Pair(0, 11), Pair(-8, 7), Pair(-6, 14), Pair(6, -2), Pair(10, -25),
        Pair(2, 21), Pair(6, 8), Pair(2, 10), Pair(14, 6), Pair(-3, 8), Pair(10, 4), Pair(35, -12), Pair(-8, 11),
        Pair(4, 15), Pair(-4, 19), Pair(6, 18), Pair(3, 18), Pair(4, 9), Pair(-2, 20), Pair(-14, 26), Pair(-5, 16)
      },
      { // Piece 4
        Pair(13, 20), Pair(19, 45), Pair(52, -7), Pair(-15, 74), Pair(-26, 65), Pair(56, 40), Pair(189, -9), Pair(-2, 34),
        Pair(9, 67), Pair(-8, 29), Pair(26, 28), Pair(34, 32), Pair(-15, 68), Pair(-11, 101), Pair(-11, 51), Pair(-29, 47),
        Pair(-9, 45), Pair(-3, 72), Pair(4, 21), Pair(21, 15), Pair(13, 40), Pair(38, 28), Pair(67, -86), Pair(-25, 109),
        Pair(22, 5), Pair(11, 34), Pair(13, 32), Pair(25, 9), Pair(11, 48), Pair(0, 0), Pair(29, 27), Pair(9, 5),
        Pair(5, -4), Pair(21, 22), Pair(16, 18), Pair(17, 28), Pair(0, -37), Pair(36, 0), Pair(4, 128), Pair(1, 79),
        Pair(-13, 92), Pair(2, 24), Pair(-1, 38), Pair(-14, 52), Pair(9, -2), Pair(13, 8), Pair(11, 7), Pair(-3, -9),
        Pair(12, 34), Pair(4, 45), Pair(4, 25), Pair(-8, 56), Pair(2, 37), Pair(8, 36), Pair(5, 36), Pair(37, 25),
        Pair(-10, 44), Pair(-12, 38), Pair(11, 23), Pair(7, 22), Pair(20, -8), Pair(0, -2), Pair(20, 10), Pair(8, 24)
      },
      { // Piece 5
        Pair(81, 4), Pair(1, 14), Pair(-23, -74), Pair(10, -67), Pair(5, -36), Pair(10, -59), Pair(-56, 33), Pair(-58, -18),
        Pair(-61, -12), Pair(-26, -19), Pair(98, -28), Pair(-78, -12), Pair(2, -50), Pair(-81, 20), Pair(30, -20), Pair(-74, 16),
        Pair(1, 3), Pair(138, -4), Pair(-93, 23), Pair(114, -34), Pair(32, -7), Pair(198, -15), Pair(27, -4), Pair(54, -13),
        Pair(-43, 21), Pair(-134, 56), Pair(93, 0), Pair(-52, 21), Pair(91, -49), Pair(0, 0), Pair(153, -50), Pair(4, 21),
        Pair(122, -32), Pair(-8, 21), Pair(62, -8), Pair(-46, 5), Pair(2, -148), Pair(-33, -35), Pair(-54, -91), Pair(31, -1),
        Pair(2, -4), Pair(37, -19), Pair(52, 2), Pair(22, -3), Pair(1, -6), Pair(43, -16), Pair(1, -5), Pair(-22, 22),
        Pair(30, -23), Pair(10, -6), Pair(19, 1), Pair(4, 12), Pair(10, 2), Pair(14, 0), Pair(6, 6), Pair(-2, 13),
        Pair(0, -10), Pair(-13, 16), Pair(0, 11), Pair(-8, 25), Pair(2, 12), Pair(-6, 10), Pair(-5, 9), Pair(0, 20)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(23, 8), Pair(26, 6), Pair(-7, 22), Pair(-48, 37), Pair(-20, 5), Pair(35, 8), Pair(51, -22), Pair(-35, 14),
        Pair(7, 3), Pair(-3, 3), Pair(12, -3), Pair(0, 3), Pair(6, 3), Pair(-1, -6), Pair(15, -11), Pair(-4, 8),
        Pair(2, 0), Pair(5, -2), Pair(5, 1), Pair(-4, 5), Pair(-3, 2), Pair(-2, 7), Pair(0, 0), Pair(0, 10),
        Pair(1, -3), Pair(6, -4), Pair(2, -2), Pair(-4, 3), Pair(-3, -2), Pair(-2, 7), Pair(0, 0), Pair(3, 9),
        Pair(0, 0), Pair(2, -4), Pair(-1, -1), Pair(-2, -2), Pair(-2, -2), Pair(-2, 3), Pair(-1, 1), Pair(1, 3),
        Pair(1, -6), Pair(5, -9), Pair(-3, 1), Pair(9, -11), Pair(-1, -3), Pair(-4, 3), Pair(3, -1), Pair(-3, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-64, 8), Pair(5, 35), Pair(-94, 2), Pair(-114, 33), Pair(73, -14), Pair(-61, 18), Pair(6, 5), Pair(-67, 30),
        Pair(-13, 45), Pair(28, 21), Pair(18, 17), Pair(-37, 41), Pair(63, 1), Pair(77, -10), Pair(-79, 15), Pair(9, -21),
        Pair(-7, 4), Pair(9, 5), Pair(5, 8), Pair(33, 21), Pair(3, 7), Pair(-29, 27), Pair(-6, 3), Pair(-5, 34),
        Pair(19, 2), Pair(10, 14), Pair(21, 13), Pair(19, 8), Pair(27, 21), Pair(24, 14), Pair(0, 0), Pair(-6, 7),
        Pair(7, -1), Pair(-34, 31), Pair(13, 24), Pair(10, 13), Pair(7, 5), Pair(-1, -33), Pair(24, 64), Pair(-11, -9),
        Pair(6, 24), Pair(3, 25), Pair(5, 9), Pair(-11, 16), Pair(10, 21), Pair(-1, -3), Pair(13, 33), Pair(-12, -21),
        Pair(23, 71), Pair(-30, 23), Pair(13, 10), Pair(-3, 17), Pair(-5, 8), Pair(-10, 21), Pair(-26, -35), Pair(-9, 41),
        Pair(3, 18), Pair(2, 18), Pair(15, -1), Pair(-7, 20), Pair(19, -19), Pair(0, 22), Pair(3, -13), Pair(-56, 39)
      },
      { // Piece 2
        Pair(-46, 63), Pair(-41, -8), Pair(-63, 53), Pair(-70, 49), Pair(-45, 35), Pair(-50, 18), Pair(115, 4), Pair(46, 12),
        Pair(15, 41), Pair(29, 21), Pair(-9, 20), Pair(-79, 83), Pair(-79, 46), Pair(-43, 34), Pair(4, 35), Pair(38, -8),
        Pair(1, 21), Pair(-22, 34), Pair(3, 39), Pair(3, 21), Pair(1, 42), Pair(32, 6), Pair(-11, 19), Pair(-80, 0),
        Pair(-22, 26), Pair(19, 20), Pair(13, 35), Pair(-18, 28), Pair(10, 14), Pair(4, 29), Pair(0, 0), Pair(-12, 26),
        Pair(39, -2), Pair(-21, 22), Pair(7, 24), Pair(13, 21), Pair(-4, 12), Pair(-2, -32), Pair(22, 45), Pair(-36, -40),
        Pair(-13, 42), Pair(15, 14), Pair(0, 29), Pair(5, 7), Pair(-3, 14), Pair(-5, 16), Pair(-7, 19), Pair(-13, 4),
        Pair(16, 31), Pair(2, 28), Pair(6, 28), Pair(-17, 15), Pair(3, 17), Pair(-23, 41), Pair(11, 15), Pair(-13, -4),
        Pair(-26, 39), Pair(-21, 41), Pair(-8, 8), Pair(-10, 21), Pair(-12, 7), Pair(9, 16), Pair(-16, 9), Pair(10, 25)
      },
      { // Piece 3
        Pair(16, 19), Pair(-11, 34), Pair(-47, 49), Pair(-44, 38), Pair(-22, 40), Pair(-97, 47), Pair(58, 2), Pair(-27, 54),
        Pair(-4, 21), Pair(30, 9), Pair(35, 14), Pair(34, 15), Pair(14, 26), Pair(21, 10), Pair(87, 18), Pair(7, 21),
        Pair(14, 3), Pair(7, 15), Pair(18, 21), Pair(-16, 37), Pair(20, 2), Pair(-29, 25), Pair(65, 9), Pair(-13, 31),
        Pair(23, 16), Pair(7, 20), Pair(6, 24), Pair(32, 20), Pair(23, 22), Pair(27, -12), Pair(0, 0), Pair(-14, 8),
        Pair(-6, 18), Pair(-3, 27), Pair(4, 13), Pair(1, 14), Pair(14, 15), Pair(-9, -8), Pair(-35, 5), Pair(-58, -44),
        Pair(6, 4), Pair(13, 6), Pair(2, 11), Pair(14, 13), Pair(24, 0), Pair(-19, 29), Pair(-15, 14), Pair(-20, 19),
        Pair(-34, 43), Pair(34, -9), Pair(15, 21), Pair(-3, 28), Pair(6, 15), Pair(6, 5), Pair(10, 13), Pair(36, -29),
        Pair(11, 17), Pair(10, 13), Pair(5, 18), Pair(11, 21), Pair(11, 5), Pair(7, 14), Pair(1, 27), Pair(-5, 5)
      },
      { // Piece 4
        Pair(-1, 28), Pair(3, -21), Pair(-49, 58), Pair(18, -56), Pair(-35, 54), Pair(-13, 41), Pair(5, 6), Pair(-10, 39),
        Pair(33, -6), Pair(12, -5), Pair(1, -8), Pair(33, -19), Pair(-55, 37), Pair(56, 13), Pair(-62, 72), Pair(-18, 76),
        Pair(6, 12), Pair(-7, 32), Pair(36, -21), Pair(1, 18), Pair(-42, 101), Pair(30, -12), Pair(-33, 61), Pair(5, -48),
        Pair(15, -18), Pair(24, 9), Pair(-6, 58), Pair(-22, 59), Pair(-33, 60), Pair(12, 8), Pair(0, 0), Pair(-27, 35),
        Pair(10, 10), Pair(-29, 52), Pair(-4, 45), Pair(2, 46), Pair(34, -10), Pair(-18, 67), Pair(14, -10), Pair(-17, -15),
        Pair(1, 32), Pair(8, -6), Pair(-7, 33), Pair(2, 37), Pair(-9, 0), Pair(-4, 9), Pair(2, -8), Pair(-20, 23),
        Pair(-13, -8), Pair(-12, 15), Pair(8, -24), Pair(5, -2), Pair(7, 10), Pair(-14, 31), Pair(7, 19), Pair(1, -44),
        Pair(12, -45), Pair(-5, 16), Pair(13, -6), Pair(5, 12), Pair(7, 9), Pair(-21, 61), Pair(-38, 75), Pair(83, 28)
      },
      { // Piece 5
        Pair(0, -18), Pair(-7, 5), Pair(32, -49), Pair(51, -59), Pair(22, -16), Pair(-12, 10), Pair(-14, -35), Pair(-12, -111),
        Pair(51, 2), Pair(-33, -6), Pair(141, -77), Pair(108, -21), Pair(199, -94), Pair(107, -40), Pair(77, -7), Pair(28, -20),
        Pair(96, -37), Pair(29, -21), Pair(58, -46), Pair(-80, 3), Pair(22, 16), Pair(22, -22), Pair(145, -26), Pair(-71, -21),
        Pair(82, -13), Pair(-12, 8), Pair(-8, 4), Pair(53, -20), Pair(-55, -4), Pair(83, -37), Pair(0, 0), Pair(5, -29),
        Pair(65, -27), Pair(11, -31), Pair(43, -24), Pair(-91, 11), Pair(5, -11), Pair(-89, -20), Pair(-44, -48), Pair(-113, -82),
        Pair(-1, -11), Pair(19, -12), Pair(33, -9), Pair(24, -9), Pair(-32, 5), Pair(57, -18), Pair(2, -15), Pair(-36, -1),
        Pair(12, -3), Pair(-49, 1), Pair(-9, -5), Pair(42, -9), Pair(-9, 2), Pair(23, 3), Pair(1, 2), Pair(8, -4),
        Pair(1, -39), Pair(-7, -14), Pair(2, -4), Pair(-25, 19), Pair(-1, 19), Pair(0, 5), Pair(-3, 3), Pair(-1, -8)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(31, -4), Pair(-25, 18), Pair(34, 5), Pair(-13, 19), Pair(31, -3), Pair(9, 8), Pair(-58, 1), Pair(28, 58),
        Pair(13, 1), Pair(-9, 5), Pair(15, -1), Pair(9, 0), Pair(-1, 4), Pair(-7, 5), Pair(-15, 5), Pair(-31, -11),
        Pair(4, -2), Pair(1, 2), Pair(5, -1), Pair(-3, 0), Pair(-6, -1), Pair(-4, 2), Pair(-10, -4), Pair(0, 0),
        Pair(5, -4), Pair(2, -3), Pair(2, -4), Pair(-2, -1), Pair(1, -3), Pair(-2, 1), Pair(-3, -9), Pair(0, 0),
        Pair(1, -4), Pair(0, -6), Pair(0, -3), Pair(-2, -3), Pair(2, -4), Pair(4, -1), Pair(-3, -4), Pair(2, 2),
        Pair(1, -5), Pair(0, -5), Pair(-3, -6), Pair(1, -9), Pair(-1, -1), Pair(4, -2), Pair(0, -5), Pair(0, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-94, -19), Pair(-26, -17), Pair(-15, 11), Pair(51, -36), Pair(91, 14), Pair(37, 45), Pair(48, -29), Pair(17, 24),
        Pair(49, -31), Pair(-25, -5), Pair(-56, 24), Pair(41, -7), Pair(29, 15), Pair(41, 20), Pair(31, -30), Pair(22, 38),
        Pair(49, -16), Pair(18, -20), Pair(5, 13), Pair(54, -17), Pair(31, 10), Pair(55, -14), Pair(-41, 39), Pair(63, -16),
        Pair(35, 0), Pair(6, -3), Pair(18, 4), Pair(21, -2), Pair(28, 8), Pair(20, 26), Pair(7, 16), Pair(0, 0),
        Pair(-3, 6), Pair(10, 2), Pair(9, -1), Pair(3, 17), Pair(25, 12), Pair(35, -7), Pair(22, 3), Pair(16, 51),
        Pair(-4, 0), Pair(-5, 6), Pair(14, 6), Pair(6, 11), Pair(15, 1), Pair(8, 14), Pair(26, -1), Pair(26, 33),
        Pair(-6, -26), Pair(16, -15), Pair(-2, -10), Pair(4, 5), Pair(9, 21), Pair(1, 1), Pair(3, 12), Pair(2, -35),
        Pair(1, -98), Pair(-2, -4), Pair(7, -33), Pair(19, -10), Pair(-7, 33), Pair(-7, 15), Pair(8, 39), Pair(14, -59)
      },
      { // Piece 2
        Pair(-47, 31), Pair(63, 31), Pair(48, 41), Pair(-48, 41), Pair(-4, 51), Pair(-9, 26), Pair(-25, 32), Pair(27, -19),
        Pair(14, 7), Pair(33, 14), Pair(-14, 31), Pair(-51, 72), Pair(-74, 59), Pair(-5, 62), Pair(-43, 12), Pair(69, 39),
        Pair(-5, 33), Pair(-26, 29), Pair(-31, 52), Pair(-26, 33), Pair(49, 9), Pair(19, 28), Pair(-20, 58), Pair(29, 9),
        Pair(-24, 15), Pair(-2, 37), Pair(-3, 17), Pair(10, 24), Pair(28, 16), Pair(16, 38), Pair(-2, 24), Pair(0, 0),
        Pair(2, 12), Pair(-12, 13), Pair(-14, 34), Pair(0, 19), Pair(22, 13), Pair(11, 18), Pair(-63, -30), Pair(5, 62),
        Pair(1, 29), Pair(14, 34), Pair(8, 14), Pair(7, 23), Pair(11, 0), Pair(-3, 29), Pair(-7, 28), Pair(7, 36),
        Pair(9, 10), Pair(3, 18), Pair(-8, 17), Pair(-6, 21), Pair(-2, 27), Pair(6, 10), Pair(12, 21), Pair(5, 18),
        Pair(-3, 12), Pair(-29, 42), Pair(2, -3), Pair(-8, 35), Pair(-30, 21), Pair(4, 22), Pair(-4, 7), Pair(56, -18)
      },
      { // Piece 3
        Pair(19, 20), Pair(10, 26), Pair(-12, 28), Pair(14, 28), Pair(-5, 27), Pair(53, 20), Pair(-14, 40), Pair(34, 28),
        Pair(27, 7), Pair(6, 37), Pair(7, 29), Pair(31, 9), Pair(23, 18), Pair(-4, 18), Pair(74, 8), Pair(65, 22),
        Pair(11, 19), Pair(-6, 23), Pair(27, 23), Pair(-5, 27), Pair(-12, 24), Pair(-5, 30), Pair(41, 11), Pair(63, 24),
        Pair(20, 24), Pair(11, 23), Pair(27, 12), Pair(11, 20), Pair(21, 17), Pair(-16, 46), Pair(19, 18), Pair(0, 0),
        Pair(2, 25), Pair(9, 20), Pair(12, 11), Pair(-6, 12), Pair(14, 8), Pair(-9, 22), Pair(56, -45), Pair(-9, 37),
        Pair(0, 12), Pair(21, 20), Pair(26, 11), Pair(19, 11), Pair(5, 11), Pair(-3, 32), Pair(1, 22), Pair(-19, 0),
        Pair(17, -3), Pair(7, 22), Pair(5, 11), Pair(-2, 32), Pair(9, 27), Pair(11, 2), Pair(39, -11), Pair(-20, 16),
        Pair(4, 28), Pair(-3, 35), Pair(6, 26), Pair(0, 26), Pair(1, 27), Pair(6, 23), Pair(-1, 29), Pair(-14, 26)
      },
      { // Piece 4
        Pair(28, 25), Pair(23, 36), Pair(53, -16), Pair(-4, -16), Pair(7, 12), Pair(5, 59), Pair(6, 45), Pair(62, -21),
        Pair(18, 7), Pair(2, 42), Pair(22, -2), Pair(-25, 34), Pair(17, 22), Pair(-56, 90), Pair(5, -6), Pair(63, 41),
        Pair(15, 34), Pair(-11, 32), Pair(12, -1), Pair(23, 1), Pair(5, 27), Pair(53, 8), Pair(-27, 57), Pair(11, 27),
        Pair(-13, 16), Pair(11, 2), Pair(3, 12), Pair(1, 39), Pair(4, 39), Pair(-7, 41), Pair(-8, 44), Pair(0, 0),
        Pair(1, 8), Pair(-2, 12), Pair(-9, 23), Pair(16, 33), Pair(7, 24), Pair(7, 20), Pair(6, -55), Pair(5, 30),
        Pair(-13, 62), Pair(5, -2), Pair(16, 1), Pair(2, 30), Pair(15, -8), Pair(-7, 47), Pair(-10, 14), Pair(-11, 3),
        Pair(-18, 70), Pair(4, 19), Pair(1, 11), Pair(2, 2), Pair(8, 14), Pair(20, -25), Pair(10, -17), Pair(-11, 74),
        Pair(-1, 1), Pair(14, -1), Pair(2, 9), Pair(4, 8), Pair(16, -5), Pair(-23, 78), Pair(-4, 16), Pair(5, 43)
      },
      { // Piece 5
        Pair(-35, -86), Pair(6, -64), Pair(150, 12), Pair(-71, -16), Pair(13, -10), Pair(45, -44), Pair(-40, -23), Pair(31, 96),
        Pair(-13, -9), Pair(-8, -33), Pair(35, -11), Pair(-48, -28), Pair(-50, -66), Pair(45, -39), Pair(-29, -31), Pair(5, 1),
        Pair(13, -22), Pair(115, -13), Pair(80, -22), Pair(72, -28), Pair(48, -7), Pair(106, -37), Pair(-34, 16), Pair(51, -19),
        Pair(87, -48), Pair(43, -18), Pair(43, -19), Pair(68, -19), Pair(30, -14), Pair(-83, 4), Pair(33, -41), Pair(0, 0),
        Pair(2, -19), Pair(105, -21), Pair(41, -16), Pair(35, -8), Pair(-16, 6), Pair(-2, 1), Pair(-145, 14), Pair(119, -60),
        Pair(-4, -12), Pair(53, -32), Pair(59, -25), Pair(51, -14), Pair(44, -10), Pair(-20, 3), Pair(20, 4), Pair(-26, 11),
        Pair(-3, -15), Pair(28, -27), Pair(25, -23), Pair(-26, 4), Pair(3, 5), Pair(-16, 16), Pair(-8, 10), Pair(-8, 6),
        Pair(-7, -24), Pair(-5, -23), Pair(-12, -8), Pair(6, 0), Pair(-5, 13), Pair(-18, 19), Pair(1, 3), Pair(-5, -5)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(80, -36), Pair(-26, 12), Pair(-51, 16), Pair(6, 0), Pair(39, -4), Pair(17, 4), Pair(27, -8), Pair(-24, 21),
        Pair(0, 0), Pair(-8, -2), Pair(10, -2), Pair(6, 2), Pair(-3, 13), Pair(-7, 8), Pair(4, 22), Pair(-6, 11),
        Pair(-10, -10), Pair(-5, -5), Pair(-1, -3), Pair(4, 4), Pair(0, 4), Pair(-7, 11), Pair(-1, 3), Pair(0, 5),
        Pair(-4, -6), Pair(-5, -2), Pair(0, -2), Pair(-3, 3), Pair(-3, 3), Pair(-3, 3), Pair(1, 1), Pair(1, 5),
        Pair(0, 0), Pair(-4, -2), Pair(2, -1), Pair(0, -2), Pair(-2, 2), Pair(-3, 0), Pair(-5, -1), Pair(0, -1),
        Pair(4, -4), Pair(-3, -4), Pair(0, -3), Pair(1, -7), Pair(-2, 1), Pair(-4, -4), Pair(-2, -2), Pair(-1, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-73, 16), Pair(93, 13), Pair(-37, 34), Pair(78, -5), Pair(-76, 42), Pair(-24, 4), Pair(105, 15), Pair(14, 22),
        Pair(9, -23), Pair(-5, 33), Pair(14, 21), Pair(21, 27), Pair(39, -10), Pair(9, -8), Pair(42, -14), Pair(7, 1),
        Pair(0, 0), Pair(14, 11), Pair(0, 22), Pair(12, 13), Pair(6, 20), Pair(57, -7), Pair(64, -16), Pair(20, 49),
        Pair(22, 54), Pair(-11, -26), Pair(8, 15), Pair(6, 18), Pair(15, 9), Pair(33, 3), Pair(26, 8), Pair(29, 0),
        Pair(1, 14), Pair(-11, 22), Pair(2, 15), Pair(3, 22), Pair(14, 17), Pair(8, 15), Pair(0, 14), Pair(10, 21),
        Pair(-16, -13), Pair(3, 24), Pair(-11, 30), Pair(15, 9), Pair(3, 2), Pair(3, 14), Pair(4, 21), Pair(17, 20),
        Pair(-12, 35), Pair(26, -6), Pair(11, -5), Pair(2, 15), Pair(-2, 16), Pair(18, -13), Pair(-1, -18), Pair(-17, 39),
        Pair(-21, 54), Pair(4, 20), Pair(3, -11), Pair(24, 1), Pair(-1, 23), Pair(0, 25), Pair(-3, -3), Pair(-3, 24)
      },
      { // Piece 2
        Pair(21, -12), Pair(-12, 61), Pair(26, 58), Pair(-10, 53), Pair(13, 1), Pair(-70, 74), Pair(36, 38), Pair(-47, 6),
        Pair(-2, 42), Pair(-17, 61), Pair(-26, 47), Pair(-3, 42), Pair(-1, 45), Pair(-34, 74), Pair(21, 39), Pair(-5, 47),
        Pair(0, 0), Pair(5, 29), Pair(-1, 59), Pair(7, 50), Pair(-11, 62), Pair(6, 49), Pair(-10, 33), Pair(6, 18),
        Pair(21, 56), Pair(-17, 32), Pair(16, 27), Pair(2, 53), Pair(10, 31), Pair(-4, 46), Pair(10, 33), Pair(9, 16),
        Pair(-9, 46), Pair(-30, 33), Pair(-3, 38), Pair(-7, 38), Pair(-1, 35), Pair(16, 25), Pair(-13, 42), Pair(15, 31),
        Pair(0, 45), Pair(3, 35), Pair(-4, 35), Pair(4, 21), Pair(5, 22), Pair(5, 23), Pair(7, 19), Pair(11, 25),
        Pair(4, 32), Pair(2, 35), Pair(-2, 33), Pair(5, 31), Pair(0, 20), Pair(-1, 10), Pair(10, 14), Pair(11, 16),
        Pair(15, 27), Pair(18, 46), Pair(5, 35), Pair(-10, 27), Pair(-16, 28), Pair(1, 26), Pair(4, 49), Pair(17, 23)
      },
      { // Piece 3
        Pair(14, 67), Pair(-46, 86), Pair(7, 42), Pair(2, 53), Pair(-4, 49), Pair(-47, 67), Pair(51, 72), Pair(28, 48),
        Pair(32, 48), Pair(-5, 48), Pair(-6, 70), Pair(-3, 63), Pair(22, 41), Pair(32, 49), Pair(38, 28), Pair(-11, 76),
        Pair(0, 0), Pair(1, 58), Pair(0, 61), Pair(11, 51), Pair(13, 61), Pair(-10, 61), Pair(6, 61), Pair(-36, 56),
        Pair(10, 46), Pair(82, -190), Pair(1, 42), Pair(-1, 68), Pair(-7, 70), Pair(-14, 59), Pair(3, 49), Pair(-3, 41),
        Pair(7, 33), Pair(-25, 56), Pair(-24, 52), Pair(-1, 36), Pair(-6, 48), Pair(7, 41), Pair(2, 30), Pair(18, 43),
        Pair(-20, 29), Pair(-8, 50), Pair(2, 34), Pair(-20, 47), Pair(-12, 53), Pair(3, 25), Pair(10, 47), Pair(-1, 36),
        Pair(-7, 41), Pair(-6, 63), Pair(4, 33), Pair(-6, 30), Pair(5, 34), Pair(8, 25), Pair(-2, 36), Pair(14, 38),
        Pair(-5, 33), Pair(-8, 40), Pair(-2, 34), Pair(-2, 46), Pair(-1, 43), Pair(2, 37), Pair(11, 50), Pair(7, 49)
      },
      { // Piece 4
        Pair(-3, 109), Pair(-20, 120), Pair(-17, 116), Pair(-42, 138), Pair(15, 110), Pair(-93, 145), Pair(8, 3), Pair(112, 21),
        Pair(11, 85), Pair(21, 104), Pair(10, 85), Pair(-32, 86), Pair(14, 122), Pair(-16, 52), Pair(-5, 20), Pair(58, 89),
        Pair(0, 0), Pair(20, 91), Pair(-11, 137), Pair(9, 125), Pair(30, 110), Pair(23, 33), Pair(34, 54), Pair(48, 30),
        Pair(22, 61), Pair(66, 45), Pair(42, 43), Pair(-14, 108), Pair(10, 89), Pair(19, 81), Pair(16, 72), Pair(25, 72),
        Pair(16, 23), Pair(10, 40), Pair(2, 81), Pair(18, 74), Pair(23, 61), Pair(22, 72), Pair(28, 41), Pair(46, 61),
        Pair(2, 80), Pair(3, 46), Pair(9, 53), Pair(10, 56), Pair(9, 59), Pair(8, 88), Pair(11, 78), Pair(18, 58),
        Pair(1, 49), Pair(6, 50), Pair(5, 50), Pair(5, 60), Pair(13, 49), Pair(2, 35), Pair(10, 71), Pair(34, 9),
        Pair(14, 75), Pair(13, 54), Pair(4, 81), Pair(6, 50), Pair(10, 57), Pair(26, 37), Pair(3, 79), Pair(-25, 49)
      },
      { // Piece 5
        Pair(-10, 38), Pair(44, 160), Pair(82, -7), Pair(74, 0), Pair(-10, -20), Pair(47, -18), Pair(30, 31), Pair(-24, -44),
        Pair(-43, -71), Pair(-56, -32), Pair(87, -31), Pair(35, -46), Pair(4, 65), Pair(-36, -23), Pair(-60, -22), Pair(-63, 53),
        Pair(0, 0), Pair(-76, -34), Pair(-9, -2), Pair(64, -7), Pair(27, -12), Pair(29, 3), Pair(-59, 17), Pair(-51, 6),
        Pair(-22, -60), Pair(-31, -31), Pair(-114, 15), Pair(39, 4), Pair(14, -8), Pair(61, 2), Pair(-28, 11), Pair(21, -10),
        Pair(49, -29), Pair(-37, -21), Pair(-5, -24), Pair(37, -5), Pair(18, 7), Pair(-2, 13), Pair(92, -17), Pair(22, 5),
        Pair(1, -14), Pair(-12, -2), Pair(-10, 3), Pair(-21, 1), Pair(5, 0), Pair(36, -5), Pair(-11, 13), Pair(-20, 14),
        Pair(-10, -2), Pair(-16, 9), Pair(-7, 10), Pair(-1, 13), Pair(14, 2), Pair(11, -3), Pair(-1, 2), Pair(-2, 13),
        Pair(29, 4), Pair(9, 10), Pair(12, 17), Pair(12, -18), Pair(0, 6), Pair(-23, 11), Pair(-2, -2), Pair(-5, 5)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 37), Pair(-20, 16), Pair(7, 2), Pair(18, -6), Pair(29, 10), Pair(55, -19), Pair(4, 21), Pair(-23, 25),
        Pair(3, 7), Pair(0, 0), Pair(9, -9), Pair(1, 3), Pair(-2, 6), Pair(2, 5), Pair(-4, 19), Pair(-3, 16),
        Pair(6, 0), Pair(-9, -12), Pair(-10, 20), Pair(2, 2), Pair(3, 6), Pair(0, 4), Pair(-4, 11), Pair(-1, 7),
        Pair(4, 1), Pair(-2, -3), Pair(-1, 7), Pair(1, 4), Pair(-2, 3), Pair(-2, 6), Pair(-2, 3), Pair(-1, 6),
        Pair(1, 1), Pair(0, 0), Pair(2, 5), Pair(-1, 0), Pair(-1, -1), Pair(-4, 0), Pair(-4, 1), Pair(-3, 3),
        Pair(-1, -1), Pair(5, -1), Pair(0, 2), Pair(1, 2), Pair(0, -1), Pair(-6, -1), Pair(-4, -2), Pair(-1, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-58, 5), Pair(43, -4), Pair(-13, 18), Pair(16, 23), Pair(-15, 42), Pair(26, 22), Pair(108, -6), Pair(-56, -2),
        Pair(-5, 25), Pair(-22, -72), Pair(-18, 46), Pair(62, -16), Pair(10, 19), Pair(3, 40), Pair(-44, 26), Pair(-12, -4),
        Pair(-11, -23), Pair(0, 0), Pair(2, 18), Pair(0, 23), Pair(24, 12), Pair(44, 24), Pair(17, 5), Pair(8, 30),
        Pair(22, 24), Pair(0, 55), Pair(-53, 20), Pair(-1, 15), Pair(7, 18), Pair(16, 41), Pair(9, 24), Pair(10, 13),
        Pair(-13, -16), Pair(-8, 33), Pair(-17, 19), Pair(0, 32), Pair(4, 15), Pair(-1, 23), Pair(18, 14), Pair(17, 27),
        Pair(8, 8), Pair(-22, -3), Pair(-2, 28), Pair(-14, 25), Pair(1, 14), Pair(4, 23), Pair(9, 23), Pair(10, 4),
        Pair(5, -8), Pair(-4, 20), Pair(9, 8), Pair(2, 13), Pair(8, 23), Pair(16, 8), Pair(-3, 31), Pair(16, 15),
        Pair(23, -48), Pair(7, 18), Pair(9, 3), Pair(-11, 21), Pair(3, 29), Pair(23, 19), Pair(-2, 36), Pair(-15, 75)
      },
      { // Piece 2
        Pair(2, 23), Pair(-34, 59), Pair(-137, 46), Pair(-11, 52), Pair(-141, 71), Pair(-101, 83), Pair(-40, 60), Pair(87, 57),
        Pair(-122, -2), Pair(-38, 57), Pair(-1, 18), Pair(-36, 73), Pair(-33, 55), Pair(46, 26), Pair(-6, 26), Pair(21, 53),
        Pair(20, 42), Pair(0, 0), Pair(1, 35), Pair(-24, 48), Pair(-4, 46), Pair(-11, 64), Pair(23, 35), Pair(17, 20),
        Pair(17, -41), Pair(3, 68), Pair(-97, -10), Pair(-14, 56), Pair(-10, 49), Pair(5, 48), Pair(8, 31), Pair(10, 36),
        Pair(-10, 28), Pair(-18, 30), Pair(-17, 37), Pair(-20, 34), Pair(5, 24), Pair(2, 24), Pair(5, 27), Pair(26, 18),
        Pair(-3, 12), Pair(1, 26), Pair(-7, 32), Pair(0, 39), Pair(-5, 20), Pair(-1, 29), Pair(12, 33), Pair(13, 20),
        Pair(4, 15), Pair(6, 19), Pair(-1, 33), Pair(0, 19), Pair(0, 26), Pair(-7, 11), Pair(7, 21), Pair(5, 8),
        Pair(-12, 46), Pair(8, 45), Pair(1, 24), Pair(0, 40), Pair(-14, 34), Pair(6, 26), Pair(-21, -12), Pair(12, 26)
      },
      { // Piece 3
        Pair(-26, 55), Pair(-90, 60), Pair(6, 36), Pair(-14, 64), Pair(22, 40), Pair(-46, 71), Pair(-54, 86), Pair(80, 23),
        Pair(1, 49), Pair(-7, 51), Pair(-14, 56), Pair(-9, 53), Pair(5, 61), Pair(56, 36), Pair(-4, 60), Pair(-6, 46),
        Pair(-38, 52), Pair(0, 0), Pair(5, 47), Pair(-6, 52), Pair(-4, 44), Pair(-8, 50), Pair(52, 22), Pair(52, 7),
        Pair(46, -15), Pair(-6, 25), Pair(-70, 42), Pair(-29, 55), Pair(-7, 36), Pair(11, 21), Pair(8, 29), Pair(6, 36),
        Pair(-7, 8), Pair(-14, 30), Pair(-19, 38), Pair(-27, 47), Pair(-1, 34), Pair(-2, 45), Pair(2, 39), Pair(29, 44),
        Pair(-17, 44), Pair(-4, 36), Pair(-32, 47), Pair(-9, 37), Pair(-7, 33), Pair(-7, 40), Pair(3, 38), Pair(8, 43),
        Pair(23, 11), Pair(-12, 25), Pair(-4, 41), Pair(8, 20), Pair(-1, 32), Pair(1, 49), Pair(-19, 51), Pair(12, 29),
        Pair(-7, 35), Pair(-7, 23), Pair(-8, 30), Pair(-4, 37), Pair(-1, 33), Pair(2, 34), Pair(7, 44), Pair(9, 46)
      },
      { // Piece 4
        Pair(48, 47), Pair(23, 79), Pair(-9, 65), Pair(48, 18), Pair(-29, 126), Pair(55, 64), Pair(-108, 117), Pair(56, 44),
        Pair(9, 64), Pair(34, 69), Pair(21, 47), Pair(39, 61), Pair(14, 59), Pair(69, 30), Pair(-5, 59), Pair(-29, 118),
        Pair(18, 10), Pair(0, 0), Pair(9, 79), Pair(44, 29), Pair(56, 15), Pair(24, 49), Pair(-24, 58), Pair(37, 45),
        Pair(-15, 220), Pair(5, 74), Pair(22, 151), Pair(33, 33), Pair(35, 34), Pair(21, 69), Pair(48, 48), Pair(29, 29),
        Pair(5, 29), Pair(-7, 40), Pair(20, 42), Pair(0, 73), Pair(1, 76), Pair(21, 68), Pair(24, 56), Pair(37, 58),
        Pair(13, 51), Pair(6, 68), Pair(10, 35), Pair(6, 39), Pair(18, 36), Pair(11, 44), Pair(22, 32), Pair(12, 74),
        Pair(10, 51), Pair(11, 47), Pair(7, 34), Pair(11, 35), Pair(6, 58), Pair(6, 64), Pair(20, 61), Pair(-31, 94),
        Pair(8, 70), Pair(6, 87), Pair(19, 29), Pair(10, 58), Pair(17, 57), Pair(29, 29), Pair(5, -10), Pair(19, 63)
      },
      { // Piece 5
        Pair(-40, -237), Pair(-56, -87), Pair(-21, 34), Pair(-23, -68), Pair(82, 100), Pair(58, 26), Pair(-4, 49), Pair(20, -10),
        Pair(11, 47), Pair(16, -22), Pair(4, -30), Pair(97, 18), Pair(-145, 8), Pair(-90, -21), Pair(8, -3), Pair(-57, 53),
        Pair(-135, 0), Pair(0, 0), Pair(19, -42), Pair(80, -22), Pair(-12, 33), Pair(50, -18), Pair(3, 1), Pair(11, 0),
        Pair(0, 0), Pair(26, -82), Pair(0, 29), Pair(-33, -4), Pair(-32, 3), Pair(63, 0), Pair(14, -6), Pair(61, -20),
        Pair(86, -101), Pair(-37, -48), Pair(120, -31), Pair(-23, -8), Pair(-16, -11), Pair(47, -7), Pair(37, -4), Pair(-31, 11),
        Pair(52, -25), Pair(56, -48), Pair(-12, -10), Pair(32, -9), Pair(15, -5), Pair(3, 3), Pair(10, -5), Pair(32, -9),
        Pair(-12, 3), Pair(22, -31), Pair(15, -17), Pair(-28, 17), Pair(0, 9), Pair(10, -2), Pair(5, -1), Pair(1, 2),
        Pair(46, -68), Pair(16, -11), Pair(26, -6), Pair(2, 4), Pair(-1, 9), Pair(23, -9), Pair(1, 0), Pair(-4, -1)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, 39), Pair(4, 11), Pair(-14, 75), Pair(3, -26), Pair(33, 11), Pair(40, -17), Pair(22, 4), Pair(11, 9),
        Pair(-3, 10), Pair(-18, 5), Pair(0, 0), Pair(15, -12), Pair(0, 9), Pair(7, 7), Pair(22, 11), Pair(-17, 11),
        Pair(-4, 2), Pair(-4, 6), Pair(-11, -11), Pair(0, 35), Pair(-2, 3), Pair(1, 2), Pair(1, 4), Pair(0, 7),
        Pair(-2, 2), Pair(1, -6), Pair(-2, -5), Pair(1, 4), Pair(1, 2), Pair(0, 4), Pair(2, 2), Pair(-1, 3),
        Pair(-2, 2), Pair(-1, -4), Pair(0, 0), Pair(2, 4), Pair(-1, 2), Pair(-5, 3), Pair(-1, 1), Pair(-1, 2),
        Pair(0, 1), Pair(-5, -6), Pair(2, 2), Pair(-4, 2), Pair(3, -2), Pair(-5, -1), Pair(1, 1), Pair(0, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(4, 38), Pair(66, 16), Pair(79, -41), Pair(-29, 26), Pair(-13, -25), Pair(229, -30), Pair(29, 31), Pair(-71, -34),
        Pair(-59, -44), Pair(-3, 37), Pair(-16, 12), Pair(47, 30), Pair(92, -60), Pair(-4, 39), Pair(31, 10), Pair(8, 14),
        Pair(-16, 16), Pair(-17, 25), Pair(0, 0), Pair(-2, 39), Pair(-8, 31), Pair(-26, 36), Pair(48, -10), Pair(5, -5),
        Pair(-12, 26), Pair(24, 26), Pair(7, 55), Pair(-32, -13), Pair(8, 21), Pair(14, 19), Pair(16, 38), Pair(6, 18),
        Pair(13, 13), Pair(-16, 19), Pair(-5, 36), Pair(-16, 28), Pair(13, 29), Pair(0, 11), Pair(-8, 29), Pair(9, 37),
        Pair(-7, -11), Pair(-4, 32), Pair(-13, 12), Pair(11, 25), Pair(-14, 18), Pair(6, 24), Pair(1, 24), Pair(4, 49),
        Pair(-7, 52), Pair(16, 20), Pair(1, 31), Pair(3, 27), Pair(1, 20), Pair(9, -2), Pair(9, 36), Pair(12, 18),
        Pair(-2, 5), Pair(4, 24), Pair(5, 10), Pair(8, 13), Pair(4, 13), Pair(11, 25), Pair(11, 54), Pair(-8, -4)
      },
      { // Piece 2
        Pair(-114, -37), Pair(-75, 32), Pair(49, 50), Pair(-56, 69), Pair(5, 18), Pair(20, 72), Pair(39, 6), Pair(23, 44),
        Pair(-2, 34), Pair(-123, 4), Pair(-20, 34), Pair(-11, 14), Pair(60, 27), Pair(14, 61), Pair(-8, 36), Pair(15, -24),
        Pair(7, 12), Pair(6, 32), Pair(0, 0), Pair(-6, 32), Pair(-28, 50), Pair(25, 34), Pair(11, 40), Pair(7, 34),
        Pair(15, 18), Pair(-20, 43), Pair(30, 47), Pair(38, -76), Pair(2, 20), Pair(0, 29), Pair(9, 35), Pair(-4, 16),
        Pair(1, -22), Pair(-17, 35), Pair(-16, 18), Pair(-21, 27), Pair(-2, 19), Pair(3, 34), Pair(-19, 39), Pair(4, 53),
        Pair(2, 29), Pair(-4, 14), Pair(2, 31), Pair(1, 13), Pair(2, 32), Pair(-7, 11), Pair(15, 10), Pair(0, 21),
        Pair(-28, 22), Pair(11, 10), Pair(-2, 22), Pair(11, 23), Pair(1, 4), Pair(16, 15), Pair(-1, -8), Pair(11, 24),
        Pair(10, 50), Pair(44, -14), Pair(12, 33), Pair(5, 19), Pair(-7, 39), Pair(-2, 12), Pair(-18, 20), Pair(-17, -5)
      },
      { // Piece 3
        Pair(5, 8), Pair(39, 6), Pair(103, -14), Pair(2, 38), Pair(85, -1), Pair(5, 27), Pair(-40, 54), Pair(-77, 54),
        Pair(-21, 43), Pair(6, 18), Pair(3, 25), Pair(-17, 40), Pair(47, 24), Pair(49, 1), Pair(16, 33), Pair(-27, 35),
        Pair(-2, 30), Pair(-1, 19), Pair(0, 0), Pair(22, 11), Pair(21, 30), Pair(28, 24), Pair(-17, 47), Pair(-56, 39),
        Pair(5, 10), Pair(35, -42), Pair(12, 18), Pair(36, -62), Pair(-13, 43), Pair(-16, 26), Pair(13, 6), Pair(-11, 23),
        Pair(12, 3), Pair(-5, 20), Pair(7, 5), Pair(-13, 11), Pair(-11, 23), Pair(-5, 40), Pair(-12, 31), Pair(23, 34),
        Pair(9, 5), Pair(-9, 8), Pair(-16, 25), Pair(-10, 22), Pair(-7, 25), Pair(-3, 25), Pair(-9, 11), Pair(-4, 39),
        Pair(5, 20), Pair(8, 4), Pair(-23, 31), Pair(-6, 27), Pair(2, 29), Pair(6, 21), Pair(-14, 34), Pair(13, -9),
        Pair(1, 19), Pair(-5, 19), Pair(-1, 11), Pair(-5, 19), Pair(4, 26), Pair(0, 24), Pair(6, 17), Pair(9, 26)
      },
      { // Piece 4
        Pair(-19, 74), Pair(36, 47), Pair(98, -54), Pair(-45, 85), Pair(50, 51), Pair(21, 34), Pair(77, 33), Pair(45, 26),
        Pair(-11, 107), Pair(-7, 51), Pair(10, 49), Pair(36, 5), Pair(-6, 82), Pair(13, 68), Pair(54, 59), Pair(-16, 99),
        Pair(8, 25), Pair(40, 30), Pair(0, 0), Pair(16, 12), Pair(-10, 102), Pair(38, 25), Pair(38, 48), Pair(32, 40),
        Pair(9, 40), Pair(-38, 112), Pair(43, 16), Pair(-58, 144), Pair(43, 0), Pair(10, 66), Pair(45, 6), Pair(15, 44),
        Pair(31, -17), Pair(8, 58), Pair(14, 59), Pair(3, 60), Pair(18, 4), Pair(22, 33), Pair(13, 60), Pair(23, 68),
        Pair(-1, 65), Pair(0, 48), Pair(21, 29), Pair(8, 45), Pair(18, 5), Pair(9, 26), Pair(27, 8), Pair(23, 23),
        Pair(-16, 70), Pair(4, 50), Pair(15, 46), Pair(8, 34), Pair(5, 53), Pair(13, 31), Pair(5, 8), Pair(-36, 143),
        Pair(5, 46), Pair(7, 62), Pair(13, 36), Pair(9, 42), Pair(8, 53), Pair(17, 30), Pair(7, -16), Pair(11, 19)
      },
      { // Piece 5
        Pair(3, 39), Pair(14, 54), Pair(-84, -30), Pair(-2, -61), Pair(47, 48), Pair(43, 45), Pair(-7, -19), Pair(24, -32),
        Pair(-25, -78), Pair(-45, -97), Pair(72, -34), Pair(81, -60), Pair(-18, 41), Pair(50, -18), Pair(-56, -44), Pair(-29, 41),
        Pair(-67, -68), Pair(-61, -31), Pair(0, 0), Pair(219, -74), Pair(61, 22), Pair(-12, 17), Pair(-145, 17), Pair(-17, 28),
        Pair(-52, -4), Pair(0, 0), Pair(38, -68), Pair(0, 0), Pair(-168, 17), Pair(-4, 12), Pair(26, 17), Pair(37, 11),
        Pair(-73, -4), Pair(32, -37), Pair(31, -44), Pair(66, -37), Pair(-73, 14), Pair(14, 17), Pair(21, 1), Pair(-29, 23),
        Pair(85, 5), Pair(-26, -24), Pair(-36, 3), Pair(21, -9), Pair(20, -2), Pair(-7, 10), Pair(-25, 16), Pair(57, -12),
        Pair(-23, 26), Pair(21, -24), Pair(-2, -6), Pair(-10, 3), Pair(9, 5), Pair(11, 11), Pair(-3, 9), Pair(0, 8),
        Pair(17, 6), Pair(-9, -8), Pair(-9, 14), Pair(17, 12), Pair(3, 3), Pair(5, 5), Pair(2, 4), Pair(9, 10)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 9), Pair(31, 4), Pair(-1, 8), Pair(35, -33), Pair(-68, 62), Pair(-3, 15), Pair(-24, 30), Pair(-4, 20),
        Pair(1, 9), Pair(-5, 8), Pair(-8, 2), Pair(0, 0), Pair(0, 1), Pair(7, -3), Pair(15, -10), Pair(-8, 22),
        Pair(-3, 6), Pair(-4, 3), Pair(-9, 1), Pair(-11, -12), Pair(-9, 18), Pair(-3, 3), Pair(3, 3), Pair(3, 4),
        Pair(1, 4), Pair(-1, -2), Pair(2, -2), Pair(-6, -6), Pair(-2, 3), Pair(1, 2), Pair(3, 2), Pair(1, 3),
        Pair(-1, 1), Pair(0, -1), Pair(-2, -4), Pair(0, 0), Pair(-1, -2), Pair(-3, 1), Pair(-1, 2), Pair(0, 4),
        Pair(0, 0), Pair(-1, 0), Pair(-3, -3), Pair(0, -2), Pair(1, -5), Pair(1, 0), Pair(1, -1), Pair(-1, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-87, 51), Pair(-8, 33), Pair(-32, 28), Pair(-71, 34), Pair(-38, 32), Pair(54, 55), Pair(-71, 95), Pair(21, 49),
        Pair(-5, 44), Pair(-7, -28), Pair(2, 5), Pair(64, -52), Pair(-59, 45), Pair(26, 28), Pair(21, -13), Pair(60, 17),
        Pair(54, -8), Pair(10, 11), Pair(-25, 35), Pair(0, 0), Pair(11, 5), Pair(11, 45), Pair(-5, 22), Pair(56, 9),
        Pair(-23, 26), Pair(-4, 20), Pair(-66, 23), Pair(-6, 59), Pair(-66, 46), Pair(-14, 44), Pair(0, 32), Pair(5, 26),
        Pair(-6, 4), Pair(-3, 7), Pair(-23, 7), Pair(-3, 39), Pair(-4, 9), Pair(-3, 30), Pair(-4, 8), Pair(-3, 39),
        Pair(8, 18), Pair(4, -29), Pair(3, 29), Pair(-14, 26), Pair(-10, 32), Pair(-14, 20), Pair(1, 31), Pair(1, 44),
        Pair(6, -2), Pair(-6, 8), Pair(7, 19), Pair(-1, 13), Pair(2, 27), Pair(7, 7), Pair(-14, 38), Pair(6, 21),
        Pair(38, -55), Pair(6, 16), Pair(30, 14), Pair(12, 17), Pair(9, 9), Pair(9, 13), Pair(-5, 21), Pair(-49, 134)
      },
      { // Piece 2
        Pair(-41, 59), Pair(-61, 14), Pair(4, 36), Pair(-1, 15), Pair(-64, 58), Pair(-51, -11), Pair(-11, 6), Pair(16, -34),
        Pair(-32, 11), Pair(12, 29), Pair(-80, 12), Pair(-10, 68), Pair(13, -25), Pair(-89, 56), Pair(10, -4), Pair(39, 24),
        Pair(3, 71), Pair(-14, 9), Pair(-28, 61), Pair(0, 0), Pair(-9, 31), Pair(-25, 43), Pair(26, 11), Pair(9, 13),
        Pair(-9, 13), Pair(-5, 36), Pair(-48, 9), Pair(6, 57), Pair(6, -124), Pair(-7, 36), Pair(-8, 26), Pair(-21, 59),
        Pair(-26, 46), Pair(-3, -6), Pair(-16, 23), Pair(-2, 3), Pair(-9, 19), Pair(-4, 12), Pair(0, 27), Pair(2, 10),
        Pair(-3, 15), Pair(-5, 31), Pair(-9, 17), Pair(-1, 25), Pair(-3, 16), Pair(-9, 38), Pair(-15, 7), Pair(-17, 56),
        Pair(-5, 0), Pair(-3, 5), Pair(6, 12), Pair(2, 5), Pair(1, 21), Pair(-7, 23), Pair(3, 21), Pair(5, -24),
        Pair(-19, 16), Pair(10, 37), Pair(3, 4), Pair(-6, 45), Pair(-9, 8), Pair(3, 23), Pair(-41, 34), Pair(-11, 31)
      },
      { // Piece 3
        Pair(-45, 42), Pair(4, 23), Pair(-30, 9), Pair(32, 13), Pair(9, 19), Pair(-22, 53), Pair(86, 2), Pair(55, 31),
        Pair(-2, 21), Pair(-9, 35), Pair(-12, 15), Pair(-27, 44), Pair(-18, 39), Pair(1, 25), Pair(-7, 37), Pair(50, 2),
        Pair(-14, 32), Pair(-9, 26), Pair(4, 20), Pair(0, 0), Pair(-4, 35), Pair(35, 22), Pair(-30, 43), Pair(-7, 13),
        Pair(5, 8), Pair(-22, 7), Pair(13, -43), Pair(18, -29), Pair(-137, 50), Pair(-2, 15), Pair(6, -13), Pair(-4, 3),
        Pair(-20, 25), Pair(-3, 8), Pair(6, 15), Pair(-16, 16), Pair(0, 17), Pair(-19, 16), Pair(1, 25), Pair(7, 29),
        Pair(-1, 27), Pair(-11, 23), Pair(-16, 23), Pair(-16, 24), Pair(-14, 24), Pair(15, 0), Pair(15, -6), Pair(-7, 17),
        Pair(9, 23), Pair(5, 18), Pair(-1, 5), Pair(-11, 19), Pair(-4, 11), Pair(12, 2), Pair(-13, 44), Pair(19, 29),
        Pair(-2, 21), Pair(-3, 20), Pair(-1, 10), Pair(-4, 16), Pair(2, 6), Pair(3, 17), Pair(1, 21), Pair(10, 23)
      },
      { // Piece 4
        Pair(-3, 20), Pair(42, -65), Pair(-11, 41), Pair(-17, 79), Pair(16, 24), Pair(-98, 137), Pair(67, -37), Pair(8, 56),
        Pair(30, 32), Pair(14, -3), Pair(-4, 31), Pair(-79, 68), Pair(-29, 32), Pair(-21, 72), Pair(33, 38), Pair(-12, 83),
        Pair(-14, 41), Pair(38, -9), Pair(-6, 51), Pair(0, 0), Pair(18, 57), Pair(32, 15), Pair(6, 34), Pair(5, 25),
        Pair(10, 6), Pair(-5, 27), Pair(108, 9), Pair(28, -21), Pair(-5, -12), Pair(-8, 70), Pair(4, 71), Pair(14, 43),
        Pair(-6, 70), Pair(16, 13), Pair(1, 32), Pair(1, 42), Pair(9, 26), Pair(16, 11), Pair(-12, 102), Pair(23, 46),
        Pair(-12, 62), Pair(1, 27), Pair(5, 12), Pair(6, 34), Pair(2, 48), Pair(-1, 46), Pair(1, 51), Pair(6, 70),
        Pair(6, 3), Pair(2, 26), Pair(8, -3), Pair(6, 25), Pair(-2, 26), Pair(-1, 38), Pair(-10, 61), Pair(33, -38),
        Pair(-4, 43), Pair(10, 6), Pair(7, 10), Pair(9, 32), Pair(22, 3), Pair(-6, 56), Pair(26, -13), Pair(-32, -7)
      },
      { // Piece 5
        Pair(16, -22), Pair(-60, -3), Pair(5, -35), Pair(19, -30), Pair(21, -19), Pair(-17, -22), Pair(6, 40), Pair(18, -43),
        Pair(5, 73), Pair(64, 10), Pair(133, -37), Pair(-24, -31), Pair(-52, 7), Pair(43, 49), Pair(78, 35), Pair(24, 37),
        Pair(22, 17), Pair(13, -53), Pair(47, -89), Pair(0, 0), Pair(69, -93), Pair(140, 10), Pair(49, 6), Pair(14, 36),
        Pair(-28, 47), Pair(-58, 18), Pair(0, 0), Pair(47, -88), Pair(0, 0), Pair(-73, 30), Pair(71, -5), Pair(89, -11),
        Pair(-25, 4), Pair(-13, -4), Pair(102, -42), Pair(38, -52), Pair(68, -29), Pair(96, -28), Pair(-48, 19), Pair(2, 1),
        Pair(-8, -18), Pair(-62, 28), Pair(-62, -1), Pair(13, -11), Pair(17, -13), Pair(1, 10), Pair(2, 6), Pair(-31, 26),
        Pair(2, 10), Pair(-5, 0), Pair(-11, -19), Pair(-22, 12), Pair(-3, 0), Pair(-8, 15), Pair(-3, 17), Pair(10, 11),
        Pair(-20, 60), Pair(-11, 19), Pair(-9, 0), Pair(-8, 11), Pair(-1, -9), Pair(-1, 13), Pair(0, 12), Pair(-1, 5)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 7), Pair(34, 0), Pair(21, 10), Pair(16, 4), Pair(-29, 5), Pair(-8, 29), Pair(-28, 29), Pair(20, 10),
        Pair(4, 7), Pair(0, 2), Pair(5, 1), Pair(1, 2), Pair(0, 0), Pair(2, 7), Pair(-17, 11), Pair(-1, 8),
        Pair(1, 1), Pair(0, 4), Pair(5, 0), Pair(1, 25), Pair(-8, -5), Pair(2, -2), Pair(5, 6), Pair(3, 6),
        Pair(2, 0), Pair(2, -4), Pair(4, 1), Pair(3, 4), Pair(-1, 0), Pair(-2, -1), Pair(1, 3), Pair(-3, 3),
        Pair(3, 0), Pair(1, 0), Pair(0, -1), Pair(2, 1), Pair(0, 0), Pair(1, -1), Pair(-2, 3), Pair(-2, 1),
        Pair(1, 0), Pair(4, 0), Pair(1, -2), Pair(5, -7), Pair(5, -1), Pair(-4, -4), Pair(-3, -1), Pair(-1, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(10, -105), Pair(-4, -34), Pair(-6, 18), Pair(6, 27), Pair(-12, 39), Pair(46, 20), Pair(-12, 49), Pair(-25, 60),
        Pair(-20, 40), Pair(5, 26), Pair(-17, 4), Pair(-37, 40), Pair(2, -11), Pair(-8, 35), Pair(-73, -13), Pair(-34, 76),
        Pair(11, 4), Pair(-22, 16), Pair(-12, 33), Pair(-1, 24), Pair(0, 0), Pair(17, 26), Pair(-3, 14), Pair(-24, 3),
        Pair(10, 13), Pair(-10, 19), Pair(3, 15), Pair(-43, -89), Pair(1, 55), Pair(-42, 65), Pair(3, 14), Pair(-4, 7),
        Pair(3, 17), Pair(-33, 36), Pair(-3, 25), Pair(-21, 8), Pair(-3, 37), Pair(-22, 1), Pair(1, 19), Pair(-4, 9),
        Pair(-10, 35), Pair(-10, 32), Pair(-11, 9), Pair(0, 20), Pair(-23, 8), Pair(0, 17), Pair(-19, 17), Pair(-2, 36),
        Pair(-11, 31), Pair(6, 45), Pair(2, 14), Pair(-2, 24), Pair(-9, 19), Pair(5, 11), Pair(13, -1), Pair(8, 44),
        Pair(29, -65), Pair(4, 19), Pair(-2, -7), Pair(14, 18), Pair(14, 17), Pair(5, 14), Pair(2, 25), Pair(27, -41)
      },
      { // Piece 2
        Pair(24, 6), Pair(-120, 71), Pair(-44, 33), Pair(-79, 50), Pair(13, 31), Pair(-148, 71), Pair(36, -95), Pair(-47, 156),
        Pair(-14, 49), Pair(-19, 20), Pair(31, 16), Pair(-79, 36), Pair(1, 34), Pair(94, -37), Pair(33, 35), Pair(-38, -4),
        Pair(8, -7), Pair(-3, 42), Pair(-27, 18), Pair(-6, 32), Pair(0, 0), Pair(-19, 53), Pair(-4, 17), Pair(19, 17),
        Pair(1, 31), Pair(-14, 28), Pair(12, 27), Pair(-35, -12), Pair(6, 55), Pair(-141, 26), Pair(0, 25), Pair(-11, 5),
        Pair(-12, 14), Pair(14, 14), Pair(-17, 9), Pair(-21, 20), Pair(-20, 21), Pair(-4, 18), Pair(-20, 12), Pair(2, 15),
        Pair(12, 32), Pair(-22, 1), Pair(3, 9), Pair(-7, 13), Pair(4, 21), Pair(-19, 15), Pair(2, 18), Pair(-25, -15),
        Pair(-14, -14), Pair(8, 17), Pair(-4, 17), Pair(8, 21), Pair(-5, 12), Pair(0, 25), Pair(-20, 10), Pair(12, 8),
        Pair(-4, 44), Pair(-10, -1), Pair(7, 30), Pair(-9, 14), Pair(-10, 35), Pair(-10, 13), Pair(-2, 16), Pair(-6, -23)
      },
      { // Piece 3
        Pair(-8, 27), Pair(-9, 19), Pair(-6, 25), Pair(-51, 37), Pair(51, 11), Pair(55, 1), Pair(-57, 33), Pair(-6, 25),
        Pair(11, 11), Pair(-2, 29), Pair(4, 29), Pair(-4, 29), Pair(44, 15), Pair(23, 0), Pair(-41, 33), Pair(44, 2),
        Pair(14, 11), Pair(0, 16), Pair(3, 20), Pair(-14, 5), Pair(0, 0), Pair(-12, 35), Pair(-44, 50), Pair(-6, 20),
        Pair(-8, 21), Pair(-8, 18), Pair(22, 0), Pair(22, -9), Pair(13, -1), Pair(9, -50), Pair(-6, 8), Pair(14, 20),
        Pair(10, 18), Pair(-6, 22), Pair(19, 4), Pair(5, 1), Pair(0, 3), Pair(9, 8), Pair(-2, 11), Pair(18, -1),
        Pair(-3, 9), Pair(-8, 31), Pair(-16, 35), Pair(3, 10), Pair(1, 8), Pair(0, 10), Pair(6, 12), Pair(20, 19),
        Pair(3, 8), Pair(24, 3), Pair(-8, 19), Pair(-15, 19), Pair(-7, 31), Pair(3, -1), Pair(4, 13), Pair(24, 24),
        Pair(2, 13), Pair(-3, 23), Pair(3, 18), Pair(-6, 16), Pair(2, 18), Pair(0, 18), Pair(2, 11), Pair(10, 11)
      },
      { // Piece 4
        Pair(-43, 51), Pair(-7, 75), Pair(13, 24), Pair(-13, 78), Pair(56, 23), Pair(59, 77), Pair(113, -15), Pair(1, 47),
        Pair(36, 28), Pair(-5, 89), Pair(38, 52), Pair(34, -5), Pair(-2, 49), Pair(-25, 29), Pair(35, 13), Pair(43, -11),
        Pair(-5, 57), Pair(10, 38), Pair(19, 30), Pair(2, 0), Pair(0, 0), Pair(20, 31), Pair(-18, 62), Pair(55, -33),
        Pair(16, 42), Pair(19, 36), Pair(7, 40), Pair(-10, -5), Pair(40, 30), Pair(128, -13), Pair(33, 33), Pair(22, 44),
        Pair(-1, 65), Pair(-5, 60), Pair(4, 52), Pair(15, 26), Pair(32, -3), Pair(15, 35), Pair(6, 42), Pair(4, 61),
        Pair(19, 27), Pair(6, 37), Pair(4, 43), Pair(10, 22), Pair(15, 37), Pair(20, -4), Pair(19, 13), Pair(38, -72),
        Pair(2, -5), Pair(8, 23), Pair(4, 43), Pair(3, 23), Pair(19, 32), Pair(8, 62), Pair(-1, 55), Pair(12, 20),
        Pair(-7, 78), Pair(17, 46), Pair(0, 64), Pair(8, 48), Pair(15, 39), Pair(23, -15), Pair(-12, 130), Pair(6, 71)
      },
      { // Piece 5
        Pair(13, 60), Pair(-1, -30), Pair(48, 26), Pair(31, -54), Pair(-12, -24), Pair(-5, -26), Pair(-46, -65), Pair(-41, -17),
        Pair(72, 85), Pair(91, 31), Pair(28, 5), Pair(-8, -3), Pair(41, -35), Pair(78, -33), Pair(-10, -66), Pair(-97, 94),
        Pair(12, -15), Pair(98, 8), Pair(49, 2), Pair(54, -70), Pair(0, 0), Pair(40, -71), Pair(56, -2), Pair(66, -24),
        Pair(135, -36), Pair(152, 0), Pair(51, -12), Pair(5, 15), Pair(0, -67), Pair(-3, -39), Pair(8, -10), Pair(30, -5),
        Pair(33, -10), Pair(86, -24), Pair(21, -11), Pair(11, -24), Pair(25, -30), Pair(23, -23), Pair(-49, 16), Pair(-33, 18),
        Pair(40, 11), Pair(106, -22), Pair(-8, 18), Pair(25, -7), Pair(32, -14), Pair(6, -4), Pair(-8, 21), Pair(13, 0),
        Pair(24, -5), Pair(12, 2), Pair(-1, 22), Pair(8, 4), Pair(2, 6), Pair(10, 4), Pair(-4, 18), Pair(5, 9),
        Pair(-12, 39), Pair(-8, 12), Pair(-6, 24), Pair(9, 22), Pair(-7, 10), Pair(9, 11), Pair(5, 13), Pair(-3, 19)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 12), Pair(38, 7), Pair(25, 10), Pair(21, -7), Pair(37, -14), Pair(-39, 39), Pair(-50, 2), Pair(31, 22),
        Pair(1, 7), Pair(7, 5), Pair(24, -8), Pair(0, 5), Pair(-9, 2), Pair(0, 0), Pair(1, 1), Pair(-3, 3),
        Pair(5, 0), Pair(3, 1), Pair(8, 0), Pair(1, 2), Pair(13, 14), Pair(-14, -3), Pair(-1, -5), Pair(5, -1),
        Pair(5, 1), Pair(4, -1), Pair(10, -3), Pair(1, 1), Pair(3, 3), Pair(-1, -3), Pair(1, -2), Pair(-3, 2),
        Pair(3, 0), Pair(4, 0), Pair(5, -2), Pair(3, -1), Pair(0, 2), Pair(0, 0), Pair(-5, -3), Pair(-5, 1),
        Pair(3, -2), Pair(4, -2), Pair(2, 0), Pair(5, -4), Pair(5, -4), Pair(5, -3), Pair(-2, -7), Pair(-6, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(47, -21), Pair(-60, 1), Pair(43, 37), Pair(53, 1), Pair(102, -22), Pair(44, 34), Pair(-86, 37), Pair(32, 99),
        Pair(-33, 83), Pair(59, 26), Pair(69, 0), Pair(-76, 22), Pair(104, -25), Pair(-103, 41), Pair(50, 20), Pair(-120, 25),
        Pair(1, 33), Pair(36, 24), Pair(-5, 31), Pair(-6, 42), Pair(37, 20), Pair(0, 0), Pair(35, 5), Pair(46, 16),
        Pair(12, 6), Pair(21, 15), Pair(19, 21), Pair(10, 8), Pair(-38, 22), Pair(29, 51), Pair(23, -60), Pair(5, 1),
        Pair(8, 42), Pair(11, 24), Pair(12, 8), Pair(19, 24), Pair(-5, 17), Pair(10, 33), Pair(3, -38), Pair(9, 24),
        Pair(6, 31), Pair(3, 22), Pair(15, 13), Pair(0, 16), Pair(1, 22), Pair(-6, 13), Pair(16, 30), Pair(-11, 14),
        Pair(-11, 2), Pair(-12, 73), Pair(6, 31), Pair(6, 11), Pair(11, 29), Pair(0, 21), Pair(13, 37), Pair(5, 19),
        Pair(-55, 33), Pair(11, 41), Pair(-15, 22), Pair(1, 22), Pair(11, 26), Pair(25, 16), Pair(-14, 52), Pair(-42, 58)
      },
      { // Piece 2
        Pair(49, 10), Pair(54, 5), Pair(43, 30), Pair(25, 10), Pair(-5, 60), Pair(-89, 39), Pair(46, 51), Pair(-92, -149),
        Pair(-43, 36), Pair(-10, 51), Pair(-63, 50), Pair(3, 65), Pair(42, 9), Pair(24, 45), Pair(20, -29), Pair(-16, 67),
        Pair(37, 29), Pair(-50, 50), Pair(26, 34), Pair(-10, 27), Pair(26, 45), Pair(0, 0), Pair(31, 14), Pair(12, 21),
        Pair(4, 10), Pair(16, 32), Pair(2, 27), Pair(19, 28), Pair(-65, 36), Pair(22, 59), Pair(-7, 7), Pair(31, 21),
        Pair(-20, 63), Pair(-19, 38), Pair(19, 21), Pair(-6, 9), Pair(-17, 21), Pair(5, 22), Pair(3, 21), Pair(7, 3),
        Pair(16, 18), Pair(10, 41), Pair(3, 6), Pair(13, 18), Pair(-3, 12), Pair(7, 30), Pair(-15, 29), Pair(9, 24),
        Pair(7, 37), Pair(0, 5), Pair(7, 19), Pair(0, 18), Pair(16, 12), Pair(7, 15), Pair(11, 19), Pair(-16, 15),
        Pair(-25, 7), Pair(15, 58), Pair(-6, 13), Pair(9, 26), Pair(19, -9), Pair(11, 22), Pair(-10, 18), Pair(2, 38)
      },
      { // Piece 3
        Pair(13, 26), Pair(35, 24), Pair(-2, 37), Pair(29, 26), Pair(-56, 31), Pair(46, -5), Pair(18, 35), Pair(-38, 32),
        Pair(13, 26), Pair(20, 17), Pair(52, 11), Pair(2, 29), Pair(3, 30), Pair(16, 30), Pair(-92, 49), Pair(56, 5),
        Pair(21, 21), Pair(4, 19), Pair(-20, 31), Pair(57, 5), Pair(-19, 44), Pair(0, 0), Pair(37, -3), Pair(-82, 44),
        Pair(10, 18), Pair(11, 13), Pair(37, 8), Pair(-28, 42), Pair(85, -20), Pair(38, -4), Pair(69, 19), Pair(-25, 25),
        Pair(16, 16), Pair(15, 13), Pair(11, 10), Pair(-25, 36), Pair(-4, 25), Pair(13, 11), Pair(46, 30), Pair(-13, 33),
        Pair(-8, 28), Pair(-1, 26), Pair(9, 25), Pair(19, 19), Pair(-7, 19), Pair(-1, 23), Pair(34, 18), Pair(-22, 56),
        Pair(15, 13), Pair(32, 5), Pair(12, 15), Pair(16, 11), Pair(-6, 6), Pair(23, 8), Pair(17, -4), Pair(-70, 52),
        Pair(10, 26), Pair(4, 32), Pair(7, 27), Pair(6, 25), Pair(8, 12), Pair(5, 26), Pair(0, 24), Pair(-5, 40)
      },
      { // Piece 4
        Pair(-51, 26), Pair(14, -2), Pair(18, 11), Pair(31, 34), Pair(33, -8), Pair(51, -14), Pair(37, 35), Pair(34, -40),
        Pair(7, 21), Pair(35, -18), Pair(-14, 26), Pair(-29, 57), Pair(-11, 61), Pair(-22, 2), Pair(38, -5), Pair(0, 67),
        Pair(22, 36), Pair(40, 1), Pair(-10, 35), Pair(-3, 25), Pair(-4, 14), Pair(0, 0), Pair(30, -47), Pair(30, -22),
        Pair(5, 19), Pair(32, 31), Pair(12, 23), Pair(-15, 22), Pair(0, -66), Pair(50, -27), Pair(-35, 48), Pair(23, 19),
        Pair(24, -32), Pair(32, 14), Pair(22, 7), Pair(13, 19), Pair(24, -9), Pair(25, -10), Pair(19, 5), Pair(34, -4),
        Pair(34, -48), Pair(2, 23), Pair(9, 22), Pair(13, -2), Pair(7, 23), Pair(29, -21), Pair(21, -5), Pair(8, 37),
        Pair(17, 7), Pair(22, -10), Pair(14, 0), Pair(8, 15), Pair(-4, 34), Pair(17, 2), Pair(16, 8), Pair(66, -67),
        Pair(3, 15), Pair(1, 3), Pair(14, 2), Pair(12, 13), Pair(6, 34), Pair(-23, 38), Pair(-36, 50), Pair(12, -55)
      },
      { // Piece 5
        Pair(-65, -30), Pair(-16, -21), Pair(-60, -30), Pair(20, 12), Pair(2, 0), Pair(-24, -113), Pair(-18, 8), Pair(20, -48),
        Pair(-7, 88), Pair(-68, -8), Pair(-114, -11), Pair(-44, 1), Pair(45, -8), Pair(130, -62), Pair(7, -9), Pair(96, -36),
        Pair(35, -21), Pair(105, -24), Pair(115, -27), Pair(-95, -23), Pair(-139, -47), Pair(0, 0), Pair(61, -67), Pair(2, -19),
        Pair(-145, 37), Pair(77, 4), Pair(-24, 14), Pair(-4, -16), Pair(-113, -190), Pair(-40, -52), Pair(1, -4), Pair(-52, 3),
        Pair(-2, -27), Pair(112, -7), Pair(-15, 4), Pair(50, -9), Pair(30, -24), Pair(59, -36), Pair(42, -16), Pair(-3, -12),
        Pair(24, -14), Pair(38, 1), Pair(81, -15), Pair(52, -9), Pair(38, -11), Pair(-9, 2), Pair(20, -9), Pair(9, 6),
        Pair(-13, 7), Pair(24, -11), Pair(10, 5), Pair(14, 2), Pair(22, -5), Pair(31, -10), Pair(-9, 3), Pair(8, 13),
        Pair(25, -15), Pair(3, -1), Pair(8, 9), Pair(39, 7), Pair(-4, 16), Pair(12, 1), Pair(-3, 7), Pair(15, -4)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(31, 14), Pair(21, 7), Pair(20, 6), Pair(37, -2), Pair(13, 5), Pair(-6, 11), Pair(39, 6), Pair(-12, 17),
        Pair(7, 7), Pair(21, 5), Pair(12, 5), Pair(-4, 6), Pair(-2, 2), Pair(-12, 3), Pair(0, 0), Pair(-6, 5),
        Pair(0, 9), Pair(8, 1), Pair(9, 2), Pair(-4, 6), Pair(1, 0), Pair(3, 22), Pair(-5, -3), Pair(19, 5),
        Pair(1, 3), Pair(5, -1), Pair(2, 0), Pair(0, 3), Pair(1, -2), Pair(3, 2), Pair(1, 0), Pair(6, 5),
        Pair(2, -3), Pair(3, 0), Pair(1, 0), Pair(-1, -2), Pair(2, -1), Pair(5, 2), Pair(0, 0), Pair(2, 3),
        Pair(2, 0), Pair(3, -1), Pair(-4, 1), Pair(5, -6), Pair(-1, 0), Pair(3, -1), Pair(0, -2), Pair(-3, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-3, 18), Pair(-103, 10), Pair(-34, -19), Pair(-84, 6), Pair(-17, 35), Pair(-62, 49), Pair(-72, 15), Pair(77, -66),
        Pair(-9, 20), Pair(15, 34), Pair(45, 17), Pair(16, 27), Pair(14, -18), Pair(26, -14), Pair(-28, -52), Pair(34, 7),
        Pair(-19, 0), Pair(7, 20), Pair(5, 11), Pair(19, 12), Pair(26, 30), Pair(19, 24), Pair(0, 0), Pair(-89, 67),
        Pair(9, 18), Pair(7, 12), Pair(8, 20), Pair(12, 14), Pair(25, 2), Pair(5, -26), Pair(6, 57), Pair(-4, 123),
        Pair(-7, 23), Pair(-12, 21), Pair(2, 26), Pair(-4, 24), Pair(10, 22), Pair(-18, 7), Pair(-5, 36), Pair(-30, 3),
        Pair(-7, 9), Pair(3, 12), Pair(1, 13), Pair(4, 14), Pair(-13, 16), Pair(3, 17), Pair(-17, 8), Pair(6, 18),
        Pair(9, 0), Pair(-22, 10), Pair(-6, 18), Pair(0, 24), Pair(-6, 14), Pair(1, -2), Pair(-4, 14), Pair(0, 11),
        Pair(-29, -37), Pair(-2, 9), Pair(19, -12), Pair(10, -5), Pair(2, 3), Pair(-3, 20), Pair(1, 6), Pair(-23, 69)
      },
      { // Piece 2
        Pair(25, 49), Pair(-65, 58), Pair(-10, 25), Pair(-59, 46), Pair(-35, 44), Pair(-73, 63), Pair(-15, 55), Pair(47, 14),
        Pair(-24, 45), Pair(-12, 31), Pair(33, 29), Pair(-25, 39), Pair(-73, 70), Pair(-23, 25), Pair(-89, 43), Pair(-100, -16),
        Pair(-4, 33), Pair(-9, 36), Pair(-7, 34), Pair(-10, 30), Pair(6, 22), Pair(-24, 50), Pair(0, 0), Pair(-6, 36),
        Pair(0, 34), Pair(4, 27), Pair(11, 35), Pair(1, 21), Pair(-1, 25), Pair(-46, -11), Pair(5, 58), Pair(-44, 12),
        Pair(-10, 20), Pair(12, 29), Pair(-9, 33), Pair(10, 32), Pair(-1, -3), Pair(-7, 25), Pair(-19, 25), Pair(-38, 28),
        Pair(1, 26), Pair(5, 16), Pair(6, 33), Pair(-11, 12), Pair(1, 21), Pair(1, 15), Pair(6, 17), Pair(-17, 27),
        Pair(-13, 43), Pair(4, 31), Pair(0, 5), Pair(-2, 24), Pair(-3, 12), Pair(-6, 23), Pair(2, 17), Pair(15, 2),
        Pair(3, 32), Pair(-8, 7), Pair(8, 18), Pair(-25, 9), Pair(-8, 33), Pair(2, 15), Pair(22, 29), Pair(-32, 38)
      },
      { // Piece 3
        Pair(8, 36), Pair(39, 19), Pair(2, 30), Pair(-6, 34), Pair(14, 36), Pair(-34, 35), Pair(-12, 36), Pair(-22, 41),
        Pair(-13, 36), Pair(13, 19), Pair(19, 25), Pair(8, 28), Pair(-29, 48), Pair(-27, 37), Pair(59, 34), Pair(13, 29),
        Pair(-9, 25), Pair(17, 25), Pair(7, 21), Pair(-6, 29), Pair(-40, 33), Pair(-19, 45), Pair(0, 0), Pair(-32, 31),
        Pair(19, 24), Pair(3, 19), Pair(5, 22), Pair(22, 27), Pair(5, 17), Pair(-47, -13), Pair(-11, 32), Pair(111, -71),
        Pair(-6, 20), Pair(-4, 42), Pair(9, 23), Pair(-4, 28), Pair(-5, 31), Pair(-22, 32), Pair(23, 10), Pair(-27, 20),
        Pair(16, 16), Pair(15, 18), Pair(-6, 26), Pair(6, 29), Pair(9, 13), Pair(-12, 38), Pair(-6, 50), Pair(0, 13),
        Pair(-5, 34), Pair(24, 27), Pair(-2, 27), Pair(11, 17), Pair(1, 24), Pair(-2, 32), Pair(-16, 20), Pair(31, 13),
        Pair(6, 27), Pair(3, 27), Pair(-2, 37), Pair(3, 25), Pair(1, 21), Pair(2, 24), Pair(11, 16), Pair(-7, 24)
      },
      { // Piece 4
        Pair(4, 21), Pair(-53, 76), Pair(-78, 85), Pair(33, -16), Pair(37, -31), Pair(44, 68), Pair(-67, 5), Pair(52, 60),
        Pair(14, 0), Pair(-7, 28), Pair(2, 29), Pair(-26, 51), Pair(-53, 73), Pair(1, 42), Pair(-25, 99), Pair(38, 19),
        Pair(9, 15), Pair(32, -17), Pair(-12, 23), Pair(-19, 2), Pair(-7, 18), Pair(13, -5), Pair(0, 0), Pair(-33, -22),
        Pair(14, 6), Pair(3, 30), Pair(5, 23), Pair(-7, 33), Pair(-28, 71), Pair(-27, -20), Pair(-2, -26), Pair(52, -24),
        Pair(2, 21), Pair(-17, 52), Pair(0, 7), Pair(-5, 54), Pair(-7, 23), Pair(-6, 28), Pair(-1, -7), Pair(-2, 28),
        Pair(2, 33), Pair(-3, 28), Pair(1, 20), Pair(1, 33), Pair(-10, 23), Pair(-6, 20), Pair(21, -26), Pair(-12, 19),
        Pair(-11, 30), Pair(-9, 19), Pair(0, 15), Pair(3, 5), Pair(-8, 28), Pair(-6, 18), Pair(3, -7), Pair(-25, 57),
        Pair(-17, 9), Pair(8, -2), Pair(-3, 11), Pair(6, -3), Pair(-1, 37), Pair(-17, 45), Pair(21, -33), Pair(-9, 65)
      },
      { // Piece 5
        Pair(144, -34), Pair(48, -30), Pair(-23, -32), Pair(45, 62), Pair(0, -60), Pair(2, -17), Pair(27, -64), Pair(-24, -57),
        Pair(1, -15), Pair(8, -30), Pair(154, 2), Pair(53, -13), Pair(106, -98), Pair(-40, -12), Pair(-9, -4), Pair(83, -59),
        Pair(101, 17), Pair(196, -18), Pair(-10, -10), Pair(26, -26), Pair(10, -5), Pair(-25, -37), Pair(0, 0), Pair(146, -65),
        Pair(101, -10), Pair(74, -10), Pair(6, 8), Pair(98, -23), Pair(-30, -7), Pair(9, 40), Pair(54, -74), Pair(-20, -136),
        Pair(82, -10), Pair(2, 2), Pair(55, -7), Pair(33, -12), Pair(-23, -4), Pair(3, -13), Pair(9, -14), Pair(-4, -25),
        Pair(71, -19), Pair(27, -6), Pair(40, -13), Pair(65, -13), Pair(-19, 7), Pair(19, 0), Pair(-2, 3), Pair(-35, 12),
        Pair(14, -10), Pair(-29, 12), Pair(-4, 6), Pair(8, 7), Pair(-6, 14), Pair(6, 4), Pair(0, 4), Pair(2, 4),
        Pair(-32, 0), Pair(-17, -9), Pair(-12, 4), Pair(-24, 13), Pair(-9, 15), Pair(-1, 13), Pair(-4, 3), Pair(-8, 1)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, 10), Pair(-40, 25), Pair(40, 5), Pair(3, 3), Pair(27, 3), Pair(9, 8), Pair(-20, -5), Pair(66, 33),
        Pair(8, 5), Pair(-4, 9), Pair(14, -2), Pair(18, -1), Pair(-2, 5), Pair(-23, 0), Pair(-17, 2), Pair(0, 0),
        Pair(2, 6), Pair(3, 2), Pair(3, 6), Pair(-1, 2), Pair(-5, 3), Pair(-7, 1), Pair(0, -6), Pair(0, -1),
        Pair(1, 0), Pair(4, -2), Pair(2, -2), Pair(-1, -1), Pair(2, 1), Pair(-2, 1), Pair(0, -3), Pair(-2, -2),
        Pair(-1, -1), Pair(3, -3), Pair(-1, -3), Pair(1, -3), Pair(1, 0), Pair(4, -1), Pair(1, -3), Pair(0, 0),
        Pair(-1, -3), Pair(1, -2), Pair(-2, -5), Pair(4, -12), Pair(1, -1), Pair(1, -2), Pair(1, -4), Pair(0, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-63, 58), Pair(-104, 8), Pair(-2, -27), Pair(-7, 5), Pair(-51, 62), Pair(2, 86), Pair(6, 46), Pair(21, -12),
        Pair(-19, 23), Pair(0, -4), Pair(-38, 29), Pair(49, 7), Pair(22, 21), Pair(-32, 6), Pair(25, 19), Pair(-21, -30),
        Pair(34, 2), Pair(1, -1), Pair(2, 19), Pair(19, 10), Pair(22, 7), Pair(45, 14), Pair(-3, 44), Pair(0, 0),
        Pair(9, 3), Pair(-4, 9), Pair(11, 10), Pair(14, 12), Pair(17, 14), Pair(16, 13), Pair(-5, -40), Pair(29, 35),
        Pair(2, 15), Pair(-5, -21), Pair(2, 9), Pair(5, 14), Pair(11, 22), Pair(16, 12), Pair(5, -6), Pair(1, 21),
        Pair(-11, -3), Pair(-3, 4), Pair(3, 10), Pair(1, 8), Pair(8, 17), Pair(-3, 18), Pair(16, 19), Pair(-18, 0),
        Pair(-5, 13), Pair(-2, 1), Pair(-22, 9), Pair(-3, 9), Pair(5, 13), Pair(-8, 19), Pair(-6, 46), Pair(3, 14),
        Pair(26, -28), Pair(-10, 23), Pair(-10, -3), Pair(4, 1), Pair(-9, 17), Pair(-8, 31), Pair(-6, 36), Pair(-72, -20)
      },
      { // Piece 2
        Pair(27, 19), Pair(-45, 52), Pair(55, 48), Pair(-110, 45), Pair(-80, 47), Pair(-78, 85), Pair(-25, 54), Pair(4, -5),
        Pair(3, 27), Pair(8, 34), Pair(-15, 25), Pair(-82, 72), Pair(-11, 30), Pair(7, 44), Pair(-57, 49), Pair(37, 41),
        Pair(-7, 38), Pair(-16, 32), Pair(-20, 51), Pair(-15, 29), Pair(16, 34), Pair(-33, 33), Pair(-12, 50), Pair(0, 0),
        Pair(-32, 35), Pair(5, 28), Pair(-28, 40), Pair(3, 38), Pair(7, 32), Pair(-19, 32), Pair(-3, 17), Pair(23, 73),
        Pair(-4, 31), Pair(-28, 31), Pair(3, 35), Pair(-7, 28), Pair(10, 26), Pair(-3, 24), Pair(11, 2), Pair(-19, 15),
        Pair(-6, 29), Pair(16, 26), Pair(7, 28), Pair(-4, 34), Pair(-2, 18), Pair(1, 33), Pair(6, 15), Pair(8, 32),
        Pair(14, 33), Pair(0, 25), Pair(3, 17), Pair(-12, 23), Pair(1, 28), Pair(-1, 21), Pair(10, 24), Pair(10, 16),
        Pair(3, 27), Pair(10, 36), Pair(-9, 12), Pair(-1, 19), Pair(-22, 30), Pair(8, 28), Pair(-28, 16), Pair(16, 19)
      },
      { // Piece 3
        Pair(21, 43), Pair(7, 37), Pair(-36, 45), Pair(12, 42), Pair(-48, 53), Pair(39, 33), Pair(14, 57), Pair(16, 45),
        Pair(17, 38), Pair(9, 40), Pair(4, 44), Pair(38, 23), Pair(20, 29), Pair(-32, 61), Pair(50, 19), Pair(72, 62),
        Pair(6, 33), Pair(-8, 43), Pair(11, 39), Pair(9, 43), Pair(27, 45), Pair(37, 43), Pair(41, 43), Pair(0, 0),
        Pair(16, 39), Pair(20, 37), Pair(6, 41), Pair(12, 37), Pair(9, 43), Pair(-21, 46), Pair(1, -12), Pair(-8, 44),
        Pair(7, 31), Pair(21, 38), Pair(17, 31), Pair(-13, 38), Pair(9, 20), Pair(-20, 47), Pair(17, 17), Pair(-35, 47),
        Pair(6, 30), Pair(8, 31), Pair(25, 34), Pair(18, 31), Pair(-1, 34), Pair(2, 31), Pair(14, 38), Pair(-5, 40),
        Pair(30, 13), Pair(14, 36), Pair(7, 31), Pair(3, 37), Pair(12, 30), Pair(4, 38), Pair(13, 15), Pair(-32, 22),
        Pair(7, 37), Pair(1, 46), Pair(8, 45), Pair(6, 36), Pair(1, 41), Pair(10, 29), Pair(4, 38), Pair(-8, 43)
      },
      { // Piece 4
        Pair(11, 31), Pair(-16, 59), Pair(-6, 66), Pair(-25, 39), Pair(21, 46), Pair(9, 28), Pair(118, -12), Pair(-56, 80),
        Pair(10, 28), Pair(0, 64), Pair(26, 22), Pair(-61, 88), Pair(-5, 66), Pair(-39, 118), Pair(-74, 138), Pair(-3, 50),
        Pair(29, 10), Pair(11, 20), Pair(2, 59), Pair(-3, 16), Pair(-4, 58), Pair(1, 71), Pair(-37, 69), Pair(0, 0),
        Pair(3, 44), Pair(-6, 52), Pair(3, 39), Pair(-10, 63), Pair(-10, 72), Pair(9, 48), Pair(-28, 7), Pair(2, 39),
        Pair(-5, 36), Pair(1, 51), Pair(-2, 38), Pair(8, 67), Pair(0, 51), Pair(14, 51), Pair(9, 30), Pair(-12, 19),
        Pair(11, 28), Pair(-7, 39), Pair(8, 27), Pair(11, 34), Pair(1, 41), Pair(-13, 68), Pair(17, 8), Pair(-2, 6),
        Pair(-2, 10), Pair(0, 38), Pair(2, 24), Pair(3, 27), Pair(2, 30), Pair(18, 9), Pair(24, -32), Pair(2, 20),
        Pair(-5, 0), Pair(2, 31), Pair(-3, 31), Pair(6, 29), Pair(5, 37), Pair(-20, 34), Pair(-19, 55), Pair(44, -34)
      },
      { // Piece 5
        Pair(-71, -59), Pair(-23, -59), Pair(-102, 11), Pair(-64, 59), Pair(137, 34), Pair(-147, -103), Pair(94, 77), Pair(5, -29),
        Pair(44, 16), Pair(44, -32), Pair(-47, -2), Pair(-165, -17), Pair(-131, 42), Pair(30, -44), Pair(-77, 4), Pair(42, 32),
        Pair(-31, 30), Pair(20, 3), Pair(-27, 24), Pair(36, -24), Pair(3, 4), Pair(19, -5), Pair(-29, -52), Pair(0, 0),
        Pair(88, -4), Pair(124, -25), Pair(104, -20), Pair(23, -5), Pair(17, 2), Pair(-32, 9), Pair(-23, -19), Pair(117, -76),
        Pair(57, -28), Pair(32, -9), Pair(92, -25), Pair(67, -4), Pair(-15, 4), Pair(2, -12), Pair(60, -19), Pair(38, -15),
        Pair(40, -33), Pair(21, -4), Pair(79, -24), Pair(57, -11), Pair(44, -11), Pair(-7, 2), Pair(6, -3), Pair(-9, 1),
        Pair(-22, 3), Pair(11, 6), Pair(13, -3), Pair(12, 4), Pair(5, 3), Pair(-3, 10), Pair(-5, 7), Pair(-3, 3),
        Pair(-31, 24), Pair(-11, -3), Pair(-3, 0), Pair(14, -6), Pair(2, 0), Pair(-6, 14), Pair(5, 7), Pair(-4, 7)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(6, 6), Pair(-43, 12), Pair(-5, 9), Pair(-5, 15), Pair(22, 10), Pair(-21, -1), Pair(-10, 13),
        Pair(-23, -22), Pair(-12, 34), Pair(3, -1), Pair(3, 8), Pair(-3, 6), Pair(-1, 4), Pair(0, 17), Pair(-7, 18),
        Pair(-9, -7), Pair(-5, 6), Pair(0, 3), Pair(5, 0), Pair(-1, 7), Pair(-6, 9), Pair(-4, 5), Pair(5, 7),
        Pair(-5, -2), Pair(-3, -2), Pair(-1, -1), Pair(0, 2), Pair(1, 3), Pair(-3, 3), Pair(-1, 5), Pair(1, 4),
        Pair(-2, 2), Pair(0, 0), Pair(1, 1), Pair(1, -2), Pair(-1, 4), Pair(-3, 3), Pair(-2, 0), Pair(0, 2),
        Pair(0, 0), Pair(2, -1), Pair(1, -1), Pair(-1, -3), Pair(1, -5), Pair(-3, 1), Pair(-1, 2), Pair(1, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-98, -21), Pair(82, 19), Pair(-108, 47), Pair(29, -2), Pair(103, -40), Pair(-205, 37), Pair(35, -58), Pair(-50, -14),
        Pair(0, 0), Pair(16, 25), Pair(10, 38), Pair(67, -10), Pair(8, 12), Pair(5, 36), Pair(13, -12), Pair(60, -15),
        Pair(19, 59), Pair(-131, -8), Pair(5, 18), Pair(25, 0), Pair(5, 31), Pair(49, -11), Pair(68, -19), Pair(62, -34),
        Pair(32, 7), Pair(-12, 21), Pair(8, 13), Pair(4, 31), Pair(16, 13), Pair(37, 6), Pair(22, 6), Pair(22, 13),
        Pair(-12, 11), Pair(-5, 31), Pair(-12, 26), Pair(9, 30), Pair(15, 22), Pair(13, 7), Pair(17, -7), Pair(13, 23),
        Pair(-5, 42), Pair(8, 14), Pair(-6, 30), Pair(13, 10), Pair(5, 16), Pair(7, 17), Pair(8, 14), Pair(20, 13),
        Pair(-1, 71), Pair(3, 27), Pair(11, 5), Pair(4, 15), Pair(-1, 28), Pair(12, 11), Pair(-2, -10), Pair(-8, 34),
        Pair(-117, 108), Pair(0, 33), Pair(-16, 39), Pair(14, 7), Pair(11, -6), Pair(5, 22), Pair(5, 5), Pair(7, 75)
      },
      { // Piece 2
        Pair(-2, 4), Pair(-9, 64), Pair(54, 50), Pair(19, 27), Pair(10, 63), Pair(26, 64), Pair(-4, 25), Pair(-48, 48),
        Pair(0, 0), Pair(-11, 47), Pair(-16, 26), Pair(-40, 57), Pair(-1, 59), Pair(24, 42), Pair(52, 26), Pair(-6, -2),
        Pair(18, 57), Pair(-302, 133), Pair(-21, 45), Pair(-11, 48), Pair(-13, 42), Pair(35, 18), Pair(-17, 40), Pair(3, 29),
        Pair(43, 25), Pair(-17, 38), Pair(17, 60), Pair(9, 38), Pair(10, 35), Pair(-9, 47), Pair(7, 40), Pair(19, 19),
        Pair(0, 53), Pair(-17, 29), Pair(-1, 43), Pair(-3, 51), Pair(4, 30), Pair(12, 41), Pair(-12, 55), Pair(1, 33),
        Pair(-4, 57), Pair(-1, 43), Pair(-6, 38), Pair(2, 29), Pair(1, 33), Pair(6, 24), Pair(3, 41), Pair(8, 31),
        Pair(19, 26), Pair(2, 35), Pair(-2, 34), Pair(2, 39), Pair(-1, 27), Pair(11, 30), Pair(9, 20), Pair(9, 38),
        Pair(11, 46), Pair(-11, 43), Pair(3, 40), Pair(14, 24), Pair(2, 41), Pair(-3, 34), Pair(11, 49), Pair(2, 35)
      },
      { // Piece 3
        Pair(-1, 74), Pair(25, 72), Pair(-23, 71), Pair(-33, 66), Pair(-59, 85), Pair(-41, 62), Pair(5, 71), Pair(18, 72),
        Pair(0, 0), Pair(-12, 70), Pair(14, 69), Pair(-8, 78), Pair(-29, 73), Pair(-4, 81), Pair(4, 78), Pair(4, 65),
        Pair(-6, 81), Pair(-40, -126), Pair(1, 58), Pair(9, 56), Pair(15, 62), Pair(24, 44), Pair(-21, 62), Pair(-11, 59),
        Pair(7, 53), Pair(-16, 65), Pair(8, 55), Pair(9, 55), Pair(10, 64), Pair(-22, 73), Pair(-14, 45), Pair(-7, 56),
        Pair(12, 36), Pair(-14, 24), Pair(2, 59), Pair(-10, 42), Pair(4, 44), Pair(10, 39), Pair(-17, 66), Pair(9, 58),
        Pair(0, 33), Pair(-19, 54), Pair(-2, 46), Pair(-2, 52), Pair(-12, 64), Pair(8, 43), Pair(15, 43), Pair(-2, 68),
        Pair(-5, 44), Pair(-3, 44), Pair(3, 44), Pair(0, 44), Pair(6, 54), Pair(1, 48), Pair(14, 40), Pair(10, 41),
        Pair(-5, 47), Pair(-11, 55), Pair(-10, 49), Pair(-6, 48), Pair(-4, 53), Pair(-2, 49), Pair(-1, 69), Pair(-1, 60)
      },
      { // Piece 4
        Pair(-132, 210), Pair(45, 47), Pair(-26, 153), Pair(-10, 118), Pair(6, 83), Pair(72, -6), Pair(-7, 105), Pair(37, 95),
        Pair(0, 0), Pair(14, 100), Pair(-6, 156), Pair(-21, 163), Pair(10, 106), Pair(-63, 163), Pair(-17, 40), Pair(70, 81),
        Pair(8, 117), Pair(-70, -30), Pair(-17, 132), Pair(4, 100), Pair(36, 73), Pair(43, 50), Pair(16, 104), Pair(32, 85),
        Pair(35, 28), Pair(-9, 112), Pair(22, 42), Pair(4, 99), Pair(6, 123), Pair(14, 117), Pair(13, 69), Pair(31, 72),
        Pair(17, 60), Pair(11, 72), Pair(0, 99), Pair(15, 89), Pair(0, 106), Pair(21, 54), Pair(31, 68), Pair(18, 124),
        Pair(6, 72), Pair(0, 72), Pair(-1, 65), Pair(7, 81), Pair(0, 91), Pair(17, 70), Pair(16, 74), Pair(1, 64),
        Pair(1, 88), Pair(5, 75), Pair(5, 74), Pair(3, 67), Pair(7, 70), Pair(-4, 91), Pair(7, 94), Pair(16, 99),
        Pair(12, 43), Pair(4, 77), Pair(6, 69), Pair(1, 73), Pair(7, 52), Pair(2, 99), Pair(-17, 126), Pair(43, -29)
      },
      { // Piece 5
        Pair(23, 22), Pair(-27, 19), Pair(-16, -5), Pair(54, 52), Pair(46, 48), Pair(60, 14), Pair(3, 12), Pair(24, -29),
        Pair(0, 0), Pair(10, -61), Pair(-15, -2), Pair(-16, 3), Pair(28, -49), Pair(34, 26), Pair(142, 34), Pair(33, 12),
        Pair(-9, -54), Pair(0, 0), Pair(-90, -23), Pair(-51, -12), Pair(-126, -6), Pair(32, -35), Pair(121, -20), Pair(-67, -2),
        Pair(-123, -22), Pair(57, -24), Pair(25, -18), Pair(50, -37), Pair(67, -12), Pair(16, 3), Pair(6, 5), Pair(-2, -3),
        Pair(-42, -28), Pair(47, -38), Pair(-35, -12), Pair(101, -29), Pair(-1, 7), Pair(-6, 16), Pair(2, -5), Pair(112, -13),
        Pair(69, -59), Pair(-2, -31), Pair(-14, -5), Pair(-9, -7), Pair(-9, -2), Pair(15, -5), Pair(3, 1), Pair(17, 8),
        Pair(-29, 20), Pair(-4, -12), Pair(3, -6), Pair(21, -5), Pair(2, -6), Pair(20, -14), Pair(2, -6), Pair(3, 2),
        Pair(21, 39), Pair(10, 23), Pair(6, 22), Pair(9, -2), Pair(11, -11), Pair(-7, -4), Pair(0, -2), Pair(-2, 5)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(21, -47), Pair(0, 0), Pair(-8, -1), Pair(29, 7), Pair(41, 7), Pair(0, 25), Pair(6, 20), Pair(1, 18),
        Pair(7, 28), Pair(-30, -15), Pair(-14, 30), Pair(5, 5), Pair(6, 0), Pair(10, 5), Pair(-3, 11), Pair(1, 12),
        Pair(8, 7), Pair(-10, -6), Pair(1, 10), Pair(3, -1), Pair(-4, 10), Pair(-2, 6), Pair(-3, 7), Pair(-1, 8),
        Pair(5, 1), Pair(-8, -6), Pair(2, 6), Pair(-2, 2), Pair(-2, 2), Pair(0, 0), Pair(-4, 9), Pair(0, 7),
        Pair(4, 1), Pair(-4, 0), Pair(3, 7), Pair(-1, -1), Pair(-1, 3), Pair(-4, 0), Pair(-4, 0), Pair(-2, 4),
        Pair(2, 2), Pair(0, 0), Pair(2, 4), Pair(-3, 8), Pair(0, -6), Pair(-5, -3), Pair(-3, -1), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-23, 28), Pair(-69, -109), Pair(-71, 22), Pair(-70, -32), Pair(58, -36), Pair(69, -68), Pair(-129, 33), Pair(-19, 31),
        Pair(-19, -24), Pair(0, 0), Pair(-18, 33), Pair(-78, 57), Pair(37, -18), Pair(29, -5), Pair(-17, -2), Pair(-59, 46),
        Pair(122, 1), Pair(-1, 58), Pair(-186, 174), Pair(7, 20), Pair(20, 17), Pair(52, 4), Pair(-13, 29), Pair(36, 1),
        Pair(10, 44), Pair(-3, 27), Pair(-33, 47), Pair(-9, 27), Pair(-1, 16), Pair(12, 19), Pair(7, 21), Pair(17, 21),
        Pair(3, 17), Pair(-23, -17), Pair(-15, 33), Pair(-3, 19), Pair(0, 28), Pair(2, 20), Pair(12, 25), Pair(2, 27),
        Pair(3, 10), Pair(-3, 19), Pair(2, 20), Pair(-3, 24), Pair(-3, 23), Pair(4, 19), Pair(3, 19), Pair(-1, 36),
        Pair(15, 37), Pair(11, 12), Pair(10, 18), Pair(4, 10), Pair(13, 4), Pair(10, 17), Pair(-15, 21), Pair(7, 27),
        Pair(113, -28), Pair(2, 27), Pair(-11, 28), Pair(-9, 12), Pair(8, 6), Pair(24, -19), Pair(-4, 43), Pair(37, 62)
      },
      { // Piece 2
        Pair(0, 0), Pair(-82, 67), Pair(-26, 31), Pair(34, 16), Pair(-22, 78), Pair(-158, 68), Pair(-25, 21), Pair(1, 56),
        Pair(1, 7), Pair(0, 0), Pair(4, 19), Pair(-102, 106), Pair(-6, 51), Pair(14, 36), Pair(-43, 40), Pair(7, 35),
        Pair(60, 22), Pair(-14, 64), Pair(-125, -56), Pair(-39, 51), Pair(7, 42), Pair(-10, 51), Pair(3, 39), Pair(4, 33),
        Pair(-4, 42), Pair(0, 37), Pair(-26, 36), Pair(-29, 66), Pair(-4, 40), Pair(-15, 52), Pair(9, 26), Pair(0, 30),
        Pair(-10, 39), Pair(1, 12), Pair(-26, 35), Pair(-12, 33), Pair(2, 24), Pair(5, 16), Pair(-11, 28), Pair(4, 26),
        Pair(2, 31), Pair(-5, 42), Pair(-3, 38), Pair(-2, 35), Pair(0, 28), Pair(-3, 31), Pair(9, 38), Pair(-2, 25),
        Pair(-4, 27), Pair(8, 31), Pair(-6, 37), Pair(5, 23), Pair(-3, 29), Pair(-13, 37), Pair(1, 26), Pair(8, 21),
        Pair(10, 13), Pair(8, 58), Pair(7, 23), Pair(-2, 51), Pair(18, 20), Pair(1, 32), Pair(2, -34), Pair(-15, 39)
      },
      { // Piece 3
        Pair(0, 25), Pair(-37, 28), Pair(-1, 43), Pair(81, 9), Pair(21, 23), Pair(-15, 31), Pair(66, -12), Pair(31, 35),
        Pair(3, 17), Pair(0, 0), Pair(-27, 54), Pair(1, 53), Pair(8, 71), Pair(-7, 46), Pair(-58, 62), Pair(-14, 52),
        Pair(-123, 1), Pair(-17, 28), Pair(-158, -31), Pair(-1, 41), Pair(-6, 30), Pair(-12, 30), Pair(12, 25), Pair(28, 28),
        Pair(5, 19), Pair(2, 21), Pair(-14, 29), Pair(-26, 36), Pair(-25, 45), Pair(-2, 23), Pair(17, 11), Pair(16, 23),
        Pair(-18, 23), Pair(-6, 30), Pair(-36, 35), Pair(-2, 36), Pair(-9, 28), Pair(2, 23), Pair(7, 45), Pair(12, 22),
        Pair(-7, 19), Pair(-5, 35), Pair(-25, 35), Pair(2, 24), Pair(12, 3), Pair(-6, 33), Pair(26, 10), Pair(25, 31),
        Pair(-6, 24), Pair(-11, 20), Pair(-8, 42), Pair(-4, 28), Pair(12, 21), Pair(6, 29), Pair(1, 35), Pair(2, 36),
        Pair(-9, 36), Pair(-5, 28), Pair(-13, 33), Pair(-8, 31), Pair(-4, 33), Pair(0, 35), Pair(-1, 34), Pair(14, 43)
      },
      { // Piece 4
        Pair(24, 20), Pair(4, 26), Pair(16, 83), Pair(6, 106), Pair(63, 57), Pair(86, 37), Pair(-102, 100), Pair(47, 10),
        Pair(-3, 97), Pair(0, 0), Pair(13, 80), Pair(12, 86), Pair(14, 62), Pair(7, 99), Pair(-2, 39), Pair(-1, 72),
        Pair(-206, -58), Pair(11, 44), Pair(-124, -83), Pair(36, 3), Pair(3, 81), Pair(52, 23), Pair(-19, 82), Pair(17, 73),
        Pair(15, 55), Pair(6, 47), Pair(-1, 59), Pair(29, 26), Pair(-18, 120), Pair(13, 74), Pair(3, 80), Pair(15, 59),
        Pair(0, 71), Pair(12, 37), Pair(20, 30), Pair(4, 71), Pair(6, 82), Pair(6, 75), Pair(1, 89), Pair(4, 108),
        Pair(15, 34), Pair(9, 36), Pair(14, 18), Pair(1, 54), Pair(12, 43), Pair(2, 71), Pair(9, 71), Pair(-10, 150),
        Pair(23, 71), Pair(5, 79), Pair(4, 53), Pair(7, 41), Pair(2, 77), Pair(-8, 87), Pair(13, 61), Pair(26, 46),
        Pair(18, 20), Pair(18, 60), Pair(17, 28), Pair(5, 51), Pair(7, 47), Pair(2, 85), Pair(-1, 133), Pair(-63, 84)
      },
      { // Piece 5
        Pair(2, 24), Pair(-3, -124), Pair(-57, -22), Pair(29, -63), Pair(-1, 18), Pair(67, -26), Pair(-40, -53), Pair(17, -110),
        Pair(-47, -37), Pair(0, 0), Pair(-34, -40), Pair(23, -54), Pair(-22, -7), Pair(2, 72), Pair(-37, 20), Pair(7, -17),
        Pair(0, 0), Pair(-66, -74), Pair(0, 0), Pair(-5, -7), Pair(-168, 23), Pair(59, 3), Pair(-9, 26), Pair(-15, -6),
        Pair(-21, -47), Pair(-23, -44), Pair(52, -13), Pair(-168, 5), Pair(126, -5), Pair(29, 15), Pair(-95, 25), Pair(92, -29),
        Pair(-86, -65), Pair(-35, -19), Pair(-24, -13), Pair(-48, 9), Pair(21, -17), Pair(2, 0), Pair(-46, 11), Pair(0, 12),
        Pair(-76, -4), Pair(-17, -15), Pair(-40, -5), Pair(1, 1), Pair(7, 1), Pair(-14, 7), Pair(18, -1), Pair(28, 1),
        Pair(-23, 15), Pair(-26, -12), Pair(23, -18), Pair(8, 3), Pair(7, 3), Pair(17, 4), Pair(10, -2), Pair(4, -4),
        Pair(13, -21), Pair(2, 9), Pair(7, -4), Pair(18, 5), Pair(-2, 5), Pair(28, -5), Pair(0, 5), Pair(6, -3)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, 15), Pair(-6, -16), Pair(0, 0), Pair(-28, -6), Pair(-40, 23), Pair(27, 9), Pair(-39, 36), Pair(31, 0),
        Pair(-2, 12), Pair(26, -12), Pair(-26, -15), Pair(-5, 41), Pair(-8, 1), Pair(9, 18), Pair(-8, 9), Pair(-10, 13),
        Pair(-1, 0), Pair(3, 7), Pair(-9, -3), Pair(2, 15), Pair(-3, 5), Pair(3, 2), Pair(6, 5), Pair(6, 4),
        Pair(-2, 3), Pair(1, -6), Pair(-7, -5), Pair(0, 6), Pair(-1, 1), Pair(0, 7), Pair(4, 0), Pair(3, 7),
        Pair(0, 4), Pair(0, -3), Pair(-2, -1), Pair(2, 1), Pair(-1, 4), Pair(-2, 2), Pair(3, 0), Pair(2, 4),
        Pair(-2, 3), Pair(-3, -5), Pair(0, 0), Pair(-4, 12), Pair(0, -5), Pair(-4, -3), Pair(4, -2), Pair(4, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-39, -8), Pair(56, 72), Pair(-2, -16), Pair(-42, 6), Pair(49, -105), Pair(-122, 82), Pair(43, 67), Pair(-67, 104),
        Pair(-15, 41), Pair(25, 18), Pair(0, 0), Pair(-68, 47), Pair(-53, 62), Pair(-31, 51), Pair(15, 20), Pair(2, 6),
        Pair(-7, -8), Pair(-3, -137), Pair(3, 48), Pair(-290, 211), Pair(4, 32), Pair(-7, 34), Pair(22, 30), Pair(-25, 18),
        Pair(-8, 33), Pair(-21, 13), Pair(-1, 39), Pair(-33, 30), Pair(-4, 44), Pair(13, 4), Pair(9, 30), Pair(4, -14),
        Pair(0, 32), Pair(-33, 55), Pair(-10, 22), Pair(-16, 24), Pair(-5, 36), Pair(-1, 30), Pair(3, 26), Pair(3, 22),
        Pair(-1, 13), Pair(1, 52), Pair(-4, 24), Pair(6, 28), Pair(-5, 23), Pair(2, 20), Pair(-2, 20), Pair(1, 12),
        Pair(-20, 39), Pair(-20, 30), Pair(4, 20), Pair(-3, 25), Pair(2, 17), Pair(2, 12), Pair(20, -13), Pair(3, 50),
        Pair(-19, -66), Pair(-3, 36), Pair(15, 21), Pair(3, 41), Pair(7, 13), Pair(-1, 31), Pair(11, 32), Pair(37, -48)
      },
      { // Piece 2
        Pair(16, 47), Pair(-35, 18), Pair(-15, 26), Pair(-20, 45), Pair(8, 64), Pair(4, 52), Pair(-103, 126), Pair(57, -7),
        Pair(-11, -1), Pair(-8, 12), Pair(0, 0), Pair(-48, 70), Pair(-17, 3), Pair(-40, 53), Pair(16, 36), Pair(-12, 20),
        Pair(-1, 59), Pair(49, -37), Pair(2, 51), Pair(-238, -44), Pair(-12, 41), Pair(6, 57), Pair(-25, 82), Pair(-15, 49),
        Pair(18, 12), Pair(-5, 21), Pair(6, 26), Pair(-19, 36), Pair(3, 31), Pair(-7, 33), Pair(-8, 36), Pair(21, 31),
        Pair(4, 64), Pair(-29, 46), Pair(-3, 41), Pair(-28, 43), Pair(1, 29), Pair(-10, 46), Pair(1, 24), Pair(-3, 8),
        Pair(2, 13), Pair(-1, 27), Pair(-2, 32), Pair(1, 33), Pair(-8, 29), Pair(-1, 30), Pair(2, 16), Pair(-3, 36),
        Pair(-28, 95), Pair(0, 18), Pair(2, 44), Pair(-5, 27), Pair(5, 29), Pair(3, 20), Pair(9, 22), Pair(16, 32),
        Pair(11, 33), Pair(-18, 101), Pair(-4, 27), Pair(4, 42), Pair(13, -1), Pair(5, 30), Pair(-11, -34), Pair(16, 28)
      },
      { // Piece 3
        Pair(-5, 15), Pair(-34, 28), Pair(-41, 30), Pair(-31, 45), Pair(21, 43), Pair(-50, 71), Pair(-30, 36), Pair(-135, 79),
        Pair(0, 27), Pair(-29, 11), Pair(0, 0), Pair(2, 29), Pair(-10, 37), Pair(-27, 39), Pair(-18, 36), Pair(-16, 33),
        Pair(7, 0), Pair(36, -132), Pair(19, 7), Pair(10, 62), Pair(-20, 13), Pair(50, 6), Pair(7, 20), Pair(-33, 32),
        Pair(-21, 37), Pair(-12, 3), Pair(-1, 18), Pair(-15, 19), Pair(-6, 24), Pair(-27, 53), Pair(14, 18), Pair(-15, 49),
        Pair(11, 11), Pair(-21, -3), Pair(-3, 16), Pair(-14, 10), Pair(7, 5), Pair(-13, 20), Pair(21, 22), Pair(14, 29),
        Pair(-20, 15), Pair(-24, 24), Pair(0, 5), Pair(-27, 25), Pair(6, 18), Pair(-15, 41), Pair(-11, 42), Pair(-21, 49),
        Pair(-14, 25), Pair(-14, 34), Pair(-15, 34), Pair(-4, 11), Pair(6, 16), Pair(3, 26), Pair(21, 11), Pair(23, 29),
        Pair(-13, 32), Pair(-10, 25), Pair(-9, 29), Pair(-11, 22), Pair(-8, 28), Pair(-9, 30), Pair(-9, 22), Pair(-6, 35)
      },
      { // Piece 4
        Pair(-17, 18), Pair(-81, 29), Pair(20, -8), Pair(16, 72), Pair(1, 43), Pair(-146, 163), Pair(0, 107), Pair(-4, 23),
        Pair(4, 90), Pair(-8, 29), Pair(0, 0), Pair(-34, 98), Pair(1, 35), Pair(-50, 105), Pair(-60, 90), Pair(15, 22),
        Pair(24, 5), Pair(-160, -28), Pair(22, 58), Pair(-87, -30), Pair(8, 11), Pair(-28, 96), Pair(32, -1), Pair(3, 41),
        Pair(14, 50), Pair(-5, 36), Pair(52, -14), Pair(-17, 54), Pair(27, 29), Pair(13, 59), Pair(20, 16), Pair(9, 67),
        Pair(10, 21), Pair(-1, 37), Pair(-1, 52), Pair(-2, 52), Pair(13, 24), Pair(14, 7), Pair(4, 28), Pair(-2, 76),
        Pair(19, -18), Pair(-1, 38), Pair(3, 34), Pair(3, 25), Pair(9, 12), Pair(0, 29), Pair(10, 12), Pair(12, -1),
        Pair(-12, -13), Pair(3, 33), Pair(7, 42), Pair(-3, 48), Pair(-5, 39), Pair(0, 19), Pair(-8, 62), Pair(-42, -17),
        Pair(8, 14), Pair(6, 8), Pair(11, 2), Pair(1, 19), Pair(0, 78), Pair(7, -3), Pair(15, -14), Pair(29, -52)
      },
      { // Piece 5
        Pair(9, 39), Pair(-12, -10), Pair(23, -79), Pair(-9, -12), Pair(37, 10), Pair(-4, 32), Pair(72, 86), Pair(-41, -9),
        Pair(-56, -78), Pair(42, -101), Pair(0, 0), Pair(56, -102), Pair(-23, 17), Pair(-90, 43), Pair(-80, 53), Pair(-2, 9),
        Pair(-32, -71), Pair(0, 0), Pair(-127, -48), Pair(0, 0), Pair(29, -9), Pair(39, -46), Pair(-8, 16), Pair(-37, 6),
        Pair(-171, -59), Pair(-182, 2), Pair(-158, -25), Pair(-13, -13), Pair(-82, 10), Pair(27, -24), Pair(11, 35), Pair(-46, -34),
        Pair(84, -37), Pair(-152, 26), Pair(-93, 3), Pair(-4, -28), Pair(4, 0), Pair(-23, 5), Pair(-54, 21), Pair(20, 2),
        Pair(40, 5), Pair(-64, -1), Pair(-2, -15), Pair(-7, -8), Pair(26, -5), Pair(6, -2), Pair(-16, 5), Pair(-44, 11),
        Pair(4, -9), Pair(-14, -7), Pair(-24, 12), Pair(-9, 6), Pair(-7, 7), Pair(0, 3), Pair(-2, -6), Pair(0, 2),
        Pair(40, -38), Pair(5, -22), Pair(-6, 14), Pair(13, -9), Pair(6, 3), Pair(2, 13), Pair(0, -2), Pair(-2, -4)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(34, -6), Pair(-55, 36), Pair(-23, 47), Pair(0, 0), Pair(38, 57), Pair(49, 7), Pair(16, -78), Pair(19, 27),
        Pair(-11, 14), Pair(-12, 31), Pair(31, 23), Pair(-24, -13), Pair(-18, 77), Pair(7, 11), Pair(4, -16), Pair(-5, 20),
        Pair(-5, 8), Pair(-7, 12), Pair(7, 12), Pair(-2, -2), Pair(2, 15), Pair(-19, 13), Pair(-1, 7), Pair(5, 4),
        Pair(2, 5), Pair(-1, 2), Pair(9, -3), Pair(-3, -3), Pair(-5, 3), Pair(-7, 3), Pair(-9, 12), Pair(-1, 9),
        Pair(0, 8), Pair(-2, -1), Pair(3, -2), Pair(-2, 0), Pair(-6, 7), Pair(-4, 4), Pair(-6, 5), Pair(-4, 11),
        Pair(0, 2), Pair(3, -7), Pair(3, -13), Pair(0, 0), Pair(-1, -11), Pair(-4, 1), Pair(-6, 0), Pair(0, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(21, 61), Pair(-8, -92), Pair(-87, 96), Pair(-54, -88), Pair(2, 26), Pair(-16, -65), Pair(23, 50), Pair(63, -16),
        Pair(-37, -40), Pair(-37, 62), Pair(-2, 6), Pair(0, 0), Pair(-39, -24), Pair(-33, -55), Pair(14, -22), Pair(76, -29),
        Pair(-21, 18), Pair(28, 19), Pair(-338, -47), Pair(11, 38), Pair(-45, -10), Pair(-39, 20), Pair(-40, -11), Pair(-6, 34),
        Pair(32, 7), Pair(6, 12), Pair(6, 24), Pair(-8, 33), Pair(-18, 14), Pair(4, 21), Pair(15, -15), Pair(15, 23),
        Pair(20, -43), Pair(-59, 74), Pair(-16, 23), Pair(2, 20), Pair(-4, 9), Pair(14, 22), Pair(-51, 99), Pair(-4, 70),
        Pair(0, 15), Pair(12, 4), Pair(11, -14), Pair(14, -13), Pair(20, -7), Pair(0, -1), Pair(-6, 12), Pair(-8, 64),
        Pair(40, -106), Pair(6, 25), Pair(15, 31), Pair(9, 4), Pair(14, 1), Pair(28, -38), Pair(31, -97), Pair(-4, 54),
        Pair(-11, 13), Pair(5, 21), Pair(-35, -55), Pair(-49, 12), Pair(1, 38), Pair(-8, 63), Pair(6, 1), Pair(-34, 82)
      },
      { // Piece 2
        Pair(-24, -80), Pair(-80, 19), Pair(-25, -53), Pair(-17, -33), Pair(-33, -22), Pair(144, 50), Pair(29, 0), Pair(23, -60),
        Pair(-12, 110), Pair(-18, -9), Pair(-13, 26), Pair(0, 0), Pair(-88, 89), Pair(-80, 48), Pair(-19, 45), Pair(42, -84),
        Pair(-40, 44), Pair(9, -8), Pair(-219, -205), Pair(20, 74), Pair(-37, 21), Pair(-70, -26), Pair(21, 10), Pair(-3, -10),
        Pair(18, -9), Pair(-11, 22), Pair(-53, 39), Pair(10, -34), Pair(8, 7), Pair(-1, 32), Pair(-6, 10), Pair(-9, 33),
        Pair(-37, 59), Pair(-28, 64), Pair(-12, -13), Pair(-11, 81), Pair(9, -25), Pair(-1, 30), Pair(-16, 19), Pair(-10, 5),
        Pair(10, -4), Pair(2, -50), Pair(5, -13), Pair(2, -2), Pair(2, 7), Pair(1, 21), Pair(-14, 96), Pair(-12, 10),
        Pair(-8, -29), Pair(5, 26), Pair(-2, 23), Pair(1, 17), Pair(-6, 24), Pair(30, -7), Pair(12, -21), Pair(5, -54),
        Pair(18, 38), Pair(-32, 23), Pair(4, 18), Pair(-34, 86), Pair(16, -15), Pair(-14, 5), Pair(-16, -45), Pair(13, -45)
      },
      { // Piece 3
        Pair(-19, 26), Pair(-44, 28), Pair(111, -10), Pair(-63, -18), Pair(-6, 82), Pair(59, 18), Pair(-134, 113), Pair(-11, -19),
        Pair(-1, 23), Pair(28, -2), Pair(46, -32), Pair(0, 0), Pair(-103, 34), Pair(4, 58), Pair(18, -44), Pair(-3, 15),
        Pair(-32, 25), Pair(23, 8), Pair(-17, -15), Pair(61, -20), Pair(32, 37), Pair(-7, 19), Pair(18, 0), Pair(-10, 12),
        Pair(3, -17), Pair(-17, 18), Pair(-17, 21), Pair(39, -49), Pair(-38, 39), Pair(-32, -32), Pair(0, 0), Pair(6, -18),
        Pair(-2, 15), Pair(4, 8), Pair(-22, 7), Pair(30, -14), Pair(-27, 29), Pair(-10, 1), Pair(-27, 64), Pair(40, 19),
        Pair(-21, 37), Pair(16, 4), Pair(-1, 11), Pair(-12, 6), Pair(9, -36), Pair(12, 46), Pair(1, -7), Pair(-38, 24),
        Pair(-37, 27), Pair(1, -5), Pair(-7, 8), Pair(36, -46), Pair(-18, -28), Pair(13, -26), Pair(40, 15), Pair(15, -61),
        Pair(-8, 11), Pair(-13, -11), Pair(-9, -4), Pair(-8, 9), Pair(-11, 15), Pair(-6, 12), Pair(8, 0), Pair(4, 18)
      },
      { // Piece 4
        Pair(26, 78), Pair(21, -3), Pair(14, -124), Pair(17, -38), Pair(-51, 147), Pair(-44, 15), Pair(34, 76), Pair(109, 2),
        Pair(-18, 12), Pair(-41, 128), Pair(60, -70), Pair(0, 0), Pair(-79, 90), Pair(9, 129), Pair(-3, 73), Pair(33, 55),
        Pair(-44, 42), Pair(13, -16), Pair(24, 2), Pair(29, -9), Pair(17, 2), Pair(2, 120), Pair(89, -110), Pair(21, 29),
        Pair(-37, 47), Pair(19, -1), Pair(19, 46), Pair(13, -17), Pair(-11, 55), Pair(21, 27), Pair(-41, 26), Pair(13, -21),
        Pair(-6, 23), Pair(-13, 80), Pair(12, -53), Pair(8, 67), Pair(29, -1), Pair(45, -28), Pair(15, 28), Pair(20, -38),
        Pair(3, -13), Pair(-5, 38), Pair(-17, 31), Pair(19, -50), Pair(-2, -37), Pair(8, 1), Pair(-11, 53), Pair(0, 68),
        Pair(-13, -50), Pair(-8, 14), Pair(-4, 9), Pair(11, -17), Pair(-7, 31), Pair(19, -32), Pair(8, -35), Pair(113, -135),
        Pair(-22, 73), Pair(7, 17), Pair(-9, 82), Pair(4, 12), Pair(12, -37), Pair(-59, 105), Pair(67, 49), Pair(-107, -38)
      },
      { // Piece 5
        Pair(0, 0), Pair(4, -49), Pair(7, 35), Pair(2, 19), Pair(-1, 33), Pair(0, 6), Pair(0, -27), Pair(-29, -55),
        Pair(-2, -28), Pair(-19, -24), Pair(50, 65), Pair(0, 0), Pair(-11, -6), Pair(-2, -26), Pair(-32, -62), Pair(-59, -119),
        Pair(-40, -129), Pair(6, 22), Pair(0, 0), Pair(7, -96), Pair(0, 0), Pair(44, 30), Pair(88, 30), Pair(-7, 38),
        Pair(-35, -5), Pair(-17, 14), Pair(-75, -14), Pair(29, -79), Pair(-21, -20), Pair(106, -37), Pair(-96, -19), Pair(-46, -25),
        Pair(-107, -75), Pair(-34, -2), Pair(-11, -18), Pair(-23, -17), Pair(-56, -16), Pair(-82, 26), Pair(98, 1), Pair(80, 9),
        Pair(-66, 2), Pair(-55, 28), Pair(-16, 10), Pair(56, -17), Pair(2, -6), Pair(49, 0), Pair(22, -5), Pair(-52, 3),
        Pair(20, 7), Pair(-55, 72), Pair(-19, 32), Pair(40, -44), Pair(-2, 12), Pair(-14, 16), Pair(16, 0), Pair(-3, -3),
        Pair(24, -15), Pair(22, -27), Pair(-6, 12), Pair(14, 5), Pair(1, -20), Pair(-5, 40), Pair(-1, 17), Pair(7, 12)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, 30), Pair(32, 0), Pair(5, 24), Pair(30, -4), Pair(0, 0), Pair(-7, 40), Pair(-35, 28), Pair(-3, -13),
        Pair(-3, 8), Pair(7, 4), Pair(7, -4), Pair(4, 40), Pair(-31, -2), Pair(-23, 68), Pair(-6, -7), Pair(-8, 30),
        Pair(1, 6), Pair(1, 9), Pair(0, 9), Pair(11, 9), Pair(-11, 7), Pair(6, 1), Pair(8, 3), Pair(-2, 4),
        Pair(5, 1), Pair(2, 3), Pair(0, 8), Pair(5, -3), Pair(-2, -8), Pair(1, 1), Pair(2, 2), Pair(1, 1),
        Pair(1, -4), Pair(2, 3), Pair(-3, 3), Pair(-1, 6), Pair(-7, 1), Pair(-6, 4), Pair(1, 0), Pair(-1, 1),
        Pair(0, 4), Pair(0, 7), Pair(1, 5), Pair(3, 11), Pair(0, 0), Pair(-4, -2), Pair(2, -1), Pair(-1, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(11, 37), Pair(41, 2), Pair(-8, -78), Pair(-111, 113), Pair(-11, -19), Pair(-81, -65), Pair(-14, 16), Pair(67, -141),
        Pair(-23, 66), Pair(20, 29), Pair(-35, 62), Pair(19, 5), Pair(0, 0), Pair(-13, 68), Pair(-29, -66), Pair(-60, 14),
        Pair(69, 33), Pair(-15, 79), Pair(-31, 19), Pair(-3, 11), Pair(-17, 61), Pair(-357, 175), Pair(13, -1), Pair(-1, -28),
        Pair(33, -13), Pair(-9, 19), Pair(-3, 42), Pair(-20, 4), Pair(-7, 22), Pair(-10, -29), Pair(1, 24), Pair(-40, 12),
        Pair(6, 29), Pair(-31, 18), Pair(-11, 35), Pair(-19, 32), Pair(7, 0), Pair(8, 12), Pair(-13, 17), Pair(14, 24),
        Pair(5, -7), Pair(-15, 51), Pair(-4, -4), Pair(-11, 22), Pair(-12, 15), Pair(-1, 9), Pair(-8, 11), Pair(-12, 53),
        Pair(-5, 7), Pair(3, 19), Pair(18, -21), Pair(-4, 6), Pair(-4, 15), Pair(-8, -36), Pair(23, -14), Pair(21, 4),
        Pair(-90, -21), Pair(2, -9), Pair(-5, 4), Pair(-10, 25), Pair(38, 18), Pair(-19, 13), Pair(-1, 50), Pair(-57, -10)
      },
      { // Piece 2
        Pair(28, -28), Pair(66, -12), Pair(-10, 56), Pair(61, -39), Pair(-21, 99), Pair(-55, -10), Pair(2, 11), Pair(-98, 98),
        Pair(-23, 44), Pair(33, -2), Pair(-6, 18), Pair(-38, 84), Pair(0, 0), Pair(-78, 71), Pair(-2, 23), Pair(-122, 39),
        Pair(2, 54), Pair(-16, 59), Pair(-26, 29), Pair(-264, 80), Pair(11, 56), Pair(-261, 114), Pair(36, 38), Pair(7, 13),
        Pair(-30, 48), Pair(11, 36), Pair(12, 7), Pair(-28, 1), Pair(8, 25), Pair(-47, 73), Pair(7, 2), Pair(5, 30),
        Pair(20, -7), Pair(13, 9), Pair(-11, 27), Pair(-36, 35), Pair(-7, 23), Pair(-16, 13), Pair(7, 25), Pair(-11, 44),
        Pair(7, -10), Pair(-18, 21), Pair(-7, 29), Pair(-5, 41), Pair(-6, 11), Pair(-15, 54), Pair(-1, -17), Pair(17, 0),
        Pair(-22, -22), Pair(-4, 13), Pair(-3, 29), Pair(-4, 22), Pair(6, 16), Pair(2, 29), Pair(-4, 34), Pair(-13, 20),
        Pair(-18, 8), Pair(13, -26), Pair(-4, 24), Pair(22, 16), Pair(-12, 21), Pair(2, 11), Pair(-7, -16), Pair(18, 22)
      },
      { // Piece 3
        Pair(26, -16), Pair(-50, 32), Pair(-70, 53), Pair(13, 32), Pair(-10, 9), Pair(35, 8), Pair(29, 25), Pair(22, 39),
        Pair(16, -5), Pair(-12, 18), Pair(-32, 11), Pair(-54, 28), Pair(0, 0), Pair(-48, 12), Pair(-58, 53), Pair(-29, 45),
        Pair(53, 2), Pair(14, -2), Pair(18, -2), Pair(-96, 2), Pair(49, 12), Pair(82, 5), Pair(-18, 21), Pair(31, -4),
        Pair(-1, 37), Pair(-5, 8), Pair(21, -17), Pair(0, -2), Pair(30, -22), Pair(-55, 17), Pair(-44, 9), Pair(21, 5),
        Pair(-17, 18), Pair(1, 31), Pair(-27, 21), Pair(-33, 2), Pair(15, -21), Pair(12, 10), Pair(-25, 0), Pair(-12, 0),
        Pair(-37, 62), Pair(-19, 23), Pair(-4, -20), Pair(7, -7), Pair(-6, -4), Pair(20, -45), Pair(3, 27), Pair(-68, 39),
        Pair(1, 15), Pair(0, 2), Pair(-12, 19), Pair(-25, 22), Pair(-3, 1), Pair(8, 5), Pair(26, -22), Pair(24, -18),
        Pair(5, -5), Pair(-7, 10), Pair(10, 0), Pair(-1, 0), Pair(2, 19), Pair(1, 8), Pair(-8, -5), Pair(4, 10)
      },
      { // Piece 4
        Pair(15, 47), Pair(4, 35), Pair(44, 39), Pair(24, -60), Pair(-79, -36), Pair(24, 54), Pair(87, 17), Pair(-64, 115),
        Pair(40, -55), Pair(10, 21), Pair(35, -84), Pair(70, -77), Pair(0, 0), Pair(28, 38), Pair(38, -123), Pair(7, -41),
        Pair(19, -80), Pair(-12, 68), Pair(30, 54), Pair(16, 3), Pair(46, 53), Pair(12, 4), Pair(4, 64), Pair(3, 44),
        Pair(-23, 36), Pair(-11, 78), Pair(17, -65), Pair(8, 12), Pair(41, -31), Pair(22, 10), Pair(12, 31), Pair(15, -12),
        Pair(-12, 22), Pair(-9, 67), Pair(-5, 56), Pair(20, -29), Pair(16, -8), Pair(-7, 76), Pair(-39, 53), Pair(9, -48),
        Pair(20, 14), Pair(-5, 13), Pair(-14, 56), Pair(-13, 28), Pair(8, 4), Pair(7, 11), Pair(-5, 22), Pair(22, -51),
        Pair(16, -37), Pair(-10, 20), Pair(-3, 9), Pair(-4, 4), Pair(7, -26), Pair(4, -15), Pair(6, -38), Pair(-4, 2),
        Pair(-8, 92), Pair(3, 14), Pair(5, 12), Pair(1, 4), Pair(21, -5), Pair(42, 17), Pair(-1, -92), Pair(44, -20)
      },
      { // Piece 5
        Pair(7, 89), Pair(1, 7), Pair(-9, -34), Pair(12, 58), Pair(-7, -33), Pair(-6, -81), Pair(25, 101), Pair(0, 0),
        Pair(7, 39), Pair(-25, -1), Pair(-26, -162), Pair(-29, -96), Pair(0, 0), Pair(25, -75), Pair(-53, -55), Pair(-5, 42),
        Pair(-9, 16), Pair(-2, -6), Pair(-17, -32), Pair(0, 0), Pair(83, -106), Pair(0, 0), Pair(-30, -31), Pair(106, -33),
        Pair(27, -9), Pair(-51, 17), Pair(-113, -10), Pair(-48, -63), Pair(54, 14), Pair(95, -22), Pair(-145, 31), Pair(-83, 19),
        Pair(-79, 45), Pair(-27, 55), Pair(-15, 18), Pair(-87, -3), Pair(-15, 1), Pair(-16, 6), Pair(-4, 5), Pair(-144, 29),
        Pair(66, 17), Pair(-33, 3), Pair(1, 16), Pair(47, -26), Pair(42, -14), Pair(-13, 3), Pair(1, 5), Pair(-38, 47),
        Pair(-66, 42), Pair(-43, 40), Pair(-64, 52), Pair(2, -4), Pair(-14, 16), Pair(28, 0), Pair(-3, 3), Pair(5, 7),
        Pair(-28, 34), Pair(-6, -7), Pair(-12, 1), Pair(16, -10), Pair(5, -11), Pair(0, 8), Pair(1, 1), Pair(3, 12)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, 12), Pair(-7, 17), Pair(11, 1), Pair(-14, 22), Pair(5, 16), Pair(0, 0), Pair(-48, 22), Pair(-28, 0),
        Pair(7, 4), Pair(16, 4), Pair(7, 1), Pair(1, 1), Pair(13, 27), Pair(-8, 5), Pair(12, 13), Pair(-1, 6),
        Pair(2, 3), Pair(3, 3), Pair(2, 8), Pair(4, 2), Pair(4, 13), Pair(-8, 1), Pair(2, 4), Pair(3, 0),
        Pair(8, 5), Pair(3, 4), Pair(7, 3), Pair(1, -2), Pair(3, 4), Pair(-5, -4), Pair(3, -3), Pair(-3, 3),
        Pair(2, 2), Pair(6, 1), Pair(4, 1), Pair(3, 1), Pair(1, 3), Pair(-4, 5), Pair(-2, 1), Pair(-3, 2),
        Pair(4, 2), Pair(2, 1), Pair(3, 0), Pair(3, -2), Pair(4, 3), Pair(0, 0), Pair(-3, -4), Pair(-3, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-10, 21), Pair(-27, 44), Pair(-36, 40), Pair(-90, 35), Pair(51, 37), Pair(-101, -60), Pair(32, 97), Pair(-114, -48),
        Pair(17, 37), Pair(19, 7), Pair(30, 10), Pair(-37, 36), Pair(-6, 44), Pair(0, 0), Pair(3, 6), Pair(42, 43),
        Pair(-84, 51), Pair(13, 23), Pair(10, 22), Pair(-1, 9), Pair(-213, 51), Pair(36, 45), Pair(-83, 77), Pair(-20, 30),
        Pair(6, 7), Pair(7, 25), Pair(5, 30), Pair(-4, 40), Pair(-32, 17), Pair(9, 43), Pair(-10, -8), Pair(16, 24),
        Pair(5, 5), Pair(-4, 24), Pair(6, 23), Pair(-2, 30), Pair(-27, 28), Pair(-7, 26), Pair(5, 31), Pair(-5, 25),
        Pair(8, 36), Pair(-3, 26), Pair(4, 28), Pair(-7, 18), Pair(3, 31), Pair(-2, 23), Pair(-6, 38), Pair(-15, 9),
        Pair(10, 3), Pair(2, 51), Pair(2, 41), Pair(1, 25), Pair(-3, 20), Pair(1, 45), Pair(-1, 37), Pair(6, 31),
        Pair(-54, -10), Pair(6, 30), Pair(-11, 22), Pair(7, 25), Pair(-7, 33), Pair(13, 12), Pair(-8, 19), Pair(40, -116)
      },
      { // Piece 2
        Pair(-48, 53), Pair(38, 33), Pair(-118, 44), Pair(-63, 85), Pair(-100, 43), Pair(-27, 21), Pair(-149, -45), Pair(-89, 93),
        Pair(-39, 67), Pair(-20, 46), Pair(-16, 58), Pair(-65, 52), Pair(-20, 51), Pair(0, 0), Pair(1, 54), Pair(8, 7),
        Pair(-20, 30), Pair(-9, 50), Pair(-44, 43), Pair(-5, 52), Pair(-80, -64), Pair(52, 72), Pair(-126, 57), Pair(-2, 52),
        Pair(8, 28), Pair(-9, 35), Pair(-21, 53), Pair(-13, 23), Pair(-29, 44), Pair(-12, 27), Pair(-10, 39), Pair(2, 9),
        Pair(-19, 36), Pair(3, 39), Pair(-17, 29), Pair(-4, 34), Pair(-36, 28), Pair(5, 37), Pair(-34, 29), Pair(28, 24),
        Pair(7, 43), Pair(-12, 34), Pair(3, 31), Pair(-10, 20), Pair(-2, 40), Pair(-14, 34), Pair(-2, 45), Pair(-14, 17),
        Pair(-17, 24), Pair(6, 24), Pair(-16, 26), Pair(3, 31), Pair(-12, 27), Pair(-4, 44), Pair(-9, 16), Pair(-6, 60),
        Pair(-11, 36), Pair(-14, 53), Pair(3, 40), Pair(-3, 23), Pair(15, 24), Pair(-9, 28), Pair(-13, 71), Pair(-10, 32)
      },
      { // Piece 3
        Pair(-26, 50), Pair(-30, 52), Pair(-20, 51), Pair(-24, 43), Pair(-2, 44), Pair(-141, 71), Pair(-35, 61), Pair(28, 26),
        Pair(-1, 37), Pair(5, 26), Pair(8, 35), Pair(-3, 35), Pair(-24, 54), Pair(0, 0), Pair(-15, 32), Pair(46, 13),
        Pair(11, 37), Pair(-16, 35), Pair(-4, 41), Pair(23, 25), Pair(-127, 28), Pair(43, 20), Pair(19, 24), Pair(-9, 39),
        Pair(9, 31), Pair(-9, 32), Pair(5, 44), Pair(-17, 54), Pair(-13, 39), Pair(16, 30), Pair(0, 44), Pair(-15, 45),
        Pair(1, 40), Pair(6, 42), Pair(17, 23), Pair(-17, 33), Pair(-13, 19), Pair(9, 24), Pair(11, 25), Pair(-13, 37),
        Pair(-3, 35), Pair(11, 30), Pair(-2, 40), Pair(-2, 32), Pair(-10, 36), Pair(4, 39), Pair(19, 17), Pair(4, 35),
        Pair(5, 36), Pair(12, 27), Pair(-5, 48), Pair(16, 29), Pair(-1, 28), Pair(23, 16), Pair(24, 6), Pair(-27, 45),
        Pair(9, 36), Pair(1, 34), Pair(8, 27), Pair(7, 31), Pair(7, 24), Pair(5, 36), Pair(-4, 28), Pair(3, 27)
      },
      { // Piece 4
        Pair(13, 2), Pair(56, -12), Pair(23, 15), Pair(-51, 72), Pair(-41, 25), Pair(-6, -17), Pair(-66, 169), Pair(-14, 58),
        Pair(2, 57), Pair(-9, 49), Pair(3, 37), Pair(31, -5), Pair(0, -34), Pair(0, 0), Pair(-96, 159), Pair(-21, 93),
        Pair(-10, 54), Pair(2, 54), Pair(14, 33), Pair(23, -2), Pair(-62, -9), Pair(22, 42), Pair(-18, 54), Pair(13, 81),
        Pair(5, 15), Pair(27, 15), Pair(-3, 67), Pair(15, 22), Pair(4, 53), Pair(17, 27), Pair(39, 24), Pair(17, 32),
        Pair(2, 9), Pair(14, 32), Pair(0, 43), Pair(16, 47), Pair(2, 46), Pair(25, 17), Pair(9, 65), Pair(11, 44),
        Pair(1, 36), Pair(0, 33), Pair(3, 25), Pair(-6, 58), Pair(7, 25), Pair(20, 7), Pair(14, 49), Pair(18, 51),
        Pair(4, 27), Pair(6, 31), Pair(2, 33), Pair(-4, 43), Pair(0, 38), Pair(16, 17), Pair(-2, 68), Pair(45, 13),
        Pair(7, 15), Pair(-8, 37), Pair(15, 28), Pair(5, 21), Pair(15, 32), Pair(-13, 37), Pair(38, 7), Pair(-3, 101)
      },
      { // Piece 5
        Pair(30, -47), Pair(3, -46), Pair(81, 16), Pair(-35, -47), Pair(-75, -43), Pair(15, -102), Pair(-56, -60), Pair(-45, -120),
        Pair(66, -43), Pair(14, -22), Pair(-106, -13), Pair(52, -20), Pair(-14, -70), Pair(0, 0), Pair(-12, -63), Pair(-38, -20),
        Pair(64, -32), Pair(-146, 32), Pair(-8, -24), Pair(-41, 1), Pair(0, 0), Pair(-147, -42), Pair(0, 0), Pair(48, -38),
        Pair(-5, 5), Pair(-16, -7), Pair(37, -16), Pair(-103, 0), Pair(-76, -11), Pair(-34, -33), Pair(-43, -24), Pair(-112, 2),
        Pair(20, -19), Pair(55, -7), Pair(49, -14), Pair(-40, 8), Pair(-39, -6), Pair(-38, -4), Pair(-44, -5), Pair(-12, -7),
        Pair(39, -11), Pair(27, -7), Pair(39, 3), Pair(33, -3), Pair(-42, 4), Pair(9, -4), Pair(-20, -5), Pair(-5, 7),
        Pair(9, 8), Pair(-9, 2), Pair(-9, 4), Pair(8, 1), Pair(-7, 7), Pair(7, -4), Pair(-8, 5), Pair(5, 3),
        Pair(-8, 11), Pair(-11, -1), Pair(-6, 7), Pair(4, 4), Pair(-3, -4), Pair(-15, 12), Pair(-6, -6), Pair(18, -11)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-2, 25), Pair(23, 3), Pair(-28, 25), Pair(1, 11), Pair(37, -16), Pair(-60, 46), Pair(0, 0), Pair(-20, -13),
        Pair(14, 4), Pair(5, 7), Pair(13, -2), Pair(-10, 8), Pair(-8, 5), Pair(-15, 14), Pair(-2, 1), Pair(0, 30),
        Pair(2, 6), Pair(7, 5), Pair(6, 4), Pair(-3, 5), Pair(-2, 0), Pair(0, 12), Pair(5, -3), Pair(12, 9),
        Pair(3, 4), Pair(4, 4), Pair(3, 2), Pair(-1, 3), Pair(1, 2), Pair(1, 6), Pair(-4, -1), Pair(-1, 6),
        Pair(3, 1), Pair(3, 0), Pair(0, 1), Pair(0, 1), Pair(1, -1), Pair(2, 7), Pair(-1, 1), Pair(-4, 4),
        Pair(2, 3), Pair(4, 0), Pair(-2, 2), Pair(5, 0), Pair(-3, 0), Pair(2, 3), Pair(0, 0), Pair(-5, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-12, 12), Pair(-146, 63), Pair(-82, 7), Pair(-158, 47), Pair(-120, 4), Pair(-9, 60), Pair(-13, 11), Pair(-55, 52),
        Pair(9, 5), Pair(2, 26), Pair(14, 16), Pair(-23, 14), Pair(-31, 16), Pair(52, -10), Pair(0, 0), Pair(-6, -41),
        Pair(-22, -5), Pair(11, 19), Pair(-6, 10), Pair(5, 21), Pair(-1, 12), Pair(-435, 172), Pair(27, 23), Pair(-33, 46),
        Pair(1, 8), Pair(10, 6), Pair(-4, 24), Pair(18, 16), Pair(11, 17), Pair(-33, 21), Pair(-2, 36), Pair(-13, -19),
        Pair(-6, 24), Pair(1, 12), Pair(-1, 26), Pair(-6, 28), Pair(16, 13), Pair(-21, 7), Pair(23, 9), Pair(-18, 31),
        Pair(-1, 12), Pair(-2, 17), Pair(-1, 23), Pair(-4, 15), Pair(-5, 15), Pair(1, 12), Pair(0, 19), Pair(1, 18),
        Pair(1, -9), Pair(0, 0), Pair(1, 18), Pair(-1, 17), Pair(-1, 10), Pair(-6, -11), Pair(4, 9), Pair(-8, 23),
        Pair(-7, -35), Pair(-2, 11), Pair(20, -4), Pair(-4, 15), Pair(20, 3), Pair(4, 19), Pair(-2, 8), Pair(-41, -23)
      },
      { // Piece 2
        Pair(-27, 101), Pair(67, 17), Pair(-21, 43), Pair(-88, 34), Pair(-34, 58), Pair(-43, 11), Pair(73, 38), Pair(0, 0),
        Pair(-57, 39), Pair(17, 33), Pair(-19, 46), Pair(-24, 61), Pair(-83, 45), Pair(-29, 56), Pair(0, 0), Pair(-3, 5),
        Pair(4, 46), Pair(-20, 27), Pair(14, 41), Pair(-29, 34), Pair(-4, 48), Pair(-221, 64), Pair(20, 55), Pair(-27, 30),
        Pair(-12, 15), Pair(16, 36), Pair(-14, 26), Pair(0, 45), Pair(-7, -1), Pair(-32, 40), Pair(11, 16), Pair(-29, 40),
        Pair(0, 30), Pair(-12, 30), Pair(-1, 43), Pair(-5, 14), Pair(3, 24), Pair(-17, 12), Pair(-11, 37), Pair(-49, 35),
        Pair(-12, 7), Pair(12, 33), Pair(-13, 17), Pair(0, 32), Pair(-10, 20), Pair(5, 33), Pair(-7, 21), Pair(-2, 46),
        Pair(-13, 89), Pair(-13, 6), Pair(10, 35), Pair(-14, 13), Pair(8, 28), Pair(-24, 29), Pair(8, 40), Pair(-16, 14),
        Pair(-22, 23), Pair(12, 17), Pair(-6, 13), Pair(-9, 32), Pair(-32, 24), Pair(9, 28), Pair(25, 7), Pair(-28, 84)
      },
      { // Piece 3
        Pair(12, 31), Pair(21, 37), Pair(-34, 61), Pair(-17, 37), Pair(43, 25), Pair(1, 42), Pair(108, 6), Pair(-56, 64),
        Pair(-15, 42), Pair(4, 26), Pair(0, 38), Pair(-6, 41), Pair(-22, 44), Pair(-71, 40), Pair(0, 0), Pair(45, 7),
        Pair(-2, 36), Pair(9, 31), Pair(3, 37), Pair(-5, 36), Pair(-18, 30), Pair(35, -41), Pair(7, 44), Pair(247, -61),
        Pair(16, 32), Pair(-16, 43), Pair(5, 37), Pair(15, 32), Pair(-8, 28), Pair(-18, 39), Pair(-14, 38), Pair(-5, 33),
        Pair(-11, 28), Pair(-27, 46), Pair(-2, 29), Pair(-11, 41), Pair(0, 16), Pair(-3, 9), Pair(12, 14), Pair(14, -3),
        Pair(-5, 38), Pair(6, 32), Pair(-13, 30), Pair(-6, 35), Pair(-7, 27), Pair(5, 25), Pair(5, 26), Pair(-8, 20),
        Pair(-7, 41), Pair(16, 38), Pair(-4, 37), Pair(6, 26), Pair(4, 33), Pair(4, 23), Pair(4, 15), Pair(16, 3),
        Pair(10, 32), Pair(5, 27), Pair(-2, 37), Pair(4, 31), Pair(0, 27), Pair(3, 23), Pair(7, 19), Pair(-6, 26)
      },
      { // Piece 4
        Pair(-18, 67), Pair(-79, 79), Pair(-65, 96), Pair(-35, 42), Pair(-10, 46), Pair(8, 56), Pair(-53, 22), Pair(2, -20),
        Pair(-4, 15), Pair(-9, 13), Pair(-29, 50), Pair(-14, 38), Pair(-29, 43), Pair(28, -18), Pair(0, 0), Pair(67, -52),
        Pair(-9, 32), Pair(27, 3), Pair(-17, 37), Pair(-13, 44), Pair(17, -4), Pair(18, -58), Pair(30, -38), Pair(-36, -53),
        Pair(-10, 33), Pair(-1, 35), Pair(-10, 66), Pair(-8, 51), Pair(-9, 36), Pair(-20, 57), Pair(7, 4), Pair(-5, 36),
        Pair(-3, 25), Pair(-16, 44), Pair(-8, 34), Pair(-1, 47), Pair(-11, 54), Pair(6, 28), Pair(-4, 16), Pair(16, -3),
        Pair(-9, 45), Pair(-6, 30), Pair(-6, 31), Pair(-12, 46), Pair(-15, 25), Pair(-2, 35), Pair(4, 5), Pair(15, 27),
        Pair(1, -16), Pair(-17, 32), Pair(-7, 15), Pair(-8, 44), Pair(-7, 28), Pair(-2, 19), Pair(0, 4), Pair(-13, 78),
        Pair(-8, 21), Pair(3, 13), Pair(-2, 20), Pair(-2, 17), Pair(-6, 30), Pair(-13, 58), Pair(22, -50), Pair(32, 23)
      },
      { // Piece 5
        Pair(-88, -17), Pair(28, 49), Pair(7, -31), Pair(1, 31), Pair(50, -51), Pair(47, -13), Pair(73, -8), Pair(8, 27),
        Pair(-108, -19), Pair(36, -32), Pair(-30, -3), Pair(-39, 18), Pair(57, -10), Pair(17, -50), Pair(0, 0), Pair(-5, -90),
        Pair(1, -6), Pair(85, -28), Pair(122, -26), Pair(52, 6), Pair(2, -2), Pair(0, 0), Pair(27, -71), Pair(0, 0),
        Pair(-96, 34), Pair(92, -9), Pair(39, -19), Pair(-34, 0), Pair(-178, 10), Pair(-62, -11), Pair(-30, -23), Pair(-68, 5),
        Pair(-31, 21), Pair(60, -8), Pair(16, -2), Pair(-44, 0), Pair(4, -12), Pair(-9, -9), Pair(-59, 5), Pair(-30, -2),
        Pair(17, 11), Pair(-22, -11), Pair(43, -12), Pair(39, -9), Pair(-5, 2), Pair(5, -4), Pair(-5, -4), Pair(-22, 7),
        Pair(11, -18), Pair(-17, 2), Pair(0, -3), Pair(13, -7), Pair(6, 2), Pair(13, 2), Pair(-4, 0), Pair(-5, 5),
        Pair(-24, 10), Pair(-3, -13), Pair(-3, -2), Pair(0, 13), Pair(5, -1), Pair(-7, 6), Pair(-3, 7), Pair(-6, -2)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(23, 4), Pair(16, -7), Pair(44, 16), Pair(-7, 17), Pair(26, -11), Pair(-9, -2), Pair(-45, 17), Pair(0, 0),
        Pair(8, 6), Pair(-4, 3), Pair(10, 5), Pair(11, -2), Pair(-7, 7), Pair(-16, 4), Pair(-16, 37), Pair(10, -9),
        Pair(1, 4), Pair(2, 4), Pair(4, 1), Pair(-2, 3), Pair(-7, 3), Pair(-5, -1), Pair(-1, 1), Pair(9, -4),
        Pair(4, 2), Pair(3, 0), Pair(2, -2), Pair(0, -1), Pair(-1, 3), Pair(-2, 1), Pair(2, -1), Pair(0, -3),
        Pair(-1, 0), Pair(1, -2), Pair(1, -3), Pair(-2, -6), Pair(3, -1), Pair(6, -1), Pair(2, -1), Pair(-1, -1),
        Pair(-1, 1), Pair(0, -2), Pair(-2, -5), Pair(0, -5), Pair(0, 1), Pair(4, -2), Pair(3, -2), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-34, -5), Pair(-47, -16), Pair(12, -13), Pair(102, 21), Pair(-36, 53), Pair(-103, 8), Pair(31, 86), Pair(-33, -136),
        Pair(-18, 56), Pair(-9, -12), Pair(-29, 17), Pair(42, 9), Pair(-22, 40), Pair(-38, 35), Pair(11, -9), Pair(0, 0),
        Pair(41, -8), Pair(13, -9), Pair(19, 11), Pair(4, 22), Pair(10, 2), Pair(30, -3), Pair(-124, -141), Pair(1, 47),
        Pair(7, 18), Pair(2, 12), Pair(15, 9), Pair(16, 7), Pair(9, 27), Pair(10, 25), Pair(-8, 16), Pair(16, 24),
        Pair(2, 22), Pair(20, -1), Pair(1, 14), Pair(8, 16), Pair(14, 25), Pair(23, 18), Pair(-6, 27), Pair(-2, -4),
        Pair(-7, 25), Pair(4, 8), Pair(7, 15), Pair(-3, 15), Pair(10, 12), Pair(3, 18), Pair(13, 29), Pair(5, 44),
        Pair(11, 8), Pair(6, 26), Pair(-18, 22), Pair(-1, 12), Pair(4, 14), Pair(1, 10), Pair(-10, 46), Pair(6, 19),
        Pair(35, -37), Pair(-4, 27), Pair(-19, 25), Pair(2, 6), Pair(-2, 22), Pair(-9, 17), Pair(-7, 16), Pair(19, 44)
      },
      { // Piece 2
        Pair(-10, 31), Pair(-9, 78), Pair(-55, 91), Pair(-22, 27), Pair(-53, 11), Pair(-26, 76), Pair(-12, 36), Pair(16, 4),
        Pair(5, 49), Pair(10, 37), Pair(-23, 40), Pair(-22, 79), Pair(-55, 44), Pair(11, 11), Pair(-25, 38), Pair(0, 0),
        Pair(-10, 25), Pair(-12, 38), Pair(-9, 35), Pair(-1, 52), Pair(7, 36), Pair(2, 48), Pair(-8, -101), Pair(10, 61),
        Pair(-39, 47), Pair(-5, 36), Pair(-9, 33), Pair(-1, 44), Pair(11, 45), Pair(-1, 33), Pair(-18, 41), Pair(3, 36),
        Pair(-8, 19), Pair(-27, 47), Pair(-3, 40), Pair(0, 30), Pair(1, 27), Pair(-1, 36), Pair(11, 8), Pair(-2, 27),
        Pair(3, 48), Pair(16, 31), Pair(6, 41), Pair(-9, 34), Pair(4, 35), Pair(2, 34), Pair(7, 34), Pair(10, 24),
        Pair(15, 32), Pair(7, 25), Pair(-12, 13), Pair(-5, 27), Pair(-3, 36), Pair(5, 29), Pair(10, 31), Pair(16, -17),
        Pair(3, 27), Pair(-12, 30), Pair(0, 27), Pair(-12, 30), Pair(-7, 7), Pair(2, 26), Pair(-7, 12), Pair(10, 27)
      },
      { // Piece 3
        Pair(42, 41), Pair(-17, 68), Pair(-16, 53), Pair(-22, 68), Pair(-23, 56), Pair(30, 50), Pair(-13, 73), Pair(-143, 108),
        Pair(9, 64), Pair(-1, 63), Pair(9, 49), Pair(21, 52), Pair(22, 41), Pair(9, 65), Pair(25, 29), Pair(0, 0),
        Pair(1, 55), Pair(-8, 53), Pair(10, 55), Pair(20, 50), Pair(14, 60), Pair(-23, 79), Pair(-101, -120), Pair(-34, 75),
        Pair(9, 54), Pair(31, 47), Pair(14, 50), Pair(12, 38), Pair(18, 53), Pair(-6, 48), Pair(-14, 71), Pair(-7, 44),
        Pair(7, 54), Pair(8, 57), Pair(11, 44), Pair(-13, 51), Pair(9, 49), Pair(-3, 56), Pair(-30, 56), Pair(-22, 52),
        Pair(5, 42), Pair(13, 41), Pair(19, 41), Pair(15, 41), Pair(-5, 44), Pair(5, 39), Pair(12, 47), Pair(-26, 65),
        Pair(31, 23), Pair(8, 46), Pair(10, 46), Pair(3, 58), Pair(4, 53), Pair(12, 37), Pair(-2, 58), Pair(-35, 59),
        Pair(10, 54), Pair(2, 58), Pair(11, 58), Pair(7, 47), Pair(3, 52), Pair(8, 49), Pair(-19, 60), Pair(-7, 47)
      },
      { // Piece 4
        Pair(-24, 87), Pair(11, 92), Pair(42, 42), Pair(-56, 111), Pair(-3, 70), Pair(-71, 124), Pair(186, -13), Pair(-55, 92),
        Pair(-7, 91), Pair(-2, 77), Pair(24, 44), Pair(-42, 106), Pair(-26, 137), Pair(-2, 68), Pair(-20, 91), Pair(0, 0),
        Pair(19, 58), Pair(4, 65), Pair(-1, 81), Pair(-18, 90), Pair(-25, 156), Pair(-3, 109), Pair(12, 31), Pair(10, 31),
        Pair(-12, 63), Pair(-1, 88), Pair(-10, 100), Pair(-1, 101), Pair(-16, 124), Pair(0, 89), Pair(-26, 115), Pair(-4, 72),
        Pair(-5, 67), Pair(-8, 94), Pair(-9, 71), Pair(9, 102), Pair(-9, 109), Pair(2, 96), Pair(4, 48), Pair(-8, 93),
        Pair(1, 81), Pair(-1, 69), Pair(15, 58), Pair(3, 72), Pair(-3, 77), Pair(-11, 79), Pair(3, 71), Pair(9, 74),
        Pair(11, 61), Pair(12, 37), Pair(3, 41), Pair(9, 37), Pair(2, 61), Pair(13, 67), Pair(25, -8), Pair(38, -8),
        Pair(3, 29), Pair(-2, 56), Pair(8, 67), Pair(7, 59), Pair(13, 43), Pair(-17, 76), Pair(0, 77), Pair(7, 79)
      },
      { // Piece 5
        Pair(-49, 66), Pair(41, 13), Pair(72, -112), Pair(-44, -95), Pair(-31, 67), Pair(55, -15), Pair(-18, -11), Pair(5, 12),
        Pair(-102, -39), Pair(72, -77), Pair(-74, 41), Pair(-56, 8), Pair(73, -25), Pair(-130, -48), Pair(-40, -73), Pair(0, 0),
        Pair(3, -4), Pair(-2, 16), Pair(-24, 4), Pair(44, -39), Pair(-50, -1), Pair(-78, -19), Pair(0, 0), Pair(72, -37),
        Pair(49, -7), Pair(12, -9), Pair(-6, -10), Pair(-29, 5), Pair(11, -8), Pair(-106, -16), Pair(-84, 6), Pair(-124, 32),
        Pair(-37, 14), Pair(103, -26), Pair(39, -14), Pair(-5, -5), Pair(12, 1), Pair(-8, 5), Pair(-29, -7), Pair(-19, -11),
        Pair(-42, 21), Pair(46, -27), Pair(16, -17), Pair(28, -3), Pair(44, -12), Pair(-26, 13), Pair(-13, 4), Pair(-20, -2),
        Pair(-1, -17), Pair(18, -17), Pair(35, -12), Pair(-13, 6), Pair(-4, 4), Pair(8, 7), Pair(-12, 14), Pair(-16, 12),
        Pair(4, -13), Pair(-9, 0), Pair(0, -1), Pair(31, -9), Pair(7, -1), Pair(-1, 8), Pair(1, 12), Pair(-5, 26)
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
        Pair(-18, 18), Pair(-107, 60), Pair(23, 20), Pair(-8, 17), Pair(55, 67), Pair(-72, 19), Pair(-13, 56), Pair(36, 44),
        Pair(59, -85), Pair(-67, 42), Pair(-51, 63), Pair(-18, 18), Pair(-62, 71), Pair(-2, 46), Pair(31, 5), Pair(-9, 22),
        Pair(-24, 5), Pair(-9, 26), Pair(19, -5), Pair(-16, 31), Pair(31, 9), Pair(-31, 6), Pair(-18, 6), Pair(75, -19),
        Pair(-9, -10), Pair(-31, 32), Pair(-35, 25), Pair(25, -4), Pair(-24, 5), Pair(-12, 11), Pair(6, 16), Pair(3, 7),
        Pair(54, 11), Pair(-13, 12), Pair(17, -11), Pair(-11, 5), Pair(15, 5), Pair(4, -4), Pair(-32, 19), Pair(-7, 16),
        Pair(9, -6), Pair(-13, 28), Pair(-5, 28), Pair(-33, -9), Pair(-14, 26), Pair(-2, 6), Pair(-11, 19), Pair(-19, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, 29), Pair(16, 74), Pair(83, 27), Pair(-17, 29), Pair(40, -10), Pair(-11, 23), Pair(12, 96), Pair(-1, -5),
        Pair(0, 0), Pair(-32, -15), Pair(-36, -66), Pair(-24, -67), Pair(-1, 97), Pair(-41, -83), Pair(26, 122), Pair(-70, -77),
        Pair(85, 47), Pair(-71, 72), Pair(42, -16), Pair(54, 0), Pair(113, -31), Pair(98, -70), Pair(44, -21), Pair(9, 35),
        Pair(-48, 89), Pair(14, 1), Pair(49, -27), Pair(-35, 101), Pair(43, -9), Pair(19, -37), Pair(-34, -47), Pair(107, -24),
        Pair(-72, 44), Pair(32, 24), Pair(4, -54), Pair(62, 46), Pair(94, -39), Pair(62, -6), Pair(18, -44), Pair(64, -130),
        Pair(-8, -63), Pair(52, -58), Pair(-86, 38), Pair(194, -60), Pair(-115, -17), Pair(121, -97), Pair(57, 10), Pair(48, -99),
        Pair(-58, 2), Pair(-64, 41), Pair(16, -26), Pair(-57, -21), Pair(-139, 13), Pair(-5, -16), Pair(98, 30), Pair(84, -91),
        Pair(-65, -18), Pair(79, -36), Pair(12, 25), Pair(-49, 28), Pair(103, 47), Pair(34, -136), Pair(-99, 52), Pair(16, -92)
      },
      { // Piece 2
        Pair(-26, -62), Pair(104, 25), Pair(32, 28), Pair(30, -106), Pair(0, -31), Pair(-39, -67), Pair(43, -1), Pair(-23, -73),
        Pair(0, 0), Pair(47, 73), Pair(133, -72), Pair(12, -66), Pair(68, -88), Pair(-3, -80), Pair(120, -92), Pair(22, -81),
        Pair(52, 6), Pair(65, -9), Pair(-53, 68), Pair(146, -27), Pair(-43, -63), Pair(88, -45), Pair(53, -59), Pair(-19, 42),
        Pair(-78, -6), Pair(-4, -48), Pair(64, -15), Pair(30, 45), Pair(200, -107), Pair(-6, 41), Pair(3, -86), Pair(-12, -65),
        Pair(-53, 7), Pair(62, -36), Pair(17, -16), Pair(178, -9), Pair(50, 14), Pair(-30, -20), Pair(12, -16), Pair(2, -41),
        Pair(-59, -61), Pair(-10, -136), Pair(-68, -30), Pair(-51, 53), Pair(80, -25), Pair(-40, 16), Pair(7, -52), Pair(7, 67),
        Pair(24, -101), Pair(-26, -73), Pair(-207, 34), Pair(-42, -26), Pair(33, -7), Pair(17, -21), Pair(66, -54), Pair(-171, -71),
        Pair(94, -80), Pair(30, -53), Pair(31, -1), Pair(104, -55), Pair(41, -41), Pair(14, 13), Pair(34, -33), Pair(-56, 135)
      },
      { // Piece 3
        Pair(13, -167), Pair(73, 133), Pair(-5, 27), Pair(-64, -39), Pair(-46, 87), Pair(-3, 73), Pair(36, 56), Pair(15, 36),
        Pair(0, 0), Pair(70, 6), Pair(178, -32), Pair(120, -40), Pair(147, -50), Pair(118, -27), Pair(-17, 17), Pair(114, -29),
        Pair(34, 4), Pair(58, -14), Pair(32, 33), Pair(-48, 33), Pair(-125, 67), Pair(14, 84), Pair(58, 66), Pair(33, -5),
        Pair(-7, 19), Pair(-41, 49), Pair(19, -15), Pair(10, -3), Pair(191, 15), Pair(-22, 2), Pair(-154, 98), Pair(-180, 90),
        Pair(-42, 37), Pair(78, 48), Pair(-72, 40), Pair(55, 11), Pair(-144, 25), Pair(-12, -136), Pair(54, 103), Pair(52, 23),
        Pair(67, -4), Pair(-72, 28), Pair(52, 55), Pair(-37, 36), Pair(-112, 170), Pair(-70, 13), Pair(32, 31), Pair(54, 18),
        Pair(12, -12), Pair(38, 76), Pair(-58, 76), Pair(55, 3), Pair(-63, 59), Pair(-59, 5), Pair(-19, 77), Pair(-48, 18),
        Pair(0, -24), Pair(110, -35), Pair(80, -41), Pair(63, 24), Pair(-119, 101), Pair(-58, 33), Pair(4, 90), Pair(33, -19)
      },
      { // Piece 4
        Pair(-121, -218), Pair(-2, -112), Pair(13, 30), Pair(-65, -89), Pair(43, 59), Pair(-81, -84), Pair(65, 28), Pair(-65, -56),
        Pair(0, 0), Pair(-28, 106), Pair(-37, -16), Pair(123, -80), Pair(20, 19), Pair(-82, 1), Pair(-2, 30), Pair(-4, -55),
        Pair(42, 59), Pair(-18, 16), Pair(2, -65), Pair(-46, 89), Pair(-46, -51), Pair(23, 62), Pair(112, 21), Pair(18, -34),
        Pair(-106, -21), Pair(-15, 31), Pair(-39, -74), Pair(39, 91), Pair(26, 18), Pair(-22, -85), Pair(-52, -71), Pair(-26, -99),
        Pair(-9, 57), Pair(-86, 108), Pair(26, -6), Pair(49, -34), Pair(64, -161), Pair(93, -13), Pair(-182, -22), Pair(113, 56),
        Pair(-59, 75), Pair(32, -76), Pair(-25, -2), Pair(-4, 37), Pair(-109, 50), Pair(-15, 67), Pair(40, -18), Pair(29, -6),
        Pair(33, -128), Pair(10, -116), Pair(55, -137), Pair(-53, -125), Pair(-59, -96), Pair(2, -102), Pair(-57, 28), Pair(-3, -75),
        Pair(-20, -38), Pair(-47, -86), Pair(-57, 51), Pair(44, 37), Pair(91, -70), Pair(28, -133), Pair(-46, -28), Pair(-22, -18)
      },
      { // Piece 5
        Pair(-71, -96), Pair(-20, 63), Pair(73, 120), Pair(12, 26), Pair(2, 1), Pair(-7, -49), Pair(-3, 24), Pair(15, 56),
        Pair(0, 0), Pair(20, 127), Pair(-21, 12), Pair(20, -4), Pair(54, 80), Pair(-69, -46), Pair(23, 10), Pair(0, 13),
        Pair(-50, -38), Pair(67, 58), Pair(46, 65), Pair(-86, 39), Pair(-88, 14), Pair(3, -14), Pair(-26, -23), Pair(2, 110),
        Pair(19, 6), Pair(33, 47), Pair(36, 25), Pair(-34, 80), Pair(61, -15), Pair(-25, 15), Pair(-8, -64), Pair(-128, -7),
        Pair(-57, 62), Pair(-4, 38), Pair(41, -4), Pair(55, 1), Pair(60, -5), Pair(-39, -25), Pair(37, -22), Pair(-45, -25),
        Pair(-143, 57), Pair(-78, 38), Pair(94, -21), Pair(-75, 36), Pair(114, -5), Pair(36, -14), Pair(-21, -25), Pair(-24, -27),
        Pair(-46, 15), Pair(169, -11), Pair(13, -1), Pair(-137, 29), Pair(-70, 4), Pair(4, -28), Pair(3, -30), Pair(-11, -13),
        Pair(-140, -80), Pair(112, -53), Pair(-32, 23), Pair(-33, 14), Pair(0, -24), Pair(31, -43), Pair(10, -37), Pair(-32, -55)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-107, 60), Pair(-13, 24), Pair(42, -30), Pair(-77, 43), Pair(-26, 10), Pair(17, 6), Pair(5, 32), Pair(26, 33),
        Pair(-46, 12), Pair(-49, -56), Pair(24, -45), Pair(-28, 62), Pair(-31, 40), Pair(36, 28), Pair(39, 46), Pair(51, 26),
        Pair(-47, 47), Pair(-4, -8), Pair(-29, 21), Pair(-9, 21), Pair(-28, 33), Pair(-56, 9), Pair(-10, 16), Pair(42, -18),
        Pair(-11, 31), Pair(-13, -34), Pair(-23, 24), Pair(12, 4), Pair(21, -13), Pair(-13, 26), Pair(20, 6), Pair(21, 15),
        Pair(-7, 14), Pair(-38, 25), Pair(-57, -2), Pair(-16, 4), Pair(-9, 9), Pair(-11, 9), Pair(8, -6), Pair(-3, 17),
        Pair(-22, 23), Pair(-11, 3), Pair(-65, 43), Pair(-62, 36), Pair(43, 17), Pair(-26, 19), Pair(15, 5), Pair(-18, 22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-17, -29), Pair(24, 115), Pair(-29, -18), Pair(18, 6), Pair(-24, -144), Pair(-3, 32), Pair(-34, -97), Pair(-11, -28),
        Pair(-32, -42), Pair(0, 0), Pair(84, -6), Pair(99, 111), Pair(35, -31), Pair(55, 33), Pair(33, 116), Pair(58, 96),
        Pair(12, 57), Pair(36, -13), Pair(222, 46), Pair(36, 5), Pair(117, -14), Pair(55, 35), Pair(-141, -13), Pair(78, -5),
        Pair(112, 30), Pair(63, 39), Pair(-40, 25), Pair(70, 46), Pair(7, 39), Pair(-96, 1), Pair(-51, -66), Pair(107, 66),
        Pair(-119, 26), Pair(110, 106), Pair(96, 15), Pair(67, -19), Pair(7, 21), Pair(82, -14), Pair(6, -27), Pair(-41, -68),
        Pair(-64, -104), Pair(13, 60), Pair(22, -27), Pair(-33, 118), Pair(-25, -11), Pair(98, -28), Pair(-78, 87), Pair(-7, 71),
        Pair(26, -31), Pair(67, -14), Pair(-171, 6), Pair(-21, -24), Pair(11, 16), Pair(-29, -44), Pair(8, -44), Pair(33, -37),
        Pair(-37, -28), Pair(-150, 99), Pair(-12, 26), Pair(27, -36), Pair(-155, 57), Pair(35, -81), Pair(-17, -100), Pair(13, 20)
      },
      { // Piece 2
        Pair(-139, -224), Pair(14, -62), Pair(110, -19), Pair(-39, -19), Pair(9, -119), Pair(19, 66), Pair(11, -69), Pair(33, 43),
        Pair(63, 0), Pair(0, 0), Pair(-44, 48), Pair(-87, -121), Pair(73, 67), Pair(15, -121), Pair(-31, 45), Pair(-97, -77),
        Pair(42, -33), Pair(114, 124), Pair(142, -50), Pair(-35, 115), Pair(103, -103), Pair(67, 51), Pair(48, -105), Pair(-65, 50),
        Pair(6, 43), Pair(114, -67), Pair(-98, 90), Pair(171, -34), Pair(83, 42), Pair(196, -110), Pair(-16, -18), Pair(133, -181),
        Pair(77, -55), Pair(93, -72), Pair(88, -43), Pair(-1, -43), Pair(114, -29), Pair(44, 33), Pair(23, -4), Pair(17, 71),
        Pair(27, -17), Pair(-1, -56), Pair(-15, 64), Pair(71, -42), Pair(57, 38), Pair(48, -7), Pair(104, -10), Pair(84, -34),
        Pair(80, -100), Pair(-14, -16), Pair(-113, -99), Pair(26, -31), Pair(-3, 36), Pair(5, -79), Pair(91, -70), Pair(-95, 100),
        Pair(-30, 45), Pair(15, -122), Pair(11, -3), Pair(39, -69), Pair(85, -29), Pair(104, -112), Pair(74, -90), Pair(16, 19)
      },
      { // Piece 3
        Pair(-4, 54), Pair(-27, -164), Pair(200, 83), Pair(-16, 152), Pair(-60, -4), Pair(5, 44), Pair(84, 31), Pair(8, 72),
        Pair(-23, 42), Pair(0, 0), Pair(86, -17), Pair(81, 13), Pair(141, -55), Pair(-4, -16), Pair(-106, 1), Pair(-9, -7),
        Pair(-67, 53), Pair(-54, 27), Pair(47, 22), Pair(84, -67), Pair(-53, 22), Pair(24, 89), Pair(46, 5), Pair(-2, 14),
        Pair(11, 51), Pair(143, 0), Pair(20, 68), Pair(-16, 31), Pair(-145, 51), Pair(51, 88), Pair(54, -4), Pair(42, 79),
        Pair(-104, 33), Pair(73, 36), Pair(44, 26), Pair(-76, 21), Pair(160, 18), Pair(-5, 92), Pair(-1, 24), Pair(-67, -24),
        Pair(-55, 29), Pair(-99, 35), Pair(62, 99), Pair(75, -67), Pair(-101, -46), Pair(-45, 53), Pair(-64, 20), Pair(-11, -98),
        Pair(25, -38), Pair(39, -12), Pair(-2, -19), Pair(109, -63), Pair(18, 31), Pair(12, -6), Pair(74, -71), Pair(44, -6),
        Pair(-7, 60), Pair(-40, 18), Pair(29, 9), Pair(-65, 75), Pair(-5, 13), Pair(7, 15), Pair(-58, 71), Pair(-24, -24)
      },
      { // Piece 4
        Pair(67, -90), Pair(-77, -68), Pair(65, 27), Pair(91, 26), Pair(4, 12), Pair(-28, -61), Pair(-36, -67), Pair(-10, -56),
        Pair(93, -117), Pair(0, 0), Pair(12, 7), Pair(-11, -16), Pair(39, 22), Pair(62, -16), Pair(-51, -94), Pair(-85, -157),
        Pair(11, -69), Pair(44, 16), Pair(-1, -7), Pair(137, 110), Pair(-11, 7), Pair(-29, -10), Pair(-21, 5), Pair(-44, 2),
        Pair(72, -40), Pair(-71, 32), Pair(-37, 38), Pair(-52, 95), Pair(68, 80), Pair(94, -18), Pair(-37, -15), Pair(14, -106),
        Pair(77, -9), Pair(-43, -51), Pair(55, 51), Pair(67, -14), Pair(-49, 41), Pair(-12, -6), Pair(-12, -26), Pair(-114, -25),
        Pair(64, -178), Pair(71, -29), Pair(-55, -9), Pair(93, -21), Pair(43, 3), Pair(-22, 72), Pair(-132, 6), Pair(-63, 21),
        Pair(-108, -20), Pair(-76, 136), Pair(-56, 43), Pair(8, -22), Pair(1, -49), Pair(-6, -49), Pair(-53, 112), Pair(-6, -11),
        Pair(-70, -192), Pair(-106, -17), Pair(3, -147), Pair(-118, 10), Pair(-108, 16), Pair(-69, -34), Pair(30, -14), Pair(62, 15)
      },
      { // Piece 5
        Pair(33, 148), Pair(11, 9), Pair(33, 29), Pair(91, 192), Pair(-15, -97), Pair(3, 13), Pair(-6, -54), Pair(-1, -6),
        Pair(26, 101), Pair(0, 0), Pair(82, 95), Pair(-12, 54), Pair(49, -44), Pair(-5, -22), Pair(-23, 16), Pair(-4, -24),
        Pair(34, 60), Pair(16, 46), Pair(47, 39), Pair(9, 40), Pair(20, -50), Pair(30, 53), Pair(-32, -76), Pair(-5, 67),
        Pair(7, 65), Pair(92, -9), Pair(59, 48), Pair(86, -8), Pair(70, 9), Pair(112, -44), Pair(-6, -7), Pair(-30, 4),
        Pair(-32, -37), Pair(49, -18), Pair(23, 31), Pair(87, -21), Pair(0, -35), Pair(-62, 18), Pair(4, -30), Pair(-2, -58),
        Pair(9, -20), Pair(-103, 28), Pair(11, -66), Pair(-54, 16), Pair(-85, -12), Pair(-40, -20), Pair(-139, -23), Pair(-113, -16),
        Pair(78, -104), Pair(151, 44), Pair(-16, 51), Pair(-26, 13), Pair(-97, -17), Pair(-183, 15), Pair(-25, -30), Pair(-15, -54),
        Pair(-11, 55), Pair(-37, 12), Pair(145, 37), Pair(43, -31), Pair(-163, -4), Pair(-72, -30), Pair(-26, -40), Pair(-29, -48)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(23, 20), Pair(42, -30), Pair(28, 3), Pair(81, 5), Pair(-33, 37), Pair(22, 72), Pair(6, 1), Pair(-7, 34),
        Pair(-28, 18), Pair(70, 13), Pair(12, -74), Pair(-46, 3), Pair(-66, -8), Pair(-62, 37), Pair(-136, 81), Pair(130, -37),
        Pair(47, 10), Pair(-43, 46), Pair(-35, 19), Pair(-22, 61), Pair(-18, 11), Pair(-13, 15), Pair(89, -14), Pair(36, 32),
        Pair(23, 8), Pair(-25, 43), Pair(-16, -10), Pair(-1, 20), Pair(-36, 18), Pair(-1, 12), Pair(44, -6), Pair(-1, 3),
        Pair(11, 14), Pair(-46, 12), Pair(-63, 38), Pair(26, -3), Pair(20, 3), Pair(-20, 6), Pair(-7, 3), Pair(10, 13),
        Pair(-23, 23), Pair(-14, 15), Pair(1, -13), Pair(-20, -32), Pair(-26, 45), Pair(-18, 0), Pair(-17, 10), Pair(-13, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(118, 44), Pair(19, 32), Pair(20, 45), Pair(15, 32), Pair(85, 6), Pair(36, 88), Pair(-12, -76), Pair(1, 2),
        Pair(17, 71), Pair(-14, 1), Pair(0, 0), Pair(-12, -99), Pair(53, 152), Pair(-24, 54), Pair(-9, -75), Pair(-97, -136),
        Pair(-14, -12), Pair(-32, 119), Pair(88, 95), Pair(1, 94), Pair(9, 2), Pair(66, 57), Pair(48, -10), Pair(11, 8),
        Pair(145, 16), Pair(24, 7), Pair(-44, 67), Pair(139, -14), Pair(8, 31), Pair(-15, 129), Pair(-67, 55), Pair(-66, -31),
        Pair(-8, 107), Pair(-76, 10), Pair(-49, 23), Pair(61, -19), Pair(28, -30), Pair(31, 60), Pair(17, 23), Pair(-20, 83),
        Pair(60, 15), Pair(47, -2), Pair(25, 31), Pair(-51, 76), Pair(4, 31), Pair(42, 20), Pair(71, 12), Pair(-68, 107),
        Pair(56, -58), Pair(-22, 1), Pair(30, -39), Pair(1, -24), Pair(-86, -38), Pair(129, -35), Pair(13, -33), Pair(-54, -63),
        Pair(-33, -18), Pair(-52, 19), Pair(-83, 9), Pair(-2, -91), Pair(-21, 72), Pair(-58, 4), Pair(11, -85), Pair(-18, 20)
      },
      { // Piece 2
        Pair(12, 67), Pair(-9, -30), Pair(-1, -27), Pair(117, -1), Pair(12, 68), Pair(47, 5), Pair(-10, -34), Pair(-16, -76),
        Pair(123, -4), Pair(-127, 11), Pair(0, 0), Pair(-12, -55), Pair(97, 34), Pair(6, 103), Pair(31, -11), Pair(63, 60),
        Pair(172, 57), Pair(89, -36), Pair(5, 84), Pair(63, -65), Pair(38, 78), Pair(85, -60), Pair(61, -4), Pair(35, -98),
        Pair(-12, 11), Pair(51, 43), Pair(62, -33), Pair(144, -51), Pair(176, -52), Pair(159, -33), Pair(130, 37), Pair(14, 78),
        Pair(-24, -110), Pair(164, -101), Pair(-62, 7), Pair(131, -23), Pair(-38, 23), Pair(50, -2), Pair(34, 108), Pair(-10, -120),
        Pair(92, 14), Pair(38, -29), Pair(9, -19), Pair(-60, 30), Pair(144, -58), Pair(67, -34), Pair(101, -45), Pair(85, 38),
        Pair(4, -55), Pair(116, -63), Pair(2, -48), Pair(-130, 6), Pair(4, 4), Pair(-7, -31), Pair(3, 13), Pair(-47, 34),
        Pair(-115, -36), Pair(-13, -42), Pair(28, -51), Pair(62, 23), Pair(42, -4), Pair(8, 31), Pair(-5, -103), Pair(84, 69)
      },
      { // Piece 3
        Pair(91, 97), Pair(-27, 156), Pair(43, -138), Pair(193, 44), Pair(3, 13), Pair(53, 61), Pair(49, 91), Pair(23, -38),
        Pair(-37, 34), Pair(41, -2), Pair(0, 0), Pair(35, 32), Pair(-70, 20), Pair(7, 36), Pair(144, 37), Pair(26, 21),
        Pair(-18, 22), Pair(-42, 58), Pair(16, -37), Pair(44, 24), Pair(-84, 66), Pair(29, 26), Pair(7, 53), Pair(-43, 115),
        Pair(-51, 61), Pair(35, 64), Pair(1, 46), Pair(15, 13), Pair(43, 144), Pair(-37, 84), Pair(100, 46), Pair(-15, 21),
        Pair(11, 24), Pair(102, 34), Pair(-75, 77), Pair(-54, 47), Pair(32, -59), Pair(-66, -31), Pair(18, 73), Pair(37, 23),
        Pair(-17, -14), Pair(114, 66), Pair(-77, 35), Pair(50, -15), Pair(59, 23), Pair(5, 33), Pair(-52, -42), Pair(-39, 56),
        Pair(-13, 36), Pair(-32, 11), Pair(96, -22), Pair(-21, -24), Pair(161, -24), Pair(-42, 66), Pair(-52, -18), Pair(-78, 22),
        Pair(-48, 25), Pair(107, 4), Pair(-6, -4), Pair(41, -34), Pair(130, -27), Pair(-15, 37), Pair(18, -8), Pair(-63, 35)
      },
      { // Piece 4
        Pair(-67, -58), Pair(26, 2), Pair(-130, -136), Pair(-65, -96), Pair(89, 80), Pair(73, 48), Pair(-59, -75), Pair(23, 18),
        Pair(91, 24), Pair(-121, 53), Pair(0, 0), Pair(34, 21), Pair(-9, -25), Pair(75, -2), Pair(26, 46), Pair(45, 2),
        Pair(68, -45), Pair(68, 35), Pair(33, 4), Pair(1, 52), Pair(63, 32), Pair(-12, -63), Pair(-26, -27), Pair(-105, -142),
        Pair(38, -4), Pair(-75, 92), Pair(113, 50), Pair(59, 11), Pair(-56, -22), Pair(59, -69), Pair(136, -14), Pair(21, 17),
        Pair(7, -98), Pair(-27, -19), Pair(53, -26), Pair(-5, 98), Pair(-87, -9), Pair(66, -54), Pair(-43, -21), Pair(70, 82),
        Pair(-29, 73), Pair(-98, -47), Pair(101, -54), Pair(-18, -79), Pair(-27, 5), Pair(-25, -82), Pair(51, -126), Pair(63, 66),
        Pair(-119, -60), Pair(-20, -34), Pair(-21, -100), Pair(65, 109), Pair(21, 47), Pair(-40, -32), Pair(-21, -112), Pair(51, -20),
        Pair(-23, -36), Pair(-12, -23), Pair(-79, -84), Pair(-85, -24), Pair(-46, -123), Pair(-124, -25), Pair(-77, 4), Pair(4, 1)
      },
      { // Piece 5
        Pair(14, 143), Pair(69, 50), Pair(-7, -47), Pair(-30, 13), Pair(-10, 68), Pair(17, 46), Pair(16, 47), Pair(3, 42),
        Pair(-2, 84), Pair(21, 144), Pair(0, 0), Pair(29, 70), Pair(-1, 17), Pair(-11, -53), Pair(-15, -18), Pair(2, -40),
        Pair(71, 138), Pair(-6, 115), Pair(-19, 54), Pair(128, 58), Pair(-7, 7), Pair(95, -73), Pair(66, 11), Pair(16, -41),
        Pair(81, 37), Pair(118, 84), Pair(60, 56), Pair(86, -2), Pair(75, 54), Pair(36, 27), Pair(-44, -8), Pair(3, -32),
        Pair(15, 90), Pair(20, -3), Pair(-12, 11), Pair(-67, 30), Pair(-73, 7), Pair(17, -44), Pair(-35, -56), Pair(-25, -65),
        Pair(-151, -21), Pair(41, 31), Pair(37, -57), Pair(-2, 0), Pair(-22, 17), Pair(-77, -58), Pair(-68, 6), Pair(-40, -62),
        Pair(-98, 5), Pair(138, -65), Pair(27, 27), Pair(-4, 21), Pair(-41, -52), Pair(-5, -52), Pair(-93, -7), Pair(16, -70),
        Pair(72, 18), Pair(96, 0), Pair(-114, -120), Pair(-47, 42), Pair(-60, -47), Pair(-73, -74), Pair(-14, -54), Pair(17, -86)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 17), Pair(-77, 43), Pair(81, 5), Pair(24, -3), Pair(-51, 59), Pair(-1, 43), Pair(42, 10), Pair(-98, 65),
        Pair(28, 16), Pair(-91, 24), Pair(20, 11), Pair(-11, -61), Pair(-8, 38), Pair(35, 75), Pair(10, 37), Pair(-7, -13),
        Pair(58, -1), Pair(-30, 17), Pair(17, 7), Pair(-39, -9), Pair(-18, 24), Pair(73, 2), Pair(45, -9), Pair(46, 5),
        Pair(-18, 24), Pair(-28, 30), Pair(0, 6), Pair(-12, 22), Pair(-29, 28), Pair(-22, 3), Pair(6, 11), Pair(-17, 12),
        Pair(-21, 23), Pair(8, 2), Pair(26, -9), Pair(-86, 43), Pair(-15, 21), Pair(19, -9), Pair(14, -1), Pair(5, -1),
        Pair(-11, 10), Pair(-26, 22), Pair(17, -15), Pair(-16, 14), Pair(59, -35), Pair(-10, 0), Pair(-1, 10), Pair(-38, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-57, -67), Pair(22, -29), Pair(12, 38), Pair(-15, -84), Pair(17, -7), Pair(42, 100), Pair(-18, -85), Pair(0, 0),
        Pair(10, 116), Pair(18, 28), Pair(-32, 75), Pair(0, 0), Pair(121, 126), Pair(-4, 142), Pair(1, 90), Pair(-60, 1),
        Pair(-21, -57), Pair(-27, 55), Pair(45, 37), Pair(110, 29), Pair(139, 49), Pair(102, -9), Pair(54, 18), Pair(55, -13),
        Pair(-55, 62), Pair(0, -27), Pair(-20, 33), Pair(136, 11), Pair(53, 64), Pair(-19, -7), Pair(20, 18), Pair(11, 9),
        Pair(80, 32), Pair(19, 29), Pair(-28, 25), Pair(79, 51), Pair(34, 12), Pair(87, -97), Pair(88, -11), Pair(12, -6),
        Pair(-87, 28), Pair(3, 3), Pair(-28, -80), Pair(25, 49), Pair(-53, 72), Pair(1, -57), Pair(116, -38), Pair(-24, 82),
        Pair(-56, -96), Pair(21, -79), Pair(41, 52), Pair(22, -15), Pair(-17, 120), Pair(107, 53), Pair(-11, 58), Pair(26, 106),
        Pair(-23, -15), Pair(-11, -39), Pair(118, 106), Pair(-37, 22), Pair(-3, -100), Pair(20, 117), Pair(67, -44), Pair(3, -34)
      },
      { // Piece 2
        Pair(26, -82), Pair(-35, -25), Pair(-8, -20), Pair(-166, -181), Pair(24, -21), Pair(-30, 12), Pair(-1, -106), Pair(-48, -110),
        Pair(0, 148), Pair(95, 58), Pair(36, 134), Pair(0, 0), Pair(39, -106), Pair(85, -111), Pair(26, -50), Pair(-12, -14),
        Pair(-20, -40), Pair(80, 95), Pair(-9, 14), Pair(126, -44), Pair(177, -33), Pair(56, 31), Pair(6, -137), Pair(161, 45),
        Pair(84, 67), Pair(92, -57), Pair(-67, 42), Pair(-4, 13), Pair(-10, 20), Pair(152, -16), Pair(49, 40), Pair(38, -7),
        Pair(69, -52), Pair(67, 86), Pair(26, -8), Pair(-17, 75), Pair(87, -54), Pair(1, 36), Pair(50, 31), Pair(30, 93),
        Pair(87, -20), Pair(-108, -50), Pair(34, 16), Pair(33, -20), Pair(88, -20), Pair(-11, -57), Pair(57, 19), Pair(122, -26),
        Pair(-137, -87), Pair(89, -98), Pair(-3, -117), Pair(-85, 110), Pair(-59, -29), Pair(-51, 36), Pair(1, 17), Pair(37, 0),
        Pair(8, -46), Pair(-65, -110), Pair(50, -27), Pair(115, -19), Pair(-9, 91), Pair(105, -22), Pair(-29, -191), Pair(63, -95)
      },
      { // Piece 3
        Pair(10, 9), Pair(-38, 47), Pair(49, 51), Pair(-51, -103), Pair(44, 66), Pair(18, 187), Pair(20, 16), Pair(55, 71),
        Pair(26, 1), Pair(74, -3), Pair(0, 20), Pair(0, 0), Pair(33, -10), Pair(12, -16), Pair(-79, 27), Pair(30, 2),
        Pair(71, 49), Pair(-27, 66), Pair(-22, -22), Pair(-47, 32), Pair(3, 11), Pair(-10, -16), Pair(14, -36), Pair(-12, 27),
        Pair(-18, 63), Pair(140, -25), Pair(105, -59), Pair(85, 20), Pair(-60, 73), Pair(36, 85), Pair(32, -15), Pair(136, 70),
        Pair(62, 16), Pair(-19, 35), Pair(36, -37), Pair(-16, 30), Pair(-11, 81), Pair(-4, -8), Pair(21, 20), Pair(-5, 33),
        Pair(24, -26), Pair(-122, 103), Pair(-20, 105), Pair(-54, 30), Pair(46, 111), Pair(43, 55), Pair(-80, 9), Pair(-164, 74),
        Pair(0, -60), Pair(12, 44), Pair(-75, 57), Pair(-14, -11), Pair(40, 74), Pair(-97, 97), Pair(-90, 76), Pair(-41, 30),
        Pair(-117, 57), Pair(-59, 63), Pair(-4, 22), Pair(9, 24), Pair(3, 98), Pair(-44, 44), Pair(-54, 1), Pair(-32, 12)
      },
      { // Piece 4
        Pair(12, 54), Pair(-57, -36), Pair(-61, 21), Pair(-84, -96), Pair(-2, -14), Pair(-4, -1), Pair(-26, -25), Pair(-38, -37),
        Pair(60, 106), Pair(-37, 48), Pair(-64, 77), Pair(0, 0), Pair(66, -66), Pair(11, -4), Pair(14, -8), Pair(-31, -91),
        Pair(19, -4), Pair(-16, 10), Pair(68, -86), Pair(55, -20), Pair(-34, -21), Pair(93, 13), Pair(64, 68), Pair(-47, -81),
        Pair(29, -37), Pair(51, 27), Pair(43, 12), Pair(-9, -7), Pair(-48, -4), Pair(148, 29), Pair(59, 106), Pair(7, 31),
        Pair(-132, -15), Pair(-18, 34), Pair(-8, 1), Pair(34, 30), Pair(67, 140), Pair(-111, 62), Pair(35, -22), Pair(49, 49),
        Pair(-7, 8), Pair(-47, 44), Pair(-55, -41), Pair(-63, 62), Pair(-87, -4), Pair(-44, -2), Pair(-49, -32), Pair(-55, -73),
        Pair(40, -49), Pair(-90, 18), Pair(33, 4), Pair(-55, 90), Pair(-4, 94), Pair(-51, 77), Pair(-24, -87), Pair(9, 0),
        Pair(16, -23), Pair(89, -29), Pair(-47, -40), Pair(66, -126), Pair(-106, -71), Pair(-44, -82), Pair(-34, -65), Pair(-17, -33)
      },
      { // Piece 5
        Pair(16, 89), Pair(33, 136), Pair(-15, 13), Pair(74, 32), Pair(5, 52), Pair(-1, 27), Pair(-3, -15), Pair(4, 52),
        Pair(5, 21), Pair(-20, -13), Pair(133, 102), Pair(0, 0), Pair(2, 83), Pair(5, 18), Pair(-30, -105), Pair(13, 50),
        Pair(-12, 45), Pair(15, 39), Pair(100, 87), Pair(44, 65), Pair(51, 88), Pair(12, 32), Pair(0, -38), Pair(6, -4),
        Pair(35, -28), Pair(77, -19), Pair(83, 19), Pair(79, 23), Pair(132, 1), Pair(-17, -21), Pair(23, -37), Pair(20, -106),
        Pair(-43, -3), Pair(-31, 21), Pair(-7, -10), Pair(7, 13), Pair(176, -52), Pair(85, -55), Pair(-82, -7), Pair(-94, -34),
        Pair(30, -19), Pair(44, 19), Pair(43, -23), Pair(65, -24), Pair(-49, -28), Pair(-52, -20), Pair(-84, -12), Pair(-8, -57),
        Pair(134, 78), Pair(-4, 22), Pair(-125, -6), Pair(-175, 21), Pair(-104, 18), Pair(-8, -47), Pair(-98, -17), Pair(-66, -20),
        Pair(116, -41), Pair(-5, -47), Pair(-60, 4), Pair(-34, 0), Pair(-60, 42), Pair(-50, -25), Pair(4, -78), Pair(6, -49)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(55, 67), Pair(-26, 10), Pair(-33, 37), Pair(-51, 59), Pair(-6, 21), Pair(52, 79), Pair(-34, 37), Pair(53, 29),
        Pair(-107, 50), Pair(-49, 2), Pair(-95, 50), Pair(60, -18), Pair(103, -11), Pair(46, -14), Pair(31, 22), Pair(8, 5),
        Pair(44, -8), Pair(17, 3), Pair(74, 15), Pair(-2, 19), Pair(35, -12), Pair(-49, 31), Pair(32, 17), Pair(13, -12),
        Pair(45, -28), Pair(29, 3), Pair(18, 1), Pair(52, 12), Pair(-65, 32), Pair(46, -32), Pair(-39, 10), Pair(10, 6),
        Pair(-23, 13), Pair(-56, 39), Pair(1, -4), Pair(41, 4), Pair(-25, -9), Pair(12, 13), Pair(-4, 20), Pair(2, -13),
        Pair(4, 6), Pair(-30, 4), Pair(15, -35), Pair(-89, 66), Pair(-20, -2), Pair(-23, 23), Pair(22, -12), Pair(-28, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, -5), Pair(-10, 72), Pair(34, 5), Pair(112, 94), Pair(2, 72), Pair(90, 42), Pair(0, 3), Pair(2, 7),
        Pair(-120, -58), Pair(-53, 180), Pair(70, -65), Pair(38, 22), Pair(0, 0), Pair(-5, 43), Pair(61, 55), Pair(26, 37),
        Pair(63, 124), Pair(35, 44), Pair(-1, -13), Pair(-9, 50), Pair(16, 80), Pair(43, 80), Pair(45, 16), Pair(-5, -52),
        Pair(-74, -30), Pair(181, -11), Pair(-107, 66), Pair(-14, 12), Pair(172, -11), Pair(-11, 29), Pair(19, -30), Pair(153, 48),
        Pair(-48, -76), Pair(-49, -49), Pair(87, -10), Pair(2, 30), Pair(-70, 87), Pair(22, 35), Pair(-30, 71), Pair(49, 51),
        Pair(-20, 40), Pair(-56, 7), Pair(-48, 68), Pair(20, -4), Pair(198, -22), Pair(-33, 55), Pair(100, -6), Pair(119, -44),
        Pair(13, 21), Pair(-85, -58), Pair(149, 45), Pair(-80, -80), Pair(68, -23), Pair(-37, -38), Pair(85, 47), Pair(-36, -70),
        Pair(-22, -9), Pair(11, -109), Pair(0, 87), Pair(108, -36), Pair(-92, 12), Pair(-8, -63), Pair(82, 90), Pair(-2, -7)
      },
      { // Piece 2
        Pair(40, 1), Pair(-51, -59), Pair(-6, 7), Pair(84, -28), Pair(12, -25), Pair(8, -111), Pair(5, -36), Pair(6, -1),
        Pair(56, 84), Pair(40, 42), Pair(-13, -10), Pair(88, 78), Pair(0, 0), Pair(-50, -1), Pair(-58, -35), Pair(13, -51),
        Pair(-64, 20), Pair(-9, -37), Pair(31, 79), Pair(156, -44), Pair(-26, -60), Pair(11, 62), Pair(45, 34), Pair(-35, -79),
        Pair(13, -31), Pair(-85, 35), Pair(35, -29), Pair(-139, 61), Pair(25, -57), Pair(11, -39), Pair(59, 5), Pair(24, 18),
        Pair(36, 111), Pair(87, -43), Pair(58, 99), Pair(-34, -30), Pair(82, 4), Pair(94, -10), Pair(62, -25), Pair(-23, 24),
        Pair(25, -56), Pair(24, -48), Pair(-23, -10), Pair(77, -27), Pair(66, -78), Pair(129, 15), Pair(-2, -66), Pair(-40, 64),
        Pair(-96, 57), Pair(-24, -8), Pair(47, -150), Pair(-81, -40), Pair(27, -5), Pair(-13, 2), Pair(32, 81), Pair(-100, -63),
        Pair(147, -70), Pair(60, -53), Pair(82, -96), Pair(-98, -15), Pair(26, 83), Pair(50, 56), Pair(83, -103), Pair(-65, -17)
      },
      { // Piece 3
        Pair(-50, 100), Pair(70, 122), Pair(35, 42), Pair(-3, 56), Pair(-62, -94), Pair(96, 110), Pair(49, -12), Pair(17, 42),
        Pair(-3, -22), Pair(-107, 28), Pair(-50, -15), Pair(26, -3), Pair(0, 0), Pair(101, -42), Pair(73, -15), Pair(42, 8),
        Pair(-13, -89), Pair(-38, -7), Pair(-15, -5), Pair(90, -41), Pair(3, 13), Pair(-46, -7), Pair(-21, 33), Pair(-64, -27),
        Pair(-8, -8), Pair(20, -77), Pair(21, 67), Pair(88, -3), Pair(89, -67), Pair(-2, 3), Pair(-18, 53), Pair(18, 55),
        Pair(118, 24), Pair(-12, 15), Pair(-27, -65), Pair(-39, -91), Pair(15, 16), Pair(56, -31), Pair(-75, -3), Pair(-173, 9),
        Pair(-3, -100), Pair(38, 31), Pair(49, 84), Pair(62, -13), Pair(-17, 1), Pair(-115, -15), Pair(30, 94), Pair(-12, 20),
        Pair(85, 53), Pair(2, -27), Pair(-88, -1), Pair(77, -4), Pair(-5, 30), Pair(27, 64), Pair(-32, -37), Pair(-10, 8),
        Pair(-60, 6), Pair(-21, 2), Pair(131, -63), Pair(38, -39), Pair(-64, 8), Pair(43, -3), Pair(-46, 6), Pair(48, -52)
      },
      { // Piece 4
        Pair(-17, -24), Pair(23, 14), Pair(47, 76), Pair(-31, -51), Pair(-166, -178), Pair(-69, -98), Pair(-40, -55), Pair(-13, -16),
        Pair(-6, -2), Pair(-53, 13), Pair(91, 20), Pair(38, -89), Pair(0, 0), Pair(73, -137), Pair(-6, -33), Pair(-19, 32),
        Pair(-93, -11), Pair(44, 22), Pair(8, 54), Pair(-2, 15), Pair(9, 19), Pair(-1, -5), Pair(82, 40), Pair(36, 7),
        Pair(-57, -75), Pair(22, 51), Pair(53, 19), Pair(4, 5), Pair(17, 74), Pair(15, 2), Pair(-18, -35), Pair(18, 6),
        Pair(-121, 3), Pair(61, 11), Pair(61, 37), Pair(145, -24), Pair(82, -101), Pair(-60, -5), Pair(87, -44), Pair(53, -89),
        Pair(-56, -77), Pair(-145, -24), Pair(25, 47), Pair(81, -67), Pair(-8, 48), Pair(-7, 31), Pair(41, -61), Pair(-45, -20),
        Pair(-126, -72), Pair(48, -32), Pair(-20, -45), Pair(43, 0), Pair(-24, 22), Pair(-65, 49), Pair(5, -6), Pair(26, 2),
        Pair(-124, -59), Pair(45, -86), Pair(-42, -86), Pair(-117, 15), Pair(-98, -104), Pair(-71, -47), Pair(-41, -62), Pair(1, 1)
      },
      { // Piece 5
        Pair(-1, -6), Pair(-21, -102), Pair(-10, 36), Pair(2, 81), Pair(-11, -63), Pair(4, -12), Pair(44, 79), Pair(8, 53),
        Pair(-37, -50), Pair(17, 7), Pair(25, 92), Pair(1, 105), Pair(0, 0), Pair(50, 70), Pair(61, 103), Pair(21, 55),
        Pair(9, 43), Pair(56, -21), Pair(33, 72), Pair(11, 47), Pair(8, -7), Pair(22, 54), Pair(63, 16), Pair(16, 1),
        Pair(-45, -73), Pair(-23, 41), Pair(114, 71), Pair(-6, 31), Pair(-15, 24), Pair(67, -9), Pair(80, -32), Pair(-46, -66),
        Pair(-39, -89), Pair(30, -21), Pair(11, 25), Pair(75, 44), Pair(-88, 33), Pair(23, -12), Pair(-9, 36), Pair(15, 0),
        Pair(-47, -59), Pair(-49, -13), Pair(111, -63), Pair(-89, 15), Pair(-80, 5), Pair(-77, -19), Pair(-8, -18), Pair(-49, -77),
        Pair(-123, 25), Pair(-7, -39), Pair(47, 40), Pair(25, -43), Pair(-196, 36), Pair(-18, -36), Pair(15, -101), Pair(87, -62),
        Pair(-79, 2), Pair(-55, -20), Pair(-42, -67), Pair(18, 0), Pair(5, -49), Pair(-47, -5), Pair(13, -69), Pair(20, -41)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-72, 19), Pair(17, 6), Pair(22, 72), Pair(-1, 43), Pair(52, 79), Pair(-25, 16), Pair(33, 41), Pair(57, 34),
        Pair(74, 16), Pair(-3, 25), Pair(-33, 46), Pair(-73, 48), Pair(-105, 47), Pair(22, -68), Pair(47, -26), Pair(-2, 7),
        Pair(40, 6), Pair(-25, 26), Pair(-52, 25), Pair(-2, 2), Pair(-32, 36), Pair(8, -14), Pair(-28, 25), Pair(31, -19),
        Pair(-5, 9), Pair(21, 23), Pair(9, 2), Pair(-48, 25), Pair(-23, -8), Pair(-61, -2), Pair(-49, 14), Pair(-40, 26),
        Pair(-43, 21), Pair(-15, 0), Pair(-59, -5), Pair(31, -24), Pair(-26, -6), Pair(37, -14), Pair(-56, 19), Pair(23, -7),
        Pair(-1, 12), Pair(-6, 14), Pair(-18, -7), Pair(13, -7), Pair(-108, 37), Pair(-25, 4), Pair(-20, 8), Pair(33, -20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(1, 26), Pair(-2, -18), Pair(-30, -24), Pair(45, -102), Pair(54, 113), Pair(51, -14), Pair(49, 60), Pair(0, -34),
        Pair(-3, 21), Pair(10, 32), Pair(-52, -62), Pair(-62, 8), Pair(-130, -112), Pair(0, 0), Pair(-2, -24), Pair(-4, 9),
        Pair(25, 79), Pair(-42, -46), Pair(-68, 7), Pair(87, -65), Pair(151, 6), Pair(34, -17), Pair(78, 148), Pair(49, 10),
        Pair(-28, -49), Pair(-158, -24), Pair(-126, 37), Pair(32, 30), Pair(168, -7), Pair(37, -10), Pair(63, 22), Pair(109, -16),
        Pair(-25, -86), Pair(-70, -38), Pair(93, -105), Pair(-129, 22), Pair(-15, 18), Pair(105, -6), Pair(-86, -8), Pair(112, -34),
        Pair(9, -71), Pair(-8, -32), Pair(74, -96), Pair(-66, -56), Pair(-16, 6), Pair(21, 118), Pair(68, -76), Pair(-19, -13),
        Pair(-5, 53), Pair(-4, -12), Pair(81, -169), Pair(-39, -38), Pair(48, -46), Pair(-114, 6), Pair(86, -63), Pair(23, -22),
        Pair(-3, -29), Pair(-95, 46), Pair(-100, 64), Pair(27, -66), Pair(-151, -61), Pair(-82, -6), Pair(24, 13), Pair(36, 20)
      },
      { // Piece 2
        Pair(-61, -44), Pair(-17, 70), Pair(-27, 36), Pair(28, 84), Pair(58, 26), Pair(-13, 93), Pair(29, -24), Pair(5, 16),
        Pair(-32, -43), Pair(93, -25), Pair(45, 96), Pair(13, -122), Pair(-53, 58), Pair(0, 0), Pair(37, -11), Pair(36, -16),
        Pair(-123, -83), Pair(-57, -30), Pair(50, -160), Pair(43, 47), Pair(50, -32), Pair(88, -32), Pair(-26, -31), Pair(58, 8),
        Pair(-9, 49), Pair(-51, -48), Pair(-18, -17), Pair(136, -23), Pair(66, -77), Pair(41, -49), Pair(-59, -19), Pair(12, -31),
        Pair(-47, -89), Pair(-5, 49), Pair(14, -13), Pair(155, 118), Pair(30, -54), Pair(170, 62), Pair(39, -151), Pair(-44, -36),
        Pair(36, 64), Pair(80, -35), Pair(43, -33), Pair(-72, -89), Pair(103, 60), Pair(-18, -41), Pair(-4, 31), Pair(30, 65),
        Pair(-190, -70), Pair(-35, -16), Pair(-66, -108), Pair(93, 13), Pair(21, 43), Pair(-63, 52), Pair(147, -112), Pair(11, -72),
        Pair(67, -3), Pair(-90, -22), Pair(68, 15), Pair(-114, -20), Pair(49, -41), Pair(-65, -142), Pair(78, 61), Pair(63, -68)
      },
      { // Piece 3
        Pair(43, 45), Pair(-5, 19), Pair(94, 110), Pair(93, 69), Pair(33, 47), Pair(-7, -63), Pair(-31, 47), Pair(66, 27),
        Pair(22, -12), Pair(-15, -8), Pair(30, 4), Pair(58, 41), Pair(34, 9), Pair(0, 0), Pair(22, -10), Pair(-66, -10),
        Pair(-70, 50), Pair(30, 46), Pair(73, 37), Pair(-67, -68), Pair(-52, 5), Pair(96, -50), Pair(37, 13), Pair(-3, 61),
        Pair(96, -44), Pair(81, -36), Pair(-20, -70), Pair(73, 8), Pair(31, 45), Pair(100, -57), Pair(1, -18), Pair(13, 43),
        Pair(115, 78), Pair(27, -78), Pair(-63, -29), Pair(63, 126), Pair(82, 61), Pair(56, 28), Pair(-46, -47), Pair(-74, -23),
        Pair(32, -43), Pair(-67, 29), Pair(-24, -138), Pair(-158, 2), Pair(-87, -3), Pair(-53, 64), Pair(-60, -11), Pair(77, -15),
        Pair(-32, -45), Pair(-48, 87), Pair(-21, -36), Pair(-168, -11), Pair(49, 69), Pair(-1, 75), Pair(67, -19), Pair(71, -79),
        Pair(-61, 36), Pair(10, -28), Pair(-58, 100), Pair(-44, -38), Pair(63, -56), Pair(-5, 17), Pair(0, 65), Pair(-28, 85)
      },
      { // Piece 4
        Pair(-14, -8), Pair(11, 21), Pair(-49, -72), Pair(52, 81), Pair(44, 14), Pair(-95, -150), Pair(-33, -15), Pair(-74, -65),
        Pair(30, -30), Pair(42, 47), Pair(-74, -18), Pair(92, 142), Pair(60, -89), Pair(0, 0), Pair(34, 29), Pair(74, 115),
        Pair(-2, -36), Pair(-32, -223), Pair(95, 66), Pair(18, -22), Pair(-36, 54), Pair(-17, -85), Pair(-62, 44), Pair(-90, -81),
        Pair(-73, -125), Pair(-9, -8), Pair(29, -2), Pair(20, -27), Pair(155, 98), Pair(40, -61), Pair(-68, -124), Pair(73, 122),
        Pair(-77, -54), Pair(-39, -24), Pair(25, -36), Pair(112, 84), Pair(-76, -144), Pair(123, 93), Pair(-97, 47), Pair(101, 56),
        Pair(-91, -65), Pair(-109, -68), Pair(-51, -39), Pair(91, 36), Pair(-58, -35), Pair(49, 20), Pair(52, 40), Pair(-61, 13),
        Pair(-67, -105), Pair(-105, -27), Pair(-25, -92), Pair(78, -48), Pair(-35, -8), Pair(-17, 16), Pair(-125, 56), Pair(-72, -18),
        Pair(146, 28), Pair(-72, -23), Pair(-89, -25), Pair(-33, -102), Pair(-42, -24), Pair(-2, 3), Pair(-26, -35), Pair(-63, -44)
      },
      { // Piece 5
        Pair(-1, -19), Pair(0, 0), Pair(-15, -70), Pair(35, 36), Pair(42, 43), Pair(-5, -8), Pair(16, 67), Pair(-5, 81),
        Pair(14, 76), Pair(-6, 17), Pair(0, 17), Pair(49, 13), Pair(8, 74), Pair(0, 0), Pair(30, 62), Pair(-9, 73),
        Pair(5, 19), Pair(24, 13), Pair(-23, 69), Pair(-37, 8), Pair(-4, 60), Pair(35, 42), Pair(72, 71), Pair(4, 32),
        Pair(4, 55), Pair(-52, -45), Pair(15, 46), Pair(45, -53), Pair(16, 25), Pair(113, 5), Pair(22, 17), Pair(-11, 110),
        Pair(-26, -29), Pair(-42, -79), Pair(-47, -54), Pair(24, -29), Pair(4, 16), Pair(42, -9), Pair(94, 27), Pair(-9, -39),
        Pair(-45, 9), Pair(-21, 6), Pair(45, -20), Pair(162, -10), Pair(27, -3), Pair(78, -42), Pair(-73, 23), Pair(16, -35),
        Pair(17, -20), Pair(-141, 31), Pair(57, 13), Pair(-80, -33), Pair(-92, -65), Pair(-16, 15), Pair(37, -69), Pair(6, -10),
        Pair(-71, 10), Pair(8, -119), Pair(-14, 6), Pair(-22, -90), Pair(-117, -101), Pair(-112, 49), Pair(-36, -19), Pair(-23, 62)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 56), Pair(5, 32), Pair(6, 1), Pair(42, 10), Pair(-34, 37), Pair(33, 41), Pair(-32, 17), Pair(-14, -129),
        Pair(4, 50), Pair(52, 82), Pair(-37, 15), Pair(77, 9), Pair(-47, 26), Pair(-17, -12), Pair(130, -146), Pair(47, -42),
        Pair(16, 23), Pair(-81, 13), Pair(16, -2), Pair(22, -4), Pair(26, -7), Pair(-9, 40), Pair(15, 28), Pair(-12, 29),
        Pair(29, 6), Pair(13, 5), Pair(61, -11), Pair(1, 10), Pair(48, 23), Pair(-30, 13), Pair(6, -18), Pair(-23, 33),
        Pair(54, 0), Pair(37, 15), Pair(13, 8), Pair(46, -24), Pair(-1, 27), Pair(-34, 15), Pair(7, -11), Pair(-26, 17),
        Pair(40, -7), Pair(22, 19), Pair(18, 11), Pair(48, -36), Pair(-86, 1), Pair(-13, 24), Pair(-17, 23), Pair(-3, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-25, -4), Pair(9, 12), Pair(-43, -133), Pair(-22, 15), Pair(40, -35), Pair(-89, -27), Pair(-3, -12), Pair(3, 8),
        Pair(-39, -35), Pair(-50, -44), Pair(-31, -11), Pair(85, 57), Pair(94, 167), Pair(167, -4), Pair(0, 0), Pair(177, 17),
        Pair(4, -28), Pair(15, 26), Pair(28, 37), Pair(6, -6), Pair(47, -104), Pair(60, -2), Pair(65, -26), Pair(52, 83),
        Pair(-4, -79), Pair(133, 92), Pair(-32, -5), Pair(59, 17), Pair(44, 13), Pair(84, 53), Pair(-17, 22), Pair(-61, 76),
        Pair(5, 90), Pair(126, 78), Pair(127, -75), Pair(19, -17), Pair(-68, -11), Pair(-69, -100), Pair(-44, 73), Pair(104, -34),
        Pair(-38, -13), Pair(1, 60), Pair(118, -146), Pair(-32, -74), Pair(12, 26), Pair(-33, 88), Pair(3, -66), Pair(87, -112),
        Pair(94, -28), Pair(15, -118), Pair(-41, 46), Pair(13, -34), Pair(-88, 120), Pair(-25, -99), Pair(92, -9), Pair(15, 25),
        Pair(-59, -41), Pair(-135, -79), Pair(-78, 65), Pair(-100, 17), Pair(133, 24), Pair(-197, -55), Pair(-113, -40), Pair(3, 15)
      },
      { // Piece 2
        Pair(-25, 7), Pair(27, 48), Pair(-22, 2), Pair(11, -69), Pair(-6, -88), Pair(-30, -90), Pair(-75, -70), Pair(-37, -90),
        Pair(-2, 46), Pair(-23, -4), Pair(33, -71), Pair(45, -62), Pair(80, -39), Pair(11, 115), Pair(0, 0), Pair(-23, -1),
        Pair(46, 15), Pair(99, -118), Pair(-5, 18), Pair(-8, -126), Pair(75, 116), Pair(17, -13), Pair(10, 59), Pair(6, -16),
        Pair(-91, -85), Pair(86, 73), Pair(-1, -14), Pair(89, 14), Pair(139, -68), Pair(58, 64), Pair(-39, -125), Pair(3, 104),
        Pair(-72, 56), Pair(50, -143), Pair(58, 4), Pair(66, 12), Pair(-101, 15), Pair(-76, -150), Pair(125, -110), Pair(-5, -173),
        Pair(22, -45), Pair(88, 21), Pair(5, 11), Pair(60, -105), Pair(87, -60), Pair(22, -11), Pair(-19, -52), Pair(49, -119),
        Pair(60, -46), Pair(0, -29), Pair(-26, -3), Pair(-6, -61), Pair(95, 0), Pair(-55, -27), Pair(-41, -33), Pair(-96, 60),
        Pair(82, -35), Pair(8, -33), Pair(53, -95), Pair(-19, 13), Pair(10, 20), Pair(-43, 29), Pair(0, -42), Pair(-1, 15)
      },
      { // Piece 3
        Pair(-26, 60), Pair(39, -4), Pair(16, -86), Pair(15, 15), Pair(10, 23), Pair(83, 54), Pair(-63, -106), Pair(90, -60),
        Pair(129, -16), Pair(72, -19), Pair(10, -51), Pair(65, -61), Pair(-25, -9), Pair(-47, -41), Pair(0, 0), Pair(-63, 28),
        Pair(12, 2), Pair(31, -68), Pair(26, -66), Pair(46, -19), Pair(34, -91), Pair(0, 25), Pair(40, 30), Pair(148, 50),
        Pair(-150, 67), Pair(74, -22), Pair(12, 96), Pair(-82, -20), Pair(-4, -26), Pair(-16, -12), Pair(12, -73), Pair(-53, 66),
        Pair(-116, 47), Pair(25, -62), Pair(54, -76), Pair(-66, -38), Pair(58, 29), Pair(75, -33), Pair(178, 2), Pair(-78, 149),
        Pair(-265, -32), Pair(-57, -52), Pair(-168, 99), Pair(3, 105), Pair(14, -15), Pair(26, -52), Pair(121, 25), Pair(-123, 51),
        Pair(-72, 7), Pair(-99, -102), Pair(72, 9), Pair(46, 21), Pair(47, -68), Pair(-99, 24), Pair(18, -73), Pair(-38, -52),
        Pair(-42, -95), Pair(-41, 56), Pair(-96, -54), Pair(8, -74), Pair(-18, -23), Pair(-69, -22), Pair(38, -24), Pair(-25, -16)
      },
      { // Piece 4
        Pair(79, 28), Pair(-177, -169), Pair(-1, 12), Pair(-11, -6), Pair(-42, -43), Pair(106, 34), Pair(-4, -15), Pair(114, -83),
        Pair(-54, -72), Pair(-46, -76), Pair(-104, -97), Pair(27, 34), Pair(-55, -162), Pair(-16, -81), Pair(0, 0), Pair(-110, -113),
        Pair(69, 26), Pair(-129, -141), Pair(32, 5), Pair(56, 98), Pair(-28, -37), Pair(30, -91), Pair(-27, 15), Pair(55, 64),
        Pair(139, 45), Pair(-38, -9), Pair(45, 7), Pair(5, 5), Pair(-6, -22), Pair(41, 89), Pair(87, 41), Pair(112, 95),
        Pair(0, -9), Pair(-81, -40), Pair(-39, -29), Pair(-5, 39), Pair(36, 51), Pair(-81, 58), Pair(-102, 8), Pair(-72, -103),
        Pair(-28, -92), Pair(-160, -72), Pair(76, -7), Pair(62, -6), Pair(-150, 42), Pair(-88, 35), Pair(134, 49), Pair(216, 154),
        Pair(60, 42), Pair(-15, -38), Pair(49, 94), Pair(-95, 35), Pair(-57, -111), Pair(-33, -13), Pair(-50, -65), Pair(93, 30),
        Pair(-62, -106), Pair(60, 13), Pair(-112, -28), Pair(-34, 68), Pair(61, -36), Pair(-44, -18), Pair(-179, -26), Pair(153, 74)
      },
      { // Piece 5
        Pair(1, -19), Pair(-10, -97), Pair(10, 32), Pair(28, 95), Pair(-4, 70), Pair(-6, 99), Pair(-22, 41), Pair(9, 17),
        Pair(0, 15), Pair(13, 71), Pair(-29, -106), Pair(-4, -66), Pair(-8, -28), Pair(-70, 76), Pair(0, 0), Pair(-56, 116),
        Pair(-70, -66), Pair(-5, -12), Pair(-14, 22), Pair(-37, -103), Pair(19, 97), Pair(22, 46), Pair(91, 42), Pair(-41, 94),
        Pair(-43, -51), Pair(6, -77), Pair(-14, -73), Pair(53, -38), Pair(16, 27), Pair(44, 73), Pair(50, 39), Pair(91, 57),
        Pair(30, 9), Pair(43, -5), Pair(-4, 29), Pair(-35, -48), Pair(37, -6), Pair(66, -34), Pair(13, 31), Pair(-75, -68),
        Pair(-88, -66), Pair(-7, 30), Pair(6, -58), Pair(-16, -15), Pair(84, -9), Pair(-26, -7), Pair(-3, 64), Pair(-28, 51),
        Pair(45, 27), Pair(58, 14), Pair(-8, -11), Pair(-99, -14), Pair(-77, 7), Pair(2, -40), Pair(-29, 46), Pair(65, 50),
        Pair(18, -191), Pair(-101, 34), Pair(6, -31), Pair(-56, 21), Pair(2, 26), Pair(31, 17), Pair(2, 2), Pair(76, 24)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(36, 44), Pair(26, 33), Pair(-7, 34), Pair(-98, 65), Pair(53, 29), Pair(57, 34), Pair(-14, -129), Pair(-59, -10),
        Pair(-97, 98), Pair(-15, 32), Pair(-98, 6), Pair(50, 18), Pair(38, -17), Pair(-33, 16), Pair(2, -20), Pair(47, -79),
        Pair(78, -6), Pair(2, 7), Pair(59, -16), Pair(-46, 37), Pair(1, 22), Pair(-7, 3), Pair(-18, 38), Pair(-9, 26),
        Pair(-16, 18), Pair(12, -2), Pair(-7, 10), Pair(33, 8), Pair(-17, 24), Pair(4, 12), Pair(5, -6), Pair(69, -27),
        Pair(8, 11), Pair(6, -7), Pair(39, 3), Pair(22, -9), Pair(12, -3), Pair(39, -5), Pair(12, 6), Pair(-10, 26),
        Pair(-16, 35), Pair(-16, 13), Pair(25, -5), Pair(-38, -6), Pair(2, 17), Pair(-22, 5), Pair(-44, 19), Pair(47, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(6, 61), Pair(0, -3), Pair(-12, -42), Pair(1, -16), Pair(19, 49), Pair(18, 46), Pair(-11, 0), Pair(44, 68),
        Pair(60, 51), Pair(44, 78), Pair(-14, -122), Pair(16, 21), Pair(42, 10), Pair(52, 19), Pair(-11, 26), Pair(0, 0),
        Pair(-97, -38), Pair(80, 31), Pair(3, -1), Pair(86, -49), Pair(146, 129), Pair(47, 23), Pair(5, -45), Pair(-26, -71),
        Pair(-69, -42), Pair(-20, 45), Pair(33, -82), Pair(-25, -49), Pair(-22, 70), Pair(59, 51), Pair(148, -45), Pair(135, 23),
        Pair(80, 75), Pair(-51, 41), Pair(-39, -12), Pair(-13, 48), Pair(159, -82), Pair(96, -21), Pair(-53, 62), Pair(141, -39),
        Pair(-11, -85), Pair(21, -53), Pair(-3, -54), Pair(78, 9), Pair(13, 13), Pair(-37, -2), Pair(26, -64), Pair(24, 129),
        Pair(-38, 22), Pair(-31, -13), Pair(32, -120), Pair(-12, 29), Pair(-6, 59), Pair(9, -6), Pair(-1, -74), Pair(-37, 11),
        Pair(-59, -35), Pair(-113, 18), Pair(12, 7), Pair(-8, -47), Pair(-210, -110), Pair(-77, -25), Pair(8, -37), Pair(-39, -27)
      },
      { // Piece 2
        Pair(9, -81), Pair(0, -5), Pair(39, 15), Pair(24, -37), Pair(12, -13), Pair(54, 75), Pair(91, 1), Pair(-3, -76),
        Pair(-67, -12), Pair(16, -115), Pair(-6, 11), Pair(-67, -122), Pair(93, 46), Pair(111, -17), Pair(29, 79), Pair(0, 0),
        Pair(64, -93), Pair(32, 47), Pair(-90, -23), Pair(-13, -6), Pair(93, -33), Pair(-14, -7), Pair(127, 46), Pair(107, 88),
        Pair(20, -34), Pair(126, -34), Pair(-4, 5), Pair(84, -80), Pair(81, -13), Pair(8, 4), Pair(19, 8), Pair(-1, 78),
        Pair(56, -97), Pair(-91, -59), Pair(9, 6), Pair(39, 44), Pair(110, -5), Pair(107, 36), Pair(-114, 74), Pair(29, 33),
        Pair(-25, 78), Pair(21, 11), Pair(146, -3), Pair(6, -21), Pair(7, 2), Pair(125, 5), Pair(124, 61), Pair(141, -113),
        Pair(-90, 57), Pair(7, 75), Pair(58, -25), Pair(-31, -19), Pair(-69, -72), Pair(-17, -92), Pair(-29, -43), Pair(-66, -224),
        Pair(-60, 21), Pair(76, -30), Pair(-1, -50), Pair(81, -87), Pair(-206, -8), Pair(6, -11), Pair(-55, -129), Pair(12, -32)
      },
      { // Piece 3
        Pair(10, 98), Pair(14, 74), Pair(-57, 11), Pair(5, 11), Pair(45, 44), Pair(14, -43), Pair(43, 70), Pair(77, -159),
        Pair(41, -6), Pair(51, 37), Pair(-30, 10), Pair(38, -9), Pair(135, -40), Pair(18, 5), Pair(3, 18), Pair(0, 0),
        Pair(117, -45), Pair(83, -19), Pair(125, -34), Pair(28, -23), Pair(162, -51), Pair(-60, -2), Pair(7, -15), Pair(-47, 44),
        Pair(-7, 38), Pair(47, -24), Pair(89, -65), Pair(25, 11), Pair(64, -85), Pair(32, -96), Pair(-52, 3), Pair(-120, 53),
        Pair(-61, 44), Pair(-24, 28), Pair(-43, 21), Pair(80, 21), Pair(-28, -40), Pair(-35, 25), Pair(55, 60), Pair(-82, -19),
        Pair(53, -48), Pair(-18, 3), Pair(25, 34), Pair(-120, -126), Pair(-40, -116), Pair(-78, -17), Pair(54, 80), Pair(-60, 87),
        Pair(-41, 75), Pair(29, 13), Pair(-47, -21), Pair(-54, -55), Pair(12, -38), Pair(-52, -98), Pair(-8, 13), Pair(-128, 47),
        Pair(8, -56), Pair(114, -9), Pair(-8, -1), Pair(-38, 35), Pair(-30, -69), Pair(-49, -85), Pair(15, 26), Pair(41, -36)
      },
      { // Piece 4
        Pair(-47, -48), Pair(-75, -71), Pair(53, 62), Pair(-37, -64), Pair(97, 100), Pair(4, -2), Pair(-52, -5), Pair(-33, -83),
        Pair(123, 72), Pair(44, -21), Pair(20, -16), Pair(31, -53), Pair(11, -21), Pair(-26, -33), Pair(26, -36), Pair(0, 0),
        Pair(-40, -72), Pair(27, -18), Pair(45, 20), Pair(-34, -16), Pair(70, 49), Pair(15, 12), Pair(60, -9), Pair(27, 160),
        Pair(25, 36), Pair(42, -53), Pair(91, 37), Pair(43, 63), Pair(58, -8), Pair(46, 41), Pair(65, -51), Pair(20, -77),
        Pair(75, -74), Pair(-238, -55), Pair(-159, -118), Pair(55, 48), Pair(107, -93), Pair(-9, -17), Pair(-17, 48), Pair(-14, -114),
        Pair(-91, -29), Pair(-150, -13), Pair(-68, -78), Pair(-7, -115), Pair(-91, 108), Pair(-102, 31), Pair(61, -42), Pair(-104, -150),
        Pair(-4, 12), Pair(-57, -9), Pair(26, 114), Pair(-59, -24), Pair(-12, -150), Pair(24, -16), Pair(-14, 103), Pair(-80, -34),
        Pair(17, -22), Pair(24, 75), Pair(-15, -30), Pair(-144, 42), Pair(-121, -59), Pair(-67, 2), Pair(-58, -50), Pair(3, 19)
      },
      { // Piece 5
        Pair(15, 43), Pair(10, 128), Pair(12, 46), Pair(12, 37), Pair(12, 52), Pair(-5, 108), Pair(28, 73), Pair(-21, -236),
        Pair(20, 51), Pair(21, -83), Pair(-59, -90), Pair(-47, -54), Pair(30, -52), Pair(-9, 104), Pair(62, 91), Pair(0, 0),
        Pair(20, 56), Pair(11, -45), Pair(5, -55), Pair(-3, 125), Pair(43, 37), Pair(-1, 117), Pair(35, 35), Pair(6, 59),
        Pair(98, 34), Pair(-39, 63), Pair(42, 26), Pair(65, -3), Pair(1, 61), Pair(33, -9), Pair(50, 57), Pair(52, -61),
        Pair(-9, -39), Pair(-45, -13), Pair(34, -6), Pair(35, -20), Pair(-29, -16), Pair(-92, 75), Pair(18, 33), Pair(18, 46),
        Pair(-62, -74), Pair(42, -45), Pair(45, 21), Pair(100, -10), Pair(63, -34), Pair(-45, -1), Pair(-54, 39), Pair(46, -26),
        Pair(-106, -67), Pair(24, 17), Pair(-31, -43), Pair(100, -22), Pair(-8, -3), Pair(-131, 63), Pair(57, -14), Pair(-14, 4),
        Pair(-36, 73), Pair(7, -31), Pair(-106, -68), Pair(-109, -12), Pair(-1, -96), Pair(-79, 41), Pair(14, 15), Pair(14, -56)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(59, -85), Pair(-46, 12), Pair(-28, 18), Pair(28, 15), Pair(-107, 50), Pair(74, 16), Pair(4, 50), Pair(-97, 98),
        Pair(0, 31), Pair(6, -21), Pair(-26, 26), Pair(-13, 28), Pair(26, 25), Pair(4, 7), Pair(-34, 5), Pair(-3, 2),
        Pair(49, -31), Pair(-11, -5), Pair(2, 7), Pair(-5, 17), Pair(12, 4), Pair(-9, 13), Pair(2, 9), Pair(-11, 15),
        Pair(-22, 8), Pair(-9, 16), Pair(0, 12), Pair(-4, 8), Pair(2, 5), Pair(-10, 6), Pair(4, 9), Pair(-7, 9),
        Pair(-21, 48), Pair(-8, 14), Pair(-2, 3), Pair(-7, 15), Pair(-1, 5), Pair(1, 12), Pair(-1, 13), Pair(0, 10),
        Pair(-18, 31), Pair(-12, 20), Pair(-7, 3), Pair(15, 3), Pair(-5, 6), Pair(-8, 14), Pair(2, 10), Pair(2, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(70, -10), Pair(-122, 7), Pair(38, 20), Pair(43, -11), Pair(-55, -7), Pair(46, -40), Pair(54, 88), Pair(67, 30),
        Pair(93, -153), Pair(18, -23), Pair(33, -7), Pair(-14, 1), Pair(145, -55), Pair(226, -86), Pair(-33, 98), Pair(-104, 40),
        Pair(0, 0), Pair(31, 13), Pair(52, 2), Pair(20, 7), Pair(27, -54), Pair(46, -19), Pair(28, 8), Pair(4, -20),
        Pair(-23, -39), Pair(18, 54), Pair(42, -12), Pair(-1, 40), Pair(28, -9), Pair(27, 12), Pair(16, -41), Pair(50, -46),
        Pair(26, 1), Pair(62, -10), Pair(-11, 19), Pair(20, -2), Pair(3, 4), Pair(17, 27), Pair(-22, 24), Pair(3, 49),
        Pair(38, -23), Pair(3, 27), Pair(1, 14), Pair(43, 4), Pair(6, -14), Pair(12, 6), Pair(19, -54), Pair(1, -9),
        Pair(-95, -73), Pair(-11, -16), Pair(-48, 7), Pair(-9, 17), Pair(12, -26), Pair(53, -34), Pair(-9, -17), Pair(27, -41),
        Pair(-121, -71), Pair(-30, 21), Pair(-1, -49), Pair(-116, 103), Pair(19, -14), Pair(1, -6), Pair(-11, -114), Pair(-120, -131)
      },
      { // Piece 2
        Pair(65, -57), Pair(153, 25), Pair(172, -86), Pair(30, -17), Pair(51, -72), Pair(-16, -115), Pair(1, -19), Pair(30, -40),
        Pair(19, -49), Pair(35, -7), Pair(101, -6), Pair(187, -61), Pair(8, -20), Pair(-49, -15), Pair(132, -62), Pair(135, 1),
        Pair(0, 0), Pair(123, -3), Pair(149, -54), Pair(17, 57), Pair(41, -24), Pair(-64, 21), Pair(-18, -52), Pair(-127, 35),
        Pair(23, 60), Pair(50, -23), Pair(29, 32), Pair(0, -14), Pair(57, -12), Pair(23, -74), Pair(20, 42), Pair(-23, -25),
        Pair(-4, -33), Pair(4, 9), Pair(27, -23), Pair(11, 40), Pair(57, -22), Pair(21, 0), Pair(-74, 16), Pair(-21, 58),
        Pair(25, 0), Pair(18, -51), Pair(11, -3), Pair(20, -23), Pair(12, 23), Pair(25, -26), Pair(41, -17), Pair(-22, 18),
        Pair(8, -57), Pair(15, -7), Pair(-18, -5), Pair(24, -22), Pair(24, -15), Pair(43, -19), Pair(43, -43), Pair(67, -3),
        Pair(14, 11), Pair(58, -37), Pair(-6, -14), Pair(10, -3), Pair(29, -7), Pair(33, -26), Pair(139, -33), Pair(40, -19)
      },
      { // Piece 3
        Pair(75, -52), Pair(33, 48), Pair(-17, 40), Pair(85, -4), Pair(9, 19), Pair(-69, 2), Pair(9, -1), Pair(-85, 26),
        Pair(46, -99), Pair(100, 0), Pair(-49, 56), Pair(81, -15), Pair(57, -13), Pair(34, 14), Pair(-17, 18), Pair(26, 29),
        Pair(0, 0), Pair(53, 4), Pair(69, -6), Pair(43, 16), Pair(110, -14), Pair(-24, 22), Pair(64, 3), Pair(-74, 53),
        Pair(-37, -7), Pair(19, 29), Pair(2, 27), Pair(39, -3), Pair(-41, 50), Pair(-62, 42), Pair(70, 13), Pair(96, -5),
        Pair(-19, 4), Pair(13, 38), Pair(-6, 55), Pair(-41, 80), Pair(0, 19), Pair(-2, 0), Pair(-47, 7), Pair(37, 17),
        Pair(-29, -6), Pair(10, 56), Pair(28, 1), Pair(38, -15), Pair(-11, 10), Pair(25, -35), Pair(12, 42), Pair(37, 24),
        Pair(-79, 19), Pair(69, -3), Pair(-30, 45), Pair(30, -22), Pair(-3, -2), Pair(-21, 44), Pair(19, 13), Pair(55, -38),
        Pair(-17, -5), Pair(-1, 2), Pair(-4, 24), Pair(11, 18), Pair(16, 10), Pair(-2, 1), Pair(6, 17), Pair(19, -16)
      },
      { // Piece 4
        Pair(30, -52), Pair(-14, 33), Pair(-10, 4), Pair(-12, 45), Pair(75, -26), Pair(-37, -84), Pair(-84, -56), Pair(-35, 47),
        Pair(12, -184), Pair(42, 3), Pair(19, 8), Pair(-62, 49), Pair(67, 45), Pair(70, -99), Pair(-82, 148), Pair(53, 25),
        Pair(0, 0), Pair(60, -18), Pair(-18, 86), Pair(-17, 52), Pair(38, -33), Pair(40, -21), Pair(-10, 26), Pair(-66, 24),
        Pair(45, -60), Pair(13, 16), Pair(-17, 60), Pair(-16, 29), Pair(14, 31), Pair(35, -25), Pair(-10, 6), Pair(11, -21),
        Pair(-4, 12), Pair(-10, 9), Pair(-9, 53), Pair(58, -84), Pair(-14, 53), Pair(24, 9), Pair(-10, -27), Pair(21, -57),
        Pair(17, 31), Pair(-1, 32), Pair(54, -49), Pair(-20, 48), Pair(-4, 52), Pair(24, -25), Pair(-15, -31), Pair(29, -65),
        Pair(1, -29), Pair(23, 17), Pair(-11, 11), Pair(13, 2), Pair(7, 10), Pair(-45, 43), Pair(14, -23), Pair(37, -36),
        Pair(-12, -8), Pair(5, 37), Pair(-4, -6), Pair(-7, 23), Pair(6, -10), Pair(51, -39), Pair(31, -5), Pair(-54, -128)
      },
      { // Piece 5
        Pair(5, -75), Pair(-23, 116), Pair(-70, 91), Pair(19, -53), Pair(-38, -103), Pair(-12, -37), Pair(12, 24), Pair(-5, -33),
        Pair(-47, -42), Pair(-89, 164), Pair(8, 113), Pair(43, 71), Pair(49, 10), Pair(9, -21), Pair(47, -31), Pair(69, 28),
        Pair(0, 0), Pair(57, 86), Pair(127, 79), Pair(77, 34), Pair(35, -28), Pair(54, 36), Pair(41, -28), Pair(-24, 26),
        Pair(125, 13), Pair(70, 53), Pair(46, 75), Pair(209, -7), Pair(-39, 64), Pair(97, 0), Pair(-49, 5), Pair(14, -15),
        Pair(-3, 12), Pair(122, 13), Pair(143, 34), Pair(130, 21), Pair(31, 13), Pair(52, 9), Pair(-39, 14), Pair(-122, 7),
        Pair(66, 36), Pair(-72, 91), Pair(27, 30), Pair(36, 33), Pair(-113, 47), Pair(1, 10), Pair(1, -8), Pair(-88, 2),
        Pair(-4, 53), Pair(38, 57), Pair(41, 21), Pair(-39, 17), Pair(22, 10), Pair(-38, 19), Pair(-2, -4), Pair(-17, -1),
        Pair(89, 51), Pair(57, -9), Pair(74, 1), Pair(14, 35), Pair(-23, 2), Pair(-30, 4), Pair(-10, -2), Pair(-17, -19)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-66, 42), Pair(-49, -56), Pair(70, 13), Pair(-91, 24), Pair(-49, 2), Pair(-3, 25), Pair(52, 82), Pair(-15, 32),
        Pair(5, -21), Pair(8, 33), Pair(-7, 23), Pair(-1, 2), Pair(23, 20), Pair(-55, 36), Pair(2, 4), Pair(36, 1),
        Pair(14, 3), Pair(17, -35), Pair(14, 7), Pair(-1, 7), Pair(-3, 18), Pair(6, 11), Pair(-20, 7), Pair(14, 9),
        Pair(-4, 18), Pair(17, 0), Pair(-7, 11), Pair(5, 6), Pair(2, 8), Pair(-3, 7), Pair(4, 2), Pair(-8, 10),
        Pair(-12, 12), Pair(16, 7), Pair(15, 7), Pair(7, -1), Pair(6, 6), Pair(7, 12), Pair(11, 7), Pair(6, 6),
        Pair(-7, 16), Pair(0, -4), Pair(-25, 23), Pair(10, 6), Pair(-13, -2), Pair(-6, 14), Pair(-2, 12), Pair(1, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-54, -57), Pair(-162, 86), Pair(73, -31), Pair(33, -50), Pair(-118, -13), Pair(44, 46), Pair(-31, 19), Pair(9, 110),
        Pair(-23, 7), Pair(72, -117), Pair(-68, 33), Pair(24, 63), Pair(-41, 74), Pair(8, 9), Pair(97, 63), Pair(-20, -87),
        Pair(-73, 96), Pair(0, 0), Pair(61, -6), Pair(-36, 33), Pair(61, -23), Pair(-12, 21), Pair(141, -88), Pair(40, -22),
        Pair(95, 7), Pair(-31, 58), Pair(50, 28), Pair(67, 3), Pair(27, 30), Pair(9, 48), Pair(8, 5), Pair(-26, 34),
        Pair(-13, 9), Pair(35, 57), Pair(25, 28), Pair(6, 4), Pair(11, -8), Pair(15, 4), Pair(-54, 65), Pair(5, -42),
        Pair(-73, 62), Pair(33, -5), Pair(16, -7), Pair(-45, 44), Pair(56, -12), Pair(19, -5), Pair(69, -76), Pair(39, 12),
        Pair(-132, -14), Pair(138, -64), Pair(27, -32), Pair(7, -1), Pair(-18, 3), Pair(7, 67), Pair(75, -80), Pair(18, -14),
        Pair(76, -92), Pair(-58, -2), Pair(-11, 12), Pair(92, -54), Pair(21, -20), Pair(33, 16), Pair(71, -65), Pair(2, -46)
      },
      { // Piece 2
        Pair(46, -58), Pair(6, 18), Pair(-52, -18), Pair(33, -31), Pair(-18, -34), Pair(10, -17), Pair(-33, -61), Pair(4, -15),
        Pair(-112, 12), Pair(9, -56), Pair(28, -19), Pair(71, -56), Pair(226, -63), Pair(-129, 15), Pair(119, -74), Pair(-63, 27),
        Pair(59, 27), Pair(0, 0), Pair(162, -33), Pair(41, 8), Pair(18, -7), Pair(120, -52), Pair(104, -18), Pair(51, -74),
        Pair(4, -14), Pair(-1, 62), Pair(55, -28), Pair(31, 31), Pair(39, -43), Pair(87, -52), Pair(43, -33), Pair(-4, 3),
        Pair(-4, -3), Pair(12, -7), Pair(46, 3), Pair(38, -19), Pair(74, 3), Pair(28, -29), Pair(-16, 11), Pair(-67, 13),
        Pair(2, 10), Pair(24, 7), Pair(13, -8), Pair(27, 21), Pair(34, -7), Pair(16, 16), Pair(65, 19), Pair(49, -29),
        Pair(67, 38), Pair(0, 6), Pair(38, -8), Pair(19, -35), Pair(12, -4), Pair(66, -26), Pair(26, 46), Pair(66, -65),
        Pair(41, -43), Pair(11, -14), Pair(-9, -13), Pair(22, 30), Pair(-30, -10), Pair(31, 8), Pair(56, -66), Pair(-3, -38)
      },
      { // Piece 3
        Pair(56, 38), Pair(20, -20), Pair(-99, 71), Pair(-32, 63), Pair(93, 5), Pair(37, 22), Pair(36, 33), Pair(116, 5),
        Pair(22, 18), Pair(-73, -57), Pair(90, 12), Pair(33, 35), Pair(38, 11), Pair(17, -40), Pair(42, 32), Pair(22, 26),
        Pair(22, 51), Pair(0, 0), Pair(71, 19), Pair(-45, 49), Pair(19, 20), Pair(52, 21), Pair(-9, 32), Pair(32, 24),
        Pair(19, 31), Pair(30, 28), Pair(62, 44), Pair(17, 15), Pair(27, 29), Pair(131, -44), Pair(-14, 60), Pair(52, 40),
        Pair(-5, 65), Pair(-1, 24), Pair(-42, 96), Pair(-13, 37), Pair(21, -5), Pair(79, 3), Pair(-2, -30), Pair(5, 37),
        Pair(-4, -5), Pair(-24, 40), Pair(6, 71), Pair(32, 1), Pair(-2, 9), Pair(19, 34), Pair(60, 22), Pair(38, -11),
        Pair(-69, 14), Pair(-42, 25), Pair(-67, 57), Pair(20, 51), Pair(-20, 48), Pair(19, 14), Pair(16, -3), Pair(44, 16),
        Pair(-2, 17), Pair(13, 10), Pair(20, 26), Pair(6, 21), Pair(-17, 31), Pair(6, 31), Pair(51, -8), Pair(-35, 12)
      },
      { // Piece 4
        Pair(-2, -5), Pair(18, 16), Pair(3, 39), Pair(-8, 23), Pair(55, -19), Pair(-43, -29), Pair(55, 33), Pair(18, -30),
        Pair(-83, -13), Pair(-117, -2), Pair(30, 23), Pair(31, -22), Pair(-41, 71), Pair(22, 15), Pair(-70, 24), Pair(13, 16),
        Pair(6, 27), Pair(0, 0), Pair(3, 26), Pair(-12, 60), Pair(109, -52), Pair(-97, 52), Pair(42, 16), Pair(-20, 20),
        Pair(30, -31), Pair(14, 19), Pair(52, -5), Pair(24, 71), Pair(30, -16), Pair(-22, 61), Pair(-5, 0), Pair(2, 182),
        Pair(18, -19), Pair(25, 32), Pair(81, -28), Pair(-2, 34), Pair(-43, 77), Pair(-14, 96), Pair(-57, -46), Pair(61, 40),
        Pair(-19, 129), Pair(29, -30), Pair(-6, 44), Pair(-22, -5), Pair(0, 76), Pair(35, -74), Pair(48, 6), Pair(35, -28),
        Pair(2, 63), Pair(24, -43), Pair(21, 1), Pair(-23, 106), Pair(33, -22), Pair(-21, 78), Pair(-45, 36), Pair(79, 2),
        Pair(-40, 70), Pair(-4, -12), Pair(-47, 53), Pair(-4, 1), Pair(-24, -53), Pair(-19, -54), Pair(-57, -21), Pair(6, 2)
      },
      { // Piece 5
        Pair(-1, 130), Pair(68, 146), Pair(52, 240), Pair(-22, -27), Pair(-10, -80), Pair(5, 4), Pair(-49, 5), Pair(-25, -33),
        Pair(34, 145), Pair(73, 57), Pair(73, 42), Pair(21, 70), Pair(42, 30), Pair(-60, -59), Pair(43, 6), Pair(-16, -12),
        Pair(107, 71), Pair(0, 0), Pair(113, 107), Pair(5, 115), Pair(28, -50), Pair(3, -16), Pair(-54, 11), Pair(-89, -15),
        Pair(31, 115), Pair(27, 60), Pair(165, 44), Pair(79, 60), Pair(83, 8), Pair(0, 27), Pair(138, -41), Pair(-87, -19),
        Pair(89, 52), Pair(40, 36), Pair(50, 37), Pair(84, 9), Pair(2, 20), Pair(-40, 15), Pair(-199, 31), Pair(-20, -9),
        Pair(2, 41), Pair(3, 20), Pair(-8, 41), Pair(92, 10), Pair(17, 10), Pair(53, -21), Pair(-21, -8), Pair(-96, 0),
        Pair(131, 10), Pair(148, -13), Pair(26, -1), Pair(-66, 1), Pair(-29, -11), Pair(-82, 25), Pair(-44, -12), Pair(-27, -8),
        Pair(-60, 96), Pair(85, 18), Pair(34, 52), Pair(18, -65), Pair(10, -38), Pair(-37, -4), Pair(-13, -5), Pair(-12, -31)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-51, 63), Pair(25, -44), Pair(12, -74), Pair(20, 12), Pair(-95, 50), Pair(-33, 46), Pair(-37, 15), Pair(-98, 6),
        Pair(-26, 25), Pair(-7, 23), Pair(3, 24), Pair(-21, 30), Pair(-8, -5), Pair(66, 17), Pair(-2, 0), Pair(-41, 35),
        Pair(-2, 11), Pair(17, 25), Pair(-19, -29), Pair(18, 20), Pair(-7, 20), Pair(-1, 17), Pair(-22, 22), Pair(33, 15),
        Pair(-8, 18), Pair(-21, 24), Pair(-6, 1), Pair(1, 11), Pair(-5, 13), Pair(3, 12), Pair(-7, 9), Pair(-4, 5),
        Pair(-10, 11), Pair(-11, 12), Pair(-16, 1), Pair(1, 8), Pair(-5, 9), Pair(17, 2), Pair(-15, 12), Pair(1, 10),
        Pair(-10, 13), Pair(-10, 8), Pair(-8, 6), Pair(-20, 7), Pair(-16, 23), Pair(3, 7), Pair(-16, 14), Pair(-1, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-40, 22), Pair(39, -73), Pair(8, -18), Pair(-63, 24), Pair(18, 51), Pair(-64, -86), Pair(16, 73), Pair(19, 54),
        Pair(-144, 34), Pair(121, 7), Pair(-6, -38), Pair(53, 44), Pair(75, -10), Pair(50, -61), Pair(47, -10), Pair(19, 0),
        Pair(62, -19), Pair(5, 17), Pair(0, 0), Pair(46, 25), Pair(192, -4), Pair(57, 7), Pair(19, 96), Pair(35, 133),
        Pair(-14, 52), Pair(37, 36), Pair(26, 43), Pair(58, 53), Pair(23, -7), Pair(36, -3), Pair(24, -1), Pair(74, -37),
        Pair(14, 6), Pair(63, 27), Pair(-1, 26), Pair(28, 34), Pair(-19, 41), Pair(-19, 92), Pair(-19, 47), Pair(45, -54),
        Pair(61, -14), Pair(-25, 29), Pair(7, 21), Pair(11, 12), Pair(22, -19), Pair(15, 29), Pair(14, 10), Pair(49, -72),
        Pair(72, -31), Pair(63, -68), Pair(21, 20), Pair(3, 54), Pair(-8, 26), Pair(49, 4), Pair(-74, 28), Pair(38, -11),
        Pair(-13, 2), Pair(-8, 25), Pair(-122, 20), Pair(-76, -25), Pair(-36, 78), Pair(-24, 32), Pair(-36, 82), Pair(-43, 41)
      },
      { // Piece 2
        Pair(-50, -89), Pair(58, 17), Pair(45, -54), Pair(35, 1), Pair(-43, 33), Pair(109, 5), Pair(29, -92), Pair(88, -24),
        Pair(-86, 98), Pair(60, -46), Pair(-5, -27), Pair(109, -57), Pair(120, 25), Pair(129, -40), Pair(-47, -35), Pair(-62, -65),
        Pair(55, -40), Pair(216, -45), Pair(0, 0), Pair(98, 27), Pair(101, -33), Pair(121, -45), Pair(63, -106), Pair(17, -63),
        Pair(63, 24), Pair(37, -45), Pair(-22, 59), Pair(34, 14), Pair(-20, 42), Pair(7, -9), Pair(107, -24), Pair(75, -18),
        Pair(24, -5), Pair(98, 9), Pair(-3, -16), Pair(46, 6), Pair(26, 18), Pair(55, 24), Pair(18, -5), Pair(117, -98),
        Pair(18, 26), Pair(81, -75), Pair(-2, 57), Pair(23, 12), Pair(-21, 16), Pair(50, -30), Pair(62, -25), Pair(49, -2),
        Pair(21, -65), Pair(27, 18), Pair(39, -18), Pair(36, -18), Pair(28, -24), Pair(70, 32), Pair(40, -3), Pair(79, 63),
        Pair(48, -4), Pair(-32, -21), Pair(17, -13), Pair(1, 16), Pair(-20, 63), Pair(-4, 16), Pair(30, -21), Pair(-12, -20)
      },
      { // Piece 3
        Pair(6, 45), Pair(111, 68), Pair(15, -1), Pair(-141, 130), Pair(100, 1), Pair(-57, 67), Pair(-98, 64), Pair(-22, 1),
        Pair(-24, 65), Pair(8, 62), Pair(-10, -77), Pair(113, -4), Pair(8, 22), Pair(68, 46), Pair(47, 50), Pair(68, 9),
        Pair(47, 28), Pair(-26, 61), Pair(0, 0), Pair(56, 4), Pair(131, -9), Pair(34, -13), Pair(79, 16), Pair(127, -23),
        Pair(47, 12), Pair(2, 31), Pair(17, 5), Pair(-84, 74), Pair(-16, 15), Pair(-18, 70), Pair(-163, 89), Pair(-1, -12),
        Pair(-19, 49), Pair(11, 60), Pair(-33, 45), Pair(-96, 75), Pair(8, 31), Pair(-7, 3), Pair(58, 6), Pair(-47, -36),
        Pair(-15, 85), Pair(44, -9), Pair(-57, 56), Pair(10, 24), Pair(22, -2), Pair(62, 1), Pair(-20, 22), Pair(6, 10),
        Pair(24, 27), Pair(60, 16), Pair(-22, -3), Pair(-18, 67), Pair(-40, 46), Pair(-101, 37), Pair(2, 25), Pair(30, -3),
        Pair(26, -1), Pair(-22, 25), Pair(-16, 31), Pair(5, 24), Pair(14, 35), Pair(21, 7), Pair(-35, 19), Pair(-7, -19)
      },
      { // Piece 4
        Pair(1, 16), Pair(15, 96), Pair(4, 12), Pair(34, 1), Pair(64, -81), Pair(-71, -68), Pair(-82, -83), Pair(92, -10),
        Pair(87, -59), Pair(24, -45), Pair(13, -148), Pair(-10, 48), Pair(127, -49), Pair(56, -88), Pair(19, 175), Pair(65, 5),
        Pair(61, -36), Pair(-17, 0), Pair(0, 0), Pair(-40, 52), Pair(5, 23), Pair(51, -24), Pair(-95, 77), Pair(-24, -42),
        Pair(-39, 64), Pair(0, 37), Pair(-28, 53), Pair(-21, 41), Pair(85, 8), Pair(-31, 29), Pair(23, -63), Pair(-44, 124),
        Pair(21, 37), Pair(-17, -28), Pair(-13, 29), Pair(48, -21), Pair(-65, 73), Pair(-45, 99), Pair(-47, 15), Pair(67, 29),
        Pair(6, -86), Pair(29, -9), Pair(46, -20), Pair(7, -27), Pair(16, -29), Pair(21, 89), Pair(38, -2), Pair(-9, 143),
        Pair(30, -62), Pair(17, -33), Pair(-17, 23), Pair(-39, 84), Pair(19, -6), Pair(34, -13), Pair(33, -62), Pair(8, 59),
        Pair(32, -19), Pair(13, -15), Pair(13, -47), Pair(32, -51), Pair(42, -71), Pair(18, -58), Pair(63, -82), Pair(-47, -5)
      },
      { // Piece 5
        Pair(-3, 14), Pair(13, 82), Pair(79, 83), Pair(7, 86), Pair(20, 31), Pair(-1, -37), Pair(1, 49), Pair(3, 28),
        Pair(-3, 116), Pair(68, 71), Pair(95, 34), Pair(6, 37), Pair(80, 66), Pair(-1, 29), Pair(11, -20), Pair(36, 29),
        Pair(31, 21), Pair(115, 81), Pair(0, 0), Pair(17, 97), Pair(80, 7), Pair(-70, -8), Pair(10, -11), Pair(63, 52),
        Pair(-112, 117), Pair(84, 63), Pair(4, 81), Pair(26, 59), Pair(76, 35), Pair(-31, 63), Pair(-43, 15), Pair(-83, 43),
        Pair(70, 2), Pair(55, 33), Pair(10, 63), Pair(32, 52), Pair(149, -17), Pair(68, -2), Pair(-4, -31), Pair(-160, 34),
        Pair(52, 56), Pair(22, 46), Pair(33, 7), Pair(-16, 37), Pair(16, 25), Pair(19, -13), Pair(28, -16), Pair(45, -52),
        Pair(70, 49), Pair(17, 6), Pair(12, 25), Pair(-82, 16), Pair(-46, 17), Pair(-7, -14), Pair(-35, 1), Pair(-56, 5),
        Pair(123, 9), Pair(10, 45), Pair(12, 0), Pair(-87, -3), Pair(6, 19), Pair(13, -36), Pair(-34, 3), Pair(-28, -22)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, 18), Pair(-28, 62), Pair(-46, 3), Pair(-11, -61), Pair(60, -18), Pair(-73, 48), Pair(77, 9), Pair(50, 18),
        Pair(-13, 28), Pair(-1, 3), Pair(-20, 30), Pair(12, 6), Pair(22, 23), Pair(51, -5), Pair(-54, 25), Pair(-3, 16),
        Pair(12, 15), Pair(8, 14), Pair(4, 34), Pair(-11, -17), Pair(18, 29), Pair(15, 12), Pair(20, 18), Pair(-17, 22),
        Pair(9, 8), Pair(2, 8), Pair(-14, 22), Pair(-2, 6), Pair(1, 11), Pair(12, 4), Pair(-5, 13), Pair(5, 7),
        Pair(1, 5), Pair(-6, 5), Pair(1, -3), Pair(-5, -2), Pair(5, 7), Pair(2, 10), Pair(-6, 5), Pair(0, 8),
        Pair(-6, 10), Pair(-11, 16), Pair(-11, 6), Pair(1, 7), Pair(-12, 30), Pair(-5, 10), Pair(10, -4), Pair(-5, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-3, 5), Pair(27, 90), Pair(-37, -29), Pair(34, -36), Pair(-53, 61), Pair(-68, -44), Pair(-105, 24), Pair(27, 82),
        Pair(145, 63), Pair(59, 37), Pair(-36, 61), Pair(21, -77), Pair(65, -8), Pair(-53, 80), Pair(-73, -80), Pair(12, -96),
        Pair(-60, 48), Pair(-46, 28), Pair(-18, 61), Pair(0, 0), Pair(74, 76), Pair(109, 31), Pair(71, 53), Pair(-52, 97),
        Pair(54, 53), Pair(25, 45), Pair(24, 65), Pair(31, 72), Pair(42, 48), Pair(55, 29), Pair(50, -27), Pair(-42, 104),
        Pair(60, -34), Pair(60, 36), Pair(19, 28), Pair(-28, 61), Pair(19, 61), Pair(-8, 30), Pair(-8, 55), Pair(-16, 19),
        Pair(17, 71), Pair(-17, 34), Pair(-3, 3), Pair(18, 17), Pair(63, -1), Pair(-30, 38), Pair(8, 8), Pair(-37, 52),
        Pair(-47, -11), Pair(18, -29), Pair(58, -73), Pair(-15, 42), Pair(-9, 34), Pair(54, 61), Pair(35, -19), Pair(-83, 2),
        Pair(79, 55), Pair(-15, 11), Pair(51, -15), Pair(75, -41), Pair(-54, 35), Pair(28, -16), Pair(-22, -53), Pair(-5, -73)
      },
      { // Piece 2
        Pair(159, -86), Pair(-27, 1), Pair(183, -6), Pair(9, -5), Pair(-33, 83), Pair(-83, -24), Pair(-36, 23), Pair(51, -10),
        Pair(4, -49), Pair(11, 15), Pair(67, -18), Pair(-21, -9), Pair(124, -12), Pair(126, -36), Pair(35, -40), Pair(30, 69),
        Pair(60, 51), Pair(80, -47), Pair(13, 17), Pair(0, 0), Pair(136, -37), Pair(119, -31), Pair(82, -32), Pair(26, -4),
        Pair(-11, 26), Pair(26, 21), Pair(-6, 31), Pair(60, 27), Pair(20, 17), Pair(89, -22), Pair(63, -14), Pair(17, 36),
        Pair(38, -2), Pair(18, 13), Pair(0, 68), Pair(48, -24), Pair(28, 13), Pair(42, -6), Pair(15, 25), Pair(12, -8),
        Pair(-25, 14), Pair(21, 15), Pair(58, -10), Pair(31, 22), Pair(34, -16), Pair(3, 36), Pair(34, -8), Pair(31, 46),
        Pair(-41, 2), Pair(-11, 51), Pair(-27, 47), Pair(-6, -8), Pair(22, 38), Pair(65, -46), Pair(58, -13), Pair(42, -35),
        Pair(-3, -14), Pair(6, 81), Pair(11, -13), Pair(-3, 48), Pair(67, -67), Pair(28, 15), Pair(37, 55), Pair(8, 27)
      },
      { // Piece 3
        Pair(-36, 84), Pair(-82, 76), Pair(-6, 21), Pair(35, 29), Pair(0, 45), Pair(97, 32), Pair(-17, 52), Pair(-54, 25),
        Pair(78, 24), Pair(66, 47), Pair(149, -22), Pair(-121, -5), Pair(104, 19), Pair(116, 16), Pair(41, 68), Pair(129, -5),
        Pair(-12, 48), Pair(88, -21), Pair(-43, 57), Pair(0, 0), Pair(134, 6), Pair(-60, 77), Pair(105, -1), Pair(-52, 84),
        Pair(8, 64), Pair(31, 41), Pair(23, 26), Pair(57, -5), Pair(-37, 85), Pair(22, 55), Pair(-50, 85), Pair(62, 4),
        Pair(26, 46), Pair(30, 71), Pair(65, -14), Pair(37, 20), Pair(27, 21), Pair(67, 22), Pair(-106, 14), Pair(30, 24),
        Pair(-2, 27), Pair(26, 32), Pair(-51, 56), Pair(19, 23), Pair(-23, 75), Pair(-13, 60), Pair(65, -85), Pair(-5, 86),
        Pair(-16, 52), Pair(3, 22), Pair(46, 0), Pair(-4, 31), Pair(6, 6), Pair(34, 15), Pair(12, 46), Pair(-59, 74),
        Pair(7, 47), Pair(-3, 38), Pair(4, 44), Pair(18, 18), Pair(16, 35), Pair(-5, 35), Pair(22, 46), Pair(-30, 38)
      },
      { // Piece 4
        Pair(-56, 19), Pair(9, 67), Pair(109, -31), Pair(-33, -61), Pair(-81, 16), Pair(-23, 43), Pair(72, 55), Pair(64, -28),
        Pair(-29, 175), Pair(65, 6), Pair(-59, 98), Pair(-88, -52), Pair(38, -38), Pair(122, -74), Pair(58, 58), Pair(43, 103),
        Pair(47, 2), Pair(32, -21), Pair(-32, 11), Pair(0, 0), Pair(82, -17), Pair(-71, 26), Pair(-41, 133), Pair(41, -20),
        Pair(5, 15), Pair(26, 95), Pair(12, 52), Pair(11, 28), Pair(35, 31), Pair(36, -20), Pair(61, -32), Pair(24, -22),
        Pair(11, -4), Pair(-13, 23), Pair(66, -29), Pair(13, 70), Pair(-21, 57), Pair(-7, 55), Pair(37, 50), Pair(-12, -2),
        Pair(40, -20), Pair(57, -53), Pair(26, -19), Pair(44, -27), Pair(37, 24), Pair(50, -31), Pair(40, -42), Pair(82, -100),
        Pair(25, 19), Pair(-49, 86), Pair(3, 14), Pair(20, 19), Pair(-10, 42), Pair(-7, -3), Pair(22, 11), Pair(-67, 11),
        Pair(17, -96), Pair(61, -43), Pair(26, 34), Pair(-20, 31), Pair(24, -2), Pair(-2, -11), Pair(-85, -7), Pair(9, -42)
      },
      { // Piece 5
        Pair(7, -38), Pair(13, 151), Pair(27, 104), Pair(43, 27), Pair(18, 167), Pair(13, -53), Pair(-2, -25), Pair(3, 17),
        Pair(20, 46), Pair(13, 71), Pair(15, 50), Pair(-44, 2), Pair(65, 89), Pair(15, 109), Pair(19, -17), Pair(16, -20),
        Pair(13, 74), Pair(31, 3), Pair(129, 79), Pair(0, 0), Pair(90, 85), Pair(71, 54), Pair(24, 37), Pair(-1, -34),
        Pair(-43, 20), Pair(63, -2), Pair(112, 48), Pair(6, 79), Pair(74, 35), Pair(44, 28), Pair(-65, 7), Pair(19, -13),
        Pair(33, -17), Pair(29, 33), Pair(139, -3), Pair(62, 7), Pair(-50, 45), Pair(115, -36), Pair(-46, 43), Pair(-148, -15),
        Pair(-133, 78), Pair(25, -43), Pair(107, -14), Pair(-109, 12), Pair(2, -37), Pair(71, -18), Pair(-50, -3), Pair(32, -46),
        Pair(52, -25), Pair(12, -50), Pair(-49, -28), Pair(-106, 7), Pair(-2, -23), Pair(-20, -3), Pair(35, -43), Pair(-14, -6),
        Pair(-6, -5), Pair(41, -9), Pair(-12, -5), Pair(-66, 5), Pair(-17, -43), Pair(-8, -34), Pair(-2, -24), Pair(-11, -20)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-62, 71), Pair(-31, 39), Pair(-66, -8), Pair(-8, 38), Pair(103, -11), Pair(-105, 47), Pair(-47, 26), Pair(38, -17),
        Pair(26, 25), Pair(23, 20), Pair(-8, -5), Pair(22, 23), Pair(6, 4), Pair(18, 34), Pair(34, -14), Pair(-25, 40),
        Pair(-5, 4), Pair(11, 2), Pair(-18, 3), Pair(10, 27), Pair(-26, -13), Pair(30, 21), Pair(4, 3), Pair(15, 2),
        Pair(-4, 3), Pair(11, 9), Pair(21, -3), Pair(-2, 17), Pair(10, -20), Pair(2, 12), Pair(1, 1), Pair(-8, 12),
        Pair(4, 5), Pair(3, 8), Pair(12, 8), Pair(4, 6), Pair(0, 8), Pair(3, 2), Pair(-10, 16), Pair(-3, 7),
        Pair(-4, 10), Pair(16, 1), Pair(17, 6), Pair(17, 12), Pair(8, 13), Pair(3, 11), Pair(-15, 9), Pair(-6, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(37, 77), Pair(-36, 51), Pair(-9, -26), Pair(-18, 38), Pair(32, 47), Pair(70, 110), Pair(74, 11), Pair(-26, 99),
        Pair(-21, -28), Pair(-67, 68), Pair(-16, 122), Pair(76, 4), Pair(-85, 0), Pair(47, -1), Pair(94, 31), Pair(50, 29),
        Pair(62, 29), Pair(72, 117), Pair(53, -4), Pair(68, 14), Pair(0, 0), Pair(118, -30), Pair(71, 70), Pair(-60, 6),
        Pair(-44, 50), Pair(-44, 13), Pair(-23, 49), Pair(71, 77), Pair(-11, 35), Pair(61, 41), Pair(34, -29), Pair(-13, 32),
        Pair(0, 0), Pair(222, -6), Pair(43, -49), Pair(11, 26), Pair(-10, 56), Pair(9, 18), Pair(111, -14), Pair(23, 32),
        Pair(-5, 65), Pair(44, -9), Pair(21, -2), Pair(4, -19), Pair(6, 20), Pair(14, 22), Pair(-26, 43), Pair(-22, -30),
        Pair(-133, -67), Pair(-47, -45), Pair(53, 30), Pair(10, -16), Pair(38, -15), Pair(18, 12), Pair(69, 43), Pair(-14, -46),
        Pair(-51, -81), Pair(2, 8), Pair(72, -75), Pair(7, 10), Pair(-86, 29), Pair(-91, 77), Pair(-23, -68), Pair(-22, 22)
      },
      { // Piece 2
        Pair(93, -94), Pair(32, 8), Pair(73, 14), Pair(148, -30), Pair(35, -89), Pair(45, 10), Pair(9, -57), Pair(45, 31),
        Pair(-47, 35), Pair(91, -2), Pair(27, 4), Pair(91, -23), Pair(-17, -40), Pair(96, -31), Pair(-1, 22), Pair(102, -53),
        Pair(-10, -52), Pair(154, -54), Pair(44, -79), Pair(96, 4), Pair(0, 0), Pair(135, -6), Pair(48, -99), Pair(-40, 81),
        Pair(20, 52), Pair(14, 5), Pair(57, 6), Pair(-2, -10), Pair(73, 41), Pair(76, -13), Pair(37, 41), Pair(-35, -28),
        Pair(104, -74), Pair(-12, 20), Pair(46, -35), Pair(12, 36), Pair(46, -27), Pair(-14, 27), Pair(60, -13), Pair(-44, -42),
        Pair(-2, -7), Pair(67, -12), Pair(17, 15), Pair(92, -23), Pair(13, 9), Pair(24, 2), Pair(-23, 6), Pair(-68, -5),
        Pair(-25, -15), Pair(-4, 30), Pair(82, -70), Pair(7, 23), Pair(31, 29), Pair(19, 22), Pair(1, 27), Pair(-21, 33),
        Pair(-54, 19), Pair(-49, 24), Pair(-25, 30), Pair(74, -48), Pair(-32, 9), Pair(-7, -17), Pair(47, -5), Pair(7, -149)
      },
      { // Piece 3
        Pair(-113, 71), Pair(52, 0), Pair(-2, 35), Pair(16, 38), Pair(-73, 6), Pair(-5, -10), Pair(-114, 93), Pair(-40, 10),
        Pair(5, 24), Pair(-39, 66), Pair(52, 14), Pair(78, 9), Pair(38, -154), Pair(144, -2), Pair(-12, 22), Pair(61, -21),
        Pair(-69, 33), Pair(56, -22), Pair(-2, 7), Pair(135, -33), Pair(0, 0), Pair(-91, 63), Pair(-22, 47), Pair(38, 43),
        Pair(-16, 28), Pair(28, -51), Pair(-2, 45), Pair(74, -44), Pair(85, -46), Pair(-6, 10), Pair(48, 32), Pair(72, 8),
        Pair(-17, -11), Pair(162, -104), Pair(41, 43), Pair(-46, 20), Pair(-18, 6), Pair(19, 7), Pair(50, 59), Pair(12, -53),
        Pair(-65, 22), Pair(14, 27), Pair(-12, 25), Pair(34, -51), Pair(60, -37), Pair(29, -22), Pair(-10, -10), Pair(-14, -16),
        Pair(-122, 69), Pair(18, -4), Pair(5, 19), Pair(29, 10), Pair(-11, 7), Pair(4, 54), Pair(47, 24), Pair(-78, 86),
        Pair(-39, 19), Pair(-8, 45), Pair(3, -3), Pair(10, -16), Pair(25, -1), Pair(-8, 39), Pair(-2, 37), Pair(-2, 35)
      },
      { // Piece 4
        Pair(-51, -3), Pair(-79, 0), Pair(-2, -1), Pair(123, -45), Pair(-50, -14), Pair(48, -19), Pair(-29, 2), Pair(31, 41),
        Pair(48, -92), Pair(-26, 44), Pair(118, -99), Pair(-48, 62), Pair(-164, -6), Pair(83, 71), Pair(71, 46), Pair(51, -19),
        Pair(16, -83), Pair(69, -12), Pair(51, -147), Pair(59, -47), Pair(0, 0), Pair(142, -59), Pair(22, -27), Pair(102, 56),
        Pair(-2, 18), Pair(20, 48), Pair(30, -13), Pair(-8, 20), Pair(-31, 2), Pair(114, -22), Pair(66, -30), Pair(34, -14),
        Pair(-21, 34), Pair(81, -191), Pair(-7, 23), Pair(-49, 57), Pair(-91, 157), Pair(2, 9), Pair(36, -66), Pair(-31, 46),
        Pair(60, -83), Pair(22, -32), Pair(-27, 10), Pair(61, -81), Pair(-44, 12), Pair(36, -17), Pair(37, 16), Pair(-55, 17),
        Pair(9, -122), Pair(-20, 8), Pair(-51, 172), Pair(-44, 57), Pair(-37, 15), Pair(1, -10), Pair(29, 51), Pair(48, -37),
        Pair(-25, -65), Pair(42, -74), Pair(4, -22), Pair(-1, -14), Pair(-5, 5), Pair(34, 143), Pair(75, -10), Pair(94, -27)
      },
      { // Piece 5
        Pair(28, 72), Pair(3, -54), Pair(-1, 11), Pair(31, 126), Pair(39, -22), Pair(-2, 71), Pair(-4, 17), Pair(-1, 64),
        Pair(13, 58), Pair(20, 55), Pair(9, -5), Pair(-41, 9), Pair(4, -22), Pair(-40, 16), Pair(-10, 45), Pair(-10, 8),
        Pair(48, 62), Pair(-33, 9), Pair(79, 61), Pair(88, 44), Pair(0, 0), Pair(106, 65), Pair(88, -2), Pair(-24, -31),
        Pair(51, 22), Pair(70, 3), Pair(-52, 62), Pair(226, 7), Pair(-22, 55), Pair(50, 31), Pair(61, -13), Pair(-8, -4),
        Pair(105, 42), Pair(-113, 37), Pair(-111, 36), Pair(-71, 62), Pair(-4, 18), Pair(22, 10), Pair(-10, 18), Pair(-53, 0),
        Pair(-120, 4), Pair(114, -51), Pair(39, -12), Pair(-11, -11), Pair(-49, 23), Pair(61, -9), Pair(48, -39), Pair(54, -33),
        Pair(-5, 0), Pair(-15, -24), Pair(-108, -15), Pair(-123, -10), Pair(-28, -30), Pair(-41, -7), Pair(0, -25), Pair(40, -43),
        Pair(38, -67), Pair(0, -14), Pair(-16, 4), Pair(29, -70), Pair(18, -65), Pair(7, -21), Pair(15, -41), Pair(43, -60)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-2, 46), Pair(36, 28), Pair(-62, 37), Pair(35, 75), Pair(46, -15), Pair(22, -68), Pair(-17, -12), Pair(-33, 16),
        Pair(4, 7), Pair(-55, 36), Pair(66, 17), Pair(51, -5), Pair(17, 34), Pair(18, -1), Pair(-11, -21), Pair(-10, 3),
        Pair(-9, 10), Pair(19, 6), Pair(38, -6), Pair(-2, 10), Pair(24, 7), Pair(16, -28), Pair(-19, 10), Pair(-13, 11),
        Pair(1, 5), Pair(-6, 11), Pair(-4, 11), Pair(7, 5), Pair(1, 17), Pair(-7, 9), Pair(-18, 19), Pair(-6, 8),
        Pair(9, 6), Pair(0, 15), Pair(-10, 4), Pair(-2, 4), Pair(-18, 9), Pair(6, 17), Pair(-4, 5), Pair(-15, 14),
        Pair(0, 9), Pair(5, 2), Pair(6, 1), Pair(-22, 11), Pair(-62, 60), Pair(-10, 13), Pair(-8, 11), Pair(-8, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(12, 14), Pair(1, 21), Pair(14, 87), Pair(54, 27), Pair(18, 41), Pair(-14, 28), Pair(-61, 56), Pair(-37, -27),
        Pair(-122, -119), Pair(117, 27), Pair(-3, 60), Pair(126, 1), Pair(63, -24), Pair(-102, 4), Pair(145, 36), Pair(-35, -8),
        Pair(-75, 39), Pair(-40, 50), Pair(-42, 43), Pair(52, 34), Pair(32, -23), Pair(0, 0), Pair(197, -97), Pair(51, 28),
        Pair(-72, -15), Pair(9, 21), Pair(-32, 33), Pair(40, 30), Pair(16, 79), Pair(69, 7), Pair(54, 8), Pair(-18, -5),
        Pair(51, 27), Pair(-81, 76), Pair(-39, 31), Pair(22, 18), Pair(56, 27), Pair(-64, 68), Pair(9, 49), Pair(21, -24),
        Pair(-22, 44), Pair(4, 23), Pair(-49, 46), Pair(18, 17), Pair(0, 41), Pair(-36, 48), Pair(-3, -12), Pair(43, 43),
        Pair(40, -67), Pair(48, 26), Pair(-68, 60), Pair(-11, -24), Pair(35, -52), Pair(23, -22), Pair(-52, -33), Pair(-31, -2),
        Pair(-18, -61), Pair(-61, 4), Pair(-61, 119), Pair(-65, -35), Pair(-74, -20), Pair(-88, 17), Pair(10, -98), Pair(63, 26)
      },
      { // Piece 2
        Pair(30, -20), Pair(49, -55), Pair(70, -41), Pair(49, 8), Pair(-15, -58), Pair(-12, -88), Pair(25, 55), Pair(-17, -80),
        Pair(182, -81), Pair(50, -53), Pair(35, -66), Pair(101, -31), Pair(151, -92), Pair(83, -93), Pair(87, -92), Pair(-20, 14),
        Pair(122, 23), Pair(212, -70), Pair(73, -12), Pair(27, -20), Pair(87, -15), Pair(0, 0), Pair(123, -19), Pair(-27, 24),
        Pair(-48, -32), Pair(124, -24), Pair(60, -75), Pair(30, 14), Pair(67, -33), Pair(27, 13), Pair(41, -33), Pair(39, -44),
        Pair(19, 13), Pair(19, -37), Pair(41, -12), Pair(-12, 13), Pair(-5, 37), Pair(-14, -83), Pair(110, -8), Pair(76, -26),
        Pair(-57, -40), Pair(37, 7), Pair(-37, -10), Pair(12, -10), Pair(11, -44), Pair(-32, 28), Pair(73, -30), Pair(18, 10),
        Pair(63, -22), Pair(-15, -31), Pair(84, -41), Pair(16, -41), Pair(3, -19), Pair(-4, -20), Pair(-2, 1), Pair(-16, -33),
        Pair(29, -62), Pair(45, -41), Pair(-34, -55), Pair(10, -18), Pair(33, -6), Pair(-75, -3), Pair(128, -171), Pair(-2, -153)
      },
      { // Piece 3
        Pair(33, 21), Pair(-26, 53), Pair(27, 3), Pair(-58, 84), Pair(17, 79), Pair(36, -17), Pair(42, 7), Pair(8, 29),
        Pair(25, 45), Pair(58, 20), Pair(62, 4), Pair(68, 14), Pair(40, 25), Pair(28, -90), Pair(68, 8), Pair(160, -14),
        Pair(-58, 19), Pair(129, -26), Pair(27, 10), Pair(1, -13), Pair(-18, 43), Pair(0, 0), Pair(107, 10), Pair(-129, 54),
        Pair(28, 32), Pair(-17, 58), Pair(44, 18), Pair(-15, 44), Pair(10, 9), Pair(20, -5), Pair(91, 2), Pair(73, -29),
        Pair(-23, -14), Pair(108, 12), Pair(19, -25), Pair(29, 3), Pair(79, -24), Pair(134, -44), Pair(98, -19), Pair(88, -85),
        Pair(-15, -9), Pair(0, 22), Pair(-33, -2), Pair(-16, 30), Pair(-7, 27), Pair(59, -50), Pair(15, 6), Pair(125, -16),
        Pair(0, -12), Pair(-13, 37), Pair(2, 15), Pair(-25, -7), Pair(21, 13), Pair(31, -42), Pair(30, 42), Pair(-149, 65),
        Pair(8, 1), Pair(13, 2), Pair(4, -13), Pair(-3, -8), Pair(21, -28), Pair(10, -16), Pair(-20, 30), Pair(7, -5)
      },
      { // Piece 4
        Pair(67, -14), Pair(42, -55), Pair(-57, 94), Pair(19, -43), Pair(91, -22), Pair(17, 39), Pair(63, -29), Pair(154, -47),
        Pair(-22, -77), Pair(-69, 72), Pair(78, -91), Pair(65, -76), Pair(117, 51), Pair(122, -166), Pair(-17, 42), Pair(40, -113),
        Pair(-72, -45), Pair(5, 6), Pair(50, -12), Pair(79, 75), Pair(-85, 156), Pair(0, 0), Pair(4, -56), Pair(106, 53),
        Pair(-81, -48), Pair(-72, 36), Pair(-8, -96), Pair(-30, -33), Pair(11, 89), Pair(15, -43), Pair(10, 2), Pair(100, -51),
        Pair(-70, -52), Pair(157, -52), Pair(-74, 85), Pair(-33, 64), Pair(-2, 17), Pair(13, -38), Pair(35, -55), Pair(19, -65),
        Pair(6, -16), Pair(-81, 155), Pair(24, -55), Pair(26, -118), Pair(-29, -14), Pair(21, 8), Pair(-13, -51), Pair(14, 110),
        Pair(72, -31), Pair(59, -36), Pair(-5, -16), Pair(-21, 50), Pair(-32, -15), Pair(-6, -82), Pair(32, -59), Pair(92, -71),
        Pair(9, -19), Pair(-7, -8), Pair(-58, -21), Pair(-46, -20), Pair(-26, -21), Pair(-21, 8), Pair(23, -83), Pair(53, 46)
      },
      { // Piece 5
        Pair(-6, 13), Pair(8, 62), Pair(-1, 60), Pair(6, -18), Pair(-4, 128), Pair(47, 29), Pair(26, 180), Pair(-32, -39),
        Pair(-4, -117), Pair(-45, -20), Pair(-43, -114), Pair(31, 91), Pair(51, 61), Pair(22, 27), Pair(58, 37), Pair(37, 87),
        Pair(19, 36), Pair(60, -65), Pair(46, 42), Pair(55, 0), Pair(-35, 101), Pair(0, 0), Pair(157, 17), Pair(44, 43),
        Pair(8, 5), Pair(-60, -7), Pair(25, -7), Pair(53, 47), Pair(136, 1), Pair(-30, 42), Pair(-29, 22), Pair(7, 30),
        Pair(-89, -61), Pair(9, 12), Pair(16, 14), Pair(35, -7), Pair(-4, 19), Pair(90, 23), Pair(28, 16), Pair(-31, 21),
        Pair(54, 47), Pair(-55, -9), Pair(-82, 11), Pair(1, 4), Pair(91, -11), Pair(5, 0), Pair(-53, -10), Pair(41, -4),
        Pair(-131, 40), Pair(-80, 16), Pair(73, -27), Pair(51, -6), Pair(-29, -29), Pair(-44, 11), Pair(9, -19), Pair(4, -2),
        Pair(19, -43), Pair(-37, -28), Pair(3, -17), Pair(-111, -11), Pair(29, -44), Pair(3, -11), Pair(18, -32), Pair(16, -11)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(31, 5), Pair(39, 46), Pair(-136, 81), Pair(10, 37), Pair(31, 22), Pair(47, -26), Pair(130, -146), Pair(3, -20),
        Pair(-34, 5), Pair(2, 5), Pair(-2, -1), Pair(-54, 25), Pair(35, -14), Pair(-11, -22), Pair(9, 25), Pair(3, -40),
        Pair(-14, -3), Pair(9, 4), Pair(21, 11), Pair(12, 18), Pair(14, 10), Pair(0, -1), Pair(51, -27), Pair(-18, 0),
        Pair(-4, -1), Pair(-18, 20), Pair(14, 15), Pair(-2, 11), Pair(-2, 11), Pair(-3, 20), Pair(10, -4), Pair(3, 10),
        Pair(-18, 8), Pair(-10, 1), Pair(21, -3), Pair(2, 4), Pair(-19, 16), Pair(14, 3), Pair(11, -9), Pair(-11, 1),
        Pair(-14, 4), Pair(-1, 12), Pair(-4, 0), Pair(35, -2), Pair(-30, 43), Pair(-16, 15), Pair(14, -13), Pair(21, -17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(26, -30), Pair(12, 72), Pair(-77, 65), Pair(77, 37), Pair(24, -1), Pair(-18, 41), Pair(-19, 12), Pair(-8, -84),
        Pair(-131, 12), Pair(-90, 28), Pair(-104, 2), Pair(8, -26), Pair(83, -8), Pair(33, 41), Pair(9, -57), Pair(-88, -14),
        Pair(8, -128), Pair(-15, 107), Pair(-71, 9), Pair(-20, 54), Pair(181, -12), Pair(76, -10), Pair(0, 0), Pair(53, -36),
        Pair(-160, -28), Pair(0, 28), Pair(-34, 21), Pair(71, -14), Pair(2, 7), Pair(88, 35), Pair(95, -12), Pair(78, -17),
        Pair(97, -59), Pair(9, 17), Pair(-9, -15), Pair(-30, -24), Pair(50, -22), Pair(2, 35), Pair(77, 12), Pair(-6, 21),
        Pair(-61, -87), Pair(-9, -52), Pair(21, -1), Pair(-30, 12), Pair(-75, -18), Pair(-21, 23), Pair(-9, -59), Pair(55, 2),
        Pair(-85, 20), Pair(-52, -63), Pair(-24, -26), Pair(37, -74), Pair(-67, -12), Pair(-82, -1), Pair(-85, 53), Pair(-24, -113),
        Pair(-18, -2), Pair(-19, -71), Pair(-22, -18), Pair(-57, 75), Pair(-47, 39), Pair(-73, -8), Pair(46, -6), Pair(-103, -63)
      },
      { // Piece 2
        Pair(-40, -48), Pair(41, -52), Pair(-91, -79), Pair(15, -27), Pair(12, -40), Pair(8, -116), Pair(-11, 52), Pair(10, -8),
        Pair(-8, 1), Pair(54, -134), Pair(62, 48), Pair(86, -53), Pair(42, 25), Pair(86, -41), Pair(-118, -18), Pair(-46, -20),
        Pair(89, -96), Pair(150, -6), Pair(-119, -36), Pair(146, 28), Pair(173, -73), Pair(91, 14), Pair(0, 0), Pair(29, -14),
        Pair(35, 67), Pair(-3, -52), Pair(-63, 81), Pair(70, -56), Pair(30, 71), Pair(96, -29), Pair(43, -29), Pair(-40, -82),
        Pair(14, -6), Pair(-9, -6), Pair(29, -16), Pair(-41, 35), Pair(93, -44), Pair(-23, -1), Pair(15, -69), Pair(126, -46),
        Pair(-5, 36), Pair(85, -100), Pair(68, 2), Pair(25, -47), Pair(8, 3), Pair(-90, -24), Pair(-50, 78), Pair(-51, -41),
        Pair(65, 1), Pair(3, 16), Pair(-38, -43), Pair(16, -28), Pair(-34, -24), Pair(17, 47), Pair(-16, -19), Pair(13, -104),
        Pair(-54, -22), Pair(-71, -87), Pair(19, -19), Pair(-18, -43), Pair(-90, 3), Pair(-53, 11), Pair(-23, -57), Pair(-31, -13)
      },
      { // Piece 3
        Pair(29, 18), Pair(71, -15), Pair(-9, 34), Pair(101, -25), Pair(112, 15), Pair(-7, 76), Pair(73, -52), Pair(-24, -4),
        Pair(7, 0), Pair(-12, 28), Pair(-37, 20), Pair(81, -79), Pair(-62, 12), Pair(60, -26), Pair(-72, -109), Pair(-9, 6),
        Pair(-66, 22), Pair(46, -21), Pair(-34, 33), Pair(42, -14), Pair(-24, 33), Pair(137, -51), Pair(0, 0), Pair(36, -33),
        Pair(-9, 11), Pair(92, 3), Pair(25, 22), Pair(-63, 74), Pair(29, -45), Pair(18, 23), Pair(81, 4), Pair(6, -18),
        Pair(-98, 29), Pair(-163, 65), Pair(45, -23), Pair(-19, 48), Pair(6, 7), Pair(105, -84), Pair(-30, -21), Pair(-19, -10),
        Pair(48, -90), Pair(-24, -17), Pair(4, -5), Pair(-38, -47), Pair(-20, -5), Pair(-63, 2), Pair(28, -40), Pair(-4, 24),
        Pair(-24, 14), Pair(101, -18), Pair(-23, -27), Pair(-5, -40), Pair(-17, 5), Pair(-36, -58), Pair(29, -4), Pair(-74, 40),
        Pair(-68, -3), Pair(-57, 19), Pair(-50, 11), Pair(-1, -15), Pair(-32, -20), Pair(21, -33), Pair(13, -6), Pair(38, -55)
      },
      { // Piece 4
        Pair(-12, -45), Pair(-129, -60), Pair(-52, -61), Pair(7, -25), Pair(-68, 5), Pair(66, 50), Pair(147, 65), Pair(34, 63),
        Pair(-75, 163), Pair(-11, 69), Pair(74, -51), Pair(-58, 4), Pair(93, -13), Pair(-18, 56), Pair(51, -175), Pair(106, -20),
        Pair(-114, -34), Pair(7, -88), Pair(-75, -29), Pair(48, -30), Pair(-23, 8), Pair(111, -44), Pair(0, 0), Pair(7, -97),
        Pair(59, -24), Pair(98, 11), Pair(81, 54), Pair(37, -74), Pair(151, 21), Pair(-68, -38), Pair(44, -98), Pair(87, -53),
        Pair(-40, 70), Pair(-112, 106), Pair(7, -13), Pair(9, -2), Pair(-17, -5), Pair(-10, 42), Pair(81, -40), Pair(7, 39),
        Pair(-60, 30), Pair(-23, 120), Pair(105, -60), Pair(21, -2), Pair(14, 25), Pair(3, 5), Pair(-9, 9), Pair(101, -84),
        Pair(104, -21), Pair(-74, 44), Pair(-11, -44), Pair(-19, -107), Pair(-34, -32), Pair(-53, 30), Pair(-23, 56), Pair(-125, -6),
        Pair(-89, -127), Pair(-82, -66), Pair(-15, -57), Pair(22, -104), Pair(-28, -69), Pair(4, -6), Pair(19, -43), Pair(44, 18)
      },
      { // Piece 5
        Pair(13, 186), Pair(37, 63), Pair(38, 196), Pair(-12, -5), Pair(-3, -75), Pair(50, 80), Pair(4, 77), Pair(-16, 22),
        Pair(9, 25), Pair(24, -56), Pair(-28, -14), Pair(34, 39), Pair(-81, 1), Pair(68, -10), Pair(-4, 28), Pair(40, 80),
        Pair(-79, -85), Pair(24, 19), Pair(68, -55), Pair(20, -23), Pair(123, -23), Pair(116, 40), Pair(0, 0), Pair(46, 46),
        Pair(19, 30), Pair(15, 16), Pair(-12, 22), Pair(129, -23), Pair(60, -10), Pair(93, 14), Pair(15, 41), Pair(-22, 31),
        Pair(-67, 1), Pair(-28, 17), Pair(114, -35), Pair(-35, -28), Pair(67, -8), Pair(4, 4), Pair(15, 26), Pair(46, 14),
        Pair(-77, -11), Pair(7, 29), Pair(-94, 6), Pair(-55, 2), Pair(0, -7), Pair(-6, -6), Pair(108, -12), Pair(-41, 45),
        Pair(-87, -30), Pair(-63, -2), Pair(25, -12), Pair(-49, -19), Pair(-78, 11), Pair(2, 10), Pair(33, 10), Pair(67, -49),
        Pair(44, -80), Pair(-49, 27), Pair(-60, 11), Pair(-70, -51), Pair(-40, -11), Pair(50, -18), Pair(17, 6), Pair(6, 9)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-9, 22), Pair(51, 26), Pair(130, -37), Pair(-7, -14), Pair(8, 5), Pair(-2, 7), Pair(47, -42), Pair(47, -79),
        Pair(-2, 3), Pair(36, 1), Pair(-41, 35), Pair(-3, 16), Pair(-25, 40), Pair(-10, 4), Pair(3, -39), Pair(3, 18),
        Pair(5, 17), Pair(13, 5), Pair(0, 8), Pair(20, -9), Pair(-3, 6), Pair(7, -2), Pair(-12, -5), Pair(34, -43),
        Pair(0, 13), Pair(6, 3), Pair(-2, 3), Pair(-7, 5), Pair(2, 0), Pair(5, 7), Pair(10, 12), Pair(23, -1),
        Pair(4, 13), Pair(0, 2), Pair(2, 12), Pair(-7, 0), Pair(-4, -3), Pair(-12, 13), Pair(9, 3), Pair(7, -11),
        Pair(-7, 16), Pair(-2, -2), Pair(3, 5), Pair(9, -19), Pair(3, -3), Pair(7, -1), Pair(11, 4), Pair(-2, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(8, -72), Pair(20, 61), Pair(36, -28), Pair(-98, -21), Pair(-32, 62), Pair(139, -6), Pair(16, 47), Pair(48, -24),
        Pair(10, -23), Pair(-15, -17), Pair(-66, -29), Pair(-54, 0), Pair(45, 7), Pair(-73, 19), Pair(48, -13), Pair(62, -59),
        Pair(38, -143), Pair(95, -113), Pair(-32, 56), Pair(2, 5), Pair(6, -9), Pair(125, -23), Pair(153, -7), Pair(0, 0),
        Pair(-14, -77), Pair(5, 18), Pair(31, 10), Pair(66, 4), Pair(-13, 39), Pair(69, -40), Pair(32, 1), Pair(87, -29),
        Pair(9, -7), Pair(17, -46), Pair(15, -10), Pair(-15, 19), Pair(21, 11), Pair(42, -14), Pair(74, -54), Pair(17, -44),
        Pair(74, -94), Pair(7, -51), Pair(10, -30), Pair(36, -34), Pair(35, -14), Pair(10, -50), Pair(-23, 21), Pair(-16, -75),
        Pair(25, -35), Pair(10, -1), Pair(52, -34), Pair(-8, -10), Pair(5, -24), Pair(1, -50), Pair(58, -12), Pair(-1, -49),
        Pair(23, -85), Pair(-38, -59), Pair(-12, -95), Pair(9, 13), Pair(-19, 1), Pair(-38, -28), Pair(28, -37), Pair(-73, -31)
      },
      { // Piece 2
        Pair(43, -28), Pair(59, -120), Pair(4, -63), Pair(46, -105), Pair(95, -40), Pair(63, -23), Pair(-19, 63), Pair(-154, -47),
        Pair(52, -51), Pair(-31, -54), Pair(-45, -67), Pair(-68, -47), Pair(-13, -28), Pair(3, 0), Pair(138, -38), Pair(-142, -31),
        Pair(58, -7), Pair(126, -60), Pair(128, -47), Pair(115, -24), Pair(51, -32), Pair(75, -79), Pair(161, -32), Pair(0, 0),
        Pair(22, 8), Pair(31, -23), Pair(-51, -14), Pair(84, -49), Pair(42, 4), Pair(-56, 23), Pair(43, -17), Pair(86, -16),
        Pair(162, -24), Pair(-22, -41), Pair(42, -24), Pair(13, 6), Pair(104, -43), Pair(28, -14), Pair(21, -19), Pair(-30, -42),
        Pair(-31, -6), Pair(41, -40), Pair(23, -40), Pair(42, -67), Pair(32, -35), Pair(0, -16), Pair(-2, -37), Pair(32, -27),
        Pair(35, 18), Pair(8, -12), Pair(40, -59), Pair(33, -45), Pair(-7, 2), Pair(7, -46), Pair(20, -24), Pair(-67, -3),
        Pair(-10, -68), Pair(19, -13), Pair(13, -32), Pair(79, -46), Pair(23, -59), Pair(11, -22), Pair(-95, -137), Pair(33, -107)
      },
      { // Piece 3
        Pair(-130, 38), Pair(82, 6), Pair(24, 11), Pair(159, -16), Pair(49, 38), Pair(0, 6), Pair(95, -14), Pair(38, -8),
        Pair(-39, 14), Pair(-62, 47), Pair(-11, 30), Pair(136, -17), Pair(-68, 55), Pair(18, 12), Pair(-4, 28), Pair(187, -126),
        Pair(-69, -4), Pair(-52, 17), Pair(32, -3), Pair(-8, 16), Pair(63, -12), Pair(119, -49), Pair(112, -32), Pair(0, 0),
        Pair(6, -13), Pair(32, -17), Pair(57, -28), Pair(-46, 3), Pair(-36, 5), Pair(-16, 53), Pair(-84, -2), Pair(-38, -39),
        Pair(0, 23), Pair(-23, -4), Pair(17, -2), Pair(11, 9), Pair(-33, 47), Pair(8, -41), Pair(-30, -5), Pair(-36, 8),
        Pair(-23, -5), Pair(12, -53), Pair(64, 9), Pair(40, -72), Pair(54, -67), Pair(1, -16), Pair(-37, 11), Pair(-37, -47),
        Pair(1, 18), Pair(-50, -5), Pair(-1, -50), Pair(4, -34), Pair(-5, -40), Pair(43, -16), Pair(-22, -7), Pair(-48, 5),
        Pair(-6, -24), Pair(16, -30), Pair(0, 13), Pair(-3, 1), Pair(-25, 6), Pair(-4, 2), Pair(3, -3), Pair(-46, -37)
      },
      { // Piece 4
        Pair(-59, -31), Pair(-102, 18), Pair(62, 16), Pair(-40, -59), Pair(104, -11), Pair(6, -54), Pair(83, -42), Pair(6, -44),
        Pair(-8, 52), Pair(-18, 9), Pair(55, -41), Pair(-13, 42), Pair(93, -76), Pair(110, 125), Pair(2, 82), Pair(-162, -98),
        Pair(-71, 131), Pair(29, 4), Pair(4, -24), Pair(84, -1), Pair(69, 56), Pair(32, -21), Pair(48, -52), Pair(0, 0),
        Pair(-130, 70), Pair(-62, 35), Pair(93, 70), Pair(-83, 109), Pair(89, -116), Pair(26, 3), Pair(65, 10), Pair(25, -68),
        Pair(-37, 64), Pair(49, -59), Pair(-29, 25), Pair(27, -2), Pair(-38, 28), Pair(70, -41), Pair(6, 5), Pair(14, 6),
        Pair(63, -170), Pair(-17, -32), Pair(13, 38), Pair(-26, -3), Pair(16, 9), Pair(4, -56), Pair(25, -76), Pair(-13, 44),
        Pair(-98, 41), Pair(-61, 23), Pair(8, -95), Pair(14, -12), Pair(-4, -77), Pair(-7, -18), Pair(-4, 41), Pair(-14, 0),
        Pair(12, -24), Pair(-41, -24), Pair(17, 11), Pair(-10, -29), Pair(-55, 50), Pair(73, -7), Pair(-15, -86), Pair(-63, -96)
      },
      { // Piece 5
        Pair(-14, -41), Pair(-19, 52), Pair(15, 69), Pair(-3, -130), Pair(22, 12), Pair(-4, 6), Pair(-97, 28), Pair(76, 0),
        Pair(-12, -35), Pair(39, 91), Pair(58, -78), Pair(-9, 139), Pair(102, 50), Pair(-6, 10), Pair(17, 71), Pair(-4, -58),
        Pair(-5, 29), Pair(-31, 28), Pair(24, 32), Pair(-21, 37), Pair(25, -3), Pair(137, 23), Pair(140, 20), Pair(0, 0),
        Pair(-58, 9), Pair(-39, 11), Pair(119, -26), Pair(-61, 41), Pair(37, 1), Pair(95, 8), Pair(26, 8), Pair(89, -21),
        Pair(87, 18), Pair(-45, 21), Pair(-74, 11), Pair(14, 28), Pair(-53, 18), Pair(91, -4), Pair(116, 0), Pair(-10, 4),
        Pair(-159, -11), Pair(-24, -10), Pair(-38, 9), Pair(-38, -5), Pair(84, -13), Pair(32, 8), Pair(10, 3), Pair(-14, 31),
        Pair(4, -29), Pair(-29, -3), Pair(-55, 5), Pair(-53, 13), Pair(11, -16), Pair(-45, 10), Pair(-6, 24), Pair(-19, 12),
        Pair(-50, 48), Pair(-19, 18), Pair(-11, -11), Pair(2, -34), Pair(2, -18), Pair(0, 12), Pair(7, 20), Pair(21, -33)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-24, 5), Pair(-47, 47), Pair(47, 10), Pair(58, -1), Pair(44, -8), Pair(40, 6), Pair(16, 23), Pair(78, -6),
        Pair(49, -32), Pair(14, 3), Pair(-2, 11), Pair(12, 15), Pair(-5, 4), Pair(-9, 10), Pair(-14, -3), Pair(6, 17),
        Pair(-2, 10), Pair(-9, -4), Pair(-3, 0), Pair(5, 2), Pair(6, 6), Pair(3, 8), Pair(4, 12), Pair(-11, 7),
        Pair(-2, -10), Pair(-9, 2), Pair(0, 6), Pair(0, 7), Pair(4, 5), Pair(3, 6), Pair(4, 10), Pair(-2, 6),
        Pair(2, 17), Pair(-6, 10), Pair(-3, 9), Pair(1, 4), Pair(2, 10), Pair(7, 6), Pair(4, 9), Pair(0, 8),
        Pair(6, 11), Pair(-8, 10), Pair(-2, 7), Pair(-7, -1), Pair(-2, 8), Pair(-2, 14), Pair(2, 11), Pair(0, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-10, -36), Pair(-102, 37), Pair(-15, 29), Pair(2, -26), Pair(-6, 74), Pair(-23, 39), Pair(53, 5), Pair(54, -30),
        Pair(19, -12), Pair(-14, 2), Pair(-24, 24), Pair(25, 24), Pair(24, 31), Pair(-116, 48), Pair(57, -35), Pair(60, -23),
        Pair(54, -43), Pair(-1, 0), Pair(40, 19), Pair(-31, 40), Pair(1, 16), Pair(-1, 32), Pair(39, -17), Pair(18, -28),
        Pair(0, 0), Pair(12, 22), Pair(0, 19), Pair(29, -4), Pair(11, 17), Pair(5, -4), Pair(-7, 14), Pair(5, 1),
        Pair(-6, 68), Pair(8, 23), Pair(21, 13), Pair(12, 5), Pair(10, 8), Pair(13, 12), Pair(17, -5), Pair(11, 5),
        Pair(9, 19), Pair(-3, 4), Pair(4, -3), Pair(-10, 24), Pair(18, 11), Pair(8, 6), Pair(-4, 4), Pair(24, -58),
        Pair(-47, 37), Pair(83, -56), Pair(-9, 7), Pair(-1, 1), Pair(-3, 18), Pair(0, 16), Pair(13, 9), Pair(-21, 52),
        Pair(-4, -44), Pair(-11, -31), Pair(-20, 22), Pair(52, 1), Pair(9, 0), Pair(5, -2), Pair(18, -30), Pair(106, -142)
      },
      { // Piece 2
        Pair(-135, 16), Pair(83, -42), Pair(-89, 55), Pair(-35, -22), Pair(24, 17), Pair(-21, -34), Pair(87, 6), Pair(-112, -50),
        Pair(13, 7), Pair(6, 35), Pair(51, -38), Pair(3, -12), Pair(1, -43), Pair(-28, 5), Pair(-27, -35), Pair(-40, 81),
        Pair(24, 9), Pair(8, -6), Pair(10, 8), Pair(53, -39), Pair(-7, 8), Pair(64, -37), Pair(-47, 11), Pair(-2, -11),
        Pair(0, 0), Pair(-36, 49), Pair(5, -7), Pair(45, -4), Pair(9, -14), Pair(-2, 15), Pair(16, -27), Pair(17, 13),
        Pair(-1, 40), Pair(13, -13), Pair(24, -3), Pair(16, -10), Pair(19, 30), Pair(12, -2), Pair(17, 19), Pair(-6, -5),
        Pair(-9, -22), Pair(10, 14), Pair(16, -13), Pair(0, 21), Pair(17, -6), Pair(3, 22), Pair(1, -6), Pair(11, -24),
        Pair(11, 7), Pair(8, -12), Pair(-5, -9), Pair(6, -15), Pair(1, 28), Pair(6, 20), Pair(6, 16), Pair(13, -7),
        Pair(11, -21), Pair(-38, 20), Pair(-9, -7), Pair(7, 10), Pair(9, -20), Pair(-3, 25), Pair(35, -16), Pair(-21, 27)
      },
      { // Piece 3
        Pair(-7, -22), Pair(3, 34), Pair(7, 26), Pair(-32, 38), Pair(-34, 47), Pair(28, 3), Pair(-29, 38), Pair(38, 17),
        Pair(-4, -12), Pair(4, 31), Pair(3, 30), Pair(49, 6), Pair(-24, 26), Pair(-39, 31), Pair(28, 26), Pair(13, 6),
        Pair(-54, -3), Pair(7, 41), Pair(19, 36), Pair(-15, 49), Pair(-31, 43), Pair(13, 36), Pair(23, -1), Pair(48, 30),
        Pair(0, 0), Pair(-14, 47), Pair(18, 21), Pair(-18, 50), Pair(5, 32), Pair(13, 24), Pair(-5, 34), Pair(-17, 19),
        Pair(-18, 5), Pair(-23, 35), Pair(10, 35), Pair(10, 25), Pair(0, 21), Pair(21, 35), Pair(-39, 48), Pair(10, 34),
        Pair(-10, 24), Pair(14, 17), Pair(4, 6), Pair(21, 20), Pair(36, 13), Pair(43, -19), Pair(25, 7), Pair(40, -14),
        Pair(-20, 4), Pair(2, 19), Pair(-12, 29), Pair(0, 0), Pair(16, 11), Pair(18, 12), Pair(34, -3), Pair(-40, 10),
        Pair(-11, -16), Pair(0, 25), Pair(9, 15), Pair(2, 19), Pair(4, 20), Pair(2, 14), Pair(23, -3), Pair(31, -22)
      },
      { // Piece 4
        Pair(-11, 6), Pair(44, -14), Pair(-82, 87), Pair(-82, 46), Pair(-23, 29), Pair(76, 14), Pair(169, 8), Pair(-20, 114),
        Pair(-41, 11), Pair(31, -14), Pair(-19, 58), Pair(-59, 52), Pair(-3, 30), Pair(39, 71), Pair(93, 70), Pair(7, 5),
        Pair(-36, -53), Pair(-5, 48), Pair(-13, 28), Pair(-17, 108), Pair(2, 23), Pair(0, 91), Pair(15, -30), Pair(-32, 73),
        Pair(0, 0), Pair(-14, 62), Pair(-32, 68), Pair(23, 40), Pair(32, 17), Pair(13, 11), Pair(45, -31), Pair(26, 5),
        Pair(-13, 16), Pair(-9, 64), Pair(-7, 43), Pair(0, 28), Pair(-30, 58), Pair(27, -22), Pair(24, -32), Pair(13, -49),
        Pair(-11, 61), Pair(11, 38), Pair(-7, 60), Pair(-8, 42), Pair(7, 47), Pair(20, 12), Pair(1, 33), Pair(9, -30),
        Pair(-26, 51), Pair(6, 8), Pair(6, 18), Pair(-1, 35), Pair(4, 9), Pair(38, -42), Pair(20, -10), Pair(22, -32),
        Pair(13, -67), Pair(-3, -22), Pair(6, -10), Pair(10, 4), Pair(8, 0), Pair(62, -39), Pair(9, -2), Pair(48, 86)
      },
      { // Piece 5
        Pair(-14, -9), Pair(43, 72), Pair(-14, 81), Pair(62, -29), Pair(14, 130), Pair(2, 62), Pair(37, -28), Pair(45, 29),
        Pair(-101, 95), Pair(29, 157), Pair(-31, 57), Pair(3, 57), Pair(-36, 7), Pair(-15, 31), Pair(20, -33), Pair(49, -73),
        Pair(58, 38), Pair(120, 53), Pair(56, 95), Pair(36, 38), Pair(108, 20), Pair(61, -11), Pair(-46, 20), Pair(-42, 6),
        Pair(0, 0), Pair(42, 46), Pair(25, 67), Pair(-27, 50), Pair(124, 16), Pair(-7, 16), Pair(-26, -6), Pair(-45, 12),
        Pair(-11, 14), Pair(66, 29), Pair(-37, 60), Pair(-39, 40), Pair(-39, 36), Pair(70, 2), Pair(-13, 2), Pair(-58, 2),
        Pair(97, -5), Pair(44, 38), Pair(-44, 32), Pair(-49, 42), Pair(-46, 38), Pair(-28, 16), Pair(-15, 2), Pair(-15, -12),
        Pair(86, -42), Pair(53, 22), Pair(-24, 33), Pair(-22, 21), Pair(-20, 19), Pair(-29, 18), Pair(-14, 8), Pair(-17, -5),
        Pair(95, 41), Pair(38, 7), Pair(6, 14), Pair(-30, 21), Pair(-25, 8), Pair(-19, -7), Pair(1, -12), Pair(-5, -10)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-9, 26), Pair(-4, -8), Pair(-43, 46), Pair(-30, 16), Pair(17, 3), Pair(-25, 26), Pair(-81, 13), Pair(2, 6),
        Pair(-12, -5), Pair(18, -35), Pair(16, 25), Pair(8, 13), Pair(11, 2), Pair(18, 6), Pair(10, 5), Pair(14, 5),
        Pair(-8, -5), Pair(-1, 16), Pair(-3, 1), Pair(-2, -3), Pair(6, 8), Pair(5, 7), Pair(5, 14), Pair(3, 8),
        Pair(0, 2), Pair(3, -12), Pair(3, 1), Pair(7, 3), Pair(4, 9), Pair(9, 7), Pair(5, 8), Pair(-2, 8),
        Pair(-3, 12), Pair(4, 10), Pair(-5, 3), Pair(6, 9), Pair(1, 7), Pair(3, 8), Pair(5, 10), Pair(-1, 10),
        Pair(-2, 9), Pair(6, 3), Pair(-5, 7), Pair(9, 1), Pair(-4, 11), Pair(4, 9), Pair(2, 8), Pair(0, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(107, 75), Pair(64, -11), Pair(-72, 74), Pair(25, 75), Pair(-67, 51), Pair(-201, 96), Pair(0, -121), Pair(-87, -200),
        Pair(19, -16), Pair(39, 24), Pair(-50, 53), Pair(-50, 97), Pair(73, 23), Pair(15, -14), Pair(-10, 117), Pair(-81, 54),
        Pair(9, 23), Pair(-23, 9), Pair(44, -3), Pair(49, 21), Pair(-18, 39), Pair(40, 63), Pair(33, 26), Pair(-21, 21),
        Pair(25, 11), Pair(0, 0), Pair(41, 31), Pair(6, 30), Pair(1, 32), Pair(-1, 26), Pair(15, 20), Pair(-6, 43),
        Pair(0, 61), Pair(42, 43), Pair(9, 30), Pair(7, 25), Pair(-3, 45), Pair(16, 33), Pair(2, 33), Pair(1, 30),
        Pair(-18, -1), Pair(22, 8), Pair(2, 17), Pair(15, 14), Pair(11, 42), Pair(7, 17), Pair(-7, 34), Pair(11, 19),
        Pair(-25, -24), Pair(17, -5), Pair(4, 13), Pair(1, 29), Pair(1, 27), Pair(-7, 2), Pair(-7, 37), Pair(8, 7),
        Pair(-20, 1), Pair(4, -15), Pair(-61, -4), Pair(-7, 44), Pair(3, 2), Pair(-2, 29), Pair(9, 25), Pair(30, -44)
      },
      { // Piece 2
        Pair(38, -3), Pair(55, 10), Pair(29, 5), Pair(-68, 65), Pair(-18, -29), Pair(10, -23), Pair(53, -23), Pair(109, -50),
        Pair(93, -16), Pair(8, -3), Pair(-29, 75), Pair(-44, -23), Pair(-21, -2), Pair(-19, -3), Pair(38, 36), Pair(18, -7),
        Pair(-19, 0), Pair(36, -11), Pair(68, -14), Pair(40, 7), Pair(36, -10), Pair(40, -15), Pair(60, -26), Pair(-10, -12),
        Pair(-10, 39), Pair(0, 0), Pair(-4, 19), Pair(24, -21), Pair(31, -8), Pair(40, -35), Pair(-3, 25), Pair(-1, 10),
        Pair(-47, -33), Pair(18, 27), Pair(14, -2), Pair(19, 16), Pair(20, 12), Pair(-6, 18), Pair(8, -8), Pair(25, -5),
        Pair(-2, -15), Pair(7, 10), Pair(9, 1), Pair(5, -1), Pair(7, 29), Pair(6, 17), Pair(4, 50), Pair(-1, -17),
        Pair(-10, -7), Pair(7, 12), Pair(3, -1), Pair(3, 10), Pair(3, -5), Pair(15, 25), Pair(6, 4), Pair(-3, 51),
        Pair(18, -16), Pair(54, -44), Pair(-14, 18), Pair(-10, -3), Pair(2, 10), Pair(-1, 7), Pair(18, 44), Pair(26, -60)
      },
      { // Piece 3
        Pair(14, 22), Pair(-100, 44), Pair(25, 14), Pair(-82, 89), Pair(-16, 28), Pair(-78, 35), Pair(14, 64), Pair(34, 28),
        Pair(-4, 28), Pair(16, 6), Pair(-4, 34), Pair(36, 32), Pair(37, 15), Pair(-101, 92), Pair(-52, 42), Pair(-47, 58),
        Pair(-15, 55), Pair(-43, 7), Pair(-14, 50), Pair(-14, 51), Pair(4, 59), Pair(-90, 84), Pair(47, 32), Pair(-30, 81),
        Pair(-37, 62), Pair(0, 0), Pair(1, 38), Pair(-6, 37), Pair(22, 22), Pair(29, 29), Pair(-50, 72), Pair(6, 33),
        Pair(-19, 50), Pair(3, 50), Pair(7, 26), Pair(11, 42), Pair(0, 38), Pair(-3, 21), Pair(-1, 50), Pair(7, 43),
        Pair(-1, 18), Pair(11, -14), Pair(2, 31), Pair(18, 14), Pair(-3, 30), Pair(5, 17), Pair(-12, 22), Pair(14, -13),
        Pair(6, 21), Pair(-9, 5), Pair(-10, 37), Pair(6, 28), Pair(18, 4), Pair(-2, 19), Pair(14, 17), Pair(5, 22),
        Pair(2, 22), Pair(-8, 20), Pair(-1, 24), Pair(-1, 27), Pair(-7, 27), Pair(-7, 34), Pair(1, 13), Pair(10, 3)
      },
      { // Piece 4
        Pair(22, -1), Pair(35, -59), Pair(-61, 52), Pair(-118, 62), Pair(61, -72), Pair(83, -81), Pair(-1, 0), Pair(20, -64),
        Pair(16, -17), Pair(26, -34), Pair(12, -14), Pair(3, 72), Pair(-7, 43), Pair(38, 7), Pair(-2, -14), Pair(75, -23),
        Pair(-44, 14), Pair(-28, -11), Pair(36, -17), Pair(26, 20), Pair(-1, 23), Pair(-11, 45), Pair(-11, 17), Pair(9, 32),
        Pair(-23, 37), Pair(0, 0), Pair(10, 46), Pair(-14, 45), Pair(-34, 70), Pair(3, 15), Pair(1, 8), Pair(8, 35),
        Pair(-16, 51), Pair(2, 17), Pair(24, -12), Pair(11, 4), Pair(-5, 36), Pair(-13, 13), Pair(-5, 11), Pair(-5, -3),
        Pair(-28, 79), Pair(6, -8), Pair(-14, 28), Pair(9, 17), Pair(20, -31), Pair(-11, 71), Pair(-3, -5), Pair(27, -24),
        Pair(7, -17), Pair(-15, 21), Pair(8, 10), Pair(1, 25), Pair(9, -6), Pair(21, 7), Pair(-4, -1), Pair(-4, -58),
        Pair(-6, -4), Pair(-17, 23), Pair(5, -3), Pair(-4, 11), Pair(-25, 40), Pair(-4, 68), Pair(98, -11), Pair(57, -78)
      },
      { // Piece 5
        Pair(12, 59), Pair(33, 138), Pair(36, 174), Pair(50, 86), Pair(12, 144), Pair(19, -42), Pair(32, -4), Pair(6, -7),
        Pair(-119, 118), Pair(-186, 125), Pair(-16, 91), Pair(48, 45), Pair(154, 58), Pair(-10, 1), Pair(39, 21), Pair(53, 32),
        Pair(119, 13), Pair(3, 32), Pair(173, 17), Pair(-67, 100), Pair(-16, 24), Pair(33, 37), Pair(80, 7), Pair(9, -1),
        Pair(94, 73), Pair(0, 0), Pair(108, 60), Pair(-7, 37), Pair(17, 12), Pair(-17, 10), Pair(-108, 24), Pair(-85, 10),
        Pair(76, 29), Pair(91, 35), Pair(63, 30), Pair(-99, 66), Pair(-3, 24), Pair(-12, 16), Pair(12, -1), Pair(-117, 1),
        Pair(-29, 46), Pair(71, 13), Pair(77, 19), Pair(-18, 30), Pair(-19, 15), Pair(-30, 15), Pair(-39, 18), Pair(-7, 1),
        Pair(85, 17), Pair(67, 22), Pair(29, 14), Pair(10, 5), Pair(-20, 10), Pair(-37, 19), Pair(-21, 12), Pair(-7, -7),
        Pair(4, 21), Pair(54, -39), Pair(23, 1), Pair(-16, 27), Pair(-19, 5), Pair(-15, 6), Pair(-1, -11), Pair(-2, -13)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(18, -6), Pair(-29, 22), Pair(-35, 19), Pair(17, 7), Pair(74, 15), Pair(-52, 25), Pair(16, -2), Pair(59, -16),
        Pair(2, 6), Pair(15, 7), Pair(-19, -29), Pair(4, 34), Pair(-18, 3), Pair(38, -7), Pair(20, 10), Pair(0, 7),
        Pair(-3, 0), Pair(-3, 1), Pair(-4, 4), Pair(2, 7), Pair(6, -2), Pair(7, 16), Pair(-8, 13), Pair(6, 6),
        Pair(0, 9), Pair(5, 9), Pair(-10, -23), Pair(9, 9), Pair(2, 3), Pair(10, 4), Pair(-2, 6), Pair(-4, 7),
        Pair(2, 11), Pair(-1, 6), Pair(-3, 4), Pair(-3, 15), Pair(3, 8), Pair(7, 4), Pair(0, 12), Pair(4, 6),
        Pair(3, 2), Pair(-6, 11), Pair(-3, 0), Pair(-6, 27), Pair(1, 4), Pair(5, 8), Pair(1, 7), Pair(4, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-94, 69), Pair(40, 83), Pair(47, -21), Pair(88, 43), Pair(-46, 66), Pair(139, -11), Pair(-10, 3), Pair(-8, -29),
        Pair(58, 62), Pair(6, 20), Pair(27, 36), Pair(-50, 26), Pair(37, 0), Pair(40, 24), Pair(-34, 85), Pair(-11, -21),
        Pair(-62, 20), Pair(-21, 9), Pair(-13, 24), Pair(39, 18), Pair(9, 15), Pair(42, -1), Pair(-51, 84), Pair(-57, 32),
        Pair(-7, 18), Pair(7, 32), Pair(0, 0), Pair(12, 51), Pair(11, 33), Pair(59, 11), Pair(-9, 18), Pair(5, 22),
        Pair(-22, 3), Pair(46, 25), Pair(26, 52), Pair(1, 54), Pair(-3, 32), Pair(12, 15), Pair(40, 5), Pair(14, -11),
        Pair(2, 33), Pair(0, 3), Pair(12, 15), Pair(10, 22), Pair(-2, 39), Pair(9, 13), Pair(5, 5), Pair(-4, 24),
        Pair(16, -16), Pair(3, 0), Pair(7, 20), Pair(-3, 24), Pair(-1, 16), Pair(23, 15), Pair(-23, 36), Pair(0, 29),
        Pair(4, -65), Pair(7, -3), Pair(-38, -4), Pair(-48, 57), Pair(3, 26), Pair(-3, 30), Pair(23, 18), Pair(102, 73)
      },
      { // Piece 2
        Pair(61, 21), Pair(27, -44), Pair(173, 10), Pair(21, -37), Pair(-72, -15), Pair(46, -20), Pair(65, 19), Pair(35, 24),
        Pair(38, -13), Pair(0, 39), Pair(-13, 0), Pair(42, 56), Pair(39, -9), Pair(44, 5), Pair(84, -26), Pair(-29, 19),
        Pair(5, 24), Pair(-56, -11), Pair(56, -46), Pair(18, -19), Pair(43, -1), Pair(-12, 9), Pair(4, 20), Pair(14, -10),
        Pair(-38, -2), Pair(18, 17), Pair(0, 0), Pair(15, 13), Pair(31, 0), Pair(6, 53), Pair(2, 0), Pair(-1, 74),
        Pair(27, 27), Pair(-8, -7), Pair(38, 38), Pair(8, 9), Pair(12, 32), Pair(6, 10), Pair(-15, 45), Pair(28, -48),
        Pair(-12, -23), Pair(6, 24), Pair(14, -9), Pair(3, 37), Pair(3, -5), Pair(13, 31), Pair(29, -11), Pair(23, 18),
        Pair(25, -10), Pair(-5, 7), Pair(17, 37), Pair(-4, -1), Pair(12, 17), Pair(-7, -12), Pair(16, 28), Pair(27, -17),
        Pair(-10, -8), Pair(7, 41), Pair(-11, -7), Pair(-3, 12), Pair(6, -5), Pair(11, 21), Pair(-29, 18), Pair(23, 53)
      },
      { // Piece 3
        Pair(-39, 73), Pair(19, 26), Pair(16, 0), Pair(-75, 50), Pair(-23, 30), Pair(-151, 59), Pair(-50, 45), Pair(87, 28),
        Pair(14, 29), Pair(-7, 30), Pair(10, 0), Pair(62, 7), Pair(65, 5), Pair(-24, 46), Pair(7, 38), Pair(71, 10),
        Pair(25, 23), Pair(18, 38), Pair(12, -21), Pair(1, 34), Pair(63, 14), Pair(4, 47), Pair(25, -3), Pair(89, 24),
        Pair(-20, 27), Pair(11, 33), Pair(0, 0), Pair(31, 21), Pair(6, 35), Pair(13, 42), Pair(23, 65), Pair(22, 22),
        Pair(5, 52), Pair(18, 30), Pair(1, 32), Pair(-15, 58), Pair(-14, 41), Pair(-22, 15), Pair(-24, 17), Pair(-33, 19),
        Pair(19, 22), Pair(-7, 39), Pair(-4, 9), Pair(11, 3), Pair(-11, 38), Pair(-6, 22), Pair(-8, 44), Pair(56, -6),
        Pair(16, 32), Pair(4, 9), Pair(13, -2), Pair(-3, 23), Pair(5, 15), Pair(-11, 33), Pair(9, 21), Pair(-33, 56),
        Pair(-1, 23), Pair(3, 30), Pair(-2, 6), Pair(6, 9), Pair(3, 18), Pair(0, 10), Pair(7, 26), Pair(10, 1)
      },
      { // Piece 4
        Pair(39, 9), Pair(35, -61), Pair(-47, 34), Pair(-3, 15), Pair(-23, -4), Pair(54, 4), Pair(52, -77), Pair(54, 19),
        Pair(5, -40), Pair(-10, 23), Pair(9, 13), Pair(27, 41), Pair(59, -22), Pair(24, -59), Pair(103, -62), Pair(4, -9),
        Pair(-29, 74), Pair(-16, 16), Pair(-11, -21), Pair(-26, 89), Pair(2, 48), Pair(-17, 31), Pair(-30, 42), Pair(-31, 30),
        Pair(-4, 45), Pair(-9, 63), Pair(0, 0), Pair(-25, 92), Pair(-7, 53), Pair(-11, 25), Pair(-20, 63), Pair(-15, 10),
        Pair(-11, 53), Pair(1, -19), Pair(-12, 42), Pair(-2, 25), Pair(1, 36), Pair(11, 0), Pair(-19, 40), Pair(5, -17),
        Pair(10, -39), Pair(-1, 22), Pair(-4, 12), Pair(14, -21), Pair(-25, 59), Pair(3, 45), Pair(-11, 31), Pair(-27, 14),
        Pair(-6, -3), Pair(-28, 52), Pair(-4, 3), Pair(-3, 29), Pair(0, 16), Pair(-2, 15), Pair(-30, 49), Pair(48, -122),
        Pair(14, -53), Pair(-34, 69), Pair(-16, 33), Pair(-6, 20), Pair(1, 19), Pair(16, -2), Pair(43, 8), Pair(-3, 29)
      },
      { // Piece 5
        Pair(-13, 45), Pair(27, 72), Pair(41, 131), Pair(18, 109), Pair(-1, -16), Pair(151, -9), Pair(-5, 70), Pair(-26, -5),
        Pair(17, 17), Pair(31, 189), Pair(123, 79), Pair(-16, 115), Pair(20, -62), Pair(-36, 14), Pair(-137, 75), Pair(-57, -25),
        Pair(55, 53), Pair(122, 9), Pair(128, 44), Pair(101, 31), Pair(-5, 85), Pair(41, 18), Pair(10, 46), Pair(-40, 63),
        Pair(63, 63), Pair(26, 38), Pair(0, 0), Pair(154, 38), Pair(116, 14), Pair(149, 1), Pair(-26, 4), Pair(4, -34),
        Pair(-16, 75), Pair(16, 38), Pair(16, 53), Pair(70, 19), Pair(-98, 33), Pair(-23, 7), Pair(-53, 6), Pair(-18, -19),
        Pair(-20, 16), Pair(-11, 18), Pair(-68, 24), Pair(27, 20), Pair(-13, 10), Pair(-24, 11), Pair(-4, -5), Pair(-28, -10),
        Pair(6, 33), Pair(-6, 14), Pair(12, -19), Pair(20, -4), Pair(-15, -9), Pair(-1, -14), Pair(-4, -14), Pair(-3, -11),
        Pair(-8, -6), Pair(17, -16), Pair(11, -12), Pair(0, 14), Pair(-6, -30), Pair(-14, -14), Pair(-1, -18), Pair(5, -40)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, 31), Pair(-9, 21), Pair(-21, 61), Pair(-39, -9), Pair(-2, 19), Pair(-2, 1), Pair(22, -4), Pair(-46, 37),
        Pair(-6, 17), Pair(-1, 7), Pair(17, 19), Pair(-11, -17), Pair(9, 26), Pair(-2, 10), Pair(11, 18), Pair(21, -8),
        Pair(4, 2), Pair(-1, -3), Pair(3, 7), Pair(0, -10), Pair(2, 11), Pair(-1, 0), Pair(3, 10), Pair(6, 5),
        Pair(-1, 7), Pair(2, 4), Pair(3, 4), Pair(-5, 1), Pair(9, 9), Pair(5, 5), Pair(3, 2), Pair(-1, 4),
        Pair(-3, 5), Pair(3, 7), Pair(-5, 9), Pair(6, 9), Pair(0, 14), Pair(8, 8), Pair(4, 5), Pair(4, 3),
        Pair(-5, 9), Pair(-1, 8), Pair(-1, 6), Pair(5, 14), Pair(-3, 23), Pair(-2, 10), Pair(0, 8), Pair(1, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(79, -24), Pair(-27, 60), Pair(42, 8), Pair(65, 33), Pair(-77, 53), Pair(-81, 31), Pair(123, 16), Pair(-53, 82),
        Pair(-12, 86), Pair(-36, 73), Pair(30, -2), Pair(-26, 63), Pair(40, 1), Pair(35, 26), Pair(-27, 90), Pair(-48, 45),
        Pair(4, 7), Pair(44, 33), Pair(33, 13), Pair(2, -17), Pair(29, 23), Pair(32, 11), Pair(19, 30), Pair(-28, 21),
        Pair(63, 40), Pair(15, 27), Pair(36, 40), Pair(0, 0), Pair(-1, 57), Pair(23, 39), Pair(-7, 53), Pair(3, 41),
        Pair(16, 12), Pair(16, 60), Pair(21, 45), Pair(23, 47), Pair(9, 63), Pair(2, 13), Pair(-19, 24), Pair(7, 34),
        Pair(2, 27), Pair(-10, 29), Pair(3, 18), Pair(1, 22), Pair(4, 8), Pair(5, 34), Pair(12, 28), Pair(10, 6),
        Pair(-44, 91), Pair(25, 2), Pair(4, 9), Pair(9, 44), Pair(4, 41), Pair(9, 13), Pair(-12, 60), Pair(-5, 30),
        Pair(139, 23), Pair(3, -22), Pair(-7, 13), Pair(8, 13), Pair(-15, 39), Pair(5, 45), Pair(-3, 10), Pair(113, -90)
      },
      { // Piece 2
        Pair(-47, -87), Pair(-22, 22), Pair(155, -61), Pair(38, -6), Pair(5, -28), Pair(55, -36), Pair(-29, -55), Pair(54, 1),
        Pair(26, -6), Pair(-29, -59), Pair(43, 28), Pair(-12, -37), Pair(22, 22), Pair(35, -39), Pair(34, 25), Pair(-64, -56),
        Pair(17, -46), Pair(32, 24), Pair(-24, -22), Pair(21, -16), Pair(33, -3), Pair(52, 17), Pair(44, -14), Pair(-1, 24),
        Pair(19, 9), Pair(0, 7), Pair(14, 17), Pair(0, 0), Pair(4, 25), Pair(27, -19), Pair(8, 49), Pair(2, -4),
        Pair(30, -11), Pair(22, 37), Pair(15, -23), Pair(42, 26), Pair(-8, -1), Pair(13, 21), Pair(4, -18), Pair(10, 35),
        Pair(4, 21), Pair(-18, -23), Pair(21, 7), Pair(0, -4), Pair(8, 36), Pair(-1, -22), Pair(29, 5), Pair(20, -25),
        Pair(-14, -58), Pair(12, 16), Pair(13, -10), Pair(18, 22), Pair(1, -2), Pair(8, 21), Pair(-7, -7), Pair(5, 5),
        Pair(48, -30), Pair(23, -37), Pair(8, 22), Pair(21, -39), Pair(-8, 33), Pair(-4, -5), Pair(34, -8), Pair(-23, -5)
      },
      { // Piece 3
        Pair(47, 7), Pair(-9, 31), Pair(-42, 63), Pair(-16, 12), Pair(-72, 61), Pair(-87, 46), Pair(-64, 48), Pair(100, -9),
        Pair(-11, 42), Pair(7, 32), Pair(-15, 36), Pair(-1, 1), Pair(31, -7), Pair(-13, 27), Pair(52, -2), Pair(-13, 13),
        Pair(1, 19), Pair(-18, 46), Pair(-3, 20), Pair(-70, -16), Pair(18, 41), Pair(-50, 76), Pair(58, 6), Pair(28, 37),
        Pair(-3, 18), Pair(5, 16), Pair(-17, 11), Pair(0, 0), Pair(3, 25), Pair(17, 4), Pair(51, 9), Pair(26, 18),
        Pair(10, 16), Pair(0, 19), Pair(9, 14), Pair(44, -6), Pair(11, 17), Pair(8, 15), Pair(-4, 35), Pair(-21, 29),
        Pair(8, 3), Pair(3, 32), Pair(4, 20), Pair(-13, 17), Pair(20, 1), Pair(-8, 22), Pair(19, 27), Pair(12, 34),
        Pair(9, 14), Pair(11, 3), Pair(4, 0), Pair(-13, 17), Pair(-4, 20), Pair(-6, 5), Pair(-3, 6), Pair(-1, 14),
        Pair(0, 18), Pair(1, 12), Pair(-6, 25), Pair(10, 1), Pair(-1, 16), Pair(1, 16), Pair(9, 13), Pair(6, 0)
      },
      { // Piece 4
        Pair(-86, 55), Pair(-55, 92), Pair(-41, 33), Pair(-71, 75), Pair(-57, 108), Pair(44, 10), Pair(99, -31), Pair(30, 43),
        Pair(-9, -12), Pair(-9, -13), Pair(20, 11), Pair(46, 16), Pair(-18, 72), Pair(7, 19), Pair(83, -92), Pair(5, 7),
        Pair(-8, 65), Pair(8, 28), Pair(-17, 38), Pair(-35, -37), Pair(-5, 39), Pair(2, 12), Pair(-3, 29), Pair(12, -49),
        Pair(-38, 94), Pair(-10, 33), Pair(29, -13), Pair(0, 0), Pair(-3, 35), Pair(2, -11), Pair(4, -4), Pair(5, -1),
        Pair(-6, 47), Pair(13, 28), Pair(12, 11), Pair(12, -7), Pair(-17, 40), Pair(7, 19), Pair(5, -2), Pair(-7, -7),
        Pair(31, -48), Pair(4, 28), Pair(5, 21), Pair(-5, 31), Pair(-6, 22), Pair(-12, 45), Pair(13, -25), Pair(-9, 56),
        Pair(1, -15), Pair(2, 39), Pair(-3, 48), Pair(16, -19), Pair(-4, 44), Pair(14, 0), Pair(-19, 28), Pair(25, -45),
        Pair(-8, 47), Pair(15, -24), Pair(-3, 40), Pair(4, 8), Pair(-8, 28), Pair(-5, 12), Pair(-46, 37), Pair(-31, 23)
      },
      { // Piece 5
        Pair(-11, 18), Pair(55, 131), Pair(-4, 38), Pair(-59, 27), Pair(42, 9), Pair(45, 5), Pair(-9, 84), Pair(-16, 3),
        Pair(17, 36), Pair(107, 97), Pair(68, 51), Pair(54, 112), Pair(-96, 30), Pair(2, 45), Pair(-3, -14), Pair(34, -49),
        Pair(-24, -7), Pair(80, 43), Pair(94, 63), Pair(-6, 21), Pair(123, -6), Pair(48, 45), Pair(52, -8), Pair(-99, 27),
        Pair(81, 55), Pair(28, 22), Pair(12, 70), Pair(0, 0), Pair(22, 54), Pair(51, 28), Pair(-48, 25), Pair(99, -16),
        Pair(-45, 49), Pair(-32, 36), Pair(-8, 28), Pair(-43, 69), Pair(-58, 32), Pair(-81, 30), Pair(-51, -4), Pair(17, 12),
        Pair(160, -33), Pair(-4, 17), Pair(8, 8), Pair(-69, 43), Pair(-13, 16), Pair(-11, 5), Pair(0, 6), Pair(32, -19),
        Pair(28, -3), Pair(-9, 5), Pair(-28, 5), Pair(-5, -5), Pair(-3, -17), Pair(-30, 3), Pair(-5, -3), Pair(2, -15),
        Pair(13, -21), Pair(-10, -1), Pair(-10, -14), Pair(-19, -38), Pair(7, -44), Pair(1, -20), Pair(0, -20), Pair(-3, -8)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(31, 10), Pair(-28, 33), Pair(-18, 11), Pair(-18, 24), Pair(35, -12), Pair(-31, 36), Pair(26, -7), Pair(1, 23),
        Pair(12, 2), Pair(-3, 19), Pair(-7, 20), Pair(18, 30), Pair(-26, -13), Pair(24, 6), Pair(14, 10), Pair(-3, 7),
        Pair(6, 7), Pair(6, 8), Pair(6, -2), Pair(1, 11), Pair(4, -15), Pair(4, 7), Pair(-15, -2), Pair(2, 6),
        Pair(0, 8), Pair(5, 6), Pair(6, 4), Pair(11, 4), Pair(0, -1), Pair(11, 5), Pair(3, 8), Pair(0, 5),
        Pair(2, 11), Pair(6, 5), Pair(5, 5), Pair(0, 8), Pair(6, 9), Pair(0, 8), Pair(-2, 7), Pair(-1, 7),
        Pair(0, 8), Pair(4, 4), Pair(5, 7), Pair(-11, 27), Pair(8, 3), Pair(-4, 15), Pair(-3, 7), Pair(-2, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-28, 15), Pair(-94, -1), Pair(-13, 12), Pair(47, 40), Pair(160, 30), Pair(42, -18), Pair(-84, 96), Pair(-68, -19),
        Pair(-21, 81), Pair(-20, 56), Pair(-81, 43), Pair(30, -1), Pair(-44, 67), Pair(-2, 31), Pair(32, 76), Pair(-40, 32),
        Pair(18, 64), Pair(-9, 27), Pair(28, 20), Pair(33, 23), Pair(26, 19), Pair(-40, 40), Pair(22, 35), Pair(-10, 37),
        Pair(-11, 76), Pair(8, 45), Pair(10, 46), Pair(18, 41), Pair(0, 0), Pair(33, 36), Pair(8, 28), Pair(5, 15),
        Pair(21, 26), Pair(30, 38), Pair(23, 37), Pair(13, 48), Pair(18, 75), Pair(32, 42), Pair(9, 20), Pair(13, 14),
        Pair(6, 2), Pair(7, 35), Pair(3, 32), Pair(-9, 40), Pair(20, 12), Pair(2, 24), Pair(20, -2), Pair(9, 54),
        Pair(4, 8), Pair(17, -28), Pair(6, 36), Pair(0, 40), Pair(12, 34), Pair(-8, 44), Pair(-2, 33), Pair(-9, 14),
        Pair(-6, 37), Pair(-2, 13), Pair(-21, 36), Pair(12, 1), Pair(-4, 18), Pair(-6, 54), Pair(11, 27), Pair(20, 72)
      },
      { // Piece 2
        Pair(3, 27), Pair(-117, -46), Pair(-56, 41), Pair(110, -21), Pair(-60, 34), Pair(79, -14), Pair(103, 6), Pair(63, -104),
        Pair(-28, -54), Pair(-15, 38), Pair(47, -41), Pair(78, -9), Pair(49, -34), Pair(6, 33), Pair(-12, -27), Pair(29, 44),
        Pair(-7, 36), Pair(4, -10), Pair(2, 30), Pair(-9, -23), Pair(10, -17), Pair(-11, -3), Pair(40, 6), Pair(17, -17),
        Pair(15, -19), Pair(12, 31), Pair(23, -22), Pair(3, 34), Pair(0, 0), Pair(74, 7), Pair(20, -8), Pair(20, 28),
        Pair(14, 18), Pair(9, -15), Pair(29, 13), Pair(-9, -2), Pair(10, 50), Pair(8, -12), Pair(21, 27), Pair(-6, 13),
        Pair(0, -9), Pair(-8, 43), Pair(-9, 8), Pair(14, 29), Pair(0, -4), Pair(13, 32), Pair(-11, -8), Pair(15, 36),
        Pair(38, -2), Pair(-14, 6), Pair(27, 10), Pair(1, -1), Pair(12, 18), Pair(9, -17), Pair(6, 16), Pair(-27, 15),
        Pair(-41, -11), Pair(23, 4), Pair(-11, 25), Pair(4, 25), Pair(-11, -20), Pair(4, 19), Pair(-1, 20), Pair(44, -38)
      },
      { // Piece 3
        Pair(11, 32), Pair(53, 15), Pair(44, 13), Pair(106, 9), Pair(-145, 44), Pair(-26, 20), Pair(99, 13), Pair(44, 12),
        Pair(20, 27), Pair(28, 34), Pair(-9, 31), Pair(9, 34), Pair(24, 12), Pair(-70, 61), Pair(8, 18), Pair(3, 48),
        Pair(31, 26), Pair(9, 43), Pair(-4, 43), Pair(44, 40), Pair(-31, -6), Pair(66, 11), Pair(67, 12), Pair(82, 24),
        Pair(14, 8), Pair(-7, 27), Pair(-16, 16), Pair(-7, 19), Pair(0, 0), Pair(29, -3), Pair(29, 19), Pair(-11, 29),
        Pair(5, 25), Pair(-30, 32), Pair(-8, 25), Pair(6, 51), Pair(18, 11), Pair(11, 30), Pair(-10, 39), Pair(12, 28),
        Pair(6, 28), Pair(3, 17), Pair(-5, 20), Pair(-10, 23), Pair(6, 9), Pair(13, 15), Pair(-14, 47), Pair(-2, 34),
        Pair(-5, 32), Pair(-20, 41), Pair(14, 10), Pair(5, 14), Pair(-4, 2), Pair(2, 13), Pair(6, 21), Pair(2, 7),
        Pair(0, 15), Pair(6, 19), Pair(-1, 17), Pair(2, 18), Pair(12, -3), Pair(2, 18), Pair(12, 9), Pair(7, 21)
      },
      { // Piece 4
        Pair(12, 47), Pair(-16, -3), Pair(43, 79), Pair(17, 12), Pair(-75, 56), Pair(101, -87), Pair(-24, 60), Pair(57, -98),
        Pair(21, 1), Pair(39, -20), Pair(14, -19), Pair(44, 0), Pair(71, -22), Pair(32, 13), Pair(-1, -10), Pair(19, -6),
        Pair(44, -67), Pair(31, -14), Pair(4, -24), Pair(-10, 31), Pair(-6, -29), Pair(54, 39), Pair(2, 71), Pair(28, 48),
        Pair(10, 24), Pair(7, 21), Pair(4, -2), Pair(8, 50), Pair(0, 0), Pair(30, -20), Pair(-22, 94), Pair(22, 13),
        Pair(-3, 19), Pair(18, -22), Pair(8, -20), Pair(-22, 67), Pair(-3, 43), Pair(12, 43), Pair(16, 19), Pair(17, 35),
        Pair(20, -8), Pair(8, 9), Pair(1, 25), Pair(10, 18), Pair(6, 28), Pair(19, 17), Pair(16, -18), Pair(-16, 92),
        Pair(-9, 19), Pair(1, 28), Pair(15, 22), Pair(10, 32), Pair(6, 22), Pair(11, 14), Pair(22, -9), Pair(0, -22),
        Pair(-7, 24), Pair(30, -44), Pair(9, -11), Pair(5, 13), Pair(4, -8), Pair(7, 44), Pair(1, 24), Pair(27, -64)
      },
      { // Piece 5
        Pair(5, 24), Pair(-64, -63), Pair(14, 106), Pair(-13, 46), Pair(-60, 83), Pair(27, 71), Pair(17, 55), Pair(-41, 5),
        Pair(-44, -76), Pair(77, 52), Pair(60, -11), Pair(113, 69), Pair(56, 57), Pair(24, 86), Pair(91, 17), Pair(-60, -70),
        Pair(139, -10), Pair(-8, 22), Pair(-54, 74), Pair(-25, 50), Pair(-17, 33), Pair(62, 13), Pair(11, 20), Pair(102, 26),
        Pair(6, 51), Pair(127, -34), Pair(-39, 36), Pair(-106, 53), Pair(0, 0), Pair(59, 19), Pair(-29, 16), Pair(50, 14),
        Pair(-137, 9), Pair(-122, 23), Pair(39, 8), Pair(-43, 23), Pair(-24, 31), Pair(-35, 16), Pair(22, -8), Pair(67, -25),
        Pair(-56, -26), Pair(-10, -5), Pair(-63, 12), Pair(-86, 24), Pair(-39, 22), Pair(-38, 1), Pair(15, -19), Pair(-1, -19),
        Pair(-13, -20), Pair(-4, -26), Pair(-10, -9), Pair(-23, -8), Pair(1, -19), Pair(-5, -22), Pair(7, -17), Pair(6, -19),
        Pair(-3, -62), Pair(-6, -23), Pair(-15, -24), Pair(-57, 11), Pair(-6, -34), Pair(-4, -46), Pair(8, -30), Pair(10, -42)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-31, 6), Pair(-56, 9), Pair(-13, 15), Pair(72, 2), Pair(-49, 31), Pair(8, -14), Pair(-9, 40), Pair(-7, 3),
        Pair(-10, 13), Pair(5, 11), Pair(-1, 17), Pair(15, 12), Pair(30, 21), Pair(16, -28), Pair(0, -1), Pair(6, -2),
        Pair(3, 7), Pair(6, 8), Pair(7, 15), Pair(-1, 0), Pair(5, 8), Pair(5, -6), Pair(-22, 5), Pair(-20, 1),
        Pair(2, 6), Pair(-2, 12), Pair(8, 5), Pair(1, 12), Pair(11, 5), Pair(-1, -2), Pair(-3, -1), Pair(4, 3),
        Pair(1, 8), Pair(-1, 7), Pair(5, 4), Pair(-1, 10), Pair(5, 10), Pair(9, 5), Pair(-7, 5), Pair(0, 8),
        Pair(-3, 11), Pair(0, 9), Pair(0, 10), Pair(-2, 18), Pair(2, 26), Pair(4, 13), Pair(-10, 9), Pair(-6, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-11, -92), Pair(98, 22), Pair(-98, 34), Pair(18, 51), Pair(116, -8), Pair(37, 17), Pair(-109, 8), Pair(0, -45),
        Pair(0, 5), Pair(1, 25), Pair(59, 24), Pair(124, 23), Pair(85, 12), Pair(93, -35), Pair(37, 42), Pair(48, 50),
        Pair(39, 38), Pair(0, 18), Pair(55, -4), Pair(16, 11), Pair(60, 10), Pair(-30, 26), Pair(27, -1), Pair(80, -20),
        Pair(-29, 46), Pair(9, -1), Pair(0, 33), Pair(10, 31), Pair(41, 27), Pair(0, 0), Pair(18, 18), Pair(24, 29),
        Pair(-18, 34), Pair(2, 73), Pair(2, 6), Pair(5, 17), Pair(26, 45), Pair(34, 30), Pair(22, 48), Pair(-1, -16),
        Pair(-1, -25), Pair(21, -1), Pair(5, 10), Pair(-11, 13), Pair(12, 15), Pair(7, 24), Pair(12, -3), Pair(4, 72),
        Pair(-26, 22), Pair(-56, -5), Pair(-34, -3), Pair(-8, 6), Pair(-14, 30), Pair(27, -13), Pair(7, -3), Pair(-3, 28),
        Pair(-61, -8), Pair(-12, 13), Pair(18, 46), Pair(-8, 17), Pair(-1, -21), Pair(-16, -1), Pair(-12, 46), Pair(-35, -138)
      },
      { // Piece 2
        Pair(-74, -53), Pair(-87, -13), Pair(-65, -47), Pair(47, -34), Pair(57, -26), Pair(-70, 24), Pair(108, -29), Pair(-36, 82),
        Pair(3, 49), Pair(-40, 8), Pair(20, -8), Pair(5, -20), Pair(57, -38), Pair(-30, -19), Pair(3, 27), Pair(-20, -8),
        Pair(-14, -21), Pair(-31, 45), Pair(7, -32), Pair(33, 10), Pair(37, 3), Pair(98, -35), Pair(-61, -9), Pair(24, 30),
        Pair(10, -2), Pair(19, -25), Pair(56, -3), Pair(39, -27), Pair(14, 14), Pair(0, 0), Pair(30, 7), Pair(-20, 5),
        Pair(14, -40), Pair(9, -6), Pair(8, -20), Pair(27, 20), Pair(-13, 4), Pair(16, 29), Pair(-17, -3), Pair(1, 61),
        Pair(26, 23), Pair(13, -36), Pair(12, -1), Pair(-21, -12), Pair(24, 4), Pair(16, -29), Pair(12, -5), Pair(-15, -35),
        Pair(-2, -9), Pair(16, 9), Pair(-6, -11), Pair(13, 11), Pair(-4, -14), Pair(29, -1), Pair(-9, -16), Pair(-1, 42),
        Pair(28, 12), Pair(-21, -40), Pair(4, 1), Pair(-15, 0), Pair(20, 18), Pair(-12, -10), Pair(56, 28), Pair(23, -48)
      },
      { // Piece 3
        Pair(20, 36), Pair(0, 16), Pair(57, 16), Pair(62, 25), Pair(21, 4), Pair(11, 3), Pair(147, -3), Pair(46, 19),
        Pair(-2, 42), Pair(42, 10), Pair(26, -4), Pair(74, 6), Pair(66, -7), Pair(-34, 43), Pair(1, 29), Pair(73, 7),
        Pair(-6, 20), Pair(0, 19), Pair(50, 2), Pair(46, 1), Pair(3, 16), Pair(98, -40), Pair(38, 5), Pair(87, -1),
        Pair(-60, 46), Pair(-10, 25), Pair(-11, 41), Pair(-35, 27), Pair(-2, 22), Pair(0, 0), Pair(33, -4), Pair(29, 17),
        Pair(19, 32), Pair(69, -5), Pair(31, -8), Pair(39, -2), Pair(-2, 32), Pair(56, -36), Pair(20, 4), Pair(102, -29),
        Pair(-2, 38), Pair(-8, 29), Pair(25, 15), Pair(10, 26), Pair(27, 4), Pair(25, -36), Pair(-2, 7), Pair(55, -17),
        Pair(-57, 50), Pair(0, 40), Pair(-6, 7), Pair(1, 15), Pair(-5, 25), Pair(4, -7), Pair(40, -6), Pair(57, -23),
        Pair(8, 10), Pair(9, 5), Pair(10, 7), Pair(11, 6), Pair(11, 7), Pair(17, -23), Pair(19, -1), Pair(7, 7)
      },
      { // Piece 4
        Pair(26, -38), Pair(12, 37), Pair(45, 46), Pair(103, 26), Pair(-25, 96), Pair(44, -2), Pair(38, 75), Pair(63, -19),
        Pair(50, -54), Pair(43, -2), Pair(53, -41), Pair(112, -85), Pair(73, -6), Pair(34, -85), Pair(10, 125), Pair(9, -37),
        Pair(-10, 14), Pair(41, 21), Pair(-19, 9), Pair(29, 106), Pair(-2, -8), Pair(41, -66), Pair(-15, 9), Pair(18, 17),
        Pair(-11, 45), Pair(-50, 25), Pair(31, -22), Pair(17, 15), Pair(-19, 83), Pair(0, 0), Pair(14, -40), Pair(13, 22),
        Pair(-7, 80), Pair(15, 31), Pair(-3, 15), Pair(0, 30), Pair(2, 11), Pair(11, 38), Pair(18, -16), Pair(57, -33),
        Pair(14, 44), Pair(11, 6), Pair(39, -69), Pair(-19, 19), Pair(17, 7), Pair(29, -45), Pair(12, 25), Pair(43, -44),
        Pair(2, -16), Pair(11, 24), Pair(9, -1), Pair(21, 8), Pair(4, 24), Pair(4, 0), Pair(29, -9), Pair(-19, 54),
        Pair(19, -24), Pair(3, 31), Pair(17, -2), Pair(8, 12), Pair(20, -14), Pair(2, -48), Pair(-7, 38), Pair(9, -35)
      },
      { // Piece 5
        Pair(-29, -3), Pair(-59, 111), Pair(-71, -21), Pair(-10, 86), Pair(-24, 61), Pair(1, -95), Pair(-14, 73), Pair(23, 38),
        Pair(-6, 15), Pair(-40, 78), Pair(65, -17), Pair(21, 71), Pair(-37, 87), Pair(74, 66), Pair(-60, 130), Pair(67, 40),
        Pair(113, 9), Pair(50, -14), Pair(37, 24), Pair(-76, 27), Pair(52, 2), Pair(2, 20), Pair(122, -4), Pair(92, 19),
        Pair(-148, -9), Pair(30, -11), Pair(-52, 22), Pair(45, 16), Pair(112, 4), Pair(0, 0), Pair(21, 10), Pair(50, 14),
        Pair(21, 11), Pair(-19, 11), Pair(-30, 2), Pair(-49, 20), Pair(31, 5), Pair(-38, 22), Pair(3, 8), Pair(29, 12),
        Pair(-63, -4), Pair(-86, 0), Pair(-95, 20), Pair(-36, 2), Pair(-28, 13), Pair(-30, 15), Pair(-16, 1), Pair(-32, 2),
        Pair(-24, -4), Pair(-18, 0), Pair(-45, 8), Pair(41, -32), Pair(-9, -10), Pair(-18, -8), Pair(11, -31), Pair(3, -10),
        Pair(-11, -69), Pair(-8, -17), Pair(-2, -40), Pair(-72, 9), Pair(5, -51), Pair(-7, -18), Pair(14, -39), Pair(9, -18)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, 6), Pair(-10, 16), Pair(89, -15), Pair(45, -9), Pair(32, 18), Pair(-28, 25), Pair(15, 28), Pair(-18, 38),
        Pair(2, 9), Pair(-18, 7), Pair(-23, 22), Pair(19, 17), Pair(5, 3), Pair(-20, 10), Pair(51, -27), Pair(-12, -5),
        Pair(4, 12), Pair(6, 14), Pair(-7, 13), Pair(3, 11), Pair(-15, -2), Pair(-22, 5), Pair(4, 3), Pair(-12, -8),
        Pair(-2, 9), Pair(-4, 10), Pair(1, 2), Pair(-3, 11), Pair(2, 2), Pair(-1, -2), Pair(0, -14), Pair(0, 0),
        Pair(-1, 10), Pair(2, 9), Pair(2, 7), Pair(-3, 11), Pair(7, 10), Pair(2, 2), Pair(3, 0), Pair(-3, 9),
        Pair(2, 4), Pair(1, 12), Pair(2, 9), Pair(-5, -3), Pair(1, 11), Pair(-3, 11), Pair(4, 3), Pair(-12, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(156, -56), Pair(22, -43), Pair(-34, 34), Pair(106, 19), Pair(10, 21), Pair(-143, 63), Pair(-14, -21), Pair(-67, 1),
        Pair(-39, 9), Pair(-25, -12), Pair(37, 13), Pair(113, -8), Pair(44, -15), Pair(115, -46), Pair(78, 11), Pair(79, 9),
        Pair(-133, 37), Pair(-43, 18), Pair(17, 30), Pair(34, 25), Pair(9, 26), Pair(6, 7), Pair(49, -28), Pair(48, -49),
        Pair(25, 18), Pair(2, 11), Pair(12, 27), Pair(33, 30), Pair(24, 19), Pair(58, 4), Pair(0, 0), Pair(41, -6),
        Pair(8, 5), Pair(-42, 21), Pair(23, 0), Pair(14, 19), Pair(39, 18), Pair(30, 21), Pair(84, 8), Pair(36, 9),
        Pair(-24, 12), Pair(-11, 5), Pair(9, 3), Pair(1, 33), Pair(5, 33), Pair(-1, 22), Pair(29, 11), Pair(-28, 20),
        Pair(84, 8), Pair(-53, 13), Pair(-25, 34), Pair(-12, 9), Pair(15, 4), Pair(-17, 25), Pair(21, -1), Pair(-20, 52),
        Pair(55, -78), Pair(-12, -28), Pair(-60, 61), Pair(4, 6), Pair(-3, 33), Pair(27, -22), Pair(-1, -44), Pair(50, -46)
      },
      { // Piece 2
        Pair(-5, -30), Pair(-43, -45), Pair(159, -27), Pair(133, -42), Pair(157, -39), Pair(44, -26), Pair(40, -26), Pair(-122, 41),
        Pair(8, -55), Pair(16, -2), Pair(44, -31), Pair(91, -34), Pair(72, -24), Pair(39, -9), Pair(22, -27), Pair(78, -11),
        Pair(12, -23), Pair(-7, -21), Pair(58, -8), Pair(83, -41), Pair(49, -4), Pair(42, -13), Pair(25, 0), Pair(-12, -9),
        Pair(33, -81), Pair(-3, -11), Pair(-5, -1), Pair(40, -2), Pair(23, -20), Pair(49, 1), Pair(0, 0), Pair(28, -19),
        Pair(-46, 10), Pair(33, -29), Pair(23, -6), Pair(44, -17), Pair(30, 14), Pair(7, 6), Pair(46, -4), Pair(-73, -30),
        Pair(20, -21), Pair(21, -12), Pair(10, -5), Pair(19, 2), Pair(6, -7), Pair(15, -11), Pair(22, -35), Pair(35, -22),
        Pair(-19, -28), Pair(17, -6), Pair(41, -2), Pair(2, -17), Pair(16, -5), Pair(3, -10), Pair(27, -4), Pair(-52, 28),
        Pair(45, -46), Pair(6, 30), Pair(5, -20), Pair(13, 17), Pair(-25, -11), Pair(21, -13), Pair(25, -101), Pair(-5, 59)
      },
      { // Piece 3
        Pair(-12, 41), Pair(38, 15), Pair(131, -16), Pair(-35, 27), Pair(170, -12), Pair(24, 42), Pair(-8, -4), Pair(-27, 13),
        Pair(-2, 29), Pair(24, 16), Pair(40, 9), Pair(65, 7), Pair(129, -39), Pair(-11, -1), Pair(25, -2), Pair(-87, 39),
        Pair(6, 25), Pair(-3, 19), Pair(25, 12), Pair(37, 8), Pair(58, -8), Pair(-8, 20), Pair(68, -48), Pair(-1, 25),
        Pair(30, 0), Pair(48, 6), Pair(0, 12), Pair(9, 22), Pair(-5, 30), Pair(-22, 13), Pair(0, 0), Pair(-45, 16),
        Pair(3, 21), Pair(21, -2), Pair(21, 19), Pair(-18, 32), Pair(28, 13), Pair(0, 16), Pair(47, -30), Pair(-4, 36),
        Pair(-13, 23), Pair(-62, 54), Pair(-10, 13), Pair(3, 24), Pair(-1, 19), Pair(0, 13), Pair(-36, 18), Pair(0, 17),
        Pair(-7, 13), Pair(-13, 15), Pair(4, 0), Pair(-9, 9), Pair(15, 4), Pair(13, -3), Pair(35, -29), Pair(30, -16),
        Pair(-3, 7), Pair(3, 6), Pair(3, 2), Pair(-5, 3), Pair(4, 1), Pair(-2, 7), Pair(4, -13), Pair(4, 4)
      },
      { // Piece 4
        Pair(39, -16), Pair(-87, 65), Pair(-114, 38), Pair(-10, 35), Pair(87, 2), Pair(-146, 19), Pair(6, -161), Pair(-16, -57),
        Pair(39, -50), Pair(-13, 63), Pair(48, -19), Pair(28, -5), Pair(13, -14), Pair(5, -37), Pair(-40, -70), Pair(90, -98),
        Pair(-61, 52), Pair(63, -84), Pair(9, 30), Pair(17, 58), Pair(12, 101), Pair(-4, 2), Pair(23, -83), Pair(29, -35),
        Pair(-5, 22), Pair(-47, -40), Pair(24, -7), Pair(54, -40), Pair(9, 21), Pair(48, -98), Pair(0, 0), Pair(7, -32),
        Pair(-11, 32), Pair(-54, 41), Pair(6, 51), Pair(18, 5), Pair(-2, 15), Pair(26, -2), Pair(-18, -29), Pair(-9, -3),
        Pair(34, -103), Pair(6, -76), Pair(6, 11), Pair(-3, 19), Pair(21, -32), Pair(-8, 11), Pair(8, 0), Pair(14, 35),
        Pair(-5, -52), Pair(-33, 46), Pair(-17, 44), Pair(1, -1), Pair(2, -3), Pair(-5, -31), Pair(0, -11), Pair(22, -3),
        Pair(42, -17), Pair(-47, 39), Pair(-34, 38), Pair(-14, -14), Pair(-9, -61), Pair(-54, 82), Pair(-5, -6), Pair(-6, 86)
      },
      { // Piece 5
        Pair(22, -99), Pair(-61, -23), Pair(-7, 8), Pair(15, 79), Pair(40, 17), Pair(-20, 113), Pair(-4, 110), Pair(50, 29),
        Pair(-40, -49), Pair(36, -22), Pair(-97, 9), Pair(-12, 5), Pair(21, -3), Pair(21, 52), Pair(6, 101), Pair(56, 60),
        Pair(20, -5), Pair(-40, 15), Pair(-15, 11), Pair(200, -11), Pair(107, 0), Pair(97, 23), Pair(36, 51), Pair(46, 16),
        Pair(-106, 6), Pair(0, 30), Pair(23, -3), Pair(-120, 58), Pair(-48, 23), Pair(43, 14), Pair(0, 0), Pair(-33, 46),
        Pair(-158, 39), Pair(-17, 9), Pair(-10, -4), Pair(-41, 25), Pair(-39, 21), Pair(11, 6), Pair(56, 8), Pair(-64, 14),
        Pair(-33, 8), Pair(-62, 2), Pair(-37, 4), Pair(1, 13), Pair(26, -1), Pair(-24, 12), Pair(22, 3), Pair(10, 15),
        Pair(-40, -2), Pair(-17, -12), Pair(-58, 15), Pair(-84, 8), Pair(-7, -10), Pair(1, -7), Pair(14, -3), Pair(9, -12),
        Pair(-19, -52), Pair(-19, -2), Pair(-11, -24), Pair(-61, 1), Pair(-15, -27), Pair(7, -19), Pair(15, -10), Pair(5, -45)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(75, -19), Pair(41, -18), Pair(36, 32), Pair(46, 5), Pair(13, -12), Pair(31, -19), Pair(-12, 29), Pair(-8, 26),
        Pair(-12, 14), Pair(14, 9), Pair(33, 16), Pair(-18, 22), Pair(16, 3), Pair(-13, 11), Pair(-18, 0), Pair(34, -42),
        Pair(-11, 8), Pair(3, 8), Pair(6, 5), Pair(5, 5), Pair(2, 5), Pair(-20, 1), Pair(-12, -8), Pair(2, 6),
        Pair(-1, 10), Pair(3, 13), Pair(-5, 12), Pair(6, 5), Pair(3, 4), Pair(-5, 2), Pair(-3, -10), Pair(5, 0),
        Pair(-1, 10), Pair(1, 10), Pair(1, 4), Pair(-5, 8), Pair(6, -2), Pair(-1, 3), Pair(-1, 5), Pair(19, 5),
        Pair(-6, 14), Pair(2, 10), Pair(-4, 5), Pair(-7, 7), Pair(1, 3), Pair(-3, 7), Pair(-3, 6), Pair(11, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-34, 167), Pair(61, 11), Pair(169, 26), Pair(147, -32), Pair(83, -41), Pair(-74, -15), Pair(48, -11), Pair(-54, 73),
        Pair(-64, -21), Pair(-42, 13), Pair(37, -4), Pair(107, -27), Pair(-118, 19), Pair(24, 17), Pair(-53, -44), Pair(-17, 56),
        Pair(-45, 25), Pair(35, -25), Pair(-44, 29), Pair(43, -12), Pair(-36, 17), Pair(78, 4), Pair(37, -22), Pair(-4, 5),
        Pair(21, -28), Pair(5, 6), Pair(5, -11), Pair(20, 16), Pair(43, 11), Pair(26, 14), Pair(33, -6), Pair(0, 0),
        Pair(-13, -12), Pair(-41, 36), Pair(1, 18), Pair(17, 12), Pair(13, 11), Pair(13, 15), Pair(33, -16), Pair(12, 8),
        Pair(9, 19), Pair(-3, -7), Pair(10, -5), Pair(5, 8), Pair(40, 1), Pair(6, 9), Pair(10, 5), Pair(-41, 40),
        Pair(-4, -10), Pair(-3, -21), Pair(-1, 3), Pair(5, 0), Pair(10, -18), Pair(11, 13), Pair(-40, -11), Pair(11, -16),
        Pair(-71, -7), Pair(-8, -14), Pair(-59, 26), Pair(-46, 3), Pair(-8, -39), Pair(-11, -20), Pair(-23, 27), Pair(-22, 60)
      },
      { // Piece 2
        Pair(6, -11), Pair(6, -8), Pair(131, -44), Pair(19, -7), Pair(18, -45), Pair(-67, 0), Pair(150, -48), Pair(-1, 21),
        Pair(73, -32), Pair(3, -38), Pair(-39, -2), Pair(73, -56), Pair(19, -26), Pair(102, -50), Pair(19, -28), Pair(102, -32),
        Pair(15, -30), Pair(-13, -11), Pair(2, -18), Pair(-30, 12), Pair(17, -39), Pair(16, -20), Pair(9, -37), Pair(27, -25),
        Pair(36, 15), Pair(11, -30), Pair(44, -11), Pair(24, -30), Pair(16, 17), Pair(37, -28), Pair(36, -5), Pair(0, 0),
        Pair(67, -47), Pair(20, -16), Pair(-2, -15), Pair(-18, 17), Pair(36, -22), Pair(5, 7), Pair(-6, -8), Pair(33, -10),
        Pair(3, 2), Pair(15, -26), Pair(2, 1), Pair(29, -33), Pair(14, -1), Pair(23, -21), Pair(14, 4), Pair(35, -45),
        Pair(36, -22), Pair(4, -3), Pair(38, -31), Pair(16, 6), Pair(6, -17), Pair(-19, 20), Pair(10, -32), Pair(-4, -9),
        Pair(-13, -5), Pair(46, -41), Pair(-10, 7), Pair(1, -20), Pair(-37, 7), Pair(4, -44), Pair(39, 11), Pair(34, -115)
      },
      { // Piece 3
        Pair(5, 21), Pair(41, 11), Pair(96, -15), Pair(70, -2), Pair(101, -24), Pair(83, -12), Pair(-51, 22), Pair(17, -29),
        Pair(49, -8), Pair(2, 14), Pair(18, -7), Pair(100, -6), Pair(74, -29), Pair(49, -2), Pair(26, 0), Pair(13, -19),
        Pair(-7, 26), Pair(45, -9), Pair(0, 16), Pair(35, 4), Pair(66, -29), Pair(60, -6), Pair(3, 4), Pair(154, -72),
        Pair(4, -2), Pair(46, -9), Pair(-1, 13), Pair(31, -4), Pair(11, 0), Pair(32, -9), Pair(25, 15), Pair(0, 0),
        Pair(63, -22), Pair(-40, 25), Pair(29, 12), Pair(1, 23), Pair(36, 12), Pair(12, 19), Pair(7, 11), Pair(-57, 20),
        Pair(3, -1), Pair(0, -3), Pair(-3, -4), Pair(-13, -19), Pair(-3, 6), Pair(9, 3), Pair(-19, 16), Pair(-77, 8),
        Pair(-20, -3), Pair(-27, 18), Pair(-21, -8), Pair(-4, -11), Pair(-2, -1), Pair(-19, -6), Pair(-92, 56), Pair(-73, 14),
        Pair(-1, -13), Pair(-4, -8), Pair(-6, 0), Pair(1, -9), Pair(-4, 5), Pair(-1, 2), Pair(3, -6), Pair(-35, -2)
      },
      { // Piece 4
        Pair(-34, 35), Pair(-82, 9), Pair(6, -61), Pair(18, -31), Pair(78, -47), Pair(-7, -4), Pair(-66, 14), Pair(107, 2),
        Pair(44, -81), Pair(-38, 36), Pair(-28, 2), Pair(-82, 43), Pair(-64, 73), Pair(-48, 42), Pair(2, -89), Pair(63, -100),
        Pair(-57, 20), Pair(3, -28), Pair(-16, 0), Pair(3, 17), Pair(43, 9), Pair(87, -32), Pair(36, 39), Pair(-20, -32),
        Pair(25, -62), Pair(98, -145), Pair(27, -58), Pair(-1, 9), Pair(-33, -11), Pair(31, -33), Pair(40, -41), Pair(0, 0),
        Pair(-3, -33), Pair(-4, 4), Pair(1, 34), Pair(-1, -7), Pair(-8, 7), Pair(-16, 9), Pair(1, -15), Pair(1, -43),
        Pair(-10, -41), Pair(1, -31), Pair(-13, 8), Pair(-1, 3), Pair(-11, -13), Pair(-23, 28), Pair(10, -37), Pair(15, -112),
        Pair(39, -58), Pair(-24, 30), Pair(-3, -29), Pair(-5, -1), Pair(-16, 4), Pair(-38, 68), Pair(25, -92), Pair(50, -81),
        Pair(28, -69), Pair(-27, -17), Pair(-58, 83), Pair(-12, -21), Pair(-17, -22), Pair(56, -85), Pair(17, -4), Pair(-45, -36)
      },
      { // Piece 5
        Pair(45, 139), Pair(38, 20), Pair(-68, -47), Pair(31, -23), Pair(75, -5), Pair(-63, 97), Pair(-10, 63), Pair(53, 111),
        Pair(42, 8), Pair(-23, -6), Pair(-3, 22), Pair(-32, 8), Pair(-21, -6), Pair(10, 36), Pair(-56, 87), Pair(-102, 42),
        Pair(-1, -35), Pair(21, 11), Pair(-22, -1), Pair(-30, 35), Pair(142, -6), Pair(121, 14), Pair(112, 6), Pair(-40, -5),
        Pair(-33, -1), Pair(-48, 15), Pair(-152, 42), Pair(-31, 8), Pair(33, -1), Pair(52, 4), Pair(50, -5), Pair(0, 0),
        Pair(-142, 20), Pair(-24, 17), Pair(-107, 24), Pair(-8, 19), Pair(-53, 22), Pair(8, 12), Pair(-3, -2), Pair(-15, -25),
        Pair(-71, 6), Pair(-6, 7), Pair(-72, 15), Pair(-66, 34), Pair(8, 8), Pair(4, 4), Pair(1, 2), Pair(-9, -14),
        Pair(-46, 3), Pair(-16, -23), Pair(-13, -1), Pair(-22, -4), Pair(2, -1), Pair(-23, 10), Pair(14, -5), Pair(6, -9),
        Pair(-1, -33), Pair(-33, 9), Pair(-28, -4), Pair(-72, -16), Pair(-18, -9), Pair(-6, 0), Pair(12, -11), Pair(3, -14)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-9, -10), Pair(-12, 29), Pair(23, 8), Pair(-19, 25), Pair(45, -28), Pair(-5, 9), Pair(30, 7), Pair(-16, 18),
        Pair(-22, 8), Pair(-4, 18), Pair(-9, 17), Pair(6, 6), Pair(-4, 4), Pair(0, 5), Pair(-5, -1), Pair(0, 14),
        Pair(-1, -9), Pair(0, 2), Pair(-1, 9), Pair(-2, 8), Pair(-1, 8), Pair(2, 7), Pair(-2, 10), Pair(-1, 10),
        Pair(-8, 6), Pair(-6, 4), Pair(0, 4), Pair(0, 9), Pair(1, 4), Pair(-2, 7), Pair(1, 10), Pair(-4, 8),
        Pair(0, 7), Pair(0, 1), Pair(0, 8), Pair(-2, 11), Pair(-4, 9), Pair(-1, 9), Pair(-1, 10), Pair(-1, 13),
        Pair(6, 5), Pair(-4, 8), Pair(-2, 4), Pair(0, 3), Pair(-5, 10), Pair(-5, 13), Pair(-3, 10), Pair(-1, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-72, -6), Pair(-6, -49), Pair(-93, 46), Pair(3, 29), Pair(-36, 19), Pair(-110, -24), Pair(-39, -17), Pair(5, 75),
        Pair(6, 15), Pair(1, 16), Pair(-5, 13), Pair(-1, 25), Pair(3, 17), Pair(23, -20), Pair(-54, 41), Pair(41, -24),
        Pair(6, 4), Pair(-11, 16), Pair(14, 26), Pair(-8, 21), Pair(11, 20), Pair(-43, 32), Pair(-18, 22), Pair(29, -4),
        Pair(-14, -9), Pair(4, 24), Pair(11, 22), Pair(4, 32), Pair(1, 41), Pair(5, 12), Pair(4, 16), Pair(-11, 15),
        Pair(0, 0), Pair(16, 28), Pair(3, 33), Pair(3, 28), Pair(-5, 35), Pair(15, 25), Pair(-8, 58), Pair(-1, 6),
        Pair(3, 22), Pair(0, 23), Pair(0, 19), Pair(5, 29), Pair(4, 37), Pair(3, 17), Pair(-3, 26), Pair(1, 1),
        Pair(-27, 19), Pair(18, 0), Pair(-4, 24), Pair(-3, 25), Pair(1, 8), Pair(-10, 41), Pair(0, 28), Pair(2, 9),
        Pair(59, 64), Pair(-5, -10), Pair(21, 3), Pair(-5, 48), Pair(-12, 31), Pair(4, 10), Pair(-3, 12), Pair(-38, 83)
      },
      { // Piece 2
        Pair(-72, 31), Pair(23, 40), Pair(66, -50), Pair(-107, 47), Pair(12, -14), Pair(75, -12), Pair(-89, 23), Pair(1, 51),
        Pair(-27, -7), Pair(15, 10), Pair(-1, 21), Pair(86, -33), Pair(18, 8), Pair(-33, 4), Pair(-57, 43), Pair(5, 28),
        Pair(15, 1), Pair(10, 19), Pair(38, 11), Pair(33, -1), Pair(6, 1), Pair(20, -8), Pair(0, 8), Pair(-28, 44),
        Pair(10, -7), Pair(19, 22), Pair(-3, 17), Pair(7, -3), Pair(-2, 24), Pair(-1, 12), Pair(3, 18), Pair(-8, 8),
        Pair(0, 0), Pair(6, 11), Pair(20, 4), Pair(10, 19), Pair(15, 18), Pair(-1, 18), Pair(11, 20), Pair(7, 19),
        Pair(1, 34), Pair(16, 4), Pair(7, 18), Pair(6, 16), Pair(4, 29), Pair(2, 26), Pair(-4, 32), Pair(5, 13),
        Pair(-4, -8), Pair(2, 9), Pair(1, 6), Pair(0, 20), Pair(2, 30), Pair(-9, 37), Pair(7, 19), Pair(7, 14),
        Pair(8, -18), Pair(-20, 9), Pair(-4, 6), Pair(11, -4), Pair(12, 11), Pair(2, 10), Pair(-8, 19), Pair(9, 28)
      },
      { // Piece 3
        Pair(-26, 17), Pair(12, 31), Pair(-13, 40), Pair(-36, 38), Pair(-7, 54), Pair(-26, 35), Pair(-94, 55), Pair(-22, 67),
        Pair(-40, 16), Pair(3, 36), Pair(-7, 30), Pair(-13, 43), Pair(-39, 46), Pair(15, 19), Pair(-39, 51), Pair(1, 30),
        Pair(13, 20), Pair(-7, 32), Pair(9, 33), Pair(4, 46), Pair(12, 25), Pair(15, 24), Pair(-27, 52), Pair(19, 28),
        Pair(-24, 7), Pair(0, 47), Pair(1, 50), Pair(-9, 37), Pair(18, 38), Pair(-42, 63), Pair(-3, 46), Pair(-15, 50),
        Pair(0, 0), Pair(20, 36), Pair(6, 40), Pair(8, 29), Pair(-4, 44), Pair(6, 23), Pair(-14, 34), Pair(-2, 37),
        Pair(-29, 21), Pair(5, 31), Pair(3, 35), Pair(23, 22), Pair(2, 25), Pair(2, 42), Pair(5, 36), Pair(33, 27),
        Pair(-57, 16), Pair(-4, 39), Pair(-5, 43), Pair(3, 31), Pair(-11, 42), Pair(-4, 27), Pair(8, 34), Pair(1, 40),
        Pair(-24, 8), Pair(-5, 35), Pair(-3, 33), Pair(-4, 33), Pair(-2, 31), Pair(-4, 36), Pair(6, 24), Pair(5, 21)
      },
      { // Piece 4
        Pair(7, 41), Pair(-51, 72), Pair(33, 47), Pair(-80, 79), Pair(-38, 51), Pair(-44, 104), Pair(-52, 77), Pair(-55, 73),
        Pair(-33, 34), Pair(-11, 45), Pair(25, 35), Pair(-21, 64), Pair(79, -9), Pair(44, -19), Pair(-3, 84), Pair(1, 38),
        Pair(13, -16), Pair(14, 40), Pair(15, 29), Pair(5, 50), Pair(-5, 48), Pair(12, 23), Pair(-32, 123), Pair(-24, 69),
        Pair(11, 1), Pair(-23, 101), Pair(-32, 70), Pair(11, 66), Pair(24, 61), Pair(7, -2), Pair(14, 9), Pair(16, 35),
        Pair(0, 0), Pair(5, 67), Pair(2, 53), Pair(9, 58), Pair(-2, 79), Pair(14, 35), Pair(-3, 46), Pair(11, 37),
        Pair(14, -6), Pair(10, 60), Pair(5, 59), Pair(7, 52), Pair(-4, 61), Pair(6, 53), Pair(12, 30), Pair(45, -21),
        Pair(-14, 32), Pair(11, 27), Pair(6, 57), Pair(6, 48), Pair(9, 42), Pair(9, 61), Pair(13, 2), Pair(12, 38),
        Pair(-15, 34), Pair(-7, 53), Pair(4, 42), Pair(6, 48), Pair(-12, 73), Pair(-3, 83), Pair(-57, 84), Pair(16, 75)
      },
      { // Piece 5
        Pair(26, 84), Pair(21, 126), Pair(-35, -7), Pair(21, 2), Pair(-76, -52), Pair(31, 76), Pair(-84, -12), Pair(2, 46),
        Pair(-5, 24), Pair(125, 89), Pair(19, 104), Pair(40, 45), Pair(-27, -25), Pair(47, 21), Pair(49, 5), Pair(1, -65),
        Pair(-77, 50), Pair(-182, 87), Pair(78, 42), Pair(-31, 65), Pair(20, 23), Pair(-50, 35), Pair(-15, -6), Pair(-87, 42),
        Pair(50, 1), Pair(-31, 21), Pair(-4, 60), Pair(16, 31), Pair(9, 26), Pair(-71, 11), Pair(70, 13), Pair(-1, 2),
        Pair(0, 0), Pair(-22, 32), Pair(-17, 36), Pair(33, 35), Pair(-31, 21), Pair(2, 14), Pair(-15, 4), Pair(26, -21),
        Pair(-56, -21), Pair(-69, 40), Pair(28, 16), Pair(-18, 18), Pair(8, 13), Pair(-15, 10), Pair(-20, 5), Pair(-48, -2),
        Pair(45, -32), Pair(38, 24), Pair(1, 8), Pair(-13, 2), Pair(-20, 15), Pair(-16, 11), Pair(-17, 0), Pair(-11, -7),
        Pair(20, -22), Pair(86, -9), Pair(23, -14), Pair(8, -2), Pair(-8, -11), Pair(-13, 0), Pair(-5, -7), Pair(-7, -22)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-30, 33), Pair(-13, -33), Pair(-24, 44), Pair(-28, 29), Pair(28, 3), Pair(21, 23), Pair(13, 5), Pair(12, -3),
        Pair(-10, 16), Pair(17, 0), Pair(-20, 24), Pair(1, 8), Pair(11, 9), Pair(-6, 10), Pair(-18, 20), Pair(7, 5),
        Pair(-9, 3), Pair(3, -12), Pair(5, 8), Pair(4, 6), Pair(6, 5), Pair(-2, 12), Pair(-4, 10), Pair(3, 12),
        Pair(-5, 5), Pair(-5, 9), Pair(-5, 7), Pair(1, 3), Pair(2, 11), Pair(6, 10), Pair(1, 13), Pair(1, 14),
        Pair(5, 8), Pair(-7, -1), Pair(4, 11), Pair(0, 10), Pair(-1, 9), Pair(2, 7), Pair(1, 14), Pair(3, 11),
        Pair(-4, 10), Pair(-3, 7), Pair(-1, 15), Pair(1, 14), Pair(-5, 11), Pair(2, 14), Pair(1, 15), Pair(5, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(30, 35), Pair(115, 2), Pair(148, 45), Pair(-121, 36), Pair(6, 37), Pair(-14, 49), Pair(-11, -25), Pair(-18, -41),
        Pair(-5, 44), Pair(9, -7), Pair(-43, 12), Pair(46, 23), Pair(12, 22), Pair(92, 12), Pair(77, 20), Pair(-6, 12),
        Pair(21, 13), Pair(-8, 18), Pair(22, 34), Pair(22, 20), Pair(1, 38), Pair(-8, 45), Pair(-11, 43), Pair(-41, 19),
        Pair(21, 1), Pair(1, 10), Pair(19, 24), Pair(16, 28), Pair(17, 38), Pair(0, 39), Pair(4, 28), Pair(-4, 47),
        Pair(-12, 39), Pair(0, 0), Pair(-1, 45), Pair(12, 31), Pair(3, 22), Pair(20, 27), Pair(-2, 29), Pair(17, 24),
        Pair(-3, 40), Pair(24, 42), Pair(5, 20), Pair(17, 26), Pair(13, 29), Pair(12, 36), Pair(3, 21), Pair(14, 14),
        Pair(-20, -13), Pair(18, -16), Pair(0, 40), Pair(8, 25), Pair(10, 26), Pair(12, 34), Pair(9, 26), Pair(17, 12),
        Pair(-2, -19), Pair(7, 20), Pair(16, 22), Pair(16, 11), Pair(-4, 46), Pair(7, 22), Pair(3, 37), Pair(-35, -79)
      },
      { // Piece 2
        Pair(122, -1), Pair(55, -28), Pair(-48, -7), Pair(17, -26), Pair(-54, -1), Pair(-16, -11), Pair(-32, -42), Pair(-79, 30),
        Pair(18, -13), Pair(-7, 27), Pair(-8, 12), Pair(-21, 31), Pair(71, -25), Pair(44, -16), Pair(-62, 14), Pair(5, 53),
        Pair(17, 12), Pair(-13, -6), Pair(13, 9), Pair(11, -7), Pair(29, 19), Pair(85, -39), Pair(18, 21), Pair(-3, 8),
        Pair(-6, 0), Pair(-17, 27), Pair(13, 10), Pair(9, 2), Pair(27, -2), Pair(33, -21), Pair(-5, -3), Pair(11, 21),
        Pair(38, 3), Pair(0, 0), Pair(11, 18), Pair(30, -2), Pair(5, 24), Pair(8, 2), Pair(11, 9), Pair(6, 3),
        Pair(2, -48), Pair(28, 28), Pair(15, -1), Pair(4, 35), Pair(9, 11), Pair(24, 23), Pair(15, 14), Pair(13, 23),
        Pair(11, -2), Pair(3, 13), Pair(4, 34), Pair(8, 15), Pair(8, 33), Pair(8, 24), Pair(9, 29), Pair(-2, 33),
        Pair(3, -15), Pair(15, 12), Pair(-4, -1), Pair(-11, 35), Pair(10, 12), Pair(0, 44), Pair(-16, 23), Pair(-5, 40)
      },
      { // Piece 3
        Pair(-7, 48), Pair(-17, 15), Pair(-83, 67), Pair(-4, 40), Pair(9, 52), Pair(5, 51), Pair(-86, 51), Pair(-70, 65),
        Pair(-14, 46), Pair(13, 15), Pair(-12, 54), Pair(20, 43), Pair(11, 37), Pair(-41, 51), Pair(-35, 56), Pair(-20, 55),
        Pair(16, 35), Pair(0, 20), Pair(-13, 46), Pair(34, 41), Pair(30, 26), Pair(-21, 48), Pair(-12, 32), Pair(13, 31),
        Pair(-6, 51), Pair(-30, 15), Pair(-16, 58), Pair(-10, 47), Pair(27, 26), Pair(16, 38), Pair(9, 46), Pair(23, 41),
        Pair(-15, 35), Pair(0, 0), Pair(-4, 45), Pair(24, 45), Pair(5, 39), Pair(19, 20), Pair(15, 26), Pair(25, 23),
        Pair(-11, 49), Pair(-1, 14), Pair(19, 64), Pair(8, 42), Pair(3, 52), Pair(3, 42), Pair(-21, 48), Pair(22, 34),
        Pair(11, 17), Pair(-8, 30), Pair(17, 35), Pair(10, 45), Pair(3, 38), Pair(7, 25), Pair(10, 33), Pair(24, 29),
        Pair(2, 37), Pair(-1, 13), Pair(5, 43), Pair(8, 34), Pair(9, 37), Pair(7, 43), Pair(-2, 51), Pair(6, 24)
      },
      { // Piece 4
        Pair(-15, 52), Pair(-55, 49), Pair(55, -28), Pair(-14, 17), Pair(-16, 4), Pair(-82, 36), Pair(-69, 49), Pair(11, 81),
        Pair(-38, 42), Pair(-41, 42), Pair(-61, 92), Pair(40, -9), Pair(22, 4), Pair(10, 7), Pair(6, 4), Pair(11, 20),
        Pair(5, 64), Pair(-4, -13), Pair(13, -1), Pair(-15, 44), Pair(8, 45), Pair(23, 11), Pair(24, 21), Pair(1, -19),
        Pair(0, 18), Pair(-11, 18), Pair(-24, 68), Pair(-22, 34), Pair(8, 33), Pair(-11, 55), Pair(-12, 28), Pair(-19, 51),
        Pair(-18, 47), Pair(0, 0), Pair(1, 44), Pair(-5, 37), Pair(-5, 39), Pair(6, 32), Pair(1, 54), Pair(-11, 16),
        Pair(-25, 26), Pair(8, 6), Pair(2, 45), Pair(-6, 77), Pair(-15, 78), Pair(-2, 52), Pair(0, 75), Pair(26, 2),
        Pair(1, 68), Pair(10, -9), Pair(13, 4), Pair(8, 40), Pair(8, 35), Pair(-2, 44), Pair(20, 6), Pair(-11, -51),
        Pair(0, 48), Pair(17, -72), Pair(-15, 66), Pair(1, 48), Pair(-2, 74), Pair(-30, 59), Pair(-10, 64), Pair(-2, 19)
      },
      { // Piece 5
        Pair(-10, 11), Pair(-40, 26), Pair(1, 77), Pair(96, 87), Pair(38, 10), Pair(24, 49), Pair(-23, -72), Pair(14, 16),
        Pair(-46, 98), Pair(-89, 122), Pair(3, 77), Pair(54, 117), Pair(19, -31), Pair(41, -9), Pair(-11, 15), Pair(20, -104),
        Pair(73, 90), Pair(67, 39), Pair(229, 49), Pair(16, 30), Pair(29, 26), Pair(42, -9), Pair(-36, 12), Pair(-57, -12),
        Pair(68, 38), Pair(50, 19), Pair(83, 19), Pair(-25, 41), Pair(60, 51), Pair(-57, 22), Pair(76, -16), Pair(64, -4),
        Pair(-42, 67), Pair(0, 0), Pair(-2, 48), Pair(-19, 44), Pair(1, 26), Pair(-11, 14), Pair(-47, 19), Pair(-96, 9),
        Pair(-25, 46), Pair(-8, 26), Pair(19, 26), Pair(-4, 25), Pair(-22, 18), Pair(-25, 16), Pair(-31, 13), Pair(-32, 4),
        Pair(111, -16), Pair(51, 19), Pair(25, 30), Pair(18, 11), Pair(-18, 17), Pair(-11, 7), Pair(-7, -5), Pair(-12, -9),
        Pair(86, -75), Pair(56, -11), Pair(33, -4), Pair(-22, -9), Pair(0, -1), Pair(7, -9), Pair(-6, -7), Pair(-7, -16)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-36, 25), Pair(-23, 23), Pair(-16, -11), Pair(1, 5), Pair(18, 1), Pair(9, 2), Pair(61, -11), Pair(-7, 11),
        Pair(0, 11), Pair(-7, 12), Pair(-5, 2), Pair(-14, 22), Pair(21, -1), Pair(-4, 12), Pair(14, 16), Pair(-2, 2),
        Pair(0, 6), Pair(2, 0), Pair(-10, -23), Pair(3, 4), Pair(5, 3), Pair(7, 4), Pair(2, 3), Pair(-7, 11),
        Pair(0, 3), Pair(-5, 7), Pair(2, -1), Pair(-2, 15), Pair(-2, 3), Pair(5, 8), Pair(2, 7), Pair(-1, 11),
        Pair(2, 2), Pair(6, 7), Pair(-8, -12), Pair(2, 11), Pair(-3, 9), Pair(3, 6), Pair(-3, 7), Pair(1, 5),
        Pair(-1, 5), Pair(-1, 9), Pair(-2, -2), Pair(-1, 5), Pair(-5, 18), Pair(-1, 11), Pair(-2, 10), Pair(1, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-129, 131), Pair(-46, -8), Pair(76, 4), Pair(109, 7), Pair(18, 54), Pair(11, -17), Pair(-53, 20), Pair(-56, -61),
        Pair(15, 6), Pair(27, 31), Pair(4, 59), Pair(-9, 34), Pair(-23, 48), Pair(-46, 52), Pair(-4, 22), Pair(4, 13),
        Pair(1, 70), Pair(-7, 22), Pair(-17, 46), Pair(5, 17), Pair(0, 28), Pair(-1, 62), Pair(-29, 44), Pair(-24, 26),
        Pair(-39, 33), Pair(-2, 34), Pair(-9, 16), Pair(22, 55), Pair(-8, 41), Pair(2, 28), Pair(-5, 17), Pair(18, 15),
        Pair(-8, 35), Pair(15, 30), Pair(0, 0), Pair(-1, 25), Pair(-2, 37), Pair(6, 34), Pair(2, 44), Pair(4, 21),
        Pair(-10, 22), Pair(-7, 39), Pair(7, 46), Pair(-1, 30), Pair(3, 31), Pair(4, 28), Pair(14, 15), Pair(18, -19),
        Pair(-20, 21), Pair(10, -4), Pair(-6, 31), Pair(-5, 31), Pair(8, 25), Pair(0, 48), Pair(15, 36), Pair(-1, 9),
        Pair(-1, 7), Pair(-6, 8), Pair(-10, 10), Pair(-22, 45), Pair(-1, 29), Pair(-3, 23), Pair(1, 12), Pair(-8, -8)
      },
      { // Piece 2
        Pair(19, -3), Pair(42, 26), Pair(-33, -2), Pair(-21, 18), Pair(96, -38), Pair(110, -12), Pair(-60, -12), Pair(-42, 6),
        Pair(-7, -3), Pair(21, -1), Pair(2, 38), Pair(39, -16), Pair(20, 26), Pair(52, -28), Pair(30, 32), Pair(12, 2),
        Pair(-32, -48), Pair(12, 3), Pair(32, -20), Pair(29, 13), Pair(-1, -14), Pair(28, -4), Pair(-26, 6), Pair(5, 16),
        Pair(0, 13), Pair(-16, -5), Pair(8, 8), Pair(40, -39), Pair(2, 13), Pair(2, -15), Pair(-5, 27), Pair(12, -11),
        Pair(-7, -1), Pair(9, 30), Pair(0, 0), Pair(11, 32), Pair(-2, 2), Pair(4, 31), Pair(15, -5), Pair(12, 4),
        Pair(-6, 11), Pair(-28, -11), Pair(17, 35), Pair(-5, -7), Pair(5, 26), Pair(9, -6), Pair(6, 11), Pair(6, 10),
        Pair(4, -33), Pair(-2, 37), Pair(4, -12), Pair(2, 22), Pair(-2, -4), Pair(0, 25), Pair(0, 18), Pair(-1, 26),
        Pair(9, 12), Pair(23, -19), Pair(3, 20), Pair(-17, -12), Pair(3, 8), Pair(-4, -15), Pair(-4, 36), Pair(-6, 43)
      },
      { // Piece 3
        Pair(-23, 47), Pair(-57, 60), Pair(-75, 38), Pair(-20, 34), Pair(-86, 53), Pair(-31, 27), Pair(20, 16), Pair(18, 27),
        Pair(-18, 48), Pair(-16, 36), Pair(9, -1), Pair(-11, 34), Pair(-2, 36), Pair(34, 18), Pair(34, 11), Pair(-45, 46),
        Pair(-25, 50), Pair(-7, 36), Pair(-55, 33), Pair(-18, 30), Pair(-15, 39), Pair(-14, 45), Pair(38, 10), Pair(28, 31),
        Pair(-1, 31), Pair(-5, 31), Pair(-10, 13), Pair(-7, 57), Pair(5, 21), Pair(-3, 32), Pair(-8, 50), Pair(-16, 40),
        Pair(4, 6), Pair(4, 24), Pair(0, 0), Pair(3, 33), Pair(7, 40), Pair(16, 12), Pair(21, 11), Pair(-4, 14),
        Pair(-4, 30), Pair(18, 19), Pair(1, -2), Pair(16, 13), Pair(-17, 42), Pair(-11, 39), Pair(-13, 19), Pair(10, 39),
        Pair(-6, 19), Pair(-1, 21), Pair(-5, -9), Pair(-11, 37), Pair(6, 17), Pair(-6, 20), Pair(1, 33), Pair(-67, 58),
        Pair(-3, 25), Pair(4, 25), Pair(0, -10), Pair(1, 23), Pair(-5, 32), Pair(-1, 27), Pair(-1, 17), Pair(-4, 30)
      },
      { // Piece 4
        Pair(-14, 52), Pair(-47, 90), Pair(20, -25), Pair(47, -4), Pair(-49, 97), Pair(-11, -2), Pair(-49, 39), Pair(31, -27),
        Pair(-9, 30), Pair(4, 18), Pair(-46, 50), Pair(5, -9), Pair(5, 26), Pair(-21, 61), Pair(-43, 101), Pair(-15, 3),
        Pair(17, -37), Pair(-23, 40), Pair(-17, 0), Pair(-25, 57), Pair(11, -14), Pair(-2, 35), Pair(23, 15), Pair(1, 34),
        Pair(-15, 57), Pair(-2, 21), Pair(5, -13), Pair(-16, 77), Pair(9, 16), Pair(1, 41), Pair(-24, 67), Pair(-6, 35),
        Pair(-6, 11), Pair(6, -5), Pair(0, 0), Pair(-6, 41), Pair(-2, 32), Pair(3, 27), Pair(9, 16), Pair(3, -10),
        Pair(-1, 11), Pair(6, 13), Pair(1, 31), Pair(3, 30), Pair(-4, 47), Pair(1, 39), Pair(-8, 54), Pair(5, 26),
        Pair(-16, 21), Pair(2, 26), Pair(2, 4), Pair(8, 17), Pair(8, 28), Pair(20, -10), Pair(-1, 40), Pair(-1, 65),
        Pair(7, 4), Pair(15, 2), Pair(14, 3), Pair(3, 21), Pair(8, 6), Pair(18, -9), Pair(-11, 92), Pair(-14, 52)
      },
      { // Piece 5
        Pair(0, 53), Pair(-17, 79), Pair(26, 99), Pair(70, 111), Pair(62, 13), Pair(-50, -30), Pair(-44, -108), Pair(-10, 36),
        Pair(18, 73), Pair(82, 81), Pair(7, 92), Pair(72, 89), Pair(115, 55), Pair(-34, 39), Pair(40, 22), Pair(-89, 36),
        Pair(4, 55), Pair(25, 84), Pair(174, 42), Pair(13, 58), Pair(59, 8), Pair(62, 43), Pair(23, -2), Pair(-31, 6),
        Pair(177, 89), Pair(60, -12), Pair(78, 11), Pair(57, 28), Pair(58, 34), Pair(9, 28), Pair(-77, 32), Pair(-5, -13),
        Pair(-102, 105), Pair(39, 35), Pair(0, 0), Pair(15, 28), Pair(-34, 33), Pair(-9, 7), Pair(-49, 24), Pair(-3, -4),
        Pair(88, 4), Pair(-26, 34), Pair(35, 11), Pair(-24, 24), Pair(18, 11), Pair(-1, 10), Pair(1, 1), Pair(-11, -4),
        Pair(-15, 26), Pair(-5, 21), Pair(7, 13), Pair(1, 9), Pair(-4, 4), Pair(11, -3), Pair(-3, 2), Pair(-6, 0),
        Pair(-11, 34), Pair(18, -24), Pair(21, -24), Pair(7, -18), Pair(9, -13), Pair(-1, -7), Pair(-4, -9), Pair(-7, -16)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(26, -2), Pair(13, 5), Pair(-1, 19), Pair(-11, 23), Pair(51, 12), Pair(-48, 25), Pair(1, 10), Pair(33, 8),
        Pair(-4, 9), Pair(3, 4), Pair(-1, 10), Pair(-2, 4), Pair(-1, 16), Pair(7, 6), Pair(-3, 11), Pair(-6, 7),
        Pair(0, 7), Pair(7, 3), Pair(9, 8), Pair(-4, 1), Pair(10, 3), Pair(0, 12), Pair(-3, 10), Pair(4, 5),
        Pair(1, 8), Pair(2, 5), Pair(-3, 14), Pair(1, -16), Pair(2, 17), Pair(1, 0), Pair(4, 10), Pair(1, 7),
        Pair(-1, 8), Pair(5, 4), Pair(9, 11), Pair(2, -4), Pair(5, 15), Pair(2, 2), Pair(2, 10), Pair(2, 6),
        Pair(-2, 7), Pair(3, 6), Pair(2, 11), Pair(10, 1), Pair(4, 15), Pair(-1, 9), Pair(-1, 12), Pair(3, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-34, -38), Pair(10, 93), Pair(23, -6), Pair(28, -7), Pair(-18, 11), Pair(-34, 67), Pair(-54, 22), Pair(-118, 106),
        Pair(5, 33), Pair(-23, 61), Pair(1, 42), Pair(-39, 53), Pair(-10, 43), Pair(4, 26), Pair(-36, 52), Pair(-6, 58),
        Pair(-36, 48), Pair(19, 25), Pair(9, 23), Pair(-4, 26), Pair(-2, 10), Pair(-15, 46), Pair(7, 30), Pair(-4, 55),
        Pair(8, 27), Pair(-1, 29), Pair(15, 34), Pair(-23, 34), Pair(9, 28), Pair(-12, 46), Pair(-4, 34), Pair(-22, 14),
        Pair(-1, 44), Pair(29, 19), Pair(1, 34), Pair(0, 0), Pair(-9, 39), Pair(1, 38), Pair(-14, 48), Pair(13, 22),
        Pair(0, 24), Pair(-7, 27), Pair(5, 39), Pair(15, 61), Pair(13, 38), Pair(1, 32), Pair(3, 43), Pair(4, 29),
        Pair(-3, 51), Pair(11, 10), Pair(0, 25), Pair(7, 29), Pair(5, 26), Pair(0, 44), Pair(1, 40), Pair(3, 11),
        Pair(-58, 30), Pair(3, 31), Pair(8, 51), Pair(20, 17), Pair(-11, 39), Pair(8, 3), Pair(0, 56), Pair(-15, 99)
      },
      { // Piece 2
        Pair(-18, 1), Pair(81, -7), Pair(44, -25), Pair(67, -53), Pair(-110, 27), Pair(20, -35), Pair(-43, 38), Pair(-42, -135),
        Pair(-45, -18), Pair(4, 24), Pair(2, 7), Pair(-19, 7), Pair(32, -27), Pair(30, -15), Pair(-39, -19), Pair(-4, 32),
        Pair(6, 7), Pair(17, -43), Pair(17, 4), Pair(7, 7), Pair(38, 3), Pair(-20, -22), Pair(-4, 15), Pair(-23, 16),
        Pair(-13, -17), Pair(6, 10), Pair(-12, 3), Pair(0, 6), Pair(-13, -23), Pair(5, 1), Pair(-9, 0), Pair(0, 7),
        Pair(28, 0), Pair(-2, 3), Pair(15, 24), Pair(0, 0), Pair(-5, 30), Pair(4, -5), Pair(10, 24), Pair(3, -8),
        Pair(-6, -15), Pair(13, 1), Pair(-19, -29), Pair(16, 37), Pair(-4, -11), Pair(12, 20), Pair(1, 6), Pair(18, 15),
        Pair(5, 20), Pair(-26, -34), Pair(14, 11), Pair(-2, -7), Pair(8, 28), Pair(0, -21), Pair(1, 24), Pair(10, 5),
        Pair(-33, -51), Pair(18, 17), Pair(-6, -13), Pair(24, 3), Pair(6, -8), Pair(4, 16), Pair(-29, -14), Pair(5, -21)
      },
      { // Piece 3
        Pair(17, 30), Pair(29, 32), Pair(8, 27), Pair(-27, 34), Pair(-10, 46), Pair(-4, 19), Pair(-16, 26), Pair(8, 30),
        Pair(-7, 47), Pair(-6, 36), Pair(10, 28), Pair(-3, 15), Pair(-30, 55), Pair(-24, 49), Pair(-8, 21), Pair(-42, 55),
        Pair(4, 40), Pair(17, 39), Pair(-13, 35), Pair(17, 10), Pair(-43, 56), Pair(-28, 23), Pair(3, 25), Pair(-7, 40),
        Pair(5, 25), Pair(7, 40), Pair(10, 28), Pair(-10, 7), Pair(11, 26), Pair(5, 14), Pair(-4, 34), Pair(1, 33),
        Pair(5, 21), Pair(-9, 34), Pair(2, 19), Pair(0, 0), Pair(-11, 43), Pair(-18, 36), Pair(15, 16), Pair(-18, 17),
        Pair(14, 31), Pair(-6, 36), Pair(21, 23), Pair(13, -2), Pair(10, 25), Pair(1, 3), Pair(3, 26), Pair(16, 12),
        Pair(9, 29), Pair(-10, 52), Pair(22, 9), Pair(-4, 10), Pair(-3, 26), Pair(0, 27), Pair(-18, 50), Pair(7, 38),
        Pair(1, 29), Pair(4, 20), Pair(-3, 32), Pair(10, 3), Pair(-5, 30), Pair(-3, 27), Pair(-5, 31), Pair(4, 20)
      },
      { // Piece 4
        Pair(53, 0), Pair(51, 40), Pair(15, -37), Pair(43, 14), Pair(-9, 32), Pair(52, 84), Pair(-37, 34), Pair(-12, 29),
        Pair(-29, 55), Pair(-2, 39), Pair(9, 8), Pair(33, -14), Pair(-28, 47), Pair(35, 67), Pair(-14, 53), Pair(-16, 106),
        Pair(-10, 53), Pair(-10, 28), Pair(10, 6), Pair(-5, 48), Pair(-13, 73), Pair(0, 32), Pair(14, 42), Pair(2, 15),
        Pair(-14, 51), Pair(-3, 29), Pair(3, 47), Pair(-18, 9), Pair(-10, 50), Pair(3, 28), Pair(-6, 14), Pair(22, -30),
        Pair(9, 3), Pair(16, -14), Pair(-1, 1), Pair(0, 0), Pair(-10, 40), Pair(-8, 35), Pair(-16, 55), Pair(-9, 38),
        Pair(-3, 31), Pair(5, 43), Pair(-4, 38), Pair(3, 30), Pair(0, 32), Pair(4, 49), Pair(-2, 44), Pair(16, 26),
        Pair(23, -15), Pair(6, 12), Pair(8, 23), Pair(5, 33), Pair(7, 12), Pair(8, 27), Pair(-2, 8), Pair(3, -19),
        Pair(21, -21), Pair(13, 23), Pair(12, 15), Pair(5, 17), Pair(0, 31), Pair(-24, 97), Pair(66, -109), Pair(-39, 7)
      },
      { // Piece 5
        Pair(-25, -3), Pair(-33, 32), Pair(-53, 49), Pair(-12, 102), Pair(-9, 97), Pair(51, 135), Pair(-19, -23), Pair(34, -3),
        Pair(-83, 13), Pair(15, 110), Pair(12, 81), Pair(12, 35), Pair(22, 53), Pair(91, 101), Pair(-50, 102), Pair(-4, 5),
        Pair(-142, 127), Pair(-33, 70), Pair(114, 33), Pair(106, 25), Pair(-5, 46), Pair(-84, 61), Pair(-41, 30), Pair(43, 36),
        Pair(-111, 47), Pair(1, 6), Pair(-22, 15), Pair(15, 0), Pair(48, -4), Pair(12, 25), Pair(77, -23), Pair(-4, -11),
        Pair(34, -23), Pair(-103, 40), Pair(-42, 36), Pair(0, 0), Pair(21, 25), Pair(26, 11), Pair(40, -8), Pair(-76, -1),
        Pair(-21, 2), Pair(33, -8), Pair(-22, 8), Pair(-84, 41), Pair(-79, 25), Pair(13, -4), Pair(5, -9), Pair(-5, -12),
        Pair(10, -3), Pair(22, -5), Pair(-13, -6), Pair(-54, 15), Pair(-11, -5), Pair(-4, -11), Pair(4, -16), Pair(2, -14),
        Pair(-12, 0), Pair(-6, -14), Pair(-1, -21), Pair(-26, -17), Pair(8, -41), Pair(-1, -15), Pair(-2, -19), Pair(3, -28)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-24, 5), Pair(20, -15), Pair(-36, 18), Pair(-29, 29), Pair(-65, 32), Pair(-24, -8), Pair(49, 23), Pair(-16, 23),
        Pair(2, 5), Pair(2, 7), Pair(-5, 12), Pair(0, 10), Pair(10, -19), Pair(1, 17), Pair(-4, 9), Pair(2, 1),
        Pair(3, 4), Pair(4, 10), Pair(3, 2), Pair(9, 10), Pair(1, 0), Pair(10, 6), Pair(1, 2), Pair(2, 4),
        Pair(2, 5), Pair(2, 11), Pair(-2, 3), Pair(2, 17), Pair(-2, -10), Pair(5, 10), Pair(-4, 5), Pair(4, 7),
        Pair(2, 7), Pair(4, 9), Pair(2, 4), Pair(13, 12), Pair(0, -2), Pair(17, 11), Pair(2, 6), Pair(3, 7),
        Pair(4, 9), Pair(2, 10), Pair(3, 11), Pair(3, 5), Pair(3, 7), Pair(4, 19), Pair(1, 11), Pair(4, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-3, 35), Pair(54, 57), Pair(-64, 102), Pair(45, 59), Pair(-15, 14), Pair(123, -20), Pair(10, -6), Pair(13, 25),
        Pair(-4, 38), Pair(-42, 38), Pair(-37, 44), Pair(14, 58), Pair(-40, 55), Pair(48, -5), Pair(-101, 49), Pair(-46, 3),
        Pair(-21, 56), Pair(-1, 68), Pair(9, 40), Pair(5, 28), Pair(-41, 57), Pair(13, 28), Pair(-33, 51), Pair(-63, 94),
        Pair(1, 34), Pair(4, 35), Pair(-9, 24), Pair(1, 57), Pair(-14, 14), Pair(-1, 32), Pair(-9, 17), Pair(-11, 29),
        Pair(13, -6), Pair(32, 35), Pair(14, 31), Pair(12, 36), Pair(0, 0), Pair(5, 35), Pair(-12, 46), Pair(14, 9),
        Pair(8, 38), Pair(3, 47), Pair(1, 23), Pair(14, 29), Pair(13, 52), Pair(7, 46), Pair(0, 6), Pair(-4, 55),
        Pair(38, -6), Pair(21, -9), Pair(-1, 31), Pair(3, 30), Pair(11, 27), Pair(2, 25), Pair(0, 26), Pair(-16, 59),
        Pair(26, -15), Pair(0, 50), Pair(-5, 50), Pair(-1, 26), Pair(-2, 54), Pair(-8, 28), Pair(8, 16), Pair(4, 22)
      },
      { // Piece 2
        Pair(-173, 1), Pair(49, -25), Pair(-48, -54), Pair(56, -16), Pair(118, -27), Pair(30, -4), Pair(-17, -22), Pair(15, -11),
        Pair(37, -21), Pair(62, -45), Pair(8, 2), Pair(45, -38), Pair(32, -8), Pair(-17, 8), Pair(1, -15), Pair(-153, -7),
        Pair(-5, 3), Pair(2, 22), Pair(16, -32), Pair(41, 2), Pair(-13, -14), Pair(46, -9), Pair(-9, -18), Pair(-10, 17),
        Pair(11, 18), Pair(-8, 9), Pair(13, 6), Pair(17, -23), Pair(-15, 18), Pair(6, -27), Pair(3, 20), Pair(-2, -20),
        Pair(4, -1), Pair(17, 17), Pair(-6, 12), Pair(12, 12), Pair(0, 0), Pair(7, 24), Pair(-13, 8), Pair(0, 38),
        Pair(4, 13), Pair(-7, 7), Pair(2, 28), Pair(-4, 0), Pair(11, 39), Pair(-26, -11), Pair(3, 36), Pair(-4, 5),
        Pair(8, -30), Pair(-3, 28), Pair(-8, -15), Pair(3, 27), Pair(-3, 1), Pair(9, 12), Pair(-30, -17), Pair(-18, 69),
        Pair(17, 24), Pair(-18, -44), Pair(1, 20), Pair(1, 14), Pair(16, 15), Pair(-12, 1), Pair(4, 20), Pair(-14, -54)
      },
      { // Piece 3
        Pair(14, 28), Pair(21, 19), Pair(-1, 26), Pair(21, 38), Pair(33, 20), Pair(34, 20), Pair(101, 2), Pair(63, 7),
        Pair(-4, 41), Pair(-23, 42), Pair(-13, 43), Pair(-5, 30), Pair(4, -7), Pair(8, 13), Pair(-78, 80), Pair(56, 20),
        Pair(33, 16), Pair(3, 40), Pair(3, 41), Pair(28, 22), Pair(6, 23), Pair(-22, 30), Pair(8, 39), Pair(63, 16),
        Pair(21, 26), Pair(26, 27), Pair(-6, 49), Pair(21, 34), Pair(20, 2), Pair(20, 41), Pair(34, 3), Pair(-12, 47),
        Pair(17, 23), Pair(3, 24), Pair(-20, 35), Pair(21, 17), Pair(0, 0), Pair(-7, 28), Pair(-13, 3), Pair(18, 17),
        Pair(15, 4), Pair(-6, 44), Pair(-11, 27), Pair(-9, 36), Pair(-4, 15), Pair(7, 26), Pair(-2, 24), Pair(32, 0),
        Pair(4, 13), Pair(6, 24), Pair(16, 7), Pair(-4, 23), Pair(-2, -7), Pair(-7, 32), Pair(3, 20), Pair(40, 12),
        Pair(4, 31), Pair(5, 23), Pair(7, 19), Pair(4, 28), Pair(8, 0), Pair(-1, 31), Pair(10, 20), Pair(18, 20)
      },
      { // Piece 4
        Pair(-43, 27), Pair(-25, 51), Pair(17, 10), Pair(-31, 67), Pair(62, -5), Pair(-36, 51), Pair(-53, 96), Pair(-3, 84),
        Pair(-19, 81), Pair(-8, 40), Pair(-2, 51), Pair(54, -27), Pair(5, 48), Pair(24, 16), Pair(24, 20), Pair(-34, 104),
        Pair(-10, 53), Pair(-18, 29), Pair(-27, 31), Pair(-2, 51), Pair(-29, 47), Pair(-7, 60), Pair(-6, 37), Pair(-22, 94),
        Pair(7, 30), Pair(4, -10), Pair(-13, 55), Pair(-1, 19), Pair(4, -3), Pair(17, -8), Pair(7, 58), Pair(-11, 49),
        Pair(5, -9), Pair(-4, 17), Pair(-9, 25), Pair(1, 57), Pair(0, 0), Pair(-17, 52), Pair(5, 21), Pair(-21, 52),
        Pair(8, -6), Pair(3, 56), Pair(0, 56), Pair(6, 24), Pair(0, 11), Pair(-3, 29), Pair(0, 30), Pair(-5, 41),
        Pair(7, 26), Pair(17, 1), Pair(8, 29), Pair(4, 42), Pair(9, 20), Pair(3, -1), Pair(15, 3), Pair(40, 1),
        Pair(9, -3), Pair(8, 12), Pair(2, 40), Pair(5, 20), Pair(2, -11), Pair(-27, 109), Pair(9, 14), Pair(28, -2)
      },
      { // Piece 5
        Pair(-37, 11), Pair(-57, -43), Pair(58, 97), Pair(-87, 103), Pair(73, 8), Pair(56, 77), Pair(30, 131), Pair(24, -77),
        Pair(37, 20), Pair(-53, 16), Pair(-8, 60), Pair(0, 43), Pair(42, 111), Pair(26, 65), Pair(66, 26), Pair(-65, 55),
        Pair(34, 13), Pair(-31, 29), Pair(-48, 33), Pair(25, 28), Pair(51, 39), Pair(8, 52), Pair(-27, 17), Pair(-47, 5),
        Pair(-80, 1), Pair(-89, 20), Pair(40, -18), Pair(23, -13), Pair(-10, 13), Pair(-11, -7), Pair(30, -11), Pair(-12, 17),
        Pair(26, -13), Pair(-8, 2), Pair(15, 13), Pair(-74, 31), Pair(0, 0), Pair(-34, 12), Pair(35, 1), Pair(11, -13),
        Pair(71, -19), Pair(57, -15), Pair(0, -3), Pair(-68, 27), Pair(-55, 26), Pair(-31, 6), Pair(8, -7), Pair(20, -5),
        Pair(-10, 10), Pair(-7, -12), Pair(-3, -6), Pair(-45, 5), Pair(-50, 15), Pair(-40, -2), Pair(5, -17), Pair(8, -17),
        Pair(-14, -42), Pair(-12, -22), Pair(-11, -32), Pair(-17, -11), Pair(-5, -21), Pair(5, -24), Pair(4, -23), Pair(8, -28)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 12), Pair(-13, 24), Pair(-1, 12), Pair(-21, 4), Pair(47, -32), Pair(-61, -2), Pair(-29, 14), Pair(3, 11),
        Pair(-9, 7), Pair(-3, 6), Pair(2, 10), Pair(13, 5), Pair(-1, 9), Pair(-7, 9), Pair(-4, 20), Pair(6, 8),
        Pair(3, 6), Pair(7, 5), Pair(9, 2), Pair(6, 7), Pair(11, 3), Pair(-1, -3), Pair(-3, -4), Pair(-5, 1),
        Pair(1, 6), Pair(6, 8), Pair(6, 8), Pair(0, 2), Pair(5, 11), Pair(1, -1), Pair(4, -2), Pair(-3, 2),
        Pair(-1, 8), Pair(4, 9), Pair(4, 4), Pair(2, 3), Pair(16, 5), Pair(4, -2), Pair(7, 1), Pair(-4, 5),
        Pair(-1, 11), Pair(5, 9), Pair(1, 7), Pair(-4, 16), Pair(13, 8), Pair(3, 7), Pair(3, 12), Pair(-5, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(99, -11), Pair(-44, 82), Pair(25, 30), Pair(98, -21), Pair(3, -12), Pair(120, -38), Pair(102, -49), Pair(26, -24),
        Pair(17, 41), Pair(25, -9), Pair(28, 0), Pair(42, 37), Pair(37, 14), Pair(-20, 45), Pair(-16, 58), Pair(49, -22),
        Pair(39, 18), Pair(3, 40), Pair(25, 36), Pair(-11, 51), Pair(14, 29), Pair(-24, 46), Pair(14, 0), Pair(21, 37),
        Pair(-37, 50), Pair(16, 22), Pair(23, 23), Pair(2, 33), Pair(20, 20), Pair(-23, 12), Pair(-12, 17), Pair(-7, 37),
        Pair(-8, 32), Pair(1, 24), Pair(18, 34), Pair(25, 27), Pair(7, 23), Pair(0, 0), Pair(-5, 28), Pair(-1, 29),
        Pair(12, 26), Pair(12, 11), Pair(7, 30), Pair(5, 28), Pair(24, 41), Pair(11, 48), Pair(12, 33), Pair(-2, -25),
        Pair(5, 23), Pair(24, 18), Pair(4, 8), Pair(6, 14), Pair(-1, 31), Pair(3, 42), Pair(-7, 21), Pair(-1, 12),
        Pair(-86, 27), Pair(10, -5), Pair(12, 44), Pair(7, 14), Pair(24, -8), Pair(12, 12), Pair(16, -20), Pair(12, 47)
      },
      { // Piece 2
        Pair(-10, 0), Pair(-66, -32), Pair(-31, 8), Pair(114, -26), Pair(26, -16), Pair(-23, -20), Pair(5, 5), Pair(-27, -18),
        Pair(21, -10), Pair(-7, 3), Pair(7, -8), Pair(44, -12), Pair(29, -9), Pair(59, -3), Pair(20, -4), Pair(-14, 20),
        Pair(-16, 2), Pair(0, -10), Pair(40, -8), Pair(35, -14), Pair(-11, 14), Pair(8, -31), Pair(-22, 23), Pair(-47, -6),
        Pair(-23, 32), Pair(23, 5), Pair(1, 1), Pair(12, 7), Pair(14, -20), Pair(-9, 8), Pair(-22, -2), Pair(7, 16),
        Pair(17, -2), Pair(-15, 14), Pair(18, 16), Pair(19, 12), Pair(14, 16), Pair(0, 0), Pair(-8, 22), Pair(-10, -8),
        Pair(-9, 9), Pair(9, 16), Pair(-5, 7), Pair(15, 16), Pair(-4, 4), Pair(28, 23), Pair(-10, -22), Pair(11, 26),
        Pair(-3, 9), Pair(-2, -2), Pair(19, 2), Pair(-13, 11), Pair(13, 11), Pair(8, -3), Pair(9, 16), Pair(-40, -29),
        Pair(13, -7), Pair(5, 16), Pair(-18, 5), Pair(0, 22), Pair(4, 0), Pair(11, 13), Pair(-6, -14), Pair(37, -16)
      },
      { // Piece 3
        Pair(63, 12), Pair(24, 20), Pair(22, 20), Pair(58, 2), Pair(12, 14), Pair(68, -15), Pair(12, 18), Pair(14, 27),
        Pair(16, 24), Pair(3, 26), Pair(0, 21), Pair(26, 8), Pair(5, 17), Pair(21, 13), Pair(42, 12), Pair(36, 17),
        Pair(10, 16), Pair(42, 4), Pair(25, 13), Pair(59, 7), Pair(9, 22), Pair(28, 2), Pair(23, -1), Pair(-9, 11),
        Pair(6, 20), Pair(29, 16), Pair(16, 21), Pair(16, 6), Pair(15, 23), Pair(38, -16), Pair(5, 31), Pair(28, 21),
        Pair(5, 25), Pair(24, 8), Pair(1, 32), Pair(15, 18), Pair(-6, 30), Pair(0, 0), Pair(-11, 25), Pair(3, 1),
        Pair(-7, 27), Pair(8, 15), Pair(5, 16), Pair(19, 15), Pair(9, 27), Pair(3, 1), Pair(7, 4), Pair(-7, 10),
        Pair(-9, 28), Pair(-6, 6), Pair(12, 17), Pair(13, 8), Pair(15, -2), Pair(-6, 10), Pair(5, 19), Pair(-23, 49),
        Pair(9, 11), Pair(11, 17), Pair(15, 11), Pair(16, 9), Pair(8, 15), Pair(7, -8), Pair(1, 17), Pair(5, 14)
      },
      { // Piece 4
        Pair(-20, 77), Pair(2, -9), Pair(-36, 63), Pair(10, 21), Pair(-30, 84), Pair(49, -33), Pair(-9, -28), Pair(-1, 33),
        Pair(4, 43), Pair(41, -1), Pair(19, 23), Pair(32, 9), Pair(49, 15), Pair(-19, -8), Pair(16, 105), Pair(-28, 79),
        Pair(10, 29), Pair(-16, 46), Pair(2, 40), Pair(-24, 90), Pair(25, -16), Pair(-79, 63), Pair(-18, 42), Pair(-15, 28),
        Pair(-21, 47), Pair(26, 6), Pair(-26, 35), Pair(-20, 89), Pair(-10, 41), Pair(30, -13), Pair(-17, 30), Pair(-19, 78),
        Pair(16, 54), Pair(9, 59), Pair(17, 26), Pair(0, 39), Pair(6, 29), Pair(0, 0), Pair(4, 11), Pair(11, -20),
        Pair(-10, 32), Pair(6, 51), Pair(14, 18), Pair(16, 20), Pair(-6, 59), Pair(10, 20), Pair(1, 26), Pair(-2, 18),
        Pair(27, 22), Pair(21, 7), Pair(8, 29), Pair(8, 34), Pair(7, 38), Pair(1, 17), Pair(13, 9), Pair(43, -65),
        Pair(21, 11), Pair(-15, 60), Pair(15, -11), Pair(3, 33), Pair(3, 36), Pair(8, 3), Pair(-2, 32), Pair(28, 13)
      },
      { // Piece 5
        Pair(49, -75), Pair(-46, -10), Pair(-11, 40), Pair(48, 12), Pair(-54, 96), Pair(-42, 52), Pair(-15, 121), Pair(-20, 74),
        Pair(-31, 32), Pair(78, -32), Pair(125, 18), Pair(-43, 9), Pair(0, 85), Pair(-36, 62), Pair(129, 62), Pair(-54, 27),
        Pair(-91, 19), Pair(-32, 10), Pair(-17, 9), Pair(-59, 45), Pair(52, 34), Pair(-27, 38), Pair(-59, 45), Pair(-44, 29),
        Pair(-28, -4), Pair(-15, -3), Pair(-49, 21), Pair(-18, 21), Pair(72, -1), Pair(47, -4), Pair(30, 2), Pair(-12, 12),
        Pair(-80, 32), Pair(-48, 12), Pair(-18, 32), Pair(72, 11), Pair(40, -3), Pair(0, 0), Pair(7, -6), Pair(-9, 21),
        Pair(18, -9), Pair(-38, 4), Pair(-2, -1), Pair(20, 1), Pair(-22, 18), Pair(-20, 17), Pair(-24, 4), Pair(36, -10),
        Pair(-48, -2), Pair(-46, 24), Pair(0, -8), Pair(-22, 12), Pair(13, -2), Pair(-67, 28), Pair(-15, 3), Pair(13, 0),
        Pair(-4, -29), Pair(-12, -8), Pair(-21, -8), Pair(1, -33), Pair(0, -26), Pair(-14, -12), Pair(8, -27), Pair(15, -26)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 17), Pair(21, 7), Pair(44, -5), Pair(5, 10), Pair(-39, 10), Pair(-49, 14), Pair(6, -18), Pair(4, -6),
        Pair(4, 8), Pair(5, 3), Pair(-6, 11), Pair(-5, 14), Pair(0, 1), Pair(-18, 19), Pair(9, -4), Pair(10, 11),
        Pair(3, 10), Pair(6, 9), Pair(-2, 6), Pair(3, 3), Pair(4, 8), Pair(-2, 1), Pair(0, -14), Pair(-3, -10),
        Pair(0, 11), Pair(1, 13), Pair(2, 7), Pair(3, 10), Pair(-4, 4), Pair(4, -2), Pair(-1, 3), Pair(9, -9),
        Pair(0, 11), Pair(1, 10), Pair(0, 9), Pair(1, 9), Pair(2, 7), Pair(14, 4), Pair(1, -6), Pair(6, -1),
        Pair(-1, 12), Pair(0, 12), Pair(-1, 8), Pair(3, 10), Pair(-4, 11), Pair(6, 14), Pair(5, -2), Pair(-1, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(13, 79), Pair(24, 4), Pair(-62, 43), Pair(11, 45), Pair(52, 26), Pair(-26, -40), Pair(-29, 53), Pair(2, -12),
        Pair(-40, 27), Pair(-31, 31), Pair(14, -1), Pair(39, 0), Pair(116, 3), Pair(94, 0), Pair(9, -11), Pair(-12, 35),
        Pair(-15, 12), Pair(19, 12), Pair(13, 20), Pair(23, 15), Pair(18, -4), Pair(10, 20), Pair(-6, 15), Pair(38, -18),
        Pair(-10, 18), Pair(13, 9), Pair(15, 23), Pair(20, 22), Pair(15, 26), Pair(26, 12), Pair(7, 10), Pair(-17, -5),
        Pair(-6, 27), Pair(9, 13), Pair(5, 15), Pair(14, 31), Pair(21, 23), Pair(28, 20), Pair(0, 0), Pair(3, 39),
        Pair(-18, 31), Pair(16, 16), Pair(8, 28), Pair(21, 30), Pair(23, 12), Pair(14, 34), Pair(18, 33), Pair(31, 31),
        Pair(6, -36), Pair(-34, 12), Pair(11, 1), Pair(4, 33), Pair(2, 26), Pair(3, 29), Pair(6, -2), Pair(-4, -10),
        Pair(24, -10), Pair(-15, -13), Pair(25, 34), Pair(-39, 37), Pair(12, 23), Pair(8, 24), Pair(8, 11), Pair(-67, 148)
      },
      { // Piece 2
        Pair(-40, -28), Pair(16, -16), Pair(15, 3), Pair(3, 4), Pair(-34, -17), Pair(7, -10), Pair(184, -22), Pair(-40, 76),
        Pair(-2, 4), Pair(18, -18), Pair(-7, 0), Pair(9, -22), Pair(61, -11), Pair(-4, -32), Pair(30, 18), Pair(-11, 14),
        Pair(-6, -22), Pair(37, -5), Pair(37, -26), Pair(47, -2), Pair(12, -9), Pair(77, -13), Pair(1, -15), Pair(17, 13),
        Pair(17, 1), Pair(-2, -8), Pair(-19, 20), Pair(14, -2), Pair(4, 10), Pair(23, -21), Pair(1, -3), Pair(-34, -9),
        Pair(21, -1), Pair(9, 14), Pair(10, -11), Pair(12, 13), Pair(21, 8), Pair(13, 11), Pair(0, 0), Pair(10, 16),
        Pair(-1, 15), Pair(-1, 4), Pair(0, 10), Pair(9, 7), Pair(5, 16), Pair(10, -2), Pair(9, 20), Pair(-30, -26),
        Pair(-21, -13), Pair(0, 17), Pair(3, 10), Pair(10, 11), Pair(-9, 8), Pair(15, -5), Pair(11, -2), Pair(1, -3),
        Pair(10, -6), Pair(-5, -26), Pair(4, 13), Pair(-19, 9), Pair(15, 8), Pair(-4, 1), Pair(-6, -6), Pair(5, -28)
      },
      { // Piece 3
        Pair(31, 17), Pair(22, 14), Pair(80, 17), Pair(118, -17), Pair(-11, 32), Pair(-21, 45), Pair(84, -3), Pair(28, 18),
        Pair(52, 3), Pair(0, 21), Pair(18, 6), Pair(6, 15), Pair(23, 21), Pair(32, 1), Pair(86, -5), Pair(0, 12),
        Pair(-2, 28), Pair(16, 9), Pair(35, 5), Pair(5, 17), Pair(19, 3), Pair(-13, 16), Pair(65, -17), Pair(-24, 37),
        Pair(-11, 35), Pair(23, 14), Pair(-10, 21), Pair(34, 7), Pair(26, 14), Pair(-20, 47), Pair(6, -6), Pair(-36, 48),
        Pair(5, 23), Pair(-9, 19), Pair(24, 14), Pair(36, 8), Pair(26, 3), Pair(-10, 29), Pair(0, 0), Pair(-47, 4),
        Pair(-14, 34), Pair(-8, 28), Pair(19, 12), Pair(17, 11), Pair(-1, 14), Pair(12, 3), Pair(-17, -18), Pair(-11, 3),
        Pair(-1, 5), Pair(-9, 15), Pair(-9, 11), Pair(2, 21), Pair(14, 11), Pair(12, -6), Pair(2, -15), Pair(-4, 5),
        Pair(4, 17), Pair(10, 8), Pair(4, 13), Pair(10, 7), Pair(8, 4), Pair(3, 15), Pair(-2, -24), Pair(1, -3)
      },
      { // Piece 4
        Pair(-15, -6), Pair(6, 35), Pair(3, 19), Pair(85, -4), Pair(-45, 61), Pair(95, 11), Pair(38, 14), Pair(82, -95),
        Pair(-19, 57), Pair(-6, 13), Pair(46, -16), Pair(23, 36), Pair(-13, 38), Pair(73, -52), Pair(28, -50), Pair(16, 25),
        Pair(-37, 39), Pair(5, -8), Pair(36, -46), Pair(6, 15), Pair(-3, -8), Pair(16, -12), Pair(30, -49), Pair(0, 5),
        Pair(1, -28), Pair(-24, -2), Pair(-4, 45), Pair(36, -26), Pair(-4, 27), Pair(-9, 23), Pair(3, 30), Pair(3, -50),
        Pair(9, -33), Pair(15, -31), Pair(9, -11), Pair(-3, 0), Pair(28, -10), Pair(-30, 38), Pair(0, 0), Pair(3, -18),
        Pair(-8, 21), Pair(18, 4), Pair(10, 24), Pair(1, 20), Pair(12, 9), Pair(16, -21), Pair(-1, 20), Pair(12, -46),
        Pair(33, -16), Pair(-15, 23), Pair(6, 18), Pair(7, 7), Pair(3, 13), Pair(-7, 3), Pair(0, 14), Pair(17, 55),
        Pair(-17, 29), Pair(-1, -2), Pair(-16, 6), Pair(-1, 38), Pair(-11, 7), Pair(30, -53), Pair(9, -81), Pair(-48, 12)
      },
      { // Piece 5
        Pair(-46, -106), Pair(-14, 50), Pair(13, 19), Pair(-13, 4), Pair(4, 2), Pair(73, 43), Pair(28, 55), Pair(22, 150),
        Pair(-41, -16), Pair(-14, 23), Pair(15, 61), Pair(10, 21), Pair(59, -21), Pair(63, 41), Pair(156, 42), Pair(35, 70),
        Pair(-99, -9), Pair(-91, 29), Pair(-32, 29), Pair(-112, 58), Pair(32, -5), Pair(25, 50), Pair(131, 46), Pair(24, 45),
        Pair(-71, 1), Pair(-1, 4), Pair(-21, 12), Pair(-34, 29), Pair(59, 33), Pair(34, -5), Pair(23, 17), Pair(-66, 3),
        Pair(-61, -4), Pair(-33, 20), Pair(-30, 23), Pair(-14, 22), Pair(15, 24), Pair(21, 4), Pair(0, 0), Pair(-18, 3),
        Pair(-17, -20), Pair(39, -10), Pair(-36, 6), Pair(-37, 14), Pair(-8, 10), Pair(-15, 9), Pair(4, 7), Pair(-31, 0),
        Pair(-42, -5), Pair(-17, -13), Pair(-35, 7), Pair(-26, 2), Pair(-13, 9), Pair(-22, 10), Pair(8, -3), Pair(-25, 9),
        Pair(17, -75), Pair(-25, -6), Pair(-22, -9), Pair(-13, -11), Pair(-5, -7), Pair(10, -25), Pair(12, -15), Pair(-7, -27)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(4, 7), Pair(20, 15), Pair(0, 3), Pair(-17, 10), Pair(9, 6), Pair(-40, 26), Pair(-23, 33), Pair(69, -27),
        Pair(-7, 10), Pair(-8, 10), Pair(-4, 4), Pair(4, 6), Pair(-7, 13), Pair(-7, 7), Pair(2, 10), Pair(22, -1),
        Pair(-3, 5), Pair(-2, 9), Pair(-3, 5), Pair(-1, 4), Pair(0, 4), Pair(3, 4), Pair(-1, 0), Pair(4, 0),
        Pair(-3, 10), Pair(0, 11), Pair(-3, 10), Pair(2, 8), Pair(4, 6), Pair(-3, 2), Pair(8, -8), Pair(7, 0),
        Pair(-2, 11), Pair(0, 10), Pair(-1, 9), Pair(-1, 9), Pair(5, 7), Pair(2, 4), Pair(7, -4), Pair(2, 3),
        Pair(-2, 14), Pair(2, 8), Pair(-5, 12), Pair(2, 3), Pair(3, 5), Pair(3, 6), Pair(0, 7), Pair(15, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(97, -7), Pair(178, 9), Pair(-51, 41), Pair(77, 17), Pair(67, -21), Pair(67, -4), Pair(13, -11), Pair(-77, -110),
        Pair(-3, -11), Pair(-17, 37), Pair(-2, 27), Pair(62, 2), Pair(43, 9), Pair(7, 11), Pair(-46, 41), Pair(-104, 47),
        Pair(-12, 22), Pair(-6, 14), Pair(10, 9), Pair(18, 22), Pair(-6, 29), Pair(-16, 24), Pair(45, -8), Pair(9, -1),
        Pair(-21, 10), Pair(12, 12), Pair(-3, 23), Pair(32, 13), Pair(22, 7), Pair(23, 5), Pair(7, 1), Pair(15, 1),
        Pair(2, 22), Pair(17, 7), Pair(17, 18), Pair(18, 6), Pair(10, 22), Pair(14, 19), Pair(7, 0), Pair(0, 0),
        Pair(-9, 19), Pair(13, 10), Pair(1, 16), Pair(-12, 37), Pair(10, 32), Pair(7, 21), Pair(4, 12), Pair(-2, 43),
        Pair(-10, 63), Pair(-22, 20), Pair(0, 7), Pair(1, 25), Pair(-3, 22), Pair(-15, 43), Pair(-24, 13), Pair(-1, 9),
        Pair(11, 61), Pair(-9, -6), Pair(-25, 35), Pair(-52, 24), Pair(8, -1), Pair(0, 2), Pair(-3, 19), Pair(-24, -108)
      },
      { // Piece 2
        Pair(67, -6), Pair(-26, -8), Pair(-96, 5), Pair(-39, 3), Pair(77, -30), Pair(-123, 15), Pair(-96, -5), Pair(30, -2),
        Pair(13, -5), Pair(63, -14), Pair(0, -4), Pair(34, -22), Pair(-16, -23), Pair(-32, -12), Pair(-10, 20), Pair(-1, -23),
        Pair(24, -4), Pair(33, -5), Pair(38, -18), Pair(14, -16), Pair(32, 7), Pair(23, -13), Pair(60, -6), Pair(2, 4),
        Pair(-18, 13), Pair(9, -2), Pair(18, -5), Pair(27, 5), Pair(4, 14), Pair(39, -6), Pair(-22, 28), Pair(2, 1),
        Pair(6, 6), Pair(7, -8), Pair(20, -2), Pair(0, 9), Pair(20, 17), Pair(5, 4), Pair(-2, 12), Pair(0, 0),
        Pair(-14, -4), Pair(11, 10), Pair(3, 2), Pair(11, 6), Pair(5, 18), Pair(4, 15), Pair(18, 2), Pair(7, 11),
        Pair(18, -18), Pair(4, 9), Pair(14, 10), Pair(3, 11), Pair(4, 18), Pair(4, 16), Pair(8, 19), Pair(10, -13),
        Pair(-16, 0), Pair(-14, 4), Pair(2, 14), Pair(4, 25), Pair(11, 9), Pair(1, 11), Pair(58, -2), Pair(16, 25)
      },
      { // Piece 3
        Pair(-17, 28), Pair(4, 20), Pair(33, 6), Pair(24, 16), Pair(37, -1), Pair(70, -15), Pair(38, 8), Pair(86, -21),
        Pair(14, 28), Pair(12, 10), Pair(30, 10), Pair(26, 5), Pair(62, -6), Pair(40, 0), Pair(-25, 21), Pair(59, -16),
        Pair(-9, 32), Pair(29, 8), Pair(12, 20), Pair(18, 7), Pair(50, -5), Pair(60, 13), Pair(-14, 15), Pair(60, -17),
        Pair(-11, 21), Pair(24, 16), Pair(9, 17), Pair(29, 4), Pair(16, 11), Pair(28, 15), Pair(-25, 32), Pair(12, -10),
        Pair(-14, 23), Pair(-11, 16), Pair(9, 21), Pair(1, 20), Pair(21, 20), Pair(3, 17), Pair(-11, 22), Pair(0, 0),
        Pair(39, 6), Pair(-12, 15), Pair(26, 6), Pair(-16, 24), Pair(-5, 18), Pair(-7, 20), Pair(-4, 12), Pair(-60, 21),
        Pair(-6, 21), Pair(-15, 11), Pair(-3, 17), Pair(12, 7), Pair(-10, 22), Pair(-13, 22), Pair(-17, 23), Pair(-36, -24),
        Pair(1, 8), Pair(6, 6), Pair(4, 9), Pair(9, 8), Pair(8, 6), Pair(9, 9), Pair(-8, 26), Pair(-26, -15)
      },
      { // Piece 4
        Pair(7, -42), Pair(87, -42), Pair(-30, 4), Pair(-32, 47), Pair(71, -25), Pair(-49, 26), Pair(7, -3), Pair(1, -36),
        Pair(18, 1), Pair(-15, 10), Pair(30, -39), Pair(43, -84), Pair(35, -23), Pair(-24, 42), Pair(48, -81), Pair(39, -132),
        Pair(-5, -21), Pair(27, -25), Pair(6, 12), Pair(26, -15), Pair(8, 7), Pair(27, -44), Pair(51, -24), Pair(-12, -27),
        Pair(-6, 5), Pair(18, -31), Pair(-13, 41), Pair(-5, 23), Pair(-11, -9), Pair(6, 11), Pair(-16, 49), Pair(3, -14),
        Pair(11, 16), Pair(-3, 6), Pair(20, 16), Pair(-10, 10), Pair(-3, 22), Pair(-6, 40), Pair(8, 11), Pair(0, 0),
        Pair(18, -21), Pair(9, -7), Pair(-2, 26), Pair(1, 29), Pair(-7, 14), Pair(3, 21), Pair(11, -14), Pair(-8, 12),
        Pair(27, -44), Pair(6, -2), Pair(1, 11), Pair(4, 12), Pair(2, 13), Pair(0, 13), Pair(7, -10), Pair(-24, 6),
        Pair(-10, 37), Pair(-23, 30), Pair(-4, 10), Pair(0, 31), Pair(19, -15), Pair(39, -28), Pair(-84, 28), Pair(4, -113)
      },
      { // Piece 5
        Pair(-53, -22), Pair(-48, 54), Pair(-14, -1), Pair(-106, 31), Pair(-7, 17), Pair(-6, 15), Pair(-27, 108), Pair(11, -6),
        Pair(-49, 50), Pair(14, 40), Pair(-43, -8), Pair(-20, 19), Pair(28, 22), Pair(-101, 69), Pair(-123, 72), Pair(-29, 25),
        Pair(-4, 29), Pair(-24, -3), Pair(-86, 29), Pair(38, 22), Pair(57, 26), Pair(12, 35), Pair(-1, 38), Pair(-18, 11),
        Pair(-36, -1), Pair(7, 10), Pair(4, 17), Pair(5, 27), Pair(-69, 27), Pair(4, 18), Pair(-56, 21), Pair(-35, -11),
        Pair(44, -26), Pair(-48, 8), Pair(-9, 7), Pair(-65, 29), Pair(11, 14), Pair(23, 14), Pair(-34, -18), Pair(0, 0),
        Pair(-116, 25), Pair(-77, 28), Pair(-86, 25), Pair(-57, 21), Pair(-10, 11), Pair(2, 2), Pair(-32, -11), Pair(-63, -13),
        Pair(-61, 17), Pair(-54, 6), Pair(-21, 4), Pair(-30, 9), Pair(-23, 0), Pair(-21, 4), Pair(2, -9), Pair(-4, -19),
        Pair(-48, 11), Pair(-27, 4), Pair(-36, 7), Pair(-51, -1), Pair(-14, -4), Pair(-12, -1), Pair(15, -8), Pair(-8, -17)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(54, 11), Pair(-7, 14), Pair(11, 14), Pair(-20, 24), Pair(-23, 14), Pair(-43, 20), Pair(54, 0), Pair(8, 12),
        Pair(-21, 47), Pair(-12, 12), Pair(-11, 11), Pair(1, 3), Pair(4, 4), Pair(9, 5), Pair(-20, 6), Pair(5, 14),
        Pair(3, 17), Pair(-2, 13), Pair(1, 10), Pair(-1, 5), Pair(1, 10), Pair(2, 9), Pair(-2, 9), Pair(0, 9),
        Pair(0, 9), Pair(5, 7), Pair(1, 4), Pair(0, 7), Pair(2, 6), Pair(1, 9), Pair(-1, 9), Pair(-2, 11),
        Pair(-3, 1), Pair(-1, 1), Pair(-4, 6), Pair(2, 11), Pair(-1, 8), Pair(2, 7), Pair(-1, 12), Pair(-1, 14),
        Pair(4, 0), Pair(0, 12), Pair(-5, 6), Pair(1, 10), Pair(-4, 15), Pair(-2, 13), Pair(0, 15), Pair(1, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(30, -67), Pair(-113, -19), Pair(-43, 10), Pair(-14, 15), Pair(-82, 72), Pair(66, -6), Pair(38, 48), Pair(-50, -31),
        Pair(-21, -1), Pair(18, -21), Pair(-16, 20), Pair(0, 35), Pair(21, -8), Pair(12, 44), Pair(-64, 65), Pair(-33, 25),
        Pair(42, -33), Pair(10, 6), Pair(5, 27), Pair(-12, 32), Pair(19, 15), Pair(-60, 53), Pair(-25, 39), Pair(-29, 3),
        Pair(5, 8), Pair(11, 17), Pair(-4, 30), Pair(0, 39), Pair(-2, 35), Pair(5, 17), Pair(0, 25), Pair(-3, 32),
        Pair(-4, 16), Pair(6, 16), Pair(2, 35), Pair(5, 15), Pair(3, 24), Pair(10, 30), Pair(4, 11), Pair(4, 7),
        Pair(0, 0), Pair(-8, 44), Pair(3, 19), Pair(0, 26), Pair(6, 30), Pair(1, 23), Pair(-4, 32), Pair(-1, 13),
        Pair(-7, 60), Pair(25, 33), Pair(-2, 20), Pair(-2, 33), Pair(-1, 23), Pair(-8, 36), Pair(8, 25), Pair(-2, 7),
        Pair(78, -1), Pair(-7, 22), Pair(0, 2), Pair(5, 32), Pair(-17, 36), Pair(0, 11), Pair(-1, 18), Pair(55, -14)
      },
      { // Piece 2
        Pair(-41, 26), Pair(-27, 22), Pair(-139, 26), Pair(-43, 23), Pair(-42, 8), Pair(-18, -4), Pair(-72, 19), Pair(-28, 34),
        Pair(13, 8), Pair(13, 8), Pair(20, 11), Pair(24, -7), Pair(9, -20), Pair(-17, 11), Pair(-47, -9), Pair(-10, 15),
        Pair(-19, 10), Pair(8, 6), Pair(9, 27), Pair(53, -19), Pair(-2, 23), Pair(2, -23), Pair(-27, 19), Pair(-17, 22),
        Pair(-3, 21), Pair(8, 19), Pair(9, -5), Pair(-3, 18), Pair(4, 15), Pair(4, 7), Pair(8, 6), Pair(-9, 28),
        Pair(0, 8), Pair(27, 15), Pair(7, 10), Pair(16, -6), Pair(16, 17), Pair(-1, 12), Pair(13, 18), Pair(-10, 41),
        Pair(0, 0), Pair(-2, 25), Pair(9, 6), Pair(5, 19), Pair(7, 16), Pair(0, 28), Pair(2, 0), Pair(-1, 12),
        Pair(12, 25), Pair(8, 3), Pair(-1, 24), Pair(2, 10), Pair(3, 30), Pair(7, 1), Pair(5, 22), Pair(8, 25),
        Pair(1, 27), Pair(-24, 36), Pair(-2, 9), Pair(7, 21), Pair(-3, 5), Pair(-5, 25), Pair(-13, 22), Pair(3, 23)
      },
      { // Piece 3
        Pair(3, 10), Pair(7, 23), Pair(-9, 26), Pair(3, 21), Pair(-79, 71), Pair(53, 9), Pair(16, 50), Pair(-44, 51),
        Pair(-31, 11), Pair(-15, 42), Pair(9, 28), Pair(-20, 32), Pair(-3, 27), Pair(19, 24), Pair(-2, 16), Pair(34, 18),
        Pair(-28, 28), Pair(13, 20), Pair(-20, 47), Pair(7, 14), Pair(-16, 35), Pair(11, 36), Pair(-30, 34), Pair(22, 26),
        Pair(-48, 33), Pair(-1, 42), Pair(0, 36), Pair(-17, 47), Pair(6, 21), Pair(-8, 57), Pair(4, 46), Pair(25, 11),
        Pair(-22, 26), Pair(27, 17), Pair(-17, 47), Pair(10, 30), Pair(3, 39), Pair(2, 32), Pair(-24, 64), Pair(28, 18),
        Pair(0, 0), Pair(2, 22), Pair(8, 27), Pair(18, 23), Pair(-2, 24), Pair(2, 42), Pair(9, 24), Pair(26, 8),
        Pair(-54, 28), Pair(3, 5), Pair(-3, 37), Pair(5, 23), Pair(1, 31), Pair(-3, 32), Pair(2, 47), Pair(27, 33),
        Pair(-20, -3), Pair(-3, 32), Pair(0, 29), Pair(2, 25), Pair(0, 28), Pair(1, 18), Pair(9, 13), Pair(9, 14)
      },
      { // Piece 4
        Pair(90, -36), Pair(-17, 43), Pair(-45, 66), Pair(-19, 43), Pair(-32, 54), Pair(-19, 16), Pair(-106, 145), Pair(-64, 45),
        Pair(-44, 61), Pair(-6, 26), Pair(11, 15), Pair(-17, 94), Pair(21, 18), Pair(17, 35), Pair(26, 0), Pair(3, -16),
        Pair(-64, 107), Pair(11, 24), Pair(-4, 38), Pair(2, 45), Pair(-4, 51), Pair(-22, 59), Pair(-8, 45), Pair(-35, 55),
        Pair(10, 26), Pair(-16, 50), Pair(-4, 44), Pair(23, 1), Pair(8, 17), Pair(8, 15), Pair(-17, 62), Pair(6, 23),
        Pair(-14, 19), Pair(13, 45), Pair(-8, 35), Pair(6, 38), Pair(5, 33), Pair(-2, 55), Pair(-4, 26), Pair(1, 49),
        Pair(0, 0), Pair(15, 20), Pair(8, 44), Pair(9, 23), Pair(3, 60), Pair(3, 49), Pair(6, 47), Pair(24, -39),
        Pair(-19, 86), Pair(11, 32), Pair(9, 36), Pair(6, 36), Pair(0, 42), Pair(16, 34), Pair(3, -11), Pair(30, -47),
        Pair(-18, 72), Pair(-26, 73), Pair(-5, 59), Pair(2, 56), Pair(4, 33), Pair(18, 28), Pair(-15, 44), Pair(27, -45)
      },
      { // Piece 5
        Pair(-5, 77), Pair(73, 21), Pair(61, 98), Pair(-1, -36), Pair(10, 81), Pair(-33, 14), Pair(4, 24), Pair(-93, -101),
        Pair(-79, -2), Pair(-76, 46), Pair(102, 26), Pair(-10, 38), Pair(36, -14), Pair(0, -41), Pair(-54, -5), Pair(-38, 3),
        Pair(-56, 27), Pair(24, 22), Pair(27, 30), Pair(-31, 73), Pair(-180, 29), Pair(87, -12), Pair(-14, 11), Pair(-13, -18),
        Pair(41, -14), Pair(60, 26), Pair(-41, 29), Pair(-41, 31), Pair(-71, 45), Pair(-13, 9), Pair(-4, -11), Pair(13, 11),
        Pair(-32, 8), Pair(-110, 22), Pair(-68, 42), Pair(-34, 28), Pair(-94, 27), Pair(-1, 1), Pair(-20, 1), Pair(-21, -8),
        Pair(0, 0), Pair(22, 9), Pair(19, 8), Pair(-28, 22), Pair(-29, 8), Pair(-7, 7), Pair(-5, -4), Pair(-59, 0),
        Pair(43, -51), Pair(16, -1), Pair(-6, 1), Pair(8, 6), Pair(-10, 0), Pair(-17, 12), Pair(-17, 1), Pair(-22, 1),
        Pair(48, -34), Pair(64, -8), Pair(50, -13), Pair(2, -19), Pair(1, -7), Pair(-6, -5), Pair(-7, -5), Pair(-7, -19)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 11), Pair(-38, 24), Pair(-45, 13), Pair(9, 2), Pair(-56, 40), Pair(-15, 0), Pair(36, 15), Pair(8, -7),
        Pair(-8, 13), Pair(16, 7), Pair(-13, 11), Pair(-5, 6), Pair(1, 6), Pair(0, 14), Pair(-10, 1), Pair(0, 0),
        Pair(-5, 10), Pair(4, 12), Pair(0, 7), Pair(1, 8), Pair(4, 1), Pair(-2, 7), Pair(1, 9), Pair(0, 9),
        Pair(2, 2), Pair(-6, -2), Pair(4, 6), Pair(6, 4), Pair(2, 6), Pair(6, 9), Pair(2, 11), Pair(0, 8),
        Pair(-1, 1), Pair(-5, 1), Pair(-4, 10), Pair(-1, 8), Pair(2, 10), Pair(4, 9), Pair(3, 13), Pair(1, 9),
        Pair(3, 12), Pair(-3, -4), Pair(7, 16), Pair(-3, 13), Pair(1, 7), Pair(-1, 12), Pair(4, 15), Pair(1, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-99, 46), Pair(15, 46), Pair(-35, 104), Pair(-82, 67), Pair(18, -33), Pair(-25, 25), Pair(-139, 68), Pair(-37, 73),
        Pair(1, 38), Pair(-3, 19), Pair(-19, 15), Pair(-66, 55), Pair(-9, 33), Pair(-3, 41), Pair(-37, 56), Pair(23, 43),
        Pair(-14, 16), Pair(11, 19), Pair(-6, 33), Pair(0, 30), Pair(-25, 44), Pair(-42, 39), Pair(-17, 26), Pair(-39, 63),
        Pair(-30, 33), Pair(2, 15), Pair(8, 25), Pair(-2, 30), Pair(0, 35), Pair(-4, 28), Pair(-9, 35), Pair(1, 25),
        Pair(-3, 20), Pair(3, 25), Pair(-6, 6), Pair(-2, 37), Pair(-13, 37), Pair(5, 34), Pair(-8, 39), Pair(-5, 31),
        Pair(-4, 18), Pair(0, 0), Pair(0, 30), Pair(6, 26), Pair(-5, 35), Pair(0, 29), Pair(-4, 35), Pair(10, 37),
        Pair(2, 11), Pair(16, 45), Pair(0, 40), Pair(-7, 36), Pair(2, 44), Pair(3, 48), Pair(3, 50), Pair(6, 19),
        Pair(-8, -25), Pair(-4, 18), Pair(-6, 25), Pair(4, 37), Pair(-2, 35), Pair(-10, 44), Pair(2, 27), Pair(-22, -22)
      },
      { // Piece 2
        Pair(59, 18), Pair(-141, 46), Pair(-67, 23), Pair(50, 6), Pair(44, -10), Pair(-30, 23), Pair(-21, -25), Pair(-38, -65),
        Pair(-7, 39), Pair(-11, 10), Pair(17, 23), Pair(23, -8), Pair(54, -16), Pair(-41, 23), Pair(-4, 14), Pair(6, -22),
        Pair(-30, 11), Pair(2, 20), Pair(24, -7), Pair(16, 27), Pair(-6, 3), Pair(-8, 16), Pair(8, -12), Pair(-20, 16),
        Pair(-10, 7), Pair(-4, -1), Pair(-4, 19), Pair(14, 2), Pair(10, 10), Pair(2, -2), Pair(5, -2), Pair(-4, 22),
        Pair(-58, -27), Pair(11, 30), Pair(2, 18), Pair(11, 13), Pair(-3, 17), Pair(1, 24), Pair(15, 7), Pair(19, 23),
        Pair(4, 10), Pair(0, 0), Pair(8, 20), Pair(-1, 11), Pair(5, 30), Pair(1, 17), Pair(1, 37), Pair(4, 14),
        Pair(-78, 13), Pair(9, 30), Pair(-7, 11), Pair(4, 32), Pair(-3, 20), Pair(19, 13), Pair(-2, 17), Pair(-9, 43),
        Pair(13, -29), Pair(5, 0), Pair(-1, 18), Pair(6, 9), Pair(-8, 36), Pair(-2, 28), Pair(-17, 43), Pair(29, -7)
      },
      { // Piece 3
        Pair(38, 16), Pair(-36, 47), Pair(-56, 56), Pair(19, 19), Pair(18, 32), Pair(-7, 57), Pair(11, 35), Pair(43, -2),
        Pair(-25, 32), Pair(-22, 27), Pair(-13, 34), Pair(30, 13), Pair(31, 22), Pair(-61, 72), Pair(-11, 30), Pair(68, 1),
        Pair(-8, 29), Pair(-48, 47), Pair(7, 29), Pair(-16, 50), Pair(-10, 46), Pair(-25, 37), Pair(-32, 23), Pair(22, 25),
        Pair(3, 30), Pair(-4, 39), Pair(-13, 39), Pair(5, 32), Pair(4, 39), Pair(4, 31), Pair(21, 24), Pair(-21, 58),
        Pair(-14, 43), Pair(-3, 23), Pair(-14, 56), Pair(-9, 53), Pair(-15, 45), Pair(-7, 38), Pair(-13, 50), Pair(-1, 26),
        Pair(-1, -2), Pair(0, 0), Pair(-6, 36), Pair(2, 38), Pair(4, 38), Pair(-8, 37), Pair(8, 23), Pair(-3, 24),
        Pair(1, 7), Pair(-14, -3), Pair(-3, 37), Pair(12, 26), Pair(3, 29), Pair(-20, 52), Pair(-8, 60), Pair(3, 34),
        Pair(-5, 27), Pair(-13, 4), Pair(-7, 34), Pair(-2, 31), Pair(-2, 31), Pair(-3, 32), Pair(-1, 44), Pair(8, 21)
      },
      { // Piece 4
        Pair(-47, 57), Pair(-65, 66), Pair(-12, 43), Pair(-65, 53), Pair(-49, 66), Pair(-53, 40), Pair(-86, 92), Pair(-16, 35),
        Pair(-3, -13), Pair(-20, 19), Pair(9, 11), Pair(3, 53), Pair(-26, 32), Pair(-31, 49), Pair(19, 67), Pair(-42, 100),
        Pair(-11, 42), Pair(-37, 57), Pair(9, -2), Pair(-1, 54), Pair(-36, 49), Pair(-31, 75), Pair(-28, 46), Pair(21, -5),
        Pair(-14, 40), Pair(9, -10), Pair(-3, 48), Pair(-27, 64), Pair(-18, 42), Pair(-18, 43), Pair(-15, 53), Pair(-21, 59),
        Pair(-19, 46), Pair(-21, 50), Pair(8, 24), Pair(-6, 36), Pair(-18, 59), Pair(-18, 54), Pair(-18, 34), Pair(-9, 37),
        Pair(-11, -25), Pair(0, 0), Pair(5, 28), Pair(-6, 58), Pair(15, 35), Pair(6, 52), Pair(-3, 41), Pair(3, 39),
        Pair(11, 16), Pair(-6, 36), Pair(9, 26), Pair(4, 38), Pair(10, 36), Pair(8, 28), Pair(3, 42), Pair(-18, 42),
        Pair(3, 1), Pair(18, -27), Pair(-2, 56), Pair(1, 36), Pair(-9, 84), Pair(14, 6), Pair(-4, 55), Pair(45, -5)
      },
      { // Piece 5
        Pair(46, 36), Pair(23, 67), Pair(17, 34), Pair(-12, -55), Pair(1, -54), Pair(31, 108), Pair(-71, -81), Pair(-6, 64),
        Pair(64, -18), Pair(27, 51), Pair(-36, 36), Pair(124, -18), Pair(41, 35), Pair(-25, -33), Pair(6, -12), Pair(-99, 43),
        Pair(-110, 72), Pair(92, 30), Pair(-6, 49), Pair(106, 1), Pair(-60, 24), Pair(-15, -18), Pair(100, 2), Pair(-108, 5),
        Pair(55, 52), Pair(28, 19), Pair(31, 31), Pair(67, 28), Pair(-122, 61), Pair(-62, 11), Pair(28, 5), Pair(-63, 21),
        Pair(42, 40), Pair(39, 12), Pair(6, 8), Pair(-23, 23), Pair(-60, 38), Pair(-63, 20), Pair(38, -5), Pair(-59, 3),
        Pair(-28, 30), Pair(0, 0), Pair(-5, 17), Pair(-11, 16), Pair(-13, 15), Pair(-4, -1), Pair(-24, 9), Pair(-43, 12),
        Pair(42, -12), Pair(42, -1), Pair(-35, 22), Pair(-9, 16), Pair(9, 3), Pair(-24, 10), Pair(-15, 1), Pair(-5, -6),
        Pair(45, -36), Pair(50, -5), Pair(42, -7), Pair(-14, 4), Pair(-3, -2), Pair(-8, 0), Pair(-5, -4), Pair(-2, -17)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, -11), Pair(-57, -1), Pair(-63, 39), Pair(26, -9), Pair(2, -3), Pair(-59, -5), Pair(13, 8), Pair(39, 3),
        Pair(-2, 4), Pair(16, 8), Pair(-17, 0), Pair(3, -2), Pair(11, 7), Pair(-11, 5), Pair(21, -3), Pair(2, 11),
        Pair(-2, 10), Pair(-4, 6), Pair(-2, 4), Pair(-4, 10), Pair(5, 5), Pair(8, 4), Pair(1, 6), Pair(0, 3),
        Pair(0, 7), Pair(4, 11), Pair(-9, -13), Pair(9, 12), Pair(2, 5), Pair(3, 3), Pair(1, 9), Pair(-3, 9),
        Pair(-4, 5), Pair(-3, 11), Pair(-4, -6), Pair(1, 19), Pair(-7, 5), Pair(4, 8), Pair(1, 10), Pair(0, 9),
        Pair(-2, 6), Pair(6, 22), Pair(-9, -14), Pair(4, 24), Pair(-8, 15), Pair(-2, 5), Pair(1, 11), Pair(0, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, -28), Pair(-165, 91), Pair(-39, 0), Pair(-73, 38), Pair(-13, 66), Pair(-32, 31), Pair(-31, -15), Pair(45, -22),
        Pair(-18, 8), Pair(-4, 11), Pair(23, -15), Pair(14, 36), Pair(9, 21), Pair(63, 6), Pair(-33, 39), Pair(-44, 47),
        Pair(1, 39), Pair(-8, 23), Pair(-16, 44), Pair(14, 11), Pair(-18, 12), Pair(-23, 61), Pair(1, 21), Pair(11, -3),
        Pair(-2, 50), Pair(2, 11), Pair(2, 28), Pair(25, 35), Pair(3, 17), Pair(8, 31), Pair(-3, 27), Pair(15, 22),
        Pair(-16, -5), Pair(1, 16), Pair(5, 14), Pair(8, 20), Pair(2, 25), Pair(8, 39), Pair(-3, 39), Pair(10, 12),
        Pair(-3, 30), Pair(1, 26), Pair(0, 0), Pair(8, 25), Pair(14, 30), Pair(7, 33), Pair(14, 2), Pair(3, 24),
        Pair(-29, -20), Pair(0, -3), Pair(6, 41), Pair(8, 36), Pair(-3, 28), Pair(3, 33), Pair(6, 42), Pair(3, 38),
        Pair(95, 36), Pair(-1, 3), Pair(11, 21), Pair(1, 25), Pair(0, 21), Pair(-2, 30), Pair(0, 46), Pair(24, 49)
      },
      { // Piece 2
        Pair(-32, 58), Pair(88, -32), Pair(95, 21), Pair(54, -17), Pair(43, -4), Pair(50, -77), Pair(88, -7), Pair(-38, -56),
        Pair(-37, 22), Pair(14, -23), Pair(29, -1), Pair(12, -18), Pair(-31, 12), Pair(-3, -17), Pair(-28, 9), Pair(30, -9),
        Pair(4, 6), Pair(45, -20), Pair(27, 11), Pair(28, -25), Pair(8, -3), Pair(-20, -9), Pair(41, -23), Pair(-15, 8),
        Pair(-4, 9), Pair(4, 7), Pair(-12, 13), Pair(25, 2), Pair(4, -9), Pair(27, -8), Pair(-8, 5), Pair(7, 29),
        Pair(24, 4), Pair(8, 6), Pair(4, 17), Pair(22, 10), Pair(7, 9), Pair(8, 4), Pair(15, 25), Pair(8, -5),
        Pair(0, -20), Pair(16, 1), Pair(0, 0), Pair(12, 20), Pair(6, 2), Pair(17, 8), Pair(8, 9), Pair(12, 24),
        Pair(27, -25), Pair(-17, -37), Pair(16, 44), Pair(-4, 3), Pair(9, 27), Pair(4, -3), Pair(11, 31), Pair(8, 8),
        Pair(-26, -68), Pair(18, -1), Pair(-2, -2), Pair(-11, 17), Pair(-2, -22), Pair(7, 30), Pair(-5, 25), Pair(13, 35)
      },
      { // Piece 3
        Pair(-27, 47), Pair(-14, 36), Pair(-74, 43), Pair(-42, 38), Pair(7, 21), Pair(28, 1), Pair(44, 0), Pair(-6, 29),
        Pair(-5, 29), Pair(-7, 37), Pair(-27, 26), Pair(-4, 13), Pair(-6, 28), Pair(-23, 48), Pair(3, 20), Pair(-24, 36),
        Pair(-21, 43), Pair(-20, 46), Pair(10, 20), Pair(3, 14), Pair(-14, 32), Pair(10, 23), Pair(-29, 27), Pair(22, 20),
        Pair(4, 39), Pair(13, 19), Pair(-16, 27), Pair(-25, 33), Pair(4, 23), Pair(-3, 47), Pair(31, -3), Pair(-19, 41),
        Pair(-2, 23), Pair(8, 14), Pair(-40, 20), Pair(21, 36), Pair(-4, 38), Pair(-13, 34), Pair(1, 12), Pair(-12, 40),
        Pair(14, 0), Pair(-13, 6), Pair(0, 0), Pair(15, 19), Pair(10, 12), Pair(14, 14), Pair(-16, 26), Pair(7, 14),
        Pair(2, 27), Pair(-18, 22), Pair(-5, 14), Pair(-10, 34), Pair(2, 20), Pair(4, 21), Pair(-8, 33), Pair(-22, 36),
        Pair(1, 27), Pair(3, 17), Pair(-1, -11), Pair(1, 21), Pair(0, 28), Pair(2, 19), Pair(-1, 28), Pair(3, 22)
      },
      { // Piece 4
        Pair(-13, 29), Pair(-62, 126), Pair(-71, 55), Pair(-90, 101), Pair(-22, 19), Pair(30, -19), Pair(-1, 70), Pair(79, -29),
        Pair(-12, 17), Pair(6, -4), Pair(-23, 40), Pair(19, 11), Pair(8, 40), Pair(52, -35), Pair(11, -95), Pair(-7, -33),
        Pair(4, 3), Pair(-9, 48), Pair(-16, 67), Pair(-27, 59), Pair(-42, 72), Pair(-4, 83), Pair(5, 23), Pair(-9, 63),
        Pair(3, 1), Pair(9, 3), Pair(13, -9), Pair(-14, 69), Pair(-18, 26), Pair(-8, 25), Pair(-7, 33), Pair(-14, 55),
        Pair(-6, 33), Pair(15, -20), Pair(-2, 34), Pair(2, 40), Pair(-11, 50), Pair(4, 33), Pair(-6, 62), Pair(-4, 22),
        Pair(-10, 11), Pair(3, -7), Pair(0, 0), Pair(6, 20), Pair(8, 31), Pair(9, 32), Pair(15, 7), Pair(-14, 112),
        Pair(11, 43), Pair(-8, 20), Pair(-5, 32), Pair(8, 27), Pair(3, 49), Pair(14, 8), Pair(-11, 31), Pair(-17, 65),
        Pair(16, -19), Pair(-2, 31), Pair(-3, 28), Pair(1, 40), Pair(5, 16), Pair(-2, 53), Pair(-7, -7), Pair(18, 53)
      },
      { // Piece 5
        Pair(-28, -59), Pair(24, 91), Pair(-45, 31), Pair(-84, 29), Pair(29, 65), Pair(2, -3), Pair(-30, -99), Pair(0, -83),
        Pair(39, -68), Pair(18, 60), Pair(94, 51), Pair(-2, 175), Pair(19, 97), Pair(1, 8), Pair(39, 18), Pair(7, -71),
        Pair(-113, 121), Pair(37, 40), Pair(-80, 93), Pair(-1, 10), Pair(72, -6), Pair(19, 28), Pair(80, -35), Pair(21, -48),
        Pair(19, -25), Pair(-117, 57), Pair(-58, 43), Pair(-86, 37), Pair(71, 14), Pair(-106, 29), Pair(-7, -10), Pair(-42, -14),
        Pair(50, 28), Pair(-39, -6), Pair(1, 4), Pair(-37, 6), Pair(-20, 19), Pair(-54, 17), Pair(-10, -1), Pair(-102, 31),
        Pair(33, 21), Pair(30, 2), Pair(0, 0), Pair(-32, 18), Pair(-2, 5), Pair(-19, 2), Pair(2, 6), Pair(8, -7),
        Pair(30, -4), Pair(1, 12), Pair(-27, 6), Pair(-15, 7), Pair(-11, 2), Pair(-8, 1), Pair(-8, -8), Pair(-2, -10),
        Pair(43, -28), Pair(-12, -12), Pair(-15, -13), Pair(-16, 12), Pair(7, -11), Pair(-5, -13), Pair(-1, -15), Pair(-5, -14)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 6), Pair(-16, 4), Pair(26, -3), Pair(-85, 43), Pair(41, 4), Pair(32, -24), Pair(46, -24), Pair(22, -9),
        Pair(-9, 15), Pair(5, -2), Pair(0, 8), Pair(-5, -2), Pair(3, 7), Pair(-2, 4), Pair(2, 4), Pair(-7, -2),
        Pair(1, 5), Pair(6, 11), Pair(-2, 16), Pair(8, 11), Pair(3, 10), Pair(0, 11), Pair(-5, 9), Pair(-7, 9),
        Pair(-1, 10), Pair(-1, 7), Pair(4, 11), Pair(2, -1), Pair(8, 10), Pair(5, 5), Pair(1, 8), Pair(-3, 8),
        Pair(0, 9), Pair(-1, 7), Pair(0, 19), Pair(1, -13), Pair(1, 20), Pair(-7, 5), Pair(2, 10), Pair(0, 7),
        Pair(-2, 10), Pair(-2, 0), Pair(6, 26), Pair(-4, -1), Pair(8, 32), Pair(-6, 11), Pair(0, 6), Pair(0, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(12, -73), Pair(71, 29), Pair(-83, 85), Pair(-105, 43), Pair(38, -9), Pair(-112, 14), Pair(-43, 110), Pair(-23, 5),
        Pair(-11, -10), Pair(-13, 42), Pair(4, 16), Pair(-50, 77), Pair(-26, 33), Pair(-70, 62), Pair(-57, 90), Pair(6, -39),
        Pair(-60, 67), Pair(9, 11), Pair(0, 15), Pair(-34, 45), Pair(-28, 33), Pair(-13, -2), Pair(-6, 55), Pair(-19, 51),
        Pair(4, 11), Pair(-3, 36), Pair(1, 10), Pair(-26, 41), Pair(-5, 45), Pair(-8, 37), Pair(-16, 43), Pair(-15, 31),
        Pair(6, 8), Pair(-28, 52), Pair(-6, 14), Pair(-3, 24), Pair(13, 36), Pair(-2, 33), Pair(-18, 38), Pair(6, 16),
        Pair(-4, 9), Pair(-1, 15), Pair(-1, 28), Pair(0, 0), Pair(0, 25), Pair(4, 37), Pair(-14, 48), Pair(3, 14),
        Pair(3, 37), Pair(-13, -11), Pair(3, 28), Pair(7, 47), Pair(6, 40), Pair(-10, 11), Pair(0, 19), Pair(4, 8),
        Pair(10, 37), Pair(-4, 18), Pair(15, 6), Pair(13, 12), Pair(-12, -6), Pair(-13, 59), Pair(1, 37), Pair(-69, 160)
      },
      { // Piece 2
        Pair(-68, 17), Pair(151, 15), Pair(-19, 35), Pair(-90, -4), Pair(4, -24), Pair(-114, 2), Pair(4, -69), Pair(-17, -14),
        Pair(9, 17), Pair(-20, 22), Pair(30, 1), Pair(-13, -2), Pair(26, -29), Pair(-16, 5), Pair(-45, 54), Pair(90, -66),
        Pair(34, -27), Pair(23, -13), Pair(1, -6), Pair(23, 8), Pair(-28, 19), Pair(-29, 16), Pair(-12, -6), Pair(-18, 43),
        Pair(11, 5), Pair(-39, 18), Pair(20, 9), Pair(-7, 4), Pair(1, 26), Pair(-18, 6), Pair(2, -2), Pair(-21, -9),
        Pair(15, -8), Pair(16, 14), Pair(-4, 16), Pair(3, 4), Pair(20, 11), Pair(3, 10), Pair(11, 3), Pair(6, -17),
        Pair(8, 10), Pair(-7, -2), Pair(12, 14), Pair(0, 0), Pair(2, 37), Pair(4, -2), Pair(-9, 21), Pair(4, -6),
        Pair(0, 76), Pair(0, 23), Pair(-19, -33), Pair(12, 33), Pair(-5, -13), Pair(14, -5), Pair(3, 6), Pair(6, 24),
        Pair(17, -3), Pair(-34, -45), Pair(3, 22), Pair(5, -21), Pair(11, 37), Pair(-13, -18), Pair(30, -11), Pair(26, -13)
      },
      { // Piece 3
        Pair(2, 25), Pair(13, 8), Pair(-62, 49), Pair(-5, 29), Pair(40, 14), Pair(45, 11), Pair(-51, 29), Pair(-8, 30),
        Pair(-17, 39), Pair(2, 38), Pair(-19, 27), Pair(-30, 27), Pair(-13, 46), Pair(25, -4), Pair(17, 15), Pair(7, 2),
        Pair(9, 33), Pair(-18, 38), Pair(5, 14), Pair(3, 22), Pair(-12, 25), Pair(-9, 19), Pair(-22, 37), Pair(11, 26),
        Pair(-4, 26), Pair(-5, 55), Pair(-19, 26), Pair(46, -4), Pair(-23, 37), Pair(8, 17), Pair(-5, 24), Pair(17, -8),
        Pair(3, 13), Pair(-20, 43), Pair(-11, 44), Pair(2, 20), Pair(7, 26), Pair(-6, 40), Pair(-12, 43), Pair(-17, 33),
        Pair(12, 8), Pair(-28, 34), Pair(-22, 35), Pair(0, 0), Pair(-1, 21), Pair(1, 6), Pair(-12, 19), Pair(20, 14),
        Pair(-1, 24), Pair(3, 16), Pair(5, 6), Pair(-28, 23), Pair(-11, 20), Pair(-8, 20), Pair(-22, 17), Pair(28, -6),
        Pair(-2, 17), Pair(0, 28), Pair(-13, 35), Pair(6, -18), Pair(-5, 21), Pair(0, 21), Pair(2, 28), Pair(6, 12)
      },
      { // Piece 4
        Pair(-64, 35), Pair(6, 60), Pair(19, 25), Pair(-73, 82), Pair(-16, 34), Pair(12, 20), Pair(76, -18), Pair(45, -90),
        Pair(-4, -14), Pair(-12, 27), Pair(-1, 13), Pair(25, -13), Pair(-24, 93), Pair(-47, 40), Pair(-26, -8), Pair(-19, -10),
        Pair(-14, 26), Pair(-24, 48), Pair(-6, 80), Pair(-18, 53), Pair(-14, 61), Pair(-18, 37), Pair(-37, 29), Pair(-11, 33),
        Pair(-20, 23), Pair(1, 14), Pair(16, -3), Pair(8, 8), Pair(-20, 4), Pair(16, -34), Pair(2, 17), Pair(7, 32),
        Pair(-8, 29), Pair(17, -5), Pair(-13, 27), Pair(-19, 38), Pair(8, 53), Pair(-8, 41), Pair(-12, 54), Pair(-5, 30),
        Pair(-21, 36), Pair(1, 0), Pair(-12, 29), Pair(0, 0), Pair(-8, 23), Pair(-1, 22), Pair(-5, 27), Pair(-24, 78),
        Pair(5, -7), Pair(7, -11), Pair(1, 6), Pair(8, 3), Pair(-2, 31), Pair(8, 33), Pair(-19, 97), Pair(38, -29),
        Pair(16, -23), Pair(2, 8), Pair(7, -1), Pair(0, 10), Pair(-8, 64), Pair(12, 5), Pair(30, 7), Pair(24, 60)
      },
      { // Piece 5
        Pair(-7, -13), Pair(27, 124), Pair(5, -11), Pair(26, 56), Pair(15, -41), Pair(12, -8), Pair(-1, -67), Pair(3, 2),
        Pair(-8, 60), Pair(-99, -1), Pair(41, 42), Pair(-23, 129), Pair(-48, 6), Pair(44, 118), Pair(73, 2), Pair(-81, -52),
        Pair(-58, 46), Pair(58, 43), Pair(14, 29), Pair(46, 33), Pair(56, 56), Pair(97, 13), Pair(-86, 4), Pair(7, -11),
        Pair(-87, 38), Pair(81, -11), Pair(-91, 49), Pair(68, 9), Pair(54, 7), Pair(-32, 0), Pair(-144, 33), Pair(-28, 31),
        Pair(127, -9), Pair(-30, 33), Pair(21, -16), Pair(27, -2), Pair(-14, -15), Pair(23, -17), Pair(-54, 20), Pair(26, -5),
        Pair(-11, -29), Pair(94, 2), Pair(-29, 22), Pair(0, 0), Pair(-51, 23), Pair(-16, -3), Pair(4, -14), Pair(-5, -9),
        Pair(3, 0), Pair(15, 0), Pair(-35, 3), Pair(-71, 19), Pair(-34, -1), Pair(-5, -15), Pair(8, -18), Pair(3, -11),
        Pair(24, -54), Pair(-17, -4), Pair(-30, -6), Pair(-67, 0), Pair(-8, -21), Pair(3, -12), Pair(0, -18), Pair(4, -23)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(15, 5), Pair(-9, 8), Pair(20, 3), Pair(-15, 22), Pair(-24, -9), Pair(-26, -7), Pair(0, 28), Pair(12, -4),
        Pair(0, 6), Pair(6, 6), Pair(-3, 10), Pair(6, 7), Pair(0, 10), Pair(-18, 9), Pair(-18, 16), Pair(-4, -3),
        Pair(2, 9), Pair(0, 8), Pair(2, 9), Pair(0, 14), Pair(3, 8), Pair(5, 9), Pair(7, 10), Pair(7, -2),
        Pair(0, 15), Pair(1, 9), Pair(-2, 11), Pair(10, 17), Pair(0, -3), Pair(15, 3), Pair(4, 9), Pair(1, 4),
        Pair(0, 8), Pair(3, 11), Pair(-7, 5), Pair(0, 22), Pair(-1, -10), Pair(10, 9), Pair(0, 3), Pair(7, 7),
        Pair(-1, 13), Pair(-1, 9), Pair(-2, 8), Pair(10, 28), Pair(-1, -9), Pair(16, 24), Pair(5, 6), Pair(7, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(65, 74), Pair(65, -20), Pair(-20, 19), Pair(9, 32), Pair(2, 27), Pair(-17, -9), Pair(111, -91), Pair(148, 17),
        Pair(49, 3), Pair(-11, 33), Pair(-3, 19), Pair(21, 20), Pair(52, 8), Pair(-56, 25), Pair(-60, 46), Pair(-8, -38),
        Pair(-32, 24), Pair(-7, 48), Pair(14, 22), Pair(-19, 39), Pair(-39, 49), Pair(-5, 8), Pair(-34, 35), Pair(17, -1),
        Pair(1, 26), Pair(5, 24), Pair(-9, 36), Pair(-5, 35), Pair(-13, 30), Pair(-10, 33), Pair(-8, 13), Pair(-4, 40),
        Pair(4, 34), Pair(21, 8), Pair(6, 17), Pair(12, 25), Pair(-5, 22), Pair(4, 23), Pair(-17, 13), Pair(4, -5),
        Pair(5, -23), Pair(6, 28), Pair(5, 31), Pair(4, 29), Pair(0, 0), Pair(-1, 29), Pair(1, 24), Pair(7, 21),
        Pair(17, 26), Pair(7, 31), Pair(-5, 5), Pair(10, 21), Pair(8, 47), Pair(12, 19), Pair(1, -4), Pair(-10, 31),
        Pair(65, -32), Pair(5, 33), Pair(4, 38), Pair(-2, 11), Pair(-5, 23), Pair(-12, 29), Pair(4, -25), Pair(-1, 40)
      },
      { // Piece 2
        Pair(-38, 34), Pair(58, -40), Pair(50, -10), Pair(40, -23), Pair(-5, 11), Pair(-24, 24), Pair(10, -27), Pair(-4, -14),
        Pair(-6, -33), Pair(4, 4), Pair(-13, -28), Pair(35, 7), Pair(-9, -5), Pair(-15, 11), Pair(-27, -9), Pair(0, 6),
        Pair(8, 10), Pair(-3, -8), Pair(8, 11), Pair(-5, 3), Pair(-2, 16), Pair(-30, -5), Pair(20, 6), Pair(-53, 9),
        Pair(10, -12), Pair(0, 19), Pair(-21, 4), Pair(0, 6), Pair(-15, -3), Pair(10, 21), Pair(-20, -11), Pair(-4, 12),
        Pair(21, -6), Pair(-6, 2), Pair(2, 14), Pair(18, 5), Pair(6, 20), Pair(-20, -9), Pair(10, 10), Pair(-14, 0),
        Pair(-20, 5), Pair(7, 18), Pair(-10, 14), Pair(0, 24), Pair(0, 0), Pair(12, 10), Pair(-15, 11), Pair(8, 14),
        Pair(21, 0), Pair(-14, 12), Pair(4, 17), Pair(-21, -8), Pair(12, 27), Pair(-21, -26), Pair(-1, 29), Pair(-19, 26),
        Pair(-10, 26), Pair(4, 0), Pair(-26, -13), Pair(1, 17), Pair(-10, -1), Pair(-3, 12), Pair(-28, -52), Pair(17, 17)
      },
      { // Piece 3
        Pair(14, 24), Pair(4, 27), Pair(-41, 42), Pair(-17, 23), Pair(21, 2), Pair(25, 16), Pair(65, 8), Pair(-32, 35),
        Pair(9, 19), Pair(-6, 37), Pair(-27, 36), Pair(-12, 26), Pair(27, 11), Pair(-30, 25), Pair(3, 11), Pair(13, 26),
        Pair(1, 23), Pair(19, 6), Pair(-19, 31), Pair(-1, 24), Pair(3, 7), Pair(-28, 24), Pair(20, 25), Pair(6, 13),
        Pair(12, 15), Pair(7, 21), Pair(13, 18), Pair(-1, 14), Pair(50, 5), Pair(20, 9), Pair(30, 13), Pair(6, 9),
        Pair(5, 17), Pair(3, 17), Pair(-12, 26), Pair(24, 14), Pair(-10, 5), Pair(-6, 20), Pair(-39, 14), Pair(19, 22),
        Pair(0, 13), Pair(-2, 24), Pair(-12, 14), Pair(-21, 22), Pair(0, 0), Pair(-11, 12), Pair(-11, -4), Pair(8, -10),
        Pair(0, 18), Pair(-7, 23), Pair(5, 23), Pair(0, 20), Pair(4, -21), Pair(10, -3), Pair(-1, 11), Pair(-3, 21),
        Pair(0, 21), Pair(3, 17), Pair(3, 12), Pair(-4, 18), Pair(-3, -12), Pair(-7, 16), Pair(5, 5), Pair(6, 18)
      },
      { // Piece 4
        Pair(-7, 72), Pair(-35, 57), Pair(-6, 43), Pair(-15, 47), Pair(67, 0), Pair(47, -22), Pair(4, 39), Pair(-65, 71),
        Pair(-14, 49), Pair(2, 38), Pair(-28, 46), Pair(19, 18), Pair(-12, 51), Pair(-14, 46), Pair(15, 18), Pair(-50, 66),
        Pair(8, 9), Pair(-2, 23), Pair(-19, 70), Pair(0, 19), Pair(18, 9), Pair(-43, 53), Pair(-22, 74), Pair(-15, -1),
        Pair(2, 40), Pair(10, 0), Pair(-12, 19), Pair(-19, 47), Pair(1, 26), Pair(-3, 35), Pair(-24, 99), Pair(-7, 0),
        Pair(5, 45), Pair(10, 8), Pair(-17, 63), Pair(-10, 51), Pair(-19, 52), Pair(-11, 25), Pair(-3, 16), Pair(-22, 45),
        Pair(7, 10), Pair(4, 39), Pair(8, -9), Pair(2, 14), Pair(0, 0), Pair(-12, 52), Pair(-7, 22), Pair(-23, 35),
        Pair(-6, 58), Pair(8, 11), Pair(5, 28), Pair(-1, 27), Pair(4, 18), Pair(-5, 30), Pair(2, 36), Pair(2, 10),
        Pair(1, 46), Pair(12, 14), Pair(-5, 17), Pair(-1, 24), Pair(-7, 22), Pair(11, 23), Pair(-69, 130), Pair(34, -12)
      },
      { // Piece 5
        Pair(31, 39), Pair(11, 46), Pair(-30, 76), Pair(-18, -35), Pair(-49, -66), Pair(-16, 69), Pair(-27, 15), Pair(14, -28),
        Pair(28, 10), Pair(-53, 50), Pair(-193, 54), Pair(-30, 74), Pair(63, 47), Pair(10, 20), Pair(52, 23), Pair(7, 9),
        Pair(-2, -3), Pair(66, -47), Pair(0, 32), Pair(46, 47), Pair(24, 53), Pair(7, 41), Pair(-10, 18), Pair(-8, 3),
        Pair(-23, 48), Pair(-82, 8), Pair(31, 0), Pair(9, 32), Pair(5, 29), Pair(13, 11), Pair(-26, 4), Pair(-140, 20),
        Pair(66, -28), Pair(-81, 17), Pair(-20, 10), Pair(-17, -6), Pair(-38, 15), Pair(-10, -16), Pair(8, -2), Pair(-22, 0),
        Pair(-5, 12), Pair(59, -8), Pair(13, -5), Pair(-47, 17), Pair(0, 0), Pair(-31, 0), Pair(21, -5), Pair(36, -20),
        Pair(29, -24), Pair(-20, -1), Pair(-23, 1), Pair(-33, 11), Pair(-49, 20), Pair(-33, 2), Pair(2, -13), Pair(11, -18),
        Pair(2, -41), Pair(6, -11), Pair(7, -15), Pair(-29, 4), Pair(-29, 13), Pair(-26, -7), Pair(5, -16), Pair(-3, -5)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, -4), Pair(-11, 10), Pair(-20, 5), Pair(19, -10), Pair(12, 13), Pair(37, -14), Pair(-34, 15), Pair(40, -5),
        Pair(1, 12), Pair(6, 13), Pair(16, 0), Pair(-1, 7), Pair(4, 3), Pair(6, 17), Pair(16, 4), Pair(-12, 13),
        Pair(6, 6), Pair(4, 9), Pair(8, 5), Pair(7, 8), Pair(1, 10), Pair(9, 6), Pair(1, 2), Pair(0, 5),
        Pair(0, 10), Pair(2, 7), Pair(2, 7), Pair(3, 4), Pair(16, 10), Pair(4, -2), Pair(14, 3), Pair(2, 4),
        Pair(2, 7), Pair(5, 10), Pair(3, 8), Pair(-7, 5), Pair(10, 10), Pair(-1, -1), Pair(10, 4), Pair(-3, 4),
        Pair(1, 12), Pair(3, 9), Pair(1, 7), Pair(-4, 8), Pair(9, 14), Pair(5, -5), Pair(11, 15), Pair(-1, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(49, -54), Pair(81, 8), Pair(-13, 57), Pair(20, 54), Pair(42, 19), Pair(56, 26), Pair(-35, -17), Pair(-61, -89),
        Pair(-26, 16), Pair(44, 5), Pair(-25, 21), Pair(44, -3), Pair(19, 31), Pair(71, -12), Pair(116, 18), Pair(-100, 22),
        Pair(50, 19), Pair(23, 14), Pair(14, 18), Pair(18, 14), Pair(47, 28), Pair(2, 23), Pair(25, 33), Pair(-38, 22),
        Pair(-17, 39), Pair(19, 34), Pair(26, 19), Pair(15, 31), Pair(25, 16), Pair(-9, 17), Pair(8, 32), Pair(-2, 48),
        Pair(9, 28), Pair(24, 28), Pair(18, 21), Pair(25, 25), Pair(28, 33), Pair(9, 27), Pair(-1, 21), Pair(-12, 2),
        Pair(16, 18), Pair(16, 30), Pair(10, 33), Pair(12, 34), Pair(20, 28), Pair(0, 0), Pair(4, 10), Pair(0, -2),
        Pair(6, 7), Pair(-4, 39), Pair(5, 34), Pair(7, 24), Pair(10, 21), Pair(16, 38), Pair(19, 27), Pair(-20, 6),
        Pair(-46, 33), Pair(-9, 45), Pair(-15, 32), Pair(11, 37), Pair(-5, 32), Pair(-15, 28), Pair(-3, -22), Pair(-17, -13)
      },
      { // Piece 2
        Pair(7, 3), Pair(64, -5), Pair(1, 14), Pair(86, 5), Pair(4, -19), Pair(-3, 10), Pair(12, -26), Pair(72, -24),
        Pair(-17, 20), Pair(16, -14), Pair(38, -1), Pair(53, -27), Pair(12, 8), Pair(-30, 22), Pair(77, -15), Pair(30, 3),
        Pair(-2, -15), Pair(24, 11), Pair(17, 3), Pair(43, -7), Pair(-16, 4), Pair(43, -22), Pair(51, -6), Pair(14, 23),
        Pair(19, 14), Pair(7, -1), Pair(16, 5), Pair(6, 2), Pair(33, 12), Pair(34, -18), Pair(22, -6), Pair(-37, -17),
        Pair(-12, 28), Pair(6, 20), Pair(11, -4), Pair(14, 26), Pair(29, 2), Pair(-4, 16), Pair(-19, 31), Pair(12, 26),
        Pair(12, 30), Pair(-1, 7), Pair(28, 7), Pair(-1, 19), Pair(22, 21), Pair(0, 0), Pair(12, 17), Pair(-13, 29),
        Pair(23, -17), Pair(14, 11), Pair(10, -2), Pair(9, 30), Pair(0, 1), Pair(34, 16), Pair(-18, -22), Pair(11, 25),
        Pair(-4, -5), Pair(-10, 8), Pair(3, 39), Pair(-39, 13), Pair(45, 16), Pair(-2, -2), Pair(54, -33), Pair(-11, -81)
      },
      { // Piece 3
        Pair(18, 23), Pair(29, 8), Pair(79, -4), Pair(16, 13), Pair(16, 11), Pair(152, -16), Pair(-3, 18), Pair(83, -11),
        Pair(12, 13), Pair(16, 25), Pair(39, 7), Pair(27, 8), Pair(30, 21), Pair(94, -12), Pair(11, 13), Pair(21, 0),
        Pair(8, 22), Pair(18, 26), Pair(15, 19), Pair(32, 18), Pair(7, 22), Pair(4, 32), Pair(-32, 14), Pair(36, 5),
        Pair(8, 18), Pair(18, 18), Pair(22, 7), Pair(39, 7), Pair(19, 16), Pair(16, 13), Pair(44, 16), Pair(30, 5),
        Pair(25, 19), Pair(8, 7), Pair(5, 26), Pair(17, 26), Pair(25, 22), Pair(46, -3), Pair(6, 49), Pair(3, 20),
        Pair(19, 28), Pair(-4, 17), Pair(1, 14), Pair(17, 6), Pair(-1, 23), Pair(0, 0), Pair(-10, 10), Pair(-8, -28),
        Pair(-37, 46), Pair(33, 4), Pair(23, 20), Pair(11, 12), Pair(0, 15), Pair(14, 3), Pair(-1, 9), Pair(-37, 27),
        Pair(11, 14), Pair(11, 24), Pair(10, 20), Pair(10, 18), Pair(4, 20), Pair(0, -3), Pair(-10, 35), Pair(1, 17)
      },
      { // Piece 4
        Pair(-37, 55), Pair(-26, 34), Pair(24, -1), Pair(-56, 59), Pair(-36, 45), Pair(1, 10), Pair(-62, 43), Pair(-36, 6),
        Pair(-22, 31), Pair(8, -16), Pair(-12, 25), Pair(-19, 70), Pair(-17, 40), Pair(-27, -4), Pair(0, 45), Pair(-29, 6),
        Pair(11, 8), Pair(-5, 16), Pair(-20, -1), Pair(-5, 46), Pair(-49, 45), Pair(-19, 40), Pair(-47, 71), Pair(-16, 16),
        Pair(3, 1), Pair(-3, 35), Pair(-7, -1), Pair(-7, 33), Pair(-33, 69), Pair(-4, 5), Pair(23, -66), Pair(-46, 19),
        Pair(-9, 89), Pair(-8, 44), Pair(-2, 12), Pair(-18, 16), Pair(-9, 42), Pair(-18, 17), Pair(-21, 43), Pair(-28, 26),
        Pair(-8, -26), Pair(0, 23), Pair(8, 17), Pair(-5, 10), Pair(-12, 22), Pair(0, 0), Pair(-20, -2), Pair(-2, -47),
        Pair(-39, 82), Pair(-8, 36), Pair(0, 19), Pair(13, -7), Pair(-8, 18), Pair(-10, 28), Pair(-9, 33), Pair(8, -22),
        Pair(-10, 51), Pair(-34, 108), Pair(-4, 1), Pair(-4, 12), Pair(-2, 5), Pair(30, -60), Pair(34, 36), Pair(-43, -38)
      },
      { // Piece 5
        Pair(-40, 126), Pair(-21, -42), Pair(93, 105), Pair(19, 11), Pair(52, -52), Pair(62, 67), Pair(-30, 52), Pair(40, -22),
        Pair(-14, 44), Pair(-60, 28), Pair(15, -16), Pair(73, -39), Pair(17, 86), Pair(115, 7), Pair(-17, 62), Pair(-122, -24),
        Pair(43, -16), Pair(-33, 22), Pair(-75, 17), Pair(-74, 54), Pair(64, 5), Pair(155, 12), Pair(-65, 56), Pair(35, 1),
        Pair(-41, 20), Pair(11, 8), Pair(-15, 8), Pair(-51, 41), Pair(-87, 45), Pair(-73, 30), Pair(1, 15), Pair(42, -16),
        Pair(-120, 21), Pair(40, -7), Pair(-18, 8), Pair(-24, 10), Pair(-54, 2), Pair(9, 3), Pair(19, -22), Pair(76, -6),
        Pair(-9, 12), Pair(-5, -3), Pair(16, 1), Pair(-16, 11), Pair(3, -1), Pair(0, 0), Pair(-4, -13), Pair(35, -6),
        Pair(-26, -4), Pair(6, -8), Pair(34, -13), Pair(-10, 0), Pair(-11, 3), Pair(-61, 18), Pair(-6, 0), Pair(21, -13),
        Pair(-32, 13), Pair(0, -16), Pair(8, -22), Pair(-35, -3), Pair(-9, -5), Pair(-30, -6), Pair(-4, -1), Pair(31, -24)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-31, 21), Pair(7, -7), Pair(-8, 1), Pair(13, -3), Pair(-4, 19), Pair(-56, 19), Pair(7, -11), Pair(12, 6),
        Pair(-3, 12), Pair(12, 7), Pair(-13, 15), Pair(-5, 6), Pair(-10, 16), Pair(-6, 4), Pair(11, -9), Pair(10, 2),
        Pair(3, 9), Pair(5, 6), Pair(-1, 10), Pair(4, 4), Pair(0, 8), Pair(-8, 5), Pair(3, 1), Pair(0, 5),
        Pair(2, 10), Pair(1, 15), Pair(1, 9), Pair(2, 9), Pair(3, 8), Pair(10, 5), Pair(1, -7), Pair(6, -5),
        Pair(2, 14), Pair(3, 14), Pair(2, 10), Pair(1, 10), Pair(2, 5), Pair(10, 4), Pair(3, 2), Pair(-3, 0),
        Pair(0, 11), Pair(3, 14), Pair(-2, 9), Pair(2, 9), Pair(1, 8), Pair(14, 15), Pair(-11, 0), Pair(0, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(7, 31), Pair(65, -1), Pair(89, 10), Pair(100, -14), Pair(-37, 43), Pair(82, 2), Pair(86, 26), Pair(158, 21),
        Pair(-42, 30), Pair(-30, 35), Pair(23, 19), Pair(27, 13), Pair(-24, 39), Pair(-9, 9), Pair(38, -24), Pair(10, 26),
        Pair(-18, 21), Pair(-21, 39), Pair(2, 36), Pair(7, 24), Pair(0, 18), Pair(-21, 38), Pair(-12, 21), Pair(-25, 18),
        Pair(6, 10), Pair(5, 25), Pair(11, 19), Pair(16, 30), Pair(-1, 37), Pair(14, 20), Pair(11, 17), Pair(-32, 47),
        Pair(0, 28), Pair(3, 22), Pair(2, 31), Pair(6, 30), Pair(7, 20), Pair(10, 21), Pair(0, 28), Pair(4, 11),
        Pair(-9, 23), Pair(4, 24), Pair(1, 25), Pair(14, 23), Pair(6, 26), Pair(2, 27), Pair(0, 0), Pair(-6, 16),
        Pair(-2, 9), Pair(-15, 45), Pair(-2, 20), Pair(5, 26), Pair(-10, 26), Pair(-3, 15), Pair(-7, 42), Pair(-5, 15),
        Pair(0, 96), Pair(-12, 16), Pair(24, 12), Pair(11, 31), Pair(-9, 22), Pair(-8, 12), Pair(6, -4), Pair(-48, 117)
      },
      { // Piece 2
        Pair(-24, 23), Pair(-30, 14), Pair(-31, 21), Pair(142, -40), Pair(-55, 26), Pair(21, -16), Pair(5, -16), Pair(-22, 27),
        Pair(-9, 5), Pair(-3, 10), Pair(-6, -2), Pair(45, -19), Pair(60, -29), Pair(0, 7), Pair(-23, 15), Pair(-34, 38),
        Pair(-9, 27), Pair(17, -3), Pair(35, -1), Pair(16, 10), Pair(28, 0), Pair(-43, 16), Pair(27, 6), Pair(5, -9),
        Pair(25, -8), Pair(7, 16), Pair(-14, 9), Pair(16, 10), Pair(-14, 17), Pair(9, 15), Pair(6, -9), Pair(11, 13),
        Pair(-4, 14), Pair(10, 7), Pair(16, 12), Pair(8, 6), Pair(11, 26), Pair(-18, 11), Pair(12, 28), Pair(21, -22),
        Pair(4, -6), Pair(2, 7), Pair(-4, 9), Pair(6, 29), Pair(-2, 11), Pair(8, 15), Pair(0, 0), Pair(12, 12),
        Pair(2, -11), Pair(-3, 2), Pair(-3, 13), Pair(0, 2), Pair(-3, 26), Pair(18, -10), Pair(13, 31), Pair(-80, -28),
        Pair(11, 7), Pair(-1, 24), Pair(-1, 6), Pair(-8, 28), Pair(8, 7), Pair(6, 18), Pair(30, -14), Pair(10, 4)
      },
      { // Piece 3
        Pair(2, 36), Pair(12, 29), Pair(78, 15), Pair(16, 16), Pair(-25, 45), Pair(-10, 30), Pair(30, -5), Pair(66, 7),
        Pair(27, 20), Pair(4, 31), Pair(24, 18), Pair(15, 33), Pair(45, 19), Pair(44, 1), Pair(119, -29), Pair(-4, 31),
        Pair(12, 27), Pair(17, 23), Pair(7, 26), Pair(4, 28), Pair(34, 12), Pair(-14, 15), Pair(94, -7), Pair(-9, 34),
        Pair(11, 21), Pair(7, 21), Pair(2, 28), Pair(33, 7), Pair(27, 22), Pair(13, 14), Pair(16, 24), Pair(-24, 38),
        Pair(13, 30), Pair(-6, 31), Pair(4, 26), Pair(18, 30), Pair(6, 31), Pair(25, 38), Pair(18, 0), Pair(8, 18),
        Pair(-1, 33), Pair(5, 18), Pair(4, 23), Pair(2, 20), Pair(16, 21), Pair(-19, 33), Pair(0, 0), Pair(-14, -2),
        Pair(4, 32), Pair(12, 28), Pair(10, 26), Pair(8, 22), Pair(6, 22), Pair(-3, 26), Pair(-9, 7), Pair(-8, 21),
        Pair(7, 21), Pair(19, 15), Pair(11, 18), Pair(8, 21), Pair(8, 20), Pair(3, 18), Pair(-25, -12), Pair(-12, 27)
      },
      { // Piece 4
        Pair(24, 13), Pair(7, -13), Pair(26, 12), Pair(15, 32), Pair(-27, 53), Pair(46, 7), Pair(65, 4), Pair(39, -33),
        Pair(-5, 26), Pair(2, 17), Pair(-4, 16), Pair(-45, 100), Pair(27, 16), Pair(62, -41), Pair(102, -72), Pair(14, 11),
        Pair(9, 28), Pair(-1, 50), Pair(-15, 21), Pair(5, 42), Pair(-24, 28), Pair(36, 5), Pair(30, 48), Pair(-10, 18),
        Pair(6, 34), Pair(-10, 47), Pair(-3, 33), Pair(-2, 46), Pair(2, 19), Pair(-13, 41), Pair(7, 14), Pair(9, -10),
        Pair(17, 4), Pair(13, 28), Pair(-1, 55), Pair(-3, 13), Pair(14, 24), Pair(-19, 33), Pair(0, 33), Pair(-30, 30),
        Pair(6, 19), Pair(16, 40), Pair(11, 36), Pair(9, 30), Pair(8, 42), Pair(-2, 41), Pair(0, 0), Pair(7, -48),
        Pair(28, 14), Pair(4, 48), Pair(12, 32), Pair(14, 36), Pair(11, 28), Pair(5, 16), Pair(0, 8), Pair(-42, 3),
        Pair(14, 64), Pair(6, 27), Pair(-4, 51), Pair(6, 45), Pair(-4, 33), Pair(-10, 33), Pair(-30, 48), Pair(-54, 58)
      },
      { // Piece 5
        Pair(-23, 42), Pair(-32, 22), Pair(-39, 14), Pair(0, 11), Pair(-46, 30), Pair(-154, -16), Pair(-32, 16), Pair(-52, 27),
        Pair(-60, -23), Pair(-115, 88), Pair(-108, -10), Pair(-118, 58), Pair(-23, 70), Pair(-136, 40), Pair(84, 38), Pair(-25, 53),
        Pair(-54, -24), Pair(12, -10), Pair(-101, 27), Pair(-101, 41), Pair(17, 10), Pair(55, 24), Pair(15, 71), Pair(-81, 44),
        Pair(59, -38), Pair(-157, 28), Pair(-105, 30), Pair(-46, 24), Pair(0, 33), Pair(36, 24), Pair(-4, 43), Pair(39, 27),
        Pair(5, 13), Pair(-22, 14), Pair(-16, 7), Pair(-50, 25), Pair(32, 13), Pair(-31, -2), Pair(34, 7), Pair(-50, -4),
        Pair(-31, -4), Pair(-56, 20), Pair(-11, 18), Pair(-31, 14), Pair(30, 8), Pair(-19, 4), Pair(0, 0), Pair(5, -19),
        Pair(-10, 7), Pair(-63, 24), Pair(-56, 22), Pair(-17, 8), Pair(-1, 3), Pair(-14, -1), Pair(-4, -1), Pair(-12, -9),
        Pair(-68, 11), Pair(-42, 6), Pair(-23, 5), Pair(-15, -20), Pair(5, -16), Pair(-9, 1), Pair(11, -6), Pair(-23, -5)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-6, 17), Pair(-1, 18), Pair(11, 13), Pair(6, 0), Pair(2, -13), Pair(22, -9), Pair(-26, 17), Pair(-10, 27),
        Pair(0, 10), Pair(7, 7), Pair(2, 9), Pair(1, 9), Pair(-3, 7), Pair(-14, 16), Pair(-10, 2), Pair(7, -11),
        Pair(0, 9), Pair(-1, 11), Pair(3, 5), Pair(4, 3), Pair(-2, 4), Pair(-1, 6), Pair(-4, 9), Pair(17, 4),
        Pair(-2, 12), Pair(4, 10), Pair(3, 9), Pair(1, 6), Pair(2, 7), Pair(-3, 6), Pair(7, 0), Pair(2, 5),
        Pair(-1, 13), Pair(0, 10), Pair(0, 10), Pair(1, 7), Pair(6, 7), Pair(-1, 3), Pair(-4, -2), Pair(-4, -10),
        Pair(-1, 13), Pair(-1, 10), Pair(1, 11), Pair(2, 4), Pair(5, 10), Pair(-3, 5), Pair(7, 10), Pair(-10, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(24, -55), Pair(-40, 67), Pair(-137, 99), Pair(-42, 15), Pair(114, -68), Pair(-19, 21), Pair(1, 42), Pair(-37, 17),
        Pair(-8, -8), Pair(-27, 20), Pair(8, 17), Pair(1, 26), Pair(-7, 33), Pair(44, 17), Pair(-43, 45), Pair(-49, 20),
        Pair(-15, 39), Pair(-7, 28), Pair(-7, 21), Pair(14, 10), Pair(1, 30), Pair(40, -6), Pair(11, 18), Pair(39, 8),
        Pair(-6, 22), Pair(3, 32), Pair(-6, 27), Pair(11, 23), Pair(6, 25), Pair(10, 18), Pair(3, 26), Pair(-11, 30),
        Pair(-6, 39), Pair(-7, 35), Pair(15, 23), Pair(11, 20), Pair(1, 31), Pair(0, 29), Pair(-3, 9), Pair(-20, 27),
        Pair(-12, 31), Pair(1, 20), Pair(-2, 29), Pair(-3, 34), Pair(3, 37), Pair(-1, 28), Pair(7, 12), Pair(0, 0),
        Pair(1, 29), Pair(-33, 38), Pair(-3, 25), Pair(-4, 30), Pair(-4, 30), Pair(0, 20), Pair(-2, 0), Pair(-4, 31),
        Pair(-34, 84), Pair(-20, 14), Pair(-49, 43), Pair(-42, 34), Pair(-6, 25), Pair(-10, 20), Pair(-11, 21), Pair(-30, 16)
      },
      { // Piece 2
        Pair(46, 14), Pair(-16, 0), Pair(-17, 0), Pair(-5, 4), Pair(58, -25), Pair(90, 8), Pair(2, -3), Pair(-60, 51),
        Pair(16, 22), Pair(8, 4), Pair(12, 6), Pair(40, -38), Pair(-4, 21), Pair(-8, 10), Pair(-20, 27), Pair(-11, 15),
        Pair(14, -4), Pair(17, 13), Pair(9, 1), Pair(-6, 7), Pair(1, 3), Pair(12, 10), Pair(20, 7), Pair(17, 7),
        Pair(-10, 22), Pair(1, 10), Pair(0, 21), Pair(16, 8), Pair(5, 23), Pair(32, -1), Pair(-8, 36), Pair(-4, -5),
        Pair(-12, 12), Pair(7, 17), Pair(8, 1), Pair(8, 18), Pair(11, 12), Pair(-4, 19), Pair(6, 33), Pair(16, 12),
        Pair(-8, 20), Pair(-3, 10), Pair(4, 19), Pair(3, 12), Pair(2, 35), Pair(-6, 12), Pair(6, 17), Pair(0, 0),
        Pair(42, -35), Pair(4, 16), Pair(2, 20), Pair(6, 18), Pair(-10, 29), Pair(15, 27), Pair(8, 13), Pair(4, 33),
        Pair(8, 20), Pair(-19, -1), Pair(2, 16), Pair(3, 13), Pair(21, 23), Pair(2, 10), Pair(15, 30), Pair(37, -17)
      },
      { // Piece 3
        Pair(31, 28), Pair(-4, 28), Pair(47, 16), Pair(25, 25), Pair(-7, 34), Pair(84, 8), Pair(92, 12), Pair(84, -12),
        Pair(3, 41), Pair(20, 35), Pair(33, 28), Pair(3, 33), Pair(9, 23), Pair(48, 17), Pair(14, 38), Pair(78, -17),
        Pair(0, 39), Pair(25, 31), Pair(20, 28), Pair(24, 28), Pair(32, 23), Pair(60, 13), Pair(18, 36), Pair(17, 5),
        Pair(-4, 44), Pair(27, 37), Pair(18, 18), Pair(21, 16), Pair(30, 11), Pair(31, 40), Pair(-3, 34), Pair(25, 17),
        Pair(-4, 36), Pair(1, 26), Pair(-5, 43), Pair(29, 22), Pair(23, 38), Pair(-1, 31), Pair(15, 38), Pair(23, 1),
        Pair(26, 36), Pair(7, 23), Pair(30, 22), Pair(11, 26), Pair(3, 33), Pair(5, 25), Pair(5, 32), Pair(0, 0),
        Pair(1, 36), Pair(-12, 33), Pair(6, 31), Pair(7, 33), Pair(-4, 30), Pair(-16, 42), Pair(-4, 26), Pair(-74, 38),
        Pair(9, 22), Pair(13, 19), Pair(12, 23), Pair(10, 29), Pair(14, 22), Pair(15, 26), Pair(-3, 24), Pair(-23, -1)
      },
      { // Piece 4
        Pair(14, 8), Pair(40, 22), Pair(34, 11), Pair(-7, 50), Pair(13, 48), Pair(-87, 77), Pair(-2, 66), Pair(31, 12),
        Pair(17, 45), Pair(6, 21), Pair(-1, 28), Pair(-20, 38), Pair(7, 33), Pair(35, 41), Pair(13, -11), Pair(-31, 27),
        Pair(14, 17), Pair(-24, 61), Pair(21, 17), Pair(19, 30), Pair(23, 17), Pair(29, 12), Pair(-1, 136), Pair(-10, 45),
        Pair(3, 26), Pair(20, 16), Pair(21, 5), Pair(-11, 62), Pair(-4, 33), Pair(26, 24), Pair(11, 46), Pair(17, 5),
        Pair(19, 11), Pair(1, 45), Pair(28, 23), Pair(0, 27), Pair(-7, 65), Pair(-12, 39), Pair(18, 13), Pair(-5, 31),
        Pair(7, 23), Pair(13, 42), Pair(6, 58), Pair(13, 28), Pair(10, 48), Pair(15, 31), Pair(4, 56), Pair(0, 0),
        Pair(18, 51), Pair(4, 50), Pair(5, 47), Pair(11, 30), Pair(7, 33), Pair(15, 19), Pair(23, 8), Pair(-51, 44),
        Pair(18, 39), Pair(-12, 27), Pair(-1, 29), Pair(9, 44), Pair(15, 21), Pair(49, -9), Pair(-45, 48), Pair(-6, -73)
      },
      { // Piece 5
        Pair(-11, -60), Pair(-99, -30), Pair(35, 28), Pair(-80, -58), Pair(-27, 17), Pair(66, 54), Pair(20, -36), Pair(-30, 43),
        Pair(-1, -3), Pair(51, 35), Pair(-2, 29), Pair(-16, 48), Pair(-104, 41), Pair(142, 24), Pair(25, 55), Pair(-106, 17),
        Pair(5, -10), Pair(-46, 43), Pair(9, 8), Pair(17, 19), Pair(42, 24), Pair(-52, 71), Pair(-95, 70), Pair(-83, 38),
        Pair(-43, 18), Pair(-58, 23), Pair(-84, 36), Pair(-124, 33), Pair(-98, 24), Pair(31, 21), Pair(46, 23), Pair(17, 1),
        Pair(-5, -6), Pair(-36, 19), Pair(-40, 28), Pair(-42, 21), Pair(-29, 26), Pair(0, 20), Pair(-7, -10), Pair(-65, 0),
        Pair(-59, 21), Pair(-89, 27), Pair(-52, 30), Pair(-9, 23), Pair(-3, 12), Pair(-3, 11), Pair(-39, -9), Pair(0, 0),
        Pair(-66, 13), Pair(-51, 23), Pair(-14, 27), Pair(-37, 24), Pair(-21, 11), Pair(-22, 7), Pair(-28, -6), Pair(-21, -23),
        Pair(-30, 4), Pair(-31, 15), Pair(-39, 17), Pair(-45, 6), Pair(-5, -7), Pair(-6, -2), Pair(9, -1), Pair(9, -27)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, -5), Pair(-23, 22), Pair(-22, 23), Pair(-9, 11), Pair(4, 6), Pair(1, 14), Pair(41, -8), Pair(-17, 34),
        Pair(-19, 31), Pair(-8, 14), Pair(-9, 14), Pair(-8, 8), Pair(-5, 10), Pair(1, 8), Pair(-14, 2), Pair(-7, 17),
        Pair(6, 10), Pair(-2, 8), Pair(3, 2), Pair(-4, 12), Pair(1, 7), Pair(-2, 14), Pair(4, 4), Pair(-5, 16),
        Pair(8, 1), Pair(-4, 11), Pair(1, 7), Pair(-1, 9), Pair(2, 7), Pair(-2, 8), Pair(0, 12), Pair(-4, 14),
        Pair(3, 0), Pair(5, 15), Pair(-3, 5), Pair(-1, 10), Pair(-2, 6), Pair(-1, 11), Pair(1, 11), Pair(0, 16),
        Pair(2, 0), Pair(-4, 4), Pair(-5, 7), Pair(2, 7), Pair(-2, 9), Pair(-4, 15), Pair(0, 15), Pair(-1, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-93, -13), Pair(-39, -24), Pair(-19, 1), Pair(-36, 55), Pair(-75, 75), Pair(-25, 57), Pair(-99, 17), Pair(-5, -59),
        Pair(20, -9), Pair(-23, 25), Pair(-27, 23), Pair(-10, 35), Pair(-18, 50), Pair(9, 38), Pair(-19, 58), Pair(-39, -10),
        Pair(46, 31), Pair(-14, 36), Pair(-12, 35), Pair(-3, 48), Pair(1, 23), Pair(-36, 55), Pair(-7, 50), Pair(24, -13),
        Pair(-16, 20), Pair(0, 35), Pair(-1, 32), Pair(-3, 43), Pair(1, 53), Pair(-11, 47), Pair(-4, 40), Pair(-6, 46),
        Pair(4, 27), Pair(4, 29), Pair(5, 33), Pair(1, 24), Pair(3, 36), Pair(11, 40), Pair(2, 27), Pair(4, 11),
        Pair(-6, -11), Pair(4, 24), Pair(6, 35), Pair(3, 42), Pair(4, 33), Pair(3, 30), Pair(-1, 41), Pair(6, 16),
        Pair(0, 0), Pair(16, 11), Pair(2, 17), Pair(-5, 35), Pair(4, 17), Pair(0, 37), Pair(-4, 51), Pair(-6, 68),
        Pair(10, -15), Pair(1, -12), Pair(48, 5), Pair(11, 52), Pair(2, 45), Pair(-2, 35), Pair(4, 5), Pair(5, -14)
      },
      { // Piece 2
        Pair(-8, 1), Pair(-19, 2), Pair(6, -23), Pair(75, -15), Pair(47, -26), Pair(40, -47), Pair(-43, 24), Pair(-3, 0),
        Pair(23, -4), Pair(2, 23), Pair(-2, 11), Pair(60, -31), Pair(32, -47), Pair(42, -2), Pair(-40, 16), Pair(-1, 38),
        Pair(-2, 25), Pair(-8, 23), Pair(18, 6), Pair(33, 7), Pair(20, 1), Pair(27, -11), Pair(-17, 19), Pair(-3, 23),
        Pair(-1, 31), Pair(18, 10), Pair(10, 20), Pair(22, -7), Pair(7, 17), Pair(8, 4), Pair(4, 18), Pair(-11, 25),
        Pair(-2, 12), Pair(21, 2), Pair(9, 5), Pair(4, 26), Pair(16, 30), Pair(-1, 30), Pair(6, 28), Pair(3, 24),
        Pair(0, 9), Pair(13, 34), Pair(13, 4), Pair(7, 27), Pair(6, 28), Pair(9, 33), Pair(-1, 31), Pair(-1, 43),
        Pair(0, 0), Pair(6, 24), Pair(6, 34), Pair(2, 26), Pair(7, 29), Pair(2, 39), Pair(7, 30), Pair(13, 15),
        Pair(9, 29), Pair(-2, 9), Pair(1, 25), Pair(17, 10), Pair(20, 0), Pair(-3, 36), Pair(-9, 27), Pair(20, -1)
      },
      { // Piece 3
        Pair(-70, 51), Pair(-28, 46), Pair(-18, 48), Pair(-39, 47), Pair(-20, 45), Pair(-71, 58), Pair(26, 50), Pair(-64, 62),
        Pair(-59, 39), Pair(-14, 46), Pair(-11, 49), Pair(-24, 46), Pair(-34, 53), Pair(-26, 28), Pair(-38, 57), Pair(31, 21),
        Pair(-5, 35), Pair(-6, 49), Pair(-24, 53), Pair(3, 38), Pair(-4, 34), Pair(-9, 48), Pair(40, 21), Pair(5, 46),
        Pair(-7, 38), Pair(-6, 54), Pair(-21, 46), Pair(0, 40), Pair(-7, 50), Pair(-8, 63), Pair(7, 44), Pair(13, 24),
        Pair(3, 40), Pair(20, 40), Pair(-5, 34), Pair(-5, 49), Pair(-10, 55), Pair(-11, 52), Pair(-4, 44), Pair(19, 23),
        Pair(-13, 15), Pair(8, 33), Pair(13, 33), Pair(2, 40), Pair(4, 33), Pair(-3, 49), Pair(11, 33), Pair(30, 9),
        Pair(0, 0), Pair(-16, 40), Pair(-11, 44), Pair(6, 40), Pair(-10, 40), Pair(1, 37), Pair(14, 29), Pair(32, 32),
        Pair(-21, 13), Pair(-7, 36), Pair(-3, 41), Pair(-2, 37), Pair(-2, 37), Pair(-3, 35), Pair(9, 25), Pair(5, 28)
      },
      { // Piece 4
        Pair(31, 52), Pair(13, 34), Pair(8, 12), Pair(4, 20), Pair(-22, 76), Pair(19, 103), Pair(18, 87), Pair(26, 18),
        Pair(-20, 66), Pair(-5, 70), Pair(-1, 67), Pair(10, 52), Pair(-12, 76), Pair(-14, 69), Pair(11, 28), Pair(-1, 15),
        Pair(-2, 58), Pair(21, -11), Pair(2, 75), Pair(6, 57), Pair(11, 52), Pair(-51, 104), Pair(-31, 76), Pair(-15, 45),
        Pair(0, 77), Pair(-12, 97), Pair(1, 76), Pair(19, 58), Pair(32, 24), Pair(17, 30), Pair(7, 41), Pair(3, 72),
        Pair(-6, 81), Pair(14, 40), Pair(5, 48), Pair(12, 46), Pair(9, 68), Pair(3, 65), Pair(9, 57), Pair(23, -6),
        Pair(4, 50), Pair(22, 50), Pair(6, 83), Pair(12, 47), Pair(-1, 83), Pair(13, 70), Pair(4, 74), Pair(13, 46),
        Pair(0, 0), Pair(8, 56), Pair(11, 63), Pair(13, 66), Pair(9, 62), Pair(17, 66), Pair(4, 61), Pair(-17, 87),
        Pair(19, 19), Pair(-7, 87), Pair(4, 73), Pair(6, 79), Pair(-3, 76), Pair(28, 27), Pair(1, 40), Pair(63, 91)
      },
      { // Piece 5
        Pair(-26, 17), Pair(-9, 81), Pair(-56, 14), Pair(51, 19), Pair(52, -15), Pair(72, 25), Pair(-12, 36), Pair(-31, 18),
        Pair(30, 51), Pair(7, 142), Pair(-64, 90), Pair(62, 38), Pair(-70, -1), Pair(113, 50), Pair(-120, 4), Pair(-28, -15),
        Pair(-119, 42), Pair(-28, 58), Pair(6, 33), Pair(-97, 48), Pair(-19, 53), Pair(-146, 48), Pair(-133, 26), Pair(-201, 37),
        Pair(-187, 75), Pair(-113, 62), Pair(-36, 47), Pair(-126, 63), Pair(-57, 40), Pair(-74, 16), Pair(-102, 17), Pair(-106, 19),
        Pair(-43, -18), Pair(-54, 27), Pair(-89, 31), Pair(-23, 39), Pair(-35, 31), Pair(-8, 3), Pair(-47, 21), Pair(-126, 26),
        Pair(-51, -13), Pair(-21, 15), Pair(28, -1), Pair(-42, 28), Pair(-72, 32), Pair(-26, 24), Pair(-30, 10), Pair(-33, -3),
        Pair(0, 0), Pair(-3, -2), Pair(24, -10), Pair(18, -4), Pair(-17, 12), Pair(-10, 9), Pair(-13, 8), Pair(-17, -1),
        Pair(2, -79), Pair(43, -36), Pair(51, -23), Pair(8, -15), Pair(-1, -1), Pair(-13, 1), Pair(-6, 0), Pair(-6, -11)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 27), Pair(-11, 4), Pair(-14, 16), Pair(-23, 24), Pair(-31, 3), Pair(-5, 14), Pair(21, 18), Pair(-16, 14),
        Pair(-11, 18), Pair(1, -3), Pair(-10, 7), Pair(-11, 14), Pair(14, -1), Pair(5, 2), Pair(-1, 12), Pair(-4, -3),
        Pair(-8, 11), Pair(6, 3), Pair(-6, 11), Pair(1, 8), Pair(4, 6), Pair(0, 9), Pair(1, 11), Pair(3, 10),
        Pair(-3, 9), Pair(-1, 6), Pair(0, 8), Pair(4, 6), Pair(1, 10), Pair(4, 11), Pair(1, 16), Pair(-1, 8),
        Pair(-1, 11), Pair(-4, -4), Pair(5, 21), Pair(1, 5), Pair(-1, 11), Pair(3, 9), Pair(3, 11), Pair(1, 10),
        Pair(-4, 6), Pair(1, 6), Pair(4, 11), Pair(3, -30), Pair(-2, 10), Pair(1, 12), Pair(2, 16), Pair(0, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-24, 78), Pair(45, 87), Pair(-93, 99), Pair(-9, 38), Pair(-49, 20), Pair(-39, 61), Pair(60, 127), Pair(-140, 106),
        Pair(25, 9), Pair(1, 5), Pair(-28, 30), Pair(-24, 23), Pair(-30, 54), Pair(-35, 30), Pair(-35, 20), Pair(0, 46),
        Pair(-21, 39), Pair(8, 26), Pair(-5, 47), Pair(-9, 28), Pair(-20, 31), Pair(-44, 46), Pair(-44, 56), Pair(-33, 47),
        Pair(8, 3), Pair(3, 28), Pair(0, 28), Pair(-3, 33), Pair(-3, 27), Pair(-19, 26), Pair(-1, 36), Pair(-1, 34),
        Pair(-6, 28), Pair(18, 37), Pair(3, 30), Pair(-1, 30), Pair(-10, 33), Pair(4, 31), Pair(-12, 45), Pair(5, 31),
        Pair(8, 35), Pair(2, 15), Pair(11, 22), Pair(9, 24), Pair(0, 39), Pair(1, 30), Pair(4, 24), Pair(7, 25),
        Pair(1, 6), Pair(0, 0), Pair(-8, 51), Pair(2, 32), Pair(4, 39), Pair(7, 33), Pair(20, 14), Pair(-4, 21),
        Pair(14, 52), Pair(6, 31), Pair(-16, 46), Pair(-9, 52), Pair(-4, 53), Pair(-2, 27), Pair(9, 12), Pair(-18, -72)
      },
      { // Piece 2
        Pair(17, -5), Pair(-14, 14), Pair(-111, 18), Pair(-79, 25), Pair(33, -7), Pair(34, -29), Pair(-15, 21), Pair(-54, -21),
        Pair(19, 4), Pair(6, 16), Pair(-4, 10), Pair(-11, 21), Pair(-12, 20), Pair(47, -1), Pair(40, -16), Pair(-14, 25),
        Pair(-14, 19), Pair(0, 21), Pair(-1, 18), Pair(-10, 17), Pair(19, -10), Pair(0, 12), Pair(3, 27), Pair(-6, 6),
        Pair(-16, 22), Pair(-6, 18), Pair(-1, 15), Pair(4, 21), Pair(4, 2), Pair(18, 10), Pair(-4, 11), Pair(-15, 18),
        Pair(6, 11), Pair(-6, 19), Pair(8, 10), Pair(5, 10), Pair(-5, 23), Pair(3, 19), Pair(17, 16), Pair(-2, 26),
        Pair(-10, 3), Pair(-6, 10), Pair(10, 32), Pair(0, 17), Pair(3, 17), Pair(5, 28), Pair(1, 17), Pair(-1, 24),
        Pair(5, 30), Pair(0, 0), Pair(9, 17), Pair(-1, 38), Pair(3, 20), Pair(2, 35), Pair(0, 33), Pair(-4, 19),
        Pair(0, 0), Pair(8, 10), Pair(-10, 12), Pair(12, 9), Pair(-4, 42), Pair(-2, 28), Pair(7, 26), Pair(29, -4)
      },
      { // Piece 3
        Pair(-34, 46), Pair(-3, 16), Pair(-4, 16), Pair(-13, 16), Pair(16, 15), Pair(-44, 57), Pair(33, 9), Pair(-32, 38),
        Pair(9, 14), Pair(-7, 16), Pair(-18, 31), Pair(12, 25), Pair(1, 39), Pair(-78, 73), Pair(-27, 57), Pair(26, 13),
        Pair(-14, 35), Pair(-16, 24), Pair(-14, 18), Pair(-8, 36), Pair(5, 37), Pair(-21, 20), Pair(3, 29), Pair(29, 8),
        Pair(-1, 27), Pair(-3, 24), Pair(-5, 43), Pair(-9, 33), Pair(-1, 21), Pair(17, 23), Pair(3, 18), Pair(-10, 31),
        Pair(-15, 28), Pair(6, 24), Pair(-13, 43), Pair(17, 22), Pair(-6, 45), Pair(-4, 25), Pair(-15, 39), Pair(19, 3),
        Pair(1, 3), Pair(-11, 11), Pair(16, 14), Pair(10, 30), Pair(-7, 26), Pair(-3, 31), Pair(-5, 35), Pair(16, 33),
        Pair(-8, -7), Pair(0, 0), Pair(-8, 41), Pair(4, 31), Pair(0, 33), Pair(-8, 40), Pair(17, 40), Pair(2, 32),
        Pair(-3, 22), Pair(-11, -2), Pair(-7, 26), Pair(-3, 29), Pair(-3, 30), Pair(-5, 28), Pair(3, 27), Pair(2, 25)
      },
      { // Piece 4
        Pair(-50, 48), Pair(-26, 28), Pair(-1, 26), Pair(25, 22), Pair(-148, 156), Pair(7, -6), Pair(83, 20), Pair(-8, 19),
        Pair(6, 10), Pair(-14, 49), Pair(-10, 54), Pair(0, 30), Pair(-51, 69), Pair(10, -24), Pair(16, 41), Pair(-29, 5),
        Pair(-21, 72), Pair(-24, 53), Pair(26, -21), Pair(8, 28), Pair(2, 11), Pair(-48, 96), Pair(-1, 42), Pair(-2, 56),
        Pair(2, 57), Pair(16, 30), Pair(-9, 84), Pair(-24, 69), Pair(5, 19), Pair(-28, 45), Pair(-7, 34), Pair(-7, 33),
        Pair(-1, 58), Pair(-15, 64), Pair(7, 23), Pair(-12, 48), Pair(-11, 53), Pair(-5, 32), Pair(-5, 42), Pair(2, 36),
        Pair(-22, 91), Pair(-1, 21), Pair(6, 56), Pair(-5, 76), Pair(16, 45), Pair(5, 44), Pair(-1, 65), Pair(1, 36),
        Pair(-22, 13), Pair(0, 0), Pair(10, 37), Pair(5, 47), Pair(10, 46), Pair(-4, 73), Pair(-4, 63), Pair(-14, 86),
        Pair(3, 41), Pair(9, -44), Pair(-4, 61), Pair(4, 53), Pair(-1, 61), Pair(1, 51), Pair(15, 51), Pair(22, 77)
      },
      { // Piece 5
        Pair(-67, -25), Pair(50, 15), Pair(-59, 52), Pair(-17, -39), Pair(49, -47), Pair(18, 44), Pair(3, -53), Pair(-32, -83),
        Pair(-9, 58), Pair(84, 15), Pair(-56, 23), Pair(14, 35), Pair(16, -40), Pair(-80, 128), Pair(-40, 40), Pair(-69, 53),
        Pair(-172, 139), Pair(4, 40), Pair(8, 44), Pair(-67, 93), Pair(11, 10), Pair(34, 18), Pair(-38, 3), Pair(34, 4),
        Pair(-28, 68), Pair(-16, 51), Pair(112, 16), Pair(-29, 34), Pair(-145, 32), Pair(-47, 20), Pair(-92, 12), Pair(-79, 22),
        Pair(-25, 20), Pair(51, 2), Pair(24, 46), Pair(-86, 36), Pair(-33, 20), Pair(-32, 20), Pair(-48, 24), Pair(2, -11),
        Pair(109, -46), Pair(-6, -1), Pair(-48, 6), Pair(-41, 19), Pair(-2, 15), Pair(6, -3), Pair(-19, 12), Pair(-48, 0),
        Pair(72, -8), Pair(0, 0), Pair(-11, 0), Pair(9, 7), Pair(14, 3), Pair(-12, 11), Pair(-19, 8), Pair(-7, -12),
        Pair(65, -29), Pair(36, -12), Pair(29, -12), Pair(16, -6), Pair(6, 11), Pair(18, -5), Pair(-7, -4), Pair(-4, -16)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 29), Pair(-64, 43), Pair(0, -13), Pair(16, -16), Pair(16, -35), Pair(-17, -7), Pair(18, 11), Pair(25, -6),
        Pair(-7, 4), Pair(-25, 24), Pair(-8, 5), Pair(-10, 7), Pair(17, 5), Pair(6, 0), Pair(-3, 1), Pair(3, 6),
        Pair(-1, 9), Pair(-7, 9), Pair(-3, 1), Pair(-2, 4), Pair(4, 8), Pair(1, 11), Pair(-1, 8), Pair(-4, 6),
        Pair(0, 8), Pair(-2, 13), Pair(-4, -5), Pair(2, 11), Pair(1, 8), Pair(3, 10), Pair(0, 10), Pair(-4, 14),
        Pair(-5, 6), Pair(5, 16), Pair(-7, -12), Pair(5, 26), Pair(-3, 8), Pair(2, 8), Pair(-2, 10), Pair(0, 10),
        Pair(-4, 6), Pair(3, 10), Pair(-1, 2), Pair(1, 10), Pair(-7, 1), Pair(-2, 12), Pair(-5, 15), Pair(1, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, 8), Pair(91, -131), Pair(49, -10), Pair(90, 25), Pair(-126, 93), Pair(-67, -68), Pair(-74, 120), Pair(64, -24),
        Pair(32, -10), Pair(-31, 92), Pair(41, 16), Pair(2, 60), Pair(15, -8), Pair(2, 1), Pair(46, -10), Pair(-5, -15),
        Pair(14, -4), Pair(-24, 25), Pair(8, 16), Pair(-6, 34), Pair(5, 4), Pair(44, -11), Pair(4, 31), Pair(-3, 13),
        Pair(20, 28), Pair(3, 17), Pair(-10, 27), Pair(19, 32), Pair(-4, 22), Pair(0, 46), Pair(-6, 41), Pair(-5, 13),
        Pair(-8, 30), Pair(45, -2), Pair(9, 17), Pair(0, 22), Pair(-2, 39), Pair(6, 19), Pair(-4, 29), Pair(5, 11),
        Pair(-6, 57), Pair(7, 19), Pair(2, 15), Pair(0, 38), Pair(12, 39), Pair(2, 34), Pair(18, 11), Pair(5, -14),
        Pair(-41, 71), Pair(9, -1), Pair(0, 0), Pair(0, 47), Pair(2, 41), Pair(0, 23), Pair(2, 36), Pair(6, 46),
        Pair(11, -42), Pair(-5, 13), Pair(-17, 26), Pair(-11, 35), Pair(1, 26), Pair(3, 34), Pair(1, 9), Pair(68, -42)
      },
      { // Piece 2
        Pair(47, 40), Pair(-110, 49), Pair(0, 11), Pair(-15, -15), Pair(-5, 18), Pair(35, 3), Pair(-54, -54), Pair(16, 42),
        Pair(10, 11), Pair(-4, 14), Pair(-30, 43), Pair(-35, 5), Pair(5, 16), Pair(16, 1), Pair(24, 22), Pair(2, 0),
        Pair(-33, 39), Pair(26, 32), Pair(0, 28), Pair(20, -7), Pair(-5, -19), Pair(-28, 26), Pair(10, -8), Pair(13, 13),
        Pair(-5, 4), Pair(-4, 9), Pair(27, 16), Pair(4, 8), Pair(-2, 26), Pair(6, 8), Pair(-1, 8), Pair(6, -5),
        Pair(-10, 21), Pair(12, 11), Pair(4, 12), Pair(18, 20), Pair(5, 3), Pair(8, 16), Pair(-3, 21), Pair(16, -3),
        Pair(15, 1), Pair(3, 13), Pair(5, 9), Pair(-2, 46), Pair(3, 28), Pair(4, 13), Pair(10, 2), Pair(-5, 7),
        Pair(6, -37), Pair(5, 42), Pair(0, 0), Pair(2, 29), Pair(-3, 19), Pair(3, 23), Pair(-2, 26), Pair(11, 31),
        Pair(-1, 28), Pair(-37, -96), Pair(7, 40), Pair(-3, -29), Pair(-11, 35), Pair(-4, 20), Pair(11, 34), Pair(-25, 62)
      },
      { // Piece 3
        Pair(-81, 60), Pair(1, 5), Pair(-19, 13), Pair(-56, 41), Pair(-48, 47), Pair(25, 2), Pair(12, 4), Pair(17, 3),
        Pair(-12, 34), Pair(1, 18), Pair(-19, 10), Pair(-20, 25), Pair(5, -6), Pair(-4, 9), Pair(-22, 13), Pair(-26, 28),
        Pair(-17, 26), Pair(-4, 27), Pair(31, 0), Pair(-29, 29), Pair(-16, 25), Pair(-2, 24), Pair(17, 18), Pair(6, 27),
        Pair(-3, 44), Pair(-14, 28), Pair(-2, 21), Pair(-27, 48), Pair(1, 13), Pair(-8, 33), Pair(-42, 54), Pair(-13, 50),
        Pair(6, 20), Pair(2, 23), Pair(37, 9), Pair(1, 23), Pair(-16, 42), Pair(-8, 19), Pair(27, 2), Pair(-3, 26),
        Pair(15, 28), Pair(16, 23), Pair(42, -3), Pair(0, 24), Pair(-4, 33), Pair(-10, 23), Pair(-29, 37), Pair(33, -16),
        Pair(-26, 15), Pair(-9, -4), Pair(0, 0), Pair(-10, 26), Pair(-5, 32), Pair(-2, 19), Pair(-15, 31), Pair(4, 36),
        Pair(-7, 28), Pair(2, 17), Pair(-7, -20), Pair(-4, 23), Pair(-5, 22), Pair(-3, 20), Pair(-4, 29), Pair(-10, 27)
      },
      { // Piece 4
        Pair(36, 41), Pair(-7, 26), Pair(-13, 11), Pair(-1, 15), Pair(-52, 95), Pair(-5, -18), Pair(46, -103), Pair(-31, 60),
        Pair(-13, 36), Pair(10, 29), Pair(-6, 46), Pair(-14, 21), Pair(47, -16), Pair(65, -59), Pair(-52, 143), Pair(-22, 35),
        Pair(-10, 65), Pair(7, 7), Pair(18, -26), Pair(-21, 54), Pair(0, 37), Pair(-55, 85), Pair(-10, 68), Pair(-9, 51),
        Pair(20, 11), Pair(1, 43), Pair(33, -27), Pair(-1, 69), Pair(5, 43), Pair(13, -21), Pair(-15, 34), Pair(-24, 30),
        Pair(1, 54), Pair(13, 9), Pair(4, 36), Pair(-2, 49), Pair(3, 24), Pair(2, 37), Pair(-1, 32), Pair(7, -14),
        Pair(-5, 58), Pair(8, 29), Pair(-2, 56), Pair(2, 60), Pair(18, -3), Pair(7, 42), Pair(-4, 58), Pair(-17, 47),
        Pair(5, -58), Pair(-6, 39), Pair(0, 0), Pair(4, 72), Pair(9, 28), Pair(13, 28), Pair(-11, 33), Pair(-55, 126),
        Pair(0, 27), Pair(-15, 59), Pair(-2, 5), Pair(0, 27), Pair(2, 12), Pair(-2, 74), Pair(7, 8), Pair(-15, 65)
      },
      { // Piece 5
        Pair(10, 43), Pair(30, 71), Pair(3, -102), Pair(-2, -22), Pair(46, 26), Pair(12, 115), Pair(27, -30), Pair(22, 8),
        Pair(16, 32), Pair(-34, 107), Pair(-73, 107), Pair(-23, -17), Pair(52, 75), Pair(-50, 28), Pair(-52, -1), Pair(-65, -97),
        Pair(-55, 149), Pair(92, 4), Pair(-102, 54), Pair(23, 84), Pair(47, 46), Pair(-18, 48), Pair(-102, 56), Pair(42, 10),
        Pair(29, 57), Pair(-139, 79), Pair(206, 2), Pair(69, 4), Pair(-118, 51), Pair(-152, 25), Pair(-18, -11), Pair(-59, 6),
        Pair(-9, -6), Pair(-82, 47), Pair(68, 4), Pair(53, 8), Pair(19, -11), Pair(-59, 16), Pair(-66, 16), Pair(-82, 14),
        Pair(8, 27), Pair(-64, 28), Pair(-42, 0), Pair(-25, 2), Pair(-4, 3), Pair(-21, 6), Pair(-29, 7), Pair(-18, 15),
        Pair(60, 31), Pair(32, -7), Pair(0, 0), Pair(0, 2), Pair(-1, -4), Pair(-4, 1), Pair(-5, -7), Pair(-6, -10),
        Pair(-9, 15), Pair(11, 3), Pair(1, 9), Pair(-13, 3), Pair(14, 8), Pair(6, -5), Pair(-4, -10), Pair(-8, -8)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-33, -9), Pair(-62, 36), Pair(-21, -32), Pair(-16, 14), Pair(-89, 67), Pair(13, -7), Pair(49, -36), Pair(-38, -6),
        Pair(15, 2), Pair(11, 6), Pair(-20, 8), Pair(1, 6), Pair(17, 12), Pair(-22, 10), Pair(35, -2), Pair(10, -18),
        Pair(-6, 0), Pair(8, 0), Pair(-6, 27), Pair(4, 13), Pair(-12, 26), Pair(-2, 18), Pair(-5, -3), Pair(-6, 10),
        Pair(1, 5), Pair(1, 14), Pair(-1, 4), Pair(10, 2), Pair(3, 6), Pair(-3, 15), Pair(3, 11), Pair(3, 3),
        Pair(1, 9), Pair(-2, 14), Pair(4, 24), Pair(-4, -1), Pair(11, 29), Pair(-6, 7), Pair(2, 10), Pair(2, 2),
        Pair(1, 6), Pair(4, -31), Pair(1, 9), Pair(-1, -5), Pair(3, 25), Pair(-7, 13), Pair(-4, 21), Pair(0, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(6, 24), Pair(-114, -128), Pair(-12, -50), Pair(-58, 21), Pair(-60, -99), Pair(-41, -12), Pair(-108, 7), Pair(13, -96),
        Pair(-51, 17), Pair(-7, 25), Pair(-40, 34), Pair(-65, 83), Pair(-119, 145), Pair(-29, 26), Pair(-97, -54), Pair(8, 0),
        Pair(-83, 111), Pair(-3, 70), Pair(-13, -15), Pair(-12, 3), Pair(58, -48), Pair(2, -2), Pair(47, -83), Pair(-4, 51),
        Pair(-51, 64), Pair(-14, 39), Pair(8, 6), Pair(-24, 78), Pair(-6, 43), Pair(4, -18), Pair(-8, 58), Pair(-18, 44),
        Pair(12, -10), Pair(53, 11), Pair(2, 20), Pair(-8, 27), Pair(4, 29), Pair(-6, 10), Pair(6, 25), Pair(-1, 12),
        Pair(1, 3), Pair(-21, 6), Pair(6, 19), Pair(4, 1), Pair(15, 15), Pair(-1, 47), Pair(2, 20), Pair(6, -3),
        Pair(3, -42), Pair(-12, 20), Pair(6, -41), Pair(0, 0), Pair(-2, 52), Pair(-4, 18), Pair(7, -7), Pair(12, 12),
        Pair(3, 14), Pair(-7, 16), Pair(36, 28), Pair(-2, 53), Pair(7, 23), Pair(25, -67), Pair(-4, -14), Pair(-5, -41)
      },
      { // Piece 2
        Pair(-26, -40), Pair(-44, -28), Pair(-92, 119), Pair(-136, 17), Pair(-17, 20), Pair(-77, 55), Pair(-15, -18), Pair(-71, 24),
        Pair(35, -69), Pair(-16, -6), Pair(-2, 16), Pair(-35, -92), Pair(19, -103), Pair(-9, -64), Pair(-36, -20), Pair(-32, 68),
        Pair(1, -37), Pair(55, -44), Pair(27, 48), Pair(31, -13), Pair(-19, 14), Pair(-74, 57), Pair(-57, 32), Pair(-55, 13),
        Pair(-4, 9), Pair(-3, 19), Pair(2, 18), Pair(-24, 63), Pair(-16, 32), Pair(22, 0), Pair(0, -29), Pair(-27, 48),
        Pair(14, -17), Pair(-7, 19), Pair(-2, -6), Pair(-13, 27), Pair(-20, 42), Pair(24, -88), Pair(34, -20), Pair(2, -19),
        Pair(-4, -48), Pair(-12, -26), Pair(15, 10), Pair(-19, 14), Pair(-22, 34), Pair(8, 2), Pair(15, 57), Pair(-9, 11),
        Pair(5, 39), Pair(-2, -8), Pair(13, -79), Pair(0, 0), Pair(2, 18), Pair(-33, 38), Pair(-3, 34), Pair(-61, -65),
        Pair(20, -55), Pair(-9, -39), Pair(-16, -47), Pair(9, 44), Pair(74, -19), Pair(-4, 17), Pair(-121, 13), Pair(10, 12)
      },
      { // Piece 3
        Pair(-75, 54), Pair(39, 16), Pair(-19, -8), Pair(-32, 42), Pair(25, -12), Pair(106, 33), Pair(12, 11), Pair(-53, 62),
        Pair(36, -14), Pair(22, 37), Pair(-82, 90), Pair(-107, 60), Pair(-45, 65), Pair(3, 34), Pair(-71, 50), Pair(-27, 26),
        Pair(40, 15), Pair(35, -2), Pair(3, -8), Pair(110, -27), Pair(-74, 48), Pair(-118, 48), Pair(47, -16), Pair(-24, 56),
        Pair(-13, 25), Pair(17, 53), Pair(15, 46), Pair(41, 39), Pair(-12, 27), Pair(23, -21), Pair(-27, -2), Pair(26, -6),
        Pair(8, 14), Pair(-31, 54), Pair(-28, 46), Pair(49, 3), Pair(-2, 14), Pair(-39, 64), Pair(-20, 98), Pair(17, -28),
        Pair(4, 45), Pair(38, 6), Pair(-1, 46), Pair(-12, 42), Pair(33, -26), Pair(-22, 33), Pair(22, -5), Pair(0, 5),
        Pair(27, 21), Pair(-11, 18), Pair(43, -23), Pair(0, 0), Pair(-53, 55), Pair(-12, 12), Pair(-11, 70), Pair(47, -3),
        Pair(-7, 4), Pair(1, -5), Pair(-8, 11), Pair(-13, -17), Pair(-19, 21), Pair(0, -11), Pair(0, 5), Pair(5, 25)
      },
      { // Piece 4
        Pair(-42, 55), Pair(7, 68), Pair(59, -104), Pair(38, -22), Pair(-73, 21), Pair(26, 4), Pair(-49, 12), Pair(-71, -48),
        Pair(-20, -13), Pair(-59, 88), Pair(-3, 1), Pair(64, -158), Pair(-11, 29), Pair(-75, 83), Pair(-34, 103), Pair(-9, -37),
        Pair(2, -51), Pair(-35, 123), Pair(8, -28), Pair(-7, -44), Pair(15, -43), Pair(-2, 94), Pair(12, 69), Pair(2, 5),
        Pair(65, -32), Pair(-45, 82), Pair(7, -15), Pair(27, -66), Pair(-9, 41), Pair(1, 7), Pair(10, 58), Pair(4, -13),
        Pair(-8, -30), Pair(-4, -47), Pair(-10, 60), Pair(4, 0), Pair(1, 12), Pair(-30, 83), Pair(-31, 131), Pair(-13, 52),
        Pair(-12, 37), Pair(-20, 37), Pair(17, -28), Pair(17, -34), Pair(19, -10), Pair(-12, 38), Pair(-9, 27), Pair(-18, 53),
        Pair(-14, 45), Pair(17, -17), Pair(6, 1), Pair(0, 0), Pair(-1, -10), Pair(-5, 6), Pair(-7, 118), Pair(-46, 193),
        Pair(24, -6), Pair(1, -37), Pair(6, -30), Pair(0, -16), Pair(-4, -51), Pair(12, -10), Pair(42, 111), Pair(44, 7)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(2, 9), Pair(17, 51), Pair(-9, -48), Pair(-22, -103), Pair(-40, -41), Pair(-11, 0),
        Pair(4, 48), Pair(19, 151), Pair(0, 41), Pair(1, -35), Pair(40, 58), Pair(7, 24), Pair(-3, -37), Pair(3, 12),
        Pair(-19, -12), Pair(64, 27), Pair(16, 68), Pair(15, 37), Pair(-73, -81), Pair(-12, -20), Pair(11, 55), Pair(21, 29),
        Pair(46, -19), Pair(13, 92), Pair(-55, -21), Pair(9, 20), Pair(21, -6), Pair(2, 26), Pair(-108, 70), Pair(28, -71),
        Pair(-35, 35), Pair(19, 8), Pair(-4, 27), Pair(61, -12), Pair(3, 77), Pair(-94, 26), Pair(-17, 6), Pair(4, 25),
        Pair(8, 57), Pair(-12, 96), Pair(60, -41), Pair(-49, 4), Pair(-9, -12), Pair(4, 21), Pair(61, -28), Pair(-7, 20),
        Pair(53, 21), Pair(-38, 48), Pair(-72, 19), Pair(0, 0), Pair(-79, 12), Pair(-4, -1), Pair(-9, 8), Pair(-2, 8),
        Pair(77, -92), Pair(1, 17), Pair(2, 10), Pair(-118, 35), Pair(-13, -23), Pair(-27, 16), Pair(5, -17), Pair(-2, -30)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 26), Pair(43, 17), Pair(-26, 45), Pair(58, -36), Pair(-20, -2), Pair(-108, 37), Pair(-86, 1), Pair(2, 17),
        Pair(-5, 7), Pair(-12, -2), Pair(-16, 24), Pair(-12, 30), Pair(8, 13), Pair(-63, 60), Pair(-31, 43), Pair(5, -2),
        Pair(-2, 8), Pair(-3, 10), Pair(1, 3), Pair(-4, 24), Pair(7, 2), Pair(2, 26), Pair(1, 11), Pair(2, 3),
        Pair(-5, 10), Pair(-5, 11), Pair(-6, 15), Pair(3, 16), Pair(3, 6), Pair(9, 8), Pair(-3, 11), Pair(4, 4),
        Pair(-5, 16), Pair(1, 8), Pair(-9, 15), Pair(7, 31), Pair(-1, -8), Pair(9, 14), Pair(2, 8), Pair(3, 8),
        Pair(-2, 10), Pair(-2, 9), Pair(-7, 1), Pair(3, 26), Pair(-1, -4), Pair(4, 14), Pair(3, -30), Pair(6, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-8, 12), Pair(80, 53), Pair(-11, 20), Pair(125, -24), Pair(-16, 31), Pair(-36, -44), Pair(17, -82), Pair(-99, 28),
        Pair(68, -53), Pair(-31, 46), Pair(-12, 9), Pair(-29, 51), Pair(-20, 10), Pair(6, 2), Pair(98, -69), Pair(-1, -23),
        Pair(75, -56), Pair(-24, 57), Pair(8, 12), Pair(-11, 36), Pair(-68, 51), Pair(-3, 27), Pair(-45, 99), Pair(-2, 33),
        Pair(-42, 56), Pair(15, 17), Pair(-3, 15), Pair(12, 29), Pair(-15, 22), Pair(11, 41), Pair(-10, 21), Pair(16, 70),
        Pair(-1, 42), Pair(14, 23), Pair(6, 15), Pair(-1, 29), Pair(-7, 21), Pair(-1, 40), Pair(-29, 65), Pair(3, 6),
        Pair(8, -6), Pair(12, 28), Pair(9, 29), Pair(-10, 52), Pair(5, 2), Pair(-4, 50), Pair(25, 28), Pair(12, -40),
        Pair(30, 42), Pair(27, -16), Pair(-2, 33), Pair(7, 10), Pair(0, 0), Pair(1, 42), Pair(-18, 41), Pair(-8, 51),
        Pair(-22, 40), Pair(5, 67), Pair(31, 39), Pair(-7, 29), Pair(0, 50), Pair(-7, 53), Pair(-5, 4), Pair(-72, -49)
      },
      { // Piece 2
        Pair(-52, 52), Pair(-52, 36), Pair(42, -34), Pair(-32, -6), Pair(-98, -11), Pair(134, -22), Pair(-24, 24), Pair(41, 27),
        Pair(9, -2), Pair(-27, 31), Pair(-6, 12), Pair(-3, -51), Pair(87, -26), Pair(-14, 41), Pair(-31, 71), Pair(-42, 21),
        Pair(-18, -30), Pair(-21, 23), Pair(3, 13), Pair(24, -21), Pair(12, -18), Pair(-91, 39), Pair(42, 3), Pair(2, -1),
        Pair(2, -14), Pair(-36, 56), Pair(-14, 12), Pair(-16, -3), Pair(-14, 17), Pair(38, -33), Pair(6, -10), Pair(2, -2),
        Pair(-8, 24), Pair(10, -10), Pair(11, 18), Pair(11, 26), Pair(-2, 9), Pair(7, -4), Pair(22, -12), Pair(-1, 50),
        Pair(3, 23), Pair(7, 40), Pair(6, 5), Pair(0, 40), Pair(-10, 0), Pair(6, 0), Pair(-7, -6), Pair(-2, -25),
        Pair(-17, 16), Pair(8, 19), Pair(2, 5), Pair(-5, 26), Pair(0, 0), Pair(9, 18), Pair(-6, 3), Pair(18, -63),
        Pair(15, 26), Pair(42, 44), Pair(-2, 19), Pair(66, -103), Pair(-9, 26), Pair(-21, -17), Pair(23, 5), Pair(-33, 27)
      },
      { // Piece 3
        Pair(98, -11), Pair(9, 20), Pair(40, -3), Pair(-14, 2), Pair(20, -13), Pair(-66, 43), Pair(-167, 86), Pair(15, 15),
        Pair(-7, 27), Pair(-12, 19), Pair(12, 25), Pair(-34, 8), Pair(-42, 51), Pair(-127, 81), Pair(-9, 10), Pair(1, 13),
        Pair(-16, 26), Pair(-27, 39), Pair(-37, 38), Pair(32, 6), Pair(-73, 64), Pair(6, -5), Pair(40, 9), Pair(32, -8),
        Pair(7, 22), Pair(0, 28), Pair(3, 17), Pair(20, -17), Pair(-51, 25), Pair(-9, 47), Pair(40, -17), Pair(56, 13),
        Pair(7, 20), Pair(-3, 30), Pair(-3, 35), Pair(-11, 10), Pair(93, -51), Pair(4, 9), Pair(33, -15), Pair(23, 40),
        Pair(22, -9), Pair(8, -2), Pair(-18, 48), Pair(-21, 39), Pair(-9, -1), Pair(-12, 28), Pair(-3, 14), Pair(42, 5),
        Pair(-24, 52), Pair(-9, 26), Pair(1, 17), Pair(-25, 28), Pair(0, 0), Pair(-21, -27), Pair(23, -68), Pair(44, -70),
        Pair(-1, 17), Pair(0, 7), Pair(0, 16), Pair(-4, 2), Pair(-1, -19), Pair(-8, 16), Pair(-5, 18), Pair(9, -11)
      },
      { // Piece 4
        Pair(15, 36), Pair(-17, 36), Pair(-9, 27), Pair(19, -42), Pair(12, 34), Pair(79, 61), Pair(62, 22), Pair(-153, 88),
        Pair(-21, 33), Pair(-15, 51), Pair(-3, 12), Pair(-40, 36), Pair(37, -39), Pair(46, 109), Pair(-103, 92), Pair(-5, 40),
        Pair(-25, 46), Pair(-44, 91), Pair(-15, 94), Pair(16, 109), Pair(1, 15), Pair(-48, 62), Pair(-2, -13), Pair(-29, 69),
        Pair(-5, 69), Pair(-17, 54), Pair(6, -18), Pair(-9, -13), Pair(-12, 28), Pair(-18, 79), Pair(0, 29), Pair(-18, -21),
        Pair(5, 18), Pair(7, 5), Pair(7, -22), Pair(-8, 18), Pair(-41, 93), Pair(-18, 30), Pair(-36, 67), Pair(-42, 101),
        Pair(24, -6), Pair(0, 31), Pair(-2, 21), Pair(-2, 13), Pair(-5, -18), Pair(-10, 22), Pair(2, 16), Pair(-28, 51),
        Pair(17, -96), Pair(16, -2), Pair(6, -3), Pair(-3, 29), Pair(0, 0), Pair(-16, -33), Pair(2, -51), Pair(-33, 90),
        Pair(-21, 76), Pair(9, -13), Pair(-7, -6), Pair(-1, -22), Pair(-17, -48), Pair(37, 30), Pair(-13, 65), Pair(42, -34)
      },
      { // Piece 5
        Pair(14, 87), Pair(-14, -16), Pair(36, 83), Pair(21, 89), Pair(-16, -59), Pair(-4, 18), Pair(4, 5), Pair(-9, -33),
        Pair(-16, 22), Pair(17, 53), Pair(19, 100), Pair(-32, -6), Pair(-3, -71), Pair(-42, 22), Pair(6, 74), Pair(-6, -33),
        Pair(-37, -32), Pair(-62, 1), Pair(40, 29), Pair(-74, 46), Pair(20, 84), Pair(-65, 52), Pair(-48, -7), Pair(22, 89),
        Pair(-12, -25), Pair(24, -27), Pair(15, 76), Pair(-77, 19), Pair(-3, 7), Pair(9, 0), Pair(23, -22), Pair(-26, 28),
        Pair(23, 44), Pair(19, -29), Pair(-73, 19), Pair(-2, 29), Pair(60, -6), Pair(99, -7), Pair(-131, 16), Pair(-25, 16),
        Pair(5, -35), Pair(-7, 35), Pair(39, 1), Pair(-7, -8), Pair(-8, -7), Pair(26, -28), Pair(17, 18), Pair(35, -21),
        Pair(-50, 6), Pair(-40, -1), Pair(-8, 4), Pair(-32, -6), Pair(0, 0), Pair(-68, 15), Pair(11, -9), Pair(8, 15),
        Pair(-16, -28), Pair(-4, -40), Pair(-9, 22), Pair(-38, 20), Pair(-39, 24), Pair(-29, 10), Pair(5, -16), Pair(3, -11)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 5), Pair(-24, 19), Pair(-18, -2), Pair(-8, 4), Pair(-22, 24), Pair(-25, 3), Pair(-14, 25), Pair(-22, 4),
        Pair(-9, 13), Pair(-7, 14), Pair(4, 9), Pair(-4, 11), Pair(4, 11), Pair(-9, 14), Pair(-16, 15), Pair(8, 0),
        Pair(-3, 14), Pair(2, 9), Pair(5, 8), Pair(-1, 9), Pair(-4, 12), Pair(3, 12), Pair(-3, 12), Pair(-3, 8),
        Pair(-4, 13), Pair(1, 11), Pair(-2, 9), Pair(1, 10), Pair(1, 14), Pair(4, 7), Pair(5, 13), Pair(2, 5),
        Pair(-1, 13), Pair(2, 15), Pair(1, 7), Pair(-4, 12), Pair(9, 21), Pair(4, -6), Pair(14, 14), Pair(1, 6),
        Pair(-2, 14), Pair(0, 13), Pair(-2, 12), Pair(-8, 13), Pair(4, 14), Pair(6, -1), Pair(3, 5), Pair(1, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(45, -42), Pair(43, -10), Pair(81, 17), Pair(82, 0), Pair(32, -11), Pair(30, 24), Pair(-46, -7), Pair(-28, 51),
        Pair(-2, 13), Pair(5, 18), Pair(-11, 19), Pair(6, 18), Pair(-23, 51), Pair(-54, 28), Pair(-16, 34), Pair(11, 30),
        Pair(15, 30), Pair(6, 29), Pair(13, 23), Pair(-19, 38), Pair(11, 25), Pair(-10, 27), Pair(-2, 41), Pair(5, -15),
        Pair(-20, 44), Pair(6, 32), Pair(9, 27), Pair(-7, 28), Pair(3, 26), Pair(-17, 17), Pair(-9, 43), Pair(-2, 36),
        Pair(-9, 33), Pair(8, 39), Pair(6, 28), Pair(10, 31), Pair(4, 29), Pair(2, 30), Pair(-5, 35), Pair(-13, 27),
        Pair(12, 18), Pair(11, 30), Pair(2, 30), Pair(2, 34), Pair(7, 34), Pair(-1, 20), Pair(3, 32), Pair(-14, 6),
        Pair(-10, 20), Pair(-11, 30), Pair(3, 30), Pair(3, 29), Pair(0, 41), Pair(0, 0), Pair(3, 28), Pair(0, 13),
        Pair(-39, -6), Pair(9, 19), Pair(-5, 51), Pair(-10, 30), Pair(4, 38), Pair(-4, 51), Pair(4, -6), Pair(-107, 37)
      },
      { // Piece 2
        Pair(-8, 17), Pair(-13, 12), Pair(92, -12), Pair(-20, 3), Pair(72, -18), Pair(-14, 25), Pair(38, -9), Pair(17, 16),
        Pair(3, 4), Pair(-11, 16), Pair(0, 21), Pair(14, -3), Pair(26, 22), Pair(-46, 37), Pair(-16, 21), Pair(3, 14),
        Pair(-8, 5), Pair(3, 6), Pair(22, 5), Pair(10, -5), Pair(-19, 29), Pair(7, 5), Pair(-10, 19), Pair(-23, 21),
        Pair(-20, 22), Pair(10, 3), Pair(7, 6), Pair(12, 17), Pair(1, 16), Pair(18, -1), Pair(4, -1), Pair(-7, 19),
        Pair(14, 16), Pair(-18, 16), Pair(10, 14), Pair(-7, 25), Pair(9, 22), Pair(-11, 20), Pair(14, 6), Pair(-15, -2),
        Pair(-3, 17), Pair(2, 18), Pair(-10, 20), Pair(6, 16), Pair(0, 32), Pair(11, 14), Pair(-3, 7), Pair(0, 21),
        Pair(10, 12), Pair(-4, 24), Pair(7, 22), Pair(-9, 28), Pair(12, 14), Pair(0, 0), Pair(4, 28), Pair(-21, 24),
        Pair(12, -7), Pair(16, -4), Pair(-9, 27), Pair(1, 15), Pair(-12, 9), Pair(12, 27), Pair(-72, -98), Pair(39, -23)
      },
      { // Piece 3
        Pair(20, 26), Pair(26, 20), Pair(54, 18), Pair(17, 40), Pair(50, 18), Pair(74, 0), Pair(24, 5), Pair(57, 11),
        Pair(20, 26), Pair(5, 32), Pair(-11, 34), Pair(1, 39), Pair(1, 31), Pair(50, 10), Pair(-33, 44), Pair(21, 18),
        Pair(11, 32), Pair(34, 29), Pair(19, 31), Pair(11, 37), Pair(3, 29), Pair(31, 32), Pair(-42, 41), Pair(-3, 36),
        Pair(9, 31), Pair(21, 27), Pair(11, 28), Pair(23, 25), Pair(-5, 28), Pair(30, 16), Pair(-20, 42), Pair(30, 24),
        Pair(10, 36), Pair(29, 18), Pair(10, 40), Pair(24, 34), Pair(5, 38), Pair(47, -1), Pair(4, 37), Pair(20, 24),
        Pair(6, 44), Pair(2, 31), Pair(0, 31), Pair(4, 34), Pair(13, 35), Pair(23, 8), Pair(-7, 25), Pair(-25, 42),
        Pair(4, 31), Pair(13, 8), Pair(11, 25), Pair(4, 29), Pair(-1, 24), Pair(0, 0), Pair(-29, 7), Pair(-34, 20),
        Pair(9, 28), Pair(8, 32), Pair(12, 27), Pair(9, 25), Pair(3, 28), Pair(-7, 15), Pair(-9, 20), Pair(1, 20)
      },
      { // Piece 4
        Pair(29, 63), Pair(50, 22), Pair(36, 40), Pair(70, 27), Pair(48, 12), Pair(-44, 57), Pair(23, 5), Pair(-27, 90),
        Pair(-12, 38), Pair(5, 49), Pair(-14, 80), Pair(8, 36), Pair(17, 53), Pair(-2, 18), Pair(4, 85), Pair(-1, 113),
        Pair(6, 49), Pair(8, 21), Pair(-3, 69), Pair(-10, 91), Pair(-18, 83), Pair(-56, 104), Pair(-10, 78), Pair(-15, 71),
        Pair(-19, 67), Pair(0, 76), Pair(-5, 41), Pair(0, 59), Pair(-14, 55), Pair(-20, 76), Pair(-8, 53), Pair(-26, 93),
        Pair(9, 78), Pair(6, 43), Pair(17, 44), Pair(0, 39), Pair(15, 30), Pair(-8, 51), Pair(2, 44), Pair(-12, 54),
        Pair(18, 25), Pair(11, 55), Pair(4, 57), Pair(10, 43), Pair(9, 56), Pair(1, 31), Pair(-10, 64), Pair(-3, 43),
        Pair(4, 42), Pair(23, 30), Pair(8, 57), Pair(8, 50), Pair(11, 46), Pair(0, 0), Pair(18, -25), Pair(45, -31),
        Pair(6, 83), Pair(2, 92), Pair(20, 28), Pair(8, 56), Pair(0, 29), Pair(9, 9), Pair(63, -47), Pair(18, 21)
      },
      { // Piece 5
        Pair(-8, -7), Pair(39, -51), Pair(-28, 74), Pair(53, 92), Pair(13, -14), Pair(1, 152), Pair(-61, -6), Pair(-19, 8),
        Pair(-102, 15), Pair(45, -30), Pair(-65, 86), Pair(-5, -21), Pair(-81, 96), Pair(-31, 89), Pair(-138, 76), Pair(-26, 22),
        Pair(30, 31), Pair(42, 23), Pair(-29, 27), Pair(-10, 48), Pair(-27, 23), Pair(-6, 46), Pair(-7, 84), Pair(-31, 1),
        Pair(-122, 24), Pair(-109, -6), Pair(-241, 47), Pair(-111, 44), Pair(5, 40), Pair(-71, 58), Pair(70, 18), Pair(-23, 28),
        Pair(-38, 9), Pair(7, 15), Pair(-129, 54), Pair(-73, 29), Pair(23, 12), Pair(-48, 33), Pair(80, 5), Pair(19, 7),
        Pair(-49, 1), Pair(-55, 19), Pair(-53, 29), Pair(-39, 27), Pair(-43, -3), Pair(-2, -7), Pair(-19, -16), Pair(28, -1),
        Pair(-14, -3), Pair(1, 17), Pair(-10, 13), Pair(-15, 10), Pair(-6, 0), Pair(0, 0), Pair(22, -16), Pair(30, -2),
        Pair(-9, 1), Pair(-1, -12), Pair(-4, 1), Pair(-19, 11), Pair(-4, -7), Pair(-42, 15), Pair(6, 3), Pair(28, 0)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, 17), Pair(14, 2), Pair(-18, 11), Pair(-2, 8), Pair(21, -13), Pair(-20, 8), Pair(-17, 22), Pair(-44, 19),
        Pair(3, 12), Pair(-2, 12), Pair(-16, 16), Pair(13, -1), Pair(-15, 10), Pair(-9, 10), Pair(16, -14), Pair(10, 2),
        Pair(4, 12), Pair(4, 10), Pair(1, 8), Pair(-1, 9), Pair(0, 8), Pair(-13, 7), Pair(4, 3), Pair(-2, 7),
        Pair(3, 12), Pair(-1, 12), Pair(-1, 12), Pair(0, 11), Pair(-1, 10), Pair(-1, 12), Pair(7, -2), Pair(0, 9),
        Pair(0, 12), Pair(-1, 12), Pair(2, 12), Pair(3, 8), Pair(2, 9), Pair(10, 16), Pair(-11, 1), Pair(9, 10),
        Pair(-2, 15), Pair(3, 14), Pair(-4, 13), Pair(-5, 21), Pair(2, -30), Pair(4, 7), Pair(5, 1), Pair(-2, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-44, 48), Pair(-67, 69), Pair(100, -8), Pair(9, 39), Pair(-47, 31), Pair(19, 7), Pair(-37, 5), Pair(82, 16),
        Pair(-32, 14), Pair(-23, 43), Pair(27, 8), Pair(20, 27), Pair(-1, 17), Pair(60, -25), Pair(16, 1), Pair(13, -11),
        Pair(-34, 27), Pair(-28, 38), Pair(7, 34), Pair(-6, 35), Pair(-4, 20), Pair(-28, 23), Pair(-12, 2), Pair(14, -30),
        Pair(-5, 19), Pair(8, 14), Pair(9, 27), Pair(9, 24), Pair(3, 22), Pair(17, 27), Pair(6, 14), Pair(-11, 35),
        Pair(-1, 20), Pair(-7, 35), Pair(4, 26), Pair(1, 29), Pair(7, 13), Pair(7, 27), Pair(9, 9), Pair(6, 6),
        Pair(-7, 28), Pair(10, 12), Pair(3, 28), Pair(5, 32), Pair(0, 21), Pair(5, 31), Pair(-3, 12), Pair(-4, 5),
        Pair(-12, 37), Pair(-9, 26), Pair(-12, 30), Pair(3, 29), Pair(-10, 27), Pair(-21, 40), Pair(0, 0), Pair(-7, 14),
        Pair(-40, 106), Pair(-15, 31), Pair(17, 13), Pair(4, 24), Pair(7, 7), Pair(1, 24), Pair(-3, 47), Pair(-5, 165)
      },
      { // Piece 2
        Pair(-61, -18), Pair(-28, -8), Pair(-47, 12), Pair(49, 11), Pair(8, 19), Pair(42, -17), Pair(60, -31), Pair(-14, 18),
        Pair(16, 3), Pair(-25, 1), Pair(14, -1), Pair(44, -29), Pair(32, -8), Pair(19, -19), Pair(2, 0), Pair(-42, 2),
        Pair(-8, 2), Pair(9, 9), Pair(39, -13), Pair(25, 13), Pair(-2, 2), Pair(6, 21), Pair(4, -8), Pair(13, 9),
        Pair(13, 9), Pair(-4, 8), Pair(-3, 16), Pair(-17, 16), Pair(3, 17), Pair(5, 9), Pair(17, -3), Pair(-4, 3),
        Pair(1, 19), Pair(17, 22), Pair(1, 13), Pair(10, 19), Pair(0, 16), Pair(3, 12), Pair(-6, 7), Pair(-8, 15),
        Pair(9, 5), Pair(0, -3), Pair(0, 23), Pair(-3, 12), Pair(1, 19), Pair(-4, 13), Pair(-6, 5), Pair(-31, 1),
        Pair(-15, 1), Pair(5, 26), Pair(-1, 6), Pair(4, 23), Pair(-12, 16), Pair(16, 4), Pair(0, 0), Pair(0, -4),
        Pair(21, 16), Pair(-1, 7), Pair(8, 19), Pair(-9, 17), Pair(0, 45), Pair(-18, 10), Pair(40, 31), Pair(0, 0)
      },
      { // Piece 3
        Pair(26, 27), Pair(24, 31), Pair(8, 40), Pair(31, 20), Pair(17, 28), Pair(34, 24), Pair(-14, 35), Pair(63, 2),
        Pair(18, 29), Pair(16, 28), Pair(23, 20), Pair(-2, 34), Pair(39, 13), Pair(48, 1), Pair(21, 6), Pair(-15, 36),
        Pair(12, 26), Pair(19, 26), Pair(12, 26), Pair(-6, 29), Pair(7, 22), Pair(19, 3), Pair(-2, 2), Pair(14, 23),
        Pair(0, 29), Pair(5, 24), Pair(6, 30), Pair(-6, 35), Pair(30, 17), Pair(1, 32), Pair(28, 9), Pair(0, 31),
        Pair(24, 29), Pair(-7, 26), Pair(12, 35), Pair(3, 35), Pair(14, 25), Pair(23, 33), Pair(48, -11), Pair(-2, 36),
        Pair(4, 28), Pair(4, 33), Pair(0, 30), Pair(0, 28), Pair(8, 30), Pair(12, 19), Pair(8, 5), Pair(-18, 43),
        Pair(11, 38), Pair(2, 28), Pair(19, 14), Pair(3, 24), Pair(1, 32), Pair(-1, 34), Pair(0, 0), Pair(-24, -11),
        Pair(8, 30), Pair(18, 17), Pair(9, 20), Pair(10, 24), Pair(11, 25), Pair(4, 24), Pair(-12, 4), Pair(-12, 13)
      },
      { // Piece 4
        Pair(-7, 25), Pair(17, 46), Pair(-14, 56), Pair(56, 32), Pair(53, -1), Pair(43, 32), Pair(59, -21), Pair(33, 41),
        Pair(3, 40), Pair(-4, 43), Pair(-5, 54), Pair(-24, 70), Pair(19, 40), Pair(38, 14), Pair(75, 21), Pair(16, 51),
        Pair(2, 46), Pair(-14, 70), Pair(-3, 61), Pair(-4, 64), Pair(-12, 24), Pair(25, 23), Pair(30, 21), Pair(8, 45),
        Pair(19, 52), Pair(-12, 50), Pair(-1, 58), Pair(22, 16), Pair(0, 48), Pair(-24, 65), Pair(2, 75), Pair(7, 32),
        Pair(15, 35), Pair(15, 47), Pair(10, 42), Pair(-1, 38), Pair(22, 27), Pair(-8, 49), Pair(9, 32), Pair(-16, 53),
        Pair(17, 28), Pair(22, 52), Pair(10, 63), Pair(18, 32), Pair(8, 51), Pair(6, 40), Pair(4, 39), Pair(-5, 7),
        Pair(33, 8), Pair(15, 40), Pair(14, 49), Pair(12, 70), Pair(16, 37), Pair(9, 46), Pair(0, 0), Pair(1, 58),
        Pair(10, 81), Pair(11, 56), Pair(8, 34), Pair(9, 54), Pair(10, 40), Pair(22, -15), Pair(-7, 29), Pair(2, -47)
      },
      { // Piece 5
        Pair(28, 116), Pair(-64, 126), Pair(-36, 2), Pair(-51, 10), Pair(10, 95), Pair(44, -28), Pair(3, 15), Pair(-16, -12),
        Pair(-80, 0), Pair(12, 9), Pair(18, 60), Pair(27, 20), Pair(-18, 33), Pair(-14, 65), Pair(-14, 43), Pair(49, 78),
        Pair(-80, 10), Pair(12, 19), Pair(-1, 32), Pair(-165, 66), Pair(-115, 80), Pair(-133, 64), Pair(0, 36), Pair(-42, 52),
        Pair(-159, 11), Pair(-108, 44), Pair(-79, 34), Pair(-46, 32), Pair(-55, 39), Pair(-142, 49), Pair(-81, 51), Pair(0, 27),
        Pair(32, 10), Pair(-95, 29), Pair(-35, 22), Pair(0, 39), Pair(2, 25), Pair(-36, 24), Pair(58, 8), Pair(19, 12),
        Pair(-169, 19), Pair(19, 3), Pair(-22, 22), Pair(-58, 30), Pair(13, 9), Pair(-58, 6), Pair(-12, 4), Pair(-5, -36),
        Pair(-46, -8), Pair(-39, 16), Pair(-23, 18), Pair(-15, 17), Pair(-6, 5), Pair(-13, -11), Pair(0, 0), Pair(-1, -6),
        Pair(-26, -33), Pair(-29, -1), Pair(-18, 3), Pair(-1, 2), Pair(24, -7), Pair(-20, 5), Pair(6, -2), Pair(-14, -9)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, 16), Pair(-20, 21), Pair(-12, 11), Pair(-38, 11), Pair(-28, 8), Pair(34, -20), Pair(-2, 21), Pair(48, 7),
        Pair(2, 12), Pair(-1, 7), Pair(-2, 9), Pair(-5, 7), Pair(-6, 10), Pair(-8, 4), Pair(20, -18), Pair(-2, 9),
        Pair(1, 10), Pair(0, 7), Pair(3, 7), Pair(1, 3), Pair(-2, 6), Pair(-5, 8), Pair(-11, 16), Pair(11, 9),
        Pair(0, 11), Pair(4, 11), Pair(-1, 9), Pair(2, 6), Pair(0, 0), Pair(-4, 4), Pair(-2, 9), Pair(15, 3),
        Pair(-1, 9), Pair(1, 12), Pair(1, 11), Pair(-2, 10), Pair(5, 4), Pair(-2, 4), Pair(2, 15), Pair(-9, 6),
        Pair(-1, 12), Pair(1, 12), Pair(-2, 9), Pair(0, 13), Pair(6, 13), Pair(-2, 5), Pair(-2, 4), Pair(3, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(45, -16), Pair(-48, 61), Pair(-71, 57), Pair(-14, -29), Pair(7, 19), Pair(15, -20), Pair(27, -27), Pair(39, -27),
        Pair(-29, 17), Pair(-52, 43), Pair(0, 25), Pair(13, 28), Pair(1, 0), Pair(17, 3), Pair(13, 58), Pair(-34, 31),
        Pair(1, -2), Pair(-7, 35), Pair(-5, 26), Pair(4, 15), Pair(-8, 26), Pair(4, 10), Pair(-21, 6), Pair(35, -19),
        Pair(-7, 29), Pair(5, 23), Pair(4, 32), Pair(8, 23), Pair(5, 24), Pair(11, 16), Pair(-4, 24), Pair(-14, 35),
        Pair(4, 18), Pair(-10, 46), Pair(10, 22), Pair(10, 26), Pair(-6, 34), Pair(-4, 38), Pair(29, -1), Pair(-9, 14),
        Pair(-9, 39), Pair(-1, 25), Pair(-3, 27), Pair(0, 27), Pair(2, 42), Pair(0, 26), Pair(8, 27), Pair(-31, 24),
        Pair(-16, 37), Pair(-31, 16), Pair(2, 19), Pair(-4, 32), Pair(-8, 36), Pair(-3, 29), Pair(7, -3), Pair(0, 0),
        Pair(29, -1), Pair(-14, 10), Pair(-15, 27), Pair(-34, 32), Pair(-4, 24), Pair(-12, 14), Pair(-9, 34), Pair(-3, 33)
      },
      { // Piece 2
        Pair(39, -3), Pair(31, -4), Pair(-2, -2), Pair(-57, 11), Pair(65, -24), Pair(-3, 49), Pair(-73, 75), Pair(50, 15),
        Pair(-1, 23), Pair(9, 8), Pair(6, 2), Pair(12, 8), Pair(-18, 9), Pair(36, -9), Pair(-16, 12), Pair(10, 16),
        Pair(14, 6), Pair(24, 17), Pair(14, 14), Pair(-13, 13), Pair(14, 14), Pair(33, -11), Pair(19, 8), Pair(3, 22),
        Pair(-7, 22), Pair(0, 7), Pair(19, 7), Pair(15, 19), Pair(7, 14), Pair(26, 14), Pair(-11, 16), Pair(0, 21),
        Pair(0, 13), Pair(8, 4), Pair(10, 18), Pair(2, 18), Pair(8, 33), Pair(-6, 19), Pair(17, -2), Pair(17, 1),
        Pair(-7, 28), Pair(-1, 32), Pair(-1, 25), Pair(6, 21), Pair(-1, 33), Pair(-6, 27), Pair(0, 27), Pair(6, 2),
        Pair(34, -9), Pair(0, 30), Pair(6, 25), Pair(0, 32), Pair(-6, 39), Pair(1, 22), Pair(3, 23), Pair(0, 0),
        Pair(14, -9), Pair(-9, -15), Pair(-2, 24), Pair(-8, 35), Pair(25, 21), Pair(6, 18), Pair(6, 33), Pair(7, 19)
      },
      { // Piece 3
        Pair(11, 46), Pair(-7, 30), Pair(39, 35), Pair(39, 43), Pair(-16, 46), Pair(48, 36), Pair(-71, 30), Pair(-9, 17),
        Pair(7, 40), Pair(6, 44), Pair(7, 41), Pair(15, 34), Pair(28, 22), Pair(21, 35), Pair(19, 35), Pair(-31, 23),
        Pair(10, 35), Pair(17, 39), Pair(9, 36), Pair(-15, 47), Pair(36, 31), Pair(32, 29), Pair(11, 13), Pair(26, 10),
        Pair(-6, 44), Pair(14, 46), Pair(5, 41), Pair(35, 21), Pair(16, 25), Pair(44, 24), Pair(9, 43), Pair(-4, 33),
        Pair(1, 42), Pair(-8, 31), Pair(-9, 60), Pair(35, 18), Pair(6, 45), Pair(11, 25), Pair(0, 44), Pair(-18, 33),
        Pair(33, 36), Pair(-2, 42), Pair(5, 46), Pair(-15, 52), Pair(1, 36), Pair(8, 26), Pair(-6, 52), Pair(-14, 10),
        Pair(-6, 55), Pair(-14, 45), Pair(8, 31), Pair(3, 31), Pair(-12, 48), Pair(-9, 38), Pair(0, 27), Pair(0, 0),
        Pair(7, 36), Pair(11, 37), Pair(9, 32), Pair(7, 35), Pair(11, 33), Pair(15, 37), Pair(-5, 51), Pair(-15, 7)
      },
      { // Piece 4
        Pair(-19, 26), Pair(54, 17), Pair(-46, 93), Pair(89, -5), Pair(0, 54), Pair(44, -47), Pair(-13, 28), Pair(-75, 133),
        Pair(24, 42), Pair(3, 24), Pair(8, 27), Pair(17, 13), Pair(11, 46), Pair(10, 80), Pair(-10, 68), Pair(7, 45),
        Pair(14, 18), Pair(-15, 37), Pair(21, 54), Pair(8, 47), Pair(20, 39), Pair(39, -2), Pair(36, 59), Pair(-1, 52),
        Pair(11, 39), Pair(35, -17), Pair(-2, 71), Pair(-7, 71), Pair(5, 19), Pair(5, 55), Pair(8, 57), Pair(17, 10),
        Pair(19, 30), Pair(5, 59), Pair(17, 51), Pair(-6, 54), Pair(8, 37), Pair(-13, 74), Pair(15, 28), Pair(19, 11),
        Pair(18, 17), Pair(11, 60), Pair(-1, 74), Pair(11, 44), Pair(7, 57), Pair(0, 60), Pair(4, 56), Pair(14, 55),
        Pair(30, 29), Pair(4, 74), Pair(6, 60), Pair(7, 59), Pair(8, 42), Pair(15, 12), Pair(18, 51), Pair(0, 0),
        Pair(13, 40), Pair(-4, 36), Pair(-4, 65), Pair(9, 47), Pair(10, 39), Pair(27, 8), Pair(-8, -5), Pair(-10, -98)
      },
      { // Piece 5
        Pair(-28, 5), Pair(-127, 48), Pair(-42, 38), Pair(-24, 90), Pair(11, 54), Pair(41, 54), Pair(38, 71), Pair(-27, 5),
        Pair(-19, 25), Pair(-94, 95), Pair(117, 84), Pair(-42, 39), Pair(-77, 113), Pair(19, 54), Pair(-22, 54), Pair(-42, 13),
        Pair(-102, 28), Pair(31, 24), Pair(7, 39), Pair(-51, 56), Pair(-159, 67), Pair(-83, 87), Pair(-149, 46), Pair(-60, 79),
        Pair(-18, 24), Pair(-48, 30), Pair(-19, 35), Pair(-51, 41), Pair(-135, 46), Pair(-19, 32), Pair(39, 39), Pair(-27, 17),
        Pair(-25, 24), Pair(-94, 42), Pair(-137, 49), Pair(6, 29), Pair(-72, 31), Pair(52, 8), Pair(28, 11), Pair(-35, 4),
        Pair(-76, 10), Pair(-119, 56), Pair(-108, 54), Pair(4, 27), Pair(0, 23), Pair(7, 3), Pair(-2, -15), Pair(-22, -14),
        Pair(-62, 30), Pair(-35, 23), Pair(-26, 32), Pair(-11, 18), Pair(-9, 14), Pair(4, 1), Pair(-21, -26), Pair(0, 0),
        Pair(-31, 58), Pair(-23, 25), Pair(-24, 13), Pair(-32, 27), Pair(12, 1), Pair(22, -7), Pair(6, -25), Pair(18, -50)
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

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(15, 66), Pair(20, 54), Pair(23, 58), Pair(24, 64), Pair(24, 71), Pair(26, 78), Pair(29, 81), Pair(35, 80),
  Pair(44, 72)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-9, 23), Pair(-1, -9), Pair(3, 8), Pair(5, 20), Pair(8, 29), Pair(11, 36), Pair(11, 39), Pair(12, 40),
  Pair(14, 45), Pair(23, 40), Pair(33, 37), Pair(53, 27), Pair(76, 34), Pair(37, 19)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-41, -66), Pair(-31, -59), Pair(-26, -27), Pair(-23, -3), Pair(-23, 12), Pair(-19, 14), Pair(-14, 18), Pair(-10, 24),
  Pair(-6, 26), Pair(0, 29), Pair(5, 31), Pair(4, 35), Pair(10, 35), Pair(35, 20), Pair(62, 3)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-31, 192), Pair(2, 182), Pair(-5, 112), Pair(1, 86), Pair(1, 125), Pair(0, 140), Pair(2, 168), Pair(4, 171),
  Pair(6, 176), Pair(6, 187), Pair(8, 189), Pair(10, 190), Pair(10, 189), Pair(15, 186), Pair(15, 181), Pair(13, 184),
  Pair(22, 166), Pair(22, 160), Pair(35, 137), Pair(25, 139), Pair(44, 107), Pair(48, 98), Pair(99, 59), Pair(110, 36),
  Pair(-39, 125), Pair(139, 8), Pair(171, 2), Pair(192, -14)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-27, -102), Pair(-19, -86), Pair(-10, -58), Pair(15, -21), Pair(13, 48), Pair(153, 152), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 8), Pair(18, 14), Pair(16, 34), Pair(43, 91), Pair(139, 170), Pair(10, 363), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(8, -3), Pair(4, 15), Pair(16, 33), Pair(43, 58), Pair(227, 102), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-26, -55), Pair(-10, -21), Pair(3, 2), Pair(-13, -14), Pair(-12, -8), Pair(-12, -12), Pair(-8, -7), Pair(-18, -42)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-4, -6), Pair(-12, -8), Pair(-9, -8), Pair(-6, -5), Pair(-5, -6), Pair(-1, -10), Pair(-9, -7), Pair(-2, -12)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(8, -17), Pair(19, -11), Pair(25, -11), Pair(32, -8), Pair(35, -9), Pair(58, -13), Pair(54, -18), Pair(14, -6)
  },
  {
      Pair(-8, 5), Pair(0, 7), Pair(12, -5), Pair(19, 2), Pair(20, -11), Pair(22, -11), Pair(26, -15), Pair(-12, 5)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(19, -8), Pair(34, -11), Pair(24, -8),
  Pair(43, -13), Pair(44, -14), Pair(41, -13),
  Pair(62, -1), Pair(0, 0), Pair(57, -1),
  Pair(34, 22), Pair(9, 15), Pair(37, 24)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-5, -5), Pair(-14, 12), Pair(-6, -1),
  Pair(-7, -2), Pair(-19, 2), Pair(-6, -2),
  Pair(1, -12), Pair(-9, -6), Pair(6, -14),
  Pair(14, -13), Pair(2, -8), Pair(21, -15),
  Pair(62, -24), Pair(64, -23), Pair(52, -20),
  Pair(-12, -35), Pair(-17, -59), Pair(99, -60),
  Pair(50, -79), Pair(0, 0), Pair(46, -77)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-1, 86), Pair(-7, 76), Pair(-3, 63), Pair(2, 53), Pair(2, 42), Pair(10, 40), Pair(12, 32)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-2, -3), Pair(-20, 25), Pair(-5, 46), Pair(0, 58), Pair(8, 61), Pair(13, 71), Pair(12, 80)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-583, 87);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-51, -47), Pair(-14, -29), Pair(-26, -13), Pair(-56, -8), Pair(-27, -4), Pair(-45, 0), Pair(-20, -1), Pair(-30, -24)
  },
  {
      Pair(-57, 18), Pair(13, 15), Pair(-2, 7), Pair(-43, 18), Pair(-11, 11), Pair(-35, 22), Pair(0, 21), Pair(-20, 7)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(24, 0), Pair(38, -5), Pair(92, -26), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 2), Pair(34, -3), Pair(66, -12), Pair(88, -33), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(24, -12), Pair(40, -12), Pair(68, -12), Pair(122, -21), Pair(183, -40), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 23), Pair(25, 43), Pair(49, 54), Pair(117, 39), Pair(149, 53), Pair(267, 3), Pair(523, -59)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(32, 3), Pair(6, 5), Pair(31, -5), Pair(18, 19), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-7, 34), Pair(-3, 38)
  },
  {
      Pair(-52, -26), Pair(-42, -33)
  },
  {
      Pair(-57, -36), Pair(-53, -68)
  },
  {
      Pair(-56, 8), Pair(-55, -11)
  },
  {
      Pair(-67, 44), Pair(-77, 55)
  },
  {
      Pair(63, 31), Pair(-99, 60)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(12, 27), Pair(11, 19), Pair(12, 26), Pair(10, 12), Pair(13, -3)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-8, -31), Pair(2, -14)
  },
  {
      Pair(-8, -12), Pair(-2, -21)
  },
  {
      Pair(-27, -40), Pair(-23, -51)
  },
  {
      Pair(-57, -17), Pair(-46, -31)
  },
  {
      Pair(-43, -29), Pair(-48, -4)
  },
  {
      Pair(-94, -15), Pair(-20, -57)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-9, -15), Pair(1, -2)
  },
  {
      Pair(-34, -30), Pair(-21, -45)
  },
  {
      Pair(-13, -16), Pair(-11, -23)
  },
  {
      Pair(-48, -20), Pair(-36, -42)
  },
  {
      Pair(-37, -24), Pair(-37, -17)
  },
  {
      Pair(-46, -7), Pair(-12, -39)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-3, -15), Pair(6, 4)
  },
  {
      Pair(-23, -24), Pair(0, -8)
  },
  {
      Pair(-29, -20), Pair(-5, -3)
  },
  {
      Pair(24, -32), Pair(17, -30)
  },
  {
      Pair(-46, -13), Pair(-42, -15)
  },
  {
      Pair(-8, -22), Pair(-10, -46)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(5, 59), Pair(42, 49), Pair(14, 54), Pair(5, 44), Pair(37, 34), Pair(51, 24), Pair(40, 28), Pair(114, 1),
  Pair(21, 4), Pair(13, 26), Pair(7, 25), Pair(16, 8), Pair(5, 22), Pair(11, 38), Pair(14, 43), Pair(33, 43),
  Pair(-1, 22), Pair(6, 18), Pair(13, 30), Pair(7, 20), Pair(-7, 4), Pair(-3, 29), Pair(11, 17), Pair(4, 26)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-33, 0), Pair(34, 15), Pair(29, 8), Pair(50, 12), Pair(50, -36), Pair(71, -16), Pair(66, 11), Pair(-23, -12),
  Pair(-31, -14), Pair(8, -3), Pair(21, -1), Pair(8, 46), Pair(9, 39), Pair(17, 31), Pair(26, -8), Pair(36, -2),
  Pair(55, 3), Pair(-1, 10), Pair(13, 4), Pair(2, 8), Pair(-16, 19), Pair(13, 16), Pair(6, -6), Pair(-56, 23)
};

constexpr ScorePair kBishopPairBonus = Pair(19, 81);

constexpr ScorePair kTempoBonus = Pair(20, 20);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H