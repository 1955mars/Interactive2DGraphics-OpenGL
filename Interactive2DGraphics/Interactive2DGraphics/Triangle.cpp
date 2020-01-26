#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include <iostream>
#include <vector>
#include "Triangle.h"

Triangle::Triangle(float col[3], float pSize)
	:Shape(GL_LINE_STRIP, GL_TRIANGLES, col, pSize)
{

}

bool Triangle::isDrawn()
{
	if (vertices.size() == 3 * 2)
	{
		return true;
	}
	return false;
}
