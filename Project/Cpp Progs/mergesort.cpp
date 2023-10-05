#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;


void merge(int arr[],int l,int h,int m){
    int n1= m-l+1;
    int n2 = h-m;

int left[n1];
int right[n2];
    for(int i = 0;i<n1;i++){
        left[i] = arr[i+l];
    }
    for(int i = 0;i< n2;i++){
        right[i] = arr[m+i+1];
    }
    int k=l, i = 0,j=0;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    while(i<n1){
        arr[k++] = left[i++];
    }
    while(j<n2){
        arr[k++] = right[j++];
    }
}

void sort(int arr[], int l, int n)
{
    if (l < n)
    {
        int mid = l+(n - l) / 2;
        sort(arr, 0, mid );
        sort(arr, mid + 1, n);
        merge(arr, l, n, mid);
    }
}

int main(){
    int arr[] = {2, 33, 12, 10, 34214, 7, 12};
    int h= (sizeof(arr) / sizeof(arr[0]));
    sort(arr, 0, h-1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
   
return 0 ;
}
