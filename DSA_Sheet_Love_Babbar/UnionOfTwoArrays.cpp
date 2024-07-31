/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given two arrays arr1[] and arr2[], the task is to find the number of elements in the union between these two arrays.

The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union.

Note: Elements are not necessarily distinct.

Constraints:
1 ≤ arr1.size, arr2.size ≤ 10^5
0 ≤ arr1[i], arr2[i] < 10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(std::vector<int> arr1, std::vector<int> arr2) {
        std::unordered_map<int, int> mp;

        for (int i : arr1) mp[i] = 1;

        for (int i : arr2) {
            mp[i] = 1;
        }

        return mp.size();
    }
};

int main() {
	std::vector<int> arr1 = {22, 41, 36, 3, 6, 4, 49, 29, 32, 20, 10, 45, 37, 34, 23, 47, 22, 17, 25, 21, 36, 26, 17, 12, 6, 46, 29, 6, 38, 7};
    std::vector<int> arr2 = {41, 6, 28, 48, 9, 13, 31, 36, 41, 16, 42, 7, 3, 1, 18, 55, 56, 25, 10, 51};

    Solution obj;

    std::cout << obj.doUnion(arr1, arr2);
}