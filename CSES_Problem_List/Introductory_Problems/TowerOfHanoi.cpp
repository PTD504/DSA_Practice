/*
###########################################
Source: CSES

Problem statement:
The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom. 
The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.
Your task is to find a solution that minimizes the number of moves.

INPUT:
The only input line has an integer n: the number of disks.

OUTPUT:
First print an integer k: the minimum number of moves.
After this, print k lines that describe the moves. Each line has two integers a and b: you move a disk from stack a to stack b.

Constraints:
1 <= n <= 16

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
using namespace std;
 
int k = 0;
 
void TowerOfHaNoi(int n, int src, int mid, int des) {
    if (n == 0) return;

    TowerOfHaNoi(n - 1, src, des, mid);

    cout << src << " " << des << '\n';
    
	TowerOfHaNoi(n - 1, mid, src, des);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    cout << (int)pow(2, n) - 1 << '\n';

    TowerOfHaNoi(n, 1, 2, 3);
}
