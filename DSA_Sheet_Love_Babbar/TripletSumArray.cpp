/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array arr of size n and an integer x. Find if there's a triplet in the array which sums up to the given integer x.

Constraints:
1 <= n <= 10^3
1 <= arr[i] <= 10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    
    int find3Numbers(int arr[], int n, int x) {
        std::sort(arr, arr + n);

        for (int i = 0; i < n; ++i) {
            int l = i + 1, h = n - 1;

            while (l < h) {
                if (arr[i] + arr[l] + arr[h] == x) return 1;
                else if (arr[i] + arr[l] + arr[h] < x) l++;
                else h--;
            }
        }

        return 0;
    }
    
};

int main() {
    int n = 50;
    int x = 34;
    int arr[] = {4, 10, 24, 22, 12, 17, 29, 26, 24, 24, 13, 4, 27, 18, 12, 10, 18, 10, 21, 23, 28, 20, 8, 8, 5, 29, 19, 13, 4, 20, 21, 30, 16, 9, 24, 27, 17, 9, 13, 16, 3, 12, 24, 5, 18, 22, 17, 4, 27, 17};

    Solution obj;

    std::cout << obj.find3Numbers(arr, n, x);
}