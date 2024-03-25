#ifndef INTEGRAL_BOARD_H_
#define INTEGRAL_BOARD_H_

#include <utility>
#include <vector>
#include <memory>
#include <utility>
#include <optional>

#include "bitboard.h"
#include "zobrist.h"
#include "transpo.h"

const int kMaxGameMoves = 1024;
const int kHalfMoveLimit = 1024;

class CastleRights {
 public:
  static constexpr int kKingsideRookIndex = 0;
  static constexpr int kQueensideRookIndex = 1;

  static constexpr std::array<std::array<Square, 2>, 2> kRookSquares = {{
    {Square::kH8, Square::kA8},
    {Square::kH1, Square::kA1}
  }};

  CastleRights() : rights(0) {}

  [[nodiscard]] inline bool can_kingside_castle(Color turn) const {
    U8 mask = turn == Color::kWhite ? CastleRightMasks::kWhiteKingside : CastleRightMasks::kBlackKingside;
    return rights & mask;
  }

  [[nodiscard]] inline bool can_queenside_castle(Color turn) const {
    U8 mask = turn == Color::kWhite ? CastleRightMasks::kWhiteQueenside : CastleRightMasks::kBlackQueenside;
    return rights & mask;
  }

  inline void set_can_kingside_castle(Color turn, bool value) {
    U8 mask = turn == Color::kWhite ? CastleRightMasks::kWhiteKingside : CastleRightMasks::kBlackKingside;
    value ? rights |= mask : rights &= ~mask;
  }

  inline void set_can_queenside_castle(Color turn, bool value) {
    U8 mask = turn == Color::kWhite ? CastleRightMasks::kWhiteQueenside : CastleRightMasks::kBlackQueenside;
    value ? rights |= mask : rights &= ~mask;
  }

  [[nodiscard]] inline Square get_kingside_rook(Color turn) const {
    return kRookSquares[turn][kKingsideRookIndex];
  }

  [[nodiscard]] inline Square get_queenside_rook(Color turn) const {
    return kRookSquares[turn][kQueensideRookIndex];
  }

 private:
  U8 rights;
};

struct BoardState {
  BoardState() : fifty_moves_clock(0), zobrist_key(0ULL), turn(Color::kWhite), en_passant(std::nullopt) {}

  [[nodiscard]] constexpr inline Color get_piece_color(U8 pos) const {
    if (side_bbs[Color::kWhite].is_set(pos)) return Color::kWhite;
    if (side_bbs[Color::kBlack].is_set(pos)) return Color::kBlack;
    return Color::kNoColor;
  }

  [[nodiscard]] constexpr inline Color get_piece_color(const BitBoard &bb) const {
    if (side_bbs[Color::kWhite] & bb) return Color::kWhite;
    if (side_bbs[Color::kBlack] & bb) return Color::kBlack;
    return Color::kNoColor;
  }

  [[nodiscard]] constexpr inline PieceType get_piece_type(U8 pos) const {
    if (!occupied().is_set(pos))
      return PieceType::kNone;

    for (int type = 0; type < PieceType::kNumPieceTypes; type++) {
      if (piece_bbs[type].is_set(pos)) {
        return PieceType(type);
      }
    }

    // should never reach here
    return PieceType::kNone;
  }

  [[nodiscard]] constexpr inline PieceType get_piece_type(const BitBoard &bb) const {
    return get_piece_type(bb.get_lsb_pos());
  }

  [[nodiscard]] constexpr inline bool piece_exists(U8 pos) const {
    return occupied().is_set(pos);
  }

  [[nodiscard]] constexpr inline BitBoard occupied() const {
    return side_bbs[Color::kWhite] | side_bbs[Color::kBlack];
  }

  [[nodiscard]] constexpr inline BitBoard &occupied(Color side) {
    return side_bbs[side];
  }

  [[nodiscard]] inline BitBoard pawns(Color side) const {
    return piece_bbs[PieceType::kPawn] & side_bbs[side];
  }

  [[nodiscard]] inline BitBoard &pawns() {
    return piece_bbs[PieceType::kPawn];
  }

  [[nodiscard]] inline BitBoard knights(Color side) const {
    return piece_bbs[PieceType::kKnight] & side_bbs[side];
  }

  [[nodiscard]] inline BitBoard &knights() {
    return piece_bbs[PieceType::kKnight];
  }

  [[nodiscard]] inline BitBoard bishops(Color side) const {
    return piece_bbs[PieceType::kBishop] & side_bbs[side];
  }

  [[nodiscard]] inline BitBoard &bishops() {
    return piece_bbs[PieceType::kBishop];
  }

  [[nodiscard]] inline BitBoard rooks(Color side) const {
    return piece_bbs[PieceType::kRook] & side_bbs[side];
  }

  [[nodiscard]] inline BitBoard &rooks() {
    return piece_bbs[PieceType::kRook];
  }

  [[nodiscard]] inline BitBoard queens(Color side) const {
    return piece_bbs[PieceType::kQueen] & side_bbs[side];
  }

  [[nodiscard]] inline BitBoard &queens() {
    return piece_bbs[PieceType::kQueen];
  }

  [[nodiscard]] inline BitBoard king(Color side) const {
    return piece_bbs[PieceType::kKing] & side_bbs[side];
  }

  [[nodiscard]] inline BitBoard &king() {
    return piece_bbs[PieceType::kKing];
  }

  std::array<BitBoard, PieceType::kNumPieceTypes> piece_bbs;
  std::array<BitBoard, 2> side_bbs;
  Color turn;
  U16 fifty_moves_clock;
  std::optional<Square> en_passant;
  CastleRights castle;
  U64 zobrist_key;
};

class Board {
 public:
  explicit Board(std::size_t transpo_table_size);

  Board();

  BoardState &get_state() {
    return state_;
  }

  TranspositionTable &get_transpo_table() {
    return transpo_table_;
  }

  [[nodiscard]] bool initialized() const {
    return initialized_;
  }

  void set_from_fen(const std::string &fen_str);

  [[nodiscard]] bool is_legal_move(const Move &move);

  void make_move(const Move &move);

  void make_null_move();

  void undo_move();

  [[nodiscard]] bool has_repeated(U8 times) const;

  [[nodiscard]] bool is_draw() const;

 private:
  void handle_castling(const Move &move);

  void handle_promotions(const Move &move);

 private:
  BoardState state_;
  bool initialized_;
  std::array<BoardState, kMaxGameMoves> history_;
  int history_count_;
  std::array<U64, kHalfMoveLimit> key_history_;
  int key_history_count_;
  TranspositionTable transpo_table_;
};

#endif // INTEGRAL_BOARD_H_