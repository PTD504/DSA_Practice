/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Constraints:
1 <= n, m <= 10^5
0 <= arr1i, arr2i <= 10^7

Solution: PTD504
###########################################
*/

#include <iostream>
#include <algorithm>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            for (int i = n - 1, j = 0; i >= 0 && j < m; --i, ++j){
                if (arr1[i] > arr2[j])
                    std::swap(arr1[i], arr2[j]);
                else
                    break;
            }
            std::sort(arr1, arr1 + n);
            std::sort(arr2, arr2 + m);
        } 
};

int main() {
	int n = 50, m = 30;
    long long arr1[] = {8, 9, 11, 12, 12, 15, 17, 18, 20, 20, 21, 24, 24, 26, 27, 27, 28, 30, 34, 37, 38, 40, 40, 43, 45, 45, 56, 56, 59, 60, 65, 65, 68, 69, 70, 75, 75, 78, 78, 79, 84, 85, 90, 91, 92, 92, 94, 96, 100, 100};
    long long arr2[] = {7, 14, 19, 22, 23, 24, 26, 28, 30, 30, 32, 34, 35, 37, 42, 42, 47, 49, 49, 53, 54, 54, 55, 58, 65, 78, 80, 84, 87, 94};

    Solution obj;
    obj.merge(arr1, arr2, n, m);

    for (int i = 0; i < n; ++i) std::cout << arr1[i] << " \n"[i == n - 1];
    for (int i = 0; i < m; ++i) std::cout << arr2[i] << " \n"[i == m - 1];
}