#include "cuckoo.h"

namespace search::cuckoo {

void Initialize() {
  moves.fill(Move::NullMove());
  keys.fill(0);

  U32 count = 0;

  for (int piece = kKnight; piece <= kKing; ++piece) {
    for (Color color : {Color::kWhite, Color::kBlack}) {
      const int colored_piece = piece * 2 + color;
      for (int from = 0; from < 64; ++from) {
        for (int to = from + 1; to < 64; ++to) {
          BitBoard possible_moves;
          switch (piece) {
            case PieceType::kKnight:
              possible_moves = move_gen::KnightMoves(from);
              break;
            case PieceType::kBishop:
              possible_moves = move_gen::BishopMoves(from, 0);
              break;
            case PieceType::kRook:
              possible_moves = move_gen::RookMoves(from, 0);
              break;
            case PieceType::kQueen:
              possible_moves = move_gen::QueenMoves(from, 0);
              break;
            case PieceType::kKing:
              possible_moves = move_gen::KingAttacks(from);
              break;
          }

          if (!possible_moves.IsSet(to)) {
            continue;
          }

          auto move = Move(from, to);
          auto key = zobrist::pieces[colored_piece][from] ^
                     zobrist::pieces[colored_piece][to] ^ zobrist::turn;
          U32 slot = H1(key);

          while (true) {
            std::swap(keys[slot], key);
            std::swap(moves[slot], move);

            if (move == Move::NullMove()) {
              break;
            }

            slot = slot == H1(key) ? H2(key) : H1(key);
          }

          ++count;
        }
      }
    }
  }

  assert(count == 3668);
}

}  // namespace search::cuckoo