#include <iostream>
#include "RightTriangle.h"
#include "graph1.h"

using namespace std;

RightTriangle::RightTriangle()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
}

RightTriangle::RightTriangle(GenPoint vertex, int height, int base, Color color)
{
	a.setPoint(vertex.getX(), vertex.getY());
	b.setPoint(vertex.getX() + base, vertex.getY());
	c.setPoint(vertex.getX(), vertex.getY() - height);
	this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());
}

void RightTriangle::print()
{
	gout << setPos(0, 15) << "Right Triangle" << endg;
	Triangle::print();
	Triangle::draw();
}
