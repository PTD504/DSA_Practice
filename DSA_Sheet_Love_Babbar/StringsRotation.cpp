/*
###########################################
Source: GeeksforGeeks

Problem statement:
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Constraints:
1 <= |s1|, |s2| <= 10^5

Solution: PTD504
###########################################
*/

#include <iostream>

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(std::string s1, std::string s2)
    {
        int n = (int)s1.size();
        int i = 0, j = 0;
        
        if (s1 == s2)
            return 1;
        
        for (; i < n; ++i) {
            int t = i;
            j = 0;
            while (t < n and s1[t] == s2[j]) {
                t++, j++;
            }
            if (t == n)
                break;
            else
                j = -1;
        }
        
        if (j == -1)
            return false;
        else
            return s1.substr(0, n - j) == s2.substr(j, n - j);
    }
};

int main() {
	std::string s1 = "akjdhksajhdjhaskjdhsadas";
    std::string s2 = "haskjdhsadaxakjdhksajhdj";

    Solution obj;

    if (obj.areRotations(s1, s2)) 
        std::cout << s2 << " is a rotated version of " << s1;
    else   
        std::cout << s2 << " is not a rotated version of " << s1;
}