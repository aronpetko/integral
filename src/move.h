#ifndef INTEGRAL_MOVE_H_
#define INTEGRAL_MOVE_H_

#include <optional>
#include <vector>
#include <string>

class BoardState;

const U32 kFromMask = 0b000000000000111111;
const U32 kToMask = 0b000000111111000000;
const U32 kPieceTypeMask = 0b000111000000000000;
const U32 kPromotionTypeMask = 0b111000000000000000;

// bits 0-5: from
// bits 6-11: to
// bits 12-14: piece type
// bits 15-17: promotion type
class Move {
 public:
  Move() = default;

  Move(U8 from, U8 to);

  Move(U8 from, U8 to, PieceType piece_type);

  Move(U8 from, U8 to, PieceType piece_type, PromotionType promotion_type);

  [[nodiscard]] static Move null_move();

  bool operator==(const Move &other) const;

  static std::optional<Move> from_str(BoardState &board, std::string_view str);

  [[nodiscard]] U8 get_from() const;

  [[nodiscard]] U8 get_to() const;

  [[nodiscard]] PieceType get_piece_type() const;

  [[nodiscard]] PromotionType get_promotion_type() const;

  void set_from(U8 from);

  void set_to(U8 to);

  void set_piece_type(PieceType piece_type);

  void set_promotion_type(PromotionType promotion_type);

  [[nodiscard]] std::string to_string() const;

 private:
  U32 data_;
};

static U8 rank_file_to_pos(U8 rank, U8 file) {
  return rank * kBoardLength + file;
}

#endif // INTEGRAL_MOVE_H_