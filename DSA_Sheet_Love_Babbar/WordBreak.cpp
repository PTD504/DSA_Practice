/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a string s and a dictionary of n words dictionary, find out if "s" can be segmented into a space-separated sequence of dictionary words.
Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0. 

Note: From the dictionary dictionary each word can be taken any number of times and in any order.

Constraints:
1 ≤ n ≤ 12
1 ≤ len(s) ≤ 1100

Solution: PTD504
###########################################
*/

#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution {
public:
    int wordBreak(int n, std::string s, std::vector<std::string>& dictionary) {
        int sz = s.size();
        std::vector<bool> dp(sz + 1, false); 
        dp[0] = true;  

        for (int i = 0; i <= sz; ++i) {
            if (!dp[i]) continue;
            for (const std::string& word : dictionary) {
                int word_length = word.size();
                if (i + word_length <= sz and s.substr(i, word_length) == word) {
                    dp[i + word_length] = true;
                }
            }
        }

        return dp[sz];
    }
};

int main() {
    int n = 6;
    std::vector<std::string> dictionary = {"Phan", "Thanh", "Dang", "Thua Thien", "Hue", "UIT"};
    std::string s = "PhanThanhDangUITDangHueThua Thien";

    Solution obj;

    std::cout << obj.wordBreak(n, s, dictionary);
}