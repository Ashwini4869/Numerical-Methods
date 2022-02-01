#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
int main(){
  int n;
  cout<<"Enter the order of matrix:";
  cin>>n;
  float matrix[n][2*n];
  
  //taking matrix as input
  cout<<"Enter the elements of the matrix"<<endl;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++){
      cout<<"Enter a"<<i<<j<<": ";
      cin>>matrix[i][j];
    }
    for(int j=n+1;j<=(2*n);j++)
    {
      if(j-n==i)
      {
        matrix[i][j]=1;
      }
      else{
        matrix[i][j]=0;
      }
    }
  }
  //printing the augmented matrix
  cout<<"The augmented matrix is:"<<endl;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=(2*n);j++){
      if((j-n)==1) 
      {
        cout<<"|\t";
      }
      cout<<matrix[i][j]<<"\t";
    }
    cout<<endl;
  }
  //generating the inverse matrix
  for(int j=1;j<=n;j++){
    for(int i=1;i<=n;i++){
      if(i==j){
        float temp=matrix[i][j];
        for(int k=1;k<=(2*n);k++){
          matrix[i][k]=matrix[i][k]/temp;
        }
      }
      else
      {
        float ratio=matrix[i][j]/matrix[j][j];
        for(int k=1;k<=(2*n);k++){
          matrix[i][k]=matrix[i][k]-(ratio*matrix[j][k]);
        }
      }
    }
  }
  //displaying the final matrix
  cout<<"The augmented matrix after the operation is"<<endl;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=(2*n);j++){
      if((j-n)==1){
        cout<<"|\t";
      }
      cout<<matrix[i][j]<<"\t";
    }
    cout<<endl;
  }
  //displaying the inverse matrix
  cout<<"The inverse matrix is:"<<endl;
  for(int i=1;i<=n;i++){
    for(int j=n+1;j<=(2*n);j++){
      cout<<matrix[i][j]<<"\t";
    }
    cout<<endl;
  }
  return 0;
}

