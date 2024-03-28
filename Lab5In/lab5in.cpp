//Jordan Rhoades
//lab5in
//

#include <iostream>
#include "graph1.h"

using namespace std;

class FilledCircle
{
private:
	int x;
	int y;
	int radius;

public:
	FilledCircle();
	bool setX(int x_val);
	int getX();
	bool setY(int y_val);
	int getY();
	bool setRadius(int r_val);
	int getRadius();
	void draw();
};

FilledCircle::FilledCircle()
{
	//Set private data fields to default values
	x = 0;
	y = 0;
	radius = 15;

}


bool FilledCircle::setX(int x_val)
{

	//Implement rules for x_val when out of range  
	bool result = false;

	if (x_val < 0)
	{
		x = 0;
		
	}
	else if (x_val >= 640)
	{
		x = 639;
	}
	else
	{
		x = x_val;
		result = true;
	}
	return result;
}

int FilledCircle::getX()
{
	return x;
}

bool FilledCircle::setY(int y_val)
{
	//Implement rules for setting the y-coord
	bool result = false;

	if (y_val < 0)
	{
		y = 0;

	}
	else if (y_val >= 479)
	{
		y = 479;
	}
	else
	{
		y = y_val;
		result = true;
	}
	return result;
}

int FilledCircle::getY()
{
	return y;
}

bool FilledCircle::setRadius(int r_val)
{
	//Implement rule for setting the radius
	bool result = false;

	if (r_val < 0)
	{
		radius = 1;

	}
	else if (r_val >= 30)
	{
		radius = 30;
	}
	else
	{
		radius = r_val;
		result = true;
	}
	return result;
}

int FilledCircle::getRadius()
{
	return radius;
}

void FilledCircle::draw()
{
	//Draw the filled circle
	for (int i = 0; i < radius; i++)
	{
		drawCircle(i, x, y);
	}
}

int main()
{
	//Variable Declaration/Initialization
	int i = 0;
	int x = 0;
	int y = 0;
	int radius = 0;

	FilledCircle circle1;
	bool result;
	char repeat;

	//Display the Graphics
	displayGraphics();

	do
	{
		//Prompt for the x/y coordinates
		cout << "Enter x/y coords: ";
		cin >> x >> y;

		//Prompt for the radius
		cout << "Enter radius: ";
		cin >> radius;

		//Set the x coord for circle1 – display message if x is out of range
		result = circle1.setX(x);
		if (result == false)
		{
			cout << "X input was out of range.\n";
		}
		result = true;
		//Set the y coord for circle1 – display message if y is out of range
		result = circle1.setY(y);
		if (result == false)
		{
			cout << "Y input was out of range.\n";
		}

		result = true;

		//Set the radius for cirle1 – display message if radius is out of range
		result = circle1.setRadius(radius);
		if (result == false)
		{
			cout << "Radius input was out of range.\n";
		}
	

		//Draw the circle
		circle1.draw();

		//Display the coordinate info, radius info under the circle along with the 
		gout << setPos(circle1.getX() - circle1.getRadius(), circle1.getY() + circle1.getRadius() +15) << "(" << circle1.getX() << "," << circle1.getY() << ")" << endg;

		gout << setPos(circle1.getX() - circle1.getRadius(), circle1.getY() + circle1.getRadius() + 30) << "Radius: " << circle1.getRadius() << endg;
		cout << "\nWould you like to repeat? (y/n): ";
		cin >> repeat;

	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}

