/*
###########################################
Source: GeeksforGeeks

Problem statement:
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Constraints:
1 ≤ n ≤ 5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <utility>

const int MAXN = 5;

class Solution{
    public:

    std::pair<char, std::pair<int, int> > dir[4] = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
    std::vector<std::string> ans;

    void recursion(std::vector<std::vector<int> > &mat, int check[MAXN][MAXN], std::string curAns, int r, int c) {

        if (r == mat.size() - 1 and c == mat.size() - 1) {
            ans.push_back(curAns);
            return;
        }

        check[r][c] = 1;

        for (int i = 0, x, y; i < 4; ++i) {
            x = r + dir[i].second.first;
            y = c + dir[i].second.second;

            if (x >= 0 and y >= 0 and x < mat.size() and y < mat.size() and mat[x][y] and check[x][y] == 0) {
                curAns += dir[i].first;
                recursion(mat, check, curAns, x, y);
                curAns.pop_back();
            } 
        }

        check[r][c] = 0;
    }

    std::vector<std::string> findPath(std::vector<std::vector<int>> &m, int n) {
        if (m[0][0] == 0) return ans;

        int check[MAXN][MAXN] = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        };
        std::string curAns = "";

        recursion(m, check, curAns, 0, 0);

        return ans;
    }
};

int main() {
    int n = 4;
    std::vector<std::vector<int> > mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    }; // size: n * n

    Solution obj;

    for (auto str : obj.findPath(mat, n)) {
        std::cout << str << '\n';
    }
}