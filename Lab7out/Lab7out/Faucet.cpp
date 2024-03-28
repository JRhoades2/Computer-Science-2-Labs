#include <iostream>
#include "graph1.h"
#include "Fluid.h"
#include "Faucet.h"
#include "Color.h"
#include "Container.h"

using namespace std;

Faucet::Faucet()
{
	on = true;
	setPosition(pos);
	setFluid(fluid);
	liquid = 0;

}

void Faucet::turnOn()
{
	liquid = drawLine(fluid.getStart().getX(), fluid.getStart().getY(), fluid.getEnd().getX(), fluid.getEnd().getY(), 5);
	setColor(liquid, fluid.getColor().getRed(), fluid.getColor().getGreen(), fluid.getColor().getBlue());
}

void Faucet::turnOff()
{
	removeObject(liquid);
}

void Faucet::setPosition(GenPoint upper)
{
	this->pos = upper;
}

GenPoint Faucet::getPosition()
{
	return pos;
}

void Faucet::setFluid(Fluid fluid)
{
	this->fluid = fluid;
}

Fluid Faucet::getFluid()
{
	return fluid;
}

void Faucet::draw()
{
	int pipe;

	pipe = drawLine(50, (fluid.getStart().getY()), (fluid.getStart().getX()), (fluid.getStart().getY()), 5);
	displayBMP("faucet.BMP", (fluid.getStart().getX() - 60), (fluid.getStart().getY()) - 40);
	setColor(pipe, 80, 80, 80);
}
