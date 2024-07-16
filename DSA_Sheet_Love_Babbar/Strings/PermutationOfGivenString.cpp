/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order. 

Constraints:
1 <= length of string <= 5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define max(a, b) (a > b ? a : b)

class Solution
{
	public:
		std::vector<std::string> find_permutation(std::string S)
		{
		    std::sort(S.begin(), S.end());
		    std::vector<std::string> ans;
		    do{
		        ans.push_back(S);
		    }
		    while(next_permutation(S.begin(), S.end()));
		    return ans;
		}
};

int main() {
	std::string S = "abght";

	Solution obj;

	for (auto str : obj.find_permutation(S)) std::cout << str << '\n';
}