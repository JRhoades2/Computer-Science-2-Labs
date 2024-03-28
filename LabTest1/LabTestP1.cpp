#include <iostream>
#include "graph1.h"

using namespace std;


void getData(int* r, int* g, int* b, int* radius, int* no_circles);
int* drawChain(int radius, int no_circles);
void colorChain(int* objects, int no_cicles, int r, int g, int b);

int main()
{
	int r = 0;
	int g = 0;
	int b = 0;
	int radius = 0;
	int no_circles = 0;
	int* objects = NULL;

	getData(&r, &g, &b, &radius, &no_circles);
	cout << r << endl << g << endl << b << endl << radius << endl << no_circles;
	displayGraphics();
	objects = drawChain(radius, no_circles);
	
	colorChain(objects, no_circles, r, g, b);

	delete[] objects;

	system("Pause");
	return 0;
}

void getData(int* r, int* g, int* b, int* radius, int* no_circles)
{
	cout << "Enter rgb color: ";
	cin >> *r;
	cin >> *g;
	cin >> *b;
	do
	{

		cout << "Enter Radius: ";
		cin >> *radius;
	} while (*radius < 15 || *radius > 25);
	do
	{
		cout << "Enter # of circles: ";
		cin >> *no_circles;
	} while (*no_circles < 3 || *no_circles > 10);
}

int* drawChain(int radius, int no_circles)
{
	int i = 0;

	int* objects = NULL;
	objects = new int[no_circles];

	for (i = 0; i < no_circles; i++)
	{
		objects[i] = drawCircle(radius, 100 + radius*i, 100);
	}


	return(objects);
}

void colorChain(int* objects, int no_cicles, int r, int g, int b)
{
	int i = 0;

	for (i = 0; i < no_cicles; i++)
	{
		if (i % 2 == 0)
		{
			setColor(objects[i], r, g, b);
		}
		else
			setColor(objects[i], 256, 256, 256);
	}


}