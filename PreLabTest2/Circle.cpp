#include <iostream>
#include "graph1.h"
#include "Circle.h"

using namespace std;

Circle::Circle()
{
	x = 50;
	y = 50;
	radius = 5;
	PI;
}



void Circle::setX(int x)
{
	if (x < 50)
	{
		this->x = 50;
	}
	else if (x > 639)
	{
		this->x = 639;
	}
	else
	{
		this->x = x;
	}
}

void Circle::setY(int y)
{
	if (y < 50)
	{
		this->y = 50;
	}
	else if (y> 479)
	{
		this->y = 479;
	}
	else
	{
		this->y = y;
	}
}

void Circle::setRadius(int radius)
{
	if (radius < 5)
	{
		this->radius = 5;
	}
	else if (radius > 20)
	{
		this->radius = 20;
	}
	else
	{
		this->radius = radius;
	}
}

int Circle::getX()
{
	return x;
}

int Circle::getY()
{
	return y;
}

int Circle::getRadius()
{
	return radius;
}

int Circle::getArea()
{
	return (PI*radius*radius);
}

int Circle::getPerimeter()
{
	return (2 * PI*radius);
}

string Circle::getType()
{
	if ((PI*radius*radius) <= 100)
	{
		return ("SMALL_CIRCLE");
	}
	else if (((PI*radius*radius) > 100) || ((PI*radius*radius) <= 300))
	{
		return("MEDIUM_CIRCLE");
	}
	else if ((PI*radius*radius) > 300)
	{
		return("LARGE_NUMBER");
	}	
}
void Circle::draw()
{
	int circle = 0;
	circle = drawCircle(getRadius(), getX(), getY());
	setColor(circle, 255, 255, 255);
}