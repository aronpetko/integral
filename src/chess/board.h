#ifndef INTEGRAL_BOARD_H_
#define INTEGRAL_BOARD_H_

#include <memory>
#include <optional>
#include <utility>
#include <vector>

#include "../engine/search/transpo.h"
#include "../utils/zobrist.h"
#include "bitboard.h"
#include "fen.h"

constexpr int kMaxMoves = 256;
using MoveList = List<Move, kMaxMoves>;

namespace nnue {

class Accumulator;

}

class CastleRights {
 public:

   enum CastleSide {
    kKingside,
    kQueenside
  };

  // Castling rights are stored as qkQK
  static constexpr U8 CastleIndex(Color turn, CastleSide side) {
    return turn == kWhite ? (side == kKingside ? 3 : 2)
                          : (side == kKingside ? 1 : 0);
  };

  static constexpr std::array<std::array<U8, 2>, 2> kMasks = {
      {{CastleRightMasks::kBlackKingside, CastleRightMasks::kBlackQueenside},
       {CastleRightMasks::kWhiteKingside, CastleRightMasks::kWhiteQueenside}}};

  CastleRights() {
    rights_.fill(kNoSquare);
  }

  bool operator==(const CastleRights &other) const {
    return rights_ == other.rights_;
  }

  [[nodiscard]] constexpr bool CanKingsideCastle(Color turn) const {
    return rights_[CastleIndex(turn, kKingside)] != Squares::kNoSquare;
  }

  [[nodiscard]] constexpr bool CanQueensideCastle(Color turn) const {
    return rights_[CastleIndex(turn, kQueenside)] != Squares::kNoSquare;
  }

  [[nodiscard]] constexpr bool CanCastle(Color turn) const {
    return CanKingsideCastle(turn) || CanQueensideCastle(turn);
  }

  constexpr void SetCastlingRights(Color turn, CastleSide side, Square sq) {
    rights_[CastleIndex(turn, side)] = sq;
  }

  constexpr void SetCanKingsideCastle(Color turn, Square sq) {
    rights_[CastleIndex(turn, kKingside)] = sq;
  }

  constexpr void SetCanQueensideCastle(Color turn, Square sq) {
    rights_[CastleIndex(turn, kQueenside)] = sq;
  }

  constexpr void UnsetCastlingRights(Color turn) {
    SetCanKingsideCastle(turn, kNoSquare);
    SetCanQueensideCastle(turn, kNoSquare);
  }

  [[nodiscard]] std::array<Square, 4>& GetUnderlying() {
    return rights_;
  }

  [[nodiscard]] U8 AsU8() const {
    constexpr U8 blackQ = 0b1;
    constexpr U8 blackK = 0b10;
    constexpr U8 whiteQ = 0b100;
    constexpr U8 whiteK = 0b1000;

    U8 flags = 0;

    if (rights_[CastleIndex(kWhite, kKingside)] != kNoSquare) flags |= whiteK;
    if (rights_[CastleIndex(kWhite, kQueenside)] != kNoSquare) flags |= whiteQ;
    if (rights_[CastleIndex(kBlack, kKingside)] != kNoSquare) flags |= blackK;
    if (rights_[CastleIndex(kBlack, kQueenside)] != kNoSquare) flags |= blackQ;

    return flags;
  }

  [[nodiscard]] Square CastleSq(Color turn, CastleSide side) const {
    return rights_[CastleIndex(turn, side)];
  }

 private:
  std::array<Square, 4> rights_;
};

struct BoardState {
  BoardState()
      : turn(Color::kWhite),
        fifty_moves_clock(0),
        en_passant(Squares::kNoSquare),
        zobrist_key(0ULL),
        pawn_key(0ULL),
        minor_key(0ULL),
        major_key(0ULL),
        non_pawn_keys({}),
        checkers(0ULL),
        pinned({}),
        half_moves(0) {
    piece_on_square.fill(PieceType::kNone);
  }

  template <bool update_key = true>
  void PlacePiece(Square square, PieceType piece_type, Color color) {
    // Add the piece to the bitboards and mailbox
    piece_bbs[piece_type].SetBit(square);
    side_bbs[color].SetBit(square);
    piece_on_square[square] = piece_type;

    // Insert the piece to the hash
    if constexpr (update_key) {
      const int colored_piece = piece_type * 2 + color;
      zobrist_key ^= zobrist::pieces[colored_piece][square];

      if (piece_type == PieceType::kPawn) {
        pawn_key ^= zobrist::pieces[colored_piece][square];
      } else {
        non_pawn_keys[color] ^= zobrist::pieces[colored_piece][square];

        if (piece_type == PieceType::kKing) {
          minor_key ^= zobrist::pieces[colored_piece][square];
          major_key ^= zobrist::pieces[colored_piece][square];
        } else if (piece_type == PieceType::kKnight ||
                   piece_type == PieceType::kBishop) {
          minor_key ^= zobrist::pieces[colored_piece][square];
        } else if (piece_type == PieceType::kRook ||
                   piece_type == PieceType::kQueen) {
          major_key ^= zobrist::pieces[colored_piece][square];
        }
      }
    }
  }

  template <bool update_key = true>
  void RemovePiece(Square square, Color color) {
    auto &piece_type = piece_on_square[square];

    // Remove the piece from the hash
    if constexpr (update_key) {
      const int colored_piece = piece_type * 2 + color;
      zobrist_key ^= zobrist::pieces[colored_piece][square];

      if (piece_type == PieceType::kPawn) {
        pawn_key ^= zobrist::pieces[colored_piece][square];
      } else {
        non_pawn_keys[color] ^= zobrist::pieces[colored_piece][square];

        if (piece_type == PieceType::kKing) {
          minor_key ^= zobrist::pieces[colored_piece][square];
          major_key ^= zobrist::pieces[colored_piece][square];
        }
        if (piece_type == PieceType::kKnight ||
            piece_type == PieceType::kBishop) {
          minor_key ^= zobrist::pieces[colored_piece][square];
        } else if (piece_type == PieceType::kRook ||
                   piece_type == PieceType::kQueen) {
          major_key ^= zobrist::pieces[colored_piece][square];
        }
      }
    }

    // Clear the piece from the bitboards
    piece_bbs[piece_type].ClearBit(square);
    side_bbs[color].ClearBit(square);

    piece_type = PieceType::kNone;
  }

  [[nodiscard]] constexpr Color GetPieceColor(U8 square) const {
    if (side_bbs[Color::kWhite].IsSet(square)) return Color::kWhite;
    if (side_bbs[Color::kBlack].IsSet(square)) return Color::kBlack;
    return Color::kNoColor;
  }

  [[nodiscard]] constexpr PieceType GetPieceType(U8 square) const {
    return piece_on_square[square];
  }

  [[nodiscard]] constexpr int GetPieceAndColor(U8 square) const {
    const auto piece = GetPieceType(square);
    return piece != PieceType::kNone ? piece * 2 + GetPieceColor(square) : -1;
  }

  [[nodiscard]] constexpr bool PieceExists(Square square) const {
    return GetPieceType(square) != PieceType::kNone;
  }

  [[nodiscard]] constexpr BitBoard Occupied() const {
    return side_bbs[Color::kWhite] | side_bbs[Color::kBlack];
  }

  [[nodiscard]] constexpr const BitBoard &Occupied(Color side) const {
    return side_bbs[side];
  }

  [[nodiscard]] constexpr BitBoard KinglessOccupied() const {
    return (side_bbs[Color::kWhite] | side_bbs[Color::kBlack]) &
           ~piece_bbs[kKing];
  }

  [[nodiscard]] constexpr BitBoard KinglessOccupied(Color side) const {
    return side_bbs[side] & ~King(side);
  }

  [[nodiscard]] constexpr BitBoard Pawns(Color side) const {
    return piece_bbs[PieceType::kPawn] & side_bbs[side];
  }

  [[nodiscard]] constexpr const BitBoard &Pawns() const {
    return piece_bbs[PieceType::kPawn];
  }

  [[nodiscard]] constexpr BitBoard Knights(Color side) const {
    return piece_bbs[PieceType::kKnight] & side_bbs[side];
  }

  [[nodiscard]] constexpr const BitBoard &Knights() const {
    return piece_bbs[PieceType::kKnight];
  }

  [[nodiscard]] constexpr BitBoard Bishops(Color side) const {
    return piece_bbs[PieceType::kBishop] & side_bbs[side];
  }

  [[nodiscard]] constexpr const BitBoard &Bishops() const {
    return piece_bbs[PieceType::kBishop];
  }

  [[nodiscard]] constexpr BitBoard Rooks(Color side) const {
    return piece_bbs[PieceType::kRook] & side_bbs[side];
  }

  [[nodiscard]] constexpr const BitBoard &Rooks() const {
    return piece_bbs[PieceType::kRook];
  }

  [[nodiscard]] constexpr BitBoard Queens(Color side) const {
    return piece_bbs[PieceType::kQueen] & side_bbs[side];
  }

  [[nodiscard]] constexpr const BitBoard &Queens() const {
    return piece_bbs[PieceType::kQueen];
  }

  [[nodiscard]] constexpr BitBoard King(Color side) const {
    return piece_bbs[PieceType::kKing] & side_bbs[side];
  }

  [[nodiscard]] constexpr const BitBoard &Kings() const {
    return piece_bbs[PieceType::kKing];
  }

  [[nodiscard]] constexpr bool InCheck() const {
    return checkers != 0;
  }

  [[nodiscard]] constexpr int MaterialCount() const {
    return 1 * Pawns().PopCount() + 3 * Knights().PopCount() +
           3 * Bishops().PopCount() + 5 * Rooks().PopCount() +
           9 * Queens().PopCount();
  }

  std::array<BitBoard, kNumPieceTypes> piece_bbs;
  std::array<BitBoard, 2> side_bbs;
  std::array<PieceType, kSquareCount> piece_on_square;
  Color turn;
  U16 fifty_moves_clock;
  U16 half_moves;
  Square en_passant;
  CastleRights castle_rights;
  U64 zobrist_key, pawn_key, minor_key, major_key;
  std::array<U64, 2> non_pawn_keys;
  BitBoard checkers;
  BitBoard threats;
  std::array<BitBoard, kNumPieceTypes> threatened_by;
  std::array<BitBoard, kNumColors> pinned;
};

class Board {
 public:
  Board();

  Board(const BoardState &state);

  // Copy constructor for deep copy of the accumulator
  Board(const Board &other);

  // Copy assignment operator for deep copy of the accumulator
  Board &operator=(const Board &other);

  inline auto &GetState() {
    return state_;
  }

  inline const auto &GetState() const {
    return state_;
  }

  inline auto &GetStateHistory() {
    return history_;
  }

  inline auto &GetAccumulator() {
    return accumulator_;
  }

  void SetFromFen(std::string_view fen_str);

  void MakeMove(Move move);

  void MakeNullMove();

  void UndoMove();

  void UndoNullMove();

  void PrintPieces();

  [[nodiscard]] bool IsMovePseudoLegal(Move move) const;

  [[nodiscard]] bool IsMoveLegal(Move move) const;

  [[nodiscard]] U64 PredictKeyAfter(Move move) const;

  [[nodiscard]] bool HasUpcomingRepetition(U16 ply) const;

  [[nodiscard]] bool IsRepetition(U16 ply) const;

  [[nodiscard]] bool IsInsufficientMaterial() const;

  void CalculateKingThreats();

  void CalculateThreats();

  [[nodiscard]] BitBoard GetOpponentWinningCaptures() const;

  [[nodiscard]] MoveList GetLegalMoves() const;

 private:
  void HandleCastling(Move move);

 private:
  BoardState state_;
  List<BoardState, 1024> history_;
  std::shared_ptr<nnue::Accumulator> accumulator_;
};

#endif  // INTEGRAL_BOARD_H_