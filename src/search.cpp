#include "search.h"
#include "move_gen.h"
#include "transpo.h"

#include <iomanip>

namespace search {

const int kMaxSearchDepth = 25;
const double kMaxSearchTime = 5; // seconds

namespace detail {

std::chrono::steady_clock::time_point start_time;

std::optional<Move> best_move_this_iteration;

int best_eval_this_iteration = -eval::kMateScore;

}

int quiesce(Board &board, int alpha, int beta) {
  auto elapsed = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - detail::start_time).count();
  //if (elapsed >= kMaxSearchTime)
  //  return 0;

  auto &state = board.get_state();

  int evaluation = eval::evaluate(state);
  if (evaluation >= beta)
    return beta;

  //const int delta = eval::kPieceValues[static_cast<int>(PieceType::kQueen)]; // queen value
  //if (evaluation < alpha - delta)
  //  return alpha;

  if (alpha < evaluation)
    alpha = evaluation;

  for (const auto &capture : order_moves(board, generate_capture_moves(board))) {
    board.make_move(capture);
    evaluation = -quiesce(board, -beta, -alpha);
    board.undo_move();

    if (evaluation >= beta)
      return beta;

    alpha = std::max(alpha, evaluation);
  }

  return alpha;
}

int negamax(Board &board, int ply, int depth, int alpha, int beta) {
  auto elapsed = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - detail::start_time).count();
  //if (elapsed >= kMaxSearchTime)
  //  return 0;

  auto &state = board.get_state();

  if (depth == 0) {
    ++nodes_searched;
    return quiesce(board, alpha, beta);
  }

  auto &transpo_table = board.get_transpo_table();
  const int orig_alpha = alpha;

  const U64 key = state.zobrist_key;
  /*const auto tt_entry = transpo_table.probe(key);

  if (tt_entry->key != 0 && tt_entry->depth >= depth) {
    if (tt_entry->flag == TranspositionTable::Entry::kExact) {
      return tt_entry->evaluation;
    } else if (tt_entry->flag == TranspositionTable::Entry::kLowerBound) {
      alpha = std::max(alpha, tt_entry->evaluation);
    } else if (tt_entry->flag == TranspositionTable::Entry::kUpperBound) {
      beta = std::min(beta, tt_entry->evaluation);
    }

    if (alpha >= beta) {
      if (ply == 0) {
        detail::best_move_this_iteration = tt_entry->best_move;
        detail::best_eval_this_iteration = tt_entry->evaluation;
      }
      return tt_entry->evaluation; // alpha-beta cutoff
    }
  }*/

  auto moves = generate_legal_moves(board);
  if (moves.empty()) {
    // either checkmate or draw
    // prefer checkmates that are delivered in fewer moves
    int score = king_in_check(state.turn, state) ? -eval::kMateScore - depth : eval::kDrawScore;

    TranspositionTable::Entry new_entry;
    new_entry.key = key;
    new_entry.depth = depth;
    new_entry.evaluation = score;
    new_entry.flag = TranspositionTable::Entry::kExact;

    // transpo_table.save(new_entry);

    return score;
  }

  std::optional<Move> best_move;
  int best_eval = -eval::kMateScore;

  for (const auto &move : order_moves(board, moves)) {
    board.make_move(move);
    const int score = -negamax(board, ply + 1, depth - 1, -beta, -alpha);
    board.undo_move();

    elapsed = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - detail::start_time).count();
    //if (elapsed >= kMaxSearchTime)
    //  return 0;

    if (score > best_eval) {
      best_eval = score;
      best_move = move;

      if (ply == 0) {
        detail::best_move_this_iteration = best_move;
        detail::best_eval_this_iteration = best_eval;
      }
    }

    alpha = std::max(alpha, score);
    if (alpha >= beta)
      break;
  }

  TranspositionTable::Entry new_entry;
  new_entry.key = key;
  new_entry.depth = depth;
  new_entry.evaluation = best_eval;

  if (best_move.has_value())
    new_entry.best_move = best_move.value();

  if (best_eval <= orig_alpha) {
    // If the score is less than or equal to the original alpha,
    // the score is an upper bound for the true score of the position.
    new_entry.flag = TranspositionTable::Entry::kUpperBound;
  } else if (best_eval >= beta) {
    // If the score is greater than or equal to beta,
    // the score is a lower bound for the true score of the position.
    new_entry.flag = TranspositionTable::Entry::kLowerBound;
  } else {
    // If the score is within the original alpha-beta window,
    // the score is an exact evaluation of the position.
    new_entry.flag = TranspositionTable::Entry::kExact;
  }

  // transpo_table.save(new_entry);

  return best_eval;
}

int partition(std::vector<std::pair<int, Move>> &list, int low, int high) {
  // select the rightmost element as pivot
  int pivot = list[high].first;

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (list[j].first > pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      std::swap(list[i], list[j]);
    }
  }

  // swap pivot with the greater element at i
  std::swap(list[i + 1], list[high]);

  // return the partition point
  return i + 1;
}

void quick_sort(std::vector<std::pair<int, Move>> &list, int low, int high) {
  if (low < high) {
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pivot = partition(list, low, high);

    // recursive call on the left of pivot
    quick_sort(list, low, pivot - 1);

    // recursive call on the right of pivot
    quick_sort(list, pivot + 1, high);
  }
}

MoveList order_moves(Board &board, const MoveList &moves) {
  auto &state = board.get_state();
  auto &transpo_table = board.get_transpo_table();

  /*std::optional<Move> tt_move;

  const auto tt_entry = transpo_table.probe(state.zobrist_key);
  if (tt_entry->key == state.zobrist_key)
    tt_move = tt_entry->best_move;*/

  const auto is_capture = [&state](const Move &move) {
    return state.pieces[state.turn == Color::kWhite ? kBlackPieces : kWhitePieces].is_set(move.get_to());
  };

  std::vector<std::pair<int, Move>> capture_moves;
  std::vector<std::pair<int, Move>> non_capture_moves;

  for (const auto &move : moves) {
    int score = 0;

    const auto promotion_type = move.get_promotion_type();
    if (promotion_type != PromotionType::kNone) {
      score += eval::kPieceValues[static_cast<int>(promotion_type)];
    }

    if (is_capture(move)) {
      const int aggressor_piece_value = eval::kPieceValues[static_cast<int>(move.get_piece_type())];
      const int victim_piece_value = is_capture(move) ? eval::kPieceValues[static_cast<int>(get_piece_type(move.get_to(), state.pieces))] : 0;

      score += victim_piece_value * 10 - aggressor_piece_value;
      capture_moves.emplace_back(score, move);
    } else {
      non_capture_moves.emplace_back(score, move);
    }
  }

  quick_sort(capture_moves, 0, capture_moves.size() - 1);
  quick_sort(non_capture_moves, 0, non_capture_moves.size() - 1);

  MoveList ordered_moves;

  // always prefer the transposition table's stored best move first
  //if (tt_move.has_value())
  //  ordered_moves.push_back(tt_move.value());

  for (const auto &move : capture_moves) ordered_moves.push_back(move.second);
  for (const auto &move : non_capture_moves) ordered_moves.push_back(move.second);

  return ordered_moves;
}

Move find_best_move(Board &board) {
  nodes_searched = 0;

  detail::start_time = std::chrono::high_resolution_clock::now();

  //if (board.get_state().half_moves % 4 == 0)
  //  board.get_transpo_table().clear();

  Move best_move;
  int best_eval = -eval::kMateScore;

  const auto moves = order_moves(board, generate_legal_moves(board));

  for (int depth = 8; depth <= 8; depth++) {
    detail::best_move_this_iteration.reset();
    detail::best_eval_this_iteration = -eval::kMateScore;

    negamax(board, 0, depth, -eval::kMateScore, eval::kMateScore);

    if (detail::best_move_this_iteration.has_value()) {
      best_move = detail::best_move_this_iteration.value();
      best_eval = detail::best_eval_this_iteration;
    }

    auto elapsed = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - detail::start_time).count();
    if (elapsed >= kMaxSearchTime)
      break;
  }

  std::cout << "game evaluation: " << std::fixed << std::setprecision(2) << best_eval / 100.0 << std::endl;
  std::cout << "nodes searched: " << nodes_searched << std::endl;
  return best_move;
}

}