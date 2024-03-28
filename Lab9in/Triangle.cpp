#include <iostream>
#include "Triangle.h"
#include "graph1.h"

using namespace std;

Triangle::Triangle()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
}

Triangle::Triangle(GenPoint a, GenPoint b, GenPoint c, Color color)
{
	setPoints(a, b, c);
	this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());
}

void Triangle::setPoints(GenPoint a, GenPoint b, GenPoint c)
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
}

double Triangle::getArea()
{
	double side1 = sqrt(pow((b.getX() - a.getX()), 2.0) + pow((b.getY() - a.getY()), 2.0));
	double side2 = sqrt(pow((c.getX() - b.getX()), 2.0) + pow((c.getY() - b.getY()), 2.0));
	double side3 = sqrt(pow((c.getX() - a.getX()), 2.0) + pow((c.getY() - a.getY()), 2.0));
	double s = (side1 + side2 + side3) / 2.0;
	double area = sqrt(s*(s - side1)*(s - side2)*(s - side3));

	return area;
}

double Triangle::getPerimeter()
{
	double side1 = sqrt(pow((b.getX() - a.getX()), 2.0) + pow((b.getY() - a.getY()), 2.0));
	double side2 = sqrt(pow((c.getX() - b.getX()), 2.0) + pow((c.getY() - b.getY()), 2.0));
	double side3 = sqrt(pow((c.getX() - a.getX()), 2.0) + pow((c.getY() - a.getY()), 2.0));

	return (side1 + side2 + side3);
}

void Triangle::print()
{
	gout << setPos(0, 400) << "---------------------------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << "Shape info follows for: Triangle" << endg;
	gout << setPos(200, 420) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Perimeter: " << getPerimeter() << " Area: " << getArea() << endg;
}

void Triangle::draw()
{
	int color;
	color = drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 1);
	::setColor(color, this->color.getRed(), this->color.getGreen(), this->color.getBlue());
	color = drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 1);
	::setColor(color, this->color.getRed(), this->color.getGreen(), this->color.getBlue());
	color = drawLine(a.getX(), a.getY(), c.getX(), c.getY(), 1);
	::setColor(color, this->color.getRed(), this->color.getGreen(), this->color.getBlue());

}