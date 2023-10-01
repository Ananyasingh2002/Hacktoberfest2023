#include<iostream>
using namespace std;

int ReverseInteger(int n){
    int ans=0;
    while(n!=0){
        int d= n%10;
        if((ans>INT_MAX/10) || (ans<INT_MIN/10)){
            return 0;
        }
        ans = ans*10+d;
        n=n/10;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
   cout<<ReverseInteger(n);

}