//Implementation of Bubble sort in C++
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
	bool isUnsorted;
	do {
		isUnsorted = false;
		for (int i = 0; i < (n - 1); i++) {
			if (arr[i] > arr[i + 1]) {
				isUnsorted = true;
				for (; i < (n - 1); i++) {
					if (arr[i] > arr[i + 1]) {
						std::swap(arr[i], arr[i + 1]);
					}
				}
			}
		}
	} while (isUnsorted);
}

// Function to print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout <<" "<< arr[i];
}

int main()
{
	int arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
	int N = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, N);
	cout <<"Sorted array: \n";
	printArray(arr, N);
	return 0;
}
