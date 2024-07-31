/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an integer array arr[]. Find the contiguous sub-array(containing at least one number) that has the maximum sum and return its sum.

Constraints:
-10^7 ≤ arr[i] ≤ 10^7
1 ≤ arr.length ≤ 10^6

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

class Solution {
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(std::vector<int> &arr) {
        long long sum = 0, mn = 0, ans = -1e13 - 1;

        for (int i : arr) {
            sum += i;
            ans = max(ans, sum - mn);
            mn = min(mn, sum);
        }

        return ans;
    }
};

int main() {
	int n = 20;
    std::vector<int> arr = {-95, -77, -21, 27, -41, -49, -13, -15, -39, 77, -75, 47, 19, -78, 12, -46, 79, -69, 83, -79, 14, 65, 27, -52, -97, -26, 4, 1, -44, 79, -67, -77, -67, -34, 41, -50, 46, -66, -1, 66, 84, 3, 91, 75, -64, -35, -3, -52, -55, -78};

    Solution obj;

    std::cout << obj.maxSubarraySum(arr);
}