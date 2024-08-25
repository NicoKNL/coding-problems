class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        INF = 1e9
        L, R = 0, -1
        total = 0
        best = INF

        while R < len(nums):
            if total < target:
                R += 1
                if R >= len(nums):
                    break
                total += nums[R]
            else:
                total -= nums[L]
                L += 1

            if total >= target:
                best = min(best, R - L + 1)
        
        if best == INF:
            return 0

        return best
