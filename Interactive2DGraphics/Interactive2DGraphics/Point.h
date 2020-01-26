#pragma once
#include "Shape.h"
class Point 
	:public Shape
{
public:
	Point(float color[3], float pSize);
	bool isDrawn();
};