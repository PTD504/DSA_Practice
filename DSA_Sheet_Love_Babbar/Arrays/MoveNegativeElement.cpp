/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an unsorted array arr[ ] having both negative and positive integers. The task is to place all negative elements at the end of the array without changing the order of positive elements and negative elements.

Constraints:
1 ≤ arr.size ≤ 10^6
-10^9 ≤ arr[i] ≤ 10^9

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

class Solution {
public:
    void segregateElements(std::vector<int>& arr) {
        std::vector<int> neg;

        for (int i : arr) if (i < 0) neg.push_back(i);

        int j = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] >= 0) std::swap(arr[i], arr[j]), j++;
        }

        j = arr.size() - 1;
        while (neg.size()) arr[j--] = neg.back(), neg.pop_back();
    }
};

int main() {
	int n = 20;
    std::vector<int> arr = {40, 40, -12, -42, -2, 26, -36, -16, -49, 50, -20, -30, -16, 2, -36, -27, -25, -22, -16, 9, -49, -18, -41, -21, -50, 50, -48, -40, -21, 1};

    Solution obj;

    obj.segregateElements(arr);

    for (auto i : arr) std::cout << i << ' ';
}