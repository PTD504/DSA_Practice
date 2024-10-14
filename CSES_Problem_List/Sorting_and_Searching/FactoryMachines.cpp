/*
###########################################
Source: CSES

Problem statement:
A factory has n machines which can be used to make products. Your goal is to make a total of t products.
For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t products?
Input
The first input line has two integers n and t: the number of machines and products.
The next line has n integers k_1,k_2,...,k_n: the time needed to make a product using each machine.
Output
Print one integer: the minimum time needed to make t products.

Constraints:
1 <= n <= 2 * 10^5
1 <= t <= 10^9
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
#include <queue>
#include <functional>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define fi first
#define se second
const int mod = 1e9 + 7;
 
void leetcode(){
    
}
 
void cses(){
    
    int n, t; cin>>n>>t;
    vector<int> k(n);
 
    for (auto &i : k)
        cin>>i;
 
    function<bool(vector<int>, int , int)> check = [&] (vector<int> k, int amount, int t) -> bool {
        
        int ans = 0;
 
        for (auto i : k){
            ans += amount / i;
            if (ans >= t)
                return 1;
        }
 
        return 0;
    };
 
    int low = 1, high = 1e18 + 1, mid, ans;
 
    while (low <= high){
        mid = low + (high - low) / 2;
 
        if (check(k, mid, t))
            ans = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    cout << ans;
}
 
signed main(){
    
    fastio
    
    int t = 1;
    
    while (t--){
        cses();
    }   
 
    return 0; 
}
 
/*
 
Dijkstra
 
6 5
0 3 9
0 5 4
1 4 4
2 5 10
4 5 3
1
 
*/
