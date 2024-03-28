#pragma once
#ifndef GenRectangle_H
#define GenRectangle_H

class GenRectangle
{
private:
	int x;
	int y;
	int width;
	int height;
	

public:
	GenRectangle();
	void setWidth(int width);
	void setHeight(int height);
	int getWidth();
	int getHeight();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int getArea();
	int getPerimeter();
	string getType();
	void draw();
};

#endif