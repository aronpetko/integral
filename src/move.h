#ifndef INTEGRAL_MOVE_H_
#define INTEGRAL_MOVE_H_

#include "types.h"

static U8 rank_file_to_pos(U8 rank, U8 file) {
  return rank * kBoardLength + file;
}

const U8 kMoveMask = 0b111111;
const U8 kPieceTypeMask = 0b111;
const U8 kPromotionTypeMask = 0b111;

// bits 0-5: from
// bits 6-11: to
// bits 12-14: piece type
// bits 15-17: promotion type
struct Move {
  U32 data = 0;

  Move(U8 from, U8 to) {
    set_from(from);
    set_to(to);
  }

  Move(U8 from, U8 to, PieceType piece_type) : Move(from, to) {
    set_piece_type(piece_type);
  }

  Move(U8 from, U8 to, PieceType piece_type, PromotionType promotion_type) : Move(from, to, piece_type) {
    set_promotion_type(promotion_type);
  }

  static std::optional<Move> from_str(std::string_view str, PieceType piece_type = PieceType::kNone) {
    const int kMinMoveLen = 4, kMaxMoveLen = 5;
    if (str.length() < kMinMoveLen || str.length() > kMaxMoveLen)
      return std::nullopt;

    const int from_rank = str[1] - '1', from_file = str[0] - 'a';
    const int to_rank = str[3] - '1', to_file = str[2] - 'a';

    if (from_rank < 0 || from_rank >= 8 || to_rank < 0 || to_rank >= 8 ||
        from_file < 0 || from_file >= 8 || to_file < 0 || to_file >= 8)
      return std::nullopt;

    U8 from = rank_file_to_pos(from_rank, from_file);
    U8 to = rank_file_to_pos(to_rank, to_file);

    if (str.length() < kMaxMoveLen)
      return Move(from, to, piece_type);

    PromotionType promotion_type;
    switch (str[4]) {
      case 'q':
      case 'Q':
        promotion_type = PromotionType::kQueen;
        break;
      case 'r':
      case 'R':
        promotion_type = PromotionType::kRook;
        break;
      case 'b':
      case 'B':
        promotion_type = PromotionType::kBishop;
        break;
      case 'n':
      case 'N':
        promotion_type = PromotionType::kKnight;
        break;
      default:
        return std::nullopt;
    }

    return Move(from, to, piece_type, promotion_type);
  }

  [[nodiscard]] U8 get_from() const {
    return data & kMoveMask;
  }

  [[nodiscard]] U8 get_to() const {
    return (data >> 6) & kMoveMask;
  }

  [[nodiscard]] PieceType get_piece_type() const {
    return PieceType((data >> 12) & kPieceTypeMask);
  }

  void set_from(U8 from) {
    data |= from & kMoveMask;
  }

  void set_to(U8 to) {
    data |= ((to & kMoveMask) << 6);
  }

  void set_piece_type(PieceType piece_type) {
    data |= (static_cast<U8>(piece_type) & kPieceTypeMask) << 12;
  }

  void set_promotion_type(PromotionType promotion_type) {
    data |= (static_cast<U8>(promotion_type) & kPromotionTypeMask) << 15;
  }
};

#endif // INTEGRAL_MOVE_H_