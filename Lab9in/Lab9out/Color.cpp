

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

Color Color::operator+(Color right)
{
	Color result;

	result.r = this->r + right.getRed();
	result.g = this->g + right.getGreen();
	result.b = this->b + right.getRed();

	if (result.r < 0)
		result.r = 0;
	else if (result.r > 255)
		result.r = 255;

	if (result.g < 0)
		result.g = 0;
	else if (result.g > 255)
		result.g = 255;

	if (result.b < 0)
		result.b = 0;
	else if (result.b > 255)
		result.b = 255;

	return result;
}
Color Color::operator-(Color right)
{
	Color result;

	result.r = this->r - right.getRed();
	result.g = this->g - right.getGreen();
	result.b = this->b - right.getRed();

	if (result.r < 0)
		result.r = 0;
	else if (result.r > 255)
		result.r = 255;

	if (result.g < 0)
		result.g = 0;
	else if (result.g > 255)
		result.g = 255;

	if (result.b < 0)
		result.b = 0;
	else if (result.b > 255)
		result.b = 255;

	return result;
}
Color Color::operator/(int right)
{
	Color result;

	if (right == 0)
		return result;

	result.r = this->r / right;
	result.g = this->g / right;
	result.b = this->b / right;

	if (result.r < 0)
		result.r = 0;
	else if (result.r > 255)
		result.r = 255;

	if (result.g < 0)
		result.g = 0;
	else if (result.g > 255)
		result.g = 255;

	if (result.b < 0)
		result.b = 0;
	else if (result.b > 255)
		result.b = 255;

	return result;
}
Color Color::operator*(int right)
{
	Color result;

	result.r = this->r * right;
	result.g = this->g * right;
	result.b = this->b * right;

	if (result.r < 0)
		result.r = 0;
	else if (result.r > 255)
		result.r = 255;

	if (result.g < 0)
		result.g = 0;
	else if (result.g > 255)
		result.g = 255;

	if (result.b < 0)
		result.b = 0;
	else if (result.b > 255)
		result.b = 255;

	return result;
}
bool Color::operator==(Color right)
{
	if (this->r == right.r && this->g == right.g && this->b == right.b)
		return true;
	else
		return false;
}
bool Color::operator!=(Color right)
{
	if (this->r != right.r || this->g != right.g || this->b != right.b)
		return true;
	else
		return false;
}
void Color::operator=(Color right)
{
	this->r = right.r;
	this->g = right.g;
	this->b = right.b;
}
Color Color::operator!()
{
	Color result;

	result.r = 255 - r;
	result.g = 255 - g;
	result.b = 255 - b;

	return result;
}
void Color::draw(int x, int y, int w, int h)
{
	::setColor(drawRect(x, y, w, h), r, g, b);
}
