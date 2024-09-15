/*
###########################################
Source: CSES

Problem statement:
There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.
What is the minimum total cost?

Input
The first input line contains an integer n: the number of sticks.
Then there are n integers: p_1,p_2,...,p_n: the lengths of the sticks.
Output
Print one integer: the minimum total cost.

Constraints:
1 <= n <= 2 * 10^5
1 <= p_i <= 10^9

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
    
    int n; cin>>n;
    vector<int> a(n);
    
    for (auto &i : a)
        cin>>i;
    
    sort(a.begin(), a.end());
    
    if (n == 1){
        cout << 0;
        return;
    }
    
    int prefix_left[n], prefix_right[n];
    prefix_left[0] = a[0], prefix_right[n - 1] = a[n - 1];
    
    for (int i = 1; i < n; ++i)
        prefix_left[i] = prefix_left[i - 1] + a[i];
    for (int i = n - 2; i >= 0; --i)
        prefix_right[i] = prefix_right[i + 1] + a[i];
    
    int ans = 1e18;
    
    for (int i = 0; i < n; ++i){
        if (i == 0)
            ans = min(ans, prefix_right[i + 1] - a[i] * (n - i - 1));
        else if (i == n - 1)
            ans = min(ans, a[i] * (n - 1) - prefix_left[i - 1]);
        else{
            ans = min(ans, a[i] * i - prefix_left[i - 1] + prefix_right[i + 1] - a[i] * (n - i - 1));
        }
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
