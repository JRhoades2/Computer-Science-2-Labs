#pragma once
#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "GenPoint.h"
#include "Color.h"
#include "Shape.h"

class Quadrilateral : public Shape
{
protected:

	GenPoint a;
	GenPoint b;
	GenPoint c;
	GenPoint d;
	Color color;

public:
	Quadrilateral(); //Sets all points/colors to 0
	Quadrilateral(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color);
	void setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d);
	void setColor(Color color);
	double getPerimeter();
	void print();
	void draw();
};

#endif
