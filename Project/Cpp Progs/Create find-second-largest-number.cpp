#include <bits/stdc++.h>
using namespace std;

/* Function to print the second largest elements */
void print2largest(int arr[], int arr_size)
{
    int i, first, second;
    /* There should be atleast two elements */
    if (arr_size < 2) {
        printf(" Invalid Input ");
        return;
    }
    // sort the array
    sort(arr, arr + arr_size);
    // start from second last element as the largest element
    // is at last
    for (i = arr_size - 2; i >= 0; i--) {
        // if the element is not equal to largest element
        if (arr[i] != arr[arr_size - 1]) {
            printf("The second largest element is %d\n",arr[i]);
            return;
        }
    }
    printf("There is no second largest element\n");
}

/* Driver program to test above function */
int main()
{
    int arr[] = { 12, 35, 1, 10, 34, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    print2largest(arr, n);
    return 0;
}
