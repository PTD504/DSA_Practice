/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array arr of size N and an element k. The task is to find the count of elements in the array that appear more than n/k times.

Constraints:
1 <= N <= 10^5
0 <= a[i] <= 10^9
1 <= k <= N

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <unordered_map>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        
        std::unordered_map<int, int> mp;
        
        int fre = n / k;
        
        for (int i = 0; i < n; ++i)
            mp[arr[i]]++;
        int ans = 0;
        
        for (auto i : mp)
            if (i.second > fre)
                ans++;
                
        return ans;
    }
};

int main() {
    int n = 100, k = 15;
	int arr[] = {15, 11, 3, 8, 14, 13, 9, 13, 12, 14, 8, 4, 7, 12, 12, 7, 14, 1, 9, 11, 6, 13, 10, 7, 14, 3, 11, 10, 9, 15, 8, 7, 6, 5, 3, 6, 7, 12, 1, 9, 4, 3, 5, 5, 12, 7, 1, 12, 15, 4, 5, 1, 4, 13, 8, 9, 9, 5, 6, 1, 14, 8, 1, 6, 6, 7, 10, 11, 12, 13, 6, 11, 5, 14, 2, 4, 9, 4, 10, 14, 1, 1, 2, 13, 7, 10, 4, 12, 3, 14, 14, 10, 7, 10, 8, 10, 11, 11, 6, 5};

	Solution obj;
	std::cout << obj.countOccurence(arr, n, k);
}