#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include "Shape.h"

Shape::Shape(int _glShapeDrawing, int _glShapeDrawn, float col[3], float pSize)
{
	glShapeDrawing = _glShapeDrawing;
	glShapeDrawn = _glShapeDrawn;

	color[0] = col[0];
	color[1] = col[1];
	color[2] = col[2];

	pointSize = pSize;
}

void Shape::UpdateColor(float col[3])
{
	color[0] = col[0];
	color[1] = col[1];
	color[2] = col[2];
}

void Shape::AddVertex(float loc[2])
{
	vertices.push_back(loc[0]);
	vertices.push_back(loc[1]);
}

void Shape::Draw(void)
{
	glPointSize(pointSize);
	glLineWidth(pointSize);
	glColor3fv(color);
	glBegin(glShapeDrawn);
	for (int i = 0; i < vertices.size(); i = i + 2)
	{
		glVertex2f(vertices[i], vertices[i + 1]);
	}
	glEnd();
}

void Shape::Draw(float mousePos[2])
{
	glPointSize(pointSize);
	glLineWidth(pointSize);
	glColor3fv(color);
	glBegin(glShapeDrawing);
	for (int i = 0; i < vertices.size(); i = i + 2)
	{
		glVertex2f(vertices[i], vertices[i + 1]);
	}
	glVertex2fv(mousePos);
	glEnd();
}