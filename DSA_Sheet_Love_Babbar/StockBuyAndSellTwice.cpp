/*
###########################################
Source: GeeksforGeeks

Problem statement:
In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, the second transaction can only start after the first one is complete (buy -> sell -> buy -> sell). The stock prices throughout the day are represented in the form of an array prices of size n.

Given an array price of size n, find out the maximum profit that a share trader could have made.

Constraints:
1 <= n <= 10^5
1 <= price[i] <= 10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <queue>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int fBuy = -2e9;
        int fSell = 0;
        int sBuy = -2e9;
        int sSell = 0;

        for (int i = 0; i < prices.size(); ++i) {
            fBuy = max(fBuy, -prices[i]);
            fSell = max(prices[i] + fBuy, fSell);

            sBuy = max(sBuy, fSell - prices[i]);
            sSell = max(sSell, prices[i] + sBuy);
        }

        return sSell;
    }
};

int main() {
    std::vector<int> prices = {699, 859, 737, 255, 970, 897, 534, 816, 482, 104, 565, 911, 619, 789, 532, 611, 262, 592, 789, 131, 717, 157, 492, 316, 152, 127, 213, 844, 537, 524, 198, 698, 367, 127, 177, 795};

	Solution obj;
	std::cout << obj.maxProfit(prices);
}