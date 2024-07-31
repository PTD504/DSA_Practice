/*
###########################################
Source: GeeksforGeeks

Problem statement:
You are given a string s. You need to reverse the string.

Constraints:
1 <= |s| <= 10000

Solution: PTD504
###########################################
*/

#include <iostream>

void reverse(std::string& str) {
	int l = 0, h = str.size() - 1;

	while (l < h) std::swap(str[l++], str[h--]);
}

int main() {
	std::string s = "abcdefj";
	reverse(s);
	std::cout << s;
}