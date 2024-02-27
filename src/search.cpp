#include "search.h"
#include "move_gen.h"

namespace search {

int negamax(Board &board, int depth, int alpha, int beta) {
  if (depth == 0) {
    ++nodes_searched;
    return eval::evaluate(board.get_state());
  }

  auto moves = generate_legal_moves(board);
  if (moves.empty()) {
    // either checkmate or draw
    if (king_in_check(board.get_state()->turn, board.get_state())) {
      return eval::kWorstScore - depth; // prefer checkmates that are delivered in fewer moves
    } else {
      return eval::kEvenScore;
    }
  }

  int best_score = eval::kWorstScore;
  for (const auto &move : order_moves(board, moves)) {
    board.make_move(move);
    best_score = std::max(best_score, -negamax(board, depth - 1, -beta, -alpha));
    board.undo_move();

    alpha = std::max(alpha, best_score);
    if (alpha >= beta)
      break;
  }

  return best_score;
}

MoveList order_moves(Board &board, const MoveList &moves) {
  auto is_capture = [&board](const Move& move) {
    const auto& state = board.get_state();
    return state->pieces[kAllPieces].is_set(move.get_to());
  };

  const auto& state = board.get_state();

  std::vector<std::pair<int, Move>> capture_moves;
  std::vector<std::pair<int, Move>> non_capture_moves;

  for (const auto& move : moves) {
    const U8 from = move.get_from();
    const U8 to = move.get_to();

    int from_piece_value = eval::kPieceValues[static_cast<int>(get_piece_type(from, state->pieces))];
    int to_piece_value = is_capture(move) ? eval::kPieceValues[static_cast<int>(get_piece_type(to, state->pieces))] : 0;

    int score = 0;

    const auto promotion_type = move.get_promotion_type();
    if (promotion_type != PromotionType::kNone) {
      // - 1 because PromotionType::kNone is at value 0 so the piece values are shifted right by 1
      score += eval::kPieceValues[static_cast<int>(promotion_type) - 1];
    }

    if (is_square_attacked(to, Color(!state->turn), state)) {
      score -= from_piece_value;
    }

    if (is_capture(move)) {
      // MVV-LVA score
      score += to_piece_value * 10 - from_piece_value; // multiply victim value to prioritize capturing higher value pieces
      capture_moves.emplace_back(score, move);
    } else {
      non_capture_moves.emplace_back(score, move);
    }
  }

  auto cmp = [](const std::pair<int, Move>& a, const std::pair<int, Move>& b) {
    return a.first > b.first;
  };

  std::ranges::sort(capture_moves, cmp);
  std::ranges::sort(non_capture_moves, cmp);

  MoveList ordered_moves;
  for (const auto& pair : capture_moves) ordered_moves.push_back(pair.second);
  for (const auto& pair : non_capture_moves) ordered_moves.push_back(pair.second);

  return ordered_moves;
}

Move find_best_move(Board &board) {
  nodes_searched = 0;

  const int kSearchDepth = 6;

  Move best_move;
  int best_move_score = eval::kWorstScore;

  int alpha = eval::kWorstScore;
  int beta = eval::kBestScore;

  for (const auto &move : order_moves(board, generate_legal_moves(board))) {
    board.make_move(move);
    const int move_score = -negamax(board, kSearchDepth - 1, -beta, -alpha);
    board.undo_move();

    if (move_score >= best_move_score) {
      best_move_score = move_score;
      best_move = move;
    }
  }

  std::cout << "nodes searched: " << nodes_searched << std::endl;
  return best_move;
}

}