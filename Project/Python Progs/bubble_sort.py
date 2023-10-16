def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        isSwapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                isSwapped = True
        if not isSwapped:
            break

arr = [64, 34, 25, 12, 22, 11, 90]
print("Before sort: ", arr)
bubble_sort(arr)
print("After sort: ", arr)
