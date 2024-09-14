/*
###########################################
Source: CSES

Problem statement:
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
Input
The first input line has an integer n: the number of customers.
After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.
Output
Print one integer: the maximum number of customers.

Constraints:
1 <= n <= 2 * 10^5
1 <= a < b <= 10^9

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
 
using namespace std;
 
#define int long long
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int n; cin >> n;
    vector<pair<int, int> > v;
    int a, b;
 
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back({a, b});
    }
 
    sort(v.begin(), v.end());
 
    priority_queue<int, vector<int>, greater<int> > pq;
    int ans = 0;
 
    for (int i = 0; i < n; ++i) {
        if (pq.empty()){
            pq.push(v[i].second);
            ans = max(ans, 1ll);
        }
        else if (v[i].first < pq.top()) {
            pq.push(v[i].second);
            ans = max(ans, (int)pq.size());
        }
        else {
            pq.pop();
            pq.push(v[i].second);
            ans = max(ans, (int)pq.size());
        }
    }

    cout << ans;
}


