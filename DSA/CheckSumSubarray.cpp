#include <iostream>
using namespace std;

int main(){

    int n,s;
    cin>>n;
    cin>>s;
    
    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }

    for (int i=0; i<n; i++){
        int sum = 0;
        for (int j=i; j<n; j++){
            sum += a[j];
            if (sum == s){
                cout<<i+1<<" "<<j+1<<endl;
                break;
            }
            else if (sum >s){
                break;
            }
        }
        if (sum == s){
            break;
        }
    }

    return 0;
}