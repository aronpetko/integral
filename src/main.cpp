#include "uci.h"

#ifdef WIN32
#include <windows.h>
#endif

int main() {
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif

  uci::accept_commands();
}