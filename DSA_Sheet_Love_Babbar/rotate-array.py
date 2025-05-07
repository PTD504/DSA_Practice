def rotateArray(arr: list, k: int) -> list:
    # Write your code here.
    n = len(arr)

    if k >= n:
        k %= n
    if k == 0:
        return arr

    arr = arr[k:] + arr[:k]

    return arr