#pragma once
class Fan {
public:
	Fan();
	int getSpeed();
	bool getOn();
	double getRadius();
	void setSpeed(int newSpeed);
	void setOn(bool newOn);
	void setRadius(double newRadius);

private:
	int speed;
	bool on;
	double radius;
};

