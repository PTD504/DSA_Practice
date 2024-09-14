/*
###########################################
Source: CSES

Problem statement:
You are given a list of n integers, and your task is to calculate the number of distinct values in the list.
Input
The first input line has an integer n: the number of values.
The second line has n integers x_1, x_2,..., x_n.
Output
Print one integers: the number of distinct values.

Constraints:
1 <= n <= 2 * 10^5
1 <= x_i <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n; cin >> n;
	vector<int> ans(n);
	
	for (auto &i : ans)
		cin >> i;
	
	sort(ans.begin(), ans.end());
	auto res = unique(ans.begin(), ans.end());
	ans.erase(res, ans.end());
	
	cout << ans.size();
}
