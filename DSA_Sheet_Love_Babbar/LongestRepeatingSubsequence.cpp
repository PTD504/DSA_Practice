/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

Constraints:
1 <= |str| <= 10^3

Solution: PTD504
###########################################
*/

#include <iostream>
#include <cstring>

#define max(a, b) (a > b ? a : b)

class Solution {
public:
	int LongestRepeatingSubsequence(std::string str){
		int n = str.size();
		int dp[n + 10][n + 10];
		memset(dp, 0, sizeof(dp));
		    
		for (int i = 1; i <= n; ++i){
		    for (int j = 1; j <= n; ++j){
		        if (str[j - 1] == str[i - 1] && i != j)
		            dp[i][j] = dp[i - 1][j - 1] + 1;
		        else{
		            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		        }
		    }
		}
		return dp[n][n];
	}
};

int main() {
	std::string s = "sadhkjsahdkjashdkjsahasdjhsadkjhsajdhjas";

	Solution obj;

	std::cout << obj.LongestRepeatingSubsequence(s);
}