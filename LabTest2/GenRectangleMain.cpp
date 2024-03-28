#include <iostream>
#include "graph1.h"
#include "GenRectangle.h"

using namespace std;




int main()
{
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	GenRectangle rec1;
	GenRectangle rec2;

	displayGraphics();

	cout << "Enter x/y coordinates: ";
	cin >> x >> y;
	rec2.setX(x);
	rec2.setY(y);
	
	cout << "Enter width for rectangle: ";
	cin >> width;
	rec2.setWidth(width);

	cout << "Enter height for rectangle: ";
	cin >> height;
	rec2.setHeight(height);

	rec1.draw();
	rec2.draw();

	gout << setPos(rec1.getX(), rec1.getY() + rec1.getHeight() + 20) << setColor(255, 255, 255) << "rec1" << endg;
	gout << setPos(rec1.getX(), rec1.getY() + rec1.getHeight() + 35) << setColor(255, 255, 255) << "Area: " << rec1.getArea() << endg;
	gout << setPos(rec1.getX(), rec1.getY() + rec1.getHeight() + 50) << setColor(255, 255, 255) << "Perimeter: " << rec1.getPerimeter() << endg;
	gout << setPos(rec1.getX(), rec1.getY() + rec1.getHeight() + 65) << setColor(255, 255, 255) << "Type: " << rec1.getType() << endg;

	gout << setPos(rec2.getX(), rec2.getY() + rec2.getHeight() + 20) << setColor(255, 255, 255) << "rec2" << endg;
	gout << setPos(rec2.getX(), rec2.getY() + rec2.getHeight() + 35) << setColor(255, 255, 255) << "Area: " << rec2.getArea() << endg;
	gout << setPos(rec2.getX(), rec2.getY() + rec2.getHeight() + 50) << setColor(255, 255, 255) << "Perimeter: " << rec2.getPerimeter() << endg;
	gout << setPos(rec2.getX(), rec2.getY() + rec2.getHeight() + 65) << setColor(255, 255, 255) << "Type: " << rec2.getType() << endg;




	return 0;
}