//Jordan Rhoades
//LabTest1 P1
//display stairs in graphics window

#include <iostream>
#include "graph1.h"

using namespace std;


void getData( int* no_stairs, int* r, int* g, int* b);
void displayStairs(int no_stairs, int r, int g, int b);


int main()
{
	int no_stairs = 0;
	int r = 0;
	int g = 0;
	int b = 0;
	char again;
	
	do {
		no_stairs = 0;
		r = 0;
		g = 0;
		b = 0;

		displayGraphics();
		getData(&no_stairs, &r, &g, &b);
		//cout << r << endl << g << endl << b  << endl << no_stairs;
		displayStairs(no_stairs, r, g, b);

		cout << "\nWould you like to run this program again? (Y or N) ";
		cin >> again;

		clearGraphics();
		system("cls");

	} while (again == 'y' || again == 'Y');

	system("Pause");
	return 0;
}

void getData(int* no_stairs, int* r, int* g, int* b)
{
	do
		{
			cout << "Enter # of stairs to display: ";
			cin >> *no_stairs;
			if (*no_stairs < 3 || *no_stairs > 6)
			{
				cout << "\nRe-enter an appropriate # of stairs that is [3,6]!\n";
			}
		} while (*no_stairs < 3 || *no_stairs > 6);

	cout << "Enter rgb color: ";
	cin >> *r;
	cin >> *g;
	cin >> *b;
	
	
}

void displayStairs(int no_stairs, int r, int g, int b)
{
	int i = 0;

	for (i = 0; i < no_stairs; i++)
	{
		if (i % 2 == 0)
		{
			setColor(drawRect(0+50*i, 400 - 20*i, 100, 20), 128, 128, 128);
		}
		else
		{
			setColor(drawRect(0+50*i, 400 - 20*i, 100, 20), r, g, b);
		}
	}


}
