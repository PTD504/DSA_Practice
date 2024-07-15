/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.

Note:  l and r denotes the starting and ending index of the array.

Constraints:
1 <= n <= 10^5
l = 0
r = N-1
1<= arr[i] <= 10^5
1 <= k <= n

Solution: PTD504
###########################################
*/

#include <iostream>
#include <algorithm>

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        std::sort(arr, arr + r + 1);
        return arr[k - 1];
    }
};

int main() {
	int n = 5, k = 3;
    int arr[] = {4, 3, 2, 7, 8};

    Solution obj;

    std::cout << obj.kthSmallest(arr, 0, n - 1, k);
}