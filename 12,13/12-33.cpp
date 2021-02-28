#include <iostream>
#include <vector>
using namespace std;

int main() {
	int numPoints = 0;
	cout << "Enter the number of the points: ";
	cin >> numPoints;
	cout << "Enter the coordinates of the points: " << endl;
	vector<double> pointsX(numPoints);
	vector<double> pointsY(numPoints);
	for (int i = 0; i < numPoints; i++)
	{
	   cin>>pointsX[i]>>pointsY[i];
	   
	}
	double sum = 0;
	for (int i = 1; i <= numPoints-2; i++)
	{
	   sum +=abs( pointsX[0] * pointsY[i] + pointsX[i] * pointsY[i+1] + pointsX[i+1] * pointsY[0] -( pointsX[i] * pointsY[0] + pointsX[i+1] * pointsY[i] + pointsX[0] * pointsY[i+1]))/2.0;
	   
	}
	cout << "The total area is " << sum << endl;
	return 0;
}