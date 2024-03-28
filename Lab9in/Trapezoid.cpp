#include <iostream>
#include "Trapezoid.h"
#include "graph1.h"

using namespace std;

Trapezoid::Trapezoid()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
	d.setPoint(0, 0);
	color.setColor(0, 0, 0);
}

Trapezoid::Trapezoid(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	setPoints(a, b, c, d);
	this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());
}

void Trapezoid::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
	this->d.setPoint(d.getX(), d.getY());
}

double Trapezoid::getArea()
{
	double base1 = sqrt(pow((b.getX() - a.getX()), 2.0) + pow((b.getY() - a.getY()), 2.0));
	double base2 = sqrt(pow((d.getX() - c.getX()), 2.0) + pow((d.getY() - c.getY()), 2.0));
	double height = sqrt(pow((b.getX() - c.getX()), 2.0) + pow((b.getY() - c.getY()), 2.0));

	return (0.5*(base1 + base2)*height);
}

void Trapezoid::print()
{
	Quadrilateral::print();
	Quadrilateral::draw();

	gout << setPos(0, 15) << "Trapezoid Information" << endg;
	gout << setPos(0, 30) << "Area: " << getArea() << endg;
}