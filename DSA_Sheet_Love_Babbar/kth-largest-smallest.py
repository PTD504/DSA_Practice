import random
from typing import List

def partition_kth_smallest(arr: List[int], low: int, high: int, pivot_index: int):
    
    pivot = arr[pivot_index]

    # swap(arr[pivot_index], arr[high])
    temp = arr[high]
    arr[high] = arr[pivot_index]
    arr[pivot_index] = temp

    store_index = low

    for i in range(low, high):
        if arr[i] < pivot:
            # swap(arr[i], arr[store_index])
            temp = arr[i]
            arr[i] = arr[store_index]
            arr[store_index] = temp

            store_index += 1
    
    # swap(arr[high], arr[store_index])
    temp = arr[high]
    arr[high] = arr[store_index]
    arr[store_index] = temp

    return store_index

def partition_kth_largest(arr: List[int], low: int, high: int, pivot_index: int):
    
    pivot = arr[pivot_index]

    temp = arr[high]
    arr[high] = arr[pivot_index]
    arr[pivot_index] = temp

    store_index = low

    for i in range(low, high):
        if arr[i] > pivot:
            temp = arr[i]
            arr[i] = arr[store_index]
            arr[store_index] = temp

            store_index += 1
        
    temp = arr[high]
    arr[high] = arr[store_index]
    arr[store_index] = temp

    return store_index
   
def quickSelect(partition, arr: List[int], low: int, high: int, k: int):
    if low == high:
        return arr[low]
    
    pivot_index = random.randint(low, high)
    pivot_index = partition(arr, low, high, pivot_index)

    if k == pivot_index:
        return arr[pivot_index]
    elif k < pivot_index:
        return quickSelect(partition, arr, low, pivot_index - 1, k)
    else:
        return quickSelect(partition, arr, pivot_index + 1, high, k)

def quickSelect_iteratively(partition, arr: List[int], low: int, high: int, k: int):
    
    while low < high:
        
        pivot_index = random.randint(low, high)
        pivot_index = partition(arr, low, high, pivot_index)

        if k == pivot_index:
            return arr[pivot_index]
        elif k < pivot_index:
            high = pivot_index - 1
        else:
            low = pivot_index + 1
    
    return arr[low]

def kthSmallLarge(arr: List[int], n: int, k: int):
    # Write your code here
    mn = quickSelect(partition_kth_smallest, arr, 0, len(arr) - 1, k - 1)
    # mx = quickSelect(partition_kth_largest, arr, 0, len(arr) - 1, k - 1)

    # mn = quickSelect_iteratively(partition_kth_smallest, arr, 0, len(arr) - 1, k - 1)
    mx = quickSelect_iteratively(partition_kth_largest, arr, 0, len(arr) - 1, k - 1)

    return [mn, mx]
