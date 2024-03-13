#include "board.h"

Move::Move(U8 from, U8 to) : data_(0) {
  set_from(from);
  set_to(to);
}

Move::Move(U8 from, U8 to, PieceType piece_type) : Move(from, to) {
  set_piece_type(piece_type);
}

Move::Move(U8 from, U8 to, PieceType piece_type, PromotionType promotion_type) : Move(from, to, piece_type) {
  set_promotion_type(promotion_type);
}

Move Move::null_move() {
  return {0, 0};
}

bool Move::operator==(const Move& other) const {
  return data_ == other.data_;
}

std::optional<Move> Move::from_str(BoardState &state, std::string_view str) {
  const int kMinMoveLen = 4, kMaxMoveLen = 5;
  if (str.length() < kMinMoveLen || str.length() > kMaxMoveLen)
    return std::nullopt;

  const int from_rank = str[1] - '1', from_file = str[0] - 'a';
  const int to_rank = str[3] - '1', to_file = str[2] - 'a';

  if (from_rank < 0 || from_rank >= 8 || to_rank < 0 || to_rank >= 8 ||
      from_file < 0 || from_file >= 8 || to_file < 0 || to_file >= 8)
    return std::nullopt;

  const auto from = rank_file_to_pos(from_rank, from_file);
  const auto to = rank_file_to_pos(to_rank, to_file);
  const auto piece_type = state.get_piece_type(from);

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

[[nodiscard]] U8 Move::get_from() const {
  return data_ & kFromMask;
}

[[nodiscard]] U8 Move::get_to() const {
  return (data_ & kToMask) >> 6;
}

[[nodiscard]] PieceType Move::get_piece_type() const {
  return PieceType((data_ & kPieceTypeMask) >> 12);
}

[[nodiscard]] PromotionType Move::get_promotion_type() const {
  return PromotionType((data_ & kPromotionTypeMask) >> 15);
}

void Move::set_from(U8 from) {
  data_ &= ~kFromMask;
  data_ |= static_cast<U32>(from) & kFromMask;
}

void Move::set_to(U8 to) {
  data_ &= ~kToMask;
  data_ |= (static_cast<U32>(to) << 6) & kToMask;
}

void Move::set_piece_type(PieceType piece_type) {
  data_ = (data_ & ~kPieceTypeMask) | (static_cast<U8>(piece_type) << 12);
}

void Move::set_promotion_type(PromotionType promotion_type) {
  data_ = (data_ & ~kPromotionTypeMask) | (static_cast<U8>(promotion_type) << 15);
}

[[nodiscard]] std::string Move::to_string() const {
  if (*this == null_move())
    return "null";

  const auto from_rank = get_from() / kBoardRanks, from_file = get_from() % kBoardFiles;
  const auto to_rank = get_to() / kBoardRanks, to_file = get_to() % kBoardFiles;

  std::string res = std::string(1, 'a' + from_file) + std::to_string(from_rank + 1) +
                    std::string(1, 'a' + to_file) + std::to_string(to_rank + 1);

  const auto promo_type = get_promotion_type();
  switch (promo_type) {
    case PromotionType::kAny:
    case PromotionType::kQueen:
      res += 'q';
      break;
    case PromotionType::kKnight:
      res += 'n';
      break;
    case PromotionType::kBishop:
      res += 'b';
      break;
    case PromotionType::kRook:
      res += 'r';
      break;
    default:
      break;
  }

  return res;
}