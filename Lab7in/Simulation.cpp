

#include <iostream>
#include "graph1.h"
#include "Simulation.h"

using namespace std;

Simulation::Simulation()
{
	setContainer(container);
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

}

void Simulation::setContainer(Container container)
{
	this->container = container;
}

Container Simulation::getContainer()
{
	return container;
}
