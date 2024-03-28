

#include <iostream>
#include "graph1.h"
#include "Simulation.h"
#include "Faucet.h"
#include "Container.h"

using namespace std;

Simulation::Simulation()
{
	setContainer(container);
	setFaucet(faucet);
	setWaterRate(waterRate);
}

void Simulation::draw()
{
	int wall = 0;
	int ground = 0;

	wall = drawRect(0, 0, 55, 400);
	setColor(wall, 200, 200, 200);

	ground = drawRect(0, 400, 640, 80);
	setColor(ground, 71, 35, 35);

	container.draw();

	faucet.turnOn();

}

void Simulation::setContainer(Container container)
{
	this->container = container;
}

Container Simulation::getContainer()
{
	return container;
}

void Simulation::setFaucet(Faucet faucet)
{
	this->faucet = faucet;
}

Faucet Simulation::getFaucet()
{
	return faucet;
}

int Simulation::getWaterRate()
{
	return waterRate;
}

void Simulation::setWaterRate(int waterRate)
{
	this->waterRate = waterRate;
}

void Simulation::start()
{
	double delta_h;
	int fluid;
	double converted;
	double pi = 3.141592654;

	converted = (3785411.78*waterRate) / 60;

	delta_h = converted / (pi*container.getRadius()*container.getRadius());


	if (container.getRadius() >= container.getHeight())
	{
		for (int i = 0; i < 10; i++)
		{

			fluid = drawRect(container.getPosition().getX(), (container.getPosition().getY() + container.getHeight()) - 5, container.getRadius() * 2, -delta_h * i);
			setColor(fluid, faucet.getFluid().getColor().getRed(), faucet.getFluid().getColor().getGreen(), faucet.getFluid().getColor().getBlue());
			Sleep(100);
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{

			fluid = drawRect(container.getPosition().getX(), (container.getPosition().getY() + container.getHeight()) - 5, container.getRadius() * 2, -(delta_h * i)/2);
			setColor(fluid, faucet.getFluid().getColor().getRed(), faucet.getFluid().getColor().getGreen(), faucet.getFluid().getColor().getBlue());
			Sleep(100);
		}
	}

	faucet.turnOff();
}