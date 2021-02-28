#include "Fan.h"

Fan::Fan() {
	speed = 1;
	on = false;
	radius = 5;
}

int Fan::getSpeed() {
	return speed;
}

bool Fan::getOn() {
	return on;
}

double Fan::getRadius() {
	return radius;
}

void Fan::setSpeed(int newSpeed) {
	speed = newSpeed;
}

void Fan::setOn(bool newOn) {
	on = newOn;
}

void Fan::setRadius(double newRadius) {
	radius = newRadius;
}