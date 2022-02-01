//least square method of curve fitting for exp
#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int n;
  float xi,yi,sumx=0,sumxsq=0,sumy=0,sumxy=0;
  float A,B,a;
  float det;
  cout<<"Enter the value of n:";
  cin>>n;
  for(int i=0;i<n;i++){
    cout<<"Enter the value of xi and yi:";
    cin>>xi>>yi;
    sumx=sumx+xi;
    sumxsq=sumxsq+pow(xi,2);
    sumy=sumy+log(yi);
    sumxy=sumxy+xi*log(yi);
  }
  det=(n*sumxsq)-(sumx*sumx);
  A=((sumy*sumxsq)-(sumxy*sumx))/det;
  B=((n*sumxy)-(sumx*sumy))/det;
  a=exp(A);
  cout<<"The value of a and b:"<<a<<"\t"<<B<<endl;
  return 0;
}
