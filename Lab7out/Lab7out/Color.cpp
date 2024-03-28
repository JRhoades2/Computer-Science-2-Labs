

#include <iostream>
#include <cmath>
#include "Color.h" 
#include "graph1.h" 

Color::Color()
{
	r = 0;
	g = 0;
	b = 0;
}

Color::Color(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}


void Color::setColor(int r, int g, int b)
{
	if (r < 0)
	{
		this->r = 0;
	}
	else if (r > 255)
	{
		this->r = 255;
	}
	else
	{
		this->r = r;
	}
	if (g < 0)
	{
		this->g = 0;
	}
	else if (g > 255)
	{
		this->g = 255;
	}
	else
	{
		this->g = g;
	}
	if (b < 0)
	{
		this->b = 0;
	}
	else if (b > 255)
	{
		this->b= 255;
	}
	else
	{
		this->b = b;
	}
}

int Color::getRed()
{
	return r;
}

int Color::getGreen()
{
	return g;
}

int Color::getBlue()
{
	return b;
}
