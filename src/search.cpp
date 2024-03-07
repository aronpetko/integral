#include "search.h"
#include "move_gen.h"
#include "transpo.h"

#include <iomanip>
#include <thread>

namespace search {

const int kMaxSearchDepth = 25;
const int kMaxSearchTime = 15; // seconds

namespace detail {

std::chrono::steady_clock::time_point start_time;

std::optional<Move> best_move_this_iteration;

int best_eval_this_iteration;

bool search_cancelled;

inline bool can_do_null_move = true;

}

bool should_exit_search() {
  if (detail::search_cancelled || nodes_searched % 200000 == 0) {
    const auto elapsed = std::chrono::duration<double>(std::chrono::steady_clock::now() - detail::start_time).count();
    if (elapsed >= kMaxSearchTime)
      return detail::search_cancelled = true;
  }

  return false;
}

int quiesce(Board &board, int alpha, int beta) {
  auto &state = board.get_state();

  int stand_pat = eval::evaluate(state);
  if (stand_pat >= beta)
    return beta;

  if (alpha < stand_pat)
    alpha = stand_pat;

  MoveList capture_moves;

  for (const auto &capture : order_moves(board, generate_capture_moves(board))) {
    board.make_move(capture);

    const bool in_check = state.pieces[state.turn == Color::kWhite ? kBlackKing : kWhiteKing] == 0ULL || king_in_check(Color(!state.turn), state);
    if (in_check) {
      board.undo_move();
      continue;
    }

    const int score = -quiesce(board, -beta, -alpha);
    board.undo_move();

    if (score >= beta)
      return beta;

    alpha = std::max(alpha, score);
  }

  return alpha;
}

int negamax(Board &board, int depth, int ply, int alpha, int beta) {
  auto &state = board.get_state();
  auto &transpo = board.get_transpo_table();

  const int original_alpha = alpha;

  auto tt_entry = transpo.probe(state.zobrist_key);
  if (tt_entry->key == state.zobrist_key && tt_entry->depth >= depth) {
    switch (tt_entry->flag) {
      case TranspositionTable::Entry::kExact:
        if (ply == 0) {
          detail::best_move_this_iteration = tt_entry->best_move;
          detail::best_eval_this_iteration = tt_entry->evaluation;
        }

        return tt_entry->evaluation;
      case TranspositionTable::Entry::kLowerBound:
        alpha = std::max(alpha, tt_entry->evaluation);
        break;
      case TranspositionTable::Entry::kUpperBound:
        beta = std::min(beta, tt_entry->evaluation);
        break;
    }

    if (alpha >= beta) {
      if (ply == 0) {
        detail::best_move_this_iteration = tt_entry->best_move;
        detail::best_eval_this_iteration = tt_entry->evaluation;
      }

      return tt_entry->evaluation;
    }
  }

  if (should_exit_search()) {
    return 0;
  }

  if (depth <= 0) {
    ++nodes_searched;
    return quiesce(board, alpha, beta);
  }

  auto moves = generate_legal_moves(board);
  if (moves.empty()) {
    // prefer checkmates that are delivered in fewer moves
    return king_in_check(state.turn, state) ? -eval::kMateScore + ply : eval::kDrawScore;
  }

  // null move heuristic
  if (detail::can_do_null_move && !king_in_check(state.turn, state)) {
    detail::can_do_null_move = false;

    board.make_null_move();
    const int reduction = depth > 6 ? 3 : 2;
    const int null_move_score = -negamax(board, depth - reduction, ply + 1, -beta, -alpha);

    board.undo_move();

    detail::can_do_null_move = true;
    if (null_move_score >= beta) {
      return beta;
    }
  }

  // detail::can_do_null_move = true;

  Move best_move;
  int best_eval = std::numeric_limits<int>::min();

  for (const auto &move : order_moves(board, moves)) {
    board.make_move(move);
    const int score = -negamax(board, depth - 1, ply + 1, -beta, -alpha);
    board.undo_move();

    if (should_exit_search()) {
      return 0;
    }

    if (score > best_eval) {
      best_eval = score;
      best_move = move;

      if (ply == 0) {
        detail::best_move_this_iteration = best_move;
        detail::best_eval_this_iteration = best_eval;
      }
    }

    alpha = std::max(alpha, best_eval);
    if (alpha >= beta) {

      break;
    }
  }

  TranspositionTable::Entry entry;
  entry.key = state.zobrist_key;
  entry.evaluation = best_eval;
  entry.depth = depth;
  entry.best_move = best_move;

  if (best_eval <= original_alpha)
    entry.flag = TranspositionTable::Entry::kUpperBound;
  else if (best_eval >= beta)
    entry.flag = TranspositionTable::Entry::kLowerBound;
  else
    entry.flag = TranspositionTable::Entry::kExact;

  transpo.save(entry, ply);

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

  std::optional<Move> tt_move;
  const auto tt_entry = transpo_table.probe(state.zobrist_key);

  if (tt_entry->key == state.zobrist_key)
    tt_move = tt_entry->best_move;

  const auto is_capture = [&state](const Move &move) {
    return state.pieces[state.turn == Color::kWhite ? kBlackPieces : kWhitePieces].is_set(move.get_to());
  };

  std::vector<std::pair<int, Move>> valued_moves;

  for (const auto &move : moves) {
    int score = 0;

    const auto promotion_type = move.get_promotion_type();
    if (promotion_type != PromotionType::kNone) {
      score += eval::kPieceValues[static_cast<int>(promotion_type)];
    }

    if (is_capture(move)) {
      const int aggressor_piece_value = eval::kPieceValues[static_cast<int>(move.get_piece_type())];
      const int victim_piece_value = eval::kPieceValues[static_cast<int>(get_piece_type(move.get_to(), state.pieces))];

      // 1000 for move valuation
      score += 1000 + victim_piece_value * 10 - aggressor_piece_value;
    }

    valued_moves.emplace_back(score, move);
  }

  quick_sort(valued_moves, 0, valued_moves.size() - 1);

  MoveList ordered_moves;

  // always prefer the transposition table's stored best move first
  if (tt_move.has_value())
    ordered_moves.push_back(tt_move.value());

  for (const auto &move : valued_moves) ordered_moves.push_back(move.second);
  return ordered_moves;
}

Move find_best_move(Board &board) {
  nodes_searched = 0;

  detail::start_time = std::chrono::steady_clock::now();
  detail::search_cancelled = false;

  Move best_move;
  int best_eval;

  for (int depth = 1; depth <= kMaxSearchDepth; depth++) {
    detail::best_move_this_iteration.reset();
    detail::best_eval_this_iteration = std::numeric_limits<int>::min();

    negamax(board, depth, 0, -eval::kMateScore, eval::kMateScore);

    if (detail::best_move_this_iteration.has_value()) {
      std::cout << "Best Move: " << detail::best_move_this_iteration->to_string() << " | Evaluation: " << std::fixed << std::setprecision(2) << detail::best_eval_this_iteration / 100.0 << " | Depth: " << depth << std::endl;
      best_move = detail::best_move_this_iteration.value();
      best_eval = detail::best_eval_this_iteration;
    }

    if (should_exit_search()) {
      break;
    }
  }

  std::cout << "game evaluation: " << std::fixed << std::setprecision(2) << best_eval / 100.0 << std::endl;
  std::cout << "nodes searched: " << nodes_searched << std::endl;
  return best_move;
}

}