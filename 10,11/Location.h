#pragma once
#ifndef LOCATION_H
#define LOCATION_H

class Location {
public:
	Location();
	int getRow();
	int getcolumn();
	double getMaxValue();
	void setRow(int newRow);
	void setColumn(int newColumn);
	void setMaxValue(double newMaxValue);
private:
	int row;
	int column;
	double maxValue;

};
#endif // !LOCATION_H
