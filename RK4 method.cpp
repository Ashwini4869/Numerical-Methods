#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

float f(float x,float y){
  return(x+8);
}
int main(){
  float x0,y0,xn,yn;
  int n;
  float m1,m2,m3,m4,m;
  cout<<"Enter the value of x0,y0 and xn:";
  cin>>x0>>y0>>xn;
  cout<<"Enter the value of n:";
  cin>>n;
  float h;
  h=(xn-x0)/n;
  for(int i=0;i<n;i++){
    m1=f(x0,y0);
    m2=f(x0+h/2,y0+(m1/2));
    m3=f(x0+h/2,y0+(m2/2));
    m4=f(x0+h,y0+m3);
    m=(1.0/6.0)*(m1+2*m2+2*m3+m4);
    yn=y0+m*h;
    y0=yn;
    x0=x0+h;
  }
  cout<<"The value of yn:"<<yn<<endl;
  return 0;
}

