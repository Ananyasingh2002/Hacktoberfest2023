// This program sort the array of number in ascending order using heap sort method
// Heap sort is one of the important algorithm to sort the number whose best time and space complexity are respectively O(n * log(n)) and  O(1)

#include <iostream>

// Function to heapify a subtree rooted at index 'root' in the array 'arr'
// n is the size of the heap
void heapify(int arr[], int n, int root) {
    int largest = root; // Initialize largest as root
    int left_child = 2 * root + 1; // Left child index
    int right_child = 2 * root + 2; // Right child index

    // If left child is larger than the largest so far
    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;

    // If right child is larger than the largest so far
    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;

    // If the largest is not the root
    if (largest != root) {
        // Swap the root with the largest element
        std::swap(arr[root], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {13, 26, 5, 172, 77, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    heapSort(arr, n); // sending the array data as a argument in the function

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
