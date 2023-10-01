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
  cout<<"Enter the matrix"<<endl;
  int a[r][c];
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      cin>>a[i][j];
    }
  }
  int sumr=0;
  int sumc=0;
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
        sumr+=a[i][j];
    }
    cout<<"Sum of elements in Row "<<(i+1)<<" is "<<sumr<<endl;
    sumr=0;
  }
  for(int j=0;j<c;j++)
  {
    for(int i=0;i<r;i++)
    {
        sumc+=a[i][j];
    }
    cout<<"Sum of elements in Column "<<(j+1)<<" is "<<sumc<<endl;
    sumr=0;
  }
}