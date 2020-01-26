#pragma once
#include <vector>
#include "Shape.h"

using std::vector;

class Triangle
	:public Shape
{
public:
	Triangle(float color[3], float pSize);
	bool isDrawn();

};