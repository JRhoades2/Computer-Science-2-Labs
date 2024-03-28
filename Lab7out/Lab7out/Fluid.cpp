#include <iostream>
#include "Fluid.h"

using namespace std;

Fluid::Fluid()
{
	setStart(start);
	setEnd(end);
	setFluidName(fluidName);
}

void Fluid::setStart(GenPoint start)
{
	this->start = start;
}

void Fluid::setEnd(GenPoint end)
{
	this->end = end;
}

void Fluid::setFluidName(string name)
{
	this->fluidName = name;
}

GenPoint Fluid::getStart()
{
	return start;
}

GenPoint Fluid::getEnd()
{
	return end;
}

void Fluid::setColor(Color color)
{
	this->color = color;
}

Color Fluid::getColor()
{
	return color;
}

string Fluid::getFluidName()
{
	return fluidName;
}