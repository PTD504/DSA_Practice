/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m, where both arrays may contain duplicate elements. The task is to determine whether array a2 is a subset of array a1. It's important to note that both arrays can be sorted or unsorted. Additionally, each occurrence of a duplicate element within an array is considered as a separate element of the set.

Constraints:
1 <= n, m <= 10^5
1 <= a1[i], a2[j] <= 10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    
    std::string isSubset(int a1[], int a2[], int n, int m) {
        std::unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i) mp[a1[i]]++;

        for (int i = 0; i < m; ++i) {
            mp[a2[i]]--;
            if (mp[a2[i]] < 0) return "No";
        }

        return "Yes";
    }
    
};

int main() {
    int n = 50;
	int a1[] = {23, 2, 3, 11, 1, 25, 6, 7, 28, 1, 30, 4, 20, 13, 21, 14, 16, 20, 20, 1, 29, 9, 23, 23, 21, 10, 21, 28, 12, 14, 17, 26, 22, 10, 20, 21, 24, 26, 19, 24, 23, 3, 16, 7, 4, 3, 5, 30, 18, 7};
    int m = 20;
    int a2[] = {14, 12, 7, 12, 14, 25, 26, 18, 17, 3, 19, 10, 8, 1, 1, 18, 16, 18, 9, 23};

    Solution obj;

    std::cout << obj.isSubset(a1, a2, n, m);
}