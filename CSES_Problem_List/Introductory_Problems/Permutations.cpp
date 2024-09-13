/*
###########################################
Source: CSES

Problem statement:
A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.

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
	if (n == 1){
		cout << 1;
		return 0;
	}
	if (n <= 3){
		cout << "NO SOLUTION";
		return 0;
	}
	int temp = n - 1;
	cout << temp << " ";
	temp -= 2;
	while(temp > 0){
		cout << temp << " ";
		temp -= 2;
	}
	cout << n << " ";
	n -= 2;
	while(n > 0){
		cout << n << " ";
		n -= 2;
	}
}

