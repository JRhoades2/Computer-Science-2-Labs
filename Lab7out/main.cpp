//Jordan Rhoades
//Lab7out
//using lab7in's container to pour water in the container and fill it up to the top
//
//This is as far as I could get with this project, the water level is the only thing that I am lacking in.
//It does work and fill up some containers with particular waterRates but it doesn't work for any parameter just waterRate = 20, with radius > height.
//I did get the flowing water, faucet, and pipe all down correctly.


#include <iostream>
#include "graph1.h"
#include "Simulation.h"

using namespace std;

int main()
{
	//Variable Declaration/Initialization
	int height = 0;
	int radius = 0;
	int r = 0;
	int b = 0;
	int g = 0;
	char repeat;
	Container container;
	Simulation simulation;
	GenPoint position;
	Color color;
	Fluid fluid;
	Faucet faucet;
	GenPoint start_pos;
	GenPoint pipe_pos;
	GenPoint end_pos;
	string fluidName;
	int waterRate = 0;
	int x_pos = 55;
	int y_pos = 0;
	int x_pos1 = 0;
	int y_pos1 = 0;



	//Display the graphics
	displayGraphics();

	//Continually simulate

	do
	{
		//Get the Container's radius/height/color (Add Data Validation)
		do
		{
			cout << "Enter fluid rate between 1 and 30 gallons/minute: ";
			cin >> waterRate;
		} while (waterRate < 0 || waterRate >30);
		//radius
		do
		{
			cout << "Enter the radius of container (between 10 and 285): ";
			cin >> radius;

			if (radius < 10 || radius > 285)
			{
				cout << "Invalid radius!";
			}
		} while (radius < 10 || radius > 285);
		//set radius
		container.setRadius(radius);
		//height

		do
		{
			cout << "Enter the height of container (between 10 and 300): ";
			cin >> height;
			if (height < 10 || height > 300)
			{
				cout << "Invalid height!";
			}
		} while (height < 10 || height > 300);
		//set height
		container.setHeight(height);

		//color
		do
		{
			cout << "Enter the color for the container: ";
			cin >> r >> g >> b;
			if (r < 0 || r > 255 || g < 0 || g>255 || b < 0 || b>255)
			{
				cout << "Invalid color!";
			}
		} while (r < 0 || r > 255 || g < 0 || g>255 || b < 0 || b>255);

		do
		{
			cout << "Enter fluid name (water, oil, or diesel): ";
			cin >> fluidName;
		} while (fluidName != "water" && fluidName != "oil" && fluidName != "diesel");

		//Set Color of the Fluid
		if (fluidName == "water")
		{
			color.setColor(0, 0, 255);

		}
		else if (fluidName == "oil")
		{
			color.setColor(142, 70, 70);
		}
		else if (fluidName == "diesel")
		{
			color.setColor(255, 0, 255);
		}

		fluid.setColor(color);

		//set color
		color.setColor(r,g,b);
		container.setColor(color);		
		//Set the Containers radius/height /color
		simulation.setWaterRate(waterRate);

		//Compute the Container upper left coordinate based on the height
		//Set the Container’s position
		//Hint: 55, 400 - height
		position.setPoint(60, 400 - height);
		container.setPosition(position);

		//set pipe position
		y_pos = 50;
		x_pos = radius - 16;
		pipe_pos.setPoint(x_pos, y_pos);
		faucet.setPosition(pipe_pos);

		//start faucet pos
		x_pos1 = radius - 16;
		y_pos1 = 400 - (container.getHeight() + 100);
		start_pos.setPoint(x_pos1, y_pos1);
		fluid.setStart(start_pos);

		//end Faucet positioh;
		y_pos = 400;
		end_pos.setPoint(x_pos, y_pos);
		fluid.setEnd(end_pos);

		//fluid sim
		faucet.setFluid(fluid);
		simulation.setFaucet(faucet);

		//Set the Container for the Simulation
		simulation.setContainer(container);

		//Draw the simulation/container (invoke draw on Simulation)
		
		simulation.draw();
		faucet.draw();
		simulation.start();

		//Repeat the simulation?
		cout << "Repeat the simulation (y/n)? ";
		cin >> repeat;

		clearGraphics();
		system("cls");

	} while (repeat == 'y');

	return 0;
}
