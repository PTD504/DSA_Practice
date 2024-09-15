/*
###########################################
Source: CSES

Problem statement:
You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?
Input
The first input line has an integer n: the number of coins.
The second line has n integers x_1,x_2,...,x_n: the value of each coin.
Output
Print one integer: the smallest coin sum.

Constraints:
1 <= n <= 2 * 10^5
1 <= x_i <= 10^9

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
 
    int sum = 0;
 
    sort(a.begin(), a.end());
 
    for (int i = 0; i < n; ++i){
        if (sum + 1 < a[i])
            break;
        else
            sum += a[i];
    }
 
    cout << sum + 1;
}
 
signed main(){
    
    fastio
    
    int t = 1;
    
    while (t--){
        solve();
    }    
}
