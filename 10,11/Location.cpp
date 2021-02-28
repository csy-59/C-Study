#include <iostream>
#include "Location.h"


Location::Location() {
	row = 0;
	column = 0;
	maxValue = 0;
}

int Location::getRow() {
	return row;
}

int Location::getcolumn(){
	return column;
}

double Location::getMaxValue() {
	return maxValue;
}

void Location::setRow(int newRow) {
	row = newRow;
}

void Location::setColumn(int newColumn) {
	column = newColumn;
}

void Location::setMaxValue(double newMaxValue) {
	maxValue = newMaxValue;
}