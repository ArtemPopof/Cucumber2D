#define IS_CUCUMBERGL_INSTALLED true

#include "cucumber_window.h"

/**
 * CucumberGL class
 *
 * Simple software 2016 realization of OpenGL clone
 * Created solely for education purposes.
 *
 */

class CucumberGL {

	CucumberWindow* currentWindow;

	void drawPixel(int x, int y);

public:

	CucumberGL(CucumberWindow* window);

	void drawPoint(float x, float y, float z = 0);
	void drawPoint(int x, int y, int z = 0);



};
