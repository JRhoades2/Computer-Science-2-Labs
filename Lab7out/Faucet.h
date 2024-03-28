#pragma once
#include "GenPoint.h"
#include "Fluid.h"
class Faucet
{
private:
	bool on;
	int liquid;
	GenPoint pos;
	Fluid fluid;


public:
	Faucet();
	void turnOn();
	void turnOff();
	void setPosition(GenPoint upper);
	GenPoint getPosition();
	void setFluid(Fluid fluid);
	Fluid getFluid();
	void draw();

};
