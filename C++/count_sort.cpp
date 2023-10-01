#include<iostream>
using namespace std;
void countSort(int arr[],int size){//complexity max(Ai,N) . Ai is the max element in array
    int k=arr[0];
    for(int i=0;i<size;i++){
        k=max(k,arr[i]);
    }
    int count[10]={0};
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    int output[size];
    for(int i=size-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<size;i++){
        arr[i]=output[i];
    }
}
int main()
{
    int arr[]={1,3,2,3,4,1,6,4,3};
    countSort(arr,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}