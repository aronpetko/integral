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

const int kMaxGameMoves = 2048;
const int kHalfMoveLimit = 1024;

class CastleData {
 public:
  CastleData() : rights(0) {
    set_kingside_rook(Color::kWhite, Square::kH1);
    set_queenside_rook(Color::kWhite, Square::kA1);
    set_kingside_rook(Color::kBlack, Square::kH8);
    set_queenside_rook(Color::kBlack, Square::kA8);
  }

  CastleData(const CastleData &other) {
    rooks = other.rooks;
    rights = other.rights;
  }

  [[nodiscard]] bool can_kingside_castle(Color turn) const {
    U8 mask = turn == Color::kWhite ? CastleRights::kWhiteKingside : CastleRights::kBlackKingside;
    return rights & mask;
  }

  [[nodiscard]] bool can_queenside_castle(Color turn) const {
    U8 mask = turn == Color::kWhite ? CastleRights::kWhiteQueenside : CastleRights::kBlackQueenside;
    return rights & mask;
  }

  void set_can_kingside_castle(Color turn, bool value) {
    U8 mask = turn == Color::kWhite ? CastleRights::kWhiteKingside : CastleRights::kBlackKingside;
    value ? rights |= mask : rights &= ~mask;
  }

  void set_can_queenside_castle(Color turn, bool value) {
    U8 mask = turn == Color::kWhite ? CastleRights::kWhiteQueenside : CastleRights::kBlackQueenside;
    value ? rights |= mask : rights &= ~mask;
  }

  [[nodiscard]] Square get_kingside_rook(Color turn) const {
    return rooks[turn][0];
  }

  [[nodiscard]] Square get_queenside_rook(Color turn) const {
    return rooks[turn][1];
  }

  void set_kingside_rook(Color turn, Square square) {
    rooks[turn][0] = square;
  }

  void set_queenside_rook(Color turn, Square square) {
    rooks[turn][1] = square;
  }

 private:
  U8 rights;
  std::array<std::array<Square, 2>, 2> rooks; // 2 rooks for each side
};

struct BoardState {
  BoardState() : half_moves(0), fifty_moves_clock(0), zobrist_key(0ULL), turn(Color::kWhite), en_passant(std::nullopt), piece_types({}) {}

  [[nodiscard]] constexpr inline Color get_piece_color(U8 pos) const {
    if (pieces[Color::kWhite][kAllPieces].is_set(pos)) return Color::kWhite;
    if (pieces[Color::kBlack][kAllPieces].is_set(pos)) return Color::kBlack;
    return Color::kNoColor;
  }

  [[nodiscard]] constexpr inline Color get_piece_color(const BitBoard &bb) const {
    if (pieces[Color::kWhite][kAllPieces] & bb) return Color::kWhite;
    if (pieces[Color::kBlack][kAllPieces] & bb) return Color::kBlack;
    return Color::kNoColor;
  }

  [[nodiscard]] constexpr inline PieceType get_piece_type(U8 pos) const {
    return piece_types[pos];
  }

  [[nodiscard]] constexpr inline PieceType get_piece_type(const BitBoard &bb) const {
    return piece_types[bb.get_lsb_pos()];
  }

  [[nodiscard]] constexpr inline BitBoard occupied() const {
    return pieces[Color::kWhite][kAllPieces] | pieces[Color::kBlack][kAllPieces];
  }

  std::array<std::array<BitBoard, kNumBitBoards>, 2> pieces;
  std::array<PieceType, Square::kSquareCount> piece_types;
  Color turn;
  U32 half_moves;
  U32 fifty_moves_clock;
  std::optional<Square> en_passant;
  CastleData castle;
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

  bool is_legal_move(const Move &move);

  void make_move(const Move &move);

  void make_null_move();

  void undo_move();

  [[nodiscard]] bool has_repeated(U8 times) const;

 private:
  void handle_castling(const Move &move);

  void handle_promotions(const Move &move);

 private:
  BoardState state_;
  bool initialized_;
  std::array<BoardState, kMaxGameMoves> history_;
  int history_count_;
  std::array<U64, kHalfMoveLimit> key_history_;
  TranspositionTable transpo_table_;
};

#endif // INTEGRAL_BOARD_H_