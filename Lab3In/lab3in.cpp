//Jordan Rhoades
//Lab 3 in
//Displays a set of images at random location

#include <iostream>
#include <ctime>
#include "graph1.h"
using namespace std;

//Protoypes
int getNoObjects();
int* getXCoords(int no_objects);
int* getYCoords(int no_objects);
void displayObjects(int* x_coords, int* y_coords, int no_objects);

int main()
{
	char again;

	do
	{

		//Variable Declaration/Initialization
		int no_objects = 0;
		int* x_coords = NULL;
		int* y_coords = NULL;


		//Initialize seed
		srand(time(0));

		//Display graphics
		displayGraphics();

		//1. Get the number of objects to be displayed
		no_objects = getNoObjects();
		//cout << no_objects;

		//2. Generate the x-coords for each object
		x_coords = getXCoords(no_objects);

		/*for (int i = 0; i < no_objects; i++)
		{
			cout << endl << x_coords[i] << endl;
		}*/

		//3. Generate the y-coords for each object
		y_coords = getYCoords(no_objects);

		//for (int i = 0; i < no_objects; i++)
		//{
		//cout << endl << y_coords[i] << endl;
		//}

		//4. Display the objects at the randomly generated coordinates
		displayObjects(x_coords, y_coords, no_objects);


		//Cleanup memory	
		delete[] x_coords;
		delete[] y_coords;

		cout << "Would you like to run the program again? ";
		cin >> again;



	} while (again == 'y' || again == 'Y');

	return 0;
}

//Implement functions below
int getNoObjects()
{
	//Variable declaration/initialization
	int no_objects;

	//Prompt for # objects – should be between 2 and 30 inclusive
	//Perform data validation
	do
	{
		cout << "Enter # of objects: ";
		cin >> no_objects;
	} while (no_objects < 2 || no_objects > 30);

	return no_objects;
}

int* getXCoords(int no_objects)
{
	//Variable declaration/initialization
	int i = 0;

	//Dynamically allocate the array for x-coords
	int* x_coords = new int[no_objects];

	//Generates x-coords for each object randomly
	for (i = 0; i < no_objects; i++)
	{
		x_coords[i] = rand() % 600;
	}

	return (x_coords);
}

int* getYCoords(int no_objects)
{
	//Variable declaration/initialization
	int i = 0;

	//Dynamically allocate the array for y-coords
	int* y_coords = new int[no_objects];
	//Generates y-coords for each object randomly
	for (i = 0; i < no_objects; i++)
	{
		y_coords[i] = rand() % 440;
	}

	return (y_coords);
}

void displayObjects(int* x_coords, int* y_coords, int no_objects)
{
	//Variable declaration/initialization
	int i = 0;

	//Dynamically allocate objects to have no_objects
	//There's nothing to dynamically allocate

	//Display all objects at x/y random positions stored in x_coords/y_coords
	for (i = 0; i < no_objects; i++)
	{
		if (i % 2 == 0)
		{
			displayPNG("even.png", x_coords[i], y_coords[i]);
		}
		else
		{
			displayPNG("odd.png", x_coords[i], y_coords[i]);
		}
	}


}
