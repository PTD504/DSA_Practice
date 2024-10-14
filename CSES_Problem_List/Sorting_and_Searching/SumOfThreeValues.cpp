/*
###########################################
Source: CSES

Problem statement:
You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,...,a_n: the array values.
Output
Print three integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints:
1 <= n <= 5000
1 <= x, a_i <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, x; cin >> n >> x;
	vector<pair<int, int> > vp;
 
	for (int i = 0, a; i < n; ++i) {
	    cin >> a;
	    vp.push_back({a, i + 1});
	}
	
	sort(vp.begin(), vp.end());
 
	for (int i = 0; i < n - 2; ++i) {
		int l = i + 1, h = n - 1;
		while (l < h) {
			if (vp[l].first + vp[h].first + vp[i].first == x) {
				cout << vp[l].second << ' ' << vp[h].second << ' ' << vp[i].second;
				return 0;
			}
			else if (vp[l].first + vp[h].first + vp[i].first < x)
				l++;
			else
				h--;
		}
	}
 
	cout << "IMPOSSIBLE";
 
	return 0;
}
