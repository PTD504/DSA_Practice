/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B. (There are some notes you can ignore).

Constraints:
1 <= N <= 30
1 <= A[i] <= 20
1 <= B <= 100

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include "Sorting.h"
#include <algorithm>

using namespace Sorting::HeapSort;

class Solution {

public:
    std::vector<std::vector<int> > ans;

    void recursion(const std::vector<int>& A, std::vector<int> curAns, int idx, int B) {
        if (B == 0) {
            ans.push_back(curAns);
            return;
        }

        while (idx < A.size() and A[idx] <= B) {
            B -= A[idx];
            curAns.push_back(A[idx]);
            recursion(A, curAns, idx, B);
            curAns.pop_back();
            B += A[idx];
            idx++;
        }
    }

    std::vector<std::vector<int> > combinationSum(std::vector<int> &A, int B) {
        sort(A);
        A.erase(unique(A.begin(), A.end()), A.end());

        std::vector<int> curAns;

        recursion(A, curAns, 0, B);

        return ans;
    }
};

int main() {
    std::vector<int> A = {6,5,7,1,8,2,9,9,7,7,9};
    int B = 6; //std::cin >> B;

    Solution obj;

    for (auto v : obj.combinationSum(A, B)) {
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';
    }
}