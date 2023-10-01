#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the size"<<endl;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element at position "<<i<<endl;
        cin>>a[i];
    }
    int u=n-1;
    int l=0;
    int m=0;
    int f=0;int q;
    cout<<"Number to be searched"<<endl;
    int s;
    cin>>s;
    for(l=0;l<=u;)
    {
        m=(u+l)/2;
        if(a[m]<s)
        {l=m+1;}
        else if(a[m]>s)
        {u=m-1;}
        else if(a[m]==s)
        {f++;
        q=m;
        break;}
    }
    if(f==1)
    {
        cout<<"Element found at position "<<q<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
}