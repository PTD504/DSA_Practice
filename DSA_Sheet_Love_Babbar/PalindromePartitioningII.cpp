/*
###########################################
Source: Naukri

Problem statement:
Ninja contains a string 'STR'. He has to partition the string 'STR' into a minimum number of partitions such that each partition is a palindrome.

Ninja is stuck and needs your help. Your task is to print the minimum number of cuts required such that each partition of the string 'STR' is a palindrome.

For example:

For the string “abc”, we can create 2 partitions and get 3 palindromic strings "a", "b" and "c". 

For the string “abbcb”, we can create 2 partitions and get 3 palindrome strings "a", "b" and "bcb".

Constraints:
1 <=  | STR | <= 200
STR contains lowercase English alphabets only.

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <cstring>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution {
public:

	int minimumCuts(std::string str) {
		int n = str.size();
		bool isPalindrome[n][n];
		int dp[n];
		dp[0] = 0;

		memset(isPalindrome, 0, sizeof(isPalindrome));	

		for (int i = 1; i < n; ++i) {
			for (int j = i; j >= 0; --j) {
				if (i == j) isPalindrome[i][j] = 1;
				else if (i == j + 1) isPalindrome[i][j] = str[i] == str[j];
				else isPalindrome[i][j] = str[i] == str[j] and isPalindrome[i - 1][j + 1];
			}
		}

		for (int i = 1; i < n; ++i) {
			int j = 0;
			dp[i] = i;

			if (isPalindrome[i][0]) {
				dp[i] = 0;
				continue;
			}

			while (j < i) {
				if (isPalindrome[i][j + 1]) {
					dp[i] = min(dp[j] + 1, dp[i]);
				}
				j++;
			}
		}

		return dp[n - 1];
	}
};

int main() {
	std::string str = "abdbsbsbabababababsbsbsbdbwbwbwbrgsgsgsgfarqrfssfssfsfsfsf";

    Solution obj;

    std::cout << obj.minimumCuts(str);
}