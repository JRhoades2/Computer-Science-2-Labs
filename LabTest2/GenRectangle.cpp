#include <iostream>
#include "graph1.h"
#include "GenRectangle.h"

using namespace std;


GenRectangle::GenRectangle()
{
	x = 100;
	y = 25;
	width = 20;
	height = 30;
}

void GenRectangle::setWidth(int width)
{
	if (width < 1)
	{
		this->width = 1;

	}
	if (width > 50)
	{
		this->width = 50;
	}
	else
	{
		this->width = width;
	}
}
int GenRectangle::getWidth()
{
	return width;
}


void GenRectangle::setHeight(int height)
{
	if (height < 1)
	{
		this->height = 1;

	}
	if (height > 50)
	{
		this->height = 50;
	}
	else
	{
		this->height = height;
	}
}

int GenRectangle::getHeight()
{
	return height;
}

void GenRectangle::setX(int x)
{
	if (x < 100)
	{
		this->x = 100;

	}
	if (x > 539)
	{
		this->x = 539;
	}
	else
	{
		this->x = x;
	}
}

void GenRectangle::setY(int y)
{
	if (y < 25)
	{
		this->y = 25;

	}
	if (y > 455)
	{
		this->y = 455;
	}
	else
	{
		this->y = y;
	}
}

int GenRectangle::getX()
{
	return x;
}

int GenRectangle::getY()
{
	return y;
}

int GenRectangle::getArea()
{
	return(width * height);
}

int GenRectangle::getPerimeter()
{
	return(width + width + height + height);

}

string GenRectangle::getType()
{
	if ((getArea()) > 0 && (getArea()) < 300)
	{
		return("SMALL_RECTANGLE");
	}
	if (getArea() >= 300 && getArea() < 1000)
	{
		return("MIDDLE_RECTANGLE");
	}
	if (getArea() >= 1000)
	{
		return("LARGE_RECTANGLE");
	}
}


void GenRectangle::draw()
{
	int topline = 0;
	int botline = 0;
	int leftline = 0;
	int rightline = 0;

	topline = drawLine(x, y, (x + width), y, 2);
	botline = drawLine(x, y, x, (y + height), 2);
	leftline = drawLine(x, (y + height), (x + width), (y + height), 2);
	rightline = drawLine((x + width), y, (x + width), (y + height), 2);

	if ((getArea()) > 0 && (getArea()) < 300)
	{
		setColor(topline, 255, 0, 0);
		setColor(botline, 255, 0, 0);
		setColor(leftline, 255, 0, 0);
		setColor(rightline, 255, 0, 0);
	}
	if (getArea() >= 300 && getArea() < 1000)
	{
		setColor(topline,0, 255, 0);
		setColor(botline, 0, 255, 0);
		setColor(leftline, 0, 255, 0);
		setColor(rightline, 0, 255, 0);
	}
	if (getArea() >= 1000)
	{
		setColor(topline, 0, 0, 255);
		setColor(botline, 0, 0, 255);
		setColor(leftline, 0, 0, 255);
		setColor(rightline, 0, 0, 255);
	}

}