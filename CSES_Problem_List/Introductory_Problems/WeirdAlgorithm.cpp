/*
###########################################
Source: CSES

Problem statement:
Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:

3->10->5->16->8->4->2->1

Your task is to simulate the execution of the algorithm for a given value of n.

Constraints:
1 <= n <= 10^6

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
	while(n > 1){
		cout << n << " ";
		if (n & 1)
			n = n * 3 + 1;
		else
			n /= 2;
	}
	cout << n;
}