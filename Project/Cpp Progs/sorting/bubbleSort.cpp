#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swaped = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaped = true;
            }
           
        }

         if (swaped == false)
            {
                break;
            }
    }
}
int main()
{
    int arr[] = {2, 33, 12, 10, 34214, 7, 12};
    bubblesort(arr, sizeof(arr) / sizeof(arr[0]));
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
