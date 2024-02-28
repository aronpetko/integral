#include "search.h"
#include "move_gen.h"

namespace search {

int quiesce(Board &board, int alpha, int beta) {
  const int evaluation = eval::evaluate(board.get_state());
  if (evaluation >= beta)
    return beta;

  const int delta = eval::kPieceValues[static_cast<int>(PieceType::kQueen) - 1]; // queen value
  if (evaluation < alpha - delta)
    return alpha;

  if (alpha < evaluation)
    alpha = evaluation;

  const auto capture_moves = order_moves(board, generate_capture_moves(board));
  for (const auto &capture : capture_moves) {
    board.make_move(capture);
    const int score = -quiesce(board, -beta, -alpha);
    board.undo_move();

    if (score >= beta)
      return beta;
    alpha = std::max(alpha, score);
  }

  if (capture_moves.empty() && king_in_check(board.get_state()->turn, board.get_state())) {
    const auto all_moves = order_moves(board, generate_legal_moves(board));
    for (const auto &move : all_moves) {
      board.make_move(move);
      const int score = -quiesce(board, -beta, -alpha);
      board.undo_move();

      if (score >= beta)
        return beta;
      alpha = std::max(alpha, score);
    }
  }

  return alpha;
}

int negamax(Board &board, int depth, int alpha, int beta) {
  if (depth == 0) {
    ++nodes_searched;
    return quiesce(board, alpha, beta);
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
  const auto& state = board.get_state();

  const auto is_capture = [&board, &state](const Move &move) {
    return state->pieces[state->turn == Color::kWhite ? kBlackPieces : kWhitePieces].is_set(move.get_to());
  };

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