/*
###########################################
Source: CSES

Problem statement:
Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.
Input
The first input line has an integer n: the size of the array.
The next line has n integers a_1,a_2,...,a_n: the contents of the array.
Output
Print one integer: the required number of subarrays.

Constraints:
1 <= n <= 2 * 10^5
-10^9 <= a_i <= 10^9

Solution: PTD504
###########################################
*/

#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int MAX = 2e5 + 5;
#define ll long long
 
ll a[MAX];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n; cin>>n;
 
	for (int i = 0; i < n; ++i)
		cin>>a[i];
 
	ll mod[n] = {0};
	ll sum = 0, ans = 0;
 
	for (int i = 0;  i < n; ++i){
		sum += a[i];
		mod[(sum % n + n) % n]++;
	}
 
	for (int i = 0; i < n; ++i)
		if (mod[i] > 1)
			ans += mod[i] * (mod[i] - 1) / 2;
 
	ans += mod[0];
 
	cout << ans;
 
}

