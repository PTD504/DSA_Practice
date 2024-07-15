/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Constraints:
1 <= N <= 10^5
0 <= a[i] <= 10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

#define max(a, b) (a > b ? a : b)

class Solution{
public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int ans = 0;
        int t = -1, Max = 0;

        for (int i = 0; i < N; ++i) t = max(t, arr[i]);

        std::vector<int> a(t + 1, 0);

        for (int i = 0; i < N; ++i)
            a[arr[i]] = 1;
        for (int i = 0; i <= t; ++i){
            if (a[i])
                ans++, Max = max(Max, ans);
            else
                ans = 0;
        }
        return Max;
    }
};

int main() {
	int N = 30;
    int arr[] = {4, 14, 13, 15, 1, 15, 6, 12, 1, 13, 6, 9, 11, 7, 8, 12, 12, 3, 14, 7, 15, 15, 3, 12, 5, 5, 7, 9, 10, 1};

    Solution obj;

    std::cout << obj.findLongestConseqSubseq(arr, N);
}