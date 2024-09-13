/*
###########################################
Source: CSES

Problem statement:
You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.

Constraints:
2 <= n <= 2 * 10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin>>n;
	vector<long long> a(n - 1);
	long long sum = 0;
	for (auto &i : a){
		cin>>i;
		sum += i;
	}
	cout << n * (n + 1) / 2 - sum;
}
