/*
###########################################
Source: CSES

Problem statement:
You are given n cubes in a certain order, and your task is to build towers using them. Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.
You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?
Input
The first input line contains an integer n: the number of cubes.
The next line contains n integers k_1,k_2,...,k_n: the sizes of the cubes.
Output
Print one integer: the minimum number of towers.

Constraints:
1 <= n <= 2 * 10^5
1 <= k_i <= 10^9

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
    
    for (auto &i : a)
        cin>>i;
    
    map<int, int> mp;
    mp[a[0]] = 1;
    
    for (int i = 1; i < n; ++i){
        auto j = mp.upper_bound(a[i]);
        if (j != mp.end()){
            if (mp[j->first] == 1)
                mp.erase(j);
            else
                mp[j->first]--;
        }
        mp[a[i]]++;
    }
    
    int ans = 0;
    
    for (auto i : mp)
        ans += i.second;
        
    cout << ans;
}
 
signed main(){
    
    fastio
    
    int t = 1;
    
    while (t--){
        solve();
    }   
 
    return 0; 
}
