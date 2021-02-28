#include "Stock.h"

Stock::Stock(const string& nSymbol, const string& nName) {
	Symbol = nSymbol;
	name = nName;
}

string Stock::getSymbol() {
	return Symbol;
}

string Stock::Stock::getName() {
	return name;
}

double Stock::getPreviousClosingPrice() {
	return previousClosingPrice;
}

double Stock::getCurrentPrice() {
	return currentPrice;
}

void Stock::setPreviousClosingPrive(double PCP) {
	previousClosingPrice = PCP;
}

void Stock::setCurrentPrice(double CP) {
	currentPrice = CP;
}

double Stock::getChangePercent() {
	return currentPrice / previousClosingPrice * 100;
}