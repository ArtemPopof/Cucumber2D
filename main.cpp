/*
 * main.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: artem96
 */

#include "cucumber_engine.h"
#include <iostream>
#include <time.h>

void run(CucumberGL* gl);
void render(CucumberGL* gl);

int main(void) {

	Cucumber::initEngine();

	CucumberWindow window(1280,1024);

	window.setRenderFunction(render);

	srand(time(NULL));

	window.showWindow();

	return 0;
}


void render(CucumberGL* gl) {

	int x,y;

	for (int i = 0; i < 3556950; i++) {

		x = rand()%1280;
		y = rand()%1024;

		gl->drawPoint(x, y);
	}

}
