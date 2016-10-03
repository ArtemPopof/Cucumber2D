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

CucumberWindow::CucumberWindow(int windowWidth, int windowHeight)
	: windowWidth(windowWidth), windowHeight(windowHeight), visibility(false) {

	if (!SystemConfiguration::isInitialized()) {
		fprintf(stderr, "please, init engine first with initEngine() func");
		exit(1);
	}

	//development
	printf("window has been initialized\n");
	printf("window size is %ix%i\n", windowWidth, windowHeight);
	printf("set visibility to true, if you want to see it\n");



}

Dimension CucumberWindow::getDimension() {
	return Dimension(windowWidth, windowHeight);
}

void CucumberWindow::setDimension(Dimension dimension) {
	windowWidth = dimension.getWidth();
	windowHeight = dimension.getHeight();
}
