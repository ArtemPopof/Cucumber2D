/*
 * cucumber_window.cpp
 *
 *  Created on: Oct 3, 2016
 *      Author: artem96
 */
#include "cucumber_window.h"
#include <stdio.h>
#include <stdlib.h>
#include "Platform/cucumber_system_configuration.h"
#include <X11/Xlib.h>
#include <thread>

using namespace std;

// private functions

void initSystemWindow(int);
void initX11Window();
void updateWindowThread(CucumberWindow* instance);

// private data

struct LinuxX11Window {
	Display* display;
	Window window;
	GC gc;
	int currentScreen;
};

LinuxX11Window win;
thread worker;

CucumberWindow::CucumberWindow(int windowWidth, int windowHeight)
	: windowWidth(windowWidth), windowHeight(windowHeight), visibility(false),
	  startX(0), startY(0) {

	if (!SystemConfiguration::isInitialized()) {
		fprintf(stderr, "please, init engine first with initEngine() func");
		exit(1);
	}

	//development
	printf("window has been initialized\n");
	printf("window size is %ix%i\n", windowWidth, windowHeight);
	printf("set visibility to true, if you want to see it\n");

	initSystemWindow(SystemConfiguration::getSystemType());
}

Dimension CucumberWindow::getDimension() {
	return Dimension(windowWidth, windowHeight);
}

void CucumberWindow::setDimension(Dimension dimension) {
	windowWidth = dimension.getWidth();
	windowHeight = dimension.getHeight();
}


void initSystemWindow(int systemType) {
	if (systemType != 0) {
		fprintf(stderr, "Please, run this program from Linux based operating system");
		return;
	}

	initX11Window();
}

void initX11Window() {

	// connect to first display
	win.display = XOpenDisplay(NULL);

	if (win.display == NULL) {
		fprintf(stderr, "Cannot connect to XServer!");
		exit(1);
	}

	win.currentScreen = DefaultScreen(win.display);

}

bool CucumberWindow::isVisible() {
	return visibility;
}

void CucumberWindow::setVisible(bool visible) {
	visibility = visible;
}

void CucumberWindow::showWindow() {

	using namespace std;

	CucumberWindow::setVisible(true);

	if (win.display != NULL) {

		win.window = XCreateSimpleWindow(win.display, RootWindow(win.display, win.currentScreen),
										startX, startY, windowWidth, windowHeight, 1,
										BlackPixel(win.display, win.currentScreen),
										WhitePixel(win.display, win.currentScreen));

		XSelectInput(win.display, win.window, ExposureMask | KeyPressMask);
		XMapWindow(win.display, win.window);

		win.gc = XCreateGC(win.display, win.window, 0, 0);

		thread worker(updateWindowThread, this);

		worker.join;

	}
}

CucumberWindow::~CucumberWindow() {
	setVisible(false);
	worker.join();

	XFreeGC(win.display, win.gc);
	XDestroyWindow(win.display,win.window);
	XCloseDisplay(win.display);
}


void updateWindowThread(CucumberWindow* instance) {

	XEvent* event;

	while (instance->isVisible()) {

		XNextEvent(win.display, event);

	}

}

bool CucumberWindow::isReadyForPainting() {
	if (*win.display == NULL, *win.window == NULL)
		return false;
	else
		return true;
}

void CucumberWindow::drawPixel(int x, int y) {

	if (!isReadyForPainting()) {
		return;
	}

	XDrawPoint(win.display, win.window, win.gc, x, y);


}
