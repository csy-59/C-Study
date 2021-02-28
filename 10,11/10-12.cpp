#include <iostream>
#include "Stock.h"
using namespace std;

int main() {
	Stock stock("MSFT", "Microsoft Corporation");
	stock.setPreviousClosingPrive(27.5);
	stock.setCurrentPrice(27.6);

	cout << "Change Percent is " << stock.getChangePercent() << endl;

	return 0;
}