/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears strictly more than N/2 times in the array.
Constraints:
1 ≤ N ≤ 10^7
0 ≤ Ai ≤ 10^6

Solution: PTD504
###########################################
*/

#include <iostream>

class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        int count = 0, majorElement = -1;

        for (int i = 0; i < size; ++i) {
            if (majorElement == a[i]) count++;
            else {
                count--;
                if (count <= 0) count = 1, majorElement = a[i];
            }
        }

        count = 0;

        for (int i = 0; i < size; ++i) {
            if (a[i] == majorElement) count++;
        }

        return count > (size >> 1) ? majorElement : -1;
    }
};

int main() {
    int size = 10; //std::cin >> size;
    int arr[] = {3, 4, 2, 3, 5, 6, 3, 3, 3, 3};

    Solution obj;

    std::cout << obj.majorityElement(arr, size);
}