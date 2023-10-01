#include<iostream>
using namespace std;
int getmax(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
void CountingSort(int arr[],int size,int div){
    int k=arr[0];
    for(int i=0;i<size;i++){
        k=max(k,arr[i]);
    }
    int count[10]={0};
    for(int i=0;i<size;i++){
        count[(arr[i]/div)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1]; 
    }
    int output[size];
    for(int i=size-1;i>=0;i--){
        output[--count[(arr[i]/div)%10]]=arr[i];
    }
    for(int i=0;i<size;i++){
        arr[i]=output[i];
    }
}
void RadixSort(int a[],int n){
    int m=getmax(a,n);
    for(int i=1;(m/i)>0;i*=10){//calling the counting sort maximum no. of digits time
        CountingSort(a,n,i);
    }
}
int main()
{
    cout<<"Enter the size of array"<<endl;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<endl;
        cin>>a[i];
    }
    RadixSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    } 
    return 0;
}