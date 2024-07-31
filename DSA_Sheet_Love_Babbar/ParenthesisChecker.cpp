/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

Constraints:
1 ≤ |x| ≤ 32000

Solution: PTD504
###########################################
*/

#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(std::string x)
    {
        std::stack<char> s;

        /*
        '(': 40, ')': 41
        '[': 91, ']': 93
        '{': 123, '}': 125
        */
        
        for (char ch : x) {
            if (ch == '(' or ch == '[' or ch == '{') s.push(ch);
            else if (s.empty()) return false;
            else if (abs(s.top() - ch) > 2) return false;
            else s.pop();
        }

        return s.empty();
    }

};

int main() {
    std::string x = "{({{}}{}{{{}}}[][[[]]])([])({})({}){[()]}{}[(())(())]";

    Solution obj;

    if (obj.ispar(x)) std::cout << "balanced";
    else std::cout << "not balanced";
}