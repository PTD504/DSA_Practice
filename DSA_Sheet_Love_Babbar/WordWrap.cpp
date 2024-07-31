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
#include <vector>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution {
public:

    int recursion(std::vector<int>& nums, std::vector<std::vector<int> >& dp, int numWord, int remainLength, int K) {
        if (numWord == nums.size() - 1) {
            if (remainLength == K) return dp[numWord][remainLength] = 0;
            else if (nums[numWord] < remainLength) return dp[numWord][remainLength] = 0;
            else return dp[numWord][remainLength] = remainLength * remainLength;
        }

        if (dp[numWord][remainLength] + 1) return dp[numWord][remainLength];

        if (nums[numWord] >= remainLength) {
            return dp[numWord][remainLength] = recursion(nums, dp, numWord + 1, K - nums[numWord], K) + remainLength * remainLength;
        }
        else {
            int cost1 = recursion(nums, dp, numWord + 1, remainLength - nums[numWord] - (remainLength != K), K);
            int cost2 = recursion(nums, dp, numWord + 1, K - nums[numWord], K) + remainLength * remainLength;

            return dp[numWord][remainLength] = min(cost1, cost2);
        }
    }    

    int solveWordWrap(std::vector<int>nums, int k) 
    { 
        int n = nums.size();
        std::vector<std::vector<int> > dp(n, std::vector<int> (k + 1, -1));
        
        return recursion(nums, dp, 0, k, k);
    } 
};

int main() {
	std::vector<int> nums = {2, 8, 2, 6, 10, 10};
    int k = 13;

    Solution obj;

    std::cout << obj.solveWordWrap(nums, k);
}