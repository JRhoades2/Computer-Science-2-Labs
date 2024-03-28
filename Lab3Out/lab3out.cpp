//Jordan Rhoades
//Lab3out
//game to shoot randomly generated bugs

#include <iostream>
#include <ctime>
#include "graph1.h"
using namespace std;

void initDisplay();
int getNoBugs();
int* getXCoords(int no_bugs);
int* getYCoords(int no_bugs);
int* displayObjects(int* x_coords, int* y_coords, int no_bugs);
int zapBugs(int* x_coords, int* y_coords, int* objects, int no_bugs);


int main()
{
	int no_bugs = 0;
	int* x_coords = NULL;
	int* y_coords = NULL;
	int no_objects = 0;
	int* objects = NULL;
	int zapped = 0;

	srand(time(0));

	char again;
	
	do
	{
		no_bugs = 0;
		x_coords = NULL;
		y_coords = NULL;
		no_objects = 0;
		objects = NULL;
		zapped = 0;

		initDisplay();

		no_bugs = getNoBugs();
		//cout << endl << no_bugs << endl;
		no_objects = no_bugs;
		x_coords = getXCoords(no_bugs);
		/*for (int i = 0; i < no_bugs; i++)
			cout << x_coords[i] << endl;*/
			//cout << endl;
		y_coords = getYCoords(no_bugs);
		/*for (int j = 0; j < no_bugs; j++)
			cout << y_coords[j] << endl;*/

		objects = displayObjects(x_coords, y_coords, no_objects);
		//cout << no_objects;
		zapped = zapBugs(x_coords, y_coords, objects, no_bugs);


		delete[] x_coords;
		delete[] y_coords;
		delete[] objects;

		

		cout << endl << "Would you like to run this program again?";
		cin >> again;

		clearGraphics();

	} while (again == 'y' || again == 'Y');

	return 0;
}

//Displays the background of our game
void initDisplay()
{
	displayGraphics();
	displayPNG("Grass.png", 0, 0);
	


}
//have user input number of bugs to zap 
int getNoBugs()
{
	int no_bugs = 0;
	do
	{
		cout << "Enter # of Bugs to Display (between 5 and 20): ";
		cin >> no_bugs;

		if (no_bugs < 5 || no_bugs > 20)
		{
			cout << endl << "Your number of bugs must be between 5 and 20 inclusively!" << endl;
		}

	} while (no_bugs < 5 || no_bugs > 20);

	return no_bugs;

}
//get random x coordinates
int* getXCoords(int no_bugs)
{
	int i = 0;

	int* x_coords = new int[no_bugs];

	for (i = 0; i < no_bugs; i++)
	{
		x_coords[i] = rand() % 576;
	}

	return(x_coords);

}
//get random y coordinates
int* getYCoords(int no_bugs)
{
	int i = 0;
	int* y_coords = new int[no_bugs];

	for (i = 0; i < no_bugs; i++)
	{
		y_coords[i] = rand() % 376 + 40;
	}

	return(y_coords);
}
//creates variable named objects that stores the images in a pointer
int* displayObjects(int* x_coords, int* y_coords, int no_objects)
{
	int i = 0;
	int* objects = NULL;
	objects = new int[no_objects];
	
	for (i = 0; i < no_objects; i++)
	{
		objects[i] = displayPNG("bugs.png", x_coords[i], y_coords[i]);
	}

	return(objects);
}
//sets up header, gets use to input coordinates and its the graphics heavy portion of the game
int zapBugs(int* x_coords, int* y_coords, int* objects, int no_bugs)
{
	int x = 0;
	int y = 0;
	int score = 0;
	int tries = 0;
	
	drawRect(250, 0, 200, 40);
	

	for (tries = 0; tries < (no_bugs * 2); tries++)
	{
		x = 0;
		y = 0;
		gout << setPos(275,20) << setColor(0, 0, 0) << "Score: " << score << "   " << "Shots: " << tries << endg;
		cout << endl << "Enter x/y coordinates: ";
		cin >> x >> y;


		for (int i = 0; i < no_bugs; i++)
		{
			
			for (int j = 1; j < 11; j++)
			{
				setColor(drawCircle(j, x, y), 0, 0, 0);
			}
			if ((x > x_coords[i]) && (x < x_coords[i] + 64) && (y > y_coords[i]) && (y < y_coords[i] + 64))
			{
				
				Sleep(1000);
				
				removeObject(objects[i]);
				//doesnt allow user to farm points from a past location of a bug
				x_coords[i] = NULL;
				y_coords[i] = NULL;
				score += 1;
				
			}
			//busts out of loop
			if (score == no_bugs)
			{
				break;
			}
		}
		//busts out of loop
		if (score == no_bugs)
		{
			tries++;
			break;
			
		}


	}

	if (score == no_bugs)
	{
		//cout << endl << "Winner!" << endl;
		gout << setPos(320, 32) << setColor(0, 0, 0) << "Winner!";
		gout << setPos(275, 20) << setColor(0, 0, 0) << "Score: " << score << "   " << "Shots: " << tries << endg;

	}
	else
	{
		//cout << endl << "Game Over" << endl;
		gout << setPos(320, 32) << setColor(0, 0, 0) << "Game Over!";
		gout << setPos(275, 20) << setColor(0, 0, 0) << "Score: " << score << "   " << "Shots: " << tries  << endg;

	}

	
	
	return score;
}
