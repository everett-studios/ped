
#ifndef LINUX_WINDOW_H
#define LINUX_WINDOW_H

void ped_linux_window_init(unsigned int width, unsigned int height, const char *title);
void ped_linux_window_update();
int ped_linux_window_shouldClose();
void ped_linux_window_free();

#endif
