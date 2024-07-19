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
#include <algorithm>
#include <vector>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution{
public:
    std::vector<int> nextPermutation(int N, std::vector<int> arr){
        if (std::next_permutation(arr.begin(), arr.end())) {
            return arr;
        }

        std::reverse(arr.begin(), arr.end());
        
        return arr;
    }
};

int main() {
    int N = 20;
	std::vector<int> arr = {32, 34, 43, 7, 9, 35, 5, 6, 31, 28, 31, 41, 33, 33, 41, 18, 20, 31, 33, 4};

    Solution obj;

    for (auto i : obj.nextPermutation(N, arr)) std::cout << i << ' ';
}