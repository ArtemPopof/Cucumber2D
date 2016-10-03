/*
 * Represents encapsulated window class.
 * All graphics will be painted on this.
 *
 *  \date: Oct 2, 2016
 *      \authors: Artem Popov
 *      \version: 0.0.1
 */

#ifndef CUCUMBER_WINDOW_H_
#define CUCUMBER_WINDOW_H_

#include "Utils/cucumber_dimension.h"

// minimum window height and width.
#define MIN_WINDOW_SIZE 5;

// just import for c++
class Dimension;

class CucumberWindow {

public:

private:

	int windowWidth;
	int windowHeight;

	bool visibility;

public:

	/* @brief Simple window constructor with just two arguments
	 *
	 * Simple window constructor with just two arguments. Window
	 * will be initialized with default values.
	 *
	 * @param[in] windowWidth window width in pixels
	 * @param[in] windowHeight window height in pixels
	 */

	CucumberWindow(int windowWidth, int windowHeight);


	/* @brief Simple window constructor with just two arguments
	 *
	 * Simple window constructor without arguments. Window
	 * will be initialized with default values.
	 *
	 */

	CucumberWindow();


	/**
	 * Receive dimension of the window.
	 *
	 * @return Window width and height
	 */
	Dimension getDimension();

	/**
	 * Is window visible now
	 */
	bool isVisible();

	/*
	 * Set window size. See @ref Dimension class
	 */
	void setDimension(Dimension dimension);

};






#endif /* CUCUMBER_WINDOW_H_ */
