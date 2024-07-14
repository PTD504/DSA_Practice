/*
Problem statement: (GeeksforGeeks)
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

	- Insert a character at any position of the string.
	- Remove any character from the string.
	- Replace any character from the string with any other character.

Constraint:
1<= |s|, |t| <= 10^3
*/

#include <iostream>
#include <cstring>

#define min(a, b) (a < b ? a : b)

const int MAXN = 1e3 + 1;

int editDistance_RecursiveApproach(const std::string& A, const std::string& B, int iA, int iB, int dp[][MAXN]) {
	if (iA == 0) return dp[iA][iB] = iB;
	if (iB == 0) return dp[iA][iB] = iA;
	if (dp[iA][iB] + 1) return dp[iA][iB];

	if (A[iA - 1] == B[iB - 1]) return dp[iA][iB] = editDistance_RecursiveApproach(A, B, iA - 1, iB - 1, dp);
	else {
		int sEdit_A = editDistance_RecursiveApproach(A, B, iA - 1, iB, dp) + 1; // Delete A[iA]
		int sEdit_B = editDistance_RecursiveApproach(A, B, iA, iB - 1, dp) + 1; // Delete B[iB]
		int bEdit = editDistance_RecursiveApproach(A, B, iA - 1, iB - 1, dp) + 1; // Change A[iA] or B[iB] such that A[iA] = B[iB]

		return dp[iA][iB] = min(bEdit, min(sEdit_A, sEdit_B));
	}
}

int editDistance_IterativeApproach(const std::string& A, const std::string& B) {
	int dp[MAXN][MAXN];
	memset(dp, 0, sizeof(dp));
	
	for (int i = 0; i <= A.size(); ++i) {
		for (int j = 0; j <= B.size(); ++j) {
			if (i == 0) dp[i][j] = j;
			else if (j == 0) dp[i][j] = i;
			else if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
		}
	}

	return dp[A.size()][B.size()];
}

int main() {
	std::string A = "bblxnaxvixupiutnpftipsrmeucrytdokhktfdlhxhuqbaohkziqjbzuytnmlgokxepjtbrmwiomnuozvbjwbqirtjvjzkbtvbph";
	std::string B = "wcdqbbvhbnzvwkwjvcuohwbgqmrglpxlibswcpnjwpyhpvamuknvkpgyagsckvivxlytbrkmwkhqeyrsqkjzinnairxgfc";
	
	int dp[MAXN][MAXN];
	memset(dp, -1, sizeof(dp));

	std::cout << editDistance_RecursiveApproach(A, B, A.size(), B.size(), dp) << '\n' << \
	editDistance_IterativeApproach(A, B);
}