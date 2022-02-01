#include<iostream>
#include<cmath>
using namespace std;
float f(float x){
  return(pow(x,3)+2*pow(x,2)+5);
}
float fdiff(float x){
  return(3*pow(x,2)+4*x);
}
int main(){
  float x0,x1,e,count=0;
  cout<<"Enter the initial value of x:";
  cin>>x0;
  cout<<"Enter tolerable error:";
  cin>>e;
  do{
    if(fabs(fdiff(x0))<0.000005){
      cout<<"Derivative is zero."<<endl;
      exit(0);
    }
    x1=x0-(f(x0)/fdiff(x0));
    x0=x1;
    count++;
  }while(fabs(f(x0))>e && count<500);
  cout<<"The required root is:"<<x1<<endl;
  return 0;
}
