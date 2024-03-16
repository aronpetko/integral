#include "search.h"
#include "move_gen.h"
#include "transpo.h"
#include "move_orderer.h"
#include "time_mgmt.h"

#include <iomanip>

Search::Search(TimeManagement::Config &time_config, Board &board)
    : board_(board),
      best_eval_this_iteration_(0),
      following_pv_(false),
      time_mgmt_(time_config, board),
      branching_factor_(0.0),
      total_bfs_(0) {}

int Search::quiesce(int ply, int alpha, int beta) {
  if (board_.has_repeated(1)) {
    return eval::kDrawScore;
  }

  auto &state = board_.get_state();

  int stand_pat = eval::evaluate(state);
  if (stand_pat >= beta)
    return beta;

  // delta pruning
  if (stand_pat + eval::kPieceValues[PieceType::kQueen] < alpha)
    return alpha;

  if (alpha < stand_pat)
    alpha = stand_pat;

  // the game is over if we couldn't try a move
  auto legal_moves = generate_legal_moves(board_);

  if (legal_moves.empty()) {
    return king_in_check(flip_color(state.turn), state) ? -eval::kMateScore + ply : eval::kDrawScore;
  } else if (state.fifty_moves_clock >= 100) {
    return eval::kDrawScore;
  }

  MoveOrderer move_orderer(board_, filter_moves(legal_moves, MoveType::kCaptures, board_), MoveType::kCaptures);

  for (int i = 0; i < move_orderer.size(); i++) {
    board_.make_move(move_orderer.get_move(i));

    const bool in_check = state.pieces[state.turn == Color::kWhite ? kBlackKing : kWhiteKing] == 0ULL
                          || king_in_check(flip_color(state.turn), state);
    if (in_check) {
      board_.undo_move();
      continue;
    }

    const int score = -quiesce(ply + 1, -beta, -alpha);
    board_.undo_move();

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

int Search::negamax(int depth, int ply, int alpha, int beta) {
  if (board_.has_repeated(1)) {
    return eval::kDrawScore;
  }

  const auto &state = board_.get_state();
  auto &transpo = board_.get_transpo_table();

  const int original_alpha = alpha;

  const auto &tt_entry = transpo.probe(state.zobrist_key);
  if (tt_entry.key == state.zobrist_key && tt_entry.depth >= depth) {
    switch (tt_entry.flag) {
      case TranspositionTable::Entry::kExact:
        if (ply == 0) {
          best_move_this_iteration_ = tt_entry.best_move;
          best_eval_this_iteration_ = tt_entry.evaluation;
        }

        return tt_entry.evaluation;
      case TranspositionTable::Entry::kLowerBound:
        alpha = std::max(alpha, tt_entry.evaluation);
        break;
      case TranspositionTable::Entry::kUpperBound:
        beta = std::min(beta, tt_entry.evaluation);
        break;
    }

    if (alpha >= beta) {
      if (ply == 0) {
        best_move_this_iteration_ = tt_entry.best_move;
        best_eval_this_iteration_ = tt_entry.evaluation;
      }

      return tt_entry.evaluation;
    }
  }

  if (time_mgmt_.times_up()) {
    return eval::kDrawScore;
  }

  // ensure we never run quiesce when in check
  const bool in_check = king_in_check(state.turn, state);
  if (in_check) {
    depth++;
  }

  // search until we've found a "quiet" position to evaluate
  if (depth <= 0) {
    time_mgmt_.update_nodes_searched();
    following_pv_ = false;
    return quiesce(ply, alpha, beta);
  }

  const int cur_eval = eval::evaluate(state);
  const int kReverseFutilityDepthLimit = 6;

  if (depth <= kReverseFutilityDepthLimit && !following_pv_ && !in_check) {
    if (cur_eval - futility_margin(depth) >= beta)
      return cur_eval;
  }

  // null move pruning
  static bool can_do_null_move = true;

  if (can_do_null_move && depth > 2 && !in_check && !following_pv_) {
    can_do_null_move = false;
    board_.make_null_move();

    const int reduction = depth / 4 + 3;
    const int null_move_score = -negamax(depth - reduction, ply + 1, -beta, -beta + 1);

    board_.undo_move();
    can_do_null_move = true;

    if (time_mgmt_.times_up()) {
      return eval::kDrawScore;
    } else if (null_move_score >= beta) {
      return beta;
    }
  }

  MoveOrderer move_orderer(board_, generate_moves(board_), MoveType::kAll);

  int moves_tried = 0;

  Move best_move = Move::null_move();
  int best_eval = std::numeric_limits<int>::min();

  for (int i = 0; i < move_orderer.size(); i++) {
    const Move &move = move_orderer.get_move(i);

    const bool is_capture = state.pieces[state.turn == Color::kWhite ? kBlackPieces : kWhitePieces].is_set(move.get_to());
    const bool is_promotion = move.get_promotion_type() != PromotionType::kNone;

    board_.make_move(move);

    // since the move generator is pseudo-legal, we must verify legality here
    if (king_in_check(flip_color(state.turn), state)) {
      board_.undo_move();
      continue;
    }

    int score;

    if (moves_tried == 0) {
      // search the first move to full depth without reduction
      score = -negamax(depth - 1, ply + 1, -beta, -alpha);
    } else {
      // apply LMR conditions to subsequent moves
      int reduction = 0;
      if (depth >= 3 && moves_tried >= 2 && !following_pv_ && !is_promotion && !is_capture && !in_check) {
        reduction = depth <= 5 ? 1 : depth / 3;
      }

      // null window search for a quick refutation or indication of a potentially good move
      const bool old_following_pv = following_pv_;
      following_pv_ = false;
      score = -negamax(depth - 1 - reduction, ply + 1, -alpha - 1, -alpha);
      following_pv_ = old_following_pv;

      // if the move looks promising from null window search, research
      if (score > alpha || score < beta) {
        score = -negamax(depth - 1 - reduction, ply + 1, -beta, -alpha);
      }
    }

    moves_tried++;

    board_.undo_move();

    if (time_mgmt_.times_up()) {
      return eval::kDrawScore;
    }

    if (score > best_eval) {
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

Move Search::find_best_move() {
  std::cout << "static eval: " << eval::evaluate(board_.get_state()) << std::endl;

  MoveOrderer::reset_move_history();

  time_mgmt_.start();

  const int config_depth = time_mgmt_.get_config().depth;
  const int max_search_depth = config_depth ? config_depth : kMaxSearchDepth;

  Move best_move = Move::null_move();
  int best_eval;

  // iterative deepening
  for (int depth = 1; depth <= max_search_depth; depth++) {
    time_mgmt_.update_move_time();

    // save time by playing the only legal move
    auto legal_moves = generate_legal_moves(board_);
    if (legal_moves.size() == 1) {
      best_move = legal_moves[0];
      best_eval = best_eval_this_iteration_;
      break;
    }

    best_move_this_iteration_ = Move::null_move();
    best_eval_this_iteration_ = std::numeric_limits<int>::min();

    negamax(depth, 0, -std::numeric_limits<int>::max(), std::numeric_limits<int>::max());

    if (best_move_this_iteration_ != Move::null_move()) {
       std::cout << "best move: " << best_move_this_iteration_.to_string() << " | evaluation: " << std::fixed
                << std::setprecision(2) << best_eval_this_iteration_ / 100.0 << " | depth: " << depth
                << std::endl;

      best_move = best_move_this_iteration_;
      best_eval = best_eval_this_iteration_;
    }

    if (time_mgmt_.times_up()) {
      break;
    }
  }

  std::cout << "game evaluation: " << std::fixed << std::setprecision(2) << best_eval / 100.0 << std::endl;
  std::cout << "took: " << time_mgmt_.get_move_time() / 1000.0 << "s" << std::endl << std::endl;
  std::cout << "nodes searched: " << time_mgmt_.get_nodes_searched() << std::endl;
  std::cout << "nps: " << std::fixed << std::setprecision(2) << time_mgmt_.get_nodes_searched() / (time_mgmt_.get_move_time() / 1000.0) << std::endl;
  std::cout << "bf: " << branching_factor_ / total_bfs_ << std::endl;

  return best_move;
}