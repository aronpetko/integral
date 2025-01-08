#include "move.h"

#include "board.h"

Move Move::NullMove() {
  return Move(0, 0, MoveType::kNormal);
}

Move::operator bool() const {
  return !IsNull();
}

Move Move::FromStr(std::string_view str, const BoardState &state) {
  constexpr int kMinMoveLen = 4, kMaxMoveLen = 5;
  if (str.length() < kMinMoveLen || str.length() > kMaxMoveLen)
    return Move::NullMove();

  const int from_rank = str[1] - '1', from_file = str[0] - 'a';
  const int to_rank = str[3] - '1', to_file = str[2] - 'a';

  if (from_rank < 0 || from_rank >= 8 || to_rank < 0 || to_rank >= 8 ||
      from_file < 0 || from_file >= 8 || to_file < 0 || to_file >= 8)
    return Move::NullMove();

  const auto from = Square::FromRankFile(from_rank, from_file);
  const auto to = Square::FromRankFile(to_rank, to_file);

  auto flag = MoveType::kNormal;

  if (str.length() < kMaxMoveLen) {
    const auto piece = state.GetPieceType(from);
    if (piece == PieceType::kKing && std::abs(from_file - to_file) == 2) {
      flag = MoveType::kCastle;
    } else if (piece == PieceType::kPawn) {
      if (state.en_passant && to == state.en_passant) {
        flag = MoveType::kEnPassant;
      }
    }

    return Move(from, to, flag);
  }

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
      return Move::NullMove();
  }

  return Move(from, to, promotion_type);
}

bool Move::IsCapture(const BoardState &state) const {
  return state.GetPieceType(GetTo()) != PieceType::kNone || IsEnPassant(state);
}

bool Move::IsNoisy(const BoardState &state) const {
  return IsCapture(state) || GetType() == MoveType::kPromotion;
}

bool Move::IsEnPassant(const BoardState &state) const {
  return GetType() == MoveType::kEnPassant;
}

bool Move::IsUnderPromotion() const {
  const auto promo_type = GetPromotionType();
  return GetType() == MoveType::kPromotion &&
         promo_type != PromotionType::kQueen &&
         promo_type != PromotionType::kKnight;
}

std::string Move::ToString() const {
  if (data_ == 0) return "null";

  const auto from_rank = GetFrom().Rank(), from_file = GetFrom().File();
  const auto to_rank = GetTo().Rank(), to_file = GetTo().File();

  std::string res = std::string(1, 'a' + from_file) +
                    std::to_string(from_rank + 1) +
                    std::string(1, 'a' + to_file) + std::to_string(to_rank + 1);

  if (GetType() == MoveType::kPromotion) {
    switch (GetPromotionType()) {
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
  }

  return res;
}
