/*
###########################################
Source: CSES

Problem statement:
You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
What is the longest sequence of successive songs where each song is unique?
Input
The first input line contains an integer n: the number of songs.
The next line has n integers k_1,k_2,...,k_n: the id number of each song.
Output
Print the length of the longest sequence of unique songs.

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
    int id[n + 1];
    
    for (int i = 1; i <= n; ++i)
        cin>>id[i];
        
    map<int, int> mp;
    
    int j = 1;
    mp[id[1]] = 1;
    
    while (j < n and (int)mp.size() == j)
        mp[id[++j]]++;
    
    
    int i = 1, ans = mp.size();
    mp[id[j]]--;
    
    while (i < j){
        
        if (j <= n)
            mp[id[j]]++;
        
        while (i < n and (int)mp.size() < j - i + 1){
            mp[id[i]]--;
            if (mp[id[i]] <= 0) 
                mp.erase(id[i]);
            i++;
        }
        
        if ((int)mp.size() == j - i + 1)
            ans = max(ans, (int)mp.size());
        
        if (j < n)
            j++;
        else
            i++;
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
