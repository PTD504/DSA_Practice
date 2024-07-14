/*Problem statement: (GeeksforGeeks)
Given two strings str1 & str 2 of length n & m respectively, return the length of their longest common subsequence. If there is no common subsequence then, return 0. 

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "abe" is a subsequence of "abcde".

Constraint:
1<= n, m <=10^3
str1 and str2 are in uppercase alphabet
*/

#include <iostream>
#include <vector>

#define max(a, b) (a > b ? a : b)

void reverse(std::string& str) {
	int l = 0, h = str.size() - 1;

	while (l < h) std::swap(str[l++], str[h--]);
}

std::string longestCommonSubsequence(const std::string& A, const std::string& B) {
	std::vector<std::vector<int> > dp(A.size(), std::vector<int> (B.size(), 0));
	dp[0][0] = (A[0] == B[0]);

	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < B.size(); ++j) {
			if (i == 0 and j == 0) dp[i][j] = (A[0] == B[0]);
			else if (i == 0) dp[i][j] = max(dp[i][j - 1], (A[0] == B[j]));
			else if (j == 0) dp[i][j] = max(dp[i - 1][j], (A[i] == B[0]));
			else if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int mxLength = dp[A.size() - 1][B.size() - 1];
	std::string lcs = "";

	std::cout << mxLength << '\n';

	// Trace the solution
	int i = A.size() - 1, j = B.size() - 1;
	while (i >= 0 and j >= 0 and mxLength) {
		if (A[i] == B[j] and dp[i][j] == mxLength) {
			lcs += A[i];
			i--, j--;
			mxLength--;
		}
		else if (i == 0) j--;
		else if (j == 0) i--;
		else if (dp[i - 1][j] < dp[i][j - 1]) j--;
		else i--;
	}

	reverse(lcs);

	return lcs;
}

int main() {
	std::string A = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
	std::string B = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";

	std::cout << longestCommonSubsequence(A, B);
}