/*
###########################################
Source: CSES

Problem statement:
Your task is to calculate the number of trailing zeros in the factorial n!.
For example, 20! = 2432902008176640000 and it has 4 trailing zeros.

INPUT:
The only input line has an integer n.

OUTPUT:
Print the number of trailing zeros in n!.

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
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin>>n;
	int ans = 0;
	for (int i = 5; i <= n; i += 5){
		int temp = i;
		while(temp % 5 == 0){
			ans++;
			temp /= 5;
		}
	}
	cout << ans;
}
