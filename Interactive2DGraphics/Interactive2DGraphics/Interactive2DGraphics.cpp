#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include <vector>

#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Quad.h"
#include "Polygon.h"

using std::vector;

enum class ShapeType
{
	PT,
	LINE,
	TRIANGLE,
	QUAD,
	POLYGON,
	NONE
};


ShapeType currShapeType = ShapeType::NONE;
vector <Shape*> shapes;

Shape* currShape = nullptr;

bool isDrawing = false;

float color[3];
float size = 1.0f;
float mousePos[2];


float canvasSize[] = { 10.0f, 10.0f };
int rasterSize[] = { 800, 600 };


void init(void)
{
	mousePos[0] = mousePos[1] = 0.0f;
	color[0] = color[1] = color[2] = 0.0f;
}

void drawCursor(void)
{
	glColor3fv(color);
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2fv(mousePos);
	glEnd();

}


void display(void)
{


	glClearColor(1.0, 1.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (currShapeType != ShapeType::NONE)
	{
		for (Shape* shape : shapes)
		{
			shape->Draw();
		}

		if (isDrawing)
		{
			(currShape) ? (currShape->Draw(mousePos)) : drawCursor();
		}
		else
		{
			drawCursor();
		}
	}

	glutSwapBuffers();
}

Shape* CreateCurrentShape()
{
	switch (currShapeType)
	{
		case ShapeType::PT:
			return (Shape*) new Point(color, size);
		case ShapeType::LINE:
			return (Shape*) new Line(color, size);
		case ShapeType::TRIANGLE:
			return (Shape*) new Triangle(color, size);
		case ShapeType::QUAD:
			return (Shape*) new Quad(color, size);
		case ShapeType::POLYGON:
			return (Shape*) new Polyg(color, size);
		default:
			return nullptr;
	}
	return nullptr;
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && currShapeType != ShapeType::NONE)
	{
		mousePos[0] = (float)x / rasterSize[0] * canvasSize[0];
		mousePos[1] = (rasterSize[1] - (float)y) / rasterSize[1] * canvasSize[1];

		if (!isDrawing) isDrawing = true;
		if (!currShape)
		{
			if((currShape = CreateCurrentShape()) == nullptr)
				std::cout << "Couldn't recognize current shape!" << std::endl;	
		}
		currShape->AddVertex(mousePos);
		if (currShape->isDrawn())
		{
			shapes.push_back(currShape);
			currShape = nullptr;
			isDrawing = false;
		}

		glutPostRedisplay();
	}
}

void reshape(int w, int h)
{
	rasterSize[0] = w;
	rasterSize[1] = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, canvasSize[0], 0.0, canvasSize[1]);
	glViewport(0, 0, rasterSize[0], rasterSize[1]);;

	glutPostRedisplay();
}

void motion(int x, int y)
{
	// mouse events are handled by OS, eventually. When using mouse in the raster window, it assumes top-left is the origin.
	// Note: the raster window created by GLUT assumes bottom-left is the origin.
	mousePos[0] = (float)x / rasterSize[0] * canvasSize[0];
	mousePos[1] = (float)(rasterSize[1] - y) / rasterSize[1] * canvasSize[1];

	glutPostRedisplay();
}

void updateColor()
{
	if (isDrawing)
	{
		if (currShape)
		{
			currShape->UpdateColor(color);
		}
	}	
}

//Finishes drawing for continous shapes like line strips and polygons
void finishDrawing()
{
	if ((currShapeType == ShapeType::LINE || currShapeType == ShapeType::POLYGON) && isDrawing)
	{
		if (currShape)
		{
			shapes.push_back(currShape);
			currShape = nullptr;
		}
		isDrawing = false;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	case 13:
		finishDrawing();
		break;
	}
}

void menu(int value)
{
	switch (value) {
	case 0: // clear
		for (Shape *x : shapes)
		{
			delete x;
		}
		shapes.clear();
		glutPostRedisplay();
		break;
	case 1: //exit
		exit(0);
	case 2: // red
		color[0] = 1.0f;
		color[1] = 0.0f;
		color[2] = 0.0f;
		updateColor();
		glutPostRedisplay();
		break;
	case 3: // green
		color[0] = 0.0f;
		color[1] = 1.0f;
		color[2] = 0.0f;
		updateColor();
		glutPostRedisplay();
		break;
	case 4: // blue
		color[0] = 0.0f;
		color[1] = 0.0f;
		color[2] = 1.0f;
		updateColor();
		glutPostRedisplay();
		break;
	case 5:
		currShapeType = ShapeType::PT;
		glutPostRedisplay();
		break;
	case 6:
		currShapeType = ShapeType::LINE;
		if (!isDrawing)
			isDrawing = true;
		glutPostRedisplay();
		break;
	case 7:
		currShapeType = ShapeType::TRIANGLE;
		if (!isDrawing)
			isDrawing = true;
		glutPostRedisplay();
		break;
	case 8:
		currShapeType = ShapeType::QUAD;
		glutPostRedisplay();
		break;
	case 9:
		currShapeType = ShapeType::POLYGON;
		glutPostRedisplay();
		break;

	case 10:
		size = 1.0f;
		glutPostRedisplay();
		break;

	case 11:
		size = 3.0f;
		glutPostRedisplay();
		break;

	case 12:
		size = 6.0f;
		glutPostRedisplay();
		break;

	case 13:
		finishDrawing();
		break;

	default:
		break;
	}
}

void createMenu()
{
	int colorMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Red", 2);
	glutAddMenuEntry("Green", 3);
	glutAddMenuEntry("Blue", 4);

	int objectMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Point", 5);
	glutAddMenuEntry("Line", 6);
	glutAddMenuEntry("Triangle", 7);
	glutAddMenuEntry("Quad", 8);
	glutAddMenuEntry("Polygon", 9);

	int sizeMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Small", 10);
	glutAddMenuEntry("Medium", 11);
	glutAddMenuEntry("Large", 12);

	glutCreateMenu(menu);
	glutAddMenuEntry("Clear", 0);
	glutAddMenuEntry("Cursor", 13);
	glutAddSubMenu("Objects", objectMenu);
	glutAddSubMenu("Colors", colorMenu);
	glutAddSubMenu("Size", sizeMenu);
	glutAddMenuEntry("Exit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char* argv[])
{
	init();

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(rasterSize[0], rasterSize[1]);

	glutCreateWindow("Interactive 2D Graphics");

	glutReshapeFunc(reshape);

	glutDisplayFunc(display);

	glutKeyboardFunc(keyboard);

	glutMouseFunc(mouse);

	glutPassiveMotionFunc(motion);

	createMenu();

	glutMainLoop();

	return 0;

}