/*
###########################################
Source: CSES

Problem statement:
You have to process n tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. Your reward for a task is d-f where d is its deadline and f is your finishing time. (The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)
What is your maximum reward if you act optimally?
Input
The first input line has an integer n: the number of tasks.
After this, there are n lines that describe the tasks. Each line has two integers a and d: the duration and deadline of the task.
Output
Print one integer: the maximum reward.

Constraints:
1 <= n <= 2 * 10^5
1 <= a, d <= 10^6

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
    
    int n, a, d; cin>>n;
    vector<pair<int, int> > v;
 
    for (int i = 0; i < n; ++i){
        cin>>a>>d;
        v.push_back({a, d});
    }
 
    sort(v.begin(), v.end());
 
    int reward = 0, finish = 0;
 
    for (int i = 0; i < n; ++i){
        finish += v[i].first;
        reward += v[i].second - finish;
    }
 
    cout << reward;
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
