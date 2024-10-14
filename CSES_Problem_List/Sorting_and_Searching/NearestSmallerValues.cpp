/*
###########################################
Source: CSES

Problem statement:
Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.
Input
The first input line has an integer n: the size of the array.
The second line has n integers x_1,x_2,...,x_n: the array values.
Output
Print n integers: for each array position the nearest position with a smaller value. If there is no such position, print 0.

Constraints:
1 <= n <= 2 * 10^5
1 <= x_i <= 10^9

Solution: PTD504
###########################################
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int MOD = 1e9 + 7;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n;
    set<pair<int, int> > st;
 
    for (int i = 0; i < n; ++i) {
      int a; cin >> a;
      
      if (i == 0) {
        cout << 0 << ' ';
        st.insert({a, i + 1});
        continue;
      }
      
      while (st.size() and st.rbegin()->first >= a) {
        st.erase(*st.rbegin());
      }
      
      if (st.size()) {
        cout << st.rbegin()->second << ' ';
      }
      else
        cout << 0 << ' ';
      
      st.insert({a, i + 1});
    }
}
