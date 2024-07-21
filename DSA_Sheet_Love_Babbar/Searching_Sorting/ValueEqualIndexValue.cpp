/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array arr. Your task is to find the elements whose value is equal to that of its index value ( Consider 1-based indexing ).

Note: There can be more than one element in the array which have the same value as its index. You need to include every such element's index. Follows 1-based indexing of the array.

Constraints:
1 ≤ arr.size ≤ 10^5
1 ≤ arr[i] ≤ 10^6

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

class Solution {
  public:
    // Function to find elements in the array that are equal to their index.
    std::vector<int> valueEqualToIndex(std::vector<int>& arr) {
        int idx = 0, n = arr.size();

        for (int i = 0; i < n; ++i) {
            if (arr[i] == i + 1) std::swap(arr[i], arr[idx++]);
        }

        arr.resize(idx);

        return arr;
    }
};

int main() {
    std::vector<int> arr = {1, 2, 3, 15, 4, 6, 7, 8, 16, 9, 11, 2, 7, 14, 15, 9, 17, 18, 1, 20, 21, 9, 23, 24, 25, 20, 9, 2, 3, 9, 31, 32, 11, 5, 35, 36, 37, 38, 2, 40};

    Solution obj;

    for (auto i : obj.valueEqualToIndex(arr)) std::cout << i << ' ';
}