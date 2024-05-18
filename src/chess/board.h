#ifndef INTEGRAL_BOARD_H_
#define INTEGRAL_BOARD_H_

#include <memory>
#include <optional>
#include <utility>
#include <vector>

#include "../engine/transpo.h"
#include "../utils/zobrist.h"
#include "bitboard.h"

constexpr int kMaxPlyFromRoot = 256;
constexpr int kMaxGamePly = 1024;

class CastleRights {
 public:
  static constexpr int kKingsideIndex = 0;
  static constexpr int kQueensideIndex = 1;

  static constexpr std::array<std::array<Square, 2>, 2> kRookSquares = {
      {{Square::kH8, Square::kA8}, {Square::kH1, Square::kA1}}};

  static constexpr std::array<std::array<U8, 2>, 2> kMasks = {
      {{CastleRightMasks::kWhiteKingside, CastleRightMasks::kWhiteQueenside},
       {CastleRightMasks::kBlackKingside, CastleRightMasks::kBlackQueenside}}};

  CastleRights() : rights_(0) {}

  bool operator==(const CastleRights &other) const {
    return rights_ == other.rights_;
  }

  [[nodiscard]] inline bool CanKingsideCastle(Color turn) const {
    return rights_ & kMasks[turn][kKingsideIndex];
  }

  [[nodiscard]] inline bool CanQueensideCastle(Color turn) const {
    return rights_ & kMasks[turn][kQueensideIndex];
  }

  [[nodiscard]] inline bool CanCastle(Color turn) const {
    return CanKingsideCastle(turn) || CanQueensideCastle(turn);
  }

  inline void SetCanKingsideCastle(Color turn, bool value) {
    const U8 mask = kMasks[turn][kKingsideIndex];
    value ? rights_ |= mask : rights_ &= ~mask;
  }

  inline void SetCanQueensideCastle(Color turn, bool value) {
    const U8 mask = kMasks[turn][kQueensideIndex];
    value ? rights_ |= mask : rights_ &= ~mask;
  }

  inline void SetBothRights(Color turn, bool value) {
    const U8 mask =
        kMasks[turn][kKingsideIndex] | kMasks[turn][kQueensideIndex];
    value ? rights_ |= mask : rights_ &= ~mask;
  }

  [[nodiscard]] inline Square GetKingsideRook(Color turn) const {
    return kRookSquares[turn][kKingsideIndex];
  }

  [[nodiscard]] inline Square GetQueensideRook(Color turn) const {
    return kRookSquares[turn][kQueensideIndex];
  }

  inline U8 GetRights() const {
    return rights_;
  }

 private:
  U8 rights_;
};

struct BoardState {
  BoardState()
      : fifty_moves_clock(0),
        zobrist_key(0ULL),
        turn(Color::kWhite),
        checkers(0ULL),
        pinned(0ULL),
        en_passant(Square::kNoSquare) {
    piece_on_square.fill(PieceType::kNone);
  }

  void PlacePiece(U8 square, PieceType piece_type, Color color) {
    piece_on_square[square] = piece_type;
    piece_bbs[piece_type].SetBit(square);
    side_bbs[color].SetBit(square);
  }

  void RemovePiece(U8 square) {
    auto &piece_type = piece_on_square[square];
    if (piece_type != PieceType::kNone) {
      piece_bbs[piece_type].ClearBit(square);
      side_bbs[Color::kBlack].ClearBit(square);
      side_bbs[Color::kWhite].ClearBit(square);
      piece_type = PieceType::kNone;
    }
  }

  [[nodiscard]] constexpr inline Color GetPieceColor(U8 square) const {
    if (side_bbs[Color::kWhite].IsSet(square)) return Color::kWhite;
    if (side_bbs[Color::kBlack].IsSet(square)) return Color::kBlack;
    return Color::kNoColor;
  }

  [[nodiscard]] constexpr inline PieceType GetPieceType(U8 square) const {
    return piece_on_square[square];
  }

  [[nodiscard]] constexpr inline int GetPieceAndColor(U8 square) const {
    const auto piece = GetPieceType(square);
    return piece != PieceType::kNone ? piece * 2 + GetPieceColor(square) : -1;
  }

  [[nodiscard]] constexpr inline bool PieceExists(Square square) const {
    return GetPieceType(square) != PieceType::kNone;
  }

  [[nodiscard]] constexpr inline BitBoard Occupied() const {
    return side_bbs[Color::kWhite] | side_bbs[Color::kBlack];
  }

  [[nodiscard]] constexpr inline const BitBoard &Occupied(Color side) const {
    return side_bbs[side];
  }

  [[nodiscard]] constexpr inline BitBoard KinglessOccupied() const {
    return (side_bbs[Color::kWhite] | side_bbs[Color::kBlack]) &
           ~piece_bbs[kKing];
  }

  [[nodiscard]] constexpr inline BitBoard KinglessOccupied(Color side) const {
    return side_bbs[side] ^ piece_bbs[kKing];
  }

  [[nodiscard]] constexpr inline BitBoard Pawns(Color side) const {
    return piece_bbs[PieceType::kPawn] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &Pawns() const {
    return piece_bbs[PieceType::kPawn];
  }

  [[nodiscard]] constexpr inline BitBoard Knights(Color side) const {
    return piece_bbs[PieceType::kKnight] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &Knights() const {
    return piece_bbs[PieceType::kKnight];
  }

  [[nodiscard]] constexpr inline BitBoard Bishops(Color side) const {
    return piece_bbs[PieceType::kBishop] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &Bishops() const {
    return piece_bbs[PieceType::kBishop];
  }

  [[nodiscard]] constexpr inline BitBoard Rooks(Color side) const {
    return piece_bbs[PieceType::kRook] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &Rooks() const {
    return piece_bbs[PieceType::kRook];
  }

  [[nodiscard]] constexpr inline BitBoard Queens(Color side) const {
    return piece_bbs[PieceType::kQueen] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &Queens() const {
    return piece_bbs[PieceType::kQueen];
  }

  [[nodiscard]] constexpr inline BitBoard King(Color side) const {
    return piece_bbs[PieceType::kKing] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &Kings() const {
    return piece_bbs[PieceType::kKing];
  }

  [[nodiscard]] constexpr inline bool InCheck() const {
    return checkers != 0;
  }

  std::array<BitBoard, PieceType::kNumTypes> piece_bbs;
  std::array<BitBoard, 2> side_bbs;
  std::array<PieceType, Square::kSquareCount> piece_on_square;
  Color turn;
  U16 fifty_moves_clock;
  Square en_passant;
  CastleRights castle_rights;
  U64 zobrist_key;
  BitBoard checkers;
  BitBoard pinned;
};

class Board {
 public:
  Board();

  inline BoardState &GetState() {
    return state_;
  }

  inline BoardState &GetPrevState() {
    return history_.Back();
  }

  void SetFromFen(std::string_view fen_str);

  [[nodiscard]] bool IsMovePseudoLegal(Move move);

  [[nodiscard]] bool IsMoveLegal(Move move);

  void MakeMove(Move move);

  void MakeNullMove();

  void UndoMove();

  U64 PredictKeyAfter(Move move);

  [[nodiscard]] bool HasRepeated(U16 ply);

  [[nodiscard]] bool IsDraw(U16 ply);

  void PrintPieces();

 private:
  void HandleCastling(Move move);

  void HandlePromotions(Move move);

  void CalculateKingThreats();

 private:
  BoardState state_;
  List<BoardState, kMaxGamePly> history_;
};

#endif  // INTEGRAL_BOARD_H_