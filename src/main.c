
#include <stdio.h>
#include <stdlib.h>

#include "include/linux_window.h"

int main(int argc, char *argv[]) {
  ped_linux_window_init(1280, 720, "Ped");

  while (!ped_linux_window_shouldClose()) {
    ped_linux_window_update();
  }

  ped_linux_window_free();
  return 0;
}
