class Solution:
    def minOperations(self, nums: list[int], k: int) -> int:
        values = set()
        for i, v in enumerate(reversed(nums)):
            if v <= k:
                values.add(v)
            if len(values) == k:
                return i + 1
