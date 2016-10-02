/*
 * main.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: artem96
 */

#include <iostream>
#include <X11/Xlib.h>
#include <stdio.h>


int main(void) {

	int screen_num;
	int screen_width;
	int screen_height;

	Window root_window;

	unsigned long white_pixel;
	unsigned long black_pixel;

	/*
	 * this variable will contain the pointer
	 * to the Display structure returned when opening connection
	 *
	 */
	Display* display;

	// open the connection to the display "simey:0".
	display = XOpenDisplay(NULL);
	if (display == NULL) {
		fprintf(stderr, "Cannot connect to X server %s\n", "simey:0");
		return 1;
	}

	screen_num = DefaultScreen(display);
	screen_width = DisplayWidth(display, screen_num);
	screen_height = DisplayHeight(display, screen_num);
	root_window = RootWindow(display, screen_num);
	white_pixel = WhitePixel(display, screen_num);
	black_pixel = BlackPixel(display, screen_num);

	printf("Screen num is: %i\n");
	printf("Screen size is: %ix%i\n", screen_width, screen_height);

	Window new_window;

	int window_height = screen_height / 2;
	int window_width = screen_width / 2;
	int window_x = 0;
	int window_y = 0;
	int win_border_width = 4;

	new_window = XCreateSimpleWindow(display,
			root_window,
			window_x, window_y,
			window_width, window_height,
			win_border_width, black_pixel,
			white_pixel);

	XMapWindow(display, new_window);
	XSelectInput(display, new_window, ExposureMask);

	GC gc;

	gc = XCreateGC(display, new_window, NULL, NULL);

	XSetForeground(display, gc, white_pixel);
	XSetBackground(display, gc, black_pixel);
	XSetFillStyle(display, gc, FillSolid);
	XSetLineAttributes(display, gc, 2, LineSolid, CapRound, JoinRound);


	XDrawPoint(display, new_window, gc, 5, 65);

	XEvent an_event;

	while (1) {

		XNextEvent(display, &an_event);

		switch (an_event.type) {
		case Expose:

			break;

		default:

			break;
		}
	}

	std::cin.get();
	std::cin.get();

	XCloseDisplay(display);

	return 0;
}

