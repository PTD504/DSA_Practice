/*
###########################################
Source: GeeksforGeeks

Problem statement:
Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.

Constraints:
1 <= N <= 10^8

Solution: PTD504
###########################################
*/

#include <iostream>

class Solution {
public:
    int countSquares(int N) {
        int t = 1;
        while (t * t <= N) t++;
        t--;

        int ans = t;
        if (t * t == N)
            ans--;
        return ans;
    }
};

int main() {
    int N = 1232423;
    
    Solution obj;

    std::cout << obj.countSquares(N);
}