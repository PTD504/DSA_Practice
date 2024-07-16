/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Constraints:
1<=n,m<=1000
0<=M[i][j]<=1

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

#define max(a, b) (a > b ? a : b)

const int MAX = 11;

class Solution{
public:

    int maxRecInHistogram(int hist[], int n) {
        std::stack<int> s;
        int ans = 0, i = 0;

        while (i < n) {
            while (!s.empty() and hist[s.top()] > hist[i]) {
                int t = s.top();
                s.pop();
                ans = max(ans, hist[t] * (s.empty() ? i : i - s.top() - 1));
            }
            s.push(i++);
        }

        while (!s.empty()) {
            int t = s.top();
            s.pop();

            ans = max(ans, hist[t] * (s.empty() ? n : n - s.top() - 1));
        }

        return ans;
    }

    int maxArea(int M[][MAX], int n, int m) {
        int hist[m], ans = 0;
        memset(hist, 0, sizeof(hist));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M[i][j]) hist[j]++;
                else hist[j] = 0;
            }

            ans = max(ans, maxRecInHistogram(hist, m));
        }

        return ans;
    }
};

int main() {
    int r = 10, c = 11;
    int matrix[][MAX] = {
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0},
        {1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0},
        {1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1},
        {1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0}
    };

    Solution obj;

    std::cout << obj.maxArea(matrix, r, c);
}