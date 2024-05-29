#include "move_gen.h"

#include "../magics/attacks.h"
#include "../magics/precomputed.h"
#include "board.h"

namespace move_gen {

inline std::array<BitBoard, 64> knight_masks;
inline std::array<BitBoard, 64> king_masks;
inline std::array<std::array<BitBoard, 64>, 2> pawn_attack_masks;
inline std::array<std::array<BitBoard, 64>, 64> ray_between_masks;
inline std::array<std::array<BitBoard, 64>, 64> ray_intersecting_masks;

void InitializeAttacks() {
  magics::attacks::Initialize();

  for (int square = 0; square < Squares::kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::FromSquare(square);

    knight_masks[square] |= (src_mask & ~kFileMasks[kFileH]) << 17;
    knight_masks[square] |=
        (src_mask & ~(kFileMasks[kFileH] | kFileMasks[kFileG])) << 10;
    knight_masks[square] |=
        (src_mask & ~(kFileMasks[kFileH] | kFileMasks[kFileG])) >> 6;
    knight_masks[square] |= (src_mask & ~kFileMasks[kFileH]) >> 15;
    knight_masks[square] |= (src_mask & ~kFileMasks[kFileA]) << 15;
    knight_masks[square] |=
        (src_mask & ~(kFileMasks[kFileA] | kFileMasks[kFileB])) << 6;
    knight_masks[square] |=
        (src_mask & ~(kFileMasks[kFileA] | kFileMasks[kFileB])) >> 10;
    knight_masks[square] |= (src_mask & ~kFileMasks[kFileA]) >> 17;

    king_masks[square] |= Shift<Direction::kNorth>(src_mask);
    king_masks[square] |= Shift<Direction::kSouth>(src_mask);
    king_masks[square] |= Shift<Direction::kEast>(src_mask);
    king_masks[square] |= Shift<Direction::kWest>(src_mask);
    king_masks[square] |= Shift<Direction::kNorthEast>(src_mask);
    king_masks[square] |= Shift<Direction::kNorthWest>(src_mask);
    king_masks[square] |= Shift<Direction::kSouthEast>(src_mask);
    king_masks[square] |= Shift<Direction::kSouthWest>(src_mask);

    pawn_attack_masks[Color::kWhite][square] |=
        Shift<Direction::kNorthEast>(src_mask);
    pawn_attack_masks[Color::kWhite][square] |=
        Shift<Direction::kNorthWest>(src_mask);
    pawn_attack_masks[Color::kBlack][square] |=
        Shift<Direction::kSouthEast>(src_mask);
    pawn_attack_masks[Color::kBlack][square] |=
        Shift<Direction::kSouthWest>(src_mask);

    const BitBoard src_bishop_rays =
        magics::attacks::GenerateBishopMoves(Square(square), 0ULL);
    const BitBoard src_rook_rays =
        magics::attacks::GenerateRookMoves(Square(square), 0ULL);

    for (int other_square = 0; other_square < Squares::kSquareCount;
         other_square++) {
      if (square == other_square) {
        continue;
      }

      const BitBoard dest_mask = BitBoard::FromSquare(other_square);

      if (src_bishop_rays & dest_mask) {
        // Calculate the rays that intersect square and other_square
        ray_intersecting_masks[square][other_square] =
            (src_mask | src_bishop_rays) &
            (dest_mask |
             magics::attacks::GenerateBishopMoves(Square(other_square), 0ULL));

        // Calculate the rays between square and other_square
        ray_between_masks[square][other_square] =
            magics::attacks::GenerateBishopMoves(Square(square), dest_mask) &
            magics::attacks::GenerateBishopMoves(Square(other_square),
                                                 src_mask);
      } else if (src_rook_rays & dest_mask) {
        // Calculate the rays that intersect square and other_square
        ray_intersecting_masks[square][other_square] =
            (src_mask | src_rook_rays) &
            (dest_mask |
             magics::attacks::GenerateRookMoves(Square(other_square), 0ULL));

        // Calculate the rays between square and other_square
        ray_between_masks[square][other_square] =
            magics::attacks::GenerateRookMoves(Square(square), dest_mask) &
            magics::attacks::GenerateRookMoves(Square(other_square), src_mask);
      }
    }
  }
}

inline bool IsSquareAttackedSlidingPieces(Square square,
                                          Color attacker,
                                          const BoardState &state) {
  const BitBoard occupied = state.Occupied();
  const BitBoard queens = state.Queens(attacker);

  const BitBoard bishop_attacks = BishopMoves(square, occupied);
  if ((queens | state.Bishops(attacker)) & bishop_attacks) {
    return true;
  }

  const BitBoard rook_attacks = RookMoves(square, occupied);
  if ((queens | state.Rooks(attacker)) & rook_attacks) {
    return true;
  }

  return false;
}

inline bool IsSquareAttackedNonSlidingPieces(Square square,
                                             Color attacker,
                                             const BoardState &state) {
  return (state.Knights(attacker) & KnightMoves(square)) != 0 ||
         (state.Pawns(attacker) &
          PawnAttacks(square, state, FlipColor(attacker))) != 0 ||
         (state.King(attacker) & KingAttacks(square)) != 0;
}

inline bool IsSquareAttacked(Square square,
                             Color attacker,
                             const BoardState &state) {
  return IsSquareAttackedNonSlidingPieces(square, attacker, state) ||
         IsSquareAttackedSlidingPieces(square, attacker, state);
}

BitBoard &PawnAttacks(Square square, const BoardState &state, Color side) {
  return pawn_attack_masks[side][square];
}

BitBoard AllLeftPawnAttacks(Color side, const BoardState &state) {
  BitBoard moves, pawns = state.Pawns(side);

  if (side == Color::kWhite) {
    moves |= Shift<Direction::kNorthWest>(pawns);
  } else {
    moves |= Shift<Direction::kSouthEast>(pawns);
  }

  return moves;
}

BitBoard AllRightPawnAttacks(Color side, const BoardState &state) {
  BitBoard moves, pawns = state.Pawns(side);

  if (side == Color::kWhite) {
    moves |= Shift<Direction::kNorthEast>(pawns);
  } else {
    moves |= Shift<Direction::kSouthWest>(pawns);
  }

  return moves;
}

BitBoard PawnMoves(Square square, const BoardState &state) {
  BitBoard moves, bb_pos = BitBoard::FromSquare(square),
                  occupied = state.Occupied();

  const auto color = state.GetPieceColor(square);
  if (color == Color::kWhite) {
    BitBoard up = Shift<Direction::kNorth>(bb_pos) & ~occupied;
    moves |= up;

    if (up && (bb_pos & kRankMasks[kRank2])) {
      BitBoard up_up = Shift<Direction::kNorth>(up) & ~occupied;
      moves |= up_up;
    }
  } else {
    BitBoard down = Shift<Direction::kSouth>(bb_pos) & ~occupied;
    moves |= down;

    if (down && (bb_pos & kRankMasks[kRank7])) {
      BitBoard down_down = Shift<Direction::kSouth>(down) & ~occupied;
      moves |= down_down;
    }
  }

  return moves;
}

BitBoard PawnPushes(Color side, const BoardState &state) {
  BitBoard moves, pawns = state.Pawns(side), occupied = state.Occupied();

  if (side == Color::kWhite) {
    BitBoard up = Shift<Direction::kNorth>(pawns) & ~occupied;
    moves |= up;
  } else {
    BitBoard down = Shift<Direction::kSouth>(pawns) & ~occupied;
    moves |= down;
  }

  return moves;
}

BitBoard PawnDoublePushes(Color side, const BoardState &state) {
  BitBoard moves, pawns = state.Pawns(side), occupied = state.Occupied();

  if (side == Color::kWhite) {
    const BitBoard double_pushers = pawns & kRankMasks[kRank2];
    if (double_pushers) {
      BitBoard up_up = Shift<Direction::kNorth>(double_pushers) & ~occupied;
      moves |= up_up;
    }
  } else {
    const BitBoard double_pushers = pawns & kRankMasks[kRank7];
    if (double_pushers) {
      BitBoard up_up = Shift<Direction::kSouth>(double_pushers) & ~occupied;
      moves |= up_up;
    }
  }

  return moves;
}

BitBoard &KnightMoves(Square square) {
  return knight_masks[square];
}

BitBoard &BishopMoves(Square square, const BitBoard &occupied) {
  const auto &entry = magics::kBishopMagics[square];
  const auto magic_index = (occupied & entry.mask) * entry.magic >> entry.shift;
  return magics::attacks::bishop_attacks[square][magic_index.AsU64()];
}

BitBoard &RookMoves(Square square, const BitBoard &occupied) {
  const auto &entry = magics::kRookMagics[square];
  const auto magic_index = (occupied & entry.mask) * entry.magic >> entry.shift;
  return magics::attacks::rook_attacks[square][magic_index.AsU64()];
}

BitBoard QueenMoves(Square square, const BitBoard &occupied) {
  return BishopMoves(square, occupied) | RookMoves(square, occupied);
}

BitBoard KingMoves(Square square, const BoardState &state) {
  BitBoard moves = KingAttacks(square);

  const auto color = state.GetPieceColor(square);
  if (state.castle_rights.CanCastle(state.turn) && !state.checkers)
    moves |= CastlingMoves(color, state);

  return moves;
}

BitBoard &KingAttacks(Square square) {
  return king_masks[square];
}

BitBoard CastlingMoves(Color side, const BoardState &state) {
  BitBoard moves, occupied = state.Occupied();

  if (side == Color::kWhite) {
    if (state.castle_rights.CanKingsideCastle(Color::kWhite)) {
      if (!occupied.IsSet(Squares::kF1) && !occupied.IsSet(Squares::kG1))
        moves.SetBit(Squares::kG1);
    }

    if (state.castle_rights.CanQueensideCastle(Color::kWhite)) {
      if (!occupied.IsSet(Squares::kD1) && !occupied.IsSet(Squares::kC1) &&
          !occupied.IsSet(Squares::kB1))
        moves.SetBit(Squares::kC1);
    }
  } else {
    if (state.castle_rights.CanKingsideCastle(Color::kBlack)) {
      if (!occupied.IsSet(Squares::kF8) && !occupied.IsSet(Squares::kG8))
        moves.SetBit(Squares::kG8);
    }

    if (state.castle_rights.CanQueensideCastle(Color::kBlack)) {
      if (!occupied.IsSet(Squares::kD8) && !occupied.IsSet(Squares::kC8) &&
          !occupied.IsSet(Squares::kB8))
        moves.SetBit(Squares::kC8);
    }
  }

  return moves;
}

BitBoard GetAttackedSquares(const BoardState &state, Color attacker) {
  BitBoard attacked, occupied = state.Occupied();

  attacked |= AllLeftPawnAttacks(attacker, state) |
              AllRightPawnAttacks(attacker, state);

  BitBoard knights = state.Knights(attacker);
  while (knights) {
    attacked |= KnightMoves(knights.PopLsb());
  }

  BitBoard queens = state.Queens(attacker);

  BitBoard bishops = state.Bishops(attacker) | queens;
  while (bishops) {
    attacked |= BishopMoves(bishops.PopLsb(), occupied);
  }

  BitBoard rooks = state.Rooks(attacker) | queens;
  while (rooks) {
    attacked |= RookMoves(rooks.PopLsb(), occupied);
  }

  BitBoard king = state.King(attacker);
  if (king) {
    // King is only in one position
    attacked |= KingAttacks(king.PopLsb());
  }

  return attacked;
}

BitBoard GetAttackersTo(const BoardState &state,
                        Square square,
                        const BitBoard &occupied,
                        Color attacker) {
  const BitBoard queens = state.Queens();

  BitBoard attackers;
  attackers |= PawnAttacks(square, state, FlipColor(attacker)) & state.Pawns();
  attackers |= KnightMoves(square) & state.Knights();
  attackers |= BishopMoves(square, occupied) & (state.Bishops() | queens);
  attackers |= RookMoves(square, occupied) & (state.Rooks() | queens);
  attackers |= KingAttacks(square) & state.Kings();

  return attackers & state.Occupied(attacker);
}

BitBoard GetAttackersTo(const BoardState &state,
                        Square square,
                        Color attacker) {
  const BitBoard occupied = state.Occupied();
  const BitBoard queens = state.Queens();

  BitBoard attackers;
  attackers |= PawnAttacks(square, state, FlipColor(attacker)) & state.Pawns();
  attackers |= KnightMoves(square) & state.Knights();
  attackers |= BishopMoves(square, occupied) & (state.Bishops() | queens);
  attackers |= RookMoves(square, occupied) & (state.Rooks() | queens);
  attackers |= KingAttacks(square) & state.Kings();

  return attackers & state.Occupied(attacker);
}

BitBoard GetSlidingAttackersTo(const BoardState &state,
                               Square square,
                               const BitBoard &occupied,
                               Color attacker) {
  const BitBoard queens = state.Queens();

  BitBoard attackers;
  attackers |= BishopMoves(square, occupied) & (state.Bishops() | queens);
  attackers |= RookMoves(square, occupied) & (state.Rooks() | queens);

  return attackers & state.Occupied(attacker);
}

BitBoard &RayBetween(Square first, Square second) {
  return ray_between_masks[first][second];
}

BitBoard &RayIntersecting(Square first, Square second) {
  return ray_intersecting_masks[first][second];
}

List<Move, kMaxMoves> GenerateMoves(MoveType move_type, Board &board) {
  List<Move, kMaxMoves> move_list;

  auto &state = board.GetState();

  const BitBoard occupied = state.Occupied();
  const BitBoard &their_pieces = state.Occupied(FlipColor(state.turn));

  BitBoard targets = 0;
  if (move_type & MoveType::kQuiet) targets |= ~occupied;
  if (move_type & MoveType::kCaptures) targets |= their_pieces;

  if (state.checkers) {
    // Only king moves are legal if there's multiple pieces checking the king
    if (state.checkers.MoreThanOne()) {
      const auto king_square = state.King(state.turn).GetLsb();

      auto possible_moves = KingMoves(king_square, state) & targets;
      while (possible_moves) {
        const Square to = possible_moves.PopLsb();
        move_list.Push(Move(king_square, to));
      }

      return move_list;
    }
  }

  const BitBoard en_passant_mask = state.en_passant != Squares::kNoSquare
                                       ? BitBoard::FromSquare(state.en_passant)
                                       : 0;

  BitBoard pawn_targets = targets;
  if (move_type & MoveType::kTactical) {  // Promotions are tactical
    pawn_targets |= kRankMasks[kRank1] | kRankMasks[kRank8];
  } else {
    pawn_targets &= ~(kRankMasks[kRank1] | kRankMasks[kRank8]);
  }

  const int pushed_pawn_distance = state.turn == Color::kWhite ? 8 : -8;

  BitBoard single_pawn_moves = PawnPushes(state.turn, state) & pawn_targets;
  BitBoard single_pawn_moves_copy = single_pawn_moves;

  while (single_pawn_moves_copy) {
    const Square to = single_pawn_moves_copy.PopLsb(), to_rank = Rank(to);
    const Square from = to - pushed_pawn_distance;

    if (to_rank == kNumRanks - 1 || to_rank == 0) {
      move_list.Push(Move(from, to, PromotionType::kQueen));
      move_list.Push(Move(from, to, PromotionType::kRook));
      move_list.Push(Move(from, to, PromotionType::kKnight));
      move_list.Push(Move(from, to, PromotionType::kBishop));
      continue;
    } else {
      move_list.Push(Move(from, to));
    }
  }

  BitBoard double_pawn_moves =
      state.turn == Color::kWhite
          ? Shift<Direction::kNorth>(single_pawn_moves & kRankMasks[kRank3])
          : Shift<Direction::kSouth>(single_pawn_moves & kRankMasks[kRank6]);
  double_pawn_moves &= targets & ~occupied;

  while (double_pawn_moves) {
    const Square to = double_pawn_moves.PopLsb();
    const Square from = to - pushed_pawn_distance * 2;
    move_list.Push(Move(from, to));
  }

  if (move_type & MoveType::kCaptures) {
    const BitBoard pawn_capture_targets = their_pieces | en_passant_mask;

    const int left_pawn_capture_dist = state.turn == Color::kWhite ? 7 : -7;
    const int right_pawn_capture_dist = state.turn == Color::kWhite ? 9 : -9;

    BitBoard left_pawn_captures =
        AllLeftPawnAttacks(state.turn, state) & pawn_capture_targets;
    while (left_pawn_captures) {
      const Square to = left_pawn_captures.PopLsb(), to_rank = Rank(to);
      const Square from = to - left_pawn_capture_dist;

      if (to_rank == kNumRanks - 1 || to_rank == 0) {
        move_list.Push(Move(from, to, PromotionType::kQueen));
        move_list.Push(Move(from, to, PromotionType::kRook));
        move_list.Push(Move(from, to, PromotionType::kKnight));
        move_list.Push(Move(from, to, PromotionType::kBishop));
        continue;
      } else {
        move_list.Push(Move(from, to));
      }
    }

    BitBoard right_pawn_captures =
        AllRightPawnAttacks(state.turn, state) & pawn_capture_targets;
    while (right_pawn_captures) {
      const Square to = right_pawn_captures.PopLsb(), to_rank = Rank(to);
      const Square from = to - right_pawn_capture_dist;

      if (to_rank == kNumRanks - 1 || to_rank == 0) {
        move_list.Push(Move(from, to, PromotionType::kQueen));
        move_list.Push(Move(from, to, PromotionType::kRook));
        move_list.Push(Move(from, to, PromotionType::kKnight));
        move_list.Push(Move(from, to, PromotionType::kBishop));
        continue;
      } else {
        move_list.Push(Move(from, to));
      }
    }
  }

  BitBoard knights = state.Knights(state.turn) & ~state.pinned;
  while (knights) {
    const auto from = knights.PopLsb();

    auto possible_moves = KnightMoves(from) & targets;
    while (possible_moves) {
      const Square to = possible_moves.PopLsb();
      move_list.Push(Move(from, to));
    }
  }

  BitBoard bishops = state.Bishops(state.turn);
  while (bishops) {
    const auto from = bishops.PopLsb();

    auto possible_moves = BishopMoves(from, occupied) & targets;
    while (possible_moves) {
      const Square to = possible_moves.PopLsb();
      move_list.Push(Move(from, to));
    }
  }

  BitBoard rooks = state.Rooks(state.turn);
  while (rooks) {
    const auto from = rooks.PopLsb();

    auto possible_moves = RookMoves(from, occupied) & targets;
    while (possible_moves) {
      const Square to = possible_moves.PopLsb();
      move_list.Push(Move(from, to));
    }
  }

  BitBoard queens = state.Queens(state.turn);
  while (queens) {
    const auto from = queens.PopLsb();

    auto possible_moves = QueenMoves(from, occupied) & targets;
    while (possible_moves) {
      const Square to = possible_moves.PopLsb();
      move_list.Push(Move(from, to));
    }
  }

  BitBoard king = state.King(state.turn);
  const auto king_square = king.GetLsb();

  auto possible_moves = KingMoves(king_square, state) & targets;
  while (possible_moves) {
    const Square to = possible_moves.PopLsb();
    move_list.Push(Move(king_square, to));
  }

  return move_list;
}

}  // namespace move_gen