#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
int main(){
  int n;
  cout<<"Enter the value of n:";
  cin>>n;
  float ratio;
  float x[n];
  float a[n][n+1];
  cout<<"Enter the value of elements:"<<endl;
  //taking matrix as input
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n+1;j++){
      cout<<"a"<<i<<j<<":";
      cin>>a[i][j];
    }
  }
    //applying gauss elimination on matrix 
    for(int j=1;j<=n;j++){
      if(fabs(a[j][j])<0.00005){
        cout<<"cannot find soln.pivot element becomes zero"<<endl;
        exit(0);
      }
      for(int i=j+1;i<=n;i++){
        if(i>j){
        ratio=a[i][j]/a[j][j];
        for(int k=1;k<=n+1;k++){
          a[i][k]=a[i][k]-ratio*a[j][k];
        }
      }
    }
    }
    //obtaining soln by back substitution
    x[n]=a[n][n+1]/a[n][n];
    for(int i=n-1;i>=1;i--){
      float sum=0;
      for(int j=i+1;j<=n;j++){
        sum=sum+a[i][j]*x[j];
      }
      x[i]=(a[i][n+1]-sum)/a[i][i];
    }
    //displaying unknowns
    for(int l=1;l<=n;l++){
      cout<<"x"<<l+1<<"="<<x[l]<<endl;
    }
  return 0;
}
