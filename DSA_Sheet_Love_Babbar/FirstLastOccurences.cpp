/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a sorted array arr containing n elements with possibly some duplicate, the task is to find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.

Constraints:
1 ≤ N ≤ 10^6
1 ≤ arr[i],x ≤ 10^9

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
    public:
    std::vector<int> find(int arr[], int n , int x )
    {
        int f = std::lower_bound(arr, arr + n, x) - arr;
        int s = std::upper_bound(arr, arr + n, x) - arr - 1;

        if (f == n or arr[f] != x) return {-1, -1};
        else return {f, s};
    }
};

int main() {
    int n = 39;
    int arr[] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 9, 9, 9, 10, 12, 14, 14, 15, 15, 16, 18, 18, 18, 18, 19, 19, 20, 20};
    int x = 18;
    Solution obj;
    
    for (auto i : obj.find(arr, n, x)) std::cout << i << ' ';
}