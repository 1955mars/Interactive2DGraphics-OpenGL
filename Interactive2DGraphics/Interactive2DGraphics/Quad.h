#pragma once
#include <vector>
#include "Shape.h"

using std::vector;

class Quad
	:public Shape
{
public:
	Quad(float color[3], float pSize);
	bool isDrawn();

	void Draw(void);
	void Draw(float mousePos[2]);

};