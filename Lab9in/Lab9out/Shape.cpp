#include <iostream>
#include <cmath>
#include "Shape.h"
#include "Color.h"
#include "graph1.h"

using namespace std;

Shape::Shape()
{
	color.setColor(0, 0, 0);
}

Color Shape::getColor()//Getter for Color
{
	return color;
}

void Shape::setColor(Color color)//Setter for Color
{
	color.setColor(color.getRed(), color.getGreen(), color.getBlue());
}