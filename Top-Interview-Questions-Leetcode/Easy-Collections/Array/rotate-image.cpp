#include <iostream>
#include <vector>

class Solution {
private:
    
    void reverse(std::vector<int>& row) {
        int i = 0, j = row.size() - 1;
        
        while (i < j) std::swap(row[i++], row[j--]);
    }
    
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose the given matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row of the transpose matrix, we will receive the expected result
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i]);
        }
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    solution.rotate(matrix);
    
    for (const std::vector<int>& row : matrix) {
        for (const int& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}