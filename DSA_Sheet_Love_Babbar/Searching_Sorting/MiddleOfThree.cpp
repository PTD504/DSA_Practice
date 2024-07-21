/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).

Constraints:
1<=A,B,C<=10^9
A,B,C are distinct.

Solution: PTD504
###########################################
*/

#include <iostream>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

class Solution{
public:
    int middle(int A, int B, int C){
        int mn1 = min(A, B), mn2 = min(B, C);
        
        return mn1 != mn2 ? max(mn1, mn2) : min(A, C);
    }
};

int main() {
    int A = 123, B = 900, C = 765;

    Solution obj;

    std::cout << obj.middle(A, B, C);
}