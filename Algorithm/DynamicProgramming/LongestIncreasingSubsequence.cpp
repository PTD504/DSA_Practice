/*
Problem statement: (GeeksforGeeks)
Given an array a[ ] of n integers, find the Length of the Longest Strictly Increasing Subsequence.

A sequence of numbers is called "strictly increasing" when each term in the sequence is smaller than the term that comes after it.

Constraint:
1 <= n <= 2 * 10^5
1 <= a[i] <= 10^9, 0 <= i < n
*/

#include <iostream>
#include <vector>

#define max(a, b) (a > b ? a : b)

const int MAXVAL = 2e9;

int upper_bound(const std::vector<int>& arr, int key) {
	int l = 0, h = arr.size() - 1, ans = arr.size();

	while (l <= h) {
		int m = l + ((h - l) >> 1);

		if (arr[m] <= key) l = m + 1;
		else ans = m, h = m - 1;
	}

	return ans;
}

template <typename T>
void reverse(std::vector<T>& arr) {
	int l = 0, h = arr.size() - 1;

	while (l < h) std::swap(arr[l++], arr[h--]);
}

std::vector<int> longestIncreasingSubsequence_NSquare(std::vector<int> arr) {
	int mxl = 1;
	std::vector<int> dp(arr.size());
	dp[0] = 1;

	for (int i = 1, mxLength = 0; i < arr.size(); ++i, mxLength = 0) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i] and dp[j] > mxLength) mxLength = dp[j];
		}

		dp[i] = 1 + mxLength;
		mxl = max(mxl, dp[i]);
	}

	// Trace the solution
	std::vector<int> lis;

	for (int i = arr.size() - 1, mx = MAXVAL; i >= 0 and mxl; --i) {
		if (dp[i] == mxl and arr[i] < mx) {
			lis.push_back(arr[i]);
			mx = arr[i];
			mxl--;
		} 
	}
	
	reverse(lis);

	return lis;
}

std::vector<int> longestIncreasingSubsequence_NLogN(std::vector<int> arr) {
	std::vector<int> ends(arr.size() + 1, MAXVAL);
	std::vector<int> index(arr.size() + 1, -1);
	std::vector<int> prev(arr.size(), -1);
	ends[0] = -MAXVAL;

	for (int i = 0; i < arr.size(); ++i) {
		int length = upper_bound(ends, arr[i]);
		if (ends[length - 1] < arr[i] and arr[i] < ends[length]) {
			ends[length] = arr[i]; 
			index[length] = i;
			prev[i] = index[length -  1];
		}
	}

	int mxl;

	for (mxl = arr.size(); mxl > 0; --mxl) {
		if (ends[mxl] < MAXVAL) break;
	}

	// Trace the solution
	std::vector<int> lis;
	for (int l = index[mxl]; l != -1; l = prev[l]) {
		lis.push_back(arr[l]);
	}

	reverse(lis);

	return lis;
}

int main() {
	std::vector<int> arr = {80, 59, 85, 93, 77, 38, 74, 18, 49, 31, 54, 26, 2, 69, 57, 67, 41, 43, 25, 56, 89, 66, 22, 57, 54, 78, 12, 82, 92, 6};

	for (auto v : longestIncreasingSubsequence_NSquare(arr)) std::cout << v << ' ';
	std::cout << '\n';
	for (auto v : longestIncreasingSubsequence_NLogN(arr)) std::cout << v << ' ';
}