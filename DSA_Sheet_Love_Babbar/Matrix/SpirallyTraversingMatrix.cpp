/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a matrix of size r*c. Traverse the matrix in spiral form.

Constraints:
1 <= r, c <= 100
0 <= matrix[i] <= 100

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    
    void recursion(std::vector<int> &ans, int start_row, int start_col, int en_row, int en_col, std::vector<std::vector<int> > matrix){
        for (int i = start_col; i <= en_col; ++i)
            ans.push_back(matrix[start_row][i]);
        if (start_row == en_row)
            return;
        for (int i = start_row + 1; i <= en_row; ++i)
            ans.push_back(matrix[i][en_col]);
        if (start_col == en_col)
            return;
        for (int i = en_col - 1; i >= start_col; --i)
            ans.push_back(matrix[en_row][i]);
        for (int i = en_row - 1; i > start_row; --i)
            ans.push_back(matrix[i][start_col]);
        if (start_row + 1 > en_row - 1 or start_col + 1 > en_col - 1)
            return;
        else
            recursion(ans, start_row + 1, start_col + 1, en_row - 1, en_col - 1, matrix);
    }
    
    std::vector<int> spirallyTraverse(std::vector<std::vector<int> > matrix, int r, int c) 
    {
        std::vector<int> ans;
        recursion(ans, 0, 0, r - 1, c - 1, matrix);
        return ans;
    }
};

int main() {
    int r = 10, c = 12;
    std::vector<std::vector<int> > matrix = {
         {13, 43, 13, 84, 79, 69, 43, 23, 78,  4, 98, 47},
         {48, 21, 48, 66, 87, 76,  5, 32, 93, 89, 18, 56},
         { 3, 46,  9, 24, 37, 13, 10, 30, 77, 24, 97, 42},
         {57,  7, 21, 66, 84, 98, 91, 35, 50, 70, 63, 67},
         {51, 58, 46, 50,  1, 40, 18,  6, 52, 37, 31, 93},
         {59, 83, 50, 55, 17, 81, 31, 35, 34, 33,  2, 94},
         {15, 79, 22, 26, 91, 99, 37, 57, 37, 32, 66, 26},
         {50, 64, 42, 83,  7, 87, 78, 35,  5, 65, 81,  3},
         {99, 97, 59,  9, 99, 57, 11, 20, 83,  3, 21,  3},
         { 2, 98, 62, 36, 56, 67, 23,  8, 15, 15, 43, 16}
    };

    Solution obj;

    auto ans = obj.spirallyTraverse(matrix, r, c);

    for (auto i : ans) std::cout << i << ' ';
}