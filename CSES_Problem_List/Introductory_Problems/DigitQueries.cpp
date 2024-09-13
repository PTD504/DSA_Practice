/*
###########################################
Source: CSES

Problem statement:
Consider an infinite string that consists of all positive integers in increasing order:
12345678910111213141516171819202122232425...

Your task is to process q queries of the form: what is the digit at position k in the string?

INPUT:
The first input line has an integer q: the number of queries.
After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.

OUTPUT:
For each query, print the corresponding digit.

Constraints:
1 <= q <= 1000
1 <= k <= 10^18

Solution: PTD504
###########################################
*/

#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
    long long p, a[19], i;

    for (i = 1; i <= 18; ++i){
        a[i] = 9 * i * pow(10, i - 1);
    }
 
    int t; cin >> t;

    while (t--) {
    	cin>>p;
    	i = 1;
	    while (p - a[i] >= 0) {
	        p -= a[i];
	        i++;
	    }
	    long long x = (long long)pow(10, i - 1) + p / i - 1;
	    p %= i;
	    if (p == 0) {
	        cout << x % 10 << '\n';
	    }
	    else {
	        x++;
	        string s = to_string(x);
	        cout << s[p - 1] << '\n';
	    }
	}

    return 0;
}
