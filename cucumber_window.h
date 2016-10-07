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
#include "CucumberGL/CucumberGL.h"

#include <thread>

// minimum window height and width.
#define MIN_WINDOW_SIZE 5;

// just import for c++
class Dimension;
class CucumberGL;

class CucumberWindow {


private:

	int windowWidth;
	int windowHeight;

	int startX, startY;

	bool visibility;

	/**
	 * Pointer to the render function.
	 * To set function call setRenderFunction(CucumberGL*)
	 *
	 */
	void (*renderFunction)(CucumberGL*);

	CucumberGL* glInstance;

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
	~CucumberWindow();


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

	bool isReadyForPainting();

	void setVisible(bool visible);

	bool isRenderFunctionSet();

	/*
	 * Set window size. See @ref Dimension class
	 */
	void setDimension(Dimension dimension);

	/*
	 * Show window on the screen.
	 * Specify all parameters before it.
	 *
	 */

	void showWindow();

	// Graphics

	void setRenderFunction(void (*renderFunction)(CucumberGL*));

	void applyGLOperations();

	// Graphics operations

	void drawPixel(int x, int y);

};


#endif /* CUCUMBER_WINDOW_H_ */
