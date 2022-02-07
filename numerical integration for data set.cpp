#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
using namespace std;
float trapezoidal(float x0, float xn, int n, vector<float> &y)
{
	float h, total = 0;
	h = (xn - x0) / n;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || i == n-1)
		{
			total += y[i];
		}
		else
		{
			total += 2 * y[i];
		}
	}
	return ((h / 2) * total);
}
float simpsononethird(float x0, float xn, int n, vector<float> &y)
{
	float h, total = 0;
	h = (xn - x0) / n;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || i == n-1)
		{
			total += y[i];
		}
		else if (i % 2 == 0)
		{
			total += 2 * y[i];
		}
		else
		{
			total += 4 * y[i];
		}
	}
	return ((h / 3) * total);
}
float simpsonthreeeight(float x0, float xn, int n, vector<float> &y)
{
	float h, total = 0;
  h=(xn-x0)/n;
  for(int i=0;i<n;i++){
    if(i==0||i==n-1){
      total+=y[i];
    }
    else if(i%3==0){
      total+=2*y[i];
    }
    else{
      total+=3*y[i];
    }
  }
	return ((3 * h / 8) * total);
}
int main()
{
	int n;
	cout << "Enter the no. of data: ";
	cin >> n;
	float x0, xn;
	cout << "Enter the value of x0 and xn: ";
	cin >> x0 >> xn;
	vector<float> y;
	cout << "Enter the values of y: " << endl;
	for (int i = 0; i < n; i++)
	{
		float x;
		cout << "Enter y" << i << ": ";
		cin >> x;
		y.push_back(x);
	}
	cout << "Area using trapezoidal rule: " << trapezoidal(x0, xn, n, y) << endl;
	if (n % 2 == 0)
	{
		cout << "Area using simpson's 1/3 rule: " << simpsononethird(x0, xn, n, y) << endl;
	}
	else
	{
		cout << "n should be in multiple of 2 for simpson's 1/3 rule" << endl;
	}
	if (n % 3 == 0)
	{
		cout << "Area using simpson's 3/8 rule: " << simpsonthreeeight(x0, xn, n, y) << endl;
	}
	else
	{
		cout << "n should be in multiple of 3 for simpson's 3/8 rule" << endl;
	}
	return 0;
}
