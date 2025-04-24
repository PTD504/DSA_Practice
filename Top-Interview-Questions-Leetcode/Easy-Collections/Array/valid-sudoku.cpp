#include <iostream>
#include <vector>


class Solution {
private:
    
    bool isValidRow(std::vector<std::vector<char> >& board, int row) {
        std::vector<int> cnt(10);
        
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == '.') continue;
            
            int num = board[row][i] - '0';
            
            if (cnt[num] > 0) return false;
            else cnt[num] = 1;
        }
        
        return true;
    }
    
    bool isValidColumn(std::vector<std::vector<char> >& board, int col) {
        std::vector<int> cnt(10);
        
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == '.') continue;
            
            int num = board[i][col] - '0';
            
            if (cnt[num] > 0) return false;
            else cnt[num] = 1;
        }
        
        return true;
    }
    
    bool isValidSubBox(std::vector<std::vector<char> >& board, int bottom_row, int right_col) {
        std::vector<int> cnt(10);
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[bottom_row - i][right_col - j] == '.') continue;
                
                int num = board[bottom_row - i][right_col - j] - '0';
                
                if (cnt[num] > 0) return false;
                else cnt[num] = 1;
            }
        }
        
        return true;
    }
    
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (!isValidRow(board, i) or !isValidColumn(board, j)) return false;
                if ((i + 1) % 3 == 0 and (j + 1) % 3 == 0) {
                    if (!isValidSubBox(board, i, j)) return false;
                }
            }
        }
        
        return true;
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '2', '8', '.', '.'},
        {'.', '.', '2', '4', '1', '9', '.', '.', '5'},
        {'.', '8', '7', '9', '3', '.', '.', '2', '.'}
    };
    
    if (solution.isValidSudoku(board)) {
        std::cout << "The Sudoku board is valid." << std::endl;
    } else {
        std::cout << "The Sudoku board is invalid." << std::endl;
    }
    
    return 0;
}