#include "eval.h"
#include "move_gen.h"

// evaluation is exactly the same as PeSTO's texel-tuned tables. using this evaluation over my own gained some +200 elo
// this will likely be reverted (even if it lowers the elo), as I don't like the idea of using someone else's evaluation
namespace eval {

const std::array<std::array<int, 64>, PieceType::kNumPieceTypes> kMiddleGameTables = {{
    // pawns
    {
        0,   0,   0,   0,   0,   0,  0,   0,
        98, 134,  61,  95,  68, 126, 34, -11,
        -6,   7,  26,  31,  65,  56, 25, -20,
        -14,  13,   6,  21,  23,  12, 17, -23,
        -27,  -2,  -5,  12,  17,   6, 10, -25,
        -26,  -4,  -4, -10,   3,   3, 33, -12,
        -35,  -1, -20, -23, -15,  24, 38, -22,
        0,   0,   0,   0,   0,   0,  0,   0,
    },
    // knights
    {
        -167, -89, -34, -49,  61, -97, -15, -107,
        -73, -41,  72,  36,  23,  62,   7,  -17,
        -47,  60,  37,  65,  84, 129,  73,   44,
        -9,  17,  19,  53,  37,  69,  18,   22,
        -13,   4,  16,  13,  28,  19,  21,   -8,
        -23,  -9,  12,  10,  19,  17,  25,  -16,
        -29, -53, -12,  -3,  -1,  18, -14,  -19,
        -105, -21, -58, -33, -17, -28, -19,  -23,
    },
    // bishops
    {
        -29,   4, -82, -37, -25, -42,   7,  -8,
        -26,  16, -18, -13,  30,  59,  18, -47,
        -16,  37,  43,  40,  35,  50,  37,  -2,
        -4,   5,  19,  50,  37,  37,   7,  -2,
        -6,  13,  13,  26,  34,  12,  10,   4,
        0,  15,  15,  15,  14,  27,  18,  10,
        4,  15,  16,   0,   7,  21,  33,   1,
        -33,  -3, -14, -21, -13, -12, -39, -21,
    },
    // rooks
    {
        32,  42,  32,  51, 63,  9,  31,  43,
        27,  32,  58,  62, 80, 67,  26,  44,
        -5,  19,  26,  36, 17, 45,  61,  16,
        -24, -11,   7,  26, 24, 35,  -8, -20,
        -36, -26, -12,  -1,  9, -7,   6, -23,
        -45, -25, -16, -17,  3,  0,  -5, -33,
        -44, -16, -20,  -9, -1, 11,  -6, -71,
        -19, -13,   1,  17, 16,  7, -37, -26,
    },
    // queens
    {
        -28,   0,  29,  12,  59,  44,  43,  45,
        -24, -39,  -5,   1, -16,  57,  28,  54,
        -13, -17,   7,   8,  29,  56,  47,  57,
        -27, -27, -16, -16,  -1,  17,  -2,   1,
        -9, -26,  -9, -10,  -2,  -4,   3,  -3,
        -14,   2, -11,  -2,  -5,   2,  14,   5,
        -35,  -8,  11,   2,   8,  15,  -3,   1,
        -1, -18,  -9,  10, -15, -25, -31, -50,
    },
    // king
    {
        -65,  23,  16, -15, -56, -34,   2,  13,
        29,  -1, -20,  -7,  -8,  -4, -38, -29,
        -9,  24,   2, -16, -20,   6,  22, -22,
        -17, -20, -12, -27, -30, -25, -14, -36,
        -49,  -1, -27, -39, -46, -44, -33, -51,
        -14, -14, -22, -46, -44, -30, -15, -27,
        1,   7,  -8, -64, -43, -16,   9,   8,
        -15,  36,  12, -54,   8, -28,  24,  14,
    }
}};

const std::array<std::array<int, 64>, PieceType::kNumPieceTypes> kEndGameTables = {{
    // pawns
    {
        0,   0,   0,   0,   0,   0,   0,   0,
        178, 173, 158, 134, 147, 132, 165, 187,
        94, 100,  85,  67,  56,  53,  82,  84,
        32,  24,  13,   5,  -2,   4,  17,  17,
        13,   9,  -3,  -7,  -7,  -8,   3,  -1,
        4,   7,  -6,   1,   0,  -5,  -1,  -8,
        13,   8,   8,  10,  13,   0,   2,  -7,
        0,   0,   0,   0,   0,   0,   0,   0,
    },
    // knights
    {
        -58, -38, -13, -28, -31, -27, -63, -99,
        -25,  -8, -25,  -2,  -9, -25, -24, -52,
        -24, -20,  10,   9,  -1,  -9, -19, -41,
        -17,   3,  22,  22,  22,  11,   8, -18,
        -18,  -6,  16,  25,  16,  17,   4, -18,
        -23,  -3,  -1,  15,  10,  -3, -20, -22,
        -42, -20, -10,  -5,  -2, -20, -23, -44,
        -29, -51, -23, -15, -22, -18, -50, -64,
    },
    // bishops
    {
        -14, -21, -11,  -8, -7,  -9, -17, -24,
        -8,  -4,   7, -12, -3, -13,  -4, -14,
        2,  -8,   0,  -1, -2,   6,   0,   4,
        -3,   9,  12,   9, 14,  10,   3,   2,
        -6,   3,  13,  19,  7,  10,  -3,  -9,
        -12,  -3,   8,  10, 13,   3,  -7, -15,
        -14, -18,  -7,  -1,  4,  -9, -15, -27,
        -23,  -9, -23,  -5, -9, -16,  -5, -17,
    },
    // rooks
    {
        13, 10, 18, 15, 12,  12,   8,   5,
        11, 13, 13, 11, -3,   3,   8,   3,
        7,  7,  7,  5,  4,  -3,  -5,  -3,
        4,  3, 13,  1,  2,   1,  -1,   2,
        3,  5,  8,  4, -5,  -6,  -8, -11,
        -4,  0, -5, -1, -7, -12,  -8, -16,
        -6, -6,  0,  2, -9,  -9, -11,  -3,
        -9,  2,  3, -1, -5, -13,   4, -20,
    },
    // queens
    {
        -9,  22,  22,  27,  27,  19,  10,  20,
        -17,  20,  32,  41,  58,  25,  30,   0,
        -20,   6,   9,  49,  47,  35,  19,   9,
        3,  22,  24,  45,  57,  40,  57,  36,
        -18,  28,  19,  47,  31,  34,  39,  23,
        -16, -27,  15,   6,   9,  17,  10,   5,
        -22, -23, -30, -16, -16, -23, -36, -32,
        -33, -28, -22, -43,  -5, -32, -20, -41,
    },
    // king
    {
        -74, -35, -18, -18, -11,  15,   4, -17,
        -12,  17,  14,  17,  17,  38,  23,  11,
        10,  17,  23,  15,  20,  45,  44,  13,
        -8,  22,  24,  27,  26,  33,  26,   3,
        -18,  -4,  21,  24,  27,  23,   9, -11,
        -19,  -3,  11,  21,  23,  16,   7,  -9,
        -27, -11,   4,  13,  14,   4,  -5, -17,
        -53, -34, -21, -11, -28, -14, -24, -43
    }
}};

const std::array<int, PieceType::kNumPieceTypes> kGamePhaseIncrements = {0, 1, 1, 2, 4, 0};
const std::array<int, PieceType::kNumPieceTypes> kMiddleGamePieceValues = {82, 337, 365, 477, 1025, 0};
const std::array<int, PieceType::kNumPieceTypes> kEndGamePieceValues = {94, 281, 297, 512, 936, 0};

bool is_mate_score(int evaluation) {
  return kMateScore - std::abs(evaluation) <= kMaxPlyFromRoot;
}

int mate_in(int evaluation) {
  if (evaluation > 0 && evaluation < kMateScore) { // mate in favor
    return (kMateScore - evaluation + 1) / 2;
  } else if (evaluation < 0 && evaluation > -kMateScore) { // mate against
    return (kMateScore + evaluation) / 2;
  }

  // not a mate score
  return evaluation;
}

bool static_exchange(const Move &move, int threshold, const BoardState &state) {
  const U8 from = move.get_from();
  const U8 to = move.get_to();

  const PieceType &from_piece = state.get_piece_type(from);
  if (from_piece == PieceType::kPawn && to == state.en_passant || // ignore en passant captures
      from_piece == PieceType::kKing && std::abs(from - to) == 2) { // ignore castling moves
    return threshold <= 0;
  }

  // score represents the maximum number of points the opponent can gain with the next capture
  int score = kSEEPieceScores[state.get_piece_type(to)] - threshold;
  // if the captured piece is worth less than what we can give up, we lose
  if (score < 0) {
    return false;
  }

  score = kSEEPieceScores[from_piece] - score;
  // if we captured a piece with equal/greater value than our capturing piece, we win
  if (score <= 0) {
    return true;
  }

  const BitBoard &pawns = state.pawns();
  const BitBoard &knights = state.knights();
  const BitBoard &bishops = state.bishops();
  const BitBoard &rooks = state.rooks();
  const BitBoard &queens = state.queens();
  const BitBoard &kings = state.kings();

  BitBoard occupied = state.occupied();
  occupied.clear_bit(from);
  occupied.clear_bit(to);

  // get all pieces that attack the capture square
  auto pawn_attackers = (move_gen::pawn_attacks(to, state, Color::kWhite, false) & state.pawns(Color::kBlack)) |
      (move_gen::pawn_attacks(to, state, Color::kBlack, false) & state.pawns(Color::kWhite));
  auto knight_attackers = move_gen::knight_moves(to) & state.knights();

  BitBoard bishop_attacks = move_gen::bishop_moves(to, occupied);
  BitBoard rook_attacks = move_gen::rook_moves(to, occupied);

  const BitBoard bishop_attackers = bishop_attacks & bishops;
  const BitBoard rook_attackers = rook_attacks & rooks;
  const BitBoard queen_attackers = (bishop_attacks | rook_attacks) & queens;
  const BitBoard king_attackers = move_gen::king_attacks(to) & kings;

  // compute all attacking pieces for this square minus the captured and capturing piece
  BitBoard all_attackers =
      pawn_attackers | knight_attackers | bishop_attackers | rook_attackers | queen_attackers | king_attackers;
  all_attackers &= occupied;

  Color turn = state.turn;
  Color winner = state.turn;

  // loop through all pieces that attack the capture square
  while (true) {
    turn = flip_color(turn);
    all_attackers &= occupied;

    const BitBoard our_attackers = all_attackers & state.occupied(turn);
    // if the current side to move has no attackers left, they lose
    if (!our_attackers) {
      break;
    }

    // without considering piece values, the winner of an exchange is whoever has more attackers
    // therefore we set the winner's side to the current side to move only after we check if they can attack
    winner = flip_color(winner);

    // find the least valuable attacker
    BitBoard next_attacker;
    int attacker_value;

    if ((next_attacker = our_attackers & pawns)) {
      attacker_value = kSEEPieceScores[PieceType::kPawn];
      occupied.clear_bit(next_attacker.get_lsb_pos());

      // add pieces that were diagonal xray attacking the captured piece
      bishop_attacks = move_gen::bishop_moves(to, occupied);
      all_attackers |= bishop_attacks & (bishops | queens);
    } else if ((next_attacker = our_attackers & knights)) {
      attacker_value = kSEEPieceScores[PieceType::kKnight];
      occupied ^= BitBoard::from_square(next_attacker.get_lsb_pos());
    } else if ((next_attacker = our_attackers & bishops)) {
      attacker_value = kSEEPieceScores[PieceType::kBishop];
      occupied.clear_bit(next_attacker.get_lsb_pos());

      // add pieces that were xray attacking the captured piece
      bishop_attacks = move_gen::bishop_moves(to, occupied);
      all_attackers |= bishop_attacks & (bishops | queens);
    } else if ((next_attacker = our_attackers & rooks)) {
      attacker_value = kSEEPieceScores[PieceType::kRook];
      occupied.clear_bit(next_attacker.get_lsb_pos());

      // add pieces that were xray attacking the captured piece
      rook_attacks = move_gen::rook_moves(to, occupied);
      all_attackers |= rook_attacks & (rooks | queens);
    } else if ((next_attacker = our_attackers & queens)) {
      attacker_value = kSEEPieceScores[PieceType::kQueen];
      occupied.clear_bit(next_attacker.get_lsb_pos());

      // add pieces that were xray attacking the captured piece
      rook_attacks = move_gen::rook_moves(to, occupied);
      bishop_attacks = move_gen::bishop_moves(to, occupied);
      all_attackers |= (rook_attacks & (queens | rooks)) | (bishop_attacks & (queens | bishops));
    } else {
      // king: check if we capture a piece that our opponent is still attacking
      return (all_attackers & state.occupied(flip_color(turn))) ? state.turn != winner : state.turn == winner;
    }

    if (next_attacker)  {
      // score represents how many points (in piece value) that the other side can gain after this capture
      // if initially a knight captured a queen, the other side can gain 3 - 9 = -6 points (indicating they can only gain a loss)
      // if we flip it and initially a queen captured a knight, the other side can gain 9 - 3 = 6 points (if they capture the queen back the least amount of points they lose is 3)
      score = -score + attacker_value;

      // if it's our opponents turn, we break only if the exchange is at a loss for them
      // if it's our turn, we break only if the exchange is either neutral or a loss for us
      if (score < (state.turn == winner)) {
        break;
      }
    }
  }

  return state.turn == winner;
}

int evaluate(const BoardState &state) {
  std::array<int, 2> middle_game_scores = {0, 0};
  std::array<int, 2> end_game_scores = {0, 0};

  // tempo bonus
  middle_game_scores[state.turn] += 10;
  end_game_scores[state.turn] += 10;

  int middle_game_phase = 0;
  for (int square = 0; square < Square::kSquareCount; square++) {
    const auto piece = state.get_piece_type(square);
    if (piece != PieceType::kNone) {
      const auto color = state.get_piece_color(square);
      const auto table_pos = color == Color::kWhite ? square ^ 56 : square;

      middle_game_scores[color] += kMiddleGamePieceValues[piece] + kMiddleGameTables[piece][table_pos];
      end_game_scores[color] += kEndGamePieceValues[piece] + kEndGameTables[piece][table_pos];

      // increase the phase of the game depending on the assigned scores
      middle_game_phase += kGamePhaseIncrements[piece];
    }
  }

  // tapered evaluation
  const int middle_game_score = middle_game_scores[state.turn] - middle_game_scores[flip_color(state.turn)];
  const int end_game_score = end_game_scores[state.turn] - end_game_scores[flip_color(state.turn)];

  const int kMaxMiddleGamePhase = 24;

  middle_game_phase = std::min(middle_game_phase, kMaxMiddleGamePhase);
  const int end_game_phase = kMaxMiddleGamePhase - middle_game_phase;

  return (middle_game_score * middle_game_phase + end_game_score * end_game_phase) / kMaxMiddleGamePhase;
}

}