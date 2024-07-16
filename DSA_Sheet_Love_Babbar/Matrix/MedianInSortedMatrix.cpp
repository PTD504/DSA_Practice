/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Constraints:
1 <= R, C <= 400
1 <= matrix[i][j] <= 2000

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
    int median(std::vector<std::vector<int>> &matrix, int R, int C){
        int mx = -1e9, mn = 1e9;

        for (int i = 0; i < R; ++i) {
            mx = max(mx, matrix[i][C - 1]);
            mn = min(mn, matrix[i][0]);
        }

        int nums = ((R * C + 1) >> 1); // The number of elements less than or equal to the median element
        
        while (mn < mx) {
            int mid = mn + ((mx - mn) >> 1);
            int cnt = 0;

            for (int i = 0, idx; i < R; ++i) {
                idx = std::upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                cnt += idx;
            }

            if (cnt >= nums) mx = mid;
            else mn = mid + 1;
        }

        return mn;
    }
};

int main() {
    int R = 9, C = 9;
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7, 9, 11, 13, 15, 17},
        {2, 4, 6, 8, 10, 12, 14, 16, 18},
        {19, 21, 23, 25, 27, 29, 31, 33, 35},
        {20, 22, 24, 26, 28, 30, 32, 34, 36},
        {37, 39, 41, 43, 45, 47, 49, 51, 53},
        {38, 40, 42, 44, 46, 48, 50, 52, 54},
        {55, 57, 59, 61, 63, 65, 67, 69, 71},
        {56, 58, 60, 62, 64, 66, 68, 70, 72},
        {73, 75, 77, 79, 81, 83, 85, 87, 89}
    };

    Solution obj;

    std::cout << obj.median(matrix, R, C);
}