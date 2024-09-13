/*
###########################################
Source: CSES

Problem statement:
Given a string, your task is to generate all different strings that can be created using its characters.

INPUT:
The only input line has a string of length n. Each character is between a–z.

OUTPUT:
First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.

Constraints:
1 <= n <= 8

Solution: PTD504
###########################################
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
 
inline int fact(int n){
	int ans = 1;
	for (int i = 2; i <= n; ++i)
		ans *= i;
	return ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	int t = (int)s.size();
	
	vector<int> a(26, 0);
	
	for (auto i : s)
		a[i - 'a']++;
	
	int ans = fact(t);
	
	for (int i = 0; i < 26; ++i)
		if (a[i] > 1) ans /= fact(a[i]);
	
	cout << ans << '\n';
	
	sort(s.begin(), s.end());
	
	do {
		cout << s << '\n';
	}
	while(next_permutation(s.begin(), s.end()));
}
