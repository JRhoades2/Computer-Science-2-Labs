#include <iostream>
#include "graph1.h"

using namespace std;




void getData(int* no_rects);
int* getXCoords(int no_rects);
int* getYCoords(int no_rects);
void displayRectangles(int no_rects, int* x, int* y);



int main()
{
	int no_rects = 0;
	int* x = NULL;
	int* y = NULL;

	displayGraphics();
	getData(&no_rects);
	x = getXCoords(no_rects);
	y = getYCoords(no_rects);

	displayRectangles(no_rects, x, y);



	system("Pause");
	return 0;
}

void getData(int* no_rects)
{
	do
	{
		cout << "Enter # of boxes: ";
		cin >> *no_rects;
	} while (*no_rects <1);


}

int* getXCoords(int no_rects)
{
	int i = 0;

	int* x = NULL;
	x = new int[no_rects];

	for (i = 0; i < no_rects; i++)
	{
		cout << "Enter x-coord for box " << i + 1 << ": ";
		cin >> x[i];
	}
	return(x);
}

int* getYCoords(int no_rects)
{
	int i = 0;

	int* y = NULL;
	y = new int[no_rects];

	for (i = 0; i < no_rects; i++)
	{
		cout << "Enter y-coord for box " << i + 1 << ": ";
		cin >> y[i];
	}

	return(y);
}

void displayRectangles(int no_rects, int* x, int* y)
{
	int i = 0;
	for (i = 0; i < no_rects; i++)
	{
		if (i % 2 == 0)
		{
			setColor(drawRect(x[i], y[i], 50, 25), 255, 0, 0);
		}

		else
			setColor(drawRect(x[i], y[i], 50, 25), 0, 0, 255);
	}
}