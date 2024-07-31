/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

Constraints:
1 <= T <= 100
1 <= N <= 10^5
1 <= A[i] <= 10^9
1 <= M <= N

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define min(a, b) (a < b ? a : b)

class Solution {
public:
    using ll = long long;

    long long findMinDiff(std::vector<long long> a, long long n, long long m) {
        std::sort(a.begin(), a.end());

        ll ans = 1e9 + 1;

        m--;
        if (m == 0) return 0ll;

        for (int i = 0; i + m < n; ++i) {
            ans = min(ans, a[i + m] - a[i]);
        }

        return ans;
    }
    
};

int main() {
    long long n = 30;
    long long m = 16;
    std::vector<long long> a = {59, 82, 29, 98, 69, 77, 25, 51, 21, 25, 32, 59, 13, 45, 64, 63, 70, 8, 37, 4, 80, 85, 44, 30, 96, 23, 57, 30, 44, 3};

    Solution obj;
    std::cout << obj.findMinDiff(a, n, m);
}