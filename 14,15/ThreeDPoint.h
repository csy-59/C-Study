#pragma once
#ifndef THREEDPOINT_H
#define THREEDPOINT_H
#include "MyPoint.h"

class ThreeDPoint : public Mypoint {
public:
	ThreeDPoint() {
		z = 0;
	}

	ThreeDPoint(double x, double y, double z) : Mypoint(x, y) {
		this->z = z;
	}

	double getZ() const {
		return this->z;
	}

	double distance(Mypoint& p1) {
		Mypoint* p = &p1;
		ThreeDPoint* np = dynamic_cast<ThreeDPoint*>(p);
		return sqrt((getX() - p1.getX())*(getX() - p1.getX()) + (getY() - p1.getY())*(getY() - p1.getY()) + (getZ() - np->getZ())*(getZ() - np->getZ()));
	}

private:
	double z;
};

#endif // !THREEDPOINT_H