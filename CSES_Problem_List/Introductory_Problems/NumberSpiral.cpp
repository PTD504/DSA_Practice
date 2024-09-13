/*
###########################################
Source: CSES

Problem statement:
A number spiral is an infinite grid whose upper-left square has number 1. Here are the first six layers of the spiral:

1   2   9  10  25  26
 4   3   8  11  24  27
 5   6   7  12  23  28
16  15  14  13  22  29
17  18  19  20  21  30
36  35  34  33  32  31

Your task is to find out the number in row y and column x.

Constraints:
1 <= t <= 10^5, the number of tests
1 <= y, x <= 10^9

Solution: PTD504
###########################################
*/

#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
 
void Solve(){
	ll x, y; cin>>x>>y;// x: row, y: column
	if (x == y){
		cout << x * y - (x - 1);
		return;
	}
	if (x < y){
		if (y & 1)
			y = y * y - (x - 1);
		else
			y = (y - 1) * (y - 1) + 1 + (x - 1);
		cout << y;
	}
	else{
		if (x & 1)
			x = (x - 1) * (x - 1) + 1 + (y - 1);
		else
			x = x * x - (y - 1);
		cout << x;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		Solve();
		cout << '\n';
	}
}


