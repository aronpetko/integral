#include "search.h"
#include "move_gen.h"
#include "transpo.h"
#include "move_orderer.h"
#include "time_mgmt.h"

#include <iomanip>
#include <format>

Search::Search(TimeManagement::Config &time_config, Board &board)
    : board_(board),
      best_eval_this_iteration_(0),
      following_pv_(false),
      time_mgmt_(time_config, board),
      branching_factor_(0.0),
      total_bfs_(0) {}

int Search::quiesce(int ply, int alpha, int beta) {
  if (board_.has_repeated(1))
    return eval::kDrawScore;

  auto &state = board_.get_state();

  int stand_pat = eval::evaluate(state);
  if (stand_pat >= beta)
    return beta;

  // delta pruning
  if (stand_pat + eval::kPieceValues[PieceType::kQueen] < alpha)
    return alpha;

  if (alpha < stand_pat)
    alpha = stand_pat;

  auto legal_moves = generate_legal_moves(board_);
  if (legal_moves.empty()) {
    return king_in_check(flip_color(state.turn), state) ? -eval::kMateScore + ply : eval::kDrawScore;
  } else if (state.fifty_moves_clock >= 100) {
    return eval::kDrawScore;
  }

  MoveOrderer move_orderer(board_, filter_moves(legal_moves, MoveType::kCaptures, board_), MoveType::kCaptures);

  for (int i = 0; i < move_orderer.size(); i++) {
    board_.make_move(move_orderer.get_move(i));
    const int score = -quiesce(ply + 1, -beta, -alpha);
    board_.undo_move();

    time_mgmt_.update_nodes_searched();

    if (score >= beta)
      return beta;

    alpha = std::max(alpha, score);
  }

  return alpha;
}

int futility_margin(int depth) {
  const int kMarginIncrement = 120;
  const int kBaseMargin = 100;

  return kBaseMargin + depth * kMarginIncrement;
}

int Search::negamax(int depth, int ply, int alpha, int beta, PVLine &pv_line) {
  if (board_.has_repeated(1))
    return eval::kDrawScore;

  const auto &state = board_.get_state();
  auto &transpo = board_.get_transpo_table();

  const int original_alpha = alpha;
  const auto &tt_entry = transpo.probe(state.zobrist_key);

  if (tt_entry.key == state.zobrist_key && tt_entry.depth >= depth) {
    const auto corrected_tt_eval = transpo.correct_eval(tt_entry.evaluation, ply);

    switch (tt_entry.flag) {
      case TranspositionTable::Entry::kExact:
        if (ply == 0 && board_.is_legal_move(tt_entry.best_move)) {
          best_move_this_iteration_ = tt_entry.best_move;
          best_eval_this_iteration_ = corrected_tt_eval;
        }

        if (!following_pv_) {
          // this move caused a beta cutoff, so it is considered a pv move
          pv_line.clear();
          pv_line.push(tt_entry.best_move);
        }

        return corrected_tt_eval;
      case TranspositionTable::Entry::kLowerBound:
        alpha = std::max(alpha, corrected_tt_eval);
        break;
      case TranspositionTable::Entry::kUpperBound:
        beta = std::min(beta, corrected_tt_eval);
        break;
    }

    if (alpha >= beta) {
      if (ply == 0) {
        best_move_this_iteration_ = tt_entry.best_move;
        best_eval_this_iteration_ = corrected_tt_eval;
      }

      if (!following_pv_) {
        // this move caused a beta cutoff, so it is considered a pv move
        pv_line.clear();
        pv_line.push(tt_entry.best_move);
      }

      return corrected_tt_eval;
    }
  }

  if (time_mgmt_.times_up() && !best_move_this_iteration_.is_null()) {
    return eval::kDrawScore;
  }

  // ensure we never run quiesce when in check
  const bool in_check = king_in_check(state.turn, state);
  if (in_check) {
    depth++;
  }

  // search until we've found a "quiet" position to evaluate
  if (depth <= 0) {
    following_pv_ = false;
    return quiesce(ply, alpha, beta);
  }

  const int static_eval = eval::evaluate(state);
  const int kReverseFutilityDepthLimit = 6;

  if (depth <= kReverseFutilityDepthLimit && !following_pv_ && !in_check) {
    if (static_eval - futility_margin(depth) >= beta)
      return static_eval;
  }

  // null move pruning
  static bool can_do_null_move = true;

  if (can_do_null_move && depth > 2 && !in_check && !following_pv_) {
    can_do_null_move = false;
    board_.make_null_move();

    const int reduction = depth >= 6 ? 3 : 2;
    const int null_move_score = -negamax(depth - reduction, ply + 1, -beta, -beta + 1, pv_line);

    board_.undo_move();
    can_do_null_move = true;

    if (time_mgmt_.times_up() && !best_move_this_iteration_.is_null()) {
      return eval::kDrawScore;
    } else if (null_move_score >= beta) {
      return beta;
    }
  }

  int moves_tried = 0;

  Move best_move = Move::null_move();
  int best_eval = std::numeric_limits<int>::min();
  PVLine child_pv_line;

  MoveOrderer move_orderer(board_, generate_moves(board_), MoveType::kAll);
  for (int i = 0; i < move_orderer.size(); i++) {
    const Move &move = move_orderer.get_move(i);

    const bool is_capture = state.piece_types[move.get_to()] != PieceType::kNone;
    const bool is_promotion = move.get_promotion_type() != PromotionType::kNone;

    board_.make_move(move);

    // since the move generator is pseudo-legal, we must verify legality here
    if (king_in_check(flip_color(state.turn), state)) {
      board_.undo_move();
      continue;
    }

    time_mgmt_.update_nodes_searched();
    const int prev_nodes_searched = time_mgmt_.get_nodes_searched();

    int score;

    // search the first move to full depth without reduction
    if (moves_tried == 0) {
      score = -negamax(depth - 1, ply + 1, -beta, -alpha, child_pv_line);
    } else {
      // apply LMR conditions to subsequent moves
      int reduction = 0;
      if (depth >= 3 && moves_tried >= 2 && !is_promotion && !is_capture && !in_check) {
        reduction = depth <= 5 ? 1 : std::min(depth / 3, 3);
      }

      // null window search for a quick refutation or indication of a potentially good move
      const bool old_following_pv = following_pv_;
      following_pv_ = false;
      score = -negamax(depth - 1 - reduction, ply + 1, -alpha - 1, -alpha, child_pv_line);
      following_pv_ = old_following_pv;

      // if the move looks promising from null window search, research
      if (score > alpha && score < beta) {
        score = -negamax(depth - 1 - reduction, ply + 1, -beta, -alpha, child_pv_line);
      }
    }

    board_.undo_move();
    moves_tried++;

    if (ply == 0) {
      time_mgmt_.update_node_spent_table(move, prev_nodes_searched);
    }

    if (time_mgmt_.times_up() && !best_move_this_iteration_.is_null()) {
      return eval::kDrawScore;
    }

    // alpha is raised, therefore this move is the new pv node for this depth
    if (score > best_eval) {
      pv_line.clear();
      pv_line.push(move);

      for (int child_pv_move = 0; child_pv_move < child_pv_line.length(); child_pv_move++)
        pv_line.push(child_pv_line[child_pv_move]);

      best_eval = score;
      best_move = move;

      if (ply == 0) {
        best_move_this_iteration_ = best_move;
        best_eval_this_iteration_ = best_eval;
      }
    }

    alpha = std::max(alpha, best_eval);

    // this opponent has a better move, so we prune this branch
    if (alpha >= beta) {
      if (!is_capture) {
        MoveOrderer::update_killer_move(move, depth);
        MoveOrderer::update_move_history(move, state.turn, depth);
      }
      break;
    }
  }

  // the game is over if we couldn't try a move
  if (moves_tried == 0) {
    return in_check ? -eval::kMateScore + ply : eval::kDrawScore;
  } else {
    if (state.fifty_moves_clock >= 100) {
      best_eval = eval::kDrawScore;
      best_move = Move::null_move();
    }

    branching_factor_ += pow(moves_tried, 1.0 / depth);
    total_bfs_++;
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

Search::Result Search::go() {
  MoveOrderer::reset_move_history();

  time_mgmt_.start();

  const int config_depth = time_mgmt_.get_config().depth;
  const int max_search_depth = config_depth ? config_depth : kMaxSearchDepth;

  Result result;

  time_mgmt_.update_move_time(Move::null_move());

  // iterative deepening
  for (int depth = 1; depth <= max_search_depth; depth++) {
    pv_line_this_iteration_.clear();
    best_move_this_iteration_ = Move::null_move();
    best_eval_this_iteration_ = std::numeric_limits<int>::min();
    following_pv_ = true;

    negamax(depth, 0, -std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), pv_line_this_iteration_);

    if (best_move_this_iteration_ != Move::null_move()) {
      std::string info;
      if (eval::is_mate_score(best_eval_this_iteration_)) {
        info = std::format("info depth {} score mate {} nodes {} nps {} time {} seldepth {} pv {}",
                           depth,
                           eval::mate_in(best_eval_this_iteration_),
                           time_mgmt_.get_nodes_searched(),
                           static_cast<int>(time_mgmt_.get_nodes_searched() / (time_mgmt_.time_elapsed() / 1000.0)),
                           time_mgmt_.time_elapsed(),
                           pv_line_this_iteration_.length(),
                           pv_line_this_iteration_.to_string());
      } else {
        info = std::format("info depth {} score cp {} nodes {} nps {} time {} seldepth {} pv {}",
                           depth,
                           best_eval_this_iteration_,
                           time_mgmt_.get_nodes_searched(),
                           static_cast<int>(time_mgmt_.get_nodes_searched() / (time_mgmt_.time_elapsed() / 1000.0)),
                           time_mgmt_.time_elapsed(),
                           pv_line_this_iteration_.length(),
                           pv_line_this_iteration_.to_string());
      }

      std::cout << info << std::endl;

      result.pv_line = pv_line_this_iteration_;
      result.best_move = best_move_this_iteration_;
      result.evaluation = best_eval_this_iteration_;
    }

    time_mgmt_.update_move_time(result.best_move);
    if (time_mgmt_.times_up()) {
      break;
    }
  }

  return result;
}