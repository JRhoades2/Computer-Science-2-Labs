
#include "graph1.h"
#include <cmath>
#include "Quadrilateral.h"
#include "GenRectangle.h"

GenRectangle::GenRectangle()
{
	GenPoint zeroSet(0, 0);
	this->setPoints(zeroSet, zeroSet);
}

GenRectangle::GenRectangle(GenPoint ul, GenPoint lr, Color c)
{
	//setPoints(ul, lr);
	this->ul = ul;
	this->lr = lr;
	this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());
}

void GenRectangle::setPoints(GenPoint ul, GenPoint lr)
{
	this->a.setPoint(ul.getX(), ul.getY());
	this->b.setPoint(lr.getX(), ul.getY());
	this->c.setPoint(lr.getX(), lr.getY());
	this->d.setPoint(ul.getX(), lr.getY());

}
double GenRectangle::getArea()
{
	double area = 0.0;
	double width = 0.0;
	double height = 0.0;

	width = sqrt(pow((a.getX() - b.getX()), 2.0) + pow((a.getY() - b.getY()), 2.0));
	height = sqrt(pow((c.getX() - b.getX()), 2.0) + pow((c.getY() - b.getY()), 2.0));
	area = width * height;

	return area;
}
void GenRectangle::print()
{	
	Quadrilateral::print();
	Quadrilateral::draw();
	gout << setPos(200, 15) << "Rectangle Info" << endg;
	gout << setPos(200, 30) << "Area:" << getArea() << endg;
	
}


