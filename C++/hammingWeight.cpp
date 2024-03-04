//# COUNT NUMBER OF 1 BITS #//
#include<iostream>
using namespace std;

int HammingWeight(int n){
    int ans=0;
    while(n){                      // 1 & 1 = 1 and 0 & 1 =0 so in this way we will count number of 1
        if(n & 1){                 // then we will right shift the n till it becomes 0
            ans++;
        }
       n= n>>1;
    }
    return ans;
}

int main(){

    int n;
    cout<<"enter n";
    cin>>n;

    cout<<HammingWeight(n);

}