/*
###########################################
Source: CSES

Problem statement:
Given n ranges, your task is to determine for each range if it contains some other range and if some other range contains it.
Range [a,b] contains range [c,d] if a <= c and d <= b.
Input
The first input line has an integer n: the number of ranges.
After this, there are n lines that describe the ranges. Each line has two integers x and y: the range is [x,y].
You may assume that no range appears more than once in the input.
Output
First print a line that describes for each range (in the input order) if it contains some other range (1) or not (0).
Then print a line that describes for each range (in the input order) if some other range contains it (1) or not (0).

Constraints:
1 <= n <= 2 * 10^5
1 <= x < y <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	vector<pair<pair<int, int>, int> > vp;
 
	int n; cin >> n;
 
	for (int i = 0, x, y; i < n; ++i) {
		cin >> x >> y;
		vp.push_back({{x, y}, i});
	}
 
	sort(vp.begin(), vp.end());
 
	// check if range i contain any other range
	vector<int> ans1(n), ans2(n);
 
	auto contain = [&] (int i) {
		int f = vp[i].first.first, s = vp[i].first.second;
 
		int l = i + 1, h = n - 1;
 
		while (l <= h) {
			int m = l + (h - l) / 2;
 
			if (vp[m].first.first >= f and vp[m].first.second <= s) return 1;
 
			if (vp[m].first.first < f) l++;
			else m--;
		}
 
		return 0;
	};
 
	// check if range i contain any other range
	
	if (n == 1) {
		cout << 0 << '\n' << 0;
		return 0;
	}
 
	for (int i = n - 2, Min = vp[n - 1].first.second; i >= 0; --i) {
		if (Min <= vp[i].first.second) ans1[vp[i].second] = 1;//, Max = vp[i].first.second;
		else Min = vp[i].first.second;								    
 
		if (Min <= vp[i + 1].first.second and vp[i + 1].first.first == vp[i].first.first)
			ans1[vp[i + 1].second] = 1;
	}
 
//	if (vp[n - 1].first.second == vp[n - 2].first.second and vp[n - 1].first.first == vp[n - 2].first.first)
//		ans1[vp[n - 1].second] = 1;
 
	for (int i = 1, Max = vp[0].first.second; i < n; ++i) {
		if (Max >= vp[i].first.second) ans2[vp[i].second] = 1;
		else Max = vp[i].first.second;
 
		if (Max >= vp[i - 1].first.second and vp[i - 1].first.first == vp[i].first.first)
			ans2[vp[i - 1].second] = 1;
	}
 
//	if (vp[0].first.first == vp[1].first.first and vp[1].first.second == vp[0].first.second)
//		ans2[vp[0].second] = 1;
 
	for (int i = 0; i < n; ++i) cout << ans1[i] << " \n"[i == n - 1];
	for (int i = 0; i < n; ++i) cout << ans2[i] << " \n"[i == n - 1];
}