/*
###########################################
Source: CSES

Problem statement:
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
Input
The first input line has an integer n: the size of the array.
The second line has n integers x_1,x_2,...,x_n: the array values.
Output
Print one integer: the maximum subarray sum.

Constraints:
1 <= n <= 2 * 10^5
-10^9 <= x_i <= 10^9

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
using namespace std;
#define ll long long
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin>>n;
	vector<ll> a(n);
	for (auto &i : a)
		cin>>i;
	vector<ll> pref(n + 1), prefMin(n + 1);
	pref[0] = prefMin[0] = 0;
	ll ans = -1e9;
	for (int i = 1; i <= n; ++i)
		pref[i] = pref[i - 1] + a[i - 1], prefMin[i] = min(prefMin[i - 1], pref[i]);
	for (int i = 1; i <= n; ++i)
		ans = max(ans, pref[i] - prefMin[i - 1]);
	cout << ans;
}
}