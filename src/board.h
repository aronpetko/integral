#ifndef INTEGRAL_BOARD_H_
#define INTEGRAL_BOARD_H_

#include <vector>
#include <memory>
#include <utility>

#include "bitboard.h"
#include "move.h"

class CastleData {
 public:
  CastleData() : rights(0) {
    set_kingside_rook(Color::kWhite, Square::kH1);
    set_queenside_rook(Color::kWhite, Square::kA1);
    set_kingside_rook(Color::kBlack, Square::kH8);
    set_queenside_rook(Color::kBlack, Square::kA8);
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
  std::array<std::array<Square, 2>, 2> rooks{}; // 2 rooks for each side
};

class BoardState {
 public:
  BoardState() {
    half_moves = 0;
    full_moves = 0;
    turn = Color::kWhite;
    en_passant = std::nullopt;
  }

  BoardState(const BoardState &other) = default;

  [[nodiscard]] bool is_end_game() const {
    const BitBoard minor_pieces = pieces[kWhiteKnights] | pieces[kWhiteBishops] |
        pieces[kBlackKnights] | pieces[kBlackBishops];
    const BitBoard major_pieces = pieces[kWhiteRooks] | pieces[kWhiteQueens] |
        pieces[kBlackRooks] | pieces[kBlackQueens];

    return minor_pieces.pop_count() + major_pieces.pop_count() < 7;
  }

 public:
  BitBoards pieces;
  Move move;
  Color turn;
  U32 full_moves;
  U32 half_moves;
  std::optional<Square> en_passant;
  CastleData castle;
};

inline unsigned long captures = 0;
inline unsigned long checks = 0;
inline unsigned long en_passant_captures = 0;
inline unsigned long castles = 0;
inline unsigned long promotions = 0;

class Board {
 public:
  explicit Board(std::unique_ptr<BoardState> state) : state_(std::move(state)) {}

  const std::unique_ptr<BoardState> &get_state() {
    return state_;
  }

  bool is_legal_move(const Move &move);

  void make_move(const Move &move, bool perft = false, int perft_depth = 0);

  void undo_move();

 private:
  void handle_castling(const Move &move, bool perft = false, int perft_depth = 0);

  void handle_promotions(const Move &move, bool perft = false, int perft_depth = 0);

 private:
  std::unique_ptr<BoardState> state_;
  std::vector<std::unique_ptr<BoardState>> history_;
};

#endif // INTEGRAL_BOARD_H_