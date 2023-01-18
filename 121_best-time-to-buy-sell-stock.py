# We maintain two variables throughout the loop
# One is max_profit, the other is min_price 
# (we need the current min price since we always buy at smaller price first) 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price, max_profit = float('inf'), 0
        for i in range(len(prices)):
            if prices[i] < min_price: 
                min_price = prices[i]
            if prices[i] - min_price > max_profit: 
                max_profit = prices[i] - min_price
        return max_profit
