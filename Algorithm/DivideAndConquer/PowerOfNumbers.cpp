/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a number and its reverse. Find that number raised to the power of its own reverse.
Note: As answers can be very large, print the result modulo (10^9 + 7).

Constraints:
1 <= N <= 10^9

Solution: PTD504
###########################################
*/

#include <iostream>

const int MOD = 1e9 + 7;

class Solution{
    public:
    //You need to complete this fucntion
    using ll = long long;
    
    long long power(int N,int R)
    {
        ll z = 1;

        while (R) {
            if (R & 1) z = z * N % MOD;
            N = 1ll * N * N % MOD;
            R >>= 1;
        }

        return z;
    }

};


int main() {
    int N = 1234567;
    int R = 7654321;

    Solution obj;

    std::cout << obj.power(N, R);
}