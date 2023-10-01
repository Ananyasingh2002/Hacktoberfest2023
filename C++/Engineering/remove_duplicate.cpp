#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the size "<<endl;
    int n;
    cin>>n;
    int a[n];int f;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element at "<<i<<endl;
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;)
        { int m=j;
        bool dele=false;
            if(a[i]==a[j])
            {dele=true;
                f=j;
            for(int k=f;k<n-1;k++)
            {
             a[k]=a[k+1];
            }
            n--;
            }
            if(dele==true)
            {
                j=m;
            }
            else{
                j++;
            }
        }
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}