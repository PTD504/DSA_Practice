/*
###########################################
Source: CSES

Problem statement:
You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,...,a_n: the array values.
Output
Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints:
1 <= n <= 1000
1 <= x, a_i <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve() {
 
	int n, x; cin>>n>>x;
	vector<int> a(n);
 
	for (auto &i : a)
		cin>>i;
 
	unordered_map<int, pair<int, int> > mp;
 
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			mp[a[i] + a[j]] = {i, j};
 
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j) {
			
			int sum = x - a[i] - a[j];
 
			if (mp.find(x - a[i] - a[j]) != mp.end()) {
				if (mp[sum].first != i and mp[sum].second != i and mp[sum].first != j and mp[sum].second != j) {
					cout << mp[sum].first + 1 << ' ' << mp[sum].second + 1 << ' ' << i + 1 << ' ' << j + 1;
					return;
				}
			}
		}
	cout << "IMPOSSIBLE";
}
 
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int test = 1; //cin>>test;
 
	//init();
 
	while (test--) {
 
		solve();
 
	}
 
	return 0;
}
