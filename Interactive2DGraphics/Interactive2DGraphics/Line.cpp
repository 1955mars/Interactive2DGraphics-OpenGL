#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include <iostream>
#include <vector>
#include "Line.h"

Line::Line(float color[3], float pSize):
	Shape(GL_LINE_STRIP, GL_LINE_STRIP, color, pSize, false, true)
{

}

bool Line::isDrawn()
{
	return false;
}