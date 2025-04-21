from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit, n = 0, len(prices)
        
        for i in range(1, n):
            if prices[i] > prices[i - 1]:
                max_profit += prices[i] - prices[i - 1]
        
        return max_profit

# Example usage
def main():
    prices = [7, 1, 5, 3, 6, 4]
    solution = Solution()
    result = solution.maxProfit(prices)
    print(f"Max profit: {result}")

if __name__ == "__main__":
    main()