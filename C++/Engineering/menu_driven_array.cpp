#include<iostream>
using namespace std;
int main()
{ for(int j=1;j<=5;j++){
   cout<<"1:Create an array"<<endl;
   cout<<"2:Print the array"<<endl;
   cout<<"3:Search in an array"<<endl;
   cout<<"4:Insertion in an array"<<endl;
   cout<<"5:Deletion in an array"<<endl;
   cout<<"Anything else to terminate"<<endl;
   int ch;int n;int a[100];
   cin>>ch;
   switch(ch)
   {
    case 1: cout<<"Please provide the size of array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i<<endl;
        cin>>a[i];
    }
    break;
    case 2: for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    break;
    case 3: cout<<"Enter the element to search"<<endl;
    int s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(a[i]==s)
        {
            cout<<"Element found at position "<<i<<endl;
            break;
        }
    }
    cout<<"\n";
    break;
    case 4: cout<<"Enter the element to insert and also the position"<<endl;
    int e,p;
    cin>>e>>p;
   for(int i=n;i>=p;i--)
   {
    a[i+1]=a[i];
   }
   a[p]=e;
   for(int i=0;i<=n;i++)
   {
    cout<<a[i]<<" ";
   }
   cout<<"\n";
   break;
   case 5: cout<<"Enter the element you want to delete"<<endl;
   int d;int f;
   cin>>d;
   for(int i=0;i<n;i++)
    {
        if(a[i]==d)
        {
            f=i;
            break;
        }
    }
    for(int i=f;i<n;i++)
    {
        a[i]=a[i+1];
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    break;
    default: cout<<"Terminated"<<endl;
   }
}
}