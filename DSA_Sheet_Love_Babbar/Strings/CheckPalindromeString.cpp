/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a string S, check if it is palindrome or not.

Constraints:
1 <= Length of S<= 2*10^5

Solution: PTD504
###########################################
*/

#include <iostream>

class Solution{
public:	
	
	
	int isPalindrome(std::string S)
	{
	    int l = 0, h = S.size() - 1;

		while (l < h) {
			if (S[l] != S[h]) return 0;
			l++, h--;
		}

		return 1;
	}

};

int main() {
	std::string s = "phanthanhDanggnaDhnahtnahp";
	
	Solution obj;
	
	if (obj.isPalindrome(s)) 
		std::cout << s << " is a palindrome";
	else
		std::cout << s << " is not a palindrome";
}