/*
###########################################
Source: GeeksforGeeks

Problem statement:
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].
Constraints:
1 ≤ n ≤ 10 

Solution: PTD504
###########################################
*/

#include <iostream>
#include "UnorderedMap.h"

class Solution 
{
public:
	
	std::vector<std::vector<int> > ans;

	void recursion(UnorderedMap<int, int>& checkMainDiagonal, std::vector<int>& checkAntiDiagonal, std::vector<int>& checkRows, \
	 std::vector<int> curAns, int curQueen, int maxNumQueens) {
		// The ith queen will be placed in the ith-column. So main task of this function is to find out the valid row for the current queen curQueen
		int col = curQueen;

		if (col > maxNumQueens) {
			ans.push_back(curAns);
			return;
		}

		for (int row = 1; row <= maxNumQueens; ++row) {
			// The current cell is (row, col)
			// Check if the current cell lie in a valid main diagonal or not
			if (checkMainDiagonal[row - col]) continue; 
			// Check valid Anti-diagonal
			if (checkAntiDiagonal[row + col - 1]) continue; // 0-based index
			// Check valid row
			if (checkRows[row - 1]) continue;
			
			// All conditions is satified
			checkMainDiagonal[row - col] = checkAntiDiagonal[row + col - 1] = checkRows[row - 1] = 1;
			curAns.push_back(row);
			recursion(checkMainDiagonal, checkAntiDiagonal, checkRows, curAns, curQueen + 1, maxNumQueens);
			curAns.pop_back();
			checkMainDiagonal[row - col] = checkAntiDiagonal[row + col - 1] = checkRows[row - 1] = 0;
		}
	}

	std::vector<std::vector<int> > nQueens(int n) {
		UnorderedMap<int, int> checkMainDiagonal;
		std::vector<int> checkAntiDiagonal(n << 1);
		std::vector<int> checkRows(n);
		std::vector<int> curAns;

		recursion(checkMainDiagonal, checkAntiDiagonal, checkRows, curAns, 1, n);

		return ans;
	}
};

int main() {
	int n; std::cin >> n;

	Solution obj;

	for (auto &v : obj.nQueens(n)) {
		for (auto i : v) std::cout << i << ' ';
		std::cout << '\n';
	}
}
