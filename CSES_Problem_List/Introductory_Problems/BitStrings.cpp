/*
###########################################
Source: CSES

Problem statement:
Your task is to calculate the number of bit strings of length n.
For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.

INPUT:
The only input line has an integer n.

OUTPUT:
Print the result modulo 10^9+7.

Constraints:
1 <= n <= 10^6

Solution: PTD504
###########################################
*/

#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin>>n;
	int ans = 1;
	while(n--){
		ans = ((ans % mod) * (2 % mod)) % mod;
	}
	cout << ans;
}