#include<iostream>
#include<cmath>
using namespace std;
float f(float x){
  return(3*x*x+2*x);
}
int main()
{
  float x0,y0,xn,h,yn;
  int n;
  cout<<"Enter the value of x0 and y0:";
  cin>>x0>>y0;
  cout<<"Enter the value of xn:";
  cin>>xn;
  cout<<"Enter the value of n:";
  cin>>n;
  h=(xn-x0)/n;
  for(int i=0;i<n;i++){
    yn=y0+h*f(x0);
    x0=x0+h;
    y0=yn;
    cout<<"Set of points: "<<x0<<"\t"<<y0<<endl;
  }
  return 0;
}
