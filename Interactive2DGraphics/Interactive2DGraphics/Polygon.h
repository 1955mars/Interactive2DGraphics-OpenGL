#pragma once
#include <vector>
#include "Shape.h"

using std::vector;

class Polyg
	:public Shape
{
public:
	Polyg(float color[3], float pSize);
	bool isDrawn();

	void Draw(float mousePos[2]);
};