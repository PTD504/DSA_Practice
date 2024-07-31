/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.

Constraints:
1 <= N <= 10^5
1 <= Arr[i], K <= 10 ^ 7

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

#define min(a, b) (a < b ? a : b)

class Solution {
public:
    
    int minSwap(int arr[], int n, int k) {
        int less = 0, lar = 0;

        for (int i = 0; i < n; ++i) {
            if (arr[i] <= k) less++;
        }

        for (int i = 0; i < less; ++i) {
            if (arr[i] > k) lar++;
        }

        int ans = lar, j = 0;

        for (int i = less; i < n; ++i) {
            if (arr[j] > k) lar--;
            if (arr[i] > k) lar++;

            ans = min(ans, lar);
            j++;
        }

        return ans;
    }
    
};

int main() {
    int n = 36, k = 27;
    int arr[] = {27, 18, 33, 11, 31, 15, 5, 45, 41, 8, 37, 44, 17, 19, 50, 3, 18, 30, 23, 27, 18, 13, 40, 46, 38, 15, 22, 32, 31, 37, 15, 8, 37, 11, 30, 44};

    Solution obj;
    std::cout << obj.minSwap(arr, n, k);
}