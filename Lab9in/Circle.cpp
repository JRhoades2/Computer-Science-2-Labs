#include <iostream>
#include "Circle.h"
#include <cmath>
#include "graph1.h"

using namespace std;

const double Circle::PI = 2 * acos(0);

Circle::Circle()
{
	radius = 0;
	center.setPoint(0, 0);
}

Circle::Circle(GenPoint center, int radius, Color c)
{
	setCenter(center);
	setRadius(radius);
	this->color.setColor(c.getRed(), c.getGreen(), c.getBlue());
}

void Circle::setCenter(GenPoint center)
{
	this->center.setPoint(center.getX(), center.getY());
}

void Circle::setRadius(int radius)
{
	this->radius = radius;
}

double Circle::getPerimeter()
{
	return (2 * PI*radius);
}

double Circle::getArea()
{
	return (PI*pow(radius, 2.0));
}

void Circle::print()
{
	gout << setPos(0, 400) << "---------------------------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << "Shape info follows for: Circle" << endg;
	gout << setPos(200, 420) << "Center Point: (" << center.getX() << "," << center.getY() << ")" << endg;
	gout << setPos(200, 435) << "Radius: " << radius << endg;
	gout << setPos(200, 450) << "Perimeter: " << getPerimeter() << endg;
	gout << setPos(200, 465) << "Area: " << getArea() << endg;
}

void Circle::draw()
{
	int color;
	color = drawCircle(radius, center.getX(), center.getY());
	::setColor(color, this->color.getRed(), this->color.getGreen(), this->color.getBlue());
}