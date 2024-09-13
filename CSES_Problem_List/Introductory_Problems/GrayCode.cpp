/*
###########################################
Source: CSES

Problem statement:
A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.

INPUT:
The only input line has an integer n.

OUTPUT:
Print 2^n lines that describe the Gray code. You can print any valid solution.

Constraints:
1 <= n <= 16

Solution: PTD504
###########################################
*/

#include <iostream>
#include <bitset>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
 
	for (int i = 0; i < (1 << n); ++i) {
		int val = (i ^ (i >> 1));
		bitset<32> bt(val);

		string s = bt.to_string();
		cout << s.substr(32 - n) << '\n';
	}
}
