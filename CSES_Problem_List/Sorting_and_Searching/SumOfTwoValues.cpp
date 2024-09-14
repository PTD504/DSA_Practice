/*
###########################################
Source: CSES

Problem statement:
You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,...,a_n: the array values.
Output
Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints:
1 <= n <= 2 * 10^5
1 <= x, a_i <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
const int mod = 1e9 + 7;
 
void lowerBound(vector<pair<int, int> > &v, pair<int, int> key){
    int mid, low = 0, high = v.size() - 1;
    while (low <= high){
        mid = low + (high - low) / 2;
        if (v[mid].first <= key.first and v[mid].second > key.second){
            v[mid] = key;
            return;
        }
        else if (v[mid].first > key.first)
            high = mid - 1;
        else if (v[mid].second <= key.second)
            low = mid + 1;
    }
}
 
void solve(){
    
    int n, x; cin>>n>>x;
    vector<int> a(n);
    
    for (auto &i : a)
        cin>>i;
        
    map<int, int> mp;
    
    for (int i = 0; i < n; ++i){
        if (mp.find(x - a[i]) != mp.end()){
            cout << mp[x - a[i]] + 1 << ' ' << i + 1;
            return;
        }
        else
            mp[a[i]] = i;
    }
    
    cout << "IMPOSSIBLE";
}
 
signed main(){
    
    fastio
    
    int t = 1;
    
    while (t--){
        solve();
    }
}