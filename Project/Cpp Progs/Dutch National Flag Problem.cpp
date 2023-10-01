#include<iostream>
using namespace std;
void printarray(int arr[], int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
// Sort 0, 1s

// void sortone(int arr[],int n){
//     int left = 0,right =n-1;
//     while(left < right){
//         while(arr[left]==0 && left<right){
//             left++;
//         }
//         while(arr[right]==1 && left<right){
//             right--;
//         }
//         if(left < right){
//             swap(arr[left],arr[right]);
//             left++;
//             right--;
//         }
//     }
// }
// int main(){
//     int arr[8] = {1,1,1,0,0,1,0,1};
//     int n=8;
//     sortone(arr,8);
//     printarray(arr,n);

//     return 0;
// }

void sortone(int arr[],int n){
    int left = 0,right =n-1, mid = 0;
    while(mid <= right){
        if(arr[mid] == 0){
            swap(arr[left],arr[mid]);
            left++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[right]);
            right--;
        }
       
    }
}
int main(){
    int arr[8] = {1,1,2,0,0,1,2,1};
    int n=8;
    sortone(arr,8);
    printarray(arr,n);

    return 0;
}