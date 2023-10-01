#include<iostream>
using namespace std;

int linear_search(int arr[],int n,int key){
    
        for(int i=0;i<n;i++)
        {
            if(arr[i]==key)
            return i;
        }
    
return -1;}

int main()
{
    int arr[10],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
   int index=linear_search(arr,n,key);
   if(index!=-1){
   cout<<" NUMBER IS PRESENT "<<index<<endl;}
   else{
   cout<<"NUMBER IS NOT PRESENT"<<endl;}

return 0;
}
