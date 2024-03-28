#include "Quadrilateral.h"
#include "graph1.h"
#include "Color.h" 
#include "GenPoint.h"
#include <cmath>

using namespace std;

Quadrilateral::Quadrilateral()
{
	GenPoint zeroSet(0, 0);
	this->setPoints(zeroSet, zeroSet, zeroSet, zeroSet);
	this->color.setColor(0, 0, 0);
}

Quadrilateral::Quadrilateral(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	setPoints(a, b, c, d);
	this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());
}

void Quadrilateral::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
	this->d.setPoint(d.getX(), d.getY());

}

void Quadrilateral::setColor(Color color)
{
	this->color = color;
}

double Quadrilateral::getPerimeter()
{
	double total = 0.0;
	//distance from A to B
	total += sqrt(pow(a.getX() - b.getX(), 2.0) + pow(a.getY() - b.getY(), 2.0));
	//B to C
	total += sqrt(pow(b.getX() - c.getX(), 2.0) + pow(b.getY() - c.getY(), 2.0));
	//C to D
	total += sqrt(pow(c.getX() - d.getX(), 2.0) + pow(c.getY() - d.getY(), 2.0));
	//D to A
	total += sqrt(pow(d.getX() - a.getX(), 2.0) + pow(d.getY() - a.getY(), 2.0));
	return(total);
}

void Quadrilateral::print()
{
	gout << setPos(0, 400) << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << "Shape Info Follows for Quadrilateral" << endg;
	gout << setPos(200, 420) << "Point a: " << "(" << a.getX() << "," << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point b: " << "(" << b.getX() << "," << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point c: " << "(" << c.getX() << "," << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Point d: " << "(" << d.getX() << "," << d.getY() << ")" << endg;
	gout << setPos(200, 480) << "Perimeter: " << getPerimeter() << endg;
}

void Quadrilateral::draw()
{
	double width = 0.0;
	double height = 0.0;

	height = sqrt(pow(b.getX() - c.getX(), 2.0) + pow(b.getY() - c.getY(), 2.0));
	width = sqrt(pow(a.getX() - b.getX(), 2.0) + pow(a.getY() - b.getY(), 2.0));
	::setColor(drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 2), color.getRed(), color.getBlue(), color.getGreen());
	::setColor(drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 2), color.getRed(), color.getBlue(), color.getGreen());
	::setColor(drawLine(c.getX(), c.getY(), d.getX(), d.getY(), 2), color.getRed(), color.getBlue(), color.getGreen());
	::setColor(drawLine(d.getX(), d.getY(), a.getX(), a.getY(), 2), color.getRed(), color.getBlue(), color.getGreen());


}
