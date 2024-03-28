//Jordan Rhoades
//Lab1in
//using graphics to make a polyline


#include <iostream>
#include "graph1.h"
using namespace std;


//Add Function Prototypes Here
int getNoPoints();
void getPoints(int x[], int y[], int no_points);
void drawPolyLine(int x[], int y[], int no_points);

int main()
{
	//Variable Declaration/Initialization
	int no_points = 0;
	const int MAX_POINTS = 10;
	int x[MAX_POINTS];
	int y[MAX_POINTS];
	char iterations;

	do
	{

	//Display Graphics Window
	displayGraphics();

	//Prompt for the number of points
	no_points = getNoPoints();

	//Prompt for the data for the points
	getPoints(x, y, no_points);

	//Draw the polyline
	drawPolyLine(x, y, no_points);
	
	cout << "Would you like to run the program again? (Y or N) ";
	cin >> iterations;

	clearGraphics();
	system("cls");

	} while (iterations == 'Y' || iterations == 'y');

	return 0;
}

//Function Stubs Follows
int getNoPoints()
{
	//Declare local variables
	int no_points = 0;
	//Prompt for the number of points
	cout << "Please enter the number of points: ";
	cin >> no_points;
	//Return the number of points
	return no_points;
}

void getPoints(int x[], int y[], int no_points)
{
	//Declare local variables
	int i = 0;
	//Using a for-loop, prompt for the coordinates of each point and store in arrays x and y
	for (i = 0; i < no_points; i++)
	{
		cout << "Enter the x/y coords for the point # " << (i + 1) << ": ";
		cin >> x[i] >> y[i];
	}
}

void drawPolyLine(int x[], int y[], int no_points)
{
	//Declare local variables
	int i = 0;
	int j;
	int k;
	//Use 1 for-loop for drawing the red circle on each point
	//Use a second for-loop for drawing the lines - remember there is always one less line than there are points!
	for (i = 0; i < no_points; i++)
	{
		j = drawCircle(5, x[i], y[i]);
		setColor(j, 255, 0, 0);

		if (i < (no_points - 1))
		{
			k = drawLine(x[i], y[i], x[i + 1], y[i + 1], 2);
			setColor(k, 255, 255, 0);
		}
	}

}
	