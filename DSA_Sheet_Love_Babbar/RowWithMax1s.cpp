/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's. Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Constraints:
1 ≤ number of rows, number of columns ≤ 10^3
0 ≤ arr[i][j] ≤ 1 

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int rowWithMax1s(std::vector<std::vector<int> > arr) {
        int n = arr.size(), m = arr[0].size();
        int i = 0, j = m - 1;
        int ans = -1;

        while (i < n and j >= 0) {
            if (arr[i][j]) j--, ans = i;
            else i++;
        }

        return ans;
    }
};

int main() {
    int r = 7, c = 8;
    std::vector<std::vector<int> > matrix = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1}
    };

    Solution obj;

    std::cout << obj.rowWithMax1s(matrix);
}