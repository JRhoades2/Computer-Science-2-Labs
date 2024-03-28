

#include <iostream>
#include <cmath>
#include "graph1.h"
#include "Container.h"

Container::Container()
{
	pos.setPoint(0, 0);
	radius = 0;
	height = 0;
}

void Container::setPosition(GenPoint pos)
{
	this->pos.setPoint(pos.getX(), pos.getY());
}

void Container::setRadius(int radius)
{
	this->radius = radius;
}

void Container::setHeight(int height)
{
	this->height = height;
}

void Container::setColor(Color color)
{
	this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());
}

GenPoint Container::getPosition()
{
	return(pos);
}

int Container::getRadius()
{
	return radius;
}

int Container::getHeight()
{
	return height;
}

Color Container::getColor()
{
	return(color);
}

void Container::draw()
{
	int line1 = 0;
	int line2 = 0;
	int line3 = 0;

	line1 = drawLine(pos.getX(), pos.getY(),pos.getX(),pos.getY() + height, 5);
	::setColor(line1, color.getRed(), color.getGreen(), color.getBlue());

	line2 = drawLine(pos.getX(), pos.getY() + height, pos.getX() + radius*2, pos.getY() + height, 5);
	::setColor(line2, color.getRed(), color.getGreen(), color.getBlue());

	line3 = drawLine(pos.getX() + radius*2, pos.getY() + height, pos.getX()+ radius*2, pos.getY(), 5);
	::setColor(line3, color.getRed(), color.getGreen(), color.getBlue());
}
