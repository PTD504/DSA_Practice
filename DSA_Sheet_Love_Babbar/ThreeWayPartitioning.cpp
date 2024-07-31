/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array of size n and a range [a, b]. The task is to partition the array around the range such that the array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.

Constraints:
1 <= n <= 10^6
1 <= array[i], a, b <= 10^9

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

#define min(a, b) (a < b ? a : b)

class Solution {
public:
    
    void threeWayPartition(std::vector<int>& array, int a, int b) {
        int n = (int)array.size();
        int l = 0, m = 0, h = n - 1;

        while (m <= h) {
            if (array[m] < a) {
                std::swap(array[l], array[m]);
                m++, l++;
            }
            else if (array[m] > b) {
                std::swap(array[h], array[m]);
                h--;
            }
            else m++;
        }
    }
    
};

int main() {
    int a = 32, b = 58;
    std::vector<int> arr = {58, 58, 33, 41, 3, 42, 6, 23, 19, 21, 40, 32, 7, 8, 5, 64, 6, 45, 63, 11, 34, 40, 64, 16, 10, 15, 54, 25, 59, 48, 16, 6, 34, 66, 10, 41, 59, 2, 5, 66};

    Solution obj;
    obj.threeWayPartition(arr, a, b);

    for (auto i : arr) std::cout << i << ' ';
}