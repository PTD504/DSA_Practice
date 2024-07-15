/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array arr[] of size n of non-negative integers. Each array element represents the maximum length of the jumps that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
Find the minimum number of jumps to reach the end of the array starting from the first element. If an element is 0, then you cannot move through that element.
Note:  Return -1 if you can't reach the end of the array.

Constraints:
0 ≤ arr[i] ≤ 10^7
1 ≤ n ≤ 10^7

Solution: PTD504
###########################################
*/

#include <iostream>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

class Solution{
  public:
    int minJumps(int arr[], int n){
        int ans = 0, steps = arr[0], i = 1, idx = 0;

        while (i < n and steps) {
            int m = 0, ix = 0;

            while (i < n and steps --) {
                if (i + arr[i] > m + ix) m = arr[i], ix = i;
                i++;
            }

            idx = ix, steps = m - (i - idx - 1);
            ans++;
        }

        return i >= n ? ans : -1;
    }
};

int main() {
	int n = 36;
    int arr[] = {14, 5, 22, 14, 18, 6, 9, 18, 20, 6, 5, 22, 11, 15, 14, 6, 20, 5, 2, 17, 2, 23, 15, 17, 23, 22, 19, 17, 14, 7, 3, 0, 25, 19, 15, 9};

    Solution obj;

    std::cout << obj.minJumps(arr, n);
}