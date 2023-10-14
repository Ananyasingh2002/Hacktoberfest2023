def selection_sort(arr):
    # Traverse through all but the last element in the list
    for i in range(len(arr) - 1):
        # Find the minimum element in the unsorted part of the list
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
                
        # Swap the found minimum element with the first element in the unsorted part
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Example Usage
unsorted_list = [64, 25, 12, 22, 11]
print("Unsorted list:", unsorted_list)

# Call the selection_sort function
selection_sort(unsorted_list)

print("Sorted list:", unsorted_list)
