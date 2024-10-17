/*
###########################################
Source: CSES

Problem statement:
Given an array of n integers, your task is to calculate the number of subarrays that have at most k distinct values.
Input
The first input line has two integers n and k.
The next line has n integers x_1,x_2,...,x_n: the contents of the array.
Output
Print one integer: the number of subarrays.

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
    
    int n, k; cin>>n>>k;
    vector<int> a(n);
    
    for (auto &i : a)
        cin>>i;
        
    unordered_map<int, int> mp;
    int ans = 0, j = 0, var = 0;
    
    for (int i = 0; i < n; ++i) {
        mp[a[i]]++, var++;
        
        while ((int)mp.size() > k) {
            mp[a[j]]--;
            var--;
            if (mp[a[j]] <= 0)
                mp.erase(a[j]);
            j++;
        }
        
        ans += var;
    }
    
    cout << ans;
}

