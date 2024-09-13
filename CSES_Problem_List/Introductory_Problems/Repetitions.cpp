/*
###########################################
Source: CSES

Problem statement:
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

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
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin>>s;
	//int n = (int)s.size();
	char var = 'A';
	int dem = 0, Max = 0;
	for (auto i : s){
		if (i == var){
			dem++;
			Max = max(Max, dem);
		}
		else
			var = i, dem = 1;
	}
	cout << Max;
}
