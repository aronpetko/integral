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
  BoardState() : half_moves(0), fifty_moves_clock(0), zobrist_key(0ULL), turn(Color::kWhite), en_passant(std::nullopt) {}

  [[nodiscard]] Color get_piece_color(U8 pos) const;

  [[nodiscard]] Color get_piece_color(const BitBoard &bb) const;

  [[nodiscard]] PieceType get_piece_type(U8 pos) const;

  [[nodiscard]] PieceType get_piece_type(const BitBoard &bb) const;

  BitBoards pieces;
  Color turn;
  U32 half_moves;
  U32 fifty_moves_clock;
  std::optional<Square> en_passant;
  CastleData castle;
  U64 zobrist_key;
};

class Board {
 public:
  explicit Board(BoardState state, std::size_t transpo_table_size) : state_(std::move(state)), transpo_table_(transpo_table_size), history_count_(0) {}

  Board() : history_count_(0) {}

  BoardState &get_state() {
    return state_;
  }

  TranspositionTable &get_transpo_table() {
    return transpo_table_;
  }

  bool is_legal_move(const Move &move);

  void make_move(const Move &move);

  void make_null_move();

  void undo_move();

  [[nodiscard]] bool has_repeated(U8 times) const;

 private:
  void handle_castling(const Move &move, BoardState &state);

  void handle_promotions(const Move &move, BoardState &state);

 private:
  BoardState state_;

  BoardState history_[kMaxGameMoves];

  int history_count_;

  U64 key_history_[kHalfMoveLimit];

  TranspositionTable transpo_table_;
};

#endif // INTEGRAL_BOARD_H_