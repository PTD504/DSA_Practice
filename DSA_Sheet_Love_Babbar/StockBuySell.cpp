/*
###########################################
Source: GeeksforGeeks

Problem statement:
The cost of stock on each day is given in an array A[] of size N. Find all the segments of days on which you buy and sell the stock such that the sum of difference between sell and buy prices is maximized. Each segment consists of indexes of two elements, first is index of day on which you buy stock and second is index of day on which you sell stock.
Note: Since there can be multiple solutions, the driver code will print 1 if your answer is correct, otherwise, it will return 0. In case there's no profit the driver code will print the string "No Profit" for a correct solution.

Constraints:
2 ≤ N ≤ 10^6
0 ≤ A[i] ≤ 10^6

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

using ll = long long;

class Solution{
public:
    
    std::vector<std::vector<int> > stockBuySell(std::vector<int> A, int n){
		std::vector<std::vector<int> > ans;
        int buy = 0, sell = -1;

		for (int i = 1; i < n; ++i) {
			if (A[buy] >= A[i]) {
				if (sell + 1) {
					ans.push_back(std::vector<int> {buy, sell});
				}
				buy = i, sell = -1;
			}
			else {
				if (sell == -1 or A[sell] < A[i]) {
					sell = i;
				}
				else {
					ans.push_back(std::vector<int> {buy, sell});
					buy = i, sell = -1;
				}
			}
		}

		if (sell + 1) ans.push_back(std::vector<int> {buy, sell});

		return ans;
    }
};

int main() {
    int N = 50;
	std::vector<int> arr = {959, 969, 679, 119, 710, 170, 109, 863, 939, 398, 271, 539, 525, 569, 247, 191, 725, 662, 481, 994, 685, 655, 984, 648, 640, 370, 315, 883, 987, 711, 692, 689, 607, 529, 339, 211, 275, 883, 844, 563, 179, 585, 584, 243, 164, 451, 330, 228, 234, 697};
	
	Solution obj;

	for (auto v : obj.stockBuySell(arr, N)) {
		for (auto i : v) std::cout << i << ' ';
		std::cout << '\n';
	}
    
}