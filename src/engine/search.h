#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include "../chess/board.h"
#include "eval.h"
#include "history.h"
#include "time_mgmt.h"

const int kMaxSearchDepth = 100;
const int kScoreNone = -eval::kInfiniteScore;

struct PVLine {
 public:
  PVLine() : moves_({}) {
    clear();
  }

  Move &operator[](int i) {
    return moves_[i];
  }

  void clear() {
    moves_.clear();
  }

  void push(const Move &move) {
    moves_.push(move);
  }

  [[nodiscard]] std::size_t length() const {
    return moves_.size();
  }

  [[nodiscard]] std::string to_string() {
    std::string str;
    for (int i = 0; i < moves_.size(); i++) {
      str += moves_[i].to_string();
      if (i < moves_.size() - 1)
        str += ' ';
    }
    return str;
  }

  friend std::ostream &operator<<(std::ostream &stream, PVLine &pv_line) {
    return stream << pv_line.to_string();
  }

 private:
  List<Move, kMaxPlyFromRoot> moves_;
};

enum class NodeType {
  kPV,
  kNonPV
};

class Search {
 public:
  struct Stack {
    [[maybe_unused]] int ply;
    int static_eval;
    PVLine pv;
    Move best_move;

    Stack() : static_eval(kScoreNone), ply(0) {}

    Stack *ahead(int amount = 1) {
      return this + amount;
    }

    Stack *behind(int amount = 1) {
      return this - amount;
    }
  };

  explicit Search(Board &board);

  void start(TimeManagement::Config &time_config);

  void stop();

 private:
  void set_time_config(TimeManagement::Config &time_config);

  void iterative_deepening();

  template<NodeType node_type>
  int quiescent_search(int ply, int alpha, int beta, Stack *stack);

  template<NodeType node_type>
  int search(int depth, int ply, int alpha, int beta, Stack *stack);

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  MoveHistory move_history_;
  // + 1 just in case we try to access memory when we're at the maximum ply
  std::array<Stack, kMaxPlyFromRoot + 1> stack_;
  int sel_depth_;
  std::atomic_bool searching;
};

#endif // INTEGRAL_SEARCH_H_