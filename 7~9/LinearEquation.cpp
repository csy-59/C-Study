#include "LinearEquation.h"

LinearEquation::LinearEquation(double nA, double nB, double nC, double nD, double nE, double nF) {
	a = nA;
	b = nB;
	c = nC;
	d = nD;
	e = nE;
	f = nF;
}
double LinearEquation::getA() {
	return a;
}
double LinearEquation::getB() {
	return b;
}
double LinearEquation::getC() {
	return c;
}
double LinearEquation::getD() {
	return d;
}
double LinearEquation::getE() {
	return e;
}
double LinearEquation::getF() {
	return f;
}
bool LinearEquation::isSolvable() {
	if ((a*d - b*c) != 0)
		return true;
	else
		return false;
}
double LinearEquation::getX() {
	return ((e*d - b*f) / (a*d - b*c));
}
double LinearEquation::getY() {
	return ((a*f - e*c) / (a*d - b*c));
}