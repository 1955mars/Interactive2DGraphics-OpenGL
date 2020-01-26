#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include <iostream>
#include <vector>
#include "Polygon.h"

Polyg::Polyg(float col[3], float pSize)
	:Shape(GL_POLYGON, GL_POLYGON, col, pSize)
{

}

bool Polyg::isDrawn()
{
	return false;
}

void Polyg::Draw(float mousePos[2])
{
	if (vertices.size() >= 4)
	{
		Shape::Draw(mousePos);
		return;
	}
	glPointSize(pointSize);
	glColor3fv(color);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < vertices.size(); i = i + 2)
	{
		glVertex2f(vertices[i], vertices[i + 1]);
	}
	glVertex2fv(mousePos);
	glEnd();
}