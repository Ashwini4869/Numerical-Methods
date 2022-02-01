//least square method for linear y=a+bx
#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int n;
  float xi,yi,sumx=0,sumxsq=0,sumy=0,sumxy=0;
  float a,b;
  float det;
  cout<<"Enter the value of n:";
  cin>>n;
  for(int i=0;i<n;i++){
    cout<<"Enter the value of xi and yi:";
    cin>>xi>>yi;
    sumx=sumx+xi;
    sumxsq=sumxsq+pow(xi,2);
    sumy=sumy+yi;
    sumxy=sumxy+xi*yi;
  }
  det=(n*sumxsq)-(sumx*sumx);
  a=((sumy*sumxsq)-(sumxy*sumx))/det;
  b=((n*sumxy)-(sumx*sumy))/det;
  cout<<"The value of a and b:"<<a<<"\t"<<b<<endl;
  return 0;
}
