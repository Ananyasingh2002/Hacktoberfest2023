#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n=6;
    int arr[n]={1,0,1,2,1,1};
    int low=0,mid=0,high=n-1;
    while (mid<=high)
    {
        /* code */
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for (int i = 0; i <n; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}
