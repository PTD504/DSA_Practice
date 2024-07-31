/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.

Constraints:
1 ≤ N ≤ 1000

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

class Solution {
public:

    void multiply(std::vector<int> &ans, int num) {
        int r = 0, n = (int)ans.size();
        
        for (int i = 0; i < n; ++i) {
            int prod = ans[i] * num + r;
            r = prod / 10;
            ans[i] = prod % 10;
        }
        
        while (r) {
            ans.push_back(r % 10);
            r /= 10;
        }
    }

    void reverse(std::vector<int>& arr) {
        int l = 0, h = arr.size() - 1;

        while (l < h) std::swap(arr[l++], arr[h--]);
    }

    std::vector<int> factorial(int N){
        
        std::vector<int> ans = {1};
        
        for (int i = 2; i <= N; ++i) 
            multiply(ans, i);
            
        reverse(ans);

        return ans;
    }
};

int main() {
	int N = 987;

    Solution obj;
    
    for (auto i : obj.factorial(N)) std::cout << i;
}