/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Constraints:
1 ≤ |s| ≤ 10^5
s contains lower case English alphabets

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution{
public:		
	int lps(std::string s) {
		int n = s.size();
		int Lps[n];

		buildLPSArray(s, Lps);

		int ans = 0;

		for (int i = 0; i < n; ++i) 
			ans = max(ans, min(Lps[i], Lps[n - 1]));

		return ans;
	}

	void buildLPSArray(std::string s, int lps[]) {
		int n = s.size();
	    int i = 1, j = 0;
		lps[0] = 0;

		while (i < n) {
			while (j > 0 and s[i] != s[j]) j = lps[j - 1];

			if (s[j] == s[i]) lps[i++] = ++j;
			else if (j == 0) lps[i++] = 0;
			else j = lps[j - 1];
		} 
	}
};

int main() {
	std::string s = "acccbaaacccbaac";

	Solution obj;

	std::cout << obj.lps(s);
}