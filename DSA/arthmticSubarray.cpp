#include <iostream>
using namespace std;

int main(){

    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int n;
        cin>>n;
        int arr[n],pd[n-1],pe=0,max=1,max2=0;
        for(int j=0; j<n;j++){
            cin>>arr[j];
            pd[j]= arr[j]-pe;
            pe=arr[j];
        }
        for (int j=0; j<n; j++){
            if (pd[j]==pd[j+1]){
                max+=1;
                // cout<<"increment: "<<max<<endl;
            }
            else{
                if (max>max2) {
                    max2=max;
                }
                max=0;
                continue;
            }
        }
        cout<<max2+1<<endl;
    }

    return 0;
}