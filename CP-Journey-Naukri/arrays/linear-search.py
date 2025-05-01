def linearSearch(n: int, num: int, arr: [int]) -> int:
    # Write your code here.
    for i in range(n):
        if arr[i] == num:
            return i
    
    return -1