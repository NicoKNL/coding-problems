class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        base = set(range(len(nums) + 1))
        missing = base - set(nums)
        return missing.pop()
