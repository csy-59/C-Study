#pragma once
#ifndef STOCK_H
#define STOCK_H

#include <string>
using namespace std;

class Stock {
public:
	Stock(const string& nSymbol, const string& nName);
	string getSymbol();
	string getName();
	double getPreviousClosingPrice();
	double getCurrentPrice();
	void setPreviousClosingPrive(double PCP);
	void setCurrentPrice(double CP);
	double getChangePercent();

private:
	string Symbol;
	string name;
	double previousClosingPrice;
	double currentPrice;
};

#endif // STOCK_H
