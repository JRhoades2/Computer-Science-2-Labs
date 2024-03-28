//Jordan Rhoades
//lab8out
//overloading operators to operate on user inputted colors

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
Color Color::operator++()//prefix
{
	r = r+25;
	g = g+25;
	b = b+25;
	if (r < 0)
	{
		r = 0;
	}
	else if (r > 255)
	{
		r = 255;
	}
	else
	{
		r = r;
	}
	if (g < 0)
	{
		g = 0;
	}
	else if (g > 255)
	{
		g = 255;
	}
	else
	{
		g = g;
	}
	if (b < 0)
	{
		b = 0;
	}
	else if (b > 255)
	{
		b = 255;
	}
	else
	{
		b = b;
	}

	return(*this);
}
Color Color::operator++(int dummy)//postfix
{
	dummy = 0;                   // to prevent compiler warning
								 // Save old value of date
	Color old_value = (*this);
	// Increment colors (call prefix operator to do the work)
	r= r+25;
	g = g+25;
	b = b+25;
	if (r < 0)
	{
		r = 0;
	}
	else if (r > 255)
	{
		r = 255;
	}
	else
	{
		r = r;
	}
	if (g < 0)
	{
		g = 0;
	}
	else if (g > 255)
	{
		g = 255;
	}
	else
	{
		g = g;
	}
	if (b < 0)
	{
		b = 0;
	}
	else if (b > 255)
	{
		b = 255;
	}
	else
	{
		b = b;
	}


	// Return old value  
	return (old_value);
}
Color Color::operator--()//prefix
{
	r = r-25;
	g = g-25;
	b= b-25;
	if (r < 0)
	{
		r = 0;
	}
	else if (r > 255)
	{
		r = 255;
	}
	else
	{
		r = r;
	}
	if (g < 0)
	{
		g = 0;
	}
	else if (g > 255)
	{
		g = 255;
	}
	else
	{
		g = g;
	}
	if (b < 0)
	{
		b = 0;
	}
	else if (b > 255)
	{
		b = 255;
	}
	else
	{
		b = b;
	}

	return(*this);
}
Color Color::operator--(int dummy)//postfix
{
	dummy = 0;                   // to prevent compiler warning
								 // Save old value of date
	Color old_value = (*this);
	// Increment colors (call prefix operator to do the work)
	r = r - 25;
	g = g - 25;
	b = b - 25;
	if (r < 0)
	{
		r = 0;
	}
	else if (r > 255)
	{
		r = 255;
	}
	else
	{
		r = r;
	}
	if (g < 0)
	{
		g = 0;
	}
	else if (g > 255)
	{
		g = 255;
	}
	else
	{
		g = g;
	}
	if (b < 0)
	{
		b = 0;
	}
	else if (b > 255)
	{
		b = 255;
	}
	else
	{
		b = b;
	}
	// Return old value  
	return (old_value);
}
bool Color::operator<(Color right)
{
	bool result = false;

	if (sqrt(pow(r, 2) + pow(g, 2) + pow(b, 2)) >= sqrt(pow(right.r,2)+ pow(right.g,2)+pow(right.b,2)))
	{
		result = false;
		return result;
	}
	else
	{
		return(true);
	}

}
bool Color::operator>(Color right)
{
	bool result = false;

	if (sqrt(pow(r, 2) + pow(g, 2) + pow(b, 2)) <= sqrt(pow(right.r, 2) + pow(right.g, 2) + pow(right.b, 2)))
	{
		result = false;
		return result;
	}
	else
	{
		return(true);
	}

}
void Color::draw(int x, int y, int w, int h)
{
	int rect;
	rect = drawRect(x, y, w, h);
	::setColor(rect, getRed(), getGreen(), getBlue());
}

