#include "move_gen.h"

#include "../magics/attacks.h"
#include "../magics/precomputed.h"
#include "board.h"

namespace move_gen {

constexpr std::array<BitBoard, 64> GenerateKnightMasks() {
  std::array<BitBoard, 64> masks{};
  for (int square = 0; square < kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::FromSquare(square);
    masks[square] |= (src_mask & ~kFileMasks[kFileH]) << 17;
    masks[square] |= (src_mask & ~(kFileMasks[kFileH] | kFileMasks[kFileG]))
                  << 10;
    masks[square] |=
        (src_mask & ~(kFileMasks[kFileH] | kFileMasks[kFileG])) >> 6;
    masks[square] |= (src_mask & ~kFileMasks[kFileH]) >> 15;
    masks[square] |= (src_mask & ~kFileMasks[kFileA]) << 15;
    masks[square] |= (src_mask & ~(kFileMasks[kFileA] | kFileMasks[kFileB]))
                  << 6;
    masks[square] |=
        (src_mask & ~(kFileMasks[kFileA] | kFileMasks[kFileB])) >> 10;
    masks[square] |= (src_mask & ~kFileMasks[kFileA]) >> 17;
  }
  return masks;
}

constexpr std::array<BitBoard, 64> GenerateKingMasks() {
  std::array<BitBoard, 64> masks{};
  for (int square = 0; square < kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::FromSquare(square);

    masks[square] |= Shift<Direction::kNorth>(src_mask);
    masks[square] |= Shift<Direction::kSouth>(src_mask);
    masks[square] |= Shift<Direction::kEast>(src_mask);
    masks[square] |= Shift<Direction::kWest>(src_mask);
    masks[square] |= Shift<Direction::kNorthEast>(src_mask);
    masks[square] |= Shift<Direction::kNorthWest>(src_mask);
    masks[square] |= Shift<Direction::kSouthEast>(src_mask);
    masks[square] |= Shift<Direction::kSouthWest>(src_mask);
  }
  return masks;
}

constexpr std::array<std::array<BitBoard, 64>, 2> GeneratePawnAttackMasks() {
  std::array<std::array<BitBoard, 64>, 2> masks{};
  for (int square = 0; square < kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::FromSquare(square);

    masks[Color::kWhite][square] |= Shift<Direction::kNorthEast>(src_mask);
    masks[Color::kWhite][square] |= Shift<Direction::kNorthWest>(src_mask);
    masks[Color::kBlack][square] |= Shift<Direction::kSouthEast>(src_mask);
    masks[Color::kBlack][square] |= Shift<Direction::kSouthWest>(src_mask);
  }
  return masks;
}

constexpr std::array<std::array<BitBoard, 64>, 64> GenerateRayBetweenMasks() {
  std::array<std::array<BitBoard, 64>, 64> masks{};
  for (int square = 0; square < kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::FromSquare(square);
    const BitBoard src_bishop_rays =
        magics::attacks::GenerateBishopMoves(Square(square), 0ULL);
    const BitBoard src_rook_rays =
        magics::attacks::GenerateRookMoves(Square(square), 0ULL);

    for (int other_square = 0; other_square < kSquareCount; other_square++) {
      if (square == other_square) {
        continue;
      }

      const BitBoard dest_mask = BitBoard::FromSquare(other_square);
      if (src_bishop_rays & dest_mask) {
        // Calculate the rays between square and other_square
        masks[square][other_square] =
            magics::attacks::GenerateBishopMoves(Square(square), dest_mask) &
            magics::attacks::GenerateBishopMoves(Square(other_square),
                                                 src_mask);
      } else if (src_rook_rays & dest_mask) {
        // Calculate the rays between square and other_square
        masks[square][other_square] =
            magics::attacks::GenerateRookMoves(Square(square), dest_mask) &
            magics::attacks::GenerateRookMoves(Square(other_square), src_mask);
      }
    }
  }
  return masks;
}

constexpr std::array<std::array<BitBoard, 64>, 64> GenerateRayIncludingMasks() {
  std::array<std::array<BitBoard, 64>, 64> masks{};
  for (int square = 0; square < kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::FromSquare(square);
    const BitBoard src_bishop_rays =
        magics::attacks::GenerateBishopMoves(Square(square), 0ULL);
    const BitBoard src_rook_rays =
        magics::attacks::GenerateRookMoves(Square(square), 0ULL);

    for (int other_square = 0; other_square < kSquareCount; other_square++) {
      if (square == other_square) {
        continue;
      }

      const BitBoard dest_mask = BitBoard::FromSquare(other_square);
      if (src_bishop_rays & dest_mask) {
        // Calculate the rays between square and other_square
        masks[square][other_square] =
            magics::attacks::GenerateBishopMoves(Square(square), dest_mask) &
            magics::attacks::GenerateBishopMoves(Square(other_square),
                                                 src_mask);
      } else if (src_rook_rays & dest_mask) {
        // Calculate the rays between square and other_square
        masks[square][other_square] =
            magics::attacks::GenerateRookMoves(Square(square), dest_mask) &
            magics::attacks::GenerateRookMoves(Square(other_square), src_mask);
      }
      masks[square][other_square] = masks[square][other_square] |
                                    (1ULL << square) | (1ULL << other_square);
    }
  }
  return masks;
}

constexpr std::array<std::array<BitBoard, 64>, 64>
GenerateRayIntersectingMasks() {
  std::array<std::array<BitBoard, 64>, 64> masks{};
  for (int square = 0; square < kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::FromSquare(square);
    const BitBoard src_bishop_rays =
        magics::attacks::GenerateBishopMoves(Square(square), 0ULL);
    const BitBoard src_rook_rays =
        magics::attacks::GenerateRookMoves(Square(square), 0ULL);

    for (int other_square = 0; other_square < kSquareCount; other_square++) {
      if (square == other_square) {
        continue;
      }

      const BitBoard dest_mask = BitBoard::FromSquare(other_square);
      if (src_bishop_rays & dest_mask) {
        // Calculate the rays that intersect square and other_square
        masks[square][other_square] =
            (src_mask | src_bishop_rays) &
            (dest_mask |
             magics::attacks::GenerateBishopMoves(Square(other_square), 0ULL));
      } else if (src_rook_rays & dest_mask) {
        // Calculate the rays that intersect square and other_square
        masks[square][other_square] =
            (src_mask | src_rook_rays) &
            (dest_mask |
             magics::attacks::GenerateRookMoves(Square(other_square), 0ULL));
      }
    }
  }
  return masks;
}

constexpr auto kKnightMasks = GenerateKnightMasks();
constexpr auto kKingMasks = GenerateKingMasks();
constexpr auto kPawnAttackMasks = GeneratePawnAttackMasks();
// Must be const because magic attacks are initialized at runtime
const auto kRayBetweenMasks = GenerateRayBetweenMasks();
const auto kRayIncludingMasks = GenerateRayIncludingMasks();
const auto kRayIntersectingMasks = GenerateRayIntersectingMasks();

BitBoard PawnPushMoves(Square square, const BoardState &state) {
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

BitBoard PawnAttacks(BitBoard pawns, Color side) {
  if (side == Color::kWhite) {
    return Shift<Direction::kNorthEast>(pawns) |
           Shift<Direction::kNorthWest>(pawns);
  } else {
    return Shift<Direction::kSouthEast>(pawns) |
           Shift<Direction::kSouthWest>(pawns);
  }
}

BitBoard PawnAttacks(Square square, Color side) {
  return kPawnAttackMasks[side][square];
}

BitBoard KnightMoves(Square square) {
  return kKnightMasks[square];
}

BitBoard BishopMoves(Square square, const BitBoard& occupied) {
  const auto &index = magics::attacks::GetBishopAttackIndex(square, occupied);
  return magics::attacks::kBishopAttacks[square][index];
}

BitBoard RookMoves(Square square, const BitBoard& occupied) {
  const auto &index = magics::attacks::GetRookAttackIndex(square, occupied);
  return magics::attacks::kRookAttacks[square][index];
}

BitBoard QueenMoves(Square square, const BitBoard &occupied) {
  return BishopMoves(square, occupied) | RookMoves(square, occupied);
}

BitBoard KingMoves(Square square, const BoardState &state) {
  return KingAttacks(square);
}

BitBoard KingAttacks(Square square) {
  return kKingMasks[square];
}

BitBoard CastlingMoves(Color side, const BoardState &state) {
  BitBoard moves, occupied = state.Occupied();

  if (side == Color::kWhite) {
    if (state.castle_rights.CanKingsideCastle(Color::kWhite)) {
      moves.SetBit(state.castle_rights.CastleSq(Color::kWhite, CastleRights::kKingside));
    }

    if (state.castle_rights.CanQueensideCastle(Color::kWhite)) {
      moves.SetBit(state.castle_rights.CastleSq(Color::kWhite, CastleRights::kQueenside));
    }
  } else {
    if (state.castle_rights.CanKingsideCastle(Color::kBlack)) {
      moves.SetBit(state.castle_rights.CastleSq(Color::kBlack, CastleRights::kKingside));
    }

    if (state.castle_rights.CanQueensideCastle(Color::kBlack)) {
      moves.SetBit(state.castle_rights.CastleSq(Color::kBlack, CastleRights::kQueenside));
    }
  }

  return moves;
}

BitBoard GetAttackersTo(const BoardState &state,
                        Square square,
                        const BitBoard &occupied,
                        Color attacker) {
  const BitBoard queens = state.Queens();

  BitBoard attackers;
  attackers |= PawnAttacks(square, FlipColor(attacker)) & state.Pawns();
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
  attackers |= PawnAttacks(square, FlipColor(attacker)) & state.Pawns();
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

BitBoard RayBetween(Square first, Square second) {
  return kRayBetweenMasks[first][second];
}

BitBoard RayIncluding(Square first, Square second) {
  return kRayIncludingMasks[first][second];
}

BitBoard RayIntersecting(Square first, Square second) {
  return kRayIntersectingMasks[first][second];
}

void AddPromotions(Square from, Square to, MoveList &move_list) {
  move_list.Push(Move(from, to, PromotionType::kQueen));
  move_list.Push(Move(from, to, PromotionType::kKnight));
  move_list.Push(Move(from, to, PromotionType::kRook));
  move_list.Push(Move(from, to, PromotionType::kBishop));
}

template <MoveGenType move_type>
void AddPawnMoves(const Board &board, MoveList &move_list) {
  auto &state = board.GetState();

  const BitBoard occupied = state.Occupied();
  const BitBoard their_pieces = state.Occupied(FlipColor(state.turn));

  BitBoard targets = 0;
  if constexpr (move_type & MoveGenType::kQuiet) targets = ~occupied;
  if constexpr (move_type & MoveGenType::kNoisy)
    targets |= kRankMasks[kRank8] | kRankMasks[kRank1];

  const BitBoard en_passant = state.en_passant != Squares::kNoSquare
                                ? BitBoard::FromSquare(state.en_passant)
                                : 0;

  const BitBoard pawns = state.Pawns(state.turn);

  if (state.turn == Color::kWhite) {
    const BitBoard promoting_pawns = pawns & kRankMasks[kRank7];
    const BitBoard non_promoting_pawns = ~promoting_pawns & pawns;

    if (move_type & MoveGenType::kQuiet) {
      // Single pushes
      const BitBoard pushed_pawns =
          Shift<Direction::kNorth>(non_promoting_pawns) & ~occupied;
      for (Square to : pushed_pawns) {
        const Square from = to - 8;
        move_list.Push(Move(from, to));
      }
      // Double pushes
      for (Square to :
           Shift<Direction::kNorth>(pushed_pawns & kRankMasks[kRank3]) &
               ~occupied) {
        const Square from = to - 16;
        move_list.Push(Move(from, to));
      }
    }

    if (move_type & MoveGenType::kNoisy) {
      // Push promotions
      for (Square to : Shift<Direction::kNorth>(promoting_pawns) & ~occupied) {
        const Square from = to - 8;
        AddPromotions(from, to, move_list);
      }
      // Left capture promotions
      for (Square to :
           Shift<Direction::kNorthWest>(promoting_pawns) & their_pieces) {
        const Square from = to - 7;
        AddPromotions(from, to, move_list);
      }
      // Right capture promotions
      for (Square to :
           Shift<Direction::kNorthEast>(promoting_pawns) & their_pieces) {
        const Square from = to - 9;
        AddPromotions(from, to, move_list);
      }
      // Left captures
      for (Square to :
           Shift<Direction::kNorthWest>(non_promoting_pawns) & their_pieces) {
        const Square from = to - 7;
        move_list.Push(Move(from, to));
      }
      // Right captures
      for (Square to :
           Shift<Direction::kNorthEast>(non_promoting_pawns) & their_pieces) {
        const Square from = to - 9;
        move_list.Push(Move(from, to));
      }
      // En passant captures
      if (en_passant) {
        // Left en passant
        for (Square to : Shift<Direction::kNorthWest>(pawns) & en_passant) {
          const Square from = to - 7;
          move_list.Push(Move(from, to, MoveType::kEnPassant));
        }
        // Right en passant
        for (Square to : Shift<Direction::kNorthEast>(pawns) & en_passant) {
          const Square from = to - 9;
          move_list.Push(Move(from, to, MoveType::kEnPassant));
        }
      }
    }
  } else {
    const BitBoard promoting_pawns = pawns & kRankMasks[kRank2];
    const BitBoard non_promoting_pawns = ~promoting_pawns & pawns;

    if (move_type & MoveGenType::kQuiet) {
      // Single pushes
      const BitBoard pushed_pawns =
          Shift<Direction::kSouth>(non_promoting_pawns) & ~occupied;
      for (Square to : pushed_pawns) {
        const Square from = to + 8;
        move_list.Push(Move(from, to));
      }
      // Double pushes
      for (Square to :
           Shift<Direction::kSouth>(pushed_pawns & kRankMasks[kRank6]) &
               ~occupied) {
        const Square from = to + 16;
        move_list.Push(Move(from, to));
      }
    }

    if (move_type & MoveGenType::kNoisy) {
      // Push promotions
      for (Square to : Shift<Direction::kSouth>(promoting_pawns) & ~occupied) {
        const Square from = to + 8;
        AddPromotions(from, to, move_list);
      }
      // Left capture promotions
      for (Square to :
           Shift<Direction::kSouthEast>(promoting_pawns) & their_pieces) {
        const Square from = to + 7;
        AddPromotions(from, to, move_list);
      }
      // Right capture promotions
      for (Square to :
           Shift<Direction::kSouthWest>(promoting_pawns) & their_pieces) {
        const Square from = to + 9;
        AddPromotions(from, to, move_list);
      }
      // Left captures
      for (Square to :
           Shift<Direction::kSouthEast>(non_promoting_pawns) & their_pieces) {
        const Square from = to + 7;
        move_list.Push(Move(from, to));
      }
      // Right captures
      for (Square to :
           Shift<Direction::kSouthWest>(non_promoting_pawns) & their_pieces) {
        const Square from = to + 9;
        move_list.Push(Move(from, to));
      }
      // En passant captures
      if (en_passant) {
        // Left en passant
        for (Square to : Shift<Direction::kSouthWest>(pawns) & en_passant) {
          const Square from = to + 9;
          move_list.Push(Move(from, to, MoveType::kEnPassant));
        }
        // Right en passant
        for (Square to : Shift<Direction::kSouthEast>(pawns) & en_passant) {
          const Square from = to + 7;
          move_list.Push(Move(from, to, MoveType::kEnPassant));
        }
      }
    }
  }
}

template MoveList GenerateMoves<MoveGenType::kAll>(const Board &board);
template MoveList GenerateMoves<MoveGenType::kQuiet>(const Board &board);
template MoveList GenerateMoves<MoveGenType::kNoisy>(const Board &board);

template <MoveGenType move_type>
MoveList GenerateMoves(const Board &board) {
  MoveList move_list;
  const auto &state = board.GetState();

  const BitBoard occupied = state.Occupied();
  const BitBoard &their_pieces = state.Occupied(FlipColor(state.turn));

  BitBoard targets = 0;
  if constexpr (move_type & MoveGenType::kQuiet) targets |= ~occupied;
  if constexpr (move_type & MoveGenType::kNoisy) targets |= their_pieces;

  const Square king_square = state.King(state.turn).GetLsb();
  if (state.checkers.MoreThanOne()) {
    // Only king moves are legal if there's multiple pieces checking the king
    for (Square to : KingAttacks(king_square) & targets) {
      move_list.Push(Move(king_square, to, MoveType::kNormal));
    }
    return move_list;
  }

  AddPawnMoves<move_type>(board, move_list);

  // Other piece moves
  for (Square from : state.Knights(state.turn) & ~state.pinned[state.turn]) {
    for (Square to : KnightMoves(from) & targets) {
      move_list.Push(Move(from, to));
    }
  }

  for (Square from : state.Bishops(state.turn)) {
    for (Square to : BishopMoves(from, occupied) & targets) {
      move_list.Push(Move(from, to));
    }
  }

  for (Square from : state.Rooks(state.turn)) {
    for (Square to : RookMoves(from, occupied) & targets) {
      move_list.Push(Move(from, to));
    }
  }

  for (Square from : state.Queens(state.turn)) {
    for (Square to : QueenMoves(from, occupied) & targets) {
      move_list.Push(Move(from, to));
    }
  }

  for (Square to : KingAttacks(king_square) & targets) {
    move_list.Push(Move(king_square, to, MoveType::kNormal));
  }

  if (!state.checkers && move_type & MoveGenType::kQuiet) {
    for (Square to : CastlingMoves(state.turn, state)) {
      move_list.Push(Move(king_square, to, MoveType::kCastle));
    }
  }

  return move_list;
}

}  // namespace move_gen