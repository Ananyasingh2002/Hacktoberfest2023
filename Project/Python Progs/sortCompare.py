import matplotlib.pyplot as plt
import psutil
import time
import random


# function for Insertion Sort
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# function for Quick Sort
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    
    stack = [(0, len(arr) - 1)]
    while stack:
        low, high = stack.pop()
        if low < high:
            pivot_index = partition(arr, low, high)
            stack.append((low, pivot_index - 1))
            stack.append((pivot_index + 1, high))

# Quick Sort Helper function
def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# function for Merge Sort
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)

# Merge Sort helper function
def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

# funciton for Heap Sort
def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)


# Heap Sort Helper function
def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and arr[i] < arr[left]:
        largest = left
    if right < n and arr[largest] < arr[right]:
        largest = right
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


# Measure execution time and space complexity for each sorting algorithm
random_list_sizes = [1000, 2000, 3000, 4000, 5000]  # Different input sizes
cases = ['Best Case', 'Average Case', 'Worst Case']
sorting_algorithms = [insertion_sort, quick_sort, merge_sort, heap_sort]
algorithm_names = ['Insertion Sort', 'Quick Sort', 'Merge Sort', 'Heap Sort']

execution_times = {algo: {case: [] for case in cases} for algo in algorithm_names}
space_complexities = {algo: {case: [] for case in cases} for algo in algorithm_names}

for algo, algo_name in zip(sorting_algorithms, algorithm_names):
    for size in random_list_sizes:
        random_list_best = list(range(1, size + 1))  # Best case: Already sorted
        random_list_avg = random.sample(range(1, size + 1), size)  # Average case: Random order
        random_list_worst = list(range(size, 0, -1))  # Worst case: Descending order
        
        for case, random_list in zip(cases, [random_list_best, random_list_avg, random_list_worst]):
            start_time = time.time()
            algo(random_list.copy())
            execution_time = time.time() - start_time
            execution_times[algo_name][case].append(execution_time)
            
            # Measure memory usage
            process = psutil.Process()
            space_complexity = process.memory_info().rss / (1024 ** 2)  # Converting to MB
            space_complexities[algo_name][case].append(space_complexity)

# Determine screen resolution
screen_width, screen_height = plt.figaspect(0.5)  # Set aspect ratio to fit half of the screen

# Plotting subplots for best-case, average-case, and worst-case comparisons for each algorithm
fig, axs = plt.subplots(len(cases), figsize=(screen_width, screen_height), sharex=True)
for idx, case in enumerate(cases):
    for algo_name in algorithm_names:
        axs[idx].plot(random_list_sizes, execution_times[algo_name][case], marker='o', label=algo_name)
        axs[idx].set_ylabel('Execution Time (seconds)')
        axs[idx].set_title(f'{case} Performance')
        axs[idx].grid(True)
        axs[idx].legend()

plt.xlabel('Input Size')
plt.show()