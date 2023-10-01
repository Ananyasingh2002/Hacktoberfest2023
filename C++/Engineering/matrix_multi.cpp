#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of rows"<<endl;
    int r;
    cin>>r;
    cout<<"Enter the number of columns"<<endl;
    int c;
    cin>>c;
    cout<<"Enter the first array"<<endl;
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           cin>>a[i][j];
        }
    }
    cout<<"Enter the number of rows"<<endl;
    int r1;
    cin>>r1;
    cout<<"Enter the number of columns"<<endl;
    int c1;
    cin>>c1;
    cout<<"Enter the second array"<<endl;
    int b[r1][c1];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
           cin>>b[i][j];
        }
    }
    if(c==r1)
    {
    int d[r][c1];
    for(int i=0;i<r;i++)
     { 
    for(int j=0;j<c1;j++)
        {    d[i][j]=0;
          for(int k=0;k<r1;k++)
          {
              d[i][j]+=a[i][k]*b[k][j];
          }
     }
  }
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c1;j++)
    {
        cout<<d[i][j]<<" ";
    }
    cout<<"\n";
  }
}
else{
    cout<<"Matrix Format Wrong"<<endl;
}
}