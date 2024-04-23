#ifndef INTEGRAL_BOARD_H_
#define INTEGRAL_BOARD_H_

#include <memory>
#include <optional>
#include <utility>
#include <vector>

#include "../engine/transpo.h"
#include "../utils/zobrist.h"
#include "bitboard.h"

const int kMaxPlyFromRoot = 256;
const int kMaxGamePly = 1024;

class CastleRights {
 public:
  static constexpr int kKingsideIndex = 0;
  static constexpr int kQueensideIndex = 1;

  static constexpr std::array<std::array<Square, 2>, 2> kRookSquares = {{
    {Square::kH8, Square::kA8},
    {Square::kH1, Square::kA1}
  }};

  static constexpr std::array<std::array<U8, 2>, 2> kMasks = {{
      {CastleRightMasks::kWhiteKingside, CastleRightMasks::kWhiteQueenside},
      {CastleRightMasks::kBlackKingside, CastleRightMasks::kBlackQueenside}
  }};

  CastleRights() : rights_(0) {}

  bool operator==(const CastleRights &other) const {
    return rights_ == other.rights_;
  }

  [[nodiscard]] inline bool can_kingside_castle(Color turn) const {
    return rights_ & kMasks[turn][kKingsideIndex];
  }

  [[nodiscard]] inline bool can_queenside_castle(Color turn) const {
    return rights_ & kMasks[turn][kQueensideIndex];
  }

  [[nodiscard]] inline bool can_castle(Color turn) const {
    return can_kingside_castle(turn) || can_queenside_castle(turn);
  }

  inline void set_can_kingside_castle(Color turn, bool value) {
    const U8 mask = kMasks[turn][kKingsideIndex];
    value ? rights_ |= mask : rights_ &= ~mask;
  }

  inline void set_can_queenside_castle(Color turn, bool value) {
    const U8 mask = kMasks[turn][kQueensideIndex];
    value ? rights_ |= mask : rights_ &= ~mask;
  }

  inline void set_both_rights(Color turn, bool value) {
    const U8 mask = kMasks[turn][kKingsideIndex] | kMasks[turn][kQueensideIndex];
    value ? rights_ |= mask : rights_ &= ~mask;
  }

  [[nodiscard]] inline Square get_kingside_rook(Color turn) const {
    return kRookSquares[turn][kKingsideIndex];
  }

  [[nodiscard]] inline Square get_queenside_rook(Color turn) const {
    return kRookSquares[turn][kQueensideIndex];
  }

  inline U8 get_rights() const {
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
        en_passant(Square::kNoSquare),
        move_played(Move::null_move()) {
    piece_on_square.fill(PieceType::kNone);
  }

  void place_piece(const U8 &square, const PieceType &piece_type, const Color &color) {
    piece_on_square[square] = piece_type;
    piece_bbs[piece_type].set_bit(square);
    side_bbs[color].set_bit(square);
  }

  void remove_piece(const U8 &square) {
    auto &piece_type = piece_on_square[square];
    if (piece_type != PieceType::kNone) {
      piece_bbs[piece_type].clear_bit(square);
      side_bbs[Color::kBlack].clear_bit(square);
      side_bbs[Color::kWhite].clear_bit(square);
      piece_type = PieceType::kNone;
    }
  }

  [[nodiscard]] constexpr inline Color get_piece_color(const U8 &square) const {
    if (side_bbs[Color::kWhite].is_set(square)) return Color::kWhite;
    if (side_bbs[Color::kBlack].is_set(square)) return Color::kBlack;
    return Color::kNoColor;
  }

  [[nodiscard]] constexpr inline PieceType get_piece_type(const U8 &square) const {
    return piece_on_square[square];
  }

  [[nodiscard]] constexpr inline bool piece_exists(Square square) const {
    return get_piece_type(square) != PieceType::kNone;
  }

  [[nodiscard]] constexpr inline BitBoard occupied() const {
    return side_bbs[Color::kWhite] | side_bbs[Color::kBlack];
  }

  [[nodiscard]] constexpr inline const BitBoard &occupied(Color side) const {
    return side_bbs[side];
  }

  [[nodiscard]] constexpr inline BitBoard kingless_occupied() const {
    return (side_bbs[Color::kWhite] | side_bbs[Color::kBlack]) & ~piece_bbs[kKing];
  }

  [[nodiscard]] constexpr inline BitBoard kingless_occupied(Color side) const {
    return side_bbs[side] ^ piece_bbs[kKing];
  }

  [[nodiscard]] constexpr inline BitBoard pawns(Color side) const {
    return piece_bbs[PieceType::kPawn] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &pawns() const {
    return piece_bbs[PieceType::kPawn];
  }

  [[nodiscard]] constexpr inline BitBoard knights(Color side) const {
    return piece_bbs[PieceType::kKnight] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &knights() const {
    return piece_bbs[PieceType::kKnight];
  }

  [[nodiscard]] constexpr inline BitBoard bishops(Color side) const {
    return piece_bbs[PieceType::kBishop] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &bishops() const {
    return piece_bbs[PieceType::kBishop];
  }

  [[nodiscard]] constexpr inline BitBoard rooks(Color side) const {
    return piece_bbs[PieceType::kRook] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &rooks() const {
    return piece_bbs[PieceType::kRook];
  }

  [[nodiscard]] constexpr inline BitBoard queens(Color side) const {
    return piece_bbs[PieceType::kQueen] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &queens() const {
    return piece_bbs[PieceType::kQueen];
  }

  [[nodiscard]] constexpr inline BitBoard king(Color side) const {
    return piece_bbs[PieceType::kKing] & side_bbs[side];
  }

  [[nodiscard]] constexpr inline const BitBoard &kings() const {
    return piece_bbs[PieceType::kKing];
  }

  [[nodiscard]] constexpr inline bool in_check() const {
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
  Move move_played;
  BitBoard checkers;
  BitBoard pinned;
};

class Board {
 public:
  Board();

  inline BoardState &get_state() {
    return state_;
  }

  inline BoardState &get_prev_state() {
    return history_.back();
  }

  void set_from_fen(const std::string &fen_str);

  [[nodiscard]] bool is_move_pseudo_legal(Move move);

  // assuming the move is pseudo legal
  [[nodiscard]] bool is_move_legal(Move move);

  void make_move(Move move);

  void make_null_move();

  void undo_move();

  U64 key_after(Move move);

  [[nodiscard]] bool has_repeated(int ply);

  [[nodiscard]] bool is_draw(int ply);

  void print_pieces();

 private:
  void handle_castling(Move move);

  void handle_promotions(Move move);

  void calculate_king_attacks();

 private:
  BoardState state_;
  List<BoardState, kMaxGamePly> history_;
};

#endif // INTEGRAL_BOARD_H_