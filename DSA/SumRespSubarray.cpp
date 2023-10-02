#include <iostream>
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

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                cout << a[k] << " ";
                sum += a[k];
            }
            cout << endl
                 << "sum: " << sum << endl
                 << endl;
        }
    }

    return 0;
}