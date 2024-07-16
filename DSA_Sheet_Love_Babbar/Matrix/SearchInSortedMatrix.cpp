/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x. Find whether element x is present in the matrix or not. Return a boolean value true if x is present in the matrix and false if it is not present.

Constraints:
1 <= n, m <= 1000
1 <= mat[i][j] <= 10^5
1 <= x <= 1000

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(std::vector<std::vector<int> > matrix, int n, int m, int x) 
    {
        int r = 0, c = m - 1;

        while (r < n and c >= 0) {
            if (matrix[r][c] == x) return true;
            else if (matrix[r][c] > x) c--;
            else r++;
        }
        
        return false;
    }
};

int main() {
    int n = 7, m = 8, x = 43;
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7, 9, 11, 13, 15},
        {2, 4, 6, 8, 10, 12, 14, 16},
        {17, 19, 21, 23, 25, 27, 29, 31},
        {18, 20, 22, 24, 26, 28, 30, 32},
        {33, 35, 37, 39, 41, 43, 45, 47},
        {34, 36, 38, 40, 42, 44, 46, 48},
        {49, 51, 53, 55, 57, 59, 61, 63}
    };

    Solution obj;

    if (obj.search(matrix, n, m, x)) 
        std::cout << "Element " << x << " is found in the matrix\n";
    else
        std::cout << "Element " << x << " is not found in the matrix\n";
}