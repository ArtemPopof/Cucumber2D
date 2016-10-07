/*
 * CucumberGL.cpp
 *
 *  Created on: Oct 7, 2016
 *      Author: artem96
 */

#include "CucumberGL.h"
#include <stdio.h>

CucumberGL::CucumberGL(CucumberWindow* window): currentWindow(window) {

	//development
	printf("CUCUMBERGL: CucumberGL instance is created!");

	if (window->isReadyForPainting())
		fprintf(stderr, "CUCUMBERGL: Window instance has not been initialized");

}

void CucumberGL::drawPoint(float x, float y, float z) {

	printf("CUCUMBERGL: drawPoint(floats) function is not available by now, please wait for next releases. Thank you.");

}

void CucumberGL::drawPoint(int x, int y, int z) {

	if (z != 0)
		fprintf(stderr, "CUCUMBERGL: 3D graphics is not supported by now, "
				"please wait for next releases. Thank you for your patient.");
	else
		drawPixel(x, y);

}

void CucumberGL::drawPixel(int x, int y) {

	currentWindow->drawPixel(x, y);

}


