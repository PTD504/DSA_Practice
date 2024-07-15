/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.

Constraints:
1 <= n <= 10^6
1 <= arr[i] <= 10^7

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
        int mnIdx = 0, mxIdx = n - 1;
        int mx = arr[n - 1] + 1;

        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                arr[i] += (arr[mnIdx] % mx) * mx;
                mnIdx ++;
            }
            else {
                arr[i] += (arr[mxIdx] % mx) * mx;
                mxIdx--;
            }
        }

        for (int i = 0; i < n; ++i) arr[i] /= mx;
    }
};

int main() {
    int n = 30;
	long long arr[] = {1, 3, 6, 7, 8, 9, 9, 11, 12, 15, 16, 18, 19, 20, 23, 24, 25, 25, 26, 30, 31, 32, 33, 33, 38, 38, 42, 42, 43, 44, 45, 46, 47, 48, 48, 49};

    Solution obj;
    obj.rearrange(arr, n);

    for (int i = 0; i < n; ++i) std::cout << arr[i] << ' ';
}