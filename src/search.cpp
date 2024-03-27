#include "search.h"
#include "move_gen.h"
#include "transpo.h"
#include "move_orderer.h"
#include "time_mgmt.h"

#include <iomanip>
#include <format>

Search::Search(TimeManagement::Config &time_config, Board &board)
    : board_(board),
      time_mgmt_(time_config, board),
      branching_factor_(0.0),
      total_bfs_(0),
      can_do_null_move_(true) {}

std::array<std::array<int, 512>, Search::kMaxSearchDepth + 1> Search::kLateMoveReductionTable;

void Search::init_tables() {
  const double kBaseReduction = 0.77;
  const double kDivisor = 2.36;

  for (int depth = 1; depth <= kMaxSearchDepth; depth++) {
    for (int move = 1; move < 512; move++) {
      Search::kLateMoveReductionTable[depth][move] =
          static_cast<int>(kBaseReduction + log(depth) + log(move) / kDivisor);
    }
  }
}

int Search::quiesce(int ply, int alpha, int beta) {
  auto &state = board_.get_state();

  if (board_.is_draw())
    return eval::kDrawScore;

  int static_eval = eval::evaluate(state);
  if (static_eval >= beta || ply >= kMaxGameMoves)
    return static_eval;

  // delta pruning
  if (static_eval + eval::kPieceValues[PieceType::kQueen] < alpha)
    return alpha;

  alpha = std::max(alpha, static_eval);

  int best_score = static_eval;

  MoveOrderer move_orderer(board_, generate_capture_moves(board_), MoveType::kCaptures);
  for (int i = 0; i < move_orderer.size(); i++) {
    if (time_mgmt_.times_up()) {
      return 0;
    }

    const auto &move = move_orderer.get_move(i);

    board_.make_move(move);
    // since the move generator is pseudo-legal, we must verify legality here
    if (king_in_check(flip_color(state.turn), state)) {
      board_.undo_move();
      continue;
    }

    const int score = -quiesce(ply + 1, -beta, -alpha);
    board_.undo_move();

    if (score > best_score) {
      best_score = score;

      if (score >= beta) {
        MoveOrderer::update_killer_move(move, ply);
        break;
      }

      alpha = std::max(alpha, score);
    }
  }

  return best_score;
}

int Search::search(int depth, int ply, int alpha, int beta, PVLine &pv_line) {
  // check for repetitions of this position and the fifty-move rule
  if (board_.is_draw()) {
    return eval::kDrawScore;
  }

  const bool in_pv_node = (beta - alpha) > 1;

  const auto &state = board_.get_state();
  auto &transpo = board_.get_transpo_table();

  const int original_alpha = alpha;

  // probe the transposition table to see if we can:
  // a) return an exact score for this position if it's been evaluated before
  // b) update alpha if this position score indicates a better option us
  // c) update beta if this position's score suggests a worse option for the opponent
  const auto &tt_entry = transpo.probe(state.zobrist_key);
  if (!in_pv_node && tt_entry.key == state.zobrist_key && tt_entry.depth >= depth) {
    const auto corrected_tt_eval = transpo.correct_score(tt_entry.score, ply);
    switch (tt_entry.flag) {
      case TranspositionTable::Entry::kExact:
        return corrected_tt_eval;
      case TranspositionTable::Entry::kLowerBound:
        alpha = std::max(alpha, corrected_tt_eval);
        break;
      case TranspositionTable::Entry::kUpperBound:
        beta = std::min(beta, corrected_tt_eval);
        break;
    }

    // since alpha and beta might have been adjusted, we check if we can prune this branch early
    // known as a "beta" cutoff
    if (alpha >= beta) {
      return corrected_tt_eval;
    }
  }

  int extensions = 0;

  // extend the main search if we're when in check to ensure we fully explore our options
  // essentially delay entering quiescent search
  const bool in_check = king_in_check(state.turn, state);
  if (in_check) {
    extensions++;
  }

  // enter quiescent search to return a final score for the original position
  // this ensures that we never evaluate positions where we may miss a tactic
  if (depth <= 0) {
    return quiesce(ply, alpha, beta);
  }

  // reverse (static) futility pruning
  // we assume that the static evaluation of the current position can't fall below beta within the next move
  // the margin for this comparison is scaled based on how many moves left we have to search
  const int kReverseFutilityDepthLimit = 6;
  if (depth <= kReverseFutilityDepthLimit && !in_pv_node && !in_check) {
    const int kMarginIncrement = 120;
    const int kBaseMargin = 100;

    const int futility_margin = kBaseMargin + depth * kMarginIncrement;
    const int static_eval = eval::evaluate(state);
    if (static_eval - futility_margin >= beta) {
      return static_eval;
    }
  }

  // null move pruning
  // forfeit a move to our opponent and perform a shallow search
  // if the search indicates a winning position, it's safe to assume this move too good and
  // the opponent wouldn't have allowed this position to occur, so we prune this branch
  if (can_do_null_move_ && depth > 2 && !in_check && !in_pv_node) {
    // nmp is considered unsafe in positions that zugwang is likely to occur
    const bool safe_to_nmp = state.knights() || state.bishops() || state.rooks() || state.queens();
    if (safe_to_nmp) {
      can_do_null_move_ = false;
      board_.make_null_move();

      PVLine dummy_pv;
      const int reduction = depth / 4 + 3;
      const int null_move_score = -search(depth - reduction, ply + 1, -beta, -alpha, dummy_pv);

      board_.undo_move();
      can_do_null_move_ = true;

      if (null_move_score >= beta) {
        return null_move_score > eval::kMateScore - kMaxGameMoves ? beta : null_move_score;
      }
    }
  }
  can_do_null_move_ = true;

  PVLine temp_pv_line;
  MoveList quiet_non_cutoffs;
  int moves_tried = 0;

  Move best_move = Move::null_move();
  int best_score = std::numeric_limits<int>::min();

  // order the list of moves to increase the likelihood of pruning this branch
  MoveOrderer move_orderer(board_, generate_moves(board_), MoveType::kAll);
  for (int i = 0; i < move_orderer.size(); i++) {
    const Move &move = move_orderer.get_move(i);

    const bool is_capture = move.is_capture(state);
    const bool is_promotion = move.get_promotion_type() != PromotionType::kNone;

    board_.make_move(move);

    // since the move generator is pseudo-legal, we must verify legality here
    if (king_in_check(flip_color(state.turn), state)) {
      board_.undo_move();
      continue;
    }

    const bool is_quiet = !is_capture && !is_promotion;

    PVLine child_pv_line;
    int score;

    // move ordering places the moves that are most likely to cause a beta cutoff first
    // therefore, we save time on searching moves that are less likely to be good by reducing the search depth for them
    int reduction = 0;
    if (depth >= 2 && moves_tried > 1 && is_quiet && !in_check) {
      reduction = kLateMoveReductionTable[depth][moves_tried];
    }

    // principal variation search (pvs)
    // search the first move with a normal alpha-beta window
    if (moves_tried == 0) {
      score = -search(depth - 1 - reduction, ply + 1, -beta, -alpha, child_pv_line);
    } else {
      // null window search for a quick refutation or indication of a potentially good move
      score = -search(depth - 1 - reduction, ply + 1, -alpha - 1, -alpha, child_pv_line);

      // if the move looks promising from null window search, research to obtain a more accurate score
      if (score > alpha && (in_pv_node || reduction > 0)) {
        score = -search(depth - 1 + extensions, ply + 1, -beta, -alpha, child_pv_line);
      }
    }

    board_.undo_move();

    time_mgmt_.update_nodes_searched();
    moves_tried++;

    if (time_mgmt_.times_up() && !best_move.is_null()) {
      temp_pv_line.clear();
      return 0;
    }

    // alpha is raised, therefore this move is the new pv node for this depth
    if (score > best_score) {
      best_score = score;
      best_move = move;

      temp_pv_line.clear();
      temp_pv_line.push(move);

      for (int child_pv_move = 0; child_pv_move < child_pv_line.length(); child_pv_move++) {
        temp_pv_line.push(child_pv_line[child_pv_move]);
      }
    }

    alpha = std::max(alpha, best_score);

    // this opponent has a better move, so we prune this branch
    if (alpha >= beta) {
      if (is_quiet) {
        MoveOrderer::update_killer_move(move, depth);
        MoveOrderer::update_move_history(move, quiet_non_cutoffs, state.turn, depth);
        MoveOrderer::update_counter_move_history(state.move_played, move);
      }
      break;
    }
    else if (is_quiet) {
      quiet_non_cutoffs.push(move);
    }
  }

  pv_line = temp_pv_line;

  // the game is over if we couldn't try a move
  if (moves_tried == 0) {
    return in_check ? -eval::kMateScore + ply : eval::kDrawScore;
  }

  TranspositionTable::Entry entry;
  entry.key = state.zobrist_key;
  entry.score = best_score;
  entry.depth = depth;
  entry.move = best_move;

  if (best_score <= original_alpha) {
    entry.flag = TranspositionTable::Entry::kUpperBound;
  } else if (best_score >= beta) {
    entry.flag = TranspositionTable::Entry::kLowerBound;
  } else {
    entry.flag = TranspositionTable::Entry::kExact;
  }

  transpo.save(entry, ply);
  return best_score;
}

Search::Result Search::search_root(int depth, int ply, int alpha, int beta) {
  Search::Result result;

  const auto &state = board_.get_state();
  const bool in_check = king_in_check(state.turn, state);

  PVLine temp_pv_line;
  MoveList quiet_non_cutoffs;
  int moves_tried = 0;

  // order the list of moves to increase the likelihood of pruning this branch
  MoveOrderer move_orderer(board_, generate_moves(board_), MoveType::kAll);
  for (int i = 0; i < move_orderer.size(); i++) {
    const Move &move = move_orderer.get_move(i);

    const bool is_capture = move.is_capture(state);
    const bool is_promotion = move.get_promotion_type() != PromotionType::kNone;

    board_.make_move(move);

    // since the move generator is pseudo-legal, we must verify legality here
    if (king_in_check(flip_color(state.turn), state)) {
      board_.undo_move();
      continue;
    }

    const bool is_quiet = !is_capture && !is_promotion;

    time_mgmt_.update_nodes_searched();
    const auto prev_nodes_searched = time_mgmt_.get_nodes_searched();

    PVLine child_pv_line;
    int score;

    // move ordering places the moves that are most likely to cause a beta cutoff first
    // therefore, we save time on searching moves that are less likely to be good by reducing the search depth for them
    int reduction = 0;
    if (depth >= 2 && moves_tried > 1 && is_quiet && !in_check) {
      reduction = kLateMoveReductionTable[depth][moves_tried];
    }

    // principal variation search (pvs)
    // search the first move with a normal alpha-beta window
    if (moves_tried == 0) {
      score = -search(depth - 1 - reduction, ply + 1, -beta, -alpha, child_pv_line);
    } else {
      // null window search for a quick refutation or indication of a potentially good move
      score = -search(depth - 1 - reduction, ply + 1, -alpha - 1, -alpha, child_pv_line);

      // if the move looks promising from null window search, research to obtain a more accurate score
      if (score > alpha) {
        score = -search(depth - 1, ply + 1, -beta, -alpha, child_pv_line);
      }
    }

    board_.undo_move();
    moves_tried++;

    time_mgmt_.update_node_spent_table(move, prev_nodes_searched);
    if (time_mgmt_.times_up() && !result.best_move.is_null()) {
      break;
    }

    // this opponent has a better move, so we prune this branch
    if (score > result.score) {
      result.score = score;
      result.best_move = move;

      temp_pv_line.clear();
      temp_pv_line.push(move);

      for (int child_pv_move = 0; child_pv_move < child_pv_line.length(); child_pv_move++)
        temp_pv_line.push(child_pv_line[child_pv_move]);
    }

    alpha = std::max(alpha, result.score);

    // this opponent has a better move, so we prune this branch
    if (alpha >= beta) {
      if (is_quiet) {
        MoveOrderer::update_killer_move(move, depth);
        MoveOrderer::update_move_history(move, quiet_non_cutoffs, state.turn, depth);
        MoveOrderer::update_counter_move_history(state.move_played, move);
      }
      break;
    }
    else if (is_quiet) {
      quiet_non_cutoffs.push(move);
    }
  }

  result.pv_line = temp_pv_line;

  // the game is over if we couldn't try a move
  if (moves_tried == 0) {
    result.score = in_check ? -eval::kMateScore + ply : eval::kDrawScore;
  }

  return result;
}

Search::Result Search::iterative_deepening() {
  Search::Result result;

  MoveOrderer::reset_move_history();

  const int config_depth = time_mgmt_.get_config().depth;
  const int max_search_depth = config_depth ? config_depth : kMaxSearchDepth;

  for (int depth = 1; depth <= max_search_depth; depth++) {
    can_do_null_move_ = true;

    const int kAspirationWindow = 75;
    const int kAspirationMinDepth = 4;

    int alpha = depth >= kAspirationMinDepth ? result.score - kAspirationWindow : -std::numeric_limits<int>::max();
    int beta = depth >= kAspirationMinDepth ? result.score + kAspirationWindow : std::numeric_limits<int>::max();

    auto new_result = search_root(depth, 0, alpha, beta);
    if (new_result.score <= alpha || new_result.score >= beta) {
      alpha = -std::numeric_limits<int>::max();
      beta = std::numeric_limits<int>::max();
      new_result = search_root(depth, 0, alpha, beta);
    }

    if (!new_result.best_move.is_null()) {
      result = new_result;
    }

    const bool is_mate = eval::is_mate_score(result.score);
    std::cout << std::format("info depth {} score {} {} nodes {} nps {} time {} seldepth {} pv {}",
                             depth,
                             is_mate ? "mate" : "cp",
                             is_mate ? eval::mate_in(result.score) : result.score,
                             time_mgmt_.get_nodes_searched(),
                             static_cast<int>(time_mgmt_.get_nodes_searched() / std::max(1.0, time_mgmt_.time_elapsed() / 1000.0)),
                             time_mgmt_.time_elapsed(),
                             result.pv_line.length(),
                             result.pv_line.to_string()) << std::endl;

    if (time_mgmt_.times_up() || time_mgmt_.root_times_up(result.best_move)) {
      break;
    }
  }

  return result;
}

Search::Result Search::go() {
  time_mgmt_.start();
  const auto result = iterative_deepening();
  time_mgmt_.stop();
  return result;
}