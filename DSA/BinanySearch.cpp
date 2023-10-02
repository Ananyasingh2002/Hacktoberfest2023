#include <iostream>
using namespace std;

int binarySearch(int key, int arr[], int n){
    int s=0, e=n;
    while (s<=e){
        int mid = (e+s)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            s= mid-1;
        }
        else {
            e = mid+1;
        }
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;
    cout<<binarySearch(key,arr,n)<<endl;

    return 0;
}