


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


	//Display the graphics
	displayGraphics();

	//Continually simulate

	do
	{
		//Get the Container's radius/height/color (Add Data Validation)
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
		//set color
		color.setColor(r,g,b);
		container.setColor(color);		
		//Set the Containers radius/height /color


		//Compute the Container upper left coordinate based on the height
		
		//Set the Container’s position
		//Hint: 55, 400 - height
		position.setPoint(60, 400 - height);
		container.setPosition(position);
		//Set the Container for the Simulation
		simulation.setContainer(container);
		//Draw the simulation/container (invoke draw on Simulation)
		simulation.draw();
		//Repeat the simulation?
		cout << "Repeat the simulation (y/n)? ";
		cin >> repeat;

		clearGraphics();
		system("cls");

	} while (repeat == 'y');

	return 0;
}
