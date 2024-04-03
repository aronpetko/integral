#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include "board.h"
#include "eval.h"
#include "time_mgmt.h"

const int kMaxSearchDepth = 100;
const int kScoreNone = std::numeric_limits<int>::min();

struct PVLine {
 public:
  PVLine() : moves_({}), move_count_(0) {
    clear();
  }

  Move &operator[](int i) {
    return moves_[i];
  }

  void clear() {
    moves_.fill(Move::null_move());
    move_count_ = 0;
  }

  void push(const Move& move) {
    moves_[move_count_++] = move;
  }

  [[nodiscard]] std::size_t length() const {
    return move_count_;
  }

  [[nodiscard]] std::string to_string() const {
    std::string str;
    for (int i = 0; i < move_count_; i++) {
      str += moves_[i].to_string();
      if (i < move_count_ - 1)
        str += ' ';
    }
    return str;
  }

  friend std::ostream& operator<<(std::ostream& stream, PVLine& pv_line) {
    return stream << pv_line.to_string();
  }

 private:
  std::array<Move, kMaxPlyFromRoot> moves_;
  int move_count_;
};

enum class NodeType {
  kRoot,
  kPV,
  kNonPV
};

class Search {
 public:
  explicit Search(TimeManagement::Config &time_config, Board &board);

  static std::array<std::array<int, kMaxPlyFromRoot>, kMaxSearchDepth + 1> kLateMoveReductionTable;

  static void init_tables();

  struct Result {
    Move best_move;
    PVLine pv_line;
    int score;

    Result() : score(kScoreNone) {}
  };

  Result go();

 private:
  template<NodeType node_type>
  int quiesce(int ply, int alpha, int beta);

  template<NodeType node_type>
  int search(int depth, int ply, int alpha, int beta,Result &result);

  Result iterative_deepening();

  struct Stack {
    int static_eval;
    PVLine pv;

    Stack() : static_eval(kScoreNone) {}

    Stack *ahead(int amount = 1) {
      return this + amount;
    }

    Stack *behind(int amount = 1) {
      return this - amount;
    }
  };

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  std::array<Stack, kMaxPlyFromRoot> stack_;
};

#endif // INTEGRAL_SEARCH_H_