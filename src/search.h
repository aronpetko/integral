#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include "board.h"
#include "eval.h"
#include "time_mgmt.h"

const int kMaxSearchDepth = 100;
const int kScoreNone = std::numeric_limits<int>::min();

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

  void push(const Move& move) {
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

  friend std::ostream &operator<<(std::ostream& stream, PVLine& pv_line) {
    return stream << pv_line.to_string();
  }

 private:
  List<Move, kMaxPlyFromRoot> moves_;
};

enum class NodeType {
  kRoot,
  kPV,
  kNonPV
};

class Search {
 public:
  struct Result {
    Move best_move;
    PVLine pv_line;
    int score;

    Result() : score(kScoreNone), best_move(Move::null_move()) {}
  };

  struct Stack {
    int ply;
    int static_eval;
    PVLine pv;
    std::array<Move, 2> killers;

    Stack() : static_eval(kScoreNone), ply(0) {
      killers.fill(Move::null_move());
    }

    Stack *ahead(int amount = 1) {
      return this + amount;
    }

    Stack *behind(int amount = 1) {
      return this - amount;
    }
  };

  explicit Search(TimeManagement::Config &time_config, Board &board);

  static std::array<std::array<int, kMaxPlyFromRoot>, kMaxSearchDepth + 1> kLateMoveReductionTable;

  static void init_tables();

  Result go();

 private:
  template<NodeType node_type>
  int quiesce(int ply, int alpha, int beta);

  template<NodeType node_type>
  int search(int depth, int ply, int alpha, int beta, Result &result);

  Result iterative_deepening();

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  std::array<Stack, kMaxPlyFromRoot> stack_;
  int sel_depth_;
};

#endif // INTEGRAL_SEARCH_H_