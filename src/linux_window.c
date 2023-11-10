
#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "include/linux_window.h"

Display *display;
Window window;
XEvent event;
int screen;

Atom wmDestroyWindow;
int closeRequested;

void ped_linux_window_init(unsigned int width, unsigned int height, const char *title) {
  unsigned long black, white;

  display = XOpenDisplay((char*)0);
  screen = XDefaultScreen(display);

  black = XBlackPixel(display, screen);
  white = XWhitePixel(display, screen);

  XSetWindowAttributes attribs;
  attribs.border_pixel = white;
  attribs.background_pixel = black;
  attribs.override_redirect = True;
  attribs.event_mask = ExposureMask; // add more for keyboard, mouse, etc.

  window = XCreateWindow(display, XRootWindow(display, screen), 250, 250, width, height, 0, 
    XDefaultDepth(display, screen), InputOutput, XDefaultVisual(display, screen), 
    CWBackPixel | CWBorderPixel | CWEventMask, &attribs);
  
  if (!window) {
    // TODO: logger
    printf("ERROR: Failed to create an X11 window! Aborting.\n");
    exit(1);
  }

  wmDestroyWindow = XInternAtom(display, "WM_DELETE_WINDOW", False);
  XSetWMProtocols(display, window, &wmDestroyWindow, 1);
  XSetStandardProperties(display, window, title, title, None, NULL, 0, NULL);

  XClearWindow(display, window);
  XMapRaised(display, window);  
}

int ped_linux_window_shouldClose() {
  return closeRequested;
}

void ped_linux_window_update() {
  if (XNextEvent(display, &event) == 0) {
    if (event.type == ClientMessage) {
      if (event.xclient.data.l[0] == wmDestroyWindow) {
        closeRequested = True;
      }
    }

    if (event.type == DestroyNotify) {
      closeRequested = True;
    }
  }
}

void ped_linux_window_free() {
  XDestroyWindow(display, window);
  XCloseDisplay(display);
}
