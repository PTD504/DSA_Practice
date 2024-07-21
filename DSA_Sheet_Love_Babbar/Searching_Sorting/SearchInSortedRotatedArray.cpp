/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a sorted and rotated array A of N distinct elements which are rotated at some point, and given an element K. The task is to find the index of the given element K in array A.

Constraints:
1 ≤ N ≤ 10^7
0 ≤ Ai ≤ 10^8
1 ≤ K ≤ 10^8

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

int Search(std::vector<int> vec, int K) {
    
    int l = 0, h = vec.size() - 1;
    
    while (l <= h) {
        int m = l + (h - l) / 2;
        
        if (vec[m] == K) return m;
        else if (vec[m] >= vec[0]) {
            if (vec[m] < K or K < vec[0]) l = m + 1;
            else h = m - 1;
        }
        else {
            if (vec[m] > K or K > vec[0]) h = m - 1;
            else l = m + 1;
        }
    }
    
    return -1;
}

int main() {
    std::vector<int> vec = {64, 65, 67, 71, 71, 75, 76, 78, 78, 79, 80, 83, 85, 86, 92, 92, 93, 95, 96, 99, 100, 3, 7, 7, 10, 11, 14, 17, 25, 27, 27, 29, 40, 42, 43, 48, 56, 56, 58, 60};
    int K = 60;
    
    std::cout << Search(vec, K);
}