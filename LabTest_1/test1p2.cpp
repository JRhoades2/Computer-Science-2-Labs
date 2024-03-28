//Jordan Rhoades
//LabTest1 P2
//create polyline using arrays and pointers


#include <iostream>
#include "graph1.h"

using namespace std;


void getData(int* no_points, int* x, int* y, int* r, int* g, int* b);
int* drawPolyLine(int* x, int* y, int no_points);
void colorPolyLine(int* objects, int no_points, int r, int g, int b);

int main()
{
	int no_points = 0;
	int r = 0;
	int g = 0;
	int b = 0;
	const int MAX_POINT = 10;
	int x[MAX_POINT] = { 0 };
	int y[MAX_POINT] = { 0 };
	int* objects = NULL;
	char again;
	do
	{
	
		no_points = 0;
		r = 0;
		g = 0;
		b = 0;
		objects = NULL;


	displayGraphics();

	getData(&no_points, x, y, &r, &g, &b);
	//cout << r << endl << g << endl << b << endl << no_points << endl;
	//for (int k = 0; k < no_points; k++)
	//{
	//	cout << x[k] << "  " << y[k] << endl;
	//}

	objects = drawPolyLine(x, y, no_points);
	colorPolyLine(objects, no_points, r, g, b);

	

	cout << "Would you like to run this program again? (Y or N) ";
	cin >> again;
	
	delete[] objects;


	clearGraphics();
	system("cls");

	} while (again == 'y' || again == 'Y');

	system("Pause");
	return 0;
}

void getData(int* no_points, int* x, int* y, int* r, int* g, int* b)
{
	int i = 0;
	do
	{
		cout << "Enter # of points: ";
		cin >> *no_points;
		
		if (*no_points < 3 || *no_points > 10)
		{
			cout << "\nEnter a number between 3 and 10 inclusively!\n";
		}

	} while (*no_points < 3 || *no_points > 10);

	cout << "Enter rgb color: ";
	cin >> *r;
	cin >> *g;
	cin >> *b;



	for (i = 0; i < *no_points; i++)
	{
		cout << "Enter x/y coord for Points #" << i + 1 << ": ";
		cin >> x[i];
		cin >> y[i];
	}
}

int* drawPolyLine(int* x, int* y, int no_points)
{
	int* objects = NULL;
	objects = new int[no_points];
	int i = 0;

	for (i = 0; i < no_points - 1; i++)
	{
		objects[i] = drawLine(x[i], y[i], x[i + 1], y[i + 1], 2);
	}


	return(objects);
}

void colorPolyLine(int* objects, int no_points, int r, int g, int b)
{
	int i = 0;

	for (i = 0; i < no_points - 1; i++)
	{
		setColor(objects[i], r, g, b);
	}

}