/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an 0-indexed array of integers arr[] of size n, find its peak element and return it's index. An element is considered to be peak if it's value is greater than or equal to the values of its adjacent elements (if they exist).

Constraints:
1 ≤ n ≤ 10^5
1 ≤ arr[i] ≤ 10^6

Solution: PTD504
###########################################
*/

#include <iostream>

/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int findPeakElement(int arr[], int low, int high, int n){
        int mid = low + (high - low) / 2;
        
        if ((mid == 0 and arr[mid] >= arr[mid + 1]) or (mid == n - 1 and arr[mid] >= arr[mid - 1]))
            return mid;
        
        if (mid > 0 and arr[mid] >= arr[mid - 1] and mid < n - 1 and arr[mid] >= arr[mid + 1])
            return mid;
        
        if (mid > 0 and arr[mid - 1] >= arr[mid])
            return findPeakElement(arr, low, mid - 1, n);
        
        else if (mid < n - 1 and arr[mid + 1] >= arr[mid])
            return findPeakElement(arr, mid + 1, high, n);
    }
    
    int peakElement(int arr[], int n)
    {
        if (n == 1) return 0;
       return findPeakElement(arr, 0, n - 1, n);
    }
};

int main() {
    int n = 10; // std::cin >> n;
    int arr[] = {2, 7, 6, 8, 2, 7, 7, 10, 9, 3};

    Solution obj;
    std::cout << obj.peakElement(arr, n);
}