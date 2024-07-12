/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a number and its reverse. Find that number raised to the power of its own reverse.
Note: As answers can be very large, print the result modulo (10^9 + 7).

Constraints:
1 <= N <= 10^9

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

class Solution {
public:
  
    int search(std::vector<int> vec, int K) {
        
        int l = 0, h = vec.size() - 1;
        
        while (l <= h) {
            int m = l + ((h - l) >> 1);
            
            if (vec[m] == K) return m;
            else if (vec[m] >= vec[0]) {
                if (vec[m] < K or K < vec[0]) l = m + 1;
                else h = m - 1;
            }
            else { 
                if (K >= vec[0]) h = m - 1;
                else if (K > vec[m]) l = m + 1;
                else h = m - 1;
            }
        }
        
        return -1;
    }

};


int main() {
    std::vector<int> arr = {4, 5, 1, 2, 3};
    int K = 5;

    Solution obj;

    std::cout << obj.search(arr, K);
}