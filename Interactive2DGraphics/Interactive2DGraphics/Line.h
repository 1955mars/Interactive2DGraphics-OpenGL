#pragma once
#include "Shape.h"
#include <vector>

using std::vector;

class Line :
	public Shape
{
public:
	Line(float color[3], float pSize);
	bool isDrawn();
};