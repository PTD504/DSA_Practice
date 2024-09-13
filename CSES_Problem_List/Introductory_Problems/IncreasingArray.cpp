/*
###########################################
Source: CSES

Problem statement:
You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?

Constraints:
1 <= n <= 2 * 10^5
1 <= x[i] <= 10^9 (0 <= i < n), where x[i] is the i-th element of the array

Solution: PTD504
###########################################
*/

#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin>>n;
	vector<ll> a(n);
	for (auto &i : a)
		cin>>i;
	ll ans = 0, dis = 0;
	for (int i = 1; i < n; ++i){
		if (a[i] < a[i - 1])
			dis = a[i - 1] - a[i], a[i] = a[i - 1];
		else
			dis = 0;
		ans += dis;
	}
	cout << ans;
}

