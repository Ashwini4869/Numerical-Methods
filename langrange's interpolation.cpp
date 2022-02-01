#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
int main() {
	int n;
	cout << "Enter the no. of data you wish to enter:";
	cin >> n;
	float x[n], y[n];
	//taking data set
	cout << "Enter the value of x row:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x" << i << ":";
		cin >> x[i];
	}
	cout << "Enter the value of y row:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "y" << i << ":";
		cin >> y[i];
	}
	float xp;
	cout << "Enter the value of x at which y is to be interpolated:";
	cin >> xp;
	//applying interpolation formula
	float sum = 0;
	for (int i = 0; i < n; i++) {
		float product = 1;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				product = product * ((xp - x[j]) / (x[i] - x[j]));
			}
		}
		sum = sum + product * y[i];
	}
	cout << "The value of y at given x:" << sum;
	return 0;
}
