#include "engine/uci/uci.h"

int main(int arg_count, char **args) {
  // Change output buffer size
  setbuf(stdout, nullptr);

  uci::AcceptCommands(arg_count, args);
}