#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int N = 100, b[N];

    for (int i = 0; i < N; i++)
    {
        b[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0 && a[i] <N)
        {
            b[a[i]] = 1;
        }

    }

    for (int i = 0; i < n; i++){
        
        if (b[i] == 0)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}