#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
int main(){
  int n;
  cout<<"Enter the value of n:";
  cin>>n;
  float ratio;
  float a[n][n+1];
  cout<<"Enter the value of elements:"<<endl;
  //matrix input
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n+1;j++)
    {
      cout<<"a"<<i<<j<<":";
      cin>>a[i][j];
  }
  }
  //row manipulation
  for(int j=1;j<=n;j++){
    if(fabs(a[j][j])<0.000005){
      cout<<"pivot element becomes zero. cannot find the solution"<<endl;
      exit(0);
    }
    for(int i=1;i<=n;i++){
      if(i!=j){
      ratio=a[i][j]/a[j][j];
      for(int k=1;k<=n+1;k++){
        a[i][k]=a[i][k]-ratio*a[j][k];
      }
        }
    }
  }
  //output
  for(int l=1;l<=n;l++){
    cout<<"x"<<l<<"="<<(a[l][n+1]/a[l][l])<<endl;
  }
  return 0;
}
