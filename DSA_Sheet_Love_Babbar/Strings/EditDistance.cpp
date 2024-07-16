/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one. 

You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)^2.

Constraints:
1 ≤ n ≤ 500
1 ≤ nums[i] ≤ 1000
max(nums[i]) ≤ k ≤ 2000

Solution: PTD504
###########################################
*/

#include <iostream>
#include <cstring>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

const int MAXN = 101;

class Solution {
public:
  
    int recursion(const std::string& A, const std::string& B, int iA, int iB, int dp[][MAXN]) {
    	if (iA == 0) return dp[iA][iB] = iB;
    	if (iB == 0) return dp[iA][iB] = iA;
    	if (dp[iA][iB] + 1) return dp[iA][iB];
    
    	if (A[iA - 1] == B[iB - 1]) return dp[iA][iB] = recursion(A, B, iA - 1, iB - 1, dp);
    	else {
    		int sEdit_A = recursion(A, B, iA - 1, iB, dp) + 1;
    		int sEdit_B = recursion(A, B, iA, iB - 1, dp) + 1;
    		int bEdit = recursion(A, B, iA - 1, iB - 1, dp) + 1;
    
    		return dp[iA][iB] = min(bEdit, min(sEdit_A, sEdit_B));
    	}
    }  
  
    int editDistance(std::string s, std::string t) {
        int dp[MAXN][MAXN];
        memset(dp, -1, sizeof(dp));
        int m = s.size(), n = t.size();
        
        return recursion(s, t, m, n, dp);
    }
};

int main() {
	std::string s = "asdkjsadkjkasldjlas";
    std::string t = "qwoieunsahdsahdad";

    Solution obj;
    
    std::cout << obj.editDistance(s, t);
}