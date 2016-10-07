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

int main(void) {

	Cucumber::initEngine();

	CucumberWindow window(500,500);

	window.setRenderFunction(render);

	return 0;
}


void render(CucumberGL* gl) {

	printf("drawing action accured\n");

}
