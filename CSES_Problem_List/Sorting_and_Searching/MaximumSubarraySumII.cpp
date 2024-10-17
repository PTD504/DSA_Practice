/*
###########################################
Source: CSES

Problem statement:
Given an array of n integers, your task is to find the maximum sum of values in a contiguous subarray with length between a and b.
Input
The first input line has three integers n, a and b: the size of the array and the minimum and maximum subarray length.
The second line has n integers x_1,x_2,...,x_n: the array values.
Output
Print one integer: the maximum subarray sum.

Constraints:
1 <= n <= 2 * 10^5
1 <= a <= b <= n
-10^9 <= x_i <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
int maxSubarraySumII(int n, int a, int b, vector<int> x) {
    int i = 0, ans = 0;

    vector<int> prefix(n);
    deque<int> q;
    partial_sum(x.begin(), x.end(), prefix.begin());
    prefix.insert(prefix.begin(), 0);
    
    for (i = a; i <= b; ++i) {
        if (q.empty())
            q.push_back(i);
        else {
            while (q.size() and prefix[q.back()] <= prefix[i])
                q.pop_back();
            q.push_back(i);
        }
    }
    
    ans = prefix[q.front()];
    
    for (int j = 2; j <= n - a + 1; ++j) {
    	if (i <= n) {
	        while (q.size() and prefix[q.back()] <= prefix[i])
	            q.pop_back();
	        q.push_back(i++);
	    }
        
        while (q.size() and q.front() - j + 1 < a)
            q.pop_front();
        
        ans = max(ans, prefix[q.front()] - prefix[j - 1]);
    }
    
    return ans;
}
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, a, b; cin >> n >> a >> b;
	vector<int> x(n);
 
	for (int &i : x)
		cin >> i;
 
	cout << maxSubarraySumII(n, a, b, x);
}