def maxSubarraySum(arr, n) :
    # Your code here
    # return the answer
    s, mn, mx_sum = 0, 0, 0

    for val in arr:
        s += val
        mx_sum = max(mx_sum, s - mn)
        mn = min(mn, s)  

    return mx_sum