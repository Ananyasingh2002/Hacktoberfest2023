#include <iostream>
using namespace std;

int main(){

    int t;
    cin>>t;

    for (int i=1; i<=t;i++){
        int n;
        cin>>n;

        int arr[n],max=0,rb=0;

        for (int j=0; j<n;j++){
            cin>>arr[j];
        }

        for (int j=0; j<n;j++){
            if (arr[j]>max){
                max=arr[j];
                if (arr[j]>arr[j+1]) {
                    rb++;
                }
            }

        }
        cout<< i<<" : "<<rb<<endl;
    }

    return 0;
}