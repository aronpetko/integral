#include "search.h"
#include "move_gen.h"
#include "transpo.h"
#include "move_orderer.h"

#include <iomanip>

namespace search {

const int kMaxSearchDepth = 99;
const int kMaxSearchTime = 15; // seconds

namespace detail {

std::chrono::steady_clock::time_point start_time;

std::optional<Move> best_move_this_iteration;

int best_eval_this_iteration;

bool search_cancelled;

bool can_do_null_move;

int nodes_searched;

}

bool should_exit_search() {
  if (detail::search_cancelled || detail::nodes_searched % 500000 == 0) {
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

  MoveOrderer move_orderer(board, generate_capture_moves(board), MoveType::kCaptures);

  for (int i = 0; i < move_orderer.size(); i++) {
    board.make_move(move_orderer.get_move(i));

    const bool in_check = state.pieces[state.turn == Color::kWhite ? kBlackKing : kWhiteKing] == 0ULL
        || king_in_check(flip_color(state.turn), state);
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
    ++detail::nodes_searched;
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

  MoveOrderer move_orderer(board, generate_legal_moves(board), MoveType::kAll);

  Move best_move;
  int best_eval = std::numeric_limits<int>::min();

  for (int i = 0; i < move_orderer.size(); i++) {
    const Move &move = move_orderer.get_move(i);

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

Move find_best_move(Board &board) {
  detail::search_cancelled = false;
  detail::can_do_null_move = true;
  detail::nodes_searched = 0;
  detail::start_time = std::chrono::steady_clock::now();

  Move best_move;
  int best_eval;

  for (int depth = 1; depth <= kMaxSearchDepth; depth++) {
    detail::best_move_this_iteration.reset();
    detail::best_eval_this_iteration = std::numeric_limits<int>::min();

    negamax(board, depth, 0, -eval::kMateScore, eval::kMateScore);

    if (detail::best_move_this_iteration.has_value()) {
      std::cout << "best move: " << detail::best_move_this_iteration->to_string() << " | evaluation: " << std::fixed
                << std::setprecision(2) << detail::best_eval_this_iteration / 100.0 << " | depth: " << depth
                << std::endl;

      best_move = detail::best_move_this_iteration.value();
      best_eval = detail::best_eval_this_iteration;
    }

    if (should_exit_search()) {
      break;
    }
  }

  const auto elapsed = std::chrono::duration<double>(std::chrono::steady_clock::now() - detail::start_time).count();

  std::cout << "game evaluation: " << std::fixed << std::setprecision(2) << best_eval / 100.0 << std::endl;
  std::cout << "nodes searched: " << detail::nodes_searched << std::endl;
  std::cout << "nps: " << std::fixed << std::setprecision(2) << (double)search::detail::nodes_searched / (double)elapsed << std::endl;

  return best_move;
}

}