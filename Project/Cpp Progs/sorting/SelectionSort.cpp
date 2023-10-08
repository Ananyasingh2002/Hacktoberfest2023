// Selection Sort 
#include <iostream>
using namespace std;
void swap(int& a,int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}
void SelectionSort(int n,int arr[] )
{
  int  min_idx;
    for(int i=0;i<n;i++)
    {
        min_idx=i;
        for(int j=i;j<n;j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
                
            }
        }
        if(min_idx!=i)
        swap(arr[min_idx],arr[i]);
    }
  
    // cout<<"array is"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    int n = 5;
    int arr[] = {5,4,2,1,3};
    cout<<"Array before sorting"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Array after sorting"<<endl;
    SelectionSort(n,arr);
     for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}