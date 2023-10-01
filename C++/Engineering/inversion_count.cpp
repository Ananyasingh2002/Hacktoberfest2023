#include<iostream>
#include<array>
using namespace std;
void conquer(int arr[], int si, int mid, int ei){
    int merge[ei-si+1];
    int idx1=si;
    int idx2=mid+1;
    int x=0;
    int count=0;
    while(idx1<=mid && idx2<=ei){
        if(arr[idx1]<=arr[idx2]){
            merge[x++]=arr[idx1++];
        }else{
            count+=(mid-idx1);
            merge[x++]=arr[idx2++];
        }
    }
    while(idx1<=mid){
        merge[x++]=arr[idx1++];
    }
    while(idx2<=ei){
        merge[x++]=arr[idx2++];
    }
    for(int i=0,j=si;i<ei-si+1;i++,j++)
    {
        arr[j]=merge[i];
    }
    cout<<count<<endl;
}
void divide(int arr[], int si, int ei){
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;
    divide(arr,si,mid);
    divide(arr,mid+1,ei);
    conquer(arr,si,mid,ei);
}
int main()
{
    int a[]={2,4,1,3,5};
    int n=sizeof(a)/sizeof(a[0]);
    int count=0;
    divide(a,0,n-1);
    //print
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
 return 0;
}