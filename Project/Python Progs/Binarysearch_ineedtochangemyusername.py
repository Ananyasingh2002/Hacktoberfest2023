def bin(arr, x,low, high):
    if high >= low:
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return bin(arr, low, mid - 1, x)
        else:
            return bin(arr, mid+ 1, high, x)
    else:
        return -1
arr = [ 2, 3, 4, 10, 40 ]
x = 10

result = bin(arr, 0, len(arr)-1, x)
if result != -1:
    print(str(result))
else:
    print("Element not there in array")