#pragma once

#include <vector>

using std::vector;

/*
	Base class for all shapes. 
*/
class Shape
{
public:
	Shape(int _glShapeDrawing, int _glShapeDrawn, float col[3], float pSize, bool usePointSize, bool useLineWidth);
	void UpdateColor(float color[3]); 
	void AddVertex(float loc[2]) ;

	virtual void Draw(void);
	virtual void Draw(float mousePos[2]); //Overloaded draw method when the drawing is still going on
	virtual bool isDrawn() = 0; //Making it a virtual class. 

protected:
	float color[3]; //Stores the color to be used to draw this shape
	float pointSize; //Stores the size to be used to draw this shape

	int glShapeDrawn;  //Type of shape to be used after drawing is complete
	int glShapeDrawing;// Type of shape to be used while drawing is still going on

	bool usesPointSize; //Does the shape uses a custom point size?
	bool usesLineWidth; // Does the shape uses a custom  line size?

	float defPointSize; //If not custom size, use this
	float defLineWidth; // ^^

	vector<float> vertices; //Holds the vertices of this shape

	void SetSize(void); //sets the point and line size based on the above boolean variables

};