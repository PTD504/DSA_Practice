/*
###########################################
Source: CSES

Problem statement:
You are given an array of n integers. Your task is to calculate the median of each window of k elements, from left to right.
The median is the middle element when the elements are sorted. If the number of elements is even, there are two possible medians and we assume that the median is the smaller of them.
Input
The first input line contains two integers n and k: the number of elements and the size of the window.
Then there are n integers x_1,x_2,...,x_n: the contents of the array.
Output
Print n-k+1 values: the medians.

Constraints:
1 <= k <= n <= 2 * 10^5
1 <= x_i <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
 
using namespace std;
 
void slidingWindowMedian(vector<int> x, int k);
int findMedian(int);
void ins(int, int);
void ers(int, int);
 
multiset<int> fir, las;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, k; cin >> n >> k;
	vector<int> x(n);
 
	for (int &i : x) cin >> i;
 
	slidingWindowMedian(x, k);
}
 
void slidingWindowMedian(vector<int> x, int k) {
	int n = (int)x.size();
	//multiset<int> fir, las;
	
	if (k == 1) {
		for (int i : x) cout << i << ' ';
		return;
	}
 
	for (int i = 0; i < k; ++i) ins(k, x[i]);
 
	cout << findMedian(k) << ' ';
 
	for (int i = k, j = 0; i < n; ++i, ++j) {
		ers(k, x[j]);
		ins(k, x[i]);
		cout << findMedian(k) << ' ';
	}
}
 
void ins(int k, int x) {
	if ((int)fir.size() < k / 2) {
		if ((int)las.size() == 0) fir.insert(x);
		else {
			int mn = *las.begin();
			if (mn < x) 
				las.erase(las.find(mn)), las.insert(x), fir.insert(mn);
			else fir.insert(x);
		}
	}
	else {
		int mx = *fir.rbegin();
		if (mx > x)
			las.insert(mx), fir.erase(fir.find(*fir.rbegin())), fir.insert(x);
		else
			las.insert(x);
	}
}
 
void ers(int k, int x) {
	if (fir.find(x) != fir.end()) fir.erase(fir.find(x));
	else las.erase(las.find(x));
}
 
int findMedian(int k) {
	if (k & 1) return *las.begin();
	else return *fir.rbegin();
}



