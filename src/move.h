#ifndef INTEGRAL_MOVE_H_
#define INTEGRAL_MOVE_H_

#include <optional>
#include "types.h"

static U8 rank_file_to_pos(U8 rank, U8 file) {
  return rank * kBoardLength + file;
}

const U32 kFromMask = 0b000000000000111111;
const U32 kToMask = 0b000000111111000000;
const U32 kPieceTypeMask = 0b000111000000000000;
const U32 kPromotionTypeMask = 0b111000000000000000;

// bits 0-5: from
// bits 6-11: to
// bits 12-14: piece type
// bits 15-17: promotion type
struct Move {
  U32 data = 0;

  Move() = default;

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
    return data & kFromMask;
  }

  [[nodiscard]] U8 get_to() const {
    return (data & kToMask) >> 6;
  }

  [[nodiscard]] PieceType get_piece_type() const {
    return PieceType((data & kPieceTypeMask) >> 12);
  }

  [[nodiscard]] PromotionType get_promotion_type() const {
    return PromotionType((data & kPromotionTypeMask) >> 15);
  }

  void set_from(U8 from) {
    data &= ~kFromMask;
    data |= static_cast<U32>(from) & kFromMask;
  }

  void set_to(U8 to) {
    data &= ~kToMask;
    data |= (static_cast<U32>(to) << 6) & kToMask;
  }

  void set_piece_type(PieceType piece_type) {
    data = (data & ~kPieceTypeMask) | (static_cast<U8>(piece_type) << 12);
  }

  void set_promotion_type(PromotionType promotion_type) {
    data = (data & ~kPromotionTypeMask) | (static_cast<U8>(promotion_type) << 15);
  }

  [[nodiscard]] std::string to_string() const {
    const U8 from_rank = get_from() / 8, from_file = get_from() % 8;
    const U8 to_rank = get_to() / 8, to_file = get_to() % 8;
    return std::string(1, 'a' + from_file) + std::to_string(from_rank + 1) +
        std::string(1, 'a' + to_file) + std::to_string(to_rank + 1);
  }

};

using MoveList = std::vector<Move>;

#endif // INTEGRAL_MOVE_H_