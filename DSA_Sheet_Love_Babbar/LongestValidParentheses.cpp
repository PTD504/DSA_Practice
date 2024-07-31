/*
###########################################
Source: Naukri

Problem statement:
You are given a string 'STR' consisting only of opening and closing parenthesis i.e. '(' and ')', your task is to find out the length of the longest valid parentheses substring.

Note:
The length of the smallest valid substring '()' is 2.
For example:
'STR' = “()()())” here we can see that except the last parentheses all the brackets are making a valid parenthesis. Therefore, the answer for this will be 6.

Constraints:
1 <= T <= 5
1 <= |STR| <= 3000

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int longestValidParentheses(std::string str)
{
    int n = str.size(), ans = 0;
    std::vector<int> dp(n);

    for (int i = 1; i < n; ++i) {
        if (str[i] == '(') {
            dp[i] = (str[i - 1] == ')' ? dp[i - 1] : 0);
        }
        else {
            int idx = i - dp[i - 1] - 1;
            
            if (idx >= 0 and str[idx] == '(') {
                dp[i] = dp[i - 1] + 2 + dp[idx];
            }
            else dp[i] = 0;
        }

        ans = max(ans, dp[i]);
    }
    
    return ans;
}

int main() {
	std::string str = "()())())()))((((((()))))()()()()(((())()((()))))))))()())))))";

    std::cout << longestValidParentheses(str);
}