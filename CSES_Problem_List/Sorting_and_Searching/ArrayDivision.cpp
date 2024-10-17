/*
###########################################
Source: CSES

Problem statement:
You are given an array containing n positive integers.
Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.
Input
The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.
The next line contains n integers x_1,x_2,...,x_n: the contents of the array.
Output
Print one integer: the maximum sum in a subarray in the optimal division.

Constraints:
1 <= k <= n <= 2 * 10^5
1 <= x_i <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, sum = 0; cin>>n>>k;
    vector<int> a(n);
    
    for (auto &i : a){
        cin>>i;
        sum += i;
    }
    
    auto check = [&] (vector<int> a, int res, int k) {
        int sum = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
        	if (a[i] > res)
        		return false;
            sum += a[i];
            if (sum > res)
                k--, sum = a[i];
        }
        
        return k > 0;
    };
    
    int low = 0, high = sum, mid, ans = 1e9;
    
    while (low <= high) {
        
        mid = low + (high - low) / 2;
        
        if (check(a, mid, k)) {
            high = mid - 1, ans = mid;
        }
        else
            low = mid + 1;
    }
    
    cout << ans;
}


