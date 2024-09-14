/*
###########################################
Source: CSES

Problem statement:
There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

Input:
The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.
The next line contains n integers a_1, a_2, ..., a_n: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x-k and x+k.
The last line contains m integers b_1, b_2, ..., b_m: the size of each apartment.
Output:
Print one integer: the number of applicants who will get an apartment.

Constraints:
1 <= n, m <= 2 * 10^5
0 <= k <= 10^9
1 <= a_i, b_i <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	int n, m, k, ans = 0; cin >> n >> m >> k;
	
	vector<int> a(n), b(m); 
	
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int i = 0, j = 0;
	
	while(i != n && j != m) {
	    if (abs(a[i] - b[j]) <= k) 
		{ans++; i++; j++;}
	    else if (a[i] > b[j]) j++;
	    else    i++;
	}
	cout << ans;
}
