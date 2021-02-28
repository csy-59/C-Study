#pragma once
#ifndef LINEAREQUATION_H
class LinearEquation {
public:
	LinearEquation(double nA, double nB, double nC, double nD, double nE, double nF);
	double getA();
	double getB();
	double getC();
	double getD();
	double getE();
	double getF();
	bool isSolvable();
	double getX();
	double getY();

private:
	double a;
	double b;
	double c;
	double d;
	double e;
	double f;
};

#endif // !LINEAREQUATION_H

