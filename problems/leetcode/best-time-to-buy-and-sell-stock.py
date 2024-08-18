class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_price = [x for x in prices]

        i = len(prices) - 2
        while i >= 0:
            max_price[i] = max(max_price[i], max_price[i + 1])
            i -= 1

        min_price = [x for x in prices]
        i = 1
        while i < len(prices):
            min_price[i] = min(min_price[i], min_price[i - 1])
            i += 1

        best = 0
        for i in range(len(prices)):
            best = max(best, max_price[i] - min_price[i])

        return best
