#include<iostream>
using namespace std;
int main()
{
    int s[]={1,3,0,5,8,5};
    int f[]={2,4,6,7,9,9};
    int n=sizeof(s)/sizeof(s[0]);
    cout<<"Following activities are selected"<<endl;
    int i=0;
    cout<<i<<" ";
    for(int j=0;j<n;j++){
        if(s[j]>=f[i]){
            cout<<j<<" ";
            i=j;
        }
    }
 return 0;
}