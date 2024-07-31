/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a number x and an array of integers arr, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

Constraints:
1 <= arr.size, x <= 10^5
0 <= arr[i] <= 10^4

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

#define min(a, b) (a < b ? a : b)

class Solution {
public:
    
    int smallestSubWithSum(int x, std::vector<int>& arr) {
        int sum = 0, j = 0;
        int ans = arr.size() + 1;

        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];

            while (j <= i and sum > x) {
                ans = min(ans, i - j + 1);
                sum -= arr[j++];
            }
        }

        return (ans > arr.size() ? 0 : ans);
    }
    
};

int main() {
    int x = 78;
    std::vector<int> arr = {39, 4, 15, 39, 0, 22, 15, 0, 32, 12, 36, 28, 29, 30, 2, 30, 20, 23, 13, 28, 36, 22, 12, 33, 23, 3, 14, 1, 0, 20};

    Solution obj;
    std::cout << obj.smallestSubWithSum(x, arr);
}