#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the size of array"<<endl;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element at position "<<i<<endl;
        cin>>a[i];
    }
    int j=n-1;int temp;
    for(int i=0;i<n/2;i++)
    {
        //if(j==n-i-1)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            j--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}