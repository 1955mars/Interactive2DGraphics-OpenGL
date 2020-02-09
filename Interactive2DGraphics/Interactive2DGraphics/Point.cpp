#include "Point.h"

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

Point::Point(float col[3], float pSize)
	: Shape(GL_POINTS, GL_POINTS, col, pSize, true, false)
{

}

bool Point::isDrawn()
{
	if (vertices.size() >= 1 * 2)
		return true;
	return false;
}