/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an unsorted array arr of size n of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer (The first index contains B and second index contains A)

Constraints:
2 ≤ n ≤ 10^5
1 ≤ arr[i] ≤ n

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

class Solution{
public:
    std::vector<int> findTwoElement(std::vector<int> arr, int n) {
        int repeat = 0, miss = 0;
        long long sum_n = 1ll * n * (n + 1) / 2;
        long long sum_arr = 0;
        
        for (int i = 0; i < n; ++i) {
            sum_arr += abs(arr[i]);

            if (!repeat) {
                if (arr[abs(arr[i]) - 1] > 0) arr[abs(arr[i]) - 1] = - arr[abs(arr[i]) - 1];
                else repeat = abs(arr[i]);
            }
        }
        miss = sum_n - (sum_arr - repeat);

        return {repeat, miss};
    }
};

int main() {
    int n = 20;
    std::vector<int> arr = {12, 15, 6, 10, 14, 4, 9, 5, 1, 11, 19, 20, 7, 11, 17, 16, 13, 18, 2, 3};

    Solution obj;

    for (auto i : obj.findTwoElement(arr, n)) std::cout << i << ' ';
}