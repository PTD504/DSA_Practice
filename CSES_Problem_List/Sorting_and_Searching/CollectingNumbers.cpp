/*
###########################################
Source: CSES

Problem statement:
You are given an array that contains each number between 1...n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible. What will be the total number of rounds?
Input
The first line has an integer n: the array size.
The next line has n integers x_1,x_2,...,x_n: the numbers in the array.
Output
Print one integer: the number of rounds.

Constraints:
1 <= n <= 2 * 10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#include <unordered_set>
#include <utility>
#include <cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
const int mod = 1e9 + 7;
 
void solve(){
    
    int n; cin>>n;
    vector<int> a(n);
 
    vector<pair<int, int> > v;
 
    for (int i = 0; i < n; ++i){
        cin>>a[i];
        v.push_back({a[i], i});
    }
 
    sort(v.begin(), v.end());
 
    int ans = 1;
 
    for (int i = 0; i < n; ++i){
        if (i == n - 1)
            break;
        if (v[i].second > v[i + 1].second)
            ans++;
    }
 
    cout << ans;
}
 
signed main(){
    
    fastio
    
    int t = 1;
    
    while (t--){
        solve();
    }    
}

