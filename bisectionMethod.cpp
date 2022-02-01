#include <iostream>
#include <cmath>
using namespace std;
float f(float x)
{
  return (x * x - 3 * x);
}
int main()
{
  float a, b, c, e, n;
  float count = 0;
  cout << "Enter a:";
  cin >> a;
  cout << "Enter b:";
  cin >> b;
  cout << "Enter error tolerance:";
  cin >> e;
  n = ((log(abs(b - a)) - log(e)) / log(2));
  if (f(a) * f(b) > 0)
  {
    cout << "Cannot find solution within the given interval" << endl;
  }
  else if (f(a) * f(b) == 0)
  {
    if (f(a) == 0)
    {
      cout << "Solution=" << a << endl;
    }
    if (f(b) == 0)
    {
      cout << "Solution=" << b << endl;
    }
  }
  else
  {
    do
    {
      count++;
      c = (a + b) / 2;
      if (f(c) * f(a) < 0)
      {
        b = c;
      }
      else
      {
        a = c;
      }
      if (fabs(f(c)) < e)
      {
        cout << "Solution=" << c << endl;
        break;
      }
      if (count > 2 * n)
      {
        cout << "Cannot find feasible solution" << endl;
        break;
      }
    } while (1);
  }
  return 0;
}
