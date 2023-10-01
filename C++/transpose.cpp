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
    int a[r][c];int b[c][r];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           b[j][i]=a[i][j];
        }
    }
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
           cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
}