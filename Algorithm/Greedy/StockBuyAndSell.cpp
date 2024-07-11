/*
###########################################
Source: GeeksforGeeks

Problem statement:
The cost of stock on each day is given in an array A[] of size N. Find all the segments of days on which you buy and sell the stock such that the sum of difference between sell and buy prices is maximized. Each segment consists of indexes of two elements, first is index of day on which you buy stock and second is index of day on which you sell stock.
Constraints:
2 ≤ N ≤ 10^6
0 ≤ A[i] ≤ 10^6

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

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
	std::vector<int> arr = {839, 903, 958, 574, 401, 977, 618, 257, 442, 321, 735, 549, 477, 799, 778, 612, 989, 760, 440, 57, 281, 12, 783, 550, 674, 539, 795, 175, 398, 500, 797, 283, 924, 316, 107, 568, 471, 414, 576, 713, 205, 310, 203, 619, 839, 424, 81, 550, 876, 605};

	Solution obj; 
	
	for (auto &v : obj.stockBuySell(arr, N)) {
		for (auto &i : v) std::cout << i << ' ';
		std::cout << '\n';
	}
}