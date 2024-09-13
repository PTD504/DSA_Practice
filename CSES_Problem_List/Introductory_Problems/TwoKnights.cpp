/*
###########################################
Source: CSES

Problem statement:
Your task is to count for k=1,2,...,n the number of ways two knights can be placed on a k * k chessboard so that they do not attack each other.

Constraints:
1 <= n <= 10000

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
	ll n; cin>>n;
	for (ll i = 1; i <= n; ++i)
		cout << i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << '\n';
}


