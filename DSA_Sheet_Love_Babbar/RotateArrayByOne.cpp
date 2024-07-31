/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array arr, rotate the array by one position in clock-wise direction.

Constraints:
1<=arr.size()<=10^5
0<=arr[i]<=10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<int> &arr) {
        int temp = arr.back();

        for (int i = arr.size() - 1; i > 0; --i) arr[i] = arr[i - 1];

        arr[0] = temp;
    }
};

int main() {
	int n = 20;
    std::vector<int> arr = {34, 37, 54, 31, 23, 8, 19, 17, 46, 21};

    Solution obj;

    obj.rotate(arr);

    for (auto i : arr) std::cout << i << ' ';
}