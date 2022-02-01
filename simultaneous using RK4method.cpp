#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
float function1(float x,float y,float z){
  return(3*x+y-z);
}
float function2(float x,float y,float z){
  return(2*x-y+z);
}
int main(){
  float x0,y0,xn,yn,z0,zn;
  int n;
  float k1,k2,k3,k4,k;
  float l1,l2,l3,l4,l;
  float h;
  cout<<"Enter the value of x0,y0 and z0: ";
  cin>>x0>>y0>>z0;
  cout<<"Enter the value of xn and n:";
  cin>>xn>>n;
  cout<<"Solution of simultaneous equation is:"<<endl;
  cout<<"x0:"<<x0<<"\t"<<"y0:"<<y0<<"\t"<<"z0:"<<z0<<endl;
  cout<<"xn:"<<xn<<"\t"<<"n:"<<n<<"\t"<<endl;
  h=(xn-x0)/n;
  cout<<"h:"<<h<<endl;
  for(int i=0;i<n;i++){
    k1=h*function1(x0,y0,z0);
    l1=h*function2(x0,y0,z0);
    cout<<"k1:"<<k1<<"\t"<<"l1:"<<l1<<endl;
    k2=h*function1(x0+(h/2),y0+(k1/2),z0+(l1/2));
    l2=h*function2(x0+(h/2),y0+(k1/2),z0+(l1/2));
    cout<<"k2:"<<k2<<"\t"<<"l2:"<<l2<<endl;
    k3=h*function1(x0+h/2,y0+k2/2,z0+l2/2);
    l3=h*function2(x0+h/2,y0+k2/2,z0+l2/2);
    cout<<"k3:"<<k3<<"\t"<<"l3:"<<l3<<endl;
    k4=h*function1(x0+h,y0+k3,z0+l3);
    l4=h*function2(x0+h,y0+k3,z0+l3);
    cout<<"k4:"<<k4<<"\t"<<"l4:"<<l4<<endl;
    k=(1.0/6.0)*(k1+2*k2+2*k3+k4);
    l=(1.0/6.0)*(l1+2*l2+2*l3+l4);
    cout<<"k:"<<k<<"\t"<<"l:"<<l<<endl;
    yn=y0+k;
    y0=yn;
    zn=z0+l;
    z0=zn;
    x0=x0+h;
  }
  cout<<"The value of yn: "<<yn<<" and zn: "<<zn<<endl;
  return 0;
}

