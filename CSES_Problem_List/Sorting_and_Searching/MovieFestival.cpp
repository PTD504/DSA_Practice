/*
###########################################
Source: CSES

Problem statement:
In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?
Input
The first input line has an integer n: the number of movies.
After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.
Output
Print one integer: the maximum number of movies.

Constraints:
1 <= n <= 2 * 10^5
1 <= a < b <= 10^9

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
    
    int n, a, b; cin>>n;
    vector<pair<int, int> > v;
    
    for (int i = 0; i < n; ++i){
        cin>>a>>b;
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end());
    vector<pair<int, int> > ans = {v[0]};
    
    for (int i = 1; i < n; ++i){
        if (v[i].first >= ans.back().second)
            ans.push_back(v[i]);
        else{
            lowerBound(ans, v[i]);
        }
    }
    cout << ans.size();
}
 
signed main(){
    
    fastio
    
    int t = 1;
    
    while (t--){
        solve();
    }
}



