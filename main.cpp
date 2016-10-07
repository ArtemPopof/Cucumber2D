/*
 * main.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: artem96
 */

#include "cucumber_engine.h"
#include <iostream>

void run(CucumberGL* gl);
void render(CucumberGL* gl);

CucumberWindow window;

int main(void) {

	Cucumber::initEngine();

	window(500,500);

	//window.setRenderCycleFunction(render);

	return 0;
}

void run(CucumberGL* gl) {

	while (window.isVisible()) {

		//render();

	}

}

void render(CucumberGL* gl) {



}
