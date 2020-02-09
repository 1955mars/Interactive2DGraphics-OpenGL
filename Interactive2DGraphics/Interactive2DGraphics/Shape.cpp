#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include "Shape.h"

Shape::Shape(int _glShapeDrawing, int _glShapeDrawn, float col[3], float pSize, bool usePointSize, bool useLineWidth)
{
	glShapeDrawing = _glShapeDrawing; //The inherited shapes set the shape type to be used while drawing
	glShapeDrawn = _glShapeDrawn; //The inherited shapes set the shape type to be used after it is drawn

	color[0] = col[0];
	color[1] = col[1];
	color[2] = col[2];

	pointSize = pSize;

	usesLineWidth = useLineWidth; //Inherited shapes mention if they use custom linewidth
	usesPointSize = usePointSize; //Inherited shapes mention if they use custom point size
	
	defPointSize = 1.0f;
	defLineWidth = 1.0f;
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
	SetSize();
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
	SetSize();
	glColor3fv(color);
	glBegin(glShapeDrawing);
	for (int i = 0; i < vertices.size(); i = i + 2)
	{
		glVertex2f(vertices[i], vertices[i + 1]);
	}
	glVertex2fv(mousePos);
	glEnd();
}

void Shape::SetSize(void)
{
	if (usesPointSize)
		glPointSize(pointSize);
	else
		glPointSize(defPointSize);

	if (usesLineWidth)
		glLineWidth(pointSize);
	else
		glLineWidth(defLineWidth);
}