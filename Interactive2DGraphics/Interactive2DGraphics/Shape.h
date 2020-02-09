#pragma once

#include <vector>

using std::vector;

class Shape
{
public:
	Shape(int _glShapeDrawing, int _glShapeDrawn, float col[3], float pSize, bool usePointSize, bool useLineWidth);
	void UpdateColor(float color[3]);
	void AddVertex(float loc[2]) ;

	virtual void Draw(void);
	virtual void Draw(float mousePos[2]);
	virtual bool isDrawn() = 0;

protected:
	float color[3];
	float pointSize;

	int glShapeDrawn;
	int glShapeDrawing;

	bool usesPointSize;
	bool usesLineWidth;

	float defPointSize;
	float defLineWidth;

	vector<float> vertices;

	void SetSize(void);

};