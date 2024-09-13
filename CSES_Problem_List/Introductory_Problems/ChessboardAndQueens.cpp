/*
###########################################
Source: CSES

Problem statement:
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

INPUT:
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

OUTPUT:
Print one integer: the number of ways you can place the queens.

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
char a[8][8];
int ans = 0;
vector<int> cot(8, 0);
unordered_map<int, int> CheoChinh;
vector<int> CheoPhu(16, 0);
 
void ChessQueens(int i){
	for (int j = 0; j < 8; ++j){
		if (cot[j] == 0 && CheoChinh[i - j] == 0 && CheoPhu[j + i] == 0 && a[i][j] != '*'){
			cot[j] = CheoChinh[i - j] = CheoPhu[i + j] = 1;
			if (i == 7)
				ans++;
			else
				ChessQueens(i + 1);
			cot[j] = CheoChinh[i - j] = CheoPhu[i + j] = 0;
		}
	}
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (auto &i : a)
		for (auto &j : i)
			cin>>j;
	ChessQueens(0);
	cout << ans;
}