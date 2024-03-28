#include <iostream>
#include "graph1.h"
#include "Color.h"

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
		this->b = 255;
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
Color Color::operator+(Color right)
{
	Color result;
	result.r = r + right.r;
	if (result.r > 255)
		result.r = 255;
	result.g = g + right.g;
	if (result.g > 255)
		result.g = 255;
	result.b = b + right.b;
	if (result.b > 255)
		result.b = 255;
	return(result);
}
Color Color::operator-(Color right)
{
	Color result;
	result.r = r - right.r;
	if (result.r > 255)
		result.r = 255;
	result.g = g - right.g;
	if (result.g > 255)
		result.g = 255;
	result.b = b - right.b;
	if (result.b > 255)
		result.b = 255;
	return(result);
}
Color Color::operator/(int right)
{
	Color result;
	result.r = r / right;
	if (result.r > 255)
		result.r = 255;
	result.g = g / right;
	if (result.g > 255)
		result.g = 255;
	result.b = b / right;
	if (result.b > 255)
		result.b = 255;
	return(result);


}
Color Color::operator*(int right)
{
	Color result;
	result.r = r * right;
	if (result.r > 255)
		result.r = 255;
	result.g = g * right;
	if (result.g > 255)
		result.g = 255;
	result.b = b * right;
	if (result.b > 255)
		result.b = 255;
	return(result);
}
bool Color::operator==(Color right)
{
	bool result = false;

	if (r != right.r)
	{	
		result = false;
		return result;
	}
	else if (g != right.g)
	{
		result = false;
		return result;
	}
	else if (b != right.b)
	{
		result = false;
		return result;
	}
	else
	{
		return(true);
	}

}
bool Color::operator!=(Color right)
{
	bool result = false;

	if (r == right.r)
	{
		result = false;
		return result;
	}
	else if (g == right.g)
	{
		result = false;
		return result;
	}
	else if (b == right.b)
	{
		result = false;
		return result;
	}
	else
	{
		return(true);
	}
}
void Color::operator=(Color right)
{
	r = right.r;
	g = right.g;
	b = right.b;
}
Color Color::operator!()
{
	Color result;
	result.r = 255 - r;
	if (result.r < 0)
		result.r = 0;
	result.g = 255 - g;
	if (result.g < 0)
		result.g = 0;
	result.b = 255 - b;
	if (result.b < 0)
		result.b = 0;
	return(result);
}
void Color::draw(int x, int y, int w, int h)
{
	int rect;
	rect = drawRect(x, y, w, h);
	::setColor(rect, getRed(), getGreen(), getBlue());
}

