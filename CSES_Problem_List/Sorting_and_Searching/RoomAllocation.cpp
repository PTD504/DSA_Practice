/*
###########################################
Source: CSES

Problem statement:
There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.
You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.
What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?
Input
The first input line contains an integer n: the number of customers.
Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.
Output
Print first an integer k: the minimum number of rooms required.
After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,...,k. You can print any valid solution.

Constraints:
1 <= n <= 2 * 10^5
1 <= a <= b <= 10^9

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
#include <queue>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define fi first
#define se second
const int mod = 1e9 + 7;
 
void leetcode(){
    
}
 
void cses(){
    
    int n; cin>>n;
 
    vector<pair<int, pair<int, int> > > v;
    int arr, dep;
 
    for (int i = 0; i < n; ++i){
        cin>>arr>>dep;
        v.push_back({arr, {dep, i}});
    }
 
    sort(v.begin(), v.end());
 
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
 
    pq.push({v[0].se.fi, {1, v[0].se.se}});
 
    vector<int> ans(n);
    ans[v[0].se.se] = 1;
 
    for (int i = 1; i < n; ++i){
        if (pq.top().fi < v[i].fi){
            ans[v[i].se.se] = pq.top().se.fi;
            pq.pop();
            pq.push({v[i].se.fi, {ans[v[i].se.se], v[i].se.se}});
        }
        else{
            ans[v[i].se.se] = (int)pq.size() + 1;
            pq.push({v[i].se.fi, {ans[v[i].se.se], v[i].se.se}});
        }
    }
    cout << pq.size() << '\n';
 
    for (auto i : ans)
        cout << i << ' ';
}
 
signed main(){
    
    fastio
    
    int t = 1;
    
    while (t--){
        cses();
    }   
 
    return 0; 
}
