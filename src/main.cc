#include "engine/uci/uci.h"

int main(int arg_count, char **args) {
  // Disable buffering to stdout
  setbuf(stdout, nullptr);

  uci::AcceptCommands(arg_count, args);
}