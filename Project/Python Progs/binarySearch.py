def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        # Check if the target is present at the middle
        if arr[mid] == target:
            return mid
        
        # If the target is greater, ignore left half
        elif arr[mid] < target:
            left = mid + 1
        
        # If the target is smaller, ignore right half
        else:
            right = mid - 1
    
    # Target was not found in the array
    return -1

# Example usage
arr = [2, 4, 7, 10, 15, 20]
target = int ( input("Enter Element : "));

# Call the binary_search function
result = binary_search(arr, target)

if result != -1:
    print(f"Element found at index {result}")
else:
    print("Element not found in the array")
