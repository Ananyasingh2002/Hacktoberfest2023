#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int arr[n], arr2[n];
    for (int j = 0; j < n; j++)
    {
        cin >> arr[j];
    }

    int N = 10e6+2, idx[N], minidx=INT_MAX;
    for (int j = 0; j < N; j++){
        idx[j] = -1;
    }

    for (int j = 0; j < n; j++)
    {
        if (idx[arr[j]] != -1){
            if (minidx >= j) minidx = j;
        }
        else {
            idx[arr[j]] = j;
        }
    }

    cout<<minidx<<endl;
    return 0;
}