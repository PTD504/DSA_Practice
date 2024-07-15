/*
###########################################
Source: GeeksforGeeks

Problem statement:
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Constraints:
1 ≤ N ≤ 10000

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

class Solution{
public:
    std::vector<int> nextPermutation(int N, std::vector<int> arr){
        if (std::next_permutation(arr.begin(), arr.end())) {
            return arr;
        }

        return arr;
    }
};

int main() {
    int N = 20;
	std::vector<int> arr = {3, 1, 12, 5, 18, 10, 15, 7, 19, 6, 13, 20, 11, 16, 2, 9, 4, 17, 8, 14};

    Solution obj;

    for (auto v : obj.nextPermutation(N, arr)) {
        std::cout << v << ' ';
    }
}