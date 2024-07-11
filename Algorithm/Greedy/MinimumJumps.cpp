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

class Solution{
  public:
    int minJumps(int arr[], int n){
        int ans = 0, steps = arr[0], i = 1, idx = 0;

        while (i < n and steps) {
            int m = 0, ix = 0;

            while (steps -- and i < n) {
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
    int n = 30; // std::cin >> n;
    int arr[n] = {10, 8, 12, 11, 9, 12, 7, 14, 12, 8, 10, 3, 7, 12, 7, 8, 14, 4, 3, 5, 12, 3, 7, 5, 3, 14, 2, 15, 9, 8};

    Solution obj;

    std::cout << obj.minJumps(arr, n);
}