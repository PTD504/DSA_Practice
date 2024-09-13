/*
###########################################
Source: CSES

Problem statement:
There are 88418 paths in a 7 \times 7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).

You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.

INPUT:
The only input line has a 48-character string of characters ?, D, U, L and R.

OUTPUT:
Print one integer: the total number of paths.

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int LEN_DIR = 48;
const int LEN_MAT = 9;
 
bool mat[LEN_MAT][LEN_MAT];
int p[LEN_DIR];
int dirR[4] = {0, 0, -1, 1};
int dirC[4] = {-1, 1, 0, 0};
 
int recursion(int r, int c, int idx) {
    
    if ((mat[r - 1][c] and mat[r + 1][c]) and (!mat[r][c - 1] and !mat[r][c + 1]))
        return 0;
    if ((mat[r][c - 1] and mat[r][c + 1]) and (!mat[r - 1][c] and !mat[r + 1][c]))
        return 0;
    
    if (r == 7 and c == 1) {
        if (idx == LEN_DIR)
            return 1;
        return 0;
    }
    
    if (idx == LEN_DIR)
        return 0;
    
    int ans = 0;
    mat[r][c] = true;
    
    if (p[idx] < 4) {
        int row = r + dirR[p[idx]];
        int col = c + dirC[p[idx]];
        if (!mat[row][col])
            ans += recursion(row, col, idx + 1);
    }
    else{
        for (int i = 0; i < 4; ++i) {
            int row = r + dirR[i];
            int col = c + dirC[i];
            
            if (!mat[row][col])
                ans += recursion(row, col, idx + 1);
        }
    }
    
    mat[r][c] = false;
    return ans;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    getline(cin, s);
    
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < LEN_MAT; ++i)
        mat[i][0] = mat[i][8] = mat[0][i] = mat[8][i] = true;
    
    for (int i = 0; i < LEN_DIR; ++i) {
        if (s[i] == 'L')
            p[i] = 0;
        else if (s[i] == 'R')
            p[i] = 1;
        else if (s[i] == 'U')
            p[i] = 2;
        else if (s[i] == 'D')
            p[i] = 3;
        else
            p[i] = 4;
    }
    
    int startR = 1, startC = 1, idx = 0;
    
    int ans = recursion(startR, startC, idx);
    
    cout << ans;
}
