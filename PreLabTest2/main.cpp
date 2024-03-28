#include <iostream>
#include "graph1.h"
#include "Circle.h"

using namespace std;



int main()
{
	int x = 0;
	int y = 0;
	int radius = 0;
	Circle cir1;
	Circle cir2;

	displayGraphics();


	cout << "Please enter x/y coordinates for your circle: ";
	cin >> x >> y;
	cir2.setX(x);
	cir2.setY(y);
	cout << "Please enter the radius: ";
	cin >> radius;
	cir2.setRadius(radius);
	cir2.draw();
	cir1.draw();



	return 0;
}