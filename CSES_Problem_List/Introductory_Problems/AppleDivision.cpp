/*
###########################################
Source: CSES

Problem statement:
There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.

INPUT:
The first input line has an integer n: the number of apples.
The next line has n integers p_1,p_2,...,p_n: the weight of each apple.

OUTPUT:
Print one integer: the minimum difference between the weights of the groups.

Constraints:
1 <= n <= 20
1 <= p[i] <= 10^9

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define ll long long
ll n, sum = 0;
vector<ll> a;
 
ll Solution(ll Sum1, ll TotalSum, ll i){
	if (i == 0)
		return abs(TotalSum - Sum1 - Sum1);
	return min(Solution(Sum1 + a[i], TotalSum, i - 1), Solution(Sum1, TotalSum, i - 1));
}
 
 
int main()
{
	cin>>n;
	a.resize(n);
	for (auto &i : a)
		cin>>i;
	for (auto i : a)
		sum += i;
	cout << Solution(0, sum, n - 1);
}
