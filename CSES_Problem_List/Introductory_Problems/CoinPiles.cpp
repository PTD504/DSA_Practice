/*
###########################################
Source: CSES

Problem statement:
You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.
Your task is to efficiently find out if you can empty both the piles.

INPUT:
The first input line has an integer t: the number of tests.
After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.

OUTPUT:
For each test, print "YES" if you can empty the piles and "NO" otherwise.

Constraints:
1 <= t <= 10^5
0 <= a, b <= 10^9

Solution: PTD504
###########################################
*/

#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
//const int mod = 1e9 + 7;
 
void Solve(){
	int a, b;
	cin>>a>>b;
	int m = (2 * b - a) / 3, n = (2 * a - b) / 3;
	if (m + 2 * n == a && 2 * m + n == b && m >= 0 && n >= 0)
		cout << "YES";
	else
		cout << "NO";
	cout << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		Solve();
	}
}

