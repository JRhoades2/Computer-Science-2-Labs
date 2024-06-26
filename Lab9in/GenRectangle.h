#pragma once
#ifndef GENRECTANGLE_H
#define GENRECTANGLE_H

#include "Quadrilateral.h"

class GenRectangle : public Quadrilateral
{
protected:
	GenPoint ul;
	GenPoint lr;

public:
	GenRectangle();
	GenRectangle(GenPoint ul, GenPoint lr, Color c);
	void setPoints(GenPoint ul, GenPoint lr);
	double getArea();
	void print();
};

#endif
