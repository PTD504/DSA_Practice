/*
###########################################
Source: CSES

Problem statement:
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.
What is the minimum number of gondolas needed for the children?
Input
The first input line contains two integers n and x: the number of children and the maximum allowed weight.
The next line contains n integers p_1,p_2,...,p_n: the weight of each child.
Output
Print one integer: the minimum number of gondolas.

Constraints:
1 <= n <= 2 * 10^5
1 <= x <= 10^9
1 <= p_i <= x

Solution: PTD504
###########################################
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
 
#define int long long 
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x; cin >> n >> x;
    vector<int> p(n);
    map<int, int> mp;
 
    for (auto &i : p){
        cin >> i;
        mp[i]++;
    }
 
    sort(p.begin(), p.end());
    int j = 0, ans = 0;
 
    for (int i = n - 1; i >= j; --i){
        if (i == j)
            ans++, j++;
        else if (p[i] + p[j] <= x)
            ans++, j++;
        else
            ans++;
    }
 
    cout << ans;
}
