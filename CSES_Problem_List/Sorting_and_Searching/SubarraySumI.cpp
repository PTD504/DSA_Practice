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
1 <= x, a_i <= 10^9

Solution: PTD504
###########################################
*/

#include <iostream>
using namespace std;
#define ll long long
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n; cin>>n;
	ll x, a[n];
	cin>>x;
	for (int i = 0; i < n; ++i)
		cin>>a[i];
 
	ll sum = 0, ans = 0;
 
	int i = 0, j = 0;
 
	while(j < n or i < n){
		if (sum < x and j < n)
			sum += a[j++];
		else if (sum == x)
			ans++, sum -= a[i++];
		else
			sum -= a[i++];
	}
 
	cout << ans;
}

