/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array of integers. Find the Inversion Count in the array.  Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum.

Constraints:
1 ≤ n ≤ 5*10^5
1 ≤ arr[i] ≤ 10^18

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

using ll = long long;

class Solution {
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll ans = 0;

    void merge(ll arr[], int l, int m, int h) {
        std::vector<ll> temp;
        int i = l, j = m + 1;

        while (i <= m and j <= h) {
            if (arr[i] > arr[j]) {
                ans += 1ll * (m - i + 1);
                temp.push_back(arr[j++]);
            }
            else 
                temp.push_back(arr[i++]);
        }

        while (i <= m) temp.push_back(arr[i++]);
        while (j <= h) temp.push_back(arr[j++]);

        for (int i = l; i <= h; ++i) arr[i] = temp[i - l];
    }

    void MergeSort(ll arr[], int l, int h) {
        if (l >= h) return;

        int m = l + ((h - l) >> 1);

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
    }

    long long inversionCount(long long arr[], int n) {
        MergeSort(arr, 0, n - 1);

        return ans;
    }
};

int main() {
    int N = 20;
	ll arr[] = {3, 1, 12, 5, 18, 10, 15, 7, 19, 6, 13, 20, 11, 16, 2, 9, 4, 17, 8, 14};

    Solution obj;

    std::cout << obj.inversionCount(arr, N);
}