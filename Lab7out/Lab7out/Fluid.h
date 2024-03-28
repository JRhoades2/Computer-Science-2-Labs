#pragma once
#include <string>
#include "GenPoint.h"
#include "Color.h"

using namespace std;

class Fluid
{
private:
	GenPoint start;
	GenPoint end;
	string fluidName;
	Color color;


public:
	Fluid();
	void setStart(GenPoint start);
	void setEnd(GenPoint end);
	void setFluidName(string name);
	GenPoint getStart();
	GenPoint getEnd();
	void setColor(Color color);
	Color getColor();
	string getFluidName();
};
