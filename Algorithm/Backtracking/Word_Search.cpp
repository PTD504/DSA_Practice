/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a 2D board of letters and a word. Check if the word exists in the board. The word can be constructed from letters of adjacent cells only. ie - horizontal or vertical neighbors. The same letter cell can not be used more than once.
Constraints:
1 ≤ N, M ≤ 100
1 ≤ L ≤ N*M (L is the length of word)

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <utility>

class Solution {
public:

    std::vector<std::vector<bool> > check;
    std::pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool recursion(std::vector<std::vector<char>>& board, std::string word, int idx, int r, int c) {
        if (idx >= word.size()) return true;

        check[r][c] = true;

        for (int i = 0, x, y; i < 4; ++i) {
            x = r + dir[i].first, y = c + dir[i].second;
            if (x >= 0 and y >= 0 and x < board.size() and y < board[0].size() and word[idx] == board[x][y] and check[x][y] == false) {
                if (recursion(board, word, idx + 1, x, y)) return true;
            }
        }

        check[r][c] = false;

        return false;
    } 

    bool isWordExist(std::vector<std::vector<char>>& board, std::string word) {
        check.resize(board.size(), std::vector<bool> (board[0].size(), false));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != word[0]) continue;
                if (recursion(board, word, 1, i, j)) return true;
            }
        }

        return false;
    }
};

int main() {
    std::vector<std::vector<char> > board = {{'a','g','b','c'},{'q','e','e','l'},{'g','b','k','s'}};
    std::string word = "geeks";

    Solution obj;

    if (obj.isWordExist(board, word)) std::cout << "The word " << word << " exists in the board";
    else std::cout << "The word " << word << " does not exist in the board";
}