#include "syzygy.h"

#include <tbprobe.h>

namespace syzygy {

void SetPath(std::string_view path) {
  syzygy::enabled = path != "<empty>";
  tb_init(path.data());
}

void Free() {
  tb_free();
}

ProbeResult ProbePosition(const BoardState &state) {
  const Square en_passant =
      state.en_passant != Squares::kNoSquare ? state.en_passant : Square(0);
  const auto result = tb_probe_wdl(state.Occupied(Color::kWhite).AsU64(),
                                   state.Occupied(Color::kBlack).AsU64(),
                                   state.Kings().AsU64(),
                                   state.Queens().AsU64(),
                                   state.Rooks().AsU64(),
                                   state.Bishops().AsU64(),
                                   state.Knights().AsU64(),
                                   state.Pawns().AsU64(),
                                   state.fifty_moves_clock,
                                   0,
                                   en_passant,
                                   state.turn == Color::kWhite);

  switch (result) {
    case TB_WIN:
      return ProbeResult::kWin;
    case TB_LOSS:
      return ProbeResult::kLoss;
    case TB_RESULT_FAILED:
      return ProbeResult::kFailed;
    case TB_DRAW:
    default:
      return ProbeResult::kDraw;
  }
}

Move ConvertTbMove(TbMove move, const BoardState &state) {
  constexpr auto kPromotionPieces = std::array{PieceType::kNone,
                                               PieceType::kQueen,
                                               PieceType::kRook,
                                               PieceType::kBishop,
                                               PieceType::kKnight};

  const auto from = Square(TB_MOVE_FROM(move));
  const auto to = Square(TB_MOVE_TO(move));

  const auto promo_piece = kPromotionPieces[TB_MOVE_PROMOTES(move)];
  if (promo_piece != PieceType::kNone) {
    return Move(from, to, static_cast<PromotionType>((promo_piece + 1)));
  } else if (to == state.en_passant &&
             state.GetPieceType(from) == PieceType::kPawn) {
    return Move(from, to, MoveType::kEnPassant);
  } else {
    return Move(from, to, MoveType::kNormal);
  }
}

std::pair<ProbeResult, MoveList> ProbeRoot(const BoardState &state) {
  if (state.Occupied().PopCount() <= 7 && state.fifty_moves_clock == 0 &&
      !state.castle_rights.CanCastle(state.turn) &&
      !state.castle_rights.CanCastle(FlipColor(state.turn))) {
    MoveList root_moves;
    TbRootMoves tb_root_moves{};

    const Square en_passant =
        state.en_passant != Squares::kNoSquare ? state.en_passant : Square(0);
    auto result = tb_probe_root_dtz(state.Occupied(Color::kWhite).AsU64(),
                                    state.Occupied(Color::kBlack).AsU64(),
                                    state.Kings().AsU64(),
                                    state.Queens().AsU64(),
                                    state.Rooks().AsU64(),
                                    state.Bishops().AsU64(),
                                    state.Knights().AsU64(),
                                    state.Pawns().AsU64(),
                                    state.fifty_moves_clock,
                                    0,
                                    en_passant,
                                    state.turn == Color::kWhite,
                                    false,
                                    true,
                                    &tb_root_moves);

    // DTZ tables are unavailable
    if (result == 0) {
      result = tb_probe_root_wdl(state.Occupied(Color::kWhite).AsU64(),
                                 state.Occupied(Color::kBlack).AsU64(),
                                 state.Kings().AsU64(),
                                 state.Queens().AsU64(),
                                 state.Rooks().AsU64(),
                                 state.Bishops().AsU64(),
                                 state.Knights().AsU64(),
                                 state.Pawns().AsU64(),
                                 state.fifty_moves_clock,
                                 0,
                                 en_passant,
                                 state.turn == Color::kWhite,
                                 true,
                                 &tb_root_moves);
    }

    if (result == 0 || tb_root_moves.size == 0) {
      return {ProbeResult::kFailed, root_moves};
    }

    // Sort the TB root moves based on their scores
    std::sort(&tb_root_moves.moves[0],
              &tb_root_moves.moves[tb_root_moves.size],
              [](auto a, auto b) { return a.tbRank > b.tbRank; });

    const auto best_move_entry = tb_root_moves.moves[0];
    root_moves.Push(ConvertTbMove(best_move_entry.move, state));

    for (int i = 1; i < tb_root_moves.size; i++) {
      const auto move_entry = tb_root_moves.moves[i];
      if (move_entry.tbRank < best_move_entry.tbRank) {
        break;
      }

      root_moves.Push(ConvertTbMove(move_entry.move, state));
    }

    ProbeResult wdl;
    if (best_move_entry.tbRank >= 900)
      wdl = ProbeResult::kWin;
    else if (best_move_entry.tbRank >= -899)
      wdl = ProbeResult::kDraw;
    else {
      wdl = ProbeResult::kLoss;
    }

    return {wdl, root_moves};
  } else {
    return {ProbeResult::kFailed, {}};
  }
}

}  // namespace syzygy