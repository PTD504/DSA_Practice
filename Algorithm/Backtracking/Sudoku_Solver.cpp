/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task is to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

A sudoku solution must satisfy all of the following rules:
	- Each of the digits 1-9 must occur exactly once in each row.
	- Each of the digits 1-9 must occur exactly once in each column.
	- Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Zeros in the grid indicates blanks, which are to be filled with some number between 1-9. You can not replace the element in the cell which is not blank.

constraint: 0 ≤ grid[i][j] ≤ 9

Solution: PTD504
###########################################
*/

#include <iostream>

const int MAXN = 9;

class Solution 
{
public:

	bool SolveSudoku(int grid[MAXN][MAXN]) {
		int row = -1, col = -1;
		
		// Find unassigned cell in grid
		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				if (grid[i][j] == 0) {
					row = i, col = j;
					break;
				}
			}
			if (row + 1) break;
		}

		if (row == - 1 || col == -1) return true;

		for (int val = 1; val <= MAXN; ++val) {

			if (isValidValue(grid, row, col, val)) {
				grid[row][col] = val;

				if (SolveSudoku(grid)) return true;

				grid[row][col] = 0;
			}
		}

		return false;
	}

	bool isValidValue(int grid[MAXN][MAXN], int row, int col, int num) {
		// Check valid row and valid column
		for (int i = 0; i < MAXN; ++i) {
			if (grid[i][col] == num or grid[row][i] == num) return false;
		}

		// Check 3x3 submatrix
		int startRow = row - row % 3;
		int startCol = col - col % 3;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (grid[i + startRow][j + startCol] == num) return false;
			}
		}

		return true;
	}

	void printGrid(int grid[MAXN][MAXN]) {
		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				std::cout << grid[i][j] << " \n"[j == MAXN - 1];
			}
		}
	}
};

int main() {
	int grid[][MAXN] = {
		{0, 0, 0, 8, 0, 0, 0, 0, 9},
		{0, 1, 9, 0, 0, 5, 8, 3, 0},
		{0, 4, 3, 0, 1, 0, 0, 0, 7},
		{4, 0, 0, 1, 5, 0, 0, 0, 3},
		{0, 0, 2, 7, 0, 4, 0, 1, 0},
		{0, 8, 0, 0, 9, 0, 6, 0, 0},
		{0, 7, 0, 0, 0, 6, 3, 0, 0},
		{0, 3, 0, 0, 7, 0, 0, 8, 0},
		{9, 0, 4, 5, 0, 0, 0, 0, 1}
	};

	Solution obj;
	if (obj.SolveSudoku(grid))
		obj.printGrid(grid);
}