#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
	int x;
	int y;
	int radius;
	const double PI = 3.14159265359;

public:
	Circle();
	void setX(int x);
	void setY(int y);
	void setRadius(int radius);
	int getX();
	int getY();
	int getRadius();
	int getArea();
	int getPerimeter();
	string getType();
	void draw();
};

#endif

