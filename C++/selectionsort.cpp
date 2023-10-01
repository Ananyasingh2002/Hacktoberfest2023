#include<iostream>
using namespace std;
int main()
{   int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
       int min=i;
       for(int j=i+1;j<n;j++)
       {if(a[j]<a[min])
       {min=j;}}
       int temp=a[min];
       a[min]=a[i];
       a[i]=temp;
    }
    cout<<"The sorted array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}