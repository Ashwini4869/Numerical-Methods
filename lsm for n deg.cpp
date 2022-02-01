//lsm for n degree polynomial
#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
int main()
{
  //variable declarations
  int n,d;
  cout<<"Enter the number of data sets of x and y:";
  cin>>n;
  
  cout<<"Enter the degree of the equation to which we need to fit the curve:";
  cin>>d;
  if(n<d){
    exit(1);
  }
  //taking inputs from the user
  float x[n],y[n];
  cout<<"Enter the data sets of x"<<endl;
  for(int i=0;i<n;i++){
    cout<<"x"<<i<<":";
    cin>>x[i];
  }
  cout<<"Enter the data sets of y"<<endl;
  for(int i=0;i<n;i++){
    cout<<"y"<<i<<":";
    cin>>y[i];
  }
  float C[d][d+1];
  //generating augmented coeff matrix
  for(int i=0;i<=d;i++){
    for(int j=0;j<=d;j++){
      C[i][j]=0;
      for(int k=0;k<n;k++){
        C[i][j]=(C[i][j]+pow(x[k],i+j));
      }
    }
  }
  for(int i=0;i<=d;i++){
    int j=d+1;
    for(int k=0;k<n;k++){
      C[i][j]=(C[i][j]+(pow(x[k],i)*y[k]));
    }
  }
  //displaying the augmented matrix
  for(int i=0;i<=d;i++){
    for(int j=0;j<=d+1;j++){
      cout<<C[i][j]<<"\t";
    }
    cout<<endl;
  }
  //solving the matrix by gauss jordan method
  for(int j=0;j<d;j++){
    if((fabs(C[j][j])<0.000005)){
      cout<<"pivot element becomes zero.cannot find the solution"<<endl;
      exit(1);
    }
    for(int i=0;i<d;i++){
      if(i!=j){
        float ratio=C[i][j]/C[j][j];
        for(int k=0;k<d+1;k++){
          C[i][k]=C[i][k]-ratio*C[j][k];
        }
      }
    }
  }
  //output
  for(int l=0;l<=d;l++){
    cout<<"a"<<l<<"="<<(C[l][d+1]/C[l][l])<<endl;
}
  return 0;
}
