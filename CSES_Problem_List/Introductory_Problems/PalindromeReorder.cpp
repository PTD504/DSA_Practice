/*
###########################################
Source: CSES

Problem statement:
Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

INPUT:
The only input line has a string of length n consisting of characters A–Z.

OUTPUT:
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".

Constraints:
1 <= n <= 10^6

Solution: PTD504
###########################################
*/

#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
//const int mod = 1e9 + 7;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s; cin>>s;
	vector<int> a(26, 0);
 
	for (char i : s)
		a[i - 'A']++;
 
	int dem = 0, cs = -1;
	for (int i = 0; i < 26; ++i)
		if (a[i] & 1){
			dem++;
			cs = i;
		}
 
	if (dem > 1){
		cout << "NO SOLUTION";
		return 0;
	}
 
	for (int i = 0; i < 26; ++i)
		if (a[i] > 0 && (a[i] & 1) == 0)
			for (int j = 1; j <= (a[i] >> 1); ++j)
				cout << char(i + int('A'));
 
	if (cs != -1)
		for (int i = 1; i <= a[cs]; ++i)
			cout << char(cs + int('A'));
 
	for (int i = 25; i >= 0; --i)
		if (a[i] > 0 && (a[i] & 1) == 0){
			a[i] = a[i] >> 1;
			for (int j = 1; j <= a[i]; ++j)
				cout << char(i + int('A'));
		}
}
