// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void InsertionSort(int arr[],int n)
{
    int i,j,key;
   for( i=1;i<n;i++)
   {
       key = arr[i];
       j = i-1;
       while(j>=0 && arr[j]> key)
       {
           arr[j+1] = arr[j];
           j = j-1;
           
       }
       arr[j+1] = key;
       
   }
 
    
}

int main() {
    int arr[] = {64,25,12,22,11};
    cout<<"Array before sorting"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Array after sorting"<<endl;
      InsertionSort(arr,5);
     for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
  

    return 0;
}