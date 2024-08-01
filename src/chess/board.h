#ifndef INTEGRAL_BOARD_H_
#define INTEGRAL_BOARD_H_

#include <memory>
#include <optional>
#include <utility>
#include <vector>

#include "../engine/evaluation/terms.h"
#include "../engine/search/transpo.h"
#include "../utils/zobrist.h"
#include "bitboard.h"
#include "fen.h"

class CastleRights {
 public:
  static constexpr int kKingsideIndex = 0;
  static constexpr int kQueensideIndex = 1;

  static constexpr std::array<std::array<U8, 2>, 2> kMasks = {
      {{CastleRightMasks::kWhiteKingside, CastleRightMasks::kWhiteQueenside},
       {CastleRightMasks::kBlackKingside, CastleRightMasks::kBlackQueenside}}};

  CastleRights() : rights_(0) {}

  bool operator==(const CastleRights &other) const {
    return rights_ == other.rights_;
  }

  [[nodiscard]] constexpr bool CanKingsideCastle(Color turn) const {
    return rights_ & kMasks[turn][kKingsideIndex];
  }

  [[nodiscard]] constexpr bool CanQueensideCastle(Color turn) const {
    return rights_ & kMasks[turn][kQueensideIndex];
  }

  [[nodiscard]] constexpr bool CanCastle(Color turn) const {
    return CanKingsideCastle(turn) || CanQueensideCastle(turn);
  }

  constexpr void SetCanKingsideCastle(Color turn, bool value) {
    const U8 mask = kMasks[turn][kKingsideIndex];
    value ? rights_ |= mask : rights_ &= ~mask;
  }

  constexpr void SetCanQueensideCastle(Color turn, bool value) {
    const U8 mask = kMasks[turn][kQueensideIndex];
    value ? rights_ |= mask : rights_ &= ~mask;
  }

  constexpr void SetBothRights(Color turn, bool value) {
    const U8 mask =
        kMasks[turn][kKingsideIndex] | kMasks[turn][kQueensideIndex];
    value ? rights_ |= mask : rights_ &= ~mask;
  }

  U8 operator&=(U8 mask) {
    rights_ &= mask;
    return rights_;
  }

  [[nodiscard]] U8 AsU8() const {
    return rights_;
  }

 private:
  U8 rights_;
};

struct BoardState {
  BoardState()
      : turn(Color::kWhite),
        fifty_moves_clock(0),
        en_passant(Squares::kNoSquare),
        zobrist_key(0ULL),
        pawn_key(0ULL),
        checkers(0ULL),
        pinned(0ULL),
        phase(0),
        king_bucket({}) {
    piece_on_square.fill(PieceType::kNone);
  }

  template <bool update_key = true>
  void PlacePiece(Square square, PieceType piece_type, Color color) {
    // Add the piece to the bitboards and mailbox
    piece_bbs[piece_type].SetBit(square);
    side_bbs[color].SetBit(square);
    piece_on_square[square] = piece_type;

    const int our_bucket = king_bucket[color],
              their_bucket = king_bucket[FlipColor(color)];

    // Incrementally update the piece/square scores
    const Square rel_square = square.RelativeTo(color);
    // piece_scores[color] += eval::kPawnPieceSquareTable[our_bucket][their_bucket]
    //                                               [piece_type][rel_square];
    piece_scores[color] += eval::kPieceValues[piece_type];

    // Incrementally update the current phase of the game
    phase += eval::kPhaseIncrements[piece_type];

    // Insert the piece to the hash
    if constexpr (update_key) {
      const int colored_piece = piece_type * 2 + color;
      zobrist_key ^= zobrist::pieces[colored_piece][square];

      if (piece_type == PieceType::kPawn) {
        pawn_key ^= zobrist::pieces[colored_piece][square];
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
      }
    }

    // Clear the piece from the bitboards
    piece_bbs[piece_type].ClearBit(square);
    side_bbs[color].ClearBit(square);

    const int our_bucket = king_bucket[color],
              their_bucket = king_bucket[FlipColor(color)];
    // Incrementally update the piece/square scores
    const Square rel_square = square.RelativeTo(color);
    // piece_scores[color] -= eval::kPawnPieceSquareTable[our_bucket][their_bucket]
    //                                               [piece_type][rel_square];
    piece_scores[color] -= eval::kPieceValues[piece_type];

    // Incrementally update the current phase of the game
    phase -= eval::kPhaseIncrements[piece_type];

    piece_type = PieceType::kNone;
  }

  void RecalculatePieceScores() {
    const Square white_king_sq = King(Color::kWhite).GetLsb();
    const Square black_king_sq = King(Color::kBlack).GetLsb();
    king_bucket = {
        eval::kKingBucketLayout[black_king_sq],
        eval::kKingBucketLayout[white_king_sq.RelativeTo(Color::kWhite)]};
    piece_scores = {};

    for (Square square : Occupied()) {
      const auto color = GetPieceColor(square);
      const auto piece = GetPieceType(square);
      const int our_bucket = king_bucket[color],
                their_bucket = king_bucket[FlipColor(color)];
      piece_scores[color] += eval::kPieceValues[piece];
      piece_scores[color] +=
          eval::kPawnPieceSquareTable[our_bucket][their_bucket][piece]
                                 [square.RelativeTo(color)];
    }
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

  std::array<BitBoard, kNumPieceTypes> piece_bbs;
  std::array<BitBoard, 2> side_bbs;
  std::array<PieceType, kSquareCount> piece_on_square;
  Color turn;
  U8 fifty_moves_clock;
  Square en_passant;
  CastleRights castle_rights;
  U64 zobrist_key;
  U64 pawn_key;
  BitBoard checkers;
  BitBoard threats;
  BitBoard pinned;
  SideTable<ScorePair> piece_scores;
  int phase;
  SideTable<int> king_bucket;
};

class Board {
 public:
  Board();

  inline BoardState &GetState() {
    return state_;
  }

  void SetFromFen(std::string_view fen_str);

  void MakeMove(Move move);

  void MakeNullMove();

  void UndoMove();

  void PrintPieces();

  [[nodiscard]] bool IsMovePseudoLegal(Move move);

  [[nodiscard]] bool IsMoveLegal(Move move);

  [[nodiscard]] U64 PredictKeyAfter(Move move);

  [[nodiscard]] bool HasRepeated(U16 ply);

  [[nodiscard]] bool IsDraw(U16 ply);

 private:
  void HandleCastling(Move move);

  void CalculateKingThreats();

  void CalculateThreats();

 private:
  BoardState state_;
  List<BoardState, kMaxGamePly> history_;
};

#endif  // INTEGRAL_BOARD_H_