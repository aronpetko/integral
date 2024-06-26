#include "engine/uci/uci.h"

int main(int arg_count, char **args) {
  // Change output buffer size
  setvbuf(stdout, nullptr, _IOLBF, 1024);

  uci::AcceptCommands(arg_count, args);
}