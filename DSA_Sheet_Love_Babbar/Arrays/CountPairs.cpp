/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array arr, and an integer k, find the number of pairs of elements in the array whose sum is k.

Constraints:
1 <= arr.size <= 10^5
1 <= k <= 10^8
1 <= arr[i] <= 10^6

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <unordered_map>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

using ll = long long;

class Solution {
  public:
    int getPairsCount(const std::vector<int>& arr, int k) {
        std::unordered_map<int, int> mp;
        int ans = 0;
        for (int i : arr) {
            if (mp.find(k - i) != mp.end()) ans += mp[k - i];
            mp[i]++;
        }
        
        return ans;
    }
};

int main() {
    std::vector<int> arr = {23, 31, 54, 73, 60, 87, 23, 38, 65, 41, 21, 94, 68, 48, 76, 31, 15, 25, 21, 16, 16, 27, 58, 87, 58, 41, 48, 14, 86, 66, 28, 87, 14, 68, 33, 94, 34, 15, 76, 20, 69, 56, 46, 37, 46, 67, 69, 40, 11, 92};
    int k = 84;

    Solution obj;
    
    std::cout << obj.getPairsCount(arr, k);
    
}