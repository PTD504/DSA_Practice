/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Constraints:
3 <= N <= 10^6
0 <= A[i] <= 10^8

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:

    long long trappingWater(int height[], int n) {
        long long ans = 0, f = 0, vf = height[0], prefix[n];
        prefix[0] = height[0];

        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + height[i];
            if (height[i] >= vf) {
                ans += (i - f - 1) * vf - (prefix[i - 1] - prefix[f]);
                f = i, vf = height[f];
            }
        }

        for (long long i = n - 2, f1 = n - 1, vf1 = height[f1], st = f; i >= f; --i) {
            if (height[i] >= vf1) {
                ans += (f1 - i - 1) * vf1 - (prefix[f1 - 1] - prefix[i]);
                f1 = i, vf1 = height[f1];
            }
        }

        return ans;
    }
};

int main() {
    int n = 50;
    int arr[] = {67, 59, 56, 63, 92, 61, 33, 38, 8, 39, 52, 73, 90, 49, 44, 4, 41, 90, 2, 20, 53, 66, 65, 74, 70, 53, 42, 95, 60, 14, 60, 43, 31, 22, 67, 24, 42, 74, 54, 47, 2, 34, 95, 88, 27, 73, 19, 79, 77, 42};

    Solution obj;

    std::cout << obj.trappingWater(arr, n);
}