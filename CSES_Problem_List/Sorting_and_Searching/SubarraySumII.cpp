/*
###########################################
Source: CSES

Problem statement:
Given an array of n positive integers, your task is to count the number of subarrays having sum x.
Input
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a_1,a_2,...,a_n: the contents of the array.
Output
Print one integer: the required number of subarrays.

Constraints:
1 <= n <= 2 * 10^5
-10^9 <= x, a_i <= 10^9

Solution: PTD504
###########################################
*/

#include <iostream>
#include <map>
using namespace std;
#define ll long long
const int MAX = 2e5 + 5;
 
ll a[MAX] = {0}, prefix[MAX] = {0};
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin>>n;
	ll x; cin>>x;
 
	ll sum = 0, ans = 0;
	for (int i = 0; i < n; ++i)
		cin>>a[i];
 
	map<ll, int> mp;
	mp[0] = 1;
 
	for (int i = 0; i < n; ++i){
		sum += a[i];
 
		//mp[sum]++;
 
		ans += mp[sum - x];
 
		mp[sum]++;
	}
 
	cout << ans;
}
