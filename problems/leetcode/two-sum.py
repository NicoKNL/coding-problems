class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i, a in enumerate(nums):
            for ii, b in enumerate(nums):
                if i != ii and a + b == target:
                    return [i, ii]
