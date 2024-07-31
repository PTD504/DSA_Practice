/*
###########################################
Source: Naukri

Problem statement:
Given a 2-dimensional matrix of size ‘N’ x ‘M’. Find the size of the largest sub-matrix whose sum is equal to 0. The size of a matrix is the product of rows and columns in it.

A sub-matrix is a matrix obtained from the given matrix by deletion of several (possibly, zero or all) rows/columns from the beginning and several (possibly, zero or all) rows/columns from the end.
If there is no sub-matrix with sum equal to 0, then return 0.

Constraints:
1 <= T <= 10
1 <= N, M <= 50
-10^5 <= data <= 10^5,

Where ‘data’ is the value of the elements of the matrix.

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <unordered_map>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution {
public:

    int longestSubarrayWithZeroSum(std::vector<int> arr) {
		int ans = 0, sum = 0;
		std::unordered_map<int, int> mp;
		mp[0] = -1;

		for (int i = 0; i < arr.size(); ++i) {
			sum += arr[i];

			if (mp.find(sum) != mp.end()) ans = max(ans, i - mp[sum]);
			else mp[sum] = i;
		}

		return ans;
	}

	int largestSubmatrixWithSumZero(std::vector<std::vector<int>> &mat, int n, int m)
	{
		int ans = 0;

		for (int j = 0; j < m; ++j) {
			std::vector<int> prefix(n);
			for (int j1 = j; j1 < m; ++j1) {
				for (int i = 0; i < n; ++i) {
					prefix[i] += mat[i][j1];
				}

				int mxLength = longestSubarrayWithZeroSum(prefix);

				ans = max(ans, mxLength * (j1 - j + 1));
			}
		}

		return ans;
	}
};

int main() {
	int n = 10, m = 12;
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

    std::cout << obj.largestSubmatrixWithSumZero(mat, n, m);
}