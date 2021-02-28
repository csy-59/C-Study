#pragma once
#ifndef MYPOINT_H
#define MYPOINT_H
#include <cmath>

class Mypoint
{
public:
	Mypoint()
	{
		x = 0;
		y = 0;

	}

	Mypoint(double newX, double newY)
	{
		x = newX;
		y = newY;
	}

	double getX() const
	{
		return x;
	}

	double getY() const
	{
		return y;
	}

	virtual double distance(Mypoint mypoint2)
	{
		return sqrt((x - mypoint2.x)*(x - mypoint2.x) + (y - mypoint2.y)*(y - mypoint2.y));
	}
private:
	double x, y;
};

#endif // !MYPOINT_H