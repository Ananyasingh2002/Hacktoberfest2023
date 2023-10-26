

//Problem: Zero Sum Subarryes
// solution using unordered_map<> and prefix sum
// Expected Time Complexity: O(n*log(n))
// Expected Auxilliary Space: O(n)



#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long int Subarray(vector<long long int>&arr,int n){
        long long int result=0;
        map<long long int,int>mp;
        long long int sum=0;
        mp[0]++;
        for(int i=1;i<=n;i++){
            sum+=arr[i-1];
            mp[sum]++;
            result+=mp[sum]-1;
        }
        return result;
    }
};

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long long int>arr(n,0);
        for(int i=0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.Subarray(arr,n)<<"\n";
    }
    return 0;
}