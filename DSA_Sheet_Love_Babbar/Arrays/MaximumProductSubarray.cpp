/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array arr[] that contains n integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Note: It is guarenteed that the output fits in 64-bit integer.

Constraints:
1 ≤ n ≤ 500
-10^2 ≤ arr[i] ≤ 10^2

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(std::vector<int> arr, int n) {
	    long long ans = arr[0];
		long long mxProd = arr[0], mnProd = arr[0];

		for (int i = 1; i < n; ++i) {
			if (arr[i] < 0) {
				mxProd ^= mnProd;
				mnProd ^= mxProd;
				mxProd ^= mnProd;
			}

			mxProd = max(arr[i], mxProd * arr[i]);
			mnProd = min(arr[i], mnProd * arr[i]);

			ans = max(ans, mxProd);
		}

		return ans;
	}
};

int main() {
    int n = 45;
	std::vector<int> arr = {-32, -23, 56, -61, 67, 1, -71, 49, -78, 0, 98, 46, 32, 12, -44, 25, 49, -34, 0, -19, 10, -21, -15, 14, -92, 0, -46, 48, 20, -42, -22, -51, -57, 51, 66, 0, -72, 15, -87, 97, 51, -1, -25, -88, 43};

	Solution obj;
	std::cout << obj.maxProduct(arr, n);
}