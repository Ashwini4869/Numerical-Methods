#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
float f(float x){
  return (pow(x,3)+2*x+6);
}
int main(){
  float a,b,c,n=0;
  cout<<"Enter two initial guesses:";
  cin>>a>>b;
  do{
    if(fabs(f(a)-f(b))<0.000005){
      cout<<"Error"<<endl;
      exit(0);
    }
    c=(((a*f(b))-(b*f(a)))/(f(b)-f(a)));
    a=b;
    b=c;
    n++;
  }while(fabs(f(c))>0.000005 && n<=500);
  cout<<"The required root is:"<<c<<endl;
  return 0;
}
