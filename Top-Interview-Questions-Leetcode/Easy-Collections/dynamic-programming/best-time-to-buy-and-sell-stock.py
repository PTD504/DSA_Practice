from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn_price, mx_profit = prices[0], 0
        
        for i in prices:
            mx_profit = max(mx_profit, i - mn_price)
            mn_price = min(mn_price, i)
        
        return mx_profit