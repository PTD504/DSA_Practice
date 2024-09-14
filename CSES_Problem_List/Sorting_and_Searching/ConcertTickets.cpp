/*
###########################################
Source: CSES

Problem statement:
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.
Input
The first input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers h_1,h_2,...,h_n: the price of each ticket.
The last line contains m integers t_1,t_2...,t_m: the maximum price for each customer in the order they arrive.
Output
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print -1.

Constraints:
1 <= n, m <= 2 * 10^5
1 <= h_i, t_i <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
using namespace std;
 
int n, m, h, t;
multiset<int> mp;
 
int main(){
    ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
    
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i){
	    cin >> h;
	    mp.insert(h);
	}
	
	for (int i = 0; i < m; ++i){
	    cin >> t;
	    auto j = mp.upper_bound(t);
	    if (j == mp.begin()) cout << -1 << '\n';
	    else {cout << *(--j) << '\n'; mp.erase(j);}
	}
}

