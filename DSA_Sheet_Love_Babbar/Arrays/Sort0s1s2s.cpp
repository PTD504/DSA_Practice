/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2

Solution: PTD504
###########################################
*/

#include <iostream>
#include <algorithm>

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int two = 0, zero = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) zero++;
            else if (a[i] == 2) two++;
        }

        int i = 0, j = n - 1;

        while (zero--) a[i++] = 0;
        while (two--) a[j--] = 2;

        for (; i <= j; ++i) a[i] = 1;
    }
    
};

int main() {
	int n = 20;
    int a[] = {2, 0, 2, 2, 1, 2, 1, 2, 2, 0, 0, 0, 2, 0, 0, 0, 2, 1, 2, 0};

    Solution obj;

    obj.sort012(a, n);

    for (int i = 0; i < n; ++i) std::cout << a[i] << ' ';
}