/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221
Look-and-Say Pattern:

To generate a member of the sequence from the previous member, read off the digits of the previous member, counting the number of digits in groups of the same digit. For example:

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
1211 is read off as "one 1, one 2, then two 1s" or 111221.
111221 is read off as "three 1s, two 2s, then one 1" or 312211.

Constraints:
1 ≤ n ≤ 30

Solution: PTD504
###########################################
*/

#include <iostream>

class Solution
{
    public:
    
    std::string lookandsay(int n)
    {
        if (n == 1) return "1";
        if (n == 2) return "11";

        std::string prev = "11"; 

        for (int i = 3; i <= n; ++i)
        {
            prev += '$';
            int len = prev.size(), cnt = 1;
            std::string tmp = "";

            for (int j = 1; j < len; ++j)
            {
                if (prev[j] != prev[j - 1])
                {
                    tmp += cnt + '0';

                    tmp += prev[j - 1];

                    cnt = 1;
                }
                else cnt++;
            }

            prev = tmp;
        }

        return prev;
    }
};

int main() {
	int n = 20;

    Solution obj;

    std::cout << obj.lookandsay(n);
}