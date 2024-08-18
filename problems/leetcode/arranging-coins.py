class Solution:
    def arrangeCoins(self, n: int) -> int:
        m = 1

        while m * (m + 1) // 2 <= n:
            m += 1
        
        return m - 1
