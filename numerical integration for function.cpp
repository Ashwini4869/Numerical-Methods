#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
float function(float x)
{
  return(3*x+5);
}
float trapezoidalRule(float x0, float xn, int n)
{
	float h = (xn - x0) / n;
	float total = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0 || i == n)
		{
			total += function(x0);
		}
		else
		{
			total += 2 * function(x0);
		}
		x0 += h;
	}
	return ((h / 2) * total);
}
float simpsonOneThirdRule(float x0, float xn, int n)
{
	float h = (xn - x0) / n;
	float total = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0 || i == n)
		{
			total += function(x0);
		}
		else if (i % 2 == 0)
		{
			total += 2 * function(x0);
		}
		else
		{
			total += 4 * function(x0);
		}
		x0 += h;
	}
	return ((h / 3) * total);
}
float simpsonThreeEightRule(float x0, float xn, int n)
{
	float h = (xn - x0) / n;
	float total = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i == 0 || i == n)
		{
			total += function(x0);
		}
		else if (i % 3 == 0)
		{
			total += 2 * function(x0);
		}
		else
		{
			total += 3 * function(x0);
		}
		x0 += h;
	}
	return ((3 * h / 8) * total);
}
int main()
{
	float x0, xn;
	int n;
	cout << "Enter the value of x0, xn and n:";
	cin >> x0 >> xn >> n;
	cout << "Value using trapezoidal rule: " << trapezoidalRule(x0, xn, n) << endl;
	if (n % 2 == 0)
	{
		cout << "Value using simpson's 1/3 rule: " << simpsonOneThirdRule(x0, xn, n) << endl;
	}
	else
	{
		cout << "Simpson's 1/3 rule requires n to be in multiple of 2." << endl;
	}
	if (n % 3 == 0)
	{
		cout << "Value using simpson's 3/8 rule: " << simpsonThreeEightRule(x0, xn, n) << endl;
	}
	else
	{
		cout << "Simpson's 3/8 rule requires n to be in multiple of 3." << endl;
	}
	return 0;
}
