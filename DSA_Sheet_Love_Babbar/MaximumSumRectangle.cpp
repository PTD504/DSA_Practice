/*
###########################################
Source: Naukri

Problem statement:
You are given an M X N matrix of integers ARR. Your task is to find the maximum sum rectangle.

Maximum sum rectangle is a rectangle with the maximum value for the sum of integers present within its boundary, considering all the rectangles that can be formed from the elements of that matrix.

A rectangle is a 2-D polygon with opposite sides parallel and equal to each other.

For example:
Consider following matrix:

 1  2 -1 -4 -20
-8 -3  4  2   1
 3  8  10 1   3
-4 -1  1  7  -6

The rectangle (1,1) to (3,3) is the rectangle with the maximum sum, i.e. 29.

 1   2 -1 -4  -20
-8 |-3  4  2 |  1
 3 | 8  10 1 |  3
-4 |-1  1  7 | -6

Constraints:
1 <= T <= 10
1 <= M, N <= 100
-10^5 <= ARR[i] <=10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution {
public:

        int maximumSubarraySum(std::vector<int> arr) {
        int ans = -1e9, sum = 0, mn = 0;

        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            ans = max(ans, sum - mn);
            mn = min(mn, sum);
        }

        return ans;
    }

    int maxSumRectangle(std::vector<std::vector<int>> arr)
    {
        int ans = 0, n = arr.size(), m = arr[0].size();

        for (int j = 0; j < m; ++j) {
            std::vector<int> prefix(n);
            for (int j1 = j; j1 < m; ++j1) {
                for (int i = 0; i < n; ++i) {
                    prefix[i] += arr[i][j1];
                }

                ans = max(ans, maximumSubarraySum(prefix));
            }
        }

        return ans;
    }
};

int main() {
	std::vector<std::vector<int> > mat = {
        {-45,  93, -12,  67,  29, -99,  83,  45, -72,  10,  55, -88},
        { 79, -66,  40, -15,  76,  21, -38,  69, -56,  85, -13,  92},
        {-31,  64, -84,  48, -21,  77, -19,  50, -23,  34,  62, -80},
        { 28, -77,  11,  95, -68,  43, -90,  22,  71, -50,  39,  87},
        {-60,  53, -92,  16,  81, -37,  14,  96, -55,  42, -75,  63},
        { 72, -28,  88, -49,  31,  58, -97,  24,  79, -66,  47, -36},
        {-85,  99, -44,  19,  61, -72,  32,  76, -93,  27,  83, -11},
        { 54, -39,  22, -81,  43,  91, -25,  68, -58,  12,  35, -98},
        {-10,  87, -74,  29,  95, -46,  37,  66, -89,  20,  58, -21},
        { 83, -33,  50, -79,  18,  74, -63,  41, -92,  55, -14,  72}
    };

    Solution obj;

    std::cout << obj.maxSumRectangle(mat);
}