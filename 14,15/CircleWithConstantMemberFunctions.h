#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
	Circle();
	Circle(double);
	double getArea() const;
	double getRadius() const;
	void setRadius(double);
	static int getNumberOfObjects();

private:
	double radius;
	static int numberOfObjects;
};

//추가
bool operator<(const Circle& c1, const Circle& c2);
bool operator<=(const Circle& c1, const Circle& c2);
bool operator==(const Circle& c1, const Circle& c2);
bool operator!=(const Circle& c1, const Circle& c2);
bool operator>(const Circle& c1, const Circle& c2);
bool operator>=(const Circle& c1, const Circle& c2);

int Circle::numberOfObjects = 0;

Circle::Circle() {
	radius = 1;
	numberOfObjects++;
}

Circle::Circle(double newRadius) {
	radius = newRadius;
	numberOfObjects++;
}

double  Circle::getArea() const {
	return radius * radius * 3.14159;
}

double Circle::getRadius() const {
	return radius;
}

void Circle::setRadius(double newRadius) {
	radius = (newRadius >= 0) ? newRadius : 0;
}

int Circle::getNumberOfObjects() {
	return numberOfObjects;
}

//추가
bool operator<(const Circle& c1, const Circle& c2) {
	return (c1.getRadius() < c2.getRadius());
}
bool operator<=(const Circle& c1, const Circle& c2) {
	return (c1.getRadius() <= c2.getRadius());
}
bool operator==(const Circle& c1, const Circle& c2) {
	return (c1.getRadius() == c2.getRadius());
}
bool operator!=(const Circle& c1, const Circle& c2) {
	return (c1.getRadius() != c2.getRadius());
}
bool operator>(const Circle& c1, const Circle& c2) {
	return (c1.getRadius() > c2.getRadius());
}
bool operator>=(const Circle& c1, const Circle& c2) {
	return (c1.getRadius() >= c2.getRadius());
}

#endif