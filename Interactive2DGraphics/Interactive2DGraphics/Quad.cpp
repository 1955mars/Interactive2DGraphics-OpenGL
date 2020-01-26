#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include <iostream>
#include <vector>
#include "Quad.h"

Quad::Quad(float col[3], float pSize)
	:Shape(GL_LINE_LOOP, GL_QUADS, col, pSize)
{

}

bool Quad::isDrawn()
{
	if (vertices.size() == 2 * 2)
	{
		return true;
	}
	return false;
}

void Quad::Draw()
{
	glPointSize(pointSize);
	glColor3fv(color);
	glBegin(GL_QUADS);
	glVertex2f(vertices[0], vertices[1]);
	glVertex2f(vertices[2], vertices[1]);
	glVertex2f(vertices[2], vertices[3]);
	glVertex2f(vertices[0], vertices[3]);
	
	glEnd();
}

void Quad::Draw(float mousePos[2])
{
	glPointSize(pointSize);
	glColor3fv(color);
	glBegin(GL_LINE_LOOP);
	glVertex2f(vertices[0], vertices[1]);
	glVertex2f(mousePos[0], vertices[1]);
	glVertex2f(mousePos[0], mousePos[1]);
	glVertex2f(vertices[0], mousePos[1]);
	
	glEnd();
}