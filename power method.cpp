#include <iostream>
#include <stdlib.h>
#include <cmath>
#define maxsize 5
using namespace std;
float max(float arr[], int n)
{
  float maximum;
  maximum = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (maximum < fabs(arr[i]))
    {
      maximum = arr[i];
    }
  }
  return maximum;
}
int main()
{
  float n;
  cout << "Enter the order of matrix:";
  cin >> n;
  float A[maxsize][maxsize];
  float X[maxsize], Y[maxsize], Z[maxsize], D[maxsize];
  float E, maxerror, elem = 0, lambda;
  int count = 0;
  cout << "Enter the value of the matrix:";
  // taking the input  matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "A" << i << j << ": ";
      cin >> A[i][i];
    }
  }
  // taking the initial vectors
  cout << "Enter the initial guesses:";
  for (int i = 0; i < n; i++)
  {
    cout << "X" << i << ": ";
    cin >> X[i];
  }
  do
  {
    // matrix multiplication
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        elem += A[i][j] * X[j];
      }
      Z[i] = elem;
    }
    // assigning max value to lambda
    lambda = max(Z, n);
    // computing Y
    for (int i = 0; i < n; i++)
    {
      Y[i] = Z[i] / lambda;
    }
    // computing difference array
    for (int i = 0; i < n; i++)
    {
      D[i] = fabs(Y[i]) - fabs(X[i]);
    }
    // assigning Y to X
    for (int i = 0; i < n; i++)
    {
      X[i] = Y[i];
    }
    // assigning max value of diff to max error
    maxerror = max(D, n);
    // increasing the value of count
    count++;
    // to break infinite loop condition; in case the process doesnot converges to a solution
    if (count > 100)
    {
      cout << "Cannot find the solution." << endl;
      exit(1);
    }
  } while (fabs(maxerror) > E);
  cout << "Value of lambda: " << lambda << endl;
  cout << "The Y matrix is:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << Y[i] << endl;
  }
  return 0;
}
