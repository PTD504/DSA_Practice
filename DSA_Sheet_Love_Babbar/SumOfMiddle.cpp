/*
###########################################
Source: GeeksforGeeks

Problem statement:


Constraints:
1 <= N <= 10^3
1 <= Arr1[i], Arr2[j] <= 10^6

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

class Solution {
public:
    
    int findMidSum(int Ar1[], int Ar2[], int n) {
        int l = -1e9, h = 1e9, pos = n, ans = 0;

        while (l <= h) {
            int m = l + ((h - l) >> 1);

            int ub = std::upper_bound(Ar1, Ar1 + n, m) - Ar1 + std::upper_bound(Ar2, Ar2 + n, m) - Ar2;

            if (ub <= pos) l = m + 1;
            else h = m - 1;
        }

        ans = l;

        pos--;
        l = -1e9, h = 1e9;

        while (l <= h) {
            int m = l + ((h - l) >> 1);
            int ub = std::upper_bound(Ar1, Ar1 + n, m) - Ar1 + std::upper_bound(Ar2, Ar2 + n, m) - Ar2;

            if (ub <= pos) l = m + 1;
            else h = m - 1;
        }

        ans += l;

        return ans;
    }
    
};

int main() {
    int n = 50;
    int Ar1[] = {3, 6, 10, 14, 15, 22, 26, 35, 36, 36, 38, 39, 39, 40, 41, 45, 45, 45, 46, 46, 47, 48, 49, 50, 52, 57, 60, 65, 71, 75, 77, 77, 78, 80, 81, 82, 83, 84, 86, 90, 90, 91, 91, 94, 97, 97, 99, 100, 100};
    int Ar2[] = {12, 13, 13, 13, 13, 14, 14, 14, 16, 16, 19, 19, 25, 25, 25, 27, 30, 32, 33, 33, 39, 39, 42, 42, 46, 48, 50, 50, 57, 57, 61, 61, 64, 65, 77, 77, 77, 77, 79, 80, 80, 80, 81, 82, 87, 89, 93, 95, 97};

    Solution obj;
    std::cout << obj.findMidSum(Ar1, Ar2, n);
}