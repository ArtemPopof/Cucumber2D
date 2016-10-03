/*
 * cucumber_dimension.cpp
 *
 *  Created on: Oct 3, 2016
 *      Author: artem96
 */

#include "cucumber_dimension.h"


Dimension::Dimension(int width, int height) : width(width), height(height) {

}

int Dimension::getWidth() {
	return width;
}

int Dimension::getHeight() {
	return height;
}

void Dimension::setWidth(int newWidth) {
	width = newWidth;
}

void Dimension::setHeight(int newHeight) {
	height = newHeight;
}
