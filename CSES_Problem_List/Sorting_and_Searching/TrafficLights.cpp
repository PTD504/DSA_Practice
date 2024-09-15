/*
###########################################
Source: CSES

Problem statement:
There is a street of length x whose positions are numbered 0,1,...,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.
Your task is to calculate the length of the longest passage without traffic lights after each addition.
Input
The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.
Then, the next line contains n integers p_1,p_2,...,p_n: the position of each set of traffic lights. Each position is distinct.
Output
Print the length of the longest passage without traffic lights after each addition.

Constraints:
1 <= x <= 10^9
1 <= n <= 2 * 10^5
0 < p_i < x

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

int main(){
    
    fastio

    int x, n, p; cin>>x>>n;
    set<int> ans{0, x};
    multiset<int> res{x};
    unordered_map<int, int> temp;
    
    auto f = [](unordered_map<int, int> &temp, int n){if (temp.count(n)) temp[n]++; else temp[n] = 1;};
    
    temp[x] = 1;
    
    for (int i = 0; i < n; ++i){
        cin>>p;
        auto j = ans.upper_bound(p);
        auto k = j;
        k--;

        temp[*j - *k]--;
        
        if (!temp[*j - *k]) res.erase(*j - *k);
        
        res.insert(p - *k);
        res.insert(*j - p);
        f(temp, p - *k), f(temp, *j - p);
        ans.insert(p);
        
        auto da = res.end();
        da--;
        
        cout << *da << " ";
    }
}

