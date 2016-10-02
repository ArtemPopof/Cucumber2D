/*
 * cucumber_dimension.h
 *
 * Dimension class. just abstact object with width and height
 *
 *
 * @date 2.10.16
 * @authors Artem Popov
 * @version 1.0
 *
 *
 */

class Dimension {

	// width of the object
	int width;

	// height of the object
	int height;



public:

	/*
	 * Simple Constructor.
	 *
	 * @param[in] width width of the object
	 * @param[in] height height of the object
	 *
	 */
	Dimension(int width, int height);



	void setWidth(int newWidth);
	void setHeight(int newHeight);

	int getWidth();
	int getHeight();

};
